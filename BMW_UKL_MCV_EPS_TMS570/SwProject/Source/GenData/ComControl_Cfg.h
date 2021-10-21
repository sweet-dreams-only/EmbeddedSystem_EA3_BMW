/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : ComControl_Cfg.h
**
**  Copyright (C) BMW Group 2011
**
**  TARGET            : All
**
**  PROJECT           : BMW Autosar Core
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : ComControl (Communication Control) as part modul of
**                      VSM Client user configuration
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: Vsm
**
**  GENERATION DATE   : 03.04.2012 10:04:23 !!!IGNORE-LINE!!!
**
**  PLATFORM DEPENDANT [yes/no]: no
**
**  TO BE CHANGED BY USER [yes/no]: no
**
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** mani         Markus Nirschl             EB Automotive                      **
** chfr         Christian Franke           EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.2.2: 23.08.2011, olho: CR71006: Replaced Xp.ModuleConf() by
 *                                    Xp.ModuleConfAtDefRefTo()
 * V1.2.1: 17.02.2011, thmi: CR70908: Update to MISRA 2004
 *                                    Revise or comment deviations
 * V1.2.0: 08.02.2011, olgo: CR70864: VSM shall support ECUs without NM
 *         07.02.2011, olgo: CR70862: preprocessor error instead of generator
 *                                    error
 * V1.1.0: 22.03.2010, chfr: CR70597: Replace "VSM_VERSION" with
 *                                    "BMWAutosarCoreVersion"
 * V1.0.0: 26.02.2010, mani: CR70415: Module extension to 3.0
 */

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/


#ifndef COMCONTROL_CFG_H
#define COMCONTROL_CFG_H

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef VSM_H_FILE
   #define VSM_H_FILE
#endif
#include <Vsm_Client.h>                /* module global include file          */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * File version information
 */
#define COMCONTROL_CFG_MAJOR_VERSION   4u
#define COMCONTROL_CFG_MINOR_VERSION   1u
#define COMCONTROL_CFG_PATCH_VERSION   5u


/* NM are not configured */
#define COMCONTROL_NM_HANDLING STD_OFF

#endif /* COMCONTROL_CFG_H */


/*** End of file **************************************************************/
