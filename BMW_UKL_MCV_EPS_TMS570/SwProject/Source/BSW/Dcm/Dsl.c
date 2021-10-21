/*
                                                                            
  SRC-MODULE: Dsl.c                                                         
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm module - DSL Part C source file                           
                                                                            
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
 *          2010.01.18, anam: CR 70453, CR 70483, CR 70493, CR 70494,
 *                            CR 70495, CR 70497 - Bug-fixing changes 
 * v 2.4.0, 2010.02.23, gema: CR 70411: DCM: Module extension to 3.0  
 * v 2.4.3, 2010.04.07, anam: CR 70598: Negative response cleared with ResponsePending
 * v 2.4.4, 2010.04.23, anam: CR 70632: Compiler abstraction missing for local pointer  
 * v 2.4.5, 2010.06.30, anam: CR 70620: Notifications via RTE are called in interrupt context
                              CR 70634: S3 timeout handling
                              CR 70764: DCM: Blockade after concurring functional/physical requests (repeated FirstFrame)
 *                      naka: CR 70722: Change the type of parameter "Length" of the function Dcm_ProvideTxBuffer to "PduLengthType"
*/

#define __DSL_C__


/*
                      Include Section                                       
*/

#include "Dcm.h"
#include "Dsd.h"
#include "Dcm_Cbk.h"
#include "Rte_dcm.h"
#if (DCM_CONFIGURATION_TYPE==DCM_LINK_TIME)
 #include "Dcm_Lcfg.h"
#endif
#if (DCM_DEV_ERROR_DETECT==STD_ON)
 #include "Det.h"
#endif 

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
/*default protocol timings taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_TimerServerType,DCM_CONST) Dcm_ProtocolDefaultTiming[DCM_NUMBER_OF_PROTOCOLS];

/*limit timing parameters taken from Dcm.c*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
DCM_AR_EXTERN CONST(Dcm_TimerServerType,DCM_CONST) Dcm_ProtocolLimitsTiming[DCM_NUMBER_OF_PROTOCOLS];
#endif

/*RxPdu information taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolRxTableType,DCM_CONST) Dcm_ProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID];

/*TxPdu configuration taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolTxTableType,DCM_CONST) Dcm_ProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID];

/*Session level information taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_SessionLevelTableType,DCM_CONST) Dcm_SessionLevel[DCM_NUMBER_OF_SESSION_LEVELS];

/*Service identifier table taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_ServiceIdentifierTableType,DCM_CONST) Dcm_ServiceIdTable[DCM_NUMBER_OF_SERVICE_ID];

/*Protocol information taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolTableType,DCM_CONST) Dcm_ProtocolTable[DCM_NUMBER_OF_PROTOCOLS];

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#else

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*default protocol timings taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_TimerServerType,DCM_VAR) Dcm_ProtocolDefaultTiming[DCM_NUMBER_OF_PROTOCOLS];

/*limit timing parameters taken from Dcm.c*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
DCM_AR_EXTERN VAR(Dcm_TimerServerType,DCM_VAR) Dcm_ProtocolLimitsTiming[DCM_NUMBER_OF_PROTOCOLS];
#endif

/*RxPdu information taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolRxTableType,DCM_VAR) Dcm_ProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID];

/*TxPdu configuration taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolTxTableType,DCM_VAR) Dcm_ProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID];

/*Session level information taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_SessionLevelTableType,DCM_VAR) Dcm_SessionLevel[DCM_NUMBER_OF_SESSION_LEVELS];

/*Service identifier table taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_ServiceIdentifierTableType,DCM_VAR) Dcm_ServiceIdTable[DCM_NUMBER_OF_SERVICE_ID];

/*Protocol information taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolTableType,DCM_VAR) Dcm_ProtocolTable[DCM_NUMBER_OF_PROTOCOLS];

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif


#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
/*Flag used at DCM initialization*/
#if (DCM_DEV_ERROR_DETECT==STD_ON)
DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_Initialized;
#endif

/*protocol that is preempting the current protocol*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_PreemptingProtocol;
#endif

DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_FirstRequest;

DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_TempNegResponse;

#if (DCM_PERIODIC_TRANS_ENABLED==STD_ON)
DCM_AR_EXTERN VAR(boolean,DCM_VAR) Dcm_PeriodicIdTransmission;   
#endif
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_PagedBufferFlag;
#endif
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_16BIT
#include "MemMap.h"
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
/*! this is used to store the number of bytes that have been sent with the PagedBuffer*/
DCM_AR_EXTERN VAR(uint16,DCM_VAR) Dcm_LengthSoFar;

DCM_AR_EXTERN VAR(uint16,DCM_VAR) Dcm_FilledPageLength;
/*! this is the total length of the buffer used in PagedBuffer processing (this will be filled for each Dsp_DcmUpdatePage)*/
DCM_AR_EXTERN VAR(PduLengthType,DCM_VAR) Dcm_PagedBufferLength;

/*! this is the length of the request. It has to be stored so that the request can be simulated in the PagedBuffer processing*/
DCM_AR_EXTERN VAR(Dcm_MsgLenType,DCM_VAR) Dcm_RequestLength;
#endif
#define DCM_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*Buffer configuration taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_DiagnosticBufferCgfType,DCM_CONST) Dcm_DiagnosticBufferCfg[DCM_NUMBER_OF_BUFFER_ID];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

DCM_AR_EXTERN VAR(Dcm_ResponseMessageType,DCM_VAR) Dcm_NegResponse;

DCM_AR_EXTERN VAR(Dcm_ResponseMessageType,DCM_VAR) Dcm_NegResponseBeforeRespPending;

DCM_AR_EXTERN VAR(Dcm_WaitForConfirmationStatusType,DCM_VAR) Dcm_WaitForConfirmation;

/* Message pointer to length & data*/
DCM_AR_EXTERN P2VAR(PduInfoType,AUTOMATIC,DCM_APPL_DATA) Dcm_ptrPduMessageType;

DCM_AR_EXTERN P2VAR(PduInfoType,AUTOMATIC,DCM_APPL_DATA) Dcm_ptrFuncPduMessageType;

/*structure used for service processing*/
DCM_AR_EXTERN P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) Dcm_pMsgContext2;

#if DCM_PAGEDBUFFER_ENABLED==STD_ON
/*! used for pagedbuffer processing to signal which function must still process*/
DCM_AR_EXTERN VAR(Dcm_DiagnosticServiceType, DCM_VAR) Dcm_PagedBufferService;
#endif

/*communication state of the DCM*/
DCM_AR_EXTERN VAR(Dcm_CommunicationStateType,DCM_VAR) Dcm_CommunicationState;

/*current timing structure*/
DCM_AR_EXTERN VAR(Dcm_TimerServerType,DCM_VAR) Dcm_CurrentTimingParameter;


/*structure containing information about the current processing*/
DCM_AR_EXTERN VAR(Dcm_Current_Message_Status_Type,DCM_VAR) Dcm_Current_Message_Status;

/*variable used when the session needs to be changed*/
DCM_AR_EXTERN VAR(Dcm_SesCtrlType,DCM_VAR) Dcm_SessionChange;

/*RxPdu of the preempted message*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
DCM_AR_EXTERN VAR(PduIdType,DCM_VAR) Dcm_PreemptedPdu;
#endif

/*the new timing parameters*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
DCM_AR_EXTERN P2VAR(Dcm_TimerServerType,AUTOMATIC,DCM_APPL_DATA) Dcm_NewTimingValues;
#endif

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
/*!ProcessPage function was called*/
VAR(uint8,DCM_VAR) Dcm_PageProcessed;

/*!Signals first UpdatePage call*/
VAR(uint8,DCM_VAR) Dcm_FirstUpdatePage;
#endif
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/*
                      Local Data                                            
*/

/*! \enum Dcm_ConcurrentMessageType
 *  \brief Indicate if a message has arrived while an old message is still in progress
 */
typedef enum
{
   DCM_NO_CONCURRENT_REQUEST          = 0,
   DCM_CONCURRENT_REQUEST             = 1,
   DCM_CONCURRENT_HIGH_PRIO_REQUEST   = 2
}Dcm_concurrentResponseMessageType;

/*! \enum Dcm_ConcurrentMessageType
 *  \brief Indicate if a response is a response pending or busy repeat message
 */
typedef enum
{
   DCM_NO_BUSY_OR_PENDING_MESSAGE = 0,
   DCM_RESPONSE_PENDING_MESSAGE   = 1,
   DCM_BUSY_REPEAT_MESSAGE        = 2
}Dcm_KindOfMessageType;

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*!confirmation status*/
VAR(Dcm_ConfirmationStatusType,DCM_VAR) Dcm_Confirmation;

VAR(Dcm_concurrentResponseMessageType,DCM_VAR) Dcm_ConcurrentMessages;  

/*!kind of message (response pending or busy repeat)*/
VAR(Dcm_KindOfMessageType,DCM_VAR) Dcm_KindOfMessage;

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_FAST_8BIT
#include "MemMap.h"
#if DCM_DEV_ERROR_DETECT==STD_ON
VAR(uint8,DCM_VAR) Dcm_DslReentrancy;
#endif
#define DCM_STOP_SEC_VAR_FAST_8BIT
#include "MemMap.h"

/* Function for resetting the timers*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_ResetTimers(void);
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/* Function for setting the request type*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_SetReqType(void);
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/* Dcm internal function to start the protocol*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(boolean,DCM_CODE) Dcm_StartProtocol(PduIdType DcmRxPduId);
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
                      Global Functions                                      
*/

/*
*! Function for setting the session level
*
* \name Dcm_SetSesCtrlType
*
* \b Service-Id:   0x07
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   Dcm_SesCtrlType SesCtrlType - the session value that has to be set
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  Function is used to set the new session value. No other checks required because they were done during
* service DiagnosticSessionControl. 
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE)  Dcm_SetSesCtrlType(Dcm_SesCtrlType SesCtrlType)
{
 uint8 index,i; 
 #if DCM_DEV_ERROR_DETECT==STD_ON
 if ((Dcm_DslReentrancy&=0x01)==0x00)
 {
    Dcm_DslReentrancy|=0x0001;/*set*/
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x07,DCM_E_UNINIT);
      Dcm_DslReentrancy&=0xFE;/*clear*/
      return;
    }
  #endif
     
  if (Dcm_Current_Message_Status.Dcm_ActiveSession != SesCtrlType)
  {   
    index=0;
    /*index of the new session in configuration tables*/
    for (i=0;i<DCM_NUMBER_OF_SESSION_LEVELS;i++)
    {
      if (SesCtrlType==Dcm_SessionLevel[i].DCM_SESSION_LEVEL)
      {
        index=i;
      }
    }
     
  
    /*set the new timing parameters for this session*/
    Dcm_CurrentTimingParameter.DCM_TIMSTR_P2SERVER_MAX=Dcm_SessionLevel[index].DCM_SESSION_P2SERVER_MAX;
    Dcm_CurrentTimingParameter.DCM_TIMSTR_P2STARSERVER_MAX=Dcm_SessionLevel[index].DCM_SESSION_P2STRSERVER_MAX;
    
  }
  
  /* >> GAN:2008-02-04 Session change indication called always, not only when new session != old session
    notify the application about the session change*/
  Rte_DcmSesCtrlChangeIndication(Dcm_Current_Message_Status.Dcm_ActiveSession,SesCtrlType);
  /* << GAN:2008-02-04 Session change indication called always, not only when new session != old session*/
     
  /*if the new session is non-default, call the fucntion in ComM and inform about the need to stay in ActiveDiagnostic*/
  if (SesCtrlType != DEFAULT_SESSION)
  {     
     ComM_DCM_ActiveDiagnostic();
  }
  /*if the new session is default, call the function in ComM and inform about the fact that ActiveDiagnostic is no longer needed*/
  else /*SesCtrlType == DEFAULT_SESSION*/
  {
      if( Dcm_Current_Message_Status.Dcm_ActiveSession != DEFAULT_SESSION )
      {
          ComM_DCM_InactiveDiagnostic();
      }
  }
  Dcm_Current_Message_Status.Dcm_ActiveSession = SesCtrlType;
  Dcm_Current_Message_Status.Dcm_ActiveSecurityLevel = 0x00; /*lock security level*/

 #if DCM_DEV_ERROR_DETECT==STD_ON   
 Dcm_DslReentrancy&=0xFE;/*clear*/
 }
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"


