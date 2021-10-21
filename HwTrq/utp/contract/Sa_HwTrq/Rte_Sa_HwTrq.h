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
 *          File:  Rte_Sa_HwTrq.h
 *     Workspace:  C:/Synergy/01_Components/HwTrq-dzxvzg/HwTrq/autosar
 *     SW-C Type:  Sa_HwTrq
 *  Generated at:  Tue Dec 17 10:15:08 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_HwTrq> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_HWTRQ_H
# define _RTE_SA_HWTRQ_H

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

typedef P2CONST(struct Rte_CDS_Sa_HwTrq, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AbsPosStepSignal_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_AnaDiffHwTrq_Volt_f32 ((Float)0)
# define Rte_InitValue_AnaHwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_CntrlDisRampComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ErrorActiveAnalog_Cnt_enum ((HwTrqStatusType)0u)
# define Rte_InitValue_HwTrqScaleVal_VoltsPerDeg_f32 ((Float)0)
# define Rte_InitValue_MECCounter_Cnt_enum ((ManufModeType)0u)
# define Rte_InitValue_SrlComHwTrqValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SysCAnaHwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_SysCHwTorqueSqd_HwNmSq_f32 ((Float)0)
# define Rte_InitValue_T1ADC_Volt_f32 ((Float)0)
# define Rte_InitValue_T1TrimVal_Volt_f32 ((Float)0)
# define Rte_InitValue_T2ADC_Volt_f32 ((Float)0)
# define Rte_InitValue_T2TrimVal_Volt_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Sa_HwTrq_T1ADC_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Sa_HwTrq_T2ADC_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Sa_HwTrq_T1TrimVal_Volt_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Sa_HwTrq_T2TrimVal_Volt_f32(Float data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_EOLTrqStep_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_EOLTrqStep_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_FaultInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_HwTrqScale_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_HwTrqScale_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_HwTrqTrim_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) ErrorStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_HwTrqTrim_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_HwTrqTrim_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32(data) \
  ( \
  Rte_Inst_Sa_HwTrq->HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32() \
  (&Rte_Inst_Sa_HwTrq->HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32->value)

# define Rte_IWrite_HwTrq_Init_T1TrimVal_Volt_f32(data) \
  ( \
  Rte_Inst_Sa_HwTrq->HwTrq_Init_T1TrimVal_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_HwTrq_Init_T1TrimVal_Volt_f32() \
  (&Rte_Inst_Sa_HwTrq->HwTrq_Init_T1TrimVal_Volt_f32->value)

# define Rte_IWrite_HwTrq_Init_T2TrimVal_Volt_f32(data) \
  ( \
  Rte_Inst_Sa_HwTrq->HwTrq_Init_T2TrimVal_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_HwTrq_Init_T2TrimVal_Volt_f32() \
  (&Rte_Inst_Sa_HwTrq->HwTrq_Init_T2TrimVal_Volt_f32->value)

# define Rte_IRead_HwTrq_Per1_AbsPosStepSignal_Cnt_u08() \
  (Rte_Inst_Sa_HwTrq->HwTrq_Per1_AbsPosStepSignal_Cnt_u08->value)

# define Rte_IRead_HwTrq_Per1_T1ADC_Volt_f32() \
  (Rte_Inst_Sa_HwTrq->HwTrq_Per1_T1ADC_Volt_f32->value)

# define Rte_IRead_HwTrq_Per1_T2ADC_Volt_f32() \
  (Rte_Inst_Sa_HwTrq->HwTrq_Per1_T2ADC_Volt_f32->value)

# define Rte_IWrite_HwTrq_Per1_AnaDiffHwTrq_Volt_f32(data) \
  ( \
  Rte_Inst_Sa_HwTrq->HwTrq_Per1_AnaDiffHwTrq_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_HwTrq_Per1_AnaDiffHwTrq_Volt_f32() \
  (&Rte_Inst_Sa_HwTrq->HwTrq_Per1_AnaDiffHwTrq_Volt_f32->value)

# define Rte_IWrite_HwTrq_Per1_AnaHwTorque_HwNm_f32(data) \
  ( \
  Rte_Inst_Sa_HwTrq->HwTrq_Per1_AnaHwTorque_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_HwTrq_Per1_AnaHwTorque_HwNm_f32() \
  (&Rte_Inst_Sa_HwTrq->HwTrq_Per1_AnaHwTorque_HwNm_f32->value)

# define Rte_IWrite_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum(data) \
  ( \
  Rte_Inst_Sa_HwTrq->HwTrq_Per1_ErrorActiveAnalog_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum() \
  (&Rte_Inst_Sa_HwTrq->HwTrq_Per1_ErrorActiveAnalog_Cnt_enum->value)

# define Rte_IWrite_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_HwTrq->HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc() \
  (&Rte_Inst_Sa_HwTrq->HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc->value)

# define Rte_IWrite_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32(data) \
  ( \
  Rte_Inst_Sa_HwTrq->HwTrq_Per1_SysCAnaHwTorque_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32() \
  (&Rte_Inst_Sa_HwTrq->HwTrq_Per1_SysCAnaHwTorque_HwNm_f32->value)

# define Rte_IRead_HwTrq_Per2_CntrlDisRampComplete_Cnt_lgc() \
  (Rte_Inst_Sa_HwTrq->HwTrq_Per2_CntrlDisRampComplete_Cnt_lgc->value)

# define Rte_IRead_HwTrq_Per2_SysCHwTorqueSqd_HwNmSq_f32() \
  (Rte_Inst_Sa_HwTrq->HwTrq_Per2_SysCHwTorqueSqd_HwNmSq_f32->value)

# define Rte_IRead_HwTrq_Per2_T1ADC_Volt_f32() \
  (Rte_Inst_Sa_HwTrq->HwTrq_Per2_T1ADC_Volt_f32->value)

# define Rte_IRead_HwTrq_Per2_T2ADC_Volt_f32() \
  (Rte_Inst_Sa_HwTrq->HwTrq_Per2_T2ADC_Volt_f32->value)

# define Rte_IRead_HwTrq_Per3_MECCounter_Cnt_enum() \
  (Rte_Inst_Sa_HwTrq->HwTrq_Per3_MECCounter_Cnt_enum->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_T1ADC_Volt_f32 Rte_Read_Sa_HwTrq_T1ADC_Volt_f32
# define Rte_Read_T2ADC_Volt_f32 Rte_Read_Sa_HwTrq_T2ADC_Volt_f32


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTrqScaleVal_VoltsPerDeg_f32 Rte_Write_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32
# define Rte_Write_T1TrimVal_Volt_f32 Rte_Write_Sa_HwTrq_T1TrimVal_Volt_f32
# define Rte_Write_T2TrimVal_Volt_f32 Rte_Write_Sa_HwTrq_T2TrimVal_Volt_f32


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLTrqStep_WriteBlock Rte_Call_Sa_HwTrq_EOLTrqStep_WriteBlock
# define Rte_Call_FaultInjection_SCom_FltInjection Rte_Call_Sa_HwTrq_FaultInjection_SCom_FltInjection
# define Rte_Call_HwTrqScale_WriteBlock Rte_Call_Sa_HwTrq_HwTrqScale_WriteBlock
# define Rte_Call_HwTrqTrim_GetErrorStatus Rte_Call_Sa_HwTrq_HwTrqTrim_GetErrorStatus
# define Rte_Call_HwTrqTrim_WriteBlock Rte_Call_Sa_HwTrq_HwTrqTrim_WriteBlock
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_GetNTCStatus Rte_Call_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_EOLTrqStepData() (*Rte_Inst_Sa_HwTrq->Pim_EOLTrqStepData)
# else
#  define Rte_Pim_EOLTrqStepData() (Rte_Inst_Sa_HwTrq->Pim_EOLTrqStepData)
# endif

# define Rte_Pim_HwTrqScaleData() (Rte_Inst_Sa_HwTrq->Pim_HwTrqScaleData)

# define Rte_Pim_HwTrqTrimData() (Rte_Inst_Sa_HwTrq->Pim_HwTrqTrimData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Float *Rte_Pim_EOLTrqStepData(void)
# else
 *   EOLTrqStepType *Rte_Pim_EOLTrqStepData(void)
# endif
 *   HwTrqScale_Datatype *Rte_Pim_HwTrqScaleData(void)
 *   HwTrqTrim_Datatype *Rte_Pim_HwTrqTrimData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_SA_HWTRQ_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Init_HwTrqScaleVal_VoltsPerDeg_f32(void)
 *   void Rte_IWrite_HwTrq_Init_T1TrimVal_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Init_T1TrimVal_Volt_f32(void)
 *   void Rte_IWrite_HwTrq_Init_T2TrimVal_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Init_T2TrimVal_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTrqTrim_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt8 Rte_IRead_HwTrq_Per1_AbsPosStepSignal_Cnt_u08(void)
 *   Float Rte_IRead_HwTrq_Per1_T1ADC_Volt_f32(void)
 *   Float Rte_IRead_HwTrq_Per1_T2ADC_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwTrq_Per1_AnaDiffHwTrq_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Per1_AnaDiffHwTrq_Volt_f32(void)
 *   void Rte_IWrite_HwTrq_Per1_AnaHwTorque_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Per1_AnaHwTorque_HwNm_f32(void)
 *   void Rte_IWrite_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum(HwTrqStatusType data)
 *   HwTrqStatusType *Rte_IWriteRef_HwTrq_Per1_ErrorActiveAnalog_Cnt_enum(void)
 *   void Rte_IWrite_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HwTrq_Per1_SrlComHwTrqValid_Cnt_lgc(void)
 *   void Rte_IWrite_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_HwTrq_Per1_SysCAnaHwTorque_HwNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_HwTrq_Per2_CntrlDisRampComplete_Cnt_lgc(void)
 *   Float Rte_IRead_HwTrq_Per2_SysCHwTorqueSqd_HwNmSq_f32(void)
 *   Float Rte_IRead_HwTrq_Per2_T1ADC_Volt_f32(void)
 *   Float Rte_IRead_HwTrq_Per2_T2ADC_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   ManufModeType Rte_IRead_HwTrq_Per3_MECCounter_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ClrHwTrqScale
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqScale> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTrqScaleVal_VoltsPerDeg_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqScale_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_HwTrqScale_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_ClrHwTrqScale(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqScale(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ClrHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_T1TrimVal_Volt_f32(Float data)
 *   Std_ReturnType Rte_Write_T2TrimVal_Volt_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_ClrHwTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqTrim(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ManualSetHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualSetHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_T1TrimVal_Volt_f32(Float data)
 *   Std_ReturnType Rte_Write_T2TrimVal_Volt_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_ManualSetHwTrqTrim(const HwTrqTrim_Datatype *HwTrqTrimDataPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ReadEOLTrqStep
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadEOLTrqStep> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void HwTrq_SCom_ReadEOLTrqStep(Float *TrqStep_HwNm_T_f32)
# else
 *   void HwTrq_SCom_ReadEOLTrqStep(EOLTrqStepType *TrqStep_HwNm_T_f32)
# endif
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadEOLTrqStep(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) TrqStep_HwNm_T_f32);
# else
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadEOLTrqStep(P2VAR(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) TrqStep_HwNm_T_f32);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ReadHwTrqScale
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadHwTrqScale> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTrq_SCom_ReadHwTrqScale(HwTrqScale_Datatype *HwTrqScaleDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqScale(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ReadHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTrq_SCom_ReadHwTrqTrim(HwTrqTrim_Datatype *HwTrqTrimDatPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqTrim(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetEOLTrqStep
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLTrqStep> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLTrqStep_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLTrqStep_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void HwTrq_SCom_SetEOLTrqStep(const Float *TrqStep_HwNm_T_f32)
# else
 *   void HwTrq_SCom_SetEOLTrqStep(const EOLTrqStepType *TrqStep_HwNm_T_f32)
# endif
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# else
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetHwTrqScale
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqScale> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTrqScaleVal_VoltsPerDeg_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqScale_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_HwTrqScale_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_SetHwTrqScale(Float ScaleValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqScale(Float ScaleValue);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_T1ADC_Volt_f32(Float *data)
 *   Std_ReturnType Rte_Read_T2ADC_Volt_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_T1TrimVal_Volt_f32(Float data)
 *   Std_ReturnType Rte_Write_T2TrimVal_Volt_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_HwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType HwTrq_SCom_SetHwTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqTrim(void);

# define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_HwTrq_SCom_ConditionsNotCorrect (20u)

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1387297287
#    error "The magic number of the generated file <C:/Synergy/01_Components/HwTrq-dzxvzg/HwTrq/utp/contract/Sa_HwTrq/Rte_Sa_HwTrq.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1387297287
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_HWTRQ_H */
