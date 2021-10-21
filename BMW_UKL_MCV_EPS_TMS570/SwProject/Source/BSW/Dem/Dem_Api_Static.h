#ifndef DEM_API_STATIC_H
/** \brief preprocessor exclusion definition */
#define DEM_API_STATIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all static external API declarations of the
 ** AUTOSAR module Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Api_Static.h.m4 2490 2011-04-01 09:39:49Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Version.h>                      /* Module version declaration */

/*==================[macros]================================================*/

/*------------------[AUTOSAR specification version identification check]----*/

#if (!defined DEM_AR_MAJOR_VERSION) /* configuration check */
#error DEM_AR_MAJOR_VERSION must be defined
#endif /* if (!defined DEM_AR_MAJOR_VERSION) */

/* major version check */
#if (DEM_AR_MAJOR_VERSION != 2U)
#error DEM_AR_MAJOR_VERSION wrong (!= 2U)
#endif /* if DEM_AR_MAJOR_VERSION */

#if (!defined DEM_AR_MINOR_VERSION) /* configuration check */
#error DEM_AR_MINOR_VERSION must be defined
#endif /* if (!defined DEM_AR_MINOR_VERSION) */

/* minor version check */
#if (DEM_AR_MINOR_VERSION < 1U)
#error DEM_AR_MINOR_VERSION wrong (< 1U)
#endif /* if DEM_AR_MINOR_VERSION */

#if (!defined DEM_AR_PATCH_VERSION) /* configuration check */
#error DEM_AR_PATCH_VERSION must be defined
#endif /* if (!defined DEM_AR_PATCH_VERSION) */

/* patch version check */
#if (DEM_AR_PATCH_VERSION < 1U)
#error DEM_AR_PATCH_VERSION wrong (< 1U)
#endif /* if DEM_AR_PATCH_VERSION */

/*------------------[AUTOSAR module version identification check]-----------*/

#if (!defined DEM_SW_MAJOR_VERSION) /* configuration check */
#error DEM_SW_MAJOR_VERSION must be defined
#endif /* if (!defined DEM_SW_MAJOR_VERSION) */

/* major version check */
#if (DEM_SW_MAJOR_VERSION != 3U)
#error DEM_SW_MAJOR_VERSION wrong (!= 3U)
#endif /* if DEM_SW_MAJOR_VERSION */

#if (!defined DEM_SW_MINOR_VERSION) /* configuration check */
#error DEM_SW_MINOR_VERSION must be defined
#endif /* if (!defined DEM_SW_MINOR_VERSION) */

/* minor version check */
#if (DEM_SW_MINOR_VERSION < 3U)
#error DEM_SW_MINOR_VERSION wrong (< 3U)
#endif /* if DEM_SW_MINOR_VERSION */

#if (!defined DEM_SW_PATCH_VERSION) /* configuration check */
#error DEM_SW_PATCH_VERSION must be defined
#endif /* if (!defined DEM_SW_PATCH_VERSION) */

/* patch version check */
#if (DEM_SW_PATCH_VERSION < 3U)
#error DEM_SW_PATCH_VERSION wrong (< 3U)
#endif /* if DEM_SW_PATCH_VERSION */

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined DEM_VENDOR_ID) /* to prevent double declaration */
#error DEM_VENDOR_ID is already defined
#endif /* if (defined DEM_VENDOR_ID) */

/** \brief AUTOSAR vendor identification */
#define DEM_VENDOR_ID DEM_VENDOR_ID_3SOFT

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined DEM_MODULE_ID) /* to prevent double declaration */
#error DEM_MODULE_ID already defined
#endif /* if (defined DEM_MODULE_ID) */

/** \brief AUTOSAR module identification */
#define DEM_MODULE_ID 54U

/*------------------[AUTOSAR event ID declaration]--------------------------*/

#if (defined DEM_EVENT_ID_INVALID) /* to prevent double declaration */
#error DEM_EVENT_ID_INVALID already defined
#endif /* if (defined DEM_EVENT_ID_INVALID) */

/** Symbolic name of invalid event ID */
#define DEM_EVENT_ID_INVALID 0U


/*------------------[DTC status bits]---------------------------------------*/

/* Definition of DTC status bits according to ISO14229-1 Annex D.3 */

#if (defined DEM_DTCSTATUSBIT_TF)
#error DEM_DTCSTATUSBIT_TF already defined
#endif
/** \brief DTC status - test failed */
#define DEM_DTCSTATUSBIT_TF                                    0x01U

#if (defined DEM_DTCSTATUSBIT_TFTOC)
#error DEM_DTCSTATUSBIT_TFTOC already defined
#endif
/** \brief DTC status - test failed this operation cycle */
#define DEM_DTCSTATUSBIT_TFTOC                                 0x02U

#if (defined DEM_DTCSTATUSBIT_PDTC)
#error DEM_DTCSTATUSBIT_PDTC already defined
#endif
/** \brief DTC status - pending DTC */
#define DEM_DTCSTATUSBIT_PDTC                                  0x04U

#if (defined DEM_DTCSTATUSBIT_CDTC)
#error DEM_DTCSTATUSBIT_CDTC already defined
#endif
/** \brief DTC status - confirmed DTC */
#define DEM_DTCSTATUSBIT_CDTC                                  0x08U

#if (defined DEM_DTCSTATUSBIT_TNCSLC)
#error DEM_DTCSTATUSBIT_TNCSLC already defined
#endif
/** \brief DTC status - test not completed since last clear */
#define DEM_DTCSTATUSBIT_TNCSLC                                0x10U

#if (defined DEM_DTCSTATUSBIT_TFSLC)
#error DEM_DTCSTATUSBIT_TFSLC already defined
#endif
/** \brief DTC status - test failed since last clear */
#define DEM_DTCSTATUSBIT_TFSLC                                 0x20U

#if (defined DEM_DTCSTATUSBIT_TNCTOC)
#error DEM_DTCSTATUSBIT_TNCTOC already defined
#endif
/** \brief DTC status - test not completed this operation cycle */
#define DEM_DTCSTATUSBIT_TNCTOC                                0x40U

#if (defined DEM_DTCSTATUSBIT_WIR)
#error DEM_DTCSTATUSBIT_WIR already defined
#endif
/** \brief DTC status - warning indicator requested */
#define DEM_DTCSTATUSBIT_WIR                                   0x80U


/*==================[type definitions]======================================*/

/*------------------[Dem_EventIdType]---------------------------------------*/

/* type is defined in Dem_RteInternal_Static.h */


/*------------------[Dem_DTCType]-------------------------------------------*/

/* type is defined in Dem_RteInternal_Static.h */


/*------------------[Dem_ViewIdType]----------------------------------------*/

/** \brief Identification of a view by assigned identification number.
 **
 ** The view ID is configured in the DEM. The ID describes a functional group
 ** in the car, like a wiper system or a window lift for the access of
 ** corresponding DTCs and related data.
 **
 ** Example:
 ** 1 refers to functionality x,
 ** 2 refers to functionality y, ...
 ** DEM only has to support limit number of views according to configuration
 ** of DEM_NUMBER_OF_VIEWS */
typedef uint8 Dem_ViewIdType;


/*------------------[Dem_EventStatusType]-----------------------------------*/

/* type and corresponding defines are defined in Dem_RteInternal_Static.h */


/*------------------[Dem_DTCKindType]---------------------------------------*/

/* type and corresponding defines are defined in Dem_RteInternal_Static.h */


/*------------------[Dem_EventStatusExtendedType]---------------------------*/

/* type is defined in Dem_RteInternal_Static.h */


/*------------------[Dem_DTCGroupType]--------------------------------------*/

/** \brief Used to define the group of DTCs
 **
 ** The user can add further groups. Unused bytes shall be filled with 00. */
typedef uint32 Dem_DTCGroupType;

/* all DEM_DTC_GROUP_<GROUP_NAME> defines are generated in Dem_Api_Cfg.h */

#if (defined DEM_DTC_GROUP_ALL_DTCS)
#error DEM_DTC_GROUP_ALL_DTCS already defined
#endif
/** All DTCs
 **
 ** Note: This is a deviation against the SWS, but compliant to UDS. */
#define DEM_DTC_GROUP_ALL_DTCS          0xFFFFFFU


/*------------------[Dem_DTCOriginType]-------------------------------------*/

/** \brief Used to define the origin of the DTC
 **
 ** The Dem_DTCOriginType is used to differ between the different event
 ** memories. Used to define the origin of the DTC. The definition and use of
 ** the different memory types is OEM specific. */
typedef uint8 Dem_DTCOriginType;

#if (defined DEM_DTC_ORIGIN_PRIMARY_MEMORY)
#error DEM_DTC_ORIGIN_PRIMARY_MEMORY already defined
#endif
/** Event information located in the primary memory */
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY    0x01U

#if (defined DEM_DTC_ORIGIN_SECONDARY_MEMORY)
#error DEM_DTC_ORIGIN_SECONDARY_MEMORY already defined
#endif
/** Event information located in the secondary memory */
#define DEM_DTC_ORIGIN_SECONDARY_MEMORY  0x02U

