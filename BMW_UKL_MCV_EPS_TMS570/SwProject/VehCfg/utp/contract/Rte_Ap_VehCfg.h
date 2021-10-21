/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_VehCfg.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/VehCfg/autosar
 *     SW-C Type:  Ap_VehCfg
 *  Generated at:  Fri Apr 28 13:56:30 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_VehCfg> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_VEHCFG_H
# define _RTE_AP_VEHCFG_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Ap_VehCfg, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CADASIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CASSISTMSA_Cnt_lgc (FALSE)
# define Rte_InitValue_CBATCURLIMITCURRENT_Amp_f32 (0.0F)
# define Rte_InitValue_CDISPCCDRDY02_Cnt_u08 (1U)
# define Rte_InitValue_CDRVDYNMSG_Cnt_lgc (FALSE)
# define Rte_InitValue_CEFANMSG_Cnt_lgc (FALSE)
# define Rte_InitValue_CEPSPWRMAX_Cnt_lgc (TRUE)
# define Rte_InitValue_CERRMVOLTFALLBACK_Cnt_lgc (FALSE)
# define Rte_InitValue_CEVIIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CFACTORIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CFRCOMPIF_Cnt_lgc (TRUE)
# define Rte_InitValue_CHWACORRECTION_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWANGLEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWTORQUEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CMTTORQUEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CPLCOMPIF_Cnt_lgc (TRUE)
# define Rte_InitValue_CSELRETURN_Cnt_lgc (FALSE)
# define Rte_InitValue_CSELTUNINGBASE_Cnt_u08 (0U)
# define Rte_InitValue_CSELTUNINGSPORT_Cnt_u08 (0U)
# define Rte_InitValue_CSELTUNINGSVT_Cnt_u08 (0U)
# define Rte_InitValue_CVEHSPDCURLIMITCURRENT_Amp_f32 (0.0F)
# define Rte_InitValue_CVEHSPDCURLIMITER_Cnt_lgc (FALSE)
# define Rte_InitValue_CVEHSPDCURLIMITSPEED_Kph_f32 (0.0F)
# define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
# define Rte_InitValue_DesiredTunSet_Cnt_u16 (0U)
# define Rte_InitValue_EnergyModeState_Cnt_enum (0U)
# define Rte_InitValue_NxtrMEC_Cnt_enum (0U)
# define Rte_InitValue_PrkAssistState_Cnt_u08 (128U)
# define Rte_InitValue_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP (3U)
# define Rte_InitValue_TxDebugMsgEn_Cnt_lgc (FALSE)
# define Rte_InitValue_VINValid_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CADASIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CASSISTMSA_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CBATCURLIMITCURRENT_Amp_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CDISPCCDRDY02_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CDRVDYNMSG_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CEFANMSG_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CEPSPWRMAX_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CEVIIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CFACTORIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CFRCOMPIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CHWACORRECTION_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CHWANGLEIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CHWTORQUEIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CMTTORQUEIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CPLCOMPIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CSELRETURN_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CSELTUNINGBASE_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CSELTUNINGSPORT_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CSELTUNINGSVT_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_TxDebugMsgEn_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_VehCfg_Block_Request(Coding_BlockIdType blockId);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_VehCfg_NvM_PrevTuningSel_ReadBlock(P2VAR(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_VehCfg_NvM_PrevTuningSel_ReadBlock(P2VAR(NvM_DestPtr, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) DstPtr);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_VehCfg_NvM_PrevTuningSel_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_VehCfg_NvM_PrevTuningSel_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_VehCfg_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_VehCfg_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_VehCfg_Init1_DesiredTunPers_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_VehCfg->VehCfg_Init1_DesiredTunPers_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_VehCfg_Init1_DesiredTunPers_Cnt_u16() \
  (&Rte_Inst_Ap_VehCfg->VehCfg_Init1_DesiredTunPers_Cnt_u16->value)

