/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp FrIp incteraction functions implementation.
 **
 ** \file    FrTp_FrIf.c
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
#include "FrTp_Cbk.h"       /* get FrTp callback                             */
#include "FrIf.h"           /* FlexRay Interface functions                   */

/* ----------------------------------------------------------------------------
 Local Macros
 ---------------------------------------------------------------------------- */
/**
 * software version check
 */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif

/* start code section declaration */
#define FRTP_START_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/**
 * \briefMacro to set unused bytes to zero
 *
 * \param TxPDUDataPtr Pointer to data to be set
 * \param UnusedOffset Offset to unused data
 * \param Length       Number of bytes to be set
 */

 /*
  * FrTp_MemSet returns the destination pointer which is not used in this
  * case, so the return value is casted to (void)
  */
     
#if (FRTP_OPT_FRIF_TRANSMIT_ACCURATE_SIZE == STD_OFF)
#define FRTP_SET_UNUSED_BYTES(TxPDUDataPtr, UnusedOffset, Length)              \
    (void) FrTp_MemSet(                                                        \
        &(TxPDUDataPtr)->PduInfo.SduDataPtr[(UnusedOffset)],                   \
        0xFFU,                                                                 \
        (Length)                                                               \
        )
#else
#define FRTP_SET_UNUSED_BYTES(TxPDUDataPtr, UnusedOffset, Length)
#endif

#if (FRTP_OPT_FRIF_TRANSMIT_ACCURATE_SIZE == STD_OFF)
#if (FRTP_USE_STD_MEMCPY == STD_ON)
#define FrTp_MemSet memset
#else
/**
 * \brief FrTp's own implementation of memset
 *
 * \param pDestination  (out) pointer to destination
 * \param nValue        (in)  Value to be filled
 * \param nBytes        (in)  how many bytes should be copied from
 *                            pSource to pDestination
 * \return pointer to the memory area pDestination
 * \remarks
 * - Max. 64KB can be set (uint16 type for nBytes)
 * - Simple, byte-oriented loop, far from optimal but at least platform
 *   independent
 * - Destination pointer is (uint8 *) and not (void *)
 */

_STATIC_ FUNC(P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA),FRTP_CODE) FrTp_MemSet(
    P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) pDestination,
    VAR(uint8,AUTOMATIC) nValue,
    VAR(uint16,AUTOMATIC) nBytes
);
#endif
#endif
/* ----------------------------------------------------------------------------
 Local Function Declarations
 ---------------------------------------------------------------------------- */
/**
 *
 *    \brief Encodes data out of a <code>FrTpFrameInfoType</code>
 *      structure  into a char buffer
 *
 *    \param  pdata: Frame Info Buffer to encode data from
 *    \param  pbuf: Data buffer to encode data to
 *    \param  *pbufsize(out): Length of encoded data buffer in bytes
 *
 *    \return FRTPD_E_ENCODE if a consistency check failed during extraction
 *            FRTPD_E_OK on success
 *
 */

_STATIC_ FUNC(Std_ReturnType,FRTP_CODE) FrTp_EncodeData(
    CONSTP2CONST (FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pdata,
    P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) pbuf,
    P2VAR(PduLengthType,AUTOMATIC,FRTP_APPL_DATA) pbufsize);

/**
 *
 *    \brief Searches a TxPDUId and returns the index of in the array.
 *
 *    \param  SearchedTxPDUId: PDU-Id to be searched
 *
 *    \return index of the PDU-ID, if the corresponding ID have been found.
 *            gFrTpTxPDUNumber in the case that the ID has not been found.
 *            E_OK on success
 *
 */
_STATIC_ FUNC(uint8,FRTP_CODE) FrTp_GetTXPDUIdx(
    VAR(PduIdType,AUTOMATIC) SearchedTxPDUId
);

/* start code section declaration */
#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/* ----------------------------------------------------------------------------
 Global Data
 ---------------------------------------------------------------------------- */

#define FRTP_START_SEC_VAR_UNSPECIFIED
/* Deviation MISRA-1 */
#include "MemMap.h"
/**
 * \brief Array to hold the transmission FrIf N-PDUs runtime values
 */
VAR(FrTp_PDUTxDataType,FRTP_VAR) FrTp_PDUTxData[FRTP_TX_PDU_NUM];

/**
 * \brief Array to hold the reception FrIf N-PDUs runtime values
 */
