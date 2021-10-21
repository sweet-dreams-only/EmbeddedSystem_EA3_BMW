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
 *          File:  Components/Rte_Edch.h
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
#ifndef _RTE_EDCH_H
# define _RTE_EDCH_H

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

# include "Rte_Hook.h"

# ifndef RTE_CORE

#  include "Com.h"

/* Com.h Compatibility Check */
#  ifndef RTE_COM_VERSION
#   if defined (IL_VECTOR_VERSION)
#    define RTE_COM_VERSION 20U
#   else
#    if defined (IL_ASRCOM_VERSION)
#     if (IL_ASRCOM_VERSION < 0x0201U)
#      define RTE_COM_VERSION 20U
#     endif
#    endif
#   endif
#   if defined (COM_AR_MAJOR_VERSION) && defined (COM_AR_MINOR_VERSION)
#    define RTE_COM_VERSION ((COM_AR_MAJOR_VERSION * 10) + COM_AR_MINOR_VERSION)
#   endif
#  endif
#  ifndef RTE_COM_VERSION
#   define RTE_COM_VERSION 33U
#  endif

#  if defined(IL_VECTOR_VERSION) || defined(IL_ASRCOM_VERSION)
#   define RTE_USE_COM_TXSIGNAL_RDACCESS
#  endif


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(UInt4, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_ALIVE;
extern VAR(UInt6, RTE_VAR_INIT) Rte_Edch_ST_DIAG_OBD_MUX_MAX;
extern VAR(UInt4, RTE_VAR_INIT) Rte_SrlComInput_SrlComSTKL_ST_KL;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ST_DIAG_OBD_ALIVE (0U)
#  define Rte_InitValue_ST_DIAG_OBD_MUX_IMME (0U)
#  define Rte_InitValue_ST_DIAG_OBD_MUX_MAX (0U)
#  define Rte_InitValue_ST_KL_ST_KL (0U)
#  define Rte_InitValue_ST_OBD_CYCLE_Status_OBD_Zyklus (0U)
#  define Rte_InitValue_ST_OBD_RESET_Anforderung_Reset_OBD_Diagnose_Fahrdynamik (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Edch_ST_DIAG_OBD_DATA(P2CONST(Edch_EventStatusIpduDataType, AUTOMATIC, RTE_EDCH_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Edch_ST_DIAG_OBD_MUX_IMME(UInt6 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_Edch_ST_DIAG_OBD_MUX_IMME(void);


# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ST_KL_ST_KL Rte_Read_Edch_ST_KL_ST_KL
#  define Rte_Read_Edch_ST_KL_ST_KL(data) (*(data) = Rte_SrlComInput_SrlComSTKL_ST_KL, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ST_OBD_CYCLE_Status_OBD_Zyklus Rte_Read_Edch_ST_OBD_CYCLE_Status_OBD_Zyklus
#  define Rte_Read_Edch_ST_OBD_CYCLE_Status_OBD_Zyklus(data) ((void)Com_ReceiveSignal(Com_ST_OBD_CYC__DIAG_OBD_ENG, (data)), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ST_OBD_RESET_Anforderung_Reset_OBD_Diagnose_Fahrdynamik Rte_Read_Edch_ST_OBD_RESET_Anforderung_Reset_OBD_Diagnose_Fahrdynamik
#  define Rte_Read_Edch_ST_OBD_RESET_Anforderung_Reset_OBD_Diagnose_Fahrdynamik(data) ((void)Com_ReceiveSignal(Com_RQ_RST_OBD_DIAG_DRDY__CTR_DIAG_OBD_DRDY, (data)), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ST_DIAG_OBD_ALIVE Rte_Write_Edch_ST_DIAG_OBD_ALIVE
#  define Rte_Write_Edch_ST_DIAG_OBD_ALIVE(data) (Rte_Edch_ST_DIAG_OBD_ALIVE = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ST_DIAG_OBD_DATA Rte_Write_Edch_ST_DIAG_OBD_DATA
#  define Rte_Write_ST_DIAG_OBD_MUX_IMME Rte_Write_Edch_ST_DIAG_OBD_MUX_IMME
#  define Rte_Write_ST_DIAG_OBD_MUX_MAX Rte_Write_Edch_ST_DIAG_OBD_MUX_MAX
#  define Rte_Write_Edch_ST_DIAG_OBD_MUX_MAX(data) (Rte_Edch_ST_DIAG_OBD_MUX_MAX = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<d> (explicit S/R communication status handling)
 *********************************************************************************************************************/
#  define Rte_Feedback_ST_DIAG_OBD_MUX_IMME Rte_Feedback_Edch_ST_DIAG_OBD_MUX_IMME


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_ClearPrestoredFreezeFrame(Dem_EventIdType parg0);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorOUT_19_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)19))
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetDTCOfEvent(Dem_EventIdType parg0, Dem_DTCKindType DTCKind, P2VAR(Dem_DTCType, AUTOMATIC, RTE_DEM_APPL_VAR) DTC, P2VAR(Dem_ReturnGetDTCOfEventType, AUTOMATIC, RTE_DEM_APPL_VAR) StatusDTCOfEvent);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorOUT_19_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)19, arg1, arg2, arg3))
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetEventFailed(Dem_EventIdType parg0, P2VAR(Boolean, AUTOMATIC, RTE_DEM_APPL_VAR) Failed);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorOUT_19_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)19, arg1))
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetEventStatus(Dem_EventIdType parg0, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_DEM_APPL_VAR) EventStatus);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorOUT_19_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)19, arg1))
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetEventTested(Dem_EventIdType parg0, P2VAR(Boolean, AUTOMATIC, RTE_DEM_APPL_VAR) Tested);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorOUT_19_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)19, arg1))
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_PrestoreFreezeFrame(Dem_EventIdType parg0);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorOUT_19_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)19))
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_ResetEventStatus(Dem_EventIdType parg0);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorOUT_19_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)19))
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DiagnosticMonitorOUT_19_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)19, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_23_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)23))
#  define Rte_Call_DiagnosticMonitorOUT_23_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)23, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_23_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)23, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_23_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)23, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_23_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)23, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_23_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)23))
#  define Rte_Call_DiagnosticMonitorOUT_23_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)23))
#  define Rte_Call_DiagnosticMonitorOUT_23_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)23, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_36_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)36))
#  define Rte_Call_DiagnosticMonitorOUT_36_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)36, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_36_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)36, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_36_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)36, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_36_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)36, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_36_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)36))
#  define Rte_Call_DiagnosticMonitorOUT_36_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)36))
#  define Rte_Call_DiagnosticMonitorOUT_36_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)36, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_37_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)37))
#  define Rte_Call_DiagnosticMonitorOUT_37_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)37, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_37_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)37, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_37_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)37, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_37_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)37, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_37_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)37))
#  define Rte_Call_DiagnosticMonitorOUT_37_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)37))
#  define Rte_Call_DiagnosticMonitorOUT_37_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)37, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_38_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)38))
#  define Rte_Call_DiagnosticMonitorOUT_38_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)38, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_38_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)38, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_38_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)38, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_38_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)38, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_38_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)38))
#  define Rte_Call_DiagnosticMonitorOUT_38_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)38))
#  define Rte_Call_DiagnosticMonitorOUT_38_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)38, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_39_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)39))
#  define Rte_Call_DiagnosticMonitorOUT_39_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)39, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_39_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)39, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_39_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)39, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_39_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)39, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_39_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)39))
#  define Rte_Call_DiagnosticMonitorOUT_39_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)39))
#  define Rte_Call_DiagnosticMonitorOUT_39_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)39, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_40_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)40))
#  define Rte_Call_DiagnosticMonitorOUT_40_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)40, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_40_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)40, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_40_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)40, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_40_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)40, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_40_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)40))
#  define Rte_Call_DiagnosticMonitorOUT_40_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)40))
#  define Rte_Call_DiagnosticMonitorOUT_40_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)40, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_41_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)41))
#  define Rte_Call_DiagnosticMonitorOUT_41_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)41, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_41_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)41, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_41_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)41, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_41_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)41, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_41_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)41))
#  define Rte_Call_DiagnosticMonitorOUT_41_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)41))
#  define Rte_Call_DiagnosticMonitorOUT_41_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)41, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_42_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)42))
#  define Rte_Call_DiagnosticMonitorOUT_42_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)42, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_42_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)42, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_42_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)42, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_42_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)42, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_42_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)42))
#  define Rte_Call_DiagnosticMonitorOUT_42_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)42))
#  define Rte_Call_DiagnosticMonitorOUT_42_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)42, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_55_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)55))
#  define Rte_Call_DiagnosticMonitorOUT_55_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)55, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_55_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)55, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_55_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)55, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_55_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)55, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_55_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)55))
#  define Rte_Call_DiagnosticMonitorOUT_55_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)55))
#  define Rte_Call_DiagnosticMonitorOUT_55_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)55, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_58_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)58))
#  define Rte_Call_DiagnosticMonitorOUT_58_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)58, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_58_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)58, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_58_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)58, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_58_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)58, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_58_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)58))
#  define Rte_Call_DiagnosticMonitorOUT_58_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)58))
#  define Rte_Call_DiagnosticMonitorOUT_58_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)58, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_74_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)74))
#  define Rte_Call_DiagnosticMonitorOUT_74_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)74, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_74_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)74, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_74_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)74, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_74_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)74, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_74_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)74))
#  define Rte_Call_DiagnosticMonitorOUT_74_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)74))
#  define Rte_Call_DiagnosticMonitorOUT_74_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)74, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_75_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)75))
#  define Rte_Call_DiagnosticMonitorOUT_75_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)75, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_75_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)75, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_75_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)75, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_75_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)75, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_75_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)75))
#  define Rte_Call_DiagnosticMonitorOUT_75_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)75))
#  define Rte_Call_DiagnosticMonitorOUT_75_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)75, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_76_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)76))
#  define Rte_Call_DiagnosticMonitorOUT_76_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)76, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_76_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)76, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_76_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)76, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_76_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)76, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_76_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)76))
#  define Rte_Call_DiagnosticMonitorOUT_76_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)76))
#  define Rte_Call_DiagnosticMonitorOUT_76_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)76, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_77_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)77))
#  define Rte_Call_DiagnosticMonitorOUT_77_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)77, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_77_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)77, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_77_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)77, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_77_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)77, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_77_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)77))
#  define Rte_Call_DiagnosticMonitorOUT_77_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)77))
#  define Rte_Call_DiagnosticMonitorOUT_77_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)77, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_78_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)78))
#  define Rte_Call_DiagnosticMonitorOUT_78_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)78, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_78_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)78, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_78_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)78, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_78_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)78, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_78_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)78))
#  define Rte_Call_DiagnosticMonitorOUT_78_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)78))
#  define Rte_Call_DiagnosticMonitorOUT_78_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)78, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_79_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)79))
#  define Rte_Call_DiagnosticMonitorOUT_79_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)79, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_79_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)79, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_79_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)79, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_79_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)79, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_79_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)79))
#  define Rte_Call_DiagnosticMonitorOUT_79_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)79))
#  define Rte_Call_DiagnosticMonitorOUT_79_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)79, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_80_ClearPrestoredFreezeFrame() (Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)80))
#  define Rte_Call_DiagnosticMonitorOUT_80_GetDTCOfEvent(arg1, arg2, arg3) (Dem_GetDTCOfEvent((Dem_EventIdType)80, arg1, arg2, arg3))
#  define Rte_Call_DiagnosticMonitorOUT_80_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)80, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_80_GetEventStatus(arg1) (Dem_GetEventStatus((Dem_EventIdType)80, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_80_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)80, arg1))
#  define Rte_Call_DiagnosticMonitorOUT_80_PrestoreFreezeFrame() (Dem_PrestoreFreezeFrame((Dem_EventIdType)80))
#  define Rte_Call_DiagnosticMonitorOUT_80_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)80))
#  define Rte_Call_DiagnosticMonitorOUT_80_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)80, arg1))
#  define RTE_START_SEC_SA_CDDINTERFACE9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_CDDINTERFACE9_APPL_CODE) FirstStartPort_GetFirstStart(void);
#  define RTE_STOP_SEC_SA_CDDINTERFACE9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_FirstStartPort_GetFirstStart FirstStartPort_GetFirstStart
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_SetOperationCycleState(Dem_OperationCycleIdType OperationCycleId, Dem_OperationCycleStateType CycleState);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RP_Dem_CYCLE_SetOperationCycleState Dem_SetOperationCycleState


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_ExclusiveArea_0() \
  { \
    Rte_EnterHook_Edch_ExclusiveArea_0_Start(); \
    SuspendOSInterrupts(); \
    Rte_EnterHook_Edch_ExclusiveArea_0_Return(); \
  }

