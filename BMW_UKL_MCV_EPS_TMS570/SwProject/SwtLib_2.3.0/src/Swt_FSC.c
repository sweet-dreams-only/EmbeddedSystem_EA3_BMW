/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_FSC.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definition of FSC services, i.e. the representation of a FSC  **
**              and the access to FSC elements.                               **
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
 * V2.0.0    : 04.04.2007, mg   : Upgrade index of SWID is now handled correctly
 * V2.0.1    : 10.04.2007, mg   : removed "unused variable" warnings in certain
 *                                configurations of the validity cond. parser
 * V2.1.0    : 01.09.2007, djk  : Modified parameter of Swt_FSCCheckSWID
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_FSC.h"                        /* declarations of FSC services */
#include "Swt_Common.h"            /* declarations of Swt common services */
#include "Swt_Date.h"                                        /* date parser */
#include "Appl_Swt.h"             /* platform specific services */

#include "Swt_Signature.h"            /* declarations of signature services */
#include "Swt_RSA.h"                                        /* RSA services */

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

#define SWT_START_SEC_CODE
#include "MemMap.h"

/*SWT_STATIC_FUNC [MP]*/ SwtRC_t Swt_GetPos
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   const uint16                         FscLength,
   const Swt_FSCElement               Element,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  PosPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_ParseSWID
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId
);

SWT_STATIC_FUNC SwtRC_t Swt_ParseSupplierNr
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SupplierNr
);

SWT_STATIC_FUNC SwtRC_t Swt_ParseOrderNr
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) OrderNr
);

SWT_STATIC_FUNC SwtRC_t  Swt_ParseRequesterId
(
   uint8                                RequesterType,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) RequesterId,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_ParseValidityField
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityField,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_ParseValidityGroup
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityGroup,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr,
   const uint16                          MaxLength
);

SWT_STATIC_FUNC SwtRC_t Swt_ParseValidityCond
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityCond,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
);

SWT_STATIC_FUNC SwtRC_t  Swt_ParseIndivAttribute
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) IndivAttribute,
   const uint8                          IndivType,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
);

SWT_STATIC_FUNC uint16 Swt_ParseDate
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Date
);

SWT_STATIC_FUNC SwtRC_t Swt_ParseAdditionalFields
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) AdditionalFields,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_CheckValidityGroup
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityGroup,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_CheckValidityCond
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityCond,
   CONSTP2VAR(boolean,AUTOMATIC,SC_FAR) CondIsGeneralPtr,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
);

SWT_STATIC_FUNC uint16 Swt_TellAppCond
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityCond,
   const SwtRC_t                      GroupIsValid
);

SWT_STATIC_FUNC boolean Swt_IsPrintableASCII
(
   const uint8 symbol
);

SWT_STATIC_FUNC uint32 Swt_GetBigEndianNumber
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) NumberArray,
   const uint8                          NumberOfBytes
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      Global Constants                                      **
*******************************************************************************/



/*******************************************************************************
**                      Global Data                                           **
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
** FUNC-NAME      : Swt_FSCParse                                            **
**                                                                            **
** DESCRIPTION    : Checks that the given FSC is well formed.                 **
**                                                                            **
** PRECONDITIONS  : 'Fsc'    is a valid pointer to a FSC (not checked)        **
**                  'Length' shall be in range FSC_MIN_LEN ...                **
**                           ... FSC_MAX_LEN (checked)                        **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Fsc       : The pointer to the FSC array                  **
**                  FscLength : The length of the FSC array                   **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a parameter is invalid             **
**                  Swt_RC_INVALID_FSC, if the FSC contains invalid content **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens   **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCParse
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   Fsc,
   const uint16                           FscLength
)
{
                                            /* Parse the FSC to the very end. */
   return Swt_GetPos( Fsc, FscLength, Swt_FSC_END, 0 );
}








