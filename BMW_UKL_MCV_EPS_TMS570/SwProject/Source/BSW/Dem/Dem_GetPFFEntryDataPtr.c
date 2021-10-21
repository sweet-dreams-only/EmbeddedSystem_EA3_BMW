/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_GetPFFEntryDataPtr().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetPFFEntryDataPtr.c 2547 2011-08-22 13:24:09Z olho2924 $
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

#include <Dem_Internal_Depend_Specific.h> /* API and internal declarations,
                                           * dependent and static part */

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

FUNC(Dem_EntryDataPtrType, DEM_CODE)
   Dem_GetPFFEntryDataPtr(Dem_EventIdType EventId)
{
   Dem_SizeEntryDataType StartPos = 0U;

#if (DEM_PFF_RUNTIME_OPTIMIZATION == STD_ON)

   if (Dem_GbiEnablePrestorage(EventId) == TRUE)
   {
      StartPos = Dem_PFFEntryDataStartPos[Dem_GbiPrestorageIndex(EventId)];
   }

#else

   Dem_EventIdType EvId;

   /* check if there are PFFs in front of the target PFF */
   for (EvId = 1U; EvId < EventId; ++EvId)
   {
      if (Dem_GbiEnablePrestorage(EvId) == TRUE)
      {
         /* get freeze frame class layout */
         CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass =
            Dem_FFClasses[Dem_GbiFFClassIdx(EvId)];

         StartPos += FFClass->StartByte[FFClass->NumFFSegs - 1U];
         StartPos += FFClass->Size[FFClass->NumFFSegs - 1U];
      }
   }

#endif

   return &Dem_PFFEntryData[StartPos];
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

#endif /* DEM_MAX_NUMBER_PRESTORED_FF */

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
