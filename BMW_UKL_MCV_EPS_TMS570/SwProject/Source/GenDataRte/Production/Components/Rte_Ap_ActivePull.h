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
 *          File:  Components/Rte_Ap_ActivePull.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  7 10:38:57 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ACTIVEPULL_H
# define _RTE_AP_ACTIVEPULL_H

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

#  define Rte_InitValue_DisableLearning_Cnt_lgc (FALSE)
#  define Rte_InitValue_DisableOutput_Cnt_lgc (FALSE)
#  define Rte_InitValue_EstLatAcc_MpSecSq_f32 (0.0F)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_PullCmpCustLrngDi_Cnt_lgc (FALSE)
#  define Rte_InitValue_PullCmpEna_Cnt_lgc (TRUE)
#  define Rte_InitValue_PullCmpLongTermIntgtrSt_HwNm_f32 (0.0F)
#  define Rte_InitValue_PullCmpLongTermIntgtrStOffs_HwNm_f32 (0.0F)
#  define Rte_InitValue_PullCmpShoTermIntgtrSt_HwNm_f32 (0.0F)
#  define Rte_InitValue_PullCmpShoTermIntgtrStOffs_HwNm_f32 (0.0F)
#  define Rte_InitValue_PullCompCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleYawRate_DegpS_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
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

extern VAR(Rte_tsTask_2msA_9, RTE_VAR_NOINIT) Rte_Task_2msA_9;

extern VAR(Rte_tsTask_100ms_9, RTE_VAR_NOINIT) Rte_Task_100ms_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_ActivePull_Per1_DisableLearning_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_DisableLearning_Cnt_lgc.value)

#  define Rte_IRead_ActivePull_Per1_DisableOutput_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_DisableOutput_Cnt_lgc.value)

#  define Rte_IRead_ActivePull_Per1_EstLatAcc_MpSecSq_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_EstLatAcc_MpSecSq_f32.value)

#  define Rte_IRead_ActivePull_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_ActivePull_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_ActivePull_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value)

#  define Rte_IRead_ActivePull_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_ActivePull_Per1_PullCmpCustLrngDi_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpCustLrngDi_Cnt_lgc.value)

#  define Rte_IRead_ActivePull_Per1_PullCmpEna_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpEna_Cnt_lgc.value)

#  define Rte_IRead_ActivePull_Per1_PullCmpShoTermIntgtrStOffs_HwNm_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32.value)

#  define Rte_IRead_ActivePull_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_ActivePull_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IRead_ActivePull_Per1_VehicleYawRate_DegpS_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleYawRate_DegpS_f32.value)

#  define Rte_IWrite_ActivePull_Per1_PullCmpShoTermIntgtrSt_HwNm_f32(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpShoTermIntgtrSt_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_ActivePull_Per1_PullCmpShoTermIntgtrSt_HwNm_f32() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpShoTermIntgtrSt_HwNm_f32.value)

#  define Rte_IRead_ActivePull_Per2_DisableOutput_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_DisableOutput_Cnt_lgc.value)

#  define Rte_IRead_ActivePull_Per2_PullCmpEna_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpEna_Cnt_lgc.value)

#  define Rte_IRead_ActivePull_Per2_PullCmpLongTermIntgtrStOffs_HwNm_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32.value)

#  define Rte_IRead_ActivePull_Per2_PullCmpShoTermIntgtrStOffs_HwNm_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32.value)

#  define Rte_IRead_ActivePull_Per2_VehicleSpeed_Kph_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_ActivePull_Per2_PullCompCmd_MtrNm_f32(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCompCmd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_ActivePull_Per2_PullCompCmd_MtrNm_f32() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCompCmd_MtrNm_f32.value)

#  define Rte_IRead_ActivePull_Per3_HwTorque_HwNm_f32() \
  (Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_ActivePull_Per3_PullCmpEna_Cnt_lgc() \
  (Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpEna_Cnt_lgc.value)

#  define Rte_IRead_ActivePull_Per3_PullCmpLongTermIntgtrStOffs_HwNm_f32() \
  (Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32.value)

#  define Rte_IRead_ActivePull_Per3_VehicleSpeed_Kph_f32() \
  (Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_ActivePull_Per3_PullCmpLongTermIntgtrSt_HwNm_f32(data) \
  ( \
    Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpLongTermIntgtrSt_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_ActivePull_Per3_PullCmpLongTermIntgtrSt_HwNm_f32() \
  (&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpLongTermIntgtrSt_HwNm_f32.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_PullCmpLTComp_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)57, arg1), ((Std_ReturnType)RTE_E_OK))
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


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_ActivePull_PullCmpLTComp_HwNm_f32;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_PullCmpLTComp_HwNm_f32() \
  (&Rte_ActivePull_PullCmpLTComp_HwNm_f32)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_ACTIVEPULL_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Init1(void);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Per1(void);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Per2(void);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Per3(void);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_ReadParam(P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) PullCompCmd_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) STComp_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) LTComp_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) EnableLearn_Cnt_lgc);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_Reset(void);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Trns1(void);

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Trns2(void);

# define RTE_STOP_SEC_AP_ACTIVEPULL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_ActivePull.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ACTIVEPULL_H */
