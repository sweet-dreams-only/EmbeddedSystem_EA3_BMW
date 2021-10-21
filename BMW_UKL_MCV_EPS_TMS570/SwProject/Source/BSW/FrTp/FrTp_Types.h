/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp config data types and structures
 **
 ** \file    FrTp_Types.h
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

 **/

/*
 * Misra-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 19.13 (advisory)
 * The # and ## preprocessor operators should not be used.
 *
 * Reason:
 * ## operator is used to keep the code simple.
 *
 * MISRA-2) Deviated Rule: 19.7 (required)
 * A function could probably be used instead of this function-like macro.
 *
 * Reason:
 * increase readability of source code. 
 */

#ifndef _FRTP_TYPES_H_
#define _FRTP_TYPES_H_

/* ----------------------------------------------------------------------------
 Include Section
 ---------------------------------------------------------------------------- */

#include "FrTp.h"           /* here the configuration is checked and all
                               neccesary includes are made */

/* ----------------------------------------------------------------------------
 Global Macros
 ---------------------------------------------------------------------------- */

/**
 * software version check
 */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif


#if (!defined UINT8_C)
/** \brief Macro to define a constant of type uint8 */
/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#define UINT8_C(x) ((uint8) x ## U)
#endif

#if (!defined UINT16_C)
/** \brief Macro to define a constant of type uint16 */
/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#define UINT16_C(x) ((uint16) x ## U)
#endif

#if (!defined UINT32_C)
/** \brief Macro to define a constant of type uint32 */
/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#define UINT32_C(x) x ## UL
#endif

#if (!defined SINT8_C)
/** \brief Macro to define a constant of type sint8 */
/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#define SINT8_C(x) ((sint8) (x))
#endif

#if (!defined SINT16_C)
/** \brief Macro to define a constant of type sint16 */
/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#define SINT16_C(x) ((sint16) (x))
#endif

#if (!defined SINT32_C)
/** \brief Macro to define a constant of type sint32 */
/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#define SINT32_C(x) x ## L
#endif


/*
 * Helper Macros for CST Lookup depending on CTR, and Ident
 *
 * Channel, Cycle Repetition, and Base Cycle are constant in FrTp
 */

/**
 * FrTp_CONFIG_ADDR is a macro used to define a configuration structure
 * element either as a pointer or as a relative offset, depending on the
 * FRTP_RELOCATABLE_CONFIG setting.
 */
#if FRTP_RELOCATABLE_CONFIG == STD_ON
/* Deviation MISRA-2 */
#define FRTP_CONFIG_ADDR(type) \
    (FrTp_ConfigOffsetType)
#else /* FRTP_RELOCATABLE_CONFIG */
/* Deviation MISRA-2 */
#define FRTP_CONFIG_ADDR(type) \
    (const type *)
#endif /* FRTP_RELOCATABLE_CONFIG */

/**
 * FRTP_CONFIG_ADDR_NULL is a macro used to set a configuration address
 * (absolute or relative) to 0.
 */
#if FRTP_RELOCATABLE_CONFIG == STD_ON
#define FRTP_CONFIG_ADDR_NULL \
    ((FrTp_ConfigOffsetType) 0)
#else /* FRTP_RELOCATABLE_CONFIG */
#define FRTP_CONFIG_ADDR_NULL \
    ((void *) 0)
#endif /* FRTP_RELOCATABLE_CONFIG */

/**
 * FRTP_SET_CONFIG_ADDR is a macro used for address calculation (absolute
 * or relative) of configuration structure elements.
 */
#if FRTP_RELOCATABLE_CONFIG == STD_ON
/* Deviation MISRA-2 */
#define FRTP_SET_CONFIG_ADDR(member) \
    ((FrTp_ConfigOffsetType) \
     &(((const FrTp_ConfigLayoutType *) 0)->member) \
    )
#else /* FRTP_RELOCATABLE_CONFIG */
/* Deviation MISRA-2 */
#define FRTP_SET_CONFIG_ADDR(member) \
    (const void *)(&FRTP_CONFIG_NAME.member)
#endif /* FRTP_RELOCATABLE_CONFIG */

