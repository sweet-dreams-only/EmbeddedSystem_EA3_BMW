/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** FrTp internal data types and structures
 **
 ** \file    FrTp_Priv.h
 ** \project BMW FrTp
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** \author  Wolfgang Huber
 ** Copyright 2002-2008 Elektrobit Austria GmbH, http://www.elektrobit.com/
 ** All rights reserved.
 ** This software is the confidential and proprietary information
 ** of Elektrobit ("Confidential Information").
 *
 ** You shall not disclose such Confidential Information
 ** and shall use it only in accordance with the terms and
 ** conditions of the License Agreement you entered into with
 ** Elektrobit.
 **/

/* Misra-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 18.4 (required)
 * "Unions shall not be used."
 *
 * Reason:
 * Is used to save memory.
 *
 * MISRA-2) Deviated Rule: 17.4 (required)
 * Array indexing shall be the only allowed form of pointer arithmetic.
 * 
 * Reason:
 * For the relocatable configuration it is necessary.
 *
 * MISRA-3) Deviated Rule: 19.7 (required)
 * A function could probably be used instead of this function-like macro.
 *
 * Reason:
 * increase readability of source code. 
 */

#ifndef _FRTP_PRIV_H_
#define _FRTP_PRIV_H_

/* ----------------------------------------------------------------------------
 Include Section
 ---------------------------------------------------------------------------- */
#include "FrTp.h"          /* get FrTp types and function prototypes          */
#include "FrTp_Param.h"           /* protocol parameters */
#include "FrTp_Types.h"           /* configuration types */
#include "SchM_FrTp.h"            /* scheduling manager */
#include "FrTp_Cfg.h"       /* get FrTp precompile time configuration        */
#include "FrTp_PBCfg.h"

/* ----------------------------------------------------------------------------
 Global Macros
 ---------------------------------------------------------------------------- */

/**
 * software version check
 * fulfills [FRTP201]
 * */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif

/*
 * BMW FrTp is prepared for relocate-able binary configuration,
 * but this feature is not supported yet.
 */

#if (FRTP_RELOCATABLE_CONFIG != STD_OFF)
  #error  Relocateable binary configuration is not supported.
#endif

/* DET error reporting macros */

/* checking for development error tracer (DET) configuration */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"               /* get development error tracer interface */

/* function-like macro for simplified DET usage - map to Det - API function call */

#define FrTp_Det_ReportError(nInstanceID, nServiceID, nErrorID) \
            Det_ReportError( \
                ((uint16)FRTP_MODULE_ID), \
                ((uint8)(nInstanceID)), \
                ((uint8)(nServiceID)), \
                ((uint8)(nErrorID))) \

#else  /* FRIF_REPORT_TO_DET_ENABLE */

/* function-like macro for simplified DET usage maps to empty statement */
#define FrTp_Det_ReportError(nInstanceID, nServiceID, nErrorID)

#endif   /* FRIF_REPORT_TO_DET_ENABLE */

/**
 * Macro to prevent warnings about unused parameters.
 * Can be used to satisfy misra checkers and compiler.
 * examples:
 * (void) (param);
 * (param) = (param);
 * or leave it blank.
 */
#define FRTP_UNUSED(param) ((param) = (param))

/**
 * Change the size in the PduInfo structure parameter of the FrIf_Transmit call
 * to the exact length of the to be transmitted data (e.g. ISO frame in bigger
 * PDU, last CF, FF in Retry Channel). This minimizes copy operations of FrIf.
 * However this optimization is not fully AUTOSAR Spec. conform (see [1],
 * [FRTP021]).
 */
#define FRTP_OPT_FRIF_TRANSMIT_ACCURATE_SIZE STD_ON

/**
 * Critical section macros: If protection is required feel free to add the
 * corresponding call at FrTp_CriticalSectionEnter and FrTp_CriticalSectionExit
 */
#define FRTP_CRITICAL_SECTION_INSTANCE                              ((uint8)0)
#define FRTP_CRITICAL_SECTION_ID                                    ((uint8)0)

#define FrTp_CriticalSectionEnter() \
        SchM_Enter_FrTp(FRTP_CRITICAL_SECTION_INSTANCE, FRTP_CRITICAL_SECTION_ID)
#define FrTp_CriticalSectionExit() \
        SchM_Exit_FrTp(FRTP_CRITICAL_SECTION_INSTANCE, FRTP_CRITICAL_SECTION_ID)

/* ----------------------------------------------------------------------------
 ** Plattform independent reimplementation of standard library functions     **
 ---------------------------------------------------------------------------- */
