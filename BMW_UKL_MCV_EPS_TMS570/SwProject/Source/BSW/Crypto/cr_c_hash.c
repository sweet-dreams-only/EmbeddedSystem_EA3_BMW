/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_c_hash.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : hash routines                                                 **
**                                                                            **
**  REMARKS   : SHA256 Hash Algorithm                                         **
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
** jd           Jochen Decker              3SOFT                              **
** mg           Matthias Galota            3SOFT                              **
** am           Alexander Much             3SOFT                              **
** sc           Juergen Scherg             3SOFT                              **
** fs           Frank Stamm                3SOFT                              **
** gema         Markus Gerngross           MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V5.0.6: 06.09.2011,  ft : CR71027: Crypto: Don't ignore possible error 
 *                           messages or return values 
 * V5.0.5: 27.01.2010, gema: CR70529: Crypto: Compiler switches shall have 
 *                           defined values
 * V5.0.4: 05.07.2007, mg : S12X signature check problems fixed with
 *                          interruption turned on
 * V5.0.1: 20.12.2006, mg : CR60916: fixed signature check problems on S12X
 * V5.0.0: 21.09.2006, mg : code clean-ups
 *         11.08.2006, mg : added cancelation functionality, modified macro
 *                          syntax, using DET, made functions return immediately
 *                          after an error, improved formatting, removed
 *                          mem_util, removed CR_SIMPLE_OPS, removed redundant
 *                          casts
 * V4.1.0: 22.06.2006, mg : no changes
 * V4.0.0: 03.04.2006, mg : moved configuration options to Crypto_Cfg.h, key
 *                          length configurable independently for authentication
 *                          and signature, cleaned up cr_c_hash.c,
 *                          removed compiler warnings
 *         22.02.2006, fs : added coding functions
 * V3.3.1: 11.11.2005, jd : added support for TriCore, ST30, MAC7100 and MB91
 * V3.3.0: 28.10.2005, jd : adapted to programming guidelines 1.6.1,
 *                          incorporated memory mappings of SC6.5,
 *                          added jumptable for access from application space
 * V3.2.1: 22.07.2005, mg : adapted header files for SC6
 * V3.2.0: 22.07.2005, am : changed type infrastructure from a mixed near/far
 *                          environment to a pure far API
 * V3.1.0: 03.05.2005, mg : adapted file header
 * V3.0.0: 17.02.2005, am : adopted to SC4, MISRA cleanups
 * V2.0.0: 08.10.2004, sc : Adoption from Acryl 2.1. Adapted to 16 bit CPUs.
 */

/**************************************************************************************************************************/
/* Nxtr Version Control:
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
10/05/16     EA3#3     ABS        Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
**************************************************************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */
#include "cr_c_hash.h"             /* hash routines declarations              */
#include "cr_c_data.h"             /* common global data                      */
#include "cr_c_callback.h"         /* interruption per callback defs+routines */
#include "cr_c_cancel.h"           /* cancelation of computation              */
/* ------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Added for SHA-256 hash algorithm
 */
/* Patch code  - START */
#include "Cal.h"
/* Patch code  - END */
/* ------------------ NXTR PATCH END -------------------------------------*/
/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

typedef union   /* Local data type for state buffer in interruptable mode     */
{               /* for subroutine CR_C_hash()                                 */
   struct       /* all local variables which have to be saved on interruption */
   {            /* must be allocated in this structure                        */
      uint8  nResume;        /* finishing-flag. must be 1st byte in structure */
      uint16 akt_nr;         /* number of currently processed block           */
   } s;
   uint8 state[CR_DEF_HASH_STATESIZE];           /* guarantees minimum length */
} CR_LCL_HashIntrBuffer_t;

/* ------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed because MD5 is no longer used.
 */
