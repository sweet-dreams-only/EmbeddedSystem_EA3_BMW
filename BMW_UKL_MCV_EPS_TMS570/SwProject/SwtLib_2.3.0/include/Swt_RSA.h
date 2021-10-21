/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Rsa.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Declarations for RSA routines                                 **
**                                                                            **
**  REMARKS   : Implementation of the mathematical operations needed for the  **
**              RSA algorithm and of routines to handle the long number       **
**              format used in those mathematical routines.                   **
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
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.9.0    : 28.11.2006, mg   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.0.0    : 04.04.2007, mg   : made different signature lengths for FSCs and
 *                                certificates possible
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

#if (!defined SWT_RSA_H)
#define SWT_RSA_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

                              /* list of guards to prevent double definitions */
#if (defined SWT_LN_WORD_LEN_BYTES)
   #error SWT_LN_WORD_LEN_BYTES already defined
#endif                                /* if (defined SWT_LN_WORD_LEN_BYTES) */

#if (defined SWT_LN_WORD_LEN_LEN_BITS)
   #error SWT_LN_WORD_LEN_LEN_BITS already defined
#endif                             /* if (defined SWT_LN_WORD_LEN_LEN_BITS) */

#if (defined SWT_LN_WORD_MAX)
   #error SWT_LN_WORD_MAX already defined
#endif                                      /* if (defined SWT_LN_WORD_MAX) */

#if (defined SWT_LN_HALFWORD_MAX)
   #error SWT_LN_HALFWORD_MAX already defined
#endif                                  /* if (defined SWT_LN_HALFWORD_MAX) */

#if (CPU_TYPE == CPU_TYPE_32)

                                               /* length of one word in bytes */
#define SWT_LN_WORD_LEN_BYTES     4U

/* Length of the word length in bits: If the word length is 32 bits, the      */
/* length of the word length is 5 bits.                                       */
#define SWT_LN_WORD_LEN_LEN_BITS  5U

                 /* the maximal value which can be stored in an unsigned word */
#define SWT_LN_WORD_MAX           0xFFFFFFFFUL

            /* the maximal value which can be stored in an unsigned half word */
#define SWT_LN_HALFWORD_MAX       0xFFFFU

#elif (CPU_TYPE == CPU_TYPE_16)

#define SWT_LN_WORD_LEN_BYTES     2U
#define SWT_LN_WORD_LEN_LEN_BITS  4U
#define SWT_LN_WORD_MAX           0xFFFFUL
#define SWT_LN_HALFWORD_MAX       0xFFU

#else

#error Unknown CPU_TPYE

#endif

#if (defined SWT_LN_WORD_LEN_BITS)
   #error SWT_LN_WORD_LEN_BITS already defined
#endif                                 /* if (defined SWT_LN_WORD_LEN_BITS) */

                                                  /* length of a word in bits */
#define SWT_LN_WORD_LEN_BITS (SWT_LN_WORD_LEN_BYTES * 8U)




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNGetWordLen                                        **
**                                                                            **
** DESCRIPTION    : When given the length of a number in bytes, computes the  **
**                  length of the long number representation in words.        **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : ByteLength: The length of a number in bytes               **
**                                                                            **
** RETURN         : The length of the long number representation in words     **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
#define Swt_LNGetWordLen(ByteLength)  \
                          ((((ByteLength) - 1U) / SWT_LN_WORD_LEN_BYTES) + 2U)



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNGetResultLen                                      **
**                                                                            **
** DESCRIPTION    : When given the length of a number in bytes, computes the  **
**                  length, in words, needed for the argument "result" in the **
**                  function Swt_LNExponentiateModular if a number of the   **
**                  given length is used as input.                            **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : ByteLength: The length of a number in bytes               **
**                                                                            **
** RETURN         : The length of the long number representation of the       **
**                  result of the function Swt_LNExponentiateModular        **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
// TODO: Barrett

#define Swt_LNGetResultLen(ByteLength) \
                                    ((Swt_LNGetWordLen(ByteLength) * 3U) + 2U)

#else

#define Swt_LNGetResultLen(ByteLength) \
                                    ((Swt_LNGetWordLen(ByteLength) * 2U) + 1U)

#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Swt_LNWordType has, for computing efficiency reasons, the natural storage*/
/* size for each controller. Since the computation intensive mathematical     */
/* operations (exponentiation and modulo) are carried out on arrays of        */
/* Words, this speeds up the computation noticeably.                          */
#if (CPU_TYPE == CPU_TYPE_32)

typedef uint32 Swt_LNWordType;

#elif (CPU_TYPE == CPU_TYPE_16)

typedef uint16 Swt_LNWordType;

#else

#error Unknown register width

#endif

                 /* context of a modulo computation without Barrett reduction */
typedef struct
{
   Swt_LNWordType LengthDifference;
}
Swt_LNModuloContextType;

                                        /* context of a modulo exponentiation */
typedef struct
{
   Swt_LNWordType          Bits;
   Swt_LNModuloContextType ModuloContext;
}
Swt_LNExpModularContextType;


                                                /* the public key information */
typedef struct
{
        /* a pointer to the long number representation of the public exponent */
   P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Exponent;
         /* a pointer to the long number representation of the public modulus */
   P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Modulus;
         /* a pointer to the extended modulus information - the Barrett value */
   P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) ModulusExt;
}
Swt_RSAKeyType;



/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"
extern void Swt_LNExponentiateModular
(
   CONSTP2VAR(Swt_LNExpModularContextType,AUTOMATIC,SC_FAR) Context,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)             Modulus,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)             Exponent,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)             ModulusExt,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)             Base,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)              Result
);

extern uint16 Swt_LNNumberToByteArray
(
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)       array
);

extern void Swt_LNByteArrayToNumber
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) array,
   const uint16        arrayLength,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)  number
);

extern SwtRC_t Swt_LNCompareNumbers
(
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number1,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number2
);

extern uint16 Swt_LNNumberToLEByteArray
(
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)       array
);

extern void Swt_LNLEByteArrayToNumber
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) array,
   const uint16        arrayLength,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)  number
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                           /* if (!defined SWT_RSA_H) */
/*** End of file **************************************************************/
