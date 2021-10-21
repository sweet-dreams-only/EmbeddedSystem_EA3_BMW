/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_c_random.c                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : a random number generator                                     **
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
 * V5.0.1: 27.01.2010, gema: CR70529: Crypto: Compiler switches shall have 
 *                                    defined values
 * V5.0.0: 21.09.2006, mg : code clean-ups
 *         11.08.2006, mg : modified macro syntax, improved formatting, removed
 *                          redundant casts, made local functions static
 * V4.1.0: 22.06.2006, mg : no changes
 * V4.0.0: 03.04.2006, mg : moved configuration options to Crypto_Cfg.h, key
 *                          length configurable independently for authentication
 *                          and signature, cleaned up cr_c_hash.c,
 *                           removed compiler warnings
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
#include "cr_c_random.h"           /* random number generator routines        */
#include "cr_c_data.h"             /* common global data                      */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

         /* define fallback values for the seed in case a zero seed was given */
#define CR_C_RANDOM_SEED_A_FALLBACK_0 ((uint32)0x12345678UL)
#define CR_C_RANDOM_SEED_A_FALLBACK_1 ((uint32)0x90abcdefUL)

#define CR_C_RANDOM_SEED_B_FALLBACK_0 ((uint32)0x12345678UL)
#define CR_C_RANDOM_SEED_B_FALLBACK_1 ((uint32)0x90abcdefUL)

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/
#define CRYPTO_START_SEC_CODE
#include "MemMap.h"
TS_STATIC_FUNCTION void CR_ST_ShiftReg
(
   CR_fp_uint32 reg
);

TS_STATIC_FUNCTION void CR_ST_ClockRegA
(
   CR_fp_uint32 reg
);

TS_STATIC_FUNCTION void CR_ST_ClockRegB
(
   CR_fp_uint32 reg
);

TS_STATIC_FUNCTION void CR_C_Random
(
   CR_fp_uint32 regA,
   CR_fp_uint32 regB,
   uint32       length,
   CR_fp_uint8  randomData
);


#if (CR_DEF_RNG_ADV == STD_ON)

TS_STATIC_FUNCTION void CR_ST_ClockRandSeedA
(
   void
);

TS_STATIC_FUNCTION void CR_ST_ClockRandSeedB
(
   void
);

TS_STATIC_FUNCTION void CR_C_RandomInit
(
   void
);

TS_STATIC_FUNCTION void CR_C_RandomUpdate
(
   CR_fpc_uint32 reg
);

#endif                                           /* if (CR_DEF_RNG_ADV == STD_ON) */



