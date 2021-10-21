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
 *          File:  Rte_Ap_BatteryVoltage.h
 *     Workspace:  C:/SynergyWorkArea/CBD_BatteryVoltage/BatteryVoltage/autosar
 *     SW-C Type:  Ap_BatteryVoltage
 *  Generated at:  Mon Oct 29 11:24:14 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_BatteryVoltage> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_BATTERYVOLTAGE_H
# define _RTE_AP_BATTERYVOLTAGE_H

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

typedef P2CONST(struct Rte_CDS_Ap_BatteryVoltage, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_Batt_Volt_f32 ((Float)0)
# define Rte_InitValue_BattSwitched_Volt_f32 ((Float)0)
# define Rte_InitValue_SysCVSwitch_Volt_f32 ((Float)0)
# define Rte_InitValue_SysC_Vecu_Volt_f32 ((Float)5)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)
# define Rte_InitValue_VswitchClosed_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_BatteryVoltage_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_BatteryVoltage_FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_BatteryVoltage_Per1_BattSwitched_Volt_f32() \
  (Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per1_BattSwitched_Volt_f32->value)

# define Rte_IRead_BatteryVoltage_Per1_Batt_Volt_f32() \
  (Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per1_Batt_Volt_f32->value)

# define Rte_IWrite_BatteryVoltage_Per1_SysC_Vecu_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per1_SysC_Vecu_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_BatteryVoltage_Per1_SysC_Vecu_Volt_f32() \
  (&Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per1_SysC_Vecu_Volt_f32->value)

# define Rte_IWrite_BatteryVoltage_Per1_Vecu_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per1_Vecu_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_BatteryVoltage_Per1_Vecu_Volt_f32() \
  (&Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per1_Vecu_Volt_f32->value)

# define Rte_IWrite_BatteryVoltage_Per1_VswitchClosed_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per1_VswitchClosed_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BatteryVoltage_Per1_VswitchClosed_Cnt_lgc() \
  (&Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per1_VswitchClosed_Cnt_lgc->value)

# define Rte_IRead_BatteryVoltage_Per2_BattSwitched_Volt_f32() \
  (Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per2_BattSwitched_Volt_f32->value)

# define Rte_IRead_BatteryVoltage_Per2_Batt_Volt_f32() \
  (Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per2_Batt_Volt_f32->value)

# define Rte_IRead_BatteryVoltage_Per2_SysCVSwitch_Volt_f32() \
  (Rte_Inst_Ap_BatteryVoltage->BatteryVoltage_Per2_SysCVSwitch_Volt_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_BatteryVoltage_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FltInjection_SCom_FltInjection Rte_Call_Ap_BatteryVoltage_FltInjection_SCom_FltInjection
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_BATTERYVOLTAGE_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BatteryVoltage_Per1
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
 *   Float Rte_IRead_BatteryVoltage_Per1_BattSwitched_Volt_f32(void)
 *   Float Rte_IRead_BatteryVoltage_Per1_Batt_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BatteryVoltage_Per1_SysC_Vecu_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_BatteryVoltage_Per1_SysC_Vecu_Volt_f32(void)
 *   void Rte_IWrite_BatteryVoltage_Per1_Vecu_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_BatteryVoltage_Per1_Vecu_Volt_f32(void)
 *   void Rte_IWrite_BatteryVoltage_Per1_VswitchClosed_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BatteryVoltage_Per1_VswitchClosed_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BATTERYVOLTAGE_APPL_CODE) BatteryVoltage_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BatteryVoltage_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *     and not in Mode(s) <WARMINIT, OFF, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_BatteryVoltage_Per2_BattSwitched_Volt_f32(void)
 *   Float Rte_IRead_BatteryVoltage_Per2_Batt_Volt_f32(void)
 *   Float Rte_IRead_BatteryVoltage_Per2_SysCVSwitch_Volt_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BATTERYVOLTAGE_APPL_CODE) BatteryVoltage_Per2(void);

# define RTE_STOP_SEC_AP_BATTERYVOLTAGE_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1351520585
#    error "The magic number of the generated file <C:/SynergyWorkArea/CBD_BatteryVoltage/BatteryVoltage/utp/contract/Ap_BatteryVoltage/Rte_Ap_BatteryVoltage.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1351520585
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_BATTERYVOLTAGE_H */
