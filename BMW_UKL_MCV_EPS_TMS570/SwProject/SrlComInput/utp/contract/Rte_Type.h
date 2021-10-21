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
 *     Workspace:  C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComInput/autosar
 *     SW-C Type:  Ap_SrlComInput2
 *  Generated at:  Thu Jun  1 11:56:35 2017
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
#  define D_SVCDFTRXMSGS_CNT_B32 (134217728U)
#  define D_ZERO_CNT_U8 (0U)


# define Rte_TypeDef_AVL_PINA_IDX_ICM
typedef uint16 AVL_PINA_IDX_ICM;
# define AVL_PINA_IDX_ICM_LowerLimit (0U)
# define AVL_PINA_IDX_ICM_UpperLimit (65534U)
# define Rte_InvalidValue_AVL_PINA_IDX_ICM (65535U)
# define InvalidValue_AVL_PINA_IDX_ICM (65535U)

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_CD_0x01
typedef boolean CD_0x01;

# define Rte_TypeDef_CD_0x04
typedef uint8 CD_0x04;
# define CD_0x04_LowerLimit (0U)
# define CD_0x04_UpperLimit (15U)

# define Rte_TypeDef_CD_0x08
typedef uint8 CD_0x08;
# define CD_0x08_LowerLimit (0U)
# define CD_0x08_UpperLimit (255U)

# define Rte_TypeDef_CD_0x16
typedef uint32 CD_0x16;
# define CD_0x16_LowerLimit (0U)
# define CD_0x16_UpperLimit (4194303U)

# define Rte_TypeDef_CRC8
typedef uint8 CRC8;
# define CRC8_LowerLimit (0U)
# define CRC8_UpperLimit (255U)

# define Rte_TypeDef_CRC_V_VEH
typedef uint8 CRC_V_VEH;
# define CRC_V_VEH_LowerLimit (0U)
# define CRC_V_VEH_UpperLimit (255U)

# define Rte_TypeDef_FACT_ASS_STMOM_FTAX
typedef uint8 FACT_ASS_STMOM_FTAX;
# define FACT_ASS_STMOM_FTAX_LowerLimit (0U)
# define FACT_ASS_STMOM_FTAX_UpperLimit (254U)
# define Rte_InvalidValue_FACT_ASS_STMOM_FTAX (255U)
# define InvalidValue_FACT_ASS_STMOM_FTAX (255U)

# define Rte_TypeDef_FACT_CTRR_STMOM_FTAX
typedef uint8 FACT_CTRR_STMOM_FTAX;
# define FACT_CTRR_STMOM_FTAX_LowerLimit (0U)
# define FACT_CTRR_STMOM_FTAX_UpperLimit (254U)
# define Rte_InvalidValue_FACT_CTRR_STMOM_FTAX (255U)
# define InvalidValue_FACT_CTRR_STMOM_FTAX (255U)

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_New_Coding_101
typedef uint8 New_Coding_101;
# define New_Coding_101_LowerLimit (0U)
# define New_Coding_101_UpperLimit (255U)

# define Rte_TypeDef_New_Coding_102
typedef uint8 New_Coding_102;
# define New_Coding_102_LowerLimit (0U)
# define New_Coding_102_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_102 (15U)
# define InvalidValue_New_Coding_102 (15U)

# define Rte_TypeDef_New_Coding_29
typedef uint8 New_Coding_29;
# define New_Coding_29_LowerLimit (0U)
# define New_Coding_29_UpperLimit (255U)

# define Rte_TypeDef_New_Coding_31
typedef uint16 New_Coding_31;
# define New_Coding_31_LowerLimit (0U)
# define New_Coding_31_UpperLimit (65535U)
# define Rte_InvalidValue_New_Coding_31 (65535U)
# define InvalidValue_New_Coding_31 (65535U)

# define Rte_TypeDef_New_Coding_32
typedef uint16 New_Coding_32;
# define New_Coding_32_LowerLimit (0U)
# define New_Coding_32_UpperLimit (4095U)
# define Rte_InvalidValue_New_Coding_32 (4095U)
# define InvalidValue_New_Coding_32 (4095U)

# define Rte_TypeDef_New_Coding_34
typedef uint8 New_Coding_34;
# define New_Coding_34_LowerLimit (0U)
# define New_Coding_34_UpperLimit (255U)

# define Rte_TypeDef_New_Coding_36
typedef uint16 New_Coding_36;
# define New_Coding_36_LowerLimit (0U)
# define New_Coding_36_UpperLimit (65000U)
# define Rte_InvalidValue_New_Coding_36 (65535U)
# define InvalidValue_New_Coding_36 (65535U)

# define Rte_TypeDef_New_Coding_37
typedef uint16 New_Coding_37;
# define New_Coding_37_LowerLimit (0U)
# define New_Coding_37_UpperLimit (4000U)
# define Rte_InvalidValue_New_Coding_37 (4095U)
# define InvalidValue_New_Coding_37 (4095U)

# define Rte_TypeDef_New_Coding_59
typedef uint8 New_Coding_59;
# define New_Coding_59_LowerLimit (0U)
# define New_Coding_59_UpperLimit (255U)

# define Rte_TypeDef_New_Coding_61
typedef uint8 New_Coding_61;
# define New_Coding_61_LowerLimit (0U)
# define New_Coding_61_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_61 (15U)
# define InvalidValue_New_Coding_61 (15U)

# define Rte_TypeDef_OFFS_QUAD_PINA_EPS
typedef uint8 OFFS_QUAD_PINA_EPS;
# define OFFS_QUAD_PINA_EPS_LowerLimit (0U)
# define OFFS_QUAD_PINA_EPS_UpperLimit (254U)
# define Rte_InvalidValue_OFFS_QUAD_PINA_EPS (255U)
# define InvalidValue_OFFS_QUAD_PINA_EPS (255U)

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define SInt16_LowerLimit (-32768)
# define SInt16_UpperLimit (32767)

# define Rte_TypeDef_STMOM_QTA_DV
typedef uint16 STMOM_QTA_DV;
# define STMOM_QTA_DV_LowerLimit (0U)
# define STMOM_QTA_DV_UpperLimit (4000U)
# define Rte_InvalidValue_STMOM_QTA_DV (4095U)
# define InvalidValue_STMOM_QTA_DV (4095U)

# define Rte_TypeDef_TAR_STMOM_DV_ACT
typedef uint16 TAR_STMOM_DV_ACT;
# define TAR_STMOM_DV_ACT_LowerLimit (0U)
# define TAR_STMOM_DV_ACT_UpperLimit (4000U)
# define Rte_InvalidValue_TAR_STMOM_DV_ACT (4095U)
# define InvalidValue_TAR_STMOM_DV_ACT (4095U)

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

# define Rte_TypeDef_V_VEH_COG
typedef uint16 V_VEH_COG;
# define V_VEH_COG_LowerLimit (0U)
# define V_VEH_COG_UpperLimit (22400U)
# define Rte_InvalidValue_V_VEH_COG (65535U)
# define InvalidValue_V_VEH_COG (65535U)

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

# define Rte_TypeDef_ALIV_COU_V
typedef uint8 ALIV_COU_V;
# define ALIV_COU_V_LowerLimit (0U)
# define ALIV_COU_V_UpperLimit (15U)
# define Rte_InvalidValue_ALIV_COU_V (15U)
# define InvalidValue_ALIV_COU_V (15U)
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_DVCO_VEH
typedef uint8 DVCO_VEH;
# define DVCO_VEH_LowerLimit (0U)
# define DVCO_VEH_UpperLimit (7U)
# define Rte_InvalidValue_DVCO_VEH (7U)
# define InvalidValue_DVCO_VEH (7U)
# if (defined RTE_CONST_Cx0_Fahrzeug_steht) || (defined Cx0_Fahrzeug_steht)
#  if (!defined RTE_CONST_Cx0_Fahrzeug_steht) || (RTE_CONST_Cx0_Fahrzeug_steht != 0U)
#   error "Enumeration constant <Cx0_Fahrzeug_steht> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Fahrzeug_steht (0U)
#  define Cx0_Fahrzeug_steht (0U)
# endif
# if (defined RTE_CONST_Cx1_Fahrzeug_faehrt_vorwaerts) || (defined Cx1_Fahrzeug_faehrt_vorwaerts)
#  if (!defined RTE_CONST_Cx1_Fahrzeug_faehrt_vorwaerts) || (RTE_CONST_Cx1_Fahrzeug_faehrt_vorwaerts != 1U)
#   error "Enumeration constant <Cx1_Fahrzeug_faehrt_vorwaerts> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Fahrzeug_faehrt_vorwaerts (1U)
#  define Cx1_Fahrzeug_faehrt_vorwaerts (1U)
# endif
# if (defined RTE_CONST_Cx2_Fahrzeug_faehrt_rueckwaerts) || (defined Cx2_Fahrzeug_faehrt_rueckwaerts)
#  if (!defined RTE_CONST_Cx2_Fahrzeug_faehrt_rueckwaerts) || (RTE_CONST_Cx2_Fahrzeug_faehrt_rueckwaerts != 2U)
#   error "Enumeration constant <Cx2_Fahrzeug_faehrt_rueckwaerts> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Fahrzeug_faehrt_rueckwaerts (2U)
#  define Cx2_Fahrzeug_faehrt_rueckwaerts (2U)
# endif
# if (defined RTE_CONST_Cx3_Fahrzeug_faehrt) || (defined Cx3_Fahrzeug_faehrt)
#  if (!defined RTE_CONST_Cx3_Fahrzeug_faehrt) || (RTE_CONST_Cx3_Fahrzeug_faehrt != 3U)
#   error "Enumeration constant <Cx3_Fahrzeug_faehrt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Fahrzeug_faehrt (3U)
#  define Cx3_Fahrzeug_faehrt (3U)
# endif
# if (defined RTE_CONST_Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt) || (defined Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt)
#  if (!defined RTE_CONST_Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt) || (RTE_CONST_Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt != 4U)
#   error "Enumeration constant <Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt (4U)
#  define Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt (4U)
# endif
# if (defined RTE_CONST_Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt) || (defined Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt)
#  if (!defined RTE_CONST_Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt) || (RTE_CONST_Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt != 5U)
#   error "Enumeration constant <Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt (5U)
#  define Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt (5U)
# endif
# if (defined RTE_CONST_Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt) || (defined Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt)
#  if (!defined RTE_CONST_Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt) || (RTE_CONST_Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt != 6U)
#   error "Enumeration constant <Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt (6U)
#  define Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt (6U)
# endif
# if (defined RTE_CONST_Cx7_Signal_ungueltig) || (defined Cx7_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx7_Signal_ungueltig) || (RTE_CONST_Cx7_Signal_ungueltig != 7U)
#   error "Enumeration constant <Cx7_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Signal_ungueltig (7U)
#  define Cx7_Signal_ungueltig (7U)
# endif

# define Rte_TypeDef_FACT_DMPNG_ADDON_STMOM_FTAX
typedef uint8 FACT_DMPNG_ADDON_STMOM_FTAX;
# define FACT_DMPNG_ADDON_STMOM_FTAX_LowerLimit (0U)
# define FACT_DMPNG_ADDON_STMOM_FTAX_UpperLimit (255U)
# define Rte_InvalidValue_FACT_DMPNG_ADDON_STMOM_FTAX (255U)
# define InvalidValue_FACT_DMPNG_ADDON_STMOM_FTAX (255U)
# if (defined RTE_CONST_CxFD_Reserviert) || (defined CxFD_Reserviert)
#  if (!defined RTE_CONST_CxFD_Reserviert) || (RTE_CONST_CxFD_Reserviert != 253U)
#   error "Enumeration constant <CxFD_Reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFD_Reserviert (253U)
#  define CxFD_Reserviert (253U)
# endif
# if (defined RTE_CONST_CxFE_Reserviert) || (defined CxFE_Reserviert)
#  if (!defined RTE_CONST_CxFE_Reserviert) || (RTE_CONST_CxFE_Reserviert != 254U)
#   error "Enumeration constant <CxFE_Reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFE_Reserviert (254U)
#  define CxFE_Reserviert (254U)
# endif
# if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#   error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#  define CxFF_Signal_unbefuellt (255U)
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
# if (defined RTE_CONST_NTC_Num_IMCLossOfCom) || (defined NTC_Num_IMCLossOfCom)
#  if (!defined RTE_CONST_NTC_Num_IMCLossOfCom) || (RTE_CONST_NTC_Num_IMCLossOfCom != 125U)
#   error "Enumeration constant <NTC_Num_IMCLossOfCom> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IMCLossOfCom (125U)
#  define NTC_Num_IMCLossOfCom (125U)
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
# if (defined RTE_CONST_NTC_Num_ImcSigArbHighOffsetCorrection) || (defined NTC_Num_ImcSigArbHighOffsetCorrection)
#  if (!defined RTE_CONST_NTC_Num_ImcSigArbHighOffsetCorrection) || (RTE_CONST_NTC_Num_ImcSigArbHighOffsetCorrection != 151U)
#   error "Enumeration constant <NTC_Num_ImcSigArbHighOffsetCorrection> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_ImcSigArbHighOffsetCorrection (151U)
#  define NTC_Num_ImcSigArbHighOffsetCorrection (151U)
# endif
# if (defined RTE_CONST_NTC_Num_EcuConfigMismatch) || (defined NTC_Num_EcuConfigMismatch)
#  if (!defined RTE_CONST_NTC_Num_EcuConfigMismatch) || (RTE_CONST_NTC_Num_EcuConfigMismatch != 152U)
#   error "Enumeration constant <NTC_Num_EcuConfigMismatch> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_EcuConfigMismatch (152U)
#  define NTC_Num_EcuConfigMismatch (152U)
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
# if (defined RTE_CONST_NTC_Num_PHAPosnSnsrVsPwrpkDataWrong) || (defined NTC_Num_PHAPosnSnsrVsPwrpkDataWrong)
#  if (!defined RTE_CONST_NTC_Num_PHAPosnSnsrVsPwrpkDataWrong) || (RTE_CONST_NTC_Num_PHAPosnSnsrVsPwrpkDataWrong != 500U)
#   error "Enumeration constant <NTC_Num_PHAPosnSnsrVsPwrpkDataWrong> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500U)
#  define NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500U)
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
# if (defined RTE_CONST_NTC_Num_PHAScratchPadTrf) || (defined NTC_Num_PHAScratchPadTrf)
#  if (!defined RTE_CONST_NTC_Num_PHAScratchPadTrf) || (RTE_CONST_NTC_Num_PHAScratchPadTrf != 503U)
#   error "Enumeration constant <NTC_Num_PHAScratchPadTrf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PHAScratchPadTrf (503U)
#  define NTC_Num_PHAScratchPadTrf (503U)
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

# define Rte_TypeDef_New_Coding_103
typedef uint8 New_Coding_103;
# define New_Coding_103_LowerLimit (0U)
# define New_Coding_103_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_103 (15U)
# define InvalidValue_New_Coding_103 (15U)
# if (defined RTE_CONST_Cx0_Kein_Spannungseinbruch) || (defined Cx0_Kein_Spannungseinbruch)
#  if (!defined RTE_CONST_Cx0_Kein_Spannungseinbruch) || (RTE_CONST_Cx0_Kein_Spannungseinbruch != 0U)
#   error "Enumeration constant <Cx0_Kein_Spannungseinbruch> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Kein_Spannungseinbruch (0U)
#  define Cx0_Kein_Spannungseinbruch (0U)
# endif
# if (defined RTE_CONST_Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1) || (defined Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1)
#  if (!defined RTE_CONST_Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1) || (RTE_CONST_Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1 != 1U)
#   error "Enumeration constant <Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1 (1U)
#  define Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1 (1U)
# endif
# if (defined RTE_CONST_Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2) || (defined Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2)
#  if (!defined RTE_CONST_Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2) || (RTE_CONST_Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2 != 2U)
#   error "Enumeration constant <Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2 (2U)
#  define Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2 (2U)
# endif
# if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#  if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#   error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
# endif
# if (defined RTE_CONST_CxE_Reserviert) || (defined CxE_Reserviert)
#  if (!defined RTE_CONST_CxE_Reserviert) || (RTE_CONST_CxE_Reserviert != 14U)
#   error "Enumeration constant <CxE_Reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Reserviert (14U)
#  define CxE_Reserviert (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#   error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_unbefuellt (15U)
#  define CxF_Signal_unbefuellt (15U)
# endif

# define Rte_TypeDef_New_Coding_104
typedef uint8 New_Coding_104;
# define New_Coding_104_LowerLimit (0U)
# define New_Coding_104_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_104 (15U)
# define InvalidValue_New_Coding_104 (15U)
# if (defined RTE_CONST_Cx0_Motor_steht) || (defined Cx0_Motor_steht)
#  if (!defined RTE_CONST_Cx0_Motor_steht) || (RTE_CONST_Cx0_Motor_steht != 0U)
#   error "Enumeration constant <Cx0_Motor_steht> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Motor_steht (0U)
#  define Cx0_Motor_steht (0U)
# endif
# if (defined RTE_CONST_Cx1_Motor_startet) || (defined Cx1_Motor_startet)
#  if (!defined RTE_CONST_Cx1_Motor_startet) || (RTE_CONST_Cx1_Motor_startet != 1U)
#   error "Enumeration constant <Cx1_Motor_startet> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Motor_startet (1U)
#  define Cx1_Motor_startet (1U)
# endif
# if (defined RTE_CONST_Cx2_Motor_laeuft) || (defined Cx2_Motor_laeuft)
#  if (!defined RTE_CONST_Cx2_Motor_laeuft) || (RTE_CONST_Cx2_Motor_laeuft != 2U)
#   error "Enumeration constant <Cx2_Motor_laeuft> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Motor_laeuft (2U)
#  define Cx2_Motor_laeuft (2U)
# endif
# if (defined RTE_CONST_Cx3_Motor_im_Auslauf) || (defined Cx3_Motor_im_Auslauf)
#  if (!defined RTE_CONST_Cx3_Motor_im_Auslauf) || (RTE_CONST_Cx3_Motor_im_Auslauf != 3U)
#   error "Enumeration constant <Cx3_Motor_im_Auslauf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Motor_im_Auslauf (3U)
#  define Cx3_Motor_im_Auslauf (3U)
# endif
# if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#  if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#   error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
# endif
# if (defined RTE_CONST_CxE_Reserviert) || (defined CxE_Reserviert)
#  if (!defined RTE_CONST_CxE_Reserviert) || (RTE_CONST_CxE_Reserviert != 14U)
#   error "Enumeration constant <CxE_Reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Reserviert (14U)
#  define CxE_Reserviert (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#   error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_unbefuellt (15U)
#  define CxF_Signal_unbefuellt (15U)
# endif

# define Rte_TypeDef_New_Coding_105
typedef uint8 New_Coding_105;
# define New_Coding_105_LowerLimit (0U)
# define New_Coding_105_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_105 (255U)
# define InvalidValue_New_Coding_105 (255U)
# if (defined RTE_CONST_Cx00_Kein_Spannungseinbruch) || (defined Cx00_Kein_Spannungseinbruch)
#  if (!defined RTE_CONST_Cx00_Kein_Spannungseinbruch) || (RTE_CONST_Cx00_Kein_Spannungseinbruch != 0U)
#   error "Enumeration constant <Cx00_Kein_Spannungseinbruch> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx00_Kein_Spannungseinbruch (0U)
#  define Cx00_Kein_Spannungseinbruch (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1) || (defined Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1)
#  if (!defined RTE_CONST_Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1) || (RTE_CONST_Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1 != 0U)
#   error "Enumeration constant <Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1 (0U)
#  define Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1 (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2) || (defined Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2)
#  if (!defined RTE_CONST_Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2) || (RTE_CONST_Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2 != 0U)
#   error "Enumeration constant <Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2 (0U)
#  define Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2 (0U)
# endif
# if (defined RTE_CONST_Cb0xxxx1xx_Spannungsversorgung_48_Volt) || (defined Cb0xxxx1xx_Spannungsversorgung_48_Volt)
#  if (!defined RTE_CONST_Cb0xxxx1xx_Spannungsversorgung_48_Volt) || (RTE_CONST_Cb0xxxx1xx_Spannungsversorgung_48_Volt != 0U)
#   error "Enumeration constant <Cb0xxxx1xx_Spannungsversorgung_48_Volt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxx1xx_Spannungsversorgung_48_Volt (0U)
#  define Cb0xxxx1xx_Spannungsversorgung_48_Volt (0U)
# endif
# if (defined RTE_CONST_CxFD_Reserviert) || (defined CxFD_Reserviert)
#  if (!defined RTE_CONST_CxFD_Reserviert) || (RTE_CONST_CxFD_Reserviert != 253U)
#   error "Enumeration constant <CxFD_Reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFD_Reserviert (253U)
#  define CxFD_Reserviert (253U)
# endif
# if (defined RTE_CONST_CxFE_Reserviert) || (defined CxFE_Reserviert)
#  if (!defined RTE_CONST_CxFE_Reserviert) || (RTE_CONST_CxFE_Reserviert != 254U)
#   error "Enumeration constant <CxFE_Reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFE_Reserviert (254U)
#  define CxFE_Reserviert (254U)
# endif
# if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#   error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#  define CxFF_Signal_unbefuellt (255U)
# endif

