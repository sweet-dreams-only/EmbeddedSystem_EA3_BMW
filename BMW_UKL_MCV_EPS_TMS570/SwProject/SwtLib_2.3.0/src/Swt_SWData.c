/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_SWData.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Routines which return the software data for a given SG.       **
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


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_SWData.h"            /* declarations for the SW data routines */
#include "Swt_Common.h"                         /* byte comparison function */

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

#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"

                            /* A list of all SGIDs this module has to handle. */
const uint8 Swt_SGIDs[SWT_NR_OF_SGIDS] = { SWT_SGIDS };

#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"


#if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_OFF)

#define SWT_START_SEC_CONST_UNSPEC
#include "MemMap.h"

const Swt_SWDataType Swt_SWDataDefault[SWT_NR_OF_SWIDS] =
{
   SWT_SW_DATA_DEFAULT_INIT
};

const Swt_SWSigDataType Swt_SWSigDataDefault[SWT_NR_OF_SGIDS] =
{
   SWT_SW_SIG_DATA_DEFAULT_INIT
};

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
const Swt_CertDataType Swt_CertDataDefault[SWT_NR_OF_CERTS] =
{
   SWT_CERT_DATA_DEFAULT_INIT
};
#endif

#if (SWT_SHORT_STORE == SWT_CFG_ON)
const Swt_ShortDataType Swt_ShortDataDefault[SWT_NR_OF_SHORT] =
{
   SWT_SHORT_DATA_DEFAULT_INIT
};
#endif

#define SWT_STOP_SEC_CONST_UNSPEC
#include "MemMap.h"

#endif                  /* #if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_OFF) */


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define SWT_START_SEC_VAR_NO_INIT
#include "MemMap.h"

/* The SW data which should be stored persistently. The NVRAM manager knows   */
/* this variable and can backup its value into and restore the value from     */
/* EEPROM.                                                                    */
/* This array is a concatenation of the arrays for all the given SGIDs.       */
Swt_SWDataType Swt_SWData[SWT_NR_OF_SWIDS];

/* The software signature state. This must also be stored persistently.       */
Swt_SWSigDataType Swt_SWSigData[SWT_NR_OF_SGIDS];

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
/* The certificate data. This array is a concatenation of the arrays for all  */
/* the given SGIDs.                                                           */
Swt_CertDataType Swt_CertData[SWT_NR_OF_CERTS];
#endif

#if (SWT_SHORT_STORE == SWT_CFG_ON)
/* The FSC Short. This array is a concatenation of the arrays for all  */
/* the given SGIDs.                                                           */
Swt_ShortDataType Swt_ShortData[SWT_NR_OF_SHORT];
#endif


#define SWT_STOP_SEC_VAR_NO_INIT
#include "MemMap.h"

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
** FUNC-NAME      : Swt_GetSWData                                           **
**                                                                            **
** DESCRIPTION    : For a given SGID, returns the start address and the       **
**                  length of an array which contains the SW data of that SG. **
**                                                                            **
** PRECONDITIONS  : none                                                      **
**                                                                            **
** POSTCONDITIONS : "*NrOfSWIDsPtr" will contain the number of SWIDs of the   **
**                  SG with ID "SGID".                                        **
**                                                                            **
** PARAMETERS     : SGID     - The ID of the SG whose SW data should be       **
**                             returned                                       **
**                  NrOfSWIDsPtr - A pointer to a variable where the amount   **
**                                 of SWIDs of the current SG should be stored**
**                                                                            **
** RETURN         : 0, if the given SGID is unknown                           **
**                  The start of an array of size "*NrOfSWIDsPtr" which       **
**                  contains the SW data of the given SG, otherwise.          **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         :                                                           **
**                                                                            **
*******************************************************************************/
P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) Swt_GetSWData
(
   const uint8                        SGID,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) NrOfSWIDsPtr
)
{
   uint8 i;                                                   /* loop counter */
   uint8 Pos;            /* The position of the given SGID in the SGID array. */
   /* A pointer to the start of the array which contains the SW data for the  */
   /* given SGID.                                                             */
   P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) arrayStart;

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
   /* An array which contains, for each virtual SG, the amount of SWIDs the   */
   /* SG has got.                                                             */
   SWT_STATIC_VAR const uint8 Swt_NrOfSWIDs[SWT_NR_OF_SGIDS] =
                                               { SWT_NR_OF_SWIDS_ARRAY_INIT };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"

          /* Initialize "Pos" with a value which it could not normally reach. */
   Pos = (uint8)SWT_NR_OF_SGIDS;

   /* Find the position of the given SGID in the SGID array and store it in   */
   /* "Pos".                                                                  */
   for ( i = 0; i < (uint8)SWT_NR_OF_SGIDS; i++ )
   {
      if ( SGID == Swt_SGIDs[i] )
      {
         Pos = i;
      }
   }

                                               /* Did we find the given SGID? */
   if ( Pos < (uint8)SWT_NR_OF_SGIDS )
   {
                                                        /* We found the SGID. */

                  /* Return the size of the SW data array in "*NrOfSWIDsPtr". */
      *NrOfSWIDsPtr = Swt_NrOfSWIDs[Pos];

                   /* Find the start of the SW data array for the given SGID. */

      arrayStart = Swt_SWData;

      for(i = 0; i < Pos; i++)
      {
         arrayStart = &arrayStart[Swt_NrOfSWIDs[i]];
      }
   }
   else
   {
                            /* We did not find the SGID. Return error values. */
      arrayStart    = 0;
      *NrOfSWIDsPtr = 0;
   }

   return arrayStart;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetSWSigData                                        **
