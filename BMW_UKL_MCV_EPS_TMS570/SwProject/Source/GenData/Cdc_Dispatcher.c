/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Cdc_Dispatcher.c                                              **
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
**              to specification for AUTOSAR                                  **
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
** gema         Markus Gerngross           MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
** gk           Guenter Kothgasser         BMW Group                          **
** ft           Florian Tausch             MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.2.1 : 13.05.2011, ft  : CR70811: CDC: Missing SWT-Preparation 
 * V1.2.0 : 14.04.2011, gk  : CR70960: Programming interface for Slave CPU 
 * V1.1.4 : 22.02.2011, muer: CR70962: EcuM_KillAllRUNRequest handling changed to optional
 *						      CR70919: some MISRA warnings removed
 * V1.1.3 : 24.06.2010, anam: CR70612: Configuration of UserExtension for asynchronous request handling
                              CR70703: Wrong neg response code in case of disabled coding module  
 * V1.1.2 : 08.04.2010, anam: CR70611: Adapt *.bmd files to support AR Rel. 3.1 configuration process 
 *                      anam: CR70618: Cdc_DcmCheckResponseCode has return type    
 * V1.1.1 : 08.04.2010, anam: CR70580: BMWAutosarCoreVersion should be now a 
 *                                     constant expression in bmd file
 * V1.1.0 : 23.02.2010, gema: CR70417, CDC: Module extension to 3.0
 * V1.0.7 : 13.01.2010, gema: CR70390, Compiler switches shall have defined values
 *                            CR70381: 61773: Sizecheck at ClearDTCSecondaryMemory
 * V1.0.6 : 06.11.2009, muer: CR70461: Code Size Optimization - Cdc - BAC HIS 
 *                                     implementation guidelines
 * V1.0.5 : 05.11.2009, gema: CR70430: changed Getter/Setter function for 
 *                                     BootMode (Rte_DcmGetSesChgPermission)
 *          06.10.2009, hauf: CR70283: avoid locking of error memory more than
 *                                     once
 * V1.0.4 : 03.07.2009, dabu: CR70255: unlock all DTCs after leaving flash mode
 *          30.06.2009, hauf: CR70188: changed name of DCM session defines
 *          25.06.2009, dabu: CR70223: Implementation of Cdc review results
 *          19.06.2009, dabu: CR70230: wrong neg. Resp. in CommunicationControl
 *                                     with unsupp.type in EXTENDED_APPL_DTC_OFF
 * V1.0.3 : 19.03.2009, dabu: CR70162: Rte_DcmCompareKey() didn't work with
 *                                     security level 1 and enable user exten.
 * V1.0.2 : 18.11.2008, dabu: BSCCDC-47: isPagedProcessingExecuted is'nt defined
 *                                       in case of deactivated paged buffering
 * V1.0.1 : 23.09.2008, dabu: CR70015: no sub session change on neg. Resp. for
 *                                     ReadDataById and RoutineControl 0203,
 *                                     0204, 0205 and TesterPresent
 * V1.0.0 : 15.08.2008, dabu: BSCCDC-34: SecurityAccess: make Rte_DcmGetSeed()
 *                                       and Rte_DcmCompareKey() user extendable
 *          08.08.2008, dabu: BSCCDC-25: changed Application Extended Session
 *                                       handling according LH FP part 5 v09
 *          26.11.2007, dabu: ported from SC6.7.2 DiagServices package
 *                            version V4.0.1 from 2007-11-06
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
#if (SC_SWT_ENABLE == STD_ON)
	#include "Swt_Dcm.h"
#endif /* (SC_SWT_ENABLE == STD_ON) */
/* -------------------------------------------------------------------------- */
#include <Cdc_Cfg.h>                /* module configuration h-file            */
/* -------------------------------------------------------------------------- */
#include <Cdc_Common_Mandatory.h>   /* prototypes of the CDC common functions */
/* -------------------------------------------------------------------------- */
#if (CdcScenarioApplication == STD_ON)
#include <Cdc_Application_Mandatory.h> /* prototypes of the CDC appl. fcts.   */
#endif
/* -------------------------------------------------------------------------- */
#if (CdcUseUserExtension == STD_ON)
#include <Cdc_User.h>               /* prototypes of the CDC user functions   */
#endif
/* -------------------------------------------------------------------------- */
#include <Rte_dcm.h>                /* DCM wrapper                            */
/* -------------------------------------------------------------------------- */
#include <Dcm.h>                    /* DCM API                                */
/* -------------------------------------------------------------------------- */
#include <EcuM.h>                   /* AUTOSAR Ecu Manager                    */


/* Nxtr Patch - Added 09/30/12, KJS: Added this include for CDC_AUTH_LEVEL correction */
#include "CDD_Data.h"

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
#if ((CDC_COMMON_MANDATORY_H_MAJOR_VERSION != 1u) || \
     (CDC_COMMON_MANDATORY_H_MINOR_VERSION != 1u))
  #error "Wrong version of Cdc_Common_Mandatory.h found!!"
#endif
#if (CdcScenarioApplication == STD_ON)
#if ((CDC_APPLICATION_MANDATORY_H_MAJOR_VERSION != 1u) || \
     (CDC_APPLICATION_MANDATORY_H_MINOR_VERSION != 1u))
  #error "Wrong version of Cdc_Application_Mandatory.h found!!"
#endif
#endif

/* clear SuspressPositiveResponseMessageIndicationBit from SubFunction        */
#define CLEAR_SPRMIB_FLAG(SubFunction) ((~((uint8)0x80u)) & ((uint8)(SubFunction)))


/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/
#define CDC_START_SEC_CODE
#include <MemMap.h>

#if (CDC_SC_SWT_ENABLE == STD_ON)
    #define CDC_SIZEOFReadDataByIdentifierTable 17
#else
    #define CDC_SIZEOFReadDataByIdentifierTable 16  
#endif /* (CDC_SC_SWT_ENABLE == STD_ON) */

typedef void (*tCdc_ReadDataByIdentifier)(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext);

typedef struct {
tCdc_ReadDataByIdentifier fkt;
uint16 id;
}tsCdc_ReadDataByIdentifier;                  

static const tsCdc_ReadDataByIdentifier Cdc_ReadDataByIdentifierTable[CDC_SIZEOFReadDataByIdentifierTable] =
{
  {Cdc_ReadDataByIdentifierTestStamp, DIAG_DID_1000_TEST_STAMP},
  {Cdc_ReadDataByIdentifierVsmOperationMode, DIAG_DID_100A_VSM_OPERATION_MODE},
  {Cdc_ReadDataByIdentifierVsmExtendedOperationMode, DIAG_DID_100E_VSM_OPERATION_MODE_EXTENSION},
  {Cdc_ReadDataByIdentifierKilometer, DIAG_DID_1700_KILOMETER},
  {Cdc_ReadDataByIdentifierRelativeTime, DIAG_DID_1701_RELATIVE_TIME},
  {Cdc_ReadDataByIdentifierDarhDTC, DIAG_DID_1704_DARH_DTC},
  {Cdc_ReadDataByIdentifierStandardCoreVersion, DIAG_DID_1720_STANDARD_CORE_VERSION},
  {Cdc_ReadDataByIdentifierScModuleVersions, DIAG_DID_1726_STANDARD_CORE_MODULE_VERSIONS},
  {Cdc_ReadDataByIdentifierProgrammingCounter, DIAG_DID_2502_PROG_COUNTER},
  {Cdc_ReadDataByIdentifierProgrammingCounterMaxValue, DIAG_DID_2503_PROG_COUNTER_MAX_VALUE},
  {Cdc_ReadDataByIdentifierTimingParameters, DIAG_DID_2504_FLASH_TIMING_PARAMS},
#if (CDC_SC_SWT_ENABLE == STD_ON)
  {Swt_DcmReadDataByIdentifierReadEcuSwtList, DIAG_DID_3F03_SWT_READ_ECU_SWTLIST},
#endif
  {Cdc_ReadDataByIdentifierSGBDIndex, DIAG_DID_F150_SGBD_INDEX},
  {Cdc_ReadDataByIdentifierActiveDiagSession, DIAG_DID_F186_ACTIVE_DIAG_SESSION},
  {Cdc_ReadDataByIdentifierEcuManufacturingData, DIAG_DID_F18B_ECU_MANUFACTURING_DATA},
  {Cdc_ReadDataByIdentifierEcuSerialNumber, DIAG_DID_F18C_ECU_SERIAL_NUMBER},
  {Cdc_ReadDataByIdentifierVin, DIAG_DID_F190_VIN}
};

_STATIC_ FUNC(void, CDC_CODE) Cdc_DcmCheckResponseCode 
            (
                CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
                Dcm_NegativeResponseCodeType ResponseCode    
            );

#define CDC_STOP_SEC_CODE     
#include <MemMap.h>

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#define CDC_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
   _STATIC_ VAR(Rte_DcmUpdatePageType, CDC_VAR_DCMDATA) pCurrentUpdatePage = NULL_PTR;
#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */

#define CDC_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define CDC_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DcmCheckResponseCode                                      **
**                                                                            **
** DESCRIPTION   : Checks response code, if not ok set negative response      **
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
_STATIC_ FUNC(void, CDC_CODE) Cdc_DcmCheckResponseCode        
(
    CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
    Dcm_NegativeResponseCodeType ResponseCode     
)
{
    if (ResponseCode != DCM_E_OK)
    {
     Dcm_SetNegResponse(pMsgContext, ResponseCode);
    }
    /* send ProcessingDone in either cases, even if paged processing is used*/
    Dcm_ProcessingDone(pMsgContext); 
    
}/* end of function 'Cdc_GetNumberOfElementsInReadMemorySegmentationTable'   */

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmReadDataByIdentifier                                **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22)                                **
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
#if (DIAG_RDBYID_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Dispatcher.c: The max. response length for service ReadDataByIdentifier is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmReadDataByIdentifier
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
    Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
    boolean                      isPagedProcessingExecuted = FALSE;
#if (CdcEnableAsyncRequestHandling == STD_ON)
    boolean                      AsyncUserFunctionCalled = FALSE;
#endif /* (CdcEnableAsyncRequestHandling == STD_ON) */

#if ( SC_SLAVE_CPU == STD_ON )
   uint8 Appl_DcmProcessingExtern = FALSE;
