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

/*
 * MISRA-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 8.8 (required)
 * An external object or function shall be declared in one and only one file.
 *
 * Reason:
 * Variable is needed to avoid an empty translation unit.
 *
 */
/* NXTR CHANGE LOG:
 /****************************************************************************************
 * 12/09/11   2      BDO   Changed  Ipdum_ProcessRequestPdu() to allow Multiplex messages:
 * Update IpuM_Comcallout.c to return TRUE for all IPUM messages and return FALSE for all 
 * messages configured to respond to a specific service ID. The EPS software is not configured
 * this way. Any response to a service request from EPS is triggered by the application.
 ****************************************************************************************/
 
/*==================[inclusions]============================================*/
#include <Std_Types.h>
#include <ComStack_Types.h>

#include <IpduM.h>
#include <IpduM_Int.h>
#include <IpduM_ComCallout_Cfg.h>
#include <IpduM_ComCallout.h>

#if (IPDUM_DEV_ERROR_DETECT==STD_ON)
#include <Det.h>
#endif

#if (IPDUM_SERVICE_MESSAGES==STD_ON)
#include <Com.h>
#endif

#if (IPDUM_SERVICE_MESSAGES==STD_ON)
/*==================[macros]================================================*/
#if (IPDUM_NETWORK_BIG_ENDIAN==STD_ON)

#if (IPDUM_RX_CALLOUT_LENGTH==1U)
#define IPDUM_GET_MESSAGEID(src,pos) \
  ((src)[(pos)])
#elif (IPDUM_RX_CALLOUT_LENGTH==2U)
#define IPDUM_GET_MESSAGEID(src,pos) \
  ((Ipdum_ServiceMessageIdType)(((Ipdum_ServiceMessageIdType)((src)[(pos)])) << 8U) | \
                                (src)[(pos)+1U])
#else
#define IPDUM_GET_MESSAGEID(src,pos) \
  ((Ipdum_ServiceMessageIdType)(((Ipdum_ServiceMessageIdType)((src)[(pos)]))    << 24U) | \
   (Ipdum_ServiceMessageIdType)(((Ipdum_ServiceMessageIdType)((src)[(pos)+1U])) << 16U) | \
   (Ipdum_ServiceMessageIdType)(((Ipdum_ServiceMessageIdType)((src)[(pos)+2U])) << 8U)  | \
   (src)[(pos)+3U])
#endif

#else /* (IPDUM_NETWORK_BIG_ENDIAN==STD_OFF) */

#if (IPDUM_RX_CALLOUT_LENGTH==1U)
#define IPDUM_GET_MESSAGEID(src,pos) \
  ((src)[(pos)])
#elif (IPDUM_RX_CALLOUT_LENGTH==2U)
#define IPDUM_GET_MESSAGEID(src,pos) \
  (((src)[(pos)]) | \
   (Ipdum_ServiceMessageIdType)(((Ipdum_ServiceMessageIdType)((src)[(pos)+1U])) << 8U))
#else
#define IPDUM_GET_MESSAGEID(src,pos) \
  ((src)[(pos)] | \
   (Ipdum_ServiceMessageIdType)(((Ipdum_ServiceMessageIdType)((src)[(pos)+1U])) << 8U)  | \
   (Ipdum_ServiceMessageIdType)(((Ipdum_ServiceMessageIdType)((src)[(pos)+2U])) << 16U) | \
   (Ipdum_ServiceMessageIdType)(((Ipdum_ServiceMessageIdType)((src)[(pos)+3U])) << 24U))
#endif

#endif

/*==================[type definitions]======================================*/

#if (IPDUM_RX_CALLOUT_LENGTH==1)
typedef uint8 Ipdum_ServiceMessageIdType;
#elif (IPDUM_RX_CALLOUT_LENGTH==2)
typedef uint16 Ipdum_ServiceMessageIdType;
#else
typedef uint32 Ipdum_ServiceMessageIdType;
#endif

typedef struct
{
  Ipdum_ServiceMessageIdType ServiceMessageId;
  PduIdType ComTxPduId;
} Ipdum_MapInfoType;

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/
#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

CONST(Ipdum_MapInfoType, IPDUM_CONST) Ipdum_MapInfo[IPDUM_MAP_INFO_LENGTH] = IPDUM_MAP_INFO_CFG;

#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/
#define IPDUM_START_SEC_CODE
#include "MemMap.h"

FUNC(boolean, IPDUM_CODE) Ipdum_ProcessRequestPdu
(
  PduIdType PdumRxPduId,
#if (IPDUM_ALTERNATIVE_PROCESSREQUEST_API == STD_ON)
  P2VAR(uint8, AUTOMATIC, PDUR_APPL_DATA) SduDataPtr
#else
  P2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) SduDataPtr
#endif
)
{
  Ipdum_ServiceMessageIdType ServiceMessageId;
  uint16 i;

  IPDUM_PARAM_UNUSED(PdumRxPduId);

  /* Extract service message */
  ServiceMessageId = (Ipdum_ServiceMessageIdType)(IPDUM_GET_MESSAGEID(SduDataPtr,
                               IPDUM_RX_CALLOUT_BYTEPOS));

  /* Search for Com PduId */
  i=0;
  while (i<(uint16)(IPDUM_MAP_INFO_LENGTH))
  {
    if (Ipdum_MapInfo[i].ServiceMessageId==ServiceMessageId)
    {
      /* Call Com */
      Com_TriggerIPDUSend(Ipdum_MapInfo[i].ComTxPduId);
	  return FALSE;
    }
    i++;
  }

  return TRUE;
}

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

#else /* #if (IPDUM_SERVICE_MESSAGES==STD_OFF) */

#define IPDUM_START_SEC_CONST_8BIT
#include <MemMap.h>

/* Necessary to satisfy ISO C */
CONST(uint8, IPDUM_CONST) Ipdum_ComCallout = 0;

#define IPDUM_STOP_SEC_CONST_8BIT
#include <MemMap.h>

#endif
/*==================[end of file]===========================================*/
