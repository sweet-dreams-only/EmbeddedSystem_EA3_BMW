/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Rsa.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for the RSA routines                              **
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
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_RSA.h"                        /* declarations of rsa services */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#if (defined Swt_LNLowHalfWord)
   #error Swt_LNLowHalfWord already defined
#endif                                    /* if (defined Swt_LNLowHalfWord) */

#if (defined Swt_LNHighHalfWord)
   #error Swt_LNHighHalfWord already defined
#endif                                   /* if (defined Swt_LNHighHalfWord) */

#if (defined Swt_LNDivByWordLen)
   #error Swt_LNDivByWordLen already defined
#endif                                   /* if (defined Swt_LNDivByWordLen) */

#if (defined Swt_LNNumberLen)
   #error Swt_LNNumberLen already defined
#endif                                      /* if (defined Swt_LNNumberLen) */

/* Function-like macros. These are a violation of MISRA rules, but they make  */
/* the code more readable.                                                    */

/* macros for the extraction of the high and low half-words */
#define Swt_LNLowHalfWord(a) \
   ((Swt_LNWordType)((a) & (Swt_LNWordType)SWT_LN_HALFWORD_MAX))

#define Swt_LNHighHalfWord(a) \
   ((Swt_LNWordType)((a) >> (SWT_LN_WORD_LEN_BITS >> 1U)))

/* Divide a value by the word length in bits. */
#define Swt_LNDivByWordLen(x) \
   ((Swt_LNWordType)((x) >> SWT_LN_WORD_LEN_LEN_BITS))

/* Compute "x mod SWT_WORD_LEN_BITS". This only works because              */
/* SWT_WORD_LEN_BITS is a power of 2.                                      */
#define Swt_LNModWordLen(x) \
   ((Swt_LNWordType)((x) & (Swt_LNWordType)(SWT_LN_WORD_LEN_BITS - 1U)))

/* Compute the amount of words that the long number representation of a       */
/* number will need from the length of the number in bytes. This is the value */
/* "(float)x / (float)SWT_LN_WORD_LEN_BYTES" rounded up. We compute this    */
/* with the following formula: ((x - 1) / SWT_LN_WORD_LEN_BYTES) + 1.       */
#define Swt_LNNumberLen(x)                            \
(                                                       \
   (Swt_LNWordType)                                   \
   (                                                    \
      (Swt_LNWordType)                                \
      (                                                 \
         (Swt_LNWordType)                             \
         (                                              \
            (Swt_LNWordType)(x) - (Swt_LNWordType)1 \
         ) /                                            \
         (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES      \
      ) +                                               \
      (Swt_LNWordType)1                                \
  )                                                    \
)

/* Get a given bit from a long number */
#define Swt_LNGetBit(number,bit)                                         \
(                                                                          \
   (Swt_LNWordType)                                                      \
   (                                                                       \
      (Swt_LNWordType)                                                   \
      (                                                                    \
         (number)[Swt_LNDivByWordLen(bit) + (Swt_LNWordType)1] >>      \
            Swt_LNModWordLen(bit) \
      ) &                                                                  \
      (Swt_LNWordType)1                                                  \
   )                                                                       \
)


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"
SWT_STATIC_FUNC Swt_LNWordType Swt_LNBitLengthOfNumber
(
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number
);

SWT_STATIC_FUNC void Swt_LNNormalizeNumber
(
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) number
);

SWT_STATIC_FUNC void Swt_LNMultiplyNumbers
(
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)  result,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) multiplicand,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) multiplicator
);

#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
// TODO: Barrett

SWT_STATIC_FUNC void Swt_LNSpecialSubtractNumbers
(
 CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)  result,
 CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) minuend,
 CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) subtrahend,
 const Swt_LNWordType   cutOff
 );

SWT_STATIC_FUNC void Swt_LNModuloWithBarrett
(
 CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)          number,
 CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         modulus,
 CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         barrett,
 CONSTP2VAR(Swt_LNModuloContextType,AUTOMATIC,SC_FAR) context
 );

#endif                   /* #if (SWT_RSA_USE_BARRETT == SWT_CFG_ON) #else */

SWT_STATIC_FUNC void Swt_LNModulo
(
 CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)          number,
 CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         modulus,
 CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         barrett,
 CONSTP2VAR(Swt_LNModuloContextType,AUTOMATIC,SC_FAR) context
 );



#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       External Constants                                   **
*******************************************************************************/


/*******************************************************************************
**                       External Data                                        **
*******************************************************************************/


/*******************************************************************************
**                       Local Constants                                      **
*******************************************************************************/


/*******************************************************************************
**                       Local Data                                           **
*******************************************************************************/



