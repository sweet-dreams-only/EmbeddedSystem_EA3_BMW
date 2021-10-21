/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Appl_Src_Cfg.h                                                **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Modular make environment. Contains configuration parameters   **
**              which are exclusively dedicated to the application source     **
**              files located in directory 'template/application/source'.     **
**              The 'application source' is considered as a sub component of  **
**              the whole application.                                        **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
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
** hauf         Andreas Hauf               EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.4: 07.04.2010, anam: CR70617: #define Appl_CheckProgrammingPreConditions() 
                                      back to TRUE.  
 * V1.0.3: 27.01.2010, gema: CR70539: Template_Can_Application: Compiler 
 *                                    switches shall have defined values  
 * V1.0.2: 30.06.2009, hauf: CR70221: No DTC required by FP_4247
 * V1.0.1: 20.11.2008, miwe: merged with SC6.7.4
 * V1.0.0: 27.08.2007, miwe: ported from SC6.7.2 file version V3.1.0
 */

#ifndef APPL_SRC_CFG_H
#define APPL_SRC_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/**** User call back ApplicationFirstStart defined empty ****/
#define ApplicationFirstStart()

/**** User call back Appl_CheckProgrammingPreConditions defined empty ****/
/*
 * The callback should contain the check of the programming preconditions. It
 * must be implemented by the ECU developer.
 * Prototype: boolean Appl_CheckProgrammingPreConditions (void);
 * Return:    TRUE:  all preconditions are fulfilled
 *            FALSE: at least one precondition is not fulfilled
 */
#define Appl_CheckProgrammingPreConditions()          TRUE

/**** User call back UserCallback_CheckProgrammingPreConditions defined empty */
/*
 * The callback should contain the check of the programming preconditions. It
 * must be implemented by the ECU developer.
 * Write every precondition that is not fulfilled into the buffer and return
 * with the number of not fulfilled preconditions.
 * The values from 'ProgrammingPreConditionType' can be used as valid
 * parameters.
 * Prototype: uint8 UserCallback_CheckProgrammingPreConditions(uint8* dataPtr)
 * Parameter: dataPtr: Buffer for the not fulfilled preconditions
 * Return:    Number of not fulfilled preconditions.
 */
#define UserCallback_CheckProgrammingPreConditions(dataPtr)       (uint8)0

/**** User call back UserCallback_WatchdogTriggerStop defined empty           */
/*
 * The callback should set a cycle counter for the disabling of the triggering
 * of the watchdog.
 * Prototype: void UserCallback_WatchdogTriggerStop(uint8 counter)
 * Parameter: uint8: cycle counter
*/
#define UserCallback_WatchdogTriggerStop(remainingTimeInS)

#endif /* APPL_SRC_CFG_H                                                      */

/*** End of file **************************************************************/

