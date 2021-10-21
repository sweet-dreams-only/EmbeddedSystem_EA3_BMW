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
 *          File:  Components/Rte_Ap_HwPwUp.h
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
#ifndef _RTE_AP_HWPWUP_H
# define _RTE_AP_HWPWUP_H

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

#  define Rte_InitValue_MtrDrvrInitComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrDrvrInitStart_Cnt_lgc (FALSE)
#  define Rte_InitValue_PwrDiscATestComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_PwrDiscATestStart_Cnt_lgc (FALSE)
#  define Rte_InitValue_PwrDiscBTestComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_PwrDiscBTestStart_Cnt_lgc (FALSE)
#  define Rte_InitValue_TMFTestComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_TMFTestStart_Cnt_lgc (FALSE)
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

extern VAR(Rte_tsTask_Trns_9, RTE_VAR_NOINIT) Rte_Task_Trns_9;

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

#  define Rte_IRead_HwPwUp_Per1_MtrDrvrInitComplete_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_MtrDrvrInitComplete_Cnt_lgc.value)

#  define Rte_IRead_HwPwUp_Per1_PwrDiscATestComplete_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscATestComplete_Cnt_lgc.value)

#  define Rte_IRead_HwPwUp_Per1_PwrDiscBTestComplete_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscBTestComplete_Cnt_lgc.value)

#  define Rte_IRead_HwPwUp_Per1_TMFTestComplete_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_TMFTestComplete_Cnt_lgc.value)

#  define Rte_IWrite_HwPwUp_Per1_MtrDrvrInitStart_Cnt_lgc(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_MtrDrvrInitStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwPwUp_Per1_MtrDrvrInitStart_Cnt_lgc() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_MtrDrvrInitStart_Cnt_lgc.value)

#  define Rte_IWrite_HwPwUp_Per1_PwrDiscATestStart_Cnt_lgc(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscATestStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwPwUp_Per1_PwrDiscATestStart_Cnt_lgc() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscATestStart_Cnt_lgc.value)

#  define Rte_IWrite_HwPwUp_Per1_PwrDiscBTestStart_Cnt_lgc(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscBTestStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwPwUp_Per1_PwrDiscBTestStart_Cnt_lgc() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_PwrDiscBTestStart_Cnt_lgc.value)

#  define Rte_IWrite_HwPwUp_Per1_TMFTestStart_Cnt_lgc(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_TMFTestStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwPwUp_Per1_TMFTestStart_Cnt_lgc() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Per1.Rte_TMFTestStart_Cnt_lgc.value)

#  define Rte_IWrite_HwPwUp_Trns1_MtrDrvrInitStart_Cnt_lgc(data) \
  ( \
    Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_MtrDrvrInitStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwPwUp_Trns1_MtrDrvrInitStart_Cnt_lgc() \
  (&Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_MtrDrvrInitStart_Cnt_lgc.value)

#  define Rte_IWrite_HwPwUp_Trns1_PwrDiscATestStart_Cnt_lgc(data) \
  ( \
    Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_PwrDiscATestStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwPwUp_Trns1_PwrDiscATestStart_Cnt_lgc() \
  (&Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_PwrDiscATestStart_Cnt_lgc.value)

#  define Rte_IWrite_HwPwUp_Trns1_PwrDiscBTestStart_Cnt_lgc(data) \
  ( \
    Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_PwrDiscBTestStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwPwUp_Trns1_PwrDiscBTestStart_Cnt_lgc() \
  (&Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_PwrDiscBTestStart_Cnt_lgc.value)

#  define Rte_IWrite_HwPwUp_Trns1_TMFTestStart_Cnt_lgc(data) \
  ( \
    Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_TMFTestStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwPwUp_Trns1_TMFTestStart_Cnt_lgc() \
  (&Rte_Task_Trns_9.Rte_RB.Rte_Ap_HwPwUp_HwPwUp_Trns1.Rte_TMFTestStart_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_STAMD9_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_STAMD9_APPL_CODE) MilestoneRqst9_WarmInitMilestoneComplete(StaMd_Users user);
#  define RTE_STOP_SEC_AP_STAMD9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MilestoneRqst_WarmInitMilestoneComplete(arg1) (MilestoneRqst9_WarmInitMilestoneComplete(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_STAMD9_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_STAMD9_APPL_CODE) MilestoneRqst9_WarmInitMilestoneNotComplete(StaMd_Users user);
#  define RTE_STOP_SEC_AP_STAMD9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MilestoneRqst_WarmInitMilestoneNotComplete(arg1) (MilestoneRqst9_WarmInitMilestoneNotComplete(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_HWPWUP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HWPWUP_APPL_CODE) HwPwUp_Per1(void);

FUNC(void, RTE_AP_HWPWUP_APPL_CODE) HwPwUp_Trns1(void);

FUNC(void, RTE_AP_HWPWUP_APPL_CODE) HwPwUp_Trns2(void);

# define RTE_STOP_SEC_AP_HWPWUP_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_HwPwUp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_HWPWUP_H */
