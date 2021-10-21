/*
                                                                            
  SRC-MODULE: Dcm.h                                                         
                                                                            
  Copyright (C) BMW Group 2007                                              
                                                                            
  TARGET    : All                                                           
                                                                            
  PROJECT   : BMW Standard Core 7                                           
                                                                            
  AUTHOR    : Norbert Gaier                                                 
                                                                            
  PURPOSE   : Dcm Module header                                             
                                                                            
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
 * v 2.4.0, 2010.02.23, gema: CR 70411: DCM: Module extension to 3.0  
 * v 2.5.0, 2010.10.26, anam: CR 70808: Dcm includes wrong callback header file  
 */

#ifndef __DCM_H__
#define __DCM_H__

/*
                      Include Section                                       
*/

#include "Dcm_BmwData.h"
#include "Dcm_cfg.h"
#include "Dsp.h"
#include "Dsl.h"
#include "Dsd.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
#include "Dcm_Cbk.h"
#include "SchM_Dcm.h"

/*
                      Global Macros                                         
*/

#define DCM_AR_EXTERN extern

/*! \define Version control for AUTOSAR specification that is used to implement this SW Unit
 *
 *  \var  DCM_AR_VERSION_MAJOR  Major version
 *  \var  DCM_AR_VERSION_MINOR  Minor version
 *  \var  DCM_AR_VERSION_PATCH  Patch version
 */
#if ( DCM_BAC_VERSION != DCM_BAC3X )
#define DCM_AR_MAJOR_VERSION  2
#define DCM_AR_MINOR_VERSION  1
#define DCM_AR_PATCH_VERSION  1
#else
#define DCM_AR_MAJOR_VERSION  3
#define DCM_AR_MINOR_VERSION  0
#define DCM_AR_PATCH_VERSION  0
#endif /* AUTOSAR Version 3.0 */

/*! \define Dcm version control defines for software
 *
 *  \var  DCM_SW_VERSION_MAJOR  Major version
 *  \var  DCM_SW_VERSION_MINOR  Minor version
 *  \var  DCM_SW_VERSION_PATCH  Patch version
 */
/*version control defines for software */
#define DCM_SW_MAJOR_VERSION 2
#define DCM_SW_MINOR_VERSION 4
#define DCM_SW_PATCH_VERSION 3

/*! \define Dcm_Module and vendor id
* \var DCM_MODULE_ID - the module Id as specified by the specification document for DCM Dcm_Module
* \var DCM_VENDOR_ID - the vendor Id according to AUTOSAR
*/
#define DCM_MODULE_ID 53
#define DCM_VENDOR_ID 16

/*development error definition*/
#define DCM_E_INTERFACE_TIMEOUT            0x01
#define DCM_E_INTERFACE_VALUE_OUT_OF_RANGE 0x02
#define DCM_E_INTERFACE_BUFFER_OVERFLOW    0x03
#define DCM_E_INTERFACE_PROTOCOL_MISMATCH  0x04 
#define DCM_E_UNINIT                       0x05
#define DCM_E_PARAM                        0x06

/*
                      Global Function Prototypes                            
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
/*Service for basic initialization of DCM module*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_Init(void);

/*Function for returning version info 
  Pre-compile time configurable On/Off by the configuration parameter: DCM_VERSION_INFO_API*/
#if (DCM_VERSION_INFO_API==STD_ON)
   DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_GetVersionInfo (P2VAR(Std_VersionInfoType,AUTOMATIC,DCM_APPL_CODE) versioninfo);
#endif

/*Dcm module main processing function*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_MainFunction(void);

/*Dcm module main processing function*/
DCM_AR_EXTERN FUNC(void,DCM_CODE) Dcm_RteMainFunction(void);


#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#undef DCM_AR_EXTERN

#endif   /* #ifndef __DCM_H__ */


