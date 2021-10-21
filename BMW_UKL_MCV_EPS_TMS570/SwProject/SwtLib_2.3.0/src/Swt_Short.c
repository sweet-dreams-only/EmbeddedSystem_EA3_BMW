/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Short.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Routines needed for the handling of short FSCs                **
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
** cb           Christian Blomenhofer      Elektrobit Automotive GmbH         **
** jd           Jochen Decker              Elektrobit Automotive GmbH         **
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
 * V2.0.0    : 04.04.2007, mg   : made different signature lengths for FSCs and
 *                                certificates possible
 * V2.0.1    : 12.04.2007, mg   : made DEK generation compatible with older
 *                                implementation.
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */



/*******************************************************************************
**                      inclusions                                            **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Short.h"                   /* declarations for Short routines */
#include "Appl_Swt.h"      /* controller key and public modulus */
#include "Swt_SWData.h"                          /* type "Swt_SWDataType" */
#include "Swt_FSC.h"                               /* length of a short FSC */
#include "Swt_Common.h"                         /* byte comparison function */

#include "Swt_DES.h"                                                 /* DES */
#include "Swt_RSA.h"                                /* long number services */
#include "Swt_Diffie.h"                      /* Diffie-Hellman key exchange */
#include "Swt_Hash.h"                                      /* hash function */
#include "Swt_PBKDF1.h"                                  /* PBKDF1 function */

#include "Swt_Date.h"

/*******************************************************************************
**                      macros                                                **
*******************************************************************************/

      /* the amount of iterations which should be done in the PBKDF1 function */
#define SWT_SHORT_ITERATION_COUNT  7U

                                             /* the length of K_Symm in bytes */
#define SWT_SHORT_KSYMM_LEN 8U

                /* The amount of bytes of KeySYMM used for computing the salt */
#define SWT_PKCS5_KEY_LEN_BYTES         8U

/*******************************************************************************
**                      type definitions                                      **
*******************************************************************************/

/*******************************************************************************
**                      external function declarations                        **
*******************************************************************************/

/*******************************************************************************
**                      internal function declarations                        **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

SWT_STATIC_FUNC void ConvertDateToUTC
(
   CONSTP2VAR(uint8, AUTOMATIC,SC_FAR)Date, 
   SwtDateType CurDate
);


SWT_STATIC_FUNC SwtRC_t Swt_ShortDeriveDEK
(
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)              DEK,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            ShortVIN,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            SWID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            DiffiePublicKey,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) KeySG,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Modulus,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Barrett

);

SWT_STATIC_FUNC SwtRC_t Swt_ShortFSCCheckValidity
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   uint16                               FscLength
);


#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      external constants                                    **
*******************************************************************************/

/*******************************************************************************
**                      external data                                         **
*******************************************************************************/

/*******************************************************************************
**                      internal constants                                    **
*******************************************************************************/
#define SWT_SHORT_VALIDITY_COND_START       0x05U
#define SWT_SHORT_VALIDITY_COND_SIZE        0x03U
#define SWT_SHORT_VALIDITY_COND_TYPE        0x00U

#define SWT_SHORT_VALIDITY_COND_UNLIMITED   0x00U
#define SWT_SHORT_VALIDITY_COND_DATE        0x01U
#define SWT_SHORT_VALIDITY_COND_KM          0x02U
#define SWT_SHORT_VALIDITY_COND_APPLICATION 0x0FU

/*******************************************************************************
**                      internal data                                         **
*******************************************************************************/

/*******************************************************************************
**                      external function definitions                         **
*******************************************************************************/


#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)

