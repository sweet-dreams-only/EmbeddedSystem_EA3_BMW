
/**************************************************************************************************
   Project Name: AUTOSAR XCP on FlexRay Transport Layer
      File Name: FrXcpS.c

    Description: XCP on FlexRay Transport Layer implementation

  -------------------------------------------------------------------------------------------------
       C O P Y R I G H T
  -------------------------------------------------------------------------------------------------
       Copyright (c) 2011 by Vctr Informatik GmbH. All rights reserved.



       This software is copyright protected and proporietary to Vctr Informatik GmbH.
       Vctr Informatik GmbH grants to you only those rights as set out in the
       license conditions. All other rights remain with Vctr Informatik GmbH.


       Use of this source code is subject to the License Agreement "license.txt"
       distributed with this file. You may not use this source code unless you
       agree to the terms of the License Agreement.

       REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.

  -------------------------------------------------------------------------------------------------
                 A U T H O R   I D E N T I T Y
  -------------------------------------------------------------------------------------------------
   Initials     Name                      Company
   --------     ---------------------     ---------------------------------------------------------
   hr           Andreas Herkommer         Vctr Informatik GmbH
  -------------------------------------------------------------------------------------------------
                 R E V I S I O N   H I S T O R Y
  -------------------------------------------------------------------------------------------------
   Date         Ver      Author  Description
   ----------   -------  ------  ------------------------------------------------------------------
   2006-09-01   2.00.00  hr      Complete Rework for Gen2 - Supports FrIf now
   2007-03-31   2.01.00  hr      Adaptation to D4 requirements: New API
   2007-05-07   2.01.01  hr      ISS001 - Buffer reconfig API includes and type usage reworked to
                                          prevent compile error if not used
                                 ISS002 - Usage of Compiler.h is not mandatory anymore
   2007-05-08   2.02.00  hr      Implementation of features described in XCP_Client_V1.1
   2007-07-23   2.02.01  hr      Minor updates
   2007-07-09   2.03.00  hr      Support AUTOSAR Memory Mapping
   2007-09-03   2.03.01  hr      Unified as Single Source
   2007-10-05   2.04.00  hr      ISS024 - ApplXcpDaqTlResume had a wrong prototype
                                 ISS027 - Support of AUTOSAR GetVersion API
                                 ISS030 - PDU buffer ordering changed
                                 ISS032 - The XCP_ACTIVATE and XCP_DEACTIVATE macros are missing
   2007-12-07   2.05.00  hr      ISS045 - Reception of concatenated frames may lead to
                                          misinterpretation of random data as xcp frame in case
                                          PDU is smaller than MAX_PDU_SIZE
                                 ISS046 - Only CTOs are flushed by the Protocol Layer
   2008-02-07   2.06.00  hr      ISS051 - XCP_ENABLE and XCP_DISABLE have intermixed values
                                 ISS052 - FrXcp_TLService missing length check of new assigned buffer
                                 ISS053 - PDU Reservation shoould happen before FrIf_Transmit as
                                          this might cause race conditions on certain FlexRay Stacks
                                 ISS054 - Copy of XCP PDUs can now also be done during Tx_Confirmation
                                          to detect displacement in the non guaranteed dynamic segment
   2008-03-20   2.07.00  hr      Added various type casts for MISRA compliance
   2008-08-27   2.08.00  hr      Update for ASR 3.0
   2009-03-16   2.09.00  hr      ESCAN00033909: Update due to 
                                                Anforderungsdokument_EA_XCP-Client_Spezifikation_V1_1.PDF
   2009-08-03   2.09.01  hr      ESCAN00036838: Race condition with XCP_FREE_PDU and Event Assign
   2009-09-07   2.09.02  hr      ESCAN00037599: Missing memmap.h and compiler_cfg.h
   2009-09-12   2.10.00  hr      ESCAN00038374: No FrXcp_InitMemory function
   2009-10-13                    ESCAN00038410: Wrong variable section for compiler abstraction
   2009-11-24            hr      ESCAN00039363: Support FrIf_Transmit with E_PENDING
   2009-12-03            hr      ESCAN00039560: Compiler Warning by ON/OFF pre-processor statements
   2009-12-09            hr      ESCAN00039641: FrXcp does not use SchM for Interrupt locks
   2010-02-02   2.10.01  hr      ESCAN00040602: Frame end detection with concatenation is one byte to long.
                                 ESCAN00040124: Support MISRA2004 checks
                                 ESCAN00040810: wrong "component version" define
   2010-08-17   2.10.02  hr      ESCAN00044142: Compiler error occurs when compiling function FrXcp_GetFreePdu
   2010-08-24                    ESCAN00044840: Compiler warning "Invalid pointer cast" might occur
   2010-11-04   2.10.03  hr      ESCAN00046457: Transport Layer not activated in Protocol Layer if frame concatenation is enabled
                                 ESCAN00046235: Adapt AUTOSAR version check
                                 ESCAN00046412: Compiler warning: variable "FrXcp_PduState" was set but never used
                                 ESCAN00046819: Add support for XCP measurement during bus off phases
   2010-12-14   2.10.04  hr      ESCAN00047672: Resume Mode Callbacks do not use Compiler abstraction
                                 ESCAN00047641: Compiler warning: FrXcp.h", line 307: warning (dcc:1479): comma at end of enumerator list ignored
   2011-01-04   2.11.00  hr      ESCAN00046310: AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
                                 ESCAN00047330: Adapt MainFunction for usage with IdentityManagerConfig
   2011-03-03   2.11.01  hr      ESCAN00049062: The SetPduMode shall be pre-compile time configurable
**************************************************************************************************/

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "FrXcp.h"
#include "FrXcp_Cbk.h"

#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  #include "Det.h"              /* Include Diagnostic Event Manager */
#endif

#include "FrIf.h"               /* Include FrIf APIs */


/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
/* Check consistency of Protocol and Transport Layer. */
#if ( CP_XCP_VERSION < 0x0116u )
  #error "XCP Protocol Layer and XCP on FlexRay Transport Layer are inconsistent!"
#endif

/* Check consistency of source and header file. */
#if defined ( CP_XCPONFRASR_VERSION )
  #if ( CP_XCPONFRASR_VERSION != 0x0211u )
    #error "Source and Header file are inconsistent!"
  #endif
  #if ( CP_XCPONFRASR_RELEASE_VERSION != 0x01u )
    #error "Source and Header file are inconsistent!"
  #endif
#endif

/* Check consistency of DET */
#if defined ( DET_VENDOR_ID )
# if (DET_VENDOR_ID == FRXCP_VENDOR_ID_DEFINITION)
#  if (FRXCP_DEV_ERROR_DETECT == STD_ON)
#   if defined(DET_AR_MAJOR_VERSION) && defined(DET_AR_MINOR_VERSION)
#    if((DET_AR_MAJOR_VERSION != 0x02u) || (DET_AR_MINOR_VERSION != 0x02u))
#     error "Imported module has incompatible AR version - expected DET version is 0x02u.0x02u \
                                                      (DET_AR_MAJOR_VERSION.DET_AR_MINOR_VERSION)."
#    endif
#   endif
#  endif
# endif
#endif

/* Check consistency of FrIf */
#if defined ( FRIF_VENDOR_ID )
# if (FRIF_VENDOR_ID == FRXCP_VENDOR_ID_DEFINITION)
#   if defined(FRIF_AR_MAJOR_VERSION) && defined(FRIF_AR_MINOR_VERSION)
#     if((FRIF_AR_MAJOR_VERSION != 0x03u) || (FRIF_AR_MINOR_VERSION != 0x00u))
#      error "Imported module has incompatible AR version - expected FRIF version is 0x03u.0x00u \
                                                      (FRIF_AR_MAJOR_VERSION.FRIF_AR_MINOR_VERSION)."
#     endif
#   endif
# endif
#endif


/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/


/****************************************************************************/
/* 16 Bit Constants for export                                              */
/****************************************************************************/
#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_CONST_16BIT
  #include "MemMap.h"
#endif