/*
*! Function for retrieving the session level
*
* \name Dcm_GetSesCtrlType
*
* \b Service-Id:   0x06
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   none
*
* \param (Output)  AS2.1: none
*                  AS3.0: Dcm_SesCtrlType - the current session level
*
* \return          AS2.1: Dcm_SesCtrlType - the current session level
*                  AS3.0: DCM_E_OK
*
* \b Description:  Function is used to obtain the current session level
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
#if ( DCM_BAC_VERSION == DCM_BAC21 )
FUNC(Dcm_SesCtrlType,DCM_CODE) Dcm_GetSesCtrlType(void)
{
  #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x06,DCM_E_UNINIT);
      return 0x01;
    }
  #endif
    return Dcm_Current_Message_Status.Dcm_ActiveSession;
}
#elif ( DCM_BAC_VERSION == DCM_BAC3X )
FUNC(Std_ReturnType,DCM_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType,AUTOMATIC,DCM_APPL_DATA) SesCtrlType)
{
  #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x06,DCM_E_UNINIT);
      *SesCtrlType = 0x01;
      return DCM_E_OK;
    }
  #endif
    *SesCtrlType = Dcm_Current_Message_Status.Dcm_ActiveSession;
    return DCM_E_OK;
}
#endif /* AUTOSAR 3.0 */
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function for retrieving the session timing values
*
* \name Dcm_GetSesTimingValues
*
* \b Service-Id:   0x0A
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   Dcm_TimerModeType TimerMode - the type of the required timing parameter
*
* \param (Output)  Dcm_TimerServerType *TimerServerCurrent - structure shall be filled with current timing values
*
* \return          none
*
* \b Description:  Function is used to obtain the current session timing values
*
*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_GetSesTimingValues(Dcm_TimerModeType TimerMode,
                              P2VAR(Dcm_TimerServerType,AUTOMATIC,DCM_APPL_DATA) TimerServerCurrent)
{  
  #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x0A,DCM_E_UNINIT);
      return;
    }
  #endif
  /*depending on the TimerMode parameter, return the correct set of parameters*/
    switch (TimerMode)
    {
        case DCM_CURRENT:
        {
            *TimerServerCurrent = Dcm_CurrentTimingParameter;
            break;
        }
        case DCM_DEFAULT:
        {            
             *TimerServerCurrent = Dcm_ProtocolDefaultTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex];
             break;
        }
        case DCM_LIMITS:
        {           
            *TimerServerCurrent = Dcm_ProtocolLimitsTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex];
            break;
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*
*! Function for setting the session timing values
*
* \name Dcm_SetSesTimingValues
*
* \b Service-Id:   0x0A
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   const Dcm_TimerServerType *TimerServerNew - this structure contain the new timing values
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  Function is used to set the new session timing values
*
*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_SetSesTimingValues(P2CONST(Dcm_TimerServerType,AUTOMATIC,DCM_APPL_DATA) TimerServerNew)
{
 #if (DCM_DEV_ERROR_DETECT==STD_ON)  
 if ((Dcm_DslReentrancy&0x02)==0x00)
 {
  Dcm_DslReentrancy|=0x02;/*set     */
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x0C,DCM_E_UNINIT);
      Dcm_DslReentrancy&=0xFD;/*clear*/
      return;
    }
  #endif
    Dcm_CurrentTimingParameter=*TimerServerNew;
 #if (DCM_DEV_ERROR_DETECT==STD_ON)
    Dcm_DslReentrancy&=0xFD;/*clear*/
 }
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*
*! Function for preparing the session timing values
*
* \name Dcm_PrepareSesTimingValues
*
* \b Service-Id:   0x0B
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   const Dcm_TimerServerType *TimerServerNew - this structure contain the new timing values (to be prepared)
*
* \param (Output)  none
*
* \return          Dcm_StatusType - the result of the preparation.
*                   DCM_E_OK: preparation was successful
*                   DCM_E_TI_PREPARE_LIMITS: requested values are not within the defined limits
*                   DCM_E_TI_PREPARE_INCONSTENT: requested values are not consistent
*                  (e.g. P2min not smaller than P2max)
*
* \b Description:  Function is used to prepare the new session timing values. Timing values shall be
* verified and the return value shall inform the caller if the timing parameters are correct or not (see return values)
*
*/

#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(Dcm_StatusType,DCM_CODE) Dcm_PrepareSesTimingValues(P2CONST(Dcm_TimerServerType,AUTOMATIC,DCM_APPL_DATA) TimerServerNew)
{
 #if (DCM_DEV_ERROR_DETECT==STD_ON)  
 if ((Dcm_DslReentrancy&0x04)==0x00)
 {   
  Dcm_DslReentrancy|=0x04;/*set*/
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x0B,DCM_E_UNINIT);
      Dcm_DslReentrancy&=0xFB;/*clear*/
      return DCM_E_TI_PREPARE_INCONSISTENT;
    }
  #endif
  if (TimerServerNew->DCM_TIMSTR_P2SERVER_MAX <= DCM_P2SERVER_ADJUST)
  {
    #if (DCM_DEV_ERROR_DETECT==STD_ON)
    Dcm_DslReentrancy&=0xFB;/*clear*/
    #endif
    return DCM_E_TI_PREPARE_INCONSISTENT;
  }
  
  if (TimerServerNew->DCM_TIMSTR_P2STARSERVER_MAX <= DCM_P2STARSERVER_ADJUST)
  {
    #if (DCM_DEV_ERROR_DETECT==STD_ON)
    Dcm_DslReentrancy&=0xFB;/*clear*/
    #endif
    return DCM_E_TI_PREPARE_INCONSISTENT;
  }
  
  /*check consistency*/
  if (((TimerServerNew->DCM_TIMSTR_P2SERVER_MAX - DCM_P2SERVER_ADJUST) >= DCM_TASK_TIME )&&\
      ((TimerServerNew->DCM_TIMSTR_P2SERVER_MAX - DCM_P2SERVER_ADJUST) > (TimerServerNew->DCM_TIMSTR_P2SERVER_MIN + DCM_TASK_TIME))&&\
      ((TimerServerNew->DCM_TIMSTR_P2STARSERVER_MAX - DCM_P2STARSERVER_ADJUST) > (TimerServerNew->DCM_TIMSTR_P2STARSERVER_MIN + DCM_TASK_TIME)))
  {
     /*check limits*/
     if (((TimerServerNew->DCM_TIMSTR_P2STARSERVER_MAX - DCM_P2STARSERVER_ADJUST) >= (TimerServerNew->DCM_TIMSTR_P2SERVER_MAX - DCM_P2SERVER_ADJUST)) &&\
         (TimerServerNew->DCM_TIMSTR_P2STARSERVER_MIN >= TimerServerNew->DCM_TIMSTR_P2SERVER_MIN))
     {
       /*check limits*/
       if (TimerServerNew->DCM_TIMSTR_S3SERVER > TimerServerNew->DCM_TIMSTR_P2STARSERVER_MIN)
       {
         #if (DCM_DEV_ERROR_DETECT==STD_ON)
         Dcm_DslReentrancy&=0xFB;/*clear*/
         #endif
         return DCM_E_OK;
       }
       else
       {
         #if (DCM_DEV_ERROR_DETECT==STD_ON)
         Dcm_DslReentrancy&=0xFB;/*clear*/
         #endif
         return DCM_E_TI_PREPARE_LIMITS;
       }       
     }
     else
     {
       #if (DCM_DEV_ERROR_DETECT==STD_ON)
       Dcm_DslReentrancy&=0xFB;/*clear*/
       #endif
       return DCM_E_TI_PREPARE_LIMITS;
     }     
  }
  else
  {
    #if (DCM_DEV_ERROR_DETECT==STD_ON)
    Dcm_DslReentrancy&=0xFB;/*clear*/
    #endif
    return DCM_E_TI_PREPARE_INCONSISTENT;
  }
 #if DCM_DEV_ERROR_DETECT==STD_ON 
 }
 else
 {
   /*this means that another call of this function is still active*/
   return DCM_E_TI_PREPARE_INCONSISTENT;
 }
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*
*! Function for retrieving the current security level
*
* \name Dcm_GetSecurityLevel
*
* \b Service-Id:   0x0D
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          Dcm_SecLevelType - the current security level
*
* \b Description:  Function is used to obtain the current security value
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(Dcm_SecLevelType,DCM_CODE) Dcm_GetSecurityLevel(void)
{
   #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x0D,DCM_E_UNINIT);
      return 0x00;
    }
   #endif
   return Dcm_Current_Message_Status.Dcm_ActiveSecurityLevel;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function for setting the current security level
*
* \name Dcm_SetSecurityLevel
*
* \b Service-Id:   0x0E
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   Dcm_SecLevelType SecurityLevel - this is the security level to be set
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  Function is used to set the current security value
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_SetSecurityLevel(Dcm_SecLevelType SecurityLevel)
{
 #if (DCM_DEV_ERROR_DETECT==STD_ON)  
 if ((Dcm_DslReentrancy&0x08)==0x00)
 {   
  Dcm_DslReentrancy|=0x08;/*set*/
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x0E,DCM_E_UNINIT);
      Dcm_DslReentrancy&=0xF7;/*clear*/
      return;
    }
 #endif
  Dcm_Current_Message_Status.Dcm_ActiveSecurityLevel=SecurityLevel;
 #if DCM_DEV_ERROR_DETECT==STD_ON 
  Dcm_DslReentrancy&=0xF7;/*clear*/
 }
 #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function for retrieving the active protocol
