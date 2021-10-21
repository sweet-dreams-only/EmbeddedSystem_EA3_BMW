/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** FrTp API prototypes
 **
 ** \file    FrTp.h
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
 * MISRA-1) Deviated Rule: 19.7 (required)
 * A function could probably be used instead of this function-like macro.
 *
 * Reason:
 * increase readability of source code. 
 */


#ifndef _FRTP_H_
#define _FRTP_H_

/* ----------------------------------------------------------------------------
 Include Section
 ---------------------------------------------------------------------------- */

#include "ComStack_Types.h" /* basic commstack types from AUTOSAR */


/**
 * Version information about the FrTp configuration interface
 * This version defines the interface, used by the FrTp
 * configuration wizard and the FrTp basic software implementation.
 */
#define FRTP_BSWIF_VERSION 1
#define FRTP_CFGIF_VERSION_REQUIRED 1

/* Deviation MISRA-1 */
#define FRTP_CFGIF_VERSION_CHECK(reserved, bswif_required, cfgif)   \
    ((FRTP_BSWIF_VERSION >= (bswif_required)) &&                    \
     (FRTP_CFGIF_VERSION_REQUIRED <= (cfgif)))


#include "FrTp_Cfg.h"       /* static configuration of FrTp */

/* ----------------------------------------------------------------------------
 Global Macros
---------------------------------------------------------------------------- */

/**
 * Vendor ID according to HIS; satisfies [FRTP178], [BSW00374], [BSW00402]
 * DECOMSYS = 10
 */
#define FRTP_VENDOR_ID 1U

/**
 * Unique module ID for FrTp; satisfies [FRTP178], [BSW00402]
 */
#define FRTP_MODULE_ID 0x24U



#if (FRTP_DEV_ERROR_DETECT == STD_ON)
/**
 * The module id, used for reporting errors via DET is defined for each
 * instance of the FrTp. Nevertheless an overall instance id must be defined
 * for reporting errors concerning the whole FrTp or for errors, where
 * no instance id can be applied.
 * FRTP_DET_GENERIC_INSTANCE_ID defines a virtual instance id of the FrTp
 * for calling DET api functions.
 */
#define FRTP_DET_GENERIC_INSTANCE_ID 0xFFU
#endif

/*
 * Version information of AUTOSAR specification on which the appropriate
 * implementation is based on [FRTP178].
 */
#define FRTP_AR_MAJOR_VERSION 2
#define FRTP_AR_MINOR_VERSION 2
#define FRTP_AR_PATCH_VERSION 0

/*
 * Version information [FRTP178] [FRTP200] [FRTP201]. This version number is
 * vendor specific.
 */
#define FRTP_SW_MAJOR_VERSION 1
#define FRTP_SW_MINOR_VERSION 2
#define FRTP_SW_PATCH_VERSION 6

#include "FrTp_Extension.h"

/**
 * Service identifiers for all API functions of the FrTp
 */
#define FRTP_GETVERSIONINFO_SERVICE_ID             0x27U
#define FRTP_INIT_SERVICE_ID                       0x00U
#define FRTP_SHUTDOWN_SERVICE_ID                   0x01U
#define FRTP_TRANSMIT_SERVICE_ID                   0x02U
#define FRTP_CANCELTRANSMITREQUEST_SERVICE_ID      0x03U
#define FRTP_CHANGEPARAMETERREQUEST_SERVICE_ID     0x04U
#define FRTP_TRIGGERTRANSMIT_SERVICE_ID            0x07U
#define FRTP_RXINDICATION_SERVICE_ID               0x05U
#define FRTP_TXCONFIRMATION_SERVICE_ID             0x06U
#define FRTP_MAINFUNCTION_SERVICE_ID               0x10U
#define FRTP_RXSTATEMACHINE_SERVICE_ID             0x11U
#define FRTP_TXSTATEMACHINE_SERVICE_ID             0x12U

/*
 * Following error identifiers for the Development Error Tracer are
 * used for the development of FrTp [FRTP187].
 */
/**
 * API service called before initializing the module
 * be executed. Satisfies [FRTP179].
 */
#define FRTP_E_NOT_INIT 0x01U

/**
 * API service called with NULL pointer. Satisfies [FRTP179].
 */
#define FRTP_E_NULL_PTR 0x02U