VAR(FrTp_PDURxDataType,FRTP_VAR) FrTp_PDURxData[FRTP_RX_PDU_NUM];


#define FRTP_STOP_SEC_VAR_UNSPECIFIED
/* Deviation MISRA-1 */
#include "MemMap.h"
/* ----------------------------------------------------------------------------
 Global Functions
 ---------------------------------------------------------------------------- */

/* start code section declaration */
#define FRTP_START_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/* ------------------------------------------------------------------------- */
FUNC(void,FRTP_CODE) FrTp_RxIndication(
    VAR(PduIdType,AUTOMATIC) FrRxPduId,
    P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) FrSduPtr
)
{
  VAR(uint8,AUTOMATIC) lError = 0;
  CONST(PduIdType,AUTOMATIC) lRxPDUId = FrRxPduId;

  FrTp_CriticalSectionEnter();
  if (FrTp_IsInitialized == FALSE)
  {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    /* report to DET is module is not initialized */
    FrTp_Det_ReportError(FrRxPduId,
        FRTP_RXINDICATION_SERVICE_ID,
        FRTP_E_NOT_INIT);
#endif
    lError = 1;
  }
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (FrSduPtr == NULL_PTR)
  {
    /* Report NULL_PTR to DET*/
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError(FrRxPduId,
        FRTP_RXINDICATION_SERVICE_ID,
        FRTP_E_NULL_PTR);
#endif
    lError = 1;
  }
  if (lRxPDUId >= gFrTpRxPDUNumber)
  {
    /* RxPDUId is out of range */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError(FrRxPduId,
        FRTP_RXINDICATION_SERVICE_ID,
        FRTP_E_WRONG_PARAM_VAL);
#endif
    lError = 1;
  }
#endif
  if (lError == 0)
  {
    /*
     * FrTp_MemCpy returns the destination pointer which is not used in this
     * case, so the return value is casted to (void)
     */
    (void) FrTp_MemCpy(
        FRTP_G_RXDATA->BufferPtr,
        FrSduPtr,
        (uint16) FRTP_G_RXCFG->Length
    );
    FRTP_G_RXDATA->PDUAvail = TRUE;
  }
  FrTp_CriticalSectionExit();
}

/* ------------------------------------------------------------------------- */
FUNC(void,FRTP_CODE) FrTp_TxConfirmation(
    VAR(PduIdType,AUTOMATIC) FrTxPduId
)
{
#if (FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF)
  VAR(uint8,AUTOMATIC) lConIdx;
#endif
  FrTp_CriticalSectionEnter();
  if (FrTp_IsInitialized == FALSE)
  {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError(FrTxPduId,
        FRTP_TXCONFIRMATION_SERVICE_ID,
        FRTP_E_NOT_INIT);
#else
    /* do nothing */
#endif
  }
  else
  {
    /*
     * Search for the Tx-PDU in the Array
     */

    VAR(uint8,AUTOMATIC) lTxPDUId = FrTp_GetTXPDUIdx(FrTxPduId);
    /*
     * If the whole Array was searched but the ID was not found exit without
     * any further action
     */
    if (lTxPDUId >= gFrTpTxPDUNumber)
    {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      FrTp_Det_ReportError(FrTxPduId,
          FRTP_TXCONFIRMATION_SERVICE_ID,
          FRTP_E_WRONG_PARAM_VAL);
#else
    /* do nothing */
#endif
    }
    else
    {
      /* Set the Confirmed flag */
      FRTP_G_TXDATA->Confirmed = TRUE;
      /*
       * If more than one PDU may be used for sending set
       * all IDs for TxPdus of this channel as confirmed
       */
#if (FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF)
      lConIdx = FRTP_G_TXCFG->ConIdx;
      while (((lTxPDUId<gFrTpTxPDUNumber) && (FRTP_G_TXCFG->ConIdx == lConIdx)) &&
          (FRTP_G_TXDATA->pInfo != NULL_PTR))
      {
        FRTP_G_TXDATA->Confirmed = TRUE;
        lTxPDUId++;
      }
#endif
    }
  }
  FrTp_CriticalSectionExit();
}

