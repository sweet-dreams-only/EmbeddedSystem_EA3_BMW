/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_a_data.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : types and data structures for asymmetrical routines           **
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
** jd           Jochen Decker              EB Automotive                      **
** mg           Matthias Galota            EB Automotive                      **
** am           Alexander Much             EB Automotive                      **
** sc           Juergen Scherg             EB Automotive                      **
** fs           Frank Stamm                EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V6.0.1: 27.01.2010, gema: CR70529: Crypto: Compiler switches shall have 
 *                                    defined values 
 * V6.0.0: 03.09.2008, mg : moved buffer size macros to *_data.h
 * V5.0.0: 21.09.2006, mg : code clean-ups
 *         11.08.2006, mg : improved formatting, changed macro syntax
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

#if !defined( CR_A_DATA_H )
#define CR_A_DATA_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */
#include "cr_a_rsa_defs.h"         /* rsa key and buffer sizes                */
#include "cr_c_data.h"             /* hash buffer sizes                       */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define CR_DEF_AA_MEXP_STATESIZE       8
#define CR_DEF_AA_MOD_STATESIZE        8
#define CR_DEF_AA_MEXP_STATESIZE_TOTAL (CR_DEF_AA_MEXP_STATESIZE + \
                                        CR_DEF_AA_MOD_STATESIZE)

/* ----- NXTR PATCH START -----
 * Added By: K. Smith (Nxtr)
 * Date Added: 27Sep16
 *
 * Reason: The hash method change from MD5 to SHA256. This has a hash length of 8 uint32
 * byte values, so the 4 needed to change to an 8.
 */
#if 0
/* ----- Original Code Start ----- */
#if !defined( CR_DEF_CHECK_AUTH_STATESIZE )
   #define CR_DEF_CHECK_AUTH_STATESIZE 4           /* the state size in words */
#else                           /* if !defined( CR_DEF_CHECK_AUTH_STATESIZE ) */
   #error CR_A_DATA_H: CR_DEF_CHECK_AUTH_STATESIZE already defined
#endif                          /* if !defined( CR_DEF_CHECK_AUTH_STATESIZE ) */
/* ----- Original Code End ----- */
#endif
/* ----- Patch Code Start ----- */
#if !defined( CR_DEF_CHECK_AUTH_STATESIZE )
   #define CR_DEF_CHECK_AUTH_STATESIZE 8           /* the state size in words */
#else                           /* if !defined( CR_DEF_CHECK_AUTH_STATESIZE ) */
   #error CR_A_DATA_H: CR_DEF_CHECK_AUTH_STATESIZE already defined
#endif                          /* if !defined( CR_DEF_CHECK_AUTH_STATESIZE ) */
/* ----- Patch Code End ----- */
/* ----- NXTR PATCH END ----- */

#if !defined( CR_C_CHECK_AUTH_STATESIZE_TOTAL )
   #define CR_C_CHECK_AUTH_STATESIZE_TOTAL \
      (CR_DEF_CHECK_AUTH_STATESIZE + CR_DEF_AA_MEXP_STATESIZE_TOTAL)
#else                       /* if !defined( CR_C_CHECK_AUTH_STATESIZE_TOTAL ) */
   #error CR_A_DATA_H: CR_C_CHECK_AUTH_STATESIZE_TOTAL already defined
#endif                      /* if !defined( CR_C_CHECK_AUTH_STATESIZE_TOTAL ) */

/* ----- NXTR PATCH START -----
 * Added By: K. Smith (Nxtr)
 * Date Added: 27Sep16
 *
 * Reason: The hash method change from MD5 to SHA256. This has a hash length of 8 uint32
 * byte values, so the 4 needed to change to an 8.
 */
#if 0
/* ----- Original Code Start ----- */
#if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE )
   #define CR_DEF_CHECK_AUTH_U_STG_STATESIZE 4
#else                     /* if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE ) */
   #error CR_A_DATA_H: CR_DEF_CHECK_AUTH_U_STG_STATESIZE already defined
#endif                    /* if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE ) */
/* ----- Original Code End ----- */
#endif
/* ----- Patch Code Start ----- */
#if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE )
   #define CR_DEF_CHECK_AUTH_U_STG_STATESIZE 8
#else                     /* if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE ) */
   #error CR_A_DATA_H: CR_DEF_CHECK_AUTH_U_STG_STATESIZE already defined
#endif                    /* if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE ) */
/* ----- Patch Code End ----- */
/* ----- NXTR PATCH END ----- */

