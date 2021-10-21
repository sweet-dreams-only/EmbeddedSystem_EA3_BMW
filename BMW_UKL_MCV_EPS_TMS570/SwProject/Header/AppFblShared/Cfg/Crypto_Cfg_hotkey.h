/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Crypto_Keys.h                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : ASBC / SWL-SEC   (through secunet AG)                         **
**                                                                            **
**  PURPOSE   : EE and SGBM-Nr relevant crypto keys are stored there.         **
**                                                                            **

**  REMARKS   : This is a automatic generated header file.                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                  (only for Telex keys!)                    **
**                                                                            **
** WARNING:                                                                   **
**  - PLEASE DO NOT MANIPULATE THIS FILE. Elsewhere no authentication and swe **
**    Signature check will be possible with PSdZ.	                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** rw           Richard Wimmer             secunet AG                         **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
********************************************************************************

** V01.00 : 21.10.2009, rw: initial version with all replacements for SWL-SEC;**
**                          removed global macro for auth key length          **
**                          and set level 0-2 keys to key size 512 (asym) and **
**                          128 Bit (symm);                                   **
**                          variable AUTHENTICATION_METHOD isn't needed,      **
**                          because SWL-SEC knowns exacly, what key algorithm **
**                          was requested by KIFA_KV                          **
** V01.01 : 23.11.2009, rw: Added flags of level usage and telex key as dummy;**
**                          fill all notused authlevel keys with zero values; **
**                          variable CRYPTO_AUTH_KEY_SIZE re-integrated,      **
** V01.02 : 29.09.2010, ah: Changed flags for CR_DEF_USE_LEVELx and           **
**                          CR_DEF_TELESERVICE from ON/OFF to STD_ON/STD_OFF  **
**                          to observe the Autosar standard                   **
********************************************************************************/

/*******************************************************************************
**                      ASBC / SWL-SEC relevant data                          **
********************************************************************************
**                                                                            **
** SGBM-Nr:     00001891                                                     **
** Requester:   C408231_from_199.107.26.250                                                   **
** Build-Date:  06.10.2011                                                  **
** Build-Time:  17:44:46                                                  **
**                                                                            **
*******************************************************************************/

/*************************************************************************************************************************
 * Version Control:
 * Date Created:      Wed Oct 19 12:16:01 2011
 * %version:          EA3#2 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Thu Oct 20 10:20:06 2011 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 10/20/11   1        BDO        Initial version - integrate BMW Crypto_Cfg_hotkey.h file
 * 10/05/16	 EA3#12    ABS		  Authentication and Signature changes - 2048bit key and SHA256 hash		     EA3#7986

*************************************************************************************************************************/

#ifndef CRYPTO_KEYS_H
#define CRYPTO_KEYS_H

/*******************************************************************************
**                      Global Macros                                         **
********************************************************************************/
/* Authentication */

#define CRYPTO_AUTH_ASYM                 		/* Defines that asymmetrical authentication is to be used   	*/
#define CRYPTO_AUTH_ASYM_DIGEST_SHA256	 		/* Asymmetrical authentication with digest SHA-256 				*/
#define CRYPTO_AUTH_KEY_SIZE 		  	2048U 	/* The length of the asymmetrical authentication key in bits. 	*/
									        	/* Allowed  - 512, 768, 1024, 1536, and 2048.  					*/

/* Signature */

#define CRYPTO_SIG_ASYM                  		/* Defines that asymmetrical signature check is to be used  	*/
#define CRYPTO_SIG_ASYM_DIGEST_SHA256  			/* Asymmetrical signature with digest SHA-256 					*/
#define CRYPTO_BOOT_SIG_KEY_SIZE 		2048U   /* The length of the asymmetrical signature key in bits 		*/
												/* Allowed - 512, 768, 1024, 1536, and 2048.    				*/


/* Coding */
#define CRYPTO_NCD_ASYM                  		/* Defines that asymmetrical coding check is to be used     	*/
#define CRYPTO_NCD_ASYM_DIGEST_SHA256			/* Asymmetrical coding with digest SHA-256 						*/
#define CRYPTO_CODING_SIG_KEY_SIZE 		1024U   /* The length of the asymmetrical coding key in bits 			*/
												/* Allowed - 512, 768, 1024, 1536, and 2048.    				*/



/* Note: If (CRYPTO_CODING_SIG_KEY_SIZE == 2048)
 You can configure the software verification check to be interuptible.
 In such a case the verification is not done in one computation but in
 several smaller steps the so-called cycles.
 The larger the key size is, the longer the longest cycle in a software
 signature verification check will last. On a very slow processor a key
 size of 2048 bit can lead to a cycle time of more than 50ms for some
 cycles of the verification check.     */


