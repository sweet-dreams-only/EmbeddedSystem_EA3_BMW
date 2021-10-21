/* -----------------------------------------------------------------------------
  Filename:    PduR_PBcfg.h
  Description: Toolversion: 11.00.11.01.01.01.24.00.00.00
               
               Serial Number: CBD1010124
               Customer Info: Nxtr
                              Package: BMW MSR SIP BAC3.0   
                              Micro: TI TMS570 TMS570LS30306
                              Compiler: Code Composer Studio 4.9.0
               
               
               Generator Fwk   : GENy 
               Generator Module: PduR
               
               Configuration   : c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\Tools\AsrProject\Config\ECUC\EPS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "A_FlexRay":
                       Databasefile: 
                       Bussystem:    FlexRay
                       Node:         EPS_A_FlexRay_1_FrIfConfig

  Generated by , 2016-02-09  08:25:11
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vctr Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vctr Informatik 
  GmbH.
  
  Vctr Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vctr Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(PDUR_PBCFG_H)
#define PDUR_PBCFG_H

#define PDUR_START_SEC_PBCFG_ROOT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* Contains all configuration data or references to it that can be changed at post-build time if Configuration Variant 3 is used. */
extern CONST(PduR_PBConfigType, PDUR_PBCFG) PduRGlobalConfig;



#define PDUR_STOP_SEC_PBCFG_ROOT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define PDUR_START_SEC_PBCFG
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ Routing Tables
 ----------------------------------------------------------------------------- */

/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblRxFrIf2UpPduRGlobalConfig[];
/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblRxFrTp2UpPduRGlobalConfig[];
/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblRxIpduM2UpPduRGlobalConfig[];
/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblTxFrIf2UpPduRGlobalConfig[];
/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblTxFrTp2UpPduRGlobalConfig[];
/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblTxIpduM2UpPduRGlobalConfig[];
/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblTxCom2LoPduRGlobalConfig[];
/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblTxDcm2LoPduRGlobalConfig[];
/* PRQA  S 3684 1 *//* RULE 8.12: When an array is declared with external linkage, its size shall be stated explicitly or defined implicitly by initialisation */
extern CONST(PduR_Core_DestInfoType, PDUR_CONST) PduR_CfgTblTxIpduM2LoPduRGlobalConfig[];



#define PDUR_STOP_SEC_PBCFG
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 214596022
      #error "The magic number of the generated file <c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\SwProject\Source\GenData\PduR_PBcfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 214596022
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* PDUR_PBCFG_H */