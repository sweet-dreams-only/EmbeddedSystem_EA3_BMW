/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_DES.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for the DES routines                              **
**                                                                            **
**  REMARKS   : Implementation of the mathematical operations needed for the  **
**              DES algorithm.                                                **
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
** jd           Jochen Decker              Elektrobit Automotive GmbH         **
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.1.0    : 06.02.2007, jd   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

#if (!defined SWT_DES_H)               /* preprocessor exclusion definition */
#define SWT_DES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define SWT_DES_ROUNDS                 16U
#define SWT_DES_KEY_LEN_BYTES           6U
#define SWT_DES_BLOCKSIZE               8U

                                           /* initial value of next, enc mode */
#define SWT_DES_NEXT_ENC_START          0U

                                           /* initial value of next, dec mode */
#define SWT_DES_NEXT_DEC_START SWT_DES_ROUNDS-1



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef uint8 Swt_DESKey[SWT_DES_BLOCKSIZE];

struct Swt_DESContextStruct   /* structure holding the internal DES context */
{
   Swt_DESKey ExpandedKey[SWT_DES_ROUNDS];/* holding the actual round key */
   uint8 NextRoundKeyOffset; /* index into the ExpandedKey for next round key */
};

typedef struct Swt_DESContextStruct       Swt_DESContextType;
typedef        Swt_DESContextType *       Swt_pDESContextStruct;
typedef const  Swt_DESContextType *       Swt_pcDESContextType;
typedef        Swt_DESContextType * const Swt_cpDESContextType;
typedef const  Swt_DESContextType * const Swt_cpcDESContextType;

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

extern void Swt_DESInit
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Key
);

extern void Swt_DESEncryptBlock
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx,
   P2CONST(uint8, AUTOMATIC,SC_FAR) InputBlock,
   P2VAR(uint8,AUTOMATIC,SC_FAR) OutputBlock
);

extern void Swt_DESDecryptBlock
(
   CONSTP2VAR(Swt_DESContextType,AUTOMATIC,SC_FAR) Ctx,
   P2CONST(uint8, AUTOMATIC,SC_FAR) InputBlock,
   P2VAR(uint8,AUTOMATIC,SC_FAR) OutputBlock
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                           /* if (!defined SWT_DES_H) */
/*** End of file **************************************************************/
