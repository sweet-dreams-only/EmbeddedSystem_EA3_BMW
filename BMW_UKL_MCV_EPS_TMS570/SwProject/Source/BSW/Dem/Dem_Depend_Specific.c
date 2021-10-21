/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the configuration and non-API relevant implementation
 ** of the AUTOSAR module Dem, which is variant specific.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Depend_Specific.c.m4 2558 2011-09-09 10:30:11Z olho2924 $
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

#include <Dem_Helper.h>                                /* Dem helper macros */
#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

/*==================[macros]================================================*/

/*------------------[AUTOSAR specification version identification check]----*/

#if (!defined DEM_AR_MAJOR_VERSION) /* configuration check */
#error DEM_AR_MAJOR_VERSION must be defined
#endif /* if (!defined DEM_AR_MAJOR_VERSION) */

/* major version check */
#if (DEM_AR_MAJOR_VERSION != 2U)
#error DEM_AR_MAJOR_VERSION wrong (!= 2U)
#endif /* if DEM_AR_MAJOR_VERSION */

#if (!defined DEM_AR_MINOR_VERSION) /* configuration check */
#error DEM_AR_MINOR_VERSION must be defined
#endif /* if (!defined DEM_AR_MINOR_VERSION) */

/* minor version check */
#if (DEM_AR_MINOR_VERSION < 1U)
#error DEM_AR_MINOR_VERSION wrong (< 1U)
#endif /* if DEM_AR_MINOR_VERSION */

#if (!defined DEM_AR_PATCH_VERSION) /* configuration check */
#error DEM_AR_PATCH_VERSION must be defined
#endif /* if (!defined DEM_AR_PATCH_VERSION) */

/* patch version check */
#if (DEM_AR_PATCH_VERSION < 1U)
#error DEM_AR_PATCH_VERSION wrong (< 1U)
#endif /* if DEM_AR_PATCH_VERSION */

/*------------------[AUTOSAR module version identification check]-----------*/

#if (!defined DEM_SW_MAJOR_VERSION) /* configuration check */
#error DEM_SW_MAJOR_VERSION must be defined
#endif /* if (!defined DEM_SW_MAJOR_VERSION) */

/* major version check */
#if (DEM_SW_MAJOR_VERSION != 3U)
#error DEM_SW_MAJOR_VERSION wrong (!= 3U)
#endif /* if DEM_SW_MAJOR_VERSION */

#if (!defined DEM_SW_MINOR_VERSION) /* configuration check */
#error DEM_SW_MINOR_VERSION must be defined
#endif /* if (!defined DEM_SW_MINOR_VERSION) */

/* minor version check */
#if (DEM_SW_MINOR_VERSION < 3U)
#error DEM_SW_MINOR_VERSION wrong (< 3U)
#endif /* if DEM_SW_MINOR_VERSION */

#if (!defined DEM_SW_PATCH_VERSION) /* configuration check */
#error DEM_SW_PATCH_VERSION must be defined
#endif /* if (!defined DEM_SW_PATCH_VERSION) */

/* patch version check */
#if (DEM_SW_PATCH_VERSION < 3U)
#error DEM_SW_PATCH_VERSION wrong (< 3U)
#endif /* if DEM_SW_PATCH_VERSION */

/*------------------[NvM Block IDs for DEM  non volatile data]--------------*/

#define DEM_NVM_BLOCK_ID_PRIMARY   NVM_BLOCK_DEM_PRIMARY

#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U)
#define DEM_NVM_BLOCK_ID_SECONDARY NVM_BLOCK_DEM_SECONDARY
#else
#define DEM_NVM_BLOCK_ID_SECONDARY 0U
#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U)
#define DEM_NVM_BLOCK_ID_MIRROR    NVM_BLOCK_DEM_MIRROR
#else
#define DEM_NVM_BLOCK_ID_MIRROR    0U
#endif

/** \brief Service Id of NvM_WriteBlock() */
#define DEM_NVM_SERVICE_ID_WRITE_BLOCK 0x07U

/*==================[type definitions]======================================*/

typedef CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT)
   Dem_EntryDataConstPtrType;

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/** \brief Function to copy entry data into gate-entry or backwards
 **
 ** \param[in] FromEntryData  pointer to entry data from which shall be copied
 ** \param[in] IntoEntryData  pointer to entry data into which shall be copied
 ** \param[in] Number  number of entry data (bytes) which shall be copied
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_EntryDataCopy(
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FromEntryData,
   CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT)   IntoEntryData,
   Dem_SizeEntryDataType                                      Number);

/** \brief Function to store given entry to the NvRam by using the gate-entry
 **
 ** \param[in] originIdx
 ** \param[in] entryIdx
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_StoreImmediately(
   const uint8                  originIdx,
   const Dem_SizeEvMemEntryType entryIdx);

/** \brief Function to search for next entry to be stored immediately
 **
 ** This function is invoked from a single block callback function from NvM.
 **
 ** \param[in] originIdx
 **/
