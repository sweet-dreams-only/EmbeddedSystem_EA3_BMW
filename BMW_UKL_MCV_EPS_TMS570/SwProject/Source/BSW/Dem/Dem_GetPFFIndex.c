/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_GetPFFIndex().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetPFFIndex.c 2547 2011-08-22 13:24:09Z olho2924 $
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
 */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)

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

FUNC(Dem_EventIdType, DEM_CODE) Dem_GetPFFIndex(Dem_EventIdType EventId)
{
   Dem_EventIdType Index = 0U;

#if (DEM_PFF_RUNTIME_OPTIMIZATION == STD_ON)

   /* get prestorage index direct from event description */
   Index = Dem_GbiPrestorageIndex(EventId);

   /* if index has value of 0 -> prestorage is disabled */
   if (Index != 0U)
   {
      /* prestorage index starts at 0 */
      --Index;
   }

#else

   Dem_EventIdType EvId;

   /* check if there are PFFs in front of the target PFF */
   for (EvId = 1U; EvId < EventId; ++EvId)
   {
      if (Dem_GbiEnablePrestorage(EvId) == TRUE)
      {
         ++Index;
      }
   }

#endif

   return Index;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

#endif /* DEM_MAX_NUMBER_PRESTORED_FF */

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
