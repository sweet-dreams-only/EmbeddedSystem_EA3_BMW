/* STARTSINGLE_OF_MULTIPLE */
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2011 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*! \file         FrIf.c
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Implementation of the AUTOSAR FlexRay Interface, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 3.0
 **********************************************************************************************************************

 **********************************************************************************************************************
 *  \author AUTHOR IDENTITY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Name                          Initials      Company
 -  -------------------------------------------------------------------------------------------------------------------
 -  Klaus Bergdolt                ber           Vctr Informatik GmbH
 -  Oliver Reineke                ore           Vctr Informatik GmbH
 -  -------------------------------------------------------------------------------------------------------------------
 *  \version REVISION HISTORY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Version   Date        Author  Change Id     Description
 -  -------------------------------------------------------------------------------------------------------------------
 -  3.0.0     2007-12-12  ber     -             release of version 3.0.0 
 -  3.0.1     2008-02-01  ber     -             added compiler abstraction and memory mapping
 -            2008-02-22  ber     -             release of version 3.0.1 
 -  3.0.2     2008-03-20  ber     ESCAN00025115 No changes here
 -            2008-04-02  ber     ESCAN00023644 FrIf detects JobListOutOfSynch in case of large difference of job times
 -            2008-04-03  ber     -             release of version 3.0.2
 -  3.0.3     2008-04-17  ber     ESCAN00026131 Memory Access Violation in embedded code during FrIf job list execution
 -            2008-04-18  ber     ESCAN00025799 No changes here
 -            2008-04-18  ber     -             release of version 3.0.3 
 -  3.0.4     2008-04-25  ore     -             renamed INVALID_JOB_NUMBER to FRIF_INVALID_JOB_NUMBER
 -            2008-04-25  ore     ESCAN00026130 Use <BSW>_InitMemory
 -            2008-04-25  ore     ESCAN00026216 Extension for MSR3.0 LinkTime checks
 -            2008-04-25  ore     ESCAN00026256 Rename files and #include statements according coding styles
 -            2008-04-28  ore     ESCAN00026445 FrIf_Cbk.h is missing
 -            2008-04-28  ore     ESCAN00026447 FrIf_ConfigType is missing in implementation
 -            2008-04-28  ore     ESCAN00026449 FrIf_GetMacroticksDuration is missing
 -            2008-05-15  ore     ESCAN00026651 Extension for MSR3.0 generator version checks
 -            2008-05-19  ore     ESCAN00026973 Inconsistent Memory Mapping
 -            2008-05-21  ore     -             release of version 3.0.4
 -  3.0.5     2008-06-09  ore     -             removed VFRIF_FBL_MODE extension
 -            2008-06-09  ore     ESCAN00026972 No changes here
 -            2008-06-09  ore     ESCAN00026341 No changes here
 -            2008-07-08  ore     ESCAN00027356 No changes here
 -            2008-07-09  ore     ESCAN00028155 FrIf does not clear transmit request when changing to state OFFLINE.
 -            2008-07-11  ore     -             release of version 3.0.5
 -  3.0.6     2008-07-17  ore     ESCAN00027548 No changes here
 -            2008-07-17  ore     -             release of version 3.0.6
 -  3.0.7     2008-07-18  ore     ESCAN00027867 No changes here
 -            2008-07-24  ore     ESCAN00027210 No changes here
 -            2008-07-24  ore     -             Added CrtlIdx Det-Check for FrIf_GetNmVector()
 -            2008-07-24  ore     -             Fixed ClstIdx Det-Check for FrIf_GetMacroticksPerCycle()
 -            2008-07-28  ore     ESCAN00028772 FrIf Single-Controller Optimization
 -            2008-08-01  ore     ESCAN00027451 FrIf Job List Execution in Polling Mode
 -            2008-08-07  ore     ESCAN00029068 No changes here
 -            2008-08-07  ore     ESCAN00029042 FrIf Job List Execution sometimes skips complete round (64 cycles)
 -            2008-08-07  ore     -             added compiler abstraction and memory mapping for FrIf_GetVersionInfo()
 -            2008-08-13  ore     ESCAN00029218 Decrease jitter in case of FrIf task overlapping
 -            2008-08-13  ore     ESCAN00029219 Provide API to monitor the quality of the FrIf job list execution
 -            2008-08-13  ore     ESCAN00029184 Call TxConf-callbacks in case of stopping or resynchronizing the 
 *                                              FrIf-JobList
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No constant is generated as link time paramter for FrIf_Init()
 -            2008-08-22  ore     -             release of version 3.0.8
 -  3.0.9     2008-09-17  ore     -             release of version 3.0.9
 -  3.0.10    2008-10-01  ore     -             Apdapted TxConf-Handling to support configurable task times
 -            2008-10-01  ore     ESCAN00030038 No changes here
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 FrIf variable/function name conventions
 -            2008-10-01  ore     ESCAN00029696 AUTOSAR Dummy Statements
 -            2008-10-01  ore     ESCAN00029736 instanceID by <MSN>_GetVersionInfo
 -            2008-11-03  ore     ESCAN00031030 No changes here
 -            2008-11-03  ore     ESCAN00031026 No changes here
 -            2008-11-04  ore     -             release of version 3.0.10
 -  3.1.0     2008-11-10  ore     ESCAN00030776 FrIf_SetState does not return E_NOT_OK in case it could not start the 
 *                                              job list execution
 -            2008-11-10  ore     ESCAN00030577 No changes here
 -            2008-11-10  ore     ESCAN00030264 PreCompile and Linktime Crc Check
 -            2008-11-10  ore     ESCAN00030764 Concurrent Write Access to FrIf State
 -            2008-11-17  ore     ESCAN00031345 No changes here
 -            2008-11-17  ore     ESCAN00030264 No changes here
 -            2008-11-18  ore     -             added MISRA violation comments
 -            2008-11-24  ore     ESCAN00031360 Implement FrIf_GetChannelStatus() and FrIf_GetClockCorrection()
 -            2008-11-24  ore     -             fixed code-review findings   
 -            2008-12-01  ore     ESCAN00031710 No changes here
 -            2008-12-08  ore     ESCAN00031843 No changes here
 -            2008-12-19  ore     -             release of version 3.1.0
 -  3.2.0     2009-02-02  ore     ESCAN00032463 No changes here
 -            2009-02-10  ore     ESCAN00032944 Call of Fr_ControllerInit
 -            2009-02-17  ore     ESCAN00033102 No changes here
 -            2009-02-18  ore     ESCAN00027867 No changes here
 -            2009-02-18  ore     ESCAN00033318 No changes here
 -            2009-02-18  ore     ESCAN00033145 No changes here
 -            2009-02-18  ore     ESCAN00033220 The functions FrIf_RxTask_0 and FrIf_TxTask_0 shall have standard 
 *                                              return values.
 -            2009-02-18  ore     ESCAN00032895 FrIf Job Concatenation Optimization
 -            2009-02-18  ore     ESCAN00033309 Remove FrIf memory class macros to reduce the number of misra 
 *                                              violations.
 -            2009-02-25  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 The FrIf source and header files don't use the Compiler-Abstraction 
 *                                              keyword STATIC.
 -            2009-02-26  ore     ESCAN00032715 Check at runtime whether the FrIf job execution is performed during 
 *                                              its own slot range.
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     ESCAN00033651 Unify DET implementation
 -            2009-03-06  ore     ESCAN00033665 Add missing Link-time configuration variant
 -            2009-03-16  ore     -             Renamed IsValidPostBuildConfigData routine according to ESCAN00030040
 -            2009-03-10  ore     ESCAN00033732 No changes here
 -            2009-03-23  ore     ESCAN00034040 Extended version check causes compiler warnings
 -            2009-03-23  ore     -             release of version 3.2.0
 -  3.3.0     2009-04-06  ore     ESCAN00036436 Add PRQA misra justification comments for QAC
 -            2009-05-28  ore     ESCAN00035398 No changes here
 -            2009-05-28  ore     ESCAN00035048 MacroTicksLengthInNanoSeconds returns invalid value for systems with 
 *                                              selectable postbuild
 -            2009-06-29  ore     ESCAN00035991 Compiler error when V_USE_DUMMY_STATEMENT == STD_ON
 -            2009-07-06  ore     ESCAN00036053 No changes here
 -            2009-07-20  ore     ESCAN00036397 No changes here
 -            2009-07-14  ore     ESCAN00035990 Pointer in FrIf_Init() is not pointer to the Flexray Init configuration
 -            2009-07-14  ore     ESCAN00035399 The static header files of the FrIf don't include the Memmap.h file 
 -            2009-07-15  ore     ESCAN00036426 Remove obsolete FrIf status changes and FrIf_StopJobExecution calls
 -            2009-07-15  ore     ESCAN00036427 Implement FrIf_DiffTime as static function
 -            2009-07-15  ore     ESCAN00036429 Reduce codesize by implementing the FrIf wrapper APIs as macros
 -            2009-07-15  ore     ESCAN00036451 Unused FrIf APIs cannot be disabled via precompile switch
 -            2009-07-16  ore     ESCAN00036471 Add precompile switch to enable/disable the usage of the request counter 
 *                                              handling
 -            2009-07-17  ore     ESCAN00034459 No changes here
 -            2009-07-28  ore     ESCAN00036120 No changes here
 -            2009-07-31  ore     ESCAN00036776 No changes here
 -            2009-07-31  ore     -             release of version 3.3.0 
 -  3.4.0     2009-08-24  ore     ESCAN00036905 No changes here
 -            2009-08-24  ore     ESCAN00037257 No changes here
 -            2009-09-08  ore     ESCAN00035396 The FrIf bitarrays in postbuild structures are not supported by the 
 *                                              GenTool_GenyFrameworkPostbuildconfig component.
 -            2009-09-08  ore     ESCAN00037643 FrIf_ext.h is not included if FRIF_CUSTOM_JLE_SCHEDULING is set to STD_ON
 -            2009-09-08  ore     ESCAN00037633 No changes here
 -            2009-09-21  ore     ESCAN00036013 Similar DET Usage
 -            2009-10-27  ore     ESCAN00038513 No changes here
 -            2009-11-02  ore     ESCAN00038914 FrIf_StartJobExecution routine shall call Fr_PrepareLPdu for all Rx and 
 *                                              Tx handles to flush the complete hardware FIFO
 -            2009-11-02  ore     ESCAN00038855 No changes here
 -            2009-11-03  ore     ESCAN00038930 The revision history of all source and header files shall contain all 
 *                                              implementation relevant ClearQuest issues of the FrIf.
 -            2009-11-17  ore     ESCAN00039212 Add FrIf_CancelTransmit API according to AUTOSAR 4.0 to reset the 
 *                                              request counter.
 -            2009-11-30  ore     ESCAN00039411 No changes here
 -            2009-12-07  ore     ESCAN00039607 No changes here
 -            2009-12-07  ore     ESCAN00039609 No changes here
 -            2009-12-07  ore     -             release of version 3.4.0 
 -  3.5.0     2010-01-11  ore     -             Added additional code-size and runtime optimizations
 -            2010-02-01  ore     ESCAN00040508 Add feature to support FreeOp-Callbacks
 -            2010-02-16  ore     ESCAN00040867 No changes here
 -            2010-02-18  ore     ESCAN00040951 No changes here
 -            2010-02-18  ore     ESCAN00040960 DEM errors are reported by the FlexRay Interface if the main function 
 *                                              is called before the FrIf state is set by the FrSM.
 -            2010-02-22  ore     ESCAN00039809 No changes here
 -            2010-03-18  ore     ESCAN00041666 No changes here
 -            2010-03-24  ore     ESCAN00041766 No changes here
 -            2010-03-24  ore     ESCAN00041788 Compile error because integer conversion resulted in a change of sign
 -            2010-03-30  ore     ESCAN00041966 No changes here
 -            2010-04-22  ore     ESCAN00042422 No changes here
 -            2010-05-05  ore     ESCAN00041396 Reduce the duration of critical sections of the FrIf when the FrIfJobList
 *                                              execution goes out of sync 
 -            2010-05-05  ore     -             release of version 3.5.0 
 -  3.6.0     2010-05-19  ore     ESCAN00042989 The FlexRay Interface shall support ReconfigLPdu and DisableLPdu (Asr 4.0)
 -            2010-05-28  ore     ESCAN00043268 Convert VectorSpecific BSWMD parameter to the corresponding ASR 4.0 parameter
 -            2010-06-24  ore     ESCAN00043567 The FlexRay Interface shall support ReadCCConfig (Bugzilla 30176)
 -            2010-06-24  ore     ESCAN00043569 The FlexRay Interface shall support GetSyncFrameList (Asr 4.0)
 -            2010-07-07  ore     -             Fixed function descriptions so that they are correctly considered by Doxygen
 -            2010-07-22  ore     ESCAN00042986 No changes here 
 -            2010-07-29  ore     ESCAN00044336 Ensure consistency to C-sources for all FrIf header files
 -            2010-07-29  ore     ESCAN00044339 Add check for enabled features that are filtered by Organi
 -            2010-08-02  ore     -             Changed QAC justifications to be CDK compliant
 -            2010-08-03  ore     -             release of version 3.6.0 
 -  3.6.1     2010-09-22  ore     ESCAN00044465 Missing DetChecks for FRIF_E_NOT_INITIALIZED
 -            2010-09-22  ore     ESCAN00045547 Compile error occurs if FrIf_GetChannelStatus API is enabled
 -            2010-09-22  ore     -             release of version 3.6.1
 -  3.7.0     2010-11-02  ore     ESCAN00045650 Compiler warning:  condition is always false
 -            2010-11-02  ore     ESCAN00046417 No changes here 
 -            2010-11-02  ore     ESCAN00046257 Adapt AUTOSAR version check
 -            2010-11-05  ore     ESCAN00046607 Add DualChannelRedundancy support according to Bugzillla 42025.
 -            2010-11-16  ore     -             Added additional PcLint and QAC justifications
 -            2010-11-16  ore     ESCAN00046950 No changes here 
 -            2010-11-25  ore     ESCAN00046093 No changes here 
 -            2010-11-26  ore     ESCAN00047186 No changes here 
 -            2010-12-01  ore     ESCAN00047302 Adapt MainFunction for usage with IdentityManagerConfig
 -            2010-12-01  ore     ESCAN00047327 No changes here 
 -            2011-01-27  ore     ESCAN00048244 No changes here 
 -            2011-01-27  ore     -             release of version 3.7.0
 -  3.7.1     2011-02-23  ore     ESCAN00048836 No changes here 
 -            2011-03-16  ore     -             release of version 3.7.1
 -  3.7.2     2011-05-02  ore     ESCAN00049388 Start the JobListExecution in the same cylce in which the FrIfState was 
 *                                              set to 'FRIF_STATE_ONLINE'
 -            2011-05-02  ore     -             All component specific MISRA deviations are now justified in FrIf.c
 -            2011-05-02  ore     -             release of version 3.7.2
 -  3.7.3     2011-09-20  ore     ESCAN00051840 TxConfirmation is not called if the FrIf goes out of sync before the Tx FrIfJob 
 *                                              is executed
 -            2011-09-20  ore     -             release of version 3.7.3
 -  3.7.4     2011-10-25  ore     ESCAN00054422 Compiler error due to missing declaration of GetBit() in FrIf.c
 -            2011-10-25  ore     -             release of version 3.7.4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"
