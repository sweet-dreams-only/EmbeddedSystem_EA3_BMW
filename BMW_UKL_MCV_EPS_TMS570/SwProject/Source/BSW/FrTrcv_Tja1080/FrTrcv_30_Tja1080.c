
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


/**************************************************************************************************
* Include files
**************************************************************************************************/
/* FlexRay transceiver driver declarations */
#include "FrTrcv_30_Tja1080.h"
#include "FrTrcv_30_Tja1080_Cbk.h"
#include "FrTrcvPhy_30_Tja1080.h"

#if ( FRTRCV_DEV_ERROR_DETECT == STD_ON )
  #include "Det.h"
#endif

#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
  #include "v_ver.h"
#endif


/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
/* Check consistency of source and header file. */
#if ( DRVTRANS_TJA1080FRDIOASR_VERSION != 0x0306u )
  #error "Source and Header file are inconsistent!"
#endif
#if ( DRVTRANS_TJA1080FRDIOASR_RELEASE_VERSION != 0x00u )
  #error "Source and Header file are inconsistent!"
#endif

/* Check consistency of source and GenData. */
#if defined ( DRVTRANS_TJA1080_FR_ASR_DLL_VERSION )
  #if ( DRVTRANS_TJA1080_FR_ASR_DLL_VERSION < 0x0112u )
    #error "Source and GENy component are inconsistent!"
  #endif
#endif


/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/

#ifndef VBCD2DEZ8
/* PRQA S 3453 1 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function like macro */
  #define VBCD2DEZ8(Bcd) (((Bcd)&0xFu)+((((Bcd)>>4)&0xFu)*10))
#endif

#define DRVTRANS_XXXFRASR_LIB_SYMBOL    DRVTRANS_TJA1080_FR_ASR_DLL_VERSION
#define DRVTRANS_XXXFRASR_LIB_VERSION   DRVTRANS_TJA1080_FR_ASR_DLL_RELEASE_VERSION

/****************************************************************************/
/* 32 Bit Constants for export                                              */
/****************************************************************************/
#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CONST_32BIT
  #include "MemMap.h"
#endif

#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
CONST( uint32, FRTRCV_CONST ) DRVTRANS_TJA1080FRDIOASR_LIB_SYMBOL = DRVTRANS_XXXFRASR_LIB_VERSION;
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

CONST( uint8, FRTRCV_CONST ) FRTRCV_30_TJA1080_MAJOR_VERSION = (uint8)(VBCD2DEZ8(DRVTRANS_TJA1080FRDIOASR_VERSION >> 8u));   /* Major version number */
CONST( uint8, FRTRCV_CONST ) FRTRCV_30_TJA1080_MINOR_VERSION = (uint8)(VBCD2DEZ8(DRVTRANS_TJA1080FRDIOASR_VERSION & 0xFFu)); /* Minor version number */
CONST( uint8, FRTRCV_CONST ) FRTRCV_30_TJA1080_PATCH_VERSION = (uint8)(VBCD2DEZ8(DRVTRANS_TJA1080FRDIOASR_RELEASE_VERSION)); /* Patch level version number */

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CONST_8BIT
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif


/**************************************************************************************************
* Macros
**************************************************************************************************/
#ifndef FRTRCV_ABORT
  #if ( FRTRCV_DEV_ERROR_DETECT == STD_ON )
    /* PRQA S 3412 1 *//* MISRA-C:2004 Rule 19.4 VIOLATION: Macro defines an unrecognized code-fragment */
    #define FRTRCV_ABORT(check, instanceId, apiId, errorId) if(FALSE==(check)){Det_ReportError((uint16)FRTRCV_MODULE_ID, (uint8)(instanceId), (uint8)(apiId), (uint8)(errorId)); return;}
  #else
    #define FRTRCV_ABORT(check, instanceId, apiId, errorId)
  #endif
    /* FRFRTRCV_DEV_ERROR_DETECT_ENABLED */
#endif
  /* #ifndef FRFRTRCV_ABORT */

#ifndef FRTRCV_ABORTVAL
  #if ( FRTRCV_DEV_ERROR_DETECT == STD_ON )
    /* PRQA S 3412 1 *//* MISRA-C:2004 Rule 19.4 VIOLATION: Macro defines an unrecognized code-fragment */
    #define FRTRCV_ABORTVAL(check, instanceId, apiId, errorId, retCode) if(FALSE==(check)){Det_ReportError((uint16)FRTRCV_MODULE_ID, (uint8)(instanceId), (uint8)(apiId), (uint8)(errorId)); return(retCode);}
  #else
    #define FRTRCV_ABORTVAL(check, instanceId, apiId, errorId, retCode)
  #endif
    /* FRTRCV_DEV_ERROR_DETECT_ENABLED */
