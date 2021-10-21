/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Certificate.h                                           **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Routines to handle DER encoded X.509 v3 certificates          **
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

#if (!defined SWT_CERTIFICATE_H)
#define SWT_CERTIFICATE_H

/*******************************************************************************
**                      inclusions                                            **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */

#include "Swt_RSA.h"                                /* long number routines */

/*******************************************************************************
**                      macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      type definitions                                      **
*******************************************************************************/

/* The type of the certificate. The values are consistent with the values     */
/* used as arguments of the functions Swt_StoreCert and Swt_CheckCert.    */
typedef enum
{
  SWT_CERT_TYPE_SIGS = 0x01,                          /* a SigS certificate */
  SWT_CERT_TYPE_FSCS = 0x02,                         /* an FSCS certificate */
  SWT_CERT_TYPE_ROOT = 0x03                           /* a root certificate */
}
Swt_CertType;


/*******************************************************************************
**                      external function declarations                        **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

extern SwtRC_t Swt_CertCheck
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            Cert,
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            RootCertSubject,
  CONSTP2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) PublicKeyPtr,
  const Swt_CertType                            CertType,
  const uint32                                    Date
);

extern SwtRC_t Swt_CertExtractRootValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                         Cert,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)                Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR)                Exponent,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) SubjectPtr
);

extern SwtRC_t Swt_CertExtractFSCSValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)          Cert,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Modulus,
   CONSTP2VAR(Swt_LNWordType,AUTOMATIC,SC_FAR) Exponent,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)            SerialNr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)           StartDatePtr,
   CONSTP2VAR(uint32,AUTOMATIC,SC_FAR)           EndDatePtr
);

extern SwtRC_t Swt_CertExtractSigSValues
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Cert,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)   SerialNr
);

extern SwtRC_t Swt_CertGetLength
(
  CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Cert,
  CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)  CertLengthPtr
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

#endif /* if (!defined SWT_CERTIFICATE_H) */
/*** End of file **************************************************************/