# define Rte_TypeDef_New_Coding_106
typedef uint8 New_Coding_106;
# define New_Coding_106_LowerLimit (0U)
# define New_Coding_106_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_106 (15U)
# define InvalidValue_New_Coding_106 (15U)
# if (defined RTE_CONST_Cb0xx1_Selbstlaufgrenze_unterschritten) || (defined Cb0xx1_Selbstlaufgrenze_unterschritten)
#  if (!defined RTE_CONST_Cb0xx1_Selbstlaufgrenze_unterschritten) || (RTE_CONST_Cb0xx1_Selbstlaufgrenze_unterschritten != 0U)
#   error "Enumeration constant <Cb0xx1_Selbstlaufgrenze_unterschritten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xx1_Selbstlaufgrenze_unterschritten (0U)
#  define Cb0xx1_Selbstlaufgrenze_unterschritten (0U)
# endif
# if (defined RTE_CONST_Cb0xx0_Selbstlaufgrenze_nicht_unterschritten) || (defined Cb0xx0_Selbstlaufgrenze_nicht_unterschritten)
#  if (!defined RTE_CONST_Cb0xx0_Selbstlaufgrenze_nicht_unterschritten) || (RTE_CONST_Cb0xx0_Selbstlaufgrenze_nicht_unterschritten != 0U)
#   error "Enumeration constant <Cb0xx0_Selbstlaufgrenze_nicht_unterschritten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xx0_Selbstlaufgrenze_nicht_unterschritten (0U)
#  define Cb0xx0_Selbstlaufgrenze_nicht_unterschritten (0U)
# endif
# if (defined RTE_CONST_Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten) || (defined Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten)
#  if (!defined RTE_CONST_Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten) || (RTE_CONST_Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten != 0U)
#   error "Enumeration constant <Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten (0U)
#  define Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten (0U)
# endif
# if (defined RTE_CONST_Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar) || (defined Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar)
#  if (!defined RTE_CONST_Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar) || (RTE_CONST_Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar != 0U)
#   error "Enumeration constant <Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar (0U)
#  define Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar (0U)
# endif
# if (defined RTE_CONST_Cb01xx_Retry_Anforderung_Fahrzeug_halten) || (defined Cb01xx_Retry_Anforderung_Fahrzeug_halten)
#  if (!defined RTE_CONST_Cb01xx_Retry_Anforderung_Fahrzeug_halten) || (RTE_CONST_Cb01xx_Retry_Anforderung_Fahrzeug_halten != 0U)
#   error "Enumeration constant <Cb01xx_Retry_Anforderung_Fahrzeug_halten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb01xx_Retry_Anforderung_Fahrzeug_halten (0U)
#  define Cb01xx_Retry_Anforderung_Fahrzeug_halten (0U)
# endif
# if (defined RTE_CONST_Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten) || (defined Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten)
#  if (!defined RTE_CONST_Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten) || (RTE_CONST_Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten != 0U)
#   error "Enumeration constant <Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten (0U)
#  define Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten (0U)
# endif
# if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#  if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#   error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
# endif
# if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#  if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#   error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#  define CxE_Funktion_meldet_Fehler (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#   error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_unbefuellt (15U)
#  define CxF_Signal_unbefuellt (15U)
# endif

# define Rte_TypeDef_New_Coding_107
typedef uint8 New_Coding_107;
# define New_Coding_107_LowerLimit (0U)
# define New_Coding_107_UpperLimit (3U)
# define Rte_InvalidValue_New_Coding_107 (3U)
# define InvalidValue_New_Coding_107 (3U)
# if (defined RTE_CONST_Cx0_Kein_Ankuendigung) || (defined Cx0_Kein_Ankuendigung)
#  if (!defined RTE_CONST_Cx0_Kein_Ankuendigung) || (RTE_CONST_Cx0_Kein_Ankuendigung != 0U)
#   error "Enumeration constant <Cx0_Kein_Ankuendigung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Kein_Ankuendigung (0U)
#  define Cx0_Kein_Ankuendigung (0U)
# endif
# if (defined RTE_CONST_Cx1_Ankuendigung_MSA_Motorstopp) || (defined Cx1_Ankuendigung_MSA_Motorstopp)
#  if (!defined RTE_CONST_Cx1_Ankuendigung_MSA_Motorstopp) || (RTE_CONST_Cx1_Ankuendigung_MSA_Motorstopp != 1U)
#   error "Enumeration constant <Cx1_Ankuendigung_MSA_Motorstopp> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Ankuendigung_MSA_Motorstopp (1U)
#  define Cx1_Ankuendigung_MSA_Motorstopp (1U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_New_Coding_108
typedef uint8 New_Coding_108;
# define New_Coding_108_LowerLimit (0U)
# define New_Coding_108_UpperLimit (3U)
# define Rte_InvalidValue_New_Coding_108 (3U)
# define InvalidValue_New_Coding_108 (3U)
# if (defined RTE_CONST_Cx0_Kein_E_Maschine_verfuegbar) || (defined Cx0_Kein_E_Maschine_verfuegbar)
#  if (!defined RTE_CONST_Cx0_Kein_E_Maschine_verfuegbar) || (RTE_CONST_Cx0_Kein_E_Maschine_verfuegbar != 0U)
#   error "Enumeration constant <Cx0_Kein_E_Maschine_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Kein_E_Maschine_verfuegbar (0U)
#  define Cx0_Kein_E_Maschine_verfuegbar (0U)
# endif
# if (defined RTE_CONST_Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv) || (defined Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv)
#  if (!defined RTE_CONST_Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv) || (RTE_CONST_Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv != 1U)
#   error "Enumeration constant <Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv (1U)
#  define Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv (1U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_New_Coding_109
typedef uint8 New_Coding_109;
# define New_Coding_109_LowerLimit (0U)
# define New_Coding_109_UpperLimit (3U)
# define Rte_InvalidValue_New_Coding_109 (3U)
# define InvalidValue_New_Coding_109 (3U)
# if (defined RTE_CONST_Cx0_ausschalten) || (defined Cx0_ausschalten)
#  if (!defined RTE_CONST_Cx0_ausschalten) || (RTE_CONST_Cx0_ausschalten != 0U)
#   error "Enumeration constant <Cx0_ausschalten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_ausschalten (0U)
#  define Cx0_ausschalten (0U)
# endif
# if (defined RTE_CONST_Cx1_einschalten) || (defined Cx1_einschalten)
#  if (!defined RTE_CONST_Cx1_einschalten) || (RTE_CONST_Cx1_einschalten != 1U)
#   error "Enumeration constant <Cx1_einschalten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_einschalten (1U)
#  define Cx1_einschalten (1U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_New_Coding_30
typedef uint8 New_Coding_30;
# define New_Coding_30_LowerLimit (0U)
# define New_Coding_30_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_30 (15U)
# define InvalidValue_New_Coding_30 (15U)
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_New_Coding_33
typedef uint8 New_Coding_33;
# define New_Coding_33_LowerLimit (0U)
# define New_Coding_33_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_33 (15U)
# define InvalidValue_New_Coding_33 (15U)
# if (defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__) || (defined Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__)
#  if (!defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__) || (RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__ != 1U)
#   error "Enumeration constant <Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__ (1U)
#  define Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__ (1U)
# endif
# if (defined RTE_CONST_Cx2_Signalwert_ist_gueltig__) || (defined Cx2_Signalwert_ist_gueltig__)
#  if (!defined RTE_CONST_Cx2_Signalwert_ist_gueltig__) || (RTE_CONST_Cx2_Signalwert_ist_gueltig__ != 2U)
#   error "Enumeration constant <Cx2_Signalwert_ist_gueltig__> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Signalwert_ist_gueltig__ (2U)
#  define Cx2_Signalwert_ist_gueltig__ (2U)
# endif
# if (defined RTE_CONST_Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__) || (defined Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__)
#  if (!defined RTE_CONST_Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__) || (RTE_CONST_Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__ != 3U)
#   error "Enumeration constant <Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__ (3U)
#  define Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__ (3U)
# endif
# if (defined RTE_CONST_Cx4_Reserved) || (defined Cx4_Reserved)
#  if (!defined RTE_CONST_Cx4_Reserved) || (RTE_CONST_Cx4_Reserved != 4U)
#   error "Enumeration constant <Cx4_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Reserved (4U)
#  define Cx4_Reserved (4U)
# endif
# if (defined RTE_CONST_Cx6_Signalwert_ist_ungueltig__) || (defined Cx6_Signalwert_ist_ungueltig__)
#  if (!defined RTE_CONST_Cx6_Signalwert_ist_ungueltig__) || (RTE_CONST_Cx6_Signalwert_ist_ungueltig__ != 6U)
#   error "Enumeration constant <Cx6_Signalwert_ist_ungueltig__> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Signalwert_ist_ungueltig__ (6U)
#  define Cx6_Signalwert_ist_ungueltig__ (6U)
# endif
# if (defined RTE_CONST_Cx7_Reserved) || (defined Cx7_Reserved)
#  if (!defined RTE_CONST_Cx7_Reserved) || (RTE_CONST_Cx7_Reserved != 7U)
#   error "Enumeration constant <Cx7_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Reserved (7U)
#  define Cx7_Reserved (7U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung__) || (defined Cx8_Initialisierung__)
#  if (!defined RTE_CONST_Cx8_Initialisierung__) || (RTE_CONST_Cx8_Initialisierung__ != 8U)
#   error "Enumeration constant <Cx8_Initialisierung__> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung__ (8U)
#  define Cx8_Initialisierung__ (8U)
# endif
# if (defined RTE_CONST_Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer) || (defined Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer) || (RTE_CONST_Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer != 9U)
#   error "Enumeration constant <Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer (9U)
#  define Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer (9U)
# endif
# if (defined RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer) || (defined CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer) || (RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer != 10U)
#   error "Enumeration constant <CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
#  define CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
# endif
# if (defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (defined CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer != 11U)
#   error "Enumeration constant <CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#  define CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
# endif
# if (defined RTE_CONST_CxC_Ersatzwert__Abgleichwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer) || (defined CxC_Ersatzwert__Abgleichwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxC_Ersatzwert__Abgleichwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer) || (RTE_CONST_CxC_Ersatzwert__Abgleichwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer != 12U)
#   error "Enumeration constant <CxC_Ersatzwert__Abgleichwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxC_Ersatzwert__Abgleichwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer (12U)
#  define CxC_Ersatzwert__Abgleichwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer (12U)
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

# define Rte_TypeDef_New_Coding_35
typedef uint8 New_Coding_35;
# define New_Coding_35_LowerLimit (0U)
# define New_Coding_35_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_35 (15U)
# define InvalidValue_New_Coding_35 (15U)
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_New_Coding_38
typedef uint8 New_Coding_38;
# define New_Coding_38_LowerLimit (0U)
# define New_Coding_38_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_38 (15U)
# define InvalidValue_New_Coding_38 (15U)
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
# if (defined RTE_CONST_Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt) || (defined Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt)
#  if (!defined RTE_CONST_Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt) || (RTE_CONST_Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt != 3U)
#   error "Enumeration constant <Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt (3U)
#  define Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt (3U)
# endif
# if (defined RTE_CONST_Cx4_Reserved) || (defined Cx4_Reserved)
#  if (!defined RTE_CONST_Cx4_Reserved) || (RTE_CONST_Cx4_Reserved != 4U)
#   error "Enumeration constant <Cx4_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Reserved (4U)
#  define Cx4_Reserved (4U)
# endif
# if (defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (defined Cx6_Signalwert_ist_ungueltig)
#  if (!defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (RTE_CONST_Cx6_Signalwert_ist_ungueltig != 6U)
#   error "Enumeration constant <Cx6_Signalwert_ist_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Signalwert_ist_ungueltig (6U)
#  define Cx6_Signalwert_ist_ungueltig (6U)
# endif
# if (defined RTE_CONST_Cx7_Reserved) || (defined Cx7_Reserved)
#  if (!defined RTE_CONST_Cx7_Reserved) || (RTE_CONST_Cx7_Reserved != 7U)
#   error "Enumeration constant <Cx7_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Reserved (7U)
#  define Cx7_Reserved (7U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#  if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#   error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung (8U)
#  define Cx8_Initialisierung (8U)
# endif
# if (defined RTE_CONST_Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer) || (defined Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer) || (RTE_CONST_Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer != 9U)
#   error "Enumeration constant <Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer (9U)
#  define Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer (9U)
# endif
# if (defined RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer) || (defined CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer) || (RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer != 10U)
#   error "Enumeration constant <CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
#  define CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
# endif
# if (defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (defined CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer != 11U)
#   error "Enumeration constant <CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#  define CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
# endif
# if (defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer) || (defined CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer) || (RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer != 12U)
#   error "Enumeration constant <CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer (12U)
#  define CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer (12U)
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

# define Rte_TypeDef_New_Coding_60
typedef uint8 New_Coding_60;
# define New_Coding_60_LowerLimit (0U)
# define New_Coding_60_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_60 (15U)
# define InvalidValue_New_Coding_60 (15U)
# if (defined RTE_CONST_Cx0_Keine_Kommunikation) || (defined Cx0_Keine_Kommunikation)
#  if (!defined RTE_CONST_Cx0_Keine_Kommunikation) || (RTE_CONST_Cx0_Keine_Kommunikation != 0U)
#   error "Enumeration constant <Cx0_Keine_Kommunikation> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Keine_Kommunikation (0U)
#  define Cx0_Keine_Kommunikation (0U)
# endif
# if (defined RTE_CONST_Cx1_Kom_Parken_BN_niO) || (defined Cx1_Kom_Parken_BN_niO)
#  if (!defined RTE_CONST_Cx1_Kom_Parken_BN_niO) || (RTE_CONST_Cx1_Kom_Parken_BN_niO != 1U)
#   error "Enumeration constant <Cx1_Kom_Parken_BN_niO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Kom_Parken_BN_niO (1U)
#  define Cx1_Kom_Parken_BN_niO (1U)
# endif
# if (defined RTE_CONST_Cx2_Kom_Parken_BN_iO) || (defined Cx2_Kom_Parken_BN_iO)
#  if (!defined RTE_CONST_Cx2_Kom_Parken_BN_iO) || (RTE_CONST_Cx2_Kom_Parken_BN_iO != 2U)
#   error "Enumeration constant <Cx2_Kom_Parken_BN_iO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Kom_Parken_BN_iO (2U)
#  define Cx2_Kom_Parken_BN_iO (2U)
# endif
# if (defined RTE_CONST_Cx3_Kom_Standfunktionen_Kunde_nicht_im_FZG) || (defined Cx3_Kom_Standfunktionen_Kunde_nicht_im_FZG)
#  if (!defined RTE_CONST_Cx3_Kom_Standfunktionen_Kunde_nicht_im_FZG) || (RTE_CONST_Cx3_Kom_Standfunktionen_Kunde_nicht_im_FZG != 3U)
#   error "Enumeration constant <Cx3_Kom_Standfunktionen_Kunde_nicht_im_FZG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Kom_Standfunktionen_Kunde_nicht_im_FZG (3U)
#  define Cx3_Kom_Standfunktionen_Kunde_nicht_im_FZG (3U)
# endif
# if (defined RTE_CONST_Cx4_reserviert) || (defined Cx4_reserviert)
#  if (!defined RTE_CONST_Cx4_reserviert) || (RTE_CONST_Cx4_reserviert != 4U)
#   error "Enumeration constant <Cx4_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_reserviert (4U)
#  define Cx4_reserviert (4U)
# endif
# if (defined RTE_CONST_Cx5_Kom_Wohnen) || (defined Cx5_Kom_Wohnen)
#  if (!defined RTE_CONST_Cx5_Kom_Wohnen) || (RTE_CONST_Cx5_Kom_Wohnen != 5U)
#   error "Enumeration constant <Cx5_Kom_Wohnen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx5_Kom_Wohnen (5U)
#  define Cx5_Kom_Wohnen (5U)
# endif
# if (defined RTE_CONST_Cx6_reserviert) || (defined Cx6_reserviert)
#  if (!defined RTE_CONST_Cx6_reserviert) || (RTE_CONST_Cx6_reserviert != 6U)
#   error "Enumeration constant <Cx6_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_reserviert (6U)
#  define Cx6_reserviert (6U)
# endif
# if (defined RTE_CONST_Cx7_Kom_Pruefen_Analyse_Diagnose) || (defined Cx7_Kom_Pruefen_Analyse_Diagnose)
#  if (!defined RTE_CONST_Cx7_Kom_Pruefen_Analyse_Diagnose) || (RTE_CONST_Cx7_Kom_Pruefen_Analyse_Diagnose != 7U)
#   error "Enumeration constant <Cx7_Kom_Pruefen_Analyse_Diagnose> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Kom_Pruefen_Analyse_Diagnose (7U)
#  define Cx7_Kom_Pruefen_Analyse_Diagnose (7U)
# endif
# if (defined RTE_CONST_Cx8_Kom_Fahrbereitschaft_herstellen) || (defined Cx8_Kom_Fahrbereitschaft_herstellen)
#  if (!defined RTE_CONST_Cx8_Kom_Fahrbereitschaft_herstellen) || (RTE_CONST_Cx8_Kom_Fahrbereitschaft_herstellen != 8U)
#   error "Enumeration constant <Cx8_Kom_Fahrbereitschaft_herstellen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Kom_Fahrbereitschaft_herstellen (8U)
#  define Cx8_Kom_Fahrbereitschaft_herstellen (8U)
# endif
# if (defined RTE_CONST_Cx9_reserviert) || (defined Cx9_reserviert)
#  if (!defined RTE_CONST_Cx9_reserviert) || (RTE_CONST_Cx9_reserviert != 9U)
#   error "Enumeration constant <Cx9_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx9_reserviert (9U)
#  define Cx9_reserviert (9U)
# endif
# if (defined RTE_CONST_CxA_Kom_Fahren) || (defined CxA_Kom_Fahren)
#  if (!defined RTE_CONST_CxA_Kom_Fahren) || (RTE_CONST_CxA_Kom_Fahren != 10U)
#   error "Enumeration constant <CxA_Kom_Fahren> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA_Kom_Fahren (10U)
#  define CxA_Kom_Fahren (10U)
# endif
# if (defined RTE_CONST_CxB_reserviert) || (defined CxB_reserviert)
#  if (!defined RTE_CONST_CxB_reserviert) || (RTE_CONST_CxB_reserviert != 11U)
#   error "Enumeration constant <CxB_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxB_reserviert (11U)
#  define CxB_reserviert (11U)
# endif
# if (defined RTE_CONST_CxC_Kom_Fahrbereitschaft_beenden) || (defined CxC_Kom_Fahrbereitschaft_beenden)
#  if (!defined RTE_CONST_CxC_Kom_Fahrbereitschaft_beenden) || (RTE_CONST_CxC_Kom_Fahrbereitschaft_beenden != 12U)
#   error "Enumeration constant <CxC_Kom_Fahrbereitschaft_beenden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxC_Kom_Fahrbereitschaft_beenden (12U)
#  define CxC_Kom_Fahrbereitschaft_beenden (12U)
# endif
# if (defined RTE_CONST_CxD_reserviert) || (defined CxD_reserviert)
#  if (!defined RTE_CONST_CxD_reserviert) || (RTE_CONST_CxD_reserviert != 13U)
#   error "Enumeration constant <CxD_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_reserviert (13U)
#  define CxD_reserviert (13U)
# endif
# if (defined RTE_CONST_CxE_reserviert) || (defined CxE_reserviert)
#  if (!defined RTE_CONST_CxE_reserviert) || (RTE_CONST_CxE_reserviert != 14U)
#   error "Enumeration constant <CxE_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_reserviert (14U)
#  define CxE_reserviert (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#   error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_unbefuellt (15U)
#  define CxF_Signal_unbefuellt (15U)
# endif

