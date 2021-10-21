#ifndef DEM_INTERNAL_STATIC_H
/** \brief preprocessor exclusion definition */
#define DEM_INTERNAL_STATIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all configuration independent internal API declarations
 ** of the AUTOSAR module Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Internal_Static.h 2556 2011-09-08 11:34:37Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise
 **/

/**  MISRA-C:2004 Deviation List
 **
 **  MISRA-1) Deviated Rule: 19.7 (advisory)
 **   A function should be used in preference to a function-like macro.
 **
 **   Reason:
 **   As the function is called very often and consists only of a one line
 **   the macro based implmentation is more run time efficient.
 **
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */
#include <Dem_Helper.h>                                    /* helper macros */

/* this is for more-library solution (e.g. debug/release) */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>                        /* AUTOSAR development error tracer */
#endif

#include <Dem_Internal_Base_Specific.h> /* Basic intern. module definitions */

/*==================[macros]================================================*/

#if (defined DEM_DTC_STATUS_AVAILABILITY_MASK)
#error DEM_DTC_STATUS_AVAILABILITY_MASK already defined
#endif
/** \brief DTC status availability mask */
#define DEM_DTC_STATUS_AVAILABILITY_MASK \
   ( DEM_DTCSTATUSBIT_TF     \
   | DEM_DTCSTATUSBIT_TFTOC  \
   | DEM_DTCSTATUSBIT_PDTC   \
   | DEM_DTCSTATUSBIT_CDTC   \
   | DEM_DTCSTATUSBIT_TNCSLC \
   | DEM_DTCSTATUSBIT_TFSLC  \
   | DEM_DTCSTATUSBIT_TNCTOC \
   | DEM_DTCSTATUSBIT_WIR)


#if (defined DEM_MAXNUM_ORIGINS)
#error DEM_MAXNUM_ORIGINS already defined
#endif
/** \brief Maximal number of configurable event memories/origins */
#define DEM_MAXNUM_ORIGINS 3U


#if (defined DEM_DATA_PADDING_VALUE)
#error DEM_DATA_PADDING_VALUE already defined
#endif
/** \brief Padding value used for extended and freeze frame data */
#define DEM_DATA_PADDING_VALUE 0xFFU

/*------------------[Enabling of View Id and Priority]----------------------*/

#if (defined DEM_USE_VIEWID)
#error DEM_USE_VIEWID already defined
#endif
/** \brief Macro to enable support for View Id. **/
#define DEM_USE_VIEWID   STD_OFF

#if (defined DEM_USE_PRIORITY)
#error DEM_USE_PRIORITY already defined
#endif
/** \brief Macro to anable support for Priority. **/
#define DEM_USE_PRIORITY STD_OFF

/*------------------[defines for debouncing]--------------------------------*/

#if (defined DEM_FDC_VALUE_FAILED)
#error DEM_FDC_VALUE_FAILED already defined
#endif
/** \brief FDC value for a qualified FAILED event */
#define DEM_FDC_VALUE_FAILED     127 /* note: this must be a signed value! */

#if (defined DEM_FDC_VALUE_PASSED)
#error DEM_FDC_VALUE_PASSED already defined
#endif
/** \brief FDC value for a qualified PASSED event */
#define DEM_FDC_VALUE_PASSED    (-128) /* note: this must be a signed value! */

#if (defined DEM_FDC_VALUE_UNQUALIFIED)
#error DEM_FDC_VALUE_UNQUALIFIED already defined
#endif
/** \brief (initial) FDC value for unqualified events */
#define DEM_FDC_VALUE_UNQUALIFIED  0 /* note: this must be a signed value! */


/*------------------[API function service IDs]------------------------------*/

#if (defined DEM_SID_GetVersionInfo)
#error DEM_SID_GetVersionInfo already defined
#endif
/** \brief Service Id for Dem_GetVersionInfo() */
#define DEM_SID_GetVersionInfo                                    0U


#if (defined DEM_SID_PreInit)
#error DEM_SID_PreInit already defined
#endif
/** \brief Service Id for Dem_PreInit() */
#define DEM_SID_PreInit                                           1U

#if (defined DEM_SID_Init)
#error DEM_SID_Init already defined
#endif
/** \brief Service Id for Dem_Init() */
#define DEM_SID_Init                                              2U

#if (defined DEM_SID_Shutdown)
#error DEM_SID_Shutdown already defined
#endif
/** \brief Service Id for Dem_Shutdown() */
#define DEM_SID_Shutdown                                          3U


#if (defined DEM_SID_SetEventStatus)
#error DEM_SID_SetEventStatus already defined
#endif
/** \brief Service Id for Dem_SetEventStatus() */
#define DEM_SID_SetEventStatus                                    4U

#if (defined DEM_SID_ResetEventStatus)
#error DEM_SID_ResetEventStatus already defined
#endif
/** \brief Service Id for Dem_ResetEventStatus() */
#define DEM_SID_ResetEventStatus                                  5U

#if (defined DEM_SID_PrestoreFreezeFrame)
#error DEM_SID_PrestoreFreezeFrame already defined
#endif
/** \brief Service Id for Dem_PrestoreFreezeFrame() */
#define DEM_SID_PrestoreFreezeFrame                               6U

#if (defined DEM_SID_ClearPrestoredFreezeFrame)
#error DEM_SID_ClearPrestoredFreezeFrame already defined
#endif
/** \brief Service Id for Dem_ClearPrestoredFreezeFrame() */
#define DEM_SID_ClearPrestoredFreezeFrame                         7U

#if (defined DEM_SID_SetOperationCycleState)
#error DEM_SID_SetOperationCycleState already defined
#endif
/** \brief Service Id for Dem_SetOperationCycleState() */
#define DEM_SID_SetOperationCycleState                            8U