#if (defined DEM_DTC_ORIGIN_MIRROR_MEMORY)
#error DEM_DTC_ORIGIN_MIRROR_MEMORY already defined
#endif
/** Event information located in the mirror memory */
#define DEM_DTC_ORIGIN_MIRROR_MEMORY     0x03U


/*------------------[Dem_DTCTranslationFormatType]--------------------------*/

/** \brief Used to define the DTCTranslationFormat */
typedef uint8 Dem_DTCTranslationFormatType;

#if (defined DEM_DTC_TRANSLATION_ISO15031_6)
#error DEM_DTC_TRANSLATION_ISO15031_6 already defined
#endif
/** DTCs of ISO15031-6 */
#define DEM_DTC_TRANSLATION_ISO15031_6     0x01U

#if (defined DEM_DTC_TRANSLATION_ISO14229_1)
#error DEM_DTC_TRANSLATION_ISO14229_1 already defined
#endif
/** DTCs of ISO14229-1 */
#define DEM_DTC_TRANSLATION_ISO14229_1     0x02U

#if (defined DEM_DTC_TRANSLATION_CUSTOMER)
#error DEM_DTC_TRANSLATION_CUSTOMER already defined
#endif
/** Customer specific DTCs */
#define DEM_DTC_TRANSLATION_CUSTOMER       0x03U

#if (defined DEM_DTC_TRANSLATION_INTERNAL)
#error DEM_DTC_TRANSLATION_INTERNAL already defined
#endif
/** Internal by EventId */
#define DEM_DTC_TRANSLATION_INTERNAL       0x04U

#if (defined DEM_DTC_TRANSLATION_SAEJ1939)
#error DEM_DTC_TRANSLATION_SAEJ1939 already defined
#endif
/** DTCs of SAEJ1939 (Extension to Autosar) */
#define DEM_DTC_TRANSLATION_SAEJ1939       0x05U

#if (defined DEM_DTC_TRANSLATION_WWH_OBD_FORMAT)
#error DEM_DTC_TRANSLATION_WWH_OBD_FORMAT already defined
#endif
/** DTCs of WWH-OBD-format (Extension to Autosar) */
#define DEM_DTC_TRANSLATION_WWH_OBD_FORMAT 0x06U


/*------------------[Dem_DTCSeverityType]-----------------------------------*/

/** \brief Used to define the DTC severity */
typedef uint8 Dem_DTCSeverityType;

#if (defined DEM_SEVERITY_NO_SEVERITY)
#error DEM_SEVERITY_NO_SEVERITY already defined
#endif
/** No severity information available */
#define DEM_SEVERITY_NO_SEVERITY        0x00U

#if (defined DEM_SEVERITY_MAINTENANCE_ONLY)
#error DEM_SEVERITY_MAINTENANCE_ONLY already defined
#endif
/** Maintenance required */
#define DEM_SEVERITY_MAINTENANCE_ONLY   0x20U

#if (defined DEM_SEVERITY_CHECK_AT_NEXT_HALT)
#error DEM_SEVERITY_CHECK_AT_NEXT_HALT already defined
#endif
/** Check at next halt */
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT 0x40U

#if (defined DEM_SEVERITY_CHECK_IMMEDIATELY)
#error DEM_SEVERITY_CHECK_IMMEDIATELY already defined
#endif
/** Check immediately */
#define DEM_SEVERITY_CHECK_IMMEDIATELY  0x80U


/*------------------[Dem_DTCRequestType]------------------------------------*/

/** \brief Request type for Dem_GetDTCByOccurrenceTime() */
typedef uint8 Dem_DTCRequestType;

#if (defined DEM_FIRST_FAILED_DTC)
#error DEM_FIRST_FAILED_DTC already defined
#endif
/** First failed DTC requested */
#define DEM_FIRST_FAILED_DTC           0x01U

#if (defined DEM_MOST_RECENT_FAILED_DTC)
#error DEM_MOST_RECENT_FAILED_DTC already defined
#endif
/** Most recent failed DTC requested */
#define DEM_MOST_RECENT_FAILED_DTC     0x02U

#if (defined DEM_FIRST_DET_CONFIRMED_DTC)
#error DEM_FIRST_DET_CONFIRMED_DTC already defined
#endif
/** First detected confirmed DTC requested */
#define DEM_FIRST_DET_CONFIRMED_DTC    0x03U

#if (defined DEM_MOST_REC_DET_CONFIRMED_DTC)
#error DEM_MOST_REC_DET_CONFIRMED_DTC already defined
#endif
/** Most recently detected confirmed DTC requested */
#define DEM_MOST_REC_DET_CONFIRMED_DTC 0x04U


/*------------------[Dem_EventPriorityType]---------------------------------*/

/** \brief Used to define the priority of an event
 **
 ** value: Define the priority of each event. 0 is the lowest priority. */
typedef uint8 Dem_EventPriorityType;


/*------------------[Dem_DataByteType]--------------------------------------*/

/** \brief Used to return the value of DataA/DataB/DataC/DataD, depending on
 ** request
 **
 ** value: DataByte (DataA, DataB, DataC, DataD) according ISO15031-5
 **        definition */
typedef uint8 Dem_DataByteType;


/*------------------[Dem_IndicatorIdType]-----------------------------------*/

/* type is defined in Dem_Api_Depend.h */


/*------------------[Dem_IndicatorStatusType]-------------------------------*/

/* type and corresponding defines are defined in Dem_Api_Depend.h */


/*------------------[Dem_OperationCycleIdType]------------------------------*/

/* type and corresponding defines are defined in Dem_RteInternal_Static.h */


/*------------------[Dem_OperationCycleStateType]---------------------------*/

/* type and corresponding defines are defined in Dem_RteInternal_Static.h */


/*------------------[Dem_FilterWithSeverityType]----------------------------*/

/** \brief Used to specify the usage of severity information */
typedef uint8 Dem_FilterWithSeverityType;

#if (defined DEM_FILTER_WITH_SEVERITY_YES)
#error DEM_FILTER_WITH_SEVERITY_YES already defined
#endif
/** Severity information used */
#define DEM_FILTER_WITH_SEVERITY_YES  0x00U

#if (defined DEM_FILTER_WITH_SEVERITY_NO)
#error DEM_FILTER_WITH_SEVERITY_NO already defined
#endif
/** Severity information not used */
#define DEM_FILTER_WITH_SEVERITY_NO   0x01U


/*------------------[Dem_InitMonitorKindType]-------------------------------*/

/* type and corresponding defines are defined in Dem_RteInternal_Static.h */


/*------------------[Dem_DTCStatusMaskType]---------------------------------*/

/* type is defined in Dem_RteInternal_Static.h */


/*------------------[Dem_FilterForFaultDetectionCounterType]----------------*/

/** \brief Used to specify the usage of Fault Detection Counter information */
typedef uint8 Dem_FilterForFaultDetectionCounterType;

#if (defined DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_YES)
#error DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_YES already defined
#endif
/** Fault Detection Counter information used */
#define DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_YES  0x00U

#if (defined DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO)
#error DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO already defined
#endif
/** Fault Detection Counter information not used */
#define DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO   0x01U


/*------------------[Dem_FaultDetectionCounterType]-------------------------*/

/* type is defined in Dem_RteInternal_Static.h */


/* ----- DEM return types ----- */

/*------------------[Dem_ReturnSetDTCFilterType]----------------------------*/

/** \brief Used to return the status of updating the DTC filter */
typedef uint8 Dem_ReturnSetDTCFilterType;

#if (defined DEM_FILTER_ACCEPTED)
#error DEM_FILTER_ACCEPTED already defined
#endif
/** Filter was accepted */
#define DEM_FILTER_ACCEPTED 0x00U

#if (defined DEM_WRONG_FILTER)
#error DEM_WRONG_FILTER already defined
#endif
/** Wrong filter selected */
#define DEM_WRONG_FILTER    0x01U


/*------------------[Dem_ReturnSetViewFilterType]---------------------------*/

/** \brief Used to return the status of updating the View filter for a
 * functional addressing */
typedef uint8 Dem_ReturnSetViewFilterType;

#if (defined DEM_VIEW_ID_ACCEPTED)
#error DEM_VIEW_ID_ACCEPTED already defined
#endif
/** View ID was accepted */
#define DEM_VIEW_ID_ACCEPTED 0x00U

#if (defined DEM_WRONG_ID)
#error DEM_WRONG_ID already defined
#endif
/** Wrong View ID selected */
#define DEM_WRONG_ID         0x01U


/*------------------[Dem_ReturnGetStatusOfDTCType]--------------------------*/

/** \brief Used to return the status of Dem_GetStatusOfDTC() */
typedef uint8 Dem_ReturnGetStatusOfDTCType;

#if (defined DEM_STATUS_OK)
#error DEM_STATUS_OK already defined
#endif
/** Status of DTC is OK */
#define DEM_STATUS_OK                0x00U

#if (defined DEM_STATUS_WRONG_DTC)
#error DEM_STATUS_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_STATUS_WRONG_DTC         0x01U

#if (defined DEM_STATUS_WRONG_DTCORIGIN)
#error DEM_STATUS_WRONG_DTCORIGIN already defined
#endif
/** Wrong DTC origin */
#define DEM_STATUS_WRONG_DTCORIGIN   0x02U

