/* -----------------------------------------------------------------------------
  Filename:    FrIf_Cfg.h
  Description: Toolversion: 11.00.11.01.01.01.24.00.00.00
               
               Serial Number: CBD1010124
               Customer Info: Nxtr
                              Package: BMW MSR SIP BAC3.0   
                              Micro: TI TMS570 TMS570LS30306
                              Compiler: Code Composer Studio 4.9.0
               
               
               Generator Fwk   : GENy 
               Generator Module: FrIf
               
               Configuration   : c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\Tools\AsrProject\Config\ECUC\EPS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "A_FlexRay":
                       Databasefile: 
                       Bussystem:    FlexRay
                       Node:         EPS_A_FlexRay_1_FrIfConfig

  Generated by , 2016-05-19  09:31:39
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

#if !defined(FRIF_CFG_H)
#define FRIF_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - If_AsrIfFrPrecompileCRC */
#include "Platform_Types.h"
#include "FrTrcv_30_Tja1080.h"
#include "FrTrcv_30_Tja1080_Cbk.h"

/* -----------------------------------------------------------------------------
    &&&~ Version
 ----------------------------------------------------------------------------- */

#define IF_ASRIFFRDLL_VERSION                0x0312
#define IF_ASRIFFRDLL_RELEASE_VERSION        0x04


/* -----------------------------------------------------------------------------
    &&&~ Linktime / Precompile CRC
 ----------------------------------------------------------------------------- */

#define FRIF_CRC_CHECK                       STD_OFF
#define FRIF_PRECOMPILE_CRC                  (uint32) 0x281A3731u


/* -----------------------------------------------------------------------------
    &&&~ FrIf EcuC Global Configuration Container Name
 ----------------------------------------------------------------------------- */

#define FrIfConfig                           FrIf_Config



/* -----------------------------------------------------------------------------
    &&&~ Defines
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - If_AsrIfFrPrecompileCRC */
#define FRIF_CONFIG_VARIANT                  1u
/* START of Checksum include for
  - If_AsrIfFrPrecompileCRC */
#define FRIF_SYNC_THRESHOLD                  (sint16) 36
#define FRIF_FILL_PATTERN                    (uint8) 0xFFu
#define FRIF_FILL_PATTERN_DWORD              (uint32) 0xFFFFFFFFu
#ifndef FRIF_OSTYPE_AUTOSAR
#define FRIF_OSTYPE_AUTOSAR
#endif


#ifndef FRIF_USE_DUMMY_FUNCTIONS
#define FRIF_USE_DUMMY_FUNCTIONS             STD_OFF
#endif


#ifndef FRIF_USE_DUMMY_STATEMENT
#define FRIF_USE_DUMMY_STATEMENT             STD_ON
#endif


#ifndef FRIF_CPU_TMS470
#define FRIF_CPU_TMS470
#endif


#ifndef FRIF_PROCESSOR_TI_TMS470_PSFC66
#define FRIF_PROCESSOR_TI_TMS470_PSFC66
#endif


#ifndef FRIF_COMP_TI
#define FRIF_COMP_TI
#endif


#ifndef FRIF_CRC_CHECK
#define FRIF_CRC_CHECK                       STD_OFF
#endif


#ifndef FRIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FRIF_ATOMIC_BIT_ACCESS_IN_BITFIELD   STD_OFF
#endif


#ifndef FRIF_ATOMIC_VARIABLE_ACCESS
#define FRIF_ATOMIC_VARIABLE_ACCESS          32
#endif


/* END of Checksum include for
  - If_AsrIfFrPrecompileCRC */

/* END of Checksum exclude for
  - If_AsrIfFrPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ Symbolic Name Value Defines
 ----------------------------------------------------------------------------- */

