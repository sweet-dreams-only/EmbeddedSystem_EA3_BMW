/** BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** Copyright 2002-2010 Elektrobit Austria GmbH, http://www.elektrobit.com/
 ** All rights reserved.
 ** This software is the confidential and proprietary information
 ** of Elektrobit ("Confidential Information").
 *
 ** You shall not disclose such Confidential Information
 ** and shall use it only in accordance with the terms and
 ** conditions of the License Agreement you entered into with
 ** Elektrobit.
 **
 */


/*
 * MCG-Version:       2.0.10
 */
/******************************************************************************
**                      Include Section                                      **
******************************************************************************/
#include "FrTp_PBCfg.h"    /* post-build time parameter */
#include "FrTp_Priv.h" /* ConfigPtr needs extern declaration */

/******************************************************************************
**                      Version Check                                        **
******************************************************************************/
#if (!defined FRTP_BSW_MCG_IFVERSION_CHECK) || \
(!FRTP_BSW_MCG_IFVERSION_CHECK(1,3,2))
 #error Interface version number mismatch.
#endif

/******************************************************************************
**                      Defines                                              **
******************************************************************************/

/* RxSdus */
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF0_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF0_EPS 14U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF1_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF1_EPS 15U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF2_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF2_EPS 16U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF3_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF3_EPS 17U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF4_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF4_EPS 18U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF5_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF5_EPS 19U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF6_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF6_EPS 20U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF7_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF7_EPS 21U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF8_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF8_EPS 22U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxF9_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxF9_EPS 23U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxFA_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxFA_EPS 24U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxFB_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxFB_EPS 25U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxFC_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxFC_EPS 26U
#endif
#if !defined PduR_TL_MST_GW_TRNSM_FR_254_TxFD_EPS
    #define PduR_TL_MST_GW_TRNSM_FR_254_TxFD_EPS 27U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF0_EPS
    #define PduR_TL_BRC_FR_32_TxF0_EPS 0U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF1_EPS
    #define PduR_TL_BRC_FR_32_TxF1_EPS 1U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF2_EPS
    #define PduR_TL_BRC_FR_32_TxF2_EPS 2U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF3_EPS
    #define PduR_TL_BRC_FR_32_TxF3_EPS 3U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF4_EPS
    #define PduR_TL_BRC_FR_32_TxF4_EPS 4U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF5_EPS
    #define PduR_TL_BRC_FR_32_TxF5_EPS 5U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF6_EPS
    #define PduR_TL_BRC_FR_32_TxF6_EPS 6U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF7_EPS
    #define PduR_TL_BRC_FR_32_TxF7_EPS 7U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF8_EPS
    #define PduR_TL_BRC_FR_32_TxF8_EPS 8U
#endif
#if !defined PduR_TL_BRC_FR_32_TxF9_EPS
    #define PduR_TL_BRC_FR_32_TxF9_EPS 9U
#endif
#if !defined PduR_TL_BRC_FR_32_TxFA_EPS
    #define PduR_TL_BRC_FR_32_TxFA_EPS 10U
#endif
#if !defined PduR_TL_BRC_FR_32_TxFB_EPS
    #define PduR_TL_BRC_FR_32_TxFB_EPS 11U
#endif
#if !defined PduR_TL_BRC_FR_32_TxFC_EPS
    #define PduR_TL_BRC_FR_32_TxFC_EPS 12U
#endif
#if !defined PduR_TL_BRC_FR_32_TxFD_EPS
    #define PduR_TL_BRC_FR_32_TxFD_EPS 13U
#endif
/* TxPdus */
#if !defined FrIf_TL_ECU_TRNSM_FR_32_EPS_Tp
    #define FrIf_TL_ECU_TRNSM_FR_32_EPS_Tp 1U
#endif

/******************************************************************************
**                      Global Data                                          **
******************************************************************************/

/*
 * MISRA RULE 87 VIOLATION:
 * memory abstraction defined by AUTOSAR requires inclusion of MemMap.h within
 * code fragments.
 */
#define FRTP_START_CONFIG_DATA_UNSPECIFIED 
#include "MemMap.h"

const FrTpMultipleConfigLayoutType FRTP_CONFIG_NAME =
{
    /* ConfigLayout */
#if FRTP_RELOCATABLE_CONFIG == STD_ON
    {
        /* RootConfig */
        UINT32_C(0x82030206), /* VersionCheck */
        FRTP_SET_CONFIG_ADDR(Channels), /* Addr(Channels) */
        FRTP_SET_CONFIG_ADDR(Connections), /* Addr(Connections) */
        FRTP_SET_CONFIG_ADDR(TxPdus), /* Addr(TxPdus) */
        FRTP_SET_CONFIG_ADDR(RxPdus), /* Addr(RxPdus) */
        UINT8_C(1), /* Number of Channels */
        UINT8_C(28), /* Number of Connections */
        UINT8_C(1), /* Number of TxPdus */
        UINT8_C(2) /* Number of RxPdus */
    },
#endif
    {
        /* Channels */
        {
            /* Channel0 */
            UINT16_C(200), /* Timeout Common */
            UINT16_C(180), /* CFCF Timeout */
            UINT16_C(3), /* Time for buffer requests */
            UINT16_C(3), /* Time for FrIf requests */
            UINT8_C(0x10), /* Initial Block Size */
            UINT8_C(0x0), /* Default Bandwidth */
            UINT8_C(3), /* Maximum Buffer Request */
            UINT8_C(3) /* Maximum FrIf Request */
        }
    },
    {
        /* Connections */
        {
            /* Connection0 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF0_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(240), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection1 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF1_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(241), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection2 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF2_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(242), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection3 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF3_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(243), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection4 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF4_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(244), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection5 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF5_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(245), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection6 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF6_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(246), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection7 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF7_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(247), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection8 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF8_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(248), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection9 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxF9_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(249), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection10 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxFA_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(250), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection11 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxFB_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(251), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection12 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxFC_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(252), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection13 */
            PduR_TL_MST_GW_TRNSM_FR_254_TxFD_EPS, /* RxSDU Id of this connection */
            UINT16_C(48), /* Local TP address */
            UINT16_C(253), /* Remote TP address */
            UINT8_C(0), /* Index of the first N-PDU in the TxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(1), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(0) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection14 */
            PduR_TL_BRC_FR_32_TxF0_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(240), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection15 */
            PduR_TL_BRC_FR_32_TxF1_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(241), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection16 */
            PduR_TL_BRC_FR_32_TxF2_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(242), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection17 */
            PduR_TL_BRC_FR_32_TxF3_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(243), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection18 */
            PduR_TL_BRC_FR_32_TxF4_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(244), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection19 */
            PduR_TL_BRC_FR_32_TxF5_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(245), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection20 */
            PduR_TL_BRC_FR_32_TxF6_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(246), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection21 */
            PduR_TL_BRC_FR_32_TxF7_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(247), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection22 */
            PduR_TL_BRC_FR_32_TxF8_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(248), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection23 */
            PduR_TL_BRC_FR_32_TxF9_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(249), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection24 */
            PduR_TL_BRC_FR_32_TxFA_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(250), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection25 */
            PduR_TL_BRC_FR_32_TxFB_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(251), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection26 */
            PduR_TL_BRC_FR_32_TxFC_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(252), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        },
        {
            /* Connection27 */
            PduR_TL_BRC_FR_32_TxFD_EPS, /* RxSDU Id of this connection */
            UINT16_C(223), /* Local TP address */
            UINT16_C(253), /* Remote TP address */
            UINT8_C(255), /* No Tx PDUs present. */
            UINT8_C(1), /* Index of the first N-PDU in the RxPDU Table which belongs to this connection. */
            UINT8_C(0), /* Number of Tx PDUs which belong to this connection */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Number of the channel to which this connection belongs to */
#endif
            UINT8_C(1) /* Defines whether this is a 1:1 or 1:n connection */
            FRTP_CON_PADDING
        }
    },
    {
        /* TxPdus */
        {
            /* TxPdu1 */
            UINT16_C(32), /* Length of this PDU */
            FrIf_TL_ECU_TRNSM_FR_32_EPS_Tp, /* PDU Id for this N-PDU */
#if FRTP_DECOUPLED_FRIF_TX_ENABLE == STD_ON
            UINT8_C(0), /* Decoupled transmission mode is used for this PDU */
#endif
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Index of the corresponding channel */
#endif
            UINT8_C(254) /* Index of the corresponding connection */
            FRTP_TXPDU_PADDING
        }
    },
    {
        /* RxPdus */
        {
            /* RxPdu0 */
            UINT16_C(254), /* Length of this PDU */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Index of the corresponding channel */
#endif
            UINT8_C(0) /* Index of the corresponding connection */
            FRTP_RXPDU_PADDING
        },
        {
            /* RxPdu1 */
            UINT16_C(32), /* Length of this PDU */
#if FRTP_MULTIPLE_CHANNEL_ENABLE == STD_ON
            UINT8_C(0), /* Index of the corresponding channel */
#endif
            UINT8_C(0) /* Index of the corresponding connection */
            FRTP_RXPDU_PADDING
        }
    }
};
#if FRTP_RELOCATABLE_CONFIG == STD_OFF
CONSTP2CONST(FrTp_ChnConfigType,FRTP_CONST,FRTP_CONST) gFrTp_ChnConfigPtr =
    &(FRTP_CONFIG_NAME.Channels[0]);
CONSTP2CONST(FrTp_ConConfigType,FRTP_CONST,FRTP_CONST) gFrTp_ConConfigPtr =
    &(FRTP_CONFIG_NAME.Connections[0]);
CONSTP2CONST(FrTp_PDUTxConfigType,FRTP_CONST,FRTP_CONST) gFrTp_PDUTxConfigPtr =
    &(FRTP_CONFIG_NAME.TxPdus[0]);
CONSTP2CONST(FrTp_PDURxConfigType,FRTP_CONST,FRTP_CONST) gFrTp_PDURxConfigPtr =
    &(FRTP_CONFIG_NAME.RxPdus[0]);
CONST(uint8,FRTP_CONST) gFrTpChnNumber= 
    (uint8)(sizeof(FRTP_CONFIG_NAME.Channels)/sizeof(FrTp_ChnConfigType));
CONST(uint8,FRTP_CONST) gFrTpConNumber= 
    (uint8)(sizeof(FRTP_CONFIG_NAME.Connections)/sizeof(FrTp_ConConfigType));
CONST(uint8,FRTP_CONST) gFrTpTxPDUNumber= 
    (uint8)(sizeof(FRTP_CONFIG_NAME.TxPdus)/sizeof(FrTp_PDUTxConfigType));
CONST(uint8,FRTP_CONST) gFrTpRxPDUNumber=         
    (uint8)(sizeof(FRTP_CONFIG_NAME.RxPdus)/sizeof(FrTp_PDURxConfigType));
#endif
/*
 * MISRA RULE 87 VIOLATION:
 * memory abstraction defined by AUTOSAR requires inclusion of MemMap.h within
 * code fragments.
 */
#define FRTP_STOP_CONFIG_DATA_UNSPECIFIED 
#include "MemMap.h"

/*
 * = eof ======================================================================
 */
