/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_SetEventStatus().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SetEventStatus.c 2514 2011-05-10 15:03:41Z olho2924 $
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

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(
   Dem_EventIdType     EventId,
   Dem_EventStatusType EventStatus)
{
   Std_ReturnType result;
   boolean ErrorIndication = FALSE;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_SetEventStatus, DEM_E_UNINIT);
      return E_NOT_OK;
   }
   if (EventId == (Dem_EventIdType)DEM_EVENT_ID_INVALID)
   {
      DEM_REPORT_ERROR(DEM_SID_SetEventStatus, DEM_E_PARAM_DATA);
      return E_NOT_OK;
   }
   if (EventId > (DEM_NUMBER_OF_EVENTS - 1U))
   {
      DEM_REPORT_ERROR(DEM_SID_SetEventStatus, DEM_E_PARAM_CONFIG);
      return E_NOT_OK;
   }
   if (   (   (EventStatus != DEM_EVENT_STATUS_PASSED)
           && (EventStatus != DEM_EVENT_STATUS_FAILED))
       && (   (EventStatus != DEM_EVENT_STATUS_PREPASSED)
           && (EventStatus != DEM_EVENT_STATUS_PREFAILED))
      )
   {
      DEM_REPORT_ERROR(DEM_SID_SetEventStatus, DEM_E_PARAM_DATA);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   result = Dem_InternalSetEventStatus(EventId, EventStatus, &ErrorIndication);

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (result != E_OK)
   {
      DEM_REPORT_ERROR(DEM_SID_SetEventStatus, DEM_E_PARAM_CONFIG);
   }
#endif /* DEM_DEV_ERROR_DETECT */

   return (ErrorIndication == TRUE) ? E_NOT_OK : result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