**                                                                            **
** DESCRIPTION    : For a given SGID, returns the start address of the data   **
**                  element which contains the SW signature data of that SG.  **
**                                                                            **
** PRECONDITIONS  : none                                                      **
**                                                                            **
** POSTCONDITIONS : none                                                      **
**                                                                            **
** PARAMETERS     : SGID     - The ID of the SG whose SW data should be       **
**                             returned                                       **
**                                                                            **
** RETURN         : 0, if the given SGID is unknown                           **
**                  The start address of an element which contains the        **
**                  signature data of the given SG, otherwise.                **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         :                                                           **
**                                                                            **
*******************************************************************************/
P2VAR(Swt_SWSigDataType,AUTOMATIC,SC_FAR) Swt_GetSWSigData
(
   const uint8 SGID
)
{
   uint8 i;                                                   /* loop counter */
   uint8 Pos;            /* The position of the given SGID in the SGID array. */

          /* Initialize "Pos" with a value which it could not normally reach. */
   Pos = (uint8)SWT_NR_OF_SGIDS;

   /* Find the position of the given SGID in the SGID array and store it in   */
   /* "Pos".                                                                  */
   for ( i = 0; i < (uint8)SWT_NR_OF_SGIDS; i++ )
   {
      if ( SGID == Swt_SGIDs[i] )
      {
         Pos = i;
      }
   }

                                               /* Did we find the given SGID? */
   if ( Pos < (uint8)SWT_NR_OF_SGIDS )
   {
                                                        /* We found the SGID. */
      return &Swt_SWSigData[Pos];
   }
   else
   {
                             /* We did not find the SGID. Return error value. */
      return 0;
   }
}




#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_GetCertData                                         **
**                                                                            **
** DESCRIPTION    : For a given SGID, returns the start address and the       **
**                  length of an array which contains the certificate data    **
**                  of that SG.                                               **
**                                                                            **
** PRECONDITIONS  : none                                                      **
**                                                                            **
** POSTCONDITIONS : "*NrOfCertsPtr" will contain the number of certificates   **
**                  of the SG with ID "SGID".                                 **
**                                                                            **
** PARAMETERS     : SGID     - The ID of the SG whose certificate data should **
**                             be returned                                    **
**                  NrOfCertsPtr - A pointer to a variable where the amount   **
**                                 of certificates of the current SG should   **
**                                 be stored                                  **
**                                                                            **
** RETURN         : 0, if the given SGID is unknown                           **
**                  The start of an array of size "*NrOfCertsPtr" which       **
**                  contains the certificate data of the given SG, otherwise. **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         :                                                           **
**                                                                            **
*******************************************************************************/
P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) Swt_GetCertData
(
   const uint8                        SGID,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) NrOfCertsPtr
)
{
   uint8 i;                                                   /* loop counter */
   uint8 Pos;            /* The position of the given SGID in the SGID array. */
   /* A pointer to the start of the array which contains the certifcate data  */
   /* for the given SGID.                                                     */
   P2VAR(Swt_CertDataType,AUTOMATIC,SC_FAR) arrayStart;

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_8BIT
#include "MemMap.h"
   /* An array which contains, for each virtual SG, the amount of             */
   /* certificates the SG must store.                                         */
   SWT_STATIC_VAR const uint8 Swt_NrOfCerts[SWT_NR_OF_SGIDS] =
                                               { SWT_NR_OF_CERTS_ARRAY_INIT };
#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"

          /* Initialize "Pos" with a value which it could not normally reach. */
   Pos = (uint8)SWT_NR_OF_SGIDS;

   /* Find the position of the given SGID in the SGID array and store it in   */
   /* "Pos".                                                                  */
   for ( i = 0; i < (uint8)SWT_NR_OF_SGIDS; i++ )
   {
      if ( SGID == Swt_SGIDs[i] )
      {
         Pos = i;
      }
   }

                                               /* Did we find the given SGID? */
   if ( Pos < (uint8)SWT_NR_OF_SGIDS )
   {
                                                        /* We found the SGID. */

         /* Return the size of the certificate data array in "*NrOfCertsPtr". */
      *NrOfCertsPtr = Swt_NrOfCerts[Pos];

          /* Find the start of the certificate data array for the given SGID. */

      arrayStart = Swt_CertData;

      for(i = 0; i < Pos; i++)
      {
         arrayStart = &arrayStart[Swt_NrOfCerts[i]];
      }
   }
   else
   {
                            /* We did not find the SGID. Return error values. */
      arrayStart    = 0;
      *NrOfCertsPtr = 0;
   }

   return arrayStart;
}