/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNExponentiateModular                               **
**                                                                            **
** DESCRIPTION    : Computes '(Base**Exponent) mod Modulus) in long number    **
**                  arithmetic and stores the value in 'Result'.              **
**                                                                            **
** PRECONDITIONS  : 'Context' is a valid pointer (not checked)                **
**                  'Modulus' is a valid pointer (not checked)                **
**                  'Exponent' is a valid pointer (not checked)               **
**                  'ModulusExt' is a valid pointer (not checked)             **
**                  'Base' is a valid pointer (not checked)                   **
**                  'Result' is a valid pointer and the memory pointed to by  **
**                    Result is large enough to hold                          **
**                    'SWT_RSA_TEMP_LEN_WORDS' words (not checked)          **
**                  'Exponent' and 'Modulus' must be normalized (not checked) **
**                  'modulus' > 0 (not checked)                               **
**                                                                            **
** POSTCONDITIONS : 'Result' contains the result of the modulo operation in   **
**                  normalized form.                                          **
**                                                                            **
** PARAMETERS     : Context:    A pointer to the context of this function     **
**                  Modulus:    The long number representation of the modulus **
**                  Exponent:   The long number representation of the exponent**
**                  ModulusExt: A pointer to the extended information of the  **
**                              modulus which must be the long number         **
**                              representation of the Barrett value if        **
**                              Barrerr reduction is turned on.               **
**                  Base:       The long number representation of the base    **
**                  Result:     This will hold the result of the operation    **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        : This function uses the square-and-multipy algorithm       **
**                  for exponentiation and uses the modulo function after     **
**                  each square and each multiply.                            **
**                                                                            **
**                  Since we use the function 'Swt_LNBitLengthOfNumber' to  **
**                  compute the length of 'Exponent', it must be normalized.  **
**                                                                            **
*******************************************************************************/
void Swt_LNExponentiateModular
(
   CONSTP2VAR(Swt_LNExpModularContextType,AUTOMATIC,SC_FAR) Context,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)             Modulus,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)             Exponent,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)             ModulusExt,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)             Base,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)              Result
)
{
   /* We compute the bit length of the exponent. */
   Context->Bits = Swt_LNBitLengthOfNumber(Exponent);

   /* Result = 1 */
   Result[0] = (Swt_LNWordType)1;
   Result[1] = (Swt_LNWordType)1;

   /* The square-and-multiply algorithm steps through each bit of the         */
   /* exponent.                                                               */
   while ((Context->Bits) > (Swt_LNWordType)0)
   {
      --(Context->Bits);

      /* Result = Result**2 mod Modulus  */
      Swt_LNMultiplyNumbers(Result, Result, Result);

#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
      // TODO: Barrett, wenn ModulusExt == 0 dann ohne Barrett, sonst mit
      if (0 != ModulusExt)
      {
         Swt_LNModuloWithBarrett
            (
            Result,
            Modulus,
            ModulusExt,
            &(Context->ModuloContext)
            );
      }
      else
      {
#endif
         Swt_LNModulo
            (
            Result,
            Modulus,
            ModulusExt,
            &(Context->ModuloContext)
            );      
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
      }
#endif
      /* If the current bit of Exponent is 1, we have to multiply 'Result' by */
      /* 'Base'.                                                              */
      if((Swt_LNWordType)1 == Swt_LNGetBit(Exponent, Context->Bits))
      {
         /* Result = (Base * Result) mod Modulus */
         Swt_LNMultiplyNumbers(Result, Result, Base);

         // TODO: Barrett, wenn ModulusExt == 0 dann ohne Barrett, sonst mit
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
         // TODO: Barrett, wenn ModulusExt == 0 dann ohne Barrett, sonst mit
         if (0 != ModulusExt)
         {
            Swt_LNModuloWithBarrett
               (
               Result,
               Modulus,
               ModulusExt,
               &(Context->ModuloContext)
               );
         }
         else
         {
#endif
            Swt_LNModulo
               (
               Result,
               Modulus,
               ModulusExt,
               &(Context->ModuloContext)
               );
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
         }
#endif
      }
   }                 /* while ((Context->Bits > 0) && (SWT_E_OK == RetVal)) */
   /* else                                                  */

   Swt_LNNormalizeNumber(Result);
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNNumberToByteArray                                 **
**                                                                            **
** DESCRIPTION    : transforms the long number representation stored in       **
**                  'number' to the big endian byte array 'array'.            **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer (not checked)                 **
**                  'array' is a valid pointer (not checked)                  **
**                                                                            **
** POSTCONDITIONS : 'array' contains the transformed number. It may contain   **
**                  leading zeroes.                                           **
**                                                                            **
** PARAMETERS     : number: The long number representation which is to be     **
**                          transformed                                       **
**                  array:  The byte array which will store the transformed   **
**                          number                                            **
**                                                                            **
** RETURN         : The length of 'array'                                     **
**                                                                            **
** REMARKS        : If 'number' is 0, 'array' will have length 0.             **
**                                                                            **
*******************************************************************************/
uint16 Swt_LNNumberToByteArray
(
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)   array
)
{
   Swt_LNWordType numberPos;                    /* the position in 'number' */
   /* the byte position in the urrent word of 'number'*/
   Swt_LNWordType wordPos;
   Swt_LNWordType arrayPos;               /* the position in the byte array */

   /* we cycle through all the words of 'number'. */
   for( numberPos = (Swt_LNWordType)1; numberPos <= number[0]; numberPos++ )
   {
      /* Begin computing the index of the byte which will be updated. */
      arrayPos  = number[0];
      arrayPos -= numberPos;
      arrayPos += (Swt_LNWordType)1;
      arrayPos *= (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES;

      /* Each word of 'number' is split into 'SWT_LN_WORD_LEN_BYTES' bytes  */
      /* of 'array'.                                                          */
      for
         (
         wordPos = (Swt_LNWordType)0;
      wordPos < (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES;
      wordPos++
         )
      {
         /* Finish computing the index of the byte which will be updated. */
         arrayPos -= (Swt_LNWordType)1;

         /* The current byte of 'array' is computed from the current word of  */
         /* 'number'.                                                         */
         array[arrayPos] = (uint8)(number[numberPos] >> (wordPos << 3U));
      }
   }

   /* Return the correct length of the byte array. */
   return (uint16)(number[0] * (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES);
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNByteArrayToNumber                                 **
**                                                                            **
** DESCRIPTION    : transforms the number stored in big endian format in the  **
**                  byte array 'array' to a long number representation and    **
**                  stores it in 'number'                                     **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer (not checked)                 **
**                  'array' is a valid pointer (not checked)                  **
**                                                                            **
** POSTCONDITIONS : 'number' contains the transformed number                  **
**                                                                            **
** PARAMETERS     : array:       The byte array which holds the number which  **
**                               is to be transformed                         **
**                  arrayLength: The length of 'array'                        **
**                  number:      Will contain the long number representation  **
**                               of the number stored in 'array'              **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        : If the array length is 0, the number output will be 0.    **
**                                                                            **
*******************************************************************************/
void Swt_LNByteArrayToNumber
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) array,
   const uint16  arrayLength,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) number
)
{
   Swt_LNWordType numberPos;                    /* the position in 'number' */
   /* the byte position in the urrent word of 'number'*/
   Swt_LNWordType wordPos;
   uint16           arrayPos;               /* the position in the byte array */

   if((uint16)0 != arrayLength)
   {
      /* We cycle through all of the words of the resulting number */
      for
         (
         numberPos = (Swt_LNWordType)1;
      numberPos <= Swt_LNNumberLen(arrayLength);
      numberPos++
         )
      {
         /* The current word of number is initialized to '0'. */
         number[numberPos] = (Swt_LNWordType)0;

         /* "SWT_LN_WORD_LEN_BYTES" bytes of the array are combined to make */
         /* up the current word of the number.                                */
         for
            (
            wordPos = (Swt_LNWordType)0;
         wordPos < (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES;
         wordPos++
            )
         {
            /* We compute the current position in 'array'. */
            arrayPos  = (uint16)SWT_LN_WORD_LEN_BYTES;
            arrayPos *= (uint16)(numberPos - (Swt_LNWordType)1);
            arrayPos += (uint16)wordPos;
            arrayPos  = (uint16)((uint16)(arrayLength - arrayPos) - (uint16)1);

            if(arrayPos < arrayLength)
            {
               /* If we are not over the edge of 'array', we incorporate the  */
               /* current byte of 'array' into the current word of the number.*/
               number[numberPos] |=
                  (Swt_LNWordType)
                  (
                  (Swt_LNWordType)array[arrayPos] << (wordPos << 3)
                  );
            }
         }
      }

      number[0] = Swt_LNNumberLen(arrayLength);

      Swt_LNNormalizeNumber(number);
   }
   else
   {
      /* The length of 'array' is '0', so the resulting number is also '0'. */
      number[0] = (Swt_LNWordType)0;
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNCompareNumbers                                    **
**                                                                            **
** DESCRIPTION    : Compares two numbers.                                     **
**                                                                            **
** PRECONDITIONS  : 'number1' is a valid pointer (not checked)                **
**                  'number2' is a valid pointer (not checked)                **
**                  Both numbers must be normalized (not checked)             **
**                                                                            **
** POSTCONDITIONS : no changes to the input                                   **
**                                                                            **
** PARAMETERS     : number1: The long number representation of the first      **
**                           number of the comparison.                        **
**                  number2: The long number representation of the second     **
**                           number of the comparison.                        **
**                                                                            **
** RETURN         : Swt_RC_SMALLER, if number1 <  number2                   **
**                  Swt_RC_EQUAL, if number1 == number2                     **
**                  Swt_RC_LARGER, if number1 >  number2                    **
**                                                                            **
** REMARKS        : The function uses the values number1[0] and number2[0]    **
**                  to obtain information about the size of the numbers. So,  **
**                  the numbers have to be normalized to obtain a correct     **
**                  result.                                                   **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_LNCompareNumbers
(
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number1,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number2
)
{
   Swt_LNWordType numberPos;         /* the current position in the numbers */
   SwtRC_t compare;                         /* the result of the comparison */


   /* First, the lengths of the two numbers are compared. If we find a        */
   /* difference here, the comparison is over.                                */
   if(number1[0] > number2[0])
   {
      compare = Swt_RC_LARGER;
   }
   else if(number1[0] < number2[0])
   {
      compare = Swt_RC_SMALLER;
   }
   else
   {
      /* Both numbers have an identical length. Now, we compare the words of  */
      /* those numbers from most to least significant word.                   */

      compare = Swt_RC_EQUAL;

      for
         (
         numberPos = number1[0];
      (numberPos > (Swt_LNWordType)0) && (Swt_RC_EQUAL == compare);
      numberPos--
         )
      {
         if(number1[numberPos] > number2[numberPos])
         {
            compare = Swt_RC_LARGER;
         }
         else if(number1[numberPos] < number2[numberPos])
         {
            compare = Swt_RC_SMALLER;
         }
         else
         {
            /* Do nothing. The numbers are identical up to here and this is   */
            /* reflected by the fact that 'compare' is EQUAL at the moment.   */
         }
      }
   }

   return compare;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNNumberToLEByteArray                               **
**                                                                            **
** DESCRIPTION    : transforms the long number representation stored in       **
**                  'number' to the little endian byte array 'array'.         **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer (not checked)                 **
**                  'array' is a valid pointer (not checked)                  **
**                                                                            **
** POSTCONDITIONS : 'array' contains the transformed number. It may contain   **
**                  leading zeroes.                                           **
**                                                                            **
** PARAMETERS     : number: The long number representation which is to be     **
**                          transformed                                       **
**                  array:  The byte array which will store the transformed   **
**                          number                                            **
**                                                                            **
** RETURN         : The length of 'array'                                     **
**                                                                            **
** REMARKS        : If 'number' is 0, 'array' will have length 0.             **
**                                                                            **
*******************************************************************************/
uint16 Swt_LNNumberToLEByteArray
(
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)   array
)
{
   Swt_LNWordType numberPos;                    /* the position in 'number' */
   /* the byte position in the urrent word of 'number'*/
   Swt_LNWordType wordPos;
   Swt_LNWordType arrayPos;               /* the position in the byte array */

   /* we cycle through all the words of 'number'. */
   for( numberPos = (Swt_LNWordType)1; numberPos <= number[0]; numberPos++ )
   {
      /* Begin computing the index of the byte which will be updated. */
      arrayPos = numberPos;
      arrayPos -= (Swt_LNWordType)1;
      arrayPos *= (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES;

      /* Each word of 'number' is split into 'SWT_LN_WORD_LEN_BYTES' bytes  */
      /* of 'array'.                                                          */
      for
         (
         wordPos = (Swt_LNWordType)0;
      wordPos < (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES;
      wordPos++
         )
      {
         /* The current byte of 'array' is computed from the current word of  */
         /* 'number'.                                                         */
         array[arrayPos] = (uint8)(number[numberPos] >> (wordPos << 3U));

         /* Finish computing the index of the byte which will be updated. */
         arrayPos += (Swt_LNWordType)1;
      }
   }

   /* Return the correct length of the byte array. */
   return (uint16)(number[0] * (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES);
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNLEByteArrayToNumber                               **
**                                                                            **
** DESCRIPTION    : transforms the number stored in little endian format in   **
**                  the byte array 'array' to a long number representation    **
**                  and stores it in 'number'                                 **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer (not checked)                 **
**                  'array' is a valid pointer (not checked)                  **
**                                                                            **
** POSTCONDITIONS : 'number' contains the transformed number                  **
**                                                                            **
** PARAMETERS     : array:       The byte array which holds the number which  **
**                               is to be transformed                         **
**                  arrayLength: The length of 'array'                        **
**                  number:      Will contain the long number representation  **
**                               of the number stored in 'array'              **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        : If the array length is 0, the number output will be 0.    **
**                                                                            **
*******************************************************************************/
void Swt_LNLEByteArrayToNumber
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) array,
   const uint16  arrayLength,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) number
)
{
   Swt_LNWordType numberPos;                    /* the position in 'number' */
   /* the byte position in the urrent word of 'number'*/
   Swt_LNWordType wordPos;
   uint16           arrayPos;               /* the position in the byte array */

   if((uint16)0 != arrayLength)
   {
      /* We cycle through all of the words of the resulting number */
      for
         (
         numberPos = (Swt_LNWordType)1;
      numberPos <= Swt_LNNumberLen(arrayLength);
      numberPos++
         )
      {
         /* The current word of number is initialized to '0'. */
         number[numberPos] = (Swt_LNWordType)0;

         /* "SWT_LN_WORD_LEN_BYTES" bytes of the array are combined to make */
         /* up the current word of the number.                                */
         for
            (
            wordPos = (Swt_LNWordType)0;
         wordPos < (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES;
         wordPos++
            )
         {
            arrayPos  = (uint16)SWT_LN_WORD_LEN_BYTES;
            arrayPos *= (uint16)(numberPos - (Swt_LNWordType)1);
            arrayPos += (uint16)wordPos;

            if(arrayPos < arrayLength)
            {
               /* If we are not over the edge of 'array', we incorporate the  */
               /* current byte of 'array' into the current word of the number.*/
               number[numberPos] |=
                  (Swt_LNWordType)
                  (
                  (Swt_LNWordType)array[arrayPos] << (wordPos << 3)
                  );
            }
         }
      }

      number[0] = Swt_LNNumberLen(arrayLength);

      Swt_LNNormalizeNumber(number);
   }
   else
   {
      /* The length of 'array' is '0', so the resulting number is also '0'. */
      number[0] = (Swt_LNWordType)0;
   }
}



/*******************************************************************************
**                      internal function definitions                         **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNBitLengthOfNumber                                 **
**                                                                            **
** DESCRIPTION    : Returns the length of "number" in bits                    **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer (not checked)                 **
**                  The number must be normalized (not checked)               **
**                                                                            **
** POSTCONDITIONS : no changes to input                                       **
**                                                                            **
** PARAMETERS     : number: The long number representation whose length is    **
**                          to be counted                                     **
**                                                                            **
** RETURN         : The length of 'number' in bits                            **
**                                                                            **
** REMARKS        : The function only uses the information in number[0] and   **
**                  number[number[0]] to obtain the bit-length of the number. **
**                  Because of this, the number needs to be normalized to     **
**                  obtain the correct result.                                **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC Swt_LNWordType Swt_LNBitLengthOfNumber
(
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) number
)
{
   Swt_LNWordType temp;            /* the most significant word of "number" */
   Swt_LNWordType length;                       /* the length of the number */


   if(number[0] > (Swt_LNWordType)0)
   {
      /* All words of the number except for the most significant word         */
      /* contribute SWT_LN_WORD_LEN_BITS bits to the length of the number.  */
      length = (Swt_LNWordType)(number[0] - (Swt_LNWordType)1) *
         (Swt_LNWordType)SWT_LN_WORD_LEN_BITS;

      /* We compute the amount of bits which the most significant word of     */
      /* "number" contributes to its length. In each round of this for-loop,  */
      /* the most significant word is shifted one bit to the right and we     */
      /* test whether it still is non-zero.                                   */
      for(temp = number[number[0]]; temp > (Swt_LNWordType)0; temp >>= 1U)
      {
         length++;
      }
   }
   else
   {
      /* The number is 0, so it has zero bits. */
      length = 0;
   }

   return length;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNNormalizeNumber                                   **
**                                                                            **
** DESCRIPTION    : All leading zeroes are removed from 'number'.             **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer (not checked)                 **
**                                                                            **
** POSTCONDITIONS : number[0] is the highest non-zero word of 'number'.       **
**                                                                            **
** PARAMETERS     : number: The long number representation of the number      **
**                          which is to be normalized.                        **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_LNNormalizeNumber
(
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) number
)
{
   Swt_LNWordType i;                                        /* loop counter */

   i = number[0];

   while((number[i] == (Swt_LNWordType)0) && (i > (Swt_LNWordType)0))
   {
      i--;
   }

   number[0] = i;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNMultiplyNumbers                                   **
**                                                                            **
** DESCRIPTION    : Multiply 'multiplicand' with 'multiplicator' in long      **
**                  number arithmetic and store the product in 'result'.      **
**                                                                            **
** PRECONDITIONS  : 'result' is a valid pointer and the memory pointed to by  **
**                  'result' is large enough to contain the multiplication    **
**                     result (not checked)                                   **
**                  'multiplicand' is a valid pointer (not checked)           **
**                  'multiplicator' is a valid pointer (not checked)          **
**                                                                            **
** POSTCONDITIONS : 'result' contains the product of 'multiplicand' and       **
**                  'multiplicator', in normalized form.                      **
**                                                                            **
** PARAMETERS     : result:        Will store the long number representation  **
**                                 of the product.                            **
**                  multiplicand:  The long number representation of the      **
**                                 multiplicand.                              **
**                  multiplicator: The long number representation of the      **
**                                 multiplicator.                             **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        : The result, multiplicand, and multiplicator may all be    **
**                  the same array. So, e.g., "in-number" squaring is         **
**                  possible with the function call                           **
**                  Swt_LNMultiplyNumbers(foobar,foobar,foobar). To achieve **
**                  this feature without using temporary arrays, we use the   **
**                  following formula to compute the multiplication           **
**                  (using LaTeX notation):                                   **
**                  Let our base be "c". Let a = \sum_{i=1}^{n}a_i*c^{i-1}    **
**                  and let b = \sum_{j=1}^{m}b_j*c^{j-1}, then we have:      **
**                  a * b = \sum_{i=1}^{n+m-1}                                **
**                           (                                                **
**                             c^{i-1} *                                      **
**                             \sum_{j=\max\{1,i-n+1\}}^{\min\{i,m\}}         **
**                             (                                              **
**                               b_j *                                        **
**                               a_{i-j+1}                                    **
**                             )                                              **
**                           )                                                **
**                 We implement this formula with a twist:                    **
**                 The outer sum (\sum_{i=1}^{n+m-1}) is computed from top to **
**                 bottom, so we start with i = n+m-1 and count down to 1. We **
**                 use this special formula because for the computation of    **
**                 word k of the result, only words from                      **
**                 1 to k of the inputs are needed. So, if we compute the     **
**                 result from highest to lowest word, after we have          **
**                 computed word k of the result, we don't need the higher    **
**                 words of the inputs anymore. So, if we write the           **
**                 word k to the result and in doing so overwrite word k of   **
**                 an input, it doesn't matter anymore.                       **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_LNMultiplyNumbers
(
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)  result,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) multiplicand,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) multiplicator
)
{
   Swt_LNWordType i;                                        /* loop counter */
   Swt_LNWordType j;                                        /* loop counter */
   Swt_LNWordType temp;
   Swt_LNWordType rl;            /* the low word of a multiplication result */
   Swt_LNWordType carry;                     /* a carry used in an addition */
   Swt_LNWordType tempResult;
   /* Will hold the value of result[i]. We cannot store    */
   /* the value in result[i] itself, because "result" may  */
   /* be one of the input arrays, and we need the value of */
   /* multiplicand[i] and multiplicator[i] for further     */
   /* computations.                                        */

   if(((Swt_LNWordType)0 == multiplicand[0]) ||
      ((Swt_LNWordType)0 == multiplicator[0]))
   {
      /* One of the inputs was 0, so the result is also 0. */
      result[0] = (Swt_LNWordType)0;
   }
   else
   {
      /* The highest word of the result is initialized to 0. This word is not */
      /* set directly during the following multiplication, but can be         */
      /* reached through overflows during the computation of the lower words. */
      result[multiplicand[0] + multiplicator[0]] = (Swt_LNWordType)0;

      /* We compute the outer sum "\sum_{i=1}^{n+m-1}" from top to bottom. */
      for
         (
         i = (Swt_LNWordType)(multiplicand[0] + multiplicator[0]) -
         (Swt_LNWordType)1;
      i > (Swt_LNWordType)0;
      i--
         )
      {
         if(i >= multiplicand[0])
         {
            j = (Swt_LNWordType)(i - multiplicand[0]) + (Swt_LNWordType)1;
         }
         else
         {
            j = (Swt_LNWordType)1;
         }

         tempResult = (Swt_LNWordType)0;

         /* We compute the inner sum "\sum_{j=\max\{1,i-n+1\}}^{\min\{i,m\}}".*/
         for(; (j <= i) && (j <= multiplicator[0]); j++)
         {
            /* Multiply 'multiplicand[i-j+1]' with 'multiplicator[j]' and     */
            /* store the lower word of the result in 'rl' and the higher word */
            /* in 'carry'. 'temp' is a temporary variable.                    */

            temp = Swt_LNLowHalfWord
               (
               multiplicand[i - j + (Swt_LNWordType)1]
            ) *
               Swt_LNHighHalfWord(multiplicator[j]);

            rl = Swt_LNHighHalfWord
               (
               multiplicand[i - j + (Swt_LNWordType)1]
            ) *
               Swt_LNLowHalfWord(multiplicator[j]);

            temp += rl;

            if (temp < rl)
            {
               carry = Swt_LNHighHalfWord(temp) |
                  (Swt_LNWordType)
                  (
                  (Swt_LNWordType)SWT_LN_HALFWORD_MAX +
                  (Swt_LNWordType)1
                  );
            }
            else
            {
               carry = Swt_LNHighHalfWord(temp);
            }

            rl = (Swt_LNWordType)
               (Swt_LNLowHalfWord(temp) << (SWT_LN_WORD_LEN_BITS >> 1U));

            temp = Swt_LNLowHalfWord
               (
               multiplicand[i - j + (Swt_LNWordType)1]
            ) *
               Swt_LNLowHalfWord(multiplicator[j]);

            /* The low word of the multiplication result is computed. */
            rl += temp;

            if( rl < temp )
            {
               carry++;
            }

            /* The high word of the multiplication result is stored in        */
            /* 'carry'.                                                       */
            carry += (Swt_LNWordType)
               (
               Swt_LNHighHalfWord
               (
               multiplicand[i - j + (Swt_LNWordType)1]
            ) *
               Swt_LNHighHalfWord(multiplicator[j])
               );

            /* The low word of the multiplication result is added to          */
            /* 'tempResult'.                                                  */
            tempResult += rl;

            if(tempResult < rl)
            {
               /* There was an overflow. So, we increase the carry by one.    */
               /* This increment cannot overflow since the carry, being the   */
               /* high word of the multiplication of two words, is at least   */
               /* one smaller than the maximal possible value.                */
               carry++;
            }

            /* We carry the carry upward until it has trickled away. */
            temp = (Swt_LNWordType)1;

            while(carry != (Swt_LNWordType)0)
            {
               result[i + temp] += carry;

               if(result[i + temp] < carry)
               {
                  /* We had another overflow. */
                  carry = (Swt_LNWordType)1;
               }
               else
               {
                  /* No overflow, the carry has trickled away. */
                  carry = (Swt_LNWordType)0;
               }

               temp++;
            }
         }

         /* Now we are sure that we do not need values of the input arrays up */
         /* to position i anymore, so we can write the result array.          */
         result[i] = tempResult;
      }

      /* We give the result the maximal possible length. */
      result[0] = multiplicand[0] + multiplicator[0];

      /* We remove leading zeroes from the result. */
      Swt_LNNormalizeNumber(result);
   }
}

/* The following functions are only needed if Barrett reduction is turned on. */
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
// TODO: Barrett
/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNSpecialSubtractNumbers                            **
**                                                                            **
** DESCRIPTION    : Subtract 'subtrahend' from 'minuend' in long number       **
**                  arithmetic and store the difference in 'result'.          **
**                                                                            **
** PRECONDITIONS  : 'result' is a valid pointer and the memory pointed to by  **
**                  'result' is large enough to contain the difference.       **
**                  'minuend' is a valid pointer (not checked)                **
**                  'subtrahend' is a valid pointer (not checked)             **
**                  'minuend' and 'subtrahend' must be normalized (not        **
**                     checked)                                               **
**                  subtrahend < 2**(SWT_LN_WORD_LEN_BITS*cutOff) (not      **
**                     checked)                                               **
**                                                                            **
** POSTCONDITIONS : 'result' contains the difference of 'minuend' and         **
**                  'subtrahend', if no error was encountered.                **
**                                                                            **
** PARAMETERS     : result:     Will store the long number representation     **
**                              of the product.                               **
**                  minuend:    The long number representation of the         **
**                              minuend.                                      **
**                  subtrahend: The long number representation of the         **
**                              subrahend.                                    **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if subtrahend > minuend               **
**                  Swt_RC_OK, otherwise                                    **
**                                                                            **
** REMARKS        : The effect of this function is as if the following would  **
**                  have been done:                                           **
**                  Let b the bitlength of one word. subtrahend is subtracted **
**                  from minuend mod 2**(b*cutOff). If the result is          **
**                  negative, 2**(b*cutOff) is added to the result.           **
**                                                                            **
**                  The function does this, for efficiency reasons, a little  **
**                  different: The number "minuend mod 2**(b*cutOff)"         **
**                  is nothing else than "minuend" where every word           **
**                  above "cutOff" is set to 0.                               **
**                                                                            **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_LNSpecialSubtractNumbers
(
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)  result,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) minuend,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) subtrahend,
   const Swt_LNWordType   cutOff
)
{
   Swt_LNWordType i;                                        /* loop counter */
   Swt_LNWordType temp;
   uint8          carry;                                         /* carry bit */


   carry = (uint8)0;

   /* We subtract subtrahend from minuend (least significant word to most     */
   /* significant word) until either the subtrahend has been exhausted or     */
   /* "cutOff" words have been done, whichever comes first.                   */
   for (i = (Swt_LNWordType)1 ; (i <= subtrahend[0]) && (i <= cutOff); i++)
   {
      if(i <= minuend[0])
      {
         temp = minuend[i];
      }
      else
      {
         temp = (Swt_LNWordType)0;
      }

      if (temp >= (Swt_LNWordType)carry)
      {
         temp -= (Swt_LNWordType)carry;
         carry = (uint8)0;
      }
      else
      {
         temp -= (Swt_LNWordType)carry;
         carry = (uint8)1;
      }

      result[i] = temp - subtrahend[i];

      if (result[i] > temp)
      {
         carry = (uint8)1;
      }
   }

   /* If the subtrahend had less than "cutOff" words, we handle leftover      */
   /* carries from the subtraction.                                           */
   for (; (i <= cutOff) && (carry != (uint8)0); i++)
   {
      if(i <= minuend[0])
      {
         temp = minuend[i];
      }
      else
      {
         temp = (Swt_LNWordType)0;
      }

      result[i] = temp - (Swt_LNWordType)carry;

      if ((Swt_LNWordType)carry <= temp)
      {
         carry = (uint8)0;
      }
      else
      {
         carry = (uint8)1;
      }
   }

   /* Now 'i' is either one larger than 'cutOff' or the last carry has        */
   /* trickled away.                                                          */
   if(i > minuend[0])
   {
      result[0] = i - (Swt_LNWordType)1;
   }
   else
   {
      result[0] = minuend[0];
   }

   Swt_LNNormalizeNumber(result);
}
// TODO: Barrett
/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNModuloWithBarrett                                   **
**                                                                            **
** DESCRIPTION    : Computes 'number mod modulus' in long number arithmetic   **
**                  with the help of the Barrett value 'barrett' and stores   **
**                  the result in 'number'.                                   **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer and the memory pointed to by  **
**                     'number' is large enough to contain                    **
**                     'number[0] + modulus[0] + 5' words.                    **
**                  'modulus' is a valid pointer (not checked)                **
**                  'barrett' is a valid pointer (not checked)                **
**                  'modulus' must be normalized (not checked)                **
**                  'modulus' > 0 (not checked)                               **
**                                                                            **
** POSTCONDITIONS : 'number' contains the long number representaion of the    **
**                  result of the modulo operation in normalized form.        **
**                                                                            **
** PARAMETERS     : number:  The long number representation of the number     **
**                           on which the modulo operation is to be performed **
**                  modulus: The long number representation of the modulus    **
**                  barrett: The long number representation of the Barrett    **
**                           value which helps speed up the operation.        **
**                  context: A pointer to the context of this function. This  **
**                           is ignored.                                      **
**                                                                            **
** RETURN         : Swt_RC_OK, if the operation finished successfuly        **
**                  An error which is returned by Swt_Subtract, otherwise   **
**                                                                            **
** REMARKS        : This function uses the Barrett modular reduction          **
**                  algorithm as described in A. Menezes, P. van Oorschot,    **
**                  S. Vanstone: Handbook of Applied Cryptology, CRC Press    **
**                  1997, p. 604. The value mu is our value 'barrett', the    **
**                  value 'b' is '2**SWT_LN_WORD_LEN_BITS', and the value   **
**                  'k' is the length of 'modulus', which is 'modulus[0]'.    **
**                                                                            **
**                  Since we use the value 'modulus[0]' to calculate the      **
**                  size of the modulus, 'modulus' must be normalized.        **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_LNModuloWithBarrett                     
(
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)          number,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         modulus,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         barrett,
   CONSTP2VAR(Swt_LNModuloContextType,AUTOMATIC,SC_FAR) context
)
{
   P2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) tempNumber;
   Swt_LNWordType  i;

   /* The input 'number' is needed twice during the computation, but once it  */
   /* is shifted 'modulus[0]-1' words to the right and once it is cropped to  */
   /* the last 'modulus[0]+1' words. This means that on the first occasion    */
   /* all the words of 'number' except for the last 'modulus[0]-1' are needed */
   /* and on the second occasion only the last 'modulus[0]+1' words of        */
   /* 'number' are needed. So, with the exception of a two word overlap, two  */
   /* distinct parts of 'number' are needed during the computation. So, we    */
   /* begin by splitting 'number' into the two distinct parts with a little   */
   /* shifting. Then we have both parts at our disposal.                      */

   /* The more significant part of 'number' is shifted 3 blocks to the left.  */
   for(i = number[0]; i >= modulus[0]; i--)
   {
      number[i + (Swt_LNWordType)3] = number[i];
   }

   /* The length of the two parts is computed. The left part starts at        */
   /* number[modulus[0]+2].                                                   */
   if(modulus[0] > number[0])
   {
      /* The number is so small that the right shifted part is zero and the   */
      /* cropped part is the number itself.                                   */
      number[modulus[0] + (Swt_LNWordType)2] = 0;
   }
   else
   {
      /* The length of the right shifted part. */
      number[modulus[0] + (Swt_LNWordType)2] =
         (Swt_LNWordType)(number[0] + (Swt_LNWordType)1) - modulus[0];

      /* The length of the cropped part. */
      number[0] = modulus[0] + (Swt_LNWordType)1;
   }

   /* tempNumber is set to the start of the newly created number. */
   tempNumber = &number[modulus[0] + (Swt_LNWordType)2];

   /* "tempNumber" now contains the value of "number" shifted "modulus[0]-1"  */
   /* words to the right, while "number" itself now contains the old value of */
   /* number cropped to the last "modulus[0]+1" words. So, in the notation of */
   /* Menezes et al., 'tempNumber' contains q1, while 'number' contains r1.   */

   /* q2 = q1 * mu. q2 is stored in "tempNumber". */
   Swt_LNMultiplyNumbers(tempNumber, tempNumber, barrett);

   /* q3 = q2 / b**(k+1). This is a right shift by 'modulus[0]+1' words. q3   */
   /* is stored in "tempNumber".                                              */
   if(modulus[0] >= tempNumber[0])
   {
      /* 'tempNumber' is so small that the right shift makes it 0. */
      tempNumber[0] = (Swt_LNWordType)0;
   }
   else
   {
      for(i = (modulus[0] + (Swt_LNWordType)2); i <= tempNumber[0]; i++)
      {
         tempNumber[i - (modulus[0] + (Swt_LNWordType)1)] = tempNumber[i];
      }

      tempNumber[0] -= (Swt_LNWordType)(modulus[0] + (Swt_LNWordType)1);
   }

   /* r3 = q3 * m. This step is not in the book. There, it is combined with   */
   /* the next step and we go directly to r2 = (q3 * m) mod b**(k+1). r3 is   */
   /* stored in tempNumber.                                                   */
   Swt_LNMultiplyNumbers(tempNumber, tempNumber, modulus);

   /* r2 = r3 mod b**(k+1). r2 is stored in tempNumber. */
   if((modulus[0] + (Swt_LNWordType)1) < tempNumber[0])
   {
      tempNumber[0] = modulus[0] + (Swt_LNWordType)1;
   }

   /* We now compute the following two steps of the algorithm in one go:      */
   /*   3. r = r1 - r2.                                                       */
   /*   4. if r < 0 then r = r + b**(k+1).                                    */
   /* r is stored in "number".                                                */
   Swt_LNSpecialSubtractNumbers
      (
      number,
      number,
      tempNumber,
      modulus[0] + (Swt_LNWordType)1
      );

   /* We know that the following while loop can never be repeated more than   */
   /* twice with the correct Barrett value. So, we count the repetitions.     */
   i = (Swt_LNWordType)0;

   /* while r > m do r = r - m. r is stored in number. After this while-loop  */
   /* has finished, the modulo computation is finished and the result is in   */
   /* "number".                                                               */
   while
      (
      (i < (Swt_LNWordType)4)  &&
      (Swt_RC_SMALLER != Swt_LNCompareNumbers(number,modulus))
      )
   {
      Swt_LNSpecialSubtractNumbers
         (
         number,
         number,
         modulus,
         SWT_LN_WORD_MAX
         );

      i++;
   }

   /* Did we do too many loop repetitions? */
   if((Swt_LNWordType)4 == i)
   {
      /* Something went wrong. Probably an incorrect Barrett value. We set    */
      /* the result to 0.                                                     */
      number[0] = (Swt_LNWordType)0;
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNModulo                                            **
**                                                                            **
** DESCRIPTION    : Computes 'number mod modulus' in long number arithmetic   **
**                  using the context pointed to by 'context'.                **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer (not checked)                 **
**                  'modulus' is a valid pointer (not checked)                **
**                  'context' is a valid pointer (not checked)                **
**                  'number' and 'modulus' must be normalized (not checked)   **
**                  'modulus' > 0 (not checked)                               **
**                                                                            **
** POSTCONDITIONS : 'number' contains the long number representation of the   **
**                  result of the modulo operation in normalized form.        **
**                                                                            **
** PARAMETERS     : number:  The long number representation of the number     **
**                           on which the modulo operation is to be performed **
**                  barrett: The long number representation of the Barrett    **
**                           value. This is ignored.                          **
**                  modulus: The long number representation of the modulus    **
**                  context: A pointer to the context of this function        **
**                                                                            **
** RETURN         : Swt_RC_OK, if the operation finished successfuly        **
**                  Swt_RC_BAD_PARAM, if the modulus was zero               **
**                                                                            **
** REMARKS        : The function uses the binary division algorithm.          **
**                                                                            **
**                  Since we compute the bit length of 'number' and 'modulus' **
**                  by calling 'Swt_LNBitLengthOfNumber', both have to be   **
**                  normalized.                                               **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_LNModulo
(
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)          number,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         modulus,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         barrett,
   CONSTP2VAR(Swt_LNModuloContextType,AUTOMATIC,SC_FAR) context
)
{
   Swt_LNWordType lengthOfNum;              /* the length of number in bits */
   Swt_LNWordType lengthOfMod;             /* the length of modulus in bits */

   Swt_LNWordType wordOfShiftedMod;      /* one word of the shifted modulus */
   Swt_LNWordType wordOfNumber;                       /* one word of number */

   SwtRC_t cmpNumMod;        /* Stores whether number is larger than the    */
   /* shifted modulus                             */

   Swt_LNWordType carry;                /* A carry used in the subtraction. */
   uint8          tempCarry; /* Used to store whether the carry has to be set */
   /* for the next word.                            */

   uint8          shiftBits; /* the amount of bits by which each word of      */
   /* modulus is to be shifted                      */
   Swt_LNWordType shiftWords; /* The amount of full words by which modulus  */
   /* is to be shifted.                          */

   Swt_LNWordType posInNum;               /* the current position in number */
   Swt_LNWordType posInMod;              /* the current position in modulus */



   /* We compute the length of number in bits. */
   lengthOfNum   = Swt_LNBitLengthOfNumber(number);

   /* We compute the length of modulus in bits. */
   lengthOfMod   = Swt_LNBitLengthOfNumber(modulus);

   /* We only do something if number is at least as long as modulus.          */
   /* Otherwise, result = number mod modulus = number.                        */
   if(lengthOfMod <= lengthOfNum)
   {
      /* We compute the length difference of number and modulus in bits. We   */
      /* add 1 because we will subtract 1 at the beginning of the             */
      /* do-while-loop.                                                       */
      context->LengthDifference = (Swt_LNWordType)(lengthOfNum - lengthOfMod)
         + (Swt_LNWordType)1;

      /* Binary division: We shift modulus an amount of                       */
      /* context->LengthDifference bits to the left. Then we check whether    */
      /* number is at least as large as the shifted modulus. If this is the   */
      /* case we subtract the shifted modulus from number. We decrease        */
      /* context->LengthDifference by one and repeat this game until          */
      /* context->LengthDifference is 0.                                      */
      /* The modulus is not really shifted but the individual words of the    */
      /* shifted modulus are computed when they are needed and stored in      */
      /* wordOfShiftedMod.                                                    */
      do
      {
         /* At the beginning of each round, we decrease                       */
         /* context->LengthDifference by one.                                 */
         (context->LengthDifference)--;

         /* We extract from context->LengthDifference how many complete       */
         /* words to shift modulus and how many bits to shift modulus.        */
         shiftWords = Swt_LNDivByWordLen(context->LengthDifference);
         shiftBits  = (uint8)Swt_LNModWordLen(context->LengthDifference);

         /* The first position of modulus from which to create the shifted    */
         /* modulus is computed. Note that this is one larger than the        */
         /* most significant word of modulus.                                 */
         posInMod = modulus[0] + (Swt_LNWordType)1;

         /* The first position of number which to compare to the shifted      */
         /* modulus is computed.                                              */
         posInNum = posInMod + shiftWords;

         /* For each word of modulus, the shifted modulus is computed and     */
         /* compared to the corresponding word of number.                     */
         do
         {
            /* We assemble the current word of the shifted modulus from the   */
            /* words modulus[posInMod] and modulus[posInMod - 1].             */

            /* We test whether the current position in modulus is an allowed  */
            /* position.                                                      */
            if(posInMod <= modulus[0])
            {
               /* The current position in modulus is allowed. We take some    */
               /* bits from the word of modulus at that position.             */
               wordOfShiftedMod = modulus[posInMod] << shiftBits;
            }
            else
            {
               /* The current position in modulus is too high. We are at a    */
               /* "leading zero". So, all the bits which go into              */
               /* wordOfShiftedMod are zero.                                  */
               wordOfShiftedMod = (Swt_LNWordType)0;
            }

            /* The needed bits from modulus[posInMod - 1] are incorporated    */
            /* into wordOfShiftedMod. If we shift the modulus by complete     */
            /* words (which means "shiftBits == 0") or if posInMod            */
            /* is the lowest possible position (which means posInMod == 1)    */
            /* no bits from modulus[posInMod - 1] are needed.                 */
            if((shiftBits != (uint8)0) && (posInMod > (Swt_LNWordType)1))
            {
               wordOfShiftedMod |=
                  (Swt_LNWordType)
                  (
                  modulus[posInMod - (Swt_LNWordType)1] >>
                  ((uint8)SWT_LN_WORD_LEN_BITS - shiftBits)
                  );
            }

            /* We compute the word of number which to compare to the word     */
            /* of the shifted modulus. This is normally simply                */
            /* number[posInNum], but the position can be too high which means */
            /* that we are at a "leading zero" of number.                     */
            if(posInNum > number[0])
            {
               wordOfNumber = (Swt_LNWordType)0;
            }
            else
            {
               wordOfNumber = number[posInNum];
            }

            /* Now, we compare the word of the shifted modulus to the current */
            /* word of number.                                                */
            if(wordOfShiftedMod == wordOfNumber)
            {
               cmpNumMod = Swt_RC_EQUAL;
            }
            else if (wordOfShiftedMod > wordOfNumber)
            {
               cmpNumMod = Swt_RC_SMALLER;
            }
            else
            {
               cmpNumMod = Swt_RC_LARGER;
            }

            /* The positions are decreased by 1. */
            posInMod--;
            posInNum--;
         }
         while((Swt_RC_EQUAL == cmpNumMod)&&(posInMod > (Swt_LNWordType)0));

         /* If number is at least as large as the shifted modulus, we         */
         /* subtract modulus from number.                                     */
         if(cmpNumMod != Swt_RC_SMALLER)
         {
            wordOfShiftedMod = (Swt_LNWordType)0;

            carry = (Swt_LNWordType)0;

            /* When subtracting the shifted modulus from number we can        */
            /* skip the least significant words of number because the         */
            /* shifted modulus is 0, there. We compute the least              */
            /* significant word of number which is affected by the            */
            /* subtraction.                                                   */
            posInNum = (Swt_LNWordType)1 + shiftWords;

            /* We go through every word of the shifted modulus.    */
            for
               (
               posInMod = (Swt_LNWordType)1;
            posInMod <= modulus[0];
            posInMod++
               )
            {
               tempCarry = (uint8)0;

               wordOfShiftedMod |=
                  (Swt_LNWordType)(modulus[posInMod] << shiftBits);

               /* We test whether a carry forms at this position. This        */
               /* happens when "wordOfShiftedMod + carry > number[posInNum]". */
               /* Since we cannot test this condition directly because of     */
               /* possible overflows we use a more complicated looking test   */
               /* which actually does exactly what we want.                   */
               if(
                  (wordOfShiftedMod >= number[posInNum])      &&
                  (
                  (wordOfShiftedMod > number[posInNum]) ||
                  (carry > (Swt_LNWordType)0)
                  )
                  )
               {
                  tempCarry = (uint8)1;
               }

               /* We subtract "wordOfShiftedMod" and "carry" from the number. */
               number[posInNum] -= wordOfShiftedMod;
               number[posInNum] -= (Swt_LNWordType)carry;

               carry = (Swt_LNWordType)tempCarry;

               if(shiftBits == (uint8)0)
               {
                  wordOfShiftedMod = (Swt_LNWordType)0;
               }
               else
               {
                  wordOfShiftedMod = modulus[posInMod] >>
                     (uint8)((uint8)SWT_LN_WORD_LEN_BITS - shiftBits);
               }

               posInNum++;
            }                     /* for(posInMod = (Swt_LNWordType)1; ...) */

            /* Now we have to deal with leftover carries and a possible last  */
            /* word of the shifted modulus. Since the carry is at most one    */
            /* and wordOfShiftedMod is at least one bit shorter than the      */
            /* largest possible word (making it at most half as large), we    */
            /* can add both numbers in "carry" without overflow.              */
            carry += wordOfShiftedMod;

            /* Now we deal with the leftover carries. */
            while(carry != (Swt_LNWordType)0)
            {
               if(number[posInNum] >= carry)
               {
                  /* The carry has trickled away. */
                  number[posInNum] -= carry;
                  carry = (Swt_LNWordType)0;
               }
               else
               {
                  /* We have to take the carry one word upwards. */
                  number[posInNum] -= carry;
                  carry = (Swt_LNWordType)1;
               }
               posInNum++;
            }
         }                                       /* if(cmpNumMod >= (sint8)0) */

      }
      while ((context->LengthDifference) > (Swt_LNWordType)0);
   }

   Swt_LNNormalizeNumber(number);
}

