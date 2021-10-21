
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2009 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  FrTrcv.c
 *    Component:  MICROSAR FR Transceiver Driver
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  FlexRay transceiver driver implementation, according to:
 *                AUTOSAR FlexRay Transceiver Driver, AUTOSAR Release 3.0
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Knut Winkelbach               wnk           Vctr Informatik GmbH
 *  Andreas Herkommer             hr            Vctr Informatik GmbH
 *  Klaus Bergdolt                ber           Vctr Informatik GmbH
 *  Sebastian Schmar              ssr           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00   2005-05-24  hr      -             Creation
 *  1.02.00   2006-05-22  ber     -             Adaptation to AUTOSAR 2.0
 *  2.00.00   2006-08-24  hr      -             Complete rework for Gen2
 *  2.01.00   2006-12-15  ber     -             Import wakeup source definition from EcuM.h
 *  2.02.00   2007-07-26  ssr     -             Initialize FrTrcv_Status word with zero, 
 *                                              delete readout of status word within init phase
 *  2.03.00   2007-08-31  hr      -             Minor Updates, Memory Mapping
 *  2.03.01   2007-12-16  hr      -             ESCAN00023747 Development Error Tracer was triggered by wrong compares
 *  3.00.00   2008-02-05  hr      -             Complete rework for AUTOSAR Release 3.0
 *  3.00.01   2008-02-12  hr      -             Minor updates
 *  3.00.02   2008-02-13  hr      -             Editorial changes
 *  3.00.03   2008-03-12  hr      -             Compiler Abstraction
 *            2008-03-12  hr      -             New configuration parameters
 *            2008-03-12  hr      -             MISRA checks
 *  3.00.04   2008-03-28  hr      -             Incorporated Review findings
 *  3.00.05   2008-04-01  hr      ESCAN00025654 Clear Transceiver Wakeup
 *  3.00.06   2008-04-18  hr      ESCAN00025971 DEM events wrapper
 *            2008-04-18  hr      ESCAN00025640 Version check of GENy component against implementation
 *            2008-04-18  hr      ESCAN00026133 Support of InitMemory service
 *            2008-04-18  hr      ESCAN00026286 Wakeup detected init
 *            2008-04-18  hr      ESCAN00026287 interrupt & polling in CB
 *            2008-04-18  hr      -             Lib version check
 *  3.00.07   2008-06-04  hr      ESCAN00027346 Removed FRTRCV_WU_POWER_ON and FRTRCV_LOCALWAKEUP detection
 *  3.00.08   2008-07-04  hr      ESCAN00026625 Extension for MSR3.0 generator version checks
 *  3.00.09   2008-08-18  hr      ESCAN00029287 Single Channel API incomplete for FrTrcv_30_Tja1080dio_Cbk_WakeupByTransceiver
 *            2008-08-18  hr      ESCAN00029454 Library issue with number of Transceivers
 *  3.01.00   2008-10-01  hr      ESCAN00029735 instanceID by FrTrcv_30_Tja1080dio_GetVersionInfo not set
 *  3.02.00   2008-11-07  hr      ESCAN00031137 ERRN Pin not low for wakeup detection
 *  3.03.00   2008-11-19  hr      ESCAN00030263 PreCompile and Linktime Crc Check
 *  3.04.00   2008-11-27  hr      ESCAN00031637 Remove Support of SWS Req FrTrcv309
 *  3.05.00   2008-12-02  hr      ESCAN00031775 Remove unnecessary MISRA violations
 *  3.05.01   2009-02-25  hr      ESCAN00033397 Missing extern in call-back declaration
 *            2009-02-25  hr      ESCAN00029695 AUTOSAR Dummy Statements
 *            2009-02-25  hr      ESCAN00033495 Wrong MemMap.h sections used
 *            2009-02-25  hr      ESCAN00034964 Single Channel API change for AUTOSAR SWS compliance
 *  3.05.02   2009-05-05  hr      ESCAN00034905 Wrong MemMap.h Stop section defines
 *  3.05.03   2009-05-06  hr      ESCAN00034037 Compile warnings by extended version checks
 *  3.05.04   2009-07-30  hr      ESCAN00036155 pre-processor checks for building the library
 *  3.05.05   2009-10-29  hr      ESCAN00038804 Support Vendor Id and vendor api infix in file and API names
 *  3.05.06   2010-01-19  hr      ESCAN00040215 Extended Version Check causes compile error
 *            2010-02-08  hr      ESCAN00040646 Remove dio in naming
 *  3.05.07   2010-03-26  hr      ESCAN00041864 EcuM_SetWakeupEvent call with active interrupt locks
 *            2010-04-21  hr      ESCAN00040839 Move FrTrcv_TrcvModeType and FrTrcv_TrcvWUReasonType to Fr_GeneralTypes.h
 *  3.05.08   2010-05-18  hr      ESCAN00042990 Missing MISRA2004 justifications
 *                                ESCAN00043289 Interrupts are enabled to early in FrTrcv_Phy
 *  3.05.09   2010-07-15  hr      ESCAN00044081 Transceiver might hang in Goto-Sleep Mode
 *  3.06.00   2011-02-22  hr      ESCAN00047306 Adapt MainFunction for usage with IdentityManagerConfig
 *********************************************************************************************************************/
