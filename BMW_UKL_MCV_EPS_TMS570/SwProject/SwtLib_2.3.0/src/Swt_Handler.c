/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Handler.c                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for SWT Light handler services.                   **
**                                                                            **
**  REMARKS   : The Swt handler which implements the functionalities          **
**              StoreFSC and CheckFSC.                                        **
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
** mp           Mike Pagel                 BMW AG                             **
*******************************************************************************/

/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Aug 18 20:09:21 2012
* %version:          2 %
* %derived_by:       wz7x3j %
* %date_modified:    Sat Sep 29 17:22:12 2012 %
*---------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 09/29/12   2        BDO         SWT updates - anomaly 3782
 */


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.9.0    : 28.11.2006, mg   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.0.0    : 04.04.2007, mg   : made different signature lengths for FSCs and
 *                                certificates possible; periodical check now
 *                                handles the SigS certificate state correctly
 * V2.1.0    : 01.09.2007, djk  : removed bug: Reset of Status (SW and FSC) if 
 *                                internal VIN is not equal to the external VIN
 *                                improved identification and elimination of  
 *                                manipulations in Swt_PeriodicalChecks
 *                                changed ErrorType in Funktion DisableFSC
 * V2.2.0    : 15.05.2008, mp   : moved public APIs to Swt_Appl.c
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Handler.h"                /* declarations of handler services */
#include "Swt_FSC.h"                         /* declaration of FSC services */
                                 /* declaration of platform specific services */
#include "Appl_Swt.h"
#include "Swt_SWData.h"          /* declarations of services to get SW data */
#include "Swt_Common.h"            /* declarations of Swt common services */

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
#include "Swt_Certificate.h"        /* declarations of certificate services */
#include "Swt_Full.h"                              /* routines for SWT Full */
#endif

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
#include "Swt_Short.h"                           /* routines for short FSCs */
#endif

#include "Swt_Nvm.h"                /* declarations for nvm usage */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

                        /* This FSC should not be saved before an SG exchange */
#define SWT_DO_NOT_SAVE_FSC 0x00U

/* How many bytes to skip in the return array of Swt_GetStatus before the   */
/* SWIDs and the FSC status bytes are to be stored                            */
#define SWT_STATUS_SKIP    (uint16)4

/* The length of one entry of the output array of Swt_GetStatus. Consists   */
/* of the SWID, the certificate status, the FSC status, and the FSC type.     */
#if (SWT_DIAG_USE_KWP2000 == SWT_CFG_ON)
	#define SWT_STATUS_ENTRY_LEN (uint16)(SWT_SWID_LEN + 2U)
#else
	#define SWT_STATUS_ENTRY_LEN (uint16)(SWT_SWID_LEN + 3U)
#endif /* #if (SWT_DIAG_USE_KWP2000 == SWT_CFG_ON) */

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

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CheckSWSig                                          **
**                                                                            **
** DESCRIPTION    : Check the signature of the software.                      **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS : The software signature state is modified.                 **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller whose software signature  **
**                         should be checked                                  **
**                                                                            **
** RETURN         : Swt_RC_SW_NOT_EXISTENT, if there is no software         **
**                  Swt_RC_SW_REJECTED, if the software is already rejected **
**                  Swt_RC_FLASH_WRITE_ERROR, if it was not possible to     **
**                                  store the signature state persistently    **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of this controller                              **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CheckSWSig
(
    const uint8 SGID, 
    const boolean writeNvm
)
{
   SwtRC_t      RetVal;                 /* the return value of the function */
   Swt_SigRet_t SigRetVal;     /* the return value of the actual sig. check */
                              /* a pointer to the start of an array with the  */
                              /* start addresses of the blocks of the SWE to  */
                              /* be checked                                   */
   P2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR)     AddressPtr;
                              /* a pointer to the start of an array with the  */
                              /* lengths of the blocks of the SWE to be       */
                              /* checked                                      */
   P2VAR(uint32,AUTOMATIC,SC_FAR)       LengthPtr;

                                /* a pointer to the start of the signature    */
   P2VAR(uint32,AUTOMATIC,SC_FAR)       SignaturePtr;
   uint32         NumberOfBlocks; /* the number of blocks of the SWE          */
   uint8          i;              /* loop counter                             */
   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */
   boolean SWExists;                    /* Stores whether there is a software */

   i = 0;

   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

   /* Get the software signature state variable.                              */
   SWSigData = Swt_GetSWSigData(SGID);

   if( 0 == SWData )
   {
      RetVal = Swt_RC_MISSING_SG_DATA;
   }
   else
   {
      RetVal = Swt_RC_OK;
   }

   if( Swt_RC_OK == RetVal)
   {
      /* Is there a software? */

      SWExists = FALSE;

      while( (NrOfSWIDs > i) &&
             (FALSE == SWExists) )
      {
         if( SWData[i].SwState != Swt_STATE_SW_NOT_EXISTENT )
         {
            SWExists = TRUE;
         }

         i++;
      }

      if( FALSE == SWExists )
      {
         /* We have found no software.                                        */
         RetVal = Swt_RC_SW_NOT_EXISTENT;
      }
   }

   if( Swt_RC_OK == RetVal)
   {
      /* If the software signature state is "accepted", "imported", or        */
      /* "rejected", the signature must be checked.                           */
      if( Swt_STATE_SWSIG_NOT_EXISTENT == SWSigData->SigState)
      {
         RetVal = Swt_RC_SW_NOT_EXISTENT;
      }
      else
      {
         /* Nothing needs to be done.                                         */
      }
   }

   if( Swt_RC_OK == RetVal)
   {
      /* Get all needed information to check the signature.                   */
      NumberOfBlocks = Appl_SwtGetSwBlockNumber(SGID);
      AddressPtr     = Appl_SwtGetSwAddresses(SGID);
      LengthPtr      = Appl_SwtGetSwLengths(SGID);
      SignaturePtr   = Appl_SwtGetSwSignature(SGID);

      /* Check the signature.                                                 */
      SigRetVal = Swt_CryptoCheckSigSW
                  (
                     NumberOfBlocks,
                     AddressPtr,
                     LengthPtr,
                     SignaturePtr
                  );

      if( Swt_SIG_OK == SigRetVal )
      {
         /* The signature was correct.                                        */

         /* The software signature state is now "accepted".                   */
         UpdateSwtNvm(SWSigData->SigState, Swt_STATE_SWSIG_ACCEPTED, nvmSwtSwSigData);


         i = 0;

         /* All SWIDs with an FSC with state "accepted" are now "activated".  */
         /* Fallback solution: If the upgrade index of the SWID is zero, the  */
         /* SW will also be activated.                                        */
         while( (NrOfSWIDs > i) &&
                (Swt_RC_OK == RetVal) )
         {
            if( ((Swt_STATE_FSC_ACCEPTED == SWData[i].FscState) ||
                ((0 == SWData[i].SwId[2]) && (0 == SWData[i].SwId[3]))))
            {
               UpdateSwtNvm(SWData[i].SwState, Swt_STATE_SW_ACTIVATED, nvmSwtSwData);
            }
            i++;
         }
                                       /* write block into persistent storage */
         //RetVal = Appl_SwtWriteBlock( (uint16)SWT_SW_DATA );
         //nvmSwtSwData = TRUE;
      }
      else
      {
         /* The signature was incorrect.                                      */

         /* The software signature state is now "rejected".                   */
         UpdateSwtNvm(SWSigData->SigState, Swt_STATE_SWSIG_REJECTED, nvmSwtSwSigData);

         i = 0;

         /* All SWIDs are now "deactivated".                                  */
         while( (NrOfSWIDs > i) &&
                (Swt_RC_OK == RetVal) )
         {
            if( Swt_STATE_SW_ACTIVATED == SWData[i].SwState )
            {
               SWData[i].SwState = Swt_STATE_SW_DEACTIVATED;
               nvmSwtSwData = TRUE;
            }
            i++;
         }

                                       /* write block into persistent storage */
         //nvmSwtSwData = TRUE;
         //if( Swt_RC_OK != Appl_SwtWriteBlock( (uint16)SWT_SW_DATA ) )
         //{
         //   RetVal = Swt_RC_FLASH_WRITE_ERROR;
         //}
         //else
         //{
            RetVal = Swt_RC_SWSIG_CHECK_FAILURE;
         //}
      }
   }

   if (TRUE == writeNvm)
   {
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
   }


   return RetVal;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetSWIDFunctional                                   **
