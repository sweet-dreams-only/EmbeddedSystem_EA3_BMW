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
 *          File:  Rte_Sa_BkCpPc.h
 *     Workspace:  C:/_Synergy_Projects/Working/BkCpPc-nz63rn/BkCpPc/autosar
 *     SW-C Type:  Sa_BkCpPc
 *  Generated at:  Fri Nov  1 11:45:21 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_BkCpPc> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_BKCPPC_H
# define _RTE_SA_BKCPPC_H

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

typedef P2CONST(struct Rte_CDS_Sa_BkCpPc, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_Batt_Volt_f32 ((Float)0)
# define Rte_InitValue_BattSwitched_Volt_f32 ((Float)0)
# define Rte_InitValue_MotorVelocityMRFUnfiltered_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_OVERRIDESIGDIAGADC_Volt_f32 ((Float)0)
# define Rte_InitValue_PMOSDIAGADC_Volt_f32 ((Float)0)
# define Rte_InitValue_PwrDiscATestComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PwrDiscATestStart_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PwrDiscBTestComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PwrDiscBTestStart_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PwrDiscClosed_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Sa_BkCpPc_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_BkCpPc_PhyCapDischarge_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_BkCpPc_PhyCapPrecharge_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_BKCPPC_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_SA_BKCPPC_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_BkCpPc_Per1_BattSwitched_Volt_f32() \
  (Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_BattSwitched_Volt_f32->value)

# define Rte_IRead_BkCpPc_Per1_Batt_Volt_f32() \
  (Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_Batt_Volt_f32->value)

# define Rte_IRead_BkCpPc_Per1_MotorVelocityMRFUnfiltered_MtrRadpS_f32() \
  (Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_MotorVelocityMRFUnfiltered_MtrRadpS_f32->value)

# define Rte_IRead_BkCpPc_Per1_OVERRIDESIGDIAGADC_Volt_f32() \
  (Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_OVERRIDESIGDIAGADC_Volt_f32->value)

# define Rte_IRead_BkCpPc_Per1_PMOSDIAGADC_Volt_f32() \
  (Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PMOSDIAGADC_Volt_f32->value)

# define Rte_IRead_BkCpPc_Per1_PwrDiscATestStart_Cnt_lgc() \
  (Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PwrDiscATestStart_Cnt_lgc->value)

# define Rte_IRead_BkCpPc_Per1_PwrDiscBTestStart_Cnt_lgc() \
  (Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PwrDiscBTestStart_Cnt_lgc->value)

# define Rte_IWrite_BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc() \
  (&Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc->value)

# define Rte_IWrite_BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc() \
  (&Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc->value)

# define Rte_IWrite_BkCpPc_Per1_PwrDiscClosed_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PwrDiscClosed_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BkCpPc_Per1_PwrDiscClosed_Cnt_lgc() \
  (&Rte_Inst_Sa_BkCpPc->BkCpPc_Per1_PwrDiscClosed_Cnt_lgc->value)

# define Rte_IWrite_BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_BkCpPc->BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc() \
  (&Rte_Inst_Sa_BkCpPc->BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc->value)

# define Rte_IWrite_BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_BkCpPc->BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc() \
  (&Rte_Inst_Sa_BkCpPc->BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc->value)

# define Rte_IWrite_BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_BkCpPc->BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc() \
  (&Rte_Inst_Sa_BkCpPc->BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc->value)

# define Rte_IWrite_BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_BkCpPc->BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc() \
  (&Rte_Inst_Sa_BkCpPc->BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc->value)

# define Rte_IWrite_BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_BkCpPc->BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc() \
  (&Rte_Inst_Sa_BkCpPc->BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Sa_BkCpPc_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_PhyCapDischarge_OP_SET Rte_Call_Sa_BkCpPc_PhyCapDischarge_OP_SET
# define Rte_Call_PhyCapPrecharge_OP_SET Rte_Call_Sa_BkCpPc_PhyCapPrecharge_OP_SET
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_SA_BKCPPC_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BkCpPc_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_BkCpPc_Per1_BattSwitched_Volt_f32(void)
 *   Float Rte_IRead_BkCpPc_Per1_Batt_Volt_f32(void)
 *   Float Rte_IRead_BkCpPc_Per1_MotorVelocityMRFUnfiltered_MtrRadpS_f32(void)
 *   Float Rte_IRead_BkCpPc_Per1_OVERRIDESIGDIAGADC_Volt_f32(void)
 *   Float Rte_IRead_BkCpPc_Per1_PMOSDIAGADC_Volt_f32(void)
 *   Boolean Rte_IRead_BkCpPc_Per1_PwrDiscATestStart_Cnt_lgc(void)
 *   Boolean Rte_IRead_BkCpPc_Per1_PwrDiscBTestStart_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Per1_PwrDiscClosed_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Per1_PwrDiscClosed_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_PhyCapDischarge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *   Std_ReturnType Rte_Call_PhyCapPrecharge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_BKCPPC_APPL_CODE) BkCpPc_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BkCpPc_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <DISABLE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_PhyCapDischarge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *   Std_ReturnType Rte_Call_PhyCapPrecharge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_BKCPPC_APPL_CODE) BkCpPc_Trns1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BkCpPc_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <WARMINIT> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_PhyCapDischarge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *   Std_ReturnType Rte_Call_PhyCapPrecharge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_BKCPPC_APPL_CODE) BkCpPc_Trns2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CapPcDcStub_OP_SET
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <OP_SET> of PortPrototype <CapPcDcStub>
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
 *   Std_ReturnType CapPcDcStub_OP_SET(IoHwAb_BoolType signal)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DigitalOut_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_BKCPPC_APPL_CODE) CapPcDcStub_OP_SET(IoHwAb_BoolType signal);

# define RTE_STOP_SEC_SA_BKCPPC_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_DigitalOut_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1383323444
#    error "The magic number of the generated file <C:/_Synergy_Projects/Working/BkCpPc-nz63rn/BkCpPc/utp/contract/Sa_BkCpPc/Rte_Sa_BkCpPc.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1383323444
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_BKCPPC_H */
