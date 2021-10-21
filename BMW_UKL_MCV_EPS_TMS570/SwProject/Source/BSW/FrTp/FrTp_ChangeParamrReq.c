/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp FrTp_ChangeParameterRequest dummy implementation.
 **
 ** \file    FrTp_ChangeParamrReq.c
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

/* ------------------------------------------------------------------------- */
FUNC(void,FRTP_CODE) FrTp_ChangeParameterRequest(
    VAR(PduIdType,AUTOMATIC) FrTpTxPduId,
    VAR(FrTp_ParameterValueType,AUTOMATIC) FrTpParameterValue
)
{
  FRTP_UNUSED(FrTpTxPduId);
  FRTP_UNUSED(FrTpParameterValue);

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  /* This is a dummy implementation, so a DET error is thrown */
  FrTp_Det_ReportError(FRTP_DET_GENERIC_INSTANCE_ID,
      FRTP_CHANGEPARAMETERREQUEST_SERVICE_ID,
      FRTP_E_WRONG_PARAM_VAL);
#endif
}

/* stop code section declaration */
#define FRTP_STOP_SEC_CODE
/* Deviation MISRA-1 */
#include "MemMap.h"

/** @} doxygen end group definition */
