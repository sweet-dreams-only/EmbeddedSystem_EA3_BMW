/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetSeverityOfDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetSeverityOfDTC.c 2480 2011-03-21 16:00:06Z olho2924 $
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

#if (defined DEM_SET_STATUSGETSEVERITY)
#error DEM_SET_STATUSGETSEVERITY already defined
#endif
/** \brief Macro to set StatusGetSeverity but only if the pointer is valid */
#define DEM_SET_STATUSGETSEVERITY(status) \
   do                                     \
   {                                      \
      if (StatusGetSeverity != NULL_PTR)  \
      {                                   \
         *StatusGetSeverity = (status);   \
      }                                   \
   }                                      \
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

FUNC(Std_ReturnType, DEM_CODE) Dem_GetSeverityOfDTC(
   Dem_DTCType                                          DTC,
   Dem_DTCOriginType                                    DTCOrigin,
   P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
   P2VAR(Dem_ReturnGetSeverityOfDTCType, AUTOMATIC, DEM_APPL_DATA)
                                                        StatusGetSeverity)
{
   Dem_EventIdType EvId;
   Std_ReturnType result = E_NOT_OK;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* check of Dem_InitializationState is not necessary:
    * it's allowed to get severity even if DEM is uninitialized */

   if ((DTC == (Dem_DTCType)0UL) || (DTC > (Dem_DTCType)0xFFFFFFUL))
   {
      DEM_REPORT_ERROR(DEM_SID_GetSeverityOfDTC, DEM_E_PARAM_DATA);
      DEM_SET_STATUSGETSEVERITY(DEM_GET_SEVERITYOFDTC_WRONG_DTC);
      return E_NOT_OK;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY ) )
   {
      DEM_REPORT_ERROR(DEM_SID_GetSeverityOfDTC, DEM_E_PARAM_DATA);
      DEM_SET_STATUSGETSEVERITY(DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN);
      return E_NOT_OK;
   }
   if ((DTCSeverity == NULL_PTR) || (StatusGetSeverity == NULL_PTR))
   {
      DEM_REPORT_ERROR(DEM_SID_GetSeverityOfDTC, DEM_E_PARAM_ADDRESS);
      DEM_SET_STATUSGETSEVERITY(DEM_GET_SEVERITYOFDTC_NOSEVERITY);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* search event Id by DTC and map return value */
   switch (Dem_GetEvIdByDTC(DTC, DEM_DTC_KIND_ALL_DTCS, DTCOrigin, &EvId))
   {
      case DEM_EIBD_OK:
         /* get the severity mapped to event Id */
         *DTCSeverity = Dem_GbiDTCSeverity(EvId);

         result = E_OK;

         *StatusGetSeverity = DEM_GET_SEVERITYOFDTC_OK;
         break;
      case DEM_EIBD_WRONG_DTC:
         *StatusGetSeverity = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
         break;
      /* case DEM_EIBD_WRONG_DTCKIND is not handled */
      case DEM_EIBD_WRONG_DTCORIGIN:
         *StatusGetSeverity = DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN;
         break;
      default: /* should never be reached */
         *StatusGetSeverity = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
         break;
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
