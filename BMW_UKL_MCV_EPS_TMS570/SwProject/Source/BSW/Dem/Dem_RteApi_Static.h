#ifndef DEM_RTEAPI_STATIC_H
/** \brief preprocessor exclusion definition */
#define DEM_RTEAPI_STATIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains static external API declarations which are used by
 ** SW-Components and BSWs.
 **
 ** \project AUTOSAR Standard Core
 ** \author Stephanie Muehlenmeister
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_RteApi_Static.h 2480 2011-03-21 16:00:06Z olho2924 $
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

/*==================[external function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[Interface SW-Components and BSW <--> DEM]--------------*/

/** \brief Function to reset the event status
 **
 ** This service shall be used to reset the Event Status stored in the Event
 ** Memory in the DEM, without the usage of API Dem_SetEventStatus(EventId,
 ** Passed), because no new test result is available at this time.
 **
 ** With this API the status bit "Failed" defined by
 ** Dem_EventStatusExtendedType is set to 0. API is called by Monitor
 ** Function.
 **
 ** Refer to ISO14229: DTC Status Bit Definition, Table D.14, Bit0 Test
 ** failed.
 **
 ** Dem_ResetEventStatus does not influence the status bit 6
 ** ("testNotCompletedThisMonitoringCycle")
 **
 ** No API parameter checks required.
 **
 ** Caveats: DEM configuration during integration of Monitor Functions is
 ** is system specific
 **
 ** Configuration: EventId
 **
 ** \service_id    ::DEM_SID_ResetEventStatus
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Identification of an Event by assigned EventID.
 ** The EventID is configured in the DEM.
 ** - Min: 1(0: Indication of no Event or Failure)
 ** - Max: Result of configuration of EventId's in DEM (Max is either 255 or
 **   65535)
 **
 ** \return success of operation
 ** \retval E_OK     reset of event status was successful
 ** \retval E_NOT_OK reset of event status failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus(
   Dem_EventIdType EventId);


/** \brief Function to prestore a freeze frame
 **
 ** This API call is used to capture the FreezeFrame data for a specific event
 ** ID before the Monitor Function reports the event status Failed to the
 ** DEM by calling Dem_SetEventStatus() (e.g. rapid changing of environmental
 ** data during running failure monitoring phase).
 **
 ** If the DEM does not receive any request to pre-store a FreezeFrame,
 ** FreezeFrame capture is linked to the API call Dem_SetEventStatus(). This
 ** API call triggers the FreezeFrame storage.
 **
 ** If Dem_SetEventStatus(EventId, Passed) is called the corresponding
 ** pre-stored FreezeFrame is discarded (same behaviour like
 ** Dem_ClearPrestoredFreezeFrame()). The API call Dem_ResetEventStatus() does
 ** not influence the pre-stored FreezeFrame.
 **
 ** API is called from Monitor Function.
 **
 ** No API parameter checks required.
 **
 ** Caveats: DEM configuration during integration of Monitor Functions is
 ** system specific.
 **
 ** Configuration: During configuration the DEM the capability of pre-store
 ** functionality for the required event has to be defined.
 **
 ** \service_id    ::DEM_SID_PrestoreFreezeFrame
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Identification of an Event by assigned Event ID.
 ** The Event ID is configured in the DEM.
 ** - Min: 1 (0: Indication of no Event or Failure)
 ** - Max: Result of configuration of Event ID's in DEM (Max is either 255 or
 **   65535)
 **
 ** \return success of operation
 ** \retval E_OK     PreStoreFreezeFrame was successful
 ** \retval E_NOT_OK PreStoreFreezeFrame failed
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame(
   Dem_EventIdType EventId);


/** \brief Function to clear a prestored freeze frame
 **
 ** The API shall be called to delete or release the prestored FreezeFrame for
 ** specific Event ID. If the API Dem_SetEventStatus() (passed|failed) is
 ** called it has the same effect - that means it's not necessary to call the
 ** API Dem_ClearPrestoredFreezeFrame() directly after Dem_SetEventStatus().
 **
 ** Caveats: DEM configuration during integration of Monitor Functions is
 ** system specific.
 **
 ** Configuration: During integration in the DEM the capability of pre-store
 ** functionality for the required event has to be defined.
 **
 ** \service_id    ::DEM_SID_ClearPrestoredFreezeFrame
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Identification of an Event by assigned Event ID.
 ** The Event ID is configured in the DEM.
 ** - Min: 1 (0: Indication of no Event or Failure)
 ** - Max: Result of configuration of Event IDs in DEM (Max is either 255 or
 **   65535)
 **
 ** \return success of operation
 ** \retval E_OK     ClearPreStoreFreezeFrame was successful
 ** \retval E_NOT_OK ClearPreStoreFreezeFrame failed
 **
 ** \note Not fully implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame(
   Dem_EventIdType EventId);


/** \brief Report begin or end of an operation cycle
 **
 ** DEM shall be called by the SW-Component as soon as it detects the status
 ** change of the CycleState for the Operation Cycle.
 **
 ** This function can be DEM internal for DEM self calculated operation
 ** cycles.
 **
 ** Configuration: The OperationCycleId shall be configured in view of sender
 ** receiver communication.
 **
 ** \service_id    ::DEM_SID_SetOperationCycleState
 ** \reentrancy    non reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] OperationCycleId  Identification of operation cycle, like power
 ** cycle, driving cycle, ... (0 <= OpCycleId < DEM_NUM_OPCYCLES)
 **
 ** \param[in] CycleState  uint8 (Start, End)
 **
 ** \return success of operation
 ** \retval E_OK     set of operation cycle was successful
 ** \retval E_NOT_OK set of operation cycle failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState(
   Dem_OperationCycleIdType    OperationCycleId,
   Dem_OperationCycleStateType CycleState);


/** \brief Function to get the extended status of diagnostic events
 **
 ** This API shall be used to read the event status from the DEM. This API is
 ** provided to be used by SW-Components or other basic software modules
 ** e.g. FIM.
 **
 ** Bit 0 is set to 1 if the last event status update by API
 ** Dem_SetEventStatus (Passed | Failed) was called with failed. The status
 ** is set to 0 if Dem_SetEventStatus is called with passed, on tester
 ** clear command and by API Dem_ResetEventStatus.
 ** Bit 0 and 6 is intended to set/reset monitor inhibit or default.
 **
 ** Bit 1 is set if at least one time the API Dem_SetEventStatus (passed |
 ** failed) is called with failed this cycle.
 ** Intended to be used for defaults reset only at next key on.
 **
 ** Bit 2 is set when associated DTC becomes available in Mode07 (currently
 ** corresponds to ISO pending bit)
 ** Intended to be used for the control of IUMPR counters.
 **
 ** Bit 3 is set when associated DTC becomes available in Mode03 (currently
 ** corresponds to ISO confirmed bit)
 ** Could be used to set e.g. service request message.
 **
 ** Bit 4 and 5 is currently not supported but can be extended if needed for
 ** interface Xxx_Dem_TriggerOnEventStatus.
 **
 ** Bit 6 is set if at least one time the API Dem_SetEventStatus (passed |
 ** failed) is called within this cycle (the usage of different cycles is
 ** application-specific, if only one cycle is the differentiation is
 ** obsolete).
 **
 ** Bit 7 reports the status of any warning indicators associated with a
 ** particular DTC.
 **
 ** For the DCM the API Dem_GetStatusOfDTC() is used.
 **
 ** \service_id    ::DEM_SID_GetEventStatus
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Identification of an Event by assigned Event ID.
 ** The Event ID is configured in the DEM.
 ** - Min: 1 (0: Indication of no Event)
 ** - Max: Result of configuration of Event IDs in DEM (Max is either 255 or
 **   65535)
 **
 ** \param[out] EventStatusExtended  for explanation see
 ** ::Dem_EventStatusExtendedType
 **
 ** \return success of operation
 ** \retval E_OK     get of event status was successful
 ** \retval E_NOT_OK get of event status failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus(
   Dem_EventIdType     EventId,
   P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, DEM_APPL_DATA)
                       EventStatusExtended);


/** \brief Function to check if an events was failed (since last clear)
 **
 ** This API shall be used to read Bit 0 of ::Dem_EventStatusExtendedType from
 ** the DEM.
 **
 ** For the DCM the API Dem_GetStatusOfDTC() is used.
 **
 ** Configuration: EventId
 **
 ** \service_id    ::DEM_SID_GetEventFailed
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Identification of an Event by assigned Event ID.
 ** The Event ID is configured in the DEM.
 ** - Min: 1 (0: Indication of no Event)
 ** - Max: Result of configuration of Event IDs in DEM (Max is either 255 or
 **   65535)
 **
 ** \param[out] EventFailed
 ** - TRUE Last Failed
 ** - FALSE not Last Failed
 **
 ** \return success of operation
 ** \retval E_OK     get of event failed was successful
 ** \retval E_NOT_OK get of event failed failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed(
   Dem_EventIdType                             EventId,
   P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)    EventFailed);


/** \brief Function to check if an events was tested
 **
 ** This API shall be used to read negated Bit 6 of
 ** ::Dem_EventStatusExtendedType from the DEM.
 **
 ** For the DCM the API Dem_GetStatusOfDTC() is used.
 **
 ** Configuration: EventId
 **
 ** \service_id    ::DEM_SID_GetEventTested
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Identification of an Event by assigned Event ID.
 ** The Event ID is configured in the DEM.
 ** - Min: 1 (0: Indication of no Event)
 ** - Max: Result of configuration of Event IDs in DEM (Max is either 255 or
 **   65535)
 **
 ** \param[out] EventTested
 ** - TRUE event tested this cycle
 ** - FALSE event not tested this cycle
 **
 ** \return success of operation
 ** \retval E_OK     get of event state "tested" was successful
 ** \retval E_NOT_OK get of event state "tested" failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested(
   Dem_EventIdType                            EventId,
   P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)   EventTested);


/** \brief Function to get the DTC of an event
 **
 ** Gets the DTC which is mapped to EventId by DEM Configuration.
 **
 ** Configuration: Mapping of Events to DTCs is configured in DEM. Mapping is
 ** "n to 1" or "1 to n".
 **
 ** \service_id    ::DEM_SID_GetDTCOfEvent
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EventId  Identification of an Event by assigned Event ID.
 ** The Event ID is configured in the DEM.
 ** - Min: 1 (0: Indication of no Event or Failure)
 ** - Max: Result of configuration of Event IDs in DEM (Max is either 255 or
 **   65535)
 **
 ** \param[in] DTCKind  This parameter defines the requested DTC, either
 ** OBD-relevant or non OBD-relevant.
 **
 ** \param[out] DTCOfEvent  Receives the DTC value returned by the function.
 ** If the return value of the function is other than OK this parameter does
 ** not contain valid data.
 **
 ** \param[out] StatusDTCOfEvent  Status of the operation of type
 ** ::Dem_ReturnGetDTCOfEventType
 **
 ** \return success of operation
 ** \retval E_OK     get of DTC was successful
 ** \retval E_NOT_OK get of DTC failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent(
   Dem_EventIdType                                 EventId,
   Dem_DTCKindType                                 DTCKind,
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)    DTCOfEvent,
   P2VAR(Dem_ReturnGetDTCOfEventType, AUTOMATIC, DEM_APPL_DATA)
                                                   StatusDTCOfEvent);


/** \brief Function to set a data value to a specific data identifier
 **
 ** This API shall be used to set a data value assigned to a specific data
 ** identifier. The list of data identifiers is OEM specific and has to be
 ** fixed at configuration time. Only simple data types (uint8...uint32;
 ** sint8...sint32) are allowed. Structured data types (struct, array) are
 ** not allowed.
 **
 ** Configuration: Required configuration parameters:
 ** - OemID
 ** - real Name of the assigned value
 **
 ** \service_id    ::DEM_SID_SetValueByOemId
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] OemID  This OEM specific parameter identifies a data value
 ** the DEM requires for internal processing, e.g. vehicle speed or mileage.
 **
 ** \param[in] DemDataValueByDataIDBufferLength  Data length of the value
 ** to be set
 **
 ** \param[out] DemDataValueByDataIDBuffer  Pointer to the buffer with the
 ** value to be set
 **
 ** \return In case the data value could be set successfully the API call
 ** returns E_OK. If the setting of the data value failed the return value
 ** of the function is E_NOT_OK.
 **
 ** \note Not implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetValueByOemId(
   uint16                                 OemID,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer,
   uint8                                  DemDataValueByDataIDBufferLength);


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
#endif /* ifndef DEM_RTEAPI_STATIC_H */
/*==================[end of file]===========================================*/