#if (STD_ON == FRIF_MEASURE_JLETASKTIMES) || (STD_ON == FRIF_CUSTOM_JLE_SCHEDULING)
# include "FrIf_Ext.h"
#endif

#if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK )
# include "v_ver.h"
#endif

#if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK ) || ( STD_ON  == FRIF_CRC_CHECK )
# include "EcuM_Cbk.h"
#endif

/*lint -e438 */ /* Suppress ID438 because the given ConfigPointer is not used in configuration variant pre-compile or link-time */
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if ( IF_ASRIFFR_VERSION != 0x0307u )
# error "The included header FrIf.h is incompatible with the FrIf.c version."
#endif
#if ( IF_ASRIFFR_RELEASE_VERSION != 0x04u )
# error "The included header FrIf.h is incompatible with the FrIf.c release version."
#endif

#if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK )
# if ( defined (ECUM_AR_MAJOR_VERSION) && defined (ECUM_AR_MINOR_VERSION) )
#  if   ((ECUM_AR_MAJOR_VERSION == 0x01u) && (ECUM_AR_MINOR_VERSION == 0x02u))
#  else
#   error "The included header EcuM_Cbk.h is incompatible with the FrIf.c version."
#  endif
# else
#  error "Version information of Module EcuM is missing. Compatibility cannot be verified!"
# endif
#endif

#if (STD_ON == FRIF_MEASURE_JLETASKTIMES) || (STD_ON == FRIF_CUSTOM_JLE_SCHEDULING)
# if defined (FRIF_EXT_VERSION)
#  if ( FRIF_EXT_VERSION != IF_ASRIFFR_VERSION )
#   error "The included header FrIf_Ext.h is incompatible with the FrIf.c version."
#  endif
# else
#  error "Version information of header FrIf_Ext.h is missing. Compatibility cannot be verified!"
# endif
# if defined (FRIF_EXT_RELEASE_VERSION)
#  if ( FRIF_EXT_RELEASE_VERSION != IF_ASRIFFR_RELEASE_VERSION )
#   error "The included header FrIf_Ext.h is incompatible with the FrIf.c release version."
#  endif
# else
#  error "Release version information of header FrIf_Ext.h is missing. Compatibility cannot be verified!"
# endif
#endif /* (STD_ON == FRIF_MEASURE_JLETASKTIMES) || (STD_ON == FRIF_CUSTOM_JLE_SCHEDULING) */

/*******************************************************************************************************************/
/*  VERSION CHECK AR3-F1155 (external modules)                                                                     */
/*******************************************************************************************************************/

#if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK ) || ( STD_ON  == FRIF_CRC_CHECK )
# if defined ( ECUM_VENDOR_ID )
#  if FRIF_VENDOR_ID == ECUM_VENDOR_ID
/* BSW004: AUTOSAR version information check has to match definition in header file */
#   if (  (ECUM_AR_MAJOR_VERSION != (0x01)) \
       || (ECUM_AR_MINOR_VERSION != (0x02)) )
