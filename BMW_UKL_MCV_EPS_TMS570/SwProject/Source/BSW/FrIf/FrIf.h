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
/*! \file         FrIf.h
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Main header file of the AUTOSAR FlexRay Interface, according to:
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
 -            2008-04-02  ber     ESCAN00023644 No changes here
 -            2008-04-03  ber     -             release of version 3.0.2
 -  3.0.3     2008-04-17  ber     ESCAN00026131 No changes here
 -            2008-04-18  ber     ESCAN00025799 No changes here
 -            2008-04-18  ber     -             release of version 3.0.3 
 -  3.0.4     2008-04-25  ore     ESCAN00026130 Use <BSW>_InitMemory
 -            2008-04-25  ore     ESCAN00026216 No changes here
 -            2008-04-25  ore     ESCAN00026256 Rename files and #include statements according coding styles
 -            2008-04-28  ore     ESCAN00026445 FrIf_Cbk.h is missing
 -            2008-04-28  ore     ESCAN00026447 FrIf_ConfigType is missing in implementation
 -            2008-04-28  ore     ESCAN00026449 FrIf_GetMacroticksDuration is missing
 -            2008-05-15  ore     ESCAN00026651 No changes here
 -            2008-05-19  ore     ESCAN00026973 No changes here
 -            2008-05-21  ore     -             release of version 3.0.4
 -  3.0.5     2008-06-09  ore     ESCAN00026972 No changes here
 -            2008-06-09  ore     ESCAN00026341 No changes here
 -            2008-07-08  ore     ESCAN00027356 No changes here
 -            2008-07-09  ore     ESCAN00028155 No changes here
 -            2008-07-11  ore     -             release of version 3.0.5
 -  3.0.6     2008-07-17  ore     ESCAN00027548 No changes here
 -            2008-07-17  ore     -             release of version 3.0.6
 -  3.0.7     2008-07-18  ore     ESCAN00027867 No changes here
 -            2008-07-24  ore     ESCAN00027210 No changes here
 -            2008-07-24  ore     -             removed VFRIF_FBL_MODE extension
 -            2008-07-24  ore     -             Added CrtlIdx Det-Check for FrIf_GetNmVector()
 -            2008-07-24  ore     -             Fixed ClstIdx Det-Check for FrIf_GetMacroticksPerCycle()
 -            2008-07-28  ore     ESCAN00028772 FrIf Single-Controller Optimization
 -            2008-08-07  ore     -             added compiler abstraction and memory mapping for FrIf_GetVersionInfo()
 -            2008-08-01  ore     ESCAN00027451 No changes here
 -            2008-08-07  ore     ESCAN00029068 No changes here
 -            2008-08-07  ore     ESCAN00029042 No changes here
 -            2008-08-13  ore     ESCAN00029218 No changes here
 -            2008-08-13  ore     ESCAN00029219 No changes here
 -            2008-08-13  ore     ESCAN00029184 No changes here
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No changes here
 -            2008-08-22  ore     -             moved FrIf_Cbk_WakeupByTransceiver declaration to FrIf_Cbk.h
 -            2008-08-22  ore     -             release of version 3.0.8
 -  3.0.9     2008-09-17  ore     -             release of version 3.0.9
 -  3.0.10    2008-10-01  ore     ESCAN00030038 No changes here
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 FrIf variable/function name conventions
 -            2008-10-01  ore     ESCAN00029696 No changes here
 -            2008-10-01  ore     ESCAN00029736 instanceID by <MSN>_GetVersionInfo
 -            2008-11-03  ore     ESCAN00031030 No changes here
 -            2008-11-03  ore     ESCAN00031026 FrIf header file structure differs from AUTOSAR specification 
 -            2008-11-04  ore     -             release of version 3.0.10
 -  3.1.0     2008-11-10  ore     ESCAN00030776 No changes here
 -            2008-11-10  ore     ESCAN00030577 No changes here
 -            2008-11-10  ore     ESCAN00030264 No changes here
 -            2008-11-10  ore     ESCAN00030764 No changes here
 -            2008-11-17  ore     ESCAN00031345 No changes here
 -            2008-11-17  ore     ESCAN00030264 No changes here
 -            2008-11-18  ore     -             added MISRA violation comments
 -            2008-11-24  ore     ESCAN00031026 FrIf header file structure differs from AUTOSAR specification 
 -            2008-11-24  ore     ESCAN00031360 Implement FrIf_GetChannelStatus() and FrIf_GetClockCorrection()
 -            2008-12-01  ore     ESCAN00031710 No changes here
 -            2008-12-08  ore     ESCAN00031843 Compile Error when Single Controller API optimization is enabled
 -            2008-12-19  ore     -             release of version 3.1.0
 -  3.2.0     2009-02-02  ore     ESCAN00032463 No changes here
 -            2009-02-10  ore     ESCAN00032944 No changes here
 -            2009-02-17  ore     ESCAN00033102 No changes here
 -            2009-02-18  ore     ESCAN00027867 No changes here
 -            2009-02-18  ore     ESCAN00033318 FrIf_Cbk.h should include Fr_GeneralTypes.h and the CrtlApiOptimization
 *                                              of FrIf_Cbk_WakeupByTransceiver should be removed
 -            2009-02-18  ore     ESCAN00033145 No changes here
 -            2009-02-18  ore     ESCAN00033220 No changes here
 -            2009-02-18  ore     ESCAN00032895 No changes here
 -            2009-02-18  ore     ESCAN00033309 Remove FrIf memory class macros to reduce the number of misra 
 *                                              violations.
 -            2009-02-18  ore     ESCAN00031278 Missing extern declaration of FrIf_Config in FrIf.h
 -            2009-02-25  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 No changes here
 -            2009-02-26  ore     ESCAN00032715 No changes here
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     ESCAN00033651 No changes here
 -            2009-03-06  ore     ESCAN00033665 No changes here
 -            2009-03-18  ore     ESCAN00033669 The FrIf main-, sub- and release-version shall be BCD coded
 -            2009-03-10  ore     ESCAN00033732 No changes here
 -            2009-03-23  ore     ESCAN00034040 No changes here
 -            2009-03-23  ore     -             release of version 3.2.0
 -  3.3.0     2009-04-06  ore     ESCAN00036436 Add PRQA misra justification comments for QAC
 -            2009-05-28  ore     ESCAN00035398 No changes here
 -            2009-05-28  ore     ESCAN00035048 No changes here
 -            2009-06-29  ore     ESCAN00035991 No changes here
 -            2009-07-06  ore     ESCAN00036053 Add FRIF_USE_FRTRCV_API precompileswitch to remove dependecy to v_cfg.h
 -            2009-07-20  ore     ESCAN00036397 No changes here
 -            2009-07-14  ore     ESCAN00035990 Pointer in FrIf_Init() is not pointer to the Flexray Init configuration 
 -            2009-07-14  ore     ESCAN00035399 The static header files of the FrIf don't include the Memmap.h file
 -            2009-07-15  ore     ESCAN00036426 No changes here
 -            2009-07-15  ore     ESCAN00036427 No changes here
 -            2009-07-15  ore     ESCAN00036429 Reduce codesize by implementing the FrIf wrapper APIs as macros
 -            2009-07-15  ore     ESCAN00036451 Unused FrIf APIs cannot be disabled via precompile switch
 -            2009-07-16  ore     ESCAN00036471 No changes here
 -            2009-07-17  ore     ESCAN00034459 Add compiler abstraction modifier <MSN>_PBCFG_ROOT
 -            2009-07-28  ore     ESCAN00036120 No changes here
 -            2009-07-31  ore     ESCAN00036776 No changes here
 -            2009-07-31  ore     -             release of version 3.3.0 
 -  3.4.0     2009-09-23  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-08-24  ore     ESCAN00036905 No changes here
 -            2009-08-24  ore     ESCAN00037257 No changes here
 -            2009-09-08  ore     ESCAN00035396 No changes here
 -            2009-09-08  ore     ESCAN00037643 No changes here
 -            2009-09-08  ore     ESCAN00037633 No changes here
 -            2009-09-21  ore     ESCAN00036013 No changes here
 -            2009-10-27  ore     ESCAN00038513 No changes here
 -            2009-11-02  ore     ESCAN00038914 No changes here
 -            2009-11-02  ore     ESCAN00038855 Support FrTrcv Vendor Id and vendor api infix in file and API names
 -            2009-11-03  ore     ESCAN00038930 The revision history of all source and header files shall contain all 
 *                                              implementation relevant ClearQuest issues of the FrIf.
 -            2009-11-17  ore     ESCAN00039212 Add FrIf_CancelTransmit API according to AUTOSAR 4.0 to reset the 
 *                                              request counter.
 -            2009-11-30  ore     ESCAN00039411 No changes here
 -            2009-12-07  ore     ESCAN00039607 No changes here
 -            2009-12-07  ore     ESCAN00039609 No changes here
 -            2009-12-07  ore     -             release of version 3.4.0 
 -  3.5.0     2010-02-01  ore     ESCAN00040508 No changes here
 -            2010-02-16  ore     ESCAN00040867 No changes here
 -            2010-02-18  ore     ESCAN00040951 No changes here
 -            2010-02-18  ore     ESCAN00040960 No changes here
 -            2010-02-22  ore     ESCAN00039809 No changes here
 -            2010-03-18  ore     ESCAN00041666 No changes here
 -            2010-03-24  ore     ESCAN00041766 No changes here
 -            2010-03-24  ore     ESCAN00041788 No changes here
 -            2010-03-30  ore     ESCAN00041966 No changes here
 -            2010-04-22  ore     ESCAN00042422 Add support for other FlexRay transceivers than Tja1080
 -            2010-05-05  ore     ESCAN00041396 No changes here 
 -            2010-05-05  ore     -             release of version 3.5.0 
 -  3.6.0     2010-05-19  ore     ESCAN00042989 The FlexRay Interface shall support ReconfigLPdu and DisableLPdu (Asr 4.0)
 -            2010-05-28  ore     ESCAN00043268 Convert VectorSpecific BSWMD parameter to the corresponding ASR 4.0 parameter
 -            2010-06-24  ore     ESCAN00043567 The FlexRay Interface shall support ReadCCConfig (Bugzilla 30176)
 -            2010-06-24  ore     ESCAN00043569 The FlexRay Interface shall support GetSyncFrameList (Asr 4.0)
 -            2010-07-07  ore     -             Fixed function descriptions so that they are correctly considered by Doxygen
 -            2010-07-22  ore     ESCAN00042986 No changes here 
 -            2010-07-29  ore     ESCAN00044336 Ensure consistency to C-sources for all FrIf header files
 -            2010-07-29  ore     ESCAN00044339 No changes here 
 -            2010-08-02  ore     -             Changed QAC justifications to be CDK compliant
 -            2010-08-03  ore     -             release of version 3.6.0 
 -  3.6.1     2010-09-22  ore     ESCAN00044465 No changes here 
 -            2010-09-22  ore     ESCAN00045547 Compile error occurs if FrIf_GetChannelStatus API is enabled
 -            2010-09-22  ore     -             release of version 3.6.1
 -  3.7.0     2010-11-02  ore     ESCAN00045650 No changes here 
 -            2010-11-02  ore     ESCAN00046417 No changes here 
 -            2010-11-02  ore     ESCAN00046257 No changes here 
 -            2010-11-05  ore     ESCAN00046607 No changes here 
 -            2010-11-16  ore     ESCAN00046950 No changes here 
 -            2010-11-25  ore     ESCAN00046093 No changes here 
 -            2010-11-26  ore     ESCAN00047186 No changes here 
 -            2010-12-01  ore     ESCAN00047302 No changes here 
 -            2010-12-01  ore     ESCAN00047327 No changes here 
 -            2011-01-27  ore     ESCAN00048244 'FrIf_Cbk_WakeupByTransceiver' is undefined if EcuM_Callout_Stubs.c 
 *                                              includes FrIf_Cbk.h
 -            2011-01-27  ore     -             release of version 3.7.0
 -  3.7.1     2011-02-23  ore     ESCAN00048836 No changes here 
 -            2011-03-16  ore     -             release of version 3.7.1
 -  3.7.2     2011-05-02  ore     ESCAN00049388 No changes here 
 -            2011-05-02  ore     -             release of version 3.7.2
 -  3.7.3     2011-09-20  ore     ESCAN00051840 No changes here 
 -            2011-09-20  ore     -             release of version 3.7.3
 -  3.7.4     2011-10-25  ore     ESCAN00054422 No changes here 
 -            2011-10-25  ore     -             release of version 3.7.4
 *********************************************************************************************************************/

#if (!defined  FRIF_H_)
# define FRIF_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "FrIf_Types.h"    /* Includes ComStack_Types.h (They include standard types and v_cfg.h in turn) and FrIf_Cfg.h */
# include "Fr_GeneralTypes.h"

# if defined ( FRIF_API_AS_MACRO ) && (STD_ON == FRIF_API_AS_MACRO)
#  include "Fr.h"
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* AUTOSAR FlexRay Interface version */
# define IF_ASRIFFR_VERSION            0x0307u /*!< BCD coded FrIf version number */
# define IF_ASRIFFR_RELEASE_VERSION    0x04u   /*!< BCD coded FrIf release version number */

/* Implemented AUTOSAR Specification Version */
# define FRIF_AR_VERSION               0x0300u /*!< BCD coded AUTOSAR specification version number */
# define FRIF_AR_RELEASE_VERSION       0x00u   /*!< BCD coded AUTOSAR specification release version number */

# if (!defined VBCD2DEZ8 )
/* PRQA S 3453 1 *//*  MD_MSR_19.7 */
#  define VBCD2DEZ8(Bcd) (((Bcd)&0xFu)+((((Bcd)>>4)&0xFu)*10))  /*!< Converts the BCD-coded integer argument Bcd to decimal. */

# endif
  /* VBCD2DEZ8 */
# define FRIF_AR_MAJOR_VERSION    (VBCD2DEZ8(FRIF_AR_VERSION >> 8))
# define FRIF_AR_MINOR_VERSION    (VBCD2DEZ8(FRIF_AR_VERSION))
# define FRIF_AR_PATCH_VERSION    (VBCD2DEZ8(FRIF_AR_RELEASE_VERSION))
# define FRIF_SW_MAJOR_VERSION    ((IF_ASRIFFR_VERSION >> 8u) & 0x00FFu)
# define FRIF_SW_MINOR_VERSION    (IF_ASRIFFR_VERSION & 0x00FFu)
# define FRIF_SW_PATCH_VERSION    (IF_ASRIFFR_RELEASE_VERSION)

/* Development errors */
/* Definition of the Mdoule and Vendor IDs */
# define FRIF_VENDOR_ID                         30 /*!< Vendor ID for Vctr Informatik */
# define FRIF_MODULE_ID                         61 /*!< FlexRay Interface ID */

/* Definition of the API ID */
# define FRIF_RECONFIG_LPDU_SERVICE_ID                     (uint8)0x00u /*!< ASR4.0 FrIf_ReconfigLPdu() service ID */
# define FRIF_GETVERSIONINFO_SERVICE_ID                    (uint8)0x01u /*!< ASR3.0 FrIf_GetVersionInfo() service ID */
# define FRIF_INIT_SERVICE_ID                              (uint8)0x02u /*!< ASR3.0 FrIf_Init() service ID */
# define FRIF_CONTROLLERINIT_SERVICE_ID                    (uint8)0x03u /*!< ASR3.0 FrIf_ControllerInit() service ID */
# define FRIF_STARTCOMMUNICATION_SERVICE_ID                (uint8)0x04u /*!< ASR3.0 FrIf_StartCommunication() service ID */
# define FRIF_HALTCOMMUNICATION_SERVICE_ID                 (uint8)0x05u /*!< ASR3.0 FrIf_HaltCommunication() service ID */
# define FRIF_ABORTCOMMUNICATION_SERVICE_ID                (uint8)0x06u /*!< ASR3.0 FrIf_AbortCommunication() service ID */
# define FRIF_GETSTATE_SERVICE_ID                          (uint8)0x07u /*!< ASR3.0 FrIf_GetState() service ID */
# define FRIF_SETSTATE_SERVICE_ID                          (uint8)0x08u /*!< ASR3.0 FrIf_SetState() service ID */
# define FRIF_SETWAKEUPCHANNEL_SERVICE_ID                  (uint8)0x09u /*!< ASR3.0 FrIf_SetWakeupChannel() service ID */
# define FRIF_SENDWUP_SERVICE_ID                           (uint8)0x0Au /*!< ASR3.0 FrIf_SendWup() service ID */
# define FRIF_GETSYNCSTATE_SERVICE_ID                      (uint8)0x0Bu /*!< ASR3.0 FrIf_GetSyncState() service ID */
# define FRIF_SETEXTSYNC_SERVICE_ID                        (uint8)0x0Cu /*!< ASR3.0 FrIf_SetExtSync() service ID */
# define FRIF_GETPOCSTATUS_SERVICE_ID                      (uint8)0x0Du /*!< ASR3.0 FrIf_GetPOCStatus() service ID */
# define FRIF_GETGLOBALTIME_SERVICE_ID                     (uint8)0x0Eu /*!< ASR3.0 FrIf_GetGlobalTime() service ID */
# define FRIF_GETNMVECTOR_SERVICE_ID                       (uint8)0x0Fu /*!< ASR3.0 FrIf_GetNmVector() service ID */
# define FRIF_ALLOWCOLDSTART_SERVICE_ID                    (uint8)0x10u /*!< ASR3.0 FrIf_AllowColdStart() service ID */
# define FRIF_GETMACROTICKSPERCYCLE_SERVICE_ID             (uint8)0x11u /*!< ASR3.0 FrIf_GetMacroticksPerCycle() service ID */
# define FRIF_TRANSMIT_SERVICE_ID                          (uint8)0x12u /*!< ASR3.0 FrIf_Transmit() service ID */
# define FRIF_SETTRANSCEIVERMODE_SERVICE_ID                (uint8)0x13u /*!< ASR3.0 FrIf_SetTransceiverMode() service ID */
# define FRIF_GETTRANSCEIVERMODE_SERVICE_ID                (uint8)0x14u /*!< ASR3.0 FrIf_GetTransceiverMode() service ID */
# define FRIF_GETTRANSCEIVERWUREASON_SERVICE_ID            (uint8)0x15u /*!< ASR3.0 FrIf_GetTransceiverWUReason() service ID */
# define FRIF_ENABLETRANSCEIVERWAKEUP_SERVICE_ID           (uint8)0x16u /*!< ASR3.0 FrIf_EnableTransceiverWakeup() service ID */
# define FRIF_DISABLETRANSCEIVERWAKEUP_SERVICE_ID          (uint8)0x17u /*!< ASR3.0 FrIf_DisableTransceiverWakeup() service ID */
# define FRIF_CLEARTRANSCEIVERWAKEUP_SERVICE_ID            (uint8)0x18u /*!< ASR3.0 FrIf_ClearTransceiverWakeup() service ID */
# define FRIF_SETABSOLUTETIMER_SERVICE_ID                  (uint8)0x19u /*!< ASR3.0 FrIf_SetAbsoluteTimer() service ID */
# define FRIF_SETRELATIVETIMER_SERVICE_ID                  (uint8)0x1Au /*!< ASR3.0 FrIf_SetRelativeTimer() service ID */
# define FRIF_CANCELABSOLUTETIMER_SERVICE_ID               (uint8)0x1Bu /*!< ASR3.0 FrIf_CancelAbsoluteTimer() service ID */
# define FRIF_CANCELRELATIVETIMER_SERVICE_ID               (uint8)0x1Cu /*!< ASR3.0 FrIf_CancelRelativeTimer() service ID */
# define FRIF_ENABLEABSOLUTETIMERIRQ_SERVICE_ID            (uint8)0x1Du /*!< ASR3.0 FrIf_EnableAbsoluteTimer() service ID */
# define FRIF_ENABLERELATIVETIMERIRQ_SERVICE_ID            (uint8)0x1Eu /*!< ASR3.0 FrIf_EnableRelativeTimer() service ID */
# define FRIF_GETABSOLUTETIMERIRQSTATUS_SERVICE_ID         (uint8)0x1Fu /*!< ASR3.0 FrIf_GetAbsoluteTimerIRQStatus() service ID */
# define FRIF_GETRELATIVETIMERIRQSTATUS_SERVICE_ID         (uint8)0x20u /*!< ASR3.0 FrIf_GetRelativeTimerIRQStatus() service ID */
# define FRIF_ACKABSOLUTETIMERIRQ_SERVICE_ID               (uint8)0x21u /*!< ASR3.0 FrIf_AckAbsoluteTimerIRQ() service ID */
# define FRIF_ACKRELATIVETIMERIRQ_SERVICE_ID               (uint8)0x22u /*!< ASR3.0 FrIf_AckRelativeTimerIRQ() service ID */
# define FRIF_DISABLEABSOLUTETIMERIRQ_SERVICE_ID           (uint8)0x23u /*!< ASR3.0 FrIf_DisableAbsoluteTimerIRQ() service ID */
# define FRIF_DISABLERELATIVETIMERIRQ_SERVICE_ID           (uint8)0x24u /*!< ASR3.0 FrIf_DisableRelativeTimerIRQ() service ID */
# define FRIF_CBK_WAKEUPBYTRANSCEIVER_SERVICE_ID           (uint8)0x25u /*!< FrIf_Cbk_WakeupByTransceiver() service ID - vector specific service id, because ASR3.0 and ASR4.0 ids overlap */
# define FRIF_GET_CHANNEL_STATUS_SERVICE_ID                (uint8)0x26u /*!< ASR4.0 FrIf_GetChannelStatus() service ID */
# define FRIF_MAINFUNCTION_SERVICE_ID                      (uint8)0x27u /*!< ASR3.0 FrIf_Mainfunction() service ID */
# define FRIF_DISABLE_LPDU_SERVICE_ID                      (uint8)0x28u /*!< ASR4.0 FrIf_DisableLPdu() service ID */
# define FRIF_GET_CLOCK_CORRECTION_SERVICE_ID              (uint8)0x29u /*!< ASR4.0 FrIf_GetClockCorrection() service ID */
# define FRIF_GETSYNCFRAMELISTSUPPORT_SERVICE_ID           (uint8)0x2Au /*!< ASR4.0 FrIf_GetSyncFrameList() service ID */
# define FRIF_CONVERTMACROTICKSTONANOSEC_SERVICE_ID        (uint8)0x2Cu /*!< FrIf_ConvertMacroticksToNanosec() service ID - vector specific service id, because ASR3.0 and ASR4.0 ids overlap */
# define FRIF_CONVERTNANOSECTOMACROTICKS_SERVICE_ID        (uint8)0x2Du /*!< FrIf_ConvertNanosecToMacroticks() service ID - vector specific service id, because ASR3.0 and ASR4.0 ids overlap */
# define FRIF_GETMACROTICKSDURATION_SERVICE_ID             (uint8)0x31u /*!< ASR3.0 FrIf_GetMacrotickDuration() service ID */
# define FRIF_JOBLISTEXEC_SERVICE_ID                       (uint8)0x32u /*!< ASR3.0 FrIf_JobListExec_0() service ID */
# define FRIF_CANCEL_TRANSMIT_SERVICE_ID                   (uint8)0x33u /*!< ASR4.0 FrIf_CancelTransmit() service ID */
# define FRIF_READCCCONFIG_SERVICE_ID                      (uint8)0x34u /*!< ASR4.0 FrIf_ReadCCConfig() service ID */

/* service ids for internal FrIf functions */
# define FRIF_EXEC_CURRENT_JOB_SERVICE_ID                  (uint8)0x40u /*!< internal FrIf_Exec_CurrentJob() service ID */
# define FRIF_TRIGGER_TRANSMIT_FCTS_SERVICE_ID             (uint8)0x41u /*!< internal FrIf_TriggerTransmitFcts() service ID */
# define FRIF_TX_CONFIRMATION_FCTS_SERVICE_ID              (uint8)0x42u /*!< internal FrIf_TxConfirmationFcts() service ID */
# define FRIF_RX_INDICATION_FCTS_SERVICE_ID                (uint8)0x43u /*!< internal FrIf_RxIndicationsFcts() service ID */

# define FRIF_CTRL_IDX_MAX_SUPPORTED 0 /*!< Maximum number-1 of FlexRay CCs that the FlexRay Interface supports */
# define FRIF_CLST_IDX_MAX_SUPPORTED 0 /*!< Maximum number-1 of FlexRay Clusters that the FlexRay Interface supports */

/* Single Controller API optimization */
# if ( STD_ON == FRIF_CTRL_ENABLE_API_OPTIMIZATION)
#  define FRIF_VCTRL_ENABLE_API_OPTIMIZATION   STD_ON

/* PRQA S 3460 1 *//*  MD_MSR_19.4 */
#  define FRIF_VCTRL_ONLY     void
#  define FRIF_VCTRL_FIRST
#  define FRIF_VCTRL_IDX      0u

/* PRQA S 3460 1 *//*  MD_MSR_19.4 */
#  define FRIF_VCLST_ONLY     void
#  define FRIF_VCLST_FIRST
#  define FRIF_VCLST_IDX      0u
# else
#  define FRIF_VCTRL_ENABLE_API_OPTIMIZATION   STD_OFF

#  define FRIF_VCTRL_ONLY     uint8 FrIf_CtrlIdx
#  define FRIF_VCTRL_FIRST    uint8 FrIf_CtrlIdx,
#  define FRIF_VCTRL_IDX      FrIf_CtrlIdx

#  define FRIF_VCLST_ONLY     uint8 FrIf_ClstIdx
#  define FRIF_VCLST_FIRST    uint8 FrIf_ClstIdx,
#  define FRIF_VCLST_IDX      FrIf_ClstIdx
# endif
  /* ( STD_ON == FRIF_CTRL_ENABLE_API_OPTIMIZATION) */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
# if defined (FRIF_TYPES_VERSION)
#  if ( FRIF_TYPES_VERSION != IF_ASRIFFR_VERSION )
#   error "The included header FrIf_Types.h is incompatible with the FrIf.c version."
#  endif
# else
#  error "Version information of header FrIf_Types.h is missing. Compatibility cannot be verified!"
# endif
# if defined (FRIF_TYPES_RELEASE_VERSION)
#  if ( FRIF_TYPES_RELEASE_VERSION != IF_ASRIFFR_RELEASE_VERSION )
#   error "The included header FrIf_Types.h is incompatible with the FrIf.c release version."
#  endif
# else
#  error "Release version information of header FrIf_Types.h is missing. Compatibility cannot be verified!"
# endif

/*******************************************************************************************************************/
/*  VERSION CHECK AR3-F1155 (external modules)                                                                     */
/*******************************************************************************************************************/

#if defined ( COMSTACKTYPE_VENDOR_ID )
# if FRIF_VENDOR_ID == COMSTACKTYPE_VENDOR_ID
/* BSW004: AUTOSAR version information check has to match definition in header file */
#  if (  (COMSTACKTYPE_AR_MAJOR_VERSION != (0x02)) \
      || (COMSTACKTYPE_AR_MINOR_VERSION != (0x02)) )
#   error "AUTOSAR Specification Version 02.02.xx of Communication Stack Types expected!"
#  endif
# endif /* ( FRIF_VENDOR_ID == COMSTACKTYPE_VENDOR_ID ) */
#endif /* ( COMSTACKTYPE_VENDOR_ID ) */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES (FrIf)
 **********************************************************************************************************************/

# if defined(FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT)

#  define FRIF_START_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

extern CONST(FrIf_ConfigType, FRIF_CONST) FrIf_Config;

#  define FRIF_STOP_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

# else

#  define FRIF_START_SEC_PBCFG_ROOT
#  include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

extern CONST(FrIf_ConfigType, FRIF_PBCFG_ROOT) FrIf_Config;

#  define FRIF_STOP_SEC_PBCFG_ROOT
#  include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 *//*  MD_MSR_19.1 */

/**********************************************************************************************************************
  FrIf_InitMemory
**********************************************************************************************************************/
/*! \brief      This function is used to initialize the global variables at startup.
 *  \param[in]  void
 *  \return     void
 *  \see        The function is called by Autosar EcuM
 *  \note       -
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_InitMemory(void);

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
     extern FUNC(void, FRIF_CODE) FrIf_Init(FRIF_P2CONSTCFGROOT(FrIf_ConfigType) FrIf_ConfigPtr);

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
     extern FUNC(void, FRIF_CODE) FrIf_Deinit(void);

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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetState(FRIF_VCLST_FIRST
                                                    FrIf_StateTransitionType  FrIf_State);

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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetState(FRIF_VCLST_FIRST
                                                    P2VAR(FrIf_StateType, AUTOMATIC, FRIF_APPL_DATA) FrIf_StatePtr);

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
     extern FUNC(uint16, FRIF_CODE) FrIf_GetMacroticksDuration(FRIF_VCTRL_ONLY);

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
     extern FUNC(void, FRIF_CODE) FrIf_JobListExec_0(void);

/**********************************************************************************************************************
  FrIf_MainFunction_0
**********************************************************************************************************************/
/*! \brief      This function is the main function for cluster 0. 
 *              It checks the state of the FlexRay CC and whether the job execution is still in synch.
 *  \see        The function is called by Autosar SchM or NodeManager
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
    extern FUNC(void, FRIF_CODE) FrIf_MainFunction_0(void);


# if ( STD_ON == FRIF_VERSION_INFO_API )
/**********************************************************************************************************************
  FrIf_GetVersionInfo
**********************************************************************************************************************/
/*! \brief      AUTOSAR compliant API to retrieve its version from the FrIf component
 *  \param[out] VersionInfo:   Pointer to struct to the store version info in
 *  \see        The function is called by Autosar BSW components
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRIF_APPL_DATA) VersionInfo);
# endif /* ( STD_ON == FRIF_VERSION_INFO_API ) */

/**********************************************************************************************************************
  FrIf_Transmit
**********************************************************************************************************************/
/*! \brief      This function transmits a PDU. If the PDU is configured for Decoupled Transmission, the PDU is marked 
 *              as dirty. When a frame that contains the PDU shall be transmitted, the <UL>_TriggerTransmit call-back 
 *              function of the upper-layer component is called in order to get the PDU content.
 *              If the PDU is configured for Immediate Transmission the PDU content is directly given to the FlexRay 
 *              Driver.
 *  \param[in]  FrTxPduId:  ID of the FlexRay PDU to be transmitted.
 *  \param[in]  PduInfoPtr: Pointer to a structure with FlexRay PDU related data
 *  \return     E_OK      Immediate transmission request has been accepted.
 *              E_PENDING Decoupled transmission request has been accepted.
 *              E_NOT_OK  Transmission request has been rejected.
 *  \see        The function is called by Autosar PduR, FrNm or FrTp component
 *  \note       During its runtime this function temporarily disables all interrupts.
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_Transmit(PduIdType           FrTxPduId,
                                                     FRIF_P2CONSTAPPLDATA(PduInfoType) PduInfoPtr);

/**********************************************************************************************************************
  FrIf_GetMacroticksPerCycle
**********************************************************************************************************************/
/*! \brief      This function returns the number of macro ticks per FlexRay cycle.
 *  \param[in]  FrIf_ClstIdx:      Index of the FlexRay cluster for which the macro ticks per cycle shall be retrieved.
 *  \return     The number of macro ticks or 0 if the FlexRay Interface is not initialized.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_ClstIdx is void
 *********************************************************************************************************************/
     extern FUNC(uint16, FRIF_CODE) FrIf_GetMacroticksPerCycle(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_ConvertNanosecToMacroticks
**********************************************************************************************************************/
/*! \brief      This function converts a time given in nanoseconds to the equivalent number of macro ticks.
 *  \param[in]  FrIf_ClstIdx:      Index of the FlexRay cluster for which the conversion shall be performed. 
 *  \param[out] FrIf_MacrotickPtr: Reference to memory location where the converted value shall be stored at.
 *  \param[in]  FrIf_Nanosec:      Time in nanoseconds to be converted.
 *  \return     void
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_ClstIdx is void
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_ConvertNanosecToMacroticks(FRIF_VCLST_FIRST
                                                            P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_MacroTickPtr, 
                                                            uint32             FrIf_Nanosec);

/**********************************************************************************************************************
  FrIf_ConvertMacroticksToNanosec
**********************************************************************************************************************/
/*! \brief      This function converts a number of macro ticks to the equivalent time in nanoseconds.
 *  \param[in]  FrIf_ClstIdx:      Index of the FlexRay cluster for which the conversion shall be performed. 
 *  \param[out] FrIf_MacrotickPtr: Reference to memory location where the converted value shall be stored at.
 *  \param[in]  FrIf_Macrotick:    Number of macroticks to be converted.
 *  \return     void
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_ClstIdx is void
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_ConvertMacroticksToNanosec(FRIF_VCLST_FIRST
                                                            P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_NanosecPtr,
                                                            uint32             FrIf_MacroTick );

# if defined ( FRIF_API_AS_MACRO ) && (STD_OFF == FRIF_API_AS_MACRO)
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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_ControllerInit(FRIF_VCTRL_ONLY);

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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_StartCommunication(FRIF_VCTRL_ONLY);

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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_HaltCommunication(FRIF_VCTRL_ONLY);

#  if defined (FRIF_ABORT_COMMUNICATION_DISABLE) && (STD_OFF == FRIF_ABORT_COMMUNICATION_DISABLE)
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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_AbortCommunication(FRIF_VCTRL_ONLY);
#  endif

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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SendWUP(FRIF_VCTRL_ONLY);

#  if defined (FRIF_SET_WAKEUP_CHANNEL_DISABLE) && (STD_OFF == FRIF_SET_WAKEUP_CHANNEL_DISABLE)
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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetWakeupChannel(FRIF_VCTRL_FIRST
                                                            Fr_ChannelType  FrIf_ChnlIdx);
#  endif

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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_AllowColdstart(FRIF_VCTRL_ONLY);

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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetPOCStatus(FRIF_VCTRL_FIRST
                                                P2VAR(Fr_POCStatusType, AUTOMATIC, FRIF_APPL_DATA) FrIf_POCStatusPtr);

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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetSyncState(FRIF_VCTRL_FIRST
                                                P2VAR(Fr_SyncStateType, AUTOMATIC, FRIF_APPL_DATA) FrIf_SyncStatePtr);

#  if defined ( FRIF_CHANNEL_STATUS_ENABLE ) && ( STD_ON == FRIF_CHANNEL_STATUS_ENABLE )
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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetChannelStatus(FRIF_VCTRL_FIRST                                                             
                                                      P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelAStatusPtr,
                                                      P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelBStatusPtr);
#  endif /* ( STD_ON == FRIF_CHANNEL_STATUS_ENABLE ) */

#  if defined ( FRIF_CLOCK_CORRECTION_ENABLE ) && ( STD_ON == FRIF_CLOCK_CORRECTION_ENABLE )
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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetClockCorrection(FRIF_VCTRL_FIRST
                                                   P2VAR(sint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_RateCorrectionPtr,
                                                   P2VAR(sint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_OffsetCorrectionPtr);
#  endif /* ( STD_ON == FRIF_CLOCK_CORRECTION_ENABLE ) */

#  if ( STD_ON == FRIF_NMVECTORSUPPORT )
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
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetNmVector(FRIF_VCTRL_FIRST
                                                       P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_NmVectorPtr);
#  endif /* ( STD_ON == FRIF_NMVECTORSUPPORT ) */




/**********************************************************************************************************************
  FrIf_GetGlobalTime
**********************************************************************************************************************/
/*! \brief      This function returns the FlexRay global time.
 *  \param[in]  FrIf_CtrlIdx:      The index of the CC the time shall be read from. 
 *  \param[out] FrIf_CyclePtr:     Reference to the memory location the current FlexRay communication cycle will 
 *                                 be stored at.
 *  \param[out] FrIf_MacroTickPtr: Reference to the memory location the current macrotick value will be stored at.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_GetGlobalTime() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_GetGlobalTime() 
 *                        has returned E_NOT_OK or a DEM error was thrown.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetGlobalTime(FRIF_VCTRL_FIRST
                                                         P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_CyclePtr, 
                                                         P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_MacroTickPtr);

#  if defined (FRIF_SET_EXT_SYNC_DISABLE) && (STD_OFF == FRIF_SET_EXT_SYNC_DISABLE)
/**********************************************************************************************************************
  FrIf_SetExtSync
**********************************************************************************************************************/
/*! \brief      This function calls Fr_SetExtSync for the FlexRay CCs with index FrIf_CtrlIdx.
 *              The external clock correction value is only applied for one Communication Cycle,  
 *              not repeatedly!
 *  \param[in]  FrIf_CtrlIdx:  Index of the FlexRay CC to whom the external clock synchronization shall be applied. 
 *  \param[in]  FrIf_Offset:   Offset correction that shall be applied
 *  \param[in]  FrIf_Rate:     Rate correction that shall be applied
 *  \return     E_OK:          The call of the FlexRay Driver API service Fr_SetExtSync() 
 *                             has returned E_OK.
 *              E_NOT_OK:      The call of the FlexRay Driver API service Fr_SetExtSync() 
 *                             has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetExtSync(FRIF_VCTRL_FIRST
                                                      Fr_OffsetCorrectionType  FrIf_Offset, 
                                                      Fr_RateCorrectionType    FrIf_Rate);
#  endif /* (STD_OFF == FRIF_SET_EXT_SYNC_DISABLE) */

#  if defined (FRIF_ABSOLUTE_TIMER_API_DISABLE) && (STD_OFF == FRIF_ABSOLUTE_TIMER_API_DISABLE)
/**********************************************************************************************************************
  FrIf_SetAbsoluteTimer
**********************************************************************************************************************/
/*! \brief      This function sets the alarm time of an FlexRay absolute timer.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer to be used for setting the alarm time
 *  \param[in]  Cycle:                 Cycle in which the timer shall expire.
 *  \param[in]  MacroTickOffset:       Offset to the cycle start in macro ticks.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_SetAbsoluteAlarmTime() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_SetAbsoluteAlarmTime() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetAbsoluteTimer(FRIF_VCTRL_FIRST
                                                            uint8   FrIf_AbsTimerIdx, 
                                                            uint8   Cycle, 
                                                            uint16  MacrotickOffset);

/**********************************************************************************************************************
  FrIf_CancelAbsoluteTimer
**********************************************************************************************************************/
/*! \brief      This function cancels an FlexRay absolute timer.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer to be used for stopping the alarm time
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_CancelAbsoluteTimer() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_CancelAbsoluteTimer() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_CancelAbsoluteTimer(FRIF_VCTRL_FIRST
                                                               uint8   FrIf_AbsTimerIdx);

/**********************************************************************************************************************
  FrIf_EnableAbsoluteTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function enables an FlexRay absolute timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer whose interrupt shall be enabled.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_EnableAbsoluteTimerIRQ() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_EnableAbsoluteTimerIRQ() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_EnableAbsoluteTimerIRQ(FRIF_VCTRL_FIRST
                                                                  uint8  FrIf_AbsTimerIdx);

/**********************************************************************************************************************
  FrIf_AckAbsoluteTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function acknowledges an FlexRay absolute timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer whose interrupt shall be acknowledged.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_AckAbsoluteTimerIRQ() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_AckAbsoluteTimerIRQ() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_AckAbsoluteTimerIRQ(FRIF_VCTRL_FIRST
                                                               uint8   FrIf_AbsTimerIdx);

/**********************************************************************************************************************
  FrIf_DisableAbsoluteTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function retrieves the interrupt status of an FlexRay absolute timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer whose interrupt shall be disabled.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_DisableAbsoluteTimerIRQ() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_DisableAbsoluteTimerIRQ() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableAbsoluteTimerIRQ(FRIF_VCTRL_FIRST
                                                                   uint8   FrIf_AbsTimerIdx);

/**********************************************************************************************************************
  FrIf_GetAbsoluteTimerIRQStatus
**********************************************************************************************************************/
/*! \brief      This function retrieves the interrupt status of an FlexRay absolute timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer whose interrupt status shall be retrieved.
 *  \param[out] FrIf_IRQStatusPtr:     Address where the interrupt status information shall be stored.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_GetAbsoluteTimerIRQStatus() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_GetAbsoluteTimerIRQStatus() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetAbsoluteTimerIRQStatus(FRIF_VCTRL_FIRST
                                                      uint8               FrIf_AbsTimerIdx, 
                                                      P2VAR(boolean, AUTOMATIC, FRIF_APPL_DATA) FrIf_IRQStatusPtr);
#  endif /* (STD_OFF == FRIF_ABSOLUTE_TIMER_API_DISABLE)  */

#  if defined(FRIF_RELATIVE_ALARM_ENABLE) && (STD_ON == FRIF_RELATIVE_ALARM_ENABLE)
/**********************************************************************************************************************
  FrIf_SetRelativeTimer
**********************************************************************************************************************/
/*! \brief      This function sets the alarm time of an FlexRay abrelativesolute timer.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_RelativeTimerIdx: Index of the relative timer to be used for setting the alarm time
 *  \param[in]  Cycle:                 Cycle in which the timer shall expire.
 *  \param[in]  MacroTickOffset:       Offset to the cycle start in macro ticks.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_SetRelativeAlarmTime() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_SetRelativeAlarmTime() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetRelativeTimer(FRIF_VCTRL_FIRST
                                                            uint8   FrIf_RelativeTimerIdx, 
                                                            uint16  MacrotickOffset);

/**********************************************************************************************************************
  FrIf_CancelRelativeTimer
**********************************************************************************************************************/
/*! \brief      This function cancels an FlexRay relative timer.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_RelativeTimerIdx: Index of the relative timer to be used for stopping the alarm time
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_CancelRelativeTimer() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_CancelRelativeTimer() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_CancelRelativeTimer(FRIF_VCTRL_FIRST
                                                               uint8   FrIf_RelativeTimerIdx);

/**********************************************************************************************************************
  FrIf_EnableRelativeTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function enables an FlexRay relative timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_RelativeTimerIdx: Index of the relative timer whose interrupt shall be enabled.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_EnableRelativeTimerIRQ() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_EnableRelativeTimerIRQ() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_EnableRelativeTimerIRQ(FRIF_VCTRL_FIRST
                                                                  uint8   FrIf_RelativeTimerIdx);


/**********************************************************************************************************************
  FrIf_DisableRelativeTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function retrieves the interrupt status of an FlexRay relative timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_RelativeTimerIdx: Index of the relative timer whose interrupt shall be disabled.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_DisableRelativeTimerIRQ() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_DisableRelativeTimerIRQ() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableRelativeTimerIRQ(FRIF_VCTRL_FIRST
                                                                   uint8   FrIf_RelativeTimerIdx);

/**********************************************************************************************************************
  FrIf_AckRelativeTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function acknowledges an FlexRay relative timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_RelativeTimerIdx: Index of the relative timer whose interrupt shall be acknowledged.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_AckRelativeTimerIRQ() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_AckRelativeTimerIRQ() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_AckRelativeTimerIRQ(FRIF_VCTRL_FIRST
                                                               uint8   FrIf_RelativeTimerIdx);

/**********************************************************************************************************************
  FrIf_GetRelativeTimerIRQStatus
**********************************************************************************************************************/
/*! \brief      This function retrieves the interrupt status of an FlexRay relative timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_RelativeTimerIdx: Index of the relative timer whose interrupt status shall be retrieved.
 *  \param[out] FrIf_IRQStatusPtr:     Address where the interrupt status information shall be stored.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_GetRelativeTimerIRQStatus() 
 *                        has returned E_OK.
 *              E_NOT_OK: The call of the FlexRay Driver API service Fr_GetRelativeTimerIRQStatus() 
 *                        has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetRelativeTimerIRQStatus(FRIF_VCTRL_FIRST
                                                    uint8               FrIf_RelativeTimerIdx, 
                                                    P2VAR(boolean, AUTOMATIC, FRIF_APPL_DATA) FrIf_IRQStatusPtr);

#  endif /* (STD_ON == FRIF_RELATIVE_ALARM_ENABLE) */

#  if defined(FRIF_USE_FRTRCV_API) && (STD_ON == FRIF_USE_FRTRCV_API)
/**********************************************************************************************************************
  FrIf_SetTransceiverMode
**********************************************************************************************************************/
/*! \brief      This function wraps the FrTrcv_SetTransceiverMode function of the FlexRay Transceiver Driver. 
 *  \param[in]  FrIf_CtrlIdx: The index of the FlexRay CC to which the transceiver is connected whose mode 
 *                            shall be set.
 *  \param[in]  FrIf_ChnlIdx: The index of the FlexRay channel to which the transceiver is connected whose mode 
 *                            shall be set. 
 *  \param[in]  FrIf_TrcvMode:The transceiver mode that shall be set.
 *  \return     E_OK:     The call of the FlexRay Transceiver Driver API service FrTrcv_SetTransceiverMode() 
 *                        has returned BUSTRCV_NO_ERROR.
 *              E_NOT_OK: The call of the FlexRay Transceiver Driver API service FrTrcv_SetTransceiverMode() 
 *                        has returned BUSTRCV_E_ERROR or an error has been detected in development mode.
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetTransceiverMode(FRIF_VCTRL_FIRST
                                                              uint8                FrIf_ChnlIdx, 
                                                              FrTrcv_TrcvModeType  FrIf_TrcvMode);

/**********************************************************************************************************************
  FrIf_GetTransceiverMode
**********************************************************************************************************************/
/*! \brief      This function wraps the FrTrcv_GetTransceiverMode function of the FlexRay Transceiver Driver. 
 *  \param[in]  FrIf_CtrlIdx:     The index of the FlexRay CC to which the transceiver is connected whose mode 
 *                                shall be read.
 *  \param[in]  FrIf_ChnlIdx:     The index of the FlexRay channel to which the transceiver is connected whose mode 
 *                                shall be read. 
 *  \param[out] FrIf_TrcvModePtr: The memory location where the transceiver mode shall be stored.
 *  \return     E_OK:     The call of the FlexRay Transceiver Driver API service FrTrcv_GetTransceiverMode() 
 *                        has returned BUSTRCV_NO_ERROR.
 *              E_NOT_OK: The call of the FlexRay Transceiver Driver API service FrTrcv_GetTransceiverMode() 
 *                        has returned BUSTRCV_E_ERROR or an error has been detected in development mode.
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetTransceiverMode(FRIF_VCTRL_FIRST
                                             uint8                           FrIf_ChnlIdx, 
                                             P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRIF_APPL_DATA) FrIf_TrcvModePtr);

/**********************************************************************************************************************
  FrIf_GetTransceiverWUReason
**********************************************************************************************************************/
/*! \brief      This function wraps the FrTrcv_GetTransceiverWUReason function of the FlexRay Transceiver Driver. 
 *              It can be used to determine the wake-up reason of a FlexRay transceiver.
 *  \param[in]  FrIf_CtrlIdx:     The index of the FlexRay CC to which the transceiver is connected whose wake-up
 *                                reason shall be determined.
 *  \param[in]  FrIf_ChnlIdx:     The index of the FlexRay channel to which the transceiver is connected whose wake-up 
 *                                reason shall be determined. 
 *  \param[out] FrIf_TrcvWUReasonPtr: The memory location where the transceiver wake-up reason shall be stored.
 *  \return     E_OK:     The call of the FlexRay Transceiver Driver API service FrTrcv_GetTransceiverWUReason() 
 *                        has returned BUSTRCV_NO_ERROR.
 *              E_NOT_OK: The call of the FlexRay Transceiver Driver API service FrTrcv_GetTransceiverWUReason() 
 *                        has returned BUSTRCV_E_ERROR or an error has been detected in development mode.
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetTransceiverWUReason(FRIF_VCTRL_FIRST
                                     uint8                               FrIf_ChnlIdx, 
                                     P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRIF_APPL_DATA) FrIf_TrcvWUReasonPtr);

/**********************************************************************************************************************
  FrIf_EnableTransceiverWakeup
**********************************************************************************************************************/
/*! \brief      This function wraps the FrTrcv_EnableTransceiverWakeup function of the FlexRay Transceiver Driver. 
 *              It can be used to enable the indication of wake-up events.
 *  \param[in]  FrIf_CtrlIdx:     The index of the FlexRay CC to which the transceiver is connected 
 *                                for which wake-up shall be enabled. 
 *  \param[in]  FrIf_ChnlIdx:     The index of the FlexRay channel to which the transceiver is connected 
 *                                for which wake-up shall be enabled.
 *  \return     E_OK:     The call of the FlexRay Transceiver Driver API service FrTrcv_EnableTransceiverWakeup() 
 *                        has returned BUSTRCV_NO_ERROR.
 *              E_NOT_OK: The call of the FlexRay Transceiver Driver API service FrTrcv_EnableTransceiverWakeup() 
 *                        has returned BUSTRCV_E_ERROR or an error has been detected in development mode.
 *  \see        The function is called by AUTOSAR FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_EnableTransceiverWakeup(FRIF_VCTRL_FIRST
                                                                   uint8  FrIf_ChnlIdx);

/**********************************************************************************************************************
  FrIf_DisableTransceiverWakeup
**********************************************************************************************************************/
/*! \brief      This function wraps the FrTrcv_DisableTransceiverWakeup function of the FlexRay Transceiver Driver. 
 *              It can be used to disable the indication of wake-up events.
 *  \param[in]  FrIf_CtrlIdx:     The index of the FlexRay CC to which the transceiver is connected 
 *                                for which wake-up shall be disabled. 
 *  \param[in]  FrIf_ChnlIdx:     The index of the FlexRay channel to which the transceiver is connected 
 *                                for which wake-up shall be disabled.
 *  \return     E_OK:     The call of the FlexRay Transceiver Driver API service FrTrcv_DisableTransceiverWakeup() 
 *                        has returned BUSTRCV_NO_ERROR.
 *              E_NOT_OK: The call of the FlexRay Transceiver Driver API service FrTrcv_DisableTransceiverWakeup() 
 *                        has returned BUSTRCV_E_ERROR or an error has been detected in development mode.
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableTransceiverWakeup(FRIF_VCTRL_FIRST
                                                                    uint8  FrIf_ChnlIdx);

/**********************************************************************************************************************
  FrIf_ClearTransceiverWakeup
**********************************************************************************************************************/
/*! \brief      This function wraps the FrTrcv_ClearTransceiverWakeup function of the FlexRay Transceiver Driver. 
 *              It can be used to clear the pending wake-up events.
 *  \param[in]  FrIf_CtrlIdx:     The index of the FlexRay CC to which the transceiver is connected 
 *                                for which wake-up shall be cleared. 
 *  \param[in]  FrIf_ChnlIdx:     The index of the FlexRay channel to which the transceiver is connected 
 *                                for which wake-up shall be cleared.
 *  \return     E_OK:     The call of the FlexRay Transceiver Driver API service FrTrcv_ClearTransceiverWakeup() 
 *                        has returned BUSTRCV_NO_ERROR.
 *              E_NOT_OK: The call of the FlexRay Transceiver Driver API service FrTrcv_ClearTransceiverWakeup() 
 *                        has returned BUSTRCV_E_ERROR or an error has been detected in development mode.
 *  \see        The function is called by Autosar FrSm or NodeManager
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_ClearTransceiverWakeup(FRIF_VCTRL_FIRST
                                                                  uint8  FrIf_ChnlIdx);

#  endif /* (STD_ON == FRIF_USE_FRTRCV_API)  */
# endif/* (STD_OFF == FRIF_API_AS_MACRO) */


# define FRIF_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 *//*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS (FrIf wrapper APIs as macro)
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACROS *//*  MD_MSR_19.7 */

# if defined ( FRIF_API_AS_MACRO ) && (STD_ON == FRIF_API_AS_MACRO)
#  define FrIf_ControllerInit(CtrlIdx)                                                     Fr_ControllerInit(CtrlIdx,0,0)
#  define FrIf_StartCommunication(CtrlIdx)                                                 Fr_StartCommunication(CtrlIdx)
#  define FrIf_HaltCommunication(CtrlIdx)                                                  Fr_HaltCommunication(CtrlIdx)

#  if defined (FRIF_ABORT_COMMUNICATION_DISABLE) && (STD_OFF == FRIF_ABORT_COMMUNICATION_DISABLE)
#   define FrIf_AbortCommunication(CtrlIdx)                                                Fr_AbortCommunication(CtrlIdx)
#  endif/* (STD_OFF == FRIF_ABORT_COMMUNICATION_DISABLE) */

#  define FrIf_SendWUP(CtrlIdx)                                                            Fr_SendWUP(CtrlIdx)

#  if defined (FRIF_SET_WAKEUP_CHANNEL_DISABLE) && (STD_OFF == FRIF_SET_WAKEUP_CHANNEL_DISABLE)
#   define FrIf_SetWakeupChannel(CtrlIdx, ChnlIdx)                                         Fr_SetWakeupChannel(CtrlIdx, ChnlIdx)
#  endif/* if defined (FRIF_SET_WAKEUP_CHANNEL_DISABLE) && (STD_OFF == FRIF_SET_WAKEUP_CHANNEL_DISABLE) */




#  define FrIf_AllowColdstart(CtrlIdx)                                                     Fr_AllowColdstart(CtrlIdx)
#  define FrIf_GetPOCStatus(CtrlIdx, POCStatusPtr)                                         Fr_GetPOCStatus(CtrlIdx, POCStatusPtr)
#  define FrIf_GetSyncState(CtrlIdx, SyncStatePtr)                                         Fr_GetSyncState(CtrlIdx, SyncStatePtr)

#  if defined ( FRIF_CHANNEL_STATUS_ENABLE ) && ( STD_ON == FRIF_CHANNEL_STATUS_ENABLE )
#   define FrIf_GetChannelStatus(CtrlIdx, ChannelAStatusPtr, ChannelBStatusPtr)            Fr_GetChannelStatus(CtrlIdx, ChannelAStatusPtr, ChannelBStatusPtr)
#  endif/* ( STD_ON == FRIF_CHANNEL_STATUS_ENABLE ) */

#  if defined ( FRIF_CLOCK_CORRECTION_ENABLE ) && ( STD_ON == FRIF_CLOCK_CORRECTION_ENABLE )
#   define FrIf_GetClockCorrection(CtrlIdx, RateCorrectionPtr, OffsetCorrectionPtr)        Fr_GetClockCorrection(CtrlIdx, RateCorrectionPtr, OffsetCorrectionPtr)
#  endif/* ( STD_ON == FRIF_CLOCK_CORRECTION_ENABLE ) */

#  if ( STD_ON == FRIF_NMVECTORSUPPORT )
#   define FrIf_GetNmVector(CtrlIdx, NmVectorPtr)                                          Fr_GetNmVector(CtrlIdx, NmVectorPtr)
#  endif/* ( STD_ON == FRIF_NMVECTORSUPPORT ) */

#  define FrIf_GetGlobalTime(CtrlIdx, CyclePtr, MacroTickPtr)                              Fr_GetGlobalTime(CtrlIdx, CyclePtr, MacroTickPtr)

#  if defined (FRIF_SET_EXT_SYNC_DISABLE) && (STD_OFF == FRIF_SET_EXT_SYNC_DISABLE)
#   define FrIf_SetExtSync(CtrlIdx, Offset, Rate)                                          Fr_SetExtSync(CtrlIdx, Offset, Rate)
#  endif/* (STD_OFF == FRIF_SET_EXT_SYNC_DISABLE)  */

#  if defined (FRIF_ABSOLUTE_TIMER_API_DISABLE) && (STD_OFF == FRIF_ABSOLUTE_TIMER_API_DISABLE)
#   define FrIf_SetAbsoluteTimer(CtrlIdx, AbsTimerIdx, Cycle, MacrotickOffset)             Fr_SetAbsoluteTimer(CtrlIdx, AbsTimerIdx, Cycle, MacrotickOffset)
#   define FrIf_CancelAbsoluteTimer(CtrlIdx, AbsTimerIdx)                                  Fr_CancelAbsoluteTimer(CtrlIdx, AbsTimerIdx)
#   define FrIf_AckAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)                                  Fr_AckAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)
#   define FrIf_EnableAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)                               Fr_EnableAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)
#   define FrIf_DisableAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)                              Fr_DisableAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)
#   define FrIf_GetAbsoluteTimerIRQStatus(CtrlIdx, AbsTimerIdx, IRQStatusPtr)              Fr_GetAbsoluteTimerIRQStatus(CtrlIdx, AbsTimerIdx, IRQStatusPtr)
#  endif/* (STD_OFF == FRIF_ABSOLUTE_TIMER_API_DISABLE) */

#  if defined(FRIF_RELATIVE_ALARM_ENABLE) && (STD_ON == FRIF_RELATIVE_ALARM_ENABLE)
#   define FrIf_SetRelativeTimer(CtrlIdx, RelativeTimerIdx, MacrotickOffset)               Fr_SetRelativeTimer(CtrlIdx, RelativeTimerIdx, MacrotickOffset)
#   define FrIf_CancelRelativeTimer(CtrlIdx, RelativeTimerIdx)                             Fr_CancelRelativeTimer(CtrlIdx, RelativeTimerIdx)
#   define FrIf_AckRelativeTimerIRQ(CtrlIdx, RelativeTimerIdx)                             Fr_AckRelativeTimerIRQ(CtrlIdx, RelativeTimerIdx)
#   define FrIf_EnableRelativeTimerIRQ(CtrlIdx, RelativeTimerIdx)                          Fr_EnableRelativeTimerIRQ(CtrlIdx, RelativeTimerIdx)
#   define FrIf_DisableRelativeTimerIRQ(CtrlIdx, RelativeTimerIdx)                         Fr_DisableRelativeTimerIRQ(CtrlIdx, RelativeTimerIdx)
#   define FrIf_GetRelativeTimerIRQStatus(CtrlIdx, RelativeTimerIdx, IRQStatusPtr)         Fr_GetRelativeTimerIRQStatus(CtrlIdx, RelativeTimerIdx, IRQStatusPtr)
#  endif/* (STD_ON == FRIF_RELATIVE_ALARM_ENABLE) */

/* note: the FrIf wrapper macros for the FrTrcv are only valid if the BusTrcvErrorType return type is the same as Std_ReturnType */
#  if defined(FRIF_USE_FRTRCV_API) && (STD_ON == FRIF_USE_FRTRCV_API)
#   define FrIf_SetTransceiverMode(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvMode)              FrTrcv_SetTransceiverMode(FrIf_ChnlIdx, FrIf_TrcvMode)
#   define FrIf_GetTransceiverMode(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvModePtr)           FrTrcv_GetTransceiverMode(FrIf_ChnlIdx, FrIf_TrcvModePtr)
#   define FrIf_GetTransceiverWUReason(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvWUReasonPtr)   FrTrcv_GetTransceiverWUReason(FrIf_ChnlIdx, FrIf_TrcvWUReasonPtr)
#   define FrIf_EnableTransceiverWakeup(FrIf_CtrlIdx, FrIf_ChnlIdx)                        FrTrcv_EnableTransceiverWakeup(FrIf_ChnlIdx)
#   define FrIf_DisableTransceiverWakeup(FrIf_CtrlIdx, FrIf_ChnlIdx)                       FrTrcv_DisableTransceiverWakeup(FrIf_ChnlIdx)
#   define FrIf_ClearTransceiverWakeup(FrIf_CtrlIdx, FrIf_ChnlIdx)                         FrTrcv_ClearTransceiverWakeup(FrIf_ChnlIdx)
#  endif/* (STD_ON == FRIF_USE_FRTRCV_API) */
# endif/* (STD_ON == FRIF_API_AS_MACRO) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS (single controller optimization)
 *********************************************************************************************************************/

# if ( STD_ON == FRIF_CTRL_ENABLE_API_OPTIMIZATION )
#  if defined ( FRIF_API_AS_MACRO ) && (STD_OFF == FRIF_API_AS_MACRO)
#   define FrIf_ControllerInit(FrIf_CtrlIdx)                                               FrIf_ControllerInit()
#   define FrIf_StartCommunication(FrIf_CtrlIdx)                                           FrIf_StartCommunication()
#   define FrIf_HaltCommunication(FrIf_CtrlIdx)                                            FrIf_HaltCommunication()

#   if defined (FRIF_ABORT_COMMUNICATION_DISABLE) && (STD_OFF == FRIF_ABORT_COMMUNICATION_DISABLE)
#    define FrIf_AbortCommunication(FrIf_CtrlIdx)                                          FrIf_AbortCommunication()
#   endif/* (STD_OFF == FRIF_ABORT_COMMUNICATION_DISABLE) */

#   define FrIf_SendWUP(FrIf_CtrlIdx)                                                      FrIf_SendWUP()

#   if defined (FRIF_SET_WAKEUP_CHANNEL_DISABLE) && (STD_OFF == FRIF_SET_WAKEUP_CHANNEL_DISABLE)
#    define FrIf_SetWakeupChannel(FrIf_CtrlIdx, FrIf_ChnlIdx)                              FrIf_SetWakeupChannel(FrIf_ChnlIdx)
#   endif/* (STD_OFF == FRIF_SET_WAKEUP_CHANNEL_DISABLE) */




#   define FrIf_AllowColdstart(FrIf_CtrlIdx)                                               FrIf_AllowColdstart()
#   define FrIf_GetPOCStatus(FrIf_CtrlIdx, FrIf_POCStatusPtr)                              FrIf_GetPOCStatus(FrIf_POCStatusPtr)
#   define FrIf_GetSyncState(FrIf_CtrlIdx, FrIf_SyncStatePtr)                              FrIf_GetSyncState(FrIf_SyncStatePtr)

#   if defined ( FRIF_CHANNEL_STATUS_ENABLE ) && ( STD_ON == FRIF_CHANNEL_STATUS_ENABLE )
#    define FrIf_GetChannelStatus(FrIf_CtrlIdx, FrIf_ChannelAStatusPtr, FrIf_ChannelBStatusPtr) FrIf_GetChannelStatus(FrIf_ChannelAStatusPtr, FrIf_ChannelBStatusPtr)
#   endif/* ( STD_ON == FRIF_CHANNEL_STATUS_ENABLE ) */

#   if defined ( FRIF_CLOCK_CORRECTION_ENABLE ) && ( STD_ON == FRIF_CLOCK_CORRECTION_ENABLE )
#    define FrIf_GetClockCorrection(FrIf_CtrlIdx, RateCorrectionPtr, OffsetCorrectionPtr)  FrIf_GetClockCorrection(RateCorrectionPtr, OffsetCorrectionPtr)
#   endif/* ( STD_ON == FRIF_CLOCK_CORRECTION_ENABLE ) */

#   if ( STD_ON == FRIF_NMVECTORSUPPORT )
#    define FrIf_GetNmVector(FrIf_CtrlIdx, FrIf_NmVectorPtr)                               FrIf_GetNmVector(FrIf_NmVectorPtr)
#   endif/* ( STD_ON == FRIF_NMVECTORSUPPORT ) */

#   define FrIf_GetGlobalTime(FrIf_CtrlIdx, FrIf_CyclePtr, FrIf_MacroTickPtr)              FrIf_GetGlobalTime(FrIf_CyclePtr, FrIf_MacroTickPtr)

#   if defined (FRIF_SET_EXT_SYNC_DISABLE) && (STD_OFF == FRIF_SET_EXT_SYNC_DISABLE)
#    define FrIf_SetExtSync(FrIf_CtrlIdx, FrIf_Offset, FrIf_Rate)                          FrIf_SetExtSync(FrIf_Offset, FrIf_Rate)
#   endif /* (STD_OFF == FRIF_SET_EXT_SYNC_DISABLE) */

#   if defined (FRIF_ABSOLUTE_TIMER_API_DISABLE) && (STD_OFF == FRIF_ABSOLUTE_TIMER_API_DISABLE)
#    define FrIf_SetAbsoluteTimer(FrIf_CtrlIdx, FrIf_AbsTimerIdx, Cycle, MacrotickOffset)  FrIf_SetAbsoluteTimer(FrIf_AbsTimerIdx, Cycle, MacrotickOffset)
#    define FrIf_CancelAbsoluteTimer(FrIf_CtrlIdx, FrIf_AbsTimerIdx)                       FrIf_CancelAbsoluteTimer(FrIf_AbsTimerIdx)
#    define FrIf_AckAbsoluteTimerIRQ(FrIf_CtrlIdx, FrIf_AbsTimerIdx)                       FrIf_AckAbsoluteTimerIRQ(FrIf_AbsTimerIdx)
#    define FrIf_EnableAbsoluteTimerIRQ(FrIf_CtrlIdx, FrIf_AbsTimerIdx)                    FrIf_EnableAbsoluteTimerIRQ(FrIf_AbsTimerIdx)
#    define FrIf_DisableAbsoluteTimerIRQ(FrIf_CtrlIdx, FrIf_AbsTimerIdx)                   FrIf_DisableAbsoluteTimerIRQ(FrIf_AbsTimerIdx)
#    define FrIf_GetAbsoluteTimerIRQStatus(FrIf_CtrlIdx, AbsTimerIdx, IRQStatusPtr)        FrIf_GetAbsoluteTimerIRQStatus(AbsTimerIdx, IRQStatusPtr)
#   endif /* (STD_OFF == FRIF_ABSOLUTE_TIMER_API_DISABLE) */

#   if defined(FRIF_RELATIVE_ALARM_ENABLE) && (STD_ON == FRIF_RELATIVE_ALARM_ENABLE)
#    define FrIf_SetRelativeTimer(FrIf_CtrlIdx, FrIf_RelativeTimerIdx, MacrotickOffset)    FrIf_SetRelativeTimer(FrIf_RelativeTimerIdx, MacrotickOffset)
#    define FrIf_CancelRelativeTimer(FrIf_CtrlIdx, FrIf_RelativeTimerIdx)                  FrIf_CancelRelativeTimer(FrIf_RelativeTimerIdx)
#    define FrIf_AckRelativeTimerIRQ(FrIf_CtrlIdx, FrIf_RelativeTimerIdx)                  FrIf_AckRelativeTimerIRQ(FrIf_RelativeTimerIdx)
#    define FrIf_EnableRelativeTimerIRQ(FrIf_CtrlIdx, FrIf_RelativeTimerIdx)               FrIf_EnableRelativeTimerIRQ(FrIf_RelativeTimerIdx)
#    define FrIf_DisableRelativeTimerIRQ(FrIf_CtrlIdx, FrIf_RelativeTimerIdx)              FrIf_DisableRelativeTimerIRQ(FrIf_RelativeTimerIdx)
#    define FrIf_GetRelativeTimerIRQStatus(FrIf_CtrlIdx, RelativeTimerIdx, IRQStatusPtr)   FrIf_GetRelativeTimerIRQStatus(RelativeTimerIdx, IRQStatusPtr)
#   endif/* (STD_ON == FRIF_RELATIVE_ALARM_ENABLE) */

#   if defined(FRIF_USE_FRTRCV_API) && (STD_ON == FRIF_USE_FRTRCV_API)
#    define FrIf_SetTransceiverMode(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvMode)             FrIf_SetTransceiverMode(FrIf_ChnlIdx, FrIf_TrcvMode)
#    define FrIf_GetTransceiverMode(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvModePtr)          FrIf_GetTransceiverMode(FrIf_ChnlIdx, FrIf_TrcvModePtr)
#    define FrIf_GetTransceiverWUReason(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvWUReasonPtr)  FrIf_GetTransceiverWUReason(FrIf_ChnlIdx, FrIf_TrcvWUReasonPtr)
#    define FrIf_EnableTransceiverWakeup(FrIf_CtrlIdx, FrIf_ChnlIdx)                       FrIf_EnableTransceiverWakeup(FrIf_ChnlIdx)
#    define FrIf_DisableTransceiverWakeup(FrIf_CtrlIdx, FrIf_ChnlIdx)                      FrIf_DisableTransceiverWakeup(FrIf_ChnlIdx)
#    define FrIf_ClearTransceiverWakeup(FrIf_CtrlIdx, FrIf_ChnlIdx)                        FrIf_ClearTransceiverWakeup(FrIf_ChnlIdx)
#   endif/* (STD_ON == FRIF_USE_FRTRCV_API) */
#  endif/* (STD_OFF == FRIF_API_AS_MACRO) */

#  define FrIf_SetState(FrIf_ClstIdx, FrIf_StatePtr)                                       FrIf_SetState(FrIf_StatePtr)
#  define FrIf_GetState(FrIf_ClstIdx, FrIf_StatePtr)                                       FrIf_GetState(FrIf_StatePtr)
#  define FrIf_GetMacroticksDuration(FrIf_CtrlIdx)                                         FrIf_GetMacroticksDuration()
#  define FrIf_GetMacroticksPerCycle(FrIf_ClstIdx)                                         FrIf_GetMacroticksPerCycle()
#  define FrIf_ConvertNanosecToMacroticks(FrIf_ClstIdx, FrIf_MacroTickPtr, FrIf_Nanosec)   FrIf_ConvertNanosecToMacroticks(FrIf_MacroTickPtr, FrIf_Nanosec)
#  define FrIf_ConvertMacroticksToNanosec(FrIf_ClstIdx, FrIf_NanosecPtr, FrIf_MacroTick)   FrIf_ConvertMacroticksToNanosec(FrIf_NanosecPtr, FrIf_MacroTick)
# endif/* ( FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON ) */

/* PRQA L:FUNCTIONLIKEMACROS *//*  MD_MSR_19.7 */

#endif
/* FRIF_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf.h
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
