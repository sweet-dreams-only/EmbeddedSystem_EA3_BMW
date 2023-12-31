/* -----------------------------------------------------------------------------
  Filename:    Com_Cfg.c
  Description: Toolversion: 11.00.11.01.01.01.24.00.00.00
               
               Serial Number: CBD1010124
               Customer Info: Nxtr
                              Package: BMW MSR SIP BAC3.0   
                              Micro: TI TMS570 TMS570LS30306
                              Compiler: Code Composer Studio 4.9.0
               
               
               Generator Fwk   : GENy 
               Generator Module: Com
               
               Configuration   : C:\Build\BMW\F40_Latest\BMW_UKL_MCV_EPS_TMS570\Tools\AsrProject\Config\ECUC\EPS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "A_FlexRay":
                       Databasefile: 
                       Bussystem:    FlexRay
                       Node:         EPS_A_FlexRay_1_FrIfConfig

  Generated by , 2016-08-09  00:23:00
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

/* START of Checksum include for
  - Il_AsrComPrecompileCRC */
#define V_IL_ASRCOM_CFG_SOURCE
#include "Com.h"
#if ((COM_RXINV == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API == STD_ON))
#include "Appl_Cbk.h"
#include "Rte_Cbk.h"
#endif

/* -----------------------------------------------------------------------------
    &&&~ Rx Signal Invalidation Configuration Data
 ----------------------------------------------------------------------------- */

/* Rx signal invalidation is deactivated */


/* -----------------------------------------------------------------------------
    &&&~ Reception Filtering Configuration Data
 ----------------------------------------------------------------------------- */

/* Reception filtering is deactivated */


/* END of Checksum include for
  - Il_AsrComPrecompileCRC */

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 214596022
      #error "The magic number of the generated file <c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\SwProject\Source\GenData\Com_Cfg.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\SwProject\Source\GenData\Com_Cfg.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

