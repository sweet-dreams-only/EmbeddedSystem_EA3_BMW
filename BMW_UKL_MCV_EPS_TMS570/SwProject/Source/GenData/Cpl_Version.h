/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Cpl
*
*  This file contains the implementation of the BMW SWC Cpl
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW Group 2015
*
*  \version     3.0.2
*
*  \remarks     --
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : artt 2.0.2.0
*
*  GENERATION TIME : 23.09.2016 10:57:18
*
------------------------------------------------------------------------------*/

#ifndef CPL_VERSION_H
#define CPL_VERSION_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief Cpl header major version
 */
#define Cpl_MAJOR_VERSION        (3u)

/**
 * \brief Cpl header minor version
 */
#define Cpl_MINOR_VERSION        (0u)

/**
 * \brief Cpl header patch version
 */
#define Cpl_PATCH_VERSION        (2u)


/* MISRA-C:2004 Rule 19.7: Macro used for precompile version check */
/* PRQA S 3453 2 */
#define Cpl_CHECK_VERSION(major,minor,patch) \
 (((major) == Cpl_MAJOR_VERSION) && ((minor) == Cpl_MINOR_VERSION) && ((patch) == Cpl_PATCH_VERSION))

#endif /* CPL_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
