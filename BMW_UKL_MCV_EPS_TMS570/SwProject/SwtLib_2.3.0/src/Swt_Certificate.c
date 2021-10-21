/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Certificate.c                                           **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Routines to handle DER encoded X.509 v3 certificates.         **
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
** --------     -------------------------  -------------------------------------
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

/*******************************************************************************
**                      inclusions                                            **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Certificate.h"        /* declarations of certificate services */
#include "Swt_Common.h"                                  /* common routines */
#include "Swt_Date.h"                                        /* date parser */
#include "Swt_FSC.h"                                     /* FSC information */

#include "Swt_Signature.h"               /* signature verification services */
#include "Swt_Hash.h"                                      /* hash routines */
#include "Swt_RSA.h"                                        /* RSA routines */

/*******************************************************************************
**                      macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      type definitions                                      **
*******************************************************************************/

/* Nxtr Patch Start -- Added Start section to complete the stop section call below
 * Added: 19Aug12 - KJS - To correct Memmap errors with incomplete sections
 */
#define SWT_START_SEC_CODE
#include "MemMap.h"
/* Nxtr Patch End */


/* The components of the DER encoding of a data value according to X.690,     */
/* chapter 8.1.                                                               */
typedef enum
{
  SWT_CERT_DER_TAG,
  SWT_CERT_DER_LENGTH,
  SWT_CERT_DER_CONTENTS,
  SWT_CERT_DER_END
}
Swt_DERComponentsType;


/* The elements of an X.509 v3 certificate according to RFC 2459, chapter 4.1.*/
typedef enum
{
  SWT_CERT_X509_TBS_CERTIFICATE,
  SWT_CERT_X509_SIGNATURE_ALGO,
  SWT_CERT_X509_SIGNATURE,
  SWT_CERT_X509_END
}
Swt_X509ElementType;

/* The elements of a TBSCertificate according to RFC 2459, chapter 4.1. */
typedef enum
{
  SWT_CERT_TBS_VERSION,
  SWT_CERT_TBS_SERIALNUMBER,
  SWT_CERT_TBS_SIGNATURE,
  SWT_CERT_TBS_ISSUER,
  SWT_CERT_TBS_VALIDITY,
  SWT_CERT_TBS_SUBJECT,
  SWT_CERT_TBS_SUBJECTPKI,
  SWT_CERT_TBS_EXTENSIONS,
  SWT_CERT_TBS_END
}
Swt_TBSElementType;


/* The elements of the SubjectPublikKeyInfo according to RFC 2459, chapter    */
/* 4.1.                                                                       */
typedef enum
{
  SWT_CERT_SUBJECTPKI_ALGO,
  SWT_CERT_SUBJECTPKI_SUBJECTPK,
  SWT_CERT_SUBJECTPKI_END
}
Swt_SubjectPKIType;


/* The elements of an Extension according to RFC 2459, chapter 4.1. */
typedef enum
{
  SWT_CERT_EXTENSION_ID,
  SWT_CERT_EXTENSION_CRITICAL,
  SWT_CERT_EXTENSION_VALUE,
  SWT_CERT_EXTENSION_END
}
Swt_ExtensionType;


/* The elements of the Validity field according to RFC 2459, chapter 4.1. */
typedef enum
{
  SWT_CERT_VALID_NOT_BEFORE,
  SWT_CERT_VALID_NOT_AFTER,
  SWT_CERT_VALID_END
}
Swt_ValidityType;

#define SWT_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      external function declarations                        **
*******************************************************************************/

/*******************************************************************************
**                      internal function declarations                        **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

SWT_STATIC_FUNC SwtRC_t Swt_DEREncodingGetInfo
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) DEREncoding,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ValueLengthPtr,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ValueStartPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_DEREncodingSkip
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) DEREncoding,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  DEREncodingLengthPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_TBSCertExtractRootValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                        TBSCert,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)                         TBSCertLengthPtr,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)               Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)               Exponent,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR)SubjectPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_TBSCertExtractFSCSValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)          TBSCert,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)           TBSCertLengthPtr,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Exponent,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)            SerialNr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)           StartDatePtr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)           EndDatePtr
);

SWT_STATIC_FUNC SwtRC_t Swt_SubjectPKIExtractKey
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)          SubjectPKI,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)           SubjectPKILengthPtr,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Exponent
);

SWT_STATIC_FUNC SwtRC_t Swt_DEREncodingExtractInteger
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)          DEREncoding,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)           DEREncodingLengthPtr,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Integer
);

SWT_STATIC_FUNC SwtRC_t Swt_SubjectExtract
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                         Subject,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)                          SubjectLengthPtr,
  CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) SubjectPtr
);

SWT_STATIC_FUNC SwtRC_t Swt_SerialNrExtract
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SerialNr,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  SerialNrLengthPtr,
  CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)   SerialNrValue
);

SWT_STATIC_FUNC SwtRC_t Swt_ValidityExtract
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Validity,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ValidityLengthPtr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)  StartDatePtr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)  EndDatePtr
);

SWT_STATIC_FUNC SwtRC_t Swt_TBSCertCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) TBSCert,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  TBSCertLengthPtr,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) RootCertSubject,
  const Swt_CertType                 CertType,
  const uint32                         Date
);

SWT_STATIC_FUNC SwtRC_t Swt_IssuerCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Issuer,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  IssuerLengthPtr,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) RootCertSubject
);

SWT_STATIC_FUNC SwtRC_t Swt_ExtensionsCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Extensions,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ExtensionsLengthPtr,
  const Swt_CertType                 CertType
);

SWT_STATIC_FUNC SwtRC_t Swt_ExtensionCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Extension,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ExtensionLengthPtr,
  const Swt_CertType                 CertType
);

SWT_STATIC_FUNC SwtRC_t Swt_KeyUsageCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) KeyUsage,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  KeyUsageLengthPtr,
  const Swt_CertType                 CertType
);

SWT_STATIC_FUNC SwtRC_t Swt_ValidityCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Validity,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ValidityLengthPtr,
  const uint32                         Date
);

/* Nxtr Patch Start -- Added stop section to complete the start section call above 
 * Added: 19Aug12 - KJS - To correct Memmap errors with incomplete sections
 */