#ifndef FRTRCV_H
#define FRTRCV_H


/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "ComStack_Types.h"
#include "Fr_GeneralTypes.h"
#include "EcuM_Cbk.h"
#include "FrTrcv_30_Tja1080_Cfg.h"

#if ( FRTRCV_PROD_ERROR_DETECT == STD_ON )
  #include "Dem.h"
#endif


#  include "SchM_FrTrcv_30_Tja1080.h"


/**************************************************************************************************
* Version
**************************************************************************************************/
/* BCD coded version number */
/* ##V_CFG_MANAGEMENT ##CQProject : DrvTrans_Tja1080FrdioAsr CQComponent : Implementation */
#define DRVTRANS_TJA1080FRDIOASR_VERSION         0x0306u /* BCD coded version number */
#define DRVTRANS_TJA1080FRDIOASR_RELEASE_VERSION 0x00u   /* BCD coded version number */

/* Implemented AUTOSAR Specification Version */
#define FRTRCV_AR_VERSION           (0x0102u)
#define FRTRCV_AR_RELEASE_VERSION   (0x01u)

/* supported Autosar version */
#define FRTRCV_AR_MAJOR_VERSION     (1u)
#define FRTRCV_AR_MINOR_VERSION     (2u)
#define FRTRCV_AR_PATCH_VERSION     (1u)
#define FRTRCV_SW_MAJOR_VERSION     (3u)
#define FRTRCV_SW_MINOR_VERSION     (5u)
#define FRTRCV_SW_PATCH_VERSION     (9u)

#define FRTRCV_VENDOR_ID (30u) /* Vector = 30 */
#define FRTRCV_MODULE_ID (71u)  /* FlexRay Trcv = 71 */


#ifdef V_EXTENDED_BUILD_LIB_CHECK
 /* pre-processor checks for building the library */
# if (FRTRCV_CONFIG_VARIANT == 1 )
#  error  "Component FrTrcv: Config variant must be 2 or 3 at lib delivery."
# endif
#endif

/**************************************************************************************************
* Global defines
**************************************************************************************************/

#  define FrTrcv_EnterCritical() SchM_Enter_FrTrcv_30_Tja1080(FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0)
#  define FrTrcv_LeaveCritical() SchM_Exit_FrTrcv_30_Tja1080(FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0)


#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
  /* The channel handle can be optimized in single channel configurations. */
  /* Definition of channel parameter. */
  #define FRTRCV_CHANNEL_SYSTEMTYPE_ONLY    void
  #define FRTRCV_CHANNEL_SYSTEMTYPE_FIRST
  #define FRTRCV_CHANNEL_IDX                0u