_STATIC_ FUNC(void, DEM_CODE) Dem_StoreImmediatelyNext(
   const uint8 originIdx);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[external constants]====================================*/

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/** \brief Primary event memory */
_STATIC_ VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT)
   Dem_EventMemoryPrimary[DEM_MAX_NUMBER_EVENT_ENTRY_PRM];

#if DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U
/** \brief Secondary event memory */
_STATIC_ VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT)
   Dem_EventMemorySecondary[DEM_MAX_NUMBER_EVENT_ENTRY_SEC];
#endif

#if DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U
/** \brief Mirror event memory */
_STATIC_ VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT)
   Dem_EventMemoryMirror[DEM_MAX_NUMBER_EVENT_ENTRY_MIR];
#endif

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/** \brief Primary entry data area */
_STATIC_ VAR(Dem_EntryDataType, DEM_VAR_NOINIT) Dem_EntryDataPrimary[
   DEM_SIZE_ENTRY_DATA_PRIMARY];

#if DEM_SIZE_ENTRY_DATA_SECONDARY != 0U
/** \brief Secondary entry data area */
_STATIC_ VAR(Dem_EntryDataType, DEM_VAR_NOINIT) Dem_EntryDataSecondary[
   DEM_SIZE_ENTRY_DATA_SECONDARY];
#endif

#if DEM_SIZE_ENTRY_DATA_MIRROR != 0U
/** \brief Mirror entry data area */
_STATIC_ VAR(Dem_EntryDataType, DEM_VAR_NOINIT) Dem_EntryDataMirror[
   DEM_SIZE_ENTRY_DATA_MIRROR];
#endif

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"

/** \brief Primary entry data free position */
_STATIC_ VAR(Dem_SizeEntryDataType, DEM_VAR_NOINIT)
   Dem_EntryDataFreePosPrimary;

#if DEM_SIZE_ENTRY_DATA_SECONDARY != 0U
/** \brief Secondary entry data free position */
_STATIC_ VAR(Dem_SizeEntryDataType, DEM_VAR_NOINIT)
   Dem_EntryDataFreePosSecondary;
#endif

#if DEM_SIZE_ENTRY_DATA_MIRROR != 0U
/** \brief Mirror entry data free position */
_STATIC_ VAR(Dem_SizeEntryDataType, DEM_VAR_NOINIT)
   Dem_EntryDataFreePosMirror;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Pointer to the DTC status masks */
CONSTP2VAR(Dem_DTCStatusMaskType, DEM_CONST, DEM_VAR_NOINIT)
   Dem_DTCStatusMasks = Dem_NvStatusData.DTCStatusMask;

/* Pointer to the clear pending DTC flags */
CONSTP2VAR(uint8, DEM_CONST, DEM_VAR_NOINIT) Dem_ClearPDTCFlags =
   Dem_NvStatusData.ClearPDTC;

CONSTP2VAR(uint8, DEM_CONST, DEM_VAR_NOINIT) Dem_EvMemOverflowFlags =
   &Dem_NvStatusData.EvMemOverflowFlags;

/* Pointers to the event memories */
CONSTP2VAR(Dem_EventMemoryEntryType, DEM_CONST, DEM_VAR_NOINIT)
Dem_EventMem[DEM_MAXNUM_ORIGINS] =
{
   Dem_EventMemoryPrimary,
#if DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U
   Dem_EventMemorySecondary,
#else
   NULL_PTR,
#endif
#if DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U
   Dem_EventMemoryMirror
#else
   NULL_PTR
#endif
};

/* Pointers to the event memory entry data */
CONSTP2VAR(Dem_EntryDataType, DEM_CONST, DEM_VAR_NOINIT)
Dem_EntryData[DEM_MAXNUM_ORIGINS] =
{
   Dem_EntryDataPrimary,
#if DEM_SIZE_ENTRY_DATA_SECONDARY != 0U
   Dem_EntryDataSecondary,
#else
   NULL_PTR,
#endif
#if DEM_SIZE_ENTRY_DATA_MIRROR != 0U
   Dem_EntryDataMirror
#else
   NULL_PTR
#endif
};

/* Pointers to the event memory entry free position data */
CONSTP2VAR(Dem_SizeEntryDataType, DEM_CONST, DEM_VAR_NOINIT)
Dem_EntryDataFreePos[DEM_MAXNUM_ORIGINS] =
{
   &Dem_EntryDataFreePosPrimary,
#if DEM_SIZE_ENTRY_DATA_SECONDARY != 0U
   &Dem_EntryDataFreePosSecondary,
#else
   NULL_PTR,
#endif
#if DEM_SIZE_ENTRY_DATA_MIRROR != 0U
   &Dem_EntryDataFreePosMirror
#else
   NULL_PTR
#endif
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]====================================*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/** \brief Array of NvRam block Id's */
_STATIC_ CONST(NvM_BlockIdType, DEM_CONST)
Dem_NvDataBlockId[DEM_MAXNUM_ORIGINS] =
{
   DEM_NVM_BLOCK_ID_PRIMARY,
   DEM_NVM_BLOCK_ID_SECONDARY,
   DEM_NVM_BLOCK_ID_MIRROR
};