# define Rte_TypeDef_New_Coding_62
typedef uint32 New_Coding_62;
# define New_Coding_62_LowerLimit (0U)
# define New_Coding_62_UpperLimit (4294967295U)
# define Rte_InvalidValue_New_Coding_62 (4294967295U)
# define InvalidValue_New_Coding_62 (4294967295U)
# if (defined RTE_CONST_CxFFFFFFFF_Signal_unbefuellt) || (defined CxFFFFFFFF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxFFFFFFFF_Signal_unbefuellt) || (RTE_CONST_CxFFFFFFFF_Signal_unbefuellt != 4294967295U)
#   error "Enumeration constant <CxFFFFFFFF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFFFFFFFF_Signal_unbefuellt (4294967295U)
#  define CxFFFFFFFF_Signal_unbefuellt (4294967295U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1_Konfiguration_ein) || (defined Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1_Konfiguration_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1_Konfiguration_ein) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1_Konfiguration_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1_Konfiguration_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1_Konfiguration_ein (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1_Konfiguration_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0_Konfiguration_aus) || (defined Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0_Konfiguration_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0_Konfiguration_aus) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0_Konfiguration_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0_Konfiguration_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0_Konfiguration_aus (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0_Konfiguration_aus (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx1x_Ethernet_Infrastruktur_ein) || (defined Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx1x_Ethernet_Infrastruktur_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx1x_Ethernet_Infrastruktur_ein) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx1x_Ethernet_Infrastruktur_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx1x_Ethernet_Infrastruktur_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx1x_Ethernet_Infrastruktur_ein (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx1x_Ethernet_Infrastruktur_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx0x_Ethernet_Infrastruktur_aus) || (defined Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx0x_Ethernet_Infrastruktur_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx0x_Ethernet_Infrastruktur_aus) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx0x_Ethernet_Infrastruktur_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx0x_Ethernet_Infrastruktur_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx0x_Ethernet_Infrastruktur_aus (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx0x_Ethernet_Infrastruktur_aus (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxx1xxxxxxxx_Klimabetrieb_ein) || (defined Cb0xxxxxxxxxxxxxxxxxxxxxx1xxxxxxxx_Klimabetrieb_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxx1xxxxxxxx_Klimabetrieb_ein) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxx1xxxxxxxx_Klimabetrieb_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxxxx1xxxxxxxx_Klimabetrieb_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxx1xxxxxxxx_Klimabetrieb_ein (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxxxx1xxxxxxxx_Klimabetrieb_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxx0xxxxxxxx_Klimabetrieb_aus) || (defined Cb0xxxxxxxxxxxxxxxxxxxxxx0xxxxxxxx_Klimabetrieb_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxx0xxxxxxxx_Klimabetrieb_aus) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxx0xxxxxxxx_Klimabetrieb_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxxxx0xxxxxxxx_Klimabetrieb_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxxx0xxxxxxxx_Klimabetrieb_aus (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxxxx0xxxxxxxx_Klimabetrieb_aus (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxx1xxxxxxxxx_Entertainmentbetrieb_ein) || (defined Cb0xxxxxxxxxxxxxxxxxxxxx1xxxxxxxxx_Entertainmentbetrieb_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxx1xxxxxxxxx_Entertainmentbetrieb_ein) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxx1xxxxxxxxx_Entertainmentbetrieb_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxxx1xxxxxxxxx_Entertainmentbetrieb_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxx1xxxxxxxxx_Entertainmentbetrieb_ein (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxxx1xxxxxxxxx_Entertainmentbetrieb_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxx0xxxxxxxxx_Entertainmentbetrieb_aus) || (defined Cb0xxxxxxxxxxxxxxxxxxxxx0xxxxxxxxx_Entertainmentbetrieb_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxx0xxxxxxxxx_Entertainmentbetrieb_aus) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxx0xxxxxxxxx_Entertainmentbetrieb_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxxx0xxxxxxxxx_Entertainmentbetrieb_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxxx0xxxxxxxxx_Entertainmentbetrieb_aus (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxxx0xxxxxxxxx_Entertainmentbetrieb_aus (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxx1xxxxxxxxxx_Externe_Kommunikation_ein) || (defined Cb0xxxxxxxxxxxxxxxxxxxx1xxxxxxxxxx_Externe_Kommunikation_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxx1xxxxxxxxxx_Externe_Kommunikation_ein) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxx1xxxxxxxxxx_Externe_Kommunikation_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxx1xxxxxxxxxx_Externe_Kommunikation_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxx1xxxxxxxxxx_Externe_Kommunikation_ein (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxx1xxxxxxxxxx_Externe_Kommunikation_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxx0xxxxxxxxxx_Externe_Kommunikation_aus) || (defined Cb0xxxxxxxxxxxxxxxxxxxx0xxxxxxxxxx_Externe_Kommunikation_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxx0xxxxxxxxxx_Externe_Kommunikation_aus) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxx0xxxxxxxxxx_Externe_Kommunikation_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxxxx0xxxxxxxxxx_Externe_Kommunikation_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxxxx0xxxxxxxxxx_Externe_Kommunikation_aus (0U)
#  define Cb0xxxxxxxxxxxxxxxxxxxx0xxxxxxxxxx_Externe_Kommunikation_aus (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxx1xxxxxxxxxxxx_Assistenz_Parken_high_ein) || (defined Cb0xxxxxxxxxxxxxxxxxx1xxxxxxxxxxxx_Assistenz_Parken_high_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxx1xxxxxxxxxxxx_Assistenz_Parken_high_ein) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxx1xxxxxxxxxxxx_Assistenz_Parken_high_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxx1xxxxxxxxxxxx_Assistenz_Parken_high_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxx1xxxxxxxxxxxx_Assistenz_Parken_high_ein (0U)
#  define Cb0xxxxxxxxxxxxxxxxxx1xxxxxxxxxxxx_Assistenz_Parken_high_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxx0xxxxxxxxxxxx_Assistenz_Parken_high_aus) || (defined Cb0xxxxxxxxxxxxxxxxxx0xxxxxxxxxxxx_Assistenz_Parken_high_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxxxxx0xxxxxxxxxxxx_Assistenz_Parken_high_aus) || (RTE_CONST_Cb0xxxxxxxxxxxxxxxxxx0xxxxxxxxxxxx_Assistenz_Parken_high_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxxxxx0xxxxxxxxxxxx_Assistenz_Parken_high_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxxxxx0xxxxxxxxxxxx_Assistenz_Parken_high_aus (0U)
#  define Cb0xxxxxxxxxxxxxxxxxx0xxxxxxxxxxxx_Assistenz_Parken_high_aus (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxx1xxxxxxxxxxxxxxx_Laden_ein) || (defined Cb0xxxxxxxxxxxxxxx1xxxxxxxxxxxxxxx_Laden_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxx1xxxxxxxxxxxxxxx_Laden_ein) || (RTE_CONST_Cb0xxxxxxxxxxxxxxx1xxxxxxxxxxxxxxx_Laden_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxx1xxxxxxxxxxxxxxx_Laden_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxx1xxxxxxxxxxxxxxx_Laden_ein (0U)
#  define Cb0xxxxxxxxxxxxxxx1xxxxxxxxxxxxxxx_Laden_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxxx0xxxxxxxxxxxxxxx_Laden_aus) || (defined Cb0xxxxxxxxxxxxxxx0xxxxxxxxxxxxxxx_Laden_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxxx0xxxxxxxxxxxxxxx_Laden_aus) || (RTE_CONST_Cb0xxxxxxxxxxxxxxx0xxxxxxxxxxxxxxx_Laden_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxxx0xxxxxxxxxxxxxxx_Laden_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxxx0xxxxxxxxxxxxxxx_Laden_aus (0U)
#  define Cb0xxxxxxxxxxxxxxx0xxxxxxxxxxxxxxx_Laden_aus (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxx1xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_ein) || (defined Cb0xxxxxxxxxxxxxx1xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxx1xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_ein) || (RTE_CONST_Cb0xxxxxxxxxxxxxx1xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxx1xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxx1xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_ein (0U)
#  define Cb0xxxxxxxxxxxxxx1xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxxxxx0xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_aus) || (defined Cb0xxxxxxxxxxxxxx0xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxxxxx0xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_aus) || (RTE_CONST_Cb0xxxxxxxxxxxxxx0xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxxxxx0xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxxxxx0xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_aus (0U)
#  define Cb0xxxxxxxxxxxxxx0xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_aus (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx1xxxxxxxxxxxxxxxxxxx_Licht_ein) || (defined Cb0xxxxxxxxxxx1xxxxxxxxxxxxxxxxxxx_Licht_ein)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx1xxxxxxxxxxxxxxxxxxx_Licht_ein) || (RTE_CONST_Cb0xxxxxxxxxxx1xxxxxxxxxxxxxxxxxxx_Licht_ein != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx1xxxxxxxxxxxxxxxxxxx_Licht_ein> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx1xxxxxxxxxxxxxxxxxxx_Licht_ein (0U)
#  define Cb0xxxxxxxxxxx1xxxxxxxxxxxxxxxxxxx_Licht_ein (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx0xxxxxxxxxxxxxxxxxxx_Licht_aus) || (defined Cb0xxxxxxxxxxx0xxxxxxxxxxxxxxxxxxx_Licht_aus)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx0xxxxxxxxxxxxxxxxxxx_Licht_aus) || (RTE_CONST_Cb0xxxxxxxxxxx0xxxxxxxxxxxxxxxxxxx_Licht_aus != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx0xxxxxxxxxxxxxxxxxxx_Licht_aus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx0xxxxxxxxxxxxxxxxxxx_Licht_aus (0U)
#  define Cb0xxxxxxxxxxx0xxxxxxxxxxxxxxxxxxx_Licht_aus (0U)
# endif

# define Rte_TypeDef_New_Coding_63
typedef uint8 New_Coding_63;
# define New_Coding_63_LowerLimit (0U)
# define New_Coding_63_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_63 (15U)
# define InvalidValue_New_Coding_63 (15U)
# if (defined RTE_CONST_Cx2_Signalwert_gueltig) || (defined Cx2_Signalwert_gueltig)
#  if (!defined RTE_CONST_Cx2_Signalwert_gueltig) || (RTE_CONST_Cx2_Signalwert_gueltig != 2U)
#   error "Enumeration constant <Cx2_Signalwert_gueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Signalwert_gueltig (2U)
#  define Cx2_Signalwert_gueltig (2U)
# endif
# if (defined RTE_CONST_Cx3_Signalwert_eingeschraenkt_gueltig) || (defined Cx3_Signalwert_eingeschraenkt_gueltig)
#  if (!defined RTE_CONST_Cx3_Signalwert_eingeschraenkt_gueltig) || (RTE_CONST_Cx3_Signalwert_eingeschraenkt_gueltig != 3U)
#   error "Enumeration constant <Cx3_Signalwert_eingeschraenkt_gueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signalwert_eingeschraenkt_gueltig (3U)
#  define Cx3_Signalwert_eingeschraenkt_gueltig (3U)
# endif
# if (defined RTE_CONST_Cx6_Reserviert_fuer_die_nicht_umgesetzte_Kennung__Fehler_) || (defined Cx6_Reserviert_fuer_die_nicht_umgesetzte_Kennung__Fehler_)
#  if (!defined RTE_CONST_Cx6_Reserviert_fuer_die_nicht_umgesetzte_Kennung__Fehler_) || (RTE_CONST_Cx6_Reserviert_fuer_die_nicht_umgesetzte_Kennung__Fehler_ != 6U)
#   error "Enumeration constant <Cx6_Reserviert_fuer_die_nicht_umgesetzte_Kennung__Fehler_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Reserviert_fuer_die_nicht_umgesetzte_Kennung__Fehler_ (6U)
#  define Cx6_Reserviert_fuer_die_nicht_umgesetzte_Kennung__Fehler_ (6U)
# endif
# if (defined RTE_CONST_CxE_Wert_nicht_verfuegbar) || (defined CxE_Wert_nicht_verfuegbar)
#  if (!defined RTE_CONST_CxE_Wert_nicht_verfuegbar) || (RTE_CONST_CxE_Wert_nicht_verfuegbar != 14U)
#   error "Enumeration constant <CxE_Wert_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Wert_nicht_verfuegbar (14U)
#  define CxE_Wert_nicht_verfuegbar (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#   error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_unbefuellt (15U)
#  define CxF_Signal_unbefuellt (15U)
# endif

# define Rte_TypeDef_New_Coding_64
typedef uint8 New_Coding_64;
# define New_Coding_64_LowerLimit (0U)
# define New_Coding_64_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_64 (15U)
# define InvalidValue_New_Coding_64 (15U)
# if (defined RTE_CONST_Cx0_reserviert) || (defined Cx0_reserviert)
#  if (!defined RTE_CONST_Cx0_reserviert) || (RTE_CONST_Cx0_reserviert != 0U)
#   error "Enumeration constant <Cx0_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_reserviert (0U)
#  define Cx0_reserviert (0U)
# endif
# if (defined RTE_CONST_Cx1_Parken_BN_niO) || (defined Cx1_Parken_BN_niO)
#  if (!defined RTE_CONST_Cx1_Parken_BN_niO) || (RTE_CONST_Cx1_Parken_BN_niO != 1U)
#   error "Enumeration constant <Cx1_Parken_BN_niO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Parken_BN_niO (1U)
#  define Cx1_Parken_BN_niO (1U)
# endif
# if (defined RTE_CONST_Cx2_Parken_BN_iO) || (defined Cx2_Parken_BN_iO)
#  if (!defined RTE_CONST_Cx2_Parken_BN_iO) || (RTE_CONST_Cx2_Parken_BN_iO != 2U)
#   error "Enumeration constant <Cx2_Parken_BN_iO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Parken_BN_iO (2U)
#  define Cx2_Parken_BN_iO (2U)
# endif
# if (defined RTE_CONST_Cx3_Standfunktionen_Kunde_nicht_im_FZG) || (defined Cx3_Standfunktionen_Kunde_nicht_im_FZG)
#  if (!defined RTE_CONST_Cx3_Standfunktionen_Kunde_nicht_im_FZG) || (RTE_CONST_Cx3_Standfunktionen_Kunde_nicht_im_FZG != 3U)
#   error "Enumeration constant <Cx3_Standfunktionen_Kunde_nicht_im_FZG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Standfunktionen_Kunde_nicht_im_FZG (3U)
#  define Cx3_Standfunktionen_Kunde_nicht_im_FZG (3U)
# endif
# if (defined RTE_CONST_Cx5_Wohnen) || (defined Cx5_Wohnen)
#  if (!defined RTE_CONST_Cx5_Wohnen) || (RTE_CONST_Cx5_Wohnen != 5U)
#   error "Enumeration constant <Cx5_Wohnen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx5_Wohnen (5U)
#  define Cx5_Wohnen (5U)
# endif
# if (defined RTE_CONST_Cx7_Pruefen_Analyse_Diagnose) || (defined Cx7_Pruefen_Analyse_Diagnose)
#  if (!defined RTE_CONST_Cx7_Pruefen_Analyse_Diagnose) || (RTE_CONST_Cx7_Pruefen_Analyse_Diagnose != 7U)
#   error "Enumeration constant <Cx7_Pruefen_Analyse_Diagnose> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Pruefen_Analyse_Diagnose (7U)
#  define Cx7_Pruefen_Analyse_Diagnose (7U)
# endif
# if (defined RTE_CONST_Cx8_Fahrbereitschaft_herstellen) || (defined Cx8_Fahrbereitschaft_herstellen)
#  if (!defined RTE_CONST_Cx8_Fahrbereitschaft_herstellen) || (RTE_CONST_Cx8_Fahrbereitschaft_herstellen != 8U)
#   error "Enumeration constant <Cx8_Fahrbereitschaft_herstellen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Fahrbereitschaft_herstellen (8U)
#  define Cx8_Fahrbereitschaft_herstellen (8U)
# endif
# if (defined RTE_CONST_CxA_Fahren) || (defined CxA_Fahren)
#  if (!defined RTE_CONST_CxA_Fahren) || (RTE_CONST_CxA_Fahren != 10U)
#   error "Enumeration constant <CxA_Fahren> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA_Fahren (10U)
#  define CxA_Fahren (10U)
# endif
# if (defined RTE_CONST_CxC_Fahrbereitschaft_beenden) || (defined CxC_Fahrbereitschaft_beenden)
#  if (!defined RTE_CONST_CxC_Fahrbereitschaft_beenden) || (RTE_CONST_CxC_Fahrbereitschaft_beenden != 12U)
#   error "Enumeration constant <CxC_Fahrbereitschaft_beenden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxC_Fahrbereitschaft_beenden (12U)
#  define CxC_Fahrbereitschaft_beenden (12U)
# endif
# if (defined RTE_CONST_CxD_reserviert) || (defined CxD_reserviert)
#  if (!defined RTE_CONST_CxD_reserviert) || (RTE_CONST_CxD_reserviert != 13U)
#   error "Enumeration constant <CxD_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_reserviert (13U)
#  define CxD_reserviert (13U)
# endif
# if (defined RTE_CONST_CxE_reserviert) || (defined CxE_reserviert)
#  if (!defined RTE_CONST_CxE_reserviert) || (RTE_CONST_CxE_reserviert != 14U)
#   error "Enumeration constant <CxE_reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_reserviert (14U)
#  define CxE_reserviert (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#   error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_unbefuellt (15U)
#  define CxF_Signal_unbefuellt (15U)
# endif

# define Rte_TypeDef_New_Coding_83
typedef uint8 New_Coding_83;
# define New_Coding_83_LowerLimit (0U)
# define New_Coding_83_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_83 (15U)
# define InvalidValue_New_Coding_83 (15U)
# if (defined RTE_CONST_Cx0_Keine_Deaktivierung_EPS_Funktionen) || (defined Cx0_Keine_Deaktivierung_EPS_Funktionen)
#  if (!defined RTE_CONST_Cx0_Keine_Deaktivierung_EPS_Funktionen) || (RTE_CONST_Cx0_Keine_Deaktivierung_EPS_Funktionen != 0U)
#   error "Enumeration constant <Cx0_Keine_Deaktivierung_EPS_Funktionen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Keine_Deaktivierung_EPS_Funktionen (0U)
#  define Cx0_Keine_Deaktivierung_EPS_Funktionen (0U)
# endif
# if (defined RTE_CONST_Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1) || (defined Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1)
#  if (!defined RTE_CONST_Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1) || (RTE_CONST_Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1 != 0U)
#   error "Enumeration constant <Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1 (0U)
#  define Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1 (0U)
# endif
# if (defined RTE_CONST_Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2) || (defined Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2)
#  if (!defined RTE_CONST_Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2) || (RTE_CONST_Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2 != 0U)
#   error "Enumeration constant <Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2 (0U)
#  define Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2 (0U)
# endif
# if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#  if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#   error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
# endif
# if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#  if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#   error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#  define CxE_Funktion_meldet_Fehler (14U)
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

# define Rte_TypeDef_QU_SER_STMOM_STMOM_DV_ACT
typedef uint8 QU_SER_STMOM_STMOM_DV_ACT;
# define QU_SER_STMOM_STMOM_DV_ACT_LowerLimit (0U)
# define QU_SER_STMOM_STMOM_DV_ACT_UpperLimit (255U)
# define Rte_InvalidValue_QU_SER_STMOM_STMOM_DV_ACT (255U)
# define InvalidValue_QU_SER_STMOM_STMOM_DV_ACT (255U)
# define Rte_TypeDef_QU_TAR_DMPNG_ADDON_STMOM_FTAX
typedef uint8 QU_TAR_DMPNG_ADDON_STMOM_FTAX;
# define QU_TAR_DMPNG_ADDON_STMOM_FTAX_LowerLimit (0U)
# define QU_TAR_DMPNG_ADDON_STMOM_FTAX_UpperLimit (15U)
# define Rte_InvalidValue_QU_TAR_DMPNG_ADDON_STMOM_FTAX (15U)
# define InvalidValue_QU_TAR_DMPNG_ADDON_STMOM_FTAX (15U)
# if (defined RTE_CONST_Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen) || (defined Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen)
#  if (!defined RTE_CONST_Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen) || (RTE_CONST_Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen != 1U)
#   error "Enumeration constant <Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen (1U)
#  define Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen (1U)
# endif
# if (defined RTE_CONST_Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen) || (defined Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen)
#  if (!defined RTE_CONST_Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen) || (RTE_CONST_Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen != 2U)
#   error "Enumeration constant <Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen (2U)
#  define Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen (2U)
# endif
# if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#   error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_unbefuellt (15U)
#  define CxF_Signal_unbefuellt (15U)
# endif

