/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_FSC.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Declaration of FSC services, i.e. the representation of a FSC **
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
 * V2.0.0    : 04.04.2007, mg   : made different signature lengths for FSCs and
 *                                certificates possible
 * V2.1.0    : 01.09.2007, djk  : Modified parameter of Swt_FSCCheckSWID
 */

#if (!defined SWT_FSC_H)               /* preprocessor exclusion definition */
#define SWT_FSC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */

#include "Swt_RSA.h"                                        /* RSA routines */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

                               /* list of guards to prevent double definition */
#if (defined SWT_VERSION_LEN)
   #error SWT_VERSION_LEN already defined
#endif                                /* if (defined SWT_VERSION_LEN) */

#if (defined SWT_FSC_VERSION)
   #error SWT_FSC_VERSION already defined
#endif                                   /* if (defined SWT_FSC_VERSION) */

#if (defined SWT_SWID_TYPE)
   #error SWT_SWID_TYPE already defined
#endif                                     /* if (defined SWT_SWID_TYPE) */

#if (defined SWT_SWID_LEN)
   #error SWT_SWID_LEN already defined
#endif                                   /* if (defined SWT_SWID_LEN) */

#if (defined SWT_APP_NUMBER_LEN)
   #error SWT_APP_NUMBER_LEN already defined
#endif                             /* if (defined SWT_APP_NUMBER_LEN) */

#if (defined SWT_UPGRADE_INDEX_LEN)
   #error SWT_UPGRADE_INDEX_LEN already defined
#endif                          /* if (defined SWT_UPGRADE_INDEX_LEN) */

#if (defined SWT_SWID_POSITION)
   #error SWT_SWID_POSITION already defined
#endif                                 /* if (defined SWT_SWID_POSITION) */

#if (defined SWT_SWID_SHORT_POSITION)
   #error SWT_SWID_SHORT_POSITION already defined
#endif

#if (defined SWT_SUPPLIER_NUMBER_LEN)
   #error SWT_SUPPLIER_NUMBER_LEN already defined
#endif                        /* if (defined SWT_SUPPLIER_NUMBER_LEN) */

#if (defined SWT_REQUESTER_TYPE_LEN)
   #error SWT_REQUESTER_TYPE_LEN already defined
#endif                         /* if (defined SWT_REQUESTER_TYPE_LEN) */

#if (defined SWT_REQUESTER_TYPE_POSITION)
   #error SWT_REQUESTER_TYPE_POSITION already defined
#endif                       /* if (defined SWT_REQUESTER_TYPE_POSITION) */

#if (defined SWT_REQUESTER_TYPE_FACTORY)
   #error SWT_REQUESTER_TYPE_FACTORY already defined
#endif                        /* if (defined SWT_REQUESTER_TYPE_FACTORY) */

#if (defined SWT_REQUESTER_TYPE_TRADER)
   #error SWT_REQUESTER_TYPE_TRADER already defined
#endif                         /* if (defined SWT_REQUESTER_TYPE_TRADER) */

#if (defined SWT_ORDER_NUMBER_LEN)
   #error SWT_ORDER_NUMBER_LEN already defined
#endif                           /* if (defined SWT_ORDER_NUMBER_LEN) */

#if (defined SWT_REQ_FACTORY_ID_LEN)
   #error SWT_REQ_FACTORY_ID_LEN already defined
#endif                         /* if (defined SWT_REQ_FACTORY_ID_LEN) */

#if (defined SWT_REQ_TRADER_ID_LEN)
   #error SWT_REQ_TRADER_ID_LEN already defined
#endif                          /* if (defined SWT_REQ_TRADER_ID_LEN) */

#if (defined SWT_REQ_ID_LEN)
   #error SWT_REQ_ID_LEN already defined
#endif                                 /* if (defined SWT_REQ_ID_LEN) */

#if (defined SWT_INDIV_TYPE_LEN)
   #error SWT_INDIV_TYPE_LEN already defined
#endif                             /* if (defined SWT_INDIV_TYPE_LEN) */

#if (defined SWT_INDIV_SHORT_VIN_LEN)
   #error SWT_INDIV_SHORT_VIN_LEN already defined
#endif                        /* if (defined SWT_INDIV_SHORT_VIN_LEN) */

#if (defined SWT_INDIV_SHORT_VIN)
   #error SWT_INDIV_SHORT_VIN already defined
#endif                               /* if (defined SWT_INDIV_SHORT_VIN) */

#if (defined SWT_VALID_CONDITION_LEN)
   #error SWT_VALID_CONDITION_LEN already defined
#endif                        /* if (defined SWT_VALID_CONDITION_LEN) */

#if (defined SWT_FSCSID_LEN)
   #error SWT_FSCSID_LEN already defined