# define Rte_IWrite_VehCfg_Init1_DesiredTunSet_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_VehCfg->VehCfg_Init1_DesiredTunSet_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_VehCfg_Init1_DesiredTunSet_Cnt_u16() \
  (&Rte_Inst_Ap_VehCfg->VehCfg_Init1_DesiredTunSet_Cnt_u16->value)

# define Rte_IRead_VehCfg_Per1_NxtrMEC_Cnt_enum() \
  (Rte_Inst_Ap_VehCfg->VehCfg_Per1_NxtrMEC_Cnt_enum->value)

# define Rte_IRead_VehCfg_Per1_PrkAssistState_Cnt_u08() \
  (Rte_Inst_Ap_VehCfg->VehCfg_Per1_PrkAssistState_Cnt_u08->value)

# define Rte_IRead_VehCfg_Per1_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP() \
  (Rte_Inst_Ap_VehCfg->VehCfg_Per1_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP->value)

# define Rte_IRead_VehCfg_Per1_VINValid_Cnt_lgc() \
  (Rte_Inst_Ap_VehCfg->VehCfg_Per1_VINValid_Cnt_lgc->value)

# define Rte_IWrite_VehCfg_Per1_DesiredTunPers_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_VehCfg->VehCfg_Per1_DesiredTunPers_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_VehCfg_Per1_DesiredTunPers_Cnt_u16() \
  (&Rte_Inst_Ap_VehCfg->VehCfg_Per1_DesiredTunPers_Cnt_u16->value)

# define Rte_IWrite_VehCfg_Per1_DesiredTunSet_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_VehCfg->VehCfg_Per1_DesiredTunSet_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_VehCfg_Per1_DesiredTunSet_Cnt_u16() \
  (&Rte_Inst_Ap_VehCfg->VehCfg_Per1_DesiredTunSet_Cnt_u16->value)

