/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp FrTp_Mainfunction implementation.
 **
 ** \file    FrTp_Mainfunction.c
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
 */

/* ----------------------------------------------------------------------------
 Include Section
 ---------------------------------------------------------------------------- */

#include "FrTp_Priv.h"      /* get FrTp private data                         */
#include "FrTp_SM.h"        /* get FrTp state machine data types             */
#include "FrIf.h"           /* FlexRay Interface functions                   */
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
FUNC(void,FRTP_CODE) FrTp_MainFunction(void)
{
  VAR(uint8,AUTOMATIC) lRxPDUId;
  VAR(uint8,AUTOMATIC) lTxPDUId;
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  VAR(FrTpChannelIndexType,AUTOMATIC) lChnIdx=0;
#endif    /*
     * Concurrent access with FrTp_Init to configuration. Configuration can be
     * changed by FrTp_Init.
     */
  FrTp_CriticalSectionEnter();
  if (FrTp_IsInitialized == FALSE)
  {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    /* Report not init error to DET */
    FrTp_Det_ReportError( FRTP_DET_GENERIC_INSTANCE_ID,
        FRTP_MAINFUNCTION_SERVICE_ID,
        FRTP_E_NOT_INIT);
#endif
    /* Leave Mainfunction */
    FrTp_CriticalSectionExit();
  }
  else
  {
    /*
     * Check for confirmed transmissions.
     */
    for (lTxPDUId=0; lTxPDUId < gFrTpTxPDUNumber; ++lTxPDUId)
    {
      FRTP_LOCAL_TXDATA
      FRTP_LOCAL_TXCFG
  
      if (FRTP_TXDATA->Confirmed == TRUE)
      {
        /*
         * check if data is available or PDU shall be resent
         */
        if ((FRTP_TXDATA->pInfo == NULL_PTR) || (FRTP_TXDATA->FrIfRetry > 0U))
        {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
          FrTp_Det_ReportError(
              lTxPDUId,
              FRTP_MAINFUNCTION_SERVICE_ID,
              FRTP_E_ASSERT);
#else
	  /* do nothing */
#endif
        }
        else
        {
  
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
          lChnIdx = FRTP_TXCFG->ChnIdx;
#endif
          /*
           * Call confirmation functions only in the case that
           * the PDU was sent by an active channel
           * (not for a CREF without channel)
           */
          if (FRTP_TXDATA->pInfo->Reserve < FRTP_NOCHANNEL)
          {
            (FRTP_CHANNEL.Chn.Tx.pTxSM)
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
            [FRTP_CHANNEL.Chn.Tx.State][FRTPSM_EVT_TX](lChnIdx, FRTP_TXDATA->pInfo);
#else
            [FRTP_CHANNEL.Chn.Tx.State][FRTPSM_EVT_TX](FRTP_TXDATA->pInfo);
#endif
          }
          /* Free the info-Buffer */
          FRTP_TXDATA->pInfo->Reserve=FRTP_INVALID;
          FRTP_TXDATA->pInfo = NULL_PTR;
        }
  
        /*
         * Clear the confirmed flag in every case
         */
        FRTP_TXDATA->Confirmed = FALSE;
      }
      /*
       * Is there a PDU which shall be re-send?
       */
      if ((FRTP_TXDATA->FrIfRetry > 0U) && (FRTP_TXDATA->pInfo != NULL_PTR))
      {
        /*
         * Is it now time to re-send?
         */
        if (FRTP_TXDATA->FrIfWait4Send == 0)
        {
          /*
           *  ReTransmit the FrIf PDU
           */
          if (FrIf_Transmit(
                        FRTP_TXCFG->PDUId,
                        &(FRTP_TXDATA->PduInfo)
                    )
                    == E_OK
              )
          {
            FRTP_TXDATA->FrIfRetry =0;
          }
          else
          {
            /*
             * Decrement number of retries
             */
            FRTP_TXDATA->FrIfRetry--;
            /*
             * Reset retransmission counter
             * or abort channel
             */
            if (FRTP_TXDATA->FrIfRetry == 0)
            {
              VAR(uint8,AUTOMATIC) lConSDU;
              /* Free the info-Buffer */
              FRTP_TXDATA->pInfo->Reserve=FRTP_INVALID;
              FRTP_TXDATA->pInfo = NULL_PTR;
              /* abort channel */
              /*
               * Call Indication/Confirmation functions
               */
              if (FRTP_CHANNEL.State == FRTP_CHN_TX)
              {
                /*
                 * TX-SDU is the Connection index
                 */
                lConSDU=FRTP_CHANNEL.ConIdx;
                FRTP_CHANNEL.State = FRTP_CHN_FREE;
                PduR_FrTpTxConfirmation(lConSDU,NTFRSLT_E_FR_FRIF_ERROR);
              }
              if (FRTP_CHANNEL.State == FRTP_CHN_RX)
              {
                /*
                 * Get the RX-SDU
                 */
                lConSDU=(uint8) gFrTp_ConConfigPtr[FRTP_CHANNEL.ConIdx].RxSDUId;
                FRTP_CHANNEL.State = FRTP_CHN_FREE;
                PduR_FrTpRxIndication(lConSDU,NTFRSLT_E_FR_FRIF_ERROR);
              }
            }
            else
            {
              FRTP_TXDATA->FrIfWait4Send = FRTP_G_CHNCFG->timeFrIf;
            }
          }
        }
        else
        {
          FRTP_TXDATA->FrIfWait4Send --;
        }
      }
    }
  
    /*
     * Check for new incoming frames, iterate over all RxPDUIds.
     */
    for (lRxPDUId=0; lRxPDUId < gFrTpRxPDUNumber; ++lRxPDUId)
    {
      FRTP_LOCAL_RXDATA
  
      if (FRTP_RXDATA->PDUAvail == TRUE)
      {
        FrTp_HandleRxData(lRxPDUId);
        /*
         * Reset PDUAvail flag if frame was decoded (successfully or
         * not). All other actions are done using per channel data in the Rx
         * state machine.
         */
        FRTP_RXDATA->PDUAvail = FALSE;
      }
    }
  
    FrTp_CriticalSectionExit();
    /*.
     * Iterate over occupied state machines, invoke state function
     */
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    for (lChnIdx = 0U; lChnIdx < FRTP_CHAN_NUM; lChnIdx++)
    {
#endif
      if(FRTP_CHANNEL.State == FRTP_CHN_RX)
      {
        /*
         * Check for timeout
         */
        FrTpSMEventType Evt;
        FRTP_CHANNEL.Chn.Rx.Timeout--;
        Evt =
        ((FRTP_CHANNEL.Chn.Rx.Timeout <= 0) ?
            FRTPSM_EVT_TIMEOUT : FRTPSM_EVT_TASK);
  
        (FRTP_CHANNEL.Chn.Rx.pRxSm)
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        [FRTP_CHANNEL.Chn.Rx.State][Evt](lChnIdx, NULL_PTR);
#else
        [FRTP_CHANNEL.Chn.Rx.State][Evt](NULL_PTR);
#endif
      }
      else if (FRTP_CHANNEL.State == FRTP_CHN_TX)
      {
        /*
         * Check for timeout
         */
        FrTpSMEventType Evt;
        FRTP_CHANNEL.Chn.Tx.Timeout--;
        Evt =
        ((FRTP_CHANNEL.Chn.Tx.Timeout <= 0) ?
            FRTPSM_EVT_TIMEOUT : FRTPSM_EVT_TASK);
  
        (FRTP_CHANNEL.Chn.Tx.pTxSM)
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        [FRTP_CHANNEL.Chn.Tx.State][Evt](lChnIdx, NULL_PTR);
#else
        [FRTP_CHANNEL.Chn.Tx.State][Evt](NULL_PTR);
#endif
      }
      else
      {
        /*
         * State == Free; nothing to do
         */
      }
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
    }
#endif
  }
}

/* stop code section declaration */
#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/** @} doxygen end group definition */
