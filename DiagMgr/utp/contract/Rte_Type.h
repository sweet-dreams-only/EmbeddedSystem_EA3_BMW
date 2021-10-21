/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Type.h
 *     Workspace:  C:/CMSynergy_Projects/DiagMgr/autosar
 *     SW-C Type:  Ap_DiagMgr
 *  Generated at:  Wed Jun 20 10:02:09 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
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

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Double
typedef float64 Double;
# define Double_LowerLimit ((Double)-DBL_MAX)
# define Double_UpperLimit ((Double)DBL_MAX)

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit ((Float)-FLT_MAX)
# define Float_UpperLimit ((Float)FLT_MAX)

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define SInt16_LowerLimit ((SInt16)-32768)
# define SInt16_UpperLimit ((SInt16)32767)

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;
# define SInt32_LowerLimit ((SInt32)-2147483648)
# define SInt32_UpperLimit ((SInt32)2147483647)

# define Rte_TypeDef_SInt8
typedef sint8 SInt8;
# define SInt8_LowerLimit ((SInt8)-128)
# define SInt8_UpperLimit ((SInt8)127)

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit ((UInt16)0u)
# define UInt16_UpperLimit ((UInt16)65535u)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit ((UInt32)0u)
# define UInt32_UpperLimit ((UInt32)4294967295u)

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;
# define UInt8_LowerLimit ((UInt8)0u)
# define UInt8_UpperLimit ((UInt8)255u)

# define Rte_TypeDef_ManufModeType
typedef uint8 ManufModeType;
# define ManufModeType_LowerLimit ((ManufModeType)0u)
# define ManufModeType_UpperLimit ((ManufModeType)2u)
# if (defined RTE_CONST_ProductionMode) || (defined ProductionMode)
#  if (!defined RTE_CONST_ProductionMode) || (RTE_CONST_ProductionMode != 0u)
#   error "Enumeration constant <ProductionMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ProductionMode (0u)
#  define ProductionMode ((ManufModeType)0u)
# endif
# if (defined RTE_CONST_ManufacturingMode) || (defined ManufacturingMode)
#  if (!defined RTE_CONST_ManufacturingMode) || (RTE_CONST_ManufacturingMode != 1u)
#   error "Enumeration constant <ManufacturingMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ManufacturingMode (1u)
#  define ManufacturingMode ((ManufModeType)1u)
# endif
# if (defined RTE_CONST_EngineeringMode) || (defined EngineeringMode)
#  if (!defined RTE_CONST_EngineeringMode) || (RTE_CONST_EngineeringMode != 2u)
#   error "Enumeration constant <EngineeringMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EngineeringMode (2u)
#  define EngineeringMode ((ManufModeType)2u)
# endif

