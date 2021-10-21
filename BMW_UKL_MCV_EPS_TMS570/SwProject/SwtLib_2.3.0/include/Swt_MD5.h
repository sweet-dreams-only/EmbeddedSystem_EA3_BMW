/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_MD5.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Implementation of the message digest algorithm MD5            **
**              see RFC 1321.                                                 **
**                                                                            **
**  REMARKS   :                                                               **
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

#if (!defined SWT_MD5_H)               /* preprocessor exclusion definition */
#define SWT_MD5_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

                               /* list of guards to prevent double definition */
#if (defined SWT_MD5_BLOCK_SIZE)
   #error SWT_MD5_BLOCK_SIZE already defined
#endif                                   /* if (defined SWT_MD5_BLOCK_SIZE) */

#if (defined SWT_MD5_STATE_WORDS)
   #error SWT_MD5_STATE_WORDS already defined
#endif                                  /* if (defined SWT_MD5_STATE_WORDS) */

#if (defined SWT_MD5_STATE_BYTES)
   #error SWT_MD5_STATE_BYTES already defined
#endif                                  /* if (defined SWT_MD5_STATE_BYTES) */

#if (defined SWT_MD5_LEN_BYTES)
   #error SWT_MD5_LEN_BYTES already defined
#endif                                    /* if (defined SWT_MD5_LEN_BYTES) */

#if (defined SWT_MD5_DIGESTINFO)
   #error SWT_MD5_DIGESTINFO already defined
#endif                                   /* if (defined SWT_MD5_DIGESTINFO) */

#if (defined SWT_MD5_DIGESTINFO_LEN_BYTES)
   #error SWT_MD5_DIGESTINFO_LEN_BYTES already defined
#endif                         /* if (defined SWT_MD5_DIGESTINFO_LEN_BYTES) */


#define SWT_MD5_BLOCK_SIZE  64U                /* Blocksize of MD5 in bytes */
#define SWT_MD5_STATE_WORDS  4U       /* Number of entries of the MD5 state */
#define SWT_MD5_STATE_BYTES 16U         /* Number of bytes of the MD5 state */
#define SWT_MD5_LEN_BYTES SWT_MD5_STATE_BYTES    /* Size of an MD5 digest */

/* The DER-encoded digestInfo of the MD5 hash algorithm as described in       */
/* chapter 9.2 of the standard PKCS #1 v2.1. This is used in some encoded     */
/* signatures, as, e.g., in the signature of an X.509 certificate.            */
#define SWT_MD5_DIGESTINFO                                        \
{                                                                   \
   (uint8)0x30, (uint8)0x20, (uint8)0x30, (uint8)0x0c, (uint8)0x06, \
   (uint8)0x08, (uint8)0x2a, (uint8)0x86, (uint8)0x48, (uint8)0x86, \
   (uint8)0xf7, (uint8)0x0d, (uint8)0x02, (uint8)0x05, (uint8)0x05, \
   (uint8)0x00, (uint8)0x04, (uint8)0x10                            \
}

                         /* The length of the DER-encoded digestInfo in bytes */
#define SWT_MD5_DIGESTINFO_LEN_BYTES 18U


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef struct
{
   uint32 State[SWT_MD5_STATE_WORDS];    /* The result of the hash function */
   uint32 Count;                            /* Amount of bytes already hashed */
   uint8  Partial[SWT_MD5_BLOCK_SIZE];                        /* Input data */
}
Swt_MD5ContextType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"
extern void Swt_MD5Init
(
   CONSTP2VAR(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx
);

extern void Swt_MD5Update
(
   CONSTP2VAR(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)    Block,
   const uint32           BlockLength
);

extern void Swt_MD5Finish
(
   CONSTP2VAR(Swt_MD5ContextType,AUTOMATIC,SC_FAR) MD5Ctx,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)          Digest
);
#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                           /* if (!defined SWT_MD5_H) */
/*** End of file **************************************************************/
