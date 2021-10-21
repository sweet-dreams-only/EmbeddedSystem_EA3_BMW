/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Type.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComOutput/autosar
 *     SW-C Type:  Ap_SrlComOutput2
 *  Generated at:  Thu Feb  2 14:05:14 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# if (defined RTE_CONST_D_ZERO_CNT_U8) || (defined D_ZERO_CNT_U8)
#  if (!defined RTE_CONST_D_ZERO_CNT_U8) || (RTE_CONST_D_ZERO_CNT_U8 != 0U)
#   error "Constant value <D_ZERO_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U8 (0U)
#  define D_ZERO_CNT_U8 (0U)
# endif

# if (defined RTE_CONST_D_MAXCONF_ULS_U8P8) || (defined D_MAXCONF_ULS_U8P8)
#  if (!defined RTE_CONST_D_MAXCONF_ULS_U8P8) || (RTE_CONST_D_MAXCONF_ULS_U8P8 != 256U)
#   error "Constant value <D_MAXCONF_ULS_U8P8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MAXCONF_ULS_U8P8 (256U)
#  define D_MAXCONF_ULS_U8P8 (256U)
# endif

#  define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;
#  define Dem_DTCStatusMaskType_LowerLimit (0U)
#  define Dem_DTCStatusMaskType_UpperLimit (255U)

# define Rte_TypeDef_Dem_EventIdType
typedef uint8 Dem_EventIdType;
# define Dem_EventIdType_LowerLimit (1U)
# define Dem_EventIdType_UpperLimit (89U)

# define Rte_TypeDef_AVL_FORC_GRD
typedef uint16 AVL_FORC_GRD;
# define AVL_FORC_GRD_LowerLimit (0U)
# define AVL_FORC_GRD_UpperLimit (4048U)
# define Rte_InvalidValue_AVL_FORC_GRD (4095U)
# define InvalidValue_AVL_FORC_GRD (4095U)

# define Rte_TypeDef_AVL_PINA_EPS
typedef uint16 AVL_PINA_EPS;
# define AVL_PINA_EPS_LowerLimit (0U)
# define AVL_PINA_EPS_UpperLimit (65534U)
# define Rte_InvalidValue_AVL_PINA_EPS (65535U)
# define InvalidValue_AVL_PINA_EPS (65535U)

# define Rte_TypeDef_AVL_PINA_IDX_ICM
typedef uint16 AVL_PINA_IDX_ICM;
# define AVL_PINA_IDX_ICM_LowerLimit (0U)
# define AVL_PINA_IDX_ICM_UpperLimit (65534U)
# define Rte_InvalidValue_AVL_PINA_IDX_ICM (65535U)
# define InvalidValue_AVL_PINA_IDX_ICM (65535U)

# define Rte_TypeDef_AVL_PWR_EL
typedef uint8 AVL_PWR_EL;
# define AVL_PWR_EL_LowerLimit (0U)
# define AVL_PWR_EL_UpperLimit (240U)
# define Rte_InvalidValue_AVL_PWR_EL (255U)
# define InvalidValue_AVL_PWR_EL (255U)

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_CD_0x04
typedef uint8 CD_0x04;
# define CD_0x04_LowerLimit (0U)
# define CD_0x04_UpperLimit (15U)

# define Rte_TypeDef_CD_0x06
typedef uint8 CD_0x06;
# define CD_0x06_LowerLimit (0U)
# define CD_0x06_UpperLimit (63U)

# define Rte_TypeDef_CD_0x08
typedef uint8 CD_0x08;
# define CD_0x08_LowerLimit (0U)
# define CD_0x08_UpperLimit (255U)

# define Rte_TypeDef_CD_0x20
typedef uint32 CD_0x20;
# define CD_0x20_LowerLimit (0U)
# define CD_0x20_UpperLimit (4294967295U)

# define Rte_TypeDef_CRC8
typedef uint8 CRC8;
# define CRC8_LowerLimit (0U)
# define CRC8_UpperLimit (255U)

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_New_Coding_40
typedef uint8 New_Coding_40;
# define New_Coding_40_LowerLimit (0U)
# define New_Coding_40_UpperLimit (255U)

# define Rte_TypeDef_New_Coding_41
typedef uint8 New_Coding_41;
# define New_Coding_41_LowerLimit (0U)
# define New_Coding_41_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_41 (15U)
# define InvalidValue_New_Coding_41 (15U)

# define Rte_TypeDef_New_Coding_42
typedef uint8 New_Coding_42;
# define New_Coding_42_LowerLimit (0U)
# define New_Coding_42_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_42 (15U)
# define InvalidValue_New_Coding_42 (15U)

# define Rte_TypeDef_New_Coding_43
typedef uint16 New_Coding_43;
# define New_Coding_43_LowerLimit (0U)
# define New_Coding_43_UpperLimit (65534U)
# define Rte_InvalidValue_New_Coding_43 (65535U)
# define InvalidValue_New_Coding_43 (65535U)

# define Rte_TypeDef_New_Coding_45
typedef uint8 New_Coding_45;
# define New_Coding_45_LowerLimit (0U)
# define New_Coding_45_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_45 (15U)
# define InvalidValue_New_Coding_45 (15U)

# define Rte_TypeDef_New_Coding_47
typedef uint8 New_Coding_47;
# define New_Coding_47_LowerLimit (0U)
# define New_Coding_47_UpperLimit (255U)

# define Rte_TypeDef_New_Coding_48
typedef uint8 New_Coding_48;
# define New_Coding_48_LowerLimit (0U)
# define New_Coding_48_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_48 (15U)
# define InvalidValue_New_Coding_48 (15U)

# define Rte_TypeDef_New_Coding_51
typedef uint8 New_Coding_51;
# define New_Coding_51_LowerLimit (0U)
# define New_Coding_51_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_51 (15U)
# define InvalidValue_New_Coding_51 (15U)

# define Rte_TypeDef_New_Coding_52
typedef uint8 New_Coding_52;
# define New_Coding_52_LowerLimit (0U)
# define New_Coding_52_UpperLimit (255U)

# define Rte_TypeDef_OFFS_GRD_MID_EPS
typedef uint16 OFFS_GRD_MID_EPS;
# define OFFS_GRD_MID_EPS_LowerLimit (0U)
# define OFFS_GRD_MID_EPS_UpperLimit (4094U)
# define Rte_InvalidValue_OFFS_GRD_MID_EPS (4095U)
# define InvalidValue_OFFS_GRD_MID_EPS (4095U)

# define Rte_TypeDef_STMOM_QTA_DV
typedef uint16 STMOM_QTA_DV;
# define STMOM_QTA_DV_LowerLimit (0U)
# define STMOM_QTA_DV_UpperLimit (4000U)
# define Rte_InvalidValue_STMOM_QTA_DV (4095U)
# define InvalidValue_STMOM_QTA_DV (4095U)

# define Rte_TypeDef_TOT_STR_EPS
typedef uint16 TOT_STR_EPS;
# define TOT_STR_EPS_LowerLimit (0U)
# define TOT_STR_EPS_UpperLimit (4094U)
# define Rte_InvalidValue_TOT_STR_EPS (4095U)
# define InvalidValue_TOT_STR_EPS (4095U)

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit (0U)
# define UInt16_UpperLimit (65535U)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit (0U)
# define UInt32_UpperLimit (4294967295U)

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;
# define UInt8_LowerLimit (0U)
# define UInt8_UpperLimit (255U)