# define Rte_TypeDef_NTCNumber
typedef uint16 NTCNumber;
# define NTCNumber_LowerLimit ((NTCNumber)0u)
# define NTCNumber_UpperLimit ((NTCNumber)511u)
# if (defined RTE_CONST_NTC_Num_FlashWrapperLgcFlt) || (defined NTC_Num_FlashWrapperLgcFlt)
#  if (!defined RTE_CONST_NTC_Num_FlashWrapperLgcFlt) || (RTE_CONST_NTC_Num_FlashWrapperLgcFlt != 1u)
#   error "Enumeration constant <NTC_Num_FlashWrapperLgcFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashWrapperLgcFlt (1u)
#  define NTC_Num_FlashWrapperLgcFlt ((NTCNumber)1u)
# endif
# if (defined RTE_CONST_NTC_Num_FlashECCCorr) || (defined NTC_Num_FlashECCCorr)
#  if (!defined RTE_CONST_NTC_Num_FlashECCCorr) || (RTE_CONST_NTC_Num_FlashECCCorr != 2u)
#   error "Enumeration constant <NTC_Num_FlashECCCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashECCCorr (2u)
#  define NTC_Num_FlashECCCorr ((NTCNumber)2u)
# endif
# if (defined RTE_CONST_NTC_Num_FlashECCMemFlt) || (defined NTC_Num_FlashECCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_FlashECCMemFlt) || (RTE_CONST_NTC_Num_FlashECCMemFlt != 3u)
#   error "Enumeration constant <NTC_Num_FlashECCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashECCMemFlt (3u)
#  define NTC_Num_FlashECCMemFlt ((NTCNumber)3u)
# endif
# if (defined RTE_CONST_NTC_Num_FlashCRCMemFault) || (defined NTC_Num_FlashCRCMemFault)
#  if (!defined RTE_CONST_NTC_Num_FlashCRCMemFault) || (RTE_CONST_NTC_Num_FlashCRCMemFault != 4u)
#   error "Enumeration constant <NTC_Num_FlashCRCMemFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_FlashCRCMemFault (4u)
#  define NTC_Num_FlashCRCMemFault ((NTCNumber)4u)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiag) || (defined NTC_Num_EEPROMDiag)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiag) || (RTE_CONST_NTC_Num_EEPROMDiag != 10u)
#   error "Enumeration constant <NTC_Num_EEPROMDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiag (10u)
#  define NTC_Num_EEPROMDiag ((NTCNumber)10u)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagMtrStr) || (defined NTC_Num_EEPROMDiagMtrStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagMtrStr) || (RTE_CONST_NTC_Num_EEPROMDiagMtrStr != 11u)
#   error "Enumeration constant <NTC_Num_EEPROMDiagMtrStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagMtrStr (11u)
#  define NTC_Num_EEPROMDiagMtrStr ((NTCNumber)11u)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagTrqSnrStr) || (defined NTC_Num_EEPROMDiagTrqSnrStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagTrqSnrStr) || (RTE_CONST_NTC_Num_EEPROMDiagTrqSnrStr != 12u)
#   error "Enumeration constant <NTC_Num_EEPROMDiagTrqSnrStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagTrqSnrStr (12u)
#  define NTC_Num_EEPROMDiagTrqSnrStr ((NTCNumber)12u)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr) || (defined NTC_Num_EEPROMDiagPosTrimStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr) || (RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr != 13u)
#   error "Enumeration constant <NTC_Num_EEPROMDiagPosTrimStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagPosTrimStr (13u)
#  define NTC_Num_EEPROMDiagPosTrimStr ((NTCNumber)13u)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMDiagPolarityStr) || (defined NTC_Num_EEPROMDiagPolarityStr)
#  if (!defined RTE_CONST_NTC_Num_EEPROMDiagPolarityStr) || (RTE_CONST_NTC_Num_EEPROMDiagPolarityStr != 14u)
#   error "Enumeration constant <NTC_Num_EEPROMDiagPolarityStr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMDiagPolarityStr (14u)
#  define NTC_Num_EEPROMDiagPolarityStr ((NTCNumber)14u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_GeneralFlt) || (defined NTC_Num_RAMDiag_GeneralFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_GeneralFlt) || (RTE_CONST_NTC_Num_RAMDiag_GeneralFlt != 16u)
#   error "Enumeration constant <NTC_Num_RAMDiag_GeneralFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_GeneralFlt (16u)
#  define NTC_Num_RAMDiag_GeneralFlt ((NTCNumber)16u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt) || (defined NTC_Num_RAMDiag_WrprLgcFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt) || (RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt != 17u)
#   error "Enumeration constant <NTC_Num_RAMDiag_WrprLgcFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_WrprLgcFlt (17u)
#  define NTC_Num_RAMDiag_WrprLgcFlt ((NTCNumber)17u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt) || (defined NTC_Num_RAMDiag_ECCCorrIndFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt) || (RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt != 18u)
#   error "Enumeration constant <NTC_Num_RAMDiag_ECCCorrIndFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
#  define NTC_Num_RAMDiag_ECCCorrIndFlt ((NTCNumber)18u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt) || (defined NTC_Num_RAMDiag_ECCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt) || (RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt != 19u)
#   error "Enumeration constant <NTC_Num_RAMDiag_ECCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ECCMemFlt (19u)
#  define NTC_Num_RAMDiag_ECCMemFlt ((NTCNumber)19u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt) || (defined NTC_Num_RAMDiag_CRCMemFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt) || (RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt != 20u)
#   error "Enumeration constant <NTC_Num_RAMDiag_CRCMemFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_CRCMemFlt (20u)
#  define NTC_Num_RAMDiag_CRCMemFlt ((NTCNumber)20u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt) || (defined NTC_Num_RAMDiag_VIMRamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt) || (RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt != 23u)
#   error "Enumeration constant <NTC_Num_RAMDiag_VIMRamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_VIMRamFlt (23u)
#  define NTC_Num_RAMDiag_VIMRamFlt ((NTCNumber)23u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt) || (defined NTC_Num_RAMDiag_NHET1RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt != 24u)
#   error "Enumeration constant <NTC_Num_RAMDiag_NHET1RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_NHET1RamFlt (24u)
#  define NTC_Num_RAMDiag_NHET1RamFlt ((NTCNumber)24u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt) || (defined NTC_Num_RAMDiag_NHET2RamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt) || (RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt != 25u)
#   error "Enumeration constant <NTC_Num_RAMDiag_NHET2RamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_NHET2RamFlt (25u)
#  define NTC_Num_RAMDiag_NHET2RamFlt ((NTCNumber)25u)
# endif
# if (defined RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt) || (defined NTC_Num_RAMDiag_ADCRamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt) || (RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt != 26u)
#   error "Enumeration constant <NTC_Num_RAMDiag_ADCRamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt (26u)
#  define NTC_Num_RAMDiag_ADCRamFlt ((NTCNumber)26u)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_RegVer) || (defined NTC_Num_CPU_RegVer)
#  if (!defined RTE_CONST_NTC_Num_CPU_RegVer) || (RTE_CONST_NTC_Num_CPU_RegVer != 32u)
#   error "Enumeration constant <NTC_Num_CPU_RegVer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_RegVer (32u)
#  define NTC_Num_CPU_RegVer ((NTCNumber)32u)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_CoreInitFlt) || (defined NTC_Num_CPU_CoreInitFlt)
#  if (!defined RTE_CONST_NTC_Num_CPU_CoreInitFlt) || (RTE_CONST_NTC_Num_CPU_CoreInitFlt != 33u)
#   error "Enumeration constant <NTC_Num_CPU_CoreInitFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_CoreInitFlt (33u)
#  define NTC_Num_CPU_CoreInitFlt ((NTCNumber)33u)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt) || (defined NTC_Num_CPU_CoreRunTimeFlt)
#  if (!defined RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt) || (RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt != 34u)
#   error "Enumeration constant <NTC_Num_CPU_CoreRunTimeFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_CoreRunTimeFlt (34u)
#  define NTC_Num_CPU_CoreRunTimeFlt ((NTCNumber)34u)
# endif
# if (defined RTE_CONST_NTC_Num_CPU_ClockMon) || (defined NTC_Num_CPU_ClockMon)
#  if (!defined RTE_CONST_NTC_Num_CPU_ClockMon) || (RTE_CONST_NTC_Num_CPU_ClockMon != 35u)
#   error "Enumeration constant <NTC_Num_CPU_ClockMon> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CPU_ClockMon (35u)
#  define NTC_Num_CPU_ClockMon ((NTCNumber)35u)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_InitDiag) || (defined NTC_Num_PropExeDiag_InitDiag)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_InitDiag) || (RTE_CONST_NTC_Num_PropExeDiag_InitDiag != 41u)
#   error "Enumeration constant <NTC_Num_PropExeDiag_InitDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_InitDiag (41u)
#  define NTC_Num_PropExeDiag_InitDiag ((NTCNumber)41u)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag) || (defined NTC_Num_PropExeDiag_RunTimeDiag)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag) || (RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag != 43u)
#   error "Enumeration constant <NTC_Num_PropExeDiag_RunTimeDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_RunTimeDiag (43u)
#  define NTC_Num_PropExeDiag_RunTimeDiag ((NTCNumber)43u)
# endif
# if (defined RTE_CONST_NTC_Num_PropExeDiag_COPTimeout) || (defined NTC_Num_PropExeDiag_COPTimeout)
#  if (!defined RTE_CONST_NTC_Num_PropExeDiag_COPTimeout) || (RTE_CONST_NTC_Num_PropExeDiag_COPTimeout != 44u)
#   error "Enumeration constant <NTC_Num_PropExeDiag_COPTimeout> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PropExeDiag_COPTimeout (44u)
#  define NTC_Num_PropExeDiag_COPTimeout ((NTCNumber)44u)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADC1Flt) || (defined NTC_Num_PerDiag_ADC1Flt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADC1Flt) || (RTE_CONST_NTC_Num_PerDiag_ADC1Flt != 50u)
#   error "Enumeration constant <NTC_Num_PerDiag_ADC1Flt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADC1Flt (50u)
#  define NTC_Num_PerDiag_ADC1Flt ((NTCNumber)50u)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADC2Flt) || (defined NTC_Num_PerDiag_ADC2Flt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADC2Flt) || (RTE_CONST_NTC_Num_PerDiag_ADC2Flt != 51u)
#   error "Enumeration constant <NTC_Num_PerDiag_ADC2Flt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADC2Flt (51u)
#  define NTC_Num_PerDiag_ADC2Flt ((NTCNumber)51u)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt) || (defined NTC_Num_PerDiag_ADCCrossChkFlt)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt) || (RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt != 52u)
#   error "Enumeration constant <NTC_Num_PerDiag_ADCCrossChkFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_ADCCrossChkFlt (52u)
#  define NTC_Num_PerDiag_ADCCrossChkFlt ((NTCNumber)52u)
# endif
# if (defined RTE_CONST_NTC_Num_PerDiag_IllegalAccess) || (defined NTC_Num_PerDiag_IllegalAccess)
#  if (!defined RTE_CONST_NTC_Num_PerDiag_IllegalAccess) || (RTE_CONST_NTC_Num_PerDiag_IllegalAccess != 53u)
#   error "Enumeration constant <NTC_Num_PerDiag_IllegalAccess> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PerDiag_IllegalAccess (53u)
#  define NTC_Num_PerDiag_IllegalAccess ((NTCNumber)53u)
# endif
# if (defined RTE_CONST_NTC_Num_TmpMonFunc) || (defined NTC_Num_TmpMonFunc)
#  if (!defined RTE_CONST_NTC_Num_TmpMonFunc) || (RTE_CONST_NTC_Num_TmpMonFunc != 64u)
#   error "Enumeration constant <NTC_Num_TmpMonFunc> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TmpMonFunc (64u)
#  define NTC_Num_TmpMonFunc ((NTCNumber)64u)
# endif
# if (defined RTE_CONST_NTC_Num_TmpMonRunTimeFlt) || (defined NTC_Num_TmpMonRunTimeFlt)
#  if (!defined RTE_CONST_NTC_Num_TmpMonRunTimeFlt) || (RTE_CONST_NTC_Num_TmpMonRunTimeFlt != 65u)
#   error "Enumeration constant <NTC_Num_TmpMonRunTimeFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TmpMonRunTimeFlt (65u)
#  define NTC_Num_TmpMonRunTimeFlt ((NTCNumber)65u)
# endif
# if (defined RTE_CONST_NTC_Num_PowerRelayInitFlt) || (defined NTC_Num_PowerRelayInitFlt)
#  if (!defined RTE_CONST_NTC_Num_PowerRelayInitFlt) || (RTE_CONST_NTC_Num_PowerRelayInitFlt != 66u)
#   error "Enumeration constant <NTC_Num_PowerRelayInitFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PowerRelayInitFlt (66u)
#  define NTC_Num_PowerRelayInitFlt ((NTCNumber)66u)
# endif
# if (defined RTE_CONST_NTC_Num_PrechargeFailure) || (defined NTC_Num_PrechargeFailure)
#  if (!defined RTE_CONST_NTC_Num_PrechargeFailure) || (RTE_CONST_NTC_Num_PrechargeFailure != 67u)
#   error "Enumeration constant <NTC_Num_PrechargeFailure> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PrechargeFailure (67u)
#  define NTC_Num_PrechargeFailure ((NTCNumber)67u)
# endif
# if (defined RTE_CONST_NTC_Num_PowerRelayRunFlt) || (defined NTC_Num_PowerRelayRunFlt)
#  if (!defined RTE_CONST_NTC_Num_PowerRelayRunFlt) || (RTE_CONST_NTC_Num_PowerRelayRunFlt != 68u)
#   error "Enumeration constant <NTC_Num_PowerRelayRunFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PowerRelayRunFlt (68u)
#  define NTC_Num_PowerRelayRunFlt ((NTCNumber)68u)
# endif
# if (defined RTE_CONST_NTC_Num_Thermistor) || (defined NTC_Num_Thermistor)
#  if (!defined RTE_CONST_NTC_Num_Thermistor) || (RTE_CONST_NTC_Num_Thermistor != 69u)
#   error "Enumeration constant <NTC_Num_Thermistor> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_Thermistor (69u)
#  define NTC_Num_Thermistor ((NTCNumber)69u)
# endif
# if (defined RTE_CONST_NTC_Num_RefSupplyVltg) || (defined NTC_Num_RefSupplyVltg)
#  if (!defined RTE_CONST_NTC_Num_RefSupplyVltg) || (RTE_CONST_NTC_Num_RefSupplyVltg != 70u)
#   error "Enumeration constant <NTC_Num_RefSupplyVltg> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RefSupplyVltg (70u)
#  define NTC_Num_RefSupplyVltg ((NTCNumber)70u)
# endif
# if (defined RTE_CONST_NTC_Num_TrcvrInterfaceFlt) || (defined NTC_Num_TrcvrInterfaceFlt)
#  if (!defined RTE_CONST_NTC_Num_TrcvrInterfaceFlt) || (RTE_CONST_NTC_Num_TrcvrInterfaceFlt != 71u)
#   error "Enumeration constant <NTC_Num_TrcvrInterfaceFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrcvrInterfaceFlt (71u)
#  define NTC_Num_TrcvrInterfaceFlt ((NTCNumber)71u)
# endif
# if (defined RTE_CONST_NTC_Num_GateDrvFlt) || (defined NTC_Num_GateDrvFlt)
#  if (!defined RTE_CONST_NTC_Num_GateDrvFlt) || (RTE_CONST_NTC_Num_GateDrvFlt != 77u)
#   error "Enumeration constant <NTC_Num_GateDrvFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_GateDrvFlt (77u)
#  define NTC_Num_GateDrvFlt ((NTCNumber)77u)
# endif
# if (defined RTE_CONST_NTC_Num_OnStateSingleFET) || (defined NTC_Num_OnStateSingleFET)
#  if (!defined RTE_CONST_NTC_Num_OnStateSingleFET) || (RTE_CONST_NTC_Num_OnStateSingleFET != 78u)
#   error "Enumeration constant <NTC_Num_OnStateSingleFET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OnStateSingleFET (78u)
#  define NTC_Num_OnStateSingleFET ((NTCNumber)78u)
# endif
# if (defined RTE_CONST_NTC_Num_OnStateMultiFET) || (defined NTC_Num_OnStateMultiFET)
#  if (!defined RTE_CONST_NTC_Num_OnStateMultiFET) || (RTE_CONST_NTC_Num_OnStateMultiFET != 79u)
#   error "Enumeration constant <NTC_Num_OnStateMultiFET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OnStateMultiFET (79u)
#  define NTC_Num_OnStateMultiFET ((NTCNumber)79u)
# endif
# if (defined RTE_CONST_NTC_Num_PhaseVoltageVerf) || (defined NTC_Num_PhaseVoltageVerf)
#  if (!defined RTE_CONST_NTC_Num_PhaseVoltageVerf) || (RTE_CONST_NTC_Num_PhaseVoltageVerf != 80u)
#   error "Enumeration constant <NTC_Num_PhaseVoltageVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PhaseVoltageVerf (80u)
#  define NTC_Num_PhaseVoltageVerf ((NTCNumber)80u)
# endif
# if (defined RTE_CONST_NTC_Num_PhaseDscnt) || (defined NTC_Num_PhaseDscnt)
#  if (!defined RTE_CONST_NTC_Num_PhaseDscnt) || (RTE_CONST_NTC_Num_PhaseDscnt != 81u)
#   error "Enumeration constant <NTC_Num_PhaseDscnt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PhaseDscnt (81u)
#  define NTC_Num_PhaseDscnt ((NTCNumber)81u)
# endif
# if (defined RTE_CONST_NTC_Num_DigPhaseVoltageVerf) || (defined NTC_Num_DigPhaseVoltageVerf)
#  if (!defined RTE_CONST_NTC_Num_DigPhaseVoltageVerf) || (RTE_CONST_NTC_Num_DigPhaseVoltageVerf != 82u)
#   error "Enumeration constant <NTC_Num_DigPhaseVoltageVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigPhaseVoltageVerf (82u)
#  define NTC_Num_DigPhaseVoltageVerf ((NTCNumber)82u)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeas1) || (defined NTC_Num_CurrentMeas1)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeas1) || (RTE_CONST_NTC_Num_CurrentMeas1 != 84u)
#   error "Enumeration constant <NTC_Num_CurrentMeas1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeas1 (84u)
#  define NTC_Num_CurrentMeas1 ((NTCNumber)84u)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeas2) || (defined NTC_Num_CurrentMeas2)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeas2) || (RTE_CONST_NTC_Num_CurrentMeas2 != 85u)
#   error "Enumeration constant <NTC_Num_CurrentMeas2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeas2 (85u)
#  define NTC_Num_CurrentMeas2 ((NTCNumber)85u)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentMeasCrossChk) || (defined NTC_Num_CurrentMeasCrossChk)
#  if (!defined RTE_CONST_NTC_Num_CurrentMeasCrossChk) || (RTE_CONST_NTC_Num_CurrentMeasCrossChk != 86u)
#   error "Enumeration constant <NTC_Num_CurrentMeasCrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentMeasCrossChk (86u)
#  define NTC_Num_CurrentMeasCrossChk ((NTCNumber)86u)
# endif
# if (defined RTE_CONST_NTC_Num_HwTrqSensor) || (defined NTC_Num_HwTrqSensor)
#  if (!defined RTE_CONST_NTC_Num_HwTrqSensor) || (RTE_CONST_NTC_Num_HwTrqSensor != 96u)
#   error "Enumeration constant <NTC_Num_HwTrqSensor> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HwTrqSensor (96u)
#  define NTC_Num_HwTrqSensor ((NTCNumber)96u)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorNotTrimmed) || (defined NTC_Num_TrqSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorNotTrimmed) || (RTE_CONST_NTC_Num_TrqSensorNotTrimmed != 97u)
#   error "Enumeration constant <NTC_Num_TrqSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorNotTrimmed (97u)
#  define NTC_Num_TrqSensorNotTrimmed ((NTCNumber)97u)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorTrimFlt) || (defined NTC_Num_TrqSensorTrimFlt)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorTrimFlt) || (RTE_CONST_NTC_Num_TrqSensorTrimFlt != 98u)
#   error "Enumeration constant <NTC_Num_TrqSensorTrimFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorTrimFlt (98u)
#  define NTC_Num_TrqSensorTrimFlt ((NTCNumber)98u)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorScaleNotSet) || (defined NTC_Num_TrqSensorScaleNotSet)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorScaleNotSet) || (RTE_CONST_NTC_Num_TrqSensorScaleNotSet != 99u)
#   error "Enumeration constant <NTC_Num_TrqSensorScaleNotSet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorScaleNotSet (99u)
#  define NTC_Num_TrqSensorScaleNotSet ((NTCNumber)99u)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorScaleInvalid) || (defined NTC_Num_TrqSensorScaleInvalid)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorScaleInvalid) || (RTE_CONST_NTC_Num_TrqSensorScaleInvalid != 100u)
#   error "Enumeration constant <NTC_Num_TrqSensorScaleInvalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorScaleInvalid (100u)
#  define NTC_Num_TrqSensorScaleInvalid ((NTCNumber)100u)
# endif
# if (defined RTE_CONST_NTC_Num_T1vsT2) || (defined NTC_Num_T1vsT2)
#  if (!defined RTE_CONST_NTC_Num_T1vsT2) || (RTE_CONST_NTC_Num_T1vsT2 != 101u)
#   error "Enumeration constant <NTC_Num_T1vsT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T1vsT2 (101u)
#  define NTC_Num_T1vsT2 ((NTCNumber)101u)
# endif
# if (defined RTE_CONST_NTC_Num_T1OutofRange) || (defined NTC_Num_T1OutofRange)
#  if (!defined RTE_CONST_NTC_Num_T1OutofRange) || (RTE_CONST_NTC_Num_T1OutofRange != 102u)
#   error "Enumeration constant <NTC_Num_T1OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T1OutofRange (102u)
#  define NTC_Num_T1OutofRange ((NTCNumber)102u)
# endif
# if (defined RTE_CONST_NTC_Num_T2OutofRange) || (defined NTC_Num_T2OutofRange)
#  if (!defined RTE_CONST_NTC_Num_T2OutofRange) || (RTE_CONST_NTC_Num_T2OutofRange != 103u)
#   error "Enumeration constant <NTC_Num_T2OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_T2OutofRange (103u)
#  define NTC_Num_T2OutofRange ((NTCNumber)103u)
# endif
# if (defined RTE_CONST_NTC_Num_DigT1vsT2) || (defined NTC_Num_DigT1vsT2)
#  if (!defined RTE_CONST_NTC_Num_DigT1vsT2) || (RTE_CONST_NTC_Num_DigT1vsT2 != 104u)
#   error "Enumeration constant <NTC_Num_DigT1vsT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT1vsT2 (104u)
#  define NTC_Num_DigT1vsT2 ((NTCNumber)104u)
# endif
# if (defined RTE_CONST_NTC_Num_DigT1OutofRange) || (defined NTC_Num_DigT1OutofRange)
#  if (!defined RTE_CONST_NTC_Num_DigT1OutofRange) || (RTE_CONST_NTC_Num_DigT1OutofRange != 105u)
#   error "Enumeration constant <NTC_Num_DigT1OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT1OutofRange (105u)
#  define NTC_Num_DigT1OutofRange ((NTCNumber)105u)
# endif
# if (defined RTE_CONST_NTC_Num_DigT2OutofRange) || (defined NTC_Num_DigT2OutofRange)
#  if (!defined RTE_CONST_NTC_Num_DigT2OutofRange) || (RTE_CONST_NTC_Num_DigT2OutofRange != 106u)
#   error "Enumeration constant <NTC_Num_DigT2OutofRange> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigT2OutofRange (106u)
#  define NTC_Num_DigT2OutofRange ((NTCNumber)106u)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorNotTrimmed) || (defined NTC_Num_HWASensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_HWASensorNotTrimmed) || (RTE_CONST_NTC_Num_HWASensorNotTrimmed != 107u)
#   error "Enumeration constant <NTC_Num_HWASensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorNotTrimmed (107u)
#  define NTC_Num_HWASensorNotTrimmed ((NTCNumber)107u)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorTrimNoAttempt) || (defined NTC_Num_HWASensorTrimNoAttempt)
#  if (!defined RTE_CONST_NTC_Num_HWASensorTrimNoAttempt) || (RTE_CONST_NTC_Num_HWASensorTrimNoAttempt != 108u)
#   error "Enumeration constant <NTC_Num_HWASensorTrimNoAttempt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorTrimNoAttempt (108u)
#  define NTC_Num_HWASensorTrimNoAttempt ((NTCNumber)108u)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorRel) || (defined NTC_Num_HWASensorRel)
#  if (!defined RTE_CONST_NTC_Num_HWASensorRel) || (RTE_CONST_NTC_Num_HWASensorRel != 110u)
#   error "Enumeration constant <NTC_Num_HWASensorRel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorRel (110u)
#  define NTC_Num_HWASensorRel ((NTCNumber)110u)
# endif
# if (defined RTE_CONST_NTC_Num_HWASensorAbs) || (defined NTC_Num_HWASensorAbs)
#  if (!defined RTE_CONST_NTC_Num_HWASensorAbs) || (RTE_CONST_NTC_Num_HWASensorAbs != 111u)
#   error "Enumeration constant <NTC_Num_HWASensorAbs> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWASensorAbs (111u)
#  define NTC_Num_HWASensorAbs ((NTCNumber)111u)
# endif
# if (defined RTE_CONST_NTC_Num_PriMSB_SinCosCorr) || (defined NTC_Num_PriMSB_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_PriMSB_SinCosCorr) || (RTE_CONST_NTC_Num_PriMSB_SinCosCorr != 112u)
#   error "Enumeration constant <NTC_Num_PriMSB_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PriMSB_SinCosCorr (112u)
#  define NTC_Num_PriMSB_SinCosCorr ((NTCNumber)112u)
# endif
# if (defined RTE_CONST_NTC_Num_SecMSB_SinCosCorr) || (defined NTC_Num_SecMSB_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_SecMSB_SinCosCorr) || (RTE_CONST_NTC_Num_SecMSB_SinCosCorr != 113u)
#   error "Enumeration constant <NTC_Num_SecMSB_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SecMSB_SinCosCorr (113u)
#  define NTC_Num_SecMSB_SinCosCorr ((NTCNumber)113u)
# endif
# if (defined RTE_CONST_NTC_Num_PriVsSec_SinCosCorr) || (defined NTC_Num_PriVsSec_SinCosCorr)
#  if (!defined RTE_CONST_NTC_Num_PriVsSec_SinCosCorr) || (RTE_CONST_NTC_Num_PriVsSec_SinCosCorr != 114u)
#   error "Enumeration constant <NTC_Num_PriVsSec_SinCosCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PriVsSec_SinCosCorr (114u)
#  define NTC_Num_PriVsSec_SinCosCorr ((NTCNumber)114u)
# endif
# if (defined RTE_CONST_NTC_Num_DigMSBFlt) || (defined NTC_Num_DigMSBFlt)
#  if (!defined RTE_CONST_NTC_Num_DigMSBFlt) || (RTE_CONST_NTC_Num_DigMSBFlt != 115u)
#   error "Enumeration constant <NTC_Num_DigMSBFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigMSBFlt (115u)
#  define NTC_Num_DigMSBFlt ((NTCNumber)115u)
# endif
# if (defined RTE_CONST_NTC_Num_MtrVelFlt) || (defined NTC_Num_MtrVelFlt)
#  if (!defined RTE_CONST_NTC_Num_MtrVelFlt) || (RTE_CONST_NTC_Num_MtrVelFlt != 116u)
#   error "Enumeration constant <NTC_Num_MtrVelFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MtrVelFlt (116u)
#  define NTC_Num_MtrVelFlt ((NTCNumber)116u)
# endif
# if (defined RTE_CONST_NTC_Num_HWAtoMtrAngleCorr) || (defined NTC_Num_HWAtoMtrAngleCorr)
#  if (!defined RTE_CONST_NTC_Num_HWAtoMtrAngleCorr) || (RTE_CONST_NTC_Num_HWAtoMtrAngleCorr != 117u)
#   error "Enumeration constant <NTC_Num_HWAtoMtrAngleCorr> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HWAtoMtrAngleCorr (117u)
#  define NTC_Num_HWAtoMtrAngleCorr ((NTCNumber)117u)
# endif
# if (defined RTE_CONST_NTC_Num_MtrSensorNotTrimmed) || (defined NTC_Num_MtrSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_MtrSensorNotTrimmed) || (RTE_CONST_NTC_Num_MtrSensorNotTrimmed != 121u)
#   error "Enumeration constant <NTC_Num_MtrSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MtrSensorNotTrimmed (121u)
#  define NTC_Num_MtrSensorNotTrimmed ((NTCNumber)121u)
# endif
# if (defined RTE_CONST_NTC_Num_TrqSensorRecoveryFlt) || (defined NTC_Num_TrqSensorRecoveryFlt)
#  if (!defined RTE_CONST_NTC_Num_TrqSensorRecoveryFlt) || (RTE_CONST_NTC_Num_TrqSensorRecoveryFlt != 122u)
#   error "Enumeration constant <NTC_Num_TrqSensorRecoveryFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TrqSensorRecoveryFlt (122u)
#  define NTC_Num_TrqSensorRecoveryFlt ((NTCNumber)122u)
# endif
# if (defined RTE_CONST_NTC_Num_DigTrqSensorScaleInvalid) || (defined NTC_Num_DigTrqSensorScaleInvalid)
#  if (!defined RTE_CONST_NTC_Num_DigTrqSensorScaleInvalid) || (RTE_CONST_NTC_Num_DigTrqSensorScaleInvalid != 123u)
#   error "Enumeration constant <NTC_Num_DigTrqSensorScaleInvalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigTrqSensorScaleInvalid (123u)
#  define NTC_Num_DigTrqSensorScaleInvalid ((NTCNumber)123u)
# endif
# if (defined RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed) || (defined NTC_Num_DigTrqSensorNotTrimmed)
#  if (!defined RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed) || (RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed != 124u)
#   error "Enumeration constant <NTC_Num_DigTrqSensorNotTrimmed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigTrqSensorNotTrimmed (124u)
#  define NTC_Num_DigTrqSensorNotTrimmed ((NTCNumber)124u)
# endif
# if (defined RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet) || (defined NTC_Num_DigTrqSensorScaleNotSet)
#  if (!defined RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet) || (RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet != 125u)
#   error "Enumeration constant <NTC_Num_DigTrqSensorScaleNotSet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DigTrqSensorScaleNotSet (125u)
#  define NTC_Num_DigTrqSensorScaleNotSet ((NTCNumber)125u)
# endif
# if (defined RTE_CONST_NTC_Num_AnaVsDigHwTrq) || (defined NTC_Num_AnaVsDigHwTrq)
#  if (!defined RTE_CONST_NTC_Num_AnaVsDigHwTrq) || (RTE_CONST_NTC_Num_AnaVsDigHwTrq != 126u)
#   error "Enumeration constant <NTC_Num_AnaVsDigHwTrq> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AnaVsDigHwTrq (126u)
#  define NTC_Num_AnaVsDigHwTrq ((NTCNumber)126u)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_PosLoss) || (defined NTC_Num_TurnCntr_PosLoss)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_PosLoss) || (RTE_CONST_NTC_Num_TurnCntr_PosLoss != 128u)
#   error "Enumeration constant <NTC_Num_TurnCntr_PosLoss> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_PosLoss (128u)
#  define NTC_Num_TurnCntr_PosLoss ((NTCNumber)128u)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_NonPosLoss) || (defined NTC_Num_TurnCntr_NonPosLoss)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_NonPosLoss) || (RTE_CONST_NTC_Num_TurnCntr_NonPosLoss != 129u)
#   error "Enumeration constant <NTC_Num_TurnCntr_NonPosLoss> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_NonPosLoss (129u)
#  define NTC_Num_TurnCntr_NonPosLoss ((NTCNumber)129u)
# endif
# if (defined RTE_CONST_NTC_Num_KinematicIntDiag) || (defined NTC_Num_KinematicIntDiag)
#  if (!defined RTE_CONST_NTC_Num_KinematicIntDiag) || (RTE_CONST_NTC_Num_KinematicIntDiag != 144u)
#   error "Enumeration constant <NTC_Num_KinematicIntDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_KinematicIntDiag (144u)
#  define NTC_Num_KinematicIntDiag ((NTCNumber)144u)
# endif
# if (defined RTE_CONST_NTC_Num_HighFriction) || (defined NTC_Num_HighFriction)
#  if (!defined RTE_CONST_NTC_Num_HighFriction) || (RTE_CONST_NTC_Num_HighFriction != 145u)
#   error "Enumeration constant <NTC_Num_HighFriction> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_HighFriction (145u)
#  define NTC_Num_HighFriction ((NTCNumber)145u)
# endif
# if (defined RTE_CONST_NTC_Num_DutyCycleExceeded) || (defined NTC_Num_DutyCycleExceeded)
#  if (!defined RTE_CONST_NTC_Num_DutyCycleExceeded) || (RTE_CONST_NTC_Num_DutyCycleExceeded != 148u)
#   error "Enumeration constant <NTC_Num_DutyCycleExceeded> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DutyCycleExceeded (148u)
#  define NTC_Num_DutyCycleExceeded ((NTCNumber)148u)
# endif
# if (defined RTE_CONST_NTC_Num_AbsTempThermLimit) || (defined NTC_Num_AbsTempThermLimit)
#  if (!defined RTE_CONST_NTC_Num_AbsTempThermLimit) || (RTE_CONST_NTC_Num_AbsTempThermLimit != 149u)
#   error "Enumeration constant <NTC_Num_AbsTempThermLimit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_AbsTempThermLimit (149u)
#  define NTC_Num_AbsTempThermLimit ((NTCNumber)149u)
# endif
# if (defined RTE_CONST_NTC_Num_LatchActive) || (defined NTC_Num_LatchActive)
#  if (!defined RTE_CONST_NTC_Num_LatchActive) || (RTE_CONST_NTC_Num_LatchActive != 160u)
#   error "Enumeration constant <NTC_Num_LatchActive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LatchActive (160u)
#  define NTC_Num_LatchActive ((NTCNumber)160u)
# endif
# if (defined RTE_CONST_NTC_Num_OpTrqVsHwTrq) || (defined NTC_Num_OpTrqVsHwTrq)
#  if (!defined RTE_CONST_NTC_Num_OpTrqVsHwTrq) || (RTE_CONST_NTC_Num_OpTrqVsHwTrq != 168u)
#   error "Enumeration constant <NTC_Num_OpTrqVsHwTrq> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OpTrqVsHwTrq (168u)
#  define NTC_Num_OpTrqVsHwTrq ((NTCNumber)168u)
# endif
# if (defined RTE_CONST_NTC_Num_CurrentReas) || (defined NTC_Num_CurrentReas)
#  if (!defined RTE_CONST_NTC_Num_CurrentReas) || (RTE_CONST_NTC_Num_CurrentReas != 169u)
#   error "Enumeration constant <NTC_Num_CurrentReas> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CurrentReas (169u)
#  define NTC_Num_CurrentReas ((NTCNumber)169u)
# endif
# if (defined RTE_CONST_NTC_Num_ExVoltageLow) || (defined NTC_Num_ExVoltageLow)
#  if (!defined RTE_CONST_NTC_Num_ExVoltageLow) || (RTE_CONST_NTC_Num_ExVoltageLow != 176u)
#   error "Enumeration constant <NTC_Num_ExVoltageLow> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ExVoltageLow (176u)
#  define NTC_Num_ExVoltageLow ((NTCNumber)176u)
# endif
# if (defined RTE_CONST_NTC_Num_ReducedAsstLowVoltage) || (defined NTC_Num_ReducedAsstLowVoltage)
#  if (!defined RTE_CONST_NTC_Num_ReducedAsstLowVoltage) || (RTE_CONST_NTC_Num_ReducedAsstLowVoltage != 177u)
#   error "Enumeration constant <NTC_Num_ReducedAsstLowVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ReducedAsstLowVoltage (177u)
#  define NTC_Num_ReducedAsstLowVoltage ((NTCNumber)177u)
# endif
# if (defined RTE_CONST_NTC_Num_OpVoltage) || (defined NTC_Num_OpVoltage)
#  if (!defined RTE_CONST_NTC_Num_OpVoltage) || (RTE_CONST_NTC_Num_OpVoltage != 178u)
#   error "Enumeration constant <NTC_Num_OpVoltage> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_OpVoltage (178u)
#  define NTC_Num_OpVoltage ((NTCNumber)178u)
# endif
# if (defined RTE_CONST_NTC_Num_IgnConfDiag) || (defined NTC_Num_IgnConfDiag)
#  if (!defined RTE_CONST_NTC_Num_IgnConfDiag) || (RTE_CONST_NTC_Num_IgnConfDiag != 179u)
#   error "Enumeration constant <NTC_Num_IgnConfDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IgnConfDiag (179u)
#  define NTC_Num_IgnConfDiag ((NTCNumber)179u)
# endif
# if (defined RTE_CONST_NTC_Num_ExVoltageHigh) || (defined NTC_Num_ExVoltageHigh)
#  if (!defined RTE_CONST_NTC_Num_ExVoltageHigh) || (RTE_CONST_NTC_Num_ExVoltageHigh != 180u)
#   error "Enumeration constant <NTC_Num_ExVoltageHigh> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ExVoltageHigh (180u)
#  define NTC_Num_ExVoltageHigh ((NTCNumber)180u)
# endif
# if (defined RTE_CONST_NTC_Num_EEPROMCloseFailed) || (defined NTC_Num_EEPROMCloseFailed)
#  if (!defined RTE_CONST_NTC_Num_EEPROMCloseFailed) || (RTE_CONST_NTC_Num_EEPROMCloseFailed != 191u)
#   error "Enumeration constant <NTC_Num_EEPROMCloseFailed> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EEPROMCloseFailed (191u)
#  define NTC_Num_EEPROMCloseFailed ((NTCNumber)191u)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath1CrossChk) || (defined NTC_Num_SigPath1CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath1CrossChk) || (RTE_CONST_NTC_Num_SigPath1CrossChk != 192u)
#   error "Enumeration constant <NTC_Num_SigPath1CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath1CrossChk (192u)
#  define NTC_Num_SigPath1CrossChk ((NTCNumber)192u)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath2CrossChk) || (defined NTC_Num_SigPath2CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath2CrossChk) || (RTE_CONST_NTC_Num_SigPath2CrossChk != 193u)
#   error "Enumeration constant <NTC_Num_SigPath2CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath2CrossChk (193u)
#  define NTC_Num_SigPath2CrossChk ((NTCNumber)193u)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath3CrossChk) || (defined NTC_Num_SigPath3CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath3CrossChk) || (RTE_CONST_NTC_Num_SigPath3CrossChk != 194u)
#   error "Enumeration constant <NTC_Num_SigPath3CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath3CrossChk (194u)
#  define NTC_Num_SigPath3CrossChk ((NTCNumber)194u)
# endif
# if (defined RTE_CONST_NTC_Num_SigPath4CrossChk) || (defined NTC_Num_SigPath4CrossChk)
#  if (!defined RTE_CONST_NTC_Num_SigPath4CrossChk) || (RTE_CONST_NTC_Num_SigPath4CrossChk != 195u)
#   error "Enumeration constant <NTC_Num_SigPath4CrossChk> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SigPath4CrossChk (195u)
#  define NTC_Num_SigPath4CrossChk ((NTCNumber)195u)
# endif
# if (defined RTE_CONST_NTC_Num_WhlImbAlgFlt) || (defined NTC_Num_WhlImbAlgFlt)
#  if (!defined RTE_CONST_NTC_Num_WhlImbAlgFlt) || (RTE_CONST_NTC_Num_WhlImbAlgFlt != 224u)
#   error "Enumeration constant <NTC_Num_WhlImbAlgFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_WhlImbAlgFlt (224u)
#  define NTC_Num_WhlImbAlgFlt ((NTCNumber)224u)
# endif
# if (defined RTE_CONST_NTC_Num_PAHwVelFlt) || (defined NTC_Num_PAHwVelFlt)
#  if (!defined RTE_CONST_NTC_Num_PAHwVelFlt) || (RTE_CONST_NTC_Num_PAHwVelFlt != 225u)
#   error "Enumeration constant <NTC_Num_PAHwVelFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PAHwVelFlt (225u)
#  define NTC_Num_PAHwVelFlt ((NTCNumber)225u)
# endif
# if (defined RTE_CONST_NTC_Num_BusOffCh1) || (defined NTC_Num_BusOffCh1)
#  if (!defined RTE_CONST_NTC_Num_BusOffCh1) || (RTE_CONST_NTC_Num_BusOffCh1 != 256u)
#   error "Enumeration constant <NTC_Num_BusOffCh1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BusOffCh1 (256u)
#  define NTC_Num_BusOffCh1 ((NTCNumber)256u)
# endif
# if (defined RTE_CONST_NTC_Num_BusOffCh2) || (defined NTC_Num_BusOffCh2)
#  if (!defined RTE_CONST_NTC_Num_BusOffCh2) || (RTE_CONST_NTC_Num_BusOffCh2 != 272u)
#   error "Enumeration constant <NTC_Num_BusOffCh2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_BusOffCh2 (272u)
#  define NTC_Num_BusOffCh2 ((NTCNumber)272u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_M) || (defined NTC_Num_InvalidMsg_M)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_M) || (RTE_CONST_NTC_Num_InvalidMsg_M != 288u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_M (288u)
#  define NTC_Num_InvalidMsg_M ((NTCNumber)288u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_M) || (defined NTC_Num_MissingMsg_M)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_M) || (RTE_CONST_NTC_Num_MissingMsg_M != 289u)
#   error "Enumeration constant <NTC_Num_MissingMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_M (289u)
#  define NTC_Num_MissingMsg_M ((NTCNumber)289u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_M) || (defined NTC_Num_CRCFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_M) || (RTE_CONST_NTC_Num_CRCFltMsg_M != 290u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_M (290u)
#  define NTC_Num_CRCFltMsg_M ((NTCNumber)290u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_M) || (defined NTC_Num_PgrsCntFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_M) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_M != 291u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_M (291u)
#  define NTC_Num_PgrsCntFltMsg_M ((NTCNumber)291u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_M) || (defined NTC_Num_DataRngFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_M) || (RTE_CONST_NTC_Num_DataRngFltMsg_M != 292u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_M (292u)
#  define NTC_Num_DataRngFltMsg_M ((NTCNumber)292u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_M) || (defined NTC_Num_DataRateFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_M) || (RTE_CONST_NTC_Num_DataRateFltMsg_M != 293u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_M (293u)
#  define NTC_Num_DataRateFltMsg_M ((NTCNumber)293u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_M) || (defined NTC_Num_DataOtherFltMsg_M)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_M) || (RTE_CONST_NTC_Num_DataOtherFltMsg_M != 294u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_M (294u)
#  define NTC_Num_DataOtherFltMsg_M ((NTCNumber)294u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_N) || (defined NTC_Num_InvalidMsg_N)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_N) || (RTE_CONST_NTC_Num_InvalidMsg_N != 296u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_N (296u)
#  define NTC_Num_InvalidMsg_N ((NTCNumber)296u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_N) || (defined NTC_Num_MissingMsg_N)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_N) || (RTE_CONST_NTC_Num_MissingMsg_N != 297u)
#   error "Enumeration constant <NTC_Num_MissingMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_N (297u)
#  define NTC_Num_MissingMsg_N ((NTCNumber)297u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_N) || (defined NTC_Num_CRCFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_N) || (RTE_CONST_NTC_Num_CRCFltMsg_N != 298u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_N (298u)
#  define NTC_Num_CRCFltMsg_N ((NTCNumber)298u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_N) || (defined NTC_Num_PgrsCntFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_N) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_N != 299u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_N (299u)
#  define NTC_Num_PgrsCntFltMsg_N ((NTCNumber)299u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_N) || (defined NTC_Num_DataRngFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_N) || (RTE_CONST_NTC_Num_DataRngFltMsg_N != 300u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_N (300u)
#  define NTC_Num_DataRngFltMsg_N ((NTCNumber)300u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_N) || (defined NTC_Num_DataRateFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_N) || (RTE_CONST_NTC_Num_DataRateFltMsg_N != 301u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_N (301u)
#  define NTC_Num_DataRateFltMsg_N ((NTCNumber)301u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_N) || (defined NTC_Num_DataOtherFltMsg_N)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_N) || (RTE_CONST_NTC_Num_DataOtherFltMsg_N != 302u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_N> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_N (302u)
#  define NTC_Num_DataOtherFltMsg_N ((NTCNumber)302u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_O) || (defined NTC_Num_InvalidMsg_O)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_O) || (RTE_CONST_NTC_Num_InvalidMsg_O != 304u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_O (304u)
#  define NTC_Num_InvalidMsg_O ((NTCNumber)304u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_O) || (defined NTC_Num_MissingMsg_O)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_O) || (RTE_CONST_NTC_Num_MissingMsg_O != 305u)
#   error "Enumeration constant <NTC_Num_MissingMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_O (305u)
#  define NTC_Num_MissingMsg_O ((NTCNumber)305u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_O) || (defined NTC_Num_CRCFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_O) || (RTE_CONST_NTC_Num_CRCFltMsg_O != 306u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_O (306u)
#  define NTC_Num_CRCFltMsg_O ((NTCNumber)306u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_O) || (defined NTC_Num_PgrsCntFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_O) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_O != 307u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_O (307u)
#  define NTC_Num_PgrsCntFltMsg_O ((NTCNumber)307u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_O) || (defined NTC_Num_DataRngFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_O) || (RTE_CONST_NTC_Num_DataRngFltMsg_O != 308u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_O (308u)
#  define NTC_Num_DataRngFltMsg_O ((NTCNumber)308u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_O) || (defined NTC_Num_DataRateFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_O) || (RTE_CONST_NTC_Num_DataRateFltMsg_O != 309u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_O (309u)
#  define NTC_Num_DataRateFltMsg_O ((NTCNumber)309u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_O) || (defined NTC_Num_DataOtherFltMsg_O)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_O) || (RTE_CONST_NTC_Num_DataOtherFltMsg_O != 310u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_O> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_O (310u)
#  define NTC_Num_DataOtherFltMsg_O ((NTCNumber)310u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_P) || (defined NTC_Num_InvalidMsg_P)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_P) || (RTE_CONST_NTC_Num_InvalidMsg_P != 312u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_P (312u)
#  define NTC_Num_InvalidMsg_P ((NTCNumber)312u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_P) || (defined NTC_Num_MissingMsg_P)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_P) || (RTE_CONST_NTC_Num_MissingMsg_P != 313u)
#   error "Enumeration constant <NTC_Num_MissingMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_P (313u)
#  define NTC_Num_MissingMsg_P ((NTCNumber)313u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_P) || (defined NTC_Num_CRCFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_P) || (RTE_CONST_NTC_Num_CRCFltMsg_P != 314u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_P (314u)
#  define NTC_Num_CRCFltMsg_P ((NTCNumber)314u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_P) || (defined NTC_Num_PgrsCntFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_P) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_P != 315u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_P (315u)
#  define NTC_Num_PgrsCntFltMsg_P ((NTCNumber)315u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_P) || (defined NTC_Num_DataRngFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_P) || (RTE_CONST_NTC_Num_DataRngFltMsg_P != 316u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_P (316u)
#  define NTC_Num_DataRngFltMsg_P ((NTCNumber)316u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_P) || (defined NTC_Num_DataRateFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_P) || (RTE_CONST_NTC_Num_DataRateFltMsg_P != 317u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_P (317u)
#  define NTC_Num_DataRateFltMsg_P ((NTCNumber)317u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_P) || (defined NTC_Num_DataOtherFltMsg_P)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_P) || (RTE_CONST_NTC_Num_DataOtherFltMsg_P != 318u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_P> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_P (318u)
#  define NTC_Num_DataOtherFltMsg_P ((NTCNumber)318u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Q) || (defined NTC_Num_InvalidMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Q) || (RTE_CONST_NTC_Num_InvalidMsg_Q != 320u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Q (320u)
#  define NTC_Num_InvalidMsg_Q ((NTCNumber)320u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Q) || (defined NTC_Num_MissingMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Q) || (RTE_CONST_NTC_Num_MissingMsg_Q != 321u)
#   error "Enumeration constant <NTC_Num_MissingMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Q (321u)
#  define NTC_Num_MissingMsg_Q ((NTCNumber)321u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Q) || (defined NTC_Num_CRCFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Q) || (RTE_CONST_NTC_Num_CRCFltMsg_Q != 322u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Q (322u)
#  define NTC_Num_CRCFltMsg_Q ((NTCNumber)322u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Q) || (defined NTC_Num_PgrsCntFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Q) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Q != 323u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Q (323u)
#  define NTC_Num_PgrsCntFltMsg_Q ((NTCNumber)323u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Q) || (defined NTC_Num_DataRngFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Q) || (RTE_CONST_NTC_Num_DataRngFltMsg_Q != 324u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Q (324u)
#  define NTC_Num_DataRngFltMsg_Q ((NTCNumber)324u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Q) || (defined NTC_Num_DataRateFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Q) || (RTE_CONST_NTC_Num_DataRateFltMsg_Q != 325u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Q (325u)
#  define NTC_Num_DataRateFltMsg_Q ((NTCNumber)325u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Q) || (defined NTC_Num_DataOtherFltMsg_Q)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Q) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Q != 326u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Q> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Q (326u)
#  define NTC_Num_DataOtherFltMsg_Q ((NTCNumber)326u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_R) || (defined NTC_Num_InvalidMsg_R)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_R) || (RTE_CONST_NTC_Num_InvalidMsg_R != 328u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_R (328u)
#  define NTC_Num_InvalidMsg_R ((NTCNumber)328u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_R) || (defined NTC_Num_MissingMsg_R)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_R) || (RTE_CONST_NTC_Num_MissingMsg_R != 329u)
#   error "Enumeration constant <NTC_Num_MissingMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_R (329u)
#  define NTC_Num_MissingMsg_R ((NTCNumber)329u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_R) || (defined NTC_Num_CRCFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_R) || (RTE_CONST_NTC_Num_CRCFltMsg_R != 330u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_R (330u)
#  define NTC_Num_CRCFltMsg_R ((NTCNumber)330u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_R) || (defined NTC_Num_PgrsCntFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_R) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_R != 331u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_R (331u)
#  define NTC_Num_PgrsCntFltMsg_R ((NTCNumber)331u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_R) || (defined NTC_Num_DataRngFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_R) || (RTE_CONST_NTC_Num_DataRngFltMsg_R != 332u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_R (332u)
#  define NTC_Num_DataRngFltMsg_R ((NTCNumber)332u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_R) || (defined NTC_Num_DataRateFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_R) || (RTE_CONST_NTC_Num_DataRateFltMsg_R != 333u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_R (333u)
#  define NTC_Num_DataRateFltMsg_R ((NTCNumber)333u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_R) || (defined NTC_Num_DataOtherFltMsg_R)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_R) || (RTE_CONST_NTC_Num_DataOtherFltMsg_R != 334u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_R> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_R (334u)
#  define NTC_Num_DataOtherFltMsg_R ((NTCNumber)334u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_S) || (defined NTC_Num_InvalidMsg_S)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_S) || (RTE_CONST_NTC_Num_InvalidMsg_S != 336u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_S (336u)
#  define NTC_Num_InvalidMsg_S ((NTCNumber)336u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_S) || (defined NTC_Num_MissingMsg_S)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_S) || (RTE_CONST_NTC_Num_MissingMsg_S != 337u)
#   error "Enumeration constant <NTC_Num_MissingMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_S (337u)
#  define NTC_Num_MissingMsg_S ((NTCNumber)337u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_S) || (defined NTC_Num_CRCFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_S) || (RTE_CONST_NTC_Num_CRCFltMsg_S != 338u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_S (338u)
#  define NTC_Num_CRCFltMsg_S ((NTCNumber)338u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_S) || (defined NTC_Num_PgrsCntFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_S) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_S != 339u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_S (339u)
#  define NTC_Num_PgrsCntFltMsg_S ((NTCNumber)339u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_S) || (defined NTC_Num_DataRngFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_S) || (RTE_CONST_NTC_Num_DataRngFltMsg_S != 340u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_S (340u)
#  define NTC_Num_DataRngFltMsg_S ((NTCNumber)340u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_S) || (defined NTC_Num_DataRateFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_S) || (RTE_CONST_NTC_Num_DataRateFltMsg_S != 341u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_S (341u)
#  define NTC_Num_DataRateFltMsg_S ((NTCNumber)341u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_S) || (defined NTC_Num_DataOtherFltMsg_S)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_S) || (RTE_CONST_NTC_Num_DataOtherFltMsg_S != 342u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_S> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_S (342u)
#  define NTC_Num_DataOtherFltMsg_S ((NTCNumber)342u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_T) || (defined NTC_Num_InvalidMsg_T)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_T) || (RTE_CONST_NTC_Num_InvalidMsg_T != 344u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_T (344u)
#  define NTC_Num_InvalidMsg_T ((NTCNumber)344u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_T) || (defined NTC_Num_MissingMsg_T)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_T) || (RTE_CONST_NTC_Num_MissingMsg_T != 345u)
#   error "Enumeration constant <NTC_Num_MissingMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_T (345u)
#  define NTC_Num_MissingMsg_T ((NTCNumber)345u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_T) || (defined NTC_Num_CRCFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_T) || (RTE_CONST_NTC_Num_CRCFltMsg_T != 346u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_T (346u)
#  define NTC_Num_CRCFltMsg_T ((NTCNumber)346u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_T) || (defined NTC_Num_PgrsCntFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_T) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_T != 347u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_T (347u)
#  define NTC_Num_PgrsCntFltMsg_T ((NTCNumber)347u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_T) || (defined NTC_Num_DataRngFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_T) || (RTE_CONST_NTC_Num_DataRngFltMsg_T != 348u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_T (348u)
#  define NTC_Num_DataRngFltMsg_T ((NTCNumber)348u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_T) || (defined NTC_Num_DataRateFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_T) || (RTE_CONST_NTC_Num_DataRateFltMsg_T != 349u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_T (349u)
#  define NTC_Num_DataRateFltMsg_T ((NTCNumber)349u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_T) || (defined NTC_Num_DataOtherFltMsg_T)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_T) || (RTE_CONST_NTC_Num_DataOtherFltMsg_T != 350u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_T> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_T (350u)
#  define NTC_Num_DataOtherFltMsg_T ((NTCNumber)350u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_U) || (defined NTC_Num_InvalidMsg_U)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_U) || (RTE_CONST_NTC_Num_InvalidMsg_U != 352u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_U (352u)
#  define NTC_Num_InvalidMsg_U ((NTCNumber)352u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_U) || (defined NTC_Num_MissingMsg_U)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_U) || (RTE_CONST_NTC_Num_MissingMsg_U != 353u)
#   error "Enumeration constant <NTC_Num_MissingMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_U (353u)
#  define NTC_Num_MissingMsg_U ((NTCNumber)353u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_U) || (defined NTC_Num_CRCFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_U) || (RTE_CONST_NTC_Num_CRCFltMsg_U != 354u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_U (354u)
#  define NTC_Num_CRCFltMsg_U ((NTCNumber)354u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_U) || (defined NTC_Num_PgrsCntFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_U) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_U != 355u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_U (355u)
#  define NTC_Num_PgrsCntFltMsg_U ((NTCNumber)355u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_U) || (defined NTC_Num_DataRngFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_U) || (RTE_CONST_NTC_Num_DataRngFltMsg_U != 356u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_U (356u)
#  define NTC_Num_DataRngFltMsg_U ((NTCNumber)356u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_U) || (defined NTC_Num_DataRateFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_U) || (RTE_CONST_NTC_Num_DataRateFltMsg_U != 357u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_U (357u)
#  define NTC_Num_DataRateFltMsg_U ((NTCNumber)357u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_U) || (defined NTC_Num_DataOtherFltMsg_U)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_U) || (RTE_CONST_NTC_Num_DataOtherFltMsg_U != 358u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_U> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_U (358u)
#  define NTC_Num_DataOtherFltMsg_U ((NTCNumber)358u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_V) || (defined NTC_Num_InvalidMsg_V)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_V) || (RTE_CONST_NTC_Num_InvalidMsg_V != 360u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_V (360u)
#  define NTC_Num_InvalidMsg_V ((NTCNumber)360u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_V) || (defined NTC_Num_MissingMsg_V)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_V) || (RTE_CONST_NTC_Num_MissingMsg_V != 361u)
#   error "Enumeration constant <NTC_Num_MissingMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_V (361u)
#  define NTC_Num_MissingMsg_V ((NTCNumber)361u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_V) || (defined NTC_Num_CRCFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_V) || (RTE_CONST_NTC_Num_CRCFltMsg_V != 362u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_V (362u)
#  define NTC_Num_CRCFltMsg_V ((NTCNumber)362u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_V) || (defined NTC_Num_PgrsCntFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_V) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_V != 363u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_V (363u)
#  define NTC_Num_PgrsCntFltMsg_V ((NTCNumber)363u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_V) || (defined NTC_Num_DataRngFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_V) || (RTE_CONST_NTC_Num_DataRngFltMsg_V != 364u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_V (364u)
#  define NTC_Num_DataRngFltMsg_V ((NTCNumber)364u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_V) || (defined NTC_Num_DataRateFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_V) || (RTE_CONST_NTC_Num_DataRateFltMsg_V != 365u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_V (365u)
#  define NTC_Num_DataRateFltMsg_V ((NTCNumber)365u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_V) || (defined NTC_Num_DataOtherFltMsg_V)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_V) || (RTE_CONST_NTC_Num_DataOtherFltMsg_V != 366u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_V> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_V (366u)
#  define NTC_Num_DataOtherFltMsg_V ((NTCNumber)366u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_W) || (defined NTC_Num_InvalidMsg_W)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_W) || (RTE_CONST_NTC_Num_InvalidMsg_W != 368u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_W (368u)
#  define NTC_Num_InvalidMsg_W ((NTCNumber)368u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_W) || (defined NTC_Num_MissingMsg_W)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_W) || (RTE_CONST_NTC_Num_MissingMsg_W != 369u)
#   error "Enumeration constant <NTC_Num_MissingMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_W (369u)
#  define NTC_Num_MissingMsg_W ((NTCNumber)369u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_W) || (defined NTC_Num_CRCFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_W) || (RTE_CONST_NTC_Num_CRCFltMsg_W != 370u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_W (370u)
#  define NTC_Num_CRCFltMsg_W ((NTCNumber)370u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_W) || (defined NTC_Num_PgrsCntFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_W) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_W != 371u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_W (371u)
#  define NTC_Num_PgrsCntFltMsg_W ((NTCNumber)371u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_W) || (defined NTC_Num_DataRngFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_W) || (RTE_CONST_NTC_Num_DataRngFltMsg_W != 372u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_W (372u)
#  define NTC_Num_DataRngFltMsg_W ((NTCNumber)372u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_W) || (defined NTC_Num_DataRateFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_W) || (RTE_CONST_NTC_Num_DataRateFltMsg_W != 373u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_W (373u)
#  define NTC_Num_DataRateFltMsg_W ((NTCNumber)373u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_W) || (defined NTC_Num_DataOtherFltMsg_W)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_W) || (RTE_CONST_NTC_Num_DataOtherFltMsg_W != 374u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_W> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_W (374u)
#  define NTC_Num_DataOtherFltMsg_W ((NTCNumber)374u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_X) || (defined NTC_Num_InvalidMsg_X)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_X) || (RTE_CONST_NTC_Num_InvalidMsg_X != 376u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_X (376u)
#  define NTC_Num_InvalidMsg_X ((NTCNumber)376u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_X) || (defined NTC_Num_MissingMsg_X)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_X) || (RTE_CONST_NTC_Num_MissingMsg_X != 377u)
#   error "Enumeration constant <NTC_Num_MissingMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_X (377u)
#  define NTC_Num_MissingMsg_X ((NTCNumber)377u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_X) || (defined NTC_Num_CRCFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_X) || (RTE_CONST_NTC_Num_CRCFltMsg_X != 378u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_X (378u)
#  define NTC_Num_CRCFltMsg_X ((NTCNumber)378u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_X) || (defined NTC_Num_PgrsCntFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_X) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_X != 379u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_X (379u)
#  define NTC_Num_PgrsCntFltMsg_X ((NTCNumber)379u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_X) || (defined NTC_Num_DataRngFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_X) || (RTE_CONST_NTC_Num_DataRngFltMsg_X != 380u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_X (380u)
#  define NTC_Num_DataRngFltMsg_X ((NTCNumber)380u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_X) || (defined NTC_Num_DataRateFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_X) || (RTE_CONST_NTC_Num_DataRateFltMsg_X != 381u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_X (381u)
#  define NTC_Num_DataRateFltMsg_X ((NTCNumber)381u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_X) || (defined NTC_Num_DataOtherFltMsg_X)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_X) || (RTE_CONST_NTC_Num_DataOtherFltMsg_X != 382u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_X> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_X (382u)
#  define NTC_Num_DataOtherFltMsg_X ((NTCNumber)382u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Y) || (defined NTC_Num_InvalidMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Y) || (RTE_CONST_NTC_Num_InvalidMsg_Y != 384u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Y (384u)
#  define NTC_Num_InvalidMsg_Y ((NTCNumber)384u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Y) || (defined NTC_Num_MissingMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Y) || (RTE_CONST_NTC_Num_MissingMsg_Y != 385u)
#   error "Enumeration constant <NTC_Num_MissingMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Y (385u)
#  define NTC_Num_MissingMsg_Y ((NTCNumber)385u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Y) || (defined NTC_Num_CRCFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Y) || (RTE_CONST_NTC_Num_CRCFltMsg_Y != 386u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Y (386u)
#  define NTC_Num_CRCFltMsg_Y ((NTCNumber)386u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Y) || (defined NTC_Num_PgrsCntFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Y) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Y != 387u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Y (387u)
#  define NTC_Num_PgrsCntFltMsg_Y ((NTCNumber)387u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Y) || (defined NTC_Num_DataRngFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Y) || (RTE_CONST_NTC_Num_DataRngFltMsg_Y != 388u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Y (388u)
#  define NTC_Num_DataRngFltMsg_Y ((NTCNumber)388u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Y) || (defined NTC_Num_DataRateFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Y) || (RTE_CONST_NTC_Num_DataRateFltMsg_Y != 389u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Y (389u)
#  define NTC_Num_DataRateFltMsg_Y ((NTCNumber)389u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Y) || (defined NTC_Num_DataOtherFltMsg_Y)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Y) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Y != 390u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Y> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Y (390u)
#  define NTC_Num_DataOtherFltMsg_Y ((NTCNumber)390u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_Z) || (defined NTC_Num_InvalidMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_Z) || (RTE_CONST_NTC_Num_InvalidMsg_Z != 392u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_Z (392u)
#  define NTC_Num_InvalidMsg_Z ((NTCNumber)392u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_Z) || (defined NTC_Num_MissingMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_Z) || (RTE_CONST_NTC_Num_MissingMsg_Z != 393u)
#   error "Enumeration constant <NTC_Num_MissingMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_Z (393u)
#  define NTC_Num_MissingMsg_Z ((NTCNumber)393u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_Z) || (defined NTC_Num_CRCFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_Z) || (RTE_CONST_NTC_Num_CRCFltMsg_Z != 394u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_Z (394u)
#  define NTC_Num_CRCFltMsg_Z ((NTCNumber)394u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Z) || (defined NTC_Num_PgrsCntFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_Z) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_Z != 395u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_Z (395u)
#  define NTC_Num_PgrsCntFltMsg_Z ((NTCNumber)395u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_Z) || (defined NTC_Num_DataRngFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_Z) || (RTE_CONST_NTC_Num_DataRngFltMsg_Z != 396u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_Z (396u)
#  define NTC_Num_DataRngFltMsg_Z ((NTCNumber)396u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_Z) || (defined NTC_Num_DataRateFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_Z) || (RTE_CONST_NTC_Num_DataRateFltMsg_Z != 397u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_Z (397u)
#  define NTC_Num_DataRateFltMsg_Z ((NTCNumber)397u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_Z) || (defined NTC_Num_DataOtherFltMsg_Z)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_Z) || (RTE_CONST_NTC_Num_DataOtherFltMsg_Z != 398u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_Z> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_Z (398u)
#  define NTC_Num_DataOtherFltMsg_Z ((NTCNumber)398u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AA) || (defined NTC_Num_InvalidMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AA) || (RTE_CONST_NTC_Num_InvalidMsg_AA != 400u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AA (400u)
#  define NTC_Num_InvalidMsg_AA ((NTCNumber)400u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AA) || (defined NTC_Num_MissingMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AA) || (RTE_CONST_NTC_Num_MissingMsg_AA != 401u)
#   error "Enumeration constant <NTC_Num_MissingMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AA (401u)
#  define NTC_Num_MissingMsg_AA ((NTCNumber)401u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AA) || (defined NTC_Num_CRCFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AA) || (RTE_CONST_NTC_Num_CRCFltMsg_AA != 402u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AA (402u)
#  define NTC_Num_CRCFltMsg_AA ((NTCNumber)402u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AA) || (defined NTC_Num_PgrsCntFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AA) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AA != 403u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AA (403u)
#  define NTC_Num_PgrsCntFltMsg_AA ((NTCNumber)403u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AA) || (defined NTC_Num_DataRngFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AA) || (RTE_CONST_NTC_Num_DataRngFltMsg_AA != 404u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AA (404u)
#  define NTC_Num_DataRngFltMsg_AA ((NTCNumber)404u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AA) || (defined NTC_Num_DataRateFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AA) || (RTE_CONST_NTC_Num_DataRateFltMsg_AA != 405u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AA (405u)
#  define NTC_Num_DataRateFltMsg_AA ((NTCNumber)405u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AA) || (defined NTC_Num_DataOtherFltMsg_AA)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AA) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AA != 406u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AA (406u)
#  define NTC_Num_DataOtherFltMsg_AA ((NTCNumber)406u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AB) || (defined NTC_Num_InvalidMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AB) || (RTE_CONST_NTC_Num_InvalidMsg_AB != 408u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AB (408u)
#  define NTC_Num_InvalidMsg_AB ((NTCNumber)408u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AB) || (defined NTC_Num_MissingMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AB) || (RTE_CONST_NTC_Num_MissingMsg_AB != 409u)
#   error "Enumeration constant <NTC_Num_MissingMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AB (409u)
#  define NTC_Num_MissingMsg_AB ((NTCNumber)409u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AB) || (defined NTC_Num_CRCFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AB) || (RTE_CONST_NTC_Num_CRCFltMsg_AB != 410u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AB (410u)
#  define NTC_Num_CRCFltMsg_AB ((NTCNumber)410u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AB) || (defined NTC_Num_PgrsCntFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AB) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AB != 411u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AB (411u)
#  define NTC_Num_PgrsCntFltMsg_AB ((NTCNumber)411u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AB) || (defined NTC_Num_DataRngFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AB) || (RTE_CONST_NTC_Num_DataRngFltMsg_AB != 412u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AB (412u)
#  define NTC_Num_DataRngFltMsg_AB ((NTCNumber)412u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AB) || (defined NTC_Num_DataRateFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AB) || (RTE_CONST_NTC_Num_DataRateFltMsg_AB != 413u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AB (413u)
#  define NTC_Num_DataRateFltMsg_AB ((NTCNumber)413u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AB) || (defined NTC_Num_DataOtherFltMsg_AB)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AB) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AB != 414u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AB (414u)
#  define NTC_Num_DataOtherFltMsg_AB ((NTCNumber)414u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AC) || (defined NTC_Num_InvalidMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AC) || (RTE_CONST_NTC_Num_InvalidMsg_AC != 416u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AC (416u)
#  define NTC_Num_InvalidMsg_AC ((NTCNumber)416u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AC) || (defined NTC_Num_MissingMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AC) || (RTE_CONST_NTC_Num_MissingMsg_AC != 417u)
#   error "Enumeration constant <NTC_Num_MissingMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AC (417u)
#  define NTC_Num_MissingMsg_AC ((NTCNumber)417u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AC) || (defined NTC_Num_CRCFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AC) || (RTE_CONST_NTC_Num_CRCFltMsg_AC != 418u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AC (418u)
#  define NTC_Num_CRCFltMsg_AC ((NTCNumber)418u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AC) || (defined NTC_Num_PgrsCntFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AC) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AC != 419u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AC (419u)
#  define NTC_Num_PgrsCntFltMsg_AC ((NTCNumber)419u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AC) || (defined NTC_Num_DataRngFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AC) || (RTE_CONST_NTC_Num_DataRngFltMsg_AC != 420u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AC (420u)
#  define NTC_Num_DataRngFltMsg_AC ((NTCNumber)420u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AC) || (defined NTC_Num_DataRateFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AC) || (RTE_CONST_NTC_Num_DataRateFltMsg_AC != 421u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AC (421u)
#  define NTC_Num_DataRateFltMsg_AC ((NTCNumber)421u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AC) || (defined NTC_Num_DataOtherFltMsg_AC)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AC) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AC != 422u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AC (422u)
#  define NTC_Num_DataOtherFltMsg_AC ((NTCNumber)422u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AD) || (defined NTC_Num_InvalidMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AD) || (RTE_CONST_NTC_Num_InvalidMsg_AD != 424u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AD (424u)
#  define NTC_Num_InvalidMsg_AD ((NTCNumber)424u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AD) || (defined NTC_Num_MissingMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AD) || (RTE_CONST_NTC_Num_MissingMsg_AD != 425u)
#   error "Enumeration constant <NTC_Num_MissingMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AD (425u)
#  define NTC_Num_MissingMsg_AD ((NTCNumber)425u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AD) || (defined NTC_Num_CRCFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AD) || (RTE_CONST_NTC_Num_CRCFltMsg_AD != 426u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AD (426u)
#  define NTC_Num_CRCFltMsg_AD ((NTCNumber)426u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AD) || (defined NTC_Num_PgrsCntFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AD) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AD != 427u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AD (427u)
#  define NTC_Num_PgrsCntFltMsg_AD ((NTCNumber)427u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AD) || (defined NTC_Num_DataRngFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AD) || (RTE_CONST_NTC_Num_DataRngFltMsg_AD != 428u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AD (428u)
#  define NTC_Num_DataRngFltMsg_AD ((NTCNumber)428u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AD) || (defined NTC_Num_DataRateFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AD) || (RTE_CONST_NTC_Num_DataRateFltMsg_AD != 429u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AD (429u)
#  define NTC_Num_DataRateFltMsg_AD ((NTCNumber)429u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AD) || (defined NTC_Num_DataOtherFltMsg_AD)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AD) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AD != 430u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AD (430u)
#  define NTC_Num_DataOtherFltMsg_AD ((NTCNumber)430u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AE) || (defined NTC_Num_InvalidMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AE) || (RTE_CONST_NTC_Num_InvalidMsg_AE != 432u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AE (432u)
#  define NTC_Num_InvalidMsg_AE ((NTCNumber)432u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AE) || (defined NTC_Num_MissingMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AE) || (RTE_CONST_NTC_Num_MissingMsg_AE != 433u)
#   error "Enumeration constant <NTC_Num_MissingMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AE (433u)
#  define NTC_Num_MissingMsg_AE ((NTCNumber)433u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AE) || (defined NTC_Num_CRCFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AE) || (RTE_CONST_NTC_Num_CRCFltMsg_AE != 434u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AE (434u)
#  define NTC_Num_CRCFltMsg_AE ((NTCNumber)434u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AE) || (defined NTC_Num_PgrsCntFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AE) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AE != 435u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AE (435u)
#  define NTC_Num_PgrsCntFltMsg_AE ((NTCNumber)435u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AE) || (defined NTC_Num_DataRngFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AE) || (RTE_CONST_NTC_Num_DataRngFltMsg_AE != 436u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AE (436u)
#  define NTC_Num_DataRngFltMsg_AE ((NTCNumber)436u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AE) || (defined NTC_Num_DataRateFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AE) || (RTE_CONST_NTC_Num_DataRateFltMsg_AE != 437u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AE (437u)
#  define NTC_Num_DataRateFltMsg_AE ((NTCNumber)437u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AE) || (defined NTC_Num_DataOtherFltMsg_AE)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AE) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AE != 438u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AE (438u)
#  define NTC_Num_DataOtherFltMsg_AE ((NTCNumber)438u)
# endif
# if (defined RTE_CONST_NTC_Num_InvalidMsg_AF) || (defined NTC_Num_InvalidMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_InvalidMsg_AF) || (RTE_CONST_NTC_Num_InvalidMsg_AF != 440u)
#   error "Enumeration constant <NTC_Num_InvalidMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_InvalidMsg_AF (440u)
#  define NTC_Num_InvalidMsg_AF ((NTCNumber)440u)
# endif
# if (defined RTE_CONST_NTC_Num_MissingMsg_AF) || (defined NTC_Num_MissingMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_MissingMsg_AF) || (RTE_CONST_NTC_Num_MissingMsg_AF != 441u)
#   error "Enumeration constant <NTC_Num_MissingMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_MissingMsg_AF (441u)
#  define NTC_Num_MissingMsg_AF ((NTCNumber)441u)
# endif
# if (defined RTE_CONST_NTC_Num_CRCFltMsg_AF) || (defined NTC_Num_CRCFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_CRCFltMsg_AF) || (RTE_CONST_NTC_Num_CRCFltMsg_AF != 442u)
#   error "Enumeration constant <NTC_Num_CRCFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_CRCFltMsg_AF (442u)
#  define NTC_Num_CRCFltMsg_AF ((NTCNumber)442u)
# endif
# if (defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AF) || (defined NTC_Num_PgrsCntFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_PgrsCntFltMsg_AF) || (RTE_CONST_NTC_Num_PgrsCntFltMsg_AF != 443u)
#   error "Enumeration constant <NTC_Num_PgrsCntFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PgrsCntFltMsg_AF (443u)
#  define NTC_Num_PgrsCntFltMsg_AF ((NTCNumber)443u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRngFltMsg_AF) || (defined NTC_Num_DataRngFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataRngFltMsg_AF) || (RTE_CONST_NTC_Num_DataRngFltMsg_AF != 444u)
#   error "Enumeration constant <NTC_Num_DataRngFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRngFltMsg_AF (444u)
#  define NTC_Num_DataRngFltMsg_AF ((NTCNumber)444u)
# endif
# if (defined RTE_CONST_NTC_Num_DataRateFltMsg_AF) || (defined NTC_Num_DataRateFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataRateFltMsg_AF) || (RTE_CONST_NTC_Num_DataRateFltMsg_AF != 445u)
#   error "Enumeration constant <NTC_Num_DataRateFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataRateFltMsg_AF (445u)
#  define NTC_Num_DataRateFltMsg_AF ((NTCNumber)445u)
# endif
# if (defined RTE_CONST_NTC_Num_DataOtherFltMsg_AF) || (defined NTC_Num_DataOtherFltMsg_AF)
#  if (!defined RTE_CONST_NTC_Num_DataOtherFltMsg_AF) || (RTE_CONST_NTC_Num_DataOtherFltMsg_AF != 446u)
#   error "Enumeration constant <NTC_Num_DataOtherFltMsg_AF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DataOtherFltMsg_AF (446u)
#  define NTC_Num_DataOtherFltMsg_AF ((NTCNumber)446u)
# endif

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;
# define NvM_RequestResultType_LowerLimit ((NvM_RequestResultType)0u)
# define NvM_RequestResultType_UpperLimit ((NvM_RequestResultType)5u)
# if (defined RTE_CONST_NVM_REQ_OK) || (defined NVM_REQ_OK)
#  if (!defined RTE_CONST_NVM_REQ_OK) || (RTE_CONST_NVM_REQ_OK != 0u)
#   error "Enumeration constant <NVM_REQ_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_OK (0u)
#  define NVM_REQ_OK ((NvM_RequestResultType)0u)
# endif
# if (defined RTE_CONST_NVM_REQ_NOT_OK) || (defined NVM_REQ_NOT_OK)
#  if (!defined RTE_CONST_NVM_REQ_NOT_OK) || (RTE_CONST_NVM_REQ_NOT_OK != 1u)
#   error "Enumeration constant <NVM_REQ_NOT_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_NOT_OK (1u)
#  define NVM_REQ_NOT_OK ((NvM_RequestResultType)1u)
# endif
# if (defined RTE_CONST_NVM_REQ_PENDING) || (defined NVM_REQ_PENDING)
#  if (!defined RTE_CONST_NVM_REQ_PENDING) || (RTE_CONST_NVM_REQ_PENDING != 2u)
#   error "Enumeration constant <NVM_REQ_PENDING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_PENDING (2u)
#  define NVM_REQ_PENDING ((NvM_RequestResultType)2u)
# endif
# if (defined RTE_CONST_NVM_REQ_INTEGRITY_FAILED) || (defined NVM_REQ_INTEGRITY_FAILED)
#  if (!defined RTE_CONST_NVM_REQ_INTEGRITY_FAILED) || (RTE_CONST_NVM_REQ_INTEGRITY_FAILED != 3u)
#   error "Enumeration constant <NVM_REQ_INTEGRITY_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_INTEGRITY_FAILED (3u)
#  define NVM_REQ_INTEGRITY_FAILED ((NvM_RequestResultType)3u)
# endif
# if (defined RTE_CONST_NVM_REQ_BLOCK_SKIPPED) || (defined NVM_REQ_BLOCK_SKIPPED)
#  if (!defined RTE_CONST_NVM_REQ_BLOCK_SKIPPED) || (RTE_CONST_NVM_REQ_BLOCK_SKIPPED != 4u)
#   error "Enumeration constant <NVM_REQ_BLOCK_SKIPPED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_BLOCK_SKIPPED (4u)
#  define NVM_REQ_BLOCK_SKIPPED ((NvM_RequestResultType)4u)
# endif
# if (defined RTE_CONST_NVM_REQ_NV_INVALIDATED) || (defined NVM_REQ_NV_INVALIDATED)
#  if (!defined RTE_CONST_NVM_REQ_NV_INVALIDATED) || (RTE_CONST_NVM_REQ_NV_INVALIDATED != 5u)
#   error "Enumeration constant <NVM_REQ_NV_INVALIDATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_NV_INVALIDATED (5u)
#  define NVM_REQ_NV_INVALIDATED ((NvM_RequestResultType)5u)
# endif

