/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Cdc_Application_Mandatory.c                                   **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Support of DCM diagnostic services corresponding              **
**              to specification for AUTOSAR - application part               **
**                                                                            **
**  REMARKS   : Implementation of application specific diagnostic             **
**              services                                                      **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** dabu         Daniel Buder               EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** muer         Murat Erdogan              MB Technology                      **
** dobr         Dominik Brader             EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.6: 27.10.2011, anam: CR71144: CDC: Cdc: Redeclaration of function 
 *                                    Cdc_ReadDataByIdentifierKilometer and 
 *                                    Cdc_ReadDataByIdentifierRelativeTime
 * V1.1.5: 26.09.2011, anam: CR71024: CDC: Don't ignore possible error messages or return values
 *                     anam: CR71075: Cdc: Insufficient check of resMaxDataLen for ResponseOnEvent
 * V1.1.4: 14.02.2010, muer: CR70919: some MISRA warnings removed
 * V1.1.3: 15.11.2010,   ft: CR70828: Removed unneccessary size check of dcm buffer 
 *                     anam: CR70803: Switch from Com-Callbacks to Polling mode for MILE_KM  
 *                     anam: CR70875: CDC: Modifications due to CR70555
 * V1.1.2: 20.04.2010, anam: CR70574: Inconsistent usage of VSM_EVENT_OPMODE    
 * V1.1.1: 08.04.2010, anam: CR70520: SGBD-ID configuration parameter shall be dynamic
 * V1.0.7: 18.11.2009, muer: CR70461: Code Size Optimization - Cdc - BAC HIS 
 *                                    implementation guidelines
 *                     gema: CR70390: Compiler switches shall have defined values
 *                           CR70381: 61773: Sizecheck at ClearDTCSecondaryMemory
 * V1.0.6: 17.11.2009, gema: CR70358: Response data completely set in 
 *                                    Cdc_RoutineControlDmTest()
 * V1.0.5: 08.10.2009, hauf: CR70292: Corrected storage class of
 *                                    Cdc_NvDataDefault to CDC_VAR_NVCONST
 * V1.0.4: 02.10.2009, hauf: CR70308: replaced reqData with resData
 * V1.0.3: 10.08.2009, dobr: CR70390: replaced 'ON/OFF' with 'STD_ON/STD_OFF'
 * V1.0.2: 03.07.2009, dabu: CR70255: unlock all DTCs after leaving flash mode
 *         30.06.2009, hauf: CR70188: changed name of DCM session defines
 *         25.06.2009, dabu: CR70223: Implementation of Cdc review results
 *         24.06.2009, dabu: CR70219: checking of extended operational modes
 * V1.0.1: 17.11.2008, dabu: CR61302: no activation of communication and
 *                                    error memory after leaving FMA mode in
 *                                    the default session by setOpMode(NORMAL)
 *         17.11.2008, dabu: CR61288: set DEM event with separate Op-Cycle
 *                                    clear event VSM_EVENT_OPMODE in NORMAL mode
 *         17.11.2008, dabu: CR70041: removed check of VSM_EVENT_OPMODE number
 *                                    to prevent wrong rte configuration
 * V1.0.0: 08.08.2008, dabu: BSCCDC-25: changed Application Extended Session
 *                                      handling according LH FP part 5 v09
 *         26.11.2007, dabu: ported from SC6.7.2 DiagServices package
 *                           version V4.0.1 from 2007-11-06
 */

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/*

 26 MISRA Rule Violation:
 43 MISRA Rule Violation:
 86 MISRA Rule Violation:
    This exceptions are created by a bug in the QAC-MISRA checker that doesn't
    support the autosar compiler abstraction

 33 MISRA Rule Violation:
    The nesting deepth is decreased, when a right hand operand that has side
    effects is used. In addition it decreases the code size in some cases when
    only one exception handling must be implemented

 44 MISRA Rule Violation:
    Redundant explicit casts should not be used.
    The redundant casts are in macros and should prevent use of wrong data type

 52 MISRA Rule Violation:
    Some control expressions may always be 'false/true':
    Reasons: The StandardCore is only a template that must be extended by the
    user

 63 MISRA Rule Violation:
 64 MISRA Rule Violation:
    A switch statement with only 2 branches should usually be replaced with an
    "if ... else" construct.
    Reason: The amount of switch case statements depends on macro definitions
    and the code is easier to extend

 82 MISRA Rule Violation:
    More then one 'return' paths are used to make the code easier to read (e.g
    checking of preconditions), to save stack, to decrease nesting depth and to
    speedup execution

101 MISRA Rule Violation:
    Arithmetic operations shall not be performed on pointers - even with the
    value "1".
    Reason: code size optimization

*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>              /* include AUTOSAR standard types         */
/* -------------------------------------------------------------------------- */
#include <Cdc.h>                    /* Subparameter macros of diagn. services */
/* -------------------------------------------------------------------------- */
#include <Cdc_Cfg.h>                /* module configuration h-file            */
/* -------------------------------------------------------------------------- */
#include <Cdc_Application_Mandatory.h> /* prototypes of the CDC functions     */
/* -------------------------------------------------------------------------- */
#include <Cdc_Common_Mandatory.h>   /* prototypes of the CDC common functions */
/* -------------------------------------------------------------------------- */
#if (CdcUseUserExtension == STD_ON)
#include <Cdc_User.h>               /* prototypes of the CDC user functions   */
#endif
/* -------------------------------------------------------------------------- */
#include <Dcm.h>                    /* DCM API                                */
/* -------------------------------------------------------------------------- */
#include <NvM.h>                    /* NvM Api                                */
/* -------------------------------------------------------------------------- */
#include <EcuM.h>                   /* AUTOSAR Ecu Manager                    */
/* -------------------------------------------------------------------------- */
#include <Dem.h>                    /* definitions of symbols used in Dem
                                     * callback functionsDataId               */

#if (CDC_USE_DYNAMIC_SGBD == STD_ON)
#include CDC_DYNAMIC_SGBD_HEADER_FILE
#endif

#if (CDC_MODULETEST_ENABLED == STD_ON)
#include <DEV_TEST_TestApp.h>       /* Cdc module test                        */
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */    

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*
 * Version check
 */
#if ((CDC_H_MAJOR_VERSION != 1u) || \
     (CDC_H_MINOR_VERSION != 1u))
  #error "Wrong version of Cdc.h found!!"
#endif
#if ((CDC_CFG_H_MAJOR_VERSION != 1u) || \
     (CDC_CFG_H_MINOR_VERSION != 1u))
  #error "Wrong version of Cdc_Cfg.h found!!"
#endif
#if ((CDC_APPLICATION_MANDATORY_H_MAJOR_VERSION != 1u) || \
     (CDC_APPLICATION_MANDATORY_H_MINOR_VERSION != 1u))
  #error "Wrong version of Cdc_Application_Mandatory.h found!!"
#endif

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define CDC_START_SEC_CODE
#include <MemMap.h>

#if (CDC_DM_TEST == STD_ON)
   _STATIC_ FUNC(uint16, CDC_CODE) Cdc_DMDebugNextDtc
            (
               P2VAR(uint8, AUTOMATIC, CDC_VAR_DCMDATA) dataPtr,
               uint16 dataLen
            );
#endif /* (CDC_DM_TEST == STD_ON) */

   _STATIC_ FUNC(boolean, CDC_CODE) Cdc_ProceedVsmOperationModeChange
            (
               uint8 newOpMode
            );

#define CDC_STOP_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CDC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

   VAR(Cdc_NvDataType, CDC_VAR_PUBLIC) Cdc_NvData;

#define CDC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

#define CDC_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

   CONST(Cdc_NvDataType, CDC_VAR_NVCONST) Cdc_NvDataDefault = {{0,0,0}};

#define CDC_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

#define CDC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

   /*
    * Pending diag context type
    * Used to save diag parameters for asynchronous processing in
    * 'BackgroundTask'
    */
   VAR(pendingDiagContextType, CDC_VAR_DCMDATA) pendingDiagContext;

#define CDC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

#define CDC_START_SEC_VAR_8BIT
#include <MemMap.h>

   /* store the actual error memory state - init in Cdc_Init()                */
   VAR(boolean, CDC_VAR_DCMDATA) isErrorMemoryEnabled;

#define CDC_STOP_SEC_VAR_8BIT
#include <MemMap.h>

/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#define CDC_START_SEC_VAR_8BIT
#include <MemMap.h>

   #if (CDC_DM_TEST == STD_ON) && (DCM_PAGEDBUFFER_ENABLED == STD_ON)
   /* Counter of calls of Cdc_UpdatePageRdbiDMDebug() */
   _STATIC_ VAR(uint8, CDC_VAR_PRIVATE) noOfCall = 0U;
   #endif

