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
 *          File:  Components/Rte_Sa_HwTrq.h
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
#ifndef _RTE_SA_HWTRQ_H
# define _RTE_SA_HWTRQ_H

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

#  define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Float, RTE_VAR_INIT) Rte_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_HwTrq_T1TrimVal_Volt_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_HwTrq_T2TrimVal_Volt_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_T1ADC_Volt_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAb7_T2ADC_Volt_f32;

#  define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AbsPosStepSignal_Cnt_u08 (0U)
#  define Rte_InitValue_AnaDiffHwTrq_Volt_f32 (0.0F)
#  define Rte_InitValue_AnaHwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_CntrlDisRampComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_ErrorActiveAnalog_Cnt_enum (0U)
#  define Rte_InitValue_HwTrqScaleVal_VoltsPerDeg_f32 (0.0F)
#  define Rte_InitValue_MECCounter_Cnt_enum (0U)
#  define Rte_InitValue_SrlComHwTrqValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SysCAnaHwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_SysCHwTorqueSqd_HwNmSq_f32 (0.0F)
#  define Rte_InitValue_T1ADC_Volt_f32 (0.0F)
#  define Rte_InitValue_T1TrimVal_Volt_f32 (0.0F)
#  define Rte_InitValue_T2ADC_Volt_f32 (0.0F)
#  define Rte_InitValue_T2TrimVal_Volt_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitB_7, RTE_VAR_NOINIT) Rte_Task_InitB_7;

extern VAR(Rte_tsTask_2ms_7, RTE_VAR_NOINIT) Rte_Task_2ms_7;

extern VAR(Rte_tsTask_4ms_7, RTE_VAR_NOINIT) Rte_Task_4ms_7;

extern VAR(Rte_tsTask_100ms_7, RTE_VAR_NOINIT) Rte_Task_100ms_7;

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

