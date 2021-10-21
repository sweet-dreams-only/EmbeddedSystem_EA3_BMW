/*
                                                                            
  SRC-MODULE: Dsd.c                                                         
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm module - DSD Part C source file                           
                                                                            
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
 *          2010.01.18, anam: CR 70489 - Bug-fixing changes 
 * v 2.4.3, 2010.07.04, anam: CR 70598: Negative response cleared with ResponsePending
 *                            CR 70614: Wrong status in Rte_DcmConfirmation()  
 * v 2.4.4, 2010.20.04, anam: CR 70609: Dcm_SuppressionOverride not cleared 
 * v 2.5.0, 2010.22.11, anam: CR 70887: Dcm_SuppressionOverride not cleared 
 */

#define __DSD_C__

/*
                      Include Section                                       
*/

#include "Dcm.h"
#include "Dcm_Cbk.h"
#if (DCM_DEV_ERROR_DETECT==STD_ON)
 #include "Det.h"
#endif 
#include "Rte_dcm.h"

/*
                      Local Macros                                          
*/

#ifdef __DCM_C__
#define DCM_AR_EXTERN 
#else
#define DCM_AR_EXTERN extern
#endif

/*
                      Global Data                                           
*/
#if DCM_CONFIGURATION_TYPE==DCM_PRE_COMPILE

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolTableType,DCM_CONST) Dcm_ProtocolTable[DCM_NUMBER_OF_PROTOCOLS];

DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolTxTableType,DCM_CONST) Dcm_ProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID];

DCM_AR_EXTERN CONST(Dcm_SessionLevelTableType,DCM_CONST) Dcm_SessionLevel[DCM_NUMBER_OF_SESSION_LEVELS];

DCM_AR_EXTERN CONST(Dcm_SecLevelTableType,DCM_CONST) Dcm_SecLevel[DCM_NUMBER_OF_SECURITY_LEVELS];

DCM_AR_EXTERN CONST(Dcm_ServiceIdentifierTableType,DCM_CONST) Dcm_ServiceIdTable[DCM_NUMBER_OF_SERVICE_ID];

DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolRxTableType,DCM_CONST) Dcm_ProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#else

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolTableType,DCM_VAR) Dcm_ProtocolTable[DCM_NUMBER_OF_PROTOCOLS];

DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolTxTableType,DCM_VAR) Dcm_ProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID];

DCM_AR_EXTERN VAR(Dcm_SessionLevelTableType,DCM_VAR) Dcm_SessionLevel[DCM_NUMBER_OF_SESSION_LEVELS];

DCM_AR_EXTERN VAR(Dcm_SecLevelTableType,DCM_VAR) Dcm_SecLevel[DCM_NUMBER_OF_SECURITY_LEVELS];

DCM_AR_EXTERN VAR(Dcm_ServiceIdentifierTableType,DCM_VAR) Dcm_ServiceIdTable[DCM_NUMBER_OF_SERVICE_ID];

DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolRxTableType,DCM_VAR) Dcm_ProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID];
#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif


#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"

#if (DCM_DEV_ERROR_DETECT==STD_ON)
DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_Initialized;
#endif

DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_TempNegResponse;

DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_SuppressionOverride;   

DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_NegResponseBuffer[DCM_NEG_RESPONSE_BUFFER_LENGTH];

#if (DCM_PERIODIC_TRANS_ENABLED==STD_ON)
DCM_AR_EXTERN VAR(boolean,DCM_VAR) Dcm_PeriodicIdTransmission;   
#endif
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_PagedBufferFlag;

DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_PageProcessed;
#endif
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_16BIT
#include "MemMap.h"
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
/*! this is used to store the number of bytes that have been sent with the PagedBuffer*/
DCM_AR_EXTERN VAR(uint16,DCM_VAR) Dcm_LengthSoFar;

/*! this is the total length of the buffer used in PagedBuffer processing (this will be filled for each Dsp_DcmUpdatePage)*/
DCM_AR_EXTERN VAR(PduLengthType,DCM_VAR) Dcm_PagedBufferLength;
/* >><< GAN:2008-08-13 Added new variable to store the filled page length*/
VAR(uint16,DCM_VAR) Dcm_FilledPageLength;
#endif
#define DCM_STOP_SEC_VAR_16BIT
#include "MemMap.h"


#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
DCM_AR_EXTERN CONST(Dcm_DiagnosticBufferCgfType,DCM_CONST) Dcm_DiagnosticBufferCfg[DCM_NUMBER_OF_BUFFER_ID];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

DCM_AR_EXTERN VAR(Dcm_ResponseMessageType,DCM_VAR) Dcm_NegResponse;

DCM_AR_EXTERN VAR(Dcm_ResponseMessageType,DCM_VAR) Dcm_NegResponseBeforeRespPending;

DCM_AR_EXTERN VAR(Dcm_WaitForConfirmationStatusType,DCM_VAR) Dcm_WaitForConfirmation;       

DCM_AR_EXTERN P2VAR(PduInfoType,AUTOMATIC,DCM_APPL_DATA) Dcm_ptrPduMessageType;

DCM_AR_EXTERN VAR(Dcm_Current_Message_Status_Type,DCM_VAR)  Dcm_Current_Message_Status;

DCM_AR_EXTERN P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) Dcm_pMsgContext2 ;  

DCM_AR_EXTERN VAR(Dcm_TimerServerType,DCM_VAR) Dcm_CurrentTimingParameter;

#if (DCM_NUMBER_OF_PROTOCOLS != 1)
DCM_AR_EXTERN VAR(PduIdType,DCM_VAR) Dcm_PreemptedPdu;
#endif

DCM_AR_EXTERN VAR(Dcm_CommunicationStateType,DCM_VAR) Dcm_CommunicationState;

DCM_AR_EXTERN VAR(Dcm_DiagnosticServiceType, DCM_VAR) Dcm_RteService;

DCM_AR_EXTERN P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) Dcm_pRteMsgContext; 

DCM_AR_EXTERN VAR(Dcm_SesCtrlType,DCM_VAR) Dcm_SessionChange;

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
/*! kind of message (positive or negative)*/
DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_FirstUpdatePage;       
#endif

#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*!confirmation status*/
extern VAR(Dcm_ConfirmationStatusType,DCM_VAR) Dcm_Confirmation;

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"



/*
                      Local Data                                            
*/

#define DCM_START_SEC_VAR_FAST_8BIT
#include "MemMap.h"
  /*!
  * \var Dcm_DsdReentrancy
  * \brief This variable is used for reentrancy issues of the Dsd functions
  */
  #if DCM_DEV_ERROR_DETECT==STD_ON
  VAR(uint8,DCM_VAR) Dcm_DsdReentrancy;
  #endif
#define DCM_STOP_SEC_VAR_FAST_8BIT
#include "MemMap.h"

/*
                      Local Function Prototypes                             
*/

#if (DCM_DEV_ERROR_DETECT == STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
  static FUNC(uint8,DCM_CODE) Dcm_CheckNegResponse(Dcm_NegativeResponseCodeType responsecode);
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
                      Local Functions                                       
*/

