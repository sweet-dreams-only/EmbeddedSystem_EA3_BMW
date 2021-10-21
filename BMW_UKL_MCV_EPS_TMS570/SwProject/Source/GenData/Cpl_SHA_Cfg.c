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
*  \copyright   BMW AG 2015
*
*  \version     3.1.0
*
*  \remarks     --
*
*/
/*----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      MISRA-Deviations
-------------------------------------------------------------------------------*/

/* MISRA-C:2004 Rule 19.1: including Auth_MemMap.h is necessary throughout the
   file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Cal.h"
#include "Cpl_Version.h"
#include "Cpl_Cfg.h"
#include "Cpl_SHA.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Cpl_CHECK_VERSION(3,0,2))
   #error "Version of Cpl_SHA_Cfg.c.tt does not match the version of the module!"
#endif

#if (CPL_SHA_ENABLED == STD_ON)



/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Cpl_START_SEC_CONST_UNSPECIFIED
#include "Cpl_MemMap.h"


/**
 * \brief SHA Configuration
 */
CONST(Cpl_SHAConfigType, Cpl_CONST) CplSHAConfig =
{
   CPL_SHA_256
};


/* PRQA S 5087 2 */
#define Cpl_STOP_SEC_CONST_UNSPECIFIED
#include "Cpl_MemMap.h"


#else /* #if (CPL_SHA_ENABLED == STD_ON) */

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/**
 * \brief Dummy type definition to prevent an empty translation unit in case no SHA Hash is
 *        configured.
 */
typedef void CplPrvntEmptyTranslationUnit_t;

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#endif /* #if (CPL_SHA_ENABLED == STD_ON) #else */

/*--- End of file ------------------------------------------------------------*/
