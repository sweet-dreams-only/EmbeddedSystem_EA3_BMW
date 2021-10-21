#ifndef DEM_INTERNAL_STATIC_SPECIFIC_H
/** \brief preprocessor exclusion definition */
#define DEM_INTERNAL_STATIC_SPECIFIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all configuration independent internal API declarations
 ** of the AUTOSAR module Dem, which are variant specific.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Internal_Static_Specific.h 2489 2011-03-31 14:12:17Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by Elektrobit Automotive GmbH and BMW Group
 ** All rights exclusively reserved for Elektrobit Automotive GmbH and
 ** BMW Group, unless expressly agreed to otherwise
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

#include <Dem_Internal_Static.h>                       /* Base class header */

/*==================[macros]================================================*/

/*------------------[variant-specific status-bit handling macros]-----------*/

#if (defined DEM_SPECIFIC_DTCSTATUSBITS_ON_REPORT)
#error DEM_SPECIFIC_DTCSTATUSBITS_ON_REPORT already defined
#endif
/** \brief additional variant-specific event status-bit handling on event
 ** reporting
 **
 ** These bit(s) are set for failed events in Dem_Init() and
 ** Dem_InternalSetEventStatus().
 **
 ** \note DEM_DTCSTATUSBIT_PDTC (BMW-specific, see CR70107) and
 **       DEM_DTCSTATUSBIT_CDTC will be set during event memory entry
 **       processing in Dem_MainFunction().
 **/
#define DEM_SPECIFIC_DTCSTATUSBITS_ON_REPORT 0U

#if (defined DEM_SPECIFIC_DTCSTATUSBITS_FOR_ENTRY)
#error DEM_SPECIFIC_DTCSTATUSBITS_FOR_ENTRY already defined
#endif
/** \brief additional variant-specific event status-bit handling for event
 ** memory entries
 **
 ** These bit(s) are set for new entries in Dem_ProcessEventEntry().
 **
 ** These bit(s) are cleared for removed (displaced or healed) entries in
 ** Dem_ProcessEventEntry() and Dem_UpdateHealingCounter().
 **
 ** \note BMW-specific DEM_DTCSTATUSBIT_PDTC handling (see CR70107 & CR61439)
 **/
#define DEM_SPECIFIC_DTCSTATUSBITS_FOR_ENTRY (DEM_DTCSTATUSBIT_PDTC)


/*------------------[variant-specific hook macros]--------------------------*/

/** \brief hook for variant-specific handling in Dem_ProcessEventEntry() */
#define DEM_SPECIFIC_HOOK_INITENTRY(EvMemEntry)                  \
   do                                                            \
   {                                                             \
      /* set inital value of occurrence counter */               \
      (EvMemEntry)->OccurrenceCounter = 0U;                      \
   }                                                             \
   while (0)

/** \brief hook for variant-specific handling in Dem_StoreED() */
#define DEM_SPECIFIC_HOOK_EDSTORAGE(EvMemEntry)                  \
   do                                                            \
   {                                                             \
      /* condition byte needs not to be handled here */          \
                                                                 \
      /* increase occurrence counter */                          \
      if ((EvMemEntry)->OccurrenceCounter < 0xFFU)               \
      {                                                          \
         ++((EvMemEntry)->OccurrenceCounter);                    \
      }                                                          \
   }                                                             \
   while (0)

/** \brief hook for variant-specific handling in Dem_UpdateHealingCounter() */
#define DEM_SPECIFIC_HOOK_UPDATEHC(EventId, EvMemEntry)          \
   do                                                            \
   {                                                             \
      /* one event memory entry has changed */                   \
      Dem_CheckForImmediateEntryStorage(                         \
                        EventId, EvMemEntry, FALSE, FALSE);      \
   }                                                             \
   while (0)

/** \brief hook for variant-specific handling in Dem_SetOperationCycleState()
 **
 ** expands to block with specific functionality:
 ** BMWDem051: [...] - Call the configured monitor function Xxx_DemInitMonitor
 **                    with parameter ::DEM_INIT_MONITOR_END
 **/
