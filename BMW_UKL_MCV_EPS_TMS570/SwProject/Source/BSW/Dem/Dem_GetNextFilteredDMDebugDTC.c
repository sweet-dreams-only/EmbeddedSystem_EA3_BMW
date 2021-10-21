/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the vendor-specific Dem function
 ** Dem_GetNextFilteredDMDebugDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetNextFilteredDMDebugDTC.c 2061 2010-01-18 12:10:39Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by BMW Group
 ** All rights exclusively reserved for BMW Group,
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

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)
Dem_GetNextFilteredDMDebugDTC(
   Dem_DTCKindType                              DTCKind,
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA) DTC)
{
   Dem_ReturnGetNextFilteredDTCType result = DEM_FILTERED_NO_MATCHING_DTC;

   boolean filterresult = FALSE;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* check of Dem_InitializationState is not necessary:
    * only ROM data and according initialized filter-mask is accessed */

   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetNextFilteredDMDebugDTC, DEM_E_PARAM_DATA);
      return DEM_FILTERED_WRONG_DTCKIND;
   }
   if (DTC == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetNextFilteredDMDebugDTC, DEM_E_PARAM_ADDRESS);
      return DEM_FILTERED_NO_MATCHING_DTC;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* search for first DTC fulfilling the filter criterion */
   while (   (Dem_DMDebugFilter.NextEventId <= (DEM_NUMBER_OF_EVENTS - 1U))
          && (filterresult == FALSE))
   {
      if (Dem_DMDebugFilter.Filter == DEM_DMDEBUG_FILTER_ROEACTIVE)
      {
         filterresult =
            Dem_GbiRoeActive((Dem_EventIdType)Dem_DMDebugFilter.NextEventId);
      }
      else
      {
         filterresult = (boolean) (
            Dem_GbiDTCGroupIdx((Dem_EventIdType)Dem_DMDebugFilter.NextEventId)
               == DEM_DTCGRP_IDX_NETWORK_COM_DTCS );
      }

      /* skip events not matching the filter criterion */
      if (filterresult != FALSE)
      {
         if (DTCKind == Dem_GbiDTCKind((Dem_EventIdType)Dem_DMDebugFilter.NextEventId))
         {
            /* return DTC */
            *DTC = Dem_GbiDTC((Dem_EventIdType)Dem_DMDebugFilter.NextEventId);

            /* next matching DTC found */
            result = DEM_FILTERED_OK;
         }
         else
         {
            result = DEM_FILTERED_WRONG_DTCKIND;
         }
      }

      /* store event id for next call in filter */
      ++Dem_DMDebugFilter.NextEventId;
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