/* FrIfClstIdx */
#define FrIf_A_FlexRay                       0u
/* FrIfCtrlIdx */
#define FrIf_EPS_A_FlexRay_1                 0u
/* FrIfAbsTimerIdx */
#define FrIf_EPS_A_FlexRay                   0u
/* FrIfLPduIdx */
#define FrIf_FrIfLPdu_ST_EST                 0u
#define FrIf_FrIfLPdu_TL_ECU_TRNSM_FR_32_EPS 1u
#define FrIf_FrIfLPdu_FR_DBG_EPS             2u
#define FrIf_FrIfLPdu_xcpdynamic254_8        3u
#define FrIf_FrIfLPdu_xcpdynamic254_7        4u
#define FrIf_FrIfLPdu_xcpdynamic254_6        5u
#define FrIf_FrIfLPdu_xcpdynamic254_5        6u
#define FrIf_FrIfLPdu_xcpdynamic254_4        7u
#define FrIf_FrIfLPdu_xcpdynamic254_3        8u
#define FrIf_FrIfLPdu_xcpdynamic254_2        9u
#define FrIf_FrIfLPdu_xcpdynamic254_1        10u
#define FrIf_FrIfLPdu_DISP_CC_EPS            11u
#define FrIf_FrIfLPdu_SU_EPS                 12u
#define FrIf_FrIfLPdu_ST_DIAG_OBD_3_DRDY     13u
#define FrIf_FrIfLPdu_xcpslave               14u
#define FrIf_FrIfLPdu_SVC_EPS                15u
#define FrIf_FrIfLPdu_AVL_PO_EPS_ENGTORQ_EPS 16u
#define FrIf_FrIfLPdu_DT_EST                 17u
#define FrIf_FrIfLPdu_AVL_STMOM_DV_ACT_AVL_FORC_GRD 18u
#define FrIf_FrIfLPdu_RELATIVZEIT            19u
#define FrIf_FrIfLPdu_KILOMETERSTAND         20u
#define FrIf_FrIfLPdu_FZZSTD                 21u
#define FrIf_FrIfLPdu_FAHRGESTELLNUMMER      22u
#define FrIf_FrIfLPdu_CTR_VIB_STW_DISP_EXMI_SP2015_FDBK_VIB_STW_DISP_EXMI 23u
#define FrIf_FrIfLPdu_A_TEMP                 24u
#define FrIf_FrIfLPdu_CTR_DIAG_OBD_DRDY      25u
#define FrIf_FrIfLPdu_DIAG_OBD_ENG           26u
#define FrIf_FrIfLPdu_ST_ENERG_GEN           27u
#define FrIf_FrIfLPdu_xcpmaster              28u
#define FrIf_FrIfLPdu_SVC_DSC_Modul          29u
#define FrIf_FrIfLPdu_SVC_SAS                30u
#define FrIf_FrIfLPdu_SVC_ZGW                31u
#define FrIf_FrIfLPdu_TL_BRC_FR_32_2         32u
#define FrIf_FrIfLPdu_TL_BRC_FR_32_1         33u
#define FrIf_FrIfLPdu_TL_BRC_FR_32_0         34u
#define FrIf_FrIfLPdu_TL_MST_GW_TRNSM_FR_254 35u
#define FrIf_FrIfLPdu_CON_VEH                36u
#define FrIf_FrIfLPdu_ST_CENG                37u
#define FrIf_FrIfLPdu_STEA_OFFS              38u
#define FrIf_FrIfLPdu_OFFS_QUAD_EPS          39u
#define FrIf_FrIfLPdu_ERRM_BN_U              40u
#define FrIf_FrIfLPdu_TAR_QTA_STRMOM_DV_TAR_STMOM_DV_ACT 41u
#define FrIf_FrIfLPdu_ENERG_DGR_DRDY         42u
#define FrIf_FrIfLPdu_TAR_ESTP_VIRT_FTAX     43u
#define FrIf_FrIfLPdu_DT_DRDYSEN_EXT_VYAW_VEH 44u
#define FrIf_FrIfLPdu_ACLNX_MASSCNTR_ACLNY_MASSCNTR 45u
#define FrIf_FrIfLPdu_V_VEH_V_VEH_2          46u
#define FrIf_FrIfLPdu_SU_CLE_DRDY_DXP_SPEC_ADPT_MOD_DXP_ST_IDLV_COOD_DBE_DXP 47u
#define FrIf_FrIfLPdu_AVL_RPM_WHL            48u


/* -----------------------------------------------------------------------------
    &&&~ Rx PDU Handle
 ----------------------------------------------------------------------------- */

