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
 *          File:  Components/Rte_Ap_SrlComOutput2.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu Feb  2 12:00:20 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT2_H
# define _RTE_AP_SRLCOMOUTPUT2_H

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

#  define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SupplyCurrLmt_Amp_f32;
extern VAR(QU_SER_STMOM_STMOM_DV_ACT, RTE_VAR_INIT) Rte_DrvDynamicsEnable_DrvDynInterfaceState_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_ElecPwr_ElecPower_Watts_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_SrlComHwPos_HwDeg_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BmwHaptcFb_HaptcFbSt_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_Sweep_OutputHwTrq_HwNm_f32;
extern VAR(QU_SER_WSTA_EST_FTAX, RTE_VAR_INIT) Rte_ParkAssistEnable_PrkAssistState_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_RackLoad_RackLoad_kN_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_ElecPwr_SupplyCur_Amp_f32;
extern VAR(TJAStateType, RTE_VAR_INIT) Rte_Ap_TJADamp_TJAState_Cnt_enum;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AVLFORCGRDTxConf_Cnt_lgc (FALSE)
#  define Rte_InitValue_AVLSTMOMTxConf_Cnt_lgc (FALSE)
#  define Rte_InitValue_CADASMSG_Cnt_lgc (FALSE)
#  define Rte_InitValue_CDISPCCEPS_Cnt_u08 (1U)
#  define Rte_InitValue_CEVIIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CFACTORIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWANGLEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWTORQUEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CMTTORQUEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CustCurrLmt_Amp_f32 (166.67F)
#  define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc (FALSE)
#  define Rte_InitValue_DrvDynState_Cnt_u08 (128U)
#  define Rte_InitValue_ElecPower_Watts_f32 (0.0F)
#  define Rte_InitValue_FinHwPos_HwDeg_f32 (0.0F)
#  define Rte_InitValue_FinHwPosAuth_Uls_f32 (0.0F)
#  define Rte_InitValue_HaptcFbSt_Cnt_u08 (1U)
#  define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
#  define Rte_InitValue_LimitPercentFiltered_Uls_f32 (0.0F)
#  define Rte_InitValue_PrkAstState_Cnt_u08 (128U)
#  define Rte_InitValue_RackLoad_kN_f32 (0.0F)
#  define Rte_InitValue_RacktoVehCntrOffset_Cnt_u16 (4095U)
#  define Rte_InitValue_RevOffsetState_Cnt_u08 (0U)
#  define Rte_InitValue_SrlComAVLPOEPS_TRGG_ENGTORQ_EPS (0U)
#  define Rte_InitValue_SrlComHwTrqValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SupplyCur_Amp_f32 (0.0F)
#  define Rte_InitValue_TJAState_Cnt_enum (1U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10msA_10, RTE_VAR_NOINIT) Rte_Task_10msA_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS(P2CONST(RT_SG_AVL_PO_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD(P2CONST(RT_SG_AVL_FORC_GRD, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(P2CONST(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS(P2CONST(SG_DISP_CC_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComDTEST_DT_EST(P2CONST(SG_DT_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComSTEST_ST_EST(P2CONST(RT_SG_ST_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComSUEPS_SU_EPS(P2CONST(RT_SG_SU_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data);

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

#  define Rte_IRead_SrlComOutput2_Per1_AVLFORCGRDTxConf_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_AVLFORCGRDTxConf_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_AVLSTMOMTxConf_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_AVLSTMOMTxConf_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_CADASMSG_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CADASMSG_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_CDISPCCEPS_Cnt_u08() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CDISPCCEPS_Cnt_u08.value)

#  define Rte_IRead_SrlComOutput2_Per1_CEVIIF_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CEVIIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_CFACTORIF_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CFACTORIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_CHWANGLEIF_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CHWANGLEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CHWTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CMTTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_DiagStsRecRmpToZeroFltPres_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput2_Per1_LimitPercentFiltered_Uls_f32() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_LimitPercentFiltered_Uls_f32.value)

#  define Rte_IRead_SrlComOutput2_Per1_RacktoVehCntrOffset_Cnt_u16() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_RacktoVehCntrOffset_Cnt_u16.value)

