


/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs.
  However, they are not thoroughly tested yet (beta-version).
  With regard to the fact that the programs are a beta-version only,
  Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence,
  to the extent admissible by law or statute.
*/



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
 *          File:  Rte_Type.h
 *     Workspace:  C:/Synergy WorkArea/CBD_StOpCtrl/StOpCtrl/autosar/Ap_StOpCtrl.dcf
 *     SW-C Type:  Ap_StOpCtrl
 *  Generated at:  Thu Jan 12 15:33:05 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit (0U)
# define UInt16_UpperLimit (65535U)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit (0U)
# define UInt32_UpperLimit (4294967295U)


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;
#  define ComM_InhibitionStatusType_LowerLimit (0U)
#  define ComM_InhibitionStatusType_UpperLimit (0U)

#  define Rte_TypeDef_Dem_DTCType
typedef uint32 Dem_DTCType;
#  define Dem_DTCType_LowerLimit (1U)
#  define Dem_DTCType_UpperLimit (16777215U)

#  define Rte_TypeDef_Dem_EventStatusExtendedType
typedef uint8 Dem_EventStatusExtendedType;
#  define Dem_EventStatusExtendedType_LowerLimit (0U)
#  define Dem_EventStatusExtendedType_UpperLimit (255U)

#  define Rte_TypeDef_Dem_FaultDetectionCounterType
typedef sint8 Dem_FaultDetectionCounterType;
#  define Dem_FaultDetectionCounterType_LowerLimit (-128)
#  define Dem_FaultDetectionCounterType_UpperLimit (127)

#  define Rte_TypeDef_SInt16
typedef sint16 SInt16;
#  define SInt16_LowerLimit (-32768)
#  define SInt16_UpperLimit (32767)

#  define Rte_TypeDef_SInt8
typedef sint8 SInt8;
#  define SInt8_LowerLimit (-128)
#  define SInt8_UpperLimit (127)

#  define Rte_TypeDef_UInt8
typedef uint8 UInt8;
#  define UInt8_LowerLimit (0U)
#  define UInt8_UpperLimit (255U)

#  define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;
#  define WdgM_ModeType_LowerLimit (0U)
#  define WdgM_ModeType_UpperLimit (255U)

#  define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;
#  define ComM_ModeType_LowerLimit (0U)
#  define ComM_ModeType_UpperLimit (2U)
#  if (defined RTE_CONST_COMM_NO_COMMUNICATION) || (defined COMM_NO_COMMUNICATION)
#   if (!defined RTE_CONST_COMM_NO_COMMUNICATION) || (RTE_CONST_COMM_NO_COMMUNICATION != 0U)
#    error "Enumeration constant <COMM_NO_COMMUNICATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_COMM_NO_COMMUNICATION (0U)
#   define COMM_NO_COMMUNICATION (0U)
#  endif
#  if (defined RTE_CONST_COMM_SILENT_COMMUNICATION) || (defined COMM_SILENT_COMMUNICATION)
#   if (!defined RTE_CONST_COMM_SILENT_COMMUNICATION) || (RTE_CONST_COMM_SILENT_COMMUNICATION != 1U)
#    error "Enumeration constant <COMM_SILENT_COMMUNICATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_COMM_SILENT_COMMUNICATION (1U)
#   define COMM_SILENT_COMMUNICATION (1U)
#  endif
#  if (defined RTE_CONST_COMM_FULL_COMMUNICATION) || (defined COMM_FULL_COMMUNICATION)
#   if (!defined RTE_CONST_COMM_FULL_COMMUNICATION) || (RTE_CONST_COMM_FULL_COMMUNICATION != 2U)
#    error "Enumeration constant <COMM_FULL_COMMUNICATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_COMM_FULL_COMMUNICATION (2U)
#   define COMM_FULL_COMMUNICATION (2U)
#  endif

#  define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;
#  define Dem_DTCKindType_LowerLimit (1U)
#  define Dem_DTCKindType_UpperLimit (2U)
#  if (defined RTE_CONST_DEM_DTC_KIND_ALL_DTCS) || (defined DEM_DTC_KIND_ALL_DTCS)
#   if (!defined RTE_CONST_DEM_DTC_KIND_ALL_DTCS) || (RTE_CONST_DEM_DTC_KIND_ALL_DTCS != 1U)
#    error "Enumeration constant <DEM_DTC_KIND_ALL_DTCS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_DTC_KIND_ALL_DTCS (1U)
#   define DEM_DTC_KIND_ALL_DTCS (1U)
#  endif
#  if (defined RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS) || (defined DEM_DTC_KIND_EMISSION_REL_DTCS)
#   if (!defined RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS) || (RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS != 2U)
#    error "Enumeration constant <DEM_DTC_KIND_EMISSION_REL_DTCS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
#   define DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
#  endif

#  define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;
#  define Dem_EventStatusType_LowerLimit (0U)
#  define Dem_EventStatusType_UpperLimit (255U)
#  if (defined RTE_CONST_DEM_EVENT_STATUS_PASSED) || (defined DEM_EVENT_STATUS_PASSED)
#   if (!defined RTE_CONST_DEM_EVENT_STATUS_PASSED) || (RTE_CONST_DEM_EVENT_STATUS_PASSED != 0U)
#    error "Enumeration constant <DEM_EVENT_STATUS_PASSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_EVENT_STATUS_PASSED (0U)
#   define DEM_EVENT_STATUS_PASSED (0U)
#  endif
#  if (defined RTE_CONST_DEM_EVENT_STATUS_FAILED) || (defined DEM_EVENT_STATUS_FAILED)
#   if (!defined RTE_CONST_DEM_EVENT_STATUS_FAILED) || (RTE_CONST_DEM_EVENT_STATUS_FAILED != 1U)
#    error "Enumeration constant <DEM_EVENT_STATUS_FAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_EVENT_STATUS_FAILED (1U)
#   define DEM_EVENT_STATUS_FAILED (1U)
#  endif
#  if (defined RTE_CONST_DEM_EVENT_STATUS_PREPASSED) || (defined DEM_EVENT_STATUS_PREPASSED)
#   if (!defined RTE_CONST_DEM_EVENT_STATUS_PREPASSED) || (RTE_CONST_DEM_EVENT_STATUS_PREPASSED != 2U)
#    error "Enumeration constant <DEM_EVENT_STATUS_PREPASSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_EVENT_STATUS_PREPASSED (2U)
#   define DEM_EVENT_STATUS_PREPASSED (2U)
#  endif
#  if (defined RTE_CONST_DEM_EVENT_STATUS_PREFAILED) || (defined DEM_EVENT_STATUS_PREFAILED)
#   if (!defined RTE_CONST_DEM_EVENT_STATUS_PREFAILED) || (RTE_CONST_DEM_EVENT_STATUS_PREFAILED != 3U)
#    error "Enumeration constant <DEM_EVENT_STATUS_PREFAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_EVENT_STATUS_PREFAILED (3U)
#   define DEM_EVENT_STATUS_PREFAILED (3U)
#  endif

#  define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;
#  define Dem_IndicatorStatusType_LowerLimit (0U)
#  define Dem_IndicatorStatusType_UpperLimit (3U)
#  if (defined RTE_CONST_DEM_INDICATOR_OFF) || (defined DEM_INDICATOR_OFF)
#   if (!defined RTE_CONST_DEM_INDICATOR_OFF) || (RTE_CONST_DEM_INDICATOR_OFF != 0U)
#    error "Enumeration constant <DEM_INDICATOR_OFF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INDICATOR_OFF (0U)
#   define DEM_INDICATOR_OFF (0U)
#  endif
#  if (defined RTE_CONST_DEM_INDICATOR_CONTINUOUS) || (defined DEM_INDICATOR_CONTINUOUS)
#   if (!defined RTE_CONST_DEM_INDICATOR_CONTINUOUS) || (RTE_CONST_DEM_INDICATOR_CONTINUOUS != 1U)
#    error "Enumeration constant <DEM_INDICATOR_CONTINUOUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INDICATOR_CONTINUOUS (1U)
#   define DEM_INDICATOR_CONTINUOUS (1U)
#  endif
#  if (defined RTE_CONST_DEM_INDICATOR_BLINKING) || (defined DEM_INDICATOR_BLINKING)
#   if (!defined RTE_CONST_DEM_INDICATOR_BLINKING) || (RTE_CONST_DEM_INDICATOR_BLINKING != 2U)
#    error "Enumeration constant <DEM_INDICATOR_BLINKING> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INDICATOR_BLINKING (2U)
#   define DEM_INDICATOR_BLINKING (2U)
#  endif
#  if (defined RTE_CONST_DEM_INDICATOR_BLINK_CONT) || (defined DEM_INDICATOR_BLINK_CONT)
#   if (!defined RTE_CONST_DEM_INDICATOR_BLINK_CONT) || (RTE_CONST_DEM_INDICATOR_BLINK_CONT != 3U)
#    error "Enumeration constant <DEM_INDICATOR_BLINK_CONT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INDICATOR_BLINK_CONT (3U)
#   define DEM_INDICATOR_BLINK_CONT (3U)
#  endif

#  define Rte_TypeDef_Dem_InitMonitorKindType
typedef uint8 Dem_InitMonitorKindType;
#  define Dem_InitMonitorKindType_LowerLimit (1U)
#  define Dem_InitMonitorKindType_UpperLimit (3U)
#  if (defined RTE_CONST_DEM_INIT_MONITOR_CLEAR) || (defined DEM_INIT_MONITOR_CLEAR)
#   if (!defined RTE_CONST_DEM_INIT_MONITOR_CLEAR) || (RTE_CONST_DEM_INIT_MONITOR_CLEAR != 1U)
#    error "Enumeration constant <DEM_INIT_MONITOR_CLEAR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INIT_MONITOR_CLEAR (1U)
#   define DEM_INIT_MONITOR_CLEAR (1U)
#  endif
#  if (defined RTE_CONST_DEM_INIT_MONITOR_RESTART) || (defined DEM_INIT_MONITOR_RESTART)
#   if (!defined RTE_CONST_DEM_INIT_MONITOR_RESTART) || (RTE_CONST_DEM_INIT_MONITOR_RESTART != 2U)
#    error "Enumeration constant <DEM_INIT_MONITOR_RESTART> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INIT_MONITOR_RESTART (2U)
#   define DEM_INIT_MONITOR_RESTART (2U)
#  endif
#  if (defined RTE_CONST_DEM_INIT_MONITOR_END) || (defined DEM_INIT_MONITOR_END)
#   if (!defined RTE_CONST_DEM_INIT_MONITOR_END) || (RTE_CONST_DEM_INIT_MONITOR_END != 3U)
#    error "Enumeration constant <DEM_INIT_MONITOR_END> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INIT_MONITOR_END (3U)
#   define DEM_INIT_MONITOR_END (3U)
#  endif

