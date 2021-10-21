/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_s_data.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : types and data structures for symmetrical routines            **
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

#if !defined( CR_S_DATA_H )
#define CR_S_DATA_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"                                  /* a&s configuration */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef struct         /* symmetrical authentication keys level 1 and 2       */
{
   uint8 AUTH_U_STG_L1_symm[16];                 /* symmetric key for level 1 */
   uint8 AUTH_U_STG_L2_symm[16];                 /* symmetric key for level 2 */
} CR_S_s1_t;

typedef struct        /* symmetrical authentication and signature temp buffer */
{
   uint8 chall_u_stg[16];                        /* controller id challenge   */
   uint8 resp_ex[16];                            /* expected value            */
   uint8 hashres[16];                            /* hash result               */
} CR_S_s2_t;

typedef struct           /* symmetrical authentication keys level 3, 4, and 5 */
{
   uint8 AUTH_U_STG_L3_symm[16];                 /* symmetric key for level 3 */
   uint8 AUTH_U_STG_L4_symm[16];                 /* symmetric key for level 4 */
   uint8 AUTH_U_STG_L5_symm[16];                 /* symmetric key for level 5 */
} CR_S_s3_t;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

                               /* store symmetric keys in CR_DEF_SYMM_KEY_SEG */

#define CRYPTO_START_SEC_SYMM_KEY_CONST_8BIT
#include "MemMap.h"

extern const CR_DEF_FAR_MEMORY CR_S_s1_t CR_S_s1;       /* keys level 1, 2    */
extern const CR_DEF_FAR_MEMORY CR_S_s3_t CR_S_s3;       /* keys level 3, 4, 5 */

#define CRYPTO_STOP_SEC_SYMM_KEY_CONST_8BIT
#include "MemMap.h"


#define CRYPTO_START_SEC_SYMM_VAR_NOINIT_8BIT
#include "MemMap.h"

extern CR_S_s2_t CR_S_s2;                  /* challenge response field        */

#define CRYPTO_STOP_SEC_SYMM_VAR_NOINIT_8BIT
#include "MemMap.h"


#define CRYPTO_START_SEC_SYMM_SIG_CONST_8BIT
#include "MemMap.h"

extern CR_fc_uint8 SIG_SW_symm[16];        /* SW signature symmetrical key    */

#define CRYPTO_STOP_SEC_SYMM_SIG_CONST_8BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_SYMM_COD_SIG_CONST_8BIT
#include "MemMap.h"

extern CR_fc_uint8 SIG_COD_symm[16];      /* coding signature symmetrical key */

#define CRYPTO_STOP_SEC_SYMM_COD_SIG_CONST_8BIT
#include "MemMap.h"

#define CRYPTO_START_SEC_SYMM_KEY_CONST_8BIT
#include "MemMap.h"

extern CR_fc_uint8 CR_S_AuthStgSamSymm[16];

#define CRYPTO_STOP_SEC_SYMM_KEY_CONST_8BIT
#include "MemMap.h"
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* if !defined( CR_S_DATA_H ) */
/*** End of file **************************************************************/
