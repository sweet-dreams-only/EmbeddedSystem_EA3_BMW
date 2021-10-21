/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BUtil Version Information
*
*  This file is a generated version header file
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW Group 2015
*
*  \version     3.0.1
*
*  \remarks     ---
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : artt 2.1.2.0
*
*  GENERATION TIME : 22.09.2016 13:18:45
*
------------------------------------------------------------------------------*/

#ifndef BUTIL_VERSION_H
#define BUTIL_VERSION_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief BUtil header major version
 */
#define BUtil_MAJOR_VERSION        (3u)

/**
 * \brief BUtil header minor version
 */
#define BUtil_MINOR_VERSION        (0u)

/**
 * \brief BUtil header patch version
 */
#define BUtil_PATCH_VERSION        (1u)


/* PRQA S 3453 2 */ /* Macro used for precompile version check */
#define BUtil_CHECK_VERSION(major,minor,patch) \
 (((major) == BUtil_MAJOR_VERSION) && ((minor) == BUtil_MINOR_VERSION) && ((patch) == BUtil_PATCH_VERSION))


#endif /* BUTIL_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