#define FRIF_RX_KILOMETERSTAND               0u
#define FRIF_RX_RELATIVZEIT                  1u
#define FRIF_RX_FAHRGESTELLNUMMER            2u
#define FRIF_RX_FZZSTD                       3u
#define FRIF_RX_CTR_VIB_STW_DISP_EXMI_SP2015 4u
#define FRIF_RX_A_TEMP                       5u
#define FRIF_RX_DIAG_OBD_ENG                 6u
#define FRIF_RX_CTR_DIAG_OBD_DRDY            7u
#define FRIF_RX_ST_ENERG_GEN                 8u
#define FRIF_RX_dummy32bmaster               9u
#define FRIF_RX_SVC_SAS                      10u
#define FRIF_RX_SVC_DSC_Modul                11u
#define FRIF_RX_SVC_ZGW                      12u
#define FRIF_RX_TL_BRC_FR_32_Tp              13u
#define FRIF_RX_TL_MST_GW_TRNSM_FR_254_Tp    14u
#define FRIF_RX_CON_VEH                      15u
#define FRIF_RX_ST_CENG                      16u
#define FRIF_RX_STEA_OFFS                    17u
#define FRIF_RX_OFFS_QUAD_EPS                18u
#define FRIF_RX_ERRM_BN_U                    19u
#define FRIF_RX_ENERG_DGR_DRDY               20u
#define FRIF_RX_TAR_QTA_STRMOM_DV            21u
#define FRIF_RX_TAR_STMOM_DV_ACT             22u
#define FRIF_RX_TAR_ESTP_VIRT_FTAX           23u
#define FRIF_RX_VYAW_VEH                     24u
#define FRIF_RX_V_VEH                        25u
#define FRIF_RX_ACLNY_MASSCNTR               26u
#define FRIF_RX_SU_CLE_DRDY_DXP              27u
#define FRIF_RX_AVL_RPM_WHL                  28u


/* -----------------------------------------------------------------------------
    &&&~ Tx PDU Handle
 ----------------------------------------------------------------------------- */

#define FRIF_TX_ST_EST                       0u
#define FRIF_TX_TL_ECU_TRNSM_FR_32_EPS_Tp    1u
#define FRIF_TX_FR_DBG_EPS                   2u
#define FRIF_TX_xcpdynamic254_8              3u
#define FRIF_TX_xcpdynamic254_7              4u
#define FRIF_TX_xcpdynamic254_6              5u
#define FRIF_TX_xcpdynamic254_5              6u
#define FRIF_TX_xcpdynamic254_4              7u
#define FRIF_TX_xcpdynamic254_3              8u
#define FRIF_TX_xcpdynamic254_2              9u
#define FRIF_TX_xcpdynamic254_1              10u
#define FRIF_TX_DISP_CC_EPS                  11u
#define FRIF_TX_SU_EPS                       12u
#define FRIF_TX_ST_DIAG_OBD_3_DRDY           13u
#define FRIF_TX_dummy32bslave                14u
#define FRIF_TX_SVC_EPS                      15u
#define FRIF_TX_AVL_PO_EPS                   16u
#define FRIF_TX_ENGTORQ_EPS                  17u
#define FRIF_TX_DT_EST                       18u
#define FRIF_TX_AVL_STMOM_DV_ACT             19u
#define FRIF_TX_AVL_FORC_GRD                 20u


/* -----------------------------------------------------------------------------
    &&&~ Upper Layer PDU Handle
 ----------------------------------------------------------------------------- */