**                                                                            **
** DESCRIPTION    : Get all SWIDs stored in all controllers.                  **
**                                                                            **
** PRECONDITIONS  : 'RetMaxLen' is large enough so that all SWIDs can be      **
**                              stored.                                       **
**                                                                            **
** POSTCONDITIONS : The SwIds are stored in the array 'Ret'.                  **
**                                                                            **
** PARAMETERS     : SGID : Ignored                                            **
**                  RetMaxLen: The amount of bytes reserved in 'Ret' for the  **
**                             storage of the SWIDs                           **
**                  Ret:   A pointer to the start of an array where the SWIDs **
**                         should be stored                                   **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if there is not enough space to store **
**                        all SWIDs or if the array was a null pointer        **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of any controller                               **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_GetSWIDFunctional
(
   const uint8   SGID,
   const uint16  RetMaxLen,
         P2VAR(uint8,AUTOMATIC,SC_FAR) Ret
)
{
   SwtRC_t    RetVal;               /* the return value of the function     */
   uint16       Pos;                  /* current position in the result array */
   uint8        i;                    /* loop counter                         */
#if 0
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */
#endif /* commented out [mp] */

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( 0 == Ret )                     /* Check if we got a valid result array */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_GETSWID_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   if(RetMaxLen < 2)
   {
                                            /* The result array is too small. */
      RetVal = Swt_RC_BAD_PARAM;
   }
   /** \bug Checking correctness of given \par SGID is not required (also see
    * function comment) in case of functional addressing.
	*/
   /* Commented out code performing the check has. [MP] */
   /* Initialized return code value. [MP] */
   RetVal = Swt_RC_OK;
#if 0
   else
   {
      /* Get the SW data for this SG.                                         */
      SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

      if( 0 == SWData )
      {
         RetVal = Swt_RC_MISSING_SG_DATA;
      }
      else
      {
         RetVal = Swt_RC_OK;
      }
   }
#endif /* #if 0 */

   if(Swt_RC_OK == RetVal)
   {
           /* The first element of the result array must be the number of SG. */
      Ret[0] = (uint8)SWT_NR_OF_SGIDS;

      Pos = 1;

      /* For each SG, we call the function "Swt_GetSWID" to get the SWIDs   */
      /* for that SG. That information is directly written to the result      */
      /* array.                                                               */
      for(  i = 0;
           (i < (uint8)SWT_NR_OF_SGIDS) && (Swt_RC_OK == RetVal);
            i++ )
      {
                          /* The current SGID is written to the result array. */
         Ret[Pos] = Swt_SGIDs[i];

         Pos++;

              /* All SWIDs of the current SG are written to the output array. */
         RetVal = Swt_GetSWID(Swt_SGIDs[i], RetMaxLen - Pos, &Ret[Pos]);

                        /* The written bytes of the output array are skipped. */
         Pos += (uint16)((uint16)(Ret[Pos] * (uint8)SWT_SWID_LEN) +
                         (uint16)1);
      }
   }

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetSWID                                             **
**                                                                            **
** DESCRIPTION    : Get all SWIDs stored in a controller.                     **
**                                                                            **
** PRECONDITIONS  : 'RetMaxLen' is large enough so that all SWIDs can be      **
**                              stored.                                       **
**                                                                            **
** POSTCONDITIONS : The SwIds are stored in the array 'Ret'.                  **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller whose SWIDs should be     **
**                         stored                                             **
**                  RetMaxLen: The amount of bytes reserved in 'Ret' for the  **
**                             storage of the SWIDs                           **
**                  Ret:   A pointer to the start of an array where the SWIDs **
**                         should be stored                                   **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if there is not enough space to store **
**                        all SWIDs or if the result array was a null pointer **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of this controller                              **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_GetSWID
(
   const uint8   SGID,
   const uint16  RetMaxLen,
   P2VAR(uint8,AUTOMATIC,SC_FAR) Ret
)
{
   SwtRC_t    RetVal;                   /* the return value of the function */
   uint8        i;                        /* loop counter                     */
   uint8        number;                   /* the number of SWIDs              */
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( 0 == Ret )                     /* Check if we got a valid result array */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_GETSWID_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   number    = 0;
   i         = 0;
   SWData    = 0;
   NrOfSWIDs = 0;

   if(RetMaxLen < 1)
   {
                                            /* The result array is too small. */
      RetVal = Swt_RC_BAD_PARAM;
   }
   else
   {
      /* Get the SW data for this SG.                                         */
      SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

      if( 0 == SWData )
      {
         RetVal = Swt_RC_MISSING_SG_DATA;
      }
      else
      {
         RetVal = Swt_RC_OK;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      /* Loop over all possible slots where SWIDs can be stored.              */
      while( NrOfSWIDs > i )
      {
         if( Swt_STATE_SW_NOT_EXISTENT != SWData[i].SwState )
         {
            /* We have found a SWID.                                          */
            //if( ((uint16)1 + (((uint16)i + (uint16)1) * (uint16)SWT_SWID_LEN)) <= RetMaxLen )
            //ChR: the length of Ret does not depend on i but on number 
            if( ((uint16)1 + (((uint16)number + (uint16)1) * (uint16)SWT_SWID_LEN)) <= RetMaxLen )
            {
               /* We have enough space to store the SWID in the output.       */
               //(void)Swt_CommonCopy( &Ret[1 + (i * SWT_SWID_LEN)],
               //ChR: The postion where to copy the next found SWID does not depend on i but 
               //on the number of found SWIDS -> number
               (void)Swt_CommonCopy( &Ret[1 + (number * SWT_SWID_LEN)],
                                     SWData[i].SwId,
                                     (uint32)SWT_SWID_LEN );

               /* One more SWID.                                              */
               number++;
            }
            else
            {
               RetVal = Swt_RC_BAD_PARAM;
            }
         }

         i++;
      }

      /* We store how many SWID we have found.                                */
       Ret[0] = number; //NXTR SWT PATCH/Bjoern - 9/25/12
      /* ChR: According to the spec the phy. address has to be reported in 
      the first byte */
       //NXTR SWT PATCH/Bjoern   Ret[0] = SWT_SGIDS;
#if SWT_NR_OF_SGIDS != 1        
#error To many SGIDs are defined for this job.
#endif
   }

   return RetVal;
}





/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetStatus                                           **
**                                                                            **
** DESCRIPTION    : Get the FSC status for all SWIDs stored in a controller.  **
**                                                                            **
** PRECONDITIONS  : 'RetMaxLen' is large enough so that all SWIDs can be      **
**                              stored.                                       **
**                                                                            **
** POSTCONDITIONS : The status information is stored in the array 'Ret'.      **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller whose status information  **
**                         is to be checked.                                  **
**                  RetMaxLen: The amount of bytes reserved in 'Ret' for the  **
**                             storage of the information                     **
**                  Ret:   A pointer to the start of an array where the FSC   **
**                         status should be stored                            **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if there is not enough space to store **
**                        all SWIDs or if the array was a null pointer        **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of this controller                              **
**                  Swt_RC_SW_NOT_ACTIVATED, if there is at least one SW    **
**                       which is not activated                               **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_GetStatus
(
   const uint8   SGID,
   const uint16  RetMaxLen,
         P2VAR(uint8,AUTOMATIC,SC_FAR) Ret
)
{
   SwtRC_t    RetVal;                   /* the return value of the function */
   uint16       i;                        /* loop counter                     */
   uint8        number;                   /* the number of SWIDs              */
   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
                      /* An array containing the certificate data for this SG */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) CertData;
   uint8 NrOfCerts ;                /* The amount of certificates for this SG */
#endif


#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( 0 == Ret )                     /* Check if we got a valid result array */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_GETSTATUS_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   /* Initialize some local variables.                                        */
   number        = 0;
   i             = 0;
   SWData        = 0;
   SWSigData     = 0;
   NrOfSWIDs     = 0;
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
   NrOfCerts     = 0;
   CertData      = 0;
#endif

   if(RetMaxLen < SWT_STATUS_SKIP)
   {
      RetVal = Swt_RC_BAD_PARAM;
   }
   else
   {
      /* Get the SW data for this SG.                                         */
      SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
      /* Get the certificate data for this SG.                                */
      CertData = Swt_GetCertData(SGID,&NrOfCerts);
#endif

      /* Get the software signature state variable.                           */
      SWSigData = Swt_GetSWSigData(SGID);

      if( 0 == SWData )
      {
         RetVal = Swt_RC_MISSING_SG_DATA;
      }
      else
      {
         RetVal = Swt_RC_OK;
      }
   }

   if( Swt_RC_OK == RetVal )
   {

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

                      /* Root certificate state. Not applicable to SWT light. */
      Ret[0] = (uint8)SWSigData->RootCertState;

              /* SW Signature certificate state. Not applicable to SWT light. */
      Ret[1] = (uint8)SWSigData->CertState;

#else

      Ret[0] = 0;
      Ret[1] = 0;

#endif                            /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

                                                       /* SW signature state. */
      Ret[2] = (uint8)SWSigData->SigState;

      /* Loop over all possible slots where SWIDs can be stored.              */
      while( ( (uint16)NrOfSWIDs > i ) && ( Swt_RC_OK == RetVal ) )
      {
         if( Swt_STATE_SW_NOT_EXISTENT != SWData[i].SwState )
         {
            /* We have found a SWID.                                          */
            if( (SWT_STATUS_SKIP + ((i + (uint16)1) * SWT_STATUS_ENTRY_LEN))
                <= RetMaxLen )
            {
               /* We have enough space to store the SWID in the output.       */
               (void)Swt_CommonCopy( &Ret[SWT_STATUS_SKIP +
                                            (i * SWT_STATUS_ENTRY_LEN)],
                                       SWData[i].SwId,
                                       (uint32)SWT_SWID_LEN );

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
               if( ( Swt_FSC_TYPE_FULL == SWData[i].FscType ) &&
                   ( (uint16)NrOfCerts > i ) )
               {
                  /* Store the certificate status                             */
                  Ret[SWT_STATUS_SKIP +
                      (i * SWT_STATUS_ENTRY_LEN) + SWT_SWID_LEN] =
                                                   (uint8)CertData[i].CertState;
               }
               else
#endif
               {
                  Ret[SWT_STATUS_SKIP +
                      (i * SWT_STATUS_ENTRY_LEN) +
                      SWT_SWID_LEN] = 0;
               }

               /* Store the FSC status                                        */
               Ret[SWT_STATUS_SKIP +
                   (i * SWT_STATUS_ENTRY_LEN) +
                   SWT_SWID_LEN + 1] = (uint8)SWData[i].FscState;

			   /* do not store FSC type for KWP 2000 implementation */
#if (SWT_DIAG_USE_KWP2000 != SWT_CFG_ON)
               /* The FSC type and the fact that it should not be saved.      */
               Ret[SWT_STATUS_SKIP +
                   (i * SWT_STATUS_ENTRY_LEN) +
                   SWT_SWID_LEN + 2] =
                        (uint8)SWData[i].FscType | (uint8)SWT_DO_NOT_SAVE_FSC;
#endif /* #if (SWT_DIAG_USE_KWP2000 != SWT_CFG_ON) */

               /* One more SWID.                                              */
               number++;
            }
            else
            {
               RetVal = Swt_RC_BAD_PARAM;
            }
         }

         i++;
      }

      /* We store how many SWID we have found.                                */
      Ret[3] = number;
   }

   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_StoreFSC                                            **
**                                                                            **
** DESCRIPTION    : Stores the given FSC into the Swt handler context.      **
**                                                                            **
** PRECONDITIONS  : 'Fsc' is a valid pointer to a FSC (debug checked)         **
**                                                                            **
** POSTCONDITIONS : The FSC is stored in the context of the handler.          **
**                                                                            **
** PARAMETERS     : SGID      : The ID of the controller                      **
**                  Fsc       : A pointer to the start of the FSC to store    **
**                  FscLength : The length of the FSC                         **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if a parameter is invalid             **
**                  Swt_RC_NO_FREE_SPACE, if the FSC is too large to be     **
**                      stored                                                **
**                  Swt_RC_INVALID_FSC, if the FSC could not be parsed      **
**                  Swt_RC_INVALID_FSC_CREATION_DATE, if the creation       **
**                      date of an already stored FSC is newer than the date  **
**                      of the given FSC                                      **
**                  Swt_RC_SW_NOT_EXISTENT, if the given SWID is not stored **
**                      in the handler or if the upgrade index of the FSC     **
**                      SWID is too old                                       **
**                  Swt_RC_MISSING_SG_DATA, if there is no controller with  **
**                       the given SGID                                       **
**                  Swt_RC_FLASH_WRITE_ERROR, if the FSC could not be       **
**                       stored persistently                                  **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens   **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t  Swt_StoreFSC
(
   const uint8         SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwIdDiag,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   const uint16        FscLength
)
{
   SwtRC_t RetVal;                        /* the return value of the function */
   uint8   posOfSW;          /* The position of the SW in the persistent data */

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
   boolean ShortFSC;             /* to distinguish between short and full FSC */
#if (SWT_SHORT_STORE == SWT_CFG_ON)
   uint8 ShortIndex;   /* The position of the decrypted key in persitent data */
#endif
#endif

   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */
   P2CONST(uint8,AUTOMATIC,SC_FAR) SWIDPtr;          /* The start of the SWID */

   /* Initialise local variables                                              */
   RetVal = Swt_RC_OK;
   posOfSW = 0;
   SWIDPtr = 0;

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
   ShortFSC = FALSE;   
#endif

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( 0 == Fsc )                              /* Check if we got a valid FSC */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_STOREFSC_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

   if( 0 == SWData )
   {
      RetVal = Swt_RC_MISSING_SG_DATA;
   }

   RetVal = Swt_FindSW
               (
                  SWData,
                  NrOfSWIDs,
                  SwIdDiag,
                  &posOfSW,  //ignored
                  TRUE
               );


   if( Swt_RC_OK == RetVal )
   {
#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
      /* check for FSCshort */
      if ( (uint16)SWT_FSC_SHORT_LEN == FscLength)
      {
         ShortFSC = TRUE;
      }
      else
      {
         ShortFSC = FALSE;
      }

      if( ( FALSE == ShortFSC ) &&
          ( Swt_FSC_TYPE_SHORT == SWData[posOfSW].FscType  ) )
      {
         /* We want to store an FSC which is not short to a position where    */
         /* only short FSCs may be stored. This is not allowed.               */
         RetVal = Swt_RC_INVALID_FSC;
      }
   }

   if( Swt_RC_OK == RetVal )
   {
      if (TRUE == ShortFSC)
      {
         SWIDPtr = &Fsc[SWT_SWID_SHORT_POSITION];
      }
      else /* if (TRUE == ShortFSC) */
#endif
      {
         /* Parse the FSC                                                     */
         RetVal = Swt_FSCParse( Fsc, FscLength );

         SWIDPtr = &Fsc[SWT_SWID_POSITION];
      }
   }

   /* Check that there is a SW with the given SWID stored in the SG           */
   if( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_FindSW
               (
                  SWData,
                  NrOfSWIDs,
                  SWIDPtr,
                  &posOfSW,
                  FALSE
               );
   }

   if( Swt_RC_OK == RetVal )
   {
#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
      if ( FALSE == ShortFSC )
#endif
      {
            /* If an FSC is already stored, compare the creation date of the  */
            /* given FSC with that of the already stored FSC.                 */
            RetVal = Swt_FSCCheckDate(
                                          Fsc,
                                          FscLength,
                                          SWData[posOfSW].Fsc,
                                          SWData[posOfSW].FscLength,
                                          SWData[posOfSW].FscState
                                       );
      }
   }

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)

   if( Swt_RC_OK == RetVal )
   {
      /* If the FSC is short, the FSC type should be set to "short".          */
      if ( TRUE == ShortFSC )
      {
         if ( Swt_FSC_TYPE_FULL == SWData[posOfSW].FscType  )
         {
            /* This position is reserved for a full FSC. We cannot store a    */
            /* short FSC here.                                                */
            RetVal = Swt_RC_INVALID_FSC;
         }
         else
         {
            /* This position is reserved for a light or short FSC. Now we     */
            /* will store a short FSC.                                        */
            SWData[posOfSW].FscType = Swt_FSC_TYPE_SHORT;
         }
      }
   }
#endif

   if( Swt_RC_OK == RetVal )
   {
      /* The FSC is imported.                                                 */
      (void)Swt_CommonCopy( SWData[posOfSW].Fsc,
                              Fsc,
                              (uint32)FscLength );

      SWData[posOfSW].FscLength = FscLength;

      SWData[posOfSW].FscState = Swt_STATE_FSC_IMPORTED;

      SWData[posOfSW].SwState = Swt_STATE_SW_DEACTIVATED;

#if ((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON))

      /* Search for the correct SWT-Short data */
      if ( TRUE == ShortFSC )
      {
         /* Search for the correct SWT-Short data */
         RetVal = Swt_FindShortSW(Swt_ShortData, SWData[posOfSW].SwId, &ShortIndex);
    
         if (Swt_RC_OK == RetVal)
         {
            uint8 EmptyArray[1] = {0};
            Swt_CommonCopy(Swt_ShortData[ShortIndex].DEK, EmptyArray, 1);
            Swt_CommonCopy(Swt_ShortData[ShortIndex].Dieffie, EmptyArray, 1);
            Swt_ShortData[ShortIndex].ShortState = Swt_STATE_SHORT_NOTCHECKED;
            
            /* Store status persistent                                        */
            RetVal = Appl_SwtWriteBlock( (uint16)SWT_SHORT_DATA );
         }
      }
#endif
   }

   /* Store status persistent                                                 */
   if( Swt_RC_OK == RetVal )
   {
                                       /* write block into persistent storage */
      RetVal = Appl_SwtWriteBlock( (uint16)SWT_SW_DATA );
   }


   return RetVal;
}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CheckFSC                                            **
**                                                                            **
** DESCRIPTION    : Check if the FSC of the given SW is valid. The FSC to     **
**                  check has to be stored into the handler before a call     **
**                  of this function (see Swt_StoreFSC).                    **
**                                                                            **
** PRECONDITIONS  : 'SwId' is a valid SWID (not checked)                      **
**                                                                            **
** POSTCONDITIONS : The FSC is stored into the persistent storage. If the FSC **
**                  is valid the state of the FSC is set to accepted and the  **
**                  state of the SW is set to activated. If the FSC is        **
**                  invalid state will change.                                **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller                           **
**                  SwId : The ID of the Sw which FSC should be checked       **
**                                                                            **
** RETURN         : Swt_RC_FSC_NOT_EXISTENT, if no FSC with the given SWID  **
**                                           is stored in the handler context **
**                  Swt_RC_FSC_CANCELLED, if the FSC has been disabled      **
**                  Swt_RC_SIG_CHECK_FAILURE, if the signature of the FSC   **
**                                              is not correct                **
**                  Swt_RC_SWID_CHECK_FAILURE, if the upgrade index of the  **
**                                               FSC SWID is too old          **
**                  Swt_RC_KEY_DERIVATION_NOT_ACTIVATED, if the FSC_Enabler **
**                                            for a short FSC is not accepted **
**                  Swt_RC_FGN_ACCESS_FAILURE, if the VIN could not be      **
**                                               accessed                     **
**                  Swt_RC_FGN_CHECK_FAILURE, if the individualisation      **
**                                          attributes of the FSC are invalid **
**                  Swt_RC_VALIDITY_CHECK_FAILURE, if the validity          **
**                                          conditions of the FSC are invalid **
**                  Swt_RC_INVALID_FSC, if the stored FSC is too big or too **
**                                        small                               **
**                  Swt_RC_BAD_FSC_CONTENT, if the FSC contains invalid or  **
**                                            malformed elements              **
**                  Swt_RC_FGN_CHECK_FAILURE, if the FGN or the ECUSNR in   **
**                                       the FSC is not the same as in the SG **
**                  Swt_RC_FLASH_WRITE_ERROR, if it was not possible to     **
**                                  store the state of the handler persistent **
**                  Swt_RC_FLASH_READ_ERROR, if the key could not be        **
**                                        extracted from the FSCS certificate **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens   **
**                  Swt_RC_SW_NOT_EXISTENT, if no software with the given   **
**                                            SwId is stored inside the ECU   **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of this controller                              **
**                  Swt_RC_BAD_PARAM, if one of the arguments was a null    **
**                                      pointer                               **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t  Swt_CheckFSC
(
   const uint8         SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId,
   const boolean       writeNvm
)
{
   SwtRC_t   RetVal;                    /* the return value of the function */
   uint8 Index;                               /* the index of the entry */
   /* A pointer to the software signature state of this SG                    */
   P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) SWSigData;
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */

   P2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) PublicKeyPtr;

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

                      /* An array containing the certificate data for this SG */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) CertData;

   uint8 NrOfCerts ;                /* The amount of certificates for this SG */

                               /* Pointer to the modulus of the FSCS cert key */
   Swt_LNWordType KeyModulus[Swt_LNGetWordLen(SWT_FSC_SIG_LEN_BYTES)];
                              /* Pointer of the exponent of the FSCS cert key */
   Swt_LNWordType KeyExponent[Swt_LNGetWordLen(SWT_FSC_SIG_LEN_BYTES)];
                                                    /* public key information */
   Swt_RSAKeyType PublicKey;
                                     /* serial number of the FSCS certificate */
   uint8 SerialNr[SWT_FSCSID_LEN];
                                     /* the start date of the validity period */
   uint32 StartDate;
                                       /* the end date of the validity period */
   uint32 EndDate;