_STATIC_ Dem_NvGateEntryDataPtrVoid Dem_NvGateEntryData[DEM_MAXNUM_ORIGINS] =
{
   (Dem_NvGateEntryDataPtrVoid) &Dem_NvGateEntryPrimaryData,
#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U)
   (Dem_NvGateEntryDataPtrVoid) &Dem_NvGateEntrySecondaryData,
#else
   (Dem_NvGateEntryDataPtrVoid) NULL_PTR,
#endif
#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U)
   (Dem_NvGateEntryDataPtrVoid) &Dem_NvGateEntryMirrorData
#else
   (Dem_NvGateEntryDataPtrVoid) NULL_PTR
#endif
};

_STATIC_ Dem_GateEntryDataPtrVoid Dem_GateEntryData[DEM_MAXNUM_ORIGINS] =
{
   (Dem_GateEntryDataPtrVoid)
      &Dem_NvGateEntryPrimaryData.EntryPrimary.EntryData,
#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U)
   (Dem_GateEntryDataPtrVoid)
      &Dem_NvGateEntrySecondaryData.EntrySecondary.EntryData,
#else
   (Dem_GateEntryDataPtrVoid) NULL_PTR,
#endif
#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U)
   (Dem_GateEntryDataPtrVoid)
      &Dem_NvGateEntryMirrorData.EntryMirror.EntryData
#else
   (Dem_GateEntryDataPtrVoid) NULL_PTR
#endif
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[external data]=========================================*/

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Non volatile status data of the DEM */
VAR(Dem_NvStatusDataType, DEM_VAR_NOINIT) Dem_NvStatusData;

/* Non volatile primary data of the DEM */
VAR(Dem_NvGateEntryPrimaryDataType, DEM_VAR_NOINIT)
   Dem_NvGateEntryPrimaryData;

#if DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U
/* Non volatile secondary data of the DEM */
VAR(Dem_NvGateEntrySecondaryDataType, DEM_VAR_NOINIT)
   Dem_NvGateEntrySecondaryData;
#endif

#if DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U
/* Non volatile mirror data of the DEM */
VAR(Dem_NvGateEntryMirrorDataType, DEM_VAR_NOINIT)
   Dem_NvGateEntryMirrorData;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/* Event status update counters */
VAR(uint8, DEM_VAR_NOINIT) Dem_EvStUpdateAllowed[DEM_NUM_DTC_GROUPS];
/* DTC storage counters */
VAR(uint8, DEM_VAR_NOINIT) Dem_DTCStorageAllowed[DEM_NUM_DTC_GROUPS];

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[internal core-function definitions]--------------------*/

FUNC(boolean, DEM_CODE) Dem_GbiClrEvAllowedRteUseage(const Dem_EventIdType EventId)
{
   return (boolean)DEM_IS_BIT_SET(Dem_EventDescSpecific[EventId].EvConf1,
                    ( 1U << DEM_RTE_CBK_CLEAR_EV_ALLOWED ));
}

FUNC(boolean, DEM_CODE) Dem_GbiClrEvAllowedCCallback(const Dem_EventIdType EventId)
{
   return (boolean)DEM_IS_BIT_SET(Dem_EventDescSpecific[EventId].EvConf1,
                    ( 1U << DEM_C_CBK_CLEAR_EV_ALLOWED ));
}

FUNC(boolean, DEM_CODE) Dem_GbiTriggerOnErrorRteUseage(const Dem_EventIdType EventId)
{
   return (boolean)DEM_IS_BIT_SET(Dem_EventDescSpecific[EventId].EvConf1,
                    ( 1U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR ));
}

FUNC(boolean, DEM_CODE) Dem_GbiTriggerOnErrorCCallback(const Dem_EventIdType EventId)
{
   return (boolean)DEM_IS_BIT_SET(Dem_EventDescSpecific[EventId].EvConf1,
                    ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR ));
}

#if ( (DEM_USE_IMMSTORAGE == STD_ON) && (DEM_USE_IMMSTORAGE_GLOBAL == STD_OFF) )
FUNC(boolean, DEM_CODE) Dem_GbiImmStorage(const Dem_EventIdType EventId)
{
   return (boolean)DEM_BIT_FIELD_VALUE_32(Dem_EventDescSpecific[EventId].EvConf1,
                                          DEM_IMMSTORAGE_OFFSET,
                                          DEM_IMMSTORAGE_MASK);
}
#endif

FUNC(boolean, DEM_CODE) Dem_GbiRoeActive(const Dem_EventIdType EventId)
{
   return (boolean)DEM_BIT_FIELD_VALUE_32(Dem_EventDescSpecific[EventId].EvConf1,
                                          DEM_ROEACTIVE_OFFSET,
                                          DEM_ROEACTIVE_MASK);
}

