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
 *          File:  Components/Rte_NtWrap.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:21 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NTWRAP_H
# define _RTE_NTWRAP_H

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


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_VehicleSystemStatus(P2VAR(SInt16, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) NCMAbsHwPos_HwDeg_s11p4);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AbsHwPos_SCom_VehicleSystemStatus(arg1) (AbsHwPos_SCom_VehicleSystemStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AbsHwPos_SetData_SetRacktoVehCntrOffset(arg1, arg2) (AbsHwPos_SetData_SetRacktoVehCntrOffset(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ASSISTSUMNLMT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
#  define RTE_STOP_SEC_AP_ASSISTSUMNLMT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AssistLmtFunc_Scom_ManualTrqCmd(arg1, arg2) (AssistLmtFunc_Scom_ManualTrqCmd(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_GENPOSTRAJ_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_GENPOSTRAJ_APPL_CODE) GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);
#  define RTE_STOP_SEC_AP_GENPOSTRAJ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_GeneratePosTraj_SCom_SetInputParam(arg1, arg2, arg3) (GenPosTraj_SCom_SetInputParam(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqScale(void);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_ClrHwTrqScale HwTrq_SCom_ClrHwTrqScale
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqTrim(void);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_ClrHwTrqTrim HwTrq_SCom_ClrHwTrqTrim
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_ManualSetHwTrqTrim HwTrq_SCom_ManualSetHwTrqTrim
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# else
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# endif
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_SetEOLTrqStep(arg1) (HwTrq_SCom_SetEOLTrqStep(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqScale(Float ScaleValue);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_SetHwTrqScale HwTrq_SCom_SetHwTrqScale
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqTrim(void);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_SetHwTrqTrim HwTrq_SCom_SetHwTrqTrim
#  define RTE_START_SEC_AP_LKTOLKSTR_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_LKTOLKSTR_APPL_CODE) LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);
#  define RTE_STOP_SEC_AP_LKTOLKSTR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_LktoLkStr_SCom_SetInputParam(arg1, arg2) (LktoLkStr_SCom_SetInputParam(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_LRNEOT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetEOT(void);
#  define RTE_STOP_SEC_AP_LRNEOT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_LrnEOT_Scom_ResetEOT() (LrnEOT_Scom_ResetEOT(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_MTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalGain(void);
#  define RTE_STOP_SEC_SA_MTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MtrCurr_SCom_CalGain MtrCurr_SCom_CalGain
#  define RTE_START_SEC_SA_MTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalOffset(void);
#  define RTE_STOP_SEC_SA_MTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MtrCurr_SCom_CalOffset() (MtrCurr_SCom_CalOffset(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_MTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_DATA) ShCurrCalPtr);
#  define RTE_STOP_SEC_SA_MTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MtrCurr_SCom_SetMtrCurrCals(arg1) (MtrCurr_SCom_SetMtrCurrCals(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_MTRPOS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);
#  define RTE_STOP_SEC_SA_MTRPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MtrPos_SCom_SetEOLMtrCals(arg1) (MtrPos_SCom_SetEOLMtrCals(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_OSCTRAJ_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_OSCTRAJ_APPL_CODE) OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32);
#  define RTE_STOP_SEC_AP_OSCTRAJ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_OscTraj_SCom_SetInputParams(arg1, arg2, arg3) (OscTraj_SCom_SetInputParams(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_POLARITY_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16);
#  define RTE_STOP_SEC_AP_POLARITY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_Polarity_SCom_SetPolarity Polarity_SCom_SetPolarity
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearRacktoVehCntrOffset(void);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_RacktoVehCntrOffset_Scom_ClearRacktoVehCntrOffset() (AbsHwPos_Scom_ClearRacktoVehCntrOffset(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_PARAMCOMP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32);
#  define RTE_STOP_SEC_AP_PARAMCOMP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SCom_EOLNomMtrParam_Set(arg1, arg2, arg3) (SCom_EOLNomMtrParam_Set(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_PARAMCOMP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32);
#  define RTE_STOP_SEC_AP_PARAMCOMP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SCom_KeIntgSVParam_Set(arg1) (SCom_KeIntgSVParam_Set(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_PARAMCOMP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32);
#  define RTE_STOP_SEC_AP_PARAMCOMP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SCom_RIntgSVParam_Set(arg1) (SCom_RIntgSVParam_Set(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_SRLCOMINPUT2_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32);
#  define RTE_STOP_SEC_AP_SRLCOMINPUT2_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SrlComInput_SCom_ManualVehSpd(arg1) (SrlComInput2_SCom_ManualVehSpd(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_STAMD9_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_STAMD9_APPL_CODE) StaMd_SCom_EcuReset(void);
#  define RTE_STOP_SEC_AP_STAMD9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_StaMd_SCom_EcuReset() (StaMd_SCom_EcuReset(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_TURNSCOUNTER_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_ClearTcEOLCals(void);
#  define RTE_STOP_SEC_CD_TURNSCOUNTER_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TcEOLCals_Scom_ClearTcEOLCals() (TcEOLCals_Scom_ClearTcEOLCals(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_TURNSCOUNTER_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8);
#  define RTE_STOP_SEC_CD_TURNSCOUNTER_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TcEOLCals_Scom_SetTcEOLCals TcEOLCals_Scom_SetTcEOLCals
#  define RTE_START_SEC_AP_TRQCMDSCL_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32);
#  define RTE_STOP_SEC_AP_TRQCMDSCL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TrqCmdScl_SCom_Set(arg1) (TrqCmdScl_SCom_Set(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_TURNSCOUNTER_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_ResetTC(void);
#  define RTE_STOP_SEC_CD_TURNSCOUNTER_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TurnsCounter_Scom_ResetTC() (TurnsCounter_Scom_ResetTC(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearCenterPosition(void);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_VehicleCenter_Scom_ClearCenterPosition() (AbsHwPos_Scom_ClearCenterPosition(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32);
#  define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_VehicleCenter_Scom_SetCenterPosition AbsHwPos_Scom_SetCenterPosition


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_SCom_VehicleSystemStatus(P2VAR(SInt16, AUTOMATIC, RTE_NTWRAP_APPL_VAR) NCMAbsHwPos_HwDeg_s11p4);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqScale(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetEOLTrqStep(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) TrqStep_HwNm_T_f32);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) TrqStep_HwNm_T_f32);
# endif

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetHwTrqScale(Float ScaleValue);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetHwTrqTrim(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_LrnEOT_Scom_ResetEOT(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_CalGain(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_CalOffset(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrCalDataPtr);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrap_Per1(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) Call_Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_StaMd_SCom_EcuReset(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_TrqCmdScl_SCom_Set(Float Par_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_SCom_ClearTcEOLCals(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_SCom_ResetTC(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8);

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_ClearCenterPosition(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32);

# define RTE_STOP_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_HwTrq_SCom_ConditionsNotCorrect (20U)

#  define RTE_E_MtrCurr_SCom_CurrentOutOfRange (34U)

#  define RTE_E_Polarity_SCom_RequestOutOfRange (49U)

#  define RTE_E_TcEOLCals_Scom_RequestDataOutOfRange (34U)

#  define RTE_E_VehicleCenter_Scom_E_NOT_OK (1U)

#  define RTE_E_VehicleCenter_Scom_E_NOT_OK_OUTOFRANGE (49U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_NtWrap.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_NTWRAP_H */
