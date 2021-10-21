/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Diffie.h                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Declarations for Diffie-Hellman key exchange                  **
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
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.0.1    : 08.02.2007, fs   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.0.0    : 04.04.2007, mg   : made different signature lengths for FSCs and
 *                                certificates possible
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

#if (!defined SWT_DIFFIE_H)
#define SWT_DIFFIE_H

/*******************************************************************************
**                      inclusions                                            **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_RSA.h"                        /* declarations of RSA routines */

/*******************************************************************************
**                      macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      type definitions                                      **
*******************************************************************************/

                                  /* context of a Diffie-Hellman key exchange */
typedef struct
{
   /* a temporary variable which can hold a number with length up to the      */
   /* length of a key                                                         */
   Swt_LNWordType    Temp[Swt_LNGetWordLen(SWT_DIFFIE_KEY_LEN_BYTES)];
                                     /* the result of a modulo exponentiation */
   Swt_LNWordType    Result[Swt_LNGetResultLen(SWT_DIFFIE_KEY_LEN_BYTES)];
                                        /* context of a modulo exponentiation */
   Swt_LNExpModularContextType MexpCtx;
}
Swt_DiffieContextType;

                               /* the Diffie-Hellman key exchange information */
typedef struct
{
       /* a pointer to the long number representation of the shared generator */
   P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) CommonGenerator;
         /* a pointer to the long number representation of the shared modulus */
   P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) CommonModulus;
                             /* a pointer to the extended modulus information */
   P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) CommonModulusExt;
}
Swt_AlgoKeyExchangeType;


/*******************************************************************************
**                      external function declarations                        **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

extern SwtRC_t Swt_ComputeKeyExchangeMyPublic
(
   CONSTP2VAR(Swt_DiffieContextType,AUTOMATIC,SC_FAR)     Ctx,
   CONSTP2CONST(Swt_AlgoKeyExchangeType,AUTOMATIC,SC_FAR) Algo,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)          MySecret,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)                       MyPublic
);


extern SwtRC_t Swt_ComputeKeyExchangeCommonKey
(
   CONSTP2VAR(Swt_DiffieContextType,AUTOMATIC,SC_FAR)     Ctx,
   CONSTP2CONST(Swt_AlgoKeyExchangeType,AUTOMATIC,SC_FAR) Algo,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                     PartnerPublic,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)          MySecret,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)                       CommonKey
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      internal function declarations                        **
*******************************************************************************/

/*******************************************************************************
**                      external constants                                    **
*******************************************************************************/

/*******************************************************************************
**                      external data                                         **
*******************************************************************************/

/*******************************************************************************
**                      internal constants                                    **
*******************************************************************************/

/*******************************************************************************
**                      internal data                                         **
*******************************************************************************/

/*******************************************************************************
**                      external function definitions                         **
*******************************************************************************/

/*******************************************************************************
**                      internal function definitions                         **
*******************************************************************************/

#endif /* if (!defined SWT_DIFFIE_H) */
/*** End of file **************************************************************/
