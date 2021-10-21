#ifndef DEM_VERSION_H
/** \brief preprocessor exclusion definition */
#define DEM_VERSION_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the declaration of the version of the AUTOSAR module
 ** Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Version.h.m4 2490 2011-04-01 09:39:49Z olho2924 $
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

/*==================[macros]================================================*/

/*------------------[AUTOSAR specification version identification]----------*/

#if (defined DEM_AR_MAJOR_VERSION) /* to prevent double declaration */
#error DEM_AR_MAJOR_VERSION already defined
#endif /* if (defined DEM_AR_MAJOR_VERSION) */

/** \brief AUTOSAR specification major version */
#define DEM_AR_MAJOR_VERSION  2U

#if (defined DEM_AR_MINOR_VERSION) /* to prevent double declaration */
#error DEM_AR_MINOR_VERSION already defined
#endif /* if (defined DEM_AR_MINOR_VERSION) */

/** \brief AUTOSAR specification minor version */
#define DEM_AR_MINOR_VERSION  1U

#if (defined DEM_AR_PATCH_VERSION) /* to prevent double declaration */
#error DEM_AR_PATCH_VERSION already defined
#endif /* if (defined DEM_AR_PATCH_VERSION) */

/** \brief AUTOSAR specification patch version */
#define DEM_AR_PATCH_VERSION  1U

/*------------------[AUTOSAR module version identification]-----------------*/

#if (defined DEM_SW_MAJOR_VERSION) /* to prevent double declaration */
#error DEM_SW_MAJOR_VERSION already defined
#endif /* if (defined DEM_SW_MAJOR_VERSION) */

/** \brief AUTOSAR module major version */
#define DEM_SW_MAJOR_VERSION  3U

#if (defined DEM_SW_MINOR_VERSION) /* to prevent double declaration */
#error DEM_SW_MINOR_VERSION already defined
#endif /* if (defined DEM_SW_MINOR_VERSION) */

/** \brief AUTOSAR module minor version */
#define DEM_SW_MINOR_VERSION  3U

#if (defined DEM_SW_PATCH_VERSION) /* to prevent double declaration */
#error DEM_SW_PATCH_VERSION already defined
#endif /* if (defined DEM_SW_PATCH_VERSION) */

/** \brief AUTOSAR module patch version */
#define DEM_SW_PATCH_VERSION  3U

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
#endif /* ifndef DEM_VERSION_H */
/*==================[end of file]============================================*/