#define DEM_SPECIFIC_HOOK_ENDOPCYCLE(EventId)                    \
   do                                                            \
   {                                                             \
      /* end of monitor function */                              \
      Dem_RteInitMonitorForEvent(EventId, DEM_INIT_MONITOR_END); \
   }                                                             \
   while (0)

/** \brief hook for variant-specific handling in Dem_ClearDTC()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookClearDTC()
 **/
#define DEM_SPECIFIC_HOOK_CLEARDTC(DTC, DTCOrigin)               \
   do { Dem_SpecificHookClearDTC(DTC, DTCOrigin); } while (0)

/** \brief hook for variant-specific handling in Dem_ProcessEventEntry() */
#define DEM_SPECIFIC_HOOK_POSTENTRYSTORAGE(OrgEvtId, EvMemEntry) \
   do                                                            \
   {                                                             \
      /* one event memory entry has changed */                   \
      Dem_CheckForImmediateEntryStorage(                         \
                        OrgEvtId, EvMemEntry, FALSE, FALSE);     \
   }                                                             \
   while (0)

/** \brief hook for variant-specific handling in Dem_DisableEventStatusUpdate()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookDisableEvStUpdateAll()
 **/
#define DEM_SPECIFIC_HOOK_DISABLEEVSTUPDATEALL(result)           \
   do { (result) = Dem_SpecificHookDisableEvStUpdateAll(); } while (0)

/** \brief hook for variant-specific handling in Dem_DisableEventStatusUpdate()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookDisableEvStUpdateIdx()
 **/
#define DEM_SPECIFIC_HOOK_DISABLEEVSTUPDATEIDX(result, GroupIdx) \
   do                                                            \
   {                                                             \
      (result) = Dem_SpecificHookDisableEvStUpdateIdx(GroupIdx); \
   }                                                             \
   while (0)

/** \brief hook for variant-specific handling in Dem_EnableEventStatusUpdate()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookEnableEvStUpdateAll()
 **
 ** \note parameter "result" remains unchanged by this macro
 **/
#define DEM_SPECIFIC_HOOK_ENABLEEVSTUPDATEALL(result)           \
   do { Dem_SpecificHookEnableEvStUpdateAll(); } while (0)

/** \brief hook for variant-specific handling in Dem_EnableEventStatusUpdate()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookEnableEvStUpdateIdx()
 **
 ** \note parameter "result" remains unchanged by this macro
 **/
#define DEM_SPECIFIC_HOOK_ENABLEEVSTUPDATEIDX(result, GroupIdx) \
   do                                                           \
   {                                                            \
      Dem_SpecificHookEnableEvStUpdateIdx(GroupIdx);            \
   }                                                            \
   while (0)

/** \brief hook for variant-specific handling in Dem_DisableDTCStorage()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookDisableDTCStorageAll()
 **/
#define DEM_SPECIFIC_HOOK_DISABLEDTCSTORAGEALL(result)           \
   do { (result) = Dem_SpecificHookDisableDTCStorageAll(); } while (0)

/** \brief hook for variant-specific handling in Dem_DisableDTCStorage()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookDisableDTCStorageIdx()
 **/
#define DEM_SPECIFIC_HOOK_DISABLEDTCSTORAGEIDX(result, GroupIdx) \
   do                                                            \
   {                                                             \
      (result) = Dem_SpecificHookDisableDTCStorageIdx(GroupIdx); \
   }                                                             \
   while (0)

/** \brief hook for variant-specific handling in Dem_EnableDTCStorage()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookEnableDTCStorageAll()
 **
 ** \note parameter "result" remains unchanged by this macro
 **/
#define DEM_SPECIFIC_HOOK_ENABLEDTCSTORAGEALL(result)           \
   do { Dem_SpecificHookEnableDTCStorageAll(); } while (0)

/** \brief hook for variant-specific handling in Dem_EnableDTCStorage()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookEnableDTCStorageIdx()
 **
 ** \note parameter "result" remains unchanged by this macro
 **/