#if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE_TOTAL )
   #define CR_DEF_CHECK_AUTH_U_STG_STATESIZE_TOTAL \
      (CR_DEF_CHECK_AUTH_U_STG_STATESIZE + CR_C_CHECK_AUTH_STATESIZE_TOTAL)
#else               /* if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE_TOTAL ) */
   #error CR_A_DATA_H: CR_DEF_CHECK_AUTH_U_STG_STATESIZE_TOTAL already defined
#endif              /* if !defined( CR_DEF_CHECK_AUTH_U_STG_STATESIZE_TOTAL ) */

                     /* settings for interuptable block of signature checking */
#if !defined( CR_DEF_CHECK_SIG_STATESIZE )
   #define CR_DEF_CHECK_SIG_STATESIZE 8
#else                            /* if !defined( CR_DEF_CHECK_SIG_STATESIZE ) */
   #error CR_A_DATA_H: CR_DEF_CHECK_SIG_STATESIZE already defined
#endif                           /* if !defined( CR_DEF_CHECK_SIG_STATESIZE ) */

#if !defined( CR_DEF_CHECK_SIG_STATESIZE_TOTAL )
   #define CR_DEF_CHECK_SIG_STATESIZE_TOTAL                        \
          (CR_DEF_CHECK_SIG_STATESIZE + CR_DEF_AA_MEXP_STATESIZE_TOTAL \
           + CR_DEF_HASH_STATESIZE_TOTAL)
#else                      /* if !defined( CR_DEF_CHECK_SIG_STATESIZE_TOTAL ) */
   #error CR_A_DATA_H: CR_DEF_CHECK_SIG_STATESIZE_TOTAL already defined
#endif                     /* if !defined( CR_DEF_CHECK_SIG_STATESIZE_TOTAL ) */

#if !defined( CR_A_CHECK_SIG_U_STG_STATESIZE_TOTAL )
   #define CR_A_CHECK_SIG_U_STG_STATESIZE_TOTAL CR_DEF_CHECK_SIG_STATESIZE_TOTAL
#else                  /* if !defined( CR_A_CHECK_SIG_U_STG_STATESIZE_TOTAL ) */
   #error CR_A_DATA_H: CR_A_CHECK_SIG_U_STG_STATESIZE_TOTAL already defined
#endif                 /* if !defined( CR_A_CHECK_SIG_U_STG_STATESIZE_TOTAL ) */



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

                                    /* type for LEVEL1 and LEVEL2 public keys */
typedef struct
{                                              /***** LEVEL1 public key ***** */
   uint32 AUTH_U_STG_L1_m[CR_DEF_AUTH_KEY_LENGTH];         /* modulus         */
   uint32 AUTH_U_STG_L1_pe[2];                             /* public exponent */
#if (CR_DEF_USE_BARRETT == STD_ON)
   uint32 AUTH_U_STG_L1_bv[CR_DEF_AUTH_KEY_LENGTH + 1];    /* barrett value   */
#endif
                                               /***** LEVEL2 public key ***** */
   uint32 AUTH_U_STG_L2_m[CR_DEF_AUTH_KEY_LENGTH];         /* modulus         */
   uint32 AUTH_U_STG_L2_pe[2];                             /* public exponent */
#if (CR_DEF_USE_BARRETT == STD_ON)
   uint32 AUTH_U_STG_L2_bv[CR_DEF_AUTH_KEY_LENGTH + 1];    /* barrett value   */
#endif
} CR_A_s1_t;

               /* authentication and signature check temporary data container */
typedef struct
{
   /* ----- NXTR PATCH START -----
    * Added By: K. Smith (Nxtr)
    * Date Added: 27Sep16
    *
    * Reason: This library was only design with 1024 bit in mind. As a result,
    * the hash result needed to increase from 16 to 32 to support 2048 bit key.
    */
   #if 0
   /* ----- Original Code Start ----- */
	uint8  CRYPTO_SW_FP[16];                    /* software fingerprint        */
	uint8  chall_u_stg[16];                     /* control device challenge    */
	uint32 resp_e[CR_DEF_MAX_KEY_LENGTH + 1];   /* decrypted response for auth */
   uint8  hashres[16];                         /* hash result                 */
   /* ----- Original Code End ----- */
   #endif
   /* ----- Patch Code Start ----- */
	uint8  CRYPTO_SW_FP[16];                    /* software fingerprint        */
	uint8  chall_u_stg[32];                     /* control device challenge    */
	uint32 resp_e[CR_DEF_MAX_KEY_LENGTH + 1];   /* decrypted response for auth */
   uint8  hashres[32];                         /* hash result                 */
   /* ----- Patch Code End ----- */
   /* ----- NXTR PATCH END ----- */
   uint32 sig_e[CR_DEF_MAX_KEY_LENGTH + 1];    /* decrypted signature         */
   uint32 tmp[(2 * CR_DEF_MAX_KEY_LENGTH) - 1];/* temp mem for CR_A_NewAaMExp */
} CR_A_s2_t;

                            /* type for LEVEL3, LEVEL4 and LEVEL5 public keys */
typedef struct
{                                             /* **** LEVEL3 public key ***** */
   uint32 AUTH_U_STG_L3_m[CR_DEF_AUTH_KEY_LENGTH];         /* modulus         */
   uint32 AUTH_U_STG_L3_pe[2];                             /* public exponent */
#if (CR_DEF_USE_BARRETT == STD_ON)
   uint32 AUTH_U_STG_L3_bv[CR_DEF_AUTH_KEY_LENGTH + 1];    /* barrett value   */
#endif

                                              /* **** LEVEL4 public key ***** */
   uint32 AUTH_U_STG_L4_m[CR_DEF_AUTH_KEY_LENGTH];         /* modulus         */
   uint32 AUTH_U_STG_L4_pe[2];                             /* public exponent */
#if (CR_DEF_USE_BARRETT == STD_ON)
   uint32 AUTH_U_STG_L4_bv[CR_DEF_AUTH_KEY_LENGTH + 1];    /* barrett value   */
#endif

                                              /* **** LEVEL5 public key ***** */
   uint32 AUTH_U_STG_L5_m[CR_DEF_AUTH_KEY_LENGTH];         /* modulus         */
   uint32 AUTH_U_STG_L5_pe[2];                             /* public exponent */
#if (CR_DEF_USE_BARRETT == STD_ON)
   uint32 AUTH_U_STG_L5_bv[CR_DEF_AUTH_KEY_LENGTH + 1];    /* barrett value   */
#endif
} CR_A_s3_t;

                                    /* type for software signature public key */
typedef struct
{
   uint32 SIG_SW_m[CR_DEF_SIG_KEY_LENGTH];                 /* modulus         */
   uint32 SIG_SW_pe[2];                                    /* public exponent */
#if (CR_DEF_USE_BARRETT == STD_ON)
   uint32 SIG_SW_bv[CR_DEF_SIG_KEY_LENGTH + 1];            /* barrett value   */
#endif
} CR_A_s4_t;

                                 /* type for coding data signature public key */
typedef struct
{
   uint32 SIG_COD_m[CR_DEF_NCD_SIG_KEY_LENGTH];            /* modulus         */
   uint32 SIG_COD_pe[2];                                   /* public exponent */
#if (CR_DEF_USE_BARRETT == STD_ON)
   uint32 SIG_COD_bv[CR_DEF_NCD_SIG_KEY_LENGTH + 1];       /* barrett value   */
#endif
} CR_A_s5_t;



/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CRYPTO_START_SEC_PUBKEY_AUTH_S1_CONST_32BIT
#include "MemMap.h"
                               /* holds LEVEL1 and LEVEL2 public keys         */
extern const CR_DEF_FAR_MEMORY CR_A_s1_t CR_A_s1;

#define CRYPTO_STOP_SEC_PUBKEY_AUTH_S1_CONST_32BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* holds authentication data */
extern CR_A_s2_t CR_A_s2;

#define CRYPTO_STOP_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


#define CRYPTO_START_SEC_PUBKEY_AUTH_S3_CONST_32BIT
#include "MemMap.h"
                               /* holds LEVEL3, LEVEL4 and LEVEL5 public keys */
extern const CR_DEF_FAR_MEMORY CR_A_s3_t CR_A_s3;

#define CRYPTO_STOP_SEC_PUBKEY_AUTH_S3_CONST_32BIT
#include "MemMap.h"


#define CRYPTO_START_SEC_PUBKEY_SIG_CONST_32BIT
#include "MemMap.h"
                               /* holds SW signature public key               */
extern const CR_DEF_FAR_MEMORY CR_A_s4_t CR_A_s4;

#define CRYPTO_STOP_SEC_PUBKEY_SIG_CONST_32BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_PUBKEY_NCD_SIG_CONST_32BIT
#include "MemMap.h"
                               /* holds coding data signature public key      */
extern const CR_DEF_FAR_MEMORY CR_A_s5_t CR_A_s5;

#define CRYPTO_STOP_SEC_PUBKEY_NCD_SIG_CONST_32BIT
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* if !defined( CR_A_DATA_H ) */
/*** End of file **************************************************************/
