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
 *          File:  Rte_Ap_SrlComOutput2.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComOutput/autosar
 *     SW-C Type:  Ap_SrlComOutput2
 *  Generated at:  Thu Feb  2 14:05:14 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComOutput2> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT2_H
# define _RTE_AP_SRLCOMOUTPUT2_H

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

typedef P2CONST(struct Rte_CDS_Ap_SrlComOutput2, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AVLFORCGRDTxConf_Cnt_lgc (FALSE)
# define Rte_InitValue_AVLSTMOMTxConf_Cnt_lgc (FALSE)
# define Rte_InitValue_CADASMSG_Cnt_lgc (FALSE)
# define Rte_InitValue_CDISPCCEPS_Cnt_u08 (1U)
# define Rte_InitValue_CEVIIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CFACTORIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWANGLEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWTORQUEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CMTTORQUEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CustCurrLmt_Amp_f32 (166.67F)
# define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc (FALSE)
# define Rte_InitValue_DrvDynState_Cnt_u08 (128U)
# define Rte_InitValue_ElecPower_Watts_f32 (0.0F)
# define Rte_InitValue_FinHwPos_HwDeg_f32 (0.0F)
# define Rte_InitValue_FinHwPosAuth_Uls_f32 (0.0F)
# define Rte_InitValue_HaptcFbSt_Cnt_u08 (1U)
# define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_LimitPercentFiltered_Uls_f32 (0.0F)
# define Rte_InitValue_PrkAstState_Cnt_u08 (128U)
# define Rte_InitValue_RackLoad_kN_f32 (0.0F)
# define Rte_InitValue_RacktoVehCntrOffset_Cnt_u16 (4095U)
# define Rte_InitValue_RevOffsetState_Cnt_u08 (0U)
# define Rte_InitValue_SrlComHwTrqValid_Cnt_lgc (FALSE)
# define Rte_InitValue_SupplyCur_Amp_f32 (0.0F)
# define Rte_InitValue_TJAState_Cnt_enum (1U)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_CustCurrLmt_Amp_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_DrvDynState_Cnt_u08(P2VAR(QU_SER_STMOM_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_ElecPower_Watts_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_FinHwPos_HwDeg_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_FinHwPosAuth_Uls_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_HaptcFbSt_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_HwTrq_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_PrkAstState_Cnt_u08(P2VAR(QU_SER_WSTA_EST_FTAX, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_RackLoad_kN_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_SrlComHwTrqValid_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_SupplyCur_Amp_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput2_TJAState_Cnt_enum(P2VAR(TJAStateType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS(P2CONST(RT_SG_AVL_PO_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD(P2CONST(RT_SG_AVL_FORC_GRD, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(P2CONST(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS(P2CONST(SG_DISP_CC_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComDTEST_DT_EST(P2CONST(SG_DT_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComSTEST_ST_EST(P2CONST(RT_SG_ST_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComSUEPS_SU_EPS(P2CONST(RT_SG_SU_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_SrlComOutput2_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput2_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput2_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput2_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) ElapsedTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SrlComOutput2_Per1_AVLFORCGRDTxConf_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_AVLFORCGRDTxConf_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_AVLSTMOMTxConf_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_AVLSTMOMTxConf_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_CADASMSG_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_CADASMSG_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_CDISPCCEPS_Cnt_u08() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_CDISPCCEPS_Cnt_u08->value)

# define Rte_IRead_SrlComOutput2_Per1_CEVIIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_CEVIIF_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_CFACTORIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_CFACTORIF_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_CHWANGLEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_CHWANGLEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_CHWTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_CMTTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput2_Per1_LimitPercentFiltered_Uls_f32() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_LimitPercentFiltered_Uls_f32->value)

# define Rte_IRead_SrlComOutput2_Per1_RacktoVehCntrOffset_Cnt_u16() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_RacktoVehCntrOffset_Cnt_u16->value)

# define Rte_IRead_SrlComOutput2_Per1_RevOffsetState_Cnt_u08() \
  (Rte_Inst_Ap_SrlComOutput2->SrlComOutput2_Per1_RevOffsetState_Cnt_u08->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_CustCurrLmt_Amp_f32 Rte_Read_Ap_SrlComOutput2_CustCurrLmt_Amp_f32
# define Rte_Read_DrvDynState_Cnt_u08 Rte_Read_Ap_SrlComOutput2_DrvDynState_Cnt_u08
# define Rte_Read_ElecPower_Watts_f32 Rte_Read_Ap_SrlComOutput2_ElecPower_Watts_f32
# define Rte_Read_FinHwPos_HwDeg_f32 Rte_Read_Ap_SrlComOutput2_FinHwPos_HwDeg_f32
# define Rte_Read_FinHwPosAuth_Uls_f32 Rte_Read_Ap_SrlComOutput2_FinHwPosAuth_Uls_f32
# define Rte_Read_HaptcFbSt_Cnt_u08 Rte_Read_Ap_SrlComOutput2_HaptcFbSt_Cnt_u08
# define Rte_Read_HwTrq_HwNm_f32 Rte_Read_Ap_SrlComOutput2_HwTrq_HwNm_f32
# define Rte_Read_PrkAstState_Cnt_u08 Rte_Read_Ap_SrlComOutput2_PrkAstState_Cnt_u08
# define Rte_Read_RackLoad_kN_f32 Rte_Read_Ap_SrlComOutput2_RackLoad_kN_f32
# define Rte_Read_SrlComHwTrqValid_Cnt_lgc Rte_Read_Ap_SrlComOutput2_SrlComHwTrqValid_Cnt_lgc
# define Rte_Read_SupplyCur_Amp_f32 Rte_Read_Ap_SrlComOutput2_SupplyCur_Amp_f32
# define Rte_Read_TJAState_Cnt_enum Rte_Read_Ap_SrlComOutput2_TJAState_Cnt_enum


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_SrlComAVLPOEPS_AVL_PO_EPS Rte_Write_Ap_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS
# define Rte_Write_SrlComAVLSTMOM_AVL_FORC_GRD Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD
# define Rte_Write_SrlComAVLSTMOM_AVL_STMOM_DV_ACT Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT
# define Rte_Write_SrlComDISPCCEPS_DISP_CC_EPS Rte_Write_Ap_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS
# define Rte_Write_SrlComDTEST_DT_EST Rte_Write_Ap_SrlComOutput2_SrlComDTEST_DT_EST
# define Rte_Write_SrlComSTEST_ST_EST Rte_Write_Ap_SrlComOutput2_SrlComSTEST_ST_EST
# define Rte_Write_SrlComSUEPS_SU_EPS Rte_Write_Ap_SrlComOutput2_SrlComSUEPS_SU_EPS


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComOutput2_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComOutput2_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_SrlComOutput2_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_SrlComOutput2_SystemTime_DtrmnElapsedTime_mS_u16




# define RTE_START_SEC_AP_SRLCOMOUTPUT2_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput2_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DrvDynState_Cnt_u08(QU_SER_STMOM_STMOM_DV_ACT *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput2_Per1
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
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CustCurrLmt_Amp_f32(Float *data)
 *   Std_ReturnType Rte_Read_DrvDynState_Cnt_u08(QU_SER_STMOM_STMOM_DV_ACT *data)
 *   Std_ReturnType Rte_Read_ElecPower_Watts_f32(Float *data)
 *   Std_ReturnType Rte_Read_FinHwPos_HwDeg_f32(Float *data)
 *   Std_ReturnType Rte_Read_FinHwPosAuth_Uls_f32(Float *data)
 *   Std_ReturnType Rte_Read_HaptcFbSt_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HwTrq_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_PrkAstState_Cnt_u08(QU_SER_WSTA_EST_FTAX *data)
 *   Std_ReturnType Rte_Read_RackLoad_kN_f32(Float *data)
 *   Std_ReturnType Rte_Read_SrlComHwTrqValid_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SupplyCur_Amp_f32(Float *data)
 *   Std_ReturnType Rte_Read_TJAState_Cnt_enum(TJAStateType *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComOutput2_Per1_AVLFORCGRDTxConf_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_AVLSTMOMTxConf_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CADASMSG_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComOutput2_Per1_CDISPCCEPS_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CEVIIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CFACTORIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CHWANGLEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CMTTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput2_Per1_LimitPercentFiltered_Uls_f32(void)
 *   UInt16 Rte_IRead_SrlComOutput2_Per1_RacktoVehCntrOffset_Cnt_u16(void)
 *   UInt8 Rte_IRead_SrlComOutput2_Per1_RevOffsetState_Cnt_u08(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComAVLPOEPS_AVL_PO_EPS(const RT_SG_AVL_PO_EPS *data)
 *   Std_ReturnType Rte_Write_SrlComAVLSTMOM_AVL_FORC_GRD(const RT_SG_AVL_FORC_GRD *data)
 *   Std_ReturnType Rte_Write_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(const RT_SG_AVL_STMOM_DV_ACT *data)
 *   Std_ReturnType Rte_Write_SrlComDISPCCEPS_DISP_CC_EPS(const SG_DISP_CC_EPS *data)
 *   Std_ReturnType Rte_Write_SrlComDTEST_DT_EST(const SG_DT_EST *data)
 *   Std_ReturnType Rte_Write_SrlComSTEST_ST_EST(const RT_SG_ST_EST *data)
 *   Std_ReturnType Rte_Write_SrlComSUEPS_SU_EPS(const RT_SG_SU_EPS *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput2_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <DISABLE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Trns1(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT2_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1457552127
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComOutput/utp/contract/Rte_Ap_SrlComOutput2.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1457552127
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT2_H */