#  define Rte_IRead_SrlComOutput2_Per1_RevOffsetState_Cnt_u08() \
  (Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_RevOffsetState_Cnt_u08.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CustCurrLmt_Amp_f32 Rte_Read_Ap_SrlComOutput2_CustCurrLmt_Amp_f32
#  define Rte_Read_Ap_SrlComOutput2_CustCurrLmt_Amp_f32(data) (*(data) = Rte_SrlComInput_SupplyCurrLmt_Amp_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DrvDynState_Cnt_u08 Rte_Read_Ap_SrlComOutput2_DrvDynState_Cnt_u08
#  define Rte_Read_Ap_SrlComOutput2_DrvDynState_Cnt_u08(data) (*(data) = Rte_DrvDynamicsEnable_DrvDynInterfaceState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ElecPower_Watts_f32 Rte_Read_Ap_SrlComOutput2_ElecPower_Watts_f32
#  define Rte_Read_Ap_SrlComOutput2_ElecPower_Watts_f32(data) (*(data) = Rte_ElecPwr_ElecPower_Watts_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_FinHwPos_HwDeg_f32 Rte_Read_Ap_SrlComOutput2_FinHwPos_HwDeg_f32
#  define Rte_Read_Ap_SrlComOutput2_FinHwPos_HwDeg_f32(data) (*(data) = Rte_AbsHwPos_SrlComHwPos_HwDeg_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_FinHwPosAuth_Uls_f32 Rte_Read_Ap_SrlComOutput2_FinHwPosAuth_Uls_f32
#  define Rte_Read_Ap_SrlComOutput2_FinHwPosAuth_Uls_f32(data) (*(data) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HaptcFbSt_Cnt_u08 Rte_Read_Ap_SrlComOutput2_HaptcFbSt_Cnt_u08
#  define Rte_Read_Ap_SrlComOutput2_HaptcFbSt_Cnt_u08(data) (*(data) = Rte_BmwHaptcFb_HaptcFbSt_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HwTrq_HwNm_f32 Rte_Read_Ap_SrlComOutput2_HwTrq_HwNm_f32
#  define Rte_Read_Ap_SrlComOutput2_HwTrq_HwNm_f32(data) (*(data) = Rte_Sweep_OutputHwTrq_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PrkAstState_Cnt_u08 Rte_Read_Ap_SrlComOutput2_PrkAstState_Cnt_u08
#  define Rte_Read_Ap_SrlComOutput2_PrkAstState_Cnt_u08(data) (*(data) = Rte_ParkAssistEnable_PrkAssistState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RackLoad_kN_f32 Rte_Read_Ap_SrlComOutput2_RackLoad_kN_f32
#  define Rte_Read_Ap_SrlComOutput2_RackLoad_kN_f32(data) (*(data) = Rte_RackLoad_RackLoad_kN_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComHwTrqValid_Cnt_lgc Rte_Read_Ap_SrlComOutput2_SrlComHwTrqValid_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput2_SrlComHwTrqValid_Cnt_lgc(data) (*(data) = Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SupplyCur_Amp_f32 Rte_Read_Ap_SrlComOutput2_SupplyCur_Amp_f32
#  define Rte_Read_Ap_SrlComOutput2_SupplyCur_Amp_f32(data) (*(data) = Rte_ElecPwr_SupplyCur_Amp_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_TJAState_Cnt_enum Rte_Read_Ap_SrlComOutput2_TJAState_Cnt_enum
#  define Rte_Read_Ap_SrlComOutput2_TJAState_Cnt_enum(data) (*(data) = Rte_Ap_TJADamp_TJAState_Cnt_enum, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SrlComAVLPOEPS_AVL_PO_EPS Rte_Write_Ap_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS
#  define Rte_Write_SrlComAVLSTMOM_AVL_FORC_GRD Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD
#  define Rte_Write_SrlComAVLSTMOM_AVL_STMOM_DV_ACT Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT
#  define Rte_Write_SrlComDISPCCEPS_DISP_CC_EPS Rte_Write_Ap_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS
#  define Rte_Write_SrlComDTEST_DT_EST Rte_Write_Ap_SrlComOutput2_SrlComDTEST_DT_EST
#  define Rte_Write_SrlComSTEST_ST_EST Rte_Write_Ap_SrlComOutput2_SrlComSTEST_ST_EST
#  define Rte_Write_SrlComSUEPS_SU_EPS Rte_Write_Ap_SrlComOutput2_SrlComSUEPS_SU_EPS


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMOUTPUT2_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Init1(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Per1(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Trns1(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT2_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_SrlComOutput2.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT2_H */
