/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Full.c                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for SWT Full handler services.                    **
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
 * V2.0.0    : 04.04.2007, mg   : made different signature lengths for FSCs and
 *                                certificates possible
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Full.h"                  /* declarations of SWT Full services */
#include "Appl_Swt.h"            /*  platform specific services */
#include "Swt_SWData.h"          /* declarations of services to get SW data */
#include "Swt_Common.h"            /* declarations of Swt common services */
#include "Swt_Certificate.h"        /* declarations of certificate services */
#include "Swt_Nvm.h"                /* declarations for nvm usage */

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
**                      Global Constants                                      **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
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

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_StoreCert                                           **
**                                                                            **
** DESCRIPTION    : Stores the given Certificate into the Swt handler data. **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS : The certificate is stored in the context of the handler.  **
**                                                                            **
** PARAMETERS     : SGID       : The ID of the controller                     **
**                  SwId       : The SWID of the corresponding SW             **
**                  CertType   : The type of the given certificate:           **
**                               0x01 - SigS certificate                      **
**                               0x02 - FSCS certificate                      **
**                  CertLength : The length of the certificate                **
**                  Cert       : A pointer to the start of the certificate    **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a parameter is invalid             **
**                  Swt_RC_NO_FREE_SPACE, if the certificate cannot be      **
**                      stored                                                **
**                  Swt_RC_SW_NOT_EXISTENT, if the given SWID is not stored **
**                      in the handler or if the upgrade index of the FSC     **
**                      SWID is too old                                       **
**                  Swt_RC_MISSING_SG_DATA, if there is no controller with  **
**                       the given SGID                                       **
**                  Swt_RC_FLASH_WRITE_ERROR, if the certificate could not  **
**                       be stored persistently                               **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_StoreCert
(
   const uint8                            SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   SwId,
   const uint8                            CertType,
   const uint32                           CertLength,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   Cert
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint8 i;                                                  /* loop variable */
   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;

   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */
   uint16 LengthOfReceivedCert;       /* The length of the stored certificate */
                      /* An array containing the certificate data for this SG */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) CertData;
   uint8 NrOfCerts ;                /* The amount of certificates for this SG */

   /* Initialise local variables                                              */
   RetVal = Swt_RC_OK;
   NrOfSWIDs = 0;
   CertData = 0;
   SWData = 0;
   NrOfCerts = 0;

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   /* Check the given pointers                                                */
   if( (0 == Cert) || (0 == SwId) )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_STORECERT_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   /* Check the given certificate type                                        */
   if((SWT_CERT_TYPE_SIGS != CertType) && (SWT_CERT_TYPE_FSCS != CertType))
   {
      RetVal = Swt_RC_BAD_PARAM;
   }

   /* Check the length of the given certificate                               */
   if( Swt_RC_OK == RetVal )
   {
      (void)Swt_CertGetLength(Cert, &LengthOfReceivedCert);

      if( CertLength != (uint32)LengthOfReceivedCert )
      {
         RetVal = Swt_RC_BAD_PARAM;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      /* Get the SW data for this SG.                                         */
      SWData = Swt_GetSWData( SGID, &NrOfSWIDs );

      /* Get the certificate data for this SG.                                */
      CertData = Swt_GetCertData(SGID,&NrOfCerts);

      if( 0 == SWData )
      {
         RetVal = Swt_RC_MISSING_SG_DATA;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      /* Check if we have SWIDs stored in the SG                              */
      if( 0 == NrOfSWIDs )
      {
         RetVal = Swt_RC_SW_NOT_EXISTENT;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      /* Check certificate length                                             */
      if( (uint32)SWT_CERT_MAX_LEN < CertLength )
      {
         RetVal = Swt_RC_NO_FREE_SPACE;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      /* handle SigS certificate                                              */
      if( SWT_CERT_TYPE_SIGS == (Swt_CertType)CertType )
      {
         /* Get the software signature data variable.                         */
         SWSigData = Swt_GetSWSigData(SGID);

         /* Import the certificate                                            */
         (void)Swt_CommonCopy( SWSigData->Cert, Cert, CertLength );

         /* Set certifcate status                                             */
         SWSigData->CertState = Swt_STATE_CERT_IMPORTED;

		 /* Following code is commented out, as software signature status should
		  * not be affected by the (unused) SigS certificate. */
         ///* Set signature status, if necessary                                */
         //if( Swt_STATE_SWSIG_ACCEPTED == SWSigData->SigState )
         //{
         //   SWSigData->SigState = Swt_STATE_SWSIG_IMPORTED;
         //}
         //else
         //{
         //   /* do nothing */
         //   ;
         //}

                                       /* write block into persistent storage */
         RetVal = Appl_SwtWriteBlock( (uint16)SWT_SWSIG_DATA );
      }
      else if( SWT_CERT_TYPE_FSCS == (Swt_CertType)CertType  )
      {
         /* Handle the special SWID 0000, i.e. replace all certificates       */
         if((((0==SwId[0]) && (0==SwId[1])) && (0==SwId[2])) && (0==SwId[3]))
         {
            for( i = 0; i < NrOfCerts; i++ )
            {
               /* Import the certificate for every SwId                       */
               (void)Swt_CommonCopy( CertData[i].Cert, Cert, CertLength );

               /* Set certificate status                                      */
               CertData[i].CertState = Swt_STATE_CERT_IMPORTED;

               /* Set signature status, if necessary                          */
               if( Swt_STATE_FSC_ACCEPTED == SWData[i].FscState )
               {
                  SWData[i].FscState = Swt_STATE_FSC_IMPORTED;
               }
               else
               {
                  /* do nothing */
                  ;
               }
            }
         }
         else
         {
            /* Is there a SW with the given ID?                               */
            RetVal = Swt_FindSW(SWData,NrOfSWIDs,SwId,&i,TRUE);

            if( Swt_RC_OK == RetVal )
            {
               if( NrOfCerts > i )
               {
                  /* Import the certificate for the SwId                      */
                  (void)Swt_CommonCopy(CertData[i].Cert,Cert,CertLength);

                  /* Set certificate status                                   */
                  CertData[i].CertState = Swt_STATE_CERT_IMPORTED;

                  /* Set signature status, if necessary                       */
                  if(Swt_STATE_FSC_ACCEPTED == SWData[i].FscState)
                  {
                     SWData[i].FscState = Swt_STATE_FSC_IMPORTED;
                  }
               }
               else
               {
                  /* There is no space to store the certificate.              */
                  RetVal = Swt_RC_NO_FREE_SPACE;
               }
            }
         }

         /* Store status persistently                                         */
         if( Swt_RC_OK == RetVal )
         {
                                       /* write block into persistent storage */
            RetVal = Appl_SwtWriteBlock( (uint16)SWT_SW_DATA );

            if( Swt_RC_OK == RetVal )
            {
               RetVal = Appl_SwtWriteBlock( (uint16)SWT_CERT_DATA );
            }
         }
      }
      else
      {
                                                 /* this should be impossible */
         RetVal = Swt_RC_UNKNOWN_ERROR;
      }
   }



   return RetVal;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CheckCert                                           **
**                                                                            **
** DESCRIPTION    : Checks the validiy of a stored certificate.               **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : SGID       : The ID of the controller                     **
**                  SwId       : The SWID of the corresponding SW             **
**                  CertType   : The type of the given certificate:           **
**                               0x01 - SigS certificate                      **
**                               0x02 - FSCS certificate                      **
**                               0x03 - Root certificate                      **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a parameter is invalid             **
**                  Swt_RC_NO_FREE_SPACE, if the certificate is too large   **
**                      to be stored                                          **
**                  Swt_RC_SW_NOT_EXISTENT, if the given SWID is not stored **
**                  Swt_RC_MISSING_SG_DATA, if there is no controller with  **
**                       the given SGID                                       **
**                  Swt_RC_ROOT_CERT_NOT_EXISTENT, if the root certificate  **
**                       can't be accessed.                                   **
**                  Swt_RC_ROOT_CERT_CORRUPT, if the root certificate can't **
**                       be parsed.                                           **
**                  Swt_STATE_CERT_NOT_EXISTENT, if the certificate to      **
**                       check has not been imported                          **
**                  Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM, if the extension   **
**                                   is not valid for the given certificate   **
**                  Swt_RC_WRONG_CERT_CONTENT_ISSUER, if the issuer is not  **
**                          identical to the subject of the root certificate  **
**                  Swt_RC_FSCS_CERT_INVALID, if the FSCS certificate could **
**                                  not be parsed or the date is invalid      **
**                  Swt_RC_SIGS_CERT_INVALID, if the SigS certificate could **
**                                  not be parsed or the date is invalid      **
**                  Swt_RC_CERT_REJECTED, if the certificate has already    **
**                       been rejected by a previous check                    **
**                  Swt_RC_SIG_CHECK_FAILURE, if the signature check failed **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens   **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CheckCert
(
   const uint8                            SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   SwId,
   const uint8                            CertType,
   const boolean                          writeNvm
)
{
   SwtRC_t RetVal;                      /* the return value of the function */

   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;

   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */
   uint32 Date;                 /* The current date for the certificate check */
                      /* An array containing the certificate data for this SG */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) CertData;
   uint8 NrOfCerts ;                /* The amount of certificates for this SG */

   uint8     i;                                        /* the index of the sw */

                                           /* Pointer to the root certificate */
   P2CONST(uint8,AUTOMATIC,SC_FAR) RootCertPtr;
                               /* Pointer to the modulus of the root cert key */
   Swt_LNWordType KeyModulus[Swt_LNGetWordLen(SWT_CERT_SIG_LEN_BYTES)];
                              /* Pointer of the exponent of the root cert key */
   Swt_LNWordType KeyExponent[Swt_LNGetWordLen(SWT_CERT_SIG_LEN_BYTES)];

                                                    /* public key information */
   Swt_RSAKeyType PublicKey;

                  /* Pointer to the the start of the subject of the root cert */
   P2CONST(uint8,AUTOMATIC,SC_FAR) SubjectStartPtr;


   /* Initialise local variables                                              */
   RetVal = Swt_RC_OK;
   SWSigData = 0;
   RootCertPtr = 0;
   SubjectStartPtr = 0;

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( 0 == SwId )                            /* Check if we got a valid SwId */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_CHECKFSC_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   /* Check the given cert type                                               */
   if( ((SWT_CERT_TYPE_SIGS != CertType) &&
       (SWT_CERT_TYPE_FSCS != CertType)) &&
       (SWT_CERT_TYPE_ROOT != CertType))
   {
      RetVal = Swt_RC_BAD_PARAM;
   }

   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

   /* Get the certificate data for this SG.                                   */
   CertData = Swt_GetCertData(SGID,&NrOfCerts);

   /* Get the software signature state variable.                              */
   SWSigData = Swt_GetSWSigData(SGID);

   if( 0 == SWData )
   {
      RetVal = Swt_RC_MISSING_SG_DATA;
   }

   /* Check status of the root certificate                                    */
   if( Swt_RC_OK == RetVal )
   {
      switch( SWSigData->RootCertState )
      {
         case Swt_STATE_CERT_NOT_EXISTENT:
            RetVal = Swt_RC_ROOT_CERT_NOT_EXISTENT;
            break;

         case Swt_STATE_CERT_REJECTED:
            RetVal = Swt_RC_ROOT_CERT_REJECTED;
            break;

         case Swt_STATE_CERT_IMPORTED:
            /* this case is not specified                                     */
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;

         default:
            /* good case, do nothing                                          */
            break;
      }
   }

   /* Get root certificate                                                    */
   if( Swt_RC_OK == RetVal )
   {
      RootCertPtr = Appl_SwtGetRootCert();

      if( 0 == RootCertPtr )
      {
         UpdateSwtNvm(SWSigData->RootCertState, Swt_STATE_CERT_NOT_EXISTENT, nvmSwtSwSigData);
         RetVal = Swt_RC_ROOT_CERT_NOT_EXISTENT;
      }
   }

   /* Parse root certificate to get issuer and key information                */
   if( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_CertExtractRootValues
               (
                  RootCertPtr,
                  KeyModulus,
                  KeyExponent,
                  &SubjectStartPtr
               );

      if( Swt_RC_OK != RetVal )
      {
         RetVal = Swt_RC_ROOT_CERT_CORRUPT;
      }
      else
      {
         /* Compose public key information                                    */
         PublicKey.Exponent = KeyExponent;
         PublicKey.Modulus = KeyModulus;
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
         // TODO: Barrett         
         PublicKey.ModulusExt = 0;
#endif /* (SWT_RSA_USE_BARRETT == SWT_CFG_ON) */
      }
   }

   /* Check the given certificate                                             */
   if( Swt_RC_OK == RetVal )
   {
      switch ( (Swt_CertType)CertType )
      {
         case SWT_CERT_TYPE_SIGS:
            /* Check status of the imported SigS certificate                  */
            if( Swt_STATE_CERT_NOT_EXISTENT == SWSigData->CertState)
            {
               RetVal = Swt_RC_CERT_NOT_EXISTENT;
            }
            else
            {
               /* Only freshly imported or rejected certificates are subject  */
               /* to a date check.                                            */
               if( ( Swt_STATE_CERT_IMPORTED == SWSigData->CertState) ||
                   ( Swt_STATE_CERT_REJECTED == SWSigData->CertState) )
               {
                  Date = Appl_SwtGetMinutes();
               }
               else
               {
                  Date = 0;
               }

               // TODO: Barrett
               // PublicKey.ModulusExt is set to 0 if SWT_RSA_USE_BARRETT == SWT_CFG_ON

               /* Check the SigS certificate                                  */
               RetVal = Swt_CertCheck
                        (
                           SWSigData->Cert,
                           SubjectStartPtr,
                           &PublicKey,
                           (Swt_CertType)CertType,
                           Date
                         );

               /* Set status of the certificate                               */
               if( Swt_RC_OK == RetVal )
               {
                  UpdateSwtNvm(SWSigData->CertState, Swt_STATE_CERT_ACCEPTED, nvmSwtSwSigData);
               }
               else
               {
                  UpdateSwtNvm(SWSigData->CertState, Swt_STATE_CERT_REJECTED, nvmSwtSwSigData);

                  for( i = 0; i < NrOfSWIDs; i++ )
                  {
                     if( Swt_STATE_SW_NOT_EXISTENT != SWData[i].SwState )
                     {                        
                        UpdateSwtNvm(SWData[i].SwState, Swt_STATE_SW_DEACTIVATED, nvmSwtSwData);
                     }
                  }
               }
            }
            break;

         case SWT_CERT_TYPE_FSCS:
            /* Is there a software with the given SwId?                       */
            RetVal = Swt_FindSW(SWData,NrOfSWIDs,SwId,&i,TRUE);

            if( Swt_RC_OK == RetVal )
            {
               if( ( ( NrOfCerts > i )                              &&
                     ( Swt_FSC_TYPE_FULL == SWData[i].FscType ) ) &&
                     ( Swt_STATE_CERT_NOT_EXISTENT != CertData[i].CertState) )
               {
                  /* Only freshly imported or rejected certificates are       */
                  /* subject to a date check.                                 */
                  if( ( Swt_STATE_CERT_IMPORTED == CertData[i].CertState) ||
                      ( Swt_STATE_CERT_REJECTED == CertData[i].CertState) )
                  {
                     Date = Appl_SwtGetMinutes();
                  }
                  else
                  {
                     Date = 0;
                  }

                  // TODO: Barrett
                  // PublicKey.ModulusExt is set to 0 if SWT_RSA_USE_BARRETT == SWT_CFG_ON

                  /* Check the corresponding FSC certificate                  */
                  RetVal = Swt_CertCheck
                           (
                              CertData[i].Cert,
                              SubjectStartPtr,
                              &PublicKey,
                              (Swt_CertType)CertType,
                              Date
                           );


                  /* Set status of the certificate                            */
                  if( Swt_RC_OK == RetVal )
                  {
                     UpdateSwtNvm(CertData[i].CertState, Swt_STATE_CERT_ACCEPTED, nvmSwtCertData);
                  }
                  else
                  {
                     UpdateSwtNvm(CertData[i].CertState, Swt_STATE_CERT_REJECTED, nvmSwtCertData);                     
                     UpdateSwtNvm(SWData[i].SwState, Swt_STATE_SW_DEACTIVATED, nvmSwtSwData);

                     /* Only set the FSC state to rejected if there is an     */
                     /* actual FSC stored.                                    */
                     if (Swt_STATE_FSC_NOT_EXISTENT != SWData[i].FscState )
                     {                        
                        UpdateSwtNvm(SWData[i].FscState, Swt_STATE_FSC_REJECTED, nvmSwtSwData);
                     }
                  }
               }
               else
               {
                  RetVal = Swt_RC_CERT_NOT_EXISTENT;
               }
            }
            else
            {
               RetVal = Swt_RC_SW_NOT_EXISTENT;
            }
            break;

         default:
                                                    /* wrong certificate type */
            RetVal =  Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   if (TRUE == writeNvm)
   {
                                                       /* Store status persistently */
      if (TRUE == nvmSwtSwData)
      {
         if( Swt_RC_OK != Appl_SwtWriteBlock( (uint16)SWT_SW_DATA ) )
         {
            RetVal = Swt_RC_FLASH_WRITE_ERROR;
         }         
      }
      if (TRUE == nvmSwtSwSigData)
      {
         if( Swt_RC_OK != Appl_SwtWriteBlock( (uint16)SWT_SWSIG_DATA ) )
         {
            RetVal = Swt_RC_FLASH_WRITE_ERROR;
         }         
      }
      if (TRUE == nvmSwtCertData)
      {
         if( Swt_RC_OK != Appl_SwtWriteBlock( (uint16)SWT_CERT_DATA ) )
         {
            RetVal = Swt_RC_FLASH_WRITE_ERROR;
         }         
      }
   }

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetCert                                             **
**                                                                            **
** DESCRIPTION    : Returns a pointer to the start of the corresponding       **
**                  certificate.                                              **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS : - '*CertPtr' will contain the start address of the        **
**                    certificate                                             **
**                  - '*CertLengthPtr' will contain the length of the         **
**                    certificate                                             **
**                                                                            **
** PARAMETERS     : SGID       : The ID of the controller                     **
**                  SwId       : The SWID of the corresponding SW             **
**                  CertType   : The type of the given certificate:           **
**                               0x01 - SigS certificate                      **
**                               0x02 - FSCS certificate                      **
**                               0x03 - Root certificate                      **
**                  CertPtr    : A pointer to an address variable where the   **
**                               start of the certificate shall be stored.    **
**                  CertLengthPtr : A pointer to a variable where the length  **
**                                  of thee certificate shall be stored.      **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a parameter is invalid             **
**                  Swt_RC_NO_FREE_SPACE, if the certificate is too large   **
**                      to be stored                                          **
**                  Swt_RC_SW_NOT_EXISTENT, if the given SWID is not stored **
**                      in the handler                                        **
**                  Swt_RC_MISSING_SG_DATA, if there is no controller with  **
**                       the given SGID                                       **
**                  Swt_RC_SIGS_CERT_NOT_EXISTENT, if the requested         **
**                       certificate is not stored                            **
**                  Swt_RC_SIGS_CERT_NOT_CHECKED, if the requested          **
**                       certificate hasn't been checked so far               **
**                  Swt_RC_SIGS_CERT_INVALID, if the requested certificate  **
**                       is not valid                                         **
**                  Swt_RC_FSCS_CERT_NOT_EXISTENT, if no certificate has    **
**                       been stored for the given SWID                       **
**                  Swt_RC_FSCS_CERT_NOT_CHECKED, if the stored certificate **
**                       has not been checked so far.                         **
**                  Swt_RC_FSCS_CERT_INVALID, if the stored certificate is  **
**                       invalid.                                             **
**                  Swt_RC_ROOT_CERT_INVALID, if the stored root certificate**
**                       is invalid, i.e. couldn't been read.                 **
**                  Swt_RC_SW_NOT_EXISTENT, if no software with the given   **
**                       SWID is stored inside the SG                         **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens   **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_GetCert
(
   const uint8                            SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   SwId,
   const uint8                            CertType,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) CertPtr,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)    CertLengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */

   uint8     i;                                        /* the index of the sw */

   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */
                      /* An array containing the certificate data for this SG */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) CertData;
   uint8 NrOfCerts ;                /* The amount of certificates for this SG */

   /* Initialise local variables                                              */
   RetVal = Swt_RC_OK;
   i = 0;
   SWSigData = 0;
   SWData = 0;
   NrOfSWIDs = 0;
   NrOfCerts = 0;
   CertData = 0;

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( ( ( 0 == SwId )      ||
         ( 0 == CertPtr ) ) ||
         ( 0 == CertLengthPtr ) )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_GETCERT_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */


   /* Check the given cert type                                               */
   if( ((SWT_CERT_TYPE_SIGS != CertType) &&
       (SWT_CERT_TYPE_FSCS != CertType)) &&
       (SWT_CERT_TYPE_ROOT != CertType))
   {
      RetVal = Swt_RC_BAD_PARAM;
   }

   /* Get the SW data for this SG.                                            */
   if( Swt_RC_OK == RetVal )
   {
      SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

      /* Get the certificate data for this SG.                                */
      CertData = Swt_GetCertData(SGID,&NrOfCerts);

      /* Get the software signature data variable.                            */
      SWSigData = Swt_GetSWSigData(SGID);

      if( 0 == SWData )
      {
         RetVal = Swt_RC_MISSING_SG_DATA;
      }
   }

   /* Handle certificate types                                                */
   if( Swt_RC_OK == RetVal )
   {
      switch( (Swt_CertType)CertType )
      {
         case SWT_CERT_TYPE_SIGS:

            if( Swt_STATE_CERT_NOT_EXISTENT == SWSigData->CertState )
            {
               RetVal = Swt_RC_SIGS_CERT_NOT_EXISTENT;
            }
            else if ( Swt_STATE_CERT_IMPORTED == SWSigData->CertState )
            {
               RetVal = Swt_RC_SIGS_CERT_NOT_CHECKED;
            }
            else if( Swt_STATE_CERT_REJECTED == SWSigData->CertState )
            {
               RetVal = Swt_RC_SIGS_CERT_INVALID;
            }
            else
            {
               *CertPtr = SWSigData->Cert;
               RetVal = Swt_CertGetLength(*CertPtr,CertLengthPtr);
            }
            break;
         case SWT_CERT_TYPE_FSCS:
            /* Is there a software with the given SwId?                       */
            RetVal = Swt_FindSW(SWData,NrOfSWIDs,SwId,&i,TRUE);

            if( Swt_RC_OK == RetVal )
            {
               if( ( NrOfCerts > i ) &&
                   ( Swt_FSC_TYPE_FULL == SWData[i].FscType ) )
               {
                  /* Is there an certificate at the given index?              */
                  if( Swt_STATE_CERT_NOT_EXISTENT == CertData[i].CertState )
                  {
                     RetVal = Swt_RC_FSCS_CERT_NOT_EXISTENT;
                  }
                  else if( Swt_STATE_CERT_IMPORTED == CertData[i].CertState )
                  {
                     RetVal = Swt_RC_FSCS_CERT_NOT_CHECKED;
                  }
                  else if( Swt_STATE_CERT_REJECTED == CertData[i].CertState )
                  {
                     RetVal = Swt_RC_FSCS_CERT_INVALID;
                  }
                  else
                  {
                     *CertPtr = CertData[i].Cert;
                     RetVal = Swt_CertGetLength(*CertPtr,CertLengthPtr);
                  }
               }
               else
               {
                  RetVal = Swt_RC_FSCS_CERT_NOT_EXISTENT;
               }
            }
            else
            {
               RetVal = Swt_RC_SW_NOT_EXISTENT;
            }
            break;
         case SWT_CERT_TYPE_ROOT:
            if( Swt_STATE_CERT_REJECTED == SWSigData->RootCertState )
            {
               RetVal = Swt_RC_ROOT_CERT_INVALID;
            }
            else
            {
               *CertPtr = Appl_SwtGetRootCert();
               RetVal = Swt_CertGetLength(*CertPtr,CertLengthPtr);
            }
            break;
         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
      }
   }

   return RetVal;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetSigSID                                           **
**                                                                            **
** DESCRIPTION    : Stores the ID of the SigS into the given buffer.          **
**                                                                            **
** PRECONDITIONS  : SigSIdPtr : valid pointer to a memory location which is   **
**                              big enough to store the SigS id (not checked) **
** POSTCONDITIONS : SigSIdPtr : Contains the ID of the SigS, whose            **
**                              certificate is stored in the SG               **
**                                                                            **
** PARAMETERS     : SGID      : The ID of the SG                              **
**                  Ret       : A pointer to the start of an array where the  **
**                              SigS ID will be stored. 8 Bytes will be copied**
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a given parameter is not valid     **
**                  Swt_RC_MISSING_SG_DATA,  if 'SGID' does not match the   **
**                                             SGID of any controller         **
**                  Swt_RC_SW_NOT_EXISTENT, if no software with the given   **
**                                            SwId is stored inside the ECU   **
**                  Swt_RC_SIGS_CERT_NOT_EXISTENT, if no SigS certficate is **
**                                                   stored                   **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_GetSigSID
(
   const uint8                   SGID,
   P2VAR(uint8,AUTOMATIC,SC_FAR) Ret
)
{
   SwtRC_t RetVal;                         /* return value of this function */
   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;


#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if(0 == Ret )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_GETSIGSID_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   /* Initialise the local variables                                          */
   RetVal = Swt_RC_OK;

   /* Get signature data for the given SGID                                   */
   SWSigData = Swt_GetSWSigData(SGID);
   if( 0 == SWSigData )
   {
      RetVal = Swt_RC_MISSING_SG_DATA;
   }

   /* Check the software signature status                                     */
   if( Swt_RC_OK == RetVal )
   {
      if( Swt_STATE_SWSIG_NOT_EXISTENT == SWSigData->SigState )
      {
         RetVal = Swt_RC_SW_NOT_EXISTENT;
      }
   }

   /* Check the certificate status                                            */
   if( Swt_RC_OK == RetVal )
   {
      if( Swt_STATE_CERT_NOT_EXISTENT == SWSigData->CertState )
      {
         RetVal = Swt_RC_SIGS_CERT_NOT_EXISTENT;
      }
   }

   /* Extract the SigS-ID from the SigS certificate                           */
   if( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_CertExtractSigSValues ( SWSigData->Cert, Ret );
   }

   return RetVal;
}

#endif                            /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */


#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/


/*** End of file **************************************************************/
