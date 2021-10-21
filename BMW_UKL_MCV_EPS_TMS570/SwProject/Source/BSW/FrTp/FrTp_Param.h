/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** FrTp internal macros with parameter definitions.
 **
 ** \file    FrTp_Param.h
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

#ifndef FRTP_PARAMS_H
#define FRTP_PARAMS_H

/**
 * software version check
 * fulfills [FRTP201]
 * */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif

/*
 * Maximum FrTp message length which can be used with 1 byte length field
 */
#define FRTP_MAXLEN_FF1B    255U

/*
 * Maximum FrTp message length
 */
#define FRTP_MAXLEN_FF2B    4095U

/*
 * Maximum group addressed FrTp message
 */
#define FRTP_MAXLEN_GRPADDR    6U

/*
 * Address field size: 1 Byte
 */
#define FRTP_ADDR_SIZE   1U     /* Length of Tgt, Src address fields */
#define FRTP_ADDRPR_SIZE 2U     /* Length of both fields together */

/*
 * Header sizes of FrTp data frames (MAS-Type ID + Address Pair sizes + PCI)
 */
#define FRTP_HSIZE_SF   (1U + FRTP_ADDRPR_SIZE + 2U)
#define FRTP_HSIZE_FF1B (1U + FRTP_ADDRPR_SIZE + 2U)
#define FRTP_HSIZE_FF2B (1U + FRTP_ADDRPR_SIZE + 3U)
#define FRTP_HSIZE_FF3B (1U + FRTP_ADDRPR_SIZE + 4U)
#define FRTP_HSIZE_CF   (1U + FRTP_ADDRPR_SIZE + 1U)

/*
 * Minimum Payload Lengths of any FrTp Frame
 * (MAS-Type ID + Address Pair sizes + 1 Byte PCI)
 */
#define FRTP_MIN_DATA_SIZE (1U + FRTP_ADDRPR_SIZE + 1U + 0U)

/*
 * Minimum FrTp Data Frame sizes ----------------------------------------------
 */

#define FRTP_SF_MIN_DATA_SIZE (FRTP_HSIZE_SF + 1U)      /* Min SF size */
#define FRTP_FF1B_MIN_DATA_SIZE (FRTP_HSIZE_FF1B + 1U)  /* Min FF1B size */
#define FRTP_FF2B_MIN_DATA_SIZE (FRTP_HSIZE_FF2B + 1U)  /* Min FF2B size */
#define FRTP_FF3B_MIN_DATA_SIZE (FRTP_HSIZE_FF3B + 1U)  /* Min FF3B size */
#define FRTP_CF_MIN_DATA_SIZE      (FRTP_HSIZE_CF + 1U) /* Min CF size */

/*
 * FrTp Flow Control Frame sizes -----------------------------------------------
 */

#define FRTP_FC_CTS_DATA_SIZE  (FRTP_MIN_DATA_SIZE + 2U) /* CTS size */
#define FRTP_FC_WT_DATA_SIZE   FRTP_MIN_DATA_SIZE   /* WT size */
#define FRTP_FC_CREF_DATA_SIZE FRTP_MIN_DATA_SIZE   /* CREF size */
#define FRTP_FC_NACK_DATA_SIZE (FRTP_MIN_DATA_SIZE + 1U) /* NACK size */
#define FRTP_FC_ACK_DATA_SIZE  FRTP_MIN_DATA_SIZE   /* ACK size */

/*
 * Indices of FrTp Header fields ----------------------------------------------
 */

#define FRTP_MAS_TI_INDEX  0U                                /* MAS_TI */
#define FRTP_TGT_INDEX     1U                                /* TGT */
#define FRTP_SRC_INDEX     (FRTP_TGT_INDEX + FRTP_ADDR_SIZE) /* SRC */
#define FRTP_FT_INDEX      (FRTP_SRC_INDEX + FRTP_ADDR_SIZE) /* Frame Type   */
#define FRTP_DL_INDEX      (FRTP_FT_INDEX + 1U)              /* Data Length  */
#define FRTP_DLH_INDEX     (FRTP_DL_INDEX)                   /* DL (Hi Byte) */
#define FRTP_DLL_INDEX     (FRTP_DLH_INDEX + 1U)             /* DL (Lo Byte) */

