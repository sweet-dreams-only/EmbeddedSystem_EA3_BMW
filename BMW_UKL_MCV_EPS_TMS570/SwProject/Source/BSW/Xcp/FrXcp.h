
/**************************************************************************************************
   Project Name: AUTOSAR XCP on FlexRay Transport Layer
      File Name: FrXcpS.h

    Description: XCP on FlexRay Transport Layer Header File

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
#ifndef __FRXCP_H__
#define __FRXCP_H__

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "ComStack_Types.h"
#include "frxcp_cfg.h"
#include "frxcp_par.h"
#include "XcpProf.h"

  #include "SchM_FrXcp.h"


/**************************************************************************************************
* Version
**************************************************************************************************/

/* BCD coded version number */
/* ##V_CFG_MANAGEMENT ##CQProject : Cp_XcpOnFrAsr CQComponent : Implementation */
#define CP_XCPONFRASR_VERSION         0x0211u
#define CP_XCPONFRASR_RELEASE_VERSION 0x01u


/**************************************************************************************************
* Global defines
**************************************************************************************************/

/* Vendor ID for Vctr Informatik */
#define FRXCP_VENDOR_ID_DEFINITION      30
 /* FlexRay XCP ID */
#define FRIF_MODULE_ID_DEFINITION       211

/* Interrupt enable and disable functions */
#if defined ( ApplXcpInterruptDisable )
#else
    #define ApplXcpInterruptDisable()             SchM_Enter_FrXcp(FRXCP_EXCLUSIVE_AREA_0)
#endif
#if defined ( ApplXcpInterruptEnable )
#else
    #define ApplXcpInterruptEnable()              SchM_Exit_FrXcp(FRXCP_EXCLUSIVE_AREA_0)
#endif

/* Define AUTOSAR types if not defined yet */
#if defined ( STATIC )
#else
  #define STATIC static
#endif

/* Define Vector Standard types if not defined yet. */
/* The AUTOSAR tpes are mapped to the Vector Standard types. */
#if defined ( V_MEMROM0 )
#else
  #define V_MEMROM0
#endif
#if defined ( V_MEMROM1 )
#else
  #define V_MEMROM1
#endif
#if defined ( V_MEMROM2 )
#else
  #define V_MEMROM2 const
#endif

#if !defined ( FRXCP_CONFIRMATION_SERIALIZED )
  #define FRXCP_CONFIRMATION_SERIALIZED STD_OFF
#endif

#if !defined ( FRXCP_USE_PDUMODE )
  #define FRXCP_USE_PDUMODE STD_ON
#endif

#if defined ( FRXCP_FRAME_ALIGNMENT_8BIT )
  #if defined ( FRXCP_FRAME_ALIGNMENT_16BIT ) || defined ( FRXCP_FRAME_ALIGNMENT_32BIT )
    #error "XCP consistency error: Select either FRXCP_FRAME_ALIGNMENT_8BIT or 16- or 32BIT."
  #endif
  #define XCP_ALIGNMENT_MASK 0u
  #define HEADER_FILL_SIZE 0u
  #if ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 1u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 1u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 1u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 1u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 2u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 2u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 2u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 2u
  #else
    #error "XCP consistency error: Either FRXCP_FRAME_PACKING or FRXCP_SEQUENCE_COUNTER not defined within range!"
  #endif
#endif

#if defined ( FRXCP_FRAME_ALIGNMENT_16BIT )
  #if defined ( FRXCP_FRAME_ALIGNMENT_8BIT ) || defined ( FRXCP_FRAME_ALIGNMENT_32BIT )
    #error "XCP consistency error: Select either FRXCP_FRAME_ALIGNMENT_8BIT or 16- or 32BIT."
  #endif
  #define XCP_ALIGNMENT_MASK 1u
  #if ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 2u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 2u
    #define HEADER_FILL_SIZE 1u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 1u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 1u
    #define HEADER_FILL_SIZE 0u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 2u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 2u
    #define HEADER_FILL_SIZE 0u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 3u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 3u
    #define HEADER_FILL_SIZE 1u
  #else
    #error "XCP consistency error: Either FRXCP_FRAME_PACKING or FRXCP_SEQUENCE_COUNTER not defined within range!"
  #endif