/* ------------------------------------------------------------------------- */
FUNC(void,FRTP_CODE) FrTp_TriggerTransmit(
    VAR(PduIdType,AUTOMATIC) FrTxPduId,
    P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) FrSduPtr
)
{
/*
 * prevent compiler warning
 */
#if (FRTP_DEV_ERROR_DETECT == STD_OFF)
    FRTP_UNUSED(FrTxPduId);
#endif
#if (FRTP_DECOUPLED_FRIF_TX_ENABLE == STD_OFF)
  /*
   * React if decoupled transmission is deactivated
   */

  /*
   * prevent compiler warning
   */
  FRTP_UNUSED(FrSduPtr);
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  FrTp_Det_ReportError(FrTxPduId,
      FRTP_TRIGGERTRANSMIT_SERVICE_ID,
      FRTP_E_WRONG_PARAM_VAL);
#endif

#else /* FRTP_DECOUPLED_FRIF_TX_ENABLE */

  if (FrTp_IsInitialized == FALSE)
  {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    FrTp_Det_ReportError(FrTxPduId,
        FRTP_TRIGGERTRANSMIT_SERVICE_ID,
        FRTP_E_NOT_INIT);
#else
    /* do nothing */
#endif
  }
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  else if (FrSduPtr == NULL_PTR)
  {
    FrTp_Det_ReportError(FrTxPduId,
        FRTP_TRIGGERTRANSMIT_SERVICE_ID,
        FRTP_E_NULL_PTR);
  }
#endif
  else
  {
    /*
     * Search for the Tx-PDU in the Array
     */
    CONST(uint8,AUTOMATIC) lTxPDUId = FrTp_GetTXPDUIdx(FrTxPduId);

    /*
     * If the whole Array was searched but the ID was not found exit without any
     * further action
     */
    if (lTxPDUId >= gFrTpTxPDUNumber)
    {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      FrTp_Det_ReportError(FrTxPduId,
          FRTP_TRIGGERTRANSMIT_SERVICE_ID,
          FRTP_E_WRONG_PARAM_VAL);
#else
      /* do nothing */
#endif
    }
    else if (FRTP_G_TXCFG->DecoupledTx == FALSE)
    {
      /* ignore Pdu if the trigger transmit request comes from a frame
       where decoupled transmission is not configured */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      FrTp_Det_ReportError(FrTxPduId,
          FRTP_TRIGGERTRANSMIT_SERVICE_ID,
          FRTP_E_WRONG_PARAM_VAL);
#else
      /* do nothing */
#endif
    }
    else
    {
      /*
       * If we sent an frame with FrIf_Transmit configured for Direct
       * Transmission we must copy the data we prepared in the main
       * function, but only if it looks like there are new data prepared.
       */
      if (
          FRTP_G_TXDATA->pInfo != NULL_PTR
      )
      {
        /*
         * [FRTP187] The old Tx buffer is kept in memory until the
         * TxConfirmation arrives.
         * FrTp_MemCpy returns the destination pointer which is not used in this
         * case, so the return value is casted to (void)
         */
        (void) FrTp_MemCpy(
            FrSduPtr,
            FRTP_G_TXDATA->PduInfo.SduDataPtr,
            (uint16) FRTP_G_TXDATA->PduInfo.SduLength
        );
      }
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      else
      {
        /* make a Det error because we ignored a Pdu because of being in
         the wrong state */
        FrTp_Det_ReportError(FrTxPduId,
            FRTP_TRIGGERTRANSMIT_SERVICE_ID,
            FRTP_E_WRONG_PARAM_VAL);
      }
#endif
    }
  }
#endif /* FRTP_DECOUPLED_FRIF_TX_ENABLE */
}

