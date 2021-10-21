
/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : Vsm_Client_Cfg.h
**
**  Copyright (C) BMW Group 2011
**
**  TARGET            : All
**
**  PROJECT           : BMW Autosar Core
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : VSM Client module user configuration
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: Vsm
**
**  GENERATION DATE   : 03.04.2012 10:04:19 !!!IGNORE-LINE!!!
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
** hauf         Andreas Hauf               EB Automotive                      **
** mani         Markus Nirschl             EB Automotive                      **
** chfr         Christian Franke           EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.7.2: 23.08.2011, olho: CR71006:    Replaced Xp.ModuleConf() by
 *                                       Xp.ModuleConfAtDefRefTo()
 * V2.7.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V2.7.0: 07.02.2011, olgo: CR70862:    preprocessor error instead of generator
 *                                       error, correct history
 * V2.6.0: 20.10.2010, olgo: CR70831:    VSM FCT id parameter is only for
 *                                       ASR 3.0 with FNM
 *         13.10.2010, olgo: CR70555:    Multiple Call to Nvm_WriteBlock()
 *                     olgo: CR70801:    Initial error blocking not released
 * V2.5.1: 16.09.2010, olgo: CR70823:    Vsm_Client_Cfg.h ignores configured CAN
 *                                       header files
 * V2.5.0: 24.06.2010, olgo: BSCVSM-178: direct include of CanNm.h in Fnm.h also
 *                                       if only FlexRay is active ( #RT24491 )
 * V2.4.0: 24.06.2010, bemo: CR70681 :   move config parameters VSM_ECU_ID_HEADER
 *                                       and VSM_ECU_ID to Vsm_Client_Cfg.h.tt
 * V2.3.0: 23.04.2010, olgo: BSCVSM-157: CanNm_RequestBusSynchronization call
 *                                       don't working on Flexray only devices
 * V2.2.0: 22.03.2010, chfr: CR70597:    Replace "VSM_VERSION" with
 *                                       "BMWAutosarCoreVersion"
 * V2.1.0: 26.02.2010, mani: CR70415:    Module extension to 3.0
 * V2.0.0: 05.10.2009, hauf: CR70371:    removed SC6 variants and added RTE switch
 *                                       removed VSM_CLIENT_VERSION_INFORMATION
 * V1.0.1: 12.02.2009, miwe  BSCVSM-106: Implemented review results
 * V1.0.0: 21.07.2008, olgo: BSCVSM-71:  Moving VSM_ECU_ID from generell Tab to
 *                                       WUR Tab (RT: 12611)
 *         09.07.2008, olgo: BSCVSM-41:  Updates of Nvm-Handling
 *         05.06.2008, olgo: BSCVSM-56:  move VSM_xxx from Stm_Cfg.h to this file
 *         03.04.2008, olgo: BSCVSM-42:  Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-36:  Using of function Nvm_SetBlockProtection
 *                                       instead of Nvm_SetRamBlockStatus
 *         31.01.2008, olgo: BSCVSM-35:  VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *                           BSCVSM-27:  Interrupt blocking must be done using
 *                                       the schedule manager
 *         16.01.2008, olgo: BSCVSM-26:  Move sub module enable switches to
 *                                       Vsm_Client_Cfg.h
 *                           BSCVSM-12:  RTE integration
 *         07.01.2008, olgo: BSCVSM-18:  Own subpage for mudule interactions
 *                                       and rename of page names in VSM plugin
 *                           BSCVSM-19:  Mapping of OS functions
 *                           BSCVSM-20:  Mapping of NVM function
 *                                       Nvm_SetBlockProtection
 *         19.12.2007, olgo: BSCVSM-12:  RTE integration
 *         27.11.2007, olgo: taken from SC6 V4.0.0 and ported to SC7
 */

#ifndef VSM_CLIENT_CFG_H
#define VSM_CLIENT_CFG_H

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

#include <Std_Types.h>                               /* include AUTOSAR types */


   
       /* WUR_ComMUser */


            /* ComMChannel */

   



#include <Fr.h> /*  */


#include <NvM.h>                   /* include file of NVM memory */


#include <applmain.h>                   /* API to wait for Nvm           */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* #define VSM_ENABLE_RTE */

#define VSM_VERSION_BAC3x

/* #define USE_VSM_WITH_CAN */

#define USE_VSM_WITH_FLEXRAY                                     /* #channel=1 */
#define NUM_FR_BUSSES_WITH_NM     0

/* #define USE_VSM_WITH_LIN */

/* compiler switch to enable VSM State Monitor */
#define VSM_ENABLE_STATE_MONITOR

/* compiler switch to enable VSM operational mode control */
#define VSM_ENABLE_MODE_CONTROL

/* compiler switch to enable VSM Wakeup Registration */
/* #define VSM_ENABLE_WAKEUP_REGISTRATION */

/* compiler switch to enable VSM - FIM (Function Inhibition Manager) */
/* #define VSM_ENABLE_FUNC_INHIB_MAN */

/* compiler switch to enable VSM - FNM (Functional Network Manager) */
/* #define VSM_ENABLE_FUNC_NM */

/* compiler switch to enable VSM - ComControl (Communication Control) */
#define VSM_ENABLE_COMCONTROL

/* VSM Client configuration File Version Tag
   For internal usage only -> do not change !!! */
#define VSM_CLIENT_CFG_MAJOR_VERSION   4u
#define VSM_CLIENT_CFG_MINOR_VERSION   1u
#define VSM_CLIENT_CFG_PATCH_VERSION   5u

/* Non volatile block used by VSM                                             */
#define VSM_OMC_NV_DATA_BLOCK          NVM_BLOCK_VSMOMC_DATA

/* Deviation MISRA-1 */
#define NVM_SETRAMBLOCKSTATUS( block )  NvM_SetRamBlockStatus( block, TRUE );
/* Deviation MISRA-1 */
#define NVM_READBLOCK( blockNum, blockPtr )  NvM_ReadBlock( blockNum, blockPtr );
/* Deviation MISRA-1 */
#define NVM_WRITEBLOCK( blockNum, blockPtr )   NvM_WriteBlock( blockNum, blockPtr );
/* Deviation MISRA-1 */
#define NVM_GETERRORSTATUS( blockNum, resPtr )  NvM_GetErrorStatus( blockNum, resPtr );
/* Deviation MISRA-1 */
#define VSM_WAIT_UNTIL_BLOCK_IS_READY( block ) Appl_WaitNvMReady(block, TRUE)

/* VSM application function IDs */
#define CLIMATE_CONTROL   0
#define FLASH_CONTROL   1
#define SYSTEM_TEST   2
/* maximum number of application modules is currently 255 */



/* Number of configured Vsm ComMUsers */
#define VSM_NUM_COMMUSERS  1

/* total number of ComM channels */
#define VSM_COMM_NUM_CHANNELS 1u

/* total number of ComM users */
#define VSM_COMM_NUM_USERS 1u



/**** timeout definitions ****/
/* call frequency of Vsm_MainFunction() in milliseconds */
/* the resolution of the VSM timers depend on the call frequency */
#define VSM_TIMER_CYCLIC_FREQUENCY            10    /* milliseconds */

#define VSM_BUS_CAN       0
#define VSM_BUS_FR        1
#define VSM_BUS_LIN       2
#define VSM_BUS_MOST      3
#define VSM_BUS_INTERNAL  4

/*  id of the ECU ( e.g. 0x7Eu ) */
#define VSM_ECU_ID                    0x7eu

/*******************************************************************************
**                      Mapping of external API                               **
*******************************************************************************/

/**** interface to DEM ****/
/* allow DEM communication error entries */
#define VSM_UNBLOCK_ERROR_MEM() (void)Dem_EnableEventStatusUpdate(DEM_DTC_GROUP_NETWORK_COM_DTCS, DEM_DTC_KIND_ALL_DTCS)

/* block DEM communication error entries */
#define VSM_BLOCK_ERROR_MEM()   (void)Dem_DisableEventStatusUpdate(DEM_DTC_GROUP_NETWORK_COM_DTCS, DEM_DTC_KIND_ALL_DTCS)

/*
 * Mapping of function to set dem event
 * The function should set the status of the given DEM event to 'failed'.
 */
/* Deviation MISRA-1 */
#define VSM_SET_DEM_EVENT( p )   Dem_ReportErrorStatus(p, DEM_EVENT_STATUS_FAILED)

/*
 * Mapping of function to clear dem event
 * The function should set the status of the given DEM event to 'passed'.
 */
/* Deviation MISRA-1 */
#define VSM_CLEAR_DEM_EVENT( p )   Dem_ReportErrorStatus(p, DEM_EVENT_STATUS_PASSED)


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyModeChange_SYSTEM_TEST(uint8 param);
   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyModeChange_CLIMATE_CONTROL(uint8 param);

   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyModeExtensionChange_SYSTEM_TEST(uint8 param);
   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyModeExtensionChange_CLIMATE_CONTROL(uint8 param);


   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyStateChange_SYSTEM_TEST(uint8 param);
   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyStateChange_CLIMATE_CONTROL(uint8 param);

   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyEnergyStateChange_SYSTEM_TEST(uint8 param);
   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyEnergyStateChange_CLIMATE_CONTROL(uint8 param);

   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyCommunicationErrorLockChange_SYSTEM_TEST(uint8 param);
   extern FUNC(void, VSM_PUBLIC_CODE) Vsm_NotifyCommunicationErrorLockChange_CLIMATE_CONTROL(uint8 param);


#endif /* VSM_CLIENT_CFG_H */

/*** End of file **************************************************************/
