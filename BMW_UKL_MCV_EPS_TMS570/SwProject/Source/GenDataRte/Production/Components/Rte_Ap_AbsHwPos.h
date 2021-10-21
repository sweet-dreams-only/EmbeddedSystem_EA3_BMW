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
 *          File:  Components/Rte_Ap_AbsHwPos.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:20 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ABSHWPOS_H
# define _RTE_AP_ABSHWPOS_H

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
extern VAR(Boolean, RTE_VAR_INIT) Rte_AbsHwPos_LTVehCenterComplete_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_LnRkCr_RackCenter_HwDeg_f32;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AlignedCumMtrPosMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_AlignedHwPos_HwDeg_f32 (0.0F)
#  define Rte_InitValue_DefeatKinIntTest_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsDefHwPos_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsHwPosDis_Cnt_lgc (FALSE)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HwTargetAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_ICMMtrPosMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_ICMRevOffsetCRF_Rev_s16 (0)
#  define Rte_InitValue_ICMRevOffsetStatus_Cnt_u08 (8U)
#  define Rte_InitValue_LTRckCntrComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_LTVehCenterComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_Polarity_Cnt_s08 (0)
#  define Rte_InitValue_RackCenter_HwDeg_f32 (0.0F)
#  define Rte_InitValue_RacktoVehCntrOffset_Cnt_u16 (4095U)
#  define Rte_InitValue_RevOffsetState_Cnt_u08 (0U)
#  define Rte_InitValue_SrlComHwPos_HwDeg_f32 (0.0F)
#  define Rte_InitValue_TCMtrPosOffsMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_TorqueCmdCRF_MtrNm_f32 (0.0F)
#  define Rte_InitValue_TurnsCntrValidity_Cnt_enum (0U)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitB_10, RTE_VAR_NOINIT) Rte_Task_InitB_10;

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

extern VAR(Rte_tsTask_10msB_10, RTE_VAR_NOINIT) Rte_Task_10msB_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

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

#  define Rte_IWrite_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_InitB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_LTVehCenterComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc() \
  (&Rte_Task_InitB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_LTVehCenterComplete_Cnt_lgc.value)