#  define Rte_IWrite_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32(data) \
  ( \
    Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_HwTrqScaleVal_VoltsPerDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32() \
  (&Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_HwTrqScaleVal_VoltsPerDeg_f32.value)

#  define Rte_IWrite_HwTrq_Init_T1TrimVal_Volt_f32(data) \
  ( \
    Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_T1TrimVal_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_HwTrq_Init_T1TrimVal_Volt_f32() \
  (&Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_T1TrimVal_Volt_f32.value)

#  define Rte_IWrite_HwTrq_Init_T2TrimVal_Volt_f32(data) \
  ( \
    Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_T2TrimVal_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_HwTrq_Init_T2TrimVal_Volt_f32() \
  (&Rte_Task_InitB_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Init.Rte_T2TrimVal_Volt_f32.value)

#  define Rte_IRead_HwTrq_Per1_AbsPosStepSignal_Cnt_u08() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_AbsPosStepSignal_Cnt_u08.value)

#  define Rte_IRead_HwTrq_Per1_T1ADC_Volt_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_T1ADC_Volt_f32.value)

#  define Rte_IRead_HwTrq_Per1_T2ADC_Volt_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_T2ADC_Volt_f32.value)

#  define Rte_IWrite_HwTrq_Per1_AnaDiffHwTrq_Volt_f32(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_AnaDiffHwTrq_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_HwTrq_Per1_AnaDiffHwTrq_Volt_f32() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_AnaDiffHwTrq_Volt_f32.value)

#  define Rte_IWrite_HwTrq_Per1_AnaHwTorque_HwNm_f32(data) \
  ( \
    Rte_Task_2ms_7.Rte_TB.Rte_I_HwTrq_AnaHwTorque_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_HwTrq_Per1_AnaHwTorque_HwNm_f32() \
  (&Rte_Task_2ms_7.Rte_TB.Rte_I_HwTrq_AnaHwTorque_HwNm_f32.value)

#  define Rte_IWrite_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum(data) \
  /* unconnected */

#  define Rte_IWriteRef_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_ErrorActiveAnalog_Cnt_enum.value)

#  define Rte_IWrite_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_SrlComHwTrqValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_SrlComHwTrqValid_Cnt_lgc.value)

#  define Rte_IWrite_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32(data) \
  ( \
    Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_SysCAnaHwTorque_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32() \
  (&Rte_Task_2ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per1.Rte_SysCAnaHwTorque_HwNm_f32.value)

#  define Rte_IRead_HwTrq_Per2_CntrlDisRampComplete_Cnt_lgc() \
  (Rte_Task_4ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per2.Rte_CntrlDisRampComplete_Cnt_lgc.value)

#  define Rte_IRead_HwTrq_Per2_SysCHwTorqueSqd_HwNmSq_f32() \
  (Rte_Task_4ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per2.Rte_SysCHwTorqueSqd_HwNmSq_f32.value)

#  define Rte_IRead_HwTrq_Per2_T1ADC_Volt_f32() \
  (Rte_Task_4ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per2.Rte_T1ADC_Volt_f32.value)

#  define Rte_IRead_HwTrq_Per2_T2ADC_Volt_f32() \
  (Rte_Task_4ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per2.Rte_T2ADC_Volt_f32.value)

#  define Rte_IRead_HwTrq_Per3_MECCounter_Cnt_enum() \
  (Rte_Task_100ms_7.Rte_RB.Rte_Sa_HwTrq_HwTrq_Per3.Rte_MECCounter_Cnt_enum.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_T1ADC_Volt_f32 Rte_Read_Sa_HwTrq_T1ADC_Volt_f32
#  define Rte_Read_Sa_HwTrq_T1ADC_Volt_f32(data) (*(data) = Rte_IoHwAb7_T1ADC_Volt_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_T2ADC_Volt_f32 Rte_Read_Sa_HwTrq_T2ADC_Volt_f32
#  define Rte_Read_Sa_HwTrq_T2ADC_Volt_f32(data) (*(data) = Rte_IoHwAb7_T2ADC_Volt_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwTrqScaleVal_VoltsPerDeg_f32 Rte_Write_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32
#  define Rte_Write_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32(data) (Rte_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_T1TrimVal_Volt_f32 Rte_Write_Sa_HwTrq_T1TrimVal_Volt_f32
#  define Rte_Write_Sa_HwTrq_T1TrimVal_Volt_f32(data) (Rte_HwTrq_T1TrimVal_Volt_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_T2TrimVal_Volt_f32 Rte_Write_Sa_HwTrq_T2TrimVal_Volt_f32
#  define Rte_Write_Sa_HwTrq_T2TrimVal_Volt_f32(data) (Rte_HwTrq_T2TrimVal_Volt_f32 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLTrqStep_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)5, arg1))
#  define RTE_START_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_FLTINJECTION_APPL_CODE) FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_FLTINJECTION_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
#  define RTE_STOP_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_FaultInjection_SCom_FltInjection(arg1, arg2) (FltInjection_SCom_FltInjection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_HwTrqScale_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)3, arg1))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(UInt8 parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_HwTrqTrim_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)4, arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_HwTrqTrim_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)4, arg1))
#  define RTE_START_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR7_APPL_CODE) NxtrDiagMgr7_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR7_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr7_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR7_APPL_CODE) NxtrDiagMgr7_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR7_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr7_GetNTCStatus
#  define RTE_START_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR7_APPL_CODE) NxtrDiagMgr7_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr7_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(EOLTrqStepType, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_EOLTrqStepData;
extern VAR(HwTrqScale_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_HwTrqScaleData;
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_HwTrqTrimData;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_EOLTrqStepData() (&((*RtePim_EOLTrqStepData())[0]))
#  else
#   define Rte_Pim_EOLTrqStepData() RtePim_EOLTrqStepData()
#  endif
#  define RtePim_EOLTrqStepData() \
  (&Rte_HwTrq_EOLTrqStepData)

#  define Rte_Pim_HwTrqScaleData() \
  (&Rte_HwTrq_HwTrqScaleData)

#  define Rte_Pim_HwTrqTrimData() \
  (&Rte_HwTrq_HwTrqTrimData)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_HWTRQ_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Init(void);

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per1(void);

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per2(void);

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per3(void);

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqScale(void);

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqTrim(void);

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadEOLTrqStep(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) TrqStep_HwNm_T_f32);
# else
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadEOLTrqStep(P2VAR(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) TrqStep_HwNm_T_f32);
# endif

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqScale(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqTrim(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# else
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# endif

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqScale(Float ScaleValue);

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqTrim(void);

# define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_HwTrq_SCom_ConditionsNotCorrect (20U)

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_HwTrq.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_HWTRQ_H */
