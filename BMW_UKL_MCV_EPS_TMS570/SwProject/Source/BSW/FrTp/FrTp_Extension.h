/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** FrTp API prototypes
 **
 ** \file    FrTp_Extension.h
 ** \project BMW FrTp
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** \author  Guenter Ebermann
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
 * MISRA-1) Deviated Rule: 19.7 (required)
 * A function could probably be used instead of this function-like macro.
 *
 * Reason:
 * increase readability of source code. 
 */

#ifndef _FRTP_EXTENSION_H_
#define _FRTP_EXTENSION_H_

/* ----------------------------------------------------------------------------
 Global Macros
 ---------------------------------------------------------------------------- */

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
/**
 * The module id, used for reporting errors via DET is defined for each
 * instance of the FrTp. Nevertheless an overall instance id must be defined
 * for reporting errors concerning the whole FrTp or for errors, where
 * no instance id can be applied.
 * FRTP_DET_GENERIC_INSTANCE_ID defines a virtual instance id of the FrTp
 * for calling DET api functions.
 */
#ifndef FRTP_DET_GENERIC_INSTANCE_ID
#define FRTP_DET_GENERIC_INSTANCE_ID 0xFFU
#endif

#endif

/*
 * EB extensions of Det error values for extended error checking
 */
/**
 * A received frame was ignored. This can happen in the following cases:
 * - wrong address information
 * - wrong channel capabilities (e.g. SFE is received in an ISO channel)
 * - received a frame in the wrong state
 * - error handling of the contained field values permitted further processing
 */
#define FRTP_E_IGNORED_RX_PDU 0x10U

/**
 * Used to trace internal coding errors in development mode.
 */
#define FRTP_E_ASSERT 0x11U

/**
 * In state machine functions the appropriate channel could not be found
 */
#define FRTP_E_UNEXP_STATE_EVENT 0x12U

/**
 * In state machine functions the appropriate channel could not be found
 */
#define FRTP_E_NO_CHANNEL 0x13U

/* ----------------------------------------------------------------------------
 Global Macro Checks
 ---------------------------------------------------------------------------- */

/**
 * Configuration Interface Version Information
 */
/** BSW to MCG interface variant */
#define FRTP_BSW_MCG_IFVERSION_VARIANT  (1)
#define FRTP_BSW_MCG_IFVERSION_PROVIDED (2)
#define FRTP_BSW_MCG_IFVERSION_REQUIRED (2)

/** macro for checking the BSW to MCG interface versions */
/* Deviation MISRA-1 */
#define FRTP_BSW_MCG_IFVERSION_CHECK(mcg_bsw_prov_ifvariant,        \
                                     mcg_bsw_prov_ifversion,        \
                                     mcg_bsw_requ_ifversion)        \
    (((FRTP_BSW_MCG_IFVERSION_VARIANT) == (mcg_bsw_prov_ifvariant)) && \
     ((FRTP_BSW_MCG_IFVERSION_PROVIDED) >= (mcg_bsw_requ_ifversion)) && \
     ((FRTP_BSW_MCG_IFVERSION_REQUIRED) <= (mcg_bsw_prov_ifversion))    \
    )


/** macro for checking the BSW to MCG interface versions */
/* Deviation MISRA-1 */
#define FRTP_SW_VERSION_CHECK(file_sw_major_version,        \
                              file_sw_minor_version,        \
                              file_sw_patch_version)        \
    (((FRTP_SW_MAJOR_VERSION) == (file_sw_major_version)) && \
     ((FRTP_SW_MINOR_VERSION) == (file_sw_minor_version)) && \
     ((FRTP_SW_PATCH_VERSION) == (file_sw_patch_version))    \
    )

/* Local file software version check */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif

/**
 * Consistency checking of the used static configuration parameter
 */
#if (!FRTP_BSW_MCG_IFVERSION_CHECK(FRTP_MCG_BSW_IFVERSION_VARIANT, \
                                   FRTP_MCG_BSW_IFVERSION_PROVIDED, \
                                   FRTP_MCG_BSW_IFVERSION_REQUIRED))
#error Interface version number mismatch
#endif

/**
* Check for defined STD_ON and STD_OFF macro value. It is a precondition that these
* values are defined, when using this file.
*/
#ifndef STD_ON
#error "FrTp: STD_ON not defined, this is a prerequisit"
#endif

#ifndef STD_OFF
#error "FrTp: STD_OFF not defined, this is a prerequisit"
#endif

/**
 * FrTp parameters have to be defined and have to be either STD_ON or STD_OFF
 */
