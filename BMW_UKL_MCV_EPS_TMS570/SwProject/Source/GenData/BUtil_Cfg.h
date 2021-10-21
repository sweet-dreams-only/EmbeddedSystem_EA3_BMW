/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Configuration header file of module BUtil.
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
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : artt 2.1.2.0
*
*  GENERATION TIME : 22.09.2016 13:18:44
*
------------------------------------------------------------------------------*/

#ifndef BUTIL_CFG_H
#define BUTIL_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil_Version.h"             /* Own version header file                */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(3,0,1))
   #error "Version of BUtil_Cfg.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                        Configuration Section
------------------------------------------------------------------------------*/


/** Minimum feature set for Blu */
#define BUTIL_FS_BLU         0x10
/** Reduced feature set for Bootmanager */
#define BUTIL_FS_BOOTMANAGER 0x20
/** Full feature set */
#define BUTIL_FS_FULL        0x30

/**
 * This parameter selects, which feature set shall be activated.
 */
#define BUTIL_FEATURESET BUTIL_FS_FULL

#endif /* BUTIL_CFG_H */


/*** End of file **************************************************************/
