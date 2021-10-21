/*
  SRC-MODULE: Dcm_types.h                                                   
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm Module type definition file                               
                                                                            
  REMARKS   :                                                               
                                                                            
  PLATFORM DEPENDANT [yes/no]: no                                           
                                                                            
  TO BE CHANGED BY USER [yes/no]: no                                        
                                                                            
*/

/*
                      Author Identity                                       


 Initials     Name                       Company
 --------     -------------------------  -------------------------------------
 gan          Norbert Gaier              Softing AG
 vm           Volker Matthes             BMW
 scma         Scheitterer Martin         MB Technology
 wab          Wolfgang Aberle            MB Technology
 anam         Andreas Amann              MB Technology
 gema         Markus Gerngross           MB Technology
*/

/*
                      Revision Control History                              
*/

/*
 * v 1.1.26,2006.07.19, gan : DCM Module based on DCM specs v.2.0.0
 * v 2.0.0, 2007.09.28, gan : DCM Module + BMW Standard Core 7 additions
 * v 2.1.0, 2007.10.10, gan : Bug-fixing changes
 * v 2.1.1, 2007.10.17, gan : Bug-fixing changes
 * v 2.1.2, 2007.10.23, gan : Bug-fixing and enhancements
 * v 2.1.3, 2007.11.08, gan : Bug-fixing and enhancements
 * v 2.1.4, 2007.12.05, gan : Bug-fixing
 * v 2.1.5, 2008.02.07, gan : Bug-fixing
 * v 2.1.6, 2008.02.29, gan : Bug-fixing
 * v 2.1.7, 2008.06.06, gan : Bug-fixing
 * v 2.1.8, 2008.08.15, gan : Bug-fixing
 * v 2.1.9, 2008.10.31, gan : Bug-fixing
 * v 2.2.0, 2008.12.03, gan : DCM release 2.2.0 delivery
 * v 2.2.1, 2009.01.30, gan : Several changes requested by BMW
 * v 2.2.2, 2009.02.20, gan : Bug-fixing
 *          2009.02.26, vm  : CR 70094 reworked 
 * v 2.2.3, 2009.03.27, gan : CR 70189: "Dcm_SuppressionOverride" flag is not reset.
 * v 2.2.4, 2009.04.22, vm  : CR 70194: Response behavior for functional adressed requests is not correct
 *          2009.04.22, vm  : CR 70200: S3 Timer handling not correct
 * v 2.3.0, 2009.08.04, scma: Initialize response data buffer with request
 *                            data buffer for Bootloader added
 * v 2.3.2, 2009.10.10, gan : CR 70286 Change storage classes in compiler abstraction for DCM
 *                            CR 70330 Dcm: wrong memory mapping
 *                            CR 70331 Dcm warnings
 *                            CR 70335 Dcm-Functionpointer corruption
 *                            CR 70351 Dcm source code has mismatching memory sections 
 *                            CR 70357 DCM: Behaviour when ResponsePending could not be sent
 *                            CR 70361 Dcm: compiler warning
 *          2010.11.02, gema: CR 70261 Dcm-Generator do not check validy of config
 *                            CR 70429 Relocation of wrapper between DCM and bootdiag 
 * v 2.3.3, 2009.11.02, anam: CR 70460: Code Size Optimization - Dcm - 
 *                                      BAC HIS implementation guidelines 
 *          2009.12.04, wab : CR 70338: DCM: Problems with DCMModuleGenerator.exe
 *                            CR 70339: Generator crashes when removing the 
 *                                      optional container DcmDspReadDTC
 *                            CR 70393: Arrays in dcm_cfg.h are badly formatted
 *                            CR 70344: DCM: PROTOCOL_LIMITSTIMING_STRUCTURE is
 *                                      generated with values of DCM_DEFAULT 
 *                            CR 70401: Errors in Dcm example configuration
 *                            CR 70384: Dcm generator should generate symbolic 
 *                                      names
 *                            CR 70452: Dcm: Special buffers are not used
 * v 2.4.2, 2009.23.03, anam: CR 70604: Dcm_ResponsePendingType typedef name clash
 * v 2.5.0, 2010.10.26, anam: CR 70846: DCM: Completion of the OBD Sevices Implementation in DCM 
 *                                      according to the Autosar DCM V.3.1
 */

/**************************************************************************************************************************
 * Nxtr Version Control:
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
10/05/16     EA3#3     ABS        Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
**************************************************************************************************************************/
 
#ifndef __DCM_TYPES_H__
#define __DCM_TYPES_H__


/*
                      Include Section                                       
*/

#include "Dcm_cfg.h"
#include "ComStack_Types.h"
#include "Compiler.h"


