/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp state machine data types and structures.
 **
 ** \file    FrTp_SM.h
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
 * Is used for save memory.
 *
 * MISRA-2) Deviated Rule: 19.7 (required)
 * A function could probably be used instead of this function-like macro.
 *
 * Reason:
 * increase readability of source code. 
 */

#ifndef FRTP_SM_H_
#define FRTP_SM_H_

/* ----------------------------------------------------------------------------
 Include Section
 ---------------------------------------------------------------------------- */

#include "FrTp_Types.h"           /* configuration types */
#include "FrTp_Cfg.h"       /* get FrTp precompile time configuration        */

/* ----------------------------------------------------------------------------
 Global Macros
 ---------------------------------------------------------------------------- */
/**
 * software version check
 * */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif

/*
 * Enforce that the Max Frame Size has at least
 * the size of the frame with the largest header and
 * payload part
 */

#if ((FRTP_HSIZE_FF2B + 1U) > FRTP_PDU_MAXLEN)
#error "FRTP_PDU_MAXLEN must be configured to be at least " (FRTP_HSIZE_FF2B + 1U)
#endif

/*
 * \brief Fills default parameters of a FrTp data frame
 *        (FF, SF, CF)
 *
 * \param fd: FrTp Frame Info Buffer
 * \param dft: FrTp Data Frame Type
 * \param mti: Mas TypeID field
 * \param srctgt: Source/Target address field as tuple
 * \param ds: Number of FrTp payload bytes in this frame
 */
#define FRTP_MK_DF(fd, dft, mti, srctgt, ds)  \
do                                            \
{                                             \
    (fd).FrameType = (dft);                   \
    (fd).MasTypeID = (mti);                   \
    (fd).AddrInfo.Key = (srctgt);             \
    (fd).DataSize = (ds);                     \
} while (0)

/*
 * \brief Fills default parameters of a FrTp flow control frame
 *        (CTS, CREF, ACK, NACK, WT)
 *
 * \param fd: FrTp Frame Info Buffer
 * \param fct: FrTp Flow Control Frame Type
 * \param mti: Mas TypeID field
 * \param src: Source address field
 * \param tgt: Target address field
 */
#define FRTP_MK_FC(fd, fct, mti, src, tgt)    \
do                                            \
{                                             \
    (fd).FrameType = (fct);                   \
    (fd).MasTypeID= (mti);                    \
    (fd).AddrInfo.Addr.Src= (src);            \
    (fd).AddrInfo.Addr.Tgt=(tgt);             \
} while (0)

/*
 * \brief Returns the max number of CF payload bytes using a
 * provided FrTp frame size
 *
 * \param fl: Provided FrTp frame size
 */
/* Deviation MISRA-2 */
#define FRTP_CF_DATA_SIZE(fl) ((fl) - (uint8)FRTP_HSIZE_CF)

/*
 * \brief Returns the max number of SF payload bytes using a
 * provided FrTp frame size
 *
 * \param fl: Provided FrTp frame size
 */
/* Deviation MISRA-2 */
#define FRTP_SF_DATA_SIZE(fl) ((fl) - (uint8)FRTP_HSIZE_SF)

/*
 * \brief Returns the max number of FF payload bytes using a
 * provided FrTp frame size
 *
 * \param fl: Provided FrTp frame size
 * \param len: Total length of the FrTp message
 */
/* Deviation MISRA-2 */
#define FRTP_FF_DATA_SIZE(fl, len) \
 (((len) > FRTP_MAXLEN_FF1B) ? ((fl) - FRTP_HSIZE_FF2B) : ((fl) - FRTP_HSIZE_FF1B))

/**
 *
 *  \brief Determines whether flow control frames will be used
 *
 *  \param  Mas_TI: Mas TypeID field determining the addressing
 *                  mode.
 */
/* Deviation MISRA-2 */
#define FRTP_USEFC(Mas_TI) \
    (((Mas_TI) == 0x01U) ? 1U : 0U)

/*
 * \brief Returns timeout counter for common timeout in provided interface
 *
 * \param Handle: Provided FrTp interface handle
 *                   (if multiple channel is disabled, 0U is used instead)
 *
 */

