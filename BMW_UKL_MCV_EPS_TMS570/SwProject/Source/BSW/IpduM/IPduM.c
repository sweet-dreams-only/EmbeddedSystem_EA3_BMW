/**
 * \file
 *
 * \brief Autosar IPduMplex
 *
 * This file contains the implementation of the Autosar
 * module IPduMplex.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2010 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* Manual coverage List
 * List of code lines which are not covered by automatic tests
 * but covered by manual tests including reviews
 *
 * MCOV-1) Prevent race conditions
 *
 * Reason:
 * This part of the code is needed to prevent race conditions. Since it
 * cannot be covered in a deterministic fashion by automated test, it will
 * covered by manual test (i.e., reviews) instead.
 *
 */

/*
 * MISRA-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 14.7 (required)
 * A function shall have a single point of exit at the end of the function.
 *
 * Reason:
 * To reduce indentation-level of code and make it more comprehensible.
 *
 * MISRA-2) Deviated Rule: 11.4 (advisory)
 * A cast should not be performed between a pointer to object type and a
 * different pointer to object type
 *
 * Reason:
 * For post build configuration this type cast is needed.
 *
 * MISRA-3) Deviated Rule: 19.7 (advisory)
 *   A function should be used in preference to a function-like macro.
 *
 *   Reason:
 *   As the function is called very often and consists only of a one line
 *   the macro based implmentation is more run time efficient.
 *
 */


/*==================[inclusions]============================================*/
#include <Std_Types.h>
#include <ComStack_Types.h>
#include <PduR_Ipdum.h>
#include <SchM_IpduM.h>
#include <IpduM_Api.h>
#include <Dem.h>
#include <IpduM_Int.h>

#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
#include <Det.h>               /* Det API */
#endif

/*==================[macros]================================================*/
#if (IPDUM_SCHM_WITH_INSTANCEID == STD_ON)
/* Deviation MISRA-3 */
#define IpduM_SchM_Enter(area) SchM_Enter_IpduM(SCHM_IPDUM_INSTANCE_0, area)
/* Deviation MISRA-3 */
#define IpduM_SchM_Exit(area) SchM_Exit_IpduM(SCHM_IPDUM_INSTANCE_0, area)
#else
/* Deviation MISRA-3 */
#define IpduM_SchM_Enter(area) SchM_Enter_IpduM(area)
/* Deviation MISRA-3 */
#define IpduM_SchM_Exit(area) SchM_Exit_IpduM(area)
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/
#define IPDUM_START_SEC_CODE
#include "MemMap.h"

#if (IPDUM_ZERO_COPY==STD_OFF)
IPDUM_STATIC FUNC(Std_ReturnType, IPDUM_CODE) Ipdum_BitCopy
(
  P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) Dest,
  P2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) Src,
  P2CONST(Ipdum_CopyBitFieldType, AUTOMATIC, IPDUM_APPL_CONST) CopyBitField,
  Ipdum_BitfieldArraySizeType Size
);

IPDUM_STATIC FUNC(Std_ReturnType, IPDUM_CODE) Ipdum_PreparePdu
(
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWay
);
#endif

#if (IPDUM_DYNAMIC_PART_QUEUE==STD_ON)
IPDUM_STATIC FUNC(Std_ReturnType, IPDUM_CODE) Ipdum_InsertQueue
(
  PduIdType PdumTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr,
  uint16 DynamicPriority
);

IPDUM_STATIC FUNC(P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT), IPDUM_CODE) Ipdum_RemoveQueue
(
  Ipdum_TxPathWayIdxType TxPathWayIdx
);

#if (IPDUM_ZERO_COPY==STD_OFF)
IPDUM_STATIC FUNC(void,IPDUM_CODE) Ipdum_SetDynamicPduReadyToSend(PduIdType PdumTxPduId);
#endif

IPDUM_STATIC FUNC(uint16, IPDUM_CODE) Ipdum_GetMaxPriorityQueue(PduIdType PdumTxPduId);
#endif

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/
#define IPDUM_START_SEC_VAR_FAST_8BIT
#include <MemMap.h>

/** \brief Ipdum_InitStatus
 * global variable for the actual initialization status of the Ipdum */
IPDUM_STATIC VAR(Ipdum_StatusType, IPDUM_VAR_FAST) Ipdum_InitStatus = IPDUM_UNINIT;

#define IPDUM_STOP_SEC_VAR_FAST_8BIT
#include <MemMap.h>

#define IPDUM_START_SEC_VAR_FAST_UNSPECIFIED
#include <MemMap.h>

/** \brief Ipdum_ConfigPtr
 * global variable for the config ptr of the Ipdum */
IPDUM_STATIC P2CONST(Ipdum_ConfigType, IPDUM_VAR, IPDUM_APPL_CONST) Ipdum_ConfigPtr = NULL_PTR;

#define IPDUM_STOP_SEC_VAR_FAST_UNSPECIFIED
#include <MemMap.h>

/*==================[external function definitions]=========================*/

#define IPDUM_START_SEC_CODE
#include "MemMap.h"

/*--------------------------------------------------------------------------*/
/* Deviation MISRA-1 */
FUNC(void, IPDUM_CODE) Ipdum_Init
(
  P2CONST(Ipdum_ConfigType, AUTOMATIC, IPDUM_APPL_CONST) Config
)
{
  P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT) TxData;
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWayI;
  uint16 i;

#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
  if (NULL_PTR == Config)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_INIT, IPDUM_E_PARAM);
    return;
  }
  /* Check if IPduMDataMemSize is big enough for the current configuration */
  if (NULL_PTR != Config->TxPathWay)
  {
#if (IPDUM_ZERO_COPY==STD_OFF)
    if ((uint32)(Config->TxPathWay[Config->TxPathWayLen-1U].BufferOffset +
          IPDUM_GET_BYTE_SIZE(Config->TxPathWay[Config->TxPathWayLen-1U].Size)) >
          IPDUM_DATA_MEM_SIZE
       )
#elif (IPDUM_DYNAMIC_PART_QUEUE==STD_ON)
    if (((uint32)(Config->TxPathWay[Config->TxPathWayLen-1U].QueueOffset +
          (Config->TxPathWay[Config->TxPathWayLen-1U].QueueSize * sizeof(Ipdum_QueueEntry)))) >
          IPDUM_DATA_MEM_SIZE
       )
#else
    if ((uint32)(Config->TxPathWayLen*sizeof(Ipdum_TxDataType)) > IPDUM_DATA_MEM_SIZE )
#endif
    {
      IPDUM_DET_REPORT_ERROR(IPDUM_SID_INIT, IPDUM_E_PARAM);
      return;
    }
  }
