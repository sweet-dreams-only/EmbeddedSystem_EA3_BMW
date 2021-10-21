/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp FrTp_Init implementation.
 **
 ** \file    FrTp_Init.c
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
 * MISRA-1) Deviated Rule: 17.4 (required)
 * Array indexing shall be the only allowed form of pointer arithmetic.
 *
 * Reason:
 * Pointer arithmetic is used for classical functions like memcpy() to
 * make them more readable and maintainable.
 *
 *
 * MISRA-2) Deviated Rule: 14.7 (required)
 * Function shall have a single point of exit at the end of the function
 *
 * Reason:
 * The function FrTp_Init is of type void and the several return exits are 
 * used to increase readability of source code
 * 
 * MISRA-3) Deviated Rule: 19.1 (required)
 * #include statements in a file should only be preceded by other preprocessor 
 * directives or comments. 
 *
 * Reason:
 * It is needed to include the MemMap.h file after code section declaration. 
 *
 * MISRA-4) Deviated Rule: 8.7 (required)
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
#include "FrTp_Cfg.h"       /* get FrTp precompile time configuration        */

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
#define FRTP_START_SEC_VAR_8BIT
/* Deviation MISRA-3 */
#include "MemMap.h"
/**
 * IsInitialized is a boolean flag, indicating the initialisation
 * status of the FrTp module.
 */
VAR(boolean,FRTP_VAR) FrTp_IsInitialized = FALSE;

#define FRTP_STOP_SEC_VAR_8BIT
/* Deviation MISRA-3 */
#include "MemMap.h"

#define FRTP_START_SEC_VAR_UNSPECIFIED
/* Deviation MISRA-3 */
#include "MemMap.h"

/**
 * Buffer to hold retry data
 */
#if (FRTP_TX_BUFFER_REQUEST_ZERO == STD_ON)
/* Deviation MISRA-4 */
_STATIC_ VAR(uint8,FRTP_VAR) aFrTp_RetryBuffer[FRTP_RETRY_BUFFER_SIZE*FRTP_CHAN_NUM];
#endif


/**
 * Array to hold the channel specific runtime values
 */
/* Deviation MISRA-4 */
_STATIC_ VAR(uint8,FRTP_VAR) FrTp_PDUBuffer[FRTP_PDU_BUFFER_SIZE];


#if (FRTP_RELOCATABLE_CONFIG == STD_ON)
/*
 * If binary relocalbe configuration is enabled set the local static variables.
 */
VAR(uint8,FRTP_VAR) gFrTpChnNumber;
VAR(uint8,FRTP_VAR) gFrTpConNumber;
VAR(uint8,FRTP_VAR) gFrTpTxPDUNumber;
VAR(uint8,FRTP_VAR) gFrTpRxPDUNumber;
#endif

#define FRTP_STOP_SEC_VAR_UNSPECIFIED
/* Deviation MISRA-3 */
#include "MemMap.h"

/* ----------------------------------------------------------------------------
 Global Functions
 ---------------------------------------------------------------------------- */

/* start code section declaration */
#define FRTP_START_SEC_CODE
/* Deviation MISRA-3 */
#include "MemMap.h"

