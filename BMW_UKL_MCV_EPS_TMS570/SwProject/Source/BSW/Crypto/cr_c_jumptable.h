/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_c_jumptable.h                                              **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : common                                                        **
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
** mg           Matthias Galota            3SOFT                              **
** am           Alexander Much             3SOFT                              **
** sc           Juergen Scherg             3SOFT                              **
** fs           Frank Stamm                3SOFT                              **
** fs           Frank Stamm                3SOFT                              **
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
 *         24.05.2006, mg : fixed definition of jumptable type
 * V4.0.0: 03.04.2006, mg : moved configuration options to Crypto_Cfg.h, key
 *                          length configurable independently for authentication
 *                          and signature, cleaned up cr_c_hash.c,
 *                          removed compiler warnings
 * V3.4.0: 22.02.2006, mg : added coding functions
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

#if !defined( CRYPTO_JUMPTABLE_H )
#define CRYPTO_JUMPTABLE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef CR_C_RC_t (*Crypto_CheckAuthUStg_t)
(
   CR_fpc_uint8  challenge,
   CR_fpc_uint8  userID,
   CR_fpc_uint8  controllerID,
   uint16        cycleCount,
   uint32 const  level,
   CR_fpc_uint32 response,
   CR_fp_uint8   state
);

typedef CR_C_RC_t (*Crypto_CheckSigSW_t)
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint32   signature,
   uint16          cycleCount,
   CR_fp_uint8     state
);

typedef CR_C_RC_t (*Crypto_CheckSigNCD_t)
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint32   signature,
   uint16          cycleCount,
   CR_fp_uint8     state
);

typedef void (*Crypto_MakeChallKey_t)
(
   uint32      length,
   CR_fp_uint8 challKey
);

typedef CR_C_RC_t (*Crypto_CheckSigSwSymm_t)
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint8    mac
);

typedef CR_C_RC_t (*Crypto_CheckSigNCDSymm_t)
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint8    mac
);

typedef CR_C_RC_t (*Crypto_CheckAuthUStgSymm_t)
(
   CR_fpc_uint8 challenge,
   CR_fpc_uint8 userID,
   CR_fpc_uint8 controllerID,
   uint32       level,
   CR_fpc_uint8 response
);


struct Crypto_JumpTable_s                 /* list of mapped function pointers */
{
  Crypto_MakeChallKey_t      Crypto_MakeChallKey;
#ifdef CRYPTO_AUTH_ASYM
  Crypto_CheckAuthUStg_t     Crypto_CheckAuthUStg;
#endif
#ifdef CRYPTO_SIG_ASYM
  Crypto_CheckSigSW_t        Crypto_CheckSigSW;
  Crypto_CheckSigNCD_t       Crypto_CheckSigNCD;
#endif
#ifdef CRYPTO_AUTH_SYM
  Crypto_CheckAuthUStgSymm_t Crypto_CheckAuthUStgSymm;
#endif
#ifdef CRYPTO_SIG_SYM
  Crypto_CheckSigSwSymm_t    Crypto_CheckSigSwSymm;
  Crypto_CheckSigNCDSymm_t   Crypto_CheckSigNCDSymm;
#endif

};


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define CRYPTO_START_SEC_JUMPTABLE_CONST_UNSPECIFIED
#include "MemMap.h"

                                                    /* function pointer table */
extern const struct Crypto_JumpTable_s Crypto_JumpTable;

#define CRYPTO_STOP_SEC_JUMPTABLE_CONST_UNSPECIFIED
#include "MemMap.h"

#endif /* if !defined( CRYPTO_JUMPTABLE_H ) */
/*** End of file **************************************************************/
