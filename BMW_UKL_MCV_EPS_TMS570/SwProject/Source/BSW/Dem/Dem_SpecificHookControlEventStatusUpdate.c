/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of vendor-specific Dem functions
 ** for controlling the event status update.
 **
 ** \project AUTOSAR Standard Core
 ** \author Stephanie Muehlenmeister
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SpecificHookControlEventStatusUpdate.c 1438 2008-05-26 12:37:46Z
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

FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)
   Dem_SpecificHookDisableEvStUpdateAll(void)
{
   Dem_ReturnControlEventUpdateType result = DEM_CONTROL_EVENT_UPDATE_OK;
   uint8 GroupIdx;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   for (GroupIdx = 0U; GroupIdx < DEM_NUM_DTC_GROUPS; GroupIdx++)
   {
      if (Dem_EvStUpdateAllowed[GroupIdx] < 0xFFU)
      {
         Dem_EvStUpdateAllowed[GroupIdx]++;
      }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
      else
      {
         result = DEM_CONTROL_EVENT_UPDATE_N_OK;

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
   if (result != DEM_CONTROL_EVENT_UPDATE_OK)
   {
      DEM_REPORT_ERROR(DEM_SID_DisableEventStatusUpdate, DEM_E_PARAM_DATA);
   }
#endif /* DEM_DEV_ERROR_DETECT */

   return result;
}

FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE)
   Dem_SpecificHookDisableEvStUpdateIdx(const uint8 GroupIdx)
{
   Dem_ReturnControlEventUpdateType result = DEM_CONTROL_EVENT_UPDATE_OK;
   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   if (Dem_EvStUpdateAllowed[GroupIdx] < 0xFFU)
   {
      Dem_EvStUpdateAllowed[GroupIdx]++;
   }
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   else
   {
      result = DEM_CONTROL_EVENT_UPDATE_N_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (result != DEM_CONTROL_EVENT_UPDATE_OK)
   {
      DEM_REPORT_ERROR(DEM_SID_DisableEventStatusUpdate, DEM_E_PARAM_DATA);
   }
#endif /* DEM_DEV_ERROR_DETECT */

   return result;
}

FUNC(void, DEM_CODE) Dem_SpecificHookEnableEvStUpdateAll(void)
{
   uint8 GroupIdx;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   for (GroupIdx = 0U; GroupIdx < DEM_NUM_DTC_GROUPS; GroupIdx++)
   {
      if (Dem_EvStUpdateAllowed[GroupIdx] > 0U)
      {
        Dem_EvStUpdateAllowed[GroupIdx]--;
      }
      /* else: no development error */
   }

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
}

FUNC(void, DEM_CODE) Dem_SpecificHookEnableEvStUpdateIdx(
   const uint8 GroupIdx)
{
   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   if (Dem_EvStUpdateAllowed[GroupIdx] > 0U)
   {
      Dem_EvStUpdateAllowed[GroupIdx]--;
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