#  define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;
#  define Dem_OperationCycleIdType_LowerLimit (0U)
#  define Dem_OperationCycleIdType_UpperLimit (255U)
#  if (defined RTE_CONST_DEM_OPCYCLE_DEFAULT) || (defined DEM_OPCYCLE_DEFAULT)
#   if (!defined RTE_CONST_DEM_OPCYCLE_DEFAULT) || (RTE_CONST_DEM_OPCYCLE_DEFAULT != 0U)
#    error "Enumeration constant <DEM_OPCYCLE_DEFAULT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_OPCYCLE_DEFAULT (0U)
#   define DEM_OPCYCLE_DEFAULT (0U)
#  endif
#  if (defined RTE_CONST_DEM_OPCYCLE_VSM_OPMODE) || (defined DEM_OPCYCLE_VSM_OPMODE)
#   if (!defined RTE_CONST_DEM_OPCYCLE_VSM_OPMODE) || (RTE_CONST_DEM_OPCYCLE_VSM_OPMODE != 1U)
#    error "Enumeration constant <DEM_OPCYCLE_VSM_OPMODE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_OPCYCLE_VSM_OPMODE (1U)
#   define DEM_OPCYCLE_VSM_OPMODE (1U)
#  endif
#  if (defined RTE_CONST_BUS_ACTIVE) || (defined BUS_ACTIVE)
#   if (!defined RTE_CONST_BUS_ACTIVE) || (RTE_CONST_BUS_ACTIVE != 2U)
#    error "Enumeration constant <BUS_ACTIVE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_BUS_ACTIVE (2U)
#   define BUS_ACTIVE (2U)
#  endif

#  define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;
#  define Dem_OperationCycleStateType_LowerLimit (1U)
#  define Dem_OperationCycleStateType_UpperLimit (2U)
#  if (defined RTE_CONST_DEM_CYCLE_STATE_START) || (defined DEM_CYCLE_STATE_START)
#   if (!defined RTE_CONST_DEM_CYCLE_STATE_START) || (RTE_CONST_DEM_CYCLE_STATE_START != 1U)
#    error "Enumeration constant <DEM_CYCLE_STATE_START> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_CYCLE_STATE_START (1U)
#   define DEM_CYCLE_STATE_START (1U)
#  endif
#  if (defined RTE_CONST_DEM_CYCLE_STATE_END) || (defined DEM_CYCLE_STATE_END)
#   if (!defined RTE_CONST_DEM_CYCLE_STATE_END) || (RTE_CONST_DEM_CYCLE_STATE_END != 2U)
#    error "Enumeration constant <DEM_CYCLE_STATE_END> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_CYCLE_STATE_END (2U)
#   define DEM_CYCLE_STATE_END (2U)
#  endif

#  define Rte_TypeDef_Dem_ReturnGetDTCOfEventType
typedef uint8 Dem_ReturnGetDTCOfEventType;
#  define Dem_ReturnGetDTCOfEventType_LowerLimit (0U)
#  define Dem_ReturnGetDTCOfEventType_UpperLimit (2U)
#  if (defined RTE_CONST_DEM_GET_DTCOFEVENT_OK) || (defined DEM_GET_DTCOFEVENT_OK)
#   if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_OK) || (RTE_CONST_DEM_GET_DTCOFEVENT_OK != 0U)
#    error "Enumeration constant <DEM_GET_DTCOFEVENT_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_GET_DTCOFEVENT_OK (0U)
#   define DEM_GET_DTCOFEVENT_OK (0U)
#  endif
#  if (defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID) || (defined DEM_GET_DTCOFEVENT_WRONG_EVENTID)
#   if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID) || (RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID != 1U)
#    error "Enumeration constant <DEM_GET_DTCOFEVENT_WRONG_EVENTID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID (1U)
#   define DEM_GET_DTCOFEVENT_WRONG_EVENTID (1U)
#  endif
#  if (defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND) || (defined DEM_GET_DTCOFEVENT_WRONG_DTCKIND)
#   if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND) || (RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND != 2U)
#    error "Enumeration constant <DEM_GET_DTCOFEVENT_WRONG_DTCKIND> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND (2U)
#   define DEM_GET_DTCOFEVENT_WRONG_DTCKIND (2U)
#  endif

#  define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;
#  define EcuM_StateType_LowerLimit (16U)
#  define EcuM_StateType_UpperLimit (255U)
#  if (defined RTE_CONST_ECUM_STATE_STARTUP) || (defined ECUM_STATE_STARTUP)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP) || (RTE_CONST_ECUM_STATE_STARTUP != 16U)
#    error "Enumeration constant <ECUM_STATE_STARTUP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP (16U)
#   define ECUM_STATE_STARTUP (16U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (defined ECUM_STATE_STARTUP_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (RTE_CONST_ECUM_STATE_STARTUP_ONE != 17U)
#    error "Enumeration constant <ECUM_STATE_STARTUP_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP_ONE (17U)
#   define ECUM_STATE_STARTUP_ONE (17U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (defined ECUM_STATE_STARTUP_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (RTE_CONST_ECUM_STATE_STARTUP_TWO != 18U)
#    error "Enumeration constant <ECUM_STATE_STARTUP_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP_TWO (18U)
#   define ECUM_STATE_STARTUP_TWO (18U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP) || (defined ECUM_STATE_WAKEUP)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP) || (RTE_CONST_ECUM_STATE_WAKEUP != 32U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP (32U)
#   define ECUM_STATE_WAKEUP (32U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (defined ECUM_STATE_WAKEUP_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (RTE_CONST_ECUM_STATE_WAKEUP_ONE != 33U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_ONE (33U)
#   define ECUM_STATE_WAKEUP_ONE (33U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (defined ECUM_STATE_WAKEUP_VALIDATION)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION != 34U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_VALIDATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION (34U)
#   define ECUM_STATE_WAKEUP_VALIDATION (34U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (defined ECUM_STATE_WAKEUP_REACTION)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (RTE_CONST_ECUM_STATE_WAKEUP_REACTION != 35U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_REACTION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_REACTION (35U)
#   define ECUM_STATE_WAKEUP_REACTION (35U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (defined ECUM_STATE_WAKEUP_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (RTE_CONST_ECUM_STATE_WAKEUP_TWO != 36U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_TWO (36U)
#   define ECUM_STATE_WAKEUP_TWO (36U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (defined ECUM_STATE_WAKEUP_WAKESLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP != 37U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_WAKESLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#   define ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (defined ECUM_STATE_WAKEUP_TTII)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (RTE_CONST_ECUM_STATE_WAKEUP_TTII != 38U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_TTII> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_TTII (38U)
#   define ECUM_STATE_WAKEUP_TTII (38U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_RUN) || (defined ECUM_STATE_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_RUN) || (RTE_CONST_ECUM_STATE_RUN != 48U)
#    error "Enumeration constant <ECUM_STATE_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_RUN (48U)
#   define ECUM_STATE_RUN (48U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_APP_RUN) || (defined ECUM_STATE_APP_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_APP_RUN) || (RTE_CONST_ECUM_STATE_APP_RUN != 50U)
#    error "Enumeration constant <ECUM_STATE_APP_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_APP_RUN (50U)
#   define ECUM_STATE_APP_RUN (50U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (defined ECUM_STATE_APP_POST_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (RTE_CONST_ECUM_STATE_APP_POST_RUN != 51U)
#    error "Enumeration constant <ECUM_STATE_APP_POST_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_APP_POST_RUN (51U)
#   define ECUM_STATE_APP_POST_RUN (51U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (defined ECUM_STATE_SHUTDOWN)
#   if (!defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (RTE_CONST_ECUM_STATE_SHUTDOWN != 64U)
#    error "Enumeration constant <ECUM_STATE_SHUTDOWN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_SHUTDOWN (64U)
#   define ECUM_STATE_SHUTDOWN (64U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (defined ECUM_STATE_PREP_SHUTDOWN)
#   if (!defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (RTE_CONST_ECUM_STATE_PREP_SHUTDOWN != 68U)
#    error "Enumeration constant <ECUM_STATE_PREP_SHUTDOWN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_PREP_SHUTDOWN (68U)
#   define ECUM_STATE_PREP_SHUTDOWN (68U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (defined ECUM_STATE_GO_SLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (RTE_CONST_ECUM_STATE_GO_SLEEP != 73U)
#    error "Enumeration constant <ECUM_STATE_GO_SLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_SLEEP (73U)
#   define ECUM_STATE_GO_SLEEP (73U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (defined ECUM_STATE_GO_OFF_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (RTE_CONST_ECUM_STATE_GO_OFF_ONE != 77U)
#    error "Enumeration constant <ECUM_STATE_GO_OFF_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_OFF_ONE (77U)
#   define ECUM_STATE_GO_OFF_ONE (77U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (defined ECUM_STATE_GO_OFF_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (RTE_CONST_ECUM_STATE_GO_OFF_TWO != 78U)
#    error "Enumeration constant <ECUM_STATE_GO_OFF_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_OFF_TWO (78U)
#   define ECUM_STATE_GO_OFF_TWO (78U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_SLEEP) || (defined ECUM_STATE_SLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_SLEEP) || (RTE_CONST_ECUM_STATE_SLEEP != 80U)
#    error "Enumeration constant <ECUM_STATE_SLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_SLEEP (80U)
#   define ECUM_STATE_SLEEP (80U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_OFF) || (defined ECUM_STATE_OFF)
#   if (!defined RTE_CONST_ECUM_STATE_OFF) || (RTE_CONST_ECUM_STATE_OFF != 128U)
#    error "Enumeration constant <ECUM_STATE_OFF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_OFF (128U)
#   define ECUM_STATE_OFF (128U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_RESET) || (defined ECUM_STATE_RESET)
#   if (!defined RTE_CONST_ECUM_STATE_RESET) || (RTE_CONST_ECUM_STATE_RESET != 144U)
#    error "Enumeration constant <ECUM_STATE_RESET> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_RESET (144U)
#   define ECUM_STATE_RESET (144U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_ERROR) || (defined ECUM_STATE_ERROR)
#   if (!defined RTE_CONST_ECUM_STATE_ERROR) || (RTE_CONST_ECUM_STATE_ERROR != 255U)
#    error "Enumeration constant <ECUM_STATE_ERROR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_ERROR (255U)
#   define ECUM_STATE_ERROR (255U)
#  endif

#  define Rte_TypeDef_ManufModeType
typedef uint8 ManufModeType;
#  define ManufModeType_LowerLimit (0U)
#  define ManufModeType_UpperLimit (2U)
#  if (defined RTE_CONST_ProductionMode) || (defined ProductionMode)
#   if (!defined RTE_CONST_ProductionMode) || (RTE_CONST_ProductionMode != 0U)
#    error "Enumeration constant <ProductionMode> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ProductionMode (0U)
#   define ProductionMode (0U)
#  endif
#  if (defined RTE_CONST_ManufacturingMode) || (defined ManufacturingMode)
#   if (!defined RTE_CONST_ManufacturingMode) || (RTE_CONST_ManufacturingMode != 1U)
#    error "Enumeration constant <ManufacturingMode> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ManufacturingMode (1U)
#   define ManufacturingMode (1U)
#  endif
#  if (defined RTE_CONST_EngineeringMode) || (defined EngineeringMode)
#   if (!defined RTE_CONST_EngineeringMode) || (RTE_CONST_EngineeringMode != 2U)
#    error "Enumeration constant <EngineeringMode> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_EngineeringMode (2U)
#   define EngineeringMode (2U)
#  endif

