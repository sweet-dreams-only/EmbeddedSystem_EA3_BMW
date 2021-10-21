/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_a_mexp.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : RSA routines                                                  **
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
** jd           Jochen Decker              3SOFT                              **
** mg           Matthias Galota            3SOFT                              **
** am           Alexander Much             3SOFT                              **
** sc           Juergen Scherg             3SOFT                              **
** fs           Frank Stamm                3SOFT                              **
** gema         Markus Gerngross           MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V6.0.1: 27.01.2010, gema: CR70529: Crypto: Compiler switches shall have 
 *                                    defined values
 * V6.0.1: 04.11.2008, mg : CR61473: fixed division-by-zero bug
 * V5.0.2: 07.03.2007, mg : CR60987: fixed bug in interruption code
 * V5.0.0: 21.09.2006, mg : code clean-ups
 *         11.08.2006, mg : added cancelation functionality, modified macro
 *                          syntax, using DET, made functions return immediately
 *                          after an error, improved formatting, removed
 *                          mem_util, made local functions static, removed
 *                          redundant casts
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */
#include "cr_a_mexp.h"             /* long number arithmetic                  */
#include "cr_c_callback.h"         /* interruption per callback defs+routines */
#include "cr_c_cancel.h"           /* cancelation of computation              */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/* The following function-like macros are in violation of MISRA rule 93. But  */
/* implementing them as functions would drastically increase computation time */
/* of the modular exponentiation.                                             */

/* define macros for the extraction of the high and low words                 */
#define LOWORD(a) ((uint32) ((a)         & (uint32)0xFFFFUL))
#define HIWORD(a) ((uint32)(((a) >> 16U) & (uint32)0xFFFFUL))

/* define a 64-bit multiplication using the 32 bit multiplication of ISO C    */
#define CR_DEF_MULULONG(a1, a2, rh, rl)          \
{                                                \
   auto uint32 rm;                               \
   rm = LOWORD (a1) * HIWORD (a2);               \
   (rl) = HIWORD (a1) * LOWORD (a2);             \
   rm += (rl);                                   \
   if (rm < (rl))                                \
   {                                             \
      (rh) = HIWORD (rm) | (uint32)0x10000UL;    \
   }                                             \
   else                                          \
   {                                             \
      (rh) = HIWORD (rm);                        \
   }                                             \
   (rl) = LOWORD (rm) << 16U;                    \
   rm = LOWORD (a1) * LOWORD (a2);               \
   (rl) += rm;                                   \
   if ((rl) < rm)                                \
   {                                             \
      (rh)++;                                    \
   }                                             \
   (rh) += HIWORD (a1) * HIWORD (a2);            \
}

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/*
      Local data type for state buffer in interruptable mode
      for subroutine CR_ST_NewAaMod()
*/
typedef struct
{
   uint8  nResume;           /* Stores whether the current subroutine has     */
                             /* reentered. This must be the first byte in the */
                             /* structure.                                    */
   uint32 lengthDifference;
} CR_LCL_ModInterruptBuffer_t;

/*
      Local data type for state buffer in interruptable mode
      for subroutine CR_A_NewAaMExp()
*/
typedef struct
{
   uint8  nResume;            /* Must be the first byte in the structure.     */
   uint32 bits;
} CR_LCL_ExpInterruptBuffer_t;

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/
#define CRYPTO_START_SEC_CODE
#include "MemMap.h"
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaNorm
(
   CR_fp_uint32 num
);

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaClear
(
   CR_fp_uint32 num,
   uint32       size
);

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaCopy
(
   CR_fpc_uint32 num,
   CR_fp_uint32  res
);

TS_STATIC_FUNCTION uint32 CR_ST_NewAaLb
(
   CR_fpc_uint32 num
);

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaMult
(
   CR_fpc_uint32 num1,
   CR_fpc_uint32 num2,
   CR_fp_uint32  res
);



#if (CR_DEF_USE_BARRETT == STD_OFF)

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaMod
(
   CR_fp_uint16  cycleCountPtr,
   CR_fp_uint32  num,
   CR_fp_uint32  res,
   CR_fpc_uint32 mod,
   CR_fp_uint8   state
);

#else                                                   /* CR_DEF_USE_BARRETT */

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaLowerDigits
(
   CR_fpc_uint32 num,
   uint32        noOfDigits,
   CR_fp_uint32  res
);

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaRDShift
(
   CR_fpc_uint32 num,
   uint32        noOfDigits,
   CR_fp_uint32  res
);

TS_STATIC_FUNCTION sint8 CR_ST_NewAaDCmp
(
   CR_fpc_uint32 num1,
   CR_fpc_uint32 num2
);

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaSub
(
   CR_fpc_uint32 num1,
   CR_fpc_uint32 num2,
   CR_fp_uint32  res
);

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaModB
(
   CR_fp_uint32  num,
   CR_fp_uint32  res,
   CR_fpc_uint32 mod,
   CR_fpc_uint32 bar
);

#endif                                                  /* CR_DEF_USE_BARRETT */