#endif

  Ipdum_ConfigPtr = Config;

  if (NULL_PTR != Config->TxPathWay)
  {
    /* Deviation MISRA-2 */
    TxData = (P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[Ipdum_ConfigPtr->TxDataOffset]);

    for (i=0; i<IPDUM_TX_PATHWAY_LEN; i++)
    {
      TxPathWayI = &Config->TxPathWay[i];

      if (TxPathWayI->Size > 0)
      {
#if (IPDUM_ZERO_COPY==STD_OFF)
        /* Initialize selector and initial values */
        Ipdum_PreparePdu(TxPathWayI);
#endif
        /* Initialize timeout monitor */
        TxData[i].ConfirmationTimeoutCounter = 0;

        /* First set confirmation id to invalid value */
        TxData[i].PdumDynTxPduId = IPDUM_RESERVED_PDUID;

#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
        /* Initialize queue position */
        TxData[i].QueuePos = 0;
#endif
      }
    }
  }

  /* tag module as initialized */
  Ipdum_InitStatus = IPDUM_INIT;
}
/*--------------------------------------------------------------------------*/
/* Deviation MISRA-1 */
FUNC(void, IPDUM_CODE) Ipdum_RxIndication
(
  PduIdType PdumRxPduId,
  P2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) SduPtr
)
{
  uint8 i;
  uint8 Selector;
#if (IPDUM_ZERO_COPY==STD_OFF)
  uint8 Buffer[IPDUM_RECEIVE_STACK_SIZE];
#else
  Ipdum_BitfieldType Offset;
#endif
  P2CONST(Ipdum_RxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) RxPathWayRI;
  P2CONST(Ipdum_RxPartType, AUTOMATIC, IPDUM_APPL_CONST) RxDynamicPart = NULL_PTR;

#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
  if (IPDUM_INIT != Ipdum_InitStatus)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_RX_INDICATION, IPDUM_E_UNINIT);
    return;
  }
  if (PdumRxPduId >= IPDUM_RX_PATHWAY_LEN)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_RX_INDICATION, IPDUM_E_PARAM);
    return;
  }
  if (NULL_PTR == SduPtr)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_RX_INDICATION, IPDUM_E_PARAM);
    return;
  }
#endif

  /* Get RxPathWay container */
  RxPathWayRI = &Ipdum_ConfigPtr->RxPathWay[PdumRxPduId];

  /* Extract selector */
  Selector = IPDUM_GET_SELECTOR(SduPtr, RxPathWayRI->StartBit, RxPathWayRI->EndBit);

  /* Search for dynamic part */
  i = 0;
  while(i < RxPathWayRI->DynamicPduArraySize)
  {
    if (RxPathWayRI->DynamicPart[i].SelectorValue == Selector)
    {
      /* Found, set RxDynamicPart */
      RxDynamicPart = &RxPathWayRI->DynamicPart[i];
      break;
    }
    i++;
  }

#if (IPDUM_ZERO_COPY==STD_ON)
    /* Static part exists? */
#if (IPDUM_STATIC_PART_EXISTS==STD_ON)
    if (NULL_PTR != RxPathWayRI->StaticPart)
    {
      /* Calculate offset */
      Offset = IPDUM_GET_BYTE_OFFSET(RxPathWayRI->StaticPart->CopyBitField[0].StartBit);

      /* Call rx indication for static part */
      PduR_IpdumRxIndication(RxPathWayRI->StaticPart->OutgoingHandleId, &SduPtr[Offset]);
    }
#endif

  /* Always ensure that the selector is valid */
  if ( NULL_PTR != RxDynamicPart )
  {
    /* Calculate offset */
    Offset = IPDUM_GET_BYTE_OFFSET(RxDynamicPart->CopyBitField[0].StartBit);

    /* Call rx indication for dynamic part */
    PduR_IpdumRxIndication(RxDynamicPart->OutgoingHandleId, &SduPtr[Offset]);
  }
#else /* IPDUM_ZERO_COPY==STD_ON) */
#if (IPDUM_STATIC_PART_EXISTS==STD_ON)
    if (NULL_PTR != RxPathWayRI->StaticPart)
    {
      /* Assemble fragmented static part into temporary buffer */
      Ipdum_BitCopy(Buffer,
        SduPtr,
        RxPathWayRI->StaticPart->CopyBitField,
        RxPathWayRI->StaticPart->CopyBitFieldArraySize);

      /* Call rx indication for static part */
      PduR_IpdumRxIndication(RxPathWayRI->StaticPart->OutgoingHandleId, Buffer);
    }
#endif

  /* Always ensure that the selector is valid */
  if ( NULL_PTR != RxDynamicPart )
  {
    /* Assemble fragmented dynamic part into temporary buffer */
    Ipdum_BitCopy(Buffer,
      SduPtr,
      RxDynamicPart->CopyBitField,
      RxDynamicPart->CopyBitFieldArraySize);

    /* Call rx indication for dynamic part */
    PduR_IpdumRxIndication(RxDynamicPart->OutgoingHandleId, Buffer);
  }
#endif
}
/*--------------------------------------------------------------------------*/
/* Deviation MISRA-1 */
FUNC(Std_ReturnType, IPDUM_CODE) Ipdum_Transmit
(
  PduIdType PdumTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr
)
{
  P2CONST(Ipdum_TxPartType, AUTOMATIC, IPDUM_APPL_CONST) TxPartT;
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWayT;
  P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT) TxData;
  PduIdType PdumDynamicTxPduId = IPDUM_RESERVED_PDUID; /* local storage of PDU Id of dynamic part */
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
  uint16 DynPriority;
  boolean ImmediatelySend = FALSE;
