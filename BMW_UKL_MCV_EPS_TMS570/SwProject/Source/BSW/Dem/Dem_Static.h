#ifndef DEM_STATIC_H
/** \brief preprocessor exclusion definition */
#define DEM_STATIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file includes all relevant files for providing internal and external
 ** static API declarations and type definitions.
 **
 ** \project AUTOSAR Standard Core
 ** \author Stephanie Muehlenmeister
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Static.h 2480 2011-03-21 16:00:06Z olho2924 $
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

/* 1. The following include has to be done before including header-file(s)
 *    depending on the provided RTE type definitions */
#include <Dem_RteInternal_Static_Specific.h>     /* API, Dem <-> SWC I-face */

/* 2. The following includes depend on RTE type definitions included before */
#include <Dem_RteApi_Static_Specific.h>     /* API, Dem <-> SWC, BSW I-face */
#include <Dem_Internal_Static_Specific.h>  /* API and internal static decl. */


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
#endif /* ifndef DEM_STATIC_H */
/*==================[end of file]===========================================*/
