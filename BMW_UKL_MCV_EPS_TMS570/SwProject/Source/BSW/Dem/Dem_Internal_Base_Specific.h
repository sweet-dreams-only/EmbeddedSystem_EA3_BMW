#ifndef DEM_INTERNAL_BASE_SPECIFIC_H
/** \brief preprocessor exclusion definition */
#define DEM_INTERNAL_BASE_SPECIFIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all configuration independent internal basic
 ** definitions of the AUTOSAR module Dem, which are variant specific.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Internal_Base_Specific.h 2480 2011-03-21 16:00:06Z olho2924 $
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

#include <Dem_Api_Static_Specific.h>                   /* Module public API */


/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/** \brief Number of freeze frames type
 **
 ** Note: The size of this type is defined by ISO14229-1.
 ** (FF RecordNumber = 0x01 ... 0xFE)
 **
 ** NumFF and MaxNumFF variables are also of this type. */
typedef uint8 Dem_FFIdxType;

/** \brief Entry data size type */
typedef uint16 Dem_SizeEntryDataType;

/** \brief Type concerning immediate storage */
typedef enum
{
   DEM_ENTRY_NOT_CHANGED,
          /**< entry was not changed and need not to be stored persistently */
   DEM_ENTRY_CHANGED,
       /**< entry was changed and has to be stored persistently at shutdown */
   DEM_ENTRY_STORE_IMMEDIATELY
         /**< entry was changed and has to be stored persistent immediately */
} Dem_EntryStatusType;

/** \brief Event memory entry type, static part of the error memory */
typedef struct
{
   Dem_EventIdType       EventId;                /**< Event Id of the entry */
   Dem_FFIdxType         NumFF;           /**< Number of used freeze frames */
   Dem_SizeEntryDataType EntryDataPos;
                               /**< Start of extended and freeze frame data */
   Dem_OccurrenceCtrType OccurrenceCounter;         /**< Occurrence counter */
   Dem_EntryStatusType   EntryStatus;
                        /**< Status indication concerning immediate storage */
} Dem_EventMemoryEntryType;

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_INTERNAL_BASE_SPECIFIC_H */
/*==================[end of file]===========================================*/
