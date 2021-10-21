/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Cdc_Common_Mandatory.c                                        **
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
**              to specification for AUTOSAR - common part                    **
**                                                                            **
**  REMARKS   : Implementation of common (application and bootloader)         **
**              specific diagnostic services                                  **
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
** gk           Guenter Kothgasser         BMW Group                          **
** ft           Florian Tausch             MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.2: 26.09.2011, anam: CR71024: CDC: Don't ignore possible error messages or return values
 * V1.1.1: 20.05.2011, anam: CR71056: SVK Read: Optimize RAM Usage
 * V1.1.0: 14.04.2011, gk  : CR70960: Programming interface for Slave CPU 
 * V1.0.8: 02.03.2011,   ft: CR70980: Usage of DATALOGISTIC_SVK_HISTORY  
 * V1.0.7: 22.02.2011, muer: CR70919: some MISRA warnings removed
 * V1.0.6: 13.01.2010, gema: CR70390, Compiler switches shall have defined values 
 * V1.0.5: 02.11.2009, muer: CR70461: Code Size Optimization - Cdc - BAC HIS 
 *                                    implementation guidelines
 * V1.0.4: 08.10.2009, hauf: CR70292: Corrected storage classes of different
 *                                    const pointers to CDC_VAR_CONST and
 *                                    decoupled location of SVK with new
 *                                    storage class DATALOGISTIC_SVK_HISTORY
 * V1.0.3: 30.06.2009, hauf: CR70188: Changed name of DCM session defines
 *         25.06.2009, dabu: CR70223: Implementation of Cdc review results
 * V1.0.2: 20.03.2009, dabu: CR70049: No reentry of error memory entry
 *                                    VSM_EVENT_OPMODE in FMA-mode at startup
 * V1.0.1: 17.11.2008, dabu: CR61288: set DEM event with separate Op-Cycle
 * V1.0.0: 15.08.2008, dabu: BSCCDC-34: SecurityAccess: make Rte_DcmGetSeed()
 *                                      and Rte_DcmCompareKey() user extendable
 *         08.08.2008, dabu: BSCCDC-25: changed Application Extended Session
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
#include <Cdc_Common_Mandatory.h>   /* prototypes of the CDC common functions */
/* -------------------------------------------------------------------------- */
#if (CdcScenarioApplication == STD_ON)
#include <Cdc_Application_Mandatory.h> /* prototypes of the CDC appl. fcts.   */
#endif
/* -------------------------------------------------------------------------- */
#include <Dcm.h>                    /* DCM API                                */
#include "Nvm.h"

/* Nxtr Patch - Added 09/30/12, KJS: Added this include for CDC_AUTH_LEVEL correction */
#include "CDD_Data.h"

/* -------------------------------------------------------------------------- */
#if ( SC_SLAVE_CPU == STD_ON )
   #include "ApplSlaveInterface.h"
#endif  /* SC_SLAVE_CPU */

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


/* Calculate the index of the previous element in a fifo buffer               */
#define CDC_GETPREVELEMENTINFIFO(num,prev,maxelem)                             \
                                      (((uint8)(num) >= (uint8)(prev)) ?       \
                                        (uint8)((uint8)(num) - (uint8)(prev)): \
                                        (uint8)((uint8)(maxelem) -             \
                                        ((uint8)(prev) - (uint8)(num) ) )      \
                                      )

/*
 * A diagnostic requirement is, that the dcm buffer has at least 350 bytes.
 */
#if (DCM_BUFFER_LENGTH < 350u)
   #error "Cdc_Common_Mandatory.c: DCM_BUFFER_LENGTH too small - at least 350 bytes are necessary"
#endif

#if (CdcScenarioBootloader == STD_ON)
   #if (CDC_SC_BOOT_CRYPTO_ENABLE == STD_ON)
      #define CDC_CRYPTO_ENABLE STD_ON
   #else
      #define CDC_CRYPTO_ENABLE STD_OFF
   #endif
#else
   #if (CDC_SC_APPL_CRYPTO_ENABLE == STD_ON)
      #define CDC_CRYPTO_ENABLE STD_ON
   #else
      #define CDC_CRYPTO_ENABLE STD_OFF
   #endif
#endif /* (CdcScenarioBootloader == STD_ON)                                   */

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/*
 * Security access params type:
 * Used to save security access parameters between GetSeed and CompareKey
 */
typedef struct
{
   uint8  PendingSeed[8];                 /* seed stored temporary in ECU     */
                                          /* between GetSeed -> CompareKey    */
   uint8  TesterId[DCM_SECURITYACCESSRECORDLENGTH];
                                          /* TesterId transfered in GetSeed   */
} SecurityAccessParamsType;

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define CDC_START_SEC_CODE
#include <MemMap.h>

   _STATIC_ FUNC(uint8, CDC_CODE) Cdc_GetNumberOfElementsInReadMemorySegmentationTable (void);

   _STATIC_ FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvk
               (
                  CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
                  CONST(SvkHistoryType,AUTOMATIC) SvkHistory,
                  CONST(uint8,AUTOMATIC) SvkBackupNumber,
                  CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
                  CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
               );

#define CDC_STOP_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CDC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

   VAR(SubSessionType, CDC_VAR_DCMDATA) activeSubSession;

   /*
    * Security access params type
    * Used to save security access parameters for asynchronous processing in
    * 'BackgroundTask'
    */
   _STATIC_ VAR(SecurityAccessParamsType, CDC_VAR_PRIVATE) SecurityAccessParams;

#define CDC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#define CDC_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

   /* static loop variable */
   _STATIC_ VAR(uint8_least, CDC_VAR_PRIVATE) iLoopStart = (uint8_least)0;
   /* static step variable */
   _STATIC_ VAR(uint8_least, CDC_VAR_PRIVATE) iStep      = (uint8_least)0;

#define CDC_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


#if (CDC_NUMBEROFSVKBACKUPS > 0)
#define CDC_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>
_STATIC_ CONST(NvM_BlockIdType, CDC_CONST) Cdc_SvkBackups[CDC_NUMBEROFSVKBACKUPS] = CDC_NVM_BLOCK_SVK_BACKUP_ARRAY;
#define CDC_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>
#endif /* (CDC_NUMBEROFSVKBACKUPS > 0)                                        */

#define CDC_START_SEC_VAR_NOINIT_16BIT
#include <MemMap.h>

   #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
      /*
       * global variable to save the actual position to write the svk via
       * paged buffer processing
       */
      _STATIC_ VAR(uint16, CDC_VAR_PRIVATE) gSVKLength;
   #endif /* DCM_PAGEDBUFFER_ENABLED == STD_ON                                */

#define CDC_STOP_SEC_VAR_NOINIT_16BIT
#include <MemMap.h>

#define CDC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

   #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
      /*
       * global variable to save the actual position to write the svk via
       * paged buffer processing
       */
      _STATIC_ P2VAR(uint8, AUTOMATIC, COMMON_APPL_DATA) gpSvk;
   #endif /* DCM_PAGEDBUFFER_ENABLED == STD_ON                                */