CONST(uint16, FRXCP_CONST) FRXCP_VENDOR_ID = (uint16)FRXCP_VENDOR_ID_DEFINITION; /* Vector = 30 */

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CONST_16BIT
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/****************************************************************************/
/* 8 Bit Constants for export                                               */
/****************************************************************************/
#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_CONST_8BIT
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif

CONST(uint8, FRXCP_CONST) FRXCP_MODULE_ID     = (uint8)FRIF_MODULE_ID_DEFINITION;  /* XCP on FlexRay = 211 */
CONST(uint8, FRXCP_CONST) FRXCP_MAJOR_VERSION = (uint8)(CP_XCPONFRASR_VERSION >> 8u); /* Major version number */
CONST(uint8, FRXCP_CONST) FRXCP_MINOR_VERSION = (uint8)(CP_XCPONFRASR_VERSION & 0xFF);/* Minor version number */
CONST(uint8, FRXCP_CONST) FRXCP_PATCH_VERSION = (uint8)CP_XCPONFRASR_RELEASE_VERSION; /* Patch level version number */

#if ( FRXCP_USE_DECOUPLED_MODE == STD_ON )
  /* PRQA S 3453 2 *//* MISRA-C:2004 Rule 19.7, the following MACROS are used for better readability of the code */
  #define FRXCP_NUMBER_OF_TRANSMITFRAMECACHE FRXCP_NUM_TX_LPDUIDS
  #define FRXCP_TFC_IDX(Index) (Index)
#else
STATIC CONST(uint8, FRXCP_CONST) LPDU_TO_BUFFER[8] = 
{ (uint8)0u, (uint8)0u, (uint8)1u, (uint8)1u, (uint8)2u, (uint8)2u, (uint8)2u, (uint8)2u };
  /* PRQA S 3453 2 *//* MISRA-C:2004 Rule 19.7, the following MACROS are used for better readability of the code */
  #define FRXCP_NUMBER_OF_TRANSMITFRAMECACHE 3u
  #define FRXCP_TFC_IDX(Index) LPDU_TO_BUFFER[(FrXcpRtConfig[Index].FrXcpPduAttributes >> 2u) & 0x07]
#endif

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CONST_8BIT
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/**************************************************************************************************
* Macros
**************************************************************************************************/
/* PRQA S 3453 3 *//* MISRA-C:2004 Rule 19.7, For easy adaptation purposes these Macros are used */
#define FRXCP_TRANSMIT(FrXcpTxPduId, PduInfoPtr) FrIf_Transmit(FrXcpTxPduId, PduInfoPtr)
#define FRXCP_COPY(dest, src, length) XcpMemCpy( (DAQBYTEPTR)(dest), (MEMORY_ROM DAQBYTEPTR)(src), (uint8)(length) )
#define FRXCP_MEMSET(dest, length, value) XcpMemSet( (BYTEPTR)(dest), (uint16)(length), (uint8)(value) )

#define MAX(a, b)   ((a) > (b) ? (a) : (b))

/* Adjust according to alignment requirements */
#if ((XCP_ALIGNMENT_MASK) > 0u)
  #define XCP_ALIGN(idx) ((idx) | (uint8)XCP_ALIGNMENT_MASK)
#else
  #define XCP_ALIGN(idx) (idx)
#endif

/* Macro for platform independent 16Bit access */
#if defined ( C_CPUTYPE_BIGENDIAN )  /* Avoid WORD access */
  #define GET_ARCHITECTURE_DEPENDANT_UI16(pt, idx) (((uint16)((pt)[(idx)+0u]) << 8u) | (uint16)((pt)[(idx)+1u]))
#else
  #define GET_ARCHITECTURE_DEPENDANT_UI16(pt, idx) (((uint16)((pt)[(idx)+1u]) << 8u) | (uint16)((pt)[(idx)+0u]))
#endif

/* Activation control macros */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  #define FrXcpCheckControlState( )               { if ( FrXcp_ControlState == (uint8)kXcponFr_Control_Disable ) { return; } }
  #define FrXcpCheckControlStateRet( ret_value )  { if ( FrXcp_ControlState == (uint8)kXcponFr_Control_Disable ) { return( ret_value ); } }
#else
  #define FrXcpCheckControlState( )
  #define FrXcpCheckControlStateRet( ret_value )
#endif

/* Macro for determining xcp frame type */
#define XCP_GET_XCP_FRAME_TYPE(frame) (((frame)[PID_OFFSET] > (uint8)PID_TYPE_DAQ) ? LPDU_LOOKUP[(uint8)(~msg[PID_OFFSET])] : (uint8)LPDU_TYPE_DAQ)

/* Sequence counter handling */
#if ( CTR_FRAME_OFFSET > 0 )
  #define EMBOSS_TFC_SEQUENCE_COUNTER(PduHandle) ((FrXcp_TransmitFrameCache[FRXCP_TFC_IDX(PduHandle)]).fc[CTR_FRAME_OFFSET] = FrXcp_GlobalSequenceCounter)
  #define INCREMENT_SEQUENCE_COUNTER() FrXcp_GlobalSequenceCounter++
#else
  #define EMBOSS_TFC_SEQUENCE_COUNTER(PduHandle)
  #define INCREMENT_SEQUENCE_COUNTER()
#endif

/* Overrun handling */
#if defined ( XCP_ENABLE_DAQ_OVERRUN_INDICATION ) && ( FRXCP_USE_TX_TASK == STD_OFF ) && ( FRXCP_CONFIRMATION_SERIALIZED == STD_OFF )
  #define XCP_MEMORIZE_OVERRUN() FrXcp_FrameOverrun = OVERFLOW_INDICATION_FLAG
  #define XCP_TRANSFER_OVERRUN(PduHandle, Position) do { FrXcp_TransmitFrameCache[FRXCP_TFC_IDX(PduHandle)].fc[Position] |= FrXcp_FrameOverrun; \
                                                         FrXcp_FrameOverrun = 0; \
                                                       } while(0)
#else
  #define XCP_MEMORIZE_OVERRUN()
  #define XCP_TRANSFER_OVERRUN(PduHandle, Position)
#endif

/* Frame concatenation handling */
#if ( FRXCP_FRAME_CONCATENATION == STD_ON )
#define INSERT_TFC_XCP_FRAME(PduHandle, msg, len) do { \
                                                       FrXcp_TransmitFrameCache[FRXCP_TFC_IDX(PduHandle)].fc[FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)]] = (len); \
                                                       FRXCP_COPY(&(FrXcp_TransmitFrameCache[FRXCP_TFC_IDX(PduHandle)].fc[FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)]+(uint8)1u]), msg, len); \
                                                       XCP_TRANSFER_OVERRUN(PduHandle, FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)]+1u); \
                                                       FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] += ((len) + (uint8)1u); \
                                                       FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] = XCP_ALIGN(FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)]); \
                                                     } while(0)
#define FINALIZE_TFC(PduHandle)                   do { \
                                                       FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] += (uint8)1u; \
                                                       if((FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] > XCP_GET_CURRENT_MAX_FLX_LEN_BUF(PduHandle)) \
                                                       || ((uint8)0u == FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)])) \
                                                       { FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] = XCP_GET_CURRENT_MAX_FLX_LEN_BUF(PduHandle); } \
                                                       else \
                                                       { FrXcp_TransmitFrameCache[FRXCP_TFC_IDX(PduHandle)].fc[FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)]-(uint8)1u] = (uint8)0u; } \
                                                     } while(0)
#else
#define INSERT_TFC_XCP_FRAME(PduHandle, msg, len) do { FRXCP_COPY(&(FrXcp_TransmitFrameCache[FRXCP_TFC_IDX(PduHandle)].fc[XCP_FRAME_START]), msg, len); \
                                                       FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] += (len); \
                                                       XCP_TRANSFER_OVERRUN(PduHandle, XCP_FRAME_START); \
                                                     } while(0)
#define FINALIZE_TFC(PduHandle)
#endif

#define CREATE_TFC_HEADER(PduHandle) do { EMBOSS_TFC_SEQUENCE_COUNTER(PduHandle); \
                                          FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] = (uint8)HEADER_SIZE; \
                                        } while(0)
#define GET_TFC_PTR(PduHandle) ((P2VAR(uint8, AUTOMATIC, FRXCP_VAR_NOINIT))&(FrXcp_TransmitFrameCache[FRXCP_TFC_IDX(PduHandle)].fc[0]))
#define GET_TFC_LENGTH(PduHandle) FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)]
#define SET_TFC_LENGTH(PduHandle, Length) FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] = (Length)

#if ( FRXCP_USE_DECOUPLED_MODE == STD_ON )
  #define XCP_RESERVE_PDU(PduHandle) FrXcpRtConfig[PduHandle].FrXcpPduAttributes |= (XcpPacketType)LPDU_TYPE_BUSY
  #define XCP_FREE_PDU(PduHandle) do { FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] = (uint8)0u; \
                                       FrXcpRtConfig[PduHandle].FrXcpPduAttributes &= (XcpPacketType)~LPDU_TYPE_BUSY; \
                                     } while(0)
#else
  #define XCP_RESERVE_PDU(PduHandle) do { FrXcpRtConfig[PduHandle].FrXcpPduAttributes |= (XcpPacketType)LPDU_TYPE_BUSY; \
                                          FrXcp_AggregatedLength[FRXCP_TFC_IDX(PduHandle)] = (uint8)0; \
                                        } while(0)
  #define XCP_FREE_PDU(PduHandle) FrXcpRtConfig[PduHandle].FrXcpPduAttributes &= (XcpPacketType)~LPDU_TYPE_BUSY
#endif

#define XCP_GET_CURRENT_PDUID(PduHandle) FrXcpPduDescriptorList[PduHandle].XcpPduId
#define XCP_GET_CURRENT_MAX_FLX_LEN_BUF(PduHandle) FrXcpRtConfig[PduHandle].FrXcpPduLength


#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  /* Check of initialization. */
  #define CheckInitialization(ApiId)    { if (FrXcp_Initialized == XCP_UNINIT) { Det_ReportError( (uint16)FRXCP_MODULE_ID, (uint8)0u, (uint8)(ApiId), (uint8)FRXCP_E_NO_INIT ); return; } }
  #define CheckInitializationRet(ApiId) { if (FrXcp_Initialized == XCP_UNINIT) { Det_ReportError( (uint16)FRXCP_MODULE_ID, (uint8)0u, (uint8)(ApiId), (uint8)FRXCP_E_NO_INIT ); return(E_NOT_OK); } }
  /* Reporting of error to Det. */
  #define ReportError(ApiId, Error)     ( Det_ReportError( (uint16)FRXCP_MODULE_ID, (uint8)0u, (uint8)(ApiId), (uint8)(Error) ) )
#else
  /* Check of initialization. */
  #define CheckInitialization(ApiId)
  #define CheckInitializationRet(ApiId)
  /* Reporting of error to Det. */
  #define ReportError(ApiId, Error)
#endif



/**************************************************************************************************
* Typedef and Struct definitions
**************************************************************************************************/

/* PRQA S 0750 5 *//* MISRA-C:2004 Rule 18.4, A union is used to enforce proper memory alignment */
typedef union
{
  uint8  fc[FRXCP_PDU_SIZE];
  uint32 dw[(FRXCP_PDU_SIZE)/4u]; /* This is to force proper alignment */
} FrXcpAlignedFrameCacheType;



/**************************************************************************************************
* Data definitions
**************************************************************************************************/

/******************************************************************************/
/* Local Data definitions with unspecified size                               */
/******************************************************************************/
#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif

/* The buffers are for Transmission caching of FlexRay-Frames */
STATIC VAR(FrXcpAlignedFrameCacheType, FRXCP_VAR_NOINIT) FrXcp_TransmitFrameCache[FRXCP_NUM_TX_LPDUIDS];

#if ( FRXCP_USE_RX_TASK == STD_ON )
STATIC VAR(FrXcpAlignedFrameCacheType, FRXCP_VAR_NOINIT) FrXcp_ReceiveFrameCache[FRXCP_NUM_RX_LPDUIDS];
#endif

STATIC VAR(FrXcp_InitStatusType, FRXCP_VAR_NOINIT) FrXcp_Initialized;

/* Used length of pdu buffer */
STATIC VAR(PduLengthType, FRXCP_VAR_NOINIT) FrXcp_AggregatedLength[FRXCP_NUMBER_OF_TRANSMITFRAMECACHE];

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/******************************************************************************/
/* Local Data definitions with 8Bit size                                      */
/******************************************************************************/
#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_VAR_NOINIT_8BIT
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif

#if defined ( XCP_ENABLE_DAQ_OVERRUN_INDICATION ) && ( FRXCP_USE_TX_TASK == STD_OFF )
STATIC VAR(uint8, FRXCP_VAR_NOINIT) FrXcp_FrameOverrun; /* odts got lost */
#endif

#if ( CTR_FRAME_OFFSET > 0 )
/* The global Sequence Counter, incremented after each L-PDU */
STATIC VAR(uint8, FRXCP_VAR_NOINIT) FrXcp_GlobalSequenceCounter;
#endif

#if ( FRXCP_USE_RX_TASK == STD_ON )
/* Receive frame flag */
STATIC VAR(uint8, FRXCP_VAR_NOINIT) FrXcp_ReceiveFrameSignal[FRXCP_NUM_RX_LPDUIDS];
#endif

/* Send Queue Variables */
#if ( FRXCP_USE_TX_TASK == STD_ON )
STATIC VAR(uint8, FRXCP_VAR_NOINIT) sq_len;
STATIC P2CONST(uint8, FRXCP_VAR_NOINIT, FRXCP_APPL_DATA) sq_msg;
#endif

/* TL Enable/Disable state */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
STATIC VAR(uint8, FRXCP_VAR_NOINIT) FrXcp_ControlState;
#endif

#if ( FRXCP_USE_PDUMODE == STD_ON )
STATIC VAR(uint8, FRXCP_VAR_NOINIT) FrXcp_PduState;
#endif

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_VAR_NOINIT_8BIT
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/**************************************************************************************************
* Prototypes for local functions
**************************************************************************************************/
#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_CODE
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif

#if ( FRXCP_USE_TX_TASK == STD_ON )
STATIC FUNC(uint8, FRXCP_CODE) FrXcp_SendHandling( VAR(uint8, AUTOMATIC) len, P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR) msg );
#endif
STATIC FUNC(uint8, FRXCP_CODE) FrXcp_GetFreePdu( XcpPacketType pduFilter, uint8 *pduIndex );

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CODE
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/**************************************************************************************************
*  Implementation
**************************************************************************************************/

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_CODE
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/**************************************************************************************************
   Function name    : FrXcp_GetFreePdu
   ------------------------------------------------------------------------------------------------
   Description      : Initializes the Hash Tables used for fast PDU locationing
   ------------------------------------------------------------------------------------------------
   Called by        : FrXcp
   ------------------------------------------------------------------------------------------------
   Parameter        : pduFilter
                      pduIndex
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
STATIC FUNC(uint8, FRXCP_CODE) FrXcp_GetFreePdu( XcpPacketType pduFilter, uint8 *pduIndex )
{
  uint8_least i;
  for( i=0; i<FRXCP_NUM_TX_LPDUIDS; i++ )
  {
    if( (FrXcpRtConfig[i].FrXcpPduAttributes & (pduFilter | (XcpPacketType)LPDU_TYPE_BUSY))
         == pduFilter )
    {
      if( ((pduFilter & (XcpPacketType)LPDU_TYPE_EV) == (XcpPacketType)LPDU_TYPE_EV) )
      {
        if ((FrXcpRtConfig[i].FrXcpPduAttributes & (XcpPacketType)LPDU_TYPE_EVTBLOCKED) != (XcpPacketType)LPDU_TYPE_EVTBLOCKED)
        {
          *pduIndex = (uint8)i;
          return((uint8)XCP_E_OK);
        }
      }
      else
      {
        *pduIndex = (uint8)i;
        return((uint8)XCP_E_OK);
      }
    }
  }
  return((uint8)XCP_E_NOT_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, This function has more than one return
                      path by design of ressource/runtime optimization */


/**************************************************************************************************
   Function name    : FrXcp_TxConfirmation
   ------------------------------------------------------------------------------------------------
   Description      : This function is called by a lower layer if the respective L-PDU has been
                      transmitted
   ------------------------------------------------------------------------------------------------
   Called by        : Lower Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : XcpTxPduId - ID of XCP L-PDU that has been transmitted
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_TxConfirmation
(
  VAR(PduIdType, AUTOMATIC) XcpTxPduId
)
{
  /* Will not be interrupted by other functions, is normally called in interrupt context itself */
  /* Check of initialization. */
  CheckInitialization(FRXCP_TXCONFIRMATION_SERVICE_ID)

  /* Check PDU Range */
#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  if(XcpTxPduId >= (PduIdType)FRXCP_NUM_TX_LPDUIDS)
  {
    ReportError(FRXCP_TXCONFIRMATION_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return;
  }
#endif

  /* Activation control */
  FrXcpCheckControlState()

  /* Return this PDU to our pool */
  XCP_FREE_PDU((uint8)XcpTxPduId);
  #if ( FRXCP_TRANSMIT_WITHIN_CONFIRMATION == STD_ON ) && ( FRXCP_USE_TX_TASK == STD_ON )
    while( (sq_len > (uint8)0u) && (XCP_TP_OK == FrXcp_SendHandling(sq_len, sq_msg)) )
    {
      /* sq_len is set by FrXcp_Send */
      sq_len  = (uint8)0u;
      (void)XcpSendCallBack();
    }
    #if( FRXCP_FLUSH_WITHIN_CONFIRMATION == STD_ON )
      FrXcp_SendFlush((uint8)XCP_FLUSH_DTO);
    #endif
  #endif
  #if ( FRXCP_CONFIRMATION_SERIALIZED == STD_ON )
    (void)XcpSendCallBack();
    FrXcp_SendFlush((uint8)XCP_FLUSH_DTO);
  #endif
}/* PRQA S 2006 *//* MISRA-C:2004 14.7, This function has more than one return
                      path by design of ressource/runtime optimization */

/**************************************************************************************************
   Function name    : FrXcp_RxIndication
   ------------------------------------------------------------------------------------------------
   Description      : This function is called by a lower layer if a XCP L-PDU has been received
   ------------------------------------------------------------------------------------------------
   Called by        : Lower Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : XcpRxPduId - ID of the L-PDU that has been received
                      SduPtr - Pointer to received L-PDU
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
#if ( FRXCP_USE_PDUINFOTYPE == STD_ON )
extern FUNC(void, FRXCP_CODE) FrXcp_RxIndication
(
  VAR(PduIdType, AUTOMATIC) XcpRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, FRXCP_APPL_VAR) PduInfoPtr
)
#else
FUNC(void, FRXCP_CODE) FrXcp_RxIndication
(
  VAR(PduIdType, AUTOMATIC) XcpRxPduId,
  P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR) SduPtr
)
#endif
{
  PduLengthType maxLength;
  #if ( FRXCP_USE_PDUINFOTYPE == STD_ON )
    uint8 *SduPtr;
    SduPtr = PduInfoPtr->SduDataPtr;
    maxLength = PduInfoPtr->SduLength;
  #else
    maxLength = XCP_GET_CURRENT_MAX_FLX_LEN_BUF(XcpRxPduId + FrXcpNumberOfTxPdus);
  #endif

  /* Will not be interrupted by other functions, is normally called in interrupt context itself */
  /* Check of initialization. */
  CheckInitialization(FRXCP_RXINDICATION_SERVICE_ID)

#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  /* Check PDU Range */
  if(XcpRxPduId >= (PduIdType)FRXCP_NUM_RX_LPDUIDS)
  {
    ReportError(FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return;
  }
  /* Check for NULL pointer */
  if(SduPtr == (P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR))NULL_PTR)
  {
    ReportError(FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_INV_POINTER);
    return;
  }
#endif

  /* Activation control */
  FrXcpCheckControlState()

  /* Is this PDU addressed for us? */
  if( FrXcpNAX == SduPtr[NAX_FRAME_OFFSET] )
  {
    #if ( FRXCP_USE_RX_TASK == STD_OFF )
      #if ( FRXCP_FRAME_CONCATENATION == STD_OFF )
        /* Process command */
        if(0xff == SduPtr[XCP_FRAME_START])
        { /* In case of connect we set this as active TL */
          XcpSetActiveTl(kFrXcpMaxCTO, kFrXcpMaxDTO, XCP_TRANSPORT_LAYER_FR);
        }
        if( XCP_TRANSPORT_LAYER_FR == XcpGetActiveTl() )
        {
          /* PRQA S 0310 1 *//* MISRA-C:2004 Rule 11.4, proper alignment guaranteed by union */
          XcpCommand((P2CONST(uint32, AUTOMATIC, FRXCP_VAR_NOINIT))&SduPtr[XCP_FRAME_START]);
        }
      #else
        {
          VAR(uint16, AUTOMATIC) frame_idx;
          frame_idx = XCP_FRAME_START;

          while((SduPtr[frame_idx] > (uint8)0u) && /* Is the length > 0? */
                ((frame_idx + (uint16)SduPtr[frame_idx] + (uint16)1) <= (uint16)maxLength) ) /* Is it within PDU size? */
          {
            /* Process command */
            if(0xff == SduPtr[frame_idx + 1u])
            { /* In case of connect we set this as active TL */
              XcpSetActiveTl(kFrXcpMaxCTO, kFrXcpMaxDTO, XCP_TRANSPORT_LAYER_FR);
            }
            if( XCP_TRANSPORT_LAYER_FR == XcpGetActiveTl() )
            {
              /* PRQA S 0310 1 *//* MISRA-C:2004 Rule 11.4, proper alignment guaranteed by union */
              XcpCommand((P2CONST(uint32, AUTOMATIC, FRXCP_VAR_NOINIT))&SduPtr[frame_idx + 1u]);
            }

            /* Move to next possible xcp-frame */
            frame_idx += ((uint16)SduPtr[frame_idx] + (uint8)1u);
            /* Adjust according to alignment requirements */
            frame_idx = XCP_ALIGN(frame_idx);
          }
        }
      #endif

    #else

      /* Copy the received frame to a temporary buffer */
      FRXCP_COPY( &(FrXcp_ReceiveFrameCache[XcpRxPduId].fc[0]), &SduPtr[0], maxLength );
      /* Check if reception overflow happened */
      #if( FRXCP_DEV_ERROR_DETECT == STD_ON )
        if( FrXcp_ReceiveFrameSignal[XcpRxPduId] > (uint8)0u )
        {
          ReportError(FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_RX_BUFFER_OVERFLOW);
          return;
        }
      #endif
      /* And memorize reception */
      FrXcp_ReceiveFrameSignal[XcpRxPduId] = (uint8)1u;
    #endif
    /* FRXCP_USE_RX_TASK */
  }
}/* PRQA S 2006 *//* MISRA-C:2004 14.7, This function has more than one return
                      path by design of ressource/runtime optimization */

/**************************************************************************************************
   Function name    : FrXcp_TriggerTransmit
   ------------------------------------------------------------------------------------------------
   Description      : This function is called by a lower layer when a L-PDU has to be transmitted
   ------------------------------------------------------------------------------------------------
   Called by        : Lower Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : XcpTxPduId - ID of L-PDU that has been triggered
                      SduPtr - Pointer to triggered L-PDU ID
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
#if ( FRXCP_USE_PDUINFOTYPE == STD_ON )
FUNC(Std_ReturnType, FRXCP_CODE) FrXcp_TriggerTransmit
(
  VAR(PduIdType, AUTOMATIC) XcpTxPduId,
  P2VAR(PduInfoType, AUTOMATIC, FRXCP_APPL_VAR) PduInfoPtr
)
{
  /* Will not be interrupted by other functions, is normally called in interrupt context itself */
  /* Check of initialization. */
  CheckInitializationRet(FRXCP_TRIGGERTRANSMIT_SERVICE_ID)

#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  /* Check PDU Range */
  if(XcpTxPduId >= FRXCP_NUM_TX_LPDUIDS)
  {
    ReportError(FRXCP_TRIGGERTRANSMIT_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return(E_NOT_OK);
  }
  /* Check for NULL pointer */
  if(PduInfoPtr->SduDataPtr == (P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR))NULL_PTR)
  {
    ReportError(FRXCP_TRIGGERTRANSMIT_SERVICE_ID, FRXCP_E_INV_POINTER);
    return(E_NOT_OK);
  }
#endif
  /* Activation control */
  FrXcpCheckControlStateRet(E_NOT_OK)
  FRXCP_COPY(PduInfoPtr->SduDataPtr, GET_TFC_PTR(XcpTxPduId), GET_TFC_LENGTH(XcpTxPduId));
  PduInfoPtr->SduLength = GET_TFC_LENGTH(XcpTxPduId);
  return(E_OK);
}/* PRQA S 2006 *//* MISRA-C:2004 14.7, This function has more than one return
                      path by design of ressource/runtime optimization */
#else
FUNC(void, FRXCP_CODE) FrXcp_TriggerTransmit
(
  VAR(PduIdType, AUTOMATIC) XcpTxPduId,
  P2VAR(uint8, AUTOMATIC, FRXCP_APPL_VAR) SduPtr
)
{
  /* Will not be interrupted by other functions, is normally called in interrupt context itself */
  /* Check of initialization. */
  CheckInitialization(FRXCP_TRIGGERTRANSMIT_SERVICE_ID)

#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  /* Check PDU Range */
  if(XcpTxPduId >= FRXCP_NUM_TX_LPDUIDS)
  {
    ReportError(FRXCP_TRIGGERTRANSMIT_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return;
  }
  /* Check for NULL pointer */
  if(SduPtr == (P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR))NULL_PTR)
  {
    ReportError(FRXCP_TRIGGERTRANSMIT_SERVICE_ID, FRXCP_E_INV_POINTER);
    return;
  }
#endif
  /* Activation control */
  FrXcpCheckControlState()
  FRXCP_COPY(SduPtr, GET_TFC_PTR(XcpTxPduId), GET_TFC_LENGTH(XcpTxPduId));
}/* PRQA S 2006 *//* MISRA-C:2004 14.7, This function has more than one return
                      path by design of ressource/runtime optimization */
#endif


#if defined ( XCP_ENABLE_DAQ ) && defined ( XCP_ENABLE_DAQ_RESUME )
/**************************************************************************************************
   Function name    : FrXcp_DaqResumeStore
   ------------------------------------------------------------------------------------------------
   Description      : This function is called in order to trigger storage of configuration data
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_DaqResumeStore( void )
{
  ApplXcpDaqTlResumeStore( &FrXcpRtConfig[0] );
}

/**************************************************************************************************
   Function name    : FrXcp_DaqResumeClear
   ------------------------------------------------------------------------------------------------
   Description      : This function is called in order to clear stored configuration data
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_DaqResumeClear( void )
{
  ApplXcpDaqTlResumeClear();
}
#endif


/**************************************************************************************************
   Function name    : FrXcp_InitMemory
   ------------------------------------------------------------------------------------------------
   Description      : Initialize the XCP on FlexRay Transport Layer variables
   ------------------------------------------------------------------------------------------------
   Called by        : Application
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_InitMemory( void )
{
  FrXcp_Initialized = XCP_UNINIT;
}


/**************************************************************************************************
   Function name    : FrXcp_Init
   ------------------------------------------------------------------------------------------------
   Description      : Initialize the XCP on FlexRay Transport Layer
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_Init( void )
{
  VAR(uint8, AUTOMATIC) i;

  FrXcp_Initialized = XCP_UNINIT;

  ApplXcpInterruptDisable();
  /* Initialize volatile Pdu filter list */
  i = FrXcpPduDescriptorListSize;
  while( i > (uint8)0u )
  {
    i--;
    FrXcpRtConfig[i].FrXcpPduAttributes = FrXcpPduDescriptorList[i].XcpPacketFilter;
    FrXcpRtConfig[i].FrXcpPduLength = FrXcpPduDescriptorList[i].MaxFlxLenBuf;
  }

  i = (uint8)FRXCP_NUMBER_OF_TRANSMITFRAMECACHE;
  while( i > (uint8)0u )
  {
    i--;
    FrXcp_TransmitFrameCache[i].fc[NAX_FRAME_OFFSET] = FrXcpNAX;
    FrXcp_AggregatedLength[i] = (uint8)0u;
  }

  #if ( FRXCP_USE_RX_TASK == STD_ON )
    XcpMemSet(FrXcp_ReceiveFrameSignal, (uint16)sizeof(FrXcp_ReceiveFrameSignal), (uint8)0x00);
  #endif

  /* Check if we have to use Resume Mode */
#if defined ( XCP_ENABLE_DAQ )
  #if defined ( XCP_ENABLE_DAQ_RESUME )
    ApplXcpDaqTlResume( &FrXcpRtConfig[0] );
  #endif
#endif

#if defined ( XCP_ENABLE_DAQ_OVERRUN_INDICATION ) && ( FRXCP_USE_TX_TASK == STD_OFF )
  FrXcp_FrameOverrun = (uint8)0u;
#endif

#if (CTR_FRAME_OFFSET > 0)
  FrXcp_GlobalSequenceCounter = (uint8)0u;
#endif

#if ( FRXCP_USE_TX_TASK == STD_ON )
  sq_len = (uint8)0u;
  sq_msg = (P2CONST(uint8, FRXCP_VAR_NOINIT, FRXCP_APPL_DATA))NULL_PTR;
#endif

#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  FrXcp_ControlState = (uint8)kXcponFr_Control_Enable;
#endif

#if ( FRXCP_USE_PDUMODE == STD_ON )
  FrXcp_PduState = FRXCP_SET_OFFLINE;
#endif

  ApplXcpInterruptEnable();

  FrXcp_Initialized = XCP_INIT;
}


/**************************************************************************************************
   Function name    : FrXcp_TLService
   ------------------------------------------------------------------------------------------------
   Description      : This function handles custom, Transport Layer specific commands which are:
                      CMD_FLX_ASSIGN
                      CMD_FLX_ACTIVATE
                      CMD_FLX_DEACTIVATE
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : pCmd: Pointer to cmd string
   ------------------------------------------------------------------------------------------------
   Returncode       : error code
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(uint8, FRXCP_CODE) FrXcp_TLService
(
  P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR) pCmd
)
{
  /* Activation control */
  FrXcpCheckControlStateRet( (uint8)XCP_CMD_DENIED )
  switch( pCmd[TL_CMD_IDX] )
  {
    /* ------------------------- CMD_FLX_ASSIGN ------------------------- */
    case (uint8)CMD_FLX_ASSIGN : 
    {
      /*---------------------------------------------------------------------------*/
      /* FLX_ASSIGN Frame plausibility checks */
      if( ((uint8)0xFFu == pCmd[FLX_BUF_IDX]) &&
          ((uint8)LPDU_TYPE_VARIABLE == pCmd[XCP_PACKET_TYPE_IDX]) )
      { /* We have to perform a complete reset */
        FrXcp_Init();
        return((uint8)XCP_CMD_OK);
      }
      else
      if( pCmd[FLX_BUF_IDX] >= FrXcpPduDescriptorListSize )
      { /* If the buffer index is out of range, we return XCP_CMD_OUT_OF_RANGE error */
        return((uint8)XCP_CMD_OUT_OF_RANGE);
      }
      else
      {
        ; /* Concluding else */
      }

      if( pCmd[MAX_FLX_LEN_BUF_IDX] > FrXcpPduDescriptorList[pCmd[FLX_BUF_IDX]].MaxFlxLenBuf )
      {
        return((uint8)XCP_CMD_OUT_OF_RANGE);
      }

      /*---------------------------------------------------------------------------*/
      /* Reconfigure Buffer */
      if( 1 == FrXcpPduDescriptorList[pCmd[FLX_BUF_IDX]].IsReconfigurable )
      {
        ApplXcpInterruptDisable();
        /* Store new buffer length */
        FrXcpRtConfig[pCmd[FLX_BUF_IDX]].FrXcpPduLength = pCmd[MAX_FLX_LEN_BUF_IDX];

        if( (uint8)LPDU_TYPE_VARIABLE == pCmd[XCP_PACKET_TYPE_IDX] )
        { /* We have to reset our current PDU to its initial setting */
          FrXcpRtConfig[pCmd[FLX_BUF_IDX]].FrXcpPduAttributes = FrXcpPduDescriptorList[pCmd[FLX_BUF_IDX]].XcpPacketFilter;
          FrXcpRtConfig[pCmd[FLX_BUF_IDX]].FrXcpPduLength = FrXcpPduDescriptorList[pCmd[FLX_BUF_IDX]].MaxFlxLenBuf;
        }

        FrXcpRtConfig[pCmd[FLX_BUF_IDX]].FrXcpPduAttributes = (pCmd[XCP_PACKET_TYPE_IDX] & (XcpPacketType)XCP_PACKET_FILTER_MASK)
                                                                                         | (XcpPacketType)LPDU_TYPE_EVTBLOCKED;
        ApplXcpInterruptEnable();
      }
      else
      {
        return((uint8)XCP_CMD_DENIED);
      }

      return((uint8)XCP_CMD_OK);
    }


    /* ------------------------- CMD_FLX_ACTIVATE ------------------------- */
	case (uint8)CMD_FLX_ACTIVATE :
    {
      ApplXcpInterruptDisable();
      if((FrXcpRtConfig[pCmd[FLX_BUF_IDX]].FrXcpPduAttributes & (XcpPacketType)LPDU_TYPE_EV) > (XcpPacketType)0u)
      {
        FrXcpRtConfig[pCmd[FLX_BUF_IDX]].FrXcpPduAttributes &= (XcpPacketType)~LPDU_TYPE_EVTBLOCKED;
        ApplXcpInterruptEnable();
        return((uint8)XCP_CMD_OK);
      }
      ApplXcpInterruptEnable();
      return((uint8)XCP_CMD_OUT_OF_RANGE);
    }

    /* ------------------------- CMD_FLX_DEACTIVATE ------------------------- */
    case (uint8)CMD_FLX_DEACTIVATE :
    {
      ApplXcpInterruptDisable();
      if((FrXcpRtConfig[pCmd[FLX_BUF_IDX]].FrXcpPduAttributes & (XcpPacketType)LPDU_TYPE_EV) > (XcpPacketType)0u)
      {
        FrXcpRtConfig[pCmd[FLX_BUF_IDX]].FrXcpPduAttributes |= (XcpPacketType)LPDU_TYPE_EVTBLOCKED;
        ApplXcpInterruptEnable();
        return((uint8)XCP_CMD_OK);
      }
      ApplXcpInterruptEnable();
      return((uint8)XCP_CMD_OUT_OF_RANGE);
    }

    default :
    {
      ;
    }
  }

  return((uint8)XCP_CMD_UNKNOWN);
}/* PRQA S 2006 *//* MISRA-C:2004 14.7, This function has more than one return
                     path by design of ressource/runtime optimization */

/**************************************************************************************************
   Function name    : FrXcp_Send
   ------------------------------------------------------------------------------------------------
   Description      : Prepare transmission of the referenced frame
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : len: length of message to send
                      msg: pointer to message
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
#if ( FRXCP_USE_TX_TASK == STD_ON )
FUNC(uint8, FRXCP_CODE) FrXcp_Send
(
  VAR(uint8, AUTOMATIC) len,
  P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR) msg
)
{
  sq_msg = msg;
  sq_len = len;
  return( (uint8)XCP_TP_BUSY );
}

STATIC FUNC(uint8, FRXCP_CODE) FrXcp_SendHandling
#else
FUNC(uint8, FRXCP_CODE) FrXcp_Send
#endif
(
  VAR(uint8, AUTOMATIC) len,
  P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR) msg
)
{
  VAR(XcpPacketType, AUTOMATIC) PacketFilter;
  /* PRQA S 0781 1 *//* MISRA-C:2004 Rule 5.6, PduHandle only used locally */
  VAR(uint8, AUTOMATIC)         PduHandle;
  VAR(uint8, AUTOMATIC)         result;

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CODE
  /* PRQA S 5087 4 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
  #define FRXCP_START_SEC_CONST_8BIT
  #include "MemMap.h"
#endif

  STATIC CONST(uint8, FRXCP_CONST) LPDU_LOOKUP[4] =
  { (uint8)LPDU_TYPE_RES, (uint8)LPDU_TYPE_RES, (uint8)LPDU_TYPE_EV, (uint8)LPDU_TYPE_EV };

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CONST_8BIT
  /* PRQA S 5087 4 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
  #define FRXCP_START_SEC_CODE
  #include "MemMap.h"
#endif

  result = (uint8)XCP_TP_OK;
  /* Activation control */
  FrXcpCheckControlStateRet( (uint8)XCP_TP_BUSY )

#if ( FRXCP_USE_PDUMODE == STD_ON )
  if( FRXCP_SET_OFFLINE == FrXcp_PduState )
  { /* We are in offline mode, return and keep message */
    return( (uint8)XCP_TP_BUSY );
  }
#endif

  /* Determine type of current XCP frame */
  PacketFilter = XCP_GET_XCP_FRAME_TYPE(msg);

#if ( FRXCP_FRAME_CONCATENATION == STD_OFF )

  if( (uint8)XCP_E_OK == FrXcp_GetFreePdu( PacketFilter, &PduHandle ) )
  {
    PduInfoType PduInfoStruct;

    CREATE_TFC_HEADER(PduHandle);
    /* The Sequence Counter is incremented individually with each XCP-Frame passed on by the Protocol Layer */
    INCREMENT_SEQUENCE_COUNTER();

    INSERT_TFC_XCP_FRAME(PduHandle, msg, len);

    FINALIZE_TFC(PduHandle);
    PduInfoStruct.SduDataPtr = GET_TFC_PTR(PduHandle);
    PduInfoStruct.SduLength  = (PduLengthType)GET_TFC_LENGTH(PduHandle);
    XCP_RESERVE_PDU(PduHandle);
    if((Std_ReturnType)E_NOT_OK == FRXCP_TRANSMIT(XCP_GET_CURRENT_PDUID(PduHandle), &PduInfoStruct))
    {  /* Transmit error happened */
      XCP_FREE_PDU(PduHandle);
      result = (uint8)XCP_TP_BUSY;
    }
  }
  else
  {
    XCP_MEMORIZE_OVERRUN();
    result = (uint8)XCP_TP_BUSY;
  }

#else /* ( FRXCP_FRAME_CONCATENATION == STD_ON ) */

  if( (uint8)XCP_E_OK == FrXcp_GetFreePdu( PacketFilter, &PduHandle ) )
  {
    #if ( FRXCP_CONFIRMATION_SERIALIZED == STD_ON )
      ApplXcpInterruptDisable();
    #endif
    if( (uint8)0u == GET_TFC_LENGTH(PduHandle) )
    {
      CREATE_TFC_HEADER(PduHandle);
      /* The Sequence Counter is incremented individually with each newly allocated PDU buffer */
      INCREMENT_SEQUENCE_COUNTER();
    }

    if((GET_TFC_LENGTH(PduHandle) + len + (uint8)1u) <= XCP_GET_CURRENT_MAX_FLX_LEN_BUF(PduHandle))
    {
      INSERT_TFC_XCP_FRAME(PduHandle, msg, len);
    }
    else
    {
      PduInfoType PduInfoStruct;
      FINALIZE_TFC(PduHandle);
      PduInfoStruct.SduDataPtr = GET_TFC_PTR(PduHandle);
      PduInfoStruct.SduLength  = (PduLengthType)GET_TFC_LENGTH(PduHandle);
      XCP_RESERVE_PDU(PduHandle);
      if((Std_ReturnType)E_NOT_OK == FRXCP_TRANSMIT(XCP_GET_CURRENT_PDUID(PduHandle), &PduInfoStruct))
      { /* Transmit error happened */
        XCP_FREE_PDU(PduHandle);
        result = (uint8)XCP_TP_BUSY;
      }

      if( (uint8)XCP_E_OK == FrXcp_GetFreePdu( PacketFilter, &PduHandle ) )
      {
        CREATE_TFC_HEADER(PduHandle);
        /* The Sequence Counter is incremented individually with each XCP-Frame passed on by the Protocol Layer */
        INCREMENT_SEQUENCE_COUNTER();
        INSERT_TFC_XCP_FRAME(PduHandle, msg, len);
      }
      else
      {
        if( (uint8)LPDU_TYPE_EV != PacketFilter )
        {
          XCP_MEMORIZE_OVERRUN();
          result = (uint8)XCP_TP_BUSY;
        }
      }
    }
    #if ( FRXCP_CONFIRMATION_SERIALIZED == STD_ON )
      ApplXcpInterruptEnable();
    #endif
  }
  else
  {
    if( (uint8)LPDU_TYPE_EV != PacketFilter )
    {
      XCP_MEMORIZE_OVERRUN();
      result = (uint8)XCP_TP_BUSY;
    }
  }
