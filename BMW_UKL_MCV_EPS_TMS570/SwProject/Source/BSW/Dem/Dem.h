#ifndef DEM_H
/** \brief preprocessor exclusion definition */
#define DEM_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains or includes all external identifiers of
 ** the AUTOSAR module Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem.h 2480 2011-03-21 16:00:06Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2008 by Elektrobit Automotive GmbH
 ** All rights exclusively reserved for Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

/* 1. The following include has to be done before including header-file(s)
 *    depending on the provided RTE type definitions */
#include <Dem_Api_Depend_Specific.h>  /* Module public API, config. depend. */

/* 2. The following include depends on RTE type definitions included before */
#include <Dem_RteApi_Static_Specific.h> /* publ API, Dem <-> SWC,BSW I-face */
#include <Dem_RteApi_Depend_Specific.h> /* publ API, Dem <-> SWC,BSW I-face */


/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_H */
/*==================[end of file]===========================================*/
