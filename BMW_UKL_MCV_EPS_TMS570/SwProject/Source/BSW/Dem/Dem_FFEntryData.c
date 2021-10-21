/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_FFEntryData().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_FFEntryData.c 2480 2011-03-21 16:00:06Z olho2924 $
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

FUNC(Dem_EntryDataPtrType, DEM_CODE) Dem_FFEntryData(
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
      EvMemEntry,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass,
   const Dem_FFIdxType                                 FFIndex)
{
#if (DEM_USE_GLOBAL_EDCLASS == STD_OFF)
   /* get extended data class layout */
   CONSTP2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST) EDClass =
      Dem_EDClasses[Dem_GbiEDClassIdx(EvMemEntry->EventId)];
   Dem_SizeEntryDataType EDClassSize = Dem_SizeOfED(EDClass);
#else
   /* substract CONDITION_BYTE and OCCURRENCE_COUNTER */
   Dem_SizeEntryDataType EDClassSize = (DEM_MAXSIZE_EDCLS - 2U);
#endif

   /* calculate start position of the needed FF */
   const Dem_SizeEntryDataType StartPos = EvMemEntry->EntryDataPos +
      EDClassSize + (Dem_SizeOfFF(FFClass) * FFIndex);

   const uint8 originIdx
      = (uint8)(Dem_GbiDTCOrigin(EvMemEntry->EventId) -
                DEM_DTC_ORIGIN_PRIMARY_MEMORY);

   return &Dem_EntryData[originIdx][StartPos];
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
