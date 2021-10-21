/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetDTCStatusAvailabilityMask().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetDTCStatusAvailabilityMask.c 2061 2010-01-18 12:10:39Z olho2924 $
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

FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCStatusAvailabilityMask(
   P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* check of Dem_InitializationState is not necessary:
    * it's allowed to get availability mask even if DEM is uninitialized */
   if (DTCStatusMask == NULL_PTR)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetDTCStatusAvailabilityMask, DEM_E_PARAM_ADDRESS);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   *DTCStatusMask = DEM_DTC_STATUS_AVAILABILITY_MASK;

   return E_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
