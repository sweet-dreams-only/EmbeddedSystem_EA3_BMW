/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_SetDTCFilterForRecords().
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SetDTCFilterForRecords.c 2556 2011-09-08 11:34:37Z olho2924 $
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

#include <Dem_Static.h>                    /* API and internal declarations */

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

FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE) Dem_SetDTCFilterForRecords(
   P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords)
{
   /* quoting SWS: "This filter always belongs to primary memory." */
   const Dem_SizeEvMemEntryType sizeEventMem = Dem_SizeEventMem[0];

   CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) Entry =
      Dem_EventMem[0];

   Dem_SizeEvMemEntryType index;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* check of Dem_InitializationState is necessary, as filter is reseted in
    * Dem_Init() (and Dem_GetNextFilteredRecord() is then not usable anyway)
    * and also the event memory is accessed */
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_SetDTCFilterForRecords, DEM_E_UNINIT);
      return DEM_WRONG_FILTER;
   }
   if (NumberOfFilteredRecords == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_SetDTCFilterForRecords, DEM_E_PARAM_ADDRESS);
      return DEM_WRONG_FILTER;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   *NumberOfFilteredRecords = 0U;

   /*
    * signal access of event memory
    */
   Dem_DcmAccessInProgress = TRUE;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   /* count number of currently stored freeze frames */
   for (index = 0U; index < sizeEventMem; ++index)
   {
      if (Entry[index].EventId != (Dem_EventIdType)DEM_EVENT_ID_INVALID)
      {
         *NumberOfFilteredRecords += (uint16) Entry[index].NumFF;
      }
   }

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   /*
    * signal access of event memory finished
    */
   Dem_DcmAccessInProgress = FALSE;

   /* reset freeze frame record-filter */
   Dem_RecordFilterIdx = 0U;

   return DEM_FILTER_ACCEPTED;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