#if 0
/* Original code  - START */
typedef union  /* Local data type for state buffer in interruptable mode      */
{              /* for subroutine CR_C_md5hash()                               */
   struct      /* all local variables, which have to be saved on interruption */
   {           /* must be allocated in this structure                         */
      uint8  nResume;        /* finishing-flag. must be 1st byte in structure */
      uint32 loops;          /* saved loop counter                            */
      uint8  blocks;         /* used in loop mode from 0 to 10                */
   } s;
   uint8 state[CR_DEF_HASH_STATESIZE];           /* guarantees minimum length */
} CR_LCL_MD5IntrBuffer_t;
/* Original code  - END */
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed because MD5 is no longer used
 */
#if 0
/* Original code - START */
#define CRYPTO_START_SEC_CODE
#include "MemMap.h"
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_md5transform
(
   void
);
#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/
#define CRYPTO_START_SEC_CODE
#include "MemMap.h"
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed because MD5 is no longer used
 */
#if 0
/* Original code - START */
/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_ST_md5transform                                        **
**                                                                            **
** DESCRIPTION   :  does the MD5 transformation of a full buffer              **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  void                                                      **
**                                                                            **
** RETURN        :  CR_C_RC_OK       if the computation finished successfully **
**                  CR_C_RC_CANCELED if the computation has been canceled     **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_md5transform
(
   void
)
{
   uint32 aa;                    /* temporary storage for state variable a    */
   uint32 bb;                    /* temporary storage for state variable b    */
   uint32 cc;                    /* temporary storage for state variable c    */
   uint32 dd;                    /* temporary storage for state variable d    */

   uint32 X[16];                 /* internal buffer to work with: 64 byte     */

   uint32 z;                     /* loop invariant: MD5 round function result */
   uint8  rot;                   /* loop invariant: bit rotation              */

   uint8_least i;                /* loop counter                              */
   uint8_least j;                /* loop counter                              */
   uint8_least r;                /* loop counter                              */
   uint8       k;                /* loop counter                              */


#if (CR_DEF_USE_INTERRUPTION == STD_ON) && (defined CR_MD5_LEVEL_0)
   CR_MD5_LEVEL_0;              /* MD5 level 0 interruption (transform start) */
#endif    /* if (CR_DEF_USE_INTERRUPTION == STD_ON) && (defined CR_MD5_LEVEL_0) */

   /* [1. initialize variables]                                               */
   aa = CR_C_s3.nMD5A;         /* copy state variables to local temp variable */
   bb = CR_C_s3.nMD5B;         /* copy state variables to local temp variable */
   cc = CR_C_s3.nMD5C;         /* copy state variables to local temp variable */
   dd = CR_C_s3.nMD5D;         /* copy state variables to local temp variable */

   j = 0;                      /* initialize byte counter                     */
   z = 0;                      /* initialize loop invariant                   */

   /* [2. initialize local state buffer (endian dependent)]                   */
   i =              0;         /* start with first word                       */
   do
   {
      X[i] = 0;                /* initialize the first word                   */
      k    = 0;                /* start with first byte                       */
      do
      {
         /* assign the input word to the internal buffer and
          * do an endianess-reversal on big-endian machines at the same time  */
         X[i] |=
               (uint32)CR_C_s3.md5buf[j + k] << (uint8)(k << 3U);
         ++k;                             /* proceed with next byte           */

      } while (k != 4);                   /* until all 4 bytes are processed  */
      j += 4;                             /* proceed with the next 4 bytes    */
      ++i;                                /* continue with next word          */

      CR_C_CheckCancelRequest();          /* are we canceled? then return     */
   } while (i != 16);                     /* until all 16 words are processed */

   /* [3. Do the MD5 transformation on the local state]                       */
   i = 0;                                  /* start with first word           */
   r = 0;                                  /* start with first round function */
   do                 /* MD5 uses 4 different round functions, loop over them */
   {
                              /* initialize to standard default value         */
      k = CR_C_s1.rundenstart[r];
      j = 0;                  /* initialize to first MD5 transformation round */
      do                      /* MD5 consists of 16 rounds, loop over them    */
      {
                                         /* choose the correct round function */
         if (r == 0)                     /* apply first round function        */
         {
            z = (uint32)(bb & cc) |
                (uint32)((uint32)(~bb) & dd);
         }
         else if (r == 1)                      /* apply second round function */
         {
            z = (uint32)(bb & dd) |
                (uint32)(cc & (uint32)(~dd));
         }
         else if (r == 2)                      /* apply third round function  */
         {
            z = (uint32)(bb ^ cc) ^ dd;
         }
         else if (r == 3)                      /* apply fourth round function */
         {
            z = cc ^ (uint32)(bb | (uint32)(~dd));
         }
         else      /* empty else-construct for MISRA-C:1998, Rule 60          */
         {
                   /* if we are here, there has been an error                 */
            ;
         }
                   /* precalculate round invariant calculations and add to h  */
         z += aa + (uint32)(X[k] + CR_C_s1.T[i]);

                   /* calculate rotation index from the MD5 shift table       */
         rot = CR_C_s1.shifts[(r << 2U) + (j & (uint8_least)3)];

                   /* and rotate by this index                                */
         z = bb + ((uint32)(z << rot) | (uint32)(z >> (uint8)(32 - rot)));

                   /* do the round variable exchange at the end of each round */
         aa = dd;                                /* round permutation: a <- d */
         dd = cc;                                /* round permutation: d <- c */
         cc = bb;                                /* round permutation: c <- b */
         bb = z;                                 /* round permutation: b <- z */
                   /* increase k by round dependent value and limit to 0...16 */
         k = (uint8)(k + CR_C_s1.rundenink[r]) & (uint8)0x0f;
         ++i;                                         /* operate on next word */

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && (defined CR_MD5_LEVEL_2)
         CR_MD5_LEVEL_2;                          /* MD5 level 2 interruption */
#endif       /* if (CR_DEF_USE_INTERRUPTION == STD_ON) && (defined CR_MD5_LEVEL2) */

         ++j;                                /* next round                    */

         CR_C_CheckCancelRequest();          /* are we canceled? then return  */

      } while (j != 16);                     /* until all rounds are finished */

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && (defined CR_MD5_LEVEL_1)
      CR_MD5_LEVEL_1; /* MD5 level 1 interruption */
#endif      /* if (CR_DEF_USE_INTERRUPTION == STD_ON) && (defined CR_MD5_LEVEL_1) */

      ++r;                          /* take next round function               */

   } while (r != 4);                /* until all subrounds are processed      */

   /* [4. add results back to global state]                                   */
   CR_C_s3.nMD5A += aa;             /* add calculated a value to global state */
   CR_C_s3.nMD5B += bb;             /* add calculated b value to global state */
   CR_C_s3.nMD5C += cc;             /* add calculated c value to global state */
   CR_C_s3.nMD5D += dd;             /* add calculated d value to global state */

   CR_C_s3.nMD5buflen = 0;          /* finished: reset buffer length          */

   return CR_C_RC_OK;
}
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed because MD5 is no longer used
 */
 #if 0
