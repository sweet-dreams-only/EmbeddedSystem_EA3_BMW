/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetIndicatorStatus().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetIndicatorStatus.c 2061 2010-01-18 12:10:39Z olho2924 $
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

#if (DEM_USE_INDICATOR == STD_ON)

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

FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus(
  Dem_IndicatorIdType                                      IndicatorId,
  P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus)
{
   const Dem_IndicatorDescType IndicatorDesc = Dem_IndicatorDesc[IndicatorId];
   CONSTP2CONST(Dem_IndicatorLinkType, AUTOMATIC, DEM_CONST) IndicatorLink =
      &Dem_IndicatorLink[IndicatorDesc.StartIdx];

   Dem_EventIdType LinkIdx; /* there are maximal as much links as events */

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetIndicatorStatus, DEM_E_UNINIT);
      return E_NOT_OK;
   }
   if (IndicatorId > DEM_NUMBER_OF_INDICATORS)
   {
      DEM_REPORT_ERROR(DEM_SID_GetIndicatorStatus, DEM_E_PARAM_DATA);
      return E_NOT_OK;
   }
   if (IndicatorStatus == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetIndicatorStatus, DEM_E_PARAM_ADDRESS);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* indicator status is calculated re-entrant, as the WIR bits are evaluated
    * atomically (and further accesses are only done on constant values) */

   *IndicatorStatus = DEM_INDICATOR_OFF;

   for (LinkIdx = 0U; LinkIdx < IndicatorDesc.Number; ++LinkIdx)
   {
      if (DEM_IS_EV_ST_BIT_SET(
             IndicatorLink[LinkIdx].EventId, DEM_DTCSTATUSBIT_WIR))
      {
         if (*IndicatorStatus == DEM_INDICATOR_OFF)
         {
            /* set initial behaviour */
            *IndicatorStatus = IndicatorLink[LinkIdx].Behaviour;
         }
         else
         {
            if (*IndicatorStatus != IndicatorLink[LinkIdx].Behaviour)
            {
               /* as different behaviours are requested, SW-C is responsible
                * for behaviour selection */
               *IndicatorStatus = DEM_INDICATOR_BLINK_CONT;
            }
         }
      }
      /* else: no linked event request their warning indicator
       *       -> status remains DEM_INDICATOR_OFF */
   }

   return E_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

#endif /* DEM_USE_INDICATOR */

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