#if (defined DEM_SID_GetEventStatus)
#error DEM_SID_GetEventStatus already defined
#endif
/** \brief Service Id for Dem_GetEventStatus() */
#define DEM_SID_GetEventStatus                                   10U

#if (defined DEM_SID_GetEventFailed)
#error DEM_SID_GetEventFailed already defined
#endif
/** \brief Service Id for Dem_GetEventFailed() */
#define DEM_SID_GetEventFailed                                   11U

#if (defined DEM_SID_GetEventTested)
#error DEM_SID_GetEventTested already defined
#endif
/** \brief Service Id for Dem_GetEventTested() */
#define DEM_SID_GetEventTested                                   12U

#if (defined DEM_SID_GetDTCOfEvent)
#error DEM_SID_GetDTCOfEvent already defined
#endif
/** \brief Service Id for Dem_GetDTCOfEvent() */
#define DEM_SID_GetDTCOfEvent                                    13U

#if (defined DEM_SID_SetValueByOemId)
#error DEM_SID_SetValueByOemId already defined
#endif
/** \brief Service Id for Dem_SetValueByOemId() */
#define DEM_SID_SetValueByOemId                                  56U

#if (defined DEM_SID_SetEnableCondition)
#error DEM_SID_SetEnableCondition already defined
#endif
/** \brief Service Id for Dem_SetEnableCondition() */
#define DEM_SID_SetEnableCondition                               57U

#if (defined DEM_SID_GetFaultDetectionCounter)
#error DEM_SID_GetFaultDetectionCounter already defined
#endif
/** \brief Service Id for Dem_GetFaultDetectionCounter() */
#define DEM_SID_GetFaultDetectionCounter                         62U

#if (defined DEM_SID_GetIndicatorStatus)
#error DEM_SID_GetIndicatorStatus already defined
#endif
/** \brief Service Id for Dem_GetIndicatorStatus() */
#define DEM_SID_GetIndicatorStatus                               41U


#if (defined DEM_SID_ReportErrorStatus)
#error DEM_SID_ReportErrorStatus already defined
#endif
/** \brief Service Id for Dem_ReportErrorStatus() */
#define DEM_SID_ReportErrorStatus                                15U


#if (defined DEM_SID_SetDTCFilter)
#error DEM_SID_SetDTCFilter already defined
#endif
/** \brief Service Id for Dem_SetDTCFilter() */
#define DEM_SID_SetDTCFilter                                     19U

#if (defined DEM_SID_SetDTCFilterForRecords)
#error DEM_SID_SetDTCFilterForRecords already defined
#endif
/** \brief Service Id for Dem_SetDTCFilterForRecords() */
#define DEM_SID_SetDTCFilterForRecords                           63U

#if (defined DEM_SID_SetViewFilter)
#error DEM_SID_SetViewFilter already defined
#endif
/** \brief Service Id for Dem_SetViewFilter() */
#define DEM_SID_SetViewFilter                                    20U

#if (defined DEM_SID_GetStatusOfDTC)
#error DEM_SID_GetStatusOfDTC already defined
#endif
/** \brief Service Id for Dem_GetStatusOfDTC() */
#define DEM_SID_GetStatusOfDTC                                   21U

#if (defined DEM_SID_GetDTCStatusAvailabilityMask)
#error DEM_SID_GetDTCStatusAvailabilityMask already defined
#endif
/** \brief Service Id for Dem_GetDTCStatusAvailabilityMask() */
#define DEM_SID_GetDTCStatusAvailabilityMask                     22U

#if (defined DEM_SID_GetNumberOfFilteredDTC)
#error DEM_SID_GetNumberOfFilteredDTC already defined
#endif
/** \brief Service Id for Dem_GetNumberOfFilteredDTC() */
#define DEM_SID_GetNumberOfFilteredDTC                           23U

#if (defined DEM_SID_GetNextFilteredDTC)
#error DEM_SID_GetNextFilteredDTC already defined
#endif
/** \brief Service Id for Dem_GetNextFilteredDTC() */
#define DEM_SID_GetNextFilteredDTC                               24U

#if (defined DEM_SID_GetDTCByOccurrenceTime)
#error DEM_SID_GetDTCByOccurrenceTime already defined
#endif
/** \brief Service Id for Dem_GetDTCByOccurrenceTime() */
#define DEM_SID_GetDTCByOccurrenceTime                           25U

#if (defined DEM_SID_GetViewIDOfDTC)
#error DEM_SID_GetViewIDOfDTC already defined
#endif
/** \brief Service Id for Dem_GetViewIDOfDTC() */
#define DEM_SID_GetViewIDOfDTC                                   54U

#if (defined DEM_SID_GetNextFilteredRecord)
#error DEM_SID_GetNextFilteredRecord already defined
#endif
/** \brief Service Id for Dem_GetNextFilteredRecord() */
#define DEM_SID_GetNextFilteredRecord                            58U

#if (defined DEM_SID_GetNextFilteredDTCAndFDC)
#error DEM_SID_GetNextFilteredDTCAndFDC already defined
#endif
/** \brief Service Id for Dem_GetNextFilteredDTCAndFDC() */
#define DEM_SID_GetNextFilteredDTCAndFDC                         59U

#if (defined DEM_SID_GetTranslationType)
#error DEM_SID_GetTranslationType already defined
#endif
/** \brief Service Id for Dem_GetTranslationType() */
#define DEM_SID_GetTranslationType                               60U