/* The following function is only needed if Barrett reduction is turned off.  */
#else                          /* #if (SWT_RSA_USE_BARRETT == SWT_CFG_ON) */

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_LNModulo                                            **
**                                                                            **
** DESCRIPTION    : Computes 'number mod modulus' in long number arithmetic   **
**                  using the context pointed to by 'context'.                **
**                                                                            **
** PRECONDITIONS  : 'number' is a valid pointer (not checked)                 **
**                  'modulus' is a valid pointer (not checked)                **
**                  'context' is a valid pointer (not checked)                **
**                  'number' and 'modulus' must be normalized (not checked)   **
**                  'modulus' > 0 (not checked)                               **
**                                                                            **
** POSTCONDITIONS : 'number' contains the long number representation of the   **
**                  result of the modulo operation in normalized form.        **
**                                                                            **
** PARAMETERS     : number:  The long number representation of the number     **
**                           on which the modulo operation is to be performed **
**                  barrett: The long number representation of the Barrett    **
**                           value. This is ignored.                          **
**                  modulus: The long number representation of the modulus    **
**                  context: A pointer to the context of this function        **
**                                                                            **
** RETURN         : Swt_RC_OK, if the operation finished successfuly        **
**                  Swt_RC_BAD_PARAM, if the modulus was zero               **
**                                                                            **
** REMARKS        : The function uses the binary division algorithm.          **
**                                                                            **
**                  Since we compute the bit length of 'number' and 'modulus' **
**                  by calling 'Swt_LNBitLengthOfNumber', both have to be   **
**                  normalized.                                               **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_LNModulo
(
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)          number,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         modulus,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)         barrett,
   CONSTP2VAR(Swt_LNModuloContextType,AUTOMATIC,SC_FAR) context
)
{
   Swt_LNWordType lengthOfNum;              /* the length of number in bits */
   Swt_LNWordType lengthOfMod;             /* the length of modulus in bits */

   Swt_LNWordType wordOfShiftedMod;      /* one word of the shifted modulus */
   Swt_LNWordType wordOfNumber;                       /* one word of number */

   SwtRC_t cmpNumMod;        /* Stores whether number is larger than the    */
   /* shifted modulus                             */

   Swt_LNWordType carry;                /* A carry used in the subtraction. */
   uint8          tempCarry; /* Used to store whether the carry has to be set */
   /* for the next word.                            */

   uint8          shiftBits; /* the amount of bits by which each word of      */
   /* modulus is to be shifted                      */
   Swt_LNWordType shiftWords; /* The amount of full words by which modulus  */
   /* is to be shifted.                          */

   Swt_LNWordType posInNum;               /* the current position in number */
   Swt_LNWordType posInMod;              /* the current position in modulus */



   /* We compute the length of number in bits. */
   lengthOfNum   = Swt_LNBitLengthOfNumber(number);

   /* We compute the length of modulus in bits. */
   lengthOfMod   = Swt_LNBitLengthOfNumber(modulus);

   /* We only do something if number is at least as long as modulus.          */
   /* Otherwise, result = number mod modulus = number.                        */
   if(lengthOfMod <= lengthOfNum)
   {
      /* We compute the length difference of number and modulus in bits. We   */
      /* add 1 because we will subtract 1 at the beginning of the             */
      /* do-while-loop.                                                       */
      context->LengthDifference = (Swt_LNWordType)(lengthOfNum - lengthOfMod)
         + (Swt_LNWordType)1;

      /* Binary division: We shift modulus an amount of                       */
      /* context->LengthDifference bits to the left. Then we check whether    */
      /* number is at least as large as the shifted modulus. If this is the   */
      /* case we subtract the shifted modulus from number. We decrease        */
      /* context->LengthDifference by one and repeat this game until          */
      /* context->LengthDifference is 0.                                      */
      /* The modulus is not really shifted but the individual words of the    */
      /* shifted modulus are computed when they are needed and stored in      */
      /* wordOfShiftedMod.                                                    */
      do
      {
         /* At the beginning of each round, we decrease                       */
         /* context->LengthDifference by one.                                 */
         (context->LengthDifference)--;

         /* We extract from context->LengthDifference how many complete       */
         /* words to shift modulus and how many bits to shift modulus.        */
         shiftWords = Swt_LNDivByWordLen(context->LengthDifference);
         shiftBits  = (uint8)Swt_LNModWordLen(context->LengthDifference);

         /* The first position of modulus from which to create the shifted    */
         /* modulus is computed. Note that this is one larger than the        */
         /* most significant word of modulus.                                 */
         posInMod = modulus[0] + (Swt_LNWordType)1;

         /* The first position of number which to compare to the shifted      */
         /* modulus is computed.                                              */
         posInNum = posInMod + shiftWords;

         /* For each word of modulus, the shifted modulus is computed and     */
         /* compared to the corresponding word of number.                     */
         do
         {
            /* We assemble the current word of the shifted modulus from the   */
            /* words modulus[posInMod] and modulus[posInMod - 1].             */

            /* We test whether the current position in modulus is an allowed  */
            /* position.                                                      */
            if(posInMod <= modulus[0])
            {
               /* The current position in modulus is allowed. We take some    */
               /* bits from the word of modulus at that position.             */
               wordOfShiftedMod = modulus[posInMod] << shiftBits;
            }
            else
            {
               /* The current position in modulus is too high. We are at a    */
               /* "leading zero". So, all the bits which go into              */
               /* wordOfShiftedMod are zero.                                  */
               wordOfShiftedMod = (Swt_LNWordType)0;
            }

            /* The needed bits from modulus[posInMod - 1] are incorporated    */
            /* into wordOfShiftedMod. If we shift the modulus by complete     */
            /* words (which means "shiftBits == 0") or if posInMod            */
            /* is the lowest possible position (which means posInMod == 1)    */
            /* no bits from modulus[posInMod - 1] are needed.                 */
            if((shiftBits != (uint8)0) && (posInMod > (Swt_LNWordType)1))
            {
               wordOfShiftedMod |=
                  (Swt_LNWordType)
                  (
                  modulus[posInMod - (Swt_LNWordType)1] >>
                  ((uint8)SWT_LN_WORD_LEN_BITS - shiftBits)
                  );
            }

            /* We compute the word of number which to compare to the word     */
            /* of the shifted modulus. This is normally simply                */
            /* number[posInNum], but the position can be too high which means */
            /* that we are at a "leading zero" of number.                     */
            if(posInNum > number[0])
            {
               wordOfNumber = (Swt_LNWordType)0;
            }
            else
            {
               wordOfNumber = number[posInNum];
            }

            /* Now, we compare the word of the shifted modulus to the current */
            /* word of number.                                                */
            if(wordOfShiftedMod == wordOfNumber)
            {
               cmpNumMod = Swt_RC_EQUAL;
            }
            else if (wordOfShiftedMod > wordOfNumber)
            {
               cmpNumMod = Swt_RC_SMALLER;
            }
            else
            {
               cmpNumMod = Swt_RC_LARGER;
            }

            /* The positions are decreased by 1. */
            posInMod--;
            posInNum--;
         }
         while((Swt_RC_EQUAL == cmpNumMod)&&(posInMod > (Swt_LNWordType)0));

         /* If number is at least as large as the shifted modulus, we         */
         /* subtract modulus from number.                                     */
         if(cmpNumMod != Swt_RC_SMALLER)
         {
            wordOfShiftedMod = (Swt_LNWordType)0;

            carry = (Swt_LNWordType)0;

            /* When subtracting the shifted modulus from number we can        */
            /* skip the least significant words of number because the         */
            /* shifted modulus is 0, there. We compute the least              */
            /* significant word of number which is affected by the            */
            /* subtraction.                                                   */
            posInNum = (Swt_LNWordType)1 + shiftWords;

            /* We go through every word of the shifted modulus.    */
            for
               (
               posInMod = (Swt_LNWordType)1;
            posInMod <= modulus[0];
            posInMod++
               )
            {
               tempCarry = (uint8)0;

               wordOfShiftedMod |=
                  (Swt_LNWordType)(modulus[posInMod] << shiftBits);

               /* We test whether a carry forms at this position. This        */
               /* happens when "wordOfShiftedMod + carry > number[posInNum]". */
               /* Since we cannot test this condition directly because of     */
               /* possible overflows we use a more complicated looking test   */
               /* which actually does exactly what we want.                   */
               if(
                  (wordOfShiftedMod >= number[posInNum])      &&
                  (
                  (wordOfShiftedMod > number[posInNum]) ||
                  (carry > (Swt_LNWordType)0)
                  )
                  )
               {
                  tempCarry = (uint8)1;
               }

               /* We subtract "wordOfShiftedMod" and "carry" from the number. */
               number[posInNum] -= wordOfShiftedMod;
               number[posInNum] -= (Swt_LNWordType)carry;

               carry = (Swt_LNWordType)tempCarry;

               if(shiftBits == (uint8)0)
               {
                  wordOfShiftedMod = (Swt_LNWordType)0;
               }
               else
               {
                  wordOfShiftedMod = modulus[posInMod] >>
                     (uint8)((uint8)SWT_LN_WORD_LEN_BITS - shiftBits);
               }

               posInNum++;
            }                     /* for(posInMod = (Swt_LNWordType)1; ...) */

            /* Now we have to deal with leftover carries and a possible last  */
            /* word of the shifted modulus. Since the carry is at most one    */
            /* and wordOfShiftedMod is at least one bit shorter than the      */
            /* largest possible word (making it at most half as large), we    */
            /* can add both numbers in "carry" without overflow.              */
            carry += wordOfShiftedMod;

            /* Now we deal with the leftover carries. */
            while(carry != (Swt_LNWordType)0)
            {
               if(number[posInNum] >= carry)
               {
                  /* The carry has trickled away. */
                  number[posInNum] -= carry;
                  carry = (Swt_LNWordType)0;
               }
               else
               {
                  /* We have to take the carry one word upwards. */
                  number[posInNum] -= carry;
                  carry = (Swt_LNWordType)1;
               }
               posInNum++;
            }
         }                                       /* if(cmpNumMod >= (sint8)0) */

      }
      while ((context->LengthDifference) > (Swt_LNWordType)0);
   }

   Swt_LNNormalizeNumber(number);
}

#endif                   /* #if (SWT_RSA_USE_BARRETT == SWT_CFG_ON) #else */
#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
