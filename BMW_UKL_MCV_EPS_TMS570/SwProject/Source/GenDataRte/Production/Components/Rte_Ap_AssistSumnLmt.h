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
 *          File:  Components/Rte_Ap_AssistSumnLmt.h
 *     Workspace:  C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu May 25 16:44:04 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ASSISTSUMNLMT_H
# define _RTE_AP_ASSISTSUMNLMT_H

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

#  define Rte_InitValue_AssistCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_AssistPowerLimit_MtrNm_f32 (8.8F)
#  define Rte_InitValue_CombinedDamping_MtrNm_f32 (0.0F)
#  define Rte_InitValue_DefeatLimitService_Cnt_lgc (FALSE)
#  define Rte_InitValue_EOTDampingLtd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_EOTGainLtd_Uls_f32 (1.0F)
#  define Rte_InitValue_EOTLimitLtd_MtrNm_f32 (8.8F)
#  define Rte_InitValue_LimitPercentFiltered_Uls_f32 (0.0F)
#  define Rte_InitValue_LimitedReturn_MtrNm_f32 (0.0F)
#  define Rte_InitValue_LrnPnCtrDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_LrnPnCtrEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_LrnPnCtrTCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_OutpTqOvrl_MtrNm_f32 (0.0F)
#  define Rte_InitValue_OutputRampMultLtd_Uls_f32 (0.0F)
#  define Rte_InitValue_PostLimitTorque_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PowerLimitPerc_Uls_f32 (0.0F)
#  define Rte_InitValue_PreLimitForPower_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PreLimitForStall_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PreLimitTorque_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PrkAssistCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PrkAssistDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PullCompCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_StallLimitLtd_MtrNm_f32 (8.8F)
#  define Rte_InitValue_ThermLimitPerc_Uls_f32 (0.0F)
#  define Rte_InitValue_ThermalLimitLtd_MtrNm_f32 (8.8F)
#  define Rte_InitValue_TrqOscCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_VehSpdLimitLtd_MtrNm_f32 (8.8F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_WhlImbRejCmd_MtrNm_f32 (0.0F)
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

#  define Rte_IRead_AssistSumnLmt_Per1_AssistCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_AssistCmd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_AssistPowerLimit_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_AssistPowerLimit_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_CombinedDamping_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_CombinedDamping_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_DefeatLimitService_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_DefeatLimitService_Cnt_lgc.value)

#  define Rte_IRead_AssistSumnLmt_Per1_EOTDampingLtd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_EOTDampingLtd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_EOTGainLtd_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_EOTGainLtd_Uls_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_EOTLimitLtd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_EOTLimitLtd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_LimitedReturn_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_LimitedReturn_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrDisable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_LrnPnCtrDisable_Cnt_lgc.value)

#  define Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_LrnPnCtrEnable_Cnt_lgc.value)

#  define Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrTCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_LrnPnCtrTCmd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_OutpTqOvrl_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_OutpTqOvrl_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_OutputRampMultLtd_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_OutputRampMultLtd_Uls_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_PrkAssistCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PrkAssistCmd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_PrkAssistDisable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PrkAssistDisable_Cnt_lgc.value)

#  define Rte_IRead_AssistSumnLmt_Per1_PullCompCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PullCompCmd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_StallLimitLtd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_StallLimitLtd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_ThermalLimitLtd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_ThermalLimitLtd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_TrqOscCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_TrqOscCmd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_VehSpdLimitLtd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_VehSpdLimitLtd_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per1_WhlImbRejCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_WhlImbRejCmd_MtrNm_f32.value)

#  define Rte_IWrite_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PostLimitTorque_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PostLimitTorque_MtrNm_f32.value)

#  define Rte_IWrite_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitForPower_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitForPower_MtrNm_f32.value)

#  define Rte_IWrite_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitForStall_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitForStall_MtrNm_f32.value)

#  define Rte_IWrite_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitTorque_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1.Rte_PreLimitTorque_MtrNm_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per2_PowerLimitPerc_Uls_f32() \
  (Rte_Task_10msB_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2.Rte_PowerLimitPerc_Uls_f32.value)

#  define Rte_IRead_AssistSumnLmt_Per2_ThermLimitPerc_Uls_f32() \
  (Rte_Task_10msB_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2.Rte_ThermLimitPerc_Uls_f32.value)

#  define Rte_IWrite_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32(data) \
  ( \
    Rte_Task_10msB_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2.Rte_LimitPercentFiltered_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32() \
  (&Rte_Task_10msB_10.Rte_RB.Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2.Rte_LimitPercentFiltered_Uls_f32.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_FLTINJECTION_APPL_CODE) FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_FLTINJECTION_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
#  define RTE_STOP_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_FaultInjection_SCom_FltInjection(arg1, arg2) (FltInjection_SCom_FltInjection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_ASSISTSUMNLMT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Init1(void);

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Per1(void);

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Per2(void);

# define RTE_STOP_SEC_AP_ASSISTSUMNLMT_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_AssistSumnLmt.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ASSISTSUMNLMT_H */