#if (IPDUM_ZERO_COPY==STD_OFF)
  P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT) QueueEntry;
#endif
#endif

#if (IPDUM_ZERO_COPY==STD_OFF)
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR_NOINIT) TxBuffer;
#endif
  Std_ReturnType RetValue = E_OK;

#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
  if (IPDUM_INIT != Ipdum_InitStatus)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TRANSMIT, IPDUM_E_UNINIT);
    return E_NOT_OK;
  }
  if (PdumTxPduId >= Ipdum_ConfigPtr->TxPartLen)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TRANSMIT, IPDUM_E_PARAM);
    return E_NOT_OK;
  }
  if (NULL_PTR == PduInfoPtr)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TRANSMIT, IPDUM_E_PARAM);
    return E_NOT_OK;
  }
#endif

  /* Get TxPartT */
  TxPartT = &Ipdum_ConfigPtr->TxPart[PdumTxPduId];

  /* Deviation MISRA-2 */
  TxData = (P2VAR(Ipdum_TxDataType, IPDUM_VAR, IPDUM_VAR))(&Ipdum_gDataMemPtr[Ipdum_ConfigPtr->TxDataOffset]);

  TxPathWayT = &Ipdum_ConfigPtr->TxPathWay[TxPartT->TxPathWayIdx];

  /* Ignore if the Size of the Path way is zero */
  if (TxPathWayT->Size > 0U)
  {
    IpduM_SchM_Enter(SCHM_IPDUM_EXCLUSIVE_AREA_0);

    /* Check if a transmission is ongoing */
    if (0 == TxData[TxPartT->TxPathWayIdx].ConfirmationTimeoutCounter)
    {
      /* No request pending */

#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
      /* Static or dynamic part */
#if (IPDUM_ZERO_COPY==STD_OFF)
      if (PdumTxPduId < Ipdum_ConfigPtr->TxDynamicPartOffset)
      {
        /* Static */
        if ((TxPathWayT->TriggerMode & IPDUM_TRIGGER_STATIC) == IPDUM_TRIGGER_STATIC)
        {
          /* Trigger condition fulfilled, increase priority for pending dynamic PDUs */
          Ipdum_SetDynamicPduReadyToSend(PdumTxPduId);

          /* Remove entry with highest priority */
          QueueEntry = Ipdum_RemoveQueue(TxPartT->TxPathWayIdx);

          /* Copy only if a dynamic part exists */
          if (NULL_PTR != QueueEntry)
          {
            /* Get pointer to static buffer */
            TxBuffer = &Ipdum_gDataMemPtr[TxPathWayT->BufferOffset];

            /* Assemble dynamic PDU */
            Ipdum_BitCopy(TxBuffer,
              QueueEntry->SduData,
              Ipdum_ConfigPtr->TxPart[QueueEntry->PdumTxPduId].CopyBitField,
              Ipdum_ConfigPtr->TxPart[QueueEntry->PdumTxPduId].CopyBitFieldArraySize);

            /* Store PDU Id for dynamic part (currently retrieved from queue) */
            PdumDynamicTxPduId = QueueEntry->PdumTxPduId;
          }

          /* And mark for immediately sending */
          ImmediatelySend = TRUE;
        }
      }
      else
#endif /* (IPDUM_ZERO_COPY==STD_OFF) */
      {
        /* dynamic part (when IPDUM_ZERO_COPY==STD_ON the must not be a static part) */

        /* Set priority */
        DynPriority = TxPartT->DynamicPriority;

        /* Dynamic triggering condition fulfilled? */
        if ((TxPathWayT->TriggerMode & IPDUM_TRIGGER_DYNAMIC) != IPDUM_TRIGGER_DYNAMIC)
        {
          /* Trigger condition not fulfilled, mark as not to send */
          DynPriority |= IPDUM_PRIO_NOT_READY_TO_SEND;
        }

        /* Check if priority is higher than highest in queue and triggered */
        if ((DynPriority < Ipdum_GetMaxPriorityQueue(PdumTxPduId)) &&
            (DynPriority < IPDUM_PRIO_NOT_READY_TO_SEND))
        {
          /* Priority is higher than in queue, send immediatly */
          ImmediatelySend = TRUE;

          /* Store PDU Id for dynamic part (currently passed via API) */
          PdumDynamicTxPduId = PdumTxPduId;
        }
        else
        {
          /* Priority is lesser than in queue, put into queue */
          RetValue = Ipdum_InsertQueue(PdumTxPduId, PduInfoPtr, DynPriority);
        }
      }
#else /* (IPDUM_DYNAMIC_PART_QUEUE == STD_ON) */
#if (IPDUM_ZERO_COPY==STD_OFF)
      /* dynamic part ? */
      if (PdumTxPduId >= Ipdum_ConfigPtr->TxDynamicPartOffset)
#endif /* (IPDUM_ZERO_COPY==STD_OFF)*/
      /* dynamic part (when IPDUM_ZERO_COPY==STD_ON the must not be a static part) */
      {
        /* Store PDU Id for dynamic part (currently passed via API) */
        PdumDynamicTxPduId = PdumTxPduId;
      }
#endif /* (IPDUM_DYNAMIC_PART_QUEUE == STD_ON) */

#if (IPDUM_ZERO_COPY==STD_OFF)
      /* Get pointer to static buffer */
      TxBuffer = &Ipdum_gDataMemPtr[TxPathWayT->BufferOffset];

      /* Assemble PDU */
      Ipdum_BitCopy(TxBuffer,
        PduInfoPtr->SduDataPtr,
        TxPartT->CopyBitField,
        TxPartT->CopyBitFieldArraySize);
#endif /* (IPDUM_ZERO_COPY==STD_OFF) */

      /* In case we have updated the dynamic part, store the PDU Id for the dynamic PDU */
      if (PdumDynamicTxPduId != IPDUM_RESERVED_PDUID)
      {
        TxData[TxPartT->TxPathWayIdx].PdumDynTxPduId = PdumDynamicTxPduId;
      }

#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
      if (TRUE == ImmediatelySend)
#else /* (IPDUM_DYNAMIC_PART_QUEUE == STD_ON) */
      /* Trigger condition fulfilled? */
      if ( ((PdumTxPduId < Ipdum_ConfigPtr->TxDynamicPartOffset) &&
            ((TxPathWayT->TriggerMode & IPDUM_TRIGGER_STATIC) == IPDUM_TRIGGER_STATIC) ) ||
           ((PdumTxPduId >= Ipdum_ConfigPtr->TxDynamicPartOffset) &&
            ((TxPathWayT->TriggerMode & IPDUM_TRIGGER_DYNAMIC) == IPDUM_TRIGGER_DYNAMIC) )
          )
#endif /* (IPDUM_DYNAMIC_PART_QUEUE == STD_ON) */
      {
        PduInfoType PduInfo;

        /* First store length */
        PduInfo.SduLength = IPDUM_GET_BYTE_SIZE(TxPathWayT->Size);

        /* set timeout counter to special value for ongoing calls to
         * PduR_IpdumTransmit() - will be set to correct timeout value after
         * PduR_IpdumTransmit() has returned */
        TxData[TxPartT->TxPathWayIdx].ConfirmationTimeoutCounter = IPDUM_TRANSMIT_ONGOING;

        /* Set Pdu Info */
#if (IPDUM_ZERO_COPY==STD_OFF)
        PduInfo.SduDataPtr = &TxBuffer[0];

        /* Automatically set selector value */
#if (IPDUM_AUTOMATIC_SELECTOR==STD_ON)
        /* do we have an updated dynamic part? */
        if (PdumDynamicTxPduId != IPDUM_RESERVED_PDUID)
        {
          CONSTP2CONST(Ipdum_TxPartType, AUTOMATIC, IPDUM_APPL_CONST) TxDynamicPart = &Ipdum_ConfigPtr->TxPart[PdumDynamicTxPduId];

          /* set the selector value based on the TxPart config (which is derived based on the PdumTxPduId */
          IPDUM_SET_SELECTOR(PduInfo.SduDataPtr,
            TxDynamicPart->SelectorValue,
            TxPathWayT->StartBit,
            TxPathWayT->EndBit);
        }
#endif /* (IPDUM_AUTOMATIC_SELECTOR==STD_ON) */
#else /* (IPDUM_ZERO_COPY==STD_OFF) */
        /* zero copy - just adjust the data pointer according to the start bit
         * (in the zero copy case only a single CopyBitField is allowed) */
        PduInfo.SduDataPtr = &PduInfoPtr->SduDataPtr[IPDUM_GET_BYTE_OFFSET(TxPartT->CopyBitField[0].StartBit)];
#endif /* (IPDUM_ZERO_COPY==STD_OFF) */

        IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);

        /* Transmit frame */
        if (E_NOT_OK == PduR_IpdumTransmit(TxPartT->TxPathWayIdx+Ipdum_ConfigPtr->TxPathWayOffset,
             &PduInfo))
        {
          /* Transmit failed, report Dem error */
          Dem_ReportErrorStatus(IPDUM_E_TRANSMIT_FAILED, DEM_EVENT_STATUS_FAILED);

          IpduM_SchM_Enter(SCHM_IPDUM_EXCLUSIVE_AREA_0);

          /* Reset confirmation timer so that a new frame can be transmitted */
          TxData[TxPartT->TxPathWayIdx].ConfirmationTimeoutCounter = 0;

          RetValue = E_NOT_OK;
        }
        else
        {
          IpduM_SchM_Enter(SCHM_IPDUM_EXCLUSIVE_AREA_0);
          switch (TxData[TxPartT->TxPathWayIdx].ConfirmationTimeoutCounter)
          {
          case IPDUM_TRANSMIT_ONGOING:
              /* Start timer for timeout monitoring */
              TxData[TxPartT->TxPathWayIdx].ConfirmationTimeoutCounter = TxPathWayT->ConfirmationTimeout;
              break;

          case IPDUM_TRANSMIT_ONGOING_CONFIRMED:
              /* Do not start the time out counting when the transmit of the PDU
               * was confirmed before PduR_IpdumTransmit() has completely finished */
              TxData[TxPartT->TxPathWayIdx].ConfirmationTimeoutCounter = 0;
              break;

          /* all possible cases have been explicitly covered in 'case's above, the 'default'
           * cannot be reached */

          /* CHECK: NOPARSE */
          default:
              break;
          /* CHECK: PARSE */
          }
        }

        /* IpduM_SchM_Exit() follows at the end of the function */
      }
      else
      {
        /* return E_OK */
      }
    }
    else /* Transmission ongoing */
    {
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
      if (PdumTxPduId < Ipdum_ConfigPtr->TxDynamicPartOffset)
      {
        /* Static part, reject */
        RetValue = E_NOT_OK;
      }
      else
      {
        /* Set priority */
        DynPriority = TxPartT->DynamicPriority;

        /* Queue dynamic part */
        if ((TxPathWayT->TriggerMode & IPDUM_TRIGGER_DYNAMIC) != IPDUM_TRIGGER_DYNAMIC)
        {
          /* Trigger condition not fulfilled, mark as not to send */
          DynPriority |= IPDUM_PRIO_NOT_READY_TO_SEND;
        }

        RetValue = Ipdum_InsertQueue(PdumTxPduId, PduInfoPtr, DynPriority);
      }
#else /* (IPDUM_DYNAMIC_PART_QUEUE == STD_ON) */
      RetValue = E_NOT_OK;
#endif /* (IPDUM_DYNAMIC_PART_QUEUE == STD_ON) */
    }

    IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);
  }
  else
  {
    RetValue = E_OK;
  }

  return RetValue;
}
/*--------------------------------------------------------------------------*/
#if (IPDUM_ZERO_COPY==STD_OFF)
/* Deviation MISRA-1 */
FUNC(void, IPDUM_CODE) Ipdum_TriggerTransmit
(
  PduIdType PdumTxPduId,
  P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) SduPtr
)
{
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWay;
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR_NOINIT) Buffer;

