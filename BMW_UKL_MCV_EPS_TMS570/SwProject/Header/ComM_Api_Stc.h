/*******************************************************************************
**                                                                            **
**  SRC-MODULE: ComM_Api_Stc.h                                                **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : This file contains or includes all external identifiers of    **
**              the AUTOSAR module ComM.                                      **
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
** dare         Daniel Reiss               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.2.0: 04.06.2009, dare: CR70241: fixed module id
 * V1.1.0: 26.01.2009, dare: CR70044: remove Rte prefixes
 * V1.0.1: 15.11.2008, dare: CR70029: use STD_ON, STD_OFF macros
 *                           CR70045: removed NetworkHandleType
 * V1.0.0: 27.11.2007, dare: initial version
 */


#ifndef _COMM_API_STC_H_
#define _COMM_API_STC_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

// #include <TSAutosar.h>         /* EB Automotive AUTOSAR standard types        */
// #include <ComStack_Types.h>    /* AUTOSAR Communication Stack types           */
// #include <ComM_Cfg.h>          /* configuration types                         */

// #if (COMM_RTE_ENABLE == STD_ON)
//    #include <Rte_Type.h>       /* RTE types                                   */
// #endif


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * AUTOSAR module identification
 */
// #if (defined COMM_MODULE_ID) /* to prevent double declaration */
// #error COMM_MODULE_ID already defined
// #endif /* if (defined COMM_MODULE_ID) */

//#define COMM_MODULE_ID 12U

/*
 * Service ID codes
 */
// #if (defined COMM_SID_INIT)
// #error COMM_SID_INIT already defined
// #endif
/* Definition of service ID for ComM_Init */
// #define COMM_SID_INIT  1U

// #if (defined COMM_SID_DEINIT)
// #error COMM_SID_DEINIT already defined
// #endif
/* Definition of service ID for ComM_DeInit */
// #define COMM_SID_DEINIT  2U

// #if (defined COMM_SID_GET_STATUS)
// #error COMM_SID_GET_STATUS already defined
// #endif
/* Definition of service ID for ComM_GetStatus */
// #define COMM_SID_GET_STATUS  3U

// #if (defined COMM_SID_GET_INHIBITION_STATUS)
// #error COMM_SID_GET_INHIBITION_STATUS already defined
// #endif
/* Definition of service ID for ComM_GetInhibitionStatus */
// #define COMM_SID_GET_INHIBITION_STATUS  4U

// #if (defined COMM_SID_REQUEST_COM_MODE)
// #error COMM_SID_REQUEST_COM_MODE already defined
// #endif
/* Definition of service ID for ComM_GetRequestComMode */
// #define COMM_SID_REQUEST_COM_MODE  5U

// #if (defined COMM_SID_GET_MAX_COM_MODE)
// #error COMM_SID_GET_MAX_COM_MODE already defined
// #endif
/* Definition of service ID for ComM_GetMaxComMode */
// #define COMM_SID_GET_MAX_COM_MODE  6U

// #if (defined COMM_SID_GET_REQUESTED_COM_MODE)
// #error COMM_SID_GET_REQUESTED_COM_MODE already defined
// #endif
/* Definition of service ID for ComM_GetRequestedComMode */
// #define COMM_SID_GET_REQUESTED_COM_MODE  7U

// #if (defined COMM_SID_GET_CURRENT_COM_MODE)
// #error COMM_SID_GET_CURRENT_COM_MODE already defined
// #endif
/* Definition of service ID for ComM_GetCurrentComMode */
// #define COMM_SID_GET_CURRENT_COM_MODE  8U

// #if (defined COMM_SID_PREVENT_WAKE_UP)
// #error COMM_SID_PREVENT_WAKE_UP already defined
// #endif
/* Definition of service ID for ComM_PreventWakeUp */
// #define COMM_SID_PREVENT_WAKE_UP  9U

// #if (defined COMM_SID_LIMIT_CHANNEL_TO_NO_COM)
// #error COMM_SID_LIMIT_CHANNEL_TO_NO_COM already defined
// #endif
/* Definition of service ID for ComM_LimitChannelToNoComMOde */
// #define COMM_SID_LIMIT_CHANNEL_TO_NO_COM  11U

// #if (defined COMM_SID_LIMIT_ECU_TO_NO_COM)
// #error COMM_SID_LIMIT_ECU_TO_NO_COM already defined
// #endif
/* Definition of service ID for ComM_LimitEcuToNoComMode */
// #define COMM_SID_LIMIT_ECU_TO_NO_COM 12U