# define Rte_TypeDef_QU_TAR_FACT_STMOM_FTAX
typedef uint8 QU_TAR_FACT_STMOM_FTAX;
# define QU_TAR_FACT_STMOM_FTAX_LowerLimit (0U)
# define QU_TAR_FACT_STMOM_FTAX_UpperLimit (15U)
# define Rte_InvalidValue_QU_TAR_FACT_STMOM_FTAX (15U)
# define InvalidValue_QU_TAR_FACT_STMOM_FTAX (15U)
# if (defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (defined Cx2_Sollwerte_umsetzen)
#  if (!defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (RTE_CONST_Cx2_Sollwerte_umsetzen != 2U)
#   error "Enumeration constant <Cx2_Sollwerte_umsetzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Sollwerte_umsetzen (2U)
#  define Cx2_Sollwerte_umsetzen (2U)
# endif
# if (defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (defined Cx7_Sollwerte_nicht_vorhanden)
#  if (!defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (RTE_CONST_Cx7_Sollwerte_nicht_vorhanden != 7U)
#   error "Enumeration constant <Cx7_Sollwerte_nicht_vorhanden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Sollwerte_nicht_vorhanden (7U)
#  define Cx7_Sollwerte_nicht_vorhanden (7U)
# endif
# if (defined RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen) || (defined CxE_Standby__Sollwerte_nicht_umsetzen)
#  if (!defined RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen) || (RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen != 14U)
#   error "Enumeration constant <CxE_Standby__Sollwerte_nicht_umsetzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen (14U)
#  define CxE_Standby__Sollwerte_nicht_umsetzen (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_QU_TAR_QTA_STMOM_DV
typedef uint8 QU_TAR_QTA_STMOM_DV;
# define QU_TAR_QTA_STMOM_DV_LowerLimit (0U)
# define QU_TAR_QTA_STMOM_DV_UpperLimit (15U)
# define Rte_InvalidValue_QU_TAR_QTA_STMOM_DV (15U)
# define InvalidValue_QU_TAR_QTA_STMOM_DV (15U)
# if (defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (defined Cx2_Sollwerte_umsetzen)
#  if (!defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (RTE_CONST_Cx2_Sollwerte_umsetzen != 2U)
#   error "Enumeration constant <Cx2_Sollwerte_umsetzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Sollwerte_umsetzen (2U)
#  define Cx2_Sollwerte_umsetzen (2U)
# endif
# if (defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (defined Cx7_Sollwerte_nicht_vorhanden)
#  if (!defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (RTE_CONST_Cx7_Sollwerte_nicht_vorhanden != 7U)
#   error "Enumeration constant <Cx7_Sollwerte_nicht_vorhanden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Sollwerte_nicht_vorhanden (7U)
#  define Cx7_Sollwerte_nicht_vorhanden (7U)
# endif
# if (defined RTE_CONST_CxE_Sollwerte_nicht_umsetzen___Standby) || (defined CxE_Sollwerte_nicht_umsetzen___Standby)
#  if (!defined RTE_CONST_CxE_Sollwerte_nicht_umsetzen___Standby) || (RTE_CONST_CxE_Sollwerte_nicht_umsetzen___Standby != 14U)
#   error "Enumeration constant <CxE_Sollwerte_nicht_umsetzen___Standby> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Sollwerte_nicht_umsetzen___Standby (14U)
#  define CxE_Sollwerte_nicht_umsetzen___Standby (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_QU_TAR_STMOM_DV_ACT
typedef uint8 QU_TAR_STMOM_DV_ACT;
# define QU_TAR_STMOM_DV_ACT_LowerLimit (0U)
# define QU_TAR_STMOM_DV_ACT_UpperLimit (15U)
# define Rte_InvalidValue_QU_TAR_STMOM_DV_ACT (15U)
# define InvalidValue_QU_TAR_STMOM_DV_ACT (15U)
# if (defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (defined Cx2_Sollwerte_umsetzen)
#  if (!defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (RTE_CONST_Cx2_Sollwerte_umsetzen != 2U)
#   error "Enumeration constant <Cx2_Sollwerte_umsetzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Sollwerte_umsetzen (2U)
#  define Cx2_Sollwerte_umsetzen (2U)
# endif
# if (defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (defined Cx7_Sollwerte_nicht_vorhanden)
#  if (!defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (RTE_CONST_Cx7_Sollwerte_nicht_vorhanden != 7U)
#   error "Enumeration constant <Cx7_Sollwerte_nicht_vorhanden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Sollwerte_nicht_vorhanden (7U)
#  define Cx7_Sollwerte_nicht_vorhanden (7U)
# endif
# if (defined RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen) || (defined CxE_Standby__Sollwerte_nicht_umsetzen)
#  if (!defined RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen) || (RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen != 14U)
#   error "Enumeration constant <CxE_Standby__Sollwerte_nicht_umsetzen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen (14U)
#  define CxE_Standby__Sollwerte_nicht_umsetzen (14U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_QU_V_VEH_COG
typedef uint8 QU_V_VEH_COG;
# define QU_V_VEH_COG_LowerLimit (0U)
# define QU_V_VEH_COG_UpperLimit (15U)
# define Rte_InvalidValue_QU_V_VEH_COG (15U)
# define InvalidValue_QU_V_VEH_COG (15U)
# if (defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (defined Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert)
#  if (!defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert != 1U)
#   error "Enumeration constant <Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#  define Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
# endif
# if (defined RTE_CONST_Cx2_Reserved) || (defined Cx2_Reserved)
#  if (!defined RTE_CONST_Cx2_Reserved) || (RTE_CONST_Cx2_Reserved != 2U)
#   error "Enumeration constant <Cx2_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Reserved (2U)
#  define Cx2_Reserved (2U)
# endif
# if (defined RTE_CONST_Cx3_Reserved) || (defined Cx3_Reserved)
#  if (!defined RTE_CONST_Cx3_Reserved) || (RTE_CONST_Cx3_Reserved != 3U)
#   error "Enumeration constant <Cx3_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Reserved (3U)
#  define Cx3_Reserved (3U)
# endif
# if (defined RTE_CONST_Cx4_Reserved) || (defined Cx4_Reserved)
#  if (!defined RTE_CONST_Cx4_Reserved) || (RTE_CONST_Cx4_Reserved != 4U)
#   error "Enumeration constant <Cx4_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Reserved (4U)
#  define Cx4_Reserved (4U)
# endif
# if (defined RTE_CONST_Cx6_Reserved) || (defined Cx6_Reserved)
#  if (!defined RTE_CONST_Cx6_Reserved) || (RTE_CONST_Cx6_Reserved != 6U)
#   error "Enumeration constant <Cx6_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Reserved (6U)
#  define Cx6_Reserved (6U)
# endif
# if (defined RTE_CONST_Cx7_Reserved) || (defined Cx7_Reserved)
#  if (!defined RTE_CONST_Cx7_Reserved) || (RTE_CONST_Cx7_Reserved != 7U)
#   error "Enumeration constant <Cx7_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Reserved (7U)
#  define Cx7_Reserved (7U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#  if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#   error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung (8U)
#  define Cx8_Initialisierung (8U)
# endif
# if (defined RTE_CONST_Cx9_Reserved) || (defined Cx9_Reserved)
#  if (!defined RTE_CONST_Cx9_Reserved) || (RTE_CONST_Cx9_Reserved != 9U)
#   error "Enumeration constant <Cx9_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx9_Reserved (9U)
#  define Cx9_Reserved (9U)
# endif
# if (defined RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer) || (defined CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer) || (RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer != 10U)
#   error "Enumeration constant <CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
#  define CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
# endif
# if (defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (defined CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer)
#  if (!defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer != 11U)
#   error "Enumeration constant <CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#  define CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
# endif
# if (defined RTE_CONST_CxC_Reserved) || (defined CxC_Reserved)
#  if (!defined RTE_CONST_CxC_Reserved) || (RTE_CONST_CxC_Reserved != 12U)
#   error "Enumeration constant <CxC_Reserved> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxC_Reserved (12U)
#  define CxC_Reserved (12U)
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

# define Rte_TypeDef_ST_OFFS_QUAD_EPS
typedef uint8 ST_OFFS_QUAD_EPS;
# define ST_OFFS_QUAD_EPS_LowerLimit (0U)
# define ST_OFFS_QUAD_EPS_UpperLimit (15U)
# if (defined RTE_CONST_STOFFSQUADEPS_SLEEP) || (defined STOFFSQUADEPS_SLEEP)
#  if (!defined RTE_CONST_STOFFSQUADEPS_SLEEP) || (RTE_CONST_STOFFSQUADEPS_SLEEP != 0U)
#   error "Enumeration constant <STOFFSQUADEPS_SLEEP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_SLEEP (0U)
#  define STOFFSQUADEPS_SLEEP (0U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_CALCULATED) || (defined STOFFSQUADEPS_CALCULATED)
#  if (!defined RTE_CONST_STOFFSQUADEPS_CALCULATED) || (RTE_CONST_STOFFSQUADEPS_CALCULATED != 1U)
#   error "Enumeration constant <STOFFSQUADEPS_CALCULATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_CALCULATED (1U)
#  define STOFFSQUADEPS_CALCULATED (1U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_INDEX) || (defined STOFFSQUADEPS_INDEX)
#  if (!defined RTE_CONST_STOFFSQUADEPS_INDEX) || (RTE_CONST_STOFFSQUADEPS_INDEX != 2U)
#   error "Enumeration constant <STOFFSQUADEPS_INDEX> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_INDEX (2U)
#  define STOFFSQUADEPS_INDEX (2U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_MODELCOMP) || (defined STOFFSQUADEPS_MODELCOMP)
#  if (!defined RTE_CONST_STOFFSQUADEPS_MODELCOMP) || (RTE_CONST_STOFFSQUADEPS_MODELCOMP != 3U)
#   error "Enumeration constant <STOFFSQUADEPS_MODELCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_MODELCOMP (3U)
#  define STOFFSQUADEPS_MODELCOMP (3U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK) || (defined STOFFSQUADEPS_LOCKTOLOCK)
#  if (!defined RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK) || (RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK != 4U)
#   error "Enumeration constant <STOFFSQUADEPS_LOCKTOLOCK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK (4U)
#  define STOFFSQUADEPS_LOCKTOLOCK (4U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE) || (defined STOFFSQUADEPS_SUMSTEERINGANGLE)
#  if (!defined RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE) || (RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE != 5U)
#   error "Enumeration constant <STOFFSQUADEPS_SUMSTEERINGANGLE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE (5U)
#  define STOFFSQUADEPS_SUMSTEERINGANGLE (5U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_CHECK) || (defined STOFFSQUADEPS_CHECK)
#  if (!defined RTE_CONST_STOFFSQUADEPS_CHECK) || (RTE_CONST_STOFFSQUADEPS_CHECK != 6U)
#   error "Enumeration constant <STOFFSQUADEPS_CHECK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_CHECK (6U)
#  define STOFFSQUADEPS_CHECK (6U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_CORRECTION) || (defined STOFFSQUADEPS_CORRECTION)
#  if (!defined RTE_CONST_STOFFSQUADEPS_CORRECTION) || (RTE_CONST_STOFFSQUADEPS_CORRECTION != 7U)
#   error "Enumeration constant <STOFFSQUADEPS_CORRECTION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_CORRECTION (7U)
#  define STOFFSQUADEPS_CORRECTION (7U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_INITIALIZATION) || (defined STOFFSQUADEPS_INITIALIZATION)
#  if (!defined RTE_CONST_STOFFSQUADEPS_INITIALIZATION) || (RTE_CONST_STOFFSQUADEPS_INITIALIZATION != 8U)
#   error "Enumeration constant <STOFFSQUADEPS_INITIALIZATION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_INITIALIZATION (8U)
#  define STOFFSQUADEPS_INITIALIZATION (8U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_DETERMINED) || (defined STOFFSQUADEPS_DETERMINED)
#  if (!defined RTE_CONST_STOFFSQUADEPS_DETERMINED) || (RTE_CONST_STOFFSQUADEPS_DETERMINED != 9U)
#   error "Enumeration constant <STOFFSQUADEPS_DETERMINED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_DETERMINED (9U)
#  define STOFFSQUADEPS_DETERMINED (9U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_APPROXIMATED) || (defined STOFFSQUADEPS_APPROXIMATED)
#  if (!defined RTE_CONST_STOFFSQUADEPS_APPROXIMATED) || (RTE_CONST_STOFFSQUADEPS_APPROXIMATED != 11U)
#   error "Enumeration constant <STOFFSQUADEPS_APPROXIMATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_APPROXIMATED (11U)
#  define STOFFSQUADEPS_APPROXIMATED (11U)
# endif
# if (defined RTE_CONST_STOFFSQUADEPS_INVALID) || (defined STOFFSQUADEPS_INVALID)
#  if (!defined RTE_CONST_STOFFSQUADEPS_INVALID) || (RTE_CONST_STOFFSQUADEPS_INVALID != 15U)
#   error "Enumeration constant <STOFFSQUADEPS_INVALID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STOFFSQUADEPS_INVALID (15U)
#  define STOFFSQUADEPS_INVALID (15U)
# endif

# define Rte_TypeDef_ST_OFFS_QUAD_PINA_EPS
typedef uint8 ST_OFFS_QUAD_PINA_EPS;
# define ST_OFFS_QUAD_PINA_EPS_LowerLimit (0U)
# define ST_OFFS_QUAD_PINA_EPS_UpperLimit (15U)
# define Rte_InvalidValue_ST_OFFS_QUAD_PINA_EPS (15U)
# define InvalidValue_ST_OFFS_QUAD_PINA_EPS (15U)
# if (defined RTE_CONST_Cx0_Algorithmus__Funktion__im_Sleep_Modus) || (defined Cx0_Algorithmus__Funktion__im_Sleep_Modus)
#  if (!defined RTE_CONST_Cx0_Algorithmus__Funktion__im_Sleep_Modus) || (RTE_CONST_Cx0_Algorithmus__Funktion__im_Sleep_Modus != 0U)
#   error "Enumeration constant <Cx0_Algorithmus__Funktion__im_Sleep_Modus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Algorithmus__Funktion__im_Sleep_Modus (0U)
#  define Cx0_Algorithmus__Funktion__im_Sleep_Modus (0U)
# endif
# if (defined RTE_CONST_Cx1_Offset__wird_ermittelt) || (defined Cx1_Offset__wird_ermittelt)
#  if (!defined RTE_CONST_Cx1_Offset__wird_ermittelt) || (RTE_CONST_Cx1_Offset__wird_ermittelt != 1U)
#   error "Enumeration constant <Cx1_Offset__wird_ermittelt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Offset__wird_ermittelt (1U)
#  define Cx1_Offset__wird_ermittelt (1U)
# endif
# if (defined RTE_CONST_Cx2_Offset_uebernehmen__Aufsetzen_ueber_Index) || (defined Cx2_Offset_uebernehmen__Aufsetzen_ueber_Index)
#  if (!defined RTE_CONST_Cx2_Offset_uebernehmen__Aufsetzen_ueber_Index) || (RTE_CONST_Cx2_Offset_uebernehmen__Aufsetzen_ueber_Index != 2U)
#   error "Enumeration constant <Cx2_Offset_uebernehmen__Aufsetzen_ueber_Index> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Offset_uebernehmen__Aufsetzen_ueber_Index (2U)
#  define Cx2_Offset_uebernehmen__Aufsetzen_ueber_Index (2U)
# endif
# if (defined RTE_CONST_Cx3_Offset_uebernehmen__Aufsetzen_ueber_Modelvergleich) || (defined Cx3_Offset_uebernehmen__Aufsetzen_ueber_Modelvergleich)
#  if (!defined RTE_CONST_Cx3_Offset_uebernehmen__Aufsetzen_ueber_Modelvergleich) || (RTE_CONST_Cx3_Offset_uebernehmen__Aufsetzen_ueber_Modelvergleich != 3U)
#   error "Enumeration constant <Cx3_Offset_uebernehmen__Aufsetzen_ueber_Modelvergleich> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Offset_uebernehmen__Aufsetzen_ueber_Modelvergleich (3U)
#  define Cx3_Offset_uebernehmen__Aufsetzen_ueber_Modelvergleich (3U)
# endif
# if (defined RTE_CONST_Cx4_Offset_uebernehmen__Aufsetzen_ueber_Anschlag_Anschlag) || (defined Cx4_Offset_uebernehmen__Aufsetzen_ueber_Anschlag_Anschlag)
#  if (!defined RTE_CONST_Cx4_Offset_uebernehmen__Aufsetzen_ueber_Anschlag_Anschlag) || (RTE_CONST_Cx4_Offset_uebernehmen__Aufsetzen_ueber_Anschlag_Anschlag != 4U)
#   error "Enumeration constant <Cx4_Offset_uebernehmen__Aufsetzen_ueber_Anschlag_Anschlag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Offset_uebernehmen__Aufsetzen_ueber_Anschlag_Anschlag (4U)
#  define Cx4_Offset_uebernehmen__Aufsetzen_ueber_Anschlag_Anschlag (4U)
# endif
# if (defined RTE_CONST_Cx5_Offset_uebernehmen__Aufsetzen_ueber_Summenlenkwinkel__im_AFS_Fall_) || (defined Cx5_Offset_uebernehmen__Aufsetzen_ueber_Summenlenkwinkel__im_AFS_Fall_)
#  if (!defined RTE_CONST_Cx5_Offset_uebernehmen__Aufsetzen_ueber_Summenlenkwinkel__im_AFS_Fall_) || (RTE_CONST_Cx5_Offset_uebernehmen__Aufsetzen_ueber_Summenlenkwinkel__im_AFS_Fall_ != 5U)
#   error "Enumeration constant <Cx5_Offset_uebernehmen__Aufsetzen_ueber_Summenlenkwinkel__im_AFS_Fall_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx5_Offset_uebernehmen__Aufsetzen_ueber_Summenlenkwinkel__im_AFS_Fall_ (5U)
#  define Cx5_Offset_uebernehmen__Aufsetzen_ueber_Summenlenkwinkel__im_AFS_Fall_ (5U)
# endif
# if (defined RTE_CONST_Cx6_Offset_in_Pruefung) || (defined Cx6_Offset_in_Pruefung)
#  if (!defined RTE_CONST_Cx6_Offset_in_Pruefung) || (RTE_CONST_Cx6_Offset_in_Pruefung != 6U)
#   error "Enumeration constant <Cx6_Offset_in_Pruefung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Offset_in_Pruefung (6U)
#  define Cx6_Offset_in_Pruefung (6U)
# endif
# if (defined RTE_CONST_Cx7_Offset_korrigieren) || (defined Cx7_Offset_korrigieren)
#  if (!defined RTE_CONST_Cx7_Offset_korrigieren) || (RTE_CONST_Cx7_Offset_korrigieren != 7U)
#   error "Enumeration constant <Cx7_Offset_korrigieren> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Offset_korrigieren (7U)
#  define Cx7_Offset_korrigieren (7U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#  if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#   error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung (8U)
#  define Cx8_Initialisierung (8U)
# endif
# if (defined RTE_CONST_Cx9_Restoffset_wird_ermittelt) || (defined Cx9_Restoffset_wird_ermittelt)
#  if (!defined RTE_CONST_Cx9_Restoffset_wird_ermittelt) || (RTE_CONST_Cx9_Restoffset_wird_ermittelt != 9U)
#   error "Enumeration constant <Cx9_Restoffset_wird_ermittelt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx9_Restoffset_wird_ermittelt (9U)
#  define Cx9_Restoffset_wird_ermittelt (9U)
# endif
# if (defined RTE_CONST_CxB_Offset_uebernehmen__Groboffset_ueber_Modell) || (defined CxB_Offset_uebernehmen__Groboffset_ueber_Modell)
#  if (!defined RTE_CONST_CxB_Offset_uebernehmen__Groboffset_ueber_Modell) || (RTE_CONST_CxB_Offset_uebernehmen__Groboffset_ueber_Modell != 11U)
#   error "Enumeration constant <CxB_Offset_uebernehmen__Groboffset_ueber_Modell> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxB_Offset_uebernehmen__Groboffset_ueber_Modell (11U)
#  define CxB_Offset_uebernehmen__Groboffset_ueber_Modell (11U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_ST_V_VEH_NSS
typedef uint8 ST_V_VEH_NSS;
# define ST_V_VEH_NSS_LowerLimit (0U)
# define ST_V_VEH_NSS_UpperLimit (15U)
# define Rte_InvalidValue_ST_V_VEH_NSS (15U)
# define InvalidValue_ST_V_VEH_NSS (15U)
# if (defined RTE_CONST_CxC_Fahrzeug_im_stillstandsnahen_Bereich) || (defined CxC_Fahrzeug_im_stillstandsnahen_Bereich)
#  if (!defined RTE_CONST_CxC_Fahrzeug_im_stillstandsnahen_Bereich) || (RTE_CONST_CxC_Fahrzeug_im_stillstandsnahen_Bereich != 12U)
#   error "Enumeration constant <CxC_Fahrzeug_im_stillstandsnahen_Bereich> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxC_Fahrzeug_im_stillstandsnahen_Bereich (12U)
#  define CxC_Fahrzeug_im_stillstandsnahen_Bereich (12U)
# endif
# if (defined RTE_CONST_CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich) || (defined CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich)
#  if (!defined RTE_CONST_CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich) || (RTE_CONST_CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich != 13U)
#   error "Enumeration constant <CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich (13U)
#  define CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich (13U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
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

# define Rte_TypeDef_SG_ACLNY_MASSCNTR
typedef struct
{
  New_Coding_37 ACLNY_COG_ERR_AMP;
  New_Coding_35 ALIV_ACLNY_COG;
  New_Coding_38 QU_ACLNY_COG;
  CD_0x04 ACLNY_MASSCNTR_0x0C_0x04;
  New_Coding_36 ACLNY_COG;
  New_Coding_34 CRC_ACLNY_COG;
} SG_ACLNY_MASSCNTR;

# define Rte_TypeDef_SG_CON_VEH
typedef struct
{
  New_Coding_61 ALIV_CON_VEH;
  New_Coding_64 ST_CON_VEH;
  New_Coding_62 CTR_FKTN_PRTNT;
  New_Coding_63 QU_ST_CON_VEH;
  CD_0x08 CON_VEH_0x38_0x08;
  New_Coding_60 CTR_BS_PRTNT;
  New_Coding_59 CRC_CON_VEH;
} SG_CON_VEH;

# define Rte_TypeDef_SG_OFFS_QUAD_EPS
typedef struct
{
  OFFS_QUAD_PINA_EPS OFFS_QUAD_RTR_EPS;
  AVL_PINA_IDX_ICM AVL_PO_IDX_ICM;
  CRC8 CRC_OFFS_QUAD_EPS;
  ST_OFFS_QUAD_PINA_EPS ST_OFFS_QUAD_EPS;
  ALIV_COU_4 ALIV_OFFS_QUAD_EPS;
} SG_OFFS_QUAD_EPS;

# define Rte_TypeDef_SG_ST_CENG
typedef struct
{
  New_Coding_101 CRC_ST_CENG;
  New_Coding_107 ST_ANO_MSA_ENG_STOP;
  New_Coding_109 CTR_LED_PUBU_MSA;
  CD_0x16 ST_CENG_0x2A_0x16;
  New_Coding_105 ST_ENERG_SUPY;
  New_Coding_108 ST_MOT_DRV;
  New_Coding_103 ST_UDP;
  New_Coding_104 ST_CENG_DRV;
  New_Coding_102 ALIV_ST_CENG;
  New_Coding_106 TR_HHASS_MSA;
  CD_0x04 ST_CENG_0x0C_0x04;
} SG_ST_CENG;

# define Rte_TypeDef_SG_TAR_QTA_STRMOM_DV
typedef struct
{
  FACT_CTRR_STMOM_FTAX FACT_CTRR_STMOM_FTAX;
  ALIV_COU_4 ALIV_TAR_QTA_STMOM_DV;
  QU_TAR_FACT_STMOM_FTAX QU_TAR_FACT_STMOM_FTAX;
  QU_TAR_QTA_STMOM_DV QU_TAR_QTA_STMOM_DV;
  CRC8 CRC_TAR_QTA_STMOM_DV;
  FACT_ASS_STMOM_FTAX FACT_ASS_STMOM_FTAX;
  FACT_CTRR_STMOM_FTAX FACT_DMPNG_STMOM_FTAX;
  STMOM_QTA_DV TAR_QTA_STMOM_DV;
  New_Coding_83 CTR_DEAC_EPS_FNS;
} SG_TAR_QTA_STRMOM_DV;