#define SWT_STOP_SEC_CODE
#include "MemMap.h"
/* Nxtr Patch End */


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
** FUNC-NAME      : Swt_CertCheck                                           **
**                                                                            **
** DESCRIPTION    : Check the validity of a given certificate. Its signature  **
**                  must be valid, the issuer must be identical to the        **
**                  subject of the root certificate, its extension field must **
**                  be valid, and the start and end dates given in the        **
**                  validity field must include the current date.             **
**                                                                            **
** PRECONDITIONS  : 'Cert' is a valid pointer (not checked)                   **
**                  'RootCertSubject' is a valid pointer (not checked)        **
**                  'PublicKeyPtr' is a valid pointer (not checked)           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Cert : A pointer to the start of a byte array which       **
**                         contains the certificate to check                  **
**                  RootCertSubject : A pointer to the start of an array      **
**                                    which contains the subject of root      **
**                                    certficate                              **
**                  PublicKeyPtr : A pointer to a public key with which the   **
**                                 signature of the FSC has to be checked     **
**                  CertType : The type of the given certificate:             **
**                             0x01 - SigS certificate                        **
**                             0x02 - FSCS certificate                        **
**                  Date: The current date (given in minutes since 2000/01/01)**
**                        or 0. If the date is not zero, the validity field   **
**                        of the certificate must be checked against this     **
**                        date.                                               **
**                                                                            **
** RETURN         : Swt_RC_FSCS_CERT_INVALID, if the FSCS certificate could **
**                                  not be parsed or the date is invalid      **
**                  Swt_RC_SIGS_CERT_INVALID, if the SigS certificate could **
**                                  not be parsed or the date is invalid      **
**                  Swt_RC_WRONG_CERT_CONTENT_ISSUER, if the issuer is not  **
**                          identical to the subject of the root certificate  **
**                  Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM, if the extension   **
**                                   is not valid for the given certificate   **
**                  Swt_RC_SIG_CHECK_FAILURE, if the signature check failed **
**                  Swt_RC_OK, if the certificate is valid                  **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CertCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            Cert,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            RootCertSubject,
  CONSTP2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) PublicKeyPtr,
  const Swt_CertType                            CertType,
  const uint32                                    Date
)
{
   SwtRC_t             RetVal;          /* the return value of the function */
   Swt_X509ElementType CertElement;     /* the current element of the cert. */
   uint16                Length;             /* The length of the certificate */
   uint16                Pos;      /* the current position in the certificate */
   uint16                ElementLength;  /* the length of the current element */
   uint16                SignatureLength;      /* the length of the signature */
   uint16                Temp;
   uint16                TBSCertLength;   /* the length of the TBSCerfiticate */
   uint16                TBSCertPos;  /* the starting position of the TBSCert.*/


   /* Initialize some values. */
   TBSCertPos = 0;
   TBSCertLength = 0;

   /* The certificate is a DER encoded sequence. We get the starting position */
   /* of the first element of the sequence, which must be the TBSCertificate, */
   /* in "Pos".                                                               */
   RetVal = Swt_DEREncodingGetInfo ( Cert, &Length, &Pos );

   /* Compute the complete length of the certificate. */
   Length += Pos;

   /* The first element of the sequence must be a TBSCertificate. */
   CertElement = SWT_CERT_X509_TBS_CERTIFICATE;

   /* Go through all elements of the certificate and check those elements     */
   /* which have to be checked until all elements are done or an error has    */
   /* been encountered.                                                       */
   while ( ( ( CertElement < SWT_CERT_X509_END ) &&
             ( Swt_RC_OK == RetVal ) )           &&
             ( Pos < Length ) )
   {
      /* What is the current element? */
      switch ( CertElement )
      {
         case SWT_CERT_X509_TBS_CERTIFICATE:
            /* We are at the TBSCertificate. */

            /* The current position is the start of the TBSCertificate. This  */
            /* is stored for the signature check.                             */
            TBSCertPos = Pos;

            /* Check the TBSCertificate. */
            RetVal = Swt_TBSCertCheck ( &Cert[Pos],
                                          &ElementLength,
                                          RootCertSubject,
                                          CertType,
                                          Date );

            /* We now know the length of the TBSCertificate. This is stored   */
            /* for the signature check.                                       */
            TBSCertLength = ElementLength;

            /* Skip the TBSCertificate. */
            Pos += ElementLength;

            /* We are now in the next element of the certificate. */
            CertElement++;
            break;

         case SWT_CERT_X509_SIGNATURE_ALGO:
            /* We are at the signature algrithm. */

            /* We simply ignore the signature algorithm. */
            RetVal = Swt_DEREncodingSkip ( &Cert[Pos], &ElementLength );

            /* Skip past the signature algorithm. */
            Pos += ElementLength;

            /* We are now in the next element of the certificate. */
            CertElement++;
            break;

         case SWT_CERT_X509_SIGNATURE:
            /* We are at the signature. It is an encoded bit string. */

            /* Get the starting position of the bit string and its length. */
            RetVal = Swt_DEREncodingGetInfo ( &Cert[Pos],
                                                &SignatureLength,
                                                &Temp );

            Pos += Temp;

            /* The bit string must start with a zero byte. */
            if ( 0x00 == Cert[Pos] )
            {
               /* Skip the zero byte. */
               Pos++;
               SignatureLength--;
            }
            else
            {
               RetVal = Swt_RC_UNKNOWN_ERROR;
            }

            if( Swt_RC_OK == RetVal )
            {
               /* Check the signature of the TBSCertificate. */
               RetVal = Swt_SignatureCheck ( &Cert[Pos],
                                               SignatureLength,
                                               &Cert[TBSCertPos],
                                               TBSCertLength,
                                               PublicKeyPtr );
            }

            Pos += SignatureLength;

            /* We are now in the next element of the certificate (which is    */
            /* the end.                                                       */
            CertElement++;
            break;

         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* If we did not parse the certificate exactly to the last byte or if   */
      /* we did not find all elements, the certificate is invalid.            */
      if ( ( Length != Pos ) || ( CertElement != SWT_CERT_X509_END ) )
      {
         RetVal = Swt_RC_CERT_INVALID;
      }
   }

   /* The return value for invalid certificates must depend on the given      */
   /* certificate.                                                            */
   if ( Swt_RC_CERT_INVALID == RetVal )
   {
      switch ( CertType )
      {
         case SWT_CERT_TYPE_SIGS:
            RetVal = Swt_RC_SIGS_CERT_INVALID;
            break;

         case SWT_CERT_TYPE_FSCS:
            RetVal = Swt_RC_FSCS_CERT_INVALID;
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
** FUNC-NAME      : Swt_CertExtractRootValues                               **
**                                                                            **
** DESCRIPTION    : Extract a public key and/or the subject from a given      **
**                  root certificate.                                         **
**                                                                            **
** PRECONDITIONS  : 'Cert' is a valid pointer (not checked)                   **
**                                                                            **
** POSTCONDITIONS : 'Modulus' contains the modulus of the public key stored   **
**                            in 'Cert'.                                      **
**                  'Exponent' contains the public exponent of the public key **
**                             stored in 'Cert'.                              **
**                  '*SubjectPtr' contains the start address of an array      **
**                                contains the subject of the certificate.    **
**                                                                            **
** PARAMETERS     : Cert : A pointer to the start of a byte array which       **
**                         contains the certificate with the public key       **
**                  Modulus : A pointer to the start of an array where the    **
**                            modulus of the public key will be stored. If    **
**                            this is the null pointer, the modulus will not  **
**                            be extracted.                                   **
**                  Exponent : A pointer to the start of an array where the   **
**                             exponent of the public key will be stored. If  **
**                             this is the null pointer, the exponent will not**
**                             be extracted.                                  **
**                  SubjectPtr : A pointer to a variable which will store the **
**                               start address of an array which contains the **
**                               subject. If this is the null  pointer, the   **
**                               subject start address will not be extracted. **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed                             **
**                  Swt_RC_OK, if the values could be extracted             **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CertExtractRootValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                         Cert,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)                Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)                Exponent,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) SubjectPtr
)
{
   SwtRC_t             RetVal;          /* the return value of the function */
   Swt_X509ElementType CertElement;     /* the current element of the cert. */
   uint16                Ignore;             /* a value which will be ignored */
   uint16                Pos;      /* the current position in the certificate */
   uint16                ElementLength;  /* the length of the current element */


   /* The certificate is a DER encoded sequence. We get the starting position */
   /* of the first element of the sequence, which must be the TBSCertificate, */
   /* in "Pos".                                                               */
   RetVal = Swt_DEREncodingGetInfo ( Cert, &Ignore, &Pos );

   /* The first element of the sequence must be a TBSCertificate. */
   CertElement = SWT_CERT_X509_TBS_CERTIFICATE;

   /* Go through all elements of the certificate until the values have been   */
   /* extracted or an error has been encountered.                             */
   while ( ( CertElement < SWT_CERT_X509_SIGNATURE_ALGO ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      /* What is the current element? */
      if ( SWT_CERT_X509_TBS_CERTIFICATE == CertElement )
      {
         /* We are at the TBSCertificate. It contains the values. */

         /* Extract the values from TBSCertificate. */
         RetVal = Swt_TBSCertExtractRootValues ( &Cert[Pos],
                                                   &ElementLength,
                                                   Modulus,
                                                   Exponent,
                                                   SubjectPtr );
         /* Skip past the TBSCertificate. */
         Pos += ElementLength;

         /* We are now in the next element of the certificate. */
         CertElement++;
      }
      else
      {
         /* Other elements of the certificate should never be reached. */
         RetVal = Swt_RC_UNKNOWN_ERROR;
      }
   }

   return RetVal;
}





/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CertExtractFSCSValues                               **
**                                                                            **
** DESCRIPTION    : Extract a public key, the start and end date of the       **
**                  validity period and the serial number from a given FSCS   **
**                  certificate.                                              **
**                                                                            **
** PRECONDITIONS  : 'Cert' is a valid pointer (not checked)                   **
**                                                                            **
** POSTCONDITIONS : 'Modulus' contains the modulus of the public key stored   **
**                            in 'Cert'.                                      **
**                  'Exponent' contains the public exponent of the public key **
**                             stored in 'Cert'.                              **
**                  'SerialNr' contains the serial number of the certificate. **
**                  The variable pointed to by 'StartDatePtr' contains the    **
**                  start date of the validity period of the certificate.     **
**                  The variable pointed to by 'EndDatePtr' contains the      **
**                  end date of the validity period of the certificate.       **
**                                                                            **
** PARAMETERS     : Cert : A pointer to the start of a byte array which       **
**                         contains the certificate with the public key       **
**                  Modulus : A pointer to the start of an array where the    **
**                            modulus of the public key will be stored. If    **
**                            this is the null pointer, the modulus will not  **
**                            be extracted.                                   **
**                  Exponent : A pointer to the start of an array where the   **
**                             exponent of the public key will be stored. If  **
**                             this is the null pointer, the exponent will not**
**                             be extracted.                                  **
**                  SerialNr : A pointer to the start of an array where the   **
**                             subject will be stored. If this is the null    **
**                             pointer, the subject will not be extracted.    **
**                  StartDatePtr : A pointer to a variable where the start    **
**                                 date of the validity period (given in      **
**                                 minutes since 2000/01/01)will be stored.   **
**                                 If this is the null  pointer, the date     **
**                                 will not be extracted.                     **
**                  EndDatePtr : A pointer to a variable where the end        **
**                               date of the validity period (given in        **
**                               minutes since 2000/01/01)will be stored.     **
**                               If this is the null  pointer, the date       **
**                               will not be extracted.                       **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed                             **
**                  Swt_RC_OK, if the values could be extracted             **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CertExtractFSCSValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)          Cert,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Exponent,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)            SerialNr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)           StartDatePtr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)           EndDatePtr
)
{
   SwtRC_t             RetVal;          /* the return value of the function */
   Swt_X509ElementType CertElement;     /* the current element of the cert. */
   uint16                Ignore;             /* a value which will be ignored */
   uint16                Pos;      /* the current position in the certificate */
   uint16                ElementLength;  /* the length of the current element */


   /* The certificate is a DER encoded sequence. We get the starting position */
   /* of the first element of the sequence, which must be the TBSCertificate, */
   /* in "Pos".                                                               */
   RetVal = Swt_DEREncodingGetInfo ( Cert, &Ignore, &Pos );

   /* The first element of the sequence must be a TBSCertificate. */
   CertElement = SWT_CERT_X509_TBS_CERTIFICATE;

   /* Go through all elements of the certificate until the values have been   */
   /* extracted or an error has been encountered.                             */
   while ( ( CertElement < SWT_CERT_X509_SIGNATURE_ALGO ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      /* What is the current element? */
      if ( SWT_CERT_X509_TBS_CERTIFICATE == CertElement )
      {
         /* We are at the TBSCertificate. It contains the values. */

         /* Extract the values from TBSCertificate. */
         RetVal = Swt_TBSCertExtractFSCSValues ( &Cert[Pos],
                                                   &ElementLength,
                                                   Modulus,
                                                   Exponent,
                                                   SerialNr,
                                                   StartDatePtr,
                                                   EndDatePtr );
         /* Skip past the TBSCertificate. */
         Pos += ElementLength;

         /* We are now in the next element of the certificate. */
         CertElement++;
      }
      else
      {
         /* Other elements of the certificate should never be reached. */
         RetVal = Swt_RC_UNKNOWN_ERROR;
      }
   }

   return RetVal;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CertExtractSigSValues                               **
**                                                                            **
** DESCRIPTION    : Extract the serial number from a given SigS certificate.  **
**                                                                            **
** PRECONDITIONS  : 'Cert' is a valid pointer (not checked)                   **
**                                                                            **
** POSTCONDITIONS : 'SerialNr' contains the serial number of the certificate. **
**                                                                            **
** PARAMETERS     : Cert : A pointer to the start of a byte array which       **
**                         contains the certificate with the public key       **
**                  SerialNr : A pointer to the start of an array where the   **
**                             subject will be stored. If this is the null    **
**                             pointer, the subject will not be extracted.    **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed                             **
**                  Swt_RC_OK, if the values could be extracted             **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CertExtractSigSValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Cert,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)   SerialNr
)
{

   return Swt_CertExtractFSCSValues ( Cert,
                                        0,
                                        0,
                                        SerialNr,
                                        0,
                                        0 );
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CertGetLength                                       **
**                                                                            **
** DESCRIPTION    : Get the length of a given certificate                     **
**                                                                            **
** PRECONDITIONS  : 'Cert' is a valid pointer (not checked)                   **
**                  'CertLengthPtr' is a valid pointer (not checked)          **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'CertLengthPtr' contains the   **
**                  length of the certificate.                                **
**                                                                            **
** PARAMETERS     : Cert : A pointer to the start of a byte array which       **
**                         contains a DER encoded certificate                 **
**                  CertLengthPtr: A pointer to a variable which will hold    **
**                                 the length of the encoding                 **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed                             **
**                  Swt_RC_OK, if the certificate could be parsed           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CertGetLength
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Cert,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  CertLengthPtr
)
{
   return Swt_DEREncodingSkip ( Cert, CertLengthPtr );
}




