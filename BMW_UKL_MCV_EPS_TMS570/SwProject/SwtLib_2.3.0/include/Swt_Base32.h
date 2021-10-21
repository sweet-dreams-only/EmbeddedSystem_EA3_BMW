/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Base32.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for the Base32 routines                           **
**                                                                            **
**  REMARKS   : Implementation of the mathematical operations needed for the  **
**              Base32 algorithm.                                             **
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
** jd           Jochen Decker              Elektrobit Automotive GmbH         **
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.1.0    : 20.02.2007, jd   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

#if (!defined SWT_BASE32_H)            /* preprocessor exclusion definition */
#define SWT_BASE32_H

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

extern SwtRC_t Swt_Base32Decode
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) EncodedData,
   uint16 EncodedDataLength,
   P2VAR(uint8,AUTOMATIC,SC_FAR) Data,
   P2VAR(uint16,AUTOMATIC,SC_FAR) DataLength
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                        /* if (!defined SWT_BASE32_H) */
/*** End of file **************************************************************/
