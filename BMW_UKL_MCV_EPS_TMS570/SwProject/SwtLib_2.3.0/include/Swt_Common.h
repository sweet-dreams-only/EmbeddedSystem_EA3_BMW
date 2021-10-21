/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Common.h                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Common declarations for the Swt                             **
**                                                                            **
**  REMARKS   : This file contains commonly used code for the module Swt.   **
**              Most of these functions are fallback functions for memory     **
**              handling using non-standard pointers, like far/huge pointers. **
**              It is used internally by the crypto routines, the parser and  **
**              the handler.                                                  **
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

#if (!defined SWT_COMMON_H)            /* preprocessor exclusion definition */
#define SWT_COMMON_H

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
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"
extern SwtRC_t Swt_CommonCompare
(
   CONSTP2CONST(void,AUTOMATIC,SC_FAR)  BlockA,
   CONSTP2CONST(void,AUTOMATIC,SC_FAR)  BlockB,
   const uint32 ByteLength
);

extern SwtRC_t Swt_CommonCopy
(
   CONSTP2VAR(void,AUTOMATIC,SC_FAR)        Dest,
   CONSTP2CONST(void,AUTOMATIC,SC_FAR)  Src,
   const uint32        ByteLength
);
#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                        /* if (!defined SWT_COMMON_H) */
/*** End of file **************************************************************/
