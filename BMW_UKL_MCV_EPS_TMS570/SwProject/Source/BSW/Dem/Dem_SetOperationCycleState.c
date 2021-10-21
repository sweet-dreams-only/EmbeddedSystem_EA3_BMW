/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_SetOperationCycleState().
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SetOperationCycleState.c 2558 2011-09-09 10:30:11Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise
 **
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief Function to handle the pending-status bit of the given event Id
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_HandlePendingDTCStatus(
   const Dem_EventIdType EventId);

#if (DEM_USE_HEALING == STD_ON)

/** \brief Function to update the healing counter of the given event Id, if an
 ** entry exists
 **
 ** The entry will be deleted, if the healing counter reaches 0(zero).
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_UpdateHealingCounter(
   const Dem_EventIdType EventId);

#endif

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState(
   Dem_OperationCycleIdType    OperationCycleId,
   Dem_OperationCycleStateType CycleState)
{
   CONSTP2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_VAR_NOINIT)
      StoredCycleState = &Dem_OpCycleState[OperationCycleId];

   Dem_EvIdLeastType EvId;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_SetOperationCycleState, DEM_E_UNINIT);
      return E_NOT_OK;
   }
   if (OperationCycleId >= DEM_NUM_OPCYCLES)
   {
      DEM_REPORT_ERROR(DEM_SID_SetOperationCycleState, DEM_E_PARAM_CONFIG);
      return E_NOT_OK;
   }
   if ((CycleState != DEM_CYCLE_STATE_START)
       && (CycleState != DEM_CYCLE_STATE_END))
   {
      DEM_REPORT_ERROR(DEM_SID_SetOperationCycleState, DEM_E_PARAM_DATA);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   if (*StoredCycleState != CycleState)
   {
      /* switch stored state to new state */
      *StoredCycleState = CycleState;

      if (CycleState == DEM_CYCLE_STATE_START)
      {
         /* event memory was read from NVRAM */
         for (EvId = 1U; EvId <= (DEM_NUMBER_OF_EVENTS - 1U); ++EvId)
         {
            /* only for events of this operation cycle */
            if (Dem_GbiOpCycleIdx((Dem_EventIdType)EvId) == OperationCycleId)
            {
               const Dem_DTCStatusMaskType OldDTCStatusMask =
                  Dem_DTCStatusMasks[EvId];

               /*
                * ENTER critical section
                */
               SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

               /* set DTC status bit: "test not completed this op. cycle" */
               DEM_SET_EV_ST_MASK(EvId, DEM_DTCSTATUSBIT_TNCTOC);

               /* clear DTC status bit: "test failed this op. cycle" */
               DEM_CLR_EV_ST_MASK(EvId, DEM_DTCSTATUSBIT_TFTOC);

               /*
                * LEAVE critical section
                */
               SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

#if (DEM_USE_DEBOUNCE == STD_ON)
               /* reset debouncing counters for event */
               Dem_DebounceFctPtrTable[
                  Dem_GbiDebounceAlgo((Dem_EventIdType)EvId)].
                     ResetFct((Dem_EventIdType)EvId);
#else
               Dem_ResetDebounceMonitor((Dem_EventIdType)EvId);
#endif /* DEM_USE_DEBOUNCE */

               /* notify application if event status has changed */
               if (OldDTCStatusMask != Dem_DTCStatusMasks[EvId])
               {
                  Dem_RteTriggerOnEventStatus(
                     (Dem_EventIdType)EvId,
                     OldDTCStatusMask,
                     Dem_DTCStatusMasks[EvId]);
               }

               /* reinit of monitor function */
               Dem_RteInitMonitorForEvent(
                  (Dem_EventIdType)EvId, DEM_INIT_MONITOR_RESTART);
            }
         }
      }
      else /* CycleState == DEM_CYCLE_STATE_END */
      {
         /* event memory was read from NVRAM */
         for (EvId = 1U; EvId <= (DEM_NUMBER_OF_EVENTS - 1U); ++EvId)
         {
            /* only for events of this operation cycle */
            if (Dem_GbiOpCycleIdx((Dem_EventIdType)EvId) == OperationCycleId)
            {
               const Dem_DTCStatusMaskType OldDTCStatusMask =
                  Dem_DTCStatusMasks[EvId];

               /* handle "pending DTC status" flag */
               Dem_HandlePendingDTCStatus((Dem_EventIdType)EvId);

#if (DEM_USE_HEALING == STD_ON)
               /* if healing is enabled */
               if (Dem_GbiHealingCycles((Dem_EventIdType)EvId) > 0U)
               {
                  /* decrease healing counter (may lead to status change) */
                  Dem_UpdateHealingCounter((Dem_EventIdType)EvId);
               }
#endif

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
               /* if prestorage of FF is enabled */
               if (Dem_GbiEnablePrestorage((Dem_EventIdType)EvId) != FALSE)
               {
                  /* discard return value function returns always E_OK */
                  (void)Dem_ClearPrestoredFreezeFrame((Dem_EventIdType)EvId);
               }
#endif

               /* notify application if event status has changed */
               if (OldDTCStatusMask != Dem_DTCStatusMasks[EvId])
               {
                  Dem_RteTriggerOnEventStatus(
                     (Dem_EventIdType)EvId,
                     OldDTCStatusMask,
                     Dem_DTCStatusMasks[EvId]);
               }

               /* hook-function for further variant specific handling */
               DEM_SPECIFIC_HOOK_ENDOPCYCLE((Dem_EventIdType)EvId);
            }
         }
      }
   }

   return E_OK;
}

