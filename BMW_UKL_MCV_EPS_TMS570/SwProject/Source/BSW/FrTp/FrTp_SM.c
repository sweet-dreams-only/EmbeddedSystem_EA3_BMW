/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp state machine implementation.
 **
 ** \file    FrTp_SM.c
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

 ** \addtogroup FrTp FlexRay Transport Protocol
 ** @{ */

/*
 * Misra-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 19.10 (advisory)
 * Macro parameter not enclosed in ()
 *
 * Reason:
 * The macro is used to declare a function therefore the name of the 
 * function can not be in parentheses
 *
 * MISRA-2) Deviated Rule: 14.7 (required)
 * Function shall have a single point of exit at the end of the function
 *
 * Reason:
 * return exits are used to increase readability of source code
 *
 * MISRA-3) Deviated Rule: 19.1 (required)
 * #include statements in a file should only be preceded by other preprocessor 
 * directives or comments. 
 *
 * Reason:
 * It is needed to include the MemMap.h file after code section declaration. 
 *
 * MISRA-4) Deviated Rule: 19.7 (required)
 * A function could probably be used instead of this function-like macro.
 *
 * Reason:
 * increase readability of source code. 
 *
 * MISRA-5) Deviated Rule: 8.7 (required)
 * Objects shall be defined at block scope if they are only accessed from within a single function.
 *
 * Reason:
 * moving to the function will be raise stack size and a static function variable is not possible due to nested MemMap.h
 */


/* ----------------------------------------------------------------------------
 Include Section
 ---------------------------------------------------------------------------- */

#include "FrTp_Priv.h"      /* get FrTp private data                         */
#include "FrTp_SM.h"        /* get FrTp state machine data types             */
#include "PduR_FrTp.h"      /* Pdu Router Interface functions                */

/* ----------------------------------------------------------------------------
 Local Macros
 ---------------------------------------------------------------------------- */
/**
 * software version check
 */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif
/*
 * Value used in ErrFrameIndex that a CREF shall be sent instead of a NACK
 */

#define FRTP_BS_CREF (FRTP_BS_MAX+2)

/*
 * Macros ---------------------------------------------------------------------
 */

/* Deviation MISRA-4 */
#define FRTP_MAX(x,y) (((x) > (y)) ? (x) : (y))
/* Deviation MISRA-4 */
#define FRTP_MIN(x,y) (((x) < (y)) ? (x) : (y))

/**
 *
 *  \brief Calculates next CF sequence number
 *
 *  \param  oldsn: Previous sequence number
 */
/* Deviation MISRA-4 */
#define FRTP_NEXTSN(oldsn) (((oldsn) >= FRTP_BS_MAX) ? 0 : ((oldsn) + 1))

/**
 *
 *  \brief Calculates previous CF sequence number
 *
 *  \param  sn: Current sequence number
 */
/* Deviation MISRA-4 */
#define FRTP_PREVSN(sn)    (((sn) > 0) ? ((sn) - 1) : FRTP_BS_MAX)

/**
 *
 *  \brief Calculates rollback in bytes after FC-NACK was
 *   received.
 *
 *  \param  CFs: Number of CFs that must be rolled back
 *  \param  CFBytes: Amount of a "full" CF  in bytes
 *  \param  LastFCBytes: Amount of last CF
 */
/* Deviation MISRA-4 */
#define FRTP_ROLLBACK(CFs, CFBytes, LastCFBytes)        \
            (((LastCFBytes) != 0) ?                              \
                ((LastCFBytes) + (((CFs) - 1) * (CFBytes))) : \
                ((CFs) * (CFBytes)))
/**
 *
 *  \brief Calculates the number of CFs to retransmit
 *
 *  \param  snPrev: Sequence number of most recently sent CF
 *  \param  snErr: Sequence number of faulty CF
 */
/* Deviation MISRA-4 */
#define FRTP_CFRESENDS(snPrev, snErr)                   \
    (1 + (((snPrev) >= (snErr)) ? ((snPrev) - (snErr)) :        \
       ((1 + FRTP_BS_MAX) - ((snErr) - (snPrev)))))

/**
 *
 *  \brief Releases a FrTp TX channel and notifies the application
 *         layer about the send status
 *
 *  \param  chn: Index of the FrTp channel to release
 *  \param  status: Status to provide to the application layer
 */
#define FRTP_RELTXCHNWITHSTATUS( status )  \
do                                                               \
{                                                                \
     FRTP_CHANNEL.State = FRTP_CHN_FREE;                         \
     PduR_FrTpTxConfirmation(                                    \
            FRTP_CHANNEL.ConIdx,                                 \
            (status));                                           \
} while (0)

/**
 *
 *  \brief Releases a FrTp RX channel and notifies the application
 *         layer about the receive status
 *
 *  \param  chn: Index of the FrTp channel to release
 *  \param  status: Status to provide to the application layer
 */
#define FRTP_RELRXCHNWITHSTATUS( status) \
do                                                               \
{                                                                \
    FRTP_CHANNEL.State = FRTP_CHN_FREE;                          \
    PduR_FrTpRxIndication(                                       \
            gFrTp_ConConfigPtr[FRTP_CHANNEL.ConIdx].RxSDUId,     \
            (status));                                           \
} while (0)

#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
/* Deviation MISRA-1 */
/* Deviation MISRA-4 */
#define FRTP_DECLSMFUNC(name)                                                \
   _STATIC_ FUNC(void,FRTP_CODE) name(                                       \
            VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,                     \
            P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData        \
                                       )
#else
/* Deviation MISRA-1 */
/* Deviation MISRA-4 */
#define FRTP_DECLSMFUNC(name)                                                \
   _STATIC_ FUNC(void,FRTP_CODE) name(                                       \
            P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData        \
                                      )
#endif
/* ----------------------------------------------------------------------------
 Global Data
 ---------------------------------------------------------------------------- */

#define FRTP_START_SEC_VAR_UNSPECIFIED
/* Deviation MISRA-3 */
#include "MemMap.h"

/*
 * RAM Data for the concurrent Channels
 */
VAR(FrTpChannelType,FRTP_VAR) aFrTpChannel[FRTP_CHAN_NUM];

/*
 * Buffer constructing frames
 */

VAR(FrTpFrameInfoType,FRTP_VAR) aFrTpFrameInfo[FRTP_PDUINFO_BUFFER_NUM];


#define FRTP_STOP_SEC_VAR_UNSPECIFIED
/* Deviation MISRA-3 */
#include "MemMap.h"
/* ----------------------------------------------------------------------------
 Local Data
 ---------------------------------------------------------------------------- */

/*
 * FrTp State Machine ---------------------------------------------------------
 */

#define FRTP_START_SEC_CODE
/* Deviation MISRA-3 */
#include "MemMap.h"
/*
 * State Machine functions for Unsegmented TX ---------------------------------
 */

FRTP_DECLSMFUNC(FrTp_Sm_Tx_u_w4_tx_sf);
FRTP_DECLSMFUNC(FrTp_Sm_Tx_u_w4_tx_sf_n);
FRTP_DECLSMFUNC(FrTp_Sm_Tx_u_w4_rx_ack);

/*
 * State Machine functions for Segmented TX -----------------------------------
 */

FRTP_DECLSMFUNC(FrTp_Sm_Tx_s_w4_tx_ff);
FRTP_DECLSMFUNC(FrTp_Sm_Tx_s_w4_tx_ff_n);
FRTP_DECLSMFUNC(FrTp_Sm_Tx_s_w4_rx_cts);
FRTP_DECLSMFUNC(FrTp_Consume_CFs);
FRTP_DECLSMFUNC(FrTp_Sm_Tx_s_w4_tx_cf);
FRTP_DECLSMFUNC(FrTp_Sm_Tx_s_w4_tx_cf_n);
FRTP_DECLSMFUNC(FrTp_Sm_Tx_s_w4_rx_ack);
FRTP_DECLSMFUNC(FrTp_Sm_Tx_s_w4_rx_nack);

/*
 * State Machine functions for Unsegmented RX ---------------------------------
 */

FRTP_DECLSMFUNC(FrTp_Sm_Rx_u_w4_rx_sf);

/*
 * State Machine functions for Segmented RX -----------------------------------
 */

FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_rx_ff);
FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_tx_cts);
FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_tx_cts_n);
FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_rx_cf);
FRTP_DECLSMFUNC(FrTp_Rx_TimeoutCFCF);
FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_tx_nack);
FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_tx_nack_n);

/*
 * State Machine functions supporting the transmission of FC-WT
 */
#if (FRTP_SUPPORT_TXWAIT == STD_ON)
FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_tx_wt);
FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_tx_wt_n);
FRTP_DECLSMFUNC(FrTp_Sm_Rx_s_w4_timeout_wt);
#endif

/*
 * Commonly used State Machine functions --------------------------------------
 */

FRTP_DECLSMFUNC(FrTp_Sm_Rx_su_w4_tx_ack);
FRTP_DECLSMFUNC(FrTp_Sm_Rx_su_w4_tx_ack_n);
FRTP_DECLSMFUNC(FrTp_Rx_Timeout);
FRTP_DECLSMFUNC(FrTp_Tx_Timeout);
FRTP_DECLSMFUNC(FrTp_Unexpected_Evt);
FRTP_DECLSMFUNC(FrTp_DoNothing);

#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-3 */
#include "MemMap.h"
/*
 * Four state machines control the send/recive process
 *
 * FrTpTxSMUnseg: Unsegmented Sending
 * FrTpTxSMSeg:   Segmented Sending
 * FrTpRxSMUnseg: Unsegmented Receiving
 * FrTpRxSMSeg:   Segmented Receiving
 *
 * The columns of the two-dimensional function pointer arrays represent the
 * type of event:
 *
 * Received Frame, Sent Frame, Cycle Passed, Timeout Elapsed
 *
 * Each of the rows represents a state the FrTp Channel may reside in
 *
 */

#define FRTP_START_SEC_CONST_UNSPECIFIED
/* Deviation MISRA-3 */
#include "MemMap.h"
CONST(FrTpTxSMType,FRTP_APPL_CONST) FrTpTxSMUnseg[] = {
  /* FRTPSM_W4_TX_FFSF */
  { &FrTp_Unexpected_Evt, &FrTp_Unexpected_Evt, &FrTp_Sm_Tx_u_w4_tx_sf,
    &FrTp_Tx_Timeout},

  /* FRTPSM_W4_TX_FFSF_NOTIF */
  { &FrTp_Unexpected_Evt, &FrTp_Sm_Tx_u_w4_tx_sf_n, &FrTp_DoNothing,
    &FrTp_Tx_Timeout},

  /* FRTPSM_W4_RX_ACK */
  { &FrTp_Sm_Tx_u_w4_rx_ack, &FrTp_Unexpected_Evt, &FrTp_DoNothing,
    &FrTp_Tx_Timeout}};

CONST(FrTpTxSMType,FRTP_APPL_CONST) FrTpTxSMSeg[] = {
  /* FRTPSM_W4_TX_FFSF */
  { &FrTp_Unexpected_Evt, &FrTp_Unexpected_Evt, &FrTp_Sm_Tx_s_w4_tx_ff,
    &FrTp_Tx_Timeout},

  /* FRTPSM_W4_TX_FFSF_NOTIF */
  { &FrTp_Unexpected_Evt, &FrTp_Sm_Tx_s_w4_tx_ff_n, &FrTp_DoNothing,
    &FrTp_Tx_Timeout},

  /* FRTPSM_W4_RX_ACK */
  { &FrTp_Sm_Tx_s_w4_rx_ack, &FrTp_Unexpected_Evt, &FrTp_DoNothing,
    &FrTp_Tx_Timeout},

  /* FRTPSM_W4_TX_CF */
  { &FrTp_Sm_Tx_s_w4_rx_nack, &FrTp_Consume_CFs, &FrTp_Sm_Tx_s_w4_tx_cf,
    &FrTp_Tx_Timeout},

  /* FRTPSM_W4_TX_CF_NOTIF */
  { &FrTp_Sm_Tx_s_w4_rx_nack, &FrTp_Sm_Tx_s_w4_tx_cf_n, &FrTp_DoNothing,
    &FrTp_Tx_Timeout},

  /* FRTPSM_W4_RX_CTS */
  { &FrTp_Sm_Tx_s_w4_rx_cts, &FrTp_Unexpected_Evt, &FrTp_DoNothing,
    &FrTp_Tx_Timeout}};

/* Deviation MISRA-5 */
_STATIC_ CONST(FrTpRxSMType,FRTP_APPL_CONST) FrTpRxSMUnseg[] = {
  /* FRTPSM_W4_RX_FFSF */
  { &FrTp_Sm_Rx_u_w4_rx_sf, &FrTp_Unexpected_Evt, &FrTp_Unexpected_Evt,
    &FrTp_Unexpected_Evt},

  /* FRTPSM_W4_TX_ACK */
  { &FrTp_Unexpected_Evt, &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_su_w4_tx_ack,
    &FrTp_Rx_Timeout},

  /* FRTPSM_W4_TX_ACK_NOTIF */
  { &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_su_w4_tx_ack_n, &FrTp_DoNothing,
    &FrTp_Rx_Timeout},
};