/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FSCCheckSWID                                        **
**                                                                            **
** DESCRIPTION    : Checks whether the SWID of an FSC is in line with the     **
**                  SWID of a software.                                       **
**                                                                            **
** PRECONDITIONS  : 'fscSWID' is a valid pointer (not checked)                **
**                  'softwareSWID' is a valid pointer (not checked)           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : fscSWID : Pointer to the start of a SWID array of an FSC  **
**                  softwareSWID : Pointer to the start of a SWID array of    **
**                                 a software                                 **
**                                                                            **
** RETURN         : Swt_RC_SWID_CHECK_FAILURE, if the SWID of the FSC has   **
**                       the wrong application number or if the upgrade index **
**                       is smaller than the upgrade index of the software    **
**                       SWID                                                 **
**                  Swt_RC_OK, if the FSC SWID fits                         **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCCheckSWID
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) FscSWID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SoftwareSWID
)
{
   SwtRC_t RetVal;
   uint16 fscUpgradeIndex;
   uint16 softwareUpgradeIndex;


   if
   (
      (FscSWID[0] == SoftwareSWID[0]) &&
      (FscSWID[1] == SoftwareSWID[1])
   )
   {
      RetVal = Swt_RC_OK;
   }
   else
   {
      RetVal = Swt_RC_SWID_CHECK_FAILURE;
   }

   if( Swt_RC_OK == RetVal )
   {

      fscUpgradeIndex      = (uint16)((uint16)FscSWID[2] * (uint16)0x100) +
                             (uint16)FscSWID[3];
      softwareUpgradeIndex = (uint16)((uint16)SoftwareSWID[2] * (uint16)0x100) +
                             (uint16)SoftwareSWID[3];

      if( fscUpgradeIndex < softwareUpgradeIndex )
      {
         RetVal = Swt_RC_SWID_CHECK_FAILURE;
      }
   }

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FSCCheckDate                                        **
**                                                                            **
** DESCRIPTION    : Compare the creation date of a given FSC to the creation  **
**                  date of an already stored FSC. If the stored FSC is       **
**                  "disabled", check that the given FSC is newer. If the     **
**                  stored FSC is "imported", "accepted", or "rejected",      **
**                  check that the given FSC is not older. If no FSC is       **
**                  stored, succeed automatically.                            **
**                                                                            **
** PRECONDITIONS  : 'Fsc' is a valid pointer (not checked)                    **
**                  'FscStored' is a valid pointer (not checked)              **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Fsc       : The pointer to the FSC array                  **
**                  FscLength : The length of the FSC array                   **
**                  FscStored : The pointer to the already stored FSC array   **
**                  FscStordLength : The length of the already stored FSC     **
**                                   array                                    **
**                  FscStoredState : The state of the already stored FSC      **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC_CREATION_DATE, if the creation date  **
**                             of the FSC is too old                          **
**                  Swt_RC_INVALID_FSC, if the FSC contains invalid content **
**                  Swt_RC_OK, if the date of the FSC is valid              **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCCheckDate
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   const uint16                         FscLength,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) FscStored,
   const uint16                         FscStoredLength,
   const Swt_FSC_State                FscStoredState
)
{
   SwtRC_t RetVal;
   uint16 dateNewPos;                        /* The start pos of a date array */
   uint16 dateOldPos;                        /* The start pos of a date array */


   dateOldPos = 0;
   dateNewPos = 0;

   /* Get the date from the current FSC.                          */
   RetVal = Swt_GetPos(Fsc, FscLength, Swt_FSC_DATE, &dateNewPos);

   if( Swt_RC_OK == RetVal )
   {
      /* Check whether the creation date of an already existing   */
      /* FSC inteferes with the creation date of the current FSC. */
      switch( FscStoredState )
      {
         case Swt_STATE_FSC_IMPORTED:
            /* Fallthrough */
         case Swt_STATE_FSC_ACCEPTED:
            /* Fallthrough */
         case Swt_STATE_FSC_REJECTED:
                                         /* Get the date from the stored FSC. */
            RetVal = Swt_GetPos(FscStored,
                                  FscStoredLength,
                                  Swt_FSC_DATE,
                                  &dateOldPos);


            /* QA-C claims violation of MISRA rule 33: "Right  hand operand   */
            /* of '&&' has side effects." But the call to Swt_DateGet does  */
            /* not have side effects.                                         */
            if
            (
               ( Swt_RC_OK == RetVal) &&
               (
                  Swt_DateGet(&FscStored[dateOldPos], Swt_DATE_FSC_TIME) >
                  Swt_DateGet(&Fsc[dateNewPos], Swt_DATE_FSC_TIME)
               )
            )
            {
               /* If the stored FSC is newer than the new FSC, the new FSC    */
               /* cannot be stored.                                           */
               RetVal = Swt_RC_INVALID_FSC_CREATION_DATE;
            }
            break;

         case Swt_STATE_FSC_DISABLED:
                                       /* Get the date from the disabled FSC. */
            RetVal = Swt_GetPos(FscStored,
                                  FscStoredLength,
                                  Swt_FSC_DATE,
                                  &dateOldPos);

            /* QA-C claims violation of MISRA rule 33: "Right hand operand of */
            /* '&&' has side effects." But the call to Swt_DateGet does not */
            /* have side effects.                                             */
            if
            (
               ( Swt_RC_OK == RetVal) &&
               (
                  Swt_DateGet(&FscStored[dateOldPos], Swt_DATE_FSC_TIME) >=
                  Swt_DateGet(&Fsc[dateNewPos], Swt_DATE_FSC_TIME)
               )
            )
            {
               /* If the disabled FSC is not older than the new FSC, the new  */
               /* FSC cannot be stored.                                       */
               RetVal = Swt_RC_INVALID_FSC_CREATION_DATE;
            }
            break;

         case Swt_STATE_FSC_NOT_EXISTENT:
            break;

         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   return RetVal;
}









/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FSCCheckSignature                                   **
**                                                                            **
** DESCRIPTION    : Check that the signature of the FSC is valid.             **
**                                                                            **
** PRECONDITIONS  : 'Fsc' is a valid pointer (not checked)                    **
**                  'PublicKeyPtr' is a valid pointer (not checked)           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Fsc : A pointer to the start of an array which contains   **
**                        the FSC whose signature shall be checked            **
**                  FscLength : the length of the FSC                         **
**                  PublicKeyPtr : A pointer to a public key with which the   **
**                                 signature shall be checked                 **
**                                                                            **
** RETURN         : Swt_RC_UNKNOWN_ERROR, if there is an error during the   **
**                     initialisation of the crypto algorithms                **
**                  Swt_RC_SIG_CHECK_FAILURE, if the signature is invalid   **
**                  Swt_RC_OK, if the digital signature is valid            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCCheckSignature
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            Fsc,
   uint16                                          FscLength,
   CONSTP2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) PublicKeyPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint16 SignaturePos;


   RetVal = Swt_GetPos(Fsc, FscLength, Swt_FSC_SIGNATURE, &SignaturePos );

   if( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_SignatureCheck ( &Fsc[SignaturePos],
                                      FscLength - SignaturePos,
                                      Fsc,
                                      SignaturePos,
                                      PublicKeyPtr );
   }

   return RetVal;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FSCCheckIndivAttr                                   **
**                                                                            **
** DESCRIPTION    : Check the individualisation attribute of a given FSC:     **
**                  Get the individualisation type from the FSC. If it is     **
**                  "no VIN", check whether the requester type of the FSC is  **
**                  marketing. If the individualisation type is "short VIN"   **
**                  or "long VIN", compare the indiv. attr. to the given VIN. **
**                  VIN.                                                      **
**                                                                            **
** PRECONDITIONS  : 'Fsc' is a valid pointer (not checked)                    **
**                  'VIN' is a valid pointer (not checked)                    **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Fsc       : The pointer to the FSC array                  **
**                  FscLength : The length of the FSC array                   **
**                  VIN : A pointer to the start of a long VIN with which to  **
**                        compare the individualisation attribute of the FSC  **
**                                                                            **
** RETURN         : Swt_RC_OK, if the individualisation attribute is valid  **
**                  Swt_RC_FGN_ACCESS_FAILURE, if the VIN pointer is a null **
**                                               pointer                      **
**                  Swt_RC_FGN_CHECK_FAILURE, otherwise                     **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCCheckIndivAttr
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) VIN
)
{
   SwtRC_t   RetVal;                    /* the return value of the function */
                 /* the position in the VIN where the comparison should start */
   uint16 StartPos;
   uint16 i;                                             /* loop counter */
   uint16 IndivTypePos;        /* the position of the indiv. type in the FSC  */
   uint16 IndivAttrPos;        /* the position of the indiv. attr. in the FSC */
   uint16 RequesterTypePos;


   RequesterTypePos = 0;
   IndivAttrPos     = 0;
   StartPos         = 0;

   if( 0 == VIN )
   {
                                              /* We could not access the VIN. */
      RetVal = Swt_RC_FGN_ACCESS_FAILURE;
   }
   else
   {
      RetVal = Swt_RC_OK;
   }

   if( Swt_RC_OK == RetVal )
   {
                                            /* Get the individualisation type */
      RetVal = Swt_GetPos( Fsc,
                             FscLength,
                             Swt_FSC_INDIVTYPE,
                             &IndivTypePos );
   }

   if( Swt_RC_OK == RetVal )
   {
                                       /* Get the individualisation attribute */
      RetVal = Swt_GetPos( Fsc,
                             FscLength,
                             Swt_FSC_INDIVATTR,
                             &IndivAttrPos );

   }

   if( Swt_RC_OK == RetVal )
   {
                                                    /* Get the requester type */
      RetVal = Swt_GetPos( Fsc,
                             FscLength,
                             Swt_FSC_REQUESTERTYPE,
                             &RequesterTypePos );

   }

   if( Swt_RC_OK == RetVal )
   {
      /* What kind of VIN is stored in the FSC? None, short, or long?         */
      switch(Fsc[IndivTypePos])
      {
         case SWT_INDIV_TYPE_NO_VIN:
            /* This FSC contains no VIN.                                      */

            /* We do not have to check the individualisation attribute. So,   */
            /* we start the comparison after the end of the VIN.              */
            StartPos = (uint16)SWT_INDIV_LONG_VIN_LEN;

            /* An FSC with no VIN is only valid if the requester type is      */
            /* marketing.                                                     */
            if( (uint8)SWT_REQUESTER_TYPE_MARKETING != Fsc[RequesterTypePos] )
            {
               RetVal = Swt_RC_FGN_CHECK_FAILURE;
            }
            break;

         case SWT_INDIV_TYPE_SHORT_VIN:
             /* We only have to check the last part of the VIN: the short VIN */
            StartPos = (uint16)SWT_INDIV_LONG_VIN_LEN -
                       (uint16)SWT_INDIV_SHORT_VIN_LEN;
            break;

         case SWT_INDIV_TYPE_LONG_VIN:
                                    /* We have to check the complete long VIN */
            StartPos = 0;
            break;

         default:
            RetVal = Swt_RC_FGN_CHECK_FAILURE;
            break;
      }
   }

        /* The individualisation attribute of the FSC is compared to the VIN. */
   for( i = StartPos;
       (i < (uint16)SWT_INDIV_LONG_VIN_LEN) && (Swt_RC_OK == RetVal);
        i++ )
   {
      if( Fsc[IndivAttrPos + i - StartPos] != VIN[i] )
      {
         RetVal = Swt_RC_FGN_CHECK_FAILURE;
      }
   }

   return RetVal;
}






/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FSCCheckValidity                                    **
**                                                                            **
** DESCRIPTION    : Check the validity field of a given FSC. If one validity  **
**                  group of the field is valid, the whole field is valid.    **
**                                                                            **
** PRECONDITIONS  : 'Fsc' is a valid pointer (not checked)                    **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Fsc       : The pointer to the FSC array                  **
**                  FscLength : The length of the FSC array                   **
**                                                                            **
** RETURN         : Swt_RC_OK, if the validity field is valid               **
**                  Swt_RC_VALIDITY_CHECK_FAILURE, otherwise                **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCCheckValidity
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength
)
{
   SwtRC_t   RetVal;                    /* the return value of the function */
                 /* the position in the VIN where the comparison should start */
   uint16 i;                                             /* loop counter */
   uint16 ValidityPos;        /* the position of the indiv. type in the FSC  */
   uint16 GroupLength;
   boolean ValidGlobal;
   SwtRC_t GroupIsValid;

   ValidGlobal = FALSE;

                                            /* Get the individualisation type */
   RetVal = Swt_GetPos( Fsc,
                          FscLength,
                          Swt_FSC_VALIDITY,
                          &ValidityPos );

   if( Swt_RC_OK == RetVal )
   {
      i = 0;

      /* Each validity field consists of validity groups. We check those      */
      /* groups until we find a validity group whose first element is a 0.    */
      /* This is the end marker for the validity field.                       */
      while( Fsc[ValidityPos + i] != 0x00 )
      {
         /* Check a single validity group and store its length in             */
         /* 'GroupLength'.                                                    */
         GroupIsValid = Swt_CheckValidityGroup( &Fsc[ValidityPos + i],
                                                  &GroupLength);

         if( Swt_RC_OK == GroupIsValid )
         {
            /* If only one validity group is valid, the whole validity field  */
            /* is valid.                                                      */
            ValidGlobal = TRUE;
         }

                               /* We can now skip the checked validity group. */
         i += GroupLength;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      if( FALSE == ValidGlobal )
      {
         RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
      }
   }

   return RetVal;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FSCCheckFSCSID                                      **
**                                                                            **
** DESCRIPTION    : Check the FSCSID field of a given FSC: Compare the FSCSID **
**                  in the FSC with the given reference value.                **
**                                                                            **
** PRECONDITIONS  : 'Fsc' is a valid pointer (not checked)                    **
**                  'FscSId' is a valid pointer (not checked)                 **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Fsc       : The pointer to the FSC array                  **
**                  FscLength : The length of the FSC array                   **
**                  FscsId    : The pointer to the FSCSId to compare with     **
**                                                                            **
** RETURN         : Swt_RC_OK, if the FSCS field is equal to the given      **
**                               reference value                              **
**                  Swt_RC_WRONG_FSCS_ID_IN_FSC, otherwise                  **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCCheckFSCSID
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) FscsId
)
{
   SwtRC_t   RetVal;                    /* the return value of the function */

   uint16 FscsIdPos;           /* the position of the FSCSID type in the FSC  */


                                                       /* Get the FSCSID type */
   RetVal = Swt_GetPos( Fsc,
                          FscLength,
                          Swt_FSC_FSCSID,
                          &FscsIdPos );

   if( Swt_RC_OK == RetVal )
   {
      /* Compare the two ids                                                  */
      if( Swt_RC_EQUAL ==
          Swt_CommonCompare(FscsId,
                              &Fsc[FscsIdPos],
                              (uint32)SWT_FSCSID_LEN) )
      {
         RetVal = Swt_RC_OK;
      }
      else
      {
         RetVal =  Swt_RC_WRONG_FSCS_ID_IN_FSC;
      }
   }
   else
   {
      RetVal =  Swt_RC_WRONG_FSCS_ID_IN_FSC;
   }

   return RetVal;
}






/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FSCCheckFreshness                                   **
**                                                                            **
** DESCRIPTION    : Check that the creation date of the given FSC is within   **
**                  the given validity period, i.e. the following holds:      **
**                  StartDate < CreationDate < EndDate                        **
**                                                                            **
** PRECONDITIONS  : 'Fsc' is a valid pointer (not checked)                    **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Fsc       : The pointer to the FSC array                  **
**                  FscLength : The length of the FSC array                   **
**                  StartDate : Start date of the validity period in minutes  **
**                              since 2000/01/01                              **
**                  EndDate   : End date of the validity period in minutes    **
**                              since 2000/01/01                              **
**                                                                            **
** RETURN         : Swt_RC_OK, if the creation date is within the validity  **
**                               period                                       **
**                  Swt_RC_FSC_REJECTED, otherwise                          **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCCheckFreshness
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength,
   uint32                               StartDate,
   uint32                               EndDate
)
{
   SwtRC_t   RetVal;                    /* the return value of the function */

   uint16 datePos;                           /* The start pos of a date array */

   /* Get the date from the current FSC.                                      */
   RetVal = Swt_GetPos(Fsc, FscLength, Swt_FSC_DATE, &datePos);

   if( Swt_RC_OK == RetVal )
   {
      /* QA-C claims violation of MISRA rule 33: "Right hand operand of       */
      /* '&&' has side effects." But the call to Swt_DateGet does not       */
      /* have side effects.                                                   */
      if( (StartDate > Swt_DateGet(&Fsc[datePos], Swt_DATE_FSC_TIME)) ||
          (EndDate < Swt_DateGet(&Fsc[datePos], Swt_DATE_FSC_TIME)) )
      {
         RetVal = Swt_RC_FSC_REJECTED;
      }
   }

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FSCExtractDiffieKey                                 **
**                                                                            **
** DESCRIPTION    : Extract a Diffie-Hellman public key from the additional   **
**                  fields of a given FSC_Enabler.                            **
**                                                                            **
** PRECONDITIONS  : 'Fsc' is a valid pointer (not checked)                    **
**                  'DiffieKeyStartPtr' is a valid pointer (not checked)      **
**                                                                            **
** POSTCONDITIONS : '*DiffieKeyStartPtr' contains a pointer to the start of   **
**                  an array which contains the Diffie-Hellman public key.    **
**                                                                            **
** PARAMETERS     : Fsc       : The pointer to the FSC array                  **
**                  FscLength : The length of the FSC array                   **
**                  DiffieKeyStartPtr : The pointer to a pointer variable     **
**                                      where the start of the key will be    **
**                                      stored                                **
**                                                                            **
** RETURN         : Swt_RC_OK, if the key could be extracted                **
**                  Swt_RC_INVALID_FSC, if the FSC contains invalid content **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FSCExtractDiffieKey
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                        Fsc,
   uint16                                                      FscLength,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR)DiffieKeyStartPtr
)
{
   SwtRC_t   RetVal;                    /* the return value of the function */
   uint16      Pos;                        /* The current position in the FSC */

   /* Get the start position of the additional fields in this FSC.            */
   RetVal = Swt_GetPos(Fsc, FscLength, Swt_FSC_ADDITIONAL, &Pos);

   if( Swt_RC_OK == RetVal )
   {
      /* The length of the type field must be 1 byte                          */
      if( (uint8)1 != (Fsc[Pos] & (uint8)0x7F) )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      /* We skip the type length field.                                       */
      Pos++;

      /* The type of this additional field must be "Diffie-Hellman public key"*/
      if( (uint8)SWT_ADD_FIELD_TYPE_DIFFIE != Fsc[Pos] )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      /* We skip the type of the additional field.                            */
      Pos++;

      /* We skip the length field.                                            */
      Pos++;

      /* The start of the public key array is stored.                         */
      *DiffieKeyStartPtr = &Fsc[Pos];
   }

   return RetVal;
}







/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetPos                                              **
**                                                                            **
** DESCRIPTION    : Returns the position of the selected FSC element in the   **
**                  given FSC. Or, if 'Element' is 'Swt_FSC_END', simply    **
**                  parses the complete FSC without returning a position.     **
**                                                                            **
** PRECONDITIONS  : 'Fsc'    is a valid pointer to an FSC (not checked)       **
**                  'Element' is an element given in the FSC (checked)        **
**                  'PosPtr' is a valid pointer. This is only needed if       **
**                           'Element' is not equal to 'Swt_FSC_END'        **
**                                                                            **
** POSTCONDITIONS : If 'Element' is not equal to 'Swt_FSC_END', '*PosPtr'   **
**                  contains the pos of the selected element. Otherwise,      **
**                  '*PosPtr' is not modified.                                **
**                                                                            **
** PARAMETERS     : Fsc       : The pointer to the FSC array                  **
**                  FscLength : The length of the FSC array                   **
**                  Element   : The name of the element whose position shall  **
**                              be returned                                   **
**                  PosPtr    : The memory location to store the position in  **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a given parameter is not valid     **
** RETURN         : Swt_RC_INVALID_FSC, if the FSC contains invalid content **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_GetPos
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   Fsc,
   const uint16                           FscLength,
   const Swt_FSCElement                 Element,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)    PosPtr

)
{
   SwtRC_t    RetVal;                   /* the return value of the function */
   uint16       Position;              /* the current position within the FSC */
   uint16       Length;                  /* the length of an entry in the FSC */
   uint8        RequesterType;        /* the requester type stored in the FSC */
   uint8        IndivType;  /* the type of the indiv. attr. stored in the FSC */


   /* Initialise local variables                                              */
   RetVal        = Swt_RC_OK;
   RequesterType = 0;
   IndivType     = 0;

   /* Check parameters                                                        */
   if( (((uint16)SWT_FSC_MIN_LEN > FscLength)) ||
        ((uint16)SWT_FSC_MAX_LEN < FscLength) )
   {
      RetVal = Swt_RC_INVALID_FSC;
   }

   /* Check FSC content                                                       */
   Position = 0;

   /* Check version (1 byte)                                                  */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_VERSION == Element)
      {
         *PosPtr = Position;
      }

      if( (uint8)SWT_FSC_VERSION != Fsc[Position] )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
      else
      {
         Position += (uint16)SWT_VERSION_LEN;   /* move to the next element */
      }
   }

   /* Check SWID type (1 byte)                                                */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_SWIDTYPE == Element)
      {
         *PosPtr = Position;
      }

      if( (uint8)SWT_SWID_TYPE != Fsc[Position] )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
      else
      {
         Position += (uint16)SWT_SWID_TYPE_LEN; /* move to the next element */
      }
   }

   /* Check SWID (4 byte)                                                     */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_SWID == Element)
      {
         *PosPtr = Position;
      }

      RetVal = Swt_ParseSWID( &Fsc[Position] );

      if( Swt_RC_OK == RetVal )
      {
         Position += (uint16)SWT_SWID_LEN;      /* move to the next element */
      }
   }

   /* Check supplier number (8 byte)                                          */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_SUPPLIER == Element)
      {
         *PosPtr = Position;
      }

      RetVal = Swt_ParseSupplierNr( &Fsc[Position] );

      if( Swt_RC_OK == RetVal )
      {
         Position += (uint16)SWT_SUPPLIER_NUMBER_LEN;
      }
   }

   /* Check requester type (1 byte)                                           */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_REQUESTERTYPE == Element)
      {
         *PosPtr = Position;
      }

      if( ( ( ( (uint8)SWT_REQUESTER_TYPE_FACTORY   != Fsc[Position] )   &&
              ( (uint8)SWT_REQUESTER_TYPE_TRADER    != Fsc[Position] ) ) &&
              ( (uint8)SWT_REQUESTER_TYPE_MARKETING != Fsc[Position] ) ) &&
              ( (uint8)SWT_REQUESTER_TYPE_CUSTOMER  != Fsc[Position] ) )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
      else
      {
         RequesterType = Fsc[Position];               /* store requester type */
                                                  /* move to the next element */
         Position += (uint16)SWT_REQUESTER_TYPE_LEN;
      }
   }

   /* Check order number (8 byte)                                             */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_ORDERNUMBER == Element)
      {
         *PosPtr = Position;
      }

      RetVal = Swt_ParseOrderNr( &Fsc[Position] );

      if( Swt_RC_OK == RetVal )
      {
         Position += (uint16)SWT_ORDER_NUMBER_LEN;
      }
   }

   /* Check requester id (2-5 byte)                                           */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_REQUESTERID == Element)
      {
         *PosPtr = Position;
      }

      RetVal = Swt_ParseRequesterId( RequesterType,
                                       &Fsc[Position],
                                       &Length );

      if( Swt_RC_OK == RetVal )
      {
                                                  /* move to the next element */
            Position += Length;
      }
   }

   /* Check individualisation type (1 byte)                                   */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_INDIVTYPE == Element)
      {
         *PosPtr = Position;
      }

      if( ( ( (uint8)SWT_INDIV_TYPE_NO_VIN    != Fsc[Position] )   &&
            ( (uint8)SWT_INDIV_TYPE_SHORT_VIN != Fsc[Position] ) ) &&
            ( (uint8)SWT_INDIV_TYPE_LONG_VIN  != Fsc[Position] ) )

      {
         RetVal = Swt_RC_INVALID_FSC;
      }

      if( Swt_RC_OK == RetVal )
      {
         IndivType = Fsc[Position];           /* store individualisation type */
         Position += (uint16)SWT_INDIV_TYPE_LEN;
      }
   }

   /* Check individualisation attribute                                       */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_INDIVATTR == Element)
      {
         *PosPtr = Position;
      }

      RetVal = Swt_ParseIndivAttribute( &Fsc[Position], IndivType, &Length );

      if( Swt_RC_OK == RetVal )
      {
                                                  /* move to the next element */
         Position += Length;
      }
   }

   /* Check validity conditions                                               */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_VALIDITY == Element)
      {
         *PosPtr = Position;
      }

      RetVal = Swt_ParseValidityField( &Fsc[Position], &Length);

      if( Swt_RC_OK == RetVal )
      {
                                                  /* move to the next element */
         Position += Length;
      }
   }

   /* Check FSCS-ID (8 bytes)                                                 */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_FSCSID == Element)
      {
         *PosPtr = Position;
      }

      /* No check defined for FSCSIDs, so skip                                */

      Position += (uint16)SWT_FSCSID_LEN;       /* move to the next element */
   }

   /* Check date                                                              */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_DATE == Element)
      {
         *PosPtr = Position;
      }

      Length = Swt_ParseDate(&Fsc[Position]);

      if( 0 == Length )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
      else
      {
         Position += Length;           /* move to the next element */
      }
   }

   /* Check additional fields                                                 */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_ADDITIONAL == Element)
      {
         *PosPtr = Position;
      }

      RetVal = Swt_ParseAdditionalFields( &Fsc[Position], &Length);

      if( Swt_RC_OK == RetVal )
      {
                                                  /* move to the next element */
         Position += Length;
      }
   }

   /* Check actual length of the FSC                                          */
   if( Swt_RC_OK == RetVal )
   {
      if(Swt_FSC_SIGNATURE == Element)
      {
         *PosPtr = Position;
      }

      if( (Position + (uint16)SWT_SIGNATURE_LEN) != FscLength )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
   }

   return RetVal;
}