# define Rte_TypeDef_SG_TAR_STMOM_DV_ACT
typedef struct
{
  QU_TAR_STMOM_DV_ACT QU_TAR_STMOM_DV_ACT;
  ALIV_COU_4 ALIV_TAR_STMOM_DV_ACT;
  TAR_STMOM_DV_ACT TAR_STMOM_DV_ACT;
  CRC8 CRC_TAR_STMOM_DV_ACT;
  FACT_DMPNG_ADDON_STMOM_FTAX FACT_DMPNG_ADDON_STMOM_FTAX;
  QU_TAR_DMPNG_ADDON_STMOM_FTAX QU_TAR_DMPNG_ADDON_STMOM_FTAX;
} SG_TAR_STMOM_DV_ACT;

# define Rte_TypeDef_SG_VYAW_VEH
typedef struct
{
  New_Coding_30 ALIV_VYAW_VEH;
  New_Coding_32 VYAW_VEH_ERR_AMP;
  CD_0x04 VYAW_VEH_0x0C_0x04;
  New_Coding_29 CRC_VYAW_VEH;
  New_Coding_31 VYAW_VEH;
  New_Coding_33 QU_VYAW_VEH;
} SG_VYAW_VEH;

# define Rte_TypeDef_SG_V_VEH
typedef struct
{
  ST_V_VEH_NSS ST_V_VEH_NSS;
  CD_0x01 V_VEH_0x27_0x01;
  ALIV_COU_V ALIV_V_VEH;
  CRC_V_VEH CRC_V_VEH;
  QU_V_VEH_COG QU_V_VEH_COG;
  V_VEH_COG V_VEH_COG;
  DVCO_VEH DVCO_VEH;
} SG_V_VEH;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_DT_NO_VECH_1
typedef uint8 DT_NO_VECH_1;
#  define DT_NO_VECH_1_LowerLimit (0U)
#  define DT_NO_VECH_1_UpperLimit (255U)
#  define Rte_InvalidValue_DT_NO_VECH_1 (255U)
#  define InvalidValue_DT_NO_VECH_1 (255U)

#  define Rte_TypeDef_DT_NO_VECH_2
typedef uint8 DT_NO_VECH_2;
#  define DT_NO_VECH_2_LowerLimit (0U)
#  define DT_NO_VECH_2_UpperLimit (255U)
#  define Rte_InvalidValue_DT_NO_VECH_2 (255U)
#  define InvalidValue_DT_NO_VECH_2 (255U)

#  define Rte_TypeDef_DT_NO_VECH_3
typedef uint8 DT_NO_VECH_3;
#  define DT_NO_VECH_3_LowerLimit (0U)
#  define DT_NO_VECH_3_UpperLimit (255U)
#  define Rte_InvalidValue_DT_NO_VECH_3 (255U)
#  define InvalidValue_DT_NO_VECH_3 (255U)

#  define Rte_TypeDef_DT_NO_VECH_4
typedef uint8 DT_NO_VECH_4;
#  define DT_NO_VECH_4_LowerLimit (0U)
#  define DT_NO_VECH_4_UpperLimit (255U)
#  define Rte_InvalidValue_DT_NO_VECH_4 (255U)
#  define InvalidValue_DT_NO_VECH_4 (255U)

#  define Rte_TypeDef_DT_NO_VECH_5
typedef uint8 DT_NO_VECH_5;
#  define DT_NO_VECH_5_LowerLimit (0U)
#  define DT_NO_VECH_5_UpperLimit (255U)
#  define Rte_InvalidValue_DT_NO_VECH_5 (255U)
#  define InvalidValue_DT_NO_VECH_5 (255U)

#  define Rte_TypeDef_DT_NO_VECH_6
typedef uint8 DT_NO_VECH_6;
#  define DT_NO_VECH_6_LowerLimit (0U)
#  define DT_NO_VECH_6_UpperLimit (255U)
#  define Rte_InvalidValue_DT_NO_VECH_6 (255U)
#  define InvalidValue_DT_NO_VECH_6 (255U)

#  define Rte_TypeDef_DT_NO_VECH_7
typedef uint8 DT_NO_VECH_7;
#  define DT_NO_VECH_7_LowerLimit (0U)
#  define DT_NO_VECH_7_UpperLimit (255U)
#  define Rte_InvalidValue_DT_NO_VECH_7 (255U)
#  define InvalidValue_DT_NO_VECH_7 (255U)

#  define Rte_TypeDef_MILE_KM
typedef uint32 MILE_KM;
#  define MILE_KM_LowerLimit (0U)
#  define MILE_KM_UpperLimit (16777214U)
#  define Rte_InvalidValue_MILE_KM (16777215U)
#  define InvalidValue_MILE_KM (16777215U)

#  define Rte_TypeDef_New_Coding_69
typedef uint8 New_Coding_69;
#  define New_Coding_69_LowerLimit (0U)
#  define New_Coding_69_UpperLimit (14U)
#  define Rte_InvalidValue_New_Coding_69 (15U)
#  define InvalidValue_New_Coding_69 (15U)

#  define Rte_TypeDef_New_Coding_70
typedef uint8 New_Coding_70;
#  define New_Coding_70_LowerLimit (0U)
#  define New_Coding_70_UpperLimit (14U)
#  define Rte_InvalidValue_New_Coding_70 (15U)
#  define InvalidValue_New_Coding_70 (15U)

#  define Rte_TypeDef_UInt4
typedef uint8 UInt4;
#  define UInt4_LowerLimit (0U)
#  define UInt4_UpperLimit (15U)

#  define Rte_TypeDef_AVL_STEA_PNI_OFFS
typedef uint16 AVL_STEA_PNI_OFFS;
#  define AVL_STEA_PNI_OFFS_LowerLimit (0U)
#  define AVL_STEA_PNI_OFFS_UpperLimit (4095U)
#  define Rte_InvalidValue_AVL_STEA_PNI_OFFS (4095U)
#  define InvalidValue_AVL_STEA_PNI_OFFS (4095U)
#  if (defined RTE_CONST_CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 4093U)
#    error "Enumeration constant <CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar (4093U)
#   define CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar (4093U)
#  endif
#  if (defined RTE_CONST_CxFFE_Funktion_meldet_Fehler) || (defined CxFFE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxFFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFFE_Funktion_meldet_Fehler != 4094U)
#    error "Enumeration constant <CxFFE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFFE_Funktion_meldet_Fehler (4094U)
#   define CxFFE_Funktion_meldet_Fehler (4094U)
#  endif
#  if (defined RTE_CONST_CxFFF_Signal_unbefuellt) || (defined CxFFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFFF_Signal_unbefuellt) || (RTE_CONST_CxFFF_Signal_unbefuellt != 4095U)
#    error "Enumeration constant <CxFFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFFF_Signal_unbefuellt (4095U)
#   define CxFFF_Signal_unbefuellt (4095U)
#  endif

#  define Rte_TypeDef_CTR_ERRM_BN_U
typedef uint8 CTR_ERRM_BN_U;
#  define CTR_ERRM_BN_U_LowerLimit (0U)
#  define CTR_ERRM_BN_U_UpperLimit (63U)
#  define Rte_InvalidValue_CTR_ERRM_BN_U (63U)
#  define InvalidValue_CTR_ERRM_BN_U (63U)
#  if (defined RTE_CONST_Cb0xxxx1_Unterspannung_Normalbetrieb) || (defined Cb0xxxx1_Unterspannung_Normalbetrieb)
#   if (!defined RTE_CONST_Cb0xxxx1_Unterspannung_Normalbetrieb) || (RTE_CONST_Cb0xxxx1_Unterspannung_Normalbetrieb != 0U)
#    error "Enumeration constant <Cb0xxxx1_Unterspannung_Normalbetrieb> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xxxx1_Unterspannung_Normalbetrieb (0U)
#   define Cb0xxxx1_Unterspannung_Normalbetrieb (0U)
#  endif
#  if (defined RTE_CONST_Cb0xxxx0_Keine_Unterspannung_Normalbetrieb) || (defined Cb0xxxx0_Keine_Unterspannung_Normalbetrieb)
#   if (!defined RTE_CONST_Cb0xxxx0_Keine_Unterspannung_Normalbetrieb) || (RTE_CONST_Cb0xxxx0_Keine_Unterspannung_Normalbetrieb != 0U)
#    error "Enumeration constant <Cb0xxxx0_Keine_Unterspannung_Normalbetrieb> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xxxx0_Keine_Unterspannung_Normalbetrieb (0U)
#   define Cb0xxxx0_Keine_Unterspannung_Normalbetrieb (0U)
#  endif
#  if (defined RTE_CONST_Cb0xxx1x_Unterspannung_MSA_Start) || (defined Cb0xxx1x_Unterspannung_MSA_Start)
#   if (!defined RTE_CONST_Cb0xxx1x_Unterspannung_MSA_Start) || (RTE_CONST_Cb0xxx1x_Unterspannung_MSA_Start != 0U)
#    error "Enumeration constant <Cb0xxx1x_Unterspannung_MSA_Start> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xxx1x_Unterspannung_MSA_Start (0U)
#   define Cb0xxx1x_Unterspannung_MSA_Start (0U)
#  endif
#  if (defined RTE_CONST_Cb0xxx0x_Keine_Unterspannung_MSA_Start) || (defined Cb0xxx0x_Keine_Unterspannung_MSA_Start)
#   if (!defined RTE_CONST_Cb0xxx0x_Keine_Unterspannung_MSA_Start) || (RTE_CONST_Cb0xxx0x_Keine_Unterspannung_MSA_Start != 0U)
#    error "Enumeration constant <Cb0xxx0x_Keine_Unterspannung_MSA_Start> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xxx0x_Keine_Unterspannung_MSA_Start (0U)
#   define Cb0xxx0x_Keine_Unterspannung_MSA_Start (0U)
#  endif
#  if (defined RTE_CONST_Cb0xx1xx_Ueberspannung) || (defined Cb0xx1xx_Ueberspannung)
#   if (!defined RTE_CONST_Cb0xx1xx_Ueberspannung) || (RTE_CONST_Cb0xx1xx_Ueberspannung != 0U)
#    error "Enumeration constant <Cb0xx1xx_Ueberspannung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xx1xx_Ueberspannung (0U)
#   define Cb0xx1xx_Ueberspannung (0U)
#  endif
#  if (defined RTE_CONST_Cb0xx0xx_Keine_Ueberspannung) || (defined Cb0xx0xx_Keine_Ueberspannung)
#   if (!defined RTE_CONST_Cb0xx0xx_Keine_Ueberspannung) || (RTE_CONST_Cb0xx0xx_Keine_Ueberspannung != 0U)
#    error "Enumeration constant <Cb0xx0xx_Keine_Ueberspannung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xx0xx_Keine_Ueberspannung (0U)
#   define Cb0xx0xx_Keine_Ueberspannung (0U)
#  endif
#  if (defined RTE_CONST_Cx3D_nicht_verfuegbar) || (defined Cx3D_nicht_verfuegbar)
#   if (!defined RTE_CONST_Cx3D_nicht_verfuegbar) || (RTE_CONST_Cx3D_nicht_verfuegbar != 61U)
#    error "Enumeration constant <Cx3D_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3D_nicht_verfuegbar (61U)
#   define Cx3D_nicht_verfuegbar (61U)
#  endif
#  if (defined RTE_CONST_Cx3E_Fehler) || (defined Cx3E_Fehler)
#   if (!defined RTE_CONST_Cx3E_Fehler) || (RTE_CONST_Cx3E_Fehler != 62U)
#    error "Enumeration constant <Cx3E_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3E_Fehler (62U)
#   define Cx3E_Fehler (62U)
#  endif
#  if (defined RTE_CONST_Cx3F_Signal_ungueltig) || (defined Cx3F_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3F_Signal_ungueltig) || (RTE_CONST_Cx3F_Signal_ungueltig != 63U)
#    error "Enumeration constant <Cx3F_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3F_Signal_ungueltig (63U)
#   define Cx3F_Signal_ungueltig (63U)
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

#  define Rte_TypeDef_New_Coding_110
typedef uint8 New_Coding_110;
#  define New_Coding_110_LowerLimit (0U)
#  define New_Coding_110_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_110 (15U)
#  define InvalidValue_New_Coding_110 (15U)
#  if (defined RTE_CONST_Cx1_Normalbetrieb) || (defined Cx1_Normalbetrieb)
#   if (!defined RTE_CONST_Cx1_Normalbetrieb) || (RTE_CONST_Cx1_Normalbetrieb != 1U)
#    error "Enumeration constant <Cx1_Normalbetrieb> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Normalbetrieb (1U)
#   define Cx1_Normalbetrieb (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Traktionsoptimiert_Stufe_1) || (defined Cx2_Traktionsoptimiert_Stufe_1)
#   if (!defined RTE_CONST_Cx2_Traktionsoptimiert_Stufe_1) || (RTE_CONST_Cx2_Traktionsoptimiert_Stufe_1 != 2U)
#    error "Enumeration constant <Cx2_Traktionsoptimiert_Stufe_1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Traktionsoptimiert_Stufe_1 (2U)
#   define Cx2_Traktionsoptimiert_Stufe_1 (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Traktionsoptimiert_Stufe_2) || (defined Cx3_Traktionsoptimiert_Stufe_2)
#   if (!defined RTE_CONST_Cx3_Traktionsoptimiert_Stufe_2) || (RTE_CONST_Cx3_Traktionsoptimiert_Stufe_2 != 3U)
#    error "Enumeration constant <Cx3_Traktionsoptimiert_Stufe_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Traktionsoptimiert_Stufe_2 (3U)
#   define Cx3_Traktionsoptimiert_Stufe_2 (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Traktionsoptimiert_Stufe_3) || (defined Cx4_Traktionsoptimiert_Stufe_3)
#   if (!defined RTE_CONST_Cx4_Traktionsoptimiert_Stufe_3) || (RTE_CONST_Cx4_Traktionsoptimiert_Stufe_3 != 4U)
#    error "Enumeration constant <Cx4_Traktionsoptimiert_Stufe_3> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Traktionsoptimiert_Stufe_3 (4U)
#   define Cx4_Traktionsoptimiert_Stufe_3 (4U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_111
typedef uint8 New_Coding_111;
#  define New_Coding_111_LowerLimit (0U)
#  define New_Coding_111_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_111 (15U)
#  define InvalidValue_New_Coding_111 (15U)
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_112
typedef uint8 New_Coding_112;
#  define New_Coding_112_LowerLimit (0U)
#  define New_Coding_112_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_112 (15U)
#  define InvalidValue_New_Coding_112 (15U)
#  if (defined RTE_CONST_Cx0_Keine_Anforderung) || (defined Cx0_Keine_Anforderung)
#   if (!defined RTE_CONST_Cx0_Keine_Anforderung) || (RTE_CONST_Cx0_Keine_Anforderung != 0U)
#    error "Enumeration constant <Cx0_Keine_Anforderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Keine_Anforderung (0U)
#   define Cx0_Keine_Anforderung (0U)
#  endif
#  if (defined RTE_CONST_Cb0xx1_Automatische_Parkunterstuetzung_unterbinden) || (defined Cb0xx1_Automatische_Parkunterstuetzung_unterbinden)
#   if (!defined RTE_CONST_Cb0xx1_Automatische_Parkunterstuetzung_unterbinden) || (RTE_CONST_Cb0xx1_Automatische_Parkunterstuetzung_unterbinden != 0U)
#    error "Enumeration constant <Cb0xx1_Automatische_Parkunterstuetzung_unterbinden> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xx1_Automatische_Parkunterstuetzung_unterbinden (0U)
#   define Cb0xx1_Automatische_Parkunterstuetzung_unterbinden (0U)
#  endif
#  if (defined RTE_CONST_Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden) || (defined Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden)
#   if (!defined RTE_CONST_Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden) || (RTE_CONST_Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden != 0U)
#    error "Enumeration constant <Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden (0U)
#   define Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden (0U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_65
typedef uint8 New_Coding_65;
#  define New_Coding_65_LowerLimit (0U)
#  define New_Coding_65_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_65 (15U)
#  define InvalidValue_New_Coding_65 (15U)
#  if (defined RTE_CONST_Cx0_Anzeigesegment_AUS) || (defined Cx0_Anzeigesegment_AUS)
#   if (!defined RTE_CONST_Cx0_Anzeigesegment_AUS) || (RTE_CONST_Cx0_Anzeigesegment_AUS != 0U)
#    error "Enumeration constant <Cx0_Anzeigesegment_AUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Anzeigesegment_AUS (0U)
#   define Cx0_Anzeigesegment_AUS (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken) || (defined Cx1_Anzeigesegment_AN__kein_Blinken)
#   if (!defined RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken) || (RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken != 1U)
#    error "Enumeration constant <Cx1_Anzeigesegment_AN__kein_Blinken> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken (1U)
#   define Cx1_Anzeigesegment_AN__kein_Blinken (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1) || (defined Cx2_Anzeigesegment_AN__Blinken_Stufe_1)
#   if (!defined RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1) || (RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1 != 2U)
#    error "Enumeration constant <Cx2_Anzeigesegment_AN__Blinken_Stufe_1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
#   define Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2) || (defined Cx3_Anzeigesegment_AN__Blinken_Stufe_2)
#   if (!defined RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2) || (RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2 != 3U)
#    error "Enumeration constant <Cx3_Anzeigesegment_AN__Blinken_Stufe_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
#   define Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3) || (defined Cx4_Anzeigesegment_AN__Blinken_Stufe_3)
#   if (!defined RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3) || (RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3 != 4U)
#    error "Enumeration constant <Cx4_Anzeigesegment_AN__Blinken_Stufe_3> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
#   define Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
#  endif
#  if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#   if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#    error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Initialisierung (8U)
#   define Cx8_Initialisierung (8U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_66
typedef uint8 New_Coding_66;
#  define New_Coding_66_LowerLimit (0U)
#  define New_Coding_66_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_66 (15U)
#  define InvalidValue_New_Coding_66 (15U)
#  if (defined RTE_CONST_Cx0_Anzeigesegment_AUS) || (defined Cx0_Anzeigesegment_AUS)
#   if (!defined RTE_CONST_Cx0_Anzeigesegment_AUS) || (RTE_CONST_Cx0_Anzeigesegment_AUS != 0U)
#    error "Enumeration constant <Cx0_Anzeigesegment_AUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Anzeigesegment_AUS (0U)
#   define Cx0_Anzeigesegment_AUS (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken) || (defined Cx1_Anzeigesegment_AN__kein_Blinken)
#   if (!defined RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken) || (RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken != 1U)
#    error "Enumeration constant <Cx1_Anzeigesegment_AN__kein_Blinken> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken (1U)
#   define Cx1_Anzeigesegment_AN__kein_Blinken (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1) || (defined Cx2_Anzeigesegment_AN__Blinken_Stufe_1)
#   if (!defined RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1) || (RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1 != 2U)
#    error "Enumeration constant <Cx2_Anzeigesegment_AN__Blinken_Stufe_1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
#   define Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2) || (defined Cx3_Anzeigesegment_AN__Blinken_Stufe_2)
#   if (!defined RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2) || (RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2 != 3U)
#    error "Enumeration constant <Cx3_Anzeigesegment_AN__Blinken_Stufe_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
#   define Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3) || (defined Cx4_Anzeigesegment_AN__Blinken_Stufe_3)
#   if (!defined RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3) || (RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3 != 4U)
#    error "Enumeration constant <Cx4_Anzeigesegment_AN__Blinken_Stufe_3> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
#   define Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
#  endif
#  if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#   if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#    error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Initialisierung (8U)
#   define Cx8_Initialisierung (8U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_67
typedef uint8 New_Coding_67;
#  define New_Coding_67_LowerLimit (0U)
#  define New_Coding_67_UpperLimit (3U)
#  define Rte_InvalidValue_New_Coding_67 (3U)
#  define InvalidValue_New_Coding_67 (3U)
#  if (defined RTE_CONST_Cx0_Kein_Wert) || (defined Cx0_Kein_Wert)
#   if (!defined RTE_CONST_Cx0_Kein_Wert) || (RTE_CONST_Cx0_Kein_Wert != 0U)
#    error "Enumeration constant <Cx0_Kein_Wert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Kein_Wert (0U)
#   define Cx0_Kein_Wert (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Mit_Trigger_beenden) || (defined Cx1_Mit_Trigger_beenden)
#   if (!defined RTE_CONST_Cx1_Mit_Trigger_beenden) || (RTE_CONST_Cx1_Mit_Trigger_beenden != 1U)
#    error "Enumeration constant <Cx1_Mit_Trigger_beenden> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Mit_Trigger_beenden (1U)
#   define Cx1_Mit_Trigger_beenden (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Mit_Aktivzeit_beenden) || (defined Cx2_Mit_Aktivzeit_beenden)
#   if (!defined RTE_CONST_Cx2_Mit_Aktivzeit_beenden) || (RTE_CONST_Cx2_Mit_Aktivzeit_beenden != 2U)
#    error "Enumeration constant <Cx2_Mit_Aktivzeit_beenden> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Mit_Aktivzeit_beenden (2U)
#   define Cx2_Mit_Aktivzeit_beenden (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#    error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_ungueltig (3U)
#   define Cx3_Signal_ungueltig (3U)
#  endif

