/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the internal functions needed for
 ** monitor internal event debouncing.
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_DebounceMonitor.c 2160 2010-03-31 10:54:54Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Dem_Helper.h>                                /* Dem helper macros */
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

/*------------------[reset debounce status]---------------------------------*/

FUNC(void, DEM_CODE) Dem_ResetDebounceMonitor(Dem_EventIdType EventId)
{
   /* dummy function, do nothing */
   DEM_PARAM_UNUSED(EventId);
}

/*------------------[debounce an event entry]-------------------------------*/

/* Dem_DebounceEventMonitor() is never be used */

/*------------------[return FDC for an event]-------------------------------*/

/* Dem_RteGetFaultDetectionCounter() returns FDC for an event for "monitor
 * internal" debouncing */

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