FUNC(void, DEM_CODE) Dem_SpecificHookInitNvData(void)
{
   Dem_EventIdType EvId;

   uint8 originIdx;
   Dem_SizeEvMemEntryType entryIdx;

   NvM_RequestResultType reqres = NVM_REQ_NOT_OK;

   /* DTC Status Bytes may be obsolet (but this can't be proved) or defect, so
    * ever restore Status-Bits where possible. */

   /* first clear all CDTC bits */
   for (EvId = 0U;
        EvId < (Dem_EventIdType)DEM_NUMBER_OF_EVENTS;
        ++EvId)
   {
      DEM_CLR_EV_ST_MASK(EvId, DEM_DTCSTATUSBIT_CDTC);
   }

   /* restore all event memory entries */

   for (originIdx = 0U; originIdx < (uint8)DEM_MAXNUM_ORIGINS; ++originIdx)
   {
      const Dem_SizeEvMemEntryType sizeEventMem = Dem_SizeEventMem[originIdx];

      if (sizeEventMem != (Dem_SizeEvMemEntryType)0U)
      {
         CONSTP2VAR(Dem_GateEntryBaseType, AUTOMATIC, DEM_VAR_NOINIT)
            GateEntryBase = Dem_NvGateEntryData[originIdx];

         const NvM_BlockIdType NvDataBlockId = Dem_NvDataBlockId[originIdx];

         /* clear gate-entry (for case that no entry could be restored) */
         GateEntryBase->EntryBase.EventId = DEM_EVENT_ID_INVALID;

         /* Dem_EntryDataFreePos[originIdx] may be NULL_PTR if all events
          * configured for this memory origin don't have any "normal" entry
          * data */
         if (Dem_EntryDataFreePos[originIdx] != NULL_PTR)
         {
            /* initalize free position of event memory entry data */
            *(Dem_EntryDataFreePos[originIdx]) = 0U;
         }

         /* for every event entry */
         for (entryIdx = 0U; entryIdx < sizeEventMem; ++entryIdx)
         {
            CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
               EvMemEntry = &Dem_EventMem[originIdx][entryIdx];

            Std_ReturnType readBlockRes;

            /* select corresponding NvRam block data */
            NvM_SetDataIndex(NvDataBlockId, (uint8)entryIdx);

            /* queue read command of gate-entry to NvM */
            readBlockRes = NvM_ReadBlock(NvDataBlockId, NULL_PTR);

            /* NvM declined read command - not handled in this version */
            if (readBlockRes != E_OK)
            {
               /* EvMemEntry->EntryStatus = DEM_ENTRY_CHANGED; */

               /* Development Error Detection ? */
            }

            Dem_StorageWaitNvMReady(NvDataBlockId);

            /* check if NVRAM dataset was successfully restored */
            NvM_GetErrorStatus(NvDataBlockId, &reqres);

            if ((reqres == NVM_REQ_OK) &&
                (GateEntryBase->EntryBase.EventId < DEM_NUMBER_OF_EVENTS))
            {
               /* copy gate-entry into event memory entry */

               EvId = GateEntryBase->EntryBase.EventId;

               EvMemEntry->EventId = EvId;

               /* mark event entry as non-changed concerning its persistent
                * data */
               EvMemEntry->EntryStatus = DEM_ENTRY_NOT_CHANGED;

               if (EvId != (Dem_EventIdType)DEM_EVENT_ID_INVALID)
               {
                  /* test for right origin */
                  if ( (Dem_GbiDTCOrigin(EvId) - DEM_DTC_ORIGIN_PRIMARY_MEMORY) == originIdx)
                  {
                     /* transfer gate-entry into event memory */

                     const Dem_OccurrenceCtrType OccurrenceCtr =
                        GateEntryBase->EntryBase.OccurrenceCounter;

                     const Dem_FFIdxType MaxNumFF = Dem_GbiMaxNumFF(EvId);
                     const Dem_SizeEntryDataType EntryDataFreePos =
                        ( ( Dem_EntryDataFreePos[originIdx] != NULL_PTR )
                          ? *(Dem_EntryDataFreePos[originIdx])
                          : 0U
                        );
                     const Dem_SizeEntryDataType sizeEntryData =
                        Dem_SizeOfEntryData(EvId);

                     EvMemEntry->OccurrenceCounter = OccurrenceCtr;
                     EvMemEntry->EntryDataPos      = EntryDataFreePos;

                     /* calculate number of freeze frame records */
                     EvMemEntry->NumFF =
                        (Dem_FFIdxType)((OccurrenceCtr > MaxNumFF) ?
                           MaxNumFF : OccurrenceCtr);

                     if (sizeEntryData > 0U)
                     {
                        /* copy gate-entry data into event memory entry data */
                        Dem_EntryDataCopy(
                           (Dem_EntryDataConstPtrType)Dem_GateEntryData[originIdx],
                           &Dem_EntryData[originIdx][EntryDataFreePos],
                           sizeEntryData);

                        /* recalculate free position of event memory entry data
                         */
                        *(Dem_EntryDataFreePos[originIdx]) += sizeEntryData;
                     }

                     /* restore possible Status-Bits (CDTC, TNCSLC, TFSLC) of
                      * possibly obsolete DTC Status Bytes for entered events */

                     DEM_CLR_EV_ST_MASK(EvId, DEM_DTCSTATUSBIT_TNCSLC);

                     DEM_SET_EV_ST_MASK(EvId,
                                        DEM_DTCSTATUSBIT_CDTC |
                                        DEM_DTCSTATUSBIT_TFSLC);
                  }
                  else
                  {
                     /* clear event memory entry */
                     EvMemEntry->EventId = DEM_EVENT_ID_INVALID;
                     /* not necessary to reset EvMemEntry->NumFF (= 0) */
                     /* not necessary to reset EvMemEntry->EntryDataPos (= 0) */
                     /* not necessary to reset EvMemEntry->OccurrenceCounter (= 0) */
                     /* not necessary to reset event memory entry data */

                     EvMemEntry->EntryStatus = DEM_ENTRY_CHANGED;
                  }
               }
               /* else: not necessary to reset any other data of this entry */
            }
            else
            {
               /* clear event memory entry */
               EvMemEntry->EventId = DEM_EVENT_ID_INVALID;
               /* not necessary to reset EvMemEntry->NumFF (= 0) */
               /* not necessary to reset EvMemEntry->EntryDataPos (= 0) */
               /* not necessary to reset EvMemEntry->OccurrenceCounter (= 0) */
               /* not necessary to reset event memory entry data */

               EvMemEntry->EntryStatus = DEM_ENTRY_CHANGED;
            }
         }
      }
   }

   /* clear all PDTC bits of all non-entered events (see CR61439) */
   for (EvId = 0U;
        EvId < (Dem_EventIdType)DEM_NUMBER_OF_EVENTS;
        ++EvId)
   {
      if (DEM_IS_BIT_SET(Dem_DTCStatusMasks[EvId], DEM_DTCSTATUSBIT_PDTC))
      {
         P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) EvMemEntry;

         /* search for DTC in event memory */
         if (Dem_SearchForEntry(EvId, &EvMemEntry) == FALSE)
         {
            /* clear PDTC bit for non-entered event */
            DEM_CLR_EV_ST_MASK(EvId, DEM_DTCSTATUSBIT_PDTC);
         }
      }
   }
}