/*
*! Function to verify if the NRC is correct
*
* \name Dcm_CheckNegResponse
*
* \b Service-Id:   0x28
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 responsecode - NRC that has to be checked
*
* \param (Output)  none
*
* \return          uint8 - this is the response code if it is correct, or GENERALREJECT if the code is not valid
*
* \b Description:  This function shall verify the negative response code. this function must be called before\n
* every call to Dcm_SetNegResponse to make sure that an invalid response code shall not be set in the message.\n
* In case an invalid response code is given as parameter, then this function shall return GENERALREJECT as the \n
* correct negative response code.
*
*/
#if (DCM_DEV_ERROR_DETECT == STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(uint8,DCM_CODE) Dcm_CheckNegResponse(Dcm_NegativeResponseCodeType responsecode)
{
    switch (responsecode)
    {
      case DCM_E_GENERALREJECT:                           
      case DCM_E_SERVICENOTSUPPORTED:
      case DCM_E_SUBFUNCTIONNOTSUPPORTED:                 
      case DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT:   
      case DCM_E_RESPONSE_TOO_LONG:
    case DCM_E_BUSYREPEATREQUEST:                               
    case DCM_E_CONDITIONSNOTCORRECT:                          
    case DCM_E_REQUESTSEQUENCEERROR:
      case DCM_E_NORESPONSEFROMSUBNETCOMPONENT:
      case DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION:
    case DCM_E_REQUESTOUTOFRANGE:                             
    case DCM_E_SECURITYACCESSDENIED:                          
    case DCM_E_INVALIDKEY:                                    
    case DCM_E_EXCEEDNUMBEROFATTEMPTS:                    
    case DCM_E_REQUIREDTIMEDELAYNOTEXPIRED:             
    case DCM_E_UPLOADDOWNLOADNOTACCEPTED:                 
    case DCM_E_TRANSFERDATASUSPENDED:                  
    case DCM_E_GENERALPROGRAMMINGFAILURE:              
    case DCM_E_WRONGBLOCKSEQUENCECOUNTER:              
    case DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING:
    case DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION: 
    case DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION:     
    case DCM_E_RPMTOOHIGH:                             
    case DCM_E_RPMTOOLOW:                                         
    case DCM_E_ENGINEISRUNNING:                        
    case DCM_E_ENGINEISNOTRUNNING:                     
    case DCM_E_ENGINERUNTIMETOOLOW:                    
    case DCM_E_TEMPERATURETOOHIGH:                     
    case DCM_E_TEMPERATURETOOLOW:                      
    case DCM_E_VEHICLESPEEDTOOHIGH:                    
    case DCM_E_VEHICLESPEEDTOOLOW:                     
    case DCM_E_THROTTLE_PEDALTOOHIGH:                         
    case DCM_E_THROTTLE_PEDALTOOLOW:                          
    case DCM_E_TRANSMISSIONRANGENOTINNEUTRAL:             
    case DCM_E_TRANSMISSIONRANGENOTINGEAR:             
    case DCM_E_BREAKSWITCH_NOTCLOSED:                  
    case DCM_E_SHIFTERLEVERNOTINPARK:                         
    case DCM_E_TORQUECONVERTERCLUTCHLOCKED:             
    case DCM_E_VOLTAGETOOHIGH:                                
    case DCM_E_VOLTAGETOOLOW:   
       /*if the parameter is a correct NRC, give permission to set it in the message                                  */
            return (responsecode);
        
    default:
    /*report the fact that the parameter is not correct*/
    #if (DCM_DEV_ERROR_DETECT == STD_ON)
         Det_ReportError(DCM_MODULE_ID,0,75,DCM_E_INTERFACE_VALUE_OUT_OF_RANGE);        
    #endif
    /*return the value DCM_E_GENERALREJECT, this shall be sent with the negative response instead of the wrong responsecode*/
      return (DCM_E_GENERALREJECT);
    }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
                      Global Functions                                      
*/

/*
*! Function for dispatching the diagnostic services
*
* \name Dcm_ReadDiagService
*
* \b Service-Id:   0x27
*
* \b Sync/Async:   Asynchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function shall dispatch the services to the data processor. This function shall also deal with 
* the security and session levels to verify if the service can be executed.
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReadDiagService(void)
{  
  uint8 line; 
  uint8 security_mask=0;
  uint8 session_mask=0;
  uint8 i;
  
  /*the +1 must be implemented because the number of security levels is 8 + 1 (the locked security level)
    the value in the configuration table refers only to the 8 security levels different from 0x00
    for security level 0x00 no service can be executed*/
 #if DCM_DEV_ERROR_DETECT==STD_ON
 if ((Dcm_DsdReentrancy&0x01)==0x00)   
 { 
  Dcm_DsdReentrancy|=0x01;/*set as entry  */
 #endif 
  security_mask=Dcm_GetSecurityMask();
  
  for (i=0;(i<DCM_NUMBER_OF_SESSION_LEVELS)&&(session_mask==0);i++)
  {
    if (Dcm_Current_Message_Status.Dcm_ActiveSession==Dcm_SessionLevel[i].DCM_SESSION_LEVEL)
    {
      /*this is safe because i can be only between 0 and 7*/
      session_mask=(uint8)(0x01<<i);
    }
  }

  /*calculation of the line in the service table where the function is located*/
  line = Dcm_GetServiceTableIndex(Dcm_Current_Message_Status.Dcm_SID);
#if (DCM_DEV_ERROR_DETECT==STD_ON)
  if(line == SNSID)
  {
     /*should not happen here because this check is already made in the calling functions*/
     Det_ReportError(DCM_MODULE_ID,0,0x27,DCM_E_PARAM);
  }
#endif
    /* check required  security access*/
    if ((Dcm_ServiceIdTable[line].DCM_SIDTAB_SEC_LEVEL  & security_mask )) /*mask the security*/
    {   
        if( Dcm_ServiceIdTable[line].DCM_SIDTAB_SESSION_LEVEL & session_mask) /*mask the session*/
          {
            /*start the normal response timer   */
            Dcm_Current_Message_Status.Dcm_NormalResponseIncrement=DCM_TASK_TIME;         
            /*call the appropriate function for the service*/
            /*this should be executed only if the data processor is DSP*/
            /*set flag and start processing at the next task*/
            Dcm_RteService=Dcm_ServiceIdTable[line].DCM_SIDTAB_FUNCTIONPOINTER;    
            /*save also the buffers*/
        Dcm_pRteMsgContext=Dcm_pMsgContext2;
        #if DCM_DEV_ERROR_DETECT==STD_ON 
              Dcm_DsdReentrancy&=0xFE;/*clear*/
        #endif
            return;
          }
        /*negative response in case the session level does not allow processing      */
        Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION);
      #if DCM_DEV_ERROR_DETECT==STD_ON 
        Dcm_DsdReentrancy&=0xFE;/*clear*/
      #endif  
        return; 
    }
  /*negative response in case the security level does not allow processing*/
   
  Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_SECURITYACCESSDENIED);
 #if DCM_DEV_ERROR_DETECT==STD_ON
  Dcm_DsdReentrancy&=0xFE;/*clear*/
  return;  
 }
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function to set the negative response message
*
* \name Dcm_SetNegResponse
*
* \b Service-Id:   0x13
*
* \b Sync/Async:   Asynchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   Dcm_MsgContextType *pMsgContext - structure containing service info
*                  
*                  Dcm_MsgType reqData - this is the request data buffer
*                
*                  Dcm_MsgType respData - this is the response data buffer
*
*                  uint8 errorCode - the NRC that nedds to be set
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function shall set the response and the length to negative response. The errorCode must be checked
*  with function Dcm_CheckNegResponse(). This function shall establish, depending on the NRC, what buffer shall be used.
*  The negative response buffer shall be used only for the NRC 0x78 and 0x21. For any other negative response the normal
*  processing buffer has to be used. This function shall be called before the Dcm_ProcessingDone function if a negative response
*  must be sent.
*
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_SetNegResponse(P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,Dcm_NegativeResponseCodeType errorCode)
{  
    uint8 SID=Dcm_Current_Message_Status.Dcm_SID;
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) buffer;
    
    #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x13,DCM_E_UNINIT);
      return;
    }
  #endif

  /* >> GAN:2008-06-04 Fixed problems with concurrent RCRRP and normal transmission*/
  if (Dcm_Current_Message_Status.Dcm_Transmission == DCM_READY_TO_SEND)
   return;
  /* << GAN:2008-06-04 Fixed problems with concurrent RCRRP and normal transmission  */
    
    /*this variable shall take the address of the buffer used*/
    buffer=pMsgContext->resData;    
    
    
    if ((errorCode==DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING)||(errorCode==DCM_E_BUSYREPEATREQUEST))
    {   
      /*in this case the buffer is the negative response buffer*/
      buffer=&Dcm_NegResponseBuffer[0];    
      Dcm_NegResponse=DCM_RESPONSE_PENDING_OR_BUSY;
    }
    else
    {
      if (Dcm_WaitForConfirmation==DCM_WAIT_FOR_CONFIRMATION)
        Dcm_TempNegResponse=1;
      else
        Dcm_NegResponse=DCM_NEG_RESPONSE;
    }
        
    /*set the bytes in the response */
    buffer[0]=0x7F;
    buffer[1]=SID;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
    buffer[2]=(uint8)Dcm_CheckNegResponse(errorCode);
