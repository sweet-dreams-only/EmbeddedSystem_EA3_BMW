/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_ResetEventStatus().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_ResetEventStatus.c 2514 2011-05-10 15:03:41Z olho2924 $
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

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

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

FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus(Dem_EventIdType EventId)
{
   Std_ReturnType result = E_OK;
   uint8 GroupIdx;
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_ResetEventStatus, DEM_E_UNINIT);
      return E_NOT_OK;
   }
   if (EventId == (Dem_EventIdType)DEM_EVENT_ID_INVALID)
   {
      DEM_REPORT_ERROR(DEM_SID_ResetEventStatus, DEM_E_PARAM_DATA);
      return E_NOT_OK;
   }
   if (EventId > (DEM_NUMBER_OF_EVENTS - 1U))
   {
      DEM_REPORT_ERROR(DEM_SID_ResetEventStatus, DEM_E_PARAM_CONFIG);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   GroupIdx = Dem_GbiDTCGroupIdx(EventId);

   /* update only if event update is enabled for this DTC group */
   if (   DEM_SPECIFIC_HOOK_ISEVSTUPDATEENABLED(GroupIdx)
       && DEM_SPECIFIC_HOOK_ISDTCSTORAGEENABLED(GroupIdx)
      )
   {
      /* clear bit only if it is set */
      if (DEM_IS_EV_ST_BIT_SET(EventId, DEM_DTCSTATUSBIT_TF))
      {
         const Dem_DTCStatusMaskType OldDTCStatusMask =
            Dem_DTCStatusMasks[EventId];

         /*
          * ENTER critical section
          */
         SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

         /* TEST FAILED -> 0 */
         DEM_CLR_EV_ST_MASK(EventId, DEM_DTCSTATUSBIT_TF);
         /* other bits are unchanged */

         /*
          * LEAVE critical section
          */
         SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

         /* notify application that event status has changed */
         Dem_RteTriggerOnEventStatus(
            EventId,
            OldDTCStatusMask,
            Dem_DTCStatusMasks[EventId]);
      }
      /* else: testFailed bit is already set to 0, do nothing */
   }
   else
   {
      result = E_NOT_OK;
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
