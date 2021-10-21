/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_c_jumptable.c                                              **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : types and data structures for jumptable                       **
**                                                                            **
**  REMARKS   : Crypto_JumpTable is used by application and bootloader and    **
**              must therefore point to the same address, see ApplCrypto.h/.c **
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
** am           Alexander Much             3SOFT                              **
** fs           Frank Stamm                3SOFT                              **
** mg           Matthias Galota            3SOFT                              **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * Log:
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */
#include "cr_c_jumptable.h"        /* container definition for jump table     */
#include "cr_a_controller.h"       /* asymmetrical API functions              */
#include "cr_c_random.h"           /* random API functions                    */
#include "cr_s_auth.h"             /* symmetrical API functions               */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CRYPTO_START_SEC_JUMPTABLE_CONST_UNSPECIFIED
#include "MemMap.h"

                                   /* function pointer table                  */
const struct Crypto_JumpTable_s Crypto_JumpTable =
{
    Crypto_MakeChallKey,
#ifdef CRYPTO_AUTH_ASYM
    Crypto_CheckAuthUStg,
#endif
#ifdef CRYPTO_SIG_ASYM
    Crypto_CheckSigSW,
    Crypto_CheckSigNCD,
#endif
#ifdef CRYPTO_AUTH_SYM
    Crypto_CheckAuthUStgSymm,
#endif
#ifdef CRYPTO_SIG_SYM
    Crypto_CheckSigSwSymm,
    Crypto_CheckSigNCDSymm
#endif
};

#define CRYPTO_STOP_SEC_JUMPTABLE_CONST_UNSPECIFIED
#include "MemMap.h"
/*** End of file **************************************************************/

