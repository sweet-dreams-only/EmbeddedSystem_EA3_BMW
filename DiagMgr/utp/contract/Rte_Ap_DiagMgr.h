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
 *          File:  Rte_Ap_DiagMgr.h
 *     Workspace:  C:/CMSynergy_Projects/DiagMgr/autosar
 *     SW-C Type:  Ap_DiagMgr
 *  Generated at:  Wed Jun 20 10:02:09 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_DiagMgr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DIAGMGR_H
# define _RTE_AP_DIAGMGR_H

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

typedef P2CONST(struct Rte_CDS_Ap_DiagMgr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DiagRampRate_XpmS_f32 ((Float)0)
# define Rte_InitValue_DiagRampValue_Uls_f32 ((Float)0)
# define Rte_InitValue_DiagRmpToZeroActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsCtrldDisRmpPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsDefTemp_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsHWASbSystmFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsScomHWANotValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsWIRDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MEC_Cnt_enum ((ManufModeType)0u)
# define Rte_InitValue_MfgDiagInhibit_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagMgr_MEC_Cnt_enum(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DiagMgr_MfgDiagInhibit_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTrq_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IgnCnt_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MtrTrq_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VehSpd_Kph_f32(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagRampRate_XpmS_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagRampValue_Uls_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagRmpToZeroActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagStsCtrldDisRmpPres_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagStsDefTemp_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagStsDefVehSpd_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagStsHWASbSystmFltPres_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagStsRecRmpToZeroFltPres_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagStsScomHWANotValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_DiagMgr_DiagStsWIRDisable_Cnt_lgc(Boolean data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_DiagMgr_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DiagMgr_DemIf_RestartDem(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DiagMgr_DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DiagMgr_DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MEC_Cnt_enum Rte_Read_Ap_DiagMgr_MEC_Cnt_enum
# define Rte_Read_MfgDiagInhibit_Cnt_lgc Rte_Read_Ap_DiagMgr_MfgDiagInhibit_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_DiagRampRate_XpmS_f32 Rte_Write_Ap_DiagMgr_DiagRampRate_XpmS_f32
# define Rte_Write_DiagRampValue_Uls_f32 Rte_Write_Ap_DiagMgr_DiagRampValue_Uls_f32
# define Rte_Write_DiagRmpToZeroActive_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagRmpToZeroActive_Cnt_lgc
# define Rte_Write_DiagStsCtrldDisRmpPres_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagStsCtrldDisRmpPres_Cnt_lgc
# define Rte_Write_DiagStsDefTemp_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagStsDefTemp_Cnt_lgc
# define Rte_Write_DiagStsDefVehSpd_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagStsDefVehSpd_Cnt_lgc
# define Rte_Write_DiagStsHWASbSystmFltPres_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagStsHWASbSystmFltPres_Cnt_lgc
# define Rte_Write_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc
# define Rte_Write_DiagStsRecRmpToZeroFltPres_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagStsRecRmpToZeroFltPres_Cnt_lgc
# define Rte_Write_DiagStsScomHWANotValid_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagStsScomHWANotValid_Cnt_lgc
# define Rte_Write_DiagStsWIRDisable_Cnt_lgc Rte_Write_Ap_DiagMgr_DiagStsWIRDisable_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_DiagMgr_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_DemIf_RestartDem Rte_Call_Ap_DiagMgr_DemIf_RestartDem
# define Rte_Call_DemIf_SetEventStatus Rte_Call_Ap_DiagMgr_DemIf_SetEventStatus
# define Rte_Call_DemIf_SetOperationCycleState Rte_Call_Ap_DiagMgr_DemIf_SetOperationCycleState


# define RTE_START_SEC_AP_DIAGMGR_APPL_CODE
# include "MemMap.h"

FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_Per1(void);
FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_Per2(void);
FUNC(void, RTE_AP_DIAGMGRQM_APPL_CODE) DiagMgr_SCom_ClearBlackBox(void);
FUNC(void, RTE_AP_DIAGMGRQM_APPL_CODE) DiagMgr_SCom_GetNTCParamByte(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGRQM_APPL_VAR) Param_Ptr_T_u08);
FUNC(void, RTE_AP_DIAGMGRQM_APPL_CODE) DiagMgr_SCom_ReadStrgArray(void);
FUNC(void, RTE_AP_DIAGMGRQM_APPL_CODE) DiagMgr_SCom_ResetNTCStatus(void);
FUNC(void, RTE_AP_DIAGMGR9_APPL_CODE) DiagMgr_StaCtrl_Shutdown(void);
FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_Trns1(void);
FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_Trns2(void);
FUNC(Std_ReturnType, RTE_AP_DIAGMGRQM_APPL_CODE) NxtrDiagMgrQM_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGRQM_APPL_VAR) NTCActive_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_AP_DIAGMGRQM_APPL_CODE) NxtrDiagMgrQM_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGRQM_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_AP_DIAGMGRQM_APPL_CODE) NxtrDiagMgrQM_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGRQM_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_AP_DIAGMGRQM_APPL_CODE) NxtrDiagMgrQM_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# define RTE_STOP_SEC_AP_DIAGMGR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_DemIf_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1340195544
#    error "The magic number of the generated file <C:/CMSynergy_Projects/DiagMgr/utp/contract/Rte_Ap_DiagMgr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1340195544
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DIAGMGR_H */