#    error "AUTOSAR Specification Version 01.02.xx of ECU State Manager expected!"
#   endif
#  endif /* ( FRIF_VENDOR_ID == ECUM_VENDOR_ID ) */
# endif /* ( ECUM_VENDOR_ID ) */
#endif /* (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK ) || ( STD_ON  == FRIF_CRC_CHECK ) */

/*******************************************************************************************************************/
/*  ORGANI config check                                                                                            */
/*******************************************************************************************************************/


/* check whether feature 'FrIfGetSyncFrameListSupport' is disabled if the corresponding source was filtered by Organi */
# if ( FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON )
#  error "FrIf.c: FRIF_GETSYNCFRAMELISTSUPPORT shall not be enabled."
# endif

/* check whether feature 'FrIfReconfigLPduSupport' is disabled if the corresponding source was filtered by Organi */
# if ( FRIF_RECONFIGLPDUSUPPORT == STD_ON )
#  error "FrIf.c: FRIF_RECONFIGLPDUSUPPORT shall not be enabled."
# endif

/* check whether feature 'FrIfReadCCConfigSupport' is disabled if the corresponding source was filtered by Organi */
# if ( FRIF_READCCCONFIGSUPPORT == STD_ON )
#  error "FrIf.c: FRIF_READCCCONFIGSUPPORT shall not be enabled."
# endif

/* check whether feature 'FrIfCancelTransmitSupport' is disabled if the corresponding source was filtered by Organi */
# if ( FRIF_CANCELTRANSMITSUPPORT == STD_ON )
#  error "FrIf.c: FRIF_CANCELTRANSMITSUPPORT shall not be enabled."
# endif

/* check whether feature 'FrIfFreeOpCallbackSupport' is disabled if the corresponding source was filtered by Organi */
# if ( FRIF_FREEOPCALLBACKSUPPORT == STD_ON )
#  error "FrIf.c: FRIF_FREEOPCALLBACKSUPPORT shall not be enabled."
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
#define FRIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

#if (STD_OFF == FRIF_PDUDIRTYBYTE_USAGE)
FRIF_DECLARE_BITVECTOR_LOOKUP_TABLE_SET_BIT; /* PRQA S 3218 *//* MD_FrIf_3218 */
#endif

#define FRIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

#if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK )
/* FlexRay Interface Library Version */
/* The name of this const variable is defined via v_ver.h and depends on the version of the C file.    */
/* The value of the const variable is also defined externally and is used for consistency checks, too. */
# define FRIF_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

CONST(uint32, FRIF_CONST) IF_ASRIFFR_LIB_SYMBOL = IF_ASRIFFR_LIB_VERSION;

# define FRIF_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */
#endif

#define FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

#if defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
P2CONST(PduInfoType, AUTOMATIC, FRIF_DATA) FrIf_RedundantRxPduInfoPtr;
#endif
VAR(FrIf_StateDataType, FRIF_VAR_NOINIT) FrIf_Status;

#if (STD_ON == FRIF_MEASURE_JLETASKTIMES)
VAR(sint16_least, FRIF_VAR_NOINIT) FrIf_MaxTaskDelay;
VAR(sint16_least, FRIF_VAR_NOINIT) FrIf_MaxTaskOverlap;
#endif


#define FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if defined(FRIF_CUSTOM_JLE_SCHEDULING) && (STD_ON == FRIF_CUSTOM_JLE_SCHEDULING)

# define FRIF_ENABLE_JLE_TIMER(ClusterIdx) \
        FrIf_Enable_JLE_Timer(ClusterIdx)
# define FRIF_DISABLE_JLE_TIMER(ClusterIdx) \
        FrIf_Disable_JLE_Timer(ClusterIdx)
# define FRIF_SET_JLE_TIMER(ClusterIdx, FrCycle, FrMacrotickOffset, RepeatJLE)  \
        FrIf_Set_JLE_Timer(ClusterIdx, FrCycle, FrMacrotickOffset, RepeatJLE)
#endif

/* By default the Absolute Timer 0 is used to schedule the FrIf Job List */

#if (!defined FRIF_ENABLE_JLE_TIMER )
 /* PRQA S 3453 1 *//*  MD_MSR_19.7 */
# define FRIF_ENABLE_JLE_TIMER(ClusterIdx)   (void)Fr_EnableAbsoluteTimerIRQ(FrIf_TimerIndex2FrCtrlIndex(0), 0)
#endif

#if (!defined FRIF_DISABLE_JLE_TIMER )
 /* PRQA S 3453 1 *//*  MD_MSR_19.7 */
# define FRIF_DISABLE_JLE_TIMER(ClusterIdx)  (void)Fr_CancelAbsoluteTimer(FrIf_TimerIndex2FrCtrlIndex(0), 0)
#endif

#if (!defined FRIF_SET_JLE_TIMER )
 /* PRQA S 3453 5 *//*  MD_MSR_19.7 */
# define FRIF_SET_JLE_TIMER(ClusterIdx, FrCycle, FrMacrotickOffset,  RepeatJLE)  \
                                            Fr_SetAbsoluteTimer(FrIf_TimerIndex2FrCtrlIndex(0), \
                                                                0, \
                                                                FrCycle, \
                                                                FrMacrotickOffset)
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */  /*  MD_MSR_19.1 */

     STATIC FUNC(void, FRIF_CODE) FrIf_InitializeTransmission(void);
     STATIC FUNC(void, FRIF_CODE) FrIf_StopJobExecution(void);
     STATIC FUNC(void, FRIF_CODE) FrIf_StartJobExecution(void);
     STATIC FUNC(void, FRIF_CODE) FrIf_JobListOutOfSync(void);
     STATIC FUNC(void, FRIF_CODE) FrIf_ExecCurrentJob_0(void);
     STATIC FUNC(sint16_least, FRIF_CODE) FrIf_DiffTime(sint16_least MacroTickDiff, sint16_least CycleDiff);

#if (STD_ON == FRIF_DEV_ERROR_DETECT) && ((!defined FRIF_CONFIG_VARIANT) || (3u==FRIF_CONFIG_VARIANT))
     STATIC FUNC(boolean, FRIF_CODE) FrIf_IsValidPostBuildConfigData(FRIF_P2CONSTCFGROOT(FrIf_ConfigType) FrIf_ConfigPtr);
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FrIf_InitMemory
**********************************************************************************************************************/
/*! \brief      This function is used to initialize the global variables at startup.
 *  \param[in]  void
 *  \return     void
 *  \see        The function is called by Autosar EcuM
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_InitMemory(void)
{
  /* mark as not initialized */
#if defined (FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT)
  FrIf_Status.IsInitialized = (uint16) 0x0u;
#else
  FrIf_Status.pConfigData = (FrIf_PostBuildConfigType *) NULL_PTR;
#endif

#if (STD_ON == FRIF_MEASURE_JLETASKTIMES)
  FrIf_ResetMaxTaskDelay();
  FrIf_ResetMaxTaskOverlap();
#endif

#if defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
  FrIf_RedundantRxPduInfoPtr = FrIf_RedundantRxPduInfo;
#endif

  /* initialize RAM for transmission */
  FrIf_InitializeTransmission();
}

/**********************************************************************************************************************
  FrIf_Init
**********************************************************************************************************************/
/*! \brief      This function is used to initialize the FlexRay Interface, all FlexRay Drivers, 
 *              all FlexRay CCs, and all FlexRay Transceivers. The configuration data that 
 *              shall be used by the FlexRay Interface is passed as parameter.
 *  \param[in]  FrIf_ConfigPtr: Pointer to the configuration data structure of the FlexRay Interface.
 *  \return     void
 *  \see        The function is called by Autosar EcuM or NodeManager
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_Init(FRIF_P2CONSTCFGROOT(FrIf_ConfigType) FrIf_ConfigPtr)
{

#if defined (V_USE_DUMMY_STATEMENT) && (STD_ON == V_USE_DUMMY_STATEMENT) && (3u != FRIF_CONFIG_VARIANT)
  FrIf_ConfigPtr = FrIf_ConfigPtr; /* PRQA S 3199 */ /* MD_FrIf_3199 */
#endif

#if (!defined FRIF_CONFIG_VARIANT) || (3u == FRIF_CONFIG_VARIANT)
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnVoid(((const void*)NULL_PTR != FrIf_ConfigPtr), FRIF_INIT_SERVICE_ID, FRIF_E_INV_POINTER); 
  FrIf_CheckDetErrorReturnVoid(FrIf_IsValidPostBuildConfigData(FrIf_ConfigPtr), FRIF_INIT_SERVICE_ID, FRIF_E_INVALID_PB_CONFIG);   
#endif