/*
                      Global Macros                                         
*/

#ifdef __DCM_C__
#define DCM_AR_EXTERN
#else
#define DCM_AR_EXTERN extern
#endif   

/*! \enum  Dcm_NegativeResponseCodeTypes;
 *  \brief Definition of negative response codes
 *
 *  \var  DCM_E_GENERALREJECT                          = 0x10
 *  \var    DCM_E_SERVICENOTSUPPORTED                    = 0x11
 *  \var  DCM_E_SUBFUNCTIONNOTSUPPORTED                = 0x12
 *  \var  DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT  = 0x13
 *  \var  DCM_E_RESPONSE_TOO_LONG                      = 0x14  
 *  \var    DCM_E_BUSYREPEATREQUEST                                = 0x21
 *  \var    DCM_E_CONDITIONSNOTCORRECT                           = 0x22
 *  \var    DCM_E_REQUESTSEQUENCEERROR                           = 0x24
 *  \var  DCM_E_NORESPONSEFROMSUBNETCOMPONENT          = 0x25
 *  \var  DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION = 0x26
 *  \var    DCM_E_REQUESTOUTOFRANGE                              = 0x31
 *  \var    DCM_E_SECURITYACCESSDENIED                           = 0x33
 *  \var    DCM_E_INVALIDKEY                                         = 0x35
 *  \var    DCM_E_EXCEEDNUMBEROFATTEMPTS                         = 0x36
 *  \var    DCM_E_REQUIREDTIMEDELAYNOTEXPIRED                  = 0x37
 *  \var    DCM_E_UPLOADDOWNLOADNOTACCEPTED                  = 0x70
 *  \var    DCM_E_TRANSFERDATASUSPENDED                  = 0x71
 *  \var    DCM_E_GENERALPROGRAMMINGFAILURE              = 0x72
 *  \var    DCM_E_WRONGBLOCKSEQUENCECOUNTER              = 0x73
 *  \var    DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING= 0x78
 *  \var    DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION = 0x7E
 *  \var    DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION     = 0x7F
 *  \var    DCM_E_RPMTOOHIGH                             = 0x81
 *  \var    DCM_E_RPMTOOLOW                                          = 0x82
 *  \var    DCM_E_ENGINEISRUNNING                        = 0x83
 *  \var    DCM_E_ENGINEISNOTRUNNING                     = 0x84
 *  \var    DCM_E_ENGINERUNTIMETOOLOW                    = 0x85
 *  \var    DCM_E_TEMPERATURETOOHIGH                     = 0x86
 *  \var    DCM_E_TEMPERATURETOOLOW                      = 0x87
 *  \var    DCM_E_VEHICLESPEEDTOOHIGH                    = 0x88
 *  \var    DCM_E_VEHICLESPEEDTOOLOW                     = 0x89
 *  \var    DCM_E_THROTTLE_PEDALTOOHIGH                          = 0x8A
 *  \var    DCM_E_THROTTLE_PEDALTOOLOW                           = 0x8B
 *  \var    DCM_E_TRANSMISSIONRANGENOTINNEUTRAL              = 0x8C
 *  \var    DCM_E_TRANSMISSIONRANGENOTINGEAR             = 0x8D
 *  \var    DCM_E_BREAKSWITCH_NOTCLOSED                  = 0x8F
 *  \var    DCM_E_SHIFTERLEVERNOTINPARK                          = 0x90
 *  \var    DCM_E_TORQUECONVERTERCLUTCHLOCKED                  = 0x91
 *  \var    DCM_E_VOLTAGETOOHIGH                                     = 0x92
 *  \var    DCM_E_VOLTAGETOOLOW                                      = 0x93
 */