#if (defined DEM_STATUS_WRONG_DTCKIND)
#error DEM_STATUS_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_STATUS_WRONG_DTCKIND     0x03U

#if (defined DEM_STATUS_FAILED)
#error DEM_STATUS_FAILED already defined
#endif
/** DTC failed */
#define DEM_STATUS_FAILED            0x04U


/*------------------[Dem_ReturnGetNextFilteredDTCType]----------------------*/

/** \brief Used to return the status of Dem_GetNextFilteredDTC() */
typedef uint8 Dem_ReturnGetNextFilteredDTCType;

#if (defined DEM_FILTERED_OK)
#error DEM_FILTERED_OK already defined
#endif
/** Returned next filtered DTC */
#define DEM_FILTERED_OK                0x00U

#if (defined DEM_FILTERED_NO_MATCHING_DTC)
#error DEM_FILTERED_NO_MATCHING_DTC already defined
#endif
/** No DTC matched */
#define DEM_FILTERED_NO_MATCHING_DTC   0x01U

#if (defined DEM_FILTERED_WRONG_DTCKIND)
#error DEM_FILTERED_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_FILTERED_WRONG_DTCKIND     0x02U


/*------------------[Dem_ReturnClearDTCType]--------------------------------*/

/** \brief Used to return the status of Dem_ClearDTC() */
typedef uint8 Dem_ReturnClearDTCType;

#if (defined DEM_CLEAR_OK)
#error DEM_CLEAR_OK already defined
#endif
/** DTC successfully cleared */
#define DEM_CLEAR_OK                0x00U

#if (defined DEM_CLEAR_WRONG_DTC)
#error DEM_CLEAR_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_CLEAR_WRONG_DTC         0x01U

#if (defined DEM_CLEAR_WRONG_DTCORIGIN)
#error DEM_CLEAR_WRONG_DTCORIGIN already defined
#endif
/** Wrong DTC origin */
#define DEM_CLEAR_WRONG_DTCORIGIN   0x02U

#if (defined DEM_CLEAR_WRONG_DTCKIND)
#error DEM_CLEAR_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_CLEAR_WRONG_DTCKIND     0x03U

#if (defined DEM_CLEAR_FAILED)
#error DEM_CLEAR_FAILED already defined
#endif
/** DTC not cleared */
#define DEM_CLEAR_FAILED            0x04U


/*------------------[Dem_ReturnControlDTCStorageType]-----------------------*/

/** \brief Used to return the status of Dem_DisableDTCStorage() and
 * Dem_EnableDTCStorage() */
typedef uint8 Dem_ReturnControlDTCStorageType;

#if (defined DEM_CONTROL_DTC_STORAGE_OK)
#error DEM_CONTROL_DTC_STORAGE_OK already defined
#endif
/** DTC storage successful */
#define DEM_CONTROL_DTC_STORAGE_OK     0x00U

#if (defined DEM_CONTROL_DTC_STORAGE_N_OK)
#error DEM_CONTROL_DTC_STORAGE_N_OK already defined
#endif
/** DTC storage not successful */
#define DEM_CONTROL_DTC_STORAGE_N_OK   0x01U

#if (defined DEM_CONTROL_DTC_WRONG_DTCGROUP)
#error DEM_CONTROL_DTC_WRONG_DTCGROUP already defined
#endif
/** DTC storage control not successful because group of DTC was wrong */
#define DEM_CONTROL_DTC_WRONG_DTCGROUP 0x02U


/*------------------[Dem_ReturnControlEventUpdateType]----------------------*/

/** \brief Used to return the status of Dem_DisableEventStatusUpdate() and
 ** Dem_EnableEventStatusUpdate() */
typedef uint8 Dem_ReturnControlEventUpdateType;

#if (defined DEM_CONTROL_EVENT_UPDATE_OK)
#error DEM_CONTROL_EVENT_UPDATE_OK already defined
#endif
/** Event storage control successful */
#define DEM_CONTROL_EVENT_UPDATE_OK      0x00U

#if (defined DEM_CONTROL_EVENT_UPDATE_N_OK)
#error DEM_CONTROL_EVENT_UPDATE_N_OK already defined
#endif
/** Event storage control not successful */
#define DEM_CONTROL_EVENT_UPDATE_N_OK    0x01U

#if (defined DEM_CONTROL_EVENT_WRONG_DTCGROUP)
#error DEM_CONTROL_EVENT_WRONG_DTCGROUP already defined
#endif
/** Event storage control not successful because group of DTC was wrong */
#define DEM_CONTROL_EVENT_WRONG_DTCGROUP 0x02U


/*------------------[Dem_ReturnGetDTCOfFreezeFrameRecordType]---------------*/

/** \brief Used to return the status of Dem_GetDTCOfFreezeFrameRecord() */
typedef uint8 Dem_ReturnGetDTCOfFreezeFrameRecordType;

#if (defined DEM_GET_DTCOFFF_OK)
#error DEM_GET_DTCOFFF_OK already defined
#endif
/** DTC successfully returned */
#define DEM_GET_DTCOFFF_OK                0x00U

#if (defined DEM_GET_DTCOFFF_WRONG_RECORD)
#error DEM_GET_DTCOFFF_WRONG_RECORD already defined
#endif
/** Wrong record */
#define DEM_GET_DTCOFFF_WRONG_RECORD      0x01U

#if (defined DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD)
#error DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD already defined
#endif
/** No DTC for record available */
#define DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD 0x02U

#if (defined DEM_GET_DTCOFFF_WRONG_DTCKIND)
#error DEM_GET_DTCOFFF_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_GET_DTCOFFF_WRONG_DTCKIND     0x03U


/*------------------[Dem_ReturnGetFreezeFrameDataIdentifierByDTCType]-------*/

/** \brief Used to return the status of
 ** Dem_GetFreezeFrameDataIdentifierByDTC() */
typedef uint8 Dem_ReturnGetFreezeFrameDataIdentifierByDTCType;

#if (defined DEM_GET_ID_OK)
#error DEM_GET_ID_OK already defined
#endif
/** Freeze frame data identifier successfully returned */
#define DEM_GET_ID_OK                0x00U

#if (defined DEM_GET_ID_WRONG_DTC)
#error DEM_GET_ID_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_GET_ID_WRONG_DTC         0x01U

#if (defined DEM_GET_ID_WRONG_DTCORIGIN)
#error DEM_GET_ID_WRONG_DTCORIGIN already defined
#endif
/** Wrong DTC origin */
#define DEM_GET_ID_WRONG_DTCORIGIN   0x02U

#if (defined DEM_GET_ID_WRONG_DTCKIND)
#error DEM_GET_ID_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_GET_ID_WRONG_DTCKIND     0x03U

#if (defined DEM_GET_ID_WRONG_FF_TYPE)
#error DEM_GET_ID_WRONG_FF_TYPE already defined
#endif
/** Freeze frame type wrong */
#define DEM_GET_ID_WRONG_FF_TYPE     0x04U


/*------------------[Dem_ReturnGetExtendedDataRecordByDTCType]--------------*/

/** \brief Used to return the status of Dem_GetExtendedDataRecordByDTC() */
typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;

#if (defined DEM_RECORD_OK)
#error DEM_RECORD_OK already defined
#endif
/** Extended data record successfully returned */
#define DEM_RECORD_OK                0x00U

#if (defined DEM_RECORD_WRONG_DTC)
#error DEM_RECORD_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_RECORD_WRONG_DTC         0x01U

#if (defined DEM_RECORD_WRONG_DTCORIGIN)
#error DEM_RECORD_WRONG_DTCORIGIN already defined
#endif
/** Wrong DTC origin */
#define DEM_RECORD_WRONG_DTCORIGIN   0x02U

#if (defined DEM_RECORD_WRONG_DTCKIND)
#error DEM_RECORD_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_RECORD_WRONG_DTCKIND     0x03U

#if (defined DEM_RECORD_WRONG_NUMBER)
#error DEM_RECORD_WRONG_NUMBER already defined
#endif
/** Record number wrong */
#define DEM_RECORD_WRONG_NUMBER      0x04U

#if (defined DEM_RECORD_WRONG_BUFFERSIZE)
#error DEM_RECORD_WRONG_BUFFERSIZE already defined
#endif
/** Provided buffer size to small */
#define DEM_RECORD_WRONG_BUFFERSIZE  0x05U


/*------------------[Dem_ReturnGetDTCByOccurrenceTimeType]------------------*/

/** \brief Status of the operation of type
 ** Dem_ReturnGetDTCByOccurrenceTime() */
typedef uint8 Dem_ReturnGetDTCByOccurrenceTimeType;

#if (defined DEM_OCCURR_OK)
#error DEM_OCCURR_OK already defined
#endif
/** Status of DTC is OK */
#define DEM_OCCURR_OK                0x00U

#if (defined DEM_OCCURR_WRONG_DTCKIND)
#error DEM_OCCURR_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_OCCURR_WRONG_DTCKIND     0x01U

#if (defined DEM_OCCURR_FAILED)
#error DEM_OCCURR_FAILED already defined
#endif
/** DTC failed */
#define DEM_OCCURR_FAILED            0x02U


/*------------------[Dem_ReturnGetDTCOfEventType]---------------------------*/

/* type and corresponding defines are defined in Dem_RteInternal_Static.h */


