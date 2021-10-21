/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetViewIDOfDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetViewIDOfDTC.c 2566 2011-09-13 11:45:28Z olho2924 $
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

#include <Dem_Helper.h>                                /* Dem helper macros */
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

FUNC(Dem_ReturnGetViewIDOfDTCType, DEM_CODE) Dem_GetViewIDOfDTC(
   Dem_DTCType                                     DTC,
   Dem_DTCKindType                                 DTCKind,
   P2VAR(Dem_ViewIdType, AUTOMATIC, DEM_APPL_DATA) ViewId)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetViewIDOfDTC, DEM_E_UNINIT);
      return DEM_VIEWID_WRONG_DTC;
   }
   if ((DTC == (Dem_DTCType)0UL) || (DTC > (Dem_DTCType)0xFFFFFFUL))
   {
      DEM_REPORT_ERROR(DEM_SID_GetViewIDOfDTC, DEM_E_PARAM_DATA);
      return DEM_VIEWID_WRONG_DTC;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetViewIDOfDTC, DEM_E_PARAM_DATA);
      return DEM_VIEWID_WRONG_DTCKIND;
   }
   if (ViewId == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetViewIDOfDTC, DEM_E_PARAM_ADDRESS);
      return DEM_VIEWID_WRONG_DTC;
   }
#else /* DEM_DEV_ERROR_DETECT */
   DEM_PARAM_UNUSED(DTC);
   DEM_PARAM_UNUSED(DTCKind);
#endif /* DEM_DEV_ERROR_DETECT */

   /* Function NOT fully implemented yet.
    * Implementation is scheduled for future releases. */

   /* due to CR71134 a positive return value and a hard coded view id with
    * value 0 will be returned */
   *ViewId = 0U;

   return DEM_VIEWID_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