#define     DCM_E_GENERALREJECT                           0x10
#define     DCM_E_SERVICENOTSUPPORTED                     0x11
#define     DCM_E_SUBFUNCTIONNOTSUPPORTED                 0x12
#define   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT   0x13
#define   DCM_E_RESPONSE_TOO_LONG                       0x14
#define     DCM_E_BUSYREPEATREQUEST                                 0x21
#define     DCM_E_CONDITIONSNOTCORRECT                            0x22
#define   DCM_E_REQUESTSEQUENCEERROR                              0x24
#define   DCM_E_NORESPONSEFROMSUBNETCOMPONENT           0x25
#define   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION 0x26
#define   DCM_E_REQUESTOUTOFRANGE                                 0x31
#define   DCM_E_SECURITYACCESSDENIED                              0x33
#define     DCM_E_INVALIDKEY                                          0x35
#define     DCM_E_EXCEEDNUMBEROFATTEMPTS                          0x36
#define     DCM_E_REQUIREDTIMEDELAYNOTEXPIRED                   0x37
#define     DCM_E_UPLOADDOWNLOADNOTACCEPTED                   0x70
#define     DCM_E_TRANSFERDATASUSPENDED                   0x71
#define     DCM_E_GENERALPROGRAMMINGFAILURE               0x72
#define     DCM_E_WRONGBLOCKSEQUENCECOUNTER               0x73
#define     DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING 0x78
#define     DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION  0x7E
#define     DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION      0x7F
#define     DCM_E_RPMTOOHIGH                              0x81
#define     DCM_E_RPMTOOLOW                                           0x82
#define     DCM_E_ENGINEISRUNNING                         0x83
#define     DCM_E_ENGINEISNOTRUNNING                      0x84
#define     DCM_E_ENGINERUNTIMETOOLOW                     0x85
#define     DCM_E_TEMPERATURETOOHIGH                      0x86
#define     DCM_E_TEMPERATURETOOLOW                       0x87
#define     DCM_E_VEHICLESPEEDTOOHIGH                     0x88
#define     DCM_E_VEHICLESPEEDTOOLOW                      0x89
#define     DCM_E_THROTTLE_PEDALTOOHIGH                           0x8A
#define     DCM_E_THROTTLE_PEDALTOOLOW                            0x8B
#define     DCM_E_TRANSMISSIONRANGENOTINNEUTRAL               0x8C
#define     DCM_E_TRANSMISSIONRANGENOTINGEAR              0x8D
#define     DCM_E_BREAKSWITCH_NOTCLOSED                   0x8F
#define     DCM_E_SHIFTERLEVERNOTINPARK                           0x90
#define     DCM_E_TORQUECONVERTERCLUTCHLOCKED                   0x91
#define     DCM_E_VOLTAGETOOHIGH                                      0x92
#define     DCM_E_VOLTAGETOOLOW                                       0x93

#define DCM_DTRSTATUS_VISIBLE   0x00
#define DCM_DTRSTATUS_INVISIBLE 0x01

/* >> GAN:2008-02-04 New type for Negative Response Codes*/
typedef uint8 Dcm_NegativeResponseCodeType;
/* << GAN:2008-02-04 New type for Negative Response Codes*/

/*
                      Global Data Types                                     
*/

/*! \enum Dcm_WaitForConfirmationStatusType
 *  \brief Store information about the status of the confirmation. 
 *         Needed for ResponsePending and FlexRay
 */
typedef enum
{
   DCM_NO_CONFIRMATION_WAIT  = 0, /* disable the wait for confirmation for a message*/
   DCM_WAIT_FOR_CONFIRMATION = 1, /* Enable the wait for confirmation for a message*/ 
   DCM_CONFIRAMTION_ARRIVED  = 2  /* Confirmation has arrived and the message can be sent*/
}Dcm_WaitForConfirmationStatusType;

/*! \enum Dcm_ResponseMessageType
 *  \brief Store information about the kind of response
 */
typedef enum
{
   DCM_NO_NEG_RESPONSE          = 0,
   DCM_NEG_RESPONSE             = 1,
   DCM_RESPONSE_PENDING_OR_BUSY = 2
}Dcm_ResponseMessageType;


/*! \enum Dcm_CommunicationStateType
 *  \brief Type for DCM state machine \n
 *         Declares the DCM state machine types that are associated with the Dcm_CommunicationState variable\n  
 *         
 *   This type holds the enumeration values for the states of the DCM. 
 *
 *
 */
typedef enum
{
 DCM_NO_COMMUNICATION,
 DCM_SILENT_COMMUNICATION,
 DCM_FULL_COMMUNICATION 
}Dcm_CommunicationStateType;

/*!
* \enum Dcm_DataProcessorType
* \brief This enumeration type declares the possible data processors.
*
*       Each diagnostic service shall be executed by one data processor. The data processors can be either 
*  the DSP layer of the DCM or the RTE Dcm_Module of the AUTOSAR. This enumeration type contains two values
*  for the DSP and the RTE respectively.
*
*/

typedef enum
 {
    DCM_DSP,
    DCM_RTE
 }Dcm_DataProcessorType;
 
/*!
* \enum Dcm_TransmissionType
* \brief This enumeration type declares the possible transmission types
*
*   The ROE and PERIODIC processings can be executed in two different transmission types. This type allows the user to configure the type of this transmission.
*
*/ 
 
typedef enum
{
  TYPE1,
  TYPE2
}Dcm_TransmissionType;