# define Rte_TypeDef_NxtrDiagMgrStatus
typedef uint8 NxtrDiagMgrStatus;
# define NxtrDiagMgrStatus_LowerLimit ((NxtrDiagMgrStatus)0u)
# define NxtrDiagMgrStatus_UpperLimit ((NxtrDiagMgrStatus)255u)
# if (defined RTE_CONST_NTC_STATUS_PASSED) || (defined NTC_STATUS_PASSED)
#  if (!defined RTE_CONST_NTC_STATUS_PASSED) || (RTE_CONST_NTC_STATUS_PASSED != 0u)
#   error "Enumeration constant <NTC_STATUS_PASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PASSED (0u)
#  define NTC_STATUS_PASSED ((NxtrDiagMgrStatus)0u)
# endif
# if (defined RTE_CONST_NTC_STATUS_FAILED) || (defined NTC_STATUS_FAILED)
#  if (!defined RTE_CONST_NTC_STATUS_FAILED) || (RTE_CONST_NTC_STATUS_FAILED != 1u)
#   error "Enumeration constant <NTC_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_FAILED (1u)
#  define NTC_STATUS_FAILED ((NxtrDiagMgrStatus)1u)
# endif
# if (defined RTE_CONST_NTC_STATUS_PREPASSED) || (defined NTC_STATUS_PREPASSED)
#  if (!defined RTE_CONST_NTC_STATUS_PREPASSED) || (RTE_CONST_NTC_STATUS_PREPASSED != 2u)
#   error "Enumeration constant <NTC_STATUS_PREPASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PREPASSED (2u)
#  define NTC_STATUS_PREPASSED ((NxtrDiagMgrStatus)2u)
# endif
# if (defined RTE_CONST_NTC_STATUS_PREFAILED) || (defined NTC_STATUS_PREFAILED)
#  if (!defined RTE_CONST_NTC_STATUS_PREFAILED) || (RTE_CONST_NTC_STATUS_PREFAILED != 3u)
#   error "Enumeration constant <NTC_STATUS_PREFAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_STATUS_PREFAILED (3u)
#  define NTC_STATUS_PREFAILED ((NxtrDiagMgrStatus)3u)
# endif