/*------------------[Dem_ReturnGetFreezeFrameDataByDTCType]-----------------*/

/** \brief Used to return the status of Dem_GetFreezeFrameDataByDTC() */
typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;

#if (defined DEM_GET_FFDATABYDTC_OK)
#error DEM_GET_FFDATABYDTC_OK already defined
#endif
/** FreezeFrame data successfully returned */
#define DEM_GET_FFDATABYDTC_OK                 0x00U

#if (defined DEM_GET_FFDATABYDTC_WRONG_DTC)
#error DEM_GET_FFDATABYDTC_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_GET_FFDATABYDTC_WRONG_DTC          0x01U

#if (defined DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN)
#error DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN already defined
#endif
/** Wrong DTC origin */
#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN    0x02U

#if (defined DEM_GET_FFDATABYDTC_WRONG_DTCKIND)
#error DEM_GET_FFDATABYDTC_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_GET_FFDATABYDTC_WRONG_DTCKIND      0x03U

#if (defined DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER)
#error DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER already defined
#endif
/** Wrong Record Number */
#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER 0x04U

#if (defined DEM_GET_FFDATABYDTC_WRONG_DATAID)
#error DEM_GET_FFDATABYDTC_WRONG_DATAID already defined
#endif
/** Wrong DataID */
#define DEM_GET_FFDATABYDTC_WRONG_DATAID       0x05U

#if (defined DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE)
#error DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE already defined
#endif
/** provided buffer size to small */
#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE   0x06U


/*------------------[Dem_ReturnGetSizeOfExtendedDataRecordByDTCType]--------*/

/** \brief Used to return the status of Dem_GetSizeOfExtendedDataRecordByDTC()
 */
typedef uint8 Dem_ReturnGetSizeOfExtendedDataRecordByDTCType;

#if (defined DEM_GET_SIZEOFEDRBYDTCTYPE_OK)
#error DEM_GET_SIZEOFEDRBYDTCTYPE_OK already defined
#endif
/** Size successfully returned */
#define DEM_GET_SIZEOFEDRBYDTCTYPE_OK                 0x00U

#if (defined DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC)
#error DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC          0x01U

#if (defined DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCORIGIN)
#error DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCORIGIN already defined
#endif
/** Wrong DTC origin */
#define DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCORIGIN    0x02U

#if (defined DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCKIND)
#error DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCKIND      0x03U

#if (defined DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_RECORDNUMBER)
#error DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_RECORDNUMBER already defined
#endif
/** Wrong Record Number */
#define DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_RECORDNUMBER 0x04U


/*------------------[Dem_ReturnGetSizeOfFreezeFrameType]--------------------*/

/** \brief Used to return the status of GetSizeOfFreezeFrame() */
typedef uint8 Dem_ReturnGetSizeOfFreezeFrameType;

#if (defined DEM_GET_SIZEOFFREEZEFRAMETYPE_OK)
#error DEM_GET_SIZEOFFREEZEFRAMETYPE_OK already defined
#endif
/** Size successfully returned */
#define DEM_GET_SIZEOFFREEZEFRAMETYPE_OK                 0x00U

#if (defined DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC)
#error DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC          0x01U

#if (defined DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCORIGIN)
#error DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCORIGIN already defined
#endif
/** Wrong DTC origin */
#define DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCORIGIN    0x02U

#if (defined DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCKIND)
#error DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCKIND      0x03U

#if (defined DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_RECORDNUMBER)
#error DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_RECORDNUMBER already defined
#endif
/** Wrong Record Number */
#define DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_RECORDNUMBER 0x04U


/*------------------[Dem_ReturnGetSeverityOfDTCType]------------------------*/

/** \brief Used to return the status of GetSeverityOfDTC() */
typedef uint8 Dem_ReturnGetSeverityOfDTCType;

#if (defined DEM_GET_SEVERITYOFDTC_OK)
#error DEM_GET_SEVERITYOFDTC_OK already defined
#endif
/** Severity successfully returned */
#define DEM_GET_SEVERITYOFDTC_OK              0x00U

#if (defined DEM_GET_SEVERITYOFDTC_WRONG_DTC)
#error DEM_GET_SEVERITYOFDTC_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC       0x01U

#if (defined DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN)
#error DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN already defined
#endif
/** Wrong DTC origin */
#define DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN 0x02U

#if (defined DEM_GET_SEVERITYOFDTC_NOSEVERITY)
#error DEM_GET_SEVERITYOFDTC_NOSEVERITY already defined
#endif
/** Severity information is not available */
#define DEM_GET_SEVERITYOFDTC_NOSEVERITY      0x03U


/*------------------[Dem_ReturnGetViewIDOfDTCType]--------------------------*/

/** \brief Used to return the status of Dem_GetViewIDOfDTC() */
typedef uint8 Dem_ReturnGetViewIDOfDTCType;

#if (defined DEM_VIEWID_OK)
#error DEM_VIEWID_OK already defined
#endif
/** Status of ViewID is OK */
#define DEM_VIEWID_OK                0x00U

#if (defined DEM_VIEWID_WRONG_DTC)
#error DEM_VIEWID_WRONG_DTC already defined
#endif
/** Wrong DTC */
#define DEM_VIEWID_WRONG_DTC         0x02U

#if (defined DEM_VIEWID_WRONG_DTCKIND)
#error DEM_VIEWID_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_VIEWID_WRONG_DTCKIND     0x03U


/*------------------[internal type definitions]-----------------------------*/

/** \brief Entry data type, dynamic part of the error memory */
typedef uint8 Dem_EntryDataType;


/*==================[external function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief This service returns the version information of this module.
 **
 ** The version information includes:
 ** - Module Id
 ** - Vendor Id
 ** - Vendor specific version numbers (BSW00407).
 **
 ** This function shall be pre compile time configurable On/Off by the
 ** configuration parameter: DEM_VERSION_INFO_API
 **
 ** Hint:
 ** If source code for caller and callee of this function is available this
 ** function should be realized as a macro. The macro should be defined in the
 ** modules header file.
 **
 ** \service_id    ::DEM_SID_GetVersionInfo
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[out] versioninfo  Pointer to where to store the version information
 ** of this module.
 **/
extern FUNC(void, DEM_CODE) Dem_GetVersionInfo(
   CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA) VersionInfoPtr);


/*------------------[Interface ECU State Manager <--> DEM]------------------*/

/** \brief PreInit function to make the DEM queue operational
 **
 ** This function shall be used to initialize the internal states necessary to
 ** process events reported by BSWs by using Dem_ReportErrorStatus().
 **
 ** Dem_PreInit() shall be called by the ECU State Manager during the startup
 ** phase of the ECU before the NVRAM Manager has finished the restore of
 ** NVRAM data.
 **
 ** \service_id    ::DEM_SID_PreInit
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **/
extern FUNC(void, DEM_CODE) Dem_PreInit(void);


/** \brief Init function to make the DEM operational
 **
 ** This function shall be used during the startup phase of the ECU after
 ** the NVRAM Manager has finished the restore of NVRAM data.
 **
 ** SW-Components including Monitor Functions are initialized afterwards.
 **
 ** Caveats: The DEM is not functional until this function has been called.
 **
 ** \service_id    ::DEM_SID_Init
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **/
extern FUNC(void, DEM_CODE) Dem_Init(void);


/** \brief Shutdown function
 **
 ** This function is used to finalize all pending operations in the DEM to
 ** prepare the internal states and event data for transfer to the NVRAM.
 **
 ** Caveats: Once this function has been executed no further updates
 ** are applied to the DEM internal event data.
 **
 ** \service_id    ::DEM_SID_Shutdown
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **/
extern FUNC(void, DEM_CODE) Dem_Shutdown(void);


/*------------------[Interface SW-Components <--> DEM]----------------------*/

/* Interfaces between SW-Cs and DEM are declared in Dem_RteApi_Static.h
 *
 * Exceptions:
 * - Dem_SetEventStatus is intended only for SW-Cs and therefore declared in
 *   Dem_RteInternal_Static.h
 * - Dem_GetFaultDetectionCounter is not specified for the DEM SW-C
 *   description in the SWS and therefore declared below */


/** \brief Function to request the current Fault Detection Counter
 **
 ** The API shall be used by SW-C to request the current Fault Detection
 ** Counter for a given EventID.
 **
 ** \service_id    ::DEM_SID_GetFaultDetectionCounter
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Provide the EventId value the fault detection counter
 ** is requested for.If the return value of the function is other than OK
 ** this parameter does not contain valid data.
 **
 ** \param[out] EventIdFaultDetectionCounter  This parameter receives the
 ** Fault Detection Counter information of the requested EventId. If the
 ** return value of the function call is other than OKthis parameter does
 ** not contain valid data.
 **
 ** \return success of operation
 ** \retval E_OK     if operation was successful
 ** \retval E_NOT_OK if operation failed
 **
 **/
extern FUNC(Std_ReturnType, DEM_CODE)Dem_GetFaultDetectionCounter(
   Dem_EventIdType                         EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA)
                                           EventIdFaultDetectionCounter);


/*------------------[Interface BSW-Components <--> DEM]---------------------*/

