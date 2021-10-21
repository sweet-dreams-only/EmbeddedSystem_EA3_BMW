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
 *          File:  Components/Rte_Sa_MtrVel.h
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
#ifndef _RTE_SA_MTRVEL_H
# define _RTE_SA_MTRVEL_H

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

#  define Rte_InitValue_AsstAssemPol_Cnt_s08 (0)
#  define Rte_InitValue_CRFMotorVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_HandwheelVel_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_HwVelValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_MRFMotorVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_MRFMotorVelUnfiltered_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_SysCDiagHandWheelVel_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_SysCDiagMtrVelMRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_SysCHandwheelVel_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_SysCMotorVelMRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_1ms_10, RTE_VAR_NOINIT) Rte_Task_1ms_10;

extern VAR(Rte_tsTask_4ms_10, RTE_VAR_NOINIT) Rte_Task_4ms_10;

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

#  define Rte_IRead_MtrVel_Per1_AsstAssemPol_Cnt_s08() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_Polarity_AssistAssyPolarity_Cnt_s08.value)

#  define Rte_IRead_MtrVel_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_CRFMotorVel_MtrRadpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_CRFMotorVel_MtrRadpS_f32.value)

#  define Rte_IWrite_MtrVel_Per1_HandwheelVel_HwRadpS_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_HandwheelVel_HwRadpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrVel_Per1_HandwheelVel_HwRadpS_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_HandwheelVel_HwRadpS_f32.value)

#  define Rte_IWrite_MtrVel_Per1_HwVelValid_Cnt_lgc(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_HwVelValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_MtrVel_Per1_HwVelValid_Cnt_lgc() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_HwVelValid_Cnt_lgc.value)

#  define Rte_IWrite_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_MRFMotorVelUnfiltered_MtrRadpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_MRFMotorVelUnfiltered_MtrRadpS_f32.value)

#  define Rte_IWrite_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value)

#  define Rte_IWrite_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_SysCHandwheelVel_HwRadpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_SysCHandwheelVel_HwRadpS_f32.value)

#  define Rte_IWrite_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_SysCMotorVelMRF_MtrRadpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_SysCMotorVelMRF_MtrRadpS_f32.value)

#  define Rte_IRead_MtrVel_Per2_SysCDiagHandWheelVel_HwRadpS_f32() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per2.Rte_SysCDiagHandWheelVel_HwRadpS_f32.value)

#  define Rte_IRead_MtrVel_Per2_SysCDiagMtrVelMRF_MtrRadpS_f32() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per2.Rte_SysCDiagMtrVelMRF_MtrRadpS_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_FLTINJECTION_APPL_CODE) FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_FLTINJECTION_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
#  define RTE_STOP_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_FaultInjection_SCom_FltInjection(arg1, arg2) (FltInjection_SCom_FltInjection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_MTRVEL_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Init1(void);

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Per1(void);

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Per2(void);

# define RTE_STOP_SEC_SA_MTRVEL_APPL_CODE
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
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_MtrVel.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRVEL_H */
