/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2008 - 2011 by Vctr Informatik GmbH.                                          All rights reserved.

                This software is copyright protected and proprietary to Vctr Informatik GmbH.
                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vctr Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  FrSM.c
      Project:  FlexRay State Manager
       Module:  -
    Generator:  -

  Description:  Implementation of AUTOSAR FlexRay State Manager AUTOSAR Release 3.0
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Mark A. Fingerle              mfi           Vctr Informatik GmbH
  Sebastian Schmar              ssr           Vctr Informatik GmbH
  Thomas Petrus                 pet           Vctr Informatik GmbH
  Klaus Bergdolt                ber           Vctr Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  00.01.00  2007-07-06  mfi     -             Initial version
  00.02.00  2007-08-07  mfi     -             New SWS v0.7
  00.03.00  2007-09-13  mfi     -             Changed course of code review
  00.04.00  2007-09-21  mfi     -             Initialization changed usage of Organi, Adaption to the generated (GENy) sources,  Shift the ComM callback to an other transition, Var initialization: POC freeze
  00.05.00  2007-09-26  mfi     -             New SWS v0.9, Transition T17 added
  00.06.00  2007-11-30  ssr     ESCAN00023503 Call FrIf_AllowColdstart if the node is coldstart node
  00.07.00  2007-12-07  pet     ESCAN00023837 Incorrect state used in a Det check, correct develop version
  00.08.00  2007-12-12  ber                   adapted to FrIf 3.0 API
  00.09.00  2008-01-27  mfi     ESCAN00024316 Fr network does not startup if duration t1 configured as zero --> timer modified
  00.10.00  2008-02-13  mfi     ESCAN00024158 Evaluation of T08 modified necessary because of timer configuration equal to zero, Adaptation to FrSM SWS 3.0 Rev 2
  01.00.00  2008-02-21  mfi     ESCAN00025109 ASR 3.0 FrIf_ControllerInit has a return value, cast to (void)
                                ESCAN00025110 include "ComM_FrSM.h" instead of "ComM_Cbk.h"
  01.01.00  2008-02-21  mfi     ESCAN00025102 Memory Mapping and Compiler Abstraction added
                                ESCAN00025103 Version defines and version checks modified
                                ESCAN00025104 ComM_FrSM_ModeIndication ==> ComM_BusSM_ModeIndication
                                ESCAN00025191 The index of the for loop FRSM_ClusterIdx was used after the loop as Det instance ID, in FrSm_GetCurrentComMode, FrSm_RequestComMode, or if FrSm_GetCurrentComMode
                                ESCAN00025209 Suggestion for Improvement  Allows the FrSM to handle the Fr channels controller specific
                                ESCAN00025210 Skip first wake up, if the network is already awake (FrIf_GetTransceiverWUReason)
                                ESCAN00025280 FrSM may not perform automatic restart process T17
                                ESCAN00025416 FrSM may raise a wrong DEM failed message
                                ESCAN00025652 Correct setting of DEM-Errors within BSW-Module Libraries, shift Dem function to _Lcfg.c
  01.02.00  2008-04-04  mfi     ESCAN00025803 Compiler Abstraction _STATIC_ substituted by ASR 3.0 STATIC
  01.02.01  2008-04-05  mfi     ESCAN00026016 Change startup sequence if the network is already awake
                                ESCAN00026128 (Re)move unneeded interrupt blocks
                                ESCAN00026109 FrSM has defined wrong ASR version number
                                ESCAN00026177 Extension for MSR3.0 LinkTime checks
                                ESCAN00026268 Rename files and #include statements according coding styles
  01.03.00  2008-07-01  mfi     ESCAN00027384 Startup time is one FlexRay cycle to long
                                ESCAN00028029 FrSM inform the FrNm about the loss of synchronization [005 006]
                                ESCAN00028163 Add "else" branch in T06 T16 T17 FRSM_State_ONLINE FRSM_State_HALT_REQ to avoid MISAR warnings
                                ESCAN00028165 Shift Dem include to avoid MISAR warnings
                                ESCAN00028166 Change FRSM_ClusterIndexType to uint8 to avoid MISRA warnings
                                ESCAN00028170 Not ASR conform null pointer define is used NULL ==> NULL_PTR
                                ESCAN00028199 Redundant check if the POC state is valid T10+T16
                                ESCAN00028259 Remove Placeholder/reminder for the check of the Cfg.h version
  01.04.00  2008-07-27  mfi     ESCAN00026503 Extension for MSR3.0 generator version checks
                                ESCAN00027976 Resource and Runtime optimization at DET calls
                                ESCAN00029340 pointer for ComM_BusSM_ModeIndication as parameter
  01.05.00  2008-09-23  mfi     ESCAN00030246 Use UpperCamelCase notation for the configuration parameter
                                ESCAN00030616 Pointer indirection for channel specific configuration parameter
                                ESCAN00030618 The switching of the PDUs are mapped by a function and shifted to FrSM_Lcfg.c
                                ESCAN00030669 FrSM delivers a wrong instance ID in the Det parameter
                                ESCAN00030670 Add compiler abstraction for function local pointers to data defined in the Lcfg.c file
                                ESCAN00030671 Correct the pointer and memory class in the compiler abstraction macros
                                ESCAN00030756 No WUP transmission when startup is repeated in case of passive wakeup [005]
                                ESCAN00030876 Inform the FrNm about the loss of synchronization cyclic [005 006]
                                ESCAN00030942 FrSM never report a Dem failed message
  01.06.00  2008-11-13  mfi     ESCAN00031339 ECU does not join after unsuccessful startup (T12 and T13 becomes executed immediately in the request function) [008]
                                ESCAN00031298 Add Ecu Passive Mode Handling [020]
                                ESCAN00031433 FrSM uses wrong pointer compiler abstraction
                                ESCAN00031484 FrSM doesn't (de)activate the Deadline monitoring
                                ESCAN00026282 Wrong value of FRSM_SW_PATCH_VERSION when calling the function FrSm_GetVersionInfo
  01.07.00  2009-02-13  mfi     ESCAN00032950 Add support of t3 timer and unlimited startup repetitions [019 017 006 005]
                                ESCAN00033132 FrSM performs startup without wakeup after sync-loss
                                ESCAN00033269 Interrupt lock missing
                                ESCAN00033273 Compiler abstraction and memory mapping for local variables are missing
  01.07.01  2009-03-23  mfi     ESCAN00034043 Compiler Warning "pointless comparison of unsigned integer with zero" if CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION is zero
                                ESCAN00034175 Wrong memory mapping for pointers to FRSM_ClusterStateDataType variables
  01.08.00  2009-05-05  mfi     ESCAN00034655 FrSM delivers the wrong communication mode
                                ESCAN00034743 Memory mapping doesn't work, compile error "MemMap.h, wrong pragma command"
                                ESCAN00034814 Compile error caused by wrong memory mapping PBCFG as CONST
                                ESCAN00034978 Optimize code size
                                ESCAN00033948 Optional usage of FlexRay transceiver driver [014 005 006]
                                ESCAN00034945 Optional usage of FrNm_FrSM_SyncLossIndication() [006]
                                ESCAN00036194 Compiler warning like "variable declared but never used" ConfigOfCurrentClusterPtr
                                ESCAN00036413 Compiler warning like "Redundantly declared symbol" FrSMClusterState
                                ESCAN00036418 Misra warning Rule 5.6; Name Spaces of Identifiers FrSMLinktimeCRC
                                ESCAN00036108 pre-processor checks for building the library
                                ESCAN00036650 Wrong FlexRay transceiver mode, if  function FrSM_SetEcuPassive is used
  01.09.00  2009-10-23  mfi     ESCAN00038708 FrSM first startup repetition being too late in case of a passive wakeup
                                ESCAN00038712 Shorten the duration of interrupt lock  FRSM_EXCLUSIVE_AREA_0
                                ESCAN00039025 Remove include "FrTrcv.h"
  01.10.00  2010-07-13  mfi     ESCAN00043912 Add change notification for BswM
                                ESCAN00043908 Change API for long term synchronization loss
                                ESCAN00043553 Add support for XCP shutdown
                                ESCAN00043918 Configurable number of wake-up patterns in FRSM_WAKEUP
                                ESCAN00044177 Configurable delay of first AllowColdstart in case of a startup with out WUP
                                ESCAN00044184 Support configuration value zero for timer T1
  01.11.00  2011-01-13  mfi     ESCAN00047495 Adapt MainFunction for usage with IdentityManagerConfig (and Init)
                                ESCAN00047729 Pointer might point to undefined memory areas when DET is activated
                                ESCAN00047987 Parse error error in FrSm.c #error "The FrSM state notification algorithm follows the assumption that TRUE is equal to 1"
  01.11.01  2011-09-13  mfi     ESCAN00053563 Add support for delayed FlexRay communication cluster shutdown
  01.11.02  2011-11-03  mfi     ESCAN00054648 DelayTimer for FlexRay communication cluster shutdown runs only if POC::HALT
**********************************************************************************************************************/

#define V_ASRFRSM_COMPONENT_SOURCE

/**********************************************************************************************************************
* INCLUDES
**********************************************************************************************************************/

