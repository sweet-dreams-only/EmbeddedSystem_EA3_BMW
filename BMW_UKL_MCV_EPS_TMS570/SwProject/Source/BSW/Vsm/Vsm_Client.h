/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Vsm_Client.h                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : "Vehicle State Management" - client header                    **
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
** olgo         Oliver Gorisch             EB Automotive                      **
** dobr         Dominik Brader             EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** mani         Markus Nirschl             EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.3.3: 07.11.2011, thmi: CR71161:    Add Mapping ComMChannel to NmChannel
 *                                       to fix wrong usage of NmChannelId
 *                                       in Nm_SetUserData call.
 * V1.3.2: 07.11.2011, thmi: CR71160:    Fix wrong array index in Fnm_Main
 *         07.11.2011, thmi: CR71161:    Fix wrong usage of NmChannelId
 *                                       in Nm_SetUserData call.
 * V3.4.1: 17.02.2011, thmi: CR70908:    Update to MISRA 2004
 *                                       Revise or comment deviations
 * V3.4.0: 13.10.2010, olgo: CR70555:    Multiple Call to Nvm_WriteBlock()
 *                     olgo: CR70801:    Initial error blocking not released
 * V3.3.0: 16.09.2010, olgo: CR70830:    Remove unused parameter in function
 *                                       vsm_cbk
 * V3.2.1: 06.07.2010, bemo: CR70712:    STOP_SEC_CONST code missing
 * V3.2.0: 23.04.2010, olgo: BSCVSM-156: BAC3.0 LIN are activated for NM
 *                                       see also Bader-RT #23790
 * V3.1.0: 26.02.2010, mani: CR70415:    Module extension to 3.0
 * V3.0.0: 05.10.2009, hauf: CR70371:    Removed SC6 variants and added RTE
 *                                       switch
 *         09.10.2009, hauf: CR70291:    Corrected storage class of
 *                                       Vsm_NvData_Default to VSM_CONST and
 *                                       corrected check of VSM_TEST_ENABLE
 *                                       switch
 * V2.0.1: 10.08.2009, dobr: BSCVSM-123: replaced 'ON/OFF' with 'STD_ON/STD_OFF'
 * V2.0.0: 11.11.2008, olgo: BSCVSM-90:  CR70027: VSM: Rename FIM functions to
 *                                       avoid name clash with AUTOSAR FIM
 * V1.0.0: 15.07.2008, olgo: BSCVSM-74:  Code Formatting
 *         03.04.2008, olgo: BSCVSM-42:  Implementation of the review results
 *         08.02.2008, olgo: BSCVSM-39:  Vsm may not include MemMap_Vsm.h but
 *                                       only MemMap.h
 *         31.01.2008, olgo: BSCVSM-35:  VSM with activated RTE collides with
 *                                       other Modules with activated RTE
 *         29.01.2008, olgo: BSCVSM-24:  Timeouts im STM
 *         16.01.2008, olgo: BSCVSM-12:  RTE integration
 *                           BSCVSM-25:  Includes und API-Mapping
 *         27.11.2007, olgo: taken from  SC6 V3.1.0 and ported to SC7
 */

#ifndef VSM_CLIENT_H
#define VSM_CLIENT_H

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/* Misra-C:2004 Deviation List:
  *
  */

/*******************************************************************************
**                      Test Configuration Checks                             **
*******************************************************************************/

#include <Std_Types.h>                               /* include AUTOSAR types */

#if !( defined STANDARD_CORE_TEST )
   #define STANDARD_CORE_TEST                                            STD_OFF
#endif /* !( defined STANDARD_CORE_TEST )                                     */

#if ( defined VSM_TEST_ENABLE )
   #if ( (STANDARD_CORE_TEST == STD_OFF) && (VSM_TEST_ENABLE == STD_ON) )
      #error "Vsm_Client.h: STANDARD_CORE_TEST == STD_OFF, but VSM_TEST_ENABLE == STD_ON"
   #endif
#else
   #define VSM_TEST_ENABLE                                               STD_OFF
#endif /* ( VSM_TEST_ENABLE == STD_ON )                                       */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Dem.h>                           /* DEM specific include for block/ */
                                           /* unblock error memory            */
#ifndef BOOTLOADER
   #include <SchM_Vsm_Client.h>            /* Schedule manager public API     */
   #include <Vsm_Client_Cfg.h>             /* VSM user configuration file     */
#endif

#ifdef VSM_ENABLE_RTE
   #if ( defined ( VSM_H_FILE ) || defined ( VSM_C_FILE ) )
      #include <Rte_VSM_CLIENT.h>
   #else
      #include <Rte_Vsm_Client_Public.h>
   #endif
#endif

#ifndef BOOTLOADER
   #include <VsmFim_Cfg.h>              /* FIM-Config specific include        */
   #include <Omc_Cfg.h>                 /* OMC-Config specific include        */
   #include <Fnm_Cfg.h>                 /* FNM-Config specific include        */
   #include <ComControl_Cfg.h>          /* ComControl-Config specific include */
   #include <Wur_Cfg.h>                 /* WUR-Config specific include        */
   #include <Stm_Cfg.h>                 /* STM-Config specific include        */
#endif

#include <VsmFim.h>                     /* FIM specific include               */
#include <Omc.h>                        /* OMC specific include               */
#include <Fnm.h>                        /* FNM specific include               */
#include <ComControl.h>                 /* ComControl specific include        */
#include <Wur.h>                        /* WUR specific include               */
#include <Stm.h>                        /* STM specific include               */


/*******************************************************************************
**                      Version Control                                       **
*******************************************************************************/

