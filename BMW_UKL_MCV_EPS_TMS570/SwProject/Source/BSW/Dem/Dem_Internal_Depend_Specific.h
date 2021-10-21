#ifndef DEM_INTERNAL_DEPEND_SPECIFIC_H
/** \brief preprocessor exclusion definition */
#define DEM_INTERNAL_DEPEND_SPECIFIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all configuration dependent internal API declarations
 ** of the AUTOSAR module Dem, which are variant specific.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Internal_Depend_Specific.h 2480 2011-03-21 16:00:06Z olho2924 $
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

#include <Dem_Internal_Depend.h>                       /* Base class header */

/*==================[macros]================================================*/

/* Independent values: offset, mask (only depends on static value widths) */

/* first 8 bits of variant-specific event description layout */

#if (defined DEM_IMMSTORAGE_OFFSET)
#error DEM_IMMSTORAGE_OFFSET already defined
#endif
#define DEM_IMMSTORAGE_OFFSET        0U

#if (defined DEM_IMMSTORAGE_MASK)
#error DEM_IMMSTORAGE_MASK already defined
#endif
#define DEM_IMMSTORAGE_MASK          ((1UL << DEM_IMMSTORAGE_WIDTH) - 1UL)


#if (defined DEM_ROEACTIVE_OFFSET)
#error DEM_ROEACTIVE_OFFSET already defined
#endif
#define DEM_ROEACTIVE_OFFSET         (DEM_IMMSTORAGE_OFFSET + DEM_IMMSTORAGE_WIDTH)

#if (defined DEM_ROEACTIVE_MASK)
#error DEM_ROEACTIVE_MASK already defined
#endif
#define DEM_ROEACTIVE_MASK           ((1UL << DEM_ROEACTIVE_WIDTH) - 1UL)

/* check if size of specific event description layout is maximal 8 bits */
#if ( (DEM_ROEACTIVE_OFFSET + DEM_ROEACTIVE_WIDTH) > 8U )
#error Variant-specific Event-Configuration-Layout needs to much space.
#endif

/*------------------[definitions for callback function]----------------------*/

#if (defined DEM_RTE_CBK_CLEAR_EV_ALLOWED)
#error DEM_RTE_CBK_CLEAR_EV_ALLOWED already defined
#endif
#define DEM_RTE_CBK_CLEAR_EV_ALLOWED       0x02U

#if (defined DEM_C_CBK_CLEAR_EV_ALLOWED)
#error DEM_C_CBK_CLEAR_EV_ALLOWED already defined
#endif
#define DEM_C_CBK_CLEAR_EV_ALLOWED         0x03U

#if (defined DEM_RTE_CBK_TRIGGER_ON_EV_ERROR)
#error DEM_RTE_CBK_TRIGGER_ON_EV_ERROR already defined
#endif
#define DEM_RTE_CBK_TRIGGER_ON_EV_ERROR    0x04U

#if (defined DEM_C_CBK_TRIGGER_ON_EV_ERROR)
#error DEM_C_CBK_TRIGGER_ON_EV_ERROR already defined
#endif
#define DEM_C_CBK_TRIGGER_ON_EV_ERROR      0x05U

/*------------------[variant-specific hook macro]---------------------------*/

/** \brief hook for variant-specific handling in Dem_Init()*/
#define DEM_SPECIFIC_HOOK_INITNVDATA()  \
   do { Dem_SpecificHookInitNvData(); } while (0)

/** \brief hook for variant-specific handling in Dem_Init()
 **
 ** disable network event updates (BMWDem055)
 **/
#define DEM_SPECIFIC_HOOK_POSTINIT()                                 \
   do                                                                \
   {                                                                 \
      uint8 Index;                                                   \
                                                                     \
      /* enable 'event status update' for all groups */              \
      for (Index = 0U; Index < DEM_NUM_DTC_GROUPS; Index++)          \
      {                                                              \
         Dem_EvStUpdateAllowed[Index] = 0U;                          \
      }                                                              \
                                                                     \
      /* do not disable 'event status update' for Network Com DTCs   \
       * since nesting of disabling / enabling event status          \
       * update is enabled (CR 61067) */                             \
                                                                     \
      /* enable 'DTC storage' for all groups */                      \
      for (Index = 0U; Index < DEM_NUM_DTC_GROUPS; Index++)          \
      {                                                              \
         Dem_DTCStorageAllowed[Index] = 0U;                          \
      }                                                              \
                                                                     \
      /* initialize shutdown-active flag */                          \
      Dem_ShutdownActive = FALSE;                                    \
                                                                     \
      /* initialize shutdown-cancellation flag */                    \
      /* only on shutdown: Dem_ShutdownCancellation = FALSE */       \
                                                                     \
      /* initialize lock-while-immediate-storage flag */             \
      for (Index = 0U; Index < DEM_MAXNUM_ORIGINS; Index++)          \
      {                                                              \
         Dem_LockWhileImmediateStorage[Index] = FALSE;               \
      }                                                              \
   }                                                                 \
   while (0)

