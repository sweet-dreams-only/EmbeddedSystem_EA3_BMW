/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_c_hash.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : hash routines                                                 **
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
 *         11.08.2006, mg : changed macro syntax, added cancelation
 *                          functionality
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

#if !defined( CR_C_HASH_H )
#define CR_C_HASH_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */

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

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Removed because MD5 is not used
 */
 #if 0
/* Original code - START */
extern CR_C_RC_t CR_C_md5end
(
   CR_fp_uint8  result
);

extern void CR_C_md5init
(
   void
);

extern CR_C_RC_t CR_C_md5hash
(
   CR_fp_uint16 cycleCountPtr,
   CR_fpc_uint8 text,
   uint32 const length,
   CR_fp_uint8  state
);
/* Original code - END */
#endif

extern CR_C_RC_t CR_C_hash
(
   CR_fp_uint16    cycleCountPtr,
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fp_uint8     hashRes,
   CR_fp_uint8     state
);
#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

#endif /* if !defined( CR_C_HASH_H ) */
/*** End of file **************************************************************/
