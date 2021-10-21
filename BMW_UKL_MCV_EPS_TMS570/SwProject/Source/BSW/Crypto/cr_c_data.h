/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_c_data.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : types and data structures for symmetric/asymmetric            **
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
 *         11.08.2006, mg : improved formatting, changed macro syntax, added
 *                          cancelation functionality
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

#if !defined( CR_C_DATA_H )
#define CR_C_DATA_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

                         /* settings for interruptable block of hash routines */
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed since MD5 hash algorithm is not used.
 */
 #if 0
/* Original code - START */
#if !defined( CR_DEF_MD5HASH_STATESIZE )
                         /* size in bytes of the state buffer of MD5          */
   #define CR_DEF_MD5HASH_STATESIZE 12
#else                    /* if !defined( CR_DEF_MD5HASH_STATESIZE )           */
   #error CR_C_DATA_H_0001: CRD_DEF_MD5HASH_STATESIZE already defined
#endif                   /* if !defined( CR_DEF_MD5HASH_STATESIZE )           */

#if !defined( CR_DEF_MD5HASH_STATESIZE_TOTAL )
                         /* total size in bytes of the MD5 state buffer       */
   #define CR_DEF_MD5HASH_STATESIZE_TOTAL CR_DEF_MD5HASH_STATESIZE
#else                    /* if !defined( CR_DEF_MD5HASH_STATESIZE_TOTAL )     */
   #error CR_C_DATA_H_0002: CR_DEF_MD5HASH_STATESIZE_TOTAL already defined
#endif                   /* if !defined( CR_DEF_MD5HASH_STATESIZE_TOTAL )     */

#if !defined( CR_DEF_HASH_STATESIZE_TOTAL )
   #define CR_DEF_HASH_STATESIZE_TOTAL \
   (CR_DEF_HASH_STATESIZE + CR_DEF_MD5HASH_STATESIZE_TOTAL)
#else                    /* if !defined( CR_DEF_HASH_STATESIZE_TOTAL )        */
   #error CR_C_DATA_H_0004: CR_DEF_HASH_STATESIZE_TOTAL already defined
#endif                   /* if !defined( CR_DEF_HASH_STATESIZE_TOTAL )        */
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

#if !defined( CR_DEF_HASH_STATESIZE )
   #define CR_DEF_HASH_STATESIZE 6                   /* size of the MD5 state */
#else                    /* if !defined( CR_DEF_HASH_STATESIZE )              */
   #error CR_C_DATA_H_0003: CR_DEF_HASH_STATESIZE already defined
#endif                   /* if !defined( CR_DEF_HASH_STATESIZE )              */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed since MD5 hash algorithm is not used
 */
 #if 0
/* Original code - START */
typedef struct global_com1                         /* type for MD5 definition */
{
   uint8  rundenstart[4];                          /* round start             */
   uint8  rundenink[4];                            /* round increment         */
   uint8  shifts[16];                              /* shift values            */
   uint32 T[64];                                   /* MD5 T constants         */
} CR_C_s1_t;

typedef struct global_md5
{
   uint8  md5buf[64U];                             /* md5 buffer              */
   uint32 nMD5buflen;                              /* size of buffer          */
   uint32 nMD5A;                                   /* MD5 reg A on PC         */
   uint32 nMD5B;                                   /* MD5 reg B on PC         */
   uint32 nMD5C;                                   /* MD5 reg C on PC         */
   uint32 nMD5D;                                   /* MD5 reg D on PC         */
   uint32 nMD5totallen;                            /* complete length         */
} CR_C_s3_t;
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

typedef struct global_com2                         /* type for RNG registers  */
{
   uint32 reg_a[2];                                /* reg a                   */
   uint32 reg_b[2];                                /* reg b                   */
} CR_C_s2_t;

#if (CR_DEF_RNG_ADV == STD_ON)
typedef struct global_random
{
   uint32 CR_C_RandSeedA[2];                 /* global seed for global LFSR A */
  uint32 CR_C_RandSeedB[2];                  /* global seed for global LFSR B */
} CR_C_s4_t;
#endif /* if (CR_DEF_RNG_ADV == STD_ON) */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Updated the BL SGBMID according to pdx template PT01_template.003_000_191.pdx
 *              with 2048-bit key and SHA-256 hash algorithm
 */
 #if 0
/* Original code - START */
#define CRYPTO_START_SEC_COMM_HASH_CONST_UNSPECIFIED
#include "MemMap.h"

extern const CR_DEF_FAR_MEMORY CR_C_s1_t CR_C_s1;          /* MD5 definitions */

#define CRYPTO_STOP_SEC_COMM_HASH_CONST_UNSPECIFIED
#include "MemMap.h"

#define CRYPTO_START_SEC_MD5_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

extern CR_C_s3_t CR_C_s3;                    /* MD5 buffer                    */

#define CRYPTO_STOP_SEC_MD5_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

#define CRYPTO_START_SEC_COMM_RNG_VAR_NOINIT_32BIT
#include "MemMap.h"

extern CR_C_s2_t CR_C_s2;                    /* RNG registers                 */

#define CRYPTO_STOP_SEC_COMM_RNG_VAR_NOINIT_32BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_KEK_KEY_CONST_8BIT
#include "MemMap.h"

extern CR_fc_uint8 KEK_KEY[16];              /* uC-internal key for SW-update */

#define CRYPTO_STOP_SEC_KEK_KEY_CONST_8BIT
#include "MemMap.h"

#if (CR_DEF_RNG_ADV == STD_ON)
#define CRYPTO_START_SEC_RAND_SEED_VAR_NOINIT_32BIT
#include "MemMap.h"

extern CR_C_s4_t CR_C_s4;                    /* Rand Seed                     */

#define CRYPTO_STOP_SEC_RAND_SEED_VAR_NOINIT_32BIT
#include "MemMap.h"
#endif                                       /* if (CR_DEF_RNG_ADV == STD_ON)     */



#if (CR_DEF_USE_CANCEL == STD_ON)

#define CRYPTO_START_SEC_COMM_VAR_NOINIT_8BIT
#include "MemMap.h"

extern uint8 CR_C_cancel;

#define CRYPTO_STOP_SEC_COMM_VAR_NOINIT_8BIT
#include "MemMap.h"

#endif                                       /* (CR_DEF_USE_CANCEL == STD_ON)     */


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* if !defined( CR_C_DATA_H ) */
/*** End of file **************************************************************/