#define VSM_CLIENT_MAJOR_VERSION   4u
#define VSM_CLIENT_MINOR_VERSION   1u
#define VSM_CLIENT_PATCH_VERSION   5u


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* return values of application callbacks                                     */
#define VSM_OK                     0x00u
#define VSM_NOT_OK                 0x01u
#define VSM_INVALID                0xFFu


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* type of all possible callback functions */
typedef enum {
  Vsm_NotifyCommunicationChange,
  Vsm_NotifyNetworkTimeOut,
  Vsm_NotifyModeChange,
  Vsm_NotifyModeExtensionChange,
  Vsm_NotifyStateChange,
  Vsm_NotifyEnergyStateChange,
  Vsm_NotifyCommunicationErrorLockChange
} Vsm_CallbackType;

/* type of VSM Client NVRAM data for OMC module                               */
typedef struct
{
   uint8 Vsm_opMode;
   uint8 Vsm_opModeExtension;
} Vsm_OmcNvDataType;

/* type of VSM Client NVRAM data for WUR module                               */
typedef struct
{
   uint8 Vsm_WurOccCounter;
   uint8 Vsm_WurWakeupReason;
} Vsm_WurNvDataType;

/* type of VSM states                                                         */
typedef enum
{
   VSM_UNINIT,
   VSM_INIT,
   VSM_RUNNIG
} Vsm_StateType;

typedef enum
{
   VSM_OMC_DEM_HANDLING,
   VSM_STM_DEM_HANDLING
} Vsm_DemHandlungFunctionType;

#if defined (VSM_VERSION_BAC3x)
typedef struct
{
   ComM_UserHandleType ComMUser;
   NetworkHandleType Channel;
   uint8 BusType;
   Com_PduGroupIdType RxIPdus;
   Com_PduGroupIdType TxIPdus;
}Vsm_ComMUserArrayType;

/* type for bustype und nm type of a specific chanel                          */
typedef struct
{
   uint8 bustype;
   uint8 nmtype;
}Vsm_ComMBusTypeOfChannelType;

#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define VSM_START_SEC_VAR_NVDATA
#include <MemMap.h>

#if (defined VSM_ENABLE_MODE_CONTROL) || (defined BOOTLOADER)
extern VAR(Vsm_OmcNvDataType, VSM_VAR) Vsm_OmcNvData; /* NVRAM mirror for OMC */
#endif /* VSM_ENABLE_MODE_CONTROL                                             */

#ifdef VSM_ENABLE_WAKEUP_REGISTRATION
extern VAR(Vsm_WurNvDataType, VSM_VAR) Vsm_WurNvData; /* NVRAM mirror for WUR */
#endif /* VSM_ENABLE_WAKEUP_REGISTRATION                                      */

#define VSM_STOP_SEC_VAR_NVDATA
#include <MemMap.h>

#define VSM_START_SEC_CONST_8BIT
#include <MemMap.h>
/* default op-mode- and op-mode-extension-value and
 * default wakeup occurrence counter value
 * in NVRAM in case of errors during NVRAM reading
 */
#ifdef VSM_ENABLE_MODE_CONTROL
extern CONST(Vsm_OmcNvDataType, VSM_CONST) Vsm_OmcNvData_Default;
#endif /* VSM_ENABLE_MODE_CONTROL                                             */

#ifdef VSM_ENABLE_WAKEUP_REGISTRATION
extern CONST(Vsm_WurNvDataType, VSM_CONST) Vsm_WurNvData_Default;
#endif /* VSM_ENABLE_WAKEUP_REGISTRATION                                      */

#define VSM_STOP_SEC_CONST_8BIT
#include <MemMap.h>


#if defined (VSM_VERSION_BAC3x)
#define VSM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

extern CONST(Vsm_ComMUserArrayType, VSM_CONST)
                                            VsmComMUserArray[VSM_NUM_COMMUSERS];
extern CONST(uint8, VSM_CONST)
              Vsm_ComMChannelUserMap[VSM_COMM_NUM_CHANNELS][VSM_COMM_NUM_USERS];
extern CONST(Vsm_ComMBusTypeOfChannelType, VSM_CONST)
                                Vsm_ComMBusTypeOfChannel[VSM_COMM_NUM_CHANNELS];

extern CONST(boolean, VSM_CONST) Vsm_NmChannelComMChannelCheck[VSM_COMM_NUM_CHANNELS];

extern CONST(uint8, VSM_CONST) Vsm_NmChannelComMChannelMap[VSM_COMM_NUM_CHANNELS];

#define VSM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>
#endif

#define VSM_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>
extern VAR(Vsm_StateType, VSM_VAR)  Vsm_State;

#ifdef VSM_ENABLE_MODE_CONTROL
/* NV mirror for OMC */
extern VAR(Vsm_OmcNvDataType, VSM_VAR) Vsm_OmcNvDataGateEntry;
#endif /* VSM_ENABLE_MODE_CONTROL                                             */

#define VSM_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

extern FUNC(void, VSM_PRIVATE_CODE)
                             Vsm_BlockDem( Vsm_DemHandlungFunctionType func );
extern FUNC(void, VSM_PRIVATE_CODE)
                             Vsm_UnBlockDem( Vsm_DemHandlungFunctionType func );

#define VSM_STOP_SEC_CODE
#include <MemMap.h>


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define VSM_START_SEC_CODE
#include <MemMap.h>

/* initialisation of client */
extern FUNC(void, VSM_PUBLIC_CODE)
            Vsm_Init(void);

/* status machine of Vsm client */
extern FUNC(void, VSM_PUBLIC_CODE)
            Vsm_MainFunction(void);

/* global callback routine for applications */
extern FUNC(void, VSM_PUBLIC_CODE)
            Vsm_Cbk(Vsm_CallbackType type, uint32 param);

#define VSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* VSM_CLIENT_FIM_H */

/*** End of file **************************************************************/
