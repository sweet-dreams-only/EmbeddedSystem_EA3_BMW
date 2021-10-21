/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Hash.h                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Declarations of the hash services.                            **
**                                                                            **
**  REMARKS   : Implementation of a hash algorithm as a high-level service    **
**              using the low-level cryptographic primitive of the Swt      **
**              in Swt_MD5.h.                                               **
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
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.9.0    : 28.11.2006, mg   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

#if (!defined SWT_HASH_H)              /* preprocessor exclusion definition */
#define SWT_HASH_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_MD5.h"                        /* declarations of MD5 services */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

                               /* list of guards to prevent double definition */
#if (defined SWT_HASH_LEN_BYTES)
   #error SWT_HASH_LEN_BYTES already defined
#endif                                   /* if (defined SWT_HASH_LEN_BYTES) */

#if (defined SWT_HASH_DIGESTINFO)
   #error SWT_HASH_DIGESTINFO already defined
#endif                                  /* if (defined SWT_HASH_DIGESTINFO) */

#if (defined SWT_HASH_DIGESTINFO_LEN_BYTES)
   #error SWT_HASH_DIGESTINFO_LEN_BYTES already defined
#endif                        /* if (defined SWT_HASH_DIGESTINFO_LEN_BYTES) */

                                     /* The length of the hash value in bytes */
#define SWT_HASH_LEN_BYTES SWT_MD5_LEN_BYTES

/* The DER-encoded digestInfo of the MD5 hash algorithm as described in       */
/* chapter 9.2 of the standard PKCS #1 v2.1. This is used in some encoded     */
/* signatures, as, e.g., in the signature of an X.509 certificate.            */
#define SWT_HASH_DIGESTINFO SWT_MD5_DIGESTINFO

                         /* The length of the DER-encoded digestInfo in bytes */
#define SWT_HASH_DIGESTINFO_LEN_BYTES SWT_MD5_DIGESTINFO_LEN_BYTES

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
                                                 /* state of the hash context */
typedef enum
{
   SWT_HASH_STATE_UNKNOWN = 0,                             /* unknown state */
   SWT_HASH_STATE_UNINITIALIZED,                /* context is uninitialized */
   SWT_HASH_STATE_INITIALIZED               /* context has been initialized */
}
Swt_HashContextStateType;
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

                                                    /* hash context structure */
typedef struct
{
   Swt_MD5ContextType MD5Ctx;     /* Context of underlying MD5 hashfunction */
#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   Swt_HashContextStateType State;/* Holds the current state of the context */
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

}
Swt_HashContextType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"
extern SwtRC_t Swt_ComputeHashInit
(
   CONSTP2VAR(Swt_HashContextType,AUTOMATIC,SC_FAR) HashCtx
);

extern SwtRC_t Swt_ComputeHashUpdate
(
   CONSTP2VAR(Swt_HashContextType,AUTOMATIC,SC_FAR) HashCtx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)     Block,
   const uint32            BlockLength
);

extern SwtRC_t Swt_ComputeHashFinalize
(
   CONSTP2VAR(Swt_HashContextType,AUTOMATIC,SC_FAR) HashCtx,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)           Digest
);
#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                          /* if (!defined SWT_HASH_H) */
/*** End of file **************************************************************/