/* Deviation MISRA-5 */
_STATIC_ CONST(FrTpRxSMType,FRTP_APPL_CONST) FrTpRxSMSeg[] = {
  /* FRTPSM_W4_RX_FFSF */
  { &FrTp_Sm_Rx_s_w4_rx_ff, &FrTp_Unexpected_Evt, &FrTp_DoNothing, &FrTp_Rx_Timeout},

  /* FRTPSM_W4_TX_ACK */
  { &FrTp_Unexpected_Evt, &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_su_w4_tx_ack,
    &FrTp_Rx_Timeout},

  /* FRTPSM_W4_TX_ACK_NOTIF */
  { &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_su_w4_tx_ack_n, &FrTp_DoNothing,
    &FrTp_Rx_Timeout},
  /* FRTPSM_W4_TX_CTS */
  { &FrTp_Unexpected_Evt, &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_s_w4_tx_cts,
    &FrTp_Rx_Timeout},

  /* FRTPSM_W4_TX_CTS_NOTIF */
  { &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_s_w4_tx_cts_n, &FrTp_DoNothing,
    &FrTp_Rx_Timeout},

  /* FRTPSM_W4_TX_NACK */
  { &FrTp_Unexpected_Evt, &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_s_w4_tx_nack,
    &FrTp_Rx_Timeout},

  /* FRTPSM_W4_TX_NACK_NOTIF */
  { &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_s_w4_tx_nack_n, &FrTp_DoNothing,
    &FrTp_Rx_Timeout},

#if (FRTP_SUPPORT_TXWAIT == STD_ON)

  /* FRTMSM_WT */
  { &FrTp_Unexpected_Evt, &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_s_w4_tx_wt,
    &FrTp_Sm_Rx_s_w4_timeout_wt},

  /* FRTMSM_WT_NOTIF */
  { &FrTp_Unexpected_Evt, &FrTp_Sm_Rx_s_w4_tx_wt_n, &FrTp_Unexpected_Evt,
    &FrTp_Sm_Rx_s_w4_timeout_wt},
#endif

  /* FRTPSM_W4_RX_CF */
  { &FrTp_Sm_Rx_s_w4_rx_cf, &FrTp_Unexpected_Evt, &FrTp_DoNothing,
    &FrTp_Rx_TimeoutCFCF},
};

#define FRTP_STOP_SEC_CONST_UNSPECIFIED
/* Deviation MISRA-3 */
#include "MemMap.h"
/* ----------------------------------------------------------------------------
 Local Functions Declaration
 ---------------------------------------------------------------------------- */

#define FRTP_START_SEC_CODE
/* Deviation MISRA-3 */
#include "MemMap.h"

/**
 *
 *  \brief Configures a FrTp channel for receiving a FrTp message
 *
 *  \param  lChnIdx: FrTp channel for message recception
 *                  (available if multiple channel support is enabled)
 *  \param  pFrameInfo: FF/SF of FrTp message
 */
_STATIC_
FUNC(void,FRTP_CODE) FrTp_SetupRxChannel(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    CONSTP2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pFrameInfo);


/**
 *
 *  \brief Get the Index of the first Tx-PDu
 *
 *  \param  lConIdx: Index of the connection to be searched
 *                 (available if multiple channel support is enabled)
 *  \return Index of the Tx-PDU in the TxPduTable
 */

_STATIC_
FUNC(uint8,FRTP_CODE) FrTp_GetTxPDUIdx(
    VAR(uint8,AUTOMATIC) lConIdx);

/**
 *
 *  \brief Check if PDU shall be ignored
 *
 *  \param  lFrameInfo: PDU to be evaluated
 *
 *  \return true, if PDU shall not be taken into account
 *          false PDU shall be processed
 */

_STATIC_
FUNC(boolean,FRTP_CODE) FrTp_IgnorePdu(
    CONST (FrTpFrameInfoType,AUTOMATIC) lFrameInfo);

/**
 *
 *  \brief Find the appropriate connection
 *
 *  \param  startIdx: Index where the search shall be started
 *  \param        SA: Source Address of the connection to be found
 *  \param        TA: Target Address of the connection
 *  \param   MasType: MasType to be searched
 *  \param   lChnIdx: Channel index for the connection searched
 *
 *  \return Index of the connection (if found)
 *          -1 if no connection could be found
 */
_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_GetConIdx(
    VAR(uint8,AUTOMATIC) startIdx,
    VAR(uint8,AUTOMATIC) SA,
    VAR(uint8,AUTOMATIC) TA,
    VAR(uint8,AUTOMATIC) MasType
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    , VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx
#endif
    );

/**
 *
 *  \brief Finds a free FrTp and ensures that no other FrTp channel
 *         is occupied with sending/receiving FrTp messages with
 *         the provided Src/Tgt address pair
 *
 *  \param  lChnIdx: Channel containing the SduID of the connection
 *
 *  \return Index of the free FrTp channel on success
 *          -1 if no channel is free or if there is already another
 *             channel occupied with the same address pair
 */

_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_ReserveFrameInfoBuffer(
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx
    );

/**
 *
 *  \brief Transmits a FrTp Flow Control frame
 *
 *  \param  lChnIdx: Index of the FrTp channel that transmits the PDU
 *  \param  lConIdx: Index of the connection that transmits the PDU
 *  \param  Src:     Source Address field of FC Frame
 *  \param  Tgt:     Target Address field of FC Frame
 *  \param  FrmType: Frame Type to transmit
 *                      (ACK, NACK, CTS, WT, CREF)
 *
 *  \return 0 on success,
 *          -1 if the frame could not be sent
 */
_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_SendFC(
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
    VAR(uint8,AUTOMATIC)           lConIdx,
    VAR(FrTpAddressType,AUTOMATIC) Src,
    VAR(FrTpAddressType,AUTOMATIC) Tgt,
    VAR(FrTpFrameType,AUTOMATIC) FrmType);

/**
 *
 *  \brief Transmits a FrTp Data PDU
 *
 *  \param  lChnIdx:   Index of the FrTp channel that transmits the PDU
 *                      (available if multiple channel support is enabled)
 *  \param  lTxPduIdx: Index of PDU which is used to send the PDU
 *  \param  FrmType:   Frame Type to transmit (FF, SF, CF)
 *
 *  \return 0 on success,
 *          -1 if the PDU could not be sent
 */
_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_SendDF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    VAR(uint8,AUTOMATIC) lTxPduIdx,
    VAR(FrTpFrameType FrameType,AUTOMATIC),
    VAR(uint8,AUTOMATIC) Ds);

/**
 *
 *    \brief processes a received NACK frame
 *
 *    if a NACK frame has been received, the data has to be rolled
 *    back to the position where the erroneous frame began.
 *    Error counters must be incremented to abort transmission
 *    after a defined threshold of two retries.
 *
 *    \param lChnIdx: Zero based index of the TX Frame buffer
 *                    (available if multiple channel support is enabled)
 *    \param ErrFrmIdx: Index of the erroneous frame (provided in NACK)
 *
 *    \return : 0 on successful processing
 *            : -1 if the retry counter exceeded the threshold
 *              value or some other error occurred
 *            : -2 if the provided NACK parameters were
 *              inconsistent and the NACK should be ignored
 */
_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_ProcessNACK(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    VAR(uint8,AUTOMATIC) ErrFrmIdx);

/**
 *
 *    \brief Sends at most n CFs
 *
 *    After the sender received a CTS frame from the receiving node,
 *    it is possible to send more than one frame per cycle in parallel
 *    (bulk) provided that enough data is available and the receiving
 *    node admitted this by the bandwidth control parameter of the CTS
 *    frame.
 *    this function tries to send at most n frames in parallel.
 *
 *    \param MaxCF  : Upper bound of CFs to send
 *    \param lChnIdx: FrTp Channel Index
 *                   (available if multiple channel support is enabled)
 *
 *    \return       : Number of CFs that were sent
 */
_STATIC_
FUNC(uint8,FRTP_CODE) FrTp_ProduceMaxNCF(
    VAR(uint8,AUTOMATIC) MaxCF
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    , VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx
#endif
    );

/**
 *
 *    \brief Determines whether CFs may be sent, and if so, how much
 *
 *    this function keeps track of the number of frames that may be
 *    sent within one communication cycle. if the bandwidth control
 *    of the receiver implied that there must be separation cycles
 *    between the CFs, it keeps track of the elapsed separation cycles
 *
 *    \param lChnIdx: Index of the FrTp channel
 *                    (available if multiple channel support is enabled)
 */
_STATIC_
FUNC(void,FRTP_CODE) FrTp_ProduceCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx
#else
    void
#endif

    );

/**
 *
 *    \brief Copies data from the FrTp Frame Info buffer
 *           to the data buffer provided in the FrTp channel
 *
 *
 *    \param lChnIdx    : Index of the FrTp channel
 *                        (available if multiple channel support is enabled)
 *    \param pData      : Frame Info Entry of FrTp data frame
 *
 *    \return
 *     FRTP_E_OK:     if the data was copied
 *     FRTP_E_BUSY:   The application layer delayed the copy operation
 *     FRTP_E_NOT_OK: The copy operation failed, the application did
 *                    not grant the necessary buffer
 */
_STATIC_
FUNC(BufReq_ReturnType,FRTP_CODE) FrTp_HandleDataFrame(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) pSrc,
    VAR(uint8,AUTOMATIC) Size);

/**
 *
 *    \brief Tries to acquire data necessary for FrTp
 *           message transmission
 *
 *    \param lChnIdx: Index of the FrTp channel that sends an FrTp message
 *                    (available if multiple channel support is enabled)
 *    \param Bytes:   Minimum necessary  size in bytes
 *
 *    \return
 *      FRTP_E_OK:     The necessary  buffer was provided by the
 *                     application layer
 *      FRTP_E_NOT_OK: The  buffer was not granted by the application
 *                     layer
 *      FRTP_E_BUSY:   No data is available yet. The Tp layer will retry to
 *                     acquire a buffer at a later point in time.
 */
_STATIC_
FUNC(BufReq_ReturnType,FRTP_CODE) FrTp_RetrievePayload(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    VAR(FrTpSizeType,AUTOMATIC) Length);

/**
 *
 *    \brief Performs consistency checks on a CF
 *
 *    this function checks the amount of data and the frame index
 *    parameter of the CF. if both parameters are OK, the data is
 *    copied into the matching frame buffer.
 *
 *    \param lChnIdx: Index of the FrTp channel handling the CF
 *                    (available if multiple channel support is enabled)
 *    \param pData : Points to the Frame Info entry containing the CF data
 *
 *    \return      : 0 if the CF is consistent
 *                   -1 if an inconsistent CF was detected
 */
_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_CheckCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData);

/**
 *
 *    \brief Handles an arrived CF
 *
 *    this function invokes the CF consistency check. if the check failed,
 *    it handles it with respect to retry counters. if the maximum number
 *    of retries has been reached, the reception is aborted.
 *    if the last CF of a block has been received, a new Flow Control Frame
 *    is set up (CTS if no error occurred, or NACK if an error occurred) by
 *    changing the state of the current TX FrTp channel.
 *
 *    \param lChnIdx: Index of the FrTp channel handling the CF
 *                   (available if multiple channel support is enabled)
 *    \param pData : Points to the Frame Info entry containing the CF data
 *
 */
_STATIC_
FUNC(void,FRTP_CODE) FrTp_HandleCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData);

_STATIC_
FUNC(void,FRTP_CODE) FrTp_CheckClearTxPduBuffer(
    VAR(uint8,AUTOMATIC) inConIdx
);
/**
 *
 *    \brief State Transition Functions
 *
 *    These functions have the same signature and are inserted into a
 *    two-dimensional array that makes up a State Machine.
 *    The functions are provided
 *
 *    \param lChnIdx    : Index of the FrTp channel
 *                        (available if multiple channel support is enabled)
 *    \param pData      : Reference to the FrTp Fame Info buffer
 *
 *    as parameters.
 *
 *    The functions are called on four types of events:
 *
 *    - FrTp Frame Received
 *    - FrTp Frame Successfully sent
 *    - Communication Cycle passes (Frame Info Buffer referenve is NULL)
 *    - Timeout expired            (Frame Info Buffer reference is NULL)
 *
 *    The following naming convention is used:
 *
 *    FrTp_Sm_<direction>_<seg>_<event>
 *
 *    direction: Rx / Tx
 *    seg: u (unsegmented), s (segmented) transmission,
 *         us (used in both segmented and unsegmented state machines)
 *
 *    event: Event the state machine waits for currently
 *      - w4_<tx_<frm>/tx_<frm>_n/rx_<frm>/timeout>
 *          - tx_<frm>:  SM waits for transmission of a frame <frm>
 *          - tx_n<frm>: SM waits for notification of successful frame <frm>
 *                       transmission
 *          - rx_<frm>:  SM waits for the reception of a frame <frm>
 *          - timeout:   SM encountered that a timeout expired
 *
 */

_STATIC_
FUNC(Std_ReturnType,FRTP_CODE) FrTp_ExtractData(
    P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) pbuf,
    VAR(uint8,AUTOMATIC) nLen,
    P2VAR(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pdata);

/**
 *
 *    \brief Encodes data out of a <code>FrTpFrameInfoType</code>
 *      structure (TL IL Buffer) into a char buffer
 *
 *    \param  pdata: Frame Info Buffer to encode data from
 *    \param  pbuf: Data buffer to encode data to
 *    \param  *pbufsize(out): Length of encoded data buffer in bytes
 *
 *    \return E_NOT_OK if a consistency check failed during extraction
 *            E_OK on success
 *
 */
 

_STATIC_
FUNC(void,FRTP_CODE) FrTp_CheckClearTxPduBuffer(
    VAR(uint8,AUTOMATIC) inConIdx
)
 
/**
 *
 *  \brief Checks if a PDU-Buffer is still locked due to a missing
 *         confirmation or failed transmission via FrTP.
 *         Such a PDU-Buffer will be released in this case.
 *
 *  \param  inConIdx: Connection to be checked
 *
 *  \return none
 */

 #define FRTP_STOP_SEC_CODE
/* Deviation MISRA-3 */
#include "MemMap.h"
/* ----------------------------------------------------------------------------
 Global Functions
 ---------------------------------------------------------------------------- */

/* start code section declaration */
#define FRTP_START_SEC_CODE
/* Deviation MISRA-3 */
#include "MemMap.h"


{
#if (FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF)
  VAR(uint8,AUTOMATIC) lConIdx;
#endif
  VAR(uint8,AUTOMATIC) lTxPDUId = FrTp_GetTxPDUIdx(inConIdx);
  
  /*
   * for existing TxPDUIds only
   */
  if ((FRTP_G_TXDATA->pInfo) != NULL_PTR && (0xFF != lTxPDUId))
  {
    /*
     * Pdu still in use, clear it to setup a clean channel
     */
    FRTP_G_TXDATA->pInfo->Reserve=FRTP_INVALID;
    FRTP_G_TXDATA->pInfo = NULL_PTR;
    /*
     * Clear the confirmed flag in every case
     */
    FRTP_G_TXDATA->Confirmed = FALSE;
    /*
     * If more than one PDU may be used for sending set
     * all IDs for TxPdus of this channel as confirmed
     */
#if (FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF)
    lConIdx = inConIdx;
    while ((lTxPDUId<gFrTpTxPDUNumber) && (FRTP_G_TXCFG->ConIdx == lConIdx) &&
        (FRTP_G_TXDATA->pInfo != NULL_PTR))
    {
      FRTP_G_TXDATA->pInfo->Reserve=FRTP_INVALID;
      FRTP_G_TXDATA->pInfo = NULL_PTR;
      FRTP_G_TXDATA->Confirmed = FALSE;
      lTxPDUId++;
    }
#endif 
  }
  
}