#endif

#if defined ( FRXCP_FRAME_ALIGNMENT_32BIT )
  #if defined ( FRXCP_FRAME_ALIGNMENT_8BIT ) || defined ( FRXCP_FRAME_ALIGNMENT_16BIT )
    #error "XCP consistency error: Select either FRXCP_FRAME_ALIGNMENT_8BIT or 16- or 32BIT."
  #endif
  #define XCP_ALIGNMENT_MASK 3u
  #if ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 4u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 4u
    #define HEADER_FILL_SIZE 3u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 3u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 3u
    #define HEADER_FILL_SIZE 2u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 4u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 4u
    #define HEADER_FILL_SIZE 2u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 3u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 3u
    #define HEADER_FILL_SIZE 1u
  #else
    #error "XCP consistency error: Either FRXCP_FRAME_PACKING or FRXCP_SEQUENCE_COUNTER not defined within range!"
  #endif
#endif

#if !defined ( FRXCP_FRAME_ALIGNMENT_8BIT ) && \
    !defined ( FRXCP_FRAME_ALIGNMENT_16BIT ) && \
    !defined ( FRXCP_FRAME_ALIGNMENT_32BIT )
  #error "XCP consistency error: Usage of Transport Layer alignment not specified!"
#endif

#if !defined ( FRXCP_CONFIRMATION_SERIALIZED )
  #define FRXCP_CONFIRMATION_SERIALIZED STD_OFF
#endif

#if !defined ( FRXCP_VERSION_INFO_API )
  #define FRXCP_VERSION_INFO_API STD_OFF
#endif


/* This constant defines the overflow flag */
#define OVERFLOW_INDICATION_FLAG (uint8)0x80u
/* Position of PID in XCP-Frame */
#define PID_OFFSET (uint8)0x00u

#define XCP_PACKET_FILTER_MASK    0x1Fu

#define XCP_E_NOT_OK    1u
#define XCP_E_OK        0u

#define XCP_TP_BUSY     1u
#define XCP_TP_OK       0u

#define XCP_FLUSH_CTO   0u
#define XCP_FLUSH_DTO   1u
#define XCP_FLUSH_ALL   2u


/* Development errors */
#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
/* Definition of the API ID */
  #define FRXCP_INIT_SERVICE_ID                   0u
  #define FRXCP_TLSERVICE_ID                      1u
  #define FRXCP_SENDCTO_ID                        2u
  #define FRXCP_SENDDTO_ID                        3u
  #define FRXCP_SENDFLUSH_ID                      4u
  #define FRXCP_CONTROL_ID                        5u
  #define FRXCP_GETVERSIONINFO                    6u
  #define FRXCP_TXCONFIRMATION_SERVICE_ID       101u
  #define FRXCP_RXINDICATION_SERVICE_ID         102u
  #define FRXCP_TRIGGERTRANSMIT_SERVICE_ID      103u
  #define FRXCP_MAINFUNCTIONRX_SERVICE_ID       200u
  #define FRXCP_MAINFUNCTIONTX_SERVICE_ID       201u

/* Definition of errors/exceptions */
  #define FRXCP_E_NO_INIT                         1u
  #define FRXCP_E_INV_PDU_ID                      2u
  #define FRXCP_E_INV_POINTER                     3u
  #define FRXCP_E_RX_BUFFER_OVERFLOW              4u
  #define FRXCP_E_WRONG_CONTROL_COMMAND           5u
#endif


/**************************************************************************************************
* Global data types and structures
**************************************************************************************************/

/* Initialization status of XCP. */
typedef enum
{
  XCP_UNINIT = 0,   /* The XCP is not initialized and is not usable. */
  XCP_INIT   = 1    /* The XCP is initialized and is usable. */
} FrXcp_InitStatusType;

/* PDU state of XCP */
typedef enum
{
  FRXCP_SET_OFFLINE = 0,
  FRXCP_SET_ONLINE
} FrXcp_PduSetModeType;