#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
  if (IPDUM_INIT != Ipdum_InitStatus)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TRIGGER_TRANSMIT, IPDUM_E_UNINIT);
    return;
  }
  if (NULL_PTR==SduPtr)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TRIGGER_TRANSMIT, IPDUM_E_PARAM);
    return;
  }
  if (PdumTxPduId<Ipdum_ConfigPtr->TxPathWayOffset)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TRIGGER_TRANSMIT, IPDUM_E_PARAM);
    return;
  }
  if (PdumTxPduId >= (Ipdum_ConfigPtr->TxPathWayOffset + Ipdum_ConfigPtr->TxPathWayLen))
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TRIGGER_TRANSMIT, IPDUM_E_PARAM);
    return;
  }
  if ((uint8)IPDUM_TRIGGER_INVALID ==
      Ipdum_ConfigPtr->TxPathWay[PdumTxPduId-Ipdum_ConfigPtr->TxPathWayOffset].TriggerMode)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TRIGGER_TRANSMIT, IPDUM_E_PARAM);
    return;
  }
#endif

  /* Ignore if the Size of the Path way is zero */
  if (Ipdum_ConfigPtr->TxPathWay[PdumTxPduId-Ipdum_ConfigPtr->TxPathWayOffset].Size > 0U)
  {
    TxPathWay = &Ipdum_ConfigPtr->TxPathWay[PdumTxPduId-Ipdum_ConfigPtr->TxPathWayOffset];

    /* Get pointer to internal buffer */
    Buffer = &Ipdum_gDataMemPtr[TxPathWay->BufferOffset];

    IpduM_SchM_Enter(SCHM_IPDUM_EXCLUSIVE_AREA_0);

    /* Copy data to output buffer */
    IPDUM_COPY(SduPtr, Buffer, IPDUM_GET_BYTE_SIZE(TxPathWay->Size));

    IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);
  }
}
#endif
/*--------------------------------------------------------------------------*/
/* Deviation MISRA-1 */
FUNC(void, IPDUM_CODE) Ipdum_TxConfirmation (PduIdType PdumTxPduId)
{
  uint8 i;
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWayC;
  P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT) TxData;
  Ipdum_TxPathWayIdxType PathWayIdx;
  PduIdType TxDynConfirmHandleId = IPDUM_RESERVED_PDUID;