// #if (defined COMM_SID_READ_INHIBIT_COUNTER)
// #error COMM_SID_READ_INHIBIT_COUNTER already defined
// #endif
/* Definition of service ID for ComM_ReadInhibitCounter */
// #define COMM_SID_READ_INHIBIT_COUNTER  13U

// #if (defined COMM_SID_RESET_INHIBIT_COUNTER)
// #error COMM_SID_RESET_INHIBIT_COUNTER already defined
// #endif
/* Definition of service ID for ComM_ResetInhibitCounter */
// #define COMM_SID_RESET_INHIBIT_COUNTER  14U

// #if (defined COMM_SID_SET_ECU_GROUP_CLASS)
// #error COMM_SID_SET_ECU_GROUP_CLASS already defined
// #endif
/* Definition of service ID for ComM_SetECUGroupClassification */
// #define COMM_SID_SET_ECU_GROUP_CLASS  15U

// #if (defined COMM_SID_GET_VERSION_INFO)
// #error COMM_SID_GET_VERSION_INFO already defined
// #endif
/* Definition of service ID for ComM_GetVersionInfo */
// #define COMM_SID_GET_VERSION_INFO  16U

// #if (defined COMM_SID_COMMUNICATION_CONTROL)
// #error COMM_SID_COMMUNICATION_CONTROL already defined
// #endif
/* Definition of service ID for ComM_CommunicationControl */
// #define COMM_SID_COMMUNICATION_CONTROL  17U

// #if (defined COMM_SID_LIMIT_CHANNEL_TO_SILENT_COM)
// #error COMM_SID_LIMIT_CHANNEL_TO_SILENT_COM already defined
// #endif
/* Definition of service ID for ComM_LimitChannelToSilentComMOde */
// #define COMM_SID_LIMIT_CHANNEL_TO_SILENT_COM  18U

// #if (defined COMM_SID_INTERNALS)
// #error COMM_SID_INTERNALS already defined
// #endif
/* Definition of service ID for general functions */
// #define COMM_SID_INTERNALS  19U

// #if (defined COMM_SID_NM_NETWORK_START_IND)
// #error COMM_SID_NM_NETWORK_START_IND already defined
// #endif
/* Definition of service ID for ComM_Nm_NetworkStartIndication */
// #define COMM_SID_NM_NETWORK_START_IND  21U

#if (defined COMM_SID_NM_NETWORK_MODE)
#error COMM_SID_NM_NETWORK_MODE already defined
#endif
/* Definition of service ID for ComM_Nm_NetworkMode */
#define COMM_SID_NM_NETWORK_MODE  24U

#if (defined COMM_SID_NM_PREPARE_BUS_SLEEP)
#error COMM_SID_NM_PREPARE_BUS_SLEEP already defined
#endif
/* Definition of service ID for ComM_Nm_PrepareBusSleepMode */
#define COMM_SID_NM_PREPARE_BUS_SLEEP  25U

#if (defined COMM_SID_NM_BUS_SLEEP_MODE)
#error COMM_SID_NM_BUS_SLEEP_MODE already defined
#endif
/* Definition of service ID for ComM_Nm_BusSleepMode */
#define COMM_SID_NM_BUS_SLEEP_MODE  26U

#if (defined COMM_SID_GET_NUM_SEND_RCV_APPL)
#error COMM_SID_GET_NUM_SEND_RCV_APPL already defined
#endif
/* Definition of service ID for ComM_GetNumSendRcvAppl */
#define COMM_SID_GET_NUM_SEND_RCV_APPL  27U

#if (defined COMM_SID_TRANSITION)
#error COMM_SID_TRANSITION already defined
#endif
/* Definition of service ID for transitions */
#define COMM_SID_TRANSITION  28U

#if (defined COMM_SID_STATE_FUNCTION)
#error COMM_SID_STATE_FUNCTION already defined
#endif
/* Definition of service ID for state function */
#define COMM_SID_STATE_FUNCTION  28U

#if (defined COMM_SID_WAKEUP_PIN_INDICATION)
#error COMM_SID_WAKEUP_PIN_INDICATION already defined
#endif
/* Definition of service ID for wakeup pin indication function */
#define COMM_SID_WAKEUP_PIN_INDICATION  29U

#if (defined COMM_SID_DCM_ACTIVE_DIAGNOSTIC)
#error COMM_SID_DCM_ACTIVE_DIAGNOSTIC already defined
#endif
/* Definition of service ID for ComM_DCM_ActiveDiagnostic */
#define COMM_SID_DCM_ACTIVE_DIAGNOSTIC  31U