/**
 * FRTP_GET_CONFIG_ADDR is a macro used to get the address of a configuration
 * structure element.
 */
#if FRTP_DEV_ERROR_DETECT == STD_ON
#if FRTP_RELOCATABLE_CONFIG == STD_ON
/* Deviation MISRA-2 */
#define FRTP_GET_CONFIG_ADDR(type, offset) \
        (((offset) == 0U) \
         ? ((const type *) 0) \
         : ((const type *) (const void *) \
            &(((const uint8 *) (const void *) FrTpRootConfigPtr) \
              [(offset)])) \
        )
#else
/* Deviation MISRA-2 */
#define FRTP_GET_CONFIG_ADDR(type, ptr) (ptr)
#endif
#else
#if FRTP_RELOCATABLE_CONFIG == STD_ON
/* Deviation MISRA-2 */
#define FRTP_GET_CONFIG_ADDR(type, offset) \
        ((const type *) (const void *) \
         &(((const uint8 *) (const void *) FrTpRootConfigPtr) \
           [ (offset) ] \
          ) \
        )
#else /* FRTP_RELOCATABLE_CONFIG */
/* Deviation MISRA-2 */
#define FRTP_GET_CONFIG_ADDR(type, ptr) (ptr)
#endif /* FRTP_RELOCATABLE_CONFIG */
#endif

#if (FRTP_RELOCATABLE_CONFIG_ALIGNMENT == STD_ON)
/*
 * Macros for alignment and padding.
 */

#define FRTP_CONFIG_PADDING_VALUE_U8 0xFF
#define FRTP_ALIGNMENT_8  CONST(uint8,AUTOMATIC) Pad1;
#define FRTP_ALIGNMENT_16 CONST(uint8,AUTOMATIC) Pad1; CONST(uint8,AUTOMATIC) Pad2;
#define FRTP_ALIGNMENT_24 CONST(uint8,AUTOMATIC) Pad1; CONST(uint8,AUTOMATIC) Pad2; CONST(uint8,AUTOMATIC) Pad3;
#define FRTP_PADDING_8    ,FRTP_CONFIG_PADDING_VALUE_U8
#define FRTP_PADDING_16   ,FRTP_CONFIG_PADDING_VALUE_U8, FRTP_CONFIG_PADDING_VALUE_U8
#define FRTP_PADDING_24   ,FRTP_CONFIG_PADDING_VALUE_U8, FRTP_CONFIG_PADDING_VALUE_U8, FRTP_CONFIG_PADDING_VALUE_U8

/**
 * Rx PDU alignment depending on pre compile time configuration.
 */
#if (FRTP_OPT_SINGLECHANNEL == STD_OFF)
#define FRTP_RXPDU_ALIGNMENT
#define FRTP_RXPDU_PADDING
#else
#define FRTP_RXPDU_ALIGNMENT FRTP_ALIGNMENT_8
#define FRTP_RXPDU_PADDING   FRTP_PADDING_8
#endif

/**
 * Tx PDU alignment depending on pre compile time configuration.
 */
#if (FRTP_DECOUPLED_FRIF_TX_ENABLE == STD_ON) && (FRTP_OPT_SINGLECHANNEL == STD_OFF)
#define FRTP_TXPDU_ALIGNMENT FRTP_ALIGNMENT_16
#define FRTP_TXPDU_PADDING   FRTP_PADDING_16
#else
#if (FRTP_DECOUPLED_FRIF_TX_ENABLE == STD_OFF) && (FRTP_OPT_SINGLECHANNEL == STD_ON)
#define FRTP_TXPDU_ALIGNMENT
#define FRTP_TXPDU_PADDING
#else
#define FRTP_TXPDU_ALIGNMENT FRTP_ALIGNMENT_24
#define FRTP_TXPDU_PADDING   FRTP_PADDING_24
#endif
#endif

/**
 * Connection alignment depending on pre compile time configuration.
 */
#if    ((FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_ON) && (FRTP_OPT_SINGLECHANNEL == STD_OFF) && (FRTP_TB_ADDR_MODE_ENABLE == STD_OFF)) \
    || ((FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF) && (FRTP_OPT_SINGLECHANNEL == STD_ON) && (FRTP_TB_ADDR_MODE_ENABLE == STD_OFF))