#define DEM_SPECIFIC_HOOK_ENABLEDTCSTORAGEIDX(result, GroupIdx) \
   do                                                           \
   {                                                            \
      Dem_SpecificHookEnableDTCStorageIdx(GroupIdx);            \
   }                                                            \
   while (0)

/** \brief hook for variant-specific check if event update is enabled
 **/
/* Deviation MISRA-1 */
#define DEM_SPECIFIC_HOOK_ISEVSTUPDATEENABLED(GroupIdx)         \
   (Dem_EvStUpdateAllowed[GroupIdx] == 0U)

/** \brief hook for variant-specific check if DTC storage is enabled
 **/
/* Deviation MISRA-1 */
#define DEM_SPECIFIC_HOOK_ISDTCSTORAGEENABLED(GroupIdx)         \
   (Dem_DTCStorageAllowed[GroupIdx] == 0U)


/*------------------[getter/setter macros for event memory overflow flags]--*/

/* Deviation MISRA-1 */
#define DEM_IS_EV_MEM_OVERFLOW(originIdx)                       \
   (DEM_IS_BIT_SET(*Dem_EvMemOverflowFlags, (uint8) (1U << (originIdx)) ))

/* Deviation MISRA-1 */
#define DEM_SET_EV_MEM_OVERFLOW(originIdx)                      \
   (DEM_SET_MASK(*Dem_EvMemOverflowFlags, (uint8) (1U << (originIdx)) ))

/* Deviation MISRA-1 */
#define DEM_CLEAR_EV_MEM_OVERFLOW(originIdx)                    \
   (DEM_CLR_MASK(*Dem_EvMemOverflowFlags, (uint8) (1U << (originIdx)) ))


/*------------------[macros for ED record with fixed numbers]---------------*/

/* these numbers are checked by generator checks in XDM file */

#if (defined DEM_FIXED_EDSNUM_CONDITION_BYTE)
#error DEM_FIXED_EDSNUM_CONDITION_BYTE already defined
#endif
#define DEM_FIXED_EDSNUM_CONDITION_BYTE 1U

#if (defined DEM_FIXED_EDSNUM_OCCURRENCE_CNT)
#error DEM_FIXED_EDSNUM_OCCURRENCE_CNT already defined
#endif
#define DEM_FIXED_EDSNUM_OCCURRENCE_CNT 2U


/*------------------[macros for fixed FF data identifiers]------------------*/

/* these values are checked by generator checks in XDM file */

#if (defined DEM_FIXED_FFSDID_ABSOLUTE_TIME)
#error DEM_FIXED_FFSDID_ABSOLUTE_TIME already defined
#endif
#define DEM_FIXED_FFSDID_ABSOLUTE_TIME 0x1701U


/*------------------[API function service IDs]------------------------------*/

#if (defined DEM_SID_CancelShutdown)
#error DEM_SID_CancelShutdown already defined
#endif
/** \brief Service Id for Dem_CancelShutdown() */
#define DEM_SID_CancelShutdown                                  100U


#if (defined DEM_SID_SetDMDebugFilter)
#error DEM_SID_SetDMDebugFilter already defined
#endif
/** \brief Service Id for Dem_SetDMDebugFilter() */
#define DEM_SID_SetDMDebugFilter                                101U

#if (defined DEM_SID_GetNextFilteredDMDebugDTC)
#error DEM_SID_GetNextFilteredDMDebugDTC already defined
#endif
/** \brief Service Id for Dem_GetNextFilteredDMDebugDTC() */
#define DEM_SID_GetNextFilteredDMDebugDTC                       102U


/*==================[type definitions]======================================*/

/** \brief Status of the DTC Filter */
typedef struct
{
   Dem_DebugFilterType Filter;                       /**< debug filter type */
   Dem_EvIdMaxType     NextEventId;          /**< Index of DTC to read next */
} Dem_DMDebugFilterType;