#if (defined DEM_SID_GetSeverityOfDTC)
#error DEM_SID_GetSeverityOfDTC already defined
#endif
/** \brief Service Id for Dem_GetSeverityOfDTC() */
#define DEM_SID_GetSeverityOfDTC                                 14U


#if (defined DEM_SID_DisableDTCRecordUpdate)
#error DEM_SID_DisableDTCRecordUpdate already defined
#endif
/** \brief Service Id for Dem_DisableDTCRecordUpdate() */
#define DEM_SID_DisableDTCRecordUpdate                           26U

#if (defined DEM_SID_EnableDTCRecordUpdate)
#error DEM_SID_EnableDTCRecordUpdate already defined
#endif
/** \brief Service Id for Dem_EnableDTCRecordUpdate() */
#define DEM_SID_EnableDTCRecordUpdate                            27U

#if (defined DEM_SID_GetDTCOfFreezeFrameRecord)
#error DEM_SID_GetDTCOfFreezeFrameRecord already defined
#endif
/** \brief Service Id for Dem_GetDTCOfFreezeFrameRecord() */
#define DEM_SID_GetDTCOfFreezeFrameRecord                        28U

#if (defined DEM_SID_GetFreezeFrameDataByDTC)
#error DEM_SID_GetFreezeFrameDataByDTC already defined
#endif
/** \brief Service Id for Dem_GetFreezeFrameDataByDTC() */
#define DEM_SID_GetFreezeFrameDataByDTC                          29U

#if (defined DEM_SID_GetFreezeFrameDataIdentifierByDTC)
#error DEM_SID_GetFreezeFrameDataIdentifierByDTC already defined
#endif
/** \brief Service Id for Dem_GetFreezeFrameDataIdentifierByDTC() */
#define DEM_SID_GetFreezeFrameDataIdentifierByDTC                30U

#if (defined DEM_SID_GetSizeOfFreezeFrame)
#error DEM_SID_GetSizeOfFreezeFrame already defined
#endif
/** \brief Service Id for Dem_GetSizeOfFreezeFrame() */
#define DEM_SID_GetSizeOfFreezeFrame                             31U

#if (defined DEM_SID_GetExtendedDataRecordByDTC)
#error DEM_SID_GetExtendedDataRecordByDTC already defined
#endif
/** \brief Service Id for Dem_GetExtendedDataRecordByDTC() */
#define DEM_SID_GetExtendedDataRecordByDTC                       32U

#if (defined DEM_SID_GetSizeOfExtendedDataRecordByDTC)
#error DEM_SID_GetSizeOfExtendedDataRecordByDTC already defined
#endif
/** \brief Service Id for Dem_GetSizeOfExtendedDataRecordByDTC() */
#define DEM_SID_GetSizeOfExtendedDataRecordByDTC                 33U


#if (defined DEM_SID_ClearDTC)
#error DEM_SID_ClearDTC already defined
#endif
/** \brief Service Id for Dem_ClearDTC() */
#define DEM_SID_ClearDTC                                         34U


#if (defined DEM_SID_DisableDTCStorage)
#error DEM_SID_DisableDTCStorage already defined
#endif
/** \brief Service Id for Dem_DisableDTCStorage() */
#define DEM_SID_DisableDTCStorage                                36U

#if (defined DEM_SID_EnableDTCStorage)
#error DEM_SID_EnableDTCStorage already defined
#endif
/** \brief Service Id for Dem_EnableDTCStorage() */
#define DEM_SID_EnableDTCStorage                                 37U

#if (defined DEM_SID_DisableEventStatusUpdate)
#error DEM_SID_DisableEventStatusUpdate already defined
#endif
/** \brief Service Id for Dem_DisableEventStatusUpdate() */
#define DEM_SID_DisableEventStatusUpdate                         38U

#if (defined DEM_SID_EnableEventStatusUpdate)
#error DEM_SID_EnableEventStatusUpdate already defined
#endif
/** \brief Service Id for Dem_EnableEventStatusUpdate() */
#define DEM_SID_EnableEventStatusUpdate                          39U


#if (defined DEM_SID_GetMILStatus)
#error DEM_SID_GetMILStatus already defined
#endif
/** \brief Service Id for Dem_GetMILStatus() */
#define DEM_SID_GetMILStatus                                     40U

#if (defined DEM_SID_GetOBDReadiness)
#error DEM_SID_GetOBDReadiness already defined
#endif
/** \brief Service Id for Dem_GetOBDReadiness() */
#define DEM_SID_GetOBDReadiness                                  42U

#if (defined DEM_SID_GetDistanceMIL)
#error DEM_SID_GetDistanceMIL already defined
#endif
/** \brief Service Id for Dem_GetDistanceMIL() */
#define DEM_SID_GetDistanceMIL                                   43U

#if (defined DEM_SID_GetWarmupCycleDTCclear)
#error DEM_SID_GetWarmupCycleDTCclear already defined
#endif
/** \brief Service Id for Dem_GetWarmupCycleDTCclear() */
#define DEM_SID_GetWarmupCycleDTCclear                           44U

#if (defined DEM_SID_GetDistanceDTCclear)
#error DEM_SID_GetDistanceDTCclear already defined
#endif
/** \brief Service Id for Dem_GetDistanceDTCclear() */
#define DEM_SID_GetDistanceDTCclear                              45U

#if (defined DEM_SID_GetMonitorStatus)
#error DEM_SID_GetMonitorStatus already defined
#endif
/** \brief Service Id for Dem_GetMonitorStatus() */
#define DEM_SID_GetMonitorStatus                                 46U

#if (defined DEM_SID_GetTimeMIL)
#error DEM_SID_GetTimeMIL already defined
#endif
/** \brief Service Id for Dem_GetTimeMIL() */
#define DEM_SID_GetTimeMIL                                       47U