#include "FrIf.h"
/* #include "Com.h" Shifted to FrSM_Cfg.h. Needed for the functions Com_IpduGroupStart and Com_IpduGroupStop. */
#include "ComM.h"               /* needed because of communication manager modes */

/* interrupts blocked by standard library */
# include "SchM_FrSM.h"
/* interrupts blocked by vector solution*/

#include "FrSM.h"

#if ( STD_ON ==  FRSM_DEV_ERROR_DETECT )
# include "Det.h"
#endif
#if ( STD_ON == FRSM_PROD_ERROR_DETECT )
# include "Dem.h"
#endif

#if ( STD_ON == FRSM_FRNM_HANDLING )
# include "FrNm_FrSM.h"         /* needed because of callback function FrNm_FrSM_StartupError */
#endif

#if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION )
# include "BswM_FrSM.h"
#endif

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
# include "v_ver.h"
# include "EcuM_Cbk.h"
#elif ( STD_ON == FRSM_CRC_CHECK )
# include "EcuM_Cbk.h"
#endif


/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/

#if ( 0x01u != FRSM_SW_MAJOR_VERSION || 0x11u != FRSM_SW_MINOR_VERSION || 0x02u != FRSM_SW_PATCH_VERSION )
# error "File FrSM.c: Source and FrSM.h file are inconsistent!"
#endif
#if ( CCL_ASRSMFR_VERSION != CCL_ASRSMFR_TYPES_HEADER_VERSION || CCL_ASRSMFR_RELEASE_VERSION != CCL_ASRSMFR_TYPES_HEADER_RELEASE_VERSION )
# error "File FrSM.c: Source and FrSM_Types.h file are inconsistent!"
#endif


#if ( STD_ON == FRSM_FRNM_HANDLING )
# if ( 0x03u > FRNM_FRSM_MAJOR_VERSION || 0x03u == FRNM_FRSM_MAJOR_VERSION && 0x10u > FRNM_FRSM_MINOR_VERSION )
#  error "File FrSM.c: FrNm version is incompatible because of changed API name. Version as from 3.10.00 is needed."
# endif
#endif



#if defined (V_EXTENDED_BUILD_LIB_CHECK)
 /**********************************************************************************************************************
 *  BUILD LIB CHECK
 *********************************************************************************************************************/
# if (FRSM_CONFIG_VARIANT == 0x01u)
#  error "FrSM: It is not allowed to create a library with configured configuration variant PRE-COMPILE!"
# endif
#endif


/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/


#define FRSM_SINGLE_CHANNEL_WAKEUP                                    (0x00u)
#define FRSM_NO_WAKEUP                                                (0x01u)  /* ECU has been wakened by bus  OR  ECU is no wakeup ECU */

/* Deactivate the error notification to the Dem */
#if ( STD_ON ==  FRSM_PROD_ERROR_DETECT )
# define FrSM_DemReportErrorStatus( FrSM_ErrorNumber, FrSM_Status )   FrSm_Dem_ReportErrorEvent( (FrSM_ErrorNumber), (FrSM_Status) );  /* PRQA S 3412 */ /* MD_MSR_19.4 */
#else
# define FrSM_DemReportErrorStatus( FrSM_ErrorNumber, FrSM_Status )
#endif

/* interrupts blocked by standard library */
# define FRSM_EnterCritical_0()              SchM_Enter_FrSM(FRSM_EXCLUSIVE_AREA_0)
# define FRSM_LeaveCritical_0()               SchM_Exit_FrSM(FRSM_EXCLUSIVE_AREA_0)
# define FRSM_EnterCritical_1()              SchM_Enter_FrSM(FRSM_EXCLUSIVE_AREA_1)
# define FRSM_LeaveCritical_1()               SchM_Exit_FrSM(FRSM_EXCLUSIVE_AREA_1)
# define FRSM_EnterCritical_2()              SchM_Enter_FrSM(FRSM_EXCLUSIVE_AREA_2)
# define FRSM_LeaveCritical_2()               SchM_Exit_FrSM(FRSM_EXCLUSIVE_AREA_2)
# define FRSM_EnterCritical_3()              SchM_Enter_FrSM(FRSM_EXCLUSIVE_AREA_3)
# define FRSM_LeaveCritical_3()               SchM_Exit_FrSM(FRSM_EXCLUSIVE_AREA_3)
/* interrupts blocked by vector solution*/


/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

#if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  )
# define FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC VAR( boolean, FRSM_VAR_ZERO_INIT ) FRSM_IsInitialized = FALSE;

# define FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif


#if ( STD_ON == FRSM_ECU_PASSIVE_MODE )
# if ( STD_ON == FRSM_TRCV_HANDLING )
#  define FRSM_START_SEC_VAR_NOINIT_8BIT
#  include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */
STATIC VAR( boolean, FRSM_VAR_NOINIT )  FrSM_EcuPassiveMode;
#  define FRSM_STOP_SEC_VAR_NOINIT_8BIT
#  include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */
# else
#  define FrSM_EcuPassiveMode   0
# endif /* end #if ( STD_ON == FRSM_TRCV_HANDLING ) */
#else
# define FrSM_EcuPassiveMode   0
#endif /* ( STD_ON == FRSM_ECU_PASSIVE_MODE ) */


#define FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* makes the configuration pointer (delivered as FrSm_Init parameter) visible in all functions of the FrSM */
STATIC P2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) FrSM_ClusterCfgPtr;

#define FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */


#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
# define FRSM_START_SEC_CONST_32BIT
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST( uint32, FRSM_CONST ) CCL_ASRSMFR_LIB_SYMBOL = CCL_ASRSMFR_LIB_VERSION;
/* PRQA S 3408 */ /* MD_MSR_19.1 */

# define FRSM_STOP_SEC_CONST_32BIT
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define FRSM_START_SEC_CODE
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */


STATIC FUNC( Fr_POCStateType, FRSM_CODE ) FRSM_DeterminePOC  ( FRSM_CtrlIdxType ControllerIndex );