#if (defined COMM_SID_DCM_INACTIVE_DIAGNOSTIC)
#error COMM_SID_DCM_INACTIVE_DIAGNOSTIC already defined
#endif
/* Definition of service ID for ComM_DCM_InactiveDiagnostic */
#define COMM_SID_DCM_INACTIVE_DIAGNOSTIC  32U

#if (defined COMM_SID_ECUM_RUN_MODE_IND)
#error COMM_SID_ECUM_RUN_MODE_IND already defined
#endif
/* Definition of service ID for ComM_EcuM_RunModeIndiciation */
#define COMM_SID_ECUM_RUN_MODE_IND  41U

#if (defined COMM_SID_ECUM_WAKE_UP_INDICATION)
#error COMM_SID_ECUM_WAKE_UP_INDICATION already defined
#endif
/* Definition of service ID for ComM_EcuM_WakeupIndiciation */
#define COMM_SID_ECUM_WAKE_UP_INDICATION  42U

#if (defined COMM_SID_BUS_SM_INDICATION)
#error COMM_SID_BUS_SM_INDICATION already defined
#endif
/* Definition of service ID for ComM_BusSm_ModeIndication */
#define COMM_SID_BUS_SM_INDICATION  51U

#if (defined COMM_SID_MAIN_FUNCTION)
#error COMM_SID_MAIN_FUNCTION already defined
#endif
/* Definition of service ID for ComM_MainFunction_<Channel_ID> */
#define COMM_SID_MAIN_FUNCTION  60U

#if (defined COMM_SID_GET_OVERALL_BUS_SLEEP_STATE)
#error COMM_SID_GET_OVERALL_BUS_SLEEP_STATE already defined
#endif
/* Definition of service ID for ComM_GetOverallBusSleepState */
#define COMM_SID_GET_OVERALL_BUS_SLEEP_STATE  61U

#if (defined COMM_SID_PASSIVE_BUS_STARTUP)
#error COMM_SID_PASSIVE_BUS_STARTUP already defined
#endif
/* Definition of service ID for ComM_PassiveBusStartup */
#define COMM_SID_PASSIVE_BUS_STARTUP  62U

#if (defined COMM_SID_BUS_OFF_INDICATION)
#error COMM_SID_BUS_OFF_INDICATION already defined
#endif
/* Definition of service ID for ComM_BusIf_BusOffIndication */
#define COMM_SID_BUS_OFF_INDICATION  62U

#if (defined COMM_E_NOT_INITED)
#error COMM_E_NOT_INITED already defined
#endif
/* API service used without module initialisation */
//#define COMM_E_NOT_INITED  1U

#if (defined COMM_E_WRONG_PARAMETERS)
#error COMM_E_WRONG_PARAMETERS already defined
#endif
/* API service used with wrong parameters */
//#define COMM_E_WRONG_PARAMETERS  2U

#if (defined COMM_E_ERROR_IN_PROV_SERVICE)
#error COMM_E_ERROR_IN_PROV_SERVICE already defined
#endif
/* API services of other modules returned with an error  */
//#define COMM_E_ERROR_IN_PROV_SERVICE  3U

/*----------------------------------------------------------------------------*/

/*
 * Communication control macros
 */

/* protocol specific defines for ComM_CommunicationControl()                  */
#define COMM_DIAG_ENABLE_RX_AND_TX                                         0x00U
#define COMM_DIAG_ENABLE_RX_AND_DISABLE_TX                                 0x01U
#define COMM_DIAG_DISABLE_RX_AND_ENABLE_TX                                 0x02U
#define COMM_DIAG_DISABLE_RX_AND_TX                                        0x03U

#define COMM_DIAG_NORMAL_COMM_MSG                                          0x01U
#define COMM_DIAG_NM_COMM_MSG                                              0x02U
#define COMM_DIAG_NORMAL_AND_NM_COMM_MSG                                   0x03U

/*----------------------------------------------------------------------------*/

/*
 * Empty callbacks
 */

/* Remote sleep handling is not supported                                     */
// #define ComM_Nm_RemoteSleepIndication(channel)
// #define ComM_Nm_RemoteSleepCancelation(channel)
// #define ComM_Nm_PduRxIndication(channel)
// #define ComM_Nm_StateChangeNotification(channel, previousState, currentState)
// #define ComM_Nm_RepeatMessageIndication(channel)

/* run mode is queried explicitely                                            */
/* Tmr */
//#define ComM_EcuM_RunModeIndication(channel)

/* Nm indications are used for passive wakeup                                 */
/* Tmr */
//#define ComM_EcuM_WakeUpIndication(channel)

/*----------------------------------------------------------------------------*/

/*
 * Extension of return type
 */

//#define COMM_E_NOT_OK                                                      0x01U
//#define COMM_E_MODE_LIMITATION                                             0x02U

