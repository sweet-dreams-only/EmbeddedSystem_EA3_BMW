
#ifndef DEM_API_DEPEND_SPECIFIC_H
/** \brief preprocessor exclusion definition */
#define DEM_API_DEPEND_SPECIFIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all configuration dependent external API declarations
 ** of the AUTOSAR module Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Api_Depend_Specific.h.m4 2480 2011-03-21 16:00:06Z olho2924 $
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

#include <NvM.h>                              /* for usage of NvRam Manager */

#include <Dem_Api_Depend.h>                            /* Base class header */

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

/*------------------[macros for InitMonitorKindType]------------------------*/

#if (DEM_INCLUDE_RTE == STD_OFF)

#if (defined DEM_INIT_MONITOR_END) /* to prevent double declaration */
#error DEM_INIT_MONITOR_END already defined
#endif
/** \brief Value for InitMonitorKindType
 **
 ** Monitor Function of the EventId is requested to restart
 **/
#define DEM_INIT_MONITOR_END ((Dem_InitMonitorKindType) 0x03U)

#endif /* DEM_INCLUDE_RTE */

/*==================[type definitions]======================================*/

/*------------------[fragments to build up further gate entry types]--------*/

/** \brief Gate entry base fragment structure */
struct Dem_GateEntryBaseFragment
{
   Dem_EventIdType       EventId;                     /**< link to used DTC */
   Dem_OccurrenceCtrType OccurrenceCounter;         /**< Occurrence counter */
};

/** \brief Gate entry primary data fragment structure
 **
 ** \note no different gate entry structures supported in this version
 **/
struct Dem_GateEntryPrimaryFragment
{
   Dem_EntryDataType     EntryData[DEM_SIZE_GATE_ENTRY_DATA_PRIMARY];
   /**< Entry data for gate entry consiting of extended data without virtual
    * records (OCCURRENCE_COUNTER and CONDITION_BYTE) and freeze frame data */
};

/** \brief Gate entry secondary data fragment structure
 **
 ** \note no different gate entry structures supported in this version
 **/
struct Dem_GateEntrySecondaryFragment
{
   Dem_EntryDataType     EntryData[DEM_SIZE_GATE_ENTRY_DATA_SECONDARY];
   /**< Entry data for gate entry consiting of extended data without virtual
    * records (OCCURRENCE_COUNTER and CONDITION_BYTE) and freeze frame data */
};

/** \brief Gate entry mirror data fragment structure
 **
 ** \note no different gate entry structures supported in this version
 **/
struct Dem_GateEntryMirrorFragment
{
   Dem_EntryDataType     EntryData[DEM_SIZE_GATE_ENTRY_DATA_MIRROR];
   /**< Entry data for gate entry consiting of extended data without virtual
    * records (OCCURRENCE_COUNTER and CONDITION_BYTE) and freeze frame data */
};

/*------------------[gate entry type inheritance structure]-----------------*/

/** \brief Gate entry data void type - used for pointers to gate entry data */
typedef void Dem_GateEntryDataVoid;

/** \brief Gate entry data void pointer type */
typedef CONSTP2VAR(Dem_GateEntryDataVoid, DEM_CONST, DEM_VAR_NOINIT)
   Dem_GateEntryDataPtrVoid;

/** \brief Gate entry base type - used for basic access
 **
 ** \note no different gate entry types supported in this version
 **/
typedef struct
{
   struct Dem_GateEntryBaseFragment      EntryBase;  /**< Basic information */
} Dem_GateEntryBaseType;

/*------------------[types resulting into NVRAM blocks]---------------------*/

/** \brief Gate entry void type - used for pointers to gate entries */
typedef void Dem_NvGateEntryDataVoid;

/** \brief Gate entry void pointer type */
typedef CONSTP2VAR(Dem_NvGateEntryDataVoid, DEM_CONST, DEM_VAR_NOINIT)
   Dem_NvGateEntryDataPtrVoid;