/* start code section declaration */
#define FRTP_START_SEC_CODE
#include "MemMap.h"


#if (FRTP_USE_STD_MEMCPY == STD_ON)
#define FrTp_MemCpy memcpy
#else
/**
 * \brief FrTp's own implementation of memcpy
 *
 * \param pDestination  (out) pointer to destination
 * \param pSource       (in)  pointer to source of copy operation
 * \param nBytes        (in)  how many bytes should be copied from
 *                            pSource to pDestination
 * \return pointer to the memory area pDestination
 * \remarks
 * - Max. 64KB can be copied (uint16 type for nBytes)
 * - Simple, byte-oriented copy loop, far from optimal but at least platform
 *   independent
 * - Source and destination pointer are (uint8 *) and not (void *)
 */
FUNC(P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA),FRTP_CODE) FrTp_MemCpy(
    P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) pDestination,
    P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) pSource,
    VAR(uint16,AUTOMATIC) nBytes
);
#endif

/* start code section declaration */
#define FRTP_STOP_SEC_CODE
#include "MemMap.h"

/*
 * Macros used to abstract names
 */

#if FRTP_RELOCATABLE_CONFIG == STD_OFF
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_OFF)
#define FRTP_G_CHNCFG  (&(FRTP_CONFIG_NAME.Channels[0]))
#else
#define FRTP_G_CHNCFG  (&(FRTP_CONFIG_NAME.Channels[lChnIdx]))
#endif

#define FRTP_G_CONCFG  (&(FRTP_CONFIG_NAME.Connections[lConIdx]))
#define FRTP_G_RXCFG   (&(FRTP_CONFIG_NAME.RxPdus[lRxPDUId]))
#define FRTP_G_TXCFG   (&(FRTP_CONFIG_NAME.TxPdus[lTxPDUId]))

#else 

#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_OFF)
/* Deviation MISRA-2 */
#define FRTP_G_CHNCFG  (&(gFrTp_ChnConfigPtr[0]))
#else
/* Deviation MISRA-2 */
#define FRTP_G_CHNCFG  (&(gFrTp_ChnConfigPtr[lChnIdx]))
#endif

/* Deviation MISRA-2 */
#define FRTP_G_CONCFG  (&(gFrTp_ConConfigPtr[lConIdx]))
/* Deviation MISRA-2 */
#define FRTP_G_RXCFG   (&(gFrTp_PDURxConfigPtr[lRxPDUId]))
/* Deviation MISRA-2 */
#define FRTP_G_TXCFG   (&(gFrTp_PDUTxConfigPtr[lTxPDUId]))

#endif

#define FRTP_G_RXDATA  (&(FrTp_PDURxData[lRxPDUId]))
#define FRTP_G_TXDATA  (&(FrTp_PDUTxData[lTxPDUId]))

/**
 * Macro to abstract location of configuration. If the configuration is linked
 * it resides in the const segment of the module. The location of the
 * configuration thus depends on the per compile setting
 * FRTP_RELOCATABLE_CONFIG.
 */
#if (FRTP_RELOCATABLE_CONFIG == STD_ON)
/* Deviation MISRA-3 */
#define CONSTP2CONSTCFG(type) \
    CONSTP2CONST(type, AUTOMATIC, FRTP_APPL_CONST)
#else
/* Deviation MISRA-3 */
#define CONSTP2CONSTCFG(type) \
    CONSTP2CONST(type, AUTOMATIC, FRTP_CONST)
#endif

/*
 * Macros used to abstract local pointer optimization switch for certain
 * platforms.
 */
#if (FRTP_OPT_LOCAL_POINTERS == STD_ON)
#define FRTP_RXDATA  lFrTp_PDURxDataPtr
#define FRTP_TXCFG   lFrTp_PDUTxConfigPtr
#define FRTP_TXDATA  lFrTp_PDUTxDataPtr
#define FRTP_LOCAL_RXDATA \
        CONSTP2VAR(FrTp_PDURxDataType,AUTOMATIC,FRTP_APPL_DATA) lFrTp_PDURxDataPtr = FRTP_G_RXDATA;
#define FRTP_LOCAL_TXCFG \
        CONSTP2CONSTCFG(FrTp_PDUTxConfigType) lFrTp_PDUTxConfigPtr = FRTP_G_TXCFG;
#define FRTP_LOCAL_TXDATA \
        CONSTP2VAR(FrTp_PDUTxDataType,AUTOMATIC,FRTP_APPL_DATA) lFrTp_PDUTxDataPtr = FRTP_G_TXDATA;