#ifdef FRTP_VERSION_INFO_API
#if   (FRTP_VERSION_INFO_API != STD_ON) \
    &&(FRTP_VERSION_INFO_API != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_VERSION_INFO_API"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_VERSION_INFO_API"
#endif

#ifdef FRTP_DEV_ERROR_DETECT
#if   (FRTP_DEV_ERROR_DETECT != STD_ON) \
    &&(FRTP_DEV_ERROR_DETECT != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_DEV_ERROR_DETECT"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_DEV_ERROR_DETECT"
#endif

/**
 * FrTp number of channels have to be defined and in range [1..32]
 */
#ifdef FRTP_CHAN_NUM
#if   (FRTP_CHAN_NUM >  32) \
    ||(FRTP_CHAN_NUM <  1)
#error "FrTp: FRTP_CHAN_NUM not in range"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_CHAN_NUM"
#endif

/**
 * FrTp Pdu maximum length to be defined
 */
#ifdef FRTP_PDU_MAXLEN
#if   (FRTP_PDU_MAXLEN >  254) \
    ||(FRTP_PDU_MAXLEN <  1)
#error "FrTp: FRTP_PDU_MAXLEN not in range"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_PDU_MAXLEN"
#endif

/**
 * FrTp number of connections have to be defined
 */
#ifndef FRTP_CON_NUM
#error "FrTp config error: Missing parameter FRTP_CON_NUM"
#endif

/**
 * FrTp number of TX-PDUs have to be defined
 */
#ifndef FRTP_TX_PDU_NUM
#error "FrTp config error: Missing parameter FRTP_TX_PDU_NUM"
#endif

/**
 * FrTp number of RX-PDU have to be defined
 */
#ifndef FRTP_RX_PDU_NUM
#error "FrTp config error: Missing parameter FRTP_RX_PDU_NUM"
#endif

/**
 * Size of buffers for all PDUs has to be defined
 */
#ifndef FRTP_PDU_BUFFER_SIZE
#error "FrTp config error: Missing parameter FRTP_PDU_BUFFER_SIZE"
#endif

/**
 * Number of Pdu-Info buffers have to be defined
 */
#ifndef FRTP_PDUINFO_BUFFER_NUM
#error "FrTp config error: Missing parameter FRTP_PDUINFO_BUFFER_NUM"
#endif

/**
 * FrTp role has to be defined
 */
#ifndef FRTP_ROLE
#error "FrTp config error: Missing parameter FRTP_ROLE"
#endif

/**
 * FrTp retry buffer size has to be defined, even it could be zero
 */
#ifndef FRTP_RETRY_BUFFER_SIZE
#error "FrTp config error: Missing parameter FRTP_RETRY_BUFFER_SIZE"
#endif



#ifdef FRTP_RELOCATABLE_CONFIG
#if   (FRTP_RELOCATABLE_CONFIG != STD_ON) \
    &&(FRTP_RELOCATABLE_CONFIG != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_RELOCATABLE_CONFIG"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_RELOCATABLE_CONFIG"
#endif

#ifdef FRTP_RELOCATABLE_CONFIG_ALIGNMENT
#if   (FRTP_RELOCATABLE_CONFIG_ALIGNMENT != STD_ON) \
    &&(FRTP_RELOCATABLE_CONFIG_ALIGNMENT != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_RELOCATABLE_CONFIG_ALIGNMENT"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_RELOCATABLE_CONFIG_ALIGNMENT"
#endif

#if   (FRTP_RELOCATABLE_CONFIG_ALIGNMENT == STD_ON) \
    &&(FRTP_RELOCATABLE_CONFIG != STD_ON)
#error "FrTp config error: If FRTP_RELOCATABLE_CONFIG_ALIGNMENT is enabled, FRTP_RELOCATABLE_CONFIG shall be enabled"
#endif

#ifdef FRTP_DECOUPLED_FRIF_TX_ENABLE
#if   (FRTP_DECOUPLED_FRIF_TX_ENABLE != STD_ON) \
    &&(FRTP_DECOUPLED_FRIF_TX_ENABLE != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_DECOUPLED_FRIF_TX_ENABLE"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_DECOUPLED_FRIF_TX_ENABLE"
#endif

#ifdef FRTP_OPT_ONE_PDU_PER_CONNECTION
#if   (FRTP_OPT_ONE_PDU_PER_CONNECTION != STD_ON) \
    &&(FRTP_OPT_ONE_PDU_PER_CONNECTION != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_OPT_ONE_PDU_PER_CONNECTION"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_OPT_ONE_PDU_PER_CONNECTION"
#endif

#ifdef FRTP_OPT_DISTINCT_CONNECTION_EACH_PDU
#if   (FRTP_OPT_DISTINCT_CONNECTION_EACH_PDU != STD_ON) \
    &&(FRTP_OPT_DISTINCT_CONNECTION_EACH_PDU != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_OPT_DISTINCT_CONNECTION_EACH_PDU"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_OPT_DISTINCT_CONNECTION_EACH_PDU"
#endif

#ifdef FRTP_OPT_LOCAL_POINTERS
#if   (FRTP_OPT_LOCAL_POINTERS != STD_ON) \
    &&(FRTP_OPT_LOCAL_POINTERS != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_OPT_LOCAL_POINTERS"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_OPT_LOCAL_POINTERS"
#endif

#ifdef FRTP_USE_STD_MEMCPY
#if   (FRTP_USE_STD_MEMCPY != STD_ON) \
    &&(FRTP_USE_STD_MEMCPY != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_USE_STD_MEMCPY"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_USE_STD_MEMCPY"
#endif

#ifdef FRTP_MULTIPLE_CHANNEL_ENABLE
#if   (FRTP_MULTIPLE_CHANNEL_ENABLE != STD_ON) \
    &&(FRTP_MULTIPLE_CHANNEL_ENABLE != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_MULTIPLE_CHANNEL_ENABLE"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_MULTIPLE_CHANNEL_ENABLE"
#endif

#ifdef FRTP_SUPPORT_TXWAIT
#if   (FRTP_SUPPORT_TXWAIT != STD_ON) \
    &&(FRTP_SUPPORT_TXWAIT != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_SUPPORT_TXWAIT"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_SUPPORT_TXWAIT"
#endif

#ifdef FRTP_TX_BUFFER_REQUEST_ZERO
#if   (FRTP_TX_BUFFER_REQUEST_ZERO != STD_ON) \
    &&(FRTP_TX_BUFFER_REQUEST_ZERO != STD_OFF)
#error "FrTp config error: Wrong value for FRTP_TX_BUFFER_REQUEST_ZERO"
#endif
#else
#error "FrTp config error: Missing parameter FRTP_TX_BUFFER_REQUEST_ZERO"
#endif

#endif /* _FRTP_EXTENSION_H_ */