#endif  /* SC_SLAVE_CPU */
    /*
    * check request length: only one DataIdentifier (DId) is supported
    */
    if (pMsgContext->reqDataLen == (uint16)2)
    {
        uint8 found=0,iLoop;
        /*
         * get DataIdentifier (DId) of the pending 'ReadDataByIdentifier' request.
         * store global for possible use in post handler
         */
        pendingDiagContext.DataOrRoutineId = CDC_MAKE16BIT( pMsgContext->reqData[0],
                                                          pMsgContext->reqData[1]
                                                        );

        for ( iLoop=0; iLoop < CDC_SIZEOFReadDataByIdentifierTable; iLoop++)
        {
            if ( pendingDiagContext.DataOrRoutineId == Cdc_ReadDataByIdentifierTable[iLoop].id )
            {
                Cdc_ReadDataByIdentifierTable[iLoop].fkt(pMsgContext);
                found = 1;
                break;
            }
        }
        if ( 0 == found )
        {
            /* dispatch between the different DataIdentifiers                       */
            switch (pendingDiagContext.DataOrRoutineId)
            {
    #if (CDC_STANDARD_CORE_TEST == STD_ON)
                case DIAG_DID_1234_STANDARD_CORE_TEST:
                    #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                       pCurrentUpdatePage = CDC_CBK_TESTUPDATEPAGE;
                    #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
                    CDC_CBK_TESTREADDATABYIDENTIFIER(pMsgContext, &isPagedProcessingExecuted);
                    break;
    #endif /* CDC_STANDARD_CORE_TEST == STD_ON */
    #if (CDC_DM_TEST == STD_ON)
                case DIAG_DID_1723_IS_DTC_ACTIVE_RESPONSE:
                    #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                       pCurrentUpdatePage = Cdc_UpdatePageRdbiDMDebug;
                    #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
                    Cdc_ReadDataByIdentifierDMDebugIsDtcActiveResponse(pMsgContext,
                                                            &isPagedProcessingExecuted);
                    break;
                case DIAG_DID_1724_IS_DTC_LOCKABLE:
                    #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                       pCurrentUpdatePage = Cdc_UpdatePageRdbiDMDebug;
                    #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
                    Cdc_ReadDataByIdentifierDMDebugIsDtcLockable(pMsgContext,
                                                            &isPagedProcessingExecuted);
                    break;
    #endif
                case DIAG_DID_2000_DTCS_OF_SECONDARY_ERR_MEM:
                    Cdc_ReadDataByIdentifierDtcsOfSecondaryErrMem(pMsgContext, &ResponseCode);
                    break;
                case DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE:
                    #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                        pCurrentUpdatePage = Cdc_ProcessReadMemorySegmentationTable;
                    #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
                    Cdc_ReadDataByIdentifierMemorySegmentationTable(pMsgContext,
                                         &ResponseCode, &isPagedProcessingExecuted);
#if ( SC_SLAVE_CPU == STD_ON )
                    Appl_DcmProcessingExtern = TRUE;
#endif  /* SC_SLAVE_CPU */
                    break;
                case DIAG_DID_F101_SVK_AKTUELL:
                    #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                        pCurrentUpdatePage = Cdc_GetCurrentSvk;
                    #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
                    Cdc_ReadDataByIdentifierSvkCurrent(pMsgContext, &ResponseCode,
                                                        &isPagedProcessingExecuted);
#if ( SC_SLAVE_CPU == STD_ON )
                    Appl_DcmProcessingExtern = TRUE;
#endif  /* SC_SLAVE_CPU */
                    break;
                case DIAG_DID_F102_SVK_SYSTEM_SUPPLIER:
                    #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                        pCurrentUpdatePage = Cdc_ProcessReadSVK;
                    #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
                    Cdc_ReadDataByIdentifierSvkSystemSupplier (pMsgContext,
                                         &ResponseCode, &isPagedProcessingExecuted);
                    break;
                case DIAG_DID_F103_SVK_PLANT:
                    #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                        pCurrentUpdatePage = Cdc_ProcessReadSVK;
                    #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
                    Cdc_ReadDataByIdentifierSvkPlant (pMsgContext, &ResponseCode,
                                                        &isPagedProcessingExecuted);
                    break;
                default:
    #if (CDC_SC_CODING_ENABLE == STD_ON)
                    if ( (pendingDiagContext.DataOrRoutineId >= (uint16)DIAG_DID_3000_CODING_BLOCK_RANGE_MIN) &&
                         (pendingDiagContext.DataOrRoutineId <= (uint16)DIAG_DID_37FE_CODING_TESTSTAMP)
                        )
                    {
                        CDC_CODING_DIAGREADDATABYIDENTIFIER(pMsgContext, pendingDiagContext.DataOrRoutineId);
                    }
                    else
    #endif
                    if ( (pendingDiagContext.DataOrRoutineId >= DIAG_DID_2001_DTC_RANGE_MIN_VALUE) &&
                         (pendingDiagContext.DataOrRoutineId <= DIAG_DID_21FF_DTC_RANGE_MAX_VALUE)
                        )
                    {
                        Cdc_ReadDataByIdentifierDtcRange( pMsgContext,
                                                        pendingDiagContext.DataOrRoutineId,
                                                        &ResponseCode
                                                        );
                    }
                    else
                    if ( (pendingDiagContext.DataOrRoutineId >= (uint16)DIAG_DID_F104_SVK_BACKUP_MIN) &&
                         (pendingDiagContext.DataOrRoutineId <= (uint16)DIAG_DID_F140_SVK_BACKUP_MAX) )
                    {
                       /* try read of backup svk                                      */
                       #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                          pCurrentUpdatePage = Cdc_ProcessReadSVK;
                       #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
                       Cdc_ReadDataByIdentifierSvkBackup(pMsgContext,
                                                     pendingDiagContext.DataOrRoutineId,
                                                     &ResponseCode,
                                                     &isPagedProcessingExecuted);
                    }
                    else
                    {
    #if (CdcUseUserExtension == STD_ON)
                        /* try to find an user extended diagnostic DataID in Cdc_User.c */
                        #if (CdcEnableAsyncRequestHandling == STD_ON)
                        (void) Rte_DcmReadDataByIdentifier_User (pMsgContext,
                        #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                                                           &pCurrentUpdatePage,
                        #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                                 */
                                                           &isPagedProcessingExecuted
                                                           );
                        AsyncUserFunctionCalled = TRUE;
                        #else
                        if ( Rte_DcmReadDataByIdentifier_User (pMsgContext,
                                                           &ResponseCode,
                        #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
                                                           &pCurrentUpdatePage,
                        #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                                 */
                                                           &isPagedProcessingExecuted
                                                           ) == E_OK )
                        {
                            /* an user extended diagnostic DataID have been found          */
                        }
                        else
                        {
                           ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                        }
                        #endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
    #else
                        ResponseCode = DCM_E_REQUESTOUTOFRANGE;
    #endif /* (CdcUseUserExtension == STD_ON)                                     */
                    }
                    break;
            }  /* end of switch case                                            */
        }
    }
    else
    {
        /* pMsgContext->reqDataLen =! (uint16)2                                 */
        if ( (pMsgContext->reqDataLen == (uint16)0) ||
            ((pMsgContext->reqDataLen & (uint16)1) == (uint16)1)
           )
        {
            /* Invalid message length                                            */
            ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
        else
        {
            /* Too many DIDs                                                     */
            ResponseCode = DCM_E_REQUESTOUTOFRANGE;
        }

        Cdc_DcmCheckResponseCode(pMsgContext, ResponseCode);    
            
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_FUNCTION_CALLED_NOT_USED, ResponseCode, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */    
        return;
    }

#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
    /* if isPagedProcessingExecuted is TRUE Dcm_ProcessingDone() have been
    * executed by the PagedBuffering
    */
    if ( isPagedProcessingExecuted == FALSE )
#endif
    {
#if (CdcEnableAsyncRequestHandling == STD_ON)
        /* If a Userfunction is called the UserFunction is responsible for the response*/
        if( FALSE == AsyncUserFunctionCalled )
#endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
        {
#if ( SC_SLAVE_CPU == STD_ON )
           if ( Appl_DcmProcessingExtern == FALSE )
           {
#endif  /* SC_SLAVE_CPU */
               Cdc_DcmCheckResponseCode(pMsgContext, ResponseCode);
#if ( SC_SLAVE_CPU == STD_ON )
           }
#endif  /* SC_SLAVE_CPU */
        }
    }
    
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_FUNCTION_CALLED_NOT_USED, ResponseCode, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */    
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmCommunicationControl                                **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 CommunicationControl (0x28)                                **
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
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmCommunicationControl
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
#if (CDC_MODULETEST_ENABLED == STD_ON)
    uint16 u16_TestFuncCalled = TEST_CDC_FUNCTION_CALLED_NOT_USED;
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */
   Dcm_SesCtrlType   ActiveSession;    
   Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
   boolean preconditionsCorrect = FALSE;

   /* Get active session */
   (void)Dcm_GetSesCtrlType(&ActiveSession);

   /*
    * check request length: 2 sub parameters are supported
    */   
   if (pMsgContext->reqDataLen != (uint16)2)
   {
      ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }

   if ( ResponseCode == DCM_E_OK )
   {
      /* only communication type 01..03 is allowed                            */
      if ( ( pMsgContext->reqData[1] != (uint8)DIAG_UDS28_01_NORMAL_COMM_MSG ) &&
           ( pMsgContext->reqData[1] != (uint8)DIAG_UDS28_02_NM_COMM_MSG )     &&
           ( pMsgContext->reqData[1] != (uint8)DIAG_UDS28_03_NORMAL_AND_NM_COMM_MSG )
         )
      {
         /* communication type is not possible / allowed                      */
         ResponseCode = DCM_E_REQUESTOUTOFRANGE;
      }
   }

   if ( ResponseCode == DCM_E_OK )
   {
      /** preconditions are correct                                          **/
      preconditionsCorrect = TRUE;

      /* Cache the sub parameter                                              */
      pendingDiagContext.SubFunction = pMsgContext->reqData[0];

      switch ( ActiveSession )
      {
         case DEFAULT_SESSION:
            /*
             * Service CommunicationControl not supported in default-session
             */
            ResponseCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
            break;
         case EXTENDED_DIAGNOSTIC_SESSION:
            /* check supported communication type                             */
            if ( ( pMsgContext->reqData[0] != (uint8)DIAG_UDS28_00_ENABLE_RX_AND_TX ) &&
                 ( pMsgContext->reqData[1] != (uint8)DIAG_UDS28_01_NORMAL_COMM_MSG )
               )
            {
               /*
                * FP_5574: communication type <> NORMAL_COMM_MSG is only allowed
                * for control type ENABLE_RX_AND_TX in the extended session
                */
               ResponseCode = DCM_E_REQUESTOUTOFRANGE;
            }
            /* handle actions in the extended sub sessions                    */
            switch ( activeSubSession )
            {
               case EXTENDED_APPL_STARTED:
                  /* all communication-changes are allowed, but change to sub
                   * session FLASH_EXIT
                   */
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  break;
               case EXTENDED_APPL_DTC_OFF:
                  /*
                   * change to sub session FLASH_EXIT if the TX direction of
                   * DisableNonDiagnosticComm. shall not be disabled
                   */
                  if ( ( pendingDiagContext.SubFunction ==
                         DIAG_UDS28_01_ENABLE_RX_AND_DISABLE_TX ) ||
                       ( pendingDiagContext.SubFunction ==
                         DIAG_UDS28_03_DISABLE_RX_AND_TX )
                     )
                  {
                     /* FP_5736: only communication type 01 is allowed        */
                     if ( pMsgContext->reqData[1]  ==
                          (uint8)DIAG_UDS28_01_NORMAL_COMM_MSG )
                     {
                        /*
                         * Change to sub session NDC_DISABLED, if programming
                         * preconditions are ok
                         */
                        if ( CDC_APPL_CHECKPROGRAMMINGPRECONDITIONS() == TRUE )
                        {
                           /* communication-change is allowed -> NDC_DISABLED */
                           activeSubSession = EXTENDED_APPL_NDC_DISABLED;
                        }
                        else
                        {
                           /*
                            * preconditions check failed -> no comm-change and
                            * stay in sub session DTC_OFF
                            */
                           ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
                        }
                     }
                     else
                     {
                        /* FP_5736: other communication types are not allowed
                         * stay in DTC_OFF
                         */
                        ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                     }
                  }
                  else
                  {
                     /*
                      * Communication change is allowed, but SubSession is
                      * changed from 'DTC_OFF' to 'FLASH_EXIT'
                      */
                     activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  }
                  break;
               case EXTENDED_APPL_NDC_DISABLED:
                  /*
                   * In case of sub session NDC_DISABLED do not change to
                   * other sub session if Sub-Par is
                   * ENABLE_RX_AND_DISABLE_TX or DISABLE_RX_AND_TX
                   * This is a repeat of the service before (LowLevel retry)
                   * Do communication change again.
                   */
                  if ( !( ( pendingDiagContext.SubFunction ==
                            DIAG_UDS28_01_ENABLE_RX_AND_DISABLE_TX ) ||
                          ( pendingDiagContext.SubFunction ==
                            DIAG_UDS28_03_DISABLE_RX_AND_TX )
                        )
                     )
                  {
                     /*
                      * Communication change is allowed, but SubSession is
                      * changed from 'NDC_DISABLED' to 'FLASH_EXIT'
                      */
                     activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  }
                  /* FP_5736: only communication type 01 is allowed           */
                  else if ( pMsgContext->reqData[1]  !=
                       (uint8)DIAG_UDS28_01_NORMAL_COMM_MSG )
                  {
                     /* FP_5736: other communication types are not allowed
                      * change to 'FLASH_EXIT'
                      */
                     activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  }
                  else
                  {
                      /* currently nothing else to do                       */
                  }
                  break;
               case EXTENDED_APPL_FLASH_EXIT:
                  /* all communication-changes are allowed, stay in FLASH_EXIT*/
                  break;
               default:
                  /* comm-changes in other sub-sess. e.g. FMA are not allowed */
                  ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
                  break;
            }
            break;
         default:
            /* In all other sessions all communication-changes are allowed    */
            break;
      }

      /* only control type 00..03 is allowed                                  */
      if ( ( pMsgContext->reqData[0] != (uint8)DIAG_UDS28_00_ENABLE_RX_AND_TX ) &&
           ( pMsgContext->reqData[0] != (uint8)DIAG_UDS28_01_ENABLE_RX_AND_DISABLE_TX ) &&
           ( pMsgContext->reqData[0] != (uint8)DIAG_UDS28_02_DISABLE_RX_AND_ENABLE_TX ) &&
           ( pMsgContext->reqData[0] != (uint8)DIAG_UDS28_03_DISABLE_RX_AND_TX )
         )
      {
         /* control type is not possible / allowed                            */
         ResponseCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
      }
   }

   /* only if no neg. resp. code was set, execute the communication change    */
   if ( ResponseCode == DCM_E_OK )
   {
      /* execute the communication change                                     */
      if ( CDC_SETCOMMUNICATIONMODE( pendingDiagContext.SubFunction,
                                     pMsgContext->reqData[1]
                                   ) == E_OK
         )
      {
#if (CDC_MODULETEST_ENABLED == STD_ON)
         u16_TestFuncCalled |= TEST_COMM_COMMUNICATIONCONTROL_CALLED;
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */          
         pMsgContext->resDataLen = (uint16)1;
      }
      else
      {
         /* communication mode change not possible (not supported)            */
         ResponseCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
      }
   }

   if (ResponseCode != DCM_E_OK)
   {
      /*
       * in extended session in other sub session than FlashModeActivated
       * change to FLASH_EXIT
       */
      if ( ( EXTENDED_DIAGNOSTIC_SESSION == ActiveSession) &&
           ( activeSubSession != EXTENDED_APPL_FLASH_MODE_ACTIVATED )
         )
      {
         /*
          * in EXTENDED_APPL_DTC_OFF is an own activeSubSession handling if the
          * the preconditions are correct
          */
         if ( ! ( ( activeSubSession == EXTENDED_APPL_DTC_OFF ) &&
                  ( preconditionsCorrect == TRUE )
                )
            )
         {
            activeSubSession = EXTENDED_APPL_FLASH_EXIT;
         }
      }
      /* communication mode change not possible                               */
      Dcm_SetNegResponse(pMsgContext, ResponseCode);
   }
   
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(u16_TestFuncCalled, ResponseCode, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */

   Dcm_ProcessingDone(pMsgContext);
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmWriteDataByIdentifier                               **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 WriteDataByIdentifier (0x2E)                               **
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
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmWriteDataByIdentifier
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
#if (CdcEnableAsyncRequestHandling == STD_ON)
   boolean                      AsyncUserFunctionCalled = FALSE;
#endif /* (CdcEnableAsyncRequestHandling == STD_ON) */

   if (pMsgContext->reqDataLen >= (uint16)2)
   {
      /*
       * get DataIdentifier (DId) of the pending 'WriteDataByIdentifier' request,
       * store global for possible use in post handler
       */
      pendingDiagContext.DataOrRoutineId = CDC_MAKE16BIT( pMsgContext->reqData[0],
                                                          pMsgContext->reqData[1]
                                                        );

      /* dispatch between the different DataIdentifiers                       */
      switch (pendingDiagContext.DataOrRoutineId)
      {
         case DIAG_DID_1000_TEST_STAMP:
            Cdc_WriteDataByIdentifierTestStamp(pMsgContext, &ResponseCode);
            break;
         default:
#if (CDC_SC_CODING_ENABLE == STD_ON)
            if ( (pendingDiagContext.DataOrRoutineId >= DIAG_DID_3000_CODING_BLOCK_RANGE_MIN) &&
                 (pendingDiagContext.DataOrRoutineId <= DIAG_DID_37FE_CODING_TESTSTAMP)
               )
            {
               CDC_CODING_DIAGWRITEDATABYIDENTIFIER(pMsgContext, pendingDiagContext.DataOrRoutineId);
            }
            else
#endif /* (CDC_SC_CODING_ENABLE == STD_ON) */
            {
#if (CdcUseUserExtension == STD_ON)
                /* try to find an user extended diagnostic DataID in Cdc_User.c */
                #if (CdcEnableAsyncRequestHandling == STD_ON)
                (void) Rte_DcmWriteDataByIdentifier_User (pMsgContext);
                AsyncUserFunctionCalled = TRUE;
                #else
                if ( Rte_DcmWriteDataByIdentifier_User (pMsgContext, &ResponseCode) == E_OK )
                {
                   /* an user extended diagnostic DataID have been found          */
                }
                else
                {
                   ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                }
                #endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
#else
               ResponseCode = DCM_E_REQUESTOUTOFRANGE;
#endif /* (CdcUseUserExtension == STD_ON)                                     */
            }
            break;
      }
   }
   else
   {
      ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }

#if (CdcEnableAsyncRequestHandling == STD_ON)
        /* If a Userfunction is called the UserFunction is responsible for the response*/
    if( FALSE == AsyncUserFunctionCalled )
#endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
    {
        Cdc_DcmCheckResponseCode(pMsgContext, ResponseCode);
    }

#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_FUNCTION_CALLED_NOT_USED, ResponseCode, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */   

}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmRoutineControl                                      **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31)                                      **
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
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmRoutineControl
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
#if (CdcEnableAsyncRequestHandling == STD_ON)
    boolean                      AsyncUserFunctionCalled = FALSE;
