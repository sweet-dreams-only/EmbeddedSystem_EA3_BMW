
/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : Wur_Cfg.h
**
**  Copyright (C) BMW Group 2011
**
**  TARGET            : All
**
**  PROJECT           : BMW Autosar Core
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : WUR (Wakeup Registration) as part modul of VSM Client
**                      user configuration
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: Vsm
**
**  GENERATION DATE   : 03.04.2012 10:04:21 !!!IGNORE-LINE!!!
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
** hauf         Andreas Hauf               EB Automotive                      **
** mani         Markus Nirschl             EB Automotive                      **
** chfr         Christian Franke           EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.3.3: 23.08.2011, olho: CR71006: Replaced Xp.ModuleConf() by
 *                                    Xp.ModuleConfAtDefRefTo()
 * V2.3.2: 17.02.2011, thmi: CR70908: Update to MISRA 2004
 *                                    Revise or comment deviations
 * V2.3.1: 07.10.2010, olho: CR70843: VSM-Generator should not check signal
 *                                    references of deactivated features
 * V2.3.0: 26.06.2010, bemo: CR70681: move config parameters VSM_ECU_ID_HEADER
 *                                    and VSM_ECU_ID to Vsm_Client_Cfg.h.tt
 * V2.2.0: 22.03.2010, chfr: CR70597: Replace "VSM_VERSION" with "BMWAutosarCoreVersion"
 * V2.1.0: 26.02.2010, mani: CR70415: Module extension to 3.0
 * V2.0.0: 05.10.2009, hauf: CR70371: removed SC6 variants and added RTE switch
 *                           CR70352: Made EcuId configurable during runtime
 * V1.0.0: 21.07.2008, olgo: BSCVSM-71: Moving VSM_ECU_ID from generell Tab to
 *                                      WUR Tab (RT: 12611)
 *         04.06.2008, olgo: BSCVSM-56: make VSM_MAX_NUM_WAKEUPS configureable
 *         03.04.2008, olgo: BSCVSM-42: Implementation of the review results
 *         31.01.2008, olgo: BSCVSM-35: VSM with activated RTE collides with
 *                           other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-26: Move sub module enable switches to
 *                           Vsm_Client_Cfg.h
 *         07.01.2008, olgo: BSCVSM-18: rename of page names in VSM plugin
 *         27.11.2007, olgo: taken from SC6 V4.0.0 and ported to SC7
 */

#ifndef WUR_CFG_H
#define WUR_CFG_H

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
#include <Vsm_Client.h>                /* module global include file          */


#ifdef VSM_ENABLE_FUNC_NM
   #define WUR_VSM_GETOVERALLBUSSLEEPSTATE() 	Vsm_GetOverallBusSleepState()
   #define WUR_VSM_GETNUMSENDRCVAPPL()       	Vsm_GetNumSendRcvAppl()
#else
   #define WUR_VSM_GETOVERALLBUSSLEEPSTATE() 	(uint8)0xFFu
   #define WUR_VSM_GETNUMSENDRCVAPPL()       	(uint8)0x00u
#endif /* defined (VSM_ENABLE_FUNC_NM) */

#endif /* WUR_CFG_H */

/*** End of file **************************************************************/
