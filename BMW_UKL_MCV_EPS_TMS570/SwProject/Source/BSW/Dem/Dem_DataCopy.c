/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_DataCopy().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_DataCopy.c 2061 2010-01-18 12:10:39Z olho2924 $
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

FUNC(void, DEM_CODE) Dem_DataCopy(
   P2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) EntryData,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                DestBuffer,
   Dem_SizeEntryDataType                                 Number)
{
   while (Number > 0U)
   {
      --Number;

      /* copy entry data into application buffer backwards */
      DestBuffer[Number] = (uint8)EntryData[Number];
   }
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
