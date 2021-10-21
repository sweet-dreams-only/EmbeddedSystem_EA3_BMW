/*----------------------------------------------------------------------------*/
/**
*  \file
*  \ingroup API
*
*  \brief       Static assertions
*
*  This file contains macros to emulate the static_assert macro of the C11 standard,
*  which is not yet supported by all compilers.
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
*  \remarks     --
*
*/
/*----------------------------------------------------------------------------*/

#ifndef BUTIL_ASSERT_H_
#define BUTIL_ASSERT_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil_Cfg.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(3,0,1))
   #error "Version of BUtil_Assert.h does not match the version of the module!"
#endif

/**
 * This macro is used to emulate the static_assert macro of the C11 standard,
 * which is not yet supported by all compilers.
 */
#define BUTIL_STATIC_ASSERT(cond, msg) BUTIL_STATIC_ASSERT_1(cond, __LINE__)

/**
 * \name Helper macros for BUTIL_STATIC_ASSERT
 */
/**\{*/
#define BUTIL_STATIC_ASSERT_1(cond, line) BUTIL_STATIC_ASSERT_2(cond, line)
#define BUTIL_STATIC_ASSERT_2(cond, line) BUTIL_STATIC_ASSERT_3(cond, static_assertion_at_line##line)
#define BUTIL_STATIC_ASSERT_3(cond, id) typedef char id[((!!(cond))*2-1)]
/**\}*/

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#endif /* BUTIL_ASSERT_H_ */

/*--- End of file ------------------------------------------------------------*/