#define FRIF_TX_ulST_EST                     0u
#define FRIF_TX_ulTL_ECU_TRNSM_FR_32_EPS_Tp  1u
#define FRIF_TX_ulFR_DBG_EPS                 2u
#define FRIF_TX_ulxcpdynamic254_8            3u
#define FRIF_TX_ulxcpdynamic254_7            7u
#define FRIF_TX_ulxcpdynamic254_6            6u
#define FRIF_TX_ulxcpdynamic254_5            5u
#define FRIF_TX_ulxcpdynamic254_4            4u
#define FRIF_TX_ulxcpdynamic254_3            3u
#define FRIF_TX_ulxcpdynamic254_2            2u
#define FRIF_TX_ulxcpdynamic254_1            1u
#define FRIF_TX_ulDISP_CC_EPS                11u
#define FRIF_TX_ulSU_EPS                     12u
#define FRIF_TX_ulST_DIAG_OBD_3_DRDY         13u
#define FRIF_TX_uldummy32bslave              0u
#define FRIF_TX_ulSVC_EPS                    15u
#define FRIF_TX_ulAVL_PO_EPS                 16u
#define FRIF_TX_ulENGTORQ_EPS                17u
#define FRIF_TX_ulDT_EST                     18u
#define FRIF_TX_ulAVL_STMOM_DV_ACT           19u
#define FRIF_TX_ulAVL_FORC_GRD               20u
#define FRIF_RX_ulKILOMETERSTAND             0u
#define FRIF_RX_ulRELATIVZEIT                1u
#define FRIF_RX_ulFAHRGESTELLNUMMER          2u
#define FRIF_RX_ulFZZSTD                     3u
#define FRIF_RX_ulCTR_VIB_STW_DISP_EXMI_SP2015 4u
#define FRIF_RX_ulA_TEMP                     5u
#define FRIF_RX_ulDIAG_OBD_ENG               6u
#define FRIF_RX_ulCTR_DIAG_OBD_DRDY          7u
#define FRIF_RX_ulST_ENERG_GEN               8u
#define FRIF_RX_uldummy32bmaster             0u
#define FRIF_RX_ulSVC_SAS                    9u
#define FRIF_RX_ulSVC_DSC_Modul              10u
#define FRIF_RX_ulSVC_ZGW                    11u
#define FRIF_RX_ulTL_BRC_FR_32_Tp            1u
#define FRIF_RX_ulTL_MST_GW_TRNSM_FR_254_Tp  0u
#define FRIF_RX_ulCON_VEH                    12u
#define FRIF_RX_ulST_CENG                    13u
#define FRIF_RX_ulSTEA_OFFS                  14u
#define FRIF_RX_ulOFFS_QUAD_EPS              15u
#define FRIF_RX_ulERRM_BN_U                  16u
#define FRIF_RX_ulENERG_DGR_DRDY             17u
#define FRIF_RX_ulTAR_QTA_STRMOM_DV          18u
#define FRIF_RX_ulTAR_STMOM_DV_ACT           19u
#define FRIF_RX_ulTAR_ESTP_VIRT_FTAX         20u
#define FRIF_RX_ulVYAW_VEH                   21u
#define FRIF_RX_ulV_VEH                      22u
#define FRIF_RX_ulACLNY_MASSCNTR             23u
#define FRIF_RX_ulSU_CLE_DRDY_DXP            24u
#define FRIF_RX_ulAVL_RPM_WHL                25u