/*----------------------------------------------------------------------------*/
/* setup use of CR_DEF_TELESERVICE routines                                   */
/*----------------------------------------------------------------------------*/
                       /* If TeleX Level4 Auth is used, PLEASE SET TO STD_ON. */

#define CR_DEF_TELESERVICE STD_OFF

/*----------------------------------------------------------------------------*/
/* depends on setup of CR_DEF_TELESERVICE.                                    */
/*----------------------------------------------------------------------------*/
#if (CR_DEF_TELESERVICE == STD_ON)
/* AM: this is commented for some reason? */
/* #define CR_DEF_USE_LEVEL0 */     /* used by CAS-merge / CR_DEF_TELESERVICE */
#else                                     /* if (CR_DEF_TELESERVICE == STD_ON)*/
    #define  CR_DEF_USE_LEVEL0 STD_OFF
#endif                                   /* if (CR_DEF_TELESERVICE == STD_ON) */

/*----------------------------------------------------------------------------*/
/* setup use of authentication levels                                         */
/*----------------------------------------------------------------------------*/
#define CR_DEF_USE_LEVEL1 STD_OFF                       /* do not use level 1 */
#define CR_DEF_USE_LEVEL2 STD_OFF                       /* do not use level 2 */
#define CR_DEF_USE_LEVEL3 STD_ON                               /* use level 3 */
#define CR_DEF_USE_LEVEL4 STD_ON                               /* use level 4 */
#define CR_DEF_USE_LEVEL5 STD_OFF                       /* do not use level 5 */

/******************************************************************************
 * symmetric TeleX Level4 Authentication key (!ATTENION! MUST BE CHAGNED)     *
 ******************************************************************************/
/* NULL VALUE KEY: If TeleX Level4 Auth is used, PLEASE CHANGE TO CORRECT KEY. */

   /* control-device authentication, symmetric key used by CR_DEF_TELESERVICE */
#define CRYPTO_SYM_AUTH_SAM_KEY                                                \
   {                                                                           \
      (uint8)0x00U, (uint8)0x00U, (uint8)0x00U, (uint8)0x00U,                  \
      (uint8)0x00U, (uint8)0x00U, (uint8)0x00U, (uint8)0x00U,                  \
      (uint8)0x00U, (uint8)0x00U, (uint8)0x00U, (uint8)0x00U,                  \
      (uint8)0x00U, (uint8)0x00U, (uint8)0x00U, (uint8)0x00U                   \
   }

/******************************************************************************
 * Authentication keys for level 1  (Asymm 512 Bit / symm 128 Bit)            *
 ******************************************************************************/
         /* FIX - DO NOT CHANGE: The asymmetrical level 1 authentication key. */

                                                                   /* modulus */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_1_M                                         \
   {                                                                           \
       (uint32)0x00000000UL,                                                   \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL                              \
    }

                                                             /* Barrett value */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_1_BV                                        \
   {                                                                           \
       (uint32)0x00000000UL,                                                   \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL                              \
    }

/* Public exponent */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_1_PE                                        \
   {                                                                           \
       (uint32)0x00000000UL, (uint32)0x00000000UL                              \
   }

/*******************************************************************************
 * Authentication keys for level 2  (Asymm 512 Bit / symm 128 Bit)             *
 *******************************************************************************/
         /* FIX - DO NOT CHANGE: The asymmetrical level 2 authentication key. */

                                                                   /* modulus */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_2_M                                         \
   {                                                                           \
       (uint32)0x00000000UL,                                                   \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL                              \
    }

                                                             /* Barrett value */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_2_BV                                        \
   {                                                                           \
       (uint32)0x00000000UL,                                                   \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL,                             \
       (uint32)0x00000000UL, (uint32)0x00000000UL                              \
    }

/* Public exponent */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_2_PE                                        \
   {                                                                           \
       (uint32)0x00000000UL, (uint32)0x00000000UL                              \
   }

/*******************************************************************************
 *          Authentication keys for level 3  (2048 Bit)                        *
 *******************************************************************************/
