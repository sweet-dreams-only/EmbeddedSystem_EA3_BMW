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


/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/
 /* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 19.7 (advisory)
  *   A function should be used in preference to a function-like macro.
  *
  *   Reason:
  *   As the function is called very often and consists only of a one line
  *   the macro based implmentation is more run time efficient.
  *
  */

#ifndef IPDUM_INT_H
#define IPDUM_INT_H

/*==================[inclusions]============================================*/
#include <IpduM_Cfg.h>

/*==================[macros]================================================*/
/** \brief macro to enable overwriting of static declaration for testing  purpose */
#ifndef IPDUM_STATIC
#if (IPDUM_AUTOSAR_VERSION == 21)
#define IPDUM_STATIC _STATIC_
#else
#define IPDUM_STATIC STATIC
#endif /* if (IPDUM_AUTOSAR_VERSION == 21) */
#endif /* ifndef IPDUM_STATIC */

/* set default value if not defined */
#ifndef IPDUM_SCHM_WITH_INSTANCEID
#define IPDUM_SCHM_WITH_INSTANCEID STD_OFF
#endif

/** \brief calculate modulo 8 in byte array  */
/* Deviation MISRA-1 */
#define IPDUM_MODULO_8(i) ((i)&7U)

/** \brief pattern to select bits between startbit and endbit */
/* Deviation MISRA-1 */
#define IPDUM_SELECT_BITMASK(startbit,stopbit) \
  ((uint8)((uint8)((1U<<(((stopbit)-(startbit))+1U))-1U)))

/** \brief pattern to clear all bits between startbit and endbit */
/* Deviation MISRA-1 */
#define IPDUM_CLEAR_BITMASK(startbit,stopbit) \
  ((uint8)~((uint8)(IPDUM_SELECT_BITMASK(startbit,stopbit)<<IPDUM_MODULO_8(startbit))))

/** \brief macro to extract the selector field */
/* Deviation MISRA-1 */
#define IPDUM_GET_SELECTOR(src,startbit,stopbit) \
  ((uint8)((uint8)((src)[(startbit)>>3U]>>((IPDUM_MODULO_8(startbit))))&IPDUM_SELECT_BITMASK(startbit,stopbit)))

/** \brief macro to set the selector field */
/* Deviation MISRA-1 */
#define IPDUM_SET_SELECTOR(dst,value,startbit,stopbit) \
  ((dst)[(startbit)>>3U]=(uint8)((dst)[(startbit)>>3U]&IPDUM_CLEAR_BITMASK(startbit,stopbit))| \
  ((uint8)((value)<<(IPDUM_MODULO_8(startbit)))))

/** \brief macro to convert bit into byte offset */
/* Deviation MISRA-1 */
#define IPDUM_GET_BYTE_OFFSET(bitpos) \
  ((uint8)((bitpos)>>3U))

/** \brief macro to convert size in bits to bytes */
/* Deviation MISRA-1 */
#define IPDUM_GET_BYTE_SIZE(bitsize) \
  ((uint8)(((bitsize)+7U)>>3U))

/** \brief macro to copy bytewise */
#define IPDUM_COPY(Dest, Src, Size) \
  do \
  { \
    uint8 ii; \
    for (ii=0U;ii<(Size);ii++) \
    { \
      (Dest)[ii] = (Src)[ii]; \
    } \
  } while(0)

/** \brief maximum size of tx pathway array */
#define IPDUM_TX_PATHWAY_LEN (Ipdum_ConfigPtr->TxPathWayLen)

/** \brief maximum size of rx pathway array */
#define IPDUM_RX_PATHWAY_LEN (Ipdum_ConfigPtr->RxPathWayLen)

/** \brief mark dynamic pdu for sending */
#define IPDUM_PRIO_NOT_READY_TO_SEND ((uint16)0x100U)

/** \brief Lowest possible priority in the queue */
#define IPDUM_PRIO_LOWEST_POSSIBLE ((uint16)0xFFFFU)

/** \brief reserved value for Ipdum_TxTimeoutType to indicate that a call to
 * PduR_IpdumTransmit() has not yet completed */
#define IPDUM_TRANSMIT_ONGOING 0xFFFFU

/** \brief reserved value for Ipdum_TxTimeoutType to indicate that a call to
 * PduR_IpdumTransmit() has not yet completed but the sending of the PDU is
 * already confirmed */
#define IPDUM_TRANSMIT_ONGOING_CONFIRMED (IPDUM_TRANSMIT_ONGOING - 1U)

/*==================[type definitions]======================================*/
/** \brief definition of the Ipdum_StatusType */
typedef uint8 Ipdum_StatusType;

/** \brief Definition of constant IPDUM_UNINIT */
#if (defined IPDUM_UNINIT)        /* To prevent double declaration */
#error IPDUM_UNINIT already defined
#endif /* if (defined IPDUM_UNINIT) */

/** \brief Define IPDUM_UNINIT */
#define IPDUM_UNINIT ((Ipdum_StatusType) 0x0)

/** \brief Definition of constant IPDUM_INIT */
#if (defined IPDUM_INIT)          /* To prevent double declaration */
#error IPDUM_INIT already defined
#endif /* if (defined IPDUM_INIT) */

/** \brief Define IPDUM_INIT */
#define IPDUM_INIT ((Ipdum_StatusType) 0x01U)

/* define function like macro for development error reporting,
 * if development error detection is enabled */
#if (IPDUM_DEV_ERROR_DETECT==STD_ON)

/* Deviation MISRA-1 */
#define IPDUM_DET_REPORT_ERROR(ApiId,ErrorId)    \
  Det_ReportError(IPDUM_MODULE_ID, IPDUM_INSTANCE_ID, (ApiId), (uint8)(ErrorId))
#endif /* if (IPDUM_DEV_ERROR_DETECT == STD_ON) */

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONSTP2VAR(uint8, IPDUM_CONST, IPDUM_VAR_NOINIT) Ipdum_gDataMemPtr;

#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_INT_H */
/*==================[end of file]===========================================*/
