
/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : Stm_Cfg.h
**
**  Copyright (C) BMW Group 2011
**
**  TARGET            : All
**
**  PROJECT           : BMW Autosar Core
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : STM (Status Monitor) as part modul of VSM Client
**                      user configuration
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: Vsm
**
**  GENERATION DATE   : 21.08.2012 18:02:44 !!!IGNORE-LINE!!!
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
** olho         Oliver Hoeft               EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.3: 23.08.2011, olho: CR71006:   Replaced Xp.ModuleConf() by
 *                                      Xp.ModuleConfAtDefRefTo()
 * V1.1.2: 17.02.2011, thmi: CR70908:   Update to MISRA 2004
 *                                      Revise or comment deviations
 * V1.1.1: 07.10.2010, olho: CR70843:   VSM-Generator should not check signal
 *                                      references of deactivated features
 * V1.0.0: 05.06.2008, olgo: BSCVSM-56: move VSM_xxx from Stm_Cfg.h to this file
 *         04.06.2008, olgo: BSCVSM-55: remove curly braces in Vsm config
 *         03.04.2008, olgo: BSCVSM-42: Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-38: Fix Com signal usage in STM
 *         31.01.2008, olgo: BSCVSM-35: VSM with activated RTE collides with
 *                           other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-26: Move sub module enable switches to
 *                           Vsm_Client_Cfg.h
 *         07.01.2008, olgo: BSCVSM-18: Own subpage for mudule interactions
 *                           in VSM plugin
 *         27.11.2007, olgo: taken from SC6 V3.1.1 and ported to SC7
 */

#ifndef STM_CFG_H
#define STM_CFG_H

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

#include <Dem.h>    /* DEM specific include for block/unblock error memory*/

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/
/*
 * File version information
 */
#define STM_CFG_MAJOR_VERSION   4u
#define STM_CFG_MINOR_VERSION   1u
#define STM_CFG_PATCH_VERSION   5u

/**** timeout definitions ****/
/* delay after startup which operation status is set to invalid if no message
   (Klemmen) to refresh the operation state is received */
#define VSM_TMO_OPERATION_STATE_REFRESH     500   /* in milliseconds (0..2550)*/

/* delay after startup which vehicle states are set to invalid if no message
   (Fahrzeugzustand) to refresh the vehicle states is received */
#define VSM_TMO_VEHICLE_STATE_REFRESH       21000 /* in milliseconds */

/* delay after startup where DEM is blocked */
#define VSM_TMO_CEL_TIME_STARTUP            0 /* in milliseconds (0..10000)*/

//#define VSM_SG_KLEMMEN_ST_VEH_CON           Com_ST_VEH_CON__KLEMMEN     /* signal ST_VEH_CON of KLEMMEN message */
#define VSM_SG_FZZSTD_ST_ENERG_FZM          Com_ST_ENERG_FZM__FZZSTD    /* signal ST_ENERG_FZM of FZZSTD message */
#define VSM_SG_FZZSTD_ST_ILK_ERRM_FZM       Com_ST_ILK_ERRM_FZM__FZZSTD /* signal ST_ILK_ERRM_FZM of FZZSTD message */


/*******************************************************************************
**                      Mapping of external API                               **
*******************************************************************************/
/* Event-ID for the error memory entry if the VehicleStateMessage is missing  */
#define VSM_EVENTID_VEHICLESTATE VSM_EVENT_VEHICLESTATE  /*NXTR - The DTC for event ID VSM_EVENT_VEHICLESTATE was removed - updated configurator with VSM_EVENT_OPMODE since configurator required an EVENT ID in order to generate */

#if defined (VSM_ENABLE_FUNC_INHIB_MAN)
   /* Deviation MISRA-1 */
   #define STM_VSM_NOTIFYSTATECHANGEEVENT(state)               Vsm_NotifyStateChangeEvent(state)
   /* Deviation MISRA-1 */
   #define STM_VSM_NOTIFYENERGYSTATECHANGEEVENT(energyState)   Vsm_NotifyEnergyStateChangeEvent(energyState)
#else
   #define STM_VSM_NOTIFYSTATECHANGEEVENT(state)
   #define STM_VSM_NOTIFYENERGYSTATECHANGEEVENT(energyState)
#endif /* defined (VSM_ENABLE_FUNC_INHIB_MAN) */

#if defined (VSM_ENABLE_MODE_CONTROL)
   /* Deviation MISRA-1 */
   #define STM_VSM_GETMODE(a)            Vsm_GetMode(a)
#else
   #define STM_VSM_GETMODE(a)            ( *( a ) = (uint8)VSM_MM_MODE_NORMAL )
#endif /* defined (VSM_ENABLE_MODE_CONTROL) */

#endif /* STM_CFG_H */

/*** End of file **************************************************************/