#define SWT_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseSWID                                           **
**                                                                            **
** DESCRIPTION    : Check that the SWID is well formed                        **
**                                                                            **
** PRECONDITIONS  : 'Swid' is a valid pointer to the SWID (not checked)       **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Swid : Pointer to the SWID array                          **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the SW ID is invalid             **
**                  Swt_RC_OK, if the given SW ID is valid                  **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ParseSWID
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId
)
{
   SwtRC_t RetVal;                      /* the return value of the function */

   /* Initialise return value                                                 */
   RetVal = Swt_RC_OK;

   /* Check application number not zero                                       */
   if( ( (uint8)0x00 == SwId[0]) && ( (uint8)0x00 == SwId[1]) )
   {
      RetVal = Swt_RC_INVALID_FSC;
   }

   /* No restrictions for the upgrade index                                   */

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseSupplierNr                                     **
**                                                                            **
** DESCRIPTION    : Check that the supplier number is well formed             **
**                                                                            **
** PRECONDITIONS  : 'SupplierNr' is a valid pointer (not checked)             **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : SupplierNr : Pointer to the start of the supplier number  **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the supplier number is invalid   **
**                  Swt_RC_OK, if the given supplier number is valid        **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ParseSupplierNr
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SupplierNr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint8     i;                                              /* loop variable */

   /* Initialise return value                                                 */
   RetVal = Swt_RC_OK;

   /* Check for each byte of the supplier number if it is a printable ASCII   */
   /* character.                                                              */
   for( i = 0;
       (i < (uint8)SWT_SUPPLIER_NUMBER_LEN) && ( Swt_RC_OK == RetVal );
        i++ )
   {
      if( FALSE == Swt_IsPrintableASCII( SupplierNr[i] ) )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
   }

   return RetVal;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseOrderNr                                        **
**                                                                            **
** DESCRIPTION    : Check that the order number is well formed                **
**                                                                            **
** PRECONDITIONS  : 'OrderNr' is a valid pointer (not checked)                **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : OrderNr : Pointer to the start of the order number        **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the order number is invalid      **
**                  Swt_RC_OK, if the given order number is valid           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ParseOrderNr
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) OrderNr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint8     i;                                              /* loop variable */

   /* Initialise return value                                                 */
   RetVal = Swt_RC_OK;

   /* Check for each byte of the order number if it is a printable ASCII      */
   /* character.                                                              */
   for( i = 0;
       (i < (uint8)SWT_ORDER_NUMBER_LEN) && ( Swt_RC_OK == RetVal );
        i++ )
   {
      if( FALSE == Swt_IsPrintableASCII( OrderNr[i] ) )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
   }

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseRequesterId                                    **
**                                                                            **
** DESCRIPTION    : Check that the requester id is well formed                **
**                                                                            **
** PRECONDITIONS  : 'RequesterType' is a supported id type (checked)          **
**                  'RequesterId' is valid pointer to the requester id        **
**                                 (not checked)                              **
**                  'LengthPtr' is a valid pointer (unchecked)                **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : RequesterType : The type of the requester id              **
**                  RequesterId   : The pointer to the requester id array     **
**                  LengthPtr : a pointer to an variable which will contain   **
**                              the length of the requester id field          **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the requester Id is invalid      **
**                  Swt_RC_OK, if the given requester id is valid           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t  Swt_ParseRequesterId
(
   uint8                                RequesterType,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) RequesterId,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint8_least i;                                            /* loop variable */
   uint32 number;                /* a number stored in the requester id field */


   /* Initialise return value                                                 */
   RetVal = Swt_RC_OK;

   switch( RequesterType )
   {
      case SWT_REQUESTER_TYPE_MARKETING:
         /* Check type marketing. The largest value allowed is 999999.        */

         number = Swt_GetBigEndianNumber( RequesterId,
                                            (uint8)SWT_REQ_MARKETING_ID_LEN );

         if( number > 999999UL )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }

         *LengthPtr = SWT_REQ_MARKETING_ID_LEN;
         break;

      case SWT_REQUESTER_TYPE_FACTORY:
         /* Check type factory. The largest value allowed is 9999.  */

         number = Swt_GetBigEndianNumber( RequesterId,
                                            (uint8)SWT_REQ_FACTORY_ID_LEN );

         if( number > 9999UL )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }

         *LengthPtr = (uint16)SWT_REQ_FACTORY_ID_LEN;
         break;

      case SWT_REQUESTER_TYPE_TRADER:
         /* Check type trader. Should be a printable ASCII.                   */

         i = 0;
         while( ((uint8_least)SWT_REQ_TRADER_ID_LEN > i) &&
                (Swt_RC_OK == RetVal) )
         {
            if( FALSE == Swt_IsPrintableASCII( RequesterId[i] ) )
            {
               RetVal = Swt_RC_INVALID_FSC;
            }
            i++;
         }

         *LengthPtr = (uint16)SWT_REQ_TRADER_ID_LEN;
         break;

      case SWT_REQUESTER_TYPE_CUSTOMER:
         /* Check type customer. Should be a printable ASCII.                 */

         i = 0;
         while( ((uint8_least)SWT_REQ_CUSTOMER_ID_LEN > i) &&
                (Swt_RC_OK == RetVal) )
         {
            if( FALSE == Swt_IsPrintableASCII( RequesterId[i] ) )
            {
               RetVal = Swt_RC_INVALID_FSC;
            }
            i++;
         }

         *LengthPtr = (uint16)SWT_REQ_CUSTOMER_ID_LEN;
         break;

      default:
         RetVal = Swt_RC_INVALID_FSC;
         break;
   }

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseIndivAttribute                                 **
**                                                                            **
** DESCRIPTION    : Check that the individualisation attribute is well formed **
**                                                                            **
** PRECONDITIONS  : 'IndivType' is a supported indiv type (checked)           **
**                  'IndivAttribute' is valid pointer to the indiv attribute  **
**                                   (not checked)                            **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : IndivType       : The type of the indiv attribute         **
**                  IndivAttribute  : The pointer to the indiv attribute      **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the indiv attribute              **
**                                            is invalid                      **
**                  Swt_RC_OK, if the given indiv attribute is valid        **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t  Swt_ParseIndivAttribute
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) IndivAttribute,
   const uint8                          IndivType,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint16 i;                                            /* loop variable */

   /* Initialise local variables                                              */
   RetVal = Swt_RC_OK;
   i = 0;


   switch(IndivType)
   {
      case SWT_INDIV_TYPE_NO_VIN:
         *LengthPtr = (uint16)SWT_INDIV_NO_VIN_LEN;
         break;

      case SWT_INDIV_TYPE_SHORT_VIN:
         *LengthPtr = (uint16)SWT_INDIV_SHORT_VIN_LEN;
         break;

      case SWT_INDIV_TYPE_LONG_VIN:
         *LengthPtr = (uint16)SWT_INDIV_LONG_VIN_LEN;
         break;

      default:
         RetVal = Swt_RC_INVALID_FSC;
         break;
   }

   /* Parse VIN                                                               */
   while
   (
      (*LengthPtr > i) && (Swt_RC_OK == RetVal)
   )
   {
      if( ( (uint8)0x20 > IndivAttribute[i]) ||
          ( (uint8)0x7E < IndivAttribute[i]) )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
      i++;
   }

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseValidityField                                  **
**                                                                            **
** DESCRIPTION    : Checks that the validity condition field is well formed   **
**                  and returns the length of the field.                      **
**                                                                            **
** PRECONDITIONS  : 'ValidityField' is a valid pointer to the validity        **
**                                    condition field (unchecked)             **
**                  'LengthPtr' is a valid pointer (unchecked)                **
**                                                                            **
** POSTCONDITIONS :  'LengthPtr' will contain the length of the validity      **
**                               condition field                              **
**                                                                            **
** PARAMETERS     : ValidityField : a pointer to the start of the field of    **
**                                  an FSC containing the validity conditions **
**                  LengthPtr : a pointer to an variable which will contain   **
**                              the length of the validity condition field    **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the validity condition field is  **
**                                        invalid                             **
**                  Swt_RC_OK, if the validity condition field is valid     **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ParseValidityField
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityField,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint16 GroupLength;           /* contains the length of one validity group */
   uint16 Pos;        /* the current position in the validity condition field */


                                                   /* Initialise return value */
   RetVal = Swt_RC_OK;

                                            /* We start at the first position */
   Pos = 0;

   /* Each validity field consists of validity groups. We parse those groups  */
   /* until we find a validity group whose first element is a 0. This is the  */
   /* end marker for the validity field. We also stop parsing if we encounter */
   /* an error.                                                               */
   while( ( ValidityField[Pos] != 0 ) && ( Swt_RC_OK == RetVal ) )
   {
      /* Parse a single validity group and store its length in 'GroupLength'. */
      RetVal = Swt_ParseValidityGroup( &ValidityField[Pos],
                                         &GroupLength,
                                         (uint16)SWT_VALIDITY_COND_MAX_LEN -
                                                 Pos);

                                /* We can now skip the parsed validity group. */
      Pos += GroupLength;

      if( Pos >= (uint16)SWT_VALIDITY_COND_MAX_LEN )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
   }

   *LengthPtr = Pos + (uint16)1;

   return RetVal;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseValidityGroup                                  **
