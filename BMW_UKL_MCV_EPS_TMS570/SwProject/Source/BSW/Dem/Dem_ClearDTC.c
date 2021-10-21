/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_ClearDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_ClearDTC.c 2558 2011-09-09 10:30:11Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise
 **
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

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

FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC(
   Dem_DTCType         DTC,
   Dem_DTCKindType     DTCKind,
   Dem_DTCOriginType   DTCOrigin)
{
   Dem_ReturnClearDTCType result;
   uint8 Idx = 0;
   boolean DTCGroupResult = TRUE;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_ClearDTC, DEM_E_UNINIT);
      return DEM_CLEAR_FAILED;
   }
   if (DTC > (Dem_DTCType) 0xFFFFFFUL)
   {
      DEM_REPORT_ERROR(DEM_SID_ClearDTC, DEM_E_PARAM_DATA);
      return DEM_CLEAR_WRONG_DTC;
   }
   if (    (DTCKind != DEM_DTC_KIND_ALL_DTCS)
        && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_ClearDTC, DEM_E_PARAM_DATA);
      return DEM_CLEAR_WRONG_DTCKIND;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY )
      )
   {
      DEM_REPORT_ERROR(DEM_SID_ClearDTC, DEM_E_PARAM_DATA);
      return DEM_CLEAR_WRONG_DTCORIGIN;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   if ((Dem_DTCGroupType) DTC != DEM_DTC_GROUP_ALL_DTCS)
   {
      DTCGroupResult = Dem_GetIdxOfDTCGroup((Dem_DTCGroupType) DTC, &Idx);
   }

   /* DTC origin is not supported */
   if (Dem_SizeEventMem[DTCOrigin - 1U] == (Dem_SizeEvMemEntryType) 0U)
   {
      result = DEM_CLEAR_WRONG_DTCORIGIN;
   }
   /* check if DTC matches a group Id */
   else if (DTCGroupResult != FALSE)
   {
      /* Idx is not evaluated if 'DTCGroup == DEM_DTC_GROUP_ALL_DTCS', and
       * is not allowed to be used in this case */

      Dem_EvIdLeastType EvId;
      uint8 GroupIdx;
      Dem_DTCOriginType ConfigOrigin;

      /* for all event Ids */
      for (EvId = 1U; EvId <= (DEM_NUMBER_OF_EVENTS - 1U); ++EvId)
      {
         GroupIdx     = Dem_GbiDTCGroupIdx((Dem_EventIdType)EvId);
         ConfigOrigin = Dem_GbiDTCOrigin((Dem_EventIdType)EvId);

         /* only for events of the requested DTC group and according origin */
         if (    (    ((Dem_DTCGroupType) DTC == DEM_DTC_GROUP_ALL_DTCS)
                   || (Idx == GroupIdx)
                 )
              && (DTCOrigin == ConfigOrigin)
            )
         {
            Dem_ResetDTC((Dem_EventIdType)EvId);
         }
      }

      /* hook-function for further variant specific handling */
      DEM_SPECIFIC_HOOK_CLEARDTC(DTC, DTCOrigin);

      result = DEM_CLEAR_OK;
   }
   else /* no group Id: try to clear single DTC */
   {
      Dem_EventIdType EvId;

      /* search event Id by DTC and map return value */
      switch (Dem_GetEvIdByDTC(DTC, DTCKind, DTCOrigin, &EvId))
      {
         case DEM_EIBD_OK:
            /* clear single DTC */
            Dem_ResetDTC(EvId);

            /* hook-function for further variant specific handling */
            DEM_SPECIFIC_HOOK_CLEARDTC(DTC, DTCOrigin);

            result = DEM_CLEAR_OK;
            break;
         case DEM_EIBD_WRONG_DTC:
            result = DEM_CLEAR_WRONG_DTC;
            break;
         case DEM_EIBD_WRONG_DTCKIND:
            result = DEM_CLEAR_WRONG_DTCKIND;
            break;
         case DEM_EIBD_WRONG_DTCORIGIN:
            /* doesn't appear, already checked at beginning */
            result = DEM_CLEAR_WRONG_DTCORIGIN;
            break;
         default: /* should never be reached */
            result = DEM_CLEAR_WRONG_DTC;
            break;
      }
   }

   if (result == DEM_CLEAR_OK)
   {
      /* lock event memory to ensure consistency for NV status block,
       * discard return value due to DET check in called function */
      (void) Dem_DisableEventStatusUpdate(DEM_DTC_GROUP_ALL_DTCS,
                                          DEM_DTC_KIND_ALL_DTCS);

      /* save also DEM status block into NVRAM (see CR70355),
       * discard return value, expected is a sufficient NVM queue size,
       * block is not write protected */
      (void) NvM_WriteBlock(NVM_BLOCK_DEM_STATUS, NULL_PTR);

      Dem_StorageWaitNvMReady(NVM_BLOCK_DEM_STATUS);

      /* unlock event memory,
       * discard return value due to DET check in called function */
      (void) Dem_EnableEventStatusUpdate(DEM_DTC_GROUP_ALL_DTCS,
                                         DEM_DTC_KIND_ALL_DTCS);
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