/* Modulus */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_3_M			\
   {                                                  \
      (uint32)0x00000040UL,                           \
      (uint32)0x032138f1UL, (uint32)0xb82109d0UL,     \
      (uint32)0xfb19329fUL, (uint32)0x2b24bc2aUL,     \
      (uint32)0x6e174488UL, (uint32)0x86e359f0UL,     \
      (uint32)0x17e7b3eaUL, (uint32)0x3bced6f8UL,     \
      (uint32)0x32e0c16bUL, (uint32)0xf0365f67UL,     \
      (uint32)0xb47c590bUL, (uint32)0x2dc22a55UL,     \
      (uint32)0x1149c4aeUL, (uint32)0xb693e228UL,     \
      (uint32)0x6432476bUL, (uint32)0xe1ddf092UL,     \
      (uint32)0x803ffa87UL, (uint32)0x80bb2074UL,     \
      (uint32)0xd49e6c5dUL, (uint32)0x099d97fcUL,     \
      (uint32)0x81f62505UL, (uint32)0x82356056UL,     \
      (uint32)0xf76ce25aUL, (uint32)0x7ff432e0UL,     \
      (uint32)0xbf627ae8UL, (uint32)0x1ae97cf5UL,     \
      (uint32)0xd177eb7dUL, (uint32)0x4a1ffa88UL,     \
      (uint32)0x3ba963c7UL, (uint32)0xc263ea46UL,     \
      (uint32)0x06c3a630UL, (uint32)0x537a6499UL,     \
      (uint32)0x5ffdf868UL, (uint32)0x25946869UL,     \
      (uint32)0x6f469c8cUL, (uint32)0x583e73ecUL,     \
      (uint32)0x6337236cUL, (uint32)0xb0562fa7UL,     \
      (uint32)0xff8862f2UL, (uint32)0xe02e9fa3UL,     \
      (uint32)0x0af75f82UL, (uint32)0xe84fe1bfUL,     \
      (uint32)0x029f77e2UL, (uint32)0x01d816d5UL,     \
      (uint32)0xf79ea56cUL, (uint32)0x8229e724UL,     \
      (uint32)0x5154be25UL, (uint32)0x17b81cebUL,     \
      (uint32)0xbf28c103UL, (uint32)0xf2a7e0e8UL,     \
      (uint32)0xbfcaa7a1UL, (uint32)0x2433c3f6UL,     \
      (uint32)0x833331ccUL, (uint32)0xb27cadbdUL,     \
      (uint32)0xb543bf79UL, (uint32)0xc6d20740UL,     \
      (uint32)0xd98859f6UL, (uint32)0x9c9e44ccUL,     \
      (uint32)0x66b964d7UL, (uint32)0xe6369e26UL,     \
      (uint32)0x2549b5f5UL, (uint32)0x31bc792bUL,     \
      (uint32)0x4823cffdUL, (uint32)0xd87b409dUL      \
   }

/* Barrett value */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_3_BV			\
   {                                                  \
      (uint32)0x00000041UL,                           \
      (uint32)0xd3d911a5UL, (uint32)0xb1dcbe2eUL,     \
      (uint32)0x2b53a08bUL, (uint32)0x614e3cdaUL,     \
      (uint32)0xf9ef2984UL, (uint32)0xb84aed3aUL,     \
      (uint32)0x72e1204eUL, (uint32)0xc06b2369UL,     \
      (uint32)0x469ad1f1UL, (uint32)0x661235deUL,     \
      (uint32)0x2aa9e0e4UL, (uint32)0x049c60a7UL,     \
      (uint32)0x633cfb53UL, (uint32)0x174ff431UL,     \
      (uint32)0x89b622d3UL, (uint32)0x282e05ccUL,     \
      (uint32)0xe89342bbUL, (uint32)0x54520fb5UL,     \
      (uint32)0xf70157bfUL, (uint32)0x9926fb9bUL,     \
      (uint32)0x5b9a60a4UL, (uint32)0xdab2f283UL,     \
      (uint32)0xf0e7d6e4UL, (uint32)0x09803a61UL,     \
      (uint32)0x3a1a5672UL, (uint32)0xdfe06393UL,     \
      (uint32)0x45989074UL, (uint32)0x6dd8fe25UL,     \
      (uint32)0xd73734f1UL, (uint32)0xdbdf5c04UL,     \
      (uint32)0xbca6f74fUL, (uint32)0xaf3ba1c0UL,     \
      (uint32)0x2294d8e4UL, (uint32)0x898050b6UL,     \
      (uint32)0x1c6cde27UL, (uint32)0x7287f0f9UL,     \
      (uint32)0x5a4ca9ccUL, (uint32)0xc6e3af90UL,     \
      (uint32)0xcecec923UL, (uint32)0x3d11a32eUL,     \
      (uint32)0xa9771ee9UL, (uint32)0x91b12c0dUL,     \
      (uint32)0x15678deeUL, (uint32)0xb6ff20d2UL,     \
      (uint32)0xd28a1aebUL, (uint32)0xfddb2134UL,     \
      (uint32)0xd3b7ff56UL, (uint32)0xfb31a790UL,     \
      (uint32)0xf8b8405fUL, (uint32)0x40fa545aUL,     \
      (uint32)0xfd404fe6UL, (uint32)0x84bea715UL,     \
      (uint32)0x30550ec1UL, (uint32)0xe2adafd9UL,     \
      (uint32)0x8bc81ae0UL, (uint32)0xd64f579eUL,     \
      (uint32)0x964aec9aUL, (uint32)0x060dd483UL,     \
      (uint32)0xfda9193eUL, (uint32)0x7c6859fdUL,     \
      (uint32)0x36e1bdf5UL, (uint32)0x192d6c2dUL,     \
      (uint32)0x2c148c02UL, (uint32)0x2ebb8d9aUL,     \
      (uint32)0x00000001UL                            \
   }

