/**************************************************************************//**
 * \file
 * Definition of SWT application level interfaces.
 *
 * \target All
 * \project SWT
 * \author BMW AG
 * \userchange No
 *****************************************************************************/
 
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Appl.h"						/* declarations of API interfaces */
#include "Swt_Handler.h"								/* internal interface */
#include "Swt_FSC.h"						   /* declaration of FSC services */
                                 /* declaration of platform specific services */
#include "Appl_Swt.h"
#include "Swt_SWData.h"            /* declarations of services to get SW data */
#include "Swt_Common.h"                /* declarations of Swt common services */

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
#include "Swt_Certificate.h"          /* declarations of certificate services */
#include "Swt_Full.h"                                /* routines for SWT Full */
#endif

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
#include "Swt_Base32.h"                    /* declarations of base32 services */
#include "Swt_Short.h"                             /* routines for short FSCs */
#endif

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

#if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_ON)

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_Init                                                **
**                                                                            **
** DESCRIPTION    : Function which initialises the SWT handler.               **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS : Global variables are initialised. The contents of the     **
**                  variable SWData are either stored into EEPROM.            **
**                                                                            **
** PARAMETER      : SGID : The ID of the controller which should be           **
**                         initialized                                        **
**                                                                            **
** RETURN         : Swt_RC_FLASH_WRITE_ERROR, if it was not possible to     **
**                                  store the state of the handler persistent **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of this controller                              **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_Init
(
   const uint8 SGID
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint8_least i;                                            /* loop variable */
   /* A pointer to the software signature data of this SG                     */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
                      /* An array containing the certificate data for this SG */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) CertData;
   uint8 NrOfCerts ;                /* The amount of certificates for this SG */
#endif

   RetVal = Swt_RC_OK;

   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
   /* Get the certificate data for this SG.                                   */
   CertData = Swt_GetCertData(SGID,&NrOfCerts);
#endif

   /* Get the software signature data variable.                               */
   SWSigData = Swt_GetSWSigData(SGID);

   if( 0 == SWData )
   {
      RetVal = Swt_RC_MISSING_SG_DATA;
   }

   if( Swt_RC_OK == RetVal)
   {
      /* Initialise the SW data                                               */
      i = (uint8_least)0U;
      while( (uint8_least)NrOfSWIDs > i )
      {

         SWData[i].SwState = Swt_STATE_SW_NOT_EXISTENT;
         SWData[i].FscState = Swt_STATE_FSC_NOT_EXISTENT;
         SWData[i].FscType = Swt_FSC_TYPE_LIGHT;

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
         if( i < (uint8_least)NrOfCerts )
         {
            CertData[i].CertState = Swt_STATE_CERT_NOT_EXISTENT;
         }
#endif

         i++;
      }

      /* write block into persistent storage                                  */
      RetVal = Appl_SwtWriteBlock( (uint16)SWT_SW_DATA );

	  /** \bug Writing SWT_CERT_DATA to persistent data is not guarded by (SWT_USE_SWT_FULL == SWT_CFG_ON). */
	  /** Added if/endif to check for SWT Full [MP]. */
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
	  if( Swt_RC_OK == RetVal )
      {
         RetVal = Appl_SwtWriteBlock( (uint16)SWT_CERT_DATA );
      }
#endif /* (SWT_USE_SWT_FULL == SWT_CFG_ON) */
   }

   if( Swt_RC_OK == RetVal)
   {
      /* Initialise the SW signature data.                                    */
      SWSigData->SigState      = Swt_STATE_SWSIG_NOT_EXISTENT;

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
      SWSigData->CertState     = Swt_STATE_CERT_NOT_EXISTENT;
      SWSigData->RootCertState = Swt_STATE_CERT_ACCEPTED;
#endif

      /* write block into persistent storage                                  */
      RetVal = Appl_SwtWriteBlock( (uint16)SWT_SWSIG_DATA);
   }

   return RetVal;
}

