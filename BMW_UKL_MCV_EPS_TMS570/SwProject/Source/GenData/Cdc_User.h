/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Cdc_User.h                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : n.a.                                                          **
**                                                                            **
**  PURPOSE   : Support of DCM diagnostic services corresponding              **
**              to specification for AUTOSAR - user part                      **
**                                                                            **
**  REMARKS   : Implementation of user specific diagnostic services           **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
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
 * V1.1.3 : 22.06.2010, anam: CR70612: Configuration of UserExtension for asynchronous request handling
 * V1.1.2 : 13.04.2010, anam: CR70619: Rte_DcmConfirmation_User wrong type of status
 * V1.1.0 : 23.02.2010, gema: CR70417, CDC: Module extension to 3.0
 * V1.0.2 : 13.01.2010, gema: CR70390, Compiler switches shall have defined values
 * V1.0.1 : 25.06.2009, dabu: CR70223: Implementation of Cdc review results
 * V1.0.0 : 15.08.2008, dabu: BSCCDC-34: SecurityAccess: make Rte_DcmGetSeed()
 *                                       and Rte_DcmCompareKey() user extendable
 *          17.01.2008, dabu: initial version
 */

#ifndef CDC_USER_H
#define CDC_USER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include <Cdc_Cfg.h>                /* module configuration h-file            */
/* -------------------------------------------------------------------------- */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * File version information
 */
#define CDC_USER_H_MAJOR_VERSION        1u
#define CDC_USER_H_MINOR_VERSION        1u
#define CDC_USER_H_PATCH_VERSION        3u

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

   extern FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmECUReset_User
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
#if (CdcEnableAsyncRequestHandling == STD_OFF)
              ,CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
#endif /* (CdcEnableAsyncRequestHandling == STD_OFF) */
            );

   extern FUNC(Std_ReturnType, CDC_CODE) Cdc_ConfirmationECUReset_User
            (
               CONST(uint8,AUTOMATIC) pendingSubFunction
            );

   extern FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmReadDataByIdentifier_User
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
#if (CdcEnableAsyncRequestHandling == STD_OFF)
               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode,
#endif /* (CdcEnableAsyncRequestHandling == STD_OFF) */
#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
               CONSTP2VAR(Rte_DcmUpdatePageType, AUTOMATIC, CDC_VAR_DCMDATA) pCurrentUpdatePage,
#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON)                                 */
               CONSTP2VAR(boolean, AUTOMATIC, CDC_VAR_DCMDATA) isPagedProcessingExecuted
            );

   extern FUNC(Std_ReturnType, CDC_CODE) Cdc_PostProcessReadDataByIdentifier_User
            (
               CONST(uint16,AUTOMATIC) pendingDataIdentifier,
               Dcm_ConfirmationStatusType status
            );

   extern FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmWriteDataByIdentifier_User
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
   #if (CdcEnableAsyncRequestHandling == STD_OFF)
               ,CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
   #endif /* (CdcEnableAsyncRequestHandling == STD_OFF) */
            );

   extern FUNC(Std_ReturnType, CDC_PUBLIC_DCMCODE) Rte_DcmRoutineControl_User
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
   #if (CdcEnableAsyncRequestHandling == STD_OFF)
              ,CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDC_VAR_DCMDATA) ResponseCode
   #endif /* (CdcEnableAsyncRequestHandling == STD_OFF) */
            );

   extern FUNC(Std_ReturnType, CDC_CODE) Cdc_ConfirmationRoutineControl_User
            (
               CONST(uint16,AUTOMATIC) pendingRoutineIdentifier
            );
   extern FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmGetSesChgPermission_User
            (
               CONST(uint8,AUTOMATIC)  SesCtrlTypeActive,
               CONST(uint8,AUTOMATIC)  SesCtrlTypeNew,
               CONSTP2VAR(Dcm_StatusType, AUTOMATIC, CDC_VAR_DCMDATA) dcmSessionChangePermission
            );

   extern FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmSesCtrlChangeIndication_User
            (
               CONST(uint8,AUTOMATIC) SesCtrlTypeOld,
               CONST(uint8,AUTOMATIC) SesCtrlTypeNew
            );

   extern FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmIndication_User
            (
               CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
               CONST(uint8,AUTOMATIC)  SID,
               CONSTP2VAR(Dcm_StatusType, AUTOMATIC, CDC_VAR_DCMDATA) returnValue
            );

   extern FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmConfirmation_User
            (
               Dcm_ConfirmationStatusType idContext,
               PduIdType dcmRxPduId,
               Dcm_StatusType status
            );

   extern FUNC(void, CDC_PUBLIC_DCMCODE) Rte_DcmGetSeed_User
            (
               uint8 SecurityLevel,
               uint8 SeedLen,
               CONSTP2VAR(uint8,AUTOMATIC,CDC_VAR_DCMDATA) Seed
            );

   extern FUNC(Dcm_StatusType, CDC_PUBLIC_DCMCODE) Rte_DcmCompareKey_User
            (
               uint8 SecurityLevel,
               uint8 KeyLen,
               CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
            );

   extern FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetDataValueByDataId_User
            (
               uint16 DataID,
               P2VAR(uint8, AUTOMATIC, CDC_VAR_DCMDATA) DemDataValueByDataIdBuffer
            );

   extern FUNC(Std_ReturnType, RTE_APPL_CODE) Cdc_DemGetExtendedDataRecord_User
            (
               uint8 ExtendedDataRecordNumber,
               P2VAR(uint8, AUTOMATIC, CDC_VAR_DCMDATA) ExtendedDataRecord
            );

#define CDC_STOP_SEC_CODE
#include <MemMap.h>


#endif  /* CDC_USER_H                                                         */

/*** End of file **************************************************************/