#define FRTP_TIMEOUTCOMMON FRTP_G_CHNCFG->TimeoutCommon

/*
 * \brief Returns timeout counter for CF/CF timeout in provided interface
 *
 * \param Handle: Provided FrTp interface handle
 *                   (if multiple channel is disabled, 0U is used instead)
 */

#define FRTP_TIMEOUTCFCF FRTP_G_CHNCFG->TimeoutCFCF

/*
 * \brief Returns Buffer Request timeout value set in the interface
 *
 * \param Handle: Provided FrTp interface handle
 *                   (if multiple channel is disabled, 0U is used instead)
 */

#define FRTP_TIMEOUTBUFREQ FRTP_G_CHNCFG->TimeoutBufReq

/*
 * \brief Returns Buffer Request amount
 *
 *                   (if multiple channel is disabled, 0U is used instead)
 */

#define FRTP_COUNTBUFREQ FRTP_G_CHNCFG->MaxBufReq

/*
 * Constants ------------------------------------------------------------------
 */

/*
 * Values of "Reserve" Field in FrTp Frame Info Buffer. The field usually
 * indicates the channel index of the channel it is assigned to
 */
#define FRTP_NOCHANNEL  (254U)  /* Buffer is reserved, not assigned to chn*/
#define FRTP_INVALID    (255U)  /* Buffer is not reserved */

#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
#define FRTP_CHANNEL     aFrTpChannel[lChnIdx]
#define CHNIDX            lChnIdx
#else
#define FRTP_CHANNEL aFrTpChannel[0U]
#define CHNIDX            UINT8_C(0)
#endif

/* ----------------------------------------------------------------------------
 Global Data Types
 ---------------------------------------------------------------------------- */

/*
 * State Machine Function type
 */
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
typedef void (* FrTpSmFunctionType)(VAR(uint8,AUTOMATIC) lChnIdx, P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData);
#else
typedef void (* FrTpSmFunctionType)(P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData);
#endif

/*
 * Events that occur and that are forwarded to FrTp State Machines
 */
typedef enum enum_FrTpSMEventType
{
  FRTPSM_EVT_RX = 0, /* FrTp Frame was received */
  FRTPSM_EVT_TX, /* FrTp Frame was sent */
  FRTPSM_EVT_TASK, /* a communication cycle passed */
  FRTPSM_EVT_TIMEOUT /* a timeout occurred */
} FrTpSMEventType;

/*
 * States for segmented/unsegmented FlexRay Sending
 */
typedef enum enum_FrTpSMTxStatesType
{
  FRTPSM_W4_TX_FFSF = 0, /* Wait for SF/FF Transmission */
  FRTPSM_W4_TX_FFSF_NOTIF, /* Wait for SF/FF Transmission Notification */
  FRTPSM_W4_RX_ACK, /* Wait for ACK Receiption */
  FRTPSM_W4_TX_CF, /* Wait for CF Transmission */
  FRTPSM_W4_TX_CF_NOTIF, /* Wait for CF Transmission Notification */
  FRTPSM_W4_RX_CTS /* Wait for CTS Receiption */
} FrTpSMTxStatesType;

/*
 * States for segmented/unsegmented FlexRay Receiving
 */
typedef enum enum_FrTpSMRxStatesType
{
  FRTPSM_W4_RX_FFSF = 0, /* Wait for FF/SF Receiption */
  FRTPSM_W4_TX_ACK, /* Wait for ACK Transmission */
  FRTPSM_W4_TX_ACK_NOTIF, /* Wait for ACK Transmission Notification */
  FRTPSM_W4_TX_CTS, /* Wait for CTS Transmission */
  FRTPSM_W4_TX_CTS_NOTIF, /* Wait for CTS Transmission Notification */
  FRTPSM_W4_TX_NACK, /* Wait for NACK Transmission */
  FRTPSM_W4_TX_NACK_NOTIF, /* Wait for NACK Transmission Notification */

#if (FRTP_SUPPORT_TXWAIT == STD_ON)
  FRTPSM_W4_TX_WT, /* Wait for WT Transmission */
  FRTPSM_W4_TX_WT_NOTIF, /* Wait for NACK Transmission Notification */
#endif

  FRTPSM_W4_RX_CF /* Wait for CF Receiption */
} FrTpSMRxStatesType;