/** \brief hook for variant-specific handling in Dem_ProcessEventEntry()
 **
 ** as handling isn't trivial, expands to function call to
 ** Dem_SpecificHookEventEntry()
 **/
#define DEM_SPECIFIC_HOOK_EVENTENTRY(FFData, EventId)  \
   do { Dem_SpecificHookEventEntry(FFData, EventId); } while (0)

/*------------------[DEM non volatile data]---------------------------------*/

/** \brief NvM block Id for DEM default block */
#define DEM_NVM_BLOCK_ID_DEFAULT   NVM_BLOCK_DEM_STATUS


/*==================[type definitions]======================================*/

/** \brief variant-specific static event/DTC description type
 **
 ** The 'bit packing scheme' is used. Access to the values is possible with
 ** the getter functions like Dem_GbiDTC().*/
typedef struct
{
   uint8 EvConf1;
   /**< 1. byte of the event description bit-package:
    *
    * - i:     ImmStorage
    * - r:     RoeActive
    * - a:     ClearEventAllowed (RTE-Callback)
    * - b:     ClearEventAllowed (C-Callback)
    * - c:     TriggerOnEventError (RTE-Callback)
    * - d:     TriggerOnEventError (C-Callback)
    *
    * - xxxx xxxx
    * - __dc bari  */
} Dem_EventDescSpecificType;

/*------------------[definitions for callback function]----------------------*/

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CbkFuncPtrClrEvAllowedType) (
   Dem_EventIdType                               EventId,
   CONSTP2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) Allowed);

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CbkFuncPtrTriggerOnErrorType) (
   Dem_DTCType DTC,
   uint32      Timestamp);

typedef struct
{
   Dem_EventIdType                EventId;
   Dem_CbkFuncPtrClrEvAllowedType Function;
} Dem_ClrEvCallbackType;

/*==================[external function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief BMW-specific function for special handling in Dem_ProcessEventEntry()
 **/
extern FUNC(void, DEM_CODE) Dem_SpecificHookEventEntry(
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FFData,
   const Dem_EventIdType                                      EventId);

/*------------------[Getter-Functions for the Event Descriptions]-----------*/

#if (DEM_USE_IMMSTORAGE == STD_ON)
#if (DEM_USE_IMMSTORAGE_GLOBAL == STD_OFF)
/** \brief Get immediate storage information from ::Dem_EventDesc by using index */
extern FUNC(boolean, DEM_CODE) Dem_GbiImmStorage(const Dem_EventIdType EventId);
#else /* (DEM_USE_IMMSTORAGE_GLOBAL == STD_OFF) */
/* if immediate storage is globaly on, the function Dem_GbiImmStorage will be
 * replaced by a function-like-macro */
#define Dem_GbiImmStorage(EventId)     TRUE
#endif /* (DEM_USE_IMMSTORAGE_GLOBAL == STD_OFF) */
#endif /*(DEM_USE_IMMSTORAGE == STD_ON) */

/** \brief Get immediate storage information from ::Dem_EventDesc by using index */
extern FUNC(boolean, DEM_CODE) Dem_GbiRoeActive(const Dem_EventIdType EventId);
/** \brief Get RTE-Port usage for ClearEventAllowed from ::Dem_EventDesc by
 ** using index */
extern FUNC(boolean, DEM_CODE) Dem_GbiClrEvAllowedRteUseage(
   const Dem_EventIdType EventId);
/** \brief Get C-Callback usage for ClearEventAllowed from ::Dem_EventDesc by
 ** using index */
extern FUNC(boolean, DEM_CODE) Dem_GbiClrEvAllowedCCallback(
   const Dem_EventIdType EventId);
/** \brief Get RTE-Port usage for TriggerOnError from ::Dem_EventDesc by
 ** using index */
extern FUNC(boolean, DEM_CODE) Dem_GbiTriggerOnErrorRteUseage(
   const Dem_EventIdType EventId);
/** \brief Get C-Callback usage for TriggerOnError from ::Dem_EventDesc by
 ** using index */
extern FUNC(boolean, DEM_CODE) Dem_GbiTriggerOnErrorCCallback(
   const Dem_EventIdType EventId);

/*------------------[immediate storage function prototypes]-----------------*/

#if (DEM_USE_IMMSTORAGE == STD_ON)