#if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK )
/* Check the PBCfg Configuration. The detailed implementation may differ.       */
/* The check tests that major and minor version in the library are valid.       */
/* The patch version is only checked for a minimum patch version at build time. */
# if (3u == FRIF_CONFIG_VARIANT)
 if(((FrIf_ConfigPtr->FrIf_GeneratorVersion& 0x00FFFF00)!=
      (((uint32)IF_ASRIFFR_GENTOOL_GENY_MAJOR_VERSION<<16) | ((uint32)IF_ASRIFFR_GENTOOL_GENY_MINOR_VERSION<<8)))
#  if defined (IF_ASRIFFR_GENTOOL_GENY_PATCH_VERSION )
#   if (IF_ASRIFFR_GENTOOL_GENY_PATCH_VERSION != 0)
       || ((FrIf_ConfigPtr->FrIf_GeneratorVersion & (uint32) 0x000000FF) < IF_ASRIFFR_GENTOOL_GENY_PATCH_VERSION)
#   endif
#  endif
    )
  {
    /* Call the Vector specific EcuM Error callback and do NOT Call Det_ReportError. */
    EcuM_GeneratorCompatibilityError((uint16) FRIF_MODULE_ID, (uint8) 0u);
    return; /* Do not continue with the initialization of the component. Application may be influenced critically. */
  }
# endif
#endif /* if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK ) */

#if (STD_ON  == FRIF_CRC_CHECK) && (1u != FRIF_CONFIG_VARIANT)
  if(FrIf_ConfigPtr->FrIf_PrecompileCRC != FRIF_PRECOMPILE_CRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) FRIF_MODULE_ID, (uint8) 0u);
    return;
  }
#endif /* if (STD_ON  == FRIF_CRC_CHECK) && (1u != FRIF_CONFIG_VARIANT) */
#if (STD_ON  == FRIF_CRC_CHECK) && (3u == FRIF_CONFIG_VARIANT)
  if(FrIf_ConfigPtr->FrIf_LinkCRC != FrIf_LinktimeCRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) FRIF_MODULE_ID, (uint8) 0u);
    return;
  }
#endif /* if (STD_ON  == FRIF_CRC_CHECK) && (3u == FRIF_CONFIG_VARIANT) */

#if defined (FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT)
  FrIf_Status.IsInitialized = FRIF_IS_INITIALIZED_MAGIC_NUMBER;
#else
  FrIf_Status.pConfigData = (FRIF_P2CONSTCFGROOT(FrIf_PostBuildConfigType)) FrIf_ConfigPtr;
  FrIf_Status.pTxFrameDescriptors = FrIf_Status.pConfigData->pTxFrameDescriptors;
  FrIf_Status.pTxFrameLayoutElements = FrIf_Status.pConfigData->pTxFrameLayoutElements;
  FrIf_Status.pTxPduDescriptors = FrIf_Status.pConfigData->pTxPduDescriptors;
  FrIf_Status.pRxFrameDescriptors = FrIf_Status.pConfigData->pRxFrameDescriptors;
  FrIf_Status.pRxFrameLayoutElements = FrIf_Status.pConfigData->pRxFrameLayoutElements;
  FrIf_Status.pRxPduDescriptors = FrIf_Status.pConfigData->pRxPduDescriptors;
  FrIf_Status.InvalidTxHandle = FrIf_Status.pConfigData->InvalidTxHandle;
  FrIf_Status.InvalidRxHandle = FrIf_Status.pConfigData->InvalidRxHandle;
#endif
  FrIf_Status.State = FRIF_STATE_OFFLINE;

  /* initialize RAM for transmission */
  FrIf_InitializeTransmission();
  FrIf_Status.JobExecutionStarted = FALSE;

} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_Deinit
**********************************************************************************************************************/
/*! \brief      This function is marks the FrIf as not initialized and reinitializes the RAM 
 *              for transmission.
 *  \param[in]  void
 *  \return     void
 *  \see        The function is called by Autosar EcuM or NodeManager
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE)FrIf_Deinit(void)
{
  /* mark as not initialized */
#if defined (FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT)
  FrIf_Status.IsInitialized = (uint16) 0x0u;
#else
  FrIf_Status.pConfigData = (FrIf_PostBuildConfigType *) NULL_PTR;
#endif
  /* initialize RAM */
  FrIf_InitializeTransmission();
}

/**********************************************************************************************************************
  FrIf_SetState
**********************************************************************************************************************/
/*! \brief      This function sets the state machine for the FlexRay cluster with index FrIf_ClstIdx 
 *              into the state given by the parameter FrIf_State, i.e. ONLINE or OFFLINE
 *  \param[in]  FrIf_ClstIdx: Index of the FlexRay cluster. Only 0 is allowed. 
 *  \param[in]  FrIf_State:   The new state that shall entered. 
 *                            Only FRIF_GOTO_OFFLINE and FRIF_GOTO_ONLINE are allowed.
 *  \return     E_OK:     The requested state change was successful
 *              E_NOT_OK: The state request could not be executed because an error has been detected in development.
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_ClstIdx is void
 *              During its runtime this function temporarily disables all interrupts.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetState(FRIF_VCLST_ONLY, 
                                             FrIf_StateTransitionType  FrIf_State)
{
  Std_ReturnType ErrorState = E_OK;
  Fr_SyncStateType SynchStatus;


  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_SETSTATE_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCLST_IDX), FRIF_SETSTATE_SERVICE_ID, FRIF_E_INV_CLST_IDX, E_NOT_OK);
  
  if (FRIF_GOTO_ONLINE  == FrIf_State)
  {
    if(E_NOT_OK == Fr_GetSyncState(FRIF_VCLST_IDX, &SynchStatus))
    {
      SynchStatus = FR_ASYNC;
    }
    if(FR_SYNC == SynchStatus)
    {
      if(FRIF_STATE_ONLINE != FrIf_Status.State)
      {
        FrIf_StartJobExecution();
        FRIF_BEGIN_CRITICAL_SECTION_0();  /* PRQA S 3109 *//* MD_MSR_14.3 */
        if(FrIf_Status.JobExecutionStarted == TRUE)
        {
          FrIf_Status.State = FRIF_STATE_ONLINE;
        }
        else
        {
          ErrorState = E_NOT_OK;
        }
        FRIF_END_CRITICAL_SECTION_0(); /* PRQA S 3109 *//* MD_MSR_14.3 */
      }
    }
    else
    {
      ErrorState = E_NOT_OK;
    }
  }
  else /* this must be the offline state */
  {
    FrIf_StopJobExecution();
    FrIf_Status.State = FRIF_STATE_OFFLINE;
  }

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_GetState
**********************************************************************************************************************/
/*! \brief      Get the current state of the state machine for the FlexRay cluster
 *              with index FrIf_ClstxIdx. 
 *  \param[in]  FrIf_ClstIdx:  Index of the FlexRay cluster. Only 0 is allowed. 
 *  \param[out] FrIf_StatePtr: Pointer to a memory location the current state shall be stored at.
 *  \return     E_OK:     The state request was successful
 *              E_NOT_OK: The state request could not be executed because an error has been detected in development.
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_ClstIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetState(FRIF_VCLST_ONLY, 
                                              P2VAR(FrIf_StateType, AUTOMATIC, FRIF_APPL_DATA) FrIf_StatePtr)
{

#if defined (V_USE_DUMMY_STATEMENT) \
     && (STD_ON == V_USE_DUMMY_STATEMENT) \
     && (STD_OFF == FRIF_VCTRL_ENABLE_API_OPTIMIZATION)
  FRIF_VCLST_IDX = FRIF_VCLST_IDX; /* PRQA S 3199 */ /* MD_FrIf_3199 */
#endif

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GETSTATE_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCLST_IDX), FRIF_GETSTATE_SERVICE_ID, FRIF_E_INV_CLST_IDX, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_StatePtr), FRIF_GETSTATE_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);  

  *FrIf_StatePtr = ((FrIf_StateType)FrIf_Status.State);

  return E_OK;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_GetMacroticksDuration
**********************************************************************************************************************/
/*! \brief      This function retrieves the number of nanoseconds of one Macrotick
 *  \param[in]  FrIf_CtrlIdx:  Index of the FlexRay CC the Macrotick duration shall be retrieved for. 
 *                             Only 0 is allowed.
 *  \return     Number of nanoseconds of one Macrotick
 *              E_NOT_OK:      In case the development error FRIF_E_NOT_INITIALIZED or FRIF_E_INV_CTRL_IDX 
 *                             was thrown.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(uint16, FRIF_CODE) FrIf_GetMacroticksDuration(FRIF_VCTRL_ONLY)
{ /* PRQA S 3007 */ /*  MD_FrIf_3199 */
  uint16 Result;
#if defined (V_USE_DUMMY_STATEMENT) \
     && (STD_ON == V_USE_DUMMY_STATEMENT) \
     && (STD_OFF == FRIF_VCTRL_ENABLE_API_OPTIMIZATION)
  FRIF_VCTRL_IDX = FRIF_VCTRL_IDX; /* PRQA S 3199 */ /* MD_FrIf_3199 */
#endif

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GETMACROTICKSDURATION_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_GETMACROTICKSDURATION_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);

#if (3u != FRIF_CONFIG_VARIANT)
    Result = FrIf_MacroTicksLengthInNanoSeconds;
#else
    Result = FrIf_Status.pConfigData->MacroTicksLengthInNanoSeconds;
#endif

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (STD_ON == FRIF_VERSION_INFO_API)
/**********************************************************************************************************************
  FrIf_GetVersionInfo
**********************************************************************************************************************/
/*! \brief      AUTOSAR compliant API to retrieve its version from the FrIf component
 *  \param[out] VersionInfo:   Pointer to struct to the store version info in
 *  \see        The function is called by Autosar BSW components
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE)FrIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRIF_APPL_DATA) VersionInfo)
{

  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnVoid(((const void*)NULL_PTR != VersionInfo), FRIF_GETVERSIONINFO_SERVICE_ID, FRIF_E_INV_POINTER);  
  
  VersionInfo->vendorID = FRIF_VENDOR_ID;
  VersionInfo->moduleID = FRIF_MODULE_ID;
  VersionInfo->instanceID = (uint8) 0x00u;
  VersionInfo->sw_major_version = FRIF_SW_MAJOR_VERSION;
  VersionInfo->sw_minor_version = FRIF_SW_MINOR_VERSION;
  VersionInfo->sw_patch_version = FRIF_SW_PATCH_VERSION;

} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* (STD_ON == FRIF_VERSION_INFO_API) */

/**********************************************************************************************************************
  FrIf_MainFunction_0
**********************************************************************************************************************/
/*! \brief      This function is the main function for cluster 0. 
 *              It checks the state of the FlexRay CC and whether the job execution is still in synch.
 *  \see        The function is called by Autosar SchM or NodeManager
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_MainFunction_0(void)
{
  if(FRIF_IS_INITIALIZED())
  {
    Fr_SyncStateType SynchStatus;
    if(FRIF_STATE_ONLINE == ((FrIf_StateType) FrIf_Status.State))
    {
      if(E_OK == Fr_GetSyncState(0, &SynchStatus))
      {
        uint8 uint8CycleDiffTime;
        uint8 uint8Cycle;
        uint16 uint16MacroTicks;

        Std_ReturnType ErrorState = Fr_GetGlobalTime(0, &uint8Cycle, &uint16MacroTicks);
        uint8CycleDiffTime = (uint8)((((FrIf_Status.CurrentCycle) - uint8Cycle) + 0x40u) & 0x3Fu);

        /* if the internal cycle counter and the real cycle counter differ more than 2 cycles */
        /* (positive or negative) the JobList is assumed to be out of sync.                   */
        if (    (FR_ASYNC == SynchStatus) 
             || (E_OK     != ErrorState)
             || ((      2 <  uint8CycleDiffTime )
             &&  (     62 >  uint8CycleDiffTime )) )
        {
          FrIf_JobListOutOfSync();
        }
      }
    }
  }
#if defined (FRIF_IDENTITY_MANAGER_CONFIG) && (FRIF_IDENTITY_MANAGER_CONFIG == STD_OFF)
  else
  {
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    FrIf_CallDetReportError(FRIF_MAINFUNCTION_SERVICE_ID, FRIF_E_NOT_INITIALIZED);  
  }
#endif /* defined (FRIF_IDENTITY_MANAGER_CONFIG) && (FRIF_IDENTITY_MANAGER_CONFIG == STD_OFF) */
}

/**********************************************************************************************************************
  FrIf_JobListExec_0
**********************************************************************************************************************/
/*! \brief      This is the common call-back function for the activation of the Rx or Tx task (job execution) 
 *              of the FlexRay Interface. 
 *              Depending on the current FlexRay global time and the configured start times of the Rx and Tx tasks, 
 *              the FlexRay Interface will either execute the Rx or Tx task.
 *  \see        The function is called by the application from interrupt level or from task level
 *  \return     void
 *  \note       During its runtime this function temporarily disables all interrupts.
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_JobListExec_0(void)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnVoid(FRIF_IS_INITIALIZED(), FRIF_JOBLISTEXEC_SERVICE_ID, FRIF_E_NOT_INITIALIZED);  

  if(FrIf_IsOnline(0))
  {
    uint8 uint8Cycle;
    uint8 JLEIsOutOfSync = FALSE;
    uint16 uint16MacroTicks;
    Std_ReturnType ErrorState;

    FRIF_P2CONSTCFG(FrIf_TaskScheduleDataType) NextJobDataPtr;
    FRIF_P2CONSTCFG(FrIf_TaskScheduleDataType) JobDataPtr = &FrIf_GetJobData(FrIf_Status.CurrentJobNumber);

    FrIf_ExecCurrentJob_0();

#if (STD_ON == FRIF_JOB_CONCATENATION_ENABLE)
      NextJobDataPtr = &FrIf_GetJobData(FrIf_Status.CurrentJobNumber);
      if(JobDataPtr->StartTimeInMakroTicks == NextJobDataPtr->StartTimeInMakroTicks)
      {
        JobDataPtr = &FrIf_GetJobData(FrIf_Status.CurrentJobNumber);
        FrIf_ExecCurrentJob_0();
      }
#endif

      NextJobDataPtr = &FrIf_GetJobData(FrIf_Status.CurrentJobNumber);
      FRIF_BEGIN_CRITICAL_SECTION_1(); /* PRQA S 3109 *//* MD_MSR_14.3 */
      ErrorState = Fr_GetGlobalTime(0, &uint8Cycle, &uint16MacroTicks);
      if(E_OK == ErrorState)
      {
        sint16_least Delay = FrIf_DiffTime(
          (sint16_least)(NextJobDataPtr->StartTimeInMakroTicks) - (sint16_least)uint16MacroTicks, 
                                           (sint16_least) (FrIf_Status.CurrentCycle) - (sint16_least) uint8Cycle);
#if (STD_ON == FRIF_MEASURE_JLETASKTIMES)
        if((Delay < FrIf_MaxTaskOverlap) || (0 == FrIf_MaxTaskOverlap))
        {
          FrIf_MaxTaskOverlap = Delay;
        }
#endif
        if(Delay > FRIF_SYNC_THRESHOLD)
        {
          /* The next job has a start time that is far enough in the future
             so that it is possible to reliably start the FlexRay Timer. */
          ErrorState = FRIF_SET_JLE_TIMER(
            0, 
            FrIf_Status.CurrentCycle, 
            NextJobDataPtr->StartTimeInMakroTicks, 
            FALSE);
        }
        else
        {
          /* The start time of the next job has already elapsed */
          /* use current time + delta for timer  */
          uint16MacroTicks += FRIF_SYNC_THRESHOLD;
          if(uint16MacroTicks >= FrIf_GetNumberOfMacroTicksPerCycle())
          {
            uint16MacroTicks -= FrIf_GetNumberOfMacroTicksPerCycle();
            uint8Cycle = NEXT_CYCLE(uint8Cycle);
          }
          ErrorState = FRIF_SET_JLE_TIMER(
            0, 
            uint8Cycle, 
            uint16MacroTicks, 
            TRUE);
        }
        if ((    (uint16MacroTicks >= JobDataPtr->StartTimeProtectedRange) 
              && (uint16MacroTicks <= JobDataPtr->EndTimeProtectedRange)  ) 
              || (E_OK != ErrorState)
           )
        {
          JLEIsOutOfSync = TRUE;
        }
      }
      else
      {
        JLEIsOutOfSync = TRUE;
      } 
      FRIF_END_CRITICAL_SECTION_1(); /* PRQA S 3109 *//* MD_MSR_14.3 */

      if (TRUE == JLEIsOutOfSync)
      {
        FrIf_JobListOutOfSync();
      }
    }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if defined ( FRIF_API_AS_MACRO ) && (STD_OFF == FRIF_API_AS_MACRO)
/**********************************************************************************************************************
  FrIf_ControllerInit
**********************************************************************************************************************/
/*! \brief      This function initializes one FlexRay communication controller. 
 *  \param[in]  FrIf_CtrlIdx: Index of the FlexRay CC to be initialized. Only 0 is allowed. 
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_ControllerInit() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_ControllerInit() 
 *                        has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_ControllerInit(FRIF_VCTRL_ONLY)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_NOT_OK;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_CONTROLLERINIT_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_CONTROLLERINIT_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  

  ErrorState = Fr_ControllerInit(FRIF_VCTRL_IDX, 0, 0);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_StartCommunication
**********************************************************************************************************************/
/*! \brief      This function starts the communication, i.e. the controller will try to 
 *              synchronize with the FlexRay bus. This is an asynchronous function, 
 *              i.e. the function returns before the FlexRay CC has completely started up.
 *  \param[in]  FrIf_CtrlIdx: Index of the FlexRay CC to be initialized. Only 0 is allowed. 
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_StartCommunication() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_StartCommunication() 
 *                        has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_StartCommunication(FRIF_VCTRL_ONLY)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_NOT_OK;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_STARTCOMMUNICATION_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_STARTCOMMUNICATION_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  

  ErrorState = Fr_StartCommunication(FRIF_VCTRL_IDX);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_HaltCommunication
**********************************************************************************************************************/
/*! \brief      This function stops the communication of the communication controller 
 *              with index FrIf_CtrlIdx at the end of the current FlexRay cycle.
 *  \param[in]  FrIf_CtrlIdx:  The index of the CC that shall be set to state Halt. 
 *                             Only 0 is allowed as parameter.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_HaltCommunication() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_HaltCommunication() 
 *                        has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_HaltCommunication(FRIF_VCTRL_ONLY)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_NOT_OK;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_HALTCOMMUNICATION_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_HALTCOMMUNICATION_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  

  ErrorState = Fr_HaltCommunication(FRIF_VCTRL_IDX);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

# if defined (FRIF_ABORT_COMMUNICATION_DISABLE) && (STD_OFF == FRIF_ABORT_COMMUNICATION_DISABLE)
/**********************************************************************************************************************
  FrIf_AbortCommunication
**********************************************************************************************************************/
/*! \brief      This function stops the communication of the communication controller 
 *              with index FrIf_CtrlIdx immediately.
 *  \param[in]  FrIf_CtrlIdx:  The index of the CC that shall be set to state FRIF_STATE_OFFLINE. 
 *                             Only 0 is allowed as parameter.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_AbortCommunication() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_AbortCommunication() 
 *                        has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_AbortCommunication(FRIF_VCTRL_ONLY)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_ABORTCOMMUNICATION_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_ABORTCOMMUNICATION_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  

  ErrorState = Fr_AbortCommunication(FRIF_VCTRL_IDX);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
# endif/* (STD_OFF == FRIF_ABORT_COMMUNICATION_DISABLE) */

/**********************************************************************************************************************
  FrIf_SendWUP
**********************************************************************************************************************/
/*! \brief      This function triggers the sending of the wake-up pattern by the 
 *              communication controller with index FrIf_CtrlIdx. 
 *              When FrIf_SetWakeupChannel was called, the channel set by this function is used. 
 *              Otherwise the configured channel for wake-up is used.
 *  \param[in]  FrIf_CtrlIdx:  The index of the CC that shall be sent the wake-up pattern.
 *                             Only 0 is allowed as parameter.
 *  \return     E_OK:          The call of the FlexRay Driver API service Fr_SendWUP() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_SendWUP () 
 *                             has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SendWUP(FRIF_VCTRL_ONLY)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_SENDWUP_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_SENDWUP_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  

  ErrorState = Fr_SendWUP(FRIF_VCTRL_IDX);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

# if defined (FRIF_SET_WAKEUP_CHANNEL_DISABLE) && (STD_OFF == FRIF_SET_WAKEUP_CHANNEL_DISABLE)
/**********************************************************************************************************************
  FrIf_SetWakeupChannel
**********************************************************************************************************************/
/*! \brief      This function wraps the Fr_SetWakeupChannel function of the FlexRay Driver. 
 *              It can be used to change the channel that shall be used for wakeup.
 *  \param[in]  FrIf_CtrlIdx   The index of the FlexRay CC for which the wakeup channel
 *                             be changed.
 *  \param[in]  FrIf_ChnlIdx   The index of the FlexRay channel that shall be used for wakeup.
 *  \return     E_OK:          The call of the FlexRay Driver API service Fr_SetWakeupChannel() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_SetWakeupChannel () 
 *                             has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetWakeupChannel(FRIF_VCTRL_ONLY,  
                                                      Fr_ChannelType  FrIf_ChnlIdx)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_SETWAKEUPCHANNEL_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_SETWAKEUPCHANNEL_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  

  ErrorState = Fr_SetWakeupChannel(FRIF_VCTRL_IDX, FrIf_ChnlIdx);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
# endif /* (STD_OFF == FRIF_SET_WAKEUP_CHANNEL_DISABLE) */

/**********************************************************************************************************************
  FrIf_AllowColdstart
**********************************************************************************************************************/
/*! \brief      This function clears the coldstart inhibit flag in the given CC.
 *  \param[in]  FrIf_CtrlIdx:  The index of the CC for which the coldstart inhibit flag shall be cleared.
 *                             Only 0 is allowed as parameter.
 *  \return     E_OK:          The call of the FlexRay Driver API service Fr_AllowColdstart() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_AllowColdstart() 
 *                             has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_AllowColdstart(FRIF_VCTRL_ONLY)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_ALLOWCOLDSTART_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_ALLOWCOLDSTART_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  

  ErrorState = Fr_AllowColdstart(FRIF_VCTRL_IDX);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_GetPOCStatus
**********************************************************************************************************************/
/*! \brief      This function determines the POC-state of the FlexRay controller with 
 *              index FrIf_CtrlIdx.
 *  \param[in]  FrIf_CtrlIdx:  Index of the FlexRay CC the POC status  shall beretrieved for. 
 *                             Only 0 is allowed.
 *  \param[out] FrIf_POCStatusPtr:  Reference to a memory location where the current POC status state 
 *                                  will be stored.
 *  \return     E_OK:          The call of the FlexRay Driver API service Fr_GetPOCStatus() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_GetPOCStatus() 
 *                             has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetPOCStatus(FRIF_VCTRL_ONLY, 
                                                  P2VAR(Fr_POCStatusType, AUTOMATIC, FRIF_APPL_DATA) FrIf_POCStatusPtr)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GETPOCSTATUS_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_GETPOCSTATUS_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_POCStatusPtr), FRIF_GETPOCSTATUS_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);

  ErrorState = Fr_GetPOCStatus(FRIF_VCTRL_IDX, FrIf_POCStatusPtr);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */


/**********************************************************************************************************************
  FrIf_GetSyncState
**********************************************************************************************************************/
/*! \brief      This function determines the sychronisation state of the FlexRay controller with 
 *              index FrIf_CtrlIdx.
 *  \param[in]  FrIf_CtrlIdx:  Index of the FlexRay CC the POC status  shall beretrieved for. 
 *                             Only 0 is allowed.
 *  \param[out] FrIf_SyncStatePtr:  Reference to a memory location where the current synchronization state 
 *                                  will be stored.
 *  \return     E_OK:          The call of the FlexRay Driver API service Fr_GetSyncState() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_GetSyncState() 
 *                             has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetSyncState(FRIF_VCTRL_ONLY, 
                                                  P2VAR(Fr_SyncStateType, AUTOMATIC, FRIF_APPL_DATA) FrIf_SyncStatePtr)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GETSYNCSTATE_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_GETSYNCSTATE_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_SyncStatePtr), FRIF_GETSYNCSTATE_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);  

  ErrorState = Fr_GetSyncState(FRIF_VCTRL_IDX, FrIf_SyncStatePtr);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

# if defined ( FRIF_CHANNEL_STATUS_ENABLE ) && ( STD_ON == FRIF_CHANNEL_STATUS_ENABLE )
/**********************************************************************************************************************
  FrIf_GetChannelStatus
**********************************************************************************************************************/
/*! \brief      Wraps the FlexRay Driver API function Fr_GetChannelStatus() and gets the aggregated channel status 
 *              information.
 *  \param[in]  FrIf_CtrlIdx:  Index of the FlexRay CC the channel status shall be retrieved for. 
 *                             Only 0 is allowed.
 *  \param[out] FrIf_ChannelAStatusPtr: Address where the bitcoded channel A status information shall be stored.
 *  \param[out] FrIf_ChannelBStatusPtr: Address where the bitcoded channel B status information shall be stored.
 *  \return     E_OK          The call of the FlexRay Driver API service Fr_GetChannelStatus() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_GetChannelStatus() 
 *                             has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetChannelStatus(FRIF_VCTRL_ONLY, 
                                                      P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelAStatusPtr,
                                                      P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelBStatusPtr)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GET_CHANNEL_STATUS_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_GET_CHANNEL_STATUS_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_ChannelAStatusPtr), FRIF_GET_CHANNEL_STATUS_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_ChannelBStatusPtr), FRIF_GET_CHANNEL_STATUS_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);

  ErrorState = Fr_GetChannelStatus(FRIF_VCTRL_IDX, FrIf_ChannelAStatusPtr, FrIf_ChannelBStatusPtr);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
# endif
/* ( STD_ON == FRIF_CHANNEL_STATUS_ENABLE ) */

# if defined ( FRIF_CLOCK_CORRECTION_ENABLE ) && ( STD_ON == FRIF_CLOCK_CORRECTION_ENABLE )
/**********************************************************************************************************************
  FrIf_GetClockCorrection
**********************************************************************************************************************/
/*! \brief      Wraps the FlexRay Driver API function Fr_GetClockCorrection() and gets the current clock correction 
 *              values.
 *  \param[in]  FrIf_CtrlIdx:  Index of the FlexRay CC the clock correction values shall be retrieved for. 
 *                             Only 0 is allowed.
 *  \param[out] FrIf_RateCorrectionPtr:   Address where the current rate correction value 
 *                                        shall be stored.
 *  \param[out] FrIf_OffsetCorrectionPtr: Address where the current offset correction value 
 *                                        shall be stored.
 *  \return     E_OK:          The call of the FlexRay Driver API service Fr_GetClockCorrection() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_GetClockCorrection() 
 *                             has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetClockCorrection(FRIF_VCTRL_ONLY,
                                                  P2VAR(sint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_RateCorrectionPtr,
                                                  P2VAR(sint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_OffsetCorrectionPtr)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GET_CLOCK_CORRECTION_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_GET_CLOCK_CORRECTION_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_RateCorrectionPtr), FRIF_GET_CLOCK_CORRECTION_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_OffsetCorrectionPtr), FRIF_GET_CLOCK_CORRECTION_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);

  ErrorState = Fr_GetClockCorrection(FRIF_VCTRL_IDX, FrIf_RateCorrectionPtr, FrIf_OffsetCorrectionPtr);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
# endif
/* ( STD_ON == FRIF_CLOCK_CORRECTION_ENABLE ) */

# if ( STD_ON == FRIF_NMVECTORSUPPORT )
/**********************************************************************************************************************
  FrIf_GetNmVector
**********************************************************************************************************************/
/*! \brief      Wraps the FlexRay Driver API function Fr_GetClockCorrection() and gets the current clock correction 
 *              values.
 *  \param[in]  FrIf_CtrlIdx:  Index of the FlexRay CC the NM vector shall be retrieved for. 
 *                             Only 0 is allowed.
 *  \param[out] FrIf_NmVectorPtr:  Reference to a memory location where the NM vector shall be stored.
 *  \return     E_OK:          The call of the FlexRay Driver API service Fr_GetNmVector() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_GetNmVector() 
 *                             has returned E_NOT_OK, or an error has been detected in development
 *  \see        The function is called by Autosar FrNm
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetNmVector(FRIF_VCTRL_ONLY, 
                                                 P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_NmVectorPtr)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GETNMVECTOR_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_GETNMVECTOR_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);  
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_NmVectorPtr), FRIF_GETNMVECTOR_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);

  ErrorState = Fr_GetNmVector(FRIF_VCTRL_IDX, FrIf_NmVectorPtr);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
# endif /* ( STD_ON == FRIF_NMVECTORSUPPORT ) */



#endif /* (STD_ON == FRIF_API_AS_MACRO) */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FrIf_ExecCurrentJob_0
**********************************************************************************************************************/
/*! \brief      executes the current frif job according to CurrentJobNumber and sets the JLE timer for the next job 
 *              (increments CurrentJobNumber).
 *  \see        The function is called by the FrIf_JobListExec_0 function of the FrIf
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
STATIC FUNC(void, FRIF_CODE)FrIf_ExecCurrentJob_0(void)
{
  uint8 uint8Cycle;
  uint16 uint16MacroTicks;
  Std_ReturnType ErrorState = Fr_GetGlobalTime(0, &uint8Cycle, &uint16MacroTicks);

  if(E_OK == ErrorState)
  {
    FRIF_P2CONSTCFG(FrIf_TaskScheduleDataType) JobDataPtr = &FrIf_GetJobData(FrIf_Status.CurrentJobNumber);
    sint16_least Delay =FrIf_DiffTime(
                          (sint16_least)uint16MacroTicks - (sint16_least)(JobDataPtr->StartTimeInMakroTicks), 
                          (sint16_least) uint8Cycle - (sint16_least) (FrIf_Status.CurrentCycle));

#if (STD_ON == FRIF_MEASURE_JLETASKTIMES)
    if((Delay > FrIf_MaxTaskDelay) || (0 == FrIf_MaxTaskDelay))
    {
      FrIf_MaxTaskDelay = Delay;
    }
#endif

    if((0 <= Delay) && (JobDataPtr->MaxDelay > Delay))
    {
      if(0 == FrIf_Status.CurrentJobNumber)
      {
        /* hard synchronization of FrIf internal cycle number and FlexRay cycle. */
        FrIf_Status.CurrentCycle = uint8Cycle;
      }
      if((JobDataPtr->MinTxConfJobNo != FRIF_INVALID_JOB_NUMBER))
      {
        FrIf_TxConfTask_0();
      }
      if(FALSE != (JobDataPtr->JobConfig & FrIf_JobDataIsRxTask))
      {
        ErrorState = FrIf_RxTask_0();
      }
      else
      {
        ErrorState = FrIf_TxTask_0();
      }

      /* set timer for next job */
      FrIf_Status.CurrentJobNumber++;
      if(FrIf_GetNumberOfJobs() <= FrIf_Status.CurrentJobNumber)
      {
        FrIf_Status.CurrentJobNumber = 0;
        FrIf_Status.CurrentCycle = NEXT_CYCLE(FrIf_Status.CurrentCycle);
      }

      if(E_OK != ErrorState)
      {
        if(FALSE != (JobDataPtr->JobConfig & FrIf_JobDataIsRxTask))
        {
          FrIf_JobListOutOfSync();
        }
        else
        {
          FrIf_CallDetReportError(FRIF_EXEC_CURRENT_JOB_SERVICE_ID, FRIF_E_TXTASK_RET_E_NOT_OK);
        }
      }
    }
    else
    {
      FrIf_JobListOutOfSync();
    }
  }
  else
  {
    FrIf_JobListOutOfSync();
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_DiffTime
**********************************************************************************************************************/
/*! \brief      Calculate the difference between two FlexRay time values t1 and t2 taking into account the wrap 
 *              around of the FlexRay cycle numbers.
 *  \param[in]  MacroTickDiff: t1.MacroTick - t2.MacroTick
 *  \param[in]  CycleDiff:     t1.Cycle     - t2.Cycle
 *  \return     t1 - t2 in macroticks
 *              If t1 and t2 differ more than the duration of a cycle, the return value may not be the exact 
 *              difference.
 *  \see        The function is called by the FrIf_JobListExec_0 and FrIf_ExecCurrentJob_0 function of the FrIf
 *  \note       -
 *********************************************************************************************************************/
STATIC FUNC(sint16_least, FRIF_CODE) FrIf_DiffTime(sint16_least MacroTickDiff, sint16_least CycleDiff)
{
  /* cycles are modulo 64, treat e.g. -63 as +1  etc. */
  if(CycleDiff < -32)
  {
    CycleDiff += 64;
  }
  if(MacroTickDiff < 0)
  {
    CycleDiff -= 1;
    MacroTickDiff += (sint16_least) FrIf_GetNumberOfMacroTicksPerCycle();
  }
  if(CycleDiff > 0)
  {
    MacroTickDiff += (sint16_least) FrIf_GetNumberOfMacroTicksPerCycle();
  }
  else
  {
    if(CycleDiff < 0)
    {
      MacroTickDiff -= (sint16_least) FrIf_GetNumberOfMacroTicksPerCycle();
    }
  }
  return MacroTickDiff;
}

#if (STD_ON == FRIF_DEV_ERROR_DETECT) && ((!defined FRIF_CONFIG_VARIANT) || (3u==FRIF_CONFIG_VARIANT))
/**********************************************************************************************************************
  FrIf_IsValidPostBuildConfigData
**********************************************************************************************************************/
/*! \brief      Check if post build configuration data is valid
 *  \param[in]  FrIf_ConfigPtr the pointer to the post build configuration data
 *  \return     TRUE  if the post build configuration data is valid
 *              FALSE otherwise
 *  \see        The function is called by the FrIf_Init function of the FrIf
 *  \note       -
 *********************************************************************************************************************/
STATIC FUNC(boolean, FRIF_CODE) FrIf_IsValidPostBuildConfigData(
                                                  FRIF_P2CONSTCFGROOT(FrIf_ConfigType) FrIf_ConfigPtr)
{
  boolean Result = FALSE;
  FRIF_P2CONSTCFGROOT(FrIf_PostBuildConfigType) ConfigData = \
                                              (FRIF_P2CONSTCFGROOT(FrIf_PostBuildConfigType)) FrIf_ConfigPtr;
  if((ConfigData->NumberOfTxFrames <= FrIf_MaxNumberOfTxFrames)
        &&(ConfigData->NumberOfTxPDUs        <= FrIf_MaxNumberOfTxPDUs)
        &&(ConfigData->NumberOfTxFLEs        <= FrIf_MaxNumberOfTxFLEs)
        &&(ConfigData->MaxFrameLengthInBytes <= FrIf_FramebufferLengthInBytes)
        )
  {
    Result = TRUE;
  }
  return Result;
}
#endif /* (STD_ON == FRIF_DEV_ERROR_DETECT) && ((!defined FRIF_CONFIG_VARIANT) || (3u==FRIF_CONFIG_VARIANT)) */

/**********************************************************************************************************************
  FrIf_StartJobExecution
**********************************************************************************************************************/
/*! \brief      Start the job execution, i.e. set the FlexRay timer for the first task
 *  \param[in]  void
 *  \return     void
 *  \see        The function is called by the FrIf_SetState and FrIf_JobListOutOfSync function of the FrIf
 *  \note       During its runtime this function temporarily disables all interrupts.
 *********************************************************************************************************************/
STATIC FUNC(void, FRIF_CODE)FrIf_StartJobExecution(void)
{
  Std_ReturnType ErrorState = E_OK;
  uint8 i;
  uint8 uint8Cycle;
  uint16 uint16MacroTicks;

  /* initialize RAM for transmission */
  FrIf_InitializeTransmission();

  FRIF_BEGIN_CRITICAL_SECTION_1(); /* PRQA S 3109 *//* MD_MSR_14.3 */
  {
    ErrorState = Fr_GetGlobalTime(0, &uint8Cycle, &uint16MacroTicks);
    if(E_OK == ErrorState)
    {
      /* start the job execution with the next job in the current cycle */
      /* (if this is not possible use the second job of the next cycle) */
      FrIf_Status.CurrentJobNumber = 1;
      FrIf_Status.CurrentCycle = NEXT_CYCLE(uint8Cycle);

      for (i=0; i < FrIf_GetNumberOfJobs(); i++)
      {
        sint16_least Delay = FrIf_DiffTime( (sint16_least)(FrIf_GetJobData(i).StartTimeInMakroTicks) - (sint16_least)uint16MacroTicks, 0);
        
        if(Delay > FRIF_SYNC_THRESHOLD)
        {
          /* The next job has a start time that is far enough in the future so that it is possible to reliably start the FlexRay Timer. */
          FrIf_Status.CurrentJobNumber = i;
          FrIf_Status.CurrentCycle = uint8Cycle;
          break;
        }
      }

      FrIf_Status.JobExecutionStarted = TRUE;

#if defined (FRIF_ENABLE_PREPARE_LPDU) && ( STD_ON == FRIF_ENABLE_PREPARE_LPDU )
      if (FrIf_GetInvalidRxHandle() > 0)
      {
        /* call Fr_PrepareLPdu for the last Rx handle to flush the complete hardware FIFO */
        ErrorState |= Fr_PrepareLPdu(0, FrIf_GetInvalidRxHandle() - 1);
      }
#endif

      ErrorState |= FRIF_SET_JLE_TIMER(
        0, 
        FrIf_Status.CurrentCycle, 
        FrIf_GetJobData(FrIf_Status.CurrentJobNumber).StartTimeInMakroTicks, 
        FALSE);
      FRIF_ENABLE_JLE_TIMER(0);      
    }
  }
  FRIF_END_CRITICAL_SECTION_1(); /* PRQA S 3109 *//* MD_MSR_14.3 */

  if(E_NOT_OK == ErrorState)
  {
    FrIf_StopJobExecution();
  }
}

/**********************************************************************************************************************
  FrIf_StopJobExecution
**********************************************************************************************************************/
/*! \brief      Stop the job execution, i.e. cancel the FlexRay timer for the tasks
 *  \param[in]  void
 *  \return     void
 *  \see        The function is called by the FrIf_SetState, FrIf_HaltCommunication, FrIf_AbortCommunication and 
 *              FrIf_JobListOutOfSync function of the FrIf
 *  \note       -
 *********************************************************************************************************************/
STATIC FUNC(void, FRIF_CODE) FrIf_StopJobExecution(void)
{
  sint16_least Handle;

  FrIf_Status.JobExecutionStarted = FALSE;

  FRIF_DISABLE_JLE_TIMER(0);
  
  /* set the sent flags for all requested (but not yet transmitted) Tx Pdus. Otherwise no Tx confirmation will be given (see ESCAN00051840) */
  for (Handle = (sint16_least)(FrIf_GetInvalidTxHandle() - 1); Handle >= (sint16_least) 0; Handle--)
  {
    FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(Handle);
    sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
    uint16_least FrameLayoutElIndex = (uint16_least) (FrameDescriptorPtr->FirstFrameLayoutElementHandle + PduNumber);    
    FrIf_NumberOfPduType PduUsage = 0;

    for(; PduNumber >= (sint16_least) 0; PduNumber--)
    {
      const PduIdType FrTxPduId = FrIf_GetTxFrameLayoutElement(FrameLayoutElIndex).PduHandle;
    
#if (STD_ON == FRIF_PDUDIRTYBYTE_USAGE)
      boolean PduIsDirty = FrIf_TxPduDirtyBytes[FrTxPduId];
#else
      boolean PduIsDirty = (boolean) GetBit(FrIf_TxPduDirtyFlags, FrTxPduId);
#endif
      PduUsage <<= 1u;
      if(FALSE != PduIsDirty)
      {
        PduUsage |= 1u;        
      }
      FrameLayoutElIndex++;
    }
    
    if (0 != PduUsage)
    {
      FrIf_TxPduWasSentFlags[Handle] = PduUsage;
    }
  }

  FrIf_ConfirmPendingTransmissions();
}

/**********************************************************************************************************************
  FrIf_JobListOutOfSync
**********************************************************************************************************************/
/*! \brief      Stop the job execution, i.e. cancel the FlexRay timer for the tasks Write DEM error and restart the 
 *              job execution.
 *  \param[in]  void
 *  \return     void
 *  \see        The function is called by the FrIf_MainFunction_0, FrIf_JobListExec_0 and FrIf_ExecCurrentJob_0 
 *              function of the FrIf
 *  \note       -
 *********************************************************************************************************************/
STATIC FUNC(void, FRIF_CODE) FrIf_JobListOutOfSync(void)
{
  FrIf_StopJobExecution();
  DEM_JobListNotSynchronized();
  FrIf_StartJobExecution();
}

/**********************************************************************************************************************
  FrIf_InitializeTransmission
**********************************************************************************************************************/
/*! \brief      Initialize all RAM variables used by FrIf
 *  \param[in]  void
 *  \return     void
 *  \see        The function is called by the FrIf_InitMemory, FrIf_Init, FrIf_Deinit and FrIf_StartJobExecution
 *              function of the FrIf
 *  \note       -
 *********************************************************************************************************************/
STATIC FUNC(void, FRIF_CODE) FrIf_InitializeTransmission(void)
{
  sint16_least i;
#if (STD_ON == FRIF_PDUDIRTYBYTE_USAGE)
  for(i = (sint16_least) FrIf_MaxNumberOfTxPDUs - 1; i >= (sint16_least) 0; i--)
  {
    FrIf_TxPduDirtyBytes[i] = 0;
  }
#else
  for(i = (sint16_least) NumberOfBytesForBits(FrIf_MaxNumberOfTxPDUs) - 1; i >= (sint16_least) 0; i--)
  {
    FrIf_TxPduDirtyFlags[i] = 0;
  }
#endif
  for(i = (sint16_least) NumberOfBytesForBits(FrIf_MaxNumberOfTxFLEs) - 1; i >= (sint16_least) 0; i--)
  {
    FrIf_TxPduWasSentFlags[i] = 0;
  }
#if defined (FRIF_REQUEST_COUNTER_HANDLING_DISABLE) && (STD_OFF == FRIF_REQUEST_COUNTER_HANDLING_DISABLE)
# if defined (FRIF_NOREQUESTCOUNTERINITMEMORY) && (STD_OFF == FRIF_NOREQUESTCOUNTERINITMEMORY)
  for(i = (sint16_least) FrIf_MaxNumberOfTxRequestCounters - 1; i >= (sint16_least) 0; i--)
  {
    FrIf_TxPduTxRequestCounter[i] = 0;
  }
# endif /* (FRIF_NOREQUESTCOUNTERINITMEMORY) && (STD_OFF == FRIF_NOREQUESTCOUNTERINITMEMORY) */
#endif /* if defined (FRIF_REQUEST_COUNTER_HANDLING_DISABLE) && (STD_OFF == FRIF_REQUEST_COUNTER_HANDLING_DISABLE) */
}

#define FRIF_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 *//*  MD_MSR_19.1 */

/* module specific MISRA deviations:
 MD_FrIf_0310:
      Reason:     The downcast between pointer and integral type is required for efficient implementation.
      Risk:       There is no risk as the cast is a downcast.
      Prevention: Covered by code review.
 MD_FrIf_0505:
      Reason:     For QAC the FrameBuffer pointer can be NULL in the follwoing statement, if direct buffer access is enabled. 
                  But this is not true as the Fr component ensures that the function Fr_RequestBuffer_DBA returns only valid FrameBuffer pointer values.
      Risk:       There is no risk as the Fr component ensures that the function Fr_RequestBuffer_DBA returns only valid FrameBuffer pointer values.
      Prevention: Covered by code review. 
 MD_FrIf_0812:
      Reason:     The arrays in file FrIf_PBcfg.h and FrIf_Lcfg.h are declared as extern without size specification since their size depend on the configuration in GENy.
      Risk:       There is no risk because these arrays are only used by FrIf.
      Prevention: Covered by code review.
 MD_FrIf_1281:
      Reason:     The GENy CSyntax.dll currently cannot generate defines with "U" suffix (because that leads sometimes to problems - see ESCAN00041788)
      Risk:       There is no risk as such statements have no effect on the code.
      Prevention: Covered by code review.
 MD_FrIf_1913:
      Reason:     For better code readabilty and to be more independent from BRS.
      Risk:       There is no risk because this code is only needed for test purpose and is not delivered.
      Prevention: Covered by code review.
 MD_FrIf_3007:
      Reason:     Due to the Single Channel API optimization void has been omitted when defining a function with no parameters.
      Risk:       There is no risk as such statements have no effect on the code.
      Prevention: Covered by code review. 
 MD_FrIf_3199:
      Reason:     Dummy statement to avoid compiler warnings.
      Risk:       There is no risk as such statements have no effect on the code.
      Prevention: Covered by code review. 
 MD_FrIf_3355:
      Reason:     Due to the Single Channel API optimization void has been omitted when defining a function with no parameters.
      Risk:       There is no risk as such statements have no effect on the code.
      Prevention: Covered by code review. 
 MD_FrIf_3408:
      Reason:     The arrays in file FrIf_PBcfg.c and FrIf_Lcfg.c are defined without size specification since their size depend on the configuration in GENy.
      Risk:       There is no risk because these arrays are only used by FrIf.
      Prevention: Covered by code review. 
*/

/**********************************************************************************************************************
 *  END OF FILE: FrIf.c
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