#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
  if (IPDUM_INIT != Ipdum_InitStatus)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TX_CONFIRMATION, IPDUM_E_UNINIT);
    return;
  }
  if (PdumTxPduId<Ipdum_ConfigPtr->TxPathWayOffset)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TX_CONFIRMATION, IPDUM_E_PARAM);
    return;
  }
  if (PdumTxPduId >= (Ipdum_ConfigPtr->TxPathWayOffset + Ipdum_ConfigPtr->TxPathWayLen))
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TX_CONFIRMATION, IPDUM_E_PARAM);
    return;
  }
  if ((uint8)IPDUM_TRIGGER_INVALID ==
      Ipdum_ConfigPtr->TxPathWay[PdumTxPduId-Ipdum_ConfigPtr->TxPathWayOffset].TriggerMode)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_TX_CONFIRMATION, IPDUM_E_PARAM);
    return;
  }
#endif

  /* Ignore if the Size of the Path way is zero */
  if (Ipdum_ConfigPtr->TxPathWay[PdumTxPduId-Ipdum_ConfigPtr->TxPathWayOffset].Size > 0U)
  {
    /* Deviation MISRA-2 */
    TxData = (P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[Ipdum_ConfigPtr->TxDataOffset]);

    PathWayIdx = (Ipdum_TxPathWayIdxType)(PdumTxPduId-Ipdum_ConfigPtr->TxPathWayOffset);

    TxPathWayC = &Ipdum_ConfigPtr->TxPathWay[PathWayIdx];

    IpduM_SchM_Enter(SCHM_IPDUM_EXCLUSIVE_AREA_0);

    /* Check if we are waiting for a confirmation */
    if (TxData[PathWayIdx].ConfirmationTimeoutCounter > 0)
    {
      if(TxData[PathWayIdx].ConfirmationTimeoutCounter==IPDUM_TRANSMIT_ONGOING)
      {
          /* Signal not to start the time out counter, because the PDU is confirmed before the function
           * Ipdum_Transmit() has finished */
          TxData[PathWayIdx].ConfirmationTimeoutCounter = IPDUM_TRANSMIT_ONGOING_CONFIRMED;
      }
      else
      {
          /* Stop timeout counter */
          TxData[PathWayIdx].ConfirmationTimeoutCounter = 0;
      }

      /* search for matching dynamic part */
      i = 0;
      while (i < TxPathWayC->DynamicConfirmArraySize)
      {
        if ((TxPathWayC->TxDynamicConfirmHandleArr[i].TxDynamicConfirmHandleId == TxData[PathWayIdx].PdumDynTxPduId)
            && (IPDUM_RESERVED_PDUID != TxPathWayC->TxDynamicConfirmHandleArr[i].TxDynamicConfirmHandleId))
        {
          /* store handle ID for TxConfirmation of dynamic part for later use */
          TxDynConfirmHandleId = TxPathWayC->TxDynamicConfirmHandleArr[i].TxDynamicConfirmHandleId;

          /* Reset stored ID for confirmation of dynamic part */
          TxData[PathWayIdx].PdumDynTxPduId = IPDUM_RESERVED_PDUID;
          break;
        }
        i++;
      }
      IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);

#if (IPDUM_STATIC_PART_EXISTS==STD_ON)
      /* Call PduR_Ipdum_TxConfirmation for the static part */
      if (IPDUM_RESERVED_PDUID != TxPathWayC->TxStaticConfirmHandleId)
      {
        PduR_IpdumTxConfirmation(TxPathWayC->TxStaticConfirmHandleId);
      }
#endif

      /* do PduR_IpdumTxConfirmation() if we have found a matching dynamic part */
      if (IPDUM_RESERVED_PDUID != TxDynConfirmHandleId)
      {
          /* Call PduR_Ipdum_TxConfirmation for the dynamic part */
        PduR_IpdumTxConfirmation(TxDynConfirmHandleId);
      }
    }
    else
    {
      /* Silently discard unexpected TxConfirmation */
      IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);
    }
  }
}