#  define Rte_TypeDef_NTCNumber
typedef uint16 NTCNumber;
#  define NTCNumber_LowerLimit (0U)
#  define NTCNumber_UpperLimit (511U)
#  if (defined RTE_CONST_NTC_Num_FlashCRCMemFault) || (defined NTC_Num_FlashCRCMemFault)
#   if (!defined RTE_CONST_NTC_Num_FlashCRCMemFault) || (RTE_CONST_NTC_Num_FlashCRCMemFault != 4U)
#    error "Enumeration constant <NTC_Num_FlashCRCMemFault> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_FlashCRCMemFault (4U)
#   define NTC_Num_FlashCRCMemFault (4U)
#  endif
#  if (defined RTE_CONST_NTC_Num_EEPROMDiag) || (defined NTC_Num_EEPROMDiag)
#   if (!defined RTE_CONST_NTC_Num_EEPROMDiag) || (RTE_CONST_NTC_Num_EEPROMDiag != 10U)
#    error "Enumeration constant <NTC_Num_EEPROMDiag> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_EEPROMDiag (10U)
#   define NTC_Num_EEPROMDiag (10U)
#  endif
#  if (defined RTE_CONST_NTC_Num_EEPROMDiagMtrStr) || (defined NTC_Num_EEPROMDiagMtrStr)
#   if (!defined RTE_CONST_NTC_Num_EEPROMDiagMtrStr) || (RTE_CONST_NTC_Num_EEPROMDiagMtrStr != 11U)
#    error "Enumeration constant <NTC_Num_EEPROMDiagMtrStr> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_EEPROMDiagMtrStr (11U)
#   define NTC_Num_EEPROMDiagMtrStr (11U)
#  endif
#  if (defined RTE_CONST_NTC_Num_EEPROMDiagTrqSnrStr) || (defined NTC_Num_EEPROMDiagTrqSnrStr)
#   if (!defined RTE_CONST_NTC_Num_EEPROMDiagTrqSnrStr) || (RTE_CONST_NTC_Num_EEPROMDiagTrqSnrStr != 12U)
#    error "Enumeration constant <NTC_Num_EEPROMDiagTrqSnrStr> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_EEPROMDiagTrqSnrStr (12U)
#   define NTC_Num_EEPROMDiagTrqSnrStr (12U)
#  endif
#  if (defined RTE_CONST_NTC_Num_EEPROMDiagPolarityStr) || (defined NTC_Num_EEPROMDiagPolarityStr)
#   if (!defined RTE_CONST_NTC_Num_EEPROMDiagPolarityStr) || (RTE_CONST_NTC_Num_EEPROMDiagPolarityStr != 14U)
#    error "Enumeration constant <NTC_Num_EEPROMDiagPolarityStr> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_EEPROMDiagPolarityStr (14U)
#   define NTC_Num_EEPROMDiagPolarityStr (14U)
#  endif
#  if (defined RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt) || (defined NTC_Num_RAMDiag_ECCCorrIndFlt)
#   if (!defined RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt) || (RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt != 18U)
#    error "Enumeration constant <NTC_Num_RAMDiag_ECCCorrIndFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
#   define NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
#  endif
#  if (defined RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt) || (defined NTC_Num_RAMDiag_ECCMemFlt)
#   if (!defined RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt) || (RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt != 19U)
#    error "Enumeration constant <NTC_Num_RAMDiag_ECCMemFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt (19U)
#   define NTC_Num_RAMDiag_ECCMemFlt (19U)
#  endif
#  if (defined RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt) || (defined NTC_Num_RAMDiag_VIMRamFlt)
#   if (!defined RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt) || (RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt != 23U)
#    error "Enumeration constant <NTC_Num_RAMDiag_VIMRamFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt (23U)
#   define NTC_Num_RAMDiag_VIMRamFlt (23U)
#  endif
#  if (defined RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt) || (defined NTC_Num_RAMDiag_NHET1RamFlt)
#   if (!defined RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt != 24U)
#    error "Enumeration constant <NTC_Num_RAMDiag_NHET1RamFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt (24U)
#   define NTC_Num_RAMDiag_NHET1RamFlt (24U)
#  endif
#  if (defined RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt) || (defined NTC_Num_RAMDiag_NHET2RamFlt)
#   if (!defined RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt != 25U)
#    error "Enumeration constant <NTC_Num_RAMDiag_NHET2RamFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt (25U)
#   define NTC_Num_RAMDiag_NHET2RamFlt (25U)
#  endif
#  if (defined RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt) || (defined NTC_Num_RAMDiag_ADCRamFlt)
#   if (!defined RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt) || (RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt != 26U)
#    error "Enumeration constant <NTC_Num_RAMDiag_ADCRamFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt (26U)
#   define NTC_Num_RAMDiag_ADCRamFlt (26U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CPU_CoreInitFlt) || (defined NTC_Num_CPU_CoreInitFlt)
#   if (!defined RTE_CONST_NTC_Num_CPU_CoreInitFlt) || (RTE_CONST_NTC_Num_CPU_CoreInitFlt != 33U)
#    error "Enumeration constant <NTC_Num_CPU_CoreInitFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CPU_CoreInitFlt (33U)
#   define NTC_Num_CPU_CoreInitFlt (33U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt) || (defined NTC_Num_CPU_CoreRunTimeFlt)
#   if (!defined RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt) || (RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt != 34U)
#    error "Enumeration constant <NTC_Num_CPU_CoreRunTimeFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt (34U)
#   define NTC_Num_CPU_CoreRunTimeFlt (34U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag) || (defined NTC_Num_PropExeDiag_RunTimeDiag)
#   if (!defined RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag) || (RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag != 43U)
#    error "Enumeration constant <NTC_Num_PropExeDiag_RunTimeDiag> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag (43U)
#   define NTC_Num_PropExeDiag_RunTimeDiag (43U)
#  endif
#  if (defined RTE_CONST_NTC_Num_TmpMonFunc) || (defined NTC_Num_TmpMonFunc)
#   if (!defined RTE_CONST_NTC_Num_TmpMonFunc) || (RTE_CONST_NTC_Num_TmpMonFunc != 64U)
#    error "Enumeration constant <NTC_Num_TmpMonFunc> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_TmpMonFunc (64U)
#   define NTC_Num_TmpMonFunc (64U)
#  endif
#  if (defined RTE_CONST_NTC_Num_Thermistor) || (defined NTC_Num_Thermistor)
#   if (!defined RTE_CONST_NTC_Num_Thermistor) || (RTE_CONST_NTC_Num_Thermistor != 69U)
#    error "Enumeration constant <NTC_Num_Thermistor> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_Thermistor (69U)
#   define NTC_Num_Thermistor (69U)
#  endif
#  if (defined RTE_CONST_NTC_Num_GateDrvFlt) || (defined NTC_Num_GateDrvFlt)
#   if (!defined RTE_CONST_NTC_Num_GateDrvFlt) || (RTE_CONST_NTC_Num_GateDrvFlt != 77U)
#    error "Enumeration constant <NTC_Num_GateDrvFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_GateDrvFlt (77U)
#   define NTC_Num_GateDrvFlt (77U)
#  endif
#  if (defined RTE_CONST_NTC_Num_OnStateSingleFET) || (defined NTC_Num_OnStateSingleFET)
#   if (!defined RTE_CONST_NTC_Num_OnStateSingleFET) || (RTE_CONST_NTC_Num_OnStateSingleFET != 78U)
#    error "Enumeration constant <NTC_Num_OnStateSingleFET> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_OnStateSingleFET (78U)
#   define NTC_Num_OnStateSingleFET (78U)
#  endif
#  if (defined RTE_CONST_NTC_Num_OnStateMultiFET) || (defined NTC_Num_OnStateMultiFET)
#   if (!defined RTE_CONST_NTC_Num_OnStateMultiFET) || (RTE_CONST_NTC_Num_OnStateMultiFET != 79U)
#    error "Enumeration constant <NTC_Num_OnStateMultiFET> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_OnStateMultiFET (79U)
#   define NTC_Num_OnStateMultiFET (79U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PhaseVoltageVerf) || (defined NTC_Num_PhaseVoltageVerf)
#   if (!defined RTE_CONST_NTC_Num_PhaseVoltageVerf) || (RTE_CONST_NTC_Num_PhaseVoltageVerf != 80U)
#    error "Enumeration constant <NTC_Num_PhaseVoltageVerf> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PhaseVoltageVerf (80U)
#   define NTC_Num_PhaseVoltageVerf (80U)
#  endif
#  if (defined RTE_CONST_NTC_Num_HwTrqSensor) || (defined NTC_Num_HwTrqSensor)
#   if (!defined RTE_CONST_NTC_Num_HwTrqSensor) || (RTE_CONST_NTC_Num_HwTrqSensor != 96U)
#    error "Enumeration constant <NTC_Num_HwTrqSensor> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_HwTrqSensor (96U)
#   define NTC_Num_HwTrqSensor (96U)
#  endif
#  if (defined RTE_CONST_NTC_Num_TrqSensorNotTrimmed) || (defined NTC_Num_TrqSensorNotTrimmed)
#   if (!defined RTE_CONST_NTC_Num_TrqSensorNotTrimmed) || (RTE_CONST_NTC_Num_TrqSensorNotTrimmed != 97U)
#    error "Enumeration constant <NTC_Num_TrqSensorNotTrimmed> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_TrqSensorNotTrimmed (97U)
#   define NTC_Num_TrqSensorNotTrimmed (97U)
#  endif
#  if (defined RTE_CONST_NTC_Num_TrqSensorScaleNotSet) || (defined NTC_Num_TrqSensorScaleNotSet)
#   if (!defined RTE_CONST_NTC_Num_TrqSensorScaleNotSet) || (RTE_CONST_NTC_Num_TrqSensorScaleNotSet != 99U)
#    error "Enumeration constant <NTC_Num_TrqSensorScaleNotSet> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_TrqSensorScaleNotSet (99U)
#   define NTC_Num_TrqSensorScaleNotSet (99U)
#  endif
#  if (defined RTE_CONST_NTC_Num_TrqSensorScaleInvalid) || (defined NTC_Num_TrqSensorScaleInvalid)
#   if (!defined RTE_CONST_NTC_Num_TrqSensorScaleInvalid) || (RTE_CONST_NTC_Num_TrqSensorScaleInvalid != 100U)
#    error "Enumeration constant <NTC_Num_TrqSensorScaleInvalid> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_TrqSensorScaleInvalid (100U)
#   define NTC_Num_TrqSensorScaleInvalid (100U)
#  endif
#  if (defined RTE_CONST_NTC_Num_T1vsT2) || (defined NTC_Num_T1vsT2)
#   if (!defined RTE_CONST_NTC_Num_T1vsT2) || (RTE_CONST_NTC_Num_T1vsT2 != 101U)
#    error "Enumeration constant <NTC_Num_T1vsT2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_T1vsT2 (101U)
#   define NTC_Num_T1vsT2 (101U)
#  endif
#  if (defined RTE_CONST_NTC_Num_T1OutofRange) || (defined NTC_Num_T1OutofRange)
#   if (!defined RTE_CONST_NTC_Num_T1OutofRange) || (RTE_CONST_NTC_Num_T1OutofRange != 102U)
#    error "Enumeration constant <NTC_Num_T1OutofRange> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_T1OutofRange (102U)
#   define NTC_Num_T1OutofRange (102U)
#  endif
#  if (defined RTE_CONST_NTC_Num_T2OutofRange) || (defined NTC_Num_T2OutofRange)
#   if (!defined RTE_CONST_NTC_Num_T2OutofRange) || (RTE_CONST_NTC_Num_T2OutofRange != 103U)
#    error "Enumeration constant <NTC_Num_T2OutofRange> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_T2OutofRange (103U)
#   define NTC_Num_T2OutofRange (103U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DigT1vsT2) || (defined NTC_Num_DigT1vsT2)
#   if (!defined RTE_CONST_NTC_Num_DigT1vsT2) || (RTE_CONST_NTC_Num_DigT1vsT2 != 104U)
#    error "Enumeration constant <NTC_Num_DigT1vsT2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DigT1vsT2 (104U)
#   define NTC_Num_DigT1vsT2 (104U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DigT1OutofRange) || (defined NTC_Num_DigT1OutofRange)
#   if (!defined RTE_CONST_NTC_Num_DigT1OutofRange) || (RTE_CONST_NTC_Num_DigT1OutofRange != 105U)
#    error "Enumeration constant <NTC_Num_DigT1OutofRange> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DigT1OutofRange (105U)
#   define NTC_Num_DigT1OutofRange (105U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DigT2OutofRange) || (defined NTC_Num_DigT2OutofRange)
#   if (!defined RTE_CONST_NTC_Num_DigT2OutofRange) || (RTE_CONST_NTC_Num_DigT2OutofRange != 106U)
#    error "Enumeration constant <NTC_Num_DigT2OutofRange> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DigT2OutofRange (106U)
#   define NTC_Num_DigT2OutofRange (106U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PriMSB_SinCosCorr) || (defined NTC_Num_PriMSB_SinCosCorr)
#   if (!defined RTE_CONST_NTC_Num_PriMSB_SinCosCorr) || (RTE_CONST_NTC_Num_PriMSB_SinCosCorr != 112U)
#    error "Enumeration constant <NTC_Num_PriMSB_SinCosCorr> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PriMSB_SinCosCorr (112U)
#   define NTC_Num_PriMSB_SinCosCorr (112U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PriVsSec_SinCosCorr) || (defined NTC_Num_PriVsSec_SinCosCorr)
#   if (!defined RTE_CONST_NTC_Num_PriVsSec_SinCosCorr) || (RTE_CONST_NTC_Num_PriVsSec_SinCosCorr != 114U)
#    error "Enumeration constant <NTC_Num_PriVsSec_SinCosCorr> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PriVsSec_SinCosCorr (114U)
#   define NTC_Num_PriVsSec_SinCosCorr (114U)
#  endif
#  if (defined RTE_CONST_NTC_Num_TrqSensorRecoveryFlt) || (defined NTC_Num_TrqSensorRecoveryFlt)
#   if (!defined RTE_CONST_NTC_Num_TrqSensorRecoveryFlt) || (RTE_CONST_NTC_Num_TrqSensorRecoveryFlt != 122U)
#    error "Enumeration constant <NTC_Num_TrqSensorRecoveryFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_TrqSensorRecoveryFlt (122U)
#   define NTC_Num_TrqSensorRecoveryFlt (122U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DigTrqSensorScaleInvalid) || (defined NTC_Num_DigTrqSensorScaleInvalid)
#   if (!defined RTE_CONST_NTC_Num_DigTrqSensorScaleInvalid) || (RTE_CONST_NTC_Num_DigTrqSensorScaleInvalid != 123U)
#    error "Enumeration constant <NTC_Num_DigTrqSensorScaleInvalid> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DigTrqSensorScaleInvalid (123U)
#   define NTC_Num_DigTrqSensorScaleInvalid (123U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed) || (defined NTC_Num_DigTrqSensorNotTrimmed)
#   if (!defined RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed) || (RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed != 124U)
#    error "Enumeration constant <NTC_Num_DigTrqSensorNotTrimmed> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed (124U)
#   define NTC_Num_DigTrqSensorNotTrimmed (124U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet) || (defined NTC_Num_DigTrqSensorScaleNotSet)
#   if (!defined RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet) || (RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet != 125U)
#    error "Enumeration constant <NTC_Num_DigTrqSensorScaleNotSet> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet (125U)
#   define NTC_Num_DigTrqSensorScaleNotSet (125U)
#  endif
#  if (defined RTE_CONST_NTC_Num_AnaVsDigHwTrq) || (defined NTC_Num_AnaVsDigHwTrq)
#   if (!defined RTE_CONST_NTC_Num_AnaVsDigHwTrq) || (RTE_CONST_NTC_Num_AnaVsDigHwTrq != 126U)
#    error "Enumeration constant <NTC_Num_AnaVsDigHwTrq> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_AnaVsDigHwTrq (126U)
#   define NTC_Num_AnaVsDigHwTrq (126U)
#  endif
#  if (defined RTE_CONST_NTC_Num_KinematicIntDiag) || (defined NTC_Num_KinematicIntDiag)
#   if (!defined RTE_CONST_NTC_Num_KinematicIntDiag) || (RTE_CONST_NTC_Num_KinematicIntDiag != 144U)
#    error "Enumeration constant <NTC_Num_KinematicIntDiag> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_KinematicIntDiag (144U)
#   define NTC_Num_KinematicIntDiag (144U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DutyCycleExceeded) || (defined NTC_Num_DutyCycleExceeded)
#   if (!defined RTE_CONST_NTC_Num_DutyCycleExceeded) || (RTE_CONST_NTC_Num_DutyCycleExceeded != 148U)
#    error "Enumeration constant <NTC_Num_DutyCycleExceeded> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DutyCycleExceeded (148U)
#   define NTC_Num_DutyCycleExceeded (148U)
#  endif
#  if (defined RTE_CONST_NTC_Num_AbsTempThermLimit) || (defined NTC_Num_AbsTempThermLimit)
#   if (!defined RTE_CONST_NTC_Num_AbsTempThermLimit) || (RTE_CONST_NTC_Num_AbsTempThermLimit != 149U)
#    error "Enumeration constant <NTC_Num_AbsTempThermLimit> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_AbsTempThermLimit (149U)
#   define NTC_Num_AbsTempThermLimit (149U)
#  endif
#  if (defined RTE_CONST_NTC_Num_ReducedAsstLowVoltage) || (defined NTC_Num_ReducedAsstLowVoltage)
#   if (!defined RTE_CONST_NTC_Num_ReducedAsstLowVoltage) || (RTE_CONST_NTC_Num_ReducedAsstLowVoltage != 178U)
#    error "Enumeration constant <NTC_Num_ReducedAsstLowVoltage> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_ReducedAsstLowVoltage (178U)
#   define NTC_Num_ReducedAsstLowVoltage (178U)
#  endif
#  if (defined RTE_CONST_NTC_Num_OpVoltageHigh) || (defined NTC_Num_OpVoltageHigh)
#   if (!defined RTE_CONST_NTC_Num_OpVoltageHigh) || (RTE_CONST_NTC_Num_OpVoltageHigh != 179U)
#    error "Enumeration constant <NTC_Num_OpVoltageHigh> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_OpVoltageHigh (179U)
#   define NTC_Num_OpVoltageHigh (179U)
#  endif
#  if (defined RTE_CONST_NTC_Num_OpVoltageLow) || (defined NTC_Num_OpVoltageLow)
#   if (!defined RTE_CONST_NTC_Num_OpVoltageLow) || (RTE_CONST_NTC_Num_OpVoltageLow != 180U)
#    error "Enumeration constant <NTC_Num_OpVoltageLow> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_OpVoltageLow (180U)
#   define NTC_Num_OpVoltageLow (180U)
#  endif
#  if (defined RTE_CONST_NTC_Num_IgnConfDiag) || (defined NTC_Num_IgnConfDiag)
#   if (!defined RTE_CONST_NTC_Num_IgnConfDiag) || (RTE_CONST_NTC_Num_IgnConfDiag != 181U)
#    error "Enumeration constant <NTC_Num_IgnConfDiag> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_IgnConfDiag (181U)
#   define NTC_Num_IgnConfDiag (181U)
#  endif
#  if (defined RTE_CONST_NTC_Num_EEPROMCloseFailed) || (defined NTC_Num_EEPROMCloseFailed)
#   if (!defined RTE_CONST_NTC_Num_EEPROMCloseFailed) || (RTE_CONST_NTC_Num_EEPROMCloseFailed != 191U)
#    error "Enumeration constant <NTC_Num_EEPROMCloseFailed> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_EEPROMCloseFailed (191U)
#   define NTC_Num_EEPROMCloseFailed (191U)
#  endif
#  if (defined RTE_CONST_NTC_Num_WhlImbAlgFlt) || (defined NTC_Num_WhlImbAlgFlt)
#   if (!defined RTE_CONST_NTC_Num_WhlImbAlgFlt) || (RTE_CONST_NTC_Num_WhlImbAlgFlt != 224U)
#    error "Enumeration constant <NTC_Num_WhlImbAlgFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_WhlImbAlgFlt (224U)
#   define NTC_Num_WhlImbAlgFlt (224U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PAHwVelFlt) || (defined NTC_Num_PAHwVelFlt)
#   if (!defined RTE_CONST_NTC_Num_PAHwVelFlt) || (RTE_CONST_NTC_Num_PAHwVelFlt != 225U)
#    error "Enumeration constant <NTC_Num_PAHwVelFlt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PAHwVelFlt (225U)
#   define NTC_Num_PAHwVelFlt (225U)
#  endif
#  if (defined RTE_CONST_NTC_Num_BusOffCh1) || (defined NTC_Num_BusOffCh1)
#   if (!defined RTE_CONST_NTC_Num_BusOffCh1) || (RTE_CONST_NTC_Num_BusOffCh1 != 256U)
#    error "Enumeration constant <NTC_Num_BusOffCh1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_BusOffCh1 (256U)
#   define NTC_Num_BusOffCh1 (256U)
#  endif
#  if (defined RTE_CONST_NTC_Num_BusOffCh2) || (defined NTC_Num_BusOffCh2)
#   if (!defined RTE_CONST_NTC_Num_BusOffCh2) || (RTE_CONST_NTC_Num_BusOffCh2 != 272U)
#    error "Enumeration constant <NTC_Num_BusOffCh2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_BusOffCh2 (272U)
#   define NTC_Num_BusOffCh2 (272U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_M) || (defined NTC_Num_InvalidMsg_M)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_M) || (RTE_CONST_NTC_Num_InvalidMsg_M != 288U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_M> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_M (288U)
#   define NTC_Num_InvalidMsg_M (288U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_M) || (defined NTC_Num_MissingMsg_M)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_M) || (RTE_CONST_NTC_Num_MissingMsg_M != 289U)
#    error "Enumeration constant <NTC_Num_MissingMsg_M> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_M (289U)
#   define NTC_Num_MissingMsg_M (289U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_M) || (defined NTC_Num_CRCFltMsg_M)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_M) || (RTE_CONST_NTC_Num_CRCFltMsg_M != 290U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_M> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_M (290U)
#   define NTC_Num_CRCFltMsg_M (290U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_M) || (defined NTC_Num_PgrsCntFltMsg_M)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_M) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_M != 291U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_M> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_M (291U)
#   define NTC_Num_PgrsCntFltMsg_M (291U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_M) || (defined NTC_Num_DataRngFltMsg_M)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_M) || (RTE_CONST_NTC_Num_DataRngFltMsg_M != 292U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_M> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_M (292U)
#   define NTC_Num_DataRngFltMsg_M (292U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_M) || (defined NTC_Num_DataRateFltMsg_M)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_M) || (RTE_CONST_NTC_Num_DataRateFltMsg_M != 293U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_M> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_M (293U)
#   define NTC_Num_DataRateFltMsg_M (293U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_M) || (defined NTC_Num_DataOtherFltMsg_M)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_M) || (RTE_CONST_NTC_Num_DataOtherFltMsg_M != 294U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_M> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_M (294U)
#   define NTC_Num_DataOtherFltMsg_M (294U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_N) || (defined NTC_Num_InvalidMsg_N)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_N) || (RTE_CONST_NTC_Num_InvalidMsg_N != 296U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_N> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_N (296U)
#   define NTC_Num_InvalidMsg_N (296U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_N) || (defined NTC_Num_MissingMsg_N)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_N) || (RTE_CONST_NTC_Num_MissingMsg_N != 297U)
#    error "Enumeration constant <NTC_Num_MissingMsg_N> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_N (297U)
#   define NTC_Num_MissingMsg_N (297U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_N) || (defined NTC_Num_CRCFltMsg_N)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_N) || (RTE_CONST_NTC_Num_CRCFltMsg_N != 298U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_N> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_N (298U)
#   define NTC_Num_CRCFltMsg_N (298U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_N) || (defined NTC_Num_PgrsCntFltMsg_N)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_N) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_N != 299U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_N> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_N (299U)
#   define NTC_Num_PgrsCntFltMsg_N (299U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_N) || (defined NTC_Num_DataRngFltMsg_N)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_N) || (RTE_CONST_NTC_Num_DataRngFltMsg_N != 300U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_N> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_N (300U)
#   define NTC_Num_DataRngFltMsg_N (300U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_N) || (defined NTC_Num_DataRateFltMsg_N)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_N) || (RTE_CONST_NTC_Num_DataRateFltMsg_N != 301U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_N> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_N (301U)
#   define NTC_Num_DataRateFltMsg_N (301U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_N) || (defined NTC_Num_DataOtherFltMsg_N)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_N) || (RTE_CONST_NTC_Num_DataOtherFltMsg_N != 302U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_N> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_N (302U)
#   define NTC_Num_DataOtherFltMsg_N (302U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_O) || (defined NTC_Num_InvalidMsg_O)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_O) || (RTE_CONST_NTC_Num_InvalidMsg_O != 304U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_O> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_O (304U)
#   define NTC_Num_InvalidMsg_O (304U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_O) || (defined NTC_Num_MissingMsg_O)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_O) || (RTE_CONST_NTC_Num_MissingMsg_O != 305U)
#    error "Enumeration constant <NTC_Num_MissingMsg_O> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_O (305U)
#   define NTC_Num_MissingMsg_O (305U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_O) || (defined NTC_Num_CRCFltMsg_O)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_O) || (RTE_CONST_NTC_Num_CRCFltMsg_O != 306U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_O> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_O (306U)
#   define NTC_Num_CRCFltMsg_O (306U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_O) || (defined NTC_Num_PgrsCntFltMsg_O)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_O) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_O != 307U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_O> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_O (307U)
#   define NTC_Num_PgrsCntFltMsg_O (307U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_O) || (defined NTC_Num_DataRngFltMsg_O)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_O) || (RTE_CONST_NTC_Num_DataRngFltMsg_O != 308U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_O> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_O (308U)
#   define NTC_Num_DataRngFltMsg_O (308U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_O) || (defined NTC_Num_DataRateFltMsg_O)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_O) || (RTE_CONST_NTC_Num_DataRateFltMsg_O != 309U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_O> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_O (309U)
#   define NTC_Num_DataRateFltMsg_O (309U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_O) || (defined NTC_Num_DataOtherFltMsg_O)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_O) || (RTE_CONST_NTC_Num_DataOtherFltMsg_O != 310U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_O> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_O (310U)
#   define NTC_Num_DataOtherFltMsg_O (310U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_P) || (defined NTC_Num_InvalidMsg_P)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_P) || (RTE_CONST_NTC_Num_InvalidMsg_P != 312U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_P> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_P (312U)
#   define NTC_Num_InvalidMsg_P (312U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_P) || (defined NTC_Num_MissingMsg_P)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_P) || (RTE_CONST_NTC_Num_MissingMsg_P != 313U)
#    error "Enumeration constant <NTC_Num_MissingMsg_P> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_P (313U)
#   define NTC_Num_MissingMsg_P (313U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_P) || (defined NTC_Num_CRCFltMsg_P)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_P) || (RTE_CONST_NTC_Num_CRCFltMsg_P != 314U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_P> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_P (314U)
#   define NTC_Num_CRCFltMsg_P (314U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_P) || (defined NTC_Num_PgrsCntFltMsg_P)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_P) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_P != 315U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_P> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_P (315U)
#   define NTC_Num_PgrsCntFltMsg_P (315U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_P) || (defined NTC_Num_DataRngFltMsg_P)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_P) || (RTE_CONST_NTC_Num_DataRngFltMsg_P != 316U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_P> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_P (316U)
#   define NTC_Num_DataRngFltMsg_P (316U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_P) || (defined NTC_Num_DataRateFltMsg_P)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_P) || (RTE_CONST_NTC_Num_DataRateFltMsg_P != 317U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_P> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_P (317U)
#   define NTC_Num_DataRateFltMsg_P (317U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_P) || (defined NTC_Num_DataOtherFltMsg_P)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_P) || (RTE_CONST_NTC_Num_DataOtherFltMsg_P != 318U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_P> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_P (318U)
#   define NTC_Num_DataOtherFltMsg_P (318U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_Q) || (defined NTC_Num_InvalidMsg_Q)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_Q) || (RTE_CONST_NTC_Num_InvalidMsg_Q != 320U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_Q> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_Q (320U)
#   define NTC_Num_InvalidMsg_Q (320U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_Q) || (defined NTC_Num_MissingMsg_Q)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_Q) || (RTE_CONST_NTC_Num_MissingMsg_Q != 321U)
#    error "Enumeration constant <NTC_Num_MissingMsg_Q> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_Q (321U)
#   define NTC_Num_MissingMsg_Q (321U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_Q) || (defined NTC_Num_CRCFltMsg_Q)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Q) || (RTE_CONST_NTC_Num_CRCFltMsg_Q != 322U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_Q> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_Q (322U)
#   define NTC_Num_CRCFltMsg_Q (322U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Q) || (defined NTC_Num_PgrsCntFltMsg_Q)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Q) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Q != 323U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Q> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_Q (323U)
#   define NTC_Num_PgrsCntFltMsg_Q (323U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Q) || (defined NTC_Num_DataRngFltMsg_Q)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Q) || (RTE_CONST_NTC_Num_DataRngFltMsg_Q != 324U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_Q> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_Q (324U)
#   define NTC_Num_DataRngFltMsg_Q (324U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Q) || (defined NTC_Num_DataRateFltMsg_Q)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Q) || (RTE_CONST_NTC_Num_DataRateFltMsg_Q != 325U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_Q> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_Q (325U)
#   define NTC_Num_DataRateFltMsg_Q (325U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Q) || (defined NTC_Num_DataOtherFltMsg_Q)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Q) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Q != 326U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_Q> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_Q (326U)
#   define NTC_Num_DataOtherFltMsg_Q (326U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_R) || (defined NTC_Num_InvalidMsg_R)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_R) || (RTE_CONST_NTC_Num_InvalidMsg_R != 328U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_R> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_R (328U)
#   define NTC_Num_InvalidMsg_R (328U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_R) || (defined NTC_Num_MissingMsg_R)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_R) || (RTE_CONST_NTC_Num_MissingMsg_R != 329U)
#    error "Enumeration constant <NTC_Num_MissingMsg_R> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_R (329U)
#   define NTC_Num_MissingMsg_R (329U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_R) || (defined NTC_Num_CRCFltMsg_R)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_R) || (RTE_CONST_NTC_Num_CRCFltMsg_R != 330U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_R> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_R (330U)
#   define NTC_Num_CRCFltMsg_R (330U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_R) || (defined NTC_Num_PgrsCntFltMsg_R)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_R) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_R != 331U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_R> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_R (331U)
#   define NTC_Num_PgrsCntFltMsg_R (331U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_R) || (defined NTC_Num_DataRngFltMsg_R)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_R) || (RTE_CONST_NTC_Num_DataRngFltMsg_R != 332U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_R> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_R (332U)
#   define NTC_Num_DataRngFltMsg_R (332U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_R) || (defined NTC_Num_DataRateFltMsg_R)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_R) || (RTE_CONST_NTC_Num_DataRateFltMsg_R != 333U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_R> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_R (333U)
#   define NTC_Num_DataRateFltMsg_R (333U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_R) || (defined NTC_Num_DataOtherFltMsg_R)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_R) || (RTE_CONST_NTC_Num_DataOtherFltMsg_R != 334U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_R> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_R (334U)
#   define NTC_Num_DataOtherFltMsg_R (334U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_S) || (defined NTC_Num_InvalidMsg_S)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_S) || (RTE_CONST_NTC_Num_InvalidMsg_S != 336U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_S> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_S (336U)
#   define NTC_Num_InvalidMsg_S (336U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_S) || (defined NTC_Num_MissingMsg_S)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_S) || (RTE_CONST_NTC_Num_MissingMsg_S != 337U)
#    error "Enumeration constant <NTC_Num_MissingMsg_S> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_S (337U)
#   define NTC_Num_MissingMsg_S (337U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_S) || (defined NTC_Num_CRCFltMsg_S)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_S) || (RTE_CONST_NTC_Num_CRCFltMsg_S != 338U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_S> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_S (338U)
#   define NTC_Num_CRCFltMsg_S (338U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_S) || (defined NTC_Num_PgrsCntFltMsg_S)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_S) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_S != 339U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_S> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_S (339U)
#   define NTC_Num_PgrsCntFltMsg_S (339U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_S) || (defined NTC_Num_DataRngFltMsg_S)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_S) || (RTE_CONST_NTC_Num_DataRngFltMsg_S != 340U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_S> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_S (340U)
#   define NTC_Num_DataRngFltMsg_S (340U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_S) || (defined NTC_Num_DataRateFltMsg_S)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_S) || (RTE_CONST_NTC_Num_DataRateFltMsg_S != 341U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_S> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_S (341U)
#   define NTC_Num_DataRateFltMsg_S (341U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_S) || (defined NTC_Num_DataOtherFltMsg_S)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_S) || (RTE_CONST_NTC_Num_DataOtherFltMsg_S != 342U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_S> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_S (342U)
#   define NTC_Num_DataOtherFltMsg_S (342U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_T) || (defined NTC_Num_InvalidMsg_T)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_T) || (RTE_CONST_NTC_Num_InvalidMsg_T != 344U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_T> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_T (344U)
#   define NTC_Num_InvalidMsg_T (344U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_T) || (defined NTC_Num_MissingMsg_T)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_T) || (RTE_CONST_NTC_Num_MissingMsg_T != 345U)
#    error "Enumeration constant <NTC_Num_MissingMsg_T> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_T (345U)
#   define NTC_Num_MissingMsg_T (345U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_T) || (defined NTC_Num_CRCFltMsg_T)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_T) || (RTE_CONST_NTC_Num_CRCFltMsg_T != 346U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_T> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_T (346U)
#   define NTC_Num_CRCFltMsg_T (346U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_T) || (defined NTC_Num_PgrsCntFltMsg_T)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_T) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_T != 347U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_T> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_T (347U)
#   define NTC_Num_PgrsCntFltMsg_T (347U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_T) || (defined NTC_Num_DataRngFltMsg_T)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_T) || (RTE_CONST_NTC_Num_DataRngFltMsg_T != 348U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_T> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_T (348U)
#   define NTC_Num_DataRngFltMsg_T (348U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_T) || (defined NTC_Num_DataRateFltMsg_T)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_T) || (RTE_CONST_NTC_Num_DataRateFltMsg_T != 349U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_T> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_T (349U)
#   define NTC_Num_DataRateFltMsg_T (349U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_T) || (defined NTC_Num_DataOtherFltMsg_T)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_T) || (RTE_CONST_NTC_Num_DataOtherFltMsg_T != 350U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_T> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_T (350U)
#   define NTC_Num_DataOtherFltMsg_T (350U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_U) || (defined NTC_Num_InvalidMsg_U)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_U) || (RTE_CONST_NTC_Num_InvalidMsg_U != 352U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_U> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_U (352U)
#   define NTC_Num_InvalidMsg_U (352U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_U) || (defined NTC_Num_MissingMsg_U)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_U) || (RTE_CONST_NTC_Num_MissingMsg_U != 353U)
#    error "Enumeration constant <NTC_Num_MissingMsg_U> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_U (353U)
#   define NTC_Num_MissingMsg_U (353U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_U) || (defined NTC_Num_CRCFltMsg_U)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_U) || (RTE_CONST_NTC_Num_CRCFltMsg_U != 354U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_U> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_U (354U)
#   define NTC_Num_CRCFltMsg_U (354U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_U) || (defined NTC_Num_PgrsCntFltMsg_U)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_U) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_U != 355U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_U> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_U (355U)
#   define NTC_Num_PgrsCntFltMsg_U (355U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_U) || (defined NTC_Num_DataRngFltMsg_U)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_U) || (RTE_CONST_NTC_Num_DataRngFltMsg_U != 356U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_U> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_U (356U)
#   define NTC_Num_DataRngFltMsg_U (356U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_U) || (defined NTC_Num_DataRateFltMsg_U)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_U) || (RTE_CONST_NTC_Num_DataRateFltMsg_U != 357U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_U> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_U (357U)
#   define NTC_Num_DataRateFltMsg_U (357U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_U) || (defined NTC_Num_DataOtherFltMsg_U)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_U) || (RTE_CONST_NTC_Num_DataOtherFltMsg_U != 358U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_U> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_U (358U)
#   define NTC_Num_DataOtherFltMsg_U (358U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_V) || (defined NTC_Num_InvalidMsg_V)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_V) || (RTE_CONST_NTC_Num_InvalidMsg_V != 360U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_V> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_V (360U)
#   define NTC_Num_InvalidMsg_V (360U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_V) || (defined NTC_Num_MissingMsg_V)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_V) || (RTE_CONST_NTC_Num_MissingMsg_V != 361U)
#    error "Enumeration constant <NTC_Num_MissingMsg_V> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_V (361U)
#   define NTC_Num_MissingMsg_V (361U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_V) || (defined NTC_Num_CRCFltMsg_V)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_V) || (RTE_CONST_NTC_Num_CRCFltMsg_V != 362U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_V> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_V (362U)
#   define NTC_Num_CRCFltMsg_V (362U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_V) || (defined NTC_Num_PgrsCntFltMsg_V)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_V) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_V != 363U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_V> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_V (363U)
#   define NTC_Num_PgrsCntFltMsg_V (363U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_V) || (defined NTC_Num_DataRngFltMsg_V)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_V) || (RTE_CONST_NTC_Num_DataRngFltMsg_V != 364U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_V> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_V (364U)
#   define NTC_Num_DataRngFltMsg_V (364U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_V) || (defined NTC_Num_DataRateFltMsg_V)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_V) || (RTE_CONST_NTC_Num_DataRateFltMsg_V != 365U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_V> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_V (365U)
#   define NTC_Num_DataRateFltMsg_V (365U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_V) || (defined NTC_Num_DataOtherFltMsg_V)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_V) || (RTE_CONST_NTC_Num_DataOtherFltMsg_V != 366U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_V> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_V (366U)
#   define NTC_Num_DataOtherFltMsg_V (366U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_W) || (defined NTC_Num_InvalidMsg_W)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_W) || (RTE_CONST_NTC_Num_InvalidMsg_W != 368U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_W> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_W (368U)
#   define NTC_Num_InvalidMsg_W (368U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_W) || (defined NTC_Num_MissingMsg_W)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_W) || (RTE_CONST_NTC_Num_MissingMsg_W != 369U)
#    error "Enumeration constant <NTC_Num_MissingMsg_W> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_W (369U)
#   define NTC_Num_MissingMsg_W (369U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_W) || (defined NTC_Num_CRCFltMsg_W)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_W) || (RTE_CONST_NTC_Num_CRCFltMsg_W != 370U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_W> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_W (370U)
#   define NTC_Num_CRCFltMsg_W (370U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_W) || (defined NTC_Num_PgrsCntFltMsg_W)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_W) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_W != 371U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_W> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_W (371U)
#   define NTC_Num_PgrsCntFltMsg_W (371U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_W) || (defined NTC_Num_DataRngFltMsg_W)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_W) || (RTE_CONST_NTC_Num_DataRngFltMsg_W != 372U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_W> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_W (372U)
#   define NTC_Num_DataRngFltMsg_W (372U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_W) || (defined NTC_Num_DataRateFltMsg_W)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_W) || (RTE_CONST_NTC_Num_DataRateFltMsg_W != 373U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_W> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_W (373U)
#   define NTC_Num_DataRateFltMsg_W (373U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_W) || (defined NTC_Num_DataOtherFltMsg_W)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_W) || (RTE_CONST_NTC_Num_DataOtherFltMsg_W != 374U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_W> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_W (374U)
#   define NTC_Num_DataOtherFltMsg_W (374U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_X) || (defined NTC_Num_InvalidMsg_X)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_X) || (RTE_CONST_NTC_Num_InvalidMsg_X != 376U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_X> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_X (376U)
#   define NTC_Num_InvalidMsg_X (376U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_X) || (defined NTC_Num_MissingMsg_X)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_X) || (RTE_CONST_NTC_Num_MissingMsg_X != 377U)
#    error "Enumeration constant <NTC_Num_MissingMsg_X> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_X (377U)
#   define NTC_Num_MissingMsg_X (377U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_X) || (defined NTC_Num_CRCFltMsg_X)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_X) || (RTE_CONST_NTC_Num_CRCFltMsg_X != 378U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_X> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_X (378U)
#   define NTC_Num_CRCFltMsg_X (378U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_X) || (defined NTC_Num_PgrsCntFltMsg_X)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_X) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_X != 379U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_X> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_X (379U)
#   define NTC_Num_PgrsCntFltMsg_X (379U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_X) || (defined NTC_Num_DataRngFltMsg_X)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_X) || (RTE_CONST_NTC_Num_DataRngFltMsg_X != 380U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_X> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_X (380U)
#   define NTC_Num_DataRngFltMsg_X (380U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_X) || (defined NTC_Num_DataRateFltMsg_X)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_X) || (RTE_CONST_NTC_Num_DataRateFltMsg_X != 381U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_X> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_X (381U)
#   define NTC_Num_DataRateFltMsg_X (381U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_X) || (defined NTC_Num_DataOtherFltMsg_X)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_X) || (RTE_CONST_NTC_Num_DataOtherFltMsg_X != 382U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_X> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_X (382U)
#   define NTC_Num_DataOtherFltMsg_X (382U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_Y) || (defined NTC_Num_InvalidMsg_Y)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_Y) || (RTE_CONST_NTC_Num_InvalidMsg_Y != 384U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_Y> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_Y (384U)
#   define NTC_Num_InvalidMsg_Y (384U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_Y) || (defined NTC_Num_MissingMsg_Y)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_Y) || (RTE_CONST_NTC_Num_MissingMsg_Y != 385U)
#    error "Enumeration constant <NTC_Num_MissingMsg_Y> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_Y (385U)
#   define NTC_Num_MissingMsg_Y (385U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_Y) || (defined NTC_Num_CRCFltMsg_Y)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Y) || (RTE_CONST_NTC_Num_CRCFltMsg_Y != 386U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_Y> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_Y (386U)
#   define NTC_Num_CRCFltMsg_Y (386U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Y) || (defined NTC_Num_PgrsCntFltMsg_Y)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Y) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Y != 387U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Y> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_Y (387U)
#   define NTC_Num_PgrsCntFltMsg_Y (387U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Y) || (defined NTC_Num_DataRngFltMsg_Y)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Y) || (RTE_CONST_NTC_Num_DataRngFltMsg_Y != 388U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_Y> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_Y (388U)
#   define NTC_Num_DataRngFltMsg_Y (388U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Y) || (defined NTC_Num_DataRateFltMsg_Y)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Y) || (RTE_CONST_NTC_Num_DataRateFltMsg_Y != 389U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_Y> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_Y (389U)
#   define NTC_Num_DataRateFltMsg_Y (389U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Y) || (defined NTC_Num_DataOtherFltMsg_Y)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Y) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Y != 390U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_Y> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_Y (390U)
#   define NTC_Num_DataOtherFltMsg_Y (390U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_Z) || (defined NTC_Num_InvalidMsg_Z)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_Z) || (RTE_CONST_NTC_Num_InvalidMsg_Z != 392U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_Z> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_Z (392U)
#   define NTC_Num_InvalidMsg_Z (392U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_Z) || (defined NTC_Num_MissingMsg_Z)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_Z) || (RTE_CONST_NTC_Num_MissingMsg_Z != 393U)
#    error "Enumeration constant <NTC_Num_MissingMsg_Z> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_Z (393U)
#   define NTC_Num_MissingMsg_Z (393U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_Z) || (defined NTC_Num_CRCFltMsg_Z)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Z) || (RTE_CONST_NTC_Num_CRCFltMsg_Z != 394U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_Z> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_Z (394U)
#   define NTC_Num_CRCFltMsg_Z (394U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Z) || (defined NTC_Num_PgrsCntFltMsg_Z)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Z) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Z != 395U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Z> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_Z (395U)
#   define NTC_Num_PgrsCntFltMsg_Z (395U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Z) || (defined NTC_Num_DataRngFltMsg_Z)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Z) || (RTE_CONST_NTC_Num_DataRngFltMsg_Z != 396U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_Z> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_Z (396U)
#   define NTC_Num_DataRngFltMsg_Z (396U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Z) || (defined NTC_Num_DataRateFltMsg_Z)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Z) || (RTE_CONST_NTC_Num_DataRateFltMsg_Z != 397U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_Z> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_Z (397U)
#   define NTC_Num_DataRateFltMsg_Z (397U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Z) || (defined NTC_Num_DataOtherFltMsg_Z)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Z) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Z != 398U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_Z> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_Z (398U)
#   define NTC_Num_DataOtherFltMsg_Z (398U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_AA) || (defined NTC_Num_InvalidMsg_AA)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_AA) || (RTE_CONST_NTC_Num_InvalidMsg_AA != 400U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_AA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_AA (400U)
#   define NTC_Num_InvalidMsg_AA (400U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_AA) || (defined NTC_Num_MissingMsg_AA)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_AA) || (RTE_CONST_NTC_Num_MissingMsg_AA != 401U)
#    error "Enumeration constant <NTC_Num_MissingMsg_AA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_AA (401U)
#   define NTC_Num_MissingMsg_AA (401U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_AA) || (defined NTC_Num_CRCFltMsg_AA)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AA) || (RTE_CONST_NTC_Num_CRCFltMsg_AA != 402U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_AA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_AA (402U)
#   define NTC_Num_CRCFltMsg_AA (402U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AA) || (defined NTC_Num_PgrsCntFltMsg_AA)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AA) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AA != 403U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_AA (403U)
#   define NTC_Num_PgrsCntFltMsg_AA (403U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AA) || (defined NTC_Num_DataRngFltMsg_AA)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AA) || (RTE_CONST_NTC_Num_DataRngFltMsg_AA != 404U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_AA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_AA (404U)
#   define NTC_Num_DataRngFltMsg_AA (404U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AA) || (defined NTC_Num_DataRateFltMsg_AA)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AA) || (RTE_CONST_NTC_Num_DataRateFltMsg_AA != 405U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_AA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_AA (405U)
#   define NTC_Num_DataRateFltMsg_AA (405U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AA) || (defined NTC_Num_DataOtherFltMsg_AA)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AA) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AA != 406U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_AA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_AA (406U)
#   define NTC_Num_DataOtherFltMsg_AA (406U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_AB) || (defined NTC_Num_InvalidMsg_AB)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_AB) || (RTE_CONST_NTC_Num_InvalidMsg_AB != 408U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_AB> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_AB (408U)
#   define NTC_Num_InvalidMsg_AB (408U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_AB) || (defined NTC_Num_MissingMsg_AB)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_AB) || (RTE_CONST_NTC_Num_MissingMsg_AB != 409U)
#    error "Enumeration constant <NTC_Num_MissingMsg_AB> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_AB (409U)
#   define NTC_Num_MissingMsg_AB (409U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_AB) || (defined NTC_Num_CRCFltMsg_AB)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AB) || (RTE_CONST_NTC_Num_CRCFltMsg_AB != 410U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_AB> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_AB (410U)
#   define NTC_Num_CRCFltMsg_AB (410U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AB) || (defined NTC_Num_PgrsCntFltMsg_AB)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AB) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AB != 411U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AB> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_AB (411U)
#   define NTC_Num_PgrsCntFltMsg_AB (411U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AB) || (defined NTC_Num_DataRngFltMsg_AB)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AB) || (RTE_CONST_NTC_Num_DataRngFltMsg_AB != 412U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_AB> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_AB (412U)
#   define NTC_Num_DataRngFltMsg_AB (412U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AB) || (defined NTC_Num_DataRateFltMsg_AB)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AB) || (RTE_CONST_NTC_Num_DataRateFltMsg_AB != 413U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_AB> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_AB (413U)
#   define NTC_Num_DataRateFltMsg_AB (413U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AB) || (defined NTC_Num_DataOtherFltMsg_AB)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AB) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AB != 414U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_AB> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_AB (414U)
#   define NTC_Num_DataOtherFltMsg_AB (414U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_AC) || (defined NTC_Num_InvalidMsg_AC)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_AC) || (RTE_CONST_NTC_Num_InvalidMsg_AC != 416U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_AC> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_AC (416U)
#   define NTC_Num_InvalidMsg_AC (416U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_AC) || (defined NTC_Num_MissingMsg_AC)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_AC) || (RTE_CONST_NTC_Num_MissingMsg_AC != 417U)
#    error "Enumeration constant <NTC_Num_MissingMsg_AC> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_AC (417U)
#   define NTC_Num_MissingMsg_AC (417U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_AC) || (defined NTC_Num_CRCFltMsg_AC)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AC) || (RTE_CONST_NTC_Num_CRCFltMsg_AC != 418U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_AC> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_AC (418U)
#   define NTC_Num_CRCFltMsg_AC (418U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AC) || (defined NTC_Num_PgrsCntFltMsg_AC)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AC) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AC != 419U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AC> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_AC (419U)
#   define NTC_Num_PgrsCntFltMsg_AC (419U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AC) || (defined NTC_Num_DataRngFltMsg_AC)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AC) || (RTE_CONST_NTC_Num_DataRngFltMsg_AC != 420U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_AC> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_AC (420U)
#   define NTC_Num_DataRngFltMsg_AC (420U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AC) || (defined NTC_Num_DataRateFltMsg_AC)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AC) || (RTE_CONST_NTC_Num_DataRateFltMsg_AC != 421U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_AC> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_AC (421U)
#   define NTC_Num_DataRateFltMsg_AC (421U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AC) || (defined NTC_Num_DataOtherFltMsg_AC)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AC) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AC != 422U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_AC> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_AC (422U)
#   define NTC_Num_DataOtherFltMsg_AC (422U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_AD) || (defined NTC_Num_InvalidMsg_AD)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_AD) || (RTE_CONST_NTC_Num_InvalidMsg_AD != 424U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_AD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_AD (424U)
#   define NTC_Num_InvalidMsg_AD (424U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_AD) || (defined NTC_Num_MissingMsg_AD)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_AD) || (RTE_CONST_NTC_Num_MissingMsg_AD != 425U)
#    error "Enumeration constant <NTC_Num_MissingMsg_AD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_AD (425U)
#   define NTC_Num_MissingMsg_AD (425U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_AD) || (defined NTC_Num_CRCFltMsg_AD)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AD) || (RTE_CONST_NTC_Num_CRCFltMsg_AD != 426U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_AD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_AD (426U)
#   define NTC_Num_CRCFltMsg_AD (426U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AD) || (defined NTC_Num_PgrsCntFltMsg_AD)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AD) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AD != 427U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_AD (427U)
#   define NTC_Num_PgrsCntFltMsg_AD (427U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AD) || (defined NTC_Num_DataRngFltMsg_AD)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AD) || (RTE_CONST_NTC_Num_DataRngFltMsg_AD != 428U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_AD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_AD (428U)
#   define NTC_Num_DataRngFltMsg_AD (428U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AD) || (defined NTC_Num_DataRateFltMsg_AD)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AD) || (RTE_CONST_NTC_Num_DataRateFltMsg_AD != 429U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_AD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_AD (429U)
#   define NTC_Num_DataRateFltMsg_AD (429U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AD) || (defined NTC_Num_DataOtherFltMsg_AD)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AD) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AD != 430U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_AD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_AD (430U)
#   define NTC_Num_DataOtherFltMsg_AD (430U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_AE) || (defined NTC_Num_InvalidMsg_AE)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_AE) || (RTE_CONST_NTC_Num_InvalidMsg_AE != 432U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_AE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_AE (432U)
#   define NTC_Num_InvalidMsg_AE (432U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_AE) || (defined NTC_Num_MissingMsg_AE)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_AE) || (RTE_CONST_NTC_Num_MissingMsg_AE != 433U)
#    error "Enumeration constant <NTC_Num_MissingMsg_AE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_AE (433U)
#   define NTC_Num_MissingMsg_AE (433U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_AE) || (defined NTC_Num_CRCFltMsg_AE)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AE) || (RTE_CONST_NTC_Num_CRCFltMsg_AE != 434U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_AE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_AE (434U)
#   define NTC_Num_CRCFltMsg_AE (434U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AE) || (defined NTC_Num_PgrsCntFltMsg_AE)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AE) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AE != 435U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_AE (435U)
#   define NTC_Num_PgrsCntFltMsg_AE (435U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AE) || (defined NTC_Num_DataRngFltMsg_AE)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AE) || (RTE_CONST_NTC_Num_DataRngFltMsg_AE != 436U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_AE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_AE (436U)
#   define NTC_Num_DataRngFltMsg_AE (436U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AE) || (defined NTC_Num_DataRateFltMsg_AE)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AE) || (RTE_CONST_NTC_Num_DataRateFltMsg_AE != 437U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_AE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_AE (437U)
#   define NTC_Num_DataRateFltMsg_AE (437U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AE) || (defined NTC_Num_DataOtherFltMsg_AE)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AE) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AE != 438U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_AE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_AE (438U)
#   define NTC_Num_DataOtherFltMsg_AE (438U)
#  endif
#  if (defined RTE_CONST_NTC_Num_InvalidMsg_AF) || (defined NTC_Num_InvalidMsg_AF)
#   if (!defined RTE_CONST_NTC_Num_InvalidMsg_AF) || (RTE_CONST_NTC_Num_InvalidMsg_AF != 440U)
#    error "Enumeration constant <NTC_Num_InvalidMsg_AF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_InvalidMsg_AF (440U)
#   define NTC_Num_InvalidMsg_AF (440U)
#  endif
#  if (defined RTE_CONST_NTC_Num_MissingMsg_AF) || (defined NTC_Num_MissingMsg_AF)
#   if (!defined RTE_CONST_NTC_Num_MissingMsg_AF) || (RTE_CONST_NTC_Num_MissingMsg_AF != 441U)
#    error "Enumeration constant <NTC_Num_MissingMsg_AF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_MissingMsg_AF (441U)
#   define NTC_Num_MissingMsg_AF (441U)
#  endif
#  if (defined RTE_CONST_NTC_Num_CRCFltMsg_AF) || (defined NTC_Num_CRCFltMsg_AF)
#   if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AF) || (RTE_CONST_NTC_Num_CRCFltMsg_AF != 442U)
#    error "Enumeration constant <NTC_Num_CRCFltMsg_AF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_CRCFltMsg_AF (442U)
#   define NTC_Num_CRCFltMsg_AF (442U)
#  endif
#  if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AF) || (defined NTC_Num_PgrsCntFltMsg_AF)
#   if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AF) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AF != 443U)
#    error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_PgrsCntFltMsg_AF (443U)
#   define NTC_Num_PgrsCntFltMsg_AF (443U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AF) || (defined NTC_Num_DataRngFltMsg_AF)
#   if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AF) || (RTE_CONST_NTC_Num_DataRngFltMsg_AF != 444U)
#    error "Enumeration constant <NTC_Num_DataRngFltMsg_AF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRngFltMsg_AF (444U)
#   define NTC_Num_DataRngFltMsg_AF (444U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AF) || (defined NTC_Num_DataRateFltMsg_AF)
#   if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AF) || (RTE_CONST_NTC_Num_DataRateFltMsg_AF != 445U)
#    error "Enumeration constant <NTC_Num_DataRateFltMsg_AF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataRateFltMsg_AF (445U)
#   define NTC_Num_DataRateFltMsg_AF (445U)
#  endif
#  if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AF) || (defined NTC_Num_DataOtherFltMsg_AF)
#   if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AF) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AF != 446U)
#    error "Enumeration constant <NTC_Num_DataOtherFltMsg_AF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_Num_DataOtherFltMsg_AF (446U)
#   define NTC_Num_DataOtherFltMsg_AF (446U)
#  endif

