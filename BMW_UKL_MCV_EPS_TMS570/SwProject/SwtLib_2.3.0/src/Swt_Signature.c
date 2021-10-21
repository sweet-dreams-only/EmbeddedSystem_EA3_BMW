/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Signature.c                                             **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions of the signature services.                        **
**                                                                            **
**  REMARKS   : Implementation of the RSASSA-PKCS1-v1_5 signature             **
**              verification routines as defined in PKCS #1 v2.1.             **
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Signature.h"             /* declaration of signature services */
#include "Swt_Common.h"            /* declarations of Swt common services */
#include "Swt_RSA.h"                        /* declarations of rsa services */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/


/*******************************************************************************
**                      External Constants                                    **
*******************************************************************************/


/*******************************************************************************
**                      External Data                                         **
*******************************************************************************/


/*******************************************************************************
**                      Local Constants                                       **
*******************************************************************************/


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"





/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_SignatureCheck                                      **
**                                                                            **
** DESCRIPTION    : Performs an asymmetrical signature check.                 **
**                                                                            **
** PRECONDITIONS  : 'Signature' is a valid pointer (not checked)              **
**                  'Data' is a valid pointer (not checked)                   **
**                  'PublicKeyPtr' is a valid pointer (not checked)           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Signature : A pointer to the start of a byte array        **
**                              containing the signature to check.            **
**                  SignatureLength : The length of the signature to check.   **
**                  Data : A pointer to the start of a byte array containing  **
**                         the data whose signature is to be checked.         **
**                  SignatureLength : The lenght of the data block.           **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a parameter was invalid            **
**                     (debug check value)                                    **
**                  Swt_RC_OK, if the signature was valid                   **
**                  Swt_RC_SIG_CHECK_FAILURE, if the signature was invalid  **
**                  Swt_UNKNOWN_ERROR, if some error occurred               **
**                                                                            **
** REMARKS        : This function implements the signature verification       **
**                  operation of the RSASSA-PKCS1-v1_5 signature scheme       **
**                  according to the standard PKCS #1 v2.1.                   **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_SignatureCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            Signature,
  const uint16                                    SignatureLength,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            Data,
  const uint16                                    DataLength,
  CONSTP2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) PublicKeyPtr
)
{
   SwtRC_t             RetVal;
   Swt_SigContextType  SignatureCtx;


                     /* Initialise the context of the signature verification. */
   RetVal =  Swt_VerifyAsymInit( &SignatureCtx );

                                  /* Feed the data to the signature function. */
   if( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_VerifyAsymUpdate( &SignatureCtx,
                                       Data,
                                       DataLength );
   }

                                                      /* Check the signature. */
   if( Swt_RC_OK == RetVal )
   {
      if( Swt_RC_EQUAL !=
          Swt_VerifyAsymFinalize( &SignatureCtx,
                                    PublicKeyPtr,
                                    Signature,
                                    SignatureLength ) )
      {
         RetVal = Swt_RC_SIG_CHECK_FAILURE;
      }
   }

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_VerifyAsymInit                                      **
**                                                                            **
** DESCRIPTION    : Initializes the asymmetrical signature check.             **
**                                                                            **
** PRECONDITIONS  : 'SigCtx' is a valid pointer (not checked)                 **
**                  'SigCtx->HashCtx' is a valid pointer (not checked)        **
**                                                                            **
** POSTCONDITIONS : 'SigCtx' is initialized.                                  **
**                                                                            **
** PARAMETERS     : SigCtx : The context which has to be initialized.         **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a parameter was invalid            **
**                     (debug check value)                                    **
**                  Swt_RC_OK, if the initialization was successful         **
**                  Swt_UNKNOWN_ERROR, if some error occurred               **
**                                                                            **
** REMARKS        : This function implements the signature verification       **
**                  operation of the RSASSA-PKCS1-v1_5 signature scheme       **
**                  according to the standard PKCS #1 v2.1.                   **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_VerifyAsymInit
(
   CONSTP2VAR(Swt_SigContextType,AUTOMATIC,SC_FAR) SigCtx
)
{
   SwtRC_t RetVal;                      /* the return value of the function */

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( 0 == SigCtx )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_VERIFY_ASYM_INIT_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
   else
   {
      SigCtx->ContextState = SWT_SIG_STATE_UNINITIALIZED;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */


   RetVal = Swt_ComputeHashInit( &(SigCtx->HashCtx) );

   if( Swt_RC_OK != RetVal )
   {
      RetVal = Swt_RC_UNKNOWN_ERROR;
   }
#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   else
   {
      SigCtx->ContextState = SWT_SIG_STATE_VRFY_IN_PROGRESS;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_VerifyAsymUpdate                                    **
**                                                                            **
** DESCRIPTION    : Gets one block which is part of a collection of blocks to **
**                  be signed and feeds it to the signature function.         **
**                                                                            **
** PRECONDITIONS  : 'SigCtx' is a valid pointer and is initialized            **
**                  properly (not checked)                                    **
**                  'Block' is a valid pointer (not checked)                  **
**                                                                            **
** POSTCONDITIONS : 'SigCtx' is updated                                       **
**                                                                            **
** PARAMETERS     : SigCtx:      The context which has to be updated          **
**                  Block:       A block of memory which is part of a         **
**                               collection of blocks of a signature check    **
**                  BlockLength: The length of the block in bytes             **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a parameter was invalid            **
**                     (debug check value)                                    **
**                  Swt_RC_INVALID_SIG_CONTEXT, if the context has not been **
**                      initialized (debug check value)                       **
**                  Swt_RC_OK, if the update was successful                 **
**                  Swt_RC_UNKNOWN_ERROR, if something went wrong           **
**                                                                            **
** REMARKS        : This function implements the signature verification       **
**                  operation of the RSASSA-PKCS1-v1_5 signature scheme       **
**                  according to the standard PKCS #1 v2.1.                   **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_VerifyAsymUpdate
(
   CONSTP2VAR(Swt_SigContextType,AUTOMATIC,SC_FAR) SigCtx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)    Block,
   const uint16           BlockLength
)
{
   SwtRC_t RetVal;                      /* the return value of the function */

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( (0 == SigCtx) || (0 == Block) )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_VERIFY_ASYM_UPDATE_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
   else
   {
      if( SWT_SIG_STATE_VRFY_IN_PROGRESS != SigCtx->ContextState )
      {
                                               /* report the error to the DET */
         Det_ReportError
         (
            SWT_DET_MODULE_ID,
            (uint8)SWT_VERIFY_ASYM_UPDATE_API_ID,
            (uint8)Swt_RC_INVALID_SIG_CONTEXT
         );

         return Swt_RC_INVALID_SIG_CONTEXT;
      }
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */


   RetVal = Swt_ComputeHashUpdate( &(SigCtx->HashCtx), Block, BlockLength );

   if( Swt_RC_OK != RetVal )
   {
      RetVal = Swt_RC_UNKNOWN_ERROR;
   }

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_VerifyAsymFinalize                                  **
**                                                                            **
** DESCRIPTION    : Computes a signature of the blocks that have been fed to  **
**                  the context and checks whether it is identical to an      **
**                  already given signature.                                  **
**                                                                            **
** PRECONDITIONS  : 'SigCtx' is a valid pointer (checked) and is initialized  **
**                  properly (checked by subfunction)                         **
**                  'PublicKey' is a valid pointer (checked)                  **
**                  'Signature' is a valid pointer (checked)                  **
**                  'PublicKey->Modulus' is the normalized long number        **
**                     representation of a non-zero number (checked)          **
**                  'PublicKey->Exponent' is the normalized long number       **
**                     representation of a non-zero number (checked)          **
**                                                                            **
** POSTCONDITIONS : 'SigCtx' is deinitialized                                 **
**                                                                            **
** PARAMETERS     : SigCtx:          A pointer to a context                   **
**                  PublicKey:       A pointer to a structure which contains  **
**                                   the public key                           **
**                  Signature:       A byte array contatining the signature   **
**                  SignatureLength: The length of the signature              **
**                                                                            **
** RETURN         : Swt_RC_EQUAL, if the signature is correct               **
**                  Swt_RC_NOT_EQUAL, if the signature does not match       **
**                  Swt_RC_BAD_PARAM, if a parameter was invalid            **
**                  Swt_RC_UNKNOWN_ERROR, if an error occurred during hash  **
**                                finalization                                **
**                  Swt_RC_INVALID_SIG_CONTEXT, if the context has not been **
**                                             initialized                    **
**                                                                            **
** REMARKS        : This function implements the signature verification       **
**                  operation of the RSASSA-PKCS1-v1_5 signature scheme       **
**                  according to the standard PKCS #1 v2.1.                   **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_VerifyAsymFinalize
(
   CONSTP2VAR(Swt_SigContextType,AUTOMATIC,SC_FAR) SigCtx,
   CONSTP2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR)    PublicKey,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)    Signature,
   const uint16           SignatureLength
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   Swt_LNWordType i;                                      /* count variable */
   Swt_LNWordType length;                           /* length of fill bytes */
   uint8          EncodedMessage[SWT_SIG_LEN_BYTES]; /* the encoded message */
                               /* the signature in long number representation */
   Swt_LNWordType LNSignature[Swt_LNGetWordLen(SWT_SIG_LEN_BYTES)];
                         /* the encoded message in long number representation */
   Swt_LNWordType LNEncodedMessage[Swt_LNGetResultLen(SWT_SIG_LEN_BYTES)];
                                        /* context of a modulo exponentiation */
   Swt_LNExpModularContextType MexpCtx;

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
                                              /* digest info of hash function */
    SWT_STATIC_VAR const uint8
         Swt_SigDigestInfo[SWT_HASH_DIGESTINFO_LEN_BYTES] =
                                                          SWT_HASH_DIGESTINFO;
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if
   (
                                                        /* NULL pointer check */
      ((((((0 == PublicKey) ||
           (0 == PublicKey->Exponent)) ||
           (0 == PublicKey->Modulus)) ||
           (0 == SigCtx)) ||
           (0 == Signature)) ||
                                  /* Are the numbers normalized and non-zero? */
       (((Swt_LNWordType)0 == PublicKey->Exponent[PublicKey->Exponent[0]]) ||
        ((Swt_LNWordType)0 == PublicKey->Modulus[PublicKey->Modulus[0]])))
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
        // TODO: Barrett
//      || (0 == PublicKey->ModulusExt)
#endif
   )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_VERIFY_ASYM_FINALIZE_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
   else
   {
      if( SWT_SIG_STATE_VRFY_IN_PROGRESS != SigCtx->ContextState)
      {
                                               /* report the error to the DET */
         Det_ReportError
         (
            SWT_DET_MODULE_ID,
            (uint8)SWT_VERIFY_ASYM_FINALIZE_API_ID,
            (uint8)Swt_RC_INVALID_SIG_CONTEXT
         );

         return Swt_RC_INVALID_SIG_CONTEXT;
      }
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */


   RetVal = Swt_RC_OK;

                    /* Transform the signature to long number representation. */
   Swt_LNByteArrayToNumber
   (
      Signature,
      SignatureLength,
      LNSignature
   );

          /* Decrypt the signature and store the value in 'LNEncodedMessage'. */
   Swt_LNExponentiateModular
   (
      &(MexpCtx),
      PublicKey->Modulus,
      PublicKey->Exponent,
      PublicKey->ModulusExt,
      LNSignature,
      LNEncodedMessage
   );

   /* The decrypted signature is converted from long number representation    */
   /* to a byte array (called "encoded message", or "EM") and stored          */
   /* EncodedMessage.                                                         */
   length = Swt_LNNumberToByteArray
                    (
                       LNEncodedMessage,
                       EncodedMessage
                    );


   if             /* The EM must be as long as the modulus of the public key. */
   (
      length !=
      ((PublicKey->Modulus[0]) * (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES)
   )
   {
      RetVal = Swt_RC_NOT_EQUAL;
   }

   /* The encoded message must have the form                                  */
   /* 0x00 0x01 0xff ... 0xff 0x00 || DigestInfo || HashValue                 */

   /* The first two bytes of the decrypted signature must be 0x00 and         */
   /* 0x01, respectively.                                                     */
   if
   (
      ((uint8)0 != EncodedMessage[0]) ||
      ((uint8)1 != EncodedMessage[1])
   )
   {
      RetVal = Swt_RC_NOT_EQUAL;
   }

   /* There must be a block of bytes containing 0xff. We compute the          */
   /* length of the block.                                                    */
   length  = PublicKey->Modulus[0] *
             (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES;

   length -= (Swt_LNWordType)(
                                SWT_HASH_LEN_BYTES +
                                SWT_HASH_DIGESTINFO_LEN_BYTES +
                                1U
                             );

                                   /* We check for the contents of the block. */
   for( i = (Swt_LNWordType)2; i < length; i++ )
   {
      if( (uint8)0xff != EncodedMessage[i] )
      {
         RetVal = Swt_RC_NOT_EQUAL;
      }
   }

   if( (uint8)0x00 != EncodedMessage[i] )      /* The next byte must be 0x00. */
   {
      RetVal = Swt_RC_NOT_EQUAL;
   }

   i++;

   if( Swt_RC_OK == RetVal )
   {
                              /* The next block must contain the digest info. */
      RetVal = Swt_CommonCompare
               (
                  &EncodedMessage[i],
                  Swt_SigDigestInfo,
                  (uint32)SWT_HASH_DIGESTINFO_LEN_BYTES
               );

      i += (Swt_LNWordType)SWT_HASH_DIGESTINFO_LEN_BYTES;

      if( Swt_RC_EQUAL == RetVal )
      {
         RetVal = Swt_RC_OK;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      /* Compute the hash value and store it in the first bytes of            */
      /* EncodedMessage. We have already checked those bytes and can          */
      /* use them as temporary space now.                                     */
      RetVal = Swt_ComputeHashFinalize( &(SigCtx->HashCtx), EncodedMessage );
   }

   if( Swt_RC_OK == RetVal )
   {
                        /* The rest of the block must contain the hash value. */
      RetVal = Swt_CommonCompare
               (
                  &(EncodedMessage[i]),
                  EncodedMessage,
                  (uint32)SWT_HASH_LEN_BYTES
               );
   }

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   SigCtx->ContextState = SWT_SIG_STATE_UNINITIALIZED;
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   return RetVal;
}
#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/




/*** End of file **************************************************************/