#define CDC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define CDC_START_SEC_CODE
#include <MemMap.h>

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_DcmSendResponseCode                                    **
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
_STATIC_ FUNC(void, CDC_CODE) Cdc_DcmSendResponseCode        
(
    CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
    CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
    if (*ResponseCode != DCM_E_OK)
    {
       Dcm_SetNegResponse(pMsgContext, *ResponseCode);
    }
    /* send ProcessingDone in either cases, even if paged processing is used*/
    Dcm_ProcessingDone(pMsgContext); 
    
}/* end of function 'Cdc_DcmSendResponseCode'   */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_GetNumberOfElementsInReadMemorySegmentationTable       **
**                                                                            **
** DESCRIPTION   : Calculate the number of elements, that will occur in the   **
**                 MemorySegmentationTable after run length encoding          **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData.MemSegTable                              **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : uint8: The number of elements in the                       **
**                        MemorySegmentationTable                             **
**                                                                            **
** REMARKS       : The result ist stored static, for further use              **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(uint8, CDC_CODE) Cdc_GetNumberOfElementsInReadMemorySegmentationTable (void)
{
   static  uint8              numberOfElements     = (uint8)0;
           uint8_least        iLoop;
                                             /* holds temporary addresses     */
           CDC_FLASHADDRESS_T expectedStartAddress = (CDC_FLASHADDRESS_T)0;
           CDC_FLASHADDRESS_T expectedSize         = (CDC_FLASHADDRESS_T)0;
           CDC_FLASHADDRESS_T nextStartAddress;
           CDC_FLASHADDRESS_T currentSize;

   P2CONST(CDC_FLASHADDRESS_T, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                            pCurrentStartAddress;

   if (numberOfElements != (uint8)0)
   {
      /* don't calculate it again ...                                         */
      return numberOfElements;
   }

   for ( iLoop = (uint8_least)0;
         iLoop < (uint8_least)CDC_FLASH_SEGMENT_NUMBER_ALL;
         iLoop++
       )
   {
      pCurrentStartAddress = &sharedBootROMData.MemSegTable[iLoop][0];
      nextStartAddress     = sharedBootROMData.MemSegTable[iLoop][1] +
                             (CDC_FLASHADDRESS_T)0x01;
      currentSize = nextStartAddress - *pCurrentStartAddress;

      if ( (*pCurrentStartAddress == expectedStartAddress) &&
           (currentSize           == expectedSize)
         )
      {
         /*
          * A same sized, bordering flash segment was found:
          * No additional element in the MemorySegmentationTable is necessary
          */
      }
      else
      {
         /*
          * An other element in the MemorySegmentationTable is necessary
          */
         ++numberOfElements;
      }

      expectedStartAddress = nextStartAddress;
      expectedSize         = currentSize;
   }

   return numberOfElements;
} /* end of function 'Cdc_GetNumberOfElementsInReadMemorySegmentationTable'   */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierSvk                                **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F102_SVK_SYSTEM_SUPPLIER /                        **
**                 DIAG_DID_F103_SVK_PLANT /                                  **
**                 DIAG_DID_F1xx_SVK_BACKUP                                   **
**                 Read the system supplier, plant or backup SVK              **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : SvkHistoryMemory                                           **
**                                                                            **
** PARAMETER     : pMsgContext     : diagnostic context                       **
**                 SvkHistory      : system supplier, plant or backup SVK     **
**                 SvkBackupNumber : backup number, in case of backup SVK     **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                 boolean isPagedProcessingExecuted                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvk
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONST(SvkHistoryType,AUTOMATIC) SvkHistory,
   CONST(uint8,AUTOMATIC) SvkBackupNumber,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
   NvM_BlockIdType SvkBlockId;
   uint8 tmpSvkBackupNumber;
   Std_ReturnType NvReadStatus;
   boolean NvWaitStatus;
   uint16 SWECount;
   uint32 Identifier;
   uint8 Version;
   uint16 i;

   switch(SvkHistory)
   {
      case SVKHISTORY_SYSTEMSUPPLIER:
         /* svk backup of system supplier should be read                      */
         SvkBlockId = CDC_NVM_BLOCK_SVK_SYS_SUPP;
         break;
      case SVKHISTORY_PLANT:
         /* svk backup of plant should be read                                */
         SvkBlockId = CDC_NVM_BLOCK_SVK_PLANT;
         break;
      case SVKHISTORY_BACKUP:                                     /* no break */
      default:
#if (CDC_NUMBEROFSVKBACKUPS > 0)
         if ( SvkBackupNumber < (uint8)CDC_NUMBEROFSVKBACKUPS )
         {
            /*
             * Calculate position that have to read from svk history memmory.
             * Remark: SvkBackupNumber = 0 means the last backup stored in
             *         history memory during flash download.
             * Remark: The SVK backup memory is a ring buffer
             */
            tmpSvkBackupNumber = SvkHistoryMemory.SvkBackupFIFOCounter;

            tmpSvkBackupNumber = CDC_GETPREVELEMENTINFIFO
                                    ( tmpSvkBackupNumber,
                                      SvkBackupNumber + (uint8)1,
                                      CDC_NUMBEROFSVKBACKUPS
                                    );

            /* normal svk backup should be read                               */
            SvkBlockId = Cdc_SvkBackups[tmpSvkBackupNumber];
         }
         else
#endif /* (CDC_NUMBEROFSVKBACKUPS > 0)                                        */
         {
            /*
             * normal svk backup should be read but this backup is not
             * configured in this case send negative response an return here
             */
            *ResponseCode = DCM_E_REQUESTOUTOFRANGE;

            return;
         }
         break;
   }

   /* check the response data length, whether they fit into the dcm buffer    */
   if ( ((uint16)SVK_BACKUP_SIZE + 2) <= pMsgContext->resMaxDataLen )
   {
       NvReadStatus = CDC_NVM_READ_BLOCK(SvkBlockId,&pMsgContext->resData[2]);
       NvWaitStatus = CDC_WAITNVMREADY(SvkBlockId);
       
       if(  (E_OK == NvReadStatus)
          &&(TRUE == NvWaitStatus))
       {
          /*
           * check if SVK history entry has initial value. That means that the
           * requested backup was not written before
           */
          if ( pMsgContext->resData[2] != sharedBootROMData.SvkVersion )
          {
             /* the requested backup was not written before                          */
             *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
          }
          else
          {
             /* send positive response                                               */
        	 SWECount = (pMsgContext->resData[4] << 8u) | pMsgContext->resData[5];
        	 Identifier = (HwDescData.HweTable[0].HWESgbmId[1] << 24u) |
        			 (HwDescData.HweTable[0].HWESgbmId[2] << 16u) |
        			 (HwDescData.HweTable[0].HWESgbmId[3] << 8u) |
        			 HwDescData.HweTable[0].HWESgbmId[4];
        	 Version = HwDescData.HweTable[0].HWESgbmId[5];

    		 pMsgContext->resDataLen = (uint16)(6u + FINGERPRINTLENGTH + (SGBM_ID_LENGTH * SWECount));

        	 /* If it is a 2MB part, don't report out the HWEL data. */
        	 if(((3u == Version) || (103u == Version)) &&
        			 ((0x1237 == Identifier) || (0x1238 == Identifier))
        			 )
        	 {
        		 /* Subtract the length of the HWEL data from the response length. */

        		/* Copy the data after the HWEL data backwards starting at the index that HWEL data starts at.*/
        		if(2u == pMsgContext->resData[27])
        		{
        			pMsgContext->resDataLen -= 8;
        			pMsgContext->resData[5]--;

					for(i = 27u; i < pMsgContext->resDataLen; i++)
					{
						pMsgContext->resData[i] = pMsgContext->resData[i + 8u];
					}
        		}
        	 }
          }
       }
       else
       {
             *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
       }
       
   }
   else
   {
         /* response data don't fit into the dcm buffer                          */
         /*
          * paged buffer processing is disabled -> data can't transmitted
          */
         *ResponseCode = DCM_E_RESPONSE_TOO_LONG;
   }
   
} /* end of function 'Cdc_ReadDataByIdentifierSvk'                            */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :   Cdc_Init                                                 **
**                                                                            **
** DESCRIPTION   :   Initialization: called once on startup                   **
**                   by EcuM                                                  **
**                                                                            **
** PRECONDITIONS :   the NvM blocks have been read                            **
**                   the VSM initialization has been completed                **
**                   the DARH initialization has been completed               **
**                                                                            **
** PARAMETER     :   ---                                                      **
**                                                                            **
** RETURN        :   ---                                                      **
**                                                                            **
** REMARKS       :   ---                                                      **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_Init(void)
{
#if (CdcScenarioApplication == STD_ON)
   CDC_VSM_OPERATINGMODETYPE           op_mode;
   CDC_VSM_OPERATINGMODEEXTENSIONTYPE  ext_op_mode;

   /*
    * Set the correct sub session in the application default session
    * is operation mode FLASH active and extended op-mode FLASH_ENABLED?
    */
    /* Return value is always E_OK in this case and can be ignored */
   (void)CDC_VSM_GETMODE( &op_mode );
    /* Return value is always E_OK in this case and can be ignored */
   (void)CDC_VSM_GETMODEEXTENSION( &ext_op_mode );

   if ( op_mode != CDC_VSM_MM_MODE_NORMAL )
   {
      boolean  eventFailed;

      /* set error memory entry "Energiesparmode aktiv", if the new
       * operation mode is not NORMAL and the error memory entry was not set yet
       */
      /* Return value is always E_OK in this case and can be ignored */
      (void)Dem_GetEventFailed( CdcVsmEventOpModeRef, &eventFailed );
      if ( eventFailed == FALSE )
      {
         /* Return value is always E_OK in this case and can be ignored */
         (void)Dem_SetOperationCycleState(DEM_OPCYCLE_VSM_OPMODE, DEM_CYCLE_STATE_START);
         Dem_ReportErrorStatus(CdcVsmEventOpModeRef, DEM_EVENT_STATUS_FAILED);
         /* Return value is always E_OK in this case and can be ignored */
         (void)Dem_SetOperationCycleState(DEM_OPCYCLE_VSM_OPMODE, DEM_CYCLE_STATE_END);
      }
   }

   if ( ( op_mode     == CDC_VSM_MM_MODE_BMW_FLASH ) &&
        ( ext_op_mode == CDC_VSM_MM_MODE_EXTENSION_FLASH_ENABLED )
      )
   {
      /* FlashMode is active                                                  */
      activeSubSession = DEFAULT_APPL_FLASH_MODE_ACTIVATED;

      /* disable error memory in activated FlashMode                          */
      /* Return value is always E_OK in this case and can be ignored */
      (void)Dem_DisableDTCStorage(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
      /* store the actual error memory state for CDC handling - disabled      */
      isErrorMemoryEnabled = FALSE;

      /* disable non diagnostic communication in activated FlashMode          */
      (void)CDC_SETCOMMUNICATIONMODE( DIAG_UDS28_01_ENABLE_RX_AND_DISABLE_TX,
                                      DIAG_UDS28_01_NORMAL_COMM_MSG );

#if (DCM_ROE_ENABLED == STD_ON)
      /* the ROE functionality must be suspended, if not set yet              */
      /* Return value is ignored because no error/retry handling is provided in Cdc_Init */
      (void)Cdc_SetRoeSuspendedStatus( TRUE );
#endif /* (DCM_ROE_ENABLED == STD_ON)                                         */
   }
   else
   {
      /* FlashMode is not active                                              */
      activeSubSession = DEFAULT_APPL_FLASH_MODE_DEACTIVATED;
      /* store the actual error memory state for CDC handling - enabled       */
      isErrorMemoryEnabled = TRUE;
#if (DCM_ROE_ENABLED == STD_ON)
      /* the ROE functionality can release the suspended mode, if set         */
      /* Return value is ignored because no error/retry handling is provided in Cdc_Init */
      (void)Cdc_SetRoeSuspendedStatus( FALSE );
#endif /* (DCM_ROE_ENABLED == STD_ON)                                         */
   }
#endif /* (CdcScenarioApplication == STD_ON)                                  */
}

#if (CdcScenarioApplication == STD_ON)
#if (DCM_ROE_ENABLED == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_SetRoeSuspendedStatus                                  **
**                                                                            **
** DESCRIPTION   : Sets or clears the suspended state of the ROE              **
**                 functionality of the DARH module                           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : boolean isSuspended (new suspended state of the ROE)       **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, CDC_CODE) Cdc_SetRoeSuspendedStatus
(
   boolean isSuspended
)
{
   Std_ReturnType                   errorCode = E_OK;
   CDC_DARH_ROEENGINETYPE           cdcRoeEngine;

   /* Read the actual ROE state of the DARH module                            */
   /* Return value is always E_OK and can be ignored*/
   (void)CDC_DARH_GETROESTATUS(&cdcRoeEngine);

   /* do not store the new state permanent                                    */
   cdcRoeEngine.RoeStoreBit = FALSE;

   if( isSuspended == TRUE )
   {
      /* the ROE functionality must be suspended                              */
      cdcRoeEngine.RoeIsStarted = CDC_ROE_START_SUSPENDED;
   }
   else
   {
      /* the ROE functionality can release the suspended mode                 */
      cdcRoeEngine.RoeIsStarted = CDC_ROE_STOP_SUSPENDED;
   }

   /* inform the DARH about the new ROE state                                 */
   if( CDC_DARH_SETROESTATUS(&cdcRoeEngine) != (Std_ReturnType)E_OK)
   {
      /* DARH request refused                                                 */
      errorCode = E_NOT_OK;
   }

   return errorCode;
}
#endif /* (DCM_ROE_ENABLED == STD_ON)                                         */
#endif /* (CdcScenarioApplication == STD_ON)                                  */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierActiveDiagSession                  **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F186_ACTIVE_DIAG_SESSION                          **
**                 Read active session                                        **
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
#if (DIAG_DID_F186_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service ReadDataByIdentifier ActiveDiagnosticSession is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierActiveDiagSession
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   SubSessionType    theActiveSubSession;
#if (CDC_BAC_VERSION == CDC_BAC3X)
    Dcm_SesCtrlType   ActiveSession;