#define FRTP_DL3BH_INDEX     (FRTP_DL_INDEX)                 /* DL (Hi Byte FF3B) */
#define FRTP_DL3BM_INDEX     (FRTP_DL3BH_INDEX + 1U)         /* DL (Mi Byte FF3B)*/
#define FRTP_DL3BL_INDEX     (FRTP_DL3BM_INDEX + 1U)         /* DL (Lo Byte FF3B) */

#define FRTP_BS_INDEX      (FRTP_FT_INDEX + 1U)              /* BS Max field */
#define FRTP_NACKSN_INDEX  (FRTP_FT_INDEX + 1U)              /* NACK SN field*/
#define FRTP_BC_INDEX      (FRTP_BS_INDEX + 1U)              /* BC field */
#define FRTP_SN_INDEX      (FRTP_FT_INDEX)                   /* CF SN field */

/*
 * Field Masks ----------------------------------------------------------------
 */

#define FRTP_FT_MASK        0xf0U /* Mask for Frame Type in PCI field */
#define FRTP_FST_MASK       0x0fU /* Mask for Frame Sub Type in PCI field */
#define FRTP_CFSN_MASK      0x0fU /* Mask for SN Field in CF frame */
#define FRTP_NACKSN_MASK    0x0fU /* Mask for SN Field in NACK frame */

#define FRTP_FF2B_DLH_MASK  0xff00U /* Mask for High Byte of Two Byte Length */
#define FRTP_FF2B_DLL_MASK  0x00ffU /* Mask for Low Byte of Two Byte Length */

#define FRTP_MAS_TI_MS_MASK 0x80U /* Message / Session Control Bit */
#define FRTP_MAS_TI_AT_MASK 0x10U /* Adressing Type Field */
#define FRTP_MAS_TI_AS_MASK 0x08U /* Adressing Type Sender Field */
#define FRTP_MAS_TI_AR_MASK 0x07U /* Adressing Type Receiver Field */

#define FRTP_AT_SC            0x01U /* Addressing of Receiver: Single Comp */
#define FRTP_AT_GC            0x02U /* Addressing of Receiver: Grp of Comp */
#define FRTP_AT_SF            0x03U /* Addressing of Receiver: Single Fct */
#define FRTP_AT_GF            0x04U /* Addressing of Receiver: Grp of Fcts */
#define FRTP_AT_CD            0x05U /* Addressing of Receiver: Content Driven */

#define FRTP_BC_SC_FILTER     0x80U /* Bandwidth Ctrl: Separation Cyc Bit */
#define FRTP_BC_VAL_FILTER    0x7fU /* Bandwidth Ctrl: Value Bit */
#define FRTP_BC_SCMAX         0x09U /* Max sep cycles between subsequent CFs */
#define FRTP_BS_MAX           0x0f  /* Maximum allowed BS value */

#define FRTP_MT_SC            0x01U /* Single Component Addr Type MAS_TI */
#define FRTP_MT_GC            0x02U /* Group Component Addr Type MAS_TI */

/*
 * Field Value constants ------------------------------------------------------
 */

#define FRTP_FT_SF            0x00U  /* SF */
#define FRTP_FT_FF            0x40U  /* FF */
#define FRTP_FST_FF1B         0x00U  /* FF Subtype 1 Byte Length encoding */
#define FRTP_FST_FF2B         0x01U  /* FF Subtype 2 Bytes Length encoding */
#define FRTP_FST_FF3B         0x02U  /* FF Subtype 3 Bytes Length encoding */
#define FRTP_FT_FC            0x30U  /* FC Frame */
#define FRTP_FT_CF            0x20U  /* CF */

#define FRTP_FT_FCCTS         0x0U  /* Flow Control: Clear To Send */
#define FRTP_FT_FCWT          0x1U  /* Flow Control: Wait*/
#define FRTP_FT_FCCREF        0x2U  /* Flow Control: Connection Refused */
#define FRTP_FT_FCNACK        0x3U  /* Flow Control: Negative Acknowledge */
#define FRTP_FT_FCACK         0x4U  /* Flow Control: Acknowledge */

#define FRTP_MAX_NACK_RETRIES 2U     /* Maximum retries after NACK */
#define FRTP_MAX_WTS 16U             /* Maximum number of subsequent FC-WTs */

#define FRTP_FIRST_CF_IDX 1U         /* SN of first CF after FF */

#endif /*FRTP_PARAM_H_*/
