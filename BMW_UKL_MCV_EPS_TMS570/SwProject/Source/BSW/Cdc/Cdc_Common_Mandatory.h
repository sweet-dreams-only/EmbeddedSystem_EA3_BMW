/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Cdc_Common_Mandatory.h                                        **
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
** gema         Markus Gerngross           MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.3 : 22.02.2011, muer: CR70947: Compiler warning fixed
 * V1.0.2 : 13.01.2010, gema: CR70390, Compiler switches shall have defined values
 * V1.0.1 : 25.06.2009, dabu: CR70223: Implementation of Cdc review results
 * V1.0.0 : 15.08.2008, dabu: BSCCDC-34: SecurityAccess: make Rte_DcmGetSeed()
 *                                       and Rte_DcmCompareKey() user extendable
 *          26.11.2007, dabu: ported from SC6.7.2 DiagServices package
 *                            version V4.0.1 from 2007-11-06
 */

#ifndef CDC_COMMON_MANDATORY_H
#define CDC_COMMON_MANDATORY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include <Cdc_Cfg.h>                /* module configuration h-file            */
/* -------------------------------------------------------------------------- */
#include <Dcm.h>                    /* DCM API                                */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * File version information
 */
#define CDC_COMMON_MANDATORY_H_MAJOR_VERSION        1u
#define CDC_COMMON_MANDATORY_H_MINOR_VERSION        1u
#define CDC_COMMON_MANDATORY_H_PATCH_VERSION        3u

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define CDC_START_SEC_CODE
#include <MemMap.h>

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierActiveDiagSession
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierTimingParameters
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierStandardCoreVersion
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierProgrammingCounter
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierProgrammingCounterMaxValue
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierMemorySegmentationTable
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
               CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvkCurrent
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
               CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvkSystemSupplier
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
               CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvkPlant
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
               CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSvkBackup
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               uint16 dataId,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
               CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierEcuManufacturingData
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierEcuSerialNumber
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierVin
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );

   extern FUNC(void, CDC_CODE) Cdc_RoutineControlReadDevelopmentInfo
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
            );

   extern FUNC(void, CDC_CODE) Cdc_GetCurrentSvk
            (
               Dcm_MsgType dataBufPtr,
               Dcm_MsgLenType dataLen
            );

   extern FUNC(void, CDC_CODE) Cdc_ProcessReadMemorySegmentationTable
            (
               Dcm_MsgType dataBufPtr,
               Dcm_MsgLenType dataLen
            );

   #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
   extern FUNC(void, CDC_CODE) Cdc_ProcessReadSVK
            (
               Dcm_MsgType dataBufPtr,
               Dcm_MsgLenType dataLen
            );

   extern FUNC(void, CDC_CODE) Cdc_CancelPagedBufferProcessing(void);
   #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                              */

   #if (CdcScenarioApplication == STD_ON)
   #if (DCM_ROE_ENABLED == STD_ON)
   extern FUNC(Std_ReturnType, CDC_CODE) Cdc_SetRoeSuspendedStatus
            (
               boolean isSuspended
            );
   #endif /* (DCM_ROE_ENABLED == STD_ON)                                      */
   #endif /* (CdcScenarioApplication == STD_ON)                               */

   extern FUNC(void, CDC_CODE) Cdc_GetSeed
            (
               uint8 SecurityLevel,
               uint8 SeedLen,
               CONSTP2VAR(uint8,AUTOMATIC,CDC_VAR_DCMDATA) Seed
            );

   /* ----------------------------------------- NXTR PATCH START ----------------------------------------
    * Added by: Archana Shivarudrappa
    * Date: 10/03/2016
    * Description: Updated the Keylen because of increase in signature key size from 1024-bit to 2048-bit
    */
    #if 0
   /* Original code - START */
   extern FUNC(Dcm_StatusType, CDC_CODE) Cdc_CompareKey
            (
               uint8 SecurityLevel,
               uint8 KeyLen,
               CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
            );
   /* Original code - END */
   #endif

   /* Patch code  - START */
   extern FUNC(Dcm_StatusType, CDC_CODE) Cdc_CompareKey
            (
               uint8 SecurityLevel,
               uint16 KeyLen,
               CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
            );
   /* Patch code  - END */
   /* ---------------------------------------- NXTR PATCH END --------------------------------------------*/

#define CDC_STOP_SEC_CODE
#include <MemMap.h>

#endif  /* CDC_COMMON_MANDATORY_H                                             */

/*** End of file **************************************************************/
