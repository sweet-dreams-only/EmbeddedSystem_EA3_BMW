/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the configuration and non-API relevant implementation
 ** of the AUTOSAR module Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Marko Schneider
 ** \author 3Soft GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Depend.c.m4 2561 2011-09-09 12:08:40Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise */

/**  MISRA-C:2004 Deviation List
 **
 **  MISRA-1) Deviated Rule: 14.7 (required)
 **   A function shall have a single point of exit at the end of the function.
 **
 **   Reason:
 **   Optimize short functions.
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Dem_Helper.h>                                /* Dem helper macros */
#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

#include <Dem_Internal_Depend_Specific.h> /* API and internal declarations,
                                           * dependent and static part */

#if (DEM_USE_DYNAMIC_DTC == STD_ON)
#include DEM_DYNAMIC_DTC_HEADER_FILE
#endif

/*==================[macros]================================================*/

/*------------------[AUTOSAR vendor identification check]-------------------*/

#if (!defined DEM_VENDOR_ID) /* configuration check */
#error DEM_VENDOR_ID must be defined
#endif /* if (!defined DEM_VENDOR_ID) */

#if (DEM_VENDOR_ID != DEM_VENDOR_ID_3SOFT) /* vendor check */
#error DEM_VENDOR_ID has wrong vendor id
#endif /* if (DEM_VENDOR_ID != DEM_VENDOR_ID_3SOFT) */

/*------------------[AUTOSAR specification version identification check]----*/

#if (!defined DEM_AR_MAJOR_VERSION) /* configuration check */
#error DEM_AR_MAJOR_VERSION must be defined
#endif /* if (!defined DEM_AR_MAJOR_VERSION) */

/* major version check */
#if (DEM_AR_MAJOR_VERSION != 2U)
#error DEM_AR_MAJOR_VERSION wrong (!= 2U)
#endif /* if DEM_AR_MAJOR_VERSION */

#if (!defined DEM_AR_MINOR_VERSION) /* configuration check */
#error DEM_AR_MINOR_VERSION must be defined
#endif /* if (!defined DEM_AR_MINOR_VERSION) */

/* minor version check */
#if (DEM_AR_MINOR_VERSION < 1U)
#error DEM_AR_MINOR_VERSION wrong (< 1U)
#endif /* if DEM_AR_MINOR_VERSION */

#if (!defined DEM_AR_PATCH_VERSION) /* configuration check */
#error DEM_AR_PATCH_VERSION must be defined
#endif /* if (!defined DEM_AR_PATCH_VERSION) */

/* patch version check */
#if (DEM_AR_PATCH_VERSION < 1U)
#error DEM_AR_PATCH_VERSION wrong (< 1U)
#endif /* if DEM_AR_PATCH_VERSION */

/*------------------[AUTOSAR module version identification check]-----------*/

#if (!defined DEM_SW_MAJOR_VERSION) /* configuration check */
#error DEM_SW_MAJOR_VERSION must be defined
#endif /* if (!defined DEM_SW_MAJOR_VERSION) */

/* major version check */
#if (DEM_SW_MAJOR_VERSION != 3U)
#error DEM_SW_MAJOR_VERSION wrong (!= 3U)
#endif /* if DEM_SW_MAJOR_VERSION */

#if (!defined DEM_SW_MINOR_VERSION) /* configuration check */
#error DEM_SW_MINOR_VERSION must be defined
#endif /* if (!defined DEM_SW_MINOR_VERSION) */

/* minor version check */
#if (DEM_SW_MINOR_VERSION < 3U)
#error DEM_SW_MINOR_VERSION wrong (< 3U)
#endif /* if DEM_SW_MINOR_VERSION */

#if (!defined DEM_SW_PATCH_VERSION) /* configuration check */
#error DEM_SW_PATCH_VERSION must be defined
#endif /* if (!defined DEM_SW_PATCH_VERSION) */

/* patch version check */
#if (DEM_SW_PATCH_VERSION < 3U)
#error DEM_SW_PATCH_VERSION wrong (< 3U)
#endif /* if DEM_SW_PATCH_VERSION */

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief Function to search for an empty entry in the given event memory
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] OriginIdx  0 <= OriginIdx < DEM_MAXNUM_ORIGINS
 ** \param[out] FoundEntry
 **
 ** \return Result of the searching
 ** \retval TRUE  entry was found
 ** \retval FALSE no entry exists
 **/
_STATIC_ FUNC(boolean, DEM_CODE) Dem_SearchForEmptyEntry(
   const uint8            OriginIdx,
   CONSTP2VAR(
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT),
      AUTOMATIC, DEM_VAR) FoundEntry);

/** \brief Function to store the complete extended data at the specified
 ** position in memory, by using the RTE-callback function
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EvMemEntry
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_StoreED(
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
      EvMemEntry);

/** \brief Function to shift the freeze frames in the entry data
 **
 ** The first freeze frame will not be shifted.
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] FFEntryData
 ** \param[in] FFClass
 ** \param[in] MaxNumFF
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_ShiftFFs(
   CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FFEntryData,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST)      FFClass,
   const Dem_FFIdxType                                      MaxNumFF);

/** \brief This function adds a new or updates an existing entry in the event
 ** memory, including its entry data
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_ProcessEventEntry(Dem_EventIdType EventId);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if DEM_SIZE_PFF_ENTRY_DATA != 0U
/** \brief Entry area for possible prestored freeze frames */
_STATIC_ VAR(Dem_EntryDataType, DEM_VAR_NOINIT)
   Dem_PFFEntryDataArea[DEM_SIZE_PFF_ENTRY_DATA];
#endif

/** \brief Index of first entry in queue to read */
_STATIC_ VAR(Dem_ErrorQueueIdxType, DEM_VAR_NOINIT) Dem_ErrorQueueReadIdx;
/** \brief Index of next entry in queue to write */
_STATIC_ VAR(Dem_ErrorQueueIdxType, DEM_VAR_NOINIT) Dem_ErrorQueueWriteIdx;

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_8BIT
#include "MemMap.h"

#if (DEM_USE_HEALING == STD_ON)
CONST(uint8, DEM_CONST) Dem_HealingCounterRecNum =
#ifdef DEM_EDS_NUM_HEALING_COUNTER
   DEM_EDS_NUM_HEALING_COUNTER;
#else
   0U;
#endif
#endif

#define DEM_STOP_SEC_CONST_8BIT
#include "MemMap.h"
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Sizes of the event memories */
CONST(Dem_SizeEvMemEntryType, DEM_CONST) Dem_SizeEventMem[DEM_MAXNUM_ORIGINS] =
{
   DEM_MAX_NUMBER_EVENT_ENTRY_PRM,
   DEM_MAX_NUMBER_EVENT_ENTRY_SEC,
   DEM_MAX_NUMBER_EVENT_ENTRY_MIR
};

/* Sizes of the event memory entry data */
CONST(Dem_SizeEntryDataType, DEM_CONST) Dem_SizeEntryData[DEM_MAXNUM_ORIGINS] =
{
   DEM_SIZE_ENTRY_DATA_PRIMARY,
   DEM_SIZE_ENTRY_DATA_SECONDARY,
   DEM_SIZE_ENTRY_DATA_MIRROR
};

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
/* Pointer to the prestored freeze frame data area */
CONSTP2VAR(Dem_EntryDataType, DEM_CONST, DEM_VAR_NOINIT) Dem_PFFEntryData =
   Dem_PFFEntryDataArea;
#endif