#if (defined DEM_SID_GetTimeDTCclear)
#error DEM_SID_GetTimeDTCclear already defined
#endif
/** \brief Service Id for Dem_GetTimeDTCclear() */
#define DEM_SID_GetTimeDTCclear                                  48U


#if (defined DEM_SID_MainFunction)
#error DEM_SID_MainFunction already defined
#endif
/** \brief Service Id for Dem_MainFunction() */
#define DEM_SID_MainFunction                                     55U


/*------------------[Development error IDs and macros]----------------------*/

#if (DEM_DEV_ERROR_DETECT == STD_ON)

/* API service called with wrong parameter */

#if (defined DEM_E_PARAM_CONFIG)
#error DEM_E_PARAM_CONFIG already defined
#endif
#define DEM_E_PARAM_CONFIG    0x10U

#if (defined DEM_E_PARAM_ADDRESS)
#error DEM_E_PARAM_ADDRESS already defined
#endif
#define DEM_E_PARAM_ADDRESS   0x11U

#if (defined DEM_E_PARAM_DATA)
#error DEM_E_PARAM_DATA already defined
#endif
#define DEM_E_PARAM_DATA      0x12U

#if (defined DEM_E_PARAM_LENGTH)
#error DEM_E_PARAM_LENGTH already defined
#endif
#define DEM_E_PARAM_LENGTH    0x13U

/* API service called before DEM initialized */

#if (defined DEM_E_UNINIT)
#error DEM_E_UNINIT already defined
#endif
#define DEM_E_UNINIT          0x20U

/* No valid data available by the SW-C */

#if (defined DEM_E_NODATAAVAILABLE)
#error DEM_E_NODATAAVAILABLE already defined
#endif
#define DEM_E_NODATAAVAILABLE 0x30U


#if (defined DEM_REPORT_ERROR)
#error DEM_REPORT_ERROR already defined
#endif
/** \brief Makro for DET calls in DEM development-error-detection sections
 **
 **/
/* Deviation MISRA-1 */
#define DEM_REPORT_ERROR(ApiId, ErrorId) \
   Det_ReportError(DEM_MODULE_ID, 0U, (ApiId), (ErrorId))

#endif /* DEM_DEV_ERROR_DETECT */


/*------------------[Several helper macros]---------------------------------*/

#if (defined DEM_BIT_FIELD_VALUE_32)
#error DEM_BIT_FIELD_VALUE_32 already defined
#endif
/** \brief Shifts field with offset, and returns the masked value
 **
 ** Macro is intended for Gbi/Gbp getter functions.
 **/
/** Deviation MISRA-1 */
#define DEM_BIT_FIELD_VALUE_32(field, offset, mask) \
   ((uint32) ((uint32) ((uint32) (field) >> (offset)) & (uint32) (mask)))


#if (defined DEM_IS_BIT_SET_IN_ARRAY)
#error DEM_IS_BIT_SET_IN_ARRAY already defined
#endif
/** \brief Is bit set in an uint8-array */
/** Deviation MISRA-1 */
#define DEM_IS_BIT_SET_IN_ARRAY(Array, Idx) \
   (((Array)[(Idx) / 8U] & ((uint8) (1U << ((Idx) % 8U)))) != 0U)

#if (defined DEM_SET_BIT_IN_ARRAY)
#error DEM_SET_BIT_IN_ARRAY already defined
#endif
/** \brief Set bit in an uint8-array */
/** Deviation MISRA-1 */
#define DEM_SET_BIT_IN_ARRAY(Array, Idx) \
   ((Array)[(Idx) / 8U] |= (uint8)  (1U << ((Idx) % 8U)))

#if (defined DEM_CLR_BIT_IN_ARRAY)
#error DEM_CLR_BIT_IN_ARRAY already defined
#endif
/** \brief Clear bit in an uint8-array */
/** Deviation MISRA-1 */
#define DEM_CLR_BIT_IN_ARRAY(Array, Idx) \
   ((Array)[(Idx) / 8U] &= (uint8) ~((uint8) (1U << ((Idx) % 8U))))


#if (defined DEM_SET_BIT_32)
#error DEM_SET_BIT_32 already defined
#endif
/** \brief Set bit in an uint32 bitfield */
/** Deviation MISRA-1 */
#define DEM_SET_BIT_32(Bitfield, Idx) \
   ((Bitfield) |= (uint32) ((uint32) 1U << (Idx)))

#if (defined DEM_CLR_BIT_32)
#error DEM_CLR_BIT_32 already defined
#endif
/** \brief Clear bit in an uint32 bitfield */
/** Deviation MISRA-1 */
#define DEM_CLR_BIT_32(Bitfield, Idx) \
   ((Bitfield) &= (uint32) ~( (uint32) ((uint32) 1U << (Idx))))


#if (defined DEM_ATOMIC_SET_BIT_IN_ARRAY)
#error DEM_ATOMIC_SET_BIT_IN_ARRAY already defined
#endif
/** \brief Set bit in an uint8-array, atomic */
/** Deviation MISRA-1 */
#define DEM_ATOMIC_SET_BIT_IN_ARRAY(Array, Idx) \
   do { Dem_AtomicSetBit(&((Array)[(Idx) / 8U]), ((Idx) % 8U)); } while (0)

#if (defined DEM_ATOMIC_CLR_BIT_IN_ARRAY)
#error DEM_ATOMIC_CLR_BIT_IN_ARRAY already defined
#endif
/** \brief Clear bit in an uint8-array, atomic */
/** Deviation MISRA-1 */
#define DEM_ATOMIC_CLR_BIT_IN_ARRAY(Array, Idx) \
   do { Dem_AtomicClearBit(&((Array)[(Idx) / 8U]), ((Idx) % 8U)); } while (0)