/* Public exponent */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_3_PE			\
   {                                                  \
      (uint32)0x00000001UL, (uint32)0x00000003UL      \
   }

/*******************************************************************************
 *         Authentication keys for level 4  (2048 Bit)                         *
 *******************************************************************************/
/* Modulus */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_4_M			\
   {                                                  \
      (uint32)0x00000040UL,                           \
      (uint32)0x547f23ddUL, (uint32)0x271c9c88UL,     \
      (uint32)0xfd36091eUL, (uint32)0xc1177037UL,     \
      (uint32)0x5a4bbd2aUL, (uint32)0x2b2302e2UL,     \
      (uint32)0x2e7eab4aUL, (uint32)0x40298acbUL,     \
      (uint32)0x77eefd7eUL, (uint32)0xf2161344UL,     \
      (uint32)0xafe1c387UL, (uint32)0x4aeccc54UL,     \
      (uint32)0xcbe664acUL, (uint32)0xddf776e7UL,     \
      (uint32)0x1aef1053UL, (uint32)0xac0f73c7UL,     \
      (uint32)0x1559fee2UL, (uint32)0xe3ef38d0UL,     \
      (uint32)0x51a2f46bUL, (uint32)0x8ee487aeUL,     \
      (uint32)0xaf70904cUL, (uint32)0xf5c1e73aUL,     \
      (uint32)0x529f5801UL, (uint32)0xa59e7233UL,     \
      (uint32)0x2b4682e1UL, (uint32)0x04a62b20UL,     \
      (uint32)0x96d70f76UL, (uint32)0x978ebe15UL,     \
      (uint32)0x15682090UL, (uint32)0x3d072eccUL,     \
      (uint32)0x9517aa6fUL, (uint32)0x36e68dfdUL,     \
      (uint32)0x329bbdc2UL, (uint32)0x5b8ce1e5UL,     \
      (uint32)0xf24be3e9UL, (uint32)0xdb1425ffUL,     \
      (uint32)0xbea403d9UL, (uint32)0x61fba835UL,     \
      (uint32)0x6ab0f462UL, (uint32)0xc594a115UL,     \
      (uint32)0xa4f62c37UL, (uint32)0xfd4f79eaUL,     \
      (uint32)0xf62b436eUL, (uint32)0x520c3752UL,     \
      (uint32)0xf5bdba53UL, (uint32)0xc60c6559UL,     \
      (uint32)0xcbb5bea5UL, (uint32)0xeaa8add7UL,     \
      (uint32)0xb0b6d4b5UL, (uint32)0x6c305d9bUL,     \
      (uint32)0x9d07308aUL, (uint32)0x5ff819adUL,     \
      (uint32)0xc0f1252fUL, (uint32)0x34465893UL,     \
      (uint32)0x5685e56bUL, (uint32)0xb51661efUL,     \
      (uint32)0x65696b20UL, (uint32)0xe95cbf1eUL,     \
      (uint32)0x24177583UL, (uint32)0x89b1b4c0UL,     \
      (uint32)0xe8659416UL, (uint32)0xf2e8f18dUL,     \
      (uint32)0xc3a31fd6UL, (uint32)0xab5e1865UL      \
   }