/*==================[internal function definitions]=========================*/

_STATIC_ FUNC(void, DEM_CODE) Dem_HandlePendingDTCStatus(
   const Dem_EventIdType EventId)
{
   /* for the algorithm calculating the pending DTC flag only operation cycles
    * count, in which the test ran at least once, so only update the flag, if
    * the event was tested in the current op. cycle */
   if (!DEM_IS_EV_ST_BIT_SET(EventId, DEM_DTCSTATUSBIT_TNCTOC))
   {
      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      if (DEM_IS_EV_ST_BIT_SET(EventId, DEM_DTCSTATUSBIT_TFTOC))
      {
         /* reset condition bit if test failed in the current op. cycle */
         DEM_CLR_BIT_IN_ARRAY(Dem_ClearPDTCFlags, EventId);
      }
      else /* test ran, passed and never failed in the current op. cycle */
      {
         /* test ran, passed and never failed in the last and the current
          * op. cycles */
         if (DEM_IS_BIT_SET_IN_ARRAY(Dem_ClearPDTCFlags, EventId))
         {
            /* clear "pending DTC status" flag */
            DEM_CLR_EV_ST_MASK(EventId, DEM_DTCSTATUSBIT_PDTC);

            /* clear "clear pending DTC condition" flag */
            DEM_CLR_BIT_IN_ARRAY(Dem_ClearPDTCFlags, EventId);
         }
         else
         {
            /* remember the "clear PDTC condition" for the next op. cycle */
            DEM_SET_BIT_IN_ARRAY(Dem_ClearPDTCFlags, EventId);
         }
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
   }
}

#if (DEM_USE_HEALING == STD_ON)

_STATIC_ FUNC(void, DEM_CODE) Dem_UpdateHealingCounter(
   const Dem_EventIdType EventId)
{
   P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_APPL_DATA) EvMemEntry;
   /* search for DTC in event memory */
   const boolean EntryExists = Dem_SearchForEntry(EventId, &EvMemEntry);

   /* process healing algorithm only, if the event is registered and was
    * tested and never failed this operation cycle */
   if (   (EntryExists != FALSE)
       && (!(DEM_IS_EV_ST_BIT_SET(EventId, (DEM_DTCSTATUSBIT_TNCTOC | DEM_DTCSTATUSBIT_TFTOC))))
      )
   {
      /* get extended data class layout */
      CONSTP2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST) EDClass =
         Dem_EDClasses[Dem_GbiEDClassIdx(EventId)];

      /* get the EDS index of the healing counter */
      const Dem_EDSegIdxType HealingCounterIdx =
         Dem_FindEDNumIndex(EDClass, Dem_HealingCounterRecNum);

      /* get pointer to healing counter */
      CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) HealingCounter =
         Dem_EDEntryData(EvMemEntry);
      const uint32 HealingCounterOffset = EDClass->StartByte[HealingCounterIdx];

      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* decrease healing counter */
      HealingCounter[HealingCounterOffset]--;

      /* heal the event if counter reaches zero */
      if (HealingCounter[HealingCounterOffset] == (Dem_EntryDataType)0U)
      {
         Dem_ClearEntry(EvMemEntry);

         /* clear confirmed, warning indicator request (and specific) bits */
         DEM_CLR_EV_ST_MASK(EventId,
                            DEM_DTCSTATUSBIT_CDTC |
                            DEM_DTCSTATUSBIT_WIR  |
                            DEM_SPECIFIC_DTCSTATUSBITS_FOR_ENTRY);
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* hook-function for further variant specific handling */
      DEM_SPECIFIC_HOOK_UPDATEHC(EventId, EvMemEntry);
   }
}
#endif

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
