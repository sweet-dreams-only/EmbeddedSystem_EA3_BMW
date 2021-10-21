/*
                                                                            
  SRC-MODULE: Dcm.c                                                         
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm module C source file                                      
                                                                            
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
 *          2010.01.18, anam: CR 70453, CR 70490, CR 70492 - Bug-fixing changes 
 * v 2.4.3, 2010.04.07, anam: CR 70598: Negative response cleared with ResponsePending
 * v 2.4.4, 2010.04.23, anam: CR 70621: Dcm.c contains LED debug code 
 * v 2.4.5, 2010.06.30, anam: CR 70620: Notifications via RTE are called in interrupt context
                              CR 70634: S3 timeout handling
                              CR 70641: DCM_START_SEC_VAR_UNSPECIFIED ist used twice without DCM_STOP_SEC_VAR_UNSPECIFIED  
 *                            CR 70658: DCM does not handle Return value of PduR_DcmTransmit() correctly 
 */

#define __DCM_C__

/*
                      Include Section                                       
*/

#include "Dcm.h"
#if (DCM_CONFIGURATION_TYPE==DCM_LINK_TIME)
 #include "Dcm_Lcfg.h"
#endif
#if (DCM_DEV_ERROR_DETECT==STD_ON)
 #include "Det.h"
#endif
#include "Rte_dcm.h" 

/*
                      Local Macros                                          
*/

#define DCM_AR_EXTERN extern

/*
                      Global Data                                           
*/

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
/*!
* \var Dcm_RxTxBuffer
* \brief Buffer used for normal request processing. Size in configurable
*/
VAR(uint8,DCM_VAR) Dcm_RxTxBuffer[DCM_BUFFER_LENGTH];

/*!
* \var Dcm_FuncRxTxBuffer
* \brief Buffer used for functional request processing. Size in configurable
*/
VAR(uint8,DCM_VAR) Dcm_FuncRxTxBuffer[DCM_FUNC_BUFFER_LENGTH];

/*!
* \var Dcm_OBDRxBuffer
* \brief Buffer used for OBD request processing. Size in configurable
*/
VAR(uint8,DCM_VAR) Dcm_OBDRxBuffer[DCM_OBD_BUFFER_LENGTH];

/*!
* \var Dcm_RoeBuffer
* \brief Buffer used for ROE processing
*/
VAR(uint8,DCM_VAR) Dcm_RoeBuffer[DCM_ROE_BUFFER_LENGTH];

/*!
* \var Dcm_PeriodicBuffer
* \brief Buffer used for normal request processing. Size in configurable
*/
#if (DCM_PERIODIC_TRANS_ENABLED==STD_ON)
VAR(uint8,DCM_VAR) Dcm_PeriodicBuffer[DCM_PERIODIC_BUFFER_LENGTH];
#endif

/*!
* \var Dcm_NegResponseBuffer
* \brief Buffer used for negative responses with NRC=0x78 and 0x21
*/
VAR(uint8,DCM_VAR) Dcm_NegResponseBuffer[DCM_NEG_RESPONSE_BUFFER_LENGTH];

/*!
* \var Dcm_Initialized
* \brief Gives the initialization state for DCM
*/
#if (DCM_DEV_ERROR_DETECT==STD_ON)
VAR(uint8,DCM_VAR) Dcm_Initialized=STD_OFF;
#endif

/*!
* \var Dcm_SuppressionOverride
* \brief Information if the suppression shall be overriden
*/
VAR(uint8,DCM_VAR) Dcm_SuppressionOverride=0;

#if (DCM_NUMBER_OF_PROTOCOLS != 1)
/*!
* \var Dcm_PreemptingProtocol
* \brief Variable that stores the value of the preemting protocol
*/
VAR(uint8,DCM_VAR) Dcm_PreemptingProtocol;
#endif

/*!
* \var Dcm_SecurityTimeOutNr
* \brief Variable that holds the index of the new security level. Needed for special processing of DCM
*/
VAR(uint8,DCM_VAR) Dcm_SecurityTimeOutNr;

/*!
* \var Dcm_FirstRequest
* \brief This variable shall inform if the request received is the first one of the default session or not
*/
VAR(uint8,DCM_VAR) Dcm_FirstRequest;

/*!
* \var Dcm_TempNegResponse
* \brief This variable shall be used in the special case when the response(pos or neg) comes very fast after the RCRRP
*/
VAR(uint8,DCM_VAR) Dcm_TempNegResponse;

/*!
* \var Dcm_PeriodicIdTransmission
* \brief This variable shall be true if a ReadDataByIdentifier service is executed from a 
         ReadDataByPeriodicId context.
*/
#if (DCM_PERIODIC_TRANS_ENABLED==STD_ON)
VAR(boolean,DCM_VAR) Dcm_PeriodicIdTransmission;
#endif