# define Rte_TypeDef_NxtrOpCycle
typedef uint8 NxtrOpCycle;
# define NxtrOpCycle_LowerLimit ((NxtrOpCycle)0u)
# define NxtrOpCycle_UpperLimit ((NxtrOpCycle)0u)
# if (defined RTE_CONST_NxtrDefaultOpCycle) || (defined NxtrDefaultOpCycle)
#  if (!defined RTE_CONST_NxtrDefaultOpCycle) || (RTE_CONST_NxtrDefaultOpCycle != 0u)
#   error "Enumeration constant <NxtrDefaultOpCycle> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NxtrDefaultOpCycle (0u)
#  define NxtrDefaultOpCycle ((NxtrOpCycle)0u)
# endif

# define Rte_TypeDef_NxtrOpCycleState
typedef uint8 NxtrOpCycleState;
# define NxtrOpCycleState_LowerLimit ((NxtrOpCycleState)1u)
# define NxtrOpCycleState_UpperLimit ((NxtrOpCycleState)2u)
# if (defined RTE_CONST_NXTR_CYCLE_STATE_START) || (defined NXTR_CYCLE_STATE_START)
#  if (!defined RTE_CONST_NXTR_CYCLE_STATE_START) || (RTE_CONST_NXTR_CYCLE_STATE_START != 1u)
#   error "Enumeration constant <NXTR_CYCLE_STATE_START> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NXTR_CYCLE_STATE_START (1u)
#  define NXTR_CYCLE_STATE_START ((NxtrOpCycleState)1u)
# endif
# if (defined RTE_CONST_NXTR_CYCLE_STATE_END) || (defined NXTR_CYCLE_STATE_END)
#  if (!defined RTE_CONST_NXTR_CYCLE_STATE_END) || (RTE_CONST_NXTR_CYCLE_STATE_END != 2u)
#   error "Enumeration constant <NXTR_CYCLE_STATE_END> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NXTR_CYCLE_STATE_END (2u)
#  define NXTR_CYCLE_STATE_END ((NxtrOpCycleState)2u)
# endif