#  define Rte_IWrite_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16(data) \
  ( \
    Rte_Task_InitB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_RacktoVehCntrOffset_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16() \
  (&Rte_Task_InitB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_RacktoVehCntrOffset_Cnt_u16.value)

#  define Rte_IRead_AbsHwPos_Per1_AlignedCumMtrPosMRF_Deg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_AlignedCumMtrPosMRF_Deg_f32.value)

#  define Rte_IRead_AbsHwPos_Per1_DiagStsDefHwPos_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_DiagStsDefHwPos_Cnt_lgc.value)

#  define Rte_IRead_AbsHwPos_Per1_DiagStsHwPosDis_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_DiagStsHwPosDis_Cnt_lgc.value)

#  define Rte_IRead_AbsHwPos_Per1_ICMRevOffsetCRF_Rev_s16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_ICMRevOffsetCRF_Rev_s16.value)

#  define Rte_IRead_AbsHwPos_Per1_ICMRevOffsetStatus_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_ICMRevOffsetStatus_Cnt_u08.value)

#  define Rte_IRead_AbsHwPos_Per1_LTRckCntrComplete_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_LTRckCntrComplete_Cnt_lgc.value)

#  define Rte_IRead_AbsHwPos_Per1_Polarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Polarity_AssistAssyPolarity_Cnt_s08.value)

#  define Rte_IRead_AbsHwPos_Per1_RackCenter_HwDeg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RackCenter_HwDeg_f32.value)

#  define Rte_IRead_AbsHwPos_Per1_TCMtrPosOffsMRF_Deg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_TCMtrPosOffsMRF_Deg_f32.value)

#  define Rte_IRead_AbsHwPos_Per1_TorqueCmdCRF_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32.value)

#  define Rte_IRead_AbsHwPos_Per1_TurnsCntrValidity_Cnt_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_TurnsCntrValidity_Cnt_enum.value)

#  define Rte_IWrite_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_AlignedHwPos_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_AlignedHwPos_HwDeg_f32.value)

#  define Rte_IWrite_AbsHwPos_Per1_HandwheelAuthority_Uls_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HandwheelAuthority_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Per1_HandwheelAuthority_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IWrite_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HandwheelPosition_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IWrite_AbsHwPos_Per1_HwTargetAuthority_Uls_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HwTargetAuthority_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Per1_HwTargetAuthority_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HwTargetAuthority_Uls_f32.value)

#  define Rte_IWrite_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_ICMMtrPosMRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_ICMMtrPosMRF_Deg_f32.value)

#  define Rte_IWrite_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RacktoVehCntrOffset_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RacktoVehCntrOffset_Cnt_u16.value)

#  define Rte_IWrite_AbsHwPos_Per1_RevOffsetState_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RevOffsetState_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Per1_RevOffsetState_Cnt_u08() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RevOffsetState_Cnt_u08.value)

#  define Rte_IWrite_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_SrlComHwPos_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_SrlComHwPos_HwDeg_f32.value)

#  define Rte_IRead_AbsHwPos_Per2_DefeatKinIntTest_Cnt_lgc() \
  (Rte_Task_10msB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_DefeatKinIntTest_Cnt_lgc.value)

#  define Rte_IRead_AbsHwPos_Per2_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Task_10msB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_DiagStsDefVehSpd_Cnt_lgc.value)

#  define Rte_IRead_AbsHwPos_Per2_VehicleSpeed_Kph_f32() \
  (Rte_Task_10msB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_VehicleSpeed_Kph_f32.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_DiagStsDefHwPos_Cnt_lgc Rte_Read_Ap_AbsHwPos_DiagStsDefHwPos_Cnt_lgc
#  define Rte_Read_Ap_AbsHwPos_DiagStsDefHwPos_Cnt_lgc(data) (*(data) = Rte_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_LTRckCntrComplete_Cnt_lgc Rte_Read_Ap_AbsHwPos_LTRckCntrComplete_Cnt_lgc
#  define Rte_Read_Ap_AbsHwPos_LTRckCntrComplete_Cnt_lgc(data) (*(data) = Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RackCenter_HwDeg_f32 Rte_Read_Ap_AbsHwPos_RackCenter_HwDeg_f32
#  define Rte_Read_Ap_AbsHwPos_RackCenter_HwDeg_f32(data) (*(data) = Rte_LnRkCr_RackCenter_HwDeg_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_LTVehCenterComplete_Cnt_lgc Rte_Write_Ap_AbsHwPos_LTVehCenterComplete_Cnt_lgc
#  define Rte_Write_Ap_AbsHwPos_LTVehCenterComplete_Cnt_lgc(data) (Rte_AbsHwPos_LTVehCenterComplete_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_LNRKCR_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrRev(void);
#  define RTE_STOP_SEC_AP_LNRKCR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_LnRkCr_Scom_ResetRckCntrMtrRev() (LnRkCr_Scom_ResetRckCntrMtrRev(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_LRNEOT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetEOT(void);
#  define RTE_STOP_SEC_AP_LRNEOT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_LrnEOT_Scom_ResetEOT() (LrnEOT_Scom_ResetEOT(), ((Std_ReturnType)RTE_E_OK))
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
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_Trim_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)7, arg1))
#  define RTE_START_SEC_CD_TURNSCOUNTER_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_ResetTC(void);
#  define RTE_STOP_SEC_CD_TURNSCOUNTER_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TurnsCounter_Scom_ResetTC() (TurnsCounter_Scom_ResetTC(), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(AbsHwPosTrim_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_AbsHwPos_Trim;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_Trim() \
  (&Rte_AbsHwPos_Trim)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Init1(void);

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per1(void);

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per2(void);

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_VehicleSystemStatus(P2VAR(SInt16, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) NCMAbsHwPos_HwDeg_s11p4);

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearCenterPosition(void);

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearRacktoVehCntrOffset(void);

FUNC(Std_ReturnType, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32);

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc);

# define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

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
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_AbsHwPos.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ABSHWPOS_H */