/*--------------------------------------------------------------------------*/
/* Deviation MISRA-1 */
FUNC(void, IPDUM_CODE) Ipdum_MainFunction (void)
{
  uint8 i;
  P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT) TxData;
#if (IPDUM_DYNAMIC_PART_QUEUE==STD_ON)
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWayMain;
  P2CONST(Ipdum_TxPartType, AUTOMATIC, IPDUM_APPL_CONST) TxPartMain;
#if (IPDUM_ZERO_COPY==STD_OFF)
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR_NOINIT) TxBuffer;
#endif
#endif

  if (IPDUM_INIT != Ipdum_InitStatus)
  {
    return;
  }

  for (i=0; i<IPDUM_TX_PATHWAY_LEN; i++)
  {
    /* Check for valid PduIds */
    if (Ipdum_ConfigPtr->TxPathWay[i].Size > 0)
    {
      /* Deviation MISRA-2 */
      TxData = (P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[Ipdum_ConfigPtr->TxDataOffset]);

      IpduM_SchM_Enter(SCHM_IPDUM_EXCLUSIVE_AREA_0);

      /* Check for pending requests */
      if (TxData[i].ConfirmationTimeoutCounter>=IPDUM_TRANSMIT_ONGOING_CONFIRMED)
      {
        /* the main function just preempted a call to PduR_IpdumTransmit() =>
         * do nothing */
        /* MCOV-1 */
        IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);
      }
      else if (TxData[i].ConfirmationTimeoutCounter>0)
      {
        /* a call to PduR_IpdumTransmit() has completed and we're waiting
         * for the corresponding confirmation */

        /* decrease timer */
        TxData[i].ConfirmationTimeoutCounter--;

        IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);
      }
#if (IPDUM_DYNAMIC_PART_QUEUE!=STD_ON)
      else
      {
        IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);
      }
#else /* (IPDUM_DYNAMIC_PART_QUEUE!=STD_ON) */
      else
      {
        P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT) QueueEntry;

        /* Get entry with highest priority */
        QueueEntry = Ipdum_RemoveQueue(i);

        if (NULL_PTR != QueueEntry)
        {
          PduInfoType PduInfo;
          Std_ReturnType RetValue;
#if (IPDUM_ZERO_COPY==STD_ON)
          uint8 SduDataBuffer[IPDUM_TX_SDU_SIZE];
#endif

          /* Get pointer of TxPathWay */
          TxPathWayMain = &Ipdum_ConfigPtr->TxPathWay[i];

          /* set timeout counter to special value for ongoing calls to
           * PduR_IpdumTransmit() - will be set to correct timeout value after
           * PduR_IpdumTransmit() has returned */
          TxData[i].ConfirmationTimeoutCounter = IPDUM_TRANSMIT_ONGOING;

          /* Set Pdu Info */
          PduInfo.SduLength = IPDUM_GET_BYTE_SIZE(TxPathWayMain->Size);

          /* TxPathWay is the same, but TxPartMain may have been changed */
          TxPartMain = &Ipdum_ConfigPtr->TxPart[QueueEntry->PdumTxPduId];

#if (IPDUM_ZERO_COPY==STD_OFF)
          /* Get pointer to static buffer */
          TxBuffer = &Ipdum_gDataMemPtr[TxPathWayMain->BufferOffset];

          /* Assemble PDU */
          Ipdum_BitCopy(TxBuffer,
            QueueEntry->SduData,
            TxPartMain->CopyBitField,
            TxPartMain->CopyBitFieldArraySize);

          /* Set Pdu Info */
          PduInfo.SduDataPtr = &TxBuffer[0];

          /* Automatically set selector value */
#if (IPDUM_AUTOMATIC_SELECTOR==STD_ON)
          IPDUM_SET_SELECTOR(PduInfo.SduDataPtr,
            TxPartMain->SelectorValue,
            TxPathWayMain->StartBit,
            TxPathWayMain->EndBit);
#endif
#else /* (IPDUM_ZERO_COPY==STD_OFF) */
          /* copy data from queue element to local buffer, since after we've
           * left the critical section another IpduM_Transmit() or the
           * IpduM_MainFunction() might preempt us and modify the queue
           * adjust the source data pointer according to the start bit
           * (in the zero copy case only a single CopyBitField is allowed) */
          IPDUM_COPY(SduDataBuffer, &QueueEntry->SduData[IPDUM_GET_BYTE_OFFSET(TxPartMain->CopyBitField[0].StartBit)], PduInfo.SduLength);

          /* Set Pdu Info */
          PduInfo.SduDataPtr = SduDataBuffer;
#endif /* (IPDUM_ZERO_COPY==STD_OFF) */

          /* Store selector value for dynamic PDU */
          TxData[TxPartMain->TxPathWayIdx].PdumDynTxPduId = QueueEntry->PdumTxPduId;

          IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);

          /* Transmit frame */
          RetValue = PduR_IpdumTransmit(
            i+Ipdum_ConfigPtr->TxPathWayOffset,
            &PduInfo
            );

          /* Transmit failed, report Dem error */
          if (E_NOT_OK == RetValue)
          {
            Dem_ReportErrorStatus(IPDUM_E_TRANSMIT_FAILED, DEM_EVENT_STATUS_FAILED);
            /* Reset conf. timer so that other frames can be transmitted */
            IpduM_AtomicAssign16(TxData[i].ConfirmationTimeoutCounter, 0);
          }
          else
          {
            /* Start timer for timeout surveillance */
            IpduM_AtomicAssign16(TxData[i].ConfirmationTimeoutCounter, TxPathWayMain->ConfirmationTimeout);
          }
        }
        else /* (NULL_PTR != QueueEntry) */
        {
          IpduM_SchM_Exit(SCHM_IPDUM_EXCLUSIVE_AREA_0);
        }
      }
