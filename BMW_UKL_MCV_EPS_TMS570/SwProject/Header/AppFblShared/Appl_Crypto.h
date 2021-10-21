/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Appl_Crypto.h                                                 **
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
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.1: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.1.0: 14.09.2010,   ft: CR70750: added missing compiler abstraction
 * V1.0.1  11.08.2008, anht: CR61427: Removed redundant crypto function pointers,
 *                                    replaced them with macros.
 * V1.0.0: 13.11.2007, miwe: ported from SC6.7.2 file version V5.0.0
 */

#if !defined( APPL_CRYPTO_H )
#define APPL_CRYPTO_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>           /* AUTOSAR Standard Types                    */
#include "Crypto_Cfg.h"          /* a&s configuration                         */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */
#include "cr_a_data.h"                    /* asymmetric external declarations */
#include "cr_c_data.h"                        /* common external declarations */
#include "cr_s_data.h"                     /* symmetric external declarations */
#include "cr_c_cancel.h"               /* needed for function Crypto_Cancel() */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

        /* check if address of jumptable has been defined by the make process */
#ifndef CRYPTO_JUMPTABLE_ADDR
   #error "Appl_Crypto.h: CRYPTO_JUMPTABLE_ADDR must be defined"
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef CR_C_RC_t (*Crypto_CheckAuthUStg_t)
(
   CR_fpc_uint8   pChallenge,                       /* challenge for checking */
   CR_fpc_uint8   pUserID,                                         /* user id */
   CR_fpc_uint8  pnControllerID,                             /* controller id */
   uint16        nCycleCount,                   /* cycle count for intterupt. */
   uint32 const  nLevel,                              /* authentication level */
   CR_fpc_uint32 pResponse,                                       /* response */
   CR_fp_uint8   pState                                       /* state buffer */
);

typedef CR_C_RC_t (*Crypto_CheckSigSW_t)
(
   uint32 const    nNumBlocks,                            /* number of blocks */
   CR_fpcfpc_uint8 ppText,                            /* field of data blocks */
   CR_fpc_uint32   pnLength,                            /* field of len. elem */
   CR_fpc_uint32   pSignature,                           /* sig.field for chk */
   uint16          nCycleCount,                         /* cycle count f.intr */
   CR_fp_uint8     pState                                     /* state buffer */
);

typedef CR_C_RC_t (*Crypto_CheckSigNCD_t)
(
   uint32 const   nNumBlocks,                             /* number of blocks */
   CR_fpcfpc_uint8 ppText,                            /* field of data blocks */
   CR_fpc_uint32  pnLength,                             /* field of len. elem */
   CR_fpc_uint32  pSignature,                            /* sig.field for chk */
   uint16         nCycleCount,                          /* cycle count f.intr */
   CR_fp_uint8    pState                                      /* state buffer */
);

typedef void (*Crypto_MakeChallKey_t)
(
   uint32      nLength,                     /* length of expected random data */
   CR_fp_uint8 pChallKey               /* random data (used as challenge key) */
);

typedef CR_C_RC_t (*Crypto_CheckSigSwSymm_t)
(
   uint32 const    nNumBlocks,                      /* num.of blocks in array */
   CR_fpcfpc_uint8 ppText,                           /* SW-text blocks to chk */
   CR_fpc_uint32   pnLength,                          /* array of block sizes */
   CR_fpc_uint8    pMac                                 /* MAC to be verified */
);

typedef CR_C_RC_t (*Crypto_CheckSigNCDSymm_t)
(
   uint32 const    nNumBlocks,                      /* num.of blocks in array */
   CR_fpcfpc_uint8 ppText,                           /* SW-text blocks to chk */
   CR_fpc_uint32   pnLength,                          /* array of block sizes */
   CR_fpc_uint8    pMac                                 /* MAC to be verified */
);

typedef CR_C_RC_t (*Crypto_CheckAuthUStgSymm_t)
(
   CR_fpc_uint8 pChallenge,                                      /* challenge */
   CR_fpc_uint8 pUserID,                                           /* user-ID */
   CR_fpc_uint8 pControllerID,                               /* controller-ID */
   uint32       nLevel,                             /* Lvl for key selection  */
   CR_fpc_uint8 pResponse                           /* response 2be verified  */
);

typedef struct                                    /* list of function pointer */
{
  Crypto_MakeChallKey_t      Crypto_MakeChallKey;

#ifdef CRYPTO_AUTH_ASYM
  Crypto_CheckAuthUStg_t     Crypto_CheckAuthUStg;
#endif

#ifdef CRYPTO_SIG_ASYM
  Crypto_CheckSigSW_t        Crypto_CheckSigSW;
#endif

#ifdef CRYPTO_NCD_ASYM
  Crypto_CheckSigNCD_t       Crypto_CheckSigNCD;
#endif

#ifdef CRYPTO_AUTH_SYM
  Crypto_CheckAuthUStgSymm_t Crypto_CheckAuthUStgSymm;
#endif

#ifdef CRYPTO_SIG_SYM
  Crypto_CheckSigSwSymm_t    Crypto_CheckSigSwSymm;
#endif

#ifdef CRYPTO_NCD_SYM
  Crypto_CheckSigNCDSymm_t   Crypto_CheckSigNCDSymm;
#endif

} Crypto_JumpTable_t;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* jumptable struct                                                           */
extern CONSTP2CONST(Crypto_JumpTable_t, CR_CONST, CR_JMPTCFG_CONST)
                                                               Crypto_Jumptable;

/* cryptographic jumptable marcros */

#define Crypto_MakeChallKey        Crypto_Jumptable->Crypto_MakeChallKey

#ifdef CRYPTO_AUTH_ASYM
#define Crypto_CheckAuthUStg       Crypto_Jumptable->Crypto_CheckAuthUStg
#endif

#ifdef CRYPTO_SIG_ASYM
#define Crypto_CheckSigSW          Crypto_Jumptable->Crypto_CheckSigSW
#endif

#ifdef CRYPTO_NCD_ASYM
#define Crypto_CheckSigNCD         Crypto_Jumptable->Crypto_CheckSigNCD
#endif

#ifdef CRYPTO_AUTH_SYM
#define Crypto_CheckAuthUStgSymm   Crypto_Jumptable->Crypto_CheckAuthUStgSymm
#endif

#ifdef CRYPTO_SIG_SYM
#define Crypto_CheckSigSwSymm      Crypto_Jumptable->Crypto_CheckSigSwSymm
#endif

#ifdef CRYPTO_NCD_SYM
#define Crypto_CheckSigNCDSymm     Crypto_Jumptable->Crypto_CheckSigNCDSymm
#endif


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

extern FUNC(void, APPLICATION_CODE) Crypto_Init( void );

#endif                                                       /* APPL_CRYPTO_H */

/*** End of file **************************************************************/

