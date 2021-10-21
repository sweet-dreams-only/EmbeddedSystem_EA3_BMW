/*
                                                                            
  SRC-MODULE: Dsl.h                                                         
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm Module - DSL part header                                  
                                                                            
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
 *          2010.01.18, anam: CR 70453, CR 70483, CR 70494 - Bug-fixing changes
 * v 2.4.0, 2010.02.23, gema: CR 70411: DCM: Module extension to 3.0  
 */


#ifndef __DSL_H__
#define __DSL_H__

/*
                      Include Section                                       
*/

#include "Dcm_cfg.h"

/*
                      Global Macros                                         
*/

#ifdef __DCM_C__
#define DCM_AR_EXTERN
#else
#define DCM_AR_EXTERN extern
#endif

/*
                      Global Function Prototypes                            
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
/*Function used to set the session value*/
DCM_AR_EXTERN FUNC(void,DCM_CODE)  Dcm_SetSesCtrlType(Dcm_SesCtrlType SesCtrlType);

#if ( DCM_BAC_VERSION == DCM_BAC21 )
/*function to read the current session value*/
DCM_AR_EXTERN FUNC(Dcm_SesCtrlType,DCM_CODE) Dcm_GetSesCtrlType(void);
#elif ( DCM_BAC_VERSION == DCM_BAC3X )
/*function to read the current session value*/
DCM_AR_EXTERN FUNC(Std_ReturnType,DCM_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType,AUTOMATIC,DCM_APPL_DATA) SesCtrlType);
#endif /* AUTOSAR Version 3.0 */

#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
/*This function is used to read the current/default/limits timing parameter values*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_GetSesTimingValues(Dcm_TimerModeType TimerMode,
                                                     P2VAR(Dcm_TimerServerType,AUTOMATIC,DCM_APPL_DATA) TimerServerCurrent);
/*This function is used to prepare the new timing parameters */
DCM_AR_EXTERN FUNC(Dcm_StatusType,DCM_CODE) Dcm_PrepareSesTimingValues(P2CONST(Dcm_TimerServerType,AUTOMATIC,DCM_APPL_DATA) TimerServerNew);

/*This function is used to set the new timing parameter values*/
DCM_AR_EXTERN   FUNC(void,DCM_CODE) Dcm_SetSesTimingValues (P2CONST(Dcm_TimerServerType,AUTOMATIC,DCM_APPL_DATA) TimerServerNew);
#endif

/*This function is used to read the active security level*/
DCM_AR_EXTERN FUNC(Dcm_SecLevelType,DCM_CODE) Dcm_GetSecurityLevel(void);

/*This function is used to set the new security level*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_SetSecurityLevel(Dcm_SecLevelType SecurityLevel);

#if ( DCM_BAC_VERSION == DCM_BAC21 )
/*This function is used to read the active diagnostic protocol id */
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType,AUTOMATIC,DCM_APPL_DATA) ActiveProtocol);
#elif ( DCM_BAC_VERSION == DCM_BAC3X )
/*This function is used to read the active diagnostic protocol id */
DCM_AR_EXTERN FUNC(Std_ReturnType,DCM_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType,AUTOMATIC,DCM_APPL_DATA) ActiveProtocol);
#endif /* AUTOSAR Version 3.0 */

/*This API provides the processing of one event requested by RTE*/
DCM_AR_EXTERN FUNC(Dcm_StatusType,DCM_CODE) Dcm_ResponseOnOneEvent(Dcm_MsgType MsgPtr,
                                                               Dcm_MsgLenType MsgLen,
                                                               PduIdType DcmRxPduId);

/*This function provides the processing of one periodic ID event*/
DCM_AR_EXTERN FUNC(Dcm_StatusType,DCM_CODE) Dcm_ResponseOnOneDataByPeriodicId(uint8 PeriodicId);


/*This function allows the application to send forced response pending messages*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_ForceRespPend(void);

/* Function for resetting the normal and busy response timers*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_ResetNormalAndBusyTimers(void);

/*Macro to retreive the assigned protocol table id from a PDU ID*/
#if (DCM_NUMBER_OF_PROTOCOLS == 1)
#define Dcm_GetProtocolTableId(RxPduID) 0
#else
#define Dcm_GetProtocolTableId(RxPduID) Dcm_ProtocolRxTable[RxPduID].DIAGNOSTIC_PROTOCOL_TABLE_ID
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#undef DCM_AR_EXTERN

#endif /* __DSL_C__*/