/* Barrett value */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_4_BV			\
   {                                                  \
      (uint32)0x00000041UL,                           \
      (uint32)0x20b623ecUL, (uint32)0x0ad0a2d8UL,     \
      (uint32)0xd06cfd5cUL, (uint32)0xd336dceaUL,     \
      (uint32)0x677a0f31UL, (uint32)0x36b49038UL,     \
      (uint32)0xe9992394UL, (uint32)0xc1bcf14bUL,     \
      (uint32)0xf9c01cc3UL, (uint32)0xb9ac2e28UL,     \
      (uint32)0x495dd010UL, (uint32)0x31ff73dcUL,     \
      (uint32)0xa0c8870aUL, (uint32)0xb01924e4UL,     \
      (uint32)0xe3183b2bUL, (uint32)0x40b32a4bUL,     \
      (uint32)0xf99b99dbUL, (uint32)0x9db30e75UL,     \
      (uint32)0xfb21e911UL, (uint32)0x6a5d5d0cUL,     \
      (uint32)0xd616de71UL, (uint32)0xbacf1c8fUL,     \
      (uint32)0xde2ee7b9UL, (uint32)0xbb2fb9a0UL,     \
      (uint32)0xfc1627c2UL, (uint32)0x7c3fa0b3UL,     \
      (uint32)0x4b2c3b81UL, (uint32)0x866a32aeUL,     \
      (uint32)0x6d9e9fbaUL, (uint32)0xb8f18a84UL,     \
      (uint32)0x79e56ae5UL, (uint32)0xb8cd1cafUL,     \
      (uint32)0x3e9c37e9UL, (uint32)0x5c0daa15UL,     \
      (uint32)0x5592ace2UL, (uint32)0x968f8602UL,     \
      (uint32)0x9085a71dUL, (uint32)0x1634db34UL,     \
      (uint32)0xd1e0cb29UL, (uint32)0xacbeba14UL,     \
      (uint32)0x1574817eUL, (uint32)0x7903d88bUL,     \
      (uint32)0x7f41376eUL, (uint32)0x3ab44ed1UL,     \
      (uint32)0x193cea14UL, (uint32)0xb7115164UL,     \
      (uint32)0x0326e66bUL, (uint32)0x8d051e0bUL,     \
      (uint32)0xc01ef61aUL, (uint32)0x34817d87UL,     \
      (uint32)0x0f5104b7UL, (uint32)0xe8fd1ad7UL,     \
      (uint32)0x9acd3a3aUL, (uint32)0x9ee77297UL,     \
      (uint32)0x89a1d094UL, (uint32)0xfee4a368UL,     \
      (uint32)0x5f8cd7deUL, (uint32)0xe6d4a042UL,     \
      (uint32)0xc0964da8UL, (uint32)0x02530bd2UL,     \
      (uint32)0x85473218UL, (uint32)0x3ff45465UL,     \
      (uint32)0x84c6bd57UL, (uint32)0x7e6defcfUL,     \
      (uint32)0x00000001UL                            \
   }

/* Public exponent */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_4_PE			\
   {                                                  \
      (uint32)0x00000001UL, (uint32)0x00000003UL      \
   }

