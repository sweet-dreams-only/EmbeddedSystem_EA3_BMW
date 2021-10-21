/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_PBKDF1.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for the PBKDF1 routines                           **
**                                                                            **
**  REMARKS   : Implementation of the mathematical operations needed for the  **
**              PBKDF1 algorithm.                                             **
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
** cb           Christian Blomenhofer      Elektrobit Automotive GmbH         **
** jd           Jochen Decker              Elektrobit Automotive GmbH         **
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.1.0    : 08.02.2007, jd   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Common.h"                              /* common declarations */
#include "Swt_MD5.h"                        /* declarations of MD5 services */
#include "Swt_PBKDF1.h"                  /* declarations of pbkdf1 services */

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
**                       External Constants                                   **
*******************************************************************************/

/*******************************************************************************
**                       External Data                                        **
*******************************************************************************/

/*******************************************************************************
**                       Local Constants                                      **
*******************************************************************************/

/*******************************************************************************
**                       Local Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_PBKDF1                                              **
**                                                                            **
** DESCRIPTION    : Computes the the PKCS#5 key accordingly PBKDF1            **
**                                                                            **
** PRECONDITIONS  : 'Password' shall be a valid pointer (not checked)         **
**                  'Salt' shall be a valid pointer (not checked)             **
**                  'Key' shall be a valid pointer (not checked)              **
**                                                                            **
** POSTCONDITIONS : After return Key holds the computed key.                  **
**                                                                            **
** PARAMETER      : Password : Pointer to the password.                       **
**                  PasswordLen : Length of the password.                     **
**                  Salt : Pointer to the salt.                               **
**                  Iterations : Count of iterations.                         **
**                  Key : Pointer to the computed key.                        **
**                  KeyLen : Length of the computed key.                      **
** RETURN         : void                                                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : Constant time for all valid inputs.                       **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_PBKDF1
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Password,
   const uint8                          PasswordLen,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Salt,
   const uint8                          Iterations,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)   Key,
   const uint8                          KeyLen
)
{
   Swt_MD5ContextType Ctx;
   uint8 Digest[SWT_MD5_LEN_BYTES];
   uint8_least i;

   if (KeyLen > (uint8)SWT_MD5_LEN_BYTES)
   {
      return Swt_RC_BAD_PARAM;
   }

   /* T1 = Hash(P||S)                                                         */
   Swt_MD5Init(&Ctx);

   Swt_MD5Update(&Ctx, Password, (uint32)PasswordLen);
   Swt_MD5Update(&Ctx, Salt, (uint32)SWT_PBKDF1_SALT_LEN_BYTES);

   Swt_MD5Finish(&Ctx, Digest);

   for (i=0; i < (uint8_least)Iterations; i++)
   {
      /* Tn = Hash(Tn-1)                                                      */
      Swt_MD5Init(&Ctx);

      Swt_MD5Update(&Ctx, Digest, (uint32)SWT_MD5_LEN_BYTES);

      Swt_MD5Finish(&Ctx, Digest);
   }

   /* return KeyLength of the digest as key                                   */
   (void)Swt_CommonCopy(Key, Digest, (uint32)KeyLen);

   return Swt_RC_OK;
}



/*******************************************************************************
**                      internal function definitions                         **
*******************************************************************************/

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