#  define Rte_TypeDef_New_Coding_68
typedef uint8 New_Coding_68;
#  define New_Coding_68_LowerLimit (0U)
#  define New_Coding_68_UpperLimit (3U)
#  define Rte_InvalidValue_New_Coding_68 (3U)
#  define InvalidValue_New_Coding_68 (3U)
#  if (defined RTE_CONST_Cx0_Vibration_AUS) || (defined Cx0_Vibration_AUS)
#   if (!defined RTE_CONST_Cx0_Vibration_AUS) || (RTE_CONST_Cx0_Vibration_AUS != 0U)
#    error "Enumeration constant <Cx0_Vibration_AUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Vibration_AUS (0U)
#   define Cx0_Vibration_AUS (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Vibration_EIN__dauerhaft) || (defined Cx1_Vibration_EIN__dauerhaft)
#   if (!defined RTE_CONST_Cx1_Vibration_EIN__dauerhaft) || (RTE_CONST_Cx1_Vibration_EIN__dauerhaft != 1U)
#    error "Enumeration constant <Cx1_Vibration_EIN__dauerhaft> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Vibration_EIN__dauerhaft (1U)
#   define Cx1_Vibration_EIN__dauerhaft (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Vibration_EIN__intermittierend) || (defined Cx2_Vibration_EIN__intermittierend)
#   if (!defined RTE_CONST_Cx2_Vibration_EIN__intermittierend) || (RTE_CONST_Cx2_Vibration_EIN__intermittierend != 2U)
#    error "Enumeration constant <Cx2_Vibration_EIN__intermittierend> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Vibration_EIN__intermittierend (2U)
#   define Cx2_Vibration_EIN__intermittierend (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#    error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_ungueltig (3U)
#   define Cx3_Signal_ungueltig (3U)
#  endif

#  define Rte_TypeDef_New_Coding_71
typedef uint8 New_Coding_71;
#  define New_Coding_71_LowerLimit (0U)
#  define New_Coding_71_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_71 (15U)
#  define InvalidValue_New_Coding_71 (15U)
#  if (defined RTE_CONST_Cx0_Keine_haptische_Warnung) || (defined Cx0_Keine_haptische_Warnung)
#   if (!defined RTE_CONST_Cx0_Keine_haptische_Warnung) || (RTE_CONST_Cx0_Keine_haptische_Warnung != 0U)
#    error "Enumeration constant <Cx0_Keine_haptische_Warnung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Keine_haptische_Warnung (0U)
#   define Cx0_Keine_haptische_Warnung (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Muster_1) || (defined Cx1_Muster_1)
#   if (!defined RTE_CONST_Cx1_Muster_1) || (RTE_CONST_Cx1_Muster_1 != 1U)
#    error "Enumeration constant <Cx1_Muster_1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Muster_1 (1U)
#   define Cx1_Muster_1 (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Muster_2) || (defined Cx2_Muster_2)
#   if (!defined RTE_CONST_Cx2_Muster_2) || (RTE_CONST_Cx2_Muster_2 != 2U)
#    error "Enumeration constant <Cx2_Muster_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Muster_2 (2U)
#   define Cx2_Muster_2 (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Muster_3) || (defined Cx3_Muster_3)
#   if (!defined RTE_CONST_Cx3_Muster_3) || (RTE_CONST_Cx3_Muster_3 != 3U)
#    error "Enumeration constant <Cx3_Muster_3> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Muster_3 (3U)
#   define Cx3_Muster_3 (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Muster_4) || (defined Cx4_Muster_4)
#   if (!defined RTE_CONST_Cx4_Muster_4) || (RTE_CONST_Cx4_Muster_4 != 4U)
#    error "Enumeration constant <Cx4_Muster_4> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Muster_4 (4U)
#   define Cx4_Muster_4 (4U)
#  endif
#  if (defined RTE_CONST_Cx5_Muster_5) || (defined Cx5_Muster_5)
#   if (!defined RTE_CONST_Cx5_Muster_5) || (RTE_CONST_Cx5_Muster_5 != 5U)
#    error "Enumeration constant <Cx5_Muster_5> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx5_Muster_5 (5U)
#   define Cx5_Muster_5 (5U)
#  endif
#  if (defined RTE_CONST_Cx6_Muster_6) || (defined Cx6_Muster_6)
#   if (!defined RTE_CONST_Cx6_Muster_6) || (RTE_CONST_Cx6_Muster_6 != 6U)
#    error "Enumeration constant <Cx6_Muster_6> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Muster_6 (6U)
#   define Cx6_Muster_6 (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Muster_7) || (defined Cx7_Muster_7)
#   if (!defined RTE_CONST_Cx7_Muster_7) || (RTE_CONST_Cx7_Muster_7 != 7U)
#    error "Enumeration constant <Cx7_Muster_7> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Muster_7 (7U)
#   define Cx7_Muster_7 (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Muster_8) || (defined Cx8_Muster_8)
#   if (!defined RTE_CONST_Cx8_Muster_8) || (RTE_CONST_Cx8_Muster_8 != 8U)
#    error "Enumeration constant <Cx8_Muster_8> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Muster_8 (8U)
#   define Cx8_Muster_8 (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Muster_9) || (defined Cx9_Muster_9)
#   if (!defined RTE_CONST_Cx9_Muster_9) || (RTE_CONST_Cx9_Muster_9 != 9U)
#    error "Enumeration constant <Cx9_Muster_9> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Muster_9 (9U)
#   define Cx9_Muster_9 (9U)
#  endif
#  if (defined RTE_CONST_CxA_Muster_10) || (defined CxA_Muster_10)
#   if (!defined RTE_CONST_CxA_Muster_10) || (RTE_CONST_CxA_Muster_10 != 10U)
#    error "Enumeration constant <CxA_Muster_10> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Muster_10 (10U)
#   define CxA_Muster_10 (10U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_72
typedef uint8 New_Coding_72;
#  define New_Coding_72_LowerLimit (0U)
#  define New_Coding_72_UpperLimit (255U)
#  define Rte_InvalidValue_New_Coding_72 (255U)
#  define InvalidValue_New_Coding_72 (255U)
#  if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#    error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#   define CxFF_Signal_unbefuellt (255U)
#  endif

#  define Rte_TypeDef_New_Coding_73
typedef uint8 New_Coding_73;
#  define New_Coding_73_LowerLimit (0U)
#  define New_Coding_73_UpperLimit (3U)
#  define Rte_InvalidValue_New_Coding_73 (3U)
#  define InvalidValue_New_Coding_73 (3U)
#  if (defined RTE_CONST_Cx0_Keine_Richtung) || (defined Cx0_Keine_Richtung)
#   if (!defined RTE_CONST_Cx0_Keine_Richtung) || (RTE_CONST_Cx0_Keine_Richtung != 0U)
#    error "Enumeration constant <Cx0_Keine_Richtung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Keine_Richtung (0U)
#   define Cx0_Keine_Richtung (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Richtung_links) || (defined Cx1_Richtung_links)
#   if (!defined RTE_CONST_Cx1_Richtung_links) || (RTE_CONST_Cx1_Richtung_links != 1U)
#    error "Enumeration constant <Cx1_Richtung_links> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Richtung_links (1U)
#   define Cx1_Richtung_links (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Richtung_rechts) || (defined Cx2_Richtung_rechts)
#   if (!defined RTE_CONST_Cx2_Richtung_rechts) || (RTE_CONST_Cx2_Richtung_rechts != 2U)
#    error "Enumeration constant <Cx2_Richtung_rechts> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Richtung_rechts (2U)
#   define Cx2_Richtung_rechts (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_unbefuellt) || (defined Cx3_Signal_unbefuellt)
#   if (!defined RTE_CONST_Cx3_Signal_unbefuellt) || (RTE_CONST_Cx3_Signal_unbefuellt != 3U)
#    error "Enumeration constant <Cx3_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_unbefuellt (3U)
#   define Cx3_Signal_unbefuellt (3U)
#  endif

#  define Rte_TypeDef_New_Coding_74
typedef uint8 New_Coding_74;
#  define New_Coding_74_LowerLimit (0U)
#  define New_Coding_74_UpperLimit (63U)
#  define Rte_InvalidValue_New_Coding_74 (63U)
#  define InvalidValue_New_Coding_74 (63U)
#  if (defined RTE_CONST_Cx00_Intensitaetsstufen1) || (defined Cx00_Intensitaetsstufen1)
#   if (!defined RTE_CONST_Cx00_Intensitaetsstufen1) || (RTE_CONST_Cx00_Intensitaetsstufen1 != 0U)
#    error "Enumeration constant <Cx00_Intensitaetsstufen1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx00_Intensitaetsstufen1 (0U)
#   define Cx00_Intensitaetsstufen1 (0U)
#  endif
#  if (defined RTE_CONST_Cx01_Intensitaetsstufen2) || (defined Cx01_Intensitaetsstufen2)
#   if (!defined RTE_CONST_Cx01_Intensitaetsstufen2) || (RTE_CONST_Cx01_Intensitaetsstufen2 != 1U)
#    error "Enumeration constant <Cx01_Intensitaetsstufen2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx01_Intensitaetsstufen2 (1U)
#   define Cx01_Intensitaetsstufen2 (1U)
#  endif
#  if (defined RTE_CONST_Cx02_Intensitaetsstufen3) || (defined Cx02_Intensitaetsstufen3)
#   if (!defined RTE_CONST_Cx02_Intensitaetsstufen3) || (RTE_CONST_Cx02_Intensitaetsstufen3 != 2U)
#    error "Enumeration constant <Cx02_Intensitaetsstufen3> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02_Intensitaetsstufen3 (2U)
#   define Cx02_Intensitaetsstufen3 (2U)
#  endif
#  if (defined RTE_CONST_Cx03_Intensitaetsstufen4) || (defined Cx03_Intensitaetsstufen4)
#   if (!defined RTE_CONST_Cx03_Intensitaetsstufen4) || (RTE_CONST_Cx03_Intensitaetsstufen4 != 3U)
#    error "Enumeration constant <Cx03_Intensitaetsstufen4> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03_Intensitaetsstufen4 (3U)
#   define Cx03_Intensitaetsstufen4 (3U)
#  endif
#  if (defined RTE_CONST_Cx04_Intensitaetsstufen5) || (defined Cx04_Intensitaetsstufen5)
#   if (!defined RTE_CONST_Cx04_Intensitaetsstufen5) || (RTE_CONST_Cx04_Intensitaetsstufen5 != 4U)
#    error "Enumeration constant <Cx04_Intensitaetsstufen5> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx04_Intensitaetsstufen5 (4U)
#   define Cx04_Intensitaetsstufen5 (4U)
#  endif
#  if (defined RTE_CONST_Cx05_Intensitaetsstufen6) || (defined Cx05_Intensitaetsstufen6)
#   if (!defined RTE_CONST_Cx05_Intensitaetsstufen6) || (RTE_CONST_Cx05_Intensitaetsstufen6 != 5U)
#    error "Enumeration constant <Cx05_Intensitaetsstufen6> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx05_Intensitaetsstufen6 (5U)
#   define Cx05_Intensitaetsstufen6 (5U)
#  endif
#  if (defined RTE_CONST_Cx06_Intensitaetsstufen7) || (defined Cx06_Intensitaetsstufen7)
#   if (!defined RTE_CONST_Cx06_Intensitaetsstufen7) || (RTE_CONST_Cx06_Intensitaetsstufen7 != 6U)
#    error "Enumeration constant <Cx06_Intensitaetsstufen7> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx06_Intensitaetsstufen7 (6U)
#   define Cx06_Intensitaetsstufen7 (6U)
#  endif
#  if (defined RTE_CONST_Cx07_Intensitaetsstufen8) || (defined Cx07_Intensitaetsstufen8)
#   if (!defined RTE_CONST_Cx07_Intensitaetsstufen8) || (RTE_CONST_Cx07_Intensitaetsstufen8 != 7U)
#    error "Enumeration constant <Cx07_Intensitaetsstufen8> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx07_Intensitaetsstufen8 (7U)
#   define Cx07_Intensitaetsstufen8 (7U)
#  endif
#  if (defined RTE_CONST_Cx08_Intensitaetsstufen9) || (defined Cx08_Intensitaetsstufen9)
#   if (!defined RTE_CONST_Cx08_Intensitaetsstufen9) || (RTE_CONST_Cx08_Intensitaetsstufen9 != 8U)
#    error "Enumeration constant <Cx08_Intensitaetsstufen9> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx08_Intensitaetsstufen9 (8U)
#   define Cx08_Intensitaetsstufen9 (8U)
#  endif
#  if (defined RTE_CONST_Cx09_Intensitaetsstufen10) || (defined Cx09_Intensitaetsstufen10)
#   if (!defined RTE_CONST_Cx09_Intensitaetsstufen10) || (RTE_CONST_Cx09_Intensitaetsstufen10 != 9U)
#    error "Enumeration constant <Cx09_Intensitaetsstufen10> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx09_Intensitaetsstufen10 (9U)
#   define Cx09_Intensitaetsstufen10 (9U)
#  endif
#  if (defined RTE_CONST_Cx0A_Intensitaetsstufen11) || (defined Cx0A_Intensitaetsstufen11)
#   if (!defined RTE_CONST_Cx0A_Intensitaetsstufen11) || (RTE_CONST_Cx0A_Intensitaetsstufen11 != 10U)
#    error "Enumeration constant <Cx0A_Intensitaetsstufen11> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0A_Intensitaetsstufen11 (10U)
#   define Cx0A_Intensitaetsstufen11 (10U)
#  endif
#  if (defined RTE_CONST_Cx0B_Intensitaetsstufen12) || (defined Cx0B_Intensitaetsstufen12)
#   if (!defined RTE_CONST_Cx0B_Intensitaetsstufen12) || (RTE_CONST_Cx0B_Intensitaetsstufen12 != 11U)
#    error "Enumeration constant <Cx0B_Intensitaetsstufen12> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0B_Intensitaetsstufen12 (11U)
#   define Cx0B_Intensitaetsstufen12 (11U)
#  endif
#  if (defined RTE_CONST_Cx0C_Intensitaetsstufen13) || (defined Cx0C_Intensitaetsstufen13)
#   if (!defined RTE_CONST_Cx0C_Intensitaetsstufen13) || (RTE_CONST_Cx0C_Intensitaetsstufen13 != 12U)
#    error "Enumeration constant <Cx0C_Intensitaetsstufen13> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0C_Intensitaetsstufen13 (12U)
#   define Cx0C_Intensitaetsstufen13 (12U)
#  endif
#  if (defined RTE_CONST_Cx0D_Intensitaetsstufen14) || (defined Cx0D_Intensitaetsstufen14)
#   if (!defined RTE_CONST_Cx0D_Intensitaetsstufen14) || (RTE_CONST_Cx0D_Intensitaetsstufen14 != 13U)
#    error "Enumeration constant <Cx0D_Intensitaetsstufen14> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0D_Intensitaetsstufen14 (13U)
#   define Cx0D_Intensitaetsstufen14 (13U)
#  endif
#  if (defined RTE_CONST_Cx0E_Intensitaetsstufen15) || (defined Cx0E_Intensitaetsstufen15)
#   if (!defined RTE_CONST_Cx0E_Intensitaetsstufen15) || (RTE_CONST_Cx0E_Intensitaetsstufen15 != 14U)
#    error "Enumeration constant <Cx0E_Intensitaetsstufen15> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0E_Intensitaetsstufen15 (14U)
#   define Cx0E_Intensitaetsstufen15 (14U)
#  endif
#  if (defined RTE_CONST_Cx0F_Intensitaetsstufen16) || (defined Cx0F_Intensitaetsstufen16)
#   if (!defined RTE_CONST_Cx0F_Intensitaetsstufen16) || (RTE_CONST_Cx0F_Intensitaetsstufen16 != 15U)
#    error "Enumeration constant <Cx0F_Intensitaetsstufen16> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0F_Intensitaetsstufen16 (15U)
#   define Cx0F_Intensitaetsstufen16 (15U)
#  endif
#  if (defined RTE_CONST_Cx10_Intensitaetsstufen17) || (defined Cx10_Intensitaetsstufen17)
#   if (!defined RTE_CONST_Cx10_Intensitaetsstufen17) || (RTE_CONST_Cx10_Intensitaetsstufen17 != 16U)
#    error "Enumeration constant <Cx10_Intensitaetsstufen17> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx10_Intensitaetsstufen17 (16U)
#   define Cx10_Intensitaetsstufen17 (16U)
#  endif
#  if (defined RTE_CONST_Cx11_Intensitaetsstufen18) || (defined Cx11_Intensitaetsstufen18)
#   if (!defined RTE_CONST_Cx11_Intensitaetsstufen18) || (RTE_CONST_Cx11_Intensitaetsstufen18 != 17U)
#    error "Enumeration constant <Cx11_Intensitaetsstufen18> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx11_Intensitaetsstufen18 (17U)
#   define Cx11_Intensitaetsstufen18 (17U)
#  endif
#  if (defined RTE_CONST_Cx12_Intensitaetsstufen19) || (defined Cx12_Intensitaetsstufen19)
#   if (!defined RTE_CONST_Cx12_Intensitaetsstufen19) || (RTE_CONST_Cx12_Intensitaetsstufen19 != 18U)
#    error "Enumeration constant <Cx12_Intensitaetsstufen19> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx12_Intensitaetsstufen19 (18U)
#   define Cx12_Intensitaetsstufen19 (18U)
#  endif
#  if (defined RTE_CONST_Cx13_Intensitaetsstufen20) || (defined Cx13_Intensitaetsstufen20)
#   if (!defined RTE_CONST_Cx13_Intensitaetsstufen20) || (RTE_CONST_Cx13_Intensitaetsstufen20 != 19U)
#    error "Enumeration constant <Cx13_Intensitaetsstufen20> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx13_Intensitaetsstufen20 (19U)
#   define Cx13_Intensitaetsstufen20 (19U)
#  endif
#  if (defined RTE_CONST_Cx14_Intensitaetsstufen21) || (defined Cx14_Intensitaetsstufen21)
#   if (!defined RTE_CONST_Cx14_Intensitaetsstufen21) || (RTE_CONST_Cx14_Intensitaetsstufen21 != 20U)
#    error "Enumeration constant <Cx14_Intensitaetsstufen21> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx14_Intensitaetsstufen21 (20U)
#   define Cx14_Intensitaetsstufen21 (20U)
#  endif
#  if (defined RTE_CONST_Cx15_Intensitaetsstufen22) || (defined Cx15_Intensitaetsstufen22)
#   if (!defined RTE_CONST_Cx15_Intensitaetsstufen22) || (RTE_CONST_Cx15_Intensitaetsstufen22 != 21U)
#    error "Enumeration constant <Cx15_Intensitaetsstufen22> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx15_Intensitaetsstufen22 (21U)
#   define Cx15_Intensitaetsstufen22 (21U)
#  endif
#  if (defined RTE_CONST_Cx16_Intensitaetsstufen23) || (defined Cx16_Intensitaetsstufen23)
#   if (!defined RTE_CONST_Cx16_Intensitaetsstufen23) || (RTE_CONST_Cx16_Intensitaetsstufen23 != 22U)
#    error "Enumeration constant <Cx16_Intensitaetsstufen23> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx16_Intensitaetsstufen23 (22U)
#   define Cx16_Intensitaetsstufen23 (22U)
#  endif
#  if (defined RTE_CONST_Cx17_Intensitaetsstufen24) || (defined Cx17_Intensitaetsstufen24)
#   if (!defined RTE_CONST_Cx17_Intensitaetsstufen24) || (RTE_CONST_Cx17_Intensitaetsstufen24 != 23U)
#    error "Enumeration constant <Cx17_Intensitaetsstufen24> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx17_Intensitaetsstufen24 (23U)
#   define Cx17_Intensitaetsstufen24 (23U)
#  endif
#  if (defined RTE_CONST_Cx18_Intensitaetsstufen25) || (defined Cx18_Intensitaetsstufen25)
#   if (!defined RTE_CONST_Cx18_Intensitaetsstufen25) || (RTE_CONST_Cx18_Intensitaetsstufen25 != 24U)
#    error "Enumeration constant <Cx18_Intensitaetsstufen25> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx18_Intensitaetsstufen25 (24U)
#   define Cx18_Intensitaetsstufen25 (24U)
#  endif
#  if (defined RTE_CONST_Cx19_Intensitaetsstufen26) || (defined Cx19_Intensitaetsstufen26)
#   if (!defined RTE_CONST_Cx19_Intensitaetsstufen26) || (RTE_CONST_Cx19_Intensitaetsstufen26 != 25U)
#    error "Enumeration constant <Cx19_Intensitaetsstufen26> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx19_Intensitaetsstufen26 (25U)
#   define Cx19_Intensitaetsstufen26 (25U)
#  endif
#  if (defined RTE_CONST_Cx1A_Intensitaetsstufen27) || (defined Cx1A_Intensitaetsstufen27)
#   if (!defined RTE_CONST_Cx1A_Intensitaetsstufen27) || (RTE_CONST_Cx1A_Intensitaetsstufen27 != 26U)
#    error "Enumeration constant <Cx1A_Intensitaetsstufen27> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1A_Intensitaetsstufen27 (26U)
#   define Cx1A_Intensitaetsstufen27 (26U)
#  endif
#  if (defined RTE_CONST_Cx1B_Intensitaetsstufen28) || (defined Cx1B_Intensitaetsstufen28)
#   if (!defined RTE_CONST_Cx1B_Intensitaetsstufen28) || (RTE_CONST_Cx1B_Intensitaetsstufen28 != 27U)
#    error "Enumeration constant <Cx1B_Intensitaetsstufen28> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1B_Intensitaetsstufen28 (27U)
#   define Cx1B_Intensitaetsstufen28 (27U)
#  endif
#  if (defined RTE_CONST_Cx1C_Intensitaetsstufen29) || (defined Cx1C_Intensitaetsstufen29)
#   if (!defined RTE_CONST_Cx1C_Intensitaetsstufen29) || (RTE_CONST_Cx1C_Intensitaetsstufen29 != 28U)
#    error "Enumeration constant <Cx1C_Intensitaetsstufen29> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1C_Intensitaetsstufen29 (28U)
#   define Cx1C_Intensitaetsstufen29 (28U)
#  endif
#  if (defined RTE_CONST_Cx1D_Intensitaetsstufen30) || (defined Cx1D_Intensitaetsstufen30)
#   if (!defined RTE_CONST_Cx1D_Intensitaetsstufen30) || (RTE_CONST_Cx1D_Intensitaetsstufen30 != 29U)
#    error "Enumeration constant <Cx1D_Intensitaetsstufen30> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1D_Intensitaetsstufen30 (29U)
#   define Cx1D_Intensitaetsstufen30 (29U)
#  endif
#  if (defined RTE_CONST_Cx1E_Intensitaetsstufen31) || (defined Cx1E_Intensitaetsstufen31)
#   if (!defined RTE_CONST_Cx1E_Intensitaetsstufen31) || (RTE_CONST_Cx1E_Intensitaetsstufen31 != 30U)
#    error "Enumeration constant <Cx1E_Intensitaetsstufen31> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1E_Intensitaetsstufen31 (30U)
#   define Cx1E_Intensitaetsstufen31 (30U)
#  endif
#  if (defined RTE_CONST_Cx1F_Intensitaetsstufen32) || (defined Cx1F_Intensitaetsstufen32)
#   if (!defined RTE_CONST_Cx1F_Intensitaetsstufen32) || (RTE_CONST_Cx1F_Intensitaetsstufen32 != 31U)
#    error "Enumeration constant <Cx1F_Intensitaetsstufen32> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1F_Intensitaetsstufen32 (31U)
#   define Cx1F_Intensitaetsstufen32 (31U)
#  endif
#  if (defined RTE_CONST_Cx20_Intensitaetsstufen33) || (defined Cx20_Intensitaetsstufen33)
#   if (!defined RTE_CONST_Cx20_Intensitaetsstufen33) || (RTE_CONST_Cx20_Intensitaetsstufen33 != 32U)
#    error "Enumeration constant <Cx20_Intensitaetsstufen33> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx20_Intensitaetsstufen33 (32U)
#   define Cx20_Intensitaetsstufen33 (32U)
#  endif
#  if (defined RTE_CONST_Cx21_Intensitaetsstufen34) || (defined Cx21_Intensitaetsstufen34)
#   if (!defined RTE_CONST_Cx21_Intensitaetsstufen34) || (RTE_CONST_Cx21_Intensitaetsstufen34 != 33U)
#    error "Enumeration constant <Cx21_Intensitaetsstufen34> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx21_Intensitaetsstufen34 (33U)
#   define Cx21_Intensitaetsstufen34 (33U)
#  endif
#  if (defined RTE_CONST_Cx22_Intensitaetsstufen35) || (defined Cx22_Intensitaetsstufen35)
#   if (!defined RTE_CONST_Cx22_Intensitaetsstufen35) || (RTE_CONST_Cx22_Intensitaetsstufen35 != 34U)
#    error "Enumeration constant <Cx22_Intensitaetsstufen35> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx22_Intensitaetsstufen35 (34U)
#   define Cx22_Intensitaetsstufen35 (34U)
#  endif
#  if (defined RTE_CONST_Cx23_Intensitaetsstufen36) || (defined Cx23_Intensitaetsstufen36)
#   if (!defined RTE_CONST_Cx23_Intensitaetsstufen36) || (RTE_CONST_Cx23_Intensitaetsstufen36 != 35U)
#    error "Enumeration constant <Cx23_Intensitaetsstufen36> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx23_Intensitaetsstufen36 (35U)
#   define Cx23_Intensitaetsstufen36 (35U)
#  endif
#  if (defined RTE_CONST_Cx24_Intensitaetsstufen37) || (defined Cx24_Intensitaetsstufen37)
#   if (!defined RTE_CONST_Cx24_Intensitaetsstufen37) || (RTE_CONST_Cx24_Intensitaetsstufen37 != 36U)
#    error "Enumeration constant <Cx24_Intensitaetsstufen37> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx24_Intensitaetsstufen37 (36U)
#   define Cx24_Intensitaetsstufen37 (36U)
#  endif
#  if (defined RTE_CONST_Cx25_Intensitaetsstufen38) || (defined Cx25_Intensitaetsstufen38)
#   if (!defined RTE_CONST_Cx25_Intensitaetsstufen38) || (RTE_CONST_Cx25_Intensitaetsstufen38 != 37U)
#    error "Enumeration constant <Cx25_Intensitaetsstufen38> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx25_Intensitaetsstufen38 (37U)
#   define Cx25_Intensitaetsstufen38 (37U)
#  endif
#  if (defined RTE_CONST_Cx26_Intensitaetsstufen39) || (defined Cx26_Intensitaetsstufen39)
#   if (!defined RTE_CONST_Cx26_Intensitaetsstufen39) || (RTE_CONST_Cx26_Intensitaetsstufen39 != 38U)
#    error "Enumeration constant <Cx26_Intensitaetsstufen39> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx26_Intensitaetsstufen39 (38U)
#   define Cx26_Intensitaetsstufen39 (38U)
#  endif
#  if (defined RTE_CONST_Cx27_Intensitaetsstufen40) || (defined Cx27_Intensitaetsstufen40)
#   if (!defined RTE_CONST_Cx27_Intensitaetsstufen40) || (RTE_CONST_Cx27_Intensitaetsstufen40 != 39U)
#    error "Enumeration constant <Cx27_Intensitaetsstufen40> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx27_Intensitaetsstufen40 (39U)
#   define Cx27_Intensitaetsstufen40 (39U)
#  endif
#  if (defined RTE_CONST_Cx28_Intensitaetsstufen41) || (defined Cx28_Intensitaetsstufen41)
#   if (!defined RTE_CONST_Cx28_Intensitaetsstufen41) || (RTE_CONST_Cx28_Intensitaetsstufen41 != 40U)
#    error "Enumeration constant <Cx28_Intensitaetsstufen41> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx28_Intensitaetsstufen41 (40U)
#   define Cx28_Intensitaetsstufen41 (40U)
#  endif
#  if (defined RTE_CONST_Cx29_Intensitaetsstufen42) || (defined Cx29_Intensitaetsstufen42)
#   if (!defined RTE_CONST_Cx29_Intensitaetsstufen42) || (RTE_CONST_Cx29_Intensitaetsstufen42 != 41U)
#    error "Enumeration constant <Cx29_Intensitaetsstufen42> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx29_Intensitaetsstufen42 (41U)
#   define Cx29_Intensitaetsstufen42 (41U)
#  endif
#  if (defined RTE_CONST_Cx2A_Intensitaetsstufen43) || (defined Cx2A_Intensitaetsstufen43)
#   if (!defined RTE_CONST_Cx2A_Intensitaetsstufen43) || (RTE_CONST_Cx2A_Intensitaetsstufen43 != 42U)
#    error "Enumeration constant <Cx2A_Intensitaetsstufen43> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2A_Intensitaetsstufen43 (42U)
#   define Cx2A_Intensitaetsstufen43 (42U)
#  endif
#  if (defined RTE_CONST_Cx2B_Intensitaetsstufen44) || (defined Cx2B_Intensitaetsstufen44)
#   if (!defined RTE_CONST_Cx2B_Intensitaetsstufen44) || (RTE_CONST_Cx2B_Intensitaetsstufen44 != 43U)
#    error "Enumeration constant <Cx2B_Intensitaetsstufen44> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2B_Intensitaetsstufen44 (43U)
#   define Cx2B_Intensitaetsstufen44 (43U)
#  endif
#  if (defined RTE_CONST_Cx2C_Intensitaetsstufen45) || (defined Cx2C_Intensitaetsstufen45)
#   if (!defined RTE_CONST_Cx2C_Intensitaetsstufen45) || (RTE_CONST_Cx2C_Intensitaetsstufen45 != 44U)
#    error "Enumeration constant <Cx2C_Intensitaetsstufen45> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2C_Intensitaetsstufen45 (44U)
#   define Cx2C_Intensitaetsstufen45 (44U)
#  endif
#  if (defined RTE_CONST_Cx2D_Intensitaetsstufen46) || (defined Cx2D_Intensitaetsstufen46)
#   if (!defined RTE_CONST_Cx2D_Intensitaetsstufen46) || (RTE_CONST_Cx2D_Intensitaetsstufen46 != 45U)
#    error "Enumeration constant <Cx2D_Intensitaetsstufen46> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2D_Intensitaetsstufen46 (45U)
#   define Cx2D_Intensitaetsstufen46 (45U)
#  endif
#  if (defined RTE_CONST_Cx2E_Intensitaetsstufen47) || (defined Cx2E_Intensitaetsstufen47)
#   if (!defined RTE_CONST_Cx2E_Intensitaetsstufen47) || (RTE_CONST_Cx2E_Intensitaetsstufen47 != 46U)
#    error "Enumeration constant <Cx2E_Intensitaetsstufen47> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2E_Intensitaetsstufen47 (46U)
#   define Cx2E_Intensitaetsstufen47 (46U)
#  endif
#  if (defined RTE_CONST_Cx2F_Intensitaetsstufen48) || (defined Cx2F_Intensitaetsstufen48)
#   if (!defined RTE_CONST_Cx2F_Intensitaetsstufen48) || (RTE_CONST_Cx2F_Intensitaetsstufen48 != 47U)
#    error "Enumeration constant <Cx2F_Intensitaetsstufen48> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2F_Intensitaetsstufen48 (47U)
#   define Cx2F_Intensitaetsstufen48 (47U)
#  endif
#  if (defined RTE_CONST_Cx30_Intensitaetsstufen49) || (defined Cx30_Intensitaetsstufen49)
#   if (!defined RTE_CONST_Cx30_Intensitaetsstufen49) || (RTE_CONST_Cx30_Intensitaetsstufen49 != 48U)
#    error "Enumeration constant <Cx30_Intensitaetsstufen49> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx30_Intensitaetsstufen49 (48U)
#   define Cx30_Intensitaetsstufen49 (48U)
#  endif
#  if (defined RTE_CONST_Cx31_Intensitaetsstufen50) || (defined Cx31_Intensitaetsstufen50)
#   if (!defined RTE_CONST_Cx31_Intensitaetsstufen50) || (RTE_CONST_Cx31_Intensitaetsstufen50 != 49U)
#    error "Enumeration constant <Cx31_Intensitaetsstufen50> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx31_Intensitaetsstufen50 (49U)
#   define Cx31_Intensitaetsstufen50 (49U)
#  endif
#  if (defined RTE_CONST_Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar != 61U)
#    error "Enumeration constant <Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar (61U)
#   define Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar (61U)
#  endif
#  if (defined RTE_CONST_Cx3E_Funktion_meldet_Fehler) || (defined Cx3E_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_Cx3E_Funktion_meldet_Fehler) || (RTE_CONST_Cx3E_Funktion_meldet_Fehler != 62U)
#    error "Enumeration constant <Cx3E_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3E_Funktion_meldet_Fehler (62U)
#   define Cx3E_Funktion_meldet_Fehler (62U)
#  endif
#  if (defined RTE_CONST_Cx3F_Signal_unbefuellt) || (defined Cx3F_Signal_unbefuellt)
#   if (!defined RTE_CONST_Cx3F_Signal_unbefuellt) || (RTE_CONST_Cx3F_Signal_unbefuellt != 63U)
#    error "Enumeration constant <Cx3F_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3F_Signal_unbefuellt (63U)
#   define Cx3F_Signal_unbefuellt (63U)
#  endif