/* ------------------------------------------------------------------------- */
FUNC(void,FRTP_CODE) FrTp_Init(
    /* ------------------------------------------------------------------------- */
#if (FRTP_RELOCATABLE_CONFIG == STD_ON)
    P2CONST(void,AUTOMATIC,FRTP_APPL_CONST) PBCfgPtr
#else
    void
#endif
)
{
  VAR(PduLengthType,AUTOMATIC) lPDUBufIdx=0;
  VAR(uint8_least,AUTOMATIC) lRxPDUId;
  VAR(uint8_least,AUTOMATIC) lTxPDUId;
  VAR(uint8_least,AUTOMATIC) i;
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  VAR(uint8_least,AUTOMATIC) lChnIdx;
#endif
#if (FRTP_TX_BUFFER_REQUEST_ZERO == STD_ON)
  VAR(uint16,AUTOMATIC) lRetryBufIdx=0;
#endif

  FrTp_CriticalSectionEnter();

  /*
   * Initialize the FrTpBuffers of the Rx/Tx Buffers and other Rx/Tx-PDU
   * specific RAM data.
   */
  for (lRxPDUId = 0; lRxPDUId < gFrTpRxPDUNumber; ++lRxPDUId)
  {
    FRTP_LOCAL_RXDATA

      /* Deviation MISRA-2 */
    FRTP_RXDATA->PDUAvail = FALSE;
    FRTP_RXDATA->BufferPtr = &(FrTp_PDUBuffer[lPDUBufIdx]);
    lPDUBufIdx += FRTP_G_RXCFG->Length;
    if (lPDUBufIdx > sizeof(FrTp_PDUBuffer))
    {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      FrTp_Det_ReportError(FRTP_DET_GENERIC_INSTANCE_ID,
          FRTP_INIT_SERVICE_ID,
          FRTP_E_WRONG_PARAM_VAL);
#endif
      FrTp_CriticalSectionExit();
      /* Deviation MISRA-2 */
      return;
    }
  }

  for (lTxPDUId = 0; lTxPDUId < gFrTpTxPDUNumber; ++lTxPDUId)
  {
    FRTP_LOCAL_TXDATA
    FRTP_LOCAL_TXCFG

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    /*
     * Check if length of Tx-Pdu does not exceed FRTP_PDU_MAXLEN
     */
    if (FRTP_TXCFG->Length > FRTP_PDU_MAXLEN)
    {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      FrTp_Det_ReportError(FRTP_DET_GENERIC_INSTANCE_ID,
          FRTP_INIT_SERVICE_ID,
          FRTP_E_WRONG_PARAM_VAL);
#endif
      FrTp_CriticalSectionExit();
      /* Deviation MISRA-2 */
      return;
    }
#endif
    FRTP_TXDATA->Confirmed = FALSE;
    FRTP_TXDATA->pInfo = NULL_PTR;
    FRTP_TXDATA->PduInfo.SduDataPtr = &(FrTp_PDUBuffer[lPDUBufIdx]);
    FRTP_TXDATA->PduInfo.SduLength = FRTP_TXCFG->Length;

    lPDUBufIdx += FRTP_TXDATA->PduInfo.SduLength;
    if (lPDUBufIdx > sizeof(FrTp_PDUBuffer))
    {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      FrTp_Det_ReportError(FRTP_DET_GENERIC_INSTANCE_ID,
          FRTP_INIT_SERVICE_ID,
          FRTP_E_WRONG_PARAM_VAL);
#endif
      FrTp_CriticalSectionExit();
      /* Deviation MISRA-2 */
      return;
    }
  }
  if (gFrTpChnNumber > FRTP_CHAN_NUM)
  {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      FrTp_Det_ReportError(FRTP_DET_GENERIC_INSTANCE_ID,
          FRTP_INIT_SERVICE_ID,
          FRTP_E_WRONG_PARAM_VAL);
#endif
      FrTp_CriticalSectionExit();
      /* Deviation MISRA-2 */
      return;
  }
  /*
   * Iterate over FrTp Channels and initialize them.
   */
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
  for (lChnIdx = 0U; lChnIdx < gFrTpChnNumber; lChnIdx++)
#endif
  {
    FRTP_CHANNEL.State = FRTP_CHN_FREE;
#if (FRTP_TX_BUFFER_REQUEST_ZERO == STD_ON)
    /*
     * Setup the retry-Buffer here
     */
    FRTP_CHANNEL.RetryBuffer.SduDataPtr=&(aFrTp_RetryBuffer[lRetryBufIdx]);
    FRTP_CHANNEL.RetryBuffer.SduLength=0;

    lRetryBufIdx += FRTP_RETRY_BUFFER_SIZE;
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
		/*
		 * aFrTp_RetryBuffer is FRTP_RETRY_BUFFER_SIZE*FRTP_CHAN_NUM, so the 
		 * check below holds in every case, therefore it is guarded precompile-
		 * time switches.
		 */
    if (lRetryBufIdx > sizeof(aFrTp_RetryBuffer))
    {
      FrTp_Det_ReportError(FRTP_DET_GENERIC_INSTANCE_ID,
          FRTP_INIT_SERVICE_ID,
          FRTP_E_WRONG_PARAM_VAL);
      FrTp_CriticalSectionExit();
      /* Deviation MISRA-2 */
      return;
    }
#endif
#endif
  }

  /*
   * Set reserved bits of Frame Info to "1"
   */
  for (i = 0U; i < FRTP_PDUINFO_BUFFER_NUM; i++)
  {
    aFrTpFrameInfo[i].Reserve = FRTP_INVALID;
  }

  /*
   * Placed at the very end of the init function, cause at this
   * point all checks passed and the module is ready to fly.
   */

  FrTp_IsInitialized = TRUE;
  FrTp_CriticalSectionExit();

  /* Deviation MISRA-2 */
}

/* ------------------------------------------------------------------------- */
FUNC(void,FRTP_CODE) FrTp_Shutdown(void)
/* ------------------------------------------------------------------------- */
{
  /*
   * Concurrent access with FrTp_Init to configuration. Configuration can be
   * changed by FrTp_Init.
   */
  FrTp_CriticalSectionEnter();

  /*
   * Only reset global flag to stop operation of the module (ignore all new
   * RxIndications and all new transmission requests) [FRTP148]. After
   * reinitializing the module (via function FrTp_Init()) all RAM variables
   * will be reset.
   */
  FrTp_IsInitialized = FALSE;

  FrTp_CriticalSectionExit();
}
/* stop code section declaration */

/* ----------------------------------------------------------------------------
 Plattform independent reimplementation of standard library functions
 ---------------------------------------------------------------------------- */
#if (FRTP_USE_STD_MEMCPY == STD_OFF)
FUNC(P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA),FRTP_CODE) FrTp_MemCpy(
    P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) pDestination,
    P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) pSource,
    VAR(uint16,AUTOMATIC) nBytes
)
{
  CONSTP2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) pReturn = pDestination;
  while (nBytes != 0)
  {
    *pDestination = *pSource;
    /* Deviation MISRA-1 */
    pDestination++;
    /* Deviation MISRA-1 */
    pSource++;
    nBytes--;
  }
  return pReturn;
}
#endif

#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-3 */
#include "MemMap.h"

/** @} doxygen end group definition */
