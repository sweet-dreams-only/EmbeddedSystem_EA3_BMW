/*
                                                                            
  SRC-MODULE: Dcm_cbk.h                                                     
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm Module - callback definitions                             
                                                                            
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
 *          2010.08.16        CR 70722: Change the type of parameter "Length" of the function Dcm_ProvideTxBuffer to "PduLengthType"    
 */
 
#ifndef __DCM_CBK_H__
#define __DCM_CBK_H__

/*
                      Include Section                                       
*/
#include "Dcm_types.h"

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
/*This function is called to provide Rx buffer for the incoming message */
DCM_AR_EXTERN FUNC(BufReq_ReturnType,DCM_CODE) Dcm_ProvideRxBuffer(PduIdType DcmRxPduId,
                                                PduLengthType TpSduLength,
                                                P2VAR(P2VAR(PduInfoType,AUTOMATIC,PDUR_IPDUM_DATA),AUTOMATIC,PDUR_IPDUM_DATA) PduInfoPtr);

/*This function is called for Rx indication*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_RxIndication(PduIdType DcmRxPduId, 
                                               NotifResultType Result);

/*This function is called to provide Tx buffer for the outgoing message */
DCM_AR_EXTERN FUNC(BufReq_ReturnType,DCM_CODE) Dcm_ProvideTxBuffer(PduIdType DcmTxPduId,
                                                               P2VAR(P2VAR(PduInfoType,AUTOMATIC,PDUR_IPDUM_DATA),AUTOMATIC,PDUR_IPDUM_DATA) PduInfoPtr,
                                                               PduLengthType Length);

/*This function is called for Tx confirmation*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_TxConfirmation(PduIdType DcmTxPduId,
                                                 NotifResultType Result);

/*Function for entering in No Communication mode called by Communication Manager*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_ComM_NoComModeEntered(void);

/*Function for entering in Silent Communication mode called by Communication Manager*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_ComM_SilentComModeEntered(void);

/*Function for entering in Full Communication mode called by Communication Manager*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_ComM_FullComModeEntered(void);
#define DCM_STOP_SEC_CODE
#include "MemMap.h" 
 
#undef DCM_AR_EXTERN
 
#endif