*
* \name Dcm_GetActiveProtocol
*
* \b Service-Id:   0x0F
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_ProtocolType *ActiveProtocol - the value of the protocol shall be returnes
*
* \return          AS2.1: none
*                  AS3.0: DCM_E_OK
*
* \b Description:  Function is used to obtain the current active protocol id.
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
#if ( DCM_BAC_VERSION == DCM_BAC21 )
FUNC(void,DCM_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType,AUTOMATIC,DCM_APPL_DATA) ActiveProtocol)
{
  #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x0F,DCM_E_UNINIT);
      return;
    }
  #endif
    *ActiveProtocol=Dcm_ProtocolTable[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_PROTOCOL_ID;
}
#elif ( DCM_BAC_VERSION == DCM_BAC3X )
FUNC(Std_ReturnType,DCM_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType,AUTOMATIC,DCM_APPL_DATA) ActiveProtocol)
{
  #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x0F,DCM_E_UNINIT);
      return DCM_E_OK;
    }
  #endif
    *ActiveProtocol=Dcm_ProtocolTable[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_PROTOCOL_ID;
    return DCM_E_OK;
}
#endif /* AUTOSAR 3.0 */
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used to signal the reception 
*
* \name Dcm_RxIndication
*
* \b Service-Id:   0x03
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   PduIdType DcmRxPduId - the Id of the received request. Range: 0..Number of RxPdus - 1
*                                    NotifResultType Result - the result of the reception. Range: NTFRSLT_OK/NOTIFRESULT_E_NOT_OK
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  Using this function, a lower layer can notify the reception of one request. The success or failure of the reception
*  is given by the parameter Result. Depending on this parameter, the DSL layer shall decide the following processing:
*  either stop the reception because of failure (Result=NTFRSLT_E_NOT_OK) or continue normally because the request
*  has been corectly received(Result=NTFRSLT_OK). The first parameter, DcmRxPduId, gives information about the received
*  message. Using this Id, the DSL can find all required information about this request that it needs to correctly dispatch
*  this message to the data processor. This function, in case of successful reception, specifies to DSL the fact that the 
*  message data is placed in the buffer provided at the call of Dcm_ProvideRxBuffer. In case of failure, the DSL shall not 
*  access the bytes of the buffer.
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_RxIndication( PduIdType DcmRxPduId, NotifResultType Result )
{
     Dcm_StatusType Diag_Status;
     uint8 line;
     /*development error for RxPduId*/   
     
     #if (DCM_DEV_ERROR_DETECT==STD_ON)
     if (Dcm_Initialized==STD_OFF)
     {
       Det_ReportError(DCM_MODULE_ID,0,0x03,DCM_E_UNINIT);
       return;
     } 
     if (DcmRxPduId >= DCM_NUMBER_OF_DCMRXPDUID)
       {
         Det_ReportError(DCM_MODULE_ID,0,0x03,DCM_E_PARAM);
         if(DEFAULT_SESSION != Dcm_Current_Message_Status.Dcm_ActiveSession)
         {
            Dcm_Current_Message_Status.Dcm_S3ServerIncrement = DCM_TASK_TIME;
            Dcm_Current_Message_Status.Dcm_S3ServerTimer = 0;
         }
         
         return;
       }
     #endif

   /*if the request has failed, stop processing and free resources*/
     if (Result!=NTFRSLT_OK)
     {
       /* >> GAN:2008-02-06 In case any concurrent message is received here, block it*/
       if (Dcm_ConcurrentMessages!=DCM_NO_CONCURRENT_REQUEST)
       {
         Dcm_ConcurrentMessages=DCM_NO_CONCURRENT_REQUEST;
         return;
       }
       /* << GAN:2008-02-06 In case any concurrent message is received here, block it*/
       Dcm_ResetTimers();
       return;
     }
     else
     {
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
      /*if a high prio request has arrived while a low prio request is still running*/
        if(Dcm_ConcurrentMessages==DCM_CONCURRENT_HIGH_PRIO_REQUEST)
       {
          /*protocol priority
            variable Dcm_pMsgContext2 should contain all data for preempted protocol
            only if the preempted timer was not yet started stop the current protocol
            because stopping should occur only once*/
          if (Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement == 0) 
          {
            Rte_DcmStopProtocol(Dcm_pMsgContext2);
            Dcm_Current_Message_Status.Dcm_StartProtocolStatus=0;
            Dcm_PreemptedPdu=Dcm_pMsgContext2->dcmRxPduId;            
          }
         Dcm_Current_Message_Status.Dcm_SID=*Dcm_DiagnosticBufferCfg[Dcm_ProtocolRxTable[Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId].DCM_PROTOCOL_RX_BUFFER_ID].DCM_BUFFER_ADDRESS;
          Dcm_PreemptingProtocol=Dcm_GetProtocolTableId(DcmRxPduId);
          /*at the next call of main function the BusyRepeatRequest processing shall be done        */
          Dcm_Current_Message_Status.Dcm_Busy_Repeat_Request=DCM_BUSYREPEATREQUEST;                             
          Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement=DCM_TASK_TIME;
          return;
       }
#endif
         
       /*here test if the function tester present has arrived during other physical processing
         >> GAN:2008-02-06 here test if the id is functional 
         if the on-going Pdu is physical, and the current*/
       if (Dcm_ConcurrentMessages==DCM_CONCURRENT_REQUEST)
       {
         Dcm_ConcurrentMessages=DCM_NO_CONCURRENT_REQUEST;
         if(  (Dcm_ProtocolRxTable[Dcm_pMsgContext2->dcmRxPduId].DCM_PROTOCOL_RX_ADDR_TYPE == DCM_PHYSICAL) 
            &&(Dcm_ProtocolRxTable[DcmRxPduId].DCM_PROTOCOL_RX_ADDR_TYPE == DCM_FUNCTIONAL))
         {
           /*this means it is the functional request has been received during a physical 
             check if the buffer is different*/
           if (Dcm_ProtocolRxTable[DcmRxPduId].DCM_PROTOCOL_RX_BUFFER_ID != Dcm_Current_Message_Status.Dcm_Message_Status_Busy-1)
           {
             /*check if it is Tester Present with suppression*/
             if ((Dcm_DiagnosticBufferCfg[Dcm_ProtocolRxTable[DcmRxPduId].DCM_PROTOCOL_RX_BUFFER_ID].DCM_BUFFER_ADDRESS[0] == 0x3E)&&\
                 (Dcm_DiagnosticBufferCfg[Dcm_ProtocolRxTable[DcmRxPduId].DCM_PROTOCOL_RX_BUFFER_ID].DCM_BUFFER_ADDRESS[1] & 0x80))
             { 
               /*reset the S3Server*/
               Dcm_Current_Message_Status.Dcm_S3ServerTimer=0;
             }
           }
           return;
         }
       }
       /*get the SID        */
       Dcm_Current_Message_Status.Dcm_SID=*Dcm_DiagnosticBufferCfg[Dcm_ProtocolRxTable[Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId].DCM_PROTOCOL_RX_BUFFER_ID].DCM_BUFFER_ADDRESS;
       Dcm_pMsgContext2->idContext=Dcm_Current_Message_Status.Dcm_SID;

       /*start the normal response timer*/
       Dcm_Current_Message_Status.Dcm_NormalResponseIncrement=DCM_TASK_TIME;    

       /*calculation of the line in the service table where the function is located*/
       line = Dcm_GetServiceTableIndex(Dcm_Current_Message_Status.Dcm_SID);
    
       /*check the SID if it is supported*/
       if(line == SNSID) /* mw060131 new if-condition*/
       {       
           Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_SERVICENOTSUPPORTED);
           return;
       }
        
       Diag_Status=(Dcm_StatusType)DCM_E_OK; 
       
       /*Check the message adressing type*/
         if(Dcm_ProtocolRxTable[DcmRxPduId].DCM_PROTOCOL_RX_ADDR_TYPE==DCM_FUNCTIONAL)
         { 
           /*Check if SID==0x3E - TesterPresent service with subfunction==0x80*/
           if((Dcm_Current_Message_Status.Dcm_SID==0x3E) && (Dcm_pMsgContext2->reqData[0]==0x80))
             {
               /*This request will not be forwarded to DSD for further interpretation           */
               Dcm_ResetTimers();
               return;
             }
         }
         
         /*if all conditions were correct start the processing              
           get the addressing type*/
         Dcm_SetReqType();
                 
         /* >> GAN:2008-05-28 Moved the suppression setting before the call to Rte_DcmIndication*/

         /*if subfunction is available, check the suppression bit and fill the bit in the additional information field of the message*/
         if (Dcm_ServiceIdTable[line].DCM_SIDTAB_SUBFUNC_AVAIL)
         {
           if (Dcm_pMsgContext2->reqData[0] & 0x80 && Dcm_Current_Message_Status.Dcm_SID!=0x36)
           {
             Dcm_pMsgContext2->msgAddInfo.suppressPosResponse=1;
             Dcm_pMsgContext2->reqData[0] &= 0x7F;
           }
           else                
           {
             Dcm_pMsgContext2->msgAddInfo.suppressPosResponse=0;
           }
         }
         else
         {
           Dcm_pMsgContext2->msgAddInfo.suppressPosResponse=0;
         }
         
         /*get the data processor    */
         Dcm_Current_Message_Status.Dcm_DataProcessor=Dcm_ServiceIdTable[line].DCM_DATAPROCESSOR;    
                
         Dcm_NegResponse=DCM_NO_NEG_RESPONSE;/*set the negative response flag to 0 */
         /* >> anam:2010-04-07 CR 70598 */
         Dcm_NegResponseBeforeRespPending = DCM_NO_NEG_RESPONSE;
         /* << anam:2010-04-07 CR 70598 */
         /* << GAN:2008-05-28 Moved the suppression setting before the call to Rte_DcmIndication*/

       /*if the indication is configured to be called in the application as well*/
       #if (DCM_REQUEST_INDICATION_ENABLED == STD_ON )
            Diag_Status = Rte_DcmIndication( Dcm_pMsgContext2,Dcm_Current_Message_Status.Dcm_SID);
       #endif
     
       switch (Diag_Status)
           {            
              case DCM_E_OK:
             if ((!Dcm_FirstRequest)&&(Dcm_Current_Message_Status.Dcm_ActiveSession == DEFAULT_SESSION))
             {
               ComM_DCM_ActiveDiagnostic();
               Dcm_FirstRequest=1;
             }
              
               /*dispatch the processing of this service to the correct function in the data processor*/
             Dcm_ReadDiagService();
            break;
            #if DCM_REQUEST_INDICATION_ENABLED==STD_ON
              case DCM_E_REQUEST_NOT_ACCEPTED:
              case DCM_E_REQUEST_ENV_NOK:         
              case DCM_E_COMPARE_KEY_FAILED:
              case DCM_E_TI_PREPARE_LIMITS:
              case DCM_E_TI_PREPARE_INCONSISTENT:
              case DCM_E_SESSION_NOT_ALLOWED:
              case DCM_E_PROTOCOL_NOT_ALLOWED:
              case DCM_E_ROE_NOT_ACCEPTED:
              case DCM_E_PERIODICID_NOT_ACCEPTED:
          default:
             /*negative response with NRC 0x22            */
             Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_CONDITIONSNOTCORRECT);
               return;
        #endif
            }
     }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used to request a reception buffer
*
* \name Dcm_ProvideRxBuffer
*
* \b Service-Id:   0x02
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   PduIdType DcmRxPduId - the RxPduId that this request is receive with. Range 0..max number of RxPduId -1
*                  PduLengthType TpSduLength - the length of the request. This is a hint for the DSL about the size of the buffer
*                                               the request needs.
*
* \param (Output)  PduInfoType PduInfoPtr - a PduInfoType structure that shall contain, when the function is finished, the pointer
*                                         to the used buffer and the length of this buffer.
*
* \return          BufReq_ReturnType - the result of the buffer request operation.
*
* \b Description:  This function is used by the lower layer to request a buffer for the received message. Using the DcmRxPduId and the TxSduLength
*  the DSL can access all information about this reception (especially the buffer to be used). If the length of the message is larger
*  than the size of buffer to be used, DSL shall provide no buffer and the return value shall be BUFREQ_E_OVFL. If some error 
*  occured during the request the return value shall be BUFREQ_E_NOT_OK. Another case can be if the buffer is already used and therefore
*  DSL cannot give it to this request. The return value shall be BUFREQ_E_BUSY. In all of these three cases, the lower layer
*  shall not access the buffer. If all conditions are correct, the DSL shall provide in the out parameter the pointer to the buffer and
*  its length. The return value shall be BUFREQ_E_OK and the lower layer can place request data inside the buffer. Besides the buffer
*  provision, the DSL shall set in this function all required information for the correct processing of this function. The protocol start 
*  (if needed) is happening in this function and the preemption of a lower priority protocol is detected here. The DSL shall ensure that 
*  preemption timer is started, the old protocol is stopped and the correct behavior is processed (DCM_E_BUSYREPEATREQUSET negative response
*  shall be sent back). DSL shall also analyze first the communication state and see if this permits the reception.
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(BufReq_ReturnType,DCM_CODE) Dcm_ProvideRxBuffer (PduIdType DcmRxPduId,
                                         PduLengthType TpSduLength,
                                         P2VAR(P2VAR(PduInfoType,AUTOMATIC,PDUR_IPDUM_DATA),AUTOMATIC,PDUR_IPDUM_DATA) PduInfoPtr)
{
  uint8 bufferused;
  
  #if (DCM_DEV_ERROR_DETECT==STD_ON) 
  if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x02,DCM_E_UNINIT);
      return BUFREQ_E_NOT_OK;
    }
  #endif   
  /*Check the DCM communication status */
  if(Dcm_CommunicationState != DCM_NO_COMMUNICATION)
  {
    
  /*development error detection and reporting*/
  #if (DCM_DEV_ERROR_DETECT==STD_ON)
     if ((DcmRxPduId >= DCM_NUMBER_OF_DCMRXPDUID)||(PduInfoPtr==0))
     {
         Det_ReportError(DCM_MODULE_ID,0,0x02,DCM_E_PARAM);
         return BUFREQ_E_NOT_OK;
     }
    #endif 
     
     
   /*start the protocol only if the preemption is not already active*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
   if (Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement ==0)
#endif
   {
      /*if the protocol has not been started*/
    if(Dcm_Current_Message_Status.Dcm_StartProtocolStatus == 0)
      {
         /*Initialze Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId on the first protocol start */
         Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId=DcmRxPduId;
         /*call application function to start protocol*/
         if(Dcm_StartProtocol(DcmRxPduId)==FALSE)
         {
            return BUFREQ_E_NOT_OK;
         }
       }
   }
   
   bufferused=Dcm_ProtocolRxTable[DcmRxPduId].DCM_PROTOCOL_RX_BUFFER_ID;     
   /*if the length is too large*/
    if (TpSduLength > Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_SIZE)
   {            
      /*development error reporting*/
      #if (DCM_DEV_ERROR_DETECT==STD_ON)
      Det_ReportError(DCM_MODULE_ID,0,0x02,DCM_E_INTERFACE_BUFFER_OVERFLOW);
      #endif 

      return BUFREQ_E_OVFL;
   }

     /*0-length message is rejected*/
    if(TpSduLength==0x00)
     {
        return BUFREQ_E_NOT_OK;
     }
  
    if (Dcm_Current_Message_Status.Dcm_Message_Status_Busy != 0) /*if any kind of buffer is used it means the ECU is busy*/
     {
        /*check priorities*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
      if(  (Dcm_Current_Message_Status.Dcm_Active_Message_Prio - Dcm_ProtocolTable[Dcm_GetProtocolTableId(DcmRxPduId)].DCM_PROTOCOL_PRIO >0 )
         &&(Dcm_Current_Message_Status.Dcm_Busy_Repeat_Request != DCM_BUSYREPEATREQUEST  ) )
        {
         if (bufferused != Dcm_Current_Message_Status.Dcm_Message_Status_Busy-1)
         {   
            /*Store the TxPduId and the RxBuffer to send  the BusyRepeatRequest*/
            Dcm_Current_Message_Status.Dcm_TxTableIndex=Dcm_ProtocolRxTable[DcmRxPduId].DIAGNOSTIC_PROTOCOL_TX_TABLE_ID;
            Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId=Dcm_ProtocolTxTable[Dcm_Current_Message_Status.Dcm_TxTableIndex].DCM_PROTOCOL_DCMTXPDUID;          
            Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId=DcmRxPduId;
            Dcm_ptrFuncPduMessageType->SduDataPtr=Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_ADDRESS;
            Dcm_ptrFuncPduMessageType->SduLength=Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_SIZE;
            (*PduInfoPtr)=Dcm_ptrFuncPduMessageType;    
            Dcm_ConcurrentMessages=DCM_CONCURRENT_HIGH_PRIO_REQUEST;
            return BUFREQ_OK;
         }
        }
#endif
       
       /* >> GAN:2008-02-06 here test if the id is functional */
       Dcm_ConcurrentMessages=DCM_CONCURRENT_REQUEST;
       /*if the on-going Pdu is physical, and the current is functional*/
       if ((Dcm_ProtocolRxTable[Dcm_pMsgContext2->dcmRxPduId].DCM_PROTOCOL_RX_ADDR_TYPE == DCM_PHYSICAL) &&\
           (Dcm_ProtocolRxTable[DcmRxPduId].DCM_PROTOCOL_RX_ADDR_TYPE == DCM_FUNCTIONAL))
       {
         /*this means it is the functional request has been received during a physical 
           check if the buffer is different*/
         if (bufferused != Dcm_Current_Message_Status.Dcm_Message_Status_Busy-1)
         {
           Dcm_ptrFuncPduMessageType->SduDataPtr=Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_ADDRESS;
           Dcm_ptrFuncPduMessageType->SduLength=Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_SIZE;
           (*PduInfoPtr)=Dcm_ptrFuncPduMessageType;        
           return BUFREQ_OK;
         }
       }
       /* << GAN:2008-02-06 here test if the id is functional */
       return BUFREQ_E_BUSY;
     }

/* if there is only one protocol the needed protocol is always equal to the current one */
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
     /*compare the current protocol with the protocol of the incoming request
       if the current protocol is different and no processing is going on, 
       then it is ok to start the incoming protocol
       this is correct here because if the preemption mechanism would have been started 
       or if the buffer is busy then the processing would not reach this point*/
     if (Dcm_ProtocolTable[Dcm_GetProtocolTableId(Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId)].DCM_PROTOCOL_ID !=\
         Dcm_ProtocolTable[Dcm_GetProtocolTableId(DcmRxPduId)].DCM_PROTOCOL_ID)
     {
        /*start the new protocol
         call application function to start protocol*/
        if(Dcm_StartProtocol(DcmRxPduId)==FALSE)
        {
            return BUFREQ_E_NOT_OK;
        }
     }
#endif
     Dcm_ConcurrentMessages=DCM_NO_CONCURRENT_REQUEST;
     /*Id 0 shall be found in line 0 , Id 1 shall be found in line 1....*/
     Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId=DcmRxPduId;
     /*retrieve from configuration the relevant information: protocol, TxPduIndex, service table index, timing parameter     */
     Dcm_Current_Message_Status.Dcm_TxTableIndex=Dcm_ProtocolRxTable[DcmRxPduId].DIAGNOSTIC_PROTOCOL_TX_TABLE_ID;
     Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId=Dcm_ProtocolTxTable[Dcm_Current_Message_Status.Dcm_TxTableIndex].DCM_PROTOCOL_DCMTXPDUID;             
     
     /*if reaches this point buffer can be given*/
     Dcm_ptrPduMessageType->SduDataPtr=Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_ADDRESS;
     Dcm_ptrPduMessageType->SduLength=Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_SIZE;
     (*PduInfoPtr)=Dcm_ptrPduMessageType;
     Dcm_Current_Message_Status.Dcm_Message_Status_Busy=bufferused+1;    
     Dcm_pMsgContext2->reqData=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_ADDRESS + 1;
     Dcm_pMsgContext2->reqDataLen=TpSduLength-1;
     bufferused=Dcm_ProtocolTxTable[Dcm_Current_Message_Status.Dcm_TxTableIndex].DCM_PROTOCOL_TX_BUFFER_ID;
     Dcm_pMsgContext2->resMaxDataLen=Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_SIZE - 1;/*SID eliminated*/
     Dcm_pMsgContext2->resData=Dcm_DiagnosticBufferCfg[bufferused].DCM_BUFFER_ADDRESS + 1;
     /* stop the s3 timer */
     Dcm_Current_Message_Status.Dcm_S3ServerIncrement = 0;
     Dcm_Current_Message_Status.Dcm_S3ServerTimer = 0;
     /* Start Fix CR70764 */
     Dcm_pMsgContext2->dcmRxPduId=DcmRxPduId;
     /* End Fix CR70764 */
     return BUFREQ_OK;
  }
  return BUFREQ_E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used to request a transmission buffer
*
* \name Dcm_ProvideTxBuffer
*
* \b Service-Id:   0x09
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   PduIdType DcmTxPduId - the TxPduId that was used at the transmit request. The buffer request comes for that transmission.
*                  uint16 Length - this value shall be always 0. Not used by the DSL.
*
* \param (Output)  PduInfoPtr PduInfoPtr - a structure that shall contain the buffer address and the length. 
*
* \return          BufReq_ReturnType - the result of the buffer request operation.
*
* \b Description:  This function shall give a transmission buffer to the lower layer. The call of the transmission function from DSL
*  shall only inform the lower layer about a new transmission and give the total length of the message. The buffer that 
*  contains the data shall be given at the call of this function. DSL shall analyze the buffer request and give the 
*  correct return value back. If any error occured, the return value shall be BUFREQ_E_NOT_OK.In this case the buffer
*  pointer present in the out parameter shall not accessed by the lower layer. If all conditions are correct, the return 
*  value shall be BUFREQ_OK and the lower layer can transmit the message. The message can be transmitted with more than
*  one buffer (PagedBuffer processing). In that case, lower layer shall request a new buffer after the previous buffer 
*  was sent. The final confirmation shall be received only after all buffers shall be transmitted. This function shall also
*  check the communication state if it permits the transmission.
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(BufReq_ReturnType,DCM_CODE) Dcm_ProvideTxBuffer(PduIdType DcmTxPduId,
                                                P2VAR(P2VAR(PduInfoType,AUTOMATIC,PDUR_IPDUM_DATA),AUTOMATIC,PDUR_IPDUM_DATA) PduInfoPtr,
                                                PduLengthType Length)
{
  P2CONST(Dcm_DiagnosticBufferCgfType,AUTOMATIC,DCM_CONST) ptrDiagBufferCfg;
    
  #if (DCM_DEV_ERROR_DETECT==STD_ON) 
  if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x09,DCM_E_UNINIT);
      return BUFREQ_E_NOT_OK;
    }
  #endif   
  
    /*Check the DCM communication status */
  if(Dcm_CommunicationState ==DCM_FULL_COMMUNICATION)
  {
     /*detection of development errors*/
   #if (DCM_DEV_ERROR_DETECT==STD_ON)
    if (PduInfoPtr==0)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x04,DCM_E_PARAM);
      return BUFREQ_E_NOT_OK;
    }
    if (DcmTxPduId!=Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x04,DCM_E_PARAM);
      return BUFREQ_E_NOT_OK;
    }
   #endif
     /*if PagedBuffer processing is in progress */
     #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
     if (Dcm_PagedBufferFlag)
     {                             
        /*if the PagedBuffer was cancelled*/
            if (Dcm_PagedBufferFlag==2)
            {
              Dcm_PagedBufferFlag=0;
              Dcm_PagedBufferService=0;
              Dcm_LengthSoFar=0;
              Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=0;
              Dcm_PagedBufferLength=0;
              Dcm_PageProcessed=0;
              Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;               
              Dcm_Current_Message_Status.Dcm_PagedBufferTimer = 0;
              Dcm_Current_Message_Status.Dcm_PagedBufferIncrement = 0;
              return BUFREQ_E_NOT_OK;
            }                                           
            
            /*the buffer address shall be filled with the call of UpdatePage in the data processor*/
            if (!Dcm_PageProcessed)
            {                       
              if (Dcm_Current_Message_Status.Dcm_DataProcessor==DCM_DSP)
              {
                Dcm_PageProcessed=2; 
                
                Dsp_DcmUpdatePage(&Dcm_ptrPduMessageType->SduDataPtr[0],Dcm_PagedBufferLength);/*to also include the SID byte              */
               
                Dcm_PageProcessed=3;
              }
              if (Dcm_Current_Message_Status.Dcm_DataProcessor==DCM_RTE)
              {
                Dcm_PageProcessed=2;

                Rte_DcmUpdatePage(&Dcm_ptrPduMessageType->SduDataPtr[0],Dcm_PagedBufferLength);/*also include the first byte               */
              }
            }

      /*if ProcessPage was called, give the buffer*/
            if (Dcm_PageProcessed==1)
            {             
              /*reset the PagedBuffer timer and increment 
                here fill the response data length
              buffer pointer is completed by the UpdatePage*/
            /* >> GAN:2008-08-13 Added special check to fix length*/
            if ((Dcm_FirstUpdatePage)&&(Dcm_Current_Message_Status.Dcm_DataProcessor==DCM_RTE))
            {
              Dcm_FirstUpdatePage=0;
              Dcm_FilledPageLength++; /*to include also the first SID byte*/
              Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen--; /*also substract from the length of the message*/
            }
            /* << GAN:2008-08-13 Added special check to fix length*/
            /* >> GAN:2008-08-13 Set the length of the page correctly*/
            Dcm_ptrPduMessageType->SduLength=Dcm_FilledPageLength;
            /* << GAN:2008-08-13 Set the length of the page correctly*/
            /* >> GAN:2008-08-13 Only check that is required here*/
            if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen == 0) 
            {
              Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;      
            }
            /* << GAN:2008-08-13 Only check that is required here*/
            
              Dcm_Current_Message_Status.Dcm_PagedBufferTimer = 0;
              Dcm_Current_Message_Status.Dcm_PagedBufferIncrement = DCM_TASK_TIME;              
              (*PduInfoPtr)=Dcm_ptrPduMessageType;
              Dcm_PageProcessed=0;
              return BUFREQ_OK;
            }
            else
            {
              /*if the page is not yet processed, give busy to the buffer request*/
              return BUFREQ_E_BUSY;
            }               
     }       
     #endif

   /* >> GAN:2008-08-19 Added the buffer setting*/
   if (Dcm_NegResponse)
   {
     if (Dcm_NegResponse==DCM_RESPONSE_PENDING_OR_BUSY)
       Dcm_ptrPduMessageType->SduDataPtr=&Dcm_NegResponseBuffer[0];
     else
       Dcm_ptrPduMessageType->SduDataPtr=Dcm_pMsgContext2->resData;
     Dcm_ptrPduMessageType->SduLength=3;
   }
   else
   {
     Dcm_ptrPduMessageType->SduDataPtr=Dcm_pMsgContext2->resData - 1;
     Dcm_ptrPduMessageType->SduLength=Dcm_pMsgContext2->resDataLen + 1;
   }
   /* << GAN:2008-08-19 Added the buffer setting*/
   /*if no PagedBuffer processing is used*/
   (*PduInfoPtr)=Dcm_ptrPduMessageType;
   
   /*if the response is from DiagnosticSessionChange, save the session value for further processing*/
   if (Dcm_ptrPduMessageType->SduDataPtr[0]==0x50)
   {
     /*diagnosticsessioncontrol positive response*/
     Dcm_SessionChange=Dcm_ptrPduMessageType->SduDataPtr[1]; /*value of the new session*/
   }
   
     /* >> GAN:2008-02-05 Rework due to new way of detecting negative responses
     special processing in case of NRC 0x78 and 0x21*/
   if (Dcm_NegResponse)
   {
     Dcm_Confirmation=DCM_RES_NEG_OK;   
     ptrDiagBufferCfg=&Dcm_DiagnosticBufferCfg[Dcm_ProtocolTxTable[Dcm_Current_Message_Status.Dcm_TxTableIndex].DCM_PROTOCOL_TX_BUFFER_ID];
     if ((Dcm_ptrPduMessageType->SduDataPtr[2]==DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING))
     {
        Dcm_KindOfMessage=DCM_RESPONSE_PENDING_MESSAGE;
        /*reset the buffer normally used...this is for the case when the 0x78 NR is used or 0x21       */
        Dcm_pMsgContext2->resMaxDataLen=ptrDiagBufferCfg->DCM_BUFFER_SIZE-1;
        Dcm_pMsgContext2->resData=ptrDiagBufferCfg->DCM_BUFFER_ADDRESS+1;
     }
     if ((Dcm_ptrPduMessageType->SduDataPtr[2]==DCM_E_BUSYREPEATREQUEST))
     {
       Dcm_KindOfMessage=DCM_BUSY_REPEAT_MESSAGE;
       /*set the buffer to the one used only if the response from the preempted protocol has arrived and ignored
         or if the preempt timer expired  */
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
       if (Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement!=0)
       {
          Dcm_pMsgContext2->resMaxDataLen=ptrDiagBufferCfg->DCM_BUFFER_SIZE-1;
          Dcm_pMsgContext2->resData=ptrDiagBufferCfg->DCM_BUFFER_ADDRESS+1;
       }
#endif
     }
     /* >> GAN:2008-03-06 Dcm_NegResponse can be made 0 now*/
     Dcm_NegResponse=DCM_NO_NEG_RESPONSE;
     /* << GAN:2008-03-06 Dcm_NegResponse can be made 0 now*/
   }
   else
   {
       Dcm_Confirmation=DCM_RES_POS_OK;
   }     
     /* << GAN:2008-02-05 Rework due to new way of detecting negative responses*/
   return BUFREQ_OK;
  }
  
 return BUFREQ_E_NOT_OK;  
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used to confirm a trasmission
*
* \name Dcm_TxConfirmation
*
* \b Service-Id:   0x05
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   PduIdType DcmTxPduId - the TxPduId that this confirmation has been received for
*                                    NotifResultType Result - the result of the transmission 
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function is function is called by lower layer to confirm a transmission. The result of this transmission
*  is given by parameter Result: if it is NTFRSLT_OK, the transmission ended correctly, if it is 
*  NTFRSLT_E_NOT_OK, the transmission failed. No information about the reason of failure shall be received.
*  This function is also responsible for reseting the timer ans other variables of the DCM module so that 
*  another reception or transmission that follows is processed correctly. This confirmation has to be
*  forwarded to the data processor as well. Because the ISO documents specify it this way, the setting of the
*  new session level and the new timing values shall be done in this function (these processing shall be done
*  only after the confirmation for the respective response message has been received. e.g. after a request
*  of service DiagnosticSessionControl, the response message has to be sent and when the confirmation to this
*  message arrives, only then the session needs to be changed).
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_TxConfirmation(PduIdType DcmTxPduId, NotifResultType Result)
{    
    uint8 i;
#if (DCM_DEV_ERROR_DETECT==STD_ON) 
    uint8 index;

   if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x05,DCM_E_UNINIT);
      return;
    }
    
   index=0xFF;
    for (i=0;i<DCM_NUMBER_OF_DCMTXPDUID;i++)
    {
      if (Dcm_ProtocolTxTable[i].DCM_PROTOCOL_DCMTXPDUID==DcmTxPduId)
      {
        index=i;
      }
    }
    
    if (index==0xFF)
      {
        Det_ReportError(DCM_MODULE_ID,0,0x05,DCM_E_PARAM);
      }
#endif

    for (i=Dcm_Current_Message_Status.Dcm_TxTableIndex+1;i<DCM_NUMBER_OF_DCMTXPDUID;i++)
    {
       if (Dcm_ProtocolTxTable[i].DCM_PROTOCOL_DCMRXPDU_INDEX==Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId)
       {
         /*here at once*/
         Dcm_Current_Message_Status.Dcm_Transmission=DCM_READY_TO_SEND;
         /*transmit always*/
         
         Dcm_Current_Message_Status.Dcm_TxTableIndex=i;
         Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId=Dcm_ProtocolTxTable[i].DCM_PROTOCOL_DCMTXPDUID;         
         Dcm_Current_Message_Status.Dcm_NormalResponseTimer=Dcm_CurrentTimingParameter.DCM_TIMSTR_P2SERVER_MIN;
         Dcm_Current_Message_Status.Dcm_NormalResponseIncrement=DCM_TASK_TIME;
         /*exists another TxPdu*/
         return;
       }
    }
            
    /*if the confirmation is negative, set the status to the correct value */
    if (Result!=NTFRSLT_OK)
    {
       Dcm_Confirmation++;
    }
    
    /*confirmation in case of PagedBuffer processing*/
    #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (Dcm_Current_Message_Status.Dcm_PagedBufferIncrement!=0)
    {
      /*this confirmation can be received only after a transmission was successful
        if the transmission that has just finished was a pagedbuffer, then reset timer and set increment to 0
        because this timer must not be active any more.*/
      Dcm_Current_Message_Status.Dcm_PagedBufferIncrement=0;
      Dcm_Current_Message_Status.Dcm_PagedBufferTimer=0;      
      Dcm_PagedBufferFlag=0;
      Dcm_PagedBufferService=0;
    }
    #endif

   /*send confirmation to the data processor*/
   if (Dcm_Current_Message_Status.Dcm_DataProcessor==DCM_DSP)
   {
      /*only call the confirmation if no busy repeat request and no normal reponse pending
        these two messages are sent independently by DCM so none of the data processors is aware of the sending
        an exception to this case is the forced response pending, which has to be confirmed using the funciton above*/
      if (DCM_NO_BUSY_OR_PENDING_MESSAGE == Dcm_KindOfMessage)
      { 
        Dsp_DcmConfirmation(Dcm_pMsgContext2->idContext,Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId,Dcm_Confirmation);
        /* >> GAN:2008-02-04 also call confirmation of the RTE*/
        Rte_DcmConfirmation(Dcm_pMsgContext2->idContext,Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId,Dcm_Confirmation);
        /* << GAN:2008-02-04 also call confirmation of the RTE*/
      }
     /* << GAN:2007-09-06 confimation to be sent depending if the message was a forced RespPend or not*/
   } else /* DCM_RTE */
   {
     /* >> GAN:2007-09-06 confirmation to be sent depending if the message was a forced RespPend or not*/
     if (DCM_FORCED_RESPONSE_PENDING == Dcm_Current_Message_Status.Dcm_ForcedRespPend)
     {      
      DCM_CONFRESPPEND_FUNCTIONPTR(Dcm_Confirmation);
     }
     else
     {
        /*only call the confirmation if no busy repeat request and no normal reponse pending
          these two messages are sent independently by DCM so none of the data processors is aware of the sending
          an exception to this case is the forced response pending, which has to be confirmed using the funciton above*/
        if (DCM_NO_BUSY_OR_PENDING_MESSAGE == Dcm_KindOfMessage)
        Rte_DcmConfirmation(Dcm_pMsgContext2->idContext,Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId,Dcm_Confirmation);
     }
      
     /* << GAN:2007-09-06 confirmation to be sent depending if the message was a forced RespPend or not*/
   }
   /*reset the forced response pending message*/
   Dcm_Current_Message_Status.Dcm_ForcedRespPend=DCM_NO_RESPONSE_PENDING; 

   /*if the message sent was a negative response with NRC=0x78 then the processing is not yet finished so the 
     buffer busy status cannot be cleared*/
   if (DCM_NO_BUSY_OR_PENDING_MESSAGE != Dcm_KindOfMessage)
   {
      /*in case of busy repeat request, the buffer has to be cleared because another request is awaited for this*/
      if (DCM_BUSY_REPEAT_MESSAGE == Dcm_KindOfMessage)
      {
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
         /*if a high prio request has arrived while a low prio request is still running*/
         if(Dcm_ConcurrentMessages==DCM_CONCURRENT_HIGH_PRIO_REQUEST)
         {
            Dcm_ConcurrentMessages=DCM_NO_CONCURRENT_REQUEST;
            /* the low prio request is still processed so the buffer stays busy*/
         }
         else
#endif
         {
            Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0; /*un-busy the buffer*/
         }
      }
      if (DCM_RESPONSE_PENDING_MESSAGE == Dcm_KindOfMessage)
         Dcm_Current_Message_Status.Dcm_BusyProcessingIncrement=DCM_TASK_TIME;
      /*in any other case the buffer busy can be cleared and the kind of message is not relevant*/
      Dcm_KindOfMessage=DCM_NO_BUSY_OR_PENDING_MESSAGE;
      Dcm_Current_Message_Status.Dcm_S3ServerTimer=0;/*reset timer*/
   }
   else
   {
      Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;

      /*normal timer should not be active any more*/
      Dcm_ResetNormalAndBusyTimers();
      
      if( DEFAULT_SESSION == Dcm_Current_Message_Status.Dcm_ActiveSession )
      {
          ComM_DCM_InactiveDiagnostic();
      }
      /* start the s3 Timer when in non default session
         or transission to non default session is requested*/
      if(  (  (DEFAULT_SESSION != Dcm_SessionChange)
            &&(0xFF != Dcm_SessionChange))
         ||(  (DEFAULT_SESSION != Dcm_Current_Message_Status.Dcm_ActiveSession)
            &&(0xFF == Dcm_SessionChange)))
      {
        Dcm_Current_Message_Status.Dcm_S3ServerIncrement = DCM_TASK_TIME;
        Dcm_Current_Message_Status.Dcm_S3ServerTimer = 0;
      }
      Dcm_KindOfMessage = DCM_NO_BUSY_OR_PENDING_MESSAGE;
   }
   
   /*here the setting of the new session is happened.*/
   if (Dcm_SessionChange!=0xFF)
   {     
Dcm_SetSesCtrlType(Dcm_SessionChange);
           
     Dcm_SessionChange=0xFF;     
   }
   
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))   
   /*set the new timing parameters after call of AccessTimingParameter service       */
   if (Dcm_NewTimingValues!=0)
   {
     /*new values for the timing parameters have to be set*/
     Dcm_SetSesTimingValues(Dcm_NewTimingValues);
     Dcm_NewTimingValues=0;
   }
#endif   
   
   /* GAN:2008-11-11 Added extra check: reset negative flag only in case of NRC = 0x78 and 0x21*/
   if (Dcm_NegResponse==DCM_RESPONSE_PENDING_OR_BUSY)
     Dcm_NegResponse=DCM_NO_NEG_RESPONSE;
   /* GAN:2008-11-11 If the confirmation is received later, leave the negative flag as it is because it is needed for the pending transmission*/
   if (Dcm_WaitForConfirmation != DCM_WAIT_FOR_CONFIRMATION)
     Dcm_NegResponse=DCM_NO_NEG_RESPONSE;
   else
   {
     /* >> GAN:2008-11-18 Fixed wrong transmission on FlexRay*/
     if (Dcm_TempNegResponse == 1)
     {
       Dcm_NegResponse=DCM_NEG_RESPONSE;
       Dcm_Current_Message_Status.Dcm_Transmission = DCM_READY_TO_SEND;
     }
     if (Dcm_TempNegResponse == 2)
     {
       Dcm_NegResponse=DCM_NO_NEG_RESPONSE;
       Dcm_ptrPduMessageType->SduLength=Dcm_pMsgContext2->resDataLen + 1;
       Dcm_Current_Message_Status.Dcm_Transmission = DCM_READY_TO_SEND;
     }
     Dcm_TempNegResponse=0;     
     /* << GAN:2008-11-18 Fixed wrong transmission on FlexRay*/
   }
   
   /*here make the WaitForConfirmation 0*/
   if (Dcm_Current_Message_Status.Dcm_Transmission == DCM_READY_TO_SEND)
   {
     if (Dcm_WaitForConfirmation == DCM_WAIT_FOR_CONFIRMATION)
       Dcm_WaitForConfirmation = DCM_CONFIRAMTION_ARRIVED; /* This means confirmation has arrived and the message can be sent*/
   }
   else
   {
     /* this is because the timer has to be started again*/
     if (Dcm_WaitForConfirmation == DCM_WAIT_FOR_CONFIRMATION)
       Dcm_Current_Message_Status.Dcm_BusyProcessingIncrement = DCM_TASK_TIME;
     Dcm_WaitForConfirmation=DCM_NO_CONFIRMATION_WAIT;
   }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used to handle the periodical responses based on PeriodicId