#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :    CR_ST_NewAaNorm                                         **
**                                                                            **
** DESCRIPTION   :    erases leading zero entries from the number             **
**                    representation, such that after invocation              **
**                    num[size] != 0  or num[0] == 0                          **
**                                                                            **
** PRECONDITIONS :    num is an array of at least num[0] length               **
**                                                                            **
** PARAMETERS    :    num - AALONG value, operand of function                 **
**                                                                            **
** RETURN        :    CR_C_RC_OK if the computation finished successfully     **
**                    CR_C_RC_CANCELED if the computation has been canceled   **
**                                                                            **
** REMARKS       :    none                                                    **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaNorm
(
   CR_fp_uint32 num
)
{
   uint32 i;

   /* We start at the highest 32-bit component of num.                        */
   i = num[0];

   while ( ( num[i] == 0 ) && ( i > 0 ) )
   {
      /* We decrease i until we have found a 32-bit component of num which    */
      /* is non-zero or we have gone through the complete number.             */
      i--;

      /* Have we been canceled? Then return with CR_C_RC_CANCELED.            */
      CR_C_CheckCancelRequest();
   }

   /* We have found the real length of num without leading zeroes.            */
   num[0] = i;

   return CR_C_RC_OK;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :    CR_ST_NewAaClear                                        **
**                                                                            **
** DESCRIPTION   :    Set AALONG value num to zero and length of num to size  **
**                                                                            **
** PRECONDITIONS :    num must be of length at least size+1                   **
**                                                                            **
** PARAMETERS    :    num   - the AALONG value to be set to zero              **
**                    size  - the number of entries to be zeroed and the      **
**                            length of the resulting AALONG value            **
**                                                                            **
** RETURN        :    CR_C_RC_OK if the computation finished successfully     **
**                    CR_C_RC_CANCELED if the computation has been canceled   **
**                                                                            **
** REMARKS       :    results in a non-standard representation of the zero    **
**                    AALONG value (standard is zero length, see note at top  **
**                    of file), used in CR_ST_NewAaMult to initialize an array**
**                    with zeros. memset is not used because the respective   **
**                    lib is considered too large for embedded systems        **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaClear
(
   CR_fp_uint32 num,
   uint32       size
)
{
   num[0] = size;

   for ( ; size > 0; size-- )
   {
      num[size] = 0;

      /* Have we been canceled? Then return with CR_C_RC_CANCELED.            */
      CR_C_CheckCancelRequest();
   }

   return CR_C_RC_OK;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :    CR_ST_NewAaCopy                                         **
**                                                                            **
** DESCRIPTION   :    copies length and contents of num to res                **
**                                                                            **
** PRECONDITIONS :    res must be of length at least num[0]+1                 **
**                                                                            **
** PARAMETERS    :    num  - the copy-source, an array of length at least     **
**                           num[0]+1                                         **
**                    res  - the copy target, an array of length at least     **
**                           num[0]+1                                         **
**                                                                            **
** RETURN        :    CR_C_RC_OK if the computation finished successfully     **
**                    CR_C_RC_CANCELED if the computation has been canceled   **
**                                                                            **
** REMARKS       :    memcpy is not used because the respective               **
**                    lib is considered too large for embedded systems        **
**                    used in CR_ST_NewAaMod and CR_A_NewAaMExp.              **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaCopy
(
   CR_fpc_uint32 num,
   CR_fp_uint32 res
)
{
   uint32 i;                                                  /* loop counter */

   for ( i = 0; i <= num[0]; i++ )
   {
      res[i] = num[i];

      /* Have we been canceled? Then return with CR_C_RC_CANCELED.            */
      CR_C_CheckCancelRequest();
   }

   return CR_C_RC_OK;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :    CR_ST_NewAaLb                                           **
**                                                                            **
** DESCRIPTION   :    returns the number of bits in num.                      **
**                    First the size of num is calculated from num[0],        **
**                    the number of bits in num[1],...,num[num[0]-1] is       **
**                    calculated as (num[0]-1)*32. In a last step the number  **
**                    of bits in num[num[0]] is calculated through subsequent **
**                    right shifts and test for zero                          **
**                                                                            **
** PRECONDITIONS :    num is assumed to be normalized (leading digit != 0)    **
**                                                                            **
** PARAMETERS    :    num - AALONG value, operand of function                 **
**                                                                            **
** RETURN        :    number of bits of num                                   **
**                                                                            **
** REMARKS       :    function is used in CR_A_NewAaMExp and CR_A_NewAaMod    **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION uint32 CR_ST_NewAaLb
(
   CR_fpc_uint32 num
)
{
   uint32 numberOfBits;                                 /* bit counter        */
   uint32 tmp;                                          /* temporary number   */

   if (num[0] == 0)
   {
      numberOfBits = 0;
   }
   else
   {
      /* numberOfBits is number of components of num                          */
      numberOfBits = num[0];

      /* tmp  = last AALONG in num                                            */
      tmp = num[numberOfBits];

      numberOfBits--;

      /* numberOfBits = (no_of_AALONGs - 1) * 32                              */
      numberOfBits = numberOfBits << 5U;

      while ( tmp != 0 )
      {
         tmp >>= 1U;
         ++numberOfBits;
      }
   }

   return numberOfBits;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :    CR_ST_NewAaMult                                         **
**                                                                            **
** DESCRIPTION   :    calculates the product of num1 and num2 and returns it  **
**                    in res                                                  **
**                                                                            **
** PRECONDITIONS :    res must be an AALONG value of length at least          **
**                    num1[num1[0]] + num2[num2[0]] - 1                       **
**                    res[] cannot be any input array                         **
**                                                                            **
** PARAMETERS    :    num1, num2 - the AALONG values to be multiplied         **
**                    res        - result of multiplication of num1 and num2  **
**                                                                            **
** RETURN        :    CR_C_RC_OK if the computation finished successfully     **
**                    CR_C_RC_CANCELED if the computation has been canceled   **
**                                                                            **
** REMARKS       :    Uses macro CR_DEF_MULULONG                              **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaMult
(
   CR_fpc_uint32 num1,
   CR_fpc_uint32 num2,
   CR_fp_uint32  res
)
{
   CR_C_RC_t RetVal;

   uint32      i1;          /* loop counter                                   */
   uint32      i2;          /* loop counter                                   */
   uint32      n1;          /* size of num1                                   */
   uint32      n2;          /* size of num2                                   */
   auto uint32 rh;          /* high AALONG of a multiplication of two AALONGs */
   auto uint32 rl;          /* low AALONG of a multiplication of two AALONGs  */
   auto uint32 carry;       /* carry bit                                      */

   n1 = num1[0];
   n2 = num2[0];

   RetVal = CR_ST_NewAaClear( res, n1 + n2 );

   /* Has the sub-function been canceled? Then return with CR_C_RC_CANCELED.  */
   CR_C_RETURN_IF_CANCELED(RetVal);

   /* loop over all AALONGs of num1                                           */
   for ( i1 = 1; i1 <= n1; ++i1 )
   {
      carry = 0;

      /* loop over all AALONGs of num2                                        */
      for ( i2 = 1; i2 <= n2; ++i2 )
      {
         /* Have we been canceled? Then return with CR_C_RC_CANCELED.         */
         CR_C_CheckCancelRequest();

         /* multiply the current AALONG of num1 with the current AALONG of    */
         /* num2 and store the result in the correct place in the result      */

         CR_DEF_MULULONG( num1[i1], num2[i2], rh, rl );

         rl += carry;
         if ( rl < carry )
         {
            carry = 1;
         }
         else
         {
            carry = 0;
         }

         res[i1 + i2 - 1] += rl;

         if (res[i1 + i2 - 1] < rl)
         {
            carry++;
         }

         /* no further overflow possible!                                     */
         carry += rh;
      }

      /* Handle carries                                                       */
      while(carry > 0)
      {
         /* Have we been canceled? Then return with CR_C_RC_CANCELED.         */
         CR_C_CheckCancelRequest();

         res[i1 + i2 - 1] += carry;

         if(res[i1 + i2 - 1] < carry)
         {
            carry = 1;
         }
         else
         {
            carry = 0;
         }

         ++i2;
      }
   }

   /* Have we been canceled? Then return with CR_C_RC_CANCELED.               */
   CR_C_CheckCancelRequest();

   RetVal = CR_ST_NewAaNorm(res);

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
   (defined CR_EXP_LEVEL_0)

   CR_EXP_LEVEL_0;

#endif

   /* successfully finished                                                   */
   return RetVal;
}
#if (CR_DEF_USE_BARRETT == STD_OFF)




/*******************************************************************************
**                                                                            **
** FUNC-NAME     :    CR_ST_NewAaMod                                          **
**                                                                            **
** DESCRIPTION   :    calculates num modulo mod and returns the result in     **
**                    res, uses binary division algorithm                     **
**                                                                            **
** PRECONDITIONS :    res must be of length mod[0], num is changed during     **
**                    calculation                                             **
**                                                                            **
** PARAMETERS    :    num    - AALONG value, operand for modular reduction    **
**                    res    - the result of modular reduction                **
**                             cannot be an input array                       **
**                    mod    - the modulus used for modular reduction         **
**                    state  - the state to be saved on interruption          **
**                                                                            **
** RETURN        :    CR_C_RC_OK  if modular reduction is successfully        **
**                                completed                                   **
**                    CR_C_RC_NF  if function was interrupted due to state1   **
**                                and *cycleCountPtr == 0                     **
**                    CR_C_RC_CANCELED if the computation has been canceled   **
**                                                                            **
** REMARKS       :    On interrupt the function's state is saved in state     **
**                    and restored in u on next call. Interrupt condition     **
**                    checked in for-loop.                                    **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaMod
(
   CR_fp_uint16  cycleCountPtr,
   CR_fp_uint32  num,
   CR_fp_uint32  res,
   CR_fpc_uint32 mod,
   CR_fp_uint8   state
)
{
   CR_LCL_ModInterruptBuffer_t u; /* interrupt buffer                         */

   CR_C_RC_t RetVal;         /* the return value                              */

   sint8  cmpNumMod;         /* stores whether num is larger than the shifted */
                             /* mod.                                          */

   uint8  carry;             /* a carry bit used in the subtraction           */

   uint8  tempCarry;         /* stores whether the carry bit has to be set    */
                             /* for the next block                            */

   uint8  shiftBits;         /* the amount of bits by which mod is to be      */
                             /* shifted                                       */

   uint16 shiftBlocks;       /* the amount of full blocks by which mod is to  */
                             /* be shifted                                    */

   uint32 lengthOfNum;       /* the length of num in bits                     */

   uint32 lengthOfMod;       /* the length of mod in bits                     */

   uint32 blockOfNum;        /* a block of num which is used in a comparison  */

   uint32 posInNum;          /* Stores the position of the currently used     */
                             /* block of num                                  */

   uint32 i;                 /* loop counter                                  */

   uint32 blockOfShiftedMod; /* stores one 32-bit block of the shifted mod    */

#if (CR_DEF_USE_INTERRUPTION == STD_ON)
   #if (CR_DEF_USE_TRIGGER_COP == STD_ON)
   uint16                      nLoopCnt;
   uint16                      nExpLvl0break;
   uint16                      nExpLvl1break;
   uint16                      nExpLvl2break;
   #endif                    /* if TRIGGER_COP else                           */
#endif                       /* USE_INTERRUPTION                              */

   RetVal        = CR_C_RC_OK;
   lengthOfNum   = CR_ST_NewAaLb( num );

   /* Have we been canceled? Then return with CR_C_RC_CANCELED.               */
   CR_C_CheckCancelRequest();

   lengthOfMod   = CR_ST_NewAaLb( mod );

   /* Have we been canceled? Then return with CR_C_RC_CANCELED.               */
   CR_C_CheckCancelRequest();

   if ( lengthOfNum == 0 )
   {
      /* Num has zero bits. This means that num is 0 and                      */
      /* res = num modulo mod = 0.                                            */
      RetVal = CR_ST_NewAaCopy( num, res );

      /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED.  */
      CR_C_RETURN_IF_CANCELED(RetVal);
   }
   else
   {

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )

      /* check whether subroutine is re-entered                               */
      if ( (state != CR_NULL) && (state[0] != 0) )
      {
         /* restore old local state                                           */
         (void)CR_C_memcpy
               (
                  (CR_fp_void)&u,
                  (CR_fp_void)state,
                  (uint16)sizeof(CR_LCL_ModInterruptBuffer_t)
               );
      }
      else
      {

#endif /* USE_INTERRUPTION && !TRIGGER_COP */

         /* If this subroutine is not re-entered, we intialize some values.   */

         /* We compute the length difference of num and mod in bits. Since    */
         /* this is an unsigned number, it will only be meaningful if num is  */
         /* at least as long as mod. But this is no problem because we will   */
         /* only use this value if num is as least as long as mod.            */
         /* We add 1 because we will subtract one at the beginning of the     */
         /* do-while-loop.                                                    */
         u.lengthDifference = (lengthOfNum - lengthOfMod) + 1;

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )
      }
#endif

      /* We only do something if num is at least as long as mod. Otherwise,   */
      /* res = num modulo mod = num.                                          */
      if ( lengthOfMod <= lengthOfNum )
      {

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_ON) )
         /* count rounds (bits processed)                                     */
         nLoopCnt = 0;
         /* every third processed bit, call TriggerCop if Lvl0break reached   */
         nExpLvl0break = (u.lengthDifference / 3) + 1;

   #if (CR_DEF_MAX_KEY_LENGTH == 17)
         nExpLvl1break = 48;
         nExpLvl2break = 768;
   #else
         nExpLvl1break = 96;
         nExpLvl2break = 3072;
   #endif /* keysize  selection */

#endif                                     /* USE_INTERRUPTION && TRIGGER_COP */

         /* Binary division: We shift mod an amount of u.lengthDifference     */
         /* bits to the left. Then we check whether num is at least as large  */
         /* as the shifted mod. If this is the case we subtract the shifted   */
         /* mod from num. We decrease u.lengthDifference by one and repeat    */
         /* this game until u.lengthDifference is 0.                          */
         do
         {
            /* At the beginning of each round, we decrease u.lengthDifference */
            /* by one.                                                        */
            u.lengthDifference--;

            /* We extract from u.lengthDifference how many complete blocks to */
            /* shift mod and how many bits to shift mod.                      */
            shiftBlocks = (uint16)(u.lengthDifference >> 5U);
            shiftBits   =  (uint8)(u.lengthDifference & (uint32)0x1F);

            /* The first position of mod from which to create the shifted     */
            /* modulus is computed. Note that this is one larger than the     */
            /* most significant word of mod.                                  */
            i = mod[0] + 1;

            /* The first position of number which to compare to the shifted   */
            /* modulus is computed.                                           */
            posInNum = i + (uint32)shiftBlocks;

            /* For each word of mod, the shifted mod is computed and          */
            /* compared to the corresponding word of num.                     */
            do
            {
               /* Have we been canceled? Then return with CR_C_RC_CANCELED.   */
               CR_C_CheckCancelRequest();

               /* We assemble the current word of the shifted mod from the    */
               /* words mod[i] and mod[i - 1].                                */

               /* We test whether the current position in mod is an allowed   */
               /* position.                                                   */
               if (i <= mod[0] )
               {
                  /* The current position in mod is allowed. We take some     */
                  /* bits from the word of mod at that position.              */
                  blockOfShiftedMod = mod[i] << shiftBits;
               }
               else
               {
                  /* The current position in mod is too high. We are at a     */
                  /* "leading zero". So, all the bits which go into           */
                  /* blockOfShiftedMod are zero.                              */
                  blockOfShiftedMod = 0;
               }

               /* The needed bits from mod[i - 1] are incorporated into       */
               /* blockOfShiftedMod. If we shift the mod by complete words    */
               /* (which means "shiftBits == 0") or if i is the lowest        */
               /* possible position (which means i == 1) no bits from         */
               /* mod[i - 1] are needed.                                      */
               if ( (shiftBits != 0) && (i > 1) )
               {
                  blockOfShiftedMod |=
                    (uint32)(mod[i - 1] >> (uint8)(32U - shiftBits));
               }

               /* We compute the word of num which to compare to the word     */
               /* of the shifted mod. This is normally simply                 */
               /* num[posInNum], but the position can be too high which means */
               /* that we are at a "leading zero" of num.                     */
               if ( posInNum > num[0] )
               {
                  blockOfNum = 0;
               }
               else
               {
                  blockOfNum = num[posInNum];
               }

               /* Now, we compare the word of the shifted mod to the current  */
               /* word of num.                                                */
               if ( blockOfShiftedMod == blockOfNum )
               {
                  cmpNumMod = 0;
               }
               else if ( blockOfShiftedMod > blockOfNum )
               {
                  cmpNumMod = -1;
               }
               else
               {
                  cmpNumMod = 1;
               }

               /* The positions are decreased by 1.                           */
               i--;
               posInNum--;
            } while ( (0 == cmpNumMod) && (i > 0) );

            /* If num is at least as large as the shifted mod, we subtract    */
            /* mod from num.                                                  */
            if ( cmpNumMod >= 0 )
            {
               blockOfShiftedMod = 0;
               carry = 0;
               /* When subtracting the shifted mod from num we can skip the   */
               /* least significant blocks of num because the shifted mod is  */
               /* 0, there. We compute the least signifcant block of num      */
               /* which is affected by the subtraction.                       */
               posInNum = 1 + (uint32)shiftBlocks;

               /* We go through every block of the shifted mod.               */
               for ( i = 1; i <= mod[0]; i++ )
               {
                  /* Have we been canceled? Then return with CR_C_RC_CANCELED.*/
                  CR_C_CheckCancelRequest();

                  /* We subtract the current block of the shifted mod from    */
                  /* the current block of num.                                */

                  tempCarry = 0;
                  blockOfShiftedMod |= (mod[i] << shiftBits);

                  if
                  (
                     (blockOfShiftedMod >= num[posInNum])                 &&
                     ((blockOfShiftedMod > num[posInNum]) || (carry > 0))
                  )
                  {
                     /* If the current block of the shifted mod plus the      */
                     /* carry are larger than the current block of num, we    */
                     /* get a carry for the next higher block.                */
                     tempCarry = 1;
                  }

                  /* The current block of the shifted mod and the carry are   */
                  /* subtracted from the current block of num.                */
                  num[posInNum] -= blockOfShiftedMod;
                  num[posInNum] -= (uint32)carry;

                  /* The carry for the next higher block is created.          */
                  carry = tempCarry;

                  if ( shiftBits == 0 )
                  {
                     blockOfShiftedMod = 0;
                  }
                  else
                  {
                     blockOfShiftedMod = mod[i] >> (uint8)(32U - shiftBits);
                  }

                  posInNum++;
               }

               if ( blockOfShiftedMod != 0 )
               {
                  /* It can happen that the shifted mod has one nonzero block */
                  /* more than the original mod. This is the case now. We     */
                  /* have to subtract this block from num.                    */

                  if
                  (
                     (blockOfShiftedMod >= num[posInNum])                 &&
                     ((blockOfShiftedMod > num[posInNum]) || (carry > 0))
                  )
                  {
                     tempCarry = 1;
                  }
                  else
                  {
                     tempCarry = 0;
                  }

                  num[posInNum] -= blockOfShiftedMod;
                  num[posInNum] -= (uint32)carry;
                  carry = tempCarry;
                  posInNum++;
               }

               /* Now we have to deal with leftover carries.                  */
               while ( carry != 0 )
               {
                  /* Have we been canceled? Then return with CR_C_RC_CANCELED.*/
                  CR_C_CheckCancelRequest();

                  if ( num[posInNum] != 0 )
                  {
                     carry = 0;
                  }

                  num[posInNum] -= 1;
                  posInNum++;
               }
            }

#if (CR_DEF_USE_INTERRUPTION == STD_ON)

   #if (CR_DEF_USE_TRIGGER_COP == STD_ON)

            ++nLoopCnt;

      #ifdef CR_EXP_LEVEL_0
            /* call TriggerCop() if next third of processing has been done    */
            if (nLoopCnt % nExpLvl0break == 0)
            {
               CR_EXP_LEVEL_0;
            }
      #endif /* CR_EXP_LEVEL_0                                                */

      #ifdef CR_EXP_LEVEL_1
            /* call TriggerCop() if 48 (512 Bit) / 96 (1024 Bit) cycles done  */
            if (nLoopCnt == nExpLvl1break)
            {
               CR_EXP_LEVEL_1;
            }
      #endif /* CR_EXP_LEVEL_1                                                */

      #ifdef CR_EXP_LEVEL_2
            /* call TriggerCop() if 768 (512 Bit) / 3072 (1024 Bit) cyc. done */
            if (nLoopCnt == nExpLvl2break)
            {
               CR_EXP_LEVEL_2;
            }
      #endif /* CR_EXP_LEVEL_2                                                */

   #else /* TRIGGER_COP                                                       */

            if ( state != CR_NULL )
            {
               /* We count down one cycle every 4 rounds of this algorithm.   */
               if ( ((uint16)0x03 & u.lengthDifference) == 0 )
               {
                  if ( *cycleCountPtr > 0 )
                  {
                     *cycleCountPtr -= 1;
                  }

                  /* If we have used up all cycles and we have not yet        */
                  /* finished the computation, we stop computing and say      */
                  /* that we are not finished yet.                            */
                  if ( (*cycleCountPtr == 0) && (u.lengthDifference > 0) )
                  {
                     u.nResume = 1;

                     /* save local state                                      */
                     (void)CR_C_memcpy
                           (
                              (CR_fp_void)state,
                              (CR_fp_void)&u,
                              (uint16)sizeof(CR_LCL_ModInterruptBuffer_t)
                           );

                     /* not yet finished                                      */
                     return CR_C_RC_NF;
                  }
               }
            }

   #endif  /* #if TRIGGER_COP #else                                           */

#endif /* #if USE_INTERRUPTION                                                */

         } while ( u.lengthDifference > 0 );

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )
         if ( state != CR_NULL )
         {
            /* We have finished the computation and can clear the resume bit. */
            /* We could set "u.nResume" to 0 and copy "u" to the state array, */
            /* but the following has the same effect.                         */
            state[0] = 0;
         }
#endif

         RetVal = CR_ST_NewAaNorm( num );

         /* Has the sub-function been canceled? Then return.                  */
         CR_C_RETURN_IF_CANCELED(RetVal);

         /* Num is copied to res.                                             */
         RetVal = CR_ST_NewAaCopy( num, res );

         /* Has the sub-function been canceled? Then return.                  */
         CR_C_RETURN_IF_CANCELED(RetVal);
      }
      else /* if(lengthOfMod <= lengthOfNum)                                  */
      {
         /* We know that res = num modulo mod = num. So, num is copied to res.*/
         RetVal = CR_ST_NewAaCopy(num, res);

         /* Has the sub-function been canceled? Then return.                  */
         CR_C_RETURN_IF_CANCELED(RetVal);
      }
   }

   return RetVal;
}