#endif /* #if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_ON) */

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_IsSwActivated                                       **
**                                                                            **
** DESCRIPTION    : Checks if the SW with the given SwId is activated in the  **
**                  controller with ID "SGID".                                **
**                                                                            **
** PRECONDITIONS  : 'SwId' is a valid SWID (not checked)                      **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : SGID : The ID of the SG which should be checked           **
**                  SwId : The SWID of the corresponding SW                   **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a given parameter is not valid     **
**                  Swt_RC_MISSING_SG_DATA,  if 'SGID' does not match the   **
**                                             SGID of any controller         **
**                  Swt_RC_SW_NOT_ACTIVATED, if no valid FSC with the given **
**                                             SwId is stored inside the SG   **
**                  Swt_RC_OK,              if the corresponding SW is      **
**                                            activated                       **
**                  Swt_RC_SW_NOT_EXISTENT, if no software with the given   **
**                                            SwId is stored inside the ECU   **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens   **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_IsSwActivated
(
   const uint8                          SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint8     i;                                            /* loop variable */
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( 0 == SwId )                            /* Check if we got a valid SwId */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_ACTIVATED_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   i = 0;

   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

   if( 0 == SWData )
   {
      RetVal = Swt_RC_MISSING_SG_DATA;
   }
   else
   {
      /* Is there a SW with the given SWId                                    */
      RetVal = Swt_FindSW(SWData,NrOfSWIDs,SwId,&i,TRUE);
   }

   if(Swt_RC_OK == RetVal)
   {
      if( Swt_STATE_SW_ACTIVATED == SWData[i].SwState )
      {
         RetVal = Swt_RC_OK;
      }
      else if( Swt_STATE_SW_DEACTIVATED == SWData[i].SwState )
      {
         RetVal = Swt_RC_SW_NOT_ACTIVATED;
      }
      else
      {
         RetVal = Swt_RC_UNKNOWN_ERROR;
      }
   }

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_PeriodicalChecks                                    **
**                                                                            **
** DESCRIPTION    : Periodical checks of the VIN, the FSC and the software    **
**                  signature.                                                **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller whose software signature  **
**                         should be checked                                  **
**                  SwId : The ID of the Sw which should be checked           **
**                                                                            **
** RETURN         : Swt_RC_SW_NOT_EXISTENT, if there is no software         **
**                  Swt_RC_FLASH_READ_ERROR, if the internal VIN could not  **
**                         be read                                            **
**                  Swt_RC_FGN_ACCESS_FAILURE, if the external VIN could    **
**                         not be read                                        **
**                  Swt_RC_FGN_CHECK_FAILURE, if the VINs are not equal     **
**                  Swt_RC_SWSIG_CHECK_FAILURE, if the software signature   **
**                                          check has failed                  **
**                  Swt_RC_SIGS_CERT_CHECK_FAILURE, if the check of the     **
**                                  SigS certificate failed                   **
**                  Swt_RC_FSCS_CERT_CHECK_FAILURE, if the check of an      **
**                                  FSCS certificate failed                   **
**                  Swt_RC_FSC_CHECK_FAILURE, if the check of an FSC failed **
**                  Swt_RC_FLASH_WRITE_ERROR, if it was not possible to     **
**                                  store the signature state persistently    **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of this controller                              **
**                  Swt_RC_BAD_PARAM, if one of the arguments was a null    **
**                                      pointer                               **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_PeriodicalChecks
(
   const uint8         SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId
)
{
   SwtRC_t     RetValFlowControl;  /* the return value for the flow control */
   SwtRC_t     RetValFinal;                           /* final return value */
   uint8         i;                                          /* loop variable */
   P2CONST(uint8,AUTOMATIC,SC_FAR) InternalVIN;
   P2CONST(uint8,AUTOMATIC,SC_FAR) ExternalVIN;
   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */

   ///* NXTR SWT */ getting error on line 519, a value of type "const uint8* cannont be assigned to an entity of type "uint8*"
   //P2VAR(uint8,AUTOMATIC,SC_FAR) CurrSwId;
   P2CONST(uint8,AUTOMATIC,SC_FAR) CurrSwId;
   
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
                      /* An array containing the certificate data for this SG */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) CertData;
   uint8 NrOfCerts ;                /* The amount of certificates for this SG */
                                           /* Pointer to the root certificate */
   P2CONST(uint8,AUTOMATIC,SC_FAR) RootCertPtr;
#endif

   InternalVIN = 0;
   ExternalVIN = 0;
   i = 0;

   RetValFlowControl    = Swt_RC_OK;
   RetValFinal          = Swt_RC_OK;
   

   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
   /* Get the certificate data for this SG.                                   */
   CertData = Swt_GetCertData(SGID,&NrOfCerts);
#endif

   /* Get the software signature state variable.                              */
   SWSigData = Swt_GetSWSigData(SGID);

   if( 0 == SWData )
   {
      RetValFlowControl    = Swt_RC_MISSING_SG_DATA;
      RetValFinal          = Swt_RC_MISSING_SG_DATA;
   }

   if( Swt_RC_OK == RetValFlowControl )
   {
      /* Get the internal VIN.                                                */
      InternalVIN = Appl_SwtGetVinInternal();

      if(0 == InternalVIN)
      {
         if ( RetValFinal == Swt_RC_OK )
            RetValFinal       = Swt_RC_FLASH_READ_ERROR;
      }
   }

   /* Check internal and external VIN                                         */
   if( Swt_RC_OK == RetValFlowControl )
   {
      /* Get the external VIN.                                                */
      ExternalVIN = Appl_SwtGetVinExternal();

      if( 0 == ExternalVIN )
      {
         if ( RetValFinal == Swt_RC_OK )
            RetValFinal       = Swt_RC_FGN_ACCESS_FAILURE;
      }
   }
   if( Swt_RC_OK == RetValFlowControl )
   {
      /* Compare the two VINs. Just the last 7 bytes                         */
      if( Swt_RC_EQUAL !=
          Swt_CommonCompare( &InternalVIN[SWT_INDIV_LONG_VIN_LEN - SWT_INDIV_SHORT_VIN_LEN],
                             &ExternalVIN[SWT_INDIV_LONG_VIN_LEN - SWT_INDIV_SHORT_VIN_LEN],
                             (uint32)SWT_INDIV_SHORT_VIN_LEN ) )
      {
         if ( RetValFinal == Swt_RC_OK )
            RetValFinal    = Swt_RC_FGN_CHECK_FAILURE;
            
         /* All FSC has to be set to state 'Rejected'                         */
         i = 0;
         while( NrOfSWIDs > i )                        /* Process all FSCs */
         {
            if ( 
                  SWData[i].FscState == Swt_STATE_FSC_ACCEPTED ||
                  SWData[i].FscState == Swt_STATE_FSC_IMPORTED
               )
            {               
               UpdateSwtNvm(SWData[i].FscState, Swt_STATE_FSC_REJECTED, nvmSwtSwData);
            }
            UpdateSwtNvm(SWData[i].SwState, Swt_STATE_SW_DEACTIVATED,nvmSwtSwData);
            i++;
         }
         /* Leave Function. All FSCs/SWs deaktivated */
         RetValFlowControl = RetValFinal;
      }
   }

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

   /* Check root certificate                                                  */
   if( Swt_RC_OK == RetValFlowControl )
   {
      RootCertPtr = Appl_SwtGetRootCert();

      if( 0 == RootCertPtr )
      {
         /* we are not able to read the root certificate, this is a realy bad */
         /* situation, we set every state to rejected                         */         
         UpdateSwtNvm(SWSigData->RootCertState, Swt_STATE_CERT_REJECTED, nvmSwtSwSigData);
         UpdateSwtNvm(SWSigData->CertState, Swt_STATE_CERT_REJECTED, nvmSwtSwSigData);
         UpdateSwtNvm(SWSigData->SigState, Swt_STATE_SWSIG_REJECTED, nvmSwtSwSigData);

         i = 0;
         while( NrOfSWIDs > i )
         {
            SWData[i].SwState        = Swt_STATE_SW_DEACTIVATED;
            if ( NrOfCerts > i )
            {               
               UpdateSwtNvm(CertData[i].CertState, Swt_STATE_CERT_REJECTED, nvmSwtCertData);
            }
            i++;
         }

         RetValFinal = Swt_RC_ROOT_CERT_NOT_READABLE;

         /* Leave Function. All FSCs/SWs deaktivated */
         RetValFlowControl = RetValFinal;
      }
   }              

   /* Check the SigS certificate                                              */
   if( Swt_RC_OK == RetValFlowControl )
   {
      if( Swt_STATE_CERT_NOT_EXISTENT != SWSigData->CertState )
      {
         if( 
             Swt_RC_OK != 
             Swt_CheckCert( SGID, SwId, ( uint8 )SWT_CERT_TYPE_SIGS, FALSE )
           )
         {
            if ( RetValFinal == Swt_RC_OK )
               RetValFinal    = Swt_RC_SIGS_CERT_CHECK_FAILURE;
         }
      }
   }
#endif                            /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

   /* Check the software signature                                            */
   if( Swt_RC_OK == RetValFlowControl )
   {
      if( Swt_STATE_SWSIG_NOT_EXISTENT != SWSigData->SigState ) 
      {
         if( Swt_RC_OK != Swt_CheckSWSig( SGID, FALSE ) )
         {
            if ( RetValFinal == Swt_RC_OK )
               RetValFinal    = Swt_RC_SWSIG_CHECK_FAILURE;
            RetValFlowControl = Swt_RC_SWSIG_CHECK_FAILURE;
         }
      }
      else
      {
         if ( RetValFinal == Swt_RC_OK )
            RetValFinal       = Swt_RC_SWSIG_CHECK_FAILURE;
         RetValFlowControl    = Swt_RC_SWSIG_CHECK_FAILURE;
      }
   }

   if( Swt_RC_OK == RetValFlowControl )
   {
      /* This means that we must check all SWIds.                             */
      i = 0;
      while( NrOfSWIDs > i )
      {
         /* Is SwID a null pointer?                                              */
         if( 0 == SwId )
         {
            CurrSwId    = SWData[ i ].SwId;
         }
         else
         {
            /* Is there a SW with the given SWId                                 */
            RetValFlowControl = Swt_FindSW( SWData, NrOfSWIDs, SwId, &i, TRUE );
            if ( Swt_RC_OK != RetValFlowControl ) 
               RetValFinal = RetValFlowControl;

            CurrSwId    = SwId;
            NrOfSWIDs   = 1;  
         }
      
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

         if( ( Swt_RC_OK == RetValFlowControl ) && ( NrOfCerts > i ) )
         {
            if( Swt_STATE_CERT_NOT_EXISTENT != CertData[i].CertState )
            {
               /* check the corresponding FSCS certificate                 */
               if ( Swt_RC_OK != Swt_CheckCert(
                                             SGID,
                                             CurrSwId,
                                             ( uint8 )SWT_CERT_TYPE_FSCS,
                                             FALSE)
                  )
               {
                  if ( RetValFinal == Swt_RC_OK )
                     RetValFinal    = Swt_RC_FSCS_CERT_CHECK_FAILURE;
               }
            }
         }

#endif                            /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

         if( Swt_RC_OK == RetValFlowControl )
         {
            /* Check the FSC which belongs to this SwId.                   */
            if( 
                  Swt_STATE_FSC_NOT_EXISTENT != SWData[i].FscState && 
                  Swt_STATE_FSC_DISABLED     != SWData[i].FscState 
               )
            {
               if( Swt_RC_OK != Swt_CheckFSC( SGID, CurrSwId, FALSE ) )
               {
                  if ( RetValFinal == Swt_RC_OK )
                     RetValFinal    = Swt_RC_FSC_CHECK_FAILURE;
               }
            }
            else
            {
               if ( SWData[i].SwState != Swt_STATE_SW_DEACTIVATED ) 
               {  
                  /* Set SW-Status to deactivated */
                  SWData[i].SwState = Swt_STATE_SW_DEACTIVATED;
                  
                  if ( RetValFinal == Swt_RC_OK )
                     RetValFinal    = Swt_RC_FSC_CHECK_FAILURE;
                     
                  nvmSwtSwData = TRUE;
               }
            }
         }
         i++;
      }
   }

      if (TRUE == nvmSwtSwData)
      {
         if( Swt_RC_OK != Appl_SwtWriteBlock( (uint16)SWT_SW_DATA ) )
         {
            RetValFinal = Swt_RC_FLASH_WRITE_ERROR;
         }         
      }
      if (TRUE == nvmSwtSwSigData)
      {
         if( Swt_RC_OK != Appl_SwtWriteBlock( (uint16)SWT_SWSIG_DATA ) )
         {
            RetValFinal = Swt_RC_FLASH_WRITE_ERROR;
         }         
      }
#ifdef SWT_USE_SWT_FULL
      if (TRUE == nvmSwtCertData)
      {
         if( Swt_RC_OK != Appl_SwtWriteBlock( (uint16)SWT_CERT_DATA ) )
         {
            RetValFinal = Swt_RC_FLASH_WRITE_ERROR;
         }         
      }
#endif

   return RetValFinal;
}

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CheckFscShortForUpdate                                **
**                                                                            **
** DESCRIPTION    : Periodical checks of the VIN, the FSC and the software    **
**                  signature.                                                **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller whose software signature  **
**                         should be checked                                  **
**                  SwId : The ID of the Sw which should be checked           **
**                                                                            **
** RETURN         : Swt_RC_FSC_CANCELLED, if the FSC has been disabled        **
**                  Swt_RC_SWID_CHECK_FAILURE, if the upgrade index of the    **
**                                               FSC SWID is too old          **
**                  Swt_RC_KEY_DERIVATION_NOT_ACTIVATED, if the FSC_Enabler   **
**                                            for a short FSC is not accepted **
**                  Swt_RC_FGN_ACCESS_FAILURE, if the VIN could not be        **
**                                               accessed                     **
**                  Swt_RC_FGN_CHECK_FAILURE, if the individualisation        **
**                                          attributes of the FSC are invalid **
**                  Swt_RC_VALIDITY_CHECK_FAILURE, if the validity            **
**                                          conditions of the FSC are invalid **
**                  Swt_RC_INVALID_FSC, if the stored FSC is too big or too   **
**                                        small                               **
**                  Swt_RC_FGN_CHECK_FAILURE, if the FGN or the ECUSNR in     **
**                                       the FSC is not the same as in the SG **
**                  Swt_RC_FLASH_WRITE_ERROR, if it was not possible to       **
**                                  store the state of the handler persistent **
**                  Swt_RC_FLASH_READ_ERROR, if the key could not be          **
**                                        extracted from the FSCS certificate **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens     **
**                  Swt_RC_SW_NOT_EXISTENT, if no software with the given     **
**                                            SwId is stored inside the ECU   **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the      **
**                       SGID of this controller                              **
**                  Swt_RC_BAD_PARAM, if one of the arguments was a null      **
**                                      pointer                               **
**                  Swt_RC_OK, if all operations were successful              **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CheckFscShortForUpdate(const uint8 SGID, CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)SwId)
{
   SwtRC_t RetVal = Swt_RC_OK;  
   uint16  NewFscLength = SWT_FSC_SHORT_BASE32_LEN;
   uint8   NewFsc[SWT_FSC_SHORT_BASE32_LEN]; 
   uint16  FSCShortLen;
   uint8   FSCShort[SWT_FSC_SHORT_LEN];
   boolean IsUpdated = FALSE;
   uint8   posOfSW;

   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */


   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

   /* Check that there is a SW with the given SWID stored in the SG           */
   /* We only check the application number, not the UI */
   if( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_FindSW(SWData, NrOfSWIDs, SwId, &posOfSW, TRUE);
   }

   /* Check whether SWID has a FSC Short*/
   if(Swt_FSC_TYPE_SHORT != SWData[posOfSW].FscType)
   {
      RetVal = Swt_RC_SWID_CHECK_FAILURE;
   }

   /* Check whether there is already a FSC for the given SWID */
   /* If it is already stored, we check and accept it */
   if (Swt_RC_OK == RetVal)
   {
      RetVal = Swt_CheckFSC( SGID, SwId, TRUE );
   }

   /* If there is no FSC available, we ask the MMI for a new one */
   if( Swt_RC_FSC_NOT_EXISTENT == RetVal)
   {
      RetVal = Appl_SwtTriggerStoreFscFromMmi(SwId, NewFsc, &NewFscLength);

      /* We got a correct FSC which we will try to accept */
      if (Swt_RC_OK == RetVal)
      {
         /* Check Format of the FSC */
         if (SWT_FSC_SHORT_BASE32_LEN != NewFscLength)
         {
            RetVal = Swt_RC_INVALID_FSC;
         }

         if (Swt_RC_OK == RetVal)
         {
         /* Decode the Base32 */         
         /* We store the length of the decoded short FSC. */
            FSCShortLen = SWT_FSC_SHORT_LEN;

         /* The short FSC is Base32-decoded */
            RetVal = Swt_Base32Decode(NewFsc,
                                      NewFscLength,
                                      FSCShort,
                                      &FSCShortLen);
         }

         if( ( Swt_RC_OK != RetVal ) || ( FSCShortLen != SWT_FSC_SHORT_LEN ) )
         {
            /* The decoding of the short FSC yielded an error or an FSC of    */
            /* incorrect length.                                              */
            RetVal = Swt_RC_INVALID_FSC;
         }

         if (Swt_RC_OK == RetVal)
         {
         /* Store FSC */
            RetVal = Swt_StoreFSC(SGID, SwId, FSCShort, FSCShortLen);
         }
         
         if (Swt_RC_OK == RetVal)
         {
         /* Check FSC */
            RetVal = Swt_CheckFSC(SGID, SwId, TRUE);
         }
         
         if (Swt_RC_OK == RetVal)
         {
         /* Trigger application to update the software with given Swid */
            RetVal = Appl_SwtTriggerSwUpdate(SwId, &IsUpdated);
         }

         if (Swt_RC_OK == RetVal)
         {
            if (TRUE == IsUpdated)            
            {
            /* Check signature of the new software */
               RetVal= Swt_CheckSWSig( SGID, FALSE ) ;
            }
         }
      }
   }
   
   /* else */
   /* We return the errorcode of the Swt_CheckFSC function */

   return RetVal;
}
#endif /* #if (SWT_USE_SWT_SHORT == SWT_CFG_ON) */


#if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_ON)

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_SwDownloadPostAction                                **
**                                                                            **
** DESCRIPTION    : Store new SWIDs and the signature centre (SigS)           **
**                  certificate in the persistent storage.                    **
**                                                                            **
** PRECONDITIONS  : 'SwIds' points to an array containing SWIDs (not checked) **
**                  'SigsCert' points to an array containing the SigS         **
**                             certificate (not checked)                      **
**                  'SigsCertLen' is the actual length of the certificate     **
**                                (not checked)                               **
**                                                                            **
** POSTCONDITIONS : The SigS certificate and the SwIds are stored in the      **
**                  persistent storage. The state of the corresponding SW is  **
**                  set to deactivated. The state of the corresponding FSC is **
**                  set to not existent.                                      **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller                           **
**                  SigsCertLen : Length of the signature center certificate  **
**                  SigsCert : A pointer to the first element of an array     **
**                             which contains the signature center cert.      **
**                  SwIdCount : The number of SWID which have to be stored    **
**                  SwIds: A pointer to the first element of an array which   **
**                         contains the SWIDs                                 **
**                                                                            **
** RETURN         : Swt_RC_NO_FREE_SPACE, if there is no space left to      **
**                                          store all the given SWIDs         **
**                  Swt_RC_FLASH_WRITE_ERROR, if it was not possible to     **
**                                  store the state of the handler persistent **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of this controller                              **
**                  Swt_RC_BAD_PARAM, if one of the arguments was a null    **
**                                      pointer                               **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_SwDownloadPostAction
(
   const uint8                          SGID,
   const uint16                         SigsCertLen,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SigsCert,
   const uint8                          SwIdCount,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwIds
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint8_least Index;                          /* the index of the SWID entry */
   uint8_least i;                                            /* loop variable */
   uint8_least j;                                            /* loop variable */
   uint16_least Position;
   boolean FreeSpace;                    /* flag indicating free memory space */
   boolean Existent;                        /* flag indicating double entries */
   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
                      /* An array containing the certificate data for this SG */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) CertData;
   uint8 NrOfCerts ;                /* The amount of certificates for this SG */
                                           /* Pointer to the root certificate */
