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
 *          File:  Components/Rte_Ap_CurrentEst.h
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
#ifndef _RTE_AP_CURRENTEST_H
# define _RTE_AP_CURRENTEST_H

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

#  define Rte_InitValue_EstPkCurr_AmpSq_f32 (0.0F)
#  define Rte_InitValue_EstR_Ohm_f32 (0.0F)
#  define Rte_InitValue_ExpIq_Amp_f32 (0.0F)
#  define Rte_InitValue_FiltEstPkCurr_AmpSq_f32 (0.0F)
#  define Rte_InitValue_IdEst_Amp_f32 (0.0F)
#  define Rte_InitValue_ModIdx_Uls_f32 (0.0F)
#  define Rte_InitValue_TermXq_Uls_f32 (0.0F)
#  define Rte_InitValue_UncorrPhsAdv_Cnt_s16 (0)
#  define Rte_InitValue_Vecu_Volt_f32 (5.0F)
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



/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

# define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
# include "MemMap.h"

extern VAR(Float, RTE_VAR_INIT) Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32_Task_100ms_10;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32_Task_2ms_10;

# define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
# include "MemMap.h"


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

extern VAR(Rte_tsTask_100ms_10, RTE_VAR_NOINIT) Rte_Task_100ms_10;

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

#  define Rte_IRead_CurrentEst_Per1_EstR_Ohm_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_ParamComp_EstR_Ohm_f32.value)

#  define Rte_IRead_CurrentEst_Per1_ExpIq_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_ExpIq_Amp_f32.value)

#  define Rte_IRead_CurrentEst_Per1_ModIdx_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_ModIdx_Uls_f32.value)

#  define Rte_IRead_CurrentEst_Per1_TermXq_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_TermXq_Uls_f32.value)

#  define Rte_IRead_CurrentEst_Per1_UncorrPhsAdv_Cnt_s16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_UncorrPhsAdv_Cnt_s16.value)

#  define Rte_IRead_CurrentEst_Per1_Vecu_Volt_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value)

#  define Rte_IWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_EstPkCurr_AmpSq_f32.value = (data) \
  )

#  define Rte_IWriteRef_CurrentEst_Per1_EstPkCurr_AmpSq_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per1.Rte_EstPkCurr_AmpSq_f32.value)

#  define Rte_IWrite_CurrentEst_Per1_IdEst_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_CurrentEst_IdEst_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CurrentEst_Per1_IdEst_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_CurrentEst_IdEst_Amp_f32.value)

#  define Rte_IWrite_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32(data) \
  ( \
    Rte_Task_100ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per2.Rte_FiltEstPkCurr_AmpSq_f32.value = (data) \
  )

#  define Rte_IWriteRef_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32() \
  (&Rte_Task_100ms_10.Rte_RB.Rte_Ap_CurrentEst_CurrentEst_Per2.Rte_FiltEstPkCurr_AmpSq_f32.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

#  define Rte_IrvIWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(data) \
  (Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32_Task_2ms_10 = (data))

#  define Rte_IrvIRead_CurrentEst_Per2_EstPkCurr_AmpSq_f32() \
  Rte_Irv_CurrentEst_EstPkCurr_AmpSq_f32_Task_100ms_10


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_CURRENTEST_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRENTEST_APPL_CODE) CurrentEst_Per1(void);

FUNC(void, RTE_AP_CURRENTEST_APPL_CODE) CurrentEst_Per2(void);

# define RTE_STOP_SEC_AP_CURRENTEST_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_CurrentEst.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CURRENTEST_H */
