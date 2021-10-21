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
 *          File:  Rte_Ap_StaMd.h
 *     Workspace:  C:/cmsynergy/Ford_S550_P552_FordBranchMPU/Ford_S550_P552_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_StaMd
 *  Generated at:  Wed Oct 29 23:34:28 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_StaMd> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_STAMD_H
# define _RTE_AP_STAMD_H

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

typedef P2CONST(struct Rte_CDS_Ap_StaMd, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ATerm_Cnt_lgc (TRUE)
# define Rte_InitValue_CTerm_Cnt_lgc (FALSE)
# define Rte_InitValue_ControlledDampStatusComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_FTerm_Cnt_lgc (FALSE)
# define Rte_InitValue_InitiatePwrDnFastWrite_Cnt_lgc (FALSE)
# define Rte_InitValue_InitiatePwrDnNormalWrite_Cnt_lgc (FALSE)
# define Rte_InitValue_PwrDnFastWriteComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_RampStatusComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_TMFTestComplete_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_StaMd_InitiatePwrDnFastWrite_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_StaMd_InitiatePwrDnNormalWrite_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_StaMd_PwrDnFastWriteComplete_Cnt_lgc(Boolean data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_StaMd_CurrentSystemState_Mode(void);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_StaMd_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode mode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StaMd_CloseCheckData_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_STAMD_APPL_VAR) ErrorStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StaMd_CloseCheckData_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_STAMD_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StaMd_CloseCheckData_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_STAMD_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StaMd_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StaMd_TOD_OP_SET(IoHwAb_BoolType signal);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StaMd_TypeHData_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_STAMD_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StaMd_TypeHData_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_STAMD_APPL_DATA) DstPtr);
# endif

FUNC(void, RTE_CODE) Rte_Enter_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea(void);
FUNC(void, RTE_CODE) Rte_Exit_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_StaMd_Per1_ATerm_Cnt_lgc() \
  (Rte_Inst_Ap_StaMd->StaMd_Per1_ATerm_Cnt_lgc->value)

# define Rte_IRead_StaMd_Per1_CTerm_Cnt_lgc() \
  (Rte_Inst_Ap_StaMd->StaMd_Per1_CTerm_Cnt_lgc->value)

# define Rte_IRead_StaMd_Per1_ControlledDampStatusComplete_Cnt_lgc() \
  (Rte_Inst_Ap_StaMd->StaMd_Per1_ControlledDampStatusComplete_Cnt_lgc->value)

# define Rte_IRead_StaMd_Per1_FTerm_Cnt_lgc() \
  (Rte_Inst_Ap_StaMd->StaMd_Per1_FTerm_Cnt_lgc->value)

# define Rte_IRead_StaMd_Per1_RampStatusComplete_Cnt_lgc() \
  (Rte_Inst_Ap_StaMd->StaMd_Per1_RampStatusComplete_Cnt_lgc->value)

# define Rte_IRead_StaMd_Per1_TMFTestComplete_Cnt_lgc() \
  (Rte_Inst_Ap_StaMd->StaMd_Per1_TMFTestComplete_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_InitiatePwrDnFastWrite_Cnt_lgc Rte_Write_Ap_StaMd_InitiatePwrDnFastWrite_Cnt_lgc
# define Rte_Write_InitiatePwrDnNormalWrite_Cnt_lgc Rte_Write_Ap_StaMd_InitiatePwrDnNormalWrite_Cnt_lgc
# define Rte_Write_PwrDnFastWriteComplete_Cnt_lgc Rte_Write_Ap_StaMd_PwrDnFastWriteComplete_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_CurrentSystemState_Mode Rte_Mode_Ap_StaMd_CurrentSystemState_Mode
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Switch_SystemState_Mode Rte_Switch_Ap_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CloseCheckData_GetErrorStatus Rte_Call_Ap_StaMd_CloseCheckData_GetErrorStatus
# define Rte_Call_CloseCheckData_WriteBlock Rte_Call_Ap_StaMd_CloseCheckData_WriteBlock
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_StaMd_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_TOD_OP_SET Rte_Call_Ap_StaMd_TOD_OP_SET
# define Rte_Call_TypeHData_WriteBlock Rte_Call_Ap_StaMd_TypeHData_WriteBlock


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_StaMds_MilestoneRqst_WARMINIT_ExclArea Rte_Enter_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea
# define Rte_Exit_StaMds_MilestoneRqst_WARMINIT_ExclArea Rte_Exit_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea




# define RTE_START_SEC_AP_STAMD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MilestoneRqst_WarmInitMilestoneComplete
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WarmInitMilestoneComplete> of PortPrototype <MilestoneRqst>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_CurrentSystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_StaMds_MilestoneRqst_WARMINIT_ExclArea(void)
 *   void Rte_Exit_StaMds_MilestoneRqst_WARMINIT_ExclArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MilestoneRqst_WarmInitMilestoneComplete(StaMd_Users user)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STAMD_APPL_CODE) MilestoneRqst_WarmInitMilestoneComplete(StaMd_Users user);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MilestoneRqst_WarmInitMilestoneNotComplete
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WarmInitMilestoneNotComplete> of PortPrototype <MilestoneRqst>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_CurrentSystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_StaMds_MilestoneRqst_WARMINIT_ExclArea(void)
 *   void Rte_Exit_StaMds_MilestoneRqst_WARMINIT_ExclArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MilestoneRqst_WarmInitMilestoneNotComplete(StaMd_Users user)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STAMD_APPL_CODE) MilestoneRqst_WarmInitMilestoneNotComplete(StaMd_Users user);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StaMd_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_CurrentSystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_CloseCheckData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_CloseCheckData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STAMD_APPL_CODE) StaMd_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StaMd_Per1
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
 *   Boolean Rte_IRead_StaMd_Per1_ATerm_Cnt_lgc(void)
 *   Boolean Rte_IRead_StaMd_Per1_CTerm_Cnt_lgc(void)
 *   Boolean Rte_IRead_StaMd_Per1_ControlledDampStatusComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_StaMd_Per1_FTerm_Cnt_lgc(void)
 *   Boolean Rte_IRead_StaMd_Per1_RampStatusComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_StaMd_Per1_TMFTestComplete_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_InitiatePwrDnFastWrite_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_InitiatePwrDnNormalWrite_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PwrDnFastWriteComplete_Cnt_lgc(Boolean data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_SystemState_Mode(Rte_ModeType_StaMd_Mode mode)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *   Rte_ModeType_StaMd_Mode Rte_Mode_CurrentSystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
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
 *   Std_ReturnType Rte_Call_TOD_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TODReset_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CloseCheckData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_CloseCheckData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_CloseCheckData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STAMD_APPL_CODE) StaMd_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StaMd_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <CurrentSystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_InitiatePwrDnFastWrite_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_InitiatePwrDnNormalWrite_Cnt_lgc(Boolean data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_CurrentSystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_TypeHData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_TypeHData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STAMD_APPL_CODE) StaMd_Trns1(void);

# define RTE_STOP_SEC_AP_STAMD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# define RTE_E_TODReset_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1391884590
#    error "The magic number of the generated file <C:/cmsynergy/Ford_S550_P552_FordBranchMPU/StaMd/utp/contract/Ap_StaMd/Rte_Ap_StaMd.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1391884590
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_STAMD_H */