#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*!
* \var Dcm_DiagnosticBufferCfg
* \brief Variable that maps the configuration table for buffers
*/
CONST(Dcm_DiagnosticBufferCgfType,DCM_CONST) Dcm_DiagnosticBufferCfg[DCM_NUMBER_OF_BUFFER_ID]= DIAGNOSTIC_BUFFER_CFG;
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*!
* \var Dcm_NegResponse
* \brief This variable shall inform if the Dcm_SetNegResponse function was called (next message is negative response)
*/
VAR(Dcm_ResponseMessageType,DCM_VAR) Dcm_NegResponse;

/*!
* \var Dcm_WaitForConfirmation
* \brief This variable shall store information about the status of the confirmation. Needed for ResponsePending and FlexRay
*/
VAR(Dcm_WaitForConfirmationStatusType,DCM_VAR) Dcm_WaitForConfirmation;

/*!
* \var Dcm_NegResponseBeforeRespPending
* \brief Variable to store Dcm_NegResponse when response pending is sent
*/
VAR(Dcm_ResponseMessageType,DCM_VAR) Dcm_NegResponseBeforeRespPending;

/*!
* \var Dcm_Current_Message_Status
* \brief Variable that holds relevant values for the currently processed request
*/
VAR(Dcm_Current_Message_Status_Type,DCM_VAR) Dcm_Current_Message_Status;

/*!
* \var Dcm_CurrentTimingParameter
* \brief Variable that stores the current values (in ms) of the timers
*/
VAR(Dcm_TimerServerType,DCM_VAR) Dcm_CurrentTimingParameter;

VAR(PduInfoType,DCM_VAR) Dcm_PduMessage;

/*!
* \var Dcm_ptrPduMessageType
* \brief This variable shall be given to the lower layer in the Dcm_ProvideTxBuffer function
*/
P2VAR(PduInfoType,AUTOMATIC,DCM_VAR) Dcm_ptrPduMessageType=&Dcm_PduMessage;

VAR(PduInfoType,DCM_VAR) Dcm_FuncPduMessage;

/*!
* \var Dcm_ptrFuncPduMessageType
* \brief This variable shall be given to the lower layer in the Dcm_ProvideTxBuffer function
*/
P2VAR(PduInfoType,AUTOMATIC,DCM_VAR) Dcm_ptrFuncPduMessageType=&Dcm_FuncPduMessage;

VAR(Dcm_MsgContextType,DCM_VAR)  Dcm_MsgContext;

/*!
* \var Dcm_pMsgContext2
* \brief Variable used to forward the requests to the data processor
*/
P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) Dcm_pMsgContext2 = &Dcm_MsgContext;

/*!
* \var Dcm_CommunicationState
* \brief Buffer used for negative responses with NRC=0x78 and 0x21
*/
VAR(Dcm_CommunicationStateType,DCM_VAR) Dcm_CommunicationState =  DCM_NO_COMMUNICATION;

/*!
* \var Dcm_PreemptedPdu
* \brief Variable that stores the value of the RxPduId of the preempted protocol
*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
VAR(PduIdType,DCM_VAR) Dcm_PreemptedPdu;
#endif

/*!
* \var Dcm_SessionChange
* \brief Variable that holds the index of the new session level. Needed for special processing of DCM
*/
VAR(Dcm_SesCtrlType,DCM_VAR) Dcm_SessionChange;

/*!
* \var Dcm_NewTimings
* \brief Variable shall store the 
*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
VAR(Dcm_TimerServerType,DCM_VAR) Dcm_NewTimings;
#endif

/*!
* \var Dcm_NewTimingValues
* \brief Variable that holds the index of the new timing values. Needed for special processing of DCM.
*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
P2VAR(Dcm_TimerServerType,AUTOMATIC,DCM_VAR) Dcm_NewTimingValues=&Dcm_NewTimings;
#endif


/*!
* \var Dcm_RteService
* \brief Variable shall store the function pointer to the Rte service to be executed
*/
VAR(Dcm_DiagnosticServiceType, DCM_VAR) Dcm_RteService;