/*
 * TX/RX state machine types
 */
typedef FrTpSmFunctionType FrTpTxSMType[FRTPSM_EVT_TIMEOUT + 1];
typedef FrTpSmFunctionType FrTpRxSMType[FRTPSM_EVT_TIMEOUT + 1];

/*
 * FrTp Tx Channel State Type
 */
typedef struct struct_FrTpTxChannelStateType {
  P2CONST(FrTpTxSMType,AUTOMATIC, FRTP_CODE) pTxSM;
  /* Points to current state machine */

  VAR(FrTpSizeType,AUTOMATIC) ReadIdx;
  /* Read index */
  VAR(FrTpSizeType,AUTOMATIC) SentBytes;
  /* Number of bytes already sent */

  VAR(FrTpSMTxStatesType,AUTOMATIC) State;
  /* Current TX Frame buffer state */

  VAR(sint16,AUTOMATIC) Timeout;
  /* Timeout Counter */
  VAR(uint16,AUTOMATIC) BufReqTimeout;
  /* Timeout for new tTx Buffer Req */

  VAR(sint8,AUTOMATIC) NextFrameIndex;
  /* Next CF Frame index */

  VAR(sint8,AUTOMATIC) ErrFrameIndex;
  /* Erroneous  CF Frame index */
  VAR(sint8,AUTOMATIC) ErrorCounter;
  VAR(sint8,AUTOMATIC) CFsSinceFC;
  /* Number of CF within block */
  VAR(uint8,AUTOMATIC) CFsWaitCtr;
  /* Number of pending CFs */
  VAR(uint8,AUTOMATIC) CFsCycleWaitCtr;
  /* Cycles to wt for next CF */
  VAR(uint8,AUTOMATIC) LastCFDataBytes;
  /* data bytes of last CF */
  VAR(uint8,AUTOMATIC) WTCounter;
  /* Currently received FC-WTs */
  VAR(uint8,AUTOMATIC) BufReqCounter;
  /* Remaining buffer requests */
} FrTpTxChannelStateType;

/*
 * FrTp Rx Channel State Type
 */
typedef struct struct_FrTpRxChannelStateType {
  P2CONST(FrTpRxSMType,AUTOMATIC,FRTP_CODE) pRxSm;
  /* Points to current state machine */

  VAR(FrTpSizeType,AUTOMATIC) WriteIdx;
  /* Write Index */
  VAR(FrTpSizeType,AUTOMATIC) ReceivedBytes;
  /* Number of bytes already received  */

  VAR(FrTpSMRxStatesType,AUTOMATIC) State;
  /* Current RX Frame buffer state */

  VAR(sint16,AUTOMATIC) Timeout;
  /* Timeout Counter */

  VAR(uint8,AUTOMATIC) ExpectedFrameIndex;
  /* Expected Frame Buffer Index */
  VAR(sint8,AUTOMATIC) ErrFrameIndex;
  /* Frame index indicated as erroneous */
  VAR(sint8,AUTOMATIC) ErrFrameIndexPrevBlock;
  /* Err Frm index in previous block */
  VAR(uint8,AUTOMATIC) LastCFDataBytes;
  /* data bytes of last CF */

  VAR(sint8,AUTOMATIC) ErrorCounter;
  /* Error/Retry counter */
  VAR(sint8,AUTOMATIC) CFsSinceFC;
  /* Number of CF within block */
  VAR(uint8,AUTOMATIC) CFsReceivedSinceFC;
/* indicates whether at least one CF
 * was received after the transmission
 * of a FC Frame */

#if (FRTP_SUPPORT_TXWAIT == STD_ON)
  VAR(uint8,AUTOMATIC) FFBuffer[FRTP_PDU_MAXLEN - FRTP_HSIZE_FF1B]; /* Tmp FF Buffer */
  VAR(uint8,AUTOMATIC) FFBufDataSize; /* Number of bytes in FF Buffer */
  VAR(uint8,AUTOMATIC) WTCtr; /* Remaining FCWTs to send */
  VAR(uint8,AUTOMATIC) WTBufReqCounter;  /* Counter for new Rx Buffer Req */
  VAR(uint16,AUTOMATIC) WTBufReqTimeout;  /* Timeout for new Rx Buffer Req */


#endif

} FrTpRxChannelStateType;