#endif                                 /* if (defined SWT_FSCSID_LEN) */

#if (defined SWT_DATE_LEN)
   #error SWT_DATE_LEN already defined
#endif                                   /* if (defined SWT_DATE_LEN) */

#if (defined SWT_ADD_FIELD_LEN)
   #error SWT_ADD_FIELD_LEN already defined
#endif                              /* if (defined SWT_ADD_FIELD_LEN) */

#if (defined SWT_ADD_FIELD)
   #error SWT_ADD_FIELD already defined
#endif                                     /* if (defined SWT_ADD_FIELD) */

#if (defined SWT_SIGNATURE_LEN)
   #error SWT_SIGNATURE_LEN already defined
#endif                              /* if (defined SWT_SIGNATURE_LEN) */

#if (defined SWT_FSC_MIN_LEN)
   #error SWT_FSC_MIN_LEN already defined
#endif                                /* if (defined SWT_FSC_MIN_LEN) */

#if (defined SWT_FSC_MAX_LEN)
   #error SWT_FSC_MAX_LEN already defined
#endif                                /* if (defined SWT_FSC_MAX_LEN) */

#if (defined SWT_FSC_SHORT_MAX_LEN)
   #error SWT_FSC_SHORT_MAX_LEN already defined
#endif                                /* if (defined SWT_FSC_SHORT_MAX_LEN) */

                           /* the version numbers of the supported FSC format */
#define SWT_VERSION_LEN   1U
#define SWT_FSC_VERSION   0x01U


                          /* the swid type number of the supported FSC format */
#define SWT_SWID_TYPE_LEN 1U
#define SWT_SWID_TYPE     0x01U

                                                   /* the supported SWID type */
#define SWT_APP_NUMBER_LEN 2U
#define SWT_UPGRADE_INDEX_LEN 2U
#define SWT_SWID_LEN (SWT_APP_NUMBER_LEN + SWT_UPGRADE_INDEX_LEN)

#define SWT_SWID_POSITION  \
            (SWT_VERSION_LEN + SWT_SWID_TYPE_LEN)

                                          /* position of the SWID in FSCshort */
#define SWT_SWID_SHORT_POSITION 8U
                                             /* the supported supplier number */
#define SWT_SUPPLIER_NUMBER_LEN 8U

                                             /* the supported requester types */
#define SWT_REQUESTER_TYPE_LEN  1U

#define SWT_REQUESTER_TYPE_MARKETING 0x00U
#define SWT_REQUESTER_TYPE_FACTORY   0x01U
#define SWT_REQUESTER_TYPE_TRADER    0x02U
#define SWT_REQUESTER_TYPE_CUSTOMER  0x03U


                                                /* the supported order number */
#define SWT_ORDER_NUMBER_LEN 8U

                                               /* the supported requester ids */
#define SWT_REQ_MARKETING_ID_LEN 4U
#define SWT_REQ_FACTORY_ID_LEN   2U
#define SWT_REQ_TRADER_ID_LEN    5U
#define SWT_REQ_CUSTOMER_ID_LEN  4U

#define SWT_REQ_MIN_LEN SWT_REQ_FACTORY_ID_LEN
#define SWT_REQ_MAX_LEN SWT_REQ_TRADER_ID_LEN

                                     /* the supported individualisation types */
#define SWT_INDIV_TYPE_LEN 1U

#define SWT_INDIV_TYPE_NO_VIN    0x00U
#define SWT_INDIV_TYPE_SHORT_VIN 0x01U
#define SWT_INDIV_TYPE_LONG_VIN  0x02U

                                /* the supported individualisation attributes */
#define SWT_INDIV_NO_VIN_LEN     0U
#define SWT_INDIV_SHORT_VIN_LEN  7U
#define SWT_INDIV_LONG_VIN_LEN  17U


                                          /* the supported validity condition */
#define SWT_VALIDITY_COND_UNLIMITED 0x01U
#define SWT_VALIDITY_COND_DATE      0x02U
#define SWT_VALIDITY_COND_PERIOD    0x03U
#define SWT_VALIDITY_COND_KM        0x04U
#define SWT_VALIDITY_COND_OP_TIME   0x05U
#define SWT_VALIDITY_COND_DAYS      0x06U


#define SWT_VALIDITY_COND_MIN_LEN 4U
/* SWT_VALIDITY_COND_MAX_LEN is defined in Swt_Cfg.h                      */


                                                      /* the supported FSCSID */
#define SWT_FSCSID_LEN 8U

                                                 /* the supported date format */
#define SWT_DATE_SEPARATOR_POS 12U
#define SWT_DATE_OFFSET_LEN    4U