/** \brief Function to report the status of diagnostic events of BSW
 **
 ** Interface for BSW Components to report Errors during start up (even before
 ** DEM initialization) and normal operation. At a first step, it is assumed,
 ** that all incoming results are considered as debounced. If a central
 ** pre-debouncing is provided, this API shall be used to support them for the
 ** BSW.
 **
 ** Configurations: The size of the buffer queue needs to be configured (ref.
 ** to DEM_BSW_ERROR_BUFFER_SIZE)
 **
 ** \service_id    ::DEM_SID_ReportErrorStatus
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Identification of an Event by assigned Event ID.
 ** The Event ID is configured in the DEM.
 ** - Min: 1 (0: Indication of no Event)
 ** - Max: Result of configuration of Event ID's in DEM (Max is either 255 or
 **   65535)
 **
 ** \param[in] EventStatus  uint8 {::DEM_EVENT_STATUS_PASSED,
 ** ::DEM_EVENT_STATUS_FAILED, ::DEM_EVENT_STATUS_PREPASSED,
 ** ::DEM_EVENT_STATUS_PREFAILED [, Custom]}
 **/
extern FUNC(void, DEM_CODE) Dem_ReportErrorStatus(
   Dem_EventIdType     EventId,
   Dem_EventStatusType EventStatus);


/*------------------[Interface DCM <--> DEM]--------------------------------*/

/* --- Access DTCs and Status Information --- */

/** \brief Sets the filter mask over all DTCs
 **
 ** This API shall be used to set the filter mask over all DTCs for the API's
 ** Dem_GetNextFilteredDTC(). The function resets the internal counter to the
 ** first event that matches the filter settings.
 **
 ** \service_id    ::DEM_SID_SetDTCFilter
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTCStatusMask  According ISO14229-1 StatusOfDTC
 ** Values:
 ** 0x00: Report all supported DTCs
 ** 0x01...0xFF: Match DTCStatusMask as defined in ISO14229-1
 **
 ** \param[in] DTCKind  Defines the functional group of DTCs to be reported
 ** (e.g. all DTC, OBD-relevant related DTC)
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory this
 ** parameter is used to select the source memory the DTCs shall be read from.
 **
 ** \param[in] FilterWithSeverity  This flag defines whether severity
 ** information (ref. to parameter below) shall be used for filtering. This is
 ** to allow for coexistence of DTCs with and without severity information.
 **
 ** \param[in] DTCSeverity  This parameter contains the DTCSeverityMask
 ** according to ISO14229-1.
 **
 ** \param[in] FilterForFaultDetectionCounter  This flag defines whether
 ** Fault Detection Counter information shall be used for filtering. This is
 ** to allow for coexistence of DTCs with and without Fault Detection Counter
 ** information. If Fault Detection Counter information is filter criteria,
 ** only those DTCs with a Fault Detection Counter value between 1 and 0x7E
 ** shall be reported.
 ** Remark: If the event does not uses the debouncing inside DEM, then the
 ** DEM must request this information via Xxx_DemGetFaultDetectionCounter.
 **
 ** \return Status of the operation of type ::Dem_ReturnSetDTCFilterType
 **/
extern FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE) Dem_SetDTCFilter(
   Dem_DTCStatusMaskType                  DTCStatusMask,
   Dem_DTCKindType                        DTCKind,
   Dem_DTCOriginType                      DTCOrigin,
   Dem_FilterWithSeverityType             FilterWithSeverity,
   Dem_DTCSeverityType                    DTCSeverity,
   Dem_FilterForFaultDetectionCounterType FilterForFaultDetectionCounter);


/** \brief Get number of filtered snapshot records
 **
 ** The filtered snapshot records can be retrieved by the function
 ** Dem_GetNextFilteredRecord(). This filter always belongs to primary memory.
 **
 ** \service_id    ::DEM_SID_SetDTCFilterForRecords
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] NumberOfFilteredRecords  Number of snapshot records currently
 ** stored in the event memory.
 **
 ** \return Status of the operation of type ::Dem_ReturnSetDTCFilterType
 **
 ** \note Not implemented yet.
 **/
extern FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE) Dem_SetDTCFilterForRecords(
   P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords);


/** \brief Sets a mask to process only the events of a functional addressable
 ** function
 **
 ** Dem_SetViewFilter() sets a mask to process only the events of a functional
 ** addressable function with the following DCM <-> DEM API calls.
 **
 ** To change the view the function Dem_SetViewFilter() must be called again
 ** with another ViewId.
 **
 ** The chosen ViewId is reset to the default value (0xFF -> all functional
 ** groups are visible) inside the DEM when Dem_SetDTCFilter() and
 ** Dem_Shutdown() is called.
 **
 ** This function can be used optional in case that only a special functional
 ** group shall be addressed (e.g. wiper system, window lifter). After setting
 ** a ViewID only events from the selected group are accessible in the event
 ** memory.
 **
 ** This function shall be used for function oriented diagnostics on ECUs with
 ** multiple functions.
 **
 ** Configuration: The assignment of an EventId to a specific view has to be
 ** configured / calibrated.
 **
 ** \service_id    ::DEM_SID_SetViewFilter
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] ViewId  The ViewId is a parameter used to select a specific
 ** view (see Dem_ViewIdType).
 **
 ** \return Status of the operation of type ::Dem_ReturnSetViewFilterType
 **
 ** \note Not fully implemented yet. View Id's not supported in this version.
 **/
extern FUNC(Dem_ReturnSetViewFilterType, DEM_CODE) Dem_SetViewFilter(
   Dem_ViewIdType ViewId);


/** \brief Read the status of a DTC
 **
 ** This API shall be used to read the status of a DTC to the parameter
 ** DTCStatus according to ISO14229.
 **
 ** \service_id    ::DEM_SID_GetStatusOfDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTC  For this DTC its status is requested
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory this
 ** parameter is used to select the source memory the DTCs shall be read from.
 **
 ** \param[out] DTCStatus  This parameter receives the status information of
 ** the requested DTC. If the return value of the function call is other than
 ** OK this parameter does not contain valid data.
 **
 ** \return Status of the operation of type ::Dem_ReturnGetStatusOfDTCType
 **/
extern FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_GetStatusOfDTC(
   Dem_DTCType                                            DTC,
   Dem_DTCKindType                                        DTCKind,
   Dem_DTCOriginType                                      DTCOrigin,
   P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA) DTCStatus);


/** \brief Read the DTC status availability mask
 **
 ** The API shall be used to get the DTC status availability mask. That means
 ** the DTC status information (according to ISO14229) supported by the DEM.
 **
 ** Only supported bits can be used as filter parameters in the API
 ** Dem_SetDTCFilter().
 **
 ** \service_id    ::DEM_SID_GetDTCStatusAvailabilityMask
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DTCStatusMask  The value from type ::Dem_DTCStatusMaskType
 ** indicates the supported DTC status bits from the DEM. All supported
 ** information is indicated by setting the corresponding status bit to 1.
 **
 ** \return success of operation
 ** \retval E_OK     get of DTC status availability mask was successful
 ** \retval E_NOT_OK get of DTC status availability mask failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCStatusAvailabilityMask(
   P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask);


/** \brief Read the number of DTC matching the defined status mask
 **
 ** The API shall be used to get the number of DTC matching the defined status
 ** mask. The DTC Status mask filter is set by the API Dem_SetDTCFilter.
 **
 ** Caveats: DTC filter has been set up properly before function call
 ** (Dem_SetDTCFilter()).
 **
 ** \service_id    ::DEM_SID_GetNumberOfFilteredDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] NumberOfFilteredDTC  The number of DTCs matching the defined
 ** status mask.
 **
 ** \return success of operation
 ** \retval E_OK     get of number of DTC was successful
 ** \retval E_NOT_OK get of number of DTC failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfFilteredDTC(
   P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC);


/** \brief Returns the current DTC and its associated status
 **
 ** The API shall be used to return the current DTC and its associated status
 ** from the DEM matching the filter criteria defined by the API call
 ** Dem_SetDTCFilter. After having returned the data the function skips to the
 ** next DTC matching the filter criteria.
 **
 ** To receive all DTCs matching the filter criteria this function shall be
 ** called continuously until the return value of the function is
 ** "NoMatchingDTC".
 **
 ** The chronological order shall be reported if the DTC status mask parameter
 ** is set to "pending" and/or "confirmed" (no other status bits are allowed
 ** to be set). The function shall start with the most recent DTC. The
 ** chronological order may vary with the customer specific attributes used by
 ** the algorithm for sorting the DTC records (e.g. pre-sorted records or
 ** time-stamp attributes of the records).
 **
 ** \service_id    ::DEM_SID_GetNextFilteredDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DTC  Receives the DTC value returned by the function. If the
 ** return value of the function is other than OK this parameter does not
 ** contain valid data.
 **
 ** \param[out] DTCStatus  This parameter receives the status information of
 ** the requested DTC. If the return value of the function call is other than
 ** OK this parameter does not contain valid data.
 **
 ** \return Status of the operation to retrieve a DTC from the DEM.
 **/
extern FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTC(
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)           DTC,
   P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA) DTCStatus);


