/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Version.c                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : BMW Group                                                     **
**                                                                            **
**  PURPOSE   : Definitions for SWT Version service.                          **
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
** cr           Christoph Raber            BMW AG                             **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0    : 10.02.2011, cr   : initial release
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Swt_Common.h"

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

/* SAP numbers not yet defined because LH not yet released */
const uint8 SAPDoc[]    = { '0','0','0','0','0','0','0','0'};
const uint8 SAPSubDoc[] = { '0','0','0' };
const uint8 SAPDocVer[] = { '0','0' };

const uint8 Major[] = { '2' };
const uint8 Minor[] = { '3' };
const uint8 Patch[] = { '0' };
const uint8 Index[] = { '0' };

#define SWT_STOP_SEC_CONST_8BIT
#include "MemMap.h"



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
** FUNC-NAME      : Swt_GetVersion                                            **
**                                                                            **
** DESCRIPTION    : Retrun the version of the SWT-Lib                         **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : SGID : The ID of the controller whose SWT-Lib verson      **
**                         shall be returned                                  **
**                                                                            **
** RETURN         : Swt_RC_OK                                                 **               
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_GetVersion
(
   const uint8         SGID,
   CONSTP2VAR(uint8, AUTOMATIC,SC_FAR) VersionPtr,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR) VersionLengthPtr
)
{
   SwtRC_t ret = Swt_RC_OK;
   uint8 SAPLen = sizeof(SAPDoc) + sizeof(SAPSubDoc) + sizeof(SAPDocVer);
   uint8 VerLen = sizeof(Major) + sizeof(Minor) + sizeof(Patch) + sizeof(Index);

   if (*VersionLengthPtr < (SAPLen + VerLen))
   {
      ret = Swt_RC_BAD_PARAM;
   }
   
   if (Swt_RC_OK == ret)
   {
      Swt_CommonCopy( &VersionPtr[0],                                  SAPDoc, sizeof(SAPDoc));
      Swt_CommonCopy( &VersionPtr[sizeof(SAPDoc)],                     SAPSubDoc, sizeof(SAPSubDoc));
      Swt_CommonCopy( &VersionPtr[sizeof(SAPDoc) + sizeof(SAPSubDoc)], SAPDocVer, sizeof(SAPDocVer));
      Swt_CommonCopy( &VersionPtr[SAPLen],                                           Major, sizeof(Major));
      Swt_CommonCopy( &VersionPtr[SAPLen+sizeof(Major)],                             Minor, sizeof(Minor));
      Swt_CommonCopy( &VersionPtr[SAPLen+sizeof(Major)+sizeof(Minor)],               Patch, sizeof(Patch));
      Swt_CommonCopy( &VersionPtr[SAPLen+sizeof(Major)+sizeof(Minor)+sizeof(Patch)], Index, sizeof(Index));
     
      *VersionLengthPtr = SAPLen + VerLen;                        
   }
   return ret;
}

#define SWT_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/


/*** End of file **************************************************************/