#if (defined DEM_IS_BIT_SET)
#error DEM_IS_BIT_SET already defined
#endif
/** \brief Logical expression of the condition, that at least one bit, set in
 ** "Mask", is set in "Byte"
 **/
/** Deviation MISRA-1 */
#define DEM_IS_BIT_SET(Byte, Mask) \
   (((Byte) & (Mask)) != 0U)

#if (defined DEM_IS_UNMASKED_BIT_SET)
#error DEM_IS_UNMASKED_BIT_SET already defined
#endif
/** \brief Logical expression of the condition, that at least one unmasked bit
 ** is set in "Byte"
 **/
/** Deviation MISRA-1 */
#define DEM_IS_UNMASKED_BIT_SET(Byte, Mask) \
   (((Byte) & (uint8)(~(Mask))) != 0U)


#if (defined DEM_SET_MASK)
#error DEM_SET_MASK already defined
#endif
/** \brief General 'set bit macro' for uint8 */
/** Deviation MISRA-1 */
#define DEM_SET_MASK(Byte, Mask) ((Byte) |= (uint8)(Mask))
#if (defined DEM_CLR_MASK)
#error DEM_CLR_MASK already defined
#endif
/** \brief General 'clear bit macro' for uint8 */
/** Deviation MISRA-1 */
#define DEM_CLR_MASK(Byte, Mask) ((Byte) &= (uint8)(~(Mask)))

#if (defined DEM_IS_EV_ST_BIT_SET)
#error DEM_IS_EV_ST_BIT_SET already defined
#endif
/** \brief Is any bit set from mask in DTC status */
/** Deviation MISRA-1 */
#define DEM_IS_EV_ST_BIT_SET(EventId, Mask) \
   (DEM_IS_BIT_SET(Dem_DTCStatusMasks[(EventId)], (Mask)))

#if (defined DEM_SET_EV_ST_MASK)
#error DEM_SET_EV_ST_MASK already defined
#endif
/** \brief Set bits in DTCStatusMask */
/** Deviation MISRA-1 */
#define DEM_SET_EV_ST_MASK(EventId, Mask) \
   (DEM_SET_MASK(Dem_DTCStatusMasks[(EventId)], (Mask)))

#if (defined DEM_CLR_EV_ST_MASK)
#error DEM_CLR_EV_ST_MASK already defined
#endif
/** \brief Clear bits in DTCStatusMask */
/** Deviation MISRA-1 */
#define DEM_CLR_EV_ST_MASK(EventId, Mask) \
   (DEM_CLR_MASK(Dem_DTCStatusMasks[(EventId)], (Mask)))


#if (defined DEM_UNINITIALIZED)
#error DEM_UNINITIALIZED already defined
#endif
/** \brief DEM is not initialized */
#define DEM_UNINITIALIZED                 0

#if (defined DEM_PREINITIALIZED)
#error DEM_PREINITIALIZED already defined
#endif
/** \brief DEM is pre-initialized */
#define DEM_PREINITIALIZED                1

#if (defined DEM_INITIALIZED)
#error DEM_INITIALIZED already defined
#endif
/** \brief DEM is full initialized */
#define DEM_INITIALIZED                   2

#if (defined DEM_POSTINITIALIZED)
#error DEM_POSTINITIALIZED already defined
#endif
/** \brief DEM is post-initialized */
#define DEM_POSTINITIALIZED               3

/*==================[type definitions]======================================*/

/** \brief This type is used for the state-values of the initialization state
 ** of the DEM
 **
 ** Possible values: DEM_UNINITIALIZED, DEM_PREINITIALIZED, DEM_INITIALIZED or
 ** DEM_POSTINITIALIZED
 **/
typedef uint8 Dem_InitializationStateType;

/** \brief This type is for global counting of event Ids
 **
 ** This is done to avoid an overflow, if exactly 255 event Ids are used.
 **
 ** Note: It is derived from the maximal size of the type ::Dem_EventIdType.
 **/
typedef uint16 Dem_EvIdMaxType;

/** \brief This type is for local counting of event Ids
 **
 ** This is done to avoid an overflow, if exactly 255 event Ids are used.
 **
 ** Note: It is derived from the maximal size of the type ::Dem_EventIdType.
 **/
typedef uint16_least Dem_EvIdLeastType;

/** \brief This type is used as index type for the error-queue
 **
 ** Its size (uint8) is given by configuration.
 **/
typedef uint8 Dem_ErrorQueueIdxType;

/** \brief Return values of function Dem_GetEvIdByDTC() */
typedef enum
{
   DEM_EIBD_OK,
   DEM_EIBD_WRONG_DTC,
   DEM_EIBD_WRONG_DTCKIND,
   DEM_EIBD_WRONG_DTCORIGIN
} Dem_ReturnGetEvIdByDTCType;

/** \brief Event memory entry size type */
typedef uint8 Dem_SizeEvMemEntryType;

/** \brief Index of freeze frame class type
 **
 ** NumFFClass variables are also of this type. */
typedef uint8 Dem_FFClassIdxType;

/** \brief Index of freeze frame segment type
 **
 ** Note: The size of this type is defined by API
 ** Dem_GetFreezeFrameDataIdentifierByDTC().
 **
 ** NumFFSeg and MaxNumFFSeg variables are also of this type. */
typedef uint8 Dem_FFSegIdxType;

