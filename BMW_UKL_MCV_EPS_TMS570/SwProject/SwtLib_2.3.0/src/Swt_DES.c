/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_DES.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for the DES routines                              **
**                                                                            **
**  REMARKS   : Implementation of the mathematical operations needed for the  **
**              DES algorithm.                                                **
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
** jd           Jochen Decker              Elektrobit Automotive GmbH         **
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.1.0    : 06.02.2007, jd   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Common.h"                   /* declaration of common services */
#include "Swt_DES.h"                        /* declarations of des services */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/
#define SWT_DES_SBOX_LEN                     64U
#define SWT_DES_PBOX_LEN                     32U


#define SWT_DES_KEY_SCHED_PC1_BIT_LEN        64U
#define SWT_DES_KEY_SCHED_PC2_BIT_LEN        32U

#define SWT_DES_INITIAL_PERM_BIT_LEN        128U
#define SWT_DES_INV_INIT_PERM_BIT_LEN       128U

#define SWT_DES_EXPANSION_BIT_LEN            32U
#define SWT_DES_PBOX_BIT_LEN                128U

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

SWT_STATIC_FUNC void Swt_DESRound
(
   P2VAR(uint8,AUTOMATIC,SC_FAR) Block,
   P2CONST(uint8, AUTOMATIC,SC_FAR) Key
);

SWT_STATIC_FUNC void Swt_DESKeyNext
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx
);

SWT_STATIC_FUNC void Swt_DESKeyPrev
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx
);

SWT_STATIC_FUNC uint8 Swt_DESIsBitSet
(
   P2CONST(uint8, AUTOMATIC,SC_FAR) Data,
   VAR(uint8,AUTOMATIC) Bit
);

SWT_STATIC_FUNC void Swt_DESPermNibble
(
   P2VAR(uint8,AUTOMATIC,SC_FAR) Dst,
   P2CONST(uint8, AUTOMATIC,SC_FAR) Src
);

SWT_STATIC_FUNC void Swt_DESShiftLeftRot
(
   P2VAR(uint8,AUTOMATIC,SC_FAR) Data,
   VAR(uint8,AUTOMATIC) Count
);

SWT_STATIC_FUNC void Swt_DESPermPC1
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Src,
   P2VAR(uint8,AUTOMATIC,SC_FAR) Dst
);

SWT_STATIC_FUNC void Swt_DESPermPC2
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Src,
   P2VAR(uint8,AUTOMATIC,SC_FAR) Dst
);

SWT_STATIC_FUNC void Swt_DESPermInitial
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Src,
   P2VAR(uint8,AUTOMATIC,SC_FAR) Dst,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) PermTable
);

SWT_STATIC_FUNC void Swt_DESPermExpansion
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Src,
   P2VAR(uint8,AUTOMATIC,SC_FAR) Dst
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

#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"

                                                    /* initial permutation IP */
SWT_STATIC_VAR const uint8 Swt_DESInitialPerm [64] =
{
   (uint8)57, (uint8)49, (uint8)41, (uint8)33,
   (uint8)25, (uint8)17, (uint8) 9, (uint8) 1,
   (uint8)59, (uint8)51, (uint8)43, (uint8)35,
   (uint8)27, (uint8)19, (uint8)11, (uint8) 3,
   (uint8)61, (uint8)53, (uint8)45, (uint8)37,
   (uint8)29, (uint8)21, (uint8)13, (uint8) 5,
   (uint8)63, (uint8)55, (uint8)47, (uint8)39,
   (uint8)31, (uint8)23, (uint8)15, (uint8) 7,
   (uint8)56, (uint8)48, (uint8)40, (uint8)32,
   (uint8)24, (uint8)16, (uint8) 8, (uint8) 0,
   (uint8)58, (uint8)50, (uint8)42, (uint8)34,
   (uint8)26, (uint8)18, (uint8)10, (uint8) 2,
   (uint8)60, (uint8)52, (uint8)44, (uint8)36,
   (uint8)28, (uint8)20, (uint8)12, (uint8) 4,
   (uint8)62, (uint8)54, (uint8)46, (uint8)38,
   (uint8)30, (uint8)22, (uint8)14, (uint8) 6
};

                                            /* initial inverse permutation IP */