/** \brief Function to check if an changed entry has to (and can) be stored
 ** immediately
 **
 ** Checks if immediate storage is enabled, and initiates copying of the entry
 ** to NvM if possible or marks entry as changed.
 **
 ** \param[in] OriginalEventId  event Id of the (possibly cleared) entry
 ** \param[in] EventMemoryEntry  pointer to the selected entry
 ** \param[in] CheckForLocking  if the entry has to be stored immediately, the
 **                             LOCK will be activated
 **/
extern FUNC(void, DEM_CODE) Dem_CheckForImmediateEntryStorage(
   Dem_EventIdType                                     OriginalEventId,
   CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR)
                                                       EventMemoryEntry,
   boolean                                             CheckForLocking,
   boolean                                             ForceImmediate);

#else

/** if immediate storage is off the function Dem_CheckForImmediateEntryStorage
 ** will be replaced by a fucntion-like-macro to set the entry status.
 **/
#define Dem_CheckForImmediateEntryStorage(OriginalEventId,                 \
                                          EventMemoryEntry,                \
                                          CheckForLocking,                 \
                                          ForceImmediate)                  \
           ((EventMemoryEntry)->EntryStatus = DEM_ENTRY_CHANGED)

#endif

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/** \brief Configuration description table for events
 **
 ** Number of elements: ::DEM_NUMBER_OF_EVENTS
 **
 ** This array contains all specific event-related data, which are packed by
 ** using the 'bit packing scheme'.
 **
 ** \note For immediate storage it is mandatory, that the description for
 **       ::DEM_EVENT_ID_INVALID is set to ImmediateStorage = false.
 **/
extern CONST(Dem_EventDescSpecificType, DEM_CONST)
   Dem_EventDescSpecific[DEM_NUMBER_OF_EVENTS];


/*-----------------[C-Functiontable]----------------------------------------*/

#if (DEM_C_CALLBACK_TABLE_CLR_EV_ALLOWED_SIZE != 0U)
/** \brief C-Callback function pointer table for ClearEventAllowed */
extern CONST(Dem_CbkFuncPtrClrEvAllowedType, DEM_CONST)
   Dem_CbkFuncPtrClrEvAllowed[DEM_C_CALLBACK_TABLE_CLR_EV_ALLOWED_SIZE];
#endif

#if (DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE != 0U)
/** \brief C-Callback function pointer table for TriggerOnError */
extern CONST(Dem_CbkFuncPtrTriggerOnErrorType, DEM_CONST)
   Dem_CbkFuncPtrTriggerOnError[DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE];
#endif

/*-----------------[C-Lookuptable]------------------------------------------*/


#if (DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE != 0U)
#if (DEM_C_CALLBACK_TABLE_CLR_EV_ALLOWED_SIZE != 0U)
   /** \brief C-Callback function lookup table for ClearEventAllowed */
   extern CONST(Dem_CbkLookupTableType, DEM_CONST)
      Dem_CbkLookupTableClrEvAllowed[DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE];
#else
   /** \brief C-Callback function lookup table for ClearEventAllowed */
   extern CONST(Dem_ClrEvCallbackType, DEM_CONST)
      Dem_CbkLookupTableClrEvAllowed[DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE];
#endif /* DEM_C_CALLBACK_TABLE_CLR_EV_ALLOWED_SIZE */
#endif /* DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE) */

#if (DEM_C_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE != 0U)
/** \brief C-Callback function lookup table for TriggerOnError */
extern CONST(Dem_CbkLookupTableType, DEM_CONST)
   Dem_CbkLookupTableTriggerOnError[DEM_C_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE];
#endif

/*-----------------[RTE-Lookuptable]----------------------------------------*/

#if (DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE != 0U)
/** \brief RTE-Callback function lookup table for ClearEventAllowed */
extern CONST(Dem_EventIdType, DEM_CONST)
   Dem_RteLookupTableClrEvAllowed[DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE];
#endif

#if (DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE != 0U)
/** \brief RTE-Callback function lookup table for TriggerOnError */
extern CONST(Dem_EventIdType, DEM_CONST)
   Dem_RteLookupTableTriggerOnError[DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE];
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/** \brief Array elements encode whether event update is allowed for the
 ** specific DTC group: 0=enabled, (1 to n)=disabled
 **/
extern VAR(uint8, DEM_VAR_NOINIT) Dem_EvStUpdateAllowed[DEM_NUM_DTC_GROUPS];
/** \brief Array elements encode whether DTC storage is allowed for the
 ** specific DTC group: 0=enabled, (1 to n)=disabled
 **/
extern VAR(uint8, DEM_VAR_NOINIT) Dem_DTCStorageAllowed[DEM_NUM_DTC_GROUPS];

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_INTERNAL_DEPEND_SPECIFIC_H */
/*==================[end of file]===========================================*/