/** \brief Layout information of freeze frame classes */
typedef struct
{
   /** Number of freeze frame segments */
   const Dem_FFSegIdxType NumFFSegs;
   /** Data IDs of freeze frame segments - ACCESSED by API */
   CONSTP2CONST(uint16, AUTOMATIC, DEM_APPL_CONST) DataID;
   /** Positions of freeze frame segments */
   CONSTP2CONST(uint8, AUTOMATIC, DEM_CONST) StartByte;
   /** Sizes of freeze frame segments */
   CONSTP2CONST(uint8, AUTOMATIC, DEM_CONST) Size;
} Dem_FFClassType;

/** \brief Index of extended data class type
 **
 ** NumEDClass variables are also of this type. */
typedef uint8 Dem_EDClassIdxType;

/** \brief Index of extended data segment type
 **
 ** Note: The size of this type is defined by ISO14229-1.
 ** (ED RecordNumber = 0x01 ... 0xFE)
 **
 ** NumEDSeg and MaxNumEDSeg variables are also of this type. */
typedef uint8 Dem_EDSegIdxType;

/** \brief Layout information of extended data classes */
typedef struct
{
   /** Number of extended data segments */
   const Dem_EDSegIdxType NumEDSegs;
   /** Numbers of extended data segments */
   CONSTP2CONST(uint8, AUTOMATIC, DEM_CONST) Number;
   /** Positions of extended data segments */
   CONSTP2CONST(uint8, AUTOMATIC, DEM_CONST) StartByte;
   /** Sizes of extended data segments */
   CONSTP2CONST(uint8, AUTOMATIC, DEM_CONST) Size;
} Dem_EDClassType;

typedef uint8 Dem_HealingCyclesType;

typedef uint8 Dem_PriorityType;

/** \brief Status of the DTC Filter */
typedef struct
{
   Dem_DTCStatusMaskType      DTCStatusMask; /**< Filter mask on DTC status */
   Dem_DTCKindType            DTCKind;                     /**< Kind of DTC */
   Dem_DTCOriginType          DTCOrigin;                 /**< Origin of DTC */
   Dem_FilterWithSeverityType FilterWithSeverity;
                                            /**< Use severity for filtering */
   Dem_DTCSeverityType        DTCSeverity;     /**< Severity to filter with */
   Dem_FilterForFaultDetectionCounterType
                              FilterForFDC;      /**< Use FDC for filtering */
   Dem_EvIdMaxType            NextEventId;   /**< Index of DTC to read next */
} Dem_DTCFilterType;

/*------------------[bit definition for RTE- & C-callback function]----------*/


#if (defined DEM_RTE_CBK_INIT_MONITOR)
#error DEM_RTE_CBK_INIT_MONITOR already defined
#endif
#define DEM_RTE_CBK_INIT_MONITOR                      0x01U

#if (defined DEM_C_CBK_INIT_MONITOR)
#error DEM_C_CBK_INIT_MONITOR already defined
#endif
#define DEM_C_CBK_INIT_MONITOR                        0x02U


#if (defined DEM_RTE_CBK_TRIGGER_ON_EV_STATUS)
#error DEM_RTE_CBK_TRIGGER_ON_EV_STATUS already defined
#endif
#define DEM_RTE_CBK_TRIGGER_ON_EV_STATUS              0x04U

#if (defined DEM_C_CBK_TRIGGER_ON_EV_STATUS)
#error DEM_C_CBK_TRIGGER_ON_EV_STATUS already defined
#endif
#define DEM_C_CBK_TRIGGER_ON_EV_STATUS                0x08U


#if (defined DEM_RTE_CBK_FAULT_DETECTION_CTR)
#error DEM_RTE_CBK_FAULT_DETECTION_CTR already defined
#endif
#define DEM_RTE_CBK_FAULT_DETECTION_CTR               0x10U

#if (defined DEM_C_CBK_FAULT_DETECTION_CTR)
#error DEM_C_CBK_FAULT_DETECTION_CTR already defined
#endif
#define DEM_C_CBK_FAULT_DETECTION_CTR                 0x20U


typedef uint8 Dem_CbkPropertyType;
typedef Dem_EventIdType Dem_CbkIndexType;

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CbkFuncPtrInitMonitorType) (
   Dem_InitMonitorKindType InitMonitorKind);

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CbkFuncPtrTriggerOnEventType) (
   Dem_EventIdType             EventId,
   Dem_EventStatusExtendedType EventStatusOld,
   Dem_EventStatusExtendedType EventStatusNew);

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CbkFuncPtrGetFDCType) (
   Dem_EventIdType                                                EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC);

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CbkFuncPtrGetDataValueByDataIdType) (
   uint16                                 DataId,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIdBuffer);

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CbkFuncPtrGetExtDataRecType) (
   uint8                                  ExtendedDataRecordNumber,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) ExtendedDataRecord);

typedef struct
{
   Dem_EventIdType          EventId;
   Dem_CbkFuncPtrGetFDCType Function;
} Dem_FDCCallbackType;

typedef struct
{
   Dem_EventIdType  EventId;
   Dem_CbkIndexType CallbackIdx;
} Dem_CbkLookupTableType;

/*------------------[return-type definitions]-------------------------------*/

typedef P2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT)
   Dem_EntryDataPtrType;

/*==================[external function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[static internal function prototypes]-------------------*/

/** \brief Function to reset the non volatile DEM data
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \note Implementation is OEM specific.
 **/
extern FUNC(void, DEM_CODE) Dem_ResetNvData(void);

/** \brief Function to process (e.g. validate and/or store) the non volatile
 ** DEM data
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \note Implementation is OEM specific.
 **/
extern FUNC(void, DEM_CODE) Dem_ShutdownNvData(void);