/*!
* \var Dcm_pRteMsgContext 
* \brief this variable is used to store the message information for the Rte service to be executed in separate task
*/
P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) Dcm_pRteMsgContext;

 #if DCM_PAGEDBUFFER_ENABLED==STD_ON
  /*! used for pagedbuffer processing to signal which function must still process*/
  DCM_AR_EXTERN VAR(Dcm_DiagnosticServiceType, DCM_VAR) Dcm_PagedBufferService;
 #endif

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if (DCM_CONFIGURATION_TYPE==DCM_PRE_COMPILE)

 #define DCM_START_SEC_CONST_UNSPECIFIED
 #include "MemMap.h"
 /*!
 * \var Dcm_ServiceIdTable
 * \brief Variable that maps the configuration table for service identifiers
 */
 CONST(Dcm_ServiceIdentifierTableType,DCM_CONST) Dcm_ServiceIdTable[DCM_NUMBER_OF_SERVICE_ID]=SERVICE_IDENTIFIER_TABLE;
 
 /*!
 * \var Dcm_SessionLevel
 * \brief Variable that maps the configuration table for session level information
 */
 CONST(Dcm_SessionLevelTableType,DCM_CONST) Dcm_SessionLevel[DCM_NUMBER_OF_SESSION_LEVELS]=DCM_SESSION_LEVEL_TABLE;
 /*!
 * \var Dcm_SecLevel
 * \brief Variable that maps the configuration table for security level information. 
 */
 CONST(Dcm_SecLevelTableType,DCM_CONST) Dcm_SecLevel[DCM_NUMBER_OF_SECURITY_LEVELS]=DCM_SEC_LEVEL_TABLE; 
 /*!
 * \var Dcm_SubFunctions0x19
 * \brief Variable that maps the configuration table for sub-functions of service 0x19
 */
 #if DCM_USE_DEM==STD_ON
 CONST(Dcm_ReadDTCSubFunctionTableType,DCM_CONST) Dcm_SubFunctions0x19[DCM_NUMBER_OF_SUBFUNCTIONS_0x19]=DCM_READDTC_SUB_FUNCTION_TABLE;
 #endif
 
 /*!
 * \var Dcm_ProtocolDefaultTiming
 * \brief Variable that maps the configuration table for default timing parameters
 */
 CONST(Dcm_TimerServerType,DCM_CONST) Dcm_ProtocolDefaultTiming[DCM_NUMBER_OF_PROTOCOLS]=PROTOCOL_DEFAULTTIMING_STRUCTURE;

 /*!
 * \var Dcm_ProtocolLimitsTiming
 * \brief Variable that maps the configuration table for limits timing parameters
 */
 #if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
 CONST(Dcm_TimerServerType,DCM_CONST) Dcm_ProtocolLimitsTiming[DCM_NUMBER_OF_PROTOCOLS]=PROTOCOL_LIMITSTIMING_STRUCTURE;
 #endif
 
 /*!
 * \var Dcm_ProtocolRxTable
 * \brief Variable that maps the configuration table for RxPduId
 */
 CONST(Dcm_DiagnosticProtocolRxTableType,DCM_CONST) Dcm_ProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID]=DIAGNOSTIC_PROTOCOL_RX_TABLE;

 /*!
 * \var Dcm_ProtocolTxTable
 * \brief Variable that maps the configuration table for TxPduId
 */
 CONST(Dcm_DiagnosticProtocolTxTableType,DCM_CONST) Dcm_ProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID]=DIAGNOSTIC_PROTOCOL_TX_TABLE;

 /*!
 * \var Dcm_ProtocolTable
 * \brief Variable that maps the configuration table for protocols
 */
 CONST(Dcm_DiagnosticProtocolTableType,DCM_CONST) Dcm_ProtocolTable[DCM_NUMBER_OF_PROTOCOLS]=DIAGNOSTIC_PROTOCOL_TABLE;
 #define DCM_STOP_SEC_CONST_UNSPECIFIED
 #include "MemMap.h"
#endif