#if (DEM_USE_DEBOUNCE == STD_ON)
/* function pointer array for easy access to debouncing functions */
CONST(Dem_DebounceFctPtrTableType, DEM_CONST)
   Dem_DebounceFctPtrTable[DEM_MAXNUM_DEBOUNCECLASSES] =
{
   /* "monitor internal" debouncing - DEM_DEBOUNCE_MONITOR */
   {
      &Dem_ResetDebounceMonitor,
      NULL_PTR, /* "debounce event" function will never be called */
      &Dem_RteGetFaultDetectionCounter
   },
#if (DEM_NUM_DEBOUNCE_COUNTER > 0U)
   /* counter based debouncing - DEM_DEBOUNCE_COUNTERBASED */
   {
      &Dem_ResetDebounceCounterBased,
      &Dem_DebounceEventCounterBased,
      &Dem_GetFDCCounterBased
   },
#endif
#if (DEM_NUM_DEBOUNCE_TIME > 0U)
   /* time based debouncing - DEM_DEBOUNCE_TIMEBASED */
   {
      &Dem_ResetDebounceTimeBased,
      &Dem_DebounceEventTimeBased,
      &Dem_GetFDCTimeBased
   },
#endif
#if (DEM_NUM_DEBOUNCE_FREQUENCY > 0U)
   /* frequency based debouncing - DEM_DEBOUNCE_FREQUENCYBASED */
   {
      &Dem_ResetDebounceFrequencyBased,
      &Dem_DebounceEventFrequencyBased,
      &Dem_GetFDCFrequencyBased
   },
#endif
};
#endif /* DEM_USE_DEBOUNCE == STD_ON */

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[external data]=========================================*/

#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
/* Flags to hold validity of the PFFs */
VAR(uint8, DEM_VAR_NOINIT) Dem_PFFEntryValid[
   DEM_MAX_NUMBER_PRESTORED_FF / 8U + 1U];
#endif

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Queue holding the errors appeared before Dem_Init(), or to be entered or
 * updated in event memory after Dem_Init() */
VAR(Dem_EventIdType, DEM_VAR_NOINIT) Dem_ErrorQueue[DEM_BSW_ERROR_BUFFER_SIZE];

/* Array of operation cycle states */
VAR(Dem_OperationCycleStateType, DEM_VAR_NOINIT)
   Dem_OpCycleState[DEM_NUM_OPCYCLES];

#if (DEM_USE_ENABLE_CONDITION == STD_ON)
/* Array of enable condition stats */
VAR(boolean, DEM_VAR_NOINIT) Dem_EnableCondition[DEM_NUM_ENABLECONDITIONS];
#endif

#if (DEM_USE_DEBOUNCE == STD_ON)

#if (DEM_NUM_DEBOUNCE_COUNTER > 0U)
/* per-event status for counter based debouncing */
VAR(Dem_DebounceCounterStatusType, DEM_VAR_NOINIT)
   Dem_DebounceCounterStatus[DEM_NUM_DEBOUNCE_COUNTER];
#endif

#if (DEM_NUM_DEBOUNCE_TIME > 0U)
/* per-event status for time based debouncing */
VAR(Dem_DebounceTimeStatusType, DEM_VAR_NOINIT)
   Dem_DebounceTimeStatus[DEM_NUM_DEBOUNCE_TIME];
#endif

#if (DEM_NUM_DEBOUNCE_FREQUENCY > 0U)
/* per-event status for frequency based debouncing */
VAR(Dem_DebounceFrequencyStatusType, DEM_VAR_NOINIT)
   Dem_DebounceFrequencyStatus[DEM_NUM_DEBOUNCE_FREQUENCY];
#endif

#endif /* DEM_USE_DEBOUNCE == STD_ON */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[internal core-function definitions]--------------------*/

#if (!defined DEM_GLOBAL_DTC_VALUE)
FUNC(uint32, DEM_CODE) Dem_GbiDTC(const Dem_EventIdType EventId)
{
   uint32 DTCval = DEM_BIT_FIELD_VALUE_32(
                      Dem_EventDesc[EventId].DEM_DTC_CONFIGFIELD,
                      DEM_DTC_OFFSET, DEM_DTC_MASK);
#if (DEM_USE_DYNAMIC_DTC == STD_ON)
   if (DTCval == 0U)
   {
      DTCval = DEM_DYNAMIC_DTC_CALLBACK_FUNCTION(EventId);  /* callback */
   }
#endif

   return DTCval;
}
#endif

#if (!defined DEM_GLOBAL_DTCKIND_VALUE)
FUNC(Dem_DTCKindType, DEM_CODE) Dem_GbiDTCKind(
   const Dem_EventIdType EventId)
{
   return (Dem_DTCKindType)(DEM_BIT_FIELD_VALUE_32(
                              Dem_EventDesc[EventId].DEM_DTCKIND_CONFIGFIELD,
                              DEM_DTCKIND_OFFSET,
                              DEM_DTCKIND_MASK)
                              + 1U); /* unpacking */
}
#endif

#if (!defined DEM_GLOBAL_DTCORIGIN_VALUE)
FUNC(Dem_DTCOriginType, DEM_CODE) Dem_GbiDTCOrigin(
   const Dem_EventIdType EventId)
{
   return (Dem_DTCOriginType)DEM_BIT_FIELD_VALUE_32(
                               Dem_EventDesc[EventId].DEM_DTCORIGIN_CONFIGFIELD,
                               DEM_DTCORIGIN_OFFSET,
                               DEM_DTCORIGIN_MASK);
}
#endif

#if (!defined DEM_GLOBAL_DTCGROUP_VALUE)
FUNC(uint8, DEM_CODE) Dem_GbiDTCGroupIdx(const Dem_EventIdType EventId)
{
   return (uint8)DEM_BIT_FIELD_VALUE_32(
                    Dem_EventDesc[EventId].DEM_DTCGROUP_CONFIGFIELD,
                    DEM_DTCGROUP_OFFSET,
                    DEM_DTCGROUP_MASK);
}
#endif

#if (!defined DEM_GLOBAL_DTCSEVERITY_VALUE)
FUNC(Dem_DTCSeverityType, DEM_CODE) Dem_GbiDTCSeverity(
   const Dem_EventIdType EventId)
{
   Dem_DTCSeverityType DTCSev;
   const uint8 sevNo = (uint8)DEM_BIT_FIELD_VALUE_32(
                                Dem_EventDesc[EventId].DEM_DTCSEVERITY_CONFIGFIELD,
                                DEM_DTCSEVERITY_OFFSET,
                                DEM_DTCSEVERITY_MASK);

   /* this number to severity code translation must match to the configuration
    * in Dem_Cfg.c */
   switch (sevNo)
   {
      case 0U:
         DTCSev = DEM_SEVERITY_NO_SEVERITY;
         break;

      case 1U:
         DTCSev = DEM_SEVERITY_MAINTENANCE_ONLY;
         break;

      case 2U:
         DTCSev = DEM_SEVERITY_CHECK_AT_NEXT_HALT;
         break;

      default:
         DTCSev = DEM_SEVERITY_CHECK_IMMEDIATELY;
         break;
   }

   return DTCSev;
}
#endif

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
#if (!defined DEM_GLOBAL_PRESTORAGE_VALUE)
FUNC(boolean, DEM_CODE) Dem_GbiEnablePrestorage(const Dem_EventIdType EventId)
{
   return (boolean)(Dem_GbiPrestorageIndex(EventId) == 0U) ? FALSE : TRUE;
}

