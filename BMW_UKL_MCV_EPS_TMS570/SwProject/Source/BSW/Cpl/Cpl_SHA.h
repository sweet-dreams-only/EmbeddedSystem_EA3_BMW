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


/* !LINKSTO CPL005, 1
 */

#ifndef CPL_SHA_H
#define CPL_SHA_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Cal.h"
#include "Cpl_Cfg.h"
#include "Cpl_Version.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Cpl_CHECK_VERSION(3,0,2))
   #error "Version of Cpl_SHA.h does not match the version of the module!"
#endif

#if (CPL_SHA_ENABLED == STD_ON)

/**
 * \brief The length of a message digest computed with the SHA-1 algorithm in bytes.
 *
 */
#define CPL_SHA1_HASH_LEN_BYTES 20U

/**
 * \brief The length of a message digest computed with the SHA-256 algorithm in bytes.
 */
#define CPL_SHA256_HASH_LEN_BYTES 32U

/**
 * \brief The X.509 algorithm identifier of the SHA-1 hash algorithm.
 */
#define CPL_SHA_1_ALGORITHM_ID 0x30U,0x09U,0x06U,0x05U,0x2bU,0x0eU,0x03U,0x02U,0x1aU,0x05U,0x00U



/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Cpl_START_SEC_CODE
#include <Cpl_MemMap.h>


extern FUNC(Cal_ReturnType, Cpl_CODE) Cpl_SHAStart(
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) CfgPtr,
   Cal_HashCtxBufType                      Ctx);

extern FUNC(Cal_ReturnType, Cpl_CODE) Cpl_SHAUpdate(
   P2CONST(void,  AUTOMATIC, Cpl_APPL_DATA) CfgPtr,
   Cal_HashCtxBufType                       Ctx,
   P2CONST(uint8, AUTOMATIC, Cpl_APPL_DATA) dataPtr,
   uint32                                   dataLength);

extern FUNC(Cal_ReturnType, Cpl_CODE) Cpl_SHAFinish(
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) CfgPtr,
   Cal_HashCtxBufType                      Ctx,
   P2VAR(uint8, AUTOMATIC,  Cpl_APPL_DATA) resultPtr,
   P2VAR(uint32, AUTOMATIC, Cpl_APPL_DATA) resultLengthPtr,
   boolean                                 truncationAllowed);


#define Cpl_STOP_SEC_CODE
#include <Cpl_MemMap.h>

#endif /* #if (CPL_SHA_ENABLED == STD_ON) */

#endif /* CPL_SHA_H */

/*--- End of file ------------------------------------------------------------*/
