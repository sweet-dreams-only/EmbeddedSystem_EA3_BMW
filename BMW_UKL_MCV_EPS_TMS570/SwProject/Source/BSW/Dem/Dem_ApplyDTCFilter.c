/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_ApplyDTCFilter().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_ApplyDTCFilter.c 2480 2011-03-21 16:00:06Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise
 **
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

FUNC(boolean, DEM_CODE) Dem_ApplyDTCFilter(
   Dem_EventIdType                                                EventId,
   P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA)         DTCStatus,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC)
{
   boolean result = FALSE;

   /* access DTC status only once centrally to ensure consistent value for
    * that filter services, which return this value */
   *DTCStatus = Dem_DTCStatusMasks[EventId];

   /* apply all filter-criteria (DEM SWS 8.3.5.1.1) */

   /* filter for DTCStatusMask */
   if (   (Dem_DTCFilter.DTCStatusMask == 0U)
       || ((Dem_DTCFilter.DTCStatusMask & *DTCStatus) != 0U)
      )
   {
      Dem_DTCKindType aDTCKind = Dem_GbiDTCKind(EventId);

      /* filter for DTCKind */
      if (   (Dem_DTCFilter.DTCKind == DEM_DTC_KIND_ALL_DTCS)
          || (Dem_DTCFilter.DTCKind == aDTCKind)
         )
      {
         /* filter for DTCOrigin */
         if (Dem_DTCFilter.DTCOrigin == Dem_GbiDTCOrigin(EventId))
         {
            Dem_DTCSeverityType FilterSeverity = Dem_GbiDTCSeverity(EventId);

            /* filter for DTCSeverity as mask */
            if (   (Dem_DTCFilter.FilterWithSeverity == DEM_FILTER_WITH_SEVERITY_NO)
                || (   (Dem_DTCFilter.DTCSeverity == FilterSeverity) /* to handle DEM_SEVERITY_NO_SEVERITY */
                    || ( (Dem_DTCFilter.DTCSeverity & FilterSeverity) != 0U )
                   )
               )
            {
               /* filter for fault detection counter */
               if (Dem_DTCFilter.FilterForFDC == DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO)
               {
                  /* filter-criteria matched to event */
                  result = TRUE;
               }
               else
               {
                  Std_ReturnType ret;
#if (DEM_USE_DEBOUNCE == STD_ON)
                  ret = Dem_DebounceFctPtrTable[Dem_GbiDebounceAlgo(EventId)].
                           GetFDCFct(EventId, FDC);
#else
                  ret = Dem_RteGetFaultDetectionCounter(EventId, FDC);
#endif
                  /* fault detection counter filter criteria:
                   * FDC must between 1 and 0x7E (inclusive) - this means all
                   * DTCs where debouncing is in PREFAILED (but not yet FAILED)
                   * stage will be returned by the filter.
                   * (DEM SWS 8.3.5.1.1, ISO 14229-1:2006 Table 258) */

                  /* note that Dem_FaultDetectionCounterType is signed! */
                  if ( (ret == E_OK) && ( (1 <= *FDC) && (*FDC <= 126) ) )
                  {
                     /* filter-criteria matched to event */
                     result = TRUE;
                  }
               } /* FDC */
            } /* DTCSeverity */
         } /* DTCOrigin */
      } /* DTCKind */
   } /* DTCStatus */

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