*
* \name Dcm_ResponseOnOneDataByPeriodicId
*
* \b Service-Id:   0x11
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   uint8 PeriodicId - the Periodic Id used by this function
*
* \param (Output)  none
*
* \return          Dcm_StatusType - the acceptance or rejection of the Periodic transmission
*
* \b Description:  This function is used to send a message periodically. The DSL shall simulate a request of service 0x22 
*  ReadDataByIdentifier. The DSL needs to check some conditions to see if the processing is accepted or not.
*  If not accepted, the return value shall be DCM_E_PERIODICID_NOT_ACCEPTED. If all conditions are passed, the 
*  value returned by the function is DCM_E_OK. By the return from this function, the function that processes 
*  this service shall already be called. 
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(Dcm_StatusType,DCM_CODE) Dcm_ResponseOnOneDataByPeriodicId(uint8 PeriodicId)
{   
 #if DCM_PERIODIC_TRANS_ENABLED==STD_ON
  Dcm_StatusType Diag_Status;  
  uint8 line;
  
  #if (DCM_DEV_ERROR_DETECT==STD_ON) 
   if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x11,DCM_E_UNINIT);
      return DCM_E_PERIODICID_NOT_ACCEPTED;
    }
   #endif  
  
  /*Check the DCM communication status*/
  if(Dcm_CommunicationState == DCM_FULL_COMMUNICATION)
  {
   
    if(Dcm_Current_Message_Status.Dcm_Message_Status_Busy !=0) /*if any kind of processing is currently running do not accept the PERIODIC*/
    {
      return DCM_E_PERIODICID_NOT_ACCEPTED;
    }
     else
     {
      /*set the PERIODIC TRANS buffer to busy*/
      Dcm_Current_Message_Status.Dcm_Message_Status_Busy=DCM_PERIODIC_TRANS_TX_BUFFER_ID+1;
     }
     
     /*Inform ComManager about the need to stay in full comunication mode*/
     if ((!Dcm_FirstRequest)&&(Dcm_Current_Message_Status.Dcm_ActiveSession == DEFAULT_SESSION))
    {
      ComM_DCM_ActiveDiagnostic();
      Dcm_FirstRequest=1;
    }
    if(DEFAULT_SESSION != Dcm_Current_Message_Status.Dcm_ActiveSession)
    {
       Dcm_Current_Message_Status.Dcm_S3ServerTimer = 0;
       Dcm_Current_Message_Status.Dcm_S3ServerIncrement = DCM_TASK_TIME;
    }
        
    /*Save SID for ReadDataByIdentifier service 0x22  */
    Dcm_Current_Message_Status.Dcm_SID=0x22;
       
    /*The RxPduId shall be used the current one for the protocol     */
     if(DCM_PERIODIC_TRANS_TYPE==TYPE1)
     {     
       /*this is the Tx of the protocol*/
       Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId=Dcm_ProtocolTxTable[Dcm_ProtocolRxTable[Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId].DIAGNOSTIC_PROTOCOL_TX_TABLE_ID].DCM_PROTOCOL_DCMTXPDUID;
               
       /*Get Dcm_TxTableIndex from Dcm_ProtocolTable*/
         Dcm_Current_Message_Status.Dcm_TxTableIndex=Dcm_ProtocolRxTable[Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId].DIAGNOSTIC_PROTOCOL_TX_TABLE_ID;
     }
     
     if(DCM_PERIODIC_TRANS_TYPE==TYPE2)
     {         
        /*Responses are sent on separate DcmTxPduId ->DCM_PERIODIC_TRANS_DCMTXPDUID*/
         Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId=DCM_PERIODIC_TRANS_DCMTXPDUID;
         /*RxPdu is used the current*/
     }
         
    /*CREATE RESPONSE MESSAGE*/        
    /*always current protocol shall be used*/
    Dcm_pMsgContext2->reqData=Dcm_DiagnosticBufferCfg[DCM_PERIODIC_TRANS_TX_BUFFER_ID].DCM_BUFFER_ADDRESS+1;
    Dcm_pMsgContext2->dcmRxPduId=Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId;
    Dcm_pMsgContext2->idContext=0x2A;
    Dcm_pMsgContext2->reqDataLen=2;
    Dcm_pMsgContext2->resData=Dcm_DiagnosticBufferCfg[DCM_PERIODIC_TRANS_TX_BUFFER_ID].DCM_BUFFER_ADDRESS + 1;
    
    Dcm_pMsgContext2->resMaxDataLen=Dcm_DiagnosticBufferCfg[DCM_PERIODIC_TRANS_TX_BUFFER_ID].DCM_BUFFER_SIZE - 1;
    
    /*For the ReadDataByPeriodicIdentifier (SID=0x2A) service
      the ReadDataByIdentifier service (SID=0x22) is executed */
    /*calculation of the line in the service table where the function is located*/
    line = Dcm_GetServiceTableIndex(0x22);
    
    if (line==SNSID)
    {
        /*service not supported*/
        Dcm_Current_Message_Status.Dcm_Message_Status_Busy = 0;
        /*the return value is ok because the periodic processing is ok, only the service is not supported*/
        return DCM_E_PERIODICID_NOT_ACCEPTED;
   }
        
    Dcm_Current_Message_Status.Dcm_DataProcessor=Dcm_ServiceIdTable[line].DCM_DATAPROCESSOR;
    
    /*Simulate a ReadDataByIdentifier service SID=0x22 */
    Dcm_pMsgContext2->reqData[0]=0xF2;
    Dcm_pMsgContext2->reqData[1]=PeriodicId;

   Diag_Status=DCM_E_OK;

   /*addressing type*/
    Dcm_SetReqType();
                
   /*sub-function availability and suppression   */
   /*>>GAN:2009-09-10 PeriodicId service 0x22 cannot be suppressed*/
   Dcm_pMsgContext2->msgAddInfo.suppressPosResponse=0;
                
  /*Indication to RTE about a successfull reception of a new request*/
  #if (DCM_REQUEST_INDICATION_ENABLED == STD_ON )
      Diag_Status = Rte_DcmIndication(Dcm_pMsgContext2,0x22);     
  #endif
  
  switch (Diag_Status)
    {
        case DCM_E_OK:         
             Dcm_ReadDiagService();
             break;
             #if DCM_REQUEST_INDICATION_ENABLED==STD_ON
        case DCM_E_REQUEST_NOT_ACCEPTED:
            /*the request is not accepted*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
            Dcm_Current_Message_Status.Dcm_Active_Message_Prio           = 0xFF; /*no priority         */
#endif
            Dcm_ResetTimers();
            #if DCM_PAGEDBUFFER_ENABLED==STD_ON
            Dcm_Current_Message_Status.Dcm_PagedBufferTimer=0;
            Dcm_Current_Message_Status.Dcm_PagedBufferIncrement=0;
            #endif 
#if (DCM_NUMBER_OF_PROTOCOLS != 1) 
            Dcm_Current_Message_Status.Dcm_ProtocolPreemptTimer=0;
            Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement=0;   
#endif
            Dcm_Current_Message_Status.Dcm_SecurityAccessTimer=0;
            Dcm_Current_Message_Status.Dcm_SecurityAccessIncrement=0;
            
            return DCM_E_PERIODICID_NOT_ACCEPTED;
            break;
        case DCM_E_REQUEST_ENV_NOK: 
      case DCM_E_COMPARE_KEY_FAILED:
        case DCM_E_TI_PREPARE_LIMITS:
        case DCM_E_TI_PREPARE_INCONSISTENT:
        case DCM_E_SESSION_NOT_ALLOWED:
        case DCM_E_PROTOCOL_NOT_ALLOWED:
        case DCM_E_ROE_NOT_ACCEPTED:
        case DCM_E_PERIODICID_NOT_ACCEPTED:
     default:
             Dcm_Current_Message_Status.Dcm_Message_Status_Busy = 0;
             return DCM_E_PERIODICID_NOT_ACCEPTED;
         break;  
      #endif
   }
   /*Indicate a periodic transmission so the correct Service ID is set in Dcm_ProcessingDone*/
   Dcm_PeriodicIdTransmission=TRUE;
   return DCM_E_OK;  
 }
 #endif
 return DCM_E_PERIODICID_NOT_ACCEPTED;  
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used to handle the response on one event
*
* \name Dcm_ResponseOnOneEvent
*
* \b Service-Id:   0x10
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   Dcm_MsgType MsgPtr - this is the pointer to the request that has to be simulated
*                  Dcm_MsgLenType MsgLen - length of the simulated request
*                  PduIdType DcmRxPduId - the RxPduId that has to be used in case TYPE1 transmission
*
* \param (Output)  none
*
* \return          Dcm_StatusType - the acceptance or rejection of the response on event mechanism
*
* \b Description:  This function implements the ResponseOnOneEvent functionality. The Application shall call this function
*  when wants to sent a response based on one event. The behavior in case of events shall be defined by
*  services ResponseOnEvent (0x86) that shall register the event and the response needed. The DSL shall 
*  analyze conditions and accept or reject the processing. The function shall receive as parameter the data
*  and the length of the request.
*/
#define DCM_START_SEC_CODE
#include "MemMap.h" 
FUNC(Dcm_StatusType,DCM_CODE) Dcm_ResponseOnOneEvent    (Dcm_MsgType MsgPtr,
                                       Dcm_MsgLenType MsgLen,
                                       PduIdType DcmRxPduId)
{

 #if DCM_ROE_ENABLED==STD_ON
  Dcm_StatusType Diag_Status;
  uint8 i;
  uint8 line;
  
  #if (DCM_DEV_ERROR_DETECT==STD_ON) 
   if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x10,DCM_E_UNINIT);
      return DCM_E_ROE_NOT_ACCEPTED;
    }
  #endif  
  /*Check the DCM communication status*/
  if(Dcm_CommunicationState == DCM_FULL_COMMUNICATION)
  {
     
     /*If ROE is not enabled, return ROE not accepted*/
     if (DCM_ROE_ENABLED != STD_ON)
     {
       return DCM_E_ROE_NOT_ACCEPTED;
     }
     
     /*DEVELOPMENT ERROR DETECTION*/
    #if(DCM_DEV_ERROR_DETECT == STD_ON)
   /*Check message pointer if null, check message length if null, check if the DxmRxPduId is valid*/
   if ((MsgPtr == 0)||(MsgLen==0)||((DCM_ROE_TRANS_TYPE==TYPE1) && (DcmRxPduId>=DCM_NUMBER_OF_DCMRXPDUID)))
   {
     Det_ReportError(DCM_MODULE_ID,0,10,DCM_E_PARAM); 
     return DCM_E_ROE_NOT_ACCEPTED;
   }  
   #endif
   
   /*Check if the ROE buffer is already in use*/
   if(Dcm_Current_Message_Status.Dcm_Message_Status_Busy !=0) /*if any kind of processing is currently running, do not accept the ROE*/
   {
     return DCM_E_ROE_NOT_ACCEPTED;
   }
   else
   {
    /*set the ROE buffer to busy*/
    Dcm_Current_Message_Status.Dcm_Message_Status_Busy=DCM_ROE_TX_BUFFER_ID+1;
   }
     
   if ((!Dcm_FirstRequest)&&(Dcm_Current_Message_Status.Dcm_ActiveSession == DEFAULT_SESSION))
   {
     ComM_DCM_ActiveDiagnostic();
     Dcm_FirstRequest=1;
   }
   if(DEFAULT_SESSION != Dcm_Current_Message_Status.Dcm_ActiveSession)
   {
      Dcm_Current_Message_Status.Dcm_S3ServerTimer = 0;
      Dcm_Current_Message_Status.Dcm_S3ServerIncrement = DCM_TASK_TIME;
   }

   /*Save the SID of the message*/
   Dcm_Current_Message_Status.Dcm_SID=MsgPtr[0];

   /* if there is only one protocol the needed protocol is always equal to the current one */
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
    /*if the protocol needed is not equal to the current one (at this point the current protocol is already determined not to be busy)*/
    if (Dcm_ProtocolTable[Dcm_GetProtocolTableId(Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId)].DCM_PROTOCOL_ID !=\
     Dcm_ProtocolTable[Dcm_GetProtocolTableId(DcmRxPduId)].DCM_PROTOCOL_ID)
    {
        /*start the new protocol
         call application function to start protocol*/
        if(Dcm_StartProtocol(DcmRxPduId)==FALSE)
        {
           Dcm_Current_Message_Status.Dcm_Message_Status_Busy = 0; 
           return DCM_E_ROE_NOT_ACCEPTED;
        }
    }
#endif

   /* t.r. fixed due ticket #21916 */
   Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId=DcmRxPduId;

   Dcm_Current_Message_Status.Dcm_ProtocolTableIndex=Dcm_GetProtocolTableId(DcmRxPduId);
   Dcm_Current_Message_Status.Dcm_TxTableIndex=Dcm_ProtocolRxTable[Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId].DIAGNOSTIC_PROTOCOL_TX_TABLE_ID;
   Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId=Dcm_ProtocolTxTable[Dcm_Current_Message_Status.Dcm_TxTableIndex].DCM_PROTOCOL_DCMTXPDUID;     
   /*>>GAN:2009-09-10 always check for the protocol situation*/
   
    if(DCM_ROE_TRANS_TYPE==TYPE2)
    {        
        /*Responses are sent on separate DcmTxPduId ->DCM_ROE_DCMTXPDUID*/
        Dcm_Current_Message_Status.Dcm_Message_DcmTxPduId=DCM_ROE_DCMTXPDUID;                        
    }
     
    /*CREATE RESPONSE MESSAGE*/                 
    /*this is correct because default value for priority is 0xFF. Any configured value for priority shall be smaller than 0xFF*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
    if (Dcm_Current_Message_Status.Dcm_Active_Message_Prio < Dcm_ProtocolTable[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_PROTOCOL_PRIO)  
    {
       Dcm_Current_Message_Status.Dcm_Message_Status_Busy = 0; 
       return DCM_E_ROE_NOT_ACCEPTED;
    }
    
    Dcm_Current_Message_Status.Dcm_Active_Message_Prio=Dcm_ProtocolTable[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_PROTOCOL_PRIO;
#endif
    Dcm_pMsgContext2->reqData=Dcm_DiagnosticBufferCfg[DCM_ROE_TX_BUFFER_ID].DCM_BUFFER_ADDRESS+1;
    Dcm_pMsgContext2->dcmRxPduId=Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId;
    Dcm_pMsgContext2->idContext=Dcm_Current_Message_Status.Dcm_SID;
    Dcm_pMsgContext2->reqDataLen=MsgLen-1;
    Dcm_pMsgContext2->resData=Dcm_DiagnosticBufferCfg[DCM_ROE_TX_BUFFER_ID].DCM_BUFFER_ADDRESS + 1;
    
    Dcm_pMsgContext2->resMaxDataLen=Dcm_DiagnosticBufferCfg[DCM_ROE_TX_BUFFER_ID].DCM_BUFFER_SIZE - 1;
    
    /*calculation of the line in the service table where the function is located*/
    line = Dcm_GetServiceTableIndex(Dcm_Current_Message_Status.Dcm_SID);
    
    if (line==SNSID)
   {
     /*>>GAN:2009-09-10 No negative response, just reject the ROE*/
      /*the ROE is accepted but the service is not supported.*/
      Dcm_Current_Message_Status.Dcm_Message_Status_Busy = 0;
      return DCM_E_ROE_NOT_ACCEPTED;
      /*<<GAN:2009-09-10 No negative response, just reject the ROE*/
   }    
    
    Dcm_Current_Message_Status.Dcm_DataProcessor=Dcm_ServiceIdTable[line].DCM_DATAPROCESSOR;
    
    /*copy the message in the ROE buffer*/
    for(i=1;i<MsgLen;i++)
    {
        Dcm_pMsgContext2->reqData[i-1]=MsgPtr[i]; 
    }

    Diag_Status=DCM_E_OK;

    /*addressing type*/
    Dcm_SetReqType();
    
    /*sub-function support and supression   */
    if (Dcm_ServiceIdTable[line].DCM_SIDTAB_SUBFUNC_AVAIL)
    {
      if (Dcm_pMsgContext2->reqData[0] & 0x80)
      {
        Dcm_pMsgContext2->msgAddInfo.suppressPosResponse=1;
        Dcm_pMsgContext2->reqData[0] &= 0x7F;
      }
      else
      {                  
        Dcm_pMsgContext2->msgAddInfo.suppressPosResponse=0;
      }
    }
    else
    {
      Dcm_pMsgContext2->msgAddInfo.suppressPosResponse=0;
    }
                
  /*Indication to RTE about a succeful reception of a new request*/
  #if (DCM_REQUEST_INDICATION_ENABLED == STD_ON )
      Diag_Status = Rte_DcmIndication(Dcm_pMsgContext2,Dcm_Current_Message_Status.Dcm_SID);       
  #endif
  
  switch (Diag_Status)
    {
        case DCM_E_OK:
             Dcm_ReadDiagService();
        break;
        #if DCM_REQUEST_INDICATION_ENABLED==STD_ON
        case DCM_E_REQUEST_NOT_ACCEPTED:
        
             /*the request is not accepted*/
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
            Dcm_Current_Message_Status.Dcm_Active_Message_Prio           = 0xFF; /*no priority         */
#endif
            Dcm_ResetTimers();
            #if DCM_PAGEDBUFFER_ENABLED==STD_ON
            Dcm_Current_Message_Status.Dcm_PagedBufferTimer=0;
            Dcm_Current_Message_Status.Dcm_PagedBufferIncrement=0;
            #endif  
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
            Dcm_Current_Message_Status.Dcm_ProtocolPreemptTimer=0;
            Dcm_Current_Message_Status.Dcm_ProtocolPreemptIncrement=0;   
#endif
            Dcm_Current_Message_Status.Dcm_SecurityAccessTimer=0;
            Dcm_Current_Message_Status.Dcm_SecurityAccessIncrement=0;

            return DCM_E_ROE_NOT_ACCEPTED;
            
        case DCM_E_REQUEST_ENV_NOK:       
        case DCM_E_COMPARE_KEY_FAILED:
        case DCM_E_TI_PREPARE_LIMITS:
        case DCM_E_TI_PREPARE_INCONSISTENT:
        case DCM_E_SESSION_NOT_ALLOWED:
        case DCM_E_PROTOCOL_NOT_ALLOWED:
        case DCM_E_ROE_NOT_ACCEPTED:
        case DCM_E_PERIODICID_NOT_ACCEPTED:
     default:
            /*negative response with NRC 0x22*/
            /*>>GAN:2009-09-10 No negative response, just reject the ROE*/            
             Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;
             /*<<GAN:2009-09-10 No negative response, just reject the ROE*/
             return DCM_E_ROE_NOT_ACCEPTED;
      #endif  
  }/*from switch*/
  
 return DCM_E_OK;  
 }    