#if (DCM_CONFIGURATION_TYPE==DCM_LINK_TIME)

 #define DCM_START_SEC_VAR_UNSPECIFIED
 #include "MemMap.h"
 /*!
 * \var Dcm_ServiceIdTable
 * \brief Variable that maps the configuration table for service identifiers
 */
 VAR(Dcm_ServiceIdentifierTableType,DCM_VAR) Dcm_ServiceIdTable[DCM_NUMBER_OF_SERVICE_ID]; 
 /*!
 * \var Dcm_SessionLevel
 * \brief Variable that maps the configuration table for session level information
 */
 VAR(Dcm_SessionLevelTableType,DCM_VAR) Dcm_SessionLevel[DCM_NUMBER_OF_SESSION_LEVELS];
 /*!
 * \var Dcm_SecLevel
 * \brief Variable that maps the configuration table for security level information. 
 */
 VAR(Dcm_SecLevelTableType,DCM_VAR) Dcm_SecLevel[DCM_NUMBER_OF_SECURITY_LEVELS];
 /*!
 * \var Dcm_SubFunctions0x19
 * \brief Variable that maps the configuration table for sub-functions of service 0x19
 */
 #if DCM_USE_DEM==STD_ON
 VAR(Dcm_ReadDTCSubFunctionTableType,DCM_VAR) Dcm_SubFunctions0x19[DCM_NUMBER_OF_SUBFUNCTIONS_0x19];
 #endif
 /*!
 * \var Dcm_ProtocolDefaultTiming
 * \brief Variable that maps the configuration table for default timing parameters
 */
 VAR(Dcm_TimerServerType,DCM_VAR) Dcm_ProtocolDefaultTiming[DCM_NUMBER_OF_PROTOCOLS];

 /*!
 * \var Dcm_ProtocolLimitsTiming
 * \brief Variable that maps the configuration table for limits timing parameters
 */
 #if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
 VAR(Dcm_TimerServerType,DCM_VAR) Dcm_ProtocolLimitsTiming[DCM_NUMBER_OF_PROTOCOLS];
 #endif
 /*!
 * \var Dcm_ProtocolRxTable
 * \brief Variable that maps the configuration table for RxPduId
 */
 VAR(Dcm_DiagnosticProtocolRxTableType,DCM_VAR) Dcm_ProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID];

 /*!
 * \var Dcm_ProtocolTxTable
 * \brief Variable that maps the configuration table for TxPduId
 */
 VAR(Dcm_DiagnosticProtocolTxTableType,DCM_VAR) Dcm_ProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID];

 /*!
 * \var Dcm_ProtocolTable
 * \brief Variable that maps the configuration table for protocols
 */
 VAR(Dcm_DiagnosticProtocolTableType,DCM_VAR) Dcm_ProtocolTable[DCM_NUMBER_OF_PROTOCOLS];
 #define DCM_STOP_SEC_VAR_UNSPECIFIED
 #include "MemMap.h"
#endif

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
  DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_PagedBufferFlag;
  
  DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_PageProcessed;
#endif
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/*
                      Local Data                                            
*/

#define DCM_START_SEC_VAR_FAST_8BIT
#include "MemMap.h"
/*!
* \var Dcm_DcmReentrancy
* \brief Variable used bitwise to control re-entrancy of Dcm functions
*/
#if DCM_DEV_ERROR_DETECT==STD_ON
VAR(uint8,DCM_VAR) Dcm_DcmReentrancy;
#endif
#define DCM_STOP_SEC_VAR_FAST_8BIT
#include "MemMap.h"

/*
                      Local Function Prototypes                             
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
  static FUNC(void,DCM_CODE) Dcm_Transmission(void);
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
                      Local Functions                                       
*/

/*
*! Function that deals with all timers processed by DCM
*
* \name Dcm_Transmission
*
* \b Service-Id:   0x26
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function is used to start the actual transmission to PduR. It will call the 
* PduR_DcmTransmit function and depending on the response it will set timer values and clear certain flags.
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_Transmission(void)
{
  if (DCM_NO_CONFIRMATION_WAIT == Dcm_WaitForConfirmation)
  {  
      Std_ReturnType retval;
      Dcm_Current_Message_Status.Dcm_Transmission=0;
      /*Also make the busy timer increment 0 and start it again at TxConfirmation*/
      Dcm_ResetNormalAndBusyTimers();
      retval = PduR_DcmTransmit(Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId,Dcm_ptrPduMessageType);
      /* >><< GAN:2008-08-19 Changed condition*/
      if (  (Dcm_NegResponse==DCM_RESPONSE_PENDING_OR_BUSY)
         &&(Dcm_NegResponseBuffer[2]==DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING))
      {       
        /*no action taken....negative response to be sent with 0x78 (RCR-RP)....other timeout must be detected        */
        Dcm_WaitForConfirmation = DCM_WAIT_FOR_CONFIRMATION; /*wait for the confirmation of this message*/
      }
      else
      {  
        /*positive response sent...stop timers*/
        /*also make the RespPend stop counting as a message was sent*/
        Dcm_Current_Message_Status.Dcm_NumberRespPend=0;
      }  
      if (retval != E_OK)
    {
         /*sending was not possible             */
         Dcm_TxConfirmation(Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId, NTFRSLT_E_NOT_OK);
    } 
  }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
                      Global Functions                                      
*/