#endif


#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( (( 0 == SwIds ) || ( 0 == SwIdCount ))/* Check if we got valid SwIds */
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
       || ( 0 == SigsCert )
#endif
      )


   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_DLPOST_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   RetVal = Swt_RC_OK;

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

   /* Check the length of the certificate                                     */
   if((SWT_CERT_MAX_LEN < SigsCertLen) || (SWT_CERT_MIN_LEN > SigsCertLen))
   {
                                                /* invalid certificate length */
      RetVal = Swt_RC_BAD_PARAM;
   }

#endif

   /* Get the relevant data of this SG                                        */
   if( Swt_RC_OK == RetVal )
   {
      /* Get the SW data for this SG.                                         */
      SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

      /* Get the software signature state variable.                           */
      SWSigData = Swt_GetSWSigData(SGID);

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
      /* Get the certificate data for this SG.                                */
      CertData = Swt_GetCertData(SGID,&NrOfCerts);
#endif


      if( (0 == SWData) || (0 == SWSigData) )
      {
         RetVal = Swt_RC_MISSING_SG_DATA;
      }
   }

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

   if( Swt_RC_OK == RetVal )
   {
      /* Store the given SigS certificate into the SW Sig Data                */
      if( 0 != SigsCert )
      {
         (void)Swt_CommonCopy(SWSigData->Cert, SigsCert, (uint32)SigsCertLen);
         SWSigData->CertState = Swt_STATE_CERT_IMPORTED;
      }

      SWSigData->RootCertState = Swt_STATE_CERT_ACCEPTED;

      RetVal = Appl_SwtWriteBlock( (uint16)SWT_SWSIG_DATA );
   }

