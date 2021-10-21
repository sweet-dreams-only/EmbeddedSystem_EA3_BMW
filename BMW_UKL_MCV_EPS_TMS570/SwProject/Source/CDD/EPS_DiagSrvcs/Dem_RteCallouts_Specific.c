/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all static external API declarations of the
 ** AUTOSAR module Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Stephanie Muehlenmeister
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** Dem_RteCallouts_Specific.c 
 ** Release: 
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2008 by Elektrobit Automotive GmbH
 ** All rights exclusively reserved for Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem.h>                                /* Diagnostic Event Manager */

/* #include your callback-function header-file(s) here */

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

/* if RTE is not available provide following callouts */
#if (DEM_INCLUDE_RTE == STD_OFF)

FUNC(void, DEM_CODE) Dem_RteTriggerOnErrorEntry(
   const Dem_EventIdType EventId,
   const uint32          Timestamp)
{
   Dem_DTCType                 DTCOfEvent;
   Dem_ReturnGetDTCOfEventType StatusDTCOfEvent;

   (void) Dem_GetDTCOfEvent(
      EventId, DEM_DTC_KIND_ALL_DTCS, &DTCOfEvent, &StatusDTCOfEvent);

   switch (EventId)
   {
      case DM_QUEUE_FULL:
         /* (void) Darh_TriggerOnErrorEntry(DTCOfEvent, Timestamp) */
         break;

      case DM_TEST_APPL:
         /* (void) Darh_TriggerOnErrorEntry(DTCOfEvent, Timestamp) */
         break;

      case DM_TEST_COM:
         /* (void) Darh_TriggerOnErrorEntry(DTCOfEvent, Timestamp) */
         break;

      case DM_EVENT_ZEITBOTSCHAFTTIMEOUT:
         /* (void) Darh_TriggerOnErrorEntry(DTCOfEvent, Timestamp) */
         break;

      case DM_QUEUE_DELETED:
         /* (void) Darh_TriggerOnErrorEntry(DTCOfEvent, Timestamp) */
         break;

      default:
         break;
   }
}

FUNC(void, DEM_CODE) Dem_RteClearEventAllowed(
   const Dem_EventIdType                          EventId,
   CONSTP2VAR(boolean, AUTOMATIC, DEM_VAR_NOINIT) Allowed)
{
   *Allowed = TRUE;
}

#endif /* DEM_INCLUDE_RTE == STD_ON */

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