#endif                            /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */



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

   /* Initialize some local variables.                                        */
   Index = 0;
   RetVal = Swt_RC_OK;
   PublicKeyPtr = 0;
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
   StartDate = 0;
   EndDate = 0;
#endif

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
      RetVal = Swt_RC_MISSING_SG_DATA;
   }

   /* Get the index of the persistent entry                                   */
   if( Swt_RC_OK == RetVal )
   {
      RetVal = Swt_FindSW(SWData,NrOfSWIDs,SwId,&Index,TRUE);
   }

   if( Swt_RC_OK == RetVal )
   {
      /* Check whether the upgrade index of the SWID is 0.                    */
      if( ( 0 == SWData[Index].SwId[2] ) && ( 0 == SWData[Index].SwId[3] ) )
      {
         /* This software does not use FSCs. It can be immediately activated. */

                                                   /* set positive FSC status */
         SWData[Index].FscState = Swt_STATE_FSC_ACCEPTED;

         if( Swt_STATE_SWSIG_ACCEPTED == SWSigData->SigState )
         {
                                                    /* set positive SW status */
            SWData[Index].SwState = Swt_STATE_SW_ACTIVATED;
         }

                                                 /* Store status persistently */
         /* special case, write directly because there is a return after that */
         RetVal = Appl_SwtWriteBlock( (uint16)SWT_SW_DATA );

         /* Immediately return. No need to check the FSC.                     */
         return RetVal;
      }
   }

   /* Check FSC status                                                        */
   if( Swt_RC_OK == RetVal )
   {
      if( Swt_STATE_FSC_NOT_EXISTENT == SWData[Index].FscState )
      {
         RetVal = Swt_RC_FSC_NOT_EXISTENT;
      }
      else if( Swt_STATE_FSC_DISABLED == SWData[Index].FscState )
      {
         RetVal = Swt_RC_FSC_CANCELLED;
      }
      else
      {
         /* Nothing needs to be done here.                                    */
      }
   }

   if( Swt_RC_OK == RetVal )
   {

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)

      /* If this FSC is short, perform the checks for short FSCs. Otherwise,  */
      /* perform the normal FSC checks.                                       */
      if( Swt_FSC_TYPE_SHORT == SWData[Index].FscType )
      {
         RetVal = Swt_ShortFSCCheck( SWData, NrOfSWIDs, Index );
      }
      else

