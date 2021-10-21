/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetDTCByOccurrenceTime().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetDTCByOccurrenceTime.c 2160 2010-03-31 10:54:54Z olho2924 $
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

FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)
Dem_GetDTCByOccurrenceTime(
   Dem_DTCRequestType                           DTCRequest,
   Dem_DTCKindType                              DTCKind,
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA) DTC)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCByOccurrenceTime, DEM_E_UNINIT);
      return DEM_OCCURR_FAILED;
   }
   if (   (   (   (DTCRequest != DEM_FIRST_FAILED_DTC)
               && (DTCRequest != DEM_MOST_RECENT_FAILED_DTC) )
           && (    DTCRequest != DEM_FIRST_DET_CONFIRMED_DTC) )
       && (        DTCRequest != DEM_MOST_REC_DET_CONFIRMED_DTC ) )
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCByOccurrenceTime, DEM_E_PARAM_DATA);
      return DEM_OCCURR_FAILED;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCByOccurrenceTime, DEM_E_PARAM_DATA);
      return DEM_OCCURR_WRONG_DTCKIND;
   }
   if (DTC == NULL_PTR)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetDTCByOccurrenceTime, DEM_E_PARAM_ADDRESS);
      return DEM_OCCURR_FAILED;
   }
#else /* DEM_DEV_ERROR_DETECT */
   DEM_PARAM_UNUSED(DTCRequest);
   DEM_PARAM_UNUSED(DTCKind);
#endif /* DEM_DEV_ERROR_DETECT */

   /* Function NOT fully implemented yet.
    * Implementation is scheduled for future releases. */

   *DTC = 0U; /* invalid DTC */

   return DEM_OCCURR_FAILED;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
