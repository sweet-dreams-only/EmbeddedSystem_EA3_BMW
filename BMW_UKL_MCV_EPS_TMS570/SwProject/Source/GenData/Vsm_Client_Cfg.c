
/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : Vsm_Client_Cfg.c
**
**  Copyright (C) BMW Group 2011
**
**  TARGET            : All
**
**  PROJECT           : BMW Autosar Core 2.1
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : VSM Client module user configuration
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: Vsm
**
**  GENERATION DATE   : 03.04.2012 10:04:16 !!!IGNORE-LINE!!!
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
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.3.2: 07.11.2011, thmi: CR71161:    Add Mapping ComMChannel to NmChannel
 *                                       to fix wrong usage of NmChannelId
 *                                       in Nm_SetUserData call.
 * V1.3.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V1.3.2: 23.08.2011, olho: CR71006:    Replaced Xp.ModuleConf() by
 *                                       Xp.ModuleConfAtDefRefTo()
 * V1.3.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V1.3.0: 16.09.2010, olgo: CR70830:    Remove unused parameter in function
 *                                       vsm_cbk
 * V1.2.0: 23.04.2010, olgo: BSCVSM-156: BAC3.0 LIN are activated for NM
 *                                       see also Bader-RT #23790
 * V2.2.0: 22.03.2010, chfr: CR70597:    Replace "VSM_VERSION" with
 *                                       "BMWAutosarCoreVersion"
 * V2.1.0: 26.02.2010, mani: CR70415:    Module extension to 3.0
 * V2.0.0: 05.10.2009, hauf: CR70371:    removed SC6 variants and added RTE
 *                                       switch
 *                           CR70379:    moved assert checks to verify.tt file
 * V1.0.1: 05.02.2008, olgo: BSCVSM-98:  Client ports with several operations
 *                                       provided by different application
 *                                       modules
 * V1.0.0: 03.04.2008, olgo: BSCVSM-42:  Implementation of the review results
 *         31.01.2008, olgo: BSCVSM-35:  VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         16.01.2008, olgo: BSCVSM-26:  Move sub module enable switches to
 *                                       Vsm_Client_Cfg.h
 *                           BSCVSM-12:  RTE integration
 *         20.12.2007, olgo: BSCVSM-16:  callback functions are not generated
 *         27.11.2007, olgo: taken from  SC6 V3.0.0 and ported to SC7
 */


/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/* Misra-C:2004 Deviation List:
  *
  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#define VSM_C_FILE
#include <Vsm_Client.h>                      /* module global include file    */

#include <Std_Types.h>           /* this will also include the platform types */

#if ( ( VSM_CLIENT_CFG_MAJOR_VERSION != ( 4u ) ) || \
      ( VSM_CLIENT_CFG_MINOR_VERSION != ( 1u ) ) )
  #error "Vsm_Client_Cfg.c: Wrong version of Vsm_Client_Cfg.h found!!"
#endif


/*******************************************************************************
**                      Global Constants                                      **
*******************************************************************************/

#define VSM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*
 * ComM configuration for each configured Vsm_ComMUser:
 *
 * ComMUserId, ComMChannelId, ComMBusType, ComMRxIPduGroup, ComMTxIPduGroup
 */
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 04/28/2017
 * Description: VSM Rx and Tx group numbers are updated to 1 and 2 respectively to match COM Configuration (EA3#13952)
 */
CONST(Vsm_ComMUserArrayType, VSM_CONST) VsmComMUserArray[VSM_NUM_COMMUSERS] =
{
   { 0, 0, VSM_BUS_FR, 1, 2}, /* VSM_ComMUser -> ComMUser_A_FlexRay */
};
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

/*
 * Matrix for ComMChannelId-ComMUserId mapping
 *
 *                 ComMUser_0  ComMUser_1  ...
 * ComMChannel_0      (x)          (x)
 * ComMChannel_1      (x)          (x)
 * ...
 *
 * (x):
 * TRUE:  ComMChannel_x is used by ComMUser_y
 * FALSE: ComMChannel_x is not used by ComMUser_y
 */
CONST(uint8, VSM_CONST) Vsm_ComMChannelUserMap[VSM_COMM_NUM_CHANNELS][VSM_COMM_NUM_USERS] =
{
   { TRUE}, /* Channel_0 */
};

/*
 * Bus type of a channel
 */
CONST(Vsm_ComMBusTypeOfChannelType, VSM_CONST) Vsm_ComMBusTypeOfChannel[VSM_COMM_NUM_CHANNELS] =
{
   { VSM_BUS_FR, VSM_NM_NONE },/* Channel_0 */
};

/*
 * Check if to a ComM channel is mapped a NM channel
 */
CONST(boolean, VSM_CONST) Vsm_NmChannelComMChannelCheck[VSM_COMM_NUM_CHANNELS] =
{
    FALSE,
  };

/*
 * NM channel mapped to a ComM channel
 */
CONST(uint8, VSM_CONST) Vsm_NmChannelComMChannelMap[VSM_COMM_NUM_CHANNELS] =
{
    0U,
  };

#define VSM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Vsm_Cbk                                                    **
**                                                                            **
** DESCRIPTION   : global Callback function                                   **
**                                                                            **
** PRECONDITIONS : no                                                         **
**                                                                            **
** PARAMETER     : type: type of the callback                                 **
**                 param: parameter of callback if neccessary                 **
**                                                                            **
** RETURN        : no                                                         **
**                                                                            **
** REMARKS       : no                                                         **
**                                                                            **
*******************************************************************************/
FUNC(void, VSM_PUBLIC_CODE)
     Vsm_Cbk(Vsm_CallbackType type, uint32 param)
{
  switch(type)
  {
    case Vsm_NotifyModeChange:
      Vsm_NotifyModeChange_SYSTEM_TEST((uint8)param);
      Vsm_NotifyModeChange_CLIMATE_CONTROL((uint8)param);
      break;

    case Vsm_NotifyModeExtensionChange:
      Vsm_NotifyModeExtensionChange_SYSTEM_TEST((uint8)param);
      Vsm_NotifyModeExtensionChange_CLIMATE_CONTROL((uint8)param);
      break;

    case Vsm_NotifyStateChange:
      Vsm_NotifyStateChange_SYSTEM_TEST((uint8)param);
      Vsm_NotifyStateChange_CLIMATE_CONTROL((uint8)param);
      break;

    case Vsm_NotifyEnergyStateChange:
      Vsm_NotifyEnergyStateChange_SYSTEM_TEST((uint8)param);
      Vsm_NotifyEnergyStateChange_CLIMATE_CONTROL((uint8)param);
      break;

    case Vsm_NotifyCommunicationErrorLockChange:
      Vsm_NotifyCommunicationErrorLockChange_SYSTEM_TEST((uint8)param);
      Vsm_NotifyCommunicationErrorLockChange_CLIMATE_CONTROL((uint8)param);
      break;

    default:
      break;

  } /* switch(type) */
} /* end of Vsm_Cbk() */


#define VSM_STOP_SEC_CODE
#include <MemMap.h>

/*** End of file **************************************************************/