#  define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;
#  define NvM_ServiceIdType_LowerLimit (6U)
#  define NvM_ServiceIdType_UpperLimit (12U)
#  if (defined RTE_CONST_NVM_READ_BLOCK) || (defined NVM_READ_BLOCK)
#   if (!defined RTE_CONST_NVM_READ_BLOCK) || (RTE_CONST_NVM_READ_BLOCK != 6U)
#    error "Enumeration constant <NVM_READ_BLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_READ_BLOCK (6U)
#   define NVM_READ_BLOCK (6U)
#  endif
#  if (defined RTE_CONST_NVM_WRITE_BLOCK) || (defined NVM_WRITE_BLOCK)
#   if (!defined RTE_CONST_NVM_WRITE_BLOCK) || (RTE_CONST_NVM_WRITE_BLOCK != 7U)
#    error "Enumeration constant <NVM_WRITE_BLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_WRITE_BLOCK (7U)
#   define NVM_WRITE_BLOCK (7U)
#  endif
#  if (defined RTE_CONST_NVM_RESTORE_BLOCK_DEFAULTS) || (defined NVM_RESTORE_BLOCK_DEFAULTS)
#   if (!defined RTE_CONST_NVM_RESTORE_BLOCK_DEFAULTS) || (RTE_CONST_NVM_RESTORE_BLOCK_DEFAULTS != 8U)
#    error "Enumeration constant <NVM_RESTORE_BLOCK_DEFAULTS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_RESTORE_BLOCK_DEFAULTS (8U)
#   define NVM_RESTORE_BLOCK_DEFAULTS (8U)
#  endif
#  if (defined RTE_CONST_NVM_ERASE_BLOCK) || (defined NVM_ERASE_BLOCK)
#   if (!defined RTE_CONST_NVM_ERASE_BLOCK) || (RTE_CONST_NVM_ERASE_BLOCK != 9U)
#    error "Enumeration constant <NVM_ERASE_BLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_ERASE_BLOCK (9U)
#   define NVM_ERASE_BLOCK (9U)
#  endif
#  if (defined RTE_CONST_NVM_INVALIDATE_NV_BLOCK) || (defined NVM_INVALIDATE_NV_BLOCK)
#   if (!defined RTE_CONST_NVM_INVALIDATE_NV_BLOCK) || (RTE_CONST_NVM_INVALIDATE_NV_BLOCK != 11U)
#    error "Enumeration constant <NVM_INVALIDATE_NV_BLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_INVALIDATE_NV_BLOCK (11U)
#   define NVM_INVALIDATE_NV_BLOCK (11U)
#  endif
#  if (defined RTE_CONST_NVM_READ_ALL) || (defined NVM_READ_ALL)
#   if (!defined RTE_CONST_NVM_READ_ALL) || (RTE_CONST_NVM_READ_ALL != 12U)
#    error "Enumeration constant <NVM_READ_ALL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_READ_ALL (12U)
#   define NVM_READ_ALL (12U)
#  endif