**                                                                            **
** DESCRIPTION    : Checks that the validity group is well formed  and        **
**                  returns the length of the group.                          **
**                                                                            **
** PRECONDITIONS  : 'ValidityGroup' is a valid pointer to the validity        **
**                                  group (unchecked)                         **
**                  'LengthPtr' is a valid pointer (unchecked)                **
**                                                                            **
** POSTCONDITIONS :  'LengthPtr' will contain the length of the validity      **
**                               group                                        **
**                                                                            **
** PARAMETERS     : ValidityGroup : a pointer to the start of the             **
**                                  validity group                            **
**                  LengthPtr : a pointer to an variable which will contain   **
**                              the length of the validity group              **
**                  MaxLength: the maximal length of the field; if this value **
**                             is passed during parsing, the parsing is       **
**                             stopped                                        **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the validity group is invalid    **
**                  Swt_RC_OK, if the validity group is valid               **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ParseValidityGroup
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityGroup,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr,
   const uint16                         MaxLength
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint16 ConditionLength;   /* contains the length of one validity condition */
   uint16 Pos;                  /* the current position in the validity group */


                                                   /* Initialise return value */
   RetVal = Swt_RC_OK;

                                            /* We start at the first position */
   Pos = 0;

   /* Each validity group consists of validity conditions. We parse those     */
   /* groups until we find a validity condition whose first element is a 0.   */
   /* This is the end marker for the validity group. We also stop parsing if  */
   /* we encounter an error.                                                  */
   while( ( ValidityGroup[Pos] != 0 ) && ( Swt_RC_OK == RetVal ) )
   {
      /* Parse a single validity condition and store its length in            */
      /* 'ConditionLength'.                                                   */
      RetVal = Swt_ParseValidityCond(&ValidityGroup[Pos],&ConditionLength);

                            /* We can now skip the parsed validity condition. */
      Pos += ConditionLength;

      if( Pos >= MaxLength )
      {
         RetVal = Swt_RC_INVALID_FSC;
      }
   }

   *LengthPtr = Pos + (uint16)1;

   return RetVal;
}








/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseValidityCond                                   **
**                                                                            **
** DESCRIPTION    : Checks that the validity condition is well formed and     **
**                  returns the length of the condition.                      **
**                                                                            **
** PRECONDITIONS  : 'ValidityCond' is a valid pointer to the validity         **
**                                  condition (unchecked)                     **
**                  'LengthPtr' is a valid pointer (unchecked)                **
**                                                                            **
** POSTCONDITIONS :  'LengthPtr' will contain the length of the validity      **
**                               condition                                    **
**                                                                            **
** PARAMETERS     : ValidityCond : a pointer to the start of the              **
**                                  validity condition                        **
**                  LengthPtr : a pointer to an variable which will contain   **
**                              the length of the validity condition          **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the validity condition is invalid**
**                  Swt_RC_OK, if the validity condition is valid           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ParseValidityCond
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityCond,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint16 Length;                     /* The length of the validity condition */

/* Several temporary variables are only used when certain types of validity   */
/* conditions are enabled.                                                    */

#if ( SWT_USE_VAL_COND_DATE == SWT_CFG_ON || \
      SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON  )
   uint32 TempLength;
#endif

#if ( SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON || \
      SWT_USE_VAL_COND_KM == SWT_CFG_ON || \
      SWT_USE_VAL_COND_OP_TIME == SWT_CFG_ON )
   uint32 TempValue1;
#endif

#if ( SWT_USE_VAL_COND_KM == SWT_CFG_ON || \
      SWT_USE_VAL_COND_OP_TIME == SWT_CFG_ON )
   uint32 TempValue2;
#endif

   /* Initialise return value                                                 */
   RetVal = Swt_RC_OK;

               /* The second element of the validity condition is its length. */
   Length = (uint16)ValidityCond[1];


   /* The first element of the validity condition is its type. Each type has  */
   /* a different syntax. We check whether the syntax is valid.               */
   switch( ValidityCond[0] )
   {
#if ( SWT_USE_VAL_COND_UNLIMITED == SWT_CFG_ON )
      case SWT_VALIDITY_COND_UNLIMITED:
                             /* The condition "unlimited" must have length 0. */
         if( Length != 0 )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }
         break;
#endif

#if ( SWT_USE_VAL_COND_DATE == SWT_CFG_ON )
      case SWT_VALIDITY_COND_DATE:
                     /* The condition "expiration date" must be a valid date. */
         TempLength = Swt_ParseDate(&ValidityCond[2]);
         if ( TempLength != Length )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }
         break;
#endif

#if ( SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON )
      case SWT_VALIDITY_COND_PERIOD:
         /* The condition "period" The condition must be a valid date plus    */
         /* two bytes.                                                        */
         TempLength = Swt_ParseDate(&ValidityCond[2]);
         if ( (TempLength + (uint16)2U) != Length )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }

                           /* The period must not be larger than 50,000 days. */
         TempValue1 = Swt_GetBigEndianNumber( &ValidityCond[2 + TempLength],
                                                (uint8)2U );

         if(TempValue1 > 50000UL)
         {
            RetVal = Swt_RC_INVALID_FSC;
         }
         break;
#endif

#if ( SWT_USE_VAL_COND_KM == SWT_CFG_ON )
      case SWT_VALIDITY_COND_KM:
                /* The condition "kilometres travelled" must be 8 bytes long. */
         if( Length != 8 )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }

         /* Both the minimal and the maximal value must not exceed 500,000.   */
         /* Also, the minimal value must not be larger than the maximal value.*/
         TempValue1 = Swt_GetBigEndianNumber( &ValidityCond[2], (uint8)4U );
         TempValue2 = Swt_GetBigEndianNumber( &ValidityCond[6], (uint8)4U );

         if( ( ( TempValue1 > 500000UL )   ||
               ( TempValue2 > 500000UL ) ) ||
             ( TempValue1 > TempValue2 ) )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }
         break;
#endif

#if ( SWT_USE_VAL_COND_OP_TIME == SWT_CFG_ON )
      case SWT_VALIDITY_COND_OP_TIME:
                      /* The condition "operation time" must be 8 bytes long. */
         if( Length != 8 )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }

         /* Both the minimal and the maximal value must not exceed 500,000.   */
         /* Also, the minimal value must not be larger than the maximal value.*/
         TempValue1 = Swt_GetBigEndianNumber( &ValidityCond[2], (uint8)4U );
         TempValue2 = Swt_GetBigEndianNumber( &ValidityCond[6], (uint8)4U );

         if( ( ( TempValue1 > 500000UL )   ||
               ( TempValue2 > 500000UL ) ) ||
             ( TempValue1 > TempValue2 ) )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }
         break;
