/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_a_data.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
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
 *         11.08.2006, mg : added cancelation functionality, modified macro
 *                          syntax, improved formatting, corrected memory
 *                          mapping
 * V4.1.0: 22.06.2006, mg : no changes
 *         24.05.2006, mg : removed initialization of PRNG state variable
 *                          CR_C_s2
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
#include "cr_c_data.h"             /* common global data declarations         */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed since MD5 hash algorithm is no longer used. Replaced with SHA256.
 */
#if 0
/* Original code - START */
#define CRYPTO_START_SEC_COMM_HASH_CONST_UNSPECIFIED
#include "MemMap.h"

const CR_DEF_FAR_MEMORY CR_C_s1_t CR_C_s1 =
{
   {                                             /* round start values        */
      (uint8)0x00U, (uint8)0x01U, (uint8)0x05U, (uint8)0x00U
   },
   {                                             /* round increment values    */
      (uint8)0x01U, (uint8)0x05U, (uint8)0x03U, (uint8)0x07U
   },
   {                                             /* shift values              */
      (uint8)0x07U, (uint8)0x0cU, (uint8)0x11U, (uint8)0x16U,
      (uint8)0x05U, (uint8)0x09U, (uint8)0x0eU, (uint8)0x14U,
      (uint8)0x04U, (uint8)0x0bU, (uint8)0x10U, (uint8)0x17U,
      (uint8)0x06U, (uint8)0x0aU, (uint8)0x0fU, (uint8)0x15U
   },
   {                                             /* MD5 constants T           */
      (uint32)0xd76aa478UL, (uint32)0xe8c7b756UL,
      (uint32)0x242070dbUL, (uint32)0xc1bdceeeUL,
      (uint32)0xf57c0fafUL, (uint32)0x4787c62aUL,
      (uint32)0xa8304613UL, (uint32)0xfd469501UL,
      (uint32)0x698098d8UL, (uint32)0x8b44f7afUL,
      (uint32)0xffff5bb1UL, (uint32)0x895cd7beUL,
      (uint32)0x6b901122UL, (uint32)0xfd987193UL,
      (uint32)0xa679438eUL, (uint32)0x49b40821UL,
      (uint32)0xf61e2562UL, (uint32)0xc040b340UL,
      (uint32)0x265e5a51UL, (uint32)0xe9b6c7aaUL,
      (uint32)0xd62f105dUL, (uint32)0x02441453UL,
      (uint32)0xd8a1e681UL, (uint32)0xe7d3fbc8UL,
      (uint32)0x21e1cde6UL, (uint32)0xc33707d6UL,
      (uint32)0xf4d50d87UL, (uint32)0x455a14edUL,
      (uint32)0xa9e3e905UL, (uint32)0xfcefa3f8UL,
      (uint32)0x676f02d9UL, (uint32)0x8d2a4c8aUL,
      (uint32)0xfffa3942UL, (uint32)0x8771f681UL,
      (uint32)0x6d9d6122UL, (uint32)0xfde5380cUL,
      (uint32)0xa4beea44UL, (uint32)0x4bdecfa9UL,
      (uint32)0xf6bb4b60UL, (uint32)0xbebfbc70UL,
      (uint32)0x289b7ec6UL, (uint32)0xeaa127faUL,
      (uint32)0xd4ef3085UL, (uint32)0x04881d05UL,
      (uint32)0xd9d4d039UL, (uint32)0xe6db99e5UL,
      (uint32)0x1fa27cf8UL, (uint32)0xc4ac5665UL,
      (uint32)0xf4292244UL, (uint32)0x432aff97UL,
      (uint32)0xab9423a7UL, (uint32)0xfc93a039UL,
      (uint32)0x655b59c3UL, (uint32)0x8f0ccc92UL,
      (uint32)0xffeff47dUL, (uint32)0x85845dd1UL,
      (uint32)0x6fa87e4fUL, (uint32)0xfe2ce6e0UL,
      (uint32)0xa3014314UL, (uint32)0x4e0811a1UL,
      (uint32)0xf7537e82UL, (uint32)0xbd3af235UL,
      (uint32)0x2ad7d2bbUL, (uint32)0xeb86d391UL
   }
};

#define CRYPTO_STOP_SEC_COMM_HASH_CONST_UNSPECIFIED
#include "MemMap.h"
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/


#define CRYPTO_START_SEC_COMM_RNG_VAR_NOINIT_32BIT
#include "MemMap.h"

CR_C_s2_t CR_C_s2;

#define CRYPTO_STOP_SEC_COMM_RNG_VAR_NOINIT_32BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_KEK_KEY_CONST_8BIT
#include "MemMap.h"

#if defined( BOOTLOADER )
CR_fc_uint8 KEK_KEY[16] = CRYPTO_KEK_KEY;        /* boot loader key           */

#endif                                           /* if defined( BOOTLOADER )  */

#define CRYPTO_STOP_SEC_KEK_KEY_CONST_8BIT
#include "MemMap.h"

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed since MD5 hash algorithm is no longer used. Replaced with SHA256.
 */
#if 0
/* Original code - START */
#define CRYPTO_START_SEC_MD5_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

CR_C_s3_t CR_C_s3;

#define CRYPTO_STOP_SEC_MD5_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/



#if (CR_DEF_RNG_ADV == STD_ON)
#define CRYPTO_START_SEC_RAND_SEED_VAR_NOINIT_32BIT
#include "MemMap.h"

CR_C_s4_t CR_C_s4;

#define CRYPTO_STOP_SEC_RAND_SEED_VAR_NOINIT_32BIT
#include "MemMap.h"
#endif                                           /* if (CR_DEF_RNG_ADV == STD_ON) */


#if (CR_DEF_USE_CANCEL == STD_ON)

#define CRYPTO_START_SEC_COMM_VAR_NOINIT_8BIT
#include "MemMap.h"

uint8 CR_C_cancel;

#define CRYPTO_STOP_SEC_COMM_VAR_NOINIT_8BIT
#include "MemMap.h"

#endif                                           /* (CR_DEF_USE_CANCEL == STD_ON) */


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*** End of file **************************************************************/
