/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_MD5.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Implementation of the message digest algorithm MD5            **
**              see RFC 1321.                                                 **
**                                                                            **
**  REMARKS   :                                                               **
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
#include "Swt_MD5.h"                        /* declarations of MD5 services */
#include "Swt_Common.h"            /* declarations of Swt common services */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

                               /* list of guards to prevent double definition */
#if (defined SWT_MD5_ROUNDS)
   #error SWT_MD5_ROUNDS already defined
#endif                                       /* if (defined SWT_MD5_ROUNDS) */

#define SWT_MD5_ROUNDS 64U                  /* Number of rounds used by MD5 */


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
SWT_STATIC_FUNC void Swt_MD5CountConvert
(
   uint32        Count,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) Convert
);

SWT_STATIC_FUNC void Swt_MD5Export
(
   CONSTP2CONST(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)           Digest
);

SWT_STATIC_FUNC void Swt_MD5Compress
(
   CONSTP2VAR(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)    Data
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
** FUNC-NAME      : Swt_MD5Init                                             **
**                                                                            **
** DESCRIPTION    : Initialize the provided MD5 context which contains        **
**                  all data for calculating a MD5 hashvalue.                 **
**                                                                            **
** PRECONDITIONS  : 'MD5Ctx' shall be a valid pointer (not checked)           **
**                  'MD5Ctx' shall point to a writeable MD5Context            **
**                           (not checked)                                    **
**                                                                            **
** POSTCONDITIONS : After return the context is initialized correctly for     **
**                  the first call of Swt_MD5Update.                        **
**                                                                            **
** PARAMETER      : MD5Ctx : Pointer to the context to initialize.            **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : Constant time for all inputs.                             **
**                                                                            **
*******************************************************************************/
void Swt_MD5Init
(
   CONSTP2VAR(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx
)
{
   MD5Ctx->Count = (uint32)0U;          /* Init the number of processed bytes */
                        /* Initialize the internal state of the hash function */
   MD5Ctx->State[0U] = (uint32) 0x67452301UL;
   MD5Ctx->State[1U] = (uint32) 0xefcdab89UL;
   MD5Ctx->State[2U] = (uint32) 0x98badcfeUL;
   MD5Ctx->State[3U] = (uint32) 0x10325476UL;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_MD5Update                                           **
**                                                                            **
** DESCRIPTION    : Updates the context MD5Ctx with the provided datablock.   **
**                                                                            **
** PRECONDITIONS  : 'MD5Ctx' shall be a valid pointer (not checked)           **
**                  'MD5Ctx' shall have been initialised by a successful call **
**                    to the function Swt_MD5Init() (not checked)           **
**                  'Block' shall be a valid pointer (not checked)            **
**                  'Block' shall point to at least 'BlockLength' bytes of    **
**                    readable memory (not checked)                           **
**                  'MD5Ctx->Count' + 'BlockLength' shall not exceed the      **
**                    maximal amount of bytes that can be hashed using this   **
**                    MD5 construction (not checked)                          **
**                                                                            **
** POSTCONDITIONS : An updated context according to the provided data.        **
**                                                                            **
** PARAMETER      : MD5Ctx : Pointer to the Swt_MD5Context to be updated    **
**                : Block : Pointer to the data to be hashed                  **
**                : BlockLength : Number of bytes to be hashed                **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** TIMING         : The timing is proportional to the number of bytes divided **
**                  by the MD5 blocksize.                                     **
**                                                                            **
*******************************************************************************/
void Swt_MD5Update
(
   CONSTP2VAR(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)    Block,
   const uint32           BlockLength
)
{
   P2CONST(uint8,AUTOMATIC,SC_FAR) p;                    /* pointer into data */
   uint32 left;                                       /* number of bytes left */
   uint8 copy;                                     /* number of bytes to copy */
   uint8 offset;                   /* offset into temporal buffer in blockCtx */

                               /* if there is no data, there is no work to do */
   if( BlockLength != (uint32) 0 )
   {
      p = Block;
      left = BlockLength;
      copy = (uint8) 0;

              /* get unprocessed bytes from last block and update the counter */
      offset = (uint8) ((MD5Ctx -> Count) & (uint32) 0x3f);
                                           /* Ignore a possible overflow here */
      MD5Ctx -> Count += BlockLength;

                                    /* if existent, process incomplete blocks */
      if( offset > (uint8) 0 )
      {
                                    /* find out how much data we need to copy */
         if( (uint32)((uint32)offset + BlockLength) >
             (uint32)SWT_MD5_BLOCK_SIZE )
         {
            copy = (uint8)SWT_MD5_BLOCK_SIZE - offset;
         }
         else
         {
                         /* cast is ok here: we tested dataBytes "< 64" above */
            copy = (uint8) BlockLength;

         }
                /* fill up the temporary buffer with as much data as possible */
         (void)Swt_CommonCopy( &MD5Ctx -> Partial[offset],
                                 p,
                                 (uint32)copy);
                                     /* look if we have one block to compress */
         if( (uint8)(offset + copy) < (uint8)SWT_MD5_BLOCK_SIZE )
         {
            /* if we still don't have enough data to fill a block, do nothing */
            /*         "mark" copy with special number to transport this case */
            /*                     a normal C routine would just exit here... */
            copy = (uint8) 0xff;

         }
         else
         {
                                /* we have one complete block, so compress it */
            p = &p[copy];
            left -= (uint32)copy;

            Swt_MD5Compress( MD5Ctx,
                               MD5Ctx -> Partial );

         }

      }
                                           /* look if copy was "marked" above */
      if( copy != (uint8) 0xff )
      {
                                                   /* process complete blocks */
         while( (left & (uint32)0xffffffc0UL) != (uint32) 0 )
         {

            Swt_MD5Compress( MD5Ctx, p );
            p = &p[SWT_MD5_BLOCK_SIZE];
            left -= (uint32)SWT_MD5_BLOCK_SIZE;
         }
                                              /* Check if there is still data */
         if( left > (uint32) 0U )
         {
                                             /* Copy data into partial buffer */
            (void)Swt_CommonCopy( MD5Ctx -> Partial, p, left );

         }

      }
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_MD5Finish                                           **
**                                                                            **
** DESCRIPTION    : Finalize the MD5 computation and determine the hash       **
**                  value represented by the provided context                 **
**                                                                            **
** PRECONDITIONS  : 'Ctx' shall be a valid pointer (not checked)              **
**                  'Ctx' shall point to a valid MD5Context that has been     **
**                        initialised by a successful call to the function    **
**                        Swt_MD5Init() (not checked)                       **
**                  'Digest' shall be a valid pointer (not checked)           **
**                  'Digest' shall point to a writeable region of memory      **
**                           of at least 16 bytes (not checked)               **
**                                                                            **
** POSTCONDITIONS : The hashvalue of the processed data is given in Digest.   **
**                                                                            **
** PARAMETER      : MD5Ctx : Valid pointer to a context which was updated     **
**                           with the data of which the hashvalue should be   **
**                           computed.                                        **
**                  Digest : Valid pointer to SWT_MD5_STATE_BYTES bytes     **
**                           which holds the hashvalue after the call         **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** TIMING         : Constant time for all inputs.                             **
**                                                                            **
*******************************************************************************/
void Swt_MD5Finish
(
   CONSTP2VAR(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)          Digest
)
{
   uint8 length[8U];               /* 64-bit representation of length of data */
   uint8 MD5Pad[SWT_MD5_BLOCK_SIZE];                   /* the padding block */

                                                  /* initialize the Pad block */
   MD5Pad[0] = (uint8)0x80;
   length[0] = (uint8)1;

   do
   {
      MD5Pad[length[0]] = (uint8)0;
      ++length[0];
   } while( length[0] < (uint8)SWT_MD5_BLOCK_SIZE );

                                                /* convert length information */
   Swt_MD5CountConvert( MD5Ctx -> Count, length );
                                          /* append padding to digest_context */
   Swt_MD5Update( MD5Ctx,
                    MD5Pad,
                    ((
                      (SWT_MD5_BLOCK_SIZE - 9U) - (MD5Ctx -> Count)
                     ) &
                     (
                      (uint32) 0x3f
                     )
                    ) + (uint32)1U );

                         /* append length information and complete last block */
   Swt_MD5Update( MD5Ctx, length, 8U );
                                                     /* export digest to user */
   Swt_MD5Export( MD5Ctx, Digest );

}
#define SWT_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_MD5CountConvert                                     **
**                                                                            **
** DESCRIPTION    : Converts the 32-bit count value of the MD5 computation    **
**                                                                            **
** PRECONDITIONS  : 'Count' shall be in range 0 .. 0x1fffffff (not checked)   **
**                  'Convert' shall be a valid pointer (not checked)          **
**                  'Convert' shall point to at least 8 bytes of writeable    **
**                            memory (not checked)                            **
**                                                                            **
** POSTCONDITIONS : The block holds the data converted according to MD5       **
**                  standard in little-endian format                          **
**                                                                            **
** PARAMETER      : Count : The number of processed bytes.                    **
**                  Convert : 8 byte memory block holding the number of       **
**                            of processed bytes according to MD5.            **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** TIMING         : Constant time for all input.                              **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_MD5CountConvert
(
   uint32        Count,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) Convert
)
{
                                                         /* convert into bits */
   Count <<= 3U;

                                                           /* Copy the result */
   /* ISO-C says that downcasting takes the lowest 8 bits of the 32-bit value */
   Convert[0U] = (uint8)(Count       );
   Convert[1U] = (uint8)(Count >>  8U);
   Convert[2U] = (uint8)(Count >> 16U);
   Convert[3U] = (uint8)(Count >> 24U);
   Convert[4U] = (uint8)0;
   Convert[5U] = (uint8)0;
   Convert[6U] = (uint8)0;
   Convert[7U] = (uint8)0;

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_MD5Export                                           **
**                                                                            **
** DESCRIPTION    : Convert the provided context into a MD5 hash value.       **
**                                                                            **
** PRECONDITIONS  : 'Ctx' shall be a valid pointer (not checked)              **
**                  'Ctx' shall have been initialised by a successful call to **
**                        the function Swt_MD5Init() (not checked)          **
**                  'Digest' shall be a valid pointer (not checked)           **
**                  'Digest' shall point to a writeable region of memory of   **
**                    at least 16 bytes (not checked)                         **
**                                                                            **
** POSTCONDITIONS : Digest holds the hashvalue of the processed data          **
**                  expressed as little-endian.                               **
**                                                                            **
** PRECONDITIONS  : Ctx  : Is valid context used to process all data          **
**                  Digest : Valid pointer to SWT_MD5_STATE_BYTES bytes     **
**                   which holds the hashvalue after the call (not checked)   **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** TIMING         : Constant time for all input.                              **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_MD5Export
(
   CONSTP2CONST(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)           Digest
)
{
  uint8_least Index;                                         /* loop variable */
  uint8_least TmpIndex;                     /* tmp space to save loop results */

  Index = (uint8_least)0;
  do
  {
     TmpIndex = Index;
     TmpIndex <<= 2U;
     Digest[TmpIndex] = (uint8)(MD5Ctx->State[Index]       );
     TmpIndex++;
     Digest[TmpIndex] = (uint8)(MD5Ctx->State[Index] >> 8U );
     TmpIndex++;
     Digest[TmpIndex] = (uint8)(MD5Ctx->State[Index] >> 16U);
     TmpIndex++;
     Digest[TmpIndex] = (uint8)(MD5Ctx->State[Index] >> 24U);

    Index++;
  } while (Index < (uint8_least)(SWT_MD5_STATE_BYTES >> 2U));

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_MD5Compress                                         **
**                                                                            **
** DESCRIPTION    : Internal MD5 compression function.                        **
**                                                                            **
** PRECONDITIONS  : 'Ctx' shall be a valid pointer (not checked)              **
**                  'Ctx' shall have been initialised by a successful call    **
**                        to the function Swt_MD5Init() (not checked)       **
**                  'Data' shall be a valid pointer (not checked)             **
**                  'Data' shall point to at least SWT_SHA1_BLOCK_SIZE      **
**                         bytes of readable memory (not checked)             **
**                                                                            **
** POSTCONDITIONS : Context which was updated according to the processed data.**
**                                                                            **
** PARAMETER      : Ctx : Pointer to the data block to operate on             **
**                  Data : Data block to update the MD5 context               **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** TIMING         : Constant time for all input                               **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_MD5Compress
(
   CONSTP2VAR(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)    Data
)
{
   uint32 a;                     /* four variables to hold the internal state */
   uint32 b;
   uint32 c;
   uint32 d;
   uint32 t;                                        /* one temporary variable */
   uint32 W[(SWT_MD5_BLOCK_SIZE >> 2U)];      /* internal copy of user data */
   uint8 i;                                                  /* loop variable */
   uint8 k;                        /* variable for internal loop calculations */
   uint8 l;                        /* variable for internal loop calculations */


/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_32BIT
#include "MemMap.h"
   /**
    * These unique values will be added each round.
    * They are constructed as follows:
    * y[i] = first 32 bits of binary value
    *        abs( sin( j + 1 ) )
    * where j is in radians and "abs" denotes the absolute value.
    * It is therefore unlikely to compress this table further.
    * size: 256 bytes
    */
   SWT_STATIC_VAR const uint32 y[64U] = {
                                                                   /* round 1 */
     (uint32)0xd76aa478UL, (uint32)0xe8c7b756UL,
     (uint32)0x242070dbUL, (uint32)0xc1bdceeeUL,
     (uint32)0xf57c0fafUL, (uint32)0x4787c62aUL,
     (uint32)0xa8304613UL, (uint32)0xfd469501UL,
     (uint32)0x698098d8UL, (uint32)0x8b44f7afUL,
     (uint32)0xffff5bb1UL, (uint32)0x895cd7beUL,
     (uint32)0x6b901122UL, (uint32)0xfd987193UL,
     (uint32)0xa679438eUL, (uint32)0x49b40821UL,
                                                                   /* round 2 */
     (uint32)0xf61e2562UL, (uint32)0xc040b340UL,
     (uint32)0x265e5a51UL, (uint32)0xe9b6c7aaUL,
     (uint32)0xd62f105dUL, (uint32)0x02441453UL,
     (uint32)0xd8a1e681UL, (uint32)0xe7d3fbc8UL,
     (uint32)0x21e1cde6UL, (uint32)0xc33707d6UL,
     (uint32)0xf4d50d87UL, (uint32)0x455a14edUL,
     (uint32)0xa9e3e905UL, (uint32)0xfcefa3f8UL,
     (uint32)0x676f02d9UL, (uint32)0x8d2a4c8aUL,
                                                                   /* round 3 */
     (uint32)0xfffa3942UL, (uint32)0x8771f681UL,
     (uint32)0x6d9d6122UL, (uint32)0xfde5380cUL,
     (uint32)0xa4beea44UL, (uint32)0x4bdecfa9UL,
     (uint32)0xf6bb4b60UL, (uint32)0xbebfbc70UL,
     (uint32)0x289b7ec6UL, (uint32)0xeaa127faUL,
     (uint32)0xd4ef3085UL, (uint32)0x04881d05UL,
     (uint32)0xd9d4d039UL, (uint32)0xe6db99e5UL,
     (uint32)0x1fa27cf8UL, (uint32)0xc4ac5665UL,
                                                                   /* round 4 */
     (uint32)0xf4292244UL, (uint32)0x432aff97UL,
     (uint32)0xab9423a7UL, (uint32)0xfc93a039UL,
     (uint32)0x655b59c3UL, (uint32)0x8f0ccc92UL,
     (uint32)0xffeff47dUL, (uint32)0x85845dd1UL,
     (uint32)0x6fa87e4fUL, (uint32)0xfe2ce6e0UL,
     (uint32)0xa3014314UL, (uint32)0x4e0811a1UL,
     (uint32)0xf7537e82UL, (uint32)0xbd3af235UL,
     (uint32)0x2ad7d2bbUL, (uint32)0xeb86d391UL
   };
#define SWT_STOP_SEC_CONST_32BIT
#include "MemMap.h"


/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
   /**
    * Thess numbers define the access order to the words.
    * The table is coded to save space: each 4-bit nibble represents
    * one value.
    * The first nibble ist packed into the first higher nibble,
    * the second in the lower nibble.
    * size: 32 bytes
    */
   SWT_STATIC_VAR const uint8 z[32u] = {
     (uint8)0x01, (uint8)0x23, (uint8)0x45, (uint8)0x67,
     (uint8)0x89, (uint8)0xab, (uint8)0xcd, (uint8)0xef,
     (uint8)0x16, (uint8)0xb0, (uint8)0x5a, (uint8)0xf4,
     (uint8)0x9e, (uint8)0x38, (uint8)0xd2, (uint8)0x7c,
     (uint8)0x58, (uint8)0xbe, (uint8)0x14, (uint8)0x7a,
     (uint8)0xd0, (uint8)0x36, (uint8)0x9c, (uint8)0xf2,
     (uint8)0x07, (uint8)0xe5, (uint8)0xc3, (uint8)0xa1,
     (uint8)0x8f, (uint8)0x6d, (uint8)0x4b, (uint8)0x29
   };

   /**
    * This table contains the constants by which to rotate.
    * Each round just 4 numbers are used.
    * size: 16 bytes
    */
   SWT_STATIC_VAR const uint8 s[16u] = {
     (uint8)0x07, (uint8)0x0c, (uint8)0x11, (uint8)0x16,
     (uint8)0x05, (uint8)0x09, (uint8)0x0e, (uint8)0x14,
     (uint8)0x04, (uint8)0x0b, (uint8)0x10, (uint8)0x17,
     (uint8)0x06, (uint8)0x0a, (uint8)0x0f, (uint8)0x15
   };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"

   /* Copy global state to local state                                        */
   a = MD5Ctx -> State[0U];
   b = MD5Ctx -> State[1U];
   c = MD5Ctx -> State[2U];
   d = MD5Ctx -> State[3U];

                                                 /* copy data to local buffer */
   (void)Swt_CommonCopy( W, Data, (uint32)SWT_MD5_BLOCK_SIZE );

#if CPU_BYTE_ORDER == HIGH_BYTE_FIRST
   i = (uint8) 0;
   do
   {
      W[i] = (W[i] << 16U) | (W[i] >> 16U);
      W[i] = ((W[i] & (uint32)0xff00ff00) >> 8U) |
             ((W[i] & (uint32)0x00ff00ff) << 8U);
      i++;
   }
   while( (SWT_MD5_BLOCK_SIZE >> 2U) > i );
#endif                                /* if CPU_BYTE_ORDER == HIGH_BYTE_FIRST */



   /* The message digest transformation loop                                  */
   i = (uint8) 0;
   do
   {
                          /* precalculations: select index into nibble-arrays */
                               /* k will contain the word access order number */
      l = z[((uint8)(i >> 1))];
      if( (i & (uint8) 0x01) != (uint8)0U )
      {
                                    /* not divisible by 2: choose lowe nibble */
         k = (uint8) (l & (uint8)0x0f);
      }
      else
      {
                                      /* divisible by 2: choose higher nibble */
         k = (uint8)(l >> 4);
      }

                          /* round transformation, start with round functions */
      l = (uint8)(i >> 4);            /* divide by 16: 4 rounds with 16 steps */


      /* Round transformation                                                 */
      switch( l )
      {
         /* Round dependent part first                                        */
         case 0:
                                                            /* rounds 0 .. 15 */
            t = (uint32) ((uint32) (c ^ d) &  b) ^ d;
         break;

         case 1:
                                                           /* rounds 16 .. 31 */
            t = (uint32) (b & d) | (uint32) (c & (uint32) (~d));
            break;

         case 2:
                                                           /* rounds 32 .. 47 */
            t = (uint32) (b ^ c) ^ d;
            break;

         default:
                                                           /* rounds 48 .. 63 */
            t = c ^ (uint32) (b | (uint32) (~d));
            break;

      }

                                                    /* round independent part */
      t += (uint32) (a + ( (uint32) (W[k] + y[i])));
      a = d;                              /* permute the words for next round */
      d = c;
      c = b;
                                          /* b = b + (t shifted left by s[i]) */
      k = s[ (l << 2) + (i & (uint8) 0x03) ];
      b += (uint32) ( ((uint32)(t << k)) | ((uint32) (t >> ((uint8)32 - k))) );

      i++;
   }
   while(i != (uint8) SWT_MD5_ROUNDS );

   /* Copy internal state back to MD5Ctx                                      */
   MD5Ctx -> State[0U] += a;
   MD5Ctx -> State[1U] += b;
   MD5Ctx -> State[2U] += c;
   MD5Ctx -> State[3U] += d;

}

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