FUNC(Std_ReturnType,FRTP_CODE) FrTp_TransmitPDU(
    VAR(PduIdType,AUTOMATIC) lTxPDUId,
    P2VAR(FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pInfo
)
{
  VAR( Std_ReturnType, AUTOMATIC ) StdRetVal = E_NOT_OK;

  /*
   * Check if PDU is already in use
   */
  if (FRTP_G_TXDATA->pInfo == NULL_PTR)
  {
    /* Encode data frame here */
    if (FrTp_EncodeData(pInfo,
            FRTP_G_TXDATA->PduInfo.SduDataPtr,
            &(FRTP_G_TXDATA->PduInfo.SduLength)) == E_OK )
    {
#if (FRTP_OPT_FRIF_TRANSMIT_ACCURATE_SIZE == STD_OFF)
      FRTP_SET_UNUSED_BYTES(FRTP_G_TXDATA,
	  (uint8) FRTP_G_TXDATA->PduInfo.SduLength,
	  (uint16) (FRTP_G_TXCFG->Length-FRTP_G_TXDATA->PduInfo.SduLength));
#endif

      FRTP_G_TXDATA->pInfo = pInfo;
      FRTP_G_TXDATA->Confirmed = FALSE;
      if (
          FrIf_Transmit(
              FRTP_G_TXCFG->PDUId,
              &(FRTP_G_TXDATA->PduInfo)
          )
          == E_OK
      )
      {
        FRTP_G_TXDATA->FrIfRetry = 0;
      }
      else
      {
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
        VAR(uint8,AUTOMATIC) lChnIdx = FRTP_G_TXCFG->ChnIdx;
#endif
        FRTP_G_TXDATA->FrIfRetry = FRTP_G_CHNCFG->maxFrIf;
        FRTP_G_TXDATA->FrIfWait4Send = FRTP_G_CHNCFG->timeFrIf;
      }
      StdRetVal = E_OK;
    }
  }

  return StdRetVal;

}
/* ----------------------------------------------------------------------------
 Local Function
 ---------------------------------------------------------------------------- */

/*
 * ----------------------------------------------------------------------------
 */

_STATIC_ FUNC(Std_ReturnType,FRTP_CODE)FrTp_EncodeData(
    CONSTP2CONST (FrTpFrameInfoType,AUTOMATIC,FRTP_APPL_DATA) pdata,
    P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) pbuf,
    P2VAR(PduLengthType,AUTOMATIC,FRTP_APPL_DATA) pbufsize)
{

  VAR( Std_ReturnType, AUTOMATIC ) StdRetVal = E_OK;

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (((pdata == NULL_PTR) || (pbuf == NULL_PTR)) || (pbufsize == NULL_PTR))
  {
    FrTp_Det_ReportError(FRTP_DET_GENERIC_INSTANCE_ID,
        FRTP_TXSTATEMACHINE_SERVICE_ID,
        FRTP_E_ASSERT);
    StdRetVal = E_NOT_OK;

  }
  if (StdRetVal == E_OK) 
#endif
  {
    *pbufsize = 0;
    
    /* MAS_TypeID */
    pbuf[FRTP_MAS_TI_INDEX] = pdata->MasTypeID;
    
    /* Target, Source Node */
    pbuf[FRTP_TGT_INDEX] = pdata->AddrInfo.Addr.Tgt;
    pbuf[FRTP_SRC_INDEX] = pdata->AddrInfo.Addr.Src;
    
    /* PCI */
    
    if (pdata->FrameType == FRTP_SF)
    {
      pbuf[FRTP_FT_INDEX] = FRTP_FT_SF;
      pbuf[FRTP_DL_INDEX] = (uint8)pdata->PCI.Length;
    
      /*
       * FrTp_MemCpy returns the destination pointer which is not used in this
       * case, so the return value is casted to (void)
       */
    
      (void)FrTp_MemCpy(
        &(pbuf[FRTP_HSIZE_SF]),
        pdata->pData,
        (uint16)pdata->DataSize);
    
      *pbufsize = (uint8)(FRTP_HSIZE_SF) + pdata->DataSize;
    }
    else if (pdata->FrameType == FRTP_FF)
    {
      VAR(uint8,AUTOMATIC) payloadIdx;
    
      if (pdata->PCI.Length <= FRTP_MAXLEN_FF1B)
      {
        pbuf[FRTP_FT_INDEX] = (uint8)(FRTP_FT_FF | FRTP_FST_FF1B);
        pbuf[FRTP_DL_INDEX] = (uint8)pdata->PCI.Length;
        payloadIdx = FRTP_HSIZE_FF1B;
      }
      else /* Maximum admissible length already checked in SM */
      {
        pbuf[FRTP_FT_INDEX] = (uint8)(FRTP_FT_FF | FRTP_FST_FF2B);
    
        pbuf[FRTP_DLL_INDEX] = (uint8)
        (((pdata->PCI.Length) & (uint16)(FRTP_FF2B_DLL_MASK)));
    
        pbuf[FRTP_DLH_INDEX] = (uint8)((pdata->PCI.Length) >> 8);
        payloadIdx = FRTP_HSIZE_FF2B;
      }
      /*
       * FrTp_MemCpy returns the destination pointer which is not used in this
       * case, so the return value is casted to (void)
       */
      (void)FrTp_MemCpy(
        &(pbuf[payloadIdx]),
        pdata->pData,
        (uint16)pdata->DataSize);
    
      *pbufsize = (payloadIdx + pdata->DataSize);
    }
    else if (pdata->FrameType == FRTP_CF)
    {
      pbuf[FRTP_FT_INDEX] = (uint8)(FRTP_FT_CF | pdata->PCI.FrameIndex);
      /*
       * FrTp_MemCpy returns the destination pointer which is not used in this
       * case, so the return value is casted to (void)
       */
      (void)FrTp_MemCpy(
        &(pbuf[FRTP_HSIZE_CF]),
        pdata->pData,
        (uint16)(pdata->DataSize));
    
      *pbufsize = (uint8)FRTP_HSIZE_CF + pdata->DataSize;
    }
    else if (pdata->FrameType == FRTP_FC_CTS)
    {
      pbuf[FRTP_FT_INDEX] = (FRTP_FT_FC | FRTP_FT_FCCTS);
      pbuf[FRTP_BS_INDEX] = pdata->PCI.FC.BSMax;
      pbuf[FRTP_BC_INDEX] = pdata->PCI.FC.BC;
      *pbufsize = (FRTP_FC_CTS_DATA_SIZE);
    }
    else if (pdata->FrameType == FRTP_FC_CREF)
    {
      pbuf[FRTP_FT_INDEX] = (FRTP_FT_FC | FRTP_FT_FCCREF);
      *pbufsize = (FRTP_FC_CREF_DATA_SIZE);
    }
    else if (pdata->FrameType == FRTP_FC_ACK)
    {
      pbuf[FRTP_FT_INDEX] = (FRTP_FT_FC | FRTP_FT_FCACK);
      *pbufsize = (FRTP_FC_ACK_DATA_SIZE);
    }
    
#if (FRTP_SUPPORT_TXWAIT == STD_ON)
    else if (pdata->FrameType == FRTP_FC_WT)
    {
      pbuf[FRTP_FT_INDEX] = (FRTP_FT_FC | FRTP_FT_FCWT);
      *pbufsize = (FRTP_FC_WT_DATA_SIZE);
    }
#endif
    
    else /*(pdata->FrameType == FRTP_FC_NACK)*/
    {
      pbuf[FRTP_FT_INDEX] = (FRTP_FT_FC | FRTP_FT_FCNACK);
      pbuf[FRTP_NACKSN_INDEX] =
      (uint8)(FRTP_NACKSN_MASK & pdata->PCI.FrameIndex);
      *pbufsize = (FRTP_FC_NACK_DATA_SIZE);
    }
    
    /*
     * The unused byte of the last word must be padded with 0xff
     */
    if (1U == (*pbufsize % 2U) )
    {
      pbuf[*pbufsize] = 0xff;
      ++*pbufsize;
    }
  }

  return StdRetVal;
}

