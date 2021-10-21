/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetNumberOfFilteredDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetNumberOfFilteredDTC.c 2061 2010-01-18 12:10:39Z olho2924 $
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

FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfFilteredDTC(
   P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC)
{
   Dem_EvIdLeastType EvId;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetNumberOfFilteredDTC, DEM_E_UNINIT);
      return E_NOT_OK;
   }
   if (NumberOfFilteredDTC == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetNumberOfFilteredDTC, DEM_E_PARAM_ADDRESS);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   *NumberOfFilteredDTC = 0U; /* total number of counted DTCs */

   /* When calculing the number of filtered DTCs the event memory need not be
    * locked (by DcmAccessInProgress): when interrupting this routine while
    * looping over the events, modifications of events with Id smaller than
    * the current processed Id are neglected, while modifications of events
    * with event Id greater than the current processed Id are represented by
    * the result. Thus the result is never corrupt (but at most represents an
    * obsolete state of the event memory). */
   for (EvId = 1U; EvId <= (DEM_NUMBER_OF_EVENTS - 1U); ++EvId)
   {
      Dem_DTCStatusMaskType idleDTCStatus; /* status not needed this time */
      Dem_FaultDetectionCounterType idleFDC; /* FDC not needed this time */

      /* if status mask matches */
      if (Dem_ApplyDTCFilter((Dem_EventIdType)EvId, &idleDTCStatus, &idleFDC)
             != FALSE)
      {
         /* new match found */
         ++(*NumberOfFilteredDTC);
      }
   }

   return E_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