# define Rte_TypeDef_ALIV_COU_4
typedef uint8 ALIV_COU_4;
# define ALIV_COU_4_LowerLimit (0U)
# define ALIV_COU_4_UpperLimit (15U)
# define Rte_InvalidValue_ALIV_COU_4 (15U)
# define InvalidValue_ALIV_COU_4 (15U)
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_IDX_TORQ_SEN
typedef uint8 IDX_TORQ_SEN;
# define IDX_TORQ_SEN_LowerLimit (0U)
# define IDX_TORQ_SEN_UpperLimit (3U)
# define Rte_InvalidValue_IDX_TORQ_SEN (3U)
# define InvalidValue_IDX_TORQ_SEN (3U)
# if (defined RTE_CONST_Cx0_Initialisierung) || (defined Cx0_Initialisierung)
#  if (!defined RTE_CONST_Cx0_Initialisierung) || (RTE_CONST_Cx0_Initialisierung != 0U)
#   error "Enumeration constant <Cx0_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Initialisierung (0U)
#  define Cx0_Initialisierung (0U)
# endif
# if (defined RTE_CONST_Cx1_Keine_Index_Flanke) || (defined Cx1_Keine_Index_Flanke)
#  if (!defined RTE_CONST_Cx1_Keine_Index_Flanke) || (RTE_CONST_Cx1_Keine_Index_Flanke != 1U)
#   error "Enumeration constant <Cx1_Keine_Index_Flanke> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Keine_Index_Flanke (1U)
#  define Cx1_Keine_Index_Flanke (1U)
# endif
# if (defined RTE_CONST_Cx2_Index_Flanke) || (defined Cx2_Index_Flanke)
#  if (!defined RTE_CONST_Cx2_Index_Flanke) || (RTE_CONST_Cx2_Index_Flanke != 2U)
#   error "Enumeration constant <Cx2_Index_Flanke> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Index_Flanke (2U)
#  define Cx2_Index_Flanke (2U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_NTCNumber
typedef uint16 NTCNumber;
# define NTCNumber_LowerLimit (0U)
# define NTCNumber_UpperLimit (511U)
# if (defined RTE_CONST_NTC_Num_FlashWrapperLgcFlt) || (defined NTC_Num_FlashWrapperLgcFlt)
#  if (!defined RTE_CONST_NTC_Num_FlashWrapperLgcFlt) || (RTE_CONST_NTC_Num_FlashWrapperLgcFlt != 1U)
#   error "Enumeration constant <NTC_Num_FlashWrapperLgcFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashWrapperLgcFlt (1U)
#  define NTC_Num_FlashWrapperLgcFlt (1U)
# endif
# if (defined RTE_CONST_NTC_Num_FlashECCCorr) || (defined NTC_Num_FlashECCCorr)
#  if (!defined RTE_CONST_NTC_Num_FlashECCCorr) || (RTE_CONST_NTC_Num_FlashECCCorr != 2U)
#   error "Enumeration constant <NTC_Num_FlashECCCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashECCCorr (2U)
#  define NTC_Num_FlashECCCorr (2U)
# endif
# if (defined RTE_CONST_NTC_Num_FlashECCMemFlt) || (defined NTC_Num_FlashECCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_FlashECCMemFlt) || (RTE_CONST_NTC_Num_FlashECCMemFlt != 3U)
#   error "Enumeration constant <NTC_Num_FlashECCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashECCMemFlt (3U)
#  define NTC_Num_FlashECCMemFlt (3U)
# endif
# if (defined RTE_CONST_NTC_Num_FlashCRCMemFault) || (defined NTC_Num_FlashCRCMemFault)
#  if (!defined RTE_CONST_NTC_Num_FlashCRCMemFault) || (RTE_CONST_NTC_Num_FlashCRCMemFault != 4U)
#   error "Enumeration constant <NTC_Num_FlashCRCMemFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashCRCMemFault (4U)
#  define NTC_Num_FlashCRCMemFault (4U)
# endif
# if (defined RTE_CONST_NTC_Num_NvMBlkDftActA) || (defined NTC_Num_NvMBlkDftActA)
#  if (!defined RTE_CONST_NTC_Num_NvMBlkDftActA) || (RTE_CONST_NTC_Num_NvMBlkDftActA != 6U)
#   error "Enumeration constant <NTC_Num_NvMBlkDftActA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_NvMBlkDftActA (6U)
#  define NTC_Num_NvMBlkDftActA (6U)
# endif
# if (defined RTE_CONST_NTC_Num_NvMBlkDftActB) || (defined NTC_Num_NvMBlkDftActB)
#  if (!defined RTE_CONST_NTC_Num_NvMBlkDftActB) || (RTE_CONST_NTC_Num_NvMBlkDftActB != 7U)
#   error "Enumeration constant <NTC_Num_NvMBlkDftActB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_NvMBlkDftActB (7U)
#  define NTC_Num_NvMBlkDftActB (7U)
# endif
# if (defined RTE_CONST_NTC_Num_NvMBlkDftActC) || (defined NTC_Num_NvMBlkDftActC)
#  if (!defined RTE_CONST_NTC_Num_NvMBlkDftActC) || (RTE_CONST_NTC_Num_NvMBlkDftActC != 8U)
#   error "Enumeration constant <NTC_Num_NvMBlkDftActC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_NvMBlkDftActC (8U)
#  define NTC_Num_NvMBlkDftActC (8U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentSensorCalOutOfRange) || (defined NTC_Num_CurrentSensorCalOutOfRange)
#  if (!defined RTE_CONST_NTC_Num_CurrentSensorCalOutOfRange) || (RTE_CONST_NTC_Num_CurrentSensorCalOutOfRange != 9U)
#   error "Enumeration constant <NTC_Num_CurrentSensorCalOutOfRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentSensorCalOutOfRange (9U)
#  define NTC_Num_CurrentSensorCalOutOfRange (9U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiag) || (defined NTC_Num_EEPROMDiag)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiag) || (RTE_CONST_NTC_Num_EEPROMDiag != 10U)
#   error "Enumeration constant <NTC_Num_EEPROMDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiag (10U)
#  define NTC_Num_EEPROMDiag (10U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagMtrStr) || (defined NTC_Num_EEPROMDiagMtrStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagMtrStr) || (RTE_CONST_NTC_Num_EEPROMDiagMtrStr != 11U)
#   error "Enumeration constant <NTC_Num_EEPROMDiagMtrStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagMtrStr (11U)
#  define NTC_Num_EEPROMDiagMtrStr (11U)
# endif
# if (defined RTE_CONST_NTC_Num_PriSnsrTrqStorFlt) || (defined NTC_Num_PriSnsrTrqStorFlt)
#  if (!defined RTE_CONST_NTC_Num_PriSnsrTrqStorFlt) || (RTE_CONST_NTC_Num_PriSnsrTrqStorFlt != 12U)
#   error "Enumeration constant <NTC_Num_PriSnsrTrqStorFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PriSnsrTrqStorFlt (12U)
#  define NTC_Num_PriSnsrTrqStorFlt (12U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr) || (defined NTC_Num_EEPROMDiagPosTrimStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr) || (RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr != 13U)
#   error "Enumeration constant <NTC_Num_EEPROMDiagPosTrimStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr (13U)
#  define NTC_Num_EEPROMDiagPosTrimStr (13U)
# endif
# if (defined RTE_CONST_NTC_Num_SecSnsrTrqStorFlt) || (defined NTC_Num_SecSnsrTrqStorFlt)
#  if (!defined RTE_CONST_NTC_Num_SecSnsrTrqStorFlt) || (RTE_CONST_NTC_Num_SecSnsrTrqStorFlt != 14U)
#   error "Enumeration constant <NTC_Num_SecSnsrTrqStorFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SecSnsrTrqStorFlt (14U)
#  define NTC_Num_SecSnsrTrqStorFlt (14U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagPolarityStr) || (defined NTC_Num_EEPROMDiagPolarityStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagPolarityStr) || (RTE_CONST_NTC_Num_EEPROMDiagPolarityStr != 15U)
#   error "Enumeration constant <NTC_Num_EEPROMDiagPolarityStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagPolarityStr (15U)
#  define NTC_Num_EEPROMDiagPolarityStr (15U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_GeneralFlt) || (defined NTC_Num_RAMDiag_GeneralFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_GeneralFlt) || (RTE_CONST_NTC_Num_RAMDiag_GeneralFlt != 16U)
#   error "Enumeration constant <NTC_Num_RAMDiag_GeneralFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_GeneralFlt (16U)
#  define NTC_Num_RAMDiag_GeneralFlt (16U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt) || (defined NTC_Num_RAMDiag_WrprLgcFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt) || (RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt != 17U)
#   error "Enumeration constant <NTC_Num_RAMDiag_WrprLgcFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt (17U)
#  define NTC_Num_RAMDiag_WrprLgcFlt (17U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt) || (defined NTC_Num_RAMDiag_ECCCorrIndFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt) || (RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt != 18U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ECCCorrIndFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
#  define NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt) || (defined NTC_Num_RAMDiag_ECCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt) || (RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt != 19U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ECCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt (19U)
#  define NTC_Num_RAMDiag_ECCMemFlt (19U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt) || (defined NTC_Num_RAMDiag_CRCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt) || (RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt != 20U)
#   error "Enumeration constant <NTC_Num_RAMDiag_CRCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt (20U)
#  define NTC_Num_RAMDiag_CRCMemFlt (20U)
# endif
# if (defined RTE_CONST_NTC_Num_PLLSlipNrcvrl) || (defined NTC_Num_PLLSlipNrcvrl)
#  if (!defined RTE_CONST_NTC_Num_PLLSlipNrcvrl) || (RTE_CONST_NTC_Num_PLLSlipNrcvrl != 22U)
#   error "Enumeration constant <NTC_Num_PLLSlipNrcvrl> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PLLSlipNrcvrl (22U)
#  define NTC_Num_PLLSlipNrcvrl (22U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt) || (defined NTC_Num_RAMDiag_VIMRamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt) || (RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt != 23U)
#   error "Enumeration constant <NTC_Num_RAMDiag_VIMRamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt (23U)
#  define NTC_Num_RAMDiag_VIMRamFlt (23U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt) || (defined NTC_Num_RAMDiag_NHET1RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt != 24U)
#   error "Enumeration constant <NTC_Num_RAMDiag_NHET1RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt (24U)
#  define NTC_Num_RAMDiag_NHET1RamFlt (24U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt) || (defined NTC_Num_RAMDiag_NHET2RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt != 25U)
#   error "Enumeration constant <NTC_Num_RAMDiag_NHET2RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt (25U)
#  define NTC_Num_RAMDiag_NHET2RamFlt (25U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ADC1RamFlt) || (defined NTC_Num_RAMDiag_ADC1RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ADC1RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_ADC1RamFlt != 26U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ADC1RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ADC1RamFlt (26U)
#  define NTC_Num_RAMDiag_ADC1RamFlt (26U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_DCANRamFault) || (defined NTC_Num_RAMDiag_DCANRamFault)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_DCANRamFault) || (RTE_CONST_NTC_Num_RAMDiag_DCANRamFault != 27U)
#   error "Enumeration constant <NTC_Num_RAMDiag_DCANRamFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_DCANRamFault (27U)
#  define NTC_Num_RAMDiag_DCANRamFault (27U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ADC2RamFlt) || (defined NTC_Num_RAMDiag_ADC2RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ADC2RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_ADC2RamFlt != 28U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ADC2RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ADC2RamFlt (28U)
#  define NTC_Num_RAMDiag_ADC2RamFlt (28U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_HETTU1RamFlt) || (defined NTC_Num_RAMDiag_HETTU1RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_HETTU1RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_HETTU1RamFlt != 29U)
#   error "Enumeration constant <NTC_Num_RAMDiag_HETTU1RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_HETTU1RamFlt (29U)
#  define NTC_Num_RAMDiag_HETTU1RamFlt (29U)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_HETTU2RamFlt) || (defined NTC_Num_RAMDiag_HETTU2RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_HETTU2RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_HETTU2RamFlt != 30U)
#   error "Enumeration constant <NTC_Num_RAMDiag_HETTU2RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_HETTU2RamFlt (30U)
#  define NTC_Num_RAMDiag_HETTU2RamFlt (30U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_RegVer) || (defined NTC_Num_CPU_RegVer)
#  if (!defined RTE_CONST_NTC_Num_CPU_RegVer) || (RTE_CONST_NTC_Num_CPU_RegVer != 32U)
#   error "Enumeration constant <NTC_Num_CPU_RegVer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_RegVer (32U)
#  define NTC_Num_CPU_RegVer (32U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_CoreInitFlt) || (defined NTC_Num_CPU_CoreInitFlt)
#  if (!defined RTE_CONST_NTC_Num_CPU_CoreInitFlt) || (RTE_CONST_NTC_Num_CPU_CoreInitFlt != 33U)
#   error "Enumeration constant <NTC_Num_CPU_CoreInitFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_CoreInitFlt (33U)
#  define NTC_Num_CPU_CoreInitFlt (33U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt) || (defined NTC_Num_CPU_CoreRunTimeFlt)
#  if (!defined RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt) || (RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt != 34U)
#   error "Enumeration constant <NTC_Num_CPU_CoreRunTimeFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt (34U)
#  define NTC_Num_CPU_CoreRunTimeFlt (34U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_ClockMon) || (defined NTC_Num_CPU_ClockMon)
#  if (!defined RTE_CONST_NTC_Num_CPU_ClockMon) || (RTE_CONST_NTC_Num_CPU_ClockMon != 35U)
#   error "Enumeration constant <NTC_Num_CPU_ClockMon> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_ClockMon (35U)
#  define NTC_Num_CPU_ClockMon (35U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_eFuseFlt) || (defined NTC_Num_CPU_eFuseFlt)
#  if (!defined RTE_CONST_NTC_Num_CPU_eFuseFlt) || (RTE_CONST_NTC_Num_CPU_eFuseFlt != 36U)
#   error "Enumeration constant <NTC_Num_CPU_eFuseFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_eFuseFlt (36U)
#  define NTC_Num_CPU_eFuseFlt (36U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_MPUViolation) || (defined NTC_Num_CPU_MPUViolation)
#  if (!defined RTE_CONST_NTC_Num_CPU_MPUViolation) || (RTE_CONST_NTC_Num_CPU_MPUViolation != 37U)
#   error "Enumeration constant <NTC_Num_CPU_MPUViolation> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_MPUViolation (37U)
#  define NTC_Num_CPU_MPUViolation (37U)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_FactPrcsErr) || (defined NTC_Num_CPU_FactPrcsErr)
#  if (!defined RTE_CONST_NTC_Num_CPU_FactPrcsErr) || (RTE_CONST_NTC_Num_CPU_FactPrcsErr != 40U)
#   error "Enumeration constant <NTC_Num_CPU_FactPrcsErr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_FactPrcsErr (40U)
#  define NTC_Num_CPU_FactPrcsErr (40U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_InitDiag) || (defined NTC_Num_PropExeDiag_InitDiag)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_InitDiag) || (RTE_CONST_NTC_Num_PropExeDiag_InitDiag != 41U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_InitDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_InitDiag (41U)
#  define NTC_Num_PropExeDiag_InitDiag (41U)
# endif
# if (defined RTE_CONST_NTC_Num_PrgFlwDeadlnFlt) || (defined NTC_Num_PrgFlwDeadlnFlt)
#  if (!defined RTE_CONST_NTC_Num_PrgFlwDeadlnFlt) || (RTE_CONST_NTC_Num_PrgFlwDeadlnFlt != 42U)
#   error "Enumeration constant <NTC_Num_PrgFlwDeadlnFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PrgFlwDeadlnFlt (42U)
#  define NTC_Num_PrgFlwDeadlnFlt (42U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag) || (defined NTC_Num_PropExeDiag_RunTimeDiag)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag) || (RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag != 43U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_RunTimeDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag (43U)
#  define NTC_Num_PropExeDiag_RunTimeDiag (43U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_COPTimeout) || (defined NTC_Num_PropExeDiag_COPTimeout)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_COPTimeout) || (RTE_CONST_NTC_Num_PropExeDiag_COPTimeout != 44U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_COPTimeout> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_COPTimeout (44U)
#  define NTC_Num_PropExeDiag_COPTimeout (44U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_PrefetchAbort) || (defined NTC_Num_PropExeDiag_PrefetchAbort)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_PrefetchAbort) || (RTE_CONST_NTC_Num_PropExeDiag_PrefetchAbort != 48U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_PrefetchAbort> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_PrefetchAbort (48U)
#  define NTC_Num_PropExeDiag_PrefetchAbort (48U)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_DataAbort) || (defined NTC_Num_PropExeDiag_DataAbort)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_DataAbort) || (RTE_CONST_NTC_Num_PropExeDiag_DataAbort != 49U)
#   error "Enumeration constant <NTC_Num_PropExeDiag_DataAbort> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_DataAbort (49U)
#  define NTC_Num_PropExeDiag_DataAbort (49U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADC1Flt) || (defined NTC_Num_PerDiag_ADC1Flt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADC1Flt) || (RTE_CONST_NTC_Num_PerDiag_ADC1Flt != 50U)
#   error "Enumeration constant <NTC_Num_PerDiag_ADC1Flt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADC1Flt (50U)
#  define NTC_Num_PerDiag_ADC1Flt (50U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADC2Flt) || (defined NTC_Num_PerDiag_ADC2Flt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADC2Flt) || (RTE_CONST_NTC_Num_PerDiag_ADC2Flt != 51U)
#   error "Enumeration constant <NTC_Num_PerDiag_ADC2Flt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADC2Flt (51U)
#  define NTC_Num_PerDiag_ADC2Flt (51U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt) || (defined NTC_Num_PerDiag_ADCCrossChkFlt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt) || (RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt != 52U)
#   error "Enumeration constant <NTC_Num_PerDiag_ADCCrossChkFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt (52U)
#  define NTC_Num_PerDiag_ADCCrossChkFlt (52U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_IllegalAccess) || (defined NTC_Num_PerDiag_IllegalAccess)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_IllegalAccess) || (RTE_CONST_NTC_Num_PerDiag_IllegalAccess != 53U)
#   error "Enumeration constant <NTC_Num_PerDiag_IllegalAccess> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_IllegalAccess (53U)
#  define NTC_Num_PerDiag_IllegalAccess (53U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_DMAFlt) || (defined NTC_Num_PerDiag_DMAFlt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_DMAFlt) || (RTE_CONST_NTC_Num_PerDiag_DMAFlt != 54U)
#   error "Enumeration constant <NTC_Num_PerDiag_DMAFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_DMAFlt (54U)
#  define NTC_Num_PerDiag_DMAFlt (54U)
# endif
# if (defined RTE_CONST_NTC_Num_PeripheralStartupFlt) || (defined NTC_Num_PeripheralStartupFlt)
#  if (!defined RTE_CONST_NTC_Num_PeripheralStartupFlt) || (RTE_CONST_NTC_Num_PeripheralStartupFlt != 55U)
#   error "Enumeration constant <NTC_Num_PeripheralStartupFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PeripheralStartupFlt (55U)
#  define NTC_Num_PeripheralStartupFlt (55U)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_CPUWarning) || (defined NTC_Num_PerDiag_CPUWarning)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_CPUWarning) || (RTE_CONST_NTC_Num_PerDiag_CPUWarning != 63U)
#   error "Enumeration constant <NTC_Num_PerDiag_CPUWarning> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_CPUWarning (63U)
#  define NTC_Num_PerDiag_CPUWarning (63U)
# endif
# if (defined RTE_CONST_NTC_Num_TmpMonFunc) || (defined NTC_Num_TmpMonFunc)
#  if (!defined RTE_CONST_NTC_Num_TmpMonFunc) || (RTE_CONST_NTC_Num_TmpMonFunc != 64U)
#   error "Enumeration constant <NTC_Num_TmpMonFunc> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TmpMonFunc (64U)
#  define NTC_Num_TmpMonFunc (64U)
# endif
# if (defined RTE_CONST_NTC_Num_TmpMonRunTimeFlt) || (defined NTC_Num_TmpMonRunTimeFlt)
#  if (!defined RTE_CONST_NTC_Num_TmpMonRunTimeFlt) || (RTE_CONST_NTC_Num_TmpMonRunTimeFlt != 65U)
#   error "Enumeration constant <NTC_Num_TmpMonRunTimeFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TmpMonRunTimeFlt (65U)
#  define NTC_Num_TmpMonRunTimeFlt (65U)
# endif
# if (defined RTE_CONST_NTC_Num_PowerRelayInitFlt) || (defined NTC_Num_PowerRelayInitFlt)
#  if (!defined RTE_CONST_NTC_Num_PowerRelayInitFlt) || (RTE_CONST_NTC_Num_PowerRelayInitFlt != 66U)
#   error "Enumeration constant <NTC_Num_PowerRelayInitFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PowerRelayInitFlt (66U)
#  define NTC_Num_PowerRelayInitFlt (66U)
# endif
# if (defined RTE_CONST_NTC_Num_PrechargeFailure) || (defined NTC_Num_PrechargeFailure)
#  if (!defined RTE_CONST_NTC_Num_PrechargeFailure) || (RTE_CONST_NTC_Num_PrechargeFailure != 67U)
#   error "Enumeration constant <NTC_Num_PrechargeFailure> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PrechargeFailure (67U)
#  define NTC_Num_PrechargeFailure (67U)
# endif
# if (defined RTE_CONST_NTC_Num_PowerRelayRunFlt) || (defined NTC_Num_PowerRelayRunFlt)
#  if (!defined RTE_CONST_NTC_Num_PowerRelayRunFlt) || (RTE_CONST_NTC_Num_PowerRelayRunFlt != 68U)
#   error "Enumeration constant <NTC_Num_PowerRelayRunFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PowerRelayRunFlt (68U)
#  define NTC_Num_PowerRelayRunFlt (68U)
# endif
# if (defined RTE_CONST_NTC_Num_Thermistor) || (defined NTC_Num_Thermistor)
#  if (!defined RTE_CONST_NTC_Num_Thermistor) || (RTE_CONST_NTC_Num_Thermistor != 69U)
#   error "Enumeration constant <NTC_Num_Thermistor> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Thermistor (69U)
#  define NTC_Num_Thermistor (69U)
# endif
# if (defined RTE_CONST_NTC_Num_RefSupplyVltg) || (defined NTC_Num_RefSupplyVltg)
#  if (!defined RTE_CONST_NTC_Num_RefSupplyVltg) || (RTE_CONST_NTC_Num_RefSupplyVltg != 70U)
#   error "Enumeration constant <NTC_Num_RefSupplyVltg> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RefSupplyVltg (70U)
#  define NTC_Num_RefSupplyVltg (70U)
# endif
# if (defined RTE_CONST_NTC_Num_TrcvrInterfaceFlt) || (defined NTC_Num_TrcvrInterfaceFlt)
#  if (!defined RTE_CONST_NTC_Num_TrcvrInterfaceFlt) || (RTE_CONST_NTC_Num_TrcvrInterfaceFlt != 71U)
#   error "Enumeration constant <NTC_Num_TrcvrInterfaceFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrcvrInterfaceFlt (71U)
#  define NTC_Num_TrcvrInterfaceFlt (71U)
# endif
# if (defined RTE_CONST_NTC_Num_CPUSupplyOvervoltage) || (defined NTC_Num_CPUSupplyOvervoltage)
#  if (!defined RTE_CONST_NTC_Num_CPUSupplyOvervoltage) || (RTE_CONST_NTC_Num_CPUSupplyOvervoltage != 72U)
#   error "Enumeration constant <NTC_Num_CPUSupplyOvervoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPUSupplyOvervoltage (72U)
#  define NTC_Num_CPUSupplyOvervoltage (72U)
# endif
# if (defined RTE_CONST_NTC_Num_BattVltgMeasdCorrlnFlt) || (defined NTC_Num_BattVltgMeasdCorrlnFlt)
#  if (!defined RTE_CONST_NTC_Num_BattVltgMeasdCorrlnFlt) || (RTE_CONST_NTC_Num_BattVltgMeasdCorrlnFlt != 73U)
#   error "Enumeration constant <NTC_Num_BattVltgMeasdCorrlnFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BattVltgMeasdCorrlnFlt (73U)
#  define NTC_Num_BattVltgMeasdCorrlnFlt (73U)
# endif
# if (defined RTE_CONST_NTC_Num_IvtrPwrDiscnctFailr) || (defined NTC_Num_IvtrPwrDiscnctFailr)
#  if (!defined RTE_CONST_NTC_Num_IvtrPwrDiscnctFailr) || (RTE_CONST_NTC_Num_IvtrPwrDiscnctFailr != 74U)
#   error "Enumeration constant <NTC_Num_IvtrPwrDiscnctFailr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IvtrPwrDiscnctFailr (74U)
#  define NTC_Num_IvtrPwrDiscnctFailr (74U)
# endif
# if (defined RTE_CONST_NTC_Num_PowerRelayInit2Flt) || (defined NTC_Num_PowerRelayInit2Flt)
#  if (!defined RTE_CONST_NTC_Num_PowerRelayInit2Flt) || (RTE_CONST_NTC_Num_PowerRelayInit2Flt != 75U)
#   error "Enumeration constant <NTC_Num_PowerRelayInit2Flt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PowerRelayInit2Flt (75U)
#  define NTC_Num_PowerRelayInit2Flt (75U)
# endif
# if (defined RTE_CONST_NTC_Num_GateDrvFltInProcess) || (defined NTC_Num_GateDrvFltInProcess)
#  if (!defined RTE_CONST_NTC_Num_GateDrvFltInProcess) || (RTE_CONST_NTC_Num_GateDrvFltInProcess != 76U)
#   error "Enumeration constant <NTC_Num_GateDrvFltInProcess> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_GateDrvFltInProcess (76U)
#  define NTC_Num_GateDrvFltInProcess (76U)
# endif
# if (defined RTE_CONST_NTC_Num_GateDrvFlt) || (defined NTC_Num_GateDrvFlt)
#  if (!defined RTE_CONST_NTC_Num_GateDrvFlt) || (RTE_CONST_NTC_Num_GateDrvFlt != 77U)
#   error "Enumeration constant <NTC_Num_GateDrvFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_GateDrvFlt (77U)
#  define NTC_Num_GateDrvFlt (77U)
# endif
# if (defined RTE_CONST_NTC_Num_OnStateSingleFET) || (defined NTC_Num_OnStateSingleFET)
#  if (!defined RTE_CONST_NTC_Num_OnStateSingleFET) || (RTE_CONST_NTC_Num_OnStateSingleFET != 78U)
#   error "Enumeration constant <NTC_Num_OnStateSingleFET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OnStateSingleFET (78U)
#  define NTC_Num_OnStateSingleFET (78U)
# endif
# if (defined RTE_CONST_NTC_Num_OnStateMultiFET) || (defined NTC_Num_OnStateMultiFET)
#  if (!defined RTE_CONST_NTC_Num_OnStateMultiFET) || (RTE_CONST_NTC_Num_OnStateMultiFET != 79U)
#   error "Enumeration constant <NTC_Num_OnStateMultiFET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OnStateMultiFET (79U)
#  define NTC_Num_OnStateMultiFET (79U)
# endif
# if (defined RTE_CONST_NTC_Num_PhaseVoltageVerf) || (defined NTC_Num_PhaseVoltageVerf)
#  if (!defined RTE_CONST_NTC_Num_PhaseVoltageVerf) || (RTE_CONST_NTC_Num_PhaseVoltageVerf != 80U)
#   error "Enumeration constant <NTC_Num_PhaseVoltageVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PhaseVoltageVerf (80U)
#  define NTC_Num_PhaseVoltageVerf (80U)
# endif
# if (defined RTE_CONST_NTC_Num_PhaseDscnt) || (defined NTC_Num_PhaseDscnt)
#  if (!defined RTE_CONST_NTC_Num_PhaseDscnt) || (RTE_CONST_NTC_Num_PhaseDscnt != 81U)
#   error "Enumeration constant <NTC_Num_PhaseDscnt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PhaseDscnt (81U)
#  define NTC_Num_PhaseDscnt (81U)
# endif
# if (defined RTE_CONST_NTC_Num_DigPhaseVoltageVerf) || (defined NTC_Num_DigPhaseVoltageVerf)
#  if (!defined RTE_CONST_NTC_Num_DigPhaseVoltageVerf) || (RTE_CONST_NTC_Num_DigPhaseVoltageVerf != 82U)
#   error "Enumeration constant <NTC_Num_DigPhaseVoltageVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigPhaseVoltageVerf (82U)
#  define NTC_Num_DigPhaseVoltageVerf (82U)
# endif
# if (defined RTE_CONST_NTC_Num_PhaseDscntFailedDisable) || (defined NTC_Num_PhaseDscntFailedDisable)
#  if (!defined RTE_CONST_NTC_Num_PhaseDscntFailedDisable) || (RTE_CONST_NTC_Num_PhaseDscntFailedDisable != 83U)
#   error "Enumeration constant <NTC_Num_PhaseDscntFailedDisable> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PhaseDscntFailedDisable (83U)
#  define NTC_Num_PhaseDscntFailedDisable (83U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeas1) || (defined NTC_Num_CurrentMeas1)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeas1) || (RTE_CONST_NTC_Num_CurrentMeas1 != 84U)
#   error "Enumeration constant <NTC_Num_CurrentMeas1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeas1 (84U)
#  define NTC_Num_CurrentMeas1 (84U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeas2) || (defined NTC_Num_CurrentMeas2)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeas2) || (RTE_CONST_NTC_Num_CurrentMeas2 != 85U)
#   error "Enumeration constant <NTC_Num_CurrentMeas2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeas2 (85U)
#  define NTC_Num_CurrentMeas2 (85U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeasCrossChk) || (defined NTC_Num_CurrentMeasCrossChk)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeasCrossChk) || (RTE_CONST_NTC_Num_CurrentMeasCrossChk != 86U)
#   error "Enumeration constant <NTC_Num_CurrentMeasCrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeasCrossChk (86U)
#  define NTC_Num_CurrentMeasCrossChk (86U)
# endif
# if (defined RTE_CONST_NTC_Num_PDSupplyOverVoltage) || (defined NTC_Num_PDSupplyOverVoltage)
#  if (!defined RTE_CONST_NTC_Num_PDSupplyOverVoltage) || (RTE_CONST_NTC_Num_PDSupplyOverVoltage != 87U)
#   error "Enumeration constant <NTC_Num_PDSupplyOverVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PDSupplyOverVoltage (87U)
#  define NTC_Num_PDSupplyOverVoltage (87U)
# endif
# if (defined RTE_CONST_NTC_Num_ChargePumpUnderVoltage) || (defined NTC_Num_ChargePumpUnderVoltage)
#  if (!defined RTE_CONST_NTC_Num_ChargePumpUnderVoltage) || (RTE_CONST_NTC_Num_ChargePumpUnderVoltage != 88U)
#   error "Enumeration constant <NTC_Num_ChargePumpUnderVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ChargePumpUnderVoltage (88U)
#  define NTC_Num_ChargePumpUnderVoltage (88U)
# endif
# if (defined RTE_CONST_NTC_Num_Ivtr2PwrDiscnctFailr) || (defined NTC_Num_Ivtr2PwrDiscnctFailr)
#  if (!defined RTE_CONST_NTC_Num_Ivtr2PwrDiscnctFailr) || (RTE_CONST_NTC_Num_Ivtr2PwrDiscnctFailr != 90U)
#   error "Enumeration constant <NTC_Num_Ivtr2PwrDiscnctFailr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Ivtr2PwrDiscnctFailr (90U)
#  define NTC_Num_Ivtr2PwrDiscnctFailr (90U)
# endif
# if (defined RTE_CONST_NTC_Num_SysVltgCorrlnFlt) || (defined NTC_Num_SysVltgCorrlnFlt)
#  if (!defined RTE_CONST_NTC_Num_SysVltgCorrlnFlt) || (RTE_CONST_NTC_Num_SysVltgCorrlnFlt != 91U)
#   error "Enumeration constant <NTC_Num_SysVltgCorrlnFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysVltgCorrlnFlt (91U)
#  define NTC_Num_SysVltgCorrlnFlt (91U)
# endif
# if (defined RTE_CONST_NTC_Num_Inv2GateDrvFltInProcess) || (defined NTC_Num_Inv2GateDrvFltInProcess)
#  if (!defined RTE_CONST_NTC_Num_Inv2GateDrvFltInProcess) || (RTE_CONST_NTC_Num_Inv2GateDrvFltInProcess != 92U)
#   error "Enumeration constant <NTC_Num_Inv2GateDrvFltInProcess> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Inv2GateDrvFltInProcess (92U)
#  define NTC_Num_Inv2GateDrvFltInProcess (92U)
# endif
# if (defined RTE_CONST_NTC_Num_Inv2GateDrvFlt) || (defined NTC_Num_Inv2GateDrvFlt)
#  if (!defined RTE_CONST_NTC_Num_Inv2GateDrvFlt) || (RTE_CONST_NTC_Num_Inv2GateDrvFlt != 93U)
#   error "Enumeration constant <NTC_Num_Inv2GateDrvFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Inv2GateDrvFlt (93U)
#  define NTC_Num_Inv2GateDrvFlt (93U)
# endif
# if (defined RTE_CONST_NTC_Num_Inv2OnStateSingleFET) || (defined NTC_Num_Inv2OnStateSingleFET)
#  if (!defined RTE_CONST_NTC_Num_Inv2OnStateSingleFET) || (RTE_CONST_NTC_Num_Inv2OnStateSingleFET != 94U)
#   error "Enumeration constant <NTC_Num_Inv2OnStateSingleFET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Inv2OnStateSingleFET (94U)
#  define NTC_Num_Inv2OnStateSingleFET (94U)
# endif
# if (defined RTE_CONST_NTC_Num_EcuIdnFlt) || (defined NTC_Num_EcuIdnFlt)
#  if (!defined RTE_CONST_NTC_Num_EcuIdnFlt) || (RTE_CONST_NTC_Num_EcuIdnFlt != 95U)
#   error "Enumeration constant <NTC_Num_EcuIdnFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EcuIdnFlt (95U)
#  define NTC_Num_EcuIdnFlt (95U)
# endif
# if (defined RTE_CONST_NTC_Num_HwTrqSensor) || (defined NTC_Num_HwTrqSensor)
#  if (!defined RTE_CONST_NTC_Num_HwTrqSensor) || (RTE_CONST_NTC_Num_HwTrqSensor != 96U)
#   error "Enumeration constant <NTC_Num_HwTrqSensor> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HwTrqSensor (96U)
#  define NTC_Num_HwTrqSensor (96U)
# endif
# if (defined RTE_CONST_NTC_Num_AnaVsDigHwTrq) || (defined NTC_Num_AnaVsDigHwTrq)
#  if (!defined RTE_CONST_NTC_Num_AnaVsDigHwTrq) || (RTE_CONST_NTC_Num_AnaVsDigHwTrq != 97U)
#   error "Enumeration constant <NTC_Num_AnaVsDigHwTrq> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AnaVsDigHwTrq (97U)
#  define NTC_Num_AnaVsDigHwTrq (97U)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorRecoveryFlt) || (defined NTC_Num_TrqSensorRecoveryFlt)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorRecoveryFlt) || (RTE_CONST_NTC_Num_TrqSensorRecoveryFlt != 98U)
#   error "Enumeration constant <NTC_Num_TrqSensorRecoveryFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorRecoveryFlt (98U)
#  define NTC_Num_TrqSensorRecoveryFlt (98U)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorScaleInvalid) || (defined NTC_Num_TrqSensorScaleInvalid)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorScaleInvalid) || (RTE_CONST_NTC_Num_TrqSensorScaleInvalid != 100U)
#   error "Enumeration constant <NTC_Num_TrqSensorScaleInvalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorScaleInvalid (100U)
#  define NTC_Num_TrqSensorScaleInvalid (100U)
# endif
# if (defined RTE_CONST_NTC_Num_T1vsT2) || (defined NTC_Num_T1vsT2)
#  if (!defined RTE_CONST_NTC_Num_T1vsT2) || (RTE_CONST_NTC_Num_T1vsT2 != 101U)
#   error "Enumeration constant <NTC_Num_T1vsT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T1vsT2 (101U)
#  define NTC_Num_T1vsT2 (101U)
# endif
# if (defined RTE_CONST_NTC_Num_T1OutofRange) || (defined NTC_Num_T1OutofRange)
#  if (!defined RTE_CONST_NTC_Num_T1OutofRange) || (RTE_CONST_NTC_Num_T1OutofRange != 102U)
#   error "Enumeration constant <NTC_Num_T1OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T1OutofRange (102U)
#  define NTC_Num_T1OutofRange (102U)
# endif
# if (defined RTE_CONST_NTC_Num_T2OutofRange) || (defined NTC_Num_T2OutofRange)
#  if (!defined RTE_CONST_NTC_Num_T2OutofRange) || (RTE_CONST_NTC_Num_T2OutofRange != 103U)
#   error "Enumeration constant <NTC_Num_T2OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T2OutofRange (103U)
#  define NTC_Num_T2OutofRange (103U)
# endif
# if (defined RTE_CONST_NTC_Num_DigT1vsT2) || (defined NTC_Num_DigT1vsT2)
#  if (!defined RTE_CONST_NTC_Num_DigT1vsT2) || (RTE_CONST_NTC_Num_DigT1vsT2 != 104U)
#   error "Enumeration constant <NTC_Num_DigT1vsT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT1vsT2 (104U)
#  define NTC_Num_DigT1vsT2 (104U)
# endif
# if (defined RTE_CONST_NTC_Num_DigT1OutofRange) || (defined NTC_Num_DigT1OutofRange)
#  if (!defined RTE_CONST_NTC_Num_DigT1OutofRange) || (RTE_CONST_NTC_Num_DigT1OutofRange != 105U)
#   error "Enumeration constant <NTC_Num_DigT1OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT1OutofRange (105U)
#  define NTC_Num_DigT1OutofRange (105U)
# endif
# if (defined RTE_CONST_NTC_Num_DigT2OutofRange) || (defined NTC_Num_DigT2OutofRange)
#  if (!defined RTE_CONST_NTC_Num_DigT2OutofRange) || (RTE_CONST_NTC_Num_DigT2OutofRange != 106U)
#   error "Enumeration constant <NTC_Num_DigT2OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT2OutofRange (106U)
#  define NTC_Num_DigT2OutofRange (106U)
# endif
# if (defined RTE_CONST_NTC_Num_RedT1vsT2) || (defined NTC_Num_RedT1vsT2)
#  if (!defined RTE_CONST_NTC_Num_RedT1vsT2) || (RTE_CONST_NTC_Num_RedT1vsT2 != 107U)
#   error "Enumeration constant <NTC_Num_RedT1vsT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RedT1vsT2 (107U)
#  define NTC_Num_RedT1vsT2 (107U)
# endif
# if (defined RTE_CONST_NTC_Num_HWACrossChecks) || (defined NTC_Num_HWACrossChecks)
#  if (!defined RTE_CONST_NTC_Num_HWACrossChecks) || (RTE_CONST_NTC_Num_HWACrossChecks != 108U)
#   error "Enumeration constant <NTC_Num_HWACrossChecks> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWACrossChecks (108U)
#  define NTC_Num_HWACrossChecks (108U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASnsrCommFault) || (defined NTC_Num_HWASnsrCommFault)
#  if (!defined RTE_CONST_NTC_Num_HWASnsrCommFault) || (RTE_CONST_NTC_Num_HWASnsrCommFault != 109U)
#   error "Enumeration constant <NTC_Num_HWASnsrCommFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASnsrCommFault (109U)
#  define NTC_Num_HWASnsrCommFault (109U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorRel) || (defined NTC_Num_HWASensorRel)
#  if (!defined RTE_CONST_NTC_Num_HWASensorRel) || (RTE_CONST_NTC_Num_HWASensorRel != 110U)
#   error "Enumeration constant <NTC_Num_HWASensorRel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorRel (110U)
#  define NTC_Num_HWASensorRel (110U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorAbs) || (defined NTC_Num_HWASensorAbs)
#  if (!defined RTE_CONST_NTC_Num_HWASensorAbs) || (RTE_CONST_NTC_Num_HWASensorAbs != 111U)
#   error "Enumeration constant <NTC_Num_HWASensorAbs> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorAbs (111U)
#  define NTC_Num_HWASensorAbs (111U)
# endif
# if (defined RTE_CONST_NTC_Num_PriMSB_SinCosCorr) || (defined NTC_Num_PriMSB_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_PriMSB_SinCosCorr) || (RTE_CONST_NTC_Num_PriMSB_SinCosCorr != 112U)
#   error "Enumeration constant <NTC_Num_PriMSB_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PriMSB_SinCosCorr (112U)
#  define NTC_Num_PriMSB_SinCosCorr (112U)
# endif
# if (defined RTE_CONST_NTC_Num_SecMSB_SinCosCorr) || (defined NTC_Num_SecMSB_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_SecMSB_SinCosCorr) || (RTE_CONST_NTC_Num_SecMSB_SinCosCorr != 113U)
#   error "Enumeration constant <NTC_Num_SecMSB_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SecMSB_SinCosCorr (113U)
#  define NTC_Num_SecMSB_SinCosCorr (113U)
# endif
# if (defined RTE_CONST_NTC_Num_PriVsSec_SinCosCorr) || (defined NTC_Num_PriVsSec_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_PriVsSec_SinCosCorr) || (RTE_CONST_NTC_Num_PriVsSec_SinCosCorr != 114U)
#   error "Enumeration constant <NTC_Num_PriVsSec_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PriVsSec_SinCosCorr (114U)
#  define NTC_Num_PriVsSec_SinCosCorr (114U)
# endif
# if (defined RTE_CONST_NTC_Num_DigMSBFlt) || (defined NTC_Num_DigMSBFlt)
#  if (!defined RTE_CONST_NTC_Num_DigMSBFlt) || (RTE_CONST_NTC_Num_DigMSBFlt != 115U)
#   error "Enumeration constant <NTC_Num_DigMSBFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigMSBFlt (115U)
#  define NTC_Num_DigMSBFlt (115U)
# endif
# if (defined RTE_CONST_NTC_Num_MtrVelFlt) || (defined NTC_Num_MtrVelFlt)
#  if (!defined RTE_CONST_NTC_Num_MtrVelFlt) || (RTE_CONST_NTC_Num_MtrVelFlt != 116U)
#   error "Enumeration constant <NTC_Num_MtrVelFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MtrVelFlt (116U)
#  define NTC_Num_MtrVelFlt (116U)
# endif
# if (defined RTE_CONST_NTC_Num_HWAtoMtrAngleCorr) || (defined NTC_Num_HWAtoMtrAngleCorr)
#  if (!defined RTE_CONST_NTC_Num_HWAtoMtrAngleCorr) || (RTE_CONST_NTC_Num_HWAtoMtrAngleCorr != 117U)
#   error "Enumeration constant <NTC_Num_HWAtoMtrAngleCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWAtoMtrAngleCorr (117U)
#  define NTC_Num_HWAtoMtrAngleCorr (117U)
# endif
# if (defined RTE_CONST_NTC_Num_RedPriVsSec_SinCosCorr) || (defined NTC_Num_RedPriVsSec_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_RedPriVsSec_SinCosCorr) || (RTE_CONST_NTC_Num_RedPriVsSec_SinCosCorr != 118U)
#   error "Enumeration constant <NTC_Num_RedPriVsSec_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RedPriVsSec_SinCosCorr (118U)
#  define NTC_Num_RedPriVsSec_SinCosCorr (118U)
# endif
# if (defined RTE_CONST_NTC_Num_ImcArbrFault) || (defined NTC_Num_ImcArbrFault)
#  if (!defined RTE_CONST_NTC_Num_ImcArbrFault) || (RTE_CONST_NTC_Num_ImcArbrFault != 127U)
#   error "Enumeration constant <NTC_Num_ImcArbrFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ImcArbrFault (127U)
#  define NTC_Num_ImcArbrFault (127U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_PosLoss) || (defined NTC_Num_TurnCntr_PosLoss)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_PosLoss) || (RTE_CONST_NTC_Num_TurnCntr_PosLoss != 128U)
#   error "Enumeration constant <NTC_Num_TurnCntr_PosLoss> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_PosLoss (128U)
#  define NTC_Num_TurnCntr_PosLoss (128U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_MicroProcFlt) || (defined NTC_Num_TurnCntr_MicroProcFlt)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_MicroProcFlt) || (RTE_CONST_NTC_Num_TurnCntr_MicroProcFlt != 129U)
#   error "Enumeration constant <NTC_Num_TurnCntr_MicroProcFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_MicroProcFlt (129U)
#  define NTC_Num_TurnCntr_MicroProcFlt (129U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_SensorPosFlt) || (defined NTC_Num_TurnCntr_SensorPosFlt)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_SensorPosFlt) || (RTE_CONST_NTC_Num_TurnCntr_SensorPosFlt != 130U)
#   error "Enumeration constant <NTC_Num_TurnCntr_SensorPosFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_SensorPosFlt (130U)
#  define NTC_Num_TurnCntr_SensorPosFlt (130U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_SpiComFlt) || (defined NTC_Num_TurnCntr_SpiComFlt)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_SpiComFlt) || (RTE_CONST_NTC_Num_TurnCntr_SpiComFlt != 131U)
#   error "Enumeration constant <NTC_Num_TurnCntr_SpiComFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_SpiComFlt (131U)
#  define NTC_Num_TurnCntr_SpiComFlt (131U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_HighQuiescCur) || (defined NTC_Num_TurnCntr_HighQuiescCur)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_HighQuiescCur) || (RTE_CONST_NTC_Num_TurnCntr_HighQuiescCur != 132U)
#   error "Enumeration constant <NTC_Num_TurnCntr_HighQuiescCur> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_HighQuiescCur (132U)
#  define NTC_Num_TurnCntr_HighQuiescCur (132U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_MainResets) || (defined NTC_Num_TurnCntr_MainResets)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_MainResets) || (RTE_CONST_NTC_Num_TurnCntr_MainResets != 133U)
#   error "Enumeration constant <NTC_Num_TurnCntr_MainResets> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_MainResets (133U)
#  define NTC_Num_TurnCntr_MainResets (133U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_PosLossNotSpdDep) || (defined NTC_Num_TurnCntr_PosLossNotSpdDep)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_PosLossNotSpdDep) || (RTE_CONST_NTC_Num_TurnCntr_PosLossNotSpdDep != 134U)
#   error "Enumeration constant <NTC_Num_TurnCntr_PosLossNotSpdDep> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
#  define NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_SpiDataFlt) || (defined NTC_Num_TurnCntr_SpiDataFlt)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_SpiDataFlt) || (RTE_CONST_NTC_Num_TurnCntr_SpiDataFlt != 135U)
#   error "Enumeration constant <NTC_Num_TurnCntr_SpiDataFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_SpiDataFlt (135U)
#  define NTC_Num_TurnCntr_SpiDataFlt (135U)
# endif
# if (defined RTE_CONST_NTC_Num_KinematicIntDiag) || (defined NTC_Num_KinematicIntDiag)
#  if (!defined RTE_CONST_NTC_Num_KinematicIntDiag) || (RTE_CONST_NTC_Num_KinematicIntDiag != 144U)
#   error "Enumeration constant <NTC_Num_KinematicIntDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_KinematicIntDiag (144U)
#  define NTC_Num_KinematicIntDiag (144U)
# endif
# if (defined RTE_CONST_NTC_Num_HighFriction) || (defined NTC_Num_HighFriction)
#  if (!defined RTE_CONST_NTC_Num_HighFriction) || (RTE_CONST_NTC_Num_HighFriction != 145U)
#   error "Enumeration constant <NTC_Num_HighFriction> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HighFriction (145U)
#  define NTC_Num_HighFriction (145U)
# endif
# if (defined RTE_CONST_NTC_Num_DutyCycleExceeded) || (defined NTC_Num_DutyCycleExceeded)
#  if (!defined RTE_CONST_NTC_Num_DutyCycleExceeded) || (RTE_CONST_NTC_Num_DutyCycleExceeded != 148U)
#   error "Enumeration constant <NTC_Num_DutyCycleExceeded> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DutyCycleExceeded (148U)
#  define NTC_Num_DutyCycleExceeded (148U)
# endif
# if (defined RTE_CONST_NTC_Num_AbsTempThermLimit) || (defined NTC_Num_AbsTempThermLimit)
#  if (!defined RTE_CONST_NTC_Num_AbsTempThermLimit) || (RTE_CONST_NTC_Num_AbsTempThermLimit != 149U)
#   error "Enumeration constant <NTC_Num_AbsTempThermLimit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AbsTempThermLimit (149U)
#  define NTC_Num_AbsTempThermLimit (149U)
# endif
# if (defined RTE_CONST_NTC_Num_EcuCrossChk) || (defined NTC_Num_EcuCrossChk)
#  if (!defined RTE_CONST_NTC_Num_EcuCrossChk) || (RTE_CONST_NTC_Num_EcuCrossChk != 150U)
#   error "Enumeration constant <NTC_Num_EcuCrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EcuCrossChk (150U)
#  define NTC_Num_EcuCrossChk (150U)
# endif
# if (defined RTE_CONST_NTC_Num_LatchActive) || (defined NTC_Num_LatchActive)
#  if (!defined RTE_CONST_NTC_Num_LatchActive) || (RTE_CONST_NTC_Num_LatchActive != 160U)
#   error "Enumeration constant <NTC_Num_LatchActive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LatchActive (160U)
#  define NTC_Num_LatchActive (160U)
# endif
# if (defined RTE_CONST_NTC_Num_LimpHomeIgnitionCounter) || (defined NTC_Num_LimpHomeIgnitionCounter)
#  if (!defined RTE_CONST_NTC_Num_LimpHomeIgnitionCounter) || (RTE_CONST_NTC_Num_LimpHomeIgnitionCounter != 161U)
#   error "Enumeration constant <NTC_Num_LimpHomeIgnitionCounter> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LimpHomeIgnitionCounter (161U)
#  define NTC_Num_LimpHomeIgnitionCounter (161U)
# endif
# if (defined RTE_CONST_NTC_Num_AgCompDiagc) || (defined NTC_Num_AgCompDiagc)
#  if (!defined RTE_CONST_NTC_Num_AgCompDiagc) || (RTE_CONST_NTC_Num_AgCompDiagc != 167U)
#   error "Enumeration constant <NTC_Num_AgCompDiagc> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AgCompDiagc (167U)
#  define NTC_Num_AgCompDiagc (167U)
# endif
# if (defined RTE_CONST_NTC_Num_OpTrqVsHwTrq) || (defined NTC_Num_OpTrqVsHwTrq)
#  if (!defined RTE_CONST_NTC_Num_OpTrqVsHwTrq) || (RTE_CONST_NTC_Num_OpTrqVsHwTrq != 168U)
#   error "Enumeration constant <NTC_Num_OpTrqVsHwTrq> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OpTrqVsHwTrq (168U)
#  define NTC_Num_OpTrqVsHwTrq (168U)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentReas) || (defined NTC_Num_CurrentReas)
#  if (!defined RTE_CONST_NTC_Num_CurrentReas) || (RTE_CONST_NTC_Num_CurrentReas != 169U)
#   error "Enumeration constant <NTC_Num_CurrentReas> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentReas (169U)
#  define NTC_Num_CurrentReas (169U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaRpdShutdn) || (defined NTC_Num_LoaRpdShutdn)
#  if (!defined RTE_CONST_NTC_Num_LoaRpdShutdn) || (RTE_CONST_NTC_Num_LoaRpdShutdn != 170U)
#   error "Enumeration constant <NTC_Num_LoaRpdShutdn> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaRpdShutdn (170U)
#  define NTC_Num_LoaRpdShutdn (170U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaCtrldShutdn) || (defined NTC_Num_LoaCtrldShutdn)
#  if (!defined RTE_CONST_NTC_Num_LoaCtrldShutdn) || (RTE_CONST_NTC_Num_LoaCtrldShutdn != 171U)
#   error "Enumeration constant <NTC_Num_LoaCtrldShutdn> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaCtrldShutdn (171U)
#  define NTC_Num_LoaCtrldShutdn (171U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaMgr_HwTqIdptSigTooLow) || (defined NTC_Num_LoaMgr_HwTqIdptSigTooLow)
#  if (!defined RTE_CONST_NTC_Num_LoaMgr_HwTqIdptSigTooLow) || (RTE_CONST_NTC_Num_LoaMgr_HwTqIdptSigTooLow != 172U)
#   error "Enumeration constant <NTC_Num_LoaMgr_HwTqIdptSigTooLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
#  define NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaMgr_MotAgIdptSigTooLow) || (defined NTC_Num_LoaMgr_MotAgIdptSigTooLow)
#  if (!defined RTE_CONST_NTC_Num_LoaMgr_MotAgIdptSigTooLow) || (RTE_CONST_NTC_Num_LoaMgr_MotAgIdptSigTooLow != 173U)
#   error "Enumeration constant <NTC_Num_LoaMgr_MotAgIdptSigTooLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
#  define NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaMgr_MotCurrIdptSigTooLow) || (defined NTC_Num_LoaMgr_MotCurrIdptSigTooLow)
#  if (!defined RTE_CONST_NTC_Num_LoaMgr_MotCurrIdptSigTooLow) || (RTE_CONST_NTC_Num_LoaMgr_MotCurrIdptSigTooLow != 174U)
#   error "Enumeration constant <NTC_Num_LoaMgr_MotCurrIdptSigTooLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
#  define NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
# endif
# if (defined RTE_CONST_NTC_Num_LoaMgr_IvtrIdptSigTooLow) || (defined NTC_Num_LoaMgr_IvtrIdptSigTooLow)
#  if (!defined RTE_CONST_NTC_Num_LoaMgr_IvtrIdptSigTooLow) || (RTE_CONST_NTC_Num_LoaMgr_IvtrIdptSigTooLow != 175U)
#   error "Enumeration constant <NTC_Num_LoaMgr_IvtrIdptSigTooLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
#  define NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
# endif
# if (defined RTE_CONST_NTC_Num_OpVoltage) || (defined NTC_Num_OpVoltage)
#  if (!defined RTE_CONST_NTC_Num_OpVoltage) || (RTE_CONST_NTC_Num_OpVoltage != 176U)
#   error "Enumeration constant <NTC_Num_OpVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OpVoltage (176U)
#  define NTC_Num_OpVoltage (176U)
# endif
# if (defined RTE_CONST_NTC_Num_ExVoltageLow) || (defined NTC_Num_ExVoltageLow)
#  if (!defined RTE_CONST_NTC_Num_ExVoltageLow) || (RTE_CONST_NTC_Num_ExVoltageLow != 177U)
#   error "Enumeration constant <NTC_Num_ExVoltageLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ExVoltageLow (177U)
#  define NTC_Num_ExVoltageLow (177U)
# endif
# if (defined RTE_CONST_NTC_Num_ReducedAsstLowVoltage) || (defined NTC_Num_ReducedAsstLowVoltage)
#  if (!defined RTE_CONST_NTC_Num_ReducedAsstLowVoltage) || (RTE_CONST_NTC_Num_ReducedAsstLowVoltage != 178U)
#   error "Enumeration constant <NTC_Num_ReducedAsstLowVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ReducedAsstLowVoltage (178U)
#  define NTC_Num_ReducedAsstLowVoltage (178U)
# endif
# if (defined RTE_CONST_NTC_Num_ExVoltageHigh) || (defined NTC_Num_ExVoltageHigh)
#  if (!defined RTE_CONST_NTC_Num_ExVoltageHigh) || (RTE_CONST_NTC_Num_ExVoltageHigh != 180U)
#   error "Enumeration constant <NTC_Num_ExVoltageHigh> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ExVoltageHigh (180U)
#  define NTC_Num_ExVoltageHigh (180U)
# endif
# if (defined RTE_CONST_NTC_Num_OpVoltageOvrMax) || (defined NTC_Num_OpVoltageOvrMax)
#  if (!defined RTE_CONST_NTC_Num_OpVoltageOvrMax) || (RTE_CONST_NTC_Num_OpVoltageOvrMax != 181U)
#   error "Enumeration constant <NTC_Num_OpVoltageOvrMax> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OpVoltageOvrMax (181U)
#  define NTC_Num_OpVoltageOvrMax (181U)
# endif
# if (defined RTE_CONST_NTC_Num_BattTransOverVolt) || (defined NTC_Num_BattTransOverVolt)
#  if (!defined RTE_CONST_NTC_Num_BattTransOverVolt) || (RTE_CONST_NTC_Num_BattTransOverVolt != 182U)
#   error "Enumeration constant <NTC_Num_BattTransOverVolt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BattTransOverVolt (182U)
#  define NTC_Num_BattTransOverVolt (182U)
# endif
# if (defined RTE_CONST_NTC_Num_IgnConfDiag) || (defined NTC_Num_IgnConfDiag)
#  if (!defined RTE_CONST_NTC_Num_IgnConfDiag) || (RTE_CONST_NTC_Num_IgnConfDiag != 184U)
#   error "Enumeration constant <NTC_Num_IgnConfDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IgnConfDiag (184U)
#  define NTC_Num_IgnConfDiag (184U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_LowBattery) || (defined NTC_Num_TurnCntr_LowBattery)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_LowBattery) || (RTE_CONST_NTC_Num_TurnCntr_LowBattery != 185U)
#   error "Enumeration constant <NTC_Num_TurnCntr_LowBattery> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_LowBattery (185U)
#  define NTC_Num_TurnCntr_LowBattery (185U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMCloseFailed) || (defined NTC_Num_EEPROMCloseFailed)
#  if (!defined RTE_CONST_NTC_Num_EEPROMCloseFailed) || (RTE_CONST_NTC_Num_EEPROMCloseFailed != 191U)
#   error "Enumeration constant <NTC_Num_EEPROMCloseFailed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMCloseFailed (191U)
#  define NTC_Num_EEPROMCloseFailed (191U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath1CrossChk) || (defined NTC_Num_SigPath1CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath1CrossChk) || (RTE_CONST_NTC_Num_SigPath1CrossChk != 192U)
#   error "Enumeration constant <NTC_Num_SigPath1CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath1CrossChk (192U)
#  define NTC_Num_SigPath1CrossChk (192U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath2CrossChk) || (defined NTC_Num_SigPath2CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath2CrossChk) || (RTE_CONST_NTC_Num_SigPath2CrossChk != 193U)
#   error "Enumeration constant <NTC_Num_SigPath2CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath2CrossChk (193U)
#  define NTC_Num_SigPath2CrossChk (193U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath3CrossChk) || (defined NTC_Num_SigPath3CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath3CrossChk) || (RTE_CONST_NTC_Num_SigPath3CrossChk != 194U)
#   error "Enumeration constant <NTC_Num_SigPath3CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath3CrossChk (194U)
#  define NTC_Num_SigPath3CrossChk (194U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath4CrossChk) || (defined NTC_Num_SigPath4CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath4CrossChk) || (RTE_CONST_NTC_Num_SigPath4CrossChk != 195U)
#   error "Enumeration constant <NTC_Num_SigPath4CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath4CrossChk (195U)
#  define NTC_Num_SigPath4CrossChk (195U)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath5CrossChk) || (defined NTC_Num_SigPath5CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath5CrossChk) || (RTE_CONST_NTC_Num_SigPath5CrossChk != 196U)
#   error "Enumeration constant <NTC_Num_SigPath5CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath5CrossChk (196U)
#  define NTC_Num_SigPath5CrossChk (196U)
# endif
# if (defined RTE_CONST_NTC_Num_DampingFWReached) || (defined NTC_Num_DampingFWReached)
#  if (!defined RTE_CONST_NTC_Num_DampingFWReached) || (RTE_CONST_NTC_Num_DampingFWReached != 197U)
#   error "Enumeration constant <NTC_Num_DampingFWReached> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DampingFWReached (197U)
#  define NTC_Num_DampingFWReached (197U)
# endif
# if (defined RTE_CONST_NTC_Num_AssistFWReached) || (defined NTC_Num_AssistFWReached)
#  if (!defined RTE_CONST_NTC_Num_AssistFWReached) || (RTE_CONST_NTC_Num_AssistFWReached != 198U)
#   error "Enumeration constant <NTC_Num_AssistFWReached> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AssistFWReached (198U)
#  define NTC_Num_AssistFWReached (198U)
# endif
# if (defined RTE_CONST_NTC_Num_ReturnFWReached) || (defined NTC_Num_ReturnFWReached)
#  if (!defined RTE_CONST_NTC_Num_ReturnFWReached) || (RTE_CONST_NTC_Num_ReturnFWReached != 199U)
#   error "Enumeration constant <NTC_Num_ReturnFWReached> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ReturnFWReached (199U)
#  define NTC_Num_ReturnFWReached (199U)
# endif
# if (defined RTE_CONST_NTC_Num_DampingFWFltMode) || (defined NTC_Num_DampingFWFltMode)
#  if (!defined RTE_CONST_NTC_Num_DampingFWFltMode) || (RTE_CONST_NTC_Num_DampingFWFltMode != 200U)
#   error "Enumeration constant <NTC_Num_DampingFWFltMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DampingFWFltMode (200U)
#  define NTC_Num_DampingFWFltMode (200U)
# endif
# if (defined RTE_CONST_NTC_Num_AssistFWFltMode) || (defined NTC_Num_AssistFWFltMode)
#  if (!defined RTE_CONST_NTC_Num_AssistFWFltMode) || (RTE_CONST_NTC_Num_AssistFWFltMode != 201U)
#   error "Enumeration constant <NTC_Num_AssistFWFltMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AssistFWFltMode (201U)
#  define NTC_Num_AssistFWFltMode (201U)
# endif
# if (defined RTE_CONST_NTC_Num_VBICFltMode) || (defined NTC_Num_VBICFltMode)
#  if (!defined RTE_CONST_NTC_Num_VBICFltMode) || (RTE_CONST_NTC_Num_VBICFltMode != 202U)
#   error "Enumeration constant <NTC_Num_VBICFltMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VBICFltMode (202U)
#  define NTC_Num_VBICFltMode (202U)
# endif
# if (defined RTE_CONST_NTC_Num_StaMdsSysC) || (defined NTC_Num_StaMdsSysC)
#  if (!defined RTE_CONST_NTC_Num_StaMdsSysC) || (RTE_CONST_NTC_Num_StaMdsSysC != 203U)
#   error "Enumeration constant <NTC_Num_StaMdsSysC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_StaMdsSysC (203U)
#  define NTC_Num_StaMdsSysC (203U)
# endif
# if (defined RTE_CONST_NTC_NUM_SysFailureForRotVel) || (defined NTC_NUM_SysFailureForRotVel)
#  if (!defined RTE_CONST_NTC_NUM_SysFailureForRotVel) || (RTE_CONST_NTC_NUM_SysFailureForRotVel != 204U)
#   error "Enumeration constant <NTC_NUM_SysFailureForRotVel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_NUM_SysFailureForRotVel (204U)
#  define NTC_NUM_SysFailureForRotVel (204U)
# endif
# if (defined RTE_CONST_NTC_NUM_SysFailForRedntRotVel) || (defined NTC_NUM_SysFailForRedntRotVel)
#  if (!defined RTE_CONST_NTC_NUM_SysFailForRedntRotVel) || (RTE_CONST_NTC_NUM_SysFailForRedntRotVel != 205U)
#   error "Enumeration constant <NTC_NUM_SysFailForRedntRotVel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_NUM_SysFailForRedntRotVel (205U)
#  define NTC_NUM_SysFailForRedntRotVel (205U)
# endif
# if (defined RTE_CONST_NTC_Num_SysFailureForTrqSnsr) || (defined NTC_Num_SysFailureForTrqSnsr)
#  if (!defined RTE_CONST_NTC_Num_SysFailureForTrqSnsr) || (RTE_CONST_NTC_Num_SysFailureForTrqSnsr != 206U)
#   error "Enumeration constant <NTC_Num_SysFailureForTrqSnsr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysFailureForTrqSnsr (206U)
#  define NTC_Num_SysFailureForTrqSnsr (206U)
# endif
# if (defined RTE_CONST_NTC_Num_SysFailureForRedTrqSnsr) || (defined NTC_Num_SysFailureForRedTrqSnsr)
#  if (!defined RTE_CONST_NTC_Num_SysFailureForRedTrqSnsr) || (RTE_CONST_NTC_Num_SysFailureForRedTrqSnsr != 207U)
#   error "Enumeration constant <NTC_Num_SysFailureForRedTrqSnsr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysFailureForRedTrqSnsr (207U)
#  define NTC_Num_SysFailureForRedTrqSnsr (207U)
# endif
# if (defined RTE_CONST_NTC_NUM_SysFailureForCtrlVolt) || (defined NTC_NUM_SysFailureForCtrlVolt)
#  if (!defined RTE_CONST_NTC_NUM_SysFailureForCtrlVolt) || (RTE_CONST_NTC_NUM_SysFailureForCtrlVolt != 209U)
#   error "Enumeration constant <NTC_NUM_SysFailureForCtrlVolt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_NUM_SysFailureForCtrlVolt (209U)
#  define NTC_NUM_SysFailureForCtrlVolt (209U)
# endif
# if (defined RTE_CONST_NTC_Num_GlblSgnlOvrwrtDet) || (defined NTC_Num_GlblSgnlOvrwrtDet)
#  if (!defined RTE_CONST_NTC_Num_GlblSgnlOvrwrtDet) || (RTE_CONST_NTC_Num_GlblSgnlOvrwrtDet != 223U)
#   error "Enumeration constant <NTC_Num_GlblSgnlOvrwrtDet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_GlblSgnlOvrwrtDet (223U)
#  define NTC_Num_GlblSgnlOvrwrtDet (223U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_00) || (defined NTC_Num_VLF_00)
#  if (!defined RTE_CONST_NTC_Num_VLF_00) || (RTE_CONST_NTC_Num_VLF_00 != 224U)
#   error "Enumeration constant <NTC_Num_VLF_00> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_00 (224U)
#  define NTC_Num_VLF_00 (224U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_01) || (defined NTC_Num_VLF_01)
#  if (!defined RTE_CONST_NTC_Num_VLF_01) || (RTE_CONST_NTC_Num_VLF_01 != 225U)
#   error "Enumeration constant <NTC_Num_VLF_01> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_01 (225U)
#  define NTC_Num_VLF_01 (225U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_02) || (defined NTC_Num_VLF_02)
#  if (!defined RTE_CONST_NTC_Num_VLF_02) || (RTE_CONST_NTC_Num_VLF_02 != 226U)
#   error "Enumeration constant <NTC_Num_VLF_02> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_02 (226U)
#  define NTC_Num_VLF_02 (226U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_03) || (defined NTC_Num_VLF_03)
#  if (!defined RTE_CONST_NTC_Num_VLF_03) || (RTE_CONST_NTC_Num_VLF_03 != 227U)
#   error "Enumeration constant <NTC_Num_VLF_03> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_03 (227U)
#  define NTC_Num_VLF_03 (227U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_04) || (defined NTC_Num_VLF_04)
#  if (!defined RTE_CONST_NTC_Num_VLF_04) || (RTE_CONST_NTC_Num_VLF_04 != 228U)
#   error "Enumeration constant <NTC_Num_VLF_04> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_04 (228U)
#  define NTC_Num_VLF_04 (228U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_05) || (defined NTC_Num_VLF_05)
#  if (!defined RTE_CONST_NTC_Num_VLF_05) || (RTE_CONST_NTC_Num_VLF_05 != 229U)
#   error "Enumeration constant <NTC_Num_VLF_05> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_05 (229U)
#  define NTC_Num_VLF_05 (229U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_06) || (defined NTC_Num_VLF_06)
#  if (!defined RTE_CONST_NTC_Num_VLF_06) || (RTE_CONST_NTC_Num_VLF_06 != 230U)
#   error "Enumeration constant <NTC_Num_VLF_06> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_06 (230U)
#  define NTC_Num_VLF_06 (230U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_07) || (defined NTC_Num_VLF_07)
#  if (!defined RTE_CONST_NTC_Num_VLF_07) || (RTE_CONST_NTC_Num_VLF_07 != 231U)
#   error "Enumeration constant <NTC_Num_VLF_07> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_07 (231U)
#  define NTC_Num_VLF_07 (231U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_08) || (defined NTC_Num_VLF_08)
#  if (!defined RTE_CONST_NTC_Num_VLF_08) || (RTE_CONST_NTC_Num_VLF_08 != 232U)
#   error "Enumeration constant <NTC_Num_VLF_08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_08 (232U)
#  define NTC_Num_VLF_08 (232U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_09) || (defined NTC_Num_VLF_09)
#  if (!defined RTE_CONST_NTC_Num_VLF_09) || (RTE_CONST_NTC_Num_VLF_09 != 233U)
#   error "Enumeration constant <NTC_Num_VLF_09> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_09 (233U)
#  define NTC_Num_VLF_09 (233U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_10) || (defined NTC_Num_VLF_10)
#  if (!defined RTE_CONST_NTC_Num_VLF_10) || (RTE_CONST_NTC_Num_VLF_10 != 234U)
#   error "Enumeration constant <NTC_Num_VLF_10> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_10 (234U)
#  define NTC_Num_VLF_10 (234U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_11) || (defined NTC_Num_VLF_11)
#  if (!defined RTE_CONST_NTC_Num_VLF_11) || (RTE_CONST_NTC_Num_VLF_11 != 235U)
#   error "Enumeration constant <NTC_Num_VLF_11> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_11 (235U)
#  define NTC_Num_VLF_11 (235U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_12) || (defined NTC_Num_VLF_12)
#  if (!defined RTE_CONST_NTC_Num_VLF_12) || (RTE_CONST_NTC_Num_VLF_12 != 236U)
#   error "Enumeration constant <NTC_Num_VLF_12> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_12 (236U)
#  define NTC_Num_VLF_12 (236U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_13) || (defined NTC_Num_VLF_13)
#  if (!defined RTE_CONST_NTC_Num_VLF_13) || (RTE_CONST_NTC_Num_VLF_13 != 237U)
#   error "Enumeration constant <NTC_Num_VLF_13> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_13 (237U)
#  define NTC_Num_VLF_13 (237U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_14) || (defined NTC_Num_VLF_14)
#  if (!defined RTE_CONST_NTC_Num_VLF_14) || (RTE_CONST_NTC_Num_VLF_14 != 238U)
#   error "Enumeration constant <NTC_Num_VLF_14> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_14 (238U)
#  define NTC_Num_VLF_14 (238U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_15) || (defined NTC_Num_VLF_15)
#  if (!defined RTE_CONST_NTC_Num_VLF_15) || (RTE_CONST_NTC_Num_VLF_15 != 239U)
#   error "Enumeration constant <NTC_Num_VLF_15> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_15 (239U)
#  define NTC_Num_VLF_15 (239U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_16) || (defined NTC_Num_VLF_16)
#  if (!defined RTE_CONST_NTC_Num_VLF_16) || (RTE_CONST_NTC_Num_VLF_16 != 240U)
#   error "Enumeration constant <NTC_Num_VLF_16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_16 (240U)
#  define NTC_Num_VLF_16 (240U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_17) || (defined NTC_Num_VLF_17)
#  if (!defined RTE_CONST_NTC_Num_VLF_17) || (RTE_CONST_NTC_Num_VLF_17 != 241U)
#   error "Enumeration constant <NTC_Num_VLF_17> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_17 (241U)
#  define NTC_Num_VLF_17 (241U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_18) || (defined NTC_Num_VLF_18)
#  if (!defined RTE_CONST_NTC_Num_VLF_18) || (RTE_CONST_NTC_Num_VLF_18 != 242U)
#   error "Enumeration constant <NTC_Num_VLF_18> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_18 (242U)
#  define NTC_Num_VLF_18 (242U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_19) || (defined NTC_Num_VLF_19)
#  if (!defined RTE_CONST_NTC_Num_VLF_19) || (RTE_CONST_NTC_Num_VLF_19 != 243U)
#   error "Enumeration constant <NTC_Num_VLF_19> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_19 (243U)
#  define NTC_Num_VLF_19 (243U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_20) || (defined NTC_Num_VLF_20)
#  if (!defined RTE_CONST_NTC_Num_VLF_20) || (RTE_CONST_NTC_Num_VLF_20 != 244U)
#   error "Enumeration constant <NTC_Num_VLF_20> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_20 (244U)
#  define NTC_Num_VLF_20 (244U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_21) || (defined NTC_Num_VLF_21)
#  if (!defined RTE_CONST_NTC_Num_VLF_21) || (RTE_CONST_NTC_Num_VLF_21 != 245U)
#   error "Enumeration constant <NTC_Num_VLF_21> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_21 (245U)
#  define NTC_Num_VLF_21 (245U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_22) || (defined NTC_Num_VLF_22)
#  if (!defined RTE_CONST_NTC_Num_VLF_22) || (RTE_CONST_NTC_Num_VLF_22 != 246U)
#   error "Enumeration constant <NTC_Num_VLF_22> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_22 (246U)
#  define NTC_Num_VLF_22 (246U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_23) || (defined NTC_Num_VLF_23)
#  if (!defined RTE_CONST_NTC_Num_VLF_23) || (RTE_CONST_NTC_Num_VLF_23 != 247U)
#   error "Enumeration constant <NTC_Num_VLF_23> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_23 (247U)
#  define NTC_Num_VLF_23 (247U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_24) || (defined NTC_Num_VLF_24)
#  if (!defined RTE_CONST_NTC_Num_VLF_24) || (RTE_CONST_NTC_Num_VLF_24 != 248U)
#   error "Enumeration constant <NTC_Num_VLF_24> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_24 (248U)
#  define NTC_Num_VLF_24 (248U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_25) || (defined NTC_Num_VLF_25)
#  if (!defined RTE_CONST_NTC_Num_VLF_25) || (RTE_CONST_NTC_Num_VLF_25 != 249U)
#   error "Enumeration constant <NTC_Num_VLF_25> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_25 (249U)
#  define NTC_Num_VLF_25 (249U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_26) || (defined NTC_Num_VLF_26)
#  if (!defined RTE_CONST_NTC_Num_VLF_26) || (RTE_CONST_NTC_Num_VLF_26 != 250U)
#   error "Enumeration constant <NTC_Num_VLF_26> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_26 (250U)
#  define NTC_Num_VLF_26 (250U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_27) || (defined NTC_Num_VLF_27)
#  if (!defined RTE_CONST_NTC_Num_VLF_27) || (RTE_CONST_NTC_Num_VLF_27 != 251U)
#   error "Enumeration constant <NTC_Num_VLF_27> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_27 (251U)
#  define NTC_Num_VLF_27 (251U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_28) || (defined NTC_Num_VLF_28)
#  if (!defined RTE_CONST_NTC_Num_VLF_28) || (RTE_CONST_NTC_Num_VLF_28 != 252U)
#   error "Enumeration constant <NTC_Num_VLF_28> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_28 (252U)
#  define NTC_Num_VLF_28 (252U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_29) || (defined NTC_Num_VLF_29)
#  if (!defined RTE_CONST_NTC_Num_VLF_29) || (RTE_CONST_NTC_Num_VLF_29 != 253U)
#   error "Enumeration constant <NTC_Num_VLF_29> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_29 (253U)
#  define NTC_Num_VLF_29 (253U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_30) || (defined NTC_Num_VLF_30)
#  if (!defined RTE_CONST_NTC_Num_VLF_30) || (RTE_CONST_NTC_Num_VLF_30 != 254U)
#   error "Enumeration constant <NTC_Num_VLF_30> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_30 (254U)
#  define NTC_Num_VLF_30 (254U)
# endif
# if (defined RTE_CONST_NTC_Num_VLF_31) || (defined NTC_Num_VLF_31)
#  if (!defined RTE_CONST_NTC_Num_VLF_31) || (RTE_CONST_NTC_Num_VLF_31 != 255U)
#   error "Enumeration constant <NTC_Num_VLF_31> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_VLF_31 (255U)
#  define NTC_Num_VLF_31 (255U)
# endif
# if (defined RTE_CONST_NTC_Num_BusOffCh1) || (defined NTC_Num_BusOffCh1)
#  if (!defined RTE_CONST_NTC_Num_BusOffCh1) || (RTE_CONST_NTC_Num_BusOffCh1 != 256U)
#   error "Enumeration constant <NTC_Num_BusOffCh1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BusOffCh1 (256U)
#  define NTC_Num_BusOffCh1 (256U)
# endif
# if (defined RTE_CONST_NTC_Num_BusOffCh1NodeMute) || (defined NTC_Num_BusOffCh1NodeMute)
#  if (!defined RTE_CONST_NTC_Num_BusOffCh1NodeMute) || (RTE_CONST_NTC_Num_BusOffCh1NodeMute != 257U)
#   error "Enumeration constant <NTC_Num_BusOffCh1NodeMute> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BusOffCh1NodeMute (257U)
#  define NTC_Num_BusOffCh1NodeMute (257U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1AAbsent) || (defined NTC_Num_Node1AAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1AAbsent) || (RTE_CONST_NTC_Num_Node1AAbsent != 258U)
#   error "Enumeration constant <NTC_Num_Node1AAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1AAbsent (258U)
#  define NTC_Num_Node1AAbsent (258U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1AFaulty) || (defined NTC_Num_Node1AFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1AFaulty) || (RTE_CONST_NTC_Num_Node1AFaulty != 259U)
#   error "Enumeration constant <NTC_Num_Node1AFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1AFaulty (259U)
#  define NTC_Num_Node1AFaulty (259U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1BAbsent) || (defined NTC_Num_Node1BAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1BAbsent) || (RTE_CONST_NTC_Num_Node1BAbsent != 260U)
#   error "Enumeration constant <NTC_Num_Node1BAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1BAbsent (260U)
#  define NTC_Num_Node1BAbsent (260U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1BFaulty) || (defined NTC_Num_Node1BFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1BFaulty) || (RTE_CONST_NTC_Num_Node1BFaulty != 261U)
#   error "Enumeration constant <NTC_Num_Node1BFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1BFaulty (261U)
#  define NTC_Num_Node1BFaulty (261U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1CAbsent) || (defined NTC_Num_Node1CAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1CAbsent) || (RTE_CONST_NTC_Num_Node1CAbsent != 262U)
#   error "Enumeration constant <NTC_Num_Node1CAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1CAbsent (262U)
#  define NTC_Num_Node1CAbsent (262U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1CFaulty) || (defined NTC_Num_Node1CFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1CFaulty) || (RTE_CONST_NTC_Num_Node1CFaulty != 263U)
#   error "Enumeration constant <NTC_Num_Node1CFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1CFaulty (263U)
#  define NTC_Num_Node1CFaulty (263U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1DAbsent) || (defined NTC_Num_Node1DAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1DAbsent) || (RTE_CONST_NTC_Num_Node1DAbsent != 264U)
#   error "Enumeration constant <NTC_Num_Node1DAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1DAbsent (264U)
#  define NTC_Num_Node1DAbsent (264U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1DFaulty) || (defined NTC_Num_Node1DFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1DFaulty) || (RTE_CONST_NTC_Num_Node1DFaulty != 265U)
#   error "Enumeration constant <NTC_Num_Node1DFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1DFaulty (265U)
#  define NTC_Num_Node1DFaulty (265U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1EAbsent) || (defined NTC_Num_Node1EAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1EAbsent) || (RTE_CONST_NTC_Num_Node1EAbsent != 266U)
#   error "Enumeration constant <NTC_Num_Node1EAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1EAbsent (266U)
#  define NTC_Num_Node1EAbsent (266U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1EFaulty) || (defined NTC_Num_Node1EFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1EFaulty) || (RTE_CONST_NTC_Num_Node1EFaulty != 267U)
#   error "Enumeration constant <NTC_Num_Node1EFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1EFaulty (267U)
#  define NTC_Num_Node1EFaulty (267U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1FAbsent) || (defined NTC_Num_Node1FAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1FAbsent) || (RTE_CONST_NTC_Num_Node1FAbsent != 268U)
#   error "Enumeration constant <NTC_Num_Node1FAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1FAbsent (268U)
#  define NTC_Num_Node1FAbsent (268U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1FFaulty) || (defined NTC_Num_Node1FFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1FFaulty) || (RTE_CONST_NTC_Num_Node1FFaulty != 269U)
#   error "Enumeration constant <NTC_Num_Node1FFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1FFaulty (269U)
#  define NTC_Num_Node1FFaulty (269U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1GAbsent) || (defined NTC_Num_Node1GAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node1GAbsent) || (RTE_CONST_NTC_Num_Node1GAbsent != 270U)
#   error "Enumeration constant <NTC_Num_Node1GAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1GAbsent (270U)
#  define NTC_Num_Node1GAbsent (270U)
# endif
# if (defined RTE_CONST_NTC_Num_Node1GFaulty) || (defined NTC_Num_Node1GFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node1GFaulty) || (RTE_CONST_NTC_Num_Node1GFaulty != 271U)
#   error "Enumeration constant <NTC_Num_Node1GFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node1GFaulty (271U)
#  define NTC_Num_Node1GFaulty (271U)
# endif
# if (defined RTE_CONST_NTC_Num_BusOffCh2) || (defined NTC_Num_BusOffCh2)
#  if (!defined RTE_CONST_NTC_Num_BusOffCh2) || (RTE_CONST_NTC_Num_BusOffCh2 != 272U)
#   error "Enumeration constant <NTC_Num_BusOffCh2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BusOffCh2 (272U)
#  define NTC_Num_BusOffCh2 (272U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2AAbsent) || (defined NTC_Num_Node2AAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2AAbsent) || (RTE_CONST_NTC_Num_Node2AAbsent != 273U)
#   error "Enumeration constant <NTC_Num_Node2AAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2AAbsent (273U)
#  define NTC_Num_Node2AAbsent (273U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2AFaulty) || (defined NTC_Num_Node2AFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2AFaulty) || (RTE_CONST_NTC_Num_Node2AFaulty != 274U)
#   error "Enumeration constant <NTC_Num_Node2AFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2AFaulty (274U)
#  define NTC_Num_Node2AFaulty (274U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2BAbsent) || (defined NTC_Num_Node2BAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2BAbsent) || (RTE_CONST_NTC_Num_Node2BAbsent != 275U)
#   error "Enumeration constant <NTC_Num_Node2BAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2BAbsent (275U)
#  define NTC_Num_Node2BAbsent (275U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2BFaulty) || (defined NTC_Num_Node2BFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2BFaulty) || (RTE_CONST_NTC_Num_Node2BFaulty != 276U)
#   error "Enumeration constant <NTC_Num_Node2BFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2BFaulty (276U)
#  define NTC_Num_Node2BFaulty (276U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2CAbsent) || (defined NTC_Num_Node2CAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2CAbsent) || (RTE_CONST_NTC_Num_Node2CAbsent != 277U)
#   error "Enumeration constant <NTC_Num_Node2CAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2CAbsent (277U)
#  define NTC_Num_Node2CAbsent (277U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2CFaulty) || (defined NTC_Num_Node2CFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2CFaulty) || (RTE_CONST_NTC_Num_Node2CFaulty != 278U)
#   error "Enumeration constant <NTC_Num_Node2CFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2CFaulty (278U)
#  define NTC_Num_Node2CFaulty (278U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2DAbsent) || (defined NTC_Num_Node2DAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2DAbsent) || (RTE_CONST_NTC_Num_Node2DAbsent != 279U)
#   error "Enumeration constant <NTC_Num_Node2DAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2DAbsent (279U)
#  define NTC_Num_Node2DAbsent (279U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2DFaulty) || (defined NTC_Num_Node2DFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2DFaulty) || (RTE_CONST_NTC_Num_Node2DFaulty != 280U)
#   error "Enumeration constant <NTC_Num_Node2DFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2DFaulty (280U)
#  define NTC_Num_Node2DFaulty (280U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2EAbsent) || (defined NTC_Num_Node2EAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2EAbsent) || (RTE_CONST_NTC_Num_Node2EAbsent != 281U)
#   error "Enumeration constant <NTC_Num_Node2EAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2EAbsent (281U)
#  define NTC_Num_Node2EAbsent (281U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2EFaulty) || (defined NTC_Num_Node2EFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2EFaulty) || (RTE_CONST_NTC_Num_Node2EFaulty != 282U)
#   error "Enumeration constant <NTC_Num_Node2EFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2EFaulty (282U)
#  define NTC_Num_Node2EFaulty (282U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2FAbsent) || (defined NTC_Num_Node2FAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2FAbsent) || (RTE_CONST_NTC_Num_Node2FAbsent != 283U)
#   error "Enumeration constant <NTC_Num_Node2FAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2FAbsent (283U)
#  define NTC_Num_Node2FAbsent (283U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2FFaulty) || (defined NTC_Num_Node2FFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2FFaulty) || (RTE_CONST_NTC_Num_Node2FFaulty != 284U)
#   error "Enumeration constant <NTC_Num_Node2FFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2FFaulty (284U)
#  define NTC_Num_Node2FFaulty (284U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2GAbsent) || (defined NTC_Num_Node2GAbsent)
#  if (!defined RTE_CONST_NTC_Num_Node2GAbsent) || (RTE_CONST_NTC_Num_Node2GAbsent != 285U)
#   error "Enumeration constant <NTC_Num_Node2GAbsent> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2GAbsent (285U)
#  define NTC_Num_Node2GAbsent (285U)
# endif
# if (defined RTE_CONST_NTC_Num_Node2GFaulty) || (defined NTC_Num_Node2GFaulty)
#  if (!defined RTE_CONST_NTC_Num_Node2GFaulty) || (RTE_CONST_NTC_Num_Node2GFaulty != 286U)
#   error "Enumeration constant <NTC_Num_Node2GFaulty> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Node2GFaulty (286U)
#  define NTC_Num_Node2GFaulty (286U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_M) || (defined NTC_Num_InvalidMsg_M)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_M) || (RTE_CONST_NTC_Num_InvalidMsg_M != 288U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_M (288U)
#  define NTC_Num_InvalidMsg_M (288U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_M) || (defined NTC_Num_MissingMsg_M)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_M) || (RTE_CONST_NTC_Num_MissingMsg_M != 289U)
#   error "Enumeration constant <NTC_Num_MissingMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_M (289U)
#  define NTC_Num_MissingMsg_M (289U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_M) || (defined NTC_Num_CRCFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_M) || (RTE_CONST_NTC_Num_CRCFltMsg_M != 290U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_M (290U)
#  define NTC_Num_CRCFltMsg_M (290U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_M) || (defined NTC_Num_PgrsCntFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_M) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_M != 291U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_M (291U)
#  define NTC_Num_PgrsCntFltMsg_M (291U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_M) || (defined NTC_Num_DataRngFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_M) || (RTE_CONST_NTC_Num_DataRngFltMsg_M != 292U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_M (292U)
#  define NTC_Num_DataRngFltMsg_M (292U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_M) || (defined NTC_Num_DataRateFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_M) || (RTE_CONST_NTC_Num_DataRateFltMsg_M != 293U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_M (293U)
#  define NTC_Num_DataRateFltMsg_M (293U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_M) || (defined NTC_Num_DataOtherFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_M) || (RTE_CONST_NTC_Num_DataOtherFltMsg_M != 294U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_M (294U)
#  define NTC_Num_DataOtherFltMsg_M (294U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOther2FltMsg_M) || (defined NTC_Num_DataOther2FltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataOther2FltMsg_M) || (RTE_CONST_NTC_Num_DataOther2FltMsg_M != 295U)
#   error "Enumeration constant <NTC_Num_DataOther2FltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOther2FltMsg_M (295U)
#  define NTC_Num_DataOther2FltMsg_M (295U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_N) || (defined NTC_Num_InvalidMsg_N)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_N) || (RTE_CONST_NTC_Num_InvalidMsg_N != 296U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_N (296U)
#  define NTC_Num_InvalidMsg_N (296U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_N) || (defined NTC_Num_MissingMsg_N)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_N) || (RTE_CONST_NTC_Num_MissingMsg_N != 297U)
#   error "Enumeration constant <NTC_Num_MissingMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_N (297U)
#  define NTC_Num_MissingMsg_N (297U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_N) || (defined NTC_Num_CRCFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_N) || (RTE_CONST_NTC_Num_CRCFltMsg_N != 298U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_N (298U)
#  define NTC_Num_CRCFltMsg_N (298U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_N) || (defined NTC_Num_PgrsCntFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_N) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_N != 299U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_N (299U)
#  define NTC_Num_PgrsCntFltMsg_N (299U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_N) || (defined NTC_Num_DataRngFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_N) || (RTE_CONST_NTC_Num_DataRngFltMsg_N != 300U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_N (300U)
#  define NTC_Num_DataRngFltMsg_N (300U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_N) || (defined NTC_Num_DataRateFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_N) || (RTE_CONST_NTC_Num_DataRateFltMsg_N != 301U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_N (301U)
#  define NTC_Num_DataRateFltMsg_N (301U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_N) || (defined NTC_Num_DataOtherFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_N) || (RTE_CONST_NTC_Num_DataOtherFltMsg_N != 302U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_N (302U)
#  define NTC_Num_DataOtherFltMsg_N (302U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_N) || (defined NTC_Num_DataOtherFlt2Msg_N)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_N) || (RTE_CONST_NTC_Num_DataOtherFlt2Msg_N != 303U)
#   error "Enumeration constant <NTC_Num_DataOtherFlt2Msg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFlt2Msg_N (303U)
#  define NTC_Num_DataOtherFlt2Msg_N (303U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_O) || (defined NTC_Num_InvalidMsg_O)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_O) || (RTE_CONST_NTC_Num_InvalidMsg_O != 304U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_O (304U)
#  define NTC_Num_InvalidMsg_O (304U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_O) || (defined NTC_Num_MissingMsg_O)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_O) || (RTE_CONST_NTC_Num_MissingMsg_O != 305U)
#   error "Enumeration constant <NTC_Num_MissingMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_O (305U)
#  define NTC_Num_MissingMsg_O (305U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_O) || (defined NTC_Num_CRCFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_O) || (RTE_CONST_NTC_Num_CRCFltMsg_O != 306U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_O (306U)
#  define NTC_Num_CRCFltMsg_O (306U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_O) || (defined NTC_Num_PgrsCntFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_O) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_O != 307U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_O (307U)
#  define NTC_Num_PgrsCntFltMsg_O (307U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_O) || (defined NTC_Num_DataRngFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_O) || (RTE_CONST_NTC_Num_DataRngFltMsg_O != 308U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_O (308U)
#  define NTC_Num_DataRngFltMsg_O (308U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_O) || (defined NTC_Num_DataRateFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_O) || (RTE_CONST_NTC_Num_DataRateFltMsg_O != 309U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_O (309U)
#  define NTC_Num_DataRateFltMsg_O (309U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_O) || (defined NTC_Num_DataOtherFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_O) || (RTE_CONST_NTC_Num_DataOtherFltMsg_O != 310U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_O (310U)
#  define NTC_Num_DataOtherFltMsg_O (310U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_P) || (defined NTC_Num_InvalidMsg_P)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_P) || (RTE_CONST_NTC_Num_InvalidMsg_P != 312U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_P (312U)
#  define NTC_Num_InvalidMsg_P (312U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_P) || (defined NTC_Num_MissingMsg_P)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_P) || (RTE_CONST_NTC_Num_MissingMsg_P != 313U)
#   error "Enumeration constant <NTC_Num_MissingMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_P (313U)
#  define NTC_Num_MissingMsg_P (313U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_P) || (defined NTC_Num_CRCFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_P) || (RTE_CONST_NTC_Num_CRCFltMsg_P != 314U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_P (314U)
#  define NTC_Num_CRCFltMsg_P (314U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_P) || (defined NTC_Num_PgrsCntFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_P) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_P != 315U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_P (315U)
#  define NTC_Num_PgrsCntFltMsg_P (315U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_P) || (defined NTC_Num_DataRngFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_P) || (RTE_CONST_NTC_Num_DataRngFltMsg_P != 316U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_P (316U)
#  define NTC_Num_DataRngFltMsg_P (316U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_P) || (defined NTC_Num_DataRateFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_P) || (RTE_CONST_NTC_Num_DataRateFltMsg_P != 317U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_P (317U)
#  define NTC_Num_DataRateFltMsg_P (317U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_P) || (defined NTC_Num_DataOtherFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_P) || (RTE_CONST_NTC_Num_DataOtherFltMsg_P != 318U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_P (318U)
#  define NTC_Num_DataOtherFltMsg_P (318U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Q) || (defined NTC_Num_InvalidMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Q) || (RTE_CONST_NTC_Num_InvalidMsg_Q != 320U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Q (320U)
#  define NTC_Num_InvalidMsg_Q (320U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Q) || (defined NTC_Num_MissingMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Q) || (RTE_CONST_NTC_Num_MissingMsg_Q != 321U)
#   error "Enumeration constant <NTC_Num_MissingMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Q (321U)
#  define NTC_Num_MissingMsg_Q (321U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Q) || (defined NTC_Num_CRCFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Q) || (RTE_CONST_NTC_Num_CRCFltMsg_Q != 322U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Q (322U)
#  define NTC_Num_CRCFltMsg_Q (322U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Q) || (defined NTC_Num_PgrsCntFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Q) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Q != 323U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Q (323U)
#  define NTC_Num_PgrsCntFltMsg_Q (323U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Q) || (defined NTC_Num_DataRngFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Q) || (RTE_CONST_NTC_Num_DataRngFltMsg_Q != 324U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Q (324U)
#  define NTC_Num_DataRngFltMsg_Q (324U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Q) || (defined NTC_Num_DataRateFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Q) || (RTE_CONST_NTC_Num_DataRateFltMsg_Q != 325U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Q (325U)
#  define NTC_Num_DataRateFltMsg_Q (325U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Q) || (defined NTC_Num_DataOtherFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Q) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Q != 326U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Q (326U)
#  define NTC_Num_DataOtherFltMsg_Q (326U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_Q) || (defined NTC_Num_DataOtherFlt2Msg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_Q) || (RTE_CONST_NTC_Num_DataOtherFlt2Msg_Q != 327U)
#   error "Enumeration constant <NTC_Num_DataOtherFlt2Msg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFlt2Msg_Q (327U)
#  define NTC_Num_DataOtherFlt2Msg_Q (327U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_R) || (defined NTC_Num_InvalidMsg_R)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_R) || (RTE_CONST_NTC_Num_InvalidMsg_R != 328U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_R (328U)
#  define NTC_Num_InvalidMsg_R (328U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_R) || (defined NTC_Num_MissingMsg_R)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_R) || (RTE_CONST_NTC_Num_MissingMsg_R != 329U)
#   error "Enumeration constant <NTC_Num_MissingMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_R (329U)
#  define NTC_Num_MissingMsg_R (329U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_R) || (defined NTC_Num_CRCFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_R) || (RTE_CONST_NTC_Num_CRCFltMsg_R != 330U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_R (330U)
#  define NTC_Num_CRCFltMsg_R (330U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_R) || (defined NTC_Num_PgrsCntFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_R) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_R != 331U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_R (331U)
#  define NTC_Num_PgrsCntFltMsg_R (331U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_R) || (defined NTC_Num_DataRngFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_R) || (RTE_CONST_NTC_Num_DataRngFltMsg_R != 332U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_R (332U)
#  define NTC_Num_DataRngFltMsg_R (332U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_R) || (defined NTC_Num_DataRateFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_R) || (RTE_CONST_NTC_Num_DataRateFltMsg_R != 333U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_R (333U)
#  define NTC_Num_DataRateFltMsg_R (333U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_R) || (defined NTC_Num_DataOtherFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_R) || (RTE_CONST_NTC_Num_DataOtherFltMsg_R != 334U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_R (334U)
#  define NTC_Num_DataOtherFltMsg_R (334U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_R) || (defined NTC_Num_DataOtherFlt2Msg_R)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFlt2Msg_R) || (RTE_CONST_NTC_Num_DataOtherFlt2Msg_R != 335U)
#   error "Enumeration constant <NTC_Num_DataOtherFlt2Msg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFlt2Msg_R (335U)
#  define NTC_Num_DataOtherFlt2Msg_R (335U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_S) || (defined NTC_Num_InvalidMsg_S)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_S) || (RTE_CONST_NTC_Num_InvalidMsg_S != 336U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_S (336U)
#  define NTC_Num_InvalidMsg_S (336U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_S) || (defined NTC_Num_MissingMsg_S)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_S) || (RTE_CONST_NTC_Num_MissingMsg_S != 337U)
#   error "Enumeration constant <NTC_Num_MissingMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_S (337U)
#  define NTC_Num_MissingMsg_S (337U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_S) || (defined NTC_Num_CRCFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_S) || (RTE_CONST_NTC_Num_CRCFltMsg_S != 338U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_S (338U)
#  define NTC_Num_CRCFltMsg_S (338U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_S) || (defined NTC_Num_PgrsCntFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_S) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_S != 339U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_S (339U)
#  define NTC_Num_PgrsCntFltMsg_S (339U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_S) || (defined NTC_Num_DataRngFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_S) || (RTE_CONST_NTC_Num_DataRngFltMsg_S != 340U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_S (340U)
#  define NTC_Num_DataRngFltMsg_S (340U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_S) || (defined NTC_Num_DataRateFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_S) || (RTE_CONST_NTC_Num_DataRateFltMsg_S != 341U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_S (341U)
#  define NTC_Num_DataRateFltMsg_S (341U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_S) || (defined NTC_Num_DataOtherFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_S) || (RTE_CONST_NTC_Num_DataOtherFltMsg_S != 342U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_S (342U)
#  define NTC_Num_DataOtherFltMsg_S (342U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_T) || (defined NTC_Num_InvalidMsg_T)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_T) || (RTE_CONST_NTC_Num_InvalidMsg_T != 344U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_T (344U)
#  define NTC_Num_InvalidMsg_T (344U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_T) || (defined NTC_Num_MissingMsg_T)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_T) || (RTE_CONST_NTC_Num_MissingMsg_T != 345U)
#   error "Enumeration constant <NTC_Num_MissingMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_T (345U)
#  define NTC_Num_MissingMsg_T (345U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_T) || (defined NTC_Num_CRCFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_T) || (RTE_CONST_NTC_Num_CRCFltMsg_T != 346U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_T (346U)
#  define NTC_Num_CRCFltMsg_T (346U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_T) || (defined NTC_Num_PgrsCntFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_T) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_T != 347U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_T (347U)
#  define NTC_Num_PgrsCntFltMsg_T (347U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_T) || (defined NTC_Num_DataRngFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_T) || (RTE_CONST_NTC_Num_DataRngFltMsg_T != 348U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_T (348U)
#  define NTC_Num_DataRngFltMsg_T (348U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_T) || (defined NTC_Num_DataRateFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_T) || (RTE_CONST_NTC_Num_DataRateFltMsg_T != 349U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_T (349U)
#  define NTC_Num_DataRateFltMsg_T (349U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_T) || (defined NTC_Num_DataOtherFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_T) || (RTE_CONST_NTC_Num_DataOtherFltMsg_T != 350U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_T (350U)
#  define NTC_Num_DataOtherFltMsg_T (350U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_U) || (defined NTC_Num_InvalidMsg_U)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_U) || (RTE_CONST_NTC_Num_InvalidMsg_U != 352U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_U (352U)
#  define NTC_Num_InvalidMsg_U (352U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_U) || (defined NTC_Num_MissingMsg_U)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_U) || (RTE_CONST_NTC_Num_MissingMsg_U != 353U)
#   error "Enumeration constant <NTC_Num_MissingMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_U (353U)
#  define NTC_Num_MissingMsg_U (353U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_U) || (defined NTC_Num_CRCFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_U) || (RTE_CONST_NTC_Num_CRCFltMsg_U != 354U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_U (354U)
#  define NTC_Num_CRCFltMsg_U (354U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_U) || (defined NTC_Num_PgrsCntFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_U) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_U != 355U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_U (355U)
#  define NTC_Num_PgrsCntFltMsg_U (355U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_U) || (defined NTC_Num_DataRngFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_U) || (RTE_CONST_NTC_Num_DataRngFltMsg_U != 356U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_U (356U)
#  define NTC_Num_DataRngFltMsg_U (356U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_U) || (defined NTC_Num_DataRateFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_U) || (RTE_CONST_NTC_Num_DataRateFltMsg_U != 357U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_U (357U)
#  define NTC_Num_DataRateFltMsg_U (357U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_U) || (defined NTC_Num_DataOtherFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_U) || (RTE_CONST_NTC_Num_DataOtherFltMsg_U != 358U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_U (358U)
#  define NTC_Num_DataOtherFltMsg_U (358U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_V) || (defined NTC_Num_InvalidMsg_V)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_V) || (RTE_CONST_NTC_Num_InvalidMsg_V != 360U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_V (360U)
#  define NTC_Num_InvalidMsg_V (360U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_V) || (defined NTC_Num_MissingMsg_V)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_V) || (RTE_CONST_NTC_Num_MissingMsg_V != 361U)
#   error "Enumeration constant <NTC_Num_MissingMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_V (361U)
#  define NTC_Num_MissingMsg_V (361U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_V) || (defined NTC_Num_CRCFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_V) || (RTE_CONST_NTC_Num_CRCFltMsg_V != 362U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_V (362U)
#  define NTC_Num_CRCFltMsg_V (362U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_V) || (defined NTC_Num_PgrsCntFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_V) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_V != 363U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_V (363U)
#  define NTC_Num_PgrsCntFltMsg_V (363U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_V) || (defined NTC_Num_DataRngFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_V) || (RTE_CONST_NTC_Num_DataRngFltMsg_V != 364U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_V (364U)
#  define NTC_Num_DataRngFltMsg_V (364U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_V) || (defined NTC_Num_DataRateFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_V) || (RTE_CONST_NTC_Num_DataRateFltMsg_V != 365U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_V (365U)
#  define NTC_Num_DataRateFltMsg_V (365U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_V) || (defined NTC_Num_DataOtherFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_V) || (RTE_CONST_NTC_Num_DataOtherFltMsg_V != 366U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_V (366U)
#  define NTC_Num_DataOtherFltMsg_V (366U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_W) || (defined NTC_Num_InvalidMsg_W)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_W) || (RTE_CONST_NTC_Num_InvalidMsg_W != 368U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_W (368U)
#  define NTC_Num_InvalidMsg_W (368U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_W) || (defined NTC_Num_MissingMsg_W)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_W) || (RTE_CONST_NTC_Num_MissingMsg_W != 369U)
#   error "Enumeration constant <NTC_Num_MissingMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_W (369U)
#  define NTC_Num_MissingMsg_W (369U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_W) || (defined NTC_Num_CRCFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_W) || (RTE_CONST_NTC_Num_CRCFltMsg_W != 370U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_W (370U)
#  define NTC_Num_CRCFltMsg_W (370U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_W) || (defined NTC_Num_PgrsCntFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_W) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_W != 371U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_W (371U)
#  define NTC_Num_PgrsCntFltMsg_W (371U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_W) || (defined NTC_Num_DataRngFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_W) || (RTE_CONST_NTC_Num_DataRngFltMsg_W != 372U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_W (372U)
#  define NTC_Num_DataRngFltMsg_W (372U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_W) || (defined NTC_Num_DataRateFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_W) || (RTE_CONST_NTC_Num_DataRateFltMsg_W != 373U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_W (373U)
#  define NTC_Num_DataRateFltMsg_W (373U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_W) || (defined NTC_Num_DataOtherFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_W) || (RTE_CONST_NTC_Num_DataOtherFltMsg_W != 374U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_W (374U)
#  define NTC_Num_DataOtherFltMsg_W (374U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_X) || (defined NTC_Num_InvalidMsg_X)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_X) || (RTE_CONST_NTC_Num_InvalidMsg_X != 376U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_X (376U)
#  define NTC_Num_InvalidMsg_X (376U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_X) || (defined NTC_Num_MissingMsg_X)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_X) || (RTE_CONST_NTC_Num_MissingMsg_X != 377U)
#   error "Enumeration constant <NTC_Num_MissingMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_X (377U)
#  define NTC_Num_MissingMsg_X (377U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_X) || (defined NTC_Num_CRCFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_X) || (RTE_CONST_NTC_Num_CRCFltMsg_X != 378U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_X (378U)
#  define NTC_Num_CRCFltMsg_X (378U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_X) || (defined NTC_Num_PgrsCntFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_X) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_X != 379U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_X (379U)
#  define NTC_Num_PgrsCntFltMsg_X (379U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_X) || (defined NTC_Num_DataRngFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_X) || (RTE_CONST_NTC_Num_DataRngFltMsg_X != 380U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_X (380U)
#  define NTC_Num_DataRngFltMsg_X (380U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_X) || (defined NTC_Num_DataRateFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_X) || (RTE_CONST_NTC_Num_DataRateFltMsg_X != 381U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_X (381U)
#  define NTC_Num_DataRateFltMsg_X (381U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_X) || (defined NTC_Num_DataOtherFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_X) || (RTE_CONST_NTC_Num_DataOtherFltMsg_X != 382U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_X (382U)
#  define NTC_Num_DataOtherFltMsg_X (382U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Y) || (defined NTC_Num_InvalidMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Y) || (RTE_CONST_NTC_Num_InvalidMsg_Y != 384U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Y (384U)
#  define NTC_Num_InvalidMsg_Y (384U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Y) || (defined NTC_Num_MissingMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Y) || (RTE_CONST_NTC_Num_MissingMsg_Y != 385U)
#   error "Enumeration constant <NTC_Num_MissingMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Y (385U)
#  define NTC_Num_MissingMsg_Y (385U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Y) || (defined NTC_Num_CRCFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Y) || (RTE_CONST_NTC_Num_CRCFltMsg_Y != 386U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Y (386U)
#  define NTC_Num_CRCFltMsg_Y (386U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Y) || (defined NTC_Num_PgrsCntFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Y) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Y != 387U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Y (387U)
#  define NTC_Num_PgrsCntFltMsg_Y (387U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Y) || (defined NTC_Num_DataRngFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Y) || (RTE_CONST_NTC_Num_DataRngFltMsg_Y != 388U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Y (388U)
#  define NTC_Num_DataRngFltMsg_Y (388U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Y) || (defined NTC_Num_DataRateFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Y) || (RTE_CONST_NTC_Num_DataRateFltMsg_Y != 389U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Y (389U)
#  define NTC_Num_DataRateFltMsg_Y (389U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Y) || (defined NTC_Num_DataOtherFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Y) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Y != 390U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Y (390U)
#  define NTC_Num_DataOtherFltMsg_Y (390U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Z) || (defined NTC_Num_InvalidMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Z) || (RTE_CONST_NTC_Num_InvalidMsg_Z != 392U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Z (392U)
#  define NTC_Num_InvalidMsg_Z (392U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Z) || (defined NTC_Num_MissingMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Z) || (RTE_CONST_NTC_Num_MissingMsg_Z != 393U)
#   error "Enumeration constant <NTC_Num_MissingMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Z (393U)
#  define NTC_Num_MissingMsg_Z (393U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Z) || (defined NTC_Num_CRCFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Z) || (RTE_CONST_NTC_Num_CRCFltMsg_Z != 394U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Z (394U)
#  define NTC_Num_CRCFltMsg_Z (394U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Z) || (defined NTC_Num_PgrsCntFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Z) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Z != 395U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Z (395U)
#  define NTC_Num_PgrsCntFltMsg_Z (395U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Z) || (defined NTC_Num_DataRngFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Z) || (RTE_CONST_NTC_Num_DataRngFltMsg_Z != 396U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Z (396U)
#  define NTC_Num_DataRngFltMsg_Z (396U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Z) || (defined NTC_Num_DataRateFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Z) || (RTE_CONST_NTC_Num_DataRateFltMsg_Z != 397U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Z (397U)
#  define NTC_Num_DataRateFltMsg_Z (397U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Z) || (defined NTC_Num_DataOtherFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Z) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Z != 398U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Z (398U)
#  define NTC_Num_DataOtherFltMsg_Z (398U)
# endif
# if (defined RTE_CONST_NTC_Num_DSTXORActive) || (defined NTC_Num_DSTXORActive)
#  if (!defined RTE_CONST_NTC_Num_DSTXORActive) || (RTE_CONST_NTC_Num_DSTXORActive != 399U)
#   error "Enumeration constant <NTC_Num_DSTXORActive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DSTXORActive (399U)
#  define NTC_Num_DSTXORActive (399U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AA) || (defined NTC_Num_InvalidMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AA) || (RTE_CONST_NTC_Num_InvalidMsg_AA != 400U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AA (400U)
#  define NTC_Num_InvalidMsg_AA (400U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AA) || (defined NTC_Num_MissingMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AA) || (RTE_CONST_NTC_Num_MissingMsg_AA != 401U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AA (401U)
#  define NTC_Num_MissingMsg_AA (401U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AA) || (defined NTC_Num_CRCFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AA) || (RTE_CONST_NTC_Num_CRCFltMsg_AA != 402U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AA (402U)
#  define NTC_Num_CRCFltMsg_AA (402U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AA) || (defined NTC_Num_PgrsCntFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AA) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AA != 403U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AA (403U)
#  define NTC_Num_PgrsCntFltMsg_AA (403U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AA) || (defined NTC_Num_DataRngFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AA) || (RTE_CONST_NTC_Num_DataRngFltMsg_AA != 404U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AA (404U)
#  define NTC_Num_DataRngFltMsg_AA (404U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AA) || (defined NTC_Num_DataRateFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AA) || (RTE_CONST_NTC_Num_DataRateFltMsg_AA != 405U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AA (405U)
#  define NTC_Num_DataRateFltMsg_AA (405U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AA) || (defined NTC_Num_DataOtherFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AA) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AA != 406U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AA (406U)
#  define NTC_Num_DataOtherFltMsg_AA (406U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AB) || (defined NTC_Num_InvalidMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AB) || (RTE_CONST_NTC_Num_InvalidMsg_AB != 408U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AB (408U)
#  define NTC_Num_InvalidMsg_AB (408U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AB) || (defined NTC_Num_MissingMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AB) || (RTE_CONST_NTC_Num_MissingMsg_AB != 409U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AB (409U)
#  define NTC_Num_MissingMsg_AB (409U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AB) || (defined NTC_Num_CRCFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AB) || (RTE_CONST_NTC_Num_CRCFltMsg_AB != 410U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AB (410U)
#  define NTC_Num_CRCFltMsg_AB (410U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AB) || (defined NTC_Num_PgrsCntFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AB) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AB != 411U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AB (411U)
#  define NTC_Num_PgrsCntFltMsg_AB (411U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AB) || (defined NTC_Num_DataRngFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AB) || (RTE_CONST_NTC_Num_DataRngFltMsg_AB != 412U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AB (412U)
#  define NTC_Num_DataRngFltMsg_AB (412U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AB) || (defined NTC_Num_DataRateFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AB) || (RTE_CONST_NTC_Num_DataRateFltMsg_AB != 413U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AB (413U)
#  define NTC_Num_DataRateFltMsg_AB (413U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AB) || (defined NTC_Num_DataOtherFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AB) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AB != 414U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AB (414U)
#  define NTC_Num_DataOtherFltMsg_AB (414U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AC) || (defined NTC_Num_InvalidMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AC) || (RTE_CONST_NTC_Num_InvalidMsg_AC != 416U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AC (416U)
#  define NTC_Num_InvalidMsg_AC (416U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AC) || (defined NTC_Num_MissingMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AC) || (RTE_CONST_NTC_Num_MissingMsg_AC != 417U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AC (417U)
#  define NTC_Num_MissingMsg_AC (417U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AC) || (defined NTC_Num_CRCFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AC) || (RTE_CONST_NTC_Num_CRCFltMsg_AC != 418U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AC (418U)
#  define NTC_Num_CRCFltMsg_AC (418U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AC) || (defined NTC_Num_PgrsCntFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AC) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AC != 419U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AC (419U)
#  define NTC_Num_PgrsCntFltMsg_AC (419U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AC) || (defined NTC_Num_DataRngFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AC) || (RTE_CONST_NTC_Num_DataRngFltMsg_AC != 420U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AC (420U)
#  define NTC_Num_DataRngFltMsg_AC (420U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AC) || (defined NTC_Num_DataRateFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AC) || (RTE_CONST_NTC_Num_DataRateFltMsg_AC != 421U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AC (421U)
#  define NTC_Num_DataRateFltMsg_AC (421U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AC) || (defined NTC_Num_DataOtherFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AC) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AC != 422U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AC (422U)
#  define NTC_Num_DataOtherFltMsg_AC (422U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AD) || (defined NTC_Num_InvalidMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AD) || (RTE_CONST_NTC_Num_InvalidMsg_AD != 424U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AD (424U)
#  define NTC_Num_InvalidMsg_AD (424U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AD) || (defined NTC_Num_MissingMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AD) || (RTE_CONST_NTC_Num_MissingMsg_AD != 425U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AD (425U)
#  define NTC_Num_MissingMsg_AD (425U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AD) || (defined NTC_Num_CRCFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AD) || (RTE_CONST_NTC_Num_CRCFltMsg_AD != 426U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AD (426U)
#  define NTC_Num_CRCFltMsg_AD (426U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AD) || (defined NTC_Num_PgrsCntFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AD) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AD != 427U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AD (427U)
#  define NTC_Num_PgrsCntFltMsg_AD (427U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AD) || (defined NTC_Num_DataRngFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AD) || (RTE_CONST_NTC_Num_DataRngFltMsg_AD != 428U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AD (428U)
#  define NTC_Num_DataRngFltMsg_AD (428U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AD) || (defined NTC_Num_DataRateFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AD) || (RTE_CONST_NTC_Num_DataRateFltMsg_AD != 429U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AD (429U)
#  define NTC_Num_DataRateFltMsg_AD (429U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AD) || (defined NTC_Num_DataOtherFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AD) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AD != 430U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AD (430U)
#  define NTC_Num_DataOtherFltMsg_AD (430U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AE) || (defined NTC_Num_InvalidMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AE) || (RTE_CONST_NTC_Num_InvalidMsg_AE != 432U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AE (432U)
#  define NTC_Num_InvalidMsg_AE (432U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AE) || (defined NTC_Num_MissingMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AE) || (RTE_CONST_NTC_Num_MissingMsg_AE != 433U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AE (433U)
#  define NTC_Num_MissingMsg_AE (433U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AE) || (defined NTC_Num_CRCFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AE) || (RTE_CONST_NTC_Num_CRCFltMsg_AE != 434U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AE (434U)
#  define NTC_Num_CRCFltMsg_AE (434U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AE) || (defined NTC_Num_PgrsCntFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AE) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AE != 435U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AE (435U)
#  define NTC_Num_PgrsCntFltMsg_AE (435U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AE) || (defined NTC_Num_DataRngFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AE) || (RTE_CONST_NTC_Num_DataRngFltMsg_AE != 436U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AE (436U)
#  define NTC_Num_DataRngFltMsg_AE (436U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AE) || (defined NTC_Num_DataRateFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AE) || (RTE_CONST_NTC_Num_DataRateFltMsg_AE != 437U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AE (437U)
#  define NTC_Num_DataRateFltMsg_AE (437U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AE) || (defined NTC_Num_DataOtherFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AE) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AE != 438U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AE (438U)
#  define NTC_Num_DataOtherFltMsg_AE (438U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AF) || (defined NTC_Num_InvalidMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AF) || (RTE_CONST_NTC_Num_InvalidMsg_AF != 440U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AF (440U)
#  define NTC_Num_InvalidMsg_AF (440U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AF) || (defined NTC_Num_MissingMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AF) || (RTE_CONST_NTC_Num_MissingMsg_AF != 441U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AF (441U)
#  define NTC_Num_MissingMsg_AF (441U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AF) || (defined NTC_Num_CRCFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AF) || (RTE_CONST_NTC_Num_CRCFltMsg_AF != 442U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AF (442U)
#  define NTC_Num_CRCFltMsg_AF (442U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AF) || (defined NTC_Num_PgrsCntFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AF) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AF != 443U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AF (443U)
#  define NTC_Num_PgrsCntFltMsg_AF (443U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AF) || (defined NTC_Num_DataRngFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AF) || (RTE_CONST_NTC_Num_DataRngFltMsg_AF != 444U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AF (444U)
#  define NTC_Num_DataRngFltMsg_AF (444U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AF) || (defined NTC_Num_DataRateFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AF) || (RTE_CONST_NTC_Num_DataRateFltMsg_AF != 445U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AF (445U)
#  define NTC_Num_DataRateFltMsg_AF (445U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AF) || (defined NTC_Num_DataOtherFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AF) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AF != 446U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AF (446U)
#  define NTC_Num_DataOtherFltMsg_AF (446U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AG) || (defined NTC_Num_InvalidMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AG) || (RTE_CONST_NTC_Num_InvalidMsg_AG != 448U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AG (448U)
#  define NTC_Num_InvalidMsg_AG (448U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AG) || (defined NTC_Num_MissingMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AG) || (RTE_CONST_NTC_Num_MissingMsg_AG != 449U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AG (449U)
#  define NTC_Num_MissingMsg_AG (449U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AG) || (defined NTC_Num_CRCFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AG) || (RTE_CONST_NTC_Num_CRCFltMsg_AG != 450U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AG (450U)
#  define NTC_Num_CRCFltMsg_AG (450U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AG) || (defined NTC_Num_PgrsCntFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AG) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AG != 451U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AG (451U)
#  define NTC_Num_PgrsCntFltMsg_AG (451U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AG) || (defined NTC_Num_DataRngFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AG) || (RTE_CONST_NTC_Num_DataRngFltMsg_AG != 452U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AG (452U)
#  define NTC_Num_DataRngFltMsg_AG (452U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AG) || (defined NTC_Num_DataRateFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AG) || (RTE_CONST_NTC_Num_DataRateFltMsg_AG != 453U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AG (453U)
#  define NTC_Num_DataRateFltMsg_AG (453U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AG) || (defined NTC_Num_DataOtherFltMsg_AG)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AG) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AG != 454U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AG (454U)
#  define NTC_Num_DataOtherFltMsg_AG (454U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AH) || (defined NTC_Num_InvalidMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AH) || (RTE_CONST_NTC_Num_InvalidMsg_AH != 456U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AH (456U)
#  define NTC_Num_InvalidMsg_AH (456U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AH) || (defined NTC_Num_MissingMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AH) || (RTE_CONST_NTC_Num_MissingMsg_AH != 457U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AH (457U)
#  define NTC_Num_MissingMsg_AH (457U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AH) || (defined NTC_Num_CRCFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AH) || (RTE_CONST_NTC_Num_CRCFltMsg_AH != 458U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AH (458U)
#  define NTC_Num_CRCFltMsg_AH (458U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AH) || (defined NTC_Num_PgrsCntFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AH) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AH != 459U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AH (459U)
#  define NTC_Num_PgrsCntFltMsg_AH (459U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AH) || (defined NTC_Num_DataRngFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AH) || (RTE_CONST_NTC_Num_DataRngFltMsg_AH != 460U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AH (460U)
#  define NTC_Num_DataRngFltMsg_AH (460U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AH) || (defined NTC_Num_DataRateFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AH) || (RTE_CONST_NTC_Num_DataRateFltMsg_AH != 461U)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AH (461U)
#  define NTC_Num_DataRateFltMsg_AH (461U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AH) || (defined NTC_Num_DataOtherFltMsg_AH)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AH) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AH != 462U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AH (462U)
#  define NTC_Num_DataOtherFltMsg_AH (462U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_ParkAssistParallel) || (defined NTC_Num_InvalidMsg_ParkAssistParallel)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_ParkAssistParallel) || (RTE_CONST_NTC_Num_InvalidMsg_ParkAssistParallel != 464U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_ParkAssistParallel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_ParkAssistParallel (464U)
#  define NTC_Num_InvalidMsg_ParkAssistParallel (464U)
# endif
# if (defined RTE_CONST_NTC_Num_FlexrayCommunicationError) || (defined NTC_Num_FlexrayCommunicationError)
#  if (!defined RTE_CONST_NTC_Num_FlexrayCommunicationError) || (RTE_CONST_NTC_Num_FlexrayCommunicationError != 465U)
#   error "Enumeration constant <NTC_Num_FlexrayCommunicationError> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlexrayCommunicationError (465U)
#  define NTC_Num_FlexrayCommunicationError (465U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AI) || (defined NTC_Num_InvalidMsg_AI)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AI) || (RTE_CONST_NTC_Num_InvalidMsg_AI != 466U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AI (466U)
#  define NTC_Num_InvalidMsg_AI (466U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AI) || (defined NTC_Num_MissingMsg_AI)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AI) || (RTE_CONST_NTC_Num_MissingMsg_AI != 467U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AI (467U)
#  define NTC_Num_MissingMsg_AI (467U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AJ) || (defined NTC_Num_InvalidMsg_AJ)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AJ) || (RTE_CONST_NTC_Num_InvalidMsg_AJ != 472U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AJ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AJ (472U)
#  define NTC_Num_InvalidMsg_AJ (472U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AJ) || (defined NTC_Num_MissingMsg_AJ)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AJ) || (RTE_CONST_NTC_Num_MissingMsg_AJ != 473U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AJ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AJ (473U)
#  define NTC_Num_MissingMsg_AJ (473U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AK) || (defined NTC_Num_InvalidMsg_AK)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AK) || (RTE_CONST_NTC_Num_InvalidMsg_AK != 480U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AK (480U)
#  define NTC_Num_InvalidMsg_AK (480U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AK) || (defined NTC_Num_MissingMsg_AK)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AK) || (RTE_CONST_NTC_Num_MissingMsg_AK != 481U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AK (481U)
#  define NTC_Num_MissingMsg_AK (481U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AM) || (defined NTC_Num_MissingMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AM) || (RTE_CONST_NTC_Num_MissingMsg_AM != 482U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AM (482U)
#  define NTC_Num_MissingMsg_AM (482U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AM) || (defined NTC_Num_InvalidMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AM) || (RTE_CONST_NTC_Num_InvalidMsg_AM != 483U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AM (483U)
#  define NTC_Num_InvalidMsg_AM (483U)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AM) || (defined NTC_Num_CRCFltMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AM) || (RTE_CONST_NTC_Num_CRCFltMsg_AM != 484U)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AM (484U)
#  define NTC_Num_CRCFltMsg_AM (484U)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AM) || (defined NTC_Num_PgrsCntFltMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AM) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AM != 485U)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AM (485U)
#  define NTC_Num_PgrsCntFltMsg_AM (485U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AM) || (defined NTC_Num_DataRngFltMsg_AM)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AM) || (RTE_CONST_NTC_Num_DataRngFltMsg_AM != 486U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AM (486U)
#  define NTC_Num_DataRngFltMsg_AM (486U)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AL) || (defined NTC_Num_InvalidMsg_AL)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AL) || (RTE_CONST_NTC_Num_InvalidMsg_AL != 488U)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AL (488U)
#  define NTC_Num_InvalidMsg_AL (488U)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AL) || (defined NTC_Num_MissingMsg_AL)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AL) || (RTE_CONST_NTC_Num_MissingMsg_AL != 489U)
#   error "Enumeration constant <NTC_Num_MissingMsg_AL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AL (489U)
#  define NTC_Num_MissingMsg_AL (489U)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AL) || (defined NTC_Num_DataRngFltMsg_AL)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AL) || (RTE_CONST_NTC_Num_DataRngFltMsg_AL != 492U)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AL (492U)
#  define NTC_Num_DataRngFltMsg_AL (492U)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AL) || (defined NTC_Num_DataOtherFltMsg_AL)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AL) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AL != 494U)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AL (494U)
#  define NTC_Num_DataOtherFltMsg_AL (494U)
# endif
# if (defined RTE_CONST_NTC_Num_SysConsistencyVerf) || (defined NTC_Num_SysConsistencyVerf)
#  if (!defined RTE_CONST_NTC_Num_SysConsistencyVerf) || (RTE_CONST_NTC_Num_SysConsistencyVerf != 496U)
#   error "Enumeration constant <NTC_Num_SysConsistencyVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysConsistencyVerf (496U)
#  define NTC_Num_SysConsistencyVerf (496U)
# endif
# if (defined RTE_CONST_NTC_Num_ConfigMisMatch) || (defined NTC_Num_ConfigMisMatch)
#  if (!defined RTE_CONST_NTC_Num_ConfigMisMatch) || (RTE_CONST_NTC_Num_ConfigMisMatch != 497U)
#   error "Enumeration constant <NTC_Num_ConfigMisMatch> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ConfigMisMatch (497U)
#  define NTC_Num_ConfigMisMatch (497U)
# endif
# if (defined RTE_CONST_NTC_Num_CalNotPrgmd) || (defined NTC_Num_CalNotPrgmd)
#  if (!defined RTE_CONST_NTC_Num_CalNotPrgmd) || (RTE_CONST_NTC_Num_CalNotPrgmd != 498U)
#   error "Enumeration constant <NTC_Num_CalNotPrgmd> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CalNotPrgmd (498U)
#  define NTC_Num_CalNotPrgmd (498U)
# endif
# if (defined RTE_CONST_NTC_Num_TunSetNotPrgmd) || (defined NTC_Num_TunSetNotPrgmd)
#  if (!defined RTE_CONST_NTC_Num_TunSetNotPrgmd) || (RTE_CONST_NTC_Num_TunSetNotPrgmd != 499U)
#   error "Enumeration constant <NTC_Num_TunSetNotPrgmd> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TunSetNotPrgmd (499U)
#  define NTC_Num_TunSetNotPrgmd (499U)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMtoFeeCpyError) || (defined NTC_Num_EEPROMtoFeeCpyError)
#  if (!defined RTE_CONST_NTC_Num_EEPROMtoFeeCpyError) || (RTE_CONST_NTC_Num_EEPROMtoFeeCpyError != 500U)
#   error "Enumeration constant <NTC_Num_EEPROMtoFeeCpyError> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMtoFeeCpyError (500U)
#  define NTC_Num_EEPROMtoFeeCpyError (500U)
# endif
# if (defined RTE_CONST_NTC_Num_EOLVehTunNtPerf) || (defined NTC_Num_EOLVehTunNtPerf)
#  if (!defined RTE_CONST_NTC_Num_EOLVehTunNtPerf) || (RTE_CONST_NTC_Num_EOLVehTunNtPerf != 501U)
#   error "Enumeration constant <NTC_Num_EOLVehTunNtPerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EOLVehTunNtPerf (501U)
#  define NTC_Num_EOLVehTunNtPerf (501U)
# endif
# if (defined RTE_CONST_NTC_Num_MtrSensorNotTrimmed) || (defined NTC_Num_MtrSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_MtrSensorNotTrimmed) || (RTE_CONST_NTC_Num_MtrSensorNotTrimmed != 502U)
#   error "Enumeration constant <NTC_Num_MtrSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MtrSensorNotTrimmed (502U)
#  define NTC_Num_MtrSensorNotTrimmed (502U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorNotTrimmed) || (defined NTC_Num_HWASensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_HWASensorNotTrimmed) || (RTE_CONST_NTC_Num_HWASensorNotTrimmed != 504U)
#   error "Enumeration constant <NTC_Num_HWASensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorNotTrimmed (504U)
#  define NTC_Num_HWASensorNotTrimmed (504U)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorTrimNoAttempt) || (defined NTC_Num_HWASensorTrimNoAttempt)
#  if (!defined RTE_CONST_NTC_Num_HWASensorTrimNoAttempt) || (RTE_CONST_NTC_Num_HWASensorTrimNoAttempt != 505U)
#   error "Enumeration constant <NTC_Num_HWASensorTrimNoAttempt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorTrimNoAttempt (505U)
#  define NTC_Num_HWASensorTrimNoAttempt (505U)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorScaleNotSet) || (defined NTC_Num_TrqSensorScaleNotSet)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorScaleNotSet) || (RTE_CONST_NTC_Num_TrqSensorScaleNotSet != 506U)
#   error "Enumeration constant <NTC_Num_TrqSensorScaleNotSet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorScaleNotSet (506U)
#  define NTC_Num_TrqSensorScaleNotSet (506U)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorNotTrimmed) || (defined NTC_Num_TrqSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorNotTrimmed) || (RTE_CONST_NTC_Num_TrqSensorNotTrimmed != 507U)
#   error "Enumeration constant <NTC_Num_TrqSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorNotTrimmed (507U)
#  define NTC_Num_TrqSensorNotTrimmed (507U)
# endif
# if (defined RTE_CONST_NTC_Num_AnaHWDiffTqOfstNotTrmd) || (defined NTC_Num_AnaHWDiffTqOfstNotTrmd)
#  if (!defined RTE_CONST_NTC_Num_AnaHWDiffTqOfstNotTrmd) || (RTE_CONST_NTC_Num_AnaHWDiffTqOfstNotTrmd != 508U)
#   error "Enumeration constant <NTC_Num_AnaHWDiffTqOfstNotTrmd> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
#  define NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
# endif
# if (defined RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet) || (defined NTC_Num_DigTrqSensorScaleNotSet)
#  if (!defined RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet) || (RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet != 509U)
#   error "Enumeration constant <NTC_Num_DigTrqSensorScaleNotSet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet (509U)
#  define NTC_Num_DigTrqSensorScaleNotSet (509U)
# endif
# if (defined RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed) || (defined NTC_Num_DigTrqSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed) || (RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed != 510U)
#   error "Enumeration constant <NTC_Num_DigTrqSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed (510U)
#  define NTC_Num_DigTrqSensorNotTrimmed (510U)
# endif
# if (defined RTE_CONST_NTC_Num_SENTHWDiffTqOfstNotTrmd) || (defined NTC_Num_SENTHWDiffTqOfstNotTrmd)
#  if (!defined RTE_CONST_NTC_Num_SENTHWDiffTqOfstNotTrmd) || (RTE_CONST_NTC_Num_SENTHWDiffTqOfstNotTrmd != 511U)
#   error "Enumeration constant <NTC_Num_SENTHWDiffTqOfstNotTrmd> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
#  define NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
# endif

