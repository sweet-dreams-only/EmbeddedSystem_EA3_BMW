


/* --------{ EB Automotive C Source File }-------- */

/* This file contains all PostBuild configurations of the AUTOSAR module IpduM that
   are target independent. */

/** \addtogroup IpduM
 ** @{ */
/*==================[inclusions]============================================*/

#include <IpduM_PBCfg.h>
#include <IpduM_Int.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

#define IPDUM_START_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>






/** \brief Array of dynamic part copy bit field structures of IPduMRxPathway with handle id 0 */
IPDUM_STATIC CONST(Ipdum_CopyBitFieldType, IPDUM_APPL_CONST) Ipdum_Rx_DynamicPart_CopyBitField_0[1] =
{
  {
    /* StartBit */
    0U,
    /* EndBit */
    63U,
    /* DestinationBit */
    0U
  },
};
/** \brief Array of dynamic part copy bit field structures of IPduMRxPathway with handle id 1 */
IPDUM_STATIC CONST(Ipdum_CopyBitFieldType, IPDUM_APPL_CONST) Ipdum_Rx_DynamicPart_CopyBitField_1[1] =
{
  {
    /* StartBit */
    0U,
    /* EndBit */
    63U,
    /* DestinationBit */
    0U
  },
};
/** \brief Array of dynamic part copy bit field structures of IPduMRxPathway with handle id 2 */
IPDUM_STATIC CONST(Ipdum_CopyBitFieldType, IPDUM_APPL_CONST) Ipdum_Rx_DynamicPart_CopyBitField_2[1] =
{
  {
    /* StartBit */
    0U,
    /* EndBit */
    63U,
    /* DestinationBit */
    0U
  },
};
/** \brief Array of dynamic part structures of IPduMRxPathway with handle id 0 */
IPDUM_STATIC CONST(Ipdum_RxPartType, IPDUM_APPL_CONST) Ipdum_Rx_DynamicPart_0[1] =
{
  {
    /* CopyBitField */
    &Ipdum_Rx_DynamicPart_CopyBitField_0[0],
    /* OutgoingHandleId */
    0U,
    /* CopyBitFieldArraySize */
    1U,
    /* SelectorValue */
    1U
  },
};
/** \brief Array of dynamic part structures of IPduMRxPathway with handle id 1 */
IPDUM_STATIC CONST(Ipdum_RxPartType, IPDUM_APPL_CONST) Ipdum_Rx_DynamicPart_1[1] =
{
  {
    /* CopyBitField */
    &Ipdum_Rx_DynamicPart_CopyBitField_1[0],
    /* OutgoingHandleId */
    1U,
    /* CopyBitFieldArraySize */
    1U,
    /* SelectorValue */
    1U
  },
};
/** \brief Array of dynamic part structures of IPduMRxPathway with handle id 2 */
IPDUM_STATIC CONST(Ipdum_RxPartType, IPDUM_APPL_CONST) Ipdum_Rx_DynamicPart_2[1] =
{
  {
    /* CopyBitField */
    &Ipdum_Rx_DynamicPart_CopyBitField_2[0],
    /* OutgoingHandleId */
    2U,
    /* CopyBitFieldArraySize */
    1U,
    /* SelectorValue */
    1U
  },
};












/** \brief Array of receive pathway structures */
IPDUM_STATIC CONST(Ipdum_RxPathWayType, IPDUM_APPL_CONST) Ipdum_RxPathWay[3] =
{
  {
    #if (IPDUM_STATIC_PART_EXISTS==STD_ON)
      NULL_PTR,
    #endif
    /* DynamicPart */
    Ipdum_Rx_DynamicPart_0,
    /* DynamicPduArraySize */
    1U,
    /* StartBit */
    0U,
    /* EndBit */
    7U,
  },
  {
    #if (IPDUM_STATIC_PART_EXISTS==STD_ON)
      NULL_PTR,
    #endif
    /* DynamicPart */
    Ipdum_Rx_DynamicPart_1,
    /* DynamicPduArraySize */
    1U,
    /* StartBit */
    0U,
    /* EndBit */
    7U,
  },
  {
    #if (IPDUM_STATIC_PART_EXISTS==STD_ON)
      NULL_PTR,
    #endif
    /* DynamicPart */
    Ipdum_Rx_DynamicPart_2,
    /* DynamicPduArraySize */
    1U,
    /* StartBit */
    0U,
    /* EndBit */
    7U,
  },
};

/*------------------------------Tx------------------------------------------*/


/** \brief Array of configuration information for Copy Bit Field */
IPDUM_STATIC CONST(Ipdum_CopyBitFieldType, IPDUM_APPL_CONST) Ipdum_TxCopyBitField[4] =
{
  {
    /* StartBit */
    0U,
    /* EndBit */
    463U,
    /* DestinationBit */
    0U
  },
  {
    /* StartBit */
    0U,
    /* EndBit */
    463U,
    /* DestinationBit */
    0U
  },
  {
    /* StartBit */
    0U,
    /* EndBit */
    63U,
    /* DestinationBit */
    0U
  },
  {
    /* StartBit */
    0U,
    /* EndBit */
    63U,
    /* DestinationBit */
    0U
  },
};