# define Rte_TypeDef_DT_SinTanLkpTbl_f32
typedef Float DT_SinTanLkpTbl_f32[193];

# define Rte_TypeDef_NvM_DestPtr
typedef UInt8 NvM_DestPtr[65535];

# define Rte_TypeDef_NTCStrg
typedef struct
{
  NTCNumber NTC;
  UInt8 Status;
} NTCStrg;

# define Rte_TypeDef_NTCStrgArray
typedef NTCStrg NTCStrgArray[15];


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_IoHwAb_BoolType
typedef uint8 IoHwAb_BoolType;
#  define IoHwAb_BoolType_LowerLimit ((IoHwAb_BoolType)0u)
#  define IoHwAb_BoolType_UpperLimit ((IoHwAb_BoolType)1u)

#  define Rte_TypeDef_SInt4
typedef sint8 SInt4;
#  define SInt4_LowerLimit ((SInt4)-8)
#  define SInt4_UpperLimit ((SInt4)7)

#  define Rte_TypeDef_UInt4
typedef uint8 UInt4;
#  define UInt4_LowerLimit ((UInt4)0u)
#  define UInt4_UpperLimit ((UInt4)15u)

#  define Rte_TypeDef_EnergyModeStateType
typedef uint8 EnergyModeStateType;
#  define EnergyModeStateType_LowerLimit ((EnergyModeStateType)0u)
#  define EnergyModeStateType_UpperLimit ((EnergyModeStateType)3u)
#  if (defined RTE_CONST_NORMAL) || (defined NORMAL)
#   if (!defined RTE_CONST_NORMAL) || (RTE_CONST_NORMAL != 0u)
#    error "Enumeration constant <NORMAL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NORMAL (0u)
#   define NORMAL ((EnergyModeStateType)0u)
#  endif
#  if (defined RTE_CONST_PRODUCTION) || (defined PRODUCTION)
#   if (!defined RTE_CONST_PRODUCTION) || (RTE_CONST_PRODUCTION != 1u)
#    error "Enumeration constant <PRODUCTION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PRODUCTION (1u)
#   define PRODUCTION ((EnergyModeStateType)1u)
#  endif
#  if (defined RTE_CONST_TRANSPORTATION) || (defined TRANSPORTATION)
#   if (!defined RTE_CONST_TRANSPORTATION) || (RTE_CONST_TRANSPORTATION != 2u)
#    error "Enumeration constant <TRANSPORTATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TRANSPORTATION (2u)
#   define TRANSPORTATION ((EnergyModeStateType)2u)
#  endif
#  if (defined RTE_CONST_FLASH) || (defined FLASH)
#   if (!defined RTE_CONST_FLASH) || (RTE_CONST_FLASH != 3u)
#    error "Enumeration constant <FLASH> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_FLASH (3u)
#   define FLASH ((EnergyModeStateType)3u)
#  endif