#else /*#if (CR_DEF_USE_BARRETT == STD_OFF)*/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CR_ST_NewAaLowerDigits                                     **
**                                                                            **
** DESCRIPTION   : returns the lower noOfDigits digits of num in res          **
**                                                                            **
** PRECONDITIONS : pointer must be valid and reference to accessible memory.  **
**                                                                            **
** PARAMETERS    : num            - AALONG value, operand of function         **
**                 noOfDigits     - number of lower digits of num             **
**                 res            - the lower noOfDigits digits of num        **
**                                                                            **
** RETURN        :  CR_C_RC_OK if the computation finished successfully       **
**                  CR_C_RC_CANCELED if the computation has been canceled     **
**                                                                            **
** REMARKS       : num == res is admissible                                   **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaLowerDigits
(
   CR_fpc_uint32 num,
   uint32        noOfDigits,
   CR_fp_uint32  res
)
{
   uint32 i;   /* loop counter                                                */

   if ( num[0] < noOfDigits )
   {
      noOfDigits = num[0];
   }

   res[0] = noOfDigits;

   if ( res != num )
   {
      for ( i = 1; i <= noOfDigits; i++ )
      {
         /* Have we been canceled? Then return with CR_C_RC_CANCELED.         */
         CR_C_CheckCancelRequest();

         res[i] = num[i];
      }
   }

   return CR_ST_NewAaNorm( res );
}
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CR_ST_NewAaRDShift                                         **
**                                                                            **
** DESCRIPTION   : performs right digit shift of num by noOfDigits            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    : num            - AALONG value, operand of shift operation  **
**                 noOfDigits     - number of digits to be shifted            **
**                 res            - the result of the right digit shift       **
**                                                                            **
** RETURN        : CR_C_RC_OK if the computation finished successfully        **
**                 CR_C_RC_CANCELED if the computation has been canceled      **
**                                                                            **
** REMARKS       : num == res is admissible                                   **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaRDShift
(
   CR_fpc_uint32 num,
   uint32        noOfDigits,
   CR_fp_uint32  res
)
{
   uint32 max; /* length of num                                               */
   uint32 i;   /* loop counter                                                */

   max = num[0];

   if ( noOfDigits >= max )
   {
      res[0] = 0;
   }
   else
   {
      for ( i = noOfDigits; i <= max; i++ )
      {
         /* Have we been canceled? Then return with CR_C_RC_CANCELED.         */
         CR_C_CheckCancelRequest();

         res[(i - noOfDigits) + 1] = num[i + 1];
      }

      res[0] = max - noOfDigits;
   }

   return CR_C_RC_OK;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CR_ST_NewAaSub                                             **
**                                                                            **
** DESCRIPTION   : computes num1 - num2 and returns the result in res,        **
**                 num1 must be larger than num2                              **
**                                                                            **
** PRECONDITIONS : res must be at least of length num1[0]+1                   **
**                                                                            **
** PARAMETERS    : num1   - AALONG value, first operand                       **
**                 num2   - AALONG value, second operand                      **
**                 res    - result of the subtraction num1 - num2             **
**                                                                            **
** RETURN        : CR_C_RC_OK  on successful completion                       **
**                 CR_C_RC_CANCELED if the computation has been canceled      **
**                                                                            **
** REMARKS       : num1 == res is admissible                                  **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaSub
(
   CR_fpc_uint32 num1,
   CR_fpc_uint32 num2,
   CR_fp_uint32  res
)
{
   uint32    j;                  /* loop counter                              */
   uint32    i;                  /* loop counter                              */
   uint8     carry;              /* carry bit                                 */
   uint8     provisionalCarry;   /* If this is 1, we need a carry.            */
   CR_C_RC_t RetVal;

   RetVal = CR_C_RC_OK;
   carry = 0;

   /* Loop through every AALONG of num2 and subtract it from the              */
   /* corresponding AALONG of num1.                                           */
   for ( i = 1 ; i <= num2[0]; i++ )
   {
      /* Have we been canceled? Then return with CR_C_RC_CANCELED.            */
      CR_C_CheckCancelRequest();

      if ( num1[i] >= (uint32)carry )
      {
         provisionalCarry = 0;
      }
      else
      {
         provisionalCarry = 1;
      }

      j = num1[i] - (uint32)carry;

      res[i] = j - num2[i];

      if ( (res[i] <= j) && (provisionalCarry == 0) )
      {
         carry = 0;
      }
      else
      {
         carry = 1;
      }
   }

   /* Handle leftover carries after num2 has finished.                        */
   for ( ; i <= num1[0]; i++ )
   {
      /* Have we been canceled? Then return with CR_C_RC_CANCELED.            */
      CR_C_CheckCancelRequest();

      if (carry <= num1[i])
      {
         provisionalCarry = 0;
      }
      else
      {
         provisionalCarry = 1;
      }

      res[i] = num1[i] - (uint32)carry;
      carry = provisionalCarry;
   }


#if (CR_DEV_ERROR_DETECT == STD_ON)
   if ( carry != 0 )
   {
     /* num2 was larger than num1. Report the error to the DET.               */
     Det_ReportError
     (
       CR_DET_MODULE_ID,
       (uint8)CR_MEXP_NEWAASUB_ID,
       (uint8)CR_C_RC_ERR
     );

     return CR_C_RC_OK;
   }
#endif                                      /* if (CR_DEV_ERROR_DETECT == STD_ON) */

   res[0] = num1[0];

   return CR_ST_NewAaNorm( res );
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :    CR_ST_NewAaDCmp                                         **
**                                                                            **
** DESCRIPTION   :    compares num1 with num2 and returns the result          **
**                                                                            **
** PRECONDITIONS :    num1, num2 must be normalized                           **
**                                                                            **
** PARAMETERS    :    num1  - AALONG value, first operand                     **
**                    num2  - AALONG value, second operand                    **
**                                                                            **
** RETURN        :    0    if num1 == num2                                    **
**                    1    if num1 >  num2                                    **
**                    -1   if num1 <  num2                                    **
**                                                                            **
** REMARKS       :    none                                                    **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION sint8 CR_ST_NewAaDCmp
(
   CR_fpc_uint32 num1,
   CR_fpc_uint32 num2
)
{
   sint8  RetVal;
   uint32 i;                                            /* loop counter       */

   if ( num1[0] > num2[0] )
   {
      RetVal = (sint8)1;
   }
   else if ( num1[0] < num2[0] )
   {
      RetVal = -1;
   }
   else
   {
      i = num1[0];

      while ( (i > 0) && (num1[i] == num2[i]) )
      {
         i--;
      }

      if ( i == 0 )
      {
         RetVal = 0;
      }
      else if (num1[i] > num2[i])
      {
         RetVal = 1;
      }
      else
      {
         RetVal = -1;
      }
   }

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :    CR_ST_NewAaModB                                         **
**                                                                            **
** DESCRIPTION   :    computes num modulo mod and returns the result in       **
**                    res, uses Barrett modular reduction algorithm as        **
**                    described in A. Menezes, P. van Oorschot, S. Vanstone:  **
**                    Handbook of Applied Cryptology, CRC Press 1997, p. 604. **
**                                                                            **
** PRECONDITIONS :    res must be of length mod[0], num is changed during     **
**                    computation                                             **
**                                                                            **
** PARAMETERS    :    num    - AALONG value, operand for modular reduction    **
**                             num[0] <= 2*mod[0]                             **
**                    res    - result of modular reduction                    **
**                    mod    - modulus used for modular reduction             **
**                    bar    - Barrett value used for modular reduction       **
**                                                                            **
** RETURN        :    CR_C_RC_OK  if modular reduction is successfully        **
**                                completed                                   **
**                    CR_C_RC_CANCELED if the computation has been canceled   **
**                                                                            **
** REMARKS       :    num is changed during calculation                       **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_NewAaModB
(
   CR_fp_uint32  num,
   CR_fp_uint32  res,
   CR_fpc_uint32 mod,
   CR_fpc_uint32 bar
)
{
   uint32    q1[(2ul * CR_DEF_MAX_KEY_LENGTH) + 1ul]; /* quotient 1           */
   uint32    q2[(2ul * CR_DEF_MAX_KEY_LENGTH) + 1ul]; /* quotient 2           */
   sint8     compQ1Q2;                            /* comparison of q1 and q2  */
   uint32    i;                                   /* loop counter             */
   CR_C_RC_t RetVal;                              /* result storage           */

   /* compute q1 = num  div (2**32)**(mod[0]-1)                               */
   /* right-digit-shift by (mod[0]-1)                                         */
   RetVal = CR_ST_NewAaRDShift( num, (uint32)(mod[0] - 1), (CR_fp_uint32)q1 );

   /* Has the sub-function been canceled? Then return with CR_C_RC_CANCELED.  */
   CR_C_RETURN_IF_CANCELED(RetVal);

   /* compute q2 = q1 * bar                                                   */
   RetVal = CR_ST_NewAaMult((CR_fp_uint32)q1, bar, (CR_fp_uint32)q2);

   CR_C_RETURN_IF_CANCELED(RetVal);

   /* compute q3 = q2 div (2**32)**(mod[0]+1)                                 */
   /* right-digit-shift by (mod[0]+1)                                         */
   RetVal = CR_ST_NewAaRDShift
            (
               (CR_fp_uint32)q2,
               (uint32)(mod[0] + 1),
               (CR_fp_uint32)q2
            );

   CR_C_RETURN_IF_CANCELED(RetVal);

   /* compute r1 = num modulo (2**32)**(mod[0]+1)                             */
   /* throw away upper digits, keep the first mod[0]+1                        */
   RetVal = CR_ST_NewAaLowerDigits
            (
               num,
               (uint32)(mod[0] + 1),
               (CR_fp_uint32)q1
            );

   CR_C_RETURN_IF_CANCELED(RetVal);

   /* compute r2 = q3 * mod modulo (2**32)**(mod[0]+1)                        */
   RetVal = CR_ST_NewAaMult( (CR_fp_uint32)q2, mod, num );

   CR_C_RETURN_IF_CANCELED(RetVal);

   /* throw away upper digits, keep the first mod[0]+1                        */
   RetVal = CR_ST_NewAaLowerDigits
            (
               num,
               (uint32)(mod[0] + 1),
               (CR_fp_uint32)q2
            );

   CR_C_RETURN_IF_CANCELED(RetVal);

   /* compare r1 with r2:                                                     */
   compQ1Q2 = CR_ST_NewAaDCmp((CR_fp_uint32)q1, (CR_fp_uint32)q2);
   /* if r1 > r2                                                              */
   if ( compQ1Q2 > 0 )
   {
      /* compute r = r1 - r2                                                  */
      RetVal = CR_ST_NewAaSub( (CR_fp_uint32)q1, (CR_fp_uint32)q2, num );

      CR_C_RETURN_IF_CANCELED(RetVal);
   }
   else
   {
      /* compute r = r1 + (2**32)**(mod[0]+1) - r2                            */
      if ( q1[0] < (mod[0] + 1) )
      {
         for ( i = q1[0]; i < (mod[0] + 1); i++ )
         {
            q1[i + 1] = 0;
         }

         q1[mod[0] + 2]= 1;
         q1[0] = mod[0] + 2;
      }
      else
      {
         q1[mod[0] + 2]++;

         if ( q1[mod[0] + 2] == 0 )
         {
            q1[mod[0] + 3] = 1;
            q1[0] = mod[0] + 2;
         }
      }

      RetVal = CR_ST_NewAaSub( (CR_fp_uint32)q1, (CR_fp_uint32)q2, num );

      CR_C_RETURN_IF_CANCELED(RetVal);
   }

   i = 0;
   /* while r >= mod                                                          */
   while ((CR_ST_NewAaDCmp(num, mod) > 0) && (i < 4))
   {
      /*  compute r = r - mod                                                 */
      RetVal = CR_ST_NewAaSub( num, mod, num );

      CR_C_RETURN_IF_CANCELED(RetVal);

      i++;
#if (CR_DEF_USE_INTERRUPTION == STD_ON) && (defined CR_EXP_LEVEL_0)
      CR_EXP_LEVEL_0;
#endif
   }


#if (CR_DEV_ERROR_DETECT == STD_ON)
   /* check whether num is larger than 2*mod[0]                               */
   if (i == 4)
   {
                                               /* report the error to the DET */
     Det_ReportError
     (
       CR_DET_MODULE_ID,
       (uint8)CR_MEXP_NEWAAMODB_ID,
       (uint8)CR_C_RC_ERR
     );

     return CR_C_RC_OK;
   }
#endif                                    /* if (CR_DEV_ERROR_DETECT == STD_ON) */

   return CR_ST_NewAaCopy( num, res );
}

#endif


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CR_A_NewAaMExp                                             **
**                                                                            **
** DESCRIPTION   : computes bas**exponent modulo mod and returns the result   **
**                 in res. tmp (of length 2*mod[0]+1) must be provided as     **
**                 register. state must be provided for state recovery        **
**                 after interrupt.                                           **
**                 Uses left-to-right binary exponentiation, see              **
**                 A. Menezes, P. van Oorschot, S. Vanstone: Handbook of      **
**                 Applied Cryptology, CRC Press 1997, p. 615.                **
**                                                                            **
** PRECONDITIONS : res[] cannot be any input array                            **
**                                                                            **
** PARAMETERS    : cycleCount - cycle counter, if using interrupted mode.     **
**                               In non-interupted mode, the value must be 0. **
**                 bas         - the base for exponentiation                  **
**                 exponent    - the exponent                                 **
**                 res         - the result (bas**exponent modulus mod)       **
**                               cannot be an input array                     **
**                 mod         - the modulus                                  **
**                 bar         - the Barrett value                            **
**                 tmp         - a place to store temporary results           **
**                 state       - state buffer for interruption mode. will be  **
**                               used on interrupted mode to save the         **
**                               internal state to complete the calculation   **
**                               on the next call, which must be called with  **
**                               the same state-buffer content.               **
**                               If used in non-interrupted mode, the routine **
**                               must be called with state value 0 (NULL).    **
**                                                                            **
** RETURN        : CR_C_RC_NF        if not yet finished                      **
**                 CR_C_RC_OK        if successfully completed                **                                                                            **
**                 CR_C_RC_CANCELED  if the computation has been canceled     **
**                                                                            **
**                                                                            **
** REMARKS       : function provides interruptability for each modular        **
**                 multiplication/squaring as a whole AND allows for          **
**                 independent interrupt of modular reduction                 **
**                                                                            **
*******************************************************************************/
CR_C_RC_t CR_A_NewAaMExp
(
   uint16        cycleCount,
   CR_fpc_uint32 bas,
   CR_fpc_uint32 exponent,
   CR_fp_uint32  res,
   CR_fpc_uint32 mod,
#if (CR_DEF_USE_BARRETT == STD_ON)
   CR_fpc_uint32 bar,
#endif
   CR_fp_uint32  tmp,
   CR_fp_uint8   state
)
{
   CR_LCL_ExpInterruptBuffer_t u;          /* interrupt buffer                */
   CR_C_RC_t                   RetVal;     /* result storage                  */

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )

   uint8                       countCycles; /* Do we count cycles?            */
   CR_fp_uint8                 tempState;   /* pointer to the start of the    */
                                            /* interruption state array which */
                                            /* is passed to lower functions   */

#endif

   RetVal = CR_C_RC_OK;

#if (CR_DEV_ERROR_DETECT == STD_ON)
   if(CR_ST_NewAaLb(mod) == 0)
   {
     /* Mod has zero bits. This means that mod is 0 and we have a division by */
     /* 0. Report the error to the DET.                                       */
     Det_ReportError
     (
       CR_DET_MODULE_ID,
       (uint8)CR_MEXP_NEWAAMEXP_ID,
       (uint8)CR_C_RC_ERR
     );

     return CR_C_RC_OK;
   }
#endif                                      /* if (CR_DEV_ERROR_DETECT == STD_ON) */


#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )

   /* Interruption by cycle count is turned on in the configuration.          */

   tempState = 0;

   if(cycleCount > 0)
   {
      /* We are really using interruption by cycle count.                     */
      countCycles = 1;
   }
   else
   {
      /* Interruption by cycle count is turned off.                           */
      countCycles = 0;
   }

   /* restore state if necessary and null-pointer-handling                    */
   if ( (state != CR_NULL) && (state[0] != 0) )
   {
      /* restore local state                                                  */
      (void)CR_C_memcpy
            (
               (CR_fp_void)&u,
               (CR_fp_void)state,
               (uint16)sizeof(CR_LCL_ExpInterruptBuffer_t)
            );
   }
   else
   {
      /* We are not coming back from an interruption.                         */
      u.nResume = 0;
      /* The number of bits of the exponent is computed.                      */
      u.bits = CR_ST_NewAaLb (exponent);
      /* res = 1                                                              */
      res[0] = res[1] = 1;
   }

   /* The left-to-right exponentiation walks through all the bits of the      */
   /* exponent.                                                               */
   while
   (
      /* Either we have not yet used up all bits of the exponent              */
      (u.bits > 0) ||
      /* or we come back from an interruption.                                */
      ((state != CR_NULL) && (u.nResume != 0))
   )
   {
      /* If u.nResume != 0, we have returned from an interruption and we      */
      /* have to jump to the point where the interruption has taken place     */
      /* without doing anything on the way.                                   */

      if ( (state == CR_NULL) || (u.nResume == 0) )
      {
         --u.bits;

         /* res = res**2 modulo mod                                           */
         RetVal = CR_ST_NewAaMult(res, res, tmp);

         /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED*/
         CR_C_RETURN_IF_CANCELED(RetVal);
      }

#if ( CR_DEF_USE_BARRETT == STD_OFF )

      /* We are not using Barrett reduction.                                  */

      if ( state != CR_NULL )
      {
         if ( u.nResume == 0 )
         {
            /* reset CR_ST_NewAaMod() state                                   */
            state[sizeof(CR_LCL_ExpInterruptBuffer_t)] = 0;
         }

         /* If u.nResume was 1, we return to the computation here.            */

         if ( u.nResume != 2 )
         {
            tempState = &state[sizeof(CR_LCL_ExpInterruptBuffer_t)];
         }
      }

      if( (state == CR_NULL) || (u.nResume != 2) )
      {
         RetVal = CR_ST_NewAaMod
                  (
                     (CR_fp_uint16)&cycleCount,
                     tmp,
                     res,
                     mod,
                     tempState
                  );

         /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED*/
         CR_C_RETURN_IF_CANCELED(RetVal);

         if ( state != CR_NULL )
         {
            if ( state[sizeof(CR_LCL_ExpInterruptBuffer_t)] != 0 )
            {
               /* substate not finished, so mark local state as not finished  */
               u.nResume = 1;

               /* save local state                                            */
               (void)CR_C_memcpy
                     (
                        (CR_fp_void)state,
                        (CR_fp_void)&u,
                        (uint16)sizeof(CR_LCL_ExpInterruptBuffer_t)
                     );

               return CR_C_RC_NF;
            }
            else
            {
               u.nResume = 0;
            }
         }
      }

      /* If the current bit of the exponent is 1, we have to multiply         */
      /* res by bas.                                                          */
      if
      (
         (
            (exponent[(u.bits >> 5U) + 1] >> (uint8)(u.bits & 0x1F)) &
            (uint32)0x1
         ) != 0
      )
      {
         if ( (state == CR_NULL) || (u.nResume != 2) )
         {
            /* res = bas*res modulo mod                                       */
            RetVal = CR_ST_NewAaMult( bas, res, tmp );

            /* Has the sub-function been canceled? Then return.               */
            CR_C_RETURN_IF_CANCELED(RetVal);
         }

         /* Check whether state buffer is available and interruption is to be */
         /* used.                                                             */
         if ( (state != CR_NULL) && (u.nResume == 0) )
         {
            /* reset CR_ST_NewAaMod() state                                   */
            state[sizeof(CR_LCL_ExpInterruptBuffer_t)] = 0;
         }

         /* If u.nResume was 2, we return to the computation here.            */

         if ( state != CR_NULL )
         {
            tempState = &state[sizeof(CR_LCL_ExpInterruptBuffer_t)];
         }

         RetVal = CR_ST_NewAaMod
                  (
                     (CR_fp_uint16)&cycleCount,
                     tmp,
                     res,
                     mod,
                     tempState
                  );

         /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED*/
         CR_C_RETURN_IF_CANCELED(RetVal);

         if ( state != CR_NULL )
         {
            if ( state[sizeof(CR_LCL_ExpInterruptBuffer_t)] != 0 )
            {
               /* not finished, so mark local state as not finished           */
               u.nResume = 2;
               /* save local state                                            */
               (void)CR_C_memcpy
                     (
                        (CR_fp_void)state,
                        (CR_fp_void)&u,
                        (uint16)sizeof(CR_LCL_ExpInterruptBuffer_t)
                     );

               /* not yet finished                                            */
               return CR_C_RC_NF;
            }
            else
            {
               u.nResume = 0;
            }
         }

      }

#else /* BARRETT                                                              */

      /* We are using Barrett reduction.                                      */

      if ( (state == CR_NULL) || (u.nResume == 0) )
      {
         RetVal = CR_ST_NewAaModB
                  (
                     tmp,
                     res,
                     mod,
                     bar
                  );

         /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED*/
         CR_C_RETURN_IF_CANCELED(RetVal);

         if ( state != CR_NULL )
         {
            if(cycleCount > 0)
            {
               /* handle interruption locally                                 */
               --cycleCount;
            }

            /* check whether routine can pause                                */
            if ( (countCycles != 0) && (cycleCount == 0) )
            {
                  /* mark local state as not finished for reentering          */
                  u.nResume = 1;
                  /* save local state                                         */
                  (void)CR_C_memcpy
                        (
                           (CR_fp_void)state,
                           (CR_fp_void)&u,
                           (uint16)sizeof(CR_LCL_ExpInterruptBuffer_t)
                        );
                  /* return as not finished                                   */
                  return CR_C_RC_NF;
            }
            else
            {
               u.nResume = 0;
            }
         }

      }


      /* If the current bit of the exponent is 1, we have to multiply         */
      /* res by bas.                                                          */
      if
      (
         (
            (exponent[(u.bits >> 5U) + 1] >> (uint8)(u.bits & 0x1F)) &
            (uint32)0x1
         ) != 0
      )
      {
         if ( (state == CR_NULL) || (u.nResume != 2) )
         {
            /* res = bas*res modulo mod                                       */
            RetVal = CR_ST_NewAaMult(bas, res, tmp);

            /* Has the sub-function been canceled? Then return.               */
            CR_C_RETURN_IF_CANCELED(RetVal);
         }

         if ( (state == CR_NULL) || (u.nResume != 2) )
         {
            RetVal = CR_ST_NewAaModB
                     (
                        tmp,
                        res,
                        mod,
                        bar
                     );

            /* Has the sub-function been canceled? Then return.               */
            CR_C_RETURN_IF_CANCELED(RetVal);

            if ( state != CR_NULL )
            {
               if ( cycleCount > 0 )
               {
                  /* handle interruption locally                              */
                  --cycleCount;
               }

               /* check whether routine can pause                             */
               if ( (countCycles != 0) && (cycleCount == 0) )
               {
                     /* mark local state as not finished for reentering       */
                     u.nResume = 2;
                     /* save local state                                      */
                     (void)CR_C_memcpy
                           (
                              (CR_fp_void)state,
                              (CR_fp_void)&u,
                              (uint16)sizeof(CR_LCL_ExpInterruptBuffer_t)
                           );

                     return CR_C_RC_NF;
               }
               else
               {
                  u.nResume = 0;
               }
            }

         }

      }

      u.nResume = 0;

#endif /* #if BARRETT == STD_OFF  #else                                           */

   }

   if ( state != CR_NULL )
   {
      /* We have finished the computation and can clear the resume bit.       */
      /* We could set "u.nResume" to 0 and copy "u" to the state array,       */
      /* but the following has the same effect.                               */
      state[0] = 0;
   }

#else /* USE_INTERRUPTION && !TRIGGER_COP                                     */

   /* We either have no interruption at all or interruption by TRIGGER_COP.   */

   u.bits = CR_ST_NewAaLb (exponent);

   /* res = 1                                                                 */
   res[0] = res[1] = 1;

   while ( u.bits > 0 )
   {
      --u.bits;

      /* res = res**2 modulo mod                                              */
      RetVal = CR_ST_NewAaMult(res, res, tmp);

      /* Has the sub-function been canceled? Then return with CR_C_RC_CANCELED*/
      CR_C_RETURN_IF_CANCELED(RetVal);

#if (CR_DEF_USE_BARRETT == STD_OFF)

      RetVal = CR_ST_NewAaMod
               (
                  (CR_fp_uint16)CR_NULL,
                  tmp,
                  res,
                  mod,
                  (CR_fp_uint8)CR_NULL
               );

#else /* USE_BARRETT                                                          */

      RetVal = CR_ST_NewAaModB
               (
                  tmp,
                  res,
                  mod,
                  bar
               );

#endif /* USE_BARRETT                                                         */

      /* Has the sub-function been canceled? Then return with CR_C_RC_CANCELED*/
      CR_C_RETURN_IF_CANCELED(RetVal);

      /* If the current bit of the exponent is 1, we have to multiply         */
      /* res by bas.                                                          */
      if
      (
         (
            (exponent[(u.bits >> 5U) + 1] >> (uint8)(u.bits & 0x1F)) &
            (uint32)0x1
         ) != 0
      )
      {
         /* res = bas*res modulo mod                                          */
         RetVal = CR_ST_NewAaMult( bas, res, tmp );

         /* Has the sub-function been canceled? Then return.                  */
         CR_C_RETURN_IF_CANCELED(RetVal);

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
(defined CR_EXP_LEVEL_2)

         CR_EXP_LEVEL_2;

#endif /* USE_INTERRUPTION && CR_EXP_LEVEL_2                                  */


#if (CR_DEF_USE_BARRETT == STD_OFF)

         RetVal = CR_ST_NewAaMod
                  (
                     (CR_fp_uint16)CR_NULL,
                     tmp,
                     res,
                     mod,
                     (CR_fp_uint8)CR_NULL
                  );

#else /* USE_BARRETT                                                          */

         RetVal = CR_ST_NewAaModB
                  (
                     tmp,
                     res,
                     mod,
                     bar
                  );

#endif /* USE_BARRETT                                                         */

         /* Has the sub-function been canceled? Then return.                  */
         CR_C_RETURN_IF_CANCELED(RetVal);

      }

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
      (defined CR_EXP_LEVEL_1)

         CR_EXP_LEVEL_1;

#endif /* !NO_INTERRUPTION && EXP_LEVEL_1                                     */

   }

#endif /* #if USE_INTERRUPTION && !TRIGGERCOP #else                           */

   return RetVal;
}

#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file *************************************************************/

