/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_ClearEntry().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_ClearEntry.c 2061 2010-01-18 12:10:39Z olho2924 $
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

FUNC(void, DEM_CODE) Dem_ClearEntry(
   CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) EvMemEntry)
{
   Dem_SizeEvMemEntryType entry;

   const Dem_SizeEntryDataType EntryDataSize =
      Dem_SizeOfEntryData(EvMemEntry->EventId);

   const Dem_DTCOriginType origin = Dem_GbiDTCOrigin(EvMemEntry->EventId);
   const uint8 originIdx = (uint8)(origin - DEM_DTC_ORIGIN_PRIMARY_MEMORY);

   /* calculate entry data size behind data to delete */
   const Dem_SizeEntryDataType width = *(Dem_EntryDataFreePos[originIdx]) -
      EvMemEntry->EntryDataPos - EntryDataSize;

   /* shift extended and freeze frame data, to close the gap - this ensures
    * enough entry data capacity to store maximal number of entries */
   Dem_ShiftData(Dem_EDEntryData(EvMemEntry), EntryDataSize, width);

   /* shift relevant event memory entry data positions */
   for (entry = 0U; entry < Dem_SizeEventMem[originIdx]; ++entry)
   {
      if (Dem_EventMem[originIdx][entry].EntryDataPos
          > EvMemEntry->EntryDataPos)
      {
         Dem_EventMem[originIdx][entry].EntryDataPos -= EntryDataSize;
      }
   }

   /* recalculate free position of event memory entry data */
   *(Dem_EntryDataFreePos[originIdx]) -= EntryDataSize;

   /* clear event entry information */
   EvMemEntry->EventId = (Dem_EventIdType)DEM_EVENT_ID_INVALID;
   /* not necessary to reset EvMemEntry->NumFF (= 0) */
   /* not necessary to reset EvMemEntry->EntryDataPos (= 0) */
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