# define Rte_TypeDef_New_Coding_39
typedef uint16 New_Coding_39;
# define New_Coding_39_LowerLimit (0U)
# define New_Coding_39_UpperLimit (4095U)
# define Rte_InvalidValue_New_Coding_39 (4095U)
# define InvalidValue_New_Coding_39 (4095U)
# if (defined RTE_CONST_CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#  if (!defined RTE_CONST_CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 4093U)
#   error "Enumeration constant <CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar (4093U)
#  define CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar (4093U)
# endif
# if (defined RTE_CONST_CxFFE_Funktion_meldet_Fehler) || (defined CxFFE_Funktion_meldet_Fehler)
#  if (!defined RTE_CONST_CxFFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFFE_Funktion_meldet_Fehler != 4094U)
#   error "Enumeration constant <CxFFE_Funktion_meldet_Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFFE_Funktion_meldet_Fehler (4094U)
#  define CxFFE_Funktion_meldet_Fehler (4094U)
# endif
# if (defined RTE_CONST_CxFFF_Signal_unbefuellt) || (defined CxFFF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxFFF_Signal_unbefuellt) || (RTE_CONST_CxFFF_Signal_unbefuellt != 4095U)
#   error "Enumeration constant <CxFFF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFFF_Signal_unbefuellt (4095U)
#  define CxFFF_Signal_unbefuellt (4095U)
# endif

