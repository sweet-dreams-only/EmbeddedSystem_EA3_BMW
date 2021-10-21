/**
 * \file
 *
 * \brief Autosar IPduMplex
 *
 * This file contains the implementation of the Autosar
 * module IPduMplex.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2010 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef IPDUM_VERSION_H
#define IPDUM_VERSION_H

/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

/*------------------[AUTOSAR specification version identification]----------*/

#if (defined IPDUM_AR_MAJOR_VERSION) /* to prevent double declaration */
#error IPDUM_AR_MAJOR_VERSION already defined
#endif /* if (defined IPDUM_AR_MAJOR_VERSION) */

/** \brief AUTOSAR specification major version */
#define IPDUM_AR_MAJOR_VERSION  1U

#if (defined IPDUM_AR_MINOR_VERSION) /* to prevent double declaration */
#error IPDUM_AR_MINOR_VERSION already defined
#endif /* if (defined IPDUM_AR_MINOR_VERSION) */

/** \brief AUTOSAR specification minor version */
#define IPDUM_AR_MINOR_VERSION  2U

#if (defined IPDUM_AR_PATCH_VERSION) /* to prevent double declaration */
#error IPDUM_AR_PATCH_VERSION already defined
#endif /* if (defined IPDUM_AR_PATCH_VERSION) */

/** \brief AUTOSAR specification patch version */
#define IPDUM_AR_PATCH_VERSION  2U

/*------------------[AUTOSAR module version identification]-----------------*/

#if (defined IPDUM_SW_MAJOR_VERSION) /* to prevent double declaration */
#error IPDUM_SW_MAJOR_VERSION already defined
#endif /* if (defined IPDUM_SW_MAJOR_VERSION) */

/** \brief AUTOSAR module major version */
#define IPDUM_SW_MAJOR_VERSION  2U

#if (defined IPDUM_SW_MINOR_VERSION) /* to prevent double declaration */
#error IPDUM_SW_MINOR_VERSION already defined
#endif /* if (defined IPDUM_SW_MINOR_VERSION) */

/** \brief AUTOSAR module minor version */
#define IPDUM_SW_MINOR_VERSION  2U

#if (defined IPDUM_SW_PATCH_VERSION) /* to prevent double declaration */
#error IPDUM_SW_PATCH_VERSION already defined
#endif /* if (defined IPDUM_SW_PATCH_VERSION) */

/** \brief AUTOSAR module patch version */
#define IPDUM_SW_PATCH_VERSION  3U

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined IPDUM_VENDOR_ID) /* to prevent double declaration */
#error IPDUM_VENDOR_ID is already defined
#endif /* if (defined IPDUM_VENDOR_ID) */

/** \brief AUTOSAR vendor identification */
#define IPDUM_VENDOR_ID IPDUM_VENDOR_ID_3SOFT

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_VERSION_H */
/*==================[end of file]===========================================*/