/** \brief Returns one DTC according to the request type
 **
 ** The API provides the capability to access specific events stored at
 ** certain important points in time, The API call will return one DTC
 ** according to the ::Dem_DTCRequestType. If no DTC is matching the requested
 ** point in time the function will return the appropriate operation status
 ** and the DTC value will be zero (0).
 **
 ** \service_id    ::DEM_SID_GetDTCByOccurrenceTime
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTCRequest  This parameter defines the request type of the DTC.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[out] DTC  Receives the DTC value returned by the function. If the
 ** return value of the function is other than OK this parameter does not
 ** contain valid data.
 **
 ** \return Status of the operation of type
 ** ::Dem_ReturnGetDTCByOccurrenceTimeType
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)
   Dem_GetDTCByOccurrenceTime(
      Dem_DTCRequestType                              DTCRequest,
      Dem_DTCKindType                                 DTCKind,
      P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)    DTC);


/** \brief Returns view Id according to the DTC
 **
 ** The API provides the capability to get the according ViewID (e.g. wiper
 ** system, window lifter, ...) of a specific DTC. The parameter ViewID is
 ** equivalent to the parameter FunctionalUnit in ISO14229-1.
 **
 ** \service_id    ::DEM_SID_GetViewIDOfDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTC  This parameter defines the requested DTC.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[out] ViewId  The ViewId is a parameter used to select a specific
 ** view (ref. to ::Dem_ViewIdType).
 **
 ** \return Status of the operation of type ::Dem_ReturnGetViewIDOfDTCType
 **
 ** \note Not fully implemented yet. View Id's not supported in this version.
 **/
extern FUNC(Dem_ReturnGetViewIDOfDTCType, DEM_CODE) Dem_GetViewIDOfDTC(
   Dem_DTCType                                        DTC,
   Dem_DTCKindType                                    DTCKind,
   P2VAR(Dem_ViewIdType, AUTOMATIC, DEM_APPL_DATA)    ViewId);


/** \brief Returns next filtered snapshot record
 **
 ** The API shall be used to return the current DTC and its associated
 ** Snapshot Record numbers from the DEM matching the filter criteria defined
 ** by the API call Dem_SetDTCFilterForRecords. After having returned the
 ** data the function skips to the next Record matching the filter criteria.
 ** To receive all Records matching the filter criteria this function shall be
 ** called continuously until the return value of the function is
 ** "NoMatchingDTC".
 **
 ** \service_id    ::DEM_SID_GetNextFilteredRecord
 ** \reentrancy    non reentrant
 ** \synchronisity synchronus
 **
 ** \param[out] DTC Receives the DTC value returned by the function. If the
 ** return value of the function is other than OK this parameter does not
 ** contain valid data.
 **
 ** \param[out] SnapshotRecord  Snapshot Record Number for the reported DTC.
 **
 ** \return Status of the operation to retrieve a DTC from the DEM.
 **
 ** \note Not implemented yet.
 **/
extern FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)
Dem_GetNextFilteredRecord(
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA) DTC,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)       SnapshotRecord);


/** \brief returns next filtered fault detection counter
 **
 ** The API shall be used to return the current DTC and its associated Fault
 ** Detection Counter (FDC)from the DEM matching the filter criteria defined
 ** by the API call Dem_SetDTCFilter. After having returned the data the
 ** function skips to the next DTC matching the filter criteria.
 ** To receive all DTCs matching the filter criteria this function shall be
 ** called continuously until the return value of the function is
 ** "NoMatchingDTC".
 **
 ** \service_id    ::DEM_SID_GetNextFilteredDTCAndFDC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronus
 **
 ** \param[out] DTC  Receives the DTC value returned by the function. If the
 ** return value of the function is other than OK this parameter does not
 ** contain valid data.
 **
 ** \param[out] DTCFaultDetectionCounter  This parameter receives the Fault
 ** Detection Counterinformation of the requested DTC. If the return value of
 ** the function call is other than OK this parameter does not contain valid
 ** data.
 **
 ** \return Status of the operation to retrieve a DTC from the DEM.
 **
 ** \note Not implemented yet.
 **/
extern FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)
Dem_GetNextFilteredDTCAndFDC(
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA)
                                                 DTCFaultDetectionCounter);


/** \brief return configured translation format
 **
 ** The API provides the capability to get the configured translation format
 ** of the ECU.
 **
 ** \service_id    ::DEM_SID_
 ** \reentrancy    non reentrant
 ** \synchronisity synchronus
 **
 ** \param[out] TranslationFormat  The translation provides the configured
 ** translation format
 **
 ** \return success of operation
 ** \retval E_OK     request of severity was successful
 ** \retval E_NOT_OK request of severity failed
 **
 ** \note Not implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetTranslationType(
   P2VAR(Dem_DTCTranslationFormatType, AUTOMATIC, DEM_APPL_DATA)
                                                  TranslationFormat);


/** \brief Gets Severity of the requested DTC
 **
 ** Caveats: Dem_DTCKindType not needed, because Severity is only available
 ** for ISO14229-1 DTCs
 **
 ** \service_id    ::DEM_SID_GetSeverityOfDTC
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] DTC  The Severity assigned to this DTC should be returned
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory
 ** this parameter is used to select the source memory the DTCs shall be read
 ** from
 **
 ** \param[out] DTCSeverity  This parameter contains the DTCSeverityMask
 ** according to ISO14229-1
 **
 ** \param[out] StatusGetSeverity  Status of the operation of type
 ** ::Dem_ReturnGetSeverityOfDTCType
 **
 ** \return success of operation
 ** \retval E_OK     request of severity was successful
 ** \retval E_NOT_OK request of severity failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetSeverityOfDTC(
   Dem_DTCType                                             DTC,
   Dem_DTCOriginType                                       DTCOrigin,
   P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA)    DTCSeverity,
   P2VAR(Dem_ReturnGetSeverityOfDTCType, AUTOMATIC, DEM_APPL_DATA)
                                                           StatusGetSeverity);


/* --- Access extended data records and Freeze Frame data --- */

/** \brief Prevents from manipulating, overwriting or deleting any existing
 ** DTC
 **
 ** This function shall be used if the freeze frame or extended data record
 ** are about to be accessed by subsequent API-calls. It is done to ensure
 ** that the data contained in this record is not changed while the freeze
 ** frame or extended data record are accessed by the external application,
 ** e.g. DCM.
 **
 ** This function is used to prevent the DEM from manipulating, overwriting or
 ** deleting any existing DTC, associated freeze frame and/or extended data
 ** records. New DTCs and associated freeze frames and extended data records
 ** can still be added to the fault record storage as long as memory is
 ** available.
 **
 ** DTC status information update is not affected by this function.
 **
 ** \service_id    ::DEM_SID_DisableDTCRecordUpdate
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DisableDTCRecordUpdate(void);


/** \brief Release the data contained in this record
 **
 ** The function Dem_EnableDTCRecordUpdate is the counterpart to the function
 ** Dem_DisableDTCRecordUpdate. It shall be called after the freeze frame and
 ** extended data record were protected by the function
 ** Dem_DisableDTCRecordUpdate and after the access by subsequent API-calls is
 ** finished.
 **
 ** It is called to release the data contained in this record so that the data
 ** can be accessed or manipulated by the external application, e.g. DCM,
 ** again.
 **
 ** \service_id    ::DEM_SID_EnableDTCRecordUpdate
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EnableDTCRecordUpdate(void);


/** \brief Returns one DTC associated with the freeze frame
 **
 ** This API shall be used to return the DTC associated with the freeze frame
 ** selected via its absolute record number.
 **
 ** Caveats: The record number has to be unique throughout the whole ECU.
 ** This function is only required for OBD-relevant ECUs.
 **
 ** \service_id    ::DEM_SID_GetDTCOfFreezeFrameRecord
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] RecordNumber  This parameter is a unique identifier for a
 ** freeze frame record as defined in ISO15031-5 and ISO14229-1.
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory this
 ** parameter is used to select the source memory the DTCs shall be read from.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[out] DTC  Receives the DTC value returned by the function. If the
 ** return value of the function is other than OK this parameter does not
 ** contain valid data.
 **
 ** \return Status of the operation of type
 ** ::Dem_ReturnGetDTCOfFreezeFrameRecordType
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Dem_ReturnGetDTCOfFreezeFrameRecordType, DEM_CODE)
   Dem_GetDTCOfFreezeFrameRecord(
      uint8                                         RecordNumber,
      Dem_DTCOriginType                             DTCOrigin,
      Dem_DTCKindType                               DTCKind,
      P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC);


/** \brief Used to copy a specific PID/DataId of a freeze frame
 **
 ** This function shall be used to copy a specific PID/DataId of a Freeze
 ** Frame selected via the associated DTC number and an optional Freeze Frame
 ** RecordNumber to the destination buffer. Shall be transmitted as complete
 ** record with format PID followed by data, PID - data, ... The DCM does not
 ** know the DEM internal structure so it asks per Identifier to get special
 ** PIDs for instance, not intended to get all Freeze Frame data value by
 ** value. In case of DataId=All Freeze Frame Data will be transferred at
 ** once.
 **
 ** Caveats: Assumptions: The software engineer implementing the DEM shall be
 ** an expert in OBD-relevant onboard diagnostics and familiar with the
 ** services as defined in ISO15031-5.
 **
 ** \service_id    ::DEM_SID_GetFreezeFrameDataByDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTC  This is the DTC the Freeze Frame is assigned to.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory
 ** this parameter is used to select the source memory the DTCs shall be read
 ** from.
 **
 ** \param[in] RecordNumber  This parameter is a unique identifier for a
 ** Freeze Frame record as defined in ISO15031-5 and ISO14229-1.
 **
 ** \param[in] DataId  This parameter specifies the PID (ISO15031-5)
 ** (Mode2 individual parameter or the whole Freeze Frame data set) or data
 ** identifier (ISO14229-1) that shall be copied to the destination buffer.
 **
 ** \param[out] DestBuffer  This parameter contains a byte pointer that points
 ** to the buffer to which the Freeze Frame data shall be written.
 **
 ** \param[in/out] BufSize  When the function is called this parameter
 ** contains the maximum number of data bytes that can be written to the
 ** buffer.
 **
 ** The function returns the actual number of written data bytes in this
 ** parameter.
 **
 ** \return Status of the operation of type
 ** ::Dem_ReturnGetFreezeFrameDataByDTCType
 **/