/** \brief Function to store a complete freeze frame at the specified position
 ** in memory, by using the RTE-callback function
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] ServiceId  only in DEM_DEV_ERROR_DETECT lib-variant
 ** \param[in] EntryData
 ** \param[in] FFClass
 **/
extern FUNC(void, DEM_CODE) Dem_StoreFF(
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   uint8                                               ServiceId,
#endif /* DEM_DEV_ERROR_DETECT */
   P2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) EntryData,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass);

/** \brief Function to get the value of the specified event status extended
 ** bit of the given event
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 ** \param[in] EventStatusExtendedBit  only DEM_DTCSTATUSBIT_XXX values
 **
 ** \return Boolean value of the bit
 ** \retval TRUE  bit is set
 ** \retval FALSE bit is not set
 **/
extern FUNC(boolean, DEM_CODE) Dem_GetEvStBitVal(
   Dem_EventIdType             EventId,
   Dem_EventStatusExtendedType EventStatusExtendedMask);

/** \brief Function to get the event Id of the given DTC
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] DTC
 ** \param[in] DTCTranslationFormat
 ** \param[in] DTCOrigin
 ** \param[out] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 **
 ** \return Status of the operation of type ::Dem_ReturnGetEvIdByDTCType
 **/
extern FUNC(Dem_ReturnGetEvIdByDTCType, DEM_CODE) Dem_GetEvIdByDTC(
   Dem_DTCType                                     DTC,
   Dem_DTCKindType                                 DTCKind,
   Dem_DTCOriginType                               DTCOrigin,
   CONSTP2VAR(Dem_EventIdType, AUTOMATIC, DEM_VAR) EventId);

/** \brief Function to apply the DTC filter with the given event
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 ** \param[out] DTCStatus
 ** \param[out] FDC
 **
 ** \return Boolean value, if the filter matches the event configuration
 ** \retval TRUE  the filters match
 ** \retval FALSE the filters don't match
 **/
extern FUNC(boolean, DEM_CODE) Dem_ApplyDTCFilter(
   Dem_EventIdType       EventId,
   P2VAR(Dem_DTCStatusMaskType, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC);

/** \brief Function to search for an entry in the event memory by the given
 ** event Id
 **
 ** This functions checks up the right event memory and starts the search. All
 ** entries in this memory are checked.
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 ** \param[out] FoundEntry
 **
 ** \return Result of the searching
 ** \retval TRUE  entry was found
 ** \retval FALSE no entry exists
 **/
extern FUNC(boolean, DEM_CODE) Dem_SearchForEntry(
   Dem_EventIdType        EventId,
   CONSTP2VAR(
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT),
      AUTOMATIC, DEM_VAR) FoundEntry);

/** \brief Clear an event memory entry
 **
 ** Its freeze frames, extended data and the DTC status are also affected.
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EvMemEntry
 **/
extern FUNC(void, DEM_CODE) Dem_ClearEntry(
   CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
      EvMemEntry);

/** \brief Function to get the index of an extended data segment by the given
 ** extended data number
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EDClass
 ** \param[in] Number
 **
 ** \return Index of the extended data segment
 **/
extern FUNC(Dem_EDSegIdxType, DEM_CODE) Dem_FindEDNumIndex(
   CONSTP2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST) EDClass,
   const uint8                                         Number);

/** \brief Function to get the size of an freeze frame by the given freeze
 ** frame class
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] FFClass
 **
 ** \return Size of the freeze frame
 **/
extern FUNC(Dem_SizeEntryDataType, DEM_CODE) Dem_SizeOfFF(
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass);

/** \brief Function to get the size of the event memory entry data (ED + FFs)
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 **
 ** \return Size of entry data
 **/
extern FUNC(Dem_SizeEntryDataType, DEM_CODE) Dem_SizeOfEntryData(
   const Dem_EventIdType EventId);

/** \brief Function to get an pointer to the ED entry data of an event memory
 ** entry
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EvMemEntry
 **
 ** \return Pointer to the ED entry data
 **/
extern FUNC(Dem_EntryDataPtrType, DEM_CODE) Dem_EDEntryData(
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
      EvMemEntry);

/** \brief Function to get an pointer to the specified FF-record entry data of
 ** an event memory entry
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EvMemEntry
 ** \param[in] FFClass
 ** \param[in] FFIndex
 **
 ** \return Pointer to the FF-record entry data
 **/
extern FUNC(Dem_EntryDataPtrType, DEM_CODE) Dem_FFEntryData(
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
      EvMemEntry,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass,
   const Dem_FFIdxType                                 FFIndex);

/** \brief Function to shift entry data
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EntryData
 ** \param[in] offset
 ** \param[in] width
 **/
extern FUNC(void, DEM_CODE) Dem_ShiftData(
   P2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) EntryData,
   const Dem_SizeEntryDataType                         offset,
   Dem_SizeEntryDataType                               width);

/** \brief Function to copy entry data into destination buffer
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EntryData
 ** \param[in] DestBuffer
 ** \param[in] Number
 **
 ** \return Pointer to the DestBuffer
 **/
extern FUNC(void, DEM_CODE) Dem_DataCopy(
   P2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) EntryData,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                DestBuffer,
   Dem_SizeEntryDataType                                 Number);

/** \brief Function to convert an 24-bit DTC-group-value into the
 ** corresponding DTC-group-index
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] DTCGroup
 ** \param[out] Idx
 **
 ** \return Boolean value indication success
 ** \retval TRUE  could find corresponding DTC-group-index
 ** \retval FALSE wrong DTC-group-value
 **/
extern FUNC(boolean, DEM_CODE) Dem_GetIdxOfDTCGroup(
   Dem_DTCGroupType                 DTCGroup,
   P2VAR(uint8, AUTOMATIC, DEM_VAR) Idx);