#  define Rte_TypeDef_NxtrDiagMgrStatus
typedef uint8 NxtrDiagMgrStatus;
#  define NxtrDiagMgrStatus_LowerLimit (0U)
#  define NxtrDiagMgrStatus_UpperLimit (255U)
#  if (defined RTE_CONST_NTC_STATUS_PASSED) || (defined NTC_STATUS_PASSED)
#   if (!defined RTE_CONST_NTC_STATUS_PASSED) || (RTE_CONST_NTC_STATUS_PASSED != 0U)
#    error "Enumeration constant <NTC_STATUS_PASSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_STATUS_PASSED (0U)
#   define NTC_STATUS_PASSED (0U)
#  endif
#  if (defined RTE_CONST_NTC_STATUS_FAILED) || (defined NTC_STATUS_FAILED)
#   if (!defined RTE_CONST_NTC_STATUS_FAILED) || (RTE_CONST_NTC_STATUS_FAILED != 1U)
#    error "Enumeration constant <NTC_STATUS_FAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_STATUS_FAILED (1U)
#   define NTC_STATUS_FAILED (1U)
#  endif
#  if (defined RTE_CONST_NTC_STATUS_PREPASSED) || (defined NTC_STATUS_PREPASSED)
#   if (!defined RTE_CONST_NTC_STATUS_PREPASSED) || (RTE_CONST_NTC_STATUS_PREPASSED != 2U)
#    error "Enumeration constant <NTC_STATUS_PREPASSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_STATUS_PREPASSED (2U)
#   define NTC_STATUS_PREPASSED (2U)
#  endif
#  if (defined RTE_CONST_NTC_STATUS_PREFAILED) || (defined NTC_STATUS_PREFAILED)
#   if (!defined RTE_CONST_NTC_STATUS_PREFAILED) || (RTE_CONST_NTC_STATUS_PREFAILED != 3U)
#    error "Enumeration constant <NTC_STATUS_PREFAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_STATUS_PREFAILED (3U)
#   define NTC_STATUS_PREFAILED (3U)
#  endif

