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
 *          File:  Components/Rte_Sa_PhaseDscnt.h
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
#ifndef _RTE_SA_PHASEDSCNT_H
# define _RTE_SA_PHASEDSCNT_H

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

#  define Rte_InitValue_MotorQuadrant_Cnt_u08 (1U)
#  define Rte_InitValue_MotorVelMRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_PDActivateTest_Cnt_lgc (FALSE)
#  define Rte_InitValue_PDChrgPmpFdbkADC_Volt_f32 (0.0F)
#  define Rte_InitValue_PDPhaseAdvSelect_Cnt_s16 (0)
#  define Rte_InitValue_PDSuplFdbkADC_Volt_f32 (0.0F)
#  define Rte_InitValue_PDTestModIndex_Uls_f32 (0.0F)
#  define Rte_InitValue_PhsDiscTestComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_RawCurrFiltered_Amp_f32 (0.0F)
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

#  define Rte_IRead_PhaseDscnt_Per1_MotorQuadrant_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_QuadDet_MtrQuad_Cnt_u08.value)

#  define Rte_IRead_PhaseDscnt_Per1_MotorVelMRF_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value)

#  define Rte_IRead_PhaseDscnt_Per1_RawCurrFiltered_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_RawCurrFiltered_Amp_f32.value)

#  define Rte_IWrite_PhaseDscnt_Per1_PDActivateTest_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDActivateTest_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PhaseDscnt_Per1_PDActivateTest_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDActivateTest_Cnt_lgc.value)

#  define Rte_IWrite_PhaseDscnt_Per1_PDPhaseAdvSelect_Cnt_s16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDPhaseAdvSelect_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_PhaseDscnt_Per1_PDPhaseAdvSelect_Cnt_s16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDPhaseAdvSelect_Cnt_s16.value)

#  define Rte_IWrite_PhaseDscnt_Per1_PDTestModIndex_Uls_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDTestModIndex_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_PhaseDscnt_Per1_PDTestModIndex_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per1.Rte_PDTestModIndex_Uls_f32.value)

#  define Rte_IRead_PhaseDscnt_Per2_PDChrgPmpFdbkADC_Volt_f32() \
  (Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDChrgPmpFdbkADC_Volt_f32.value)

#  define Rte_IRead_PhaseDscnt_Per2_PDSuplFdbkADC_Volt_f32() \
  (Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDSuplFdbkADC_Volt_f32.value)

#  define Rte_IWrite_PhaseDscnt_Per2_PDActivateTest_Cnt_lgc(data) \
  ( \
    Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDActivateTest_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PhaseDscnt_Per2_PDActivateTest_Cnt_lgc() \
  (&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDActivateTest_Cnt_lgc.value)

#  define Rte_IWrite_PhaseDscnt_Per2_PDPhaseAdvSelect_Cnt_s16(data) \
  ( \
    Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDPhaseAdvSelect_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_PhaseDscnt_Per2_PDPhaseAdvSelect_Cnt_s16() \
  (&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDPhaseAdvSelect_Cnt_s16.value)

#  define Rte_IWrite_PhaseDscnt_Per2_PDTestModIndex_Uls_f32(data) \
  ( \
    Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDTestModIndex_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_PhaseDscnt_Per2_PDTestModIndex_Uls_f32() \
  (&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PDTestModIndex_Uls_f32.value)

#  define Rte_IWrite_PhaseDscnt_Per2_PhsDiscTestComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PhsDiscTestComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PhaseDscnt_Per2_PhsDiscTestComplete_Cnt_lgc() \
  (&Rte_Task_10msB_10.Rte_RB.Rte_Sa_PhaseDscnt_PhaseDscnt_Per2.Rte_PhsDiscTestComplete_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWAB10_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_IOHWAB10_APPL_CODE) NHETSigCtrl_GetPhaseDisconnectSignal(P2VAR(UInt8, AUTOMATIC, RTE_IOHWAB10_APPL_VAR) Signal_Cnt_T_u08);
#  define RTE_STOP_SEC_IOHWAB10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NHETSigCtrl_GetPhaseDisconnectSignal(arg1) (NHETSigCtrl_GetPhaseDisconnectSignal(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_IOHWAB10_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_IOHWAB10_APPL_CODE) NHETSigCtrl_SetPhaseDisconnectSignal(Boolean Signal_Cnt_T_lgc);
#  define RTE_STOP_SEC_IOHWAB10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NHETSigCtrl_SetPhaseDisconnectSignal(arg1) (NHETSigCtrl_SetPhaseDisconnectSignal(arg1), ((Std_ReturnType)RTE_E_OK))
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


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_PHASEDSCNT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_PHASEDSCNT_APPL_CODE) PhaseDscnt_Init1(void);

FUNC(void, RTE_SA_PHASEDSCNT_APPL_CODE) PhaseDscnt_Per1(void);

FUNC(void, RTE_SA_PHASEDSCNT_APPL_CODE) PhaseDscnt_Per2(void);

# define RTE_STOP_SEC_SA_PHASEDSCNT_APPL_CODE
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
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_PhaseDscnt.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_PHASEDSCNT_H */