#  define Rte_TypeDef_New_Coding_75
typedef uint8 New_Coding_75;
#  define New_Coding_75_LowerLimit (0U)
#  define New_Coding_75_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_75 (15U)
#  define InvalidValue_New_Coding_75 (15U)
#  if (defined RTE_CONST_Cx0_Intensitaetsstufe_0) || (defined Cx0_Intensitaetsstufe_0)
#   if (!defined RTE_CONST_Cx0_Intensitaetsstufe_0) || (RTE_CONST_Cx0_Intensitaetsstufe_0 != 0U)
#    error "Enumeration constant <Cx0_Intensitaetsstufe_0> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Intensitaetsstufe_0 (0U)
#   define Cx0_Intensitaetsstufe_0 (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Intensitaetsstufe_1) || (defined Cx1_Intensitaetsstufe_1)
#   if (!defined RTE_CONST_Cx1_Intensitaetsstufe_1) || (RTE_CONST_Cx1_Intensitaetsstufe_1 != 1U)
#    error "Enumeration constant <Cx1_Intensitaetsstufe_1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Intensitaetsstufe_1 (1U)
#   define Cx1_Intensitaetsstufe_1 (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Intensitaetsstufe_2) || (defined Cx2_Intensitaetsstufe_2)
#   if (!defined RTE_CONST_Cx2_Intensitaetsstufe_2) || (RTE_CONST_Cx2_Intensitaetsstufe_2 != 2U)
#    error "Enumeration constant <Cx2_Intensitaetsstufe_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Intensitaetsstufe_2 (2U)
#   define Cx2_Intensitaetsstufe_2 (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Intensitaetsstufe_3) || (defined Cx3_Intensitaetsstufe_3)
#   if (!defined RTE_CONST_Cx3_Intensitaetsstufe_3) || (RTE_CONST_Cx3_Intensitaetsstufe_3 != 3U)
#    error "Enumeration constant <Cx3_Intensitaetsstufe_3> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Intensitaetsstufe_3 (3U)
#   define Cx3_Intensitaetsstufe_3 (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Intensitaetsstufe_4) || (defined Cx4_Intensitaetsstufe_4)
#   if (!defined RTE_CONST_Cx4_Intensitaetsstufe_4) || (RTE_CONST_Cx4_Intensitaetsstufe_4 != 4U)
#    error "Enumeration constant <Cx4_Intensitaetsstufe_4> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Intensitaetsstufe_4 (4U)
#   define Cx4_Intensitaetsstufe_4 (4U)
#  endif
#  if (defined RTE_CONST_Cx5_Intensitaetsstufe_5) || (defined Cx5_Intensitaetsstufe_5)
#   if (!defined RTE_CONST_Cx5_Intensitaetsstufe_5) || (RTE_CONST_Cx5_Intensitaetsstufe_5 != 5U)
#    error "Enumeration constant <Cx5_Intensitaetsstufe_5> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx5_Intensitaetsstufe_5 (5U)
#   define Cx5_Intensitaetsstufe_5 (5U)
#  endif
#  if (defined RTE_CONST_Cx6_Intensitaetsstufe_6) || (defined Cx6_Intensitaetsstufe_6)
#   if (!defined RTE_CONST_Cx6_Intensitaetsstufe_6) || (RTE_CONST_Cx6_Intensitaetsstufe_6 != 6U)
#    error "Enumeration constant <Cx6_Intensitaetsstufe_6> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Intensitaetsstufe_6 (6U)
#   define Cx6_Intensitaetsstufe_6 (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Intensitaetsstufe_7) || (defined Cx7_Intensitaetsstufe_7)
#   if (!defined RTE_CONST_Cx7_Intensitaetsstufe_7) || (RTE_CONST_Cx7_Intensitaetsstufe_7 != 7U)
#    error "Enumeration constant <Cx7_Intensitaetsstufe_7> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Intensitaetsstufe_7 (7U)
#   define Cx7_Intensitaetsstufe_7 (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Intensitaetsstufe_8) || (defined Cx8_Intensitaetsstufe_8)
#   if (!defined RTE_CONST_Cx8_Intensitaetsstufe_8) || (RTE_CONST_Cx8_Intensitaetsstufe_8 != 8U)
#    error "Enumeration constant <Cx8_Intensitaetsstufe_8> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Intensitaetsstufe_8 (8U)
#   define Cx8_Intensitaetsstufe_8 (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Intensitaetsstufe_9) || (defined Cx9_Intensitaetsstufe_9)
#   if (!defined RTE_CONST_Cx9_Intensitaetsstufe_9) || (RTE_CONST_Cx9_Intensitaetsstufe_9 != 9U)
#    error "Enumeration constant <Cx9_Intensitaetsstufe_9> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Intensitaetsstufe_9 (9U)
#   define Cx9_Intensitaetsstufe_9 (9U)
#  endif
#  if (defined RTE_CONST_CxA_Intensitaetsstufe_10) || (defined CxA_Intensitaetsstufe_10)
#   if (!defined RTE_CONST_CxA_Intensitaetsstufe_10) || (RTE_CONST_CxA_Intensitaetsstufe_10 != 10U)
#    error "Enumeration constant <CxA_Intensitaetsstufe_10> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Intensitaetsstufe_10 (10U)
#   define CxA_Intensitaetsstufe_10 (10U)
#  endif
#  if (defined RTE_CONST_CxB_Intensitaetsstufe_11) || (defined CxB_Intensitaetsstufe_11)
#   if (!defined RTE_CONST_CxB_Intensitaetsstufe_11) || (RTE_CONST_CxB_Intensitaetsstufe_11 != 11U)
#    error "Enumeration constant <CxB_Intensitaetsstufe_11> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_Intensitaetsstufe_11 (11U)
#   define CxB_Intensitaetsstufe_11 (11U)
#  endif
#  if (defined RTE_CONST_CxC_Intensitaetsstufe_12) || (defined CxC_Intensitaetsstufe_12)
#   if (!defined RTE_CONST_CxC_Intensitaetsstufe_12) || (RTE_CONST_CxC_Intensitaetsstufe_12 != 12U)
#    error "Enumeration constant <CxC_Intensitaetsstufe_12> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_Intensitaetsstufe_12 (12U)
#   define CxC_Intensitaetsstufe_12 (12U)
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

#  define Rte_TypeDef_New_Coding_76
typedef uint8 New_Coding_76;
#  define New_Coding_76_LowerLimit (0U)
#  define New_Coding_76_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_76 (15U)
#  define InvalidValue_New_Coding_76 (15U)
#  if (defined RTE_CONST_Cx0_Verschliffen) || (defined Cx0_Verschliffen)
#   if (!defined RTE_CONST_Cx0_Verschliffen) || (RTE_CONST_Cx0_Verschliffen != 0U)
#    error "Enumeration constant <Cx0_Verschliffen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Verschliffen (0U)
#   define Cx0_Verschliffen (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Ueberzeichnung) || (defined Cx1_Ueberzeichnung)
#   if (!defined RTE_CONST_Cx1_Ueberzeichnung) || (RTE_CONST_Cx1_Ueberzeichnung != 1U)
#    error "Enumeration constant <Cx1_Ueberzeichnung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Ueberzeichnung (1U)
#   define Cx1_Ueberzeichnung (1U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_77
typedef uint8 New_Coding_77;
#  define New_Coding_77_LowerLimit (0U)
#  define New_Coding_77_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_77 (15U)
#  define InvalidValue_New_Coding_77 (15U)
#  if (defined RTE_CONST_Cx1_Ultrahart__S__) || (defined Cx1_Ultrahart__S__)
#   if (!defined RTE_CONST_Cx1_Ultrahart__S__) || (RTE_CONST_Cx1_Ultrahart__S__ != 1U)
#    error "Enumeration constant <Cx1_Ultrahart__S__> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Ultrahart__S__ (1U)
#   define Cx1_Ultrahart__S__ (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Sportlich_optimal__S_e_) || (defined Cx2_Sportlich_optimal__S_e_)
#   if (!defined RTE_CONST_Cx2_Sportlich_optimal__S_e_) || (RTE_CONST_Cx2_Sportlich_optimal__S_e_ != 2U)
#    error "Enumeration constant <Cx2_Sportlich_optimal__S_e_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Sportlich_optimal__S_e_ (2U)
#   define Cx2_Sportlich_optimal__S_e_ (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Sportlich_ausgewogen__S_) || (defined Cx3_Sportlich_ausgewogen__S_)
#   if (!defined RTE_CONST_Cx3_Sportlich_ausgewogen__S_) || (RTE_CONST_Cx3_Sportlich_ausgewogen__S_ != 3U)
#    error "Enumeration constant <Cx3_Sportlich_ausgewogen__S_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Sportlich_ausgewogen__S_ (3U)
#   define Cx3_Sportlich_ausgewogen__S_ (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Komfort_ausgewogen__B_) || (defined Cx4_Komfort_ausgewogen__B_)
#   if (!defined RTE_CONST_Cx4_Komfort_ausgewogen__B_) || (RTE_CONST_Cx4_Komfort_ausgewogen__B_ != 4U)
#    error "Enumeration constant <Cx4_Komfort_ausgewogen__B_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Komfort_ausgewogen__B_ (4U)
#   define Cx4_Komfort_ausgewogen__B_ (4U)
#  endif
#  if (defined RTE_CONST_Cx5_Weich__C_) || (defined Cx5_Weich__C_)
#   if (!defined RTE_CONST_Cx5_Weich__C_) || (RTE_CONST_Cx5_Weich__C_ != 5U)
#    error "Enumeration constant <Cx5_Weich__C_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx5_Weich__C_ (5U)
#   define Cx5_Weich__C_ (5U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_78
typedef uint8 New_Coding_78;
#  define New_Coding_78_LowerLimit (0U)
#  define New_Coding_78_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_78 (15U)
#  define InvalidValue_New_Coding_78 (15U)
#  if (defined RTE_CONST_Cx1_Luftfeder_in_Normalstellung__B_) || (defined Cx1_Luftfeder_in_Normalstellung__B_)
#   if (!defined RTE_CONST_Cx1_Luftfeder_in_Normalstellung__B_) || (RTE_CONST_Cx1_Luftfeder_in_Normalstellung__B_ != 1U)
#    error "Enumeration constant <Cx1_Luftfeder_in_Normalstellung__B_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Luftfeder_in_Normalstellung__B_ (1U)
#   define Cx1_Luftfeder_in_Normalstellung__B_ (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Luftfeder_abgesenkt__S_) || (defined Cx2_Luftfeder_abgesenkt__S_)
#   if (!defined RTE_CONST_Cx2_Luftfeder_abgesenkt__S_) || (RTE_CONST_Cx2_Luftfeder_abgesenkt__S_ != 2U)
#    error "Enumeration constant <Cx2_Luftfeder_abgesenkt__S_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Luftfeder_abgesenkt__S_ (2U)
#   define Cx2_Luftfeder_abgesenkt__S_ (2U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_79
typedef uint8 New_Coding_79;
#  define New_Coding_79_LowerLimit (0U)
#  define New_Coding_79_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_79 (15U)
#  define InvalidValue_New_Coding_79 (15U)
#  if (defined RTE_CONST_Cx1_Ultrahart) || (defined Cx1_Ultrahart)
#   if (!defined RTE_CONST_Cx1_Ultrahart) || (RTE_CONST_Cx1_Ultrahart != 1U)
#    error "Enumeration constant <Cx1_Ultrahart> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Ultrahart (1U)
#   define Cx1_Ultrahart (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Sportlich_ausgewogen) || (defined Cx2_Sportlich_ausgewogen)
#   if (!defined RTE_CONST_Cx2_Sportlich_ausgewogen) || (RTE_CONST_Cx2_Sportlich_ausgewogen != 2U)
#    error "Enumeration constant <Cx2_Sportlich_ausgewogen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Sportlich_ausgewogen (2U)
#   define Cx2_Sportlich_ausgewogen (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Ausgewogen) || (defined Cx3_Ausgewogen)
#   if (!defined RTE_CONST_Cx3_Ausgewogen) || (RTE_CONST_Cx3_Ausgewogen != 3U)
#    error "Enumeration constant <Cx3_Ausgewogen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Ausgewogen (3U)
#   define Cx3_Ausgewogen (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Weich) || (defined Cx4_Weich)
#   if (!defined RTE_CONST_Cx4_Weich) || (RTE_CONST_Cx4_Weich != 4U)
#    error "Enumeration constant <Cx4_Weich> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Weich (4U)
#   define Cx4_Weich (4U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_80
typedef uint8 New_Coding_80;
#  define New_Coding_80_LowerLimit (0U)
#  define New_Coding_80_UpperLimit (255U)
#  define Rte_InvalidValue_New_Coding_80 (255U)
#  define InvalidValue_New_Coding_80 (255U)
#  if (defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 253U)
#    error "Enumeration constant <CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#   define CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#  endif
#  if (defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (defined CxFE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFE_Funktion_meldet_Fehler != 254U)
#    error "Enumeration constant <CxFE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFE_Funktion_meldet_Fehler (254U)
#   define CxFE_Funktion_meldet_Fehler (254U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#    error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#   define CxFF_Signal_unbefuellt (255U)
#  endif

