/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetSizeOfFreezeFrame().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetSizeOfFreezeFrame.c 2556 2011-09-08 11:34:37Z olho2924 $
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

#include <Dem_Internal_Depend_Specific.h> /* API and internal declarations,
                                           * dependent and static part */

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

FUNC(Dem_ReturnGetSizeOfFreezeFrameType, DEM_CODE)
   Dem_GetSizeOfFreezeFrame(
      Dem_DTCType                              DTC,
      Dem_DTCKindType                          DTCKind,
      Dem_DTCOriginType                        DTCOrigin,
      uint8                                    RecordNumber,
      P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame)
{
   Dem_ReturnGetSizeOfFreezeFrameType result;
   Dem_EventIdType EvId;
   Dem_FFIdxType MaxNumFF;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetSizeOfFreezeFrame, DEM_E_UNINIT);
      return DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC;
   }
   if ((DTC == (Dem_DTCType)0UL) || (DTC > (Dem_DTCType)0xFFFFFFUL))
   {
      DEM_REPORT_ERROR(DEM_SID_GetSizeOfFreezeFrame, DEM_E_PARAM_DATA);
      return DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetSizeOfFreezeFrame, DEM_E_PARAM_DATA);
      return DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCKIND;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY ) )
   {
      DEM_REPORT_ERROR(DEM_SID_GetSizeOfFreezeFrame, DEM_E_PARAM_DATA);
      return DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCORIGIN;
   }
   if (SizeOfFreezeFrame == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetSizeOfFreezeFrame, DEM_E_PARAM_ADDRESS);
      return DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   *SizeOfFreezeFrame = 0U;

   /* search event Id by DTC and map return value */
   switch (Dem_GetEvIdByDTC(DTC, DTCKind, DTCOrigin, &EvId))
   {
      case DEM_EIBD_OK:
         result = DEM_GET_SIZEOFFREEZEFRAMETYPE_OK;
         break;
      case DEM_EIBD_WRONG_DTC:
         result = DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC;
         break;
      case DEM_EIBD_WRONG_DTCKIND:
         result = DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCKIND;
         break;
      case DEM_EIBD_WRONG_DTCORIGIN:
         result = DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTCORIGIN;
         break;
      default: /* should never be reached */
         result = DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_DTC;
         break;
   }

   if (result == DEM_GET_SIZEOFFREEZEFRAMETYPE_OK)
   {
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) EvMemEntry;
      boolean EntryExists;

      Dem_FFIdxType NumOfFF = 0U;

      /*
       * signal access of event memory
       */
      Dem_DcmAccessInProgress = TRUE;

      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* search for DTC in event memory */
      EntryExists = Dem_SearchForEntry(EvId, &EvMemEntry);

      if (EntryExists != FALSE)
      {
         NumOfFF = EvMemEntry->NumFF;
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /*
       * signal access of event memory finished
       */
      Dem_DcmAccessInProgress = FALSE;

      if (EntryExists != FALSE)
      {
         MaxNumFF = Dem_GbiMaxNumFF(EvId);

         if (   ((RecordNumber >= 1U) && (RecordNumber <= NumOfFF))
             || (RecordNumber == 0xFFU)
             )
         {
            /* get freeze frame class layout */
            CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass =
               Dem_FFClasses[Dem_GbiFFClassIdx(EvId)];

            /* one ore more FF requested and record num is valid and stored */
            /* calculate needed size */
            *SizeOfFreezeFrame = Dem_SizeOfFF(FFClass);

            if (RecordNumber == 0xFFU)
            {
               *SizeOfFreezeFrame *= (uint16)NumOfFF;
            }
         }
         else if ((RecordNumber >= 1U) && (RecordNumber <= MaxNumFF))
         {
            /* record number is valid but no FF is stored for this record,
             * return 0 lenght buffer */
            *SizeOfFreezeFrame = 0U;
         }
         else
         {
            /* FF record number is not possible for this DTC */
            result = DEM_GET_SIZEOFFREEZEFRAMETYPE_WRONG_RECORDNUMBER;
         }
      }
      /* else: SizeOfFreezeFrame remains 0 */
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