#endif

   if ( (Swt_RC_OK == RetVal) &&
        (Swt_STATE_SWSIG_NOT_EXISTENT == SWSigData->SigState) )
   {
      /* The software signature state is now "accepted".                      */
      SWSigData->SigState = Swt_STATE_SWSIG_ACCEPTED;

      RetVal = Appl_SwtWriteBlock( (uint16)SWT_SWSIG_DATA );
   }

   for( j = 0; (j < SwIdCount) && (Swt_RC_OK == RetVal); j++)
   {
      Position = SWT_SWID_LEN * j;

      /* Check that there is space to store the SWID                          */
      i = (uint8_least)0U;
      Index = (uint8_least)0U;
      FreeSpace = FALSE;
      Existent = FALSE;
      while( ((uint8_least)NrOfSWIDs > i) && (FALSE == Existent) )
      {
         /* Look for the first free entry                                     */
         if( Swt_STATE_SW_NOT_EXISTENT == SWData[i].SwState )
         {
            if( FALSE == FreeSpace )
            {
               Index = i;                /* get index of the first free entry */
               FreeSpace = TRUE;
            }
         }
         /* check if the SWID is stored in the handler already                */
         else
         {
            /* We only compare the application number of the SWID. Applications
               with different upgrade index are stored at the same entry, i.e.
               they will be overwritten                                       */
            if
            (
               Swt_RC_EQUAL ==
               Swt_CommonCompare
               (
                  &SwIds[Position],
                  SWData[i].SwId,
                  (uint32)SWT_APP_NUMBER_LEN    /* only the first two bytes */
               )
            )
               {
                  Index = i;                        /* get index of the entry */
                  Existent = TRUE;           /* the application number exists */
                  FreeSpace = TRUE;                /* and will be overwritten */
               }
         }
         i++;
      }

      if( FALSE == FreeSpace )
      {
         RetVal = Swt_RC_NO_FREE_SPACE;
      }

      /* Store information about the SWID into flash if it does not yet       */
      /* exist.                                                               */
      if( ( Swt_RC_OK == RetVal ) && ( FALSE == Existent ) )
      {
         SWData[Index].SwState = Swt_STATE_SW_DEACTIVATED;
         SWData[Index].FscState = Swt_STATE_FSC_NOT_EXISTENT;
         (void)Swt_CommonCopy
         (
            SWData[Index].SwId,
            &SwIds[Position],
            (uint32)SWT_SWID_LEN
         );

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

         if( Index < NrOfCerts )
         {
            /* We can store certificates at the current index. This means     */
            /* that the FSC type must be full.                                */
            SWData[Index].FscType = Swt_FSC_TYPE_FULL;
         }
         else

#else

         {
            /* We cannot store certificates at the current index. This means  */
            /* that the FSC type is light. Note that short FSCs can still be  */
            /* be stored if the type is given as light. The type will then be */
            /* set to short.                                                  */
            SWData[Index].FscType = Swt_FSC_TYPE_LIGHT;
         }

#endif

                                       /* write block into persistent storage */
         RetVal = Appl_SwtWriteBlock( (uint16)SWT_SW_DATA );
      }
   }

   return RetVal;
}

#endif                   /* #if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_ON) */


#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/


/*** End of file **************************************************************/