extern FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)
   Dem_GetFreezeFrameDataByDTC(
      Dem_DTCType                               DTC,
      Dem_DTCKindType                           DTCKind,
      Dem_DTCOriginType                         DTCOrigin,
      uint8                                     RecordNumber,
      uint16                                    DataId,
      P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)    DestBuffer,
      P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)    BufSize);


/** \brief Returns the data identifiers
 **
 ** This function shall be used to return the data identifiers and the number
 ** of data identifiers of a Freeze Frame which belong to a specific DTC.
 **
 ** Configuration: This function is only required for emission related ECUs.
 **
 ** \service_id    ::DEM_SID_GetFreezeFrameDataIdentifierByDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTC  This is the DTC the Freeze Frame is assigned to.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory this
 ** parameter is used to select the source memory the DTCs shall be read from.
 **
 ** \param[in] RecordNumber  This parameter is a unique identifier for a
 ** Freeze Frame record as defined in ISO15031-5 and ISO14229-1.
 **
 ** \param[out] ArraySize  This parameter specifies the number of data
 ** identifiers for the selected RecordNumber.
 **
 ** \param[out] DataId  Pointer to an array with the supported data identifier
 ** for the selected RecordNumber and DTC.
 **
 ** \return Status of the operation of type
 ** ::Dem_ReturnGetFreezeFrameDataIdentifierByDTCType
 **/
extern FUNC(Dem_ReturnGetFreezeFrameDataIdentifierByDTCType, DEM_CODE)
Dem_GetFreezeFrameDataIdentifierByDTC(
   Dem_DTCType                               DTC,
   Dem_DTCKindType                           DTCKind,
   Dem_DTCOriginType                         DTCOrigin,
   uint8                                     RecordNumber,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)    ArraySize,
   P2VAR(P2CONST(uint16, AUTOMATIC, DEM_APPL_CONST), AUTOMATIC, DEM_APPL_DATA)
                                             DataId);


/** \brief Returns the size of the requested freeze frame
 **
 ** The API shall be used to return the size of the requested freeze frame.
 ** This size only represents the number of user data bytes (pure freeze frame
 ** data) and does not contain any freeze frame structure information.
 **
 ** \service_id    ::DEM_SID_GetSizeOfFreezeFrame
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTC  This is the DTC the Freeze Frame is assigned to.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory this
 ** parameter is used to select the source memory the DTCs shall be read from.
 **
 ** \param[in] RecordNumber  This parameter is a unique identifier for a
 ** Freeze Frame record as defined in ISO15031-5 and ISO14229-1.
 **
 ** \param[out] SizeOfFreezeFrame  Number of bytes in the requested
 ** Freeze Frame.
 **
 ** \return Status of the operation of type
 ** ::Dem_ReturnGetSizeOfFreezeFrameType
 **/
extern FUNC(Dem_ReturnGetSizeOfFreezeFrameType, DEM_CODE)
   Dem_GetSizeOfFreezeFrame(
      Dem_DTCType                              DTC,
      Dem_DTCKindType                          DTCKind,
      Dem_DTCOriginType                        DTCOrigin,
      uint8                                    RecordNumber,
      P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame);


/** \brief Used to return the complete Freeze Frame for the requested DTC
 **
 ** This function shall be used to return the complete Extended Data Record
 ** for the requested DTC. The format of the data is raw hexadecimal values
 ** and is not standardized to comply with predefined scaling methods.
 **
 ** Configuration: Values of 'Extended Data Record' have to be defined.
 **
 ** \service_id    ::DEM_SID_GetExtendedDataRecordByDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTC  This is the DTC the 'Extended Data Record' is assigned to.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory this
 ** parameter is used to select the source memory the DTCs shall be read from.
 **
 ** \param[in] ExtendedDataNumber  Identification of requested Extended data
 ** record. The requested record is copied to the destination buffer.
 **
 ** \param[out] DestBuffer  This parameter contains a byte pointer that points
 ** to the buffer to which the Extended Data data shall be written.
 **
 ** \param[in/out] BufSize  When the function is called this parameter
 ** contains the maximum number of data bytes that can be written to the
 ** buffer.
 **
 ** The function returns the actual number of written data bytes in this
 ** parameter.
 **
 ** \return Status of the operation of type
 ** Dem_ReturnGetExtendedDataRecordByDTCType
 **/
extern FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
Dem_GetExtendedDataRecordByDTC(
   Dem_DTCType                            DTC,
   Dem_DTCKindType                        DTCKind,
   Dem_DTCOriginType                      DTCOrigin,
   uint8                                  ExtendedDataNumber,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize);


/** \brief Used to return the size of the requested extended data record
 **
 ** The API shall be used to return the size of the requested 'Extended Data
 ** Record' frame. This size only represents the number of user data bytes
 ** stored in the 'Extended Data Record'.
 **
 ** Configuration: Values of 'Extended Data Record' have to be defined.
 **
 ** \service_id    ::DEM_SID_GetSizeOfExtendedDataRecordByDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTC  This is the DTC the 'Extended Data Record' is assigned to.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory this
 ** parameter is used to select the source memory the DTCs shall be read from.
 **
 ** \param[in] ExtendedDataNumber  Identification of requested Extended data
 ** record. The requested record is copied to the destination buffer.
 **
 ** \param[out] SizeOfExtendedDataRecord  Pointer to Size of the requested
 ** data record
 **
 ** \return Status of the operation of type
 ** ::Dem_ReturnGetSizeOfExtendedDataRecordByDTCType
 **/
extern FUNC(Dem_ReturnGetSizeOfExtendedDataRecordByDTCType, DEM_CODE)
Dem_GetSizeOfExtendedDataRecordByDTC(
   Dem_DTCType                               DTC,
   Dem_DTCKindType                           DTCKind,
   Dem_DTCOriginType                         DTCOrigin,
   uint8                                     ExtendedDataNumber,
   P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)   SizeOfExtendedDataRecord);


/* --- Clear DTC information --- */

/** \brief Clears the specified DTC
 **
 ** This API shall be used to clear
 ** - all the event status related the specified DTC
 ** - all associated event memory entries for these events (environmental
 **   and/or FreezeFrame data, ...)
 **
 ** \param[in] DTC  Defines the DTC that shall be cleared from the event
 ** memory. If the DTC fits to a DTC group number, all DTCs of the group shall
 ** be cleared.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant
 **
 ** \param[in] DTCOrigin  If the DEM supports more than one event memory this
 ** parameter is used to select the source memory the DTCs shall be cleared
 ** from.
 **
 ** \return Status of the operation of type ::Dem_ReturnClearDTCType
 **/

extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC(
   Dem_DTCType         DTC,
   Dem_DTCKindType     DTCKind,
   Dem_DTCOriginType   DTCOrigin);


/* --- Control DTC storage --- */

/** \brief Disables the storage of DTCs
 **
 ** This function shall be called to disable the storage of DTCs in the event
 ** memory.
 **
 ** DTC status information update is not affected by this function.
 **
 ** This is only for preventing DTCs from being stored in case of an induced
 ** failure situations in a system, e.g. during flash-reprogramming of one ECU
 ** in a network. In that case all the ECU's are commanded via diagnostic
 ** request (linked to the above diagnostic request) to suppress storage of a
 ** DTC while maintaining correct fail-safe behavior as the flashed ECU is not
 ** participating in the normal communication anymore. If one of the other
 ** networked ECUs needs one of the signals which are now missing, this will
 ** lead to a failsafe-reaction of the ECU as by the AUTOSAR concept the
 ** fail-safe reaction of an ECU is triggered by certain event-status updates
 ** or a FIM-command which is itself triggered by an event-status update.
 **
 ** \service_id    ::DEM_SID_DisableDTCStorage
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTCGroup  Defines the group of DTC that shall be disabled to
 ** store in event memory.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant
 **
 ** \return Status of the operation of type ::Dem_ReturnControlDTCStorageType
 **
 ** \note Not fully implemented yet. DTCKind parameter is ignored, because OBD
 ** is not supported in this version.
 **/
extern FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE) Dem_DisableDTCStorage(
   Dem_DTCGroupType DTCGroup,
   Dem_DTCKindType  DTCKind);