#endif
  /* #ifndef FRTRCV_ABORTVAL(x) */

#if ( FRTRCV_PROD_ERROR_DETECT == STD_ON )
  /* PRQA S 3453 1 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function like macro */
  #define FrTrcv_DemReportError(eventId) ((void)Dem_ReportErrorStatus((Dem_EventIdType)(eventId), (uint8)(DEM_EVENT_STATUS_FAILED)))
#else
  #define FrTrcv_DemReportError(eventId)
#endif


/**************************************************************************************************
* Typedef and Struct definitions
**************************************************************************************************/

/**************************************************************************************************
* Data definitions
**************************************************************************************************/

/******************************************************************************/
/* Local Data definitions with unspecified size                               */
/******************************************************************************/
#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

STATIC VAR( FrTrcv_TrcvWUReasonType, FRTRCV_VAR_NOINIT ) FrTrcv_TrcvWUReason[MAX_NUM_OF_BTR_BUSSES];
STATIC VAR( FrTrcv_InitStatusType, FRTRCV_VAR_NOINIT )   FrTrcv_IsInitialized[MAX_NUM_OF_BTR_BUSSES];

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif


#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_VAR_NOINIT_8BIT
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

STATIC VAR( uint8, FRTRCV_VAR_NOINIT ) FrTrcv_WakeupCbEnabled[MAX_NUM_OF_BTR_BUSSES];
STATIC VAR( uint8, FRTRCV_VAR_NOINIT ) FrTrcv_WakeupDetected[MAX_NUM_OF_BTR_BUSSES];

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_VAR_NOINIT_8BIT
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif


/**************************************************************************************************
* Prototypes for local functions
**************************************************************************************************/
STATIC FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_CheckWakeupEvent( FRTRCV_CHANNEL_SYSTEMTYPE_ONLY );

#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
/* PRQA S 3453 1 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function-like macro. */
#define FrTrcv_30_Tja1080_CheckWakeupEvent(TrcvIdx)    FrTrcv_30_Tja1080_CheckWakeupEvent()
#endif /* #if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u ) */



/**************************************************************************************************
*  Implementation
**************************************************************************************************/

#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_START_SEC_CODE
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_CheckWakeupEvent
   ------------------------------------------------------------------------------------------------
   Description      : Check for current and pending wakeup events
   ------------------------------------------------------------------------------------------------
   Called by        : internal
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : None
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
STATIC FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_CheckWakeupEvent( FRTRCV_CHANNEL_SYSTEMTYPE_ONLY )
{
  FrTrcv_StatusWordType kTrcvCurrentStatusWord;

#if ( FRTRCV_TRCV_DIAGNOSIS == STD_ON )
#else
  FrTrcv_TrcvModeType   FrTrcv_TrcvMode;
  if( (BusTrcvErrorType)BUSTRCV_E_OK == TrcvPhy_30_Tja1080_GetMode(FRTRCV_CHANNEL_IDX, &FrTrcv_TrcvMode) )
  {
    /* Without diagnosis, only STANDBY and SLEEP is relevant for wakeup */
    if( (FRTRCV_TRCVMODE_STANDBY == FrTrcv_TrcvMode) || (FRTRCV_TRCVMODE_SLEEP == FrTrcv_TrcvMode) )
    {
#endif
      /* Get new transceiver status flags */
      if((BusTrcvErrorType)BUSTRCV_E_OK != TrcvPhy_30_Tja1080_ReadStatusWord(FRTRCV_CHANNEL_IDX, &kTrcvCurrentStatusWord))
      {
        FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
      }

      if((kTrcvCurrentStatusWord & (FrTrcv_StatusWordType)FRTRCV_REMOTEWAKEUP) > (FrTrcv_StatusWordType)0u)
      {
        FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX] = FRTRCV_WU_BY_BUS;
        FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)1u;
      }
      else
      if((kTrcvCurrentStatusWord & (FrTrcv_StatusWordType)FRTRCV_LOCALWAKEUP) > (FrTrcv_StatusWordType)0u)
      {
        FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX] = FRTRCV_WU_INTERNALLY;
        FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)1u;
      }
      else
      {
        /* Concluding else */
      }

#if ( FRTRCV_TRCV_DIAGNOSIS == STD_ON )
      {
        uint8_least i;

        i = FrTrcv_StatusMaskTableSize;
        while(i > 0u)
        {
          i--;
          if( (kTrcvCurrentStatusWord & FrTrcv_StatusMaskTable[i]) > (FrTrcv_StatusWordType)0u )
          {
            /* We detected an error, notify DEM */
            FrTrcv_DemReportError( FrTrcv_DEM_E_Table[i] );
          }
        }
      }