#endif /* (CdcEnableAsyncRequestHandling == STD_ON) */

#if ( SC_SLAVE_CPU == STD_ON )
   uint8 Appl_DcmProcessingExtern = FALSE;
#endif  /* SC_SLAVE_CPU */

   /* request length check                                                    */
   if (pMsgContext->reqDataLen > 2)
   {
      pendingDiagContext.SubFunction     = pMsgContext->reqData[0];

      pendingDiagContext.DataOrRoutineId = CDC_MAKE16BIT( pMsgContext->reqData[1],
                                                          pMsgContext->reqData[2]
                                                        );

      switch (pendingDiagContext.SubFunction)
      {
         /***************************************************** START ROUTINE */
         case DIAG_UDS31_01_START_ROUTINE:
            switch (pendingDiagContext.DataOrRoutineId)
            {
               case DIAG_RID_0203_CHECK_PROGRAMMING_PRECONDITIONS:
                  Cdc_RoutineControlCheckProgrammingPreConditions(pMsgContext, &ResponseCode);
                  break;

               case DIAG_RID_0205_READ_DEVELOPMENT_INFO:
                  Cdc_RoutineControlReadDevelopmentInfo(pMsgContext, &ResponseCode);
#if ( SC_SLAVE_CPU == STD_ON )
                  Appl_DcmProcessingExtern = TRUE;
#endif  /* SC_SLAVE_CPU */
                  break;

#if (CDC_STANDARD_CORE_TEST == STD_ON)
               case DIAG_RID_0209_WATCHDOG_TRIGGER_STOP:
                  Cdc_RoutineControlWatchdogTriggerStop(pMsgContext);
                  break;
#endif /* CDC_STANDARD_CORE_TEST == STD_ON */

#if (CDC_STANDARD_CORE_TEST == STD_ON)
               case DIAG_RID_0302_STANDARD_CORE_TEST:
                  CDC_CBK_TESTSTARTROUTINE(pMsgContext);
                  break;
#endif /* CDC_STANDARD_CORE_TEST == STD_ON */

               case DIAG_RID_0303_DIAG_COMM_LOOPBACK:
                  Cdc_RoutineControlDiagCommLoopback(pMsgContext);
                  break;

#if (CDC_DM_TEST == STD_ON)
               case DIAG_RID_0304_DM_TEST:
                  Cdc_RoutineControlDmTest(pMsgContext, &ResponseCode);
                  break;
#endif /* CDC_DM_TEST == STD_ON */

#if (CDC_SC_CODING_ENABLE == STD_ON)
               case DIAG_RID_0F01_CHECK_CODING_SIGNATURE:
                  CDC_CODING_DIAGROUTINECONTROLCHECKSIGNATURE(pMsgContext);
                  break;
#endif
               case DIAG_RID_0F06_CLEAR_DTC_SECONDARY_MEMORY:
                  Cdc_RoutineControlClearDtcSecondaryMemory(pMsgContext, &ResponseCode);
                  break;
#if (CDC_SC_SWT_ENABLE == STD_ON)
                case DIAG_RID_0F1F_SWT_OPERATION:
                  Swt_DcmRoutineControlSwtOperation(0x30, pMsgContext);/* NXTR SWT */ //  CDC_SWT_DCMROUTINECONTROLSWTOPERATION(Sgid, pMsgContext);
                  break;
#endif
               case DIAG_RID_0F0C_SET_VSM_OPERATION_MODE:
                  Cdc_RoutineControlSetVsmOperationMode(pMsgContext, &ResponseCode);
                  break;
               case DIAG_RID_1003_SET_VSM_OPERATION_MODE_EXTENSION:
                  Cdc_RoutineControlSetVsmExtendedOperationMode(pMsgContext, &ResponseCode);
                  break;

#if (CDC_SC_CSM_ENABLE == STD_ON)
               case DIAG_RID_020C_CSM_F30:
                  /* no break */

               case DIAG_RID_020D_CSM_F40:
                  /* no break */

               case DIAG_RID_020E_CSM_F60:
                  /* no break */

               case DIAG_RID_020F_CSM_F70:
                  CDC_CSM_TPRECEIVEMESSAGE(pMsgContext);
                  break;
#endif  /* CDC_SC_CSM_ENABLE == STD_ON                                        */

               default:
#if (CdcUseUserExtension == STD_ON)
                /* try to find an user extended diagnostic RoutineID in Cdc_User.c */
                #if (CdcEnableAsyncRequestHandling == STD_ON)
                (void) Rte_DcmRoutineControl_User (pMsgContext);
                AsyncUserFunctionCalled = TRUE;
                #else
                if ( Rte_DcmRoutineControl_User (pMsgContext, &ResponseCode) != E_OK )
                {
                    /* 'routineIdentifier' not supported                     */
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                }
                #endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
#else
                {
                    /* 'routineIdentifier' not supported                     */
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                }
#endif /* (CdcUseUserExtension == STD_ON)                                     */
                  break;
            }  /* switch(pendingDiagContext.DataOrRoutineId)                  */
            break;

         /****************************************************** STOP ROUTINE */
         case DIAG_UDS31_02_STOP_ROUTINE:
            switch (pendingDiagContext.DataOrRoutineId)
            {
#if (CDC_STANDARD_CORE_TEST == STD_ON)
               case DIAG_RID_0302_STANDARD_CORE_TEST:
                  CDC_CBK_TESTSTOPROUTINE(pMsgContext);
                  break;
#endif /* CDC_STANDARD_CORE_TEST == STD_ON */

               case DIAG_RID_0303_DIAG_COMM_LOOPBACK:
                  Cdc_RoutineControlDiagCommLoopback(pMsgContext);
                  break;

               default:
#if (CdcUseUserExtension == STD_ON)
                /* try to find an user extended diagnostic RoutineID in Cdc_User.c */
                #if (CdcEnableAsyncRequestHandling == STD_ON)
                (void) Rte_DcmRoutineControl_User (pMsgContext);
                AsyncUserFunctionCalled = TRUE;
                #else
                if ( Rte_DcmRoutineControl_User (pMsgContext, &ResponseCode) != E_OK )
                {
                    /* 'routineIdentifier' not supported                     */
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                }
                #endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
#else
                {
                    /* 'routineIdentifier' not supported                     */
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                }
#endif /* (CdcUseUserExtension == STD_ON)                                     */
                  break;
            }  /* switch(pendingDiagContext.DataOrRoutineId)                  */
            break;

         /**************************************************** REQUEST RESULT */
         case DIAG_UDS31_03_REQUEST_RESULT:
            switch (pendingDiagContext.DataOrRoutineId)
            {
#if (CDC_SC_CSM_ENABLE == STD_ON)
               case DIAG_RID_020C_CSM_F30:
                  /* no break */
               case DIAG_RID_020D_CSM_F40:
                  /* no break */
               case DIAG_RID_020E_CSM_F60:
                  /* no break */
               case DIAG_RID_020F_CSM_F70:
                  CDC_CSM_TPREQUESTRESULT(pMsgContext);
                  break;
#endif  /* CDC_SC_CSM_ENABLE == STD_ON                                                */

#if (CDC_STANDARD_CORE_TEST == STD_ON)
               case DIAG_RID_0302_STANDARD_CORE_TEST:
                  CDC_CBK_TESTREQUESTROUTINERESULT(pMsgContext);
                  break;
#endif /* CDC_STANDARD_CORE_TEST == STD_ON */

               case DIAG_RID_0303_DIAG_COMM_LOOPBACK:
                  Cdc_RoutineControlDiagCommLoopback(pMsgContext);
                  break;

               default:
#if (CdcUseUserExtension == STD_ON)
                /* try to find an user extended diagnostic RoutineID in Cdc_User.c */
                #if (CdcEnableAsyncRequestHandling == STD_ON)
                (void) Rte_DcmRoutineControl_User (pMsgContext);
                AsyncUserFunctionCalled = TRUE;
                #else
                if ( Rte_DcmRoutineControl_User (pMsgContext, &ResponseCode) != E_OK )
                {
                    /* 'routineIdentifier' not supported                     */
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                }
                #endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
#else
                {
                    /* 'routineIdentifier' not supported                     */
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                }
#endif /* (CdcUseUserExtension == STD_ON)                                     */
                  break;
            }  /* switch(pendingDiagContext.DataOrRoutineId)                  */
            break;

         /*********************************************************************/
         default:
            ResponseCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
            break;
      } /* SubFunction switch                                                 */
   }
   else
   {
      ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }

#if (CdcEnableAsyncRequestHandling == STD_ON)
        /* If a Userfunction is called the UserFunction is responsible for the response*/
    if( FALSE == AsyncUserFunctionCalled )
#endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
    {
#if ( SC_SLAVE_CPU == STD_ON )
           if ( Appl_DcmProcessingExtern == FALSE )
           {
#endif  /* SC_SLAVE_CPU */
               Cdc_DcmCheckResponseCode(pMsgContext, ResponseCode);
#if ( SC_SLAVE_CPU == STD_ON )
           }
#endif  /* SC_SLAVE_CPU */
    }

#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_FUNCTION_CALLED_NOT_USED, ResponseCode, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */     

}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmGetSesChgPermission                                 **
**                                                                            **
** DESCRIPTION   : Check if the given session transition is allowed or your   **
**                 ECU is currently not able to perform it.                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SesCtrlTypeActive:                                       **
**                    - Contains the current session state which the state    **
**                      group will left.                                      **
**                    - Access type: read                                     **
**                 - SesCtrlTypeNew:                                          **
**                    - Contains the new session state in which the state     **
**                      group will be set.                                    **
**                    - Access type: read                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : DCM_TRUE if the session is accepted, DCM_FALSE if not.     **
**                                                                            **
** REMARKS       : - The function "Dcm_SetNegResponse" may not be called.     **
**                 - The function "Dcm_ProcessingDone" may not be called.     **
**                                                                            **
*******************************************************************************/
FUNC(Dcm_StatusType, CDC_PUBLIC_DCMCODE) Rte_DcmGetSesChgPermission
(
   CONST(uint8,AUTOMATIC)  SesCtrlTypeActive,
   CONST(uint8,AUTOMATIC)  SesCtrlTypeNew
)
{
   Dcm_StatusType dcmSessionChangePermission = DCM_E_SESSION_NOT_ALLOWED;

   switch (SesCtrlTypeNew)
   {
      case DEFAULT_SESSION:
         /* request for default session                                       */
         switch (SesCtrlTypeActive)
         {
#if (CDC_SC_CODING_ENABLE == STD_ON)
            case CODING_SESSION:
            /* no break */
#endif
#if (CDC_SC_SWT_ENABLE == STD_ON)
            case SWT_SESSION:
            /* no break */
#endif
            case EXTENDED_DIAGNOSTIC_SESSION:
            /* no break */
            case DEFAULT_SESSION:
               /* currently nothing else to do                                */
               dcmSessionChangePermission = DCM_E_OK;
               break;
            default:
               /* session change is not not allowed                           */
               break;
         }
         break;
      case PROGRAMMING_SESSION:
         /* request for programming session                                   */
         switch (SesCtrlTypeActive)
         {
            case EXTENDED_DIAGNOSTIC_SESSION:
               /* only from sub session FlashModeActivated and NDCDisabled a session
                * change to the programming session is possible
                */
               if ( (activeSubSession == EXTENDED_APPL_NDC_DISABLED) ||
                    (activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED)
                  )
               {
                  /* session change is allowed                                */
               }
               else
               {
                  /*
                   * session change is not allowed in other sub sessions
                   * switch to sub session state FLASH_EXIT
                   */
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  break;
               }
               /* no break */
            case PROGRAMMING_SESSION:
               /*
                * the change from ProgrammingSession to ProgrammingSession could
                * never happen in Application but should be allowed
                */

               /*
                * The BootTarget has to be changed and
                * all non volatile data of the application have to be saved
                * from RAM mirror to NVRAM.
                * FP_5447: Before application is terminated, check programming
                * preconditions [optional] - not supported in this moment
                */
#if (CdcUseUserExtension == STD_ON)                             /* CR70962 */               
                if( Rte_DcmGetSesChgPermissionProgramming_User(SesCtrlTypeActive,SesCtrlTypeNew) == E_OK )
                {
#endif    
                   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&BootStatus.BootMode[0],
                                        (const void SC_FAR_POINTER)
                                           &sharedBootROMData.BootModeBootloader[0],
                                        sizeof(BootStatus.BootMode)
                                      );

                   dcmSessionChangePermission  = DCM_E_OK;
#if (CdcUseUserExtension == STD_ON)
                }
#endif
               break;
            default:
               /* session change is not allowed                           */
               break;
         }
         break;
      case EXTENDED_DIAGNOSTIC_SESSION:
         /*
          * a change from the CodingSession to the ExtendedSession is'nt allowed
          */
         if ( SesCtrlTypeActive != CODING_SESSION )
         {
            /* currently nothing else to do                                   */
            dcmSessionChangePermission = DCM_E_OK;
         }
         break;
#if (CDC_SC_CODING_ENABLE == STD_ON)
      case CODING_SESSION:
         /* request for coding session                                        */
         switch (SesCtrlTypeActive)
         {
            case EXTENDED_DIAGNOSTIC_SESSION:
               if ( ( activeSubSession == EXTENDED_APPL_DTC_OFF ) ||
                    ( activeSubSession == EXTENDED_APPL_NDC_DISABLED )
                  )
               {
                  /*
                   * session change is not allowed in DTC_OFF and NDC_DISABLED
                   * switch to sub session state FLASH_EXIT
                   */
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
               }
               else
               {
                  if ( (activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED) ||
                       ( ( activeSubSession == EXTENDED_APPL_FLASH_EXIT ) &&
                         ( isErrorMemoryEnabled == FALSE )
                       )
                     )
                  {
                     /*
                      * session change is not allowed in sub session
                      * FLASH_MODE_ACTIVATED and FLASH_EXIT (with deactivated
                      * error memory), stay in the current sub session
                      */
                  }
                  else
                  {
                     /*
                      * Handling for sub session STARTED and FLASH_EXIT (with
                      * activated error memory):
                      * session change is allowed, stay in sub session
                      * FLASH_EXIT if the Coding-entry-conditions are not
                      * fulfilled
                      */
                     /* Get coding session start permission from coding module*/
                     dcmSessionChangePermission = CDC_CODING_DIAGGETSESSIONSTARTPERMISSION();
                     if (dcmSessionChangePermission != DCM_E_OK)
                     {
                        /* switch to sub session state FLASH_EXIT             */
                        activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                     }
                  }
               }
               break;
            case CODING_SESSION:
               dcmSessionChangePermission = DCM_E_OK;
               break;
            default:
               /* session change is not allowed                               */
               break;
         }
         break;
#endif
#if (CDC_SC_SWT_ENABLE == STD_ON)
      case SWT_SESSION:
         /* request for swt session                                           */
         switch (SesCtrlTypeActive)
         {
            case EXTENDED_DIAGNOSTIC_SESSION:
               if (activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED)
               {
                  /*
                   * session change is not allowed, stay in sub session
                   * FLASH_MODE_ACTIVATED
                   */
               }
               else
               {
                  /* Get swt session start permission from swt module         */
                  dcmSessionChangePermission = CDC_SWT_DCMGETSESSIONSTARTPERMISSION();
                  if (dcmSessionChangePermission != DCM_E_OK)
                  {
                     /* switch to sub session state FLASH_EXIT                */
                     activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  }
               }
               break;
            case SWT_SESSION:
               dcmSessionChangePermission = DCM_E_OK;
               break;
            default:
               /* session change is not allowed                               */
               break;
         }
         break;
#endif

      default:
         /* change to other session :
          * in extended session in other sub session than FlashModeActivated
          * change to FLASH_EXIT
          */
         if ( ( SesCtrlTypeActive == EXTENDED_DIAGNOSTIC_SESSION ) &&
              ( activeSubSession != EXTENDED_APPL_FLASH_MODE_ACTIVATED )
            )
         {
               activeSubSession = EXTENDED_APPL_FLASH_EXIT;
         }
         /* session change is not not allowed                                 */
         break;
   }

