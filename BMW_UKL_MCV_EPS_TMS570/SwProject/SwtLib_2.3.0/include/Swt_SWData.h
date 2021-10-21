/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_SWData.h                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Declarations for the routines which return the software data  **
**              for a given SG.                                               **
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
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

#if (!defined SWT_SWDATA_H)            /* preprocessor exclusion definition */
#define SWT_SWDATA_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_FSC.h"                                          /* FSC length */

#if ((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON))
#include "Swt_Des.h"
#endif /*((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON))*/

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef enum
{
   Swt_STATE_CERT_NOT_EXISTENT = 0U,               /* No certificate stored */
   Swt_STATE_CERT_IMPORTED,                     /*  certificate is imported */
   Swt_STATE_CERT_ACCEPTED,                  /* The certificate is accepted */
   Swt_STATE_CERT_REJECTED  /* The certificate has failed a signature check */
}
Swt_CertStateType;

typedef enum
{
   Swt_STATE_SHORT_NOTCHECKED,    /* The key for decrypting FSC Short is not yet checked */
   Swt_STATE_SHORT_CHECKED        /* The key for decrypting FSC Short is already checked and stored */
}
Swt_ShortStateType;
                                /* A type which will hold all SW information. */
// TODO: Barrett
typedef struct
{
                                        /* The state of the corresponding SW. */
   Swt_SW_State       SwState;
                                       /* The state of the corresponding FSC. */
   Swt_FSC_State      FscState;
                                      /* The id of the SW to handle with SWT. */
   uint8              SwId[SWT_SWID_LEN];
                                          /* The FSC used to activate the SW. */
   uint8              Fsc[SWT_FSC_MAX_LEN];
                                             /* The length of the stored FSC. */
   uint16             FscLength;
                                                 /* what king of FSC is this? */
   Swt_FSCTypeType    FscType;   
}
Swt_SWDataType;



#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
                            /* A type which will hold certificate information */
typedef struct
{
                                          /* current state of the certificate */
   Swt_CertStateType  CertState;
                                         /* certificate of the the public key */
   uint8                Cert[SWT_CERT_MAX_LEN];
}
Swt_CertDataType;
#endif

#if ((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON))
typedef struct
{
   uint8               SwId[SWT_SWID_LEN];
   Swt_ShortStateType  ShortState;
   uint8               Dieffie[SWT_DIFFIE_KEY_LEN_BYTES];
   uint8               DEK[SWT_DES_BLOCKSIZE];       /* the key to decrypt the short FSC */
}
Swt_ShortDataType;
#endif


                                      /* The states of the software signature */

typedef enum
{
   Swt_STATE_SWSIG_NOT_EXISTENT = 0U,                       /* No SW stored */
   Swt_STATE_SWSIG_IMPORTED,                             /*  SW is imported */
   Swt_STATE_SWSIG_ACCEPTED,                          /* The SW is accepted */
   Swt_STATE_SWSIG_REJECTED          /* The SW has failed a signature check */
}
Swt_SWSigStateType;


typedef struct
{
                                   /* current state of the software signature */
   Swt_SWSigStateType SigState;

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
                                     /* current state of the SigS certificate */
   Swt_CertStateType  CertState;
                                     /* current state of the root certificate */
   Swt_CertStateType  RootCertState;
                                    /* certificate of the signature authority */
   uint8                Cert[SWT_CERT_MAX_LEN];
#endif

}
Swt_SWSigDataType;


/*******************************************************************************
**                      Global Constants                                      **
*******************************************************************************/

#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"

extern const uint8 Swt_SGIDs[SWT_NR_OF_SGIDS];

#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


#if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_OFF)

#define SWT_START_SEC_CONST_UNSPEC
#include "MemMap.h"

/** ROM default for NVRAM data #Swt_SWData. */
extern const Swt_SWDataType Swt_SWDataDefault[SWT_NR_OF_SWIDS];

/** ROM default for NVRAM data #Swt_SWSigData. */
extern const Swt_SWSigDataType Swt_SWSigDataDefault[SWT_NR_OF_SGIDS];

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
/** ROM default for NVRAM data #Swt_CertData. */
extern const Swt_CertDataType Swt_CertDataDefault[SWT_NR_OF_CERTS];
#endif

#if ((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON))
/** ROM default for NVRAM data #Swt_ShortData. */
extern const Swt_ShortDataType Swt_ShortDataDefault[SWT_NR_OF_SHORT];
#endif

#define SWT_STOP_SEC_CONST_UNSPEC
#include "MemMap.h"

#endif                  /* #if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_OFF) */


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define SWT_START_SEC_VAR_NO_INIT
#include "MemMap.h"

/** SWT software data to be stored persistently in NVRAM. */
extern Swt_SWDataType Swt_SWData[SWT_NR_OF_SWIDS];

/** SWT software signature data to be stored persistently in NVRAM. */
extern Swt_SWSigDataType Swt_SWSigData[SWT_NR_OF_SGIDS];

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
/** SWT certificate data to be stored persistently in NVRAM. */
extern Swt_CertDataType Swt_CertData[SWT_NR_OF_CERTS];
#endif

#if ((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON))
/** FSC short data to be stored persistently in NVMRAM. */
extern Swt_ShortDataType Swt_ShortData[SWT_NR_OF_SHORT];
#endif

#define SWT_STOP_SEC_VAR_NO_INIT
#include "MemMap.h"



/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

extern P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) Swt_GetSWData
(
   const uint8                        SGID,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) NrOfSWIDsPtr
);

extern P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) Swt_GetSWSigData
(
   const uint8 SGID
);

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
extern P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) Swt_GetCertData
(
   const uint8                        SGID,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) NrOfCertsPtr
);
#endif


extern SwtRC_t Swt_FindSW
(
   CONSTP2CONST(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData,
   uint8                                           NrOfSWIDs,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            SwId,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)              PosPtr,
   boolean                                         Strict
);

#if ((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON))
SwtRC_t Swt_FindShortSW
(
   CONSTP2CONST(Swt_ShortDataType,AUTOMATIC,SC_FAR) ShortData,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)             SwId,
   CONSTP2VAR(uint8, AUTOMATIC,SC_FAR)              ShortIndex
);
#endif

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                        /* if (!defined SWT_SWDATA_H) */
/*** End of file **************************************************************/