#endif

#if ( FRXCP_USE_TX_TASK == STD_OFF ) && ( FRXCP_CONFIRMATION_SERIALIZED == STD_OFF )
    (void)XcpSendCallBack();
#endif

  return( result );
}


/**************************************************************************************************
   Function name    : FrXcp_SendFlush
   ------------------------------------------------------------------------------------------------
   Description      : Purge the current Frame Cache.
                      Only needed, when frame concatenation is enabled
   ------------------------------------------------------------------------------------------------
   Called by        : Application: after all XcpEvents per cycle happened before actual transmission
                    : XCP Protocol Layer: when a transmission requires immediate attention (RES/EV)
   ------------------------------------------------------------------------------------------------
   Parameter        : XcpFlushTypeSel: determines which type of xcp frames are flushed
                                       XCP_FLUSH_CTO: Only CTOs are flushed
                                       XCP_FLUSH_DTO: Only DTOs are flushed
                                       XCP_FLUSH_ALL: CTOs and DTOs are flushed
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_SendFlush
(
  VAR(uint8, AUTOMATIC) XcpFlushTypeSel
)
{
#if ( FRXCP_FRAME_CONCATENATION == STD_ON )
  VAR(PduInfoType, AUTOMATIC) PduInfoStruct;
  VAR(uint8, AUTOMATIC)       PduHandle;
  VAR(uint8, AUTOMATIC)       i;
  VAR(uint8, AUTOMATIC)       last;

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CODE
  /* PRQA S 5087 4 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
  #define FRXCP_START_SEC_CONST_8BIT
  #include "MemMap.h"
#endif

#if ( FRXCP_FRAME_CONCATENATION == STD_ON )
  STATIC CONST(uint8, FRXCP_CONST) LPDU_TYPES[3] =
  { (uint8)LPDU_TYPE_RES, (uint8)LPDU_TYPE_EV, (uint8)LPDU_TYPE_DAQ };
#endif

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CONST_8BIT
  /* PRQA S 5087 4 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
  #define FRXCP_START_SEC_CODE
  #include "MemMap.h"
#endif


  /* Activation control */
  FrXcpCheckControlState()

#if ( FRXCP_USE_PDUMODE == STD_ON )
  if( FRXCP_SET_OFFLINE == FrXcp_PduState )
  { /* We are in offline mode, return and keep message */
    return;
  }
#endif

  i = (uint8)0u;
  last = (uint8)sizeof(LPDU_TYPES);
  if(XcpFlushTypeSel == (uint8)XCP_FLUSH_CTO)
  {
    last--;
  }
  else
  if(XcpFlushTypeSel == (uint8)XCP_FLUSH_DTO)
  {
    i += (uint8)2u;
  }
  else
  {
    ; /* Concluding else */
  }

  ApplXcpInterruptDisable();
  /* Check all PDUs */
  for(; i<last; i++)
  {
    if( (uint8)XCP_E_OK == FrXcp_GetFreePdu( LPDU_TYPES[i], &PduHandle ) )
    {
      if( GET_TFC_LENGTH(PduHandle) > (uint8)0u )
      {
        FINALIZE_TFC(PduHandle);
        PduInfoStruct.SduDataPtr = GET_TFC_PTR(PduHandle);
        PduInfoStruct.SduLength  = (PduLengthType)GET_TFC_LENGTH(PduHandle);
        XCP_RESERVE_PDU(PduHandle);
        if((Std_ReturnType)E_NOT_OK == FRXCP_TRANSMIT(XCP_GET_CURRENT_PDUID(PduHandle), &PduInfoStruct))
        { /* Transmit error happened */
          XCP_FREE_PDU(PduHandle);
        }
      }
    }
  }
  ApplXcpInterruptEnable();
#endif /* FRXCP_FRAME_CONCATENATION */
}



#if ( FRXCP_VERSION_INFO_API == STD_ON )
/**************************************************************************************************
   Function name    : FrXcp_GetVersionInfo
   ------------------------------------------------------------------------------------------------
   Description      : Returns version information of module
   ------------------------------------------------------------------------------------------------
   Called by        : Application
   ------------------------------------------------------------------------------------------------
   Parameter        : FrXcpVerInfoPtr: Pointer to location at which version information
                                       shall be stored at
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, FRXCP_APPL_VAR) FrXcpVerInfoPtr
)
{
  /* Since this service only access non-volatile data and no channel parameter is passed,
     checking of the channel handle and initialization is omitted. */
  FrXcpVerInfoPtr->vendorID = FRXCP_VENDOR_ID;
  FrXcpVerInfoPtr->moduleID = (uint8)FRXCP_MODULE_ID;
  #if ( STD_TYPES_AR_MAJOR_VERSION == 0x01 ) && ( STD_TYPES_AR_MINOR_VERSION >= 0x02 )
  FrXcpVerInfoPtr->instanceID       = 0x00u;
  #endif  
  FrXcpVerInfoPtr->sw_major_version = FRXCP_MAJOR_VERSION;
  FrXcpVerInfoPtr->sw_minor_version = FRXCP_MINOR_VERSION;
  FrXcpVerInfoPtr->sw_patch_version = FRXCP_PATCH_VERSION;
}
#endif
  /* FRXCP_VERSION_INFO_API */



/**************************************************************************************************
   Function name    : FrXcp_MainFunctionRx
   ------------------------------------------------------------------------------------------------
   Description      : Cyclic task, must be called for reception processing
   ------------------------------------------------------------------------------------------------
   Called by        : Application
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_MainFunctionRx( void )
{
  /* Activation control */
  FrXcpCheckControlState()

#if ( FRXCP_USE_RX_TASK == STD_ON )
  {
    VAR(uint8_least, AUTOMATIC) pduIdx;

    if( XCP_INIT == FrXcp_Initialized )
    {
      for( pduIdx = (uint8_least)0u; pduIdx < (uint8_least)FRXCP_NUM_RX_LPDUIDS; pduIdx++ )
      {
        ApplXcpInterruptDisable();
        if( FrXcp_ReceiveFrameSignal[pduIdx] > (uint8)0u )
        {
          FrXcp_ReceiveFrameSignal[pduIdx] = (uint8)0u;
          #if ( FRXCP_FRAME_CONCATENATION == STD_OFF )
            /* Process command */
            if(0xff == FrXcp_ReceiveFrameCache[pduIdx].fc[XCP_FRAME_START])
            { /* In case of connect we set this as active TL */
              XcpSetActiveTl(kFrXcpMaxCTO, kFrXcpMaxDTO, XCP_TRANSPORT_LAYER_FR);
            }
            if( XCP_TRANSPORT_LAYER_FR == XcpGetActiveTl() )
            {
              /* PRQA S 0310 1 *//* MISRA-C:2004 Rule 11.4, proper alignment guaranteed by union */
              XcpCommand( (P2CONST(uint32, AUTOMATIC, FRXCP_VAR_NOINIT))&FrXcp_ReceiveFrameCache[pduIdx].fc[XCP_FRAME_START] );
            }
          #else
            {
              uint16 frame_idx;
              frame_idx = (uint16)XCP_FRAME_START;

              while((FrXcp_ReceiveFrameCache[pduIdx].fc[frame_idx] > (uint8)0u) && /* Is the length > 0? */
                    ((frame_idx + (uint16)FrXcp_ReceiveFrameCache[pduIdx].fc[frame_idx] + (uint16)1)
                    <= (uint16)XCP_GET_CURRENT_MAX_FLX_LEN_BUF(pduIdx + FrXcpNumberOfTxPdus)) ) /* Is it within PDU size? */
              {
                /* Process command */
                if(0xff == FrXcp_ReceiveFrameCache[pduIdx].fc[frame_idx + 1u])
                { /* In case of connect we set this as active TL */
                  XcpSetActiveTl(kFrXcpMaxCTO, kFrXcpMaxDTO, XCP_TRANSPORT_LAYER_FR);
                }
                if( XCP_TRANSPORT_LAYER_FR == XcpGetActiveTl() )
                {
                  /* PRQA S 0310 1 *//* MISRA-C:2004 Rule 11.4, proper alignment guaranteed by union */
                  XcpCommand((P2CONST(uint32, AUTOMATIC, FRXCP_VAR_NOINIT))&FrXcp_ReceiveFrameCache[pduIdx].fc[frame_idx + 1u]);
                }

                /* Move to next possible xcp-frame */
                frame_idx += ((uint16)FrXcp_ReceiveFrameCache[pduIdx].fc[frame_idx] + (uint16)1u);
                /* Adjust according to alignment requirements */
                frame_idx = XCP_ALIGN(frame_idx);
              }
            }
          #endif
        }
        ApplXcpInterruptEnable();
      }
    }
  }
#endif
}


/**************************************************************************************************
   Function name    : FrXcp_MainFunctionTx
   ------------------------------------------------------------------------------------------------
   Description      : Cyclic task, must be called for transmission processing
   ------------------------------------------------------------------------------------------------
   Called by        : XcpPl
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_MainFunctionTx( void )
{
#if ( FRXCP_USE_TX_TASK == STD_ON )
  /* Activation control */
  FrXcpCheckControlState()

  if( XCP_INIT == FrXcp_Initialized )
  {
    ApplXcpInterruptDisable();
    /* PRQA S 3415 1 *//* MISRA-C:2004 Rule 12.4, The side effects are wanted for optimization  */
    while( (sq_len > (uint8)0u) && ((uint8)XCP_TP_OK == FrXcp_SendHandling(sq_len, sq_msg)) )
    {
      /* sq_len is set by FrXcp_Send */
      sq_len  = (uint8)0u;
      (void)XcpSendCallBack();
    }
    ApplXcpInterruptEnable();
    FrXcp_SendFlush((uint8)XCP_FLUSH_ALL);
  }
#endif
}


#if ( FRXCP_ENABLE_CONTROL == STD_ON )
/**************************************************************************************************
   Function name    : FrXcp_Control
   ------------------------------------------------------------------------------------------------
   Description      : Enable or disable the component
   ------------------------------------------------------------------------------------------------
   Called by        : Application
   ------------------------------------------------------------------------------------------------
   Parameter        : command: XCP_ENABLE - Activate Transport Layer
                               XCP_DISABLE - Deactivate Transport Layer
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_Control
(
  VAR(uint8, AUTOMATIC) command
)
{
#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  if( ((uint8)XCP_ENABLE != command) && ((uint8)XCP_DISABLE != command) )
  {
    ReportError(FRXCP_CONTROL_ID, FRXCP_E_WRONG_CONTROL_COMMAND);
    return;
  }
#endif

  FrXcp_ControlState = command;
}
#endif


#if ( FRXCP_USE_PDUMODE == STD_ON )
/**************************************************************************************************
   Function name    : CanXcp_SetPduMode
   ------------------------------------------------------------------------------------------------
   Description      : Enable or disable the component
   ------------------------------------------------------------------------------------------------
   Called by        : State Manager
   ------------------------------------------------------------------------------------------------
   Parameter        : command: FRXCP_SET_ONLINE - Activate Transport Layer
                               FRXCP_SET_OFFLINE - Deactivate Transport Layer
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_SetPduMode(NetworkHandleType XcpNwH, FrXcp_PduSetModeType PduMode)
{
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  XcpNwH = XcpNwH;
  #endif

  FrXcp_PduState = PduMode;
}
#endif


#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CODE
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif



/*****************************************************************************/
/* Consistency checks ( XCP Transport Layer on FLX specific )                */
/*****************************************************************************/

/* Check consistency of Transport Layer configuration */
#if defined ( XCP_TRANSPORT_LAYER_TYPE_FLEXRAY_ASR )
#else
  #error "Configuration for Transport Layer on FlexRay doesn't exist!"
#endif

/* Check consistency of alignment switch */
#if defined ( XCP_DISABLE_UNALIGNED_MEM_ACCESS )
  #if defined ( C_CPUTYPE_8BIT )
    #error "XCP consistency error: Forcing alignment for 8-bit microcontrollers is useless."
  #endif
  #if defined ( XCP_ENABLE_UNALIGNED_MEM_ACCESS )
    #error "XCP consistency error: Select either alignment or no alignment."
  #endif
#else /* if defined ( XCP_DISABLE_UNALIGNED_MEM_ACCESS ) */
  #if defined ( XCP_ENABLE_UNALIGNED_MEM_ACCESS )
  #else
    #error "XCP consistency error: Usage of alignment not specified."
  #endif
#endif /* if defined ( XCP_DISABLE_UNALIGNED_MEM_ACCESS ) */

/* C_CPUTYPE_BIGENDIAN or C_CPUTYPE_LITTLEENDIAN must be defined */
#if defined ( C_CPUTYPE_LITTLEENDIAN ) || defined ( C_CPUTYPE_BIGENDIAN )
#else
  #error "Please define C_CPUTYPE_LITTLEENDIAN or C_CPUTYPE_BIGENDIAN"
#endif

/* Tx Task must be used in combination with the Send Queue */
#if ( FRXCP_USE_TX_TASK == STD_ON )
  #if defined ( XCP_ENABLE_SEND_QUEUE ) || defined ( XCP_DISABLE_DAQ )
  #else
    #error "The XCP Send Queue must be enabled if TX Task usage is enabled!"
  #endif
#else
  #if defined ( XCP_ENABLE_SEND_QUEUE ) && defined ( XCP_ENABLE_DAQ )
    #error "The XCP Send Queue must be disabled if TX Task usage is disabled!"
  #else
  #endif
#endif

/* Check range of kXcpMaxCTO and kXcpMaxDTO */
#if (kFrXcpMaxCTO >= 12)
#else
  #error "XCP consistency error: MAX_CTO must be at least 12."
#endif

#if(kFrXcpMaxDTO <= (FRXCP_PDU_SIZE - HEADER_SIZE))
#else
  #error "XCP consistency error: MAX_DTO must not be greater than: "(FRXCP_PDU_SIZE - HEADER_SIZE)
#endif
#if(kFrXcpMaxCTO <= (FRXCP_PDU_SIZE - HEADER_SIZE))
#else
  #error "XCP consistency error: MAX_CTO must not be greater than: "(FRXCP_PDU_SIZE - HEADER_SIZE)
#endif

#if ( FRXCP_FRAME_CONCATENATION != STD_ON ) && ( FRXCP_FRAME_CONCATENATION != STD_OFF )
  #error "XCPonFR consistency error: Set FRXCP_FRAME_CONCATENATION either to STD_ON or STD_OFF."
#endif

#if ( FRXCP_SEQUENCE_COUNTER != STD_ON ) && ( FRXCP_SEQUENCE_COUNTER != STD_OFF )
  #error "XCPonFR consistency error: Set FRXCP_SEQUENCE_COUNTER either to STD_ON or STD_OFF."
#endif

#if ( FRXCP_TRANSMIT_WITHIN_CONFIRMATION != STD_ON ) && ( FRXCP_TRANSMIT_WITHIN_CONFIRMATION != STD_OFF )
  #error "XCPonFR consistency error: Set FRXCP_TRANSMIT_WITHIN_CONFIRMATION either to STD_ON or STD_OFF."
#endif

#if ( FRXCP_USE_DECOUPLED_MODE != STD_ON ) && ( FRXCP_USE_DECOUPLED_MODE != STD_OFF )
  #error "XCPonFR consistency error: Set FRXCP_USE_DECOUPLED_MODE either to STD_ON or STD_OFF."
#endif
