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
 *          File:  Components/Rte_Ap_SrlComOutput.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue May 24 13:45:33 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT_H
# define _RTE_AP_SRLCOMOUTPUT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_CuTempEst_DegC_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_ElecPwr_SupplyCur_Amp_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_SrlComHwPos_HwDeg_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sweep_OutputHwTrq_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_MagTempEst_DegC_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrCurr_MtrCurrQax_Amp_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;
extern VAR(UInt4, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_ALIVE;
extern VAR(UInt6, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_MUX_IMME;
extern VAR(UInt6, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_MUX_MAX;
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_T1ADC_Volt_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_T2ADC_Volt_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_ThrmlDutyCycle_ThermLimitPerc_Uls_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_TxDebugMsgEn_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_BatteryVoltage_Vecu_Volt_f32;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AVLFORCGRDTxConf_Cnt_lgc (FALSE)
#  define Rte_InitValue_AVLSTMOMTxConf_Cnt_lgc (FALSE)
#  define Rte_InitValue_AVL_PO_EPS_TRGG_ENGTORQ_EPS (0U)
#  define Rte_InitValue_CtrlTempFinal_DegC_f32 (0.0F)
#  define Rte_InitValue_CuTempEst_DegC_f32 (0.0F)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1 (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2 (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3 (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4 (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5 (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6 (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7 (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8 (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX (0U)
#  define Rte_InitValue_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX (0U)
#  define Rte_InitValue_EpsOpTrq_MtrNm_f32 (0.0F)
#  define Rte_InitValue_EstBattCurr_Amp_f32 (0.0F)
#  define Rte_InitValue_FR_DBG_EPS_Batt (0U)
#  define Rte_InitValue_FR_DBG_EPS_CtrlTemp (0U)
#  define Rte_InitValue_FR_DBG_EPS_DiffTrq (0)
#  define Rte_InitValue_FR_DBG_EPS_EstBattCurr (0)
#  define Rte_InitValue_FR_DBG_EPS_EstCuTemp (0U)
#  define Rte_InitValue_FR_DBG_EPS_EstMtrTemp (0U)
#  define Rte_InitValue_FR_DBG_EPS_MtrCurr (0U)
#  define Rte_InitValue_FR_DBG_EPS_MtrTrqCmd (0)
#  define Rte_InitValue_FR_DBG_EPS_MtrTrqCmdLmtd (0)
#  define Rte_InitValue_FR_DBG_EPS_MtrVel (0)
#  define Rte_InitValue_FR_DBG_EPS_NTCNumber (0U)
#  define Rte_InitValue_FR_DBG_EPS_Res_TBD (0U)
#  define Rte_InitValue_FR_DBG_EPS_SWA (0)
#  define Rte_InitValue_FR_DBG_EPS_SystemState (0U)
#  define Rte_InitValue_FR_DBG_EPS_ThrmlLimitPerc (0U)
#  define Rte_InitValue_FR_DBG_EPS_Trq1 (0U)
#  define Rte_InitValue_FR_DBG_EPS_Trq2 (0U)
#  define Rte_InitValue_FinHwPos_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
#  define Rte_InitValue_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS (0U)
#  define Rte_InitValue_MagTempEst_DegC_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrTrqCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_MtrVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_ST_DIAG_OBD_ALIVE (0U)
#  define Rte_InitValue_ST_DIAG_OBD_MUX_IMME (0U)
#  define Rte_InitValue_ST_DIAG_OBD_MUX_MAX (0U)
#  define Rte_InitValue_SrlComAVLPOEPS_TRGG_ENGTORQ_EPS (0U)
#  define Rte_InitValue_T1ADC_Volt_f32 (0.0F)
#  define Rte_InitValue_T2ADC_Volt_f32 (0.0F)
#  define Rte_InitValue_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS (0U)
#  define Rte_InitValue_ThermLimitPerc_Uls_f32 (0.0F)
#  define Rte_InitValue_TxDebugMsgEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_Vecu_Volt_f32 (5.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_EcuM_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_EcuM_currentMode_currentMode;
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd9_SystemState9_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10msA_9, RTE_VAR_NOINIT) Rte_Task_10msA_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul(P2VAR(SG_ANFRAGE_DSC_Modul, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS(P2VAR(SG_ANFRAGE_SAS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW(P2VAR(SG_ANFRAGE_ZGW, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_DATA(P2VAR(Edch_EventStatusIpduDataType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLPOEPS_AVL_PO_EPS(P2VAR(RT_SG_AVL_PO_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_FORC_GRD(P2VAR(RT_SG_AVL_FORC_GRD, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(P2VAR(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComDISPCCEPS_DISP_CC_EPS(P2VAR(SG_DISP_CC_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComDTEST_DT_EST(P2VAR(SG_DT_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComSTEST_ST_EST(P2VAR(RT_SG_ST_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComSUEPS_SU_EPS(P2VAR(RT_SG_SU_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
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

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IWrite_SrlComOutput_Per1_AVLFORCGRDTxConf_Cnt_lgc(data) \
  ( \
    Rte_Task_10msA_9.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AVLFORCGRDTxConf_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_AVLFORCGRDTxConf_Cnt_lgc() \
  (&Rte_Task_10msA_9.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AVLFORCGRDTxConf_Cnt_lgc.value)

#  define Rte_IWrite_SrlComOutput_Per1_AVLSTMOMTxConf_Cnt_lgc(data) \
  ( \
    Rte_Task_10msA_9.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AVLSTMOMTxConf_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_AVLSTMOMTxConf_Cnt_lgc() \
  (&Rte_Task_10msA_9.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AVLSTMOMTxConf_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CtrlTempFinal_DegC_f32 Rte_Read_Ap_SrlComOutput_CtrlTempFinal_DegC_f32
#  define Rte_Read_Ap_SrlComOutput_CtrlTempFinal_DegC_f32(data) (*(data) = Rte_CtrlTemp_FiltMeasTemp_DegC_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CuTempEst_DegC_f32 Rte_Read_Ap_SrlComOutput_CuTempEst_DegC_f32
#  define Rte_Read_Ap_SrlComOutput_CuTempEst_DegC_f32(data) (*(data) = Rte_MtrTempEst_CuTempEst_DegC_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EpsOpTrq_MtrNm_f32 Rte_Read_Ap_SrlComOutput_EpsOpTrq_MtrNm_f32
#  define Rte_Read_Ap_SrlComOutput_EpsOpTrq_MtrNm_f32(data) (*(data) = Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EstBattCurr_Amp_f32 Rte_Read_Ap_SrlComOutput_EstBattCurr_Amp_f32
#  define Rte_Read_Ap_SrlComOutput_EstBattCurr_Amp_f32(data) (*(data) = Rte_ElecPwr_SupplyCur_Amp_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_FinHwPos_HwDeg_f32 Rte_Read_Ap_SrlComOutput_FinHwPos_HwDeg_f32
#  define Rte_Read_Ap_SrlComOutput_FinHwPos_HwDeg_f32(data) (*(data) = Rte_AbsHwPos_SrlComHwPos_HwDeg_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HwTrq_HwNm_f32 Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32
#  define Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32(data) (*(data) = Rte_Sweep_OutputHwTrq_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_MagTempEst_DegC_f32 Rte_Read_Ap_SrlComOutput_MagTempEst_DegC_f32
#  define Rte_Read_Ap_SrlComOutput_MagTempEst_DegC_f32(data) (*(data) = Rte_MtrTempEst_MagTempEst_DegC_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_MtrCurrQax_Amp_f32 Rte_Read_Ap_SrlComOutput_MtrCurrQax_Amp_f32
#  define Rte_Read_Ap_SrlComOutput_MtrCurrQax_Amp_f32(data) (*(data) = Rte_MtrCurr_MtrCurrQax_Amp_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_MtrTrqCmd_MtrNm_f32 Rte_Read_Ap_SrlComOutput_MtrTrqCmd_MtrNm_f32
#  define Rte_Read_Ap_SrlComOutput_MtrTrqCmd_MtrNm_f32(data) (*(data) = Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_MtrVel_MtrRadpS_f32 Rte_Read_Ap_SrlComOutput_MtrVel_MtrRadpS_f32
#  define Rte_Read_Ap_SrlComOutput_MtrVel_MtrRadpS_f32(data) (*(data) = Rte_MtrVel_MRFMotorVel_MtrRadpS_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul
#  define Rte_Read_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS
#  define Rte_Read_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW
#  define Rte_Read_ST_DIAG_OBD_ALIVE Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_ALIVE
#  define Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_ALIVE(data) (*(data) = Rte_Edch_ST_DIAG_OBD_ALIVE, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ST_DIAG_OBD_DATA Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_DATA
#  define Rte_Read_ST_DIAG_OBD_MUX_IMME Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_MUX_IMME
#  define Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_MUX_IMME(data) (*(data) = Rte_Edch_ST_DIAG_OBD_MUX_IMME, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ST_DIAG_OBD_MUX_MAX Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_MUX_MAX
#  define Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_MUX_MAX(data) (*(data) = Rte_Edch_ST_DIAG_OBD_MUX_MAX, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComAVLPOEPS_AVL_PO_EPS Rte_Read_Ap_SrlComOutput_SrlComAVLPOEPS_AVL_PO_EPS
#  define Rte_Read_SrlComAVLSTMOM_AVL_FORC_GRD Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_FORC_GRD
#  define Rte_Read_SrlComAVLSTMOM_AVL_STMOM_DV_ACT Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_STMOM_DV_ACT
#  define Rte_Read_SrlComDISPCCEPS_DISP_CC_EPS Rte_Read_Ap_SrlComOutput_SrlComDISPCCEPS_DISP_CC_EPS
#  define Rte_Read_SrlComDTEST_DT_EST Rte_Read_Ap_SrlComOutput_SrlComDTEST_DT_EST
#  define Rte_Read_SrlComSTEST_ST_EST Rte_Read_Ap_SrlComOutput_SrlComSTEST_ST_EST
#  define Rte_Read_SrlComSUEPS_SU_EPS Rte_Read_Ap_SrlComOutput_SrlComSUEPS_SU_EPS
#  define Rte_Read_T1ADC_Volt_f32 Rte_Read_Ap_SrlComOutput_T1ADC_Volt_f32
#  define Rte_Read_Ap_SrlComOutput_T1ADC_Volt_f32(data) (*(data) = Rte_IoHwAb7_T1ADC_Volt_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_T2ADC_Volt_f32 Rte_Read_Ap_SrlComOutput_T2ADC_Volt_f32
#  define Rte_Read_Ap_SrlComOutput_T2ADC_Volt_f32(data) (*(data) = Rte_IoHwAb7_T2ADC_Volt_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ThermLimitPerc_Uls_f32 Rte_Read_Ap_SrlComOutput_ThermLimitPerc_Uls_f32
#  define Rte_Read_Ap_SrlComOutput_ThermLimitPerc_Uls_f32(data) (*(data) = Rte_ThrmlDutyCycle_ThermLimitPerc_Uls_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_TxDebugMsgEn_Cnt_lgc Rte_Read_Ap_SrlComOutput_TxDebugMsgEn_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_TxDebugMsgEn_Cnt_lgc(data) (*(data) = Rte_VehCfg_TxDebugMsgEn_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Vecu_Volt_f32 Rte_Read_Ap_SrlComOutput_Vecu_Volt_f32
#  define Rte_Read_Ap_SrlComOutput_Vecu_Volt_f32(data) (*(data) = Rte_BatteryVoltage_Vecu_Volt_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AVL_PO_EPS_AVL_PO_EPS Rte_Write_Ap_SrlComOutput_AVL_PO_EPS_AVL_PO_EPS
#  define Rte_Write_AVL_PO_EPS_TRGG_ENGTORQ_EPS Rte_Write_Ap_SrlComOutput_AVL_PO_EPS_TRGG_ENGTORQ_EPS
#  define Rte_Write_AVL_STMOM_AVL_FORC_GRD Rte_Write_Ap_SrlComOutput_AVL_STMOM_AVL_FORC_GRD
#  define Rte_Write_AVL_STMOM_AVL_STMOM_DV_ACT Rte_Write_Ap_SrlComOutput_AVL_STMOM_AVL_STMOM_DV_ACT
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8 Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX
#  define Rte_Write_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX
#  define Rte_Write_DISP_CC_EPS_DISP_CC_EPS Rte_Write_Ap_SrlComOutput_DISP_CC_EPS_DISP_CC_EPS
#  define Rte_Write_DT_EST_DT_EST Rte_Write_Ap_SrlComOutput_DT_EST_DT_EST
#  define Rte_Write_FR_DBG_EPS_Batt Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Batt
#  define Rte_Write_FR_DBG_EPS_CtrlTemp Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_CtrlTemp
#  define Rte_Write_FR_DBG_EPS_DiffTrq Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_DiffTrq
#  define Rte_Write_FR_DBG_EPS_EstBattCurr Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstBattCurr
#  define Rte_Write_FR_DBG_EPS_EstCuTemp Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstCuTemp
#  define Rte_Write_FR_DBG_EPS_EstMtrTemp Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstMtrTemp
#  define Rte_Write_FR_DBG_EPS_MtrCurr Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrCurr
#  define Rte_Write_FR_DBG_EPS_MtrTrqCmd Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmd
#  define Rte_Write_FR_DBG_EPS_MtrTrqCmdLmtd Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmdLmtd
#  define Rte_Write_FR_DBG_EPS_MtrVel Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrVel
#  define Rte_Write_FR_DBG_EPS_NTCNumber Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_NTCNumber
#  define Rte_Write_FR_DBG_EPS_Res_TBD Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Res_TBD
#  define Rte_Write_FR_DBG_EPS_SWA Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_SWA
#  define Rte_Write_FR_DBG_EPS_SystemState Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_SystemState
#  define Rte_Write_FR_DBG_EPS_ThrmlLimitPerc Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_ThrmlLimitPerc
#  define Rte_Write_FR_DBG_EPS_Trq1 Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Trq1
#  define Rte_Write_FR_DBG_EPS_Trq2 Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Trq2
#  define Rte_Write_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS Rte_Write_Ap_SrlComOutput_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS
#  define Rte_Write_ST_EST_ST_EST Rte_Write_Ap_SrlComOutput_ST_EST_ST_EST
#  define Rte_Write_SU_EPS_SU_EPS Rte_Write_Ap_SrlComOutput_SU_EPS_SU_EPS
#  define Rte_Write_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS Rte_Write_Ap_SrlComOutput_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_EcuM_CurrentMode_currentMode() Rte_ModeMachine_EcuM_currentMode_currentMode
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetIndicatorStatus(Dem_IndicatorIdType parg0, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_DEM_APPL_VAR) IndicatorStatus);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EPSIndicatorStatus_GetIndicatorStatus(arg1) (Dem_GetIndicatorStatus((Dem_IndicatorIdType)0, arg1))
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode);
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EpsComMStRqst_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)0, arg1))
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr9_GetNTCFailed


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init1(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per2(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_TRGD_SVCRequest(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION (2U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

#  define RTE_E_IndicatorStatus_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_SrlComOutput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT_H */