/*
*! Initialization function of the DCM Module
*
* \name Dcm_Init
*
* \b Service-Id:   0x01
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function will initialize the DCM Module (configurations, buffers, local variables)
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_Init(void)
{
 #if DCM_DEV_ERROR_DETECT==STD_ON   
 if ((Dcm_DcmReentrancy & 0x01)==0x00)
 {    
  Dcm_DcmReentrancy|=0x01;/*set as entry  */
  #endif
  #if (DCM_CONFIGURATION_TYPE==DCM_LINK_TIME)
  {    
    uint8 i;
    uint8 j;
           
    for (i=0;i<DCM_NUMBER_OF_SERVICE_ID;i++)
      Dcm_ServiceIdTable[i]=Dcm_LinkTimeServiceTable[i];   
      
    for (i=0;i<DCM_NUMBER_OF_SECURITY_LEVELS;i++)
      Dcm_SecLevel[i]=Dcm_LinkTimeSecurityLevel[i];  
      
    for (i=0;i<DCM_NUMBER_OF_SESSION_LEVELS;i++)
      Dcm_SessionLevel[i]=Dcm_LinkTimeSessionLevel[i];  
      
    #if DCM_USE_DEM==STD_ON
    for (i=0;i<DCM_NUMBER_OF_SUBFUNCTIONS_0x19;i++)
      Dcm_SubFunctions0x19[i]=Dcm_LinkTimeSubFunctions0x19[i]; 
    #endif
      
    for (i=0;i<DCM_NUMBER_OF_PROTOCOLS;i++)
    {
      Dcm_ProtocolDefaultTiming[i]=Dcm_LinkTimeDefaultTimingParameters[i];
      Dcm_ProtocolTable[i]=Dcm_LinkTimeProtocolTable[i];
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
      Dcm_ProtocolLimitsTiming[i]=Dcm_LinkTimeLimitsTimingParameters[i];
#endif
    }
    
    for (i=0;i<DCM_NUMBER_OF_DCMRXPDUID;i++)
    {
      Dcm_ProtocolRxTable[i]=Dcm_LinkTimeProtocolRxTable[i];
    }
    
    for (i=0;i<DCM_NUMBER_OF_DCMTXPDUID;i++)
    {
      Dcm_ProtocolTxTable[i]=Dcm_LinkTimeProtocolTxTable[i];
    }
  }
  #endif    
  /*security is locked*/
  Dcm_Current_Message_Status.Dcm_ActiveSecurityLevel = 0x00;
  /*default session*/
  Dcm_Current_Message_Status.Dcm_ActiveSession   = DEFAULT_SESSION;    
  /*no protocol has been started*/
  Dcm_Current_Message_Status.Dcm_StartProtocolStatus=0;
  /*no buffer is used*/
  Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;
  /*no priority is yet active  */
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
  Dcm_Current_Message_Status.Dcm_Active_Message_Prio=0xFF;
  /*necessary variable initialization for correct processing*/
  Dcm_PreemptedPdu=0xFF;  
#endif
  Dcm_SessionChange=0xFF;  
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
  Dcm_NewTimingValues=0;
#endif
#if (DCM_PERIODIC_TRANS_ENABLED==STD_ON)
  Dcm_PeriodicIdTransmission=FALSE;
#endif
  Dcm_pRteMsgContext=0;
  Dcm_RteService=0;
  Dcm_FirstRequest=0;
  #if DCM_PAGEDBUFFER_ENABLED==STD_ON
    Dcm_PagedBufferFlag=0;
  #endif
  /*the WaitForConfirmation has to be set to 0 here*/
  Dcm_WaitForConfirmation=DCM_NO_CONFIRMATION_WAIT;

  /* default timing are loaded in the current timing parameter structure*/
  Dcm_CurrentTimingParameter=Dcm_ProtocolDefaultTiming[0]; 

  /*each increment shall be 0 or DCM_TASK_TIME
    if 0, it means that the timer is not active
    if DCM_TASK_TIME, it means the timer is active and a timeout can happen
    each increment shall be set to DCM_TASK_TIME when it has to be started    */
  Dcm_ResetNormalAndBusyTimers();
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
  Dcm_Current_Message_Status.Dcm_PagedBufferTimer=0;
  Dcm_Current_Message_Status.Dcm_PagedBufferIncrement=0;
#endif
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
  Dcm_Current_Message_Status.Dcm_ProtocolPreemptTimer=0;
  Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement=0;
#endif
  Dcm_Current_Message_Status.Dcm_S3ServerTimer=0;
  Dcm_Current_Message_Status.Dcm_S3ServerIncrement=0;
  Dcm_Current_Message_Status.Dcm_SecurityAccessTimer=0;
  Dcm_Current_Message_Status.Dcm_SecurityAccessIncrement=0;
  /* >> GAN:2007-09-05 initial security access timer increment - started from beginning */
  if (DCM_SEC_ACCESS_DELAY!=0)
    Dcm_Current_Message_Status.Dcm_InitialSecurityAccessIncrement=DCM_TASK_TIME; 
  /* << GAN:2007-09-05 initial security access timer increment - started from beginning */
  
  /* >> GAN:2007-09-05 count of negative response pending shall be set to 0 */
  Dcm_Current_Message_Status.Dcm_NumberRespPend=0;
  /* << GAN:2007-09-05 count of negative response pending shall be set to 0*/
  /* >> anam:2010-04-07 CR 70598 */
  Dcm_NegResponseBeforeRespPending = DCM_NO_NEG_RESPONSE;
  /* << anam:2010-04-07 CR 70598 */
  /*the communication state is no communication*/
  Dcm_CommunicationState=DCM_NO_COMMUNICATION;    