/*!
* \enum Dcm_ForcedResponsePendingType
* \brief This enumeration type indicates if a response pending transmission is currently in progress
*/ 
typedef enum 
{
    DCM_NO_RESPONSE_PENDING     = 0, /*No response pending active*/
    DCM_NORMAL_RESPONSE_PENDING = 1, /*A response pending is requested by the Dcm module after a P2 /P2* timeout */
    DCM_FORCED_RESPONSE_PENDING = 2  /*A forced response pending is requested by the application*/
}Dcm_ForcedResponsePendingType;

/*! \struct Dcm_Current_Message_Status_Type
 *  \brief  Main status struct for the DCM
 *
 *  This structure shall contain fields for relevant parameters that must be kept each time a request
 *  is being processed. These parameters shall store information about security and session level, priorities,
 *  timing parameters, diagnostic service information (SID, RxPduId, TxPduId), links to configuration tables
 *  for protocol, buffers, timings. The buffer used by the current processing is also stored by this structure
 *  along with the protocol that has been started.
 *
 *  \param     uint8   Dcm_SID;                    service Id currently processed           
 *  \param     uint8   Dcm_StartProtocolStatus;      if protocol has been started 
 *  \param     uint8   Dcm_Busy_Repeat_Request;      used for the protocol preemption functionality
 *  \param     uint8   Dcm_Transmission;           this parameter signals if the response has been assembled and it is ready for transmission
 *  \param     uint8   Dcm_Active_Message_Prio;      current priority of the protocol
 *  \param     uint8   Dcm_Message_Status_Busy;      this shall be the buffer Id + 1 (+1 is used to avoid the usage of value 0)
 *  \param     uint8   Dcm_Message_DcmRxPduId;       RxPduId, also gives the line in configuration table DIAGNOSTIC_PROTOCOL_RX_TABLE
 *  \param     uint8   Dcm_Message_DcmTxPduId;     TxPduId used during current processing
 *  \param     uint8   Dcm_TxTableIndex;           index in DIAGNOSTIC_PROTOCOL_TX_TABLE
 *  \param     uint8   Dcm_ProtocolTableIndex;     index in the DIAGNOSTIC_PROTOCOL_TABLE
 *  \param Dcm_ForcedResponsePendingType Dcm_ForcedRespPend;         signals if the last response pending sent is forced or not
 *  \param Dcm_DataProcessorType Dcm_DataProcessor;  information about the data processor that executes this service
 *  \param     uint16  Dcm_NormalResponseTimer;    used to count the normal request timer
 *  \param     uint16  Dcm_BusyProcessingTimer;    used to count the busy processing timer
 *  \param     uint16  Dcm_ProtocolPreemptTimer;   used to count the protocol preemption timer
 *  \param     uint16  Dcm_S3ServerTimer;          used to count the S3Server timer
 *  \param     uint16  Dcm_PagedBufferTimer;       used to count the paged buffer timer
 *  \param     uint16  Dcm_SecurityAccessTimer;    used to count the security access timer
 *  \param     uint8   Dcm_NormalResponseIncrement;    value that increases the normal request timer (if 0 the timer is not active)
 *  \param     uint8   Dcm_BusyProcessingIncrement;    value that increases the busy processing timer (if 0 the timer is not active)
 *  \param     uint8   Dcm_ProtocolPreemptIncrement;   value that increases the protocol preemption timer (if 0 the timer is not active)
 *  \param     uint8   Dcm_S3ServerIncrement;          value that increases the S3Server timer (if 0 the timer is not active)
 *  \param     uint8   Dcm_PagedBufferIncrement;       value that increases the paged buffer timer (if 0 the timer is not active)
 *  \param     uint8   Dcm_SecurityAccessIncrement;    value that increases the security access timer (if 0 the timer is not active)
 *  \param     uint8   Dcm_InitialSecurityAccessIncrement;  value used to increment the security timer in case the initial timer is active
 *  \param     uint8   Dcm_ActiveSession            currently active session
 *  \param     uint8   Dcm_ActiveSecurityLevel      currently active security level
 *  \param     uint16  Dcm_PagedProcessing_DataLen  length of the message during paged buffer processing
 *  \param     uint8   Dcm_NumberRespPend;          this shall hold the number of consecutive response pendings sent
 */
     
