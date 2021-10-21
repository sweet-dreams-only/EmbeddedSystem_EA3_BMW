/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem internal
 ** function Dem_SearchForEntryToReplace().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider, Tobias Jordan
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SearchForEntryToReplace.c 2480 2011-03-21 16:00:06Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by BMW Group
 ** All rights exclusively reserved for BMW Group,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Dem_Helper.h>                                /* Dem helper macros */
#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Internal_Depend_Specific.h> /* API and internal declarations,
                                           * dependent and static part */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief compare age of two event memory entries
 **
 ** \param[in] Entry1  pointer to the first event memory entry to compare
 ** \param[in] Entry2  pointer to the second event memory entry to compare
 **
 ** \retval TRUE: Entry1 is older that Entry2
 ** \retval FALSE: Entry1 is younger or of the same age as Entry2
 **/
_STATIC_ FUNC(boolean, DEM_CODE) Dem_CmpAge(
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) Entry1,
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) Entry2);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

FUNC(boolean, DEM_CODE) Dem_SearchForEntryToReplace(
   uint8                  OriginIdx,
   Dem_EventIdType        EventId,
   CONSTP2VAR(
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT),
      AUTOMATIC, DEM_VAR) FoundEntry)
{
   const Dem_SizeEvMemEntryType sizeEventMem = Dem_SizeEventMem[OriginIdx];

   Dem_SizeEvMemEntryType index;

   CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
      EventMemory = Dem_EventMem[OriginIdx];

   const Dem_DTCSeverityType Severity = Dem_GbiDTCSeverity(EventId);

   P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_APPL_DATA) Entry;
   P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_APPL_DATA) BestEntry =
      NULL_PTR; /* initialized to avoid warning, but not necessary */
   Dem_DTCSeverityType BestSeverity = Severity;
      /* initialized to avoid warning, but not necessary */

   boolean CandidateFound = FALSE;

#if (defined DEM_GLOBAL_DTCSEVERITY_VALUE)
   /* Dem_GbiDTCSeverity is a function like macro */
   DEM_PARAM_UNUSED(EventId);
#endif

   /* if this function is called, no free entry has been found, so the
    * condition byte for the event memory must be set (BMWDem025, BMWDem029) */
   DEM_SET_EV_MEM_OVERFLOW(OriginIdx);

   /* BMWDem033: If no free entry is found then an entry with a lower severity
    * than that of the current event's severity shall be returned. If several
    * such entries exist, the entry with the lowest severity shall be returned.
    * If several entries have this lowest severity, then the oldest of these
    * entries shall be returned. */
   /* search for the oldest entry with lowest and lower severity */
   index = 0U;
   Entry = &EventMemory[index];
   while (   (index < sizeEventMem)
          && DEM_IS_BIT_SET(Dem_DTCStatusMasks[Entry->EventId],
                            DEM_DTCSTATUSBIT_CDTC)
          )
   {
      const Dem_DTCSeverityType currentSeverity =
         Dem_GbiDTCSeverity(Entry->EventId);

      /* only search if stored event has lower severity than new one */
      if (currentSeverity < Severity)
      {
         /* first match */
         if (CandidateFound == FALSE)
         {
            /* slot containing entry with lower severity found */
            BestEntry = Entry;
            BestSeverity = currentSeverity;
            CandidateFound = TRUE;
         }
         /* further matches */
         else
         {
            if (currentSeverity < BestSeverity)
            {
               /* re-set best slot containing entry with lower severity */
               BestEntry = Entry;
               BestSeverity = currentSeverity;
            }
            else if (currentSeverity == BestSeverity)
            {
               const boolean EvOlderThanBestEv = Dem_CmpAge(Entry, BestEntry);

               if (EvOlderThanBestEv != FALSE)
               {
                  /* re-set best slot containing older entry with same
                   * severity */
                  BestEntry = Entry;
               }
            }
            else /* currentSeverity > BestSeverity */
            {
               /* do not re-set best slot containing entry with higher
                * severity */
            }
         }
      }

      index++;
      /* pointer won't be used if index is out of range */
      Entry = &EventMemory[index];
   }

   if (index < sizeEventMem)
   {
      /* found an entry without CDTC bit set */
      BestEntry = &EventMemory[index];
      CandidateFound = TRUE;
   }

   /* BMWDem034: If no entry with a lower severity is found then the oldest
    * entry with Bit#0 (testFailed) and Bit#6 (testNotCompletedThis-
    * OperationCycle) of the StatusOfDTC cleared shall be returned. */
   /* no entry has lower severity, search for oldest non-present entry */
   if (CandidateFound == FALSE)
   {
      Dem_DTCStatusMaskType StatusMask;

      for (index = 0U; index < sizeEventMem; index++)
      {
         Entry = &EventMemory[index];

         /* read status atomically */
         StatusMask = Dem_DTCStatusMasks[Entry->EventId];

         if (    (!(DEM_IS_BIT_SET(StatusMask, DEM_DTCSTATUSBIT_TF)))
              && (!(DEM_IS_BIT_SET(StatusMask, DEM_DTCSTATUSBIT_TNCTOC)))
            )
         {
            /* first match */
            if (CandidateFound == FALSE)
            {
               /* slot containing non-present entry found */
               BestEntry = Entry;
               CandidateFound = TRUE;
            }
            /* further matches */
            else
            {
               const boolean EvOlderThanBestEv = Dem_CmpAge(Entry, BestEntry);

               if (EvOlderThanBestEv != FALSE)
               {
                  /* re-set best slot containing older non-present entry */
                  BestEntry = Entry;
               }
            }
         }
      }
   }

   if (CandidateFound != FALSE)
   {
      *FoundEntry = BestEntry;
   }
   /* else: */
   /* BMWDem035: If no entry satisfying BMWDem033 or BMWDem034 was found the
    * sequence shall return with false.
    */

   return CandidateFound;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

_STATIC_ FUNC(boolean, DEM_CODE) Dem_CmpAge(
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) Entry1,
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) Entry2)
{
   /* get freeze frame class layout */
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass1 =
      Dem_FFClasses[Dem_GbiFFClassIdx(Entry1->EventId)];
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass2 =
      Dem_FFClasses[Dem_GbiFFClassIdx(Entry2->EventId)];

   /* get index of last FF */
   const Dem_FFIdxType FFIndex1 = Entry1->NumFF - 1U;
   const Dem_FFIdxType FFIndex2 = Entry2->NumFF - 1U;

   /* get pointer to FF data */
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT)
      ff1 = Dem_FFEntryData(Entry1, FFClass1, FFIndex1);
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT)
      ff2 = Dem_FFEntryData(Entry2, FFClass2, FFIndex2);

   const uint32 time1 = Dem_GetTimeFromFFData(ff1);
   const uint32 time2 = Dem_GetTimeFromFFData(ff2);

   return (boolean)((time1 < time2) ? TRUE : FALSE);
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"


/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
