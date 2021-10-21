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
 *          File:  Components/Rte_Ap_DrvDynEnbl.h
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
#ifndef _RTE_AP_DRVDYNENBL_H
# define _RTE_AP_DRVDYNENBL_H

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

#  define Rte_InitValue_DDEnableRqst_Cnt_lgc (FALSE)
#  define Rte_InitValue_DDErrInterfaceActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStatus_Cnt_lgc (FALSE)
#  define Rte_InitValue_DrvDynActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DrvDynInterfaceState_Cnt_u08 (128U)
#  define Rte_InitValue_OpTrqOvRmpInEnable_Cnt_lgc (FALSE)
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

#  define Rte_IRead_DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DDEnableRqst_Cnt_lgc.value)

#  define Rte_IRead_DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DDErrInterfaceActive_Cnt_lgc.value)

#  define Rte_IRead_DrvDynEnbl_Per1_DiagStatus_Cnt_lgc() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DiagStatus_Cnt_lgc.value)

#  define Rte_IRead_DrvDynEnbl_Per1_PrkAssistState_Cnt_u08() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_PrkAssistState_Cnt_u08.value)

#  define Rte_IWrite_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DrvDynActive_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DrvDynActive_Cnt_lgc.value)

#  define Rte_IWrite_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DrvDynInterfaceState_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_DrvDynInterfaceState_Cnt_u08.value)

#  define Rte_IWrite_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_OpTrqOvRmpInEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1.Rte_OpTrqOvRmpInEnable_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd7_SystemState7_Mode


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_DRVDYNENBL_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DRVDYNENBL_APPL_CODE) DrvDynEnbl_Per1(void);

# define RTE_STOP_SEC_AP_DRVDYNENBL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_DrvDynEnbl.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DRVDYNENBL_H */
