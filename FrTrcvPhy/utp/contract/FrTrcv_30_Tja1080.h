
#ifndef FRTRCV_H
#define FRTRCV_H

#include "ComStack_Types.h"
#include "Fr_GeneralTypes.h"

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

#if 0
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

#endif

/***** end of header file ************************************************************************/
#endif
  /* ifndef FRTRCV_H */