/**
 * API service called with not allowed parameter value. Satisfies [FRTP179].
 */
#define FRTP_E_WRONG_PARAM_VAL 0x03U


/**
 * Extensions of AUTOSAR NotifResultType [FRTP142]. Defined in ComStack_Types.h
 */

/**
 * Invalid BS value received (Sender Side)
 */
#define NTFRSLT_E_FR_INVALID_BS 0x5BU

/**
 * Number of retries has exceed FRTP_MAXRN (Sender and Receiver Side)
 */
#define NTFRSLT_E_FR_RN_OVRN 0x5CU

/**
 * AF with invalid value of the ACK field received (Sender Side)
 */
#define NTFRSLT_E_FR_INVALID_ACK 0x5DU

/**
 * AF with ACK = NEG_ACK received (Sender Side)
 */
#define NTFRSLT_E_FR_NEG_ACK 0x5EU

/**
 * FrIf did not accept the transmit request (Sender and Receiver Side)
 */
#define NTFRSLT_E_FR_FRIF_ERROR 0x5FU

/**
 * FC frame with FS = FRTP_CNLDO received (Sender and Receiver Side)
 */
#define NTFRSLT_E_FR_CNLDO 0x60U

/**
 * FC frame with FS = FRTP_CNLNB received (Sender and Receiver Side)
 */
#define NTFRSLT_E_FR_CNLNB 0x61U

/**
 * FC frame with FS = FRTP_CNLOR received (Sender and Receiver Side)
 */
#define NTFRSLT_E_FR_CNLOR 0x62U


/* ----------------------------------------------------------------------------
 Global Data Types
---------------------------------------------------------------------------- */

/**
 * The cancel reason is sent to the other peer by the means of an appropriate FC
 * frame.
 */
typedef enum
{
    FRTP_CNLDO, /**< Cancel Transfer because data are outdated */
    FRTP_CNLNB, /**< Cancel Transfer because no further buffer can be
                     provided */
    FRTP_CNLOR  /**< Cancel Transfer because of another reason */
} FrTp_CancelReasonType;

typedef uint8 FrTp_ParameterValueType;

typedef enum
{
    FRTP_CHANGE_OK,       /**< Successful execution of the parameter change
                               request. Enum changed to FRTP_CHANGE_OK because
                               of conflict of [FRTP146] and [FRTP194] */
    FRTP_RX_ON,           /**< Parameter change request not executed due to an
                               ongoing reception */
    FRTP_WRONG_PARAMETER, /**< Parameter change request not executed due to a
                               wrong value for FrTp_ParameterType */
    FRTP_WRONG_VALUE      /**< Parameter change request not executed due to a
                               wrong value for FrTp_ParameterValueType */
} FrTp_ChangeResultType;

typedef enum
{
    FRTP_OK, /**< Successful execution of the cancel transmit request */
    FRTP_E_NOT_OK  /**< Cancellation was not successful, e. g. the FC(CNLxx)
                        could not be sent */
} FrTp_CancelResultType;

typedef struct
{
    PduIdType FRTP_PDUID;          /**< The PDU-ID */
    PduLengthType FRTP_PDU_LENGTH; /**< Length of the PDU */
} FrTp_PduInfoType;

/* ----------------------------------------------------------------------------
 Global Function Declarations
---------------------------------------------------------------------------- */
/* start code section declaration */
#define FRTP_START_SEC_CODE
#include "MemMap.h"

/**
 * \brief This service returns the version information of this module. The
 *        version information includes: Module Id, Vendor Id and Vendor specific
 *        version numbers [BSW00407].
 *
 * \param versioninfo (out) Pointer to where to store the version information of
 *                          this module.
 *
 * \remarks Configuration: Optional (Only available if FRTP_VERSION_INFO_API
 *          is defined).
 *          If FRTP_DEV_ERROR_DETECT == STD_OFF the function is implemented as a
 *          macro in FrTp.h [FRTP211].
 */
#if (FRTP_VERSION_INFO_API == STD_ON)
extern FUNC(void,FRTP_CODE) FrTp_GetVersionInfo(
    P2VAR(Std_VersionInfoType,AUTOMATIC,FRTP_APPL_DATA) versioninfo
    );
