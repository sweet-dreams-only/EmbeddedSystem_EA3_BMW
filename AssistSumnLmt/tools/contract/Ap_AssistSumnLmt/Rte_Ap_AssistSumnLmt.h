/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_AssistSumnLmt.h
 *     Workspace:  C:/EA3 Component/AssistSumnLmt/autosar
 *     SW-C Type:  Ap_AssistSumnLmt
 *  Generated at:  Thu May 11 10:26:31 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_AssistSumnLmt> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ASSISTSUMNLMT_H
# define _RTE_AP_ASSISTSUMNLMT_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Ap_AssistSumnLmt, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_AssistPowerLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_CombinedDamping_MtrNm_f32 ((Float)0)
# define Rte_InitValue_DefeatLimitService_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EOTDampingLtd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_EOTGainLtd_Uls_f32 ((Float)1)
# define Rte_InitValue_EOTLimitLtd_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_LimitPercentFiltered_Uls_f32 ((Float)0)
# define Rte_InitValue_LimitedReturn_MtrNm_f32 ((Float)0)
# define Rte_InitValue_LrnPnCtrDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LrnPnCtrEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LrnPnCtrTCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_OutpTqOvrl_MtrNm_f32 ((Float)0)
# define Rte_InitValue_OutputRampMultLtd_Uls_f32 ((Float)0)
# define Rte_InitValue_PostLimitTorque_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PowerLimitPerc_Uls_f32 ((Float)0)
# define Rte_InitValue_PreLimitForPower_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PreLimitForStall_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PreLimitTorque_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PrkAssistCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PrkAssistDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PullCompCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_StallLimitLtd_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_ThermLimitPerc_Uls_f32 ((Float)0)
# define Rte_InitValue_ThermalLimitLtd_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_TrqOscCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehSpdLimitLtd_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_WhlImbRejCmd_MtrNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_AssistSumnLmt_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AssistSumnLmt_FaultInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_ASSISTSUMNLMT_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_AssistSumnLmt_Per1_AssistCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_AssistCmd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_AssistPowerLimit_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_AssistPowerLimit_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_CombinedDamping_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_CombinedDamping_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_DefeatLimitService_Cnt_lgc() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_DefeatLimitService_Cnt_lgc->value)

# define Rte_IRead_AssistSumnLmt_Per1_EOTDampingLtd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_EOTDampingLtd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_EOTGainLtd_Uls_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_EOTGainLtd_Uls_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_EOTLimitLtd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_EOTLimitLtd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_LimitedReturn_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_LimitedReturn_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrDisable_Cnt_lgc() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_LrnPnCtrDisable_Cnt_lgc->value)

# define Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrEnable_Cnt_lgc() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_LrnPnCtrEnable_Cnt_lgc->value)

# define Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrTCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_LrnPnCtrTCmd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_OutpTqOvrl_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_OutpTqOvrl_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_OutputRampMultLtd_Uls_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_OutputRampMultLtd_Uls_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_PrkAssistCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PrkAssistCmd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_PrkAssistDisable_Cnt_lgc() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PrkAssistDisable_Cnt_lgc->value)

# define Rte_IRead_AssistSumnLmt_Per1_PullCompCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PullCompCmd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_StallLimitLtd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_StallLimitLtd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_ThermalLimitLtd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_ThermalLimitLtd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_TrqOscCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_TrqOscCmd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_VehSpdLimitLtd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_VehSpdLimitLtd_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IRead_AssistSumnLmt_Per1_WhlImbRejCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_WhlImbRejCmd_MtrNm_f32->value)

# define Rte_IWrite_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32() \
  (&Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32->value)

# define Rte_IWrite_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32() \
  (&Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32->value)

# define Rte_IWrite_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32() \
  (&Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32->value)

# define Rte_IWrite_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32() \
  (&Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32->value)

# define Rte_IRead_AssistSumnLmt_Per2_PowerLimitPerc_Uls_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per2_PowerLimitPerc_Uls_f32->value)

# define Rte_IRead_AssistSumnLmt_Per2_ThermLimitPerc_Uls_f32() \
  (Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per2_ThermLimitPerc_Uls_f32->value)

# define Rte_IWrite_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32() \
  (&Rte_Inst_Ap_AssistSumnLmt->AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_AssistSumnLmt_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FaultInjection_SCom_FltInjection Rte_Call_Ap_AssistSumnLmt_FaultInjection_SCom_FltInjection




# define RTE_START_SEC_AP_ASSISTSUMNLMT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistLmtFunc_Scom_ManualTrqCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualTrqCmd> of PortPrototype <AssistLmtFunc_Scom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistSumnLmt_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistSumnLmt_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AssistSumnLmt_Per1_AssistCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_AssistPowerLimit_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_CombinedDamping_MtrNm_f32(void)
 *   Boolean Rte_IRead_AssistSumnLmt_Per1_DefeatLimitService_Cnt_lgc(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_EOTDampingLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_EOTGainLtd_Uls_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_EOTLimitLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_LimitedReturn_MtrNm_f32(void)
 *   Boolean Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrDisable_Cnt_lgc(void)
 *   Boolean Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrEnable_Cnt_lgc(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_LrnPnCtrTCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_OutpTqOvrl_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_OutputRampMultLtd_Uls_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_PrkAssistCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_AssistSumnLmt_Per1_PrkAssistDisable_Cnt_lgc(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_PullCompCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_StallLimitLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_ThermalLimitLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_TrqOscCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_VehSpdLimitLtd_MtrNm_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_VehicleSpeed_Kph_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per1_WhlImbRejCmd_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per1_PostLimitTorque_MtrNm_f32(void)
 *   void Rte_IWrite_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitForPower_MtrNm_f32(void)
 *   void Rte_IWrite_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitForStall_MtrNm_f32(void)
 *   void Rte_IWrite_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per1_PreLimitTorque_MtrNm_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistSumnLmt_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AssistSumnLmt_Per2_PowerLimitPerc_Uls_f32(void)
 *   Float Rte_IRead_AssistSumnLmt_Per2_ThermLimitPerc_Uls_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AssistSumnLmt_Per2_LimitPercentFiltered_Uls_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistSumnLmt_Per2(void);

# define RTE_STOP_SEC_AP_ASSISTSUMNLMT_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1494509955
#    error "The magic number of the generated file <C:/EA3 Component/AssistSumnLmt/tools/contract/Ap_AssistSumnLmt/Rte_Ap_AssistSumnLmt.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1494509955
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ASSISTSUMNLMT_H */
