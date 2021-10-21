/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetSizeOfExtendedDataRecordByDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetSizeOfExtendedDataRecordByDTC.c 2556 2011-09-08 11:34:37Z olho2924 $
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

FUNC(Dem_ReturnGetSizeOfExtendedDataRecordByDTCType, DEM_CODE)
Dem_GetSizeOfExtendedDataRecordByDTC(
   Dem_DTCType                               DTC,
   Dem_DTCKindType                           DTCKind,
   Dem_DTCOriginType                         DTCOrigin,
   uint8                                     ExtendedDataNumber,
   P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)   SizeOfExtendedDataRecord)
{
   Dem_ReturnGetSizeOfExtendedDataRecordByDTCType result;
   Dem_EventIdType EvId;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetSizeOfExtendedDataRecordByDTC, DEM_E_UNINIT);
      return DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC;
   }
   if ((DTC == (Dem_DTCType)0UL) || (DTC > (Dem_DTCType)0xFFFFFFUL))
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetSizeOfExtendedDataRecordByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetSizeOfExtendedDataRecordByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCKIND;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY ) )
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetSizeOfExtendedDataRecordByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCORIGIN;
   }
   if (SizeOfExtendedDataRecord == NULL_PTR)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetSizeOfExtendedDataRecordByDTC, DEM_E_PARAM_ADDRESS);
      return DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   *SizeOfExtendedDataRecord = 0U;

   /* search event Id by DTC and map return value */
   switch (Dem_GetEvIdByDTC(DTC, DTCKind, DTCOrigin, &EvId))
   {
      case DEM_EIBD_OK:
         result = DEM_GET_SIZEOFEDRBYDTCTYPE_OK;
         break;
      case DEM_EIBD_WRONG_DTC:
         result = DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC;
         break;
      case DEM_EIBD_WRONG_DTCKIND:
         result = DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCKIND;
         break;
      case DEM_EIBD_WRONG_DTCORIGIN:
         result = DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTCORIGIN;
         break;
      default: /* should never be reached */
         result = DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_DTC;
         break;
   }

   if (result == DEM_GET_SIZEOFEDRBYDTCTYPE_OK)
   {
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) EvMemEntry;
      boolean EntryExists;

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
         /* get extended data class layout */
         CONSTP2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST) EDClass =
            Dem_EDClasses[Dem_GbiEDClassIdx(EvId)];

#if (DEM_USE_GLOBAL_EDCLASS == STD_OFF)
   Dem_SizeEntryDataType EDClassSize = Dem_SizeOfED(EDClass);
#else
   /* substract CONDITION_BYTE and OCCURRENCE_COUNTER */
   Dem_SizeEntryDataType EDClassSize = (DEM_MAXSIZE_EDCLS - 2U);
#endif

         if (ExtendedDataNumber == 0xFFU)
         {
            /* add all record sizes of this extended data class (including
             * virtual records OCCURRENCE_COUNTER and CONDITION_BYTE) */
            *SizeOfExtendedDataRecord = (uint16)(EDClassSize + 2U);
         }
         else
         {
            /* check if record number is valid (is known) for this DTC */
            const Dem_EDSegIdxType SegIndex =
               Dem_FindEDNumIndex(EDClass, ExtendedDataNumber);

            if (SegIndex < EDClass->NumEDSegs)
            {
               *SizeOfExtendedDataRecord = (uint16)EDClass->Size[SegIndex];
            }
            else if ((ExtendedDataNumber == DEM_FIXED_EDSNUM_CONDITION_BYTE)
                  || (ExtendedDataNumber == DEM_FIXED_EDSNUM_OCCURRENCE_CNT))
            {
               *SizeOfExtendedDataRecord = 1U;
            }
            else
            {
               result = DEM_GET_SIZEOFEDRBYDTCTYPE_WRONG_RECORDNUMBER;
            }
         }
      }
      /* else: SizeOfExtendedDataRecord remains 0 */
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