typedef struct{
   uint8   Dcm_SID;             /* for storage of the Service Identifier*/
   uint8   Dcm_StartProtocolStatus;     /* Protocol- Status, if diagnosis allowed from the application*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
   unsigned int   Dcm_Busy_Repeat_Request:1;        /* Busy status*/
#endif
   unsigned int   Dcm_Transmission:1;          /* Flag to signal transmission*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
   uint8   Dcm_Active_Message_Prio;     /* current priority of active request   */
#endif
   uint8   Dcm_Message_Status_Busy;     /* ECU is busy*/
   PduIdType   Dcm_Message_DcmRxPduId;      /* RXPduId   */
   uint8   Dcm_Message_DcmTxPduId;
   uint8   Dcm_TxTableIndex;
   uint8   Dcm_ProtocolTableIndex;
   Dcm_ForcedResponsePendingType Dcm_ForcedRespPend;        /*flag to signal that a forced resp pend was sent so, confirmation should be sent to a special function*/
   Dcm_DataProcessorType Dcm_DataProcessor;
   
   uint16  Dcm_NormalResponseTimer;
   uint16  Dcm_BusyProcessingTimer;
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
   uint16  Dcm_ProtocolPreemptTimer;
#endif
   uint16  Dcm_S3ServerTimer;
   #if DCM_PAGEDBUFFER_ENABLED==STD_ON
     uint16  Dcm_PagedBufferTimer;
   #endif
   uint16  Dcm_SecurityAccessTimer;   
  
     uint8   Dcm_NormalResponseIncrement;
     uint8   Dcm_BusyProcessingIncrement;
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
     uint8   Dcm_ProtocolPreemptIncrement;
#endif
     uint8   Dcm_S3ServerIncrement;
     #if DCM_PAGEDBUFFER_ENABLED==STD_ON
       uint8   Dcm_PagedBufferIncrement;
     #endif
     uint8   Dcm_SecurityAccessIncrement;
     uint8   Dcm_InitialSecurityAccessIncrement;
     
   uint8   Dcm_ActiveSession;   
   uint8   Dcm_ActiveSecurityLevel;
   PduLengthType  Dcm_PagedProcessing_DataLen;       
   uint8   Dcm_NumberRespPend;
}Dcm_Current_Message_Status_Type;

/*! \enum Dcm_StatusType
 *  \brief Definition of Dcm_StatusType\n
 *
 *  These values are used by different DCM functions at the return value. With these values, the DCM functions
 *  signal the success or the failure of one operation.
 *
 *  \var DCM_E_OK                                This value represents a successful operation
 *  \var DCM_E_COMPARE_KEY_FAILED            The comparing of the key needed for SecurityAccess service has failed. 
 *  \var DCM_E_TI_PREPARE_LIMITS             New timing parameter are not in the required limits.
 *  \var DCM_E_TI_PREPARE_INCONSTENT         New timing are not consistent (e.g. P2ServerMin is larger than P2ServerMax)
 *  \var DCM_E_SESSION_NOT_ALLOWED         The new session is not allowed to be started
 *  \var DCM_E_PROTOCOL_NOT_ALLOWED        The new protocol is not allowed
 *  \var DCM_E_ROE_NOT_ACCEPTED            ROE processing is not accepted
 *  \var DCM_E_PERIODICID_NOT_ACCEPTED   PERIODIC processing is not accepted
 *  \var DCM_E_REQUEST_NOT_ACCEPTED        The last request is not accepted 
 *  \var DCM_E_REQUEST_ENV_NOK             Environmental conditions are not correct
 */
typedef enum 
{
 DCM_E_OK,
 DCM_E_COMPARE_KEY_FAILED,
 DCM_E_TI_PREPARE_LIMITS,
 DCM_E_TI_PREPARE_INCONSISTENT,
 DCM_E_SESSION_NOT_ALLOWED,
 /* >> GAN:2008-02-04 Added new value that can be returned from RTE*/
 DCM_E_WAIT_PROCESSING_DONE,
 /* << GAN:2008-02-04 Added new value that can be returned from RTE*/
 DCM_E_PROTOCOL_NOT_ALLOWED,
 DCM_E_ROE_NOT_ACCEPTED,
 DCM_E_PERIODICID_NOT_ACCEPTED,
 DCM_E_REQUEST_NOT_ACCEPTED,
 DCM_E_REQUEST_ENV_NOK
}Dcm_StatusType;

/*! \enum  Dcm_ProtocolType;
 *  \brief  Protocol type definition
 *
 *  This type contains all possible values for the protocol.
 *
 *  \var  0x00  OBD on CAN (ISO15765-4; ISO15031-5)
 *  \var  0x01  UDS on CAN (ISO15765-3; ISO14229-1)
 *  \var  0x02  UDS on FlexRay (Manufacturer specific; ISO14229-1)
 *  
 */


/*reserved part not declared yet */
#define DCM_OBD_CAN 0
#define DCM_UDS_CAN 1
#define DCM_UDS_FLEXRAY 2