#if (DCM_DEV_ERROR_DETECT==STD_ON)
  Dcm_Initialized=STD_ON;
#endif
  
 #if DCM_DEV_ERROR_DETECT==STD_ON
  Dcm_DcmReentrancy&=0xFE;
 } /* from the if with re-entrancy */
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function that returns the version information of the DCM Module
*
* \name Dcm_GetVersionInfo
*
* \b Service-Id:   0x24
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Std_VersionInfoType* versioninfo
*
* \return          none
*
* \b Description:  This function is used to obtain the version information for this DCM Module. Information\n
* about 
*
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
#if (DCM_VERSION_INFO_API==STD_ON)
FUNC(void,DCM_CODE) Dcm_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,DCM_APPL_DATA) versioninfo)
{
  #if DCM_DEV_ERROR_DETECT==STD_ON
  if ((Dcm_DcmReentrancy&0x02)==0x00)
  {
   Dcm_DcmReentrancy|=0x02;/*set as entry      */
  #endif 
   /*version info is completed with the required information*/
     versioninfo->moduleID=DCM_MODULE_ID;
     versioninfo->vendorID=DCM_VENDOR_ID;
     versioninfo->sw_major_version=DCM_SW_MAJOR_VERSION;
     versioninfo->sw_minor_version=DCM_SW_MINOR_VERSION;
     versioninfo->sw_patch_version=DCM_SW_PATCH_VERSION;
  #if DCM_DEV_ERROR_DETECT==STD_ON
     Dcm_DcmReentrancy&=0xFD;/*clear*/
  } /*from the reentrancy*/
  #endif
}
#endif
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function that deals with all timers processed by DCM
*
* \name Dcm_MainFunction
*
* \b Service-Id:   0x25
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function shall be executed cyclicly at intervals defined in configuration (parameter
* DCM_TASK_TIME).
*
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_MainFunction(void)
{
 #if (DCM_DEV_ERROR_DETECT==STD_ON)
 if ((Dcm_DcmReentrancy&0x04)==0x00)
 {
  Dcm_DcmReentrancy|=0x04;/*set as entry*/
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x25,DCM_E_UNINIT);
      Dcm_DcmReentrancy&=0xFB;/*clear    */
      return;
    }
  #endif    
    Dcm_Current_Message_Status.Dcm_NormalResponseTimer +=Dcm_Current_Message_Status.Dcm_NormalResponseIncrement;
    
    Dcm_Current_Message_Status.Dcm_BusyProcessingTimer +=Dcm_Current_Message_Status.Dcm_BusyProcessingIncrement;

#if (DCM_NUMBER_OF_PROTOCOLS != 1)
    Dcm_Current_Message_Status.Dcm_ProtocolPreemptTimer +=Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement;
