/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Appl_Crypto.c                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : types and data structures for accessing jumptable             **
**                                                                            **
**  REMARKS   : CRYPTO_JUMPTABLE_ADDR defines address for jump table, it      **
**              must point to the same address used by the bootloader         **
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
** miwe         Michael Weger              EB Automotive                      **
** anht         Andreas Hartmann           EB Automotive                      **
** ft           Florian Tausch             MB Technology                      **
** ep           Erik Pusch                 R. Bader GmbH                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.2: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.1.1: 14.04.2011,   ep: CR70989: Remaining ON/OFF switches should be converted to STD_ON/STD_OFF
 * V1.1.0: 14.09.2010,   ft: CR70750: added missing compiler abstraction
 * V1.0.1: 20.06.2008, anht: CR61399: Use TRUE/FALSE instead of 0/1 for
 *                                    assignments to cr_c_cancel
 *         11.08.2008, anht: CR61427: Removed redundant crypto function pointers,
 *                                    replaced them with macros.
 * V1.0.0: 13.11.2007, miwe: ported from SC6.7.2 file version 5.1.0
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

#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "Appl_Crypto.h"          /* Jumptable types                          */


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#if (SC_APPL_CRYPTO_ENABLE == STD_ON)

/* All of the variables "CR_*" are already defined in the bootloader. They    */
/* are again defined here and must be mapped to the same memory locations     */
/* where the bootloader versions are placed. This is needed so that the       */
/* application can access those variables directly.                           */

#if (defined CRYPTO_AUTH_ASYM) || \
    (defined CRYPTO_SIG_ASYM)  || \
    (defined CRYPTO_NCD_ASYM)
#define CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(CR_A_s2_t, APPLICATION_VAR) CR_A_s2;                               /* holds authentication data */
#define CRYPTO_STOP_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif

#define CRYPTO_START_SEC_COMM_RNG_VAR_NOINIT_32BIT
#include "MemMap.h"
VAR(CR_C_s2_t, APPLICATION_VAR) CR_C_s2;                                           /* RNG registers */
#define CRYPTO_STOP_SEC_COMM_RNG_VAR_NOINIT_32BIT
#include "MemMap.h"

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Removed because MD5 is no longer used
 */
 #if 0
/* Original code - START */
#define CRYPTO_START_SEC_MD5_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(CR_C_s3_t, APPLICATION_VAR) CR_C_s3;                                              /* MD5 buffer */
#define CRYPTO_STOP_SEC_MD5_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

#if (CR_DEF_RNG_ADV == STD_ON)
#define CRYPTO_START_SEC_RAND_SEED_VAR_NOINIT_32BIT
#include "MemMap.h"
VAR(CR_C_s4_t, APPLICATION_VAR) CR_C_s4;                                             /* Random Seed */
#define CRYPTO_STOP_SEC_RAND_SEED_VAR_NOINIT_32BIT
#include "MemMap.h"
#endif

#if (defined CRYPTO_AUTH_SYM) || \
    (defined CRYPTO_SIG_SYM)  || \
    (defined CRYPTO_NCD_SYM)
#define CRYPTO_START_SEC_SYMM_VAR_NOINIT_8BIT
#include "MemMap.h"
VAR(CR_S_s2_t, APPLICATION_VAR) CR_S_s2;                            /* challenge-response-container */
#define CRYPTO_STOP_SEC_SYMM_VAR_NOINIT_8BIT
#include "MemMap.h"
#endif

#if (CR_DEF_USE_CANCEL == STD_ON)
#define CRYPTO_START_SEC_COMM_VAR_NOINIT_8BIT
#include "MemMap.h"
VAR(uint8, APPLICATION_VAR) CR_C_cancel;
#define CRYPTO_STOP_SEC_COMM_VAR_NOINIT_8BIT
#include "MemMap.h"
#endif                                       /* (CR_DEF_USE_CANCEL == ON)     */

                                                             /* map jumptable */
CONSTP2CONST(Crypto_JumpTable_t, CR_CONST, CR_JMPTCFG_CONST) Crypto_Jumptable =
   ( CONSTP2CONST(Crypto_JumpTable_t, CR_CONST, CR_JMPTCFG_CONST) )CRYPTO_JUMPTABLE_ADDR ;


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  Crypto_Init                                               **
**                                                                            **
** DESCRIPTION   :  initialies the crypto module                              **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :  void                                                      **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  The function pointers are initialized so that the         **
**                  application can use the cryptographic routines of the     **
**                  bootloader per jumptable.                                 **
**                                                                            **
**                  The global variables used by the cryptographic routines   **
**                  are initialized so that they are not optimized away.      **
**                                                                            **
*******************************************************************************/
FUNC(void, APPLICATION_CODE) Crypto_Init( void )
{

   /* Initialize all global crypto variables. This is done simply because     */
   /* otherwise those variables would be optimized away.                      */

#if (defined CRYPTO_AUTH_ASYM) || \
    (defined CRYPTO_SIG_ASYM)  || \
    (defined CRYPTO_NCD_ASYM)
   CR_A_s2.hashres[0] = 0;
#endif

#if (defined CRYPTO_AUTH_SYM) || \
    (defined CRYPTO_SIG_SYM)  || \
    (defined CRYPTO_NCD_SYM)
   CR_S_s2.hashres[0] = 0;
#endif

   CR_C_s2.reg_a[0] = 0;
   /* ----------------------------------- NXTR PATCH START -------------------------------------
    * Added by: Archana Shivarudrappa
    * Date: 10/03/2016
    * Description: Removed because MD5 is no longer used
    */
    #if 0
   /* Original code - START */
   CR_C_s3.nMD5buflen = 0;
   /* Original code - END */
   #endif
   /* ----------------------------------- NXTR PATCH END -------------------------------------*/

#if (CR_DEF_RNG_ADV == STD_ON)
   CR_C_s4.CR_C_RandSeedA[0] = 0;
#endif

#if (CR_DEF_USE_CANCEL == STD_ON)
   CR_C_cancel = FALSE;
#endif

}

#endif /* (SC_APPL_CRYPTO_ENABLE == STD_ON) */

/*** End of file **************************************************************/