#endif

      {

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

         /* Check FSCS certificate status                                     */         
         if( Swt_FSC_TYPE_FULL == SWData[Index].FscType ) 
         {
            if ( NrOfCerts > Index ) 
            {
               if( Swt_STATE_CERT_NOT_EXISTENT == CertData[Index].CertState )
               {
                  RetVal = Swt_RC_FSCS_CERT_NOT_EXISTENT;
               }
               else if( Swt_STATE_CERT_IMPORTED == CertData[Index].CertState )
               {
                  RetVal = Swt_RC_FSCS_CERT_NOT_CHECKED;
               }
               else if( Swt_STATE_CERT_REJECTED == CertData[Index].CertState )
               {
                  RetVal = Swt_RC_FSCS_CERT_CHECK_FAILURE;
               }
               else
               {
                  /* Nothing needs to be done here.                              */
               }

               /* Parse FSCS certificate to get key information                  */
               if( Swt_RC_OK == RetVal )
               {
                  RetVal = Swt_CertExtractFSCSValues
                     (
                     CertData[Index].Cert,
                     KeyModulus,
                     KeyExponent,
                     SerialNr,
                     &StartDate,
                     &EndDate
                     );

                  if( Swt_RC_OK != RetVal )
                  {
                     RetVal = Swt_RC_FLASH_READ_ERROR;
                  }
                  else
                  {
                     /* Compose public key information                           */
                     PublicKey.Exponent = KeyExponent;
                     PublicKey.Modulus = KeyModulus;                     
#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
                     PublicKey.ModulusExt = 0;
#endif
                     PublicKeyPtr = &PublicKey;
                  }
               }

               if( Swt_RC_OK == RetVal )
               {
                  /* Check the serial number of the FSC                          */
                  RetVal = Swt_FSCCheckFSCSID( SWData[Index].Fsc,
                     SWData[Index].FscLength,
                     SerialNr );
               }

               if( Swt_RC_OK == RetVal )
               {
                  /* Check that the creation date is within the validity period  */
                  RetVal = Swt_FSCCheckFreshness( SWData[Index].Fsc,
                     SWData[Index].FscLength,
                     StartDate,
                     EndDate );
                  if ( Swt_RC_OK != RetVal )
                     RetVal = Swt_RC_FSC_REJECTED;
               }            
            }
            else    //if ( NrOfCerts > Index ) 
            {
               RetVal = Swt_RC_FSCS_CERT_NOT_EXISTENT;
            }
         }
         else //if( Swt_FSC_TYPE_FULL == SWData[Index].FscType ) 
#endif                            /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */
         {
            PublicKeyPtr = Appl_SwtGetPublicFscsKey();
         }

         if( Swt_RC_OK == RetVal )
         {
            /* Check the signature of the FSC                                 */
            RetVal = Swt_FSCCheckSignature( SWData[Index].Fsc,
               SWData[Index].FscLength,
               PublicKeyPtr );

            if ( Swt_RC_OK != RetVal ) 
               RetVal = Swt_RC_SIG_CHECK_FAILURE;
         }

         /* Check individualisation attributes                                */
         if( Swt_RC_OK == RetVal )
         {
            RetVal = Swt_FSCCheckIndivAttr( SWData[Index].Fsc,
               SWData[Index].FscLength,
               Appl_SwtGetVinInternal() );

            if ( Swt_RC_OK != RetVal ) 
               RetVal = Swt_RC_FGN_CHECK_FAILURE;
         }

         if( Swt_RC_OK == RetVal )
         {
            /* Check the validity conditions                                  */
            RetVal = Swt_FSCCheckValidity( SWData[Index].Fsc,
               SWData[Index].FscLength);

            if ( Swt_RC_OK != RetVal ) 
               RetVal = Swt_RC_VALIDITY_CHECK_FAILURE;
         }
      }
   }

   /* Set positive FSC status                                                 */
   if( Swt_RC_OK == RetVal )
   {
                                                   /* set positive FSC status */
      UpdateSwtNvm(SWData[Index].FscState, Swt_STATE_FSC_ACCEPTED, nvmSwtSwData)

      if( Swt_STATE_SWSIG_ACCEPTED == SWSigData->SigState )
      {
                                                    /* set positive SW status */
         UpdateSwtNvm(SWData[Index].SwState, Swt_STATE_SW_ACTIVATED, nvmSwtSwData);
      }
   }
   else if( ( ( ( ( ( ( ( Swt_RC_SIG_CHECK_FAILURE              == RetVal )   ||
                        ( Swt_RC_FGN_CHECK_FAILURE              == RetVal ) ) ||
                        ( Swt_RC_VALIDITY_CHECK_FAILURE         == RetVal ) ) ||
                        ( Swt_RC_SWID_CHECK_FAILURE             == RetVal ) ) ||
                        ( Swt_RC_FSC_CHECK_FAILURE              == RetVal ) ) ||
                        ( Swt_RC_FSCS_CERT_NOT_EXISTENT         == RetVal ) ) ||
                        ( Swt_RC_WRONG_FSCS_ID_IN_FSC           == RetVal ) ) ||
                        ( Swt_RC_KEY_DERIVATION_NOT_ACTIVATED   == RetVal ) ) 
   {
      UpdateSwtNvm(SWData[Index].FscState, Swt_STATE_FSC_REJECTED, nvmSwtSwData);

                                                    /* set negative SW status */
      UpdateSwtNvm(SWData[Index].SwState, Swt_STATE_SW_DEACTIVATED, nvmSwtSwData);
   }
   else
   {
                                                  /* Nothing to be done here. */
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
   }

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DisableFSC                                          **
**                                                                            **
** DESCRIPTION    : Disable a stored FSC and the corresponding SW.            **
**                                                                            **
** PRECONDITIONS  : 'SwId' is a valid SWID (not checked)                      **
**                                                                            **
** POSTCONDITIONS : The FSC is set to state disabled and the corresponding    **
**                  SW is deactivated in the persistent storage.              **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller                           **
**                  SwId : The ID of the Sw which FSC should be checked       **
**                                                                            **
** RETURN         : Swt_RC_FSC_NOT_EXISTENT, if no FSC with the given SWID  **
**                                           is stored in the handler context **
**                  Swt_RC_FSC_CANCELLED, if the corresponding FSC is       **
**                                          already disabled                  **
**                  Swt_RC_FLASH_WRITE_ERROR, if it was not possible to     **
**                                  store the state of the handler persistent **
**                  Swt_RC_MISSING_SG_DATA, if 'SGID' does not match the    **
**                       SGID of this controller                              **
**                  Swt_RC_BAD_PARAM, if one of the arguments was a null    **
**                                      pointer                               **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens   **
**                  Swt_RC_OK, if all operations were successful            **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t  Swt_DisableFSC
(
   const uint8         SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId
)
{   
   SwtRC_t RetVal;                      /* the return value of the function */

   uint8_least Index;                               /* the index of the entry */
   uint8_least i;                                            /* loop variable */
   boolean existent;                   /* flag indicating the existence of SW */
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
         (uint8)SWT_HANDLER_DISABLEFSC_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   Index = 0;

   RetVal = Swt_RC_OK;

   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

   if( 0 == SWData )
   {
      RetVal = Swt_RC_MISSING_SG_DATA;
   }

   /* Get the index of the persistent entry                                   */
   if( Swt_RC_OK == RetVal )
   {
      i = (uint8_least)0U;
      Index = (uint8_least)0U;
      existent = FALSE;
      while( ((uint8_least)NrOfSWIDs > i) && (FALSE == existent) )
      {
         /* Look for existing SW                                              */
         if( Swt_STATE_SW_NOT_EXISTENT != SWData[i].SwState )
         {
            if
            (
               Swt_RC_EQUAL ==
               Swt_CommonCompare
               (
                  SwId,
                  SWData[i].SwId,
                  (uint32)SWT_SWID_LEN
               )
            )
            {
               Index = i;
               existent = TRUE;
            }
         }
         i++;
      }

      if( FALSE == existent )
      {
         RetVal = Swt_RC_SW_NOT_EXISTENT;
      }
   }

   /* Set negative FSC status, if necessary                                   */
   if( Swt_RC_OK == RetVal )
   {
      if( Swt_STATE_FSC_NOT_EXISTENT == SWData[Index].FscState )
      {
         RetVal = Swt_RC_FSC_NOT_EXISTENT;
      }
      else if( Swt_STATE_FSC_DISABLED == SWData[Index].FscState )
      {
         RetVal = Swt_RC_FSC_CANCELLED;
      }
      else
      {
                                                   /* set negative FSC status */
         SWData[Index].FscState = Swt_STATE_FSC_DISABLED;
                                                    /* set negative SW status */
         SWData[Index].SwState = Swt_STATE_SW_DEACTIVATED;

                                                 /* Store status persistently */
         RetVal = Appl_SwtWriteBlock( (uint16)SWT_SW_DATA );
      }
   }

   return RetVal;
}





