/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Diag_Cfg.h                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Diagnostic configuration file                                 **
**                                                                            **
**  REMARKS   : --                                                            **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0: 23.10.2007, miwe: ported from SC6.7.2 file version V1.1.0
 */

#ifndef DIAG_CFG_H
#define DIAG_CFG_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types */
#include "FreeTimer.h"            /* free running timer driver initialization */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* Mapping of CreateRandomNumber() to FreeTimer */
#define CreateRandomNumber()                      FreeTimer_CreateRandomNumber()

#endif /* DIAG_CFG_H                                                          */

/*** End of file **************************************************************/