/** \brief Array of configuration information for Tx Part */
IPDUM_STATIC CONST(Ipdum_TxPartType, IPDUM_APPL_CONST) Ipdum_TxPart[4] =
{
  /* Dynamic part Id: 0*/
  {
    /* CopyBitField */
    &Ipdum_TxCopyBitField[0],
    /* TxPathWayIdx */
    0U,
    /* CopyBitFieldArraySize */
    1U,
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
    /* DynamicPriority */
    0U,
#endif
#if (IPDUM_AUTOMATIC_SELECTOR == STD_ON)
    /* Selector */
    0U,
#endif
  },
  /* Dynamic part Id: 1*/
  {
    /* CopyBitField */
    &Ipdum_TxCopyBitField[1],
    /* TxPathWayIdx */
    0U,
    /* CopyBitFieldArraySize */
    1U,
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
    /* DynamicPriority */
    0U,
#endif
#if (IPDUM_AUTOMATIC_SELECTOR == STD_ON)
    /* Selector */
    0U,
#endif
  },
  /* Dynamic part Id: 2*/
  {
    /* CopyBitField */
    &Ipdum_TxCopyBitField[2],
    /* TxPathWayIdx */
    1U,
    /* CopyBitFieldArraySize */
    1U,
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
    /* DynamicPriority */
    0U,
#endif
#if (IPDUM_AUTOMATIC_SELECTOR == STD_ON)
    /* Selector */
    0U,
#endif
  },
  /* Dynamic part Id: 3*/
  {
    /* CopyBitField */
    &Ipdum_TxCopyBitField[3],
    /* TxPathWayIdx */
    1U,
    /* CopyBitFieldArraySize */
    1U,
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
    /* DynamicPriority */
    0U,
#endif
#if (IPDUM_AUTOMATIC_SELECTOR == STD_ON)
    /* Selector */
    0U,
#endif
  },
};


/** \brief Array of configuration information for Tx Dynamic Confirmation Handle Id
** of outgoing handle id: 0*/
IPDUM_STATIC CONST(Ipdum_TxDynamicConfirmType, IPDUM_APPL_CONST) Ipdum_TxDynConfirmHandleArr_0[2] =
{
  {
    /* TxDynamicHandleId */
    0U,
  },
  {
    /* TxDynamicHandleId */
    1U,
  },
};

/** \brief Array of configuration information for Tx Dynamic Confirmation Handle Id
** of outgoing handle id: 1*/
IPDUM_STATIC CONST(Ipdum_TxDynamicConfirmType, IPDUM_APPL_CONST) Ipdum_TxDynConfirmHandleArr_1[2] =
{
  {
    /* TxDynamicHandleId */
    2U,
  },
  {
    /* TxDynamicHandleId */
    3U,
  },
};

/** \brief Transmit Pathway array */
IPDUM_STATIC CONST(Ipdum_TxPathWayType, IPDUM_APPL_CONST) Ipdum_TxPathWay[2] =
{
  {
    /* TxDynamicConfirmHandleId */
    Ipdum_TxDynConfirmHandleArr_0,
#if (IPDUM_ZERO_COPY == STD_OFF)
    /* BufferOffset */
    ((Ipdum_DataOffsetType)sizeof(Ipdum_TxDataType) * 2U) + ((Ipdum_DataOffsetType)sizeof(Ipdum_QueueEntry) * 0U) + 0U,
#endif
    /* Size */
    464U,
    /* DynamicConfirmArraySize */
    2U,
    /* ConfirmationTimeout */
    5U,
#if (IPDUM_STATIC_PART_EXISTS == STD_ON)
    /* TxStaticConfirmHandleId */
    IPDUM_RESERVED_PDUID,
#endif
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
    /* QueueOffset */
    0U,
#endif
    /* StartBit */
    0U,
    /* EndBit */
    7U,
    /* UnusedAreasDefault */
    0U,
    /* TriggerMode */
    IPDUM_TRIGGER_DYNAMIC,
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
    /* QueueSize */
    0U,
#endif
  },
  {
    /* TxDynamicConfirmHandleId */
    Ipdum_TxDynConfirmHandleArr_1,
#if (IPDUM_ZERO_COPY == STD_OFF)
    /* BufferOffset */
    ((Ipdum_DataOffsetType)sizeof(Ipdum_TxDataType) * 2U) + ((Ipdum_DataOffsetType)sizeof(Ipdum_QueueEntry) * 0U) + 58U,
#endif
    /* Size */
    64U,
    /* DynamicConfirmArraySize */
    2U,
    /* ConfirmationTimeout */
    5U,
#if (IPDUM_STATIC_PART_EXISTS == STD_ON)
    /* TxStaticConfirmHandleId */
    IPDUM_RESERVED_PDUID,
#endif
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
    /* QueueOffset */
    0U,
#endif
    /* StartBit */
    0U,
    /* EndBit */
    7U,
    /* UnusedAreasDefault */
    0U,
    /* TriggerMode */
    IPDUM_TRIGGER_DYNAMIC,
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
    /* QueueSize */
    0U,
#endif
  },
};

#define IPDUM_STOP_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>
/*==================[external constants for IPduMConfig]==================*/
#define IPDUM_START_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/** \brief Configuration structure for IpduM */
CONST(Ipdum_ConfigType, IPDUM_APPL_CONST) IPduMConfig =
{
  /* RxPathWay */
  Ipdum_RxPathWay,
  /* TxPathWay */
  Ipdum_TxPathWay,
  /* TxPart */
  Ipdum_TxPart,
  /* TxPathWayOffset */
  0U,
  /* TxDataOffset */
  0U,
  /* Length of RxPathway array */
  3U,
  /* Length of TxPathway array */
  2U,
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
  /* Length of TxPart array */
  4U,
#endif
  /* TxDynamicPartOffset */
  0U
};

#define IPDUM_STOP_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
