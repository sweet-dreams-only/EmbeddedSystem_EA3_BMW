/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem functions
 ** Dem_DisableEventStatusUpdate() and Dem_EnableEventStatusUpdate().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_ControlEventStatusUpdate.c 2160 2010-03-31 10:54:54Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Dem_Helper.h>                                /* Dem helper macros */
#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Static.h>                    /* API and internal declarations */

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

FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE) Dem_DisableEventStatusUpdate(
   Dem_DTCGroupType DTCGroup,
   Dem_DTCKindType  DTCKind)
   /* DTCKind parameter is ignored:
      The current implementation only supports non OBD-relevant ECUs.
      Implementation is scheduled for future releases. */
{
   Dem_ReturnControlEventUpdateType result = DEM_CONTROL_EVENT_UPDATE_OK;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_DisableEventStatusUpdate, DEM_E_UNINIT);
      return DEM_CONTROL_EVENT_UPDATE_N_OK;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_DisableEventStatusUpdate, DEM_E_PARAM_DATA);
      return DEM_CONTROL_EVENT_UPDATE_N_OK;
   }
#else /* DEM_DEV_ERROR_DETECT */
   DEM_PARAM_UNUSED(DTCKind);
#endif /* DEM_DEV_ERROR_DETECT */

   if (DTCGroup == DEM_DTC_GROUP_ALL_DTCS)
   {
      DEM_SPECIFIC_HOOK_DISABLEEVSTUPDATEALL(result);
   }
   else
   {
      uint8 GroupIdx;

      if (Dem_GetIdxOfDTCGroup(DTCGroup, &GroupIdx) == TRUE)
      {
         DEM_SPECIFIC_HOOK_DISABLEEVSTUPDATEIDX(result, GroupIdx);
      }
      else /* invalid or not configured group */
      {
         result = DEM_CONTROL_EVENT_WRONG_DTCGROUP;
      }
   }

   return result;
}

FUNC(Dem_ReturnControlEventUpdateType, DEM_CODE) Dem_EnableEventStatusUpdate(
   Dem_DTCGroupType DTCGroup,
   Dem_DTCKindType  DTCKind)
   /* DTCKind parameter is ignored:
      The current implementation only supports non OBD-relevant ECUs.
      Implementation is scheduled for future releases. */
{
   Dem_ReturnControlEventUpdateType result = DEM_CONTROL_EVENT_UPDATE_OK;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_EnableEventStatusUpdate, DEM_E_UNINIT);
      return DEM_CONTROL_EVENT_UPDATE_N_OK;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_EnableEventStatusUpdate, DEM_E_PARAM_DATA);
      return DEM_CONTROL_EVENT_UPDATE_N_OK;
   }
#else /* DEM_DEV_ERROR_DETECT */
   DEM_PARAM_UNUSED(DTCKind);
#endif /* DEM_DEV_ERROR_DETECT */

   if (DTCGroup == DEM_DTC_GROUP_ALL_DTCS)
   {
      DEM_SPECIFIC_HOOK_ENABLEEVSTUPDATEALL(result);
   }
   else
   {
      uint8 GroupIdx;

      if (Dem_GetIdxOfDTCGroup(DTCGroup, &GroupIdx) == TRUE)
      {
         DEM_SPECIFIC_HOOK_ENABLEEVSTUPDATEIDX(result, GroupIdx);
      }
      else /* invalid or not configured group */
      {
         result = DEM_CONTROL_EVENT_WRONG_DTCGROUP;
      }
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