/*
 * Overall FrTp Channel State Type
 */
typedef enum enum_FrTpChannelStateType
{
  FRTP_CHN_FREE = 0, /* FrTp Channel os free to use */
  FRTP_CHN_RX, /* FrTp Channel is occupied in RX mode */
  FRTP_CHN_TX /* FrTp Channel is occupied in TX mode */
} FrTpChannelStateType;

/*
 * FrTp Channel
 */
typedef struct struct_FrTpChannelType {
  P2VAR(PduInfoType,AUTOMATIC,FRTP_APPL_DATA) pBuffer;
  /* Data buf provided by app layer */
  VAR(uint8,AUTOMATIC) PduSize;
  /* Size of Tx PDUs in bytes */
  VAR(uint8,AUTOMATIC) BSMax;
  /* BS Max param used currently */
  VAR(uint8,AUTOMATIC) BC;
  /* Bandwidth control param used curr */

  VAR(uint8,AUTOMATIC) ConIdx;
  /* Connection Index of the corresponding connection */

  VAR(FrTpPDUInfoType,AUTOMATIC) Info;
  /* Contains Src, Tgt address fields,
   * MAS-TypeID field */

  /* Deviation MISRA-1 */
  union /* Either TX or RX state */
  {
    VAR(FrTpRxChannelStateType,AUTOMATIC) Rx;
    VAR(FrTpTxChannelStateType,AUTOMATIC) Tx;
  } Chn;

  VAR(FrTpSizeType,AUTOMATIC) Length;
  /* Length of Tp PDU in bytes */
  VAR(FrTpChannelStateType,AUTOMATIC) State;
  /* Overall channel state */

#if (FRTP_TX_BUFFER_REQUEST_ZERO == STD_ON)
  VAR(PduInfoType,AUTOMATIC) RetryBuffer;
  P2VAR(PduInfoType,AUTOMATIC,FRTP_APPL_DATA) pAppBuffer;

  VAR(FrTpSizeType,AUTOMATIC) nApplBufRemain;
#endif

} FrTpChannelType;

#define FRTP_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

extern VAR(FrTpChannelType,FRTP_VAR) aFrTpChannel[FRTP_CHAN_NUM];

extern VAR(FrTpFrameInfoType,FRTP_VAR) aFrTpFrameInfo[FRTP_PDUINFO_BUFFER_NUM];


#define FRTP_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define FRTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* State Machine states for Unsegmented TX are:
     * FRTPSM_W4_TX_FFSF 
     * FRTPSM_W4_TX_FFSF_NOTIF
     * FRTPSM_W4_RX_ACK */
#define FRTPTXSMUNSEG_STATES_NUM_MAX 3U

/* State Machine states for Segmented TX are:
     * FRTPSM_W4_TX_FFSF 
     * FRTPSM_W4_TX_FFSF_NOTIF
     * FRTPSM_W4_RX_ACK
     * FRTPSM_W4_TX_CF
     * FRTPSM_W4_TX_CF_NOTIF
     * FRTPSM_W4_RX_CTS */
#define FRTPTXSMSEG_STATES_NUM_MAX 6U

extern CONST(FrTpTxSMType,FRTP_APPL_CONST) FrTpTxSMUnseg[FRTPTXSMUNSEG_STATES_NUM_MAX];

extern CONST(FrTpTxSMType,FRTP_APPL_CONST) FrTpTxSMSeg[FRTPTXSMSEG_STATES_NUM_MAX];

#define FRTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif /*FRTP_SM_H_*/