# define Rte_TypeDef_New_Coding_44
typedef uint8 New_Coding_44;
# define New_Coding_44_LowerLimit (0U)
# define New_Coding_44_UpperLimit (3U)
# define Rte_InvalidValue_New_Coding_44 (3U)
# define InvalidValue_New_Coding_44 (3U)
# if (defined RTE_CONST_Cx0_Kein_Blinken) || (defined Cx0_Kein_Blinken)
#  if (!defined RTE_CONST_Cx0_Kein_Blinken) || (RTE_CONST_Cx0_Kein_Blinken != 0U)
#   error "Enumeration constant <Cx0_Kein_Blinken> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Kein_Blinken (0U)
#  define Cx0_Kein_Blinken (0U)
# endif
# if (defined RTE_CONST_Cx1_Langsames_Blinken) || (defined Cx1_Langsames_Blinken)
#  if (!defined RTE_CONST_Cx1_Langsames_Blinken) || (RTE_CONST_Cx1_Langsames_Blinken != 1U)
#   error "Enumeration constant <Cx1_Langsames_Blinken> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Langsames_Blinken (1U)
#  define Cx1_Langsames_Blinken (1U)
# endif
# if (defined RTE_CONST_Cx2_Schnelles_Blinken) || (defined Cx2_Schnelles_Blinken)
#  if (!defined RTE_CONST_Cx2_Schnelles_Blinken) || (RTE_CONST_Cx2_Schnelles_Blinken != 2U)
#   error "Enumeration constant <Cx2_Schnelles_Blinken> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Schnelles_Blinken (2U)
#  define Cx2_Schnelles_Blinken (2U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_New_Coding_46
typedef uint8 New_Coding_46;
# define New_Coding_46_LowerLimit (0U)
# define New_Coding_46_UpperLimit (3U)
# define Rte_InvalidValue_New_Coding_46 (3U)
# define InvalidValue_New_Coding_46 (3U)
# if (defined RTE_CONST_Cx0_Ruecksetzen) || (defined Cx0_Ruecksetzen)
#  if (!defined RTE_CONST_Cx0_Ruecksetzen) || (RTE_CONST_Cx0_Ruecksetzen != 0U)
#   error "Enumeration constant <Cx0_Ruecksetzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Ruecksetzen (0U)
#  define Cx0_Ruecksetzen (0U)
# endif
# if (defined RTE_CONST_Cx1_Setzen) || (defined Cx1_Setzen)
#  if (!defined RTE_CONST_Cx1_Setzen) || (RTE_CONST_Cx1_Setzen != 1U)
#   error "Enumeration constant <Cx1_Setzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Setzen (1U)
#  define Cx1_Setzen (1U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_New_Coding_49
typedef uint8 New_Coding_49;
# define New_Coding_49_LowerLimit (0U)
# define New_Coding_49_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_49 (255U)
# define InvalidValue_New_Coding_49 (255U)
# if (defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#  if (!defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 253U)
#   error "Enumeration constant <CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#  define CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
# endif
# if (defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (defined CxFE_Funktion_meldet_Fehler)
#  if (!defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFE_Funktion_meldet_Fehler != 254U)
#   error "Enumeration constant <CxFE_Funktion_meldet_Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFE_Funktion_meldet_Fehler (254U)
#  define CxFE_Funktion_meldet_Fehler (254U)
# endif
# if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#   error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#  define CxFF_Signal_unbefuellt (255U)
# endif