FUNC(Dem_EventIdType, DEM_CODE) Dem_GbiPrestorageIndex(const Dem_EventIdType EventId)
{
   return (Dem_EventIdType)DEM_BIT_FIELD_VALUE_32(
                      Dem_EventDesc[EventId].DEM_PRESTORAGE_CONFIGFIELD,
                      DEM_PRESTORAGE_OFFSET,
                      DEM_PRESTORAGE_MASK);
}
#endif
#endif

#if (!defined DEM_GLOBAL_FFCLASSIDX_VALUE)
FUNC(Dem_FFClassIdxType, DEM_CODE) Dem_GbiFFClassIdx(
   const Dem_EventIdType EventId)
{
   return (Dem_FFClassIdxType)DEM_BIT_FIELD_VALUE_32(
                                 Dem_EventDesc[EventId].DEM_FFCLASSIDX_CONFIGFIELD,
                                 DEM_FFCLASSIDX_OFFSET,
                                 DEM_FFCLASSIDX_MASK);
}
#endif

#if (!defined DEM_GLOBAL_MAXNUMFF_VALUE)
FUNC(Dem_FFIdxType, DEM_CODE) Dem_GbiMaxNumFF(const Dem_EventIdType EventId)
{
   return (Dem_FFIdxType)DEM_BIT_FIELD_VALUE_32(
                            Dem_EventDesc[EventId].DEM_MAXNUMFF_CONFIGFIELD,
                            DEM_MAXNUMFF_OFFSET,
                            DEM_MAXNUMFF_MASK);
}
#endif

#if (!defined DEM_GLOBAL_EDCLASSIDX_VALUE)
FUNC(Dem_EDClassIdxType, DEM_CODE) Dem_GbiEDClassIdx(
   const Dem_EventIdType EventId)
{
   return (Dem_EDClassIdxType)DEM_BIT_FIELD_VALUE_32(
                                 Dem_EventDesc[EventId].DEM_EDCLASSIDX_CONFIGFIELD,
                                 DEM_EDCLASSIDX_OFFSET,
                                 DEM_EDCLASSIDX_MASK);
}
#endif

#if (!defined DEM_GLOBAL_OPCYCLEIDX_VALUE)
FUNC(Dem_OperationCycleIdType, DEM_CODE) Dem_GbiOpCycleIdx(
   const Dem_EventIdType EventId)
{
   return (Dem_OperationCycleIdType)DEM_BIT_FIELD_VALUE_32(
                                       Dem_EventDesc[EventId].DEM_OPCYCLEIDX_CONFIGFIELD,
                                       DEM_OPCYCLEIDX_OFFSET,
                                       DEM_OPCYCLEIDX_MASK);
}
#endif

#if (DEM_USE_HEALING == STD_ON)
#if ( (DEM_GLOBAL_HEALING_ALL_EVENTS == STD_OFF) || \
      (!defined DEM_GLOBAL_HEALINGCYCLES_VALUE)      )
FUNC(Dem_HealingCyclesType, DEM_CODE) Dem_GbiHealingCycles(
   const Dem_EventIdType EventId)
{
   uint8 retval = (Dem_HealingCyclesType)DEM_BIT_FIELD_VALUE_32(
                                            Dem_EventDesc[EventId].DEM_HEALINGCYCLES_CONFIGFIELD,
                                            DEM_HEALINGCYCLES_OFFSET,
                                            DEM_HEALINGCYCLES_MASK);
   #if (defined DEM_GLOBAL_HEALINGCYCLES_VALUE)
      if( retval == 1U ) /* If healing is on and a global value exists, then return this value */
      {
         retval = DEM_GLOBAL_HEALINGCYCLES_VALUE;
      }
   #endif
   return retval;
}
#endif
#endif

#if (DEM_USE_ENABLE_CONDITION == STD_ON)
#if (!defined DEM_GLOBAL_ENCONDID_VALUE)
FUNC(Dem_EnableConditionIdType, DEM_CODE) Dem_GbiEnCondId(
   const Dem_EventIdType EventId)
{
   return (Dem_EnableConditionIdType)DEM_BIT_FIELD_VALUE_32(
                                        Dem_EventDesc[EventId].DEM_ENCONDID_CONFIGFIELD,
                                        DEM_ENCONDID_OFFSET,
                                        DEM_ENCONDID_MASK);
}
#endif
#endif

#if (DEM_USE_VIEWID == STD_ON)
#if (!defined DEM_GLOBAL_VIEWID_VALUE)
FUNC(Dem_ViewIdType, DEM_CODE) Dem_GbiViewId(const Dem_EventIdType EventId)
{
   return (Dem_ViewIdType)DEM_BIT_FIELD_VALUE_32(
                             Dem_EventDesc[EventId].DEM_VIEWID_CONFIGFIELD,
                             DEM_VIEWID_OFFSET,
                             DEM_VIEWID_MASK);
}
#endif
#endif

#if (DEM_USE_INDICATOR == STD_ON)
#if (!defined DEM_GLOBAL_INDICATORUSED_VALUE)
FUNC(boolean, DEM_CODE) Dem_GbiIndicatorUsed(
   const Dem_EventIdType EventId)
{
   return (boolean)DEM_BIT_FIELD_VALUE_32(
                      Dem_EventDesc[EventId].DEM_INDICATORUSED_CONFIGFIELD,
                      DEM_INDICATORUSED_OFFSET,
                      DEM_INDICATORUSED_MASK);
}
#endif
#endif

#if (DEM_USE_PRIORITY == STD_ON)
#if (!defined DEM_GLOBAL_PRIORITY_VALUE)
FUNC(Dem_PriorityType, DEM_CODE) Dem_GbiPriority(
   const Dem_EventIdType EventId)
{
   return (Dem_PriorityType)DEM_BIT_FIELD_VALUE_32(
                               Dem_EventDesc[EventId].DEM_PRIORITY_CONFIGFIELD,
                               DEM_PRIORITY_OFFSET,
                               DEM_PRIORITY_MASK);
}
#endif
#endif

#if (DEM_USE_DEBOUNCE == STD_ON)

#if (!defined DEM_GLOBAL_DEBOUNCEALGO_VALUE)
FUNC(Dem_DebounceType, DEM_CODE) Dem_GbiDebounceAlgo(
   const Dem_EventIdType EventId)
{
   return (Dem_DebounceType)DEM_BIT_FIELD_VALUE_32(
                               Dem_EventDesc[EventId].DEM_DEBOUNCEALGO_CONFIGFIELD,
                               DEM_DEBOUNCEALGO_OFFSET,
                               DEM_DEBOUNCEALGO_MASK);
}
#endif /* (!defined DEM_GLOBAL_DEBOUNCEALGO_VALUE) */

#if (!defined DEM_GLOBAL_DEBOUNCEIDX_VALUE)
FUNC(Dem_EventIdType, DEM_CODE) Dem_GbiDebounceIdx(
   const Dem_EventIdType EventId)
{
   return (Dem_EventIdType)DEM_BIT_FIELD_VALUE_32(
                              Dem_EventDesc[EventId].DEM_DEBOUNCEIDX_CONFIGFIELD,
                              DEM_DEBOUNCEIDX_OFFSET,
                              DEM_DEBOUNCEIDX_MASK);
}
#endif /* (!defined DEM_GLOBAL_DEBOUNCEIDX_VALUE) */

#endif /* DEM_USE_DEBOUNCE == STD_ON */