typedef uint8 Dcm_ProtocolType;

/*! \struct Dcm_MsgAddInfoType
 *  \brief  Additional information on message request
 *
 *  \param  uint8 reqType ;             physical or functional request
 *  \param  uint8 suppressPosResponse;  1 for suppression of response
 */
typedef struct{
 unsigned int reqType:1;            /* physical or functional request*/
 unsigned int suppressPosResponse:1; /* 1 for suppression*/
}Dcm_MsgAddInfoType;

/*!
* \brief Type for one message item
*/
typedef uint8             Dcm_MsgItemType;

/*!
* \brief Message type
*/
typedef P2VAR(Dcm_MsgItemType,AUTOMATIC,DCM_VAR)  Dcm_MsgType ;

/*!
* \brief Type for the message length
*/
typedef uint16            Dcm_MsgLenType;     

/*!
* \brief Type for the IdContext
*/
typedef uint8             Dcm_IdContextType;

/*! \struct Dcm_MsgContextType
 *  \brief Data structure contains all information to process a diagnostic message
 * 
 *  \param Dcm_MsgType reqData;            this contains information about the received data
 *  \param Dcm_MsgLenType   reqDataLen;      Request data length 
 *  \param Dcm_MsgType resData;            this will contain the response data
 *  \param Dcm_MsgLenType   resDataLen;      Response data length
 *  \param Dcm_MsgAddInfoType   msgAddInfo;  Additional Information
 *  \param Dcm_MsgLenType   resMaxDataLen;   Maximal length of response
 *  \param Dcm_IdContextType idContext;    Message context identifier
 *  \param PduIdType    dcmRxPduId;          Pdu identifier which request was received
 */
typedef struct{
 Dcm_MsgType        reqData;         /* Pointer to requested data*/
 Dcm_MsgLenType     reqDataLen;      /* Request data length*/
 Dcm_MsgType        resData;         /* Pointer to response data*/
 Dcm_MsgLenType     resDataLen;      /* Response data length*/
 Dcm_MsgAddInfoType msgAddInfo;      /* Additional Information*/
 Dcm_MsgLenType     resMaxDataLen;   /* Maximal length of response*/
 Dcm_IdContextType  idContext;       /* Message context identifier*/
 PduIdType          dcmRxPduId;      /* Pdu identifier which request was received*/
}Dcm_MsgContextType;

/*! \enum Dcm_AddrType
 *  \brief  Type for configuration parameter DCM_PROTOCOL_RX_ADDR_TYPE \n
 *
 *  This type shall be used to specify the adressing type of one diagnostic request.          
 *
 *  \var  0 PHYSICAL
 *  \var  1 FUNCTIONAL
 */
typedef enum{
    DCM_PHYSICAL,
    DCM_FUNCTIONAL
}Dcm_AddrType;

/*
*! \enum  Dcm_ConfirmationStatusType
*  \brief Definition of DCM responses on message request
*
*  \var 0x00 - DCM_RES_POS_OK      Positive response OK 
*  \var 0x01 - DCM_RES_POS_NOT_OK    Positive response NOT OK
*  \var 0x02 - DCM_RES_NEG_OK            Negative response OK
*  \var 0x03 - DCM_RES_NEG_NOT_OK    Negative response NOT OK
*
*/
typedef enum 
{
  DCM_RES_POS_OK,
  DCM_RES_POS_NOT_OK,
  DCM_RES_NEG_OK,
  DCM_RES_NEG_NOT_OK 
}Dcm_ConfirmationStatusType;         

/*! \enum Dcm_TimerModeType
 *  \brief  Different types of timing parameters.
 *
 * This type is used for the API Dcm_GetSesTimingValues() to get values of configured default timing parameters, values of current active timing parameters or values of configured timing parameter limits
 *
 *  \var DCM_DEFAULT    Configured Default timing parameters
 *  \var DCM_CURRENT    Current active timing parameters
 *  \var DCM_LIMITS Configured Timing parameters limits
 */
typedef enum {
    DCM_DEFAULT,
    DCM_CURRENT,
    DCM_LIMITS
}Dcm_TimerModeType;


/*!
* \enum Dcm_ObdIdType
* \brief Enum for determining the type of PID (Parameter ID)/OBDMID (On-Board Monitor ID)/TID (Test ID)/INFOTYPE
*        for OBD services
*/
typedef enum {
    DCM_OBD_NO_ID,
    DCM_OBD_DATA_ID,
    DCM_OBD_AVAILABILITY_ID,
    DCM_OBD_INVALID_ID
}Dcm_ObdIdType;

