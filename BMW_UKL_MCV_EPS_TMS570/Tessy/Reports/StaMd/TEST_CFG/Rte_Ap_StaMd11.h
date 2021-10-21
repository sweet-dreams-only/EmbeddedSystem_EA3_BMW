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
 *          File:  Components/Rte_Ap_StaMd11.h
 *     Workspace:  C:/ccm_wa/EPS/570/I410/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Mon Feb 11 13:51:17 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_STAMD11_H
# define _RTE_AP_STAMD11_H

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

# include "Rte_Hook.h"


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd11_SystemState11_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd11_SystemState11_Mode(Rte_ModeType_StaMd_Mode nextMode);


# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState11_Mode() Rte_ModeMachine_StaMd11_SystemState11_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_SystemState11_Mode Rte_Switch_Ap_StaMd11_SystemState11_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_WDGM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_WDGM_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType parg1);
#  define RTE_STOP_SEC_WDGM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_StaMd11_Per1_CP1_CheckpointReached() (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)4, (WdgM_CheckpointIdType)0))


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_StaMds11_MilestoneRqst_WARMINIT_ExclArea() \
  { \
    Rte_EnterHook_Ap_StaMd11_StaMds11_MilestoneRqst_WARMINIT_ExclArea_Start(); \
    SuspendOSInterrupts(); \
    Rte_EnterHook_Ap_StaMd11_StaMds11_MilestoneRqst_WARMINIT_ExclArea_Return(); \
  }

#  define Rte_Exit_StaMds11_MilestoneRqst_WARMINIT_ExclArea() \
  { \
    Rte_ExitHook_Ap_StaMd11_StaMds11_MilestoneRqst_WARMINIT_ExclArea_Start(); \
    ResumeOSInterrupts(); \
    Rte_ExitHook_Ap_StaMd11_StaMds11_MilestoneRqst_WARMINIT_ExclArea_Return(); \
  }


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_STAMD11_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STAMD11_APPL_CODE) MilestoneRqst11_WarmInitMilestoneComplete(StaMd_Users user);

FUNC(void, RTE_AP_STAMD11_APPL_CODE) MilestoneRqst11_WarmInitMilestoneNotComplete(StaMd_Users user);

FUNC(void, RTE_AP_STAMD11_APPL_CODE) StaMd11_Per1(void);

# define RTE_STOP_SEC_AP_STAMD11_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_WdgM_CheckpointReached_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1360603994
#    error "The magic number of the generated file <C:/ccm_wa/EPS/570/I410/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_StaMd11.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1360603994
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_STAMD11_H */
