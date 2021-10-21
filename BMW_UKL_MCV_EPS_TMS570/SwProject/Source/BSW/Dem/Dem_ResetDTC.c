/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the internal static function
 ** Dem_ResetDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_ResetDTC.c 2556 2011-09-08 11:34:37Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Internal_Depend_Specific.h> /* API and internal declarations,
                                           * dependent and static part */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

FUNC(void, DEM_CODE) Dem_ResetDTC(Dem_EventIdType EventId)
{
   boolean clearAllowed;

   Dem_RteClearEventAllowed(EventId, &clearAllowed);

   if (clearAllowed != FALSE)
   {
      const Dem_DTCStatusMaskType StatusMask =
         (DEM_DTCSTATUSBIT_TNCSLC | DEM_DTCSTATUSBIT_TNCTOC);
      Dem_DTCStatusMaskType OldStatusMask;

      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) EvMemEntry;
      boolean EntryExists;

      /*
       * signal access of event memory
       */
      Dem_DcmAccessInProgress = TRUE;

      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* search for DTC in event memory */
      EntryExists = Dem_SearchForEntry(EventId, &EvMemEntry);

      if (EntryExists != FALSE)
      {
         Dem_ClearEntry(EvMemEntry);
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* get old status mask */
      OldStatusMask = Dem_DTCStatusMasks[EventId];

      /* reset status mask for event */
      Dem_DTCStatusMasks[EventId] = StatusMask;

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
      /* release prestored freeze frame */
      if (Dem_GbiEnablePrestorage(EventId) != FALSE)
      {
         /* mark prestored freeze frame as unused */
         DEM_ATOMIC_CLR_BIT_IN_ARRAY(
            Dem_PFFEntryValid, Dem_GetPFFIndex(EventId));
      }
#endif

      if (EntryExists != FALSE)
      {
         /* one event memory entry has changed */
         Dem_CheckForImmediateEntryStorage(EventId, EvMemEntry, TRUE, TRUE);
      }

      /*
       * signal access of event memory finished
       */
      Dem_DcmAccessInProgress = FALSE;

#if (DEM_USE_DEBOUNCE == STD_ON)
      /* reset debouncing counters for event */
      Dem_DebounceFctPtrTable[Dem_GbiDebounceAlgo(EventId)].ResetFct(EventId);
#else
      Dem_ResetDebounceMonitor(EventId);
#endif

      /* report event change by callback */
      if (OldStatusMask != StatusMask)
      {
         /* notify application that event status has changed */
         Dem_RteTriggerOnEventStatus(EventId, OldStatusMask, StatusMask);

         /* Dem009: inform application about clearance */
         Dem_RteInitMonitorForEvent(EventId, DEM_INIT_MONITOR_CLEAR);
      }
   }
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
