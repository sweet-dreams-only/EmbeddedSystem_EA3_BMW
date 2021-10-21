/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_ReportErrorStatus().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_ReportErrorStatus.c 2558 2011-09-09 10:30:11Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/** \brief Error-Queue-Access-Function to check the validity of the event Id
 **
 ** \param[in] EventId  0 < EventId <= DEM_MAX_EVENTID
 **
 ** \return Boolean value indicating presence of event Id in error-queue
 ** \retval TRUE  an event Id was already present in the error-queue
 ** \retval FALSE event Id was not present in the error-queue
 **
 ** \Reentrancy{Non reentrant}
 ** \Synchronicity{Synchronous}
 **/
_STATIC_ FUNC(boolean, DEM_CODE) Dem_CheckErrorQueueEntry(
   const Dem_EventIdType EventId);

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

FUNC(void, DEM_CODE) Dem_ReportErrorStatus(
   Dem_EventIdType     EventId,
   Dem_EventStatusType EventStatus)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* this function can also be called within pre-initialized state */
   if (Dem_InitializationState == DEM_UNINITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_ReportErrorStatus, DEM_E_UNINIT);
      return;
   }
   if (EventId == (Dem_EventIdType)DEM_EVENT_ID_INVALID)
   {
      DEM_REPORT_ERROR(DEM_SID_ReportErrorStatus, DEM_E_PARAM_DATA);
      return;
   }
   if (EventId > (DEM_NUMBER_OF_EVENTS - 1U))
   {
      DEM_REPORT_ERROR(DEM_SID_ReportErrorStatus, DEM_E_PARAM_CONFIG);
      return;
   }
   if (   (   (EventStatus != DEM_EVENT_STATUS_PASSED)
           && (EventStatus != DEM_EVENT_STATUS_FAILED))
       && (   (EventStatus != DEM_EVENT_STATUS_PREPASSED)
           && (EventStatus != DEM_EVENT_STATUS_PREFAILED))
      )
   {
      DEM_REPORT_ERROR(DEM_SID_ReportErrorStatus, DEM_E_PARAM_DATA);
      return;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   if (   (Dem_InitializationState == DEM_PREINITIALIZED)
       || (Dem_InitializationState == DEM_POSTINITIALIZED)
      )
   {
      if (EventStatus == DEM_EVENT_STATUS_FAILED)
      {
         const boolean EntryExists = Dem_CheckErrorQueueEntry(EventId);

         /* no double report of events during preinitialization */
         if (EntryExists == FALSE)
         {
            /* make entry in error-queue */

#if (DEM_DEV_ERROR_DETECT == STD_ON)
            boolean EntryIsWritten = Dem_WriteErrorQueueEntry(EventId);

            if (EntryIsWritten == FALSE)
            {
               DEM_REPORT_ERROR(DEM_SID_ReportErrorStatus, DEM_E_PARAM_CONFIG);
            }
#else /* DEM_DEV_ERROR_DETECT */

            /* evaluation of return value is done with DET:ON */
            (void) Dem_WriteErrorQueueEntry(EventId);

#endif /* DEM_DEV_ERROR_DETECT */
         }
      }
   }
   else /* Dem_InitializationState == DEM_INITIALIZED or development error */
   {
      /* process "normal" event handling */

      boolean UnusedErrorIndication;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
      Std_ReturnType result = Dem_InternalSetEventStatus(EventId,
                                                         EventStatus,
                                                         &UnusedErrorIndication);

      if (result != E_OK)
      {
         DEM_REPORT_ERROR(DEM_SID_ReportErrorStatus, DEM_E_PARAM_CONFIG);
      }
#else /* DEM_DEV_ERROR_DETECT */

      /* evaluation of return value is done with DET:ON */
      (void) Dem_InternalSetEventStatus(EventId,
                                        EventStatus,
                                        &UnusedErrorIndication);

#endif /* DEM_DEV_ERROR_DETECT */

   }
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

_STATIC_ FUNC(boolean, DEM_CODE) Dem_CheckErrorQueueEntry(
   const Dem_EventIdType EventId)
{
   boolean result = FALSE;
   uint8_least index;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   for (index = 0U;
        (index < (uint8_least)DEM_BSW_ERROR_BUFFER_SIZE) && (result == FALSE);
        index++)
   {
      if (Dem_ErrorQueue[index] == EventId)
      {
         result = TRUE;
      }
   }

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   return result;
}

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
