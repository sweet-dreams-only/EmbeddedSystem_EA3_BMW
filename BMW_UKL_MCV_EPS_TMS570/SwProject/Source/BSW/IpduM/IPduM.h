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
#ifndef IPDUM_H
#define IPDUM_H

/*==================[inclusions]============================================*/
#include <IpduM_PBcfg.h>
#include <IpduM_Api.h>

/*==================[macros]================================================*/
/*------------------[macros for 4.0 API]------------------------------------*/
#define IpduM_Init Ipdum_Init
#define IpduM_RxIndication Ipdum_RxIndication
#define IpduM_Transmit Ipdum_Transmit
#define IpduM_TriggerTransmit Ipdum_TriggerTransmit
#define IpduM_TxConfirmation Ipdum_TxConfirmation
#define IpduM_MainFunction Ipdum_MainFunction
#define IpduM_GetVersionInfo Ipdum_GetVersionInfo

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_H */
/*==================[end of file]===========================================*/