#else
    }
  }
  else
  {
    FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
  }
#endif

  if( ((uint8)1u == FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX])
   && ((uint8)1u == FrTrcv_WakeupCbEnabled[FRTRCV_CHANNEL_IDX]) )
  { /* Wakeup callbacks enabled? */
    FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)0u;
    EcuM_SetWakeupEvent(FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_WakeupSourceRef);
  }
}


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_InitMemory
   ------------------------------------------------------------------------------------------------
   Description      : Initialize static variables
   ------------------------------------------------------------------------------------------------
   Called by        : Startup Code / Application
   ------------------------------------------------------------------------------------------------
   Parameter        : None
   ------------------------------------------------------------------------------------------------
   Returncode       : None
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_InitMemory( void )
{
  uint8_least kTrcvChannel;

  for(kTrcvChannel = (uint8_least)0u; kTrcvChannel < FrTrcv_MaxNumOfBtrBusses; kTrcvChannel++ )
  {
    FrTrcv_IsInitialized[kTrcvChannel] = FRTRCV_UNINIT;
  }
}


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_TrcvInit
   ------------------------------------------------------------------------------------------------
   Description      : Initialize the FlexRay Transceiver
   ------------------------------------------------------------------------------------------------
   Called by        : FlexRay Interface
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : None
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_TrcvInit( FRTRCV_CHANNEL_SYSTEMTYPE_ONLY )
{
  FRTRCV_ABORT(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
               FRTRCV_TRCVINIT_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX)

  FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX] = FRTRCV_UNINIT;

#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
 if(((FrTrcv_GeneratorVersion & 0x00FFFF00)!=
   (((uint32)DRVTRANS_TJA1080FRASR_GENTOOL_GENY_MAJOR_VERSION<<16) | ((uint32)DRVTRANS_TJA1080FRASR_GENTOOL_GENY_MINOR_VERSION<<8)))
#if defined ( DRVTRANS_TJA1080FRASR_GENTOOL_GENY_PATCH_VERSION )
  #if( DRVTRANS_TJA1080FRASR_GENTOOL_GENY_PATCH_VERSION != 0 )
   || ((FrTrcv_GeneratorVersion & (uint32)0x000000FF) < DRVTRANS_TJA1080FRASR_GENTOOL_GENY_PATCH_VERSION)
  #endif
#endif
   )
  {
    /* Ms: Call the Vector specific EcuM Error callback and do NOT Call Det_ReportError. */
    EcuM_GeneratorCompatibilityError((uint16) FRTRCV_MODULE_ID, (uint8) 0);
    return; /* Do not continue with the initialization of the component the Application may be influenced critically. */
  }
#endif

#if ( FRTRCV_CRC_CHECK == STD_ON )
  if (FrTrcv_PreCompileCRC32 != FRTRCV_PRECOMPILE_CRC32)
  {
    EcuM_GeneratorCompatibilityError((uint16) FRTRCV_MODULE_ID, (uint8) 0);
    return;
  }
#endif

  /* Initialize physical Transceiver, if required */
  TrcvPhy_30_Tja1080_TrcvInit(FRTRCV_CHANNEL_IDX);

  /* Set the transceiver to a default state */
  if( (BusTrcvErrorType)BUSTRCV_E_OK != TrcvPhy_30_Tja1080_SetMode(FRTRCV_CHANNEL_IDX, FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_InitState) )
  {
    FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
  }

  FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX]  = (uint8)0u;
  FrTrcv_WakeupCbEnabled[FRTRCV_CHANNEL_IDX] = (uint8)0u;
  FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX]    = FRTRCV_WU_NOT_SUPPORTED;
  if( FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_WakeupByNodeUsedPolling > FRTRCV_WAKEUP_NONE)
  {
    FrTrcv_WakeupCbEnabled[FRTRCV_CHANNEL_IDX] = (uint8)1u;
    FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX] = FRTRCV_WU_RESET;
    /* Check for pending wakeup events */
    FrTrcv_30_Tja1080_CheckWakeupEvent( FRTRCV_CHANNEL_IDX );
  }

  FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX] = FRTRCV_INIT;
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