#endif
    
    if(Dcm_Current_Message_Status.Dcm_Message_Status_Busy==0) 
        Dcm_Current_Message_Status.Dcm_S3ServerTimer +=Dcm_Current_Message_Status.Dcm_S3ServerIncrement;
    
    #if DCM_PAGEDBUFFER_ENABLED==STD_ON
      Dcm_Current_Message_Status.Dcm_PagedBufferTimer +=Dcm_Current_Message_Status.Dcm_PagedBufferIncrement;
    #endif

  if (Dcm_WaitForConfirmation == DCM_CONFIRAMTION_ARRIVED)
  {
    Dcm_WaitForConfirmation = DCM_NO_CONFIRMATION_WAIT;
    /*to force the transmission of the response*/
    Dcm_Current_Message_Status.Dcm_NormalResponseTimer=Dcm_CurrentTimingParameter.DCM_TIMSTR_P2SERVER_MIN; 
  }
    
    /* >> GAN:2007-09-05 depending on the increment, increase the security access time*/
    /*both increments cannot be different from zero at one time*/
    Dcm_Current_Message_Status.Dcm_SecurityAccessTimer +=Dcm_Current_Message_Status.Dcm_SecurityAccessIncrement;
    Dcm_Current_Message_Status.Dcm_SecurityAccessTimer +=Dcm_Current_Message_Status.Dcm_InitialSecurityAccessIncrement;
    /* << GAN:2007-09-05 depending on the increment, increase the security access time  */
    
    if ((Dcm_Current_Message_Status.Dcm_Transmission==DCM_READY_TO_SEND)&&\
        ((Dcm_Current_Message_Status.Dcm_NormalResponseTimer>=Dcm_CurrentTimingParameter.DCM_TIMSTR_P2SERVER_MIN)||\
        (Dcm_Current_Message_Status.Dcm_BusyProcessingTimer>=Dcm_CurrentTimingParameter.DCM_TIMSTR_P2STARSERVER_MIN))) 
    {      
      Dcm_Transmission();     
    }
    
    /*check if normal response timer is elapsed*/
    if ((Dcm_Current_Message_Status.Dcm_NormalResponseTimer 
         >(Dcm_CurrentTimingParameter.DCM_TIMSTR_P2SERVER_MAX - DCM_P2SERVER_ADJUST))
        ||(Dcm_Current_Message_Status.Dcm_BusyProcessingTimer 
          >(Dcm_CurrentTimingParameter.DCM_TIMSTR_P2STARSERVER_MAX - DCM_P2STARSERVER_ADJUST)))
    {
       
      /* >> GAN:2007-09-05 check if another RespPend is allowed*/
      if (Dcm_Current_Message_Status.Dcm_NumberRespPend < DCM_NUM_MAX_RESPPEND) 
      {     
        /*negative response with RCRRP*/
        /* >> GAN:2008-03-06 added check */
        if (Dcm_Current_Message_Status.Dcm_Transmission != DCM_READY_TO_SEND)
        {
           /*if a forced response pending has been requested by the application
             do not request it again here*/
           if(DCM_FORCED_RESPONSE_PENDING != Dcm_Current_Message_Status.Dcm_ForcedRespPend)
           {
           
              /* >> anam:2010-04-07 CR 70598 */
              /* store Dcm_NegResponse so it is not overwritten */
              if( DCM_NO_NEG_RESPONSE == Dcm_NegResponseBeforeRespPending)
              {
                Dcm_NegResponseBeforeRespPending = Dcm_NegResponse;
              }
              /* << anam:2010-04-07 CR 70598 */
              Dcm_SetNegResponse(Dcm_pMsgContext2, DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING);      
              if (Dcm_NegResponse ==DCM_RESPONSE_PENDING_OR_BUSY)
              {
                Dcm_ProcessingDone(Dcm_pMsgContext2);
                
                /*indicate that a normal (not forced) response pending is requested*/
                Dcm_Current_Message_Status.Dcm_ForcedRespPend=DCM_NORMAL_RESPONSE_PENDING;
                
                /* >> GAN:2007-09-05 count the response pending*/
                Dcm_Current_Message_Status.Dcm_NumberRespPend++;
                /* << GAN:2007-09-05 count the response pending
                   >> GAN:2007-16-10 response pending called, no suppression available*/
                if (Dcm_pMsgContext2->msgAddInfo.suppressPosResponse==1)
                  Dcm_SuppressionOverride=1;
                /* << GAN:2007-16-10 response pending called, no suppression available*/
              }
           }
        }
      }
      else 
      {
        /*here a general reject should be sent*/
        Dcm_HandleNegResponse(Dcm_pMsgContext2, DCM_E_GENERALREJECT);
      }
      
      /*here actually do the transmission */
      if (Dcm_Current_Message_Status.Dcm_Transmission==DCM_READY_TO_SEND)
        Dcm_Transmission();
      /* << GAN:2007-09-05 check if another RespPend is allowed*/
     #if DCM_DEV_ERROR_DETECT==STD_ON
      Dcm_DcmReentrancy&=0xFB;/*clear*/
     #endif
      return;
    }
    
    /*only if the increment is different than 0 this timer shall be checked*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
    if (Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement!=0)
    {            
     /*check if the protocol preemption timer has been elapsed*/
     if (Dcm_Current_Message_Status.Dcm_ProtocolPreemptTimer > Dcm_ProtocolTable[Dcm_PreemptingProtocol].DCM_PROTOCOL_PREEMPT_TIMEOUT)
     { 
       Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement=0;
       Dcm_Current_Message_Status.Dcm_ProtocolPreemptTimer=0;
           
       /*free some resurces so that the repeated request can be processed      */
       Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0; /*un-busy the buffer       */
       Dcm_PreemptedPdu=0xFF;
     }
    }
#endif
    
    /*if this parameter is set, the busy repeat request processing shall be done*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
    if (Dcm_Current_Message_Status.Dcm_Busy_Repeat_Request==DCM_BUSYREPEATREQUEST)
    {
       Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_BUSYREPEATREQUEST);
      
      /*clear this flag, this shall be set if this situation occurs again*/
      Dcm_Current_Message_Status.Dcm_Busy_Repeat_Request=0;
      #if DCM_DEV_ERROR_DETECT==STD_ON
      Dcm_DcmReentrancy&=0xFB;/*clear*/
      #endif
      return;
    }