/* ----------------------------------------------------------------------------
 Local Functions
 ---------------------------------------------------------------------------- */

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_GetConIdx(
    VAR(uint8,AUTOMATIC) startIdx,
    VAR(uint8,AUTOMATIC) SA,
    VAR(uint8,AUTOMATIC) TA,
    VAR(uint8,AUTOMATIC) MasType
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    , VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx
#endif
) {
  VAR(uint8,AUTOMATIC) lConIdx;
  VAR(sint8,AUTOMATIC) returnIdx;
  /*
   * set default return value
   */
  returnIdx=-1;
  for (lConIdx=startIdx; lConIdx<gFrTpConNumber; lConIdx++) {
    /*
     * check source and target address and
     * Flow Control may only be used by none group addressed
     * connections
     */
    if (((( FRTP_G_CONCFG->LAddr == TA ) && ( FRTP_G_CONCFG->RAddr == SA ))
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
	 && ( FRTP_G_CONCFG->ChnIdx == lChnIdx )
#endif
       ) && ( FRTP_USEFC(MasType) != FRTP_G_CONCFG->mult_rec)) {
      returnIdx= (sint8) lConIdx;
    }
  }
  return  returnIdx;
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(uint8,FRTP_CODE) FrTp_GetTxPDUIdx(
    VAR(uint8,AUTOMATIC) lConIdx)
{
  /* return the index of the first Tx-PDU
   */
  return FRTP_G_CONCFG->TxPDUTblIdx;
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(boolean,FRTP_CODE) FrTp_IgnorePdu(
    CONST(FrTpFrameInfoType,AUTOMATIC) lFrameInfo)
{
  VAR(boolean, AUTOMATIC) ignorePdu=FALSE;

  if (FRTP_SF == lFrameInfo.FrameType)

  {
    /*
     * Ignore this zero bytes long frame
     */
    if (lFrameInfo.PCI.Length == 0) {
      ignorePdu=TRUE;
    }
    if ((lFrameInfo.PCI.Length > (FRTP_MAXLEN_GRPADDR)) && (FRTP_USEFC(lFrameInfo.MasTypeID) == 0)) {
      /*
       * Ignore this group addressed, because it is to long
       */
      ignorePdu=TRUE;
    }
  }

  if (FRTP_FF == lFrameInfo.FrameType) {
    /*
     * Ignore this zero bytes long frame
     */
    if (lFrameInfo.PCI.Length == 0) {
      ignorePdu=TRUE;
    }
    /*
     * Message is too long
     */
    if (lFrameInfo.PCI.Length >FRTP_MAXLEN_FF2B) {
      /*
       * Ignore this too long FF
       */
      ignorePdu=TRUE;
    }
    /*
     * FF provides too few bytes, so that a SF shall be used instead
     */
    if (lFrameInfo.PCI.Length <= lFrameInfo.DataSize) {
      /*
       * Ignore this short frame due to requirement R.27
       */
      ignorePdu=TRUE;
    }
    /*
     * Group-addressed segmented messages are not supported, so ignore it
     */
    if (FRTP_USEFC(lFrameInfo.MasTypeID) == 0) {
      ignorePdu=TRUE;
    }
  }

  return ignorePdu;
}

/*
 *
 *
 * ----------------------------------------------------------------------------
 */

FUNC(void,FRTP_CODE) FrTp_HandleRxData(
    CONST(uint8,AUTOMATIC) lRxPDUId
)

{
  VAR(FrTpFrameInfoType,AUTOMATIC) lFrameInfo;
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  VAR(sint8,AUTOMATIC) lChnIdx;
#endif
  VAR(Std_ReturnType,AUTOMATIC) status;

  /*
   * Extract data out of PDU
   */
  status = FrTp_ExtractData(FRTP_G_RXDATA->BufferPtr,
      (uint8)FRTP_G_RXCFG->Length,&(lFrameInfo));

  if (status != E_OK)
  {
    /*
     * Data extraction has failed
     */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError(lRxPDUId,
        FRTP_MAINFUNCTION_SERVICE_ID,
        FRTP_E_IGNORED_RX_PDU);
#else
    /* do nothing */
#endif
  }
  /*
   * Check if Frame shall be ignored
   */
  else if (FrTp_IgnorePdu(lFrameInfo) == TRUE)
  {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError(lRxPDUId,
        FRTP_MAINFUNCTION_SERVICE_ID,
        FRTP_E_IGNORED_RX_PDU);
#else
    /* do nothing */
#endif
  }
  else
  {
    /*
     * Set the active channel to those of the Rx-PDU
     */
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    lChnIdx = (sint8) FRTP_G_RXCFG->ChnIdx;
#endif
    /*
     * Check if the associated channel is occupied for transmission
     * switch addresses, because sender of PDU is receiver of PDU
     */
    if ((((FRTP_CHANNEL.State == FRTP_CHN_TX) &&
          (FRTP_CHANNEL.Info.AddrInfo.Addr.Src == lFrameInfo.AddrInfo.Addr.Tgt)) &&
         (FRTP_CHANNEL.Info.AddrInfo.Addr.Tgt == lFrameInfo.AddrInfo.Addr.Src)) &&
        (FRTP_CHANNEL.Info.MasTypeID == lFrameInfo.MasTypeID))
    {
      /*
       * Channel is used by this connection for transmission
       */
      /*
       * Check if MasType matches
       */
      if (lFrameInfo.FrameType > FRTP_CF) /* Flow Control Frames */
      {
        /*
         * Only FC-PDUs are awaited in this channel
         */
        (FRTP_CHANNEL.Chn.Tx.pTxSM)
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        [FRTP_CHANNEL.Chn.Tx.State][FRTPSM_EVT_RX]
        ((FrTpChannelIndexType)lChnIdx, &lFrameInfo);
#else
        [FRTP_CHANNEL.Chn.Tx.State][FRTPSM_EVT_RX]
        (&lFrameInfo);
#endif
      }
    }
  
    /*
     * Check if the associated channel is occupied for reception
     */
    if (((FRTP_CHANNEL.State == FRTP_CHN_RX) &&
         (FRTP_CHANNEL.Info.AddrInfo.Key == lFrameInfo.AddrInfo.Key)) &&
        (FRTP_CHANNEL.Info.MasTypeID == lFrameInfo.MasTypeID))
  
    {
      if (lFrameInfo.FrameType == FRTP_CF)
      {
        (FRTP_CHANNEL.Chn.Rx.pRxSm)
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        [FRTP_CHANNEL.Chn.Rx.State][FRTPSM_EVT_RX]
        ((FrTpChannelIndexType)lChnIdx, &(lFrameInfo));
#else
        [FRTP_CHANNEL.Chn.Rx.State][FRTPSM_EVT_RX]
        (&(lFrameInfo));
#endif
  
      }
      if ((lFrameInfo.FrameType == FRTP_FF) ||
          (lFrameInfo.FrameType == FRTP_SF))
      {
        /*
         * Cancel ongoing segmented transmission (R.75)
         */
        FRTP_RELRXCHNWITHSTATUS(
            FRTP_E_NOT_OK
        );
      }
    }
    /*
     * For SF and FFs:
     * If channel is free (now), setup new Channel,
     * otherwise send FC-CREF
     */
    if ((lFrameInfo.FrameType == FRTP_FF) ||
        (lFrameInfo.FrameType == FRTP_SF))
    {
      VAR(sint8,AUTOMATIC) lConIdx;
  
      /*
       * Search channel for this connection
       */
      lConIdx=FrTp_GetConIdx(FRTP_G_RXCFG->ConIdx,
          lFrameInfo.AddrInfo.Addr.Src,
          lFrameInfo.AddrInfo.Addr.Tgt,
          lFrameInfo.MasTypeID
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
          ,(FrTpChannelIndexType) lChnIdx
#endif
      );
  
      if (FRTP_CHANNEL.State == FRTP_CHN_FREE)
      {
  
        /*
         * a Connection has been found -> setup new channel
         */
        if (lConIdx >=0)
        {
          FRTP_CHANNEL.ConIdx = (uint8) lConIdx;

        /*
         * Frame Size is relevant for segmented receiving,
         * as every data frame will have the same length
         * (with the exception of the last CF)
         */
        if (FRTP_FF == lFrameInfo.FrameType) {
          FRTP_CHANNEL.PduSize = (uint8)FRTP_G_RXCFG->Length;
        }

          FrTp_SetupRxChannel(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
              (FrTpChannelIndexType)lChnIdx,
#endif
              &(lFrameInfo));
        }
        else
        {
          /*
           * do nothing and ignore the PDU-> PDU was not addressed to this node
           */
        }
      }
      else
      {
        /*
         * Reject this one only if the FF/SF has
         * been sent in SC mode and Connection has been found
         */
        if ((FRTP_USEFC(lFrameInfo.MasTypeID) != 0) && (lConIdx >= 0))
        {
          /*
           * There is already a transaction with
           * the same address tuple going on.
           * ->Reject this one by sending CREF
           * Ignoring return value, because if sending of the FC_CREF fails
           * no further actions can be done in next cycle, because no channel
           * will be set up.
           */
          (void)FrTp_SendFC(
              (FrTpChannelIndexType)FRTP_NOCHANNEL,
              (uint8) lConIdx,
              lFrameInfo.AddrInfo.Addr.Tgt,
              lFrameInfo.AddrInfo.Addr.Src,
              FRTP_FC_CREF);
        }
      }
    }
  }
}

_STATIC_ FUNC(void,FRTP_CODE) FrTp_SetupRxChannel(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    CONSTP2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pFrameInfo) {
  /*
   * Reserve FrTp Channel for Rx
   */
  FRTP_CHANNEL.State = FRTP_CHN_RX;

  /*
   * Setup configuration
   */

  FRTP_CHANNEL.BC = FRTP_G_CHNCFG->BCDefault;

  FRTP_CHANNEL.BSMax = FRTP_G_CHNCFG->BSInit;

  FRTP_CHANNEL.Length = pFrameInfo->PCI.Length;

  /*
   * MAS typeid is MAS Type ID used by sender. We are always
   * using SC addressing when sending FC frames
   */
  FRTP_CHANNEL.Info.MasTypeID = pFrameInfo->MasTypeID;
  FRTP_CHANNEL.Info.AddrInfo.Key = pFrameInfo->AddrInfo.Key;

  /*
   * Setup Buffer
   */
  FRTP_CHANNEL.pBuffer = NULL_PTR;
#if (FRTP_TX_BUFFER_REQUEST_ZERO == STD_ON)
  FRTP_CHANNEL.RetryBuffer.SduLength = 0;
#endif
  /*
   * Setup State
   */
  FRTP_CHANNEL.Chn.Rx.CFsSinceFC = 0;
  FRTP_CHANNEL.Chn.Rx.CFsReceivedSinceFC = 0;
  FRTP_CHANNEL.Chn.Rx.ErrFrameIndex = -1;
  FRTP_CHANNEL.Chn.Rx.ErrFrameIndexPrevBlock = -1;
  FRTP_CHANNEL.Chn.Rx.ErrorCounter = 0;
  FRTP_CHANNEL.Chn.Rx.ReceivedBytes = 0;
  FRTP_CHANNEL.Chn.Rx.LastCFDataBytes = 0;

  FRTP_CHANNEL.Chn.Rx.Timeout =(sint16)FRTP_TIMEOUTCOMMON;

  FRTP_CHANNEL.Chn.Rx.WriteIdx = 0;
  FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_RX_FFSF;

  if (FRTP_SF == pFrameInfo->FrameType) {
    FRTP_CHANNEL.Chn.Rx.pRxSm = FrTpRxSMUnseg;
  } else {
    FRTP_CHANNEL.Chn.Rx.pRxSm = FrTpRxSMSeg;
  }

  /*
   * Immediately invoke state machine function here. No need
   * to check the pointer validity. The state machine function
   * is defined in _any_ case.
   */
  (FRTP_CHANNEL.Chn.Rx.pRxSm)
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  [FRTP_CHANNEL.Chn.Rx.State][FRTPSM_EVT_RX](lChnIdx, pFrameInfo);
#else
  [FRTP_CHANNEL.Chn.Rx.State][FRTPSM_EVT_RX](pFrameInfo);
#endif
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_ReserveFrameInfoBuffer(
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx)
{
  VAR(uint8,AUTOMATIC) i = 0;

  for (i = 0U; i < FRTP_PDUINFO_BUFFER_NUM; i++) {
    if (aFrTpFrameInfo[i].Reserve == (uint8)FRTP_INVALID) {
      aFrTpFrameInfo[i].Reserve = lChnIdx;
      /* Deviation MISRA-2 */
      return (sint8)i;
    }
  }

  /* Deviation MISRA-2 */
  return (sint8)-1;
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(sint8, FRTP_CODE) FrTp_SendFC(
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
    VAR(uint8,AUTOMATIC) lConIdx,
    VAR(FrTpAddressType,AUTOMATIC) Src,
    VAR(FrTpAddressType,AUTOMATIC) Tgt,
    VAR(FrTpFrameType,AUTOMATIC) FrmType)
{

  VAR(sint8,AUTOMATIC) idx = FrTp_ReserveFrameInfoBuffer(lChnIdx);

  VAR(Std_ReturnType,AUTOMATIC) status;

  /*
   * No Interaction Buffer left?
   */
  if (idx < 0) {
    /* Deviation MISRA-2 */
    return -1;
  }

  FRTP_MK_FC(aFrTpFrameInfo[idx], FrmType, FRTP_AT_SC, Src, Tgt);

  /*
   * FC frames with parameters. In these cases, the FrTp Channel
   * _must_ be a valid RX Frame Channel!
   */
  if (FRTP_FC_CTS == FrmType) {
    aFrTpFrameInfo[idx].PCI.FC.BC = FRTP_CHANNEL.BC;
    aFrTpFrameInfo[idx].PCI.FC.BSMax = FRTP_CHANNEL.BSMax;
  } else if (FRTP_FC_NACK == FrmType) {
    aFrTpFrameInfo[idx].PCI.FrameIndex
        = (uint8) FRTP_CHANNEL.Chn.Rx.ErrFrameIndex;
  } else {
    /*
     * All necessary parameters already set
     */
  }

  /*
   * Schedule CREF frame for transmission
   */
  status= FrTp_TransmitPDU(FrTp_GetTxPDUIdx(lConIdx),
      &(aFrTpFrameInfo[idx]));

  if (E_OK != status) {
    aFrTpFrameInfo[idx].Reserve = FRTP_INVALID;
    /* Deviation MISRA-2 */
    return -1;
  }

  /* Deviation MISRA-2 */
  return 0;
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_SendDF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    VAR(uint8,AUTOMATIC) lTxPduIdx,
    VAR(FrTpFrameType,AUTOMATIC) FrameType,
    VAR(uint8,AUTOMATIC) Ds)
{
  VAR(sint8,AUTOMATIC) idx = FrTp_ReserveFrameInfoBuffer(CHNIDX);

  /*
   * No Interaction Buffer left?
   */
  if (idx < 0) {
    /* Deviation MISRA-2 */
    return -1;
  }

  /*
   * Common Data Frame Fields
   */
  FRTP_MK_DF(aFrTpFrameInfo[idx], FrameType,
      FRTP_CHANNEL.Info.MasTypeID,
      FRTP_CHANNEL.Info.AddrInfo.Key, Ds);

  /*
   * Frame Type dependent fields
   */
  if (FrameType == FRTP_CF) {
    aFrTpFrameInfo[idx].PCI.FrameIndex
        = (uint8)FRTP_CHANNEL.Chn.Tx.NextFrameIndex;

    aFrTpFrameInfo[idx].pData = &(FRTP_CHANNEL.pBuffer->SduDataPtr
    [FRTP_CHANNEL.Chn.Tx.ReadIdx]);

  } else /* FF and SF */
  {
    aFrTpFrameInfo[idx].pData = FRTP_CHANNEL.pBuffer->SduDataPtr;
    aFrTpFrameInfo[idx].PCI.Length = FRTP_CHANNEL.Length;
  }

  if (FrTp_TransmitPDU(lTxPduIdx,
      &(aFrTpFrameInfo[idx])) == E_NOT_OK) {
    aFrTpFrameInfo[idx].Reserve = FRTP_INVALID;
    /* Deviation MISRA-2 */
    return -1;
  }

  /* Deviation MISRA-2 */
  return 0;
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_ProcessNACK(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    VAR(uint8,AUTOMATIC) ErrFrmIdx)
{
  VAR(uint8,AUTOMATIC) CFResends;
  VAR(FrTpSizeType,AUTOMATIC) CFRollback;

  /*
   * Index of previously sent CF
   */
  VAR(uint8,AUTOMATIC) chPrev = (uint8) FRTP_PREVSN(FRTP_CHANNEL.Chn.Tx.NextFrameIndex);

  /*
   * Calculate number of CF frames to resend
   */
  CFResends = FRTP_CFRESENDS(chPrev, ErrFrmIdx);

  /*
   * Erroneous SN in NACK Parameter leads to rollback
   * if the number of frames to resend is larger than number of
   * CFs sent since the previous FC frame
   */
  if (CFResends > FRTP_CHANNEL.Chn.Tx.CFsSinceFC) {
    /* Deviation MISRA-2 */
    return -2;
  }

  /*
   * Calculate appropriate read index
   */
  CFRollback = (FrTpSizeType)FRTP_ROLLBACK(
      CFResends,
      FRTP_CF_DATA_SIZE(
          FRTP_CHANNEL.PduSize),
      FRTP_CHANNEL.Chn.Tx.LastCFDataBytes);

  /*
   * internal error: rollback is larger than available data
   * -> Terminate transmission
   */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (CFRollback > FRTP_CHANNEL.Chn.Tx.ReadIdx) {
    FrTp_Det_ReportError( CHNIDX,
        FRTP_TXSTATEMACHINE_SERVICE_ID,
        FRTP_E_ASSERT);
    /* Deviation MISRA-2 */
    return -1;
  }
#endif
  /*
   * Check three times the same erroneous frame index
   */

  if (ErrFrmIdx == FRTP_CHANNEL.Chn.Tx.ErrFrameIndex) {
    ++FRTP_CHANNEL.Chn.Tx.ErrorCounter;

    if (FRTP_CHANNEL.Chn.Tx.ErrorCounter > (sint8)FRTP_MAX_NACK_RETRIES) {
      /*
       * Abort, we have received three times an nack on the same frame
       */
      /* Deviation MISRA-2 */
      return -1;
    }
  } else {
    /*
     * Different frame counter, reset error counter
     */
    FRTP_CHANNEL.Chn.Tx.ErrorCounter = 1;
  }

  /*
   * Reset data to restart re-sending
   */
  FRTP_CHANNEL.Chn.Tx.ReadIdx -= CFRollback;
  FRTP_CHANNEL.Chn.Tx.SentBytes -= CFRollback;
  FRTP_CHANNEL.Chn.Tx.NextFrameIndex = (sint8)ErrFrmIdx;
  FRTP_CHANNEL.Chn.Tx.ErrFrameIndex = (sint8)ErrFrmIdx;
  FRTP_CHANNEL.Chn.Tx.CFsSinceFC -= (sint8)CFResends;
  FRTP_CHANNEL.Chn.Tx.LastCFDataBytes = 0;

  /* Deviation MISRA-2 */
  return 0;
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(uint8,FRTP_CODE) FrTp_ProduceMaxNCF(uint8 MaxCF
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
, VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx
#endif
) {
  /*
   * produce CFs as long as there is enough data for a full CF or
   * if the data pointer reaches the end of the data to send
   * (produce the last CF)
   */
  VAR(uint8,AUTOMATIC) i = 0;
  VAR(uint8,AUTOMATIC) ldoCF = MaxCF;
  VAR(uint8,AUTOMATIC) CFDataSize = (uint8) (FRTP_CF_DATA_SIZE(FRTP_CHANNEL.PduSize));
#if (FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF)
  VAR(uint8,AUTOMATIC) lConIdx=FRTP_CHANNEL.ConIdx;
#endif

  /* data available to send */
  VAR(sint16 DataAvail,AUTOMATIC) = (sint16) FRTP_MIN(
      (FRTP_CHANNEL.pBuffer->SduLength -
          FRTP_CHANNEL.Chn.Tx.ReadIdx),
      (FRTP_CHANNEL.Length -
          FRTP_CHANNEL.Chn.Tx.SentBytes));

#if (FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF)
  /*
   * limit to the maximum number of TX-PDU available for this connection
   */
  ldoCF = FRTP_MIN(MaxCF,FRTP_G_CONCFG->TxPDUcount);
  /*
   * limit to the maximum data available
   */
  ldoCF = FRTP_MIN(ldoCF,(uint8)(DataAvail/CFDataSize) +1U);
  /*
   * limit to the maximum CFs left in this block
   */
  ldoCF = FRTP_MIN(ldoCF,FRTP_CHANNEL.BSMax-FRTP_CHANNEL.Chn.Tx.CFsSinceFC);
#else
  /*
   * limit to the maximum CFs to 1
   */
  ldoCF = 1U;
#endif

  while ((i < ldoCF) && (DataAvail != 0)) {
    /*
     * Calculate amount to send in CF
     */
    VAR(sint8,AUTOMATIC) nRet;
    VAR(uint8,AUTOMATIC) amnt = (uint8)FRTP_MIN((sint16)CFDataSize, DataAvail);
    VAR(uint8,AUTOMATIC) lTxIdx = FrTp_GetTxPDUIdx(FRTP_CHANNEL.ConIdx);

#if (FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF)
    /*
     * TxPDUs are sortet by the MCG, so if more than one PDU is available
     * these PDUs follows after lTxPduIdx.
     * However, the PDU on position lTxPduIdx must be the last used for
     * transmission
     */
     lTxIdx =(lTxIdx + (ldoCF -1U)) - i;
#endif

    nRet = FrTp_SendDF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        lChnIdx,
#endif
        lTxIdx,
        FRTP_CF,
        amnt);

    if (nRet < 0) {
      /* Deviation MISRA-2 */
      return i;
    }

    if (amnt < CFDataSize) {
      /* remember last junk of data for rollback in case of NACK */
      FRTP_CHANNEL.Chn.Tx.LastCFDataBytes = amnt;
    }

    ++i;

    FRTP_CHANNEL.Chn.Tx.NextFrameIndex = (sint8)
    FRTP_NEXTSN(FRTP_CHANNEL.Chn.Tx.NextFrameIndex);

    /* Update data amount, read index */
    FRTP_CHANNEL.Chn.Tx.ReadIdx += (FrTpSizeType)amnt;
    FRTP_CHANNEL.Chn.Tx.SentBytes += (FrTpSizeType)amnt;

    DataAvail -= amnt;

    /*
     * one CF successfully sent
     */
    ++FRTP_CHANNEL.Chn.Tx.CFsSinceFC;

  } /* while */

  /* Deviation MISRA-2 */
  return i;
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_ProduceCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx
#else
    void
#endif
) {

  /*
   * Check the Bandwidth control variable: How many identifiers
   * are allowed to be sent per cycle / how many cycles should
   * the state machine wait until the next frame is to be sent?
   */

  /*
   * Max number of frames per cycle case
   */
  if ((FRTP_CHANNEL.BC & FRTP_BC_SC_FILTER) != 0) {
    VAR(uint8,AUTOMATIC) MaxCFs = (uint8)
#if (FRTP_ROLE == FRTP_NODE)
        1;
#else
    (FRTP_CHANNEL.BC &
        FRTP_BC_VAL_FILTER);
#endif
    /*
     * Bulk send at most MaxCFs frames
     */
    VAR(uint8,AUTOMATIC) TxCFs = FrTp_ProduceMaxNCF(MaxCFs
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        , lChnIdx
#endif
        );

    if (TxCFs != 0) {
      FRTP_CHANNEL.Chn.Tx.CFsWaitCtr = TxCFs;

      /*
       * Change state to wait for tx notification
       */
      FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_CF_NOTIF;
    }
  }
  /*
   * Separation cycles case: Wait for n cycles to transmit next CF
   */
  else {
    if (FRTP_CHANNEL.Chn.Tx.CFsCycleWaitCtr == 0) {
      /*
       * Send _one_ CF here after a number of cycles has passed
       */

      VAR(uint8,AUTOMATIC) TxCFs = FrTp_ProduceMaxNCF( (uint8)(1)
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
          , lChnIdx
#endif
          );

      if (TxCFs > 0) {
        /*
         * CF was sent, set wait counter back
         */

        FRTP_CHANNEL.Chn.Tx.CFsCycleWaitCtr =
        (uint8)(FRTP_CHANNEL.BC &
            FRTP_BC_VAL_FILTER);

        /*
         * Wait for the transmission of this CF before continuing
         */
        FRTP_CHANNEL.Chn.Tx.CFsWaitCtr = 1;

        /*
         * Change state to wait for tx notification
         */
        FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_CF_NOTIF;
      }
    } else {
      --FRTP_CHANNEL.Chn.Tx.CFsCycleWaitCtr;
    }
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(BufReq_ReturnType,FRTP_CODE) FrTp_HandleDataFrame(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) pSrc,
    VAR(uint8,AUTOMATIC) Size)
{
  /*
   * Available data in the current buffer
   */
  VAR(uint16,AUTOMATIC) avail = 0;
  VAR(uint8,AUTOMATIC) chToCopy = 0;
  VAR(uint8,AUTOMATIC) chRest = Size;
  VAR(uint8,AUTOMATIC) chSrcIdx = 0;

  if (FRTP_CHANNEL.pBuffer != 0) {
    avail = (FrTpSizeType)(FRTP_CHANNEL.pBuffer->SduLength -
                           FRTP_CHANNEL.Chn.Rx.WriteIdx);

    chToCopy = (uint8)FRTP_MIN(avail, (uint16)Size);
    chRest = (uint8)(Size - chToCopy);
    chSrcIdx = 0;
    /*
     * FrTp_MemCpy returns the destination pointer which is not used in this
     * case, so the return value is casted to (void)
     */
    if (chToCopy != 0) {
      (void)FrTp_MemCpy( &FRTP_CHANNEL.pBuffer->SduDataPtr
      [FRTP_CHANNEL.Chn.Rx.WriteIdx], &(pSrc[chSrcIdx]), (uint16)chToCopy);
      FRTP_CHANNEL.Chn.Rx.WriteIdx += (FrTpSizeType)chToCopy;
    }
  }

  /*
   * Is there a rest to copy? Beware: Badly implemented
   * application layers can introduce many loops here
   */
  while (chRest != 0) {
    BufReq_ReturnType status;
    VAR(uint8,AUTOMATIC) lConIdx= FRTP_CHANNEL.ConIdx;

    chSrcIdx += chToCopy;

    /*
     * Acquire new data buffer from application layer
     */

    status=PduR_FrTpProvideRxBuffer(
    FRTP_G_CONCFG->RxSDUId,
    FRTP_CHANNEL.Length,
    &(FRTP_CHANNEL.pBuffer));

    if (BUFREQ_OK != status) {
      /*
       * Ensure that pBuffer is invalid
       */
      FRTP_CHANNEL.pBuffer = NULL_PTR;
      /* Deviation MISRA-2 */
      return status;
    }

    if ((NULL_PTR == FRTP_CHANNEL.pBuffer) || (0U
        == FRTP_CHANNEL.pBuffer->SduLength)) {
      /* Deviation MISRA-2 */
      return BUFREQ_E_NOT_OK;

    }

    /*
     * new Buffer, reset write index
     */
    FRTP_CHANNEL.Chn.Rx.WriteIdx = 0;

    /*
     * Data amount that must be copied, remaining data
     */
    chToCopy = (uint8)FRTP_MIN(
        (FrTpSizeType)chRest,
        FRTP_CHANNEL.pBuffer->SduLength);

    chRest = chRest - chToCopy;
    /*
     * FrTp_MemCpy returns the destination pointer which is not used in this
     * case, so the return value is casted to (void)
     */
    if (chToCopy != 0) {
      (void)FrTp_MemCpy( &FRTP_CHANNEL.pBuffer->SduDataPtr
      [FRTP_CHANNEL.Chn.Rx.WriteIdx], &(pSrc[chSrcIdx]), (uint16)chToCopy);
      FRTP_CHANNEL.Chn.Rx.WriteIdx += (FrTpSizeType)chToCopy;
    }
  }

  /* Deviation MISRA-2 */
  return BUFREQ_OK;
}

/*
 * ----------------------------------------------------------------------------
 */

#if (FRTP_TX_BUFFER_REQUEST_ZERO == STD_ON)
_STATIC_
FUNC(BufReq_ReturnType,FRTP_CODE) FrTp_RetrievePayload(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    FrTpSizeType Length) {
  VAR(BufReq_ReturnType,AUTOMATIC) status;
  VAR(FrTpSizeType,AUTOMATIC) ntoCopy;

  /*
   * Following conditions must hold
 */
  if ((FRTP_CHANNEL.Chn.Tx.BufReqTimeout == 0U)
      || (((sint16)FRTP_CHANNEL.Chn.Tx.BufReqTimeout
              > FRTP_CHANNEL.Chn.Tx.Timeout)
          && (((sint16)FRTP_CHANNEL.Chn.Tx.BufReqTimeout
                  - FRTP_CHANNEL.Chn.Tx.Timeout)
              > (sint16)FRTP_TIMEOUTBUFREQ))) {

     /*
     * Check, if there are some bytes remaining
     */
    ntoCopy= FRTP_MIN((FrTpSizeType)FRTP_CHANNEL.nApplBufRemain,
        (FrTpSizeType)Length);
    /*
     * FrTp_MemCpy returns the destination pointer which is not used in this
     * case, so the return value is casted to (void)
     */
    if (ntoCopy >0) {
      (void)FrTp_MemCpy(
          &FRTP_CHANNEL.RetryBuffer.SduDataPtr[0],
          &(FRTP_CHANNEL.pAppBuffer->SduDataPtr
              [FRTP_CHANNEL.pAppBuffer->SduLength-FRTP_CHANNEL.nApplBufRemain]),
           ntoCopy);
      FRTP_CHANNEL.RetryBuffer.SduLength=ntoCopy;

      FRTP_CHANNEL.nApplBufRemain = FRTP_CHANNEL.nApplBufRemain - ntoCopy;
    }

    /*
     * It is time to acquire data from application layer, or even no buffer
     * has been requested till now
     */
    status = BUFREQ_OK;
    while (((status == BUFREQ_OK) && (FRTP_CHANNEL.RetryBuffer.SduLength < Length)))
    {
      /*
       * Connection Index ConIdx can be used as SDU, because the Index in the
       * Connection Table equals to the TxSDUId
       */
      status = PduR_FrTpProvideTxBuffer(
          FRTP_CHANNEL.ConIdx,
          &(FRTP_CHANNEL.pAppBuffer),
          0
      );

      if (BUFREQ_E_BUSY == status) {
        --FRTP_CHANNEL.Chn.Tx.BufReqCounter;

        if (FRTP_CHANNEL.Chn.Tx.BufReqCounter > 0) {
          /*
           * Reset the timeout counter for next buffer request
           * to current timeout counter
           */
          FRTP_CHANNEL.Chn.Tx.BufReqTimeout = (uint16)
          FRTP_CHANNEL.Chn.Tx.Timeout;

	  /* Deviation MISRA-2 */
          return BUFREQ_E_BUSY;
        } else {
          /*
           * Maximum number of requests exceeded.
           */
	  /* Deviation MISRA-2 */
          return BUFREQ_E_NOT_OK;
        }
      }

      /* Is the handed over data valid? */

      if ((NULL_PTR == FRTP_CHANNEL.pAppBuffer)
          || (BUFREQ_E_NOT_OK == status)) {
	/* Deviation MISRA-2 */
        return BUFREQ_E_NOT_OK;
      }
      /*
       * Reset the remaining amount in the buffer
       */
      FRTP_CHANNEL.nApplBufRemain = (FrTpSizeType) FRTP_CHANNEL.pAppBuffer->SduLength;

      /* Calculate the number of byte to fill in the buffer */
      ntoCopy= FRTP_MIN((FrTpSizeType)(FRTP_CHANNEL.pAppBuffer->SduLength),
          (FrTpSizeType)(Length - FRTP_CHANNEL.RetryBuffer.SduLength));

      /* copy the data into the retry buffer
       * FrTp_MemCpy returns the destination pointer which is not used in this
       * case, so the return value is casted to (void)
       */
      (void)FrTp_MemCpy(
          &FRTP_CHANNEL.RetryBuffer.SduDataPtr[FRTP_CHANNEL.RetryBuffer.SduLength],
          &(FRTP_CHANNEL.pAppBuffer->SduDataPtr[0]),
          ntoCopy);

      /* Add the length to the retry buffer */
      FRTP_CHANNEL.RetryBuffer.SduLength+=ntoCopy;

      /*
       * Are there some Bytes left in the Application Buffer
       * Store the amont
       */
      FRTP_CHANNEL.nApplBufRemain -= ntoCopy;

    }
    FRTP_CHANNEL.pBuffer = &(FRTP_CHANNEL.RetryBuffer);
    /*
     * Reset the read index and counters here. if the call
     * was successful, this is necessary. if it was not
     * successful, the transaction will be cancelled
     */
    FRTP_CHANNEL.Chn.Tx.ReadIdx = 0;
    FRTP_CHANNEL.Chn.Tx.BufReqTimeout = 0;
    FRTP_CHANNEL.Chn.Tx.BufReqCounter = FRTP_COUNTBUFREQ;
    /* Deviation MISRA-2 */
    return status;

  } else {
    /* Deviation MISRA-2 */
    return BUFREQ_E_BUSY;
  }
}

#else
_STATIC_
FUNC(BufReq_ReturnType,FRTP_CODE) FrTp_RetrievePayload(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    VAR(FrTpSizeType,AUTOMATIC) Length)
{
  VAR(BufReq_ReturnType,AUTOMATIC) status;

  if ((FRTP_CHANNEL.Chn.Tx.BufReqTimeout == 0U)
      || (((sint16)FRTP_CHANNEL.Chn.Tx.BufReqTimeout
          > FRTP_CHANNEL.Chn.Tx.Timeout)
          && (((sint16)FRTP_CHANNEL.Chn.Tx.BufReqTimeout
              - FRTP_CHANNEL.Chn.Tx.Timeout) > (sint16)FRTP_TIMEOUTBUFREQ))) {
    /*
     * It is time to acquire data from application layer
     */

    /*
     * Connection Index ConIdx can be used as SDU, because the Index in the
     * Connection Table equals to the TxSDUId
     */
    status = PduR_FrTpProvideTxBuffer(
    FRTP_CHANNEL.ConIdx,
    &(FRTP_CHANNEL.pBuffer),
    Length);
    if (BUFREQ_E_BUSY == status) {
      --FRTP_CHANNEL.Chn.Tx.BufReqCounter;

      if (FRTP_CHANNEL.Chn.Tx.BufReqCounter > 0) {
        /*
         * Reset the timeout counter for next buffer request
         * to current timeout counter
         */
        FRTP_CHANNEL.Chn.Tx.BufReqTimeout = (uint16)
        FRTP_CHANNEL.Chn.Tx.Timeout;

	/* Deviation MISRA-2 */
        return BUFREQ_E_BUSY;
      } else {
        /*
         * Maximum number of requests exceeded.
         */
	/* Deviation MISRA-2 */
        return BUFREQ_E_NOT_OK;
      }
    }
    /*
     * Is the handed over data valid?
     */
    if ((BUFREQ_E_NOT_OK == status)
         ||((NULL_PTR == FRTP_CHANNEL.pBuffer)
        || (FRTP_CHANNEL.pBuffer->SduLength < Length))) {
      /* Deviation MISRA-2 */
      return BUFREQ_E_NOT_OK;
    }
    /*
     * Reset the read index and counters here. if the call
     * was successful, this is necessary. if it was not
     * successful, the transaction will be cancelled
     */
    FRTP_CHANNEL.Chn.Tx.ReadIdx = 0;
    FRTP_CHANNEL.Chn.Tx.BufReqTimeout = 0;
    FRTP_CHANNEL.Chn.Tx.BufReqCounter = FRTP_COUNTBUFREQ;
    /* Deviation MISRA-2 */
    return status;

  } else {
    /* Deviation MISRA-2 */
    return BUFREQ_E_BUSY;
  }
}
#endif
/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(sint8,FRTP_CODE) FrTp_CheckCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData) {
  /*
   * How many bytes are still to be received?
   */
  VAR(FrTpSizeType,AUTOMATIC) DataToRcv=
        FRTP_CHANNEL.Length -
  FRTP_CHANNEL.Chn.Rx.ReceivedBytes;

  /*
   * Is the frame index the expected one?
   */
  if (pData->PCI.FrameIndex != FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex) {
    /* Deviation MISRA-2 */
    return -1;
  }

  /*
   * Is the frame size the expected one? (check padding)
   */
  if (DataToRcv <= (FrTpSizeType)FRTP_CF_DATA_SIZE(FRTP_CHANNEL.PduSize)) {
    /*
     * Last CF: May be at most data_to_rcv or (data_to_rcv + 1)
     * (padding byte for uneven data lengths)
     */

    /* Framesize cannot be checked, because FrIf does not indicate the
     * length of the PDU!!
     * So this check is deactivated for ASR-BMWTp

     if ((((FrTpSizeType)pData->DataSize) != DataToRcv)
     && (((FrTpSizeType)pData->DataSize) != (DataToRcv + 1U))) {
     return -1;
     }
     */
  } else {
    /*
     * Data size must match the FRTP_CF_DATA_SIZE
     */

    if (pData->DataSize != FRTP_CF_DATA_SIZE(FRTP_CHANNEL.PduSize)) {
      /* Deviation MISRA-2 */
      return -1;
    }
  }

  /*
   * CF is OK
   */
  /* Deviation MISRA-2 */
  return 0;
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_HandleCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  VAR(uint8,AUTOMATIC) bRxComplete = 0;
  VAR(uint8,AUTOMATIC) chExpDataBytes = (uint8) FRTP_MIN(
      (FrTpSizeType)(FRTP_CHANNEL.Length -
          FRTP_CHANNEL.Chn.Rx.ReceivedBytes),
      (FrTpSizeType)(FRTP_CF_DATA_SIZE(
              FRTP_CHANNEL.PduSize)));
  /*
   * Count numbers of received CFs since last Flow Control Frame
   */
  ++FRTP_CHANNEL.Chn.Rx.CFsSinceFC;

  /*
   * Remember that we have received a CF since the transmission
   * of a Flow Control Frame
   */
  FRTP_CHANNEL.Chn.Rx.CFsReceivedSinceFC = 1;

  if (FRTP_CHANNEL.Chn.Rx.ErrFrameIndex == -1) {
    /*
     * Currently, CFs are consistent, perform check on this one
     */
    VAR(sint8,AUTOMATIC) cStatus = FrTp_CheckCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        lChnIdx,
#endif
        pData);

    if (cStatus < 0) {
      /*
       * Remember Frame Index where the error occurred and rx bytes
       */
      FRTP_CHANNEL.Chn.Rx.ErrFrameIndex =
      (sint8)FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex;

      /*
       * Compare the erroneous frame index to the previous one
       */
      if (FRTP_CHANNEL.Chn.Rx.ErrFrameIndex ==
      FRTP_CHANNEL.Chn.Rx.ErrFrameIndexPrevBlock) {
        ++FRTP_CHANNEL.Chn.Rx.ErrorCounter;
      } else {
        /*
         * Reset Error Counter
         */
        FRTP_CHANNEL.Chn.Rx.ErrorCounter = 1;
      }
    } else {
      /*
       * Correct CF detected, try to copy data
       */
      BufReq_ReturnType status = FrTp_HandleDataFrame(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
          lChnIdx,
#endif
          pData->pData, chExpDataBytes);

      if (BUFREQ_OK != status) {
        /*
         * The necessary data buffer was not provided.
         * Mark channel to send a CREF:
         */
        FRTP_CHANNEL.Chn.Rx.ErrFrameIndex = FRTP_BS_CREF;
      }
    }
  }

  /*
   * Update "Last CF Data Bytes" field if the very last CF should
   * contain less than "CF data bytes" payload bytes
   */

  if (chExpDataBytes < (uint8)FRTP_CF_DATA_SIZE(
      FRTP_CHANNEL.PduSize)) {
    FRTP_CHANNEL.Chn.Rx.LastCFDataBytes =
    chExpDataBytes;
  }

  /*
   * Update Read Bytes counter here and next expected SN (in any case)
   */
  FRTP_CHANNEL.Chn.Rx.ReceivedBytes += (FrTpSizeType)chExpDataBytes;

  FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex = (uint8)
  FRTP_NEXTSN(FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex);

  /*
   * Is this the very last consecutive frame?
   */
  if (FRTP_CHANNEL.Chn.Rx.ReceivedBytes >=
  FRTP_CHANNEL.Length) {
    bRxComplete = 1;
  }

  /*
   * Send an Acknowledge if the block size has been reached,
   * or the final CF has been received
   */

  if ((bRxComplete != 0) || (FRTP_CHANNEL.Chn.Rx.CFsSinceFC ==
  FRTP_CHANNEL.BSMax)) {
    /*
     * Has the previous block been received correctly?
     */

    if (FRTP_CHANNEL.Chn.Rx.ErrFrameIndex == -1) {

      /*
       * Determine transmission mode: Group Addressing
       * Single Component Addressing (Flow Control / Non FC)
       */

      if (bRxComplete != 0) {

        FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_ACK;

      } else {
        FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_CTS;

        FRTP_CHANNEL.Chn.Rx.CFsSinceFC = 0;
      }
    } else /* block completed, an error ocurred within */
    {

      {
        VAR(uint8,AUTOMATIC) CFResends;
        VAR(FrTpSizeType,AUTOMATIC) CFRollback;
        /*
         * Channel has been marked to send a CREF:
         * Send the CREF and free the Channel afterwards
         * Ignoring return value, because if sending of the FC_CREF fails
         * no further actions can be done in next cycle, because channel well
         * be freed.
         */
        if (FRTP_CHANNEL.Chn.Rx.ErrFrameIndex == (FRTP_BS_CREF)) {
          (void)FrTp_SendFC(
              (FrTpChannelIndexType)FRTP_NOCHANNEL,
              FRTP_CHANNEL.ConIdx,
              pData->AddrInfo.Addr.Tgt,
              pData->AddrInfo.Addr.Src,
              FRTP_FC_CREF);
          FRTP_RELRXCHNWITHSTATUS(
              NTFRSLT_E_NOT_OK
          );

	  /* Deviation MISRA-2 */
          return;
        }
        /*
         * Calc Frames to resend, calc bytes to rollback
         */
        CFResends = FRTP_CFRESENDS(
            FRTP_PREVSN(
                FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex),
            FRTP_CHANNEL.Chn.Rx.ErrFrameIndex);

        CFRollback = (FrTpSizeType) FRTP_ROLLBACK(
            CFResends,
            FRTP_CF_DATA_SIZE(
                FRTP_CHANNEL.PduSize),
            FRTP_CHANNEL.Chn.Rx.LastCFDataBytes);

        /*
         * Issue a NACK Frame, reset values for retransmission.
         */

        FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_NACK;
        FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex =
        (uint8)FRTP_CHANNEL.Chn.Rx.ErrFrameIndex;
        FRTP_CHANNEL.Chn.Rx.ReceivedBytes = (FrTpSizeType)
        (FRTP_CHANNEL.Chn.Rx.ReceivedBytes - CFRollback);
        FRTP_CHANNEL.Chn.Rx.CFsSinceFC -= (sint8)CFResends;

        FRTP_CHANNEL.Chn.Rx.Timeout = (sint16) FRTP_TIMEOUTCOMMON;
      }
    }
  } else /* block/transmission did not end */
  {
    /*
     * Check if an illegal CF has been received in non FC mode.
     * if this is the , jump to the abort state immediately
     */
    {
      /*
       * CF received, update timeout
       */
      FRTP_CHANNEL.Chn.Rx.Timeout = (sint16)FRTP_TIMEOUTCFCF;
    }
  }
  /* Deviation MISRA-2 */
}

_STATIC_
FUNC(Std_ReturnType,FRTP_CODE) FrTp_ExtractData(
    P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) pbuf,
    VAR(uint8,AUTOMATIC) nLen,
    P2VAR(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pdata) {
  VAR(uint8,AUTOMATIC) c_tl_ft;
  VAR(uint8,AUTOMATIC) c_tl_fst;


  /* Init frame data structure */

  pdata->MasTypeID = pbuf[FRTP_MAS_TI_INDEX];

  /*
   * At first: Enter sender and receive address for error analysis
   * at higher levels
   */
  pdata->AddrInfo.Addr.Tgt = pbuf[FRTP_TGT_INDEX];
  pdata->AddrInfo.Addr.Src = pbuf[FRTP_SRC_INDEX];

  c_tl_ft = (uint8)(pbuf[FRTP_FT_INDEX] & FRTP_FT_MASK);
  c_tl_fst = (uint8)(pbuf[FRTP_FT_INDEX] & FRTP_FST_MASK);

  switch (c_tl_ft) {
  case FRTP_FT_SF:
    /* Subtype must be zero in this case */
    if (((c_tl_fst != 0)) || (nLen < (uint8)(FRTP_SF_MIN_DATA_SIZE))) {
      /* Deviation MISRA-2 */
      return E_NOT_OK;
    }
    pdata->FrameType = FRTP_SF;
    pdata->PCI.Length = pbuf[FRTP_DL_INDEX];
    if ((uint8)(nLen - (uint8)(FRTP_HSIZE_SF)) < pdata->PCI.Length) {
      /* Deviation MISRA-2 */
      return E_NOT_OK;
    }
    pdata->pData = &(pbuf[FRTP_HSIZE_SF]);
    pdata->DataSize = pbuf[FRTP_DL_INDEX];
    break;

  case FRTP_FT_FF:

    pdata->FrameType = FRTP_FF;

    if (FRTP_FST_FF1B == c_tl_fst) {
      /* One byte size encoding */
      if (nLen < (uint8)(FRTP_FF1B_MIN_DATA_SIZE)) {
	/* Deviation MISRA-2 */
        return E_NOT_OK;
      }
      pdata->PCI.Length = (FrTpSizeType)(pbuf[FRTP_DL_INDEX]);
      pdata->pData = &(pbuf[FRTP_HSIZE_FF1B]);
      pdata->DataSize = (uint8)(nLen - (uint8)(FRTP_HSIZE_FF1B));
    } else if (FRTP_FST_FF2B == c_tl_fst) {
      /* Two byte size encoding */
      if (nLen < (uint8)(FRTP_FF2B_MIN_DATA_SIZE)) {
	/* Deviation MISRA-2 */
        return E_NOT_OK;
      }

      /*
       * Endianess-independent extraction
       */
      pdata->PCI.Length = ((FrTpSizeType)(((FrTpSizeType)pbuf[FRTP_DLH_INDEX]) << 8U)) | 
                          ((FrTpSizeType)pbuf[FRTP_DLL_INDEX]);

      pdata->pData = &(pbuf[FRTP_HSIZE_FF2B]);
      pdata->DataSize = (uint8)(nLen - (uint8)(FRTP_HSIZE_FF2B));
    } else if (FRTP_FST_FF3B == c_tl_fst) {
      /* Three byte size encoding */
      if (nLen < (uint8)(FRTP_FF3B_MIN_DATA_SIZE)) {
	/* Deviation MISRA-2 */
        return E_NOT_OK;
      }

      /*
       * Endianess-independent extraction
       *
       * High Byte is not used in SC6
       * ((FrTpSizeType)pbuf[FRTP_DL3BH_INDEX]) << 16) |
       * FrTpSizeType is uint16!
       */
      if (pbuf[FRTP_DL3BH_INDEX] >0) {
	/* Deviation MISRA-2 */
        return E_NOT_OK;
      }
      pdata->PCI.Length = ((FrTpSizeType)(((FrTpSizeType)pbuf[FRTP_DL3BM_INDEX]) << 8U)) | 
                          ((FrTpSizeType)pbuf[FRTP_DL3BL_INDEX]);

      pdata->pData = &(pbuf[FRTP_HSIZE_FF3B]);
      pdata->DataSize = (uint8)(nLen - (uint8)(FRTP_HSIZE_FF3B));
    } else {
      /* Deviation MISRA-2 */
      return E_NOT_OK;
    }
    break;

  case FRTP_FT_CF:
    if (nLen < (uint8)(FRTP_CF_MIN_DATA_SIZE)) {
      /* Deviation MISRA-2 */
      return E_NOT_OK;
    }
    pdata->FrameType = FRTP_CF;
    pdata->PCI.FrameIndex = (uint8)(pbuf[FRTP_SN_INDEX] & FRTP_CFSN_MASK);
    pdata->pData = &(pbuf[FRTP_HSIZE_CF]);
    pdata->DataSize = (uint8)(nLen - (uint8)(FRTP_HSIZE_CF));
    break;

  case FRTP_FT_FC:
    switch (c_tl_fst) {
    /* Flow Control: Clear to send */
    case FRTP_FT_FCCTS:
      if (nLen < (uint8)(FRTP_FC_CTS_DATA_SIZE)) {
	/* Deviation MISRA-2 */
        return E_NOT_OK;
      }
      pdata->FrameType = FRTP_FC_CTS;
      pdata->PCI.FC.BSMax = pbuf[FRTP_BS_INDEX];
      pdata->PCI.FC.BC = pbuf[FRTP_BC_INDEX];
      break;

      /* Flow Control: Wait */
    case FRTP_FT_FCWT:

      pdata->FrameType = FRTP_FC_WT;
      break;

      /* Flow Control: Connection refused */
    case FRTP_FT_FCCREF:

      pdata->FrameType = FRTP_FC_CREF;
      break;

      /* Flow Control: Negative acknowledge */
    case FRTP_FT_FCNACK:
      if (nLen < (uint8)(FRTP_FC_NACK_DATA_SIZE)) {
	/* Deviation MISRA-2 */
        return E_NOT_OK;
      }
      pdata->FrameType = FRTP_FC_NACK;
      pdata->PCI.FrameIndex = (uint8)(pbuf[FRTP_NACKSN_INDEX]
          & FRTP_NACKSN_MASK);
      break;

      /* Flow Control: Acknowledge */
    case FRTP_FT_FCACK:

      pdata->FrameType = FRTP_FC_ACK;
      break;

    default:
      /* Illegal FC frame type encountered */
      /* Deviation MISRA-2 */
      return E_NOT_OK;
    }
    break;

  default:
    /* Illegal frame type encountered */
    /* Deviation MISRA-2 */
    return E_NOT_OK;
  }

  /*
   * perform consistency checks after copying data since the api
   * layers might need the data even of inconsistent frames
   */
  /* Only component-adressing of receiver(s) supported */
  if ((pdata->MasTypeID  != FRTP_AT_SC )  && 
     (pdata->MasTypeID != FRTP_AT_GC )) 
  {
    /* Deviation MISRA-2 */
    return E_NOT_OK;
  }
  /* Deviation MISRA-2 */
  return E_OK;
}

/*
 * State Machine functions
 */

/*
 * --- Unsegmented Data Transfer Tx -------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_u_w4_tx_sf(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData) {
  BufReq_ReturnType status;
  /*
   * The necessary data must be provided here for the whole
   * SF
   */
  status = FrTp_RetrievePayload(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
      lChnIdx,
#endif
      FRTP_CHANNEL.Length);

  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);

  if (BUFREQ_E_NOT_OK == status) {
    FRTP_RELTXCHNWITHSTATUS(
        NTFRSLT_E_NO_BUFFER);
  } else if (BUFREQ_OK == status) {
    VAR(sint8,AUTOMATIC) nRet = FrTp_SendDF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        lChnIdx,
#endif
        FrTp_GetTxPDUIdx(FRTP_CHANNEL.ConIdx),
        FRTP_SF, (uint8)FRTP_CHANNEL.Length);

    if (nRet >= 0) {
      /*
       * do not reset timeout counter: The SF is not yet sent!
       */

      FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_FFSF_NOTIF;
    }
  } else {
    /*
     * FRTP_E_BUSY: do nothing. Wait until timeout expires or maximum
     * buffer request count exceeded
     */
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_u_w4_tx_sf_n(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData) {
    /*
     * Avoid warnings about unused param
     */
#if (FRTP_DEV_ERROR_DETECT == STD_OFF)
  FRTP_UNUSED(pData);
#endif

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (FRTP_SF == pData->FrameType)
#endif
  {
    VAR(uint8,AUTOMATIC) bUseFC= (uint8) FRTP_USEFC(FRTP_CHANNEL.Info.MasTypeID);


    if (bUseFC != 0) {
      /*
       * Reset Timeout Counter
       */
      FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)
      FRTP_TIMEOUTCOMMON;

      FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_RX_ACK;
    } else {
      FRTP_RELTXCHNWITHSTATUS(
          NTFRSLT_OK
      );
    }
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  } else {
    FrTp_Det_ReportError( CHNIDX,
        FRTP_TXSTATEMACHINE_SERVICE_ID,
        FRTP_E_NO_CHANNEL);
#endif
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_u_w4_rx_ack(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData) {

  /*
   * According to Tp ISO Spec: Ignore anything than the expected ACK frame
   */
  switch (pData->FrameType) {
  case FRTP_FC_ACK:
    /*
     * Notify application, release channel
     */
    FRTP_RELTXCHNWITHSTATUS(
        NTFRSLT_OK
    );
    break;
  case FRTP_FC_CREF:
    FRTP_RELTXCHNWITHSTATUS(
        NTFRSLT_E_NO_BUFFER
    );
    break;
  case FRTP_SF:
  case FRTP_FF:
  case FRTP_CF:
  case FRTP_FC_CTS:
  case FRTP_FC_WT:
  case FRTP_FC_NACK:
  default:
    /* do nothing */
    break;
  }
}

/*
 * Segmented Data Transfer Tx -------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_s_w4_tx_ff(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  VAR(BufReq_ReturnType,AUTOMATIC) status;
  /*
   * Enough data must be available: schedule first frame
   */
  VAR(uint8,AUTOMATIC) FFDataSize = (uint8) FRTP_FF_DATA_SIZE(
      (FrTpSizeType)FRTP_CHANNEL.PduSize,
      FRTP_CHANNEL.Length);

  /*
   * Acquire data from application layer
   */
  status = FrTp_RetrievePayload(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
      lChnIdx,
#endif
      (FrTpSizeType)FFDataSize);

  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);

  if (BUFREQ_E_NOT_OK == status) {
    FRTP_RELTXCHNWITHSTATUS(
        NTFRSLT_E_NO_BUFFER
    );
  } else if (BUFREQ_OK == status) {
    VAR(sint8, AUTOMATIC) nRet = FrTp_SendDF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        lChnIdx,
#endif
        FrTp_GetTxPDUIdx(FRTP_CHANNEL.ConIdx),
        FRTP_FF, FFDataSize);

    if (nRet >= 0) {
      FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_FFSF_NOTIF;

      /*
       * Update sent byte amount, next frame index for CF
       */
      FRTP_CHANNEL.Chn.Tx.SentBytes = FFDataSize;
      FRTP_CHANNEL.Chn.Tx.ReadIdx = FFDataSize;
      FRTP_CHANNEL.Chn.Tx.NextFrameIndex = (sint8)FRTP_FIRST_CF_IDX;
    }
  } else {
    /*
     * FRTP_E_BUSY: do nothing. Wait until the next request
     * for a Tp buffer
     */
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_s_w4_tx_ff_n(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
#if (FRTP_DEV_ERROR_DETECT == STD_OFF)
  FRTP_UNUSED(pData);
#endif
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (FRTP_FF == pData->FrameType) {
#endif

    /*
     * Reset Timeout Counter
     */
    FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)
    FRTP_TIMEOUTCOMMON;

    /*
     * State Transision depending on kind of addressing mode
     * with or w/o Flow Control
     */
    FRTP_CHANNEL.Chn.Tx.State =
    FRTPSM_W4_RX_CTS;

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  } else {
    FrTp_Det_ReportError( CHNIDX,
        FRTP_TXSTATEMACHINE_SERVICE_ID,
        FRTP_E_UNEXP_STATE_EVENT);
  }
#endif
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_s_w4_rx_cts(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  switch (pData->FrameType) {
  case FRTP_FC_CTS:
    /*
     * Get Block Size, Bandwidth Control params
     */
    FRTP_CHANNEL.BSMax = pData->PCI.FC.BSMax;

    /* BS_MAX is maximum value of SN field in CF: 0x0f */
    if ((pData->PCI.FC.BSMax == 0) || (pData->PCI.FC.BSMax > (FRTP_BS_MAX + 1))) {
      /*
       * Ignore the frame with invalid params
       */
    } else {
      /* blocksize OK, get the rest */
      if ((pData->PCI.FC.BC & FRTP_BC_SC_FILTER) == 0) {
        /*
         * At most FRTP_BC_SCMAX separation cycles are necessary
         */
        FRTP_CHANNEL.BC =
        FRTP_MIN(pData->PCI.FC.BC, (uint8)FRTP_BC_SCMAX);
      } else {
        FRTP_CHANNEL.BC = pData->PCI.FC.BC;
      }
      FRTP_CHANNEL.BSMax = pData->PCI.FC.BSMax;
      FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_CF;
      FRTP_CHANNEL.Chn.Tx.CFsSinceFC = 0;
      FRTP_CHANNEL.Chn.Tx.CFsWaitCtr = 0;
      FRTP_CHANNEL.pBuffer = NULL_PTR;
#if (FRTP_TX_BUFFER_REQUEST_ZERO == STD_ON)
      FRTP_CHANNEL.RetryBuffer.SduLength = 0;
#endif
      /*
       * reset error index, retry counter as this data
       * block got through completely
       */
      FRTP_CHANNEL.Chn.Tx.ErrFrameIndex = -1;
      FRTP_CHANNEL.Chn.Tx.ErrorCounter = 0;

      FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)
      FRTP_TIMEOUTCOMMON;
    }
    break;

  case FRTP_FC_NACK: {
    /*
     * Process NACK data, reset data back to erroneous frame
     */
    VAR(sint8,AUTOMATIC) StatusProcNACK = FrTp_ProcessNACK(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        lChnIdx,
#endif
        pData->PCI.FrameIndex);

    if (StatusProcNACK == 0) {
      FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_CF;
      FRTP_CHANNEL.Chn.Tx.Timeout = (sint16) FRTP_TIMEOUTCOMMON;
    } else if (StatusProcNACK == -1) {
      FRTP_RELTXCHNWITHSTATUS(
          NTFRSLT_E_NOT_OK
      );
    } else {
      /*
       * The NACK provided an invalid SN. Ignore it
       */
    }
  }
    break;

  case FRTP_FC_WT: {
    /*
     * Maximum number of WTs received?
     */
    if (FRTP_CHANNEL.Chn.Tx.WTCounter < FRTP_MAX_WTS) {
      /*
       * Reset Timeout
       */
      ++FRTP_CHANNEL.Chn.Tx.WTCounter;
      FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)FRTP_TIMEOUTCOMMON;
    }
  }
    break;

  case FRTP_FC_CREF:
    FRTP_RELTXCHNWITHSTATUS(
        NTFRSLT_E_NO_BUFFER
    );
    break;
  case FRTP_CF:
  case FRTP_SF:
  case FRTP_FF:
  case FRTP_FC_ACK:
  default:
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError( CHNIDX,
        FRTP_TXSTATEMACHINE_SERVICE_ID,
        FRTP_E_UNEXP_STATE_EVENT);
#endif
    break;
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_s_w4_rx_nack(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Only a NACK is admissible with turned on flow control
   */
  if ((FRTP_FC_NACK == pData->FrameType)) {
    VAR(sint8,AUTOMATIC) StatusProcNACK = FrTp_ProcessNACK(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        lChnIdx,
#endif
        pData->PCI.FrameIndex);

    if (StatusProcNACK == 0) {
      FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_CF;
      FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)FRTP_TIMEOUTCOMMON;
    } else if (StatusProcNACK == -1) {
      FRTP_RELTXCHNWITHSTATUS(
          NTFRSLT_E_NOT_OK
      );
    } else {
      /*
       * The NACK provided an invalid SN. Ignore it
       */
    }
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_s_w4_tx_cf(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  VAR(FrTpSizeType,AUTOMATIC) amnt;
  VAR(BufReq_ReturnType,AUTOMATIC) status = BUFREQ_OK;
  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);
  /*
   * Calculate necessary data: minimum of
   *   - amount left to send
   *   - amount that may be sent within one block
   */
  amnt = (FrTpSizeType) FRTP_MIN((FRTP_CHANNEL.Length -
          FRTP_CHANNEL.Chn.Tx.SentBytes),
      (FrTpSizeType)(FRTP_CF_DATA_SIZE(
              FRTP_CHANNEL.PduSize)) *
      (FrTpSizeType)(FRTP_CHANNEL.BSMax));

  if ((NULL_PTR == FRTP_CHANNEL.pBuffer)) {
    /*
     * Acquire data from application layer
     */
    status = FrTp_RetrievePayload(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        lChnIdx,
#endif
        amnt

        );

    if (BUFREQ_E_NOT_OK == status) {
      FRTP_RELTXCHNWITHSTATUS(
          NTFRSLT_E_NO_BUFFER
      );
    }
  }

  /*
   * Wait for the previous bulk to be transmitted completely
   */

  if ((FRTP_CHANNEL.Chn.Tx.CFsWaitCtr == 0)
      && (BUFREQ_OK == status)) {
    /*
     * process next bulk
     */
    FrTp_ProduceCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    lChnIdx
#endif
    );
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_s_w4_tx_cf_n(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);

  if (FRTP_CHANNEL.Chn.Tx.CFsWaitCtr > 0) {
    /*
     * Has the previous bulk been transmitted successfully?
     */
    --FRTP_CHANNEL.Chn.Tx.CFsWaitCtr;

    if (FRTP_CHANNEL.Chn.Tx.CFsWaitCtr == 0) {
      /*
       * Has the whole data been sent completely?
       */
      if (FRTP_CHANNEL.Chn.Tx.SentBytes ==
      FRTP_CHANNEL.Length) {
        {
          FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)FRTP_TIMEOUTCOMMON;
          FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_RX_ACK;
        }

      } else if ((FRTP_CHANNEL.Chn.Tx.CFsSinceFC <
      FRTP_CHANNEL.BSMax)) {
        /*
         * No Block End reached, or no flow control necessary
         */
        FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)FRTP_TIMEOUTCOMMON;
        FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_CF;

      } else {
        /*
         * Block End reached in FC mode
         */
        FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_RX_CTS;
        FRTP_CHANNEL.Chn.Tx.Timeout = (sint16) FRTP_TIMEOUTCOMMON;
      }
    } else {
      /*
       * Reset Timeout since a CF was successfully sent, but
       * the bulk has not been sent completely
       */
      FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)FRTP_TIMEOUTCFCF;
    }
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  } else {
    FrTp_Det_ReportError( CHNIDX,
        FRTP_TXSTATEMACHINE_SERVICE_ID,
        FRTP_E_ASSERT);
#endif
  }

}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Consume_CFs(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);

  /*
   * Consume the CFs so that the state machine can
   * resume the transmission after all pending CFs have been
   * sent
   */
  if (FRTP_CHANNEL.Chn.Tx.CFsWaitCtr > 0) {
    --FRTP_CHANNEL.Chn.Tx.CFsWaitCtr;
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Tx_s_w4_rx_ack(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Reset the timeout in any case
   */
  switch (pData->FrameType) {
  case FRTP_FC_NACK: {
    /*
     * Process NACK data, reset data back to erroneous frame
     */
    VAR(sint8,AUTOMATIC) StatusProcNACK = FrTp_ProcessNACK(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        lChnIdx,
#endif
        pData->PCI.FrameIndex);

    if (StatusProcNACK == 0) {
      /*
       * NACK was OK, reset to erroneous frame
       */
      FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_CF;
      FRTP_CHANNEL.Chn.Tx.Timeout = (sint16)FRTP_TIMEOUTCOMMON;
    } else if (StatusProcNACK == -1) {
      /*
       * Either max retry on NACK of the same index, or internal
       * error
       */
      FRTP_RELTXCHNWITHSTATUS(
          NTFRSLT_E_NOT_OK
      );

    } else {
      /*
       * NACK with invalid params detected, ignore the NACK
       */
    }
  }
    break;

  case FRTP_FC_ACK:
    /*
     * Finish here
     */
      FRTP_RELTXCHNWITHSTATUS(
          NTFRSLT_OK
      );
    break;
  case FRTP_CF:
  case FRTP_SF:
  case FRTP_FF:
  case FRTP_FC_CTS:
  case FRTP_FC_CREF:
  case FRTP_FC_WT:
  default:
    /* unexpected frame */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError( CHNIDX,
        FRTP_TXSTATEMACHINE_SERVICE_ID,
        FRTP_E_UNEXP_STATE_EVENT);
#endif
    break;
  }
}

/*
 * Unsegmented Data Transfer Rx -----------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_u_w4_rx_sf(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  VAR(uint8,AUTOMATIC) bWithFC= (uint8) FRTP_USEFC(pData->MasTypeID);

  BufReq_ReturnType status = FrTp_HandleDataFrame(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
      lChnIdx,
#endif
      pData->pData, pData->DataSize);

  if (BUFREQ_OK == status) {
    if (bWithFC != 0) {
      FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_ACK;
    } else {

      FRTP_RELRXCHNWITHSTATUS(
          NTFRSLT_OK
      );
    }
  } else {
    /*
     * No buffer is available. Send a CREF if the
     * request was sent in SC mode
     */
    if (bWithFC != 0) {
      (void)FrTp_SendFC(
          (FrTpChannelIndexType)FRTP_NOCHANNEL,
          FRTP_CHANNEL.ConIdx,
          pData->AddrInfo.Addr.Tgt,
          pData->AddrInfo.Addr.Src,
          FRTP_FC_CREF);
    }
    FRTP_RELRXCHNWITHSTATUS(
        NTFRSLT_E_NO_BUFFER
    );
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_su_w4_tx_ack(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Answer "Acknowledge" on FlexRay side
   */
  VAR(sint8,AUTOMATIC) nRet = FrTp_SendFC(
      CHNIDX,
      FRTP_CHANNEL.ConIdx,
      FRTP_CHANNEL.Info.AddrInfo.Addr.Tgt,
      FRTP_CHANNEL.Info.AddrInfo.Addr.Src,
      FRTP_FC_ACK);

  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);

  if (nRet >= 0) {
    /*
     * switch to the "Wait for notification of ACK" state in any case
     */
    FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_ACK_NOTIF;
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_su_w4_tx_ack_n(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
#if (FRTP_DEV_ERROR_DETECT == STD_OFF)
  FRTP_UNUSED(pData);
#endif

  FRTP_UNUSED(pData);
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (FRTP_FC_ACK == pData->FrameType) {
#endif

    /*
     * Avoid warnings about unused param
     */


    FRTP_RELRXCHNWITHSTATUS(
        NTFRSLT_OK
    );

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  } else {
    FrTp_Det_ReportError( CHNIDX,
        FRTP_RXSTATEMACHINE_SERVICE_ID,
        FRTP_E_UNEXP_STATE_EVENT);
  }
#endif
}

/*
 * Segmented Data Transfer Rx -------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_tx_cts(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{

  VAR(sint8,AUTOMATIC) nRet = FrTp_SendFC(
      CHNIDX,
      FRTP_CHANNEL.ConIdx,
      FRTP_CHANNEL.Info.AddrInfo.Addr.Tgt,
      FRTP_CHANNEL.Info.AddrInfo.Addr.Src,
      FRTP_FC_CTS);

  if (nRet >=0) {
    FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_CTS_NOTIF;
  }
  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);

}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_tx_cts_n(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * this check is necessary because (if FC-WT transmission
   * is enabled, we could experience a FC-WT here.
   */
  if (FRTP_FC_CTS == pData->FrameType) {
    FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_RX_CF;
    FRTP_CHANNEL.Chn.Rx.Timeout = (sint16)FRTP_TIMEOUTCOMMON;

    /*
     * In the case a block got completed: Reset Error indices
     * and error counters
     */
    FRTP_CHANNEL.Chn.Rx.ErrFrameIndexPrevBlock = -1;
    FRTP_CHANNEL.Chn.Rx.ErrFrameIndex = -1;
    FRTP_CHANNEL.Chn.Rx.ErrorCounter = 0;
    FRTP_CHANNEL.Chn.Rx.CFsReceivedSinceFC = 0;
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_rx_ff(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{

  VAR(BufReq_ReturnType,AUTOMATIC) status = FrTp_HandleDataFrame(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
      lChnIdx,
#endif
      pData->pData, pData->DataSize);

  /*
   * Expected CF index must be set manually to the first one
   * here.
   */
  FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex = FRTP_FIRST_CF_IDX;
  switch (status) {
  case BUFREQ_OK:
    FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_CTS;
    FRTP_CHANNEL.Chn.Rx.ReceivedBytes += (FrTpSizeType)pData->DataSize;
    break;
  case BUFREQ_E_BUSY:

#if (FRTP_SUPPORT_TXWAIT == STD_ON)
    FRTP_CHANNEL.Chn.Rx.WTCtr = (FRTP_MAX_WTS * 2);
    FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_WT;
    /*setup counter for next bufferrequest*/
    FRTP_CHANNEL.Chn.Rx.WTBufReqTimeout =
      (uint16) (FRTP_CHANNEL.Chn.Rx.Timeout - FRTP_TIMEOUTBUFREQ -1);
    FRTP_CHANNEL.Chn.Rx.WTBufReqCounter = FRTP_COUNTBUFREQ;

    /*
     * Store data of FF in temporary buffer, until a buffer
     * is provided by the application
     */
    FRTP_CHANNEL.Chn.Rx.FFBufDataSize =
    FRTP_MIN(
        FRTP_PDU_MAXLEN - FRTP_HSIZE_FF1B,
        pData->DataSize);
    /*
     * FrTp_MemCpy returns the destination pointer which is not used in this
     * case, so the return value is casted to (void)
     */
    (void)FrTp_MemCpy(
        FRTP_CHANNEL.Chn.Rx.FFBuffer,
        pData->pData,
        (uint16)(FRTP_CHANNEL.Chn.Rx.FFBufDataSize));
    break;
#endif /* FRTP_SUPPORT_TXWT == STD_ON */
  case BUFREQ_E_OVFL:
  case BUFREQ_E_NOT_OK:
  default:
    /*
     * No buffer is available. Send a CREF if the
     * request was sent in SC mode
     * Ignoring return value, because if sending of the FC_CREF fails
     * no further actions can be done in next cycle, because no channel
     * will be set up.
     */
    (void)FrTp_SendFC(
        (FrTpChannelIndexType)FRTP_NOCHANNEL,
        FRTP_CHANNEL.ConIdx,
        pData->AddrInfo.Addr.Tgt,
        pData->AddrInfo.Addr.Src,
        FRTP_FC_CREF);

    FRTP_RELRXCHNWITHSTATUS(
        NTFRSLT_E_NO_BUFFER
    );
    break;
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_rx_cf(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{

  if (FRTP_CF == pData->FrameType) {
    /*
     * Check consistency, change fsm state
     */
    FrTp_HandleCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    lChnIdx,
#endif
    pData);
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  } else {
    FrTp_Det_ReportError( CHNIDX,
        FRTP_RXSTATEMACHINE_SERVICE_ID,
        FRTP_E_UNEXP_STATE_EVENT);
#endif
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Rx_TimeoutCFCF(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * 0.9s timeout expired between two subsequent CFs
   */
  FRTP_UNUSED(pData);

  /*
   * Either no FC involved, or there has not yet been received one
   * single CF since the transmission of the most recent FC frame
   * -> Cancel receive operation
   */

  if (FRTP_CHANNEL.Chn.Rx.CFsReceivedSinceFC == 0)
  {
    /*
     * Cancel reception: Timeout Expired
     */

    FRTP_RELRXCHNWITHSTATUS(
        NTFRSLT_E_TIMEOUT_CR
    );
  } else {

    VAR(sint8,AUTOMATIC) status;
    /*
     * A timeout occured while waiting to complete the block, because
     * a FC-CREF should be sent. Afterwards the channel well be released.
     * Ignoring return value, because if sending of the FC_CREF fails
     * no further actions can be done in next cycle, because the channel
     * will be freed.

     */
    if (FRTP_CHANNEL.Chn.Rx.ErrFrameIndex == (FRTP_BS_CREF)) {
      (void)FrTp_SendFC(
          (FrTpChannelIndexType)FRTP_NOCHANNEL,
          FRTP_CHANNEL.ConIdx,
          FRTP_CHANNEL.Info.AddrInfo.Addr.Tgt,
          FRTP_CHANNEL.Info.AddrInfo.Addr.Src,
          FRTP_FC_CREF);
      FRTP_RELRXCHNWITHSTATUS(
          NTFRSLT_E_TIMEOUT_CR
      );
      /* Deviation MISRA-2 */
      return;
    }
    /*
     * A CFCF Timeout expired. We assume that an error occurred
     * with the transmission of the frame with the expected index
     * number if there is not already another erroneous frame.
     * Perform error handling here
     */

    if (FRTP_CHANNEL.Chn.Rx.ErrFrameIndex == -1) {
      FRTP_CHANNEL.Chn.Rx.ErrFrameIndex = (sint8)
      FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex;
    /*
     * There was no erroneos frame detected, check if the
     * error occoured in the last block at the same position.
     */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
		/*
		 * If a CFCF timeout at least one CF has to be received 
		 * and if no errorneos frame has been detected, the frame
		 * is valid and so it could not be the same as in the 
		 * previous block
		 */
    if (FRTP_CHANNEL.Chn.Rx.ErrFrameIndex ==
    FRTP_CHANNEL.Chn.Rx.ErrFrameIndexPrevBlock) {
      ++FRTP_CHANNEL.Chn.Rx.ErrorCounter;
    } else 
#endif    	
    {
      FRTP_CHANNEL.Chn.Rx.ErrorCounter = 1U;
    }

    } else {
      /*
       * Before the timeout, a different frame was detected as
       * erroneous: We have to perform a rollback
       */
      VAR(uint8,AUTOMATIC) CFResends = (uint8) FRTP_CFRESENDS(
          FRTP_PREVSN(FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex),
          FRTP_CHANNEL.Chn.Rx.ErrFrameIndex);

      FrTpSizeType CFRollback = (FrTpSizeType) FRTP_ROLLBACK(
          CFResends,
          FRTP_CF_DATA_SIZE(
              FRTP_CHANNEL.PduSize),
          FRTP_CHANNEL.Chn.Rx.LastCFDataBytes);

      FRTP_CHANNEL.Chn.Rx.ReceivedBytes =
      FRTP_CHANNEL.Chn.Rx.ReceivedBytes - CFRollback;
      FRTP_CHANNEL.Chn.Rx.CFsSinceFC -= (sint8) CFResends;

      /*
       * Update expected frame index only here;
       * in other branch it is set correctly
       */
      FRTP_CHANNEL.Chn.Rx.ExpectedFrameIndex = (uint8)
      FRTP_CHANNEL.Chn.Rx.ErrFrameIndex;
    }

    FRTP_CHANNEL.Chn.Rx.Timeout = (sint16)FRTP_TIMEOUTCOMMON;

    /*
     * try to immediately send the NACK (we are in the context
     * of the state machine function here).
     */
    status = FrTp_SendFC(
        CHNIDX,
        FRTP_CHANNEL.ConIdx,
        FRTP_CHANNEL.Info.AddrInfo.Addr.Tgt,
        FRTP_CHANNEL.Info.AddrInfo.Addr.Src,
        FRTP_FC_NACK);

    /*
     * Set the following state according to success of transmission
     */
    FRTP_CHANNEL.Chn.Rx.State =
    ((status < 0) ? FRTPSM_W4_TX_NACK : FRTPSM_W4_TX_NACK_NOTIF);
  }
  /* Deviation MISRA-2 */
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_tx_nack(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  VAR(sint8,AUTOMATIC) nRet = FrTp_SendFC(
      CHNIDX,
      FRTP_CHANNEL.ConIdx,
      FRTP_CHANNEL.Info.AddrInfo.Addr.Tgt,
      FRTP_CHANNEL.Info.AddrInfo.Addr.Src,
      FRTP_FC_NACK);

  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);

  if (nRet >= 0) {
    FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_NACK_NOTIF;
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_tx_nack_n(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);

  /*
   * Maximum Number of Transmit Retries reached?
   */
  if (FRTP_CHANNEL.Chn.Rx.ErrorCounter > (sint8)FRTP_MAX_NACK_RETRIES) {
    FRTP_RELRXCHNWITHSTATUS(
        FRTP_E_NOT_OK
    );
  } else {
    /*
     * Retry receiving data
     */
    FRTP_CHANNEL.Chn.Rx.Timeout = (sint16) FRTP_TIMEOUTCOMMON;

    FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_RX_CF;

    FRTP_CHANNEL.Chn.Rx.ErrFrameIndexPrevBlock =
    FRTP_CHANNEL.Chn.Rx.ErrFrameIndex;

    FRTP_CHANNEL.Chn.Rx.ErrFrameIndex = -1;
    FRTP_CHANNEL.Chn.Rx.CFsReceivedSinceFC = 0;
  }
}

/*
 * ----------------------------------------------------------------------------
 */

#if (FRTP_SUPPORT_TXWAIT == STD_ON)

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_tx_wt(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  VAR(BufReq_ReturnType,AUTOMATIC) status;

  FRTP_UNUSED(pData);
  if (0 == FRTP_CHANNEL.Chn.Rx.WTCtr) {
    FRTP_RELRXCHNWITHSTATUS(
        FRTP_E_NOT_OK);
  } else {
    if (0 == (FRTP_CHANNEL.Chn.Rx.WTCtr % 2)) {
      /*
       * Even Wait Counter: Send as soon as possible
       */
      VAR(sint8,AUTOMATIC) nRet = FrTp_SendFC(
          CHNIDX,
          FRTP_CHANNEL.ConIdx,
          FRTP_CHANNEL.Info.AddrInfo.Addr.Tgt,
          FRTP_CHANNEL.Info.AddrInfo.Addr.Src,
          FRTP_FC_WT);

      if (nRet >= 0) {
        FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_WT_NOTIF;
      }
    }
  }
  /*
   * Time to ask for next buffer?
   */
  if (FRTP_CHANNEL.Chn.Rx.WTBufReqTimeout == FRTP_CHANNEL.Chn.Rx.Timeout)
  {
    /*
     * maximum number of buffer request used
     */
    FRTP_CHANNEL.Chn.Rx.WTBufReqCounter--;
    if (FRTP_CHANNEL.Chn.Rx.WTBufReqCounter == 0)
    {
      FRTP_RELRXCHNWITHSTATUS(
      FRTP_E_NOT_OK);
    }
    else
    {
      status = FrTp_HandleDataFrame(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
          lChnIdx,
#endif
          FRTP_CHANNEL.Chn.Rx.FFBuffer,
          FRTP_CHANNEL.Chn.Rx.FFBufDataSize);

      if ((BUFREQ_E_NOT_OK == status)
          || (BUFREQ_E_OVFL == status))
      {
        FRTP_RELRXCHNWITHSTATUS(
          FRTP_E_NOT_OK);
      }
      if (BUFREQ_OK == status)
      {
          /*
           * Update the Write ReadBytes Counter after the
           * temporary data has been copied
           */
          FRTP_CHANNEL.Chn.Rx.ReceivedBytes =
              FRTP_CHANNEL.Chn.Rx.FFBufDataSize;
          /*
           * The necessary buffer has been obtained and copied.
           * set the new state to Transmit CTS (must be sent within
           * 100ms).
           */
          FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_CTS;
      }
      else
      {
        /*
         * Status is busy -> wait for the next try
         */
        if (FRTP_CHANNEL.Chn.Rx.Timeout>= FRTP_TIMEOUTBUFREQ)
        {
          FRTP_CHANNEL.Chn.Rx.WTBufReqTimeout =
            (uint16) (FRTP_CHANNEL.Chn.Rx.Timeout- FRTP_TIMEOUTBUFREQ);
        } else
        {
          /*
           * setup timeout after next FC_WAIT
           * the timeout to TX the FC_WAIT is
           * FRTP_TIMEOUTCOMMON - FRTP_TIMEOUTCFCF
           */
          FRTP_CHANNEL.Chn.Rx.WTBufReqTimeout =
            (uint16) (FRTP_TIMEOUTCOMMON - FRTP_TIMEOUTCFCF - FRTP_TIMEOUTBUFREQ
                +FRTP_CHANNEL.Chn.Rx.WTBufReqTimeout);
        }
      }
    }
  }
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_tx_wt_n(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  VAR(uint16,AUTOMATIC) Timeout_remain;
  FRTP_UNUSED(pData);
  /*
   * Back to WT state immediately. Decrement wait counter
   * to indicate that the state machine is now "sleeping"
   */
  FRTP_CHANNEL.Chn.Rx.State = FRTPSM_W4_TX_WT;
  --FRTP_CHANNEL.Chn.Rx.WTCtr;

  /*
   * Timeout: 900ms (waiting for time to pass)
   */
  Timeout_remain = FRTP_CHANNEL.Chn.Rx.Timeout- FRTP_CHANNEL.Chn.Rx.WTBufReqTimeout;
  FRTP_CHANNEL.Chn.Rx.Timeout = (sint16) FRTP_TIMEOUTCFCF;
  FRTP_CHANNEL.Chn.Rx.WTBufReqTimeout =
        (uint16) (FRTP_CHANNEL.Chn.Rx.Timeout- Timeout_remain);
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Sm_Rx_s_w4_timeout_wt(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  FRTP_UNUSED(pData);
  /*
   * A frame could not be sent in time: Abort
   */
  if (0 == (FRTP_CHANNEL.Chn.Rx.WTCtr % 2)) {
    FRTP_RELRXCHNWITHSTATUS(
        FRTP_E_NOT_OK);
  } else {
    /*
     * 900ms have passed. Next frame must be sent within
     * 100ms.
     */
    FRTP_CHANNEL.Chn.Rx.Timeout = (sint16)(FRTP_TIMEOUTCOMMON - FRTP_TIMEOUTCFCF);

    --FRTP_CHANNEL.Chn.Rx.WTCtr;
  }
}

#endif /* ! (FRTP_SUPPORT_TXWT == STD_ON) */

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Unexpected_Evt(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Avoid warnings about unused param
   */
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  FRTP_UNUSED(lChnIdx);
#endif
  FRTP_UNUSED(pData);


  /*
   * Marks illegal events, for debugging
   */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  FrTp_Det_ReportError( CHNIDX,
      FRTP_TXSTATEMACHINE_SERVICE_ID,
      FRTP_E_WRONG_PARAM_VAL);
#endif
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Rx_Timeout(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Avoid warnings about unused param
   */

  /*
   * Check and Clear TxPduBuffers for this connection
   */
  FrTp_CheckClearTxPduBuffer(FRTP_CHANNEL.ConIdx);

  /*
   * Cancel Transmission in case of Timeout
   */
  FRTP_RELRXCHNWITHSTATUS(
      FRTP_E_NOT_OK
  );

  FRTP_UNUSED(pData);
}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_
FUNC(void,FRTP_CODE) FrTp_Tx_Timeout(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Avoid warnings about unused param
   */
  FRTP_UNUSED(pData);
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  FRTP_UNUSED(lChnIdx);
#endif

  /*
   * Check and Clear TxPduBuffers for this connection
   */
  FrTp_CheckClearTxPduBuffer(FRTP_CHANNEL.ConIdx);

  /*
   * Set state to "Free" in case of timeout
   */
  FRTP_RELTXCHNWITHSTATUS(
      NTFRSLT_E_TIMEOUT_A
  );

}

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_ FUNC(void,FRTP_CODE) FrTp_DoNothing(
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx,
#endif
    P2CONST(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pData)
{
  /*
   * Avoid warnings about unused param
   */
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  FRTP_UNUSED(lChnIdx);
#endif
  FRTP_UNUSED(pData);
}

/* stop code section declaration */
#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-3 */
#include "MemMap.h"
