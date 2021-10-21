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
 *          File:  Rte.c
 *     Workspace:  C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu Jun  1 10:59:44 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 **********************************************************************************************************************
  MISRA rule:   8.8: '%s' has external linkage but is being defined without any previous declaration.
  MISRA rule:  8.10: The object '%1s' is only referenced in the translation unit where it is defined.
  MISRA rule:  10.6: Integer literal constant is of an unsigned type but does not include a U suffix.
  MISRA rule:  13.3: Floating-point expressions shall not be tested for equality or inequality.
  MISRA rule:  14.1: The function '%1s' is defined but is not used within this project.
  MISRA rule:  14.2: This statement has no side-effect - it can be removed.
  MISRA rule:  14.3: Empty statement (';' on its own) - if this is deliberate, it is best to put ';' on a line by itself.
  MISRA rule:  18.4: An object of union type has been defined.
  MISRA rule:  19.1: #include statements in a file should only be preceded by other preprocessor directives or comments.
  MISRA rule:  19.4: Macro defines an unrecognised code-fragment.
  MISRA rule:  19.7: A function could probably be used instead of this function-like macro.
  MISRA rule:  19.8: [U] Macro argument is empty.
  MISRA rule: 12.10: The comma operator has been used outside a for-loop header.
  MISRA rule: 19.13: The # and ## preprocessor directives should not be used.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Rte_Type.h"
#include "Rte_Main.h"

#define RTE_CORE
#include "Rte_Ap_AbsHwPos.h"
#include "Rte_Ap_ActivePull.h"
#include "Rte_Ap_ApXcp.h"
#include "Rte_Ap_Assist.h"
#include "Rte_Ap_AssistFirewall.h"
#include "Rte_Ap_AssistSumnLmt.h"
#include "Rte_Ap_AvgFricLrn.h"
#include "Rte_Ap_BVDiag.h"
#include "Rte_Ap_BatteryVoltage.h"
#include "Rte_Ap_BmwHaptcFb.h"
#include "Rte_Ap_BmwRtnArbn.h"
#include "Rte_Ap_BmwTqOvrlCdng.h"
#include "Rte_Ap_ChkPtAp10.h"
#include "Rte_Ap_ChkPtAp11.h"
#include "Rte_Ap_ChkPtAp7.h"
#include "Rte_Ap_ChkPtAp8.h"
#include "Rte_Ap_ChkPtAp9.h"
#include "Rte_Ap_CtrldDisShtdn.h"
#include "Rte_Ap_CurrentEst.h"
#include "Rte_Ap_CustPL.h"
#include "Rte_Ap_Damping.h"
#include "Rte_Ap_DampingFirewall.h"
#include "Rte_Ap_DemIf.h"
#include "Rte_Ap_DiagMgr10.h"
#include "Rte_Ap_DiagMgr11.h"
#include "Rte_Ap_DiagMgr7.h"
#include "Rte_Ap_DiagMgr8.h"
#include "Rte_Ap_DiagMgr9.h"
#include "Rte_Ap_DigPhsReasDiag.h"
#include "Rte_Ap_DrvDynCtrl.h"
#include "Rte_Ap_DrvDynEnbl.h"
#include "Rte_Ap_EOTActuatorMng.h"
#include "Rte_Ap_ElecPwr.h"
#include "Rte_Ap_EtDmpFw.h"
#include "Rte_Ap_FltInjection.h"
#include "Rte_Ap_FrqDepDmpnInrtCmp.h"
#include "Rte_Ap_GenPosTraj.h"
#include "Rte_Ap_Gsod.h"
#include "Rte_Ap_HiLoadStall.h"
#include "Rte_Ap_HwPwUp.h"
#include "Rte_Ap_HystAdd.h"
#include "Rte_Ap_HystComp.h"
#include "Rte_Ap_LktoLkStr.h"
#include "Rte_Ap_LmtCod.h"
#include "Rte_Ap_LnRkCr.h"
#include "Rte_Ap_LrnEOT.h"
#include "Rte_Ap_MtrCtrlOpConv.h"
#include "Rte_Ap_MtrTempEst.h"
#include "Rte_Ap_Nhet2.h"
#include "Rte_Ap_OscTraj.h"
#include "Rte_Ap_ParamComp.h"
#include "Rte_Ap_ParkAstEnbl.h"
#include "Rte_Ap_PhaseCtrl.h"
#include "Rte_Ap_Polarity.h"
#include "Rte_Ap_PosServo.h"
#include "Rte_Ap_PrkAstMfgServCh2.h"
#include "Rte_Ap_PwrLmtFunc.h"
#include "Rte_Ap_QuadDet.h"
#include "Rte_Ap_RackLoad.h"
#include "Rte_Ap_Return.h"
#include "Rte_Ap_ReturnFirewall.h"
#include "Rte_Ap_SignlCondn.h"
#include "Rte_Ap_SrlComInput.h"
#include "Rte_Ap_SrlComInput2.h"
#include "Rte_Ap_SrlComOutput.h"
#include "Rte_Ap_SrlComOutput2.h"
#include "Rte_Ap_SrlScomSrvc.h"
#include "Rte_Ap_StOpCtrl.h"
#include "Rte_Ap_StaMd.h"
#include "Rte_Ap_StaMd11.h"
#include "Rte_Ap_StaMd7.h"
#include "Rte_Ap_StaMd8.h"
#include "Rte_Ap_StaMd9.h"
#include "Rte_Ap_StabilityComp.h"
#include "Rte_Ap_StabilityComp2.h"
#include "Rte_Ap_Sweep.h"
#include "Rte_Ap_Sweep2.h"
#include "Rte_Ap_TJADamp.h"
#include "Rte_Ap_ThrmlDutyCycle.h"
#include "Rte_Ap_TrqBasedInrtCmp.h"
#include "Rte_Ap_TrqCmdScl.h"
#include "Rte_Ap_TrqOsc.h"
#include "Rte_Ap_TuningSelAuth.h"
#include "Rte_Ap_VehCfg.h"
#include "Rte_Ap_VehPwrMd.h"
#include "Rte_Ap_VehSpdLmt.h"
#include "Rte_Ap_VltgCtrl.h"
#include "Rte_CDD.h"
#include "Rte_Cd_TurnsCounter.h"
#include "Rte_Cd_uDiag.h"
#include "Rte_Coding.h"
#include "Rte_ComM.h"
#include "Rte_DEM.h"
#include "Rte_EcuM.h"
#include "Rte_Edch.h"
#include "Rte_IoHwAb10.h"
#include "Rte_IoHwAb7.h"
#include "Rte_IoHwAbstraction.h"
#include "Rte_NxtrLibs.h"
#include "Rte_NtWrap.h"
#include "Rte_NvM.h"
#include "Rte_NvMProxy.h"
#include "Rte_RteErrata10.h"
#include "Rte_RteErrata11.h"
#include "Rte_RteErrata7.h"
#include "Rte_RteErrata8.h"
#include "Rte_RteErrata9.h"
#include "Rte_Sa_BkCpPc.h"
#include "Rte_Sa_CDDInterface10.h"
#include "Rte_Sa_CDDInterface9.h"
#include "Rte_Sa_CtrlTemp.h"
#include "Rte_Sa_HwTrq.h"
#include "Rte_Sa_HwTrq2.h"
#include "Rte_Sa_MtrCurr.h"
#include "Rte_Sa_MtrDrvDiag.h"
#include "Rte_Sa_MtrPos.h"
#include "Rte_Sa_MtrPos2.h"
#include "Rte_Sa_MtrPos3.h"
#include "Rte_Sa_MtrVel.h"
#include "Rte_Sa_MtrVel2.h"
#include "Rte_Sa_MtrVel3.h"
#include "Rte_Sa_PhaseDscnt.h"
#include "Rte_Sa_PrimaryShutdown.h"
#include "Rte_Sa_ShtdnMech.h"
#include "Rte_Sa_TmprlMon.h"
#include "Rte_Sa_TmprlMon2.h"
#include "Rte_SpiNxt.h"
#include "Rte_WdgM.h"

#include "Os.h"

/* Os.h Compatibility Check */
#ifndef RTE_OS_VERSION
# if defined (OS_AR_MAJOR_VERSION) && defined (OS_AR_MINOR_VERSION)
#  define RTE_OS_VERSION ((OS_AR_MAJOR_VERSION * 10) + OS_AR_MINOR_VERSION)
# endif
#endif
#if !defined (OS_VENDOR_ID)
# define RTE_INCOMPATIBLE_OS
#else
# if (OS_VENDOR_ID != RTE_VENDOR_ID)
#  define RTE_INCOMPATIBLE_OS
# endif
#endif
#if defined (RTE_INCOMPATIBLE_OS)
# error "Incompatible AUTOSAR OS. The MICROSAR RTE requires MICROSAR OS if memory protection is enabled!"
#endif

#include "Rte_Hook.h"

#include "Com.h"

/* Com.h Compatibility Check */
#ifndef RTE_COM_VERSION
# if defined (IL_VECTOR_VERSION)
#  define RTE_COM_VERSION 20U
# else
#  if defined (IL_ASRCOM_VERSION)
#   if (IL_ASRCOM_VERSION < 0x0201U)
#    define RTE_COM_VERSION 20U
#   endif
#  endif
# endif
# if defined (COM_AR_MAJOR_VERSION) && defined (COM_AR_MINOR_VERSION)
#  define RTE_COM_VERSION ((COM_AR_MAJOR_VERSION * 10) + COM_AR_MINOR_VERSION)
# endif
#endif
#ifndef RTE_COM_VERSION
# define RTE_COM_VERSION 33U
#endif

#if (RTE_COM_VERSION == 20U) || (RTE_COM_VERSION == 21U)
# define RTE_COM_SENDCAST(x) (x)
#else
# define RTE_COM_SENDCAST(x)
#endif

#if defined(IL_VECTOR_VERSION) || defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

/* AUTOSAR 2.1 compatibility */
#if !defined (STATIC) && defined (_STATIC_)
# define STATIC _STATIC_
#endif

#ifndef V_USE_DUMMY_STATEMENT
# define V_USE_DUMMY_STATEMENT STD_OFF
#endif


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
#ifdef RTE_DISABLE_ISUPDATED

typedef unsigned int Rte_BitType;
#endif


/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_STATE_UNINIT (0U)
#define RTE_STATE_INIT   (1U)

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"

STATIC VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT;

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/


#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_AlignedHwPos_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelAuthority_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelPosition_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HwTargetAuthority_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_ICMMtrPosMRF_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_AbsHwPos_LTVehCenterComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_AbsHwPos_RacktoVehCntrOffset_Cnt_u16 = 4095U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_AbsHwPos_RevOffsetState_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ActivePull_PullCmpLongTermIntgtrSt_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ActivePull_PullCmpShoTermIntgtrSt_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ActivePull_PullCompCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_ApXcp_ActiveTunOvrPtrAddr_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(TuningSessionAddrPtrEnum, RTE_VAR_INIT) Rte_ApXcp_TuningSessionActPtr_Cnt_u8 = 255U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_BmwTqOvrlCdng_OutpTqOvrl_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TJADamp_CustomDamp_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(TJAStateType, RTE_VAR_INIT) Rte_Ap_TJADamp_TJAState_Cnt_enum = 1U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Assist_BaseAssistCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AssistFirewall_AsstFirewallActive_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AssistFirewall_CombinedAssist_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AssistSumnLmt_LimitPercentFiltered_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AssistSumnLmt_PreLimitForPower_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AssistSumnLmt_PreLimitForStall_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AssistSumnLmt_PreLimitTorque_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AvgFricLrn_EstFric_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AvgFricLrn_FricOffset_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AvgFricLrn_SatEstFric_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_BatteryVoltage_SysC_Vecu_Volt_f32 = 5.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_BatteryVoltage_Vecu_Volt_f32 = 5.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_BatteryVoltage_VswitchClosed_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_BmwHaptcFb_HaptcFbSt_Cnt_u08 = 1U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_BmwHaptcFb_TrqOscAmp_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_BmwHaptcFb_TrqOscEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_BmwHaptcFb_TrqOscFallingRampRate_MtrNmpS_f32 = -4400.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_BmwHaptcFb_TrqOscFreq_Hz_f32 = 50.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_BmwHaptcFb_TrqOscRisngRampRate_MtrNmpS_f32 = 4400.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_BmwRtnArbn_ReturnCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface10_DutyCycleSmall_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface10_ExpectedOnTimeA_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface10_ExpectedOnTimeB_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface10_ExpectedOnTimeC_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface10_MeasuredOnTimeA_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface10_MeasuredOnTimeB_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface10_MeasuredOnTimeC_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_ActPullCompLrnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_AvgFrcLrnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_DampingSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_DftAsstTbl_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_DrivingDynSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface9_DwnldAsstGain_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_EOTImpactSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_EOTThermalSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_EngONSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_FirewallSrlComSrvDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_FreqDepDmpSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_HysAddSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_HystCompSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface9_IgnCnt_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_KinIntDiagSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_LimitSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_LrnPnCenterEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_MfgDiagInhibit_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_ModIdxSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_MultIgnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(ManufModeType, RTE_VAR_INIT) Rte_CDDInterface9_NxtrMEC_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_OscTrajEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_ParkAstSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_PosTrajEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_PullCompSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_ReturnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_RxMsgsSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface9_SrlComSvcDft_Cnt_b32 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_CDDInterface9_TcFlashErrors_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_TcFlashVerify_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_TcReflashActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_ThermalDCSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_TrqRmpSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface9_WhlImbRejSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CtrldDisShtdn_CtrldDmpStsCmp_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrldDisShtdn_SysC_CRFMtrTrqCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrldDisShtdn_SysC_MRFMtrTrqCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrentEst_EstPkCurr_AmpSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrentEst_FiltEstPkCurr_AmpSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrentEst_IdEst_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CustPL_CCLMSAActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CustPL_CCLTrqRamp_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CustPL_CustCurrLmt_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Damping_DampingCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DampingFirewall_CombinedDamping_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DiagMgr10_DiagRampRate_XpmS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DiagMgr10_DiagRampValue_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsDefTemp_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsWIRDisable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DrvDynCtrl_AssistDDFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DrvDynCtrl_DampingDDFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DrvDynCtrl_ReturnDDFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DrvDynamicsEnable_DrvDynActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(QU_SER_STMOM_STMOM_DV_ACT, RTE_VAR_INIT) Rte_DrvDynamicsEnable_DrvDynInterfaceState_Cnt_u08 = 128U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DrvDynamicsEnable_OpTrqOvRmpInEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_EOTActuatorMng_AssistEOTDamping_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_EOTActuatorMng_AssistEOTGain_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_EOTActuatorMng_AssistEOTLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt4, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_ALIVE = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Edch_EventStatusIpduDataType, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_DATA = {
  {15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U}
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt6, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_MUX_IMME = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt6, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_MUX_MAX = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ElecPwr_ElecPower_Watts_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ElecPwr_SupplyCur_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_EtDmpFw_EOTDampingLtd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_GenPosTraj_PosTrajHwAngle_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HiLoadStall_AssistStallLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_HwPwUp_MtrDrvrInitStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_HwPwUp_PwrDiscATestStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_HwPwUp_PwrDiscBTestStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_HwPwUp_TMFTestStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HwTrq_AnaDiffHwTrq_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HwTrq_AnaHwTorque_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HwTrq_SysCAnaHwTorque_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HwTrq_T1TrimVal_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HwTrq_T2TrimVal_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HwTrq2_SysCHwTorqueSqd_HwNmSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HystAdd_HysAddHwTrq_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HystComp_HysteresisComp_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_ADCMtrCurr1_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_Batt_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_BattSwitched_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_InvCos2Scaled_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_InvSin2Scaled_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_PDChrgPmpFdbkADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_PDSuplFdbkADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_SysCT1ADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_SysCT2ADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_SysCVSwitch_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_T1ADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_T2ADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_TemperatureADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LktoLkStr_LrnPnCntrCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LktoLkStr_LrnPnCntrHwCenter_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LktoLkStr_LrnPnCntrHwTravel_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(LktoLkStrStateType, RTE_VAR_INIT) Rte_LktoLkStr_LrnPnCntrState_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LmtCod_EOTGainLtd_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LmtCod_EOTLimitLtd_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LmtCod_OutputRampMultLtd_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LmtCod_StallLimitLtd_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LmtCod_ThermalLimitLtd_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LmtCod_VehSpdLimitLtd_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LnRkCr_RackCenter_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_LnRkCr_RackCntrComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_LnRkCr_RackCntrMtrAngleError_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_LnRkCr_RackCntrMtrAngleFound_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_LrnEOT_CCWFound_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LrnEOT_CCWPosition_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_LrnEOT_CWFound_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_LrnEOT_CWPosition_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_MtrCtrlOpConv_CommutationOffset_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrCtrlOpConv_DeadTimeComp_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrCtrlOpConv_ModulationIndexFinal_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt16, RTE_VAR_INIT) Rte_MtrCtrlOpConv_MtrTrqCmdSign_Cnt_s16 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_MtrCtrlOpConv_PhaseAdvanceFinal_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrCurr_MtrCurrDax_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrCurr_MtrCurrQax_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrCurr_RawCurrFiltered_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_MtrCurr_ValidSampleFlag_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(FETPHASETYPE_ENUM, RTE_VAR_INIT) Rte_MtrDrvDiag_FETFaultPhase_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(FETFAULTTYPE_ENUM, RTE_VAR_INIT) Rte_MtrDrvDiag_FETFaultType_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_MtrDrvDiag_MtrDrvrInitComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos_AlignedCumMtrPosMRF_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos_CumMtrPosCRF_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos_CumMtrPosMRF_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos_SysCCumMtrPosCRF_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos_SysCCumMtrPosMRF_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos2_CorrectedMtrPos_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos2_CosTheta1_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos2_MechMtrPos_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos2_SinTheta1_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos2_SysCCorrectedMtrPos_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrPos2_SysCMechMtrPos_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_AssistMechTempEst_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_CuTempEst_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_MagTempEst_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_SiTempEst_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrVel_CRFMotorVel_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrVel_HandwheelVel_HwRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_MtrVel_HwVelValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrVel_MRFMotorVel_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrVel_MRFMotorVelUnfiltered_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrVel_SysCHandwheelVel_HwRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrVel_SysCMotorVelMRF_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrVel2_SysCDiagHandWheelVel_HwRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrVel2_SysCDiagMtrVelMRF_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(OscTrajCmdStateType, RTE_VAR_INIT) Rte_OscTraj_OscTrajState_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_OscTraj_OscillateHwAngle_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ParamComp_EstKe_VpRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ParamComp_EstLd_Henry_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ParamComp_EstLq_Henry_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ParamComp_EstR_Ohm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ParamComp_ExpIq_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_ParkAssistEnable_PosServEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ParkAssistEnable_PosServoHwAngle_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(QU_SER_WSTA_EST_FTAX, RTE_VAR_INIT) Rte_ParkAssistEnable_PrkAssistState_Cnt_u08 = 128U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_PhaseDscnt_PDActivateTest_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt16, RTE_VAR_INIT) Rte_PhaseDscnt_PDPhaseAdvSelect_Cnt_s16 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PhaseDscnt_PDTestModIndex_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_PhaseDscnt_PhsDiscTestComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_AssistAssyPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_HwPosPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_HwTrqPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_MtrElecMechPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_MtrPosPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_MtrVelPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt32, RTE_VAR_INIT) Rte_Polarity_SysC_MtrElecMechPolarity_Cnt_s32 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PosServo_PosSrvoCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PosServo_PosSrvoReturnSclFct_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PosServo_PosSrvoSmoothEnable_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_PrkAstMfgServCh2_SysCLnPnCtrCCDisable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_PrkAstMfgServCh2_SysCPosServCCDisable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PwrLmtFunc_AssistPowerLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PwrLmtFunc_MtrEnvSpd_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PwrLmtFunc_PowerLimitPerc_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_QuadDet_InstMtrDir_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_QuadDet_MtrQuad_Cnt_u08 = 1U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_RackLoad_RackLoad_kN_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Return_ReturnCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ReturnFirewall_LimitedReturn_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_BkCpPc_PwrDiscATestComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_BkCpPc_PwrDiscBTestComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_BkCpPc_PwrDiscClosed_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_EstimdLatAcce_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SignlCondn_EstimdLatAcceValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SignlCondn_VehicleLatAcceValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_VehicleLatAccel_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_VehicleLonAccel_KphpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SignlCondn_VehicleLonAccelValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_VehicleSpeed_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SignlCondn_VehicleSpeedValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_VehicleYawRate_DegpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SignlCondn_VehicleYawRateValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(CTR_ERRM_BN_U, RTE_VAR_INIT) Rte_SrlComInput_ErrmBnU_Cnt_u8 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_HaptcFbIntenNr_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_HaptcFbPatNr_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaptcFbPatSigVld_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_SrlComInput_IgnTimeOff_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(ST_ILK_ERRM_FZM, RTE_VAR_INIT) Rte_SrlComInput_IlkErrmFzm_Cnt_u8 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_ReturnOffset_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_ACLNY_MASSCNTR, RTE_VAR_INIT) Rte_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR = {
  0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_CON_VEH, RTE_VAR_INIT) Rte_SrlComInput_SrlComCONVEH_CON_VEH = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_OFFS_QUAD_EPS, RTE_VAR_INIT) Rte_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS = {
  127U, 32767U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_TAR_QTA_STRMOM_DV, RTE_VAR_INIT) Rte_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 2000U, 0U
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_TAR_STMOM_DV_ACT, RTE_VAR_INIT) Rte_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT = {
  0U, 0U, 2000U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_V_VEH, RTE_VAR_INIT) Rte_SrlComInput_SrlComSGVVEH_SG_V_VEH = {
  15U, FALSE, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_ST_CENG, RTE_VAR_INIT) Rte_SrlComInput_SrlComSTCENG_ST_CENG = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt4, RTE_VAR_INIT) Rte_SrlComInput_SrlComSTKL_ST_KL = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(New_Coding_79, RTE_VAR_INIT) Rte_SrlComInput_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP = 3U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_VYAW_VEH, RTE_VAR_INIT) Rte_SrlComInput_SrlComVYAWVEH_VYAW_VEH = {
  0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SupplyCurrLmt_Amp_f32 = 166.67F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_VINValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_VehTimeValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_FRVldVehSpd_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComAssistScaleFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt16, RTE_VAR_INIT) Rte_SrlComInput2_SrlComCRFRevOffset_Rev_s16 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComDampingScaleFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComEngCrank_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_ST_CENG, RTE_VAR_INIT) Rte_SrlComInput2_SrlComEngDrvStatus_ST_CENG = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComInputTorqueOverlay_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComPrkAstHwAngle_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComPrkAstInvalid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComReturnScaleFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(ST_OFFS_QUAD_EPS, RTE_VAR_INIT) Rte_SrlComInput2_SrlComRevOffsetSts_Cnt_u08 = 8U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(New_Coding_64, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(DVCO_VEH, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehDrvCondition_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(ST_V_VEH_NSS, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehNearStandstill_Cnt_u08 = 15U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehSpd_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehYawRate_DegpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(QU_V_VEH_COG, RTE_VAR_INIT) Rte_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_TJADampSclRqst_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(TJAStateType, RTE_VAR_INIT) Rte_SrlComInput2_TJAStateRqst_Cnt_enum = 1U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_VehSpdValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComOutput_AVLFORCGRDTxConf_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComOutput_AVLSTMOMTxConf_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(RT_SG_AVL_PO_EPS, RTE_VAR_INIT) Rte_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS = {
  0U, 32767U, 0U, 0U, 0U, 2046U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(New_Coding_39, RTE_VAR_INIT) Rte_SrlComOutput2_SrlComAVLPOEPS_TRGG_ENGTORQ_EPS = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(RT_SG_AVL_FORC_GRD, RTE_VAR_INIT) Rte_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD = {
  0U, 2023U, 0U, 120U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(RT_SG_AVL_STMOM_DV_ACT, RTE_VAR_INIT) Rte_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT = {
  0U, 2000U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_DISP_CC_EPS, RTE_VAR_INIT) Rte_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SG_DT_EST, RTE_VAR_INIT) Rte_SrlComOutput2_SrlComDTEST_DT_EST = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(RT_SG_ST_EST, RTE_VAR_INIT) Rte_SrlComOutput2_SrlComSTEST_ST_EST = {
  0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(RT_SG_SU_EPS, RTE_VAR_INIT) Rte_SrlComOutput2_SrlComSUEPS_SU_EPS = {
  0U, 0U, 0U, 0U, 0U, 0U
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_StOpCtrl_OutputRampMult_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_StOpCtrl_RampDwnStatusComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_StaMd_InitiatePwrDnFastWrite_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_StaMd_InitiatePwrDnNormalWrite_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_StaMd_PwrDnFastWriteComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_StabilityComp_AssistCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_StabilityComp2_SysAssistCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sweep_OutputHwTrq_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sweep2_OutputMtrTrq_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ThrmlDutyCycle_DutyCycleLevel_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ThrmlDutyCycle_ThermLimitPerc_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ThrmlDutyCycle_ThermalLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_TmprlMon_TMFTestComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_TrqBasedInrtCmp_HighFreqAssist_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_TrqOsc_TrqOscActv_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_TrqOsc_TrqOscCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_TrqOsc_TrqOscDCExceeded_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_TuningSelAuth_ActiveTunPers_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_TuningSelAuth_ActiveTunSet_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_TurnsCounter_TCMtrPosOffsMRF_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_TurnsCounter_TcActivePN_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_TurnsCounter_TcActivePNVldCnt_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(TurnsCntrValStateType, RTE_VAR_INIT) Rte_TurnsCounter_TurnsCntrValidity_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CADASIF_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CASSISTMSA_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehCfg_CBATCURLIMITCURRENT_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_VehCfg_CDISPCCDRDY02_Cnt_u08 = 1U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CDRVDYNMSG_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CEFANMSG_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CEPSPWRMAX_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CEVIIF_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CFACTORIF_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CFRCOMPIF_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CHWACORRECTION_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CHWANGLEIF_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CHWTORQUEIF_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CMTTORQUEIF_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CPLCOMPIF_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CSELRETURN_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_VehCfg_CSELTUNINGBASE_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_VehCfg_CSELTUNINGSPORT_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_VehCfg_CSELTUNINGSVT_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_VehCfg_DesiredTunPers_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_VehCfg_DesiredTunSet_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(EnergyModeStateType, RTE_VAR_INIT) Rte_VehCfg_EnergyModeState_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_TxDebugMsgEn_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehPwrMd_ATermActive_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehPwrMd_CTermActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(MSA_Cmd_Type, RTE_VAR_INIT) Rte_VehPwrMd_MSACommand_MSACmd_enum = 3U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehPwrMd_OperRampRate_XpmS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehPwrMd_OperRampValue_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehSpdLmt_AstVehSpdLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_ModIdx_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt16, RTE_VAR_INIT) Rte_VltgCtrl_PhsAdv_Cnt_s16 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_TermA_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_TermBSS_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_TermBTOT_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_TermXd_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_TermXq_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_TermY_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_TermZ_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt16, RTE_VAR_INIT) Rte_VltgCtrl_UnCorrPhsAdv_Cnt_s16 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_VdTerm_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VltgCtrl_VqTerm_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_ActivePull_PullCmpCustLrngDi_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ActivePull_PullCmpLongTermIntgtrStOffs_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ActivePull_PullCmpShoTermIntgtrStOffs_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Assist_IpTrqOvr_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Assist_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AssistSumnLmt_WhlImbRejCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_AmbTemp_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DampingFirewall_VehicleLonAccel_KphpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DampingFirewall_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_FrqDepDmpnInrtCmp_VehicleLonAccel_KphpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_FrqDepDmpnInrtCmp_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_HwTrq_AbsPosStepSignal_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HystComp_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_LrnEOT_DiagStsHwPosDis_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_MtrCurr_PADelta1_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_AmbTemp_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_MtrTempEst_EngTemp_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_MtrTempEst_ScomAMDefeat_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_MtrTempEst_ScomTempDataRcvd_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_ParkAssistEnable_PAEnableRqst_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_ParkAssistEnable_PAErrInterfaceActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ParkAssistEnable_PAHWAngleRqst_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_BkCpPc_OVERRIDESIGDIAGADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_BkCpPc_PMOSDIAGADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_SrlComVehLatAccel_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_SrlComVehLonAccel_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SignlCondn_SrlComVehLonAccelValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_SrlComVehYawRate_DegpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"



/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_SINELKPTBL_ULS_F32 = {
  0.0F, 0.00818114F, 0.016361732F, 0.024541229F, 0.032719083F, 0.040894747F, 0.049067674F, 0.057237317F, 0.065403129F, 
  0.073564564F, 0.081721074F, 0.089872115F, 0.09801714F, 0.106155605F, 0.114286965F, 0.122410675F, 0.130526192F, 
  0.138632973F, 0.146730475F, 0.154818155F, 0.162895473F, 0.170961889F, 0.179016861F, 0.187059852F, 0.195090322F, 
  0.203107734F, 0.211111552F, 0.21910124F, 0.227076263F, 0.235036087F, 0.24298018F, 0.250908009F, 0.258819045F, 
  0.266712758F, 0.274588618F, 0.2824461F, 0.290284677F, 0.298103825F, 0.30590302F, 0.31368174F, 0.321439465F, 
  0.329175676F, 0.336889853F, 0.344581482F, 0.352250048F, 0.359895037F, 0.367515937F, 0.375112238F, 0.382683432F, 
  0.390229013F, 0.397748475F, 0.405241314F, 0.41270703F, 0.420145122F, 0.427555093F, 0.434936447F, 0.44228869F, 
  0.44961133F, 0.456903876F, 0.46416584F, 0.471396737F, 0.478596082F, 0.485763394F, 0.492898192F, 0.5F, 0.507068342F, 
  0.514102744F, 0.521102737F, 0.528067851F, 0.53499762F, 0.541891581F, 0.548749271F, 0.555570233F, 0.562354009F, 
  0.569100146F, 0.575808191F, 0.582477697F, 0.589108216F, 0.595699305F, 0.602250522F, 0.608761429F, 0.615231591F, 
  0.621660573F, 0.628047947F, 0.634393284F, 0.64069616F, 0.646956153F, 0.653172843F, 0.659345815F, 0.665474656F, 
  0.671558955F, 0.677598305F, 0.683592302F, 0.689540545F, 0.695442635F, 0.701298178F, 0.707106781F, 0.712868056F, 
  0.718581618F, 0.724247083F, 0.729864073F, 0.735432211F, 0.740951125F, 0.746420446F, 0.751839808F, 0.757208847F, 
  0.762527204F, 0.767794524F, 0.773010453F, 0.778174644F, 0.783286749F, 0.788346428F, 0.79335334F, 0.798307152F, 
  0.803207532F, 0.80805415F, 0.812846685F, 0.817584813F, 0.822268219F, 0.826896589F, 0.831469612F, 0.835986984F, 
  0.840448401F, 0.844853565F, 0.849202182F, 0.853493959F, 0.85772861F, 0.861905852F, 0.866025404F, 0.870086991F, 
  0.874090342F, 0.878035187F, 0.881921264F, 0.885748312F, 0.889516075F, 0.893224301F, 0.896872742F, 0.900461152F, 
  0.903989293F, 0.907456928F, 0.910863825F, 0.914209756F, 0.917494496F, 0.920717827F, 0.923879533F, 0.926979401F, 
  0.930017224F, 0.932992799F, 0.935905927F, 0.938756413F, 0.941544065F, 0.944268698F, 0.94693013F, 0.949528181F, 
  0.952062678F, 0.954533451F, 0.956940336F, 0.95928317F, 0.961561798F, 0.963776066F, 0.965925826F, 0.968010935F, 
  0.970031253F, 0.971986645F, 0.973876979F, 0.97570213F, 0.977461975F, 0.979156396F, 0.98078528F, 0.982348519F, 
  0.983846006F, 0.985277642F, 0.986643332F, 0.987942984F, 0.98917651F, 0.990343829F, 0.991444861F, 0.992479535F, 
  0.993447779F, 0.99434953F, 0.995184727F, 0.995953314F, 0.996655239F, 0.997290457F, 0.997858923F, 0.998360601F, 
  0.998795456F, 0.99916346F, 0.999464588F, 0.999698819F, 0.999866138F, 0.999966534F, 1.0F
};
CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_TANLKPTBL_ULS_F32 = {
  0.004090638F, 0.012272462F, 0.02045593F, 0.028642137F, 0.036832181F, 0.045027163F, 0.053228185F, 0.061436353F, 
  0.069652776F, 0.077878569F, 0.086114851F, 0.094362747F, 0.102623388F, 0.110897912F, 0.119187464F, 0.127493199F, 
  0.135816279F, 0.144157876F, 0.152519173F, 0.160901363F, 0.16930565F, 0.177733252F, 0.1861854F, 0.194663336F, 
  0.203168319F, 0.211701624F, 0.22026454F, 0.228858373F, 0.237484449F, 0.24614411F, 0.254838719F, 0.26356966F, 
  0.272338336F, 0.281146175F, 0.289994626F, 0.298885164F, 0.307819289F, 0.316798527F, 0.325824432F, 0.334898586F, 
  0.344022602F, 0.353198123F, 0.362426827F, 0.371710423F, 0.381050656F, 0.390449308F, 0.399908199F, 0.409429188F, 
  0.419014177F, 0.42866511F, 0.438383974F, 0.448172804F, 0.458033683F, 0.467968746F, 0.477980176F, 0.488070214F, 
  0.498241156F, 0.508495358F, 0.518835235F, 0.529263268F, 0.539782003F, 0.550394056F, 0.561102113F, 0.571908936F, 
  0.582817365F, 0.593830322F, 0.604950811F, 0.616181926F, 0.627526852F, 0.638988871F, 0.650571362F, 0.662277811F, 
  0.674111811F, 0.686077068F, 0.698177407F, 0.710416776F, 0.722799253F, 0.735329049F, 0.748010517F, 0.760848156F, 
  0.77384662F, 0.787010724F, 0.80034545F, 0.813855957F, 0.827547589F, 0.841425884F, 0.855496581F, 0.869765633F, 
  0.884239215F, 0.898923737F, 0.913825852F, 0.928952473F, 0.944310785F, 0.959908255F, 0.97575265F, 0.991852054F, 
  1.008214881F, 1.024849894F, 1.041766226F, 1.058973397F, 1.076481336F, 1.094300405F, 1.112441422F, 1.130915688F, 
  1.149735011F, 1.168911743F, 1.188458804F, 1.208389721F, 1.228718659F, 1.249460468F, 1.270630717F, 1.292245742F, 
  1.314322696F, 1.336879599F, 1.359935394F, 1.383510008F, 1.407624417F, 1.432300717F, 1.4575622F, 1.483433437F, 
  1.509940366F, 1.53711039F, 1.564972483F, 1.593557306F, 1.622897326F, 1.65302696F, 1.683982719F, 1.715803371F, 
  1.74853012F, 1.782206799F, 1.816880088F, 1.852599743F, 1.889418859F, 1.927394157F, 1.966586293F, 2.007060212F, 
  2.048885533F, 2.092136977F, 2.136894845F, 2.183245548F, 2.231282201F, 2.281105287F, 2.332823403F, 2.386554093F, 
  2.442424793F, 2.500573891F, 2.561151937F, 2.624323002F, 2.690266237F, 2.759177648F, 2.831272122F, 2.906785762F, 
  2.985978571F, 3.069137557F, 3.156580334F, 3.248659312F, 3.345766601F, 3.448339762F, 3.556868595F, 3.671903171F, 
  3.7940634F, 3.924050484F, 4.062660691F, 4.210802034F, 4.369514589F, 4.539995414F, 4.723629328F, 4.92202723F, 
  5.137074201F, 5.370990435F, 5.626409169F, 5.90647743F, 6.214987771F, 6.556552741F, 6.936839169F, 7.362887641F, 
  7.843555652F, 8.390144119F, 9.01730236F, 9.744367451F, 10.59740238F, 11.61239886F, 12.84050299F, 14.35692958F, 
  16.27700796F, 18.78703932F, 22.20881656F, 27.15017067F, 34.91359651F, 48.88558064F, 81.48324021F, 244.460629F, 
  244.460629F
};
CONST(Edch_EventStatusIpduDataType, RTE_CONST) Rte_C_ST_DIAG_OBD_DATA_INIT_VAL = {
  {15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U}
};
CONST(RT_SG_AVL_FORC_GRD, RTE_CONST) Rte_C_RT_SG_AVL_FORC_GRD = {
  0U, 2023U, 0U, 120U, 0U, 0U
};
CONST(RT_SG_AVL_PO_EPS, RTE_CONST) Rte_C_RT_SG_AVL_PO_EPS = {
  0U, 32767U, 0U, 0U, 0U, 2046U, 0U, 0U
};
CONST(RT_SG_AVL_STMOM_DV_ACT, RTE_CONST) Rte_C_RT_SG_AVL_STMOM_DV_ACT = {
  0U, 2000U, 0U, 0U, 0U
};
CONST(RT_SG_ST_EST, RTE_CONST) Rte_C_RT_SG_ST_EST_INIT = {
  0U, 0U, 0U, 0U, 0U, 0U
};
CONST(RT_SG_SU_EPS, RTE_CONST) Rte_C_RT_SG_SU_EPS_INIT = {
  0U, 0U, 0U, 0U, 0U, 0U
};
CONST(RT_VIN_NO_VECH, RTE_CONST) Rte_C_RT_VIN_NO_VECH = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
CONST(SG_ACLNY_MASSCNTR, RTE_CONST) Rte_SG_ACLNY_MASSCNTR_INIT = {
  0U, 0U, 0U, 0U, 0U, 0U
};
CONST(SG_ANFRAGE_DSC_Modul, RTE_CONST) Rte_C_RT_SG_ANFRAGE_DSC_Modul = {
  1U, 0U
};
CONST(SG_ANFRAGE_EPS, RTE_CONST) Rte_C_RT_SG_ANFRAGE_EPS = {
  0U, 1U
};
CONST(SG_ANFRAGE_SAS, RTE_CONST) Rte_C_RT_SG_ANFRAGE_SAS = {
  0U, 1U
};
CONST(SG_ANFRAGE_ZGW, RTE_CONST) Rte_C_RT_SG_ANFRAGE_ZGW = {
  0U, 1U
};
CONST(SG_CON_VEH, RTE_CONST) Rte_SG_CON_VEH_INIT = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
CONST(SG_DISP_CC_EPS, RTE_CONST) Rte_SG_DISP_CC_EPS_INIT = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
CONST(SG_DT_EST, RTE_CONST) Rte_SG_DT_EST_INIT = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
CONST(SG_OFFS_QUAD_EPS, RTE_CONST) Rte_C_RT_OFFS_QUAD_EPS = {
  127U, 32767U, 0U, 0U, 0U
};
CONST(SG_ST_CENG, RTE_CONST) Rte_C_ST_CENG_INIT = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
CONST(SG_TAR_QTA_STRMOM_DV, RTE_CONST) Rte_C_RT_TAR_QTA_STRMOM_DV = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 2000U, 0U
};
CONST(SG_TAR_STMOM_DV_ACT, RTE_CONST) Rte_C_RT_TAR_STMOM_DV_ACT = {
  0U, 0U, 2000U, 0U, 0U, 0U
};
CONST(SG_VYAW_VEH, RTE_CONST) Rte_SG_VYAW_VEH_INIT = {
  0U, 0U, 0U, 0U, 0U, 0U
};
CONST(SG_V_VEH, RTE_CONST) Rte_C_RT_V_VEH = {
  15U, FALSE, 0U, 0U, 0U, 0U, 0U
};
CONST(SysOutpCpbySig_Str, RTE_CONST) Rte_T_HWPOSNCOMPINIT_HWDEG_STR = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"

VAR(EOLTrqStepType, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_EOLTrqStepData;
VAR(HwTrqScale_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_HwTrqScaleData;
VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_HwTrqTrimData;
VAR(ShCurrCal_DataType, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_MtrCurr_ShCurrCal;
VAR(EOLTurnsCntrCals_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_TurnsCounter_EOLTurnsCntrCals;

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"

VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_ActivePull_PullCmpLTComp_HwNm_f32;
VAR(AvgFricLrnType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_AvgFricLrn_AvgFricLrnData;
VAR(RackCenterType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_LnRkCr_LearnedRackCntr;
VAR(ThrmlDutyCycle_FltStVal_Datatype, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_ThrmlDutyCycle_ThrmlDutyCycle_FltStVal;
VAR(TuningSelectParam, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_VehCfg_PrevVldTuningSel;

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"

VAR(Float, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_TrqCmdScl_TorqueCmdSF_Uls_f32;
VAR(UInt16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Polarity_k_SystemPolarity_Cnt_b16;
VAR(AbsHwPosTrim_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_AbsHwPos_Trim;
VAR(EOTLearned_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_LrnEOT_LearnedEOT;
VAR(MtrPosCal_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_MtrPos_MtrPosSnsr_EOLData;
VAR(EOLNomMtrParamType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_ParamComp_EOLNomMtrParam;

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags for each Rte_Feedback function
 *********************************************************************************************************************/


typedef struct
{
  Rte_BitType Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack : 1;
} Rte_Ap_9_AckFlagsType;

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_9_AckFlagsType, RTE_VAR_INIT) Rte_Ap_9_AckFlags = {
  1,
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_9_AckFlagsInit() (Rte_MemClr(&Rte_Ap_9_AckFlags, sizeof(Rte_Ap_9_AckFlagsType)))


/**********************************************************************************************************************
 * Timeout Flags for each external Rx Signals with aliveTimeout != 0
 *********************************************************************************************************************/

typedef struct
{
  Rte_BitType Rte_RxTimeout_AVL_STEA_PNI_OFFS : 1;
  Rte_BitType Rte_RxTimeout_BE_CHOV_CLU_VE_DYNMC_DXP : 1;
  Rte_BitType Rte_RxTimeout_CTR_ACDU_IVIB_STW : 1;
  Rte_BitType Rte_RxTimeout_CTR_DIM_DSE_EXMI : 1;
  Rte_BitType Rte_RxTimeout_CTR_PRG_IVIB_STW : 1;
  Rte_BitType Rte_RxTimeout_CTR_PSDU_IVIB_STW : 1;
  Rte_BitType Rte_RxTimeout_CTR_VIB_STW : 1;
  Rte_BitType Rte_RxTimeout_CTR_WARN_DIR_VIB_EPS : 1;
  Rte_BitType Rte_RxTimeout_CTR_WARN_ILVL_VIB_EPS : 1;
  Rte_BitType Rte_RxTimeout_CTR_WARN_ILVL_VIB_STW : 1;
  Rte_BitType Rte_RxTimeout_CTR_WARN_LGA_DSE_1_LH : 1;
  Rte_BitType Rte_RxTimeout_CTR_WARN_LGA_DSE_1_RH : 1;
  Rte_BitType Rte_RxTimeout_CTR_WARN_PTRN_VIB_EPS : 1;
  Rte_BitType Rte_RxTimeout_ENERG_AVAI_ARS : 1;
  Rte_BitType Rte_RxTimeout_FACT_MO_STE_SO_DXP : 1;
  Rte_BitType Rte_RxTimeout_MAX_I_LD_SPEC_ARS : 1;
  Rte_BitType Rte_RxTimeout_MAX_I_RECUP_SPEC_ARS : 1;
  Rte_BitType Rte_RxTimeout_MAX_I_SPEC_BAX_STE : 1;
  Rte_BitType Rte_RxTimeout_MAX_I_SPEC_EPS : 1;
  Rte_BitType Rte_RxTimeout_MILE_KM : 1;
  Rte_BitType Rte_RxTimeout_QU_DGR_AISP_ENERG : 1;
  Rte_BitType Rte_RxTimeout_SG_ACLNY_MASSCNTR : 1;
  Rte_BitType Rte_RxTimeout_SG_CON_VEH : 1;
  Rte_BitType Rte_RxTimeout_SG_FAHRGESTELLNUMMER : 1;
  Rte_BitType Rte_RxTimeout_SG_OFFS_QUAD_EPS : 1;
  Rte_BitType Rte_RxTimeout_SG_ST_CENG : 1;
  Rte_BitType Rte_RxTimeout_SG_TAR_QTA_STRMOM_DV : 1;
  Rte_BitType Rte_RxTimeout_SG_VYAW_VEH : 1;
  Rte_BitType Rte_RxTimeout_SG_V_VEH : 1;
  Rte_BitType Rte_RxTimeout_ST_ILK_ERRM_FZM : 1;
  Rte_BitType Rte_RxTimeout_SU_CLU_ASS_LIBE : 1;
  Rte_BitType Rte_RxTimeout_SU_CLU_PARASS_DXP : 1;
  Rte_BitType Rte_RxTimeout_SU_CLU_STMOM_SFE_DXP : 1;
  Rte_BitType Rte_RxTimeout_SU_CLU_TROPT : 1;
  Rte_BitType Rte_RxTimeout_SU_CLU_VE_DYNMC_DXP : 1;
  Rte_BitType Rte_RxTimeout_SU_FN_EDP_DXP : 1;
  Rte_BitType Rte_RxTimeout_SU_FN_LCS_DXP : 1;
  Rte_BitType Rte_RxTimeout_SU_FN_LCS_UD_DXP : 1;
} Rte_Ap_9_RxTimeoutFlagsType;

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_9_RxTimeoutFlagsType, RTE_VAR_ZERO_INIT) Rte_Ap_9_RxTimeoutFlags = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_9_RxTimeoutFlagsInit() (Rte_MemClr(&Rte_Ap_9_RxTimeoutFlags, sizeof(Rte_Ap_9_RxTimeoutFlagsType)))


#ifndef RTE_DISABLE_ISUPDATED

/**********************************************************************************************************************
 * Update Flags for each Receiver with enableUpdate != 0
 *********************************************************************************************************************/

# define RTE_START_SEC_VAR_Ap_10_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"

VAR(Rte_Ap_10_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_Ap_10_RxUpdateFlags = {
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

# define RTE_STOP_SEC_VAR_Ap_10_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"


# define Rte_Ap_10_RxUpdateFlagsInit() (Rte_MemClr(&Rte_Ap_10_RxUpdateFlags, sizeof(Rte_Ap_10_RxUpdateFlagsType)))
# define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"

VAR(Rte_Ap_9_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_Ap_9_RxUpdateFlags = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

# define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"


# define Rte_Ap_9_RxUpdateFlagsInit() (Rte_MemClr(&Rte_Ap_9_RxUpdateFlags, sizeof(Rte_Ap_9_RxUpdateFlagsType)))
#endif /* !defined(RTE_DISABLE_ISUPDATED) */


/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_100ms_10, RTE_VAR_NOINIT) Rte_Task_100ms_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_100ms_7, RTE_VAR_NOINIT) Rte_Task_100ms_7;
#define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_100ms_8, RTE_VAR_NOINIT) Rte_Task_100ms_8;
#define RTE_STOP_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_100ms_9, RTE_VAR_NOINIT) Rte_Task_100ms_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_10msA_10, RTE_VAR_NOINIT) Rte_Task_10msA_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_10msA_9, RTE_VAR_NOINIT) Rte_Task_10msA_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_10msB_10, RTE_VAR_NOINIT) Rte_Task_10msB_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_10msB_9, RTE_VAR_NOINIT) Rte_Task_10msB_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_10ms_7, RTE_VAR_NOINIT) Rte_Task_10ms_7;
#define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_1ms_10, RTE_VAR_NOINIT) Rte_Task_1ms_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_2msA_9, RTE_VAR_NOINIT) Rte_Task_2msA_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_2ms_11, RTE_VAR_NOINIT) Rte_Task_2ms_11;
#define RTE_STOP_SEC_VAR_Ap_11_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_2ms_7, RTE_VAR_NOINIT) Rte_Task_2ms_7;
#define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_2ms_8, RTE_VAR_NOINIT) Rte_Task_2ms_8;
#define RTE_STOP_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_4ms_10, RTE_VAR_NOINIT) Rte_Task_4ms_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_4ms_7, RTE_VAR_NOINIT) Rte_Task_4ms_7;
#define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_4ms_8, RTE_VAR_NOINIT) Rte_Task_4ms_8;
#define RTE_STOP_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_4ms_9, RTE_VAR_NOINIT) Rte_Task_4ms_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_5ms_9, RTE_VAR_NOINIT) Rte_Task_5ms_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_InitA_10, RTE_VAR_NOINIT) Rte_Task_InitA_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_InitA_7, RTE_VAR_NOINIT) Rte_Task_InitA_7;
#define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_InitA_9, RTE_VAR_NOINIT) Rte_Task_InitA_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_InitB_10, RTE_VAR_NOINIT) Rte_Task_InitB_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_InitB_7, RTE_VAR_NOINIT) Rte_Task_InitB_7;
#define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_InitB_9, RTE_VAR_NOINIT) Rte_Task_InitB_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Init_8, RTE_VAR_NOINIT) Rte_Task_Init_8;
#define RTE_STOP_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Trgd_10, RTE_VAR_NOINIT) Rte_Task_Trgd_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Trns_11, RTE_VAR_NOINIT) Rte_Task_Trns_11;
#define RTE_STOP_SEC_VAR_Ap_11_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Trns_7, RTE_VAR_NOINIT) Rte_Task_Trns_7;
#define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Trns_9, RTE_VAR_NOINIT) Rte_Task_Trns_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * Buffer for inter-runnable variables
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

VAR(Float, RTE_VAR_INIT) Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32_Task_100ms_10 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32_Task_2ms_10 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32 = 0.0F;

#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

VAR(UInt32, RTE_VAR_INIT) Rte_Irv_NxtrLibs_Time_mS_u32 = 0U;

#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"

STATIC FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16 num);
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode nextMode);
STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode previousMode);
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd11_SystemState11_Mode(Rte_ModeType_StaMd_Mode nextMode);
STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd11_SystemState11_Mode(Rte_ModeType_StaMd_Mode previousMode);
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd7_SystemState7_Mode(Rte_ModeType_StaMd_Mode nextMode);
STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd7_SystemState7_Mode(Rte_ModeType_StaMd_Mode previousMode);
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd8_SystemState8_Mode(Rte_ModeType_StaMd_Mode nextMode);
STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd8_SystemState8_Mode(Rte_ModeType_StaMd_Mode previousMode);
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode nextMode);
STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode previousMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

typedef struct
{
  Rte_ModeType_EcuM_Mode Rte_ModeQueue[2];
  uint8 Rte_ModeQueueReadCtr;
  uint8 Rte_ModeQueueWriteCtr;
} Rte_ModeInfoType_EcuM_currentMode_currentMode;

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_EcuM_currentMode_currentMode, RTE_VAR_INIT) Rte_ModeInfo_EcuM_currentMode_currentMode = {
  {
    RTE_MODE_EcuM_Mode_STARTUP,
    RTE_MODE_EcuM_Mode_STARTUP
  },
  0,
  0
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_EcuM_Mode, RTE_VAR_INIT) Rte_ModeMachine_EcuM_currentMode_currentMode = RTE_MODE_EcuM_Mode_STARTUP;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

typedef struct
{
  Rte_ModeType_StaMd_Mode Rte_ModeQueue[1+1];
} Rte_ModeInfoType_StaMd_SystemState_Mode;

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_StaMd_SystemState_Mode, RTE_VAR_INIT) Rte_ModeInfo_StaMd_SystemState_Mode = {
  {
    RTE_MODE_StaMd_Mode_WARMINIT,
    RTE_MODE_StaMd_Mode_WARMINIT
  }
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_StaMd_SystemState_Mode = RTE_TRANSITION_StaMd_Mode;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

typedef struct
{
  Rte_ModeType_StaMd_Mode Rte_ModeQueue[1+1];
} Rte_ModeInfoType_StaMd11_SystemState11_Mode;

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_StaMd11_SystemState11_Mode, RTE_VAR_INIT) Rte_ModeInfo_StaMd11_SystemState11_Mode = {
  {
    RTE_MODE_StaMd_Mode_WARMINIT,
    RTE_MODE_StaMd_Mode_WARMINIT
  }
};
#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_StaMd11_SystemState11_Mode = RTE_TRANSITION_StaMd_Mode;
#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

typedef struct
{
  Rte_ModeType_StaMd_Mode Rte_ModeQueue[1+1];
} Rte_ModeInfoType_StaMd7_SystemState7_Mode;

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_StaMd7_SystemState7_Mode, RTE_VAR_INIT) Rte_ModeInfo_StaMd7_SystemState7_Mode = {
  {
    RTE_MODE_StaMd_Mode_WARMINIT,
    RTE_MODE_StaMd_Mode_WARMINIT
  }
};
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_StaMd7_SystemState7_Mode = RTE_TRANSITION_StaMd_Mode;
#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

typedef struct
{
  Rte_ModeType_StaMd_Mode Rte_ModeQueue[1+1];
} Rte_ModeInfoType_StaMd8_SystemState8_Mode;

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_StaMd8_SystemState8_Mode, RTE_VAR_INIT) Rte_ModeInfo_StaMd8_SystemState8_Mode = {
  {
    RTE_MODE_StaMd_Mode_WARMINIT,
    RTE_MODE_StaMd_Mode_WARMINIT
  }
};
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_StaMd8_SystemState8_Mode = RTE_TRANSITION_StaMd_Mode;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

typedef struct
{
  Rte_ModeType_StaMd_Mode Rte_ModeQueue[1+1];
} Rte_ModeInfoType_StaMd9_SystemState9_Mode;

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_StaMd9_SystemState9_Mode, RTE_VAR_INIT) Rte_ModeInfo_StaMd9_SystemState9_Mode = {
  {
    RTE_MODE_StaMd_Mode_WARMINIT,
    RTE_MODE_StaMd_Mode_WARMINIT
  }
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_StaMd9_SystemState9_Mode = RTE_TRANSITION_StaMd_Mode;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_EcuM_currentMode_currentMode[6] =
{
  (EventMaskType) 0, /* POST_RUN */
  Rte_Ev_Run_SrlComOutput_SrlComOutput_Init1, /* RUN */
  (EventMaskType) 0, /* SHUTDOWN */
  (EventMaskType) 0, /* SLEEP */
  (EventMaskType) 0, /* STARTUP */
  (EventMaskType) 0  /* WAKE_SLEEP */
};


CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_StaMd_SystemState_Mode[4] =
{
  (EventMaskType) 0, /* DISABLE */
  Rte_Ev_Run_DiagMgr10_DiagMgr10_Trns, /* OFF */
  Rte_Ev_Run_Nhet2_Nhet2_Trns2, /* OPERATE */
  (EventMaskType) 0  /* WARMINIT */
};

CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_StaMd_SystemState_Mode[4] =
{
  Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_DISABLE, /* DISABLE */
  Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OFF, /* OFF */
  Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OPERATE, /* OPERATE */
  Rte_Ev_Run_RteErrata10_RteErrata10_Trns  /* WARMINIT */
};


CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_StaMd11_SystemState11_Mode[4] =
{
  (EventMaskType) 0, /* DISABLE */
  Rte_Ev_Run_DiagMgr11_DiagMgr11_Trns, /* OFF */
  (EventMaskType) 0, /* OPERATE */
  (EventMaskType) 0  /* WARMINIT */
};

CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_StaMd11_SystemState11_Mode[4] =
{
  Rte_Ev_Run_RteErrata11_RteErrata11_Trns, /* DISABLE */
  Rte_Ev_Run_RteErrata11_RteErrata11_Trns, /* OFF */
  Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_OPERATE, /* OPERATE */
  Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_WARMINIT  /* WARMINIT */
};


CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_StaMd7_SystemState7_Mode[4] =
{
  (EventMaskType) 0, /* DISABLE */
  Rte_Ev_Run_DiagMgr7_DiagMgr7_Trns, /* OFF */
  (EventMaskType) 0, /* OPERATE */
  (EventMaskType) 0  /* WARMINIT */
};

CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_StaMd7_SystemState7_Mode[4] =
{
  Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE, /* DISABLE */
  Rte_Ev_Run_RteErrata7_RteErrata7_Trns, /* OFF */
  Rte_Ev_Run_RteErrata7_RteErrata7_Trns, /* OPERATE */
  Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_WARMINIT  /* WARMINIT */
};


CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_StaMd8_SystemState8_Mode[4] =
{
  (EventMaskType) 0, /* DISABLE */
  Rte_Ev_Run_DiagMgr8_DiagMgr8_Trns, /* OFF */
  (EventMaskType) 0, /* OPERATE */
  (EventMaskType) 0  /* WARMINIT */
};

CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_StaMd8_SystemState8_Mode[4] =
{
  Rte_Ev_Run_RteErrata8_RteErrata8_Trns, /* DISABLE */
  Rte_Ev_Run_RteErrata8_RteErrata8_Trns, /* OFF */
  Rte_Ev_Run_RteErrata8_RteErrata8_Trns, /* OPERATE */
  Rte_Ev_Run_RteErrata8_RteErrata8_Trns  /* WARMINIT */
};


CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_StaMd9_SystemState9_Mode[4] =
{
  Rte_Ev_Run_HwPwUp_HwPwUp_Trns1, /* DISABLE */
  Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OFF, /* OFF */
  Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE, /* OPERATE */
  (EventMaskType) 0  /* WARMINIT */
};

CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_StaMd9_SystemState9_Mode[4] =
{
  Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_DISABLE, /* DISABLE */
  Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF, /* OFF */
  Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE, /* OPERATE */
  Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_WARMINIT  /* WARMINIT */
};


#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * Trigger Disable Flags
 *********************************************************************************************************************/

#define Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_DiagMgr9_DiagMgr_Per2 1
#define Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 2
#define Rte_TriggerDisableMaxCount_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2 1
#define Rte_TriggerDisableMaxCount_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 2
#define Rte_TriggerDisableMaxCount_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3 2
#define Rte_TriggerDisableMaxCount_Task_10ms_7_Rte_Trigger1_CustPL_CustPL_Per1 1
#define Rte_TriggerDisableMaxCount_Task_10ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per2 1
#define Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per2 1
#define Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1 1
#define Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2 2
#define Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_DrvDynamicsEnable_DrvDynEnbl_Per1 1
#define Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per1 1
#define Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 2
#define Rte_TriggerDisableMaxCount_Task_2ms_8_Rte_Trigger1_Gsod_Gsod_Per1 1
#define Rte_TriggerDisableMaxCount_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 2

typedef struct
{
  Rte_BitType Rte_Trigger_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1 : 2;
} Rte_Ap_10_TriggerDisableFlagsType;
typedef struct
{
  Rte_BitType Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2 : 2;
} Rte_Ap_11_TriggerDisableFlagsType;
typedef struct
{
  Rte_BitType Rte_Trigger_Task_10ms_7_Rte_Trigger1_CustPL_CustPL_Per1 : 1;
  Rte_BitType Rte_Trigger_Task_10ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_7_Rte_Trigger1_DrvDynamicsEnable_DrvDynEnbl_Per1 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per1 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 : 2;
  Rte_BitType Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 : 2;
} Rte_Ap_7_TriggerDisableFlagsType;
typedef struct
{
  Rte_BitType Rte_Trigger_Task_2ms_8_Rte_Trigger1_Gsod_Gsod_Per1 : 1;
} Rte_Ap_8_TriggerDisableFlagsType;
typedef struct
{
  Rte_BitType Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 : 2;
  Rte_BitType Rte_Trigger_Task_100ms_9_Rte_Trigger1_DiagMgr9_DiagMgr_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 : 2;
} Rte_Ap_9_TriggerDisableFlagsType;

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_10_TriggerDisableFlagsType, RTE_VAR_INIT) Rte_Ap_10_TriggerDisableFlags = {
  1,
  1,
  1,
  1,
  1
};

#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_10_TriggerDisableFlagsInit() (Rte_MemClr(&Rte_Ap_10_TriggerDisableFlags, sizeof(Rte_Ap_10_TriggerDisableFlagsType)))

#define RTE_START_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_11_TriggerDisableFlagsType, RTE_VAR_INIT) Rte_Ap_11_TriggerDisableFlags = {
  1,
  0,
  1
};

#define RTE_STOP_SEC_VAR_Ap_11_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_11_TriggerDisableFlagsInit() (Rte_MemClr(&Rte_Ap_11_TriggerDisableFlags, sizeof(Rte_Ap_11_TriggerDisableFlagsType)))

#define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_7_TriggerDisableFlagsType, RTE_VAR_INIT) Rte_Ap_7_TriggerDisableFlags = {
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  1
};

#define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_7_TriggerDisableFlagsInit() (Rte_MemClr(&Rte_Ap_7_TriggerDisableFlags, sizeof(Rte_Ap_7_TriggerDisableFlagsType)))

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_8_TriggerDisableFlagsType, RTE_VAR_INIT) Rte_Ap_8_TriggerDisableFlags = {
  0
};

#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_8_TriggerDisableFlagsInit() (Rte_MemClr(&Rte_Ap_8_TriggerDisableFlags, sizeof(Rte_Ap_8_TriggerDisableFlagsType)))

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_9_TriggerDisableFlagsType, RTE_VAR_INIT) Rte_Ap_9_TriggerDisableFlags = {
  1,
  0,
  1,
  1,
  0,
  1
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_9_TriggerDisableFlagsInit() (Rte_MemClr(&Rte_Ap_9_TriggerDisableFlags, sizeof(Rte_Ap_9_TriggerDisableFlagsType)))


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if (OSTICKDURATION < 1000)
# error "The MICROSAR RTE does not support OSTICKDURATION < 1000 ns"
#endif

#define RTE_TICKDURATION (OSTICKDURATION / 1000U)
#define RTE_USEC(val) ((TickType)((uint32)(val) / (uint32)RTE_TICKDURATION))
#define RTE_MSEC(val) ((TickType)RTE_CONST_MSEC_##val)
#define RTE_SEC(val)  ((TickType)RTE_CONST_SEC_##val)

#define RTE_MSEC_BASE 1000UL
#define RTE_SEC_BASE  1000000UL

#if ((0) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_0 (((uint32)(0) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_0 ((uint32)(0) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_0 ((uint32)(0) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((1) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_1 (((uint32)(1) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_1 ((uint32)(1) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_1 ((uint32)(1) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((10) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_10 (((uint32)(10) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_10 ((uint32)(10) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_10 ((uint32)(10) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((100) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_100 (((uint32)(100) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_100 ((uint32)(100) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_100 ((uint32)(100) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((160) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_160 (((uint32)(160) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_160 ((uint32)(160) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_160 ((uint32)(160) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((2) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_2 (((uint32)(2) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_2 ((uint32)(2) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_2 ((uint32)(2) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((4) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_4 (((uint32)(4) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_4 ((uint32)(4) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_4 ((uint32)(4) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((5) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_5 (((uint32)(5) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_5 ((uint32)(5) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_5 ((uint32)(5) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)


/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h"

#if (RTE_TICKDURATION > (100UL * 1000UL))
# error "The cycle time of runnable(s) <DiagMgr10_Per>, <uDiagStaticRegs_Per>, <ChkPtAp10_100msEnd_Per>, <NtWrap_Per1>, <ParamComp_Per2>, <ChkPtAp10_100msStart_Per>, <CurrentEst_Per2> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (100UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp11_100msStart_Per>, <ChkPtAp11_100msEnd_Per>, <DiagMgr11_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (100UL * 1000UL))
# error "The cycle time of runnable(s) <MtrTempEst_Per1>, <CtrlTemp_Per2>, <ChkPtAp7_100msStart_Per>, <HwTrq_Per3>, <ChkPtAp7_100msEnd_Per>, <DiagMgr7_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (100UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp8_100msEnd_Per>, <ChkPtAp8_100msStart_Per>, <DiagMgr8_Per>, <HwTrq2_Per3> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (100UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp9_100msEnd_Per>, <DiagMgr9_Per>, <Runnable_MainFunction>, <DiagMgr_Per2>, <ThrmlDutyCycle_Per1>, <RE_Main>, <ChkPtAp9_100msStart_Per>, <ActivePull_Per3>, <RE_CalculateSubCvn> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (10UL * 1000UL))
# error "The cycle time of runnable(s) <ShtdnMech_Per1>, <uDiagVIM_Per>, <AbsHwPos_Per2>, <ChkPtAp10_10msEndB_Per>, <uDiagECC_Per>, <PhaseDscnt_Per2>, <LrnEOT_Per1>, <AssistSumnLmt_Per2>, <ChkPtAp10_10msStartB_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (10UL * 1000UL))
# error "The cycle time of runnable(s) <ApXcp_Per1>, <AvgFricLrn_Per1>, <VehCfg_Per1>, <SrlComSrvc_Per1>, <ChkPtAp9_10msEndB_Per>, <ChkPtAp9_10msStartB_Per>, <RackLoad_Per1>, <ElecPwr_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (10UL * 1000UL))
# error "The cycle time of runnable(s) <PwrLmtFunc_Per2>, <ChkPtAp7_10msStart_Per>, <TmprlMon_Per3>, <CustPL_Per1>, <TuningSelAuth_Per1>, <ChkPtAp7_10msEnd_Per>, <BVDiag_Per1>, <TurnsCounter_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (1UL * 1000UL))
# error "The cycle time of runnable(s) <uDiagLossOfExec_Per2>, <PhaseCtrl_Per1>, <QuadDet_Per1>, <VltgCtrl_Per4>, <MtrCtrlOpConv_Per1>, <CDDInterface10_Per2>, <VltgCtrl_Per2>, <MtrPos_Per2>, <MtrVel_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (1UL * 1000UL))
# error "The cycle time of runnable(s) <DAQ_1msTL> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <VehPwrMd_Per1>, <Assist_Per1>, <BmwRtnArbn_Per1>, <ChkPtAp9_2msStartA_Per>, <TrqBasedInrtCmp_Per1>, <HiLoadStall_Per1>, <StaMd9_Per1>, <HystComp_Per1>, <ChkPtAp9_2msEndA_Per>, <FrqDepDmpnInrtCmp_Per1>, <BmwHaptcFb_Per1>, <ActivePull_Per1>, <HwPwUp_Per1>, <ActivePull_Per2>, <HystAdd_Per1>, <VehSpdLmt_Per1>, <StabilityComp2_Per1>, <Damping_Per1>, <TJADamp_Per1>, <SrlComInput_Per1>, <Return_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <DAQ_2msTL>, <ChkPtAp9_2msEndB_Per>, <ChkPtAp9_2msStartB_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp10_2msEnd_Per>, <AbsHwPos_Per1>, <BmwTqOvrlCdng_Per1>, <EtDmpFw_Per1>, <CDDInterface10_Per3>, <PhaseDscnt_Per1>, <VltgCtrl_Per1>, <DiagMgr_Per1>, <StaMd_Per1>, <TmprlMon2_Per1>, <ChkPtAp10_2msStart_Per>, <CtrldDisShtdn_Per1>, <EOTActuatorMng_Per1>, <VltgCtrl_Per3>, <TrqCmdScl_Per1>, <TrqOsc_Per1>, <LmtCod_Per1>, <StabilityComp_Per1>, <CurrentEst_Per1>, <SrlComInput2_Per1>, <SystemTime_Per1>, <AssistSumnLmt_Per1>, <DampingFirewall_Per1>, <StOpCtrl_Per1>, <CDDInterface10_Per1>, <ParamComp_Per1>, <Sweep2_Per1>, <AssistFirewall_Per1>, <ReturnFirewall_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp11_2msEnd_Per>, <DigPhsReasDiag_Per1>, <MtrDrvDiag_Per2>, <MtrDrvDiag_Per1>, <StaMd11_Per1>, <ChkPtAp11_2msStart_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <BatteryVoltage_Per1>, <DrvDynEnbl_Per1>, <FltInjection_Per1>, <TmprlMon_Per2>, <MtrCurr_Per1>, <ChkPtAp7_2msStart_Per>, <CtrlTemp_Per1>, <PosServo_Per1>, <HwTrq_Per1>, <IoHwAb7_FdbkPathAdc>, <TmprlMon_Per1>, <DrvDynCtrl_Per1>, <SignlCondn_Per1>, <IoHwAb7_FwdPathAdc>, <ParkAstEnbl_Per1>, <GenPosTraj_Per1>, <MtrPos2_Per1>, <LktoLkStr_Per1>, <OscTraj_Per1>, <PwrLmtFunc_Per1>, <BkCpPc_Per1>, <StaMd7_Per1>, <Sweep_Per1>, <ChkPtAp7_2msEnd_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp8_2msStart_Per>, <ChkPtAp8_2msEnd_Per>, <StaMd8_Per1>, <HwTrq2_Per1>, <MtrVel2_Per1>, <Gsod_Per1>, <MtrPos3_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (4UL * 1000UL))
# error "The cycle time of runnable(s) <MtrVel_Per2>, <ChkPtAp10_4msEnd_Per>, <uDiagLossOfExec_Per3>, <ChkPtAp10_4msStart_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (4UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp7_4msEnd_Per>, <HwTrq_Per2>, <ChkPtAp7_4msStart_Per>, <BatteryVoltage_Per2> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (4UL * 1000UL))
# error "The cycle time of runnable(s) <HwTrq2_Per2>, <PrkAstMfgServCh2_Per1>, <MtrVel2_Per2>, <ChkPtAp8_4msEnd_Per>, <MtrPos3_Per2>, <ChkPtAp8_4msStart_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (4UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp9_4msEnd_Per>, <ChkPtAp9_4msStart_Per>, <LnRkCr_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (160UL * 1000UL))
# error "The cycle time of runnable(s) <RE_SendCyclic> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (5UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp9_5msEnd_Per>, <SrlComOutput_Per2>, <CDDInterface9_Per1>, <ChkPtAp9_5msStart_Per> is smaller than the tick time of the operating system."
#endif

STATIC FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16 num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = ptr;
  uint16 i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  /* activate the tasks */
  Rte_Task_Activate(Task_5ms_9);
  (void)ActivateTask(Task_5ms_9);
  Rte_Task_Activate(Task_InitA_10);
  (void)ActivateTask(Task_InitA_10);
  Rte_Task_Activate(Task_InitA_7);
  (void)ActivateTask(Task_InitA_7);
  Rte_Task_Activate(Task_InitA_9);
  (void)ActivateTask(Task_InitA_9);
  Rte_Task_Activate(Task_InitB_10);
  (void)ActivateTask(Task_InitB_10);
  Rte_Task_Activate(Task_InitB_7);
  (void)ActivateTask(Task_InitB_7);
  Rte_Task_Activate(Task_InitB_9);
  (void)ActivateTask(Task_InitB_9);
  Rte_Task_Activate(Task_Init_11);
  (void)ActivateTask(Task_Init_11);
  Rte_Task_Activate(Task_Init_8);
  (void)ActivateTask(Task_Init_8);
  Rte_Task_Activate(Task_Trgd_10);
  (void)ActivateTask(Task_Trgd_10);
  Rte_Task_Activate(Task_Trns_10);
  (void)ActivateTask(Task_Trns_10);
  Rte_Task_Activate(Task_Trns_11);
  (void)ActivateTask(Task_Trns_11);
  Rte_Task_Activate(Task_Trns_7);
  (void)ActivateTask(Task_Trns_7);
  Rte_Task_Activate(Task_Trns_8);
  (void)ActivateTask(Task_Trns_8);
  Rte_Task_Activate(Task_Trns_9);
  (void)ActivateTask(Task_Trns_9);

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_10_0_100ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(100));
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_11_0_100ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(100));
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_7_0_100ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(100));
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_8_0_100ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(100));
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_9_0_100ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(100));
  (void)SetRelAlarm(Rte_Al_TE_Task_10msB_10_0_10ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(10));
  (void)SetRelAlarm(Rte_Al_TE_Task_10msB_9_0_10ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(10));
  (void)SetRelAlarm(Rte_Al_TE_Task_10ms_7_0_10ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(10));
  (void)SetRelAlarm(Rte_Al_TE_Task_1ms_10_0_1ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(1));
  (void)SetRelAlarm(Rte_Al_TE_ApXcp_DAQ_1msTL, RTE_MSEC(0) + (TickType)1, RTE_MSEC(1));
  (void)SetRelAlarm(Rte_Al_TE_Task_2msA_9_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_2msB_9_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_10_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_11_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_7_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_8_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_4ms_10_0_4ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(4));
  (void)SetRelAlarm(Rte_Al_TE_Task_4ms_7_0_4ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(4));
  (void)SetRelAlarm(Rte_Al_TE_Task_4ms_8_0_4ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(4));
  (void)SetRelAlarm(Rte_Al_TE_Task_4ms_9_0_4ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(4));
  (void)SetRelAlarm(Rte_Al_TE_Edch_RE_SendCyclic, RTE_MSEC(0) + (TickType)1, RTE_MSEC(160));
  (void)SetRelAlarm(Rte_Al_TE_Task_5ms_9_0_5ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(5));

  /* mode management initialization part 2 */

  Rte_Task_SetEvent(Task_Trns_10, Rte_ModeEntryEventMask_StaMd_SystemState_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);
  (void)SetEvent(Task_Trns_10, Rte_ModeEntryEventMask_StaMd_SystemState_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);

  Rte_Task_SetEvent(Task_Trns_11, Rte_ModeEntryEventMask_StaMd11_SystemState11_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);
  (void)SetEvent(Task_Trns_11, Rte_ModeEntryEventMask_StaMd11_SystemState11_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);

  Rte_Task_SetEvent(Task_Trns_7, Rte_ModeEntryEventMask_StaMd7_SystemState7_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);
  (void)SetEvent(Task_Trns_7, Rte_ModeEntryEventMask_StaMd7_SystemState7_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);

  Rte_Task_SetEvent(Task_Trns_8, Rte_ModeEntryEventMask_StaMd8_SystemState8_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);
  (void)SetEvent(Task_Trns_8, Rte_ModeEntryEventMask_StaMd8_SystemState8_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);

  Rte_Task_SetEvent(Task_Trns_9, Rte_ModeEntryEventMask_StaMd9_SystemState9_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);
  (void)SetEvent(Task_Trns_9, Rte_ModeEntryEventMask_StaMd9_SystemState9_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);


  Rte_InitState = RTE_STATE_INIT;

  return RTE_E_OK;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_10_0_100ms);
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_11_0_100ms);
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_7_0_100ms);
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_8_0_100ms);
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_9_0_100ms);
  (void)CancelAlarm(Rte_Al_TE_Task_10msB_10_0_10ms);
  (void)CancelAlarm(Rte_Al_TE_Task_10msB_9_0_10ms);
  (void)CancelAlarm(Rte_Al_TE_Task_10ms_7_0_10ms);
  (void)CancelAlarm(Rte_Al_TE_Task_1ms_10_0_1ms);
  (void)CancelAlarm(Rte_Al_TE_ApXcp_DAQ_1msTL);
  (void)CancelAlarm(Rte_Al_TE_Task_2msA_9_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_2msB_9_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_10_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_11_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_7_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_8_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_4ms_10_0_4ms);
  (void)CancelAlarm(Rte_Al_TE_Task_4ms_7_0_4ms);
  (void)CancelAlarm(Rte_Al_TE_Task_4ms_8_0_4ms);
  (void)CancelAlarm(Rte_Al_TE_Task_4ms_9_0_4ms);
  (void)CancelAlarm(Rte_Al_TE_Edch_RE_SendCyclic);
  (void)CancelAlarm(Rte_Al_TE_Task_5ms_9_0_5ms);

  Rte_InitState = RTE_STATE_UNINIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  Rte_InitState = RTE_STATE_UNINIT;
  /* reset Rx Timeout Flags */
  Rte_Ap_9_RxTimeoutFlagsInit();

#ifndef RTE_DISABLE_ISUPDATED
  /* initialize flags for update handling */
  Rte_Ap_10_RxUpdateFlagsInit();
  Rte_Ap_9_RxUpdateFlagsInit();
#endif

  /* set default values for internal data */
  Rte_AbsHwPos_AlignedHwPos_HwDeg_f32 = 0.0F;
  Rte_AbsHwPos_HandwheelAuthority_Uls_f32 = 0.0F;
  Rte_AbsHwPos_HandwheelPosition_HwDeg_f32 = 0.0F;
  Rte_AbsHwPos_HwTargetAuthority_Uls_f32 = 0.0F;
  Rte_AbsHwPos_ICMMtrPosMRF_Deg_f32 = 0.0F;
  Rte_AbsHwPos_LTVehCenterComplete_Cnt_lgc = FALSE;
  Rte_AbsHwPos_RacktoVehCntrOffset_Cnt_u16 = 4095U;
  Rte_AbsHwPos_RevOffsetState_Cnt_u08 = 0U;
  Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 = 0.0F;
  Rte_ActivePull_PullCmpLongTermIntgtrSt_HwNm_f32 = 0.0F;
  Rte_ActivePull_PullCmpShoTermIntgtrSt_HwNm_f32 = 0.0F;
  Rte_ActivePull_PullCompCmd_MtrNm_f32 = 0.0F;
  Rte_ApXcp_ActiveTunOvrPtrAddr_Cnt_u32 = 0U;
  Rte_ApXcp_TuningSessionActPtr_Cnt_u8 = 255U;
  Rte_Ap_BmwTqOvrlCdng_OutpTqOvrl_MtrNm_f32 = 0.0F;
  Rte_Ap_TJADamp_CustomDamp_MtrNm_f32 = 0.0F;
  Rte_Ap_TJADamp_TJAState_Cnt_enum = 1U;
  Rte_Assist_BaseAssistCmd_MtrNm_f32 = 0.0F;
  Rte_AssistFirewall_AsstFirewallActive_Uls_f32 = 0.0F;
  Rte_AssistFirewall_CombinedAssist_MtrNm_f32 = 0.0F;
  Rte_AssistSumnLmt_LimitPercentFiltered_Uls_f32 = 0.0F;
  Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32 = 0.0F;
  Rte_AssistSumnLmt_PreLimitForPower_MtrNm_f32 = 0.0F;
  Rte_AssistSumnLmt_PreLimitForStall_MtrNm_f32 = 0.0F;
  Rte_AssistSumnLmt_PreLimitTorque_MtrNm_f32 = 0.0F;
  Rte_AvgFricLrn_EstFric_HwNm_f32 = 0.0F;
  Rte_AvgFricLrn_FricOffset_HwNm_f32 = 0.0F;
  Rte_AvgFricLrn_SatEstFric_HwNm_f32 = 0.0F;
  Rte_BatteryVoltage_SysC_Vecu_Volt_f32 = 5.0F;
  Rte_BatteryVoltage_Vecu_Volt_f32 = 5.0F;
  Rte_BatteryVoltage_VswitchClosed_Cnt_lgc = FALSE;
  Rte_BmwHaptcFb_HaptcFbSt_Cnt_u08 = 1U;
  Rte_BmwHaptcFb_TrqOscAmp_MtrNm_f32 = 0.0F;
  Rte_BmwHaptcFb_TrqOscEnable_Cnt_lgc = FALSE;
  Rte_BmwHaptcFb_TrqOscFallingRampRate_MtrNmpS_f32 = -4400.0F;
  Rte_BmwHaptcFb_TrqOscFreq_Hz_f32 = 50.0F;
  Rte_BmwHaptcFb_TrqOscRisngRampRate_MtrNmpS_f32 = 4400.0F;
  Rte_BmwRtnArbn_ReturnCmd_MtrNm_f32 = 0.0F;
  Rte_CDDInterface10_DutyCycleSmall_Cnt_u16 = 0U;
  Rte_CDDInterface10_ExpectedOnTimeA_Cnt_u32 = 0U;
  Rte_CDDInterface10_ExpectedOnTimeB_Cnt_u32 = 0U;
  Rte_CDDInterface10_ExpectedOnTimeC_Cnt_u32 = 0U;
  Rte_CDDInterface10_MeasuredOnTimeA_Cnt_u32 = 0U;
  Rte_CDDInterface10_MeasuredOnTimeB_Cnt_u32 = 0U;
  Rte_CDDInterface10_MeasuredOnTimeC_Cnt_u32 = 0U;
  Rte_CDDInterface9_ActPullCompLrnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_AvgFrcLrnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_DampingSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_DftAsstTbl_Cnt_lgc = FALSE;
  Rte_CDDInterface9_DrivingDynSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_DwnldAsstGain_Uls_f32 = 0.0F;
  Rte_CDDInterface9_EOTImpactSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_EOTThermalSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_EngONSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_FirewallSrlComSrvDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_FreqDepDmpSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_HysAddSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_HystCompSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_IgnCnt_Cnt_u16 = 0U;
  Rte_CDDInterface9_KinIntDiagSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_LimitSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_LrnPnCenterEnable_Cnt_lgc = FALSE;
  Rte_CDDInterface9_MfgDiagInhibit_Cnt_lgc = FALSE;
  Rte_CDDInterface9_ModIdxSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_MultIgnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_NxtrMEC_Cnt_enum = 0U;
  Rte_CDDInterface9_OscTrajEnable_Cnt_lgc = FALSE;
  Rte_CDDInterface9_ParkAstSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_PosTrajEnable_Cnt_lgc = FALSE;
  Rte_CDDInterface9_PullCompSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_ReturnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_RxMsgsSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_SrlComSvcDft_Cnt_b32 = 0U;
  Rte_CDDInterface9_TcFlashErrors_Cnt_u08 = 0U;
  Rte_CDDInterface9_TcFlashVerify_Cnt_lgc = FALSE;
  Rte_CDDInterface9_TcReflashActive_Cnt_lgc = FALSE;
  Rte_CDDInterface9_ThermalDCSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_TrqRmpSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface9_WhlImbRejSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CtrlTemp_FiltMeasTemp_DegC_f32 = 0.0F;
  Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32 = 0.0F;
  Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32 = 0.0F;
  Rte_CtrldDisShtdn_CtrldDmpStsCmp_Cnt_lgc = FALSE;
  Rte_CtrldDisShtdn_SysC_CRFMtrTrqCmd_MtrNm_f32 = 0.0F;
  Rte_CtrldDisShtdn_SysC_MRFMtrTrqCmd_MtrNm_f32 = 0.0F;
  Rte_CurrentEst_EstPkCurr_AmpSq_f32 = 0.0F;
  Rte_CurrentEst_FiltEstPkCurr_AmpSq_f32 = 0.0F;
  Rte_CurrentEst_IdEst_Amp_f32 = 0.0F;
  Rte_CustPL_CCLMSAActive_Cnt_lgc = FALSE;
  Rte_CustPL_CCLTrqRamp_Uls_f32 = 1.0F;
  Rte_CustPL_CustCurrLmt_Amp_f32 = 0.0F;
  Rte_Damping_DampingCmd_MtrNm_f32 = 0.0F;
  Rte_DampingFirewall_CombinedDamping_MtrNm_f32 = 0.0F;
  Rte_DiagMgr10_DiagRampRate_XpmS_f32 = 0.0F;
  Rte_DiagMgr10_DiagRampValue_Uls_f32 = 0.0F;
  Rte_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc = FALSE;
  Rte_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc = FALSE;
  Rte_DiagMgr10_DiagStsDefTemp_Cnt_lgc = FALSE;
  Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc = FALSE;
  Rte_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc = FALSE;
  Rte_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc = FALSE;
  Rte_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc = FALSE;
  Rte_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc = FALSE;
  Rte_DiagMgr10_DiagStsWIRDisable_Cnt_lgc = FALSE;
  Rte_DrvDynCtrl_AssistDDFactor_Uls_f32 = 1.0F;
  Rte_DrvDynCtrl_DampingDDFactor_Uls_f32 = 1.0F;
  Rte_DrvDynCtrl_ReturnDDFactor_Uls_f32 = 1.0F;
  Rte_DrvDynamicsEnable_DrvDynActive_Cnt_lgc = FALSE;
  Rte_DrvDynamicsEnable_DrvDynInterfaceState_Cnt_u08 = 128U;
  Rte_DrvDynamicsEnable_OpTrqOvRmpInEnable_Cnt_lgc = FALSE;
  Rte_EOTActuatorMng_AssistEOTDamping_MtrNm_f32 = 0.0F;
  Rte_EOTActuatorMng_AssistEOTGain_Uls_f32 = 1.0F;
  Rte_EOTActuatorMng_AssistEOTLimit_MtrNm_f32 = 8.8F;
  Rte_Edch_ST_DIAG_OBD_ALIVE = 0U;
  Rte_Edch_ST_DIAG_OBD_DATA = C_ST_DIAG_OBD_DATA_INIT_VAL;
  Rte_Edch_ST_DIAG_OBD_MUX_IMME = 0U;
  Rte_Edch_ST_DIAG_OBD_MUX_MAX = 0U;
  Rte_ElecPwr_ElecPower_Watts_f32 = 0.0F;
  Rte_ElecPwr_SupplyCur_Amp_f32 = 0.0F;
  Rte_EtDmpFw_EOTDampingLtd_MtrNm_f32 = 0.0F;
  Rte_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_MtrNm_f32 = 0.0F;
  Rte_GenPosTraj_PosTrajHwAngle_HwDeg_f32 = 0.0F;
  Rte_HiLoadStall_AssistStallLimit_MtrNm_f32 = 8.8F;
  Rte_HwPwUp_MtrDrvrInitStart_Cnt_lgc = FALSE;
  Rte_HwPwUp_PwrDiscATestStart_Cnt_lgc = FALSE;
  Rte_HwPwUp_PwrDiscBTestStart_Cnt_lgc = FALSE;
  Rte_HwPwUp_TMFTestStart_Cnt_lgc = FALSE;
  Rte_HwTrq_AnaDiffHwTrq_Volt_f32 = 0.0F;
  Rte_HwTrq_AnaHwTorque_HwNm_f32 = 0.0F;
  Rte_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32 = 0.0F;
  Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc = FALSE;
  Rte_HwTrq_SysCAnaHwTorque_HwNm_f32 = 0.0F;
  Rte_HwTrq_T1TrimVal_Volt_f32 = 0.0F;
  Rte_HwTrq_T2TrimVal_Volt_f32 = 0.0F;
  Rte_HwTrq2_SysCHwTorqueSqd_HwNmSq_f32 = 0.0F;
  Rte_HystAdd_HysAddHwTrq_HwNm_f32 = 0.0F;
  Rte_HystComp_HysteresisComp_MtrNm_f32 = 0.0F;
  Rte_IoHwAb7_ADCMtrCurr1_Volt_f32 = 0.0F;
  Rte_IoHwAb7_Batt_Volt_f32 = 0.0F;
  Rte_IoHwAb7_BattSwitched_Volt_f32 = 0.0F;
  Rte_IoHwAb7_InvCos2Scaled_Volt_f32 = 0.0F;
  Rte_IoHwAb7_InvSin2Scaled_Volt_f32 = 0.0F;
  Rte_IoHwAb7_PDChrgPmpFdbkADC_Volt_f32 = 0.0F;
  Rte_IoHwAb7_PDSuplFdbkADC_Volt_f32 = 0.0F;
  Rte_IoHwAb7_SysCT1ADC_Volt_f32 = 0.0F;
  Rte_IoHwAb7_SysCT2ADC_Volt_f32 = 0.0F;
  Rte_IoHwAb7_SysCVSwitch_Volt_f32 = 0.0F;
  Rte_IoHwAb7_T1ADC_Volt_f32 = 0.0F;
  Rte_IoHwAb7_T2ADC_Volt_f32 = 0.0F;
  Rte_IoHwAb7_TemperatureADC_Volt_f32 = 0.0F;
  Rte_LktoLkStr_LrnPnCntrCmd_MtrNm_f32 = 0.0F;
  Rte_LktoLkStr_LrnPnCntrHwCenter_HwDeg_f32 = 0.0F;
  Rte_LktoLkStr_LrnPnCntrHwTravel_HwDeg_f32 = 0.0F;
  Rte_LktoLkStr_LrnPnCntrState_Cnt_enum = 0U;
  Rte_LmtCod_EOTGainLtd_Uls_f32 = 1.0F;
  Rte_LmtCod_EOTLimitLtd_MtrNm_f32 = 8.8F;
  Rte_LmtCod_OutputRampMultLtd_Uls_f32 = 0.0F;
  Rte_LmtCod_StallLimitLtd_MtrNm_f32 = 8.8F;
  Rte_LmtCod_ThermalLimitLtd_MtrNm_f32 = 8.8F;
  Rte_LmtCod_VehSpdLimitLtd_MtrNm_f32 = 8.8F;
  Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc = FALSE;
  Rte_LnRkCr_RackCenter_HwDeg_f32 = 0.0F;
  Rte_LnRkCr_RackCntrComplete_Cnt_lgc = FALSE;
  Rte_LnRkCr_RackCntrMtrAngleError_Cnt_lgc = FALSE;
  Rte_LnRkCr_RackCntrMtrAngleFound_Cnt_lgc = FALSE;
  Rte_LrnEOT_CCWFound_Cnt_lgc = FALSE;
  Rte_LrnEOT_CCWPosition_HwDeg_f32 = 0.0F;
  Rte_LrnEOT_CWFound_Cnt_lgc = FALSE;
  Rte_LrnEOT_CWPosition_HwDeg_f32 = 0.0F;
  Rte_MtrCtrlOpConv_CommutationOffset_Cnt_u16 = 0U;
  Rte_MtrCtrlOpConv_DeadTimeComp_Uls_f32 = 0.0F;
  Rte_MtrCtrlOpConv_ModulationIndexFinal_Uls_f32 = 0.0F;
  Rte_MtrCtrlOpConv_MtrTrqCmdSign_Cnt_s16 = 0;
  Rte_MtrCtrlOpConv_PhaseAdvanceFinal_Cnt_u16 = 0U;
  Rte_MtrCurr_MtrCurrDax_Amp_f32 = 0.0F;
  Rte_MtrCurr_MtrCurrQax_Amp_f32 = 0.0F;
  Rte_MtrCurr_RawCurrFiltered_Amp_f32 = 0.0F;
  Rte_MtrCurr_ValidSampleFlag_Cnt_lgc = FALSE;
  Rte_MtrDrvDiag_FETFaultPhase_Cnt_enum = 0U;
  Rte_MtrDrvDiag_FETFaultType_Cnt_enum = 0U;
  Rte_MtrDrvDiag_MtrDrvrInitComplete_Cnt_lgc = FALSE;
  Rte_MtrPos_AlignedCumMtrPosMRF_Deg_f32 = 0.0F;
  Rte_MtrPos_CumMtrPosCRF_Deg_f32 = 0.0F;
  Rte_MtrPos_CumMtrPosMRF_Deg_f32 = 0.0F;
  Rte_MtrPos_SysCCumMtrPosCRF_Deg_f32 = 0.0F;
  Rte_MtrPos_SysCCumMtrPosMRF_Deg_f32 = 0.0F;
  Rte_MtrPos2_CorrectedMtrPos_Rev_f32 = 0.0F;
  Rte_MtrPos2_CosTheta1_Volt_f32 = 0.0F;
  Rte_MtrPos2_MechMtrPos_Rev_f32 = 0.0F;
  Rte_MtrPos2_SinTheta1_Volt_f32 = 0.0F;
  Rte_MtrPos2_SysCCorrectedMtrPos_Rev_f32 = 0.0F;
  Rte_MtrPos2_SysCMechMtrPos_Rev_f32 = 0.0F;
  Rte_MtrTempEst_AssistMechTempEst_DegC_f32 = 0.0F;
  Rte_MtrTempEst_CuTempEst_DegC_f32 = 0.0F;
  Rte_MtrTempEst_MagTempEst_DegC_f32 = 0.0F;
  Rte_MtrTempEst_SiTempEst_DegC_f32 = 0.0F;
  Rte_MtrVel_CRFMotorVel_MtrRadpS_f32 = 0.0F;
  Rte_MtrVel_HandwheelVel_HwRadpS_f32 = 0.0F;
  Rte_MtrVel_HwVelValid_Cnt_lgc = FALSE;
  Rte_MtrVel_MRFMotorVel_MtrRadpS_f32 = 0.0F;
  Rte_MtrVel_MRFMotorVelUnfiltered_MtrRadpS_f32 = 0.0F;
  Rte_MtrVel_SysCHandwheelVel_HwRadpS_f32 = 0.0F;
  Rte_MtrVel_SysCMotorVelMRF_MtrRadpS_f32 = 0.0F;
  Rte_MtrVel2_SysCDiagHandWheelVel_HwRadpS_f32 = 0.0F;
  Rte_MtrVel2_SysCDiagMtrVelMRF_MtrRadpS_f32 = 0.0F;
  Rte_OscTraj_OscTrajState_Cnt_enum = 0U;
  Rte_OscTraj_OscillateHwAngle_HwDeg_f32 = 0.0F;
  Rte_ParamComp_EstKe_VpRadpS_f32 = 0.0F;
  Rte_ParamComp_EstLd_Henry_f32 = 0.0F;
  Rte_ParamComp_EstLq_Henry_f32 = 0.0F;
  Rte_ParamComp_EstR_Ohm_f32 = 0.0F;
  Rte_ParamComp_ExpIq_Amp_f32 = 0.0F;
  Rte_ParkAssistEnable_PosServEnable_Cnt_lgc = FALSE;
  Rte_ParkAssistEnable_PosServoHwAngle_HwDeg_f32 = 0.0F;
  Rte_ParkAssistEnable_PrkAssistState_Cnt_u08 = 128U;
  Rte_PhaseDscnt_PDActivateTest_Cnt_lgc = FALSE;
  Rte_PhaseDscnt_PDPhaseAdvSelect_Cnt_s16 = 0;
  Rte_PhaseDscnt_PDTestModIndex_Uls_f32 = 0.0F;
  Rte_PhaseDscnt_PhsDiscTestComplete_Cnt_lgc = FALSE;
  Rte_Polarity_AssistAssyPolarity_Cnt_s08 = 0;
  Rte_Polarity_HwPosPolarity_Cnt_s08 = 0;
  Rte_Polarity_HwTrqPolarity_Cnt_s08 = 0;
  Rte_Polarity_MtrElecMechPolarity_Cnt_s08 = 0;
  Rte_Polarity_MtrPosPolarity_Cnt_s08 = 0;
  Rte_Polarity_MtrVelPolarity_Cnt_s08 = 0;
  Rte_Polarity_SysC_MtrElecMechPolarity_Cnt_s32 = 0;
  Rte_PosServo_PosSrvoCmd_MtrNm_f32 = 0.0F;
  Rte_PosServo_PosSrvoReturnSclFct_Uls_f32 = 1.0F;
  Rte_PosServo_PosSrvoSmoothEnable_Uls_f32 = 0.0F;
  Rte_PrkAstMfgServCh2_SysCLnPnCtrCCDisable_Cnt_lgc = FALSE;
  Rte_PrkAstMfgServCh2_SysCPosServCCDisable_Cnt_lgc = FALSE;
  Rte_PwrLmtFunc_AssistPowerLimit_MtrNm_f32 = 8.8F;
  Rte_PwrLmtFunc_MtrEnvSpd_MtrRadpS_f32 = 0.0F;
  Rte_PwrLmtFunc_PowerLimitPerc_Uls_f32 = 0.0F;
  Rte_QuadDet_InstMtrDir_Cnt_s08 = 0;
  Rte_QuadDet_MtrQuad_Cnt_u08 = 1U;
  Rte_RackLoad_RackLoad_kN_f32 = 0.0F;
  Rte_Return_ReturnCmd_MtrNm_f32 = 0.0F;
  Rte_ReturnFirewall_LimitedReturn_MtrNm_f32 = 0.0F;
  Rte_Sa_BkCpPc_PwrDiscATestComplete_Cnt_lgc = FALSE;
  Rte_Sa_BkCpPc_PwrDiscBTestComplete_Cnt_lgc = FALSE;
  Rte_Sa_BkCpPc_PwrDiscClosed_Cnt_lgc = FALSE;
  Rte_SignlCondn_EstimdLatAcce_MpSecSq_f32 = 0.0F;
  Rte_SignlCondn_EstimdLatAcceValid_Cnt_lgc = FALSE;
  Rte_SignlCondn_VehicleLatAcceValid_Cnt_lgc = FALSE;
  Rte_SignlCondn_VehicleLatAccel_MpSecSq_f32 = 0.0F;
  Rte_SignlCondn_VehicleLonAccel_KphpS_f32 = 0.0F;
  Rte_SignlCondn_VehicleLonAccelValid_Cnt_lgc = FALSE;
  Rte_SignlCondn_VehicleSpeed_Kph_f32 = 0.0F;
  Rte_SignlCondn_VehicleSpeedValid_Cnt_lgc = FALSE;
  Rte_SignlCondn_VehicleYawRate_DegpS_f32 = 0.0F;
  Rte_SignlCondn_VehicleYawRateValid_Cnt_lgc = FALSE;
  Rte_SrlComInput_ErrmBnU_Cnt_u8 = 0U;
  Rte_SrlComInput_HaptcFbIntenNr_Cnt_u16 = 0U;
  Rte_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc = FALSE;
  Rte_SrlComInput_HaptcFbPatNr_Cnt_u16 = 0U;
  Rte_SrlComInput_HaptcFbPatSigVld_Cnt_lgc = FALSE;
  Rte_SrlComInput_IgnTimeOff_Cnt_u32 = 0U;
  Rte_SrlComInput_IlkErrmFzm_Cnt_u8 = 0U;
  Rte_SrlComInput_ReturnOffset_HwDeg_f32 = 0.0F;
  Rte_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR = SG_ACLNY_MASSCNTR_INIT;
  Rte_SrlComInput_SrlComCONVEH_CON_VEH = SG_CON_VEH_INIT;
  Rte_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS = C_RT_OFFS_QUAD_EPS;
  Rte_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV = C_RT_TAR_QTA_STRMOM_DV;
  Rte_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT = C_RT_TAR_STMOM_DV_ACT;
  Rte_SrlComInput_SrlComSGVVEH_SG_V_VEH = C_RT_V_VEH;
  Rte_SrlComInput_SrlComSTCENG_ST_CENG = C_ST_CENG_INIT;
  Rte_SrlComInput_SrlComSTKL_ST_KL = 0U;
  Rte_SrlComInput_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP = 3U;
  Rte_SrlComInput_SrlComVYAWVEH_VYAW_VEH = SG_VYAW_VEH_INIT;
  Rte_SrlComInput_SupplyCurrLmt_Amp_f32 = 166.67F;
  Rte_SrlComInput_VINValid_Cnt_lgc = FALSE;
  Rte_SrlComInput_VehTimeValid_Cnt_lgc = FALSE;
  Rte_SrlComInput2_FRVldVehSpd_Kph_f32 = 0.0F;
  Rte_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32 = 0.0F;
  Rte_SrlComInput2_SrlComAssistScaleFactor_Uls_f32 = 1.0F;
  Rte_SrlComInput2_SrlComCRFRevOffset_Rev_s16 = 0;
  Rte_SrlComInput2_SrlComDampingScaleFactor_Uls_f32 = 1.0F;
  Rte_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc = FALSE;
  Rte_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc = FALSE;
  Rte_SrlComInput2_SrlComEngCrank_Cnt_lgc = TRUE;
  Rte_SrlComInput2_SrlComEngDrvStatus_ST_CENG = C_ST_CENG_INIT;
  Rte_SrlComInput2_SrlComInputTorqueOverlay_HwNm_f32 = 0.0F;
  Rte_SrlComInput2_SrlComPrkAstHwAngle_HwDeg_f32 = 0.0F;
  Rte_SrlComInput2_SrlComPrkAstInvalid_Cnt_lgc = FALSE;
  Rte_SrlComInput2_SrlComReturnScaleFactor_Uls_f32 = 1.0F;
  Rte_SrlComInput2_SrlComRevOffsetSts_Cnt_u08 = 8U;
  Rte_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus = 0U;
  Rte_SrlComInput2_SrlComVehDrvCondition_Cnt_u08 = 0U;
  Rte_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32 = 0.0F;
  Rte_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc = FALSE;
  Rte_SrlComInput2_SrlComVehNearStandstill_Cnt_u08 = 15U;
  Rte_SrlComInput2_SrlComVehSpd_Kph_f32 = 0.0F;
  Rte_SrlComInput2_SrlComVehYawRate_DegpS_f32 = 0.0F;
  Rte_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc = FALSE;
  Rte_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08 = 0U;
  Rte_SrlComInput2_TJADampSclRqst_Uls_f32 = 0.0F;
  Rte_SrlComInput2_TJAStateRqst_Cnt_enum = 1U;
  Rte_SrlComInput2_VehSpdValid_Cnt_lgc = FALSE;
  Rte_SrlComOutput_AVLFORCGRDTxConf_Cnt_lgc = FALSE;
  Rte_SrlComOutput_AVLSTMOMTxConf_Cnt_lgc = FALSE;
  Rte_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS = C_RT_SG_AVL_PO_EPS;
  Rte_SrlComOutput2_SrlComAVLPOEPS_TRGG_ENGTORQ_EPS = 0U;
  Rte_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD = C_RT_SG_AVL_FORC_GRD;
  Rte_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT = C_RT_SG_AVL_STMOM_DV_ACT;
  Rte_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS = SG_DISP_CC_EPS_INIT;
  Rte_SrlComOutput2_SrlComDTEST_DT_EST = SG_DT_EST_INIT;
  Rte_SrlComOutput2_SrlComSTEST_ST_EST = C_RT_SG_ST_EST_INIT;
  Rte_SrlComOutput2_SrlComSUEPS_SU_EPS = C_RT_SG_SU_EPS_INIT;
  Rte_StOpCtrl_OutputRampMult_Uls_f32 = 0.0F;
  Rte_StOpCtrl_RampDwnStatusComplete_Cnt_lgc = FALSE;
  Rte_StaMd_InitiatePwrDnFastWrite_Cnt_lgc = FALSE;
  Rte_StaMd_InitiatePwrDnNormalWrite_Cnt_lgc = FALSE;
  Rte_StaMd_PwrDnFastWriteComplete_Cnt_lgc = FALSE;
  Rte_StabilityComp_AssistCmd_MtrNm_f32 = 0.0F;
  Rte_StabilityComp2_SysAssistCmd_MtrNm_f32 = 0.0F;
  Rte_Sweep_OutputHwTrq_HwNm_f32 = 0.0F;
  Rte_Sweep2_OutputMtrTrq_MtrNm_f32 = 0.0F;
  Rte_ThrmlDutyCycle_DutyCycleLevel_Uls_f32 = 0.0F;
  Rte_ThrmlDutyCycle_ThermLimitPerc_Uls_f32 = 0.0F;
  Rte_ThrmlDutyCycle_ThermalLimit_MtrNm_f32 = 8.8F;
  Rte_TmprlMon_TMFTestComplete_Cnt_lgc = FALSE;
  Rte_TrqBasedInrtCmp_HighFreqAssist_MtrNm_f32 = 0.0F;
  Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32 = 0.0F;
  Rte_TrqOsc_TrqOscActv_Cnt_lgc = FALSE;
  Rte_TrqOsc_TrqOscCmd_MtrNm_f32 = 0.0F;
  Rte_TrqOsc_TrqOscDCExceeded_Cnt_lgc = FALSE;
  Rte_TuningSelAuth_ActiveTunPers_Cnt_u16 = 0U;
  Rte_TuningSelAuth_ActiveTunSet_Cnt_u16 = 0U;
  Rte_TurnsCounter_TCMtrPosOffsMRF_Deg_f32 = 0.0F;
  Rte_TurnsCounter_TcActivePN_Cnt_u32 = 0U;
  Rte_TurnsCounter_TcActivePNVldCnt_Cnt_u32 = 0U;
  Rte_TurnsCounter_TurnsCntrValidity_Cnt_enum = 0U;
  Rte_VehCfg_CADASIF_Cnt_lgc = FALSE;
  Rte_VehCfg_CASSISTMSA_Cnt_lgc = FALSE;
  Rte_VehCfg_CBATCURLIMITCURRENT_Amp_f32 = 0.0F;
  Rte_VehCfg_CDISPCCDRDY02_Cnt_u08 = 1U;
  Rte_VehCfg_CDRVDYNMSG_Cnt_lgc = FALSE;
  Rte_VehCfg_CEFANMSG_Cnt_lgc = FALSE;
  Rte_VehCfg_CEPSPWRMAX_Cnt_lgc = TRUE;
  Rte_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc = FALSE;
  Rte_VehCfg_CEVIIF_Cnt_lgc = FALSE;
  Rte_VehCfg_CFACTORIF_Cnt_lgc = FALSE;
  Rte_VehCfg_CFRCOMPIF_Cnt_lgc = TRUE;
  Rte_VehCfg_CHWACORRECTION_Cnt_lgc = FALSE;
  Rte_VehCfg_CHWANGLEIF_Cnt_lgc = FALSE;
  Rte_VehCfg_CHWTORQUEIF_Cnt_lgc = FALSE;
  Rte_VehCfg_CMTTORQUEIF_Cnt_lgc = FALSE;
  Rte_VehCfg_CPLCOMPIF_Cnt_lgc = TRUE;
  Rte_VehCfg_CSELRETURN_Cnt_lgc = FALSE;
  Rte_VehCfg_CSELTUNINGBASE_Cnt_u08 = 0U;
  Rte_VehCfg_CSELTUNINGSPORT_Cnt_u08 = 0U;
  Rte_VehCfg_CSELTUNINGSVT_Cnt_u08 = 0U;
  Rte_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32 = 0.0F;
  Rte_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc = FALSE;
  Rte_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32 = 0.0F;
  Rte_VehCfg_DesiredTunPers_Cnt_u16 = 0U;
  Rte_VehCfg_DesiredTunSet_Cnt_u16 = 0U;
  Rte_VehCfg_EnergyModeState_Cnt_enum = 0U;
  Rte_VehCfg_TxDebugMsgEn_Cnt_lgc = FALSE;
  Rte_VehPwrMd_ATermActive_Cnt_lgc = TRUE;
  Rte_VehPwrMd_CTermActive_Cnt_lgc = FALSE;
  Rte_VehPwrMd_MSACommand_MSACmd_enum = 3U;
  Rte_VehPwrMd_OperRampRate_XpmS_f32 = 0.0F;
  Rte_VehPwrMd_OperRampValue_Uls_f32 = 0.0F;
  Rte_VehSpdLmt_AstVehSpdLimit_MtrNm_f32 = 8.8F;
  Rte_VltgCtrl_ModIdx_Uls_f32 = 0.0F;
  Rte_VltgCtrl_PhsAdv_Cnt_s16 = 0;
  Rte_VltgCtrl_TermA_Volt_f32 = 0.0F;
  Rte_VltgCtrl_TermBSS_Volt_f32 = 0.0F;
  Rte_VltgCtrl_TermBTOT_Volt_f32 = 0.0F;
  Rte_VltgCtrl_TermXd_Uls_f32 = 0.0F;
  Rte_VltgCtrl_TermXq_Uls_f32 = 0.0F;
  Rte_VltgCtrl_TermY_Uls_f32 = 0.0F;
  Rte_VltgCtrl_TermZ_Uls_f32 = 1.0F;
  Rte_VltgCtrl_UnCorrPhsAdv_Cnt_s16 = 0;
  Rte_VltgCtrl_VdTerm_Volt_f32 = 0.0F;
  Rte_VltgCtrl_VqTerm_Volt_f32 = 0.0F;
  Rte_ActivePull_PullCmpCustLrngDi_Cnt_lgc = FALSE;
  Rte_ActivePull_PullCmpLongTermIntgtrStOffs_HwNm_f32 = 0.0F;
  Rte_ActivePull_PullCmpShoTermIntgtrStOffs_HwNm_f32 = 0.0F;
  Rte_Assist_IpTrqOvr_HwNm_f32 = 0.0F;
  Rte_Assist_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
  Rte_AssistSumnLmt_WhlImbRejCmd_MtrNm_f32 = 0.0F;
  Rte_CtrlTemp_AmbTemp_DegC_f32 = 0.0F;
  Rte_DampingFirewall_VehicleLonAccel_KphpS_f32 = 0.0F;
  Rte_DampingFirewall_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
  Rte_FrqDepDmpnInrtCmp_VehicleLonAccel_KphpS_f32 = 0.0F;
  Rte_FrqDepDmpnInrtCmp_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
  Rte_HwTrq_AbsPosStepSignal_Cnt_u08 = 0U;
  Rte_HystComp_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
  Rte_LrnEOT_DiagStsHwPosDis_Cnt_lgc = FALSE;
  Rte_MtrCurr_PADelta1_Cnt_u16 = 0U;
  Rte_MtrTempEst_AmbTemp_DegC_f32 = 0.0F;
  Rte_MtrTempEst_EngTemp_DegC_f32 = 0.0F;
  Rte_MtrTempEst_ScomAMDefeat_Cnt_lgc = FALSE;
  Rte_MtrTempEst_ScomTempDataRcvd_Cnt_lgc = FALSE;
  Rte_ParkAssistEnable_PAEnableRqst_Cnt_lgc = FALSE;
  Rte_ParkAssistEnable_PAErrInterfaceActive_Cnt_lgc = FALSE;
  Rte_ParkAssistEnable_PAHWAngleRqst_HwDeg_f32 = 0.0F;
  Rte_Sa_BkCpPc_OVERRIDESIGDIAGADC_Volt_f32 = 0.0F;
  Rte_Sa_BkCpPc_PMOSDIAGADC_Volt_f32 = 0.0F;
  Rte_SignlCondn_SrlComVehLatAccel_MpSecSq_f32 = 0.0F;
  Rte_SignlCondn_SrlComVehLonAccel_MpSecSq_f32 = 0.0F;
  Rte_SignlCondn_SrlComVehLonAccelValid_Cnt_lgc = FALSE;
  Rte_SignlCondn_SrlComVehYawRate_DegpS_f32 = 0.0F;

  /* reset Tx Ack Flags */
  Rte_Ap_9_AckFlagsInit();

  /* initialize inter-runnable variables */
  Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32 = 0.0F;
  Rte_Irv_NxtrLibs_Time_mS_u32 = 0U;

  /* mode management initialization part 1 */
  /* reset Trigger Disable Flags */
  Rte_Ap_10_TriggerDisableFlagsInit();
  Rte_Ap_11_TriggerDisableFlagsInit();
  Rte_Ap_7_TriggerDisableFlagsInit();
  Rte_Ap_8_TriggerDisableFlagsInit();
  Rte_Ap_9_TriggerDisableFlagsInit();


  Rte_ModeMachine_EcuM_currentMode_currentMode = RTE_MODE_EcuM_Mode_STARTUP;

  Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr = (uint8)0;
  Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr = (uint8)0;
  Rte_Ap_9_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack = 1;

  Rte_ModeMachine_StaMd_SystemState_Mode = RTE_TRANSITION_StaMd_Mode;

  Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[0] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[1] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1++;

  Rte_ModeMachine_StaMd11_SystemState11_Mode = RTE_TRANSITION_StaMd_Mode;

  Rte_ModeInfo_StaMd11_SystemState11_Mode.Rte_ModeQueue[0] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_ModeInfo_StaMd11_SystemState11_Mode.Rte_ModeQueue[1] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1++;
  Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2++;

  Rte_ModeMachine_StaMd7_SystemState7_Mode = RTE_TRANSITION_StaMd_Mode;

  Rte_ModeInfo_StaMd7_SystemState7_Mode.Rte_ModeQueue[0] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_ModeInfo_StaMd7_SystemState7_Mode.Rte_ModeQueue[1] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3++;
  Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2++;

  Rte_ModeMachine_StaMd8_SystemState8_Mode = RTE_TRANSITION_StaMd_Mode;

  Rte_ModeInfo_StaMd8_SystemState8_Mode.Rte_ModeQueue[0] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_ModeInfo_StaMd8_SystemState8_Mode.Rte_ModeQueue[1] = RTE_MODE_StaMd_Mode_WARMINIT;

  Rte_ModeMachine_StaMd9_SystemState9_Mode = RTE_TRANSITION_StaMd_Mode;

  Rte_ModeInfo_StaMd9_SystemState9_Mode.Rte_ModeQueue[0] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_ModeInfo_StaMd9_SystemState9_Mode.Rte_ModeQueue[1] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3++;
  Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1++;
  Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1++;
  Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1++;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Edch_ST_DIAG_OBD_DATA(P2CONST(Edch_EventStatusIpduDataType, AUTOMATIC, RTE_EDCH_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Edch_ST_DIAG_OBD_DATA_Start(data);
  Rte_Edch_ST_DIAG_OBD_DATA = *(data);
  Rte_WriteHook_Edch_ST_DIAG_OBD_DATA_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Edch_ST_DIAG_OBD_MUX_IMME(UInt6 data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Edch_ST_DIAG_OBD_MUX_IMME_Start(data);
  Rte_Edch_ST_DIAG_OBD_MUX_IMME = *(&data);
  Rte_WriteHook_Edch_ST_DIAG_OBD_MUX_IMME_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS(P2CONST(SG_ANFRAGE_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ID2_0x08_Mx01_EPS__ANFRAGE_EPS_SigTx(&(*(data)).ID2_0x08_Mx01_EPS);
  Com_UpdateShadowSignal(Com_ID2_0x08_Mx01_EPS__ANFRAGE_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR))&(*(data)).ID2_0x08_Mx01_EPS);
  Rte_ComHook_Com_ID_FN_INQY_EPS__ANFRAGE_EPS_SigTx(&(*(data)).ID_FN_INQY_EPS);
  Com_UpdateShadowSignal(Com_ID_FN_INQY_EPS__ANFRAGE_EPS, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR))&(*(data)).ID_FN_INQY_EPS);
  (void)Com_SendSignalGroup(Com_Grp_SG_ANFRAGE_EPS__ANFRAGE_EPS);
#else
  Rte_ComHook_Com_ID2_0x08_Mx01_EPS__ANFRAGE_EPS_SigTx(&(*(data)).ID2_0x08_Mx01_EPS);
  Com_UpdateShadowSignal(Com_ID2_0x08_Mx01_EPS__ANFRAGE_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA))&(*(data)).ID2_0x08_Mx01_EPS);
  Rte_ComHook_Com_ID_FN_INQY_EPS__ANFRAGE_EPS_SigTx(&(*(data)).ID_FN_INQY_EPS);
  Com_UpdateShadowSignal(Com_ID_FN_INQY_EPS__ANFRAGE_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA))&(*(data)).ID_FN_INQY_EPS);
  ret |= Com_SendSignalGroup(Com_Grp_SG_ANFRAGE_EPS__ANFRAGE_EPS);
#endif
  Rte_WriteHook_Ap_SrlComInput_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(P2CONST(SG_ACLNY_MASSCNTR, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR = *(data);
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_Sender = !Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR;
#endif
  ResumeOSInterrupts();
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_RxAclnyMassCntr */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr);
  Rte_WriteHook_Ap_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComCONVEH_CON_VEH(P2CONST(SG_CON_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SrlComCONVEH_CON_VEH_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput_SrlComCONVEH_CON_VEH = *(data);
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComCONVEH_CON_VEH_Sender = !Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComCONVEH_CON_VEH;
#endif
  ResumeOSInterrupts();
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxConVeh);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_RxConVeh */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxConVeh);
  Rte_WriteHook_Ap_SrlComInput_SrlComCONVEH_CON_VEH_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(P2CONST(SG_OFFS_QUAD_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS = *(data);
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_Sender = !Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS;
#endif
  ResumeOSInterrupts();
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxRevOffset);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_RxRevOffset */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxRevOffset);
  Rte_WriteHook_Ap_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(P2CONST(SG_TAR_QTA_STRMOM_DV, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV = *(data);
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_Sender = !Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV;
#endif
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(P2CONST(SG_TAR_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT = *(data);
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_Sender = !Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT;
#endif
  ResumeOSInterrupts();
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_RxPaDrvDyn */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn);
  Rte_WriteHook_Ap_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGVVEH_SG_V_VEH(P2CONST(SG_V_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SrlComSGVVEH_SG_V_VEH_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput_SrlComSGVVEH_SG_V_VEH = *(data);
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGVVEH_SG_V_VEH_Sender = !Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGVVEH_SG_V_VEH;
#endif
  ResumeOSInterrupts();
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVehSpd);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_RxVehSpd */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVehSpd);
  Rte_WriteHook_Ap_SrlComInput_SrlComSGVVEH_SG_V_VEH_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSTCENG_ST_CENG(P2CONST(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SrlComSTCENG_ST_CENG_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput_SrlComSTCENG_ST_CENG = *(data);
  ResumeOSInterrupts();
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxStCeng);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_RxStCeng */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxStCeng);
  Rte_WriteHook_Ap_SrlComInput_SrlComSTCENG_ST_CENG_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComVYAWVEH_VYAW_VEH(P2CONST(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput_SrlComVYAWVEH_VYAW_VEH_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput_SrlComVYAWVEH_VYAW_VEH = *(data);
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComVYAWVEH_VYAW_VEH_Sender = !Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComVYAWVEH_VYAW_VEH;
#endif
  ResumeOSInterrupts();
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_RxVYawVeh */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh);
  Rte_WriteHook_Ap_SrlComInput_SrlComVYAWVEH_VYAW_VEH_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComEngDrvStatus_ST_CENG(P2CONST(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComInput2_SrlComEngDrvStatus_ST_CENG_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComInput2_SrlComEngDrvStatus_ST_CENG = *(data);
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComInput2_SrlComEngDrvStatus_ST_CENG_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_AVL_PO_EPS_AVL_PO_EPS(P2CONST(RT_SG_AVL_PO_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_AVL_PO_EPS_AVL_PO_EPS_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ALIV_AVL_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).ALIV_AVL_PO_EPS);
  Com_UpdateShadowSignal(Com_ALIV_AVL_PO_EPS__AVL_PO_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ALIV_AVL_PO_EPS);
  Rte_ComHook_Com_AVL_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).AVL_PO_EPS);
  Com_UpdateShadowSignal(Com_AVL_PO_EPS__AVL_PO_EPS, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).AVL_PO_EPS);
  Rte_ComHook_Com_AVL_PO_IDX_EPS__AVL_PO_EPS_SigTx(&(*(data)).AVL_PO_IDX_EPS);
  Com_UpdateShadowSignal(Com_AVL_PO_IDX_EPS__AVL_PO_EPS, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).AVL_PO_IDX_EPS);
  Rte_ComHook_Com_CRC_AVL_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).CRC_AVL_PO_EPS);
  Com_UpdateShadowSignal(Com_CRC_AVL_PO_EPS__AVL_PO_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).CRC_AVL_PO_EPS);
  Rte_ComHook_Com_IDX_TORQ_SEN__AVL_PO_EPS_SigTx(&(*(data)).IDX_TORQ_SEN);
  Com_UpdateShadowSignal(Com_IDX_TORQ_SEN__AVL_PO_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).IDX_TORQ_SEN);
  Rte_ComHook_Com_OFFS_GRD_MID_EPS__AVL_PO_EPS_SigTx(&(*(data)).OFFS_GRD_MID_EPS);
  Com_UpdateShadowSignal(Com_OFFS_GRD_MID_EPS__AVL_PO_EPS, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).OFFS_GRD_MID_EPS);
  Rte_ComHook_Com_QU_AVL_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).QU_AVL_PO_EPS);
  Com_UpdateShadowSignal(Com_QU_AVL_PO_EPS__AVL_PO_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).QU_AVL_PO_EPS);
  Rte_ComHook_Com_UN_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).UN_PO_EPS);
  Com_UpdateShadowSignal(Com_UN_PO_EPS__AVL_PO_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).UN_PO_EPS);
  (void)Com_SendSignalGroup(Com_Grp_SG_AVL_PO_EPS__AVL_PO_EPS);
#else
  Rte_ComHook_Com_ALIV_AVL_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).ALIV_AVL_PO_EPS);
  Com_UpdateShadowSignal(Com_ALIV_AVL_PO_EPS__AVL_PO_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ALIV_AVL_PO_EPS);
  Rte_ComHook_Com_AVL_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).AVL_PO_EPS);
  Com_UpdateShadowSignal(Com_AVL_PO_EPS__AVL_PO_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).AVL_PO_EPS);
  Rte_ComHook_Com_AVL_PO_IDX_EPS__AVL_PO_EPS_SigTx(&(*(data)).AVL_PO_IDX_EPS);
  Com_UpdateShadowSignal(Com_AVL_PO_IDX_EPS__AVL_PO_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).AVL_PO_IDX_EPS);
  Rte_ComHook_Com_CRC_AVL_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).CRC_AVL_PO_EPS);
  Com_UpdateShadowSignal(Com_CRC_AVL_PO_EPS__AVL_PO_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).CRC_AVL_PO_EPS);
  Rte_ComHook_Com_IDX_TORQ_SEN__AVL_PO_EPS_SigTx(&(*(data)).IDX_TORQ_SEN);
  Com_UpdateShadowSignal(Com_IDX_TORQ_SEN__AVL_PO_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).IDX_TORQ_SEN);
  Rte_ComHook_Com_OFFS_GRD_MID_EPS__AVL_PO_EPS_SigTx(&(*(data)).OFFS_GRD_MID_EPS);
  Com_UpdateShadowSignal(Com_OFFS_GRD_MID_EPS__AVL_PO_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).OFFS_GRD_MID_EPS);
  Rte_ComHook_Com_QU_AVL_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).QU_AVL_PO_EPS);
  Com_UpdateShadowSignal(Com_QU_AVL_PO_EPS__AVL_PO_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).QU_AVL_PO_EPS);
  Rte_ComHook_Com_UN_PO_EPS__AVL_PO_EPS_SigTx(&(*(data)).UN_PO_EPS);
  Com_UpdateShadowSignal(Com_UN_PO_EPS__AVL_PO_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).UN_PO_EPS);
  ret |= Com_SendSignalGroup(Com_Grp_SG_AVL_PO_EPS__AVL_PO_EPS);
#endif
  Rte_WriteHook_Ap_SrlComOutput_AVL_PO_EPS_AVL_PO_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_AVL_PO_EPS_TRGG_ENGTORQ_EPS(New_Coding_39 data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_AVL_PO_EPS_TRGG_ENGTORQ_EPS_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_TRGG_ENGTORQ_EPS__ENGTORQ_EPS_SigTx(&data);
  (void)Com_SendSignal(Com_TRGG_ENGTORQ_EPS__ENGTORQ_EPS, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_TRGG_ENGTORQ_EPS__ENGTORQ_EPS_SigTx(&data);
  ret |= Com_SendSignal(Com_TRGG_ENGTORQ_EPS__ENGTORQ_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_AVL_PO_EPS_TRGG_ENGTORQ_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_AVL_STMOM_AVL_FORC_GRD(P2CONST(RT_SG_AVL_FORC_GRD, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_AVL_STMOM_AVL_FORC_GRD_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ALIV_AVL_FORC_GRD__AVL_FORC_GRD_SigTx(&(*(data)).ALIV_AVL_FORC_GRD);
  Com_UpdateShadowSignal(Com_ALIV_AVL_FORC_GRD__AVL_FORC_GRD, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ALIV_AVL_FORC_GRD);
  Rte_ComHook_Com_AVL_FORC_GRD__AVL_FORC_GRD_SigTx(&(*(data)).AVL_FORC_GRD);
  Com_UpdateShadowSignal(Com_AVL_FORC_GRD__AVL_FORC_GRD, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).AVL_FORC_GRD);
  Rte_ComHook_Com_AVL_FORC_GRD_0x0C_0x04__AVL_FORC_GRD_SigTx(&(*(data)).AVL_FORC_GRD_0x0C_0x04);
  Com_UpdateShadowSignal(Com_AVL_FORC_GRD_0x0C_0x04__AVL_FORC_GRD, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).AVL_FORC_GRD_0x0C_0x04);
  Rte_ComHook_Com_AVL_PWR_EL_EPS_COOD__AVL_FORC_GRD_SigTx(&(*(data)).AVL_PWR_EL_EPS_COOD);
  Com_UpdateShadowSignal(Com_AVL_PWR_EL_EPS_COOD__AVL_FORC_GRD, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).AVL_PWR_EL_EPS_COOD);
  Rte_ComHook_Com_CRC_AVL_FORC_GRD__AVL_FORC_GRD_SigTx(&(*(data)).CRC_AVL_FORC_GRD);
  Com_UpdateShadowSignal(Com_CRC_AVL_FORC_GRD__AVL_FORC_GRD, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).CRC_AVL_FORC_GRD);
  Rte_ComHook_Com_QU_AVL_FORC_GRD__AVL_FORC_GRD_SigTx(&(*(data)).QU_AVL_FORC_GRD);
  Com_UpdateShadowSignal(Com_QU_AVL_FORC_GRD__AVL_FORC_GRD, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).QU_AVL_FORC_GRD);
  (void)Com_SendSignalGroup(Com_Grp_SG_AVL_FORC_GRD__AVL_FORC_GRD);
#else
  Rte_ComHook_Com_ALIV_AVL_FORC_GRD__AVL_FORC_GRD_SigTx(&(*(data)).ALIV_AVL_FORC_GRD);
  Com_UpdateShadowSignal(Com_ALIV_AVL_FORC_GRD__AVL_FORC_GRD, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ALIV_AVL_FORC_GRD);
  Rte_ComHook_Com_AVL_FORC_GRD__AVL_FORC_GRD_SigTx(&(*(data)).AVL_FORC_GRD);
  Com_UpdateShadowSignal(Com_AVL_FORC_GRD__AVL_FORC_GRD, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).AVL_FORC_GRD);
  Rte_ComHook_Com_AVL_FORC_GRD_0x0C_0x04__AVL_FORC_GRD_SigTx(&(*(data)).AVL_FORC_GRD_0x0C_0x04);
  Com_UpdateShadowSignal(Com_AVL_FORC_GRD_0x0C_0x04__AVL_FORC_GRD, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).AVL_FORC_GRD_0x0C_0x04);
  Rte_ComHook_Com_AVL_PWR_EL_EPS_COOD__AVL_FORC_GRD_SigTx(&(*(data)).AVL_PWR_EL_EPS_COOD);
  Com_UpdateShadowSignal(Com_AVL_PWR_EL_EPS_COOD__AVL_FORC_GRD, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).AVL_PWR_EL_EPS_COOD);
  Rte_ComHook_Com_CRC_AVL_FORC_GRD__AVL_FORC_GRD_SigTx(&(*(data)).CRC_AVL_FORC_GRD);
  Com_UpdateShadowSignal(Com_CRC_AVL_FORC_GRD__AVL_FORC_GRD, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).CRC_AVL_FORC_GRD);
  Rte_ComHook_Com_QU_AVL_FORC_GRD__AVL_FORC_GRD_SigTx(&(*(data)).QU_AVL_FORC_GRD);
  Com_UpdateShadowSignal(Com_QU_AVL_FORC_GRD__AVL_FORC_GRD, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).QU_AVL_FORC_GRD);
  ret |= Com_SendSignalGroup(Com_Grp_SG_AVL_FORC_GRD__AVL_FORC_GRD);
#endif
  Rte_WriteHook_Ap_SrlComOutput_AVL_STMOM_AVL_FORC_GRD_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_AVL_STMOM_AVL_STMOM_DV_ACT(P2CONST(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_AVL_STMOM_AVL_STMOM_DV_ACT_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ALIV_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT_SigTx(&(*(data)).ALIV_AVL_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_ALIV_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ALIV_AVL_STMOM_DV_ACT);
  Rte_ComHook_Com_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT_SigTx(&(*(data)).AVL_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).AVL_STMOM_DV_ACT);
  Rte_ComHook_Com_AVL_STMOM_DV_ACT_0x0C_0x04__AVL_STMOM_DV_ACT_SigTx(&(*(data)).AVL_STMOM_DV_ACT_0x0C_0x04);
  Com_UpdateShadowSignal(Com_AVL_STMOM_DV_ACT_0x0C_0x04__AVL_STMOM_DV_ACT, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).AVL_STMOM_DV_ACT_0x0C_0x04);
  Rte_ComHook_Com_CRC_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT_SigTx(&(*(data)).CRC_AVL_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_CRC_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).CRC_AVL_STMOM_DV_ACT);
  Rte_ComHook_Com_QU_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT_SigTx(&(*(data)).QU_AVL_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_QU_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).QU_AVL_STMOM_DV_ACT);
  (void)Com_SendSignalGroup(Com_Grp_SG_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT);
#else
  Rte_ComHook_Com_ALIV_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT_SigTx(&(*(data)).ALIV_AVL_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_ALIV_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ALIV_AVL_STMOM_DV_ACT);
  Rte_ComHook_Com_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT_SigTx(&(*(data)).AVL_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).AVL_STMOM_DV_ACT);
  Rte_ComHook_Com_AVL_STMOM_DV_ACT_0x0C_0x04__AVL_STMOM_DV_ACT_SigTx(&(*(data)).AVL_STMOM_DV_ACT_0x0C_0x04);
  Com_UpdateShadowSignal(Com_AVL_STMOM_DV_ACT_0x0C_0x04__AVL_STMOM_DV_ACT, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).AVL_STMOM_DV_ACT_0x0C_0x04);
  Rte_ComHook_Com_CRC_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT_SigTx(&(*(data)).CRC_AVL_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_CRC_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).CRC_AVL_STMOM_DV_ACT);
  Rte_ComHook_Com_QU_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT_SigTx(&(*(data)).QU_AVL_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_QU_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).QU_AVL_STMOM_DV_ACT);
  ret |= Com_SendSignalGroup(Com_Grp_SG_AVL_STMOM_DV_ACT__AVL_STMOM_DV_ACT);
#endif
  Rte_WriteHook_Ap_SrlComOutput_AVL_STMOM_AVL_STMOM_DV_ACT_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY(ALIV_4_BIT_Unsigned_Integer data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ALIV_ST_DIAG_OBD_3_DRDY__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_ALIV_ST_DIAG_OBD_3_DRDY__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_ALIV_ST_DIAG_OBD_3_DRDY__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_ALIV_ST_DIAG_OBD_3_DRDY__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ALIV_ST_DIAG_OBD_3_DRDY_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1(DIAG_ST_OBD data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_1__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_1__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_1__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_1__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_1_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2(DIAG_ST_OBD data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_2__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_2__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_2__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_2__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_2_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3(DIAG_ST_OBD data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_3__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_3__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_3__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_3__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_3_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4(DIAG_ST_OBD data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_4__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_4__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_4__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_4__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_4_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5(DIAG_ST_OBD data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_5__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_5__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_5__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_5__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_5_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6(DIAG_ST_OBD data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_6__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_6__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_6__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_6__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_6_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7(DIAG_ST_OBD data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_7__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_7__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_7__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_7__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_7_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8(DIAG_ST_OBD data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_8__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_8__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIAG_ST_OBD_3_DRDY_8__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_DIAG_ST_OBD_3_DRDY_8__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_DIAG_ST_OBD_3_DRDY_8_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX(ST_DIAG_OBD_MUX_IMME data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ST_DIAG_OBD_3_DRDY_IMME_MUX__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_ST_DIAG_OBD_3_DRDY_IMME_MUX__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_ST_DIAG_OBD_3_DRDY_IMME_MUX__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_ST_DIAG_OBD_3_DRDY_IMME_MUX__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_IMME_MUX_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX(ST_DIAG_OBD_MUX_MAX data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ST_DIAG_OBD_3_DRDY_MAX_MUX__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  (void)Com_SendSignal(Com_ST_DIAG_OBD_3_DRDY_MAX_MUX__ST_DIAG_OBD_3_DRDY, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_ST_DIAG_OBD_3_DRDY_MAX_MUX__ST_DIAG_OBD_3_DRDY_SigTx(&data);
  ret |= Com_SendSignal(Com_ST_DIAG_OBD_3_DRDY_MAX_MUX__ST_DIAG_OBD_3_DRDY, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_DIAG_ST_OBD_3_DRDY_ST_DIAG_OBD_3_DRDY_MAX_MUX_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DISP_CC_EPS_DISP_CC_EPS(P2CONST(SG_DISP_CC_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DISP_CC_EPS_DISP_CC_EPS_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ALIV_DISP_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).ALIV_DISP_CC_EPS);
  Com_UpdateShadowSignal(Com_ALIV_DISP_CC_EPS__DISP_CC_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ALIV_DISP_CC_EPS);
  Rte_ComHook_Com_CHL_DISP_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).CHL_DISP_CC_EPS);
  Com_UpdateShadowSignal(Com_CHL_DISP_CC_EPS__DISP_CC_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).CHL_DISP_CC_EPS);
  Rte_ComHook_Com_CRC_DISP_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).CRC_DISP_CC_EPS);
  Com_UpdateShadowSignal(Com_CRC_DISP_CC_EPS__DISP_CC_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).CRC_DISP_CC_EPS);
  Rte_ComHook_Com_NO_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).NO_CC_EPS);
  Com_UpdateShadowSignal(Com_NO_CC_EPS__DISP_CC_EPS, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).NO_CC_EPS);
  Rte_ComHook_Com_ST_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).ST_CC_EPS);
  Com_UpdateShadowSignal(Com_ST_CC_EPS__DISP_CC_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ST_CC_EPS);
  Rte_ComHook_Com_ST_IDC_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).ST_IDC_CC_EPS);
  Com_UpdateShadowSignal(Com_ST_IDC_CC_EPS__DISP_CC_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ST_IDC_CC_EPS);
  Rte_ComHook_Com_TRANF_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).TRANF_CC_EPS);
  Com_UpdateShadowSignal(Com_TRANF_CC_EPS__DISP_CC_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).TRANF_CC_EPS);
  (void)Com_SendSignalGroup(Com_Grp_SG_DISP_CC_EPS__DISP_CC_EPS);
#else
  Rte_ComHook_Com_ALIV_DISP_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).ALIV_DISP_CC_EPS);
  Com_UpdateShadowSignal(Com_ALIV_DISP_CC_EPS__DISP_CC_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ALIV_DISP_CC_EPS);
  Rte_ComHook_Com_CHL_DISP_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).CHL_DISP_CC_EPS);
  Com_UpdateShadowSignal(Com_CHL_DISP_CC_EPS__DISP_CC_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).CHL_DISP_CC_EPS);
  Rte_ComHook_Com_CRC_DISP_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).CRC_DISP_CC_EPS);
  Com_UpdateShadowSignal(Com_CRC_DISP_CC_EPS__DISP_CC_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).CRC_DISP_CC_EPS);
  Rte_ComHook_Com_NO_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).NO_CC_EPS);
  Com_UpdateShadowSignal(Com_NO_CC_EPS__DISP_CC_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).NO_CC_EPS);
  Rte_ComHook_Com_ST_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).ST_CC_EPS);
  Com_UpdateShadowSignal(Com_ST_CC_EPS__DISP_CC_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ST_CC_EPS);
  Rte_ComHook_Com_ST_IDC_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).ST_IDC_CC_EPS);
  Com_UpdateShadowSignal(Com_ST_IDC_CC_EPS__DISP_CC_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ST_IDC_CC_EPS);
  Rte_ComHook_Com_TRANF_CC_EPS__DISP_CC_EPS_SigTx(&(*(data)).TRANF_CC_EPS);
  Com_UpdateShadowSignal(Com_TRANF_CC_EPS__DISP_CC_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).TRANF_CC_EPS);
  ret |= Com_SendSignalGroup(Com_Grp_SG_DISP_CC_EPS__DISP_CC_EPS);
#endif
  Rte_WriteHook_Ap_SrlComOutput_DISP_CC_EPS_DISP_CC_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_DT_EST_DT_EST(P2CONST(SG_DT_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_DT_EST_DT_EST_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ALIV_DT_EST__DT_EST_SigTx(&(*(data)).ALIV_DT_EST);
  Com_UpdateShadowSignal(Com_ALIV_DT_EST__DT_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ALIV_DT_EST);
  Rte_ComHook_Com_AVL_I_ACT_EST__DT_EST_SigTx(&(*(data)).AVL_I_ACT_EST);
  Com_UpdateShadowSignal(Com_AVL_I_ACT_EST__DT_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).AVL_I_ACT_EST);
  Rte_ComHook_Com_CRC_DT_EST__DT_EST_SigTx(&(*(data)).CRC_DT_EST);
  Com_UpdateShadowSignal(Com_CRC_DT_EST__DT_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).CRC_DT_EST);
  Rte_ComHook_Com_DT_EST_0x0C_0x20__DT_EST_SigTx(&(*(data)).DT_EST_0x0C_0x20);
  Com_UpdateShadowSignal(Com_DT_EST_0x0C_0x20__DT_EST, (P2VAR(uint32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).DT_EST_0x0C_0x20);
  Rte_ComHook_Com_DT_EST_0x2C_0x04__DT_EST_SigTx(&(*(data)).DT_EST_0x2C_0x04);
  Com_UpdateShadowSignal(Com_DT_EST_0x2C_0x04__DT_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).DT_EST_0x2C_0x04);
  Rte_ComHook_Com_DT_EST_0x38_0x20__DT_EST_SigTx(&(*(data)).DT_EST_0x38_0x20);
  Com_UpdateShadowSignal(Com_DT_EST_0x38_0x20__DT_EST, (P2VAR(uint32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).DT_EST_0x38_0x20);
  Rte_ComHook_Com_DT_EST_0x58_0x20__DT_EST_SigTx(&(*(data)).DT_EST_0x58_0x20);
  Com_UpdateShadowSignal(Com_DT_EST_0x58_0x20__DT_EST, (P2VAR(uint32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).DT_EST_0x58_0x20);
  Rte_ComHook_Com_DT_EST_0x78_0x08__DT_EST_SigTx(&(*(data)).DT_EST_0x78_0x08);
  Com_UpdateShadowSignal(Com_DT_EST_0x78_0x08__DT_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).DT_EST_0x78_0x08);
  (void)Com_SendSignalGroup(Com_Grp_SG_DT_EST__DT_EST);
#else
  Rte_ComHook_Com_ALIV_DT_EST__DT_EST_SigTx(&(*(data)).ALIV_DT_EST);
  Com_UpdateShadowSignal(Com_ALIV_DT_EST__DT_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ALIV_DT_EST);
  Rte_ComHook_Com_AVL_I_ACT_EST__DT_EST_SigTx(&(*(data)).AVL_I_ACT_EST);
  Com_UpdateShadowSignal(Com_AVL_I_ACT_EST__DT_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).AVL_I_ACT_EST);
  Rte_ComHook_Com_CRC_DT_EST__DT_EST_SigTx(&(*(data)).CRC_DT_EST);
  Com_UpdateShadowSignal(Com_CRC_DT_EST__DT_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).CRC_DT_EST);
  Rte_ComHook_Com_DT_EST_0x0C_0x20__DT_EST_SigTx(&(*(data)).DT_EST_0x0C_0x20);
  Com_UpdateShadowSignal(Com_DT_EST_0x0C_0x20__DT_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).DT_EST_0x0C_0x20);
  Rte_ComHook_Com_DT_EST_0x2C_0x04__DT_EST_SigTx(&(*(data)).DT_EST_0x2C_0x04);
  Com_UpdateShadowSignal(Com_DT_EST_0x2C_0x04__DT_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).DT_EST_0x2C_0x04);
  Rte_ComHook_Com_DT_EST_0x38_0x20__DT_EST_SigTx(&(*(data)).DT_EST_0x38_0x20);
  Com_UpdateShadowSignal(Com_DT_EST_0x38_0x20__DT_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).DT_EST_0x38_0x20);
  Rte_ComHook_Com_DT_EST_0x58_0x20__DT_EST_SigTx(&(*(data)).DT_EST_0x58_0x20);
  Com_UpdateShadowSignal(Com_DT_EST_0x58_0x20__DT_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).DT_EST_0x58_0x20);
  Rte_ComHook_Com_DT_EST_0x78_0x08__DT_EST_SigTx(&(*(data)).DT_EST_0x78_0x08);
  Com_UpdateShadowSignal(Com_DT_EST_0x78_0x08__DT_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).DT_EST_0x78_0x08);
  ret |= Com_SendSignalGroup(Com_Grp_SG_DT_EST__DT_EST);
#endif
  Rte_WriteHook_Ap_SrlComOutput_DT_EST_DT_EST_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Batt(BATT_VOLTS data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_Batt_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_BATT_VOLTS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_BATT_VOLTS__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_BATT_VOLTS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_BATT_VOLTS__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_Batt_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_CtrlTemp(CONT_TEMP_DEG data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_CtrlTemp_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_CONT_TEMP_DEG__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_CONT_TEMP_DEG__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_CONT_TEMP_DEG__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_CONT_TEMP_DEG__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_CtrlTemp_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_DiffTrq(DIFF_TRQ_NM data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_DiffTrq_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_DIFF_TRQ_NM__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_DIFF_TRQ_NM__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_DIFF_TRQ_NM__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_DIFF_TRQ_NM__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_DiffTrq_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstBattCurr(EST_BATT_AMPS data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_EstBattCurr_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_EST_BATT_AMPS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_EST_BATT_AMPS__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_EST_BATT_AMPS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_EST_BATT_AMPS__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_EstBattCurr_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstCuTemp(EST_CUTEMP_DEG data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_EstCuTemp_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_EST_CUTEMP_DEG__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_EST_CUTEMP_DEG__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_EST_CUTEMP_DEG__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_EST_CUTEMP_DEG__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_EstCuTemp_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_EstMtrTemp(EST_MOTTEMP_DEG data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_EstMtrTemp_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_EST_MOTTEMP_DEG__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_EST_MOTTEMP_DEG__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_EST_MOTTEMP_DEG__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_EST_MOTTEMP_DEG__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_EstMtrTemp_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrCurr(New_Coding_3 data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_MtrCurr_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_MTR_CURR_AMPS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_MTR_CURR_AMPS__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_MTR_CURR_AMPS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_MTR_CURR_AMPS__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_MtrCurr_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmd(MTRTRQCMD_NM data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmd_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_MTRTRQCMD_NM__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_MTRTRQCMD_NM__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_MTRTRQCMD_NM__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_MTRTRQCMD_NM__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmd_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmdLmtd(MTRTRQLMTD_NM data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmdLmtd_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_MTRTRQLMTD_NM__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_MTRTRQLMTD_NM__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_MTRTRQLMTD_NM__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_MTRTRQLMTD_NM__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_MtrTrqCmdLmtd_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_MtrVel(MOT_VEL_RADPSEC data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_MtrVel_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_MOT_VEL_RADPSEC__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_MOT_VEL_RADPSEC__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_MOT_VEL_RADPSEC__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_MOT_VEL_RADPSEC__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_MtrVel_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_NTCNumber(New_Coding_28 data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_NTCNumber_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_NTC_Number__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_NTC_Number__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_NTC_Number__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_NTC_Number__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_NTCNumber_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Res_TBD(New_Coding_15 data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_Res_TBD_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_RES_TBD__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_RES_TBD__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_RES_TBD__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_RES_TBD__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_Res_TBD_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_SWA(SWA_DEG data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_SWA_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_SWA_DEG__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_SWA_DEG__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_SWA_DEG__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_SWA_DEG__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_SWA_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_SystemState(SYS_STATE_ENUM data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_SystemState_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_SYS_STATE_ENUM__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_SYS_STATE_ENUM__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_SYS_STATE_ENUM__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_SYS_STATE_ENUM__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_SystemState_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_ThrmlLimitPerc(THRML_LIMIT_PERC data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_ThrmlLimitPerc_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_THRML_LIMIT_PERC__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_THRML_LIMIT_PERC__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_THRML_LIMIT_PERC__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_THRML_LIMIT_PERC__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_ThrmlLimitPerc_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Trq1(TORQUE1_VOLTS data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_Trq1_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_TORQUE1_VOLTS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_TORQUE1_VOLTS__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_TORQUE1_VOLTS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_TORQUE1_VOLTS__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_Trq1_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_FR_DBG_EPS_Trq2(TORQUE2_VOLTS data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_Trq2_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_TORQUE2_VOLTS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  (void)Com_SendSignal(Com_TORQUE2_VOLTS__DBG_EPS_BS_MOD_58_BYTE, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_TORQUE2_VOLTS__DBG_EPS_BS_MOD_58_BYTE_SigTx(&data);
  ret |= Com_SendSignal(Com_TORQUE2_VOLTS__DBG_EPS_BS_MOD_58_BYTE, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_FR_DBG_EPS_Trq2_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS(ID_TEMP_CPO_HET_MNG data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ID_TEMP_CPO_HET_MNG_EPS__RQ_STG_EFAN_EPS_SigTx(&data);
  (void)Com_SendSignal(Com_ID_TEMP_CPO_HET_MNG_EPS__RQ_STG_EFAN_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_ID_TEMP_CPO_HET_MNG_EPS__RQ_STG_EFAN_EPS_SigTx(&data);
  ret |= Com_SendSignal(Com_ID_TEMP_CPO_HET_MNG_EPS__RQ_STG_EFAN_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_ID_TEMP_CPO_HET_MNG_EPS_ID_TEMP_CPO_HET_MNG_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_ST_EST_ST_EST(P2CONST(RT_SG_ST_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_ST_EST_ST_EST_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ALIV_ST_EST_FTAX__ST_EST_SigTx(&(*(data)).ALIV_ST_EST_FTAX);
  Com_UpdateShadowSignal(Com_ALIV_ST_EST_FTAX__ST_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ALIV_ST_EST_FTAX);
  Rte_ComHook_Com_CRC_ST_EST_FTAX__ST_EST_SigTx(&(*(data)).CRC_ST_EST_FTAX);
  Com_UpdateShadowSignal(Com_CRC_ST_EST_FTAX__ST_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).CRC_ST_EST_FTAX);
  Rte_ComHook_Com_QU_FN_EST__ST_EST_SigTx(&(*(data)).QU_FN_EST);
  Com_UpdateShadowSignal(Com_QU_FN_EST__ST_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).QU_FN_EST);
  Rte_ComHook_Com_QU_FN_VIB_EPS__ST_EST_SigTx(&(*(data)).QU_FN_VIB_EPS);
  Com_UpdateShadowSignal(Com_QU_FN_VIB_EPS__ST_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).QU_FN_VIB_EPS);
  Rte_ComHook_Com_QU_SER_STMOM_DV_ACT__ST_EST_SigTx(&(*(data)).QU_SER_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_QU_SER_STMOM_DV_ACT__ST_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).QU_SER_STMOM_DV_ACT);
  Rte_ComHook_Com_ST_EST_0x10_0x08__ST_EST_SigTx(&(*(data)).ST_EST_0x10_0x08);
  Com_UpdateShadowSignal(Com_ST_EST_0x10_0x08__ST_EST, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ST_EST_0x10_0x08);
  (void)Com_SendSignalGroup(Com_Grp_SG_ST_EST__ST_EST);
#else
  Rte_ComHook_Com_ALIV_ST_EST_FTAX__ST_EST_SigTx(&(*(data)).ALIV_ST_EST_FTAX);
  Com_UpdateShadowSignal(Com_ALIV_ST_EST_FTAX__ST_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ALIV_ST_EST_FTAX);
  Rte_ComHook_Com_CRC_ST_EST_FTAX__ST_EST_SigTx(&(*(data)).CRC_ST_EST_FTAX);
  Com_UpdateShadowSignal(Com_CRC_ST_EST_FTAX__ST_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).CRC_ST_EST_FTAX);
  Rte_ComHook_Com_QU_FN_EST__ST_EST_SigTx(&(*(data)).QU_FN_EST);
  Com_UpdateShadowSignal(Com_QU_FN_EST__ST_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).QU_FN_EST);
  Rte_ComHook_Com_QU_FN_VIB_EPS__ST_EST_SigTx(&(*(data)).QU_FN_VIB_EPS);
  Com_UpdateShadowSignal(Com_QU_FN_VIB_EPS__ST_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).QU_FN_VIB_EPS);
  Rte_ComHook_Com_QU_SER_STMOM_DV_ACT__ST_EST_SigTx(&(*(data)).QU_SER_STMOM_DV_ACT);
  Com_UpdateShadowSignal(Com_QU_SER_STMOM_DV_ACT__ST_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).QU_SER_STMOM_DV_ACT);
  Rte_ComHook_Com_ST_EST_0x10_0x08__ST_EST_SigTx(&(*(data)).ST_EST_0x10_0x08);
  Com_UpdateShadowSignal(Com_ST_EST_0x10_0x08__ST_EST, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ST_EST_0x10_0x08);
  ret |= Com_SendSignalGroup(Com_Grp_SG_ST_EST__ST_EST);
#endif
  Rte_WriteHook_Ap_SrlComOutput_ST_EST_ST_EST_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_SU_EPS_SU_EPS(P2CONST(RT_SG_SU_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_SU_EPS_SU_EPS_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_ALIV_SU_EPS__SU_EPS_SigTx(&(*(data)).ALIV_SU_EPS);
  Com_UpdateShadowSignal(Com_ALIV_SU_EPS__SU_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).ALIV_SU_EPS);
  Rte_ComHook_Com_CRC_SU_EPS__SU_EPS_SigTx(&(*(data)).CRC_SU_EPS);
  Com_UpdateShadowSignal(Com_CRC_SU_EPS__SU_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).CRC_SU_EPS);
  Rte_ComHook_Com_SU_EPS_0x0E_0x20__SU_EPS_SigTx(&(*(data)).SU_EPS_0x0E_0x20);
  Com_UpdateShadowSignal(Com_SU_EPS_0x0E_0x20__SU_EPS, (P2VAR(uint32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).SU_EPS_0x0E_0x20);
  Rte_ComHook_Com_SU_EPS_0x2E_0x06__SU_EPS_SigTx(&(*(data)).SU_EPS_0x2E_0x06);
  Com_UpdateShadowSignal(Com_SU_EPS_0x2E_0x06__SU_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).SU_EPS_0x2E_0x06);
  Rte_ComHook_Com_TOT_STR_EPS__SU_EPS_SigTx(&(*(data)).TOT_STR_EPS);
  Com_UpdateShadowSignal(Com_TOT_STR_EPS__SU_EPS, (P2VAR(uint16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).TOT_STR_EPS);
  Rte_ComHook_Com_UN_TOT_STR_EPS__SU_EPS_SigTx(&(*(data)).UN_TOT_STR_EPS);
  Com_UpdateShadowSignal(Com_UN_TOT_STR_EPS__SU_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))&(*(data)).UN_TOT_STR_EPS);
  (void)Com_SendSignalGroup(Com_Grp_SG_SU_EPS__SU_EPS);
#else
  Rte_ComHook_Com_ALIV_SU_EPS__SU_EPS_SigTx(&(*(data)).ALIV_SU_EPS);
  Com_UpdateShadowSignal(Com_ALIV_SU_EPS__SU_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).ALIV_SU_EPS);
  Rte_ComHook_Com_CRC_SU_EPS__SU_EPS_SigTx(&(*(data)).CRC_SU_EPS);
  Com_UpdateShadowSignal(Com_CRC_SU_EPS__SU_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).CRC_SU_EPS);
  Rte_ComHook_Com_SU_EPS_0x0E_0x20__SU_EPS_SigTx(&(*(data)).SU_EPS_0x0E_0x20);
  Com_UpdateShadowSignal(Com_SU_EPS_0x0E_0x20__SU_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).SU_EPS_0x0E_0x20);
  Rte_ComHook_Com_SU_EPS_0x2E_0x06__SU_EPS_SigTx(&(*(data)).SU_EPS_0x2E_0x06);
  Com_UpdateShadowSignal(Com_SU_EPS_0x2E_0x06__SU_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).SU_EPS_0x2E_0x06);
  Rte_ComHook_Com_TOT_STR_EPS__SU_EPS_SigTx(&(*(data)).TOT_STR_EPS);
  Com_UpdateShadowSignal(Com_TOT_STR_EPS__SU_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).TOT_STR_EPS);
  Rte_ComHook_Com_UN_TOT_STR_EPS__SU_EPS_SigTx(&(*(data)).UN_TOT_STR_EPS);
  Com_UpdateShadowSignal(Com_UN_TOT_STR_EPS__SU_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))&(*(data)).UN_TOT_STR_EPS);
  ret |= Com_SendSignalGroup(Com_Grp_SG_SU_EPS__SU_EPS);
#endif
  Rte_WriteHook_Ap_SrlComOutput_SU_EPS_SU_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS(TEMP_CPO_HET_MNG data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS_Start(data);
#if defined(IL_VECTOR_VERSION)
  Rte_ComHook_Com_TEMP_CPO_HET_MNG_EPS__RQ_STG_EFAN_EPS_SigTx(&data);
  (void)Com_SendSignal(Com_TEMP_CPO_HET_MNG_EPS__RQ_STG_EFAN_EPS, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR))(&data));
#else
  Rte_ComHook_Com_TEMP_CPO_HET_MNG_EPS__RQ_STG_EFAN_EPS_SigTx(&data);
  ret |= Com_SendSignal(Com_TEMP_CPO_HET_MNG_EPS__RQ_STG_EFAN_EPS, RTE_COM_SENDCAST(P2VAR(void, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_DATA))(&data));
#endif
  Rte_WriteHook_Ap_SrlComOutput_TEMP_CPO_HET_MNG_EPS_TEMP_CPO_HET_MNG_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS(P2CONST(RT_SG_AVL_PO_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS = *(data);
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD(P2CONST(RT_SG_AVL_FORC_GRD, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD = *(data);
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(P2CONST(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT = *(data);
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS(P2CONST(SG_DISP_CC_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS = *(data);
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComDTEST_DT_EST(P2CONST(SG_DT_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput2_SrlComDTEST_DT_EST_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComOutput2_SrlComDTEST_DT_EST = *(data);
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComOutput2_SrlComDTEST_DT_EST_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComSTEST_ST_EST(P2CONST(RT_SG_ST_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput2_SrlComSTEST_ST_EST_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComOutput2_SrlComSTEST_ST_EST = *(data);
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComOutput2_SrlComSTEST_ST_EST_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComOutput2_SrlComSUEPS_SU_EPS(P2CONST(RT_SG_SU_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT2_APPL_DATA) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_SrlComOutput2_SrlComSUEPS_SU_EPS_Start(data);
  SuspendOSInterrupts();
  Rte_SrlComOutput2_SrlComSUEPS_SU_EPS = *(data);
  ResumeOSInterrupts();
  Rte_WriteHook_Ap_SrlComOutput2_SrlComSUEPS_SU_EPS_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CFACTORIF_Cnt_lgc(Boolean data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_VehCfg_CFACTORIF_Cnt_lgc_Start(data);
  Rte_VehCfg_CFACTORIF_Cnt_lgc = *(&data);
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_VehCfgUpdate */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
  Rte_WriteHook_Ap_VehCfg_CFACTORIF_Cnt_lgc_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CHWANGLEIF_Cnt_lgc(Boolean data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_VehCfg_CHWANGLEIF_Cnt_lgc_Start(data);
  Rte_VehCfg_CHWANGLEIF_Cnt_lgc = *(&data);
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_VehCfgUpdate */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
  Rte_WriteHook_Ap_VehCfg_CHWANGLEIF_Cnt_lgc_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CHWTORQUEIF_Cnt_lgc(Boolean data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_VehCfg_CHWTORQUEIF_Cnt_lgc_Start(data);
  Rte_VehCfg_CHWTORQUEIF_Cnt_lgc = *(&data);
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_VehCfgUpdate */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
  Rte_WriteHook_Ap_VehCfg_CHWTORQUEIF_Cnt_lgc_Return(data);
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CMTTORQUEIF_Cnt_lgc(Boolean data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_WriteHook_Ap_VehCfg_CMTTORQUEIF_Cnt_lgc_Start(data);
  Rte_VehCfg_CMTTORQUEIF_Cnt_lgc = *(&data);
  Rte_Task_SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
  /* scheduled trigger for runnables: SrlComInput2_TRGD_VehCfgUpdate */
  (void)SetEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
  Rte_WriteHook_Ap_VehCfg_CMTTORQUEIF_Cnt_lgc_Return(data);
  return ret;
}


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ACLNY_MASSCNTR_ACLNY_MASSCNTR(P2VAR(SG_ACLNY_MASSCNTR, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_ACLNY_MASSCNTR_ACLNY_MASSCNTR_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR);
  (void)Com_ReceiveShadowSignal(Com_ACLNY_COG__ACLNY_MASSCNTR, &(*(data)).ACLNY_COG);
  Rte_ComHook_Com_ACLNY_COG__ACLNY_MASSCNTR_SigRx(&(*(data)).ACLNY_COG);
  (void)Com_ReceiveShadowSignal(Com_ACLNY_COG_ERR_AMP__ACLNY_MASSCNTR, &(*(data)).ACLNY_COG_ERR_AMP);
  Rte_ComHook_Com_ACLNY_COG_ERR_AMP__ACLNY_MASSCNTR_SigRx(&(*(data)).ACLNY_COG_ERR_AMP);
  (void)Com_ReceiveShadowSignal(Com_ACLNY_MASSCNTR_0x0C_0x04__ACLNY_MASSCNTR, &(*(data)).ACLNY_MASSCNTR_0x0C_0x04);
  Rte_ComHook_Com_ACLNY_MASSCNTR_0x0C_0x04__ACLNY_MASSCNTR_SigRx(&(*(data)).ACLNY_MASSCNTR_0x0C_0x04);
  (void)Com_ReceiveShadowSignal(Com_ALIV_ACLNY_COG__ACLNY_MASSCNTR, &(*(data)).ALIV_ACLNY_COG);
  Rte_ComHook_Com_ALIV_ACLNY_COG__ACLNY_MASSCNTR_SigRx(&(*(data)).ALIV_ACLNY_COG);
  (void)Com_ReceiveShadowSignal(Com_CRC_ACLNY_COG__ACLNY_MASSCNTR, &(*(data)).CRC_ACLNY_COG);
  Rte_ComHook_Com_CRC_ACLNY_COG__ACLNY_MASSCNTR_SigRx(&(*(data)).CRC_ACLNY_COG);
  (void)Com_ReceiveShadowSignal(Com_QU_ACLNY_COG__ACLNY_MASSCNTR, &(*(data)).QU_ACLNY_COG);
  Rte_ComHook_Com_QU_ACLNY_COG__ACLNY_MASSCNTR_SigRx(&(*(data)).QU_ACLNY_COG);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_ACLNY_MASSCNTR != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_ACLNY_MASSCNTR_ACLNY_MASSCNTR_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(P2VAR(AVL_STEA_PNI_OFFS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS_Start(data);
  (void)Com_ReceiveSignal(Com_AVL_STEA_PNI_OFFS__STEA_OFFS, (data));
  Rte_ComHook_Com_AVL_STEA_PNI_OFFS__STEA_OFFS_SigRx(data);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_AVL_STEA_PNI_OFFS != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_CON_VEH_CON_VEH(P2VAR(SG_CON_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_CON_VEH_CON_VEH_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_CON_VEH__CON_VEH);
  (void)Com_ReceiveShadowSignal(Com_ALIV_CON_VEH__CON_VEH, &(*(data)).ALIV_CON_VEH);
  Rte_ComHook_Com_ALIV_CON_VEH__CON_VEH_SigRx(&(*(data)).ALIV_CON_VEH);
  (void)Com_ReceiveShadowSignal(Com_CON_VEH_0x38_0x08__CON_VEH, &(*(data)).CON_VEH_0x38_0x08);
  Rte_ComHook_Com_CON_VEH_0x38_0x08__CON_VEH_SigRx(&(*(data)).CON_VEH_0x38_0x08);
  (void)Com_ReceiveShadowSignal(Com_CRC_CON_VEH__CON_VEH, &(*(data)).CRC_CON_VEH);
  Rte_ComHook_Com_CRC_CON_VEH__CON_VEH_SigRx(&(*(data)).CRC_CON_VEH);
  (void)Com_ReceiveShadowSignal(Com_CTR_BS_PRTNT__CON_VEH, &(*(data)).CTR_BS_PRTNT);
  Rte_ComHook_Com_CTR_BS_PRTNT__CON_VEH_SigRx(&(*(data)).CTR_BS_PRTNT);
  (void)Com_ReceiveShadowSignal(Com_CTR_FKTN_PRTNT__CON_VEH, &(*(data)).CTR_FKTN_PRTNT);
  Rte_ComHook_Com_CTR_FKTN_PRTNT__CON_VEH_SigRx(&(*(data)).CTR_FKTN_PRTNT);
  (void)Com_ReceiveShadowSignal(Com_QU_ST_CON_VEH__CON_VEH, &(*(data)).QU_ST_CON_VEH);
  Rte_ComHook_Com_QU_ST_CON_VEH__CON_VEH_SigRx(&(*(data)).QU_ST_CON_VEH);
  (void)Com_ReceiveShadowSignal(Com_ST_CON_VEH__CON_VEH, &(*(data)).ST_CON_VEH);
  Rte_ComHook_Com_ST_CON_VEH__CON_VEH_SigRx(&(*(data)).ST_CON_VEH);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_CON_VEH != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_CON_VEH_CON_VEH_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS(P2VAR(New_Coding_75, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS_Start(data);
  (void)Com_ReceiveSignal(Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015, (data));
  Rte_ComHook_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015_SigRx(data);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_ILVL_VIB_EPS != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS(P2VAR(New_Coding_71, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS_Start(data);
  (void)Com_ReceiveSignal(Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015, (data));
  Rte_ComHook_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015_SigRx(data);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_PTRN_VIB_EPS != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ENERG_DGR_DRDY_MAX_I_SPEC_EPS(P2VAR(New_Coding_94, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_ENERG_DGR_DRDY_MAX_I_SPEC_EPS_Start(data);
  (void)Com_ReceiveSignal(Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY, (data));
  Rte_ComHook_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY_SigRx(data);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_SPEC_EPS != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_ENERG_DGR_DRDY_MAX_I_SPEC_EPS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(P2VAR(SG_OFFS_QUAD_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS_Start(data);
  SuspendOSInterrupts();
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS);
  (void)Com_ReceiveShadowSignal(Com_ALIV_OFFS_QUAD_EPS__OFFS_QUAD_EPS, &(*(data)).ALIV_OFFS_QUAD_EPS);
  Rte_ComHook_Com_ALIV_OFFS_QUAD_EPS__OFFS_QUAD_EPS_SigRx(&(*(data)).ALIV_OFFS_QUAD_EPS);
  (void)Com_ReceiveShadowSignal(Com_AVL_PO_IDX_ICM__OFFS_QUAD_EPS, &(*(data)).AVL_PO_IDX_ICM);
  Rte_ComHook_Com_AVL_PO_IDX_ICM__OFFS_QUAD_EPS_SigRx(&(*(data)).AVL_PO_IDX_ICM);
  (void)Com_ReceiveShadowSignal(Com_CRC_OFFS_QUAD_EPS__OFFS_QUAD_EPS, &(*(data)).CRC_OFFS_QUAD_EPS);
  Rte_ComHook_Com_CRC_OFFS_QUAD_EPS__OFFS_QUAD_EPS_SigRx(&(*(data)).CRC_OFFS_QUAD_EPS);
  (void)Com_ReceiveShadowSignal(Com_OFFS_QUAD_RTR_EPS__OFFS_QUAD_EPS, &(*(data)).OFFS_QUAD_RTR_EPS);
  Rte_ComHook_Com_OFFS_QUAD_RTR_EPS__OFFS_QUAD_EPS_SigRx(&(*(data)).OFFS_QUAD_RTR_EPS);
  (void)Com_ReceiveShadowSignal(Com_ST_OFFS_QUAD_EPS__OFFS_QUAD_EPS, &(*(data)).ST_OFFS_QUAD_EPS);
  Rte_ComHook_Com_ST_OFFS_QUAD_EPS__OFFS_QUAD_EPS_SigRx(&(*(data)).ST_OFFS_QUAD_EPS);
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS = Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS_Sender;
#endif
  ResumeOSInterrupts();
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_OFFS_QUAD_EPS != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV(P2VAR(SG_TAR_QTA_STRMOM_DV, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV);
  (void)Com_ReceiveShadowSignal(Com_ALIV_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV, &(*(data)).ALIV_TAR_QTA_STMOM_DV);
  Rte_ComHook_Com_ALIV_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).ALIV_TAR_QTA_STMOM_DV);
  (void)Com_ReceiveShadowSignal(Com_CRC_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV, &(*(data)).CRC_TAR_QTA_STMOM_DV);
  Rte_ComHook_Com_CRC_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).CRC_TAR_QTA_STMOM_DV);
  (void)Com_ReceiveShadowSignal(Com_CTR_DEAC_EPS_FNS__TAR_QTA_STRMOM_DV, &(*(data)).CTR_DEAC_EPS_FNS);
  Rte_ComHook_Com_CTR_DEAC_EPS_FNS__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).CTR_DEAC_EPS_FNS);
  (void)Com_ReceiveShadowSignal(Com_FACT_ASS_STMOM_FTAX__TAR_QTA_STRMOM_DV, &(*(data)).FACT_ASS_STMOM_FTAX);
  Rte_ComHook_Com_FACT_ASS_STMOM_FTAX__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).FACT_ASS_STMOM_FTAX);
  (void)Com_ReceiveShadowSignal(Com_FACT_CTRR_STMOM_FTAX__TAR_QTA_STRMOM_DV, &(*(data)).FACT_CTRR_STMOM_FTAX);
  Rte_ComHook_Com_FACT_CTRR_STMOM_FTAX__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).FACT_CTRR_STMOM_FTAX);
  (void)Com_ReceiveShadowSignal(Com_FACT_DMPNG_STMOM_FTAX__TAR_QTA_STRMOM_DV, &(*(data)).FACT_DMPNG_STMOM_FTAX);
  Rte_ComHook_Com_FACT_DMPNG_STMOM_FTAX__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).FACT_DMPNG_STMOM_FTAX);
  (void)Com_ReceiveShadowSignal(Com_QU_TAR_FACT_STMOM_FTAX__TAR_QTA_STRMOM_DV, &(*(data)).QU_TAR_FACT_STMOM_FTAX);
  Rte_ComHook_Com_QU_TAR_FACT_STMOM_FTAX__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).QU_TAR_FACT_STMOM_FTAX);
  (void)Com_ReceiveShadowSignal(Com_QU_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV, &(*(data)).QU_TAR_QTA_STMOM_DV);
  Rte_ComHook_Com_QU_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).QU_TAR_QTA_STMOM_DV);
  (void)Com_ReceiveShadowSignal(Com_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV, &(*(data)).TAR_QTA_STMOM_DV);
  Rte_ComHook_Com_TAR_QTA_STMOM_DV__TAR_QTA_STRMOM_DV_SigRx(&(*(data)).TAR_QTA_STMOM_DV);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_TAR_QTA_STRMOM_DV != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT(P2VAR(SG_TAR_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT);
  (void)Com_ReceiveShadowSignal(Com_ALIV_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT, &(*(data)).ALIV_TAR_STMOM_DV_ACT);
  Rte_ComHook_Com_ALIV_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT_SigRx(&(*(data)).ALIV_TAR_STMOM_DV_ACT);
  (void)Com_ReceiveShadowSignal(Com_CRC_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT, &(*(data)).CRC_TAR_STMOM_DV_ACT);
  Rte_ComHook_Com_CRC_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT_SigRx(&(*(data)).CRC_TAR_STMOM_DV_ACT);
  (void)Com_ReceiveShadowSignal(Com_FACT_DMPNG_ADDON_STMOM_FTAX__TAR_STMOM_DV_ACT, &(*(data)).FACT_DMPNG_ADDON_STMOM_FTAX);
  Rte_ComHook_Com_FACT_DMPNG_ADDON_STMOM_FTAX__TAR_STMOM_DV_ACT_SigRx(&(*(data)).FACT_DMPNG_ADDON_STMOM_FTAX);
  (void)Com_ReceiveShadowSignal(Com_QU_TAR_DMPNG_ADDON_STMOM_FTAX__TAR_STMOM_DV_ACT, &(*(data)).QU_TAR_DMPNG_ADDON_STMOM_FTAX);
  Rte_ComHook_Com_QU_TAR_DMPNG_ADDON_STMOM_FTAX__TAR_STMOM_DV_ACT_SigRx(&(*(data)).QU_TAR_DMPNG_ADDON_STMOM_FTAX);
  (void)Com_ReceiveShadowSignal(Com_QU_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT, &(*(data)).QU_TAR_STMOM_DV_ACT);
  Rte_ComHook_Com_QU_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT_SigRx(&(*(data)).QU_TAR_STMOM_DV_ACT);
  (void)Com_ReceiveShadowSignal(Com_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT, &(*(data)).TAR_STMOM_DV_ACT);
  Rte_ComHook_Com_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT_SigRx(&(*(data)).TAR_STMOM_DV_ACT);
  Rte_ReadHook_Ap_SrlComInput_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SG_V_VEH_SG_V_VEH(P2VAR(SG_V_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_SG_V_VEH_SG_V_VEH_Start(data);
#if defined(IL_VECTOR_VERSION)
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_V_VEH__V_VEH);
  (void)Com_ReceiveShadowSignal(Com_ALIV_V_VEH__V_VEH, &(*(data)).ALIV_V_VEH);
  Rte_ComHook_Com_ALIV_V_VEH__V_VEH_SigRx(&(*(data)).ALIV_V_VEH);
  (void)Com_ReceiveShadowSignal(Com_CRC_V_VEH__V_VEH, &(*(data)).CRC_V_VEH);
  Rte_ComHook_Com_CRC_V_VEH__V_VEH_SigRx(&(*(data)).CRC_V_VEH);
  (void)Com_ReceiveShadowSignal(Com_DVCO_VEH__V_VEH, &(*(data)).DVCO_VEH);
  Rte_ComHook_Com_DVCO_VEH__V_VEH_SigRx(&(*(data)).DVCO_VEH);
  (void)Com_ReceiveShadowSignal(Com_QU_V_VEH_COG__V_VEH, &(*(data)).QU_V_VEH_COG);
  Rte_ComHook_Com_QU_V_VEH_COG__V_VEH_SigRx(&(*(data)).QU_V_VEH_COG);
  (void)Com_ReceiveShadowSignal(Com_ST_V_VEH_NSS__V_VEH, &(*(data)).ST_V_VEH_NSS);
  Rte_ComHook_Com_ST_V_VEH_NSS__V_VEH_SigRx(&(*(data)).ST_V_VEH_NSS);
  (void)Com_ReceiveShadowSignal(Com_V_VEH_0x27_0x01__V_VEH, (P2VAR(uint8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR))&(*(data)).V_VEH_0x27_0x01);
  Rte_ComHook_Com_V_VEH_0x27_0x01__V_VEH_SigRx(&(*(data)).V_VEH_0x27_0x01);
  (void)Com_ReceiveShadowSignal(Com_V_VEH_COG__V_VEH, &(*(data)).V_VEH_COG);
  Rte_ComHook_Com_V_VEH_COG__V_VEH_SigRx(&(*(data)).V_VEH_COG);
#else
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_V_VEH__V_VEH);
  (void)Com_ReceiveShadowSignal(Com_ALIV_V_VEH__V_VEH, &(*(data)).ALIV_V_VEH);
  Rte_ComHook_Com_ALIV_V_VEH__V_VEH_SigRx(&(*(data)).ALIV_V_VEH);
  (void)Com_ReceiveShadowSignal(Com_CRC_V_VEH__V_VEH, &(*(data)).CRC_V_VEH);
  Rte_ComHook_Com_CRC_V_VEH__V_VEH_SigRx(&(*(data)).CRC_V_VEH);
  (void)Com_ReceiveShadowSignal(Com_DVCO_VEH__V_VEH, &(*(data)).DVCO_VEH);
  Rte_ComHook_Com_DVCO_VEH__V_VEH_SigRx(&(*(data)).DVCO_VEH);
  (void)Com_ReceiveShadowSignal(Com_QU_V_VEH_COG__V_VEH, &(*(data)).QU_V_VEH_COG);
  Rte_ComHook_Com_QU_V_VEH_COG__V_VEH_SigRx(&(*(data)).QU_V_VEH_COG);
  (void)Com_ReceiveShadowSignal(Com_ST_V_VEH_NSS__V_VEH, &(*(data)).ST_V_VEH_NSS);
  Rte_ComHook_Com_ST_V_VEH_NSS__V_VEH_SigRx(&(*(data)).ST_V_VEH_NSS);
  (void)Com_ReceiveShadowSignal(Com_V_VEH_0x27_0x01__V_VEH, &(*(data)).V_VEH_0x27_0x01);
  Rte_ComHook_Com_V_VEH_0x27_0x01__V_VEH_SigRx(&(*(data)).V_VEH_0x27_0x01);
  (void)Com_ReceiveShadowSignal(Com_V_VEH_COG__V_VEH, &(*(data)).V_VEH_COG);
  Rte_ComHook_Com_V_VEH_COG__V_VEH_SigRx(&(*(data)).V_VEH_COG);
#endif
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_V_VEH != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_SG_V_VEH_SG_V_VEH_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ST_CENG_ST_CENG(P2VAR(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_ST_CENG_ST_CENG_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_ST_CENG__ST_CENG);
  (void)Com_ReceiveShadowSignal(Com_ALIV_ST_CENG__ST_CENG, &(*(data)).ALIV_ST_CENG);
  Rte_ComHook_Com_ALIV_ST_CENG__ST_CENG_SigRx(&(*(data)).ALIV_ST_CENG);
  (void)Com_ReceiveShadowSignal(Com_CRC_ST_CENG__ST_CENG, &(*(data)).CRC_ST_CENG);
  Rte_ComHook_Com_CRC_ST_CENG__ST_CENG_SigRx(&(*(data)).CRC_ST_CENG);
  (void)Com_ReceiveShadowSignal(Com_CTR_LED_PUBU_MSA__ST_CENG, &(*(data)).CTR_LED_PUBU_MSA);
  Rte_ComHook_Com_CTR_LED_PUBU_MSA__ST_CENG_SigRx(&(*(data)).CTR_LED_PUBU_MSA);
  (void)Com_ReceiveShadowSignal(Com_ST_ANO_MSA_ENG_STOP__ST_CENG, &(*(data)).ST_ANO_MSA_ENG_STOP);
  Rte_ComHook_Com_ST_ANO_MSA_ENG_STOP__ST_CENG_SigRx(&(*(data)).ST_ANO_MSA_ENG_STOP);
  (void)Com_ReceiveShadowSignal(Com_ST_CENG_0x0C_0x04__ST_CENG, &(*(data)).ST_CENG_0x0C_0x04);
  Rte_ComHook_Com_ST_CENG_0x0C_0x04__ST_CENG_SigRx(&(*(data)).ST_CENG_0x0C_0x04);
  (void)Com_ReceiveShadowSignal(Com_ST_CENG_0x2A_0x16__ST_CENG, &(*(data)).ST_CENG_0x2A_0x16);
  Rte_ComHook_Com_ST_CENG_0x2A_0x16__ST_CENG_SigRx(&(*(data)).ST_CENG_0x2A_0x16);
  (void)Com_ReceiveShadowSignal(Com_ST_CENG_DRV__ST_CENG, &(*(data)).ST_CENG_DRV);
  Rte_ComHook_Com_ST_CENG_DRV__ST_CENG_SigRx(&(*(data)).ST_CENG_DRV);
  (void)Com_ReceiveShadowSignal(Com_ST_ENERG_SUPY__ST_CENG, &(*(data)).ST_ENERG_SUPY);
  Rte_ComHook_Com_ST_ENERG_SUPY__ST_CENG_SigRx(&(*(data)).ST_ENERG_SUPY);
  (void)Com_ReceiveShadowSignal(Com_ST_MOT_DRV__ST_CENG, &(*(data)).ST_MOT_DRV);
  Rte_ComHook_Com_ST_MOT_DRV__ST_CENG_SigRx(&(*(data)).ST_MOT_DRV);
  (void)Com_ReceiveShadowSignal(Com_ST_UDP__ST_CENG, &(*(data)).ST_UDP);
  Rte_ComHook_Com_ST_UDP__ST_CENG_SigRx(&(*(data)).ST_UDP);
  (void)Com_ReceiveShadowSignal(Com_TR_HHASS_MSA__ST_CENG, &(*(data)).TR_HHASS_MSA);
  Rte_ComHook_Com_TR_HHASS_MSA__ST_CENG_SigRx(&(*(data)).TR_HHASS_MSA);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_ST_CENG != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_ST_CENG_ST_CENG_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP(P2VAR(New_Coding_79, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP_Start(data);
  (void)Com_ReceiveSignal(Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP, (data));
  Rte_ComHook_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP_SigRx(data);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_STMOM_SFE_DXP != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_VYAW_VEH_VYAW_VEH(P2VAR(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput_VYAW_VEH_VYAW_VEH_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_VYAW_VEH__VYAW_VEH);
  (void)Com_ReceiveShadowSignal(Com_ALIV_VYAW_VEH__VYAW_VEH, &(*(data)).ALIV_VYAW_VEH);
  Rte_ComHook_Com_ALIV_VYAW_VEH__VYAW_VEH_SigRx(&(*(data)).ALIV_VYAW_VEH);
  (void)Com_ReceiveShadowSignal(Com_CRC_VYAW_VEH__VYAW_VEH, &(*(data)).CRC_VYAW_VEH);
  Rte_ComHook_Com_CRC_VYAW_VEH__VYAW_VEH_SigRx(&(*(data)).CRC_VYAW_VEH);
  (void)Com_ReceiveShadowSignal(Com_QU_VYAW_VEH__VYAW_VEH, &(*(data)).QU_VYAW_VEH);
  Rte_ComHook_Com_QU_VYAW_VEH__VYAW_VEH_SigRx(&(*(data)).QU_VYAW_VEH);
  (void)Com_ReceiveShadowSignal(Com_VYAW_VEH__VYAW_VEH, &(*(data)).VYAW_VEH);
  Rte_ComHook_Com_VYAW_VEH__VYAW_VEH_SigRx(&(*(data)).VYAW_VEH);
  (void)Com_ReceiveShadowSignal(Com_VYAW_VEH_0x0C_0x04__VYAW_VEH, &(*(data)).VYAW_VEH_0x0C_0x04);
  Rte_ComHook_Com_VYAW_VEH_0x0C_0x04__VYAW_VEH_SigRx(&(*(data)).VYAW_VEH_0x0C_0x04);
  (void)Com_ReceiveShadowSignal(Com_VYAW_VEH_ERR_AMP__VYAW_VEH, &(*(data)).VYAW_VEH_ERR_AMP);
  Rte_ComHook_Com_VYAW_VEH_ERR_AMP__VYAW_VEH_SigRx(&(*(data)).VYAW_VEH_ERR_AMP);
  if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_VYAW_VEH != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }
  Rte_ReadHook_Ap_SrlComInput_VYAW_VEH_VYAW_VEH_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(P2VAR(SG_ACLNY_MASSCNTR, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR;
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR = Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_Sender;
#endif
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComCONVEH_CON_VEH(P2VAR(SG_CON_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput2_SrlComCONVEH_CON_VEH_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_SrlComInput_SrlComCONVEH_CON_VEH;
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComCONVEH_CON_VEH = Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComCONVEH_CON_VEH_Sender;
#endif
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComInput2_SrlComCONVEH_CON_VEH_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(P2VAR(SG_OFFS_QUAD_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS;
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS = Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_Sender;
#endif
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(P2VAR(SG_TAR_QTA_STRMOM_DV, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV;
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV = Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_Sender;
#endif
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(P2VAR(SG_TAR_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT;
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT = Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_Sender;
#endif
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH(P2VAR(SG_V_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_SrlComInput_SrlComSGVVEH_SG_V_VEH;
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGVVEH_SG_V_VEH = Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGVVEH_SG_V_VEH_Sender;
#endif
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSTCENG_ST_CENG(P2VAR(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput2_SrlComSTCENG_ST_CENG_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_SrlComInput_SrlComSTCENG_ST_CENG;
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComInput2_SrlComSTCENG_ST_CENG_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH(P2VAR(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_SrlComInput_SrlComVYAWVEH_VYAW_VEH;
#ifndef RTE_DISABLE_ISUPDATED
  Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComVYAWVEH_VYAW_VEH = Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComVYAWVEH_VYAW_VEH_Sender;
#endif
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul(P2VAR(SG_ANFRAGE_DSC_Modul, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_ANFRAGE_DSC_Modul__ANFRAGE_DSC_Modul);
  (void)Com_ReceiveShadowSignal(Com_ID2_0x08_Mx01_DSC_Modul__ANFRAGE_DSC_Modul, &(*(data)).ID2_0x08_Mx01_DSC_Modul);
  Rte_ComHook_Com_ID2_0x08_Mx01_DSC_Modul__ANFRAGE_DSC_Modul_SigRx(&(*(data)).ID2_0x08_Mx01_DSC_Modul);
  (void)Com_ReceiveShadowSignal(Com_ID_FN_INQY_DSC_Modul__ANFRAGE_DSC_Modul, &(*(data)).ID_FN_INQY_DSC_Modul);
  Rte_ComHook_Com_ID_FN_INQY_DSC_Modul__ANFRAGE_DSC_Modul_SigRx(&(*(data)).ID_FN_INQY_DSC_Modul);
  Rte_ReadHook_Ap_SrlComOutput_SG_ANFRAGE_DSC_Modul_SG_ANFRAGE_DSC_Modul_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS(P2VAR(SG_ANFRAGE_SAS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_ANFRAGE_SAS__ANFRAGE_SAS);
  (void)Com_ReceiveShadowSignal(Com_ID2_0x08_Mx01_SAS__ANFRAGE_SAS, &(*(data)).ID2_0x08_Mx01_SAS);
  Rte_ComHook_Com_ID2_0x08_Mx01_SAS__ANFRAGE_SAS_SigRx(&(*(data)).ID2_0x08_Mx01_SAS);
  (void)Com_ReceiveShadowSignal(Com_ID_FN_INQY_SAS__ANFRAGE_SAS, &(*(data)).ID_FN_INQY_SAS);
  Rte_ComHook_Com_ID_FN_INQY_SAS__ANFRAGE_SAS_SigRx(&(*(data)).ID_FN_INQY_SAS);
  Rte_ReadHook_Ap_SrlComOutput_SG_ANFRAGE_SAS_SG_ANFRAGE_SAS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW(P2VAR(SG_ANFRAGE_ZGW, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW_Start(data);
  (void)Com_ReceiveSignalGroup(Com_Grp_SG_ANFRAGE_ZGW__ANFRAGE_ZGW);
  (void)Com_ReceiveShadowSignal(Com_ID2_0x08_Mx01_ZGW__ANFRAGE_ZGW, &(*(data)).ID2_0x08_Mx01_ZGW);
  Rte_ComHook_Com_ID2_0x08_Mx01_ZGW__ANFRAGE_ZGW_SigRx(&(*(data)).ID2_0x08_Mx01_ZGW);
  (void)Com_ReceiveShadowSignal(Com_ID_FN_INQY_ZGW__ANFRAGE_ZGW, &(*(data)).ID_FN_INQY_ZGW);
  Rte_ComHook_Com_ID_FN_INQY_ZGW__ANFRAGE_ZGW_SigRx(&(*(data)).ID_FN_INQY_ZGW);
  Rte_ReadHook_Ap_SrlComOutput_SG_ANFRAGE_ZGW_SG_ANFRAGE_ZGW_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ST_DIAG_OBD_DATA(P2VAR(Edch_EventStatusIpduDataType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_ST_DIAG_OBD_DATA_Start(data);
  SuspendOSInterrupts();
  *(data) = Rte_Edch_ST_DIAG_OBD_DATA;
  ResumeOSInterrupts();
  Rte_ReadHook_Ap_SrlComOutput_ST_DIAG_OBD_DATA_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLPOEPS_AVL_PO_EPS(P2VAR(RT_SG_AVL_PO_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SrlComAVLPOEPS_AVL_PO_EPS_Start(data);
  *(data) = Rte_SrlComOutput2_SrlComAVLPOEPS_AVL_PO_EPS;
  Rte_ReadHook_Ap_SrlComOutput_SrlComAVLPOEPS_AVL_PO_EPS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_FORC_GRD(P2VAR(RT_SG_AVL_FORC_GRD, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_FORC_GRD_Start(data);
  *(data) = Rte_SrlComOutput2_SrlComAVLSTMOM_AVL_FORC_GRD;
  Rte_ReadHook_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_FORC_GRD_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(P2VAR(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_STMOM_DV_ACT_Start(data);
  *(data) = Rte_SrlComOutput2_SrlComAVLSTMOM_AVL_STMOM_DV_ACT;
  Rte_ReadHook_Ap_SrlComOutput_SrlComAVLSTMOM_AVL_STMOM_DV_ACT_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComDISPCCEPS_DISP_CC_EPS(P2VAR(SG_DISP_CC_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SrlComDISPCCEPS_DISP_CC_EPS_Start(data);
  *(data) = Rte_SrlComOutput2_SrlComDISPCCEPS_DISP_CC_EPS;
  Rte_ReadHook_Ap_SrlComOutput_SrlComDISPCCEPS_DISP_CC_EPS_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComDTEST_DT_EST(P2VAR(SG_DT_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SrlComDTEST_DT_EST_Start(data);
  *(data) = Rte_SrlComOutput2_SrlComDTEST_DT_EST;
  Rte_ReadHook_Ap_SrlComOutput_SrlComDTEST_DT_EST_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComSTEST_ST_EST(P2VAR(RT_SG_ST_EST, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SrlComSTEST_ST_EST_Start(data);
  *(data) = Rte_SrlComOutput2_SrlComSTEST_ST_EST;
  Rte_ReadHook_Ap_SrlComOutput_SrlComSTEST_ST_EST_Return(data);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComSUEPS_SU_EPS(P2VAR(RT_SG_SU_EPS, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ReadHook_Ap_SrlComOutput_SrlComSUEPS_SU_EPS_Start(data);
  *(data) = Rte_SrlComOutput2_SrlComSUEPS_SU_EPS;
  Rte_ReadHook_Ap_SrlComOutput_SrlComSUEPS_SU_EPS_Return(data);

  return ret;
}


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgment handling (Rte_Feedback)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_EcuM_currentMode_currentMode(void)
{
  Std_ReturnType ret = RTE_E_TRANSMIT_ACK;

  Rte_FeedbackHook_EcuM_currentMode_currentMode_Start();

  if (Rte_Ap_9_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack == 0)
  {
    ret = RTE_E_NO_DATA;
  }
  Rte_FeedbackHook_EcuM_currentMode_currentMode_Return();
  return ret;
}


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_currentMode_currentMode(Rte_ModeType_EcuM_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_EcuM_currentMode_currentMode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_EcuM_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_EcuM_currentMode_currentMode == RTE_TRANSITION_EcuM_Mode)
  {
    if (Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr != Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr)
    {
      Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueue[Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr] = nextMode;

      if (Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr < (2-1))
      {
        Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr++;
      }
      else
      {
        Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr = 0;
      }

      Rte_Ap_9_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack = 0;
    }
    else
    {
      ret = RTE_E_LIMIT;
    }
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;

    ModeSwitchEventMask = Rte_ModeEntryEventMask_EcuM_currentMode_currentMode[nextMode];

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueue[Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr] = nextMode;
      if (Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr < (2-1))
      {
        Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr++;
      }
      else
      {
        Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr = 0;
      }

      Rte_ModeMachine_EcuM_currentMode_currentMode = RTE_TRANSITION_EcuM_Mode;
      Rte_Ap_9_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack = 0;
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_InitB_9, ModeSwitchEventMask);
      (void)SetEvent(Task_InitB_9, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_EcuM_currentMode_currentMode = nextMode;
      Rte_Ap_9_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack = 1;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_EcuM_currentMode_currentMode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgment handling (Rte_Feedback)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_Edch_ST_DIAG_OBD_MUX_IMME(void)
{
  Std_ReturnType ret = RTE_E_TRANSMIT_ACK;

  Rte_FeedbackHook_Edch_ST_DIAG_OBD_MUX_IMME_Start();
  Rte_FeedbackHook_Edch_ST_DIAG_OBD_MUX_IMME_Return();
  return ret;
}


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  if (nextMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2 < Rte_TriggerDisableMaxCount_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1++;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode previousMode)
{
  if (previousMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1--;
  }
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_StaMd_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_StaMd_SystemState_Mode == RTE_TRANSITION_StaMd_Mode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    Rte_ModeType_StaMd_Mode currentMode = Rte_ModeMachine_StaMd_SystemState_Mode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_StaMd_SystemState_Mode[currentMode] | Rte_ModeEntryEventMask_StaMd_SystemState_Mode[nextMode];

    if ((ModeSwitchEventMask == (EventMaskType)0) && (currentMode != nextMode))
    {
      if (nextMode == RTE_MODE_StaMd_Mode_OFF)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_10;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_10;
      }
    }

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[0] = nextMode;
      Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[1] = currentMode;

      Rte_ModeMachine_StaMd_SystemState_Mode = RTE_TRANSITION_StaMd_Mode;
      if (currentMode != nextMode)
      {
        Rte_IncDisableFlags_StaMd_SystemState_Mode(nextMode);
      }
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_Trns_10, ModeSwitchEventMask);
      (void)SetEvent(Task_Trns_10, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_StaMd_SystemState_Mode = nextMode;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd11_SystemState11_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1++;
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1++;
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_OPERATE)
  {
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1++;
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2++;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd11_SystemState11_Mode(Rte_ModeType_StaMd_Mode previousMode)
{
  if (previousMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1--;
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1--;
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_OPERATE)
  {
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1--;
    Rte_Assert(Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2--;
  }
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd11_SystemState11_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_Ap_StaMd11_SystemState11_Mode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_StaMd_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_StaMd11_SystemState11_Mode == RTE_TRANSITION_StaMd_Mode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    Rte_ModeType_StaMd_Mode currentMode = Rte_ModeMachine_StaMd11_SystemState11_Mode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_StaMd11_SystemState11_Mode[currentMode] | Rte_ModeEntryEventMask_StaMd11_SystemState11_Mode[nextMode];

    if ((ModeSwitchEventMask == (EventMaskType)0) && (currentMode != nextMode))
    {
      if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_11;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_11;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_OPERATE)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_11;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_11;
      }
    }

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_StaMd11_SystemState11_Mode.Rte_ModeQueue[0] = nextMode;
      Rte_ModeInfo_StaMd11_SystemState11_Mode.Rte_ModeQueue[1] = currentMode;

      Rte_ModeMachine_StaMd11_SystemState11_Mode = RTE_TRANSITION_StaMd_Mode;
      if (currentMode != nextMode)
      {
        Rte_IncDisableFlags_StaMd11_SystemState11_Mode(nextMode);
      }
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_Trns_11, ModeSwitchEventMask);
      (void)SetEvent(Task_Trns_11, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_StaMd11_SystemState11_Mode = nextMode;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_Ap_StaMd11_SystemState11_Mode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd7_SystemState7_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_CustPL_CustPL_Per1 < Rte_TriggerDisableMaxCount_Task_10ms_7_Rte_Trigger1_CustPL_CustPL_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_CustPL_CustPL_Per1++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per2 < Rte_TriggerDisableMaxCount_Task_10ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per2++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per1++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 < Rte_TriggerDisableMaxCount_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3 < Rte_TriggerDisableMaxCount_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_DrvDynamicsEnable_DrvDynEnbl_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_DrvDynamicsEnable_DrvDynEnbl_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_DrvDynamicsEnable_DrvDynEnbl_Per1++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 < Rte_TriggerDisableMaxCount_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_OPERATE)
  {
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3 < Rte_TriggerDisableMaxCount_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3++;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 < Rte_TriggerDisableMaxCount_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2++;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd7_SystemState7_Mode(Rte_ModeType_StaMd_Mode previousMode)
{
  if (previousMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_CustPL_CustPL_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_CustPL_CustPL_Per1--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per2--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per1--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_DrvDynamicsEnable_DrvDynEnbl_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_DrvDynamicsEnable_DrvDynEnbl_Per1--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_OPERATE)
  {
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3--;
    Rte_Assert(Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2--;
  }
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd7_SystemState7_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_Ap_StaMd7_SystemState7_Mode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_StaMd_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_StaMd7_SystemState7_Mode == RTE_TRANSITION_StaMd_Mode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    Rte_ModeType_StaMd_Mode currentMode = Rte_ModeMachine_StaMd7_SystemState7_Mode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_StaMd7_SystemState7_Mode[currentMode] | Rte_ModeEntryEventMask_StaMd7_SystemState7_Mode[nextMode];

    if ((ModeSwitchEventMask == (EventMaskType)0) && (currentMode != nextMode))
    {
      if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_7;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_7;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_OPERATE)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_7;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_7;
      }
    }

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_StaMd7_SystemState7_Mode.Rte_ModeQueue[0] = nextMode;
      Rte_ModeInfo_StaMd7_SystemState7_Mode.Rte_ModeQueue[1] = currentMode;

      Rte_ModeMachine_StaMd7_SystemState7_Mode = RTE_TRANSITION_StaMd_Mode;
      if (currentMode != nextMode)
      {
        Rte_IncDisableFlags_StaMd7_SystemState7_Mode(nextMode);
      }
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_Trns_7, ModeSwitchEventMask);
      (void)SetEvent(Task_Trns_7, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_StaMd7_SystemState7_Mode = nextMode;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_Ap_StaMd7_SystemState7_Mode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd8_SystemState8_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  if (nextMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_8_TriggerDisableFlags.Rte_Trigger_Task_2ms_8_Rte_Trigger1_Gsod_Gsod_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_8_Rte_Trigger1_Gsod_Gsod_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_8_TriggerDisableFlags.Rte_Trigger_Task_2ms_8_Rte_Trigger1_Gsod_Gsod_Per1++;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd8_SystemState8_Mode(Rte_ModeType_StaMd_Mode previousMode)
{
  if (previousMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_8_TriggerDisableFlags.Rte_Trigger_Task_2ms_8_Rte_Trigger1_Gsod_Gsod_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_8_TriggerDisableFlags.Rte_Trigger_Task_2ms_8_Rte_Trigger1_Gsod_Gsod_Per1--;
  }
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd8_SystemState8_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_StaMd_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_StaMd8_SystemState8_Mode == RTE_TRANSITION_StaMd_Mode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    Rte_ModeType_StaMd_Mode currentMode = Rte_ModeMachine_StaMd8_SystemState8_Mode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_StaMd8_SystemState8_Mode[currentMode] | Rte_ModeEntryEventMask_StaMd8_SystemState8_Mode[nextMode];

    if ((ModeSwitchEventMask == (EventMaskType)0) && (currentMode != nextMode))
    {
      if (nextMode == RTE_MODE_StaMd_Mode_OFF)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_8;
      }
    }

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_StaMd8_SystemState8_Mode.Rte_ModeQueue[0] = nextMode;
      Rte_ModeInfo_StaMd8_SystemState8_Mode.Rte_ModeQueue[1] = currentMode;

      Rte_ModeMachine_StaMd8_SystemState8_Mode = RTE_TRANSITION_StaMd_Mode;
      if (currentMode != nextMode)
      {
        Rte_IncDisableFlags_StaMd8_SystemState8_Mode(nextMode);
      }
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_Trns_8, ModeSwitchEventMask);
      (void)SetEvent(Task_Trns_8, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_StaMd8_SystemState8_Mode = nextMode;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 < Rte_TriggerDisableMaxCount_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 < Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 < Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_DiagMgr9_DiagMgr_Per2 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_DiagMgr9_DiagMgr_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_DiagMgr9_DiagMgr_Per2++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 < Rte_TriggerDisableMaxCount_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 < Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per2 < Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per2++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 < Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 < Rte_TriggerDisableMaxCount_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 < Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 < Rte_TriggerDisableMaxCount_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1++;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode previousMode)
{
  if (previousMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_DiagMgr9_DiagMgr_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_DiagMgr9_DiagMgr_Per2--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per2--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1--;
  }
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_StaMd_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_StaMd9_SystemState9_Mode == RTE_TRANSITION_StaMd_Mode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    Rte_ModeType_StaMd_Mode currentMode = Rte_ModeMachine_StaMd9_SystemState9_Mode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_StaMd9_SystemState9_Mode[currentMode] | Rte_ModeEntryEventMask_StaMd9_SystemState9_Mode[nextMode];

    if ((ModeSwitchEventMask == (EventMaskType)0) && (currentMode != nextMode))
    {
      if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_9;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_9;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trns_9;
      }
    }

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_StaMd9_SystemState9_Mode.Rte_ModeQueue[0] = nextMode;
      Rte_ModeInfo_StaMd9_SystemState9_Mode.Rte_ModeQueue[1] = currentMode;

      Rte_ModeMachine_StaMd9_SystemState9_Mode = RTE_TRANSITION_StaMd_Mode;
      if (currentMode != nextMode)
      {
        Rte_IncDisableFlags_StaMd9_SystemState9_Mode(nextMode);
      }
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_Trns_9, ModeSwitchEventMask);
      (void)SetEvent(Task_Trns_9, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_StaMd9_SystemState9_Mode = nextMode;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * COM-Callbacks for DataReceivedEvent triggered runnables, for queued com. and for Rx timeout / Rx inv. flag (reset)
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_Com_AVL_STEA_PNI_OFFS__STEA_OFFS(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_AVL_STEA_PNI_OFFS__STEA_OFFS();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_AVL_STEA_PNI_OFFS = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxAvlSteaPniOffs */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_BE_CHOV_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_BE_CHOV_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_BE_CHOV_CLU_VE_DYNMC_DXP = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_ACDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_ACDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_ACDU_IVIB_STW = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_DIM_DSE_EXMI__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_DIM_DSE_EXMI__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_DIM_DSE_EXMI = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_PRG_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_PRG_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_PRG_IVIB_STW = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_PSDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_PSDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_PSDU_IVIB_STW = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_VIB_STW = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_DIR_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_WARN_DIR_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_DIR_VIB_EPS = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_ILVL_VIB_EPS = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxCtrVibStwDisp */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_ILVL_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_WARN_ILVL_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_ILVL_VIB_STW = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_LGA_DSE_1_LH__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_WARN_LGA_DSE_1_LH__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_LGA_DSE_1_LH = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_LGA_DSE_1_RH__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_WARN_LGA_DSE_1_RH__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_LGA_DSE_1_RH = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_PTRN_VIB_EPS = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxCtrVibStwDisp */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_ENERG_AVAI_ARS__ENERG_DGR_DRDY(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_ENERG_AVAI_ARS__ENERG_DGR_DRDY();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_ENERG_AVAI_ARS = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_FACT_MO_STE_SO_DXP__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_FACT_MO_STE_SO_DXP__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_FACT_MO_STE_SO_DXP = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_ACLNY_MASSCNTR = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAclnyCog);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxAclnyCog */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAclnyCog);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ANFRAGE_DSC_Modul__ANFRAGE_DSC_Modul(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_ANFRAGE_DSC_Modul__ANFRAGE_DSC_Modul();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
    /* scheduled trigger for runnables: SrlComOutput_TRGD_SVCRequest */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ANFRAGE_SAS__ANFRAGE_SAS(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_ANFRAGE_SAS__ANFRAGE_SAS();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
    /* scheduled trigger for runnables: SrlComOutput_TRGD_SVCRequest */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ANFRAGE_ZGW__ANFRAGE_ZGW(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_ANFRAGE_ZGW__ANFRAGE_ZGW();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
    /* scheduled trigger for runnables: SrlComOutput_TRGD_SVCRequest */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_CON_VEH__CON_VEH(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_CON_VEH__CON_VEH();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_CON_VEH = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxConVeh);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxConVeh */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxConVeh);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_FAHRGESTELLNUMMER = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVIN);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxVIN */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVIN);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS();
#ifndef RTE_DISABLE_ISUPDATED
    DisableAllInterrupts();
    Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS_Sender = !Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS;
    EnableAllInterrupts();
#endif

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_OFFS_QUAD_EPS = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffset);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxRevOffset */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffset);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ST_CENG__ST_CENG(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_ST_CENG__ST_CENG();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_ST_CENG = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxStCeng);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxStCeng */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxStCeng);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_TAR_QTA_STRMOM_DV = 0;
    EnableAllInterrupts();

  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxPaDrvDyn */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_VYAW_VEH__VYAW_VEH(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_VYAW_VEH__VYAW_VEH();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_VYAW_VEH = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVYawVeh);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxVYawVeh */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVYawVeh);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_V_VEH__V_VEH(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_Grp_SG_V_VEH__V_VEH();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_V_VEH = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVehSpd);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxVehSpd */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVehSpd);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_MAX_I_LD_SPEC_ARS__ENERG_DGR_DRDY(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_MAX_I_LD_SPEC_ARS__ENERG_DGR_DRDY();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_LD_SPEC_ARS = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_MAX_I_RECUP_SPEC_ARS__ENERG_DGR_DRDY(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_MAX_I_RECUP_SPEC_ARS__ENERG_DGR_DRDY();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_RECUP_SPEC_ARS = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_MAX_I_SPEC_BAX_STE__ENERG_DGR_DRDY(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_MAX_I_SPEC_BAX_STE__ENERG_DGR_DRDY();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_SPEC_BAX_STE = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_SPEC_EPS = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxEnergDgrDrdy */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_MILE_KM__KILOMETERSTAND(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_MILE_KM__KILOMETERSTAND();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MILE_KM = 0;
    EnableAllInterrupts();

  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_QU_DGR_AISP_ENERG__ENERG_DGR_DRDY(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_QU_DGR_AISP_ENERG__ENERG_DGR_DRDY();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_QU_DGR_AISP_ENERG = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_RQ_RST_OBD_DIAG_DRDY__CTR_DIAG_OBD_DRDY(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_RQ_RST_OBD_DIAG_DRDY__CTR_DIAG_OBD_DRDY();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_Edch_RE_ClearErrorMem);
    /* scheduled trigger for runnables: RE_ClearErrorMem */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_Edch_RE_ClearErrorMem);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_ST_ILK_ERRM_FZM__FZZSTD(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_ST_ILK_ERRM_FZM__FZZSTD();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_ST_ILK_ERRM_FZM = 0;
    EnableAllInterrupts();

  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_ST_OBD_CYC__DIAG_OBD_ENG(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_ST_OBD_CYC__DIAG_OBD_ENG();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_Edch_RE_OperationCycleUpdated);
    /* scheduled trigger for runnables: RE_OperationCycleUpdated */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_Edch_RE_OperationCycleUpdated);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_ASS_LIBE__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_SU_CLU_ASS_LIBE__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_ASS_LIBE = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_PARASS_DXP__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_SU_CLU_PARASS_DXP__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_PARASS_DXP = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_STMOM_SFE_DXP = 0;
    EnableAllInterrupts();

    Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxTuningSel);
    /* scheduled trigger for runnables: SrlComInput_TRGD_RxTuningSel */
    (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxTuningSel);
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_TROPT__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_SU_CLU_TROPT__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_TROPT = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_SU_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_VE_DYNMC_DXP = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_FN_EDP_DXP__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_SU_FN_EDP_DXP__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_FN_EDP_DXP = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_FN_LCS_DXP__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_SU_FN_LCS_DXP__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_FN_LCS_DXP = 0;
    EnableAllInterrupts();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_FN_LCS_UD_DXP__SU_CLE_DRDY_DXP(void)
{
  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_ComHook_Com_SU_FN_LCS_UD_DXP__SU_CLE_DRDY_DXP();

    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_FN_LCS_UD_DXP = 0;
    EnableAllInterrupts();
  }
}


/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_AVL_STEA_PNI_OFFS__STEA_OFFS(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_AVL_STEA_PNI_OFFS__STEA_OFFS(void)
#endif
{
  Rte_ComHookTOut_Com_AVL_STEA_PNI_OFFS__STEA_OFFS();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_AVL_STEA_PNI_OFFS = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_AvlSteaPniOffsLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_BE_CHOV_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_BE_CHOV_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_BE_CHOV_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_BE_CHOV_CLU_VE_DYNMC_DXP = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_ACDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_ACDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_ACDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_ACDU_IVIB_STW = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_DIM_DSE_EXMI__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_DIM_DSE_EXMI__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_DIM_DSE_EXMI__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_DIM_DSE_EXMI = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_PRG_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_PRG_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_PRG_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_PRG_IVIB_STW = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_PSDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_PSDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_PSDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_PSDU_IVIB_STW = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_VIB_STW = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_DIR_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_DIR_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_WARN_DIR_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_DIR_VIB_EPS = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_ILVL_VIB_EPS = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_CtrVibStwDispLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_ILVL_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_ILVL_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_WARN_ILVL_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_ILVL_VIB_STW = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_LGA_DSE_1_LH__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_LGA_DSE_1_LH__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_WARN_LGA_DSE_1_LH__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_LGA_DSE_1_LH = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_LGA_DSE_1_RH__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_LGA_DSE_1_RH__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_WARN_LGA_DSE_1_RH__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_LGA_DSE_1_RH = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void)
#endif
{
  Rte_ComHookTOut_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_PTRN_VIB_EPS = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_CtrVibStwDispLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ENERG_AVAI_ARS__ENERG_DGR_DRDY(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ENERG_AVAI_ARS__ENERG_DGR_DRDY(void)
#endif
{
  Rte_ComHookTOut_Com_ENERG_AVAI_ARS__ENERG_DGR_DRDY();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_ENERG_AVAI_ARS = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_FACT_MO_STE_SO_DXP__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_FACT_MO_STE_SO_DXP__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_FACT_MO_STE_SO_DXP__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_FACT_MO_STE_SO_DXP = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR(void)
#endif
{
  Rte_ComHookTOut_Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_ACLNY_MASSCNTR = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AclnyCogLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_AclnyCogLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AclnyCogLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_CON_VEH__CON_VEH(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_CON_VEH__CON_VEH(void)
#endif
{
  Rte_ComHookTOut_Com_Grp_SG_CON_VEH__CON_VEH();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_CON_VEH = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_ConVehLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_ConVehLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_ConVehLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER(void)
#endif
{
  Rte_ComHookTOut_Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_FAHRGESTELLNUMMER = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VINLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_VINLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VINLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS(void)
#endif
{
  Rte_ComHookTOut_Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_OFFS_QUAD_EPS = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_RxRevOffsetLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_ST_CENG__ST_CENG(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_ST_CENG__ST_CENG(void)
#endif
{
  Rte_ComHookTOut_Com_Grp_SG_ST_CENG__ST_CENG();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_ST_CENG = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_StCengLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_StCengLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_StCengLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV(void)
#endif
{
  Rte_ComHookTOut_Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_TAR_QTA_STRMOM_DV = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_PaDrvDynLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_VYAW_VEH__VYAW_VEH(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_VYAW_VEH__VYAW_VEH(void)
#endif
{
  Rte_ComHookTOut_Com_Grp_SG_VYAW_VEH__VYAW_VEH();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_VYAW_VEH = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VYawVehLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_VYawVehLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VYawVehLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_V_VEH__V_VEH(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_V_VEH__V_VEH(void)
#endif
{
  Rte_ComHookTOut_Com_Grp_SG_V_VEH__V_VEH();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_V_VEH = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VehSpdLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_VehSpdLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VehSpdLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_LD_SPEC_ARS__ENERG_DGR_DRDY(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_LD_SPEC_ARS__ENERG_DGR_DRDY(void)
#endif
{
  Rte_ComHookTOut_Com_MAX_I_LD_SPEC_ARS__ENERG_DGR_DRDY();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_LD_SPEC_ARS = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_RECUP_SPEC_ARS__ENERG_DGR_DRDY(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_RECUP_SPEC_ARS__ENERG_DGR_DRDY(void)
#endif
{
  Rte_ComHookTOut_Com_MAX_I_RECUP_SPEC_ARS__ENERG_DGR_DRDY();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_RECUP_SPEC_ARS = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_SPEC_BAX_STE__ENERG_DGR_DRDY(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_SPEC_BAX_STE__ENERG_DGR_DRDY(void)
#endif
{
  Rte_ComHookTOut_Com_MAX_I_SPEC_BAX_STE__ENERG_DGR_DRDY();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_SPEC_BAX_STE = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY(void)
#endif
{
  Rte_ComHookTOut_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MAX_I_SPEC_EPS = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_EnergDgrDrdyLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MILE_KM__KILOMETERSTAND(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MILE_KM__KILOMETERSTAND(void)
#endif
{
  Rte_ComHookTOut_Com_MILE_KM__KILOMETERSTAND();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_MILE_KM = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_MileKMLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_MileKMLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_MileKMLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_QU_DGR_AISP_ENERG__ENERG_DGR_DRDY(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_QU_DGR_AISP_ENERG__ENERG_DGR_DRDY(void)
#endif
{
  Rte_ComHookTOut_Com_QU_DGR_AISP_ENERG__ENERG_DGR_DRDY();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_QU_DGR_AISP_ENERG = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ST_ILK_ERRM_FZM__FZZSTD(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ST_ILK_ERRM_FZM__FZZSTD(void)
#endif
{
  Rte_ComHookTOut_Com_ST_ILK_ERRM_FZM__FZZSTD();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_ST_ILK_ERRM_FZM = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_FZZSTDLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_FZZSTDLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_FZZSTDLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_ASS_LIBE__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_ASS_LIBE__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_SU_CLU_ASS_LIBE__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_ASS_LIBE = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_PARASS_DXP__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_PARASS_DXP__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_SU_CLU_PARASS_DXP__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_PARASS_DXP = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_STMOM_SFE_DXP = 1;
    EnableAllInterrupts();

    if (Rte_InitState == RTE_STATE_INIT)
    {
      Rte_Task_SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_TuningSelLoss);
      /* scheduled trigger for runnables: SrlComInput_TRGD_TuningSelLoss */
      (void)SetEvent(Task_5ms_9, Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_TuningSelLoss);
    }
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_TROPT__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_TROPT__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_SU_CLU_TROPT__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_TROPT = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_SU_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_VE_DYNMC_DXP = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_EDP_DXP__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_EDP_DXP__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_SU_FN_EDP_DXP__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_FN_EDP_DXP = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_LCS_DXP__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_LCS_DXP__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_SU_FN_LCS_DXP__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_FN_LCS_DXP = 1;
    EnableAllInterrupts();
  }
}

#if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_LCS_UD_DXP__SU_CLE_DRDY_DXP(uint8 error)
#else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_LCS_UD_DXP__SU_CLE_DRDY_DXP(void)
#endif
{
  Rte_ComHookTOut_Com_SU_FN_LCS_UD_DXP__SU_CLE_DRDY_DXP();

#if RTE_COM_VERSION == 21U
  if (error == COM_TIMEOUT)
#endif
  {
    DisableAllInterrupts();
    Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SU_FN_LCS_UD_DXP = 1;
    EnableAllInterrupts();
  }
}


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     Task_100ms_10
 * Priority: 12
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_10)
{
  Rte_Task_Dispatch(Task_100ms_10);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_100msStart_Per_Start();
  ChkPtAp10_100msStart_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_100msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per2.Rte_CuTempEst_DegC_f32.value) = Rte_MtrTempEst_CuTempEst_DegC_f32;
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per2.Rte_MagTempEst_DegC_f32.value) = Rte_MtrTempEst_MagTempEst_DegC_f32;
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per2.Rte_SiTempEst_DegC_f32.value) = Rte_MtrTempEst_SiTempEst_DegC_f32;

  /* call runnable */
  Rte_Runnable_Ap_ParamComp_ParamComp_Per2_Start();
  ParamComp_Per2();
  Rte_Runnable_Ap_ParamComp_ParamComp_Per2_Return();

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start();
  DiagMgr10_Per();
  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start();
  uDiagStaticRegs_Per();
  Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return();

  /* read implicit inter-runnable variables */
  Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32_Task_100ms_10 = Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32;

  /* call runnable */
  Rte_Runnable_Ap_CurrentEst_CurrentEst_Per2_Start();
  CurrentEst_Per2();
  Rte_Runnable_Ap_CurrentEst_CurrentEst_Per2_Return();

  /* write implicit data */
  Rte_CurrentEst_FiltEstPkCurr_AmpSq_f32 = *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per2.Rte_FiltEstPkCurr_AmpSq_f32.value);

  /* call runnable */
  Rte_Runnable_NtWrap_NtWrap_Per1_Start();
  NtWrap_Per1();
  Rte_Runnable_NtWrap_NtWrap_Per1_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_100msEnd_Per_Start();
  ChkPtAp10_100msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_100msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_100ms_11
 * Priority: 11
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_11)
{
  Rte_Task_Dispatch(Task_100ms_11);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp11_ChkPtAp11_100msStart_Per_Start();
  ChkPtAp11_100msStart_Per();
  Rte_Runnable_Ap_ChkPtAp11_ChkPtAp11_100msStart_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr11_DiagMgr11_Per_Start();
  DiagMgr11_Per();
  Rte_Runnable_Ap_DiagMgr11_DiagMgr11_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp11_ChkPtAp11_100msEnd_Per_Start();
  ChkPtAp11_100msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp11_ChkPtAp11_100msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_100ms_7
 * Priority: 15
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_7)
{
  Rte_Task_Dispatch(Task_100ms_7);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_100msStart_Per_Start();
  ChkPtAp7_100msStart_Per();
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_100msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per3.Rte_MECCounter_Cnt_enum.value) = Rte_CDDInterface9_NxtrMEC_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start();
  HwTrq_Per3();
  Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return();

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr7_DiagMgr7_Per_Start();
  DiagMgr7_Per();
  Rte_Runnable_Ap_DiagMgr7_DiagMgr7_Per_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Sa_CtrlTemp_CtrlTemp_Per2.Rte_AmbTemp_DegC_f32.value) = Rte_CtrlTemp_AmbTemp_DegC_f32;

  /* call runnable */
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start();
  CtrlTemp_Per2();
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_AmbTemp_DegC_f32.value) = Rte_MtrTempEst_AmbTemp_DegC_f32;
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_CtrlTempFinal_DegC_f32.value) = Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_EngTemp_DegC_f32.value) = Rte_MtrTempEst_EngTemp_DegC_f32;
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_EstPkCurr_AmpSq_f32.value) = Rte_CurrentEst_EstPkCurr_AmpSq_f32;
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_HwVel_HwRadpS_f32.value) = Rte_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_ScomAMDefeat_Cnt_lgc.value) = Rte_MtrTempEst_ScomAMDefeat_Cnt_lgc;
  *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_ScomTempDataRcvd_Cnt_lgc.value) = Rte_MtrTempEst_ScomTempDataRcvd_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start();
  MtrTempEst_Per1();
  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return();

  /* write implicit data */
  Rte_MtrTempEst_AssistMechTempEst_DegC_f32 = *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_AssistMechTempEst_DegC_f32.value);
  Rte_MtrTempEst_CuTempEst_DegC_f32 = *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_CuTempEst_DegC_f32.value);
  Rte_MtrTempEst_MagTempEst_DegC_f32 = *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_MagTempEst_DegC_f32.value);
  Rte_MtrTempEst_SiTempEst_DegC_f32 = *(&Rte_Task_100ms_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_SiTempEst_DegC_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_100msEnd_Per_Start();
  ChkPtAp7_100msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_100msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_100ms_8
 * Priority: 14
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_8)
{
  Rte_Task_Dispatch(Task_100ms_8);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_100msStart_Per_Start();
  ChkPtAp8_100msStart_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_100msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per3.Rte_AnaDiffHwTrq_Volt_f32.value) = Rte_HwTrq_AnaDiffHwTrq_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start();
  HwTrq2_Per3();
  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return();

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start();
  DiagMgr8_Per();
  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_100msEnd_Per_Start();
  ChkPtAp8_100msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_100msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_100ms_9
 * Priority: 13
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_9)
{
  Rte_Task_Dispatch(Task_100ms_9);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_100msStart_Per_Start();
  ChkPtAp9_100msStart_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_100msStart_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start();
  DiagMgr9_Per();
  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return();

  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_DiagMgr9_DiagMgr_Per2 == 0)
  {
    /* call runnable */
    Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start();
    DiagMgr_Per2();
    Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return();
  }

  /* call runnable */
  Rte_Runnable_Coding_Runnable_MainFunction_Start();
  Coding_MainFunction();
  Rte_Runnable_Coding_Runnable_MainFunction_Return();

  /* call runnable */
  Rte_Runnable_Edch_RE_Main_Start();
  Edch_Main();
  Rte_Runnable_Edch_RE_Main_Return();

  /* call runnable */
  Rte_Runnable_Edch_RE_CalculateSubCvn_Start();
  Edch_CalculateSubCvn();
  Rte_Runnable_Edch_RE_CalculateSubCvn_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_CuTempEst_DegC_f32.value) = Rte_MtrTempEst_CuTempEst_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_DefeatDutySvc_Cnt_lgc.value) = Rte_CDDInterface9_ThermalDCSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_FiltMeasTemp_DegC_f32.value) = Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_FilteredPkCurr_AmpSq_f32.value) = Rte_CurrentEst_FiltEstPkCurr_AmpSq_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_IgnTimeOff_Cnt_u32.value) = Rte_SrlComInput_IgnTimeOff_Cnt_u32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_MagTempEst_DegC_f32.value) = Rte_MtrTempEst_MagTempEst_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_MotorVelCRF_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_MtrPkCurr_AmpSq_f32.value) = Rte_CurrentEst_EstPkCurr_AmpSq_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_SiTempEst_DegC_f32.value) = Rte_MtrTempEst_SiTempEst_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_VehTimeValid_Cnt_lgc.value) = Rte_SrlComInput_VehTimeValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start();
  ThrmlDutyCycle_Per1();
  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return();

  /* write implicit data */
  Rte_ThrmlDutyCycle_DutyCycleLevel_Uls_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_DutyCycleLevel_Uls_f32.value);
  Rte_ThrmlDutyCycle_ThermLimitPerc_Uls_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_ThermLimitPerc_Uls_f32.value);
  Rte_ThrmlDutyCycle_ThermalLimit_MtrNm_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_ThermalLimit_MtrNm_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_ActivePull_ActivePull_Per3 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpEna_Cnt_lgc.value) = Rte_VehCfg_CPLCOMPIF_Cnt_lgc;
    *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32.value) = Rte_ActivePull_PullCmpLongTermIntgtrStOffs_HwNm_f32;
    *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start();
    ActivePull_Per3();
    Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return();

    /* write implicit data */
    Rte_ActivePull_PullCmpLongTermIntgtrSt_HwNm_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpLongTermIntgtrSt_HwNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_100msEnd_Per_Start();
  ChkPtAp9_100msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_100msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_10msA_10
 * Priority: 34
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_10msA_10)
{
  Rte_Task_Dispatch(Task_10msA_10);

  /* read implicit data */
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_AVLFORCGRDTxConf_Cnt_lgc.value) = Rte_SrlComOutput_AVLFORCGRDTxConf_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_AVLSTMOMTxConf_Cnt_lgc.value) = Rte_SrlComOutput_AVLSTMOMTxConf_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CADASMSG_Cnt_lgc.value) = Rte_VehCfg_CADASIF_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CDISPCCEPS_Cnt_u08.value) = Rte_VehCfg_CDISPCCDRDY02_Cnt_u08;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CEVIIF_Cnt_lgc.value) = Rte_VehCfg_CEVIIF_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CFACTORIF_Cnt_lgc.value) = Rte_VehCfg_CFACTORIF_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CHWANGLEIF_Cnt_lgc.value) = Rte_VehCfg_CHWANGLEIF_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CHWTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CHWTORQUEIF_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_CMTTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CMTTORQUEIF_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_DiagStsRecRmpToZeroFltPres_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_LimitPercentFiltered_Uls_f32.value) = Rte_AssistSumnLmt_LimitPercentFiltered_Uls_f32;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_RacktoVehCntrOffset_Cnt_u16.value) = Rte_AbsHwPos_RacktoVehCntrOffset_Cnt_u16;
  *(&Rte_Task_10msA_10.Rte_RB.Rte_Ap_SrlComOutput2_SrlComOutput2_Per1.Rte_RevOffsetState_Cnt_u08.value) = Rte_AbsHwPos_RevOffsetState_Cnt_u08;

  /* call runnable */
  Rte_Runnable_Ap_SrlComOutput2_SrlComOutput2_Per1_Start();
  SrlComOutput2_Per1();
  Rte_Runnable_Ap_SrlComOutput2_SrlComOutput2_Per1_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_10msA_9
 * Priority: 35
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_10msA_9)
{
  Rte_Task_Dispatch(Task_10msA_9);

  /* call runnable */
  Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start();
  SrlComOutput_Per1();
  Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return();

  /* write implicit data */
  Rte_SrlComOutput_AVLFORCGRDTxConf_Cnt_lgc = *(&Rte_Task_10msA_9.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AVLFORCGRDTxConf_Cnt_lgc.value);
  Rte_SrlComOutput_AVLSTMOMTxConf_Cnt_lgc = *(&Rte_Task_10msA_9.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AVLSTMOMTxConf_Cnt_lgc.value);

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_10msB_10
 * Priority: 30
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_10msB_10)
{
  Rte_Task_Dispatch(Task_10msB_10);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_10msStartB_Per_Start();
  ChkPtAp10_10msStartB_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_10msStartB_Per_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start();
  uDiagECC_Per();
  Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start();
  uDiagVIM_Per();
  Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return();

  /* read implicit data */
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_DefeatKinIntTest_Cnt_lgc.value) = Rte_CDDInterface9_KinIntDiagSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_DiagStsDefVehSpd_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc;
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per2_Start();
  AbsHwPos_Per2();
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per2_Return();

  /* read implicit data */
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_DiagStsHwPosDis_Cnt_lgc.value) = Rte_LrnEOT_DiagStsHwPosDis_Cnt_lgc;
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_SrlComHwPos_HwDeg_f32;
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_MtrVelCRF_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_PostLimitTorque_MtrNm_f32.value) = Rte_Sweep2_OutputMtrTrq_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start();
  LrnEOT_Per1();
  Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return();

  /* write implicit data */
  Rte_LrnEOT_CCWFound_Cnt_lgc = *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_CCWFound_Cnt_lgc.value);
  Rte_LrnEOT_CCWPosition_HwDeg_f32 = *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_CCWPosition_HwDeg_f32.value);
  Rte_LrnEOT_CWFound_Cnt_lgc = *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_CWFound_Cnt_lgc.value);
  Rte_LrnEOT_CWPosition_HwDeg_f32 = *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_CWPosition_HwDeg_f32.value);

  /* read implicit data */
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDChrgPmpFdbkADC_Volt_f32.value) = Rte_IoHwAb7_PDChrgPmpFdbkADC_Volt_f32;
  *(&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDSuplFdbkADC_Volt_f32.value) = Rte_IoHwAb7_PDSuplFdbkADC_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_PhaseDscnt_PhaseDscnt_Per2_Start();
  PhaseDscnt_Per2();
  Rte_Runnable_Sa_PhaseDscnt_PhaseDscnt_Per2_Return();

  /* write implicit data */
  Rte_PhaseDscnt_PDActivateTest_Cnt_lgc = *(&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDActivateTest_Cnt_lgc.value);
  Rte_PhaseDscnt_PDPhaseAdvSelect_Cnt_s16 = *(&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDPhaseAdvSelect_Cnt_s16.value);
  Rte_PhaseDscnt_PDTestModIndex_Uls_f32 = *(&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDTestModIndex_Uls_f32.value);
  Rte_PhaseDscnt_PhsDiscTestComplete_Cnt_lgc = *(&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PhsDiscTestComplete_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start();
  ShtdnMech_Per1();
  Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return();

  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10msB_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per2 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2.Rte_PowerLimitPerc_Uls_f32.value) = Rte_PwrLmtFunc_PowerLimitPerc_Uls_f32;
    *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2.Rte_ThermLimitPerc_Uls_f32.value) = Rte_ThrmlDutyCycle_ThermLimitPerc_Uls_f32;

    /* call runnable */
    Rte_Runnable_Ap_AssistSumnLmt_AssistSumnLmt_Per2_Start();
    AssistSumnLmt_Per2();
    Rte_Runnable_Ap_AssistSumnLmt_AssistSumnLmt_Per2_Return();

    /* write implicit data */
    Rte_AssistSumnLmt_LimitPercentFiltered_Uls_f32 = *(&Rte_Task_10msB_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2.Rte_LimitPercentFiltered_Uls_f32.value);
  }

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_10msEndB_Per_Start();
  ChkPtAp10_10msEndB_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_10msEndB_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_10msB_9
 * Priority: 31
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_10msB_9)
{
  Rte_Task_Dispatch(Task_10msB_9);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_10msStartB_Per_Start();
  ChkPtAp9_10msStartB_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_10msStartB_Per_Return();

  /* read implicit data */
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_EstR_Ohm_f32.value) = Rte_ParamComp_EstR_Ohm_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_ModIdx_Uls_f32.value) = Rte_VltgCtrl_ModIdx_Uls_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_TermA_Volt_f32.value) = Rte_VltgCtrl_TermA_Volt_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_TermXq_Uls_f32.value) = Rte_VltgCtrl_TermXq_Uls_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_TermZ_Uls_f32.value) = Rte_VltgCtrl_TermZ_Uls_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_UncorrPhsAdv_Cnt_s16.value) = Rte_VltgCtrl_UnCorrPhsAdv_Cnt_s16;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_Vecu_Volt_f32.value) = Rte_BatteryVoltage_Vecu_Volt_f32;

  /* call runnable */
  Rte_Runnable_Ap_ElecPwr_ElecPwr_Per1_Start();
  ElecPwr_Per1();
  Rte_Runnable_Ap_ElecPwr_ElecPwr_Per1_Return();

  /* write implicit data */
  Rte_ElecPwr_ElecPower_Watts_f32 = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_ElecPower_Watts_f32.value);
  Rte_ElecPwr_SupplyCur_Amp_f32 = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ElecPwr_ElecPwr_Per1.Rte_SupplyCur_Amp_f32.value);

  /* read implicit data */
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_RackLoad_RackLoad_Per1.Rte_CRFMtrTrqCmd_MtrNm_f32.value) = Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_RackLoad_RackLoad_Per1.Rte_CRFMtrVel_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_RackLoad_RackLoad_Per1.Rte_HwPos_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_RackLoad_RackLoad_Per1.Rte_HwPosAuth_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_RackLoad_RackLoad_Per1.Rte_HwTrq_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_RackLoad_RackLoad_Per1_Start();
  RackLoad_Per1();
  Rte_Runnable_Ap_RackLoad_RackLoad_Per1_Return();

  /* write implicit data */
  Rte_RackLoad_RackLoad_kN_f32 = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_RackLoad_RackLoad_Per1.Rte_RackLoad_kN_f32.value);

  /* read implicit data */
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_NxtrMEC_Cnt_enum.value) = Rte_CDDInterface9_NxtrMEC_Cnt_enum;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_PrkAssistState_Cnt_u08.value) = Rte_ParkAssistEnable_PrkAssistState_Cnt_u08;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP.value) = Rte_SrlComInput_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_VINValid_Cnt_lgc.value) = Rte_SrlComInput_VINValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_VehCfg_VehCfg_Per1_Start();
  VehCfg_Per1();
  Rte_Runnable_Ap_VehCfg_VehCfg_Per1_Return();

  /* write implicit data */
  Rte_VehCfg_DesiredTunPers_Cnt_u16 = *(&Rte_Task_10msB_9.Rte_TB.Rte_I_VehCfg_DesiredTunPers_Cnt_u16.value);
  Rte_VehCfg_DesiredTunSet_Cnt_u16 = *(&Rte_Task_10msB_9.Rte_TB.Rte_I_VehCfg_DesiredTunSet_Cnt_u16.value);
  Rte_VehCfg_EnergyModeState_Cnt_enum = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_EnergyModeState_Cnt_enum.value);

  /* call runnable */
  Rte_Runnable_Ap_SrlScomSrvc_SrlComSrvc_Per1_Start();
  SrlComSrvc_Per1();
  Rte_Runnable_Ap_SrlScomSrvc_SrlComSrvc_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunPers_Cnt_u16.value) = Rte_TuningSelAuth_ActiveTunPers_Cnt_u16;
  *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunSet_Cnt_u16.value) = Rte_TuningSelAuth_ActiveTunSet_Cnt_u16;

  /* call runnable */
  Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start();
  ApXcp_Per1();
  Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return();

  /* write implicit data */
  Rte_ApXcp_ActiveTunOvrPtrAddr_Cnt_u32 = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunOvrPtrAddr_Cnt_u32.value);
  Rte_ApXcp_TuningSessionActPtr_Cnt_u8 = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_TuningSessionActPtr_Cnt_u8.value);

  DisableAllInterrupts();
  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10msB_9_Rte_Trigger1_AvgFricLrn_AvgFricLrn_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_CRFMtrTrq_MtrNm_f32.value) = Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_DefeatFricLearning_Cnt_lgc.value) = Rte_CDDInterface9_AvgFrcLrnSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_FricLrnCustEna_Cnt_lgc.value) = Rte_VehCfg_CFRCOMPIF_Cnt_lgc;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_HwAng_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_HwPosAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_HwTrq_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_HwVel_HwRadpS_f32.value) = Rte_MtrVel_HandwheelVel_HwRadpS_f32;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_LatAcc_MpSecSq_f32.value) = Rte_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_Temperature_DegC_f32.value) = Rte_MtrTempEst_AssistMechTempEst_DegC_f32;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_VehSpd_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_SignlCondn_VehicleSpeedValid_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start();
    AvgFricLrn_Per1();
    Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return();

    /* write implicit data */
    Rte_AvgFricLrn_EstFric_HwNm_f32 = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_EstFric_HwNm_f32.value);
    Rte_AvgFricLrn_FricOffset_HwNm_f32 = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_FricOffset_HwNm_f32.value);
    Rte_AvgFricLrn_SatEstFric_HwNm_f32 = *(&Rte_Task_10msB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_SatEstFric_HwNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_10msEndB_Per_Start();
  ChkPtAp9_10msEndB_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_10msEndB_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_10ms_7
 * Priority: 33
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_10ms_7)
{
  Rte_Task_Dispatch(Task_10ms_7);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_10msStart_Per_Start();
  ChkPtAp7_10msStart_Per();
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_10msStart_Per_Return();

  DisableAllInterrupts();
  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per3 == 0)
  {
    EnableAllInterrupts();
    /* call runnable */
    Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start();
    TmprlMon_Per3();
    Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return();
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_BVDiag_BVDiag_Per1.Rte_Batt_Volt_f32.value) = Rte_IoHwAb7_Batt_Volt_f32;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_BVDiag_BVDiag_Per1.Rte_CCLMSAActive_Cnt_lgc.value) = Rte_CustPL_CCLMSAActive_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start();
  BVDiag_Per1();
  Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_ActiveTunOvrPtrAddr_Cnt_u32.value) = Rte_ApXcp_ActiveTunOvrPtrAddr_Cnt_u32;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_DesiredTunPers_Cnt_u16.value) = Rte_VehCfg_DesiredTunPers_Cnt_u16;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_DesiredTunSet_Cnt_u16.value) = Rte_VehCfg_DesiredTunSet_Cnt_u16;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_TuningSessionActPtr_Cnt_u8.value) = Rte_ApXcp_TuningSessionActPtr_Cnt_u8;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start();
  TuningSelAuth_Per1();
  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return();

  /* write implicit data */
  Rte_TuningSelAuth_ActiveTunPers_Cnt_u16 = *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_ActiveTunPers_Cnt_u16.value);
  Rte_TuningSelAuth_ActiveTunSet_Cnt_u16 = *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_ActiveTunSet_Cnt_u16.value);

  /* read implicit data */
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_AlignedCumMtrPosMRF_Deg_f32.value) = Rte_MtrPos_AlignedCumMtrPosMRF_Deg_f32;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_EnergyModeState_Cnt_enum.value) = Rte_VehCfg_EnergyModeState_Cnt_enum;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_HwTargetAuthority_Uls_f32.value) = Rte_AbsHwPos_HwTargetAuthority_Uls_f32;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_ICMMtrPosMRF_Deg_f32.value) = Rte_AbsHwPos_ICMMtrPosMRF_Deg_f32;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_LTRackCntrComplete_Cnt_lgc.value) = Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_LTVehCenterComplete_Cnt_lgc.value) = Rte_AbsHwPos_LTVehCenterComplete_Cnt_lgc;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_MotorVelMRF_MtrRadpS_f32.value) = Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_RackCenterComplete_Cnt_lgc.value) = Rte_LnRkCr_RackCntrComplete_Cnt_lgc;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TCFlash_Cnt_lgc.value) = Rte_CDDInterface9_TcReflashActive_Cnt_lgc;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcFlashErrors_Cnt_u08.value) = Rte_CDDInterface9_TcFlashErrors_Cnt_u08;
  *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcFlashVerify_Cnt_lgc.value) = Rte_CDDInterface9_TcFlashVerify_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Cd_TurnsCounter_TurnsCounter_Per1_Start();
  TurnsCounter_Per1();
  Rte_Runnable_Cd_TurnsCounter_TurnsCounter_Per1_Return();

  /* write implicit data */
  Rte_TurnsCounter_TCMtrPosOffsMRF_Deg_f32 = *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TCMtrPosOffsMRF_Deg_f32.value);
  Rte_TurnsCounter_TcActivePN_Cnt_u32 = *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcActivePN_Cnt_u32.value);
  Rte_TurnsCounter_TcActivePNVldCnt_Cnt_u32 = *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcActivePNVldCnt_Cnt_u32.value);
  Rte_TurnsCounter_TurnsCntrValidity_Cnt_enum = *(&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TurnsCntrValidity_Cnt_enum.value);

  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_CustPL_CustPL_Per1 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CASSISTMSA_Cnt_lgc.value) = Rte_VehCfg_CASSISTMSA_Cnt_lgc;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CBATCURLIMITCUR_Amp_f32.value) = Rte_VehCfg_CBATCURLIMITCURRENT_Amp_f32;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CVEHSPDCURLIMITCURRENT_Amp_f32.value) = Rte_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CVEHSPDCURLIMITER_Cnt_lgc.value) = Rte_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CVEHSPDCURLIMITSPEED_Kph_f32.value) = Rte_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_MSACommand_MSACmd_enum.value) = Rte_VehPwrMd_MSACommand_MSACmd_enum;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_SupplyCurrLmt_Amp_f32.value) = Rte_SrlComInput_SupplyCurrLmt_Amp_f32;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_CustPL_CustPL_Per1_Start();
    CustPL_Per1();
    Rte_Runnable_Ap_CustPL_CustPL_Per1_Return();

    /* write implicit data */
    Rte_CustPL_CCLMSAActive_Cnt_lgc = *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CCLMSAActive_Cnt_lgc.value);
    Rte_CustPL_CCLTrqRamp_Uls_f32 = *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CCLTrqRamp_Uls_f32.value);
    Rte_CustPL_CustCurrLmt_Amp_f32 = *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CustCurrLmt_Amp_f32.value);
  }

  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_10ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per2 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per2.Rte_CCLMSAActive_Cnt_lgc.value) = Rte_CustPL_CCLMSAActive_Cnt_lgc;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per2.Rte_PreLimitForPwr_MtrNm_f32.value) = Rte_AssistSumnLmt_PreLimitForPower_MtrNm_f32;
    *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per2.Rte_Vecu_Volt_f32.value) = Rte_BatteryVoltage_Vecu_Volt_f32;

    /* call runnable */
    Rte_Runnable_Ap_PwrLmtFunc_PwrLmtFunc_Per2_Start();
    PwrLmtFunc_Per2();
    Rte_Runnable_Ap_PwrLmtFunc_PwrLmtFunc_Per2_Return();

    /* write implicit data */
    Rte_PwrLmtFunc_PowerLimitPerc_Uls_f32 = *(&Rte_Task_10ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per2.Rte_PowerLimitPerc_Uls_f32.value);
  }

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_10msEnd_Per_Start();
  ChkPtAp7_10msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_10msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_1ms_10
 * Priority: 71
 * Schedule: FULL
 * Alarm:    Cycle Time 0.001 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_1ms_10)
{
  Rte_Task_Dispatch(Task_1ms_10);

  /* read implicit data */
  *(&Rte_Task_1ms_10.Rte_TB.Rte_I_Polarity_AssistAssyPolarity_Cnt_s08.value) = Rte_Polarity_AssistAssyPolarity_Cnt_s08;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start();
  MtrVel_Per1();
  Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return();

  /* write implicit data */
  Rte_MtrVel_CRFMotorVel_MtrRadpS_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_CRFMotorVel_MtrRadpS_f32.value);
  Rte_MtrVel_HandwheelVel_HwRadpS_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_HandwheelVel_HwRadpS_f32.value);
  Rte_MtrVel_HwVelValid_Cnt_lgc = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_HwVelValid_Cnt_lgc.value);
  Rte_MtrVel_MRFMotorVel_MtrRadpS_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value);
  Rte_MtrVel_MRFMotorVelUnfiltered_MtrRadpS_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_MRFMotorVelUnfiltered_MtrRadpS_f32.value);
  Rte_MtrVel_SysCHandwheelVel_HwRadpS_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_SysCHandwheelVel_HwRadpS_f32.value);
  Rte_MtrVel_SysCMotorVelMRF_MtrRadpS_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_SysCMotorVelMRF_MtrRadpS_f32.value);

  /* call runnable */
  Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start();
  MtrPos_Per2();
  Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return();

  /* write implicit data */
  Rte_MtrPos_AlignedCumMtrPosMRF_Deg_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_AlignedCumMtrPosMRF_Deg_f32.value);
  Rte_MtrPos_CumMtrPosCRF_Deg_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_CumMtrPosCRF_Deg_f32.value);
  Rte_MtrPos_CumMtrPosMRF_Deg_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrPos_CumMtrPosMRF_Deg_f32.value);
  Rte_MtrPos_SysCCumMtrPosCRF_Deg_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_SysCCumMtrPosCRF_Deg_f32.value);
  Rte_MtrPos_SysCCumMtrPosMRF_Deg_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrPos_MtrPos_Per2.Rte_SysCCumMtrPosMRF_Deg_f32.value);

  /* read implicit data */
  *(&Rte_Task_1ms_10.Rte_TB.Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32.value) = Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start();
  QuadDet_Per1();
  Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return();

  /* write implicit data */
  Rte_QuadDet_InstMtrDir_Cnt_s08 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_QuadDet_QuadDet_Per1.Rte_InstMtrDir_Cnt_s08.value);
  Rte_QuadDet_MtrQuad_Cnt_u08 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_QuadDet_MtrQuad_Cnt_u08.value);

  /* read implicit data */
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_CuTempEst_DegC_f32.value) = Rte_MtrTempEst_CuTempEst_DegC_f32;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_EstKe_VpRadpS_f32.value) = Rte_ParamComp_EstKe_VpRadpS_f32;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_EstLd_Henry_f32.value) = Rte_ParamComp_EstLd_Henry_f32;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_EstLq_Henry_f32.value) = Rte_ParamComp_EstLq_Henry_f32;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_EstR_Ohm_f32.value) = Rte_ParamComp_EstR_Ohm_f32;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_MtrEnvSpd_MtrRadpS_f32.value) = Rte_PwrLmtFunc_MtrEnvSpd_MtrRadpS_f32;
  *(&Rte_Task_1ms_10.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value) = Rte_BatteryVoltage_Vecu_Volt_f32;

  /* call runnable */
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Per2_Start();
  VltgCtrl_Per2();
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Per2_Return();

  /* write implicit data */
  Rte_VltgCtrl_TermA_Volt_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermA_Volt_f32.value);
  Rte_VltgCtrl_TermBTOT_Volt_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermBTOT_Volt_f32.value);
  Rte_VltgCtrl_TermXd_Uls_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermXd_Uls_f32.value);
  Rte_VltgCtrl_TermXq_Uls_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermXq_Uls_f32.value);
  Rte_VltgCtrl_TermY_Uls_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermY_Uls_f32.value);
  Rte_VltgCtrl_TermZ_Uls_f32 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_TermZ_Uls_f32.value);
  Rte_VltgCtrl_VdTerm_Volt_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_VdTerm_Volt_f32.value);
  Rte_VltgCtrl_VqTerm_Volt_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_VqTerm_Volt_f32.value);

  /* read implicit data */
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_PhaseCtrl_PhaseCtrl_Per1.Rte_TermBSS_Volt_f32.value) = Rte_VltgCtrl_TermBSS_Volt_f32;

  /* call runnable */
  Rte_Runnable_Ap_PhaseCtrl_PhaseCtrl_Per1_Start();
  PhaseCtrl_Per1();
  Rte_Runnable_Ap_PhaseCtrl_PhaseCtrl_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_PDActivateTest_Cnt_lgc.value) = Rte_PhaseDscnt_PDActivateTest_Cnt_lgc;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_PDPhsAdvSel_Cnt_s16.value) = Rte_PhaseDscnt_PDPhaseAdvSelect_Cnt_s16;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_PDTestModIdx_Uls_f32.value) = Rte_PhaseDscnt_PDTestModIndex_Uls_f32;

  /* call runnable */
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Per4_Start();
  VltgCtrl_Per4();
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Per4_Return();

  /* write implicit data */
  Rte_VltgCtrl_ModIdx_Uls_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_ModIdx_Uls_f32.value);
  Rte_VltgCtrl_PhsAdv_Cnt_s16 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_PhsAdv_Cnt_s16.value);
  Rte_VltgCtrl_UnCorrPhsAdv_Cnt_s16 = *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_UnCorrPhsAdv_Cnt_s16.value);

  /* read implicit data */
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1.Rte_CurrentGainSvc_Cnt_b32.value) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;
  *(&Rte_Task_1ms_10.Rte_RB.Rte_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1.Rte_TorqueCmdMRF_MtrNm_f32.value) = Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1_Start();
  MtrCtrlOpConv_Per1();
  Rte_Runnable_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1_Return();

  /* write implicit data */
  Rte_MtrCtrlOpConv_CommutationOffset_Cnt_u16 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_CommutationOffset_Cnt_u16.value);
  Rte_MtrCtrlOpConv_DeadTimeComp_Uls_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_DeadTimeComp_Uls_f32.value);
  Rte_MtrCtrlOpConv_ModulationIndexFinal_Uls_f32 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_ModulationIndexFinal_Uls_f32.value);
  Rte_MtrCtrlOpConv_MtrTrqCmdSign_Cnt_s16 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_MtrTrqCmdSign_Cnt_s16.value);
  Rte_MtrCtrlOpConv_PhaseAdvanceFinal_Cnt_u16 = *(&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrCtrlOpConv_PhaseAdvanceFinal_Cnt_u16.value);

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface10_CDDInterface10_Per2_Start();
  CDDInterface10_Per2();
  Rte_Runnable_Sa_CDDInterface10_CDDInterface10_Per2_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start();
  uDiagLossOfExec_Per2();
  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_1ms_9
 * Priority: 70
 * Schedule: FULL
 * Alarm:    Cycle Time 0.001 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_1ms_9)
{
  Rte_Task_Dispatch(Task_1ms_9);

  /* call runnable */
  Rte_Runnable_Ap_ApXcp_DAQ_1msTL_Start();
  DAQ_1msTL();
  Rte_Runnable_Ap_ApXcp_DAQ_1msTL_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2msA_9
 * Priority: 67
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2msA_9)
{
  Rte_Task_Dispatch(Task_2msA_9);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msStartA_Per_Start();
  ChkPtAp9_2msStartA_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msStartA_Per_Return();

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HiLoadStall_HiLoadStall_Per1.Rte_DftStallLimit_Cnt_lgc.value) = Rte_CDDInterface9_EOTThermalSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_MtrVel_CRFMotorVel_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HiLoadStall_HiLoadStall_Per1.Rte_PreLimitForStall_MtrNm_f32.value) = Rte_AssistSumnLmt_PreLimitForStall_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start();
  HiLoadStall_Per1();
  Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return();

  /* write implicit data */
  Rte_HiLoadStall_AssistStallLimit_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HiLoadStall_HiLoadStall_Per1.Rte_AssistStallLimit_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehSpdLmt_VehSpdLmt_Per1.Rte_CCWPosition_HwDeg_f32.value) = Rte_LrnEOT_CCWPosition_HwDeg_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehSpdLmt_VehSpdLmt_Per1.Rte_CWPosition_HwDeg_f32.value) = Rte_LrnEOT_CWPosition_HwDeg_f32;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start();
  VehSpdLmt_Per1();
  Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return();

  /* write implicit data */
  Rte_VehSpdLmt_AstVehSpdLimit_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehSpdLmt_VehSpdLmt_Per1.Rte_AstVehSpdLimit_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_MtrTempEst_AssistMechTempEst_DegC_f32.value) = Rte_MtrTempEst_AssistMechTempEst_DegC_f32;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_MtrVel_HandwheelVel_HwRadpS_f32.value) = Rte_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_Sweep_OutputHwTrq_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_PosServo_PosSrvoReturnSclFct_Uls_f32.value) = Rte_PosServo_PosSrvoReturnSclFct_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_DrvDynCtrl_ReturnDDFactor_Uls_f32.value) = Rte_DrvDynCtrl_ReturnDDFactor_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_SrlComInput_ReturnOffset_HwDeg_f32.value) = Rte_SrlComInput_ReturnOffset_HwDeg_f32;

  /* call runnable */
  Rte_Runnable_Ap_Return_Return_Per1_Start();
  Return_Per1();
  Rte_Runnable_Ap_Return_Return_Per1_Return();

  /* write implicit data */
  Rte_Return_ReturnCmd_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_TB.Rte_I_Return_ReturnCmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_DefeatReturnSvc_Cnt_lgc.value) = Rte_CDDInterface9_ReturnSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_EnableCVR_Cnt_lgc.value) = Rte_VehCfg_CSELRETURN_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_MRFMtrTrqCmdScl_MtrNm_f32.value) = Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_BmwRtnArbn_BmwRtnArbn_Per1_Start();
  BmwRtnArbn_Per1();
  Rte_Runnable_Ap_BmwRtnArbn_BmwRtnArbn_Per1_Return();

  /* write implicit data */
  Rte_BmwRtnArbn_ReturnCmd_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_ReturnCmd_MtrNm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_TrqBasedInrtCmp_TrqBasedInrtCmp_Per1_Start();
  TrqBasedInrtCmp_Per1();
  Rte_Runnable_Ap_TrqBasedInrtCmp_TrqBasedInrtCmp_Per1_Return();

  /* write implicit data */
  Rte_TrqBasedInrtCmp_HighFreqAssist_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_TrqBasedInrtCmp_TrqBasedInrtCmp_Per1.Rte_HighFreqAssist_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HystAdd_HystAdd_Per1.Rte_HysAddSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface9_HysAddSrlComSvcDft_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_HystAdd_HystAdd_Per1_Start();
  HystAdd_Per1();
  Rte_Runnable_Ap_HystAdd_HystAdd_Per1_Return();

  /* write implicit data */
  Rte_HystAdd_HysAddHwTrq_HwNm_f32 = *(&Rte_Task_2msA_9.Rte_TB.Rte_I_HystAdd_HysAddHwTrq_HwNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_TB.Rte_I_DrvDynCtrl_AssistDDFactor_Uls_f32.value) = Rte_DrvDynCtrl_AssistDDFactor_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_DftAsstTbl_Cnt_lgc.value) = Rte_CDDInterface9_DftAsstTbl_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_DutyCycleLevel_Uls_f32.value) = Rte_ThrmlDutyCycle_DutyCycleLevel_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_DwnldAsstGain_Uls_f32.value) = Rte_CDDInterface9_DwnldAsstGain_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_IpTrqOvr_HwNm_f32.value) = Rte_Assist_IpTrqOvr_HwNm_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value) = Rte_Assist_WIRCmdAmpBlnd_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_Assist_Assist_Per1_Start();
  Assist_Per1();
  Rte_Runnable_Ap_Assist_Assist_Per1_Return();

  /* write implicit data */
  Rte_Assist_BaseAssistCmd_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_TB.Rte_I_Assist_BaseAssistCmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HystComp_HystComp_Per1.Rte_DefeatHystService_Cnt_lgc.value) = Rte_CDDInterface9_HystCompSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HystComp_HystComp_Per1.Rte_FricOffset_HwNm_f32.value) = Rte_AvgFricLrn_FricOffset_HwNm_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HystComp_HystComp_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value) = Rte_HystComp_WIRCmdAmpBlnd_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_HystComp_HystComp_Per1_Start();
  HystComp_Per1();
  Rte_Runnable_Ap_HystComp_HystComp_Per1_Return();

  /* write implicit data */
  Rte_HystComp_HysteresisComp_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HystComp_HystComp_Per1.Rte_HysteresisComp_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_TJADamp_TJADamp_Per1.Rte_TJADampSclRqst_Uls_f32.value) = Rte_SrlComInput2_TJADampSclRqst_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_TJADamp_TJADamp_Per1.Rte_TJAStateRqst_Cnt_enum.value) = Rte_SrlComInput2_TJAStateRqst_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Ap_TJADamp_TJADamp_Per1_Start();
  TJADamp_Per1();
  Rte_Runnable_Ap_TJADamp_TJADamp_Per1_Return();

  /* write implicit data */
  Rte_Ap_TJADamp_CustomDamp_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_TB.Rte_I_Ap_TJADamp_CustomDamp_MtrNm_f32.value);
  Rte_Ap_TJADamp_TJAState_Cnt_enum = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_TJADamp_TJADamp_Per1.Rte_TJAState_Cnt_enum.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_AssistCmd_MtrNm_f32.value) = Rte_StabilityComp_AssistCmd_MtrNm_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_DampingDDFactor_Uls_f32.value) = Rte_DrvDynCtrl_DampingDDFactor_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_DefeatDampingSvc_Cnt_lgc.value) = Rte_CDDInterface9_DampingSrlComSvcDft_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_Damping_Damping_Per1_Start();
  Damping_Per1();
  Rte_Runnable_Ap_Damping_Damping_Per1_Return();

  /* write implicit data */
  Rte_Damping_DampingCmd_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_DampingCmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface9_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_VehicleLonAccel_KphpS_f32.value) = Rte_FrqDepDmpnInrtCmp_VehicleLonAccel_KphpS_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value) = Rte_FrqDepDmpnInrtCmp_WIRCmdAmpBlnd_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start();
  FrqDepDmpnInrtCmp_Per1();
  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return();

  /* write implicit data */
  Rte_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_FrqDepDmpnInrtCmp_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_AsstFWActive_Uls_f32.value) = Rte_AssistFirewall_AsstFirewallActive_Uls_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_CombinedAssist_MtrNm_f32.value) = Rte_AssistFirewall_CombinedAssist_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start();
  StabilityComp2_Per1();
  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return();

  /* write implicit data */
  Rte_StabilityComp2_SysAssistCmd_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_SysAssistCmd_MtrNm_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_DisableLearning_Cnt_lgc.value) = Rte_CDDInterface9_ActPullCompLrnSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_DisableOutput_Cnt_lgc.value) = Rte_CDDInterface9_PullCompSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_EstLatAcc_MpSecSq_f32.value) = Rte_SignlCondn_EstimdLatAcce_MpSecSq_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value) = Rte_MtrVel_HandwheelVel_HwRadpS_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpCustLrngDi_Cnt_lgc.value) = Rte_ActivePull_PullCmpCustLrngDi_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpEna_Cnt_lgc.value) = Rte_VehCfg_CPLCOMPIF_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32.value) = Rte_ActivePull_PullCmpShoTermIntgtrStOffs_HwNm_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_SignlCondn_VehicleSpeedValid_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleYawRate_DegpS_f32.value) = Rte_SrlComInput2_SrlComVehYawRate_DegpS_f32;

    /* call runnable */
    Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start();
    ActivePull_Per1();
    Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return();

    /* write implicit data */
    Rte_ActivePull_PullCmpShoTermIntgtrSt_HwNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpShoTermIntgtrSt_HwNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_ActivePull_ActivePull_Per2 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_DisableOutput_Cnt_lgc.value) = Rte_CDDInterface9_PullCompSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpEna_Cnt_lgc.value) = Rte_VehCfg_CPLCOMPIF_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32.value) = Rte_ActivePull_PullCmpLongTermIntgtrStOffs_HwNm_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32.value) = Rte_ActivePull_PullCmpShoTermIntgtrStOffs_HwNm_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start();
    ActivePull_Per2();
    Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return();

    /* write implicit data */
    Rte_ActivePull_PullCompCmd_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCompCmd_MtrNm_f32.value);
  }

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_MtrDrvrInitComplete_Cnt_lgc.value) = Rte_MtrDrvDiag_MtrDrvrInitComplete_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscATestComplete_Cnt_lgc.value) = Rte_Sa_BkCpPc_PwrDiscATestComplete_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscBTestComplete_Cnt_lgc.value) = Rte_Sa_BkCpPc_PwrDiscBTestComplete_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_TMFTestComplete_Cnt_lgc.value) = Rte_TmprlMon_TMFTestComplete_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start();
  HwPwUp_Per1();
  Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return();

  /* write implicit data */
  Rte_HwPwUp_MtrDrvrInitStart_Cnt_lgc = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_MtrDrvrInitStart_Cnt_lgc.value);
  Rte_HwPwUp_PwrDiscATestStart_Cnt_lgc = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscATestStart_Cnt_lgc.value);
  Rte_HwPwUp_PwrDiscBTestStart_Cnt_lgc = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscBTestStart_Cnt_lgc.value);
  Rte_HwPwUp_TMFTestStart_Cnt_lgc = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_TMFTestStart_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start();
  StaMd9_Per1();
  Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_CASSISTMSA_Cnt_lgc.value) = Rte_VehCfg_CASSISTMSA_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_EngONSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface9_EngONSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_SrlComEngDrvStatus_ST_CENG.value) = Rte_SrlComInput2_SrlComEngDrvStatus_ST_CENG;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_SrlComVehCdnStatus_VehCdnStatus.value) = Rte_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_SrlComVehNearStandstill_Cnt_u08.value) = Rte_SrlComInput2_SrlComVehNearStandstill_Cnt_u08;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_SignlCondn_VehicleSpeedValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start();
  VehPwrMd_Per1();
  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return();

  /* write implicit data */
  Rte_VehPwrMd_ATermActive_Cnt_lgc = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_ATermActive_Cnt_lgc.value);
  Rte_VehPwrMd_CTermActive_Cnt_lgc = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_CTermActive_Cnt_lgc.value);
  Rte_VehPwrMd_MSACommand_MSACmd_enum = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_MSACommand_MSACmd_enum.value);
  Rte_VehPwrMd_OperRampRate_XpmS_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_OperRampRate_XpmS_f32.value);
  Rte_VehPwrMd_OperRampValue_Uls_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_OperRampValue_Uls_f32.value);

  /* read implicit data */
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CERRMVOLTFALLBACK_Cnt_lgc.value) = Rte_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc;
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DiagStsDefVehSpd_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc;
  (void)Com_ReceiveSignal(Com_CTR_ERRM_BN_U__ERRM_BN_U, (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_RxCtrErrmBnU_Cnt_u8.value));
  Rte_ComHook_Com_CTR_ERRM_BN_U__ERRM_BN_U_SigRx(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_RxCtrErrmBnU_Cnt_u8.value);
  *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_SrlComSvcDft_Cnt_b32.value) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;

  /* call runnable */
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start();
  SrlComInput_Per1();
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return();

  DisableAllInterrupts();
  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2msA_9_Rte_Trigger1_BmwHaptcFb_BmwHaptcFb_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbEnable_Cnt_lgc.value) = Rte_VehCfg_CEVIIF_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbIntenNr_Cnt_u16.value) = Rte_SrlComInput_HaptcFbIntenNr_Cnt_u16;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbIntenSigVld_Cnt_lgc.value) = Rte_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbPatNr_Cnt_u16.value) = Rte_SrlComInput_HaptcFbPatNr_Cnt_u16;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbPatSigVld_Cnt_lgc.value) = Rte_SrlComInput_HaptcFbPatSigVld_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_PostLimitTrq_MtrNm_f32.value) = Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_PreLimitTrq_MtrNm_f32.value) = Rte_AssistSumnLmt_PreLimitTorque_MtrNm_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscActv_Cnt_lgc.value) = Rte_TrqOsc_TrqOscActv_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscDCExceeded_Cnt_lgc.value) = Rte_TrqOsc_TrqOscDCExceeded_Cnt_lgc;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_SignlCondn_VehicleSpeedValid_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Ap_BmwHaptcFb_BmwHaptcFb_Per1_Start();
    BmwHaptcFb_Per1();
    Rte_Runnable_Ap_BmwHaptcFb_BmwHaptcFb_Per1_Return();

    /* write implicit data */
    Rte_BmwHaptcFb_HaptcFbSt_Cnt_u08 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbSt_Cnt_u08.value);
    Rte_BmwHaptcFb_TrqOscAmp_MtrNm_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscAmp_MtrNm_f32.value);
    Rte_BmwHaptcFb_TrqOscEnable_Cnt_lgc = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscEnable_Cnt_lgc.value);
    Rte_BmwHaptcFb_TrqOscFallingRampRate_MtrNmpS_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscFallingRampRate_MtrNmpS_f32.value);
    Rte_BmwHaptcFb_TrqOscFreq_Hz_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscFreq_Hz_f32.value);
    Rte_BmwHaptcFb_TrqOscRisngRampRate_MtrNmpS_f32 = *(&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscRisngRampRate_MtrNmpS_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msEndA_Per_Start();
  ChkPtAp9_2msEndA_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msEndA_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2msB_9
 * Priority: 61
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2msB_9)
{
  Rte_Task_Dispatch(Task_2msB_9);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msStartB_Per_Start();
  ChkPtAp9_2msStartB_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msStartB_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start();
  DAQ_2msTL();
  Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msEndB_Per_Start();
  ChkPtAp9_2msEndB_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msEndB_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2ms_10
 * Priority: 65
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_10)
{
  Rte_Task_Dispatch(Task_2ms_10);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_2msStart_Per_Start();
  ChkPtAp10_2msStart_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_2msStart_Per_Return();

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistFirewall_AssistFirewall_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_BaseAssistCmd_MtrNm_f32.value) = Rte_Assist_BaseAssistCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_Defeat_AsstTbl_Service_Cnt_lgc.value) = Rte_CDDInterface9_FirewallSrlComSrvDft_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_HighFreqAssist_MtrNm_f32.value) = Rte_TrqBasedInrtCmp_HighFreqAssist_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_HysteresisComp_MtrNm_f32.value) = Rte_HystComp_HysteresisComp_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_MEC_Counter_Cnt_enum.value) = Rte_CDDInterface9_NxtrMEC_Cnt_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start();
    AssistFirewall_Per1();
    Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return();

    /* write implicit data */
    Rte_AssistFirewall_AsstFirewallActive_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_AsstFirewallActive_Uls_f32.value);
    Rte_AssistFirewall_CombinedAssist_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_CombinedAssist_MtrNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_AssistDDFactor_Uls_f32.value) = Rte_DrvDynCtrl_AssistDDFactor_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_AsstFWActive_Uls_f32.value) = Rte_AssistFirewall_AsstFirewallActive_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_CombinedAssist_MtrNm_f32.value) = Rte_AssistFirewall_CombinedAssist_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_SysAssistCmd_MtrNm_MtrNm_f32.value) = Rte_StabilityComp2_SysAssistCmd_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start();
  StabilityComp_Per1();
  Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return();

  /* write implicit data */
  Rte_StabilityComp_AssistCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_AssistCmd_MtrNm_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_DampingFirewall_DampingFirewall_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_AsstFirewallActive_Uls_f32.value) = Rte_AssistFirewall_AsstFirewallActive_Uls_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_BaseAssistCmd_MtrNm_f32.value) = Rte_Assist_BaseAssistCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_DampingCmd_MtrNm_f32.value) = Rte_Damping_DampingCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_Defeat_Damping_Svc_Cnt_lgc.value) = Rte_CDDInterface9_FirewallSrlComSrvDft_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface9_FreqDepDmpSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_InertiaComp_MtrNm_f32.value) = Rte_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_MEC_Counter_Cnt_enum.value) = Rte_CDDInterface9_NxtrMEC_Cnt_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_MtrVelCRF_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_VehicleLonAccel_KphpS_f32.value) = Rte_DampingFirewall_VehicleLonAccel_KphpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value) = Rte_DampingFirewall_WIRCmdAmpBlnd_MtrNm_f32;

    /* call runnable */
    Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start();
    DampingFirewall_Per1();
    Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return();

    /* write implicit data */
    Rte_DampingFirewall_CombinedDamping_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_CombinedDamping_MtrNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_ReturnFirewall_ReturnFirewall_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ReturnFirewall_ReturnFirewall_Per1.Rte_Defeat_Return_Svc_Cnt_lgc.value) = Rte_CDDInterface9_FirewallSrlComSrvDft_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ReturnFirewall_ReturnFirewall_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ReturnFirewall_ReturnFirewall_Per1.Rte_MEC_Counter_Cnt_enum.value) = Rte_CDDInterface9_NxtrMEC_Cnt_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ReturnFirewall_ReturnFirewall_Per1.Rte_ReturnCmd_MtrNm_f32.value) = Rte_BmwRtnArbn_ReturnCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ReturnFirewall_ReturnFirewall_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start();
    ReturnFirewall_Per1();
    Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return();

    /* write implicit data */
    Rte_ReturnFirewall_LimitedReturn_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ReturnFirewall_ReturnFirewall_Per1.Rte_LimitedReturn_MtrNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_CcwEOT_HwDeg_f32.value) = Rte_LrnEOT_CCWPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_CcwFound_Cnt_lgc.value) = Rte_LrnEOT_CCWFound_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_CwEOT_HwDeg_f32.value) = Rte_LrnEOT_CWPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_CwFound_Cnt_lgc.value) = Rte_LrnEOT_CWFound_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_EOTDisable_Cnt_lgc.value) = Rte_CDDInterface9_EOTImpactSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_MtrVel_CRFMotorVel_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_OutputRampMultLtd_Uls_f32.value) = Rte_LmtCod_OutputRampMultLtd_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_PreLimitTorque_MtrNm_f32.value) = Rte_AssistSumnLmt_PreLimitTorque_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start();
  EOTActuatorMng_Per1();
  Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return();

  /* write implicit data */
  Rte_EOTActuatorMng_AssistEOTDamping_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_EOTActuatorMng_AssistEOTDamping_MtrNm_f32.value);
  Rte_EOTActuatorMng_AssistEOTGain_Uls_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_EOTActuatorMng_AssistEOTGain_Uls_f32.value);
  Rte_EOTActuatorMng_AssistEOTLimit_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_EOTActuatorMng_AssistEOTLimit_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EtDmpFw_EtDmpFw_Per1.Rte_EOTDisable_Cnt_lgc.value) = Rte_CDDInterface9_FirewallSrlComSrvDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EtDmpFw_EtDmpFw_Per1.Rte_MEC_Counter_Cnt_enum.value) = Rte_CDDInterface9_NxtrMEC_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Ap_EtDmpFw_EtDmpFw_Per1_Start();
  EtDmpFw_Per1();
  Rte_Runnable_Ap_EtDmpFw_EtDmpFw_Per1_Return();

  /* write implicit data */
  Rte_EtDmpFw_EOTDampingLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EtDmpFw_EtDmpFw_Per1.Rte_EOTDampingLtd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_DiagRampRate_XpmS_f32.value) = Rte_DiagMgr10_DiagRampRate_XpmS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_DiagRampValue_Uls_f32.value) = Rte_DiagMgr10_DiagRampValue_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_DiagStsDiagRmpActive_Cnt_lgc.value) = Rte_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_OperRampRate_XpmS_f32.value) = Rte_VehPwrMd_OperRampRate_XpmS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_OperRampValue_Uls_f32.value) = Rte_VehPwrMd_OperRampValue_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_RampSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface9_TrqRmpSrlComSvcDft_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start();
  StOpCtrl_Per1();
  Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return();

  /* write implicit data */
  Rte_StOpCtrl_OutputRampMult_Uls_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_StOpCtrl_OutputRampMult_Uls_f32.value);
  Rte_StOpCtrl_RampDwnStatusComplete_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_RampDwnStatusComplete_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AssistStallLimit_MtrNm_f32.value) = Rte_HiLoadStall_AssistStallLimit_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AssistVehSpdLimit_MtrNm_f32.value) = Rte_VehSpdLmt_AstVehSpdLimit_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_CCLTrqRamp_Uls_f32.value) = Rte_CustPL_CCLTrqRamp_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_ThermalLimit_MtrNm_f32.value) = Rte_ThrmlDutyCycle_ThermalLimit_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start();
  LmtCod_Per1();
  Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return();

  /* write implicit data */
  Rte_LmtCod_EOTGainLtd_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_EOTGainLtd_Uls_f32.value);
  Rte_LmtCod_EOTLimitLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_EOTLimitLtd_MtrNm_f32.value);
  Rte_LmtCod_OutputRampMultLtd_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_OutputRampMultLtd_Uls_f32.value);
  Rte_LmtCod_StallLimitLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_StallLimitLtd_MtrNm_f32.value);
  Rte_LmtCod_ThermalLimitLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_ThermalLimitLtd_MtrNm_f32.value);
  Rte_LmtCod_VehSpdLimitLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_VehSpdLimitLtd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscAmp_MtrNm_f32.value) = Rte_BmwHaptcFb_TrqOscAmp_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscEnable_Cnt_lgc.value) = Rte_BmwHaptcFb_TrqOscEnable_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscFallRampRate_MtrNmpS_f32.value) = Rte_BmwHaptcFb_TrqOscFallingRampRate_MtrNmpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscFreq_Hz_f32.value) = Rte_BmwHaptcFb_TrqOscFreq_Hz_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscRisngRampRate_MtrNmpS_f32.value) = Rte_BmwHaptcFb_TrqOscRisngRampRate_MtrNmpS_f32;

  /* call runnable */
  Rte_Runnable_Ap_TrqOsc_TrqOsc_Per1_Start();
  TrqOsc_Per1();
  Rte_Runnable_Ap_TrqOsc_TrqOsc_Per1_Return();

  /* write implicit data */
  Rte_TrqOsc_TrqOscActv_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscActv_Cnt_lgc.value);
  Rte_TrqOsc_TrqOscCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscCmd_MtrNm_f32.value);
  Rte_TrqOsc_TrqOscDCExceeded_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscDCExceeded_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1.Rte_DrvDynActive_Cnt_lgc.value) = Rte_DrvDynamicsEnable_DrvDynActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1.Rte_DrvgDynErrIfActv_Cnt_lgc.value) = Rte_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1.Rte_DrvgDynIfSt_Cnt_u08.value) = Rte_DrvDynamicsEnable_DrvDynInterfaceState_Cnt_u08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1.Rte_OpTrqOvRmpInEnable_Cnt_lgc.value) = Rte_DrvDynamicsEnable_OpTrqOvRmpInEnable_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1.Rte_SerlComTarSteerTqDrvrActr_MtrNm_f32.value) = Rte_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1_Start();
  BmwTqOvrlCdng_Per1();
  Rte_Runnable_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1_Return();

  /* write implicit data */
  Rte_Ap_BmwTqOvrlCdng_OutpTqOvrl_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1.Rte_OutpTqOvrl_MtrNm_f32.value);

  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_AssistSumnLmt_AssistSumnLmt_Per1 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_AssistCmd_MtrNm_f32.value) = Rte_StabilityComp_AssistCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_AssistPowerLimit_MtrNm_f32.value) = Rte_PwrLmtFunc_AssistPowerLimit_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_CombinedDamping_MtrNm_f32.value) = Rte_DampingFirewall_CombinedDamping_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_DefeatLimitService_Cnt_lgc.value) = Rte_CDDInterface9_LimitSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_EOTDampingLtd_MtrNm_f32.value) = Rte_EtDmpFw_EOTDampingLtd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_EOTGainLtd_Uls_f32.value) = Rte_LmtCod_EOTGainLtd_Uls_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_EOTLimitLtd_MtrNm_f32.value) = Rte_LmtCod_EOTLimitLtd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_LimitedReturn_MtrNm_f32.value) = Rte_ReturnFirewall_LimitedReturn_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_LrnPnCtrDisable_Cnt_lgc.value) = Rte_PrkAstMfgServCh2_SysCLnPnCtrCCDisable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_LrnPnCtrEnable_Cnt_lgc.value) = Rte_CDDInterface9_LrnPnCenterEnable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_LrnPnCtrTCmd_MtrNm_f32.value) = Rte_LktoLkStr_LrnPnCntrCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_OutpTqOvrl_MtrNm_f32.value) = Rte_Ap_BmwTqOvrlCdng_OutpTqOvrl_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_OutputRampMultLtd_Uls_f32.value) = Rte_LmtCod_OutputRampMultLtd_Uls_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PrkAssistCmd_MtrNm_f32.value) = Rte_PosServo_PosSrvoCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PrkAssistDisable_Cnt_lgc.value) = Rte_PrkAstMfgServCh2_SysCPosServCCDisable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PullCompCmd_MtrNm_f32.value) = Rte_ActivePull_PullCompCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_StallLimitLtd_MtrNm_f32.value) = Rte_LmtCod_StallLimitLtd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_ThermalLimitLtd_MtrNm_f32.value) = Rte_LmtCod_ThermalLimitLtd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_TrqOscCmd_MtrNm_f32.value) = Rte_TrqOsc_TrqOscCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_VehSpdLimitLtd_MtrNm_f32.value) = Rte_LmtCod_VehSpdLimitLtd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_WhlImbRejCmd_MtrNm_f32.value) = Rte_AssistSumnLmt_WhlImbRejCmd_MtrNm_f32;

    /* call runnable */
    Rte_Runnable_Ap_AssistSumnLmt_AssistSumnLmt_Per1_Start();
    AssistSumnLmt_Per1();
    Rte_Runnable_Ap_AssistSumnLmt_AssistSumnLmt_Per1_Return();

    /* write implicit data */
    Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PostLimitTorque_MtrNm_f32.value);
    Rte_AssistSumnLmt_PreLimitForPower_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitForPower_MtrNm_f32.value);
    Rte_AssistSumnLmt_PreLimitForStall_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitForStall_MtrNm_f32.value);
    Rte_AssistSumnLmt_PreLimitTorque_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitTorque_MtrNm_f32.value);
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Sweep2_Sweep2_Per1.Rte_InputMtrTrq_MtrNm_f32.value) = Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_Sweep2_Sweep2_Per1_Start();
  Sweep2_Per1();
  Rte_Runnable_Ap_Sweep2_Sweep2_Per1_Return();

  /* write implicit data */
  Rte_Sweep2_OutputMtrTrq_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sweep2_OutputMtrTrq_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Polarity_AssistAssyPolarity_Cnt_s08.value) = Rte_Polarity_AssistAssyPolarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1.Rte_CRFMtrVel_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1.Rte_DiagStsF2Active_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start();
  CtrldDisShtdn_Per1();
  Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return();

  /* write implicit data */
  Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32.value);
  Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32.value);
  Rte_CtrldDisShtdn_CtrldDmpStsCmp_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CtrldDisShtdn_CtrldDmpStsCmp_Cnt_lgc.value);
  Rte_CtrldDisShtdn_SysC_CRFMtrTrqCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1.Rte_SysC_CRFMtrTrqCmd_MtrNm_f32.value);
  Rte_CtrldDisShtdn_SysC_MRFMtrTrqCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1.Rte_SysC_MRFMtrTrqCmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_AlignedCumMtrPosMRF_Deg_f32.value) = Rte_MtrPos_AlignedCumMtrPosMRF_Deg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_DiagStsDefHwPos_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_DiagStsHwPosDis_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_ICMRevOffsetCRF_Rev_s16.value) = Rte_SrlComInput2_SrlComCRFRevOffset_Rev_s16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_ICMRevOffsetStatus_Cnt_u08.value) = Rte_SrlComInput2_SrlComRevOffsetSts_Cnt_u08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_LTRckCntrComplete_Cnt_lgc.value) = Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RackCenter_HwDeg_f32.value) = Rte_LnRkCr_RackCenter_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_TCMtrPosOffsMRF_Deg_f32.value) = Rte_TurnsCounter_TCMtrPosOffsMRF_Deg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_TurnsCntrValidity_Cnt_enum.value) = Rte_TurnsCounter_TurnsCntrValidity_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per1_Start();
  AbsHwPos_Per1();
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per1_Return();

  /* write implicit data */
  Rte_AbsHwPos_AlignedHwPos_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_AlignedHwPos_HwDeg_f32.value);
  Rte_AbsHwPos_HandwheelAuthority_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HandwheelAuthority_Uls_f32.value);
  Rte_AbsHwPos_HandwheelPosition_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HandwheelPosition_HwDeg_f32.value);
  Rte_AbsHwPos_HwTargetAuthority_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_HwTargetAuthority_Uls_f32.value);
  Rte_AbsHwPos_ICMMtrPosMRF_Deg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_ICMMtrPosMRF_Deg_f32.value);
  Rte_AbsHwPos_RacktoVehCntrOffset_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RacktoVehCntrOffset_Cnt_u16.value);
  Rte_AbsHwPos_RevOffsetState_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RevOffsetState_Cnt_u08.value);
  Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_SrlComHwPos_HwDeg_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per3.Rte_FETFaultPhase_Cnt_enum.value) = Rte_MtrDrvDiag_FETFaultPhase_Cnt_enum;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per3.Rte_FETFaultType_Cnt_enum.value) = Rte_MtrDrvDiag_FETFaultType_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface10_CDDInterface10_Per3_Start();
  CDDInterface10_Per3();
  Rte_Runnable_Sa_CDDInterface10_CDDInterface10_Per3_Return();

  /* call runnable */
  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start();
  TrqCmdScl_Per1();
  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return();

  /* write implicit data */
  Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per1.Rte_EstKe_VpRadpS_f32.value) = Rte_ParamComp_EstKe_VpRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_ParamComp_EstR_Ohm_f32.value) = Rte_ParamComp_EstR_Ohm_f32;

  /* call runnable */
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Per1_Start();
  VltgCtrl_Per1();
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Per1_Return();

  /* write implicit data */
  Rte_VltgCtrl_TermBSS_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per1.Rte_TermBSS_Volt_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_ExpIq_Amp_f32.value) = Rte_ParamComp_ExpIq_Amp_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_ModIdx_Uls_f32.value) = Rte_VltgCtrl_ModIdx_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_TermXq_Uls_f32.value) = Rte_VltgCtrl_TermXq_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_UncorrPhsAdv_Cnt_s16.value) = Rte_VltgCtrl_UnCorrPhsAdv_Cnt_s16;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value) = Rte_BatteryVoltage_Vecu_Volt_f32;

  /* call runnable */
  Rte_Runnable_Ap_CurrentEst_CurrentEst_Per1_Start();
  CurrentEst_Per1();
  Rte_Runnable_Ap_CurrentEst_CurrentEst_Per1_Return();

  /* write implicit inter-runnable variables */
  Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32 = Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32_Task_2ms_10;
  /* write implicit data */
  Rte_CurrentEst_EstPkCurr_AmpSq_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_EstPkCurr_AmpSq_f32.value);
  Rte_CurrentEst_IdEst_Amp_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CurrentEst_IdEst_Amp_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value) = Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_MtrCurrQax_Amp_f32.value) = Rte_MtrCurr_MtrCurrQax_Amp_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface9_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_QuadDet_MtrQuad_Cnt_u08.value) = Rte_QuadDet_MtrQuad_Cnt_u08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_ValidCurrSample_Cnt_lgc.value) = Rte_MtrCurr_ValidSampleFlag_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_ParamComp_ParamComp_Per1_Start();
  ParamComp_Per1();
  Rte_Runnable_Ap_ParamComp_ParamComp_Per1_Return();

  /* write implicit data */
  Rte_ParamComp_EstKe_VpRadpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstKe_VpRadpS_f32.value);
  Rte_ParamComp_EstLd_Henry_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstLd_Henry_f32.value);
  Rte_ParamComp_EstLq_Henry_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstLq_Henry_f32.value);
  Rte_ParamComp_EstR_Ohm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstR_Ohm_f32.value);
  Rte_ParamComp_ExpIq_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_ExpIq_Amp_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per3.Rte_CCLMSAActive_Cnt_lgc.value) = Rte_CustPL_CCLMSAActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per3.Rte_MtrEnvSpd_MtrRadpS_f32.value) = Rte_PwrLmtFunc_MtrEnvSpd_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Per3_Start();
  VltgCtrl_Per3();
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Per3_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_RawCurrFiltered_Amp_f32.value) = Rte_MtrCurr_RawCurrFiltered_Amp_f32;

  /* call runnable */
  Rte_Runnable_Sa_PhaseDscnt_PhaseDscnt_Per1_Start();
  PhaseDscnt_Per1();
  Rte_Runnable_Sa_PhaseDscnt_PhaseDscnt_Per1_Return();

  /* write implicit data */
  Rte_PhaseDscnt_PDActivateTest_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDActivateTest_Cnt_lgc.value);
  Rte_PhaseDscnt_PDPhaseAdvSelect_Cnt_s16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDPhaseAdvSelect_Cnt_s16.value);
  Rte_PhaseDscnt_PDTestModIndex_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDTestModIndex_Uls_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start();
  DiagMgr_Per1();
  Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_ATerm_Cnt_lgc.value) = Rte_VehPwrMd_ATermActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_CTerm_Cnt_lgc.value) = Rte_VehPwrMd_CTermActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_FTerm_Cnt_lgc.value) = Rte_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_RampStatusComplete_Cnt_lgc.value) = Rte_StOpCtrl_RampDwnStatusComplete_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_TMFTestComplete_Cnt_lgc.value) = Rte_TmprlMon_TMFTestComplete_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_StaMd_StaMd_Per1_Start();
  StaMd_Per1();
  Rte_Runnable_Ap_StaMd_StaMd_Per1_Return();

  /* call runnable */
  Rte_Runnable_NxtrLibs_SystemTime_Per1_Start();
  SystemTime_Per1();
  Rte_Runnable_NxtrLibs_SystemTime_Per1_Return();

  /* call runnable */
  Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start();
  TmprlMon2_Per1();
  Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MtrElecMechPolarity_Cnt_s08.value) = Rte_Polarity_MtrElecMechPolarity_Cnt_s08;

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface10_CDDInterface10_Per1_Start();
  CDDInterface10_Per1();
  Rte_Runnable_Sa_CDDInterface10_CDDInterface10_Per1_Return();

  /* write implicit data */
  Rte_CDDInterface10_DutyCycleSmall_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_DutyCycleSmall_Cnt_u16.value);
  Rte_CDDInterface10_ExpectedOnTimeA_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value);
  Rte_CDDInterface10_ExpectedOnTimeB_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value);
  Rte_CDDInterface10_ExpectedOnTimeC_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value);
  Rte_CDDInterface10_MeasuredOnTimeA_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value);
  Rte_CDDInterface10_MeasuredOnTimeB_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value);
  Rte_CDDInterface10_MeasuredOnTimeC_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_DiagStsDefVehSpd_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_SrlComSvcDft_Cnt_b32.value) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;

  /* call runnable */
  Rte_Runnable_Ap_SrlComInput2_SrlComInput2_Per1_Start();
  SrlComInput2_Per1();
  Rte_Runnable_Ap_SrlComInput2_SrlComInput2_Per1_Return();

  /* write implicit data */
  Rte_SrlComInput2_SrlComEngCrank_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_SrlComEngCrank_Cnt_lgc.value);
  Rte_SrlComInput2_VehSpdValid_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_VehSpdValid_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_2msEnd_Per_Start();
  ChkPtAp10_2msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_2msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2ms_11
 * Priority: 63
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_11)
{
  Rte_Task_Dispatch(Task_2ms_11);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp11_ChkPtAp11_2msStart_Per_Start();
  ChkPtAp11_2msStart_Per();
  Rte_Runnable_Ap_ChkPtAp11_ChkPtAp11_2msStart_Per_Return();

  DisableAllInterrupts();
  if (Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_MtrDrvrInitStart_Cnt_lgc.value) = Rte_HwPwUp_MtrDrvrInitStart_Cnt_lgc;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_VswitchClosed_Cnt_lgc.value) = Rte_BatteryVoltage_VswitchClosed_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start();
    MtrDrvDiag_Per1();
    Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return();

    /* write implicit data */
    Rte_MtrDrvDiag_FETFaultPhase_Cnt_enum = *(&Rte_Task_2ms_11.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_FETFaultPhase_Cnt_enum.value);
    Rte_MtrDrvDiag_FETFaultType_Cnt_enum = *(&Rte_Task_2ms_11.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_FETFaultType_Cnt_enum.value);
    Rte_MtrDrvDiag_MtrDrvrInitComplete_Cnt_lgc = *(&Rte_Task_2ms_11.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_MtrDrvrInitComplete_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_MtrDrvDiag_MtrDrvDiag_Per2 == 0)
  {
    EnableAllInterrupts();
    /* call runnable */
    Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start();
    MtrDrvDiag_Per2();
    Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return();
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_11_TriggerDisableFlags.Rte_Trigger_Task_2ms_11_Rte_Trigger1_DigPhsReasDiag_DigPhsReasDiag_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value) = Rte_CDDInterface10_ExpectedOnTimeA_Cnt_u32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value) = Rte_CDDInterface10_ExpectedOnTimeB_Cnt_u32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value) = Rte_CDDInterface10_ExpectedOnTimeC_Cnt_u32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_LRPRCorrectedMtrPosCaptured_Rev_f32.value) = Rte_MtrPos2_CorrectedMtrPos_Rev_f32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_LRPRModulationIndexCaptured_Uls_f32.value) = Rte_VltgCtrl_ModIdx_Uls_f32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_LRPRPhaseadvanceCaptured_Cnt_s16.value) = Rte_VltgCtrl_PhsAdv_Cnt_s16;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value) = Rte_CDDInterface10_MeasuredOnTimeA_Cnt_u32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value) = Rte_CDDInterface10_MeasuredOnTimeB_Cnt_u32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value) = Rte_CDDInterface10_MeasuredOnTimeC_Cnt_u32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MotorVelMRFUnfiltered_MtrRadpS_f32.value) = Rte_MtrVel_MRFMotorVelUnfiltered_MtrRadpS_f32;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MtrElecMechPolarity_Cnt_s08.value) = Rte_Polarity_MtrElecMechPolarity_Cnt_s08;
    *(&Rte_Task_2ms_11.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_PDActivateTest_Cnt_lgc.value) = Rte_PhaseDscnt_PDActivateTest_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start();
    DigPhsReasDiag_Per1();
    Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return();
  }
  else
  {
    EnableAllInterrupts();
  }

  /* call runnable */
  Rte_Runnable_Ap_StaMd11_StaMd11_Per1_Start();
  StaMd11_Per1();
  Rte_Runnable_Ap_StaMd11_StaMd11_Per1_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp11_ChkPtAp11_2msEnd_Per_Start();
  ChkPtAp11_2msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp11_ChkPtAp11_2msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2ms_7
 * Priority: 68
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_7)
{
  Rte_Task_Dispatch(Task_2ms_7);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_2msStart_Per_Start();
  ChkPtAp7_2msStart_Per();
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_2msStart_Per_Return();

  /* call runnable */
  Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start();
  TmprlMon_Per1();
  Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return();

  /* call runnable */
  Rte_Runnable_IoHwAb7_IoHwAb7_FwdPathAdc_Start();
  IoHwAb7_FwdPathAdc();
  Rte_Runnable_IoHwAb7_IoHwAb7_FwdPathAdc_Return();

  /* write implicit data */
  Rte_IoHwAb7_ADCMtrCurr1_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FwdPathAdc.Rte_ADCMtrCurr1_Volt_f32.value);
  Rte_IoHwAb7_SysCT1ADC_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FwdPathAdc.Rte_SysCT1ADC_Volt_f32.value);
  Rte_IoHwAb7_SysCT2ADC_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FwdPathAdc.Rte_SysCT2ADC_Volt_f32.value);
  Rte_IoHwAb7_T1ADC_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FwdPathAdc.Rte_T1ADC_Volt_f32.value);
  Rte_IoHwAb7_T2ADC_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FwdPathAdc.Rte_T2ADC_Volt_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_MotorVelMRF_MtrRadpS_f32.value) = Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start();
  MtrPos2_Per1();
  Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return();

  /* write implicit data */
  Rte_MtrPos2_CorrectedMtrPos_Rev_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_CorrectedMtrPos_Rev_f32.value);
  Rte_MtrPos2_CosTheta1_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_CosTheta1_Volt_f32.value);
  Rte_MtrPos2_MechMtrPos_Rev_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_MechMtrPos_Rev_f32.value);
  Rte_MtrPos2_SinTheta1_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SinTheta1_Volt_f32.value);
  Rte_MtrPos2_SysCCorrectedMtrPos_Rev_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SysCCorrectedMtrPos_Rev_f32.value);
  Rte_MtrPos2_SysCMechMtrPos_Rev_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SysCMechMtrPos_Rev_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_LktoLkStr_LktoLkStr_Per1.Rte_AlignedHwPosition_HwDeg_f32.value) = Rte_AbsHwPos_AlignedHwPos_HwDeg_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_LktoLkStr_LktoLkStr_Per1.Rte_LrnPnCenterEnable_Cnt_lgc.value) = Rte_CDDInterface9_LrnPnCenterEnable_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_TB.Rte_I_MtrVel_CRFMotorVel_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Ap_LktoLkStr_LktoLkStr_Per1_Start();
  LktoLkStr_Per1();
  Rte_Runnable_Ap_LktoLkStr_LktoLkStr_Per1_Return();

  /* write implicit data */
  Rte_LktoLkStr_LrnPnCntrCmd_MtrNm_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_LktoLkStr_LktoLkStr_Per1.Rte_LrnPnCntrCmd_MtrNm_f32.value);
  Rte_LktoLkStr_LrnPnCntrHwCenter_HwDeg_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_LktoLkStr_LktoLkStr_Per1.Rte_LrnPnCntrHwCenter_HwDeg_f32.value);
  Rte_LktoLkStr_LrnPnCntrHwTravel_HwDeg_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_LktoLkStr_LktoLkStr_Per1.Rte_LrnPnCntrHwTravel_HwDeg_f32.value);
  Rte_LktoLkStr_LrnPnCntrState_Cnt_enum = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_LktoLkStr_LktoLkStr_Per1.Rte_LrnPnCntrState_Cnt_enum.value);

  /* call runnable */
  Rte_Runnable_Ap_FltInjection_FltInjection_Per1_Start();
  FltInjection_Per1();
  Rte_Runnable_Ap_FltInjection_FltInjection_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_TB.Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_2ms_7.Rte_TB.Rte_I_CDDInterface9_PosTrajEnable_Cnt_lgc.value) = Rte_CDDInterface9_PosTrajEnable_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_GenPosTraj_GenPosTraj_Per1_Start();
  GenPosTraj_Per1();
  Rte_Runnable_Ap_GenPosTraj_GenPosTraj_Per1_Return();

  /* write implicit data */
  Rte_GenPosTraj_PosTrajHwAngle_HwDeg_f32 = *(&Rte_Task_2ms_7.Rte_TB.Rte_I_GenPosTraj_PosTrajHwAngle_HwDeg_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_TB.Rte_I_CDDInterface9_OscTrajEnable_Cnt_lgc.value) = Rte_CDDInterface9_OscTrajEnable_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_OscTraj_OscTraj_Per1_Start();
  OscTraj_Per1();
  Rte_Runnable_Ap_OscTraj_OscTraj_Per1_Return();

  /* write implicit data */
  Rte_OscTraj_OscTrajState_Cnt_enum = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_OscTraj_OscTraj_Per1.Rte_OscTrajState_Cnt_enum.value);
  Rte_OscTraj_OscillateHwAngle_HwDeg_f32 = *(&Rte_Task_2ms_7.Rte_TB.Rte_I_OscTraj_OscillateHwAngle_HwDeg_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_DiagStsRmpZeroNRec_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_DiagStsRmpZeroRec_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_HandwheelVel_HwRadpS_f32.value) = Rte_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_LimitPercentFiltered_Uls_f32.value) = Rte_AssistSumnLmt_LimitPercentFiltered_Uls_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PAEnableRqst_Cnt_lgc.value) = Rte_ParkAssistEnable_PAEnableRqst_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PAErrInterfaceActive_Cnt_lgc.value) = Rte_ParkAssistEnable_PAErrInterfaceActive_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PAHWAngleRqst_HwDeg_f32.value) = Rte_ParkAssistEnable_PAHWAngleRqst_HwDeg_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PASpdHigh_Cnt_u08.value) = Rte_SrlComInput2_SrlComVehNearStandstill_Cnt_u08;

  /* call runnable */
  Rte_Runnable_Ap_ParkAstEnbl_ParkAstEnbl_Per1_Start();
  ParkAstEnbl_Per1();
  Rte_Runnable_Ap_ParkAstEnbl_ParkAstEnbl_Per1_Return();

  /* write implicit data */
  Rte_ParkAssistEnable_PosServEnable_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PosServEnable_Cnt_lgc.value);
  Rte_ParkAssistEnable_PosServoHwAngle_HwDeg_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PosServoHwAngle_HwDeg_f32.value);
  Rte_ParkAssistEnable_PrkAssistState_Cnt_u08 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PrkAssistState_Cnt_u08.value);

  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_DrvDynamicsEnable_DrvDynEnbl_Per1 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DDEnableRqst_Cnt_lgc.value) = Rte_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DDErrInterfaceActive_Cnt_lgc.value) = Rte_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DiagStatus_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_PrkAssistState_Cnt_u08.value) = Rte_ParkAssistEnable_PrkAssistState_Cnt_u08;

    /* call runnable */
    Rte_Runnable_Ap_DrvDynEnbl_DrvDynEnbl_Per1_Start();
    DrvDynEnbl_Per1();
    Rte_Runnable_Ap_DrvDynEnbl_DrvDynEnbl_Per1_Return();

    /* write implicit data */
    Rte_DrvDynamicsEnable_DrvDynActive_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DrvDynActive_Cnt_lgc.value);
    Rte_DrvDynamicsEnable_DrvDynInterfaceState_Cnt_u08 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DrvDynInterfaceState_Cnt_u08.value);
    Rte_DrvDynamicsEnable_OpTrqOvRmpInEnable_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_OpTrqOvRmpInEnable_Cnt_lgc.value);
  }

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_2ms_7.Rte_TB.Rte_I_Sweep_OutputHwTrq_HwNm_f32.value) = Rte_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_7.Rte_TB.Rte_I_MtrVel_CRFMotorVel_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoEnable_Cnt_lgc.value) = Rte_ParkAssistEnable_PosServEnable_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoHwAngle_HwDeg_f32.value) = Rte_ParkAssistEnable_PosServoHwAngle_HwDeg_f32;
  *(&Rte_Task_2ms_7.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_PosServo_PosServo_Per1_Start();
  PosServo_Per1();
  Rte_Runnable_Ap_PosServo_PosServo_Per1_Return();

  /* write implicit data */
  Rte_PosServo_PosSrvoCmd_MtrNm_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoCmd_MtrNm_f32.value);
  Rte_PosServo_PosSrvoReturnSclFct_Uls_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoReturnSclFct_Uls_f32.value);
  Rte_PosServo_PosSrvoSmoothEnable_Uls_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoSmoothEnable_Uls_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_AbsPosStepSignal_Cnt_u08.value) = Rte_HwTrq_AbsPosStepSignal_Cnt_u08;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_T1ADC_Volt_f32.value) = Rte_IoHwAb7_T1ADC_Volt_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_T2ADC_Volt_f32.value) = Rte_IoHwAb7_T2ADC_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start();
  HwTrq_Per1();
  Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return();

  /* write implicit data */
  Rte_HwTrq_AnaDiffHwTrq_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_AnaDiffHwTrq_Volt_f32.value);
  Rte_HwTrq_AnaHwTorque_HwNm_f32 = *(&Rte_Task_2ms_7.Rte_TB.Rte_I_HwTrq_AnaHwTorque_HwNm_f32.value);
  Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_SrlComHwTrqValid_Cnt_lgc.value);
  Rte_HwTrq_SysCAnaHwTorque_HwNm_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_SysCAnaHwTorque_HwNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_Sweep_Sweep_Per1.Rte_VehSpdValid_Cnt_lgc.value) = Rte_SignlCondn_VehicleSpeedValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_Sweep_Sweep_Per1_Start();
  Sweep_Per1();
  Rte_Runnable_Ap_Sweep_Sweep_Per1_Return();

  /* write implicit data */
  Rte_Sweep_OutputHwTrq_HwNm_f32 = *(&Rte_Task_2ms_7.Rte_TB.Rte_I_Sweep_OutputHwTrq_HwNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_BatteryVoltage_BatteryVoltage_Per1.Rte_Batt_Volt_f32.value) = Rte_IoHwAb7_Batt_Volt_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_BatteryVoltage_BatteryVoltage_Per1.Rte_BattSwitched_Volt_f32.value) = Rte_IoHwAb7_BattSwitched_Volt_f32;

  /* call runnable */
  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start();
  BatteryVoltage_Per1();
  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return();

  /* write implicit data */
  Rte_BatteryVoltage_SysC_Vecu_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_BatteryVoltage_BatteryVoltage_Per1.Rte_SysC_Vecu_Volt_f32.value);
  Rte_BatteryVoltage_Vecu_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_BatteryVoltage_BatteryVoltage_Per1.Rte_Vecu_Volt_f32.value);
  Rte_BatteryVoltage_VswitchClosed_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_BatteryVoltage_BatteryVoltage_Per1.Rte_VswitchClosed_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehLatAccel_MpSecSq_f32.value) = Rte_SignlCondn_SrlComVehLatAccel_MpSecSq_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehLatAccelValid_Cnt_lgc.value) = Rte_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehLonAccel_MpSecSq_f32.value) = Rte_SignlCondn_SrlComVehLonAccel_MpSecSq_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehLonAccelValid_Cnt_lgc.value) = Rte_SignlCondn_SrlComVehLonAccelValid_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehSpeed_Kph_f32.value) = Rte_SrlComInput2_SrlComVehSpd_Kph_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehSpeedValid_Cnt_lgc.value) = Rte_SrlComInput2_VehSpdValid_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehYawRate_DegpS_f32.value) = Rte_SignlCondn_SrlComVehYawRate_DegpS_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehYawRateValid_Cnt_lgc.value) = Rte_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start();
  SignlCondn_Per1();
  Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return();

  /* write implicit data */
  Rte_SignlCondn_EstimdLatAcce_MpSecSq_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_EstimdLatAcce_MpSecSq_f32.value);
  Rte_SignlCondn_EstimdLatAcceValid_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_EstimdLatAcceValid_Cnt_lgc.value);
  Rte_SignlCondn_VehicleLatAcceValid_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleLatAcceValid_Cnt_lgc.value);
  Rte_SignlCondn_VehicleLatAccel_MpSecSq_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleLatAccel_MpSecSq_f32.value);
  Rte_SignlCondn_VehicleLonAccel_KphpS_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleLonAccel_KphpS_f32.value);
  Rte_SignlCondn_VehicleLonAccelValid_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleLonAccelValid_Cnt_lgc.value);
  Rte_SignlCondn_VehicleSpeed_Kph_f32 = *(&Rte_Task_2ms_7.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value);
  Rte_SignlCondn_VehicleSpeedValid_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value);
  Rte_SignlCondn_VehicleYawRate_DegpS_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleYawRate_DegpS_f32.value);
  Rte_SignlCondn_VehicleYawRateValid_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleYawRateValid_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynCtrl_DrvDynCtrl_Per1.Rte_DDAstFactRqst_Uls_f32.value) = Rte_SrlComInput2_SrlComAssistScaleFactor_Uls_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynCtrl_DrvDynCtrl_Per1.Rte_DDDmpFactRqst_Uls_f32.value) = Rte_SrlComInput2_SrlComDampingScaleFactor_Uls_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynCtrl_DrvDynCtrl_Per1.Rte_DDRtnFactRqst_Uls_f32.value) = Rte_SrlComInput2_SrlComReturnScaleFactor_Uls_f32;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynCtrl_DrvDynCtrl_Per1.Rte_DrvDynActive_Cnt_lgc.value) = Rte_DrvDynamicsEnable_DrvDynActive_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_DrvDynCtrl_DrvDynCtrl_Per1_Start();
  DrvDynCtrl_Per1();
  Rte_Runnable_Ap_DrvDynCtrl_DrvDynCtrl_Per1_Return();

  /* write implicit data */
  Rte_DrvDynCtrl_AssistDDFactor_Uls_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynCtrl_DrvDynCtrl_Per1.Rte_AssistDDFactor_Uls_f32.value);
  Rte_DrvDynCtrl_DampingDDFactor_Uls_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynCtrl_DrvDynCtrl_Per1.Rte_DampingDDFactor_Uls_f32.value);
  Rte_DrvDynCtrl_ReturnDDFactor_Uls_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynCtrl_DrvDynCtrl_Per1.Rte_ReturnDDFactor_Uls_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_CtrlTemp_CtrlTemp_Per1.Rte_DiagStsTempRdPrf_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsDefTemp_Cnt_lgc;
  *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_CtrlTemp_CtrlTemp_Per1.Rte_TemperatureADC_Volt_f32.value) = Rte_IoHwAb7_TemperatureADC_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start();
  CtrlTemp_Per1();
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return();

  /* write implicit data */
  Rte_CtrlTemp_FiltMeasTemp_DegC_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_CtrlTemp_CtrlTemp_Per1.Rte_FiltMeasTemp_DegC_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_Sa_BkCpPc_BkCpPc_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_Batt_Volt_f32.value) = Rte_IoHwAb7_Batt_Volt_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_BattSwitched_Volt_f32.value) = Rte_IoHwAb7_BattSwitched_Volt_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_MotorVelocityMRFUnfiltered_MtrRadpS_f32.value) = Rte_MtrVel_MRFMotorVelUnfiltered_MtrRadpS_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_OVERRIDESIGDIAGADC_Volt_f32.value) = Rte_Sa_BkCpPc_OVERRIDESIGDIAGADC_Volt_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_PMOSDIAGADC_Volt_f32.value) = Rte_Sa_BkCpPc_PMOSDIAGADC_Volt_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_PwrDiscATestStart_Cnt_lgc.value) = Rte_HwPwUp_PwrDiscATestStart_Cnt_lgc;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_PwrDiscBTestStart_Cnt_lgc.value) = Rte_HwPwUp_PwrDiscBTestStart_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start();
    BkCpPc_Per1();
    Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return();

    /* write implicit data */
    Rte_Sa_BkCpPc_PwrDiscATestComplete_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_PwrDiscATestComplete_Cnt_lgc.value);
    Rte_Sa_BkCpPc_PwrDiscBTestComplete_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_PwrDiscBTestComplete_Cnt_lgc.value);
    Rte_Sa_BkCpPc_PwrDiscClosed_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Per1.Rte_PwrDiscClosed_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_PwrLmtFunc_PwrLmtFunc_Per1 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1.Rte_CCLMSAActive_Cnt_lgc.value) = Rte_CustPL_CCLMSAActive_Cnt_lgc;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1.Rte_CustCurrLmt_Amp_f32.value) = Rte_CustPL_CustCurrLmt_Amp_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1.Rte_KeEstimate_VpRadpS_f32.value) = Rte_ParamComp_EstKe_VpRadpS_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1.Rte_MotorVelocityMRF_MtrRadpS_f32.value) = Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1.Rte_PosServEnable_Cnt_lgc.value) = Rte_ParkAssistEnable_PosServEnable_Cnt_lgc;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1.Rte_Vecu_Volt_f32.value) = Rte_BatteryVoltage_Vecu_Volt_f32;

    /* call runnable */
    Rte_Runnable_Ap_PwrLmtFunc_PwrLmtFunc_Per1_Start();
    PwrLmtFunc_Per1();
    Rte_Runnable_Ap_PwrLmtFunc_PwrLmtFunc_Per1_Return();

    /* write implicit data */
    Rte_PwrLmtFunc_AssistPowerLimit_MtrNm_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1.Rte_AssistPowerLimit_MtrNm_f32.value);
    Rte_PwrLmtFunc_MtrEnvSpd_MtrRadpS_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1.Rte_MtrEnvSpd_MtrRadpS_f32.value);
  }

  DisableAllInterrupts();
  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_MtrCurr_MtrCurr_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_ADCMtrCurr1_Volt_f32.value) = Rte_IoHwAb7_ADCMtrCurr1_Volt_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_CorrectedMtrPos_Rev_f32.value) = Rte_MtrPos2_CorrectedMtrPos_Rev_f32;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_DutyCycleSmall_Cnt_u16.value) = Rte_CDDInterface10_DutyCycleSmall_Cnt_u16;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_InstantaneousMotorDirection_Cnt_s08.value) = Rte_QuadDet_InstMtrDir_Cnt_s08;
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_PADelta1_Cnt_u16.value) = Rte_MtrCurr_PADelta1_Cnt_u16;

    /* call runnable */
    Rte_Runnable_Sa_MtrCurr_MtrCurr_Per1_Start();
    MtrCurr_Per1();
    Rte_Runnable_Sa_MtrCurr_MtrCurr_Per1_Return();

    /* write implicit data */
    Rte_MtrCurr_MtrCurrDax_Amp_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_MtrCurrDax_Amp_f32.value);
    Rte_MtrCurr_MtrCurrQax_Amp_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_MtrCurrQax_Amp_f32.value);
    Rte_MtrCurr_RawCurrFiltered_Amp_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_RawCurrFiltered_Amp_f32.value);
    Rte_MtrCurr_ValidSampleFlag_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrCurr_MtrCurr_Per1.Rte_ValidSampleFlag_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_2ms_7_Rte_Trigger1_TmprlMon_TmprlMon_Per2 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_TmprlMon_TmprlMon_Per2.Rte_TMFTestStart_Cnt_lgc.value) = Rte_HwPwUp_TMFTestStart_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start();
    TmprlMon_Per2();
    Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return();

    /* write implicit data */
    Rte_TmprlMon_TMFTestComplete_Cnt_lgc = *(&Rte_Task_2ms_7.Rte_RB.Rte_Sa_TmprlMon_TmprlMon_Per2.Rte_TMFTestComplete_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* call runnable */
  Rte_Runnable_IoHwAb7_IoHwAb7_FdbkPathAdc_Start();
  IoHwAb7_FdbkPathAdc();
  Rte_Runnable_IoHwAb7_IoHwAb7_FdbkPathAdc_Return();

  /* write implicit data */
  Rte_IoHwAb7_Batt_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FdbkPathAdc.Rte_Batt_Volt_f32.value);
  Rte_IoHwAb7_BattSwitched_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FdbkPathAdc.Rte_BattSwitched_Volt_f32.value);
  Rte_IoHwAb7_InvCos2Scaled_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FdbkPathAdc.Rte_InvCos2Scaled_Volt_f32.value);
  Rte_IoHwAb7_InvSin2Scaled_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FdbkPathAdc.Rte_InvSin2Scaled_Volt_f32.value);
  Rte_IoHwAb7_PDChrgPmpFdbkADC_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FdbkPathAdc.Rte_PDChrgPmpFdbkADC_Volt_f32.value);
  Rte_IoHwAb7_PDSuplFdbkADC_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FdbkPathAdc.Rte_PDSuplFdbkADC_Volt_f32.value);
  Rte_IoHwAb7_SysCVSwitch_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FdbkPathAdc.Rte_SysCVSwitch_Volt_f32.value);
  Rte_IoHwAb7_TemperatureADC_Volt_f32 = *(&Rte_Task_2ms_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_FdbkPathAdc.Rte_TemperatureADC_Volt_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_StaMd7_StaMd7_Per1_Start();
  StaMd7_Per1();
  Rte_Runnable_Ap_StaMd7_StaMd7_Per1_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_2msEnd_Per_Start();
  ChkPtAp7_2msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_2msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2ms_8
 * Priority: 62
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_8)
{
  Rte_Task_Dispatch(Task_2ms_8);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_2msStart_Per_Start();
  ChkPtAp8_2msStart_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_2msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_AsstAssemPol_Cnt_s08.value) = Rte_Polarity_AssistAssyPolarity_Cnt_s08;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_CumMtrPosMRF_Deg_f32.value) = Rte_MtrPos_CumMtrPosMRF_Deg_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start();
  MtrVel2_Per1();
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return();

  /* write implicit data */
  Rte_MtrVel2_SysCDiagHandWheelVel_HwRadpS_f32 = *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_SysCDiagHandWheelVel_HwRadpS_f32.value);
  Rte_MtrVel2_SysCDiagMtrVelMRF_MtrRadpS_f32 = *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_SysCDiagMtrVelMRF_MtrRadpS_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per1.Rte_HwTrqScaleVal_VoltsPerDeg_f32.value) = Rte_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per1.Rte_SysCT1ADC_Volt_f32.value) = Rte_IoHwAb7_SysCT1ADC_Volt_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per1.Rte_SysCT2ADC_Volt_f32.value) = Rte_IoHwAb7_SysCT2ADC_Volt_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per1.Rte_T1TrimVal_Volt_f32.value) = Rte_HwTrq_T1TrimVal_Volt_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per1.Rte_T2TrimVal_Volt_f32.value) = Rte_HwTrq_T2TrimVal_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start();
  HwTrq2_Per1();
  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return();

  /* write implicit data */
  Rte_HwTrq2_SysCHwTorqueSqd_HwNmSq_f32 = *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per1.Rte_SysCHwTorqueSqd_HwNmSq_f32.value);

  if (Rte_Ap_8_TriggerDisableFlags.Rte_Trigger_Task_2ms_8_Rte_Trigger1_Gsod_Gsod_Per1 == 0)
  {
    /* call runnable */
    Rte_Runnable_Ap_Gsod_Gsod_Per1_Start();
    Gsod_Per1();
    Rte_Runnable_Ap_Gsod_Gsod_Per1_Return();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_ATerm_Cnt_lgc.value) = Rte_VehPwrMd_ATermActive_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_CTerm_Cnt_lgc.value) = Rte_VehPwrMd_CTermActive_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_ControlledDampStatusComplete_Cnt_lgc.value) = Rte_CtrldDisShtdn_CtrldDmpStsCmp_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_FTerm_Cnt_lgc.value) = Rte_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_RampStatusComplete_Cnt_lgc.value) = Rte_StOpCtrl_RampDwnStatusComplete_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_TMFTestComplete_Cnt_lgc.value) = Rte_TmprlMon_TMFTestComplete_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start();
  StaMd8_Per1();
  Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrPos3_MtrPos3_Per1.Rte_InvCos2Scaled_Volt_f32.value) = Rte_IoHwAb7_InvCos2Scaled_Volt_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrPos3_MtrPos3_Per1.Rte_InvSin2Scaled_Volt_f32.value) = Rte_IoHwAb7_InvSin2Scaled_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start();
  MtrPos3_Per1();
  Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_2msEnd_Per_Start();
  ChkPtAp8_2msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_2msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_4ms_10
 * Priority: 42
 * Schedule: FULL
 * Alarm:    Cycle Time 0.004 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_4ms_10)
{
  Rte_Task_Dispatch(Task_4ms_10);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_4msStart_Per_Start();
  ChkPtAp10_4msStart_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_4msStart_Per_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start();
  uDiagLossOfExec_Per3();
  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return();

  /* read implicit data */
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per2.Rte_SysCDiagHandWheelVel_HwRadpS_f32.value) = Rte_MtrVel2_SysCDiagHandWheelVel_HwRadpS_f32;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per2.Rte_SysCDiagMtrVelMRF_MtrRadpS_f32.value) = Rte_MtrVel2_SysCDiagMtrVelMRF_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start();
  MtrVel_Per2();
  Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_4msEnd_Per_Start();
  ChkPtAp10_4msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_4msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_4ms_7
 * Priority: 45
 * Schedule: FULL
 * Alarm:    Cycle Time 0.004 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_4ms_7)
{
  Rte_Task_Dispatch(Task_4ms_7);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_4msStart_Per_Start();
  ChkPtAp7_4msStart_Per();
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_4msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_4ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per2.Rte_CntrlDisRampComplete_Cnt_lgc.value) = Rte_CtrldDisShtdn_CtrldDmpStsCmp_Cnt_lgc;
  *(&Rte_Task_4ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per2.Rte_SysCHwTorqueSqd_HwNmSq_f32.value) = Rte_HwTrq2_SysCHwTorqueSqd_HwNmSq_f32;
  *(&Rte_Task_4ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per2.Rte_T1ADC_Volt_f32.value) = Rte_IoHwAb7_T1ADC_Volt_f32;
  *(&Rte_Task_4ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per2.Rte_T2ADC_Volt_f32.value) = Rte_IoHwAb7_T2ADC_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start();
  HwTrq_Per2();
  Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return();

  DisableAllInterrupts();
  if (Rte_Ap_7_TriggerDisableFlags.Rte_Trigger_Task_4ms_7_Rte_Trigger1_BatteryVoltage_BatteryVoltage_Per2 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_4ms_7.Rte_RB.Rte_Ap_BatteryVoltage_BatteryVoltage_Per2.Rte_BattSwitched_Volt_f32.value) = Rte_IoHwAb7_BattSwitched_Volt_f32;
    *(&Rte_Task_4ms_7.Rte_RB.Rte_Ap_BatteryVoltage_BatteryVoltage_Per2.Rte_SysCVSwitch_Volt_f32.value) = Rte_IoHwAb7_SysCVSwitch_Volt_f32;

    /* call runnable */
    Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start();
    BatteryVoltage_Per2();
    Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return();
  }
  else
  {
    EnableAllInterrupts();
  }

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_4msEnd_Per_Start();
  ChkPtAp7_4msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp7_ChkPtAp7_4msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_4ms_8
 * Priority: 43
 * Schedule: FULL
 * Alarm:    Cycle Time 0.004 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_4ms_8)
{
  Rte_Task_Dispatch(Task_4ms_8);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_4msStart_Per_Start();
  ChkPtAp8_4msStart_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_4msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per2.Rte_HandWheelVel_HwRadpS_f32.value) = Rte_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per2.Rte_MRFMotorVel_MtrRadpS_f32.value) = Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start();
  MtrVel2_Per2();
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return();

  /* read implicit data */
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_LrnPnCntrCmd_MtrNm_f32.value) = Rte_LktoLkStr_LrnPnCntrCmd_MtrNm_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_LrnPnCntrEnable_Cnt_lgc.value) = Rte_CDDInterface9_LrnPnCenterEnable_Cnt_lgc;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_PASpdHigh_Cnt_u08.value) = Rte_SrlComInput2_SrlComVehNearStandstill_Cnt_u08;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_PosServEnable_Cnt_lgc.value) = Rte_ParkAssistEnable_PosServEnable_Cnt_lgc;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_PosSrvoSmoothEnable_Uls_f32.value) = Rte_PosServo_PosSrvoSmoothEnable_Uls_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_PrkAssistCmd_MtrNm_f32.value) = Rte_PosServo_PosSrvoCmd_MtrNm_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1_Start();
  PrkAstMfgServCh2_Per1();
  Rte_Runnable_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1_Return();

  /* write implicit data */
  Rte_PrkAstMfgServCh2_SysCLnPnCtrCCDisable_Cnt_lgc = *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_SysCLnPnCtrCCDisable_Cnt_lgc.value);
  Rte_PrkAstMfgServCh2_SysCPosServCCDisable_Cnt_lgc = *(&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_SysCPosServCCDisable_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per2.Rte_AnaHwTorque_HwNm_f32.value) = Rte_HwTrq_AnaHwTorque_HwNm_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per2.Rte_SysCT1ADC_Volt_f32.value) = Rte_IoHwAb7_SysCT1ADC_Volt_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per2.Rte_SysCT2ADC_Volt_f32.value) = Rte_IoHwAb7_SysCT2ADC_Volt_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per2.Rte_T1TrimVal_Volt_f32.value) = Rte_HwTrq_T1TrimVal_Volt_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_HwTrq2_HwTrq2_Per2.Rte_T2TrimVal_Volt_f32.value) = Rte_HwTrq_T2TrimVal_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start();
  HwTrq2_Per2();
  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return();

  /* read implicit data */
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_MtrPos3_MtrPos3_Per2.Rte_InvCos2Scaled_Volt_f32.value) = Rte_IoHwAb7_InvCos2Scaled_Volt_f32;
  *(&Rte_Task_4ms_8.Rte_RB.Rte_Sa_MtrPos3_MtrPos3_Per2.Rte_InvSin2Scaled_Volt_f32.value) = Rte_IoHwAb7_InvSin2Scaled_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start();
  MtrPos3_Per2();
  Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_4msEnd_Per_Start();
  ChkPtAp8_4msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_4msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_4ms_9
 * Priority: 44
 * Schedule: FULL
 * Alarm:    Cycle Time 0.004 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_4ms_9)
{
  Rte_Task_Dispatch(Task_4ms_9);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_4msStart_Per_Start();
  ChkPtAp9_4msStart_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_4msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_AlignedHwPos_HwDeg_f32.value) = Rte_AbsHwPos_AlignedHwPos_HwDeg_f32;
  *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_CRFMtrTrqCmd_MtrNm_f32.value) = Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32;
  *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LrnPnCntrEnable_Cnt_lgc.value) = Rte_CDDInterface9_LrnPnCenterEnable_Cnt_lgc;
  *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LrnPnCntrHwCenter_HwDeg_f32.value) = Rte_LktoLkStr_LrnPnCntrHwCenter_HwDeg_f32;
  *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LrnPnCntrHwTravel_HwDeg_f32.value) = Rte_LktoLkStr_LrnPnCntrHwTravel_HwDeg_f32;
  *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LrnPnCntrState_Cnt_enum.value) = Rte_LktoLkStr_LrnPnCntrState_Cnt_enum;
  *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_MtrVelCRF_MtrRadpS_f32.value) = Rte_MtrVel_CRFMotorVel_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Ap_LnRkCr_LnRkCr_Per1_Start();
  LnRkCr_Per1();
  Rte_Runnable_Ap_LnRkCr_LnRkCr_Per1_Return();

  /* write implicit data */
  Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc = *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LTRackCntrComplete_Cnt_lgc.value);
  Rte_LnRkCr_RackCenter_HwDeg_f32 = *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCenter_HwDeg_f32.value);
  Rte_LnRkCr_RackCntrComplete_Cnt_lgc = *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrComplete_Cnt_lgc.value);
  Rte_LnRkCr_RackCntrMtrAngleError_Cnt_lgc = *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrMtrAngleError_Cnt_lgc.value);
  Rte_LnRkCr_RackCntrMtrAngleFound_Cnt_lgc = *(&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrMtrAngleFound_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_4msEnd_Per_Start();
  ChkPtAp9_4msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_4msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_5ms_9
 * Priority: 40
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_5ms_9)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_5ms_9);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_5ms_9, Rte_Ev_Cyclic_Task_5ms_9_0_5ms | Rte_Ev_Run_Edch_RE_ClearErrorMem | Rte_Ev_Run_Edch_RE_InitSend | Rte_Ev_Run_Edch_RE_OperationCycleUpdated | Rte_Ev_Run_Edch_RE_SendCyclic | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AclnyCogLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_ConVehLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_FZZSTDLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_MileKMLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAclnyCog | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxConVeh | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffset | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxStCeng | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxTuningSel | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVIN | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVYawVeh | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVehSpd | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_StCengLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_TuningSelLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VINLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VYawVehLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VehSpdLoss | Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
    (void)WaitEvent(Rte_Ev_Cyclic_Task_5ms_9_0_5ms | Rte_Ev_Run_Edch_RE_ClearErrorMem | Rte_Ev_Run_Edch_RE_InitSend | Rte_Ev_Run_Edch_RE_OperationCycleUpdated | Rte_Ev_Run_Edch_RE_SendCyclic | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AclnyCogLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_ConVehLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_FZZSTDLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_MileKMLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAclnyCog | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxConVeh | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffset | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxStCeng | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxTuningSel | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVIN | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVYawVeh | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVehSpd | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_StCengLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_TuningSelLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VINLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VYawVehLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VehSpdLoss | Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
    Rte_Task_WaitEventRet(Task_5ms_9, Rte_Ev_Cyclic_Task_5ms_9_0_5ms | Rte_Ev_Run_Edch_RE_ClearErrorMem | Rte_Ev_Run_Edch_RE_InitSend | Rte_Ev_Run_Edch_RE_OperationCycleUpdated | Rte_Ev_Run_Edch_RE_SendCyclic | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AclnyCogLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_ConVehLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_FZZSTDLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_MileKMLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAclnyCog | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxConVeh | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffset | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxStCeng | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxTuningSel | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVIN | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVYawVeh | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVehSpd | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_StCengLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_TuningSelLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VINLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VYawVehLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VehSpdLoss | Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest);
    (void)GetEvent(Task_5ms_9, &ev);
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_Task_5ms_9_0_5ms | Rte_Ev_Run_Edch_RE_ClearErrorMem | Rte_Ev_Run_Edch_RE_InitSend | Rte_Ev_Run_Edch_RE_OperationCycleUpdated | Rte_Ev_Run_Edch_RE_SendCyclic | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AclnyCogLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_ConVehLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_FZZSTDLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_MileKMLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAclnyCog | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxConVeh | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffset | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxStCeng | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxTuningSel | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVIN | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVYawVeh | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVehSpd | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_StCengLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_TuningSelLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VINLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VYawVehLoss | Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VehSpdLoss | Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest));

    if ((ev & Rte_Ev_Cyclic_Task_5ms_9_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_5msStart_Per_Start();
      ChkPtAp9_5msStart_Per();
      Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_5msStart_Per_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVehSpd) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVehSpd.Rte_DiagStsDefVehSpd_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxVehSpd_Start();
      SrlComInput_TRGD_RxVehSpd();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxVehSpd_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VehSpdLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_VehSpdLoss_Start();
      SrlComInput_TRGD_VehSpdLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_VehSpdLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVIN) != (EventMaskType)0)
    {
      /* read implicit data */
      (void)Com_ReceiveSignalGroup(Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER);
      (void)Com_ReceiveShadowSignal(Com_NO_VECH_1__FAHRGESTELLNUMMER, &(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE1);
      Rte_ComHook_Com_NO_VECH_1__FAHRGESTELLNUMMER_SigRx(&(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE1);
      (void)Com_ReceiveShadowSignal(Com_NO_VECH_2__FAHRGESTELLNUMMER, &(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE2);
      Rte_ComHook_Com_NO_VECH_2__FAHRGESTELLNUMMER_SigRx(&(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE2);
      (void)Com_ReceiveShadowSignal(Com_NO_VECH_3__FAHRGESTELLNUMMER, &(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE3);
      Rte_ComHook_Com_NO_VECH_3__FAHRGESTELLNUMMER_SigRx(&(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE3);
      (void)Com_ReceiveShadowSignal(Com_NO_VECH_4__FAHRGESTELLNUMMER, &(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE4);
      Rte_ComHook_Com_NO_VECH_4__FAHRGESTELLNUMMER_SigRx(&(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE4);
      (void)Com_ReceiveShadowSignal(Com_NO_VECH_5__FAHRGESTELLNUMMER, &(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE5);
      Rte_ComHook_Com_NO_VECH_5__FAHRGESTELLNUMMER_SigRx(&(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE5);
      (void)Com_ReceiveShadowSignal(Com_NO_VECH_6__FAHRGESTELLNUMMER, &(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE6);
      Rte_ComHook_Com_NO_VECH_6__FAHRGESTELLNUMMER_SigRx(&(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE6);
      (void)Com_ReceiveShadowSignal(Com_NO_VECH_7__FAHRGESTELLNUMMER, &(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE7);
      Rte_ComHook_Com_NO_VECH_7__FAHRGESTELLNUMMER_SigRx(&(*(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)).VIN_BYTE7);
      Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.status = RTE_E_OK;
      if (Rte_Ap_9_RxTimeoutFlags.Rte_RxTimeout_SG_FAHRGESTELLNUMMER != 0)
      {
         Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.status |= RTE_E_MAX_AGE_EXCEEDED;
      }

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxVIN_Start();
      SrlComInput_TRGD_RxVIN();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxVIN_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VINLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_VINLoss_Start();
      SrlComInput_TRGD_VINLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_VINLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_MileKMLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_MileKMLoss_Start();
      SrlComInput_TRGD_MileKMLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_MileKMLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_FZZSTDLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_FZZSTDLoss_Start();
      SrlComInput_TRGD_FZZSTDLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_FZZSTDLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn.Rte_CFACTORIF_Cnt_lgc.value) = Rte_VehCfg_CFACTORIF_Cnt_lgc;
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn.Rte_CHWANGLEIF_Cnt_lgc.value) = Rte_VehCfg_CHWANGLEIF_Cnt_lgc;
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn.Rte_CHWTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CHWTORQUEIF_Cnt_lgc;
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn.Rte_CMTTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CMTTORQUEIF_Cnt_lgc;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn_Start();
      SrlComInput_TRGD_RxPaDrvDyn();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss.Rte_CHWTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CHWTORQUEIF_Cnt_lgc;
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss.Rte_CMTTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CMTTORQUEIF_Cnt_lgc;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss_Start();
      SrlComInput_TRGD_PaDrvDynLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffset) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffset.Rte_SrlComSvcDft_Cnt_b32.value) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffset_Start();
      SrlComInput_TRGD_RxRevOffset();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffset_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss_Start();
      SrlComInput_TRGD_RxRevOffsetLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffsetLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComOutput_SrlComOutput_TRGD_SVCRequest) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComOutput_SrlComOutput_TRGD_SVCRequest_Start();
      SrlComOutput_TRGD_SVCRequest();
      Rte_Runnable_Ap_SrlComOutput_SrlComOutput_TRGD_SVCRequest_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxTuningSel) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel.Rte_CDRVDYNMSG_Cnt_lgc.value) = Rte_VehCfg_CDRVDYNMSG_Cnt_lgc;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel_Start();
      SrlComInput_TRGD_RxTuningSel();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel_Return();

      /* write implicit data */
      Rte_SrlComInput_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP = *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel.Rte_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP.value);
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_TuningSelLoss) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_TuningSelLoss.Rte_CDRVDYNMSG_Cnt_lgc.value) = Rte_VehCfg_CDRVDYNMSG_Cnt_lgc;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_TuningSelLoss_Start();
      SrlComInput_TRGD_TuningSelLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_TuningSelLoss_Return();
    }

    if ((ev & Rte_Ev_Cyclic_Task_5ms_9_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per2_Start();
      SrlComOutput_Per2();
      Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per2_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs.Rte_CHWACORRECTION_Cnt_lgc.value) = Rte_VehCfg_CHWACORRECTION_Cnt_lgc;
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs.Rte_SrlComSvcDft_Cnt_b32.value) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs_Start();
      SrlComInput_TRGD_RxAvlSteaPniOffs();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs_Return();

      /* write implicit data */
      Rte_SrlComInput_ReturnOffset_HwDeg_f32 = *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs.Rte_ReturnOffset_HwDeg_f32.value);
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss.Rte_CHWACORRECTION_Cnt_lgc.value) = Rte_VehCfg_CHWACORRECTION_Cnt_lgc;
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss.Rte_SrlComSvcDft_Cnt_b32.value) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss_Start();
      SrlComInput_TRGD_AvlSteaPniOffsLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxAclnyCog) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxAclnyCog_Start();
      SrlComInput_TRGD_RxAclnyCog();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxAclnyCog_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_AclnyCogLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_AclnyCogLoss_Start();
      SrlComInput_TRGD_AclnyCogLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_AclnyCogLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxVYawVeh) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxVYawVeh_Start();
      SrlComInput_TRGD_RxVYawVeh();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxVYawVeh_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_VYawVehLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_VYawVehLoss_Start();
      SrlComInput_TRGD_VYawVehLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_VYawVehLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxConVeh) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxConVeh_Start();
      SrlComInput_TRGD_RxConVeh();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxConVeh_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_ConVehLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_ConVehLoss_Start();
      SrlComInput_TRGD_ConVehLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_ConVehLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp_Start();
      SrlComInput_TRGD_RxCtrVibStwDisp();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxCtrVibStwDisp_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss_Start();
      SrlComInput_TRGD_CtrVibStwDispLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_CtrVibStwDispLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy_Start();
      SrlComInput_TRGD_RxEnergDgrDrdy();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxEnergDgrDrdy_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss_Start();
      SrlComInput_TRGD_EnergDgrDrdyLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_EnergDgrDrdyLoss_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_RxStCeng) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxStCeng_Start();
      SrlComInput_TRGD_RxStCeng();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_RxStCeng_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput_SrlComInput_TRGD_StCengLoss) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_StCengLoss_Start();
      SrlComInput_TRGD_StCengLoss();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_TRGD_StCengLoss_Return();
    }

    if ((ev & Rte_Ev_Run_Edch_RE_InitSend) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Edch_RE_InitSend_Start();
      Edch_InitSend();
      Rte_Runnable_Edch_RE_InitSend_Return();
    }

    if ((ev & Rte_Ev_Run_Edch_RE_OperationCycleUpdated) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Edch_RE_OperationCycleUpdated_Start();
      Edch_OperationCycleUpdated();
      Rte_Runnable_Edch_RE_OperationCycleUpdated_Return();
    }

    if ((ev & Rte_Ev_Run_Edch_RE_ClearErrorMem) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Edch_RE_ClearErrorMem_Start();
      Edch_ClearErrorMem();
      Rte_Runnable_Edch_RE_ClearErrorMem_Return();
    }

    if ((ev & Rte_Ev_Cyclic_Task_5ms_9_0_5ms) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcActivePN_Cnt_u32.value) = Rte_TurnsCounter_TcActivePN_Cnt_u32;
      *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcActivePNVldCnt_Cnt_u32.value) = Rte_TurnsCounter_TcActivePNVldCnt_Cnt_u32;

      /* call runnable */
      Rte_Runnable_Sa_CDDInterface9_CDDInterface9_Per1_Start();
      CDDInterface9_Per1();
      Rte_Runnable_Sa_CDDInterface9_CDDInterface9_Per1_Return();

      /* write implicit data */
      Rte_CDDInterface9_ActPullCompLrnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ActPullCompLrnSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_AvgFrcLrnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_AvgFrcLrnSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_DampingSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DampingSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_DftAsstTbl_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DftAsstTbl_Cnt_lgc.value);
      Rte_CDDInterface9_DrivingDynSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_DwnldAsstGain_Uls_f32 = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DwnldAsstGain_Uls_f32.value);
      Rte_CDDInterface9_EOTImpactSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_EOTThermalSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_EngONSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EngONSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_FirewallSrlComSrvDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_FirewallSrlComSrvDft_Cnt_lgc.value);
      Rte_CDDInterface9_FreqDepDmpSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_HysAddSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_HysAddSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_HystCompSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_HystCompSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_IgnCnt_Cnt_u16 = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_IgnCnt_Cnt_u16.value);
      Rte_CDDInterface9_KinIntDiagSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_KinIntDiagSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_LimitSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_LimitSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_LrnPnCenterEnable_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_LrnPnCenterEnable_Cnt_lgc.value);
      Rte_CDDInterface9_MfgDiagInhibit_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MfgDiagInhibit_Cnt_lgc.value);
      Rte_CDDInterface9_ModIdxSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_MultIgnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_NxtrMEC_Cnt_enum = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_NxtrMEC_Cnt_enum.value);
      Rte_CDDInterface9_OscTrajEnable_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_OscTrajEnable_Cnt_lgc.value);
      Rte_CDDInterface9_ParkAstSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_PosTrajEnable_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_PosTrajEnable_Cnt_lgc.value);
      Rte_CDDInterface9_PullCompSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_PullCompSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_ReturnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ReturnSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_RxMsgsSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_SrlComSvcDft_Cnt_b32 = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_SrlComSvcDft_Cnt_b32.value);
      Rte_CDDInterface9_TcFlashErrors_Cnt_u08 = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcFlashErrors_Cnt_u08.value);
      Rte_CDDInterface9_TcFlashVerify_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcFlashVerify_Cnt_lgc.value);
      Rte_CDDInterface9_TcReflashActive_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcReflashActive_Cnt_lgc.value);
      Rte_CDDInterface9_ThermalDCSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_TrqRmpSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value);
      Rte_CDDInterface9_WhlImbRejSrlComSvcDft_Cnt_lgc = *(&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_WhlImbRejSrlComSvcDft_Cnt_lgc.value);
    }

    if ((ev & Rte_Ev_Run_Edch_RE_SendCyclic) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Edch_RE_SendCyclic_Start();
      Edch_SendCyclic();
      Rte_Runnable_Edch_RE_SendCyclic_Return();
    }

    if ((ev & Rte_Ev_Cyclic_Task_5ms_9_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_5msEnd_Per_Start();
      ChkPtAp9_5msEnd_Per();
      Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_5msEnd_Per_Return();
    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_InitA_10
 * Priority: 86
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_InitA_10)
{
  Rte_Task_Dispatch(Task_InitA_10);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start();
  DiagMgr10_Init();
  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_StaMd_StaMd_Init1_Start();
  StaMd_Init1();
  Rte_Runnable_Ap_StaMd_StaMd_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_Polarity_Polarity_Init1_Start();
  Polarity_Init1();
  Rte_Runnable_Ap_Polarity_Polarity_Init1_Return();

  /* write implicit data */
  Rte_Polarity_AssistAssyPolarity_Cnt_s08 = *(&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_AssistAssyPolarity_Cnt_s08.value);
  Rte_Polarity_HwPosPolarity_Cnt_s08 = *(&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_HwPosPolarity_Cnt_s08.value);
  Rte_Polarity_HwTrqPolarity_Cnt_s08 = *(&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_HwTrqPolarity_Cnt_s08.value);
  Rte_Polarity_MtrElecMechPolarity_Cnt_s08 = *(&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrElecMechPolarity_Cnt_s08.value);
  Rte_Polarity_MtrPosPolarity_Cnt_s08 = *(&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrPosPolarity_Cnt_s08.value);
  Rte_Polarity_MtrVelPolarity_Cnt_s08 = *(&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrVelPolarity_Cnt_s08.value);
  Rte_Polarity_SysC_MtrElecMechPolarity_Cnt_s32 = *(&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_SysC_MtrElecMechPolarity_Cnt_s32.value);

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_InitA_7
 * Priority: 87
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_InitA_7)
{
  Rte_Task_Dispatch(Task_InitA_7);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr7_DiagMgr7_Init_Start();
  DiagMgr7_Init();
  Rte_Runnable_Ap_DiagMgr7_DiagMgr7_Init_Return();

  /* read implicit data */
  *(&Rte_Task_InitA_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Init1.Rte_DesiredTunPers_Cnt_u16.value) = Rte_VehCfg_DesiredTunPers_Cnt_u16;
  *(&Rte_Task_InitA_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Init1.Rte_DesiredTunSet_Cnt_u16.value) = Rte_VehCfg_DesiredTunSet_Cnt_u16;

  /* call runnable */
  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start();
  TuningSelAuth_Init1();
  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return();

  /* write implicit data */
  Rte_TuningSelAuth_ActiveTunPers_Cnt_u16 = *(&Rte_Task_InitA_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Init1.Rte_ActiveTunPers_Cnt_u16.value);
  Rte_TuningSelAuth_ActiveTunSet_Cnt_u16 = *(&Rte_Task_InitA_7.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Init1.Rte_ActiveTunSet_Cnt_u16.value);

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_InitA_9
 * Priority: 88
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_InitA_9)
{
  Rte_Task_Dispatch(Task_InitA_9);

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface9_CDDInterface9_Init2_Start();
  CDDInterface9_Init2();
  Rte_Runnable_Sa_CDDInterface9_CDDInterface9_Init2_Return();

  /* write implicit data */
  Rte_CDDInterface9_IgnCnt_Cnt_u16 = *(&Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_IgnCnt_Cnt_u16.value);
  Rte_CDDInterface9_MfgDiagInhibit_Cnt_lgc = *(&Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_MfgDiagInhibit_Cnt_lgc.value);
  Rte_CDDInterface9_NxtrMEC_Cnt_enum = *(&Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_NxtrMEC_Cnt_enum.value);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start();
  DiagMgr9_Init();
  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return();

  /* call runnable */
  Rte_Runnable_Coding_Coding_Init_Start();
  Coding_Init();
  Rte_Runnable_Coding_Coding_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_VehCfg_VehCfg_Init1_Start();
  VehCfg_Init1();
  Rte_Runnable_Ap_VehCfg_VehCfg_Init1_Return();

  /* write implicit data */
  Rte_VehCfg_DesiredTunPers_Cnt_u16 = *(&Rte_Task_InitA_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Init1.Rte_DesiredTunPers_Cnt_u16.value);
  Rte_VehCfg_DesiredTunSet_Cnt_u16 = *(&Rte_Task_InitA_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Init1.Rte_DesiredTunSet_Cnt_u16.value);

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_InitB_10
 * Priority: 82
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_InitB_10)
{
  Rte_Task_Dispatch(Task_InitB_10);

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start();
  uDiagResetHandler_Init();
  Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagPeriphStartup_Init_Start();
  uDiagPeriphStartup_Init();
  Rte_Runnable_Cd_uDiag_uDiagPeriphStartup_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start();
  DampingFirewall_Init1();
  Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return();

  /* call runnable */
  Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start();
  MtrPos_Init1();
  Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return();

  /* call runnable */
  Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start();
  MtrVel3_Init();
  Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return();

  /* call runnable */
  Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start();
  MtrVel_Init1();
  Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Init1_Start();
  AbsHwPos_Init1();
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Init1_Return();

  /* write implicit data */
  Rte_AbsHwPos_LTVehCenterComplete_Cnt_lgc = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_LTVehCenterComplete_Cnt_lgc.value);
  Rte_AbsHwPos_RacktoVehCntrOffset_Cnt_u16 = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_RacktoVehCntrOffset_Cnt_u16.value);

  /* call runnable */
  Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start();
  AssistFirewall_Init1();
  Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start();
  StabilityComp_Init1();
  Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Init1_Start();
  VltgCtrl_Init1();
  Rte_Runnable_Ap_VltgCtrl_VltgCtrl_Init1_Return();

  /* read implicit data */
  *(&Rte_Task_InitB_10.Rte_RB.Rte_Sa_CDDInterface10_CDDInterface10_Init1.Rte_MtrElecMechPolarity_Cnt_s08.value) = Rte_Polarity_MtrElecMechPolarity_Cnt_s08;

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface10_CDDInterface10_Init1_Start();
  CDDInterface10_Init1();
  Rte_Runnable_Sa_CDDInterface10_CDDInterface10_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_ParamComp_ParamComp_Init1_Start();
  ParamComp_Init1();
  Rte_Runnable_Ap_ParamComp_ParamComp_Init1_Return();

  /* write implicit data */
  Rte_ParamComp_EstKe_VpRadpS_f32 = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstKe_VpRadpS_f32.value);
  Rte_ParamComp_EstLd_Henry_f32 = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstLd_Henry_f32.value);
  Rte_ParamComp_EstLq_Henry_f32 = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstLq_Henry_f32.value);
  Rte_ParamComp_EstR_Ohm_f32 = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstR_Ohm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start();
  LrnEOT_Init1();
  Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return();

  /* write implicit data */
  Rte_LrnEOT_CCWFound_Cnt_lgc = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Init1.Rte_CCWFound_Cnt_lgc.value);
  Rte_LrnEOT_CCWPosition_HwDeg_f32 = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Init1.Rte_CCWPosition_HwDeg_f32.value);
  Rte_LrnEOT_CWFound_Cnt_lgc = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Init1.Rte_CWFound_Cnt_lgc.value);
  Rte_LrnEOT_CWPosition_HwDeg_f32 = *(&Rte_Task_InitB_10.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Init1.Rte_CWPosition_HwDeg_f32.value);

  /* call runnable */
  Rte_Runnable_Sa_PhaseDscnt_PhaseDscnt_Init1_Start();
  PhaseDscnt_Init1();
  Rte_Runnable_Sa_PhaseDscnt_PhaseDscnt_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_SrlComInput2_SrlComInput2_Init_Start();
  SrlComInput2_Init();
  Rte_Runnable_Ap_SrlComInput2_SrlComInput2_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_SrlComOutput2_SrlComOutput2_Init1_Start();
  SrlComOutput2_Init1();
  Rte_Runnable_Ap_SrlComOutput2_SrlComOutput2_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Init1_Start();
  BmwTqOvrlCdng_Init1();
  Rte_Runnable_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_AssistSumnLmt_AssistSumnLmt_Init1_Start();
  AssistSumnLmt_Init1();
  Rte_Runnable_Ap_AssistSumnLmt_AssistSumnLmt_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_Nhet2_Nhet2_Init1_Start();
  Nhet2_Init1();
  Rte_Runnable_Ap_Nhet2_Nhet2_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_TrqOsc_TrqOsc_Init_Start();
  TrqOsc_Init();
  Rte_Runnable_Ap_TrqOsc_TrqOsc_Init_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_InitB_7
 * Priority: 85
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_InitB_7)
{
  Rte_Task_Dispatch(Task_InitB_7);

  /* call runnable */
  Rte_Runnable_IoHwAb7_IoHwAb7_Init_Start();
  IoHwAb7_Init();
  Rte_Runnable_IoHwAb7_IoHwAb7_Init_Return();

  /* write implicit data */
  Rte_IoHwAb7_ADCMtrCurr1_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_ADCMtrCurr1_Volt_f32.value);
  Rte_IoHwAb7_Batt_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_Batt_Volt_f32.value);
  Rte_IoHwAb7_BattSwitched_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_BattSwitched_Volt_f32.value);
  Rte_IoHwAb7_InvCos2Scaled_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_InvCos2Scaled_Volt_f32.value);
  Rte_IoHwAb7_InvSin2Scaled_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_InvSin2Scaled_Volt_f32.value);
  Rte_IoHwAb7_PDChrgPmpFdbkADC_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_PDChrgPmpFdbkADC_Volt_f32.value);
  Rte_IoHwAb7_PDSuplFdbkADC_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_PDSuplFdbkADC_Volt_f32.value);
  Rte_IoHwAb7_SysCT1ADC_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_SysCT1ADC_Volt_f32.value);
  Rte_IoHwAb7_SysCT2ADC_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_SysCT2ADC_Volt_f32.value);
  Rte_IoHwAb7_SysCVSwitch_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_SysCVSwitch_Volt_f32.value);
  Rte_IoHwAb7_T1ADC_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_T1ADC_Volt_f32.value);
  Rte_IoHwAb7_T2ADC_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_IoHwAb7_IoHwAb7_Init.Rte_T2ADC_Volt_f32.value);
  Rte_IoHwAb7_TemperatureADC_Volt_f32 = *(&Rte_Task_InitB_7.Rte_TB.Rte_I_IoHwAb7_TemperatureADC_Volt_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_LktoLkStr_Ap_LktoLkStr_Init_Start();
  Ap_LktoLkStr_Init();
  Rte_Runnable_Ap_LktoLkStr_Ap_LktoLkStr_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_PosServo_PosServo_Init1_Start();
  PosServo_Init1();
  Rte_Runnable_Ap_PosServo_PosServo_Init1_Return();

  /* call runnable */
  Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start();
  HwTrq_Init();
  Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return();

  /* write implicit data */
  Rte_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_HwTrqScaleVal_VoltsPerDeg_f32.value);
  Rte_HwTrq_T1TrimVal_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_T1TrimVal_Volt_f32.value);
  Rte_HwTrq_T2TrimVal_Volt_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_T2TrimVal_Volt_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_Sweep_Sweep_Init_Start();
  Sweep_Init();
  Rte_Runnable_Ap_Sweep_Sweep_Init_Return();

  /* call runnable */
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start();
  CtrlTemp_Init1();
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return();

  /* write implicit data */
  Rte_CtrlTemp_FiltMeasTemp_DegC_f32 = *(&Rte_Task_InitB_7.Rte_TB.Rte_I_CtrlTemp_FiltMeasTemp_DegC_f32.value);

  /* call runnable */
  Rte_Runnable_Sa_MtrCurr_MtrCurr_Init1_Start();
  MtrCurr_Init1();
  Rte_Runnable_Sa_MtrCurr_MtrCurr_Init1_Return();

  /* read implicit data */
  *(&Rte_Task_InitB_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Init1.Rte_EnergyModeState_Cnt_enum.value) = Rte_VehCfg_EnergyModeState_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Cd_TurnsCounter_TurnsCounter_Init1_Start();
  TurnsCounter_Init1();
  Rte_Runnable_Cd_TurnsCounter_TurnsCounter_Init1_Return();

  /* write implicit data */
  Rte_TurnsCounter_TcActivePN_Cnt_u32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Init1.Rte_TcActivePN_Cnt_u32.value);
  Rte_TurnsCounter_TcActivePNVldCnt_Cnt_u32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Init1.Rte_TcActivePNVldCnt_Cnt_u32.value);

  /* read implicit data */
  *(&Rte_Task_InitB_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_AmbTemp_DegC_f32.value) = Rte_MtrTempEst_AmbTemp_DegC_f32;
  *(&Rte_Task_InitB_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_EngTemp_DegC_f32.value) = Rte_MtrTempEst_EngTemp_DegC_f32;

  /* call runnable */
  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start();
  MtrTempEst_Init1();
  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return();

  /* write implicit data */
  Rte_MtrTempEst_AssistMechTempEst_DegC_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_AssistMechTempEst_DegC_f32.value);
  Rte_MtrTempEst_CuTempEst_DegC_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_CuTempEst_DegC_f32.value);
  Rte_MtrTempEst_MagTempEst_DegC_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_MagTempEst_DegC_f32.value);
  Rte_MtrTempEst_SiTempEst_DegC_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_SiTempEst_DegC_f32.value);

  /* call runnable */
  Rte_Runnable_SpiNxt_SpiNxt_Init_Start();
  SpiNxt_Init();
  Rte_Runnable_SpiNxt_SpiNxt_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_PwrLmtFunc_PwrLmtFunc_Init_Start();
  PwrLmtFunc_Init();
  Rte_Runnable_Ap_PwrLmtFunc_PwrLmtFunc_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_CustPL_CustPL_Init1_Start();
  CustPL_Init1();
  Rte_Runnable_Ap_CustPL_CustPL_Init1_Return();

  /* write implicit data */
  Rte_CustPL_CCLMSAActive_Cnt_lgc = *(&Rte_Task_InitB_7.Rte_RB.Rte_Ap_CustPL_CustPL_Init1.Rte_CCLMSAActive_Cnt_lgc.value);
  Rte_CustPL_CCLTrqRamp_Uls_f32 = *(&Rte_Task_InitB_7.Rte_RB.Rte_Ap_CustPL_CustPL_Init1.Rte_CCLTrqRamp_Uls_f32.value);

  /* call runnable */
  Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start();
  MtrPos2_Init1();
  Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_SignlCondn_SignlCondn_Init1_Start();
  SignlCondn_Init1();
  Rte_Runnable_Ap_SignlCondn_SignlCondn_Init1_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_InitB_9
 * Priority: 80
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_InitB_9)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_InitB_9);

  /* call runnable */
  Rte_Runnable_Sa_PrimaryShutdown_PrimShtdn_Init_Start();
  PrimShtdn_Init();
  Rte_Runnable_Sa_PrimaryShutdown_PrimShtdn_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start();
  VehPwrMd_Init1();
  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return();

  /* write implicit data */
  Rte_VehPwrMd_MSACommand_MSACmd_enum = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_MSACommand_MSACmd_enum.value);
  Rte_VehPwrMd_OperRampRate_XpmS_f32 = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_OperRampRate_XpmS_f32.value);
  Rte_VehPwrMd_OperRampValue_Uls_f32 = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_OperRampValue_Uls_f32.value);

  /* read implicit data */
  *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1.Rte_DefeatDutySvc_Cnt_lgc.value) = Rte_CDDInterface9_ThermalDCSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1.Rte_IgnTimeOff_Cnt_u32.value) = Rte_SrlComInput_IgnTimeOff_Cnt_u32;
  *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1.Rte_VehTimeValid_Cnt_lgc.value) = Rte_SrlComInput_VehTimeValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start();
  ThrmlDutyCycle_Init1();
  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_SrlScomSrvc_SrlScomSrvc_Init_Start();
  SrlScomSrvc_Init();
  Rte_Runnable_Ap_SrlScomSrvc_SrlScomSrvc_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start();
  SrlComInput_Init();
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return();

  /* write implicit data */
  Rte_SrlComInput_IgnTimeOff_Cnt_u32 = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_IgnTimeOff_Cnt_u32.value);
  Rte_SrlComInput_SrlComSTKL_ST_KL = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_SrlComSTKL_ST_KL.value);
  Rte_SrlComInput_VehTimeValid_Cnt_lgc = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_VehTimeValid_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface9_CDDInterface9_Init1_Start();
  CDDInterface9_Init1();
  Rte_Runnable_Sa_CDDInterface9_CDDInterface9_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_RackLoad_RackLoad_Init1_Start();
  RackLoad_Init1();
  Rte_Runnable_Ap_RackLoad_RackLoad_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_HystComp_HystComp_Init1_Start();
  HystComp_Init1();
  Rte_Runnable_Ap_HystComp_HystComp_Init1_Return();

  /* read implicit data */
  *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_AlignedHwPos_HwDeg_f32.value) = Rte_AbsHwPos_AlignedHwPos_HwDeg_f32;

  /* call runnable */
  Rte_Runnable_Ap_LnRkCr_LnRkCr_Init1_Start();
  LnRkCr_Init1();
  Rte_Runnable_Ap_LnRkCr_LnRkCr_Init1_Return();

  /* write implicit data */
  Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_LTRackCntrComplete_Cnt_lgc.value);
  Rte_LnRkCr_RackCenter_HwDeg_f32 = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCenter_HwDeg_f32.value);
  Rte_LnRkCr_RackCntrComplete_Cnt_lgc = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrComplete_Cnt_lgc.value);
  Rte_LnRkCr_RackCntrMtrAngleError_Cnt_lgc = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrMtrAngleError_Cnt_lgc.value);
  Rte_LnRkCr_RackCntrMtrAngleFound_Cnt_lgc = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrMtrAngleFound_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start();
  FrqDepDmpnInrtCmp_Init();
  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start();
  StabilityComp2_Init1();
  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_TJADamp_TJADamp_Init_Start();
  TJADamp_Init();
  Rte_Runnable_Ap_TJADamp_TJADamp_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_Damping_Damping_Init1_Start();
  Damping_Init1();
  Rte_Runnable_Ap_Damping_Damping_Init1_Return();

  /* call runnable */
  Rte_Runnable_Edch_RE_Init_Start();
  Edch_Init();
  Rte_Runnable_Edch_RE_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start();
  AvgFricLrn_Init1();
  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return();

  /* write implicit data */
  Rte_AvgFricLrn_FricOffset_HwNm_f32 = *(&Rte_Task_InitB_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Init1.Rte_FricOffset_HwNm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start();
  ActivePull_Init1();
  Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_BmwHaptcFb_BmwHaptcFb_Init1_Start();
  BmwHaptcFb_Init1();
  Rte_Runnable_Ap_BmwHaptcFb_BmwHaptcFb_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_BmwRtnArbn_BmwRtnArbn_Init1_Start();
  BmwRtnArbn_Init1();
  Rte_Runnable_Ap_BmwRtnArbn_BmwRtnArbn_Init1_Return();

  for(;;)
  {
    Rte_Task_WaitEvent(Task_InitB_9, Rte_Ev_Run_SrlComOutput_SrlComOutput_Init1);
    (void)WaitEvent(Rte_Ev_Run_SrlComOutput_SrlComOutput_Init1);
    Rte_Task_WaitEventRet(Task_InitB_9, Rte_Ev_Run_SrlComOutput_SrlComOutput_Init1);
    (void)GetEvent(Task_InitB_9, &ev);
    (void)ClearEvent(ev & (Rte_Ev_Run_SrlComOutput_SrlComOutput_Init1));

    if ((ev & Rte_Ev_Run_SrlComOutput_SrlComOutput_Init1) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start();
      SrlComOutput_Init1();
      Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return();
    }

    if (((ev & Rte_Ev_Run_SrlComOutput_SrlComOutput_Init1) != (EventMaskType)0))
    {
      Rte_ModeType_EcuM_Mode nextMode;
      boolean doAnotherSwitch = FALSE;

      Rte_Assert((Rte_ModeMachine_EcuM_currentMode_currentMode == RTE_TRANSITION_EcuM_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();

      Rte_ModeMachine_EcuM_currentMode_currentMode = Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueue[Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr];
      if (Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr < (2-1))
      {
        Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr++;
      }
      else
      {
        Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr = 0;
      }

      if (Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr != Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr)
      {
        doAnotherSwitch = TRUE;
        Rte_ModeMachine_EcuM_currentMode_currentMode = RTE_TRANSITION_EcuM_Mode;
      }

      Rte_Ap_9_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack = 1;

      EnableAllInterrupts();



      while (doAnotherSwitch == TRUE)
      {
        EventMaskType ModeSwitchEventMask;

        nextMode = Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueue[Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr];
        ModeSwitchEventMask = Rte_ModeEntryEventMask_EcuM_currentMode_currentMode[nextMode];

        if ((ModeSwitchEventMask) != (EventMaskType)0)
        {
          DisableAllInterrupts();

          Rte_ModeMachine_EcuM_currentMode_currentMode = RTE_TRANSITION_EcuM_Mode;

          EnableAllInterrupts();

          Rte_Task_SetEvent(Task_InitB_9, ModeSwitchEventMask);
          (void)SetEvent(Task_InitB_9, ModeSwitchEventMask);
          break;
        }
        else
        {
          DisableAllInterrupts();

          Rte_ModeMachine_EcuM_currentMode_currentMode = nextMode;
          if (Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr < (2-1))
          {
            Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr++;
          }
          else
          {
            Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr = 0;
          }
          Rte_Ap_9_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack = 1;
          if (Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueWriteCtr != Rte_ModeInfo_EcuM_currentMode_currentMode.Rte_ModeQueueReadCtr)
          {
            doAnotherSwitch = TRUE;
            Rte_ModeMachine_EcuM_currentMode_currentMode = RTE_TRANSITION_EcuM_Mode;
          }
          else
          {
            doAnotherSwitch = FALSE;
          }

          EnableAllInterrupts();
        }
      }
    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_Init_11
 * Priority: 83
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Init_11)
{
  Rte_Task_Dispatch(Task_Init_11);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr11_DiagMgr11_Init_Start();
  DiagMgr11_Init();
  Rte_Runnable_Ap_DiagMgr11_DiagMgr11_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start();
  DigPhsReasDiag_Init();
  Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_Init_8
 * Priority: 84
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Init_8)
{
  Rte_Task_Dispatch(Task_Init_8);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start();
  DiagMgr8_Init();
  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return();

  /* call runnable */
  Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start();
  HwTrq2_Init1();
  Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return();

  /* read implicit data */
  *(&Rte_Task_Init_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Init.Rte_CumMtrPosMRF_Deg_f32.value) = Rte_MtrPos_CumMtrPosMRF_Deg_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start();
  MtrVel2_Init();
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Init_Start();
  PrkAstMfgServCh2_Init();
  Rte_Runnable_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Init_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_Trgd_10
 * Priority: 41
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trgd_10)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trgd_10);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxConVeh | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxRevOffset | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxStCeng | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVehSpd | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
    (void)WaitEvent(Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxConVeh | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxRevOffset | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxStCeng | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVehSpd | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
    Rte_Task_WaitEventRet(Task_Trgd_10, Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxConVeh | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxRevOffset | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxStCeng | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVehSpd | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate);
    (void)GetEvent(Task_Trgd_10, &ev);
    (void)ClearEvent(ev & (Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxConVeh | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxRevOffset | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxStCeng | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVehSpd | Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate));

    if ((ev & Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVehSpd) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxVehSpd.Rte_DiagStsDefVehSpd_Cnt_lgc.value) = Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxVehSpd_Start();
      SrlComInput2_TRGD_RxVehSpd();
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxVehSpd_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CADASIF_Cnt_lgc.value) = Rte_VehCfg_CADASIF_Cnt_lgc;
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CFACTORIF_Cnt_lgc.value) = Rte_VehCfg_CFACTORIF_Cnt_lgc;
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CHWANGLEIF_Cnt_lgc.value) = Rte_VehCfg_CHWANGLEIF_Cnt_lgc;
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CHWTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CHWTORQUEIF_Cnt_lgc;
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CMTTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CMTTORQUEIF_Cnt_lgc;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn_Start();
      SrlComInput2_TRGD_RxPaDrvDyn();
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxRevOffset) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxRevOffset.Rte_SrlComSvcDft_Cnt_b32.value) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxRevOffset_Start();
      SrlComInput2_TRGD_RxRevOffset();
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxRevOffset_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate.Rte_CFACTORIF_Cnt_lgc.value) = Rte_VehCfg_CFACTORIF_Cnt_lgc;
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate.Rte_CHWANGLEIF_Cnt_lgc.value) = Rte_VehCfg_CHWANGLEIF_Cnt_lgc;
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate.Rte_CHWTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CHWTORQUEIF_Cnt_lgc;
      *(&Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate.Rte_CMTTORQUEIF_Cnt_lgc.value) = Rte_VehCfg_CMTTORQUEIF_Cnt_lgc;

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate_Start();
      SrlComInput2_TRGD_VehCfgUpdate();
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr_Start();
      SrlComInput2_TRGD_RxAclnyMassCntr();
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxAclnyMassCntr_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxConVeh) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxConVeh_Start();
      SrlComInput2_TRGD_RxConVeh();
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxConVeh_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh_Start();
      SrlComInput2_TRGD_RxVYawVeh();
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxVYawVeh_Return();
    }

    if ((ev & Rte_Ev_Run_SrlComInput2_SrlComInput2_TRGD_RxStCeng) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxStCeng_Start();
      SrlComInput2_TRGD_RxStCeng();
      Rte_Runnable_Ap_SrlComInput2_SrlComInput2_TRGD_RxStCeng_Return();
    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_TrnsB_9
 * Priority: 10
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_TrnsB_9)
{
  Rte_Task_Dispatch(Task_TrnsB_9);

  /* call runnable */
  Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start();
  StaMd9_Trns_DemShutdown();
  Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_Trns_10
 * Priority: 8
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trns_10)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trns_10);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trns_10, Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OFF | Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OPERATE | Rte_Ev_Run_DiagMgr10_DiagMgr10_Trns | Rte_Ev_Run_Nhet2_Nhet2_Trns2 | Rte_Ev_Run_RteErrata10_RteErrata10_Trns | Rte_Ev_MS_Task_Trns_10);
    (void)WaitEvent(Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OFF | Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OPERATE | Rte_Ev_Run_DiagMgr10_DiagMgr10_Trns | Rte_Ev_Run_Nhet2_Nhet2_Trns2 | Rte_Ev_Run_RteErrata10_RteErrata10_Trns | Rte_Ev_MS_Task_Trns_10);
    Rte_Task_WaitEventRet(Task_Trns_10, Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OFF | Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OPERATE | Rte_Ev_Run_DiagMgr10_DiagMgr10_Trns | Rte_Ev_Run_Nhet2_Nhet2_Trns2 | Rte_Ev_Run_RteErrata10_RteErrata10_Trns | Rte_Ev_MS_Task_Trns_10);
    (void)GetEvent(Task_Trns_10, &ev);
    (void)ClearEvent(ev & (Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OFF | Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OPERATE | Rte_Ev_Run_DiagMgr10_DiagMgr10_Trns | Rte_Ev_Run_Nhet2_Nhet2_Trns2 | Rte_Ev_Run_RteErrata10_RteErrata10_Trns | Rte_Ev_MS_Task_Trns_10));

    if ((ev & Rte_Ev_Run_DiagMgr10_DiagMgr10_Trns) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start();
      DiagMgr10_Trns();
      Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return();
    }

    if ((ev & Rte_Ev_Run_Nhet2_Nhet2_Trns2) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_Nhet2_Nhet2_Trns2_Start();
      Nhet2_Trns2();
      Rte_Runnable_Ap_Nhet2_Nhet2_Trns2_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OFF) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start();
      StaMd_Trns1();
      Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_DISABLE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_SrlComOutput2_SrlComOutput2_Trns1_Start();
      SrlComOutput2_Trns1();
      Rte_Runnable_Ap_SrlComOutput2_SrlComOutput2_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OPERATE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_Nhet2_Nhet2_Trns1_Start();
      Nhet2_Trns1();
      Rte_Runnable_Ap_Nhet2_Nhet2_Trns1_Return();
    }

    if (((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_Run_RteErrata10_RteErrata10_Trns) != (EventMaskType)0))
    {
      /* call runnable */
      Rte_Runnable_RteErrata10_RteErrata10_Trns_Start();
      RteErrata10_Trns();
      Rte_Runnable_RteErrata10_RteErrata10_Trns_Return();
    }

    if (((ev & Rte_Ev_Run_DiagMgr10_DiagMgr10_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_Run_Nhet2_Nhet2_Trns2) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_10_StaMd_SystemState_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_Run_RteErrata10_RteErrata10_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_MS_Task_Trns_10) != (EventMaskType)0))
    {
      Rte_ModeType_StaMd_Mode previousMode;
      Rte_ModeType_StaMd_Mode nextMode;

      Rte_Assert((Rte_ModeMachine_StaMd_SystemState_Mode == RTE_TRANSITION_StaMd_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();
      previousMode = Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[1];
      nextMode = Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[0];

      if (previousMode != nextMode)
      {
        Rte_DecDisableFlags_StaMd_SystemState_Mode(previousMode);
      }

      Rte_ModeMachine_StaMd_SystemState_Mode = Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[0];

      EnableAllInterrupts();


    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_Trns_11
 * Priority: 7
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trns_11)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trns_11);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trns_11, Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_WARMINIT | Rte_Ev_Run_DiagMgr11_DiagMgr11_Trns | Rte_Ev_Run_RteErrata11_RteErrata11_Trns | Rte_Ev_MS_Task_Trns_11);
    (void)WaitEvent(Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_WARMINIT | Rte_Ev_Run_DiagMgr11_DiagMgr11_Trns | Rte_Ev_Run_RteErrata11_RteErrata11_Trns | Rte_Ev_MS_Task_Trns_11);
    Rte_Task_WaitEventRet(Task_Trns_11, Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_WARMINIT | Rte_Ev_Run_DiagMgr11_DiagMgr11_Trns | Rte_Ev_Run_RteErrata11_RteErrata11_Trns | Rte_Ev_MS_Task_Trns_11);
    (void)GetEvent(Task_Trns_11, &ev);
    (void)ClearEvent(ev & (Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_WARMINIT | Rte_Ev_Run_DiagMgr11_DiagMgr11_Trns | Rte_Ev_Run_RteErrata11_RteErrata11_Trns | Rte_Ev_MS_Task_Trns_11));

    if ((ev & Rte_Ev_Run_DiagMgr11_DiagMgr11_Trns) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DiagMgr11_DiagMgr11_Trns_Start();
      DiagMgr11_Trns();
      Rte_Runnable_Ap_DiagMgr11_DiagMgr11_Trns_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_OPERATE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start();
      DigPhsReasDiag_Trans1();
      Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_WARMINIT) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start();
      MtrDrvDiag_Trns1();
      Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return();

      /* write implicit data */
      Rte_MtrDrvDiag_MtrDrvrInitComplete_Cnt_lgc = *(&Rte_Task_Trns_11.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Trns1.Rte_MtrDrvrInitComplete_Cnt_lgc.value);
    }

    if (((ev & Rte_Ev_Run_RteErrata11_RteErrata11_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_WARMINIT) != (EventMaskType)0))
    {
      /* call runnable */
      Rte_Runnable_RteErrata11_RteErrata11_Trns_Start();
      RteErrata11_Trns();
      Rte_Runnable_RteErrata11_RteErrata11_Trns_Return();
    }

    if (((ev & Rte_Ev_Run_DiagMgr11_DiagMgr11_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_11_StaMd11_SystemState11_Mode_WARMINIT) != (EventMaskType)0) || ((ev & Rte_Ev_Run_RteErrata11_RteErrata11_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_MS_Task_Trns_11) != (EventMaskType)0))
    {
      Rte_ModeType_StaMd_Mode previousMode;
      Rte_ModeType_StaMd_Mode nextMode;

      Rte_Assert((Rte_ModeMachine_StaMd11_SystemState11_Mode == RTE_TRANSITION_StaMd_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();
      previousMode = Rte_ModeInfo_StaMd11_SystemState11_Mode.Rte_ModeQueue[1];
      nextMode = Rte_ModeInfo_StaMd11_SystemState11_Mode.Rte_ModeQueue[0];

      if (previousMode != nextMode)
      {
        Rte_DecDisableFlags_StaMd11_SystemState11_Mode(previousMode);
      }

      Rte_ModeMachine_StaMd11_SystemState11_Mode = Rte_ModeInfo_StaMd11_SystemState11_Mode.Rte_ModeQueue[0];

      EnableAllInterrupts();


    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_Trns_7
 * Priority: 6
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trns_7)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trns_7);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trns_7, Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_WARMINIT | Rte_Ev_Run_DiagMgr7_DiagMgr7_Trns | Rte_Ev_Run_RteErrata7_RteErrata7_Trns | Rte_Ev_MS_Task_Trns_7);
    (void)WaitEvent(Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_WARMINIT | Rte_Ev_Run_DiagMgr7_DiagMgr7_Trns | Rte_Ev_Run_RteErrata7_RteErrata7_Trns | Rte_Ev_MS_Task_Trns_7);
    Rte_Task_WaitEventRet(Task_Trns_7, Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_WARMINIT | Rte_Ev_Run_DiagMgr7_DiagMgr7_Trns | Rte_Ev_Run_RteErrata7_RteErrata7_Trns | Rte_Ev_MS_Task_Trns_7);
    (void)GetEvent(Task_Trns_7, &ev);
    (void)ClearEvent(ev & (Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_WARMINIT | Rte_Ev_Run_DiagMgr7_DiagMgr7_Trns | Rte_Ev_Run_RteErrata7_RteErrata7_Trns | Rte_Ev_MS_Task_Trns_7));

    if ((ev & Rte_Ev_Run_DiagMgr7_DiagMgr7_Trns) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DiagMgr7_DiagMgr7_Trns_Start();
      DiagMgr7_Trns();
      Rte_Runnable_Ap_DiagMgr7_DiagMgr7_Trns_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start();
      BkCpPc_Trns1();
      Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return();

      /* write implicit data */
      Rte_Sa_BkCpPc_PwrDiscATestComplete_Cnt_lgc = *(&Rte_Task_Trns_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Trns1.Rte_PwrDiscATestComplete_Cnt_lgc.value);
      Rte_Sa_BkCpPc_PwrDiscBTestComplete_Cnt_lgc = *(&Rte_Task_Trns_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Trns1.Rte_PwrDiscBTestComplete_Cnt_lgc.value);
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_WARMINIT) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start();
      TmprlMon_Trns1();
      Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return();

      /* write implicit data */
      Rte_TmprlMon_TMFTestComplete_Cnt_lgc = *(&Rte_Task_Trns_7.Rte_RB.Rte_Sa_TmprlMon_TmprlMon_Trns1.Rte_TMFTestComplete_Cnt_lgc.value);

      /* call runnable */
      Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start();
      BkCpPc_Trns2();
      Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return();

      /* write implicit data */
      Rte_Sa_BkCpPc_PwrDiscATestComplete_Cnt_lgc = *(&Rte_Task_Trns_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Trns2.Rte_PwrDiscATestComplete_Cnt_lgc.value);
      Rte_Sa_BkCpPc_PwrDiscBTestComplete_Cnt_lgc = *(&Rte_Task_Trns_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Trns2.Rte_PwrDiscBTestComplete_Cnt_lgc.value);
      Rte_Sa_BkCpPc_PwrDiscClosed_Cnt_lgc = *(&Rte_Task_Trns_7.Rte_RB.Rte_Sa_BkCpPc_BkCpPc_Trns2.Rte_PwrDiscClosed_Cnt_lgc.value);
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start();
      TmprlMon_Trns2();
      Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return();
    }

    if (((ev & Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_Run_RteErrata7_RteErrata7_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_WARMINIT) != (EventMaskType)0))
    {
      /* call runnable */
      Rte_Runnable_RteErrata7_RteErrata7_Trns_Start();
      RteErrata7_Trns();
      Rte_Runnable_RteErrata7_RteErrata7_Trns_Return();
    }

    if (((ev & Rte_Ev_Run_DiagMgr7_DiagMgr7_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_Run_RteErrata7_RteErrata7_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_7_StaMd7_SystemState7_Mode_WARMINIT) != (EventMaskType)0) || ((ev & Rte_Ev_MS_Task_Trns_7) != (EventMaskType)0))
    {
      Rte_ModeType_StaMd_Mode previousMode;
      Rte_ModeType_StaMd_Mode nextMode;

      Rte_Assert((Rte_ModeMachine_StaMd7_SystemState7_Mode == RTE_TRANSITION_StaMd_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();
      previousMode = Rte_ModeInfo_StaMd7_SystemState7_Mode.Rte_ModeQueue[1];
      nextMode = Rte_ModeInfo_StaMd7_SystemState7_Mode.Rte_ModeQueue[0];

      if (previousMode != nextMode)
      {
        Rte_DecDisableFlags_StaMd7_SystemState7_Mode(previousMode);
      }

      Rte_ModeMachine_StaMd7_SystemState7_Mode = Rte_ModeInfo_StaMd7_SystemState7_Mode.Rte_ModeQueue[0];

      EnableAllInterrupts();


    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_Trns_8
 * Priority: 5
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trns_8)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trns_8);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trns_8, Rte_Ev_Run_DiagMgr8_DiagMgr8_Trns | Rte_Ev_Run_RteErrata8_RteErrata8_Trns | Rte_Ev_MS_Task_Trns_8);
    (void)WaitEvent(Rte_Ev_Run_DiagMgr8_DiagMgr8_Trns | Rte_Ev_Run_RteErrata8_RteErrata8_Trns | Rte_Ev_MS_Task_Trns_8);
    Rte_Task_WaitEventRet(Task_Trns_8, Rte_Ev_Run_DiagMgr8_DiagMgr8_Trns | Rte_Ev_Run_RteErrata8_RteErrata8_Trns | Rte_Ev_MS_Task_Trns_8);
    (void)GetEvent(Task_Trns_8, &ev);
    (void)ClearEvent(ev & (Rte_Ev_Run_DiagMgr8_DiagMgr8_Trns | Rte_Ev_Run_RteErrata8_RteErrata8_Trns | Rte_Ev_MS_Task_Trns_8));

    if ((ev & Rte_Ev_Run_DiagMgr8_DiagMgr8_Trns) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start();
      DiagMgr8_Trns();
      Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return();
    }

    if ((ev & Rte_Ev_Run_RteErrata8_RteErrata8_Trns) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_RteErrata8_RteErrata8_Trns_Start();
      RteErrata8_Trns();
      Rte_Runnable_RteErrata8_RteErrata8_Trns_Return();
    }

    if (((ev & Rte_Ev_Run_DiagMgr8_DiagMgr8_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_Run_RteErrata8_RteErrata8_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_MS_Task_Trns_8) != (EventMaskType)0))
    {
      Rte_ModeType_StaMd_Mode previousMode;
      Rte_ModeType_StaMd_Mode nextMode;

      Rte_Assert((Rte_ModeMachine_StaMd8_SystemState8_Mode == RTE_TRANSITION_StaMd_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();
      previousMode = Rte_ModeInfo_StaMd8_SystemState8_Mode.Rte_ModeQueue[1];
      nextMode = Rte_ModeInfo_StaMd8_SystemState8_Mode.Rte_ModeQueue[0];

      if (previousMode != nextMode)
      {
        Rte_DecDisableFlags_StaMd8_SystemState8_Mode(previousMode);
      }

      Rte_ModeMachine_StaMd8_SystemState8_Mode = Rte_ModeInfo_StaMd8_SystemState8_Mode.Rte_ModeQueue[0];

      EnableAllInterrupts();


    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_Trns_9
 * Priority: 9
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trns_9)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trns_9);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trns_9, Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_WARMINIT | Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_Run_HwPwUp_HwPwUp_Trns1 | Rte_Ev_MS_Task_Trns_9);
    (void)WaitEvent(Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_WARMINIT | Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_Run_HwPwUp_HwPwUp_Trns1 | Rte_Ev_MS_Task_Trns_9);
    Rte_Task_WaitEventRet(Task_Trns_9, Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_WARMINIT | Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_Run_HwPwUp_HwPwUp_Trns1 | Rte_Ev_MS_Task_Trns_9);
    (void)GetEvent(Task_Trns_9, &ev);
    (void)ClearEvent(ev & (Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_WARMINIT | Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_Run_HwPwUp_HwPwUp_Trns1 | Rte_Ev_MS_Task_Trns_9));

    if ((ev & Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start();
      DiagMgr9_Trns();
      Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return();

      /* call runnable */
      Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start();
      DiagMgr_Trns1();
      Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Sa_PrimaryShutdown_PrimShtdn_Trns2_Start();
      PrimShtdn_Trns2();
      Rte_Runnable_Sa_PrimaryShutdown_PrimShtdn_Trns2_Return();

      /* call runnable */
      Rte_Runnable_Ap_SrlComInput_SrlComInput_Trns1_Start();
      SrlComInput_Trns1();
      Rte_Runnable_Ap_SrlComInput_SrlComInput_Trns1_Return();
    }

    if (((ev & Rte_Ev_Run_HwPwUp_HwPwUp_Trns1) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_WARMINIT) != (EventMaskType)0))
    {
      /* call runnable */
      Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start();
      HwPwUp_Trns1();
      Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return();

      /* write implicit data */
      Rte_HwPwUp_MtrDrvrInitStart_Cnt_lgc = *(&Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_MtrDrvrInitStart_Cnt_lgc.value);
      Rte_HwPwUp_PwrDiscATestStart_Cnt_lgc = *(&Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_PwrDiscATestStart_Cnt_lgc.value);
      Rte_HwPwUp_PwrDiscBTestStart_Cnt_lgc = *(&Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_PwrDiscBTestStart_Cnt_lgc.value);
      Rte_HwPwUp_TMFTestStart_Cnt_lgc = *(&Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_TMFTestStart_Cnt_lgc.value);
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Sa_PrimaryShutdown_PrimShtdn_Trns1_Start();
      PrimShtdn_Trns1();
      Rte_Runnable_Sa_PrimaryShutdown_PrimShtdn_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_DISABLE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start();
      HwPwUp_Trns2();
      Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start();
      AvgFricLrn_Trns1();
      Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start();
      ActivePull_Trns1();
      Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_ActivePull_ActivePull_Trns2_Start();
      ActivePull_Trns2();
      Rte_Runnable_Ap_ActivePull_ActivePull_Trns2_Return();
    }

    if (((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_WARMINIT) != (EventMaskType)0))
    {
      /* call runnable */
      Rte_Runnable_RteErrata9_RteErrata9_Trns_Start();
      RteErrata9_Trns();
      Rte_Runnable_RteErrata9_RteErrata9_Trns_Return();
    }

    if (((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_Run_HwPwUp_HwPwUp_Trns1) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_WARMINIT) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trns_9_StaMd9_SystemState9_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_OnExit_Task_Trns_9_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_MS_Task_Trns_9) != (EventMaskType)0))
    {
      Rte_ModeType_StaMd_Mode previousMode;
      Rte_ModeType_StaMd_Mode nextMode;

      Rte_Assert((Rte_ModeMachine_StaMd9_SystemState9_Mode == RTE_TRANSITION_StaMd_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();
      previousMode = Rte_ModeInfo_StaMd9_SystemState9_Mode.Rte_ModeQueue[1];
      nextMode = Rte_ModeInfo_StaMd9_SystemState9_Mode.Rte_ModeQueue[0];

      if (previousMode != nextMode)
      {
        Rte_DecDisableFlags_StaMd9_SystemState9_Mode(previousMode);
      }

      Rte_ModeMachine_StaMd9_SystemState9_Mode = Rte_ModeInfo_StaMd9_SystemState9_Mode.Rte_ModeQueue[0];

      EnableAllInterrupts();


    }
  }
}

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
# ifdef RTE_MAGIC_NUMBER
#  if RTE_MAGIC_NUMBER != 1455040902
#   error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Rte.c> is different. Please check time and date of the generated RTE files!"
#  endif
# else
#  define RTE_MAGIC_NUMBER 1455040902
# endif  /* RTE_MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */
