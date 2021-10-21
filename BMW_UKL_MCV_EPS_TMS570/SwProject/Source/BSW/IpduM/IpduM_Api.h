/**
 * \file
 *
 * \brief Autosar IPduMplex
 *
 * This file contains the implementation of the Autosar
 * module IPduMplex.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2010 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef IPDUM_API_H
#define IPDUM_API_H

/*==================[inclusions]============================================*/
#include <Std_Types.h>
#include <ComStack_Types.h>
#include <IpduM_Types.h>
#include <IpduM_Cfg.h>
#include <IpduM_Lcfg.h>
#include <IpduM_Version.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/
#define IPDUM_START_SEC_CODE
#include "MemMap.h"

/** \brief Initializes all module-related global variables.
 **
 ** Initializes all module-related global variables including defualt values,
 ** default selector field and state of timeout monitors.
 **
 ** \param[in]  Config  Pointer to post build configuration of the Ipdum
 **
 ** \ServiceID{0}
 ** \Reentrancy{non reentrant}
 ** \Synchronicity{synchronous}
 **
 */
extern FUNC(void, IPDUM_CODE) Ipdum_Init
(
  P2CONST(Ipdum_ConfigType, AUTOMATIC, IPDUM_APPL_CONST) Config
);

/** \brief Receive indication callback function
 **
 ** This is the receive indication callback function. It de-multiplex the incoming
 ** PDU and calls the corresponding upper layer receive indication callback function
 **
 ** \param[in]  PdumRxPduId  ID of I-PDU that has been received.
 ** \param[in]  SduPtr       Pointer to underlying layer's L-SDU (buffer of received payload).
 **
 ** \ServiceID{2}
 ** \Reentrancy{reentrant}
 ** \Synchronicity{synchronous}
 **
 */
extern FUNC(void, IPDUM_CODE) Ipdum_RxIndication
(
  PduIdType PdumRxPduId,
  P2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) SduPtr
);

/** \brief Transmit an I-PDU
 **
 ** This function transmits the data given through \p PduInfoPtr through the
 ** I-PDU given by \p PdumTxPduId.
 **
 ** \param[in]  PdumTxPduId  ID of I-PDU to be transmitted.
 ** \param[in]  PduInfoPtr   A pointer to a structure with I-PDU related data that shall be
 **                          transmitted: data length and pointer to I-SDU buffer
 **
 **
 ** \return Standard Return Code
 ** \retval E_OK The request was accepted by Ipdum.
 ** \retval E_NOT_OK The request was not accepted by Ipdum, a detailed error
 **                  condition was sent to DET.
 **
 ** \ServiceID{3}
 ** \Reentrancy{reentrant}
 ** \Synchronicity{synchronous}
 **
 */
extern FUNC(Std_ReturnType, IPDUM_CODE) Ipdum_Transmit
(
  PduIdType PdumTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr
);

/** \brief Copy data to PDU-router memory
 **
 ** The function Ipdum_TriggerTransmit copies the contents of its I-PDU transmit buffer
 ** to the I-PDU buffer given by SduPtr
 **
 ** \param[in]  PdumTxPduId  ID of IPduM I-PDU that is requested to be transmitted by IPduM
 ** \param[in]  SduPtr       Pointer to transmit buffer of I-PDU
 **
 ** \ServiceID{5}
 ** \Reentrancy{reentrant}
 ** \Synchronicity{synchronous}
 **
 */
extern FUNC(void, IPDUM_CODE) Ipdum_TriggerTransmit
(
  PduIdType PdumTxPduId,
  P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) SduPtr
);

/** \brief Transmit confirmation callback function
 **
 ** This is the transmit confirmation callback function. It gets the PDU
 ** handle for the transmitted I-PDU, translates it for the upper layer and
 ** then calls the upper layer callback functions configured for this handle.
 **
 ** \param[in]  PdumTxPduId  ID of multiplexed I-PDU that has been transmitted.
 **
 ** \ServiceID{4}
 ** \Reentrancy{reentrant}
 ** \Synchronicity{synchronous}
 **
 */
extern FUNC(void, IPDUM_CODE) Ipdum_TxConfirmation (PduIdType PdumTxPduId);

/** \brief Ipdum main function
 **
 ** Performs the processes of the activities that are not directly initiated by
 ** the calls from PDU-R. This includes at least the TxConfirmation time observation.
 **
 ** This function has to be called periodically by a task controlled by the
 ** BSW scheduler.
 **
 ** \ServiceID{0x10}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, IPDUM_CODE) Ipdum_MainFunction (void);

/** \brief Return module version information
 **
 ** This function returns the Ipdum version information in the memory
 ** area \p VersionInfoPtr references.
 **
 ** Preconditions:
 ** - The parameter \p VersionInfoPtr may not be a NULL pointer
 **
 ** \param[out] VersionInfoPtr Version information
 **
 ** \ServiceID{1}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, IPDUM_CODE) Ipdum_GetVersionInfo
(
  CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, IPDUM_APPL_DATA) VersionInfoPtr
);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_API_H */
/*==================[end of file]===========================================*/