#else 
    buffer[2]=errorCode;
#endif
        
    /*length of the response    */
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function to set the negative response message and signal end of processing for a service
*
* \name Dcm_NegResponse
*
* \b Service-Id:   
*
* \b Sync/Async:   Asynchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   Dcm_MsgContextType *pMsgContext - structure containing service info
*
*                  Dcm_NegativeResponseCodeType errorCode - the NRC that nedds to be set
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function shall set the negative response message 
*  and signal end of processing for a service
*
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_HandleNegResponse(P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,Dcm_NegativeResponseCodeType errorCode)
{  
    Dcm_SetNegResponse(pMsgContext, errorCode);
    Dcm_ProcessingDone(pMsgContext);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function to signal end of processing for a service
*
* \name Dcm_ProcessingDone
*
* \b Service-Id:   0x14
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   Dcm_MsgContextType *pMsgContext - structure containing service info
*                  
*                  Dcm_MsgType reqData - this is the request data buffer
*                
*                  Dcm_MsgType respData - this is the response data buffer
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function is called whenever a service was processed. The function is called by the data processor (DSP or RTE) and the
*  processing shall be the same, independent of the data processor. This function can decide if the response from the DSP shall be
*  sent using the PagedBuffer mechanism. If the length is larger than 100 bytes, the message is sent using PagedBuffer mechanism. The RTE
*  responses should be already decided if PagedBuffer is used or not, but this function can process the response correctly for the 
*  long RTE responses as well. This mechanism was implemented because of optimization issues. This function shall initiate the
*  transmission to the lower layer by calling the appropriate function. In case of errors, this function is responsible for reset
*  of required parameters.
*
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ProcessingDone(P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{    
   Dcm_MsgType UsedBuf;
     #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x14,DCM_E_UNINIT);
      return;
    }
  #endif
  SchM_Enter_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
  /* >> anam:2010-04-07 CR 70598 */
  if( DCM_NO_NEG_RESPONSE == Dcm_NegResponse )
  {
    /* Restore Dcm_NegResponse */
    Dcm_NegResponse = Dcm_NegResponseBeforeRespPending;
    Dcm_NegResponseBeforeRespPending = DCM_NO_NEG_RESPONSE;
  }
  /* << anam:2010-04-07 CR 70598 */
  
  /* >> GAN:2008-06-04 If a message has already been marked for sending, do not acept any other responses*/
  if ((Dcm_Current_Message_Status.Dcm_Transmission==DCM_READY_TO_SEND)&&(Dcm_NegResponse==DCM_NO_NEG_RESPONSE))
  {
    /*this is in case the Response comes just before the RCRRP error message....this will block the sending of the */
    SchM_Exit_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
    return;
  }
  /* << GAN:2008-06-04 If a message has already been marked for sending, do not acept any other responses*/

  if ((Dcm_Current_Message_Status.Dcm_Transmission==DCM_READY_TO_SEND)&&(Dcm_NegResponse))
  {
    /*if negative response has not been yet transmitted ....this can happen only for 0x78 neg response
      do now the overwritting of the negative message*/
    /* >><< GAN:2008-08-19 Added special check*/  
    if (Dcm_NegResponseBuffer[2]==DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING)
      Dcm_NegResponse=DCM_NO_NEG_RESPONSE;
  }
  
  if (Dcm_WaitForConfirmation == DCM_WAIT_FOR_CONFIRMATION)
  {
    if (Dcm_TempNegResponse != 1)
    {
      Dcm_TempNegResponse = 2;     
      
      UsedBuf = Dcm_pMsgContext2->resData - 1;
      
      UsedBuf[0]=Dcm_Current_Message_Status.Dcm_SID+0x40;
      
      if (UsedBuf[0]==0x50)
          Dcm_SessionChange=UsedBuf[1];
    }
    Dcm_pMsgContext2->resDataLen = pMsgContext->resDataLen;

    /* rois: Workaround for the Bug reportet in RT17510
       Unerwartete Antwort auf Diagnose mit SuppressPosResp */
    Dcm_SuppressionOverride=0;
    SchM_Exit_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
    return;
  } 
  /*this is the only problem where the negative response can be mixed with a normal response*/    
  if (Dcm_NegResponse)
  {
    if (Dcm_NegResponse==DCM_NEG_RESPONSE) 
    {
      Dcm_SuppressionOverride=0;
      UsedBuf=Dcm_pMsgContext2->resData;/*negative response*/
    }
    else
    {
      UsedBuf=&Dcm_NegResponseBuffer[0];
    }
    if (Dcm_ProtocolRxTable[pMsgContext->dcmRxPduId].DCM_PROTOCOL_RX_ADDR_TYPE==DCM_FUNCTIONAL)
      {
         if ((UsedBuf[2]==0x11)||(UsedBuf[2]==0x12)||(UsedBuf[2]==0x31))
         {
            /* >> anam:2010-04-07 CR 70614 */
            Dcm_Confirmation=DCM_RES_NEG_OK;
            /* << anam:2010-04-07 CR 70614 */
            /*suppression of negative response - if permited*/
            Dcm_TxConfirmation(Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId,NTFRSLT_OK); 
            SchM_Exit_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
            return;
         }
      }
  }
  else
  {
    UsedBuf=Dcm_pMsgContext2->resData - 1;/*to give including the first byte for the response*/
      
    /* >> GAN:2008-11-18 Reworked function */ 
#if (DCM_NUMBER_OF_PROTOCOLS != 1) 
    if (pMsgContext->dcmRxPduId==Dcm_PreemptedPdu)
    {
        Dcm_Current_Message_Status.Dcm_ProtocolPreemptTimer=0;
        Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement=0;
        Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;       
        Dcm_PreemptedPdu=0xFF;
        SchM_Exit_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
        return;
    }
#endif
        
#if (DCM_PERIODIC_TRANS_ENABLED==STD_ON)
     if(Dcm_PeriodicIdTransmission==TRUE)
     {
        /*Response SID is 0x2A and not 0x22*/
        UsedBuf[0]=0x2A+0x40;
        Dcm_PeriodicIdTransmission=FALSE;
     }
     else
#endif
     {
        UsedBuf[0]=Dcm_Current_Message_Status.Dcm_SID+0x40;
     }
     
      if (pMsgContext->msgAddInfo.suppressPosResponse==1)
      {
        if (UsedBuf[0]==0x50)
          Dcm_SessionChange=UsedBuf[1];
        if (Dcm_SuppressionOverride!=1)
        {
           /* >> anam:2010-04-07 CR 70614 */
           Dcm_Confirmation=DCM_RES_POS_OK;
           /* << anam:2010-04-07 CR 70614 */
          Dcm_TxConfirmation(Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId,NTFRSLT_OK); 
          SchM_Exit_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
          return;
        }
        else
        {
          Dcm_SuppressionOverride=0;
        }
      }
      /* << GAN:2008-11-18 Reworked function */  
    }
    
  /*one is added because the SID is only re-added to the message here*/
  if (Dcm_NegResponse==DCM_NO_NEG_RESPONSE)
    Dcm_ptrPduMessageType->SduLength=pMsgContext->resDataLen + 1;        
  else
    Dcm_ptrPduMessageType->SduLength=3; /* negative response length always 3*/
  Dcm_pMsgContext2->resDataLen = pMsgContext->resDataLen;

  /*if comm state does not permit it, do not transmit*/
  if (Dcm_CommunicationState==DCM_FULL_COMMUNICATION)
  {
    Dcm_Current_Message_Status.Dcm_Transmission=DCM_READY_TO_SEND;
  }
  else
  {
    /*stop the request normally*/
    Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;
    Dcm_ResetNormalAndBusyTimers();
  }
  SchM_Exit_Dcm(SCHM_DCM_PROTECT_FUNCPTR_INSTANCE_0, SCHM_DCM_PROTECT_FUNCPTR_EXCLUSIVE_AREA_0);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function to signal that the page of the PagedBuffer processing was filled
*
* \name Dcm_ProcessPage
*
* \b Service-Id:   0x1A
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   Dcm_MsgLenType FilledPageLen - the length of the last filled page
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  By calling this function, the data processor shall signal the fact that the page can be sent. This function
*    processes the length of the PagedBuffer mechanism. This function shall be present only if the PagedBuffer
*  mechanism is enabled. 
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
#if (DCM_PAGEDBUFFER_ENABLED == STD_ON )
FUNC(void,DCM_CODE) Dcm_ProcessPage(Dcm_MsgLenType FilledPageLen)
{
  #if (DCM_DEV_ERROR_DETECT==STD_ON)
  if ((Dcm_DsdReentrancy&0x02)==0x00)
  {      
    Dcm_DsdReentrancy|=0x02;/*set as entry*/
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x1A,DCM_E_UNINIT);
      Dcm_DsdReentrancy&=0xFD;/*clear*/
      return;
    }
    #endif 
        
        /*this must be done when processed by DSP*/
        /* >> GAN:2008-02-05 Fixed wrong byte setting for RTE*/
    if ((!Dcm_LengthSoFar)&&(Dcm_Current_Message_Status.Dcm_DataProcessor == DCM_DSP))
      Dcm_pMsgContext2->resData[0]=Dcm_Current_Message_Status.Dcm_SID+0x40;     
        /* << GAN:2008-02-05 Fixed wrong byte setting for RTE*/
        /* store the length of the filled bytes in page ...this have to be saved and not set because
           otherwise it will interfere with the calling of DcmTransmit and provide the length filled
           in the first page rather than the correct total length*/
        /* >> GAN:2008-08-13 FilledPageLen saved and used later*/
        Dcm_FilledPageLength=FilledPageLen;     
        /*this can be done here*/
        Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen-=FilledPageLen; 
        /* >> GAN:2008-08-13 FilledPageLen saved and used later*/
        /*when processed by RTE, how to do*/
    Dcm_PageProcessed=1;
  #if DCM_DEV_ERROR_DETECT==STD_ON
    Dcm_DsdReentrancy&=0xFD;/*clear */
  }
  #endif
}
#endif
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function to signal start of PagedBuffer processing for the current service
*
* \name Dcm_StartPagedProcessing
*
* \b Service-Id:   0x18
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   Dcm_MsgContextType *pMsgContext - structure containing service info
*                  
*                  Dcm_MsgType reqData - this is the request data buffer
*                
*                  Dcm_MsgType respData - this is the response data buffer
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function is used by the data processor to signal the fact that the response is large and it shall
*  be sent in several pages. This function shall start the transmission and inform the lower layer about the full length 
*  of the response. This function is defined only if the PagedBuffer processing is enabled.
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_StartPagedProcessing(P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
    #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if ((Dcm_DsdReentrancy&0x04)==0x00)
     {
    Dcm_DsdReentrancy|=0x04;/*set*/
    if (Dcm_Initialized==STD_OFF)
     {
      Det_ReportError(DCM_MODULE_ID,0,0x18,DCM_E_UNINIT);
      Dcm_DsdReentrancy&=0xFB;/*clear*/
      return;
     }
    #endif
    
      if (Dcm_CommunicationState==DCM_FULL_COMMUNICATION)
        {           
          /*start the PagedBuffer timer      */
          Dcm_Current_Message_Status.Dcm_PagedBufferTimer=0;
          Dcm_Current_Message_Status.Dcm_PagedBufferIncrement=DCM_TASK_TIME;          
          
          /*address of the transmission buffer for this message
            buffer is not needed...not used at this stage...only during the first buffer request
            at this stage only the full length of the response is needed          */
          Dcm_ptrPduMessageType->SduLength=pMsgContext->resDataLen;/*+1; the response on the first page does not include the SID          */
          if (Dcm_Current_Message_Status.Dcm_DataProcessor==DCM_RTE)
          { 
            Dcm_ptrPduMessageType->SduLength++;/*the RTE does not provide the length with SID*/
            Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=Dcm_ptrPduMessageType->SduLength;/*total length of PagedBuffer*/
          }
          Dcm_ptrPduMessageType->SduDataPtr=Dcm_pMsgContext2->resData - 1; /*also include here the SID*/
                                              
      Dcm_Current_Message_Status.Dcm_NormalResponseTimer=0;
      Dcm_Current_Message_Status.Dcm_NormalResponseIncrement=DCM_TASK_TIME;
      /*reset the timers - this part must be done always (if the PagedBuffer was accepted or rejected)      */
      Dcm_Current_Message_Status.Dcm_BusyProcessingTimer=0;
      Dcm_Current_Message_Status.Dcm_BusyProcessingIncrement=0;
                        
      /*this is the maximum length of the buffer                       */
      Dcm_PagedBufferLength=pMsgContext->resMaxDataLen+1;/*this should be the buffer size*/
      
      Dcm_PagedBufferFlag=1;/*start paged processing        */
      /*wait for the min timer to expire*/
      Dcm_Current_Message_Status.Dcm_Transmission=DCM_READY_TO_SEND;
      
      if (Dcm_Current_Message_Status.Dcm_DataProcessor==DCM_RTE)
          { 
        Dcm_PageProcessed=2;
        /* >> GAN:2008-08-13 Moved in this if statement*/
        Dcm_FirstUpdatePage=1; 
        /* << GAN:2008-08-13 Moved in this if statement*/
      
        Dcm_ptrPduMessageType->SduDataPtr[0]=Dcm_Current_Message_Status.Dcm_SID+0x40;/*fill the service ID byte*/
        Rte_DcmUpdatePage(&Dcm_ptrPduMessageType->SduDataPtr[1],Dcm_PagedBufferLength-1);/*save first byte for SID info             */
      
          }
          else
          { 
            Dcm_PageProcessed=2; 
                
              Dsp_DcmUpdatePage(&Dcm_ptrPduMessageType->SduDataPtr[0],Dcm_PagedBufferLength);/*to also include the SID byte            */
               
              Dcm_PageProcessed=3;
          }
        }
      else
      {
          /*if no answer is allowed, then the normal timers should be inactivated because this processing is over*/
          Dcm_ResetNormalAndBusyTimers();
        /*>>GAN2009-09-09 Also make the buffer un-used*/
        Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;
        /*<<GAN2009-09-09 Also make the buffer un-used*/

      }
   #if DCM_DEV_ERROR_DETECT==STD_ON
      Dcm_DsdReentrancy&=0xFB;/*clear*/
   }
   #endif
}
#endif
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Retrieves the active service table identifier
*
* \name Dcm_GetActiveServiceTable
*
* \b Service-Id:   0x1C
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  uint8* ServiceIdTable - the Id of the currently used service table
*
* \return          none
*
* \b Description:  This function is used to obtain the service table Id of the currently used service Id. The value shall be returned
*  via output parameter.  
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_GetActiveServiceTable(P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) ServiceTableId)
{
 #if (DCM_DEV_ERROR_DETECT==STD_ON)
 if ((Dcm_DsdReentrancy&0x08)==0x00)
 {
  Dcm_DsdReentrancy|=0x08;/*set   */
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x1C,DCM_E_UNINIT);
      Dcm_DsdReentrancy&=0xF7;/*clear*/
      return;
    }
  #endif
  *ServiceTableId=Dcm_ProtocolTable[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_PROTOCOL_IDENTIFIER_TABLE_ID;
 #if DCM_DEV_ERROR_DETECT==STD_ON
  Dcm_DsdReentrancy&=0xF7;
 }
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Get the index of the service table from an incomming Service ID
*
* \name Dcm_GetServiceTableIndex
*
* \b Service-Id:   
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   uint8 ServiceId
*
* \param (Output)  none
*
* \return          uint8 serviceTableIndex - The table index for the service id
                   If the service is not supported SNSID is returned.