SWT_STATIC_VAR const uint8 Swt_DESInvInitialPerm [64] =
{
   (uint8)39, (uint8) 7, (uint8)47, (uint8)15,
   (uint8)55, (uint8)23, (uint8)63, (uint8)31,
   (uint8)38, (uint8) 6, (uint8)46, (uint8)14,
   (uint8)54, (uint8)22, (uint8)62, (uint8)30,
   (uint8)37, (uint8) 5, (uint8)45, (uint8)13,
   (uint8)53, (uint8)21, (uint8)61, (uint8)29,
   (uint8)36, (uint8) 4, (uint8)44, (uint8)12,
   (uint8)52, (uint8)20, (uint8)60, (uint8)28,
   (uint8)35, (uint8) 3, (uint8)43, (uint8)11,
   (uint8)51, (uint8)19, (uint8)59, (uint8)27,
   (uint8)34, (uint8) 2, (uint8)42, (uint8)10,
   (uint8)50, (uint8)18, (uint8)58, (uint8)26,
   (uint8)33, (uint8) 1, (uint8)41, (uint8) 9,
   (uint8)49, (uint8)17, (uint8)57, (uint8)25,
   (uint8)32, (uint8) 0, (uint8)40, (uint8) 8,
   (uint8)48, (uint8)16, (uint8)56, (uint8)24
};

#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"

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
** FUNC-NAME      : Swt_DESInit                                             **
**                                                                            **
** DESCRIPTION    : Initialize the provided DES context which contains        **
**                  all round keys.                                           **
**                                                                            **
** PRECONDITIONS  : 'Ctx' shall be a valid pointer (not checked)              **
**                  'Key' shall be a valid pointer (not checked)              **
**                                                                            **
** POSTCONDITIONS : After return the context is initialized correctly for     **
**                  the first call of Swt_DESEncryptBlock or                **
                    Swt_DESDecryptBlock.                                    **
