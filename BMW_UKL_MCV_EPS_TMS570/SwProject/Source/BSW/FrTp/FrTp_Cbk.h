/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** FrTp Callback prototypes.
 **
 ** \file    FrTp_Cbk.h
 ** \project BMW FrTp
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** \author Guenter Ebermann
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


#ifndef _FRTP_CBK_H_
#define _FRTP_CBK_H_

/* ----------------------------------------------------------------------------
 Include Section
---------------------------------------------------------------------------- */

#include "ComStack_Types.h" /* basic commstack types from AUTOSAR */
#include "FrTp.h"             /* get module prototypes, etc.    */

/******************************************************************************
 Global Macros
******************************************************************************/

/* Local file software version check */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif

/* ----------------------------------------------------------------------------
 Global Function Declarations
 ---------------------------------------------------------------------------- */
/* start code section declaration */
#define FRTP_START_SEC_CODE
#include "MemMap.h"

/**
 * \brief This function is called by the FlexRay Interface for sending out a
 *        FlexRay frame.
 *
 * \param FrTxPduId (in) ID of FlexRay L-PDU that is requested to be
 *                       transmitted.
 * \param FrSduPtr (in)  Pointer to transmit buffer of L-PDU.
 *
 * \remarks: No critical section macros are used in the implementation since
 * this callback function is called by FrIf, which is executed synchronously
 * with the FlexRay bus and thus synchronously with the FrTp_MainFunction.
 */
extern FUNC(void,FRTP_CODE) FrTp_TriggerTransmit(
    VAR(PduIdType,AUTOMATIC) FrTxPduId,
    P2VAR(uint8,AUTOMATIC,FRTP_APPL_DATA) FrSduPtr
    );

/**
 * \brief The FlexRay Interface calls this primitive after the reception of an
 *        Fr N-PDU.
 *
 * \param FrRxPduId (in) This parameter contains the identifier of the received
 *                       Fr N-PDU.
 * \param FrSduPtr (in)  Pointer to FlexRay SDU buffer in FrIf.
 *
 * \remarks: No critical section macros are used in the implementation since
 * this callback function is called by FrIf, which is executed synchronously
 * with the FlexRay bus and thus synchronously with the FrTp_MainFunction.
 */
extern FUNC(void,FRTP_CODE) FrTp_RxIndication(
    VAR(PduIdType,AUTOMATIC) FrRxPduId,
    P2CONST(uint8,AUTOMATIC,FRTP_APPL_DATA) FrSduPtr
    );

/**
 * \brief This function is called by the FlexRay Interface after the TP-related
 *        Pdu has been transmitted over the network.
 *
 * \param FrTxPduId (in) This parameter contains the identifier of the
 *                       transmitted Fr N-PDU.
 *
 * \remarks: No critical section macros are used in the implementation since
 * this callback function is called by FrIf, which is executed synchronously
 * with the FlexRay bus and thus synchronously with the FrTp_MainFunction.
 */
extern FUNC(void,FRTP_CODE) FrTp_TxConfirmation(
    VAR(PduIdType,AUTOMATIC) FrTxPduId
    );

/* start code section declaration */
#define FRTP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* _FRTP_CBK_H_ */
