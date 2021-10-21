/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Handler.h                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Declaration of SWT Light handler services.                    **
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

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.9.0    : 28.11.2006, mg   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 * V2.2.0    : 15.05.2008, mp   : moved public API functions to Swt_Appl.h
 */

#if (!defined SWT_HANDLER_H)           /* preprocessor exclusion definition */
#define SWT_HANDLER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */

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

extern SwtRC_t Swt_CheckSWSig
(
    const uint8 SGID,
    const boolean writeNvm
);

extern SwtRC_t Swt_GetSWIDFunctional
(
   const uint8   SGID,
   const uint16  RetMaxLen,
         P2VAR(uint8,AUTOMATIC,SC_FAR) Ret
);

extern SwtRC_t Swt_GetSWID
(
   const uint8   SGID,
   const uint16  RetMaxLen,
         P2VAR(uint8,AUTOMATIC,SC_FAR) Ret
);

extern SwtRC_t Swt_GetStatus
(
   const uint8   SGID,
   const uint16  RetMaxLen,
         P2VAR(uint8,AUTOMATIC,SC_FAR) Ret
);

extern SwtRC_t  Swt_StoreFSC
(
   const uint8         SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwIdDiag,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Fsc,
   const uint16        FscLength
);

extern SwtRC_t Swt_CheckFSC
(
   const uint8         SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId,
   const boolean       writeNvm
);

extern SwtRC_t Swt_DisableFSC
(
   const uint8         SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId
);

extern SwtRC_t Swt_GetFSC
(
   const uint8                                                    SGID,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)                           SwId,
   CONSTP2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR)   FscPtr,
   CONSTP2VAR(uint16,AUTOMATIC,SC_FAR)                            FscLengthPtr
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                       /* if (!defined SWT_HANDLER_H) */
/*** End of file **************************************************************/