#endif /* (IPDUM_DYNAMIC_PART_QUEUE!=STD_ON) */
    }
  }
}
/*--------------------------------------------------------------------------*/
#if (IPDUM_VERSION_INFO_API==STD_ON)
/* Deviation MISRA-1 */
FUNC(void, IPDUM_CODE) Ipdum_GetVersionInfo
(
  CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, IPDUM_APPL_DATA) VersionInfoPtr
)
{
#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
  if (NULL_PTR==VersionInfoPtr)
  {
    IPDUM_DET_REPORT_ERROR(IPDUM_SID_GET_VERSION_INFO, IPDUM_E_PARAM);
    return;
  }
#endif

  VersionInfoPtr->vendorID         = IPDUM_VENDOR_ID;
  VersionInfoPtr->moduleID         = IPDUM_MODULE_ID;
#if (IPDUM_AUTOSAR_VERSION != 21)
  VersionInfoPtr->instanceID       = IPDUM_INSTANCE_ID;
#endif
  VersionInfoPtr->sw_major_version = IPDUM_SW_MAJOR_VERSION;
  VersionInfoPtr->sw_minor_version = IPDUM_SW_MINOR_VERSION;
  VersionInfoPtr->sw_patch_version = IPDUM_SW_PATCH_VERSION;

  return;
}
#endif

/*--------------------------------------------------------------------------*/

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

#define IPDUM_START_SEC_CODE
#include "MemMap.h"

#if (IPDUM_ZERO_COPY==STD_OFF)
IPDUM_STATIC FUNC(Std_ReturnType, IPDUM_CODE) Ipdum_BitCopy
(
  P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) Dest,
  P2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) Src,
  P2CONST(Ipdum_CopyBitFieldType, AUTOMATIC, IPDUM_APPL_CONST) CopyBitField,
  Ipdum_BitfieldArraySizeType Size
)
{
  Ipdum_BitfieldArraySizeType i;

  for (i=0; i<Size; i++)
  {
#if (IPDUM_BYTE_COPY==STD_ON)
    uint8 SrcOffset = IPDUM_GET_BYTE_OFFSET(CopyBitField[i].StartBit);
    uint8 DstOffset = IPDUM_GET_BYTE_OFFSET(CopyBitField[i].DestinationBit);
    uint8 Length = IPDUM_GET_BYTE_SIZE(CopyBitField[i].EndBit-CopyBitField[i].StartBit);

    /* Copy data bytewise */
    IPDUM_COPY(&Dest[DstOffset], &Src[SrcOffset], Length);
#else
    uint16 j;
    uint16 Length = CopyBitField[i].EndBit-CopyBitField[i].StartBit;

    /* Copy data bitwise */
    for (j=0; j<=Length; j++)
    {
      /* Src and Dst offset in bytes */
      uint8 SrcOffset = (uint8)((uint16)(CopyBitField[i].StartBit+j)>>3U);
      uint8 DstOffset = (uint8)((uint16)(CopyBitField[i].DestinationBit+j)>>3U);

      /* First clear bit, because destination can be initialized with any value */
      Dest[DstOffset] &= (uint8)(~(1U<<
                          (IPDUM_MODULO_8((uint16)(CopyBitField[i].DestinationBit+j)))));

      /* Set bit */
      Dest[DstOffset] |= ((uint8)(Src[SrcOffset]>>
                          (IPDUM_MODULO_8((uint16)(CopyBitField[i].StartBit+j))))&1U) <<
                          (IPDUM_MODULO_8((uint16)(CopyBitField[i].DestinationBit+j)));
    }
#endif
  }
  return E_OK;
}
#endif

/*--------------------------------------------------------------------------*/
#if (IPDUM_ZERO_COPY==STD_OFF)
IPDUM_STATIC FUNC(Std_ReturnType, IPDUM_CODE) Ipdum_PreparePdu
(
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWay
)
{
  uint8 i;
  uint8 Size;
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR_NOINIT) Buffer;

  Buffer = &Ipdum_gDataMemPtr[TxPathWay->BufferOffset];

  /* Convert from bits to bytes */
  Size = IPDUM_GET_BYTE_SIZE(TxPathWay->Size);

  /* set default values */
  for (i=0; i<Size; i++)
  {
    Buffer[i] = TxPathWay->UnusedAreasDefault;
  }

  return E_OK;
}
#endif