#  define Rte_TypeDef_LktoLkStrStateType
typedef uint8 LktoLkStrStateType;
#  define LktoLkStrStateType_LowerLimit ((LktoLkStrStateType)0u)
#  define LktoLkStrStateType_UpperLimit ((LktoLkStrStateType)7u)
#  if (defined RTE_CONST_HOLD) || (defined HOLD)
#   if (!defined RTE_CONST_HOLD) || (RTE_CONST_HOLD != 0u)
#    error "Enumeration constant <HOLD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_HOLD (0u)
#   define HOLD ((LktoLkStrStateType)0u)
#  endif
#  if (defined RTE_CONST_POSANGVEL) || (defined POSANGVEL)
#   if (!defined RTE_CONST_POSANGVEL) || (RTE_CONST_POSANGVEL != 1u)
#    error "Enumeration constant <POSANGVEL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_POSANGVEL (1u)
#   define POSANGVEL ((LktoLkStrStateType)1u)
#  endif
#  if (defined RTE_CONST_POSMTRTRQ) || (defined POSMTRTRQ)
#   if (!defined RTE_CONST_POSMTRTRQ) || (RTE_CONST_POSMTRTRQ != 2u)
#    error "Enumeration constant <POSMTRTRQ> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_POSMTRTRQ (2u)
#   define POSMTRTRQ ((LktoLkStrStateType)2u)
#  endif
#  if (defined RTE_CONST_NEGANGVEL) || (defined NEGANGVEL)
#   if (!defined RTE_CONST_NEGANGVEL) || (RTE_CONST_NEGANGVEL != 3u)
#    error "Enumeration constant <NEGANGVEL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NEGANGVEL (3u)
#   define NEGANGVEL ((LktoLkStrStateType)3u)
#  endif
#  if (defined RTE_CONST_NEGMTRTRQ) || (defined NEGMTRTRQ)
#   if (!defined RTE_CONST_NEGMTRTRQ) || (RTE_CONST_NEGMTRTRQ != 4u)
#    error "Enumeration constant <NEGMTRTRQ> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NEGMTRTRQ (4u)
#   define NEGMTRTRQ ((LktoLkStrStateType)4u)
#  endif
#  if (defined RTE_CONST_MOVETO) || (defined MOVETO)
#   if (!defined RTE_CONST_MOVETO) || (RTE_CONST_MOVETO != 5u)
#    error "Enumeration constant <MOVETO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_MOVETO (5u)
#   define MOVETO ((LktoLkStrStateType)5u)
#  endif
#  if (defined RTE_CONST_DONE) || (defined DONE)
#   if (!defined RTE_CONST_DONE) || (RTE_CONST_DONE != 6u)
#    error "Enumeration constant <DONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DONE (6u)
#   define DONE ((LktoLkStrStateType)6u)
#  endif
#  if (defined RTE_CONST_TIMEOUT) || (defined TIMEOUT)
#   if (!defined RTE_CONST_TIMEOUT) || (RTE_CONST_TIMEOUT != 7u)
#    error "Enumeration constant <TIMEOUT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TIMEOUT (7u)
#   define TIMEOUT ((LktoLkStrStateType)7u)
#  endif