#define FRTP_CON_ALIGNMENT FRTP_ALIGNMENT_8
#define FRTP_CON_PADDING   FRTP_PADDING_8
#else
#if    ((FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_ON) && (FRTP_OPT_SINGLECHANNEL == STD_ON) && (FRTP_TB_ADDR_MODE_ENABLE == STD_OFF)) \
    || ((FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF) && (FRTP_OPT_SINGLECHANNEL == STD_OFF) && (FRTP_TB_ADDR_MODE_ENABLE == STD_ON))
#define FRTP_CON_ALIGNMENT FRTP_ALIGNMENT_16
#define FRTP_CON_PADDING   FRTP_PADDING_16
#else
#if    ((FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF) && (FRTP_OPT_SINGLECHANNEL == STD_ON) && (FRTP_TB_ADDR_MODE_ENABLE == STD_ON)) \
    || ((FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_ON) && (FRTP_OPT_SINGLECHANNEL == STD_OFF) && (FRTP_TB_ADDR_MODE_ENABLE == STD_ON))
#define FRTP_CON_ALIGNMENT FRTP_ALIGNMENT_24
#define FRTP_CON_PADDING   FRTP_PADDING_24
#else
#define FRTP_CON_ALIGNMENT
#define FRTP_CON_PADDING
#endif
#endif
#endif

/**
 * Channel alignment depending on pre compile time configuration.
 */


/* no alignment needed for FrTp */
#define FRTP_CHN_ALIGNMENT
#define FRTP_CHN_PADDING

#else /* FRTP_RELOCATABLE_CONFIG_ALIGNMENT */

#define FRTP_RXPDU_ALIGNMENT
#define FRTP_RXPDU_PADDING
#define FRTP_TXPDU_ALIGNMENT
#define FRTP_TXPDU_PADDING
#define FRTP_CON_ALIGNMENT
#define FRTP_CON_PADDING
#define FRTP_CHN_ALIGNMENT
#define FRTP_CHN_PADDING
#define FRTP_ALIGNMENT_8
#define FRTP_ALIGNMENT_16
#define FRTP_ALIGNMENT_24
#define FRTP_PADDING_8
#define FRTP_PADDING_16
#define FRTP_PADDING_24

#endif /* FRTP_RELOCATABLE_CONFIG_ALIGNMENT */

/**
 * All possible message lengths
 */
#define FRTP_ISO  (uint8) 0U   /**< up to 2^12 - 1 byte message length */
#define FRTP_ISO6 (uint8) 1U   /**< up to 2^12 - 1 byte message length - but max 6 bytes payload length */

/**
 * All possible
 */
#define FRTP_NODE 0U          /* Identifies the handle as a "Node" handle */
#define FRTP_MASTERGATEWAY 1U /* Identifies the handle as a "Master Gateway" handle */
#define FRTP_GATEWAY 2U       /* Identifies the handle as a "Gateway" handle */
#define FRTP_TESTER  3U       /* Tester, not yet supported */

/* ----------------------------------------------------------------------------
 **                      Global Data Types
 ---------------------------------------------------------------------------- */

#if (FRTP_RELOCATABLE_CONFIG == STD_ON)
/**
 * used for relative address offsets in relocatable configurations
 */
typedef uint16 FrTp_ConfigOffsetType;
#endif

/**
 * Type used to store the address information
 */
typedef uint8 FrTp_AddressType;

/**
 * configuration channel config type (ROM)
 */
typedef struct {
/*
 * Timeout Counters
 */
CONST(uint16,AUTOMATIC) TimeoutCommon; /* Common Timeout (usually 1 sec) */
CONST(uint16,AUTOMATIC) TimeoutCFCF; /* CF/CF Timeout  (always 0.9sec) */
CONST(uint16,AUTOMATIC) TimeoutBufReq; /* Timeout between two buf requests */
CONST(uint8,AUTOMATIC) timeFrIf; /**< Maximum numbers of tries to send via FrIf */
/**
 * Protocol parameters
 */
CONST(uint8,AUTOMATIC) BSInit; /* Intial Block Size */
CONST(uint8,AUTOMATIC) BCDefault; /* Default Bandwidth Control */
CONST(uint8,AUTOMATIC) MaxBufReq; /* Maximum Buffer Requests */
CONST(uint8,AUTOMATIC) maxFrIf; /**< Maximum numbers of tries to send via FrIf */
FRTP_CHN_ALIGNMENT
}FrTp_ChnConfigType;