/* -----------------------------------------------------------------------------
    &&&~ Precompile config
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - If_AsrIfFrPrecompileCRC */
#define FRIF_USE_FRTRCV_API                  STD_ON
#define FRIF_API_AS_MACRO STD_OFF
#define FRIF_DEV_ERROR_DETECT STD_ON
#define FRIF_PROD_ERROR_DETECT STD_OFF
#define FRIF_VERSION_INFO_API STD_ON
#define FRIF_LARGE_RX_HANDLES STD_OFF
#define FRIF_LARGE_TX_HANDLES STD_OFF
#define FRIF_ENABLE_PREPARE_LPDU STD_OFF
#define FRIF_CTRL_ENABLE_API_OPTIMIZATION STD_OFF
#define FRIF_UNIFORMUPDATEBYTEPOS STD_OFF
#define FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS STD_OFF
#define FRIF_MEASURE_JLETASKTIMES STD_OFF
#define FRIF_PDUDIRTYBYTE_USAGE STD_OFF
#define FRIF_JOB_CONCATENATION_ENABLE STD_OFF
#define FRIF_DIRECT_BUFFER_ACCESS_ENABLE STD_OFF
#define FRIF_FIFO_SUPPORT_ENABLE STD_ON
#define FRIF_RELATIVE_ALARM_ENABLE STD_OFF
#define FRIF_CHANNEL_STATUS_ENABLE STD_OFF
#define FRIF_CLOCK_CORRECTION_ENABLE STD_OFF
#define FRIF_SET_EXT_SYNC_DISABLE STD_OFF
#define FRIF_ABORT_COMMUNICATION_DISABLE STD_OFF
#define FRIF_SET_WAKEUP_CHANNEL_DISABLE STD_OFF
#define FRIF_ABSOLUTE_TIMER_API_DISABLE STD_OFF
#define FRIF_TIME_CONVERSION_DISABLE STD_OFF
#define FRIF_REQUEST_COUNTER_HANDLING_DISABLE STD_OFF
#define FRIF_CANCELTRANSMITSUPPORT STD_OFF
#define FRIF_DELAYEDTXCONFSUPPORT STD_OFF
#define FRIF_FREEOPCALLBACKSUPPORT STD_OFF
#define FRIF_RECONFIGLPDUSUPPORT STD_OFF
#define FRIF_READCCCONFIGSUPPORT STD_OFF
#define FRIF_GETSYNCFRAMELISTSUPPORT STD_OFF
#define FRIF_NMVECTORSUPPORT STD_OFF
#define FRIF_DUALCHANNELREDUNDANCYSUPPORT STD_OFF
#define FRIF_USEPDUINFOTYPE STD_OFF
#define FRIF_IDENTITY_MANAGER_CONFIG STD_OFF
#define FRIF_NOREQUESTCOUNTERINITMEMORY STD_ON
/* END of Checksum include for
  - If_AsrIfFrPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ FrTrcv API re-defines
 ----------------------------------------------------------------------------- */

#define FrTrcv_SetTransceiverMode            FrTrcv_30_Tja1080_SetTransceiverMode
#define FrTrcv_GetTransceiverMode            FrTrcv_30_Tja1080_GetTransceiverMode
#define FrTrcv_GetTransceiverWUReason        FrTrcv_30_Tja1080_GetTransceiverWUReason
#define FrTrcv_EnableTransceiverWakeup       FrTrcv_30_Tja1080_EnableTransceiverWakeup
#define FrTrcv_DisableTransceiverWakeup      FrTrcv_30_Tja1080_DisableTransceiverWakeup
#define FrTrcv_ClearTransceiverWakeup        FrTrcv_30_Tja1080_ClearTransceiverWakeup
#define FrTrcv_Cbk_WakeupByTransceiver       FrTrcv_30_Tja1080_Cbk_WakeupByTransceiver



/* -----------------------------------------------------------------------------
    &&&~ Typedefs
 ----------------------------------------------------------------------------- */

typedef uint8 FrIf_FLEIdxType;
typedef uint8 FrIf_NumberOfPduType;


/* -----------------------------------------------------------------------------
    &&&~ Precompile Defines
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - If_AsrIfFrPrecompileCRC */
#define FrIf_MaxNumberOfTxPDUs               21u
#define FrIf_MaxNumberOfTxFLEs               21u
#define FrIf_MaxNumberOfTxFrames             19u
#define FrIf_FramebufferLengthInBytes        254u
#define FrIf_MaxNumberOfTxRequestCounters    0u
#define FrIf_MacroTicksPerCycle              3636u
#define FrIf_MacroTicksLengthInNanoSeconds   1375u
#define FrIf_RxRotation                      0u
#define FrIf_TxRotation                      0u
#define FrIf_NumberOfRxPDUs                  29u
#define FrIf_NumberOfTxPDUs                  21u
#define FrIf_NumberOfTxFLEs                  21u
#define FrIf_NumberOfTxFrames                19u
#define FrIf_InvalidRxHandle                 0x1Eu
#define FrIf_InvalidTxHandle                 0x13u
#define FrIf_NumberOfChannels                1u
/* END of Checksum exclude for
  - If_AsrIfFrPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ externals
 ----------------------------------------------------------------------------- */

#define FRIF_START_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define FRIF_STOP_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"




/* END of Checksum exclude for
  - If_AsrIfFrPrecompileCRC */



/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 214596022
      #error "The magic number of the generated file <c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\SwProject\Source\GenData\FrIf_Cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 214596022
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* FRIF_CFG_H */
