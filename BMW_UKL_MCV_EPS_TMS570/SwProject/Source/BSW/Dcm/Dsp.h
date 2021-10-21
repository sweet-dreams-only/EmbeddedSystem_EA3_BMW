/*
                                                                            
  SRC-MODULE: Dsp.h                                                         
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm Module - DSP part header                                  
                                                                            
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
 *          2010.01.18, anam: CR 70496 - Bug-fixing changes 
 * v 2.5.0, 2010.10.26, anam: CR 70846: DCM: Completion of the OBD Sevices Implementation in DCM 
 *                                      according to the Autosar DCM V.3.1
 */

#ifndef __DSP_H__
#define __DSP_H__

/*
                      Include Section                                       
*/

#include "Dcm_cfg.h"
/* >> GAN:2008-02-04 Added Dcm_Types include*/
#include "Dcm_types.h"
/* << GAN:2008-02-04 Added Dcm_Types include*/


/*
                      Global Macros                                         
*/

#define DCM_AR_EXTERN extern

/*
                      Global Function Prototypes                            
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
/*confirmation function for DSP-processed services*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dsp_DcmConfirmation  (Dcm_IdContextType idContext, 
                                     PduIdType DcmRxPduId, 
                                     Dcm_ConfirmationStatusType status
                                    );
                                    
/*PagedBuffer functions                                    */
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dsp_DcmUpdatePage(Dcm_MsgType PageBufPtr, Dcm_MsgLenType PageLen);
                                    
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dsp_DcmCancelPagedBufferProcessing(void);                                            
                                            
#if DCM_USE_DEM==STD_ON                    
  /*UDS services implemented by DSP*/
  DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmClearDiagnosticInformation(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

  DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmReadDTCInformation(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
                                                      
  DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmControlDTCSetting(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
#endif
                                                        
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmTesterPresent(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
                                                   
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmDiagnosticSessionControl(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
                                                                
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmSecurityAccess(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmAccessTimingParameter(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
#endif

#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
/*OBD emission related diagnostic services implemented by DSP*/

/* OBD service 0x01 */
#if ((defined DCM_OBD_SERVICE_0x01_SUPPORTED)&&(DCM_OBD_SERVICE_0x01_SUPPORTED == STD_ON))
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmObdRequestCurrentPowerTrainDiagnosticData(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
#endif /*((defined DCM_OBD_SERVICE_0x01_SUPPORTED)&&(DCM_OBD_SERVICE_0x01_SUPPORTED == STD_ON))*/

/* OBD service 0x02 */
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmRequestFreezeFrameData(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

/* OBD service 0x03 */
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmRequestEmissionRelatedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

/* OBD service 0x04 */
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmClearEmissionRelatedInformation(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

/* OBD service 0x06 */
#if ((defined DCM_OBD_SERVICE_0x06_SUPPORTED)&&(DCM_OBD_SERVICE_0x06_SUPPORTED == STD_ON))
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmObdRequestOnBoardMonitorTestResult(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
#endif /*((defined DCM_OBD_SERVICE_0x06_SUPPORTED)&&(DCM_OBD_SERVICE_0x06_SUPPORTED == STD_ON))*/

/* OBD service 0x07 */
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmReqEmissionRelDTCDrivCyc(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

/* OBD service 0x08 */
#if ((defined DCM_OBD_SERVICE_0x08_SUPPORTED)&&(DCM_OBD_SERVICE_0x08_SUPPORTED == STD_ON))
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmObdRequestControl(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
#endif /*((defined DCM_OBD_SERVICE_0x08_SUPPORTED)&&(DCM_OBD_SERVICE_0x08_SUPPORTED == STD_ON))*/

/* OBD service 0x09 */
#if ((defined DCM_OBD_SERVICE_0x09_SUPPORTED)&&(DCM_OBD_SERVICE_0x09_SUPPORTED == STD_ON))
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmObdRequestVehicleInformation(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
#endif /*((defined DCM_OBD_SERVICE_0x09_SUPPORTED)&&(DCM_OBD_SERVICE_0x09_SUPPORTED == STD_ON))*/

/* OBD service 0x0A */
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_DcmObdRequestPermanentEmissionRelatedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

#endif /*((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))*/
                                                                
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#undef DCM_AR_EXTERN

#endif /* __DSP_H__*/