FUNC(void, DEM_CODE) Dem_ReadErrorQueueEntry(
   CONSTP2VAR(Dem_EventIdType, AUTOMATIC, DEM_APPL_DATA) EventId)
{
   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   *EventId = Dem_ErrorQueue[Dem_ErrorQueueReadIdx];

   Dem_ErrorQueue[Dem_ErrorQueueReadIdx] = DEM_EVENT_ID_INVALID;

   ++Dem_ErrorQueueReadIdx;
   Dem_ErrorQueueReadIdx %= DEM_BSW_ERROR_BUFFER_SIZE;

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
}

FUNC(boolean, DEM_CODE) Dem_WriteErrorQueueEntry(
   const Dem_EventIdType EventId)
{
   boolean result = FALSE;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   if (Dem_ErrorQueue[Dem_ErrorQueueWriteIdx] ==
       (Dem_EventIdType)DEM_EVENT_ID_INVALID)
   {
      Dem_ErrorQueue[Dem_ErrorQueueWriteIdx] = EventId;

      ++Dem_ErrorQueueWriteIdx;
      Dem_ErrorQueueWriteIdx %= DEM_BSW_ERROR_BUFFER_SIZE;

      result = TRUE;
   }

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   return result;
}

FUNC(Std_ReturnType, DEM_CODE) Dem_InternalSetEventStatus(
   Dem_EventIdType                    EventId,
   Dem_EventStatusType                EventStatus,
   P2VAR(boolean, AUTOMATIC, DEM_VAR) ErrorIndication)
{
   const Dem_DTCStatusMaskType OldDTCStatusMask = Dem_DTCStatusMasks[EventId];

   const Dem_EventStatusType OldEventStatus =
      DEM_IS_BIT_SET(OldDTCStatusMask, DEM_DTCSTATUSBIT_TF) ?
      DEM_EVENT_STATUS_FAILED : DEM_EVENT_STATUS_PASSED;

   uint8 GroupIdx;

#if (DEM_USE_DEBOUNCE == STD_ON)
   const Dem_DebounceType DebounceAlgo = Dem_GbiDebounceAlgo(EventId);
#endif
#if (DEM_USE_ENABLE_CONDITION == STD_ON)
   const Dem_EnableConditionIdType EnCondId = Dem_GbiEnCondId(EventId);
#endif

   Std_ReturnType result = E_OK;
   Std_ReturnType debounceresult = E_OK;

   if (Dem_OpCycleState[Dem_GbiOpCycleIdx(EventId)] == DEM_CYCLE_STATE_END)
   {
      /* the operation cycle of the event is not started:
       * no debounce-/qualification-handling allowed */

      /* operationcycle not started, set error indication flag */
      *ErrorIndication = TRUE;

      /* Deviation MISRA-1 */
      return E_OK;
   }

#if (DEM_USE_DEBOUNCE == STD_ON)
   /* I) event debounce-handling */
   if (DebounceAlgo != DEM_DEBOUNCE_MONITOR)
   {
      /* debounce event */
      Dem_DebounceFctPtrTable[DebounceAlgo].
         DebounceEventFct(EventId, &EventStatus);
   }
   else
   {
      /* if the event is not qualified and monitor internal debouncing is used,
       * an error is signaled (caller will trigger DET) by the check below */
      debounceresult = E_NOT_OK;
   }
#else
   debounceresult = E_NOT_OK;
#endif /* DEM_USE_DEBOUNCE == STD_ON */

   if (   (EventStatus == DEM_EVENT_STATUS_PREFAILED)
       || (EventStatus == DEM_EVENT_STATUS_PREPASSED))
   {
      /* debouncing did not qualify the event:
       * no qualification-handling possible */
      /* Deviation MISRA-1 */
      return debounceresult;
   }

#if (DEM_USE_ENABLE_CONDITION == STD_ON)
   if (   (EnCondId < DEM_NUM_ENABLECONDITIONS) /* enable codition exists */
       && (Dem_EnableCondition[EnCondId] == FALSE))
   {
      /* the enable condition of the event is not enabled:
       * no qualification-handling allowed */
      /* Deviation MISRA-1 */
      return E_OK;
   }
#endif

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
   /* release prestored freeze frame for passed events */
   if (EventStatus == DEM_EVENT_STATUS_PASSED)
   {
      if (Dem_GbiEnablePrestorage(EventId) == TRUE)
      {
         /* mark prestored freeze frame as unused */
         DEM_ATOMIC_CLR_BIT_IN_ARRAY(Dem_PFFEntryValid, Dem_GetPFFIndex(EventId));
      }
   }
#endif

   if (   (!(DEM_IS_EV_ST_BIT_SET(EventId, DEM_DTCSTATUSBIT_TNCTOC)))
       && (EventStatus == OldEventStatus))
   {
      /* the event was already tested this operation cycle and reported status
       * doesn't change:
       * no qualification-handling necessary */
      /* Deviation MISRA-1 */
      return E_OK;
   }

   GroupIdx = Dem_GbiDTCGroupIdx(EventId);

   /* II) event qualification-handling, if update and storage is enabled */
   if (   DEM_SPECIFIC_HOOK_ISEVSTUPDATEENABLED(GroupIdx)
       && DEM_SPECIFIC_HOOK_ISDTCSTORAGEENABLED(GroupIdx)
       )
   {
      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* update status mask of event: */

      /* TEST NOT COMPLETE -> 0 */
      DEM_CLR_EV_ST_MASK(EventId,
                         DEM_DTCSTATUSBIT_TNCSLC |
                         DEM_DTCSTATUSBIT_TNCTOC);

      /* check Event Status */
      if (EventStatus == DEM_EVENT_STATUS_PASSED)
      {
         /* TEST FAILED -> 0, warning indicator req. -> 0 */
         DEM_CLR_EV_ST_MASK(EventId,
                            DEM_DTCSTATUSBIT_TF |
                            DEM_DTCSTATUSBIT_WIR);
         /* EVER FAILED -> unchanged */
      }
      else /* EventStatus == DEM_EVENT_STATUS_FAILED */
      {
         /* TEST FAILED -> 1, TEST FAILED TOC -> 1, TEST FAILED SLC -> 1 */
         DEM_SET_EV_ST_MASK(EventId,
                            DEM_DTCSTATUSBIT_TF    |
                            DEM_DTCSTATUSBIT_TFTOC |
                            DEM_DTCSTATUSBIT_TFSLC |
                            DEM_SPECIFIC_DTCSTATUSBITS_ON_REPORT);

         if (DEM_IS_EV_ST_BIT_SET(EventId, DEM_DTCSTATUSBIT_CDTC))
         {
            /* set pending bit request */
            DEM_SET_EV_ST_MASK(EventId, DEM_DTCSTATUSBIT_PDTC);
         }

#if (DEM_USE_INDICATOR == STD_ON)
         if (DEM_IS_EV_ST_BIT_SET(EventId, DEM_DTCSTATUSBIT_CDTC))
         {
            if (Dem_GbiIndicatorUsed(EventId) != FALSE)
            {
               /* set warning indicator request */
               DEM_SET_EV_ST_MASK(EventId, DEM_DTCSTATUSBIT_WIR);
            }
         }
#endif
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* append or update event entry, if error-reenter-condition is satisfied */
      if (   (OldEventStatus == DEM_EVENT_STATUS_PASSED)
          && (EventStatus    == DEM_EVENT_STATUS_FAILED)
          )
      {
         /* make entry in error-queue */
         boolean EntryIsWritten = Dem_WriteErrorQueueEntry(EventId);

         if (EntryIsWritten == FALSE)
         {
            /* an error is signaled (caller will trigger DET) */
            result = E_NOT_OK;
         }
      }

      /* notify application that event status has changed */
      /* selective masking of event bits is not supported */
      if (OldDTCStatusMask != Dem_DTCStatusMasks[EventId])
      {
         Dem_RteTriggerOnEventStatus(
            EventId,
            OldDTCStatusMask,
            Dem_DTCStatusMasks[EventId]);
      }
   }
   else
   {
      /* status-update or DTC-storage is disabled, set error indication flag */
      *ErrorIndication = TRUE;
   }

   return result;
}

/*------------------[API core-function definitions]-------------------------*/

FUNC(void, DEM_CODE) Dem_PreInit(void)
{
   Dem_ErrorQueueIdxType queueIdx;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_UNINITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_PreInit, DEM_E_UNINIT);
      return;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* initialize (relative) error-queue pointers */
   Dem_ErrorQueueReadIdx =  0U;
   Dem_ErrorQueueWriteIdx = 0U;

   /* initialize error-queue event id's */
   for (queueIdx = 0U; queueIdx < DEM_BSW_ERROR_BUFFER_SIZE; ++queueIdx)
   {
      Dem_ErrorQueue[queueIdx] = (Dem_EventIdType)DEM_EVENT_ID_INVALID;
   }

   /* after pre-initializing, mark internal flag */
   Dem_InitializationState = DEM_PREINITIALIZED;
}