#endif

#if ( SWT_USE_VAL_COND_DAYS == SWT_CFG_ON )
      case SWT_VALIDITY_COND_DAYS:
                                /* The condition "days" must be 2 bytes long. */
         if( Length != 2 )
         {
            RetVal = Swt_RC_INVALID_FSC;
         }
         break;
#endif

      default:
                                                /* Is the type at least 0x80? */
         if( ValidityCond[0] > (uint8)0x7F)
         {
               /* This is an AppGB. It can only be parsed by the application. */
            RetVal = Appl_SwtParseAppCond(ValidityCond);
         }
         else
         {
                                   /* This is an AllgGB which we do not know. */
            RetVal = Swt_RC_INVALID_FSC;
         }
         break;
   }

   /* The total length of the condition is the length given in its second     */
   /* element plus two bytes for the first two fields.                        */
   *LengthPtr = Length + (uint16)2;

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseDate                                           **
**                                                                            **
** DESCRIPTION    : Parse the date field of an FSC and return the length of   **
**                  that field. If this is not a valid date field, return 0.  **
**                                                                            **
** PRECONDITIONS  : 'Date' is a valid pointer (not checked)                   **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Date : A pointer to the start of a date field of an FSC   **
**                                                                            **
** RETURN         : the length of the date field, if it is valid              **
**                  0, if this is not a valid date field                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC uint16 Swt_ParseDate
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Date
)
{
   uint32    Minutes;
   uint16    DateLength;


   Minutes = Swt_DateGet(Date, Swt_DATE_FSC_TIME);

   if(0 == Minutes)
   {
      DateLength = 0;
   }
   else
   {
      if('Z' == Date[SWT_DATE_SEPARATOR_POS])
      {
         DateLength = (uint16)SWT_SHORT_DATE_LEN;
      }
      else
      {
         DateLength = (uint16)SWT_LONG_DATE_LEN;
      }
   }

   return DateLength;
}





/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ParseAdditionalFields                               **
**                                                                            **
** DESCRIPTION    : Checks that the given additional fields are well formed   **
**                  and returns their length.                                 **
**                                                                            **
** PRECONDITIONS  : 'AdditionalFields' is a valid pointer (not checked)       **
**                  'LengthPtr' is a valid pointer (not checked)              **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : AdditionalField : A pointer to the start of an array      **
**                                    which contains the additional fields    **
**                  LengthPtr : a pointer to an variable which will contain   **
**                              the length of the additional fields           **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the additional fields are invalid**
**                  Swt_RC_OK, if the additional fields are valid           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ParseAdditionalFields
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) AdditionalFields,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
)
{
   uint16 Pos;
   uint16 Length;


   Pos = 0;

   while( ( AdditionalFields[Pos] != 0 ) &&
          ( Pos < (uint16)SWT_ADD_FIELD_MAX_LEN ) )
   {
      /* The length of the type field.                                        */
      Length = (uint16)(AdditionalFields[Pos] & (uint8)0x7F);

      /* We skip the type length field.                                       */
      Pos++;

      /* We skip the type of the additional field.                            */
      Pos += Length;

      /* The length of the additional field.                                  */
      Length = (uint16)AdditionalFields[Pos];

      /* We skip the length field.                                            */
      Pos++;

      /* We skip the additional field.                                        */
      Pos += Length;
   }

   *LengthPtr = Pos + (uint16)1;

   if( Pos < (uint16)SWT_ADD_FIELD_MAX_LEN )
   {
      return Swt_RC_OK;
   }
   else
   {
      return Swt_RC_INVALID_FSC;
   }
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CheckValidityGroup                                  **
**                                                                            **
** DESCRIPTION    : Checks whether the validity group is valid and returns    **
**                  its length.                                               **
**                                                                            **
** PRECONDITIONS  : 'ValidityGroup' is a valid pointer to the validity        **
**                                  group (unchecked)                         **
**                  'LengthPtr' is a valid pointer (unchecked)                **
**                                                                            **
** POSTCONDITIONS : 'LengthPtr' will contain the length of the validity       **
**                              group                                         **
**                                                                            **
** PARAMETERS     : ValidityGroup : a pointer to the start of the             **
**                                  validity group                            **
**                  LengthPtr : a pointer to an variable which will contain   **
**                              the length of the validity group              **
**                                                                            **
** RETURN         : Swt_RC_VALIDITY_CHECK_FAILURE, if the validity group    **
**                                                   is invalid               **
**                  Swt_RC_OK, if the validity group is valid               **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_CheckValidityGroup
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityGroup,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint16 ConditionLength;   /* contains the length of one validity condition */
   uint16 Pos;                  /* the current position in the validity group */
   SwtRC_t CondIsValid;         /* Is the current validity condition valid? */
   boolean ContainsGeneralCond;   /* Does this group contain a general cond.? */
   boolean CondIsGeneral;        /* Is the current condition a general cond.? */
                                                   /* Initialise return value */
   RetVal = Swt_RC_OK;

         /* We have not yet found a general condition in this validity group. */
   ContainsGeneralCond = FALSE;

                     /* We start at the first position of the validity group. */
   Pos = 0;

   /* Each validity group consists of validity conditions. We check those     */
   /* conditions until we find a validity condition whose first element is a  */
   /* 0. This is the end marker for the validity group. We also stop checking */
   /* if we encounter an error.                                               */
   while( ValidityGroup[Pos] != 0 )
   {
      /* Check a single validity condition                                    */
      CondIsValid = Swt_CheckValidityCond( &ValidityGroup[Pos],
                                             &CondIsGeneral,
                                             &ConditionLength);

      if( Swt_RC_OK != CondIsValid )
      {
         /* The current validity condition is invalid. This means that the    */
         /* whole group is invalid.                                           */
         RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
      }

      if( TRUE == CondIsGeneral )
      {
                                        /* We have found a general condition. */
         ContainsGeneralCond = TRUE;
      }

                           /* We can now skip the checked validity condition. */
      Pos += ConditionLength;
   }

   if( FALSE == ContainsGeneralCond )
   {
      /* The validity group can only be valid if it contains at least one     */
      /* general condition.                                                   */
      RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
   }

   /* We again go through the complete validity group. This time we call for  */
   /* each application condition a platform specific function which tells the */
   /* application belonging to that condition about the state (valid or       */
   /* invalid) of the validity group the application condition belongs to.    */
   Pos = 0;

   while( ValidityGroup[Pos] != 0 )
   {
                     /* Tell the application about the validity of the group. */
      ConditionLength = Swt_TellAppCond( &ValidityGroup[Pos],
                                           RetVal );

                                   /* We can now skip the validity condition. */
      Pos += ConditionLength;
   }

   *LengthPtr = Pos + (uint16)1;

   return RetVal;
}







/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CheckValidityCond                                   **
**                                                                            **
** DESCRIPTION    : Checks the given validity condition, returns whether it   **
**                  is a general condition, and returns the length of the     **
**                  condition.                                                **
**                                                                            **
** PRECONDITIONS  : 'ValidityCond' is a valid pointer to the validity         **
**                                  condition (unchecked)                     **
**                  'LengthPtr' is a valid pointer (unchecked)                **
**                                                                            **
** POSTCONDITIONS :  'LengthPtr' will contain the length of the validity      **
**                               condition                                    **
**                                                                            **
** PARAMETERS     : ValidityCond : a pointer to the start of the              **
**                                  validity condition                        **
**                  LengthPtr : a pointer to an variable which will contain   **
**                              the length of the validity condition          **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the validity condition is invalid**
**                  Swt_RC_OK, if the validity condition is valid           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_CheckValidityCond
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityCond,
   CONSTP2VAR(boolean,AUTOMATIC,SC_FAR) CondIsGeneralPtr,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  LengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint16 Length;                     /* The length of the validity condition */

