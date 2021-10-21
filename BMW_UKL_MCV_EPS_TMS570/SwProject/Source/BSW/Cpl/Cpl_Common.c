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
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* MISRA-C:2004 Rule 17.4: Pointers are needed instead of array types to be able
   to use the Autosar compiler abstraction, see PRQA: 0492 */

/* MISRA-C:2004 Rule 19.1: including Auth_MemMap.h is necessary throughout the
   file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include <Std_Types.h>

#include <Cpl_Common.h>
#include <Cpl_Version.h>


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Cpl_CHECK_VERSION(3,0,2))
   #error "Version of Cpl_Common.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

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

/* PRQA S 5087 2 */
#define Cpl_START_SEC_CODE
#include "Cpl_MemMap.h"

/*----------------------------------------------------------------------------*/
/**
 * \brief  This function copies a block of data to a different location.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[out]  Destination   A pointer to the memory area which should hold the copy of the data.
 * \param[in]   Source        A pointer to the block of data which should be copied.
 * \param[in]   ByteLength    Holds the amount of bytes which should be copied.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

FUNC(void, Cpl_CODE) Cpl_CommonCopy(
   P2VAR(void, AUTOMATIC, Cpl_APPL_DATA)   Destination,
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) Source,
   uint32                                  ByteLength)
{
   uint32_least len; /* internal length value */


   /* loop over the block length */
   for(len = (uint32_least)0; len < ByteLength;  ++len)
   {
      /* copy byte-wise */
      /* PRQA S 0492 2 */
      ((P2VAR(uint8, AUTOMATIC, Cpl_APPL_DATA))Destination)[len] =
                        ((P2CONST(uint8, AUTOMATIC, Cpl_APPL_DATA))Source)[len];
   }
} /* end of function Cpl_CommonCopy */


/*----------------------------------------------------------------------------*/
/**
 * \brief  This function XOR a block of data to a another block of data.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in,out]  Destination   A pointer to the memory area which should hold the XOR-ed data.
 * \param[in]      Source        A pointer to the block of data which should be XOR-ed to the
 *                                 destination.
 * \param[in]      ByteLength    Holds the amount of bytes which should be XOR-ed.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

FUNC(void, Cpl_CODE) Cpl_CommonXOR(
   P2VAR(void, AUTOMATIC, Cpl_APPL_DATA)   Destination,
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) Source,
   uint32                                  ByteLength)
{
   uint32_least len; /* internal length value */


   /* loop over the block length */
   for(len = (uint32_least)0; len < ByteLength;  ++len)
   {
      /* XOR byte-wise */
      /* PRQA S 0492 2 */
      ((P2VAR(uint8, AUTOMATIC, Cpl_APPL_DATA))Destination)[len] ^=
                        ((P2CONST(uint8, AUTOMATIC, Cpl_APPL_DATA))Source)[len];
   }
} /* end of function Cpl_CommonXOR */


/*----------------------------------------------------------------------------*/
/**
 * \brief  This function compares two blocks of data.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in]  BlockA        Holds a pointer to the first block to compare.
 * \param[in]  BlockB        Holds a pointer to the second block to compare.
 * \param[in]  ByteLength    Holds the amount of bytes which should be compared.
 *
 * \return result of the comparison
 * \retval TRUE   If both blocks are identical.
 * \retval FALSE  If the blocks differ.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

FUNC(boolean, Cpl_CODE) Cpl_CommonCompare(
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) BlockA,
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) BlockB,
   uint32                                  ByteLength)
{
  boolean retVal; /* return value */
  uint32 len;            /* internal length index */


  /* initialize the return value */
  retVal = TRUE;

   /* loop over the block length */
   for(len = (uint32)0; (len < ByteLength) && (retVal == TRUE); ++len)
   {
      /* compare byte-wise */
      if
      (
        /* PRQA S 0492 2 */
        ((P2CONST(uint8, AUTOMATIC, Cpl_APPL_DATA))BlockA)[len] !=
           ((P2CONST(uint8, AUTOMATIC, Cpl_APPL_DATA))BlockB)[len]
      )
      {
         retVal = FALSE;
      }
   }

   return retVal;
} /* end of function Cpl_CommonCompare */

/* PRQA S 5087 2 */
#define Cpl_STOP_SEC_CODE
#include "Cpl_MemMap.h"

/*--- End of file ------------------------------------------------------------*/
