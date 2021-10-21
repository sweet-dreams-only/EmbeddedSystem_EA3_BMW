
/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : VsmFim_Cfg.h
**
**  Copyright (C) BMW Group 2011
**
**  TARGET            : All
**
**  PROJECT           : BMW Autosar Core
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : FIM (Function Inhibition Manager) as part modul of
**                      VSM Client user configuration
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: Vsm
**
**  GENERATION DATE   : 03.04.2012 10:04:20 !!!IGNORE-LINE!!!
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
** olgo         Oliver Gorisch             EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.1.2: 23.08.2011, olho: CR71006:    Replaced Xp.ModuleConf() by
 *                                       Xp.ModuleConfAtDefRefTo()
 * V2.1.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V2.1.0: 02.02.2010, olgo: CR70908:    some MISRA warnings are missing
 *                                       in the report
 * V2.0.4: 07.10.2010, olho: CR70843:    VSM-Generator should not check signal
 *                                       references of deactivated features
 * V2.0.3: 10.03.2010, olho: CR70415:    Module extension to 3.0
 * V2.0.2: 12.02.2009, miwe  BSCVSM-106: Implemented review results
 * V2.0.1: 21.01.2009, olgo: BSCVSM-100: CR70070: Vsm_IsInhibitedService does
 *                                       not return the correct inhibition
 *                                       status
 * V2.0.0: 11.11.2008, olgo: BSCVSM-90 : CR70027: VSM: Rename FIM functions to
 *                                       avoid name clash with AUTOSAR FIM
 * V1.0.0: 04.06.2008, olgo: BSCVSM-55 : remove curly braces in Vsm config
 *         28.04.2008, olgo: BSCVSM-49 : Number of Applications in FIM wrong
 *         03.04.2008, olgo: BSCVSM-42 : Implementation of the review results
 *         31.01.2008, olgo: BSCVSM-35 : VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-26 : Move sub module enable switches to
 *                                       Vsm_Client_Cfg.h
 *         07.01.2008, olgo: BSCVSM-18 : rename of page names in VSM plugin
 *         27.11.2007, olgo: taken from SC6 V3.0.1 and ported to SC7
 */


#ifndef VSM_FIM_CFG_H
#define VSM_FIM_CFG_H

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 19.7 (advisory)
  *   A function should be used in preference to a function-like macro.
  *
  *   Reason:
  *   As the function is called very often and consists only of a one line
  *   the macro based implmentation is more run time efficient.
  *
  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef VSM_H_FILE
   #define VSM_H_FILE
#endif
#include <Vsm_Client.h>                      /* module global include file    */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * File version information
 */
#define FIM_CFG_MAJOR_VERSION   4u
#define FIM_CFG_MINOR_VERSION   1u
#define FIM_CFG_PATCH_VERSION   5u

#endif /* VSM_FIM_CFG_H */

/*** End of file **************************************************************/
