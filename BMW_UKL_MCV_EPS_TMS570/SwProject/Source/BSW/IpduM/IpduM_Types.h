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
#ifndef IPDUM_TYPES_H
#define IPDUM_TYPES_H

/*==================[inclusions]============================================*/

#include <Std_Types.h>          /* AUTOSAR standard types */
#include <ComStack_Types.h>
#include <IpduM_Cfg.h>

/*==================[macros]================================================*/

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined IPDUM_MODULE_ID) /* to prevent double declaration */
#error IPDUM_MODULE_ID already defined
#endif

/** \brief Module Information.
 **
 ** AUTOSAR module identification.
 */
#define IPDUM_MODULE_ID  52U

#if (defined IPDUM_INSTANCE_ID)
#error IPDUM_INSTANCE_ID already defined
#endif
/** \brief Id of instance of IpduM */
#define IPDUM_INSTANCE_ID  0U

/*------------------[macros for error codes]--------------------------------*/

#if (defined IPDUM_E_PARAM) /* to prevent double declaration */
#error IPDUM_E_PARAM already defined
#endif
/** \brief Development Error Code
 **
 ** API service called with wrong parameter.
 */
#define IPDUM_E_PARAM  0x10


#if (defined IPDUM_E_UNINIT) /* to prevent double declaration */
#error IPDUM_E_UNINIT already defined
#endif
/** \brief Development Error Code
 **
 ** API service used without module initialization.
 */
#define IPDUM_E_UNINIT  0x20

/*------------------[macros for service IDs]--------------------------------*/

#if (defined IPDUM_SID_INIT)
#error IPDUM_SID_INIT already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Ipdum_Init.
 */
#define IPDUM_SID_INIT  0x0


#if (defined IPDUM_SID_GET_VERSION_INFO)
#error IPDUM_SID_GET_VERSION_INFO already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Ipdum_GetVersionInfo.
 */
#define IPDUM_SID_GET_VERSION_INFO  0x1


#if (defined IPDUM_SID_RX_INDICATION)
#error IPDUM_SID_RX_INDICATION already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Ipdum_RxIndication.
 */
#define IPDUM_SID_RX_INDICATION  0x2


#if (defined IPDUM_SID_TRANSMIT)
#error IPDUM_SID_TRANSMIT already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Ipdum_Transmit.
 */
#define IPDUM_SID_TRANSMIT  0x3


#if (defined IPDUM_SID_TX_CONFIRMATION)
#error IPDUM_SID_TX_CONFIRMATION already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Ipdum_TxConfirmation.
 */
#define IPDUM_SID_TX_CONFIRMATION  0x4


#if (defined IPDUM_SID_TRIGGER_TRANSMIT)
#error IPDUM_SID_TRIGGER_TRANSMIT already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Ipdum_TriggerTransmit.
 */
#define IPDUM_SID_TRIGGER_TRANSMIT  0x5


#if (defined IPDUM_SID_MAIN_FUNCTION)
#error IPDUM_SID_MAIN_FUNCTION already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Ipdum_MainFunction.
 */
#define IPDUM_SID_MAIN_FUNCTION  0x10

/*------------------[macros for Trigger Mode]-------------------------------*/

/* Trigger modes */
#define IPDUM_TRIGGER_NONE                 0U
#define IPDUM_TRIGGER_STATIC               1U
#define IPDUM_TRIGGER_DYNAMIC              2U
#define IPDUM_TRIGGER_STATIC_OR_DYNAMIC    (IPDUM_TRIGGER_STATIC | IPDUM_TRIGGER_DYNAMIC)
#define IPDUM_TRIGGER_INVALID              (~(0U) & \
                                            (~(IPDUM_TRIGGER_STATIC | \
                                               IPDUM_TRIGGER_DYNAMIC)))

/* Reserved for TxConfirmationId */
#define IPDUM_RESERVED_PDUID               ((PduIdType)0xFFFFU)

/*==================[type definitions]======================================*/

/*------------------[common]------------------------------------------------*/

typedef uint16 Ipdum_BitfieldType;
typedef uint16 Ipdum_BitfieldArraySizeType;

typedef struct
{
  Ipdum_BitfieldType StartBit;
  Ipdum_BitfieldType EndBit;
  Ipdum_BitfieldType DestinationBit;
} Ipdum_CopyBitFieldType;

/* Offset in Bytes in Ipdum_DataMem */
typedef uint16 Ipdum_DataOffsetType;

typedef uint16 Ipdum_TxTimeoutType;

typedef uint16 Ipdum_PathWayLenType;

