#ifndef DEM_API_STATIC_SPECIFIC_H
/** \brief preprocessor exclusion definition */
#define DEM_API_STATIC_SPECIFIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all static external API declarations of the
 ** AUTOSAR module Dem, which are variant specific.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Api_Static_Specific.h.m4 2480 2011-03-21 16:00:06Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by Elektrobit Automotive GmbH and BMW Group
 ** All rights exclusively reserved for Elektrobit Automotive GmbH and
 ** BMW Group, unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Api_Static.h>                            /* Base class header */

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

/*==================[type definitions]======================================*/

/*------------------[Dem_DebugFilterType]-----------------------------------*/

/** \brief See API Dem_SetDMDebugFilter() */
typedef uint8 Dem_DebugFilterType;

#if (defined DEM_DMDEBUG_FILTER_ROEACTIVE)
#error DEM_DMDEBUG_FILTER_ROEACTIVE already defined
#endif
/** Response on event is active, i.e. XXX_DemTriggerOnErrorEntry is configured
 ** for this DTC. */
#define DEM_DMDEBUG_FILTER_ROEACTIVE  0x01U

#if (defined DEM_DMDEBUG_FILTER_LOCKABLE)
#error DEM_DMDEBUG_FILTER_LOCKABLE already defined
#endif
/** The DTC belongs to the DTC group DEM_DTC_GROUP_NETWORK_COM_DTCS */
#define DEM_DMDEBUG_FILTER_LOCKABLE   0x02U


/*------------------[internal type definitions]-----------------------------*/

/** \brief Occurrence counter type
 **
 ** Note: The size of this type is defined from 0x00/0x01 to 0xFF. */
typedef uint8 Dem_OccurrenceCtrType;


/*==================[external function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[Interface ECU State Manager <--> DEM]------------------*/

/** \brief API to cancel the DEM shutdown function
 **
 ** On call of this API the abortion of the process Dem_Shutdown() shall be
 ** caused.
 **
 ** This API is required to enable a faster restart of the DEM in case the ECU
 ** aborts its shutdown.
 **
 ** \service_id    ::DEM_SID_CancelShutdown
 ** \reentrancy    reentrant
 ** \synchronisity synchronous
 **/
extern FUNC(void, DEM_CODE) Dem_CancelShutdown(void);


/*------------------[Interface DCM <--> DEM]--------------------------------*/

/* --- Access DTCs and Status Information --- */

/** \brief Sets the DM debug filter
 **
 ** This function sets the filter to either ROEACTIVE (i.e. DTCs with
 ** Xxx_TriggerOnErrorEntry configured) or LOCKABLE (i.e. DTCs that belong to
 ** ::DEM_DTC_GROUP_NETWORK_COM_DTCS) and resets the internal counter to
 ** the first event.
 **
 ** \service_id    ::DEM_SID_SetDMDebugFilter
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] Filter  This parameter is used to select a set of DTCs.
 **
 ** \return success of operation
 ** \retval E_OK     if set of DM debug filter was successful
 ** \retval E_NOT_OK if set of DM debug filter failed
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDMDebugFilter(
   Dem_DebugFilterType Filter);


/** \brief Returns next DTC matching the DM debug filter
 **
 ** Return ::DEM_FILTERED_WRONG_DTCKIND if the DTCKind of the next filtered
 ** DTC does not match the input parameter DTCKind.
 ** Return ::DEM_FILTERED_NO_MATCHING_DTC if no DTC matching the current
 ** DMDebugFilter setting was found.
 **
 ** \service_id    ::DEM_SID_GetNextFilteredDMDebugDTC
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] DTCKind  Only filtered DTCs of this DTCKind shall be returned.
 **
 ** \param[out] DTC  Receives the DTC value returned by the function. If the
 ** return value is other than DEM_FILTERED_OK, this parameter does not
 ** contain valid data.
 **
 ** \return Status of the operation to retrieve a DTC from the DEM
 **/
extern FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)
Dem_GetNextFilteredDMDebugDTC(
   Dem_DTCKindType                              DTCKind,
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA) DTC);


/*------------------[Interface DEM <--> SW-Components]----------------------*/

/** \brief Wrapper-Function to call TriggerOnErrorEntry functions
 **
 ** This must be done by a wrapper, because it depends on configuration.
 **
 ** \param[in] EventId
 ** \param[in] Timestamp
 **/
extern FUNC(void, DEM_CODE) Dem_RteTriggerOnErrorEntry(
   const Dem_EventIdType EventId,
   const uint32          Timestamp);


/** \brief Wrapper-Function to call ClearEventAllowed functions
 **
 ** This must be done by a wrapper, because it depends on configuration.
 **
 ** \param[in] EventId
 ** \param[out] Allowed
 **/
extern FUNC(void, DEM_CODE) Dem_RteClearEventAllowed(
   const Dem_EventIdType                         EventId,
   CONSTP2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) Allowed);

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
#endif /* ifndef DEM_API_STATIC_SPECIFIC_H */
/*==================[end of file]===========================================*/