#  define Rte_TypeDef_NxtrOpCycle
typedef uint8 NxtrOpCycle;
#  define NxtrOpCycle_LowerLimit (0U)
#  define NxtrOpCycle_UpperLimit (0U)
#  if (defined RTE_CONST_NxtrDefaultOpCycle) || (defined NxtrDefaultOpCycle)
#   if (!defined RTE_CONST_NxtrDefaultOpCycle) || (RTE_CONST_NxtrDefaultOpCycle != 0U)
#    error "Enumeration constant <NxtrDefaultOpCycle> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NxtrDefaultOpCycle (0U)
#   define NxtrDefaultOpCycle (0U)
#  endif

#  define Rte_TypeDef_NxtrOpCycleState
typedef uint8 NxtrOpCycleState;
#  define NxtrOpCycleState_LowerLimit (1U)
#  define NxtrOpCycleState_UpperLimit (2U)
#  if (defined RTE_CONST_NXTR_CYCLE_STATE_START) || (defined NXTR_CYCLE_STATE_START)
#   if (!defined RTE_CONST_NXTR_CYCLE_STATE_START) || (RTE_CONST_NXTR_CYCLE_STATE_START != 1U)
#    error "Enumeration constant <NXTR_CYCLE_STATE_START> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NXTR_CYCLE_STATE_START (1U)
#   define NXTR_CYCLE_STATE_START (1U)
#  endif
#  if (defined RTE_CONST_NXTR_CYCLE_STATE_END) || (defined NXTR_CYCLE_STATE_END)
#   if (!defined RTE_CONST_NXTR_CYCLE_STATE_END) || (RTE_CONST_NXTR_CYCLE_STATE_END != 2U)
#    error "Enumeration constant <NXTR_CYCLE_STATE_END> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NXTR_CYCLE_STATE_END (2U)
#   define NXTR_CYCLE_STATE_END (2U)
#  endif

