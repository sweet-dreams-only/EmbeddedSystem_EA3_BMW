/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetExtendedDataRecordByDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT Elektrobit Automotive, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetExtendedDataRecordByDTC.c 2556 2011-09-08 11:34:37Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by Elektrobit Automotive GmbH and BMW Group
 ** All rights exclusively reserved for Elektrobit Automotive GmbH and
 ** BMW Group, unless expressly agreed to otherwise
 **
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Internal_Depend_Specific.h>      /* API and internal declarations,
                                                * dependent and static part */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief Function to copy the ED informations of one record to the
 ** destination buffer
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EDClass
 ** \param[in] ExtendedDataNumber  0x01 <= ExtendedDataNumber <= 0xFE
 ** \param[in] EventMemoryEntry
 ** \param[out] DestBuffer
 ** \param[in/out] BufSize
 **
 ** \return Status of the operation of type
 ** Dem_ReturnGetExtendedDataRecordByDTCType
 **/
_STATIC_ FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
Dem_GetOneEDRecord(
   P2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST)        EDClass,
   uint8                                                 ExtendedDataNumber,
   P2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) EventMemoryEntry,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                DestBuffer,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                BufSize,
   Dem_DTCOriginType                                     DTCOrigin);

/** \brief Function to copy the ED informations of all records to the
 ** destination buffer
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] EDClass
 ** \param[in] EventMemoryEntry
 ** \param[out] DestBuffer
 ** \param[in/out] BufSize
 **
 ** \return Status of the operation of type
 ** Dem_ReturnGetExtendedDataRecordByDTCType
 **/
_STATIC_ FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
Dem_GetAllEDRecords(
   P2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST)        EDClass,
   P2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) EventMemoryEntry,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                DestBuffer,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                BufSize,
   Dem_DTCOriginType                                     DTCOrigin);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
Dem_GetExtendedDataRecordByDTC(
   Dem_DTCType                            DTC,
   Dem_DTCKindType                        DTCKind,
   Dem_DTCOriginType                      DTCOrigin,
   uint8                                  ExtendedDataNumber,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize)
{
   Dem_ReturnGetExtendedDataRecordByDTCType result;
   Dem_EventIdType EvId;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetExtendedDataRecordByDTC, DEM_E_UNINIT);
      return DEM_RECORD_WRONG_DTC;
   }
   if ((DTC == (Dem_DTCType)0UL) || (DTC > (Dem_DTCType)0xFFFFFFUL))
   {
      DEM_REPORT_ERROR(DEM_SID_GetExtendedDataRecordByDTC, DEM_E_PARAM_DATA);
      return DEM_RECORD_WRONG_DTC;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetExtendedDataRecordByDTC, DEM_E_PARAM_DATA);
      return DEM_RECORD_WRONG_DTCKIND;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY ) )
   {
      DEM_REPORT_ERROR(DEM_SID_GetExtendedDataRecordByDTC, DEM_E_PARAM_DATA);
      return DEM_RECORD_WRONG_DTCORIGIN;
   }
   if (BufSize == NULL_PTR)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetExtendedDataRecordByDTC, DEM_E_PARAM_ADDRESS);
      return DEM_RECORD_WRONG_BUFFERSIZE;
   }
   if (DestBuffer == NULL_PTR)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetExtendedDataRecordByDTC, DEM_E_PARAM_ADDRESS);
      return DEM_RECORD_WRONG_DTC;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* search event Id by DTC and map return value */
   switch (Dem_GetEvIdByDTC(DTC, DTCKind, DTCOrigin, &EvId))
   {
      case DEM_EIBD_OK:
         result = DEM_RECORD_OK;
         break;
      case DEM_EIBD_WRONG_DTC:
         result = DEM_RECORD_WRONG_DTC;
         break;
      case DEM_EIBD_WRONG_DTCKIND:
         result = DEM_RECORD_WRONG_DTCKIND;
         break;
      case DEM_EIBD_WRONG_DTCORIGIN:
         result = DEM_RECORD_WRONG_DTCORIGIN;
         break;
      default: /* should never be reached */
         result = DEM_RECORD_WRONG_DTC;
         break;
   }

   if (result == DEM_RECORD_OK)
   {
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) EvMemEntry;
      boolean EntryExists;

      /* get extended data class layout */
      CONSTP2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST) EDClass =
         Dem_EDClasses[Dem_GbiEDClassIdx(EvId)];

      /*
       * signal access of event memory
       */
      Dem_DcmAccessInProgress = TRUE;

      /* search for DTC in event memory */
      EntryExists = Dem_SearchForEntry(EvId, &EvMemEntry);

      if (EntryExists != FALSE)
      {
         result = (ExtendedDataNumber == 0xFFU) ?
            Dem_GetAllEDRecords(EDClass, EvMemEntry, DestBuffer, BufSize,
               DTCOrigin) :
            Dem_GetOneEDRecord(EDClass, ExtendedDataNumber, EvMemEntry,
               DestBuffer, BufSize, DTCOrigin);
      }
      else /* DTC not stored in event memory */
      {
         /* check if record number is valid (is known) for this DTC */
         const Dem_EDSegIdxType SegIndex =
            Dem_FindEDNumIndex(EDClass, ExtendedDataNumber);

         if ((SegIndex < EDClass->NumEDSegs)
             || (ExtendedDataNumber == 0xFFU))
         {
            /* Record number is valid for this DTC, but DTC is not stored:
             * return empty buffer */
            *BufSize = 0U;
         }
         else
         {
            /* Record number invalid for this DTC */
            result = DEM_RECORD_WRONG_NUMBER;
         }
      }

      /*
       * signal access of event memory finished
       */
      Dem_DcmAccessInProgress = FALSE;
   }

   return result;
}