#if (IPDUM_DYNAMIC_PART_QUEUE==STD_ON)
/*--------------------------------------------------------------------------*/
IPDUM_STATIC FUNC(Std_ReturnType, IPDUM_CODE) Ipdum_InsertQueue
(
  PduIdType PdumTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr,
  uint16 DynamicPriority
)
{
  uint8 i;
  Ipdum_QueueEntry key;
  P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT) Queue;
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR_NOINIT) QueuePosition;
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWayIQ;
  P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT) TxData;
  Std_ReturnType RetValue = E_OK;

  /* Get TxPathWay */
  TxPathWayIQ = &Ipdum_ConfigPtr->TxPathWay[Ipdum_ConfigPtr->TxPart[PdumTxPduId].TxPathWayIdx];

  /* Get TxData */
  /* Deviation MISRA-2 */
  TxData = (P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[Ipdum_ConfigPtr->TxDataOffset]);

  /* Get start address of queue for this Pdu */
  /* Deviation MISRA-2 */
  Queue = (P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[TxPathWayIQ->QueueOffset]);

  /* Get Queue position */
  QueuePosition = &TxData[Ipdum_ConfigPtr->TxPart[PdumTxPduId].TxPathWayIdx].QueuePos;

  /* First check if PDU is already queued */
  for (i=0; i<(*QueuePosition); i++)
  {
    if (Queue[i].PdumTxPduId == PdumTxPduId)
    {
      RetValue = E_NOT_OK;
    }
  }

  if (E_OK == RetValue)
  {
    if ((*QueuePosition) >= TxPathWayIQ->QueueSize)
    {
      /* Queue full, check if priority is higher than job with lowest priority */
      if ( DynamicPriority < Queue[0].DynamicPriority )
      {
        /* Priority is higher, overwrite lowest priority job */
        Queue[0].PdumTxPduId = PdumTxPduId;
        IPDUM_COPY(Queue[0].SduData, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
        Queue[0].DynamicPriority = DynamicPriority;

        /* Sort queue */
        i=0;
        while(((i+1)<TxPathWayIQ->QueueSize) && (Queue[i].DynamicPriority<Queue[i+1].DynamicPriority))
        {
          /* Swap entries */
          key = Queue[i];
          Queue[i] = Queue[i+1];
          Queue[i+1] = key;
          i++;
        }
      }
      else
      {
        /* Priority is lower, job cannot be queued */
        RetValue = E_NOT_OK;
      }
    }
    else
    {
      /* Queue not full, insert entry */
      Queue[(*QueuePosition)].PdumTxPduId = PdumTxPduId;
      IPDUM_COPY(Queue[(*QueuePosition)].SduData, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
      Queue[(*QueuePosition)].DynamicPriority = DynamicPriority;

      /* Sort queue according to priority */
      i=(*QueuePosition);
      while((i>0) && (Queue[i].DynamicPriority>=Queue[i-1].DynamicPriority))
      {
        /* Swap entries */
        key = Queue[i];
        Queue[i] = Queue[i-1];
        Queue[i-1] = key;
        i--;
      }
      /* Set position to next free element */
      (*QueuePosition)++;
    }
  }
  return RetValue;
}

/*--------------------------------------------------------------------------*/
IPDUM_STATIC FUNC(P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT), IPDUM_CODE) Ipdum_RemoveQueue
(
  Ipdum_TxPathWayIdxType TxPathWayIdx
)
{
  P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT) Queue;
  P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT) NextEntry;
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR_NOINIT) QueuePosition;
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWayRQ;
  P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT) TxData;

  /* Get TxPathWay */
  TxPathWayRQ = &Ipdum_ConfigPtr->TxPathWay[TxPathWayIdx];

  /* Get TxData */
  /* Deviation MISRA-2 */
  TxData = (P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[Ipdum_ConfigPtr->TxDataOffset]);

  /* Get start address of queue for this PDU */
  /* Deviation MISRA-2 */
  Queue = (P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[TxPathWayRQ->QueueOffset]);

  /* Get start address of queue for this PDU */
  QueuePosition = &TxData[TxPathWayIdx].QueuePos;

  if ( (*(QueuePosition) > 0) &&
       ((Queue[(*QueuePosition)-1U].DynamicPriority&IPDUM_PRIO_NOT_READY_TO_SEND)!=IPDUM_PRIO_NOT_READY_TO_SEND)
     )
  {
    /* Return job with highest priority */
    NextEntry = &Queue[(*QueuePosition)-1U];

    /* Remove element */
    (*QueuePosition)--;
  }
  else
  {
    NextEntry = NULL_PTR;
  }
  return NextEntry;
}

/*--------------------------------------------------------------------------*/
#if (IPDUM_ZERO_COPY==STD_OFF)
IPDUM_STATIC FUNC(void, IPDUM_CODE) Ipdum_SetDynamicPduReadyToSend(PduIdType PdumTxPduId)
{
  uint8 i;
  P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT) Queue;
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR_NOINIT) QueuePos;
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWay;
  P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT) TxData;

  /* Get TxPathWay */
  TxPathWay = &Ipdum_ConfigPtr->TxPathWay[Ipdum_ConfigPtr->TxPart[PdumTxPduId].TxPathWayIdx];

  /* Get TxData */
  /* Deviation MISRA-2 */
  TxData = (P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[Ipdum_ConfigPtr->TxDataOffset]);

  /* Get start address of queue for this PDU */
  /* Deviation MISRA-2 */
  Queue = (P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[TxPathWay->QueueOffset]);

  /* Get Queue position */
  QueuePos = &TxData[Ipdum_ConfigPtr->TxPart[PdumTxPduId].TxPathWayIdx].QueuePos;

  /* Set PDU to ready for send */
  for(i=0; i<(*QueuePos);i++)
  {
    Queue[i].DynamicPriority &= (uint16)(~IPDUM_PRIO_NOT_READY_TO_SEND);
  }
}
#endif
/*--------------------------------------------------------------------------*/
IPDUM_STATIC FUNC(uint16, IPDUM_CODE) Ipdum_GetMaxPriorityQueue(PduIdType PdumTxPduId)
{
  uint8 QueuePosition;
  P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT) Queue;
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWayGM;
  P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT) TxData;
  uint16 Priority=IPDUM_PRIO_LOWEST_POSSIBLE;

  /* Get TxPathWay */
  TxPathWayGM = &Ipdum_ConfigPtr->TxPathWay[Ipdum_ConfigPtr->TxPart[PdumTxPduId].TxPathWayIdx];

  /* Get TxData */
  /* Deviation MISRA-2 */
  TxData = (P2VAR(Ipdum_TxDataType, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[Ipdum_ConfigPtr->TxDataOffset]);

  /* Get start address of queue for this PDU */
  /* Deviation MISRA-2 */
  Queue = (P2VAR(Ipdum_QueueEntry, AUTOMATIC, IPDUM_VAR_NOINIT))(&Ipdum_gDataMemPtr[TxPathWayGM->QueueOffset]);

  /* Get Queue position */
  QueuePosition = TxData[Ipdum_ConfigPtr->TxPart[PdumTxPduId].TxPathWayIdx].QueuePos;

  if (QueuePosition > 0)
  {
      Priority = Queue[QueuePosition - 1].DynamicPriority;
  }
  return Priority;
}

#endif

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[end of file]===========================================*/