#define SWT_SHORT_DATE_LEN (SWT_DATE_SEPARATOR_POS + 2U)
#define SWT_LONG_DATE_LEN  (SWT_SHORT_DATE_LEN + SWT_DATE_OFFSET_LEN)

                                           /* the supported additional fields */
#define SWT_ADD_FIELD_MIN_LEN 1U
/* SWT_ADD_FIELD_MAX_LEN is defined in Swt_Cfg.h                          */

    /* the only allowed type of additional field: a Diffie-Hellman public key */
#define SWT_ADD_FIELD_TYPE_DIFFIE 0x0CU


  /* the supported signature length depends on the length of the used RSA key */
#define SWT_SIGNATURE_LEN SWT_FSC_SIG_LEN_BYTES

                                              /* the range of the FSC lengths */
#define SWT_FSC_MIN_LEN                    \
           (SWT_VERSION_LEN              + \
            SWT_SWID_TYPE_LEN            + \
            SWT_SWID_LEN                 + \
            SWT_SUPPLIER_NUMBER_LEN      + \
            SWT_REQUESTER_TYPE_LEN       + \
            SWT_ORDER_NUMBER_LEN         + \
            SWT_REQ_MIN_LEN              + \
            SWT_INDIV_TYPE_LEN           + \
            SWT_INDIV_NO_VIN_LEN         + \
            SWT_VALIDITY_COND_MIN_LEN    + \
            SWT_FSCSID_LEN               + \
            SWT_SHORT_DATE_LEN           + \
            SWT_ADD_FIELD_MIN_LEN        + \
            SWT_SIGNATURE_LEN)

#define SWT_FSC_MAX_LEN                    \
           (SWT_VERSION_LEN              + \
            SWT_SWID_TYPE_LEN            + \
            SWT_SWID_LEN                 + \
            SWT_SUPPLIER_NUMBER_LEN      + \
            SWT_REQUESTER_TYPE_LEN       + \
            SWT_ORDER_NUMBER_LEN         + \
            SWT_REQ_MAX_LEN              + \
            SWT_INDIV_TYPE_LEN           + \
            SWT_INDIV_LONG_VIN_LEN       + \
            SWT_VALIDITY_COND_MAX_LEN    + \
            SWT_FSCSID_LEN               + \
            SWT_LONG_DATE_LEN            + \
            SWT_ADD_FIELD_MAX_LEN        + \
            SWT_SIGNATURE_LEN)

                                     /* the base32 encoded length of FSCshort */
#define SWT_FSC_SHORT_BASE32_LEN         20U
#define SWT_FSC_SHORT_LEN                12U  /* decoded length of FSCShort */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

                                                     /* The elements of a FSC */
typedef enum
{
  Swt_FSC_VERSION = 0,
  Swt_FSC_SWIDTYPE,
  Swt_FSC_SWID,
  Swt_FSC_SUPPLIER,
  Swt_FSC_REQUESTERTYPE,
  Swt_FSC_ORDERNUMBER,
  Swt_FSC_REQUESTERID,
  Swt_FSC_INDIVTYPE,
  Swt_FSC_INDIVATTR,
  Swt_FSC_VALIDITY,
  Swt_FSC_FSCSID,
  Swt_FSC_DATE,
  Swt_FSC_ADDITIONAL,
  Swt_FSC_SIGNATURE,
  Swt_FSC_END
}
Swt_FSCElement;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

extern SwtRC_t Swt_FSCParse
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   Fsc,
   const uint16                           FscLength
);

extern SwtRC_t Swt_FSCCheckDate
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   const uint16                         FscLength,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) FscStored,
   const uint16                         FscStoredLength,
   const Swt_FSC_State                FscStoredState
);

extern SwtRC_t Swt_FSCCheckSWID
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) FscSWID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SoftwareSWID
);

extern SwtRC_t Swt_FSCCheckSignature
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            Fsc,
   uint16                                          FscLength,
   CONSTP2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) PublicKeyPtr
);

extern SwtRC_t Swt_FSCCheckIndivAttr
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) VIN
);

extern SwtRC_t Swt_FSCCheckValidity
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength
);

extern SwtRC_t Swt_FSCCheckFSCSID
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) FscsId
);

extern SwtRC_t Swt_FSCCheckFreshness
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength,
   uint32                               StartDate,
   uint32                               EndDate
);

SwtRC_t Swt_FSCExtractDiffieKey
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                        Fsc,
   uint16                                                      FscLength,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR)DiffieKeyStartPtr

);

SwtRC_t Swt_GetPos
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   Fsc,
   const uint16                           FscLength,
   const Swt_FSCElement                 Element,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)    PosPtr

);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"


#endif                                           /* if (!defined SWT_FSC_H) */
/*** End of file **************************************************************/
