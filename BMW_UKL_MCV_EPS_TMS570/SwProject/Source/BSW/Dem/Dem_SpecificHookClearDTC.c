/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the vendor-specific Dem function
 ** Dem_SpecificHookClearDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SpecificHookClearDTC.c 2391 2010-10-27 12:00:10Z olho2924 $
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

FUNC(void, DEM_CODE) Dem_SpecificHookClearDTC(
   Dem_DTCType        DTC,
   Dem_DTCOriginType  DTCOrigin)
{
   uint8 originIdx = (uint8)(DTCOrigin - DEM_DTC_ORIGIN_PRIMARY_MEMORY);

   /* BMWDem043: If the DTC is the group DEM_DTC_GROUP_ALL_DTCS then the
    * ConditionByte for the DTCOrigin shall be reset after the sequence "Clear
    * single DTC" was called for all DTCs with origin equal to DTCOrigin.
    */
   if ((Dem_DTCGroupType) DTC == DEM_DTC_GROUP_ALL_DTCS)
   {
      DEM_CLEAR_EV_MEM_OVERFLOW(originIdx);
   }

   while (Dem_LockWhileImmediateStorage[originIdx] != FALSE)
   {
      /* lock return until last entry was cleared immediately */
   }
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