#else
  /* Definition of channel parameter. */
  #define FRTRCV_CHANNEL_SYSTEMTYPE_ONLY    uint8 FrTrcv_TrcvIdx
  #define FRTRCV_CHANNEL_SYSTEMTYPE_FIRST   uint8 FrTrcv_TrcvIdx,
  #define FRTRCV_CHANNEL_IDX                FrTrcv_TrcvIdx
#endif


/* Development errors */
/* Definition of the API ID */
#define FRTRCV_TRCVINIT_SERVICE_ID                     0u
#define FRTRCV_SETTRANSCEIVERMODE_SERVICE_ID           1u
#define FRTRCV_GETTRANSCEIVERMODE_SERVICE_ID           5u
#define FRTRCV_GETTRANSCEIVERWUREASON_SERVICE_ID       6u
#define FRTRCV_GETVERSIONINFO_SERVICE_ID               7u
#define FRTRCV_DISABLETRANSCEIVERWAKEUP_SERVICE_ID    10u
#define FRTRCV_ENABLETRANSCEIVERWAKEUP_SERVICE_ID     11u
#define FRTRCV_CLEARTRANSCEIVERWAKEUP_SERVICE_ID      12u
#define FRTRCV_MAINFUNCTION_SERVICE_ID                13u
#define FRTRCV_CBK_WAKEUPBYTRANSCEIVER                14u

/* Definition of errors/exceptions */
#define FRTRCV_E_FR_INVALID_TRCVIDX                 0x01u
#define FRTRCV_E_FR_UNINIT                          0x10u
#define FRTRCV_E_FR_TRCV_NOT_STANDBY                0x11u
#define FRTRCV_E_FR_TRCV_NOT_NORMAL                 0x12u
#define FRTRCV_E_FR_TRCV_NOT_SLEEP                  0x13u
#define FRTRCV_E_FR_TRCV_NOT_RECEIVEONLY            0x14u
/* Additional development errors, not officially specified yet */
#define FRTRCV_E_FR_INVALID_POINTER                 0x20u


/**************************************************************************************************
* Global data types and structures
**************************************************************************************************/

#define FRTRCV_WAKEUP_NONE              (uint8)0u
#define FRTRCV_WAKEUP_POLLING           (uint8)1u
#define FRTRCV_WAKEUP_INTERRUPT         (uint8)2u

typedef uint8 FrTrcv_InitStatusType;
#define FRTRCV_UNINIT  (FrTrcv_InitStatusType)0u /* The FrTrcv is not initialized and is not usable. */
#define FRTRCV_INIT    (FrTrcv_InitStatusType)1u /* The FrTrcv is initialized and is usable. */


typedef struct
{
  FrTrcv_TrcvModeType    FrTrcv_BusLowPowerMode; /* The lowest allowed operation mode */
  FrTrcv_TrcvModeType    FrTrcv_InitState;       /* The initial operation mode */
  EcuM_WakeupSourceType  FrTrcv_WakeupSourceRef; /* Wake Up Source Reference */
  uint8                  FrTrcv_WakeupByNodeUsedPolling; /* Is Wakeup detected by polling oder isr */
  uint8                  FrTrcv_ReadOutWS; /* Wait states used for status word read out */
} FrTrcv_GenConfigType;


/**************************************************************************************************
* Prototypes of export variables
**************************************************************************************************/

/****************************************************************************/
/* Constants for export with unspecified size                               */
/****************************************************************************/
#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CONST_UNSPECIFIED
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

extern CONST( uint8, FRTRCV_CONST ) FrTrcv_MaxNumOfBtrBusses;
extern CONST( FrTrcv_GenConfigType, FRTRCV_CONST ) FrTrcv_Config[MAX_NUM_OF_BTR_BUSSES];

