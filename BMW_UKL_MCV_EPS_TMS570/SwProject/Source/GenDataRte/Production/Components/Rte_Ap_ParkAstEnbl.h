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
 *          File:  Components/Rte_Ap_ParkAstEnbl.h
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
#ifndef _RTE_AP_PARKASTENBL_H
# define _RTE_AP_PARKASTENBL_H

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
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_DiagStsRmpZeroNRec_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsRmpZeroRec_Cnt_lgc (FALSE)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HandwheelVel_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_LimitPercentFiltered_Uls_f32 (0.0F)
#  define Rte_InitValue_PAEnableRqst_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAErrInterfaceActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAHWAngleRqst_HwDeg_f32 (0.0F)
#  define Rte_InitValue_PASpdHigh_Cnt_u08 (15U)
#  define Rte_InitValue_PASpdStdStill_Cnt_u08 (0U)
#  define Rte_InitValue_PendEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PendHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_PosServEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosServoHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_PosTrajEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosTrajHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_PrkAssistState_Cnt_u08 (128U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd7_SystemState7_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_7, RTE_VAR_NOINIT) Rte_Task_2ms_7;

#  define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroNRec_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_DiagStsRmpZeroNRec_Cnt_lgc.value)

#  define Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroRec_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_DiagStsRmpZeroRec_Cnt_lgc.value)

#  define Rte_IRead_ParkAstEnbl_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_ParkAstEnbl_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_2ms_7.Rte_TB.Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_ParkAstEnbl_Per1_HandwheelVel_HwRadpS_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_HandwheelVel_HwRadpS_f32.value)

#  define Rte_IRead_ParkAstEnbl_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_ParkAstEnbl_Per1_LimitPercentFiltered_Uls_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_LimitPercentFiltered_Uls_f32.value)

#  define Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PAEnableRqst_Cnt_lgc.value)

#  define Rte_IRead_ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PAErrInterfaceActive_Cnt_lgc.value)

#  define Rte_IRead_ParkAstEnbl_Per1_PAHWAngleRqst_HwDeg_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PAHWAngleRqst_HwDeg_f32.value)

#  define Rte_IRead_ParkAstEnbl_Per1_PASpdHigh_Cnt_u08() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PASpdHigh_Cnt_u08.value)

#  define Rte_IRead_ParkAstEnbl_Per1_PASpdStdStill_Cnt_u08() \
  (0U)

#  define Rte_IRead_ParkAstEnbl_Per1_PendEnable_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_TB.Rte_I_CDDInterface9_OscTrajEnable_Cnt_lgc.value)

#  define Rte_IRead_ParkAstEnbl_Per1_PendHwAngle_HwDeg_f32() \
  (Rte_Task_2ms_7.Rte_TB.Rte_I_OscTraj_OscillateHwAngle_HwDeg_f32.value)

#  define Rte_IRead_ParkAstEnbl_Per1_PosTrajEnable_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_TB.Rte_I_CDDInterface9_PosTrajEnable_Cnt_lgc.value)

#  define Rte_IRead_ParkAstEnbl_Per1_PosTrajHwAngle_HwDeg_f32() \
  (Rte_Task_2ms_7.Rte_TB.Rte_I_GenPosTraj_PosTrajHwAngle_HwDeg_f32.value)

#  define Rte_IWrite_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PosServEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PosServEnable_Cnt_lgc.value)

#  define Rte_IWrite_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PosServoHwAngle_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PosServoHwAngle_HwDeg_f32.value)

#  define Rte_IWrite_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PrkAssistState_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1.Rte_PrkAssistState_Cnt_u08.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd7_SystemState7_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR7_APPL_CODE) NxtrDiagMgr7_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR7_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr7_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR7_APPL_CODE) NxtrDiagMgr7_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr7_SetNTCStatus
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(arg1, arg2) (DtrmnElapsedTime_mS_u32(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_PARKASTENBL_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARKASTENBL_APPL_CODE) ParkAstEnbl_Per1(void);

# define RTE_STOP_SEC_AP_PARKASTENBL_APPL_CODE
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
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_ParkAstEnbl.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PARKASTENBL_H */
