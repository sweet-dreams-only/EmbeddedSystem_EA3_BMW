/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Diffie.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for Diffie-Hellman key exchange.                  **
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
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */



/*******************************************************************************
**                      inclusions                                            **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_DES.h"                        /* declarations of DES services */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_RSA.h"                        /* declarations of RSA services */
#include "Swt_Diffie.h"                   /* declarations for Diffie-Helman */


/*******************************************************************************
**                      macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      type definitions                                      **
*******************************************************************************/

/*******************************************************************************
**                      external function declarations                        **
*******************************************************************************/

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

#define SWT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ComputeKeyExchangeMyPublic                          **
**                                                                            **
** DESCRIPTION    : Diffie-Hellman Key Exchange: Creates the public key which **
**                  is to be sent to the communcation partner from the        **
**                  shared generator, the shared modulus and the secret       **
**                  exponent.                                                 **
**                                                                            **
** PRECONDITIONS  : 'Ctx' is a valid pointer (checked)                        **
**                                                                            **
**                  'Algo' is a valid pointer (checked)                       **
**                                                                            **
**                  'MySecret' is a valid pointer (checked)                   **
**                                                                            **
**                  'MyPublic' is a valid pointer (checked)                   **
**                                                                            **
**                                                                            **
** POSTCONDITIONS : 'MyPublic' contains the key exchange parameter which is   **
**                  to be sent to the communication partner. Its length is    **
**                  exactly the length of the common modulus                  **
**                                                                            **
** PARAMETERS     : Ctx:             A pointer to a context                   **
**                  Algo:            A pointer to an Diffie-Hellman key       **
**                                   exchange structure containing the        **
**                                   shared modulus and generator             **
**                  MySecret:        The long number representation of the    **
**                                   secret exponent                          **
**                  MyPublic:        The public key which is to be sent to    **
**                                   the communication partner                **
**                                                                            **
** RETURN         : Swt_RC_OK, if the computation was successful            **
**                  Swt_RC_UNKNOWN_ERROR, if an error occurs                **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_ComputeKeyExchangeMyPublic
(
   CONSTP2VAR(Swt_DiffieContextType,AUTOMATIC,SC_FAR)     Ctx,
   CONSTP2CONST(Swt_AlgoKeyExchangeType,AUTOMATIC,SC_FAR) Algo,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)          MySecret,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)                       MyPublic
)
{
   SwtRC_t RetVal;
   Swt_LNWordType i;

   if
   (
      ((((0 != Ctx) &&
         (0 != Algo)) &&
         (0 != MySecret)) &&
         (0 != MyPublic))
   )
   {
#if SWT_RSA_USE_BARRETT == SWT_CFG_ON
      // TODO: Barrett
      if (0 != Algo->CommonModulusExt)
      {
#endif
         RetVal = Swt_RC_OK;

         Swt_LNExponentiateModular
            (
            &Ctx->MexpCtx,
            Algo->CommonModulus,
            MySecret,
            Algo->CommonModulusExt,
            Algo->CommonGenerator,
            Ctx->Result
            );

         /* If the result does not have the full length of the modulus, it is    */
         /* padded with leading zeroes.                                          */
         for
            (
            i = (Ctx->Result[0] + (Swt_LNWordType)1);
         i <= Algo->CommonModulus[0];
         i++
            )
         {
            Ctx->Result[i] = (Swt_LNWordType)0;
         }

         Ctx->Result[0] = Algo->CommonModulus[0];

         /* The result is converted to a byte array. We know that the length     */
         /* of the byte array is the length of the modulus. So, we can ignore    */
         /* the length returned by the conversion function.                      */
         (void)Swt_LNNumberToLEByteArray(Ctx->Result, MyPublic);
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
      }
      else 
      {
         RetVal = Swt_RC_UNKNOWN_ERROR;
      }
#endif
   }
   else
   {
      RetVal = Swt_RC_UNKNOWN_ERROR;
   }

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ComputeKeyExchangeCommonKey                         **
**                                                                            **
** DESCRIPTION    : Diffie-Hellman Key Exchange: The symmetrical key is       **
**                  computed from the public key sent by the communication    **
**                  partner                                                   **
**                                                                            **
** PRECONDITIONS  : 'Ctx' is a valid pointer (checked)                        **
**                                                                            **
**                  'Algo' is a valid pointer (checked)                       **
**                                                                            **
**                  'PartnerPublic' is a valid pointer (checked)              **
**                                                                            **
**                  'MySecret' is a valid pointer (checked)                   **
**                                                                            **
**                  'CommonKey' is a valid pointer (checked)                  **
**                                                                            **
**                                                                            **
** POSTCONDITIONS : 'CommonKey' contains the symmetrical key which both       **
**                  communication partners can use.                           **
**                                                                            **
** PARAMETERS     : Ctx:             A pointer to a context                   **
**                  Algo:            A pointer to an Diffie-Hellman key       **
**                                   exchange structure containing the        **
**                                   shared modulus                           **
**                  PartnerPublic:   A byte array containing the public key   **
**                                   which has been sent by the communication **
**                                   partner. Its length has to be exactly    **
**                                   the length of the common modulus         **
**                  MySecret:        The long number representation of the    **
**                                   secret exponent                          **
**                  CommonKey:       The symmetrical key as a byte array      **
**                                   which has the length of a symmetrical key**
**                                                                            **
** RETURN         : Swt_RC_OK, if the computation was successful            **
**                  Swt_RC_UNKNOWN_ERROR, if an error occurs                **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_ComputeKeyExchangeCommonKey
(
   CONSTP2VAR(Swt_DiffieContextType,AUTOMATIC,SC_FAR)     Ctx,
   CONSTP2CONST(Swt_AlgoKeyExchangeType,AUTOMATIC,SC_FAR) Algo,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                     PartnerPublic,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)          MySecret,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)                       CommonKey
)
{
   SwtRC_t RetVal;
   Swt_LNWordType i;

   if
      (
      (((((0 != Ctx) &&
      (0 != Algo)) &&
      (0 != PartnerPublic)) &&
      (0 != MySecret)) &&
      (0 != CommonKey))
      )
   {
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
      // TODO: Barrett
      if (0 != Algo->CommonModulusExt)
      {
#endif
         RetVal = Swt_RC_OK;

         Swt_LNLEByteArrayToNumber
            (
            PartnerPublic,
            (uint16)(Algo->CommonModulus[0] *
            (Swt_LNWordType)SWT_LN_WORD_LEN_BYTES),
            Ctx->Temp
            );

         Swt_LNExponentiateModular
            (
            &Ctx->MexpCtx,
            Algo->CommonModulus,
            MySecret,
            Algo->CommonModulusExt,
            Ctx->Temp,
            Ctx->Result
            );

         /* If the result does not have the full length of the modulus, it is    */
         /* padded with leading zeroes.                                          */
         for
            (
            i = (Ctx->Result[0] + (Swt_LNWordType)1);
         i <= Algo->CommonModulus[0];
         i++
            )
         {
            Ctx->Result[i] = (Swt_LNWordType)0;
         }

         Ctx->Result[0] = Algo->CommonModulus[0];

         /* The result is converted to a byte array. We know that the length     */
         /* of the byte array is the length of the modulus. So, we can ignore    */
         /* the length returned by the conversion function.                      */
         (void)Swt_LNNumberToLEByteArray(Ctx->Result, CommonKey);

#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)   
      }
      else
      {
         RetVal = Swt_RC_BAD_PARAM;
      }
#endif
   }
   else
   {
      RetVal = Swt_RC_BAD_PARAM;
   }

   return RetVal;
}

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      internal function definitions                         **
*******************************************************************************/

/*** End of file **************************************************************/