/** \brief Enables the storage of DTCs
 **
 ** This function shall be called to enable the storage of DTCs in the event
 ** memory. See also Dem_DisableDTCStorage().
 **
 ** \service_id    ::DEM_SID_EnableDTCStorage
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTCGroup  Defines the group of DTC that shall be enabled to
 ** store in event memory.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant
 **
 ** \return Status of the operation of type ::Dem_ReturnControlDTCStorageType
 **
 ** \note Not fully implemented yet. DTCKind parameter is ignored, because OBD
 ** is not supported in this version.
 **/
extern FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE) Dem_EnableDTCStorage(
   Dem_DTCGroupType DTCGroup,
   Dem_DTCKindType  DTCKind);


/** \brief Disables the update of the event status
 **
 ** This function shall be called to disable the update of the event status.
 **
 ** This API has influence only on the execution of the API's
 ** Dem_SetEventStatus and Dem_ResetEventStatus. This is defined by
 ** configuration.
 **
 ** In this case both, the event status update and consequently the storage of
 ** DTCs, are suppressed. Thereby any fail-safe reaction of the ECU which is
 ** tight to certain event-status-updates will be suppressed as well, leaving
 ** the system in an unpredictable or even self-destructive condition if
 ** failures are not correctly handled anymore.
 **
 ** This feature / API-call may be used for engineering purposes or during
 ** manufacturing in a controlled environment to supress failsafe-reaction
 ** (e.g. prevent headlamps on, windshield wiper on, etc.).
 **
 ** Configuration: Depending on configuration within the API
 ** Dem_DisableEventStatusUpdate the reaction on the event status is defined.
 ** For example: the execution of Dem_ResetEventStatus is possible also during
 ** this phase.
 **
 ** \service_id    ::DEM_SID_DisableEventStatusUpdate
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTCGroup  Defines the group of DTC that shall be disabled to
 ** update event status.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant
 **
 ** \return Status of the operation of type ::Dem_ReturnControlDTCStorageType
 **
 ** \note Not fully implemented yet. DTCKind parameter is ignored, because OBD
 ** is not supported in this version.
 **/
extern FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)
Dem_DisableEventStatusUpdate(
   Dem_DTCGroupType DTCGroup,
   Dem_DTCKindType  DTCKind);


/** \brief Enables the update of the event status
 **
 ** This function shall be called to enable the update of the event status.
 ** See also Dem_DisableEventStatusUpdate().
 **
 ** \service_id    ::DEM_SID_EnableEventStatusUpdate
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTCGroup  Defines the group of DTC that shall be enabled to
 ** update event status.
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant
 **
 ** \return Status of the operation of type ::Dem_ReturnControlDTCStorageType
 **
 ** \note Not fully implemented yet. DTCKind parameter is ignored, because OBD
 ** is not supported in this version.
 **/
extern FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)
Dem_EnableEventStatusUpdate(
   Dem_DTCGroupType DTCGroup,
   Dem_DTCKindType  DTCKind);


/* --- Get DEM statistical data / legislated data / indicator status --- */

/** \brief Reads the PID01h of ISO15031-5 Data B/C/D
 **
 ** This function shall be used to read the PID01h of ISO15031-5 Data B/C/D
 ** information.
 **
 ** Configuration: This function shall only be supported and implemented by
 ** OBD-relevant ECUs.
 **
 ** The readiness group shall be configured in the DEM.
 **
 ** \service_id    ::DEM_SID_GetOBDReadiness
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DataByte_B  Data B of PID01h of ISO15031-5
 ** \param[out] DataByte_C  Data C of PID01h of ISO15031-5
 ** \param[out] DataByte_D  Data D of PID01h of ISO15031-5
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed or is not supported
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetOBDReadiness(
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_B,
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_C,
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_D);


/** \brief Reads the PID21h of ISO15031-5 Data A/B
 **
 ** This function shall be used to read the PID21h of ISO15031-5 Data A/B
 ** information.
 **
 ** Configuration: This function shall only be supported and implemented by
 ** OBD-relevant ECUs.
 **
 ** \service_id    ::DEM_SID_GetDistanceMIL
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DataByte_A  Data A of PID21h of ISO15031-5
 ** \param[out] DataByte_B  Data B of PID21h of ISO15031-5
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed or is not supported
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDistanceMIL(
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_A,
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_B);


/** \brief Reads the PID30h of ISO15031-5 Data A
 **
 ** This function shall be used to read the PID30h of ISO15031-5 Data A
 ** information.
 **
 ** Configuration: This function shall only be supported and implemented by
 ** OBD-related ECUs.
 **
 ** \service_id    ::DEM_SID_GetWarmupCycleDTCclear
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DataByte_A  Data A of PID30h of ISO15031-5
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed or is not supported
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetWarmupCycleDTCclear(
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_A);


/** \brief Reads the PID31h of ISO15031-5 Data A/B
 **
 ** This function shall be used to read the PID31h of ISO15031-5 Data A/B
 ** information.
 **
 ** Configuration: This function shall only be supported and implemented by
 ** OBD-related ECUs.
 **
 ** \service_id    ::DEM_SID_GetDistanceDTCclear
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DataByte_A  Data A of PID31h of ISO15031-5
 ** \param[out] DataByte_B  Data B of PID31h of ISO15031-5
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed or is not supported
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDistanceDTCclear(
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_A,
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_B);


/** \brief Reads the PID41h of ISO15031-5 Data B/C/D
 **
 ** This function shall be used to read the PID41h of ISO15031-5 Data B/C/D
 ** information.
 **
 ** Configuration: This function shall only be supported and implemented by
 ** OBD-relevantECUs.
 **
 ** The readiness group shall be configured in the DEM.
 **
 ** \service_id    ::DEM_SID_GetMonitorStatus
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DataByte_B  Data B of PID41h of ISO15031-5
 ** \param[out] DataByte_C  Data C of PID41h of ISO15031-5
 ** \param[out] DataByte_D  Data D of PID41h of ISO15031-5
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed or is not supported
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetMonitorStatus(
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_B,
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_C,
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_D);


/** \brief Reads the PID4Dh of ISO15031-5 Data A/B
 **
 ** This function shall be used to read the PID4Dh of ISO15031-5 Data A/B
 ** information.
 **
 ** Configuration: This function shall only be supported and implemented by
 ** OBD-related ECUs.
 **
 ** \service_id    ::DEM_SID_GetTimeMIL
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DataByte_A  Data A of PID4Dh of ISO15031-5
 ** \param[out] DataByte_B  Data B of PID4Dh of ISO15031-5
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed or is not supported
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetTimeMIL(
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_A,
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_B);


/** \brief Reads the PID4Eh of ISO15031-5 Data A/B
 **
 ** This function shall be used to read the PID4Eh of ISO15031-5 Data A/B
 ** information.
 **
 ** Configuration: This function shall only be supported and implemented by
 ** OBD-related ECUs.
 **
 ** \service_id    ::DEM_SID_GetTimeDTCclear
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[out] DataByte_A  Data A of PID4Eh of ISO15031-5
 ** \param[out] DataByte_B  Data B of PID4Eh of ISO15031-5
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed or is not supported
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetTimeDTCclear(
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_A,
   P2VAR(Dem_DataByteType, AUTOMATIC, DEM_APPL_DATA) DataByte_B);


/*------------------[Interface DEM <--> SW-Components]----------------------*/

/** brief\ Wrapper-Function to call init-monitor-for-event functions
 **
 ** This must be done by a wrapper, because it depends on configuration.
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 ** \param[in] InitMonitorKind
 **/
extern FUNC(void, DEM_CODE) Dem_RteInitMonitorForEvent(
   const Dem_EventIdType         EventId,
   const Dem_InitMonitorKindType InitMonitorKind);


/** brief\ Wrapper-Function to call trigger-on-event-status functions
 **
 ** This must be done by a wrapper, because it depends on configuration.
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 ** \param[in] OldDTCStatusMask
 ** \param[in] NewDTCStatusMask
 **/
extern FUNC(void, DEM_CODE) Dem_RteTriggerOnEventStatus(
   const Dem_EventIdType       EventId,
   const Dem_DTCStatusMaskType OldDTCStatusMask,
   const Dem_DTCStatusMaskType NewDTCStatusMask);


/** brief\ Wrapper-Function to call get-fault-detection-counter functions
 **
 ** This must be done by a wrapper, because it depends on configuration.
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 ** \param[out] FDC
 **
 ** \return E_OK if FDC could be acquired, E_NOT_OK otherwise
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_RteGetFaultDetectionCounter(
   Dem_EventIdType                                                EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC);


/*------------------[Scheduled functions]-----------------------------------*/

/** \brief Processes event memory entries from error-queue
 **
 ** This function is used to process all not event based DEM internal
 ** functions. It shall be called periodically as cyclic task by the software
 ** system (e.g. by operating system).
 **
 ** Timing: fixed cyclic
 **
 ** Configuration: The cyclic time for the main function has to be defined as
 ** an operating system task or run able entity.
 **
 ** \service_id    ::DEM_SID_MainFunction
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed
 **/
FUNC(Std_ReturnType, DEM_CODE) Dem_MainFunction(void);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_API_STATIC_H */
/*==================[end of file]===========================================*/
