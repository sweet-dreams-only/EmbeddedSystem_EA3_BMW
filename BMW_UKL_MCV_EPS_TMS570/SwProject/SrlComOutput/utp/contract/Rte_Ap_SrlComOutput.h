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
 *          File:  Rte_Ap_SrlComOutput.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComOutput/autosar
 *     SW-C Type:  Ap_SrlComOutput
 *  Generated at:  Thu May 26 03:50:30 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComOutput> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT_H
# define _RTE_AP_SRLCOMOUTPUT_H

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

typedef P2CONST(struct Rte_CDS_Ap_SrlComOutput, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AVLFORCGRDTxConf_Cnt_lgc (FALSE)
# define Rte_InitValue_AVLSTMOMTxConf_Cnt_lgc (FALSE)
# define Rte_InitValue_AVL_PO_EPS_TRGG_ENGTORQ_EPS (0U)
# define Rte_InitValue_CtrlTempFinal_DegC_f32 (0.0F)
# define Rte_InitValue_CuTempEst_DegC_f32 (0.0F)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1 (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2 (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3 (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4 (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5 (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6 (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7 (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8 (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX (0U)
# define Rte_InitValue_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX (0U)
# define Rte_InitValue_EpsOpTrq_MtrNm_f32 (0.0F)
# define Rte_InitValue_EstBattCurr_Amp_f32 (0.0F)
# define Rte_InitValue_FR_DBG_EPS_Batt (0U)
# define Rte_InitValue_FR_DBG_EPS_CtrlTemp (0U)
# define Rte_InitValue_FR_DBG_EPS_DiffTrq (0)
# define Rte_InitValue_FR_DBG_EPS_EstBattCurr (0)
# define Rte_InitValue_FR_DBG_EPS_EstCuTemp (0U)
# define Rte_InitValue_FR_DBG_EPS_EstMtrTemp (0U)
# define Rte_InitValue_FR_DBG_EPS_MtrCurr (0U)
# define Rte_InitValue_FR_DBG_EPS_MtrTrqCmd (0)
# define Rte_InitValue_FR_DBG_EPS_MtrTrqCmdLmtd (0)
# define Rte_InitValue_FR_DBG_EPS_MtrVel (0)
# define Rte_InitValue_FR_DBG_EPS_NTCNumber (0U)
# define Rte_InitValue_FR_DBG_EPS_Res_TBD (0U)
# define Rte_InitValue_FR_DBG_EPS_SWA (0)
# define Rte_InitValue_FR_DBG_EPS_SystemState (0U)
# define Rte_InitValue_FR_DBG_EPS_ThrmlLimitPerc (0U)
# define Rte_InitValue_FR_DBG_EPS_Trq1 (0U)
# define Rte_InitValue_FR_DBG_EPS_Trq2 (0U)
# define Rte_InitValue_FinHwPos_HwDeg_f32 (0.0F)
# define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS (0U)
# define Rte_InitValue_MagTempEst_DegC_f32 (0.0F)
# define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
# define Rte_InitValue_MtrTrqCmd_MtrNm_f32 (0.0F)
# define Rte_InitValue_MtrVel_MtrRadpS_f32 (0.0F)
# define Rte_InitValue_ST_DIAG_OBD_ALIVE (0U)
# define Rte_InitValue_ST_DIAG_OBD_MUX_IMME (0U)
# define Rte_InitValue_ST_DIAG_OBD_MUX_MAX (0U)
# define Rte_InitValue_T1ADC_Volt_f32 (0.0F)
# define Rte_InitValue_T2ADC_Volt_f32 (0.0F)
# define Rte_InitValue_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS (0U)
# define Rte_InitValue_ThermLimitPerc_Uls_f32 (0.0F)
# define Rte_InitValue_TxDebugMsgEn_Cnt_lgc (FALSE)
# define Rte_InitValue_Vecu_Volt_f32 (5.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_CtrlTempFinal_DegC_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_CuTempEst_DegC_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_EpsOpTrq_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_EstBattCurr_Amp_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_FinHwPos_HwDeg_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_MagTempEst_DegC_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_MtrCurrQax_Amp_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_MtrTrqCmd_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_MtrVel_MtrRadpS_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul(P2VAR(SG_ANFRAGE_DSC_Modul, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS(P2VAR(SG_ANFRAGE_SAS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW(P2VAR(SG_ANFRAGE_ZGW, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_ALIVE(P2VAR(UInt4, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_DATA(P2VAR(Edch_EventStatusIpduDataType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_MUX_IMME(P2VAR(UInt6, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_MUX_MAX(P2VAR(UInt6, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLPOEPS_AVL_PO_EPS(P2VAR(RT_SG_AVL_PO_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_FORC_GRD(P2VAR(RT_SG_AVL_FORC_GRD, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(P2VAR(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComDISPCCEPS_DISP_CC_EPS(P2VAR(SG_DISP_CC_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComDTEST_DT_EST(P2VAR(SG_DT_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComSTEST_ST_EST(P2VAR(RT_SG_ST_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComSUEPS_SU_EPS(P2VAR(RT_SG_SU_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_T1ADC_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_T2ADC_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ThermLimitPerc_Uls_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_TxDebugMsgEn_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_Vecu_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_AVL_PO_EPS_AVL_PO_EPS(P2CONST(RT_SG_AVL_PO_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_AVL_PO_EPS_TRGG_ENGTORQ_EPS(New_Coding_39 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_AVL_STMOM_AVL_FORC_GRD(P2CONST(RT_SG_AVL_FORC_GRD, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_AVL_STMOM_AVL_STMOM_DV_ACT(P2CONST(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY(ALIV_4_BIT_Unsigned_Integer data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1(DIAG_ST_OBD data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2(DIAG_ST_OBD data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3(DIAG_ST_OBD data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4(DIAG_ST_OBD data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5(DIAG_ST_OBD data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6(DIAG_ST_OBD data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7(DIAG_ST_OBD data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8(DIAG_ST_OBD data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX(ST_DIAG_OBD_MUX_IMME data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX(ST_DIAG_OBD_MUX_MAX data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DISP_CC_EPS_DISP_CC_EPS(P2CONST(SG_DISP_CC_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DT_EST_DT_EST(P2CONST(SG_DT_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Batt(BATT_VOLTS data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_CtrlTemp(CONT_TEMP_DEG data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_DiffTrq(DIFF_TRQ_NM data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstBattCurr(EST_BATT_AMPS data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstCuTemp(EST_CUTEMP_DEG data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstMtrTemp(EST_MOTTEMP_DEG data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrCurr(New_Coding_3 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmd(MTRTRQCMD_NM data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmdLmtd(MTRTRQLMTD_NM data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrVel(MOT_VEL_RADPSEC data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_NTCNumber(New_Coding_28 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Res_TBD(New_Coding_15 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_SWA(SWA_DEG data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_SystemState(SYS_STATE_ENUM data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_ThrmlLimitPerc(THRML_LIMIT_PERC data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Trq1(TORQUE1_VOLTS data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Trq2(TORQUE2_VOLTS data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS(ID_TEMP_CPO_HET_MNG data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_ST_EST_ST_EST(P2CONST(RT_SG_ST_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_SU_EPS_SU_EPS(P2CONST(RT_SG_SU_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS(TEMP_CPO_HET_MNG data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_SrlComOutput_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_EPSIndicatorStatus_GetIndicatorStatus(P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IndicatorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_EpsComMStRqst_RequestComMode(ComM_ModeType ComMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_SrlComOutput_Per1_AVLFORCGRDTxConf_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AVLFORCGRDTxConf_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_AVLFORCGRDTxConf_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AVLFORCGRDTxConf_Cnt_lgc->value)

# define Rte_IWrite_SrlComOutput_Per1_AVLSTMOMTxConf_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AVLSTMOMTxConf_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_AVLSTMOMTxConf_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AVLSTMOMTxConf_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_CtrlTempFinal_DegC_f32 Rte_Read_Ap_SrlComOutput_CtrlTempFinal_DegC_f32
# define Rte_Read_CuTempEst_DegC_f32 Rte_Read_Ap_SrlComOutput_CuTempEst_DegC_f32
# define Rte_Read_EpsOpTrq_MtrNm_f32 Rte_Read_Ap_SrlComOutput_EpsOpTrq_MtrNm_f32
# define Rte_Read_EstBattCurr_Amp_f32 Rte_Read_Ap_SrlComOutput_EstBattCurr_Amp_f32
# define Rte_Read_FinHwPos_HwDeg_f32 Rte_Read_Ap_SrlComOutput_FinHwPos_HwDeg_f32
# define Rte_Read_HwTrq_HwNm_f32 Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32
# define Rte_Read_MagTempEst_DegC_f32 Rte_Read_Ap_SrlComOutput_MagTempEst_DegC_f32
# define Rte_Read_MtrCurrQax_Amp_f32 Rte_Read_Ap_SrlComOutput_MtrCurrQax_Amp_f32
# define Rte_Read_MtrTrqCmd_MtrNm_f32 Rte_Read_Ap_SrlComOutput_MtrTrqCmd_MtrNm_f32
# define Rte_Read_MtrVel_MtrRadpS_f32 Rte_Read_Ap_SrlComOutput_MtrVel_MtrRadpS_f32
# define Rte_Read_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul
# define Rte_Read_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS
# define Rte_Read_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW
# define Rte_Read_ST_DIAG_OBD_ALIVE Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_ALIVE
# define Rte_Read_ST_DIAG_OBD_DATA Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_DATA
# define Rte_Read_ST_DIAG_OBD_MUX_IMME Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_MUX_IMME
# define Rte_Read_ST_DIAG_OBD_MUX_MAX Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_MUX_MAX
# define Rte_Read_SrlComAVLPOEPS_AVL_PO_EPS Rte_Read_Ap_SrlComOutput_SrlComAVLPOEPS_AVL_PO_EPS
# define Rte_Read_SrlComAVLSTMOM_AVL_FORC_GRD Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_FORC_GRD
# define Rte_Read_SrlComAVLSTMOM_AVL_STMOM_DV_ACT Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_STMOM_DV_ACT
# define Rte_Read_SrlComDISPCCEPS_DISP_CC_EPS Rte_Read_Ap_SrlComOutput_SrlComDISPCCEPS_DISP_CC_EPS
# define Rte_Read_SrlComDTEST_DT_EST Rte_Read_Ap_SrlComOutput_SrlComDTEST_DT_EST
# define Rte_Read_SrlComSTEST_ST_EST Rte_Read_Ap_SrlComOutput_SrlComSTEST_ST_EST
# define Rte_Read_SrlComSUEPS_SU_EPS Rte_Read_Ap_SrlComOutput_SrlComSUEPS_SU_EPS
# define Rte_Read_T1ADC_Volt_f32 Rte_Read_Ap_SrlComOutput_T1ADC_Volt_f32
# define Rte_Read_T2ADC_Volt_f32 Rte_Read_Ap_SrlComOutput_T2ADC_Volt_f32
# define Rte_Read_ThermLimitPerc_Uls_f32 Rte_Read_Ap_SrlComOutput_ThermLimitPerc_Uls_f32
# define Rte_Read_TxDebugMsgEn_Cnt_lgc Rte_Read_Ap_SrlComOutput_TxDebugMsgEn_Cnt_lgc
# define Rte_Read_Vecu_Volt_f32 Rte_Read_Ap_SrlComOutput_Vecu_Volt_f32


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_AVL_PO_EPS_AVL_PO_EPS Rte_Write_Ap_SrlComOutput_AVL_PO_EPS_AVL_PO_EPS
# define Rte_Write_AVL_PO_EPS_TRGG_ENGTORQ_EPS Rte_Write_Ap_SrlComOutput_AVL_PO_EPS_TRGG_ENGTORQ_EPS
# define Rte_Write_AVL_STMOM_AVL_FORC_GRD Rte_Write_Ap_SrlComOutput_AVL_STMOM_AVL_FORC_GRD
# define Rte_Write_AVL_STMOM_AVL_STMOM_DV_ACT Rte_Write_Ap_SrlComOutput_AVL_STMOM_AVL_STMOM_DV_ACT
# define Rte_Write_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY
# define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1
# define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2
# define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3
# define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4
# define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5
# define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6
# define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7
# define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8
# define Rte_Write_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX
# define Rte_Write_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX
# define Rte_Write_DISP_CC_EPS_DISP_CC_EPS Rte_Write_Ap_SrlComOutput_DISP_CC_EPS_DISP_CC_EPS
# define Rte_Write_DT_EST_DT_EST Rte_Write_Ap_SrlComOutput_DT_EST_DT_EST
# define Rte_Write_FR_DBG_EPS_Batt Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Batt
# define Rte_Write_FR_DBG_EPS_CtrlTemp Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_CtrlTemp
# define Rte_Write_FR_DBG_EPS_DiffTrq Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_DiffTrq
# define Rte_Write_FR_DBG_EPS_EstBattCurr Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstBattCurr
# define Rte_Write_FR_DBG_EPS_EstCuTemp Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstCuTemp
# define Rte_Write_FR_DBG_EPS_EstMtrTemp Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstMtrTemp
# define Rte_Write_FR_DBG_EPS_MtrCurr Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrCurr
# define Rte_Write_FR_DBG_EPS_MtrTrqCmd Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmd
# define Rte_Write_FR_DBG_EPS_MtrTrqCmdLmtd Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmdLmtd
# define Rte_Write_FR_DBG_EPS_MtrVel Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrVel
# define Rte_Write_FR_DBG_EPS_NTCNumber Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_NTCNumber
# define Rte_Write_FR_DBG_EPS_Res_TBD Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Res_TBD
# define Rte_Write_FR_DBG_EPS_SWA Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_SWA
# define Rte_Write_FR_DBG_EPS_SystemState Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_SystemState
# define Rte_Write_FR_DBG_EPS_ThrmlLimitPerc Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_ThrmlLimitPerc
# define Rte_Write_FR_DBG_EPS_Trq1 Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Trq1
# define Rte_Write_FR_DBG_EPS_Trq2 Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Trq2
# define Rte_Write_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS Rte_Write_Ap_SrlComOutput_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS
# define Rte_Write_ST_EST_ST_EST Rte_Write_Ap_SrlComOutput_ST_EST_ST_EST
# define Rte_Write_SU_EPS_SU_EPS Rte_Write_Ap_SrlComOutput_SU_EPS_SU_EPS
# define Rte_Write_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS Rte_Write_Ap_SrlComOutput_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_EcuM_CurrentMode_currentMode Rte_Mode_Ap_SrlComOutput_EcuM_CurrentMode_currentMode
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComOutput_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EPSIndicatorStatus_GetIndicatorStatus Rte_Call_Ap_SrlComOutput_EPSIndicatorStatus_GetIndicatorStatus
# define Rte_Call_EpsComMStRqst_RequestComMode Rte_Call_Ap_SrlComOutput_EpsComMStRqst_RequestComMode
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed




# define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <RUN> of ModeDeclarationGroupPrototype <currentMode> of PortPrototype <EcuM_CurrentMode>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_EcuM_Mode Rte_Mode_EcuM_CurrentMode_currentMode(void)
 *   Modes of Rte_ModeType_EcuM_Mode:
 *   - RTE_MODE_EcuM_Mode_POST_RUN
 *   - RTE_MODE_EcuM_Mode_RUN
 *   - RTE_MODE_EcuM_Mode_SHUTDOWN
 *   - RTE_MODE_EcuM_Mode_SLEEP
 *   - RTE_MODE_EcuM_Mode_STARTUP
 *   - RTE_MODE_EcuM_Mode_WAKE_SLEEP
 *   - RTE_TRANSITION_EcuM_Mode
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EpsComMStRqst_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per1
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
 *   Std_ReturnType Rte_Read_CtrlTempFinal_DegC_f32(Float *data)
 *   Std_ReturnType Rte_Read_ST_DIAG_OBD_ALIVE(UInt4 *data)
 *   Std_ReturnType Rte_Read_ST_DIAG_OBD_DATA(Edch_EventStatusIpduDataType *data)
 *   Std_ReturnType Rte_Read_ST_DIAG_OBD_MUX_IMME(UInt6 *data)
 *   Std_ReturnType Rte_Read_ST_DIAG_OBD_MUX_MAX(UInt6 *data)
 *   Std_ReturnType Rte_Read_SrlComAVLPOEPS_AVL_PO_EPS(RT_SG_AVL_PO_EPS *data)
 *   Std_ReturnType Rte_Read_SrlComAVLSTMOM_AVL_FORC_GRD(RT_SG_AVL_FORC_GRD *data)
 *   Std_ReturnType Rte_Read_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(RT_SG_AVL_STMOM_DV_ACT *data)
 *   Std_ReturnType Rte_Read_SrlComDISPCCEPS_DISP_CC_EPS(SG_DISP_CC_EPS *data)
 *   Std_ReturnType Rte_Read_SrlComDTEST_DT_EST(SG_DT_EST *data)
 *   Std_ReturnType Rte_Read_SrlComSTEST_ST_EST(RT_SG_ST_EST *data)
 *   Std_ReturnType Rte_Read_SrlComSUEPS_SU_EPS(RT_SG_SU_EPS *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AVL_PO_EPS_AVL_PO_EPS(const RT_SG_AVL_PO_EPS *data)
 *   Std_ReturnType Rte_Write_AVL_PO_EPS_TRGG_ENGTORQ_EPS(New_Coding_39 data)
 *   Std_ReturnType Rte_Write_AVL_STMOM_AVL_FORC_GRD(const RT_SG_AVL_FORC_GRD *data)
 *   Std_ReturnType Rte_Write_AVL_STMOM_AVL_STMOM_DV_ACT(const RT_SG_AVL_STMOM_DV_ACT *data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY(ALIV_4_BIT_Unsigned_Integer data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1(DIAG_ST_OBD data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2(DIAG_ST_OBD data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3(DIAG_ST_OBD data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4(DIAG_ST_OBD data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5(DIAG_ST_OBD data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6(DIAG_ST_OBD data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7(DIAG_ST_OBD data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8(DIAG_ST_OBD data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX(ST_DIAG_OBD_MUX_IMME data)
 *   Std_ReturnType Rte_Write_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX(ST_DIAG_OBD_MUX_MAX data)
 *   Std_ReturnType Rte_Write_DISP_CC_EPS_DISP_CC_EPS(const SG_DISP_CC_EPS *data)
 *   Std_ReturnType Rte_Write_DT_EST_DT_EST(const SG_DT_EST *data)
 *   Std_ReturnType Rte_Write_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS(ID_TEMP_CPO_HET_MNG data)
 *   Std_ReturnType Rte_Write_ST_EST_ST_EST(const RT_SG_ST_EST *data)
 *   Std_ReturnType Rte_Write_SU_EPS_SU_EPS(const RT_SG_SU_EPS *data)
 *   Std_ReturnType Rte_Write_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS(TEMP_CPO_HET_MNG data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComOutput_Per1_AVLFORCGRDTxConf_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComOutput_Per1_AVLFORCGRDTxConf_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComOutput_Per1_AVLSTMOMTxConf_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComOutput_Per1_AVLSTMOMTxConf_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_EcuM_Mode Rte_Mode_EcuM_CurrentMode_currentMode(void)
 *   Modes of Rte_ModeType_EcuM_Mode:
 *   - RTE_MODE_EcuM_Mode_POST_RUN
 *   - RTE_MODE_EcuM_Mode_RUN
 *   - RTE_MODE_EcuM_Mode_SHUTDOWN
 *   - RTE_MODE_EcuM_Mode_SLEEP
 *   - RTE_MODE_EcuM_Mode_STARTUP
 *   - RTE_MODE_EcuM_Mode_WAKE_SLEEP
 *   - RTE_TRANSITION_EcuM_Mode
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
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EPSIndicatorStatus_GetIndicatorStatus(Dem_IndicatorStatusType *IndicatorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IndicatorStatus_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CtrlTempFinal_DegC_f32(Float *data)
 *   Std_ReturnType Rte_Read_CuTempEst_DegC_f32(Float *data)
 *   Std_ReturnType Rte_Read_EpsOpTrq_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_EstBattCurr_Amp_f32(Float *data)
 *   Std_ReturnType Rte_Read_FinHwPos_HwDeg_f32(Float *data)
 *   Std_ReturnType Rte_Read_HwTrq_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_MagTempEst_DegC_f32(Float *data)
 *   Std_ReturnType Rte_Read_MtrCurrQax_Amp_f32(Float *data)
 *   Std_ReturnType Rte_Read_MtrTrqCmd_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_MtrVel_MtrRadpS_f32(Float *data)
 *   Std_ReturnType Rte_Read_T1ADC_Volt_f32(Float *data)
 *   Std_ReturnType Rte_Read_T2ADC_Volt_f32(Float *data)
 *   Std_ReturnType Rte_Read_ThermLimitPerc_Uls_f32(Float *data)
 *   Std_ReturnType Rte_Read_TxDebugMsgEn_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_Vecu_Volt_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_Batt(BATT_VOLTS data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_CtrlTemp(CONT_TEMP_DEG data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_DiffTrq(DIFF_TRQ_NM data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_EstBattCurr(EST_BATT_AMPS data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_EstCuTemp(EST_CUTEMP_DEG data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_EstMtrTemp(EST_MOTTEMP_DEG data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_MtrCurr(New_Coding_3 data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_MtrTrqCmd(MTRTRQCMD_NM data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_MtrTrqCmdLmtd(MTRTRQLMTD_NM data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_MtrVel(MOT_VEL_RADPSEC data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_NTCNumber(New_Coding_28 data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_Res_TBD(New_Coding_15 data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_SWA(SWA_DEG data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_SystemState(SYS_STATE_ENUM data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_ThrmlLimitPerc(THRML_LIMIT_PERC data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_Trq1(TORQUE1_VOLTS data)
 *   Std_ReturnType Rte_Write_FR_DBG_EPS_Trq2(TORQUE2_VOLTS data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_EcuM_Mode Rte_Mode_EcuM_CurrentMode_currentMode(void)
 *   Modes of Rte_ModeType_EcuM_Mode:
 *   - RTE_MODE_EcuM_Mode_POST_RUN
 *   - RTE_MODE_EcuM_Mode_RUN
 *   - RTE_MODE_EcuM_Mode_SHUTDOWN
 *   - RTE_MODE_EcuM_Mode_SLEEP
 *   - RTE_MODE_EcuM_Mode_STARTUP
 *   - RTE_MODE_EcuM_Mode_WAKE_SLEEP
 *   - RTE_TRANSITION_EcuM_Mode
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_TRGD_SVCRequest
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_ANFRAGE_DSC_Modul> of PortPrototype <SG_ANFRAGE_DSC_Modul>
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_ANFRAGE_SAS> of PortPrototype <SG_ANFRAGE_SAS>
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_ANFRAGE_ZGW> of PortPrototype <SG_ANFRAGE_ZGW>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul(SG_ANFRAGE_DSC_Modul *data)
 *   Std_ReturnType Rte_Read_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS(SG_ANFRAGE_SAS *data)
 *   Std_ReturnType Rte_Read_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW(SG_ANFRAGE_ZGW *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_EcuM_Mode Rte_Mode_EcuM_CurrentMode_currentMode(void)
 *   Modes of Rte_ModeType_EcuM_Mode:
 *   - RTE_MODE_EcuM_Mode_POST_RUN
 *   - RTE_MODE_EcuM_Mode_RUN
 *   - RTE_MODE_EcuM_Mode_SHUTDOWN
 *   - RTE_MODE_EcuM_Mode_SLEEP
 *   - RTE_MODE_EcuM_Mode_STARTUP
 *   - RTE_MODE_EcuM_Mode_WAKE_SLEEP
 *   - RTE_TRANSITION_EcuM_Mode
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_TRGD_SVCRequest(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION (2U)

# define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

# define RTE_E_IndicatorStatus_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1457552127
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComOutput/utp/contract/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1457552127
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT_H */