#if (CdcUseUserExtension == STD_ON)
   /* execute the user extension of this functionality                        */
   Rte_DcmGetSesChgPermission_User( SesCtrlTypeActive,  SesCtrlTypeNew,
                                    &dcmSessionChangePermission );
#endif

   return dcmSessionChangePermission;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmSesCtrlChangeIndication                             **
**                                                                            **
** DESCRIPTION   : Notification function for state change of the given        **
**                 state group, defined by CANdelaStudio.                     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SesCtrlTypeOld:                                          **
**                    - The old state which will be left.                     **
**                    - Access type: read                                     **
**                 - SesCtrlTypeNew:                                          **
**                    - The new state which will be set.                      **
**                    - Access type: read                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : - The function "Dcm_ProcessingDone" may not be called.     **
**                 - The function "Dcm_SetNegResponse" may not be called.     **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmSesCtrlChangeIndication
(
   CONST(uint8,AUTOMATIC) SesCtrlTypeOld,
   CONST(uint8,AUTOMATIC) SesCtrlTypeNew
)
{
   CDC_VSM_OPERATINGMODETYPE           op_mode;
   CDC_VSM_OPERATINGMODEEXTENSIONTYPE  ext_op_mode;

   switch (SesCtrlTypeNew)
   {
      case DEFAULT_SESSION:
         /*
          * is operation mode FLASH active and extended op-mode FLASH_ENABLED?
          */
         (void)CDC_VSM_GETMODE( &op_mode );
         (void)CDC_VSM_GETMODEEXTENSION( &ext_op_mode );
         if ( ( op_mode     == CDC_VSM_MM_MODE_BMW_FLASH ) &&
              ( ext_op_mode == CDC_VSM_MM_MODE_EXTENSION_FLASH_ENABLED )
            )
         {
            /*
             * FlashMode is active (this is in sub session FLASH_MODE_ACTIVATED
             * error memory and communication are still deactivated
             */
            activeSubSession = DEFAULT_APPL_FLASH_MODE_ACTIVATED;
         }
         else
         {
            /*
             * in case of change from extended session and sub sessions
             * NDC_DISABLED, DTC_OFF or FLASH_EXIT
             * to the default session -> activate error memory
             */
            if ( (SesCtrlTypeOld == EXTENDED_DIAGNOSTIC_SESSION) &&
                 ( (activeSubSession == EXTENDED_APPL_NDC_DISABLED) ||
                   (activeSubSession == EXTENDED_APPL_DTC_OFF) ||
                   (activeSubSession == EXTENDED_APPL_FLASH_EXIT)
                 )
               )
            {
               /* activate error memory                                       */
               (void)Dem_EnableDTCStorage(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
               /* store the actual error memory state for CDC handling        */
               isErrorMemoryEnabled = TRUE;

               /*
                * in case of sub session NDC_DISABLED or FLASH_EXIT
                * -> activate communication
                */
               if ( (activeSubSession == EXTENDED_APPL_NDC_DISABLED) ||
                    (activeSubSession == EXTENDED_APPL_FLASH_EXIT)
                  )
               {
                  (void)CDC_SETCOMMUNICATIONMODE( DIAG_UDS28_00_ENABLE_RX_AND_TX,
                                                  DIAG_UDS28_01_NORMAL_COMM_MSG );
               }
            }

#if (DCM_ROE_ENABLED == STD_ON)
            if ( SesCtrlTypeOld != DEFAULT_SESSION )
            {
               /* the ROE functionality can release the suspended mode, if set*/
               (void)Cdc_SetRoeSuspendedStatus( FALSE );
            }
#endif /* (DCM_ROE_ENABLED == STD_ON) */

            /* FlashMode is not active */
            activeSubSession = DEFAULT_APPL_FLASH_MODE_DEACTIVATED;
         }
         break;

      case PROGRAMMING_SESSION:
         /*
          * only from sub session FlashModeActivated and NDCDisabled a session
          * change to the programming session is possible
          */
         if ( (activeSubSession == EXTENDED_APPL_NDC_DISABLED) ||
              (activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED)
            )
         {
#if (CdcUseUserExtension == STD_ON)                             /* CR70962 */
            Rte_DcmSesCtrlChangeIndicationProgramming_User(pendingDiagContext.SubFunction);
#else             
            /* initiate an ECU reset                                          */
            (void)EcuM_SelectShutdownTarget(ECUM_STATE_RESET, (uint8)0);

            EcuM_KillAllRUNRequests();
#endif              
         }       
         break;

      case EXTENDED_DIAGNOSTIC_SESSION:
         if ( SesCtrlTypeOld != EXTENDED_DIAGNOSTIC_SESSION )
         {
            /*
             * is operation mode FLASH active and extended op-mode FLASH_ENABLED?
             */
            (void)CDC_VSM_GETMODE( &op_mode );
            (void)CDC_VSM_GETMODEEXTENSION( &ext_op_mode );
            if ( ( op_mode     == CDC_VSM_MM_MODE_BMW_FLASH ) &&
                 ( ext_op_mode == CDC_VSM_MM_MODE_EXTENSION_FLASH_ENABLED )
               )
            {
               /* FlashMode is active->go to sub session FLASH_MODE_ACTIVATED */
               activeSubSession = EXTENDED_APPL_FLASH_MODE_ACTIVATED;
            }
            else
            {
               if ( SesCtrlTypeOld == DEFAULT_SESSION )
               {
                  /* Handling for session change from Default to Extended     */
#if (DCM_ROE_ENABLED == STD_ON)
                  /* the ROE functionality must be suspended, if not set yet  */
                  (void)Cdc_SetRoeSuspendedStatus( TRUE );
#endif /* (DCM_ROE_ENABLED == STD_ON) */

                  /* FlashMode is not active -> go to sub session STARTED     */
                  activeSubSession = EXTENDED_APPL_STARTED;
                }
                else
                {
                  /* Handling for session change from Non-Default to Extended */
                  /* FlashMode is not active -> go to sub session FLASH_EXIT  */
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                }
             }
         }
         /*
          * session change from ExtendedSession to ExtendedSession causes no
          * necessary actions !
          */
         break;

#if (CDC_SC_CODING_ENABLE == STD_ON)
      case CODING_SESSION:
         /* no break;                                                         */
#endif
      default:
         activeSubSession = ELSE_SUB_SESSION_STATE;
         break;
   }

#if (CDC_SC_CODING_ENABLE == STD_ON)
   switch (SesCtrlTypeOld)
   {
      case CODING_SESSION:
         /* When leaving coding session                                       */
         if ( SesCtrlTypeNew != CODING_SESSION )
         {
            /* Inform the coding module about the end of the coding session   */
            CDC_CODING_DIAGSESSIONENDINDICATION();
         }
         break;
      default:
         /* do nothing                                                        */
         break;
   }
#endif

#if (CdcUseUserExtension == STD_ON)
   /* execute the user extension of this functionality                        */
   Rte_DcmSesCtrlChangeIndication_User( SesCtrlTypeOld, SesCtrlTypeNew );
#endif

}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmIndication                                          **
**                                                                            **
** DESCRIPTION   : not available                                              **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 uint8 SID                                                  **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : The feature must be enabled in the GENy configuration      **
**                                                                            **
*******************************************************************************/
#if (DCM_REQUEST_INDICATION_ENABLED != STD_ON)
 #error "Cdc_Dispatcher.c: Wrong DCM configuration - DCM_REQUEST_INDICATION_ENABLED must be STD_ON"
#endif
FUNC(Dcm_StatusType, CDC_PUBLIC_DCMCODE) Rte_DcmIndication
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONST(uint8,AUTOMATIC)  SID
)
{
   Dcm_SesCtrlType   ActiveSession;      
   Dcm_StatusType returnValue = DCM_E_OK;

   /* Get active session */
   (void)Dcm_GetSesCtrlType(&ActiveSession);
   /* TesterPresent must not be handled, because it can occour while other
    * diagnostic service handling and wrongly change pendingDiagContext
    */
   if ( SID != DIAG_UDS3E_SERVICE_TESTER_PRESENT )
   {
      Dcm_MsgType reqDataPtr = pMsgContext->reqData;
      Dcm_MsgType resDataPtr = pMsgContext->resData;

#if (SC_LED_DEMO_ON == STD_ON)
      /* indicate tp reception                                                */
      CDC_LED_SET( LED_DIAG_ACTIVE );
#endif

      if ( resDataPtr != reqDataPtr )
      {
         /*
          * Initialize first three bytes of response data buffer with request
          * data:
          * E.g. DataIdentifier for ReadDataById or RoutineType and
          * RoutineIdentifier for RoutineControl
          */
         *resDataPtr++ = *reqDataPtr++;
         *resDataPtr++ = *reqDataPtr++;
         *resDataPtr   = *reqDataPtr;
      }

      /* only in the extended session are any restrictions                    */
      if ( EXTENDED_DIAGNOSTIC_SESSION == ActiveSession )
      {
         /*
          * store sub parameter for post handler:
          * (clear SuspressPositiveResponseMessageIndicationBit)
          */
         pendingDiagContext.SubFunction = CLEAR_SPRMIB_FLAG(pMsgContext->reqData[0]);

         switch (SID)
         {
            case DIAG_UDS10_SERVICE_DIAGNOSTIC_SESSION_CONTROL:
               if ( (pendingDiagContext.SubFunction == PROGRAMMING_SESSION) &&
                    ( ( activeSubSession == EXTENDED_APPL_STARTED ) ||
                      ( activeSubSession == EXTENDED_APPL_DTC_OFF )
                    )
                  )
               {
                  /*
                   * change to programming session not allowed in sub sessions
                   * other than NDC_DISABLED and FLASH_MODE_ACTIVATED
                   * change to sub session FLASH_EXIT
                   * -> negative Response by Rte_DcmGetSesChgPermission()
                   */
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
               }
#ifndef SWT_SESSION
               /*
                * if the SWT session is not defined change to FLASH_EXIT if a
                * session change in the not defined SWT session shall be made
                * (in extended session in other sub session than FlashModeActivated)
                */
               if ( ! ( (pendingDiagContext.SubFunction == DEFAULT_SESSION) ||
                        (pendingDiagContext.SubFunction == PROGRAMMING_SESSION) ||
                        (pendingDiagContext.SubFunction == EXTENDED_DIAGNOSTIC_SESSION) ||
                        (pendingDiagContext.SubFunction == CODING_SESSION)
                      )
                  )
               {
                  if ( activeSubSession != EXTENDED_APPL_FLASH_MODE_ACTIVATED )
                  {
                     activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  }
                  /* the neg. Resp. will be set by the DCM                    */
               }
#endif
               break;
            case DIAG_UDS11_SERVICE_ECU_RESET:
               break;
            case DIAG_UDS22_SERVICE_READ_DATA_BY_IDENTIFIER:
               break;
            case DIAG_UDS28_SERVICE_COMMUNICATION_CONTROL:
               if ( activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED )
               {
                  /*
                   * COMMUNICATION_CONTROL is not allowed in sub session
                   * FLASH_MODE_ACTIVATED, but stay in this sub session
                   */
                  returnValue = DCM_E_REQUEST_NOT_ACCEPTED;
               }
               /*
                * all further sub session handlings are implemented in
                * Rte_DcmCommunicationControl()
                */
               break;
            case DIAG_UDS31_SERVICE_ROUTINE_CONTROL:
               /*
                * special handling for RoutineControl: only the following RIDs
                * don't cause a change to sub session FLASH_EXIT
                */
               switch ( CDC_MAKE16BIT( pMsgContext->reqData[1],
                                       pMsgContext->reqData[2] )
                      )
               {
                  case DIAG_RID_0203_CHECK_PROGRAMMING_PRECONDITIONS:
                     break;
                  case DIAG_RID_0204_READ_SWE_PROGRAMMING_STATUS:
                     /*
                      * not supported in Application but must stay in actual sub
                      * session --> RT14484
                      */
                     break;
                  case DIAG_RID_0205_READ_DEVELOPMENT_INFO:
                     break;
                  case DIAG_RID_0F0C_SET_VSM_OPERATION_MODE:
                     break;
                  case DIAG_RID_1003_SET_VSM_OPERATION_MODE_EXTENSION:
                     break;
                  default:
                     if (activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED)
                     {
                        /*
                         * other RIDs are not allowed in sub session
                         * FLASH_MODE_ACTIVATED, but stay in this sub session
                         */
                        returnValue = DCM_E_REQUEST_NOT_ACCEPTED;
                     }
                     else
                     {
                        /*
                         * other RoutineIDs in this sub sessions are allowed,
                         * but cause a change to sub session FLASH_EXIT
                         */
                        activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                     }
                     break;
               }
               break;

            /* case DIAG_UDS3E_SERVICE_TESTER_PRESENT: is handled above       */

            case DIAG_UDS85_SERVICE_CONTROL_DTC_SETTING:
               if ( activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED )
               {
                  /*
                   * CONTROL_DTC_SETTING is not allowed in sub session
                   * FLASH_MODE_ACTIVATED, but stay in this sub session
                   */
                  returnValue = DCM_E_REQUEST_NOT_ACCEPTED;
               }
               else if (pendingDiagContext.SubFunction != DIAG_UDS85_02_OFF)
               {
                  /*
                   * ControlDTCSettings(ON) is only in sub session
                   * FLASH_MODE_ACTIVATED not allowed but causes a change to
                   * sub session FLASH_EXIT
                   */
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
               }
               else
               {
                  /*
                   * ControlDTCSettings(OFF) is only in sub session
                   * FLASH_MODE_ACTIVATED not allowed
                   * The sub session switching is handled after service handling
                   * in Rte_DcmConfirmation()
                   */

               }
               break;
            default:
               if ( activeSubSession == EXTENDED_APPL_FLASH_MODE_ACTIVATED )
               {
                  /*
                   * other services in sub session FLASH_MODE_ACTIVATED are
                   * not allowed -> stay in this sub session
                   */
                  returnValue = DCM_E_REQUEST_NOT_ACCEPTED;
               }
               else
               {
                  /*
                   * other services in other sub sessions are allowed, but
                   * cause a change to sub session FLASH_EXIT
                   */
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
               }
               break;
         } /* switch (SID)                                                    */

      } /* EXTENDED_DIAGNOSTIC_SESSION == ActiveSession                       */
   } /* SID != DIAG_UDS3E_SERVICE_TESTER_PRESENT                              */

#if (CdcUseUserExtension == STD_ON)
   /* execute the user extension of this functionality                        */
   Rte_DcmIndication_User( pMsgContext, SID, &returnValue );
#endif

#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_FUNCTION_CALLED_NOT_USED, returnValue, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */   

   return returnValue;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmConfirmation (Service request header:0xff )         **
**                                                                            **
** DESCRIPTION   : Post handler for all diag services                         **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - idContext:                                               **
**                   - An identfier of the dcm instance.                      **
**                   - Access type: read                                      **
**                 - dcmRxPduId:                                              **
**                   - The PduId on which the request has been received.      **
**                   - Access type: read                                      **
**                 - status:                                                  **
**                   - Shows the status of the process accomplishment.        **
**                   - Can be:                                                **
**                     + DCM_RES_POS_OK                                       **
**                     + DCM_RES_POS_NOT_OK                                   **
**                     + DCM_RES_NEG_OK                                       **
**                     + DCM_RES_NEG_NOT_OK                                   **
**                   - Access type: read                                      **
**                                                                            **
** INPUT:        : pendingDiagContext.SubFunction                             **
**                 pendingDiagContext.DataOrRoutineId                         **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : - The function "Dcm_ProcessingDone" may not be called.     **
**                 - The function "Dcm_SetNegResponse" may not be called.     **
**                 - 'pMsgContext' can not be used here - it is released      **
**                   before call of 'Rte_DcmCondirmation'.                    **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmConfirmation
(
   Dcm_IdContextType idContext,
   PduIdType dcmRxPduId,
   Dcm_ConfirmationStatusType status
)
{
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* set module test function called flag */
    uint16 u16_TESTRetVal = TEST_CDC_RETVAL_NOT_USED;
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */   
   Dcm_SesCtrlType   ActiveSession; 

      /* Get active session */
   (void)Dcm_GetSesCtrlType(&ActiveSession);
   if ( idContext == (uint8)DIAG_UDS22_SERVICE_READ_DATA_BY_IDENTIFIER )
   {
      Cdc_PostProcessReadDataByIdentifier ( pendingDiagContext.DataOrRoutineId,
                                            status
                                          );
   }

   switch(status)
   {
      case DCM_RES_POS_OK:
         /* ... positive response has been successfully sent.                 */
         switch (idContext)
         {
            case DIAG_UDS11_SERVICE_ECU_RESET:
#if (CdcUseUserExtension == STD_ON)                                 /* CR70962 */
               (void)Cdc_ConfirmationECUReset_User(pendingDiagContext.SubFunction);                              
#else                     
               Cdc_ConfirmationECUReset(pendingDiagContext.SubFunction);    
#endif                 
               break;
            case DIAG_UDS31_SERVICE_ROUTINE_CONTROL:
               Cdc_ConfirmationRoutineControl(pendingDiagContext.DataOrRoutineId);
               break;
            default:
               break;
         }
         /* no break - further handling for POS_OK below                      */
      case DCM_RES_POS_NOT_OK:
         /* ... positive response transmission has failed.                    */
         /*
          * the service has been successfully finished but the postive
          * response was not successfully sent to the tester (RT14530)
          */
         if ( idContext == DIAG_UDS85_SERVICE_CONTROL_DTC_SETTING )
         {
      	    if ( EXTENDED_DIAGNOSTIC_SESSION == ActiveSession )
            {
               if ( (pendingDiagContext.SubFunction == DIAG_UDS85_02_OFF) &&
                    ( (activeSubSession == EXTENDED_APPL_STARTED) ||
                      (activeSubSession == EXTENDED_APPL_DTC_OFF) )
                  )
               {
                  /*
                   * go or stay in DTC_OFF if the error memory was
                   * successfully disabled
                   */
                  activeSubSession = EXTENDED_APPL_DTC_OFF;
#if (CDC_MODULETEST_ENABLED == STD_ON)
                    /* get return value */
                    u16_TESTRetVal = activeSubSession;
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */                     

               }
               /*
                * in other sub sessions with DIAG_UDS85_02_OFF stay in the
                * current sub session
                * only with DIAG_UDS85_01_ON go to FLASH_EXIT (handled by
                * Rte_DcmIndication() )
                */
            }
            /* store the actual error memory state for Diag. handling         */
            if ( pendingDiagContext.SubFunction == DIAG_UDS85_02_OFF )
            {
               /* if error memory has already been disabled                   */
               if ( isErrorMemoryEnabled == FALSE )
               {
                  /* enable error memory once to keep nesting depth at one.   */
                  /* it will be disabled by DCM afterwards.                   */
                  (void)Dem_EnableDTCStorage( DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS );
               }
               isErrorMemoryEnabled = FALSE;
            }
            else
            {
               isErrorMemoryEnabled = TRUE;
            }
         }
         break;
      case DCM_RES_NEG_OK:
         /* ... negative response has been successfully sent.                 */
         /* no break - further handling for NEG_OK below                      */
      case DCM_RES_NEG_NOT_OK:
         /* ... negative response transmission has failed.                    */
         /*
          * in extended session in other sub session than FlashModeActivated
          * change to FLASH_EXIT
          */
      	    if ( ( EXTENDED_DIAGNOSTIC_SESSION == ActiveSession ) &&
              ( activeSubSession != EXTENDED_APPL_FLASH_MODE_ACTIVATED )
            )
         {
            switch (idContext)
            {
               case DIAG_UDS22_SERVICE_READ_DATA_BY_IDENTIFIER:
                  /* stay in the actual sub session on neg. responses         */
                  break;
               case DIAG_UDS28_SERVICE_COMMUNICATION_CONTROL:
                  /* CommunicationControl has an own sub session handling     */
                  break;
               case DIAG_UDS31_SERVICE_ROUTINE_CONTROL:
                  /*
                   * only change to FLASH_EXIT if not RC 0203, 0204, 0205 or
                   * 1003 (special sub session handling) was sent
                   */
                  switch ( pendingDiagContext.DataOrRoutineId )
                  {
                     case DIAG_RID_0203_CHECK_PROGRAMMING_PRECONDITIONS:
                        /* no break */
                     case DIAG_RID_0204_READ_SWE_PROGRAMMING_STATUS:
                        /* no break */
                     case DIAG_RID_0205_READ_DEVELOPMENT_INFO:
                        /* no break */
                     case DIAG_RID_1003_SET_VSM_OPERATION_MODE_EXTENSION:
                        break;
                     default:
                        activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                        break;
                  }
                  break;
               case DIAG_UDS3E_SERVICE_TESTER_PRESENT:
                  /* stay in the actual sub session on neg. responses         */
                  break;
               default:
                  /* for all other services change to FLASH_EXIT on neg. Resp.*/
                  activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                  break;
            } /* switch (idContext)                                           */
         }
         break;
      default:
         break;
   } /* switch(status)                                                        */

#if (SC_LED_DEMO_ON == STD_ON)
   if ( idContext != DIAG_UDS3E_SERVICE_TESTER_PRESENT )
   {
      /* indicate end of diagnostic processing                                */
      Led_Clear(LED_DIAG_ACTIVE);
   }
#endif

#if (CdcUseUserExtension == STD_ON)
   /* execute the user extension of this functionality                        */
   Rte_DcmConfirmation_User( idContext, dcmRxPduId, status );
#endif

#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_FUNCTION_CALLED_NOT_USED, TEST_CDC_RESPONSE_CODE_NOT_USED, u16_TESTRetVal);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */ 

}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmECUReset (Service request header:0x11 )             **
**                                                                            **
** DESCRIPTION   : Trigger a reset. This function implements the first step   **
**                 of the operation: the sending of the positive response.    **
**                 The second step, the trigger of the reset, will be done    **
**                 in function 'Cdc_ConfirmationECUReset', to guarantee       **
**                 that the positive response will be sent successfully.      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : pMsgContext:  pointer to diag context:                     **
**                               For more information see the DCM docs        **
**                                                                            **
** INPUT:        : pMsgContext->reqData[0]: reset Mode                        **
**                                                                            **
** RETURN        : positive response: when SubFunction is supported           **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmECUReset
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
#if (CdcEnableAsyncRequestHandling == STD_ON)
   boolean                      AsyncUserFunctionCalled = FALSE;
#endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
   Dcm_SesCtrlType   ActiveSession;      
   Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;

   /* Get active session */
   (void)Dcm_GetSesCtrlType(&ActiveSession);
   if (pMsgContext->reqDataLen == (uint16)1)
   {
      /* store sub parameter for post handler                                 */
      pendingDiagContext.SubFunction = pMsgContext->reqData[0];

      switch (pendingDiagContext.SubFunction)
      {
         case DIAG_UDS11_01_HARD_RESET:
            /*
             * force RESET. Positive response will send later in
             * ResetSequence()
             */
#if (CdcUseUserExtension == STD_ON)                 /* CR70962 */
            /* try to find an user extended diagnostic SubFunction in Cdc_User.c */
            #if (CdcEnableAsyncRequestHandling == STD_ON)
            AsyncUserFunctionCalled = TRUE;
            if ( Rte_DcmECUReset_User (pMsgContext) != E_OK )
            #else
            if ( Rte_DcmECUReset_User (pMsgContext, &ResponseCode) != E_OK )
            #endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
            {
                /* prepare negative response                                      */
                pMsgContext->resDataLen = (uint16)0u;
            }
            else
#endif            
            {
                /* prepare positive response                                      */
                pMsgContext->resDataLen = (uint16)1u;
            }
            break;
         default:
            {
#if (CdcUseUserExtension == STD_ON)
                /* try to find an user extended diagnostic SubFunction in Cdc_User.c */
                #if (CdcEnableAsyncRequestHandling == STD_ON)
                AsyncUserFunctionCalled = TRUE;
                if ( Rte_DcmECUReset_User (pMsgContext) != E_OK )
                #else
                if ( Rte_DcmECUReset_User (pMsgContext, &ResponseCode) != E_OK )
                #endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
#endif
                {
                   /* Request contains invalid data - send negative response!     */
                   ResponseCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                   /* handle sub sessions in the ExtendedSession                  */
                   if ( ( EXTENDED_DIAGNOSTIC_SESSION == ActiveSession ) &&
                        ( activeSubSession != EXTENDED_APPL_FLASH_MODE_ACTIVATED )
                      )
                   {
                      /*
                       * an EcuReset with an undefined parameter in the
                       * ExtendedSession in all sub sessions <> FLASH_MODE_ACTIVATED
                       * cause a change to sub session FLASH_EXIT
                       */
                      activeSubSession = EXTENDED_APPL_FLASH_EXIT;
                   }
                }
            }
            break;
      }
   }
   else
   {
      ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }
#if (CdcEnableAsyncRequestHandling == STD_ON)
    /* If a Userfunction is called the UserFunction is responsible for the response*/
    if( FALSE == AsyncUserFunctionCalled )
#endif /* (CdcEnableAsyncRequestHandling == STD_ON) */
    {
        Cdc_DcmCheckResponseCode(pMsgContext, ResponseCode);
    }

} /* end of function 'Rte_DcmECUReset'                                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmGetSeed                                             **
**                                                                            **
** DESCRIPTION   : Request for a security level based seed sequence           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SecurityLevel:                                           **
**                   - The security level needed this seed.                   **
**                   - Access type: read                                      **
**                 - SeedLen:                                                 **
**                   - The seed sequence length.                              **
**                   - Access type: read                                      **
**                 - Seed:                                                    **
**                   - Pointer to the seed sequence buffer.                   **
**                   - Access type: write                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmGetSeed
(
   uint8 SecurityLevel,
   uint8 SeedLen,
   CONSTP2VAR(uint8,AUTOMATIC,CDC_VAR_DCMDATA) Seed
)
{

#if (CdcUseUserExtension == STD_ON)
	/* NXTR SWT */// - CDCSWT patch, added SWT get seed request