#  define Rte_TypeDef_RoutineStatus
typedef uint8 RoutineStatus;
#  define RoutineStatus_LowerLimit (0U)
#  define RoutineStatus_UpperLimit (3U)
#  if (defined RTE_CONST_RTN_INACTIVE) || (defined RTN_INACTIVE)
#   if (!defined RTE_CONST_RTN_INACTIVE) || (RTE_CONST_RTN_INACTIVE != 0U)
#    error "Enumeration constant <RTN_INACTIVE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_INACTIVE (0U)
#   define RTN_INACTIVE (0U)
#  endif
#  if (defined RTE_CONST_RTN_ACTIVE) || (defined RTN_ACTIVE)
#   if (!defined RTE_CONST_RTN_ACTIVE) || (RTE_CONST_RTN_ACTIVE != 1U)
#    error "Enumeration constant <RTN_ACTIVE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_ACTIVE (1U)
#   define RTN_ACTIVE (1U)
#  endif
#  if (defined RTE_CONST_RTN_COMPLETE) || (defined RTN_COMPLETE)
#   if (!defined RTE_CONST_RTN_COMPLETE) || (RTE_CONST_RTN_COMPLETE != 2U)
#    error "Enumeration constant <RTN_COMPLETE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_COMPLETE (2U)
#   define RTN_COMPLETE (2U)
#  endif
#  if (defined RTE_CONST_RTN_CANCELLED) || (defined RTN_CANCELLED)
#   if (!defined RTE_CONST_RTN_CANCELLED) || (RTE_CONST_RTN_CANCELLED != 3U)
#    error "Enumeration constant <RTN_CANCELLED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_CANCELLED (3U)
#   define RTN_CANCELLED (3U)
#  endif

