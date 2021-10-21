/*
                                                                            
  SRC-MODULE: Dcm_BmwData.h                                                 
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm Module - request minimum length definition                
                                                                            
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
 * v 2.5.0, 2010.10.26, anam: CR 70846: DCM: Completion of the OBD Sevices Implementation in DCM 
 *                                      according to the Autosar DCM V.3.1
 */
 
 #ifndef __DCM_BMWDATA_H__
 #define __DCM_BMWDATA_H__
 
 /*
                      Global Macros                                         
*/

/*! minimum request length for OBD services*/
#define DCM_OBD_REQUEST_MIN_LEN 1

/*! maximum request length for OBD services*/
#define DCM_OBD_REQUEST_MAX_LEN 6

 /*this length shall not include the SID*/
 /*! for the Request Powertrain Freeze Frame (all sub-functions)                     0x02*/
 #define DCM_REQUESTFREEZEFRAMEDATALENGTH 2
 /*! for the Request emission-related DTC                                            0x03*/
 #define REQUESTEMISSIONRELATEDDTCLENGTH 0
 /*! for the Clear emission-related diagnostic information                           0x04*/
 #define CLEAREMISSIONRELATEDINFORMATIONLENGTH 0
 /*! for Request emission-related DTC from the last driving cycle                    0x07*/
 #define REQUESTEMISSIONRELATEDDTCDURINGLASTDRIVINGCYCLELENGTH 0


 /*! for Clear diagnostic information                                                0x14*/
 #define CLEARDIAGNOSTICINFORMATIONLENGTH 3 
 /*! Read DTC information sub-function 0x01                                          0x19 0x01*/
 #define READDTCINFORMATIONSUBFUNCTION1LENGTH 2
 /*! Read DTC information sub-function 0x02                                          0x19 0x02*/
 #define READDTCINFORMATIONSUBFUNCTION2LENGTH 2
 /*! Read DTC information sub-function 0x03                                          0x19 0x03*/
 #define READDTCINFORMATIONSUBFUNCTION3LENGTH 1
 /*! Read DTC information sub-function 0x04                                          0x19 0x04*/
 #define READDTCINFORMATIONSUBFUNCTION4LENGTH 5
 /*! Read DTC information sub-function 0x05                                          0x19 0x05*/
 #define READDTCINFORMATIONSUBFUNCTION5LENGTH 2
 /*! Read DTC information sub-function 0x06                                          0x19 0x06*/
 #define READDTCINFORMATIONSUBFUNCTION6LENGTH 5
 /*! Read DTC information sub-function 0x07                                          0x19 0x07*/
 #define READDTCINFORMATIONSUBFUNCTION7LENGTH 3
 /*! Read DTC information sub-function 0x08                                          0x19 0x08*/
 #define READDTCINFORMATIONSUBFUNCTION8LENGTH 3
 /*! Read DTC information sub-function 0x09                                          0x19 0x09*/
 #define READDTCINFORMATIONSUBFUNCTION9LENGTH 4
 /*! Read DTC information sub-function 0x0A                                          0x19 0x0A*/
 #define READDTCINFORMATIONSUBFUNCTIONALENGTH 1
 /*! Read DTC information sub-function 0x0B                                          0x19 0x0B*/
 #define READDTCINFORMATIONSUBFUNCTIONBLENGTH 1
 /*! Read DTC information sub-function 0x0C                                          0x19 0x0C*/
 #define READDTCINFORMATIONSUBFUNCTIONCLENGTH 1
 /*! Read DTC information sub-function 0x0D                                          0x19 0x0D*/
 #define READDTCINFORMATIONSUBFUNCTIONDLENGTH 1
 /*! Read DTC information sub-function 0x0E                                          0x19 0x0E*/
 #define READDTCINFORMATIONSUBFUNCTIONELENGTH 1
 /*! Read DTC information sub-function 0x0F                                          0x19 0x0F*/
 #define READDTCINFORMATIONSUBFUNCTIONFLENGTH 2
 /*! Read DTC information sub-function 0x10                                          0x19 0x10*/
 #define READDTCINFORMATIONSUBFUNCTION10LENGTH 5
 /*! Read DTC information sub-function 0x11                                          0x19 0x11*/
 #define READDTCINFORMATIONSUBFUNCTION11LENGTH 2
 /*! Read DTC information sub-function 0x12                                          0x19 0x12*/
 #define READDTCINFORMATIONSUBFUNCTION12LENGTH 2
 /*! Read DTC information sub-function 0x13                                          0x19 0x13*/
 #define READDTCINFORMATIONSUBFUNCTION13LENGTH 2
 /*! Read DTC information sub-function 0x14                                          0x19 0x14*/
 #define READDTCINFORMATIONSUBFUNCTION14LENGTH 1
 /*! Read DTC information sub-function 0x15                                          0x19 0x15*/
 #define READDTCINFORMATIONSUBFUNCTION15LENGTH 1
 /*! Control DTC setting                                                             0x85*/
 #define CONTROLDTCSETTINGLENGTH 1
 /*! Diagnostic session control                                                      0x10*/
 #define DIAGNOSTICSESSIONCONTROLLENGTH 1
 /*! Tester present                                                                  0x3E*/
 #define TESTERPRESENTLENGTH 1
 /*! AccessTiming parameter length                                                   0x83*/
 #define ACCESSTIMINGPARAMETERLENGTH 1
 /*! SecurityAccess length                                                           0x27*/
 #define SECURITYACCESSLENGTH 1 
 #endif 