STATIC FUNC( void, FRSM_CODE ) FRSM_FrGoOfflineHalt   ( CONSTP2VAR( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr, CONSTP2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr );
STATIC FUNC( void, FRSM_CODE ) FRSM_FrOfflineReStart  ( CONSTP2VAR( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr, CONSTP2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr );
STATIC FUNC( void, FRSM_CODE ) FRSM_StopTrcv      ( CONSTP2VAR( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr, CONSTP2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr );

STATIC FUNC( void, FRSM_CODE ) FRSM_MainFunction  ( FRSM_ClusterIndexType const FRSM_ClusterIdx );


/*********************************************************************************************************************
  FUNCTION: FRSM_DeterminePOC
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: FRSM_CtrlIdxType                  ControllerIndex

  Output: -
  Return: Fr_POCStateType                   FrSM_PocStateReturn
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: FRSM_MainFunction
  Precondition:

*********************************************************************************************************************/
STATIC FUNC( Fr_POCStateType, FRSM_CODE ) FRSM_DeterminePOC( FRSM_CtrlIdxType ControllerIndex )
{
  VAR( Fr_POCStateType, AUTOMATIC )  FrSM_PocStateReturn = FR_POCSTATE_CONFIG;
  VAR( Fr_POCStatusType, AUTOMATIC ) FrSmPOCStatus;

  if (  E_OK == FrIf_GetPOCStatus( ControllerIndex, &FrSmPOCStatus )  )
  {
    if ( TRUE == FrSmPOCStatus.Freeze )
    {
      FrSM_PocStateReturn = FR_POCSTATE_HALT;
    }
    else
    {
      FrSM_PocStateReturn = FrSmPOCStatus.State;
    }
  }

  return FrSM_PocStateReturn;

}     /* end FRSM_DeterminePOC () */


/*********************************************************************************************************************
  FUNCTION: FRSM_FrGoOfflineHalt
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: FRSM_ClusterIndexType             FRSM_ClusterIdx
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: FRSM_MainFunction
  Precondition:

*********************************************************************************************************************/
STATIC FUNC( void, FRSM_CODE ) FRSM_FrGoOfflineHalt( CONSTP2VAR( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr, CONSTP2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr )
{

  /* used in T09 and T14 */
  (void)FrIf_SetState         ( (*ConfigOfCurrentClusterPtr).FrSMClusterIndex, FRIF_GOTO_OFFLINE );
  (void)FrIf_HaltCommunication( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
#if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION )
  BswM_FrSM_StateChangeNotification(  (*ConfigOfCurrentClusterPtr).FrSMNetworkHandle, (FrSM_BswM_StateType)( (*StateOfCurrentClusterPtr).FRSM_InternalState + (uint8)FrSM_EcuPassiveMode ), ( FRSM_BSWM_HALT_REQ + (FrSM_BswM_StateType)FrSM_EcuPassiveMode )  );
#endif /* if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION ) */
#if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY )
  (*StateOfCurrentClusterPtr).FrSM_Timer_TrcvStbyDelay =  FrSMTrcvStbyDelayTimer[ (*ConfigOfCurrentClusterPtr).FrSMClusterIndex ];
#endif /* if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY ) */
  (*StateOfCurrentClusterPtr).FRSM_InternalState = FRSM_STATE_HALT_REQ;

}    /* end FRSM_FrGoOfflineHalt () */


/*********************************************************************************************************************
  FUNCTION: FRSM_FrOfflineReStart
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: FRSM_ClusterIndexType             FRSM_ClusterIdx
          FRSM_CtrlIdxType                  ControllerIndex

  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: FRSM_MainFunction
  Precondition:

*********************************************************************************************************************/
STATIC FUNC( void, FRSM_CODE ) FRSM_FrOfflineReStart( CONSTP2VAR( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr, CONSTP2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr )
{

  /* used in T10 and T17 */
  (void)FrIf_SetState           ( (*ConfigOfCurrentClusterPtr).FrSMClusterIndex, FRIF_GOTO_OFFLINE );
  (void)FrIf_ControllerInit     ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
  (void)FrIf_StartCommunication ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
  (*StateOfCurrentClusterPtr).FRSM_StartupCounter            = 1;
  /* start timer t2: */
  (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = FRSM_CANCEL_TIMER;
  (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup    = (*ConfigOfCurrentClusterPtr).FrSMDurationT2;
  /* (*StateOfCurrentClusterPtr).FRSM_InternalState             = FRSM_STATE_STARTUP; already done */

}    /* end FRSM_FrOfflineReStart () */


/*********************************************************************************************************************
  FUNCTION: FRSM_StopTrcv
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: FRSM_ClusterIndexType             FRSM_ClusterIdx
          FRSM_CtrlIdxType                  ControllerIndex
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: FRSM_MainFunction
  Precondition:

*********************************************************************************************************************/
STATIC FUNC( void, FRSM_CODE ) FRSM_StopTrcv( CONSTP2VAR( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr, CONSTP2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr )
{

  /* used in T11 MainFunc() and (T12 + T13) RequestCommode() */
#if ( STD_ON == FRSM_TRCV_HANDLING )
  (void)FrIf_SetTransceiverMode      ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel, FRTRCV_TRCVMODE_STANDBY );
  (void)FrIf_EnableTransceiverWakeup ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel );
#endif /* end #if ( STD_ON == FRSM_TRCV_HANDLING ) */
  (void)FrIf_ControllerInit          ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
  (*StateOfCurrentClusterPtr).FRSM_InternalState = FRSM_STATE_READY;
}    /* end FRSM_StopTrcv () */


/*********************************************************************************************************************
  FUNCTION: FRSM_MainFunction
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: FRSM_ClusterIndexType             FRSM_ClusterIdx                 channel handle
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: FrSm_MainFunction_<Cluster Id>
  Precondition: FrSM initialisation

*********************************************************************************************************************/
STATIC FUNC( void, FRSM_CODE ) FRSM_MainFunction( const FRSM_ClusterIndexType FRSM_ClusterIdx )
{
  CONSTP2VAR ( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr   = &FrSMClusterState[ FRSM_ClusterIdx ];
  CONSTP2CONST ( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG )       ConfigOfCurrentClusterPtr  = &FrSM_ClusterCfgPtr[ FRSM_ClusterIdx ];
  VAR( Fr_POCStateType, AUTOMATIC )         FrSM_CurrentPocState = FR_POCSTATE_CONFIG; /* The initialiser is always modified before being used. But some compilers don't understand it, so it's initialized to avoid a warning */
#if ( STD_ON == FRSM_TRCV_HANDLING )
  VAR( FrTrcv_TrcvWUReasonType, AUTOMATIC ) FrSM_TrcvWUReason    = FRTRCV_WU_NOT_SUPPORTED;
#endif
#if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION )
  VAR( uint8, AUTOMATIC )  FrSM_PriorState                       = (*StateOfCurrentClusterPtr).FRSM_InternalState;
#endif
  VAR( Fr_POCStatusType, AUTOMATIC ) FrSmPOCStatus;


#if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  )
  if ( FALSE == FRSM_IsInitialized )
  {
#endif  /* if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  ) */

#if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) && ( STD_OFF == FRSM_IDENTITY_MANAGER_CONFIG )  )
    Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_MAINFUNCTION0_SERVICE_ID, FRSM_E_NOT_INITIALIZED );
#endif
#if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  )
  }
  else  /* else if ( true == FRSM_IsInitialized ) */
#endif  /* if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  ) */
  {
#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
  if ( (FRSM_ClusterIndexType)FrSMCountOfFrClusters <= FRSM_ClusterIdx )
  {
    Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_MAINFUNCTION0_SERVICE_ID, FRSM_E_INV_HANDLE );
  }
#endif

  /* Timer t3 count down. Supervises the startup of the FlexRay cluster */
  if (  ( FRSM_CANCEL_TIMER != (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail )  )
  {
    (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail--;
  }


  FRSM_EnterCritical_0(); /* Blocks FrSm_RequestComMode( NoCom )  */
  if ( FRSM_MODE_REQUEST_RESET == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode )
  {
    /* Request NoComReq+FullComReq in sequence during FRSM_STATE_WAKEUP OR FRSM_STATE_STARTUP */
    (*StateOfCurrentClusterPtr).FRSM_InternalState             = FRSM_STATE_STARTUP; /* enable T05 T06 */

    (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = FRSM_CANCEL_TIMER; /* cancel t1 avoid T04 */
    (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup    = FRSM_TIMER_EXPIRED + 1; /* enable T05 T06 */
    (*StateOfCurrentClusterPtr).FRSM_StartupCounter            = 0;
    (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail     = (*ConfigOfCurrentClusterPtr).FrSMDurationT3; /* re-start error timer t3 */
    (*StateOfCurrentClusterPtr).FRSM_RequestedComMode          = COMM_FULL_COMMUNICATION;
    if ( TRUE == (*ConfigOfCurrentClusterPtr).FrSMIsWakeupEcu )
    {
      (*StateOfCurrentClusterPtr).FRSM_WakeUpType              = FRSM_SINGLE_CHANNEL_WAKEUP;
    }
  } /* end if ( FRSM_MODE_REQUEST_RESET == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode ) */
  FRSM_LeaveCritical_0();


  /* Here a part of the state machine is handled. It has to be prevented that the main function and the RequestComMode accesses the state machine simultaneous. */
  switch ( (*StateOfCurrentClusterPtr).FRSM_InternalState )
  {
    case FRSM_STATE_READY :
    {
      /* check (FULL_COM) once for the transitions T01 and T02 */
      if ( COMM_FULL_COMMUNICATION == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode )
      {
#if ( STD_ON == FRSM_TRCV_HANDLING )
# if ( STD_ON == FRSM_ECU_PASSIVE_MODE )
      FRSM_EnterCritical_1();
        if ( FALSE == FrSM_EcuPassiveMode )
        {
# endif /* end if ( STD_ON == FRSM_ECU_PASSIVE_MODE ) */
          (void)FrIf_SetTransceiverMode       ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel, FRTRCV_TRCVMODE_NORMAL );
# if ( STD_ON == FRSM_ECU_PASSIVE_MODE )
        }
        else
        {
          (void)FrIf_SetTransceiverMode       ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel,  FRTRCV_TRCVMODE_RECEIVEONLY );
        }
# endif /* end if ( STD_ON == FRSM_ECU_PASSIVE_MODE ) */
        (void)FrIf_DisableTransceiverWakeup ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel );
        (void)FrIf_GetTransceiverWUReason   ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel, &FrSM_TrcvWUReason );
        (void)FrIf_ClearTransceiverWakeup   ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel );
#endif /* end #if ( STD_ON == FRSM_TRCV_HANDLING ) */

        (*StateOfCurrentClusterPtr).FRSM_StartupCounter = 1;

        /* Transition T01 (READY to WAKEUP) Condition: [ reqComMode = FullCom & IsWakeupECU ] */
#if ( STD_ON == FRSM_TRCV_HANDLING )
        if (  (TRUE == (*ConfigOfCurrentClusterPtr).FrSMIsWakeupEcu) && (FRTRCV_WU_BY_BUS != FrSM_TrcvWUReason) )
#else
        if ( TRUE == (*ConfigOfCurrentClusterPtr).FrSMIsWakeupEcu )
#endif /* end else #if ( STD_ON == FRSM_TRCV_HANDLING ) */
        {
          (void)FrIf_SendWUP ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
          (*StateOfCurrentClusterPtr).FRSM_WakeUpType    = FRSM_SINGLE_CHANNEL_WAKEUP;
          (*StateOfCurrentClusterPtr).FRSM_InternalState = FRSM_STATE_WAKEUP;
#if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP )
          (*StateOfCurrentClusterPtr).FRSM_WakeUpPatternCounter = 1;
          (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = (*ConfigOfCurrentClusterPtr).FrSMDurationT1;
#endif /* if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP ) */
        }     /* end if Transition T01 */

        /* Transition T02 (READY to STARTUP) Condition: [ reqComMode = FullCom & ! IsWakeupECU ] */
        else                    /* NO WakeUp ECU */
        {
          (void)FrIf_StartCommunication       ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
#if ( STD_ON == FRSM_ENABLE_DELAY_ALLOWCOLDSTART )
          if ( FALSE == (*ConfigOfCurrentClusterPtr).FrSMDelayFirstAllowColdstart )
          {
            /* if CS NOT delayed OR delayed by 0 */
#endif
            /* Rest of T02 is equal to T04 and shift below StateMachine, so T04 AllowCS becomes executed immediately */
            (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = FRSM_TIMER_EXPIRED;
#if ( STD_ON == FRSM_ENABLE_DELAY_ALLOWCOLDSTART )
          }
          else
          {
            /* Rest of T02 is equal to T04 and shift below StateMachine AND delyed by T1 */
            (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = (*ConfigOfCurrentClusterPtr).FrSMDurationT1;
          }
#endif
            /* Rest of T02 is equal to T04 and shift below StateMachine , t2 will be started there, after the AllowCS delay */
          (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup = FRSM_CANCEL_TIMER;
          (*StateOfCurrentClusterPtr).FRSM_WakeUpType    = FRSM_NO_WAKEUP;
          (*StateOfCurrentClusterPtr).FRSM_InternalState = FRSM_STATE_STARTUP;
        } /* end if Transition T02 */
#if ( STD_ON == FRSM_TRCV_HANDLING )
# if ( STD_ON == FRSM_ECU_PASSIVE_MODE )
        FRSM_LeaveCritical_1();
# endif /* end if ( STD_ON == FRSM_ECU_PASSIVE_MODE ) */
#endif /* end #if ( STD_ON == FRSM_TRCV_HANDLING ) */


        (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail  = (*ConfigOfCurrentClusterPtr).FrSMDurationT3; /* start error timer t3 */

      } /* end if FullCom Requested T01 + T02*/

      break;
    } /* end case FRSM_STATE_READY : */
    case FRSM_STATE_WAKEUP :
    {
      /* Transition T13 (WAKEUP to READY) Condition: [ reqComMode = NoCom ] */
      if ( COMM_NO_COMMUNICATION == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode )
      {
        FRSM_StopTrcv( StateOfCurrentClusterPtr, ConfigOfCurrentClusterPtr );
        (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail = FRSM_CANCEL_TIMER;
        (*StateOfCurrentClusterPtr).FRSM_InternalState         = FRSM_STATE_READY;
#if ( STD_ON == FRSM_DEM_SYNCLOSS_INDICATION )
        FrSM_DemReportErrorStatus( FRSM_DEM_SYNC_LOSS_HANDLE, DEM_EVENT_STATUS_PASSED )
#endif
      }     /* end if Transition T13 */
      else  /* FULL communication requested */
      {
      /*  Transition T03 */
#if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP )
        if( (FRSM_TIMER_EXPIRED != (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization) )
        {
          (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization--;
        }

#endif /* if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP ) */
        if (  E_OK == FrIf_GetPOCStatus( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, &FrSmPOCStatus )  )
        {
          if ( FR_POCSTATE_READY == FrSmPOCStatus.State )
          {
#if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP )
            if ( 1 == (*ConfigOfCurrentClusterPtr).FrSMNumWakeupPattern )
            {
#endif /* if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP ) */
              /* Condition for T03 full filled */
              (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = (*ConfigOfCurrentClusterPtr).FrSMDurationT1;
#if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP )
            }
            else if ( FR_WAKEUP_TRANSMITTED == FrSmPOCStatus.WakeupStatus )
            {
              /* enable AllowCS in T03  */
              (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = FRSM_TIMER_EXPIRED;
            }
            else if (  ( FR_WAKEUP_RECEIVED_HEADER == FrSmPOCStatus.WakeupStatus ) || ( FR_WAKEUP_RECEIVED_WUP == FrSmPOCStatus.WakeupStatus )  )
            {
              /* enable condition for T03 */
              (*StateOfCurrentClusterPtr).FRSM_WakeUpPatternCounter   = (*ConfigOfCurrentClusterPtr).FrSMNumWakeupPattern;
            }
            else
            {
              /* MISRA; other values has no impact */
            }

            if ( (*ConfigOfCurrentClusterPtr).FrSMNumWakeupPattern <= (*StateOfCurrentClusterPtr).FRSM_WakeUpPatternCounter )
            {
#endif /* if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP ) */
              /* Transition T03 (WAKEUP to STARTUP) Condition: [ (vPOC!State = Ready) &  ! vPOC!Freeze  &  reqComMode = FullCom ] */
              (void)FrIf_StartCommunication( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );

              (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup = FRSM_CANCEL_TIMER;
              (*StateOfCurrentClusterPtr).FRSM_InternalState          = FRSM_STATE_STARTUP;
#if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP )
            } /* end if trigger T03 */
            else
            {
              (void)FrIf_SendWUP ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
              (*StateOfCurrentClusterPtr).FRSM_WakeUpPatternCounter++;
            } /* end if proceed consecutive WUP sequence */
#endif /* if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP ) */
          } /* end if ( FR_POCSTATE_READY == FrSmPOCStatus.State ) */
        } /* end if POC valid */

      }    /* end else FULL communication requested */

      break;
    } /* end case FRSM_STATE_WAKEUP : */
    case FRSM_STATE_STARTUP :
    {
      /* Timers are only needed in the state FRSM_STARTUP ==> timer handling shifted from main function to state function */
      /* Timer t1 count down ensures a minimum distance between sending a WUP and becoming a leading coldstart node. */
      if( (FRSM_CANCEL_TIMER != (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization) )
      {
        (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization--;
      }
      /* Timer t2 count down. Supervises the startup of the FlexRay cluster */
      if( (FRSM_CANCEL_TIMER != (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup) )
      {
        (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup--;
      }

      /* Transition T12 (STARTUP to READY) Condition: [ reqComMode = NoCom ] */
      if ( COMM_NO_COMMUNICATION == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode )
      {
        FRSM_StopTrcv( StateOfCurrentClusterPtr, ConfigOfCurrentClusterPtr );
        (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = FRSM_CANCEL_TIMER;
        (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail     = FRSM_CANCEL_TIMER;
        (*StateOfCurrentClusterPtr).FRSM_InternalState             = FRSM_STATE_READY;
#if ( STD_ON == FRSM_DEM_SYNCLOSS_INDICATION )
        FrSM_DemReportErrorStatus( FRSM_DEM_SYNC_LOSS_HANDLE, DEM_EVENT_STATUS_PASSED )
#endif
      } /* end if Transition T12 */
      else /* FULL communication requested    OR   FRSM_MODE_REQUEST_RESET */
      {
        /*  Transition T08 */
        /* Transition T08 (STARTUP to ONLINE) Condition: [ vPOC!State = Normal Active & ! vPOC!Freeze ] */
        if (  FR_POCSTATE_NORMAL_ACTIVE == FRSM_DeterminePOC( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex )  )
        {
          /* (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = FRSM_CANCEL_TIMER; */
          /* (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup    = FRSM_CANCEL_TIMER; */
          FrSm_SwitchIpduGroup( (*ConfigOfCurrentClusterPtr).FrSMClusterIndex,  FRSM_PDU_START+(uint8)FrSM_EcuPassiveMode);
          (void)FrIf_SetState       ( (*ConfigOfCurrentClusterPtr).FrSMClusterIndex, FRIF_GOTO_ONLINE );
          FrSM_DemReportErrorStatus ( FRSM_DEM_STARTUP_HANDLE, (uint8)DEM_EVENT_STATUS_PASSED )
          (*StateOfCurrentClusterPtr).FRSM_WakeUpType            = FRSM_SINGLE_CHANNEL_WAKEUP;
        }    /* end if Transition T08 */
        else if ( FRSM_TIMER_EXPIRED == (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup )
        {

          /* Transition T05 (STARTUP to WAKEUP) Condition: t2 [ startupCounter <= WakeupRepetitions && FRSM_CHANNEL_WAKEUP && reqComMode = FullCom ] */
          if (   (  ( (*ConfigOfCurrentClusterPtr).FrSMWakeupRepetitions >= (*StateOfCurrentClusterPtr).FRSM_StartupCounter ) || ( TRUE == (*ConfigOfCurrentClusterPtr).FrSMWakeupUnlimited )  ) && ( FRSM_NO_WAKEUP != (*StateOfCurrentClusterPtr).FRSM_WakeUpType )   )
          {
            (void)FrIf_ControllerInit ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
            (void)FrIf_SendWUP        ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
            (*StateOfCurrentClusterPtr).FRSM_StartupCounter++;
            (*StateOfCurrentClusterPtr).FRSM_InternalState = FRSM_STATE_WAKEUP;
#if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP )
            (*StateOfCurrentClusterPtr).FRSM_WakeUpPatternCounter = 1;
            (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = (*ConfigOfCurrentClusterPtr).FrSMDurationT1;
#endif /* if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP ) */
          }    /* end if Transition T05 */
          /* Transition T06 (STARTUP to STARTUP) Condition: t2 [ WakeupRepetitions < startupCounter & startupCounter <= StartupRepetitions & reqComMode = FullCom ]. Condition "WakeupRepetitions" already assured above */
          else if ( ( (*ConfigOfCurrentClusterPtr).FrSMStartupRepetitions >= (*StateOfCurrentClusterPtr).FRSM_StartupCounter ) || ( TRUE == (*ConfigOfCurrentClusterPtr).FrSMStartupUnlimited ) )
          {
            (void)FrIf_ControllerInit     ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
            (void)FrIf_StartCommunication ( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
            if ( TRUE == (*ConfigOfCurrentClusterPtr).FrSMIsColdstartEcu )
            {
              (void)FrIf_AllowColdstart( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
            }

            if ( FALSE == (*ConfigOfCurrentClusterPtr).FrSMStartupUnlimited )
            {
              (*StateOfCurrentClusterPtr).FRSM_StartupCounter++;
            }
            /* start timer t2: */
            (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup = (*ConfigOfCurrentClusterPtr).FrSMDurationT2;
            /* the state stays the same (*StateOfCurrentClusterPtr).FRSM_InternalState          = FRSM_STATE_STARTUP; */
          }    /* end if Transition T06 */
          else
          {
            /* MISRA */
          }

        }    /* end if: check timer t2 once for the transitions T05 and T06 */
        else
        {
          /* MISRA */
        }
      }    /* end else  ==  FULL communication requested    OR   FRSM_MODE_REQUEST_RESET */

      break;
    } /* end case FRSM_STATE_STARTUP : */
    case FRSM_STATE_ONLINE:
    {
      /*  Transition T09 already handled in the function FrSm_RequestComMode */

      /*  Transition T10 */
      FRSM_EnterCritical_0();
      if ( FRSM_STATE_ONLINE == (*StateOfCurrentClusterPtr).FRSM_InternalState )
      {
        FrSM_CurrentPocState = FRSM_DeterminePOC( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
        /* first part Transition T10 (ONLINE to STARTUP) Condition: [ vPOC!State = Halt | vPOC!State = Ready | vPOC!Freeze ] */
        if ( FR_POCSTATE_HALT == FrSM_CurrentPocState )
        {
          FrSm_SwitchIpduGroup( (*ConfigOfCurrentClusterPtr).FrSMClusterIndex,  FRSM_PDU_STOP+(uint8)FrSM_EcuPassiveMode);
          /* FRSM_FrOfflineReStart shift after the critical section */
          (*StateOfCurrentClusterPtr).FRSM_InternalState         = FRSM_STATE_STARTUP;
          (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail = (*ConfigOfCurrentClusterPtr).FrSMDurationT3;
        }    /* end if Transition T10 */

        /* Transition T16 (ONLINE to ONLINE_PASSIVE) Condition: [ vPOC!State = Normal Passive &  !  vPOC!Freeze ] */
        else if ( FR_POCSTATE_NORMAL_PASSIVE == FrSM_CurrentPocState )
        {
          FrSm_SwitchIpduGroup( (*ConfigOfCurrentClusterPtr).FrSMClusterIndex,  FRSM_PDU_STOP+(uint8)FrSM_EcuPassiveMode);
#if ( STD_ON == FRSM_DEM_SYNCLOSS_INDICATION )
          FrSM_DemReportErrorStatus( FRSM_DEM_SYNC_LOSS_HANDLE, DEM_EVENT_STATUS_FAILED )
#endif
          (*StateOfCurrentClusterPtr).FRSM_InternalState         = FRSM_STATE_ONLINE_PASSIVE;
          (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail =  (*ConfigOfCurrentClusterPtr).FrSMDurationT3;
        }    /* end if Transition T16 */
        else
        {
          /* MISRA */
          /* POC status OK. Nothing to do */
        }
      }    /* if state is FRSM_STATE_ONLINE */

      FRSM_LeaveCritical_0();

      if (  FRSM_STATE_STARTUP == (*StateOfCurrentClusterPtr).FRSM_InternalState  )
      {
        /* second part Transition T10 (ONLINE to STARTUP) Condition: [ vPOC!State = Halt | vPOC!State = Ready | vPOC!Freeze ] */
#if ( STD_ON == FRSM_DEM_SYNCLOSS_INDICATION )
        FrSM_DemReportErrorStatus( FRSM_DEM_SYNC_LOSS_HANDLE, DEM_EVENT_STATUS_FAILED )
#endif
        FRSM_FrOfflineReStart( StateOfCurrentClusterPtr, ConfigOfCurrentClusterPtr );
      }

      break;
    } /* end case FRSM_STATE_ONLINE: */
    case FRSM_STATE_ONLINE_PASSIVE:
    {
      /* Transition T14 (STARTUP to READY) Condition: [ reqComMode = NoCom ] */
      /* shifted to FrSm_RequestComMode() */

      /*  Transition T15 + T17 */
      FRSM_EnterCritical_0();
      if (  FRSM_STATE_ONLINE_PASSIVE == (*StateOfCurrentClusterPtr).FRSM_InternalState  )
      {
        FrSM_CurrentPocState = FRSM_DeterminePOC( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
        /* Transition T15 (ONLINE_PASSIVE to ONLINE) Condition: [ vPOC!State = Normal Active &  ! vPOC!Freeze ] */
        if ( FR_POCSTATE_NORMAL_ACTIVE == FrSM_CurrentPocState )
        {
          FrSm_SwitchIpduGroup( (*ConfigOfCurrentClusterPtr).FrSMClusterIndex,  FRSM_PDU_START+(uint8)FrSM_EcuPassiveMode);
        }    /* end if Transition T15 */

        /* Transition T17 ( ONLINE_PASSIVE  to  STARTUP )  Condition:   *[ vPOC!State = Halt | vPOC!Freeze | vPOC!State = Ready ] */
        else if ( FR_POCSTATE_HALT == FrSM_CurrentPocState )
        {
          /* FRSM_FrOfflineReStart shift after the critical section */
          (*StateOfCurrentClusterPtr).FRSM_InternalState = FRSM_STATE_STARTUP;
        }    /* end if Transition T17 */
        else
        {
          /* MISRA */
        }
      }    /* end else E_OK == FRSM_POCStatusValid  */

      FRSM_LeaveCritical_0();

      if (  FRSM_STATE_STARTUP == (*StateOfCurrentClusterPtr).FRSM_InternalState  )
      {
        /* Transition T17 ( ONLINE_PASSIVE  to  STARTUP )  Condition:   *[ vPOC!State = Halt | vPOC!Freeze | vPOC!State = Ready ] */
        FRSM_FrOfflineReStart( StateOfCurrentClusterPtr, ConfigOfCurrentClusterPtr );
      }

      break;
    } /* end case FRSM_STATE_ONLINE_PASSIVE: */
    case FRSM_STATE_HALT_REQ:
    {
      /*  Transition T11 */
      /* Transition T11 (HALT_REQ to READY) Condition: [ vPOC!State = Halt |    vPOC!Freeze ] */
      if (  FR_POCSTATE_HALT == FRSM_DeterminePOC( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex )  )
      {
#if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY )
        if (  ( FRSM_TIMER_EXPIRED == (*StateOfCurrentClusterPtr).FrSM_Timer_TrcvStbyDelay ) || ( COMM_FULL_COMMUNICATION == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode )  )
        {
#endif /* if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY ) */
          FRSM_StopTrcv( StateOfCurrentClusterPtr, ConfigOfCurrentClusterPtr );
#if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY )
          /* (*StateOfCurrentClusterPtr).FrSM_Timer_TrcvStbyDelay  == FRSM_CANCEL_TIMER; not neccesary because not uded in following state and reinitilaized before used again */
        }
        else
        {
          (*StateOfCurrentClusterPtr).FrSM_Timer_TrcvStbyDelay--;
        }
#endif /* if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY ) */
      }    /* end if FR_POCSTATE_HALT */

      break;
    }
    case FRSM_INITIAL:
    {
      /* FrSM not initialized */
      break;
    }
    default:
    {
      /* FRSM_InternalState has an invalid value */
      /* MISRA demands a default branch.
       * Only possible if the cluster index leads to a memory location outside of the configurated array */
#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
      Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_MAINFUNCTION0_SERVICE_ID, FRSM_E_INV_HANDLE );
#endif
      break;
    }
  }    /* End switch( FRSM_InternalState ) */


  if (  ( FRSM_STATE_STARTUP == (*StateOfCurrentClusterPtr).FRSM_InternalState ) && ( FRSM_TIMER_EXPIRED == (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization )  )
  {
    /* Transition T04 (STARTUP to STARTUP) Condition: T1==0 | t1==0 | WUP received */
    if ( TRUE == (*ConfigOfCurrentClusterPtr).FrSMIsColdstartEcu )
    {
      (void)FrIf_AllowColdstart( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
    }
    /* start timer t2: */
    (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup = (*ConfigOfCurrentClusterPtr).FrSMDurationT2;
    /* The Timer 1 (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization is canceled automatically by next documentation */
    /* the state stays the same (*StateOfCurrentClusterPtr).FRSM_InternalState          = FRSM_STATE_STARTUP; */
  }


#if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION )
  if ( FrSM_PriorState  != (*StateOfCurrentClusterPtr).FRSM_InternalState )
  { /* state has been changed ==> inform BswM */
    BswM_FrSM_StateChangeNotification( (*ConfigOfCurrentClusterPtr).FrSMNetworkHandle,  (FrSM_BswM_StateType)FrSM_PriorState + (uint8)FrSM_EcuPassiveMode, (FrSM_BswM_StateType)( (*StateOfCurrentClusterPtr).FRSM_InternalState + (uint8)FrSM_EcuPassiveMode ) );
  }  /* end if State has been changed  if ( FrSM_PriorState  != (*StateOfCurrentClusterPtr).FRSM_InternalState ) */
#endif /* if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION ) */


  if (  ( FRSM_STATE_WAKEUP == (*StateOfCurrentClusterPtr).FRSM_InternalState ) || ( FRSM_STATE_STARTUP == (*StateOfCurrentClusterPtr).FRSM_InternalState ) || ( FRSM_STATE_ONLINE_PASSIVE == (*StateOfCurrentClusterPtr).FRSM_InternalState )  )
  {
    if ( FRSM_TIMER_EXPIRED == (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail )
    {
      /* T30 */
      FrSM_DemReportErrorStatus( FRSM_DEM_STARTUP_HANDLE, (uint8)DEM_EVENT_STATUS_FAILED )
#if ( STD_ON == FRSM_FRNM_HANDLING )
      FrNm_FrSM_StartupError( (*ConfigOfCurrentClusterPtr).FrSMNetworkHandle );
#endif
    }
    else if ( FRSM_CANCEL_TIMER == (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail )
    {
      /* T31, T32 */
#if ( STD_ON == FRSM_FRNM_HANDLING )
      FrNm_FrSM_StartupError( (*ConfigOfCurrentClusterPtr).FrSMNetworkHandle );
#endif
    }
    else
    {
      /* MISRA */
    }
  }    /* end if   Startup Observation active */
  } /* end else if ( true == FRSM_IsInitialized ) */


}   /* end FRSM_MainFunction( const FRSM_ClusterIndexType FRSM_ClusterIdx ) */



/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/*********************************************************************************************************************
  FUNCTION: FrSM_InitMemory
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: void                              -                               -
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: EcuM / Application

     Function to initialize some global variables which has to be set before the Init has been called (e.g. after ECU reset without power-up)
*********************************************************************************************************************/
FUNC( void, FRSM_CODE ) FrSM_InitMemory( void )
{

#if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  )
    FRSM_IsInitialized = FALSE;
#endif

}    /* end FrSM_InitMemory() */


/*********************************************************************************************************************
  FUNCTION: FrSm_Init
----------------------------------------------------------------------------------------------------------------------
  API     Type                     Name                     Description
----------------------------------------------------------------------------------------------------------------------
   Input: FrSm_ConfigType*         FrSmConfigPtr            configuration structure
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: Communication manager has to be initialized.

   FrSM_Init initializes the FlexRay state machine
*********************************************************************************************************************/
FUNC( void, FRSM_CODE ) FrSm_Init( CONSTP2CONST( FrSm_ConfigType, AUTOMATIC, FRSM_PBCFG ) FrSmConfigPtr )
{
  VAR( sint8_least, AUTOMATIC ) FrSM_ClusterIdx;
  P2VAR( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr = NULL_PTR; /* The initialiser is always modified before being used. But some compilers don't understand it, so it's initialized to avoid a warning */

#if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  )
  if ( NULL_PTR != FrSmConfigPtr )
  {
    FRSM_IsInitialized  = TRUE;
#endif  /* if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  ) */
    FrSM_ClusterCfgPtr  = (*FrSmConfigPtr).FrSMClusterConfigPtr;


#if ( STD_ON == FRSM_CRC_CHECK  )
    if ( (*FrSmConfigPtr).FrSMPrecompileCRC != FRSM_PRECOMPILE_CRC )
    {
      EcuM_GeneratorCompatibilityError( (uint16)FRSM_MODULE_ID, (uint8) 0u);
      return;
    }
    if ( (*FrSmConfigPtr).FrSMLinktimeCRC != FrSM_LinktimeCRC )
    {
      EcuM_GeneratorCompatibilityError( (uint16)FRSM_MODULE_ID, (uint8) 0u);
      return;
    }
#endif


#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
/* Check the PBCfg Configuration. The check tests that major and minor version in the library are valid. */
# if ( FRSM_CONFIG_VARIANT == 3 )
    if(    (   ( (*FrSmConfigPtr).FrSMGeneratorVersion & 0x00FFFF00 ) != (  ( (uint32)CCL_ASRSMFR_GENTOOL_GENY_MAJOR_VERSION<<16 ) | ( (uint32)CCL_ASRSMFR_GENTOOL_GENY_MINOR_VERSION<<8 )  )   )
#  if defined ( CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION )
#   if ( 0x00u != CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION )
         || (  ( (*FrSmConfigPtr).FrSMGeneratorVersion & 0x000000FF ) < CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION  )
#   endif /* 0x00u == CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION */
#  endif /* if defined ( CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION ) */
     )
# else
    if(    (   ( (*FrSmConfigPtr).FrSMGeneratorVersion & 0x00FFFF00 ) != (  ( (uint32)CCL_ASRSMFR_GENTOOL_GENY_MAJOR_VERSION<<16 ) | ( (uint32)CCL_ASRSMFR_GENTOOL_GENY_MINOR_VERSION<<8 )  )   )
#  if defined ( CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION )
#   if ( 0x00u != CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION )
         || (  ( (*FrSmConfigPtr).FrSMGeneratorVersion & 0x000000FF ) < CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION  )
#   endif /* 0x00u == CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION */
#  endif /* if defined ( CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION ) */
     )
 /* currently no difference
  * if(  ( (FrSm_ClusterConfig.FrSMGeneratorVersion & 0x00FFFF00) != (((uint32)CCL_ASRSMFR_GENTOOL_GENY_MAJOR_VERSION<<16) | ((uint32)CCL_ASRSMFR_GENTOOL_GENY_MINOR_VERSION<<8)) ) || ( (FrSm_ClusterConfig.FrSMGeneratorVersion & 0x000000FF) < CCL_ASRSMFR_GENTOOL_GENY_PATCH_VERSION )  ) */
# endif
    {
      EcuM_GeneratorCompatibilityError((uint16) FRSM_MODULE_ID, (uint8) 0);
      return; /* Not continue with the initialization of the component the Application may be influenced critically. */
    }
#endif


#if ( STD_ON == FRSM_ECU_PASSIVE_MODE )
# if ( STD_ON == FRSM_TRCV_HANDLING )
    FrSM_EcuPassiveMode                      = FALSE;
# endif /* end #if ( STD_ON == FRSM_TRCV_HANDLING ) */
#endif /* if ( STD_ON == FRSM_ECU_PASSIVE_MODE ) */

    for ( FrSM_ClusterIdx = (sint8_least)(FrSMCountOfFrClusters - 1);  0 <= FrSM_ClusterIdx; FrSM_ClusterIdx-- )
    {
#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
      CONSTP2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr = &FrSM_ClusterCfgPtr[ FrSM_ClusterIdx ];
#endif

#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
      /* additional checks. Max possible duration value not allowed */
      if ( (FRSM_CANCEL_TIMER <= (*ConfigOfCurrentClusterPtr).FrSMDurationT1) || ((FRSM_CANCEL_TIMER - 1) <= (*ConfigOfCurrentClusterPtr).FrSMDurationT2) )
      {
        Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_INIT_SERVICE_ID, FRSM_E_INV_TIMER_DURATION );
        FRSM_IsInitialized = FALSE;
      }
      /* additional checks. startup greater than wakeup repetitions FrSm069 */
      if ( (*ConfigOfCurrentClusterPtr).FrSMStartupRepetitions < (*ConfigOfCurrentClusterPtr).FrSMWakeupRepetitions )
      {
        Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_INIT_SERVICE_ID, FRSM_E_INV_STARTLTWAKEUP );
        FRSM_IsInitialized = FALSE;
      }
#endif

#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
      if ( TRUE == FRSM_IsInitialized )
#endif
      {
        /* State variable initialisation of the current FR cluster */
        StateOfCurrentClusterPtr = &FrSMClusterState[ FrSM_ClusterIdx ];

        (*StateOfCurrentClusterPtr).FRSM_RequestedComMode          = COMM_NO_COMMUNICATION;
        (*StateOfCurrentClusterPtr).FRSM_Timer_TillSynchronization = FRSM_CANCEL_TIMER;
        (*StateOfCurrentClusterPtr).FRSM_Timer_SuperviseStartup    = FRSM_CANCEL_TIMER;
#if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY )
        /* not necessary, timer only used in FRSM_STATE_HALT_REQ and timer started in T09 and T14 */
        /* (*StateOfCurrentClusterPtr).FrSM_Timer_TrcvStbyDelay       = FRSM_CANCEL_TIMER; */
#endif /* if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY ) */
        (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail     = FRSM_CANCEL_TIMER;
        /* init of FRSM_StartupCounter not necessary */
        (*StateOfCurrentClusterPtr).FRSM_InternalState             = FRSM_STATE_READY;
#if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION )
        /* BswM_FrSM_StateChangeNotification( (*ConfigOfCurrentClusterPtr).FrSMNetworkHandle, FRSM_BSWM_READY_ECU_PASSIVE ); */
#endif /* if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION ) */

        /* Transition T00 (reset to READY) Condition: [ initialization ] */
#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
        (void)FrIf_ControllerInit( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex );
#else
        (void)FrIf_ControllerInit( FrSM_ClusterCfgPtr[ FrSM_ClusterIdx ].FrSMFirstControllerIndex );
#endif
      }

    }   /* end for (each ClusterIdx) */

#if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  )
  }    /* end if pointer NOT points to NULL */
# if ( STD_ON == FRSM_DEV_ERROR_DETECT )
  else                          /* NULL pointer as parameter */
  {
    Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_INIT_SERVICE_ID, FRSM_E_INV_POINTER );
    FRSM_IsInitialized = FALSE;
  }    /* end else (ClusterIdx valid) */
# endif
#endif /* if (  ( STD_ON == FRSM_DEV_ERROR_DETECT ) || ( STD_ON == FRSM_IDENTITY_MANAGER_CONFIG )  ) */

}    /* end FrSm_Init() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */


/*********************************************************************************************************************
  FUNCTION: FrSm_MainFunction_<Cluster Id>
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: -
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: SchM
  Precondition:  have to be called cyclically with a cycle time that is shorter than or equal to the FlexRay cycle .


  Maps the Channel specific Main functions.
*********************************************************************************************************************/
FUNC( void, FRSM_CODE ) FrSm_MainFunction_0(void)
{
  FRSM_MainFunction( (FRSM_ClusterIndexType)0 );
}


/*********************************************************************************************************************
  FUNCTION: FrSm_RequestComMode
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                Description
----------------------------------------------------------------------------------------------------------------------
   Input: NetworkHandleType       NetworkHandle       FlexRay cluster for which a communication mode is requested
          ComM_ModeType           ComM_Mode           requested communication mode.
  Output: -
  Return: Std_ReturnType          E_OK                Request was successful
          Std_ReturnType          E_NOT_OK            Request was not successful, any error occurred
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: FrSM has to be initialized.


  This API function is used by the ComM to startup or shutdown the communication on a FlexRay cluster.
*********************************************************************************************************************/
FUNC( Std_ReturnType, FRSM_CODE ) FrSm_RequestComMode( NetworkHandleType NetworkHandle, ComM_ModeType ComM_Mode )
{
#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
  VAR( Std_ReturnType, AUTOMATIC ) FRSM_StdReturnValue         = E_NOT_OK;
#else
  VAR( Std_ReturnType, AUTOMATIC ) FRSM_StdReturnValue         = E_OK;
#endif
  VAR( FRSM_ClusterIndexType, AUTOMATIC ) FRSM_FoundClusterIdx = 0;
  P2VAR( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr   = NULL_PTR; /* The initialiser is always modified before being used. But some compilers don't understand it, so it's initialized to avoid a warning */
  P2CONST( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr       = NULL_PTR; /* The initialiser is always modified before being used. But some compilers don't understand it, so it's initialized to avoid a warning */
  VAR( sint8_least, AUTOMATIC ) FRSM_ClusterIdx;


#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
  if ( TRUE == FRSM_IsInitialized )
  {
    if ( (COMM_FULL_COMMUNICATION == ComM_Mode) || (COMM_NO_COMMUNICATION  == ComM_Mode) )
    {
#endif
      /* search for the index of the cluster which belongs to the NetworkHandle */
      for ( FRSM_ClusterIdx = (sint8_least)(FrSMCountOfFrClusters - 1);  0 <= FRSM_ClusterIdx; FRSM_ClusterIdx-- )
      {
        if ( FrSM_ClusterCfgPtr[ FRSM_ClusterIdx ].FrSMNetworkHandle == NetworkHandle )
        {
#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
          FRSM_StdReturnValue = E_OK;
#endif
          FRSM_FoundClusterIdx = (FRSM_ClusterIndexType) FRSM_ClusterIdx;
          break;
        }    /* end if. NetworkHandle index in list */
      }    /* end for (). Search ClusterIndex */

#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
      if ( E_OK == FRSM_StdReturnValue )
      {
        /* NetworkHandle found in the array FRSM_NETWORK_HANDLE[] */
      }
      else
      {
        Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_REQUESTCOMMODE_SERVICE_ID, FRSM_E_INV_HANDLE );
      }

    }    /* end if ComM_Mode has an valid value */
    else   /* parameter ComM_Mode has an invalid value */
    {
      Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_REQUESTCOMMODE_SERVICE_ID, FRSM_E_INV_MODE );
    }
  }    /* end if module is initialized */
  else                          /* FrSM has not been initialized  */
  {
    Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_REQUESTCOMMODE_SERVICE_ID, FRSM_E_NOT_INITIALIZED );
  }
#endif


#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
  if ( (Std_ReturnType)E_OK == FRSM_StdReturnValue )
#endif
  {
    StateOfCurrentClusterPtr    = &FrSMClusterState[ FRSM_FoundClusterIdx ];
    ConfigOfCurrentClusterPtr   = &FrSM_ClusterCfgPtr[ FRSM_FoundClusterIdx ];


    if (   ( COMM_NO_COMMUNICATION == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode ) && ( COMM_FULL_COMMUNICATION == ComM_Mode ) && (  ( FRSM_STATE_STARTUP == (*StateOfCurrentClusterPtr).FRSM_InternalState ) || ( FRSM_STATE_WAKEUP == (*StateOfCurrentClusterPtr).FRSM_InternalState )  )   )
    {
      (*StateOfCurrentClusterPtr).FRSM_RequestedComMode = FRSM_MODE_REQUEST_RESET;
    }
    else if ( ( FRSM_MODE_REQUEST_RESET != (*StateOfCurrentClusterPtr).FRSM_RequestedComMode ) || ( COMM_FULL_COMMUNICATION != ComM_Mode ) )
    {
      (*StateOfCurrentClusterPtr).FRSM_RequestedComMode = ComM_Mode;
    }
    else
    {
      /* MISRA */
      /* ( FRSM_MODE_REQUEST_RESET == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode ) && ( COMM_FULL_COMMUNICATION == ComM_Mode )        Sequence No Full Full ModeRequest stays FRSM_MODE_REQUEST_RESET */
    }


    /* transitions of the state machine be processed in this context in order to quicken the timing  */
    if ( (COMM_NO_COMMUNICATION == (*StateOfCurrentClusterPtr).FRSM_RequestedComMode) )
    {
      FRSM_EnterCritical_2();
      {
        /* Transition T09 (ONLINE to HALT_REQ) Condition: [ reqComMode = NoCom ] */
        if ( FRSM_STATE_ONLINE == (*StateOfCurrentClusterPtr).FRSM_InternalState )
        {
          FrSm_SwitchIpduGroup( (*ConfigOfCurrentClusterPtr).FrSMClusterIndex,  FRSM_PDU_STOP+(uint8)FrSM_EcuPassiveMode);
          FRSM_FrGoOfflineHalt( StateOfCurrentClusterPtr, ConfigOfCurrentClusterPtr );
        }    /* end if Transition T09 */
        /* Transition T14 (ONLINE_PASSIVE to HALT_REQ) Condition: [ reqComMode = NoCom ] */
        else if ( FRSM_STATE_ONLINE_PASSIVE == (*StateOfCurrentClusterPtr).FRSM_InternalState )
        {
          FRSM_FrGoOfflineHalt( StateOfCurrentClusterPtr, ConfigOfCurrentClusterPtr );
          (*StateOfCurrentClusterPtr).FRSM_Timer_TillStartUpFail = FRSM_CANCEL_TIMER;
#if ( STD_ON == FRSM_DEM_SYNCLOSS_INDICATION )
          FrSM_DemReportErrorStatus( FRSM_DEM_SYNC_LOSS_HANDLE, DEM_EVENT_STATUS_PASSED )
#endif
        }    /* end if Transition T14 */
        else
        {
          /* MISRA */
        }
      }    /* Exit ExclusiveArea */
      FRSM_LeaveCritical_2();
    }    /* end if (RequestedComMode == NoCom) */
  }    /* end if. any error occurred */


  return FRSM_StdReturnValue;

}    /* end FrSm_RequestComMode() */


/*********************************************************************************************************************
  FUNCTION: FrSm_GetCurrentComMode
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                 Description
----------------------------------------------------------------------------------------------------------------------
   Input: NetworkHandleType       NetworkHandle        FlexRay cluster for which a communication mode is requested
          ComM_ModeType           ComM_ModePtr         Pointer to the memory location where the current communication mode shall be stored
  Output: -
  Return: Std_ReturnType          E_OK                 Request was successful
          Std_ReturnType          E_NOT_OK             Request was not successful, any error occurred
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: FrSM has to be initialized.

*********************************************************************************************************************/
FUNC( Std_ReturnType, FRSM_CODE ) FrSm_GetCurrentComMode( NetworkHandleType NetworkHandle, P2VAR( ComM_ModeType, AUTOMATIC, FRSM_APPL_VAR ) ComM_ModePtr )
{
  VAR( Std_ReturnType, AUTOMATIC ) FRSM_StdReturnValue         = E_NOT_OK;
  VAR( FRSM_ClusterIndexType, AUTOMATIC ) FRSM_FoundClusterIdx = 0;
  VAR( FrIf_StateType, AUTOMATIC ) FrSmFrIf_State              = FRIF_STATE_OFFLINE;
  VAR( sint8_least, AUTOMATIC ) FRSM_ClusterIdx;


#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
  if ( TRUE == FRSM_IsInitialized )
  {
    if ( NULL_PTR != ComM_ModePtr )
    {
#endif
      /* search for the index of the cluster which belongs to the NetworkHandle */
      for ( FRSM_ClusterIdx = (sint8_least)(FrSMCountOfFrClusters - 1);  0 <= FRSM_ClusterIdx; FRSM_ClusterIdx-- )
      {
        if ( FrSM_ClusterCfgPtr[ FRSM_ClusterIdx ].FrSMNetworkHandle == NetworkHandle )
        {
          FRSM_StdReturnValue   = E_OK;
          FRSM_FoundClusterIdx  = (FRSM_ClusterIndexType)FRSM_ClusterIdx;
          break;
        }    /* end if. NetworkHandle index in list */
      }    /* end for (). Search ClusterIndex */

#if ( STD_ON == FRSM_DEV_ERROR_DETECT )
      if ( E_OK == FRSM_StdReturnValue )
      {
        /* NetworkHandle found in the array FRSM_NETWORK_HANDLE[] */
      }
      else
      {
        Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_GETCURRENTCOMMODE_SERVICE_ID, FRSM_E_INV_HANDLE );
      }

    }    /* end if pointer NOT points to NULL_PTR */
    else                        /* NULL_PTR pointer as parameter */
    {
      Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_GETCURRENTCOMMODE_SERVICE_ID, FRSM_E_INV_POINTER );
    }
  }    /* end if module is initialized */
  else                          /* FrSM  not  initialized  */
  {
    Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_GETCURRENTCOMMODE_SERVICE_ID, FRSM_E_NOT_INITIALIZED );
  }
#endif


  if ( (Std_ReturnType)E_OK == FRSM_StdReturnValue )
  {
    FRSM_StdReturnValue = FrIf_GetState( FRSM_FoundClusterIdx, &FrSmFrIf_State );
    if (  ( FRSM_STATE_ONLINE == FrSMClusterState[ FRSM_FoundClusterIdx ].FRSM_InternalState ) && ( E_OK == FRSM_StdReturnValue ) && ( FRIF_STATE_ONLINE == FrSmFrIf_State )  )
    {
      *ComM_ModePtr = COMM_FULL_COMMUNICATION;
    }
    else                        /* NOT FULL communication */
    {
      *ComM_ModePtr = COMM_NO_COMMUNICATION;
    }
  }    /* end if. any error occurred */


  return FRSM_StdReturnValue;


}    /* end FrSm_GetCurrentComMode() */


#if ( STD_ON ==  FRSM_VERSION_INFO_API )
/*********************************************************************************************************************
  FUNCTION: FrSm_GetVersionInfo
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name              Description
----------------------------------------------------------------------------------------------------------------------
  Input: Std_VersionInfoType     *versioninfo      Pointer to where to store the version information of this module.
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: FrSM has to be initialized.

  This service returns the version information of this module. The version information includes:
  - Module Id
  - Vendor Id
  - Vendor specific version numbers (BSW00407).
*********************************************************************************************************************/
FUNC( void, FRSM_CODE ) FrSm_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, FRSM_APPL_VAR ) versioninfo )
{

# if ( STD_ON == FRSM_DEV_ERROR_DETECT )
  if ( NULL_PTR != versioninfo )
  {
# endif
    (*versioninfo).vendorID         = (uint16)FRSM_VENDOR_ID;
    (*versioninfo).moduleID         =  (uint8)FRSM_MODULE_ID;
    (*versioninfo).sw_major_version =  (uint8)FRSM_SW_MAJOR_VERSION;
    (*versioninfo).sw_minor_version =  (uint8)FRSM_SW_MINOR_VERSION;
    (*versioninfo).sw_patch_version =  (uint8)FRSM_SW_PATCH_VERSION;
# if ( STD_ON == FRSM_DEV_ERROR_DETECT )
  }
  else                          /* error parameter versioninfo is a NULL pointer */
  {
    Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_GETVERSIONINFO_SERVICE_ID, FRSM_E_INV_POINTER );
  }
# endif


}    /* end FrSm_GetVersionInfo() */
#endif


#if ( STD_ON == FRSM_ECU_PASSIVE_MODE )
/*********************************************************************************************************************
  FUNCTION: FrSM_SetEcuPassive
----------------------------------------------------------------------------------------------------------------------
  API     Type                        Name                        Description
----------------------------------------------------------------------------------------------------------------------
   Input: boolean                     FrSM_TxOffline              parameter ist true if Ecu Mode should be passive
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer BSW
  Precondition: FrSM has to be initialized.

  This API function notifies the FrSM if ECU has to be set in passive mode
*********************************************************************************************************************/
FUNC( void, FRSM_CODE ) FrSM_SetEcuPassive( boolean FrSM_TxOffline )
{
# if ( STD_ON == FRSM_TRCV_HANDLING )
  VAR( sint8_least, AUTOMATIC ) FrSM_ClusterIdx;


  if ( FrSM_TxOffline != FrSM_EcuPassiveMode )
  {
    /* FrSM_EcuPassiveMode = FrSM_TxOffline; shift below */

    for ( FrSM_ClusterIdx = (sint8_least)(FrSMCountOfFrClusters - 1);  0 <= FrSM_ClusterIdx; FrSM_ClusterIdx-- )
    {
      CONSTP2CONST ( FrSM_ClusterConfigType, AUTOMATIC, FRSM_PBCFG ) ConfigOfCurrentClusterPtr  = &FrSM_ClusterCfgPtr[ FrSM_ClusterIdx ];
      CONSTP2VAR ( FRSM_ClusterStateDataType, AUTOMATIC, FRSM_VAR_NOINIT ) StateOfCurrentClusterPtr    = &FrSMClusterState[ FrSM_ClusterIdx ];

      FRSM_EnterCritical_3();
      if (  ( FRSM_STATE_READY != (*StateOfCurrentClusterPtr).FRSM_InternalState ) && ( FRSM_STATE_HALT_REQ != (*StateOfCurrentClusterPtr).FRSM_InternalState )  )
      {
        if ( TRUE == FrSM_TxOffline )
        {
          (void)FrIf_SetTransceiverMode( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel, FRTRCV_TRCVMODE_RECEIVEONLY );
        }    /* end if passive mode */
        else
        {
          (void)FrIf_SetTransceiverMode( (*ConfigOfCurrentClusterPtr).FrSMFirstControllerIndex, (*ConfigOfCurrentClusterPtr).FrSMFrChannel, FRTRCV_TRCVMODE_NORMAL );
        }   /* end else if active mode */
      }    /* end if transceiver has to be switched */

      FRSM_LeaveCritical_3();

      if ( FRSM_STATE_ONLINE == (*StateOfCurrentClusterPtr).FRSM_InternalState )
      {
        FrSM_Xcp_SetPduMode( (*ConfigOfCurrentClusterPtr).FrSMNetworkHandle, FrSM_EcuPassiveMode );
      }

#if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION )
      BswM_FrSM_StateChangeNotification( (*ConfigOfCurrentClusterPtr).FrSMNetworkHandle, (FrSM_BswM_StateType)( (*StateOfCurrentClusterPtr).FRSM_InternalState + (uint8)FrSM_EcuPassiveMode ), (FrSM_BswM_StateType)( (*StateOfCurrentClusterPtr).FRSM_InternalState + (uint8)FrSM_TxOffline ) );
#endif /* if ( STD_ON == FRSM_STATE_CHANGE_NOTIFICATION ) */

    }  /* end for (). Search ClusterIndex */

    FrSM_EcuPassiveMode = FrSM_TxOffline;

  } /* end if passive mode changed */


# endif /* end #if ( STD_ON == FRSM_TRCV_HANDLING ) */

}    /* end FrSM_SetEcuPassive() */
#endif /* end if ( STD_ON == FRSM_ECU_PASSIVE_MODE ) */


#define FRSM_STOP_SEC_CODE
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */


/* module specific MISRA deviations:
MD_FRSM_1.1
    Reason:     Nesting level exceeded to optimize the code
    Risk:       New compiler (As far as known all compiler used by Vector supports nesting of control structures greater than 15)
    Prevention: runtime test during integration will fail
MD_FRSM_1.2
    Reason:     Null pointer check only active if FRSM_DEV_ERROR_DETECT is activated
    Risk:       usage of null pointer
    Prevention: System has to be evaluated (with activated FRSM_DEV_ERROR_DETECT).
MD_FRSM_8.8
    Reason:     Implemented according basic design spec. The warnig " 'CCL_ASRSMFR_LIB_SYMBOL' has external linkage but is being defined without any previous declaration" is caused by stub test enviroment.
    Risk:       none
    Prevention: Covered by code review.
MD_FRSM_8.12
    Reason:     Avoid libraries with arrays which contains only one single element caused by compiler optimization.
    Risk:       none
    Prevention: Covered by code review.
*/

/*******************************************************************************
* Organi check
*******************************************************************************/



/**********************************************************************************************************************
  END OF FILE: FrSM.c
**********************************************************************************************************************/
/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */
