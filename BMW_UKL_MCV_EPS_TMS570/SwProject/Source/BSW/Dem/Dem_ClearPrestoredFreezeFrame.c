/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_ClearPrestoredFreezeFrame().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_ClearPrestoredFreezeFrame.c 2061 2010-01-18 12:10:39Z olho2924 $
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

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)

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

FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame(
   Dem_EventIdType EventId)
{
   Dem_EventIdType PFFIndex;    /* there are maximal as much PFFs as events */

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_ClearPrestoredFreezeFrame, DEM_E_UNINIT);
      return E_NOT_OK;
   }
   if (EventId == (Dem_EventIdType)DEM_EVENT_ID_INVALID)
   {
      DEM_REPORT_ERROR(DEM_SID_ClearPrestoredFreezeFrame, DEM_E_PARAM_DATA);
      return E_NOT_OK;
   }
   if (EventId > (DEM_NUMBER_OF_EVENTS - 1U))
   {
      DEM_REPORT_ERROR(DEM_SID_ClearPrestoredFreezeFrame, DEM_E_PARAM_CONFIG);
      return E_NOT_OK;
   }
   if (Dem_GbiEnablePrestorage(EventId) == FALSE)
   {
      DEM_REPORT_ERROR(DEM_SID_ClearPrestoredFreezeFrame, DEM_E_PARAM_CONFIG);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   PFFIndex = Dem_GetPFFIndex(EventId);

   /* mark prestored freeze frame as empty */
   DEM_ATOMIC_CLR_BIT_IN_ARRAY(Dem_PFFEntryValid, PFFIndex);

   return E_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

#endif /* DEM_MAX_NUMBER_PRESTORED_FF */

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