/* ------------------------------------------------------------------------- */
_STATIC_ FUNC(uint8,FRTP_CODE) FrTp_GetTXPDUIdx(
    VAR(PduIdType,AUTOMATIC) SearchedTxPDUId
)
{
  VAR(uint8,AUTOMATIC) lTxPDUId;
  VAR(boolean,AUTOMATIC) Matches = FALSE;
  VAR(uint8,AUTOMATIC) Ret = gFrTpTxPDUNumber;

  for (
    lTxPDUId = 0;
    (lTxPDUId < gFrTpTxPDUNumber) && (Matches == FALSE);
    lTxPDUId++
  )
  {
    if (FRTP_G_TXCFG->PDUId == SearchedTxPDUId)
    {
      Matches = TRUE;
      Ret = lTxPDUId;
    }
  }
  return Ret;
}
#if (FRTP_OPT_FRIF_TRANSMIT_ACCURATE_SIZE == STD_OFF)
#if (FRTP_USE_STD_MEMCPY == STD_OFF)
_STATIC_ FUNC(P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA),FRTP_CODE) FrTp_MemSet(
    P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) pDestination,
    VAR(uint8,AUTOMATIC) nValue,
    VAR(uint16,AUTOMATIC) nBytes
)
{
  CONSTP2VAR(uint8,AUTOMATIC,FRTP_VAR) pReturn = pDestination;
  while (nBytes != 0)
  {
    *(pDestination++) = nValue;
    nBytes--;
  }
  return pReturn;
}
#endif
#endif
/* stop code section declaration */
#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/** @} doxygen end group definition */