#endif
    /*S3Server timeout handling*/
    if (Dcm_Current_Message_Status.Dcm_S3ServerTimer > Dcm_CurrentTimingParameter.DCM_TIMSTR_S3SERVER)
    { 
       Dcm_SetSesCtrlType(0x01);
    }
    
    /*if the paged buffeer processing in enabled*/
    #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
     /*check if the timer has elapsed*/
    /* >> GAN:2008-02-05 Change suggested by BMW*/
    /* >><< GAN:2009-09-10 changed condition from == 2 to > 2 so that cancellation can happen also in DSP processed services*/
    if ((Dcm_PageProcessed >= 2)&&(Dcm_Current_Message_Status.Dcm_PagedBufferTimer > DCM_PAGEDBUFFER_TIMEOUT))
    {
    /* << GAN:2008-02-05 Change suggested by BMW*/
       /*call cancellation function in the data processor*/
       if (Dcm_Current_Message_Status.Dcm_DataProcessor==DCM_DSP)
       {
         Dsp_DcmCancelPagedBufferProcessing();
       }
       if (Dcm_Current_Message_Status.Dcm_DataProcessor==DCM_RTE)
       {
         Rte_DcmCancelPagedBufferProcessing();
         Dcm_PagedBufferFlag=2;
       }
     
     /*stop the timer...processing shall be stopped with the cancellation function     */
       Dcm_Current_Message_Status.Dcm_PagedBufferTimer=0;
       Dcm_Current_Message_Status.Dcm_PagedBufferIncrement=0;          
    }
    #endif
    
    /*this is the security access timer */
    if (Dcm_Current_Message_Status.Dcm_SecurityAccessIncrement !=0)
    {     
      /*if the timer has elapsed clear the timer increment and reset the timer
        while this timer is running, no security access is allowed*/
      if (Dcm_Current_Message_Status.Dcm_SecurityAccessTimer > Dcm_SecLevel[Dcm_SecurityTimeOutNr].DCM_SEC_DELAY_INV_KEY)
      {
        /*stop the timer*/
        Dcm_Current_Message_Status.Dcm_SecurityAccessIncrement=0;
        Dcm_Current_Message_Status.Dcm_SecurityAccessTimer=0;
      }
    }
    if (Dcm_Current_Message_Status.Dcm_InitialSecurityAccessIncrement != 0)
    {
      if (Dcm_Current_Message_Status.Dcm_SecurityAccessTimer > DCM_SEC_ACCESS_DELAY)
      {     
      /*stop the timer*/
        Dcm_Current_Message_Status.Dcm_InitialSecurityAccessIncrement=0;
        Dcm_Current_Message_Status.Dcm_SecurityAccessTimer=0;       
      }
    }
 #if DCM_DEV_ERROR_DETECT==STD_ON
    Dcm_DcmReentrancy&=0xFB;/*clear*/
 }/*from the reentrancy*/
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used only for RTE service processing
*
* \name Dcm_RteMainFunction
*
* \b Service-Id:   0x70
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  Function is used to call the RTE services. This is because RTE must be called asynchronously
* and they should not block the DCM.
*
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_RteMainFunction(void)
{
 VAR(Dcm_DiagnosticServiceType, DCM_VAR) protectedFuncPtr = NULL_PTR;
 #if (DCM_DEV_ERROR_DETECT==STD_ON)  
 if ((Dcm_DcmReentrancy&0x10)==0x00)
 {
    Dcm_DcmReentrancy|=0x10;/*set as entry*/
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x25,DCM_E_UNINIT);
      Dcm_DcmReentrancy&=0xEF;/*clear    */
      return;
    }
  #endif
  /*check if the flag is set and process the RTE service*/
  /*>>GAN:2009-09-23 disable and re-enable the interrupts when reading the Dcm_RteService*/
  SchM_Enter_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
  if (Dcm_RteService)
  {
    protectedFuncPtr = Dcm_RteService;
    Dcm_RteService=0;    
    SchM_Exit_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
    protectedFuncPtr(Dcm_pRteMsgContext);    
  }
  else
  {
    SchM_Exit_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
  }
  /*<<GAN:2009-09-23 disable and re-enable the interrupts when readin the Dcm_RteService*/
  /*the new page is given   */
  #if DCM_PAGEDBUFFER_ENABLED==STD_ON
  if (Dcm_PageProcessed==3)
  {
      if (Dcm_PagedBufferService)
      {
        Dcm_PageProcessed=2;
         
        Dcm_PagedBufferService(Dcm_pMsgContext2);
      }
  }
  #endif
 #if DCM_DEV_ERROR_DETECT==STD_ON
 Dcm_DcmReentrancy&=0xEF;/*clear*/
 }/*from the reentrancy*/
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#undef DCM_AR_EXTERN

#undef __DCM_C__
