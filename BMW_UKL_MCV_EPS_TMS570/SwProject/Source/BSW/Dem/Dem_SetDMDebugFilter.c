/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the vendor-specific Dem function
 ** Dem_SetDTCFilter().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SetDMDebugFilter.c 2061 2010-01-18 12:10:39Z olho2924 $
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

FUNC(Std_ReturnType, DEM_CODE) Dem_SetDMDebugFilter(
   Dem_DebugFilterType Filter)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* check of Dem_InitializationState is not necessary:
    * according filter-mask is always accepted */

   if (   (Filter != DEM_DMDEBUG_FILTER_ROEACTIVE)
       && (Filter != DEM_DMDEBUG_FILTER_LOCKABLE)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_SetDMDebugFilter, DEM_E_PARAM_DATA);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* save filter information in internal data structure */
   Dem_DMDebugFilter.Filter      = Filter;

   /* reset next event Id to the first configured event Id */
   Dem_DMDebugFilter.NextEventId = 1U;

   return E_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