/*******************************************************************************
 *       Authentication keys for level 5  (2048 Bit)        *
 *******************************************************************************/
         /* FIX - DO NOT CHANGE: The asymmetrical level 5 authentication key. */

                                                                   /* modulus */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_5_M                                         \
   {                                                                           \
      (uint32)0x00000040UL,                           \
      (uint32)0xe92d6ec7UL, (uint32)0xa7e749f3UL,     \
      (uint32)0xb607c883UL, (uint32)0x21bf8dc2UL,     \
      (uint32)0x07c8d206UL, (uint32)0xd4c3adc4UL,     \
      (uint32)0xd28c9128UL, (uint32)0xabbcdcceUL,     \
      (uint32)0x3013a4d8UL, (uint32)0x64623482UL,     \
      (uint32)0x575176abUL, (uint32)0xc59d9fd4UL,     \
      (uint32)0xb5c89537UL, (uint32)0x816f217bUL,     \
      (uint32)0x32c4a6b8UL, (uint32)0x4db141dfUL,     \
      (uint32)0xb3b468dbUL, (uint32)0x21f61366UL,     \
      (uint32)0xecfc6d89UL, (uint32)0x1f6a1c10UL,     \
      (uint32)0x17e28344UL, (uint32)0xe049d70fUL,     \
      (uint32)0x5b8d6a6aUL, (uint32)0x7da47af0UL,     \
      (uint32)0x91d03e1dUL, (uint32)0xa4cc94acUL,     \
      (uint32)0xcfd3d85fUL, (uint32)0x32d65546UL,     \
      (uint32)0x285f4c90UL, (uint32)0xc1a92c0aUL,     \
      (uint32)0x68ceb548UL, (uint32)0xd6d1bf4fUL,     \
      (uint32)0x4233bb9fUL, (uint32)0xf1d1976dUL,     \
      (uint32)0xd416a154UL, (uint32)0xf884a915UL,     \
      (uint32)0x5788d300UL, (uint32)0x09b663e4UL,     \
      (uint32)0xf4a2ce9eUL, (uint32)0xae810309UL,     \
      (uint32)0x51c5c092UL, (uint32)0xc87ef75aUL,     \
      (uint32)0xb7174dbfUL, (uint32)0x6f84f39dUL,     \
      (uint32)0x5f45318cUL, (uint32)0x8af77ab5UL,     \
      (uint32)0xd47e167aUL, (uint32)0x329b8ed1UL,     \
      (uint32)0xdeb39184UL, (uint32)0x3fc4c833UL,     \
      (uint32)0x9b4af502UL, (uint32)0xe9668f5aUL,     \
      (uint32)0x8cbe18deUL, (uint32)0xeb7fd5cbUL,     \
      (uint32)0xd3fbbcfeUL, (uint32)0x8614f1dbUL,     \
      (uint32)0x45df0637UL, (uint32)0x5f6e3883UL,     \
      (uint32)0x55afb0fcUL, (uint32)0xbe5b9e46UL,     \
      (uint32)0xb96c6092UL, (uint32)0x814f6929UL,     \
      (uint32)0x6043d921UL, (uint32)0xa34bcf1dUL      \
   }

                                                             /* Barrett value */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_5_BV                                        \
   {                                                                           \
      (uint32)0x00000041UL,                           \
      (uint32)0x0dc45356UL, (uint32)0x51e3b8eeUL,     \
      (uint32)0x30c2c8e9UL, (uint32)0xb946b250UL,     \
      (uint32)0xa4ccf148UL, (uint32)0x693c80a4UL,     \
      (uint32)0x2d774790UL, (uint32)0xb3ec9c92UL,     \
      (uint32)0xb2152806UL, (uint32)0xb25c055fUL,     \
      (uint32)0x970e555bUL, (uint32)0x833cfd98UL,     \
      (uint32)0x6d0ea42fUL, (uint32)0xfefaf0c6UL,     \
      (uint32)0xd14d4b99UL, (uint32)0x3cb1e9abUL,     \
      (uint32)0xdf4f716dUL, (uint32)0xd2f33a7eUL,     \
      (uint32)0xe1e8b34dUL, (uint32)0x49a9e20cUL,     \
      (uint32)0x5cb603c0UL, (uint32)0x9c403150UL,     \
      (uint32)0x61de77e0UL, (uint32)0xa298f4a1UL,     \
      (uint32)0x95e95244UL, (uint32)0xdb02b9acUL,     \
      (uint32)0x0b618f14UL, (uint32)0x5680fc3fUL,     \
      (uint32)0xe502f1f9UL, (uint32)0xc785b6b6UL,     \
      (uint32)0xd063d06aUL, (uint32)0x5b8651fdUL,     \
      (uint32)0x0520de41UL, (uint32)0x4857086aUL,     \
      (uint32)0x1e9692abUL, (uint32)0x03959ac4UL,     \
      (uint32)0x3727adc4UL, (uint32)0x80aaa3e6UL,     \
      (uint32)0xe51438d7UL, (uint32)0x098156abUL,     \
      (uint32)0x274d5f21UL, (uint32)0x149ae918UL,     \
      (uint32)0x905f5497UL, (uint32)0x99f4ae88UL,     \
      (uint32)0xae9a5850UL, (uint32)0xd958b374UL,     \
      (uint32)0xc10675f8UL, (uint32)0xf663fa4dUL,     \
      (uint32)0x272b8a37UL, (uint32)0xf2fbd05fUL,     \
      (uint32)0xf11f10c9UL, (uint32)0x7934b219UL,     \
      (uint32)0x08cf115dUL, (uint32)0x9a0e4942UL,     \
      (uint32)0xc3445c11UL, (uint32)0xaf01f6c2UL,     \
      (uint32)0x571c573fUL, (uint32)0x882fd9feUL,     \
      (uint32)0x715f69e9UL, (uint32)0x7633cd64UL,     \
      (uint32)0x3305a47eUL, (uint32)0x5fe35d27UL,     \
      (uint32)0x789201b9UL, (uint32)0x91550d2cUL,     \
      (uint32)0x00000001UL                            \
   }

/* Public exponent */
#define CRYPTO_ASYM_AUTH_KEY_LEVEL_5_PE                                        \
   {                                                  \
      (uint32)0x00000001UL, (uint32)0x00000003UL      \
   }

/*******************************************************************************
 * 					SWE Signature key (2048 Bit)                               *
 *******************************************************************************/