#endif

   /* Cache the pointer                                                       */
   Dcm_MsgType       resDataPtr = &pMsgContext->resData[2];

#if (CDC_BAC_VERSION == CDC_BAC3X)
   /* activeDiagnosticSession MSB: get active session from DCM                */
   /* Return value is always E_OK and can be ignored */
   (void)Dcm_GetSesCtrlType(&ActiveSession);
   /* activeDiagnosticSession MSB: get active session from DCM                */
   *resDataPtr++ = ActiveSession;
#endif

#if (CDC_BAC_VERSION == CDC_BAC21)
   /* activeDiagnosticSession MSB: get active session from DCM                */
   *resDataPtr++ = Dcm_GetSesCtrlType();
#endif   

#if (CdcScenarioApplication == STD_ON)
#if (CDC_SC_CODING_ENABLE == STD_ON)
#if (CDC_BAC_VERSION == CDC_BAC21)
   if ( Dcm_GetSesCtrlType() == CODING_SESSION )
#endif
#if (CDC_BAC_VERSION == CDC_BAC3X)
   if ( CODING_SESSION == ActiveSession )
#endif   
   {
      theActiveSubSession = (SubSessionType)(Dcm_GetSecurityLevel() + 1);
   }
   else
#endif /* (CDC_SC_CODING_ENABLE == STD_ON)                                    */
#endif /* (CdcScenarioApplication == STD_ON)                                  */
   {
      theActiveSubSession = activeSubSession;
   }

   /*
    * activeDiagnosticSession LSB:
    * In Bootloader the higher nibble is used to save the substates in case of a
    * positive response with negativ content (e.g.
    * PROG_BOOT_MEMORY_ERASE_FAILED). This states are not reported to the
    * tester.
    */
#if (CdcScenarioBootloader == STD_ON)
   *resDataPtr = (uint8)((uint8)0x0Fu & (uint8)theActiveSubSession);
#else
   *resDataPtr = (uint8)theActiveSubSession;
#endif

   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F186_RESPONSE_LENGTH;
} /* end of function 'Cdc_ReadDataByIdentifierActiveDiagSession'              */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierTimingParameters                   **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2504_FLASH_TIMING_PARAMS                          **
**                 Read program specific timing parameters                    **
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
#if (DIAG_DID_2504_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service ReadDataByIdentifier FlashTimingParameter is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierTimingParameters
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* Function returns always the first parameter
     so the return value can be ignored */
   (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) &pMsgContext->resData[2],
                            (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) &sharedBootROMData.TimingParameters[0],
                            sizeof(sharedBootROMData.TimingParameters)
                          );

   /* set response length                                                     */
   pMsgContext->resDataLen = (uint16)DIAG_DID_2504_RESPONSE_LENGTH;
} /* end of function 'Cdc_ReadDataByIdentifierTimingParameters'               */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierStandardCoreVersion                **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_1720_STANDARD_CORE_VERSION                        **
**                 Read the actual SC version from 'StandardCore_Cfg.h'       **
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
#if (DIAG_DID_1720_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service ReadDataByIdentifier StandardCoreVersion is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierStandardCoreVersion
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   *resDataPtr++ = (uint8)CDC_STANDARDCORE_MAJOR_VERSION;
   *resDataPtr++ = (uint8)CDC_STANDARDCORE_MINOR_VERSION;
   *resDataPtr++ = (uint8)CDC_STANDARDCORE_PATCH_VERSION;
   *resDataPtr   = (uint8)0;                                      /* reserved */

   /* set response length                                                     */
   pMsgContext->resDataLen = (uint16)DIAG_DID_1720_RESPONSE_LENGTH;
} /* end of function 'Cdc_ReadDataByIdentifierStandardCoreVersion'            */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierProgrammingCounter                 **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2502_PROG_COUNTER                                 **
**                 Read programming counter                                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : BootProgCounter.ProgrammingCounter                         **
**                 sharedBootROMData.ProgrammingCounterMaxValue               **
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
#if (DIAG_DID_2502_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service ReadDataByIdentifier ProgrammingCounter is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierProgrammingCounter
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   uint8_least iLoop;                              /* temporary loop variable */
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   /*
    * search for the max. value of all ProgrammingCounters -> store to
    * 'programmingCounter'
    */
   uint16 highestSWEProgrammingCounter = (uint16)0;
   for ( iLoop = (uint8_least)0;
         iLoop < (uint8_least)CDC_SWENUMBEROFALLSWE;
         iLoop++
       )
   {
      if ( BootProgCounter.ProgrammingCounter[iLoop] >
                                                  highestSWEProgrammingCounter )
      {
         highestSWEProgrammingCounter =
                                      BootProgCounter.ProgrammingCounter[iLoop];
      }
   }

   *resDataPtr++ = (uint8)0x00;                              /* reserved byte */

   if ( highestSWEProgrammingCounter >=
                                  sharedBootROMData.ProgrammingCounterMaxValue )

   {
      /* the ECU can be reprogrammed never again                              */
      *resDataPtr++ = (uint8)NEVERMORE;
   }
   else if ( highestSWEProgrammingCounter ==
          (uint16)(sharedBootROMData.ProgrammingCounterMaxValue - (uint16)0x1) )
   {
      /* the ECU can be reprogrammed at least for one time                    */
      *resDataPtr++ = (uint8)ATLEASTONETIME;
   }
   else
   {
      /* the ECU can be reprogrammed for several times. It means              */
      *resDataPtr++ = (uint8)SEVERALTIMES;
   }

   /* send max. value of ProgrammingCounters                                  */
   *resDataPtr++ = CDC_GETHIBYTE(highestSWEProgrammingCounter);
   *resDataPtr   = CDC_GETLOBYTE(highestSWEProgrammingCounter);

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_2502_RESPONSE_LENGTH;
} /* end of function 'Cdc_ReadDataByIdentifierProgrammingCounter'             */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierProgrammingCounterMaxValue         **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2503_PROG_COUNTER_MAX_VALUE                       **
**                 Response with ProgrammingCounterMaxValue                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData.ProgrammingCounterMaxValue               **
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
#if (DIAG_DID_2503_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service ReadDataByIdentifier ProgrammingCounterMaxValue is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierProgrammingCounterMaxValue
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   *resDataPtr++ = CDC_GETHIBYTE(sharedBootROMData.ProgrammingCounterMaxValue);
   *resDataPtr   = CDC_GETLOBYTE(sharedBootROMData.ProgrammingCounterMaxValue);

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_2503_RESPONSE_LENGTH;
} /* end of function 'Cdc_ReadDataByIdentifierProgrammingCounterMaxValue'     */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierMemorySegmentationTable            **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE                    **
**                 Read memory segmentation table                             **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                 boolean isPagedProcessingExecuted                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if ( (DCM_PAGEDBUFFER_ENABLED == STD_OFF)       &&                            \
      (DIAG_DID_2501_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH))
   /*
    * This must not be an error, because a run length encoding of the response
    * is used
    */
   #warning "Cdc_Common_Mandatory.c: The worst-case response length for service ReadDataByIdentifier MemorySegmentationTable is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierMemorySegmentationTable
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
   /*
    * The response will be run length encoded:
    * calculate response length at runtime
    */
   pMsgContext->resDataLen =
                    ( (uint16)10 *
                      (uint16)Cdc_GetNumberOfElementsInReadMemorySegmentationTable()
                    ) + (uint16)5u;

   /* check the response data length, whether they fit into the dcm buffer    */
   if ( pMsgContext->resDataLen <= pMsgContext->resMaxDataLen )
   {
      /* all response data fit into the dcm buffer --> process it             */
      Cdc_ProcessReadMemorySegmentationTable(&pMsgContext->resData[0],
                                             (uint16)RESPONSE_FIT_INTO_BUFFER );

#if ( SC_SLAVE_CPU == STD_ON )
      Bsi_MemorySegmentTable( pMsgContext );
#endif  /* SC_SLAVE_CPU */
   }
   else
   {
      #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
         /* paged buffer processing is enabled                                */
         /* set isPagedProcessingExecuted to TRUE to prevent a duplicated
          * execution of Dcm_ProcessingDone() because this will be done by
          * the PagedBuffering
          */
         *isPagedProcessingExecuted = TRUE;
         /* start paged buffer processing                                     */
         Dcm_StartPagedProcessing(pMsgContext);
      #else
         /* paged buffer processing is disabled -> data can't be transmitted  */
         *ResponseCode = DCM_E_RESPONSE_TOO_LONG;
      #endif
#if ( SC_SLAVE_CPU == STD_ON )
         Cdc_DcmSendResponseCode(pMsgContext, ResponseCode);
#endif  /* SC_SLAVE_CPU */
   }
} /* end of function 'Cdc_ReadDataByIdentifierMemorySegmentationTable'        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierSvkCurrent                         **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F101_SVK_AKTUELL                                  **
**                 Read present/current SVK                                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                 boolean isPagedProcessingExecuted                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvkCurrent
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
   uint16 SvkSize = (uint16)SVK_BACKUP_SIZE;
   /* ---- NXTR PATCH START -----
    * Date Added: 12/2/13
    * Added by: K. Smith
    *
    * Reason: Support for the changes below.
    */
   uint16 numberOfSvks;
   uint16 RespSvkCnt;
	/* ---- NXTR PATCH END ----- */