#  define Rte_Exit_ExclusiveArea_0() \
  { \
    Rte_ExitHook_Edch_ExclusiveArea_0_Start(); \
    ResumeOSInterrupts(); \
    Rte_ExitHook_Edch_ExclusiveArea_0_Return(); \
  }


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_EDCH_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_EDCH_APPL_CODE) Edch_CalculateSubCvn(void);

FUNC(void, RTE_EDCH_APPL_CODE) Edch_ClearErrorMem(void);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_DataServicePort_Read(P2VAR(UInt8, AUTOMATIC, RTE_EDCH_APPL_VAR) Data);
# else
FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_DataServicePort_Read(P2VAR(Dcm_Data_CALID_CVN_ArrayType, AUTOMATIC, RTE_EDCH_APPL_VAR) Data);
# endif

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_EventStatusChanged(Edch_EventIdxType parg0, Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew);

FUNC(void, RTE_EDCH_APPL_CODE) Edch_Init(void);

FUNC(void, RTE_EDCH_APPL_CODE) Edch_InitSend(void);

FUNC(void, RTE_EDCH_APPL_CODE) Edch_Main(void);

FUNC(void, RTE_EDCH_APPL_CODE) Edch_OperationCycleUpdated(void);

FUNC(void, RTE_EDCH_APPL_CODE) Edch_SendCyclic(void);

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_ClearPrestoredFreezeFrameIN(Edch_EventIdxType IdxIN);

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_GetDTCOfEventIN(Edch_EventIdxType IdxIN, Dem_DTCKindType DTCKind, P2VAR(Dem_DTCType, AUTOMATIC, RTE_EDCH_APPL_VAR) DTC, P2VAR(Dem_ReturnGetDTCOfEventType, AUTOMATIC, RTE_EDCH_APPL_VAR) StatusDTCOfEvent);

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_GetEventFailedIN(Edch_EventIdxType IdxIN, P2VAR(Boolean, AUTOMATIC, RTE_EDCH_APPL_VAR) Failed);

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_GetEventStatusIN(Edch_EventIdxType IdxIN, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_EDCH_APPL_VAR) EventStatus);

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_GetEventTestedIN(Edch_EventIdxType IdxIN, P2VAR(Boolean, AUTOMATIC, RTE_EDCH_APPL_VAR) Tested);

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_PrestoreFreezeFrameIN(Edch_EventIdxType IdxIN);

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_ResetEventStatusIN(Edch_EventIdxType IdxIN);

FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_SetEventStatusIN(Edch_EventIdxType IdxIN, Dem_EventStatusType EventStatus);

# define RTE_STOP_SEC_EDCH_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackEventStatusChange_E_NOT_OK (1U)

#  define RTE_E_DataServices_CALID_CVN_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_Edch_DiagnosticMonitor_NxtrAddon_E_NOT_OK (1U)

#  define RTE_E_FirstStartInterface_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Edch.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_EDCH_H */
