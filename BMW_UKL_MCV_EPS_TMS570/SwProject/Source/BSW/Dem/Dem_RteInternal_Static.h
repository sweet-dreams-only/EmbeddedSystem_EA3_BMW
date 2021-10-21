#if (!defined DEM_RTEINTERNAL_STATIC_H)
/** \brief preprocessor exclusion definition */
#define DEM_RTEINTERNAL_STATIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains static internal API declarations which are used by
 ** SW-Components and internal type definitions which are used by both, the
 ** Dem and SW-Components.
 **
 ** \project AUTOSAR Standard Core
 ** \author Stephanie Muehlenmeister
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_RteInternal_Static.h 2061 2010-01-18 12:10:39Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2008 by Elektrobit Automotive GmbH
 ** All rights exclusively reserved for Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */
/* Start Nxtr Patch block. Added to workaround usrostype.h inclusion of Rte_Type.h */
#include "Rte_Type.h"
#include "Dem_Api_Cfg.h"
#if (!defined DEM_INCLUDE_RTE)
	#define DEM_INCLUDE_RTE STD_OFF
#endif
/* End Nxtr Patch Block */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*------------------[Dem_EventIdType]---------------------------------------*/

/** \brief Identification of an event by assigned EventId. The EventId is
 ** configured in the DEM.
 **
 ** Example:
 ** - 1 refers to Monitor Function x,
 ** - 2 refers to Monitor Function y, ...
 **
 ** Small and encapsulated systems will only use uint8 for EventId definition
 ** due to resource optimization. Systems with enough resources shall use
 ** uint16. For Monitor Functions using uint8 adaptions might be required to
 ** ensure compatibility between different data types. */
#if (DEM_LIDS == STD_OFF)
typedef uint8  Dem_EventIdType;
#elif (DEM_LIDS == STD_ON)
typedef uint16 Dem_EventIdType;
#else
#error DEM_LIDS is neither set to STD_OFF nor STD_ON, check your build system
#endif


/*------------------[Dem_DTCType]-------------------------------------------*/

/** \brief Diagnostic Trouble Code (DTC) assigned to each event stored in the
 ** event memory. The DTC is configured in the DEM.
 **
 ** The DEM uses always a 3 Byte definition with the following
 ** representations.
 **
 ** For UDS services, the DTC size is 3 bytes (HighByte, MiddleByte and
 ** LowByte). The Dem services shall report these DTC as a uint32 with byte 0
 ** = LowByte, byte 1 = MiddleByte and byte 2 = HighByte. The byte 3 of the
 ** uint32 is free.
 **
 ** For OBD services there are only two bytes (HighByte, LowByte) used. The
 ** Dem services shall report these DTC as a uint32 with byte 1 = LowByte and
 ** byte 2 = HighByte, byte 3 being free and byte 0 = 0x00. */
typedef uint32 Dem_DTCType;


#if (DEM_INCLUDE_RTE == STD_OFF) /* Nxtr Patch. Added to workaround usrostype.h inclusion of Rte_Type.h */
/*------------------[Dem_EventStatusType]-----------------------------------*/

/** \brief See API Dem_SetEventStatus()
 **
 ** 0x04..0x1F: reserved
 **
 ** 0x20..0xFF: DEM_EVENT_STATUS_<Custom>:
 ** Monitor Function reports custom status, optional, for complex OBD
 ** applications and / or transitions of, e.g. misfire entries.
 **
 ** \note Custom Event Status is NOT supported in this version. */
typedef uint8 Dem_EventStatusType;

#if (defined DEM_EVENT_STATUS_PASSED)
#error DEM_EVENT_STATUS_PASSED already defined
#endif
/** Monitor Function reports test result passed */
#define DEM_EVENT_STATUS_PASSED      0x00U

#if (defined DEM_EVENT_STATUS_FAILED)
#error DEM_EVENT_STATUS_FAILED already defined
#endif
/** Monitor Function reports test result failed */
#define DEM_EVENT_STATUS_FAILED      0x01U

#if (defined DEM_EVENT_STATUS_PREPASSED)
#error DEM_EVENT_STATUS_PREPASSED already defined
#endif
/** Monitor Function reports test result passed */
#define DEM_EVENT_STATUS_PREPASSED   0x02U

#if (defined DEM_EVENT_STATUS_PREFAILED)
#error DEM_EVENT_STATUS_PREFAILED already defined
#endif
/** Monitor Function reports test result failed */
#define DEM_EVENT_STATUS_PREFAILED   0x03U


/*------------------[Dem_DTCKindType]---------------------------------------*/

/** \brief Used to define the DTC kind (type) */
typedef uint8 Dem_DTCKindType;

#if (defined DEM_DTC_KIND_ALL_DTCS)
#error DEM_DTC_KIND_ALL_DTCS already defined
#endif
/** Select all DTC's */
#define DEM_DTC_KIND_ALL_DTCS          0x01U

#if (defined DEM_DTC_KIND_EMISSION_REL_DTCS)
#error DEM_DTC_KIND_EMISSION_REL_DTCS already defined
#endif
/** Select emission related DTCs */
#define DEM_DTC_KIND_EMISSION_REL_DTCS 0x02U


/*------------------[Dem_EventStatusExtendedType]---------------------------*/

/** \brief See API Dem_GetEventStatus()
 **
 ** Used in Dem_GetEventStatus() and Xxx_TriggerOnEventStatus().
 ** - Bit0: testFailed (= 1; Passed = 0)
 ** - Bit1: testFailedThisOperationCycle (= 1; not yet failed this cycle = 0)
 ** - Bit2: pendingDTC (= 1; Not Pending DTC status = 0)
 ** - Bit3: confirmedDTC (= 1; Not Confirmed DTC status = 0)
 ** - Bit4: testNotCompletedSinceLastClear (= 1; Test Completed Since Last
 **         Clear = 0)
 ** - Bit5: testFailedSinceLastClear (= 1; test not Failed Since Last Clear
 **         = 0)
 ** - Bit6: testNotCompletedThisOperationCycle (= 1; Completed this cycle = 0)
 ** - Bit7: warningIndicatorRequested (= 1) */
typedef uint8 Dem_EventStatusExtendedType;

/*------------------[Dem_OperationCycleIdType]------------------------------*/

/** \brief Used to select the individual operation cycle in the API
 ** Dem_SetOperationCycleState()
 **
 ** value: The OperationCycleId, e.g. the ignition cycle is assigned to an
 **        ID. */
typedef uint8 Dem_OperationCycleIdType;


/*------------------[Dem_OperationCycleStateType]---------------------------*/

/** \brief Used to indicate start and end of operation cycle by API
 ** Dem_SetOperationCycleState() */
typedef uint8 Dem_OperationCycleStateType;

#if (defined DEM_CYCLE_STATE_START)
#error DEM_CYCLE_STATE_START already defined
#endif
/** Start of operation cycle */
#define DEM_CYCLE_STATE_START 0x01U

#if (defined DEM_CYCLE_STATE_END)
#error DEM_CYCLE_STATE_END already defined
#endif
/** End of operation cycle */
#define DEM_CYCLE_STATE_END   0x02U


/*------------------[Dem_InitMonitorKindType]-------------------------------*/

/** \brief See API Xxx_InitMonitor{EventId}() */
typedef uint8 Dem_InitMonitorKindType;

#if (defined DEM_INIT_MONITOR_CLEAR)
#error DEM_INIT_MONITOR_CLEAR already defined
#endif
/** Monitor Function of the EventId is cleared and internal values and states
  * are reseted */
#define DEM_INIT_MONITOR_CLEAR    0x01U

#if (defined DEM_INIT_MONITOR_RESTART)
#error DEM_INIT_MONITOR_RESTART already defined
#endif
/** Monitor Function of the EventId is requested to restart */
#define DEM_INIT_MONITOR_RESTART  0x02U


/*------------------[Dem_DTCStatusMaskType]---------------------------------*/

/** \brief Used to set the current status
 **
 ** value: - 0x00 ... 0xFF: Match DTCStatusMask as defined in ISO14229-1 */
typedef uint8 Dem_DTCStatusMaskType;


/*------------------[Dem_FaultDetectionCounterType]-------------------------*/

/** \brief Used to report Fault Detection Counter via API
 ** Dem_GetFaultDetectionCounter
 **
 ** value: -128dec...127dec: PASSED ... FAILED according to ISO 14229-1 */
typedef sint8 Dem_FaultDetectionCounterType;


/*------------------[Dem_ReturnGetDTCOfEventType]---------------------------*/

/** \brief Used to return the status of Dem_GetDTCOfEvent() */
typedef uint8 Dem_ReturnGetDTCOfEventType;

#if (defined DEM_GET_DTCOFEVENT_OK)
#error DEM_GET_DTCOFEVENT_OK already defined
#endif
/** DTC successfully returned */
#define DEM_GET_DTCOFEVENT_OK                0x00U

#if (defined DEM_GET_DTCOFEVENT_WRONG_EVENTID)
#error DEM_GET_DTCOFEVENT_WRONG_EVENTID already defined
#endif
/** Wrong EventId */
#define DEM_GET_DTCOFEVENT_WRONG_EVENTID     0x01U

#if (defined DEM_GET_DTCOFEVENT_WRONG_DTCKIND)
#error DEM_GET_DTCOFEVENT_WRONG_DTCKIND already defined
#endif
/** DTC kind wrong */
#define DEM_GET_DTCOFEVENT_WRONG_DTCKIND     0x02U

#endif /* Nxtr Patch. (DEM_INCLUDE_RTE == STD_OFF) Nxtr add to workaround usrostype.h inclusion of Rte_Type.h */

/*==================[external function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[Interface SW-Components <--> DEM]----------------------*/

/** \brief Function to report the status of diagnostic events
 **
 ** Service for reporting the Event Status to the DEM. This service shall be
 ** used to report an Event Status as soon as a new test result is available.
 **
 ** This Service stores the event to the Event Memory.
 **
 ** API is called from the Monitor Function.
 **
 ** No API parameter checks required.
 **
 ** Caveats: DEM configuration during integration of Monitor Functions is
 ** system specific.
 **
 ** \service_id    ::DEM_SID_SetEventStatus
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
 **
 ** \return success of operation
 ** \retval E_OK     set of event status was successful
 ** \retval E_NOT_OK set of event status failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(
   Dem_EventIdType     EventId,
   Dem_EventStatusType EventStatus);

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
#endif /* if !defined( DEM_RTEINTERNAL_STATIC_H ) */
/*==================[end of file]===========================================*/