//	if ( ( SecurityLevel == DIAG_UDS27_01_CODING_SESSION_GET_SEED ) ||
//        ( SecurityLevel == DIAG_UDS27_11_PROGRAMMING_SESSION_GET_SEED )
//    )
   	if ( ( SecurityLevel == DIAG_UDS27_01_CODING_SESSION_GET_SEED ) ||
         ( SecurityLevel == DIAG_UDS27_11_PROGRAMMING_SESSION_GET_SEED ) ||
         ( SecurityLevel == DIAG_UDS27_13_SWT_SESSION_GET_SEED) )
   {
#endif

   		if(SecurityLevel == DIAG_UDS27_13_SWT_SESSION_GET_SEED)
   		{
   			CDD_CdcAuthLevel_Cnt_G_u8 = 0x04;
   		}
   		else
   		{
   			CDD_CdcAuthLevel_Cnt_G_u8 = 0x03;
   		}


      /* execute the CDC mandatory implementation of this functionality       */
      Cdc_GetSeed( SecurityLevel, SeedLen, Seed );
#if (CdcUseUserExtension == STD_ON)
   }
   else
   {
      /* execute the user extension of this functionality                     */
      Rte_DcmGetSeed_User( SecurityLevel, SeedLen, Seed );
   }
#endif

} /* end of function 'Rte_DcmGetSeed'                                         */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmCompareKey                                          **
**                                                                            **
** DESCRIPTION   : Request for a security level based key sequence            **
**                 comparision                                                **
**                                                                            **
** PRECONDITIONS : successful SeedRequest                                     **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SecurityLevel:                                           **
**                   - The security level needed this seed.                   **
**                   - Access type: read                                      **
**                 - KeyLen:                                                  **
**                   - The key sequence length.                               **
**                   - Access type: read                                      **
**                 - Key:                                                     **
**                   - Pointer to the key sequence buffer.                    **
**                   - Access type: read                                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : DCM_E_OK : return value doesn't matter                     **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
/* ----- NXTR PATCH START -----
 * Added By: K. Smith (Nxtr)
 * Date Added: 28Sep16
 *
 * Reason: Due to the increase in key size, the Dcm needed to be patched to support the new key length. However, that value is
 * 260, which is larger than a uint8. As a result, the data type needed to be patched in order to properly hold the correct
 * value.
 */