#else
#define FrTp_GetVersionInfo(versioninfo)                          \
    do {                                                          \
        (versioninfo)->vendorID = FRTP_VENDOR_ID;                 \
        (versioninfo)->moduleID = FRTP_MODULE_ID;                 \
        (versioninfo)->sw_major_version = FRTP_SW_MAJOR_VERSION;  \
        (versioninfo)->sw_minor_version = FRTP_SW_MINOR_VERSION;  \
        (versioninfo)->sw_patch_version = FRTP_SW_PATCH_VERSION;  \
    } while (0)
#endif /* FRTP_VERSION_INFO_API */

/**
 * \brief This service initializes all global variables of a FlexRay Transport
 *        Layer instance and set it in the idle state.
 *
 * \remarks The call of this service is mandatory before using the FrTp instance
 *          for further processing.
 *          This function has to be called after initialization of the FlexRay
 *          interface. This function uses guards for controlling the mutual
 *          access to the data elements of the FrTp. The caller of this function
 *          has to be aware about the implementation of these macros and that
 *          the calls are allowed at the time of executing FrTp_Init() (e.g. no
 *          interrupt locks allowed in StartupHook of OSEKTime).
 */
extern FUNC(void,FRTP_CODE) FrTp_Init(
#if (FRTP_RELOCATABLE_CONFIG == STD_ON)
    P2CONST(void,AUTOMATIC,FRTP_APPL_CONST) PBCfgPtr
#else
    void
#endif
    );

/**
 * \brief This service closes all pending transport protocol connections by
 *        simply stopping operation, frees all resources and stops the FrTp
 *        Module.
 */
extern FUNC(void,FRTP_CODE) FrTp_Shutdown(void);

/**
 * \brief Request the transfer of data.
 *
 * \param FrTpTxPduId (in) contains the FlexRay TP instance unique identifier of
 *                         the Fr N-SDU to be transmitted.
 * \param PduInfoPtr (in)  A pointer to a structure with Fr N-SDU related data:
 *                         data length and pointer to an Fr N-SDU buffer.
 *
 * \return E_OK            The request has been accepted
 * \return E_NOT_OK        The request has not been accepted, e. g. due to a
 *                         still ongoing transmission in the corresponding
 *                         channel or the to be transmitted message is too
 *                         long.
 */
extern FUNC(Std_ReturnType,FRTP_CODE) FrTp_Transmit(
    VAR(PduIdType,AUTOMATIC) FrTpTxPduId,
    P2CONST(PduInfoType,AUTOMATIC,FRTP_APPL_DATA) PduInfoPtr
    );

/**
 * \brief This service primitive is used to cancel the transfer of pending Fr
 *        N-SDUs. The connection is identified by FrTpTxSduId.
 *
 * \param FrTpTxPduId (in) contains the FlexRay TP instance unique identifier of
 *                         the Fr N-SDU to be cancelled.
 * \param Reason (in)      The reason for cancellation.
 *
 * \return E_OK            Cancellation request of the transfer (sending or
 *                         receiving) of the specified Fr N-SDU is accepted.
 * \return E_NOT_OK        Cancellation request of the transfer of the specified
 *                         Fr N-SDU is rejected, e. g. cancellation is requested
 *                         at the receiver in an 1:n connection or in an
 *                         unsegmented transfer at the receiver or cancellation
 *                         is not allowed for the corresponding channel.
 */
extern FUNC(Std_ReturnType,FRTP_CODE) FrTp_CancelTransmitRequest(
    VAR(PduIdType,AUTOMATIC) FrTpTxPduId,
    VAR(FrTp_CancelReasonType,AUTOMATIC) Reason
    );

/**
 * \brief This service primitive is used to request the change of the value of
 *        the FRTP_STMIN parameter.
 *
 * \param FrTpTxPduId (in) Gives the ID of the connection (message) for whose
 *                         channel the change shall be done.
 * \param FrTp_ParameterValueType (in) contains the new value of FRTP_STMIN.
 */
extern FUNC(void,FRTP_CODE) FrTp_ChangeParameterRequest(
    VAR(PduIdType,AUTOMATIC) FrTpTxPduId,
    VAR(FrTp_ParameterValueType,AUTOMATIC) FrTpParameterValue
    );

/**
 * \brief The main function for scheduling the TP (Entry point for scheduling)
 */
extern FUNC(void,FRTP_CODE) FrTp_MainFunction(void);

/* start code section declaration */
#define FRTP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* _FRTP_H_ */