FUNC(void, DEM_CODE) Dem_Init(void)
{
   NvM_RequestResultType RestoredNvData = NVM_REQ_NOT_OK;
   Dem_ErrorQueueIdxType queueIdx;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (   (Dem_InitializationState != DEM_PREINITIALIZED)
       && (Dem_InitializationState != DEM_POSTINITIALIZED)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_Init, DEM_E_UNINIT);
      return;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* following initializations are only done, if the DEM is full initialized
    * first time */
   if (Dem_InitializationState == DEM_PREINITIALIZED)
   {
      Dem_OperationCycleIdType OpCycleId;
#if (DEM_USE_ENABLE_CONDITION == STD_ON)
      Dem_EnableConditionIdType EnCondId;
#endif
#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
      Dem_EventIdType ByteIdx; /* there are maximal as much PFFs as events */
#endif

      /* mark all operation cycles as closed */
      for (OpCycleId = 0U; OpCycleId < DEM_NUM_OPCYCLES; ++OpCycleId)
      {
         Dem_OpCycleState[OpCycleId] = DEM_CYCLE_STATE_END;
      }

#if (DEM_USE_ENABLE_CONDITION == STD_ON)
      /* mark all enable conditions as enabled */
      for (EnCondId = 0U; EnCondId < DEM_NUM_ENABLECONDITIONS; ++EnCondId)
      {
         Dem_EnableCondition[EnCondId] = TRUE;
      }
#endif

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
      /* mark all prestored freeze frames as deleted */
      for (ByteIdx = 0U;
           ByteIdx < ((DEM_MAX_NUMBER_PRESTORED_FF / 8U) + 1U);
           ++ByteIdx)
      {
         /* set eight-bit-group at once */
         Dem_PFFEntryValid[ByteIdx] = 0U;
      }
#endif

      /* recovery of Dem_NvData from persistent memory must be done within
       * NvM_ReadAll() */

      /* get status from NvM of DEM default block */
      NvM_GetErrorStatus(DEM_NVM_BLOCK_ID_DEFAULT, &RestoredNvData);

      if (RestoredNvData != NVM_REQ_OK)
      {
         /* initialise RAM mirror of non volatile data to default values */
         Dem_ResetNvData();
      }

      /* hook-function for further variant specific handling */
      DEM_SPECIFIC_HOOK_INITNVDATA();

      /* initialize freeze frame record-filter */
      Dem_RecordFilterIdx = 0U;

      /* Dem_EnableDTCRecordUpdate() */
      Dem_DTCRecordUpdate = TRUE;
      /* initialize DCM-Access-Flag */
      Dem_DcmAccessInProgress = FALSE;

      /* hook-function for further variant specific handling */
      DEM_SPECIFIC_HOOK_POSTINIT();
   }

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   /* process status-bytes of events entered already in error-queue from
    * Dem_ReportErrorStatus() - event memory entry is done by main function */
   for (queueIdx = 0U; queueIdx < DEM_BSW_ERROR_BUFFER_SIZE; ++queueIdx)
   {
      Dem_EventIdType EvId = Dem_ErrorQueue[queueIdx];

      if (EvId != (Dem_EventIdType)DEM_EVENT_ID_INVALID)
      {
         /* TEST NOT COMPLETE -> 0 */
         DEM_CLR_EV_ST_MASK(EvId,
                            DEM_DTCSTATUSBIT_TNCSLC |
                            DEM_DTCSTATUSBIT_TNCTOC);

         /* TEST FAILED -> 1, TEST FAILED TOC -> 1, TEST FAILED SLC -> 1 */
         DEM_SET_EV_ST_MASK(EvId,
                            DEM_DTCSTATUSBIT_TF    |
                            DEM_DTCSTATUSBIT_TFTOC |
                            DEM_DTCSTATUSBIT_TFSLC |
                            DEM_SPECIFIC_DTCSTATUSBITS_ON_REPORT);
      }
   }

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   /* after full initializing, mark internal flag */
   Dem_InitializationState = DEM_INITIALIZED;
}

FUNC(Std_ReturnType, DEM_CODE) Dem_MainFunction(void)
{
   Dem_EventIdType ErrorEntryId;
   Dem_ErrorQueueIdxType ReadIndex;
   Dem_ErrorQueueIdxType WriteIndex;

#if (DEM_USE_DEBOUNCE == STD_ON)
#if (DEM_NUM_DEBOUNCE_TIME > 0U)
   /* update timers used for debouncing */
   Dem_DebounceTimeTimerTick();
#endif
#if (DEM_NUM_DEBOUNCE_FREQUENCY > 0U)
   Dem_DebounceFrequencyTimerTick();
#endif
#endif
   /* only try to access event memory if there is no DCM access in progress */
   if (Dem_DcmAccessInProgress == FALSE)
   {
      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      ReadIndex = Dem_ErrorQueueReadIdx;
      WriteIndex = Dem_ErrorQueueWriteIdx;

      ErrorEntryId = Dem_ErrorQueue[ReadIndex];

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* get current number of error queue entries */
      /* reentrant check if queue is empty, as Dem_ErrorQueueReadIdx is only
       * modified from this function */
      if (ErrorEntryId != (Dem_EventIdType)DEM_EVENT_ID_INVALID)
      {
         Dem_EventIdType EvId;
         Dem_ErrorQueueIdxType ProcessedQueueErrors;

         /* calculation is done reentrant, because Dem_ErrorQueueWriteIdx is
          * fetched atomically and Dem_ErrorQueueReadIdx is only modified from
          * this function */
         Dem_ErrorQueueIdxType NumQueuedErrors = (Dem_ErrorQueueIdxType) (
            ((uint16)(DEM_BSW_ERROR_BUFFER_SIZE - ReadIndex) +
               WriteIndex) % DEM_BSW_ERROR_BUFFER_SIZE );

         if (NumQueuedErrors == 0U)
         {
            /* queue is filled, because not empty and (max % max) = 0 */
            NumQueuedErrors = DEM_BSW_ERROR_BUFFER_SIZE;
         }

         /* only process as much errors as exists at this time and skip
          * (possibly) (re-)entered errors while main function runs
          * (those will be processed at next main function call) */
         for (ProcessedQueueErrors = 0U;
              ProcessedQueueErrors < NumQueuedErrors;
              ++ProcessedQueueErrors)
         {
            Dem_ReadErrorQueueEntry(&EvId);

            Dem_ProcessEventEntry(EvId);
         }
      }
   }

   return E_OK;
}

