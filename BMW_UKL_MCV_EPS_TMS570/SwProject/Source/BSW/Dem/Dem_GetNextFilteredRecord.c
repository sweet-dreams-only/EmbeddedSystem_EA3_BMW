/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetNextFilteredRecord().
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetNextFilteredRecord.c 2556 2011-09-08 11:34:37Z olho2924 $
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

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredRecord(
   P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA) DTC,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)       SnapshotRecord)
{
   /* quoting SWS: "This filter always belongs to primary memory." */
   const Dem_SizeEvMemEntryType sizeEventMem = Dem_SizeEventMem[0];

   CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) Entry =
      Dem_EventMem[0];

   uint16 NumStoredFFs = 0U;
   Dem_SizeEvMemEntryType index;
   Dem_EventIdType EvId;

   Dem_ReturnGetNextFilteredDTCType result = DEM_FILTERED_NO_MATCHING_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetNextFilteredRecord, DEM_E_UNINIT);
      return DEM_FILTERED_NO_MATCHING_DTC;
   }
   if (DTC == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetNextFilteredRecord, DEM_E_PARAM_ADDRESS);
      return DEM_FILTERED_NO_MATCHING_DTC;
   }
   if (SnapshotRecord == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetNextFilteredRecord, DEM_E_PARAM_ADDRESS);
      return DEM_FILTERED_NO_MATCHING_DTC;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /*
    * signal access of event memory
    */
   Dem_DcmAccessInProgress = TRUE;

   /* search for event memory entry, which contains the next record */
   for (index = 0U; index < sizeEventMem; ++index)
   {
      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      EvId = Entry[index].EventId;

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      if (EvId != (Dem_EventIdType)DEM_EVENT_ID_INVALID)
      {
         NumStoredFFs += (uint16) Entry[index].NumFF;

         if (NumStoredFFs > Dem_RecordFilterIdx)
         {
            /* event memory entry with demanded freeze frame record reached */

            *DTC = Dem_GbiDTC(EvId);
            /* in this version the snapshot record number is calculated
             * dynamically (and not stored for each record separately) */
            *SnapshotRecord = Dem_RecordFilterIdx;

            result = DEM_FILTERED_OK;

            if (Dem_RecordFilterIdx != 0xFFU)
            {
               Dem_RecordFilterIdx++;
            }

            break;
         }
      }
   }

   /*
    * signal access of event memory finished
    */
   Dem_DcmAccessInProgress = FALSE;

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