/*! \struct Dcm_TimerServerType
 *  \brief  Data structure contains all timing parameters, valid for a diagnostic protocol.\n
 *          Resolution for all elements is in ms.
 *
 *  \param  Dcm_TimerModeType          ->   DCM_TIMSTR_TYPE
 *  \param  P2CAN_Server min value     ->   DCM_TIMSTR_P2SERVER_MIN
 *  \param  P2CAN_Server max value     ->   DCM_TIMSTR_P2SERVER_MAX
 *  \param  P2*CAN_Server min value    ->   DCM_TIMSTR_P2STARSERVER_MIN
 *  \param  P2*CAN_Server max value    ->   DCM_TIMSTR_P2STARSERVER_MAX
 *  \param  S3Server                   ->   DCM_TIMSTR_S3SERVER
 */
typedef struct
{
  Dcm_TimerModeType DCM_TIMSTR_TYPE;
  uint16            DCM_TIMSTR_P2SERVER_MIN;
  uint16            DCM_TIMSTR_P2SERVER_MAX;
  uint16            DCM_TIMSTR_P2STARSERVER_MIN;
  uint16            DCM_TIMSTR_P2STARSERVER_MAX;
  uint16            DCM_TIMSTR_S3SERVER;
}Dcm_TimerServerType;


/*!
* \brief Function pointer for all diagnostic services
*/
typedef void (*Dcm_DiagnosticServiceType)(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

/*!
* \brief Type for session level value
*/
typedef uint8 Dcm_SesCtrlType;

/*!
* \brief Type for security level value
*/
typedef uint8 Dcm_SecLevelType;

/*!
* \struct Dcm_DiagnosticProtocolTableType
* \brief Type for the configuration table for protocol information
*/
typedef struct
{
   Dcm_ProtocolType DCM_PROTOCOL_ID;
   uint16           DCM_PROTOCOL_PREEMPT_TIMEOUT;
   uint8            DCM_PROTOCOL_IDENTIFIER_TABLE_ID;
   uint8            DCM_PROTOCOL_PRIO;   
}Dcm_DiagnosticProtocolTableType;

/*!
* \struct Dcm_DiagnosticProtocolRxTableType
* \brief Type for the configuration table for RxPduId information
*/
typedef struct
{
   uint8        DCM_PROTOCOL_DCMRXPDUID;
   Dcm_AddrType DCM_PROTOCOL_RX_ADDR_TYPE;
   uint8        DCM_PROTOCOL_RX_BUFFER_ID;
   uint8        DIAGNOSTIC_PROTOCOL_TABLE_ID;
   uint8        DIAGNOSTIC_PROTOCOL_TX_TABLE_ID;
} Dcm_DiagnosticProtocolRxTableType;

/*!
* \struct Dcm_DiagnosticProtocolTxTableType
* \brief Type for the configuration table for TxPduId information
*/
typedef struct
{
 uint8 DCM_PROTOCOL_DCMTXPDUID;
 uint8 DCM_PROTOCOL_TX_BUFFER_ID;
 uint8 DCM_PROTOCOL_DCMRXPDU_INDEX;  
}Dcm_DiagnosticProtocolTxTableType;

/*!
* \struct Dcm_DiagnosticBufferCgfType
* \brief Type for the configuration table for buffers
*/
typedef struct
{
  uint8  DCM_BUFFER_ID;
  PduLengthType DCM_BUFFER_SIZE;
  P2VAR(uint8,AUTOMATIC,DCM_VAR) DCM_BUFFER_ADDRESS;
}Dcm_DiagnosticBufferCgfType;


/*!
* \struct Dcm_ServiceIdentifierTableType
* \brief Type for the configuration table for service identifiers
*/
typedef struct
{
  uint8                     DCM_SIDTAB_ID;
  uint8                     DCM_SIDTAB_SERVICEID;
  Dcm_DiagnosticServiceType DCM_SIDTAB_FUNCTIONPOINTER;
  Dcm_SecLevelType          DCM_SIDTAB_SEC_LEVEL;
  Dcm_SesCtrlType           DCM_SIDTAB_SESSION_LEVEL;
  boolean                                   DCM_SIDTAB_SUBFUNC_AVAIL;  
  Dcm_DataProcessorType     DCM_DATAPROCESSOR;   
}Dcm_ServiceIdentifierTableType;


/*!
* \struct Dcm_SessionLevelTableType
* \brief Type for the configuration table for session level information
*/
typedef struct
{
  Dcm_SesCtrlType DCM_SESSION_LEVEL;  
  uint16          DCM_SESSION_P2STRSERVER_MAX;
  uint16                DCM_SESSION_P2SERVER_MAX;
}Dcm_SessionLevelTableType;

/*!
* \struct Dcm_SecLevelTableType
* \brief Type for the configuration table for security level information
*/
/* ----- NXTR PATCH START -----
 * Added By: K. Smith (Nxtr)
 * Date Added: 28Sep16
 *
 * Reason: Due to the increase in key size, the Dcm needed to be patched to support the new key length. However, that value is
 * 260, which is larger than a uint8. As a result, the data type needed to be patched in order to properly hold the correct
 * value.
 */
#if 0
/* ----- Original Code Start ----- */
typedef struct
{
  Dcm_SecLevelType DCM_SEC_LEVEL;  
  uint8            DCM_SEC_NUM_MAX_ATT_DELAY;
  uint16           DCM_SEC_DELAY_INV_KEY;
  uint8                      DCM_SEC_NUM_MAX_ATT_LOCK;
  uint8                      DCM_SEC_NUM_SEED;
  uint8                      DCM_SEC_NUM_KEY;
}Dcm_SecLevelTableType;
/* ----- Original Code End ----- */
#endif
/* ----- Patch Code Start ----- */
typedef struct
{
  Dcm_SecLevelType DCM_SEC_LEVEL;
  uint8            DCM_SEC_NUM_MAX_ATT_DELAY;
  uint16           DCM_SEC_DELAY_INV_KEY;
  uint8            DCM_SEC_NUM_MAX_ATT_LOCK;
  uint8            DCM_SEC_NUM_SEED;
  uint16           DCM_SEC_NUM_KEY;
}Dcm_SecLevelTableType;
/* ----- Patch Code End ----- */
/* ----- NXTR PATCH END ----- */

/*!
* \struct Dcm_ReadDTCSubFunctionTableType
* \brief Type for the configuration table for sub-functions of the 0x19 service
*/
typedef struct
{
  uint8            DCM_DTC_INFO_SUB_FUNCTION_LEVEL;
  boolean          DCM_DTC_INFO_SUB_FUNCTION_SUPPORT;
  Dcm_SecLevelType DCM_SEC_LEVEL;  
}Dcm_ReadDTCSubFunctionTableType;


/*!
* \struct Dcm_ObdAvailabilityDataType
* \brief Type for availability data of obd services
*/
typedef struct
{
  uint8                     DataA;
  uint8                     DataB;
  uint8                     DataC;
  uint8                     DataD;
}Dcm_ObdAvailabilityDataType;


/*!
* \brief Function pointer for retreiving data of OBD service 0x01
*/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ObdPidServiceType) (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataValueBuffer);