#else
#define FRTP_RXDATA  FRTP_G_RXDATA
#define FRTP_TXCFG   FRTP_G_TXCFG
#define FRTP_TXDATA  FRTP_G_TXDATA
#define FRTP_LOCAL_CONCFG
#define FRTP_LOCAL_RXDATA
#define FRTP_LOCAL_TXCFG
#define FRTP_LOCAL_TXDATA
#endif

/* ----------------------------------------------------------------------------
 **                      Global Data Types
 ---------------------------------------------------------------------------- */

typedef uint8 FrTpChannelIndexType; /* FrTp Channel Index */

/*
 * FrTp Frame Types -----------------------------------------------------------
 */
typedef enum enum_FrTpFrameType
{
  /* Data Frames */
  FRTP_SF = 0, /* Single Frame */
  FRTP_FF, /* First Frame */
  FRTP_CF, /* Consecutive Frame */

  /* Flow Control Frames */
  FRTP_FC_CTS, /* Clear To Send Frame */
  FRTP_FC_WT, /* Wait Frame */
  FRTP_FC_CREF, /* Connection Refused Frame */
  FRTP_FC_NACK, /* Negative Acknowledge */
  FRTP_FC_ACK /* Positive Acknowledge */
} FrTpFrameType;

/*
 * FrTpFC: Flow Control Data in a FC-CTS frame --------------------------------
 */

typedef uint16 FrTpSizeType; /* FrTp Datalength field */

typedef uint8 FrTpAddressType; /* FrTp Addressing field */
typedef uint16 FrTpAddressKeyType; /* FrTp Src/Tgt Address Tuple */

/*
 * FrTp Addressing Information (Address-oriented access)
 */
typedef struct struct_FrTpAddressPairType {
  VAR(FrTpAddressType,AUTOMATIC) Tgt; /* Target address */
  VAR(FrTpAddressType,AUTOMATIC) Src; /* Source address */
} FrTpAddressPairType;

/*
 * Unified Addressing Information
 */
/* Deviation MISRA-1 */
typedef union union_FrTpAddressInfoType {
  VAR(FrTpAddressKeyType,AUTOMATIC)  Key; /* Key oriented access */
  VAR(FrTpAddressPairType,AUTOMATIC) Addr; /* Address oriented access */
} FrTpAddressInfoType;

/*
 * FrTp PDU info
 */
typedef struct struct_FrTpPDUInfoType {
  VAR(FrTpAddressInfoType,AUTOMATIC) AddrInfo;  /* Addressing Info */
  VAR(uint8,AUTOMATIC)               MasTypeID; /* MAS-TypeID used for PDU transmission */
} FrTpPDUInfoType;

typedef struct struct_FrTpFC {
  VAR(uint8,AUTOMATIC) BSMax;
  VAR(uint8,AUTOMATIC) BC;
} FrTpFCType;

/*
 * FrTpFrameInfoType is the representation of a FrTp Frame --------------------
 */
typedef struct struct_FrTpFrameInfoType {
/* Deviation MISRA-1 */
  union {
    VAR(FrTpSizeType,AUTOMATIC) Length;     /* SF, FF: data length field */
    VAR(FrTpFCType,AUTOMATIC)   FC;         /* CTS: Block Size, Flow Control */
    VAR(uint8,AUTOMATIC)        FrameIndex; /* CF, NACK: index of CF, Erroneous CF */
  } PCI;

  FrTpAddressInfoType AddrInfo; /* Contains information about Src, Tgt */

  P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) pData; /* points to the first TL frame data byte */
  VAR(uint8,AUTOMATIC)         DataSize;  /* length of payload in pdata SF, FF, CF */
  VAR(uint8,AUTOMATIC)         MasTypeID; /* Message Adress Session Type Identifier */
  VAR(uint8,AUTOMATIC)         Reserve;   /* Used for reservation of buffer */
  VAR(FrTpFrameType,AUTOMATIC) FrameType; /* Indicates the type of TP frame */

} FrTpFrameInfoType;

/**
 * Runtime data of a PDU for reception.
 */
typedef struct struct_FrTp_PDURxDataType {
  P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) BufferPtr;
  /**< Pointer to the part of FrTp_Buffer which belongs to this N-PDU. */
  VAR(boolean,AUTOMATIC) PDUAvail;
/**< flag which indicates that new data is available. */
} FrTp_PDURxDataType;

/**
 * Runtime data of a PDU for transmission.
 */