/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetFSC                                              **
**                                                                            **
** DESCRIPTION    : When given a SwId, returns a pointer to the start of the  **
**                  corresponding FSC and its length                          **
**                                                                            **
** PRECONDITIONS  : 'SwId' is a valid SWID (not checked)                      **
**                  'FscPtr' is a valid pointer (not checked)                 **
**                  'FscLengthPtr' is a valid pointer (not checked)           **
**                                                                            **
** POSTCONDITIONS : '*FscPtr' contains the start of the FSC                   **
**                  '*FscLengthPtr' contains the length of the FSC            **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller whose whose FSC shall be  **
**                         returned                                           **
**                  SwId : The SWID of the SW whose FSC shall be returned     **
**                  FscPtr : A pointer to an address variable where the start **
**                           of the FSC shall be stored                       **
**                  FscLengthPtr : A pointer to the variable where the length **
**                                 of the FSC shall be stored                 **
**                                                                            **
** RETURN         : Swt_RC_OK,               if the corresponding FSC is    **
**                                             found                          **
**                  Swt_RC_MISSING_SG_DATA,  if 'SGID' does not match the   **
**                                             SGID of this controller        **
**                  Swt_RC_FSC_NOT_EXISTENT, if no FSC with the given       **
**                                             SwId is stored inside the ECU  **
**                  Swt_RC_SW_NOT_EXISTENT, if no software with the given   **
**                                            SwId is stored inside the ECU   **
**                  Swt_RC_BAD_PARAM, if one of the arguments was a null    **
**                                      pointer                               **
**                  Swt_RC_UNKNOWN_ERROR, if something unexpected happens   **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_GetFSC
(
   const uint8            SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   SwId,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) FscPtr,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)   FscLengthPtr
)
{
   SwtRC_t RetVal;                      /* the return value of the function */
   uint8     i;                                        /* the index of the sw */
   /* A pointer to start of the array containing the SW data for this SG      */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData;
   uint8 NrOfSWIDs ;            /* The length of the SWData array for this SG */

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( ( 0 == SwId ) ||
       ( 0 == FscPtr ) ||
       ( 0 == FscLengthPtr ) )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_HANDLER_GETFSC_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   i = 0;

   RetVal = Swt_RC_OK;

   /* Get the SW data for this SG.                                            */
   SWData = Swt_GetSWData(SGID,&NrOfSWIDs);

   if( 0 == SWData )
   {
      RetVal = Swt_RC_MISSING_SG_DATA;
   }

   if( Swt_RC_OK == RetVal )
   {
      /* Is there a software with the given SwId?                             */
      RetVal = Swt_FindSW(SWData,NrOfSWIDs,SwId,&i,TRUE);
   }

   if( Swt_RC_OK == RetVal )
   {
      /* Is there an FSC at the given index?                                  */
      if( Swt_STATE_FSC_NOT_EXISTENT == SWData[i].FscState )
      {
         RetVal = Swt_RC_FSC_NOT_EXISTENT;
      }
      else
      {
         *FscPtr = SWData[i].Fsc;
         *FscLengthPtr = SWData[i].FscLength;
         RetVal = Swt_RC_OK;
      }
   }

   return RetVal;
}


#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/


/*** End of file **************************************************************/