#if (CdcScenarioApplication == STD_ON)
#if (CDC_SC_CODING_ENABLE == STD_ON)
         SvkSize += ( (uint16)CDC_CODING_DIAGGETNUMBEROFCODEDAREAS() * (uint16)8 );
#endif
#endif

   /* check the response data length, whether they fit into the dcm buffer    */
   if ( (SvkSize + 2) <= pMsgContext->resMaxDataLen )
   {
      Cdc_GetCurrentSvk(&pMsgContext->resData[0],
                    (uint16)RESPONSE_FIT_INTO_BUFFER);

   /* ---- NXTR PATCH START -----
    * Date Added: 12/2/13
    * Added by: K. Smith
    *
    * Reason: Added to change the lenth of the response based on the number of SVKs returned from the service.
	* Original Code:
	* pMsgContext->resDataLen = (uint16)(2u + SvkSize);
	*/
      numberOfSvks = (uint16)CDC_NUMBEROFHWESGBMIDS +
                     (uint16)CDC_SWENUMBEROFALLSWE  +
                     (uint16)CDC_CODING_DIAGGETNUMBEROFCODEDAREAS();

      RespSvkCnt = (uint16)(pMsgContext->resData[4] << 8u) + (uint16)(pMsgContext->resData[5]);

      if(numberOfSvks > RespSvkCnt)
      {
    	  pMsgContext->resDataLen = (uint16)(2u + SvkSize) - (uint16)((numberOfSvks - RespSvkCnt) * (uint16)8u);
      }
      else
      {
    	  /* send positive response                                               */
    	  pMsgContext->resDataLen = (uint16)(2u + SvkSize);
      }
	/* ---- NXTR PATCH END ----- */

#if ( SC_SLAVE_CPU == STD_ON )
      Bsi_SvkLesen( pMsgContext );
#endif  /* SC_SLAVE_CPU */
   }
   else
   {
      /* response data don't fit into the dcm buffer                          */
      #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
         /* paged buffer processing is enabled                                */

         /* set the length of the positive response                           */
         pMsgContext->resDataLen = (uint16)(2u + SvkSize);

         /* set isPagedProcessingExecuted to TRUE to prevent a duplicated
          * execution of Dcm_ProcessingDone() because this will be done by
          * the PagedBuffering
          */
         *isPagedProcessingExecuted = TRUE;
         /* start paged buffer processing                                     */
         Dcm_StartPagedProcessing(pMsgContext);
      #else
         /* paged buffer processing is disabled -> data can't transmitted     */
         *ResponseCode = DCM_E_RESPONSE_TOO_LONG;
      #endif
#if ( SC_SLAVE_CPU == STD_ON )
         Cdc_DcmSendResponseCode(pMsgContext, ResponseCode);
#endif  /* SC_SLAVE_CPU */
   }
} /* end of function 'Cdc_ReadDataByIdentifierSvkCurrent'                     */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierSvkSystemSupplier                  **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F102_SVK_SYSTEM_SUPPLIER                          **
**                 Read the system supplier SVK.                              **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                 boolean isPagedProcessingExecuted                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvkSystemSupplier
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
   Cdc_ReadDataByIdentifierSvk (
                                     pMsgContext,
                                     SVKHISTORY_SYSTEMSUPPLIER,
                                     (uint8)0x00u,     /* dummy value */
                                     ResponseCode,
                                     isPagedProcessingExecuted
                               );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierSvkPlant                           **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F103_SVK_PLANT                                    **
**                 Read the plant SVK.                                        **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                 boolean isPagedProcessingExecuted                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvkPlant
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
   Cdc_ReadDataByIdentifierSvk (
                                     pMsgContext,
                                     SVKHISTORY_PLANT,
                                     (uint8)0x00u,     /* dummy value */
                                     ResponseCode,
                                     isPagedProcessingExecuted
                               );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierSvkBackup                          **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F104_SVK_BACKUP_MIN - DIAG_DID_F140_SVK_BACKUP_MAX**
**                 Read the backup SVK.                                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : pMsgContext : pointer to Dcm_MsgContextType                **
**                 dataId      : data ID                                      **
**                 Dcm_NegativeResponseCodeType* const ResponseCode           **
**                 boolean isPagedProcessingExecuted                          **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvkBackup
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   uint16 dataId,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
   CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
)
{
   Cdc_ReadDataByIdentifierSvk
      (
         pMsgContext,
         SVKHISTORY_BACKUP,
         (uint8)( dataId - (uint16)DIAG_DID_F104_SVK_BACKUP_MIN ),
         ResponseCode,
         isPagedProcessingExecuted
      );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierEcuManufacturingData               **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F18B_ECU_MANUFACTURING_DATA                       **
**                 Read the ECU Manufacturing Data                            **
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
#if (DIAG_DID_F18B_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service ReadDataByIdentifier EcuManufacturingData is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierEcuManufacturingData
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
#if (CDC_ECUMANUFACTURINGDATALENGTH != 3u)
   #error "Cdc_Common_Mandatory.c: CDC_ECUMANUFACTURINGDATALENGTH must be 3"
#endif

   /* copy ECUManufacturingData to response                                   */
   /* Function returns always the first parameter
     so the return value can be ignored */
   (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) &pMsgContext->resData[2],
                            (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) &HwDescData.ECUManufacturingData[0],
                            sizeof(HwDescData.ECUManufacturingData)
                          );

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F18B_RESPONSE_LENGTH;
} /* end of function 'Cdc_ReadDataByIdentifierEcuManufacturingData'           */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierSerialNumber                       **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F18C_ECU_SERIAL_NUMBER                            **
**                 Read the ECU SerialNumber                                  **
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
#if (DIAG_DID_F18C_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service ReadDataByIdentifier EcuSerialNumber is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierEcuSerialNumber
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
#if (CDC_ECUSERIALNUMBERLENGTH != 10u)
   #error "Cdc_Common_Mandatory.c: CDC_ECUSERIALNUMBERLENGTH must be 10"
#endif

   /* copy EcuSerialNumber to response                                        */
   /* Function returns always the first parameter
     so the return value can be ignored */
   (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) &pMsgContext->resData[2],
                            (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) &HwDescData.ECUSerialNumber[0],
                            sizeof(HwDescData.ECUSerialNumber)
                          );

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F18C_RESPONSE_LENGTH;
} /* end of function 'Cdc_ReadDataByIdentifierEcuSerialNumber'                */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ReadDataByIdentifierVin                                **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F190_VIN                                          **
**                 Read VIN                                                   **
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
#if (DIAG_DID_F190_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service ReadDataByIdentifier VIN is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierVin
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
)
{
   /* copy VIN to response                                                    */
   /* Function returns always the first parameter
     so the return value can be ignored */
   (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) &pMsgContext->resData[2],
                            (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) &BootProgData.VIN[0],
                            sizeof(BootProgData.VIN)
                          );

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F190_RESPONSE_LENGTH;
} /* end of function 'Cdc_ReadDataByIdentifierVin'                            */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_RoutineControlReadDevelopmentInfo                      **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_0205_READ_DEVELOPMENT_INFO                        **
**                 Reads the SWE development info for the sgbm-id             **
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
#if (DIAG_RID_0205_RESPONSE_LENGTH >= DCM_BUFFER_LENGTH)
   #error "Cdc_Common_Mandatory.c: The response length for service RoutineControl ReadDevelopmentInfo is greater than DCM_BUFFER_LENGTH"
