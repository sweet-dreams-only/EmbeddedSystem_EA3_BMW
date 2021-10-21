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
 *          File:  Components/Rte_Ap_ApXcp.h
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
#ifndef _RTE_AP_APXCP_H
# define _RTE_AP_APXCP_H

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

#  define Rte_InitValue_ActiveTunOvrPtrAddr_Cnt_u32 (0U)
#  define Rte_InitValue_ActiveTunPers_Cnt_u16 (0U)
#  define Rte_InitValue_ActiveTunSet_Cnt_u16 (0U)
#  define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
#  define Rte_InitValue_DesiredTunSet_Cnt_u16 (0U)
#  define Rte_InitValue_TuningSessionActPtr_Cnt_u8 (255U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10msB_9, RTE_VAR_NOINIT) Rte_Task_10msB_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_ApXcp_Per1_ActiveTunPers_Cnt_u16() \
  (Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunPers_Cnt_u16.value)

#  define Rte_IRead_ApXcp_Per1_ActiveTunSet_Cnt_u16() \
  (Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunSet_Cnt_u16.value)

#  define Rte_IRead_ApXcp_Per1_DesiredTunPers_Cnt_u16() \
  (Rte_Task_10msB_9.Rte_TB.Rte_I_VehCfg_DesiredTunPers_Cnt_u16.value)

#  define Rte_IRead_ApXcp_Per1_DesiredTunSet_Cnt_u16() \
  (Rte_Task_10msB_9.Rte_TB.Rte_I_VehCfg_DesiredTunSet_Cnt_u16.value)

#  define Rte_IWrite_ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32(data) \
  ( \
    Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunOvrPtrAddr_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32() \
  (&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunOvrPtrAddr_Cnt_u32.value)

#  define Rte_IWrite_ApXcp_Per1_TuningSessionActPtr_Cnt_u8(data) \
  ( \
    Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_TuningSessionActPtr_Cnt_u8.value = (data) \
  )

#  define Rte_IWriteRef_ApXcp_Per1_TuningSessionActPtr_Cnt_u8() \
  (&Rte_Task_10msB_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_TuningSessionActPtr_Cnt_u8.value)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_APXCP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_APXCP_APPL_CODE) ApXcp_Per1(void);

FUNC(void, RTE_AP_APXCP_APPL_CODE) DAQ_1msTL(void);

FUNC(void, RTE_AP_APXCP_APPL_CODE) DAQ_2msTL(void);

# define RTE_STOP_SEC_AP_APXCP_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_ApXcp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_APXCP_H */