# define Rte_IWrite_VehCfg_Per1_EnergyModeState_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_VehCfg->VehCfg_Per1_EnergyModeState_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_VehCfg_Per1_EnergyModeState_Cnt_enum() \
  (&Rte_Inst_Ap_VehCfg->VehCfg_Per1_EnergyModeState_Cnt_enum->value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_CADASIF_Cnt_lgc Rte_Write_Ap_VehCfg_CADASIF_Cnt_lgc
# define Rte_Write_CASSISTMSA_Cnt_lgc Rte_Write_Ap_VehCfg_CASSISTMSA_Cnt_lgc
# define Rte_Write_CBATCURLIMITCURRENT_Amp_f32 Rte_Write_Ap_VehCfg_CBATCURLIMITCURRENT_Amp_f32
# define Rte_Write_CDISPCCDRDY02_Cnt_u08 Rte_Write_Ap_VehCfg_CDISPCCDRDY02_Cnt_u08
# define Rte_Write_CDRVDYNMSG_Cnt_lgc Rte_Write_Ap_VehCfg_CDRVDYNMSG_Cnt_lgc
# define Rte_Write_CEFANMSG_Cnt_lgc Rte_Write_Ap_VehCfg_CEFANMSG_Cnt_lgc
# define Rte_Write_CEPSPWRMAX_Cnt_lgc Rte_Write_Ap_VehCfg_CEPSPWRMAX_Cnt_lgc
# define Rte_Write_CERRMVOLTFALLBACK_Cnt_lgc Rte_Write_Ap_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc
# define Rte_Write_CEVIIF_Cnt_lgc Rte_Write_Ap_VehCfg_CEVIIF_Cnt_lgc
# define Rte_Write_CFACTORIF_Cnt_lgc Rte_Write_Ap_VehCfg_CFACTORIF_Cnt_lgc
# define Rte_Write_CFRCOMPIF_Cnt_lgc Rte_Write_Ap_VehCfg_CFRCOMPIF_Cnt_lgc
# define Rte_Write_CHWACORRECTION_Cnt_lgc Rte_Write_Ap_VehCfg_CHWACORRECTION_Cnt_lgc
# define Rte_Write_CHWANGLEIF_Cnt_lgc Rte_Write_Ap_VehCfg_CHWANGLEIF_Cnt_lgc
# define Rte_Write_CHWTORQUEIF_Cnt_lgc Rte_Write_Ap_VehCfg_CHWTORQUEIF_Cnt_lgc
# define Rte_Write_CMTTORQUEIF_Cnt_lgc Rte_Write_Ap_VehCfg_CMTTORQUEIF_Cnt_lgc
# define Rte_Write_CPLCOMPIF_Cnt_lgc Rte_Write_Ap_VehCfg_CPLCOMPIF_Cnt_lgc
# define Rte_Write_CSELRETURN_Cnt_lgc Rte_Write_Ap_VehCfg_CSELRETURN_Cnt_lgc
# define Rte_Write_CSELTUNINGBASE_Cnt_u08 Rte_Write_Ap_VehCfg_CSELTUNINGBASE_Cnt_u08
# define Rte_Write_CSELTUNINGSPORT_Cnt_u08 Rte_Write_Ap_VehCfg_CSELTUNINGSPORT_Cnt_u08
# define Rte_Write_CSELTUNINGSVT_Cnt_u08 Rte_Write_Ap_VehCfg_CSELTUNINGSVT_Cnt_u08
# define Rte_Write_CVEHSPDCURLIMITCURRENT_Amp_f32 Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32
# define Rte_Write_CVEHSPDCURLIMITER_Cnt_lgc Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc
# define Rte_Write_CVEHSPDCURLIMITSPEED_Kph_f32 Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32
# define Rte_Write_TxDebugMsgEn_Cnt_lgc Rte_Write_Ap_VehCfg_TxDebugMsgEn_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_Block_Request Rte_Call_Ap_VehCfg_Block_Request
# define Rte_Call_NvM_PrevTuningSel_ReadBlock Rte_Call_Ap_VehCfg_NvM_PrevTuningSel_ReadBlock
# define Rte_Call_NvM_PrevTuningSel_WriteBlock Rte_Call_Ap_VehCfg_NvM_PrevTuningSel_WriteBlock
# define Rte_Call_NxtrDiagMgr_GetNTCStatus Rte_Call_Ap_VehCfg_NxtrDiagMgr_GetNTCStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_VehCfg_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/
typedef Rte_PimType_Ap_VehCfg_TuningSelectParam TuningSelectParam;

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PrevVldTuningSel() (Rte_Inst_Ap_VehCfg->Pim_PrevVldTuningSel)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   TuningSelectParam *Rte_Pim_PrevVldTuningSel(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_VEHCFG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkBlockValid_Check
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Check> of PortPrototype <CbkBlockValid>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void CbkBlockValid_Check(Coding_BlockIdType blockId, const UInt8 *blockData, UInt8 blockSize, Coding_ErrorType *error)
# else
 *   void CbkBlockValid_Check(Coding_BlockIdType blockId, const Coding_BlockDataType *blockData, UInt8 blockSize, Coding_ErrorType *error)
# endif
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlockValid_Check(Coding_BlockIdType blockId, P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);
# else
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlockValid_Check(Coding_BlockIdType blockId, P2CONST(Coding_BlockDataType, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkBlock_Receive
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Receive> of PortPrototype <CbkBlock>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CADASIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CASSISTMSA_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CBATCURLIMITCURRENT_Amp_f32(Float data)
 *   Std_ReturnType Rte_Write_CDISPCCDRDY02_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CDRVDYNMSG_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CEFANMSG_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CEPSPWRMAX_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CERRMVOLTFALLBACK_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CEVIIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CFACTORIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CFRCOMPIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CHWACORRECTION_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CHWANGLEIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CHWTORQUEIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CMTTORQUEIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CPLCOMPIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CSELRETURN_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CSELTUNINGBASE_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CSELTUNINGSPORT_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CSELTUNINGSVT_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CVEHSPDCURLIMITCURRENT_Amp_f32(Float data)
 *   Std_ReturnType Rte_Write_CVEHSPDCURLIMITER_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CVEHSPDCURLIMITSPEED_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_TxDebugMsgEn_Cnt_lgc(Boolean data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void CbkBlock_Receive(Coding_BlockIdType blockId, const UInt8 *blockData, UInt8 blockSize)
# else
 *   void CbkBlock_Receive(Coding_BlockIdType blockId, const Coding_BlockDataType *blockData, UInt8 blockSize)
# endif
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlock_Receive(Coding_BlockIdType blockId, P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize);
# else
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlock_Receive(Coding_BlockIdType blockId, P2CONST(Coding_BlockDataType, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkDataChange_EndNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EndNotification> of PortPrototype <CbkDataChange>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Block_Request(Coding_BlockIdType blockId)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CbkDataChange_EndNotification(Coding_DataStatusType dataStatus)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkDataChange_EndNotification(Coding_DataStatusType dataStatus);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkDataChange_StartNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <StartNotification> of PortPrototype <CbkDataChange>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CbkDataChange_StartNotification(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkDataChange_StartNotification(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkPreConditions_Check
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Check> of PortPrototype <CbkPreConditions>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CbkPreConditions_Check(Coding_ErrorType *error)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkPreConditions_Check(P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VehCfg_Init1_DesiredTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_VehCfg_Init1_DesiredTunPers_Cnt_u16(void)
 *   void Rte_IWrite_VehCfg_Init1_DesiredTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_VehCfg_Init1_DesiredTunSet_Cnt_u16(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_ReadBlock(UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_ReadBlock(NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   ManufModeType Rte_IRead_VehCfg_Per1_NxtrMEC_Cnt_enum(void)
 *   QU_SER_WSTA_EST_FTAX Rte_IRead_VehCfg_Per1_PrkAssistState_Cnt_u08(void)
 *   New_Coding_79 Rte_IRead_VehCfg_Per1_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(void)
 *   Boolean Rte_IRead_VehCfg_Per1_VINValid_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VehCfg_Per1_DesiredTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_VehCfg_Per1_DesiredTunPers_Cnt_u16(void)
 *   void Rte_IWrite_VehCfg_Per1_DesiredTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_VehCfg_Per1_DesiredTunSet_Cnt_u16(void)
 *   void Rte_IWrite_VehCfg_Per1_EnergyModeState_Cnt_enum(EnergyModeStateType data)
 *   EnergyModeStateType *Rte_IWriteRef_VehCfg_Per1_EnergyModeState_Cnt_enum(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Scom_ClearRacktoVehCntrOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearRacktoVehCntrOffset> of PortPrototype <VehCfg_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void VehCfg_Scom_ClearRacktoVehCntrOffset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_ClearRacktoVehCntrOffset(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Scom_GetVariantSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetVariantSelect> of PortPrototype <VehCfg_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void VehCfg_Scom_GetVariantSelect(UInt8 *VehicleVariant_Cnt_T_u8)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_GetVariantSelect(P2VAR(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) VehicleVariant_Cnt_T_u8);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Scom_SetVariantSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetVariantSelect> of PortPrototype <VehCfg_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType VehCfg_Scom_SetVariantSelect(UInt8 VehicleVariant_Cnt_T_u8)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_VehCfg_Scom_E_VARIANT_OUTOFRANGE
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_SetVariantSelect(UInt8 VehicleVariant_Cnt_T_u8);

# define RTE_STOP_SEC_AP_VEHCFG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# define RTE_E_VehCfg_Scom_E_VARIANT_OUTOFRANGE (34U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1457412286
#    error "The magic number of the generated file <C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-MCV_UKL-F40_cz7lt6/BMW_UKL_MCV_EPS_TMS570/SwProject/VehCfg/utp/contract/Rte_Ap_VehCfg.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1457412286
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_VEHCFG_H */
