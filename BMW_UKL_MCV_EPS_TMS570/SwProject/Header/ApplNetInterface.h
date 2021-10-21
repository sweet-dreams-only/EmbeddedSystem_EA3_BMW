/*******************************************************************************
**                                                                            **
**  SRC-MODULE: ApplNetInterface.h                                            **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : This module contains all communication bus dependend          **
**              function calls, for example: module initialisation, start     **
**              and stop of communication on the supported communication      **
**              buses, reinitialisation of the communication buses.           **
**              This module within the new functions called out from the      **
**              diagnosis eliminates the communication bus dependencies.      **
**                                                                            **
**  REMARKS   : ---                                                           **
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
** miwe         Michael Weger              EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0: 20.11.2007, olgo: integration of VSM
 *         27.08.2007, miwe: ported from SC6.7.2 file version V3.0.0
 */

#ifndef APPLNETINTERFACE_H
#define APPLNETINTERFACE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>                              /* AUTOSAR Standard Types */


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

extern boolean applPassiveWakeupFlag;
extern uint32                 netMsgMileKm;


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

extern void ApplNetInterface_Init(void);
extern void ApplHandleBusState(void);

#endif /* APPLNETINTERFACE_H                                                  */

/*** End of file **************************************************************/

