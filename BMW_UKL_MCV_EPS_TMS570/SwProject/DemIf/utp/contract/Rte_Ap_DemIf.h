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
 *          File:  Rte_Ap_DemIf.h
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_I501/BMW_UKL_MCV_EPS_TMS570/SwProject/DemIf/autosar/Ap_DemIf.dcf
 *     SW-C Type:  Ap_DemIf
 *  Generated at:  Wed May 29 17:52:35 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_DemIf> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DEMIF_H
# define _RTE_AP_DEMIF_H

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

typedef P2CONST(struct Rte_CDS_Ap_DemIf, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ErrmBnU_Cnt_u8 (0U)
# define Rte_InitValue_IlkErrmFzm_Cnt_u8 (0U)
# define Rte_InitValue_SrlComEngCrank_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DemIf_ErrmBnU_Cnt_u8(P2VAR(CTR_ERRM_BN_U, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DemIf_IlkErrmFzm_Cnt_u8(P2VAR(ST_ILK_ERRM_FZM, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_DemIf_SrlComEngCrank_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DemIf_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DemIf_OperationCycle_SetOperationCycleState(Dem_OperationCycleIdType OperationCycleId, Dem_OperationCycleStateType CycleState);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_ErrmBnU_Cnt_u8 Rte_Read_Ap_DemIf_ErrmBnU_Cnt_u8
# define Rte_Read_IlkErrmFzm_Cnt_u8 Rte_Read_Ap_DemIf_IlkErrmFzm_Cnt_u8
# define Rte_Read_SrlComEngCrank_Cnt_lgc Rte_Read_Ap_DemIf_SrlComEngCrank_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_DemIf_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_OperationCycle_SetOperationCycleState Rte_Call_Ap_DemIf_OperationCycle_SetOperationCycleState




# define RTE_START_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_MainFunctionDummy
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_MainFunctionDummy(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_RestartDem
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RestartDem> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_RestartDem(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetEventStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEventStatus> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ErrmBnU_Cnt_u8(CTR_ERRM_BN_U *data)
 *   Std_ReturnType Rte_Read_IlkErrmFzm_Cnt_u8(ST_ILK_ERRM_FZM *data)
 *   Std_ReturnType Rte_Read_SrlComEngCrank_Cnt_lgc(Boolean *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DemIf_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetOperationCycleState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOperationCycleState> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_OperationCycle_SetOperationCycleState(Dem_OperationCycleIdType OperationCycleId, Dem_OperationCycleStateType CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_Shutdown
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DemShutdown> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_Shutdown(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Shutdown(void);

# define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_DemIf_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# define RTE_E_OperationCycle_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1363872904
#    error "The magic number of the generated file <C:/SynergyWorkArea/nivi13.05/BMW_UKL_MCV_EPS_TMS570/SwProject/DemIf/utp/contract/Rte_Ap_DemIf.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1363872904
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DEMIF_H */