FUNC(void, DEM_CODE) Dem_ResetNvData(void)
{
   Dem_EvIdLeastType EvId;
   Dem_EvIdLeastType byteIdx;

   /* init loop for events */
   for (EvId = 0U; EvId <= (DEM_NUMBER_OF_EVENTS - 1U); ++EvId)
   {
      /* clear all DTC status bits beside "not testet this operating cycle"
       * and "not tested since last clear" */
      Dem_DTCStatusMasks[EvId] =
         DEM_DTCSTATUSBIT_TNCSLC |
         DEM_DTCSTATUSBIT_TNCTOC;
   }

   /* initialize "Clear Pending DTC"-flags */
   for (byteIdx = 0U;
        byteIdx < (((DEM_NUMBER_OF_EVENTS - 1U) / 8U) + 1U);
        ++byteIdx)
   {
      /* set eight-bit-group at once */
      Dem_ClearPDTCFlags[byteIdx] = 0U;
   }

   /* clear all event memory overflow flags */
   *Dem_EvMemOverflowFlags = 0U;
}

FUNC(void, DEM_CODE) Dem_ShutdownNvData(void)
{
   uint8 originIdx;
   Dem_SizeEvMemEntryType entryIdx;

   /* reset shutdown-cancellation (if still activated) */
   Dem_ShutdownCancellation = FALSE;

   /*
    * Enter critical shutdown phase
    */
   Dem_ShutdownActive = TRUE;

   for (originIdx = 0U;
           (originIdx < (uint8)DEM_MAXNUM_ORIGINS)
        && (Dem_ShutdownCancellation == FALSE); /* stop at cancellation */
        ++originIdx)
   {
      Dem_StorageWaitNvMReady(Dem_NvDataBlockId[originIdx]);

      /* for every event entry */
      for (entryIdx = 0U;
              (entryIdx < Dem_SizeEventMem[originIdx])
           && (Dem_ShutdownCancellation == FALSE); /* stop at cancellation */
           ++entryIdx)
      {
         if (Dem_EventMem[originIdx][entryIdx].EntryStatus
                != DEM_ENTRY_NOT_CHANGED)
         {
            /* if shutdown will be canceled, this entry is marked as stored
             * persistently */
            Dem_EventMem[originIdx][entryIdx].EntryStatus =
               DEM_ENTRY_NOT_CHANGED;

            /* store this primary event memory entry persistent immediately */
            Dem_StoreImmediately(originIdx, entryIdx);

            Dem_StorageWaitNvMReady(Dem_NvDataBlockId[originIdx]);
         }
      }
   }

   /*
    * Leave critical shutdown phase
    */
   Dem_ShutdownActive = FALSE;
   /* NXTR PATCH START
    * Added: 4/1/15
    * Reason: Enable a quick loop write for NvM. Trigger placed after DEM shutdown to prevent possible re-entrance of NvM functions
    */
   CDD_NvMFastWriteEnable_Cnt_G_lgc = TRUE;
   /* NXTR PATCH END */

   if (Dem_ShutdownCancellation == FALSE)
   {
      /* validate Dem_NvStatusData, to be stored persistently during
       * NvM_WriteAll() */
      NvM_SetRamBlockStatus(DEM_NVM_BLOCK_ID_DEFAULT, TRUE);

      /* persistent storage of Dem_NvStatusData must be done within
       * NvM_WriteAll() */
   }
   else /* Dem_ShutdownCancellation == TRUE -> DEM remains initialized */
   {
      /* reset internal flag to initialized-state */
      Dem_InitializationState = DEM_INITIALIZED;
   }
}

