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
 *          File:  Rte_Ap_DiagMgr10.h
 *     Workspace:  C:/SynergyWorkArea/BMW_I431/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_DiagMgr10
 *  Generated at:  Wed Jun 26 09:53:47 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_DiagMgr10> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DIAGMGR10_H
# define _RTE_AP_DIAGMGR10_H

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

typedef P2CONST(struct Rte_CDS_Ap_DiagMgr10, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DiagRampRate_XpmS_f32 (0.0F)
# define Rte_InitValue_DiagRampValue_Uls_f32 (0.0F)
# define Rte_InitValue_DiagRmpToZeroActive_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsCtrldDisRmpPres_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsDefTemp_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsHWASbSystmFltPres_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsScomHWANotValid_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsWIRDisable_Cnt_lgc (FALSE)
# define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_IgnCnt_Cnt_u16 (0U)
# define Rte_InitValue_MEC_Cnt_enum (0U)
# define Rte_InitValue_MfgDiagInhibit_Cnt_lgc (FALSE)
# define Rte_InitValue_MtrTrq_MtrNm_f32 (0.0F)
# define Rte_InitValue_VehSpd_Kph_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagMgr10_HwTrq_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagMgr10_IgnCnt_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagMgr10_MEC_Cnt_enum(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagMgr10_MtrTrq_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagMgr10_VehSpd_Kph_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagRampRate_XpmS_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagRampValue_Uls_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc(Boolean data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_DiagMgr10_SystemState_Mode(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTrq_HwNm_f32 Rte_Read_Ap_DiagMgr10_HwTrq_HwNm_f32
# define Rte_Read_IgnCnt_Cnt_u16 Rte_Read_Ap_DiagMgr10_IgnCnt_Cnt_u16
# define Rte_Read_MEC_Cnt_enum Rte_Read_Ap_DiagMgr10_MEC_Cnt_enum
# define Rte_Read_MfgDiagInhibit_Cnt_lgc Rte_Read_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc
# define Rte_Read_MtrTrq_MtrNm_f32 Rte_Read_Ap_DiagMgr10_MtrTrq_MtrNm_f32
# define Rte_Read_VehSpd_Kph_f32 Rte_Read_Ap_DiagMgr10_VehSpd_Kph_f32


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_DiagRampRate_XpmS_f32 Rte_Write_Ap_DiagMgr10_DiagRampRate_XpmS_f32
# define Rte_Write_DiagRampValue_Uls_f32 Rte_Write_Ap_DiagMgr10_DiagRampValue_Uls_f32
# define Rte_Write_DiagRmpToZeroActive_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc
# define Rte_Write_DiagStsCtrldDisRmpPres_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc
# define Rte_Write_DiagStsDefTemp_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc
# define Rte_Write_DiagStsDefVehSpd_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc
# define Rte_Write_DiagStsHWASbSystmFltPres_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc
# define Rte_Write_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc
# define Rte_Write_DiagStsRecRmpToZeroFltPres_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc
# define Rte_Write_DiagStsScomHWANotValid_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc
# define Rte_Write_DiagStsWIRDisable_Cnt_lgc Rte_Write_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_DiagMgr10_SystemState_Mode




# define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagMgr10_Init
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

FUNC(void, RTE_AP_DIAGMGR10_APPL_CODE) DiagMgr10_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagMgr10_Per
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
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

FUNC(void, RTE_AP_DIAGMGR10_APPL_CODE) DiagMgr10_Per(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagMgr10_Trns
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_AP_DIAGMGR10_APPL_CODE) DiagMgr10_Trns(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagMgr_Per1
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
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DiagRampRate_XpmS_f32(Float data)
 *   Std_ReturnType Rte_Write_DiagRampValue_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_DiagRmpToZeroActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DiagStsCtrldDisRmpPres_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DiagStsDefTemp_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DiagStsDefVehSpd_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DiagStsHWASbSystmFltPres_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DiagStsRecRmpToZeroFltPres_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DiagStsScomHWANotValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DiagStsWIRDisable_Cnt_lgc(Boolean data)
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

FUNC(void, RTE_AP_DIAGMGR10_APPL_CODE) DiagMgr_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrDiagMgr10_GetNTCActive
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNTCActive> of PortPrototype <NxtrDiagMgr10>
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
 *   Std_ReturnType NxtrDiagMgr10_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCActive_Ptr_T_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrDiagMgr10_GetNTCFailed
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNTCFailed> of PortPrototype <NxtrDiagMgr10>
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
 *   Std_ReturnType NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrDiagMgr10_GetNTCStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNTCStatus> of PortPrototype <NxtrDiagMgr10>
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
 *   Std_ReturnType NxtrDiagMgr10_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) Status_Ptr_T_u08);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrDiagMgr10_SetNTCStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetNTCStatus> of PortPrototype <NxtrDiagMgr10>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTrq_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_IgnCnt_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_MEC_Cnt_enum(ManufModeType *data)
 *   Std_ReturnType Rte_Read_MfgDiagInhibit_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_MtrTrq_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_VehSpd_Kph_f32(Float *data)
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
 *   Std_ReturnType NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1372252107
#    error "The magic number of the generated file <C:/SynergyWorkArea/CBD_DiagMgrnew/DiagMgr/utp/contract/Ap_DiagMgr10/Rte_Ap_DiagMgr10.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1372252107
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DIAGMGR10_H */
