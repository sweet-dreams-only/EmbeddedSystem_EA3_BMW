/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_types.h                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Contains architecture independent type definitions which      **
**              are used both by the bootloader and the application.          **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
** tr           Thomas Rösch               Richard Bader GmbH                 **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.2: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.0.1: 14.04.2011,   tr: CR70826 Vector Release 10 Update for all Tools
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V5.1.0
 */


/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/*

(1) Violation: MISRA Rule 93
    A function should be used in preference to a function-like macro.
    Reason: The VSM should be designed portable to use to VSM in different
    integration variants. Therefore a macro layer is designed and used.

*/

#ifndef  SC_TYPES_H
#define  SC_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "sc_types_arch.h"        /* Include architecture dependent types     */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define Make16Bit(hiByte,loByte)         ((uint16)((((uint16)(hiByte))<<8)|    \
                                         ((uint16)(loByte))))

#define Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)                         \
                                         ((uint32)((((uint32)(hiHiByte))<<24)| \
                                         (((uint32)(hiLoByte))<<16)|           \
                                         (((uint32)(loHiByte))<<8) |           \
                                         ((uint32)(loLoByte))))

#define GetHiByte(data)                  ((uint8)(((uint16)(data))>>8))
#define GetLoByte(data)                  ((uint8)(data))

#define GetHiHiByte(data)                ((uint8)(((uint32)(data))>>24))
#define GetHiLoByte(data)                ((uint8)(((uint32)(data))>>16))
#define GetLoHiByte(data)                ((uint8)(((uint32)(data))>>8))
#define GetLoLoByte(data)                ((uint8)(data))

/*
 ****** Macros for multi-byte-bit-array access *********************************
 *
 * Caluclate the number of bytes that are needed for the bit field to store the
 * number of elements
 */
#define CALC_REQUIRED_BYTES_FOR_MULTI_BYTE_BIT_ARRAY(elements)                 \
            ( ( ( (elements) - 0x01u ) / 0x08u ) + 0x01u )
                           /*** MISRA rule 93 violation - see (1) in header ***/

/*
 * Calculate the index of the byte-level that holds the bit for the given entry:
 * Equivalent to 'element / 8'
 */
#define CALC_ARRAY_BYTE_LEVEL(element)                                         \
            ( (element) >> 3 )
                           /*** MISRA rule 93 violation - see (1) in header ***/
/*
 * Calculate the special bit position in the corresponding byte of the
 * multi-byte-bit-array, that holds the bits for the given entry:
 * Equivalent to 'element % 8'
 * Bit 0 ... 7 is equivalent to LSB ... MSB
 */
#define CALC_BIT_INDEX(element)                                                \
            ( (uint8)(element) & (uint8)0x07u )
                           /*** MISRA rule 93 violation - see (1) in header ***/

/*
 * Set the bit number 'element' in the multi-byte-bit-array 'array' (to '1')
 */
#define SET_BIT_IN_MULTI_BYTE_BIT_ARRAY(array,element)                         \
            ( (((uint8 * SC_FAR)array)[CALC_ARRAY_BYTE_LEVEL(element)]) |=            \
              ((uint8)(0x01u << CALC_BIT_INDEX(element)))                      \
            )              /*** MISRA rule 93 violation - see (1) in header ***/

/*
 * Clear the bit number 'element' in the multi-byte-bit-array 'array' (to '0')
 */
#define CLEAR_BIT_IN_MULTI_BYTE_BIT_ARRAY(array,element)                       \
            ( (((uint8 * SC_FAR)array)[CALC_ARRAY_BYTE_LEVEL(element)]) &=            \
              ((uint8)~(0x01u << CALC_BIT_INDEX(element)))                     \
            )              /*** MISRA rule 93 violation - see (1) in header ***/

/*
 * Get the value ('0' or '1') of the the bit number 'element' in the multi-byte-
 * bit-array 'array'
 */
#define GET_BIT_IN_MULTI_BYTE_BIT_ARRAY(array,element)                         \
     (uint8)(                                                                  \
       ((uint8)(((uint8)(((uint8 * SC_FAR)array)[CALC_ARRAY_BYTE_LEVEL(element)])) >> \
              CALC_BIT_INDEX(element))) & (uint8)(0x01u)                       \
            )              /*** MISRA rule 93 violation - see (1) in header ***/

#endif /* SC_TYPES_H                                                          */

/*** End of file **************************************************************/