/* Modulus */
#define CRYPTO_ASYM_SIG_KEY_M			\
   {                                                  \
      (uint32)0x00000040UL,                           \
      (uint32)0x63fe25efUL, (uint32)0x941ceb2aUL,     \
      (uint32)0xb9498f1fUL, (uint32)0x37fc2715UL,     \
      (uint32)0x9e09231cUL, (uint32)0xd681c0d4UL,     \
      (uint32)0x846fe232UL, (uint32)0xca4a9dfdUL,     \
      (uint32)0xb90bd03aUL, (uint32)0x9244f902UL,     \
      (uint32)0x88da8439UL, (uint32)0xc7a8754eUL,     \
      (uint32)0xf8b3aeb5UL, (uint32)0x91b60d8aUL,     \
      (uint32)0x467dccbbUL, (uint32)0x34fa725dUL,     \
      (uint32)0xd9bc7630UL, (uint32)0x971cc5afUL,     \
      (uint32)0xb7543dbeUL, (uint32)0x6e66f034UL,     \
      (uint32)0x8bec6ef4UL, (uint32)0x9936a588UL,     \
      (uint32)0x6e13ee7aUL, (uint32)0xa14c9857UL,     \
      (uint32)0x68c8624dUL, (uint32)0x4276c9cbUL,     \
      (uint32)0xbee532e5UL, (uint32)0xd1865c03UL,     \
      (uint32)0xf5ea1209UL, (uint32)0x4ad8eccaUL,     \
      (uint32)0x02118eceUL, (uint32)0x70c529a8UL,     \
      (uint32)0x6c062e50UL, (uint32)0x9c094d3dUL,     \
      (uint32)0x3cee0dd7UL, (uint32)0x4ff5801eUL,     \
      (uint32)0x343efbf1UL, (uint32)0x13fcf978UL,     \
      (uint32)0x9d20b430UL, (uint32)0x96855974UL,     \
      (uint32)0x79e6fe48UL, (uint32)0xb88327beUL,     \
      (uint32)0x06f55145UL, (uint32)0x72de1b4bUL,     \
      (uint32)0x2c112b58UL, (uint32)0xef00b961UL,     \
      (uint32)0x321b5a0cUL, (uint32)0x22083f49UL,     \
      (uint32)0xc78b6929UL, (uint32)0xf0c20308UL,     \
      (uint32)0x11a923f5UL, (uint32)0x1da23e69UL,     \
      (uint32)0x90a69926UL, (uint32)0x3797c84cUL,     \
      (uint32)0x7d2f8decUL, (uint32)0x262faad4UL,     \
      (uint32)0xc7bfac7aUL, (uint32)0xb10e812aUL,     \
      (uint32)0x0693bceeUL, (uint32)0x2793f81eUL,     \
      (uint32)0x13fb3050UL, (uint32)0xb57c0036UL,     \
      (uint32)0xf8bc7550UL, (uint32)0x98d707a8UL      \
   }

/* Barrett value */
#define CRYPTO_ASYM_SIG_KEY_BV			\
   {                                                  \
      (uint32)0x00000041UL,                           \
      (uint32)0x56fc5218UL, (uint32)0xf5c2ca4aUL,     \
      (uint32)0x85b957c6UL, (uint32)0x2c5b85e0UL,     \
      (uint32)0xbf06df0bUL, (uint32)0x8acd73b2UL,     \
      (uint32)0x6b7dd20eUL, (uint32)0xc798734dUL,     \
      (uint32)0x1b41558aUL, (uint32)0xbb354e66UL,     \
      (uint32)0x5e8eb084UL, (uint32)0xa9b1327bUL,     \
      (uint32)0x1e36094cUL, (uint32)0x10337764UL,     \
      (uint32)0x35e7bd71UL, (uint32)0x3c2193a9UL,     \
      (uint32)0xeb02e55cUL, (uint32)0x5fde6941UL,     \
      (uint32)0x5434c553UL, (uint32)0x64e96ffeUL,     \
      (uint32)0x96435e3eUL, (uint32)0x418c6cccUL,     \
      (uint32)0x93441daeUL, (uint32)0x64e95128UL,     \
      (uint32)0x11f5dfbaUL, (uint32)0x9cd5d8acUL,     \
      (uint32)0x8ccfa091UL, (uint32)0xea622d88UL,     \
      (uint32)0xfc394976UL, (uint32)0x1e7fc2dfUL,     \
      (uint32)0x1595c466UL, (uint32)0x5d2ba041UL,     \
      (uint32)0xdb49e5a1UL, (uint32)0x6b0afb8aUL,     \
      (uint32)0x94805d10UL, (uint32)0x2203cc8bUL,     \
      (uint32)0xeaa10fb2UL, (uint32)0x57c29ea6UL,     \
      (uint32)0x7f86a145UL, (uint32)0x375ee204UL,     \
      (uint32)0x7a5fc1dfUL, (uint32)0x9c8b8039UL,     \
      (uint32)0xe3d91a92UL, (uint32)0x4dc9d340UL,     \
      (uint32)0x8539adedUL, (uint32)0xe8e15e12UL,     \
      (uint32)0x44fefd74UL, (uint32)0xa0c80a48UL,     \
      (uint32)0x322b8fbbUL, (uint32)0x676c3d27UL,     \
      (uint32)0x303eb37dUL, (uint32)0x5688831cUL,     \
      (uint32)0xe8bb52a8UL, (uint32)0xfd26d071UL,     \
      (uint32)0x7c6e63f3UL, (uint32)0x4d994d98UL,     \
      (uint32)0x4590b45bUL, (uint32)0x4afd7837UL,     \
      (uint32)0x444a523bUL, (uint32)0xd0d80b32UL,     \
      (uint32)0xb665e4feUL, (uint32)0x68bd7dddUL,     \
      (uint32)0x3f315c93UL, (uint32)0xacc9d3a6UL,     \
      (uint32)0x00000001UL                            \
   }