#  define Rte_TypeDef_OscTrajCmdStateType
typedef uint8 OscTrajCmdStateType;
#  define OscTrajCmdStateType_LowerLimit ((OscTrajCmdStateType)0u)
#  define OscTrajCmdStateType_UpperLimit ((OscTrajCmdStateType)2u)
#  if (defined RTE_CONST_CMD_STATE0) || (defined CMD_STATE0)
#   if (!defined RTE_CONST_CMD_STATE0) || (RTE_CONST_CMD_STATE0 != 0u)
#    error "Enumeration constant <CMD_STATE0> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CMD_STATE0 (0u)
#   define CMD_STATE0 ((OscTrajCmdStateType)0u)
#  endif
#  if (defined RTE_CONST_CMD_STATE1) || (defined CMD_STATE1)
#   if (!defined RTE_CONST_CMD_STATE1) || (RTE_CONST_CMD_STATE1 != 1u)
#    error "Enumeration constant <CMD_STATE1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CMD_STATE1 (1u)
#   define CMD_STATE1 ((OscTrajCmdStateType)1u)
#  endif
#  if (defined RTE_CONST_CMD_STATE2) || (defined CMD_STATE2)
#   if (!defined RTE_CONST_CMD_STATE2) || (RTE_CONST_CMD_STATE2 != 2u)
#    error "Enumeration constant <CMD_STATE2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CMD_STATE2 (2u)
#   define CMD_STATE2 ((OscTrajCmdStateType)2u)
#  endif

#  define Rte_TypeDef_PersonalizationType
typedef uint8 PersonalizationType;
#  define PersonalizationType_LowerLimit ((PersonalizationType)0u)
#  define PersonalizationType_UpperLimit ((PersonalizationType)3u)
#  if (defined RTE_CONST_PERSONALIZATION_NOTUSED) || (defined PERSONALIZATION_NOTUSED)
#   if (!defined RTE_CONST_PERSONALIZATION_NOTUSED) || (RTE_CONST_PERSONALIZATION_NOTUSED != 0u)
#    error "Enumeration constant <PERSONALIZATION_NOTUSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PERSONALIZATION_NOTUSED (0u)
#   define PERSONALIZATION_NOTUSED ((PersonalizationType)0u)
#  endif
#  if (defined RTE_CONST_PERSONALIZATION_COMFORT) || (defined PERSONALIZATION_COMFORT)
#   if (!defined RTE_CONST_PERSONALIZATION_COMFORT) || (RTE_CONST_PERSONALIZATION_COMFORT != 1u)
#    error "Enumeration constant <PERSONALIZATION_COMFORT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PERSONALIZATION_COMFORT (1u)
#   define PERSONALIZATION_COMFORT ((PersonalizationType)1u)
#  endif
#  if (defined RTE_CONST_PERSONALIZATION_NORMAL) || (defined PERSONALIZATION_NORMAL)
#   if (!defined RTE_CONST_PERSONALIZATION_NORMAL) || (RTE_CONST_PERSONALIZATION_NORMAL != 2u)
#    error "Enumeration constant <PERSONALIZATION_NORMAL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PERSONALIZATION_NORMAL (2u)
#   define PERSONALIZATION_NORMAL ((PersonalizationType)2u)
#  endif
#  if (defined RTE_CONST_PERSONALIZATION_SPORT) || (defined PERSONALIZATION_SPORT)
#   if (!defined RTE_CONST_PERSONALIZATION_SPORT) || (RTE_CONST_PERSONALIZATION_SPORT != 3u)
#    error "Enumeration constant <PERSONALIZATION_SPORT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PERSONALIZATION_SPORT (3u)
#   define PERSONALIZATION_SPORT ((PersonalizationType)3u)
#  endif

#  define Rte_TypeDef_RoutineStatus
typedef uint8 RoutineStatus;
#  define RoutineStatus_LowerLimit ((RoutineStatus)0u)
#  define RoutineStatus_UpperLimit ((RoutineStatus)3u)
#  if (defined RTE_CONST_RTN_INACTIVE) || (defined RTN_INACTIVE)
#   if (!defined RTE_CONST_RTN_INACTIVE) || (RTE_CONST_RTN_INACTIVE != 0u)
#    error "Enumeration constant <RTN_INACTIVE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_INACTIVE (0u)
#   define RTN_INACTIVE ((RoutineStatus)0u)
#  endif
#  if (defined RTE_CONST_RTN_ACTIVE) || (defined RTN_ACTIVE)
#   if (!defined RTE_CONST_RTN_ACTIVE) || (RTE_CONST_RTN_ACTIVE != 1u)
#    error "Enumeration constant <RTN_ACTIVE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_ACTIVE (1u)
#   define RTN_ACTIVE ((RoutineStatus)1u)
#  endif
#  if (defined RTE_CONST_RTN_COMPLETE) || (defined RTN_COMPLETE)
#   if (!defined RTE_CONST_RTN_COMPLETE) || (RTE_CONST_RTN_COMPLETE != 2u)
#    error "Enumeration constant <RTN_COMPLETE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_COMPLETE (2u)
#   define RTN_COMPLETE ((RoutineStatus)2u)
#  endif
#  if (defined RTE_CONST_RTN_CANCELLED) || (defined RTN_CANCELLED)
#   if (!defined RTE_CONST_RTN_CANCELLED) || (RTE_CONST_RTN_CANCELLED != 3u)
#    error "Enumeration constant <RTN_CANCELLED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_CANCELLED (3u)
#   define RTN_CANCELLED ((RoutineStatus)3u)
#  endif

#  define Rte_TypeDef_ST_OFFS_QUAD_EPS
typedef uint8 ST_OFFS_QUAD_EPS;
#  define ST_OFFS_QUAD_EPS_LowerLimit ((ST_OFFS_QUAD_EPS)0u)
#  define ST_OFFS_QUAD_EPS_UpperLimit ((ST_OFFS_QUAD_EPS)15u)
#  if (defined RTE_CONST_STOFFSQUADEPS_SLEEP) || (defined STOFFSQUADEPS_SLEEP)
#   if (!defined RTE_CONST_STOFFSQUADEPS_SLEEP) || (RTE_CONST_STOFFSQUADEPS_SLEEP != 0u)
#    error "Enumeration constant <STOFFSQUADEPS_SLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_SLEEP (0u)
#   define STOFFSQUADEPS_SLEEP ((ST_OFFS_QUAD_EPS)0u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_CALCULATED) || (defined STOFFSQUADEPS_CALCULATED)
#   if (!defined RTE_CONST_STOFFSQUADEPS_CALCULATED) || (RTE_CONST_STOFFSQUADEPS_CALCULATED != 1u)
#    error "Enumeration constant <STOFFSQUADEPS_CALCULATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_CALCULATED (1u)
#   define STOFFSQUADEPS_CALCULATED ((ST_OFFS_QUAD_EPS)1u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_INDEX) || (defined STOFFSQUADEPS_INDEX)
#   if (!defined RTE_CONST_STOFFSQUADEPS_INDEX) || (RTE_CONST_STOFFSQUADEPS_INDEX != 2u)
#    error "Enumeration constant <STOFFSQUADEPS_INDEX> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_INDEX (2u)
#   define STOFFSQUADEPS_INDEX ((ST_OFFS_QUAD_EPS)2u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_MODELCOMP) || (defined STOFFSQUADEPS_MODELCOMP)
#   if (!defined RTE_CONST_STOFFSQUADEPS_MODELCOMP) || (RTE_CONST_STOFFSQUADEPS_MODELCOMP != 3u)
#    error "Enumeration constant <STOFFSQUADEPS_MODELCOMP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_MODELCOMP (3u)
#   define STOFFSQUADEPS_MODELCOMP ((ST_OFFS_QUAD_EPS)3u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK) || (defined STOFFSQUADEPS_LOCKTOLOCK)
#   if (!defined RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK) || (RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK != 4u)
#    error "Enumeration constant <STOFFSQUADEPS_LOCKTOLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK (4u)
#   define STOFFSQUADEPS_LOCKTOLOCK ((ST_OFFS_QUAD_EPS)4u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE) || (defined STOFFSQUADEPS_SUMSTEERINGANGLE)
#   if (!defined RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE) || (RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE != 5u)
#    error "Enumeration constant <STOFFSQUADEPS_SUMSTEERINGANGLE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE (5u)
#   define STOFFSQUADEPS_SUMSTEERINGANGLE ((ST_OFFS_QUAD_EPS)5u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_CHECK) || (defined STOFFSQUADEPS_CHECK)
#   if (!defined RTE_CONST_STOFFSQUADEPS_CHECK) || (RTE_CONST_STOFFSQUADEPS_CHECK != 6u)
#    error "Enumeration constant <STOFFSQUADEPS_CHECK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_CHECK (6u)
#   define STOFFSQUADEPS_CHECK ((ST_OFFS_QUAD_EPS)6u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_CORRECTION) || (defined STOFFSQUADEPS_CORRECTION)
#   if (!defined RTE_CONST_STOFFSQUADEPS_CORRECTION) || (RTE_CONST_STOFFSQUADEPS_CORRECTION != 7u)
#    error "Enumeration constant <STOFFSQUADEPS_CORRECTION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_CORRECTION (7u)
#   define STOFFSQUADEPS_CORRECTION ((ST_OFFS_QUAD_EPS)7u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_INITIALIZATION) || (defined STOFFSQUADEPS_INITIALIZATION)
#   if (!defined RTE_CONST_STOFFSQUADEPS_INITIALIZATION) || (RTE_CONST_STOFFSQUADEPS_INITIALIZATION != 8u)
#    error "Enumeration constant <STOFFSQUADEPS_INITIALIZATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_INITIALIZATION (8u)
#   define STOFFSQUADEPS_INITIALIZATION ((ST_OFFS_QUAD_EPS)8u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_DETERMINED) || (defined STOFFSQUADEPS_DETERMINED)
#   if (!defined RTE_CONST_STOFFSQUADEPS_DETERMINED) || (RTE_CONST_STOFFSQUADEPS_DETERMINED != 9u)
#    error "Enumeration constant <STOFFSQUADEPS_DETERMINED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_DETERMINED (9u)
#   define STOFFSQUADEPS_DETERMINED ((ST_OFFS_QUAD_EPS)9u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_APPROXIMATED) || (defined STOFFSQUADEPS_APPROXIMATED)
#   if (!defined RTE_CONST_STOFFSQUADEPS_APPROXIMATED) || (RTE_CONST_STOFFSQUADEPS_APPROXIMATED != 11u)
#    error "Enumeration constant <STOFFSQUADEPS_APPROXIMATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_APPROXIMATED (11u)
#   define STOFFSQUADEPS_APPROXIMATED ((ST_OFFS_QUAD_EPS)11u)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_INVALID) || (defined STOFFSQUADEPS_INVALID)
#   if (!defined RTE_CONST_STOFFSQUADEPS_INVALID) || (RTE_CONST_STOFFSQUADEPS_INVALID != 15u)
#    error "Enumeration constant <STOFFSQUADEPS_INVALID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_INVALID (15u)
#   define STOFFSQUADEPS_INVALID ((ST_OFFS_QUAD_EPS)15u)
#  endif

#  define Rte_TypeDef_StaMd_Users
typedef uint8 StaMd_Users;
#  define StaMd_Users_LowerLimit ((StaMd_Users)0u)
#  define StaMd_Users_UpperLimit ((StaMd_Users)15u)
#  if (defined RTE_CONST_STAMD_STOPCTRL) || (defined STAMD_STOPCTRL)
#   if (!defined RTE_CONST_STAMD_STOPCTRL) || (RTE_CONST_STAMD_STOPCTRL != 0u)
#    error "Enumeration constant <STAMD_STOPCTRL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STAMD_STOPCTRL (0u)
#   define STAMD_STOPCTRL ((StaMd_Users)0u)
#  endif
#  if (defined RTE_CONST_STAMD_VEHPWRMD) || (defined STAMD_VEHPWRMD)
#   if (!defined RTE_CONST_STAMD_VEHPWRMD) || (RTE_CONST_STAMD_VEHPWRMD != 1u)
#    error "Enumeration constant <STAMD_VEHPWRMD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STAMD_VEHPWRMD (1u)
#   define STAMD_VEHPWRMD ((StaMd_Users)1u)
#  endif
#  if (defined RTE_CONST_STAMD_DIAGMGR) || (defined STAMD_DIAGMGR)
#   if (!defined RTE_CONST_STAMD_DIAGMGR) || (RTE_CONST_STAMD_DIAGMGR != 2u)
#    error "Enumeration constant <STAMD_DIAGMGR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STAMD_DIAGMGR (2u)
#   define STAMD_DIAGMGR ((StaMd_Users)2u)
#  endif
#  if (defined RTE_CONST_STAMD_PHSDSCNCT) || (defined STAMD_PHSDSCNCT)
#   if (!defined RTE_CONST_STAMD_PHSDSCNCT) || (RTE_CONST_STAMD_PHSDSCNCT != 3u)
#    error "Enumeration constant <STAMD_PHSDSCNCT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STAMD_PHSDSCNCT (3u)
#   define STAMD_PHSDSCNCT ((StaMd_Users)3u)
#  endif
#  if (defined RTE_CONST_STAMD_MTRDRVR) || (defined STAMD_MTRDRVR)
#   if (!defined RTE_CONST_STAMD_MTRDRVR) || (RTE_CONST_STAMD_MTRDRVR != 4u)
#    error "Enumeration constant <STAMD_MTRDRVR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STAMD_MTRDRVR (4u)
#   define STAMD_MTRDRVR ((StaMd_Users)4u)
#  endif
#  if (defined RTE_CONST_STAMD_TMPRLMON) || (defined STAMD_TMPRLMON)
#   if (!defined RTE_CONST_STAMD_TMPRLMON) || (RTE_CONST_STAMD_TMPRLMON != 5u)
#    error "Enumeration constant <STAMD_TMPRLMON> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STAMD_TMPRLMON (5u)
#   define STAMD_TMPRLMON ((StaMd_Users)5u)
#  endif