#define CDC_STOP_SEC_VAR_8BIT
#include <MemMap.h>

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define CDC_START_SEC_CODE
#include <MemMap.h>

#if (CDC_DM_TEST == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DMDebugNextDtc                                         **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) - DMClient_IsDTCActive and     **
**                 DM_Client_IsDTCLockable                                    **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : noOfCall                                                   **
**                                                                            **
** PARAMETER     : uint8* dataPtr: ptr to write data to                       **
**                 uint16 dataLen: maximum allowed length in bytes            **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : Called also of interrupt level                             **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(uint16, CDC_CODE) Cdc_DMDebugNextDtc
(
   P2VAR(uint8, AUTOMATIC, CDC_VAR_DCMDATA) dataPtr,
   uint16 dataLen
)
{
  uint32                            dtc;
  Dem_ReturnGetNextFilteredDTCType  resultGetNextDtc = DEM_FILTERED_OK;
  uint16                            usedBytes = 0U;

  /* Gather the DTC info */
  while ((resultGetNextDtc != DEM_FILTERED_NO_MATCHING_DTC)
         && (dataLen >= (uint16)3U))
  {
     resultGetNextDtc = CDC_DEM_GETNEXTFILTEREDDMDEBUGDTC(
        DEM_DTC_KIND_ALL_DTCS,
        &dtc);

     /* write DTC into response buffer */
     if (resultGetNextDtc == DEM_FILTERED_OK)
     {
        *dataPtr++ = CDC_GETHILOBYTE(dtc);
        *dataPtr++ = CDC_GETLOHIBYTE(dtc);
        *dataPtr++ = CDC_GETLOLOBYTE(dtc);

        dataLen   -= (uint16)3U;
        usedBytes += (uint16)3U; /* response length: + 3 byte */
     }
  }

  return usedBytes;
}

#endif  /* CDC_DM_TEST */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ProceedVsmOperationModeChange                          **
**                                                                            **
** DESCRIPTION   : Inform VSM about new operation mode and                    **
**                 save it permanently in EEPROM                              **
**                                                                            **
** PRECONDITIONS : no                                                         **
**                                                                            **
** GLOBAL DATA   : no                                                         **
**                                                                            **
** PARAMETER     : uint8 newOpMode                                            **
**                                                                            **
** INPUT:        : no                                                         **
**                                                                            **
** RETURN        : boolean: result of setting the new op. mode (clear event)  **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(boolean, CDC_CODE) Cdc_ProceedVsmOperationModeChange
(
   uint8 newOpMode
)
{
   boolean                    returnValue = TRUE;
   CDC_VSM_OPERATINGMODETYPE  oldOpMode;

   /* get the actual VSM operation mode                                       */
   CDC_VSM_GETMODE( &oldOpMode );

   if ( ( newOpMode != (uint8)CDC_VSM_MM_MODE_NORMAL ) &&
        ( oldOpMode == (uint8)CDC_VSM_MM_MODE_NORMAL ) )
   {
      /* error memory entry "Energiesparmode aktiv", if the new operation
       * mode is not NORMAL but was NORMAL before
       */
      /* Function returns always E_OK in this case so the return value can be ignored */
      (void)Dem_SetOperationCycleState(DEM_OPCYCLE_VSM_OPMODE, DEM_CYCLE_STATE_START);
      Dem_ReportErrorStatus(CdcVsmEventOpModeRef, DEM_EVENT_STATUS_FAILED);
      /* Function returns always E_OK in this case so the return value can be ignored */
      (void)Dem_SetOperationCycleState(DEM_OPCYCLE_VSM_OPMODE, DEM_CYCLE_STATE_END);
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_DEM_REPORTERRORSTATUS_CALLED, TEST_CDC_RESPONSE_CODE_NOT_USED, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */       
   }

   /* set the operation mode in the VSM                                       */
   CDC_VSM_DIAGMODECHANGE((Vsm_OperatingModeType)newOpMode);

   /* clear error memory entry "Energiesparmode aktiv", if the new operation
    * mode is NORMAL and was not NORMAL before
    */
   if ( ( newOpMode == (uint8)CDC_VSM_MM_MODE_NORMAL ) &&
        ( oldOpMode != (uint8)CDC_VSM_MM_MODE_NORMAL ) )
   {
      Dem_DTCType DTC = 0U;
      Dem_ReturnGetDTCOfEventType StatusDTC;

      /* get dtc value of the DEM-events                                      */
      /* A returnvalue != E_OK is not possible in this case*/
      (void) Dem_GetDTCOfEvent(
                     CdcVsmEventOpModeRef, DEM_DTC_KIND_ALL_DTCS, &DTC, &StatusDTC);

      if ( Dem_ClearDTC(DTC, DEM_DTC_KIND_ALL_DTCS,
                      DEM_DTC_ORIGIN_PRIMARY_MEMORY) != DEM_CLEAR_OK )
      {
         /* Clear DTC failed                                                  */
         returnValue = FALSE;
      }
   }

   return returnValue;
}

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_RoutineControlCheckProgrammingPreConditions            **
**                                                                            **
** DESCRIPTION   : This callback implements the check of the programming      **
**                 preconditions. Therefore it calls the ECU                  **
**                 developer specific function (macro)                        **
**                 'UserCallback_CheckProgrammingPreConditions'               **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : The callback 'UserCallback_CheckProgrammingPreConditions'  **
**                 must be implemented by the ECU developer                   **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_RoutineControlCheckProgrammingPreConditions
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
#if (CDC_BAC_VERSION == CDC_BAC3X)
    Dcm_SesCtrlType   ActiveSession;
    /* Function returns always E_OK so the return value can be ignored */
    (void)Dcm_GetSesCtrlType(&ActiveSession);
