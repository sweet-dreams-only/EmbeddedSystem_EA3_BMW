/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp FrTp_Transmit implementation.
 **
 ** \file    FrTp_Transmit.c
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
 * MISRA-1) Deviated Rule: 19.1 (required)
 * #include statements in a file should only be preceded by other preprocessor 
 * directives or comments. 
 *
 * Reason:
 * It is needed to include the MemMap.h file after code section declaration. 
 *
 * MISRA-2) Deviated Rule: 14.7 (required)
 * Function shall have a single point of exit at the end of the function
 *
 * Reason:
 * return exits are used to increase readability of source code
 *
 */

/* ----------------------------------------------------------------------------
 Include Section
 ---------------------------------------------------------------------------- */

#include "FrTp_Priv.h"      /* get FrTp private data                         */
#include "FrTp_SM.h"        /* get FrTp state machine data types             */

/* ----------------------------------------------------------------------------
 Local Macros
 ---------------------------------------------------------------------------- */
/**
 * software version check
 */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif
/* ----------------------------------------------------------------------------
 Global Data
 ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
 Global Functions
 ---------------------------------------------------------------------------- */

/* start code section declaration */
#define FRTP_START_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/* ------------------------------------------------------------------------- */
FUNC(Std_ReturnType,FRTP_CODE) FrTp_Transmit(
    VAR(PduIdType,AUTOMATIC) FrTpTxPduId,
    P2CONST(PduInfoType,AUTOMATIC,FRTP_APPL_DATA) PduInfoPtr
)
{
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  VAR(uint8,AUTOMATIC) lChnIdx;
#endif
  CONST(PduIdType,AUTOMATIC) lConIdx = FrTpTxPduId;
  CONST(uint8,AUTOMATIC) lTxPDUId = FRTP_G_CONCFG->TxPDUTblIdx;
  FrTp_CriticalSectionEnter();

#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  lChnIdx = FRTP_G_CONCFG->ChnIdx;
#endif
  /*
   * Concurrent access with FrTp_Init to configuration. Configuration can be
   * changed by FrTp_Init.
   */
  if (FrTp_IsInitialized == FALSE)
  {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError(CHNIDX,
        FRTP_TRANSMIT_SERVICE_ID,
        FRTP_E_NOT_INIT);
#endif
    FrTp_CriticalSectionExit();
    /* Deviation MISRA-2 */
    return E_NOT_OK;
  }

  /*
   * ----------------------------------------------------------------------------
   */

  if (((PduInfoPtr->SduLength > FRTP_MAXLEN_FF2B) ||
      ((FRTP_G_CONCFG->mult_rec != 0))) && (PduInfoPtr->SduLength > FRTP_MAXLEN_GRPADDR))
  {
    /*
     * Maximum admissible length exceeded
     */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError(CHNIDX,
        FRTP_TRANSMIT_SERVICE_ID,
        FRTP_E_WRONG_PARAM_VAL);
#endif
    FrTp_CriticalSectionExit();
    /* Deviation MISRA-2 */
    return E_NOT_OK;
  }

  if (FRTP_CHN_FREE != FRTP_CHANNEL.State)
  {
    /*
     * either Tx channel with existing sender/receiver pair has
     * been found or no channel is currently available
     * -> The transmit currently cannot be served
     */

    FrTp_CriticalSectionExit();
    /* Deviation MISRA-2 */
    return E_NOT_OK;
  }

  /*
   * Reserve the free channel for Tx
   */

  FRTP_CHANNEL.State = FRTP_CHN_TX;

  /*
   * Store connection index
   */
  FRTP_CHANNEL.ConIdx = (uint8) FrTpTxPduId;

  /*
   * Setup configuration
   */
  FRTP_CHANNEL.BC = FRTP_G_CHNCFG->BCDefault;

  FRTP_CHANNEL.BSMax = FRTP_G_CHNCFG->BSInit;
  /* Size of the used PDUs, in FlexRay max 254 is possible */
  FRTP_CHANNEL.PduSize = (uint8)FRTP_G_TXCFG->Length;

  FRTP_CHANNEL.Info.MasTypeID = ((FRTP_G_CONCFG->mult_rec) != 0) ? FRTP_MT_GC : FRTP_MT_SC;
  FRTP_CHANNEL.Info.AddrInfo.Addr.Src = FRTP_G_CONCFG->LAddr;
  FRTP_CHANNEL.Info.AddrInfo.Addr.Tgt = FRTP_G_CONCFG->RAddr;

  FRTP_CHANNEL.Length = (FrTpSizeType) PduInfoPtr->SduLength;

  /*
   * Setup Buffer
   */
  FRTP_CHANNEL.pBuffer = NULL_PTR;

#if (FRTP_TX_BUFFER_REQUEST_ZERO == STD_ON)
  FRTP_CHANNEL.pAppBuffer = NULL_PTR;
  FRTP_CHANNEL.RetryBuffer.SduLength=0;
  FRTP_CHANNEL.nApplBufRemain=0;
#endif
  /*
   * Setup State
   */
  FRTP_CHANNEL.Chn.Tx.CFsCycleWaitCtr = 0;
  FRTP_CHANNEL.Chn.Tx.CFsSinceFC = 0;
  FRTP_CHANNEL.Chn.Tx.CFsWaitCtr = 0;
  FRTP_CHANNEL.Chn.Tx.ErrFrameIndex = -1;
  FRTP_CHANNEL.Chn.Tx.ErrorCounter = 0;
  FRTP_CHANNEL.Chn.Tx.LastCFDataBytes = 0;
  FRTP_CHANNEL.Chn.Tx.ReadIdx = 0;
  FRTP_CHANNEL.Chn.Tx.SentBytes = 0;
  FRTP_CHANNEL.Chn.Tx.State = FRTPSM_W4_TX_FFSF;
  FRTP_CHANNEL.Chn.Tx.Timeout =(sint16)FRTP_TIMEOUTCOMMON;
  FRTP_CHANNEL.Chn.Tx.WTCounter = 0;

  FRTP_CHANNEL.Chn.Tx.BufReqTimeout = 0;

  FRTP_CHANNEL.Chn.Tx.BufReqCounter = FRTP_G_CHNCFG->MaxBufReq;

  /*
   * Setup State machine
   */
  if (PduInfoPtr->SduLength >
      (FrTpSizeType)FRTP_SF_DATA_SIZE(FRTP_CHANNEL.PduSize))
  {
    FRTP_CHANNEL.Chn.Tx.pTxSM = FrTpTxSMSeg;
  }
  else
  {
    FRTP_CHANNEL.Chn.Tx.pTxSM = FrTpTxSMUnseg;
  }

  FrTp_CriticalSectionExit();
    /* Deviation MISRA-2 */
  return E_OK;
}

/* stop code section declaration */
#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/** @} doxygen end group definition */