/* ----- Original Code Start ----- */
#if 0
FUNC(Dcm_StatusType, CDC_PUBLIC_DCMCODE) Rte_DcmCompareKey
(
   uint8 SecurityLevel,
   uint8 KeyLen,
   CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
)
#endif
/* ----- Original Code End ----- */
/* ----- Patch Code Start ----- */
FUNC(Dcm_StatusType, CDC_PUBLIC_DCMCODE) Rte_DcmCompareKey
(
   uint8 SecurityLevel,
   uint16 KeyLen,
   CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
)
/* ----- Patch Code End ----- */
/* ----- NXTR PATCH END ----- */
{
   Dcm_StatusType retVal;

#if (CdcUseUserExtension == STD_ON)
   /* NXTR SWT */
 //  if ( ( SecurityLevel == DIAG_UDS27_01_CODING_SESSION_GET_SEED ) ||
 //      ( SecurityLevel == DIAG_UDS27_11_PROGRAMMING_SESSION_GET_SEED )
 //     )
   if ( ( SecurityLevel == DIAG_UDS27_01_CODING_SESSION_GET_SEED ) ||
	     ( SecurityLevel == DIAG_UDS27_11_PROGRAMMING_SESSION_GET_SEED ) ||
	     ( SecurityLevel == DIAG_UDS27_13_SWT_SESSION_GET_SEED) )
   {
#endif
      /* execute the CDC mandatory implementation of this functionality       */
      retVal = Cdc_CompareKey( SecurityLevel, KeyLen, Key );
#if (CdcUseUserExtension == STD_ON)
   }
   else
   {
      /* execute the user extension of this functionality                     */
      retVal = Rte_DcmCompareKey_User( SecurityLevel, KeyLen, Key );
   }
#endif

   return retVal;
} /* end of function 'Rte_DcmCompareKey'                                      */


