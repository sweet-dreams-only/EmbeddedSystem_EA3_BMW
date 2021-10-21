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



#ifndef CPL_COMMON_H
#define CPL_COMMON_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Cal.h"
#include "Cpl_Version.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Cpl_CHECK_VERSION(3,0,2))
   #error "Version of Cpl_Common.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/**
 * \brief Enumeration of the return type of the CPL module.
 */
typedef enum
{
   CPL_E_OK,
   CPL_E_NOT_OK,
   CPL_E_EQUAL,
   CPL_E_NOT_EQUAL,
   CPL_E_SMALLER,
   CPL_E_LARGER
}
Cpl_ReturnType;


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


extern FUNC(void, Cpl_CODE) Cpl_CommonCopy(
   P2VAR(void, AUTOMATIC, Cpl_APPL_DATA)   Destination,
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) Source,
   uint32                                  ByteLength);



extern FUNC(void, Cpl_CODE) Cpl_CommonXOR(
   P2VAR(void, AUTOMATIC, Cpl_APPL_DATA)   Destination,
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) Source,
   uint32                                  ByteLength);


extern FUNC(boolean, Cpl_CODE) Cpl_CommonCompare(
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) BlockA,
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) BlockB,
   uint32                                  ByteLength);


#define Cpl_STOP_SEC_CODE
#include <Cpl_MemMap.h>

#endif /* CPL_COMMON_H */

/*--- End of file ------------------------------------------------------------*/
