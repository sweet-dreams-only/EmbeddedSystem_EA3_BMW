/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2008 - 2011 by Vctr Informatik GmbH.                                           All rights reserved.

                This software is copyright protected and proprietary to Vctr Informatik GmbH.
                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vctr Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  FrSM_Types.h
      Project:  FlexRay State Manager
       Module:  -
    Generator:  -

  Description:  Types header of FlexRay State Manager AUTOSAR Release 3.0
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

#ifndef V_FRSM_TYPES_COMPONENT_HEADER
# define V_FRSM_TYPES_COMPONENT_HEADER

/**********************************************************************************************************************
* INCLUDES
**********************************************************************************************************************/

# include "Std_Types.h"
# include "ComM_Types.h"        /* included because of the ComM_ModeType */
# include "Fr_GeneralTypes.h"   /* included because of the Fr_ChannelType */
# include "FrSM_Cfg.h"

/**********************************************************************************************************************
* Version                                                                                                            *
********************************************************************************************************************/

/* FrSM Types header version */
# define CCL_ASRSMFR_TYPES_HEADER_VERSION                             0x0111
# define CCL_ASRSMFR_TYPES_HEADER_RELEASE_VERSION                     0x02


/**************************************************************************************************
* Global defines
**************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

#define FRSM_BSWM_READY                       (0x00u)
#define FRSM_BSWM_READY_ECU_PASSIVE           (0x01u)
#define FRSM_BSWM_STARTUP                     (0x02u)
#define FRSM_BSWM_STARTUP_ECU_PASSIVE         (0x03u)
#define FRSM_BSWM_WAKEUP                      (0x04u)
#define FRSM_BSWM_WAKEUP_ECU_PASSIVE          (0x05u)
#define FRSM_BSWM_HALT_REQ                    (0x06u)
#define FRSM_BSWM_HALT_REQ_ECU_PASSIVE        (0x07u)
#define FRSM_BSWM_KEYSLOT_ONLY                (0x08u)
#define FRSM_BSWM_KEYSLOT_ONLY_ECU_PASSIVE    (0x09u)
#define FRSM_BSWM_ONLINE                      (0x0Au)
#define FRSM_BSWM_ONLINE_ECU_PASSIVE          (0x0Bu)
#define FRSM_BSWM_ONLINE_PASSIVE              (0x0Cu)
#define FRSM_BSWM_ONLINE_PASSIVE_ECU_PASSIVE  (0x0Du)
typedef uint8 FrSM_BswM_StateType;

typedef uint16             FRSM_StartupCounterType;
typedef uint16             FRSM_TimerType;
typedef uint8              FRSM_ClusterIndexType;
typedef uint8              FRSM_CtrlIdxType;


typedef struct
{
  /* the duration has to be lower than the max number of the data type, here is not allowed 0xFFFF */
  FRSM_TimerType          FrSMDurationT1;
  FRSM_TimerType          FrSMDurationT2;
  FRSM_TimerType          FrSMDurationT3;
  /* FrSmStartupRepetitions must be greater or equal FrSMWakeupRepetitions  */
  FRSM_StartupCounterType FrSMWakeupRepetitions;
  FRSM_StartupCounterType FrSMStartupRepetitions;
#if ( STD_ON == FRSM_ENABLE_CONSECUTIVE_WUP )
  uint8                   FrSMNumWakeupPattern;
#endif
  FRSM_ClusterIndexType   FrSMClusterIndex;
  NetworkHandleType       FrSMNetworkHandle;
  FRSM_CtrlIdxType        FrSMFirstControllerIndex;
  /* FRSM_CtrlIdxType        FRSM_LAST_CONTROLLER_INDEX; */
  Fr_ChannelType          FrSMFrChannel;
#if ( STD_ON == FRSM_ENABLE_DELAY_ALLOWCOLDSTART )
  boolean                 FrSMDelayFirstAllowColdstart;
#endif
  boolean                 FrSMIsWakeupEcu;
  boolean                 FrSMIsColdstartEcu;
  boolean                 FrSMStartupUnlimited;
  boolean                 FrSMWakeupUnlimited;
} FrSM_ClusterConfigType;



typedef P2CONST(FrSM_ClusterConfigType, TYPEDEF, FRSM_PBCFG) FrSM_ClusterConfigTypePtr;




/* Local state variable */
typedef struct
{
  FRSM_TimerType          FRSM_Timer_TillSynchronization; /* t1 minimum distance between sending a WUP and start synchronizing (coldstart listen). */
  FRSM_TimerType          FRSM_Timer_SuperviseStartup;   /* t2 to supervise the startup of the FlexRay cluster */
  FRSM_TimerType          FRSM_Timer_TillStartUpFail;   /* t3 to trigger a Dem message and a FrNm message */
#if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY )
  uint16                  FrSM_Timer_TrcvStbyDelay;
#endif /* if ( STD_ON == FRSM_ENABLE_DELAY_TRCV_STANDBY ) */
  FRSM_StartupCounterType FRSM_StartupCounter;          /* The number of startup attempts that have been performed */
  uint8                   FRSM_WakeUpPatternCounter;          /* states of the FrSm state machiene */
  uint8                   FRSM_InternalState;          /* states of the FrSm state machiene */
  uint8                   FRSM_WakeUpType;            /* distinguishes how the FlexRay bus has been wakened */
  ComM_ModeType           FRSM_RequestedComMode;     /* requested mode which the FrSm shall to set */
} FRSM_ClusterStateDataType;





#endif /* V_FRSM_TYPES_COMPONENT_HEADER */
/**********************************************************************************************************************
  END OF FILE: FrSM_Types.h
**********************************************************************************************************************/
/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */

