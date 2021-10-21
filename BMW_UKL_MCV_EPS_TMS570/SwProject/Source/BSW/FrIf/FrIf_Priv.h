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
/*! \file         FrIf_Priv.h
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Private header file of the AUTOSAR FlexRay Interface, according to:
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
 -  3.0.1     2008-02-22  ber     -             release of version 3.0.1 
 -  3.0.2     2008-03-20  ber     ESCAN00025115 No changes here
 -            2008-03-27  ore     -             renamed Fr_RxLSduStatusType to Fr_RxLPduStatusType
 -            2008-04-02  ber     ESCAN00023644 No changes here
 -            2008-04-03  ber     -             release of version 3.0.2
 -  3.0.3     2008-04-17  ber     ESCAN00026131 Memory Access Violation in embedded code during FrIf job list execution
 -            2008-04-18  ber     ESCAN00025799 No changes here
 -            2008-04-18  ber     -             release of version 3.0.3 
 -  3.0.4     2008-04-25  ore     ESCAN00026130 No changes here
 -            2008-04-25  ore     ESCAN00026216 No changes here
 -            2008-04-25  ore     ESCAN00026256 Rename files and #include statements according coding styles
 -            2008-04-28  ore     ESCAN00026445 No changes here
 -            2008-04-28  ore     ESCAN00026447 No changes here
 -            2008-04-28  ore     ESCAN00026449 No changes here
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
 -            2008-07-28  ore     ESCAN00028772 FrIf Single-Controller Optimization
 -            2008-08-01  ore     ESCAN00027451 No changes here
 -            2008-08-07  ore     ESCAN00029068 No changes here
 -            2008-08-07  ore     ESCAN00029042 No changes here
 -            2008-08-13  ore     ESCAN00029218 No changes here
 -            2008-08-13  ore     ESCAN00029219 No changes here
 -            2008-08-13  ore     ESCAN00029184 Call TxConf-callbacks in case of stopping or resynchronizing the FrIf-JobList
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No changes here
 -            2008-08-22  ore     -             release of version 3.0.8
 -  3.0.9     2008-09-17  ore     -             release of version 3.0.9
 -  3.0.10    2008-10-01  ore     ESCAN00030038 FrIf file name conventions
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 No changes here
 -            2008-10-01  ore     ESCAN00029696 No changes here
 -            2008-10-01  ore     ESCAN00029736 No changes here
 -            2008-11-03  ore     ESCAN00031030 Unused frame parts are not always initialized
 -            2008-11-03  ore     ESCAN00031026 No changes here
 -            2008-11-04  ore     -             release of version 3.0.10
 -  3.1.0     2008-11-10  ore     ESCAN00030776 No changes here
 -            2008-11-10  ore     ESCAN00030577 No changes here
 -            2008-11-10  ore     ESCAN00030264 No changes here
 -            2008-11-10  ore     ESCAN00030764 No changes here
 -            2008-11-17  ore     ESCAN00031345 No changes here
 -            2008-11-17  ore     ESCAN00030264 No changes here
 -            2008-11-18  ore     -             added MISRA violation comments
 -            2008-11-24  ore     -             fixed code-review findings   
 -            2008-11-24  ore     ESCAN00031360 No changes here
 -            2008-12-01  ore     ESCAN00031710 No changes here
 -            2008-12-08  ore     ESCAN00031843 No changes here
 -            2008-12-19  ore     -             release of version 3.1.0
 -  3.2.0     2009-02-02  ore     ESCAN00032463 No changes here
 -            2009-02-10  ore     ESCAN00032944 No changes here
 -            2009-02-17  ore     ESCAN00033102 No changes here
 -            2009-02-18  ore     ESCAN00027867 No changes here
 -            2009-02-18  ore     ESCAN00033318 No changes here
 -            2009-02-18  ore     ESCAN00033145 No changes here
 -            2009-02-18  ore     ESCAN00033220 The functions FrIf_RxTask_0 and FrIf_TxTask_0 shall have standard 
 *                                              return values.
 -            2009-02-18  ore     ESCAN00032895 FrIf Job Concatenation Optimization
 -            2009-02-18  ore     ESCAN00033309 Remove FrIf memory class macros to reduce the number of misra 
 *                                              violations.
 -            2009-02-18  ore     ESCAN00031278 No changes here
 -            2009-02-25  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 The FrIf source and header files don't use the Compiler-Abstraction 
 *                                              keyword STATIC.
 -            2009-02-26  ore     ESCAN00032715 No changes here
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     ESCAN00033651 Unify DET implementation
 -            2009-03-06  ore     ESCAN00033665 Add missing Link-time configuration variant
 -            2009-03-16  ore     -             Renamed IsValidPostBuildConfigData routine according to ESCAN00030040
 -            2009-03-10  ore     ESCAN00033732 No changes here
 -            2009-03-23  ore     ESCAN00034040 No changes here
 -            2009-03-23  ore     -             release of version 3.2.0
 -  3.3.0     2009-04-06  ore     ESCAN00036436 Add PRQA misra justification comments for QAC
 -            2009-05-28  ore     ESCAN00035398 No changes here
 -            2009-05-28  ore     ESCAN00035048 No changes here
 -            2009-06-29  ore     ESCAN00035991 No changes here
 -            2009-07-06  ore     ESCAN00036053 No changes here
 -            2009-07-20  ore     ESCAN00036397 No changes here
 -            2009-07-14  ore     ESCAN00035990 Pointer in FrIf_Init() is not pointer to the Flexray Init configuration
 -            2009-07-14  ore     ESCAN00035399 The static header files of the FrIf don't include the Memmap.h file 
 -            2009-07-15  ore     ESCAN00036426 No changes here
 -            2009-07-15  ore     ESCAN00036427 Implement FrIf_DiffTime as static function
 -            2009-07-15  ore     ESCAN00036429 No changes here
 -            2009-07-15  ore     ESCAN00036451 No changes here
 -            2009-07-16  ore     ESCAN00036471 No changes here
 -            2009-07-17  ore     ESCAN00034459 No changes here
 -            2009-07-28  ore     ESCAN00036120 pre-processor checks for building the library
 -            2009-07-31  ore     ESCAN00036776 No changes here
 -            2009-07-31  ore     -             release of version 3.3.0 
 -  3.4.0     2009-08-24  ore     ESCAN00036905 No changes here
 -            2009-08-24  ore     ESCAN00037257 No changes here
 -            2009-09-08  ore     ESCAN00035396 The FrIf bitarrays in postbuild structures are not supported by the 
 *                                              GenTool_GenyFrameworkPostbuildconfig component.
 -            2009-09-08  ore     ESCAN00037643 No changes here
 -            2009-09-08  ore     ESCAN00037633 No changes here
 -            2009-09-21  ore     ESCAN00036013 Similar DET Usage
 -            2009-10-27  ore     ESCAN00038513 Use E_PENDING in FrIf_Transmit if data is copied in PduR_FrIfTriggerTransmit, 
 *                                              FrNm_TriggerTransmit and FrTp_TriggerTransmit
 -            2009-11-02  ore     ESCAN00038914 FrIf_StartJobExecution routine shall call Fr_PrepareLPdu for all Rx and 
 *                                              Tx handles to flush the complete hardware FIFO
 -            2009-11-02  ore     ESCAN00038855 No changes here
 -            2009-11-03  ore     ESCAN00038930 The revision history of all source and header files shall contain all 
 *                                              implementation relevant ClearQuest issues of the FrIf.
 -            2009-11-17  ore     ESCAN00039212 No changes here
 -            2009-11-30  ore     ESCAN00039411 No changes here
 -            2009-12-07  ore     ESCAN00039607 No changes here
 -            2009-12-07  ore     ESCAN00039609 No changes here
 -            2009-12-07  ore     -             release of version 3.4.0 
 -  3.5.0     2010-02-01  ore     -             Removed obsolete AUTOSAR 2.1 FlexRay IL Support 
 -            2010-02-01  ore     ESCAN00040508 Add feature to support FreeOp-Callbacks
 -            2010-02-16  ore     ESCAN00040867 No changes here
 -            2010-02-18  ore     ESCAN00040951 FrIf without SchM cannot be compiled
 -            2010-02-18  ore     ESCAN00040960 No changes here
 -            2010-02-22  ore     ESCAN00039809 Store the update byte position as link-time variable or pre-compile define
 -            2010-03-18  ore     ESCAN00041666 No changes here
 -            2010-03-24  ore     ESCAN00041766 No changes here
 -            2010-03-24  ore     ESCAN00041788 No changes here
 -            2010-03-30  ore     ESCAN00041966 Metrowerks Compile warning: Possible loss of data
 -            2010-04-22  ore     ESCAN00042422 No changes here
 -            2010-05-05  ore     ESCAN00041396 Reduce the duration of critical sections of the FrIf when the FrIfJobList
 *                                              execution goes out of sync
 -            2010-05-05  ore     -             release of version 3.5.0
 -  3.6.0     2010-05-19  ore     ESCAN00042989 No changes here
 -            2010-05-28  ore     ESCAN00043268 No changes here 
 -            2010-06-24  ore     ESCAN00043567 No changes here 
 -            2010-06-24  ore     ESCAN00043569 No changes here 
 -            2010-07-07  ore     -             Fixed function descriptions so that they are correctly considered by Doxygen
 -            2010-07-22  ore     ESCAN00042986 No changes here 
 -            2010-07-29  ore     ESCAN00044336 Ensure consistency to C-sources for all FrIf header files
 -            2010-07-29  ore     ESCAN00044339 No changes here 
 -            2010-08-02  ore     -             Changed QAC justifications to be CDK compliant
 -            2010-08-03  ore     -             release of version 3.6.0 
 -  3.6.1     2010-09-22  ore     ESCAN00044465 No changes here 
 -            2010-09-22  ore     ESCAN00045547 No changes here 
 -            2010-09-22  ore     -             release of version 3.6.1
 -  3.7.0     2010-11-02  ore     ESCAN00045650 No changes here 
 -            2010-11-02  ore     ESCAN00046417 No changes here 
 -            2010-11-02  ore     ESCAN00046257 Adapt AUTOSAR version check
 -            2010-11-05  ore     ESCAN00046607 No changes here 
 -            2010-11-16  ore     ESCAN00046950 No changes here 
 -            2010-11-25  ore     ESCAN00046093 No changes here 
 -            2010-11-26  ore     ESCAN00047186 No changes here 
 -            2010-12-01  ore     ESCAN00047302 No changes here 
 -            2010-12-01  ore     ESCAN00047327 No changes here 
 -            2011-01-27  ore     ESCAN00048244 No changes here 
 -            2011-01-27  ore     -             release of version 3.7.0
 -  3.7.1     2011-02-23  ore     ESCAN00048836 No changes here 
 -            2011-05-02  ore     -             All component specific MISRA deviations are now justified in FrIf.c
 -            2011-03-16  ore     -             release of version 3.7.1
 -  3.7.3     2011-09-20  ore     ESCAN00051840 No changes here 
 -            2011-09-20  ore     -             release of version 3.7.3
 -  3.7.4     2011-10-25  ore     ESCAN00054422 No changes here 
 -            2011-10-25  ore     -             release of version 3.7.4
 *********************************************************************************************************************/

#if (!defined FRIF_PRIV_H_)
# define FRIF_PRIV_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "FrIf.h"
# include "FrIf_Lcfg.h"
# include "FrIf_PBcfg.h"

# include "Fr.h"

# include "SchM_FrIf.h"


# if defined(FRIF_DEV_ERROR_DETECT) && (STD_ON == FRIF_DEV_ERROR_DETECT)
#  include "Det.h"              /* Include Development Error Tracer */
# endif

# if defined(FRIF_PROD_ERROR_DETECT) && (STD_ON == FRIF_PROD_ERROR_DETECT)
#  include "Dem.h"
# endif



/**********************************************************************************************************************
 *  CONSISTENCY CHECK
 *********************************************************************************************************************/
#if ( IF_ASRIFFR_VERSION != 0x0307u )
# error "The included header FrIf.h is incompatible with the FrIf.c version."
#endif
#if ( IF_ASRIFFR_RELEASE_VERSION != 0x04u )
# error "The included header FrIf.h is incompatible with the FrIf.c release version."
#endif

# if defined (FRIF_LCFG_VERSION)
#  if ( FRIF_LCFG_VERSION != IF_ASRIFFR_VERSION )
#   error "The included header FrIf_Lcfg.h is incompatible with the FrIf version in FrIf_Priv.h."
#  endif
# else
#  error "Version information of header FrIf_Lcfg.h is missing. Compatibility cannot be verified!"
# endif
# if defined (FRIF_LCFG_RELEASE_VERSION)
#  if ( FRIF_LCFG_RELEASE_VERSION != IF_ASRIFFR_RELEASE_VERSION )
#   error "The included header FrIf_Lcfg.h is incompatible with the FrIf release version in FrIf_Priv.h."
#  endif
# else
#  error "Release version information of header FrIf_Lcfg.h is missing. Compatibility cannot be verified!"
# endif

# if defined (FRIF_PBCFG_VERSION)
#  if ( FRIF_PBCFG_VERSION != IF_ASRIFFR_VERSION )
#   error "The included header FrIf_PBcfg.h is incompatible with the FrIf version in FrIf_Priv.h."
#  endif
# else
#  error "Version information of header FrIf_PBcfg.h is missing. Compatibility cannot be verified!"
# endif
# if defined (FRIF_PBCFG_RELEASE_VERSION)
#  if ( FRIF_PBCFG_RELEASE_VERSION != IF_ASRIFFR_RELEASE_VERSION )
#   error "The included header FrIf_PBcfg.h is incompatible with the FrIf release version in FrIf_Priv.h."
#  endif
# else
#  error "Release version information of header FrIf_PBcfg.h is missing. Compatibility cannot be verified!"
# endif


# if (IF_ASRIFFRDLL_VERSION < 0x0312u)
#  error "Component FrIf: Wrong configuration tool version."
# endif

# if defined (COMMONASR__COMMON_IMPL_STDTYPES_VERSION)        \
      && (((COMMONASR__COMMON_IMPL_STDTYPES_VERSION < 0x303u) \
      ||  ((COMMONASR__COMMON_IMPL_STDTYPES_VERSION ==  0x303u) && (COMMONASR__COMMON_IMPL_STDTYPES_RELEASE_VERSION < 0x01))))
#  error "Component FrIf: Invalid version of Std_Types.h used. Minimum version 03.03.01 is required for definition of return value E_PENDING."
# endif


/* pre-processor checks for building the library */
# if defined ( V_EXTENDED_BUILD_LIB_CHECK )
#  if defined ( FRIF_CONFIG_VARIANT ) && (1u == FRIF_CONFIG_VARIANT)
#   error "Component FrIf: Configuration variant must be 2 or 3 at lib delivery."
#  endif
# endif

/*******************************************************************************************************************/
/*  VERSION CHECK AR3-F1155 (external modules)                                                                     */
/*******************************************************************************************************************/

#if defined ( FR_VENDOR_ID )
# if FRIF_VENDOR_ID == FR_VENDOR_ID
/* BSW004: AUTOSAR version information check has to match definition in header file */
#  if (  (FR_AR_MAJOR_VERSION != (0x02)) \
      || (FR_AR_MAJOR_VERSION != (0x02)) )
#   error "AUTOSAR Specification Version 02.02.xx of FlexRay Driver expected!"
#  endif
# endif /* ( FRIF_VENDOR_ID == FR_VENDOR_ID ) */
#endif /* ( FR_VENDOR_ID ) */

# if defined ( SCHM_VENDOR_ID )
#  if FRIF_VENDOR_ID == SCHM_VENDOR_ID
/* BSW004: AUTOSAR version information check has to match definition in header file */
#   if (  (SCHM_AR_MAJOR_VERSION != (0x01)) \
       || (SCHM_AR_MINOR_VERSION != (0x01)) )
#    error "AUTOSAR Specification Version 01.01.xx of BSW Scheduler expected!"
#   endif
#  endif /* ( FRIF_VENDOR_ID == SCHM_VENDOR_ID ) */
# endif /* ( SCHM_VENDOR_ID ) */

#if defined(FRIF_DEV_ERROR_DETECT) && (STD_ON == FRIF_DEV_ERROR_DETECT)
# if defined ( DET_VENDOR_ID )
#  if FRIF_VENDOR_ID == DET_VENDOR_ID
/* BSW004: AUTOSAR version information check has to match definition in header file */
#   if (  (DET_AR_MAJOR_VERSION != (0x02)) \
       || (DET_AR_MINOR_VERSION != (0x02)) )
#    error "AUTOSAR Specification Version 02.02.xx of Development Error Tracer expected!"
#   endif
#  endif /* ( FRIF_VENDOR_ID == DET_VENDOR_ID ) */
# endif /* ( DET_VENDOR_ID ) */
#endif /* defined(FRIF_DEV_ERROR_DETECT) && (STD_ON == FRIF_DEV_ERROR_DETECT) */

#if defined(FRIF_PROD_ERROR_DETECT) && (STD_ON == FRIF_PROD_ERROR_DETECT)
# if defined ( DEM_VENDOR_ID )
#  if FRIF_VENDOR_ID == DEM_VENDOR_ID
/* BSW004: AUTOSAR version information check has to match definition in header file */
#   if (  (DEM_AR_MAJOR_VERSION != (0x02)) \
       || (DEM_AR_MINOR_VERSION != (0x02)) )
#    error "AUTOSAR Specification Version 02.02.xx of Diagnostic Event Manager expected!"
#   endif
#  endif /* ( FRIF_VENDOR_ID == DEM_VENDOR_ID ) */
# endif /* ( DEM_VENDOR_ID ) */
#endif /* defined(FRIF_PROD_ERROR_DETECT) && (STD_ON == FRIF_PROD_ERROR_DETECT) */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* AUTOSAR FlexRay Interface version */
# define FRIF_PRIV_VERSION            0x0307u /*!< BCD coded FrIf Priv Header version number */
# define FRIF_PRIV_RELEASE_VERSION    0x04u   /*!< BCD coded FrIf Priv Header release version number */

# define FRIF_IS_INITIALIZED_MAGIC_NUMBER  (uint16)0xCAFEu
# define FRIF_MAX_NUMBER_OF_REDUNDANT_PDUS (uint8)0x02u
# define NO_FLEXRAY_CYCLES                 (uint8)64u

# if (!defined FRIF_CUSTOM_JLE_SCHEDULING)
#  define FRIF_CUSTOM_JLE_SCHEDULING        STD_OFF
# endif

# if (!defined FRIF_FILL_PATTERN )
#  define FRIF_FILL_PATTERN                 (uint8)0x00u
# endif

# if (!defined FRIF_FILL_PATTERN_DWORD )
#  define FRIF_FILL_PATTERN_DWORD           (uint32)0x00u
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

 /* PRQA S 3453 FUNCTIONLIKEMACRO *//* MD_MSR_19.7 */

# define NEXT_CYCLE(Cycle)     ((uint8)((uint8)((Cycle) + (uint8) 1u) & (uint8)0x3Fu))
# define PREVIOUS_CYCLE(Cycle) ((uint8)((uint8)((Cycle) + (uint8)63u) & (uint8)0x3Fu))

# define GET_TRANSCEIVER_INDEX(CtrlIdx, ChnlIdx)   (ChnlIdx)
# define FrIf_TimerIndex2FrTimerIndex(TimerIndex)  (TimerIndex)
# define FrIf_TimerIndex2FrCtrlIndex(TimerIndex)   (0)

# if defined(FRIF_DEV_ERROR_DETECT) && ( STD_ON == FRIF_DEV_ERROR_DETECT )
#  define DET_ERRORMSG(service, error) Det_ReportError(FRIF_MODULE_ID, 0, (service), (error))
# endif

# if defined(FRIF_PROD_ERROR_DETECT) && (STD_ON==FRIF_PROD_ERROR_DETECT)
#  define DEM_JobListNotSynchronized() \
  Dem_ReportErrorStatus((Dem_EventIdType)FrIf_ErrorId_JLE_Sync, DEM_EVENT_STATUS_FAILED)
# else
#  define DEM_JobListNotSynchronized()
# endif/* defined(FRIF_PROD_ERROR_DETECT) && (STD_ON==FRIF_PROD_ERROR_DETECT) */

# if defined (FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT)
#  define FRIF_IS_INITIALIZED()        (FRIF_IS_INITIALIZED_MAGIC_NUMBER == FrIf_Status.IsInitialized)
# else
#  define FRIF_IS_INITIALIZED()        (0 != FrIf_Status.pConfigData)
# endif/* defined (FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT) */

# if (FRIF_DEV_ERROR_DETECT == STD_ON)

/* If DET is enabled, a MISRA-C:2004 analysis will yield deviations to the rules:
*  - 14.3 Before preprocessing, a null statement shall only occur on a line by itself; it may be followed by a comment provided that the first character following the null statement is a white-space character.
*  - 14.7 A function shall have a single point of exit at the end of the function
*  - 19.4 C macros shall only expand to a braced initializer, a constant, a parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct
*  - 19.7 A function should be used in preference to a function-like macro.
*  These deviations are caused by design of the runtime/ressource optimized DET handling and are globally justified.
*/

#  define FrIf_CheckDetErrorReturnVoid(  CONDITION, API_ID, ERROR_CODE )           { if(!(CONDITION)) { Det_ReportError( FRIF_MODULE_ID, 0, (API_ID), (ERROR_CODE)); return; } } /* PRQA S 3458 */ /* MD_MSR_19.4 */
#  define FrIf_CheckDetErrorReturnValue( CONDITION, API_ID, ERROR_CODE, RET_VAL )  { if(!(CONDITION)) { Det_ReportError( FRIF_MODULE_ID, 0, (API_ID), (ERROR_CODE)); return (RET_VAL); } } /* PRQA S 3458 */ /* MD_MSR_19.4 */
#  define FrIf_CallDetReportError( API_ID, ERROR_CODE )                            Det_ReportError( FRIF_MODULE_ID, 0, (API_ID),(ERROR_CODE))
# else
#  define FrIf_CheckDetErrorReturnVoid(  CONDITION, API_ID, ERROR_CODE )
#  define FrIf_CheckDetErrorReturnValue( CONDITION, API_ID, ERROR_CODE, RET_VAL ) 
#  define FrIf_CallDetReportError( API_ID, ERROR_CODE ) 
# endif

/* PRQA L:FUNCTIONLIKEMACRO *//* MD_MSR_19.7 */

/* macros for entering and leaving critical sections */
#  define FRIF_BEGIN_CRITICAL_SECTION_0() SchM_Enter_FrIf(FRIF_EXCLUSIVE_AREA_0)
#  define FRIF_END_CRITICAL_SECTION_0()   SchM_Exit_FrIf(FRIF_EXCLUSIVE_AREA_0)
#  define FRIF_BEGIN_CRITICAL_SECTION_1() SchM_Enter_FrIf(FRIF_EXCLUSIVE_AREA_1)
#  define FRIF_END_CRITICAL_SECTION_1()   SchM_Exit_FrIf(FRIF_EXCLUSIVE_AREA_1)


/* macros for accessing current state */

 /* PRQA S 3453 1 *//* MD_MSR_19.7 */
# define FrIf_IsOnline(CCIndex)     (FRIF_STATE_ONLINE == FrIf_Status.State)

/* macros for accessing configuration data in ROM */
# if defined(FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT)

 /* PRQA S 3453 13 *//* MD_MSR_19.7 */
#  define FrIf_GetTxFrameLayoutElement(Index)     (FrIf_TxFrameLayoutElements[(Index)])
#  define FrIf_GetTxFrameDescriptor(Index)        (FrIf_TxFrameDescriptors[(Index)])
#  define FrIf_GetTxPduDescriptor(Index)          (FrIf_TxPduDescriptors[(Index)])
#  define FrIf_GetRxFrameDescriptor(Index)        (FrIf_RxFrameDescriptors[(Index)])
#  define FrIf_GetRxFrameLayoutElement(Index)     (FrIf_RxFrameLayoutElements[(Index)])
#  define FrIf_GetRxPduDescriptor(Index)          (FrIf_RxPduDescriptors[(Index)])
#  define FrIf_GetJobData(Index)                  (FrIf_RxTxTaskScheduleData[(Index)])
#  define FrIf_GetTxColumn(ColumnNumber)          (FrIf_TxHandles[(ColumnNumber)])
#  define FrIf_GetRxColumn(ColumnNumber)          (FrIf_RxHandles[(ColumnNumber)])
#  define FrIf_GetTxCycleNumberMask(ColumnNumber) (FrIf_TxCycleMasks[(ColumnNumber)])
#  define FrIf_GetRxCycleNumberMask(ColumnNumber) (FrIf_RxCycleMasks[(ColumnNumber)])
#  define FrIf_GetMinControllerIndex(ClstIdx)     0
#  define FrIf_GetMaxControllerIndex(ClstIdx)     0
#  define FrIf_GetInvalidRxHandle()               (FrIf_InvalidRxHandle)
#  define FrIf_GetInvalidTxHandle()               (FrIf_InvalidTxHandle)
#  define FrIf_GetNumberOfTxPdus()                (FrIf_NumberOfTxPDUs)
#  define FrIf_GetMacroTicksLengthInNanoSeconds() (FrIf_MacroTicksLengthInNanoSeconds)
#  define FrIf_GetNumberOfMacroTicksPerCycle()    (FrIf_MacroTicksPerCycle)
#  define FrIf_GetNumberOfJobs()                  (FrIf_NumberOfJobs)
#  if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) && (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
#   define FrIf_GetUpdateBitBytePos()              (FrIf_UpdateBitBytePos)
#  endif

# else

#  define FrIf_GetConfig()                         FrIf_Status.pConfigData
 /* PRQA S 3453 13 *//* MD_MSR_19.7 */
#  define FrIf_GetTxFrameLayoutElement(Index)     (FrIf_Status.pTxFrameLayoutElements[(Index)])
#  define FrIf_GetTxFrameDescriptor(Index)        (FrIf_Status.pTxFrameDescriptors[(Index)])
#  define FrIf_GetTxPduDescriptor(Index)          (FrIf_Status.pTxPduDescriptors[(Index)])
#  define FrIf_GetRxFrameDescriptor(Index)        (FrIf_Status.pRxFrameDescriptors[(Index)])
#  define FrIf_GetRxFrameLayoutElement(Index)     (FrIf_Status.pRxFrameLayoutElements[(Index)])
#  define FrIf_GetRxPduDescriptor(Index)          (FrIf_Status.pRxPduDescriptors[(Index)])
#  define FrIf_GetJobData(Index)                  (FrIf_GetConfig()->pJobData[(Index)])
#  define FrIf_GetTxColumn(ColumnNumber)          (FrIf_GetConfig()->pTxHandles[(ColumnNumber)])
#  define FrIf_GetRxColumn(ColumnNumber)          (FrIf_GetConfig()->pRxHandles[(ColumnNumber)])
#  define FrIf_GetTxCycleNumberMask(ColumnNumber) (FrIf_GetConfig()->pTxCycleNumberMasks[(ColumnNumber)])
#  define FrIf_GetRxCycleNumberMask(ColumnNumber) (FrIf_GetConfig()->pRxCycleNumberMasks[(ColumnNumber)])
#  define FrIf_GetMinControllerIndex(ClstIdx)     0
#  define FrIf_GetMaxControllerIndex(ClstIdx)     0
#  define FrIf_GetInvalidRxHandle()               (FrIf_Status.InvalidRxHandle)
#  define FrIf_GetInvalidTxHandle()               (FrIf_Status.InvalidTxHandle)
#  define FrIf_GetNumberOfTxPdus()                (FrIf_Status.pConfigData->NumberOfTxPDUs)
#  define FrIf_GetMacroTicksLengthInNanoSeconds() (FrIf_GetConfig()->MacroTicksLengthInNanoSeconds)
#  define FrIf_GetNumberOfMacroTicksPerCycle()    (FrIf_GetConfig()->MacroTicksPerCycle)
#  define FrIf_GetNumberOfJobs()                  (FrIf_GetConfig()->NumberOfJobs)
#  if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) && (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
#   define FrIf_GetUpdateBitBytePos()             (FrIf_GetConfig()->UpdateBitBytePos)
#  endif

# endif
/* if defined(FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT) */

# if (STD_OFF == FRIF_PDUDIRTYBYTE_USAGE)

/** Bit vectors
    Modules that are using bit vectors must use DECLARE_BITVECTOR_LOOKUP_TABLE
    so that the arrays SetBitMask and ClearBitMask are defined as constants inside
    of this module.
*/

 /* PRQA S 3412 8 *//* MD_MSR_19.4 */
#  define FRIF_DECLARE_BITVECTOR_LOOKUP_TABLE_SET_BIT               \
STATIC CONST(uint8, FRIF_CONST) SetBitMask[]   =                    \
  {0x01u, 0x02u, 0x04u, 0x08u,                                      \
   0x10u, 0x20u, 0x40u, 0x80u}
#  define FRIF_DECLARE_BITVECTOR_LOOKUP_TABLE_CLR_BIT               \
STATIC CONST(uint8, FRIF_CONST) ClearBitMask[] =                    \
  {0xFEu, 0xFDu, 0xFBu, 0xF7u,                                      \
   0xEFu, 0xDFu, 0xBFu, 0x7Fu}

 /* PRQA S 3453 6 *//* MD_MSR_19.7 */
#  define SetBit(  /* uint8* */ pData, bitNumber)  \
     ((pData)[(bitNumber) >> 3]   |= SetBitMask[(bitNumber)  &(uint8)0x07u])
#  define ClearBit(/* uint8* */ pData, bitNumber)  \
     ((pData)[(bitNumber) >> 3]   &= ClearBitMask[(bitNumber)&(uint8)0x07u])
#  define GetBit(  /* uint8* */ pData, bitNumber)  \
     ((pData)[(bitNumber) >> 3]   &  SetBitMask[(bitNumber)  &(uint8)0x07u])
# endif
/* if (STD_OFF == FRIF_PDUDIRTYBYTE_USAGE) */

/* Calculate the number of bytes needed to store the given number of bits */
 /* PRQA S 3453 4 *//* MD_MSR_19.7 */
# define NumberOfBytesForBits(numberOfBits) (((numberOfBits)+7) / 8)