/*------------------[interface to Rte]--------------------------------------*/

FUNC(Std_ReturnType, DEM_CODE) Dem_GetCallbackIndex(
   Dem_EventIdType                                            EventId,
   CONSTP2CONST(Dem_CbkLookupTableType, AUTOMATIC, DEM_CONST) LookupTable,
   uint16                                                     TableSize,
   P2VAR(uint16, AUTOMATIC, DEM_VAR)                          StartIdx,
   P2VAR(uint16, AUTOMATIC, DEM_VAR)                          NumberOfCb)
{
   Std_ReturnType RetVal = E_NOT_OK;
   uint16 NumberOfEv = 0U;
   uint16 Idx = 0U;

   /* search for start index of given Event Id */
   while (   (Idx < TableSize)
          && (LookupTable[Idx].EventId != EventId))
   {
      Idx++;
   }

   /* determine number of callbacks of given Event Id */
   while (   ((Idx + NumberOfEv) < TableSize)
          && (LookupTable[Idx + NumberOfEv].EventId == EventId))
   {
      NumberOfEv++;
      RetVal = E_OK;
   }

   *StartIdx = Idx;
   *NumberOfCb = NumberOfEv;

   return RetVal;
}

FUNC(void, DEM_CODE) Dem_RteInitMonitorForEvent(
   const Dem_EventIdType         EventId,
   const Dem_InitMonitorKindType InitMonitorKind)
{
#if (   (DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE == 0U) \
     && (DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE == 0U))
   DEM_PARAM_UNUSED(EventId);
   DEM_PARAM_UNUSED(InitMonitorKind);
#else
   uint16 CbIdx = 0U;
#if (DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE > 0U)
   uint16 Idx = 0U;
#endif /* DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE */
#endif /* (DEM_RTE_LOOKUP / DEM_C_CALLBACK) _TABLE_INIT_MONITOR_SIZE */

#if (DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE > 0U)
   if ((Dem_CbkProperty[EventId] & DEM_RTE_CBK_INIT_MONITOR) != 0U)
   {
      Rte_PortHandle_CallbackInitMonitorForEvent_R monitorCallbackPorts =
      Rte_Ports_CallbackInitMonitorForEvent_R();

      CbIdx = 0U;
      while (   (CbIdx < DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE)
             && (Dem_RteLookupTableInitMonitor[CbIdx] != EventId))
      {
         CbIdx++;
      }

      if (CbIdx < DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE)
      {
         /* notify application that monitoring function has to be initialized,
          * return value is not evaluated -> error handling has to be done
          * by application */
         (void)monitorCallbackPorts[CbIdx].Call_InitMonitorForEvent(
            InitMonitorKind);
      }
   }
#endif

#if (DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE > 0U)
   if ((Dem_CbkProperty[EventId] & DEM_C_CBK_INIT_MONITOR) != 0U)
   {
      CbIdx = 0U;
      Idx = 1U;
      while (   (Idx < EventId)
             && (CbIdx < DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE))
      {
         if ((Dem_CbkProperty[Idx] & DEM_C_CBK_INIT_MONITOR) != 0U)
         {
            CbIdx++;
         }
         Idx++;
      }

      if (CbIdx < DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE)
      {
         /* notify application that monitoring function has to be initialized,
          * return value is not evaluated -> error handling has to be done
          * by application */
         (void)Dem_InitMonitorCallback[CbIdx](InitMonitorKind);
      }
   }
#endif
}

FUNC(void, DEM_CODE) Dem_RteTriggerOnEventStatus(
   const Dem_EventIdType       EventId,
   const Dem_DTCStatusMaskType OldDTCStatusMask,
   const Dem_DTCStatusMaskType NewDTCStatusMask)
{
#if (DEM_C_CALLBACK_TABLE_TRIGGER_ON_EVENT_SIZE > 0U)
   Std_ReturnType RetVal;
#endif

#if (   (DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE == 0U) \
     && (DEM_C_CALLBACK_TABLE_TRIGGER_ON_EVENT_SIZE == 0U))
   DEM_PARAM_UNUSED(EventId);
   DEM_PARAM_UNUSED(OldDTCStatusMask);
   DEM_PARAM_UNUSED(NewDTCStatusMask);
#else
   uint16 StartIdx = 0U;
   uint16 NumberOfCb = 0U;
   uint16 CbIdx = 0U;
   uint16 i;
#endif

#if (DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE > 0U)
   if ((Dem_CbkProperty[EventId] & DEM_RTE_CBK_TRIGGER_ON_EV_STATUS) != 0U)
   {
      Rte_PortHandle_CallbackEventStatusChange_R statusCallbackPorts =
         Rte_Ports_CallbackEventStatusChange_R();

      CbIdx = 0U;
      while (   (CbIdx < DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE)
             && (Dem_RteLookupTableTriggerOnEvent[CbIdx] != EventId))
      {
         CbIdx++;
      }

      if (CbIdx < DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE)
      {
         /* notify application that event status has changed,
          * return value is not evaluated -> error handling has to be done
          * by application */
         (void)statusCallbackPorts[CbIdx].Call_EventStatusChanged(
            OldDTCStatusMask, NewDTCStatusMask);
      }
   }
#endif

#if (DEM_C_CALLBACK_TABLE_TRIGGER_ON_EVENT_SIZE > 0U)
   if ((Dem_CbkProperty[EventId] & DEM_C_CBK_TRIGGER_ON_EV_STATUS) != 0U)
   {
      RetVal = Dem_GetCallbackIndex(
           EventId,
           Dem_CbkLookupTableTriggerOnEvent,
           DEM_C_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE,
           &StartIdx,
           &NumberOfCb);
      if (RetVal == E_OK)
      {
         for (i = 0U; i < NumberOfCb; i++)
         {
            CbIdx = Dem_CbkLookupTableTriggerOnEvent[StartIdx + i].CallbackIdx;
            /* notify application that event status has changed,
             * return value is not evaluated -> error handling has to be done
             * by application */
            (void)Dem_CbkFuncPtrTriggerOnEvent[CbIdx](
               EventId,
               OldDTCStatusMask,
               NewDTCStatusMask);
         }
      }
   }
#endif
}

FUNC(Std_ReturnType, DEM_CODE) Dem_RteGetFaultDetectionCounter(
   Dem_EventIdType                                                EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC)
{
   Std_ReturnType RetVal = E_NOT_OK;

#if (   (DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE == 0U) \
     && (DEM_C_LOOKUP_TABLE_GET_FDC_SIZE == 0U))
   DEM_PARAM_UNUSED(EventId);
   DEM_PARAM_UNUSED(FDC);
#else
   uint16 CbIdx = 0U;
#endif

#if (DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE > 0U)
   if ((Dem_CbkProperty[EventId] & DEM_RTE_CBK_FAULT_DETECTION_CTR) != 0U)
   {
      Rte_PortHandle_CallbackGetFaultDetectCounter_R getFDCCallbackPorts =
         Rte_Ports_CallbackGetFaultDetectCounter_R();

      CbIdx = 0U;
      while (   (CbIdx < DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE)
             && (Dem_RteLookupTableGetFaultDetectionCounter[CbIdx] != EventId))
      {
         CbIdx++;
      }

      if (CbIdx != DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE)
      {
         /* notify application that event status has changed */
         return getFDCCallbackPorts[CbIdx].Call_GetFaultDetectionCounter(FDC);
      }
   }
#endif