#endif
   /*
    * check request length: no parameters after the identifier are supported
    */
   if (pMsgContext->reqDataLen == (uint16)3)
   {
#if (CDC_BAC_VERSION == CDC_BAC3X)
      if ( EXTENDED_DIAGNOSTIC_SESSION == ActiveSession )
#endif          
#if (CDC_BAC_VERSION == CDC_BAC21)
      if ( Dcm_GetSesCtrlType() == EXTENDED_DIAGNOSTIC_SESSION )
#endif      
      {
         pMsgContext->resDataLen =
            (uint16)(3 + CDC_USERCALLBACK_CHECKPROGRAMMINGPRECONDITIONS(&pMsgContext->resData[3]));
      }
      else
      {
         /* CheckProgrammingPreConditions is not supported in this session    */
         *ResponseCode = DCM_E_REQUESTOUTOFRANGE;
      }
   }
   else
   {
      *ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ConfirmationECUReset                                   **
**                                                                            **
** DESCRIPTION   : Post handler of 'Cdc_ECUReset' (0x11)                      **
**                 Trigger a reset. This function implements the second step  **
**                 of the operation after the positive response was send.     **
**                 The functions initiates the shutdown (inc. writing         **
**                 data to EEPROM)                                            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : pendingSubFunction: reset Mode                             **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ConfirmationECUReset
(
   CONST(uint8,AUTOMATIC) pendingSubFunction
)
{
    if(DIAG_UDS11_01_HARD_RESET == pendingSubFunction)
    {
        /* initiate an ECU reset                                             */
        (void)EcuM_SelectShutdownTarget(ECUM_STATE_RESET, (uint8)0);

        EcuM_KillAllRUNRequests();      
               
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_CONFIRMATIONECURESET_CALLED, TEST_CDC_RESPONSE_CODE_NOT_USED, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */         
    }
    else
    {
        /* unknown sub parameter                                             */
#if (CdcUseUserExtension == STD_ON)
        /* try to find an user extended diagnostic SubFunction in Cdc_User.c */
        (void)Cdc_ConfirmationECUReset_User(pendingSubFunction);
#endif        
    }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierTestStamp                          **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -  DIAG_DID_1000_TEST_STAMP    **
**                 Returns the teststamp                                      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (DIAG_DID_1000_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Application_Mandatory.c: The response length for service ReadDataByIdentifier TestStamp is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierTestStamp
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   /*
    * copy test stamp from global buffer to response:
    */
   /* Function returns always the first parameter
     so the return value can be ignored */
   (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) resDataPtr,
                            (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) &Cdc_NvData.testStamp,
                            sizeof(Cdc_NvData.testStamp)
                          );

   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)(2 + sizeof(Cdc_NvData.testStamp));
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierVsmOperationMode                   **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_100A_VSM_OPERATION_MODE                           **
**                 Returns the actual VSM operation-mode.                     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (DIAG_DID_100A_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Application_Mandatory.c: The response length for service ReadDataByIdentifier VsmOperationMode is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierVsmOperationMode
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   CDC_VSM_OPERATINGMODETYPE op_mode;

   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   /* Function returns always E_OK so the return value can be ignored */
   (void)CDC_VSM_GETMODE( &op_mode );
   *resDataPtr = (uint8)op_mode;

   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_100A_RESPONSE_LENGTH;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierVsmExtendedOperationMode           **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_100E_VSM_OPERATION_MODE_EXTENSION                 **
**                 Returns the actual VSM operation-mode-extension.           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (DIAG_DID_100E_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Application_Mandatory.c: The response length for service ReadDataByIdentifier VsmOperationModeExtension is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierVsmExtendedOperationMode
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   CDC_VSM_OPERATINGMODEEXTENSIONTYPE  ext_op_mode;

   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   /* Function returns always E_OK so the return value can be ignored */
   (void)CDC_VSM_GETMODEEXTENSION( &ext_op_mode );
   *resDataPtr = (uint8)ext_op_mode;

   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_100E_RESPONSE_LENGTH;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierKilometer                          **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -  DIAG_DID_1700_KILOMETER     **
**                 Returns the actual mile/km value.                          **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (DIAG_DID_1700_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Application_Mandatory.c: The response length for service ReadDataByIdentifier Kilometer is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierKilometer
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   uint32 mile_km_value = (uint32)0xFFFFFFuL; /* holds local mile_km_value       */

#if (CdcUseRte != STD_ON)
   /* Default value is used when function returns != E_OK 
      so the return value can be ignored */
   (void)Com_ReceiveSignal( CdcKmValueComSignalIdRef,
                            #if (CDC_BAC_VERSION == CDC_BAC3X)
                               ( void*)                     &mile_km_value
                            #endif
                            #if (CDC_BAC_VERSION == CDC_BAC21)
                               ( Com_ApplicationDataRefType)&mile_km_value
                            #endif
                          );
#else
   /* read signal from RTE module                                             */
   /* Default value is used when function returns != E_OK 
      so the return value can be ignored */
   (void)Rte_Read_MileKm_Port_MileKm(&mile_km_value);
#endif /* (CdcUseRte != STD_ON) */

   *resDataPtr++ = CDC_GETHILOBYTE(mile_km_value);
   *resDataPtr++ = CDC_GETLOHIBYTE(mile_km_value);
   *resDataPtr   = CDC_GETLOLOBYTE(mile_km_value);

   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_1700_RESPONSE_LENGTH;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierRelativeTime                       **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -  DIAG_DID_1701_RELATIVE_TIME **
**                 Returns the actual relative time value.                    **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (DIAG_DID_1701_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Application_Mandatory.c: The response length for service ReadDataByIdentifier RelativeTime is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierRelativeTime
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   /* get the current system time from the systime client                     */
   uint32 tempVar;
   /* Function returns always E_OK so the return value can be ignored */
   (void)CDC_SYSTIMECLIENT_GETTIME(&tempVar);

   *resDataPtr++  = CDC_GETHIHIBYTE(tempVar);
   *resDataPtr++  = CDC_GETHILOBYTE(tempVar);
   *resDataPtr++  = CDC_GETLOHIBYTE(tempVar);
   *resDataPtr    = CDC_GETLOLOBYTE(tempVar);

   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_1701_RESPONSE_LENGTH;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierDarhDTC                            **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -  DIAG_DID_1704_DARH_DTC      **
**                 Returns the active response payload from DARH.             **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (DIAG_DID_1704_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Application_Mandatory.c: The response length for service ReadDataByIdentifier DarhDTC is greater than DCM_BUFFER_LENGTH"
#endif
#if (DCM_ROE_ENABLED == STD_ON)
  #if (DIAG_DID_1704_RESPONSE_LENGTH >= DCM_ROE_BUFFER_LENGTH)
     #error "Cdc_Application_Mandatory.c: The response length for service ResponseOnEvent DarhDTC is greater than DCM_ROE_BUFFER_LENGTH"
  #endif
#endif /* (DCM_ROE_ENABLED == STD_ON)                                         */
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDarhDTC
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];
    
   /* Function returns always E_OK so the return value can be ignored */
   (void)CDC_DARH_GETACTIVERESPONSEPAYLOAD ( resDataPtr, &pMsgContext->resDataLen );

   /*
    * the datalength of the darh-user-data will be set absolute in the
    * called darh-function --> 2 bytes must be added for dataID
    */
   pMsgContext->resDataLen += (uint16)2;              /* add length of dataID */
}


#if (CDC_DM_TEST == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierDMDebugIsDtcActiveResponse         **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_1723_IS_DTC_ACTIVE_RESPONSE                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 boolean isPagedProcessingExecuted                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDMDebugIsDtcActiveResponse
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
   /* reset the requested filter */
   CDC_DEM_SETDMDEBUGFILTER(CDC_DEM_DMDEBUG_FILTER_ROEACTIVE);

# if (DCM_PAGEDBUFFER_ENABLED == STD_ON)

   noOfCall = 0U;
   pMsgContext->resDataLen = (Dcm_MsgLenType)2U +
      (DEM_NUMBER_OF_ROE_EVENTS * 3U);
   /* set isPagedProcessingExecuted to TRUE to prevent a duplicated
    * execution of Dcm_ProcessingDone() because this will be done by
    * the PagedBuffering
    */
   *isPagedProcessingExecuted = TRUE;
   /* set special error code for behaviour differentiation and start the paged
    * buffered process */
   Dcm_StartPagedProcessing(pMsgContext);

# else /* no paged buffer handling */

#  if ((2U + DEM_NUMBER_OF_ROE_EVENTS * 3U) >= DCM_BUFFER_LENGTH)
#   error "Cdc_Application_Mandatory.c: Response length for service ReadDataByIdentifier DIAG_DID_1723_IS_DTC_ACTIVE_RESPONSE is greater than DCM_BUFFER_LENGTH"
#  endif

   /* response length: + 2 byte DataID */
   pMsgContext->resDataLen = (Dcm_MsgLenType)2U;

   /* fill rest of response buffer with filtered DTCs */
   pMsgContext->resDataLen += Cdc_DMDebugNextDtc(
      &pMsgContext->resData[2],
      (uint16)pMsgContext->resMaxDataLen - (uint16)2U);

# endif  /* DCM_PAGEDBUFFER_ENABLED == STD_ON */
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierDMDebugIsDtcLockable               **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_1724_IS_DTC_LOCKABLE                              **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 boolean isPagedProcessingExecuted                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDMDebugIsDtcLockable
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
   /* reset the requested filter */
   CDC_DEM_SETDMDEBUGFILTER(CDC_DEM_DMDEBUG_FILTER_LOCKABLE);

# if (DCM_PAGEDBUFFER_ENABLED == STD_ON)

   noOfCall = 0U;
   pMsgContext->resDataLen = (Dcm_MsgLenType)2U +
      (DEM_NUMBER_OF_LOCKABLE_EVENTS * 3U);
   /* set isPagedProcessingExecuted to TRUE to prevent a duplicated
    * execution of Dcm_ProcessingDone() because this will be done by
    * the PagedBuffering
    */
   *isPagedProcessingExecuted = TRUE;
   /* set special error code for behaviour differentiation and start the paged
    * buffered process */
   Dcm_StartPagedProcessing(pMsgContext);

# else /* no paged buffer handling */

#  if ((2U + DEM_NUMBER_OF_LOCKABLE_EVENTS * 3U) >= DCM_BUFFER_LENGTH)
#   error "Cdc_Application_Mandatory.c: Response length for service ReadDataByIdentifier DIAG_DID_1724_IS_DTC_LOCKABLE is greater than DCM_BUFFER_LENGTH"
#  endif

   /* response length: + 2 byte DataID */
   pMsgContext->resDataLen = (Dcm_MsgLenType)2U;

   /* fill rest of response buffer with filtered DTCs */
   pMsgContext->resDataLen += Cdc_DMDebugNextDtc(
      &pMsgContext->resData[2],
      (uint16)pMsgContext->resMaxDataLen - (uint16)2U);

# endif  /* DCM_PAGEDBUFFER_ENABLED == STD_ON */
}

#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_UpdatePageRdbiDMDebug                                  **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) - DMClient_IsDTCActive and     **
**                 DM_Client_IsDTCLockable for paged buffering processing     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : noOfCall                                                   **
**                                                                            **
** PARAMETER     : uint8* dataPtr: ptr to write data to                       **
**                 uint16 dataLen: maximum allowed length in bytes            **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : Called also of interrupt level                             **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_UpdatePageRdbiDMDebug
(
   Dcm_MsgType dataPtr,
   Dcm_MsgLenType dataLen
)
{
  uint16 usedBytes = 0U;

  ++noOfCall;
  if (noOfCall == (uint8)1U)
  {
     /* write DID into response buffer */
     *dataPtr++ = CDC_GETHIBYTE(pendingDiagContext.DataOrRoutineId);
     *dataPtr++ = CDC_GETLOBYTE(pendingDiagContext.DataOrRoutineId);

     dataLen   -= (uint16)2U;
     usedBytes += (uint16)2U;   /* reponse length +2 byte */
  }

  /* fill response buffer with filtered DTCs */
  usedBytes += Cdc_DMDebugNextDtc(dataPtr, dataLen);

  /* paged buffer processing done */
  Dcm_ProcessPage(usedBytes);
  
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_UPDATEPAGERDBIDMDEBUG_CALLED, TEST_CDC_RESPONSE_CODE_NOT_USED, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */     
}
#endif  /* DCM_PAGEDBUFFER_ENABLED == STD_ON */

#endif  /* CDC_DM_TEST */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierScModuleVersions                   **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_1726_STANDARD_CORE_MODULE_VERSIONS                **
**                 Returns the Standard Core module IDs and versions          **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierScModuleVersions
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /*
    * Array with current Standard Core package IDs and versions;
    * SC_PACKAGE_IDS taken from ScModuleVersions.h (generated by APM Tool)
    */
   static const uint8 scPackageIds[] = CDC_SC_PACKAGE_IDS;

   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   /*
    * copy package IDs and versions from local ROM buffer to response:
    */
   /* Function returns always the first parameter
     so the return value can be ignored */
   (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) resDataPtr,
                            (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) scPackageIds,
                            sizeof(scPackageIds)
                          );
   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)(2 + sizeof(scPackageIds));
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierDtcsOfSecondaryErrMem              **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2000_DTCS_OF_SECONDARY_ERR_MEM                    **
**                 Returns the status record of the secondary error memory    **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDtcsOfSecondaryErrMem
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
   Dem_ReturnSetDTCFilterType resultSetDtcFilter;
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];
   boolean     bNegResp   = FALSE;

   /* confirmed DTCs                                                          */
   resultSetDtcFilter = Dem_SetDTCFilter (
      (Dem_DTCStatusMaskType)DEM_DTCSTATUSBIT_CDTC,
      DEM_DTC_KIND_ALL_DTCS,
      DEM_DTC_ORIGIN_SECONDARY_MEMORY,
      DEM_FILTER_WITH_SEVERITY_NO,
      DEM_SEVERITY_NO_SEVERITY,
      DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO );

   if (resultSetDtcFilter == DEM_WRONG_FILTER)
   {
      /* should never happen                                                  */
      *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      Dem_ReturnGetNextFilteredDTCType    resultGetNextDtc;
      Dem_DTCStatusMaskType               dtcStatusMask;
      Dem_DTCType                         reqDtc;

      resultGetNextDtc = DEM_FILTERED_OK;

      /* set response data length to be updated later                         */
      pMsgContext->resDataLen = (Dcm_MsgLenType)2U;

      /* loop until no matching DTC is found or the response buffer got to
       * small */
      do
      {
         /* check if buffer size suffices                                     */
         if ( (pMsgContext->resDataLen + (Dcm_MsgLenType)4U) > pMsgContext->resMaxDataLen )
         {
            /* data cannot be transmitted - DCM buffer too small              */
            *ResponseCode = DCM_E_RESPONSE_TOO_LONG;

            bNegResp = TRUE;
         }
         else
         {
            /* collect DTC info                                               */
            resultGetNextDtc = Dem_GetNextFilteredDTC(&reqDtc, &dtcStatusMask);

            if (resultGetNextDtc == DEM_FILTERED_OK)
            {
               /* append 4 bytes to the response buffer                       */
               *resDataPtr++ = CDC_GETHILOBYTE(reqDtc);
               *resDataPtr++ = CDC_GETLOHIBYTE(reqDtc);
               *resDataPtr++ = CDC_GETLOLOBYTE(reqDtc);
               *resDataPtr++ = (Dcm_MsgItemType)dtcStatusMask;

               /* Update response length: the initial response data length was
                * set before the do-while-loop */
               pMsgContext->resDataLen += (Dcm_MsgLenType)4U;
            }
            /* else: do nothing if filtered DTC has wrong translation or no
             * matching DTC was found */
         }
      }
      while ((resultGetNextDtc != DEM_FILTERED_NO_MATCHING_DTC)
             && (! bNegResp));
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierDtcRange                           **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2001_DTC_RANGE_MIN_VALUE - ...MAX_VALUE           **
**                 Returns the DTC record of the secondary error memory       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 uint16 pendingDataIdentifier                               **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (8U >= DCM_BUFFER_LENGTH)
   #error "Cdc_Application_Mandatory.c: The response length for service ReadDataByIdentifier DTCs of secondary memory is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDtcRange
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONST(uint16,AUTOMATIC) pendingDataIdentifier,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
   Dem_ReturnSetDTCFilterType resultSetDtcFilter;
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];
   Dcm_NegativeResponseCodeType negResCode = DCM_E_OK;

   /* confirmed DTCs                                                          */
   resultSetDtcFilter = Dem_SetDTCFilter (
      (Dem_DTCStatusMaskType)DEM_DTCSTATUSBIT_CDTC,
      DEM_DTC_KIND_ALL_DTCS,
      DEM_DTC_ORIGIN_SECONDARY_MEMORY,
      DEM_FILTER_WITH_SEVERITY_NO,
      DEM_SEVERITY_NO_SEVERITY,
      DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO );

   if (resultSetDtcFilter == DEM_WRONG_FILTER)
   {
      /* should never happen                                                  */
      negResCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      Dem_ReturnGetNextFilteredDTCType resultGetNextDtc;
      Dem_DTCStatusMaskType dtcStatusMask;
      Dem_DTCType           reqDtc;
      uint16_least          DtcCtr;

      resultGetNextDtc=DEM_FILTERED_WRONG_DTCKIND;

      /* Get the nth filtered DTC from the secondary event memory             */
      for ( DtcCtr = 0U;
            DtcCtr <= ((uint16_least)pendingDataIdentifier -
                       (uint16_least)DIAG_DID_2001_DTC_RANGE_MIN_VALUE);
            ++DtcCtr
          )
      {
         /* skip over DTCs with wrong kind                                    */
         do
         {
            /* retrieve the DTC status from the DEM                           */
            resultGetNextDtc = Dem_GetNextFilteredDTC(&reqDtc, &dtcStatusMask);
         }
         while (resultGetNextDtc == DEM_FILTERED_WRONG_DTCKIND);
      }

      if (resultGetNextDtc == DEM_FILTERED_OK)
      {
         Dem_ReturnGetSizeOfFreezeFrameType resultGetSizeOfFF;

         uint8 recNum = 0U;
         uint16 firstFFSize = 0U;
         uint16 allFFsSize  = 0U;

         /* Get size of first freeze frame record                             */
         resultGetSizeOfFF = Dem_GetSizeOfFreezeFrame(
            reqDtc,
            DEM_DTC_KIND_ALL_DTCS,
            DEM_DTC_ORIGIN_SECONDARY_MEMORY,
            1U, /* first freeze frame record */
            &firstFFSize );

         if (   (resultGetSizeOfFF == DEM_GET_SIZEOFFREEZEFRAMETYPE_OK)
             && (firstFFSize > (uint8)0U))
         {
            /* Get size of all freeze frame records                           */
            resultGetSizeOfFF = Dem_GetSizeOfFreezeFrame(
               reqDtc,
               DEM_DTC_KIND_ALL_DTCS,
               DEM_DTC_ORIGIN_SECONDARY_MEMORY,
               0xFFU, /* all freeze frame records */
               &allFFsSize );

            if (resultGetSizeOfFF == DEM_GET_SIZEOFFREEZEFRAMETYPE_OK)
            {
               /* calculate number of stored freeze frame records of selected
                * DTC - therefore it is assumed, that all records have the same
                * size */
               recNum = (uint8)(allFFsSize / firstFFSize);
            }
         }

         if (recNum > 0U)
         {
            Dem_DTCSeverityType sev = DEM_SEVERITY_NO_SEVERITY;
            Dem_ReturnGetSeverityOfDTCType sevStatus;

            uint8 size;
            uint8_least recNumCtr;

            /* Get severity of DTC and store it into sev                      */
            /* When function returns a value != E_OK the variable 
              &sev is not overwritten thus the return value can be ignored */
            (void)Dem_GetSeverityOfDTC(
               reqDtc,
               DEM_DTC_ORIGIN_SECONDARY_MEMORY,
               &sev,
               &sevStatus );

            /* DEM severity numbers comply with severity byte values defined in
             * ISO-14229 Annex D */
            *resDataPtr++ = (uint8)sev;

            *resDataPtr++ = CDC_GETHILOBYTE(reqDtc);
            *resDataPtr++ = CDC_GETLOHIBYTE(reqDtc);
            *resDataPtr++ = CDC_GETLOLOBYTE(reqDtc);
            *resDataPtr++ = (Dcm_MsgItemType)dtcStatusMask;

            *resDataPtr++ = recNum;

            /* response data length: 2 byte DataID + 6 byte from above        */
            pMsgContext->resDataLen = (Dcm_MsgLenType)8U;

            /* append data for all stored freeze frame records to the response
             * buffer until all FF records are written or buffer size is
             * exceeded */
            for ( recNumCtr = 1U;
                  (recNumCtr <= (uint8_least)recNum)
                     && (negResCode == DCM_E_OK);
                  ++recNumCtr )
            {
               Dem_ReturnGetFreezeFrameDataByDTCType resultGetFFData;

               /* calculate maximal remaining buffer size                     */
               size = (uint8)
                  (((Dcm_MsgLenType)(pMsgContext->resMaxDataLen
                                     - pMsgContext->resDataLen)
                    < (Dcm_MsgLenType)0xFFU) ?
                   (pMsgContext->resMaxDataLen - pMsgContext->resDataLen) :
                   0xFFU);

               resultGetFFData = Dem_GetFreezeFrameDataByDTC(
                  reqDtc,
                  DEM_DTC_KIND_ALL_DTCS,
                  DEM_DTC_ORIGIN_SECONDARY_MEMORY,
                  (uint8)recNumCtr, /* record number */
                  (uint16)0xFFFFU, /* all DIDs */
                  resDataPtr,
                  &size );

               if (resultGetFFData == DEM_GET_FFDATABYDTC_OK)
               {
                  /* adjust size because first 2 bytes (FF record number) are
                   * discarded */
                  size -= (uint8)2U;
                  /* shift freeze frame data by 2 bytes                       */
                  /* Function returns always the first parameter
                     so the return value can be ignored */
                  (void)CDC_SC_MEMMOVE(resDataPtr, &resDataPtr[2], size);
                  /* adjust the response buffer length                        */
                  pMsgContext->resDataLen += (Dcm_MsgLenType)(size);
                  resDataPtr              += size;
               }
               else
               {
                  /* presumably small buffer error */
                  negResCode = DCM_E_CONDITIONSNOTCORRECT;
               }
            }

            if (negResCode == DCM_E_OK)
            {
               Dem_ReturnGetExtendedDataRecordByDTCType resultGetEDRec;

               /* calculate maximal remaining buffer size                     */
               size = (uint8)
                  (((Dcm_MsgLenType)(pMsgContext->resMaxDataLen
                                     - pMsgContext->resDataLen)
                    < (Dcm_MsgLenType)0xFFU) ?
                   (pMsgContext->resMaxDataLen - pMsgContext->resDataLen) :
                   0xFFU);

               /* append the extended data records to the response buffer     */
               resultGetEDRec = Dem_GetExtendedDataRecordByDTC(
                  reqDtc,
                  DEM_DTC_KIND_ALL_DTCS,
                  DEM_DTC_ORIGIN_SECONDARY_MEMORY,
                  (uint8)0xFFU, /* all extended data records */
                  resDataPtr,
                  &size );

               if (resultGetEDRec == DEM_RECORD_OK)
               {
                  /* adjust the response buffer length                        */
                  pMsgContext->resDataLen += (Dcm_MsgLenType)size;
               }
               else
               {
                  /* presumably small buffer error */
                  negResCode = DCM_E_CONDITIONSNOTCORRECT;
               }
            }
         }
         else
         {
            /* error - requested freeze frame data of DTC not found */
            negResCode = DCM_E_CONDITIONSNOTCORRECT;
         }
      }
      else
      {
         /* error - requested DTC not found */
         negResCode = DCM_E_CONDITIONSNOTCORRECT;
      }
   }

   if ( negResCode != DCM_E_OK )
   {
      *ResponseCode = negResCode;
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierSGBDIndex                          **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -  DIAG_DID_F150_SGBD_INDEX    **
**                 Returns the SGBD-Index                                     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (DIAG_DID_F150_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Application_Mandatory.c: The response length for service ReadDataByIdentifier SGBDIndex is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSGBDIndex
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /*
    * 3-bytes SGBD-Index is used by to identify the actual implementation
    * version of the diagnosis module.
    */

   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   *resDataPtr++ = CDC_SGBD_INDEX_FIRST_BYTE;
   *resDataPtr++ = CDC_SGBD_INDEX_SECOND_BYTE;
   *resDataPtr   = CDC_SGBD_INDEX_THIRD_BYTE;

   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F150_RESPONSE_LENGTH;
 
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_PostProcessReadDataByIdentifier                        **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) - post handler                 **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint16 pendingDataIdentifier                               **
**                 Dcm_ConfirmationStatusType status                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_PostProcessReadDataByIdentifier
(
   CONST(uint16,AUTOMATIC) pendingDataIdentifier,
   Dcm_ConfirmationStatusType status
)
{
   /*
    * 'pMsgContext' can not be used here - it is released before call of
    * 'Rte_DcmCondirmation'
    */
    if(DIAG_DID_1704_DARH_DTC == pendingDataIdentifier)
    {
        /* in case of success -> post processing of DARH                     */
        /* Return value is always E_OK and can be ingored */
        (void)CDC_DARH_READDATABYIDTRANSMISSION(status);      
    }
    else
    {
        /* unknown sub parameter                                             */
#if (CdcUseUserExtension == STD_ON)
        /* try to find an user extended diagnostic DataId in Cdc_User.c      */
        /* Return value != E_OK can be ingored in this case */
        (void)Cdc_PostProcessReadDataByIdentifier_User (pendingDataIdentifier, status);
#endif        
    }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_WriteDataByIdentifierTestStamp                         **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 WriteDataByIdentifier (0x2E) -  DIAG_DID_1000_TEST_STAMP   **
**                 Returns the teststamp                                      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_WriteDataByIdentifierTestStamp
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
   uint8_least  iLoop;                           /* temporary loop variable   */

   /*
    * copy test stamp from request to global buffer:
    * do not use memcpy for 3 bytes
    */
   if (pMsgContext->reqDataLen != (uint16)(2 + sizeof(Cdc_NvData.testStamp)))
   {
      *ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }
   else
   {
      for ( iLoop = (uint8_least)0;
            iLoop < (uint8_least)sizeof(Cdc_NvData.testStamp);
            iLoop++
          )
      {
         Cdc_NvData.testStamp[iLoop] = pMsgContext->reqData[2 + iLoop];
      }
   }

    /* Immediately save the RAM block to NVRAM. */
    if(E_OK == NvM_WriteBlock(CdcNvMTestStampBlockIdRef, NULL_PTR))
    {
        /* wait until NvM is ready for last NvM job           */
        if(FALSE == CDC_WAITNVMREADY(CdcNvMTestStampBlockIdRef))
        {
            *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    
   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)2;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ConfirmationRoutineControl                             **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) - post handler                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : const uint16 pendingDataIdentifier                         **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ConfirmationRoutineControl
(
   CONST(uint16,AUTOMATIC) pendingRoutineIdentifier
)
{
   /*
    * 'pMsgContext' can not be used here - it is released before call of
    * 'Rte_DcmCondirmation'
    */

   switch(pendingRoutineIdentifier)
   {

#if (CDC_SC_CSM_ENABLE == STD_ON)
      case DIAG_RID_020C_CSM_F30:
         /* no break */
      case DIAG_RID_020D_CSM_F40:
         /* no break */
      case DIAG_RID_020E_CSM_F60:
         /* no break */
      case DIAG_RID_020F_CSM_F70:
         CDC_CSM_TPSENDCONFIRMATION(DIAG_UDS31_SERVICE_ROUTINE_CONTROL);

         break;
#endif /* CDC_SC_CSM_ENABLE == STD_ON */

#if (CDC_STANDARD_CORE_TEST == STD_ON)
      case DIAG_RID_0302_STANDARD_CORE_TEST:
         CDC_CBK_TESTCONFIRMATION();
         break;
#endif /* CDC_STANDARD_CORE_TEST == STD_ON */

     default:
        /* no post handler for 'pendingDataIdentifier' available              */
#if (CdcUseUserExtension == STD_ON)
        /* try to find an user extended diagnostic RoutineId in Cdc_User.c    */
        (void)Cdc_ConfirmationRoutineControl_User (pendingRoutineIdentifier);
#endif
        break;
  }
} /* Cdc_ConfirmationRoutineControl                                           */


#if (CDC_STANDARD_CORE_TEST == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_RoutineControlWatchdogTriggerStop                      **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_0209_WATCHDOG_TRIGGER_STOP                        **
**                 set a cycle counter for the disabling of the triggering    **
**                 of the watchdog                                            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_RoutineControlWatchdogTriggerStop
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* call user callback to disable watchdog triggering
    * pMsgContext->reqData[3] = remainingTimeInS
    */
   CDC_USERCALLBACK_WATCHDOGTRIGGERSTOP(pMsgContext->reqData[3]);

}
#endif /* (CDC_STANDARD_CORE_TEST == STD_ON) */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_RoutineControlDiagCommLoopback                         **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_0303_DIAG_COMM_LOOPBACK                           **
**                 Send the request back as response.                         **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_RoutineControlDiagCommLoopback
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   Dcm_MsgType reqDataPtr = &pMsgContext->reqData[3];
   Dcm_MsgType resDataPtr = &pMsgContext->resData[3];

   if ( resDataPtr != reqDataPtr )
   {
      /*
       * copy request data to response
       */
      /* Function returns always the first parameter
         so the return value can be ignored */
      (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA))  resDataPtr,
                               (P2CONST(void, AUTOMATIC, CDC_FAR_DATA))reqDataPtr,
                               (pMsgContext->reqDataLen - (Dcm_MsgLenType)3)
                             );
   }

   /* set the length for the positive response                                */
   pMsgContext->resDataLen = pMsgContext->reqDataLen;
}