typedef struct struct_FrTp_PDUTxDataType {
  VAR(PduInfoType,AUTOMATIC) PduInfo;
  /**< Pointer to the part of FrTp_Buffer which belongs to this N-PDU.*/
  P2VAR(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pInfo;
  /**< Pointer to the FrameInfo using this PDU */
  VAR(boolean,AUTOMATIC) Confirmed;
  /**< TxConfirmation has arrived for this N-PDU */
  VAR(uint8,AUTOMATIC) FrIfRetry;
  /**< Numbers of Retry to send it on the FrIf */
  VAR(uint8,AUTOMATIC) FrIfWait4Send;
  /**< Cycles to wait for the next transmission */
} FrTp_PDUTxDataType;

/* ----------------------------------------------------------------------------
 FrTp Private Functions
 ---------------------------------------------------------------------------- */

/* start code section declaration */
#define FRTP_START_SEC_CODE
#include "MemMap.h"
/**
 *
 *    \brief Transmits the content of a schedule entry using
 *           a provided FlexRay identifier.
 *
 *    \param  pHnd: Provided FrTp interface
 *                  (available if multi controller support is enabled)
 *    \param  pEntry: FrTp entry to use for sending
 *
 *
 *    \return
 *       E_OK if the transmission call was successful
 *      E_NOT_OK if the transmission call was not successful
 *
 */
FUNC(Std_ReturnType,FRTP_CODE) FrTp_TransmitPDU(
    VAR(PduIdType,AUTOMATIC) lTxPDUId,
    P2VAR(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pInfo
);
/**
 *
 *    \brief Processes the incoming data of an Rx-PDU.
 *
 *    \param  lRxPDUId: RxPduId
 *
 *    \return (none)
 *
 */

FUNC(void,FRTP_CODE) FrTp_HandleRxData(
    CONST(uint8,AUTOMATIC) lRxPDUId
);

/* start code section declaration */
#define FRTP_STOP_SEC_CODE
#include "MemMap.h"
/* ----------------------------------------------------------------------------
 Global Data
 ---------------------------------------------------------------------------- */
#define FRTP_START_SEC_VAR_8BIT
#include "MemMap.h"
/**
 * IsInitialized is a boolean flag, indicating the initialisation
 * status of the FrTp module.
 */
extern VAR(boolean,FRTP_VAR) FrTp_IsInitialized;

#define FRTP_STOP_SEC_VAR_8BIT
#include "MemMap.h"


#define FRTP_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/**
 * Array to hold the transmission FrIf N-PDUs runtime values
 */
extern VAR(FrTp_PDUTxDataType,FRTP_VAR) FrTp_PDUTxData[FRTP_TX_PDU_NUM];

/**
 * Array to hold the reception FrIf N-PDUs runtime values
 */
extern VAR(FrTp_PDURxDataType,FRTP_VAR) FrTp_PDURxData[FRTP_RX_PDU_NUM];


#define FRTP_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if (FRTP_RELOCATABLE_CONFIG == STD_OFF)
/*
 * If binary relocatable configuration is disabled enabled these variables are
 * linked.
 */
#define FRTP_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONSTP2CONST(FrTp_ChnConfigType,FRTP_CONST,FRTP_CONST) gFrTp_ChnConfigPtr;
extern CONSTP2CONST(FrTp_ConConfigType,FRTP_CONST,FRTP_CONST) gFrTp_ConConfigPtr;
extern CONSTP2CONST(FrTp_PDUTxConfigType,FRTP_CONST,FRTP_CONST) gFrTp_PDUTxConfigPtr;
extern CONSTP2CONST(FrTp_PDURxConfigType,FRTP_CONST,FRTP_CONST) gFrTp_PDURxConfigPtr;
extern CONST(uint8,FRTP_CONST) gFrTpChnNumber;
extern CONST(uint8,FRTP_CONST) gFrTpConNumber;
extern CONST(uint8,FRTP_CONST) gFrTpTxPDUNumber;
extern CONST(uint8,FRTP_CONST) gFrTpRxPDUNumber;

#define FRTP_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#else

#define FRTP_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

extern VAR(uint8,FRTP_VAR) gFrTpChnNumber;
extern VAR(uint8,FRTP_VAR) gFrTpConNumber;
extern VAR(uint8,FRTP_VAR) gFrTpTxPDUNumber;
extern VAR(uint8,FRTP_VAR) gFrTpRxPDUNumber;

#define FRTP_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#endif


#endif /* _FRTP_PRIV_H_ */