/**
 * Post build time configuration of a connection.
 */
typedef struct {
CONST(PduIdType,AUTOMATIC) RxSDUId; /**< SDU Id of this connection */
CONST(FrTp_AddressType,AUTOMATIC) LAddr; /**< Local TP address */
CONST(FrTp_AddressType,AUTOMATIC) RAddr; /**< Remote TP address */
CONST(uint8,AUTOMATIC) TxPDUTblIdx; /**< Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
CONST(uint8,AUTOMATIC) RxPDUTblIdx; /**< Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
#if (FRTP_OPT_ONE_PDU_PER_CONNECTION == STD_OFF)
CONST(uint8,AUTOMATIC) TxPDUcount; /**< Number of Tx PDUs which belong to this connection */
#endif
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
CONST(uint8,AUTOMATIC) ChnIdx; /**< Number of the channel to which this connection belongs to */
#endif
CONST(uint8,AUTOMATIC) mult_rec; /**< Defines whether this is a 1:1 or 1:n connection. */
FRTP_CON_ALIGNMENT
}FrTp_ConConfigType;

/**
 * Post build time configuration of a Rx PDU.
 */
typedef struct {
CONST(PduLengthType,AUTOMATIC) Length; /**< Length of this PDU */
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
CONST(uint8,AUTOMATIC) ChnIdx; /**<  Index of the corresponding channel */
#endif
CONST(uint8,AUTOMATIC) ConIdx; /**< Index of the corresponding connection */
FRTP_RXPDU_ALIGNMENT
}FrTp_PDURxConfigType;

/**
 * Post build time configuration of a Tx PDU
 */
typedef struct {
CONST(PduLengthType,AUTOMATIC) Length; /**< Length of this PDU */
CONST(PduIdType,AUTOMATIC) PDUId; /**< PDU Id for this N-PDU */
#if (FRTP_DECOUPLED_FRIF_TX_ENABLE == STD_ON)
CONST(uint8,AUTOMATIC) DecoupledTx; /**< Decoupled transmission mode is used for this PDU */
#endif
#if (FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON)
CONST(uint8,AUTOMATIC) ChnIdx; /**<  Index of the corresponding channel */
#endif
CONST(uint8,AUTOMATIC) ConIdx; /**< Index of the corresponding connection */
FRTP_TXPDU_ALIGNMENT
}FrTp_PDUTxConfigType;

#if (FRTP_RELOCATABLE_CONFIG == STD_ON)
/**
 * Post build time root structure
 */
typedef struct {
CONST(uint32,AUTOMATIC) nConfigSignature; /**< Check number */
CONST(FrTp_ConfigOffsetType,AUTOMATIC) ChnConfigOffset; /**< Pointer to the channel configuration */
CONST(FrTp_ConfigOffsetType,AUTOMATIC) ConConfigOffset; /**< Pointer to the Rx connection configuration */
CONST(FrTp_ConfigOffsetType,AUTOMATIC) PDUTxConfigOffset; /**< Pointer to the Tx N-PDU configuration */
CONST(FrTp_ConfigOffsetType,AUTOMATIC) PDURxConfigOffset; /**< Pointer to the Rx N-PDU configuration */
CONST(uint8,AUTOMATIC) NumChn; /**< Number of channels*/
CONST(uint8,AUTOMATIC) NumCon; /**< Number of connections */
CONST(uint8,AUTOMATIC) NumTxPDU; /**< Number of transmission N-PDUs  */
CONST(uint8,AUTOMATIC) NumRxPDU; /**< Number of receiving N-PDUs  */
}FrTpRootConfigType;
#endif

/* ----------------------------------------------------------------------------
 Global Data
 ---------------------------------------------------------------------------- */

#endif /* _FRTP_TYPES_H_ */