typedef uint8  FrXcpNAXType;
typedef uint8  XcpPacketType;

typedef struct
{
  XcpPacketType FrXcpPduAttributes;
  PduLengthType FrXcpPduLength;
} tXcpDaqTl;

typedef struct
{
  PduIdType     XcpPduId; /* PDU ID */
  XcpPacketType XcpPacketFilter; /* Allowed packed types */
  uint8         MaxFlxLenBuf;    /* Maximum length allowed */
  uint8         IsReconfigurable;
  uint8         IsInitialized;
} FrXcpPduDescriptorType;

typedef struct
{
  FrXcpPduDescriptorType *FrXcpPduDescriptorList;
  FrXcpNAXType           *FrXcpNAX;
  uint8                  *FrXcpPduDescriptorListSize;
} FrXcp_ConfigType;


#define NAX_FRAME_OFFSET 0		/* Offset of NAX in FlexRay PDU */

/* These are the possible types, a LPDU can have assigned (exclusive only) */
#define LPDU_TYPE_VARIABLE          0x00u
#define LPDU_TYPE_CMD               0x01u
#define LPDU_TYPE_STIM              0x02u
#define LPDU_TYPE_RES               0x04u
#define LPDU_TYPE_EV                0x08u
#define LPDU_TYPE_DAQ               0x10u
#define LPDU_TYPE_EVTBLOCKED        0x40u
#define LPDU_TYPE_BUSY              0x80u

/* The following XCP PIDs represent the equivalent XCP-Frame Types */
#define PID_TYPE_DAQ                0xFBu
#define PID_TYPE_STIM               0xBFu
#define PID_TYPE_CMD                0xC0u
#define PID_TYPE_RES                0xFFu
#define PID_TYPE_ERR                0xFEu
#define PID_TYPE_EV                 0xFDu
#define PID_TYPE_SERV               0xFCu

/* Some bordering values */
#define MAX_OFFSET                  63u
#define MAX_CYCLE_REPETITION        64u

/* Defines for optional commands */
#define CMD_FLX_ASSIGN              0xFFu
#define CMD_FLX_ACTIVATE            0xFEu
#define CMD_FLX_DEACTIVATE          0xFDu
#define CMD_GET_DAQ_FLX_LPDU_ID     0xFCu
#define CMD_SET_DAQ_FLX_LPDU_ID     0xFBu

#define TL_CMD_IDX                  0x01u
#define FLX_BUF_IDX                 0x02u
#define XCP_PACKET_TYPE_IDX         0x03u
#define FLX_SLOT_ID_IDX             0x04u
#define CYCLE_COUNTER_OFFSET_IDX    0x06u
#define CYCLE_COUNTER_REPET_IDX     0x07u
#define FLX_CHANNEL_IDX             0x08u
#define MAX_FLX_LEN_BUF_IDX         0x09u
#define HEADER_CRC_IDX              0x0Au

#define XCP_CHANNELA                0x00u
#define XCP_CHANNELB                0x01u
#define XCP_COM_TX                  0x00u
#define XCP_COM_RX                  0x01u
#define XCP_RESET                   0xFFu

#define XCP_ENABLE                  1u
#define XCP_DISABLE                 0u


/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_CODE
  #include "MemMap.h"
#endif

#define FrXcp_Background()
/* Initialize the XCP on FlexRay Transport Layer */
extern FUNC(void, FRXCP_CODE) FrXcp_InitMemory( void );
extern FUNC(void, FRXCP_CODE) FrXcp_Init( void );

/* This function handles custom, Transport Layer specific commands. */
extern FUNC(uint8, FRXCP_CODE) FrXcp_TLService
(
  P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR) pCmd
);


/* Transmit the given frame */
#define FrXcp_SendCTO FrXcp_Send
#define FrXcp_SendDTO FrXcp_Send
extern FUNC(uint8, FRXCP_CODE) FrXcp_Send
(
  VAR(uint8, AUTOMATIC) len,
  P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR) msg
);

/* Purge the current Frame Cache. */
extern FUNC(void, FRXCP_CODE) FrXcp_SendFlush
(
  VAR(uint8, AUTOMATIC) XcpFlushTypeSel
);


#if defined ( FRXCP_ENABLE_CONTROL )
/* En- or disable the Xcp Protocol Layer globally */
extern FUNC(void, FRXCP_CODE) FrXcp_Control
(
  VAR(uint8, AUTOMATIC) command
);
  #define kXcponFr_Control_Disable   0x00u
  #define kXcponFr_Control_Enable    0x01u
#endif

#if defined ( XCP_ENABLE_DAQ ) && defined ( XCP_ENABLE_DAQ_RESUME )
extern FUNC(void, FRXCP_CODE)  FrXcp_DaqResumeStore( void );
extern FUNC(void, FRXCP_CODE)  FrXcp_DaqResumeClear( void );
extern FUNC(void, FRXCP_CODE)  ApplXcpDaqTlResumeClear( void );
extern FUNC(void, FRXCP_CODE)  ApplXcpDaqTlResumeStore( P2CONST(tXcpDaqTl, AUTOMATIC, FRXCP_APPL_VAR) rtConfigPt );
extern FUNC(uint8, FRXCP_CODE) ApplXcpDaqTlResume( P2VAR(tXcpDaqTl, AUTOMATIC, FRXCP_APPL_VAR) rtConfigPt );
#endif

#if ( FRXCP_VERSION_INFO_API == STD_ON )
extern FUNC(void, FRXCP_CODE) FrXcp_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, FRXCP_APPL_VAR) FrXcpVerInfoPtr
);
#endif

/* Main Tasks */
extern FUNC(void, FRXCP_CODE) FrXcp_MainFunctionRx( void );
extern FUNC(void, FRXCP_CODE) FrXcp_MainFunctionTx( void );

#if ( FRXCP_USE_PDUMODE == STD_ON )
extern FUNC(void, FRXCP_CODE) FrXcp_SetPduMode(NetworkHandleType XcpNwH, FrXcp_PduSetModeType PduMode);
#endif

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CODE
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/**************************************************************************************************
* Prototypes of external variables
**************************************************************************************************/

/****************************************************************************/
/* 16 Bit Constants for export                                              */
/****************************************************************************/
#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_CONST_16BIT
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif

extern CONST(uint16, FRXCP_CONST) FRXCP_VENDOR_ID; /* Vector = 30 */

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

extern CONST(uint8, FRXCP_CONST) FRXCP_MODULE_ID;     /* XCP on FlexRay = 211 */
extern CONST(uint8, FRXCP_CONST) FRXCP_MAJOR_VERSION; /* Major version number */
extern CONST(uint8, FRXCP_CONST) FRXCP_MINOR_VERSION; /* Minor version number */
extern CONST(uint8, FRXCP_CONST) FRXCP_PATCH_VERSION; /* Patch level version number */

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CONST_8BIT
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/****************************************************************************/
/* Constants for export with unspecified size                               */
/****************************************************************************/
#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_CONST_UNSPECIFIED
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif

/* PRQA S 0781 5 *//* MISRA-C:2004 Rule 5.6, naming used in different contexts */
extern CONST(FrXcpNAXType, FRXCP_CONST) FrXcpNAX;
extern CONST(uint8, FRXCP_CONST) FrXcpPduDescriptorListSize;
extern CONST(uint8, FRXCP_CONST) FrXcpNumberOfTxPdus;
extern CONST(uint8, FRXCP_CONST) FrXcpNumberOfRxPdus;
extern CONST(FrXcpPduDescriptorType, FRXCP_CONST) FrXcpPduDescriptorList[FRXCP_NUM_TX_LPDUIDS  + FRXCP_NUM_RX_LPDUIDS];

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CONST_UNSPECIFIED
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/******************************************************************************/
/* Local Data definitions with unspecified size                               */
/******************************************************************************/
#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif

extern VAR(tXcpDaqTl, FRXCP_VAR_NOINIT) FrXcpRtConfig[FRXCP_NUM_TX_LPDUIDS + FRXCP_NUM_RX_LPDUIDS];

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


/***** end of header file ************************************************************************/
#endif
  /* __FRXCP_H__ */