/* Several temporary variables are only used when certain types of validity   */
/* conditions are enabled.                                                    */

#if ( SWT_USE_VAL_COND_DATE == SWT_CFG_ON || \
      SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON || \
      SWT_USE_VAL_COND_KM == SWT_CFG_ON || \
      SWT_USE_VAL_COND_OP_TIME == SWT_CFG_ON )
   uint32 EndValue;
   uint32 SGValue;
#endif

#if ( SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON || \
      SWT_USE_VAL_COND_KM == SWT_CFG_ON || \
      SWT_USE_VAL_COND_OP_TIME == SWT_CFG_ON )
   uint32 StartValue;
#endif

#if ( SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON )
   uint32 Days;
#endif


   RetVal = Swt_RC_OK;

              /* We assume that this is a general validity condition for now. */
   *CondIsGeneralPtr = TRUE;

               /* The second element of the validity condition is its length. */
   Length = (uint16)ValidityCond[1];

   /* The first element of the validity condition is its type. Each type      */
   /* needs to be checked differently.                                        */
   switch( ValidityCond[0] )
   {
#if ( SWT_USE_VAL_COND_UNLIMITED == SWT_CFG_ON )
      case SWT_VALIDITY_COND_UNLIMITED:
                       /* This is an unlimited condition. It is always valid. */
         break;
#endif

#if ( SWT_USE_VAL_COND_DATE == SWT_CFG_ON )
      case SWT_VALIDITY_COND_DATE:
                                              /* This condition is: end date. */

            /* We get the end date in minutes since 2000/01/01 from the cond. */
         EndValue = Swt_DateGet(&ValidityCond[2], Swt_DATE_FSC_TIME);

                              /* We get the current date from the controller. */
         SGValue  = Appl_SwtGetMinutes();

         if( EndValue < SGValue )
         {
            /* The current date is later than the end date. This condition    */
            /* is no longer valid.                                            */
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
         break;
#endif

#if ( SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON )
      case SWT_VALIDITY_COND_PERIOD:
                                           /* This condition is: time period. */

               /* We get the start of the period in minutes since 2000/01/01. */
         StartValue = Swt_DateGet(&ValidityCond[2], Swt_DATE_FSC_TIME);

                                  /* We get the length of the period in days. */
         Days = Swt_GetBigEndianNumber(&ValidityCond[Length], (uint8)2);

         /* We compute the end date of the period from the start date and its */
         /* length.                                                           */
         EndValue = StartValue + (Days * (uint32)1440);

                              /* We get the current date from the controller. */
         SGValue  = Appl_SwtGetMinutes();

         if( ( StartValue > SGValue ) || ( EndValue < SGValue ) )
         {
            /* The start date of the period has not been reached or the end   */
            /* date has been passed. This condition is not valid.             */
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }

         break;
#endif

#if ( SWT_USE_VAL_COND_KM == SWT_CFG_ON )
      case SWT_VALIDITY_COND_KM:
                                  /* This condition is: kilometers travelled. */

               /* We get the minimum kilometers travelled from the condition. */
         StartValue = Swt_GetBigEndianNumber(&ValidityCond[2], (uint8)4);

               /* We get the maximum kilometers travelled from the condition. */
         EndValue = Swt_GetBigEndianNumber(&ValidityCond[6], (uint8)4);

               /* We get the actual kilometers travelled from the controller. */
         SGValue = Appl_SwtGetKm();

         if( ( StartValue > SGValue ) || ( EndValue < SGValue ) )
         {
                                               /* The condition is not valid. */
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
         break;
#endif

#if ( SWT_USE_VAL_COND_OP_TIME == SWT_CFG_ON )
      case SWT_VALIDITY_COND_OP_TIME:
                                       /* This condition is: operating hours. */

                       /* Get the minimum operation hours from the condition. */
         StartValue = Swt_GetBigEndianNumber(&ValidityCond[2], (uint8)4);

                       /* Get the maximum operation hours from the condition. */
         EndValue = Swt_GetBigEndianNumber(&ValidityCond[6], (uint8)4);

                      /* Get the actual operationg hours from the controller. */
         SGValue = Appl_SwtGetOperatingHours();

         if( ( StartValue > SGValue ) || ( EndValue < SGValue ) )
         {
                                               /* The condition is not valid. */
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
          break;
#endif

#if ( SWT_USE_VAL_COND_DAYS == SWT_CFG_ON )
      case SWT_VALIDITY_COND_DAYS:
         break;
#endif

      default:
                                                /* Is the type at least 0x80? */
         if( ValidityCond[0] > (uint8)0x7F)
         {
            /* This is an application condition. So, it is not a general      */
            /* condition.                                                     */
            *CondIsGeneralPtr = FALSE;
         }
         else
         {
            /* This is a general condition which we do not know. Because of   */
            /* this, it is invalid.                                           */
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
         break;
   }

   /* The total length of the condition is the length given in its second     */
   /* element plus two bytes for the first two fields.                        */
   *LengthPtr = Length + (uint16)2;

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_TellAppCond                                         **
**                                                                            **
** DESCRIPTION    : Checks that the validity condition is well formed and     **
**                  returns the length of the condition.                      **
**                                                                            **
** PRECONDITIONS  : 'ValidityCond' is a valid pointer to the validity         **
**                                  condition (unchecked)                     **
**                  'LengthPtr' is a valid pointer (unchecked)                **
**                                                                            **
** POSTCONDITIONS :  'LengthPtr' will contain the length of the validity      **
**                               condition                                    **
**                                                                            **
** PARAMETERS     : ValidityCond : a pointer to the start of the              **
**                                  validity condition                        **
**                  LengthPtr : a pointer to an variable which will contain   **
**                              the length of the validity condition          **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the validity condition is invalid**
**                  Swt_RC_OK, if the validity condition is valid           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC uint16 Swt_TellAppCond
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) ValidityCond,
   const SwtRC_t                      GroupIsValid
)
{
   if( ValidityCond[0] > (uint8)0x7F )
   {
      Appl_SwtTellAppCond(ValidityCond,GroupIsValid);
   }

   /* The total length of the condition is the length given in its second     */
   /* element plus two bytes for the first two fields.                        */
   return (uint16)ValidityCond[1] + (uint16)2;
}











/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_IsPrintableASCII                                    **
**                                                                            **
** DESCRIPTION    : Checks that the given symbol is printable ASCII.          **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : symbol: an 8-bit variable which should be checked         **
**                                                                            **
** RETURN         : TRUE, if the symbol is printable ASCII                    **
**                  FALSE, otherwise                                          **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC boolean Swt_IsPrintableASCII
(
   const uint8 symbol
)
{
   if ( ( symbol < (uint8)0x20) || ( symbol > (uint8)0x7E ) )
   {
      return FALSE;
   }
   else
   {
      return TRUE;
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetBigEndianNumber                                  **
**                                                                            **
** DESCRIPTION    : Compute a big endian number from a byte array.            **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : NumberArray : A pointer to the start of an array          **
**                                which contains a big endian number          **
**                  NumberOfBytes: The amount of bytes of the array which     **
**                                 should be used                             **
**                                                                            **
** RETURN         : the number stored in the array                            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC uint32 Swt_GetBigEndianNumber
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) NumberArray,
   const uint8                          NumberOfBytes
)
{
   uint32 number;
   uint8  i;

   number = 0;

   for( i = 0; i < NumberOfBytes; i++ )
   {
      number *= (uint32)0x100;
      number += (uint32)NumberArray[i];
   }

   return number;
}





#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