#  define Rte_TypeDef_TurnsCntrValStateType
typedef uint8 TurnsCntrValStateType;
#  define TurnsCntrValStateType_LowerLimit ((TurnsCntrValStateType)0u)
#  define TurnsCntrValStateType_UpperLimit ((TurnsCntrValStateType)255u)
#  if (defined RTE_CONST_TCV_COMPUTING) || (defined TCV_COMPUTING)
#   if (!defined RTE_CONST_TCV_COMPUTING) || (RTE_CONST_TCV_COMPUTING != 0u)
#    error "Enumeration constant <TCV_COMPUTING> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TCV_COMPUTING (0u)
#   define TCV_COMPUTING ((TurnsCntrValStateType)0u)
#  endif
#  if (defined RTE_CONST_TCV_VALID) || (defined TCV_VALID)
#   if (!defined RTE_CONST_TCV_VALID) || (RTE_CONST_TCV_VALID != 100u)
#    error "Enumeration constant <TCV_VALID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TCV_VALID (100u)
#   define TCV_VALID ((TurnsCntrValStateType)100u)
#  endif
#  if (defined RTE_CONST_TCV_INVALID) || (defined TCV_INVALID)
#   if (!defined RTE_CONST_TCV_INVALID) || (RTE_CONST_TCV_INVALID != 255u)
#    error "Enumeration constant <TCV_INVALID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TCV_INVALID (255u)
#   define TCV_INVALID ((TurnsCntrValStateType)255u)
#  endif

#  define Rte_TypeDef_DiagSettings_Str
typedef struct
{
  UInt16 Threshold;
  UInt16 PStep;
  UInt16 NStep;
} DiagSettings_Str;

# endif


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
typedef uint8 Rte_ModeType_StaMd_Mode;

# define RTE_MODE_StaMd_Mode_DISABLE ((Rte_ModeType_StaMd_Mode)0)
# define RTE_MODE_StaMd_Mode_OFF ((Rte_ModeType_StaMd_Mode)1)
# define RTE_MODE_StaMd_Mode_OPERATE ((Rte_ModeType_StaMd_Mode)2)
# define RTE_MODE_StaMd_Mode_WARMINIT ((Rte_ModeType_StaMd_Mode)3)
# define RTE_TRANSITION_StaMd_Mode ((Rte_ModeType_StaMd_Mode)4)


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
#  define D_FALSE_CNT_LGC ((Boolean)FALSE)
# endif

# if (defined RTE_CONST_D_TRUE_CNT_LGC) || (defined D_TRUE_CNT_LGC)
#  if (!defined RTE_CONST_D_TRUE_CNT_LGC) || (RTE_CONST_D_TRUE_CNT_LGC != TRUE)
#   error "Constant value <D_TRUE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRUE_CNT_LGC (TRUE)
#  define D_TRUE_CNT_LGC ((Boolean)TRUE)
# endif

# if (defined RTE_CONST_D_SFINVMILLI_ULS_F32) || (defined D_SFINVMILLI_ULS_F32)
#  if (!defined RTE_CONST_D_SFINVMILLI_ULS_F32) || (RTE_CONST_D_SFINVMILLI_ULS_F32 != 1000)
#   error "Constant value <D_SFINVMILLI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SFINVMILLI_ULS_F32 (1000)
#  define D_SFINVMILLI_ULS_F32 ((Double)1000)
# endif

# if (defined RTE_CONST_D_180OVRPI_ULS_F32) || (defined D_180OVRPI_ULS_F32)
#  if (!defined RTE_CONST_D_180OVRPI_ULS_F32) || (RTE_CONST_D_180OVRPI_ULS_F32 != 57.295779513082)
#   error "Constant value <D_180OVRPI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_180OVRPI_ULS_F32 (57.295779513082)
#  define D_180OVRPI_ULS_F32 ((Float)57.295779513082)
# endif

# if (defined RTE_CONST_D_2MS_SEC_F32) || (defined D_2MS_SEC_F32)
#  if (!defined RTE_CONST_D_2MS_SEC_F32) || (RTE_CONST_D_2MS_SEC_F32 != 0.002)
#   error "Constant value <D_2MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_SEC_F32 (0.002)
#  define D_2MS_SEC_F32 ((Float)0.002)
# endif

# if (defined RTE_CONST_D_2PI_ULS_F32) || (defined D_2PI_ULS_F32)
#  if (!defined RTE_CONST_D_2PI_ULS_F32) || (RTE_CONST_D_2PI_ULS_F32 != 6.2831853071796)
#   error "Constant value <D_2PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2PI_ULS_F32 (6.2831853071796)
#  define D_2PI_ULS_F32 ((Float)6.2831853071796)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (defined D_MTRTRQCMDHILMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 != 8.8)
#   error "Constant value <D_MTRTRQCMDHILMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 (8.8)
#  define D_MTRTRQCMDHILMT_MTRNM_F32 ((Float)8.8)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32) || (defined D_MTRTRQCMDLOLMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32 != -8.8)
#   error "Constant value <D_MTRTRQCMDLOLMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32 (-8.8)
#  define D_MTRTRQCMDLOLMT_MTRNM_F32 ((Float)-8.8)
# endif

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1)
#  define D_ONE_ULS_F32 ((Float)1)
# endif

# if (defined RTE_CONST_D_PIOVR180_ULS_F32) || (defined D_PIOVR180_ULS_F32)
#  if (!defined RTE_CONST_D_PIOVR180_ULS_F32) || (RTE_CONST_D_PIOVR180_ULS_F32 != 0.0174532925199)
#   error "Constant value <D_PIOVR180_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PIOVR180_ULS_F32 (0.0174532925199)
#  define D_PIOVR180_ULS_F32 ((Float)0.0174532925199)
# endif

# if (defined RTE_CONST_D_PI_ULS_F32) || (defined D_PI_ULS_F32)
#  if (!defined RTE_CONST_D_PI_ULS_F32) || (RTE_CONST_D_PI_ULS_F32 != 3.1415926535898)
#   error "Constant value <D_PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PI_ULS_F32 (3.1415926535898)
#  define D_PI_ULS_F32 ((Float)3.1415926535898)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0)
#  define D_ZERO_ULS_F32 ((Float)0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S16) || (defined D_NEGONE_CNT_S16)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S16) || (RTE_CONST_D_NEGONE_CNT_S16 != -1)
#   error "Constant value <D_NEGONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S16 (-1)
#  define D_NEGONE_CNT_S16 ((SInt16)-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S16) || (defined D_ONE_CNT_S16)
#  if (!defined RTE_CONST_D_ONE_CNT_S16) || (RTE_CONST_D_ONE_CNT_S16 != 1)
#   error "Constant value <D_ONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S16 (1)
#  define D_ONE_CNT_S16 ((SInt16)1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S16) || (defined D_ZERO_CNT_S16)
#  if (!defined RTE_CONST_D_ZERO_CNT_S16) || (RTE_CONST_D_ZERO_CNT_S16 != 0)
#   error "Constant value <D_ZERO_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S16 (0)
#  define D_ZERO_CNT_S16 ((SInt16)0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S32) || (defined D_NEGONE_CNT_S32)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S32) || (RTE_CONST_D_NEGONE_CNT_S32 != -1)
#   error "Constant value <D_NEGONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S32 (-1)
#  define D_NEGONE_CNT_S32 ((SInt32)-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S32) || (defined D_ONE_CNT_S32)
#  if (!defined RTE_CONST_D_ONE_CNT_S32) || (RTE_CONST_D_ONE_CNT_S32 != 1)
#   error "Constant value <D_ONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S32 (1)
#  define D_ONE_CNT_S32 ((SInt32)1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S32) || (defined D_ZERO_CNT_S32)
#  if (!defined RTE_CONST_D_ZERO_CNT_S32) || (RTE_CONST_D_ZERO_CNT_S32 != 0)
#   error "Constant value <D_ZERO_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S32 (0)
#  define D_ZERO_CNT_S32 ((SInt32)0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S8) || (defined D_NEGONE_CNT_S8)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S8) || (RTE_CONST_D_NEGONE_CNT_S8 != -1)
#   error "Constant value <D_NEGONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S8 (-1)
#  define D_NEGONE_CNT_S8 ((SInt8)-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S8) || (defined D_ONE_CNT_S8)
#  if (!defined RTE_CONST_D_ONE_CNT_S8) || (RTE_CONST_D_ONE_CNT_S8 != 1)
#   error "Constant value <D_ONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S8 (1)
#  define D_ONE_CNT_S8 ((SInt8)1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S8) || (defined D_ZERO_CNT_S8)
#  if (!defined RTE_CONST_D_ZERO_CNT_S8) || (RTE_CONST_D_ZERO_CNT_S8 != 0)
#   error "Constant value <D_ZERO_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S8 (0)
#  define D_ZERO_CNT_S8 ((SInt8)0)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U16) || (defined D_ONE_CNT_U16)
#  if (!defined RTE_CONST_D_ONE_CNT_U16) || (RTE_CONST_D_ONE_CNT_U16 != 1u)
#   error "Constant value <D_ONE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U16 (1u)
#  define D_ONE_CNT_U16 ((UInt16)1u)
# endif

# if (defined RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16) || (defined D_RACKTOVEHCNTRINVALID_CNT_U16)
#  if (!defined RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16) || (RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16 != 4095u)
#   error "Constant value <D_RACKTOVEHCNTRINVALID_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16 (4095u)
#  define D_RACKTOVEHCNTRINVALID_CNT_U16 ((UInt16)4095u)
# endif

# if (defined RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16) || (defined D_RACKTOVEHCNTRUNLEARNED_CNT_U16)
#  if (!defined RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16) || (RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16 != 4094u)
#   error "Constant value <D_RACKTOVEHCNTRUNLEARNED_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16 (4094u)
#  define D_RACKTOVEHCNTRUNLEARNED_CNT_U16 ((UInt16)4094u)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U16) || (defined D_ZERO_CNT_U16)
#  if (!defined RTE_CONST_D_ZERO_CNT_U16) || (RTE_CONST_D_ZERO_CNT_U16 != 0u)
#   error "Constant value <D_ZERO_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U16 (0u)
#  define D_ZERO_CNT_U16 ((UInt16)0u)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U32) || (defined D_ONE_CNT_U32)
#  if (!defined RTE_CONST_D_ONE_CNT_U32) || (RTE_CONST_D_ONE_CNT_U32 != 1u)
#   error "Constant value <D_ONE_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U32 (1u)
#  define D_ONE_CNT_U32 ((UInt32)1u)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0u)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0u)
#  define D_ZERO_CNT_U32 ((UInt32)0u)
# endif

# if (defined RTE_CONST_D_MTRPOLESDIV2_CNT_U8) || (defined D_MTRPOLESDIV2_CNT_U8)
#  if (!defined RTE_CONST_D_MTRPOLESDIV2_CNT_U8) || (RTE_CONST_D_MTRPOLESDIV2_CNT_U8 != 3u)
#   error "Constant value <D_MTRPOLESDIV2_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRPOLESDIV2_CNT_U8 (3u)
#  define D_MTRPOLESDIV2_CNT_U8 ((UInt8)3u)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U8) || (defined D_ONE_CNT_U8)
#  if (!defined RTE_CONST_D_ONE_CNT_U8) || (RTE_CONST_D_ONE_CNT_U8 != 1u)
#   error "Constant value <D_ONE_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U8 (1u)
#  define D_ONE_CNT_U8 ((UInt8)1u)
# endif

# if (defined RTE_CONST_D_QUADRANT1_CNT_U8) || (defined D_QUADRANT1_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT1_CNT_U8) || (RTE_CONST_D_QUADRANT1_CNT_U8 != 1u)
#   error "Constant value <D_QUADRANT1_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT1_CNT_U8 (1u)
#  define D_QUADRANT1_CNT_U8 ((UInt8)1u)
# endif

# if (defined RTE_CONST_D_QUADRANT2_CNT_U8) || (defined D_QUADRANT2_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT2_CNT_U8) || (RTE_CONST_D_QUADRANT2_CNT_U8 != 2u)
#   error "Constant value <D_QUADRANT2_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT2_CNT_U8 (2u)
#  define D_QUADRANT2_CNT_U8 ((UInt8)2u)
# endif

# if (defined RTE_CONST_D_QUADRANT3_CNT_U8) || (defined D_QUADRANT3_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT3_CNT_U8) || (RTE_CONST_D_QUADRANT3_CNT_U8 != 3u)
#   error "Constant value <D_QUADRANT3_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT3_CNT_U8 (3u)
#  define D_QUADRANT3_CNT_U8 ((UInt8)3u)
# endif

# if (defined RTE_CONST_D_QUADRANT4_CNT_U8) || (defined D_QUADRANT4_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT4_CNT_U8) || (RTE_CONST_D_QUADRANT4_CNT_U8 != 4u)
#   error "Constant value <D_QUADRANT4_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT4_CNT_U8 (4u)
#  define D_QUADRANT4_CNT_U8 ((UInt8)4u)
# endif

# if (defined RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08) || (defined D_TURNSCNTRPARTNUMINIT_CNT_U08)
#  if (!defined RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08) || (RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08 != 255u)
#   error "Constant value <D_TURNSCNTRPARTNUMINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08 (255u)
#  define D_TURNSCNTRPARTNUMINIT_CNT_U08 ((UInt8)255u)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U8) || (defined D_ZERO_CNT_U8)
#  if (!defined RTE_CONST_D_ZERO_CNT_U8) || (RTE_CONST_D_ZERO_CNT_U8 != 0u)
#   error "Constant value <D_ZERO_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U8 (0u)
#  define D_ZERO_CNT_U8 ((UInt8)0u)
# endif

# if defined T_SINELKPTBL_ULS_F32
#  error "Constant value <T_SINELKPTBL_ULS_F32> conflicts with an already defined symbol."
# else
#  define T_SINELKPTBL_ULS_F32 (Rte_T_SINELKPTBL_ULS_F32)
# endif
extern CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_SINELKPTBL_ULS_F32;

# if defined T_TANLKPTBL_ULS_F32
#  error "Constant value <T_TANLKPTBL_ULS_F32> conflicts with an already defined symbol."
# else
#  define T_TANLKPTBL_ULS_F32 (Rte_T_TANLKPTBL_ULS_F32)
# endif
extern CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_TANLKPTBL_ULS_F32;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_DiagMgr
{
  /* PIM Handles section */
  P2VAR(NTCStrgArray, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_NTCStrgArray;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_DiagMgr, RTE_CONST, RTE_CONST) Rte_Inst_Ap_DiagMgr;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1340195544
#    error "The magic number of the generated file <C:/CMSynergy_Projects/DiagMgr/utp/contract/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1340195544
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
