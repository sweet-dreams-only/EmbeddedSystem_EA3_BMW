/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp Cancel Transmit Dummy implementation.
 **
 ** \file    FrTp_CancelTrReq.c
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

/** \brief Dummy implementation of FrTp_CancelTransmitRequest
 ** This version of FrTp_CancelTransmitRequest throws a Det error in
 ** every case.
 ** */

FUNC(Std_ReturnType,FRTP_CODE) FrTp_CancelTransmitRequest
(
  VAR(PduIdType,AUTOMATIC) FrTpTxPduId,
  VAR(FrTp_CancelReasonType,AUTOMATIC) Reason
)
{
  FRTP_UNUSED(FrTpTxPduId);
  FRTP_UNUSED(Reason);
  /*
   * [FRTP150] [FRTO099]
   */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  FrTp_Det_ReportError(
    FrTpTxPduId,
    FRTP_CANCELTRANSMITREQUEST_SERVICE_ID,
    FRTP_E_WRONG_PARAM_VAL
  );
#endif
  return E_NOT_OK;
}

/* stop code section declaration */
#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/** @} doxygen end group definition */