#if (DEM_USE_IMMSTORAGE == STD_ON)

FUNC(void, DEM_CODE) Dem_CheckForImmediateEntryStorage(
   Dem_EventIdType                                     OriginalEventId,
   CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR)
                                                       EventMemoryEntry,
   boolean                                             CheckForLocking,
   boolean                                             ForceImmediate)
{
   const Dem_EventIdType CurrentEventId = EventMemoryEntry->EventId;

   const Dem_DTCOriginType origin = Dem_GbiDTCOrigin(OriginalEventId);
   const uint8 originIdx = (uint8)(origin - DEM_DTC_ORIGIN_PRIMARY_MEMORY);
   boolean ImmStorage = TRUE;

   /* check for immediate storage
    * (immediate storage for DEM_EVENT_ID_INVALID is always false) */
   if (ForceImmediate == FALSE)
   {
      if (Dem_GbiImmStorage(CurrentEventId) == FALSE)
      {
         ImmStorage = Dem_GbiImmStorage(OriginalEventId);
      }
   }

   if (ImmStorage != FALSE)
   {
      NvM_RequestResultType reqres = NVM_REQ_NOT_OK;

      if (CheckForLocking != FALSE)
      {
         Dem_LockWhileImmediateStorage[originIdx] = TRUE;
      }

      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      NvM_GetErrorStatus(Dem_NvDataBlockId[originIdx], &reqres);

      /* check if no former gate-entry is queued or in copying */
      if (reqres != NVM_REQ_PENDING)
      {
         const Dem_SizeEvMemEntryType sizeEventMem =
            Dem_SizeEventMem[originIdx];

         Dem_SizeEvMemEntryType entryIdx;
         P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT)
            EventMemory = Dem_EventMem[originIdx];

         /* search for entry in event memory */
         for (entryIdx = 0U;
              (   (entryIdx < sizeEventMem) /* should never happen */
               && (EventMemoryEntry != &EventMemory[entryIdx]));
              ++entryIdx)
         {
            /* empty search loop */
         }

         /* entry was found */
         if (entryIdx < sizeEventMem)
         {
            EventMemoryEntry->EntryStatus = DEM_ENTRY_NOT_CHANGED;

            /* initiate copying to NvRam */
            Dem_StoreImmediately(originIdx, entryIdx);
         }
         /* else: should never happen */
      }
      else
      {
         EventMemoryEntry->EntryStatus = DEM_ENTRY_STORE_IMMEDIATELY;
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
   }
   else /* no immediate storage - store changed entry at shutdown */
   {
      EventMemoryEntry->EntryStatus = DEM_ENTRY_CHANGED;
   }
}

#endif /* DEM_USE_IMMSTORAGE */

/*------------------[interface from NvM]------------------------------------*/

FUNC(Std_ReturnType, DEM_CODE) Dem_NvMGateEntryPrimaryBlockCallback(
   uint8                 ServiceId,
   NvM_RequestResultType JobResult)
{
   /* job result is not directly needed */
   DEM_PARAM_UNUSED(JobResult);

   if (ServiceId == DEM_NVM_SERVICE_ID_WRITE_BLOCK)
   {
      Dem_StoreImmediatelyNext((uint8)(DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U));
   }

   return E_OK;
}

#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC != 0U)
FUNC(Std_ReturnType, DEM_CODE) Dem_NvMGateEntrySecondaryBlockCallback(
   uint8                 ServiceId,
   NvM_RequestResultType JobResult)
{
   /* job result is not directly needed */
   DEM_PARAM_UNUSED(JobResult);

   if (ServiceId == DEM_NVM_SERVICE_ID_WRITE_BLOCK)
   {
      Dem_StoreImmediatelyNext((uint8)(DEM_DTC_ORIGIN_SECONDARY_MEMORY - 1U));
   }

   return E_OK;
}
#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR != 0U)
FUNC(Std_ReturnType, DEM_CODE) Dem_NvMGateEntryMirrorBlockCallback(
   uint8                 ServiceId,
   NvM_RequestResultType JobResult)
{
   /* job result is not directly needed */
   DEM_PARAM_UNUSED(JobResult);

   if (ServiceId == DEM_NVM_SERVICE_ID_WRITE_BLOCK)
   {
      Dem_StoreImmediatelyNext((uint8)(DEM_DTC_ORIGIN_MIRROR_MEMORY - 1U));
   }

   return E_OK;
}
#endif