/*----------------------------------------------------------------------------*/

#if (COMM_RTE_ENABLE == OFF)

/*
 * Values of ComM_BusStateType
 */

#define COMM_BUS_AWAKE                                                      0x00
#define COMM_BUS_SLEEP                                                      0x01
#define COMM_BUS_ERROR                                                      0xFF

/*----------------------------------------------------------------------------*/

/*
 * Values of ComM_ModeType
 */

#define COMM_NO_COMMUNICATION                                                  0
#define COMM_SILENT_COMMUNICATION                                              1
#define COMM_FULL_COMMUNICATION                                                2

#endif /* (COMM_RTE_ENABLE == OFF) */


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#if (COMM_RTE_ENABLE == OFF)
/*
 * mode of the bus state.
 */
typedef uint8 ComM_BusStateType;

/*
 * mode of the Communication Manager
 */
//typedef uint8 ComM_ModeType;
#endif /* (COMM_RTE_ENABLE == OFF) */

/*
 * Initialisation status of ComM
 */

//typedef enum
//{
//   COMM_UNINIT = 0, /* ComM is not initialised or not usable                  */
//   COMM_INIT = 0xA5 /* ComM is initialised and usable                         */
//} ComM_InitStatusType;

/*
 * wakeup types
 */
typedef enum
{
   COMM_WAKEUP_ACTIVE = 0,
   COMM_WAKEUP_PASSIVE
} ComM_WakeupType;

/*
 * Inhibition status of ComM
 */
//typedef uint8 ComM_InhibitionStatusType;


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#define COMM_START_SEC_CODE
#include "MemMap.h"

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_CommunicationControl
//(
//   VAR(uint8, AUTOMATIC) mode,
//   VAR(uint8, AUTOMATIC) controlType
//);

//extern FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic
//(
//   void
//);

//extern FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic
//(
//   void
//);

//extern FUNC(void, COMM_CODE) ComM_DeInit
//(
//   void
//);

//extern FUNC(void, COMM_CODE) ComM_BusIf_BusOffIndication
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel,
//   P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus
//(
//   P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
//);

//extern FUNC(void, COMM_CODE) ComM_Init
//(
//   P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_CONST) Configuration
//);

//extern FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel
//);

//extern FUNC(void, COMM_CODE) ComM_Nm_NetworkMode
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel
//);

//extern FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel
//);

//extern FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter
//(
//   P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter
//(
//   void
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification
//(
//   VAR(ComM_InhibitionStatusType, AUTOMATIC) Status
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode
//(
//   VAR(ComM_UserHandleType, AUTOMATIC) User,
//   P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode
//(
//   VAR(ComM_UserHandleType, AUTOMATIC) User,
//   P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode
//(
//   VAR(ComM_UserHandleType, AUTOMATIC) User,
//   P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetNumSendRcvAppl
//(
//   P2VAR(uint8, AUTOMATIC, COMM_APPL_DATA) sendRcvApplCount
//);

//extern FUNC(void, COMM_CODE) ComM_WakeupPinIndication
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel,
//   VAR(boolean, AUTOMATIC) Status
//);

#if (COMM_VERSION_INFO_API == STD_ON)
//extern FUNC(void, COMM_CODE) ComM_GetVersionInfo
//(
//   P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) VersionInfoPtr
//);
#endif /* (COMM_VERSION_INFO_API == STD_ON) */

#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
//extern FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel,
//   VAR(boolean, AUTOMATIC) Status
//);
#endif /* (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON) */

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
//extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToSilentComMode
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel,
//   VAR(boolean, AUTOMATIC) Status
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel,
//   VAR(boolean, AUTOMATIC) Status
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode
//(
//   VAR(boolean, AUTOMATIC) Status
//);
#endif /* (COMM_MODE_LIMITATION_ENABLED == STD_ON) */

#if (COMM_RTE_ENABLE == STD_OFF)
//extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode
//(
//   VAR(ComM_UserHandleType, AUTOMATIC) User,
//   VAR(ComM_ModeType, AUTOMATIC) ComMode
//);

//extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetOverallBusSleepState
//(
//   P2VAR(ComM_BusStateType, AUTOMATIC, COMM_APPL_DATA) BusState
//);
#endif /* (COMM_RTE_ENABLE == STD_OFF) */

//extern FUNC(void, COMM_CODE) ComM_PassiveBusStartup
//(
//   VAR(ComM_ChannelHandleType, AUTOMATIC) Channel
//);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"


#endif /* _COMM_API_STC_H_ */

/*** End of file **************************************************************/

