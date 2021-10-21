/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_SizeOfED().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SizeOfED.c 2061 2010-01-18 12:10:39Z olho2924 $
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

#if (DEM_USE_GLOBAL_EDCLASS == STD_OFF)

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

FUNC(Dem_SizeEntryDataType, DEM_CODE) Dem_SizeOfED(
   CONSTP2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST) EDClass)
{
   Dem_SizeEntryDataType result = 0U;
   Dem_EDSegIdxType index;

   /* add all data sizes of the ED class */
   for (index = 0U; index < EDClass->NumEDSegs; ++index)
   {
      result += (Dem_SizeEntryDataType)EDClass->Size[index];
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

#endif /* DEM_USE_GLOBAL_EDCLASS */

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
