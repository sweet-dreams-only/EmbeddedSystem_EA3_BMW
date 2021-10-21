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
 *          File:  Components/Rte_Ap_TJADamp.h
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
#ifndef _RTE_AP_TJADAMP_H
# define _RTE_AP_TJADAMP_H

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

#  define Rte_InitValue_CustomDamp_MtrNm_f32 (0.0F)
#  define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_TJADampSclRqst_Uls_f32 (0.0F)
#  define Rte_InitValue_TJAState_Cnt_enum (1U)
#  define Rte_InitValue_TJAStateRqst_Cnt_enum (1U)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2msA_9, RTE_VAR_NOINIT) Rte_Task_2msA_9;

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

#  define Rte_IRead_TJADamp_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_MtrVel_CRFMotorVel_MtrRadpS_f32.value)

#  define Rte_IRead_TJADamp_Per1_TJADampSclRqst_Uls_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_TJADamp_TJADamp_Per1.Rte_TJADampSclRqst_Uls_f32.value)

#  define Rte_IRead_TJADamp_Per1_TJAStateRqst_Cnt_enum() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_TJADamp_TJADamp_Per1.Rte_TJAStateRqst_Cnt_enum.value)

#  define Rte_IRead_TJADamp_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_TJADamp_Per1_CustomDamp_MtrNm_f32(data) \
  ( \
    Rte_Task_2msA_9.Rte_TB.Rte_I_Ap_TJADamp_CustomDamp_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_TJADamp_Per1_CustomDamp_MtrNm_f32() \
  (&Rte_Task_2msA_9.Rte_TB.Rte_I_Ap_TJADamp_CustomDamp_MtrNm_f32.value)

#  define Rte_IWrite_TJADamp_Per1_TJAState_Cnt_enum(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_TJADamp_TJADamp_Per1.Rte_TJAState_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_TJADamp_Per1_TJAState_Cnt_enum() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_TJADamp_TJADamp_Per1.Rte_TJAState_Cnt_enum.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr9_GetNTCFailed


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_TJADAMP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TJADAMP_APPL_CODE) TJADamp_Init(void);

FUNC(void, RTE_AP_TJADAMP_APPL_CODE) TJADamp_Per1(void);

# define RTE_STOP_SEC_AP_TJADAMP_APPL_CODE
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
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_TJADamp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TJADAMP_H */