#endif
FUNC(void, CDC_CODE) Cdc_RoutineControlReadDevelopmentInfo
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
)
{
   boolean     foundDevelopmentInfo = FALSE;       /*
                                                    * TRUE when an according SWE
                                                    * is found
                                                    */
   /* Cache the request pointer                                               */
   Dcm_MsgType reqDataPtr;

   uint8_least iLoop  = (uint8_least)0;            /* temporary loop variable */

   if (pMsgContext->reqDataLen == ((uint16)3 + (uint16)SGBM_ID_LENGTH))
   {
      reqDataPtr = &pMsgContext->reqData[3];

      switch(reqDataPtr[0])                        /* check process class     */
      {
         case PROCESSCLASS_HWEL:
         case PROCESSCLASS_HWAP:
         case PROCESSCLASS_HWFR:
            /* search in HWEDevelopmentInfo list                              */
#if ((CDC_HWEDEVELOPMENTINFOLENGTH > 0u) && (CDC_NUMBEROFHWESGBMIDS > 0u))
            do
            {
               /* cache pointers to HWE-Table and SgbmId                      */
               CONSTP2CONST(HweTableType, AUTOMATIC, CDC_FAR_CONST) tmpHweTable =
                                                    &HwDescData.HweTable[iLoop];
               CONSTP2CONST(uint8, AUTOMATIC, CDC_FAR_CONST) tmpSgbmId =
                                                    &tmpHweTable->HWESgbmId[0];

               /* check SweClassification                                     */
               if ( CDC_SC_MEMCMP_ROM( (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) &tmpSgbmId[0],
                                       (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) reqDataPtr,
                                       SGBM_ID_LENGTH
                                     ) == 0x00
                  )
               {
                  /* an according SWE was found                               */
                  CONSTP2CONST(uint8, AUTOMATIC, CDC_FAR_CONST) tmpXweDevInfo =
                                            &tmpHweTable->HWEDevelopmentInfo[0];
                   /* Function returns always the first parameter
                     so the return value can be ignored */
                  (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) &pMsgContext->resData[3],
                                           (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) &tmpXweDevInfo[0],
                                           (size_t)(tmpXweDevInfo[0] + 0x01)
                                         );

                  pMsgContext->resDataLen = (uint16)(3u + tmpXweDevInfo[0] + 0x01);
                  foundDevelopmentInfo = TRUE;
               }

               ++iLoop;
            } while ( (foundDevelopmentInfo == FALSE) &&
                      (iLoop < (uint8_least)CDC_NUMBEROFHWESGBMIDS)
                    );
#endif
            break;
         case PROCESSCLASS_CAFD:
         case PROCESSCLASS_BTLD:
         case PROCESSCLASS_FLSL:
         case PROCESSCLASS_SWFL:
         case PROCESSCLASS_SWFF:
         case PROCESSCLASS_SWPF:
         case PROCESSCLASS_ONPS:
         case PROCESSCLASS_IBAD:
         case PROCESSCLASS_FAFP:
         case PROCESSCLASS_FCFA:
         /* case PROCESSCLASS_TLRT: deactivated because of FP_5029            */
         /* case PROCESSCLASS_TPRG: deactivated because of FP_5029            */
         case PROCESSCLASS_ENTD:
         case PROCESSCLASS_NAVD:
         case PROCESSCLASS_FCFN:
            /* search in SWEDevelopmentInfo list                              */
            do
            {
               /* cache pointers to SWE-Table and SgbmId                      */
               CONSTP2CONST(SweTableType, AUTOMATIC, CDC_FAR_CONST) tmpSweTable =
                                     sharedBootROMData.PointerToSweTable[iLoop];
               CONSTP2CONST(uint8, AUTOMATIC, CDC_FAR_CONST) tmpSgbmId =
                                     &tmpSweTable->SgbmId[0];

               /* check SweClassification                                     */
               if ( CDC_SC_MEMCMP_ROM( (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) &tmpSgbmId[0],
                                       (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) reqDataPtr,
                                       SGBM_ID_LENGTH
                                     ) == 0x00
                  )
               {
                  /* an according SWE was found                               */
                  CONSTP2CONST(uint8, AUTOMATIC, CDC_FAR_CONST) tmpXweDevInfo =
                                                    &tmpSweTable->SweDevInfo[0];
                   /* Function returns always the first parameter
                     so the return value can be ignored */
                  (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) &pMsgContext->resData[3],
                                           (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) &tmpXweDevInfo[0],
                                           (size_t)(tmpXweDevInfo[0] + 0x01)
                                         );

                  pMsgContext->resDataLen = (uint16)(3u + tmpXweDevInfo[0] + 0x01);
                  foundDevelopmentInfo = TRUE;
               }

               ++iLoop;
            } while ( (foundDevelopmentInfo == FALSE) &&
                      (iLoop < (uint8_least)CDC_SWENUMBEROFALLSWE)
                    );
            break;
         default:
             /* invalid process class                                         */
             *ResponseCode = DCM_E_REQUESTOUTOFRANGE;
             /* return is used here to decrease nesting depth                 */
#if ( SC_SLAVE_CPU == STD_ON )
             Cdc_DcmSendResponseCode(pMsgContext, ResponseCode);
#endif  /* SC_SLAVE_CPU */
             return;
             /* no break;                                                     */
      }

      if (foundDevelopmentInfo == FALSE)
      {
         /*
          * No according SWE found or no DevelopmentInfo is available:
          * Response with 0x00
          */
         pMsgContext->resData[3] = (uint8)0x00;
         pMsgContext->resDataLen = (uint16)4;

#if ( SC_SLAVE_CPU == STD_ON )
         Bsi_ReadDevelopmentInfo( pMsgContext );
      }
      else
      {
         Cdc_DcmSendResponseCode(pMsgContext, ResponseCode);
#endif  /* SC_SLAVE_CPU */
      }
   }
   else
   {
      *ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
#if ( SC_SLAVE_CPU == STD_ON )
      Cdc_DcmSendResponseCode(pMsgContext, ResponseCode);
#endif  /* SC_SLAVE_CPU */
   }
} /* end of function 'Cdc_RoutineControlReadDevelopmentInfo'                  */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_GetCurrentSvk                                          **
**                                                                            **
** DESCRIPTION   : collect information about current SVK to data buffer       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint8* dataBufPtr: Pointer to data buffer                     **
**                                                                            **
**                 uint16 dataLen - max. length of the writeable data         **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_GetCurrentSvk
(
   Dcm_MsgType dataBufPtr,
   Dcm_MsgLenType dataLen
)
{
   uint8_least iLoop;                              /* temporary loop variable */
   uint16      numberOfSvks;                                /* number of svks */
   uint16      numberOfCodingCafIds = (uint16)0;  /* number of coding caf ids */
   uint16      writtenData;                   /* counter for the written data */
   boolean     bLeaveEarly          = FALSE;

   /* ---- NXTR PATCH START -----
    * Date Added: 12/2/13
    * Added by: K. Smith
    *
    * Reason: Added to support patch in later in this function.
    */
   uint32 Identifier;
   uint8 Version;
   P2VAR(uint8, AUTOMATIC, AUTOMATIC) SWECntDataPtr;
   /* ---- NEXTER PATCH END ----- */

   /* ############################   STEP 0   ################################*/
   /* only at first call of this function during a request do ...             */
   if ( iStep == (uint8_least)0 )
   {
      #if (CdcScenarioApplication == STD_ON)
         #if (CDC_SC_CODING_ENABLE == STD_ON)
               numberOfCodingCafIds += CDC_CODING_DIAGGETNUMBEROFCODEDAREAS();
         #endif
      #endif

      if ( dataLen != (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM )
      {
         *dataBufPtr++ = (uint8)0xF1;
         *dataBufPtr++ = (uint8)0x01;
      }

      /* SVK Version                                                          */
      *dataBufPtr++ = sharedBootROMData.SvkVersion;

      /*
       * set ProgrammingDependencies status:
       * In the Application, the status is always OK, otherwise the BootManager
       * would have started the Bootloader not the Application
       */
      #if (CdcScenarioBootloader == STD_ON)
         *dataBufPtr++ = (uint8)CheckProgDepStatus();
      #else
         *dataBufPtr++ = (uint8)DEPCHECKCORRECTRESULT;
      #endif

      /*
       * Number of SVK entries in dataBufPtr[2] and dataBufPtr[3]:
       * Count number of HWE SVKs, number of SWE SVKs and number of coding caf
       * ids
       */
      numberOfSvks = (uint16)CDC_NUMBEROFHWESGBMIDS +
                     (uint16)CDC_SWENUMBEROFALLSWE  +
                     numberOfCodingCafIds;
      /* set number of SVK entries                                            */
      *dataBufPtr++ = CDC_GETHIBYTE(numberOfSvks);                        /* MSB */

   /* ---- NXTR PATCH START -----
    * Date Added: 12/2/13
    * Added by: K. Smith
    *
    * Reason: Added to apply a pointer back to the LSB of the number of SVKs
    */
   SWECntDataPtr = dataBufPtr;
   /* ---- NEXTER PATCH END ----- */

      *dataBufPtr++ = CDC_GETLOBYTE(numberOfSvks);                        /* LSB */

      writtenData =      (uint16)6;
      iStep       = (uint8_least)1;
   }
   else
   {
      writtenData = (uint16)0;
   }

   /* ############################   STEP 1   ################################*/
   if ( ( iStep == (uint8_least)1 ) &&
        ( ( dataLen == (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) ||
          ( (sizeof(BootProgData.FingerPrint) + writtenData) <= dataLen )
        )
      )
   {
      /* copy current FingerPrint                                             */
      /* Function returns always the first parameter
        so the return value can be ignored */
      (void)CDC_SC_MEMCPY_ROM ( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) dataBufPtr,
                                (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) &BootProgData.FingerPrint[0],
                                sizeof(BootProgData.FingerPrint)
                              );

         /* increase data pointer with FingerPrint size                       */
      dataBufPtr += sizeof(BootProgData.FingerPrint);

      writtenData += sizeof(BootProgData.FingerPrint);
      iStep        = (uint8_least)2;
   }

   /* ############################   STEP 2   ################################*/
   if ( ( iStep == (uint8_least)2 ) &&
        ( ( dataLen == (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) ||
          ( (SGBM_ID_LENGTH + writtenData) <= dataLen )
        )
      )
   {
      iLoop = iLoopStart;
      /* write bootloader and application segmentation table to response      */
      while ( (iLoop < (uint8_least)CDC_NUMBEROFHWESGBMIDS) &&
              (bLeaveEarly == FALSE)
            )
      {
       /* Function returns always the first parameter
         so the return value can be ignored */
         (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) dataBufPtr,
                                  (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) &HwDescData.HweTable[iLoop].HWESgbmId[0],
                                  SGBM_ID_LENGTH
                                );

         /* increase data pointer                                             */
         dataBufPtr += SGBM_ID_LENGTH;

         writtenData += SGBM_ID_LENGTH;

         /* ---- NXTR PATCH START -----
          * Date Added: 12/2/13
          * Added by: K. Smith
          *
          * Reason: To modify the response based on the number of SGBM ID's
          * The code works by reading the first Hwe SGBM ID which is the HWEL.
          * This data is used to determine if a second call into the loop is required.
          */
         if(NUMBEROFHWESGBMIDS > 1)
         {
			 if(HwDescData.HweTable[iLoop].HWESgbmId[0] == 1u) /* HWEL SGBM class ID is 1, this is to confirm SW is reading the correct data */
			 {
				Identifier = 	(HwDescData.HweTable[iLoop].HWESgbmId[1] << 24u) |
									(HwDescData.HweTable[iLoop].HWESgbmId[2] << 16u) |
									(HwDescData.HweTable[iLoop].HWESgbmId[3] << 8u) |
									HwDescData.HweTable[iLoop].HWESgbmId[4];
				 Version = HwDescData.HweTable[iLoop].HWESgbmId[5];

				 if( ( (3u == Version) || (103u == Version) ) &&
					 ( (0x1237 == Identifier) || (0x1238 == Identifier) ) )
				 {
					 iLoop++; /* Adds another 1 to skip the HWAP ID */
					 *SWECntDataPtr = *SWECntDataPtr - 1u; /* Remove 1 from the dataPtr[5], which is the lower byte of the number of SGBM IDs. */
				 }
			 }
         }

         /* ---- NXTR PATCH END ----- */

         iLoop++;

         /* fit the next data into the buffer or are all data written ?       */
         if ( ( dataLen != (uint16)RESPONSE_FIT_INTO_BUFFER ) &&
              ( dataLen != (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) &&
              ( (writtenData + SGBM_ID_LENGTH) > dataLen ) )
         {
            bLeaveEarly = TRUE;
         }
      }

      if ( iLoop == (uint8_least)CDC_NUMBEROFHWESGBMIDS )
      {
         /* reset iLoopStart for the next step                                */
         iLoopStart = (uint8_least)0;
         iStep      = (uint8_least)3;
      }
      else
      {
         /* save the actual iLoop value to continue on next function call     */
         iLoopStart = iLoop;
      }
   }

   /* ############################   STEP 3   ################################*/
   if ( ( iStep == (uint8_least)3 ) &&
        ( ( dataLen == (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) ||
          ( (SGBM_ID_LENGTH + writtenData) <= dataLen )
        )
      )
   {
      iLoop = iLoopStart;
      /* copy all Sgbm Ids of bootloader and application SWE Tables           */
      while ( ( iLoop < (uint8_least)CDC_SWENUMBEROFALLSWE ) &&
              ( bLeaveEarly == FALSE)
            )
      {
/*
 * In the Application, the SWEProgrammingStatus is always OK, otherwise
 * the BootManager would have started the Bootloader not the
 * Application
 */
#if (CdcScenarioBootloader == STD_ON)
         /* check if the SWE is valid in EEPROM                               */
         if ( BootProgStatus.SWEProgrammingStatus[iLoop] ==
                                                  PROGSTAT_CHECKSIGNATUREOK )
         {
#endif /* #if (CdcScenarioBootloader == STD_ON)                               */

            /* copy each Sgbm Ids of application                              */
            /* Function returns always the first parameter
              so the return value can be ignored */
            (void)CDC_SC_MEMCPY_ROM
               ( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) dataBufPtr,
                 (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) &sharedBootROMData.
                                            PointerToSweTable[iLoop]->SgbmId[0],
                 SGBM_ID_LENGTH
               );
/*
 * In the Application, the SWEProgrammingStatus is always OK, otherwise
 * the BootManager would have started the Bootloader not the
 * Application
 */
#if (CdcScenarioBootloader == STD_ON)
         }
         else
         {
            /*
             * set default value for SGBM ids of application and bootloader
             * that are not signature checked
             */
            (void)CDC_SC_MEMSET_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) dataBufPtr,
                                     (uint8)DIAG_SGBM_ID_DEFAULT_VALUE,
                                     SGBM_ID_LENGTH
                                   );
         }
#endif /* #if (CdcScenarioBootloader == STD_ON)                               */

         /* increase data pointer                                             */
         dataBufPtr += SGBM_ID_LENGTH;

         writtenData += SGBM_ID_LENGTH;

         /* fit the next data into the buffer or are all data written ?       */
         if ( ( dataLen != (uint16)RESPONSE_FIT_INTO_BUFFER ) &&
              ( dataLen != (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) &&
              ( (writtenData + SGBM_ID_LENGTH) > dataLen ) )
         {
            bLeaveEarly = TRUE;
         }
         iLoop++;
      }

      if ( iLoop == (uint8_least)CDC_SWENUMBEROFALLSWE )
      {
         /* reset iLoopStart for the next execution of this diagnostic service*/
         iLoopStart = (uint8_least)0;
         iStep      = (uint8_least)4;
      }
      else
      {
         /* save the actual iLoop value to continue on next function call     */
         iLoopStart = iLoop;
      }
   }

   /* ############################   STEP 4   ################################*/
   #if (CdcScenarioApplication == STD_ON)
      #if (CDC_SC_CODING_ENABLE == STD_ON)
      if ( ( iStep == (uint8_least)4 ) &&
           ( (dataLen == (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM) ||
             ( ( (CDC_CODING_DIAGGETNUMBEROFCODEDAREAS() * (uint16)0x08u)
                 + writtenData ) <= dataLen
             )
           )
         )
      {
         writtenData += CDC_CODING_DIAGGETCAFIDSOFCODEDAREAS(dataBufPtr);
         iStep = (uint8_least)0;
      }
   #else
      if ( iStep == (uint8_least)4 )
      {
         iStep = (uint8_least)0;
      }
      #endif
#else
   if ( iStep == (uint8_least)4 )
   {
      iStep = (uint8_least)0;
   }
   #endif

#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
   /* only if call from diagnosis and if paged buffer processing used, do ... */
   if ( ( dataLen != (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) &&
        ( dataLen != (uint16)RESPONSE_FIT_INTO_BUFFER )
      )
   {
      /* send page to DCM                                                     */
      Dcm_ProcessPage(writtenData);
   }
#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                                 */

#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_GETCURRENTSVK_CALLED, TEST_CDC_RESPONSE_CODE_NOT_USED, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */  
} /* end of function 'Cdc_GetCurrentSvk'                                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ProcessReadMemorySegmentationTable                     **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE                    **
**                 Read memory segmentation table                             **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : iLoopStart                                                 **
**                                                                            **
** PARAMETER     : dataBufPtr - Pointer for memory segmentation table data    **
**                                                                            **
**                 dataLen - max. length of the writeable data                **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ProcessReadMemorySegmentationTable
(
   Dcm_MsgType dataBufPtr,
   Dcm_MsgLenType dataLen
)
{
   uint8_least          iLoop;               /* temporary loop variable       */
   uint16               writtenData;         /* counter for the written data  */
   uint16               sameSizedFlashSegments;
                                             /* holds temporary addresses     */
   CDC_FLASHADDRESS_T   oldEndAddress        = (CDC_FLASHADDRESS_T)0;
   CDC_FLASHADDRESS_T   oldSize              = (CDC_FLASHADDRESS_T)0;
   CDC_FLASHADDRESS_T   currentSize;
   boolean              bLeaveEarly          = FALSE;
   P2CONST(CDC_FLASHADDRESS_T, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                        pCurrentStartAddress;
   P2CONST(CDC_FLASHADDRESS_T, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                        pCurrentEndAddress;

   /* only at first call of this function during a request do ...             */
   if ( iLoopStart == (uint8_least)0 )
   {
      const uint8 tmpNumberOfSWEs =
         Cdc_GetNumberOfElementsInReadMemorySegmentationTable();

      *dataBufPtr++ = (uint8)0x25u;
      *dataBufPtr++ = (uint8)0x01u;

      /* set addressAndLengthFormatIdentifier: equivalent uint32 (4 Bytes)    */
      *dataBufPtr++ = (uint8)DIAG_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER;

      /* number of SWEs (boot and appl) MSB/LSB                               */
      *dataBufPtr++ = CDC_GETHIBYTE((uint16)tmpNumberOfSWEs);
      *dataBufPtr++ = CDC_GETLOBYTE((uint16)tmpNumberOfSWEs);

      writtenData = (uint16)5u;
   }
   else
   {
      writtenData = (uint16)0u;
   }

   iLoop = iLoopStart;

   pCurrentStartAddress   = &sharedBootROMData.MemSegTable[iLoop][0];
   pCurrentEndAddress     = &sharedBootROMData.MemSegTable[iLoop][1];
   currentSize            = *pCurrentEndAddress   -
                            *pCurrentStartAddress +
                            (CDC_FLASHADDRESS_T)0x01u;
   sameSizedFlashSegments = (uint16)0x00u;

   /* write bootloader and application segmentation table to response         */
   while ( (iLoop < (uint8_least)CDC_FLASH_SEGMENT_NUMBER_ALL) && (bLeaveEarly != TRUE))
   {
      if ( (*pCurrentStartAddress == (oldEndAddress + (CDC_FLASHADDRESS_T)1)) &&
           (currentSize           == oldSize)
         )
      {
         ++sameSizedFlashSegments;

         /*
          * Go back to bytes in the response to increase the number of same
          * sized flash segments
          */
         dataBufPtr -= 2;
      }
      else
      {
         *dataBufPtr++ = CDC_GETHIHIBYTE(*pCurrentStartAddress);
         *dataBufPtr++ = CDC_GETHILOBYTE(*pCurrentStartAddress);
         *dataBufPtr++ = CDC_GETLOHIBYTE(*pCurrentStartAddress);
         *dataBufPtr++ = CDC_GETLOLOBYTE(*pCurrentStartAddress);

         *dataBufPtr++ = CDC_GETHIHIBYTE(currentSize);
         *dataBufPtr++ = CDC_GETHILOBYTE(currentSize);
         *dataBufPtr++ = CDC_GETLOHIBYTE(currentSize);
         *dataBufPtr++ = CDC_GETLOLOBYTE(currentSize);

         sameSizedFlashSegments = (uint16)0x01;
         writtenData += (uint16)10;
      }

      oldEndAddress = *pCurrentEndAddress;
      oldSize       = currentSize;

      /* number of consecutive same sized flash segments                      */
      *dataBufPtr++ = CDC_GETHIBYTE(sameSizedFlashSegments);           /* MSB */
      *dataBufPtr++ = CDC_GETLOBYTE(sameSizedFlashSegments);           /* LSB */

      iLoop++;

      if (iLoop < (uint8_least)CDC_FLASH_SEGMENT_NUMBER_ALL)
      {
         pCurrentStartAddress = &sharedBootROMData.MemSegTable[iLoop][0];
         pCurrentEndAddress   = &sharedBootROMData.MemSegTable[iLoop][1];
         currentSize          = *pCurrentEndAddress   -
                                *pCurrentStartAddress +
                                (CDC_FLASHADDRESS_T)0x01;
      }

#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
      /* fit the next data into the buffer or are all data written ?          */
      if ( ( dataLen != (uint16)RESPONSE_FIT_INTO_BUFFER ) &&
                                                  /* paged processing is used */
           (
             (
               ((writtenData + (uint16)10) > dataLen) &&
               (
                  (*pCurrentStartAddress != (oldEndAddress + (CDC_FLASHADDRESS_T)1))
                  ||
                  (currentSize           != oldSize)
               )
             ) ||
             (iLoop == (uint8_least)CDC_FLASH_SEGMENT_NUMBER_ALL)
           )
         )
      {
         /* this code is only reached if paged buffer processing is used      */
         /* page buffer is full -> send page to DCM                           */
         Dcm_ProcessPage(writtenData);

         bLeaveEarly = TRUE;
      }
#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */
   }

   if ( iLoop == (uint8_least)CDC_FLASH_SEGMENT_NUMBER_ALL )
   {
      /* reset iLoopStart for the next execution of this diagnostic service   */
      iLoopStart = (uint8_least)0;
   }
   else
   {
      /* save the actual iLoop value to continue on next function call        */
      iLoopStart = iLoop;
   }
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_PROCESSREADMEMORYSEGMANTATIONTABLE_CALLED, TEST_CDC_RESPONSE_CODE_NOT_USED, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */        
} /* end of function 'Cdc_ProcessReadMemorySegmentationTable'                 */


#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_ProcessReadSVK                                         **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F102_SVK_SYSTEM_SUPPLIER / DIAG_DID_F103_SVK_PLANT**
**                 Read the system supplier or plant SVK                      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : dataBufPtr - Pointer for memory segmentation table data    **
**                                                                            **
**                 dataLen - max. length of the writeable data                **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
FUNC(void, CDC_CODE) Cdc_ProcessReadSVK
(
   Dcm_MsgType dataBufPtr,
   Dcm_MsgLenType dataLen
)
{
   /* only at first call of this function do ...                              */
   if ( iLoopStart == (uint8_least)0 )
   {
      /*
       * at first call the first 2 bytes of the buffer are the service data-id
       */
      dataBufPtr += 2;
      dataLen -= 2;
   }

   /* copy only the valid data in the buffer - correct dataLen                */
   if ( gSVKLength < dataLen )
   {
      dataLen = gSVKLength;
   }
   /* Function returns always the first parameter
     so the return value can be ignored */
  (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) dataBufPtr,
                           (P2CONST(void, AUTOMATIC, CDC_FAR_CONST)) gpSvk,
                           dataLen
                         );

   /* only at first call of this function do ...                              */
   if ( iLoopStart == (uint8_least)0 )
   {
      /* page buffer is full -> send page to DCM                              */
      Dcm_ProcessPage(dataLen + 2);
   }
   else
   {
      /* page buffer is full -> send page to DCM                              */
      Dcm_ProcessPage(dataLen);
   }

   /* increase data pointer for the next function call                        */
   gpSvk += dataLen;
   gSVKLength -= dataLen;

   /* are all data written?                                                   */
   if (gSVKLength == 0)
   {
      /*
       * reset loop counter, to reserve the first 2 bytes at next function call
       */
      iLoopStart = (uint8_least)0;
   }
   else
   {
      /* increase call counter                                                */
      iLoopStart++;
   }
   
#if (CDC_MODULETEST_ENABLED == STD_ON)
    /* Return response code to TEST application */
    TEST_CBFCdcModulTestRetVal(TEST_CDC_PROCESSREADSVK_CALLED, TEST_CDC_RESPONSE_CODE_NOT_USED, TEST_CDC_RETVAL_NOT_USED);
#endif /* (CDC_MODULETEST_ENABLED == STD_ON ) */     
} /* end of function 'Cdc_ProcessReadSVK'                                     */
#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                                 */


#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_CancelPagedBufferProcessing                            **
**                                                                            **
** DESCRIPTION   : Error function for the paged buffer processing             **
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
FUNC(void, CDC_CODE) Cdc_CancelPagedBufferProcessing(void)
{
   /*
    * reset static loop and step variables for the next execution of a
    * diagnostic service with paged processing
    */
   iLoopStart = (uint8_least)0;
   iStep      = (uint8_least)0;
} /* end of function 'Cdc_CancelPagedBufferProcessing'                        */
#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                                 */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_GetSeed                                                **
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
FUNC(void, CDC_CODE) Cdc_GetSeed
(
   uint8 SecurityLevel,
   uint8 SeedLen,
   CONSTP2VAR(uint8,AUTOMATIC,CDC_VAR_DCMDATA) Seed
)
{
   #if ( (CDC_CRYPTO_ENABLE == STD_ON) && (CDC_STANDARD_CORE_TEST == STD_ON) )
      /*
       * use constant buffer for SC test. Almost the same seed for
       * security access in programming/coding session are send
       */
      static const uint8 ConstSeed[8] =
      {
         0xA2u,0x0Au,0x1Bu,0xFFu,0x93u,0xEBu,0x8Eu,0x1Bu
      };
   #endif

   /* Copy TesterId from incoming diagnostic buffer to 'SecurityAccessParams' */
   /* Function returns always the first parameter
     so the return value can be ignored */
   (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA))   &SecurityAccessParams.TesterId[0],
                            (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) &Seed[0],
                            DCM_SECURITYACCESSRECORDLENGTH
                          );

   if (SeedLen > (uint8)sizeof(SecurityAccessParams.PendingSeed))
   {
      /* exception handling can not be done with this AUTOSAR DCM version!    */
      SeedLen = (uint8)sizeof(SecurityAccessParams.PendingSeed);
   }

   #if (CDC_CRYPTO_ENABLE == STD_ON)
      #if (CDC_STANDARD_CORE_TEST == STD_ON)
         /* Copy the random number to DCM buffers                             */
         /* Function returns always the first parameter
           so the return value can be ignored */
         (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA))   &SecurityAccessParams.PendingSeed[0],
                                  (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) &ConstSeed[0],
                                  SeedLen
                                );

         /* Function returns always the first parameter
           so the return value can be ignored */
         (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA))   &Seed[0],
                                  (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) &ConstSeed[0],
                                  SeedLen
                                );
      #else
         /* Copy initial value for random number generator from               */
         /* 'BootProgData.RANDOM' to 'CR_C_S2'.                               */
         /* XOR the initial value with another "random" value                 */
         CR_C_s2.reg_a[0] = BootProgData.RANDOM.reg_a[0] ^
                                             CDC_FREETIMER_CREATERANDOMNUMBER();
         CR_C_s2.reg_a[1] = BootProgData.RANDOM.reg_a[1] ^
                                             CDC_FREETIMER_CREATERANDOMNUMBER();
         CR_C_s2.reg_b[0] = BootProgData.RANDOM.reg_b[0] ^
                                             CDC_FREETIMER_CREATERANDOMNUMBER();
         CR_C_s2.reg_b[1] = BootProgData.RANDOM.reg_b[1] ^
                                             CDC_FREETIMER_CREATERANDOMNUMBER();

         /* Generate random number to buffer 'SecurityAccessParams.SeedOrKey' */
         CDC_CRYPTO_MAKECHALLKEY ( (uint32)         SeedLen,
                                   (CDC_CR_FP_UINT8)&SecurityAccessParams.PendingSeed[0]
                                 );

         /* Copy the random number to DCM buffer                              */
         /* Function returns always the first parameter
           so the return value can be ignored */
         (void)CDC_SC_MEMCPY_ROM( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA))   &Seed[0],
                                  (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) &SecurityAccessParams.PendingSeed[0],
                                  SeedLen
                                );

         /*
          * Save new initial value for the random number generator to
          * 'BootProgData.RANDOM'. It will be used for the generation of the
          * next random number.
          */
         BootProgData.RANDOM.reg_a[0] = CR_C_s2.reg_a[0];
         BootProgData.RANDOM.reg_a[1] = CR_C_s2.reg_a[1];
         BootProgData.RANDOM.reg_b[0] = CR_C_s2.reg_b[0];
         BootProgData.RANDOM.reg_b[1] = CR_C_s2.reg_b[1];

         #if (CdcScenarioBootloader == STD_ON)
            /* write to nv memory                                             */
            /* Return value is ignored because no error/retry handling is provided in this case */
            (void)CDC_OPERATENVDATA( CDC_NVM_BLOCK_BOOT_PROG_DATA, CDC_NV_WRITE_OPERATION);
         #else
            NvM_SetBlockProtection(CDC_NVM_BLOCK_BOOT_PROG_DATA, FALSE);
            /* Return value is ignored because no error/retry handling is provided in this case */
            (void)NvM_WriteBlock(CDC_NVM_BLOCK_BOOT_PROG_DATA, NULL_PTR);
            /* wait until NvM is ready for last NvM job                       */
            CDC_WAITNVMREADY(CDC_NVM_BLOCK_BOOT_PROG_DATA);
            NvM_SetBlockProtection(CDC_NVM_BLOCK_BOOT_PROG_DATA, TRUE);
         #endif /* (CdcScenarioBootloader == STD_ON)                          */

      #endif /* CDC_STANDARD_CORE_TEST == STD_ON                              */
   #endif /* CDC_CRYPTO_ENABLE == STD_ON                                      */

} /* end of function 'Cdc_GetSeed'                                            */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Cdc_CompareKey                                             **
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
/* ---------------------------------------- NXTR PATCH START ----------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Updated the Keylen because of increase in signature key size from 1024-bit to 2048-bit
 */
 #if 0