**                                                                            **
** PARAMETER      : Ctx : Pointer to the context to initialize.               **
**                  Key : Pointer to the symmetric key for en-/decryption     **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : Constant time for all inputs.                             **
**                                                                            **
*******************************************************************************/
void Swt_DESInit
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Key
)
{
   uint8_least i;
                                             /* permutation of key input data */
   uint8 permutatedKey[SWT_DES_BLOCKSIZE];

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
   /* This table defines the DES key schedule shift.                          */
   /* round 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16             */
   /* shift 1, 1, 2, 2, 2, 2, 2, 2, 1,  2,  2,  2,  2,  2,  2,  1             */
   SWT_STATIC_VAR const uint8 Swt_DESKeyShiftTable [SWT_DES_ROUNDS] =
   {
      (uint8)1, (uint8)1, (uint8)2, (uint8)2,
      (uint8)2, (uint8)2, (uint8)2, (uint8)2,
      (uint8)1, (uint8)2, (uint8)2, (uint8)2,
      (uint8)2, (uint8)2, (uint8)2, (uint8)1
   };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


   /* The 64-bit key is reduced to 56 bit accordingly DES key schedule        */
   /* through bit selection table PC1                                         */
   Swt_DESPermPC1(Key, permutatedKey);

   /* Split key into two 28-bit halves (C0, D0) and create sixteen round keys */
   /* through rotating the permutatedKey (see Swt_DESKeyShiftTable)         */

                                                  /* loop over all round keys */
   for (i = 0; i < (uint8_least)SWT_DES_ROUNDS; ++i)
   {
      /* shift left half of the key (28 bits) Cn                              */
      Swt_DESShiftLeftRot(permutatedKey,     Swt_DESKeyShiftTable[i]);
      /* shift right half of the key (28 bits) Dn                             */
      Swt_DESShiftLeftRot(&permutatedKey[4], Swt_DESKeyShiftTable[i]);

      /* concatenation of CnDn and reducing to 48 bits                        */
      Swt_DESPermPC2(permutatedKey, Ctx->ExpandedKey[i]);
   }                              /* until all sixteen round keys are created */
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESEncryptBlock                                     **
**                                                                            **
** DESCRIPTION    : Computes the encrypted block                              **
**                                                                            **
** PRECONDITIONS  : 'Ctx' shall be a valid pointer (not checked)              **
**                  'InputBlock' shall be a valid pointer (not checked)       **
**                  'OutputBlock' shall be a valid pointer (not checked)      **
**                                                                            **
** POSTCONDITIONS : After return the output block holds the ciphertext.       **
**                                                                            **
** PARAMETER      : Ctx : Pointer to the context DES context.                 **
**                  InputBlock : Pointer to the plaintext.                    **
**                  OutputBlock : Pointer to the ciphertext.                  **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : Constant time for all inputs.                             **
**                                                                            **
*******************************************************************************/
void Swt_DESEncryptBlock
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx,
   P2CONST(uint8, AUTOMATIC,SC_FAR) InputBlock,
   P2VAR(uint8,AUTOMATIC,SC_FAR) OutputBlock
)
{
   uint8   workBlock[8];       /* temporary work block */
   uint8   permutedInput[8];   /* input permutation result used in rounds     */
   uint8_least i;

   Ctx->NextRoundKeyOffset = (uint8)SWT_DES_NEXT_ENC_START;

   /* Permutes the input block accordingly the initial permutation table IP   */
   Swt_DESPermInitial(InputBlock, permutedInput, Swt_DESInitialPerm);

   i = (uint8_least)SWT_DES_ROUNDS;
   do
   {
      /* The block is divided into eight 6-bit pieces before processing by    */
      /* the S-boxes. Each of the eight S-boxes replaces its six input bits   */
      /* with four output bits according to a non-linear transformation,      */
      /* provided in the form of a lookup table.                              */

      Swt_DESRound
      (
         permutedInput,
         Ctx->ExpandedKey[Ctx->NextRoundKeyOffset]
      );
      Swt_DESKeyNext(Ctx);
      i--;
   } while (i != (uint8_least)0);

                                               /* swap left and a right block */
   (void)Swt_CommonCopy (workBlock, &permutedInput[4], (uint32)4);
   (void)Swt_CommonCopy (&workBlock[4], permutedInput, (uint32)4);

                                          /* Final inverse permutation (IP-1) */
   Swt_DESPermInitial(workBlock, OutputBlock, Swt_DESInvInitialPerm);
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESDecryptBlock                                     **
**                                                                            **
** DESCRIPTION    : Computes the decrypted block                              **
**                                                                            **
** PRECONDITIONS  : 'Ctx' shall be a valid pointer (not checked)              **
**                  'InputBlock' shall be a valid pointer (not checked)       **
**                  'OutputBlock' shall be a valid pointer (not checked)      **
**                                                                            **
** POSTCONDITIONS : After return the output block holds the plaintext .       **
**                                                                            **
** PARAMETER      : Ctx : Pointer to the context DES context.                 **
**                  InputBlock : Pointer to the ciphertext.                   **
**                  OutputBlock : Pointer to the plaintext.                   **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : Constant time for all inputs.                             **
**                                                                            **
*******************************************************************************/
void Swt_DESDecryptBlock
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx,
   P2CONST(uint8, AUTOMATIC,SC_FAR) InputBlock,
   P2VAR(uint8,AUTOMATIC,SC_FAR) OutputBlock
)
{
   uint8   workBlock[8];       /* temporary work block                        */
   uint8   permutedInput[8];   /* input permutation result used in rounds     */
   uint8_least i;

                     /* decrypting uses the same round keys in reversed order */
   Ctx->NextRoundKeyOffset = (uint8)SWT_DES_NEXT_DEC_START;

   /* Permutes the input block accordingly the initial permutation table IP   */
   Swt_DESPermInitial(InputBlock, permutedInput, Swt_DESInitialPerm);

   i = (uint8_least)(SWT_DES_ROUNDS);
   do
   {
      /* The block is divided into eight 6-bit pieces before processing by    */
      /* the S-boxes. Each of the eight S-boxes replaces its six input bits   */
      /* with four output bits according to a non-linear transformation,      */
      /* provided in the form of a lookup table.                              */

      Swt_DESRound
      (
         permutedInput,
         Ctx->ExpandedKey[Ctx->NextRoundKeyOffset]
      );

      Swt_DESKeyPrev(Ctx);
      i--;
   } while (i != (uint8_least)0);

                                               /* swap left and a right block */
   (void)Swt_CommonCopy (workBlock, &permutedInput[4], (uint32)4);
   (void)Swt_CommonCopy (&workBlock[4], permutedInput, (uint32)4);

                                          /* Final inverse permutation (IP-1) */
   Swt_DESPermInitial(workBlock, OutputBlock, Swt_DESInvInitialPerm);
}