/** \brief Error-Queue-Access-Function to read the latest entry
 **
 ** This function always reads the next event Id from the error-queue; it does
 ** not check if the error-queue is empty.
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **/
extern FUNC(void, DEM_CODE) Dem_ReadErrorQueueEntry(
   CONSTP2VAR(Dem_EventIdType, AUTOMATIC, DEM_VAR) EventId);

/** \brief Error-Queue-Access-Function to write the next entry
 **
 ** \reentrancy    reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 **
 ** \return Boolean value indication success
 ** \retval TRUE  an event Id was inserted to the error-queue
 ** \retval FALSE the error-queue was full
 **/
extern FUNC(boolean, DEM_CODE) Dem_WriteErrorQueueEntry(
   const Dem_EventIdType EventId);

/** \brief Function to search for an replaceable entry in the event memory by
 ** the given event Id using specific displacement-search-algorithm
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] OriginIdx  0 <= OriginIdx < DEM_MAXNUM_ORIGINS
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 ** \param[out] FoundEntry
 **
 ** \return Result of the searching
 ** \retval TRUE  entry was found
 ** \retval FALSE no entry exists
 **
 ** \note Implementation is OEM specific.
 **/
extern FUNC(boolean, DEM_CODE) Dem_SearchForEntryToReplace(
   uint8                  OriginIdx,
   Dem_EventIdType        EventId,
   CONSTP2VAR(
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT),
      AUTOMATIC, DEM_VAR) FoundEntry);

/** \brief Reset an DTC by its given event Id
 **
 ** If an entry exists, it will cleared by Dem_ClearEntry().
 **
 ** This function is called by the API Dem_ClearSingleDTC() and
 ** Dem_ClearGroupOfDTC().
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 **
 ** \note Implementation is OEM specific.
 **/
extern FUNC(void, DEM_CODE) Dem_ResetDTC(Dem_EventIdType EventId);

/** \brief Internal function to report event status
 **
 ** This helper function is called by the APIs Dem_ReportErrorstatus(),
 ** Dem_SetEventStatus() and Dem_MainFunction().
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EventId  0 < EventId <= (DEM_NUMBER_OF_EVENTS - 1U)
 ** \param[in] EventStatus
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_InternalSetEventStatus(
   Dem_EventIdType                    EventId,
   Dem_EventStatusType                EventStatus,
   P2VAR(boolean, AUTOMATIC, DEM_VAR) ErrorIndication);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/** \brief Pointer to the DTC status masks */
extern CONSTP2VAR(Dem_DTCStatusMaskType, DEM_CONST, DEM_VAR_NOINIT)
   Dem_DTCStatusMasks;

/** \brief Pointer to the clear pending DTC flags */
extern CONSTP2VAR(uint8, DEM_CONST, DEM_VAR_NOINIT) Dem_ClearPDTCFlags;

/** \brief Array holding the sizes of the 3 event memories */
extern CONST(Dem_SizeEvMemEntryType, DEM_CONST)
   Dem_SizeEventMem[DEM_MAXNUM_ORIGINS];

/** \brief Array holding the pointers to the 3 event memories */
extern CONSTP2VAR(Dem_EventMemoryEntryType, DEM_CONST, DEM_VAR_NOINIT)
   Dem_EventMem[DEM_MAXNUM_ORIGINS];

/** \brief Array holding the sizes of the 3 event mem. entry data areas */
extern CONST(Dem_SizeEntryDataType, DEM_CONST)
   Dem_SizeEntryData[DEM_MAXNUM_ORIGINS];

/** \brief Array holding the pointers to the 3 event mem. entry data areas */
extern CONSTP2VAR(Dem_EntryDataType, DEM_CONST, DEM_VAR_NOINIT)
   Dem_EntryData[DEM_MAXNUM_ORIGINS];

/** \brief Array holding the pointers to the 3 event mem. entry data free
 ** positions */
extern CONSTP2VAR(Dem_SizeEntryDataType, DEM_CONST, DEM_VAR_NOINIT)
   Dem_EntryDataFreePos[DEM_MAXNUM_ORIGINS];

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

#define DEM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/** \brief Status of the DEM
 **
 ** This flag is used to store the initialization state of the DEM. It's only
 ** be modified (written) by the functions Dem_PreInit(), Dem_Init() and
 ** Dem_Shutdown().
 **/
extern VAR(Dem_InitializationStateType, DEM_VAR) Dem_InitializationState;

/** \brief Status of DTC-filter
 **
 ** This variable is used from DTC-based filter functions.
 **
 ** It reflects the status of the DTC-filter setted by Dem_SetDTCFilter().
 **/
extern VAR(Dem_DTCFilterType, DEM_VAR) Dem_DTCFilter;

#define DEM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/** \brief Status of record-filter
 **
 ** This variable is used from freeze frame record-based filter functions.
 **
 ** It holds the current record index setted by Dem_SetDTCFilterForRecords().
 **/
extern VAR(uint8, DEM_VAR_NOINIT) Dem_RecordFilterIdx;

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/** \brief Lock for DCM access
 **
 ** This variable is used as a semaphore to prevent the Dem_MainFunction()
 ** from interrupting DCM access functions.
 **/
extern VAR(boolean, DEM_VAR_NOINIT) Dem_DcmAccessInProgress;

/** \brief Flag that specifies, if DTC record update is allowed */
extern VAR(boolean, DEM_VAR_NOINIT) Dem_DTCRecordUpdate;

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/** @} doxygen end group definition */
#endif /* ifndef DEM_INTERNAL_STATIC_H */
/*==================[end of file]===========================================*/