/*==================[external function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[static internal interface-function prototypes]---------*/

/** \brief Wrapper-Function to wait for NvM readiness
 **
 ** \param[in] BlockId  Id of NvM block
 **/
extern FUNC(void, DEM_CODE) Dem_StorageWaitNvMReady(uint16 BlockId);


/*------------------[static internal function prototypes]-------------------*/

/** \brief BMW-specific function for special handling in Dem_Init()
 **/
extern FUNC(void, DEM_CODE) Dem_SpecificHookInitNvData(void);

/** \brief BMW-specific function for special handling in Dem_ClearDTC()
 **/
extern FUNC(void, DEM_CODE) Dem_SpecificHookClearDTC(
   Dem_DTCType        DTC,
   Dem_DTCOriginType  DTCOrigin);

/** \brief BMW-specific function for special handling in
 ** Dem_DisableEventStatusUpdate()
 **/
extern FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)
   Dem_SpecificHookDisableEvStUpdateAll(void);

/** \brief BMW-specific function for special handling in
 ** Dem_DisableEventStatusUpdate()
 **/
extern FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)
   Dem_SpecificHookDisableEvStUpdateIdx(const uint8 GroupIdx);

/** \brief BMW-specific function for special handling in
 ** Dem_EnableEventStatusUpdate()
 **/
extern FUNC(void, DEM_CODE) Dem_SpecificHookEnableEvStUpdateAll(void);

/** \brief BMW-specific function for special handling in
 ** Dem_EnableEventStatusUpdate()
 **/
extern FUNC(void, DEM_CODE) Dem_SpecificHookEnableEvStUpdateIdx(
   const uint8 GroupIdx);

/** \brief BMW-specific function for special handling in
 ** Dem_DisableDTCStorage()
 **/
extern FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE)
   Dem_SpecificHookDisableDTCStorageAll(void);

/** \brief BMW-specific function for special handling in
 ** Dem_DisableDTCStorage()
 **/
extern FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE)
   Dem_SpecificHookDisableDTCStorageIdx(const uint8 GroupIdx);

/** \brief BMW-specific function for special handling in
 ** Dem_EnableDTCStorage()
 **/
extern FUNC(void, DEM_CODE) Dem_SpecificHookEnableDTCStorageAll(void);

/** \brief BMW-specific function for special handling in
 ** Dem_EnableDTCStorage()
 **/
extern FUNC(void, DEM_CODE) Dem_SpecificHookEnableDTCStorageIdx(
   const uint8 GroupIdx);

/** \brief Function to get the stored time out of a freeze frame data buffer
 **
 ** \param[in] FFData  pointer to buffer containing freeze frame data
 **
 ** \return time value stored in freeze frame data
 **/
extern FUNC(uint32, DEM_CODE) Dem_GetTimeFromFFData(
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FFData);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/** \brief pointer to global Condition Byte information */
extern CONSTP2VAR(uint8, DEM_CONST, DEM_VAR_NOINIT) Dem_EvMemOverflowFlags;

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

#define DEM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/** \brief Status of DM Debug-filter
 **
 ** This variable reflects the status of the DM Debug-filter.
 **/
extern VAR(Dem_DMDebugFilterType, DEM_VAR) Dem_DMDebugFilter;

#define DEM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/** \brief Boolean flag, indicating that Dem_Shutdown() runs */
extern VAR(boolean, DEM_VAR_NOINIT) Dem_ShutdownActive;

/** \brief Boolean flag, indicating shutdown-cancellation */
extern VAR(boolean, DEM_VAR_NOINIT) Dem_ShutdownCancellation;

/** \brief Boolean flag, indicating that "immediate storage" is in progress
 **
 ** While this flag is set, the return of Dem_ClearDTC() is prevented. */
extern volatile VAR(boolean, DEM_VAR_NOINIT)
   Dem_LockWhileImmediateStorage[DEM_MAXNUM_ORIGINS];

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_INTERNAL_STATIC_SPECIFIC_H */
/*==================[end of file]===========================================*/