#if ( FRTRCV_CRC_CHECK == STD_ON )
extern CONST(uint32, FRTRCV_CONST) FrTrcv_PreCompileCRC32;
#endif

#if ( FRTRCV_PROD_ERROR_DETECT == STD_ON )
extern CONST( Dem_EventIdType, FRTRCV_CONST ) FrTrcv_DEM_E_NoControl;
#endif

extern CONST( uint32, FRTRCV_CONST ) FrTrcv_GeneratorVersion;

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CONST_UNSPECIFIED
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

/****************************************************************************/
/* 32 Bit Constants for export                                              */
/****************************************************************************/
#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CONST_32BIT
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
extern CONST( uint32, FRTRCV_CONST ) DRVTRANS_TJA1080FRDIOASR_LIB_SYMBOL;
#endif

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CONST_32BIT
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

/****************************************************************************/
/* 8 Bit Constants for export                                               */
/****************************************************************************/
#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CONST_8BIT
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

extern CONST( uint8, FRTRCV_CONST ) FRTRCV_30_TJA1080_MAJOR_VERSION; /* Major version number */
extern CONST( uint8, FRTRCV_CONST ) FRTRCV_30_TJA1080_MINOR_VERSION; /* Minor version number */
extern CONST( uint8, FRTRCV_CONST ) FRTRCV_30_TJA1080_PATCH_VERSION; /* Patch level version number */

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CONST_8BIT
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif


/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CODE
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

extern FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_InitMemory( void );
extern FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_TrcvInit(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);
#if ( FRTRCV_MAIN_FUNCTION_CYCLE_TIME > 0 )
  extern FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_MainFunction( void );
#else
  #define FrTrcv_30_Tja1080_MainFunction()
#endif
#if ( FRTRCV_VERSION_INFO_API == STD_ON )
  extern FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRTRCV_APPL_DATA) versioninfo);
#endif
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_SetTransceiverMode(FRTRCV_CHANNEL_SYSTEMTYPE_FIRST FrTrcv_TrcvModeType FrTrcv_TrcvMode);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_GetTransceiverMode(FRTRCV_CHANNEL_SYSTEMTYPE_FIRST P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvModePtr);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_GetTransceiverWUReason(FRTRCV_CHANNEL_SYSTEMTYPE_FIRST P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvWUReasonPtr);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_DisableTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_EnableTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_ClearTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);

#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
/* PRQA S 3453 7 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function-like macro. */
#define FrTrcv_30_Tja1080_TrcvInit(TrcvIdx)                                FrTrcv_30_Tja1080_TrcvInit()
#define FrTrcv_30_Tja1080_SetTransceiverMode(TrcvIdx, FrTrcv_TrcvMode)     FrTrcv_30_Tja1080_SetTransceiverMode(FrTrcv_TrcvMode)
#define FrTrcv_30_Tja1080_GetTransceiverMode(TrcvIdx, FrTrcv_TrcvModePtr)  FrTrcv_30_Tja1080_GetTransceiverMode(FrTrcv_TrcvModePtr)
#define FrTrcv_30_Tja1080_GetTransceiverWUReason(TrcvIdx, FrTrcv_TrcvWUReasonPtr) FrTrcv_30_Tja1080_GetTransceiverWUReason(FrTrcv_TrcvWUReasonPtr)
#define FrTrcv_30_Tja1080_DisableTransceiverWakeup(TrcvIdx)                FrTrcv_30_Tja1080_DisableTransceiverWakeup()
#define FrTrcv_30_Tja1080_EnableTransceiverWakeup(TrcvIdx)                 FrTrcv_30_Tja1080_EnableTransceiverWakeup()
#define FrTrcv_30_Tja1080_ClearTransceiverWakeup(TrcvIdx)                  FrTrcv_30_Tja1080_ClearTransceiverWakeup()
#endif /* #if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u ) */

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CODE
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif


/***** end of header file ************************************************************************/
#endif
  /* ifndef FRTRCV_H */