/*==================[internal function definitions]=========================*/

_STATIC_ FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
Dem_GetOneEDRecord(
   P2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST)        EDClass,
   uint8                                                 ExtendedDataNumber,
   P2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) EventMemoryEntry,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                DestBuffer,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                BufSize,
   Dem_DTCOriginType                                     DTCOrigin)
{
   Dem_ReturnGetExtendedDataRecordByDTCType result = DEM_RECORD_WRONG_NUMBER;
   uint8 Idx = 0;

   /* check if record number is valid (is known) for this DTC */
   const Dem_EDSegIdxType SegIndex =
      Dem_FindEDNumIndex(EDClass, ExtendedDataNumber);

   if (SegIndex < EDClass->NumEDSegs)
   {
      /* calculate needed buffer size */
      const uint16 NeededSize = EDClass->Size[SegIndex] + 1U;

      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
      {

         /* pointer to ED data */
         CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) EDEntryData =
            Dem_EDEntryData(EventMemoryEntry);

         /* range check, maximal buffersize is 255 bytes */
         if (NeededSize <= (uint16)*BufSize)
         {
            /* copy the extended record number into the destination buffer */
            DestBuffer[Idx] = ExtendedDataNumber;
            Idx++;

            /* copy content of the record into the destination buffer */
            Dem_DataCopy(&EDEntryData[EDClass->StartByte[SegIndex]],
                         &DestBuffer[Idx],
                         EDClass->Size[SegIndex]);

            /* store size of buffer */
            *BufSize = (uint8)NeededSize;

            result = DEM_RECORD_OK;
         }
         else
         {
            result = DEM_RECORD_WRONG_BUFFERSIZE;
         }
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
   }
   else if ((ExtendedDataNumber == DEM_FIXED_EDSNUM_CONDITION_BYTE) ||
            (ExtendedDataNumber == DEM_FIXED_EDSNUM_OCCURRENCE_CNT))
   {
      if (2U <= *BufSize)
      {
         DestBuffer[Idx] = ExtendedDataNumber;
         Idx++;

         if (ExtendedDataNumber == DEM_FIXED_EDSNUM_CONDITION_BYTE)
         {
            DestBuffer[Idx] =
               (Dem_EntryDataType)DEM_IS_EV_MEM_OVERFLOW(DTCOrigin - 1U);
         }
         else /* ExtendedDataNumber == DEM_FIXED_EDSNUM_OCCURRENCE_CNT */
         {
            DestBuffer[Idx] =
               (Dem_EntryDataType)EventMemoryEntry->OccurrenceCounter;
         }

         /* store size of buffer */
         *BufSize = 2U;

         result = DEM_RECORD_OK;
      }
      else
      {
         result = DEM_RECORD_WRONG_BUFFERSIZE;
      }
   }
   else
   {
      /* Record number not found in extended data */
   }

   return result;
}

_STATIC_ FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
Dem_GetAllEDRecords(
   P2CONST(Dem_EDClassType, AUTOMATIC, DEM_CONST)        EDClass,
   P2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) EventMemoryEntry,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                DestBuffer,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)                BufSize,
   Dem_DTCOriginType                                     DTCOrigin)
{
   Dem_ReturnGetExtendedDataRecordByDTCType result =
      DEM_RECORD_WRONG_BUFFERSIZE;
   Dem_EDSegIdxType SegIndex;
   uint8 Idx = 0;

#if (DEM_USE_GLOBAL_EDCLASS == STD_OFF)
   Dem_SizeEntryDataType EDClassSize = Dem_SizeOfED(EDClass);
#else
   /* substract CONDITION_BYTE and OCCURRENCE_COUNTER */
   Dem_SizeEntryDataType EDClassSize = (DEM_MAXSIZE_EDCLS - 2U);
#endif

   /* add 2 bytes for CONDITION_BYTE (1 byte record number and 1 byte data)
    * add 2 bytes for OCCURRENCE_COUNTER (1 byte number and 1 byte data)
    * add size of ED record number (for each ED segment)
    * add size of ED segment data */
   const uint16 NeededSize = 2U + 2U + (1U * EDClass->NumEDSegs) + EDClassSize;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
   {
      /* pointer to ED data */
      CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) EDEntryData =
         Dem_EDEntryData(EventMemoryEntry);

      /* range check, maximal buffersize is 255 bytes */
      if (NeededSize <= (uint16)*BufSize)
      {
         /* copy CONDITION_BYTE */
         DestBuffer[Idx]     = DEM_FIXED_EDSNUM_CONDITION_BYTE;
         DestBuffer[Idx + 1] = (Dem_EntryDataType)DEM_IS_EV_MEM_OVERFLOW(DTCOrigin - 1U);
         Idx += 2;

         /* copy OCCURRENCE_COUNTER */
         DestBuffer[Idx]     = DEM_FIXED_EDSNUM_OCCURRENCE_CNT;
         DestBuffer[Idx + 1] = (Dem_EntryDataType)EventMemoryEntry->OccurrenceCounter;
         Idx += 2;

         /* copy "regular" ED records */
         for (SegIndex = 0U; SegIndex < EDClass->NumEDSegs; ++SegIndex)
         {
            /* copy the extended record number into the destination buffer */
            DestBuffer[Idx] = EDClass->Number[SegIndex];
            Idx++;

            /* copy content of the record into the destination buffer */
            Dem_DataCopy(&EDEntryData[EDClass->StartByte[SegIndex]],
                         &DestBuffer[Idx],
                         EDClass->Size[SegIndex]);

            Idx += EDClass->Size[SegIndex];
         }

         /* store size of buffer */
         *BufSize = (uint8)NeededSize;

         result = DEM_RECORD_OK;
      }
      /* else: buffer size insufficient */
   }
   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