#define SWT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ShortFSCCheck                                       **
**                                                                            **
** DESCRIPTION    : Check a short FSC.                                        **
**                                                                            **
** PRECONDITIONS  : 'SWData' is a valid pointer (not checked)                 **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : SWData: A pointer to the start of an array which contains **
**                          SW data.                                          **
**                  NrOfSWIDs: The number of SWIDs on the current controller  **
**                  Index: The position of the FSC to check in the array      **
**                         "SWData"                                           **
**                                                                            **
** RETURN         : Swt_RC_OK, if the FSC check was successful              **
**                  Swt_RC_KEY_DERIVATION_NOT_ACTIVATED, if the FSC_Enabler **
**                      is not accepted                                       **
**                  Swt_RC_SWID_CHECK_FAILURE, if the SWID stored in the    **
**                      decrypted FSC is not identical to the given SWID      **
**                  Swt_RC_FSC_CHECK_FAILURE, if the decrypted FSC contains **
**                      garbage                                               **
**                  Swt_RC_UNKNOWN_ERROR, if an error occurs                **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_ShortFSCCheck
(
   CONSTP2CONST(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData,
   const uint8                                     NrOfSWIDs,
   const uint8                                     Index
)
{
   SwtRC_t RetVal = Swt_RC_OK;            /* the return value of the function */
   uint8  DEK[SWT_DES_BLOCKSIZE];       /* the key to decrypt the short FSC */
                                     /* pointer to the start of the short VIN */
   P2CONST(uint8,AUTOMATIC,SC_FAR) VINPtr;
                 /* pointer to the start of the Diffie-Hellman public key "Y" */
   P2CONST(uint8,AUTOMATIC,SC_FAR) DiffiePublicKeyStart;
   uint8 FSCEnablerIndex;   /* the position of the FSC_Enabler in the sw data */
   Swt_DESContextType DESCtx;                 /* context for DES decryption */
                                       /* the decoded and decrypted short FSC */
   uint8 FSCDecrypted[SWT_DES_BLOCKSIZE];

#if (SWT_SHORT_STORE == SWT_CFG_ON)
   uint8 ShortIndex;
#endif

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"

                                               /* The SWID of the FSC_Enabler */
   SWT_STATIC_VAR const uint8 FSCEnablerSWID[SWT_SWID_LEN] =
                                                { SWT_FSC_ENABLER_SWID_INIT };

#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


   /* Initialize some local variables. */
   FSCEnablerIndex = 0;
   DiffiePublicKeyStart = 0;

   if ( Swt_RC_OK == RetVal )
   {
      /* The SWID stored at the end of the decoded is compared to the SWID    */
      /* in the sw data.                                                      */
      RetVal = Swt_FSCCheckSWID( &(SWData[Index].Fsc[SWT_SWID_SHORT_POSITION]),
                                 SWData[Index].SwId );
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* We try to find the FSC_Enabler and store its position in             */
      /* "FSCEnablerIndex".                                                   */
      RetVal = Swt_FindSW( SWData,
                           NrOfSWIDs,
                           FSCEnablerSWID,
                           &FSCEnablerIndex,
                           TRUE );

      if ( Swt_RC_OK != RetVal )
      {
         RetVal = Swt_RC_KEY_DERIVATION_NOT_ACTIVATED;
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* Is the FSC_Enabler accepted? */
      if ( Swt_STATE_FSC_ACCEPTED != SWData[FSCEnablerIndex].FscState )
      {
         RetVal = Swt_RC_KEY_DERIVATION_NOT_ACTIVATED;
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* Extract the Diffie-Hellman public key "Y" from the FSC_Enabler. */
      RetVal = Swt_FSCExtractDiffieKey ( SWData[FSCEnablerIndex].Fsc,
                                         SWData[FSCEnablerIndex].FscLength,
                                         &DiffiePublicKeyStart );
   }

   /* If SWT_SHORT_STORE is set, we only derive the key in case it is not 
      already stored. */

#if (SWT_SHORT_STORE == SWT_CFG_ON)
   /* Search for the correct SWT-Short data */
   RetVal = Swt_FindShortSW(Swt_ShortData, SWData[Index].SwId, &ShortIndex);
   if (Swt_RC_OK == RetVal)
   {
      if ((Swt_STATE_SHORT_NOTCHECKED == Swt_ShortData[ShortIndex].ShortState)
        ||(Swt_RC_EQUAL != Swt_CommonCompare(DiffiePublicKeyStart, 
                                             Swt_ShortData[ShortIndex].Dieffie, 
                                             SWT_DIFFIE_KEY_LEN_BYTES)))
      {
#endif

         if ( Swt_RC_OK == RetVal ) 
         {
            /* Get the long VIN */
            VINPtr = Appl_SwtGetVinInternal();

            /* Jump to the start of the short VIN. */
            VINPtr = &VINPtr[SWT_INDIV_LONG_VIN_LEN - SWT_INDIV_SHORT_VIN_LEN];            

            /* Derive the key with which to decrypt the decoded short FSC. */
            RetVal = Swt_ShortDeriveDEK ( DEK,
                                          VINPtr,
                                          &(SWData[Index].Fsc[SWT_SWID_SHORT_POSITION]),
                                          DiffiePublicKeyStart,
                                          Appl_SwtGetKeyEcu (),
                                          Appl_SwtGetModulus (),
#if(SWT_RSA_USE_BARRETT == SWT_CFG_ON)
                                          Appl_SwtGetBarrettValue ()
#else
                                          0
#endif
                                          );
         }
#if (SWT_SHORT_STORE == SWT_CFG_ON)
         if (Swt_RC_OK == RetVal)
         {
            Swt_CommonCopy(Swt_ShortData[ShortIndex].DEK, DEK, SWT_DES_BLOCKSIZE);
            Swt_CommonCopy(Swt_ShortData[ShortIndex].Dieffie, 
                           DiffiePublicKeyStart,
                           SWT_DIFFIE_KEY_LEN_BYTES);
            Swt_ShortData[ShortIndex].ShortState = Swt_STATE_SHORT_CHECKED;
         }
         else
         {
            Swt_ShortData[ShortIndex].ShortState = Swt_STATE_SHORT_NOTCHECKED;
         }
         /* Store status persistent                                                 */
         RetVal = Appl_SwtWriteBlock( (uint16)SWT_SHORT_DATA );
      }
      else
      {
         Swt_CommonCopy(DEK, Swt_ShortData[ShortIndex].DEK, SWT_DES_BLOCKSIZE);
      }
   }
#endif

   if ( Swt_RC_OK == RetVal )
   {
      /* Decrypt the decoded short FSC and store it in "FSCDecrypted. */
      Swt_DESInit( &DESCtx, DEK );
      Swt_DESDecryptBlock ( &DESCtx, SWData[Index].Fsc, FSCDecrypted );

      /* Check that the decrypted FSC does not contain garbage. */
      if ((uint8)SWT_SWID_TYPE != FSCDecrypted[0] )
      {
         RetVal = Swt_RC_FSC_CHECK_FAILURE;
      }

      if ( Swt_RC_OK == RetVal )
      {
         /* The SWID stored at the end of the decoded FSC is compared to the SWID    */
         /* in the decrypted FSC.                                                    */
         RetVal = Swt_FSCCheckSWID( &(SWData[Index].Fsc[SWT_SWID_SHORT_POSITION]),
                                    &FSCDecrypted[1] );
      }
      if ( Swt_RC_OK == RetVal )
      {
         /* Check the validity conditions contained in the decrypted FSC */
         RetVal = Swt_ShortFSCCheckValidity(FSCDecrypted, SWT_DES_BLOCKSIZE);
      }
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* Check the SWID of the decrypted short FSC. */
      if ( Swt_RC_EQUAL !=
           Swt_CommonCompare( &FSCDecrypted[1],
                              &(SWData[Index].Fsc[SWT_SWID_SHORT_POSITION]),
                              (uint32)SWT_SWID_LEN ) )
      {
         RetVal = Swt_RC_SWID_CHECK_FAILURE;
      }
   }

   return RetVal;
}





/*******************************************************************************
**                      internal function definitions                         **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ShortFSCCheckValidity                                 **
**                                                                            **
** DESCRIPTION    : Checks the Validity conditions of a given decrypted       **
**                  FSC Short                                                 **
**                                                                            ** 
** PRECONDITIONS  : Fsc is a valid pointer to the Fsc                         **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : Fsc: a valid decrypted FSC short                          **
**                  FscLength: the length of the array with the Fsc           **
**                                                                            **
** RETURN         : Swt_RC_OK in case that the Validity conditions could be   **
**                            interpreted and are ok                          **
**                  Swt_RC_VALIDITY_CHECK_FAILURE in case that the condtions  **
**                            are wrong formatted, in a wrong range or the    **
**                            conditions are not valid                        **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ShortFSCCheckValidity(CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc, uint16 FscLength)
{
   SwtRC_t RetVal = Swt_RC_OK;
   /* Array for the Validity conditions */
   uint8 ValidityCond[SWT_SHORT_VALIDITY_COND_SIZE];

#if (SWT_USE_VAL_COND_SHORT_KM == SWT_CFG_ON)
   /* Current kilometer value of the ECU */
   uint32 SGKMValue;
   /* Kilometer value until the FSC is valid */
   uint32 ValidKMValue;
#endif /* (SWT_USE_VAL_COND_SHORT_KM == SWT_CFG_ON) */

#if (SWT_USE_VAL_COND_SHORT_CURRENT_DATE == SWT_CFG_ON)
   /* current date of the ECU */
   SwtDateType SGCurDate;
   uint32 SGCurDateConverted;
   /* Date until the FSC is valid */
   SwtDateType ValidityDate;   
   uint32 ValidityDateConverted;
   /* Declare a placeholder for the Dates in UTC-Format */
   uint8 Date[] = {0x31,0x35,0x31,0x32,0x33,0x31,0x30,0x30,0x30,0x30,0x30,0x30,'Z'};
#endif /* (SWT_USE_VAL_COND_SHORT_CURRENT_DATE == SWT_CFG_ON) */


   /* Extract the Validity conditions out of the decrypted FSC */
   Swt_CommonCopy(ValidityCond, &Fsc[SWT_SHORT_VALIDITY_COND_START], SWT_SHORT_VALIDITY_COND_SIZE);

#ifdef TEST_VALIDITYDATE   
   ValidityCond[0] = 0x11;   /* Januar */
   ValidityCond[1] = 0x05;   /* 2015 */
   ValidityCond[2] = 31;     /* 31 */
#endif

   switch ((ValidityCond[SWT_SHORT_VALIDITY_COND_TYPE] & 0xF0) >> 4)
   {
      case SWT_SHORT_VALIDITY_COND_UNLIMITED:
         if (0x01 != (ValidityCond[0] & 0x0F))
         {
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
         break;

#if (SWT_USE_VAL_COND_SHORT_CURRENT_DATE == SWT_CFG_ON)
      case SWT_SHORT_VALIDITY_COND_DATE:
         /* Read the current date of the ECU */
         SGCurDate = Appl_SwtGetCurrentDate();
         /* Extract the validity date out of the validity conditions */
         ValidityDate.day   = ValidityCond[2] & 0x1F;
         ValidityDate.month = ValidityCond[0] & 0x0F;
         ValidityDate.year  = ValidityCond[1] + 2010;

         /* Check date and convert it */  
         ConvertDateToUTC(Date, SGCurDate);
         /* Swt_DateGet does also check the format and the range of the values */
         SGCurDateConverted    = Swt_DateGet(Date, Swt_DATE_UTC_TIME);
         ConvertDateToUTC(Date, ValidityDate);
         ValidityDateConverted = Swt_DateGet(Date, Swt_DATE_UTC_TIME);
         
         /* If the current date is later than the Validity date
            or if one of the converted dates is 0 (error) return an error */
         if ((SGCurDateConverted > ValidityDateConverted)
           ||(SGCurDateConverted == 0)
           ||(ValidityDateConverted == 0))
         {
            /* The condition is not valid. */
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
         break;
#endif

#if (SWT_USE_VAL_COND_KM == SWT_CFG_ON)
      case SWT_SHORT_VALIDITY_COND_KM:
         /* Get the actual kilometers travelled from the controller. */
         SGKMValue = Appl_SwtGetKm()/10;
         /* Convert the Validity condition to the same format */
         ValidKMValue = ((ValidityCond[0] & 0x0F) * 65536) + (ValidityCond[1] * 256) + ValidityCond[0];

         if( SGKMValue > ValidKMValue )
         {
            /* The condition is not valid. */
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
         break;
#endif

#if (SWT_USE_VAL_COND_SHORT_APPLICATION == SWT_CFG_ON)
      case SWT_SHORT_VALIDITY_COND_APPLICATION:
         ValidityCond[0] = ValidityCond[0] & 0x0F;
         /* If the Validity condition is application specific we have to ask the application */
         if (Swt_RC_OK != Appl_SwtShortFSCCheckValidity(ValidityCond, SWT_SHORT_VALIDITY_COND_SIZE))
         {
            /* The condition is not valid. */
            RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
         break;
#endif
      default:
         /* something is wrong with the Validity conditions */
         RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         break;
   }

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : ConvertDateToUTC                                          **
**                                                                            **
** DESCRIPTION    : Convert the SwtDateType to UTC-Format                     **
**                  Converts the struct-members into the Date array           **
**                  in ASCII-format                                           **
**                                                                            ** 
** PRECONDITIONS  : Date is an array with the correct length and some         **
**                  placeholders for hours, minutes, seconds and the endflag. **
**       uint8 Date[]                                                         **
**       = {0x31,0x35,0x31,0x32,0x33,0x31,0x30,0x30,0x30,0x30,0x30,0x30,'Z'}; **
** POSTCONDITIONS : The first 6 bytes of the Date array contain the given     **
**                  informations.                                             ** 
**                                                                            **
** PARAMETERS     : Date: a well defined uint8 array                          **
**                  CurDate: the date that has to be converted                **
**                                                                            **
** RETURN         :                                                           **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC void ConvertDateToUTC(CONSTP2VAR(uint8, AUTOMATIC,SC_FAR)Date, SwtDateType DateToBeConverted)
{
   /* Year starting with 2000 as ASCII */
   Date[0] = ((DateToBeConverted.year-2000)/10) + 0x30;
   Date[1] = ((DateToBeConverted.year-2000)%10) + 0x30;
   /* Month */
   Date[2] = ((DateToBeConverted.month)/10) + 0x30;
   Date[3] = ((DateToBeConverted.month)%10) + 0x30;
   /* Day */
   Date[4] = ((DateToBeConverted.day)/10) + 0x30;
   Date[5] = ((DateToBeConverted.day)%10) + 0x30;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ShortDeriveDEK                                      **
**                                                                            **
** DESCRIPTION    : This function derives the key "DEK", with which a short   **
**                  FSC can be decrypted, from the short VIN, the SWID, the   **
**                  Diffie-Hellman public key stored in the FSC_Enabler,      **
**                  the public modulus and the controller key.                **
**                                                                            **
** PRECONDITIONS  : 'DEK' is a valid pointer (not checked)                    **
**                  'ShortVIN' is a valid pointer (not checked)               **
**                  'SWID' is a valid pointer (not checked)                   **
**                  'DiffiePublicKey' is a valid pointer (not checked)        **
**                  'KeySG' is a valid pointer (not checked)                  **
**                  'Modulus' is a valid pointer (not checked)                **
**                                                                            **
** POSTCONDITIONS : The array pointed to by "DEK" contains the DES key which  **
**                  can be used to decrypt a short FSC.                       **
**                                                                            **
** PARAMETERS     : DEK: A pointer to the start of an array which will        **
**                       the key "DEK"                                        **
**                  ShortVIN: A pointer to the start of an array which must   **
**                            contain the short VIN                           **
**                  SWID: A pointer to the start of an array which must       **
**                        contain the short SWID                              **
**                  DiffiePublicKey: A pointer to the start of an array which **
**                                   must contain the Diffie-Hellman public   **
**                                   key                                      **
**                  KeySG: A pointer to the start of an array which must      **
**                         contain the controller key                         **
**                  Modulus: A pointer to the start of an array which must    **
**                            contain the public modulus                      **
**                                                                            **
** RETURN         : Swt_RC_OK, if the computation was successful              **
**                  Swt_RC_UNKNOWN_ERROR, if an error occurs                  **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SWT_STATIC_FUNC SwtRC_t Swt_ShortDeriveDEK
(
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)              DEK,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            ShortVIN,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            SWID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            DiffiePublicKey,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)   KeySG,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)   Modulus,
   CONSTP2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR)   Barrett
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   Swt_DiffieContextType DiffieCtx;           /* context for Diffie-Hellman */
   Swt_HashContextType   HashCtx;           /* context for hash computation */
                   /* The common key, called "K" in the requirements document */
   uint8 CommonKey[SWT_DIFFIE_KEY_LEN_BYTES];
           /* the key "K_Symm", but with 8 trailing byte which can be ignored */
   uint8 KeySymmLong[SWT_HASH_LEN_BYTES];
   /* A temporary variable which holds the salt for the PBKDF1 function and   */
   /* later the provisional DEK.                                              */
   uint8 Temp[SWT_HASH_LEN_BYTES];
                      /* the public values of the Diffie Hellman key exchange */
   Swt_AlgoKeyExchangeType DiffieHellmanPublic;
   uint8_least i;                                             /* loop counter */


   /* We set the public modulus for the Diffie-Hellman key exchange to the    */
   /* given modulus.                                                          */
   DiffieHellmanPublic.CommonModulus = Modulus;
   DiffieHellmanPublic.CommonModulusExt = Barrett;

   /* We compute the common key "K" and store it in "CommonKey. */
   RetVal = Swt_ComputeKeyExchangeCommonKey ( &DiffieCtx,
                                              &DiffieHellmanPublic,
                                              DiffiePublicKey,
                                              KeySG,
                                              CommonKey );

   /* We hash "K" to get "K_Symm" and store it in KeySymmLong. The array is   */
   /* 16 bytes long, because it is an MD5 digest. But we only need the first  */
   /* 8 bytes.                                                                */

   if ( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_ComputeHashInit ( &HashCtx );
   }

   if ( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_ComputeHashUpdate ( &HashCtx,
                                         CommonKey,
                                         SWT_DIFFIE_KEY_LEN_BYTES );
   }

   if ( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_ComputeHashFinalize ( &HashCtx,
                                           KeySymmLong );
   }


   /* We compute the salt from "K_Symm", the short VIN and the SWID and store */
   /* it in "Temp".                                                           */

   if ( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_ComputeHashInit ( &HashCtx );
   }

   if ( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_ComputeHashUpdate ( &HashCtx,
                                         ShortVIN,
                                         (uint32)SWT_INDIV_SHORT_VIN_LEN );
   }

   if ( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_ComputeHashUpdate ( &HashCtx,
                                         KeySymmLong,
                                         (uint32)SWT_PKCS5_KEY_LEN_BYTES );
   }

   if ( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_ComputeHashUpdate ( &HashCtx,
                                         SWID,
                                         (uint32)SWT_SWID_LEN );
   }

   if ( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_ComputeHashFinalize ( &HashCtx,
                                           Temp );
   }

   if ( Swt_RC_OK == RetVal )
   {
      /* We compute the the provisional DEK by using the function PBKDF1 with */
      /* "K_Symm" as the input and the just computed salt. The provisional    */
      /* DEK is again stored in "Temp". According to the requirements, the    */
      /* first 8 bytes of this provisional DEK are the real DEK. But to be    */
      /* compatible with an older SWT Short implementation, a further XOR     */
      /* operation has to be performed to get the DEK.                        */
      RetVal = Swt_PBKDF1 ( KeySymmLong,
                              SWT_SHORT_KSYMM_LEN,
                              Temp,
                              SWT_SHORT_ITERATION_COUNT,
                              Temp,
                              SWT_HASH_LEN_BYTES );
   }

   /* We XOR the first 8 bytes of the provisional DEK with the next 8 bytes   */
   /* to get the real DEK. This is not in the requirements but it is needed   */
   /* be compatible with an older SWT Short implementation.                   */
   for(i = 0; i < SWT_DES_BLOCKSIZE; i++)
   {
      DEK[i] = Temp[i] ^ Temp[SWT_DES_BLOCKSIZE + i];
   }

   return RetVal;
}


#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                           /* #if (SWT_USE_SWT_SHORT == SWT_CFG_ON) */

/*** End of file **************************************************************/
