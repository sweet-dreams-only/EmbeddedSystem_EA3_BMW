/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_GetIndexOfDTCGroup().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetIdxOfDTCGroup.c 2061 2010-01-18 12:10:39Z olho2924 $
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

FUNC(boolean, DEM_CODE) Dem_GetIdxOfDTCGroup(
   Dem_DTCGroupType                 DTCGroup,
   P2VAR(uint8, AUTOMATIC, DEM_VAR) Idx)
{
   for (*Idx = 0;
        (*Idx < DEM_NUM_DTC_GROUPS) && (DTCGroup != Dem_DTCGroups[*Idx]);
        ++*Idx)
   {
      /* empty search loop */
   }

   return (boolean) ((*Idx < DEM_NUM_DTC_GROUPS) ? TRUE : FALSE);
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
