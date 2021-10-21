/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all definitions of the configuration of the
 ** AUTOSAR module Dem that are target independent, which is variant specific.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Static_Specific.c 2374 2010-10-04 08:47:58Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by Elektrobit Automotive GmbH and BMW Group
 ** All rights exclusively reserved for Elektrobit Automotive GmbH and
 ** BMW Group, unless expressly agreed to otherwise */

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

#define DEM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* Status of DM Debug-filter */
VAR(Dem_DMDebugFilterType, DEM_VAR) Dem_DMDebugFilter =
{
   DEM_DMDEBUG_FILTER_ROEACTIVE, /* filter */
   1U                            /* index of event to read next */
};

#define DEM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Boolean flag, indicating that Dem_Shutdown() runs */
VAR(boolean, DEM_VAR_NOINIT) Dem_ShutdownActive;
/* Boolean flag, indicating shutdown-cancellation */
VAR(boolean, DEM_VAR_NOINIT) Dem_ShutdownCancellation;
/* Boolean flag, indicating that "immediate storage" is in progress */
volatile VAR(boolean, DEM_VAR_NOINIT)
   Dem_LockWhileImmediateStorage[DEM_MAXNUM_ORIGINS];

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[internal core-function definitions]--------------------*/

FUNC(uint32, DEM_CODE) Dem_GetTimeFromFFData(
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FFData)
{
   /* required freeze frame data layout:
    *
    * | data[0] | data[1] | data[2] | data[3] | data[4] | data[5] | data[6]
    * +---------+---------+---------+---------+---------+---------+---------
    * |   -     |   -     |   -     | time    | time    | time    | time
    * |         |         |         | (MSB)   |         |         | (LSB)
    * +---------+---------+---------+---------+---------+---------+---------
    */
   return (uint32) (   ((uint32)FFData[3] << 24) + ((uint32)FFData[4] << 16)
                     + ((uint32)FFData[5] <<  8) +  (uint32)FFData[6]);
}

/*------------------[API core-function definitions]-------------------------*/

FUNC(void, DEM_CODE) Dem_CancelShutdown(void)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState == DEM_UNINITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_CancelShutdown, DEM_E_UNINIT);
      return;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* initiate shutdown-cancellation */
   Dem_ShutdownCancellation = TRUE;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*============================[end of file]=================================*/