# define Rte_TypeDef_New_Coding_50
typedef uint8 New_Coding_50;
# define New_Coding_50_LowerLimit (0U)
# define New_Coding_50_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_50 (15U)
# define InvalidValue_New_Coding_50 (15U)
# if (defined RTE_CONST_Cx1_Funktion_verfuegbar_nicht_aktiv) || (defined Cx1_Funktion_verfuegbar_nicht_aktiv)
#  if (!defined RTE_CONST_Cx1_Funktion_verfuegbar_nicht_aktiv) || (RTE_CONST_Cx1_Funktion_verfuegbar_nicht_aktiv != 1U)
#   error "Enumeration constant <Cx1_Funktion_verfuegbar_nicht_aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Funktion_verfuegbar_nicht_aktiv (1U)
#  define Cx1_Funktion_verfuegbar_nicht_aktiv (1U)
# endif
# if (defined RTE_CONST_Cx6_Fehler) || (defined Cx6_Fehler)
#  if (!defined RTE_CONST_Cx6_Fehler) || (RTE_CONST_Cx6_Fehler != 6U)
#   error "Enumeration constant <Cx6_Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Fehler (6U)
#  define Cx6_Fehler (6U)
# endif
# if (defined RTE_CONST_Cx9_Funktion_verfuegbar_aktiv) || (defined Cx9_Funktion_verfuegbar_aktiv)
#  if (!defined RTE_CONST_Cx9_Funktion_verfuegbar_aktiv) || (RTE_CONST_Cx9_Funktion_verfuegbar_aktiv != 9U)
#   error "Enumeration constant <Cx9_Funktion_verfuegbar_aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx9_Funktion_verfuegbar_aktiv (9U)
#  define Cx9_Funktion_verfuegbar_aktiv (9U)
# endif
# if (defined RTE_CONST_CxE_Funktion_nicht_verfuegbar) || (defined CxE_Funktion_nicht_verfuegbar)
#  if (!defined RTE_CONST_CxE_Funktion_nicht_verfuegbar) || (RTE_CONST_CxE_Funktion_nicht_verfuegbar != 14U)
#   error "Enumeration constant <CxE_Funktion_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Funktion_nicht_verfuegbar (14U)
#  define CxE_Funktion_nicht_verfuegbar (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#   error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_unbefuellt (15U)
#  define CxF_Signal_unbefuellt (15U)
# endif

# define Rte_TypeDef_NxtrDiagMgrStatus
typedef uint8 NxtrDiagMgrStatus;
# define NxtrDiagMgrStatus_LowerLimit (0U)
# define NxtrDiagMgrStatus_UpperLimit (255U)
# if (defined RTE_CONST_NTC_STATUS_PASSED) || (defined NTC_STATUS_PASSED)
#  if (!defined RTE_CONST_NTC_STATUS_PASSED) || (RTE_CONST_NTC_STATUS_PASSED != 0U)
#   error "Enumeration constant <NTC_STATUS_PASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PASSED (0U)
#  define NTC_STATUS_PASSED (0U)
# endif
# if (defined RTE_CONST_NTC_STATUS_FAILED) || (defined NTC_STATUS_FAILED)
#  if (!defined RTE_CONST_NTC_STATUS_FAILED) || (RTE_CONST_NTC_STATUS_FAILED != 1U)
#   error "Enumeration constant <NTC_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_FAILED (1U)
#  define NTC_STATUS_FAILED (1U)
# endif
# if (defined RTE_CONST_NTC_STATUS_PREPASSED) || (defined NTC_STATUS_PREPASSED)
#  if (!defined RTE_CONST_NTC_STATUS_PREPASSED) || (RTE_CONST_NTC_STATUS_PREPASSED != 2U)
#   error "Enumeration constant <NTC_STATUS_PREPASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PREPASSED (2U)
#  define NTC_STATUS_PREPASSED (2U)
# endif
# if (defined RTE_CONST_NTC_STATUS_PREFAILED) || (defined NTC_STATUS_PREFAILED)
#  if (!defined RTE_CONST_NTC_STATUS_PREFAILED) || (RTE_CONST_NTC_STATUS_PREFAILED != 3U)
#   error "Enumeration constant <NTC_STATUS_PREFAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PREFAILED (3U)
#  define NTC_STATUS_PREFAILED (3U)
# endif