/*!
* \struct Dcm_ObdPidConfigType
* \brief Type for the configuration table for OBD service 0x01
*/
typedef struct
{
  uint8                     PID;
  uint8                     PidSize;
  Dcm_ObdPidServiceType     GetPidFuncPtr;
}Dcm_ObdPidConfigType;

/*!
* \brief Function pointer for retreiving data of OBD service 0x06
*/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ObdDtrServiceType) (
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) TestVal,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) MinLimit,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) MaxLimit,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Status
    );

/*!
* \struct Dcm_ObdObdmidConfigType
* \brief Type for the configuration table for OBD service 0x06
*/
typedef struct
{
    uint8                   OBDMID;
    uint8                   TestId;
    uint8                   UaSId;
    Dcm_ObdDtrServiceType   GetDTRValueFuncPtr;
}Dcm_ObdObdmidConfigType;

/*!
* \brief Function pointer for retreiving data of OBD service 0x08
*/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ObdReqControlServiceType) (
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) OutBuffer,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) InBuffer
    );
/*!
* \struct Dcm_ObdReqControlConfigType
* \brief Type for the configuration table for OBD service 0x08
*/
typedef struct
{
  uint8                        TID;
  uint8                        InBufferSize;
  uint8                        OutBufferSize;
  Dcm_ObdReqControlServiceType ReqControlFuncPtr;
}Dcm_ObdReqControlConfigType;

/*!
* \brief Function pointer for retreiving data of OBD service 0x09
*/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ObdInfoTypeServiceType) (
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataValueBuffer
    );

/*!
* \struct Dcm_ObdVehInfoConfigType
* \brief Type for the configuration table for OBD service 0x09
*/
typedef struct
{
  uint8                        InfoType;
  uint8                        VehInfoSize;
  Dcm_ObdInfoTypeServiceType GetInfoTypeFuncPtr;
}Dcm_ObdVehInfoConfigType;


#undef DCM_AR_EXTERN

#endif   /* #ifndef __DCM_TYPES_H__*/