/*******************************************************************************
**                      internal function definitions                         **
*******************************************************************************/



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DEREncodingGetInfo                                  **
**                                                                            **
** DESCRIPTION    : Parse a DER encoding of a value and return the length     **
**                  of the value and its starting position in the encoding.   **
**                                                                            **
** PRECONDITIONS  : 'DEREncoding' is a valid pointer (not checked)            **
**                  'ValueLengthPtr' is a valid pointer (not checked)         **
**                  'ValueStartPtr' is a valid pointer (not checked)          **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'ValueLengthPtr' contains      **
**                  the length of the value.                                  **
**                  The variable pointed to by 'ValueStartPtr' contains       **
**                  the starting position of the value in the DER encoding.   **
**                                                                            **
** PARAMETERS     : DEREncoding : A pointer to the start of a byte array      **
**                               which contains the DER encoding of a value   **
**                  ValueLengthPtr: A pointer to a variable which will        **
**                                  hold the length of the value              **
**                  ValueStartPtr: A pointer to a variable which will         **
**                                 hold the starting position of the value    **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the DER encoding could not be   **
**                                         parsed                             **
**                  Swt_RC_OK, if the information could be extracted        **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_DEREncodingGetInfo
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) DEREncoding,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ValueLengthPtr,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ValueStartPtr
)
{
   SwtRC_t               RetVal;        /* the return value of the function */
   Swt_DERComponentsType Component; /* the current component of the encoding*/
   uint16                  Pos;       /* the current position in the encoding */
   uint16                  Length;         /* the length of the encoded value */


   /* Initialize some values. */
   RetVal = Swt_RC_OK;
   Length = 0;

   /* We start at the beginning of the encoding. */
   Component = SWT_CERT_DER_TAG;
   Pos = 0;

   /* We go through the encoding until we have parsed the length component or */
   /* we have encountered an error.                                           */
   while ( ( Component < SWT_CERT_DER_CONTENTS ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      switch ( Component )
      {
         case SWT_CERT_DER_TAG:
            /* We skip the tag of the encoding. */
            Pos++;
            Component++;
            break;

         case SWT_CERT_DER_LENGTH:
            /* The length is parsed. */

            if (DEREncoding[Pos] < (uint8)0x7F)
            {
               /* length information in one byte */
               Length = (uint16)DEREncoding[Pos];
               Component++;
               Pos++;
            }
            else if (DEREncoding[Pos] == (uint8)0x81)
            {
               /* length information in two bytes */
               Pos++;
               Length = (uint16)DEREncoding[Pos];
               Component++;
               Pos++;
            }
            else if (DEREncoding[Pos] == (uint8)0x82)
            {
               /* length information in three bytes */
               Pos++;
               Length = (uint16)((uint16)DEREncoding[Pos] * (uint16)0x100) +
                        (uint16)DEREncoding[Pos + 1];
               Component++;
               Pos += 2;
            }
            else
            {
               /* Length information in more than three bytes is not       */
               /* supported.                                               */
               RetVal = Swt_RC_UNKNOWN_ERROR;
            }
            break;

        default:
            /* Other elements of the encoding should never be reached. */
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   *ValueStartPtr  = Pos;
   *ValueLengthPtr = Length;

   return RetVal;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DEREncodingSkip                                     **
**                                                                            **
** DESCRIPTION    : Skip the DER encoding of a value.                         **
**                                                                            **
** PRECONDITIONS  : 'DEREncoding' is a valid pointer (not checked)            **
**                  'DEREncodingLengthPtr' is a valid pointer (not checked)   **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'DEREncodingLengthPtr'         **
**                  contains the length of the DER encoding of the value.     **
**                                                                            **
** PARAMETERS     : DEREncoding : A pointer to the start of a byte array      **
**                               which contains the DER encoding of a value   **
**                  DEREncodingLengthPtr: A pointer to a variable which will  **
**                                        hold the length of the encoding     **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the DER encoding could not be   **
**                                         parsed                             **
**                  Swt_RC_OK, if the encoding could be skipped             **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_DEREncodingSkip
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) DEREncoding,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  DEREncodingLengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint16    ValueStartPos;             /* the starting position of the value */
   uint16    ValueLength;                          /* the length of the value */

   /* Get the length of the value and its starting position. */
   RetVal = Swt_DEREncodingGetInfo ( DEREncoding,
                                       &ValueLength,
                                       &ValueStartPos );

   /* The length of the DER encoding is the sum of the length of the encoded  */
   /* value and the length of the components preceding it.                    */
   *DEREncodingLengthPtr = ValueLength + ValueStartPos;

   return RetVal;
}







/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_TBSCertExtractRootValues                            **
**                                                                            **
** DESCRIPTION    : Extract a public key and/or the subject from a given      **
**                  TBSCertificate.                                           **
**                                                                            **
** PRECONDITIONS  : 'TBSCert' is a valid pointer (not checked)                **
**                  'TBSCertLengthPtr' is a valid pointer (not checked)       **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'TBSCertLengthPtr'             **
**                  contains the length of the TBSCertificate.                **
**                  'Modulus' and 'Exponent' contain the public key.          **
**                  '*SubjectPtr' contains the start address of an array      **
**                                contains the subject of the certificate.    **
**                                                                            **
** PARAMETERS     : TBSCert : A pointer to the start of a byte array          **
**                            which contains the TBSCertificate               **
**                  TBSCertLengthPtr: A pointer to a variable which will      **
**                                    hold the length of the TBSCertificate   **
**                  Modulus : A pointer to the start of an array where the    **
**                            modulus of the public key will be stored. If    **
**                            this is the null pointer, the modulus will not  **
**                            be extracted.                                   **
**                  Exponent : A pointer to the start of an array where the   **
**                             exponent of the public key will be stored. If  **
**                             this is the null pointer, the exponent will not**
**                             be extracted.                                  **
**                  SubjectPtr : A pointer to a variable which will store the **
**                               start address of an array which contains the **
**                               subject. If this is the null  pointer, the   **
**                               subject start address will not be extracted. **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed                             **
**                  Swt_RC_OK, if the public key could be extracted         **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_TBSCertExtractRootValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                        TBSCert,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)                         TBSCertLengthPtr,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)               Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)               Exponent,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR)SubjectPtr
)
{
   SwtRC_t            RetVal;           /* the return value of the function */
   Swt_TBSElementType Element; /* the current element of the TBSCertificate */
   uint16               ElementLength;   /* the length of the current element */
   uint16               Pos;    /* the current position in the TBSCertificate */
   uint16               Ignored;                     /* this value is ignored */

   /* The TBSCertificate is a DER encoded sequence. We get the starting       */
   /* position of the first element of the sequence in "Pos".                 */
   RetVal = Swt_DEREncodingGetInfo ( TBSCert, &Ignored, &Pos );

   /* The first element of TBSCertificate is the version. */
   Element = SWT_CERT_TBS_VERSION;

   /* Go through all elements of TBSCertificate until the end has been        */
   /* reached or an error has been encountered.                               */
   while ( ( Element < SWT_CERT_TBS_END ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      switch ( Element )
      {
         case SWT_CERT_TBS_VERSION:
         case SWT_CERT_TBS_SERIALNUMBER:
         case SWT_CERT_TBS_SIGNATURE:
         case SWT_CERT_TBS_ISSUER:
         case SWT_CERT_TBS_VALIDITY:
         case SWT_CERT_TBS_EXTENSIONS:
            /* Simply skip these elements. **/
            RetVal = Swt_DEREncodingSkip ( &TBSCert[Pos], &ElementLength );
            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_TBS_SUBJECT:
            if ( 0 != SubjectPtr )
            {
               /* Extract the subject. */
               RetVal = Swt_SubjectExtract ( &TBSCert[Pos],
                                               &ElementLength,
                                               SubjectPtr );
            }
            else
            {
               RetVal = Swt_DEREncodingSkip ( &TBSCert[Pos], &ElementLength );
            }

            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_TBS_SUBJECTPKI:
            if ( ( 0 != Modulus ) && ( 0 != Exponent ) )
            {
               /* Extract the public key from subjectPublicKeyInfo. */
               RetVal = Swt_SubjectPKIExtractKey ( &TBSCert[Pos],
                                                     &ElementLength,
                                                     Modulus,
                                                     Exponent );
            }
            else
            {
               RetVal = Swt_DEREncodingSkip ( &TBSCert[Pos], &ElementLength );
            }

            Pos += ElementLength;
            Element++;
            break;

         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   *TBSCertLengthPtr = Pos;

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_TBSCertExtractFSCSValues                            **
**                                                                            **
** DESCRIPTION    : Extract several values from a given  TBSCertificate.      **
**                                                                            **
** PRECONDITIONS  : 'TBSCert' is a valid pointer (not checked)                **
**                  'TBSCertLengthPtr' is a valid pointer (not checked)       **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'TBSCertLengthPtr'             **
**                  contains the length of the TBSCertificate.                **
**                  'Modulus' and 'Exponent' contain the public key.          **
**                  'SerialNr' contains the serial number of the certificate. **
**                  The variable pointed to by 'StartDatePtr' contains the    **
**                  start date of the validity period of the certificate.     **
**                  The variable pointed to by 'EndDatePtr' contains the      **
**                  end date of the validity period of the certificate.       **
**                                                                            **
** PARAMETERS     : TBSCert : A pointer to the start of a byte array          **
**                            which contains the TBSCertificate               **
**                  TBSCertLengthPtr: A pointer to a variable which will      **
**                                    hold the length of the TBSCertificate   **
**                  Modulus : A pointer to the start of an array where the    **
**                            modulus of the public key will be stored. If    **
**                            this is the null pointer, the modulus will not  **
**                            be extracted.                                   **
**                  Exponent : A pointer to the start of an array where the   **
**                             exponent of the public key will be stored. If  **
**                             this is the null pointer, the exponent will not**
**                             be extracted.                                  **
**                  SerialNr : A pointer to the start of an array where the   **
**                             subject will be stored. If this is the null    **
**                             pointer, the subject will not be extracted.    **
**                  StartDatePtr : A pointer to a variable where the start    **
**                                 date of the validity period (given in      **
**                                 minutes since 2000/01/01)will be stored.   **
**                                 If this is the null  pointer, the date     **
**                                 will not be extracted.                     **
**                  EndDatePtr : A pointer to a variable where the end        **
**                               date of the validity period (given in        **
**                               minutes since 2000/01/01)will be stored.     **
**                               If this is the null  pointer, the date       **
**                               will not be extracted.                       **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed                             **
**                  Swt_RC_OK, if the public key could be extracted         **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_TBSCertExtractFSCSValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)          TBSCert,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)           TBSCertLengthPtr,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Exponent,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)            SerialNr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)           StartDatePtr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)           EndDatePtr
)
{
   SwtRC_t            RetVal;           /* the return value of the function */
   Swt_TBSElementType Element; /* the current element of the TBSCertificate */
   uint16               ElementLength;   /* the length of the current element */
   uint16               Pos;    /* the current position in the TBSCertificate */
   uint16               Ignored;                     /* this value is ignored */

   /* The TBSCertificate is a DER encoded sequence. We get the starting       */
   /* position of the first element of the sequence in "Pos".                 */
   RetVal = Swt_DEREncodingGetInfo ( TBSCert, &Ignored, &Pos );

   /* The first element of TBSCertificate is the version. */
   Element = SWT_CERT_TBS_VERSION;

   /* Go through all elements of TBSCertificate until the end has been        */
   /* reached or an error has been encountered.                               */
   while ( ( Element < SWT_CERT_TBS_END ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      switch ( Element )
      {
         case SWT_CERT_TBS_VERSION:
         case SWT_CERT_TBS_SIGNATURE:
         case SWT_CERT_TBS_ISSUER:
         case SWT_CERT_TBS_SUBJECT:
         case SWT_CERT_TBS_EXTENSIONS:
            /* Simply skip these elements. **/
            RetVal = Swt_DEREncodingSkip ( &TBSCert[Pos], &ElementLength );
            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_TBS_SERIALNUMBER:
            if ( 0 != SerialNr )
            {
               /* Extract the serial number. */
               RetVal = Swt_SerialNrExtract ( &TBSCert[Pos],
                                                &ElementLength,
                                                SerialNr );
            }
            else
            {
               RetVal = Swt_DEREncodingSkip ( &TBSCert[Pos], &ElementLength );
            }

            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_TBS_VALIDITY:
            if ( ( 0 != StartDatePtr ) && ( 0 != EndDatePtr ) )
            {
               /* Extract the validity period. */
               RetVal = Swt_ValidityExtract ( &TBSCert[Pos],
                                                &ElementLength,
                                                StartDatePtr,
                                                EndDatePtr );
            }
            else
            {
               RetVal = Swt_DEREncodingSkip ( &TBSCert[Pos], &ElementLength );
            }

            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_TBS_SUBJECTPKI:
            if ( ( 0 != Modulus ) && ( 0 != Exponent ) )
            {
               /* Extract the public key from subjectPublicKeyInfo. */
               RetVal = Swt_SubjectPKIExtractKey ( &TBSCert[Pos],
                                                     &ElementLength,
                                                     Modulus,
                                                     Exponent );
            }
            else
            {
               RetVal = Swt_DEREncodingSkip ( &TBSCert[Pos], &ElementLength );
            }

            Pos += ElementLength;
            Element++;
            break;

         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   *TBSCertLengthPtr = Pos;

   return RetVal;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_SubjectPKIExtractKey                                **
**                                                                            **
** DESCRIPTION    : Extract a public key from a given subjectPublicKeyInfo.   **
**                                                                            **
** PRECONDITIONS  : 'SubjectPKI' is a valid pointer (not checked)             **
**                  'SubjectPKILengthPtr' is a valid pointer (not checked)    **
**                  'Modulus' is a valid pointer (not checked)                **
**                  'Exponent' is a valid pointer (not checked)               **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'SubjectPKILengthPtr'          **
**                  contains the length of the subjectPublicKeyInfo.          **
**                  'Modulus' and 'Exponent' contain the public key.          **
**                                                                            **
** PARAMETERS     : SubjectPKI : A pointer to the start of a byte array       **
**                               which contains the subjectPublicKeyInfo      **
**                  SubjectPKILengthPtr: A pointer to a variable which will   **
**                                 hold the length of the subjecPublicKeyInfo **
**                  Modulus : A pointer to the start of an array where the    **
**                            modulus of the public key will be stored        **
**                  Exponent : A pointer to the start of an array where the   **
**                             exponent of the public key will be stored      **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed                             **
**                  Swt_RC_OK, if the public key could be extracted         **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_SubjectPKIExtractKey
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)          SubjectPKI,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)           SubjectPKILengthPtr,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Exponent
)
{
   SwtRC_t            RetVal;           /* the return value of the function */
   Swt_SubjectPKIType Element;     /* the current element of the subjectPKI */
   uint16               ElementLength;   /* the length of the current element */
   uint16               Pos;        /* the current position in the subjectPKI */
   uint16               Temp;
   uint16               Ignored;                     /* this value is ignored */


   /* The subjectPublicKeyInfo is a DER encoded sequence. We get the starting */
   /* position of the first element of the sequence in "Pos".                 */
   RetVal = Swt_DEREncodingGetInfo ( SubjectPKI, &Ignored, &Pos );

   /* The first element of of the subjectPublicKeyInfo is the algorithm       */
   /* identifier.                                                             */
   Element = SWT_CERT_SUBJECTPKI_ALGO;

   /* We go through all elements of the subjectPublicKeyInfo until the public */
   /* key is extracted or an error has been encountered.                      */
   while ( ( Element < SWT_CERT_SUBJECTPKI_END ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      switch ( Element )
      {
         case SWT_CERT_SUBJECTPKI_ALGO:
            /* The algorithm identifier is skipped. */
            RetVal = Swt_DEREncodingSkip ( &SubjectPKI[Pos], &ElementLength );
            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_SUBJECTPKI_SUBJECTPK:
            /* The subjectPublicKey. This is a bit string which contains a    */
            /* sequence of two DER encoded integers.                          */

            /* Get the start of the bit string. */
            RetVal = Swt_DEREncodingGetInfo ( &SubjectPKI[Pos],
                                                &Ignored,
                                                &Temp );

            Pos += Temp;

            if ( Swt_RC_OK == RetVal )
            {
               /* The first byte of the bit string must bea zero byte. */
               if ( 0x00 == SubjectPKI[Pos]  )
               {
                  /* Skip the zero byte. */
                  Pos++;
               }
               else
               {
                  RetVal = Swt_RC_UNKNOWN_ERROR;
               }
            }

            if ( Swt_RC_OK == RetVal )
            {
               /* Now we must be at the start of an DER encoded sequence      */
               /* containing two integers. We get the starting position of    */
               /* the first element of the sequence in "Temp".                */

               RetVal = Swt_DEREncodingGetInfo ( &SubjectPKI[Pos],
                                                   &Ignored,
                                                   &Temp );

               Pos += Temp;
            }

            if ( Swt_RC_OK == RetVal )
            {
               /* Now we must be at the start of the DER encoding of the      */
               /* modulus. Extract the modulus from the encoding.             */
               RetVal = Swt_DEREncodingExtractInteger ( &SubjectPKI[Pos],
                                                          &Temp,
                                                          Modulus );

               Pos += Temp;
            }

            if ( Swt_RC_OK == RetVal )
            {
               /* Now we must be at the start of the DER encoding of the      */
               /* exponent. Extract the exponent from the encoding.           */
               RetVal = Swt_DEREncodingExtractInteger ( &SubjectPKI[Pos],
                                                          &Temp,
                                                          Exponent );

               Pos += Temp;
            }

            Element++;
            break;

         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   *SubjectPKILengthPtr = Pos;

   return RetVal;
}






/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DEREncodingExtractInteger                           **
**                                                                            **
** DESCRIPTION    : Get a DER encoded integer and store it in 'Integer' in    **
**                  long number format.                                       **
**                                                                            **
** PRECONDITIONS  : 'DEREncoding' is a valid pointer (not checked)            **
**                  'DEREncodingLengthPtr' is a valid pointer (not checked)   **
**                  'Integer' is a valid pointer (not checked)                **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'DEREncodingLengthPtr'         **
**                  contains the length of the DER encoding of the value.     **
**                  'Integer' contains the integer in long number format.     **
**                                                                            **
** PARAMETERS     : DEREncoding : A pointer to the start of a byte array      **
**                               which contains the DER encoding of a value   **
**                  DEREncodingLengthPtr: A pointer to a variable which will  **
**                                        hold the length of the encoding     **
**                  Integer: A pointer to the start of an array which will    **
**                           store the extracted integer.                     **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the DER encoding could not be   **
**                                         parsed                             **
**                  Swt_RC_OK, if the integer could be extracted            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_DEREncodingExtractInteger
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)          DEREncoding,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)           DEREncodingLengthPtr,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Integer
)
{
   SwtRC_t             RetVal;
   uint16                Pos;
   uint16                Length;

   /* Get to the start of the integer and get its length. */
   RetVal = Swt_DEREncodingGetInfo ( DEREncoding, &Length, &Pos );

   *DEREncodingLengthPtr = Pos + Length;

   /* An integer can start with a zero byte. If this is the case, skip it. */
   if( 0x00 == DEREncoding[Pos])
   {
      Pos++;
      Length--;
   }

   /* Convert the integer to long number format and store it in 'Integer'. */
   Swt_LNByteArrayToNumber
   (
      &DEREncoding[Pos],
      Length,
      Integer
   );

   return RetVal;
}







/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_SubjectExtract                                      **
**                                                                            **
** DESCRIPTION    : Extract the subject value from the given encoding of the  **
**                  subject.                                                  **
**                                                                            **
** PRECONDITIONS  : 'Subject' is a valid pointer (not checked)                **
**                  'SubjectLengthPtr' is a valid pointer (not checked)       **
**                  'SubjectValue' is a valid pointer (not checked)           **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'SubjectLengthPtr'             **
**                  contains the length of the encoding of the subject.       **
**                  '*SubjectPtr' contains the start address of an array      **
**                                contains the subject of the certificate.    **
**                                                                            **
** PARAMETERS     : Subject : A pointer to the start of a byte array which    **
**                           contains the DER encoding of the subject         **
**                  SubjectLengthPtr: A pointer to a variable which will hold **
**                                   the length of the encoding               **
**                  SubjectPtr : A pointer to a variable which will store the **
**                               start address of an array which contains the **
**                               subject.                                     **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the subject could not be parsed **
**                  Swt_RC_OK, if the subject could be extracted            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_SubjectExtract
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                         Subject,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)                          SubjectLengthPtr,
  CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) SubjectPtr
)
{
   SwtRC_t RetVal;                      /* The return value of the function */
   uint16    Pos;      /* the current position in the encoding of the subject */
   uint16    Length;                             /* the length of the subject */


   /* Get the start of the subject value in 'Pos'. */
   RetVal = Swt_DEREncodingGetInfo ( Subject, &Length, &Pos );

   *SubjectLengthPtr = Pos + Length;

   if(Swt_RC_OK == RetVal)
   {

      /* Extract the start address of the subject value. */
      *SubjectPtr = &Subject[Pos];
   }

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_SerialNrExtract                                     **
**                                                                            **
** DESCRIPTION    : Extract the serial number from the given encoding.        **
**                                                                            **
** PRECONDITIONS  : 'SerialNr' is a valid pointer (not checked)               **
**                  'SerialNrLengthPtr' is a valid pointer (not checked)      **
**                  'SerialNrValue' is a valid pointer (not checked)          **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'SerialNrLengthPtr'            **
**                  contains the length of the encoding of the serial number. **
**                  The array pointed to by 'SerialNrValue' contains the      **
**                  serial number.                                            **
**                                                                            **
** PARAMETERS     : SerialNr : A pointer to the start of a byte array which   **
**                           contains the DER encoding of the serial number   **
**                  SerialNrLengthPtr: A pointer to a variable which will hold**
**                                   the length of the encoding               **
**                  SerialNrValue : A pointer to the start of an array        **
**                                    where the serial number will be copied  **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the encoding could not be       **
**                        parsed or the serial number is too long             **
**                  Swt_RC_OK, if the serial number could be extracted      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_SerialNrExtract
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SerialNr,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  SerialNrLengthPtr,
  CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)   SerialNrValue
)
{
   SwtRC_t RetVal;                      /* The return value of the function */
   uint16    Pos; /* the current position in the encoding of the serial number*/
   uint16    Length;                       /* the length of the serial number */
   uint16    NrOfPadBytes;                /* the number of padding zero bytes */
   uint16    i;                                               /* loop counter */


   /* Get the start of the serial number value in 'Pos'. */
   RetVal = Swt_DEREncodingGetInfo ( SerialNr, &Length, &Pos );

   *SerialNrLengthPtr = Pos + Length;

   if(Swt_RC_OK == RetVal)
   {

      /* The serial number is encoded as an integer. An integer can start     */
      /* with a zero byte. If this is the case, skip it.                      */
      if( 0x00 == SerialNr[Pos])
      {
         Pos++;
         Length--;
      }

      /* The serial number must be SWT_FSCSID_LEN bytes long. If the given  */
      /* serial number is shorter, it is padded with zero bytes at the        */
      /* beginning. If it is longer, the certificate is invalid.              */
      if ( (uint16)SWT_FSCSID_LEN >= Length )
      {
         NrOfPadBytes = (uint16)SWT_FSCSID_LEN - Length;

         for ( i = 0; i < NrOfPadBytes ; i++ )
         {
            SerialNrValue[i] = 0;
         }

         /* Copy the serial number to the return buffer. */
         (void)Swt_CommonCopy( &SerialNrValue[NrOfPadBytes],
                                 &SerialNr[Pos],
                                 (uint32)Length );

      }
      else
      {
         RetVal = Swt_RC_CERT_INVALID;
      }
   }

   return RetVal;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ValidityExtract                                     **
**                                                                            **
** DESCRIPTION    : Extract the start date and end date of the validity       **
**                  period.                                                   **
**                                                                            **
** PRECONDITIONS  : 'Validity' is a valid pointer (not checked)               **
**                  'ValidityLengthPtr' is a valid pointer (not checked)      **
**                  'StartDatePtr' is a valid pointer (not checked)           **
**                  'EndDatePtr' is a valid pointer (not checked)             **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'ValidityLengthPtr' contains   **
**                  the length of the encoding of the validity field.         **
**                  The variable pointed to by 'StartDatePtr' contains the    **
**                  start date of the validity period of the certificate.     **
**                  The variable pointed to by 'EndDatePtr' contains the      **
**                  end date of the validity period of the certificate.       **
**                                                                            **
** PARAMETERS     : Validity : A pointer to the start of a byte array which   **
**                           contains the DER encoding of the validity field  **
**                  ValidityLengthPtr: A pointer to a variable which will     **
**                                     hold the length of the encoding        **
**                  StartDatePtr : A pointer to a variable where the start    **
**                                 date of the validity period (given in      **
**                                 minutes since 2000/01/01) will be stored.  **
**                  EndDatePtr : A pointer to a variable where the end        **
**                               date of the validity period (given in        **
**                               minutes since 2000/01/01) will be stored.    **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed                             **
**                  Swt_RC_OK, if the validity could be extracted           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ValidityExtract
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Validity,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ValidityLengthPtr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)  StartDatePtr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)  EndDatePtr
)
{
   SwtRC_t            RetVal;           /* the return value of the function */
   Swt_ValidityType   Element; /* the current element of the Validity field */
   uint16               Pos;    /* the current position in the validity field */
   uint16               Length;                      /* the length of a value */
   uint16               ValueSkip;                 /* amount of bytes to skip */
   Swt_DateType       DateType;            /* the type of the date encoding */

   /* The Validity field is a DER encoded sequence containing the start date  */
   /* and the end date. We get the starting position of the first element of  */
   /* the sequence in "Pos".                                                  */
   RetVal = Swt_DEREncodingGetInfo ( Validity, &Length, &Pos );

   /* The first element of the Validity field is the start date. */
   Element = SWT_CERT_VALID_NOT_BEFORE;

   /* Go through all elements of the validity field and extract start and end */
   /* date and until the end has been reached or an error has been            */
   /* encountered.                                                            */
   while ( ( Element < SWT_CERT_VALID_END ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      switch ( Element )
      {
         case SWT_CERT_VALID_NOT_BEFORE:
            /* The tag of the encoding contains the date type (UTC or         */
            /* Generalized time.                                              */
            DateType = (Swt_DateType)Validity[Pos];

            /* Skip to the start of the date value. */
            RetVal = Swt_DEREncodingGetInfo ( &Validity[Pos],
                                                &Length,
                                                &ValueSkip );
            Pos += ValueSkip;

            /* Extract the start date. */
            *StartDatePtr = Swt_DateGet ( &Validity[Pos], DateType );
            Pos += Length;
            Element++;
            break;

         case SWT_CERT_VALID_NOT_AFTER:
            /* The tag of the encoding contains the date type (UTC or         */
            /* Generalized time.                                              */
            DateType = (Swt_DateType)Validity[Pos];

            /* Skip to the start of the date value. */
            RetVal = Swt_DEREncodingGetInfo ( &Validity[Pos],
                                                &Length,
                                                &ValueSkip );
            Pos += ValueSkip;

            /* Extract the end date. */
            *EndDatePtr = Swt_DateGet ( &Validity[Pos], DateType );
            Pos += Length;
            Element++;
            break;

         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   *ValidityLengthPtr = Pos;

   return RetVal;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_TBSCertCheck                                        **
**                                                                            **
** DESCRIPTION    : Check the validity of a given TBSCertificate. The issuer  **
**                  must be identical to the subject of the root certificate, **
**                  its extension field must be valid, and the start and end  **
**                  dates given in the validity field must include the        **
**                  current date.                                             **
**                                                                            **
**                                                                            **
** PRECONDITIONS  : 'TBSCert' is a valid pointer (not checked)                **
**                  'TBSCertLengthPtr' is a valid pointer (not checked)       **
**                  'RootCertSubject' is a valid pointer (not checked)        **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'TBSCertLengthPtr'             **
**                  contains the length of the TBSCertificate.                **
**                                                                            **
** PARAMETERS     : TBSCert : A pointer to the start of a byte array          **
**                            which contains the TBSCertificate               **
**                  TBSCertLengthPtr: A pointer to a variable which will      **
**                                    hold the length of the TBSCertificate   **
**                  RootCertSubject : A pointer to the start of an array      **
**                                    which contains the subject of the root  **
**                                    certficate                              **
**                  CertType : The type of the given certificate:             **
**                             0x01 - SigS certificate                        **
**                             0x02 - FSCS certificate                        **
**                  Date: The current date (given in minutes since 2000/01/01)**
**                        or 0. If the date is not zero, the validity field   **
**                        of the certificate must be checked against this     **
**                        date.                                               **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed or the date is invalid      **
**                  Swt_RC_WRONG_CERT_CONTENT_ISSUER, if the issuer is not  **
**                          identical to the subject of the root certificate  **
**                  Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM, if the extension   **
**                                   is not valid for the given certificate   **
**                  Swt_RC_OK, if the check succeeded                       **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_TBSCertCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) TBSCert,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  TBSCertLengthPtr,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) RootCertSubject,
  const Swt_CertType                 CertType,
  const uint32                         Date
)
{
   SwtRC_t            RetVal;           /* the return value of the function */
   Swt_TBSElementType Element; /* the current element of the TBSCertificate */
   uint16               ElementLength;   /* the length of the current element */
   uint16               Pos;    /* the current position in the TBSCertificate */
   uint16               Length;           /* The length of the TBSCertificate */

   /* The TBSCertificate is a DER encoded sequence. We get the starting       */
   /* position of the first element of the sequence in "Pos".                 */
   RetVal = Swt_DEREncodingGetInfo ( TBSCert, &Length, &Pos );

   /* Compute the length of the TBSCertificate. */
   *TBSCertLengthPtr = Length + Pos;

   /* The first element of TBSCertificate is the version. */
   Element = SWT_CERT_TBS_VERSION;

   /* Go through all elements of TBSCertificate and check some of them until  */
   /* the end has been reached or an error has been encountered.              */
   while ( ( ( Element < SWT_CERT_TBS_END ) &&
             ( Swt_RC_OK == RetVal ) )      &&
             ( Pos < *TBSCertLengthPtr ) )
   {
      switch ( Element )
      {
         case SWT_CERT_TBS_VERSION:
         case SWT_CERT_TBS_SERIALNUMBER:
         case SWT_CERT_TBS_SIGNATURE:
         case SWT_CERT_TBS_SUBJECT:
         case SWT_CERT_TBS_SUBJECTPKI:
            /* Do not check these elements of TBSCertificate. Simply skip     */
            /* them.                                                          */
            RetVal = Swt_DEREncodingSkip ( &TBSCert[Pos], &ElementLength );
            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_TBS_ISSUER:
            /* Check that the issuer is the same as the subject of the root   */
            /* certificate.                                                   */
            RetVal = Swt_IssuerCheck ( &TBSCert[Pos],
                                         &ElementLength,
                                         RootCertSubject );
            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_TBS_VALIDITY:
            RetVal = Swt_ValidityCheck ( &TBSCert[Pos],
                                           &ElementLength,
                                           Date );
            Pos += ElementLength;
            Element++;
            break;

         case SWT_CERT_TBS_EXTENSIONS:
            /* Check the extensions. */
            RetVal = Swt_ExtensionsCheck ( &TBSCert[Pos],
                                             &ElementLength,
                                             CertType );
            Pos += ElementLength;
            Element++;
            break;

         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* If we did not parse the TBSCertificate exactly to the last byte or   */
      /* if we did not find all elements, the TBSCertificate is invalid.      */
      if ( ( Pos != *TBSCertLengthPtr ) || ( Element != SWT_CERT_TBS_END ) )
      {
         RetVal = Swt_RC_CERT_INVALID;
      }
   }

   return RetVal;
}






/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_IssuerCheck                                         **
**                                                                            **
** DESCRIPTION    : Check that the given issuer is identical to the given     **
**                  subject of a root certificate.                            **
**                                                                            **
** PRECONDITIONS  : 'Issuer' is a valid pointer (not checked)                 **
**                  'IssuerLengthPtr' is a valid pointer (not checked)        **
**                  'RootCertSubject' is a valid pointer (not checked)        **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'IssuerLengthPtr'              **
**                  contains the length of the encoding of the issuer.        **
**                                                                            **
** PARAMETERS     : Issuer : A pointer to the start of a byte array which     **
**                           contains the DER encoding of the issuer          **
**                  IssuerLengthPtr: A pointer to a variable which will hold  **
**                                   the length of the encoding               **
**                  RootCertSubject : A pointer to the start of an array      **
**                                    which contains the subject of the root  **
**                                    certficate                              **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the issuer could not be parsed  **
**                  Swt_RC_WRONG_CERT_CONTENT_ISSUER, if the issuer is not  **
**                          identical to the subject of the root certificate  **
**                  Swt_RC_OK, if the encoding could be skipped             **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_IssuerCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Issuer,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  IssuerLengthPtr,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) RootCertSubject
)
{
   SwtRC_t RetVal;                      /* The return value of the function */
   uint16    Pos;       /* the current position in the encoding of the issuer */
   uint16    Length;                              /* the length of the issuer */


   /* Get the start of the issuer in 'Pos'. */
   RetVal = Swt_DEREncodingGetInfo ( Issuer, &Length, &Pos );

   *IssuerLengthPtr = Pos + Length;

   if(Swt_RC_OK == RetVal)
   {
      /* Compare the issuer with the subject of the root certificate. */
      if( Swt_RC_EQUAL !=
          Swt_CommonCompare( &Issuer[Pos],
                               RootCertSubject,
                               (uint32)Length ) )
      {
         RetVal = Swt_RC_WRONG_CERT_CONTENT_ISSUER;
      }
   }

   return RetVal;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ExtensionsCheck                                     **
**                                                                            **
** DESCRIPTION    : Check that given certificate extensions are valid for     **
**                  the given certificate type.                               **
**                                                                            **
** PRECONDITIONS  : 'Extensions' is a valid pointer (not checked)             **
**                  'ExtensionsLengthPtr' is a valid pointer (not checked)    **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'ExtensionsLengthPtr'          **
**                  contains the length of the encoding of the exentsions.    **
**                                                                            **
** PARAMETERS     : Extensions : A pointer to the start of a byte array which **
**                           contains the DER encoding of the extensions      **
**                  ExtensionsLengthPtr: A pointer to a variable which will   **
**                                       hold the length of the encoding      **
**                  CertType : The type of the given certificate:             **
**                             0x01 - SigS certificate                        **
**                             0x02 - FSCS certificate                        **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the extensions could not be     **
**                                         parsed                             **
**                  Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM, if the extensions  **
**                                   are not valid for the given certificate  **
**                  Swt_RC_OK, if the extensions are valid                  **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ExtensionsCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Extensions,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ExtensionsLengthPtr,
  const Swt_CertType                 CertType
)
{
   SwtRC_t RetVal;                      /* The return value of the function */
   uint16    Pos;   /* the current position in the encoding of the extensions */
   uint16    Length;                                 /* the length of a value */
   uint16    ValueSkip;    /* the amount of bytes to skip to get to the value */

   /* The extensions field is a tagged sequence type. First get to the start  */
   /* of the encoding of the sequence. The tag must be skipped for that.      */
   RetVal = Swt_DEREncodingGetInfo ( Extensions, &Length, &Pos );

   *ExtensionsLengthPtr = Pos + Length;

   if ( Swt_RC_OK == RetVal )
   {
      /* Now, we are at the start of the encoding of the sequence. Skip to    */
      /* the real start of the sequence.                                      */
      RetVal = Swt_DEREncodingGetInfo ( Extensions, &Length, &ValueSkip );
      Pos += ValueSkip;
   }

   /* Step over each element of the sequence until all elements are done or   */
   /* we have encountered an error.                                           */
   while ( ( Pos < *ExtensionsLengthPtr ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      /* Each element of the sequence is a single extension field. We check   */
      /* it.                                                                  */
      RetVal = Swt_ExtensionCheck ( &Extensions[Pos],
                                      &Length,
                                      CertType );

      Pos += Length;
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* If we did not parse the extensions exactly to the last byte, the     */
      /* extensions field is invalid.                                         */
      if ( Pos != *ExtensionsLengthPtr )
      {
         RetVal = Swt_RC_CERT_INVALID;
      }
   }

   return RetVal;
}







/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ExtensionCheck                                      **
**                                                                            **
** DESCRIPTION    : Check that a given certificate extension is valid for the **
**                  given certificate type. It is invalid if it is critical   **
**                  but not an extended key usage field. It is invalid if it  **
**                  is a basic constraint. It is invalid if it is an extended **
**                  key usage field but not critical. If it is an extended    **
**                  key usage field and critical, it must be checked further. **
**                                                                            **
** PRECONDITIONS  : 'Extension' is a valid pointer (not checked)              **
**                  'ExtensionLengthPtr' is a valid pointer (not checked)     **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'ExtensionLengthPtr'           **
**                  contains the length of the encoding of the exentsions.    **
**                                                                            **
** PARAMETERS     : Extension : A pointer to the start of a byte array which  **
**                           contains the DER encoding of an extension        **
**                  ExtensionLengthPtr: A pointer to a variable which will    **
**                                      hold the length of the encoding       **
**                  CertType : The type of the given certificate:             **
**                             0x01 - SigS certificate                        **
**                             0x02 - FSCS certificate                        **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the extension could not be      **
**                                         parsed                             **
**                  Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM, if the extension   **
**                                   is not valid for the given certificate   **
**                  Swt_RC_OK, if the extension is valid                    **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ExtensionCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Extension,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ExtensionLengthPtr,
  const Swt_CertType                 CertType
)
{
   SwtRC_t           RetVal;            /* the return value of the function */
   Swt_ExtensionType Element;       /* the current element of the extension */
   uint16              Pos;          /* the current position in the extension */
   uint16              Length;                       /* the length of a value */
   uint16              ValueSkip;    /* the bytes to skip to get to the value */
   boolean             Critical;               /* is this extension critical? */
   boolean             IsKeyUsage;    /* is this an extended key usage field? */

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"

   /* the OID for basic constraints */
   SWT_STATIC_VAR const uint8 OIDBasicConstraints[] = { 0x55, 0x1d, 0x13 };
   /* the OID for the extended key usage field */
   SWT_STATIC_VAR const uint8 OIDKeyUsage[]         = { 0x55, 0x1d, 0x25 };

#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


   /* Initialize some values. */
   IsKeyUsage = FALSE;
   Critical = TRUE;

   /* The extension is a DER encoded sequence. We get the starting position   */
   /* of the first element of the sequence in "Pos".                          */
   RetVal = Swt_DEREncodingGetInfo ( Extension, &Length, &Pos );

   /* Compute the length of the encoded extension. */
   *ExtensionLengthPtr = Length + Pos;

   /* The first element of of the extension is the extension ID. */
   Element = SWT_CERT_EXTENSION_ID;

   /* We go through all elements of the extension until we are at the end or  */
   /* an error has been encountered.                                          */
   while ( ( ( Element < SWT_CERT_EXTENSION_END ) &&
             ( Swt_RC_OK == RetVal ) )            &&
             ( Pos < *ExtensionLengthPtr ) )
   {
      switch ( Element )
      {
         case SWT_CERT_EXTENSION_ID:
            /* We are at the extension ID. */

            /* Go to the value of the ID.*/
            RetVal = Swt_DEREncodingGetInfo ( &Extension[Pos],
                                                &Length,
                                                &ValueSkip );
            Pos += ValueSkip;

            if( Swt_RC_EQUAL ==
                Swt_CommonCompare( &Extension[Pos],
                                     OIDBasicConstraints,
                                     (uint32)Length ) )
            {
               /* This is a basic constraint. Those are not allowed. */
               RetVal = Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM;
            }
            else if( Swt_RC_EQUAL ==
                     Swt_CommonCompare( &Extension[Pos],
                                          OIDKeyUsage,
                                          (uint32)Length ) )
            {
               /* This is an extended key usage field. */
               IsKeyUsage = TRUE;
            }
            else
            {
               /* This is not an extension we know. */
               IsKeyUsage = FALSE;
            }

            Pos += Length;
            Element++;
            break;

         case SWT_CERT_EXTENSION_CRITICAL:
            /* We are at the criticality field. */

            /* Get to the criticality value. */
            RetVal = Swt_DEREncodingGetInfo ( &Extension[Pos],
                                                &Length,
                                                &ValueSkip );
            Pos += ValueSkip;

            if ( 0 == Extension[Pos] )
            {
               /* This extension is marked as not critical. */
               Critical = FALSE;
            }
            else
            {
               /* This extension is marked as critical. */
               Critical = TRUE;
            }

            Pos += Length;
            Element++;
            break;

         case SWT_CERT_EXTENSION_VALUE:
            /* We are at the extension value. */

            /* Is this an extended key usage field? */
            if ( TRUE == IsKeyUsage )
            {
               /* Is this extened key usage field marked as critical? */
               if ( TRUE == Critical )
               {
                  /* Check the extended key usage field further. */
                  RetVal = Swt_KeyUsageCheck ( &Extension[Pos],
                                                 &ValueSkip,
                                                 CertType );

                  Pos += ValueSkip;
               }
               else
               {
                  /* An extended key usage field must be marked as critical. */
                  RetVal = Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM;
               }
            }
            else
            {
               /* This is an extension we do not know. It must not be marked  */
               /* as critical.                                                */
               if ( TRUE == Critical )
               {
                  RetVal = Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM;
               }
               else
               {
                  /* We can skip the extension. */
                  RetVal = Swt_DEREncodingSkip ( &Extension[Pos],
                                                   &ValueSkip );
                  Pos += ValueSkip;
               }
            }

            Element++;
            break;

         default:
            RetVal = Swt_RC_UNKNOWN_ERROR;
            break;
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* If we did not parse the extension exactly to the last byte or if     */
      /* we did not find all elements, the certificate is invalid.            */
      if( ( Pos != *ExtensionLengthPtr ) ||
          ( Element != SWT_CERT_EXTENSION_END ) )
      {
         RetVal = Swt_RC_CERT_INVALID;
      }
   }

   return RetVal;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_KeyUsageCheck                                       **
**                                                                            **
** DESCRIPTION    : Check that a given extended key usage field is valid for  **
**                  the given certificate type.                               **
**                                                                            **
** PRECONDITIONS  : 'KeyUsage' is a valid pointer (not checked)               **
**                  'KeyUsageLengthPtr' is a valid pointer (not checked)      **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'KeyUsageLengthPtr' contains   **
**                  the length of the encoding of the key usag field.         **
**                                                                            **
** PARAMETERS     : KeyUsage : A pointer to the start of a byte array which   **
**                           contains the DER encoding of the key usage field **
**                  KeyUsageLengthPtr: A pointer to a variable which will     **
**                                     hold the length of the encoding        **
**                  CertType : The type of the given certificate:             **
**                             0x01 - SigS certificate                        **
**                             0x02 - FSCS certificate                        **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the extension could not be      **
**                                         parsed                             **
**                  Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM, if the key usage   **
**                          field is not valid for the given certificate type **
**                  Swt_RC_OK, if the key usage field is valid              **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_KeyUsageCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) KeyUsage,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  KeyUsageLengthPtr,
  const Swt_CertType                 CertType
)
{
   SwtRC_t RetVal;                      /* The return value of the function */
   uint16    Pos;    /* the current position in the encoding of the key usage */
   uint16    Length;                                 /* the length of a value */
   uint16    ValueSkip;    /* the amount of bytes to skip to get to the value */

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"

   /* the OID for code signing */
   SWT_STATIC_VAR const uint8 OIDCodeSigning[] = { 0x06, 0x08, 0x2B, 0x06,
                                                     0x01, 0x05, 0x05, 0x07,
                                                     0x03, 0x03 };
   /* the OID for FSC signing */
   SWT_STATIC_VAR const uint8 OIDFSCSigning[]  = { 0x06, 0x0A, 0x2B, 0x06,
                                                     0x01, 0x04, 0x01, 0x84,
                                                     0x01, 0x0A, 0x01, 0x01 };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


   /* The extended key usage field is a sequence of key usages. Get the start */
   /* of the first key usage in 'Pos'.                                        */
   RetVal = Swt_DEREncodingGetInfo ( KeyUsage, &Length, &Pos );

   /* Compute the length of the key usage field. */
   *KeyUsageLengthPtr = Pos + Length;

   /* Go through all key usages until the end has been reached or we have     */
   /* encountered an error.                                                   */
   while ( ( Pos < *KeyUsageLengthPtr ) &&
           ( Swt_RC_OK == RetVal ) )
   {
      /* Skip past the start of the encoding of the key usage. */
      RetVal = Swt_DEREncodingGetInfo ( &KeyUsage[Pos],
                                          &Length,
                                          &ValueSkip );

      Pos += ValueSkip;

      if ( Swt_RC_OK == RetVal )
      {
         /* Which certificate type do we have? */
         switch ( CertType )
         {
            case SWT_CERT_TYPE_SIGS:
               /* This is a SigS certificate. */


               if( Swt_RC_EQUAL !=
                   Swt_CommonCompare( &KeyUsage[Pos],
                                        OIDCodeSigning,
                                        (uint32)Length ) )
               {
                  /* The extended key usage is not for code signing. This is  */
                  /* not allowed.                                             */
                  RetVal = Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM;
               }
               break;

            case SWT_CERT_TYPE_FSCS:
               /* This is a FSCS certificate. */

               if( Swt_RC_EQUAL !=
                   Swt_CommonCompare( &KeyUsage[Pos],
                                        OIDFSCSigning,
                                        (uint32)Length ) )
               {
                  /* The extended key usage is not for FSC signing. This is   */
                  /* not allowed.                                             */
                  RetVal = Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM;
               }
               break;

            default:
               RetVal = Swt_RC_UNKNOWN_ERROR;
         }
      }

      Pos += Length;
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* If we did not parse the key usage field exactly to the last byte,    */
      /* the certificate is invalid.                                          */
      if( Pos != *KeyUsageLengthPtr )
      {
         RetVal = Swt_RC_CERT_INVALID;
      }
   }

   return RetVal;
}