/*******************************************************************************
**                      internal function definitions                         **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESRound                                            **
**                                                                            **
** DESCRIPTION    : Computes Li and Ri                                        **
**                                                                            **
** PRECONDITIONS  : - Block is a valid pointer (not checked)                  **
**                  - Key is a valid pointer (not checked)                    **
**                                                                            **
** POSTCONDITIONS : Block contains result of computation of Li and Ri         **
**                                                                            **
** PARAMETER      : Block - pointer to the previous round result              **
**                  Key - round key                                           **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESRound
(
   P2VAR(uint8,AUTOMATIC,SC_FAR) Block,
   P2CONST(uint8, AUTOMATIC,SC_FAR) Key
)
{
   uint8 TempBlock[8];
   uint8 Left[4];
   uint8 SResult[4];
   uint8 PResult[4];
   uint8_least i;

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
                                                                   /* S-Boxes */
   SWT_STATIC_VAR const uint8 Swt_DESSBox12 [SWT_DES_SBOX_LEN] =
   {
      (uint8)0xef, (uint8)0x03, (uint8)0x41, (uint8)0xfd,
      (uint8)0xd8, (uint8)0x74, (uint8)0x1e, (uint8)0x47,
      (uint8)0x26, (uint8)0xef, (uint8)0xfb, (uint8)0x22,
      (uint8)0xb3, (uint8)0xd8, (uint8)0x84, (uint8)0x1e,
      (uint8)0x39, (uint8)0xac, (uint8)0xa7, (uint8)0x60,
      (uint8)0x62, (uint8)0xc1, (uint8)0xcd, (uint8)0xba,
      (uint8)0x5c, (uint8)0x96, (uint8)0x90, (uint8)0x59,
      (uint8)0x05, (uint8)0x3b, (uint8)0x7a, (uint8)0x85,
      (uint8)0x40, (uint8)0xfd, (uint8)0x1e, (uint8)0xc8,
      (uint8)0xe7, (uint8)0x8a, (uint8)0x8b, (uint8)0x21,
      (uint8)0xda, (uint8)0x43, (uint8)0x64, (uint8)0x9f,
      (uint8)0x2d, (uint8)0x14, (uint8)0xb1, (uint8)0x72,
      (uint8)0xf5, (uint8)0x5b, (uint8)0xc8, (uint8)0xb6,
      (uint8)0x9c, (uint8)0x37, (uint8)0x76, (uint8)0xec,
      (uint8)0x39, (uint8)0xa0, (uint8)0xa3, (uint8)0x05,
      (uint8)0x52, (uint8)0x6e, (uint8)0x0f, (uint8)0xd9
   };

   SWT_STATIC_VAR const uint8 Swt_DESSBox34 [SWT_DES_SBOX_LEN] =
   {
      (uint8)0xa7, (uint8)0xdd, (uint8)0x0d, (uint8)0x78,
      (uint8)0x9e, (uint8)0x0b, (uint8)0xe3, (uint8)0x95,
      (uint8)0x60, (uint8)0x36, (uint8)0x36, (uint8)0x4f,
      (uint8)0xf9, (uint8)0x60, (uint8)0x5a, (uint8)0xa3,
      (uint8)0x11, (uint8)0x24, (uint8)0xd2, (uint8)0x87,
      (uint8)0xc8, (uint8)0x52, (uint8)0x75, (uint8)0xec,
      (uint8)0xbb, (uint8)0xc1, (uint8)0x4c, (uint8)0xba,
      (uint8)0x24, (uint8)0xfe, (uint8)0x8f, (uint8)0x19,
      (uint8)0xda, (uint8)0x13, (uint8)0x66, (uint8)0xaf,
      (uint8)0x49, (uint8)0xd0, (uint8)0x90, (uint8)0x06,
      (uint8)0x8c, (uint8)0x6a, (uint8)0xfb, (uint8)0x91,
      (uint8)0x37, (uint8)0x8d, (uint8)0x0d, (uint8)0x78,
      (uint8)0xbf, (uint8)0x49, (uint8)0x11, (uint8)0xf4,
      (uint8)0x23, (uint8)0xe5, (uint8)0xce, (uint8)0x3b,
      (uint8)0x55, (uint8)0xbc, (uint8)0xa2, (uint8)0x57,
      (uint8)0xe8, (uint8)0x22, (uint8)0x74, (uint8)0xce
   };

   SWT_STATIC_VAR const uint8 Swt_DESSBox56 [SWT_DES_SBOX_LEN] =
   {
      (uint8)0x2c, (uint8)0xea, (uint8)0xc1, (uint8)0xbf,
      (uint8)0x4a, (uint8)0x24, (uint8)0x1f, (uint8)0xc2,
      (uint8)0x79, (uint8)0x47, (uint8)0xa2, (uint8)0x7c,
      (uint8)0xb6, (uint8)0xd9, (uint8)0x68, (uint8)0x15,
      (uint8)0x80, (uint8)0x56, (uint8)0x5d, (uint8)0x01,
      (uint8)0x33, (uint8)0xfd, (uint8)0xf4, (uint8)0xae,
      (uint8)0xde, (uint8)0x30, (uint8)0x07, (uint8)0x9b,
      (uint8)0xe5, (uint8)0x83, (uint8)0x9b, (uint8)0x68,
      (uint8)0x49, (uint8)0xb4, (uint8)0x2e, (uint8)0x83,
      (uint8)0x1f, (uint8)0xc2, (uint8)0xb5, (uint8)0x7c,
      (uint8)0xa2, (uint8)0x19, (uint8)0xd8, (uint8)0xe5,
      (uint8)0x7c, (uint8)0x2f, (uint8)0x83, (uint8)0xda,
      (uint8)0xf7, (uint8)0x6b, (uint8)0x90, (uint8)0xfe,
      (uint8)0xc4, (uint8)0x01, (uint8)0x5a, (uint8)0x97,
      (uint8)0x61, (uint8)0xa6, (uint8)0x3d, (uint8)0x40,
      (uint8)0x0b, (uint8)0x58, (uint8)0xe6, (uint8)0x3d
   };

   SWT_STATIC_VAR const uint8 Swt_DESSBox78 [SWT_DES_SBOX_LEN] =
   {
      (uint8)0x4d, (uint8)0xd1, (uint8)0xb2, (uint8)0x0f,
      (uint8)0x28, (uint8)0xbd, (uint8)0xe4, (uint8)0x78,
      (uint8)0xf6, (uint8)0x4a, (uint8)0x0f, (uint8)0x93,
      (uint8)0x8b, (uint8)0x17, (uint8)0xd1, (uint8)0xa4,
      (uint8)0x3a, (uint8)0xec, (uint8)0xc9, (uint8)0x35,
      (uint8)0x93, (uint8)0x56, (uint8)0x7e, (uint8)0xcb,
      (uint8)0x55, (uint8)0x20, (uint8)0xa0, (uint8)0xfe,
      (uint8)0x6c, (uint8)0x89, (uint8)0x17, (uint8)0x62,
      (uint8)0x17, (uint8)0x62, (uint8)0x4b, (uint8)0xb1,
      (uint8)0xb4, (uint8)0xde, (uint8)0xd1, (uint8)0x87,
      (uint8)0xc9, (uint8)0x14, (uint8)0x3c, (uint8)0x4a,
      (uint8)0x7e, (uint8)0xa8, (uint8)0xe2, (uint8)0x7d,
      (uint8)0xa0, (uint8)0x9f, (uint8)0xf6, (uint8)0x5c,
      (uint8)0x6a, (uint8)0x09, (uint8)0x8d, (uint8)0xf0,
      (uint8)0x0f, (uint8)0xe3, (uint8)0x53, (uint8)0x25,
      (uint8)0x95, (uint8)0x36, (uint8)0x28, (uint8)0xcb
   };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


   /* Copy the right value, it will be the new left value after the round.    */
   (void)Swt_CommonCopy(Left, &Block[4], (uint32)4);

   /* The 32-bit half-block is expanded to 48 bits using the expansion        */
   /* permutation E.                                                          */

   Swt_DESPermExpansion(&Block[4], TempBlock);

   /* The result is combined with a round key using an XOR operation          */
   for (i=0; i < (uint8_least)8; i++)
   {
      TempBlock[i] ^= Key[i];
   }

   /* The block is divided into eight 6-bit pieces before processing by the   */
   /* S-boxes. Each of the eight S-boxes replaces its six input bits with     */
   /* four output bits according to a non-linear transformation, provided in  */
   /* the form of a lookup table.                                             */

   SResult[0]  =         Swt_DESSBox12[TempBlock[0]] & (uint8)0xf0 ;
   SResult[0] |= (uint8)(Swt_DESSBox12[TempBlock[1]] & (uint8)0x0f);
   SResult[1]  =         Swt_DESSBox34[TempBlock[2]] & (uint8)0xf0 ;
   SResult[1] |= (uint8)(Swt_DESSBox34[TempBlock[3]] & (uint8)0x0f);
   SResult[2]  =         Swt_DESSBox56[TempBlock[4]] & (uint8)0xf0 ;
   SResult[2] |= (uint8)(Swt_DESSBox56[TempBlock[5]] & (uint8)0x0f);
   SResult[3]  =         Swt_DESSBox78[TempBlock[6]] & (uint8)0xf0 ;
   SResult[3] |= (uint8)(Swt_DESSBox78[TempBlock[7]] & (uint8)0x0f);

   /* The 32 outputs from the S-boxes are rearranged according to a fixed     */
   /* permutation (P-box)                                                     */
   Swt_DESPermNibble (PResult, SResult);

   for (i = 0; i < (uint8_least)4; i++)
   {
      Block[4+i] = PResult[i] ^ Block[i];
   }

   /* Copy the saved right value into the computed block                      */
   (void)Swt_CommonCopy(Block, Left, (uint32)4);
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESKeyNext                                          **
**                                                                            **
** DESCRIPTION    : sets the key parameters in context 'ctx' to the next      **
**                  round key                                                 **
**                                                                            **
** PRECONDITIONS  : - Ctx is a valid pointer (not checked)                    **
**                  - Ctx points to a valid DESContext (not checked)          **
**                  - Ctx has been initialized by a successful call to the    **
**                    function Swt_DESInit().                               **
**                    (not checked)                                           **
**                                                                            **
** POSTCONDITIONS : the given context 'Ctx' has been changed to work with     **
**                     the next round key                                     **
**                                                                            **
** PARAMETER      : Ctx - pointer to an DES context                           **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESKeyNext
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx
)
{
   /* SWT_STATIC_FUNC: just "hop" to next round key */
   Ctx->NextRoundKeyOffset += (uint8)1;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESKeyPrev                                          **
**                                                                            **
** DESCRIPTION    : sets the key parameters in context 'ctx' to the           **
**                  previous round key                                        **
**                                                                            **
** PRECONDITIONS  : - Ctx is a valid pointer (not checked)                    **
**                  - Ctx points to a valid DESContext (not checked)          **
**                  - Ctx has been initialized by a successful call to the    **
**                    function Swt_DESInit().                               **
**                    (not checked)                                           **
**                                                                            **
** POSTCONDITIONS : the given context 'Ctx' has been changed to work with     **
**                  the previous round key                                    **
**                                                                            **
** PARAMETER      : Ctx - pointer to an DES context                           **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESKeyPrev
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx
)
{
   /* SWT_STATIC_FUNC scheduling: just "hop" to prev round key */
   Ctx->NextRoundKeyOffset -= (uint8)1;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESIsBitSet                                         **
**                                                                            **
** DESCRIPTION    : Test bit in array of four bytes (64bit value)             **
**                                                                            **
** PRECONDITIONS  : - Data is a valid pointer (not checked)                   **
**                  - Bit is a valid value                                    **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
**                                                                            **
** PARAMETER      : Data - pointer to an 4 bytes array (64-bit value)         **
**                  Bit - bit number in array                                 **
**                                                                            **
** RETURN         : uint8 - returns 1 if bit is set                           **
**                          returns 0 if bit is not set                       **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC uint8 Swt_DESIsBitSet
(
 P2CONST(uint8, AUTOMATIC,SC_FAR) Data,
 VAR(uint8,AUTOMATIC) Bit
)
{
   return (Data[Bit >> 3] & (uint8)(0x80 >> (Bit & (uint8)0x07)));
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESPermNibble                                       **
**                                                                            **
** DESCRIPTION    : The 32 outputs from the S-boxes are rearranged according  **
**                  to a fixed permutation (P-box).                           **
**                                                                            **
** PRECONDITIONS  : - Dst is a valid pointer (not checked)                    **
**                  - Src is a valid pointer (not checked)                    **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
**                                                                            **
** PARAMETER      : Dst - pointer to the output data                          **
**                  Src - pointer to the input data                           **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESPermNibble
(
   P2VAR(uint8,AUTOMATIC,SC_FAR) Dst,
   P2CONST(uint8, AUTOMATIC,SC_FAR) Src
)
{
   uint8_least i,j;

#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"
                                                   /* P-Box fixed permutation */
   SWT_STATIC_VAR const uint8 Swt_DESPermBox[4][8] =
   {
      { (uint8)15, (uint8) 6, (uint8)19, (uint8)20,
        (uint8)28, (uint8)11, (uint8)27, (uint8)16 },
      { (uint8) 0, (uint8)14, (uint8)22, (uint8)25,
        (uint8) 4, (uint8)17, (uint8)30, (uint8) 9 },
      { (uint8) 1, (uint8) 7, (uint8)23, (uint8)13,
        (uint8)31, (uint8)26, (uint8) 2, (uint8) 8 },
      { (uint8)18, (uint8)12, (uint8)29, (uint8) 5,
        (uint8)21, (uint8)10, (uint8) 3, (uint8)24 }
   };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"

   /* loop through the bytes                                                  */
   for (i=0; i < (uint8_least)4; i++)
   {
      Dst[i] = 0;                             /* initialize destination value */

      /* loop through the bits                                                */
      for (j=0; j < (uint8_least)8; j++)
      {
         /* If the bit in the current table entry is set in the input data,   */
         /* set it in the output data too.                                    */
         if (Swt_DESIsBitSet(Src, Swt_DESPermBox[i][j]))
         {
            Dst[i] |= (uint8)((uint8)SWT_DES_PBOX_BIT_LEN >> j);
         }
      }
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESPermPC1                                          **
**                                                                            **
** DESCRIPTION    : The 64-bit key is reduced to 56 bit accordingly DES key   **
**                  schedule through bit selection table PC1.                 **
**                                                                            **
** PRECONDITIONS  : - Dst is a valid pointer (not checked)                    **
**                  - Src is a valid pointer (not checked)                    **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
**                                                                            **
** PARAMETER      : Dst - pointer to the output data                          **
**                  Src - pointer to the input data                           **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESPermPC1
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Src,
  P2VAR(uint8,AUTOMATIC,SC_FAR) Dst
)
{
   uint8_least i,j;                                        /* Permutation PC1 */

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
             /* This table defines the DES key schedule bit selections (PC1). */
   SWT_STATIC_VAR const uint8 Swt_DESKeySchedulePC1[8][7]  =
   {
      {(uint8)56,(uint8)48,(uint8)40,(uint8)32,(uint8)24,(uint8)16,(uint8) 8},
      {(uint8) 0,(uint8)57,(uint8)49,(uint8)41,(uint8)33,(uint8)25,(uint8)17},
      {(uint8) 9,(uint8) 1,(uint8)58,(uint8)50,(uint8)42,(uint8)34,(uint8)26},
      {(uint8)18,(uint8)10,(uint8) 2,(uint8)59,(uint8)51,(uint8)43,(uint8)35},
      {(uint8)62,(uint8)54,(uint8)46,(uint8)38,(uint8)30,(uint8)22,(uint8)14},
      {(uint8) 6,(uint8)61,(uint8)53,(uint8)45,(uint8)37,(uint8)29,(uint8)21},
      {(uint8)13,(uint8) 5,(uint8)60,(uint8)52,(uint8)44,(uint8)36,(uint8)28},
      {(uint8)20,(uint8)12,(uint8) 4,(uint8)27,(uint8)19,(uint8)11,(uint8) 3}
   };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


   for (i=0; i < (uint8_least)8; i++)
   {
      Dst[i] = 0;                             /* initialize destination value */

      for (j=0; j < (uint8_least)7; j++)
      {
         if (Swt_DESIsBitSet(Src, Swt_DESKeySchedulePC1[i][j]))
         {
            Dst[i] |= (uint8)((uint8)SWT_DES_KEY_SCHED_PC1_BIT_LEN >> j);
         }
      }
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESPermPC2                                          **
**                                                                            **
** DESCRIPTION    : Reducing the key to 48 bits                               **
**                                                                            **
** PRECONDITIONS  : - Dst is a valid pointer (not checked)                    **
**                  - Src is a valid pointer (not checked)                    **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
**                                                                            **
** PARAMETER      : Dst - pointer to the output data                          **
**                  Src - pointer to the input data                           **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESPermPC2
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Src,
  P2VAR(uint8,AUTOMATIC,SC_FAR) Dst
)
{
   uint8_least i,j;                                        /* Permutation PC2 */

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
             /* This table defines the DES key schedule bit selections (PC2). */
   SWT_STATIC_VAR const uint8 Swt_DESKeySchedulePC2[8][6] =
   {
      { (uint8)15, (uint8)19, (uint8)12, (uint8)27, (uint8) 1, (uint8) 5 },
      { (uint8) 3, (uint8)31, (uint8)17, (uint8) 6, (uint8)23, (uint8)11 },
      { (uint8)26, (uint8)21, (uint8)13, (uint8) 4, (uint8)29, (uint8) 9 },
      { (uint8)18, (uint8) 7, (uint8)30, (uint8)22, (uint8)14, (uint8) 2 },
      { (uint8)46, (uint8)59, (uint8)35, (uint8)42, (uint8)53, (uint8)62 },
      { (uint8)34, (uint8)45, (uint8)58, (uint8)51, (uint8)37, (uint8)54 },
      { (uint8)50, (uint8)55, (uint8)44, (uint8)63, (uint8)38, (uint8)60 },
      { (uint8)52, (uint8)47, (uint8)57, (uint8)41, (uint8)33, (uint8)36 }
   };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


   for (i=0; i < (uint8_least)8; i++)
   {
      Dst[i] = 0;                             /* initialize destination value */

      for (j=0; j < (uint8_least)6; j++)
      {
         if (Swt_DESIsBitSet(Src, Swt_DESKeySchedulePC2[i][j]))
         {
            Dst[i] |= (uint8)((uint8)SWT_DES_KEY_SCHED_PC2_BIT_LEN >> j);
         }
      }
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESPermInitial                                      **
**                                                                            **
** DESCRIPTION    : Initial Permutation                                       **
**                                                                            **
** PRECONDITIONS  : - Dst is a valid pointer (not checked)                    **
**                  - Src is a valid pointer (not checked)                    **
**                  - PermTable is a valid pointer (not checked)              **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
**                                                                            **
** PARAMETER      : Dst - pointer to the output data                          **
**                  Src - pointer to the input data                           **
**                  PermTable - initial (inverse) permutation table           **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESPermInitial
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Src,
  P2VAR(uint8,AUTOMATIC,SC_FAR) Dst,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) PermTable
)
{
   uint8_least i,j;                              /* Initial (Inv-)Permutation */

   for (i=0; i < (uint8_least)8; i++)
   {
      Dst[i] = 0;                             /* initialize destination value */

      for (j=0; j < (uint8_least)8; j++)
      {
         if (Swt_DESIsBitSet(Src, PermTable[(i * 8) + j]))
         {
            Dst[i] |= (uint8)((uint8)SWT_DES_INITIAL_PERM_BIT_LEN >> j);
         }
      }
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESPermExpansion                                    **
**                                                                            **
** DESCRIPTION    : The 32-bit half-block is expanded to 48 bits using the    **
**                  expansion permutation E.                                  **
**                                                                            **
** PRECONDITIONS  : - Dst is a valid pointer (not checked)                    **
**                  - Src is a valid pointer (not checked)                    **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
**                                                                            **
** PARAMETER      : Dst - pointer to the output data                          **
**                  Src - pointer to the input data                           **
**                  PermTable - initial (inverse) permutation table           **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESPermExpansion
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Src,
  P2VAR(uint8,AUTOMATIC,SC_FAR) Dst
)
{
   uint8_least i,j;                              /* Permutation Key Expansion */

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
                                                               /* expansion E */
   SWT_STATIC_VAR const uint8 Swt_DESExpansion [8][6] =
   {
      { (uint8)31, (uint8) 0, (uint8) 1, (uint8) 2, (uint8) 3, (uint8) 4 },
      { (uint8) 3, (uint8) 4, (uint8) 5, (uint8) 6, (uint8) 7, (uint8) 8 },
      { (uint8) 7, (uint8) 8, (uint8) 9, (uint8)10, (uint8)11, (uint8)12 },
      { (uint8)11, (uint8)12, (uint8)13, (uint8)14, (uint8)15, (uint8)16 },
      { (uint8)15, (uint8)16, (uint8)17, (uint8)18, (uint8)19, (uint8)20 },
      { (uint8)19, (uint8)20, (uint8)21, (uint8)22, (uint8)23, (uint8)24 },
      { (uint8)23, (uint8)24, (uint8)25, (uint8)26, (uint8)27, (uint8)28 },
      { (uint8)27, (uint8)28, (uint8)29, (uint8)30, (uint8)31, (uint8) 0 }
   };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


   for (i=0; i < (uint8_least)8; i++)
   {
      Dst[i] = 0;                             /* initialize destination value */

      for (j=0; j < (uint8_least)6; j++)
      {
         if (Swt_DESIsBitSet(Src, Swt_DESExpansion[i][j]))
         {
            Dst[i] |= (uint8)((uint8)SWT_DES_EXPANSION_BIT_LEN >> j);
         }
      }
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DESShiftLeftRot                                     **
**                                                                            **
** DESCRIPTION    : Shift left rotate of the key (28 bits).                   **
**                                                                            **
** PRECONDITIONS  : - Data is a valid pointer (not checked)                   **
**                  - Count is a valid value                                  **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
**                                                                            **
** PARAMETER      : Data - pointer to the input data                          **
**                  Count - number of shifts                                  **
**                                                                            **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant timing for all input                             **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void Swt_DESShiftLeftRot
(
   P2VAR(uint8,AUTOMATIC,SC_FAR) Data,
   VAR(uint8,AUTOMATIC) Count
)
{
   uint8  Carry;                                                /* carry flag */
   uint8_least i;

   /* This function left rotates bytewise (7bit arithmetic).                  */
   /* 1. shift Count bits to left                                             */
   /* 2. add carry */
   /* 3. save carry for next byte                                             */
   /* 4. remove highest bit                                                   */
   /* 5. add carry from highest to lowest byte (see rotate)                   */

   /* loop over for every shift                                               */
   do
   {
      Carry = 0;                                            /* init carry bit */

      /* loop over key                                                        */
      for (i=0; i < (uint8_least)4; i++)
      {
         Data[3-i] <<= (uint8)1;               /* shift one bit left (parity) */
         Data[3-i] |= Carry;                   /* add carry from last byte    */

                                             /* calculate carry for next byte */
         Carry = (uint8)(Data[3-i] & (uint8)0x80) >> 7;
         Data[3-i] &= (uint8)0x7f;                        /* remove carry bit */

      }
      Data[3] |= Carry;

      --Count;
   }
   while (Count);
}

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