/** \brief Structure containing all non volatile primary event memory data
 ** for one gate entry
 **
 ** \note configuration dependent type, derived from GateEntryBaseType
 **/
typedef struct
{
   struct Dem_GateEntryBaseFragment      EntryBase;  /**< Basic information */
   struct Dem_GateEntryPrimaryFragment   EntryPrimary;
                                              /**< Primary data information */
} Dem_NvGateEntryPrimaryDataType;

/** \brief Structure containing all non volatile secondary event memory data
 ** for one gate entry
 **
 ** \note configuration dependent type, derived from GateEntryBaseType
 **/
typedef struct
{
   struct Dem_GateEntryBaseFragment      EntryBase;  /**< Basic information */
   struct Dem_GateEntrySecondaryFragment EntrySecondary;
                                            /**< Secondary data information */
} Dem_NvGateEntrySecondaryDataType;

/** \brief Structure containing all non volatile mirror event memory data
 ** for one gate entry
 **
 ** \note configuration dependent type, derived from GateEntryBaseType
 **/
typedef struct
{
   struct Dem_GateEntryBaseFragment      EntryBase;  /**< Basic information */
   struct Dem_GateEntryMirrorFragment    EntryMirror;
                                               /**< Mirror data information */
} Dem_NvGateEntryMirrorDataType;


/** \brief Structure containing all non volatile status data
 **
 ** \note configuration dependent type
 **/
typedef struct
{
   Dem_DTCStatusMaskType    DTCStatusMask[DEM_NUMBER_OF_EVENTS];
                                                    /**< Status of each DTC */
   uint8                    ClearPDTC[(DEM_NUMBER_OF_EVENTS - 1U) / 8U + 1U];
   /**< Bit array to store the condition wheter the pending DTC flag may be
    * cleared at the end of the current/next operation cycle */

   uint8                    EvMemOverflowFlags;
                     /**< Overflow Flags / "Condition Byte" for each origin */
} Dem_NvStatusDataType;

/*==================[external function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief Callback-Function from NvM for primary NV gate-entry data block
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] ServiceId
 ** \param[in] JobResult
 **
 ** \return returns always E_OK (NVM368)
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_NvMGateEntryPrimaryBlockCallback(
   uint8                 ServiceId,
   NvM_RequestResultType JobResult);


#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U)
/** \brief Callback-Function from NvM for secondary NV gate-entry data block
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] ServiceId
 ** \param[in] JobResult
 **
 ** \return returns always E_OK (NVM368)
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_NvMGateEntrySecondaryBlockCallback(
   uint8                 ServiceId,
   NvM_RequestResultType JobResult);
#endif


#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U)
/** \brief Callback-Function from NvM for mirror NV gate-entry data block
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronous
 **
 ** \param[in] ServiceId
 ** \param[in] JobResult
 **
 ** \return returns always E_OK (NVM368)
 **/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_NvMGateEntryMirrorBlockCallback(
   uint8                 ServiceId,
   NvM_RequestResultType JobResult);
#endif

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/** \brief Non volatile status data of the DEM */
extern VAR(Dem_NvStatusDataType, DEM_VAR_NOINIT) Dem_NvStatusData;

/** \brief Non volatile primary data of the DEM */
extern VAR(Dem_NvGateEntryPrimaryDataType, DEM_VAR_NOINIT)
   Dem_NvGateEntryPrimaryData;

#if DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U
/** \brief Non volatile secondary data of the DEM */
extern VAR(Dem_NvGateEntrySecondaryDataType, DEM_VAR_NOINIT)
   Dem_NvGateEntrySecondaryData;
#endif

#if DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U
/** \brief Non volatile mirror data of the DEM */
extern VAR(Dem_NvGateEntryMirrorDataType, DEM_VAR_NOINIT)
   Dem_NvGateEntryMirrorData;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_API_DEPEND_SPECIFIC_H */
/*==================[end of file]===========================================*/