#if (DEM_C_LOOKUP_TABLE_GET_FDC_SIZE > 0U)
   if ((Dem_CbkProperty[EventId] & DEM_C_CBK_FAULT_DETECTION_CTR) != 0U)
   {
      CbIdx = 0U;
      while (   (CbIdx < DEM_C_LOOKUP_TABLE_GET_FDC_SIZE)
             && (Dem_CbkLookupTableGetFaultDetectionCounter[CbIdx].EventId != EventId))
      {
         CbIdx++;
      }

      if (CbIdx != DEM_C_LOOKUP_TABLE_GET_FDC_SIZE)
      {
         /* notify application that event status has changed */
#if (DEM_C_CALLBACK_TABLE_GET_FDC_SIZE != 0U)
         CbIdx = Dem_CbkLookupTableGetFaultDetectionCounter[CbIdx].CallbackIdx;
         RetVal = Dem_CbkFuncPtrGetFaultDetectionCounter[CbIdx](EventId, FDC);
#else
         RetVal = Dem_CbkLookupTableGetFaultDetectionCounter[CbIdx].Function(
            EventId, FDC);
#endif
      }
   }
#endif

   return RetVal;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

_STATIC_ FUNC(boolean, DEM_CODE) Dem_SearchForEmptyEntry(
   const uint8            OriginIdx,
   CONSTP2VAR(
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT),
      AUTOMATIC, DEM_VAR) FoundEntry)
{
   boolean result = FALSE;

   const Dem_SizeEvMemEntryType sizeEventMem = Dem_SizeEventMem[OriginIdx];

   Dem_SizeEvMemEntryType index;
   P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) Entry =
      Dem_EventMem[OriginIdx];

   /* search for empty entry in event memory */
   /* stop if all entries checked or the first empty entry was found */
   for (index = 0U;
        (index < sizeEventMem)
           && (Entry[index].EventId != (Dem_EventIdType)DEM_EVENT_ID_INVALID);
        ++index)
   {
      /* empty search loop */
   }

   if (index < sizeEventMem)
   {
      result = TRUE;
      *FoundEntry = &Entry[index];
   }

   return result;
}

_STATIC_ FUNC(void, DEM_CODE) Dem_StoreED(
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
      EvMemEntry)
{
   Std_ReturnType dataPresent = E_NOT_OK;
   CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) EDEntryData =
      Dem_EDEntryData(EvMemEntry);

   /* get extended data class layout */
   CONSTP2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST) EDClass =
      Dem_EDClasses[Dem_GbiEDClassIdx(EvMemEntry->EventId)];

#if (DEM_USE_GLOBAL_EDCLASS == STD_OFF)
   Dem_SizeEntryDataType EDClassSize = Dem_SizeOfED(EDClass);
#else
   /* substract CONDITION_BYTE and OCCURRENCE_COUNTER */
   Dem_SizeEntryDataType EDClassSize = (DEM_MAXSIZE_EDCLS - 2U);
#endif

   Dem_EDSegIdxType SegIndex;

   /* at new (or displaced) entry */
   if (EvMemEntry->NumFF == 0U)
   {
      Dem_SizeEntryDataType index;

      /* initialize extended data record */
      for (index = 0U; index < EDClassSize; ++index)
      {
         EDEntryData[index] = 0U;
      }
   }

#if (DEM_USE_HEALING == STD_ON)
   /* if healing is enabled */
   if (Dem_GbiHealingCycles(EvMemEntry->EventId) != 0U)
   {
      /* get the EDS index of the healing counter */
      const Dem_EDSegIdxType HealingCounterIdx =
         Dem_FindEDNumIndex(EDClass, Dem_HealingCounterRecNum);

      /* get pointer to healing counter */
      CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) HealingCounter =
         &EDEntryData[EDClass->StartByte[HealingCounterIdx]];

      /* reset healing counter */
      *HealingCounter = Dem_GbiHealingCycles(EvMemEntry->EventId);
   }
#endif

   /* get data values to all numbers of the extended data class */
   for (SegIndex = 0U; SegIndex < EDClass->NumEDSegs; ++SegIndex)
   {
#if (DEM_GET_EXTENDED_DATA_VALUE_RECORD_RTE_USAGE == STD_ON)
      dataPresent = Rte_Call_ExtendedDataRecord_GetExtendedDataRecord(
         EDClass->Number[SegIndex],
         &EDEntryData[EDClass->StartByte[SegIndex]]);
#else
      dataPresent = DEM_CBK_FUNCPTR_GET_EXT_DATA_REC(
         EDClass->Number[SegIndex],
         &EDEntryData[EDClass->StartByte[SegIndex]]);
#endif

      if (dataPresent != E_OK)
      {
         Dem_SizeEntryDataType index;

         /* fill ED segment with padding values */
         for (index = EDClass->StartByte[SegIndex];
              index < (EDClass->StartByte[SegIndex] + EDClass->Size[SegIndex]);
              ++index)
         {
            EDEntryData[index] = DEM_DATA_PADDING_VALUE;
         }

#if (DEM_DEV_ERROR_DETECT == STD_ON)
         /* report non-available data for EDS */
         DEM_REPORT_ERROR(DEM_SID_MainFunction, DEM_E_NODATAAVAILABLE);
#endif /* DEM_DEV_ERROR_DETECT */
      }
   }
}

_STATIC_ FUNC(void, DEM_CODE) Dem_ShiftFFs(
   CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FFEntryData,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST)      FFClass,
   const Dem_FFIdxType                                      MaxNumFF)
{
   /* shift is only neccessary if the event can hold more than 2 FF records */
   if (MaxNumFF > 2U)
   {
      const Dem_SizeEntryDataType offset = Dem_SizeOfFF(FFClass);
      const Dem_SizeEntryDataType width = offset * (MaxNumFF - 2U);

      /* the freeze frames will be shifted according the following figure:
       *
       *   offset         width
       *   /-^-\   /--------^--------\
       *   +---+---+---+---+-----+---+         +---+---+---+-----+---+---+
       *   | 0 | 1 | 2 | 3 | ... | N |   -->   | 0 | 2 | 3 | ... | N | - |
       *   +---+---+---+---+-----+---+         +---+---+---+-----+---+---+
       *       ^                     ^             ^                 ^
       */

      Dem_ShiftData(&FFEntryData[offset], offset, width);
   }
}