/* Public exponent */
#define CRYPTO_ASYM_SIG_KEY_PE			\
   {                                                  \
      (uint32)0x00000001UL, (uint32)0x00000003UL      \
   }

/*******************************************************************************
 * NCD Signature key (1024 Bit)                                                *
 *******************************************************************************/
/* Modulus */
#define CRYPTO_ASYM_NCD_KEY_M			\
   {                                                  \
      (uint32)0x00000020UL,                           \
      (uint32)0x6abb7d67UL, (uint32)0x0dc726ffUL,     \
      (uint32)0xfb5307a5UL, (uint32)0xa0ee7ec0UL,     \
      (uint32)0xd937e5daUL, (uint32)0x067f8056UL,     \
      (uint32)0x87c8fbd2UL, (uint32)0x92d32708UL,     \
      (uint32)0x0912e48fUL, (uint32)0x64f6cbecUL,     \
      (uint32)0xf11caa77UL, (uint32)0xcf99f2e1UL,     \
      (uint32)0x528bd4abUL, (uint32)0x24da05dbUL,     \
      (uint32)0xecd15439UL, (uint32)0x225743a3UL,     \
      (uint32)0x9abeb0c6UL, (uint32)0xfac6fe5aUL,     \
      (uint32)0xe3cd3b75UL, (uint32)0x1365c2faUL,     \
      (uint32)0x743a38f6UL, (uint32)0xf54f4a43UL,     \
      (uint32)0xe4792891UL, (uint32)0xbf112ff9UL,     \
      (uint32)0xb46abbebUL, (uint32)0xa3755f20UL,     \
      (uint32)0x3ee69431UL, (uint32)0x7641551bUL,     \
      (uint32)0x97672ee7UL, (uint32)0xd990cdafUL,     \
      (uint32)0xce4eeb59UL, (uint32)0xc0f37fc6UL      \
   }

/* Barrett value */
#define CRYPTO_ASYM_NCD_KEY_BV			\
   {                                                  \
      (uint32)0x00000021UL,                           \
      (uint32)0xe1612238UL, (uint32)0xe6ac4bc3UL,     \
      (uint32)0xc286449bUL, (uint32)0xcc178b25UL,     \
      (uint32)0x86d45eafUL, (uint32)0xa3393cc2UL,     \
      (uint32)0x45a51e1eUL, (uint32)0x24dc2f6fUL,     \
      (uint32)0xce958ba5UL, (uint32)0x383b583eUL,     \
      (uint32)0x06135cb3UL, (uint32)0x7835d4d4UL,     \
      (uint32)0x9dc099a9UL, (uint32)0xa84510feUL,     \
      (uint32)0x48ef6239UL, (uint32)0xaddab023UL,     \
      (uint32)0xec3973c5UL, (uint32)0xf8ceb920UL,     \
      (uint32)0x440a81ebUL, (uint32)0x87449b90UL,     \
      (uint32)0x8bc2d92dUL, (uint32)0x9c7ab458UL,     \
      (uint32)0xcf41dbb7UL, (uint32)0x83f3345eUL,     \
      (uint32)0x9a36db2cUL, (uint32)0x4863370bUL,     \
      (uint32)0x3e6efee4UL, (uint32)0x43fadb21UL,     \
      (uint32)0x945f0f79UL, (uint32)0x9542fc1eUL,     \
      (uint32)0x8dbcc216UL, (uint32)0x53a69477UL,     \
      (uint32)0x00000001UL                            \
   }

/* Public exponent */
#define CRYPTO_ASYM_NCD_KEY_PE			\
   {                                                  \
      (uint32)0x00000001UL, (uint32)0x00000003UL      \
   }

/*******************************************************************************
 * Key Encryption key, Bootloader Update relevant (128 Bit)                     *
 *******************************************************************************/
              /* FIX - DO NOT CHANGE - The symmetrical kek key (zero values). */
#define CRYPTO_KEK_KEY                                                        \
   {                                                                           \
      (uint8)0x00U, (uint8)0x00U, (uint8)0x00U, (uint8)0x00U,                  \
      (uint8)0x00U, (uint8)0x00U, (uint8)0x00U, (uint8)0x00U,                  \
      (uint8)0x00U, (uint8)0x00U, (uint8)0x00U, (uint8)0x00U,                  \
      (uint8)0x00U, (uint8)0x00U, (uint8)0x00U, (uint8)0x00U                   \
   }

#endif /* CRYPTO_KEY_H                                                        */

/*** End of file **************************************************************/