/*------------------[interface to Rte]--------------------------------------*/

FUNC(void, DEM_CODE) Dem_RteTriggerOnErrorEntry(
   const Dem_EventIdType EventId,
   const uint32          Timestamp)
{
#if (   (DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE == 0U) \
     && (DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE == 0U))
   DEM_PARAM_UNUSED(EventId);
   DEM_PARAM_UNUSED(Timestamp);
#else
   uint16 CbIdx = 0U;
#endif
#if (DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE > 0U)
   Std_ReturnType RetVal = E_NOT_OK;
   uint16 StartIdx = 0U;
   uint16 NumberOfCb = 0U;
   uint16 i;
#endif

#if (DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE > 0U)
   if (Dem_GbiTriggerOnErrorRteUseage(EventId) != FALSE)
   {
      Rte_PortHandle_CallbackTriggerOnErrorEntry_R triggerOnErrorEntryCBPorts =
         Rte_Ports_CallbackTriggerOnErrorEntry_R();

      while (   (CbIdx < DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE)
             && (Dem_RteLookupTableTriggerOnError[CbIdx] != EventId))
      {
         CbIdx++;
      }

      if (CbIdx < DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE)
      {
         /* notify application that error entry was done,
          * return value is not evaluated -> error handling has to be done
          * by application */
         (void)triggerOnErrorEntryCBPorts[CbIdx].Call_TriggerOnErrorEntry(
            Dem_GbiDTC(EventId), Timestamp);
      }
   }
#endif

#if (DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE > 0U)
   if (Dem_GbiTriggerOnErrorCCallback(EventId) != FALSE)
   {
      RetVal = Dem_GetCallbackIndex(
           EventId,
           Dem_CbkLookupTableTriggerOnError,
           DEM_C_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE,
           &StartIdx,
           &NumberOfCb);
      if (RetVal == E_OK)
      {
         for (i = 0U; i < NumberOfCb; i++)
         {
            CbIdx = Dem_CbkLookupTableTriggerOnError[StartIdx + i].CallbackIdx;
            /* notify application that error entry was done,
             * return value is not evaluated -> error handling has to be done
             * by application */
            (void)Dem_CbkFuncPtrTriggerOnError[CbIdx](
               Dem_GbiDTC(EventId),
               Timestamp);
         }
      }
   }
#endif
}

FUNC(void, DEM_CODE) Dem_RteClearEventAllowed(
   const Dem_EventIdType                         EventId,
   CONSTP2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) Allowed)
{
#if (   (DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE == 0U) \
     && (DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE == 0U))
   DEM_PARAM_UNUSED(EventId);
   DEM_PARAM_UNUSED(Allowed);
#else
   Std_ReturnType RetVal = E_NOT_OK;
   uint16 CbIdx = 0U;
#endif

#if (DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE > 0U)
   if (Dem_GbiClrEvAllowedRteUseage(EventId) != FALSE)
   {
      Rte_PortHandle_CallbackClearEventAllowed_R clearEvtAllowedCBPorts =
         Rte_Ports_CallbackClearEventAllowed_R();

      CbIdx = 0U;
      while (   (CbIdx < DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE)
             && (Dem_RteLookupTableClrEvAllowed[CbIdx] != EventId))
      {
         CbIdx++;
      }

      if (CbIdx < DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE)
      {
         /* ask application if entry clearance is allowed */
         RetVal = clearEvtAllowedCBPorts[CbIdx].Call_ClearEventAllowed(Allowed);
      }
   }
#endif

#if (DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE > 0U)
   if (Dem_GbiClrEvAllowedCCallback(EventId) != FALSE)
   {
      CbIdx = 0U;
      while (   (CbIdx < DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE)
             && (Dem_CbkLookupTableClrEvAllowed[CbIdx].EventId != EventId))
      {
         CbIdx++;
      }

      if (CbIdx < DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE)
      {
#if (DEM_C_CALLBACK_TABLE_CLR_EV_ALLOWED_SIZE != 0U)
         CbIdx = Dem_CbkLookupTableClrEvAllowed[CbIdx].CallbackIdx;
         RetVal = Dem_CbkFuncPtrClrEvAllowed[CbIdx](EventId, Allowed);
#else
         RetVal = Dem_CbkLookupTableClrEvAllowed[CbIdx].Function(EventId,
                                                                 Allowed);
#endif
      }
   }
#endif

   /* basicly allow clearance of events */
#if (   (DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE != 0U) \
     || (DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE != 0U))
   if (RetVal != E_OK)
#endif
   {
      *Allowed = TRUE;
   }
}


/*==================[internal function definitions]=========================*/

_STATIC_ FUNC(void, DEM_CODE) Dem_EntryDataCopy(
   CONSTP2CONST(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) FromEntryData,
   CONSTP2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT)   IntoEntryData,
   Dem_SizeEntryDataType                                      Number)
{
   while (Number > 0U)
   {
      --Number;

      /* copy from one entry data into another entry data buffer backwards */
      IntoEntryData[Number] = FromEntryData[Number];
   }
}

