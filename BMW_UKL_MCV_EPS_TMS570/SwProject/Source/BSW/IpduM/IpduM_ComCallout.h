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
#ifndef IPDUM_COMCALLOUT_H
#define IPDUM_COMCALLOUT_H

/*==================[includes]==============================================*/
#include <IpduM.h>
#include <IpduM_ComCallout_Cfg.h>

/*==================[macros]================================================*/
#if (defined IPDUM_SID_PROCESS_REQUEST_PDU)
#error IPDUM_SID_PROCESS_REQUEST_PDU already defined
#endif
/** \brief Service Message API service ID.
 **
 ** Definition of service ID for Ipdum_ProcessRequestPdu.
 */
#define IPDUM_SID_PROCESS_REQUEST_PDU  0x20


#if (defined IPDUM_E_GLOBAL_ECUID) /* to prevent double declaration */
#error IPDUM_E_GLOBAL_ECUID already defined
#endif
/** \brief Development Error Code
 **
 ** Global EcuID unknown to ECU.
 */
#define IPDUM_E_GLOBAL_ECUID           0x80

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/
#if (IPDUM_SERVICE_MESSAGES==STD_ON)

#define IPDUM_START_SEC_CODE
#include "MemMap.h"

/** \brief Process a request PDU
 **
 ** This function has to be called as a Com callout function for a Com Rx-PDU
 ** that is a requesting message. The function extracts the requested
 ** service message ID from the data of the PDU and triggers the sending of
 ** the appropriate Com PDU via Com_TriggerIPDUSend().
 **
 ** Preconditions:
 ** - The parameter \p SduDataPtr may not be a NULL pointer
 **
 ** \param[in] PdumRxPduId Unused paramater
 ** \param[in] SduDataPtr The PDU data which contains the service message ID
 **
 ** \ServiceID{0x20}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(boolean, IPDUM_CODE) Ipdum_ProcessRequestPdu
(
  PduIdType PdumRxPduId,
#if (IPDUM_ALTERNATIVE_PROCESSREQUEST_API == STD_ON)
  P2VAR(uint8, AUTOMATIC, PDUR_APPL_DATA) SduDataPtr
#else
  P2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) SduDataPtr
#endif
);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

#endif

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_COMCALLOUT_H */
/*==================[end of file]===========================================*/