#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmUpdatePage                                          **
**                                                                            **
** DESCRIPTION   : Callback if paged buffering processing requests the next   **
**                 page                                                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgType PageBufPtr                                     **
**                 Dcm_MsgLenType PageLen                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_APPL_CODE) Rte_DcmUpdatePage
(
   Dcm_MsgType PageBufPtr,
   Dcm_MsgLenType PageLen
)
{
   pCurrentUpdatePage(PageBufPtr, PageLen);
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmCancelPagedBufferProcessing                         **
**                                                                            **
** DESCRIPTION   : Callback if paged buffering processing is canceled         **
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
** REMARKS       : Called also of interrupt level                             **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_APPL_CODE) Rte_DcmCancelPagedBufferProcessing (void)
{
  /* not used */
  Cdc_CancelPagedBufferProcessing();
}/* end of function 'Rte_DcmCancelPagedBufferProcessing'                      */

#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */



#if (DCM_ROE_ENABLED == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmResponseOnEvent                                     **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 Rte_DcmResponseOnEvent (0x86)                              **
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
FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmResponseOnEvent
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   CDC_DARH_ROEENGINETYPE           cdcRoeEngine;
   CDC_DARH_ROESTOREBITTYPE         doStore;
   CDC_DARH_ROEISSTARTEDTYPE        isStarted;
   Dcm_NegativeResponseCodeType     errorCode = DCM_E_OK;
   Dcm_MsgType reqDataPtr = pMsgContext->reqData;
   Dcm_MsgType resDataPtr = pMsgContext->resData;
   Dcm_SesCtrlType   ActiveSession; 

   /* Read always - the DARH module will take care of the value */
   (void)CDC_DARH_GETROESTATUS(&cdcRoeEngine);

   /*Is there a sub-function? */
   if(pMsgContext->reqDataLen !=  0)
   {
      /* mask out bit 6 and 7
       *    bit 6 = ROE store bit
       *    bit 7 = suppress positive response bit
       */
      uint8 subFunctionValue = (uint8)(reqDataPtr[0] & (uint8)(~0xC0u));
    
      switch (subFunctionValue)
      {
         case 0x05:      /* Roe has to be started ( or 0x45 )*/
            /* no break */
         case 0x00:      /* Roe has to be stopped ( or 0x40 )*/
            if(pMsgContext->reqDataLen == 2)
            {
               /* Event window time must be always 2 */
               if(reqDataPtr[1] == 2)
               {
                  /* is the doStore bit set? */
                  doStore = (CDC_DARH_ROESTOREBITTYPE)((((reqDataPtr[0]) & 0x40) != 0)?TRUE:FALSE);

                  /* Get active session */
                  (void)Dcm_GetSesCtrlType(&ActiveSession);
                  /* start/stop */
                  if( subFunctionValue != 0x00 )
                  {
                     /* if FMA-mode in default-session or a non-default-session is activ ? */
                     if ( ( activeSubSession == DEFAULT_APPL_FLASH_MODE_ACTIVATED ) ||
                          ( DEFAULT_SESSION != ActiveSession )
                        )
                     {
                        /*
                         * ROE is suspended if:
                         * FlashMode = FMA is active in the default-session
                         * or if the active session is a non-default-session
                         */
                        isStarted = (CDC_DARH_ROEISSTARTEDTYPE)CDC_ROE_START_SUSPENDED;
                     }
                     else
                     {
                        isStarted = (CDC_DARH_ROEISSTARTEDTYPE)CDC_ROE_IS_STARTED;
                     }
                  }
                  else
                  {
                     /* if FMA-mode in default-session or a non-default-session is activ ? */
                     if ( ( activeSubSession == DEFAULT_APPL_FLASH_MODE_ACTIVATED ) ||
                          ( DEFAULT_SESSION != ActiveSession )
                        )
                     {
                        /*
                         * ROE is suspended if:
                         * FlashMode = FMA is active in the default-session
                         * or if the active session is a non-default-session
                         */
                        isStarted = (CDC_DARH_ROEISSTARTEDTYPE)CDC_ROE_STOP_SUSPENDED;
                     }
                     else
                     {
                        isStarted = (CDC_DARH_ROEISSTARTEDTYPE)CDC_ROE_IS_STOPPED;
                     }
                  }

                  cdcRoeEngine.RoeIsStarted = isStarted;
                  cdcRoeEngine.RoeStoreBit = doStore;
                  cdcRoeEngine.DcmRxPduId = pMsgContext->dcmRxPduId;
                  /* inform the DARH about the actual ROE state and store
                   * it in the NVRAM if required
                   */
                  if( CDC_DARH_SETROESTATUS(&cdcRoeEngine) != (Std_ReturnType)E_OK)
                  {
                     /* DARH request refused */
                     errorCode = DCM_E_CONDITIONSNOTCORRECT;
                  }
                  else
                  {
                     /* positive response */
                     resDataPtr[1] = 0x00; /* numberOfIdentifiedEvents */
                     resDataPtr[2] = 0x02; /* eventWindowTime */
                     pMsgContext->resDataLen = 3;
                  }
               }
               else
               {
                  /* Request parameter invalid - send negative response! */
                  errorCode = DCM_E_REQUESTOUTOFRANGE;
               }
            }
            else
            {
               /* Request length invalid - send negative response! */
               errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            }
            break;

         case 0x03:      /* onChangeOfDataIdentifier */
            if(pMsgContext->reqDataLen == 7)
            {
               if ((reqDataPtr[1] == 0x02) /* eventWindowTime */       &&
                     (reqDataPtr[2] == CDC_GETHIBYTE(DIAG_DID_1704_DARH_DTC)) &&
                     (reqDataPtr[3] == CDC_GETLOBYTE(DIAG_DID_1704_DARH_DTC)) &&
                     (reqDataPtr[4] == 0x22) /* only SID $22 is allowed */ &&
                     (reqDataPtr[5] == CDC_GETHIBYTE(DIAG_DID_1704_DARH_DTC)) &&
                     (reqDataPtr[6] == CDC_GETLOBYTE(DIAG_DID_1704_DARH_DTC)))
               { /* positive response */
                  resDataPtr[1] = 0x00; /* numberOfIdentifiedEvents */
                  resDataPtr[2] = 0x02; /* eventWindowTime */
                  resDataPtr[3] = CDC_GETHIBYTE(DIAG_DID_1704_DARH_DTC);
                  resDataPtr[4] = CDC_GETLOBYTE(DIAG_DID_1704_DARH_DTC);
                  resDataPtr[5] = 0x22; /* only SID $22 is allowed */
                  resDataPtr[6] = CDC_GETHIBYTE(DIAG_DID_1704_DARH_DTC);
                  resDataPtr[7] = CDC_GETLOBYTE(DIAG_DID_1704_DARH_DTC);

                  pMsgContext->resDataLen = 8;
               }
               else
               { /* negative   response */
                  errorCode = DCM_E_REQUESTOUTOFRANGE;
               }
            }
            else
            {
               /* Request length invalid - send negative response! */
               errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            }
            break;

         case 0x04:      /* reportActivatedEvents */
            if(pMsgContext->reqDataLen == 1)
            { /* BMWAG: no eventWindowTime parameter in request */
               /* positive response */
               if ( (cdcRoeEngine.RoeIsStarted != CDC_ROE_IS_STOPPED) &&
                    (cdcRoeEngine.RoeIsStarted != CDC_ROE_STOP_SUSPENDED) )
               {
                  resDataPtr[1] = 0x01; /* numberOfActivatedEvents */
                  resDataPtr[2] = 0x43; /* eventTypeOfActiveEvent */
                  resDataPtr[3] = 0x02; /* eventWindowTime */
                  resDataPtr[4] = CDC_GETHIBYTE(DIAG_DID_1704_DARH_DTC); /* eventTypeRecord (BMWAG: 2 bytes only) */
                  resDataPtr[5] = CDC_GETLOBYTE(DIAG_DID_1704_DARH_DTC);
                  resDataPtr[6] = 0x22; /* only SID $22 is allowed */
                  resDataPtr[7] = CDC_GETHIBYTE(DIAG_DID_1704_DARH_DTC);
                  resDataPtr[8] = CDC_GETLOBYTE(DIAG_DID_1704_DARH_DTC);

                  pMsgContext->resDataLen = 9;
               }
               else
               {
                  resDataPtr[1] = 0x00; /* numberOfActivatedEvents */

                  pMsgContext->resDataLen = 2;
               }
            }
            else
            {
               /* Request length invalid - send negative response! */
               errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            }
            break;

         default:
            errorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
            break;
      }
   }
   else
   {
      /* Request length invalid - send negative response! */
      errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }

   Cdc_DcmCheckResponseCode(pMsgContext, errorCode);          
   
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_FUNCTION_CALLED_NOT_USED, errorCode, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */       
}
#endif /* (DCM_ROE_ENABLED == STD_ON) */

#define CDC_STOP_SEC_CODE
#include <MemMap.h>

/*** End of file **************************************************************/
