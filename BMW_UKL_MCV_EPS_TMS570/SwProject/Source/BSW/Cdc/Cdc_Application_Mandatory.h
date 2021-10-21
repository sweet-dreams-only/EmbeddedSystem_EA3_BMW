/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Cdc_Application_Mandatory.h                                   **
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
** gema         Markus Gerngross           MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.3 : 27.10.2011, anam: CR71144: Cdc: Redeclaration of function 
 *                            Cdc_ReadDataByIdentifierKilometer and 
 *                            Cdc_ReadDataByIdentifierRelativeTime
 * V1.0.2 : 13.01.2010, gema: CR70390: Compiler switches shall have defined values
 *                            CR70381: Sizecheck at ClearDTCSecondaryMemory
 * V1.0.1 : 25.06.2009, dabu: CR70223: Implementation of Cdc review results
 * V1.0.0 : 08.08.2008, dabu: BSCCDC-25: changed Application Extended Session
 *                            handling according LH FP part 5 v09
 *          26.11.2007, dabu: ported from SC6.7.2 DiagServices package
 *                            version V4.0.1 from 2007-11-06
 */

#ifndef CDC_APPLICATION_MANDATORY_H
#define CDC_APPLICATION_MANDATORY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Cdc_Cfg.h>                /* module configuration h-file            */
/* -------------------------------------------------------------------------- */
#include <Dcm.h>                    /* DCM API                                */
/* -------------------------------------------------------------------------- */
#include <Dem.h>                    /* definitions of symbols used in Dem
                                     * callback functionsDataId               */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * File version information
 */
#define CDC_APPLICATION_MANDATORY_H_MAJOR_VERSION        1u
#define CDC_APPLICATION_MANDATORY_H_MINOR_VERSION        1u
#define CDC_APPLICATION_MANDATORY_H_PATCH_VERSION        3u

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CDC_START_SEC_VAR_8BIT
#include <MemMap.h>

   /* store the actual error memory state - init in Cdc_Init()                */
   extern VAR(boolean, CDC_VAR_DCMDATA) isErrorMemoryEnabled;

#define CDC_STOP_SEC_VAR_8BIT
#include <MemMap.h>

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define CDC_START_SEC_CODE
#include <MemMap.h>

   extern FUNC(void, CDC_CODE) Cdc_RoutineControlCheckProgrammingPreConditions
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
            );

   extern FUNC(void, CDC_CODE) Cdc_ConfirmationECUReset
            (
               CONST(uint8,AUTOMATIC) pendingSubFunction
            );

   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierTestStamp
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierVsmOperationMode
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierVsmExtendedOperationMode
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierKilometer
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierRelativeTime
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDarhDTC
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierSGBDIndex
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierScModuleVersions
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDtcsOfSecondaryErrMem
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDtcRange
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONST(uint16,AUTOMATIC) pendingDataIdentifier,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
            );
   extern FUNC(void, CDC_CODE) Cdc_PostProcessReadDataByIdentifier
            (
               CONST(uint16,AUTOMATIC) pendingDataIdentifier,
               Dcm_ConfirmationStatusType status
            );

#if (CDC_DM_TEST == STD_ON)
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDMDebugIsDtcActiveResponse
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
            );
   extern FUNC(void, CDC_CODE) Cdc_ReadDataByIdentifierDMDebugIsDtcLockable
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
            );
#endif /* (CDC_DM_TEST == STD_ON) */

   extern FUNC(void, CDC_CODE) Cdc_WriteDataByIdentifierTestStamp
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
            );

   extern FUNC(void, CDC_CODE) Cdc_ConfirmationRoutineControl
            (
               CONST(uint16,AUTOMATIC) pendingRoutineIdentifier
            );
#if (CDC_STANDARD_CORE_TEST == STD_ON)
   extern FUNC(void, CDC_CODE) Cdc_RoutineControlWatchdogTriggerStop
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
#endif /* (CDC_STANDARD_CORE_TEST == STD_ON) */
   extern FUNC(void, CDC_CODE) Cdc_RoutineControlDiagCommLoopback
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
            );
#if (CDC_DM_TEST == STD_ON)
   extern FUNC(void, CDC_CODE) Cdc_RoutineControlDmTest
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode

            );
#endif /* (CDC_DM_TEST == STD_ON) */
   extern FUNC(void, CDC_CODE) Cdc_RoutineControlClearDtcSecondaryMemory
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
            );
   extern FUNC(void, CDC_CODE) Cdc_RoutineControlSetVsmOperationMode
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
            );
   extern FUNC(void, CDC_CODE) Cdc_RoutineControlSetVsmExtendedOperationMode
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
            );

   #if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
   #if (CDC_DM_TEST == STD_ON)
   extern FUNC(void, CDC_CODE) Cdc_UpdatePageRdbiDMDebug
            (
               Dcm_MsgType dataPtr,
               Dcm_MsgLenType dataLen
            );
   #endif /* (CDC_DM_TEST == STD_ON) */
   #endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                              */

#if (CdcUseRte != STD_ON)
   extern FUNC(Std_ReturnType, DEM_PUBLIC_CODE) Cdc_DemClearEventAllowedRunnable
            (
               P2VAR(boolean, AUTOMATIC, RTE_CDC_APPL_VAR) Allowed
            );
   extern FUNC(Std_ReturnType, DEM_PUBLIC_CODE) Cdc_DemClearEventAllowed
            (
               Dem_EventIdType EventId,
               P2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) Allowed
            );
   extern FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetDataValueByDataId
            (
               uint16 DataID,
               P2VAR(uint8, AUTOMATIC, RTE_CDC_APPL_VAR) DemDataValueByDataIdBuffer
            );
   extern FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetExtendedDataRecord
            (
               uint8 ExtendedDataRecordNumber,
               P2VAR(uint8, AUTOMATIC, RTE_CDC_APPL_VAR) ExtendedDataRecord
            );
   extern FUNC(void, RTE_APPL_CODE) Cdc_ReadDataByIdentifierKilometerDummy(void);
   extern FUNC(void, RTE_APPL_CODE) Cdc_ReadDataByIdentifierRelativeTimeDummy(void);
#endif /* (CdcUseRte != STD_ON) */

#define CDC_STOP_SEC_CODE
#include <MemMap.h>

#endif  /* CDC_APPLICATION_MANDATORY_H                                        */

/*** End of file **************************************************************/