#endif 
return DCM_E_ROE_NOT_ACCEPTED;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used to force the sending of a response pending message (BMW specific)
*
* \name Dcm_ForceRespPend
*
* \b Service-Id:   0x40
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
* \b Description:  This function will send the response pending message earlier than the P2 or P2star minimum timer expires.
* 
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ForceRespPend(void)
{
  #if DCM_DEV_ERROR_DETECT==STD_ON 
  /*re-entrancy check*/
  if ((Dcm_DslReentrancy & 0x10)==0x00)
  {    
    Dcm_DslReentrancy|=0x10;/*set as entry  */
  #endif
    /*check if service is processing and the response should be assembled at the moment */
    if (Dcm_Current_Message_Status.Dcm_Message_Status_Busy != 0) 
    {
      if (Dcm_Current_Message_Status.Dcm_NumberRespPend < DCM_NUM_MAX_RESPPEND)
      {
        if(DCM_NO_RESPONSE_PENDING == Dcm_Current_Message_Status.Dcm_ForcedRespPend)
        {
           Dcm_Current_Message_Status.Dcm_ForcedRespPend=DCM_FORCED_RESPONSE_PENDING;
           /*this can be processed - just set the negative response message*/
           Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING);
           /*increase the number of RCR-RP messages*/
           Dcm_Current_Message_Status.Dcm_NumberRespPend++;
        }
        else
        {
           /*if the sending of a response pending is currently in progress
             do not request it again but set the Dcm_ForcedRespPend flag
             so that the callback function is called in Dcm_TxConfirmation*/
           Dcm_Current_Message_Status.Dcm_ForcedRespPend=DCM_FORCED_RESPONSE_PENDING;
        }
        /* >> GAN:2007-16-10 response pending called, no suppression available*/
        Dcm_pMsgContext2->msgAddInfo.suppressPosResponse=0;
        /* << GAN:2007-16-10 response pending called, no suppression available*/
      }
      else
      {
        /*this can be processed - just set the negative response message*/
        Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_GENERALREJECT);
      }
    }
  
  #if DCM_DEV_ERROR_DETECT==STD_ON
    Dcm_DslReentrancy&=0xEF;
  }
  #endif
  
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function called by ComManager to set DCM in NoCommunication state
*
* \name Dcm_ComM_NoComModeEntered
*
* \b Service-Id:   0x21
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  DCM must be in NoCommunication state after the call of this function.
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ComM_NoComModeEntered(void)
{
  #if (DCM_DEV_ERROR_DETECT==STD_ON) 
   if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x21,DCM_E_UNINIT);
      return;
    }
   #endif  
  Dcm_CommunicationState=DCM_NO_COMMUNICATION;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
  
/*
*! Function called by ComManager to set DCM in SilentCommunication state
*
* \name Dcm_ComM_SilentComModeEntered
*
* \b Service-Id:   0x22
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  DCM must be in SilentCommunication state after the call of this function.
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ComM_SilentComModeEntered(void)
{
  #if (DCM_DEV_ERROR_DETECT==STD_ON) 
   if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x22,DCM_E_UNINIT);
      return;
    }
   #endif  
  Dcm_CommunicationState=DCM_SILENT_COMMUNICATION;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function called by ComManager to set DCM in FullCommunication state
*
* \name Dcm_ComM_FullComModeEntered
*
* \b Service-Id:   0x23
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  DCM must be in FullCommunication state after the call of this function.
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ComM_FullComModeEntered(void)
{
  #if (DCM_DEV_ERROR_DETECT==STD_ON) 
   if (Dcm_Initialized==STD_OFF)
    {
      Det_ReportError(DCM_MODULE_ID,0,0x23,DCM_E_UNINIT);
      return;
    }
   #endif  
  Dcm_CommunicationState=DCM_FULL_COMMUNICATION;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function for resetting the timers
*
* \name Dcm_ResetTimers
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
* \return          none
*
* \b Description:  Function for resetting the timers
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_ResetTimers()
{
    if(DEFAULT_SESSION != Dcm_Current_Message_Status.Dcm_ActiveSession)
    {
        Dcm_Current_Message_Status.Dcm_S3ServerIncrement = DCM_TASK_TIME;
        Dcm_Current_Message_Status.Dcm_S3ServerTimer=0;
    }
    Dcm_Current_Message_Status.Dcm_Message_Status_Busy=0;
    Dcm_ResetNormalAndBusyTimers();
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function for resetting the normal and busy response timers
*
* \name Dcm_ResetNormalAndBusyTimers
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
* \return          none
*
* \b Description:  Function for resetting the normal and busy response timers
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ResetNormalAndBusyTimers()
{

    Dcm_Current_Message_Status.Dcm_NormalResponseTimer=0;
    Dcm_Current_Message_Status.Dcm_NormalResponseIncrement=0;
    Dcm_Current_Message_Status.Dcm_BusyProcessingTimer=0;
    Dcm_Current_Message_Status.Dcm_BusyProcessingIncrement=0;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function for setting the request type
*
* \name Dcm_SetReqType
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
* \return          none
*
* \b Description:  Function for setting the request type in Dcm_pMsgContext2 for the current message.
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_SetReqType()
{
    if (Dcm_ProtocolRxTable[Dcm_Current_Message_Status.Dcm_Message_DcmRxPduId].DCM_PROTOCOL_RX_ADDR_TYPE==DCM_FUNCTIONAL)
    {
        Dcm_pMsgContext2->msgAddInfo.reqType=1;
    }
    else /*DCM_PHYSICAL*/
    {
        Dcm_pMsgContext2->msgAddInfo.reqType=0;
    }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"


/*
*! Function for starting the protocol
*
* \name Dcm_SetReqType
*
* \b Service-Id:   
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   PduIdType DcmRxPduId - the RxPduId that this request is receive with. Range 0..max number of RxPduId -1
*
* \param (Output)  none
*
* \return          TRUE on success
*                  FALSE if protocol was not started successfully
*
* \b Description:  Dcm internal function to start the protocol
*
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(boolean,DCM_CODE) Dcm_StartProtocol(PduIdType DcmRxPduId)
{
    /*start the new protocol
    call application function to start protocol*/
    Dcm_Current_Message_Status.Dcm_StartProtocolStatus= (uint8)\
    Rte_DcmStartProtocol(Dcm_ProtocolTable[Dcm_GetProtocolTableId(DcmRxPduId)].DCM_PROTOCOL_ID);        
    Dcm_Current_Message_Status.Dcm_StartProtocolStatus++;                 
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
    Dcm_PreemptedPdu=0xff;
#endif
    if(Dcm_Current_Message_Status.Dcm_StartProtocolStatus != ((uint8)DCM_E_OK +1))
    {
        /*if protocol was not started successfully*/
        Dcm_Current_Message_Status.Dcm_StartProtocolStatus = 0; /* no protocol has been started*/
        return FALSE;
    }
    else
    {
        /*store the protocol table index for the received RxPduId*/
        Dcm_Current_Message_Status.Dcm_ProtocolTableIndex=Dcm_GetProtocolTableId(DcmRxPduId);
        
#if (DCM_NUMBER_OF_PROTOCOLS != 1)
        /*set the current protocol priority*/
        Dcm_Current_Message_Status.Dcm_Active_Message_Prio=Dcm_ProtocolTable[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_PROTOCOL_PRIO;
#endif
#ifndef BOOTLOADER
        /* Session and security level shall be reset*/
        Dcm_SetSesCtrlType(0x01);
#endif
        /*default timing parameters shall be loaded        */
        Dcm_CurrentTimingParameter=Dcm_ProtocolDefaultTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex];
    }
    return TRUE;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"


#undef DCM_AR_EXTERN

#undef __DSL_C__