# define Rte_TypeDef_QU_AVL_FORC_GRD
typedef uint8 QU_AVL_FORC_GRD;
# define QU_AVL_FORC_GRD_LowerLimit (0U)
# define QU_AVL_FORC_GRD_UpperLimit (15U)
# define Rte_InvalidValue_QU_AVL_FORC_GRD (15U)
# define InvalidValue_QU_AVL_FORC_GRD (15U)
# if (defined RTE_CONST_Cx2_Signalwert_ist_gueltig) || (defined Cx2_Signalwert_ist_gueltig)
#  if (!defined RTE_CONST_Cx2_Signalwert_ist_gueltig) || (RTE_CONST_Cx2_Signalwert_ist_gueltig != 2U)
#   error "Enumeration constant <Cx2_Signalwert_ist_gueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Signalwert_ist_gueltig (2U)
#  define Cx2_Signalwert_ist_gueltig (2U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#  if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#   error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung (8U)
#  define Cx8_Initialisierung (8U)
# endif
# if (defined RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer) || (defined CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer) || (RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer != 14U)
#   error "Enumeration constant <CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
#  define CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_QU_AVL_PINA_EPS
typedef uint8 QU_AVL_PINA_EPS;
# define QU_AVL_PINA_EPS_LowerLimit (0U)
# define QU_AVL_PINA_EPS_UpperLimit (15U)
# define Rte_InvalidValue_QU_AVL_PINA_EPS (15U)
# define InvalidValue_QU_AVL_PINA_EPS (15U)
# if (defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (defined Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert)
#  if (!defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert != 1U)
#   error "Enumeration constant <Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#  define Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
# endif
# if (defined RTE_CONST_Cx2_Signalwert_ist_gueltig) || (defined Cx2_Signalwert_ist_gueltig)
#  if (!defined RTE_CONST_Cx2_Signalwert_ist_gueltig) || (RTE_CONST_Cx2_Signalwert_ist_gueltig != 2U)
#   error "Enumeration constant <Cx2_Signalwert_ist_gueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Signalwert_ist_gueltig (2U)
#  define Cx2_Signalwert_ist_gueltig (2U)
# endif
# if (defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (defined Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt)
#  if (!defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt != 4U)
#   error "Enumeration constant <Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#  define Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#  if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#   error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung (8U)
#  define Cx8_Initialisierung (8U)
# endif
# if (defined RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer) || (defined CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer) || (RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer != 10U)
#   error "Enumeration constant <CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
#  define CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
# endif
# if (defined RTE_CONST_CxC_Abgleichwert_ist_im_Nutzsignal_gesetzt___Zustand_Status_temporaer) || (defined CxC_Abgleichwert_ist_im_Nutzsignal_gesetzt___Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxC_Abgleichwert_ist_im_Nutzsignal_gesetzt___Zustand_Status_temporaer) || (RTE_CONST_CxC_Abgleichwert_ist_im_Nutzsignal_gesetzt___Zustand_Status_temporaer != 12U)
#   error "Enumeration constant <CxC_Abgleichwert_ist_im_Nutzsignal_gesetzt___Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxC_Abgleichwert_ist_im_Nutzsignal_gesetzt___Zustand_Status_temporaer (12U)
#  define CxC_Abgleichwert_ist_im_Nutzsignal_gesetzt___Zustand_Status_temporaer (12U)
# endif
# if (defined RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer) || (defined CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer) || (RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer != 14U)
#   error "Enumeration constant <CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
#  define CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_QU_AVL_STMOM_DV_ACT
typedef uint8 QU_AVL_STMOM_DV_ACT;
# define QU_AVL_STMOM_DV_ACT_LowerLimit (0U)
# define QU_AVL_STMOM_DV_ACT_UpperLimit (15U)
# define Rte_InvalidValue_QU_AVL_STMOM_DV_ACT (15U)
# define InvalidValue_QU_AVL_STMOM_DV_ACT (15U)
# if (defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (defined Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert)
#  if (!defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert != 1U)
#   error "Enumeration constant <Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#  define Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
# endif
# if (defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (defined Cx6_Signalwert_ist_ungueltig)
#  if (!defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (RTE_CONST_Cx6_Signalwert_ist_ungueltig != 6U)
#   error "Enumeration constant <Cx6_Signalwert_ist_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Signalwert_ist_ungueltig (6U)
#  define Cx6_Signalwert_ist_ungueltig (6U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#  if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#   error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung (8U)
#  define Cx8_Initialisierung (8U)
# endif
# if (defined RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer) || (defined CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer) || (RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer != 14U)
#   error "Enumeration constant <CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
#  define CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_QU_FN_EST
typedef uint8 QU_FN_EST;
# define QU_FN_EST_LowerLimit (0U)
# define QU_FN_EST_UpperLimit (255U)
# define Rte_InvalidValue_QU_FN_EST (255U)
# define InvalidValue_QU_FN_EST (255U)
# if (defined RTE_CONST_Cx31_Funktion_in_Rueckfallebene) || (defined Cx31_Funktion_in_Rueckfallebene)
#  if (!defined RTE_CONST_Cx31_Funktion_in_Rueckfallebene) || (RTE_CONST_Cx31_Funktion_in_Rueckfallebene != 49U)
#   error "Enumeration constant <Cx31_Funktion_in_Rueckfallebene> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx31_Funktion_in_Rueckfallebene (49U)
#  define Cx31_Funktion_in_Rueckfallebene (49U)
# endif
# if (defined RTE_CONST_Cx33_Funktion_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv) || (defined Cx33_Funktion_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv)
#  if (!defined RTE_CONST_Cx33_Funktion_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv) || (RTE_CONST_Cx33_Funktion_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv != 51U)
#   error "Enumeration constant <Cx33_Funktion_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx33_Funktion_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv (51U)
#  define Cx33_Funktion_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv (51U)
# endif
# if (defined RTE_CONST_Cx60_Funktion_nicht_verfuegbar___Fehler) || (defined Cx60_Funktion_nicht_verfuegbar___Fehler)
#  if (!defined RTE_CONST_Cx60_Funktion_nicht_verfuegbar___Fehler) || (RTE_CONST_Cx60_Funktion_nicht_verfuegbar___Fehler != 96U)
#   error "Enumeration constant <Cx60_Funktion_nicht_verfuegbar___Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx60_Funktion_nicht_verfuegbar___Fehler (96U)
#  define Cx60_Funktion_nicht_verfuegbar___Fehler (96U)
# endif
# if (defined RTE_CONST_Cx80_Initialisierung) || (defined Cx80_Initialisierung)
#  if (!defined RTE_CONST_Cx80_Initialisierung) || (RTE_CONST_Cx80_Initialisierung != 128U)
#   error "Enumeration constant <Cx80_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx80_Initialisierung (128U)
#  define Cx80_Initialisierung (128U)
# endif
# if (defined RTE_CONST_CxA0_Funktion_verfuegbar___Aktiv__12V_EPS) || (defined CxA0_Funktion_verfuegbar___Aktiv__12V_EPS)
#  if (!defined RTE_CONST_CxA0_Funktion_verfuegbar___Aktiv__12V_EPS) || (RTE_CONST_CxA0_Funktion_verfuegbar___Aktiv__12V_EPS != 160U)
#   error "Enumeration constant <CxA0_Funktion_verfuegbar___Aktiv__12V_EPS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA0_Funktion_verfuegbar___Aktiv__12V_EPS (160U)
#  define CxA0_Funktion_verfuegbar___Aktiv__12V_EPS (160U)
# endif
# if (defined RTE_CONST_CxA2_Funktion_verfuegbar___Aktiv__Notfallfunktion_Umwelteinfluesse___Aktiv) || (defined CxA2_Funktion_verfuegbar___Aktiv__Notfallfunktion_Umwelteinfluesse___Aktiv)
#  if (!defined RTE_CONST_CxA2_Funktion_verfuegbar___Aktiv__Notfallfunktion_Umwelteinfluesse___Aktiv) || (RTE_CONST_CxA2_Funktion_verfuegbar___Aktiv__Notfallfunktion_Umwelteinfluesse___Aktiv != 162U)
#   error "Enumeration constant <CxA2_Funktion_verfuegbar___Aktiv__Notfallfunktion_Umwelteinfluesse___Aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA2_Funktion_verfuegbar___Aktiv__Notfallfunktion_Umwelteinfluesse___Aktiv (162U)
#  define CxA2_Funktion_verfuegbar___Aktiv__Notfallfunktion_Umwelteinfluesse___Aktiv (162U)
# endif
# if (defined RTE_CONST_CxA4_Funktion_verfuegbar___Aktiv__12V_EAS) || (defined CxA4_Funktion_verfuegbar___Aktiv__12V_EAS)
#  if (!defined RTE_CONST_CxA4_Funktion_verfuegbar___Aktiv__12V_EAS) || (RTE_CONST_CxA4_Funktion_verfuegbar___Aktiv__12V_EAS != 164U)
#   error "Enumeration constant <CxA4_Funktion_verfuegbar___Aktiv__12V_EAS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA4_Funktion_verfuegbar___Aktiv__12V_EAS (164U)
#  define CxA4_Funktion_verfuegbar___Aktiv__12V_EAS (164U)
# endif
# if (defined RTE_CONST_CxA8_Funktion_verfuegbar___Aktiv__24V_EAS) || (defined CxA8_Funktion_verfuegbar___Aktiv__24V_EAS)
#  if (!defined RTE_CONST_CxA8_Funktion_verfuegbar___Aktiv__24V_EAS) || (RTE_CONST_CxA8_Funktion_verfuegbar___Aktiv__24V_EAS != 168U)
#   error "Enumeration constant <CxA8_Funktion_verfuegbar___Aktiv__24V_EAS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA8_Funktion_verfuegbar___Aktiv__24V_EAS (168U)
#  define CxA8_Funktion_verfuegbar___Aktiv__24V_EAS (168U)
# endif
# if (defined RTE_CONST_CxB0_Funktion_temporaer_in_Rueckfallebene) || (defined CxB0_Funktion_temporaer_in_Rueckfallebene)
#  if (!defined RTE_CONST_CxB0_Funktion_temporaer_in_Rueckfallebene) || (RTE_CONST_CxB0_Funktion_temporaer_in_Rueckfallebene != 176U)
#   error "Enumeration constant <CxB0_Funktion_temporaer_in_Rueckfallebene> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxB0_Funktion_temporaer_in_Rueckfallebene (176U)
#  define CxB0_Funktion_temporaer_in_Rueckfallebene (176U)
# endif
# if (defined RTE_CONST_CxB2_Funktion_temporaer_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv) || (defined CxB2_Funktion_temporaer_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv)
#  if (!defined RTE_CONST_CxB2_Funktion_temporaer_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv) || (RTE_CONST_CxB2_Funktion_temporaer_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv != 178U)
#   error "Enumeration constant <CxB2_Funktion_temporaer_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxB2_Funktion_temporaer_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv (178U)
#  define CxB2_Funktion_temporaer_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv (178U)
# endif
# if (defined RTE_CONST_CxE0_Funktion_nicht_verfuegbar___ausgeschaltet) || (defined CxE0_Funktion_nicht_verfuegbar___ausgeschaltet)
#  if (!defined RTE_CONST_CxE0_Funktion_nicht_verfuegbar___ausgeschaltet) || (RTE_CONST_CxE0_Funktion_nicht_verfuegbar___ausgeschaltet != 224U)
#   error "Enumeration constant <CxE0_Funktion_nicht_verfuegbar___ausgeschaltet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE0_Funktion_nicht_verfuegbar___ausgeschaltet (224U)
#  define CxE0_Funktion_nicht_verfuegbar___ausgeschaltet (224U)
# endif
# if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255U)
#   error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_ungueltig (255U)
#  define CxFF_Signal_ungueltig (255U)
# endif

# define Rte_TypeDef_QU_SER_STMOM_STMOM_DV_ACT
typedef uint8 QU_SER_STMOM_STMOM_DV_ACT;
# define QU_SER_STMOM_STMOM_DV_ACT_LowerLimit (0U)
# define QU_SER_STMOM_STMOM_DV_ACT_UpperLimit (255U)
# define Rte_InvalidValue_QU_SER_STMOM_STMOM_DV_ACT (255U)
# define InvalidValue_QU_SER_STMOM_STMOM_DV_ACT (255U)
# if (defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit_ohne_Zusatzdaempfung) || (defined Cx20_Schnittstelle_verfuegbar___funktionsbereit_ohne_Zusatzdaempfung)
#  if (!defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit_ohne_Zusatzdaempfung) || (RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit_ohne_Zusatzdaempfung != 32U)
#   error "Enumeration constant <Cx20_Schnittstelle_verfuegbar___funktionsbereit_ohne_Zusatzdaempfung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit_ohne_Zusatzdaempfung (32U)
#  define Cx20_Schnittstelle_verfuegbar___funktionsbereit_ohne_Zusatzdaempfung (32U)
# endif
# if (defined RTE_CONST_Cx21_Schnittstelle_aktiv___Zusatzdaempfung_nicht_verfuegbar) || (defined Cx21_Schnittstelle_aktiv___Zusatzdaempfung_nicht_verfuegbar)
#  if (!defined RTE_CONST_Cx21_Schnittstelle_aktiv___Zusatzdaempfung_nicht_verfuegbar) || (RTE_CONST_Cx21_Schnittstelle_aktiv___Zusatzdaempfung_nicht_verfuegbar != 33U)
#   error "Enumeration constant <Cx21_Schnittstelle_aktiv___Zusatzdaempfung_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx21_Schnittstelle_aktiv___Zusatzdaempfung_nicht_verfuegbar (33U)
#  define Cx21_Schnittstelle_aktiv___Zusatzdaempfung_nicht_verfuegbar (33U)
# endif
# if (defined RTE_CONST_Cx22_Schnittstelle_verfuegbar___funktionsbereit_mit_Zusatzdaempfung) || (defined Cx22_Schnittstelle_verfuegbar___funktionsbereit_mit_Zusatzdaempfung)
#  if (!defined RTE_CONST_Cx22_Schnittstelle_verfuegbar___funktionsbereit_mit_Zusatzdaempfung) || (RTE_CONST_Cx22_Schnittstelle_verfuegbar___funktionsbereit_mit_Zusatzdaempfung != 34U)
#   error "Enumeration constant <Cx22_Schnittstelle_verfuegbar___funktionsbereit_mit_Zusatzdaempfung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx22_Schnittstelle_verfuegbar___funktionsbereit_mit_Zusatzdaempfung (34U)
#  define Cx22_Schnittstelle_verfuegbar___funktionsbereit_mit_Zusatzdaempfung (34U)
# endif
# if (defined RTE_CONST_Cx23_Schnittstelle_aktiv___Zusatzdaempfung_verfuegbar) || (defined Cx23_Schnittstelle_aktiv___Zusatzdaempfung_verfuegbar)
#  if (!defined RTE_CONST_Cx23_Schnittstelle_aktiv___Zusatzdaempfung_verfuegbar) || (RTE_CONST_Cx23_Schnittstelle_aktiv___Zusatzdaempfung_verfuegbar != 35U)
#   error "Enumeration constant <Cx23_Schnittstelle_aktiv___Zusatzdaempfung_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx23_Schnittstelle_aktiv___Zusatzdaempfung_verfuegbar (35U)
#  define Cx23_Schnittstelle_aktiv___Zusatzdaempfung_verfuegbar (35U)
# endif
# if (defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (defined Cx60_Service_nicht_verfuegbar___Fehler)
#  if (!defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler != 96U)
#   error "Enumeration constant <Cx60_Service_nicht_verfuegbar___Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler (96U)
#  define Cx60_Service_nicht_verfuegbar___Fehler (96U)
# endif
# if (defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (defined Cx80_Schnittstelle_wird_initialisiert)
#  if (!defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (RTE_CONST_Cx80_Schnittstelle_wird_initialisiert != 128U)
#   error "Enumeration constant <Cx80_Schnittstelle_wird_initialisiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx80_Schnittstelle_wird_initialisiert (128U)
#  define Cx80_Schnittstelle_wird_initialisiert (128U)
# endif
# if (defined RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA) || (defined CxE0_Service_nicht_verfuegbar___Standby___PMA)
#  if (!defined RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA) || (RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA != 224U)
#   error "Enumeration constant <CxE0_Service_nicht_verfuegbar___Standby___PMA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA (224U)
#  define CxE0_Service_nicht_verfuegbar___Standby___PMA (224U)
# endif
# if (defined RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status) || (defined CxE1_Service_nicht_verfuegbar___Standby___EPS_Status)
#  if (!defined RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status) || (RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status != 225U)
#   error "Enumeration constant <CxE1_Service_nicht_verfuegbar___Standby___EPS_Status> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status (225U)
#  define CxE1_Service_nicht_verfuegbar___Standby___EPS_Status (225U)
# endif
# if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255U)
#   error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_ungueltig (255U)
#  define CxFF_Signal_ungueltig (255U)
# endif

# define Rte_TypeDef_QU_SER_WSTA_EST_FTAX
typedef uint8 QU_SER_WSTA_EST_FTAX;
# define QU_SER_WSTA_EST_FTAX_LowerLimit (0U)
# define QU_SER_WSTA_EST_FTAX_UpperLimit (255U)
# define Rte_InvalidValue_QU_SER_WSTA_EST_FTAX (255U)
# define InvalidValue_QU_SER_WSTA_EST_FTAX (255U)
# if (defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit) || (defined Cx20_Schnittstelle_verfuegbar___funktionsbereit)
#  if (!defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit) || (RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit != 32U)
#   error "Enumeration constant <Cx20_Schnittstelle_verfuegbar___funktionsbereit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit (32U)
#  define Cx20_Schnittstelle_verfuegbar___funktionsbereit (32U)
# endif
# if (defined RTE_CONST_Cx21_Schnittstelle_aktiv) || (defined Cx21_Schnittstelle_aktiv)
#  if (!defined RTE_CONST_Cx21_Schnittstelle_aktiv) || (RTE_CONST_Cx21_Schnittstelle_aktiv != 33U)
#   error "Enumeration constant <Cx21_Schnittstelle_aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx21_Schnittstelle_aktiv (33U)
#  define Cx21_Schnittstelle_aktiv (33U)
# endif
# if (defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (defined Cx60_Service_nicht_verfuegbar___Fehler)
#  if (!defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler != 96U)
#   error "Enumeration constant <Cx60_Service_nicht_verfuegbar___Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler (96U)
#  define Cx60_Service_nicht_verfuegbar___Fehler (96U)
# endif
# if (defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (defined Cx80_Schnittstelle_wird_initialisiert)
#  if (!defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (RTE_CONST_Cx80_Schnittstelle_wird_initialisiert != 128U)
#   error "Enumeration constant <Cx80_Schnittstelle_wird_initialisiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx80_Schnittstelle_wird_initialisiert (128U)
#  define Cx80_Schnittstelle_wird_initialisiert (128U)
# endif
# if (defined RTE_CONST_CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0) || (defined CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0)
#  if (!defined RTE_CONST_CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0) || (RTE_CONST_CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 != 224U)
#   error "Enumeration constant <CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 (224U)
#  define CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 (224U)
# endif
# if (defined RTE_CONST_CxE2_Funktion_in_Rueckfallebene___Hands_On) || (defined CxE2_Funktion_in_Rueckfallebene___Hands_On)
#  if (!defined RTE_CONST_CxE2_Funktion_in_Rueckfallebene___Hands_On) || (RTE_CONST_CxE2_Funktion_in_Rueckfallebene___Hands_On != 226U)
#   error "Enumeration constant <CxE2_Funktion_in_Rueckfallebene___Hands_On> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE2_Funktion_in_Rueckfallebene___Hands_On (226U)
#  define CxE2_Funktion_in_Rueckfallebene___Hands_On (226U)
# endif
# if (defined RTE_CONST_CxE3_Funktion_in_Rueckfallebene___EPS_Status) || (defined CxE3_Funktion_in_Rueckfallebene___EPS_Status)
#  if (!defined RTE_CONST_CxE3_Funktion_in_Rueckfallebene___EPS_Status) || (RTE_CONST_CxE3_Funktion_in_Rueckfallebene___EPS_Status != 227U)
#   error "Enumeration constant <CxE3_Funktion_in_Rueckfallebene___EPS_Status> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE3_Funktion_in_Rueckfallebene___EPS_Status (227U)
#  define CxE3_Funktion_in_Rueckfallebene___EPS_Status (227U)
# endif
# if (defined RTE_CONST_CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen) || (defined CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen)
#  if (!defined RTE_CONST_CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen) || (RTE_CONST_CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen != 228U)
#   error "Enumeration constant <CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen (228U)
#  define CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen (228U)
# endif
# if (defined RTE_CONST_CxE7_Schnittstelle_aktiv_degradiert) || (defined CxE7_Schnittstelle_aktiv_degradiert)
#  if (!defined RTE_CONST_CxE7_Schnittstelle_aktiv_degradiert) || (RTE_CONST_CxE7_Schnittstelle_aktiv_degradiert != 231U)
#   error "Enumeration constant <CxE7_Schnittstelle_aktiv_degradiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE7_Schnittstelle_aktiv_degradiert (231U)
#  define CxE7_Schnittstelle_aktiv_degradiert (231U)
# endif
# if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255U)
#   error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_ungueltig (255U)
#  define CxFF_Signal_ungueltig (255U)
# endif

# define Rte_TypeDef_TJAStateType
typedef uint8 TJAStateType;
# define TJAStateType_LowerLimit (1U)
# define TJAStateType_UpperLimit (3U)
# if (defined RTE_CONST_TJA_Inactive) || (defined TJA_Inactive)
#  if (!defined RTE_CONST_TJA_Inactive) || (RTE_CONST_TJA_Inactive != 1U)
#   error "Enumeration constant <TJA_Inactive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TJA_Inactive (1U)
#  define TJA_Inactive (1U)
# endif
# if (defined RTE_CONST_TJA_Active) || (defined TJA_Active)
#  if (!defined RTE_CONST_TJA_Active) || (RTE_CONST_TJA_Active != 2U)
#   error "Enumeration constant <TJA_Active> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TJA_Active (2U)
#  define TJA_Active (2U)
# endif
# if (defined RTE_CONST_TJA_Error) || (defined TJA_Error)
#  if (!defined RTE_CONST_TJA_Error) || (RTE_CONST_TJA_Error != 3U)
#   error "Enumeration constant <TJA_Error> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TJA_Error (3U)
#  define TJA_Error (3U)
# endif

# define Rte_TypeDef_UN_PO_EPS
typedef uint8 UN_PO_EPS;
# define UN_PO_EPS_LowerLimit (0U)
# define UN_PO_EPS_UpperLimit (3U)
# define Rte_InvalidValue_UN_PO_EPS (3U)
# define InvalidValue_UN_PO_EPS (3U)
# if (defined RTE_CONST_Cx0_Ritzelschnittstelle) || (defined Cx0_Ritzelschnittstelle)
#  if (!defined RTE_CONST_Cx0_Ritzelschnittstelle) || (RTE_CONST_Cx0_Ritzelschnittstelle != 0U)
#   error "Enumeration constant <Cx0_Ritzelschnittstelle> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Ritzelschnittstelle (0U)
#  define Cx0_Ritzelschnittstelle (0U)
# endif
# if (defined RTE_CONST_Cx1_Zahnstangenhubschnittstelle) || (defined Cx1_Zahnstangenhubschnittstelle)
#  if (!defined RTE_CONST_Cx1_Zahnstangenhubschnittstelle) || (RTE_CONST_Cx1_Zahnstangenhubschnittstelle != 1U)
#   error "Enumeration constant <Cx1_Zahnstangenhubschnittstelle> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Zahnstangenhubschnittstelle (1U)
#  define Cx1_Zahnstangenhubschnittstelle (1U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_UN_TOT_STR_EPS
typedef uint8 UN_TOT_STR_EPS;
# define UN_TOT_STR_EPS_LowerLimit (0U)
# define UN_TOT_STR_EPS_UpperLimit (3U)
# define Rte_InvalidValue_UN_TOT_STR_EPS (3U)
# define InvalidValue_UN_TOT_STR_EPS (3U)
# if (defined RTE_CONST_Cx0_Ritzelschnittstelle) || (defined Cx0_Ritzelschnittstelle)
#  if (!defined RTE_CONST_Cx0_Ritzelschnittstelle) || (RTE_CONST_Cx0_Ritzelschnittstelle != 0U)
#   error "Enumeration constant <Cx0_Ritzelschnittstelle> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Ritzelschnittstelle (0U)
#  define Cx0_Ritzelschnittstelle (0U)
# endif
# if (defined RTE_CONST_Cx1_Zahnstangenhubschnittstelle) || (defined Cx1_Zahnstangenhubschnittstelle)
#  if (!defined RTE_CONST_Cx1_Zahnstangenhubschnittstelle) || (RTE_CONST_Cx1_Zahnstangenhubschnittstelle != 1U)
#   error "Enumeration constant <Cx1_Zahnstangenhubschnittstelle> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Zahnstangenhubschnittstelle (1U)
#  define Cx1_Zahnstangenhubschnittstelle (1U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_RT_SG_AVL_FORC_GRD
typedef struct
{
  ALIV_COU_4 ALIV_AVL_FORC_GRD;
  AVL_FORC_GRD AVL_FORC_GRD;
  CD_0x04 AVL_FORC_GRD_0x0C_0x04;
  AVL_PWR_EL AVL_PWR_EL_EPS_COOD;
  CRC8 CRC_AVL_FORC_GRD;
  QU_AVL_FORC_GRD QU_AVL_FORC_GRD;
} RT_SG_AVL_FORC_GRD;

# define Rte_TypeDef_RT_SG_AVL_PO_EPS
typedef struct
{
  ALIV_COU_4 ALIV_AVL_PO_EPS;
  AVL_PINA_EPS AVL_PO_EPS;
  CRC8 CRC_AVL_PO_EPS;
  IDX_TORQ_SEN IDX_TORQ_SEN;
  AVL_PINA_IDX_ICM AVL_PO_IDX_EPS;
  OFFS_GRD_MID_EPS OFFS_GRD_MID_EPS;
  QU_AVL_PINA_EPS QU_AVL_PO_EPS;
  UN_PO_EPS UN_PO_EPS;
} RT_SG_AVL_PO_EPS;

# define Rte_TypeDef_RT_SG_AVL_STMOM_DV_ACT
typedef struct
{
  ALIV_COU_4 ALIV_AVL_STMOM_DV_ACT;
  STMOM_QTA_DV AVL_STMOM_DV_ACT;
  CD_0x04 AVL_STMOM_DV_ACT_0x0C_0x04;
  CRC8 CRC_AVL_STMOM_DV_ACT;
  QU_AVL_STMOM_DV_ACT QU_AVL_STMOM_DV_ACT;
} RT_SG_AVL_STMOM_DV_ACT;

# define Rte_TypeDef_RT_SG_ST_EST
typedef struct
{
  ALIV_COU_4 ALIV_ST_EST_FTAX;
  CRC8 CRC_ST_EST_FTAX;
  QU_FN_EST QU_FN_EST;
  CD_0x08 ST_EST_0x10_0x08;
  QU_SER_STMOM_STMOM_DV_ACT QU_SER_STMOM_DV_ACT;
  New_Coding_50 QU_FN_VIB_EPS;
} RT_SG_ST_EST;

# define Rte_TypeDef_RT_SG_SU_EPS
typedef struct
{
  TOT_STR_EPS TOT_STR_EPS;
  UN_TOT_STR_EPS UN_TOT_STR_EPS;
  New_Coding_51 ALIV_SU_EPS;
  New_Coding_52 CRC_SU_EPS;
  CD_0x20 SU_EPS_0x0E_0x20;
  CD_0x06 SU_EPS_0x2E_0x06;
} RT_SG_SU_EPS;

# define Rte_TypeDef_SG_DISP_CC_EPS
typedef struct
{
  New_Coding_45 TRANF_CC_EPS;
  New_Coding_43 NO_CC_EPS;
  New_Coding_46 ST_CC_EPS;
  New_Coding_44 ST_IDC_CC_EPS;
  New_Coding_40 CRC_DISP_CC_EPS;
  New_Coding_41 CHL_DISP_CC_EPS;
  New_Coding_42 ALIV_DISP_CC_EPS;
} SG_DISP_CC_EPS;

# define Rte_TypeDef_SG_DT_EST
typedef struct
{
  New_Coding_47 CRC_DT_EST;
  CD_0x20 DT_EST_0x38_0x20;
  CD_0x04 DT_EST_0x2C_0x04;
  New_Coding_48 ALIV_DT_EST;
  New_Coding_49 AVL_I_ACT_EST;
  CD_0x08 DT_EST_0x78_0x08;
  CD_0x20 DT_EST_0x0C_0x20;
  CD_0x20 DT_EST_0x58_0x20;
} SG_DT_EST;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_ALIV_4_BIT_Unsigned_Integer
typedef uint8 ALIV_4_BIT_Unsigned_Integer;
#  define ALIV_4_BIT_Unsigned_Integer_LowerLimit (0U)
#  define ALIV_4_BIT_Unsigned_Integer_UpperLimit (14U)
#  define Rte_InvalidValue_ALIV_4_BIT_Unsigned_Integer (15U)
#  define InvalidValue_ALIV_4_BIT_Unsigned_Integer (15U)

#  define Rte_TypeDef_BATT_VOLTS
typedef uint16 BATT_VOLTS;
#  define BATT_VOLTS_LowerLimit (0U)
#  define BATT_VOLTS_UpperLimit (65535U)

#  define Rte_TypeDef_CONT_TEMP_DEG
typedef uint8 CONT_TEMP_DEG;
#  define CONT_TEMP_DEG_LowerLimit (0U)
#  define CONT_TEMP_DEG_UpperLimit (255U)

#  define Rte_TypeDef_DIAG_ST_OBD
typedef uint8 DIAG_ST_OBD;
#  define DIAG_ST_OBD_LowerLimit (0U)
#  define DIAG_ST_OBD_UpperLimit (63U)
#  define Rte_InvalidValue_DIAG_ST_OBD (63U)
#  define InvalidValue_DIAG_ST_OBD (63U)

#  define Rte_TypeDef_DIFF_TRQ_NM
typedef sint16 DIFF_TRQ_NM;
#  define DIFF_TRQ_NM_LowerLimit (-32768)
#  define DIFF_TRQ_NM_UpperLimit (32767)

#  define Rte_TypeDef_EST_BATT_AMPS
typedef sint16 EST_BATT_AMPS;
#  define EST_BATT_AMPS_LowerLimit (-32768)
#  define EST_BATT_AMPS_UpperLimit (32767)

#  define Rte_TypeDef_EST_CUTEMP_DEG
typedef uint8 EST_CUTEMP_DEG;
#  define EST_CUTEMP_DEG_LowerLimit (0U)
#  define EST_CUTEMP_DEG_UpperLimit (255U)

#  define Rte_TypeDef_EST_MOTTEMP_DEG
typedef uint8 EST_MOTTEMP_DEG;
#  define EST_MOTTEMP_DEG_LowerLimit (0U)
#  define EST_MOTTEMP_DEG_UpperLimit (255U)