/* Original code - START */
FUNC(Dcm_StatusType, CDC_CODE) Cdc_CompareKey
(
   uint8 SecurityLevel,
   uint8 KeyLen,
   CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
)
/* Original code - END */
#endif
/* Patch code  - START */
FUNC(Dcm_StatusType, CDC_CODE) Cdc_CompareKey
(
   uint8 SecurityLevel,
   uint16 KeyLen,
   CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
)
/* Patch code  - END */
/* --------------------------------------- NXTR PATCH END --------------------------------------------*/
{
   Dcm_StatusType retVal;

   #if (CDC_CRYPTO_ENABLE == STD_ON)
      #if defined CDC_CRYPTO_AUTH_ASYM
         #if ((SG_KEY_LEN % 0x04u) != 0x00u)
            #error "Cdc_Dispatcher.c: 'SG_KEY_LEN' must be a multiple of '4'"
         #endif
         /* encoded random value in longs                                     */
         static uint32 sgkey[SG_KEY_LEN / sizeof(uint32)];
      #endif

      CDC_CR_C_RC_T    res;            /* authentication check response       */

      if (KeyLen != SG_KEY_LEN)
      {
         /* report authentication failure to DCM                              */
         retVal = DCM_E_COMPARE_KEY_FAILED;
      }
      else
      {
         #ifdef CDC_CRYPTO_AUTH_SYM
            /* symmetric authentication                                       */
            res = CDC_CRYPTO_CHECKAUTHUSTGSYMM
            (
               /* seed for check.                                             */
               (CDC_CR_FP_UINT8) &SecurityAccessParams.PendingSeed[0],
               /* tester Id                                                   */
               (CDC_CR_FP_UINT8) &SecurityAccessParams.TesterId[0],
               /* BOOTLOGISTICIDENTIFIERDATA                                  */
               (CDC_CR_FPC_UINT8)&SweBootTable.SgbmId[1],
               /* auth level                                                  */
               (uint32)          CDC_AUTH_LEVEL,
               /* response                                                    */
               (CDC_CR_FPC_UINT8)&Key[0]
            );

         #elif defined CDC_CRYPTO_AUTH_ASYM
            /*
             * Copy key length and encrypted challenge from incoming diagnostic
             * buffer to array 'sgkey'
             */
            #if (DIAG_ENDIANESS_FITS == STD_ON)
               /* Function returns always the first parameter
                 so the return value can be ignored */
               (void)CDC_SC_MEMCPY( (P2VAR(void, AUTOMATIC, CDC_FAR_DATA)) sgkey,
                                    (P2CONST(void, AUTOMATIC, CDC_FAR_DATA)) Key,
                                    SG_KEY_LEN
                                  );
            #else /* copy manually                                            */
               uint8_least iLoop;           /* temporary loop variable        */
               for ( iLoop = (uint8_least)0;
                     iLoop < (uint8_least)SG_KEY_LEN;
                     iLoop+= (uint8_least)4
                   )
               {
                  sgkey[iLoop >> (uint8_least)2] = CDC_MAKE32BIT
                                                  ( Key[iLoop + (uint8_least)0],
                                                    Key[iLoop + (uint8_least)1],
                                                    Key[iLoop + (uint8_least)2],
                                                    Key[iLoop + (uint8_least)3]
                                                  );
               }
            #endif

            /* asymmetric authentication                                      */
            res = CDC_CRYPTO_CHECKAUTHUSTG
            (
               /* challenge                                                   */
               (CDC_CR_FP_UINT8)  &SecurityAccessParams.PendingSeed[0],
               /* tester Id                                                   */
               (CDC_CR_FP_UINT8)  &SecurityAccessParams.TesterId[0],
               /* BOOTLOGISTICIDENTIFIERDATA                                  */
               (CDC_CR_FPC_UINT8) &SweBootTable.SgbmId[1],
               /* interrupt cycles                                            */
               (uint16)           0,
               /* auth level                                                  */
               (uint32)           CDD_CdcAuthLevel_Cnt_G_u8,		/* Nxtr Patch -- Added 09/30/12, KJS: Removed CDC_AUTH_LEVEL and replaced it with CDD_CdcAuthLevel_Cnt_G_u8 defined in CDD_Data */
               /* response                                                    */
               (CDC_CR_FPC_UINT32)&sgkey[0],
               /* state buffer                                                */
               (CDC_CR_FP_UINT8)  NULL_PTR
            );

         #else
            #error "Cdc_Dispatcher.c: No crypto method defined."
            #error "Define 'CDC_CRYPTO_AUTH_ASYM' or 'CDC_CRYPTO_AUTH_SYM'."
         #endif

         /* if authentication successful                                      */
         if (res == CDC_CR_C_RC_OK)
         {
            /* Authentication succeeded                                       */
            #if (CdcScenarioBootloader == STD_ON)
               /* store new programming status                                */
               activeSubSession = PROG_BOOT_UNLOCKED;
            #endif
            /* report successful authentication to DCM                        */
            retVal = DCM_E_OK;
         }
         else
         {
            /* report authentication failure to DCM                           */
            retVal = DCM_E_COMPARE_KEY_FAILED;
         }
      } /* if (KeyLen != SG_KEY_LEN)                                          */

   #else /* CDC_CRYPTO_ENABLE == STD_ON                                       */
      #if (CdcScenarioBootloader == STD_ON)
         /* store new programming status                                      */
         activeSubSession = PROG_BOOT_UNLOCKED;
      #endif
      /* if crypto is disabled the authentication always passes               */
      retVal = DCM_E_OK;
   #endif /* CDC_CRYPTO_ENABLE == STD_ON                                      */

   return retVal;
} /* end of function 'Cdc_CompareKey'                                         */

#define CDC_STOP_SEC_CODE
#include <MemMap.h>

/*** End of file **************************************************************/
