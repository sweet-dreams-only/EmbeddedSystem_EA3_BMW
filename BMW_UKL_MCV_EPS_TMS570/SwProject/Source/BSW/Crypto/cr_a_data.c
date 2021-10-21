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
 *         11.08.2006, mg : modified macro syntax, improved formatting
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
#include "cr_a_data.h"             /* container definition for asymm. keys    */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CRYPTO_START_SEC_PUBKEY_AUTH_S1_CONST_32BIT
#include "MemMap.h"

/* public keys LEVEL1, LEVEL2 */
const CR_DEF_FAR_MEMORY CR_A_s1_t CR_A_s1 =
{
                                 /* **************** LEVEL1 ***************** */
    CRYPTO_ASYM_AUTH_KEY_LEVEL_1_M,
    CRYPTO_ASYM_AUTH_KEY_LEVEL_1_PE,

#if (CR_DEF_USE_BARRETT == STD_ON)
    CRYPTO_ASYM_AUTH_KEY_LEVEL_1_BV,
#endif

                                 /* **************** LEVEL2 ***************** */
    CRYPTO_ASYM_AUTH_KEY_LEVEL_2_M,
    CRYPTO_ASYM_AUTH_KEY_LEVEL_2_PE,

#if (CR_DEF_USE_BARRETT == STD_ON)
    CRYPTO_ASYM_AUTH_KEY_LEVEL_2_BV,
#endif
};                               /* const CR_DEF_FAR_MEMORY CR_A_s1_t CR_A_s1 */


#define CRYPTO_STOP_SEC_PUBKEY_AUTH_S1_CONST_32BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_PUBKEY_AUTH_S3_CONST_32BIT
#include "MemMap.h"

                                 /* public keys Level 3, 4, 5                 */
const CR_DEF_FAR_MEMORY CR_A_s3_t CR_A_s3 =
{
                                 /* **************** LEVEL3 ***************** */
    CRYPTO_ASYM_AUTH_KEY_LEVEL_3_M,
    CRYPTO_ASYM_AUTH_KEY_LEVEL_3_PE,

#if (CR_DEF_USE_BARRETT == STD_ON)
    CRYPTO_ASYM_AUTH_KEY_LEVEL_3_BV,
#endif

                                 /* **************** LEVEL4 ***************** */
    CRYPTO_ASYM_AUTH_KEY_LEVEL_4_M,
    CRYPTO_ASYM_AUTH_KEY_LEVEL_4_PE,

#if (CR_DEF_USE_BARRETT == STD_ON)
    CRYPTO_ASYM_AUTH_KEY_LEVEL_4_BV,
#endif

                                 /* **************** LEVEL5 ***************** */
    CRYPTO_ASYM_AUTH_KEY_LEVEL_5_M,
    CRYPTO_ASYM_AUTH_KEY_LEVEL_5_PE,

#if (CR_DEF_USE_BARRETT == STD_ON)
    CRYPTO_ASYM_AUTH_KEY_LEVEL_5_BV,
#endif

};

#define CRYPTO_STOP_SEC_PUBKEY_AUTH_S3_CONST_32BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_PUBKEY_SIG_CONST_32BIT
#include "MemMap.h"
                                 /* SW signature keys                         */
const CR_DEF_FAR_MEMORY CR_A_s4_t CR_A_s4 =
{
    CRYPTO_ASYM_SIG_KEY_M,
    CRYPTO_ASYM_SIG_KEY_PE,

#if (CR_DEF_USE_BARRETT == STD_ON)
    CRYPTO_ASYM_SIG_KEY_BV,
#endif
};

#define CRYPTO_STOP_SEC_PUBKEY_SIG_CONST_32BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_PUBKEY_NCD_SIG_CONST_32BIT
#include "MemMap.h"
                                 /* coding data signature keys                */
const CR_DEF_FAR_MEMORY CR_A_s5_t CR_A_s5 =
{
    CRYPTO_ASYM_NCD_KEY_M,
    CRYPTO_ASYM_NCD_KEY_PE,

#if (CR_DEF_USE_BARRETT == STD_ON)
    CRYPTO_ASYM_NCD_KEY_BV,
#endif
};

#define CRYPTO_STOP_SEC_PUBKEY_NCD_SIG_CONST_32BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

CR_A_s2_t CR_A_s2;               /* holds authentication data                 */

#define CRYPTO_STOP_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

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

