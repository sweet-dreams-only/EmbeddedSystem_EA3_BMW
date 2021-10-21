/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Full.h                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Declaration of SWT Full handler services.                     **
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

#if (!defined SWT_FULL_H)              /* preprocessor exclusion definition */
#define SWT_FULL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_SWData.h"

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/



/*******************************************************************************
**                      Global Constants                                      **
*******************************************************************************/



/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/



/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"


extern SwtRC_t Swt_StoreCert
(
   const uint8                            SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   SwId,
   const uint8                            CertType,
   const uint32                           CertLength,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   Cert
);

extern SwtRC_t Swt_CheckCert
(
   const uint8                            SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   SwId,
   const uint8                            CertType,
   const boolean                          nvmWrite
);

extern SwtRC_t Swt_GetCert
(
   const uint8                            SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)   SwId,
   const uint8                            CertType,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) CertPtr,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)    CertLengthPtr
);

extern SwtRC_t Swt_GetSigSID
(
   const uint8                            SGID,
   P2VAR(uint8,AUTOMATIC,SC_FAR)          Ret
);


#define SWT_STOP_SEC_CODE
#include "MemMap.h"


#endif                                          /* if (!defined SWT_FULL_H) */

/*** End of file **************************************************************/