/*------------------[RxPath]------------------------------------------------*/
typedef struct
{
  P2CONST(Ipdum_CopyBitFieldType, AUTOMATIC, IPDUM_APPL_CONST) CopyBitField;
  PduIdType OutgoingHandleId;
  Ipdum_BitfieldArraySizeType CopyBitFieldArraySize;
  uint8 SelectorValue;
} Ipdum_RxPartType;

typedef struct
{
#if (IPDUM_STATIC_PART_EXISTS==STD_ON)
  P2CONST(Ipdum_RxPartType, AUTOMATIC, IPDUM_APPL_CONST) StaticPart;
#endif
  P2CONST(Ipdum_RxPartType, AUTOMATIC, IPDUM_APPL_CONST) DynamicPart;
  uint16 DynamicPduArraySize;
  Ipdum_BitfieldType StartBit;
  Ipdum_BitfieldType EndBit;
} Ipdum_RxPathWayType;

/*------------------[TxPath]------------------------------------------------*/
typedef uint16 Ipdum_TxPathWayIdxType;
typedef uint16 Ipdum_TxOffsetType;

typedef struct
{
  PduIdType TxDynamicConfirmHandleId;
} Ipdum_TxDynamicConfirmType;

typedef struct
{
  P2CONST(Ipdum_TxDynamicConfirmType, AUTOMATIC, IPDUM_APPL_CONST) TxDynamicConfirmHandleArr;
#if (IPDUM_ZERO_COPY==STD_OFF)
  Ipdum_DataOffsetType BufferOffset;   /* Offset in bytes for first element of TxBuffer */
#endif
  uint16 Size; /* Caution: Size in bits */
  uint16 DynamicConfirmArraySize;
  Ipdum_TxTimeoutType ConfirmationTimeout;
#if (IPDUM_STATIC_PART_EXISTS==STD_ON)
  PduIdType TxStaticConfirmHandleId;
#endif
#if (IPDUM_DYNAMIC_PART_QUEUE==STD_ON)
  Ipdum_DataOffsetType QueueOffset;    /* Offset in bytes for first element in queue */
#endif
  Ipdum_BitfieldType StartBit;
  Ipdum_BitfieldType EndBit;
  uint8 UnusedAreasDefault;
  uint8 TriggerMode;
#if (IPDUM_DYNAMIC_PART_QUEUE==STD_ON)
  uint8 QueueSize;
#endif
} Ipdum_TxPathWayType;

typedef struct
{
  P2CONST(Ipdum_CopyBitFieldType, AUTOMATIC, IPDUM_APPL_CONST) CopyBitField;
  Ipdum_TxPathWayIdxType TxPathWayIdx;
  Ipdum_BitfieldArraySizeType CopyBitFieldArraySize;
#if (IPDUM_DYNAMIC_PART_QUEUE==STD_ON)
  uint8 DynamicPriority;
#endif
#if (IPDUM_AUTOMATIC_SELECTOR==STD_ON)
  uint8 SelectorValue;
#endif
} Ipdum_TxPartType;

/*------------------[Config]------------------------------------------------*/
typedef struct
{
  P2CONST(Ipdum_RxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) RxPathWay;
  P2CONST(Ipdum_TxPathWayType, AUTOMATIC, IPDUM_APPL_CONST) TxPathWay;
  P2CONST(Ipdum_TxPartType, AUTOMATIC, IPDUM_APPL_CONST) TxPart;
  /* Index offset */
  Ipdum_TxOffsetType TxPathWayOffset;
  /* Offset in bytes for first TxData element in Ipdum_DataMem */
  Ipdum_DataOffsetType TxDataOffset;
  /* Length of RxPathway array */
  Ipdum_PathWayLenType RxPathWayLen;
  /* Length of TxPathway array */
  Ipdum_PathWayLenType TxPathWayLen;
#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
  /* Length of TxPart array */
  Ipdum_PathWayLenType TxPartLen;
#endif
  /* Offset for dynamic part */
  Ipdum_TxOffsetType TxDynamicPartOffset;
} Ipdum_ConfigType;

/*------------------[Data]--------------------------------------------------*/
typedef struct
{
  PduIdType PdumTxPduId;
  uint16 DynamicPriority;
  uint8 SduData[IPDUM_TX_SDU_SIZE];
} Ipdum_QueueEntry;

typedef struct
{
  Ipdum_TxTimeoutType ConfirmationTimeoutCounter;
  PduIdType PdumDynTxPduId;
#if (IPDUM_DYNAMIC_PART_QUEUE == STD_ON)
  /* Postion of next free entry in queue */
  uint8 QueuePos;
#endif
} Ipdum_TxDataType;

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_TYPES_H */
/*==================[end of file]===========================================*/
