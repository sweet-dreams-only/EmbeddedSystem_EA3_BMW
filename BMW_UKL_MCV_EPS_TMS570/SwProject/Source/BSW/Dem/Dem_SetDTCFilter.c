/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_SetDTCFilter().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SetDTCFilter.c 2061 2010-01-18 12:10:39Z olho2924 $
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

#include <Dem_Static.h>                    /* API and internal declarations */

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

FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE) Dem_SetDTCFilter(
   Dem_DTCStatusMaskType                  DTCStatusMask,
   Dem_DTCKindType                        DTCKind,
   Dem_DTCOriginType                      DTCOrigin,
   Dem_FilterWithSeverityType             FilterWithSeverity,
   Dem_DTCSeverityType                    DTCSeverity,
   Dem_FilterForFaultDetectionCounterType FilterForFaultDetectionCounter)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* check of Dem_InitializationState would be not necessary, but if this API
    * is called before full initialization, the system design is dubious
    * (and Dem_GetNextFilteredDTC[AndFDC]() is then not usable anyway) */
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_SetDTCFilter, DEM_E_UNINIT);
      return DEM_WRONG_FILTER;
   }

   /* DCM is responsible, that no status masks with unavailable bits are
    * requested (but this would not influence correctness of the filter) */
   /* no check with DEM_IS_UNMASKED_BIT_SET(DTCStatusMask, AVAILABILITY_MASK)
    * done, because all bits are supported */

   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_SetDTCFilter, DEM_E_PARAM_DATA);
      return DEM_WRONG_FILTER;
   }
   if (   (   (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
           && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (    DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY )
      )
   {
      DEM_REPORT_ERROR(DEM_SID_SetDTCFilter, DEM_E_PARAM_DATA);
      return DEM_WRONG_FILTER;
   }
   if (   (FilterWithSeverity != DEM_FILTER_WITH_SEVERITY_NO)
       && (FilterWithSeverity != DEM_FILTER_WITH_SEVERITY_YES)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_SetDTCFilter, DEM_E_PARAM_DATA);
      return DEM_WRONG_FILTER;
   }
   if (   (DTCSeverity != DEM_SEVERITY_NO_SEVERITY)
       && (DEM_IS_UNMASKED_BIT_SET(DTCSeverity,
                                   DEM_SEVERITY_MAINTENANCE_ONLY   |
                                   DEM_SEVERITY_CHECK_AT_NEXT_HALT |
                                   DEM_SEVERITY_CHECK_IMMEDIATELY  ) )
      )
   {
      DEM_REPORT_ERROR(DEM_SID_SetDTCFilter, DEM_E_PARAM_DATA);
      return DEM_WRONG_FILTER;
   }
   if (   (   FilterForFaultDetectionCounter
           != DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_YES
          )
       && (   FilterForFaultDetectionCounter
           != DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO
          )
      )
   {
      DEM_REPORT_ERROR(DEM_SID_SetDTCFilter, DEM_E_PARAM_DATA);
      return DEM_WRONG_FILTER;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* save filter information in internal data structure */
   Dem_DTCFilter.DTCStatusMask      = DTCStatusMask;
   Dem_DTCFilter.DTCKind            = DTCKind;
   Dem_DTCFilter.DTCOrigin          = DTCOrigin;
   Dem_DTCFilter.FilterWithSeverity = FilterWithSeverity;
   Dem_DTCFilter.DTCSeverity        = DTCSeverity;
   Dem_DTCFilter.FilterForFDC       = FilterForFaultDetectionCounter;

   /* reset next event Id to the first configured event Id */
   Dem_DTCFilter.NextEventId        = 1U;

   return DEM_FILTER_ACCEPTED;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