#  define Rte_TypeDef_New_Coding_81
typedef uint8 New_Coding_81;
#  define New_Coding_81_LowerLimit (0U)
#  define New_Coding_81_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_81 (15U)
#  define InvalidValue_New_Coding_81 (15U)
#  if (defined RTE_CONST_Cx1_Voll) || (defined Cx1_Voll)
#   if (!defined RTE_CONST_Cx1_Voll) || (RTE_CONST_Cx1_Voll != 1U)
#    error "Enumeration constant <Cx1_Voll> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Voll (1U)
#   define Cx1_Voll (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Mid) || (defined Cx2_Mid)
#   if (!defined RTE_CONST_Cx2_Mid) || (RTE_CONST_Cx2_Mid != 2U)
#    error "Enumeration constant <Cx2_Mid> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Mid (2U)
#   define Cx2_Mid (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Keine) || (defined Cx3_Keine)
#   if (!defined RTE_CONST_Cx3_Keine) || (RTE_CONST_Cx3_Keine != 3U)
#    error "Enumeration constant <Cx3_Keine> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Keine (3U)
#   define Cx3_Keine (3U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_82
typedef uint8 New_Coding_82;
#  define New_Coding_82_LowerLimit (0U)
#  define New_Coding_82_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_82 (15U)
#  define InvalidValue_New_Coding_82 (15U)
#  if (defined RTE_CONST_Cx1_Dynamische_Auspraegung_des_EDP) || (defined Cx1_Dynamische_Auspraegung_des_EDP)
#   if (!defined RTE_CONST_Cx1_Dynamische_Auspraegung_des_EDP) || (RTE_CONST_Cx1_Dynamische_Auspraegung_des_EDP != 1U)
#    error "Enumeration constant <Cx1_Dynamische_Auspraegung_des_EDP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Dynamische_Auspraegung_des_EDP (1U)
#   define Cx1_Dynamische_Auspraegung_des_EDP (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Ausgewogene_Auspraegung_des_EDP) || (defined Cx2_Ausgewogene_Auspraegung_des_EDP)
#   if (!defined RTE_CONST_Cx2_Ausgewogene_Auspraegung_des_EDP) || (RTE_CONST_Cx2_Ausgewogene_Auspraegung_des_EDP != 2U)
#    error "Enumeration constant <Cx2_Ausgewogene_Auspraegung_des_EDP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Ausgewogene_Auspraegung_des_EDP (2U)
#   define Cx2_Ausgewogene_Auspraegung_des_EDP (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Oekonomische_Auspraegung_des_EDP) || (defined Cx3_Oekonomische_Auspraegung_des_EDP)
#   if (!defined RTE_CONST_Cx3_Oekonomische_Auspraegung_des_EDP) || (RTE_CONST_Cx3_Oekonomische_Auspraegung_des_EDP != 3U)
#    error "Enumeration constant <Cx3_Oekonomische_Auspraegung_des_EDP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Oekonomische_Auspraegung_des_EDP (3U)
#   define Cx3_Oekonomische_Auspraegung_des_EDP (3U)
#  endif
#  if (defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#   define CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (defined CxE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxE_Funktion_meldet_Fehler) || (RTE_CONST_CxE_Funktion_meldet_Fehler != 14U)
#    error "Enumeration constant <CxE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Funktion_meldet_Fehler (14U)
#   define CxE_Funktion_meldet_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_unbefuellt) || (defined CxF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxF_Signal_unbefuellt) || (RTE_CONST_CxF_Signal_unbefuellt != 15U)
#    error "Enumeration constant <CxF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_unbefuellt (15U)
#   define CxF_Signal_unbefuellt (15U)
#  endif

#  define Rte_TypeDef_New_Coding_94
typedef uint8 New_Coding_94;
#  define New_Coding_94_LowerLimit (0U)
#  define New_Coding_94_UpperLimit (255U)
#  define Rte_InvalidValue_New_Coding_94 (255U)
#  define InvalidValue_New_Coding_94 (255U)
#  if (defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 253U)
#    error "Enumeration constant <CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#   define CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#  endif
#  if (defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (defined CxFE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFE_Funktion_meldet_Fehler != 254U)
#    error "Enumeration constant <CxFE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFE_Funktion_meldet_Fehler (254U)
#   define CxFE_Funktion_meldet_Fehler (254U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#    error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#   define CxFF_Signal_unbefuellt (255U)
#  endif

#  define Rte_TypeDef_New_Coding_95
typedef uint8 New_Coding_95;
#  define New_Coding_95_LowerLimit (0U)
#  define New_Coding_95_UpperLimit (255U)
#  define Rte_InvalidValue_New_Coding_95 (255U)
#  define InvalidValue_New_Coding_95 (255U)
#  if (defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 253U)
#    error "Enumeration constant <CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#   define CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#  endif
#  if (defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (defined CxFE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFE_Funktion_meldet_Fehler != 254U)
#    error "Enumeration constant <CxFE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFE_Funktion_meldet_Fehler (254U)
#   define CxFE_Funktion_meldet_Fehler (254U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#    error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#   define CxFF_Signal_unbefuellt (255U)
#  endif

#  define Rte_TypeDef_New_Coding_96
typedef uint8 New_Coding_96;
#  define New_Coding_96_LowerLimit (0U)
#  define New_Coding_96_UpperLimit (255U)
#  define Rte_InvalidValue_New_Coding_96 (255U)
#  define InvalidValue_New_Coding_96 (255U)
#  if (defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 253U)
#    error "Enumeration constant <CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#   define CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#  endif
#  if (defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (defined CxFE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFE_Funktion_meldet_Fehler != 254U)
#    error "Enumeration constant <CxFE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFE_Funktion_meldet_Fehler (254U)
#   define CxFE_Funktion_meldet_Fehler (254U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#    error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#   define CxFF_Signal_unbefuellt (255U)
#  endif

#  define Rte_TypeDef_New_Coding_97
typedef uint8 New_Coding_97;
#  define New_Coding_97_LowerLimit (0U)
#  define New_Coding_97_UpperLimit (255U)
#  define Rte_InvalidValue_New_Coding_97 (255U)
#  define InvalidValue_New_Coding_97 (255U)
#  if (defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 253U)
#    error "Enumeration constant <CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#   define CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#  endif
#  if (defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (defined CxFE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFE_Funktion_meldet_Fehler != 254U)
#    error "Enumeration constant <CxFE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFE_Funktion_meldet_Fehler (254U)
#   define CxFE_Funktion_meldet_Fehler (254U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#    error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#   define CxFF_Signal_unbefuellt (255U)
#  endif

#  define Rte_TypeDef_New_Coding_98
typedef uint8 New_Coding_98;
#  define New_Coding_98_LowerLimit (0U)
#  define New_Coding_98_UpperLimit (255U)
#  define Rte_InvalidValue_New_Coding_98 (255U)
#  define InvalidValue_New_Coding_98 (255U)
#  if (defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar != 253U)
#    error "Enumeration constant <CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#   define CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
#  endif
#  if (defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (defined CxFE_Funktion_meldet_Fehler)
#   if (!defined RTE_CONST_CxFE_Funktion_meldet_Fehler) || (RTE_CONST_CxFE_Funktion_meldet_Fehler != 254U)
#    error "Enumeration constant <CxFE_Funktion_meldet_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFE_Funktion_meldet_Fehler (254U)
#   define CxFE_Funktion_meldet_Fehler (254U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#   if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#    error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#   define CxFF_Signal_unbefuellt (255U)
#  endif

#  define Rte_TypeDef_New_Coding_99
typedef uint8 New_Coding_99;
#  define New_Coding_99_LowerLimit (0U)
#  define New_Coding_99_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_99 (15U)
#  define InvalidValue_New_Coding_99 (15U)
#  if (defined RTE_CONST_Cx0_Degradationsstufe_0) || (defined Cx0_Degradationsstufe_0)
#   if (!defined RTE_CONST_Cx0_Degradationsstufe_0) || (RTE_CONST_Cx0_Degradationsstufe_0 != 0U)
#    error "Enumeration constant <Cx0_Degradationsstufe_0> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Degradationsstufe_0 (0U)
#   define Cx0_Degradationsstufe_0 (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Degradationsstufe_1) || (defined Cx1_Degradationsstufe_1)
#   if (!defined RTE_CONST_Cx1_Degradationsstufe_1) || (RTE_CONST_Cx1_Degradationsstufe_1 != 1U)
#    error "Enumeration constant <Cx1_Degradationsstufe_1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Degradationsstufe_1 (1U)
#   define Cx1_Degradationsstufe_1 (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Degradationsstufe_2) || (defined Cx2_Degradationsstufe_2)
#   if (!defined RTE_CONST_Cx2_Degradationsstufe_2) || (RTE_CONST_Cx2_Degradationsstufe_2 != 2U)
#    error "Enumeration constant <Cx2_Degradationsstufe_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Degradationsstufe_2 (2U)
#   define Cx2_Degradationsstufe_2 (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Degradationsstufe_3) || (defined Cx3_Degradationsstufe_3)
#   if (!defined RTE_CONST_Cx3_Degradationsstufe_3) || (RTE_CONST_Cx3_Degradationsstufe_3 != 3U)
#    error "Enumeration constant <Cx3_Degradationsstufe_3> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Degradationsstufe_3 (3U)
#   define Cx3_Degradationsstufe_3 (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Degradationsstufe_4) || (defined Cx4_Degradationsstufe_4)
#   if (!defined RTE_CONST_Cx4_Degradationsstufe_4) || (RTE_CONST_Cx4_Degradationsstufe_4 != 4U)
#    error "Enumeration constant <Cx4_Degradationsstufe_4> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Degradationsstufe_4 (4U)
#   define Cx4_Degradationsstufe_4 (4U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif
#  define Rte_TypeDef_DT_ST_OFFS_QUAD_EPS
typedef uint8 DT_ST_OFFS_QUAD_EPS;
#  define DT_ST_OFFS_QUAD_EPS_LowerLimit (0U)
#  define DT_ST_OFFS_QUAD_EPS_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ST_OFFS_QUAD_EPS (15U)
#  define InvalidValue_DT_ST_OFFS_QUAD_EPS (15U)
#  define Rte_TypeDef_DT_V_VEH_COG
typedef uint16 DT_V_VEH_COG;
#  define DT_V_VEH_COG_LowerLimit (0U)
#  define DT_V_VEH_COG_UpperLimit (22400U)
#  define Rte_InvalidValue_DT_V_VEH_COG (65535U)
#  define InvalidValue_DT_V_VEH_COG (65535U)

# if (defined RTE_CONST_D_ZERO_CNT_S32) || (defined D_ZERO_CNT_S32)
#  if (!defined RTE_CONST_D_ZERO_CNT_S32) || (RTE_CONST_D_ZERO_CNT_S32 != 0)
#   error "Constant value <D_ZERO_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S32 (0)
#  define D_ZERO_CNT_S32 (0)
# endif
#  define Rte_TypeDef_ST_ILK_ERRM_FZM
typedef uint8 ST_ILK_ERRM_FZM;
#  define ST_ILK_ERRM_FZM_LowerLimit (0U)
#  define ST_ILK_ERRM_FZM_UpperLimit (3U)
#  define Rte_InvalidValue_ST_ILK_ERRM_FZM (3U)
#  define InvalidValue_ST_ILK_ERRM_FZM (3U)
#  if (defined RTE_CONST_Cx0_Fehlerspeicherfreigabe) || (defined Cx0_Fehlerspeicherfreigabe)
#   if (!defined RTE_CONST_Cx0_Fehlerspeicherfreigabe) || (RTE_CONST_Cx0_Fehlerspeicherfreigabe != 0U)
#    error "Enumeration constant <Cx0_Fehlerspeicherfreigabe> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Fehlerspeicherfreigabe (0U)
#   define Cx0_Fehlerspeicherfreigabe (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Fehlerspeichersperre) || (defined Cx1_Fehlerspeichersperre)
#   if (!defined RTE_CONST_Cx1_Fehlerspeichersperre) || (RTE_CONST_Cx1_Fehlerspeichersperre != 1U)
#    error "Enumeration constant <Cx1_Fehlerspeichersperre> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Fehlerspeichersperre (1U)
#   define Cx1_Fehlerspeichersperre (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Reserve) || (defined Cx2_Reserve)
#   if (!defined RTE_CONST_Cx2_Reserve) || (RTE_CONST_Cx2_Reserve != 2U)
#    error "Enumeration constant <Cx2_Reserve> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Reserve (2U)
#   define Cx2_Reserve (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#    error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_ungueltig (3U)
#   define Cx3_Signal_ungueltig (3U)
#  endif

#  define Rte_TypeDef_RT_VIN_NO_VECH
typedef struct
{
  DT_NO_VECH_1 VIN_BYTE1;
  DT_NO_VECH_2 VIN_BYTE2;
  DT_NO_VECH_3 VIN_BYTE3;
  DT_NO_VECH_4 VIN_BYTE4;
  DT_NO_VECH_5 VIN_BYTE5;
  DT_NO_VECH_6 VIN_BYTE6;
  DT_NO_VECH_7 VIN_BYTE7;
} RT_VIN_NO_VECH;

#  define Rte_TypeDef_SG_ANFRAGE_EPS
typedef struct
{
  ID_FN_INQY ID_FN_INQY_EPS;
  CD_0x08 ID2_0x08_Mx01_EPS;
} SG_ANFRAGE_EPS;

# endif


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

# if (defined RTE_CONST_D_TRUE_CNT_LGC) || (defined D_TRUE_CNT_LGC)
#  if (!defined RTE_CONST_D_TRUE_CNT_LGC) || (RTE_CONST_D_TRUE_CNT_LGC != TRUE)
#   error "Constant value <D_TRUE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRUE_CNT_LGC (TRUE)
#  define D_TRUE_CNT_LGC (TRUE)
# endif

# if (defined RTE_CONST_D_SUPPLYCURRINIT_AMP_F32) || (defined D_SUPPLYCURRINIT_AMP_F32)
#  if (!defined RTE_CONST_D_SUPPLYCURRINIT_AMP_F32) || (RTE_CONST_D_SUPPLYCURRINIT_AMP_F32 != 166.67F)
#   error "Constant value <D_SUPPLYCURRINIT_AMP_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SUPPLYCURRINIT_AMP_F32 (166.67F)
#  define D_SUPPLYCURRINIT_AMP_F32 (166.67F)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U16) || (defined D_ZERO_CNT_U16)
#  if (!defined RTE_CONST_D_ZERO_CNT_U16) || (RTE_CONST_D_ZERO_CNT_U16 != 0U)
#   error "Constant value <D_ZERO_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U16 (0U)
#  define D_ZERO_CNT_U16 (0U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0U)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0U)
#  define D_ZERO_CNT_U32 (0U)
# endif

# if defined SG_ACLNY_MASSCNTR_INIT
#  error "Constant value <SG_ACLNY_MASSCNTR_INIT> conflicts with an already defined symbol."
# else
#  define SG_ACLNY_MASSCNTR_INIT (Rte_SG_ACLNY_MASSCNTR_INIT)
# endif
extern CONST(SG_ACLNY_MASSCNTR, RTE_CONST) Rte_SG_ACLNY_MASSCNTR_INIT;

# if defined SG_CON_VEH_INIT
#  error "Constant value <SG_CON_VEH_INIT> conflicts with an already defined symbol."
# else
#  define SG_CON_VEH_INIT (Rte_SG_CON_VEH_INIT)
# endif
extern CONST(SG_CON_VEH, RTE_CONST) Rte_SG_CON_VEH_INIT;

# if defined C_RT_OFFS_QUAD_EPS
#  error "Constant value <C_RT_OFFS_QUAD_EPS> conflicts with an already defined symbol."
# else
#  define C_RT_OFFS_QUAD_EPS (Rte_C_RT_OFFS_QUAD_EPS)
# endif
extern CONST(SG_OFFS_QUAD_EPS, RTE_CONST) Rte_C_RT_OFFS_QUAD_EPS;

# if defined C_ST_CENG_INIT
#  error "Constant value <C_ST_CENG_INIT> conflicts with an already defined symbol."
# else
#  define C_ST_CENG_INIT (Rte_C_ST_CENG_INIT)
# endif
extern CONST(SG_ST_CENG, RTE_CONST) Rte_C_ST_CENG_INIT;

# if defined C_RT_TAR_QTA_STRMOM_DV
#  error "Constant value <C_RT_TAR_QTA_STRMOM_DV> conflicts with an already defined symbol."
# else
#  define C_RT_TAR_QTA_STRMOM_DV (Rte_C_RT_TAR_QTA_STRMOM_DV)
# endif
extern CONST(SG_TAR_QTA_STRMOM_DV, RTE_CONST) Rte_C_RT_TAR_QTA_STRMOM_DV;

# if defined C_RT_TAR_STMOM_DV_ACT
#  error "Constant value <C_RT_TAR_STMOM_DV_ACT> conflicts with an already defined symbol."
# else
#  define C_RT_TAR_STMOM_DV_ACT (Rte_C_RT_TAR_STMOM_DV_ACT)
# endif
extern CONST(SG_TAR_STMOM_DV_ACT, RTE_CONST) Rte_C_RT_TAR_STMOM_DV_ACT;

# if defined SG_VYAW_VEH_INIT
#  error "Constant value <SG_VYAW_VEH_INIT> conflicts with an already defined symbol."
# else
#  define SG_VYAW_VEH_INIT (Rte_SG_VYAW_VEH_INIT)
# endif
extern CONST(SG_VYAW_VEH, RTE_CONST) Rte_SG_VYAW_VEH_INIT;

# if defined C_RT_V_VEH
#  error "Constant value <C_RT_V_VEH> conflicts with an already defined symbol."
# else
#  define C_RT_V_VEH (Rte_C_RT_V_VEH)
# endif
extern CONST(SG_V_VEH, RTE_CONST) Rte_C_RT_V_VEH;

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
  UInt32 value;
} Rte_DE_UInt32;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_SrlComInput2
{
  /* Data Handles section */
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_Per1_DiagStsDefVehSpd_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc;
  P2VAR(Rte_DE_UInt32, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_Per1_SrlComSvcDft_Cnt_b32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_Per1_VehSpdValid_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_RxPaDrvDyn_CADASIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc;
  P2VAR(Rte_DE_UInt32, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_VehCfgUpdate_CFACTORIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_VehCfgUpdate_CHWANGLEIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_VehCfgUpdate_CHWTORQUEIF_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_SRLCOMINPUT2_APPL_VAR) SrlComInput2_TRGD_VehCfgUpdate_CMTTORQUEIF_Cnt_lgc;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_SrlComInput2, RTE_CONST, RTE_CONST) Rte_Inst_Ap_SrlComInput2;
extern CONSTP2CONST(struct Rte_CDS_Ap_SrlComInput, RTE_CONST, RTE_CONST) Rte_Inst_Ap_SrlComInput;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1457566584
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComInput/utp/contract/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1457566584
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
