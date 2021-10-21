/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_PBKDF1.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for the PBKDF1 routines                           **
**                                                                            **
**  REMARKS   : Implementation of the mathematical operations needed for the  **
**              PBKDF1 algorithm.                                             **
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
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.1.0    : 08.02.2007, jd   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

#if (!defined SWT_PBKDF1_H)            /* preprocessor exclusion definition */
#define SWT_PBKDF1_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define SWT_PBKDF1_SALT_LEN_BYTES        8U

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

extern SwtRC_t Swt_PBKDF1
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Password,
   const uint8                          PasswordLen,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Salt,
   const uint8                          Iterations,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)   Key,
   const uint8                          KeyLen
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                        /* if (!defined SWT_PBKDF1_H) */
/*** End of file **************************************************************/
