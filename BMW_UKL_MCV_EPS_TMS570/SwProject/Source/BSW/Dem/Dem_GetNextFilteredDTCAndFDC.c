/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetNextFilteredDTCAndFDC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetNextFilteredDTCAndFDC.c 2061 2010-01-18 12:10:39Z olho2924 $
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

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTCAndFDC(
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA)
                                                 DTCFaultDetectionCounter)
{
   Dem_ReturnGetNextFilteredDTCType result = DEM_FILTERED_NO_MATCHING_DTC;

   boolean filterresult = FALSE;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetNextFilteredDTCAndFDC, DEM_E_UNINIT);
      return DEM_FILTERED_NO_MATCHING_DTC;
   }
   if ( (DTC == NULL_PTR) || (DTCFaultDetectionCounter == NULL_PTR) )
   {
      DEM_REPORT_ERROR(DEM_SID_GetNextFilteredDTCAndFDC, DEM_E_PARAM_ADDRESS);
      return DEM_FILTERED_NO_MATCHING_DTC;
   }
   if (Dem_DTCFilter.FilterForFDC == DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO)
   {
      /* function was called while FDC filtering is inactive (not sensible)
       * -> FDC information would not be retrieved and be returned bogus */
      DEM_REPORT_ERROR(DEM_SID_GetNextFilteredDTCAndFDC, DEM_E_PARAM_DATA);
      return DEM_FILTERED_NO_MATCHING_DTC;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* search for first DTC fulfilling the filter criterion */
   while (   (Dem_DTCFilter.NextEventId <= (DEM_NUMBER_OF_EVENTS - 1U))
          && (filterresult == FALSE)
         )
   {
      Dem_DTCStatusMaskType idleDTCStatus; /* status not needed this time */

      filterresult = Dem_ApplyDTCFilter(
         (Dem_EventIdType)Dem_DTCFilter.NextEventId,
         &idleDTCStatus,
         DTCFaultDetectionCounter);

      /* skip events not matching the filter criterion */
      if (filterresult == TRUE)
      {
         /* return DTC */
         *DTC = Dem_GbiDTC((Dem_EventIdType)Dem_DTCFilter.NextEventId);

         /* next matching DTC found */
         result = DEM_FILTERED_OK;
      }

      /* store event id for next call in filter */
      ++Dem_DTCFilter.NextEventId;
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
