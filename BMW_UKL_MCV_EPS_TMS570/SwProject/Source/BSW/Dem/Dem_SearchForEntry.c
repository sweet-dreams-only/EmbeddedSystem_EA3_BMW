/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_SearchForEntry().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SearchForEntry.c 2061 2010-01-18 12:10:39Z olho2924 $
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

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

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

FUNC(boolean, DEM_CODE) Dem_SearchForEntry(
   Dem_EventIdType        EventId,
   CONSTP2VAR(
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT),
      AUTOMATIC, DEM_VAR) FoundEntry)
{
   boolean result = FALSE;

   const Dem_DTCOriginType origin = Dem_GbiDTCOrigin(EventId);
   const uint8 originIdx = (uint8)(origin - DEM_DTC_ORIGIN_PRIMARY_MEMORY);
   const Dem_SizeEvMemEntryType sizeEventMem = Dem_SizeEventMem[originIdx];

   Dem_SizeEvMemEntryType index;
   P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) Entry =
      Dem_EventMem[originIdx];

   /* search for entry with given event id */
   for (index = 0U;
        (index < sizeEventMem) && (Entry[index].EventId != EventId);
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

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
