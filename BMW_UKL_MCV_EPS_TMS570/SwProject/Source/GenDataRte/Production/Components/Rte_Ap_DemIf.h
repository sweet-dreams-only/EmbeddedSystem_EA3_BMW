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
 *          File:  Components/Rte_Ap_DemIf.h
 *     Workspace:  C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu May 25 09:39:15 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DEMIF_H
# define _RTE_AP_DEMIF_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(CTR_ERRM_BN_U, RTE_VAR_INIT) Rte_SrlComInput_ErrmBnU_Cnt_u8;
extern VAR(ST_ILK_ERRM_FZM, RTE_VAR_INIT) Rte_SrlComInput_IlkErrmFzm_Cnt_u8;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComEngCrank_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ErrmBnU_Cnt_u8 (0U)
#  define Rte_InitValue_IlkErrmFzm_Cnt_u8 (0U)
#  define Rte_InitValue_SrlComEngCrank_Cnt_lgc (TRUE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ErrmBnU_Cnt_u8 Rte_Read_Ap_DemIf_ErrmBnU_Cnt_u8
#  define Rte_Read_Ap_DemIf_ErrmBnU_Cnt_u8(data) (*(data) = Rte_SrlComInput_ErrmBnU_Cnt_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IlkErrmFzm_Cnt_u8 Rte_Read_Ap_DemIf_IlkErrmFzm_Cnt_u8
#  define Rte_Read_Ap_DemIf_IlkErrmFzm_Cnt_u8(data) (*(data) = Rte_SrlComInput_IlkErrmFzm_Cnt_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComEngCrank_Cnt_lgc Rte_Read_Ap_DemIf_SrlComEngCrank_Cnt_lgc
#  define Rte_Read_Ap_DemIf_SrlComEngCrank_Cnt_lgc(data) (*(data) = Rte_SrlComInput2_SrlComEngCrank_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_EDCH_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_SetEventStatusIN(Edch_EventIdxType IdxIN, Dem_EventStatusType EventStatus);
#  define RTE_STOP_SEC_EDCH_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorIN_19_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_23_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_36_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_37_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_38_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_39_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_40_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_41_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_42_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_55_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_58_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_74_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_75_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_76_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_77_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_78_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_79_SetEventStatus Edch_SetEventStatusIN
#  define Rte_Call_DiagnosticMonitorIN_80_SetEventStatus Edch_SetEventStatusIN
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr9_GetNTCFailed
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_SetOperationCycleState(Dem_OperationCycleIdType OperationCycleId, Dem_OperationCycleStateType CycleState);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_OperationCycle_SetOperationCycleState Dem_SetOperationCycleState


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_MainFunctionDummy(void);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void);

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Shutdown(void);

# define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DemIf_E_NOT_OK (1U)

#  define RTE_E_Edch_DiagnosticMonitor_NxtrAddon_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_DemIf.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DEMIF_H */
