/* --------{ BMW C Source File }-------- */
#ifndef EDCH_VERSION_H
#define EDCH_VERSION_H

/*==================[inclusions]==============================================*/

/*==================[macros]==================================================*/

/*------------------[AUTOSAR vendor identification]---------------------------*/

#if (defined EDCH_VENDOR_ID) /* to prevent double declaration */
#error EDCH_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: BMW Group */
#define EDCH_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]---------------------------*/

#if (defined EDCH_MODULE_ID) /* to prevent double declaration */
#error EDCH_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define EDCH_MODULE_ID         0U

/*------------------[AUTOSAR specification version identification]------------*/

#if (defined EDCH_AR_MAJOR_VERSION) /* to prevent double declaration */
#error EDCH_AR_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR specification major version */
#define EDCH_AR_MAJOR_VERSION  3U

#if (defined EDCH_AR_MINOR_VERSION) /* to prevent double declaration */
#error EDCH_AR_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR specification minor version */
#define EDCH_AR_MINOR_VERSION  1U

#if (defined EDCH_AR_PATCH_VERSION) /* to prevent double declaration */
#error EDCH_AR_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR specification patch version */
#define EDCH_AR_PATCH_VERSION  0U

/*------------------[AUTOSAR module version identification]-------------------*/

#if (defined EDCH_SW_MAJOR_VERSION) /* to prevent double declaration */
#error EDCH_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define EDCH_SW_MAJOR_VERSION  1U

#if (defined EDCH_SW_MINOR_VERSION) /* to prevent double declaration */
#error EDCH_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define EDCH_SW_MINOR_VERSION  4U

#if (defined EDCH_SW_PATCH_VERSION) /* to prevent double declaration */
#error EDCH_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define EDCH_SW_PATCH_VERSION  1U

/*==================[type definitions]========================================*/

/*==================[external function declarations]==========================*/

/*==================[internal function declarations]==========================*/

/*==================[external constants]======================================*/

/*==================[internal constants]======================================*/

/*==================[external data]===========================================*/

/*==================[internal data]===========================================*/

/*==================[external function definitions]===========================*/

/*==================[internal function definitions]===========================*/

#endif /* if !defined( EDCH_VERSION_H ) */
/*==================[end of file]=============================================*/