#  define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;
#  define WdgM_GlobalStatusType_LowerLimit (0U)
#  define WdgM_GlobalStatusType_UpperLimit (255U)
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_OK) || (defined WDGM_GLOBAL_STATUS_OK)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_OK) || (RTE_CONST_WDGM_GLOBAL_STATUS_OK != 0U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_OK (0U)
#   define WDGM_GLOBAL_STATUS_OK (0U)
#  endif
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_FAILED) || (defined WDGM_GLOBAL_STATUS_FAILED)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_FAILED) || (RTE_CONST_WDGM_GLOBAL_STATUS_FAILED != 1U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_FAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_FAILED (1U)
#   define WDGM_GLOBAL_STATUS_FAILED (1U)
#  endif
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED) || (defined WDGM_GLOBAL_STATUS_EXPIRED)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED) || (RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED != 2U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_EXPIRED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED (2U)
#   define WDGM_GLOBAL_STATUS_EXPIRED (2U)
#  endif
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED) || (defined WDGM_GLOBAL_STATUS_STOPPED)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED) || (RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED != 3U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_STOPPED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED (3U)
#   define WDGM_GLOBAL_STATUS_STOPPED (3U)
#  endif
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED) || (defined WDGM_GLOBAL_STATUS_DEACTIVATED)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED) || (RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED != 4U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_DEACTIVATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#   define WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#  endif

#  define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;
#  define WdgM_LocalStatusType_LowerLimit (0U)
#  define WdgM_LocalStatusType_UpperLimit (255U)
#  if (defined RTE_CONST_WDGM_LOCAL_STATUS_OK) || (defined WDGM_LOCAL_STATUS_OK)
#   if (!defined RTE_CONST_WDGM_LOCAL_STATUS_OK) || (RTE_CONST_WDGM_LOCAL_STATUS_OK != 0U)
#    error "Enumeration constant <WDGM_LOCAL_STATUS_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_LOCAL_STATUS_OK (0U)
#   define WDGM_LOCAL_STATUS_OK (0U)
#  endif
#  if (defined RTE_CONST_WDGM_LOCAL_STATUS_FAILED) || (defined WDGM_LOCAL_STATUS_FAILED)
#   if (!defined RTE_CONST_WDGM_LOCAL_STATUS_FAILED) || (RTE_CONST_WDGM_LOCAL_STATUS_FAILED != 1U)
#    error "Enumeration constant <WDGM_LOCAL_STATUS_FAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_LOCAL_STATUS_FAILED (1U)
#   define WDGM_LOCAL_STATUS_FAILED (1U)
#  endif
#  if (defined RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED) || (defined WDGM_LOCAL_STATUS_EXPIRED)
#   if (!defined RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED) || (RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED != 2U)
#    error "Enumeration constant <WDGM_LOCAL_STATUS_EXPIRED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED (2U)
#   define WDGM_LOCAL_STATUS_EXPIRED (2U)
#  endif
#  if (defined RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED) || (defined WDGM_LOCAL_STATUS_DEACTIVATED)
#   if (!defined RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED) || (RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED != 4U)
#    error "Enumeration constant <WDGM_LOCAL_STATUS_DEACTIVATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#   define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  endif

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# if (defined RTE_CONST_D_FALSE_CNT_LGC) || (defined D_FALSE_CNT_LGC)
#  if (!defined RTE_CONST_D_FALSE_CNT_LGC) || (RTE_CONST_D_FALSE_CNT_LGC != FALSE)
#   error "Constant value <D_FALSE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FALSE_CNT_LGC (FALSE)
#  define D_FALSE_CNT_LGC (FALSE)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif



/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_StOpCtrl
{
  /* Data Handles section */
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_STOPCTRL_APPL_VAR) StOpCtrl_Per1_DiagRampRate_XpmS_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_STOPCTRL_APPL_VAR) StOpCtrl_Per1_DiagRampValue_Uls_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_STOPCTRL_APPL_VAR) StOpCtrl_Per1_DiagStsDiagRmpActive_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_STOPCTRL_APPL_VAR) StOpCtrl_Per1_OperRampRate_XpmS_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_STOPCTRL_APPL_VAR) StOpCtrl_Per1_OperRampValue_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_STOPCTRL_APPL_VAR) StOpCtrl_Per1_OutputRampMult_Uls_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_STOPCTRL_APPL_VAR) StOpCtrl_Per1_RampDwnStatusComplete_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_STOPCTRL_APPL_VAR) StOpCtrl_Per1_RampSrlComSvcDft_Cnt_lgc;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_StOpCtrl, RTE_CONST, RTE_CONST) Rte_Inst_Ap_StOpCtrl;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1326403392
#    error "The magic number of the generated file <C:/Synergy WorkArea/CBD_StOpCtrl/StOpCtrl/src/Ap_StOpCtrl/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1326403392
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