#endif                            /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FindSW                                                **
**                                                                            **
** DESCRIPTION    : Given a SwId, the function looks in SWData whether        **
**                  a software which fits this SwId exists. If it does exist, **
**                  the index of that software is returned.                   **
**                                                                            **
** PRECONDITIONS  : 'SWData' is a valid pointer (not checked)                 **
**                  'SwId'   is a valid SWID (not checked)                    **
**                  'PosPtr' is a valid pointer (not checked)                 **
**                                                                            **
** POSTCONDITIONS : 'PosPtr' contains the index of the software with the      **
**                           given SwId                                       **
**                                                                            **
** PARAMETERS     : SWData: A pointer to the start of the SW data array which **
**                          is to be checked                                  **
**                  NrOfSWIDs: The length of the SW data array                **
**                  SwId : The SWID of the corresponding SW                   **
**                  PosPtr : A pointer to the variable where the index shall  **
**                           be stored                                        **
**                  Strict: If this is TRUE, the given SwId must be identical **
**                          to the one given in SWData. If this is FALSE,     **
**                          the application numbers of both SWIDs must be     **
**                          identical and the upgrade index of the given SWID **
**                          must be at least as big as the one given in       **
**                          SWData.                                           **
**                                                                            **
** RETURN         : Swt_RC_OK,              if the corresponding SW is        **
**                                            found                           **
**                  Swt_RC_SW_NOT_EXISTENT, if no software with the given     **
**                                            SwId is stored inside the ECU   **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FindSW
(
   CONSTP2CONST(Swt_SWDataType,AUTOMATIC,SC_FAR) SWData,
   uint8                                           NrOfSWIDs,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)            SwId,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)              PosPtr,
   boolean                                         Strict
)
{
   uint8 i;                                                  /* loop variable */
   SwtRC_t ComparisonResult;

   i = 0;
   while( NrOfSWIDs > i )
   {
      /* Look for existing SW                                                 */
      if( Swt_STATE_SW_NOT_EXISTENT != SWData[i].SwState )
      {
         if( TRUE == Strict )
         {
            ComparisonResult =
                            Swt_CommonCompare( SwId,
                                                 SWData[i].SwId,
                                                 (uint32)SWT_APP_NUMBER_LEN );

         }
         else
         {
            ComparisonResult = Swt_FSCCheckSWID( SwId,
                                                   SWData[i].SwId );

            if ( Swt_RC_OK == ComparisonResult )
            {
               ComparisonResult = Swt_RC_EQUAL;
            }
         }


         /* Compare Ids of SW                                                 */
         if( Swt_RC_EQUAL == ComparisonResult )
         {
            *PosPtr = i;
            return Swt_RC_OK;
         }
      }
      i++;
   }

   return Swt_RC_SW_NOT_EXISTENT;
}


#if ((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON))
/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_FindShortSW                                           **
**                                                                            **
** DESCRIPTION    : Given a SwId, the function looks in ShortData whether     **
**                  a software which fits this SwId exists. If it does exist, **
**                  the index of that software is returned.                   **
**                                                                            **
** PRECONDITIONS  : 'ShortData'  is a valid pointer (not checked)             **
**                  'SwId'       is a valid SWID (not checked)                **
**                  'ShortIndex' is a valid pointer (not checked)             **
**                                                                            **
** POSTCONDITIONS : 'ShortIndex' contains the index of the software with the  **
**                               given SwId                                   **
**                                                                            **
** PARAMETERS     : SWData: A pointer to the start of the Short data array    **
**                          which is to be checked                            **
**                  SwId : The SWID of the corresponding SW                   **
**                  ShortIndex: A pointer to the variable where the index     **
**                           shall be stored                                  **
**                                                                            **
** RETURN         : Swt_RC_OK,              if the corresponding SW is        **
**                                            found                           **
**                  Swt_RC_UNKNOWN_ERROR, if no software with the given       **
**                                            SwId is stored inside the ECU   **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_FindShortSW
(
   CONSTP2CONST(Swt_ShortDataType,AUTOMATIC,SC_FAR) ShortData,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)             SwId,
   CONSTP2VAR(uint8, AUTOMATIC,SC_FAR)              ShortIndex
)
{
   SwtRC_t RetVal = Swt_RC_OK;
   uint8 Index;

   for (Index = 0; Index <= SWT_NR_OF_SHORT; Index++)
   {
      if (Swt_RC_EQUAL == Swt_CommonCompare(ShortData[Index].SwId, SwId, SWT_SWID_LEN))
      {
         break;
      }
   }
   /* If there is a configuration error, the correct entry in Swt_ShortData cannot be found. */
   if (SWT_NR_OF_SHORT <= Index)
   {
      RetVal = Swt_RC_UNKNOWN_ERROR;
   }
   else
   {
      *ShortIndex = Index;
   }
   return RetVal;
}
#endif /* ((SWT_USE_SWT_SHORT == SWT_CFG_ON) && (SWT_SHORT_STORE == SWT_CFG_ON)) */

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/

/*** End of file **************************************************************/
