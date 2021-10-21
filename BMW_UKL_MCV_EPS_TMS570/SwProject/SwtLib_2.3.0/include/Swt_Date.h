/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Date.h                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Routines to parse an encoded date as stored in certificates   **
**              or FSCs.                                                      **
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

#if (!defined SWT_DATE_H)            /* preprocessor exclusion definition */
#define SWT_DATE_H

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


/* the type of an encoding of a date. */
typedef enum
{
   Swt_DATE_FSC_TIME = 0x00,                 /* date format as used in FSCs */
   Swt_DATE_UTC_TIME = 0x17,             /* UTCTime, see X.690 chapter 11.8 */
   Swt_DATE_GENERALIZED_TIME = 0x18 /* Generalized Time, X.690 chapter 11.7 */
}
Swt_DateType;



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

extern uint32 Swt_DateGet
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Date,
   const Swt_DateType                 DateType
);

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif                                        /* if (!defined SWT_DATE_H) */
/*** End of file **************************************************************/
