/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetFreezeFrameDataByDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetFreezeFrameDataByDTC.c 2561 2011-09-09 12:08:40Z olho2924 $
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

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief Function to get the size of an freeze frame segment including the 2
 ** bytes for the DID by the given freeze frame class and data Id
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] FFClass
 ** \param[in] DataId
 **
 ** \return Size of the freeze frame segment + 2
 **/
_STATIC_ FUNC(uint16, DEM_CODE) Dem_SizeOfFFInfo(
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass,
   uint16                                              DataId);

/** \brief Function to copy one freeze frame segment data Ids and values into
 ** the destination buffer
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] DestBuffer
 ** \param[in] FFClass
 ** \param[in] FFSegIndex  0 <= FFSegIndex < FFClass->NumFFSegs
 ** \param[in] FFEntryData
 **/
_STATIC_ FUNC(uint8, DEM_CODE) Dem_CopyFFSegInfo(
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)              DestBuffer,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass,
   const uint16                                        FFSegIndex,
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR) FFEntryData);

/** \brief Function to copy one or all freeze frame segment data Ids and
 ** values into the destination buffer
 **
 ** \reentrancy    non-reentrant
 ** \synchronisity synchronus
 **
 ** \param[in] DestBuffer
 ** \param[in] EventMemoryEntry
 ** \param[in] FFClass
 ** \param[in] RecIndex  0 <= RecIndex < EventMemoryEntry->NumFF
 ** \param[in] DataId
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_CopyFFInfo(
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)              DestBuffer,
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR)
                                                       EventMemoryEntry,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass,
   uint8                                               RecIndex,
   uint16                                              DataId);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)
   Dem_GetFreezeFrameDataByDTC(
      Dem_DTCType                               DTC,
      Dem_DTCKindType                           DTCKind,
      Dem_DTCOriginType                         DTCOrigin,
      uint8                                     RecordNumber,
      uint16                                    DataId,
      P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)    DestBuffer,
      P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)    BufSize)
{
   Dem_ReturnGetFreezeFrameDataByDTCType result;
   Dem_EventIdType EvId;
   Dem_FFIdxType NumberOfFF = 0;
   uint8 Idx = 0;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetFreezeFrameDataByDTC, DEM_E_UNINIT);
      return DEM_GET_FFDATABYDTC_WRONG_DTC;
   }
   if ((DTC == (Dem_DTCType)0UL) || (DTC > (Dem_DTCType)0xFFFFFFUL))
   {
      DEM_REPORT_ERROR(DEM_SID_GetFreezeFrameDataByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_FFDATABYDTC_WRONG_DTC;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetFreezeFrameDataByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_FFDATABYDTC_WRONG_DTCKIND;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY ) )
   {
      DEM_REPORT_ERROR(DEM_SID_GetFreezeFrameDataByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
   }
   if (BufSize == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetFreezeFrameDataByDTC, DEM_E_PARAM_ADDRESS);
      return DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
   }
   if (DestBuffer == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetFreezeFrameDataByDTC, DEM_E_PARAM_ADDRESS);
      return DEM_GET_FFDATABYDTC_WRONG_DTC;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* search event Id by DTC and map return value */
   switch (Dem_GetEvIdByDTC(DTC, DTCKind, DTCOrigin, &EvId))
   {
      case DEM_EIBD_OK:
         result = DEM_GET_FFDATABYDTC_OK;
         break;
      case DEM_EIBD_WRONG_DTC:
         result = DEM_GET_FFDATABYDTC_WRONG_DTC;
         break;
      case DEM_EIBD_WRONG_DTCKIND:
         result = DEM_GET_FFDATABYDTC_WRONG_DTCKIND;
         break;
      case DEM_EIBD_WRONG_DTCORIGIN:
         result = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
         break;
      default: /* should never be reached */
         result = DEM_GET_FFDATABYDTC_WRONG_DTC;
         break;
   }

   if (result == DEM_GET_FFDATABYDTC_OK)
   {
      P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) EvMemEntry;
      boolean EntryExists;

      /* get freeze frame class layout */
      CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass =
         Dem_FFClasses[Dem_GbiFFClassIdx(EvId)];

      const Dem_FFIdxType MaxNumFF = Dem_GbiMaxNumFF(EvId);

      const uint16 SizeFFInfo = (DataId == (uint16)0xFFFFU) ?
         (uint16)( Dem_SizeOfFF(FFClass) + (2U * FFClass->NumFFSegs) ) :
         Dem_SizeOfFFInfo(FFClass, DataId);

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
         NumberOfFF = EvMemEntry->NumFF;
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      if (! (((RecordNumber >= 1U) && (RecordNumber <= MaxNumFF))
             || (RecordNumber == 0xFFU)) )
      {
         /* one non-existend record requested: return "out of range" */
         result = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
      }
      else if (SizeFFInfo == 0U)
      {
         /* Data Id is not valid for this DTC */
         result = DEM_GET_FFDATABYDTC_WRONG_DATAID;
      }
      else if (EntryExists == FALSE)
      {
         /* No DTC stored, return empty buffer */
         *BufSize = 0U;
      }
      /* all FFs are requested? (if yes: at least one FF is stored) */
      else if (RecordNumber == 0xFFU)
      {
         /* calculate needed buffer size */
         const uint16 NeededSize = NumberOfFF * (2U + SizeFFInfo);

         /* range check, maximal buffersize is 255 bytes */
         if (NeededSize <= (uint16)*BufSize)
         {
            uint8 RecIndex;

            /* cycle through all stored freeze frame records */
            for (RecIndex = 0U; RecIndex < NumberOfFF; ++RecIndex)
            {
               DestBuffer[Idx]     = RecIndex + 1U;
               DestBuffer[Idx + 1] = (DataId == (uint16)0xFFFFU) ? FFClass->NumFFSegs : 1U;
               Idx += 2;

               Dem_CopyFFInfo(&DestBuffer[Idx], EvMemEntry, FFClass, RecIndex, DataId);
               Idx += (uint8)SizeFFInfo;
            }

            *BufSize = (uint8)NeededSize;
         }
         else /* destination buffer is too small */
         {
            result = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
         }
      }
      /* only one FF requested and record number is valid and stored */
      else if (RecordNumber <= NumberOfFF)
      {
         /* calculate needed buffer size */
         const uint16 NeededSize = 2U + SizeFFInfo;

         /* range check, maximal buffersize is 255 bytes */
         if (NeededSize <= (uint16)*BufSize)
         {
            /* write data for one record */
            DestBuffer[Idx]     = RecordNumber;
            DestBuffer[Idx + 1] = (DataId == (uint16)0xFFFFU) ? FFClass->NumFFSegs : 1U;
            Idx += 2;

            Dem_CopyFFInfo(&DestBuffer[Idx], EvMemEntry, FFClass, (RecordNumber - 1U), DataId);

            *BufSize = (uint8)NeededSize;
         }
         else /* destination buffer is too small */
         {
            result = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
         }
      }
      /* only one FF requested and record number is valid, but not stored */
      else
      {
         if (2U <= *BufSize)
         {
            DestBuffer[Idx]     = RecordNumber;
            DestBuffer[Idx + 1] = 0U; /* no DID and value follows */

            *BufSize = 2U;
         }
         else /* destination buffer is too small */
         {
            result = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
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

_STATIC_ FUNC(uint16, DEM_CODE) Dem_SizeOfFFInfo(
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass,
   uint16                                              DataId)
{
   Dem_FFSegIdxType SegIdx;

   for (SegIdx = 0U;
        (SegIdx < FFClass->NumFFSegs) && (FFClass->DataID[SegIdx] != DataId);
        ++SegIdx)
   {
      /* empty search loop */
   }

   /* if data Id was not found: size = 0 */
   return (uint16)( (SegIdx < FFClass->NumFFSegs) ?
      (FFClass->Size[SegIdx] + 2U) : 0U );
}

_STATIC_ FUNC(uint8, DEM_CODE) Dem_CopyFFSegInfo(
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)              DestBuffer,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass,
   const uint16                                        FFSegIndex,
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR) FFEntryData)
{
   DestBuffer[0] = (uint8)(FFClass->DataID[FFSegIndex] >> 8U);
   DestBuffer[1] = (uint8) FFClass->DataID[FFSegIndex];

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   /* write content into response */
   Dem_DataCopy(&FFEntryData[FFClass->StartByte[FFSegIndex]],
                &DestBuffer[2],
                FFClass->Size[FFSegIndex]);

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   return (2U + FFClass->Size[FFSegIndex]);
}

