/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Signature.h                                             **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Declarations of the signature routines.                       **
**                                                                            **
**  REMARKS   : Implementation of the RSASSA-PKCS1-v1_5 signature computation **
**              and verification routines as defined in PKCS #1 v2.1.         **
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
 * V2.0.0    : 04.04.2007, mg   : made different signature lengths for FSCs and
 *                                certificates possible
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

#if (!defined SWT_SIGNATURE_H)         /* preprocessor exclusion definition */
#define SWT_SIGNATURE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Hash.h"                      /* declarations of hash services */
#include "Swt_RSA.h"                        /* declarations of rsa services */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
typedef enum                       /* internal state of the signature context */
{
   SWT_SIG_STATE_UNKNOWN = 0,                              /* unknown state */
   SWT_SIG_STATE_UNINITIALIZED,     /* the context has not been initialized */
   SWT_SIG_STATE_INITIALIZED,               /* context has been initialized */
   SWT_SIG_STATE_SIGN_IN_PROGRESS,                /* encryption in progress */
   SWT_SIG_STATE_VRFY_IN_PROGRESS                 /* decryption in progress */
}
Swt_SigContextStateType;
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

typedef struct
{
#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
                                                  /* the state of the context */
   Swt_SigContextStateType ContextState;
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

                                             /* context of a hash computation */
   Swt_HashContextType     HashCtx;
}
Swt_SigContextType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

extern SwtRC_t Swt_SignatureCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            Signature,
  const uint16                                    SignatureLength,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            Data,
  const uint16                                    DataLength,
  CONSTP2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) PublicKeyPtr
);

extern SwtRC_t Swt_VerifyAsymInit
(
   CONSTP2VAR(Swt_SigContextType,AUTOMATIC,SC_FAR) SigCtx
);


extern SwtRC_t Swt_VerifyAsymUpdate
(
   CONSTP2VAR(Swt_SigContextType,AUTOMATIC,SC_FAR) SigCtx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)              Block,
   const uint16                                      BlockLength
);


extern SwtRC_t Swt_VerifyAsymFinalize
(
   CONSTP2VAR(Swt_SigContextType,AUTOMATIC,SC_FAR) SigCtx,
   CONSTP2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR)   PublicKey,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)              Signature,
   const uint16                                      SignatureLength
);
#define SWT_STOP_SEC_CODE
#include "MemMap.h"


#endif                                     /* if (!defined SWT_SIGNATURE_H) */
/*** End of file **************************************************************/