# define FrIf_IsLastFrIfRxTaskForNm(FrIf_ClstIdx) (boolean)(0 != (FrIf_GetJobData(FrIf_Status.CurrentJobNumber).JobConfig & FrIf_JobDataIsLastFrIfRxTaskForNm))
# define FrIf_IsLastFrIfRxTaskForTp(FrIf_ClstIdx) (boolean)(0 != (FrIf_GetJobData(FrIf_Status.CurrentJobNumber).JobConfig & FrIf_JobDataIsLastFrIfRxTaskForTp))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES (FrIf)
 **********************************************************************************************************************/
typedef struct
{
# if defined(FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT)
  uint16 IsInitialized;
# else
  FRIF_P2CONSTCFGROOT(FrIf_PostBuildConfigType) pConfigData;
  FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) pTxFrameDescriptors;
  FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) pTxFrameLayoutElements;
  FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) pTxPduDescriptors;
  FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) pRxFrameDescriptors;
  FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) pRxFrameLayoutElements;
  FRIF_P2CONSTCFG(FrIf_RxPduDescriptorType) pRxPduDescriptors;
# endif
  uint16 InvalidTxHandle;
  uint16 InvalidRxHandle;
  uint8 State;
  uint8 CurrentJobNumber;
  uint8 CurrentCycle;
  uint8 JobExecutionStarted;
} FrIf_StateDataType;

# define FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

extern VAR(FrIf_StateDataType, FRIF_VAR_NOINIT) FrIf_Status;

# define FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_19.1 */

/**********************************************************************************************************************
  FrIf_RxTask_0
**********************************************************************************************************************/
/*! \brief      Perform reception for the current job.
 *  \see        The function is called by the FrIf_JobListExec_0 function of the FrIf
 *  \param[in]  void
 *  \return     E_OK:       The call of the service FrIf_RxTask_0() returns E_OK if the FrIf state was FRIF_ONLINE 
 *              E_NOT_OK:   The call of the service FrIf_RxTask_0() returns E_NOT_OK if the FrIf state was 
 *                          FRIF_OFFLINE
 *  \note       -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_RxTask_0(void);

/**********************************************************************************************************************
  FrIf_TxTask_0
**********************************************************************************************************************/
/*! \brief      Perform transmission for the current job.
 *  \see        The function is called by the FrIf_JobListExec_0 function of the FrIf
 *  \param[in]  void
 *  \return     E_OK:       The call of the service FrIf_TxTask_0() returns E_OK if the FrIf state was FRIF_ONLINE 
 *                          and Fr_TransmitTxLPdu returned E_OK.
 *              E_NOT_OK:   The call of the service FrIf_TxTask_0() returns E_NOT_OK if the FrIf state was 
 *                          FRIF_OFFLINE or Fr_TransmitTxLPdu returned E_NOT_OK.
 *  \note       -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_TxTask_0(void);

/**********************************************************************************************************************
  FrIf_TxConfTask_0
**********************************************************************************************************************/
/*! \brief      Perform transmission confirmation for all frames that have been copied to the driver during a 
 *              previous task. This previous task is determined by the TxConfJobNo attribute of the current task.
 *  \see        The function is called by the FrIf_JobListExec_0 function of the FrIf
 *  \param[in]  void
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_TxConfTask_0(void);

/**********************************************************************************************************************
  FrIf_Receive
**********************************************************************************************************************/
/*! \brief      Perform reception for the frame that is described by the frame descriptor with index Handle.
 *  \see        The function is called by the FrIf_RxTask_0() and ApplFrDrv_ISR_Rx()
 *  \param[in]  FrameDescriptorPtr:    The pointer to the frame descriptor                                           */
/*  \return     FR_NOT_RECEIVED or FR_RECEIVED depending on whether a frame was received.
 *  \note       -
 ********************************************************************************************************************/
FUNC(Fr_RxLPduStatusType, FRIF_CODE) FrIf_Receive(
                                        FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr, 
                                        uint16 Handle
  );

/**********************************************************************************************************************
  FrIf_ConfirmPendingTransmissions
**********************************************************************************************************************/
/*! \brief      When stopping or resynchronizing  the FrIf-JobList execution, the FrIf shall call the TxConfirmation-
 *              callback of the upper layers as if the pending transmission had been completed.
 *  \see        The function is called by the FrIf_StopJobExecution() function of the FrIf
 *  \param[in]  void
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_ConfirmPendingTransmissions(void);

# define FRIF_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_19.1 */

#endif
/* FRIF_PRIV_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Priv.h
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