_STATIC_ FUNC(void, DEM_CODE) Dem_CopyFFInfo(
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)              DestBuffer,
   CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR)
                                                       EventMemoryEntry,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass,
   uint8                                               RecIndex,
   uint16                                              DataId)
{
   /* pointer to FF data */
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FFEntryData =
      Dem_FFEntryData(EventMemoryEntry, FFClass, RecIndex);

   Dem_FFSegIdxType SegIdx;
   uint8 Idx = 0;

   if (DataId == (uint16)0xFFFFU)
   {
      for (SegIdx = 0U; SegIdx < FFClass->NumFFSegs; ++SegIdx)
      {
         uint8 offset = Dem_CopyFFSegInfo(&DestBuffer[Idx], FFClass, SegIdx, FFEntryData);

         Idx += offset;
      }
   }
   else
   {
      /* find existing data Id and write DID value pair */
      for (SegIdx = 0U;
           (SegIdx < FFClass->NumFFSegs)
              && (FFClass->DataID[SegIdx] != DataId);
           ++SegIdx)
      {
         /* empty search loop */
      }

      if (SegIdx < FFClass->NumFFSegs)
      {
         /* discard return value -> size of copied data does not matter for
          * only one FF segment */
         (void) Dem_CopyFFSegInfo(DestBuffer, FFClass, SegIdx, FFEntryData);
      }
   }
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
