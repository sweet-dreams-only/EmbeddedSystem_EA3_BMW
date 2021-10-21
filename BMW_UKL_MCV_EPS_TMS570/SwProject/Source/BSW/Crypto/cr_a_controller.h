/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_a_controller.h                                             **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : asymmetrical authentication and signature check               **
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
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V6.0.0: 03.09.2008, mg : moved buffer size macros to *_data.h
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

#if !defined( CR_A_CONTROLLER_H )
#define CR_A_CONTROLLER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"                                  /* a&s configuration */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */
#include "cr_a_rsa_defs.h"                        /* rsa key and buffer sizes */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define CRYPTO_START_SEC_CODE
#include "MemMap.h"
extern CR_C_RC_t Crypto_CheckAuthUStg
(
   CR_fpc_uint8  challenge,                        /* challenge for checking */
   CR_fpc_uint8  userID,                                          /* user id */
   CR_fpc_uint8  controllerID,                             /* controller id */
   uint16        cycleCount,                   /* cycle count for intterupt. */
   uint32 const  level,                              /* authentication level */
   CR_fpc_uint32 response,                                       /* response */
   CR_fp_uint8   state                                       /* state buffer */
);

extern CR_C_RC_t Crypto_CheckSigSW
(
   uint32 const    numBlocks,                            /* number of blocks */
   CR_fpcfpc_uint8 textPtr,                            /* field of data blocks */
   CR_fpc_uint32   length,                            /* field of len. elem */
   CR_fpc_uint32   signature,                           /* sig.field for chk */
   uint16          cycleCount,                         /* cycle count f.intr */
   CR_fp_uint8     state                                     /* state buffer */
);

extern CR_C_RC_t Crypto_CheckSigNCD
(
   uint32 const    numBlocks,                            /* number of blocks */
   CR_fpcfpc_uint8 textPtr,                            /* field of data blocks */
   CR_fpc_uint32   length,                            /* field of len. elem */
   CR_fpc_uint32   signature,                           /* sig.field for chk */
   uint16          cycleCount,                         /* cycle count f.intr */
   CR_fp_uint8     state                                     /* state buffer */
);
#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"
#endif /* if !defined( CR_A_CONTROLLER_H ) */
/*** End of file **************************************************************/
