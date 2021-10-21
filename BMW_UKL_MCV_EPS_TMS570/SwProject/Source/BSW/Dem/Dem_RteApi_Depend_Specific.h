#ifndef DEM_RTEAPI_DEPEND_SPECIFIC_H
/** \brief preprocessor exclusion definition */
#define DEM_RTEAPI_DEPEND_SPECIFIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains variant specific dependent external API declarations which
 ** are used by SW-Components and BSWs.
 **
 ** \project AUTOSAR Standard Core
 ** \author Oliver Hoeft
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_RteApi_Depend_Specific.h 1438 2008-05-26 12:37:46Z masc2461 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2009 by Elektrobit Automotive GmbH
 ** All rights exclusively reserved for Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Api_Cfg_Specific.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

#if (DEM_INCLUDE_RTE == STD_OFF)

#if (DEM_USE_INDICATOR == STD_ON)

/*------------------[Dem_IndicatorIdType]-----------------------------------*/

/** \brief Used to request a indicator type
 **
 ** value: indicator lamp ID */
typedef uint8 Dem_IndicatorIdType;


/*------------------[Dem_IndicatorStatusType]-------------------------------*/

/** \brief Used to return the status of Dem_GetIndicatorStatus() and
 ** Dem_GetMILStatus() */
typedef uint8 Dem_IndicatorStatusType;

#if (defined DEM_INDICATOR_OFF)
#error DEM_INDICATOR_OFF already defined
#endif
/** Indicator off */
#define DEM_INDICATOR_OFF        0x00U

#if (defined DEM_INDICATOR_CONTINUOUS)
#error DEM_INDICATOR_CONTINUOUS already defined
#endif
/** Continuous on */
#define DEM_INDICATOR_CONTINUOUS 0x01U

#if (defined DEM_INDICATOR_BLINKING)
#error DEM_INDICATOR_BLINKING already defined
#endif
/** Blinking state */
#define DEM_INDICATOR_BLINKING   0x02U

#if (defined DEM_INDICATOR_BLINK_CONT)
#error DEM_INDICATOR_BLINK_CONT already defined
#endif
/** Continuous and blinking mode. The SW-C for indicator is responsible to
 ** decide if the indicator is blinking or continuously on. */
#define DEM_INDICATOR_BLINK_CONT 0x03U

#endif /* DEM_USE_INDICATOR */

#endif /* DEM_INCLUDE_RTE */

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/* --- Get DEM statistical data / legislated data / indicator status --- */

#if (DEM_USE_INDICATOR == STD_ON)

/** \brief Reads the indicator-status
 **
 ** This function shall be used to read the indicator-status derived from the
 ** event status as a summary of all assigned events.
 **
 ** Configuration: The assignment for the Dem_IndicatorId to indicator has to
 ** be done. Examples for indicators: lamps, different text messages, icons,
 ** ...
 **
 ** \service_id    ::DEM_SID_GetIndicatorStatus
 ** \reentrancy    non reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] IndicatorId  Number of indicator
 **
 ** \param[out] IndicatorStatus  Status of the indicator, like on, off,
 ** blinking.
 **
 ** \return success of operation
 ** \retval E_OK     Operation was successful
 ** \retval E_NOT_OK Operation failed or is not supported
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus(
   Dem_IndicatorIdType                                      IndicatorId,
   P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus);

#endif /* DEM_USE_INDICATOR */

#if (DEM_USE_ENABLE_CONDITION == STD_ON)

/** \brief Function to set enable condition
 **
 ** This API shall be used to set the enable condition. For each event an
 ** enable condition value is assigned to. An enable condition specifies
 ** a certain number of checks (e.g. correct voltage range) for an event
 ** before the event can be qualified as confirmed.
 **
 ** Configuration: Required configuration parameters per event:
 ** - EnableConditionID
 ** - EnableConditionStatus
 **
 ** This API is optional and depends on the automotive manufacturer.
 **
 ** \service_id    ::DEM_SID_SetEnableCondition
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] EnableConditionID  This parameter identifies the enable
 ** condition.
 **
 ** \param[in] ConditionFulfilled  This parameter specifies whether the
 ** enable condition assigned to the EnableConditionID is fulfilled (TRUE)
 ** or not fulfilled (FALSE).
 **
 ** \return In case the enable condition could be set successfully the
 ** API call returns E_OK. If the setting of the enable condition failed
 ** the return value of the function is E_NOT_OK.
 **
 ** \note Not implemented yet.
 **/
extern FUNC(Std_ReturnType, DEM_CODE)Dem_SetEnableCondition(
   uint8     EnableConditionID,
   boolean   ConditionFulfilled);

#endif /* DEM_USE_ENABLE_CONDITION */

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_RTEAPI_DEPEND_SPECIFIC_H */
/*==================[end of file]===========================================*/
