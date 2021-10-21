/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetStatusOfDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetStatusOfDTC.c 2480 2011-03-21 16:00:06Z olho2924 $
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

FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_GetStatusOfDTC(
   Dem_DTCType                                            DTC,
   Dem_DTCKindType                                        DTCKind,
   Dem_DTCOriginType                                      DTCOrigin,
   P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA) DTCStatus)
{
   Dem_ReturnGetStatusOfDTCType result;
   Dem_EventIdType EvId;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetStatusOfDTC, DEM_E_UNINIT);
      return DEM_STATUS_FAILED;
   }
   if ((DTC == (Dem_DTCType)0UL) || (DTC > (Dem_DTCType)0xFFFFFFUL))
   {
      DEM_REPORT_ERROR(DEM_SID_GetStatusOfDTC, DEM_E_PARAM_DATA);
      return DEM_STATUS_WRONG_DTC;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetStatusOfDTC, DEM_E_PARAM_DATA);
      return DEM_STATUS_WRONG_DTCKIND;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY ) )
   {
      DEM_REPORT_ERROR(DEM_SID_GetStatusOfDTC, DEM_E_PARAM_DATA);
      return DEM_STATUS_WRONG_DTCORIGIN;
   }
   if (DTCStatus == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetStatusOfDTC, DEM_E_PARAM_ADDRESS);
      return DEM_STATUS_FAILED;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* search event Id by DTC and map return value */
   switch (Dem_GetEvIdByDTC(DTC, DTCKind, DTCOrigin, &EvId))
   {
      case DEM_EIBD_OK:
         result = DEM_STATUS_OK;
         break;
      case DEM_EIBD_WRONG_DTC:
         result = DEM_STATUS_WRONG_DTC;
         break;
      case DEM_EIBD_WRONG_DTCKIND:
         result = DEM_STATUS_WRONG_DTCKIND;
         break;
      case DEM_EIBD_WRONG_DTCORIGIN:
         result = DEM_STATUS_WRONG_DTCORIGIN;
         break;
      default: /* should never be reached */
         result = DEM_STATUS_WRONG_DTC;
         break;
   }

   if (result == DEM_STATUS_OK)
   {
      /* copy DTCStatusMask to return parameter */
      *DTCStatus = Dem_DTCStatusMasks[EvId]
         & DEM_DTC_STATUS_AVAILABILITY_MASK;
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
