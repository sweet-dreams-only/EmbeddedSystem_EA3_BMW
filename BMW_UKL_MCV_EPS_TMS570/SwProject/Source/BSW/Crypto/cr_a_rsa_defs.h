/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_a_rsa_defs.h                                               **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : defines for the RSA routines                                  **
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
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V5.0.0: 21.09.2006, mg : code clean-ups
 *         11.08.2006, mg : improved formatting
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

#if !defined( CR_A_RSA_DEFS_H )
#define CR_A_RSA_DEFS_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/




#if (CRYPTO_BOOT_SIG_KEY_SIZE == 512U)

    /* 512-Bit -> number of used unsigned longs = 16 + 1 long length          */
    #define CR_DEF_SIG_KEY_LENGTH   (16ul + 1ul)

#elif (CRYPTO_BOOT_SIG_KEY_SIZE == 768U)

    /* 768-Bit -> number of used unsigned longs = 24 + 1 long length          */
    #define CR_DEF_SIG_KEY_LENGTH   (24ul + 1ul)

#elif (CRYPTO_BOOT_SIG_KEY_SIZE == 1024U)

    /* 1024-Bit -> number of used unsigned longs = 32 + 1 long length          */
    #define CR_DEF_SIG_KEY_LENGTH   (32ul+1ul)

#elif (CRYPTO_BOOT_SIG_KEY_SIZE == 1536U)

    /* 1536-Bit -> number of used unsigned longs = 48 + 1 long length         */
    #define CR_DEF_SIG_KEY_LENGTH   (48ul + 1ul)

#elif (CRYPTO_BOOT_SIG_KEY_SIZE == 2048U)

    /* 2048-Bit -> number of used unsigned longs = 64 + 1 long length         */
    #define CR_DEF_SIG_KEY_LENGTH   (64ul + 1ul)

#else

    #error cr_a_rsa_defs.h: Incorrect signature key size!

#endif


#if (CRYPTO_AUTH_KEY_SIZE == 512U)

    /* 512-Bit -> number of used unsigned longs = 16 + 1 long length          */
    #define CR_DEF_AUTH_KEY_LENGTH  (16 + 1)

#elif (CRYPTO_AUTH_KEY_SIZE == 768U)

    /* 768-Bit -> number of used unsigned longs = 24 + 1 long length          */
    #define CR_DEF_AUTH_KEY_LENGTH  (24 + 1)

#elif (CRYPTO_AUTH_KEY_SIZE == 1024U)

    /* 1024-Bit -> number of used unsigned longs = 32 + 1 long length         */
    #define CR_DEF_AUTH_KEY_LENGTH  (32+1)

#elif (CRYPTO_AUTH_KEY_SIZE == 1536U)

    /* 1536-Bit -> number of used unsigned longs = 48 + 1 long length         */
    #define CR_DEF_AUTH_KEY_LENGTH  (48 + 1)

#elif (CRYPTO_AUTH_KEY_SIZE == 2048U)

    /* 2048-Bit -> number of used unsigned longs = 64 + 1 long length         */
    #define CR_DEF_AUTH_KEY_LENGTH  (64 + 1)

#else

    #error cr_a_rsa_defs.h: Incorrect authentication key size!

#endif




#if (CRYPTO_CODING_SIG_KEY_SIZE == 512U)

   /* 512-Bit -> number of used unsigned longs = 16 + 1 long length          */
    #define CR_DEF_NCD_SIG_KEY_LENGTH   (16ul + 1ul)

#elif (CRYPTO_CODING_SIG_KEY_SIZE == 768U)

    /* 768-Bit -> number of used unsigned longs = 24 + 1 long length          */
    #define CR_DEF_NCD_SIG_KEY_LENGTH   (24ul + 1ul)

#elif (CRYPTO_CODING_SIG_KEY_SIZE == 1024U)

    /* 1024-Bit -> number of used unsigned longs = 32 + 1 long length         */
    #define CR_DEF_NCD_SIG_KEY_LENGTH   (32ul+1ul)

#elif (CRYPTO_CODING_SIG_KEY_SIZE == 1536U)

    /* 1536-Bit -> number of used unsigned longs = 48 + 1 long length         */
    #define CR_DEF_NCD_SIG_KEY_LENGTH   (48ul + 1ul)

#elif (CRYPTO_CODING_SIG_KEY_SIZE == 2048U)

    /* 2048-Bit -> number of used unsigned longs = 64 + 1 long length         */
    #define CR_DEF_NCD_SIG_KEY_LENGTH   (64ul + 1ul)

#else

    #error cr_a_rsa_defs.h: Incorrect coding key size!

#endif



#if (CR_DEF_SIG_KEY_LENGTH >= CR_DEF_NCD_SIG_KEY_LENGTH)
   #if (CR_DEF_SIG_KEY_LENGTH >= CR_DEF_AUTH_KEY_LENGTH)
      #define CR_DEF_MAX_KEY_LENGTH CR_DEF_SIG_KEY_LENGTH
   #else
      #define CR_DEF_MAX_KEY_LENGTH CR_DEF_AUTH_KEY_LENGTH
   #endif
#elif (CR_DEF_NCD_SIG_KEY_LENGTH >= CR_DEF_AUTH_KEY_LENGTH)
   #define CR_DEF_MAX_KEY_LENGTH CR_DEF_NCD_SIG_KEY_LENGTH
#else
   #define CR_DEF_MAX_KEY_LENGTH CR_DEF_AUTH_KEY_LENGTH
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* if !defined( CR_A_RSA_DEFS_H ) */
/*** End of file **************************************************************/