_STATIC_ FUNC(void, DEM_CODE) Dem_ProcessEventEntry(Dem_EventIdType EventId)
{
   const Dem_DTCOriginType origin = Dem_GbiDTCOrigin(EventId);
   const uint8 originIdx = (uint8)(origin - DEM_DTC_ORIGIN_PRIMARY_MEMORY);

   P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) EvMemEntry;
   /* search for DTC in event memory */
   const boolean EntryExists = Dem_SearchForEntry(EventId, &EvMemEntry);

   /* pointer to FF data - for writing */
   P2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FFEntryData = NULL_PTR;

   /* FALSE, if event memory is filled and no entry could be replaced, or
    * DTCRecordUpdate is locked and entry exists or is replaced */
   boolean entryPosIsValid = TRUE;

   Dem_EventIdType OriginalEventId = EventId;
   CDD_DemIdSnapshot_Cnt_G_u8 = EventId;                       /*<<=====================================  DD added this line to capture EventId for Snappshot data DID$5030 */

   if (EntryExists == FALSE)
   {
      /* find empty event memory entry */
      const boolean EmptyEntryExists =
         Dem_SearchForEmptyEntry(originIdx, &EvMemEntry);

      if (EmptyEntryExists == FALSE)
      {
         if (Dem_DTCRecordUpdate == TRUE)
         {
            /* find event memory entry to replace */
            entryPosIsValid =
               Dem_SearchForEntryToReplace(originIdx, EventId, &EvMemEntry);

            /* clear existing event memory entry */
            if (entryPosIsValid != FALSE)
            {
               Dem_DTCStatusMaskType OriginalDTCStatusMask;

               OriginalEventId       = EvMemEntry->EventId;
               OriginalDTCStatusMask = Dem_DTCStatusMasks[OriginalEventId];

               /*
                * ENTER critical section
                */
               SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

               Dem_ClearEntry(EvMemEntry);

               /* clear confirmed (and specific) bit(s), but NOT warning
                * indicator request bit */
               DEM_CLR_EV_ST_MASK(OriginalEventId,
                                  DEM_DTCSTATUSBIT_CDTC |
                                  DEM_SPECIFIC_DTCSTATUSBITS_FOR_ENTRY);

               /*
                * LEAVE critical section
                */
               SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

               /* notify application that event status has changed */
               Dem_RteTriggerOnEventStatus(
                  OriginalEventId,
                  OriginalDTCStatusMask,
                  Dem_DTCStatusMasks[OriginalEventId]);
            }
         }
         else /* DTCRecordUpdate is locked */
         {
            /* do not replace an event memory entry */
            entryPosIsValid = FALSE;

            /* write event Id back into error-queue */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
            {
               boolean EntryIsWritten = Dem_WriteErrorQueueEntry(EventId);

               if (EntryIsWritten == FALSE)
               {
                  DEM_REPORT_ERROR(DEM_SID_MainFunction, DEM_E_PARAM_CONFIG);
               }
            }
#else /* DEM_DEV_ERROR_DETECT */

            /* evaluation of return value is done with DET:ON */
            (void) Dem_WriteErrorQueueEntry(EventId);

#endif /* DEM_DEV_ERROR_DETECT */
         }
      }

      /* create new event memory entry */
      if (entryPosIsValid != FALSE)
      {
         const Dem_DTCStatusMaskType OldDTCStatusMask =
            Dem_DTCStatusMasks[EventId];

         /*
          * ENTER critical section
          */
         SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

         /* set confirmed (and specific) bit(s), to indicate event entry */
         DEM_SET_EV_ST_MASK(EventId,
                            DEM_DTCSTATUSBIT_CDTC |
                            DEM_SPECIFIC_DTCSTATUSBITS_FOR_ENTRY);

#if (DEM_USE_INDICATOR == STD_ON)
         if (Dem_GbiIndicatorUsed(EventId) != FALSE)
         {
            /* set warning indicator request */
            DEM_SET_EV_ST_MASK(EventId, DEM_DTCSTATUSBIT_WIR);
         }
#endif

         /* store inital event entry information */
         EvMemEntry->EventId      = EventId;
         EvMemEntry->NumFF        = 0U;
         EvMemEntry->EntryDataPos = *(Dem_EntryDataFreePos[originIdx]);

         /* hook-function for further variant specific handling */
         DEM_SPECIFIC_HOOK_INITENTRY(EvMemEntry);

         /* recalculate free position of event memory entry data */
         *(Dem_EntryDataFreePos[originIdx]) += Dem_SizeOfEntryData(EventId);

         /*
          * LEAVE critical section
          */
         SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

         /* notify application if event status has changed */
         if (OldDTCStatusMask != Dem_DTCStatusMasks[EventId])
         {
            Dem_RteTriggerOnEventStatus(
               EventId,
               OldDTCStatusMask,
               Dem_DTCStatusMasks[EventId]);
         }
      }
   }
   else /* entry exists */
   {
      /* could sort according to age of element here
       * however, when prestored freeze frames are used, the freeze frame
       * data for an event may not correlate to the time the event is reported
       */

      if (Dem_DTCRecordUpdate == FALSE) /* DTCRecordUpdate is locked */
      {
         /* do not update the event memory entry */
         entryPosIsValid = FALSE;

         /* write event Id back into error-queue */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
         {
            boolean EntryIsWritten = Dem_WriteErrorQueueEntry(EventId);

            if (EntryIsWritten == FALSE)
            {
               DEM_REPORT_ERROR(DEM_SID_MainFunction, DEM_E_PARAM_CONFIG);
            }
         }
#else /* DEM_DEV_ERROR_DETECT */

         /* evaluation of return value is done with DET:ON */
         (void) Dem_WriteErrorQueueEntry(EventId);

#endif /* DEM_DEV_ERROR_DETECT */
      }
   }

   /* update extended data and freeze frames */
   if (entryPosIsValid != FALSE)
   {
      /* get freeze frame class layout */
      CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass =
         Dem_FFClasses[Dem_GbiFFClassIdx(EventId)];

      const Dem_FFIdxType MaxNumFF = Dem_GbiMaxNumFF(EventId);

      /* get index where to place the new FF */
      const Dem_FFIdxType FFIndex = (EvMemEntry->NumFF == MaxNumFF) ?
         (EvMemEntry->NumFF - 1U) : EvMemEntry->NumFF;

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
      const Dem_EventIdType PFFIndex = Dem_GetPFFIndex(EventId);
#endif

      FFEntryData = Dem_FFEntryData(EvMemEntry, FFClass, FFIndex);

      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* update extended data */
      Dem_StoreED(EvMemEntry);

      /* hook-function for further variant specific handling */
      DEM_SPECIFIC_HOOK_EDSTORAGE(EvMemEntry);

      /* check if freeze frame count of this event is reached */
      if (EvMemEntry->NumFF == MaxNumFF)
      {
         CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT)
            FFEntryDataStart = Dem_FFEntryData(EvMemEntry, FFClass, 0U);

         /* shift freeze frames, to get a free place */
         Dem_ShiftFFs(FFEntryDataStart, FFClass, MaxNumFF);
      }
      else
      {
         ++EvMemEntry->NumFF;
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)

      /* check if prestored freeze frame for this event exists */
      if ((Dem_GbiEnablePrestorage(EventId) != FALSE) &&
          DEM_IS_BIT_SET_IN_ARRAY(Dem_PFFEntryValid, PFFIndex))
      {
         CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT)
            PFFEntryData = Dem_GetPFFEntryDataPtr(EventId);

         /*
          * ENTER critical section
          */
         SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

         /* copy PFF to event memory */
         Dem_DataCopy(PFFEntryData, FFEntryData, Dem_SizeOfFF(FFClass));

         /* mark prestored freeze frame as empty */
         DEM_CLR_BIT_IN_ARRAY(Dem_PFFEntryValid, PFFIndex);

         /*
          * LEAVE critical section
          */
         SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      }
      else
      {
         Dem_StoreFF(
   #if (DEM_DEV_ERROR_DETECT == STD_ON)
            DEM_SID_MainFunction,
   #endif /* DEM_DEV_ERROR_DETECT */
            FFEntryData,
            FFClass);
      }

#else /* DEM_MAX_NUMBER_PRESTORED_FF */

      Dem_StoreFF(
   #if (DEM_DEV_ERROR_DETECT == STD_ON)
         DEM_SID_MainFunction,
   #endif
         FFEntryData,
         FFClass);

#endif /* DEM_MAX_NUMBER_PRESTORED_FF */

      /* hook-function for further variant specific handling */
      DEM_SPECIFIC_HOOK_POSTENTRYSTORAGE(OriginalEventId, EvMemEntry);
   }

   /* variant-specific handling of event entry */
   DEM_SPECIFIC_HOOK_EVENTENTRY(FFEntryData, EventId);
}

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