/* Original code - START */
/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_C_md5init                                              **
**                                                                            **
** DESCRIPTION   :  initializes the MD5 registers                             **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  void                                                      **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
void CR_C_md5init
(
   void
)
{
   CR_C_s3.nMD5A = (uint32)0x67452301UL;     /* initialize state variable a   */
   CR_C_s3.nMD5B = (uint32)0xefcdab89UL;     /* initialize state variable b   */
   CR_C_s3.nMD5C = (uint32)0x98badcfeUL;     /* initialize state variable c   */
   CR_C_s3.nMD5D = (uint32)0x10325476UL;     /* initialize state variable d   */
   CR_C_s3.nMD5buflen = 0;                   /* set actual buffer length to 0 */
   CR_C_s3.nMD5totallen = 0;                 /* set global buffer length to 0 */
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_C_md5hash                                              **
**                                                                            **
** DESCRIPTION   :  continues hashing with a given text                       **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  cycleCountPtr - cycle counter                             **
**                  text        - pointer to chars to be hashed               **
**                  length      - length of buffer to be hashed               **
**                  state       - internal state                              **
**                                                                            **
** RETURN        :  CR_C_RC_OK        sucessfully finished                    **
**                  CR_C_RC_NF        not finished yet                        **
**                  CR_C_RC_CANCELED  if the computation has been canceled    **
**                                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
CR_C_RC_t CR_C_md5hash
(
   CR_fp_uint16 cycleCountPtr,
   CR_fpc_uint8 text,
   uint32 const length,
   CR_fp_uint8  state
)
{
   CR_C_RC_t RetVal;                      /* return value                     */
   uint32 i;                              /* loop counter                     */

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
    (CR_DEF_USE_TRIGGER_COP == STD_OFF)
   CR_LCL_MD5IntrBuffer_t u;              /* internal buffer for interruption */
   uint32 k;                              /* loop counter                     */
   uint8 bState;
#endif                                /* if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
                                       * (CR_DEF_USE_TRIGGER_COP == STD_OFF)      */

   RetVal = CR_C_RC_OK;             /* initialise the return value            */

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
    (CR_DEF_USE_TRIGGER_COP == STD_OFF)

                 /* if interruption by cycle counter is used, set bState to 1 */
   if ((cycleCountPtr != CR_NULL) && (*cycleCountPtr != 0))
   {
      bState = 1;
   }
   else
   {
      bState = 0;
   }

   if (state != CR_NULL)                 /* do we have a state?               */
   {
      if (state[0] != 0)                 /* check if we are re-entered now    */
      {                                  /* restore state                     */
         /* CR71023: Don't ignore possible error messages or return values:   */
         /* The operation memcpy does only return a pointer but no error code */
         /* => No error handling required, use of this void cast is OK        */
         (void) CR_C_memcpy ((CR_fp_void)&u, (CR_fp_void)state,
                             (uint16)CR_DEF_MD5HASH_STATESIZE);
      }
      else                               /* not re-entered, first call        */
      {
         u.s.loops = 0;                  /* initialise the state              */
      }
      u.s.blocks = 0;                    /* reset internal block counter      */
      k = u.s.loops;                     /* start from the saved loop counter */
      while (k < length)
      {
         /* copy this byte. Special macro used for array indexing because of  */
         /* a compiler limitation in CodeWarrior for S12X.                    */
         CR_C_s3.md5buf[CR_C_s3.nMD5buflen] =
                                           CR_C_LARGE_BYTE_ARRAY_ACCESS(text,k);
         ++CR_C_s3.nMD5buflen;           /* adjust global length counter      */
                                         /* do we have a full buffer?         */
         if (CR_C_s3.nMD5buflen == 64)
         {
            RetVal = CR_ST_md5transform ();     /* yes, then transform it     */

            CR_C_RETURN_IF_CANCELED(RetVal); /* sub-func canceled? then return*/

            ++u.s.blocks;                /* next block                        */
                          /* if 10 blocks are hashed or everything was hashed */
            if ((u.s.blocks == 10) ||
                ((uint32)(k + 1) == length))
            {
               u.s.blocks = 0;                /* reset internal block counter */

               if (bState != 0)
               {
                  if (*cycleCountPtr != 0)   /* decrease cycles left          */
                  {
                     --*cycleCountPtr;
                  }
                  if (*cycleCountPtr == 0)   /* all cycles used?              */
                  {
                     u.s.nResume = 1;                     /* indicate: resumed*/
                     u.s.loops = (uint32)(k + 1);         /* save counter     */
                                                          /* save state       */
                     /* CR71023: Don't ignore possible error messages or      */
					 /* return values: The operation memcpy does only return  */
					 /* a pointer but no error code                           */
                     /* => No error handling required                         */
					 /* => Use of this void cast is OK                        */
                     (void) CR_C_memcpy ((CR_fp_void)state, (CR_fp_void)&u,
                                         (uint16)CR_DEF_MD5HASH_STATESIZE);
                     return CR_C_RC_NF;                /* return not finished */
                  }
               }
            }
         }
         ++k;
      }

      CR_C_s3.nMD5totallen += length;        /* adjust total buffer length    */
      state[0] = 0;                          /* finish interruption mechanism */

   }
   else
   {
#endif                              /* if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
                                     * (CR_DEF_USE_TRIGGER_COP == STD_OFF)        */

      CR_C_CheckCancelRequest();  /* are we canceled? then return             */

                                  /* hash without interruption                */
      i = 0;                      /* start with first byte                    */
      while (i < length)          /* until all length bytes are processed     */
      {
         /* copy this byte. Special macro used for array indexing because of  */
         /* a compiler limitation in CodeWarrior for S12X.                    */
         CR_C_s3.md5buf[CR_C_s3.nMD5buflen] =
                                           CR_C_LARGE_BYTE_ARRAY_ACCESS(text,i);

         ++CR_C_s3.nMD5buflen;                /* adjust global length counter */
                                              /* we have a full buffer?       */

         if ((CR_C_s3.nMD5buflen  & (uint32)0xf) == 0)
         {
            CR_C_CheckCancelRequest();        /* are we canceled? then return */

            if (CR_C_s3.nMD5buflen == 64)
            {
               RetVal = CR_ST_md5transform ();  /* yes, then transform it     */

                                            /* sub-func canceled? then return */
               CR_C_RETURN_IF_CANCELED(RetVal);
            }
         }
                                             /* if (nMD5buflen == 64)         */
         ++i;                                /* take next byte                */
      }
      CR_C_s3.nMD5totallen += length;        /* adjust total buffer length    */

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
    (CR_DEF_USE_TRIGGER_COP == STD_OFF)
   }
#endif /* if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
             (CR_DEF_USE_TRIGGER_COP == STD_OFF) */

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_C_md5end                                               **
**                                                                            **
** DESCRIPTION   :  finalizes the hash operation and returns the              **
**                  MD5 hash value                                            **
**                                                                            **
** PRECONDITIONS :  Hashing must have been initialized and hash must have     **
**                  been called at least once.                                **
**                                                                            **
** PARAMETERS    :  result - buffer for hash value, 16 Bytes                  **
**                                                                            **
** RETURN        :  CR_C_RC_OK       if the computation finished successfully **
**                  CR_C_RC_CANCELED if the computation has been canceled     **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
CR_C_RC_t CR_C_md5end
(
   CR_fp_uint8 result
)
{
   CR_C_RC_t RetVal;
   uint8_least i;                            /* loop variable                 */
   uint8_least j;

                                             /* add a single bit to buffer    */
   CR_C_s3.md5buf[CR_C_s3.nMD5buflen] = 0x80;
   ++CR_C_s3.nMD5buflen;                     /* increase global buffer length */

   if (CR_C_s3.nMD5buflen == 64)             /* we have a full buffer?        */
   {
      RetVal = CR_ST_md5transform();         /* then do a transformation      */

      CR_C_RETURN_IF_CANCELED(RetVal);      /* sub-func canceled? then return */
   }

   while (CR_C_s3.nMD5buflen != 56)          /* fill buffer with 0x00         */
   {                                         /* until 56 bytes long           */
                                             /* fill this byte                */
      CR_C_s3.md5buf[CR_C_s3.nMD5buflen] = 0;
      ++CR_C_s3.nMD5buflen;                  /* go to next byte               */

      if ((CR_C_s3.nMD5buflen  & (uint32)0xfU) == 0)
      {
         CR_C_CheckCancelRequest();          /* are we canceled? then return  */

         if (CR_C_s3.nMD5buflen == 64)
         {
            RetVal = CR_ST_md5transform ();  /* yes, then transform it        */

            CR_C_RETURN_IF_CANCELED(RetVal); /* sub-func canceled? then return*/
         }
      }
   }

     /* append the total size: tricky, since this is possibly endian-reversed
                                                            64-bit arithmetic */
   CR_C_s3.md5buf[56] = (uint8)(CR_C_s3.nMD5totallen << 3U);
   i = 0;                                 /* have to fill 4 8-bit values      */
   do
   {
      CR_C_s3.md5buf[57 + i] =
         (uint8)(CR_C_s3.nMD5totallen >> (uint8)(5 + (i << 3U)));
      ++i;                                /* take next byte                   */
   } while (i != 4);                      /* until 64-bit value is completed  */

                             /* contruct a full buffer by filling with zeroes */
   i = 61;                   /* start with byte 61                            */
   do
   {
      CR_C_s3.md5buf[i] = 0;        /* fill this byte                         */
      ++i;                          /* take next byte                         */
   } while (i != 64);               /* until the buffer is completed          */

   CR_C_CheckCancelRequest();               /* are we canceled? then return   */

   RetVal = CR_ST_md5transform();           /* do a last transformation       */

   CR_C_RETURN_IF_CANCELED(RetVal);         /* sub-func canceled? then return */

                                    /* copy the hash value into result buffer */
   for( i = 0; i < 4; ++i )
   {
      CR_C_CheckCancelRequest();            /* are we canceled? then return   */

      j = i << 3U;

      result[i     ] = (uint8)(CR_C_s3.nMD5A >> j);
      result[i + 4 ] = (uint8)(CR_C_s3.nMD5B >> j);
      result[i + 8 ] = (uint8)(CR_C_s3.nMD5C >> j);
      result[i + 12] = (uint8)(CR_C_s3.nMD5D >> j);
   }

   CR_C_CheckCancelRequest();               /* are we canceled? then return   */

   return CR_C_RC_OK;
}
/* Original code - END */
#endif

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_C_hash                                                 **
**                                                                            **
** DESCRIPTION   :  returns an SHA256 hash value for a given input, which can be **
**                  made up of multiple blocks                                **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  cycleCountPtr - pointer to cycle counter                  **
**                  numBlocks   - number of blocks to be hashed               **
**                  textPtr       - array of blocks to be hashed              **
**                  length     - pointer to array of block lengths            **
**                  hashRes     - result of the operation                     **
**                  state       - internal state                              **
**                                                                            **
** RETURN        :  CR_C_RC_OK        on success                              **
**                  CR_C_RC_NF        not finished yet                        **
**                  CR_C_RC_CANCELED  if the computation has been canceled    **
**                                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
CR_C_RC_t CR_C_hash
(
   CR_fp_uint16    cycleCountPtr,
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fp_uint8     hashRes,
   CR_fp_uint8     state
)
{
   CR_C_RC_t RetVal;                               /* return value            */
   uint32 i;                                       /* loop counter            */

  /* ----- NXTR PATCH START -----
   * Added By: K. Smith (Nxtr)
   * Date Added: 27Sep16
   *
   * Reason: Declare local buffers used for the hashing of the passed data. However
   * these buffers only need to be temporary because the results and hash values 
   * will be passed back to the calling functions. 
   */
   Cal_HashCtxBufType CalHashBuffAry_Cnt_T_u32; /* Type is generated as an array of uint32 */
   uint32 HashSize_Cnt_T_u32;
   Cal_ReturnType CalReturn_Cnt_T_enum;
   /* ----- NXTR PATCH END ----- */

   
#if (CR_DEF_USE_INTERRUPTION == STD_ON) &&\
    (CR_DEF_USE_TRIGGER_COP == STD_OFF)
   CR_LCL_HashIntrBuffer_t u;                      /* buffer for interruption */

#endif                             /* (CR_DEF_USE_INTERRUPTION == STD_ON) && \
                                    * (CR_DEF_USE_TRIGGER_COP == STD_OFF)         */

   RetVal = CR_C_RC_OK;            /* initialize the return value             */

#if (CR_DEF_USE_INTERRUPTION == STD_ON) &&\
    (CR_DEF_USE_TRIGGER_COP == STD_OFF)

   if (state != CR_NULL)                /* do we have a state ?               */
   {
      if (state[0] != 0)                /* check if we are re-entered now     */
      {
         /* CR71023: Don't ignore possible error messages or return values:   */
         /* The operation memcpy does only return a pointer but no error code */
         /* => No error handling required, use of this void cast is OK        */
         (void) CR_C_memcpy (&u, state,  /* restore old state                  */
                             (uint32)CR_DEF_HASH_STATESIZE);
      }
      else                               /* not re-entered, first call        */
      {
         u.s.akt_nr = 0;                 /* reset akt dataset number          */
         u.s.nResume = 0;                /* not coming back from interruption */
         /* ----- NXTR PATCH START -----
          * Added By: K. Smith (Nxtr)
          * Date Added: 27Sep16
          *
          * Reason: Use the Cal abstraction to initialize the hash routine and buffer
          */
		#if 0
         /* ----- Original Code Start ----- */
                                /* hash without interruption            */
         CR_C_md5init ();                /* initialize the hash                  */
                                /* process all blocks                   */
         /* ----- Original Code End ----- */
		#endif
         /* ----- Patch Code Start ------ */
         CalReturn_Cnt_T_enum = Cal_HashStart(CalHashConfig, CalHashBuffAry_Cnt_T_u32);
         /* ----- Patch Code End ------ */
         /* ----- NXTR PATCH END ----- */

         state[CR_DEF_HASH_STATESIZE] = 0;
      }

                                          /* process all blocks               */
      i = (uint32)u.s.akt_nr;
      while ((i < numBlocks) || (u.s.nResume != 0))
                    /* still blocks to go or coming back from an interruption */
      {
          /* ----- NXTR PATCH START -----
           * Added By: K. Smith (Nxtr)
           * Date Added: 27Sep16
           *
           * Reason: Run the update function for each block that is configured
           * to be hashed.
           */
           #if 0
           /* ----- Original Code Start ----- */
           RetVal = CR_C_md5hash ((CR_fp_uint16)CR_NULL, textPtr[i],
                                   length[i], (CR_fp_uint8)CR_NULL);

           CR_C_RETURN_IF_CANCELED(RetVal);   /* sub-func canceled? then return */
           /* ----- Original Code End ----- */
           #endif
           /* ----- Patch Code Start ------ */
           CalReturn_Cnt_T_enum = Cal_HashUpdate(CalHashConfig, CalHashBuffAry_Cnt_T_u32, textPtr[i], length[i]);
           /* ----- Patch Code End ------ */
           /* ----- NXTR PATCH END ----- */

         CR_C_RETURN_IF_CANCELED(RetVal);   /* sub-func canceled? then return */

                                        /* check if sub-state is not finished */
         if (state[CR_DEF_HASH_STATESIZE] != 0)
         {
            u.s.nResume = 1;                        /* mark as "not finished" */
            u.s.akt_nr = (uint16)i;                 /* save local state       */
            /* CR71023: Don't ignore possible error messages or return        */
			/* values: The operation memcpy does only return a pointer but no */
			/* error code                                                     */
            /* => No error handling required                                  */
			/* => Use of this void cast is OK                                 */
            (void) CR_C_memcpy ((CR_fp_void)state, (CR_fp_void)&u,
                                (uint16)CR_DEF_HASH_STATESIZE);

            return CR_C_RC_NF;                         /* return not finished */
         }
         else
         {
                /* if we came back from an interruption, we continue normally */
            u.s.nResume = 0;
         }

         ++i;                          /* proceed to next block               */
      }
      /* ----- NXTR PATCH START -----
      * Added By: K. Smith (Nxtr)
      * Date Added: 27Sep16
      *
      * Reason: Finalize hash routine and return result to calling function.
      */
      #if 0
      /* ----- Original Code Start ----- */
      RetVal = CR_C_md5end (hashRes);       /* finalize the hash value        */

      CR_C_RETURN_IF_CANCELED(RetVal);      /* sub-func canceled? then return */
      /* ----- Original Code End ----- */
      #endif
      /* ----- Patch Code Start ------ */
      /* Calculate the size of the Hash table */
      HashSize_Cnt_T_u32 = 32;

      /* Finalize the hash function and return the result to hashRes */
      CalReturn_Cnt_T_enum = Cal_HashFinish(CalHashConfig, CalHashBuffAry_Cnt_T_u32, hashRes, &HashSize_Cnt_T_u32, TRUE);

      /* Cast Cal return to function return type */
      RetVal = (CR_C_RC_t)CalReturn_Cnt_T_enum;
      /* ----- Patch Code End ------ */
      /* ----- NXTR PATCH END ----- */

      CR_C_RETURN_IF_CANCELED(RetVal);      /* sub-func canceled? then return */

      state[0] = 0;
   }
   else
   {
#endif                                /* (CR_DEF_USE_INTERRUPTION == STD_ON) && \
                                       * (CR_DEF_USE_TRIGGER_COP == STD_OFF)      */

       /* ----- NXTR PATCH START -----
        * Added By: K. Smith (Nxtr)
        * Date Added: 27Sep16
        *
        * Reason: Use the Cal abstraction to initialize the hash routine and buffer 
        */
        #if 0
        /* ----- Original Code Start ----- */
                                        /* hash without interruption            */
        CR_C_md5init ();                /* initialize the hash                  */
                                        /* process all blocks                   */
        /* ----- Original Code End ----- */
        #endif
        /* ----- Patch Code Start ------ */
        CalReturn_Cnt_T_enum = Cal_HashStart(CalHashConfig, CalHashBuffAry_Cnt_T_u32);
        /* ----- Patch Code End ------ */
      /* ----- NXTR PATCH END ----- */
       
      i = 0;
      while (i < numBlocks)
      {
           /* ----- NXTR PATCH START -----
            * Added By: K. Smith (Nxtr)
            * Date Added: 27Sep16
            *
            * Reason: Run the update function for each block that is configured 
            * to be hashed. 
            */
            #if 0
            /* ----- Original Code Start ----- */
            RetVal = CR_C_md5hash ((CR_fp_uint16)CR_NULL, textPtr[i],
                                    length[i], (CR_fp_uint8)CR_NULL);

            CR_C_RETURN_IF_CANCELED(RetVal);   /* sub-func canceled? then return */
            /* ----- Original Code End ----- */
            #endif
            /* ----- Patch Code Start ------ */
            CalReturn_Cnt_T_enum = Cal_HashUpdate(CalHashConfig, CalHashBuffAry_Cnt_T_u32, textPtr[i], length[i]);
            /* ----- Patch Code End ------ */
            /* ----- NXTR PATCH END ----- */
         
         ++i;                        /* next block                            */
      }

      /* ----- NXTR PATCH START -----
      * Added By: K. Smith (Nxtr)
      * Date Added: 27Sep16
      *
      * Reason: Finalize hash routine and return result to calling function.
      */
      #if 0
      /* ----- Original Code Start ----- */
      RetVal = CR_C_md5end (hashRes);       /* finalize the hash value        */

      CR_C_RETURN_IF_CANCELED(RetVal);      /* sub-func canceled? then return */
      /* ----- Original Code End ----- */
      #endif
      /* ----- Patch Code Start ------ */
      /* Calculate the size of the Hash table */
      HashSize_Cnt_T_u32 = 32;
      
      /* Finalize the hash function and return the result to hashRes */
      CalReturn_Cnt_T_enum = Cal_HashFinish(CalHashConfig, CalHashBuffAry_Cnt_T_u32, hashRes, &HashSize_Cnt_T_u32, TRUE);
      
      /* Cast Cal return to function return type */
      RetVal = (CR_C_RC_t)CalReturn_Cnt_T_enum;
      /* ----- Patch Code End ------ */
      /* ----- NXTR PATCH END ----- */

#if (CR_DEF_USE_INTERRUPTION == STD_ON) &&\
    (CR_DEF_USE_TRIGGER_COP == STD_OFF)
   }
#endif                               /* (CR_DEF_USE_INTERRUPTION == STD_ON) && \
                                      * (CR_DEF_USE_TRIGGER_COP == STD_OFF)       */
   return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
