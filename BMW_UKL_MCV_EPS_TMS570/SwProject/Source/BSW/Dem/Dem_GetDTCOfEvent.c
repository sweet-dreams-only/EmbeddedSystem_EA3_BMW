/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetDTCOfEvent().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetDTCOfEvent.c 2061 2010-01-18 12:10:39Z olho2924 $
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

#if (DEM_DEV_ERROR_DETECT == STD_ON)

#if (defined DEM_SET_STATUSDTCOFEVENT)
#error DEM_SET_STATUSDTCOFEVENT already defined
#endif
/** \brief Macro to set StatusDTCOfEvent but only if the pointer is valid */
#define DEM_SET_STATUSDTCOFEVENT(status) \
   do                                    \
   {                                     \
      if (StatusDTCOfEvent != NULL_PTR)  \
      {                                  \
         *StatusDTCOfEvent = (status);   \
      }                                  \
   }                                     \
   while (0)

#endif /* DEM_DEV_ERROR_DETECT */

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

FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent(
   Dem_EventIdType                              EventId,
   Dem_DTCKindType                              DTCKind,
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent,
   P2VAR(Dem_ReturnGetDTCOfEventType, AUTOMATIC, DEM_APPL_DATA)
                                                StatusDTCOfEvent)
{
   Std_ReturnType result = E_NOT_OK;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* check of Dem_InitializationState is not necessary:
    * it's allowed to get DTC of event even if DEM is uninitialized */

   if (EventId == (Dem_EventIdType)DEM_EVENT_ID_INVALID)
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCOfEvent, DEM_E_PARAM_DATA);
      DEM_SET_STATUSDTCOFEVENT(DEM_GET_DTCOFEVENT_WRONG_EVENTID);
      return E_NOT_OK;
   }
   if (EventId > (DEM_NUMBER_OF_EVENTS - 1U))
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCOfEvent, DEM_E_PARAM_CONFIG);
      DEM_SET_STATUSDTCOFEVENT(DEM_GET_DTCOFEVENT_WRONG_EVENTID);
      return E_NOT_OK;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCOfEvent, DEM_E_PARAM_DATA);
      DEM_SET_STATUSDTCOFEVENT(DEM_GET_DTCOFEVENT_WRONG_DTCKIND);
      return E_NOT_OK;
   }

   if ((DTCOfEvent == NULL_PTR) || (StatusDTCOfEvent == NULL_PTR))
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCOfEvent, DEM_E_PARAM_ADDRESS);
      DEM_SET_STATUSDTCOFEVENT(DEM_GET_DTCOFEVENT_WRONG_EVENTID);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   if (DTCKind == Dem_GbiDTCKind(EventId))
   {
      /* get the DTC mapped to event Id */
      *DTCOfEvent = Dem_GbiDTC(EventId);

      result = E_OK;

      *StatusDTCOfEvent = DEM_GET_DTCOFEVENT_OK;
   }
   else
   {
      *StatusDTCOfEvent = DEM_GET_DTCOFEVENT_WRONG_DTCKIND;
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