#if ( FRTRCV_MAIN_FUNCTION_CYCLE_TIME > 0 )
/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_MainFunction
   ------------------------------------------------------------------------------------------------
   Description      : Cyclic task
   ------------------------------------------------------------------------------------------------
   Called by        : -
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : void
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_MainFunction( void )
{
  uint8 kTrcvChannel;

  for(kTrcvChannel = (uint8)0u; kTrcvChannel < FrTrcv_MaxNumOfBtrBusses; kTrcvChannel++ )
  {
    if( FRTRCV_INIT == FrTrcv_IsInitialized[kTrcvChannel] )
    {
      if( FRTRCV_WAKEUP_POLLING == FrTrcv_Config[kTrcvChannel].FrTrcv_WakeupByNodeUsedPolling )
      {
        /* Check for pending wakeup events */
        FrTrcv_30_Tja1080_CheckWakeupEvent(kTrcvChannel);
      }
    }
  }
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */
#endif


#if ( FRTRCV_VERSION_INFO_API == STD_ON )
/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_GetVersionInfo
   ------------------------------------------------------------------------------------------------
   Description      : Query module version information
   ------------------------------------------------------------------------------------------------
   Called by        : NodeManager
   ------------------------------------------------------------------------------------------------
   Parameter        : versioninfo: Pointer to version information structure
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRTRCV_APPL_DATA) versioninfo)
{
  FRTRCV_ABORT(NULL_PTR != versioninfo, 0u,
               FRTRCV_GETVERSIONINFO_SERVICE_ID, FRTRCV_E_FR_INVALID_POINTER)

  versioninfo->vendorID         = FRTRCV_VENDOR_ID;
  versioninfo->moduleID         = FRTRCV_MODULE_ID;
  versioninfo->instanceID       = (uint8)0u;
  versioninfo->sw_major_version = FRTRCV_30_TJA1080_MAJOR_VERSION;
  versioninfo->sw_minor_version = FRTRCV_30_TJA1080_MINOR_VERSION;
  versioninfo->sw_patch_version = FRTRCV_30_TJA1080_PATCH_VERSION;
}
#endif


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_SetTransceiverMode
   ------------------------------------------------------------------------------------------------
   Description      : Changes the operation mode of the selected transceiver
   ------------------------------------------------------------------------------------------------
   Called by        : NodeManager
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
                      FrTrcv_TrcvModeType: The Transceive mode that shall be set
   ------------------------------------------------------------------------------------------------
   Returncode       : FrTrcv_StatusType: BUSTRCV_E_OK - Transceiver state change was successful
                                         BUSTRCV_E_ERROR -  Transceiver state change failed or parameter
                                                            is out of range.
                                                            The previous state has not been changed.
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_SetTransceiverMode(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY, FrTrcv_TrcvModeType FrTrcv_TrcvMode)
{
  BusTrcvErrorType result;

  FRTRCV_ABORTVAL(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                  FRTRCV_SETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FRTRCV_ABORTVAL(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                  FRTRCV_SETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  result = (BusTrcvErrorType)BUSTRCV_E_ERROR;
  if(FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_BusLowPowerMode >= FrTrcv_TrcvMode)
  {
    switch(FrTrcv_TrcvMode)
    {
      case FRTRCV_TRCVMODE_NORMAL :
      case FRTRCV_TRCVMODE_STANDBY :
      case FRTRCV_TRCVMODE_SLEEP :
      case FRTRCV_TRCVMODE_RECEIVEONLY :
      {
        result = TrcvPhy_30_Tja1080_SetMode(FRTRCV_CHANNEL_IDX, FrTrcv_TrcvMode);
      } break;
      default :
      {
        return( (BusTrcvErrorType)BUSTRCV_E_ERROR );
      }
    }
  }

  if( (BusTrcvErrorType)BUSTRCV_E_OK != result )
  {
    FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
  }
  return(result);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_GetTransceiverMode
   ------------------------------------------------------------------------------------------------
   Description      : Reads the operation mode of the selected transceiver
   ------------------------------------------------------------------------------------------------
   Called by        : NodeManager
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : FrTrcv_StatusType: BUSTRCV_E_OK - Transceiver state change was successful
                                         BUSTRCV_E_ERROR -  Transceiver state change failed or parameter
                                                            is out of range.
                                                            The previous state has not been changed.
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_GetTransceiverMode(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY, P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvModePtr)
{
  FRTRCV_ABORTVAL(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                  FRTRCV_GETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FRTRCV_ABORTVAL(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                  FRTRCV_GETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FRTRCV_ABORTVAL(NULL_PTR != FrTrcv_TrcvModePtr, FRTRCV_CHANNEL_IDX,
                  FRTRCV_GETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_INVALID_POINTER, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  if( (BusTrcvErrorType)BUSTRCV_E_ERROR == TrcvPhy_30_Tja1080_GetMode(FRTRCV_CHANNEL_IDX, FrTrcv_TrcvModePtr) )
  {
    FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
    return((BusTrcvErrorType)BUSTRCV_E_ERROR);
  }
  return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_GetTransceiverWUReason
   ------------------------------------------------------------------------------------------------
   Description      : Returns the wakeup reason of the selected bus
   ------------------------------------------------------------------------------------------------
   Called by        : NodeManager
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : BUSTRCV_E_OK if no error occured
                      BUSTRCV_E_ERROR  if the transceiver index is out of range
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_GetTransceiverWUReason(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY, P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvWUReasonPtr)
{ 
  FRTRCV_ABORTVAL(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                  FRTRCV_GETTRANSCEIVERWUREASON_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FRTRCV_ABORTVAL(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                  FRTRCV_GETTRANSCEIVERWUREASON_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FRTRCV_ABORTVAL(NULL_PTR != FrTrcv_TrcvWUReasonPtr, FRTRCV_CHANNEL_IDX,
                  FRTRCV_GETTRANSCEIVERWUREASON_SERVICE_ID, FRTRCV_E_FR_INVALID_POINTER, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  *FrTrcv_TrcvWUReasonPtr = FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX];
  return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_DisableTransceiverWakeup
   ------------------------------------------------------------------------------------------------
   Description      : Disables the notification for wakeup events on the selected bus
   ------------------------------------------------------------------------------------------------
   Called by        : NodeManager
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : BUSTRCV_E_OK if no error occured
                      BUSTRCV_E_ERROR  if the transceiver index is out of range
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_DisableTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY)
{
  FRTRCV_ABORTVAL(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                  FRTRCV_DISABLETRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FRTRCV_ABORTVAL(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                  FRTRCV_DISABLETRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  FrTrcv_WakeupCbEnabled[FRTRCV_CHANNEL_IDX] = (uint8)0u;
  return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_EnableTransceiverWakeup
   ------------------------------------------------------------------------------------------------
   Description      : Enables the notification for wakeup events on the selected bus
   ------------------------------------------------------------------------------------------------
   Called by        : NodeManager
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : BUSTRCV_E_OK if no error occured
                      BUSTRCV_E_ERROR  if the transceiver index is out of range
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_EnableTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY)
{
  FRTRCV_ABORTVAL(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                  FRTRCV_ENABLETRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FRTRCV_ABORTVAL(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                  FRTRCV_ENABLETRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  FrTrcv_WakeupCbEnabled[FRTRCV_CHANNEL_IDX] = (uint8)1u;
  /* FRTRCV300 */
  FrTrcv_EnterCritical();
  if( (uint8)1u == FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] )
  {
    FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)0u;
    FrTrcv_LeaveCritical();
    EcuM_SetWakeupEvent(FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_WakeupSourceRef);
  }
  else
  {
    FrTrcv_LeaveCritical();
  }

  return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_ClearTransceiverWakeup
   ------------------------------------------------------------------------------------------------
   Description      : Clears pending wakeup events
   ------------------------------------------------------------------------------------------------
   Called by        : NodeManager
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : BUSTRCV_E_OK if no error occured
                      BUSTRCV_E_ERROR  if the transceiver index is out of range
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_30_Tja1080_ClearTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY)
{
  FRTRCV_ABORTVAL(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                  FRTRCV_CLEARTRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FRTRCV_ABORTVAL(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                  FRTRCV_CLEARTRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  FrTrcv_EnterCritical();
  FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)0u;
  FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX]   = FRTRCV_WU_RESET;
  FrTrcv_LeaveCritical();

  return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */


/**************************************************************************************************
   Function name    : FrTrcv_30_Tja1080_Cbk_WakeupByTransceiver(uint8 FrTrcv_TrcvIdx)
   ------------------------------------------------------------------------------------------------
   Description      : Is triggered by interrupts or used for polling
   ------------------------------------------------------------------------------------------------
   Called by        : ICU
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : - 
**************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_Cbk_WakeupByTransceiver(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY)
{
  FRTRCV_ABORT(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
               FRTRCV_CBK_WAKEUPBYTRANSCEIVER, FRTRCV_E_FR_INVALID_TRCVIDX)
  FRTRCV_ABORT(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
               FRTRCV_CBK_WAKEUPBYTRANSCEIVER, FRTRCV_E_FR_UNINIT)

  if( FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_WakeupByNodeUsedPolling > FRTRCV_WAKEUP_NONE )
  {
    FrTrcv_30_Tja1080_CheckWakeupEvent(FRTRCV_CHANNEL_IDX);
  }
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */


#if ( FRTRCV_MEM_MAPPING == STD_ON )
  #define FRTRCV_STOP_SEC_CODE
  #include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

