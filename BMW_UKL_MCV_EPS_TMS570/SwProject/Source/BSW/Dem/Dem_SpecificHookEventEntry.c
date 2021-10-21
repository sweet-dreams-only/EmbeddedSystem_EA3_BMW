/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the vendor-specific Dem function
 ** Dem_SpecificHookEventEntry().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SpecificHookEventEntry.c 2562 2011-09-12 08:16:11Z olho2924 $
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

FUNC(void, DEM_CODE) Dem_SpecificHookEventEntry(
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FFData,
   const Dem_EventIdType                                      EventId)
{
   uint32 timestamp;

   if (FFData == NULL_PTR)
   {
      Dem_EntryDataType fakeFFdata[7];

      /* no freeze frame data for event - get time using callback function,
       * return value is not evaluated -> error handling has to be done
       * by application */
#if (DEM_GET_DATA_VALUE_BY_DATAID_RTE_USAGE == STD_ON)
      (void) Rte_Call_DataValueByDataId_GetDataValueByDataIdentifier(
                DEM_FIXED_FFSDID_ABSOLUTE_TIME, &fakeFFdata[3]);
#else
      (void) DEM_CBK_FUNCPTR_GET_DATA_VALUE_BY_DATAID(
                DEM_FIXED_FFSDID_ABSOLUTE_TIME, &fakeFFdata[3]);
#endif
      timestamp = Dem_GetTimeFromFFData(fakeFFdata);
   }
   else
   {
      /* get time out of freeze frame */
      timestamp = Dem_GetTimeFromFFData(FFData);
   }

   Dem_RteTriggerOnErrorEntry(EventId, timestamp);
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
