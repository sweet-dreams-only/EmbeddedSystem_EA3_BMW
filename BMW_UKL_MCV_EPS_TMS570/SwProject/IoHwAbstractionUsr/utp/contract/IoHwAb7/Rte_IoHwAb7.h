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
 *          File:  Rte_IoHwAb7.h
 *     Workspace:  C:/ccm_wa/EPS/570/I410/BMW_UKL_MCV_EPS_TMS570/SwProject/IoHwAbstractionUsr/autosar
 *     SW-C Type:  IoHwAb7
 *  Generated at:  Mon Feb  4 11:22:47 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <IoHwAb7> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_IOHWAB7_H
# define _RTE_IOHWAB7_H

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

typedef P2CONST(struct Rte_CDS_IoHwAb7, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ADCMtrCurr1_Volt_f32 ((Float)0)
# define Rte_InitValue_Batt_Volt_f32 ((Float)0)
# define Rte_InitValue_BattSwitched_Volt_f32 ((Float)0)
# define Rte_InitValue_InvCos2Scaled_Volt_f32 ((Float)0)
# define Rte_InitValue_InvSin2Scaled_Volt_f32 ((Float)0)
# define Rte_InitValue_PDChrgPmpFdbkADC_Volt_f32 ((Float)0)
# define Rte_InitValue_PDSuplFdbkADC_Volt_f32 ((Float)0)
# define Rte_InitValue_SysCT1ADC_Volt_f32 ((Float)0)
# define Rte_InitValue_SysCT2ADC_Volt_f32 ((Float)0)
# define Rte_InitValue_SysCVSwitch_Volt_f32 ((Float)0)
# define Rte_InitValue_T1ADC_Volt_f32 ((Float)0)
# define Rte_InitValue_T2ADC_Volt_f32 ((Float)0)
# define Rte_InitValue_TemperatureADC_Volt_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IoHwAb7_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IoHwAb7_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB7_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IoHwAb7_SystemTime_GetSystemTime_uS_u32(P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB7_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FdbkPathAdc_Batt_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_Batt_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FdbkPathAdc_Batt_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_Batt_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FwdPathAdc_T1ADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_T1ADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FwdPathAdc_T1ADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_T1ADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_FwdPathAdc_T2ADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_T2ADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_FwdPathAdc_T2ADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_FwdPathAdc_T2ADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_ADCMtrCurr1_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_ADCMtrCurr1_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_ADCMtrCurr1_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_ADCMtrCurr1_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_BattSwitched_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_BattSwitched_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_BattSwitched_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_BattSwitched_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_Batt_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_Batt_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_Batt_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_Batt_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_InvCos2Scaled_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_InvCos2Scaled_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_InvCos2Scaled_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_InvCos2Scaled_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_InvSin2Scaled_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_InvSin2Scaled_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_InvSin2Scaled_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_InvSin2Scaled_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_PDSuplFdbkADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_PDSuplFdbkADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_PDSuplFdbkADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_PDSuplFdbkADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_SysCT1ADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_SysCT1ADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_SysCT1ADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_SysCT1ADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_SysCT2ADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_SysCT2ADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_SysCT2ADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_SysCT2ADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_SysCVSwitch_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_SysCVSwitch_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_SysCVSwitch_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_SysCVSwitch_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_T1ADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_T1ADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_T1ADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_T1ADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_T2ADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_T2ADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_T2ADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_T2ADC_Volt_f32->value)

# define Rte_IWrite_IoHwAb7_Init_TemperatureADC_Volt_f32(data) \
  ( \
  Rte_Inst_IoHwAb7->IoHwAb7_Init_TemperatureADC_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_IoHwAb7_Init_TemperatureADC_Volt_f32() \
  (&Rte_Inst_IoHwAb7->IoHwAb7_Init_TemperatureADC_Volt_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_IoHwAb7_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16 Rte_Call_IoHwAb7_SystemTime_DtrmnElapsedTime_uS_u16
# define Rte_Call_SystemTime_GetSystemTime_uS_u32 Rte_Call_IoHwAb7_SystemTime_GetSystemTime_uS_u32




# define RTE_START_SEC_IOHWAB7_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb7_FdbkPathAdc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_BattSwitched_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_InvCos2Scaled_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_InvSin2Scaled_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_PDChrgPmpFdbkADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_PDSuplFdbkADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_SysCVSwitch_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FdbkPathAdc_TemperatureADC_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB7_APPL_CODE) IoHwAb7_FdbkPathAdc(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb7_FwdPathAdc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_ADCMtrCurr1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_SysCT1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_SysCT2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_T1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_T1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_FwdPathAdc_T2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_FwdPathAdc_T2ADC_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB7_APPL_CODE) IoHwAb7_FwdPathAdc(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb7_Init
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
 *   void Rte_IWrite_IoHwAb7_Init_ADCMtrCurr1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_ADCMtrCurr1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_BattSwitched_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_BattSwitched_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_InvCos2Scaled_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_InvCos2Scaled_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_InvSin2Scaled_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_InvSin2Scaled_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_PDChrgPmpFdbkADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_PDSuplFdbkADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_PDSuplFdbkADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_SysCT1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_SysCT1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_SysCT2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_SysCT2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_SysCVSwitch_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_SysCVSwitch_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_T1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_T1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_T2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_T2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb7_Init_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb7_Init_TemperatureADC_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB7_APPL_CODE) IoHwAb7_Init(void);

# define RTE_STOP_SEC_IOHWAB7_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1359995282
#    error "The magic number of the generated file <C:/ccm_wa/EPS/570/I410/BMW_UKL_MCV_EPS_TMS570/SwProject/IoHwAbstractionUsr/utp/contract/IoHwAb7/Rte_IoHwAb7.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1359995282
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_IOHWAB7_H */