/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ValidityCheck                                       **
**                                                                            **
** DESCRIPTION    : If the given date is not zero, check that the given       **
**                  validity field includes the given date. Otherwise, just   **
**                  parse the validity field.                                 **
**                                                                            **
** PRECONDITIONS  : 'Validity' is a valid pointer (not checked)               **
**                  'ValidityLengthPtr' is a valid pointer (not checked)      **
**                                                                            **
** POSTCONDITIONS : The variable pointed to by 'ValidityLengthPtr' contains   **
**                  the length of the encoding of the validity field.         **
**                                                                            **
** PARAMETERS     : Validity : A pointer to the start of a byte array which   **
**                           contains the DER encoding of the validity field  **
**                  ValidityLengthPtr: A pointer to a variable which will     **
**                                     hold the length of the encoding        **
**                  Date: The current date (given in minutes since 2000/01/01)**
**                        or 0. If the date is not zero, the validity field   **
**                        of the certificate must be checked against this     **
**                        date.                                               **
**                                                                            **
** RETURN         : Swt_RC_CERT_INVALID, if the certificate could not be    **
**                                         parsed or the date is invalid      **
**                  Swt_RC_OK, if the validity field is valid               **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ValidityCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Validity,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  ValidityLengthPtr,
  const uint32                         Date
)
{
   SwtRC_t            RetVal;           /* the return value of the function */
   uint32               StartDate;        /* the start of the validity period */
   uint32               EndDate;            /* the end of the validity period */


   RetVal = Swt_ValidityExtract ( Validity,
                                    ValidityLengthPtr,
                                    &StartDate,
                                    &EndDate );

   if ( Swt_RC_OK == RetVal )
   {
      /* Do we have to check the validity field? */
      if ( 0 != Date )
      {
         /* Is the current date before the start date or after the end date? */
         if ( ( StartDate > Date ) || ( EndDate < Date ) )
         {
            /* The certificate is not valid at the current date. */
            RetVal = Swt_RC_CERT_INVALID;
         }
      }
   }

   return RetVal;
}

#define SWT_STOP_SEC_CODE
#include "MemMap.h"





/*** End of file **************************************************************/
