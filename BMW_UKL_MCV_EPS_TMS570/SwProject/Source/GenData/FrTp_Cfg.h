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
#ifndef _FRTP_CFG_H_
#define _FRTP_CFG_H_

/*
 * Include Section
 */

#include "Std_Types.h"      /* definitions of STD_ON and STD_OFF */

/*
 * Defines
 */

/* RxPdus */
#define FrTp_TL_MST_GW_TRNSM_FR_254_Tp 0U
#define FrTp_TL_BRC_FR_32_Tp 1U

/* TxSdus */
#define FrTp_FrTpConnection_14 0U
#define FrTp_FrTpConnection_15 1U
#define FrTp_FrTpConnection_16 2U
#define FrTp_FrTpConnection_17 3U
#define FrTp_FrTpConnection_18 4U
#define FrTp_FrTpConnection_19 5U
#define FrTp_FrTpConnection_20 6U
#define FrTp_FrTpConnection_21 7U
#define FrTp_FrTpConnection_22 8U
#define FrTp_FrTpConnection_23 9U
#define FrTp_FrTpConnection_24 10U
#define FrTp_FrTpConnection_25 11U
#define FrTp_FrTpConnection_26 12U
#define FrTp_FrTpConnection_27 13U
#define FrTp_FrTpConnection_0 14U
#define FrTp_FrTpConnection_1 15U
#define FrTp_FrTpConnection_2 16U
#define FrTp_FrTpConnection_3 17U
#define FrTp_FrTpConnection_4 18U
#define FrTp_FrTpConnection_5 19U
#define FrTp_FrTpConnection_6 20U
#define FrTp_FrTpConnection_7 21U
#define FrTp_FrTpConnection_8 22U
#define FrTp_FrTpConnection_9 23U
#define FrTp_FrTpConnection_10 24U
#define FrTp_FrTpConnection_11 25U
#define FrTp_FrTpConnection_12 26U
#define FrTp_FrTpConnection_13 27U

/* Channels */
#define FrTp_FrTpChannel 0U

/*
 * Global Macros
 */

/** BSW to MCG interface variant */
#define FRTP_MCG_BSW_IFVERSION_VARIANT (1)
#define FRTP_MCG_BSW_IFVERSION_PROVIDED (3)
#define FRTP_MCG_BSW_IFVERSION_REQUIRED (2)

/**
* Pre-processor switch for enabling version info API support. [BSW00411]
*/
#define FRTP_VERSION_INFO_API STD_ON

/**
* Preprocessor switch for defining the number of concurrent channels the module
* supports. Up to 32 channels shall be definable here.
*/
#define FRTP_CHAN_NUM 1

/**
* Pre-processor switch for enabling development error detection. [FRTP217]
*/
#define FRTP_DEV_ERROR_DETECT STD_ON

/******************************************************************************
**                      Vendor specific pre-compile time switches            **
******************************************************************************/

/**
* Pre-processor switch to specify the maximum number of connections.
*/
#define FRTP_CON_NUM 28

/**
* Pre-processor switch to specify the maximum number of TX FrIf-PDUs.
*/
#define FRTP_TX_PDU_NUM 1

/**
* Pre-processor switch to specify the maximum number of RX FrIf-PDUs.
*/
#define FRTP_RX_PDU_NUM 32

/**
* Pre-processor switch to specify the maximum size of the PDU_Buffer.
*/
#define FRTP_PDU_BUFFER_SIZE 1500U


/*
* Preprocessor switch for enabling binary relocatable configuration
*/
#define FRTP_RELOCATABLE_CONFIG STD_OFF

/*
* Preprocessor switch for enabling a forced 1-2-4 alignment when using binary
* configuration.
*/
#define FRTP_RELOCATABLE_CONFIG_ALIGNMENT STD_OFF
 
/*
* Preprocessor switch to support the decoupled FrIf Transmit mode.
*/
#define FRTP_DECOUPLED_FRIF_TX_ENABLE STD_ON

/*
* Preprocessor switch to simplify the RX and TX procedures because only one 
* PDU per connection may be used for transmission and reception.
*/
#define FRTP_OPT_ONE_PDU_PER_CONNECTION STD_OFF

/*
* Preprocessor switch to simplify the PDU to connection mapping. this switch 
* may be enabled if a PDU belongs to exactly one connection.
*/
#define FRTP_OPT_DISTINCT_CONNECTION_EACH_PDU STD_OFF

/*
* Preprocessor switch to generated local pointer definition. RISC processors 
* like MPC55xx produce better code if local pointers are defined if only one 
* channel is available. On the other hand for e.g. S12X processors this will 
* produce unnecessary code.
* May be used combined with FRTP_HAVE_SINGLECHANNEL.
*/ 
#define FRTP_OPT_LOCAL_POINTERS STD_ON

/*
* Use memcpy function from the standard C library.
*/
#define FRTP_USE_STD_MEMCPY STD_OFF

/*
 * Pre-processor switch to enable multiple channel support.
 */
#define FRTP_MULTIPLE_CHANNEL_ENABLE STD_ON

/*
 * Number of available Frame Info Buffers.
 */
#define FRTP_PDUINFO_BUFFER_NUM 5

/**
 * Maximum allowed PDU frame length.
 */
#define FRTP_PDU_MAXLEN 254U

/**
 * Pre-processor switch to specify the Tp-ROLE (NODE/GATEWAY/MASTERGW).
 */
#define FRTP_ROLE FRTP_GATEWAY

/**
 * Pre-processor switch for enabling the transmission FC-WAITs in case the
 * gateway can not provide a receive buffer. for nodes this option must be
 * switched off.
 */
#define FRTP_SUPPORT_TXWAIT STD_OFF

/*
 * Length of the Buffer to hold data for retry mechanism for each channel
 */
#define FRTP_RETRY_BUFFER_SIZE 1024

/**
 * Defines the behavior to get data for transmission fro the upper layer.
 * E.g. some implementations of the DCM are not able to provide a specific
 * number of bytes, so 0 as length shall be used. In this case the upper 
 * layer provides as much data as possible
 */
#define FRTP_TX_BUFFER_REQUEST_ZERO STD_ON


#endif /* _FRTP_CFG_H_ */


/*
 * = eof ======================================================================
 */
