/* -----------------------------------------------------------------------------
  Filename:    FrSM_Cfg.h
  Description: Toolversion: 11.00.11.01.01.01.24.00.00.00
               
               Serial Number: CBD1010124
               Customer Info: Nxtr
                              Package: BMW MSR SIP BAC3.0   
                              Micro: TI TMS570 TMS570LS30306
                              Compiler: Code Composer Studio 4.9.0
               
               
               Generator Fwk   : GENy 
               Generator Module: FrSM
               
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

#if !defined(FRSM_CFG_H)
#define FRSM_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ Precompile config
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

#include "Com.h"


/* -----------------------------------------------------------------------------
    &&&~ Version Defines
 ----------------------------------------------------------------------------- */

#if (COM_AR_MAJOR_VERSION != 0x03u)
# error "COM_AR_MAJOR_VERSION not correct. Check AUTOSAR Release version!"
#endif

#if (COM_AR_MINOR_VERSION != 0x00u)
# error "COM_AR_MINOR_VERSION not correct. Check AUTOSAR Release version!"
#endif



/* -----------------------------------------------------------------------------
    &&&~ Precompile Definitions
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Ccl_AsrSmFrPrecompileCRC */
#define FRSM_DEV_ERROR_DETECT                STD_ON
#define FRSM_PROD_ERROR_DETECT               STD_OFF
#define FRSM_VERSION_INFO_API                STD_ON
#define FRSM_CONFIG_VARIANT                  (0x01u)
#define FRSM_CRC_CHECK                       STD_OFF
#define FRSM_PRECOMPILE_CRC                  (uint32) 0xBAB88D62u
#define FRSM_ECU_PASSIVE_MODE                STD_OFF
#define FRSM_TRCV_HANDLING                   STD_ON
#define FRSM_FRNM_HANDLING                   STD_OFF
#define FRSM_STATE_CHANGE_NOTIFICATION       STD_OFF
#define FRSM_ENABLE_CONSECUTIVE_WUP          STD_OFF
#define FRSM_ENABLE_DELAY_ALLOWCOLDSTART     STD_OFF
#define FRSM_DEM_SYNCLOSS_INDICATION         STD_OFF
#define FRSM_IDENTITY_MANAGER_CONFIG         STD_OFF
#define FRSM_ENABLE_DELAY_TRCV_STANDBY       STD_OFF
/* END of Checksum include for
  - Ccl_AsrSmFrPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ Linktime Definitions
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Ccl_AsrSmFrLinktimeCRC */
#define FRSM_NUMBER_OF_CLUSTERS              1
/* END of Checksum include for
  - Ccl_AsrSmFrLinktimeCRC */


/* FrSM instance properties */
/* -----------------------------------------------------------------------------
    &&&~ FrSm EcuC Global Configuration Container Name
 ----------------------------------------------------------------------------- */

#define A_FlexRay                            FrSMConfig



#define FRSM_START_SEC_CONST_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* START of Checksum include for
  - Ccl_AsrSmFrLinktimeCRC */
extern CONST(uint8, FRSM_CONST) FrSMCountOfFrClusters;
/* END of Checksum include for
  - Ccl_AsrSmFrLinktimeCRC */

#define FRSM_STOP_SEC_CONST_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#if (FRSM_CRC_CHECK == STD_ON)
#define FRSM_START_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* START of Checksum include for
  - Ccl_AsrSmFrLinktimeCRC */
extern CONST(uint32, FRSM_CONST) FrSM_LinktimeCRC;
/* END of Checksum include for
  - Ccl_AsrSmFrLinktimeCRC */

#define FRSM_STOP_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#endif

#define FRSM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* START of Checksum include for
  - Ccl_AsrSmFrLinktimeCRC */
extern FUNC(void, FRSM_CODE) FrSm_SwitchIpduGroup(uint8 FrSm_ClusterIdx, uint8 RxTxStartStop);
/* END of Checksum include for
  - Ccl_AsrSmFrLinktimeCRC */

#define FRSM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 214596022
      #error "The magic number of the generated file <c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\SwProject\Source\GenData\FrSM_Cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 214596022
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* FRSM_CFG_H */
