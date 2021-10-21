/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of vendor-specific Dem functions
 ** for controlling the DTC storage.
 **
 ** \project AUTOSAR Standard Core
 ** \author Stephanie Muehlenmeister
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SpecificHookControlDTCStorage.c 1438 2008-05-26 12:37:46Z
 ** masc2461 $ Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by BMW Group
 ** All rights exclusively reserved for BMW Group,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

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

FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE)
   Dem_SpecificHookDisableDTCStorageAll(void)
{
   Dem_ReturnControlDTCStorageType result = DEM_CONTROL_DTC_STORAGE_OK;
   Dem_DTCGroupType GroupIdx;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   for (GroupIdx = 0U; GroupIdx < DEM_NUM_DTC_GROUPS; GroupIdx++)
   {
      if (Dem_DTCStorageAllowed[GroupIdx] < 0xFFU)
      {
         Dem_DTCStorageAllowed[GroupIdx]++;
      }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
      else
      {
         result = DEM_CONTROL_DTC_STORAGE_N_OK;

         /* break loop and return error code */
         break;
      }
#endif /* DEM_DEV_ERROR_DETECT */
   }

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (result != DEM_CONTROL_DTC_STORAGE_OK)
   {
      DEM_REPORT_ERROR(DEM_SID_DisableDTCStorage, DEM_E_PARAM_DATA);
   }
#endif /* DEM_DEV_ERROR_DETECT */

   return result;
}

FUNC(Dem_ReturnControlDTCStorageType, DEM_CODE)
   Dem_SpecificHookDisableDTCStorageIdx(const uint8 GroupIdx)
{
   Dem_ReturnControlDTCStorageType result = DEM_CONTROL_DTC_STORAGE_OK;
   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   if (Dem_DTCStorageAllowed[GroupIdx] < 0xFFU)
   {
      Dem_DTCStorageAllowed[GroupIdx]++;
   }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   else
   {
      result = DEM_CONTROL_DTC_STORAGE_N_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (result != DEM_CONTROL_DTC_STORAGE_OK)
   {
      DEM_REPORT_ERROR(DEM_SID_DisableDTCStorage, DEM_E_PARAM_DATA);
   }
#endif /* DEM_DEV_ERROR_DETECT */

   return result;
}

FUNC(void, DEM_CODE) Dem_SpecificHookEnableDTCStorageAll(void)
{
   Dem_DTCGroupType GroupIdx;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   for (GroupIdx = 0U; GroupIdx < DEM_NUM_DTC_GROUPS; GroupIdx++)
   {
      if (Dem_DTCStorageAllowed[GroupIdx] > 0U)
      {
        Dem_DTCStorageAllowed[GroupIdx]--;
      }
      /* else: no development error */
   }

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
}

FUNC(void, DEM_CODE) Dem_SpecificHookEnableDTCStorageIdx(
   const uint8 GroupIdx)
{
   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   if (Dem_DTCStorageAllowed[GroupIdx] > 0U)
   {
      Dem_DTCStorageAllowed[GroupIdx]--;
   }
   /* else: no development error */

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
}


#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
