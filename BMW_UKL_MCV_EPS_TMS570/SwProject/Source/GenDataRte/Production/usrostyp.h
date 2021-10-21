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
 *          File:  usrostyp.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:24 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  User Types header file (osCAN specific)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _USROSTYP_H
# define _USROSTYP_H

# include "Com.h"
# include "Rte_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Assist_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BmwHaptcFb_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BmwHaptcFb_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_100msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_100msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_2msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp11_ChkPtAp11_2msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp7_ChkPtAp7_100msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp7_ChkPtAp7_100msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp7_ChkPtAp7_10msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp7_ChkPtAp7_10msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp7_ChkPtAp7_2msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp7_ChkPtAp7_2msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp7_ChkPtAp7_4msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp7_ChkPtAp7_4msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp8_ChkPtAp8_100msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp8_ChkPtAp8_100msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp8_ChkPtAp8_2msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp8_ChkPtAp8_2msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp8_ChkPtAp8_4msEnd_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ChkPtAp8_ChkPtAp8_4msStart_CP_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Damping_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_FltInjection_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_FltInjection_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_HystComp_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LktoLkStr_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LktoLkStr_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LnRkCr_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LnRkCr_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LnRkCr_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ParkAstEnbl_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ParkAstEnbl_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PrkAstMfgServCh2_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PwrLmtFunc_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PwrLmtFunc_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Return_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Sweep_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Sweep_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_TrqBasedInrtCmp_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehPwrMd_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_VehPwrMd_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_TurnsCounter_EOLTurnsCntrCals_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_TurnsCounter_EOLTurnsCntrCals_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_TurnsCounter_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_TurnsCounter_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_TurnsCounter_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_TurnsCounter_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_TurnsCounter_TcMCLR_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_IoHwAb7_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_IoHwAb7_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_EOLTrqStep_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_HwTrqScale_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_HwTrqTrim_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_HwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrCurr_EOLShCurrCal_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetDrvReset_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt1Data_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_FetDrvCntl_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_PwrSwitchEn_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault2_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault2_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault3_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault3_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_WdMonitor_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_WdReset_OP_SET(IoHwAb_BoolType signal);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/usrostyp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _USROSTYP_H */