*
* \b Description:  This function is used to Function to get the index of the service table from an incomming Service ID
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8,DCM_CODE) Dcm_GetServiceTableIndex(uint8 ServiceId)
{
    uint8 i;
    uint8 ProtocolIdentifierTableId=Dcm_ProtocolTable[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_PROTOCOL_IDENTIFIER_TABLE_ID;
    /*Search all entries of Dcm_ServiceIdTable if the incomming SID is supported*/
    for (i=0;i<DCM_NUMBER_OF_SERVICE_ID;i++)
    {
        if(Dcm_ServiceIdTable[i].DCM_SIDTAB_ID == ProtocolIdentifierTableId)
        {
            if(Dcm_ServiceIdTable[i].DCM_SIDTAB_SERVICEID == ServiceId)
            {
                /*Service Table Index has been found so exit the loops*/
                return i;
            }
        }
    }
    return SNSID;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function to calculate the security mask for the current message
*
* \name Dcm_GetSecurityMask
*
* \b Service-Id:   
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          uint8 the security mask
*                  or 0 if no security level is set
*
* \b Description:  Function to calculate the security mask for the current message
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8,DCM_CODE) Dcm_GetSecurityMask(void)
{
    uint8 i=0;
    uint8 security_mask=0;
    /*establish the security mask */
    for (i=0;(i<DCM_NUMBER_OF_SECURITY_LEVELS)&&(security_mask==0);i++)
    {
        if (Dcm_Current_Message_Status.Dcm_ActiveSecurityLevel==Dcm_SecLevel[i].DCM_SEC_LEVEL)
        {
            /*this is safe because i can be only between 0 and 7*/
            security_mask=(uint8)(0x01<<i);
        }
    }
    return security_mask;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"


#undef DCM_AR_EXTERN

#undef __DSD_C__