#if (CDC_DM_TEST == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_RoutineControlDmTest                                   **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) - DIAG_RID_0304_DM_TEST              **
**                 DM test function                                           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_RoutineControlDmTest
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
   if (pMsgContext->reqDataLen == (Dcm_MsgLenType)4U)
   {
      Dem_DTCType dtc = 0U;
      Dem_ReturnGetDTCOfEventType statusDTC;

      if (pMsgContext->reqData[3] == 0U)
      {
         Dem_ReportErrorStatus(CdcDmTestApplEventRef, DEM_EVENT_STATUS_FAILED);
         Dem_GetDTCOfEvent(CdcDmTestApplEventRef, DEM_DTC_KIND_ALL_DTCS, &dtc, &statusDTC);
      }
      else if (pMsgContext->reqData[3] == 1U)
      {
         Dem_ReportErrorStatus(CdcDmTestComEventRef, DEM_EVENT_STATUS_FAILED);
         Dem_GetDTCOfEvent(CdcDmTestComEventRef, DEM_DTC_KIND_ALL_DTCS, &dtc, &statusDTC);
      }
      else
      {
         /* else: wrong parameter, do no action */
         *ResponseCode = DCM_E_REQUESTOUTOFRANGE;
      }

      /* set response indirect - 71, 01,03,04,0?,xx,yy,zz */
      pMsgContext->resData[3] = pMsgContext->reqData[3];
      pMsgContext->resData[4] = CDC_GETHILOBYTE(dtc);
      pMsgContext->resData[5] = CDC_GETLOHIBYTE(dtc);
      pMsgContext->resData[6] = CDC_GETLOLOBYTE(dtc);
      pMsgContext->resDataLen = 7U;
   }
   else
   {
      *ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }
}
#endif /* (CDC_DM_TEST == STD_ON) */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_RoutineControlClearDtcSecondaryMemory                  **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_0F06_CLEAR_DTC_SECONDARY_MEMORY                   **
**                 Clear the DTC from the secondary error memory              **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_RoutineControlClearDtcSecondaryMemory
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{

   /* request length check                                                    */
   if (pMsgContext->reqDataLen != (uint16)3)
   {
      *ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      /* return is used for faster execution and decrease nesting depth       */
      return;
   }
   
   if( DEM_CLEAR_OK != Dem_ClearDTC( DEM_DTC_GROUP_ALL_DTCS,
                                     DEM_DTC_KIND_ALL_DTCS,
                                     DEM_DTC_ORIGIN_SECONDARY_MEMORY
                                    ))
    {
        *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
    }

   /* set the length for the positive response                                */
   pMsgContext->resDataLen = pMsgContext->reqDataLen;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_RoutineControlSetVsmOperationMode                      **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_0F0C_SET_VSM_OPERATION_MODE                       **
**                 Set the actual vehicle operation mode                      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_RoutineControlSetVsmOperationMode
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
   P2CONST(uint8, AUTOMATIC, CDC_CONST_DCMDATA) pVSMOperationMode;
   CDC_VSM_OPERATINGMODETYPE                    oldVSMOperationMode;

#if (CDC_BAC_VERSION == CDC_BAC3X)
    Dcm_SesCtrlType   ActiveSession;
    
    /* activeDiagnosticSession MSB: get active session from DCM                */
    /* Function returns only E_OK so the return value can be ignored           */
    (void)Dcm_GetSesCtrlType(&ActiveSession);
#endif

   /* request length check                                                    */
   if (pMsgContext->reqDataLen != (uint16)4)
   {
      *ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /** preconditions are correct                                             **/

   pVSMOperationMode = &pMsgContext->reqData[3];

#if (CDC_BAC_VERSION == CDC_BAC3X)
   switch ( ActiveSession )
#endif    
#if (CDC_BAC_VERSION == CDC_BAC21)
   switch ( Dcm_GetSesCtrlType() )
#endif   
   {
      case DEFAULT_SESSION:
         /* check VSM operation mode parameter                                */
         switch (*pVSMOperationMode)
         {
            case CDC_VSM_MM_MODE_BMW_FLASH:
               /* VSM operation mode change to 'FLASH' no allowed             */
               *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
               break;
            case CDC_VSM_MM_MODE_NORMAL:
               /* no break */
            case CDC_VSM_MM_MODE_ASSEMBLY:
               /* no break */
            case CDC_VSM_MM_MODE_TRANSPORT:
               if ( activeSubSession == DEFAULT_APPL_FLASH_MODE_ACTIVATED )
               {
                  /* the FMA mode have been exited
                   * activate error memory
                   */
                  /* Return value is ignored because a value != E_OK is not possible in this case */
                  (void)Dem_EnableDTCStorage(DEM_DTC_GROUP_ALL_DTCS,
                                             DEM_DTC_KIND_ALL_DTCS);
                  /* store the actual error memory state for CDC handling     */
                  isErrorMemoryEnabled = TRUE;

                  /* communication must be activated                          */
                  /* A return value != E_OK can be ignored in this case */
                  (void)CDC_SETCOMMUNICATIONMODE(
                                    DIAG_UDS28_00_ENABLE_RX_AND_TX,
                                    DIAG_UDS28_01_NORMAL_COMM_MSG
                                                );

#if (DCM_ROE_ENABLED == STD_ON)
                  /* the ROE functionality can release the suspended mode    */
                  /* A return value != E_OK can be ignored in this case */
                  (void)Cdc_SetRoeSuspendedStatus( FALSE );
#endif /* (DCM_ROE_ENABLED == STD_ON) */
               }
               /* change to any other VSM operation mode is allowed           */
               activeSubSession = DEFAULT_APPL_FLASH_MODE_DEACTIVATED;
               break;
            default:
               /* VSM operation mode not supported                            */
               *ResponseCode = DCM_E_REQUESTOUTOFRANGE;
               break;
         } /* switch (*pVSMOperationMode)                                     */
         break;
      case EXTENDED_DIAGNOSTIC_SESSION:
         /* check VSM operation mode parameter                                */
         switch (*pVSMOperationMode)
         {
            case CDC_VSM_MM_MODE_BMW_FLASH:
               /*
                * FP_5624: change to EnergyMode=Flash only possible in sub
                * session STARTED (error entries must be possible)
                */
               if (activeSubSession != EXTENDED_APPL_STARTED)
               {
                  /*
                   * change to EnergyMode=Flash not possible in other sub
                   * sessions -> change to sub session FLASH_EXIT
                   * only in FLASH_MODE_ACTIVATED stay in this sub session
                   */
                  if ( activeSubSession != EXTENDED_APPL_FLASH_MODE_ACTIVATED )
                  {
                     activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  }

                  *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
               }
               break;
            case CDC_VSM_MM_MODE_NORMAL:
               /*
                * activate communication on change from FLASH_MODE_ACTIVATED to
                * FlashExit
                */
               if ( activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED )
               {
                  /* activate error memory                                    */
                  /* Return value is ignored because a value != E_OK is not possible in this case */
                  (void)Dem_EnableDTCStorage(DEM_DTC_GROUP_ALL_DTCS,
                                             DEM_DTC_KIND_ALL_DTCS);
                  /* store the actual error memory state for CDC handling     */
                  isErrorMemoryEnabled = TRUE;

                  /* communication must be activated                          */
                  /* A return value != E_OK can be ignored in this case */
                  (void)CDC_SETCOMMUNICATIONMODE(
                                    DIAG_UDS28_00_ENABLE_RX_AND_TX,
                                    DIAG_UDS28_01_NORMAL_COMM_MSG
                                                );
               }
               /*
                * set of the Normal mode in other sub sessions than NORMAL
                * causes a change to the FLASH_EXIT sub session
                */
               if (activeSubSession != EXTENDED_APPL_STARTED)
               {
                  /* pos. Resp. and go to sub-session FLASH_EXIT              */
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
               }
               break;
            case CDC_VSM_MM_MODE_ASSEMBLY:
               /* no break */
            case CDC_VSM_MM_MODE_TRANSPORT:
               switch (activeSubSession)
               {
                  case EXTENDED_APPL_STARTED:
                     /*
                      * setting of the EnergyMode=Fe/Tra is possible here
                      * but go to sub-session FLASH_EXIT
                      */
                     activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                     break;
                  case EXTENDED_APPL_DTC_OFF:
                     /* set of neg.Resp. CNC below in FLASH_MODE_ACTIVATED!   */
                     /* go to sub-session FLASH_EXIT                          */
                     /* no break */
                  case EXTENDED_APPL_NDC_DISABLED:
                     /* set of neg.Resp. CNC below in FLASH_MODE_ACTIVATED!   */
                     /* go to sub-session FLASH_EXIT                          */
                     activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                     /* no break */
                  case EXTENDED_APPL_FLASH_MODE_ACTIVATED:
                     /*
                      * setting of the EnergyMode=Fe/Tra is not possible here
                      */
                     *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
                     /* stay in sub session FLASH_MODE_ACTIVATED              */
                     break;
                  case EXTENDED_APPL_FLASH_EXIT:
                     /* Function returns only E_OK so the return value can be ignored */
                     (void)CDC_VSM_GETMODE( &oldVSMOperationMode );
                     if ( ( oldVSMOperationMode == CDC_VSM_MM_MODE_NORMAL ) &&
                          ( isErrorMemoryEnabled == FALSE )
                        )
                     {
                        /*
                         * setting of the EnergyMode=Fe/Tra is not possible in
                         * sub session FLASH_EXIT if oldEnergyMode=Normal and
                         * the error memory is disabled - stay in FLASH_EXIT
                         */
                        *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
                     }
                     /*
                      * In the other cases a change of the EnergyMode is
                      * possible - stay in FLASH_EXIT
                      */
                     break;
                  default:
                     /* sub-session not supported in the ExtendedSession      */
                     *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
                     break;
               } /* switch (activeSubSession)                                 */

               break;
            default:
               /* VSM operation mode not supported                            */
               *ResponseCode = DCM_E_REQUESTOUTOFRANGE;
               break;
         } /* switch (*pVSMOperationMode)                                     */
         break;
      default:
         /* operation mode change only in Default and Exteded session allowed */
         *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
         break;
   } /* switch ( Dcm_GetSesCtrlType() )                                       */


   /* only if no neg. resp. code was set,set the new operation mode           */
   if ( *ResponseCode == DCM_E_OK )
   {
      /* set the operation mode in the VSM and write it to nvram              */
      if( Cdc_ProceedVsmOperationModeChange(*pVSMOperationMode) == FALSE )
      {
         /*  setting the new op. mode (clear DEM event) failed                */
         *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
      }
      else
      {
         pMsgContext->resDataLen = (uint16)3;
      }
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_RoutineControlSetVsmExtendedOperationMode              **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_1003_SET_VSM_OPERATION_MODE_EXTENSION             **
**                 Set the actual vehicle operation mode extension            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_RoutineControlSetVsmExtendedOperationMode
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
   /* cache extended mode param                                               */
   P2CONST(uint8, AUTOMATIC, CDC_CONST_DCMDATA) pNewOpModeExtension;
   CDC_VSM_OPERATINGMODETYPE op_mode;
#if (CDC_BAC_VERSION == CDC_BAC3X)
    Dcm_SesCtrlType   ActiveSession;
    
    /* activeDiagnosticSession MSB: get active session from DCM                */
    /* Function returns only E_OK so the return value can be ignored           */
    (void)Dcm_GetSesCtrlType(&ActiveSession);
#endif

   /* check request length                                                    */
   if (pMsgContext->reqDataLen != (uint16)4)
   {
      *ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }

   /* get actual VSM operation mode ( = energy mode )                         */
   /* Function returns only E_OK so the return value can be ignored           */
   (void)CDC_VSM_GETMODE( &op_mode );

   if ( ( *ResponseCode == DCM_E_OK ) && ( op_mode == CDC_VSM_MM_MODE_NORMAL ) )
   {
      /*
       * "SAP10000784 -  2.2.7.2 Erweiterter Betriebsmodus":
       * set of the operation mode extension only allowed in FeTraFla operation
       * mode
       */
      *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   if ( *ResponseCode != DCM_E_OK )
   {
      /* switch at neg.resp. in ExtendedSession != FMA to FLASH_EXIT          */
#if (CDC_BAC_VERSION == CDC_BAC3X)      
      if ( ( EXTENDED_DIAGNOSTIC_SESSION == ActiveSession ) &&
#endif     
#if (CDC_BAC_VERSION == CDC_BAC21)      
      if ( ( Dcm_GetSesCtrlType() == EXTENDED_DIAGNOSTIC_SESSION ) &&
#endif    
           ( activeSubSession != EXTENDED_APPL_FLASH_MODE_ACTIVATED )
         )
      {
         activeSubSession = EXTENDED_APPL_FLASH_EXIT;
      }
      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* cache extended mode param                                               */
   pNewOpModeExtension = &pMsgContext->reqData[3];

#if (CDC_BAC_VERSION == CDC_BAC3X)      
   if ( EXTENDED_DIAGNOSTIC_SESSION == ActiveSession )
#endif     
#if (CDC_BAC_VERSION == CDC_BAC21)      
   if ( Dcm_GetSesCtrlType() == EXTENDED_DIAGNOSTIC_SESSION )
#endif     
   {
      /* handling for the ExtendedSession and its sub sessions                */
      switch (activeSubSession)
      {
         case EXTENDED_APPL_STARTED:
            /* no break - further handling below */
         case EXTENDED_APPL_DTC_OFF:
            /* go to sub-session FLASH_EXIT                                   */
            activeSubSession = EXTENDED_APPL_FLASH_EXIT;
            /* no break - further handling below */
         case EXTENDED_APPL_FLASH_EXIT:
            if ( op_mode == CDC_VSM_MM_MODE_BMW_FLASH )
            {
               /*
                * set of the operation mode extension not allowed
                * in BMW_FLASH operation mode in this sub sessions
                */
               *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
         case EXTENDED_APPL_NDC_DISABLED:
            if ( op_mode == CDC_VSM_MM_MODE_BMW_FLASH )
            {
               if ( *pNewOpModeExtension == (uint8)CDC_VSM_MM_MODE_EXTENSION_FLASH_ENABLED)
               {
                  /* FP_1472: check ProgrammingPreConditions                  */
                  if ( CDC_APPL_CHECKPROGRAMMINGPRECONDITIONS() == TRUE )
                  {
                     /* OK: set new sub session state FLASH_MODE_ACTIVATED    */
                     activeSubSession = EXTENDED_APPL_FLASH_MODE_ACTIVATED;
                  }
                  else
                  {
                     /*
                      * VSM operation mode extension change not possible because
                      * of not fulfilled ProgrammingPreConditions - stay in
                      * sub session NDC_DISABLED
                      */
                     *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
                  }
               }
               else
               {
                  /*
                   * in operation mode BMW_FLASH only extension FLASH_ENABLED is
                   * allowed - switch to sub session FLASH_EXIT
                   */
                  *ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
               }
            }
            else
            {
               /*
                * an operation mode extension change in VSM operation mode
                * Fe/Tra is possible but switch to sub session state FLASH_EXIT
                */
               activeSubSession = EXTENDED_APPL_FLASH_EXIT;
            }
            break;
         case EXTENDED_APPL_FLASH_MODE_ACTIVATED:
            /*
             * in this sub session only the operation mode BMW_FLASH can be
             * active - check if extension FLASH_ENABLED shall be set
             */
            if ( *pNewOpModeExtension != (uint8)CDC_VSM_MM_MODE_EXTENSION_FLASH_ENABLED)
            {
               /*
                * in operation mode BMW_FLASH only extension FLASH_ENABLED is
                * allowed - stay in sub session FLASH_MODE_ACTIVATED
                */
               *ResponseCode = DCM_E_REQUESTOUTOFRANGE;
            }
            break;
         default:
            /* sub-session not supported in the ExtendedSession               */
            *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
            break;
      } /* switch (activeSubSession)                                          */
   }
   else /* if (Dcm_GetSesCtrlType() == EXTENDED_DIAGNOSTIC_SESSION)           */
   {
        /* handling for all non-ExtendedSessions */
      if ( op_mode == CDC_VSM_MM_MODE_BMW_FLASH )
      {
        /*
          * set of the operation mode extension not allowed in BMW_FLASH
          * operation mode
        */
        *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
      }
   } /* else Dcm_GetSesCtrlType() == EXTENDED_DIAGNOSTIC_SESSION              */

   /* only if no neg. resp. code was set,set the new operation mode extension */
   if ( *ResponseCode == DCM_E_OK )
   {
      /* set the operation mode extension in the VSM                          */
      if ( CDC_VSM_DIAGMODEEXTENSIONCHANGE(*pNewOpModeExtension) == E_OK )
      {
         pMsgContext->resDataLen = (uint16)3;
      }
      else
      {
         /*
          * set the operation mode extension was rejected by the VSM
          */
         *ResponseCode = DCM_E_REQUESTOUTOFRANGE;
      }
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DemClearEventAllowedRunnable                           **
**                                                                            **
** DESCRIPTION   : This function is called whenever the VSM-OPMODE event      **
**                 entry should be cleared. The application denie or allow    **
**                 this deletion.                                             **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : boolean Allowed                                            **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : TRUE  : clearing allowed                                   **
**                 FALSE : clearing denied                                    **
**                                                                            **
** REMARKS       : This function shall only be called, if the VSM-OPMODE      **
**                 Event should be cleared !                                  **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, DEM_PUBLIC_CODE) Cdc_DemClearEventAllowedRunnable
(
   P2VAR(boolean, AUTOMATIC, RTE_CDC_APPL_VAR) Allowed
)
{
   CDC_VSM_OPERATINGMODETYPE op_mode;

   /* get the actual VSM operation mode                                       */
   CDC_VSM_GETMODE( &op_mode );

   if ( op_mode != CDC_VSM_MM_MODE_NORMAL )
   {
      /* denied deletion of CdcVsmEventOpModeRef entry
       * if VSM is not in NORMAL operation mode
       */
      *Allowed = FALSE;
   }
   else
   {
      *Allowed = TRUE;
   }
   return E_OK;
} /* end of Cdc_DemClearEventAllowedRunnable                                  */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DemClearEventAllowed                                   **
**                                                                            **
** DESCRIPTION   : This function is called whenever a event entry should be   **
**                 cleared. The application denie or allow this deletion.     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : EventId: Id of event that should cleared                   **
**                 boolean Allowed                                            **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : TRUE  : clearing allowed                                   **
**                 FALSE : clearing denied                                    **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, DEM_PUBLIC_CODE) Cdc_DemClearEventAllowed
(
   Dem_EventIdType EventId,
   P2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) Allowed
)
{
   /* for all events except for the VSM-OPMODE the clearing is allowed        */
   *Allowed = TRUE;

   if ( EventId == (Dem_EventIdType)CdcVsmEventOpModeRef )
   {
      /* only for the VSM-OPMODE event further decisions are necessary        */
      /* Function returns only E_OK so the return value can be ignored */
      (void) Cdc_DemClearEventAllowedRunnable(Allowed);
   }

   return E_OK;
} /* end of Cdc_DemClearEventAllowed                                          */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DemGetDataValueByDataId                                **
**                                                                            **
** DESCRIPTION   : Mandatory callback functions for the DEM                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint16 DataID                                              **
**                 uint8 * DemDataValueByDataIdBuffer                         **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetDataValueByDataId
(
   uint16 DataID,
   P2VAR(uint8, AUTOMATIC, RTE_CDC_APPL_VAR) DemDataValueByDataIdBuffer
)
{
   Std_ReturnType  returnCode = E_OK;
   uint8_least u8_index = (uint8_least)0;
   uint32 mile_km_value = (uint32)0xFFFFFFuL; /* holds local mile_km_value       */


   switch (DataID)
   {
      case DEM_FFS_DID_KILOMETER:
         /* get mileage from CAN and write it into the first 3 bytes
          * of the freeze frame */

#if (CdcUseRte != STD_ON)
        /* Default value is used when function returns != E_OK 
           so the return value can be ignored */
        (void)Com_ReceiveSignal( CdcKmValueComSignalIdRef,
                            #if (CDC_BAC_VERSION == CDC_BAC3X)
                               ( void*)                     &mile_km_value
                            #endif
                            #if (CDC_BAC_VERSION == CDC_BAC21)
                               ( Com_ApplicationDataRefType)&mile_km_value
                            #endif
                          );
#else
       /* read signal from RTE module                                             */
        /* Default value is used when function returns != E_OK 
           so the return value can be ignored */
       (void)Rte_Read_MileKm_Port_MileKm(&mile_km_value);
#endif /* (CdcUseRte != STD_ON) */
          
         DemDataValueByDataIdBuffer[u8_index++] = CDC_GETHILOBYTE(mile_km_value);
         DemDataValueByDataIdBuffer[u8_index++] = CDC_GETLOHIBYTE(mile_km_value);
         DemDataValueByDataIdBuffer[u8_index  ] = CDC_GETLOLOBYTE(mile_km_value);
         break;

      case DEM_FFS_DID_ABSOLUTE_TIME:
         {
            /* save 4 byte long SysTime into Freeze Frame */
            uint32 systime;
            (void)CDC_SYSTIMECLIENT_GETTIME(&systime);
            DemDataValueByDataIdBuffer[u8_index++] = CDC_GETHIHIBYTE(systime);
            DemDataValueByDataIdBuffer[u8_index++] = CDC_GETHILOBYTE(systime);
            DemDataValueByDataIdBuffer[u8_index++] = CDC_GETLOHIBYTE(systime);
            DemDataValueByDataIdBuffer[u8_index  ] = CDC_GETLOLOBYTE(systime);
         }
         break;
#if (CDC_SC_CSM_ENABLE == STD_ON)
      case DEM_FFS_DID_CSM_ERROR_CODE:
         DemDataValueByDataIdBuffer[0] = CDC_CSM_DEMERRORCODE;
         break;
#endif
      default:
         /* unknown DID */
#if (CdcUseUserExtension == STD_ON)
         /* try to find an user extended diagnostic DataId in Cdc_User.c      */
         returnCode = Cdc_DemGetDataValueByDataId_User (DataID, DemDataValueByDataIdBuffer);
#else
         returnCode = E_NOT_OK;
#endif
         break;
   }

   return returnCode;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DemGetExtendedDataRecord                               **
**                                                                            **
** DESCRIPTION   : Mandatory callback functions for the DEM                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint8 ExtendedDataRecordNumber                             **
**                 uint8 * ExtendedDataRecord                                 **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : uint8 * ExtendedDataRecord                                 **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetExtendedDataRecord
(
   uint8 ExtendedDataRecordNumber,
   P2VAR(uint8, AUTOMATIC, RTE_CDC_APPL_VAR) ExtendedDataRecord
)
{
   Std_ReturnType  returnCode = E_OK;
   /*
    * This is only a sample implementation.
    */
#if (CdcUseUserExtension == STD_ON)
   /* try to find an user extended handling in Cdc_User.c                     */
   returnCode = Cdc_DemGetExtendedDataRecord_User (ExtendedDataRecordNumber, ExtendedDataRecord);
#else
   returnCode = E_OK;
#endif

   return returnCode;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierRelativeTimeDummy                  **
**                                                                            **
** DESCRIPTION   : Dummy function used for runnable entity definition         **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE) Cdc_ReadDataByIdentifierRelativeTimeDummy(void)
{
   /*dummy function*/
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierKilometerDummy                     **
**                                                                            **
** DESCRIPTION   : Dummy function used for runnable entity definition         **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, RTE_APPL_CODE) Cdc_ReadDataByIdentifierKilometerDummy(void)
{
   /*dummy function*/
}

#define CDC_STOP_SEC_CODE
#include <MemMap.h>

/*** End of file **************************************************************/