#  define Rte_TypeDef_MOT_VEL_RADPSEC
typedef sint16 MOT_VEL_RADPSEC;
#  define MOT_VEL_RADPSEC_LowerLimit (-32768)
#  define MOT_VEL_RADPSEC_UpperLimit (32767)

#  define Rte_TypeDef_MTRTRQCMD_NM
typedef sint16 MTRTRQCMD_NM;
#  define MTRTRQCMD_NM_LowerLimit (-32768)
#  define MTRTRQCMD_NM_UpperLimit (32767)

#  define Rte_TypeDef_MTRTRQLMTD_NM
typedef sint16 MTRTRQLMTD_NM;
#  define MTRTRQLMTD_NM_LowerLimit (-32768)
#  define MTRTRQLMTD_NM_UpperLimit (32767)

#  define Rte_TypeDef_New_Coding_15
typedef uint8 New_Coding_15;
#  define New_Coding_15_LowerLimit (0U)
#  define New_Coding_15_UpperLimit (255U)

#  define Rte_TypeDef_New_Coding_28
typedef uint16 New_Coding_28;
#  define New_Coding_28_LowerLimit (0U)
#  define New_Coding_28_UpperLimit (65535U)

#  define Rte_TypeDef_New_Coding_3
typedef uint16 New_Coding_3;
#  define New_Coding_3_LowerLimit (0U)
#  define New_Coding_3_UpperLimit (65535U)

#  define Rte_TypeDef_ST_DIAG_OBD_MUX_MAX
typedef uint8 ST_DIAG_OBD_MUX_MAX;
#  define ST_DIAG_OBD_MUX_MAX_LowerLimit (0U)
#  define ST_DIAG_OBD_MUX_MAX_UpperLimit (60U)
#  define Rte_InvalidValue_ST_DIAG_OBD_MUX_MAX (63U)
#  define InvalidValue_ST_DIAG_OBD_MUX_MAX (63U)

#  define Rte_TypeDef_SWA_DEG
typedef sint16 SWA_DEG;
#  define SWA_DEG_LowerLimit (-32768)
#  define SWA_DEG_UpperLimit (32767)

#  define Rte_TypeDef_THRML_LIMIT_PERC
typedef uint8 THRML_LIMIT_PERC;
#  define THRML_LIMIT_PERC_LowerLimit (0U)
#  define THRML_LIMIT_PERC_UpperLimit (1U)

#  define Rte_TypeDef_TORQUE1_VOLTS
typedef uint16 TORQUE1_VOLTS;
#  define TORQUE1_VOLTS_LowerLimit (0U)
#  define TORQUE1_VOLTS_UpperLimit (65535U)

#  define Rte_TypeDef_TORQUE2_VOLTS
typedef uint16 TORQUE2_VOLTS;
#  define TORQUE2_VOLTS_LowerLimit (0U)
#  define TORQUE2_VOLTS_UpperLimit (65535U)

#  define Rte_TypeDef_UInt4
typedef uint8 UInt4;
#  define UInt4_LowerLimit (0U)
#  define UInt4_UpperLimit (15U)

#  define Rte_TypeDef_UInt6
typedef uint8 UInt6;
#  define UInt6_LowerLimit (0U)
#  define UInt6_UpperLimit (63U)
#  define Rte_InvalidValue_UInt6 (63U)
#  define InvalidValue_UInt6 (63U)

#  define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;
#  define ComM_ModeType_LowerLimit (0U)
#  define ComM_ModeType_UpperLimit (2U)
#  if (defined RTE_CONST_COMM_NO_COMMUNICATION) || (defined COMM_NO_COMMUNICATION)
#   if (!defined RTE_CONST_COMM_NO_COMMUNICATION) || (RTE_CONST_COMM_NO_COMMUNICATION != 0U)
#    error "Enumeration constant <COMM_NO_COMMUNICATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_COMM_NO_COMMUNICATION (0U)
#   define COMM_NO_COMMUNICATION (0U)
#  endif
#  if (defined RTE_CONST_COMM_SILENT_COMMUNICATION) || (defined COMM_SILENT_COMMUNICATION)
#   if (!defined RTE_CONST_COMM_SILENT_COMMUNICATION) || (RTE_CONST_COMM_SILENT_COMMUNICATION != 1U)
#    error "Enumeration constant <COMM_SILENT_COMMUNICATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_COMM_SILENT_COMMUNICATION (1U)
#   define COMM_SILENT_COMMUNICATION (1U)
#  endif
#  if (defined RTE_CONST_COMM_FULL_COMMUNICATION) || (defined COMM_FULL_COMMUNICATION)
#   if (!defined RTE_CONST_COMM_FULL_COMMUNICATION) || (RTE_CONST_COMM_FULL_COMMUNICATION != 2U)
#    error "Enumeration constant <COMM_FULL_COMMUNICATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_COMM_FULL_COMMUNICATION (2U)
#   define COMM_FULL_COMMUNICATION (2U)
#  endif

#  define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;
#  define Dem_IndicatorStatusType_LowerLimit (0U)
#  define Dem_IndicatorStatusType_UpperLimit (3U)
#  if (defined RTE_CONST_DEM_INDICATOR_OFF) || (defined DEM_INDICATOR_OFF)
#   if (!defined RTE_CONST_DEM_INDICATOR_OFF) || (RTE_CONST_DEM_INDICATOR_OFF != 0U)
#    error "Enumeration constant <DEM_INDICATOR_OFF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INDICATOR_OFF (0U)
#   define DEM_INDICATOR_OFF (0U)
#  endif
#  if (defined RTE_CONST_DEM_INDICATOR_CONTINUOUS) || (defined DEM_INDICATOR_CONTINUOUS)
#   if (!defined RTE_CONST_DEM_INDICATOR_CONTINUOUS) || (RTE_CONST_DEM_INDICATOR_CONTINUOUS != 1U)
#    error "Enumeration constant <DEM_INDICATOR_CONTINUOUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INDICATOR_CONTINUOUS (1U)
#   define DEM_INDICATOR_CONTINUOUS (1U)
#  endif
#  if (defined RTE_CONST_DEM_INDICATOR_BLINKING) || (defined DEM_INDICATOR_BLINKING)
#   if (!defined RTE_CONST_DEM_INDICATOR_BLINKING) || (RTE_CONST_DEM_INDICATOR_BLINKING != 2U)
#    error "Enumeration constant <DEM_INDICATOR_BLINKING> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INDICATOR_BLINKING (2U)
#   define DEM_INDICATOR_BLINKING (2U)
#  endif
#  if (defined RTE_CONST_DEM_INDICATOR_BLINK_CONT) || (defined DEM_INDICATOR_BLINK_CONT)
#   if (!defined RTE_CONST_DEM_INDICATOR_BLINK_CONT) || (RTE_CONST_DEM_INDICATOR_BLINK_CONT != 3U)
#    error "Enumeration constant <DEM_INDICATOR_BLINK_CONT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INDICATOR_BLINK_CONT (3U)
#   define DEM_INDICATOR_BLINK_CONT (3U)
#  endif

#  define Rte_TypeDef_ID_FN_INQY
typedef uint16 ID_FN_INQY;
#  define ID_FN_INQY_LowerLimit (0U)
#  define ID_FN_INQY_UpperLimit (65535U)
#  define Rte_InvalidValue_ID_FN_INQY (65535U)
#  define InvalidValue_ID_FN_INQY (65535U)
#  if (defined RTE_CONST_Cx03EB_Grenzwerte_Schwenk_Links) || (defined Cx03EB_Grenzwerte_Schwenk_Links)
#   if (!defined RTE_CONST_Cx03EB_Grenzwerte_Schwenk_Links) || (RTE_CONST_Cx03EB_Grenzwerte_Schwenk_Links != 1003U)
#    error "Enumeration constant <Cx03EB_Grenzwerte_Schwenk_Links> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03EB_Grenzwerte_Schwenk_Links (1003U)
#   define Cx03EB_Grenzwerte_Schwenk_Links (1003U)
#  endif
#  if (defined RTE_CONST_Cx03EC_Grenzwerte_Schwenk_Rechts) || (defined Cx03EC_Grenzwerte_Schwenk_Rechts)
#   if (!defined RTE_CONST_Cx03EC_Grenzwerte_Schwenk_Rechts) || (RTE_CONST_Cx03EC_Grenzwerte_Schwenk_Rechts != 1004U)
#    error "Enumeration constant <Cx03EC_Grenzwerte_Schwenk_Rechts> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03EC_Grenzwerte_Schwenk_Rechts (1004U)
#   define Cx03EC_Grenzwerte_Schwenk_Rechts (1004U)
#  endif
#  if (defined RTE_CONST_Cx03F1_Status_Licht_Erweitert_CKM) || (defined Cx03F1_Status_Licht_Erweitert_CKM)
#   if (!defined RTE_CONST_Cx03F1_Status_Licht_Erweitert_CKM) || (RTE_CONST_Cx03F1_Status_Licht_Erweitert_CKM != 1009U)
#    error "Enumeration constant <Cx03F1_Status_Licht_Erweitert_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03F1_Status_Licht_Erweitert_CKM (1009U)
#   define Cx03F1_Status_Licht_Erweitert_CKM (1009U)
#  endif
#  if (defined RTE_CONST_Cx03F5_Status_Laderaumabdeckung_CKM) || (defined Cx03F5_Status_Laderaumabdeckung_CKM)
#   if (!defined RTE_CONST_Cx03F5_Status_Laderaumabdeckung_CKM) || (RTE_CONST_Cx03F5_Status_Laderaumabdeckung_CKM != 1013U)
#    error "Enumeration constant <Cx03F5_Status_Laderaumabdeckung_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03F5_Status_Laderaumabdeckung_CKM (1013U)
#   define Cx03F5_Status_Laderaumabdeckung_CKM (1013U)
#  endif
#  if (defined RTE_CONST_Cx0424_Status_Konfiguration_Kombi) || (defined Cx0424_Status_Konfiguration_Kombi)
#   if (!defined RTE_CONST_Cx0424_Status_Konfiguration_Kombi) || (RTE_CONST_Cx0424_Status_Konfiguration_Kombi != 1060U)
#    error "Enumeration constant <Cx0424_Status_Konfiguration_Kombi> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0424_Status_Konfiguration_Kombi (1060U)
#   define Cx0424_Status_Konfiguration_Kombi (1060U)
#  endif
#  if (defined RTE_CONST_Cx0427_Konfiguration_DSC) || (defined Cx0427_Konfiguration_DSC)
#   if (!defined RTE_CONST_Cx0427_Konfiguration_DSC) || (RTE_CONST_Cx0427_Konfiguration_DSC != 1063U)
#    error "Enumeration constant <Cx0427_Konfiguration_DSC> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0427_Konfiguration_DSC (1063U)
#   define Cx0427_Konfiguration_DSC (1063U)
#  endif
#  if (defined RTE_CONST_Cx042E_Status_M_Drive_2) || (defined Cx042E_Status_M_Drive_2)
#   if (!defined RTE_CONST_Cx042E_Status_M_Drive_2) || (RTE_CONST_Cx042E_Status_M_Drive_2 != 1070U)
#    error "Enumeration constant <Cx042E_Status_M_Drive_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx042E_Status_M_Drive_2 (1070U)
#   define Cx042E_Status_M_Drive_2 (1070U)
#  endif
#  if (defined RTE_CONST_Cx0434_Konfiguration_EPS) || (defined Cx0434_Konfiguration_EPS)
#   if (!defined RTE_CONST_Cx0434_Konfiguration_EPS) || (RTE_CONST_Cx0434_Konfiguration_EPS != 1076U)
#    error "Enumeration constant <Cx0434_Konfiguration_EPS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0434_Konfiguration_EPS (1076U)
#   define Cx0434_Konfiguration_EPS (1076U)
#  endif
#  if (defined RTE_CONST_Cx0435_Messung_Motoroel) || (defined Cx0435_Messung_Motoroel)
#   if (!defined RTE_CONST_Cx0435_Messung_Motoroel) || (RTE_CONST_Cx0435_Messung_Motoroel != 1077U)
#    error "Enumeration constant <Cx0435_Messung_Motoroel> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0435_Messung_Motoroel (1077U)
#   define Cx0435_Messung_Motoroel (1077U)
#  endif
#  if (defined RTE_CONST_Cx043F_Identifikationsnummer_Sensorcluster) || (defined Cx043F_Identifikationsnummer_Sensorcluster)
#   if (!defined RTE_CONST_Cx043F_Identifikationsnummer_Sensorcluster) || (RTE_CONST_Cx043F_Identifikationsnummer_Sensorcluster != 1087U)
#    error "Enumeration constant <Cx043F_Identifikationsnummer_Sensorcluster> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx043F_Identifikationsnummer_Sensorcluster (1087U)
#   define Cx043F_Identifikationsnummer_Sensorcluster (1087U)
#  endif
#  if (defined RTE_CONST_Cx00A1_Bedienung_Tasten_Entertainment) || (defined Cx00A1_Bedienung_Tasten_Entertainment)
#   if (!defined RTE_CONST_Cx00A1_Bedienung_Tasten_Entertainment) || (RTE_CONST_Cx00A1_Bedienung_Tasten_Entertainment != 161U)
#    error "Enumeration constant <Cx00A1_Bedienung_Tasten_Entertainment> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx00A1_Bedienung_Tasten_Entertainment (161U)
#   define Cx00A1_Bedienung_Tasten_Entertainment (161U)
#  endif
#  if (defined RTE_CONST_Cx00F6_Steuerung_Aussenspiegel) || (defined Cx00F6_Steuerung_Aussenspiegel)
#   if (!defined RTE_CONST_Cx00F6_Steuerung_Aussenspiegel) || (RTE_CONST_Cx00F6_Steuerung_Aussenspiegel != 246U)
#    error "Enumeration constant <Cx00F6_Steuerung_Aussenspiegel> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx00F6_Steuerung_Aussenspiegel (246U)
#   define Cx00F6_Steuerung_Aussenspiegel (246U)
#  endif
#  if (defined RTE_CONST_Cx01AA_Effekt_ErgoCommander) || (defined Cx01AA_Effekt_ErgoCommander)
#   if (!defined RTE_CONST_Cx01AA_Effekt_ErgoCommander) || (RTE_CONST_Cx01AA_Effekt_ErgoCommander != 426U)
#    error "Enumeration constant <Cx01AA_Effekt_ErgoCommander> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx01AA_Effekt_ErgoCommander (426U)
#   define Cx01AA_Effekt_ErgoCommander (426U)
#  endif
#  if (defined RTE_CONST_Cx01AE_Effekt_FondCommander) || (defined Cx01AE_Effekt_FondCommander)
#   if (!defined RTE_CONST_Cx01AE_Effekt_FondCommander) || (RTE_CONST_Cx01AE_Effekt_FondCommander != 430U)
#    error "Enumeration constant <Cx01AE_Effekt_FondCommander> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx01AE_Effekt_FondCommander (430U)
#   define Cx01AE_Effekt_FondCommander (430U)
#  endif
#  if (defined RTE_CONST_Cx020D_Position_Lenksaeule) || (defined Cx020D_Position_Lenksaeule)
#   if (!defined RTE_CONST_Cx020D_Position_Lenksaeule) || (RTE_CONST_Cx020D_Position_Lenksaeule != 525U)
#    error "Enumeration constant <Cx020D_Position_Lenksaeule> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx020D_Position_Lenksaeule (525U)
#   define Cx020D_Position_Lenksaeule (525U)
#  endif
#  if (defined RTE_CONST_Cx0226_Regensensor_Wischergeschwindigkeit) || (defined Cx0226_Regensensor_Wischergeschwindigkeit)
#   if (!defined RTE_CONST_Cx0226_Regensensor_Wischergeschwindigkeit) || (RTE_CONST_Cx0226_Regensensor_Wischergeschwindigkeit != 550U)
#    error "Enumeration constant <Cx0226_Regensensor_Wischergeschwindigkeit> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0226_Regensensor_Wischergeschwindigkeit (550U)
#   define Cx0226_Regensensor_Wischergeschwindigkeit (550U)
#  endif
#  if (defined RTE_CONST_Cx023A_Status_Funkschluessel) || (defined Cx023A_Status_Funkschluessel)
#   if (!defined RTE_CONST_Cx023A_Status_Funkschluessel) || (RTE_CONST_Cx023A_Status_Funkschluessel != 570U)
#    error "Enumeration constant <Cx023A_Status_Funkschluessel> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx023A_Status_Funkschluessel (570U)
#   define Cx023A_Status_Funkschluessel (570U)
#  endif
#  if (defined RTE_CONST_Cx0248_Status_Rueckfahrkamera) || (defined Cx0248_Status_Rueckfahrkamera)
#   if (!defined RTE_CONST_Cx0248_Status_Rueckfahrkamera) || (RTE_CONST_Cx0248_Status_Rueckfahrkamera != 584U)
#    error "Enumeration constant <Cx0248_Status_Rueckfahrkamera> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0248_Status_Rueckfahrkamera (584U)
#   define Cx0248_Status_Rueckfahrkamera (584U)
#  endif
#  if (defined RTE_CONST_Cx0252_Wischerstatus) || (defined Cx0252_Wischerstatus)
#   if (!defined RTE_CONST_Cx0252_Wischerstatus) || (RTE_CONST_Cx0252_Wischerstatus != 594U)
#    error "Enumeration constant <Cx0252_Wischerstatus> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0252_Wischerstatus (594U)
#   define Cx0252_Wischerstatus (594U)
#  endif
#  if (defined RTE_CONST_Cx0267_Bedienung_Tastgeber_Bedienelement_Front) || (defined Cx0267_Bedienung_Tastgeber_Bedienelement_Front)
#   if (!defined RTE_CONST_Cx0267_Bedienung_Tastgeber_Bedienelement_Front) || (RTE_CONST_Cx0267_Bedienung_Tastgeber_Bedienelement_Front != 615U)
#    error "Enumeration constant <Cx0267_Bedienung_Tastgeber_Bedienelement_Front> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0267_Bedienung_Tastgeber_Bedienelement_Front (615U)
#   define Cx0267_Bedienung_Tastgeber_Bedienelement_Front (615U)
#  endif
#  if (defined RTE_CONST_Cx027E_Status_Verdeck_Cabrio) || (defined Cx027E_Status_Verdeck_Cabrio)
#   if (!defined RTE_CONST_Cx027E_Status_Verdeck_Cabrio) || (RTE_CONST_Cx027E_Status_Verdeck_Cabrio != 638U)
#    error "Enumeration constant <Cx027E_Status_Verdeck_Cabrio> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx027E_Status_Verdeck_Cabrio (638U)
#   define Cx027E_Status_Verdeck_Cabrio (638U)
#  endif
#  if (defined RTE_CONST_CxFFFF_Signal_ungueltig) || (defined CxFFFF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxFFFF_Signal_ungueltig) || (RTE_CONST_CxFFFF_Signal_ungueltig != 65535U)
#    error "Enumeration constant <CxFFFF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFFFF_Signal_ungueltig (65535U)
#   define CxFFFF_Signal_ungueltig (65535U)
#  endif
#  if (defined RTE_CONST_Cx0291_Bedienung_Einheiten) || (defined Cx0291_Bedienung_Einheiten)
#   if (!defined RTE_CONST_Cx0291_Bedienung_Einheiten) || (RTE_CONST_Cx0291_Bedienung_Einheiten != 657U)
#    error "Enumeration constant <Cx0291_Bedienung_Einheiten> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0291_Bedienung_Einheiten (657U)
#   define Cx0291_Bedienung_Einheiten (657U)
#  endif
#  if (defined RTE_CONST_Cx02E6_Status_Klima_Luftverteilung_FA) || (defined Cx02E6_Status_Klima_Luftverteilung_FA)
#   if (!defined RTE_CONST_Cx02E6_Status_Klima_Luftverteilung_FA) || (RTE_CONST_Cx02E6_Status_Klima_Luftverteilung_FA != 742U)
#    error "Enumeration constant <Cx02E6_Status_Klima_Luftverteilung_FA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02E6_Status_Klima_Luftverteilung_FA (742U)
#   define Cx02E6_Status_Klima_Luftverteilung_FA (742U)
#  endif
#  if (defined RTE_CONST_Cx02EA_Status_Klima_Luftverteilung_BF) || (defined Cx02EA_Status_Klima_Luftverteilung_BF)
#   if (!defined RTE_CONST_Cx02EA_Status_Klima_Luftverteilung_BF) || (RTE_CONST_Cx02EA_Status_Klima_Luftverteilung_BF != 746U)
#    error "Enumeration constant <Cx02EA_Status_Klima_Luftverteilung_BF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02EA_Status_Klima_Luftverteilung_BF (746U)
#   define Cx02EA_Status_Klima_Luftverteilung_BF (746U)
#  endif
#  if (defined RTE_CONST_Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe) || (defined Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe)
#   if (!defined RTE_CONST_Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe) || (RTE_CONST_Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe != 748U)
#    error "Enumeration constant <Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe (748U)
#   define Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe (748U)
#  endif
#  if (defined RTE_CONST_Cx02EE_Status_Klima_Zusatzprogramme) || (defined Cx02EE_Status_Klima_Zusatzprogramme)
#   if (!defined RTE_CONST_Cx02EE_Status_Klima_Zusatzprogramme) || (RTE_CONST_Cx02EE_Status_Klima_Zusatzprogramme != 750U)
#    error "Enumeration constant <Cx02EE_Status_Klima_Zusatzprogramme> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02EE_Status_Klima_Zusatzprogramme (750U)
#   define Cx02EE_Status_Klima_Zusatzprogramme (750U)
#  endif
#  if (defined RTE_CONST_Cx02F0_Status_Klima_Standfunktionen) || (defined Cx02F0_Status_Klima_Standfunktionen)
#   if (!defined RTE_CONST_Cx02F0_Status_Klima_Standfunktionen) || (RTE_CONST_Cx02F0_Status_Klima_Standfunktionen != 752U)
#    error "Enumeration constant <Cx02F0_Status_Klima_Standfunktionen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02F0_Status_Klima_Standfunktionen (752U)
#   define Cx02F0_Status_Klima_Standfunktionen (752U)
#  endif
#  if (defined RTE_CONST_Cx02F7_Einheiten) || (defined Cx02F7_Einheiten)
#   if (!defined RTE_CONST_Cx02F7_Einheiten) || (RTE_CONST_Cx02F7_Einheiten != 759U)
#    error "Enumeration constant <Cx02F7_Einheiten> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02F7_Einheiten (759U)
#   define Cx02F7_Einheiten (759U)
#  endif
#  if (defined RTE_CONST_Cx02F8_Uhrzeit_Datum) || (defined Cx02F8_Uhrzeit_Datum)
#   if (!defined RTE_CONST_Cx02F8_Uhrzeit_Datum) || (RTE_CONST_Cx02F8_Uhrzeit_Datum != 760U)
#    error "Enumeration constant <Cx02F8_Uhrzeit_Datum> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02F8_Uhrzeit_Datum (760U)
#   define Cx02F8_Uhrzeit_Datum (760U)
#  endif
#  if (defined RTE_CONST_Cx0300_Status_RSE) || (defined Cx0300_Status_RSE)
#   if (!defined RTE_CONST_Cx0300_Status_RSE) || (RTE_CONST_Cx0300_Status_RSE != 768U)
#    error "Enumeration constant <Cx0300_Status_RSE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0300_Status_RSE (768U)
#   define Cx0300_Status_RSE (768U)
#  endif
#  if (defined RTE_CONST_Cx030F_Status_Service_Call_TeleX) || (defined Cx030F_Status_Service_Call_TeleX)
#   if (!defined RTE_CONST_Cx030F_Status_Service_Call_TeleX) || (RTE_CONST_Cx030F_Status_Service_Call_TeleX != 783U)
#    error "Enumeration constant <Cx030F_Status_Service_Call_TeleX> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx030F_Status_Service_Call_TeleX (783U)
#   define Cx030F_Status_Service_Call_TeleX (783U)
#  endif
#  if (defined RTE_CONST_Cx0313_Status_Service_Call_Teleservice) || (defined Cx0313_Status_Service_Call_Teleservice)
#   if (!defined RTE_CONST_Cx0313_Status_Service_Call_Teleservice) || (RTE_CONST_Cx0313_Status_Service_Call_Teleservice != 787U)
#    error "Enumeration constant <Cx0313_Status_Service_Call_Teleservice> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0313_Status_Service_Call_Teleservice (787U)
#   define Cx0313_Status_Service_Call_Teleservice (787U)
#  endif
#  if (defined RTE_CONST_Cx0332_Verbrauch_Information_Daten) || (defined Cx0332_Verbrauch_Information_Daten)
#   if (!defined RTE_CONST_Cx0332_Verbrauch_Information_Daten) || (RTE_CONST_Cx0332_Verbrauch_Information_Daten != 818U)
#    error "Enumeration constant <Cx0332_Verbrauch_Information_Daten> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0332_Verbrauch_Information_Daten (818U)
#   define Cx0332_Verbrauch_Information_Daten (818U)
#  endif
#  if (defined RTE_CONST_Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_) || (defined Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_)
#   if (!defined RTE_CONST_Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_) || (RTE_CONST_Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_ != 822U)
#    error "Enumeration constant <Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_ (822U)
#   define Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_ (822U)
#  endif
#  if (defined RTE_CONST_Cx033A_Status_Monitor_Front) || (defined Cx033A_Status_Monitor_Front)
#   if (!defined RTE_CONST_Cx033A_Status_Monitor_Front) || (RTE_CONST_Cx033A_Status_Monitor_Front != 826U)
#    error "Enumeration constant <Cx033A_Status_Monitor_Front> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx033A_Status_Monitor_Front (826U)
#   define Cx033A_Status_Monitor_Front (826U)
#  endif
#  if (defined RTE_CONST_Cx033C_Status_Monitor_Fond_1) || (defined Cx033C_Status_Monitor_Fond_1)
#   if (!defined RTE_CONST_Cx033C_Status_Monitor_Fond_1) || (RTE_CONST_Cx033C_Status_Monitor_Fond_1 != 828U)
#    error "Enumeration constant <Cx033C_Status_Monitor_Fond_1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx033C_Status_Monitor_Fond_1 (828U)
#   define Cx033C_Status_Monitor_Fond_1 (828U)
#  endif
#  if (defined RTE_CONST_Cx033E_Status_Monitor_Fond_2) || (defined Cx033E_Status_Monitor_Fond_2)
#   if (!defined RTE_CONST_Cx033E_Status_Monitor_Fond_2) || (RTE_CONST_Cx033E_Status_Monitor_Fond_2 != 830U)
#    error "Enumeration constant <Cx033E_Status_Monitor_Fond_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx033E_Status_Monitor_Fond_2 (830U)
#   define Cx033E_Status_Monitor_Fond_2 (830U)
#  endif
#  if (defined RTE_CONST_Cx0341_Status_Kartendaten) || (defined Cx0341_Status_Kartendaten)
#   if (!defined RTE_CONST_Cx0341_Status_Kartendaten) || (RTE_CONST_Cx0341_Status_Kartendaten != 833U)
#    error "Enumeration constant <Cx0341_Status_Kartendaten> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0341_Status_Kartendaten (833U)
#   define Cx0341_Status_Kartendaten (833U)
#  endif
#  if (defined RTE_CONST_Cx0349_Rohdaten_Fuellstand_Tank) || (defined Cx0349_Rohdaten_Fuellstand_Tank)
#   if (!defined RTE_CONST_Cx0349_Rohdaten_Fuellstand_Tank) || (RTE_CONST_Cx0349_Rohdaten_Fuellstand_Tank != 841U)
#    error "Enumeration constant <Cx0349_Rohdaten_Fuellstand_Tank> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0349_Rohdaten_Fuellstand_Tank (841U)
#   define Cx0349_Rohdaten_Fuellstand_Tank (841U)
#  endif
#  if (defined RTE_CONST_Cx035C_Status_Bordcomputer) || (defined Cx035C_Status_Bordcomputer)
#   if (!defined RTE_CONST_Cx035C_Status_Bordcomputer) || (RTE_CONST_Cx035C_Status_Bordcomputer != 860U)
#    error "Enumeration constant <Cx035C_Status_Bordcomputer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx035C_Status_Bordcomputer (860U)
#   define Cx035C_Status_Bordcomputer (860U)
#  endif
#  if (defined RTE_CONST_Cx0360_Daten_Bordcomputer__Fahrtbeginn_) || (defined Cx0360_Daten_Bordcomputer__Fahrtbeginn_)
#   if (!defined RTE_CONST_Cx0360_Daten_Bordcomputer__Fahrtbeginn_) || (RTE_CONST_Cx0360_Daten_Bordcomputer__Fahrtbeginn_ != 864U)
#    error "Enumeration constant <Cx0360_Daten_Bordcomputer__Fahrtbeginn_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0360_Daten_Bordcomputer__Fahrtbeginn_ (864U)
#   define Cx0360_Daten_Bordcomputer__Fahrtbeginn_ (864U)
#  endif
#  if (defined RTE_CONST_Cx0380_Fahrgestellnummer) || (defined Cx0380_Fahrgestellnummer)
#   if (!defined RTE_CONST_Cx0380_Fahrgestellnummer) || (RTE_CONST_Cx0380_Fahrgestellnummer != 896U)
#    error "Enumeration constant <Cx0380_Fahrgestellnummer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0380_Fahrgestellnummer (896U)
#   define Cx0380_Fahrgestellnummer (896U)
#  endif
#  if (defined RTE_CONST_Cx0381_Elektronischer_Motoroelmessstab) || (defined Cx0381_Elektronischer_Motoroelmessstab)
#   if (!defined RTE_CONST_Cx0381_Elektronischer_Motoroelmessstab) || (RTE_CONST_Cx0381_Elektronischer_Motoroelmessstab != 897U)
#    error "Enumeration constant <Cx0381_Elektronischer_Motoroelmessstab> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0381_Elektronischer_Motoroelmessstab (897U)
#   define Cx0381_Elektronischer_Motoroelmessstab (897U)
#  endif
#  if (defined RTE_CONST_Cx0382_Elektronischer_Motoroelmessstab_M) || (defined Cx0382_Elektronischer_Motoroelmessstab_M)
#   if (!defined RTE_CONST_Cx0382_Elektronischer_Motoroelmessstab_M) || (RTE_CONST_Cx0382_Elektronischer_Motoroelmessstab_M != 898U)
#    error "Enumeration constant <Cx0382_Elektronischer_Motoroelmessstab_M> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0382_Elektronischer_Motoroelmessstab_M (898U)
#   define Cx0382_Elektronischer_Motoroelmessstab_M (898U)
#  endif
#  if (defined RTE_CONST_Cx0388_Fahrzeugtyp) || (defined Cx0388_Fahrzeugtyp)
#   if (!defined RTE_CONST_Cx0388_Fahrzeugtyp) || (RTE_CONST_Cx0388_Fahrzeugtyp != 904U)
#    error "Enumeration constant <Cx0388_Fahrzeugtyp> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0388_Fahrzeugtyp (904U)
#   define Cx0388_Fahrzeugtyp (904U)
#  endif
#  if (defined RTE_CONST_Cx038E_Startdrehzahl) || (defined Cx038E_Startdrehzahl)
#   if (!defined RTE_CONST_Cx038E_Startdrehzahl) || (RTE_CONST_Cx038E_Startdrehzahl != 910U)
#    error "Enumeration constant <Cx038E_Startdrehzahl> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx038E_Startdrehzahl (910U)
#   define Cx038E_Startdrehzahl (910U)
#  endif
#  if (defined RTE_CONST_Cx0395_Codierung_Powermanagement) || (defined Cx0395_Codierung_Powermanagement)
#   if (!defined RTE_CONST_Cx0395_Codierung_Powermanagement) || (RTE_CONST_Cx0395_Codierung_Powermanagement != 917U)
#    error "Enumeration constant <Cx0395_Codierung_Powermanagement> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0395_Codierung_Powermanagement (917U)
#   define Cx0395_Codierung_Powermanagement (917U)
#  endif
#  if (defined RTE_CONST_Cx0399_Status_M_Drive) || (defined Cx0399_Status_M_Drive)
#   if (!defined RTE_CONST_Cx0399_Status_M_Drive) || (RTE_CONST_Cx0399_Status_M_Drive != 921U)
#    error "Enumeration constant <Cx0399_Status_M_Drive> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0399_Status_M_Drive (921U)
#   define Cx0399_Status_M_Drive (921U)
#  endif
#  if (defined RTE_CONST_Cx03A9_Status_Motorsteuerung_CKM) || (defined Cx03A9_Status_Motorsteuerung_CKM)
#   if (!defined RTE_CONST_Cx03A9_Status_Motorsteuerung_CKM) || (RTE_CONST_Cx03A9_Status_Motorsteuerung_CKM != 937U)
#    error "Enumeration constant <Cx03A9_Status_Motorsteuerung_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03A9_Status_Motorsteuerung_CKM (937U)
#   define Cx03A9_Status_Motorsteuerung_CKM (937U)
#  endif
#  if (defined RTE_CONST_Cx03AB_Status_Shiftlights_CKM) || (defined Cx03AB_Status_Shiftlights_CKM)
#   if (!defined RTE_CONST_Cx03AB_Status_Shiftlights_CKM) || (RTE_CONST_Cx03AB_Status_Shiftlights_CKM != 939U)
#    error "Enumeration constant <Cx03AB_Status_Shiftlights_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03AB_Status_Shiftlights_CKM (939U)
#   define Cx03AB_Status_Shiftlights_CKM (939U)
#  endif
#  if (defined RTE_CONST_Cx03B6_Position_Fensterheber_FAT) || (defined Cx03B6_Position_Fensterheber_FAT)
#   if (!defined RTE_CONST_Cx03B6_Position_Fensterheber_FAT) || (RTE_CONST_Cx03B6_Position_Fensterheber_FAT != 950U)
#    error "Enumeration constant <Cx03B6_Position_Fensterheber_FAT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03B6_Position_Fensterheber_FAT (950U)
#   define Cx03B6_Position_Fensterheber_FAT (950U)
#  endif
#  if (defined RTE_CONST_Cx03B7_Position_Fensterheber_FATH) || (defined Cx03B7_Position_Fensterheber_FATH)
#   if (!defined RTE_CONST_Cx03B7_Position_Fensterheber_FATH) || (RTE_CONST_Cx03B7_Position_Fensterheber_FATH != 951U)
#    error "Enumeration constant <Cx03B7_Position_Fensterheber_FATH> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03B7_Position_Fensterheber_FATH (951U)
#   define Cx03B7_Position_Fensterheber_FATH (951U)
#  endif
#  if (defined RTE_CONST_Cx03B8_Position_Fensterheber_BFT) || (defined Cx03B8_Position_Fensterheber_BFT)
#   if (!defined RTE_CONST_Cx03B8_Position_Fensterheber_BFT) || (RTE_CONST_Cx03B8_Position_Fensterheber_BFT != 952U)
#    error "Enumeration constant <Cx03B8_Position_Fensterheber_BFT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03B8_Position_Fensterheber_BFT (952U)
#   define Cx03B8_Position_Fensterheber_BFT (952U)
#  endif
#  if (defined RTE_CONST_Cx03B9_Position_Fensterheber_BFTH) || (defined Cx03B9_Position_Fensterheber_BFTH)
#   if (!defined RTE_CONST_Cx03B9_Position_Fensterheber_BFTH) || (RTE_CONST_Cx03B9_Position_Fensterheber_BFTH != 953U)
#    error "Enumeration constant <Cx03B9_Position_Fensterheber_BFTH> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03B9_Position_Fensterheber_BFTH (953U)
#   define Cx03B9_Position_Fensterheber_BFTH (953U)
#  endif
#  if (defined RTE_CONST_Cx03BA_Position_SHD) || (defined Cx03BA_Position_SHD)
#   if (!defined RTE_CONST_Cx03BA_Position_SHD) || (RTE_CONST_Cx03BA_Position_SHD != 954U)
#    error "Enumeration constant <Cx03BA_Position_SHD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03BA_Position_SHD (954U)
#   define Cx03BA_Position_SHD (954U)
#  endif
#  if (defined RTE_CONST_Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug) || (defined Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug)
#   if (!defined RTE_CONST_Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug) || (RTE_CONST_Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug != 956U)
#    error "Enumeration constant <Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug (956U)
#   define Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug (956U)
#  endif
#  if (defined RTE_CONST_Cx03BF_Position_Fensterheber_Heckscheibe) || (defined Cx03BF_Position_Fensterheber_Heckscheibe)
#   if (!defined RTE_CONST_Cx03BF_Position_Fensterheber_Heckscheibe) || (RTE_CONST_Cx03BF_Position_Fensterheber_Heckscheibe != 959U)
#    error "Enumeration constant <Cx03BF_Position_Fensterheber_Heckscheibe> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03BF_Position_Fensterheber_Heckscheibe (959U)
#   define Cx03BF_Position_Fensterheber_Heckscheibe (959U)
#  endif
#  if (defined RTE_CONST_Cx03C0_Konfiguration_FAS) || (defined Cx03C0_Konfiguration_FAS)
#   if (!defined RTE_CONST_Cx03C0_Konfiguration_FAS) || (RTE_CONST_Cx03C0_Konfiguration_FAS != 960U)
#    error "Enumeration constant <Cx03C0_Konfiguration_FAS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03C0_Konfiguration_FAS (960U)
#   define Cx03C0_Konfiguration_FAS (960U)
#  endif
#  if (defined RTE_CONST_Cx03C1_Konfiguration_BFS) || (defined Cx03C1_Konfiguration_BFS)
#   if (!defined RTE_CONST_Cx03C1_Konfiguration_BFS) || (RTE_CONST_Cx03C1_Konfiguration_BFS != 961U)
#    error "Enumeration constant <Cx03C1_Konfiguration_BFS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03C1_Konfiguration_BFS (961U)
#   define Cx03C1_Konfiguration_BFS (961U)
#  endif
#  if (defined RTE_CONST_Cx03C2_Konfiguration_FASH) || (defined Cx03C2_Konfiguration_FASH)
#   if (!defined RTE_CONST_Cx03C2_Konfiguration_FASH) || (RTE_CONST_Cx03C2_Konfiguration_FASH != 962U)
#    error "Enumeration constant <Cx03C2_Konfiguration_FASH> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03C2_Konfiguration_FASH (962U)
#   define Cx03C2_Konfiguration_FASH (962U)
#  endif
#  if (defined RTE_CONST_Cx03C3_Konfiguration_BFSH) || (defined Cx03C3_Konfiguration_BFSH)
#   if (!defined RTE_CONST_Cx03C3_Konfiguration_BFSH) || (RTE_CONST_Cx03C3_Konfiguration_BFSH != 963U)
#    error "Enumeration constant <Cx03C3_Konfiguration_BFSH> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03C3_Konfiguration_BFSH (963U)
#   define Cx03C3_Konfiguration_BFSH (963U)
#  endif
#  if (defined RTE_CONST_Cx03C4_Status_EDCK_CKM) || (defined Cx03C4_Status_EDCK_CKM)
#   if (!defined RTE_CONST_Cx03C4_Status_EDCK_CKM) || (RTE_CONST_Cx03C4_Status_EDCK_CKM != 964U)
#    error "Enumeration constant <Cx03C4_Status_EDCK_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03C4_Status_EDCK_CKM (964U)
#   define Cx03C4_Status_EDCK_CKM (964U)
#  endif
#  if (defined RTE_CONST_Cx03D0_Status_Spurverlassenswarnsystem_CKM) || (defined Cx03D0_Status_Spurverlassenswarnsystem_CKM)
#   if (!defined RTE_CONST_Cx03D0_Status_Spurverlassenswarnsystem_CKM) || (RTE_CONST_Cx03D0_Status_Spurverlassenswarnsystem_CKM != 976U)
#    error "Enumeration constant <Cx03D0_Status_Spurverlassenswarnsystem_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03D0_Status_Spurverlassenswarnsystem_CKM (976U)
#   define Cx03D0_Status_Spurverlassenswarnsystem_CKM (976U)
#  endif
#  if (defined RTE_CONST_Cx03D5_Status_Zentralverriegelung_CKM) || (defined Cx03D5_Status_Zentralverriegelung_CKM)
#   if (!defined RTE_CONST_Cx03D5_Status_Zentralverriegelung_CKM) || (RTE_CONST_Cx03D5_Status_Zentralverriegelung_CKM != 981U)
#    error "Enumeration constant <Cx03D5_Status_Zentralverriegelung_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03D5_Status_Zentralverriegelung_CKM (981U)
#   define Cx03D5_Status_Zentralverriegelung_CKM (981U)
#  endif
#  if (defined RTE_CONST_Cx03D7_Status_DWA_CKM) || (defined Cx03D7_Status_DWA_CKM)
#   if (!defined RTE_CONST_Cx03D7_Status_DWA_CKM) || (RTE_CONST_Cx03D7_Status_DWA_CKM != 983U)
#    error "Enumeration constant <Cx03D7_Status_DWA_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03D7_Status_DWA_CKM (983U)
#   define Cx03D7_Status_DWA_CKM (983U)
#  endif
#  if (defined RTE_CONST_Cx03D9_Status_RLS_CKM) || (defined Cx03D9_Status_RLS_CKM)
#   if (!defined RTE_CONST_Cx03D9_Status_RLS_CKM) || (RTE_CONST_Cx03D9_Status_RLS_CKM != 985U)
#    error "Enumeration constant <Cx03D9_Status_RLS_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03D9_Status_RLS_CKM (985U)
#   define Cx03D9_Status_RLS_CKM (985U)
#  endif
#  if (defined RTE_CONST_Cx03DB_Status_Memorypositionen_CKM) || (defined Cx03DB_Status_Memorypositionen_CKM)
#   if (!defined RTE_CONST_Cx03DB_Status_Memorypositionen_CKM) || (RTE_CONST_Cx03DB_Status_Memorypositionen_CKM != 987U)
#    error "Enumeration constant <Cx03DB_Status_Memorypositionen_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03DB_Status_Memorypositionen_CKM (987U)
#   define Cx03DB_Status_Memorypositionen_CKM (987U)
#  endif
#  if (defined RTE_CONST_Cx03DD_Status_Licht_CKM) || (defined Cx03DD_Status_Licht_CKM)
#   if (!defined RTE_CONST_Cx03DD_Status_Licht_CKM) || (RTE_CONST_Cx03DD_Status_Licht_CKM != 989U)
#    error "Enumeration constant <Cx03DD_Status_Licht_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03DD_Status_Licht_CKM (989U)
#   define Cx03DD_Status_Licht_CKM (989U)
#  endif
#  if (defined RTE_CONST_Cx03DF_Status_Klima_CKM) || (defined Cx03DF_Status_Klima_CKM)
#   if (!defined RTE_CONST_Cx03DF_Status_Klima_CKM) || (RTE_CONST_Cx03DF_Status_Klima_CKM != 991U)
#    error "Enumeration constant <Cx03DF_Status_Klima_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03DF_Status_Klima_CKM (991U)
#   define Cx03DF_Status_Klima_CKM (991U)
#  endif
#  if (defined RTE_CONST_Cx03E1_Status_ALC_CKM) || (defined Cx03E1_Status_ALC_CKM)
#   if (!defined RTE_CONST_Cx03E1_Status_ALC_CKM) || (RTE_CONST_Cx03E1_Status_ALC_CKM != 993U)
#    error "Enumeration constant <Cx03E1_Status_ALC_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03E1_Status_ALC_CKM (993U)
#   define Cx03E1_Status_ALC_CKM (993U)
#  endif
#  if (defined RTE_CONST_Cx03E3_Status_Heckklappe_CKM) || (defined Cx03E3_Status_Heckklappe_CKM)
#   if (!defined RTE_CONST_Cx03E3_Status_Heckklappe_CKM) || (RTE_CONST_Cx03E3_Status_Heckklappe_CKM != 995U)
#    error "Enumeration constant <Cx03E3_Status_Heckklappe_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03E3_Status_Heckklappe_CKM (995U)
#   define Cx03E3_Status_Heckklappe_CKM (995U)
#  endif
#  if (defined RTE_CONST_Cx03E5_Status_Rueckfahrkamera_CKM) || (defined Cx03E5_Status_Rueckfahrkamera_CKM)
#   if (!defined RTE_CONST_Cx03E5_Status_Rueckfahrkamera_CKM) || (RTE_CONST_Cx03E5_Status_Rueckfahrkamera_CKM != 997U)
#    error "Enumeration constant <Cx03E5_Status_Rueckfahrkamera_CKM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03E5_Status_Rueckfahrkamera_CKM (997U)
#   define Cx03E5_Status_Rueckfahrkamera_CKM (997U)
#  endif