_STATIC_ FUNC(void, DEM_CODE) Dem_StoreImmediately(
   const uint8                  originIdx,
   const Dem_SizeEvMemEntryType entryIdx)
{
   /* sizes of the gate entry data */
   const Dem_SizeEntryDataType SizeGateEntryData[DEM_MAXNUM_ORIGINS] =
   {
      DEM_SIZE_GATE_ENTRY_DATA_PRIMARY,
      DEM_SIZE_GATE_ENTRY_DATA_SECONDARY,
      DEM_SIZE_GATE_ENTRY_DATA_MIRROR
   };
   CONSTP2VAR(Dem_GateEntryBaseType, AUTOMATIC, DEM_VAR_NOINIT) GateEntryBase
      = Dem_NvGateEntryData[originIdx];
   CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR_NOINIT) EvMemEntry
      = &Dem_EventMem[originIdx][entryIdx];

   const NvM_BlockIdType NvDataBlockId = Dem_NvDataBlockId[originIdx];
   Std_ReturnType writeBlockRes;

   /* transfer event memory entry into gate-entry */

   const Dem_EventIdType EvId = EvMemEntry->EventId;

   Dem_SizeEntryDataType sizeWrittenEntryData = Dem_SizeOfEntryData(EvId);

   GateEntryBase->EntryBase.EventId = EvId;

   if (EvId != (Dem_EventIdType)DEM_EVENT_ID_INVALID)
   {
      GateEntryBase->EntryBase.OccurrenceCounter =
         EvMemEntry->OccurrenceCounter;

      /* copy event memory entry data into gate-entry data */
      Dem_EntryDataCopy(
         &Dem_EntryData[originIdx][EvMemEntry->EntryDataPos],
         (Dem_EntryDataConstPtrType)Dem_GateEntryData[originIdx],
         sizeWrittenEntryData);
   }
   else /* fill NvGateEntryData[] with zero values for DEM_EVENT_ID_INVALID */
   {
      GateEntryBase->EntryBase.OccurrenceCounter = 0U;

      sizeWrittenEntryData = 0U;
   }

   /* fill remaining GateEntryData[] with zero values */
   while (sizeWrittenEntryData < SizeGateEntryData[originIdx])
   {
      ((Dem_EntryDataConstPtrType) Dem_GateEntryData[originIdx])
                                                [sizeWrittenEntryData] = 0U;

      ++sizeWrittenEntryData;
   }

   /* select corresponding NvRam primary block data */
   NvM_SetDataIndex(NvDataBlockId, (uint8)entryIdx);

   /* queue write command of primary gate-entry to NvM */
   writeBlockRes = NvM_WriteBlock(NvDataBlockId, NULL_PTR);

   /* NvM declined write command for immediate storage */
   if (writeBlockRes != E_OK)
   {
      /* break immediate-storage-loop -> events will be written at shutdown */

      /* mark entry as changed to store it at shutdown */
      EvMemEntry->EntryStatus = DEM_ENTRY_CHANGED;
   }
}

_STATIC_ FUNC(void, DEM_CODE) Dem_StoreImmediatelyNext(
   const uint8 originIdx)
{
   if ((Dem_ShutdownActive == FALSE) || (Dem_ShutdownCancellation != FALSE))
   {
      NvM_RequestResultType reqres = NVM_REQ_NOT_OK;
      const Dem_SizeEvMemEntryType sizeEventMem = Dem_SizeEventMem[originIdx];

      Dem_SizeEvMemEntryType entryIdx;

      NvM_GetErrorStatus(Dem_NvDataBlockId[originIdx], &reqres);

      /*
       * ENTER critical section
       */
      SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

      /* before NvM triggers this callback, a parallel immediate write job can
       * be queued -> break immediate-storage-loop here */
      if (reqres != NVM_REQ_PENDING)
      {
         /* search for next changed entry which shall be stored immediately */
         for (entryIdx = 0U; entryIdx < sizeEventMem; ++entryIdx)
         {
            if (Dem_EventMem[originIdx][entryIdx].EntryStatus ==
                   DEM_ENTRY_STORE_IMMEDIATELY)
            {
               /* entry found */
               break;
            }
         }

         /* changed entry was found */
         if (entryIdx < sizeEventMem)
         {
            Dem_EventMem[originIdx][entryIdx].EntryStatus =
               DEM_ENTRY_NOT_CHANGED;

            /* initiate copying to NvRam */
            Dem_StoreImmediately(originIdx, entryIdx);
         }
         else /* all immediate-storage entries of this event memory are written */
         {
            Dem_LockWhileImmediateStorage[originIdx] = FALSE;
         }
      }

      /*
       * LEAVE critical section
       */
      SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
   }
   else /* Dem_ShutdownActive == TRUE and Dem_ShutdownCancellation == FALSE */
   {
      Dem_LockWhileImmediateStorage[originIdx] = FALSE;
   }
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
