/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_SizeOfEntryData().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SizeOfEntryData.c 2450 2011-02-23 18:22:47Z olho2924 $
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

#include <Dem_Internal_Depend_Specific.h> /* API and internal declarations,
                                           * dependent and static part */

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

FUNC(Dem_SizeEntryDataType, DEM_CODE) Dem_SizeOfEntryData(
   const Dem_EventIdType EventId)
{
#if (DEM_USE_GLOBAL_EDCLASS == STD_OFF)
   /* get extended data class layout */
   CONSTP2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST) EDClass =
      Dem_EDClasses[Dem_GbiEDClassIdx(EventId)];
   Dem_SizeEntryDataType EDClassSize = Dem_SizeOfED(EDClass);
#else
   /* substract CONDITION_BYTE and OCCURRENCE_COUNTER */
   Dem_SizeEntryDataType EDClassSize = (DEM_MAXSIZE_EDCLS - 2U);
#endif

   /* get freeze frame class layout */
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass =
      Dem_FFClasses[Dem_GbiFFClassIdx(EventId)];

#if ((defined DEM_GLOBAL_FFCLASSIDX_VALUE) && \
     (defined DEM_GLOBAL_MAXNUMFF_VALUE) &&   \
     (defined DEM_GLOBAL_EDCLASSIDX_VALUE))
   DEM_PARAM_UNUSED(EventId);
#endif

   return (Dem_SizeEntryDataType)( EDClassSize +
            (Dem_SizeOfFF(FFClass) * Dem_GbiMaxNumFF(EventId)) );
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
