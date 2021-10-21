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
 *          File:  Rte_Ap_PwrLmtFunc.h
 *     Workspace:  C:/SynergyWorkArea/Working/PwrLmtFunc-czmgrw/PwrLmtFunc/autosar
 *     SW-C Type:  Ap_PwrLmtFunc
 *  Generated at:  Thu Jan 29 13:58:59 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_PwrLmtFunc> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PWRLMTFUNC_H
# define _RTE_AP_PWRLMTFUNC_H

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

typedef P2CONST(struct Rte_CDS_Ap_PwrLmtFunc, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistPowerLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_CCLMSAActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_CustCurrLmt_Amp_f32 ((Float)0)
# define Rte_InitValue_KeEstimate_VpRadpS_f32 ((Float)0)
# define Rte_InitValue_MotorVelocityMRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MtrEnvSpd_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_PosServEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PowerLimitPerc_Uls_f32 ((Float)0)
# define Rte_InitValue_PreLimitForPwr_MtrNm_f32 ((Float)0)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_PwrLmtFunc_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PwrLmtFunc_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_PWRLMTFUNC_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PwrLmtFunc_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PwrLmtFunc_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_PWRLMTFUNC_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PwrLmtFunc_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_PWRLMTFUNC_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_PwrLmtFunc_Per1_CCLMSAActive_Cnt_lgc() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_CCLMSAActive_Cnt_lgc->value)

# define Rte_IRead_PwrLmtFunc_Per1_CustCurrLmt_Amp_f32() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_CustCurrLmt_Amp_f32->value)

# define Rte_IRead_PwrLmtFunc_Per1_KeEstimate_VpRadpS_f32() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_KeEstimate_VpRadpS_f32->value)

# define Rte_IRead_PwrLmtFunc_Per1_MotorVelocityMRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_MotorVelocityMRF_MtrRadpS_f32->value)

# define Rte_IRead_PwrLmtFunc_Per1_PosServEnable_Cnt_lgc() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_PosServEnable_Cnt_lgc->value)

# define Rte_IRead_PwrLmtFunc_Per1_Vecu_Volt_f32() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_Vecu_Volt_f32->value)

# define Rte_IWrite_PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32() \
  (&Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32->value)

# define Rte_IWrite_PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32(data) \
  ( \
  Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32() \
  (&Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32->value)

# define Rte_IRead_PwrLmtFunc_Per2_CCLMSAActive_Cnt_lgc() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per2_CCLMSAActive_Cnt_lgc->value)

# define Rte_IRead_PwrLmtFunc_Per2_PreLimitForPwr_MtrNm_f32() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per2_PreLimitForPwr_MtrNm_f32->value)

# define Rte_IRead_PwrLmtFunc_Per2_Vecu_Volt_f32() \
  (Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per2_Vecu_Volt_f32->value)

# define Rte_IWrite_PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32() \
  (&Rte_Inst_Ap_PwrLmtFunc->PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_PwrLmtFunc_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCStatus Rte_Call_Ap_PwrLmtFunc_NxtrDiagMgr_GetNTCStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_PwrLmtFunc_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_PwrLmtFunc_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_PwrLmtFunc_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_PWRLMTFUNC_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrLmtFunc_Init
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

FUNC(void, RTE_AP_PWRLMTFUNC_APPL_CODE) PwrLmtFunc_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrLmtFunc_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_PwrLmtFunc_Per1_CCLMSAActive_Cnt_lgc(void)
 *   Float Rte_IRead_PwrLmtFunc_Per1_CustCurrLmt_Amp_f32(void)
 *   Float Rte_IRead_PwrLmtFunc_Per1_KeEstimate_VpRadpS_f32(void)
 *   Float Rte_IRead_PwrLmtFunc_Per1_MotorVelocityMRF_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_PwrLmtFunc_Per1_PosServEnable_Cnt_lgc(void)
 *   Float Rte_IRead_PwrLmtFunc_Per1_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PwrLmtFunc_Per1_AssistPowerLimit_MtrNm_f32(void)
 *   void Rte_IWrite_PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_PwrLmtFunc_Per1_MtrEnvSpd_MtrRadpS_f32(void)
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

FUNC(void, RTE_AP_PWRLMTFUNC_APPL_CODE) PwrLmtFunc_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrLmtFunc_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_PwrLmtFunc_Per2_CCLMSAActive_Cnt_lgc(void)
 *   Float Rte_IRead_PwrLmtFunc_Per2_PreLimitForPwr_MtrNm_f32(void)
 *   Float Rte_IRead_PwrLmtFunc_Per2_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PwrLmtFunc_Per2_PowerLimitPerc_Uls_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
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

FUNC(void, RTE_AP_PWRLMTFUNC_APPL_CODE) PwrLmtFunc_Per2(void);

# define RTE_STOP_SEC_AP_PWRLMTFUNC_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1422564231
#    error "The magic number of the generated file <C:/SynergyWorkArea/Working/PwrLmtFunc-czmgrw/PwrLmtFunc/utp/contract/Ap_PwrLmtFunc/Rte_Ap_PwrLmtFunc.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1422564231
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PWRLMTFUNC_H */
