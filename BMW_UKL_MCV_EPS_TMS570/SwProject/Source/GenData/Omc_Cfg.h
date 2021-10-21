/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : Omc_Cfg.h
**
**  Copyright (C) BMW Group 2009
**
**  TARGET            : All
**
**  PROJECT           : BMW Autosar Core 2.1
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : OMC (Operational Mode Control) as part modul of
**                      VSM Client user configuration
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: Vsm
**
**  GENERATION DATE   : 03.04.2012 10:04:17 !!!IGNORE-LINE!!!
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
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V1.1.0: 06.07.2009, olgo: BSCVSM-119: CR70257 - VSM (OMC): Wrong useage of
 *                                       DEM function
 *                     olgo: CR70801:    Initial error blocking not released
 * V1.0.0: 03.06.2008, olgo: BSCVSM-54:  remove ComSignal_FZZSTD_ST_ILK_ERRM_FZM
 *                                       because its not used anymore
 *                           BSCVSM-55:  remove curly braces in Vsm config
 *         03.04.2008, olgo: BSCVSM-42:  Implementation of the review results
 *         31.01.2008, olgo: BSCVSM-35:  VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-26:  Move sub module enable switches to
 *                                       Vsm_Client_Cfg.h
 *         07.01.2008, olgo: BSCVSM-18:  rename of page names in VSM plugin
 *         27.11.2007, olgo: taken from SC6 V3.0.1 and ported to SC7
 */

#ifndef OMC_CFG_H
#define OMC_CFG_H

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
#define OMC_CFG_MAJOR_VERSION   4u
#define OMC_CFG_MINOR_VERSION   1u
#define OMC_CFG_PATCH_VERSION   5u


/*******************************************************************************
**                      Mapping of external API                               **
*******************************************************************************/

#if defined (VSM_ENABLE_FUNC_INHIB_MAN)
   /* Deviation MISRA-1 */
   #define OMC_VSM_NOTIFYMODECHANGEEVENT(mode) Vsm_NotifyModeChangeEvent(mode)
#else
   #define OMC_VSM_NOTIFYMODECHANGEEVENT(mode)
#endif /* defined (VSM_ENABLE_FUNC_INHIB_MAN) */

#if defined (VSM_ENABLE_STATE_MONITOR)
   #define OMC_UNBLOCK_ERROR_MEM()        do { Vsm_UnBlockDem( VSM_OMC_DEM_HANDLING ); } while(0)
   #define OMC_BLOCK_ERROR_MEM()          do { Vsm_BlockDem( VSM_OMC_DEM_HANDLING ); } while(0)
#else
   #define OMC_UNBLOCK_ERROR_MEM()        (void)Dem_EnableEventStatusUpdate(DEM_DTC_GROUP_NETWORK_COM_DTCS, DEM_DTC_KIND_ALL_DTCS);
   #define OMC_BLOCK_ERROR_MEM()          (void)Dem_DisableEventStatusUpdate(DEM_DTC_GROUP_NETWORK_COM_DTCS, DEM_DTC_KIND_ALL_DTCS);
#endif /* defined (VSM_ENABLE_STATE_MONITOR) */

#endif /* OMC_CFG_H */

/*** End of file **************************************************************/