#  define Rte_TypeDef_ID_TEMP_CPO_HET_MNG
typedef uint8 ID_TEMP_CPO_HET_MNG;
#  define ID_TEMP_CPO_HET_MNG_LowerLimit (0U)
#  define ID_TEMP_CPO_HET_MNG_UpperLimit (15U)
#  define Rte_InvalidValue_ID_TEMP_CPO_HET_MNG (15U)
#  define InvalidValue_ID_TEMP_CPO_HET_MNG (15U)
#  if (defined RTE_CONST_Cx1_EPS_Motortemperatur) || (defined Cx1_EPS_Motortemperatur)
#   if (!defined RTE_CONST_Cx1_EPS_Motortemperatur) || (RTE_CONST_Cx1_EPS_Motortemperatur != 1U)
#    error "Enumeration constant <Cx1_EPS_Motortemperatur> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_EPS_Motortemperatur (1U)
#   define Cx1_EPS_Motortemperatur (1U)
#  endif
#  if (defined RTE_CONST_CxD_Reserviert) || (defined CxD_Reserviert)
#   if (!defined RTE_CONST_CxD_Reserviert) || (RTE_CONST_CxD_Reserviert != 13U)
#    error "Enumeration constant <CxD_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Reserviert (13U)
#   define CxD_Reserviert (13U)
#  endif
#  if (defined RTE_CONST_CxE_Reserviert) || (defined CxE_Reserviert)
#   if (!defined RTE_CONST_CxE_Reserviert) || (RTE_CONST_CxE_Reserviert != 14U)
#    error "Enumeration constant <CxE_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Reserviert (14U)
#   define CxE_Reserviert (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_ST_DIAG_OBD_MUX_IMME
typedef uint8 ST_DIAG_OBD_MUX_IMME;
#  define ST_DIAG_OBD_MUX_IMME_LowerLimit (0U)
#  define ST_DIAG_OBD_MUX_IMME_UpperLimit (63U)
#  define Rte_InvalidValue_ST_DIAG_OBD_MUX_IMME (63U)
#  define InvalidValue_ST_DIAG_OBD_MUX_IMME (63U)
#  if (defined RTE_CONST_Cx01_Cal_ID__software_calibration_identification_) || (defined Cx01_Cal_ID__software_calibration_identification_)
#   if (!defined RTE_CONST_Cx01_Cal_ID__software_calibration_identification_) || (RTE_CONST_Cx01_Cal_ID__software_calibration_identification_ != 1U)
#    error "Enumeration constant <Cx01_Cal_ID__software_calibration_identification_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx01_Cal_ID__software_calibration_identification_ (1U)
#   define Cx01_Cal_ID__software_calibration_identification_ (1U)
#  endif
#  if (defined RTE_CONST_Cx02_CVN__software_calibration_verification_number_) || (defined Cx02_CVN__software_calibration_verification_number_)
#   if (!defined RTE_CONST_Cx02_CVN__software_calibration_verification_number_) || (RTE_CONST_Cx02_CVN__software_calibration_verification_number_ != 2U)
#    error "Enumeration constant <Cx02_CVN__software_calibration_verification_number_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02_CVN__software_calibration_verification_number_ (2U)
#   define Cx02_CVN__software_calibration_verification_number_ (2U)
#  endif
#  if (defined RTE_CONST_Cx3F_Ungueltig) || (defined Cx3F_Ungueltig)
#   if (!defined RTE_CONST_Cx3F_Ungueltig) || (RTE_CONST_Cx3F_Ungueltig != 63U)
#    error "Enumeration constant <Cx3F_Ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3F_Ungueltig (63U)
#   define Cx3F_Ungueltig (63U)
#  endif

#  define Rte_TypeDef_SYS_STATE_ENUM
typedef uint8 SYS_STATE_ENUM;
#  define SYS_STATE_ENUM_LowerLimit (0U)
#  define SYS_STATE_ENUM_UpperLimit (255U)
#  if (defined RTE_CONST_Cx00_DISABLE) || (defined Cx00_DISABLE)
#   if (!defined RTE_CONST_Cx00_DISABLE) || (RTE_CONST_Cx00_DISABLE != 0U)
#    error "Enumeration constant <Cx00_DISABLE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx00_DISABLE (0U)
#   define Cx00_DISABLE (0U)
#  endif
#  if (defined RTE_CONST_Cx01_OFF) || (defined Cx01_OFF)
#   if (!defined RTE_CONST_Cx01_OFF) || (RTE_CONST_Cx01_OFF != 1U)
#    error "Enumeration constant <Cx01_OFF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx01_OFF (1U)
#   define Cx01_OFF (1U)
#  endif
#  if (defined RTE_CONST_Cx02_RUN) || (defined Cx02_RUN)
#   if (!defined RTE_CONST_Cx02_RUN) || (RTE_CONST_Cx02_RUN != 2U)
#    error "Enumeration constant <Cx02_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02_RUN (2U)
#   define Cx02_RUN (2U)
#  endif
#  if (defined RTE_CONST_Cx03_WI) || (defined Cx03_WI)
#   if (!defined RTE_CONST_Cx03_WI) || (RTE_CONST_Cx03_WI != 3U)
#    error "Enumeration constant <Cx03_WI> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03_WI (3U)
#   define Cx03_WI (3U)
#  endif
#  if (defined RTE_CONST_Cx04_TRANSITION) || (defined Cx04_TRANSITION)
#   if (!defined RTE_CONST_Cx04_TRANSITION) || (RTE_CONST_Cx04_TRANSITION != 4U)
#    error "Enumeration constant <Cx04_TRANSITION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx04_TRANSITION (4U)
#   define Cx04_TRANSITION (4U)
#  endif

#  define Rte_TypeDef_TEMP_CPO_HET_MNG
typedef uint8 TEMP_CPO_HET_MNG;
#  define TEMP_CPO_HET_MNG_LowerLimit (0U)
#  define TEMP_CPO_HET_MNG_UpperLimit (255U)
#  define Rte_InvalidValue_TEMP_CPO_HET_MNG (255U)
#  define InvalidValue_TEMP_CPO_HET_MNG (255U)
#  if (defined RTE_CONST_CxFD_Reserviert) || (defined CxFD_Reserviert)
#   if (!defined RTE_CONST_CxFD_Reserviert) || (RTE_CONST_CxFD_Reserviert != 253U)
#    error "Enumeration constant <CxFD_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFD_Reserviert (253U)
#   define CxFD_Reserviert (253U)
#  endif
#  if (defined RTE_CONST_CxFE_Reserviert) || (defined CxFE_Reserviert)
#   if (!defined RTE_CONST_CxFE_Reserviert) || (RTE_CONST_CxFE_Reserviert != 254U)
#    error "Enumeration constant <CxFE_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFE_Reserviert (254U)
#   define CxFE_Reserviert (254U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#    error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#   define CxFF_Signal_unbefuellt (255U)
#  endif

#  define Rte_TypeDef_DIAG_OBD_DATA_Type
typedef UInt6 DIAG_OBD_DATA_Type[8];

#  define Rte_TypeDef_SG_ANFRAGE_DSC_Modul
typedef struct
{
  CD_0x08 ID2_0x08_Mx01_DSC_Modul;
  ID_FN_INQY ID_FN_INQY_DSC_Modul;
} SG_ANFRAGE_DSC_Modul;

#  define Rte_TypeDef_SG_ANFRAGE_SAS
typedef struct
{
  ID_FN_INQY ID_FN_INQY_SAS;
  CD_0x08 ID2_0x08_Mx01_SAS;
} SG_ANFRAGE_SAS;

#  define Rte_TypeDef_SG_ANFRAGE_ZGW
typedef struct
{
  ID_FN_INQY ID_FN_INQY_ZGW;
  CD_0x08 ID2_0x08_Mx01_ZGW;
} SG_ANFRAGE_ZGW;

#  define Rte_TypeDef_Edch_EventStatusIpduDataType
typedef struct
{
  DIAG_OBD_DATA_Type IpduData;
} Edch_EventStatusIpduDataType;

# endif


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
typedef uint8 Rte_ModeType_StaMd_Mode;

# define RTE_MODE_StaMd_Mode_DISABLE (0U)
# define RTE_MODE_StaMd_Mode_OFF (1U)
# define RTE_MODE_StaMd_Mode_OPERATE (2U)
# define RTE_MODE_StaMd_Mode_WARMINIT (3U)
# define RTE_TRANSITION_StaMd_Mode (4U)


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

# if (defined RTE_CONST_D_FALSE_CNT_LGC) || (defined D_FALSE_CNT_LGC)
#  if (!defined RTE_CONST_D_FALSE_CNT_LGC) || (RTE_CONST_D_FALSE_CNT_LGC != FALSE)
#   error "Constant value <D_FALSE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FALSE_CNT_LGC (FALSE)
#  define D_FALSE_CNT_LGC (FALSE)
# endif

# if (defined RTE_CONST_D_SUPPLYCURRINIT_AMP_F32) || (defined D_SUPPLYCURRINIT_AMP_F32)
#  if (!defined RTE_CONST_D_SUPPLYCURRINIT_AMP_F32) || (RTE_CONST_D_SUPPLYCURRINIT_AMP_F32 != 166.67F)
#   error "Constant value <D_SUPPLYCURRINIT_AMP_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SUPPLYCURRINIT_AMP_F32 (166.67F)
#  define D_SUPPLYCURRINIT_AMP_F32 (166.67F)
# endif

# if (defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (defined D_VECUMIN_VOLTS_F32)
#  if (!defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (RTE_CONST_D_VECUMIN_VOLTS_F32 != 5.0F)
#   error "Constant value <D_VECUMIN_VOLTS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_VECUMIN_VOLTS_F32 (5.0F)
#  define D_VECUMIN_VOLTS_F32 (5.0F)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif

# if (defined RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16) || (defined D_RACKTOVEHCNTRINVALID_CNT_U16)
#  if (!defined RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16) || (RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16 != 4095U)
#   error "Constant value <D_RACKTOVEHCNTRINVALID_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16 (4095U)
#  define D_RACKTOVEHCNTRINVALID_CNT_U16 (4095U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U8) || (defined D_ONE_CNT_U8)
#  if (!defined RTE_CONST_D_ONE_CNT_U8) || (RTE_CONST_D_ONE_CNT_U8 != 1U)
#   error "Constant value <D_ONE_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U8 (1U)
#  define D_ONE_CNT_U8 (1U)
# endif

# if defined C_RT_SG_AVL_FORC_GRD
#  error "Constant value <C_RT_SG_AVL_FORC_GRD> conflicts with an already defined symbol."
# else
#  define C_RT_SG_AVL_FORC_GRD (Rte_C_RT_SG_AVL_FORC_GRD)
# endif
extern CONST(RT_SG_AVL_FORC_GRD, RTE_CONST) Rte_C_RT_SG_AVL_FORC_GRD;

# if defined C_RT_SG_AVL_PO_EPS
#  error "Constant value <C_RT_SG_AVL_PO_EPS> conflicts with an already defined symbol."
# else
#  define C_RT_SG_AVL_PO_EPS (Rte_C_RT_SG_AVL_PO_EPS)
# endif
extern CONST(RT_SG_AVL_PO_EPS, RTE_CONST) Rte_C_RT_SG_AVL_PO_EPS;

# if defined C_RT_SG_AVL_STMOM_DV_ACT
#  error "Constant value <C_RT_SG_AVL_STMOM_DV_ACT> conflicts with an already defined symbol."
# else
#  define C_RT_SG_AVL_STMOM_DV_ACT (Rte_C_RT_SG_AVL_STMOM_DV_ACT)
# endif
extern CONST(RT_SG_AVL_STMOM_DV_ACT, RTE_CONST) Rte_C_RT_SG_AVL_STMOM_DV_ACT;

# if defined C_RT_SG_ST_EST_INIT
#  error "Constant value <C_RT_SG_ST_EST_INIT> conflicts with an already defined symbol."
# else
#  define C_RT_SG_ST_EST_INIT (Rte_C_RT_SG_ST_EST_INIT)
# endif
extern CONST(RT_SG_ST_EST, RTE_CONST) Rte_C_RT_SG_ST_EST_INIT;

# if defined C_RT_SG_SU_EPS_INIT
#  error "Constant value <C_RT_SG_SU_EPS_INIT> conflicts with an already defined symbol."
# else
#  define C_RT_SG_SU_EPS_INIT (Rte_C_RT_SG_SU_EPS_INIT)
# endif
extern CONST(RT_SG_SU_EPS, RTE_CONST) Rte_C_RT_SG_SU_EPS_INIT;

# if defined SG_DISP_CC_EPS_INIT
#  error "Constant value <SG_DISP_CC_EPS_INIT> conflicts with an already defined symbol."
# else
#  define SG_DISP_CC_EPS_INIT (Rte_SG_DISP_CC_EPS_INIT)
# endif
extern CONST(SG_DISP_CC_EPS, RTE_CONST) Rte_SG_DISP_CC_EPS_INIT;

# if defined SG_DT_EST_INIT
#  error "Constant value <SG_DT_EST_INIT> conflicts with an already defined symbol."
# else
#  define SG_DT_EST_INIT (Rte_SG_DT_EST_INIT)
# endif
extern CONST(SG_DT_EST, RTE_CONST) Rte_SG_DT_EST_INIT;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;

typedef struct
{
  UInt8 value;
} Rte_DE_UInt8;

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  UInt16 value;
} Rte_DE_UInt16;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_SrlComOutput2
{
  /* Data Handles section */
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_AVLFORCGRDTxConf_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_AVLSTMOMTxConf_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_CADASMSG_Cnt_lgc;
  P2VAR(Rte_DE_UInt8, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_CDISPCCEPS_Cnt_u08;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_CFACTORIF_Cnt_lgc;
    P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_CEVIIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_CHWANGLEIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_CHWTORQUEIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_CMTTORQUEIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_LimitPercentFiltered_Uls_f32;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_RacktoVehCntrOffset_Cnt_u16;
  P2VAR(Rte_DE_UInt8, TYPEDEF, RTE_AP_SRLCOMOUTPUT2_APPL_VAR) SrlComOutput2_Per1_RevOffsetState_Cnt_u08;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_SrlComOutput2, RTE_CONST, RTE_CONST) Rte_Inst_Ap_SrlComOutput2;
extern CONSTP2CONST(struct Rte_CDS_Ap_SrlComOutput, RTE_CONST, RTE_CONST) Rte_Inst_Ap_SrlComOutput;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1457552127
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComOutput/utp/contract/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1457552127
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