#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_ST_ShiftReg                                            **
**                                                                            **
** DESCRIPTION   :  shift right one bit of a 64bit register                   **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  reg - register array                                      **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION void CR_ST_ShiftReg
(
   CR_fp_uint32 reg
)
{
   reg[0] >>= 1U;                                  /* shift first 32-bit word  */
                                                  /* overflow occurred ?      */
   if ((uint32)(reg[1u] & (uint32)1) != 0)
   {
      reg[0] ^= (uint32)0x80000000UL;             /* yes, so set highest bit  */
   }
   reg[1] >>= 1U;                                  /* shift second 32-bit word */
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_ST_ClockRegA                                           **
**                                                                            **
** DESCRIPTION   :  polynomial feedback x^62+x^6+x^5+x^3+1                    **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  reg - register array                                      **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/

TS_STATIC_FUNCTION void CR_ST_ClockRegA
(
   CR_fp_uint32 reg
)
{
   uint8 feedback;            /* to store feedback                           */

                               /* calculate the feedback using the polynomial */
   feedback = (uint8)(
                         (
                            (uint32)(reg[0] >> 6U) ^
                            (uint32)(reg[0] >> 5U) ^
                            (uint32)(reg[0] >> 3U) ^
                            (uint32)(reg[0]      )
                         ) & (uint32)0xff
                      );

   CR_ST_ShiftReg (reg);               /* shift the 64-bit register           */
   reg[1] &= (uint32)0x1fffffffUL;     /* "shave" unwanted bits: reg = 000*...*/
                                       /* do we have to feedback one bit?     */
   if ((uint8)(feedback & (uint8)1) != 0)
   {
      reg[1] ^= (uint32)0x20000000UL;  /* feedback to right position          */
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_ST_ClockRegB                                           **
**                                                                            **
** DESCRIPTION   :  polynomial feedback x^61+x^5+x^2+x+1                      **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  reg <-> register array                                    **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/

TS_STATIC_FUNCTION void CR_ST_ClockRegB
(
   CR_fp_uint32 reg
)
{
   uint8 feedback;            /* to store feedback                           */

                               /* calculate the feedback using the polynomial */
   feedback =(uint8)(
                        (
                           (uint32)(reg[0] >> 5U) ^
                           (uint32)(reg[0] >> 2U) ^
                           (uint32)(reg[0] >> 1U) ^
                           (uint32)(reg[0]      )
                        ) & (uint32)0xff
                     );

   CR_ST_ShiftReg (reg);               /* shift the 64-bit register           */
   reg[1] &= (uint32)0x0fffffffUL;     /* "shave unwanted bits: reg = 0000*...*/
                                       /* do we have to feedback one bit?     */
   if ((uint8)(feedback & (uint8)1) != 0)
   {
      reg[1] ^= (uint32)0x10000000UL;  /* yes, feedback to right position     */
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_ST_ClockRandSeedA                                      **
**                                                                            **
** DESCRIPTION   :  polynomial feedback x^59+x^6+x^5+x^4+x^3+x+1              **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  void                                                      **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  calls CR_ST_ShiftReg                                      **
**                                                                            **
*******************************************************************************/
#if (CR_DEF_RNG_ADV == STD_ON)
TS_STATIC_FUNCTION void CR_ST_ClockRandSeedA
(
   void
)
{
   uint8 feedback;             /* to store feedback                           */

                               /* calculate the feedback using the polynomial */
   feedback = (uint8)(
                        (
                           (uint32)(CR_C_s4.CR_C_RandSeedA[0] >> 6U) ^
                           (uint32)(CR_C_s4.CR_C_RandSeedA[0] >> 5U) ^
                           (uint32)(CR_C_s4.CR_C_RandSeedA[0] >> 4U) ^
                           (uint32)(CR_C_s4.CR_C_RandSeedA[0] >> 3U) ^
                           (uint32)(CR_C_s4.CR_C_RandSeedA[0] >> 1U) ^
                           (uint32)(CR_C_s4.CR_C_RandSeedA[0]      )
                        ) & (uint32)1
                     );
                              /* shift the 64-bit register                    */
   (void)CR_ST_ShiftReg ((CR_fp_uint32)CR_C_s4.CR_C_RandSeedA);
                              /* set initial bits to 0                        */
   CR_C_s4.CR_C_RandSeedA[1] &= (uint32)0x03ffffffUL;
   if (feedback != 0)         /* do we have to feedback one bit?              */
   {
                              /* feedback to right position                   */
      CR_C_s4.CR_C_RandSeedA[1] ^= (uint32)0x04000000UL;
   }
}

#endif                                           /* if (CR_DEF_RNG_ADV == STD_ON) */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_ST_ClockRandSeedB                                      **
**                                                                            **
** DESCRIPTION   :  polynomial feedback x^57+x^5+x^3+x^2+1                    **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  void                                                      **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  calls CR_ST_ShiftReg                                      **
**                                                                            **
*******************************************************************************/
#if (CR_DEF_RNG_ADV == STD_ON)
TS_STATIC_FUNCTION void CR_ST_ClockRandSeedB
(
   void
)
{
   uint8 feedback;            /* to store feedback                            */

                              /* calculate the feedback using the polynomial  */
   feedback = (uint8)(
                        (
                           (uint32)(CR_C_s4.CR_C_RandSeedB[0] >> 5U) ^
                           (uint32)(CR_C_s4.CR_C_RandSeedB[0] >> 3U) ^
                           (uint32)(CR_C_s4.CR_C_RandSeedB[0] >> 2U) ^
                           (uint32)(CR_C_s4.CR_C_RandSeedB[0]      )
                        ) & (uint32)1
                     );
                              /* shift the 64-bit register                    */
   (void)CR_ST_ShiftReg((CR_fp_uint32)CR_C_s4.CR_C_RandSeedB);
                              /* set initial bits to 0                        */
   CR_C_s4.CR_C_RandSeedB[1] &= (uint32)0x00ffffffUL;
   if (feedback != 0)         /* do we have to feedback one bit?              */
   {
                              /* feedback to right position                   */
      CR_C_s4.CR_C_RandSeedB[1] ^= (uint32)0x01000000UL;
   }
}

#endif                                           /* if (CR_DEF_RNG_ADV == STD_ON) */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_C_Random                                               **
**                                                                            **
** DESCRIPTION   :  generates random data basing on regA and regB             **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  regA       - RNG register a                               **
**                  regB       - RNG register b                               **
**                  length     - demanded length of random data               **
**                  randomData - buffer for random data                       **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  called by CR_C_MakeChallKey                               **
**                  calls CR_ST_ClockRegA, CR_ST_ClockRegB                    **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION void CR_C_Random
(
   CR_fp_uint32 regA,
   CR_fp_uint32 regB,
   uint32       length,
   CR_fp_uint8  randomData
)
{
   uint8  nBits;               /* bit counter (0-7)                           */
   uint8  tempBit;             /* temporary bit                               */
   uint8  randomByte;          /* current random byte                         */
   uint32 i;                   /* loop counter                                */

   i = 0;                      /* start with first byte                       */
   while (i < length)          /* as long as not enough data generated        */
   {
      nBits = 0;               /* generated zero bits in this byte            */
      randomByte = 0;          /* initialize the random byte to zero          */

      do                       /* loop over the eight bits of the random byte */
      {
         CR_ST_ClockRegA (regA);                              /* clock lfsr A */
         CR_ST_ClockRegB (regB);                              /* clock lsfr B */

         /* This is an a-b-shrinking generator. Use the generated bit from    */
         /* both LFSRs only if the first clock bit is one. Otherwise discard  */
         /* the bit.                                                          */
         if ((regB[0] & (uint32)1) != 0)
         {
                               /* take the first bit of LFSR_a                */
            tempBit = (uint8)(regA[0] & (uint32)1);
                               /* and set the appropriate bit in bByte        */
            randomByte = (uint8)(randomByte << 1U) ^ tempBit;
            ++nBits;           /* and set next bit                            */
         }
      } while (nBits != 8);    /* until all eight bits are finished           */
      randomData[i] = randomByte;                /* assign the generated byte */
      ++i;                     /* go to next byte to generate random data for */
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_C_RandomInit                                           **
**                                                                            **
** DESCRIPTION   :  Initialization of the random generator.                   **
**                  Depends on time.                                          **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  void                                                      **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  calls CR_ST_ClockRandSeedA, CR_ST_ClockRandSeedB          **
**                                                                            **
*******************************************************************************/
#if (CR_DEF_RNG_ADV == STD_ON)
TS_STATIC_FUNCTION void CR_C_RandomInit
(
   void
)
{
   for(;;)                                       /* endless loop              */
   {
      CR_ST_ClockRandSeedA ();                   /* clock first LFSR          */
      CR_ST_ClockRandSeedB ();                   /* clock second LFSR         */
   }
}
#endif                                           /* if (CR_DEF_RNG_ADV == STD_ON) */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_C_RandomUpdate                                         **
**                                                                            **
** DESCRIPTION   :  refresh random generator                                  **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  reg - RNG register                                        **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  side effect on global var                                 **
**                                                                            **
*******************************************************************************/
#if (CR_DEF_RNG_ADV == STD_ON)
TS_STATIC_FUNCTION void CR_C_RandomUpdate
(
   CR_fpc_uint32 reg
)
{
                                          /* add register to global generator */
   CR_C_s4.CR_C_RandSeedA[0] ^= reg[0];
                                          /* add register to global generator */
   CR_C_s4.CR_C_RandSeedA[1] ^= reg[1];
                                          /* add register to global generator */
   CR_C_s4.CR_C_RandSeedB[0] ^= reg[2];
                                          /* add register to global generator */
   CR_C_s4.CR_C_RandSeedB[1] ^= reg[3];
}
#endif                                    /* if (CR_DEF_RNG_ADV == STD_ON)        */




/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_C_MakeChallKey                                         **
**                                                                            **
** DESCRIPTION   :  creation of a challenge / key                             **
**                                                                            **
** PRECONDITIONS :  space for the challenge must be allready allocated        **
**                                                                            **
** PARAMETERS    :  length   - demanded length of random data                 **
**                  challKey - buffer for random data                         **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  calls CR_C_Random                                         **
**                                                                            **
*******************************************************************************/
void Crypto_MakeChallKey
(
   uint32      length,
   CR_fp_uint8 challKey
)
{
#if (CR_DEF_RNG_ADV == STD_ON)
           /* time dependent initialization of the random generator registers */

           /* add global random to local                                      */
   CR_C_s2.reg_a[0] ^= CR_C_s4.CR_C_RandSeedA[0];
           /* add global random to local                                      */
   CR_C_s2.reg_a[1] ^= CR_C_s4.CR_C_RandSeedA[1];
           /* add global random to local                                      */
   CR_C_s2.reg_b[0] ^= CR_C_s4.CR_C_RandSeedB[0];
           /* add global random to local                                      */
   CR_C_s2.reg_b[1] ^= CR_C_s4.CR_C_RandSeedB[1];
#endif     /* if (CR_DEF_RNG_ADV == STD_ON)                                       */

   if ((CR_C_s2.reg_a[0] == 0) && (CR_C_s2.reg_a[1] == 0))
   {
      CR_C_s2.reg_a[0] = CR_C_RANDOM_SEED_A_FALLBACK_0;
      CR_C_s2.reg_a[1] = CR_C_RANDOM_SEED_A_FALLBACK_1;
   }

   if ((CR_C_s2.reg_b[0] == 0) && (CR_C_s2.reg_b[1] == 0))
   {
      CR_C_s2.reg_b[0] = CR_C_RANDOM_SEED_B_FALLBACK_0;
      CR_C_s2.reg_b[1] = CR_C_RANDOM_SEED_B_FALLBACK_1;
   }

           /* create challenge key                                            */
   CR_C_Random ((CR_fp_uint32)CR_C_s2.reg_a, (CR_fp_uint32)CR_C_s2.reg_b,
                length, challKey);

           /* most significant byte must be != 0                              */
           /* -> significant length of challKey = length                      */
   challKey[length - 1] |= (uint8)1;
}

#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
