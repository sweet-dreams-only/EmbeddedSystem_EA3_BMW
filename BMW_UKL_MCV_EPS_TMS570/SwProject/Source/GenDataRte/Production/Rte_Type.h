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
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Fri Jun  2 16:47:37 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_ALIV_4_BIT_Unsigned_Integer
typedef uint8 ALIV_4_BIT_Unsigned_Integer;
# define ALIV_4_BIT_Unsigned_Integer_LowerLimit (0U)
# define ALIV_4_BIT_Unsigned_Integer_UpperLimit (14U)
# define Rte_InvalidValue_ALIV_4_BIT_Unsigned_Integer (15U)
# define InvalidValue_ALIV_4_BIT_Unsigned_Integer (15U)

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

# define Rte_TypeDef_BATT_VOLTS
typedef uint16 BATT_VOLTS;
# define BATT_VOLTS_LowerLimit (0U)
# define BATT_VOLTS_UpperLimit (65535U)

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_CD_0x01
typedef boolean CD_0x01;

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

# define Rte_TypeDef_CD_0x16
typedef uint32 CD_0x16;
# define CD_0x16_LowerLimit (0U)
# define CD_0x16_UpperLimit (4194303U)

# define Rte_TypeDef_CD_0x20
typedef uint32 CD_0x20;
# define CD_0x20_LowerLimit (0U)
# define CD_0x20_UpperLimit (4294967295U)

# define Rte_TypeDef_CONT_TEMP_DEG
typedef uint8 CONT_TEMP_DEG;
# define CONT_TEMP_DEG_LowerLimit (0U)
# define CONT_TEMP_DEG_UpperLimit (255U)

# define Rte_TypeDef_CRC8
typedef uint8 CRC8;
# define CRC8_LowerLimit (0U)
# define CRC8_UpperLimit (255U)

# define Rte_TypeDef_CRC_V_VEH
typedef uint8 CRC_V_VEH;
# define CRC_V_VEH_LowerLimit (0U)
# define CRC_V_VEH_UpperLimit (255U)

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;
# define ComM_InhibitionStatusType_LowerLimit (0U)
# define ComM_InhibitionStatusType_UpperLimit (0U)

# define Rte_TypeDef_ComM_NetworkHandleType
typedef uint8 ComM_NetworkHandleType;
# define ComM_NetworkHandleType_LowerLimit (0U)
# define ComM_NetworkHandleType_UpperLimit (255U)

# define Rte_TypeDef_ComM_UserHandleType
typedef uint8 ComM_UserHandleType;
# define ComM_UserHandleType_LowerLimit (0U)
# define ComM_UserHandleType_UpperLimit (255U)

# define Rte_TypeDef_DIAG_ST_OBD
typedef uint8 DIAG_ST_OBD;
# define DIAG_ST_OBD_LowerLimit (0U)
# define DIAG_ST_OBD_UpperLimit (63U)
# define Rte_InvalidValue_DIAG_ST_OBD (63U)
# define InvalidValue_DIAG_ST_OBD (63U)

# define Rte_TypeDef_DIFF_TRQ_NM
typedef sint16 DIFF_TRQ_NM;
# define DIFF_TRQ_NM_LowerLimit (-32768)
# define DIFF_TRQ_NM_UpperLimit (32767)

# define Rte_TypeDef_DT_NO_VECH_1
typedef uint8 DT_NO_VECH_1;
# define DT_NO_VECH_1_LowerLimit (0U)
# define DT_NO_VECH_1_UpperLimit (255U)
# define Rte_InvalidValue_DT_NO_VECH_1 (255U)
# define InvalidValue_DT_NO_VECH_1 (255U)

# define Rte_TypeDef_DT_NO_VECH_2
typedef uint8 DT_NO_VECH_2;
# define DT_NO_VECH_2_LowerLimit (0U)
# define DT_NO_VECH_2_UpperLimit (255U)
# define Rte_InvalidValue_DT_NO_VECH_2 (255U)
# define InvalidValue_DT_NO_VECH_2 (255U)

# define Rte_TypeDef_DT_NO_VECH_3
typedef uint8 DT_NO_VECH_3;
# define DT_NO_VECH_3_LowerLimit (0U)
# define DT_NO_VECH_3_UpperLimit (255U)
# define Rte_InvalidValue_DT_NO_VECH_3 (255U)
# define InvalidValue_DT_NO_VECH_3 (255U)

# define Rte_TypeDef_DT_NO_VECH_4
typedef uint8 DT_NO_VECH_4;
# define DT_NO_VECH_4_LowerLimit (0U)
# define DT_NO_VECH_4_UpperLimit (255U)
# define Rte_InvalidValue_DT_NO_VECH_4 (255U)
# define InvalidValue_DT_NO_VECH_4 (255U)

# define Rte_TypeDef_DT_NO_VECH_5
typedef uint8 DT_NO_VECH_5;
# define DT_NO_VECH_5_LowerLimit (0U)
# define DT_NO_VECH_5_UpperLimit (255U)
# define Rte_InvalidValue_DT_NO_VECH_5 (255U)
# define InvalidValue_DT_NO_VECH_5 (255U)

# define Rte_TypeDef_DT_NO_VECH_6
typedef uint8 DT_NO_VECH_6;
# define DT_NO_VECH_6_LowerLimit (0U)
# define DT_NO_VECH_6_UpperLimit (255U)
# define Rte_InvalidValue_DT_NO_VECH_6 (255U)
# define InvalidValue_DT_NO_VECH_6 (255U)

# define Rte_TypeDef_DT_NO_VECH_7
typedef uint8 DT_NO_VECH_7;
# define DT_NO_VECH_7_LowerLimit (0U)
# define DT_NO_VECH_7_UpperLimit (255U)
# define Rte_InvalidValue_DT_NO_VECH_7 (255U)
# define InvalidValue_DT_NO_VECH_7 (255U)

# define Rte_TypeDef_Dem_DTCType
typedef uint32 Dem_DTCType;
# define Dem_DTCType_LowerLimit (1U)
# define Dem_DTCType_UpperLimit (16777215U)

# define Rte_TypeDef_Dem_EventIdType
typedef uint8 Dem_EventIdType;
# define Dem_EventIdType_LowerLimit (1U)
# define Dem_EventIdType_UpperLimit (107U)

# define Rte_TypeDef_Dem_EventStatusExtendedType
typedef uint8 Dem_EventStatusExtendedType;
# define Dem_EventStatusExtendedType_LowerLimit (0U)
# define Dem_EventStatusExtendedType_UpperLimit (255U)

# define Rte_TypeDef_Dem_IndicatorIdType
typedef uint8 Dem_IndicatorIdType;
# define Dem_IndicatorIdType_LowerLimit (0U)
# define Dem_IndicatorIdType_UpperLimit (0U)

# define Rte_TypeDef_Double
typedef float64 Double;
# define Double_LowerLimit (-DBL_MAX)
# define Double_UpperLimit (DBL_MAX)

# define Rte_TypeDef_EST_BATT_AMPS
typedef sint16 EST_BATT_AMPS;
# define EST_BATT_AMPS_LowerLimit (-32768)
# define EST_BATT_AMPS_UpperLimit (32767)

# define Rte_TypeDef_EST_CUTEMP_DEG
typedef uint8 EST_CUTEMP_DEG;
# define EST_CUTEMP_DEG_LowerLimit (0U)
# define EST_CUTEMP_DEG_UpperLimit (255U)

# define Rte_TypeDef_EST_MOTTEMP_DEG
typedef uint8 EST_MOTTEMP_DEG;
# define EST_MOTTEMP_DEG_LowerLimit (0U)
# define EST_MOTTEMP_DEG_UpperLimit (255U)

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;
# define EcuM_UserType_LowerLimit (0U)
# define EcuM_UserType_UpperLimit (255U)

# define Rte_TypeDef_Edch_EventIdxType
typedef uint8 Edch_EventIdxType;
# define Edch_EventIdxType_LowerLimit (0U)
# define Edch_EventIdxType_UpperLimit (18U)

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

# define Rte_TypeDef_IoHwAb_BoolType
typedef uint8 IoHwAb_BoolType;
# define IoHwAb_BoolType_LowerLimit (0U)
# define IoHwAb_BoolType_UpperLimit (1U)

# define Rte_TypeDef_MILE_KM
typedef uint32 MILE_KM;
# define MILE_KM_LowerLimit (0U)
# define MILE_KM_UpperLimit (16777214U)
# define Rte_InvalidValue_MILE_KM (16777215U)
# define InvalidValue_MILE_KM (16777215U)

# define Rte_TypeDef_MOT_VEL_RADPSEC
typedef sint16 MOT_VEL_RADPSEC;
# define MOT_VEL_RADPSEC_LowerLimit (-32768)
# define MOT_VEL_RADPSEC_UpperLimit (32767)

# define Rte_TypeDef_MTRTRQCMD_NM
typedef sint16 MTRTRQCMD_NM;
# define MTRTRQCMD_NM_LowerLimit (-32768)
# define MTRTRQCMD_NM_UpperLimit (32767)

# define Rte_TypeDef_MTRTRQLMTD_NM
typedef sint16 MTRTRQLMTD_NM;
# define MTRTRQLMTD_NM_LowerLimit (-32768)
# define MTRTRQLMTD_NM_UpperLimit (32767)

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

# define Rte_TypeDef_New_Coding_15
typedef uint8 New_Coding_15;
# define New_Coding_15_LowerLimit (0U)
# define New_Coding_15_UpperLimit (255U)

# define Rte_TypeDef_New_Coding_28
typedef uint16 New_Coding_28;
# define New_Coding_28_LowerLimit (0U)
# define New_Coding_28_UpperLimit (65535U)

# define Rte_TypeDef_New_Coding_29
typedef uint8 New_Coding_29;
# define New_Coding_29_LowerLimit (0U)
# define New_Coding_29_UpperLimit (255U)

# define Rte_TypeDef_New_Coding_3
typedef uint16 New_Coding_3;
# define New_Coding_3_LowerLimit (0U)
# define New_Coding_3_UpperLimit (65535U)

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

# define Rte_TypeDef_New_Coding_69
typedef uint8 New_Coding_69;
# define New_Coding_69_LowerLimit (0U)
# define New_Coding_69_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_69 (15U)
# define InvalidValue_New_Coding_69 (15U)

# define Rte_TypeDef_New_Coding_70
typedef uint8 New_Coding_70;
# define New_Coding_70_LowerLimit (0U)
# define New_Coding_70_UpperLimit (14U)
# define Rte_InvalidValue_New_Coding_70 (15U)
# define InvalidValue_New_Coding_70 (15U)

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;
# define NvM_BlockIdType_LowerLimit (1U)
# define NvM_BlockIdType_UpperLimit (32767U)

# define Rte_TypeDef_OFFS_GRD_MID_EPS
typedef uint16 OFFS_GRD_MID_EPS;
# define OFFS_GRD_MID_EPS_LowerLimit (0U)
# define OFFS_GRD_MID_EPS_UpperLimit (4094U)
# define Rte_InvalidValue_OFFS_GRD_MID_EPS (4095U)
# define InvalidValue_OFFS_GRD_MID_EPS (4095U)

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

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;
# define SInt32_LowerLimit (-2147483648)
# define SInt32_UpperLimit (2147483647)

# define Rte_TypeDef_SInt8
typedef sint8 SInt8;
# define SInt8_LowerLimit (-128)
# define SInt8_UpperLimit (127)

# define Rte_TypeDef_STMOM_QTA_DV
typedef uint16 STMOM_QTA_DV;
# define STMOM_QTA_DV_LowerLimit (0U)
# define STMOM_QTA_DV_UpperLimit (4000U)
# define Rte_InvalidValue_STMOM_QTA_DV (4095U)
# define InvalidValue_STMOM_QTA_DV (4095U)

# define Rte_TypeDef_ST_DIAG_OBD_MUX_MAX
typedef uint8 ST_DIAG_OBD_MUX_MAX;
# define ST_DIAG_OBD_MUX_MAX_LowerLimit (0U)
# define ST_DIAG_OBD_MUX_MAX_UpperLimit (60U)
# define Rte_InvalidValue_ST_DIAG_OBD_MUX_MAX (63U)
# define InvalidValue_ST_DIAG_OBD_MUX_MAX (63U)

# define Rte_TypeDef_SWA_DEG
typedef sint16 SWA_DEG;
# define SWA_DEG_LowerLimit (-32768)
# define SWA_DEG_UpperLimit (32767)

# define Rte_TypeDef_Spi_ChannelType
typedef uint8 Spi_ChannelType;
# define Spi_ChannelType_LowerLimit (0U)
# define Spi_ChannelType_UpperLimit (255U)

# define Rte_TypeDef_Spi_DataType
typedef uint8 Spi_DataType;
# define Spi_DataType_LowerLimit (0U)
# define Spi_DataType_UpperLimit (255U)

# define Rte_TypeDef_Spi_NumberOfDataType
typedef uint16 Spi_NumberOfDataType;
# define Spi_NumberOfDataType_LowerLimit (0U)
# define Spi_NumberOfDataType_UpperLimit (65535U)

# define Rte_TypeDef_Spi_SequenceType
typedef uint8 Spi_SequenceType;
# define Spi_SequenceType_LowerLimit (0U)
# define Spi_SequenceType_UpperLimit (255U)

# define Rte_TypeDef_TAR_STMOM_DV_ACT
typedef uint16 TAR_STMOM_DV_ACT;
# define TAR_STMOM_DV_ACT_LowerLimit (0U)
# define TAR_STMOM_DV_ACT_UpperLimit (4000U)
# define Rte_InvalidValue_TAR_STMOM_DV_ACT (4095U)
# define InvalidValue_TAR_STMOM_DV_ACT (4095U)

# define Rte_TypeDef_THRML_LIMIT_PERC
typedef uint8 THRML_LIMIT_PERC;
# define THRML_LIMIT_PERC_LowerLimit (0U)
# define THRML_LIMIT_PERC_UpperLimit (1U)

# define Rte_TypeDef_TORQUE1_VOLTS
typedef uint16 TORQUE1_VOLTS;
# define TORQUE1_VOLTS_LowerLimit (0U)
# define TORQUE1_VOLTS_UpperLimit (65535U)

# define Rte_TypeDef_TORQUE2_VOLTS
typedef uint16 TORQUE2_VOLTS;
# define TORQUE2_VOLTS_LowerLimit (0U)
# define TORQUE2_VOLTS_UpperLimit (65535U)

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

# define Rte_TypeDef_UInt2
typedef uint8 UInt2;
# define UInt2_LowerLimit (0U)
# define UInt2_UpperLimit (3U)
# define Rte_InvalidValue_UInt2 (3U)
# define InvalidValue_UInt2 (3U)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit (0U)
# define UInt32_UpperLimit (4294967295U)

# define Rte_TypeDef_UInt4
typedef uint8 UInt4;
# define UInt4_LowerLimit (0U)
# define UInt4_UpperLimit (15U)

# define Rte_TypeDef_UInt6
typedef uint8 UInt6;
# define UInt6_LowerLimit (0U)
# define UInt6_UpperLimit (63U)
# define Rte_InvalidValue_UInt6 (63U)
# define InvalidValue_UInt6 (63U)

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

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;
# define WdgM_CheckpointIdType_LowerLimit (0U)
# define WdgM_CheckpointIdType_UpperLimit (65535U)

# define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;
# define WdgM_ModeType_LowerLimit (0U)
# define WdgM_ModeType_UpperLimit (255U)

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;
# define WdgM_SupervisedEntityIdType_LowerLimit (0U)
# define WdgM_SupervisedEntityIdType_UpperLimit (65535U)

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

# define Rte_TypeDef_AVL_STEA_PNI_OFFS
typedef uint16 AVL_STEA_PNI_OFFS;
# define AVL_STEA_PNI_OFFS_LowerLimit (0U)
# define AVL_STEA_PNI_OFFS_UpperLimit (4095U)
# define Rte_InvalidValue_AVL_STEA_PNI_OFFS (4095U)
# define InvalidValue_AVL_STEA_PNI_OFFS (4095U)
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

# define Rte_TypeDef_ApaAbortSt_State_enum
typedef uint8 ApaAbortSt_State_enum;
# define ApaAbortSt_State_enum_LowerLimit (0U)
# define ApaAbortSt_State_enum_UpperLimit (7U)
# if (defined RTE_CONST_CAAPAABORTST_NODRVGINTRPT) || (defined CAAPAABORTST_NODRVGINTRPT)
#  if (!defined RTE_CONST_CAAPAABORTST_NODRVGINTRPT) || (RTE_CONST_CAAPAABORTST_NODRVGINTRPT != 0U)
#   error "Enumeration constant <CAAPAABORTST_NODRVGINTRPT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_NODRVGINTRPT (0U)
#  define CAAPAABORTST_NODRVGINTRPT (0U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_DRVRRCVRY) || (defined CAAPAABORTST_DRVRRCVRY)
#  if (!defined RTE_CONST_CAAPAABORTST_DRVRRCVRY) || (RTE_CONST_CAAPAABORTST_DRVRRCVRY != 1U)
#   error "Enumeration constant <CAAPAABORTST_DRVRRCVRY> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_DRVRRCVRY (1U)
#  define CAAPAABORTST_DRVRRCVRY (1U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_HIVEHSPDERR) || (defined CAAPAABORTST_HIVEHSPDERR)
#  if (!defined RTE_CONST_CAAPAABORTST_HIVEHSPDERR) || (RTE_CONST_CAAPAABORTST_HIVEHSPDERR != 2U)
#   error "Enumeration constant <CAAPAABORTST_HIVEHSPDERR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_HIVEHSPDERR (2U)
#  define CAAPAABORTST_HIVEHSPDERR (2U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_AGRDELTAERR) || (defined CAAPAABORTST_AGRDELTAERR)
#  if (!defined RTE_CONST_CAAPAABORTST_AGRDELTAERR) || (RTE_CONST_CAAPAABORTST_AGRDELTAERR != 3U)
#   error "Enumeration constant <CAAPAABORTST_AGRDELTAERR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_AGRDELTAERR (3U)
#  define CAAPAABORTST_AGRDELTAERR (3U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_AGRSPDERR) || (defined CAAPAABORTST_AGRSPDERR)
#  if (!defined RTE_CONST_CAAPAABORTST_AGRSPDERR) || (RTE_CONST_CAAPAABORTST_AGRSPDERR != 4U)
#   error "Enumeration constant <CAAPAABORTST_AGRSPDERR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_AGRSPDERR (4U)
#  define CAAPAABORTST_AGRSPDERR (4U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_THERMLIM) || (defined CAAPAABORTST_THERMLIM)
#  if (!defined RTE_CONST_CAAPAABORTST_THERMLIM) || (RTE_CONST_CAAPAABORTST_THERMLIM != 5U)
#   error "Enumeration constant <CAAPAABORTST_THERMLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_THERMLIM (5U)
#  define CAAPAABORTST_THERMLIM (5U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_ASSISTALLLIM) || (defined CAAPAABORTST_ASSISTALLLIM)
#  if (!defined RTE_CONST_CAAPAABORTST_ASSISTALLLIM) || (RTE_CONST_CAAPAABORTST_ASSISTALLLIM != 6U)
#   error "Enumeration constant <CAAPAABORTST_ASSISTALLLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_ASSISTALLLIM (6U)
#  define CAAPAABORTST_ASSISTALLLIM (6U)
# endif
# if (defined RTE_CONST_CAAPAABORTST_RESD) || (defined CAAPAABORTST_RESD)
#  if (!defined RTE_CONST_CAAPAABORTST_RESD) || (RTE_CONST_CAAPAABORTST_RESD != 7U)
#   error "Enumeration constant <CAAPAABORTST_RESD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAABORTST_RESD (7U)
#  define CAAPAABORTST_RESD (7U)
# endif

# define Rte_TypeDef_ApaReqSt_State_enum
typedef uint8 ApaReqSt_State_enum;
# define ApaReqSt_State_enum_LowerLimit (0U)
# define ApaReqSt_State_enum_UpperLimit (2U)
# if (defined RTE_CONST_CAAPAREQST_NOREQ) || (defined CAAPAREQST_NOREQ)
#  if (!defined RTE_CONST_CAAPAREQST_NOREQ) || (RTE_CONST_CAAPAREQST_NOREQ != 0U)
#   error "Enumeration constant <CAAPAREQST_NOREQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAREQST_NOREQ (0U)
#  define CAAPAREQST_NOREQ (0U)
# endif
# if (defined RTE_CONST_CAAPAREQST_REQCTRL) || (defined CAAPAREQST_REQCTRL)
#  if (!defined RTE_CONST_CAAPAREQST_REQCTRL) || (RTE_CONST_CAAPAREQST_REQCTRL != 1U)
#   error "Enumeration constant <CAAPAREQST_REQCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAREQST_REQCTRL (1U)
#  define CAAPAREQST_REQCTRL (1U)
# endif
# if (defined RTE_CONST_CAAPAREQST_CTRLACTV) || (defined CAAPAREQST_CTRLACTV)
#  if (!defined RTE_CONST_CAAPAREQST_CTRLACTV) || (RTE_CONST_CAAPAREQST_CTRLACTV != 2U)
#   error "Enumeration constant <CAAPAREQST_CTRLACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CAAPAREQST_CTRLACTV (2U)
#  define CAAPAREQST_CTRLACTV (2U)
# endif

# define Rte_TypeDef_BattSwdVltgCorrSts_Cnt_enum
typedef uint8 BattSwdVltgCorrSts_Cnt_enum;
# define BattSwdVltgCorrSts_Cnt_enum_LowerLimit (0U)
# define BattSwdVltgCorrSts_Cnt_enum_UpperLimit (4U)
# if (defined RTE_CONST_BSVCS_NOFLT) || (defined BSVCS_NOFLT)
#  if (!defined RTE_CONST_BSVCS_NOFLT) || (RTE_CONST_BSVCS_NOFLT != 0U)
#   error "Enumeration constant <BSVCS_NOFLT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_NOFLT (0U)
#  define BSVCS_NOFLT (0U)
# endif
# if (defined RTE_CONST_BSVCS_BATTVLTGSWD2FLT) || (defined BSVCS_BATTVLTGSWD2FLT)
#  if (!defined RTE_CONST_BSVCS_BATTVLTGSWD2FLT) || (RTE_CONST_BSVCS_BATTVLTGSWD2FLT != 1U)
#   error "Enumeration constant <BSVCS_BATTVLTGSWD2FLT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_BATTVLTGSWD2FLT (1U)
#  define BSVCS_BATTVLTGSWD2FLT (1U)
# endif
# if (defined RTE_CONST_BSVCS_BATTVLTGSWD1FLT) || (defined BSVCS_BATTVLTGSWD1FLT)
#  if (!defined RTE_CONST_BSVCS_BATTVLTGSWD1FLT) || (RTE_CONST_BSVCS_BATTVLTGSWD1FLT != 2U)
#   error "Enumeration constant <BSVCS_BATTVLTGSWD1FLT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_BATTVLTGSWD1FLT (2U)
#  define BSVCS_BATTVLTGSWD1FLT (2U)
# endif
# if (defined RTE_CONST_BSVCS_BATTVLTGFLT) || (defined BSVCS_BATTVLTGFLT)
#  if (!defined RTE_CONST_BSVCS_BATTVLTGFLT) || (RTE_CONST_BSVCS_BATTVLTGFLT != 3U)
#   error "Enumeration constant <BSVCS_BATTVLTGFLT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_BATTVLTGFLT (3U)
#  define BSVCS_BATTVLTGFLT (3U)
# endif
# if (defined RTE_CONST_BSVCS_NOCORRLN) || (defined BSVCS_NOCORRLN)
#  if (!defined RTE_CONST_BSVCS_NOCORRLN) || (RTE_CONST_BSVCS_NOCORRLN != 4U)
#   error "Enumeration constant <BSVCS_NOCORRLN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BSVCS_NOCORRLN (4U)
#  define BSVCS_NOCORRLN (4U)
# endif

# define Rte_TypeDef_BattVltgSt_Cnt_enum
typedef uint8 BattVltgSt_Cnt_enum;
# define BattVltgSt_Cnt_enum_LowerLimit (0U)
# define BattVltgSt_Cnt_enum_UpperLimit (6U)
# if (defined RTE_CONST_SYSPRFMNCST_NORMOPER) || (defined SYSPRFMNCST_NORMOPER)
#  if (!defined RTE_CONST_SYSPRFMNCST_NORMOPER) || (RTE_CONST_SYSPRFMNCST_NORMOPER != 0U)
#   error "Enumeration constant <SYSPRFMNCST_NORMOPER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_NORMOPER (0U)
#  define SYSPRFMNCST_NORMOPER (0U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_HIVLTGWARN) || (defined SYSPRFMNCST_HIVLTGWARN)
#  if (!defined RTE_CONST_SYSPRFMNCST_HIVLTGWARN) || (RTE_CONST_SYSPRFMNCST_HIVLTGWARN != 1U)
#   error "Enumeration constant <SYSPRFMNCST_HIVLTGWARN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_HIVLTGWARN (1U)
#  define SYSPRFMNCST_HIVLTGWARN (1U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_HIVLTGCRIT) || (defined SYSPRFMNCST_HIVLTGCRIT)
#  if (!defined RTE_CONST_SYSPRFMNCST_HIVLTGCRIT) || (RTE_CONST_SYSPRFMNCST_HIVLTGCRIT != 2U)
#   error "Enumeration constant <SYSPRFMNCST_HIVLTGCRIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_HIVLTGCRIT (2U)
#  define SYSPRFMNCST_HIVLTGCRIT (2U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_HIVLTGOFF) || (defined SYSPRFMNCST_HIVLTGOFF)
#  if (!defined RTE_CONST_SYSPRFMNCST_HIVLTGOFF) || (RTE_CONST_SYSPRFMNCST_HIVLTGOFF != 3U)
#   error "Enumeration constant <SYSPRFMNCST_HIVLTGOFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_HIVLTGOFF (3U)
#  define SYSPRFMNCST_HIVLTGOFF (3U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_LOVLTGWARN) || (defined SYSPRFMNCST_LOVLTGWARN)
#  if (!defined RTE_CONST_SYSPRFMNCST_LOVLTGWARN) || (RTE_CONST_SYSPRFMNCST_LOVLTGWARN != 4U)
#   error "Enumeration constant <SYSPRFMNCST_LOVLTGWARN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_LOVLTGWARN (4U)
#  define SYSPRFMNCST_LOVLTGWARN (4U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_LOVLTGCRIT) || (defined SYSPRFMNCST_LOVLTGCRIT)
#  if (!defined RTE_CONST_SYSPRFMNCST_LOVLTGCRIT) || (RTE_CONST_SYSPRFMNCST_LOVLTGCRIT != 5U)
#   error "Enumeration constant <SYSPRFMNCST_LOVLTGCRIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_LOVLTGCRIT (5U)
#  define SYSPRFMNCST_LOVLTGCRIT (5U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_LOVLTGOFF) || (defined SYSPRFMNCST_LOVLTGOFF)
#  if (!defined RTE_CONST_SYSPRFMNCST_LOVLTGOFF) || (RTE_CONST_SYSPRFMNCST_LOVLTGOFF != 6U)
#   error "Enumeration constant <SYSPRFMNCST_LOVLTGOFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_LOVLTGOFF (6U)
#  define SYSPRFMNCST_LOVLTGOFF (6U)
# endif

# define Rte_TypeDef_CTR_ERRM_BN_U
typedef uint8 CTR_ERRM_BN_U;
# define CTR_ERRM_BN_U_LowerLimit (0U)
# define CTR_ERRM_BN_U_UpperLimit (63U)
# define Rte_InvalidValue_CTR_ERRM_BN_U (63U)
# define InvalidValue_CTR_ERRM_BN_U (63U)
# if (defined RTE_CONST_Cb0xxxx1_Unterspannung_Normalbetrieb) || (defined Cb0xxxx1_Unterspannung_Normalbetrieb)
#  if (!defined RTE_CONST_Cb0xxxx1_Unterspannung_Normalbetrieb) || (RTE_CONST_Cb0xxxx1_Unterspannung_Normalbetrieb != 0U)
#   error "Enumeration constant <Cb0xxxx1_Unterspannung_Normalbetrieb> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxx1_Unterspannung_Normalbetrieb (0U)
#  define Cb0xxxx1_Unterspannung_Normalbetrieb (0U)
# endif
# if (defined RTE_CONST_Cb0xxxx0_Keine_Unterspannung_Normalbetrieb) || (defined Cb0xxxx0_Keine_Unterspannung_Normalbetrieb)
#  if (!defined RTE_CONST_Cb0xxxx0_Keine_Unterspannung_Normalbetrieb) || (RTE_CONST_Cb0xxxx0_Keine_Unterspannung_Normalbetrieb != 0U)
#   error "Enumeration constant <Cb0xxxx0_Keine_Unterspannung_Normalbetrieb> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxx0_Keine_Unterspannung_Normalbetrieb (0U)
#  define Cb0xxxx0_Keine_Unterspannung_Normalbetrieb (0U)
# endif
# if (defined RTE_CONST_Cb0xxx1x_Unterspannung_MSA_Start) || (defined Cb0xxx1x_Unterspannung_MSA_Start)
#  if (!defined RTE_CONST_Cb0xxx1x_Unterspannung_MSA_Start) || (RTE_CONST_Cb0xxx1x_Unterspannung_MSA_Start != 0U)
#   error "Enumeration constant <Cb0xxx1x_Unterspannung_MSA_Start> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxx1x_Unterspannung_MSA_Start (0U)
#  define Cb0xxx1x_Unterspannung_MSA_Start (0U)
# endif
# if (defined RTE_CONST_Cb0xxx0x_Keine_Unterspannung_MSA_Start) || (defined Cb0xxx0x_Keine_Unterspannung_MSA_Start)
#  if (!defined RTE_CONST_Cb0xxx0x_Keine_Unterspannung_MSA_Start) || (RTE_CONST_Cb0xxx0x_Keine_Unterspannung_MSA_Start != 0U)
#   error "Enumeration constant <Cb0xxx0x_Keine_Unterspannung_MSA_Start> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxx0x_Keine_Unterspannung_MSA_Start (0U)
#  define Cb0xxx0x_Keine_Unterspannung_MSA_Start (0U)
# endif
# if (defined RTE_CONST_Cb0xx1xx_Ueberspannung) || (defined Cb0xx1xx_Ueberspannung)
#  if (!defined RTE_CONST_Cb0xx1xx_Ueberspannung) || (RTE_CONST_Cb0xx1xx_Ueberspannung != 0U)
#   error "Enumeration constant <Cb0xx1xx_Ueberspannung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xx1xx_Ueberspannung (0U)
#  define Cb0xx1xx_Ueberspannung (0U)
# endif
# if (defined RTE_CONST_Cb0xx0xx_Keine_Ueberspannung) || (defined Cb0xx0xx_Keine_Ueberspannung)
#  if (!defined RTE_CONST_Cb0xx0xx_Keine_Ueberspannung) || (RTE_CONST_Cb0xx0xx_Keine_Ueberspannung != 0U)
#   error "Enumeration constant <Cb0xx0xx_Keine_Ueberspannung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xx0xx_Keine_Ueberspannung (0U)
#  define Cb0xx0xx_Keine_Ueberspannung (0U)
# endif
# if (defined RTE_CONST_Cx3D_nicht_verfuegbar) || (defined Cx3D_nicht_verfuegbar)
#  if (!defined RTE_CONST_Cx3D_nicht_verfuegbar) || (RTE_CONST_Cx3D_nicht_verfuegbar != 61U)
#   error "Enumeration constant <Cx3D_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3D_nicht_verfuegbar (61U)
#  define Cx3D_nicht_verfuegbar (61U)
# endif
# if (defined RTE_CONST_Cx3E_Fehler) || (defined Cx3E_Fehler)
#  if (!defined RTE_CONST_Cx3E_Fehler) || (RTE_CONST_Cx3E_Fehler != 62U)
#   error "Enumeration constant <Cx3E_Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3E_Fehler (62U)
#  define Cx3E_Fehler (62U)
# endif
# if (defined RTE_CONST_Cx3F_Signal_ungueltig) || (defined Cx3F_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3F_Signal_ungueltig) || (RTE_CONST_Cx3F_Signal_ungueltig != 63U)
#   error "Enumeration constant <Cx3F_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3F_Signal_ungueltig (63U)
#  define Cx3F_Signal_ungueltig (63U)
# endif

# define Rte_TypeDef_Coding_BlockIdType
typedef uint8 Coding_BlockIdType;
# define Coding_BlockIdType_LowerLimit (0U)
# define Coding_BlockIdType_UpperLimit (5U)
# if (defined RTE_CONST_CODING_ID_AREA_CODINGDATASET1) || (defined CODING_ID_AREA_CODINGDATASET1)
#  if (!defined RTE_CONST_CODING_ID_AREA_CODINGDATASET1) || (RTE_CONST_CODING_ID_AREA_CODINGDATASET1 != 0U)
#   error "Enumeration constant <CODING_ID_AREA_CODINGDATASET1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_ID_AREA_CODINGDATASET1 (0U)
#  define CODING_ID_AREA_CODINGDATASET1 (0U)
# endif
# if (defined RTE_CONST_CODING_ID_AREA_CODINGDATASET2) || (defined CODING_ID_AREA_CODINGDATASET2)
#  if (!defined RTE_CONST_CODING_ID_AREA_CODINGDATASET2) || (RTE_CONST_CODING_ID_AREA_CODINGDATASET2 != 1U)
#   error "Enumeration constant <CODING_ID_AREA_CODINGDATASET2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_ID_AREA_CODINGDATASET2 (1U)
#  define CODING_ID_AREA_CODINGDATASET2 (1U)
# endif
# if (defined RTE_CONST_CODING_ID_AREA_CODINGDATASET3) || (defined CODING_ID_AREA_CODINGDATASET3)
#  if (!defined RTE_CONST_CODING_ID_AREA_CODINGDATASET3) || (RTE_CONST_CODING_ID_AREA_CODINGDATASET3 != 2U)
#   error "Enumeration constant <CODING_ID_AREA_CODINGDATASET3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_ID_AREA_CODINGDATASET3 (2U)
#  define CODING_ID_AREA_CODINGDATASET3 (2U)
# endif
# if (defined RTE_CONST_CODING_ID_AREA_CAFID) || (defined CODING_ID_AREA_CAFID)
#  if (!defined RTE_CONST_CODING_ID_AREA_CAFID) || (RTE_CONST_CODING_ID_AREA_CAFID != 3U)
#   error "Enumeration constant <CODING_ID_AREA_CAFID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_ID_AREA_CAFID (3U)
#  define CODING_ID_AREA_CAFID (3U)
# endif
# if (defined RTE_CONST_CODING_ID_AREA_SIGNATURE) || (defined CODING_ID_AREA_SIGNATURE)
#  if (!defined RTE_CONST_CODING_ID_AREA_SIGNATURE) || (RTE_CONST_CODING_ID_AREA_SIGNATURE != 4U)
#   error "Enumeration constant <CODING_ID_AREA_SIGNATURE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_ID_AREA_SIGNATURE (4U)
#  define CODING_ID_AREA_SIGNATURE (4U)
# endif

# define Rte_TypeDef_Coding_DataStatusType
typedef uint8 Coding_DataStatusType;
# define Coding_DataStatusType_LowerLimit (0U)
# define Coding_DataStatusType_UpperLimit (2U)
# if (defined RTE_CONST_CODING_DATA_UNDEFINED) || (defined CODING_DATA_UNDEFINED)
#  if (!defined RTE_CONST_CODING_DATA_UNDEFINED) || (RTE_CONST_CODING_DATA_UNDEFINED != 0U)
#   error "Enumeration constant <CODING_DATA_UNDEFINED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_DATA_UNDEFINED (0U)
#  define CODING_DATA_UNDEFINED (0U)
# endif
# if (defined RTE_CONST_CODING_DATA_NOT_CODED) || (defined CODING_DATA_NOT_CODED)
#  if (!defined RTE_CONST_CODING_DATA_NOT_CODED) || (RTE_CONST_CODING_DATA_NOT_CODED != 1U)
#   error "Enumeration constant <CODING_DATA_NOT_CODED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_DATA_NOT_CODED (1U)
#  define CODING_DATA_NOT_CODED (1U)
# endif
# if (defined RTE_CONST_CODING_DATA_CODED) || (defined CODING_DATA_CODED)
#  if (!defined RTE_CONST_CODING_DATA_CODED) || (RTE_CONST_CODING_DATA_CODED != 2U)
#   error "Enumeration constant <CODING_DATA_CODED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_DATA_CODED (2U)
#  define CODING_DATA_CODED (2U)
# endif

# define Rte_TypeDef_Coding_ErrorType
typedef uint8 Coding_ErrorType;
# define Coding_ErrorType_LowerLimit (0U)
# define Coding_ErrorType_UpperLimit (3U)
# if (defined RTE_CONST_CODING_E_OK) || (defined CODING_E_OK)
#  if (!defined RTE_CONST_CODING_E_OK) || (RTE_CONST_CODING_E_OK != 0U)
#   error "Enumeration constant <CODING_E_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_E_OK (0U)
#  define CODING_E_OK (0U)
# endif
# if (defined RTE_CONST_CODING_E_NOT_OK) || (defined CODING_E_NOT_OK)
#  if (!defined RTE_CONST_CODING_E_NOT_OK) || (RTE_CONST_CODING_E_NOT_OK != 1U)
#   error "Enumeration constant <CODING_E_NOT_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_E_NOT_OK (1U)
#  define CODING_E_NOT_OK (1U)
# endif
# if (defined RTE_CONST_CODING_E_BUSY) || (defined CODING_E_BUSY)
#  if (!defined RTE_CONST_CODING_E_BUSY) || (RTE_CONST_CODING_E_BUSY != 2U)
#   error "Enumeration constant <CODING_E_BUSY> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_E_BUSY (2U)
#  define CODING_E_BUSY (2U)
# endif
# if (defined RTE_CONST_CODING_E_PENDING) || (defined CODING_E_PENDING)
#  if (!defined RTE_CONST_CODING_E_PENDING) || (RTE_CONST_CODING_E_PENDING != 3U)
#   error "Enumeration constant <CODING_E_PENDING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_E_PENDING (3U)
#  define CODING_E_PENDING (3U)
# endif

# define Rte_TypeDef_Coding_ProtectionType
typedef uint8 Coding_ProtectionType;
# define Coding_ProtectionType_LowerLimit (0U)
# define Coding_ProtectionType_UpperLimit (1U)
# if (defined RTE_CONST_CODING_WRITE_PROTECTION_OFF) || (defined CODING_WRITE_PROTECTION_OFF)
#  if (!defined RTE_CONST_CODING_WRITE_PROTECTION_OFF) || (RTE_CONST_CODING_WRITE_PROTECTION_OFF != 0U)
#   error "Enumeration constant <CODING_WRITE_PROTECTION_OFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_WRITE_PROTECTION_OFF (0U)
#  define CODING_WRITE_PROTECTION_OFF (0U)
# endif
# if (defined RTE_CONST_CODING_WRITE_PROTECTION_ON) || (defined CODING_WRITE_PROTECTION_ON)
#  if (!defined RTE_CONST_CODING_WRITE_PROTECTION_ON) || (RTE_CONST_CODING_WRITE_PROTECTION_ON != 1U)
#   error "Enumeration constant <CODING_WRITE_PROTECTION_ON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CODING_WRITE_PROTECTION_ON (1U)
#  define CODING_WRITE_PROTECTION_ON (1U)
# endif

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;
# define ComM_ModeType_LowerLimit (0U)
# define ComM_ModeType_UpperLimit (2U)
# if (defined RTE_CONST_COMM_NO_COMMUNICATION) || (defined COMM_NO_COMMUNICATION)
#  if (!defined RTE_CONST_COMM_NO_COMMUNICATION) || (RTE_CONST_COMM_NO_COMMUNICATION != 0U)
#   error "Enumeration constant <COMM_NO_COMMUNICATION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_COMM_NO_COMMUNICATION (0U)
#  define COMM_NO_COMMUNICATION (0U)
# endif
# if (defined RTE_CONST_COMM_SILENT_COMMUNICATION) || (defined COMM_SILENT_COMMUNICATION)
#  if (!defined RTE_CONST_COMM_SILENT_COMMUNICATION) || (RTE_CONST_COMM_SILENT_COMMUNICATION != 1U)
#   error "Enumeration constant <COMM_SILENT_COMMUNICATION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_COMM_SILENT_COMMUNICATION (1U)
#  define COMM_SILENT_COMMUNICATION (1U)
# endif
# if (defined RTE_CONST_COMM_FULL_COMMUNICATION) || (defined COMM_FULL_COMMUNICATION)
#  if (!defined RTE_CONST_COMM_FULL_COMMUNICATION) || (RTE_CONST_COMM_FULL_COMMUNICATION != 2U)
#   error "Enumeration constant <COMM_FULL_COMMUNICATION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_COMM_FULL_COMMUNICATION (2U)
#  define COMM_FULL_COMMUNICATION (2U)
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

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;
# define Dcm_OpStatusType_LowerLimit (0U)
# define Dcm_OpStatusType_UpperLimit (255U)
# if (defined RTE_CONST_EDCH_DCM_INITIAL) || (defined EDCH_DCM_INITIAL)
#  if (!defined RTE_CONST_EDCH_DCM_INITIAL) || (RTE_CONST_EDCH_DCM_INITIAL != 0U)
#   error "Enumeration constant <EDCH_DCM_INITIAL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_INITIAL (0U)
#  define EDCH_DCM_INITIAL (0U)
# endif
# if (defined RTE_CONST_EDCH_DCM_PENDING) || (defined EDCH_DCM_PENDING)
#  if (!defined RTE_CONST_EDCH_DCM_PENDING) || (RTE_CONST_EDCH_DCM_PENDING != 1U)
#   error "Enumeration constant <EDCH_DCM_PENDING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_PENDING (1U)
#  define EDCH_DCM_PENDING (1U)
# endif
# if (defined RTE_CONST_EDCH_DCM_CANCEL) || (defined EDCH_DCM_CANCEL)
#  if (!defined RTE_CONST_EDCH_DCM_CANCEL) || (RTE_CONST_EDCH_DCM_CANCEL != 2U)
#   error "Enumeration constant <EDCH_DCM_CANCEL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_CANCEL (2U)
#  define EDCH_DCM_CANCEL (2U)
# endif
# if (defined RTE_CONST_EDCH_DCM_FORCE_RCRRP_OK) || (defined EDCH_DCM_FORCE_RCRRP_OK)
#  if (!defined RTE_CONST_EDCH_DCM_FORCE_RCRRP_OK) || (RTE_CONST_EDCH_DCM_FORCE_RCRRP_OK != 3U)
#   error "Enumeration constant <EDCH_DCM_FORCE_RCRRP_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_FORCE_RCRRP_OK (3U)
#  define EDCH_DCM_FORCE_RCRRP_OK (3U)
# endif

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;
# define Dem_DTCKindType_LowerLimit (1U)
# define Dem_DTCKindType_UpperLimit (2U)
# if (defined RTE_CONST_DEM_DTC_KIND_ALL_DTCS) || (defined DEM_DTC_KIND_ALL_DTCS)
#  if (!defined RTE_CONST_DEM_DTC_KIND_ALL_DTCS) || (RTE_CONST_DEM_DTC_KIND_ALL_DTCS != 1U)
#   error "Enumeration constant <DEM_DTC_KIND_ALL_DTCS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_DTC_KIND_ALL_DTCS (1U)
#  define DEM_DTC_KIND_ALL_DTCS (1U)
# endif
# if (defined RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS) || (defined DEM_DTC_KIND_EMISSION_REL_DTCS)
#  if (!defined RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS) || (RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS != 2U)
#   error "Enumeration constant <DEM_DTC_KIND_EMISSION_REL_DTCS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
#  define DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
# endif

# define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;
# define Dem_EventStatusType_LowerLimit (0U)
# define Dem_EventStatusType_UpperLimit (255U)
# if (defined RTE_CONST_DEM_EVENT_STATUS_PASSED) || (defined DEM_EVENT_STATUS_PASSED)
#  if (!defined RTE_CONST_DEM_EVENT_STATUS_PASSED) || (RTE_CONST_DEM_EVENT_STATUS_PASSED != 0U)
#   error "Enumeration constant <DEM_EVENT_STATUS_PASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_EVENT_STATUS_PASSED (0U)
#  define DEM_EVENT_STATUS_PASSED (0U)
# endif
# if (defined RTE_CONST_DEM_EVENT_STATUS_FAILED) || (defined DEM_EVENT_STATUS_FAILED)
#  if (!defined RTE_CONST_DEM_EVENT_STATUS_FAILED) || (RTE_CONST_DEM_EVENT_STATUS_FAILED != 1U)
#   error "Enumeration constant <DEM_EVENT_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_EVENT_STATUS_FAILED (1U)
#  define DEM_EVENT_STATUS_FAILED (1U)
# endif
# if (defined RTE_CONST_DEM_EVENT_STATUS_PREPASSED) || (defined DEM_EVENT_STATUS_PREPASSED)
#  if (!defined RTE_CONST_DEM_EVENT_STATUS_PREPASSED) || (RTE_CONST_DEM_EVENT_STATUS_PREPASSED != 2U)
#   error "Enumeration constant <DEM_EVENT_STATUS_PREPASSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_EVENT_STATUS_PREPASSED (2U)
#  define DEM_EVENT_STATUS_PREPASSED (2U)
# endif
# if (defined RTE_CONST_DEM_EVENT_STATUS_PREFAILED) || (defined DEM_EVENT_STATUS_PREFAILED)
#  if (!defined RTE_CONST_DEM_EVENT_STATUS_PREFAILED) || (RTE_CONST_DEM_EVENT_STATUS_PREFAILED != 3U)
#   error "Enumeration constant <DEM_EVENT_STATUS_PREFAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_EVENT_STATUS_PREFAILED (3U)
#  define DEM_EVENT_STATUS_PREFAILED (3U)
# endif

# define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;
# define Dem_IndicatorStatusType_LowerLimit (0U)
# define Dem_IndicatorStatusType_UpperLimit (3U)
# if (defined RTE_CONST_DEM_INDICATOR_OFF) || (defined DEM_INDICATOR_OFF)
#  if (!defined RTE_CONST_DEM_INDICATOR_OFF) || (RTE_CONST_DEM_INDICATOR_OFF != 0U)
#   error "Enumeration constant <DEM_INDICATOR_OFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_INDICATOR_OFF (0U)
#  define DEM_INDICATOR_OFF (0U)
# endif
# if (defined RTE_CONST_DEM_INDICATOR_CONTINUOUS) || (defined DEM_INDICATOR_CONTINUOUS)
#  if (!defined RTE_CONST_DEM_INDICATOR_CONTINUOUS) || (RTE_CONST_DEM_INDICATOR_CONTINUOUS != 1U)
#   error "Enumeration constant <DEM_INDICATOR_CONTINUOUS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_INDICATOR_CONTINUOUS (1U)
#  define DEM_INDICATOR_CONTINUOUS (1U)
# endif
# if (defined RTE_CONST_DEM_INDICATOR_BLINKING) || (defined DEM_INDICATOR_BLINKING)
#  if (!defined RTE_CONST_DEM_INDICATOR_BLINKING) || (RTE_CONST_DEM_INDICATOR_BLINKING != 2U)
#   error "Enumeration constant <DEM_INDICATOR_BLINKING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_INDICATOR_BLINKING (2U)
#  define DEM_INDICATOR_BLINKING (2U)
# endif
# if (defined RTE_CONST_DEM_INDICATOR_BLINK_CONT) || (defined DEM_INDICATOR_BLINK_CONT)
#  if (!defined RTE_CONST_DEM_INDICATOR_BLINK_CONT) || (RTE_CONST_DEM_INDICATOR_BLINK_CONT != 3U)
#   error "Enumeration constant <DEM_INDICATOR_BLINK_CONT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_INDICATOR_BLINK_CONT (3U)
#  define DEM_INDICATOR_BLINK_CONT (3U)
# endif

# define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;
# define Dem_OperationCycleIdType_LowerLimit (0U)
# define Dem_OperationCycleIdType_UpperLimit (255U)
# if (defined RTE_CONST_DEM_OPCYCLE_DEFAULT) || (defined DEM_OPCYCLE_DEFAULT)
#  if (!defined RTE_CONST_DEM_OPCYCLE_DEFAULT) || (RTE_CONST_DEM_OPCYCLE_DEFAULT != 0U)
#   error "Enumeration constant <DEM_OPCYCLE_DEFAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_OPCYCLE_DEFAULT (0U)
#  define DEM_OPCYCLE_DEFAULT (0U)
# endif
# if (defined RTE_CONST_DEM_OPCYCLE_VSM_OPMODE) || (defined DEM_OPCYCLE_VSM_OPMODE)
#  if (!defined RTE_CONST_DEM_OPCYCLE_VSM_OPMODE) || (RTE_CONST_DEM_OPCYCLE_VSM_OPMODE != 1U)
#   error "Enumeration constant <DEM_OPCYCLE_VSM_OPMODE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_OPCYCLE_VSM_OPMODE (1U)
#  define DEM_OPCYCLE_VSM_OPMODE (1U)
# endif
# if (defined RTE_CONST_BUS_ACTIVE) || (defined BUS_ACTIVE)
#  if (!defined RTE_CONST_BUS_ACTIVE) || (RTE_CONST_BUS_ACTIVE != 2U)
#   error "Enumeration constant <BUS_ACTIVE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_BUS_ACTIVE (2U)
#  define BUS_ACTIVE (2U)
# endif
# if (defined RTE_CONST_OBD_CYCLE) || (defined OBD_CYCLE)
#  if (!defined RTE_CONST_OBD_CYCLE) || (RTE_CONST_OBD_CYCLE != 3U)
#   error "Enumeration constant <OBD_CYCLE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_OBD_CYCLE (3U)
#  define OBD_CYCLE (3U)
# endif

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;
# define Dem_OperationCycleStateType_LowerLimit (1U)
# define Dem_OperationCycleStateType_UpperLimit (2U)
# if (defined RTE_CONST_DEM_CYCLE_STATE_START) || (defined DEM_CYCLE_STATE_START)
#  if (!defined RTE_CONST_DEM_CYCLE_STATE_START) || (RTE_CONST_DEM_CYCLE_STATE_START != 1U)
#   error "Enumeration constant <DEM_CYCLE_STATE_START> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_CYCLE_STATE_START (1U)
#  define DEM_CYCLE_STATE_START (1U)
# endif
# if (defined RTE_CONST_DEM_CYCLE_STATE_END) || (defined DEM_CYCLE_STATE_END)
#  if (!defined RTE_CONST_DEM_CYCLE_STATE_END) || (RTE_CONST_DEM_CYCLE_STATE_END != 2U)
#   error "Enumeration constant <DEM_CYCLE_STATE_END> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_CYCLE_STATE_END (2U)
#  define DEM_CYCLE_STATE_END (2U)
# endif

# define Rte_TypeDef_Dem_ReturnGetDTCOfEventType
typedef uint8 Dem_ReturnGetDTCOfEventType;
# define Dem_ReturnGetDTCOfEventType_LowerLimit (0U)
# define Dem_ReturnGetDTCOfEventType_UpperLimit (2U)
# if (defined RTE_CONST_DEM_GET_DTCOFEVENT_OK) || (defined DEM_GET_DTCOFEVENT_OK)
#  if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_OK) || (RTE_CONST_DEM_GET_DTCOFEVENT_OK != 0U)
#   error "Enumeration constant <DEM_GET_DTCOFEVENT_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_GET_DTCOFEVENT_OK (0U)
#  define DEM_GET_DTCOFEVENT_OK (0U)
# endif
# if (defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID) || (defined DEM_GET_DTCOFEVENT_WRONG_EVENTID)
#  if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID) || (RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID != 1U)
#   error "Enumeration constant <DEM_GET_DTCOFEVENT_WRONG_EVENTID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID (1U)
#  define DEM_GET_DTCOFEVENT_WRONG_EVENTID (1U)
# endif
# if (defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND) || (defined DEM_GET_DTCOFEVENT_WRONG_DTCKIND)
#  if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND) || (RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND != 2U)
#   error "Enumeration constant <DEM_GET_DTCOFEVENT_WRONG_DTCKIND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND (2U)
#  define DEM_GET_DTCOFEVENT_WRONG_DTCKIND (2U)
# endif

# define Rte_TypeDef_DrvrModCtrl_enum
typedef uint8 DrvrModCtrl_enum;
# define DrvrModCtrl_enum_LowerLimit (1U)
# define DrvrModCtrl_enum_UpperLimit (4U)
# if (defined RTE_CONST_DMC_NORMAL) || (defined DMC_NORMAL)
#  if (!defined RTE_CONST_DMC_NORMAL) || (RTE_CONST_DMC_NORMAL != 1U)
#   error "Enumeration constant <DMC_NORMAL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DMC_NORMAL (1U)
#  define DMC_NORMAL (1U)
# endif
# if (defined RTE_CONST_DMC_SPORT) || (defined DMC_SPORT)
#  if (!defined RTE_CONST_DMC_SPORT) || (RTE_CONST_DMC_SPORT != 2U)
#   error "Enumeration constant <DMC_SPORT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DMC_SPORT (2U)
#  define DMC_SPORT (2U)
# endif
# if (defined RTE_CONST_DMC_SNOW) || (defined DMC_SNOW)
#  if (!defined RTE_CONST_DMC_SNOW) || (RTE_CONST_DMC_SNOW != 3U)
#   error "Enumeration constant <DMC_SNOW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DMC_SNOW (3U)
#  define DMC_SNOW (3U)
# endif
# if (defined RTE_CONST_DMC_TOUR) || (defined DMC_TOUR)
#  if (!defined RTE_CONST_DMC_TOUR) || (RTE_CONST_DMC_TOUR != 4U)
#   error "Enumeration constant <DMC_TOUR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DMC_TOUR (4U)
#  define DMC_TOUR (4U)
# endif

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;
# define EcuM_StateType_LowerLimit (16U)
# define EcuM_StateType_UpperLimit (255U)
# if (defined RTE_CONST_ECUM_STATE_STARTUP) || (defined ECUM_STATE_STARTUP)
#  if (!defined RTE_CONST_ECUM_STATE_STARTUP) || (RTE_CONST_ECUM_STATE_STARTUP != 16U)
#   error "Enumeration constant <ECUM_STATE_STARTUP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_STARTUP (16U)
#  define ECUM_STATE_STARTUP (16U)
# endif
# if (defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (defined ECUM_STATE_STARTUP_ONE)
#  if (!defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (RTE_CONST_ECUM_STATE_STARTUP_ONE != 17U)
#   error "Enumeration constant <ECUM_STATE_STARTUP_ONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_STARTUP_ONE (17U)
#  define ECUM_STATE_STARTUP_ONE (17U)
# endif
# if (defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (defined ECUM_STATE_STARTUP_TWO)
#  if (!defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (RTE_CONST_ECUM_STATE_STARTUP_TWO != 18U)
#   error "Enumeration constant <ECUM_STATE_STARTUP_TWO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_STARTUP_TWO (18U)
#  define ECUM_STATE_STARTUP_TWO (18U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP) || (defined ECUM_STATE_WAKEUP)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP) || (RTE_CONST_ECUM_STATE_WAKEUP != 32U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP (32U)
#  define ECUM_STATE_WAKEUP (32U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (defined ECUM_STATE_WAKEUP_ONE)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (RTE_CONST_ECUM_STATE_WAKEUP_ONE != 33U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_ONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_ONE (33U)
#  define ECUM_STATE_WAKEUP_ONE (33U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (defined ECUM_STATE_WAKEUP_VALIDATION)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION != 34U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_VALIDATION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION (34U)
#  define ECUM_STATE_WAKEUP_VALIDATION (34U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (defined ECUM_STATE_WAKEUP_REACTION)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (RTE_CONST_ECUM_STATE_WAKEUP_REACTION != 35U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_REACTION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_REACTION (35U)
#  define ECUM_STATE_WAKEUP_REACTION (35U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (defined ECUM_STATE_WAKEUP_TWO)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (RTE_CONST_ECUM_STATE_WAKEUP_TWO != 36U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_TWO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_TWO (36U)
#  define ECUM_STATE_WAKEUP_TWO (36U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (defined ECUM_STATE_WAKEUP_WAKESLEEP)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP != 37U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_WAKESLEEP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#  define ECUM_STATE_WAKEUP_WAKESLEEP (37U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (defined ECUM_STATE_WAKEUP_TTII)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (RTE_CONST_ECUM_STATE_WAKEUP_TTII != 38U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_TTII> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_TTII (38U)
#  define ECUM_STATE_WAKEUP_TTII (38U)
# endif
# if (defined RTE_CONST_ECUM_STATE_RUN) || (defined ECUM_STATE_RUN)
#  if (!defined RTE_CONST_ECUM_STATE_RUN) || (RTE_CONST_ECUM_STATE_RUN != 48U)
#   error "Enumeration constant <ECUM_STATE_RUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_RUN (48U)
#  define ECUM_STATE_RUN (48U)
# endif
# if (defined RTE_CONST_ECUM_STATE_APP_RUN) || (defined ECUM_STATE_APP_RUN)
#  if (!defined RTE_CONST_ECUM_STATE_APP_RUN) || (RTE_CONST_ECUM_STATE_APP_RUN != 50U)
#   error "Enumeration constant <ECUM_STATE_APP_RUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_APP_RUN (50U)
#  define ECUM_STATE_APP_RUN (50U)
# endif
# if (defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (defined ECUM_STATE_APP_POST_RUN)
#  if (!defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (RTE_CONST_ECUM_STATE_APP_POST_RUN != 51U)
#   error "Enumeration constant <ECUM_STATE_APP_POST_RUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_APP_POST_RUN (51U)
#  define ECUM_STATE_APP_POST_RUN (51U)
# endif
# if (defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (defined ECUM_STATE_SHUTDOWN)
#  if (!defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (RTE_CONST_ECUM_STATE_SHUTDOWN != 64U)
#   error "Enumeration constant <ECUM_STATE_SHUTDOWN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_SHUTDOWN (64U)
#  define ECUM_STATE_SHUTDOWN (64U)
# endif
# if (defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (defined ECUM_STATE_PREP_SHUTDOWN)
#  if (!defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (RTE_CONST_ECUM_STATE_PREP_SHUTDOWN != 68U)
#   error "Enumeration constant <ECUM_STATE_PREP_SHUTDOWN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_PREP_SHUTDOWN (68U)
#  define ECUM_STATE_PREP_SHUTDOWN (68U)
# endif
# if (defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (defined ECUM_STATE_GO_SLEEP)
#  if (!defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (RTE_CONST_ECUM_STATE_GO_SLEEP != 73U)
#   error "Enumeration constant <ECUM_STATE_GO_SLEEP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_GO_SLEEP (73U)
#  define ECUM_STATE_GO_SLEEP (73U)
# endif
# if (defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (defined ECUM_STATE_GO_OFF_ONE)
#  if (!defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (RTE_CONST_ECUM_STATE_GO_OFF_ONE != 77U)
#   error "Enumeration constant <ECUM_STATE_GO_OFF_ONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_GO_OFF_ONE (77U)
#  define ECUM_STATE_GO_OFF_ONE (77U)
# endif
# if (defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (defined ECUM_STATE_GO_OFF_TWO)
#  if (!defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (RTE_CONST_ECUM_STATE_GO_OFF_TWO != 78U)
#   error "Enumeration constant <ECUM_STATE_GO_OFF_TWO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_GO_OFF_TWO (78U)
#  define ECUM_STATE_GO_OFF_TWO (78U)
# endif
# if (defined RTE_CONST_ECUM_STATE_SLEEP) || (defined ECUM_STATE_SLEEP)
#  if (!defined RTE_CONST_ECUM_STATE_SLEEP) || (RTE_CONST_ECUM_STATE_SLEEP != 80U)
#   error "Enumeration constant <ECUM_STATE_SLEEP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_SLEEP (80U)
#  define ECUM_STATE_SLEEP (80U)
# endif
# if (defined RTE_CONST_ECUM_STATE_OFF) || (defined ECUM_STATE_OFF)
#  if (!defined RTE_CONST_ECUM_STATE_OFF) || (RTE_CONST_ECUM_STATE_OFF != 128U)
#   error "Enumeration constant <ECUM_STATE_OFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_OFF (128U)
#  define ECUM_STATE_OFF (128U)
# endif
# if (defined RTE_CONST_ECUM_STATE_RESET) || (defined ECUM_STATE_RESET)
#  if (!defined RTE_CONST_ECUM_STATE_RESET) || (RTE_CONST_ECUM_STATE_RESET != 144U)
#   error "Enumeration constant <ECUM_STATE_RESET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_RESET (144U)
#  define ECUM_STATE_RESET (144U)
# endif
# if (defined RTE_CONST_ECUM_STATE_ERROR) || (defined ECUM_STATE_ERROR)
#  if (!defined RTE_CONST_ECUM_STATE_ERROR) || (RTE_CONST_ECUM_STATE_ERROR != 255U)
#   error "Enumeration constant <ECUM_STATE_ERROR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_ERROR (255U)
#  define ECUM_STATE_ERROR (255U)
# endif

# define Rte_TypeDef_Edch_Dcm_NegativeResponseCodeType
typedef uint8 Edch_Dcm_NegativeResponseCodeType;
# define Edch_Dcm_NegativeResponseCodeType_LowerLimit (0U)
# define Edch_Dcm_NegativeResponseCodeType_UpperLimit (255U)
# if (defined RTE_CONST_EDCH_DCM_E_GENERALREJECT) || (defined EDCH_DCM_E_GENERALREJECT)
#  if (!defined RTE_CONST_EDCH_DCM_E_GENERALREJECT) || (RTE_CONST_EDCH_DCM_E_GENERALREJECT != 16U)
#   error "Enumeration constant <EDCH_DCM_E_GENERALREJECT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_GENERALREJECT (16U)
#  define EDCH_DCM_E_GENERALREJECT (16U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_BUSYREPEATREQUEST) || (defined EDCH_DCM_E_BUSYREPEATREQUEST)
#  if (!defined RTE_CONST_EDCH_DCM_E_BUSYREPEATREQUEST) || (RTE_CONST_EDCH_DCM_E_BUSYREPEATREQUEST != 33U)
#   error "Enumeration constant <EDCH_DCM_E_BUSYREPEATREQUEST> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_BUSYREPEATREQUEST (33U)
#  define EDCH_DCM_E_BUSYREPEATREQUEST (33U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_CONDITIONSNOTCORRECT) || (defined EDCH_DCM_E_CONDITIONSNOTCORRECT)
#  if (!defined RTE_CONST_EDCH_DCM_E_CONDITIONSNOTCORRECT) || (RTE_CONST_EDCH_DCM_E_CONDITIONSNOTCORRECT != 34U)
#   error "Enumeration constant <EDCH_DCM_E_CONDITIONSNOTCORRECT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_CONDITIONSNOTCORRECT (34U)
#  define EDCH_DCM_E_CONDITIONSNOTCORRECT (34U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_REQUESTSEQUENCEERROR) || (defined EDCH_DCM_E_REQUESTSEQUENCEERROR)
#  if (!defined RTE_CONST_EDCH_DCM_E_REQUESTSEQUENCEERROR) || (RTE_CONST_EDCH_DCM_E_REQUESTSEQUENCEERROR != 36U)
#   error "Enumeration constant <EDCH_DCM_E_REQUESTSEQUENCEERROR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_REQUESTSEQUENCEERROR (36U)
#  define EDCH_DCM_E_REQUESTSEQUENCEERROR (36U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_REQUESTOUTOFRANGE) || (defined EDCH_DCM_E_REQUESTOUTOFRANGE)
#  if (!defined RTE_CONST_EDCH_DCM_E_REQUESTOUTOFRANGE) || (RTE_CONST_EDCH_DCM_E_REQUESTOUTOFRANGE != 49U)
#   error "Enumeration constant <EDCH_DCM_E_REQUESTOUTOFRANGE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_REQUESTOUTOFRANGE (49U)
#  define EDCH_DCM_E_REQUESTOUTOFRANGE (49U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_SECURITYACCESSDENIED) || (defined EDCH_DCM_E_SECURITYACCESSDENIED)
#  if (!defined RTE_CONST_EDCH_DCM_E_SECURITYACCESSDENIED) || (RTE_CONST_EDCH_DCM_E_SECURITYACCESSDENIED != 51U)
#   error "Enumeration constant <EDCH_DCM_E_SECURITYACCESSDENIED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_SECURITYACCESSDENIED (51U)
#  define EDCH_DCM_E_SECURITYACCESSDENIED (51U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_GENERALPROGRAMMINGFAILURE) || (defined EDCH_DCM_E_GENERALPROGRAMMINGFAILURE)
#  if (!defined RTE_CONST_EDCH_DCM_E_GENERALPROGRAMMINGFAILURE) || (RTE_CONST_EDCH_DCM_E_GENERALPROGRAMMINGFAILURE != 114U)
#   error "Enumeration constant <EDCH_DCM_E_GENERALPROGRAMMINGFAILURE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_GENERALPROGRAMMINGFAILURE (114U)
#  define EDCH_DCM_E_GENERALPROGRAMMINGFAILURE (114U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION) || (defined EDCH_DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION)
#  if (!defined RTE_CONST_EDCH_DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION) || (RTE_CONST_EDCH_DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION != 126U)
#   error "Enumeration constant <EDCH_DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
#  define EDCH_DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_RPMTOOHIGH) || (defined EDCH_DCM_E_RPMTOOHIGH)
#  if (!defined RTE_CONST_EDCH_DCM_E_RPMTOOHIGH) || (RTE_CONST_EDCH_DCM_E_RPMTOOHIGH != 129U)
#   error "Enumeration constant <EDCH_DCM_E_RPMTOOHIGH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_RPMTOOHIGH (129U)
#  define EDCH_DCM_E_RPMTOOHIGH (129U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_RPMTOOLOW) || (defined EDCH_DCM_E_RPMTOOLOW)
#  if (!defined RTE_CONST_EDCH_DCM_E_RPMTOOLOW) || (RTE_CONST_EDCH_DCM_E_RPMTOOLOW != 130U)
#   error "Enumeration constant <EDCH_DCM_E_RPMTOOLOW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_RPMTOOLOW (130U)
#  define EDCH_DCM_E_RPMTOOLOW (130U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_ENGINEISRUNNING) || (defined EDCH_DCM_E_ENGINEISRUNNING)
#  if (!defined RTE_CONST_EDCH_DCM_E_ENGINEISRUNNING) || (RTE_CONST_EDCH_DCM_E_ENGINEISRUNNING != 131U)
#   error "Enumeration constant <EDCH_DCM_E_ENGINEISRUNNING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_ENGINEISRUNNING (131U)
#  define EDCH_DCM_E_ENGINEISRUNNING (131U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_ENGINEISNOTRUNNING) || (defined EDCH_DCM_E_ENGINEISNOTRUNNING)
#  if (!defined RTE_CONST_EDCH_DCM_E_ENGINEISNOTRUNNING) || (RTE_CONST_EDCH_DCM_E_ENGINEISNOTRUNNING != 132U)
#   error "Enumeration constant <EDCH_DCM_E_ENGINEISNOTRUNNING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_ENGINEISNOTRUNNING (132U)
#  define EDCH_DCM_E_ENGINEISNOTRUNNING (132U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_ENGINERUNTIMETOOLOW) || (defined EDCH_DCM_E_ENGINERUNTIMETOOLOW)
#  if (!defined RTE_CONST_EDCH_DCM_E_ENGINERUNTIMETOOLOW) || (RTE_CONST_EDCH_DCM_E_ENGINERUNTIMETOOLOW != 133U)
#   error "Enumeration constant <EDCH_DCM_E_ENGINERUNTIMETOOLOW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_ENGINERUNTIMETOOLOW (133U)
#  define EDCH_DCM_E_ENGINERUNTIMETOOLOW (133U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_TEMPERATURETOOHIGH) || (defined EDCH_DCM_E_TEMPERATURETOOHIGH)
#  if (!defined RTE_CONST_EDCH_DCM_E_TEMPERATURETOOHIGH) || (RTE_CONST_EDCH_DCM_E_TEMPERATURETOOHIGH != 134U)
#   error "Enumeration constant <EDCH_DCM_E_TEMPERATURETOOHIGH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_TEMPERATURETOOHIGH (134U)
#  define EDCH_DCM_E_TEMPERATURETOOHIGH (134U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_TEMPERATURETOOLOW) || (defined EDCH_DCM_E_TEMPERATURETOOLOW)
#  if (!defined RTE_CONST_EDCH_DCM_E_TEMPERATURETOOLOW) || (RTE_CONST_EDCH_DCM_E_TEMPERATURETOOLOW != 135U)
#   error "Enumeration constant <EDCH_DCM_E_TEMPERATURETOOLOW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_TEMPERATURETOOLOW (135U)
#  define EDCH_DCM_E_TEMPERATURETOOLOW (135U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_VEHICLESPEEDTOOHIGH) || (defined EDCH_DCM_E_VEHICLESPEEDTOOHIGH)
#  if (!defined RTE_CONST_EDCH_DCM_E_VEHICLESPEEDTOOHIGH) || (RTE_CONST_EDCH_DCM_E_VEHICLESPEEDTOOHIGH != 136U)
#   error "Enumeration constant <EDCH_DCM_E_VEHICLESPEEDTOOHIGH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_VEHICLESPEEDTOOHIGH (136U)
#  define EDCH_DCM_E_VEHICLESPEEDTOOHIGH (136U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_VEHICLESPEEDTOOLOW) || (defined EDCH_DCM_E_VEHICLESPEEDTOOLOW)
#  if (!defined RTE_CONST_EDCH_DCM_E_VEHICLESPEEDTOOLOW) || (RTE_CONST_EDCH_DCM_E_VEHICLESPEEDTOOLOW != 137U)
#   error "Enumeration constant <EDCH_DCM_E_VEHICLESPEEDTOOLOW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_VEHICLESPEEDTOOLOW (137U)
#  define EDCH_DCM_E_VEHICLESPEEDTOOLOW (137U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_THROTTLE_PEDALTOOHIGH) || (defined EDCH_DCM_E_THROTTLE_PEDALTOOHIGH)
#  if (!defined RTE_CONST_EDCH_DCM_E_THROTTLE_PEDALTOOHIGH) || (RTE_CONST_EDCH_DCM_E_THROTTLE_PEDALTOOHIGH != 138U)
#   error "Enumeration constant <EDCH_DCM_E_THROTTLE_PEDALTOOHIGH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_THROTTLE_PEDALTOOHIGH (138U)
#  define EDCH_DCM_E_THROTTLE_PEDALTOOHIGH (138U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_THROTTLE_PEDALTOOLOW) || (defined EDCH_DCM_E_THROTTLE_PEDALTOOLOW)
#  if (!defined RTE_CONST_EDCH_DCM_E_THROTTLE_PEDALTOOLOW) || (RTE_CONST_EDCH_DCM_E_THROTTLE_PEDALTOOLOW != 139U)
#   error "Enumeration constant <EDCH_DCM_E_THROTTLE_PEDALTOOLOW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_THROTTLE_PEDALTOOLOW (139U)
#  define EDCH_DCM_E_THROTTLE_PEDALTOOLOW (139U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_TRANSMISSIONRANGENOTINNEUTRAL) || (defined EDCH_DCM_E_TRANSMISSIONRANGENOTINNEUTRAL)
#  if (!defined RTE_CONST_EDCH_DCM_E_TRANSMISSIONRANGENOTINNEUTRAL) || (RTE_CONST_EDCH_DCM_E_TRANSMISSIONRANGENOTINNEUTRAL != 140U)
#   error "Enumeration constant <EDCH_DCM_E_TRANSMISSIONRANGENOTINNEUTRAL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
#  define EDCH_DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_TRANSMISSIONRANGENOTINGEAR) || (defined EDCH_DCM_E_TRANSMISSIONRANGENOTINGEAR)
#  if (!defined RTE_CONST_EDCH_DCM_E_TRANSMISSIONRANGENOTINGEAR) || (RTE_CONST_EDCH_DCM_E_TRANSMISSIONRANGENOTINGEAR != 141U)
#   error "Enumeration constant <EDCH_DCM_E_TRANSMISSIONRANGENOTINGEAR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
#  define EDCH_DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_BRAKESWITCH_NOTCLOSED) || (defined EDCH_DCM_E_BRAKESWITCH_NOTCLOSED)
#  if (!defined RTE_CONST_EDCH_DCM_E_BRAKESWITCH_NOTCLOSED) || (RTE_CONST_EDCH_DCM_E_BRAKESWITCH_NOTCLOSED != 143U)
#   error "Enumeration constant <EDCH_DCM_E_BRAKESWITCH_NOTCLOSED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_BRAKESWITCH_NOTCLOSED (143U)
#  define EDCH_DCM_E_BRAKESWITCH_NOTCLOSED (143U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_SHIFTERLEVERNOTINPARK) || (defined EDCH_DCM_E_SHIFTERLEVERNOTINPARK)
#  if (!defined RTE_CONST_EDCH_DCM_E_SHIFTERLEVERNOTINPARK) || (RTE_CONST_EDCH_DCM_E_SHIFTERLEVERNOTINPARK != 144U)
#   error "Enumeration constant <EDCH_DCM_E_SHIFTERLEVERNOTINPARK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_SHIFTERLEVERNOTINPARK (144U)
#  define EDCH_DCM_E_SHIFTERLEVERNOTINPARK (144U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_TORQUECONVERTERCLUTCHLOCKED) || (defined EDCH_DCM_E_TORQUECONVERTERCLUTCHLOCKED)
#  if (!defined RTE_CONST_EDCH_DCM_E_TORQUECONVERTERCLUTCHLOCKED) || (RTE_CONST_EDCH_DCM_E_TORQUECONVERTERCLUTCHLOCKED != 145U)
#   error "Enumeration constant <EDCH_DCM_E_TORQUECONVERTERCLUTCHLOCKED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
#  define EDCH_DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_VOLTAGETOOHIGH) || (defined EDCH_DCM_E_VOLTAGETOOHIGH)
#  if (!defined RTE_CONST_EDCH_DCM_E_VOLTAGETOOHIGH) || (RTE_CONST_EDCH_DCM_E_VOLTAGETOOHIGH != 146U)
#   error "Enumeration constant <EDCH_DCM_E_VOLTAGETOOHIGH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_VOLTAGETOOHIGH (146U)
#  define EDCH_DCM_E_VOLTAGETOOHIGH (146U)
# endif
# if (defined RTE_CONST_EDCH_DCM_E_VOLTAGETOOLOW) || (defined EDCH_DCM_E_VOLTAGETOOLOW)
#  if (!defined RTE_CONST_EDCH_DCM_E_VOLTAGETOOLOW) || (RTE_CONST_EDCH_DCM_E_VOLTAGETOOLOW != 147U)
#   error "Enumeration constant <EDCH_DCM_E_VOLTAGETOOLOW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EDCH_DCM_E_VOLTAGETOOLOW (147U)
#  define EDCH_DCM_E_VOLTAGETOOLOW (147U)
# endif

# define Rte_TypeDef_EnergyModeStateType
typedef uint8 EnergyModeStateType;
# define EnergyModeStateType_LowerLimit (0U)
# define EnergyModeStateType_UpperLimit (3U)
# if (defined RTE_CONST_NORMAL) || (defined NORMAL)
#  if (!defined RTE_CONST_NORMAL) || (RTE_CONST_NORMAL != 0U)
#   error "Enumeration constant <NORMAL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NORMAL (0U)
#  define NORMAL (0U)
# endif
# if (defined RTE_CONST_PRODUCTION) || (defined PRODUCTION)
#  if (!defined RTE_CONST_PRODUCTION) || (RTE_CONST_PRODUCTION != 1U)
#   error "Enumeration constant <PRODUCTION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PRODUCTION (1U)
#  define PRODUCTION (1U)
# endif
# if (defined RTE_CONST_TRANSPORTATION) || (defined TRANSPORTATION)
#  if (!defined RTE_CONST_TRANSPORTATION) || (RTE_CONST_TRANSPORTATION != 2U)
#   error "Enumeration constant <TRANSPORTATION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TRANSPORTATION (2U)
#  define TRANSPORTATION (2U)
# endif
# if (defined RTE_CONST_FLASH) || (defined FLASH)
#  if (!defined RTE_CONST_FLASH) || (RTE_CONST_FLASH != 3U)
#   error "Enumeration constant <FLASH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLASH (3U)
#  define FLASH (3U)
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

# define Rte_TypeDef_FETFAULTTYPE_ENUM
typedef uint8 FETFAULTTYPE_ENUM;
# define FETFAULTTYPE_ENUM_LowerLimit (0U)
# define FETFAULTTYPE_ENUM_UpperLimit (255U)
# if (defined RTE_CONST_NOFAULT) || (defined NOFAULT)
#  if (!defined RTE_CONST_NOFAULT) || (RTE_CONST_NOFAULT != 0U)
#   error "Enumeration constant <NOFAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NOFAULT (0U)
#  define NOFAULT (0U)
# endif
# if (defined RTE_CONST_LOWER) || (defined LOWER)
#  if (!defined RTE_CONST_LOWER) || (RTE_CONST_LOWER != 1U)
#   error "Enumeration constant <LOWER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOWER (1U)
#  define LOWER (1U)
# endif
# if (defined RTE_CONST_UPPER) || (defined UPPER)
#  if (!defined RTE_CONST_UPPER) || (RTE_CONST_UPPER != 2U)
#   error "Enumeration constant <UPPER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_UPPER (2U)
#  define UPPER (2U)
# endif

# define Rte_TypeDef_FETPHASETYPE_ENUM
typedef uint8 FETPHASETYPE_ENUM;
# define FETPHASETYPE_ENUM_LowerLimit (0U)
# define FETPHASETYPE_ENUM_UpperLimit (255U)
# if (defined RTE_CONST_NOPHASE) || (defined NOPHASE)
#  if (!defined RTE_CONST_NOPHASE) || (RTE_CONST_NOPHASE != 0U)
#   error "Enumeration constant <NOPHASE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NOPHASE (0U)
#  define NOPHASE (0U)
# endif
# if (defined RTE_CONST_PHASEA) || (defined PHASEA)
#  if (!defined RTE_CONST_PHASEA) || (RTE_CONST_PHASEA != 1U)
#   error "Enumeration constant <PHASEA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PHASEA (1U)
#  define PHASEA (1U)
# endif
# if (defined RTE_CONST_PHASEB) || (defined PHASEB)
#  if (!defined RTE_CONST_PHASEB) || (RTE_CONST_PHASEB != 2U)
#   error "Enumeration constant <PHASEB> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PHASEB (2U)
#  define PHASEB (2U)
# endif
# if (defined RTE_CONST_PHASEC) || (defined PHASEC)
#  if (!defined RTE_CONST_PHASEC) || (RTE_CONST_PHASEC != 3U)
#   error "Enumeration constant <PHASEC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_PHASEC (3U)
#  define PHASEC (3U)
# endif

# define Rte_TypeDef_FltInjectionLocType
typedef uint8 FltInjectionLocType;
# define FltInjectionLocType_LowerLimit (0U)
# define FltInjectionLocType_UpperLimit (255U)
# if (defined RTE_CONST_FLTINJ_ASSIST) || (defined FLTINJ_ASSIST)
#  if (!defined RTE_CONST_FLTINJ_ASSIST) || (RTE_CONST_FLTINJ_ASSIST != 1U)
#   error "Enumeration constant <FLTINJ_ASSIST> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSIST (1U)
#  define FLTINJ_ASSIST (1U)
# endif
# if (defined RTE_CONST_FLTINJ_RETURN) || (defined FLTINJ_RETURN)
#  if (!defined RTE_CONST_FLTINJ_RETURN) || (RTE_CONST_FLTINJ_RETURN != 2U)
#   error "Enumeration constant <FLTINJ_RETURN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_RETURN (2U)
#  define FLTINJ_RETURN (2U)
# endif
# if (defined RTE_CONST_FLTINJ_DAMPING) || (defined FLTINJ_DAMPING)
#  if (!defined RTE_CONST_FLTINJ_DAMPING) || (RTE_CONST_FLTINJ_DAMPING != 3U)
#   error "Enumeration constant <FLTINJ_DAMPING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DAMPING (3U)
#  define FLTINJ_DAMPING (3U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTSUMNLMT) || (defined FLTINJ_ASSTSUMNLMT)
#  if (!defined RTE_CONST_FLTINJ_ASSTSUMNLMT) || (RTE_CONST_FLTINJ_ASSTSUMNLMT != 4U)
#   error "Enumeration constant <FLTINJ_ASSTSUMNLMT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTSUMNLMT (4U)
#  define FLTINJ_ASSTSUMNLMT (4U)
# endif
# if (defined RTE_CONST_FLTINJ_AVGFRICLRN) || (defined FLTINJ_AVGFRICLRN)
#  if (!defined RTE_CONST_FLTINJ_AVGFRICLRN) || (RTE_CONST_FLTINJ_AVGFRICLRN != 7U)
#   error "Enumeration constant <FLTINJ_AVGFRICLRN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_AVGFRICLRN (7U)
#  define FLTINJ_AVGFRICLRN (7U)
# endif
# if (defined RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE) || (defined FLTINJ_VECU_BATTERYVOLTAGE)
#  if (!defined RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE) || (RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE != 8U)
#   error "Enumeration constant <FLTINJ_VECU_BATTERYVOLTAGE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE (8U)
#  define FLTINJ_VECU_BATTERYVOLTAGE (8U)
# endif
# if (defined RTE_CONST_FLTINJ_HYSTCOMP) || (defined FLTINJ_HYSTCOMP)
#  if (!defined RTE_CONST_FLTINJ_HYSTCOMP) || (RTE_CONST_FLTINJ_HYSTCOMP != 12U)
#   error "Enumeration constant <FLTINJ_HYSTCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_HYSTCOMP (12U)
#  define FLTINJ_HYSTCOMP (12U)
# endif
# if (defined RTE_CONST_FLTINJ_INERTIACOMP) || (defined FLTINJ_INERTIACOMP)
#  if (!defined RTE_CONST_FLTINJ_INERTIACOMP) || (RTE_CONST_FLTINJ_INERTIACOMP != 14U)
#   error "Enumeration constant <FLTINJ_INERTIACOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_INERTIACOMP (14U)
#  define FLTINJ_INERTIACOMP (14U)
# endif
# if (defined RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL) || (defined FLTINJ_SUPPPWRLMT_CUSTPL)
#  if (!defined RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL) || (RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL != 25U)
#   error "Enumeration constant <FLTINJ_SUPPPWRLMT_CUSTPL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL (25U)
#  define FLTINJ_SUPPPWRLMT_CUSTPL (25U)
# endif
# if (defined RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW) || (defined FLTINJ_EOTDAMPING_ETDMPFW)
#  if (!defined RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW) || (RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW != 27U)
#   error "Enumeration constant <FLTINJ_EOTDAMPING_ETDMPFW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW (27U)
#  define FLTINJ_EOTDAMPING_ETDMPFW (27U)
# endif
# if (defined RTE_CONST_FLTINJ_STABILITYCOMP) || (defined FLTINJ_STABILITYCOMP)
#  if (!defined RTE_CONST_FLTINJ_STABILITYCOMP) || (RTE_CONST_FLTINJ_STABILITYCOMP != 29U)
#   error "Enumeration constant <FLTINJ_STABILITYCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_STABILITYCOMP (29U)
#  define FLTINJ_STABILITYCOMP (29U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQBASEDINRTCOMP) || (defined FLTINJ_TRQBASEDINRTCOMP)
#  if (!defined RTE_CONST_FLTINJ_TRQBASEDINRTCOMP) || (RTE_CONST_FLTINJ_TRQBASEDINRTCOMP != 30U)
#   error "Enumeration constant <FLTINJ_TRQBASEDINRTCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQBASEDINRTCOMP (30U)
#  define FLTINJ_TRQBASEDINRTCOMP (30U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND) || (defined FLTINJ_SRLCOMVEHSPD_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND != 33U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHSPD_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND (33U)
#  define FLTINJ_SRLCOMVEHSPD_SGNLCOND (33U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTFIREWALL) || (defined FLTINJ_ASSTFIREWALL)
#  if (!defined RTE_CONST_FLTINJ_ASSTFIREWALL) || (RTE_CONST_FLTINJ_ASSTFIREWALL != 34U)
#   error "Enumeration constant <FLTINJ_ASSTFIREWALL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTFIREWALL (34U)
#  define FLTINJ_ASSTFIREWALL (34U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD) || (defined FLTINJ_ASSTEOTGAIN_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD) || (RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD != 38U)
#   error "Enumeration constant <FLTINJ_ASSTEOTGAIN_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD (38U)
#  define FLTINJ_ASSTEOTGAIN_LMTCOD (38U)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTRQT1) || (defined FLTINJ_ANAHWTRQT1)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTRQT1) || (RTE_CONST_FLTINJ_ANAHWTRQT1 != 39U)
#   error "Enumeration constant <FLTINJ_ANAHWTRQT1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTRQT1 (39U)
#  define FLTINJ_ANAHWTRQT1 (39U)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTRQT2) || (defined FLTINJ_ANAHWTRQT2)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTRQT2) || (RTE_CONST_FLTINJ_ANAHWTRQT2 != 40U)
#   error "Enumeration constant <FLTINJ_ANAHWTRQT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTRQT2 (40U)
#  define FLTINJ_ANAHWTRQT2 (40U)
# endif
# if (defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT) || (defined FLTINJ_DIGHWTRQSENT_T1FAULT)
#  if (!defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT) || (RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT != 41U)
#   error "Enumeration constant <FLTINJ_DIGHWTRQSENT_T1FAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT (41U)
#  define FLTINJ_DIGHWTRQSENT_T1FAULT (41U)
# endif
# if (defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT) || (defined FLTINJ_DIGHWTRQSENT_T2FAULT)
#  if (!defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT) || (RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT != 42U)
#   error "Enumeration constant <FLTINJ_DIGHWTRQSENT_T2FAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT (42U)
#  define FLTINJ_DIGHWTRQSENT_T2FAULT (42U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND) || (defined FLTINJ_TRQOSC_PREFINALCOMMAND)
#  if (!defined RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND) || (RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND != 43U)
#   error "Enumeration constant <FLTINJ_TRQOSC_PREFINALCOMMAND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND (43U)
#  define FLTINJ_TRQOSC_PREFINALCOMMAND (43U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBCROLLGCNTR) || (defined FLTINJ_IMCARBCROLLGCNTR)
#  if (!defined RTE_CONST_FLTINJ_IMCARBCROLLGCNTR) || (RTE_CONST_FLTINJ_IMCARBCROLLGCNTR != 44U)
#   error "Enumeration constant <FLTINJ_IMCARBCROLLGCNTR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBCROLLGCNTR (44U)
#  define FLTINJ_IMCARBCROLLGCNTR (44U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRCRC) || (defined FLTINJ_IMCARBRCRC)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRCRC) || (RTE_CONST_FLTINJ_IMCARBRCRC != 45U)
#   error "Enumeration constant <FLTINJ_IMCARBRCRC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRCRC (45U)
#  define FLTINJ_IMCARBRCRC (45U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRDATA) || (defined FLTINJ_IMCARBRDATA)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRDATA) || (RTE_CONST_FLTINJ_IMCARBRDATA != 46U)
#   error "Enumeration constant <FLTINJ_IMCARBRDATA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRDATA (46U)
#  define FLTINJ_IMCARBRDATA (46U)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_HWTRQ) || (defined FLTINJ_GCCDIAG_HWTRQ)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_HWTRQ) || (RTE_CONST_FLTINJ_GCCDIAG_HWTRQ != 46U)
#   error "Enumeration constant <FLTINJ_GCCDIAG_HWTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_HWTRQ (46U)
#  define FLTINJ_GCCDIAG_HWTRQ (46U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRPATIDN) || (defined FLTINJ_IMCARBRPATIDN)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRPATIDN) || (RTE_CONST_FLTINJ_IMCARBRPATIDN != 47U)
#   error "Enumeration constant <FLTINJ_IMCARBRPATIDN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRPATIDN (47U)
#  define FLTINJ_IMCARBRPATIDN (47U)
# endif
# if (defined RTE_CONST_FLTINJ_CMMTRCURR1) || (defined FLTINJ_CMMTRCURR1)
#  if (!defined RTE_CONST_FLTINJ_CMMTRCURR1) || (RTE_CONST_FLTINJ_CMMTRCURR1 != 48U)
#   error "Enumeration constant <FLTINJ_CMMTRCURR1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_CMMTRCURR1 (48U)
#  define FLTINJ_CMMTRCURR1 (48U)
# endif
# if (defined RTE_CONST_FLTINJ_CMMTRCURR2) || (defined FLTINJ_CMMTRCURR2)
#  if (!defined RTE_CONST_FLTINJ_CMMTRCURR2) || (RTE_CONST_FLTINJ_CMMTRCURR2 != 49U)
#   error "Enumeration constant <FLTINJ_CMMTRCURR2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_CMMTRCURR2 (49U)
#  define FLTINJ_CMMTRCURR2 (49U)
# endif
# if (defined RTE_CONST_FLTINJ_NHET1CFGANDUSE1) || (defined FLTINJ_NHET1CFGANDUSE1)
#  if (!defined RTE_CONST_FLTINJ_NHET1CFGANDUSE1) || (RTE_CONST_FLTINJ_NHET1CFGANDUSE1 != 50U)
#   error "Enumeration constant <FLTINJ_NHET1CFGANDUSE1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_NHET1CFGANDUSE1 (50U)
#  define FLTINJ_NHET1CFGANDUSE1 (50U)
# endif
# if (defined RTE_CONST_FLTINJ_NHET1CFGANDUSE2) || (defined FLTINJ_NHET1CFGANDUSE2)
#  if (!defined RTE_CONST_FLTINJ_NHET1CFGANDUSE2) || (RTE_CONST_FLTINJ_NHET1CFGANDUSE2 != 51U)
#   error "Enumeration constant <FLTINJ_NHET1CFGANDUSE2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_NHET1CFGANDUSE2 (51U)
#  define FLTINJ_NHET1CFGANDUSE2 (51U)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP1) || (defined FLTINJ_EPWM_UP1)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP1) || (RTE_CONST_FLTINJ_EPWM_UP1 != 52U)
#   error "Enumeration constant <FLTINJ_EPWM_UP1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP1 (52U)
#  define FLTINJ_EPWM_UP1 (52U)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP2) || (defined FLTINJ_EPWM_UP2)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP2) || (RTE_CONST_FLTINJ_EPWM_UP2 != 53U)
#   error "Enumeration constant <FLTINJ_EPWM_UP2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP2 (53U)
#  define FLTINJ_EPWM_UP2 (53U)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP3) || (defined FLTINJ_EPWM_UP3)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP3) || (RTE_CONST_FLTINJ_EPWM_UP3 != 54U)
#   error "Enumeration constant <FLTINJ_EPWM_UP3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP3 (54U)
#  define FLTINJ_EPWM_UP3 (54U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENCAN) || (defined FLTINJ_IMCARBROPENCAN)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENCAN) || (RTE_CONST_FLTINJ_IMCARBROPENCAN != 65U)
#   error "Enumeration constant <FLTINJ_IMCARBROPENCAN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENCAN (65U)
#  define FLTINJ_IMCARBROPENCAN (65U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENCANSCI) || (defined FLTINJ_IMCARBROPENCANSCI)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENCANSCI) || (RTE_CONST_FLTINJ_IMCARBROPENCANSCI != 66U)
#   error "Enumeration constant <FLTINJ_IMCARBROPENCANSCI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENCANSCI (66U)
#  define FLTINJ_IMCARBROPENCANSCI (66U)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENSCI) || (defined FLTINJ_IMCARBROPENSCI)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENSCI) || (RTE_CONST_FLTINJ_IMCARBROPENSCI != 67U)
#   error "Enumeration constant <FLTINJ_IMCARBROPENSCI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENSCI (67U)
#  define FLTINJ_IMCARBROPENSCI (67U)
# endif
# if (defined RTE_CONST_FLTINJ_BMWTOC) || (defined FLTINJ_BMWTOC)
#  if (!defined RTE_CONST_FLTINJ_BMWTOC) || (RTE_CONST_FLTINJ_BMWTOC != 68U)
#   error "Enumeration constant <FLTINJ_BMWTOC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_BMWTOC (68U)
#  define FLTINJ_BMWTOC (68U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT) || (defined FLTINJ_TRQOVLSTA_LKAFAULT)
#  if (!defined RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT) || (RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT != 91U)
#   error "Enumeration constant <FLTINJ_TRQOVLSTA_LKAFAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT (91U)
#  define FLTINJ_TRQOVLSTA_LKAFAULT (91U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND) || (defined FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND != 100U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100U)
#  define FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQARBLIM_LKACMD) || (defined FLTINJ_TRQARBLIM_LKACMD)
#  if (!defined RTE_CONST_FLTINJ_TRQARBLIM_LKACMD) || (RTE_CONST_FLTINJ_TRQARBLIM_LKACMD != 101U)
#   error "Enumeration constant <FLTINJ_TRQARBLIM_LKACMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQARBLIM_LKACMD (101U)
#  define FLTINJ_TRQARBLIM_LKACMD (101U)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_VEHSPD) || (defined FLTINJ_GCCDIAG_VEHSPD)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_VEHSPD) || (RTE_CONST_FLTINJ_GCCDIAG_VEHSPD != 146U)
#   error "Enumeration constant <FLTINJ_GCCDIAG_VEHSPD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_VEHSPD (146U)
#  define FLTINJ_GCCDIAG_VEHSPD (146U)
# endif
# if (defined RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDASTFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL != 150U)
#   error "Enumeration constant <FLTINJ_DDASTFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150U)
#  define FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150U)
# endif
# if (defined RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDDMPFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL != 151U)
#   error "Enumeration constant <FLTINJ_DDDMPFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151U)
#  define FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151U)
# endif
# if (defined RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDRTNFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL != 152U)
#   error "Enumeration constant <FLTINJ_DDRTNFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152U)
#  define FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152U)
# endif
# if (defined RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD) || (defined FLTINJ_OUTPUTRAMPMULT_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD) || (RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD != 153U)
#   error "Enumeration constant <FLTINJ_OUTPUTRAMPMULT_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD (153U)
#  define FLTINJ_OUTPUTRAMPMULT_LMTCOD (153U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD) || (defined FLTINJ_ASSTEOTLIMIT_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD) || (RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD != 154U)
#   error "Enumeration constant <FLTINJ_ASSTEOTLIMIT_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD (154U)
#  define FLTINJ_ASSTEOTLIMIT_LMTCOD (154U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND) || (defined FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND != 155U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155U)
#  define FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155U)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTORQUE) || (defined FLTINJ_ANAHWTORQUE)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTORQUE) || (RTE_CONST_FLTINJ_ANAHWTORQUE != 156U)
#   error "Enumeration constant <FLTINJ_ANAHWTORQUE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTORQUE (156U)
#  define FLTINJ_ANAHWTORQUE (156U)
# endif
# if (defined RTE_CONST_FLTINJ_MTRVEL) || (defined FLTINJ_MTRVEL)
#  if (!defined RTE_CONST_FLTINJ_MTRVEL) || (RTE_CONST_FLTINJ_MTRVEL != 160U)
#   error "Enumeration constant <FLTINJ_MTRVEL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_MTRVEL (160U)
#  define FLTINJ_MTRVEL (160U)
# endif
# if (defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD) || (defined FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD)
#  if (!defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD) || (RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD != 200U)
#   error "Enumeration constant <FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200U)
#  define FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200U)
# endif
# if (defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR) || (defined FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR)
#  if (!defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR) || (RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR != 201U)
#   error "Enumeration constant <FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201U)
#  define FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201U)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ) || (defined FLTINJ_GCCDIAG_MTRTRQ)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ) || (RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ != 246U)
#   error "Enumeration constant <FLTINJ_GCCDIAG_MTRTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ (246U)
#  define FLTINJ_GCCDIAG_MTRTRQ (246U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND) || (defined FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND != 255U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255U)
#  define FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255U)
# endif

# define Rte_TypeDef_HwTrqStatusType
typedef uint8 HwTrqStatusType;
# define HwTrqStatusType_LowerLimit (0U)
# define HwTrqStatusType_UpperLimit (2U)
# if (defined RTE_CONST_HWTRQSTATUS_NONE) || (defined HWTRQSTATUS_NONE)
#  if (!defined RTE_CONST_HWTRQSTATUS_NONE) || (RTE_CONST_HWTRQSTATUS_NONE != 0U)
#   error "Enumeration constant <HWTRQSTATUS_NONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_HWTRQSTATUS_NONE (0U)
#  define HWTRQSTATUS_NONE (0U)
# endif
# if (defined RTE_CONST_HWTRQSTATUS_ACTIVE) || (defined HWTRQSTATUS_ACTIVE)
#  if (!defined RTE_CONST_HWTRQSTATUS_ACTIVE) || (RTE_CONST_HWTRQSTATUS_ACTIVE != 1U)
#   error "Enumeration constant <HWTRQSTATUS_ACTIVE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_HWTRQSTATUS_ACTIVE (1U)
#  define HWTRQSTATUS_ACTIVE (1U)
# endif
# if (defined RTE_CONST_HWTRQSTATUS_FAULT) || (defined HWTRQSTATUS_FAULT)
#  if (!defined RTE_CONST_HWTRQSTATUS_FAULT) || (RTE_CONST_HWTRQSTATUS_FAULT != 2U)
#   error "Enumeration constant <HWTRQSTATUS_FAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_HWTRQSTATUS_FAULT (2U)
#  define HWTRQSTATUS_FAULT (2U)
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

# define Rte_TypeDef_ID_FN_INQY
typedef uint16 ID_FN_INQY;
# define ID_FN_INQY_LowerLimit (0U)
# define ID_FN_INQY_UpperLimit (65535U)
# define Rte_InvalidValue_ID_FN_INQY (65535U)
# define InvalidValue_ID_FN_INQY (65535U)
# if (defined RTE_CONST_Cx03EB_Grenzwerte_Schwenk_Links) || (defined Cx03EB_Grenzwerte_Schwenk_Links)
#  if (!defined RTE_CONST_Cx03EB_Grenzwerte_Schwenk_Links) || (RTE_CONST_Cx03EB_Grenzwerte_Schwenk_Links != 1003U)
#   error "Enumeration constant <Cx03EB_Grenzwerte_Schwenk_Links> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03EB_Grenzwerte_Schwenk_Links (1003U)
#  define Cx03EB_Grenzwerte_Schwenk_Links (1003U)
# endif
# if (defined RTE_CONST_Cx03EC_Grenzwerte_Schwenk_Rechts) || (defined Cx03EC_Grenzwerte_Schwenk_Rechts)
#  if (!defined RTE_CONST_Cx03EC_Grenzwerte_Schwenk_Rechts) || (RTE_CONST_Cx03EC_Grenzwerte_Schwenk_Rechts != 1004U)
#   error "Enumeration constant <Cx03EC_Grenzwerte_Schwenk_Rechts> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03EC_Grenzwerte_Schwenk_Rechts (1004U)
#  define Cx03EC_Grenzwerte_Schwenk_Rechts (1004U)
# endif
# if (defined RTE_CONST_Cx03F1_Status_Licht_Erweitert_CKM) || (defined Cx03F1_Status_Licht_Erweitert_CKM)
#  if (!defined RTE_CONST_Cx03F1_Status_Licht_Erweitert_CKM) || (RTE_CONST_Cx03F1_Status_Licht_Erweitert_CKM != 1009U)
#   error "Enumeration constant <Cx03F1_Status_Licht_Erweitert_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03F1_Status_Licht_Erweitert_CKM (1009U)
#  define Cx03F1_Status_Licht_Erweitert_CKM (1009U)
# endif
# if (defined RTE_CONST_Cx03F5_Status_Laderaumabdeckung_CKM) || (defined Cx03F5_Status_Laderaumabdeckung_CKM)
#  if (!defined RTE_CONST_Cx03F5_Status_Laderaumabdeckung_CKM) || (RTE_CONST_Cx03F5_Status_Laderaumabdeckung_CKM != 1013U)
#   error "Enumeration constant <Cx03F5_Status_Laderaumabdeckung_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03F5_Status_Laderaumabdeckung_CKM (1013U)
#  define Cx03F5_Status_Laderaumabdeckung_CKM (1013U)
# endif
# if (defined RTE_CONST_Cx0424_Status_Konfiguration_Kombi) || (defined Cx0424_Status_Konfiguration_Kombi)
#  if (!defined RTE_CONST_Cx0424_Status_Konfiguration_Kombi) || (RTE_CONST_Cx0424_Status_Konfiguration_Kombi != 1060U)
#   error "Enumeration constant <Cx0424_Status_Konfiguration_Kombi> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0424_Status_Konfiguration_Kombi (1060U)
#  define Cx0424_Status_Konfiguration_Kombi (1060U)
# endif
# if (defined RTE_CONST_Cx0427_Konfiguration_DSC) || (defined Cx0427_Konfiguration_DSC)
#  if (!defined RTE_CONST_Cx0427_Konfiguration_DSC) || (RTE_CONST_Cx0427_Konfiguration_DSC != 1063U)
#   error "Enumeration constant <Cx0427_Konfiguration_DSC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0427_Konfiguration_DSC (1063U)
#  define Cx0427_Konfiguration_DSC (1063U)
# endif
# if (defined RTE_CONST_Cx042E_Status_M_Drive_2) || (defined Cx042E_Status_M_Drive_2)
#  if (!defined RTE_CONST_Cx042E_Status_M_Drive_2) || (RTE_CONST_Cx042E_Status_M_Drive_2 != 1070U)
#   error "Enumeration constant <Cx042E_Status_M_Drive_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx042E_Status_M_Drive_2 (1070U)
#  define Cx042E_Status_M_Drive_2 (1070U)
# endif
# if (defined RTE_CONST_Cx0434_Konfiguration_EPS) || (defined Cx0434_Konfiguration_EPS)
#  if (!defined RTE_CONST_Cx0434_Konfiguration_EPS) || (RTE_CONST_Cx0434_Konfiguration_EPS != 1076U)
#   error "Enumeration constant <Cx0434_Konfiguration_EPS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0434_Konfiguration_EPS (1076U)
#  define Cx0434_Konfiguration_EPS (1076U)
# endif
# if (defined RTE_CONST_Cx0435_Messung_Motoroel) || (defined Cx0435_Messung_Motoroel)
#  if (!defined RTE_CONST_Cx0435_Messung_Motoroel) || (RTE_CONST_Cx0435_Messung_Motoroel != 1077U)
#   error "Enumeration constant <Cx0435_Messung_Motoroel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0435_Messung_Motoroel (1077U)
#  define Cx0435_Messung_Motoroel (1077U)
# endif
# if (defined RTE_CONST_Cx043F_Identifikationsnummer_Sensorcluster) || (defined Cx043F_Identifikationsnummer_Sensorcluster)
#  if (!defined RTE_CONST_Cx043F_Identifikationsnummer_Sensorcluster) || (RTE_CONST_Cx043F_Identifikationsnummer_Sensorcluster != 1087U)
#   error "Enumeration constant <Cx043F_Identifikationsnummer_Sensorcluster> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx043F_Identifikationsnummer_Sensorcluster (1087U)
#  define Cx043F_Identifikationsnummer_Sensorcluster (1087U)
# endif
# if (defined RTE_CONST_Cx00A1_Bedienung_Tasten_Entertainment) || (defined Cx00A1_Bedienung_Tasten_Entertainment)
#  if (!defined RTE_CONST_Cx00A1_Bedienung_Tasten_Entertainment) || (RTE_CONST_Cx00A1_Bedienung_Tasten_Entertainment != 161U)
#   error "Enumeration constant <Cx00A1_Bedienung_Tasten_Entertainment> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx00A1_Bedienung_Tasten_Entertainment (161U)
#  define Cx00A1_Bedienung_Tasten_Entertainment (161U)
# endif
# if (defined RTE_CONST_Cx00F6_Steuerung_Aussenspiegel) || (defined Cx00F6_Steuerung_Aussenspiegel)
#  if (!defined RTE_CONST_Cx00F6_Steuerung_Aussenspiegel) || (RTE_CONST_Cx00F6_Steuerung_Aussenspiegel != 246U)
#   error "Enumeration constant <Cx00F6_Steuerung_Aussenspiegel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx00F6_Steuerung_Aussenspiegel (246U)
#  define Cx00F6_Steuerung_Aussenspiegel (246U)
# endif
# if (defined RTE_CONST_Cx01AA_Effekt_ErgoCommander) || (defined Cx01AA_Effekt_ErgoCommander)
#  if (!defined RTE_CONST_Cx01AA_Effekt_ErgoCommander) || (RTE_CONST_Cx01AA_Effekt_ErgoCommander != 426U)
#   error "Enumeration constant <Cx01AA_Effekt_ErgoCommander> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx01AA_Effekt_ErgoCommander (426U)
#  define Cx01AA_Effekt_ErgoCommander (426U)
# endif
# if (defined RTE_CONST_Cx01AE_Effekt_FondCommander) || (defined Cx01AE_Effekt_FondCommander)
#  if (!defined RTE_CONST_Cx01AE_Effekt_FondCommander) || (RTE_CONST_Cx01AE_Effekt_FondCommander != 430U)
#   error "Enumeration constant <Cx01AE_Effekt_FondCommander> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx01AE_Effekt_FondCommander (430U)
#  define Cx01AE_Effekt_FondCommander (430U)
# endif
# if (defined RTE_CONST_Cx020D_Position_Lenksaeule) || (defined Cx020D_Position_Lenksaeule)
#  if (!defined RTE_CONST_Cx020D_Position_Lenksaeule) || (RTE_CONST_Cx020D_Position_Lenksaeule != 525U)
#   error "Enumeration constant <Cx020D_Position_Lenksaeule> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx020D_Position_Lenksaeule (525U)
#  define Cx020D_Position_Lenksaeule (525U)
# endif
# if (defined RTE_CONST_Cx0226_Regensensor_Wischergeschwindigkeit) || (defined Cx0226_Regensensor_Wischergeschwindigkeit)
#  if (!defined RTE_CONST_Cx0226_Regensensor_Wischergeschwindigkeit) || (RTE_CONST_Cx0226_Regensensor_Wischergeschwindigkeit != 550U)
#   error "Enumeration constant <Cx0226_Regensensor_Wischergeschwindigkeit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0226_Regensensor_Wischergeschwindigkeit (550U)
#  define Cx0226_Regensensor_Wischergeschwindigkeit (550U)
# endif
# if (defined RTE_CONST_Cx023A_Status_Funkschluessel) || (defined Cx023A_Status_Funkschluessel)
#  if (!defined RTE_CONST_Cx023A_Status_Funkschluessel) || (RTE_CONST_Cx023A_Status_Funkschluessel != 570U)
#   error "Enumeration constant <Cx023A_Status_Funkschluessel> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx023A_Status_Funkschluessel (570U)
#  define Cx023A_Status_Funkschluessel (570U)
# endif
# if (defined RTE_CONST_Cx0248_Status_Rueckfahrkamera) || (defined Cx0248_Status_Rueckfahrkamera)
#  if (!defined RTE_CONST_Cx0248_Status_Rueckfahrkamera) || (RTE_CONST_Cx0248_Status_Rueckfahrkamera != 584U)
#   error "Enumeration constant <Cx0248_Status_Rueckfahrkamera> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0248_Status_Rueckfahrkamera (584U)
#  define Cx0248_Status_Rueckfahrkamera (584U)
# endif
# if (defined RTE_CONST_Cx0252_Wischerstatus) || (defined Cx0252_Wischerstatus)
#  if (!defined RTE_CONST_Cx0252_Wischerstatus) || (RTE_CONST_Cx0252_Wischerstatus != 594U)
#   error "Enumeration constant <Cx0252_Wischerstatus> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0252_Wischerstatus (594U)
#  define Cx0252_Wischerstatus (594U)
# endif
# if (defined RTE_CONST_Cx0267_Bedienung_Tastgeber_Bedienelement_Front) || (defined Cx0267_Bedienung_Tastgeber_Bedienelement_Front)
#  if (!defined RTE_CONST_Cx0267_Bedienung_Tastgeber_Bedienelement_Front) || (RTE_CONST_Cx0267_Bedienung_Tastgeber_Bedienelement_Front != 615U)
#   error "Enumeration constant <Cx0267_Bedienung_Tastgeber_Bedienelement_Front> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0267_Bedienung_Tastgeber_Bedienelement_Front (615U)
#  define Cx0267_Bedienung_Tastgeber_Bedienelement_Front (615U)
# endif
# if (defined RTE_CONST_Cx027E_Status_Verdeck_Cabrio) || (defined Cx027E_Status_Verdeck_Cabrio)
#  if (!defined RTE_CONST_Cx027E_Status_Verdeck_Cabrio) || (RTE_CONST_Cx027E_Status_Verdeck_Cabrio != 638U)
#   error "Enumeration constant <Cx027E_Status_Verdeck_Cabrio> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx027E_Status_Verdeck_Cabrio (638U)
#  define Cx027E_Status_Verdeck_Cabrio (638U)
# endif
# if (defined RTE_CONST_CxFFFF_Signal_ungueltig) || (defined CxFFFF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxFFFF_Signal_ungueltig) || (RTE_CONST_CxFFFF_Signal_ungueltig != 65535U)
#   error "Enumeration constant <CxFFFF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFFFF_Signal_ungueltig (65535U)
#  define CxFFFF_Signal_ungueltig (65535U)
# endif
# if (defined RTE_CONST_Cx0291_Bedienung_Einheiten) || (defined Cx0291_Bedienung_Einheiten)
#  if (!defined RTE_CONST_Cx0291_Bedienung_Einheiten) || (RTE_CONST_Cx0291_Bedienung_Einheiten != 657U)
#   error "Enumeration constant <Cx0291_Bedienung_Einheiten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0291_Bedienung_Einheiten (657U)
#  define Cx0291_Bedienung_Einheiten (657U)
# endif
# if (defined RTE_CONST_Cx02E6_Status_Klima_Luftverteilung_FA) || (defined Cx02E6_Status_Klima_Luftverteilung_FA)
#  if (!defined RTE_CONST_Cx02E6_Status_Klima_Luftverteilung_FA) || (RTE_CONST_Cx02E6_Status_Klima_Luftverteilung_FA != 742U)
#   error "Enumeration constant <Cx02E6_Status_Klima_Luftverteilung_FA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02E6_Status_Klima_Luftverteilung_FA (742U)
#  define Cx02E6_Status_Klima_Luftverteilung_FA (742U)
# endif
# if (defined RTE_CONST_Cx02EA_Status_Klima_Luftverteilung_BF) || (defined Cx02EA_Status_Klima_Luftverteilung_BF)
#  if (!defined RTE_CONST_Cx02EA_Status_Klima_Luftverteilung_BF) || (RTE_CONST_Cx02EA_Status_Klima_Luftverteilung_BF != 746U)
#   error "Enumeration constant <Cx02EA_Status_Klima_Luftverteilung_BF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02EA_Status_Klima_Luftverteilung_BF (746U)
#  define Cx02EA_Status_Klima_Luftverteilung_BF (746U)
# endif
# if (defined RTE_CONST_Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe) || (defined Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe)
#  if (!defined RTE_CONST_Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe) || (RTE_CONST_Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe != 748U)
#   error "Enumeration constant <Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe (748U)
#  define Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe (748U)
# endif
# if (defined RTE_CONST_Cx02EE_Status_Klima_Zusatzprogramme) || (defined Cx02EE_Status_Klima_Zusatzprogramme)
#  if (!defined RTE_CONST_Cx02EE_Status_Klima_Zusatzprogramme) || (RTE_CONST_Cx02EE_Status_Klima_Zusatzprogramme != 750U)
#   error "Enumeration constant <Cx02EE_Status_Klima_Zusatzprogramme> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02EE_Status_Klima_Zusatzprogramme (750U)
#  define Cx02EE_Status_Klima_Zusatzprogramme (750U)
# endif
# if (defined RTE_CONST_Cx02F0_Status_Klima_Standfunktionen) || (defined Cx02F0_Status_Klima_Standfunktionen)
#  if (!defined RTE_CONST_Cx02F0_Status_Klima_Standfunktionen) || (RTE_CONST_Cx02F0_Status_Klima_Standfunktionen != 752U)
#   error "Enumeration constant <Cx02F0_Status_Klima_Standfunktionen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02F0_Status_Klima_Standfunktionen (752U)
#  define Cx02F0_Status_Klima_Standfunktionen (752U)
# endif
# if (defined RTE_CONST_Cx02F7_Einheiten) || (defined Cx02F7_Einheiten)
#  if (!defined RTE_CONST_Cx02F7_Einheiten) || (RTE_CONST_Cx02F7_Einheiten != 759U)
#   error "Enumeration constant <Cx02F7_Einheiten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02F7_Einheiten (759U)
#  define Cx02F7_Einheiten (759U)
# endif
# if (defined RTE_CONST_Cx02F8_Uhrzeit_Datum) || (defined Cx02F8_Uhrzeit_Datum)
#  if (!defined RTE_CONST_Cx02F8_Uhrzeit_Datum) || (RTE_CONST_Cx02F8_Uhrzeit_Datum != 760U)
#   error "Enumeration constant <Cx02F8_Uhrzeit_Datum> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02F8_Uhrzeit_Datum (760U)
#  define Cx02F8_Uhrzeit_Datum (760U)
# endif
# if (defined RTE_CONST_Cx0300_Status_RSE) || (defined Cx0300_Status_RSE)
#  if (!defined RTE_CONST_Cx0300_Status_RSE) || (RTE_CONST_Cx0300_Status_RSE != 768U)
#   error "Enumeration constant <Cx0300_Status_RSE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0300_Status_RSE (768U)
#  define Cx0300_Status_RSE (768U)
# endif
# if (defined RTE_CONST_Cx030F_Status_Service_Call_TeleX) || (defined Cx030F_Status_Service_Call_TeleX)
#  if (!defined RTE_CONST_Cx030F_Status_Service_Call_TeleX) || (RTE_CONST_Cx030F_Status_Service_Call_TeleX != 783U)
#   error "Enumeration constant <Cx030F_Status_Service_Call_TeleX> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx030F_Status_Service_Call_TeleX (783U)
#  define Cx030F_Status_Service_Call_TeleX (783U)
# endif
# if (defined RTE_CONST_Cx0313_Status_Service_Call_Teleservice) || (defined Cx0313_Status_Service_Call_Teleservice)
#  if (!defined RTE_CONST_Cx0313_Status_Service_Call_Teleservice) || (RTE_CONST_Cx0313_Status_Service_Call_Teleservice != 787U)
#   error "Enumeration constant <Cx0313_Status_Service_Call_Teleservice> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0313_Status_Service_Call_Teleservice (787U)
#  define Cx0313_Status_Service_Call_Teleservice (787U)
# endif
# if (defined RTE_CONST_Cx0332_Verbrauch_Information_Daten) || (defined Cx0332_Verbrauch_Information_Daten)
#  if (!defined RTE_CONST_Cx0332_Verbrauch_Information_Daten) || (RTE_CONST_Cx0332_Verbrauch_Information_Daten != 818U)
#   error "Enumeration constant <Cx0332_Verbrauch_Information_Daten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0332_Verbrauch_Information_Daten (818U)
#  define Cx0332_Verbrauch_Information_Daten (818U)
# endif
# if (defined RTE_CONST_Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_) || (defined Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_)
#  if (!defined RTE_CONST_Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_) || (RTE_CONST_Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_ != 822U)
#   error "Enumeration constant <Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_ (822U)
#  define Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_ (822U)
# endif
# if (defined RTE_CONST_Cx033A_Status_Monitor_Front) || (defined Cx033A_Status_Monitor_Front)
#  if (!defined RTE_CONST_Cx033A_Status_Monitor_Front) || (RTE_CONST_Cx033A_Status_Monitor_Front != 826U)
#   error "Enumeration constant <Cx033A_Status_Monitor_Front> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx033A_Status_Monitor_Front (826U)
#  define Cx033A_Status_Monitor_Front (826U)
# endif
# if (defined RTE_CONST_Cx033C_Status_Monitor_Fond_1) || (defined Cx033C_Status_Monitor_Fond_1)
#  if (!defined RTE_CONST_Cx033C_Status_Monitor_Fond_1) || (RTE_CONST_Cx033C_Status_Monitor_Fond_1 != 828U)
#   error "Enumeration constant <Cx033C_Status_Monitor_Fond_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx033C_Status_Monitor_Fond_1 (828U)
#  define Cx033C_Status_Monitor_Fond_1 (828U)
# endif
# if (defined RTE_CONST_Cx033E_Status_Monitor_Fond_2) || (defined Cx033E_Status_Monitor_Fond_2)
#  if (!defined RTE_CONST_Cx033E_Status_Monitor_Fond_2) || (RTE_CONST_Cx033E_Status_Monitor_Fond_2 != 830U)
#   error "Enumeration constant <Cx033E_Status_Monitor_Fond_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx033E_Status_Monitor_Fond_2 (830U)
#  define Cx033E_Status_Monitor_Fond_2 (830U)
# endif
# if (defined RTE_CONST_Cx0341_Status_Kartendaten) || (defined Cx0341_Status_Kartendaten)
#  if (!defined RTE_CONST_Cx0341_Status_Kartendaten) || (RTE_CONST_Cx0341_Status_Kartendaten != 833U)
#   error "Enumeration constant <Cx0341_Status_Kartendaten> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0341_Status_Kartendaten (833U)
#  define Cx0341_Status_Kartendaten (833U)
# endif
# if (defined RTE_CONST_Cx0349_Rohdaten_Fuellstand_Tank) || (defined Cx0349_Rohdaten_Fuellstand_Tank)
#  if (!defined RTE_CONST_Cx0349_Rohdaten_Fuellstand_Tank) || (RTE_CONST_Cx0349_Rohdaten_Fuellstand_Tank != 841U)
#   error "Enumeration constant <Cx0349_Rohdaten_Fuellstand_Tank> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0349_Rohdaten_Fuellstand_Tank (841U)
#  define Cx0349_Rohdaten_Fuellstand_Tank (841U)
# endif
# if (defined RTE_CONST_Cx035C_Status_Bordcomputer) || (defined Cx035C_Status_Bordcomputer)
#  if (!defined RTE_CONST_Cx035C_Status_Bordcomputer) || (RTE_CONST_Cx035C_Status_Bordcomputer != 860U)
#   error "Enumeration constant <Cx035C_Status_Bordcomputer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx035C_Status_Bordcomputer (860U)
#  define Cx035C_Status_Bordcomputer (860U)
# endif
# if (defined RTE_CONST_Cx0360_Daten_Bordcomputer__Fahrtbeginn_) || (defined Cx0360_Daten_Bordcomputer__Fahrtbeginn_)
#  if (!defined RTE_CONST_Cx0360_Daten_Bordcomputer__Fahrtbeginn_) || (RTE_CONST_Cx0360_Daten_Bordcomputer__Fahrtbeginn_ != 864U)
#   error "Enumeration constant <Cx0360_Daten_Bordcomputer__Fahrtbeginn_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0360_Daten_Bordcomputer__Fahrtbeginn_ (864U)
#  define Cx0360_Daten_Bordcomputer__Fahrtbeginn_ (864U)
# endif
# if (defined RTE_CONST_Cx0380_Fahrgestellnummer) || (defined Cx0380_Fahrgestellnummer)
#  if (!defined RTE_CONST_Cx0380_Fahrgestellnummer) || (RTE_CONST_Cx0380_Fahrgestellnummer != 896U)
#   error "Enumeration constant <Cx0380_Fahrgestellnummer> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0380_Fahrgestellnummer (896U)
#  define Cx0380_Fahrgestellnummer (896U)
# endif
# if (defined RTE_CONST_Cx0381_Elektronischer_Motoroelmessstab) || (defined Cx0381_Elektronischer_Motoroelmessstab)
#  if (!defined RTE_CONST_Cx0381_Elektronischer_Motoroelmessstab) || (RTE_CONST_Cx0381_Elektronischer_Motoroelmessstab != 897U)
#   error "Enumeration constant <Cx0381_Elektronischer_Motoroelmessstab> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0381_Elektronischer_Motoroelmessstab (897U)
#  define Cx0381_Elektronischer_Motoroelmessstab (897U)
# endif
# if (defined RTE_CONST_Cx0382_Elektronischer_Motoroelmessstab_M) || (defined Cx0382_Elektronischer_Motoroelmessstab_M)
#  if (!defined RTE_CONST_Cx0382_Elektronischer_Motoroelmessstab_M) || (RTE_CONST_Cx0382_Elektronischer_Motoroelmessstab_M != 898U)
#   error "Enumeration constant <Cx0382_Elektronischer_Motoroelmessstab_M> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0382_Elektronischer_Motoroelmessstab_M (898U)
#  define Cx0382_Elektronischer_Motoroelmessstab_M (898U)
# endif
# if (defined RTE_CONST_Cx0388_Fahrzeugtyp) || (defined Cx0388_Fahrzeugtyp)
#  if (!defined RTE_CONST_Cx0388_Fahrzeugtyp) || (RTE_CONST_Cx0388_Fahrzeugtyp != 904U)
#   error "Enumeration constant <Cx0388_Fahrzeugtyp> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0388_Fahrzeugtyp (904U)
#  define Cx0388_Fahrzeugtyp (904U)
# endif
# if (defined RTE_CONST_Cx038E_Startdrehzahl) || (defined Cx038E_Startdrehzahl)
#  if (!defined RTE_CONST_Cx038E_Startdrehzahl) || (RTE_CONST_Cx038E_Startdrehzahl != 910U)
#   error "Enumeration constant <Cx038E_Startdrehzahl> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx038E_Startdrehzahl (910U)
#  define Cx038E_Startdrehzahl (910U)
# endif
# if (defined RTE_CONST_Cx0395_Codierung_Powermanagement) || (defined Cx0395_Codierung_Powermanagement)
#  if (!defined RTE_CONST_Cx0395_Codierung_Powermanagement) || (RTE_CONST_Cx0395_Codierung_Powermanagement != 917U)
#   error "Enumeration constant <Cx0395_Codierung_Powermanagement> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0395_Codierung_Powermanagement (917U)
#  define Cx0395_Codierung_Powermanagement (917U)
# endif
# if (defined RTE_CONST_Cx0399_Status_M_Drive) || (defined Cx0399_Status_M_Drive)
#  if (!defined RTE_CONST_Cx0399_Status_M_Drive) || (RTE_CONST_Cx0399_Status_M_Drive != 921U)
#   error "Enumeration constant <Cx0399_Status_M_Drive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0399_Status_M_Drive (921U)
#  define Cx0399_Status_M_Drive (921U)
# endif
# if (defined RTE_CONST_Cx03A9_Status_Motorsteuerung_CKM) || (defined Cx03A9_Status_Motorsteuerung_CKM)
#  if (!defined RTE_CONST_Cx03A9_Status_Motorsteuerung_CKM) || (RTE_CONST_Cx03A9_Status_Motorsteuerung_CKM != 937U)
#   error "Enumeration constant <Cx03A9_Status_Motorsteuerung_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03A9_Status_Motorsteuerung_CKM (937U)
#  define Cx03A9_Status_Motorsteuerung_CKM (937U)
# endif
# if (defined RTE_CONST_Cx03AB_Status_Shiftlights_CKM) || (defined Cx03AB_Status_Shiftlights_CKM)
#  if (!defined RTE_CONST_Cx03AB_Status_Shiftlights_CKM) || (RTE_CONST_Cx03AB_Status_Shiftlights_CKM != 939U)
#   error "Enumeration constant <Cx03AB_Status_Shiftlights_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03AB_Status_Shiftlights_CKM (939U)
#  define Cx03AB_Status_Shiftlights_CKM (939U)
# endif
# if (defined RTE_CONST_Cx03B6_Position_Fensterheber_FAT) || (defined Cx03B6_Position_Fensterheber_FAT)
#  if (!defined RTE_CONST_Cx03B6_Position_Fensterheber_FAT) || (RTE_CONST_Cx03B6_Position_Fensterheber_FAT != 950U)
#   error "Enumeration constant <Cx03B6_Position_Fensterheber_FAT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03B6_Position_Fensterheber_FAT (950U)
#  define Cx03B6_Position_Fensterheber_FAT (950U)
# endif
# if (defined RTE_CONST_Cx03B7_Position_Fensterheber_FATH) || (defined Cx03B7_Position_Fensterheber_FATH)
#  if (!defined RTE_CONST_Cx03B7_Position_Fensterheber_FATH) || (RTE_CONST_Cx03B7_Position_Fensterheber_FATH != 951U)
#   error "Enumeration constant <Cx03B7_Position_Fensterheber_FATH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03B7_Position_Fensterheber_FATH (951U)
#  define Cx03B7_Position_Fensterheber_FATH (951U)
# endif
# if (defined RTE_CONST_Cx03B8_Position_Fensterheber_BFT) || (defined Cx03B8_Position_Fensterheber_BFT)
#  if (!defined RTE_CONST_Cx03B8_Position_Fensterheber_BFT) || (RTE_CONST_Cx03B8_Position_Fensterheber_BFT != 952U)
#   error "Enumeration constant <Cx03B8_Position_Fensterheber_BFT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03B8_Position_Fensterheber_BFT (952U)
#  define Cx03B8_Position_Fensterheber_BFT (952U)
# endif
# if (defined RTE_CONST_Cx03B9_Position_Fensterheber_BFTH) || (defined Cx03B9_Position_Fensterheber_BFTH)
#  if (!defined RTE_CONST_Cx03B9_Position_Fensterheber_BFTH) || (RTE_CONST_Cx03B9_Position_Fensterheber_BFTH != 953U)
#   error "Enumeration constant <Cx03B9_Position_Fensterheber_BFTH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03B9_Position_Fensterheber_BFTH (953U)
#  define Cx03B9_Position_Fensterheber_BFTH (953U)
# endif
# if (defined RTE_CONST_Cx03BA_Position_SHD) || (defined Cx03BA_Position_SHD)
#  if (!defined RTE_CONST_Cx03BA_Position_SHD) || (RTE_CONST_Cx03BA_Position_SHD != 954U)
#   error "Enumeration constant <Cx03BA_Position_SHD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03BA_Position_SHD (954U)
#  define Cx03BA_Position_SHD (954U)
# endif
# if (defined RTE_CONST_Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug) || (defined Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug)
#  if (!defined RTE_CONST_Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug) || (RTE_CONST_Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug != 956U)
#   error "Enumeration constant <Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug (956U)
#  define Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug (956U)
# endif
# if (defined RTE_CONST_Cx03BF_Position_Fensterheber_Heckscheibe) || (defined Cx03BF_Position_Fensterheber_Heckscheibe)
#  if (!defined RTE_CONST_Cx03BF_Position_Fensterheber_Heckscheibe) || (RTE_CONST_Cx03BF_Position_Fensterheber_Heckscheibe != 959U)
#   error "Enumeration constant <Cx03BF_Position_Fensterheber_Heckscheibe> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03BF_Position_Fensterheber_Heckscheibe (959U)
#  define Cx03BF_Position_Fensterheber_Heckscheibe (959U)
# endif
# if (defined RTE_CONST_Cx03C0_Konfiguration_FAS) || (defined Cx03C0_Konfiguration_FAS)
#  if (!defined RTE_CONST_Cx03C0_Konfiguration_FAS) || (RTE_CONST_Cx03C0_Konfiguration_FAS != 960U)
#   error "Enumeration constant <Cx03C0_Konfiguration_FAS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03C0_Konfiguration_FAS (960U)
#  define Cx03C0_Konfiguration_FAS (960U)
# endif
# if (defined RTE_CONST_Cx03C1_Konfiguration_BFS) || (defined Cx03C1_Konfiguration_BFS)
#  if (!defined RTE_CONST_Cx03C1_Konfiguration_BFS) || (RTE_CONST_Cx03C1_Konfiguration_BFS != 961U)
#   error "Enumeration constant <Cx03C1_Konfiguration_BFS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03C1_Konfiguration_BFS (961U)
#  define Cx03C1_Konfiguration_BFS (961U)
# endif
# if (defined RTE_CONST_Cx03C2_Konfiguration_FASH) || (defined Cx03C2_Konfiguration_FASH)
#  if (!defined RTE_CONST_Cx03C2_Konfiguration_FASH) || (RTE_CONST_Cx03C2_Konfiguration_FASH != 962U)
#   error "Enumeration constant <Cx03C2_Konfiguration_FASH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03C2_Konfiguration_FASH (962U)
#  define Cx03C2_Konfiguration_FASH (962U)
# endif
# if (defined RTE_CONST_Cx03C3_Konfiguration_BFSH) || (defined Cx03C3_Konfiguration_BFSH)
#  if (!defined RTE_CONST_Cx03C3_Konfiguration_BFSH) || (RTE_CONST_Cx03C3_Konfiguration_BFSH != 963U)
#   error "Enumeration constant <Cx03C3_Konfiguration_BFSH> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03C3_Konfiguration_BFSH (963U)
#  define Cx03C3_Konfiguration_BFSH (963U)
# endif
# if (defined RTE_CONST_Cx03C4_Status_EDCK_CKM) || (defined Cx03C4_Status_EDCK_CKM)
#  if (!defined RTE_CONST_Cx03C4_Status_EDCK_CKM) || (RTE_CONST_Cx03C4_Status_EDCK_CKM != 964U)
#   error "Enumeration constant <Cx03C4_Status_EDCK_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03C4_Status_EDCK_CKM (964U)
#  define Cx03C4_Status_EDCK_CKM (964U)
# endif
# if (defined RTE_CONST_Cx03D0_Status_Spurverlassenswarnsystem_CKM) || (defined Cx03D0_Status_Spurverlassenswarnsystem_CKM)
#  if (!defined RTE_CONST_Cx03D0_Status_Spurverlassenswarnsystem_CKM) || (RTE_CONST_Cx03D0_Status_Spurverlassenswarnsystem_CKM != 976U)
#   error "Enumeration constant <Cx03D0_Status_Spurverlassenswarnsystem_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03D0_Status_Spurverlassenswarnsystem_CKM (976U)
#  define Cx03D0_Status_Spurverlassenswarnsystem_CKM (976U)
# endif
# if (defined RTE_CONST_Cx03D5_Status_Zentralverriegelung_CKM) || (defined Cx03D5_Status_Zentralverriegelung_CKM)
#  if (!defined RTE_CONST_Cx03D5_Status_Zentralverriegelung_CKM) || (RTE_CONST_Cx03D5_Status_Zentralverriegelung_CKM != 981U)
#   error "Enumeration constant <Cx03D5_Status_Zentralverriegelung_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03D5_Status_Zentralverriegelung_CKM (981U)
#  define Cx03D5_Status_Zentralverriegelung_CKM (981U)
# endif
# if (defined RTE_CONST_Cx03D7_Status_DWA_CKM) || (defined Cx03D7_Status_DWA_CKM)
#  if (!defined RTE_CONST_Cx03D7_Status_DWA_CKM) || (RTE_CONST_Cx03D7_Status_DWA_CKM != 983U)
#   error "Enumeration constant <Cx03D7_Status_DWA_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03D7_Status_DWA_CKM (983U)
#  define Cx03D7_Status_DWA_CKM (983U)
# endif
# if (defined RTE_CONST_Cx03D9_Status_RLS_CKM) || (defined Cx03D9_Status_RLS_CKM)
#  if (!defined RTE_CONST_Cx03D9_Status_RLS_CKM) || (RTE_CONST_Cx03D9_Status_RLS_CKM != 985U)
#   error "Enumeration constant <Cx03D9_Status_RLS_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03D9_Status_RLS_CKM (985U)
#  define Cx03D9_Status_RLS_CKM (985U)
# endif
# if (defined RTE_CONST_Cx03DB_Status_Memorypositionen_CKM) || (defined Cx03DB_Status_Memorypositionen_CKM)
#  if (!defined RTE_CONST_Cx03DB_Status_Memorypositionen_CKM) || (RTE_CONST_Cx03DB_Status_Memorypositionen_CKM != 987U)
#   error "Enumeration constant <Cx03DB_Status_Memorypositionen_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03DB_Status_Memorypositionen_CKM (987U)
#  define Cx03DB_Status_Memorypositionen_CKM (987U)
# endif
# if (defined RTE_CONST_Cx03DD_Status_Licht_CKM) || (defined Cx03DD_Status_Licht_CKM)
#  if (!defined RTE_CONST_Cx03DD_Status_Licht_CKM) || (RTE_CONST_Cx03DD_Status_Licht_CKM != 989U)
#   error "Enumeration constant <Cx03DD_Status_Licht_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03DD_Status_Licht_CKM (989U)
#  define Cx03DD_Status_Licht_CKM (989U)
# endif
# if (defined RTE_CONST_Cx03DF_Status_Klima_CKM) || (defined Cx03DF_Status_Klima_CKM)
#  if (!defined RTE_CONST_Cx03DF_Status_Klima_CKM) || (RTE_CONST_Cx03DF_Status_Klima_CKM != 991U)
#   error "Enumeration constant <Cx03DF_Status_Klima_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03DF_Status_Klima_CKM (991U)
#  define Cx03DF_Status_Klima_CKM (991U)
# endif
# if (defined RTE_CONST_Cx03E1_Status_ALC_CKM) || (defined Cx03E1_Status_ALC_CKM)
#  if (!defined RTE_CONST_Cx03E1_Status_ALC_CKM) || (RTE_CONST_Cx03E1_Status_ALC_CKM != 993U)
#   error "Enumeration constant <Cx03E1_Status_ALC_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03E1_Status_ALC_CKM (993U)
#  define Cx03E1_Status_ALC_CKM (993U)
# endif
# if (defined RTE_CONST_Cx03E3_Status_Heckklappe_CKM) || (defined Cx03E3_Status_Heckklappe_CKM)
#  if (!defined RTE_CONST_Cx03E3_Status_Heckklappe_CKM) || (RTE_CONST_Cx03E3_Status_Heckklappe_CKM != 995U)
#   error "Enumeration constant <Cx03E3_Status_Heckklappe_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03E3_Status_Heckklappe_CKM (995U)
#  define Cx03E3_Status_Heckklappe_CKM (995U)
# endif
# if (defined RTE_CONST_Cx03E5_Status_Rueckfahrkamera_CKM) || (defined Cx03E5_Status_Rueckfahrkamera_CKM)
#  if (!defined RTE_CONST_Cx03E5_Status_Rueckfahrkamera_CKM) || (RTE_CONST_Cx03E5_Status_Rueckfahrkamera_CKM != 997U)
#   error "Enumeration constant <Cx03E5_Status_Rueckfahrkamera_CKM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03E5_Status_Rueckfahrkamera_CKM (997U)
#  define Cx03E5_Status_Rueckfahrkamera_CKM (997U)
# endif

# define Rte_TypeDef_ID_TEMP_CPO_HET_MNG
typedef uint8 ID_TEMP_CPO_HET_MNG;
# define ID_TEMP_CPO_HET_MNG_LowerLimit (0U)
# define ID_TEMP_CPO_HET_MNG_UpperLimit (15U)
# define Rte_InvalidValue_ID_TEMP_CPO_HET_MNG (15U)
# define InvalidValue_ID_TEMP_CPO_HET_MNG (15U)
# if (defined RTE_CONST_Cx1_EPS_Motortemperatur) || (defined Cx1_EPS_Motortemperatur)
#  if (!defined RTE_CONST_Cx1_EPS_Motortemperatur) || (RTE_CONST_Cx1_EPS_Motortemperatur != 1U)
#   error "Enumeration constant <Cx1_EPS_Motortemperatur> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_EPS_Motortemperatur (1U)
#  define Cx1_EPS_Motortemperatur (1U)
# endif
# if (defined RTE_CONST_CxD_Reserviert) || (defined CxD_Reserviert)
#  if (!defined RTE_CONST_CxD_Reserviert) || (RTE_CONST_CxD_Reserviert != 13U)
#   error "Enumeration constant <CxD_Reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_Reserviert (13U)
#  define CxD_Reserviert (13U)
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

# define Rte_TypeDef_ImcArbrRxSts_enum
typedef uint8 ImcArbrRxSts_enum;
# define ImcArbrRxSts_enum_LowerLimit (0U)
# define ImcArbrRxSts_enum_UpperLimit (2U)
# if (defined RTE_CONST_IMCARBRRXSTS_NODATA) || (defined IMCARBRRXSTS_NODATA)
#  if (!defined RTE_CONST_IMCARBRRXSTS_NODATA) || (RTE_CONST_IMCARBRRXSTS_NODATA != 0U)
#   error "Enumeration constant <IMCARBRRXSTS_NODATA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_IMCARBRRXSTS_NODATA (0U)
#  define IMCARBRRXSTS_NODATA (0U)
# endif
# if (defined RTE_CONST_IMCARBRRXSTS_VALID) || (defined IMCARBRRXSTS_VALID)
#  if (!defined RTE_CONST_IMCARBRRXSTS_VALID) || (RTE_CONST_IMCARBRRXSTS_VALID != 1U)
#   error "Enumeration constant <IMCARBRRXSTS_VALID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_IMCARBRRXSTS_VALID (1U)
#  define IMCARBRRXSTS_VALID (1U)
# endif
# if (defined RTE_CONST_IMCARBRRXSTS_INVALID) || (defined IMCARBRRXSTS_INVALID)
#  if (!defined RTE_CONST_IMCARBRRXSTS_INVALID) || (RTE_CONST_IMCARBRRXSTS_INVALID != 2U)
#   error "Enumeration constant <IMCARBRRXSTS_INVALID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_IMCARBRRXSTS_INVALID (2U)
#  define IMCARBRRXSTS_INVALID (2U)
# endif

# define Rte_TypeDef_LOA_State_enum
typedef uint8 LOA_State_enum;
# define LOA_State_enum_LowerLimit (0U)
# define LOA_State_enum_UpperLimit (5U)
# if (defined RTE_CONST_LOAST_NORM) || (defined LOAST_NORM)
#  if (!defined RTE_CONST_LOAST_NORM) || (RTE_CONST_LOAST_NORM != 0U)
#   error "Enumeration constant <LOAST_NORM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_NORM (0U)
#  define LOAST_NORM (0U)
# endif
# if (defined RTE_CONST_LOAST_REDCD) || (defined LOAST_REDCD)
#  if (!defined RTE_CONST_LOAST_REDCD) || (RTE_CONST_LOAST_REDCD != 1U)
#   error "Enumeration constant <LOAST_REDCD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_REDCD (1U)
#  define LOAST_REDCD (1U)
# endif
# if (defined RTE_CONST_LOAST_SWBASDMTGTN) || (defined LOAST_SWBASDMTGTN)
#  if (!defined RTE_CONST_LOAST_SWBASDMTGTN) || (RTE_CONST_LOAST_SWBASDMTGTN != 2U)
#   error "Enumeration constant <LOAST_SWBASDMTGTN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_SWBASDMTGTN (2U)
#  define LOAST_SWBASDMTGTN (2U)
# endif
# if (defined RTE_CONST_LOAST_FADEOUT) || (defined LOAST_FADEOUT)
#  if (!defined RTE_CONST_LOAST_FADEOUT) || (RTE_CONST_LOAST_FADEOUT != 3U)
#   error "Enumeration constant <LOAST_FADEOUT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_FADEOUT (3U)
#  define LOAST_FADEOUT (3U)
# endif
# if (defined RTE_CONST_LOAST_CTRLDSHTDWNREQD) || (defined LOAST_CTRLDSHTDWNREQD)
#  if (!defined RTE_CONST_LOAST_CTRLDSHTDWNREQD) || (RTE_CONST_LOAST_CTRLDSHTDWNREQD != 4U)
#   error "Enumeration constant <LOAST_CTRLDSHTDWNREQD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_CTRLDSHTDWNREQD (4U)
#  define LOAST_CTRLDSHTDWNREQD (4U)
# endif
# if (defined RTE_CONST_LOAST_RPDSHTDWNREQD) || (defined LOAST_RPDSHTDWNREQD)
#  if (!defined RTE_CONST_LOAST_RPDSHTDWNREQD) || (RTE_CONST_LOAST_RPDSHTDWNREQD != 5U)
#   error "Enumeration constant <LOAST_RPDSHTDWNREQD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_LOAST_RPDSHTDWNREQD (5U)
#  define LOAST_RPDSHTDWNREQD (5U)
# endif

# define Rte_TypeDef_LdwSt_State_enum
typedef uint8 LdwSt_State_enum;
# define LdwSt_State_enum_LowerLimit (0U)
# define LdwSt_State_enum_UpperLimit (3U)
# if (defined RTE_CONST_CALDWST_HAPTCRDY) || (defined CALDWST_HAPTCRDY)
#  if (!defined RTE_CONST_CALDWST_HAPTCRDY) || (RTE_CONST_CALDWST_HAPTCRDY != 0U)
#   error "Enumeration constant <CALDWST_HAPTCRDY> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALDWST_HAPTCRDY (0U)
#  define CALDWST_HAPTCRDY (0U)
# endif
# if (defined RTE_CONST_CALDWST_HAPTCACTV) || (defined CALDWST_HAPTCACTV)
#  if (!defined RTE_CONST_CALDWST_HAPTCACTV) || (RTE_CONST_CALDWST_HAPTCACTV != 1U)
#   error "Enumeration constant <CALDWST_HAPTCACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALDWST_HAPTCACTV (1U)
#  define CALDWST_HAPTCACTV (1U)
# endif
# if (defined RTE_CONST_CALDWST_TMPLIMD) || (defined CALDWST_TMPLIMD)
#  if (!defined RTE_CONST_CALDWST_TMPLIMD) || (RTE_CONST_CALDWST_TMPLIMD != 2U)
#   error "Enumeration constant <CALDWST_TMPLIMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALDWST_TMPLIMD (2U)
#  define CALDWST_TMPLIMD (2U)
# endif
# if (defined RTE_CONST_CALDWST_DI) || (defined CALDWST_DI)
#  if (!defined RTE_CONST_CALDWST_DI) || (RTE_CONST_CALDWST_DI != 3U)
#   error "Enumeration constant <CALDWST_DI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALDWST_DI (3U)
#  define CALDWST_DI (3U)
# endif

# define Rte_TypeDef_LkaSt_State_enum
typedef uint8 LkaSt_State_enum;
# define LkaSt_State_enum_LowerLimit (0U)
# define LkaSt_State_enum_UpperLimit (5U)
# if (defined RTE_CONST_CALKAST_TMPLIMD) || (defined CALKAST_TMPLIMD)
#  if (!defined RTE_CONST_CALKAST_TMPLIMD) || (RTE_CONST_CALKAST_TMPLIMD != 0U)
#   error "Enumeration constant <CALKAST_TMPLIMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_TMPLIMD (0U)
#  define CALKAST_TMPLIMD (0U)
# endif
# if (defined RTE_CONST_CALKAST_INACTV) || (defined CALKAST_INACTV)
#  if (!defined RTE_CONST_CALKAST_INACTV) || (RTE_CONST_CALKAST_INACTV != 1U)
#   error "Enumeration constant <CALKAST_INACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_INACTV (1U)
#  define CALKAST_INACTV (1U)
# endif
# if (defined RTE_CONST_CALKAST_ACTV) || (defined CALKAST_ACTV)
#  if (!defined RTE_CONST_CALKAST_ACTV) || (RTE_CONST_CALKAST_ACTV != 2U)
#   error "Enumeration constant <CALKAST_ACTV> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_ACTV (2U)
#  define CALKAST_ACTV (2U)
# endif
# if (defined RTE_CONST_CALKAST_TMPFAILD) || (defined CALKAST_TMPFAILD)
#  if (!defined RTE_CONST_CALKAST_TMPFAILD) || (RTE_CONST_CALKAST_TMPFAILD != 3U)
#   error "Enumeration constant <CALKAST_TMPFAILD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_TMPFAILD (3U)
#  define CALKAST_TMPFAILD (3U)
# endif
# if (defined RTE_CONST_CALKAST_PRMNTFAILD) || (defined CALKAST_PRMNTFAILD)
#  if (!defined RTE_CONST_CALKAST_PRMNTFAILD) || (RTE_CONST_CALKAST_PRMNTFAILD != 4U)
#   error "Enumeration constant <CALKAST_PRMNTFAILD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_PRMNTFAILD (4U)
#  define CALKAST_PRMNTFAILD (4U)
# endif
# if (defined RTE_CONST_CALKAST_MFGDI) || (defined CALKAST_MFGDI)
#  if (!defined RTE_CONST_CALKAST_MFGDI) || (RTE_CONST_CALKAST_MFGDI != 5U)
#   error "Enumeration constant <CALKAST_MFGDI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CALKAST_MFGDI (5U)
#  define CALKAST_MFGDI (5U)
# endif

# define Rte_TypeDef_LktoLkStrStateType
typedef uint8 LktoLkStrStateType;
# define LktoLkStrStateType_LowerLimit (0U)
# define LktoLkStrStateType_UpperLimit (7U)
# if (defined RTE_CONST_HOLD) || (defined HOLD)
#  if (!defined RTE_CONST_HOLD) || (RTE_CONST_HOLD != 0U)
#   error "Enumeration constant <HOLD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_HOLD (0U)
#  define HOLD (0U)
# endif
# if (defined RTE_CONST_POSANGVEL) || (defined POSANGVEL)
#  if (!defined RTE_CONST_POSANGVEL) || (RTE_CONST_POSANGVEL != 1U)
#   error "Enumeration constant <POSANGVEL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_POSANGVEL (1U)
#  define POSANGVEL (1U)
# endif
# if (defined RTE_CONST_POSMTRTRQ) || (defined POSMTRTRQ)
#  if (!defined RTE_CONST_POSMTRTRQ) || (RTE_CONST_POSMTRTRQ != 2U)
#   error "Enumeration constant <POSMTRTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_POSMTRTRQ (2U)
#  define POSMTRTRQ (2U)
# endif
# if (defined RTE_CONST_NEGANGVEL) || (defined NEGANGVEL)
#  if (!defined RTE_CONST_NEGANGVEL) || (RTE_CONST_NEGANGVEL != 3U)
#   error "Enumeration constant <NEGANGVEL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NEGANGVEL (3U)
#  define NEGANGVEL (3U)
# endif
# if (defined RTE_CONST_NEGMTRTRQ) || (defined NEGMTRTRQ)
#  if (!defined RTE_CONST_NEGMTRTRQ) || (RTE_CONST_NEGMTRTRQ != 4U)
#   error "Enumeration constant <NEGMTRTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NEGMTRTRQ (4U)
#  define NEGMTRTRQ (4U)
# endif
# if (defined RTE_CONST_MOVETO) || (defined MOVETO)
#  if (!defined RTE_CONST_MOVETO) || (RTE_CONST_MOVETO != 5U)
#   error "Enumeration constant <MOVETO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_MOVETO (5U)
#  define MOVETO (5U)
# endif
# if (defined RTE_CONST_DONE) || (defined DONE)
#  if (!defined RTE_CONST_DONE) || (RTE_CONST_DONE != 6U)
#   error "Enumeration constant <DONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DONE (6U)
#  define DONE (6U)
# endif
# if (defined RTE_CONST_TIMEOUT) || (defined TIMEOUT)
#  if (!defined RTE_CONST_TIMEOUT) || (RTE_CONST_TIMEOUT != 7U)
#   error "Enumeration constant <TIMEOUT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TIMEOUT (7U)
#  define TIMEOUT (7U)
# endif

# define Rte_TypeDef_MSA_Cmd_Type
typedef uint8 MSA_Cmd_Type;
# define MSA_Cmd_Type_LowerLimit (0U)
# define MSA_Cmd_Type_UpperLimit (3U)
# if (defined RTE_CONST_MSA_STOP_ANNOUNCEMENT) || (defined MSA_STOP_ANNOUNCEMENT)
#  if (!defined RTE_CONST_MSA_STOP_ANNOUNCEMENT) || (RTE_CONST_MSA_STOP_ANNOUNCEMENT != 0U)
#   error "Enumeration constant <MSA_STOP_ANNOUNCEMENT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_MSA_STOP_ANNOUNCEMENT (0U)
#  define MSA_STOP_ANNOUNCEMENT (0U)
# endif
# if (defined RTE_CONST_MSA_STOP_COMMAND) || (defined MSA_STOP_COMMAND)
#  if (!defined RTE_CONST_MSA_STOP_COMMAND) || (RTE_CONST_MSA_STOP_COMMAND != 1U)
#   error "Enumeration constant <MSA_STOP_COMMAND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_MSA_STOP_COMMAND (1U)
#  define MSA_STOP_COMMAND (1U)
# endif
# if (defined RTE_CONST_MSA_START_ANNOUNCEMENT) || (defined MSA_START_ANNOUNCEMENT)
#  if (!defined RTE_CONST_MSA_START_ANNOUNCEMENT) || (RTE_CONST_MSA_START_ANNOUNCEMENT != 2U)
#   error "Enumeration constant <MSA_START_ANNOUNCEMENT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_MSA_START_ANNOUNCEMENT (2U)
#  define MSA_START_ANNOUNCEMENT (2U)
# endif
# if (defined RTE_CONST_MSA_ENGINE_RUN) || (defined MSA_ENGINE_RUN)
#  if (!defined RTE_CONST_MSA_ENGINE_RUN) || (RTE_CONST_MSA_ENGINE_RUN != 3U)
#   error "Enumeration constant <MSA_ENGINE_RUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_MSA_ENGINE_RUN (3U)
#  define MSA_ENGINE_RUN (3U)
# endif

# define Rte_TypeDef_ManufModeType
typedef uint8 ManufModeType;
# define ManufModeType_LowerLimit (0U)
# define ManufModeType_UpperLimit (2U)
# if (defined RTE_CONST_ProductionMode) || (defined ProductionMode)
#  if (!defined RTE_CONST_ProductionMode) || (RTE_CONST_ProductionMode != 0U)
#   error "Enumeration constant <ProductionMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ProductionMode (0U)
#  define ProductionMode (0U)
# endif
# if (defined RTE_CONST_ManufacturingMode) || (defined ManufacturingMode)
#  if (!defined RTE_CONST_ManufacturingMode) || (RTE_CONST_ManufacturingMode != 1U)
#   error "Enumeration constant <ManufacturingMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ManufacturingMode (1U)
#  define ManufacturingMode (1U)
# endif
# if (defined RTE_CONST_EngineeringMode) || (defined EngineeringMode)
#  if (!defined RTE_CONST_EngineeringMode) || (RTE_CONST_EngineeringMode != 2U)
#   error "Enumeration constant <EngineeringMode> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EngineeringMode (2U)
#  define EngineeringMode (2U)
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

# define Rte_TypeDef_New_Coding_110
typedef uint8 New_Coding_110;
# define New_Coding_110_LowerLimit (0U)
# define New_Coding_110_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_110 (15U)
# define InvalidValue_New_Coding_110 (15U)
# if (defined RTE_CONST_Cx1_Normalbetrieb) || (defined Cx1_Normalbetrieb)
#  if (!defined RTE_CONST_Cx1_Normalbetrieb) || (RTE_CONST_Cx1_Normalbetrieb != 1U)
#   error "Enumeration constant <Cx1_Normalbetrieb> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Normalbetrieb (1U)
#  define Cx1_Normalbetrieb (1U)
# endif
# if (defined RTE_CONST_Cx2_Traktionsoptimiert_Stufe_1) || (defined Cx2_Traktionsoptimiert_Stufe_1)
#  if (!defined RTE_CONST_Cx2_Traktionsoptimiert_Stufe_1) || (RTE_CONST_Cx2_Traktionsoptimiert_Stufe_1 != 2U)
#   error "Enumeration constant <Cx2_Traktionsoptimiert_Stufe_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Traktionsoptimiert_Stufe_1 (2U)
#  define Cx2_Traktionsoptimiert_Stufe_1 (2U)
# endif
# if (defined RTE_CONST_Cx3_Traktionsoptimiert_Stufe_2) || (defined Cx3_Traktionsoptimiert_Stufe_2)
#  if (!defined RTE_CONST_Cx3_Traktionsoptimiert_Stufe_2) || (RTE_CONST_Cx3_Traktionsoptimiert_Stufe_2 != 3U)
#   error "Enumeration constant <Cx3_Traktionsoptimiert_Stufe_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Traktionsoptimiert_Stufe_2 (3U)
#  define Cx3_Traktionsoptimiert_Stufe_2 (3U)
# endif
# if (defined RTE_CONST_Cx4_Traktionsoptimiert_Stufe_3) || (defined Cx4_Traktionsoptimiert_Stufe_3)
#  if (!defined RTE_CONST_Cx4_Traktionsoptimiert_Stufe_3) || (RTE_CONST_Cx4_Traktionsoptimiert_Stufe_3 != 4U)
#   error "Enumeration constant <Cx4_Traktionsoptimiert_Stufe_3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Traktionsoptimiert_Stufe_3 (4U)
#  define Cx4_Traktionsoptimiert_Stufe_3 (4U)
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

# define Rte_TypeDef_New_Coding_111
typedef uint8 New_Coding_111;
# define New_Coding_111_LowerLimit (0U)
# define New_Coding_111_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_111 (15U)
# define InvalidValue_New_Coding_111 (15U)
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

# define Rte_TypeDef_New_Coding_112
typedef uint8 New_Coding_112;
# define New_Coding_112_LowerLimit (0U)
# define New_Coding_112_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_112 (15U)
# define InvalidValue_New_Coding_112 (15U)
# if (defined RTE_CONST_Cx0_Keine_Anforderung) || (defined Cx0_Keine_Anforderung)
#  if (!defined RTE_CONST_Cx0_Keine_Anforderung) || (RTE_CONST_Cx0_Keine_Anforderung != 0U)
#   error "Enumeration constant <Cx0_Keine_Anforderung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Keine_Anforderung (0U)
#  define Cx0_Keine_Anforderung (0U)
# endif
# if (defined RTE_CONST_Cb0xx1_Automatische_Parkunterstuetzung_unterbinden) || (defined Cb0xx1_Automatische_Parkunterstuetzung_unterbinden)
#  if (!defined RTE_CONST_Cb0xx1_Automatische_Parkunterstuetzung_unterbinden) || (RTE_CONST_Cb0xx1_Automatische_Parkunterstuetzung_unterbinden != 0U)
#   error "Enumeration constant <Cb0xx1_Automatische_Parkunterstuetzung_unterbinden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xx1_Automatische_Parkunterstuetzung_unterbinden (0U)
#  define Cb0xx1_Automatische_Parkunterstuetzung_unterbinden (0U)
# endif
# if (defined RTE_CONST_Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden) || (defined Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden)
#  if (!defined RTE_CONST_Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden) || (RTE_CONST_Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden != 0U)
#   error "Enumeration constant <Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden (0U)
#  define Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden (0U)
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

# define Rte_TypeDef_New_Coding_65
typedef uint8 New_Coding_65;
# define New_Coding_65_LowerLimit (0U)
# define New_Coding_65_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_65 (15U)
# define InvalidValue_New_Coding_65 (15U)
# if (defined RTE_CONST_Cx0_Anzeigesegment_AUS) || (defined Cx0_Anzeigesegment_AUS)
#  if (!defined RTE_CONST_Cx0_Anzeigesegment_AUS) || (RTE_CONST_Cx0_Anzeigesegment_AUS != 0U)
#   error "Enumeration constant <Cx0_Anzeigesegment_AUS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Anzeigesegment_AUS (0U)
#  define Cx0_Anzeigesegment_AUS (0U)
# endif
# if (defined RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken) || (defined Cx1_Anzeigesegment_AN__kein_Blinken)
#  if (!defined RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken) || (RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken != 1U)
#   error "Enumeration constant <Cx1_Anzeigesegment_AN__kein_Blinken> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken (1U)
#  define Cx1_Anzeigesegment_AN__kein_Blinken (1U)
# endif
# if (defined RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1) || (defined Cx2_Anzeigesegment_AN__Blinken_Stufe_1)
#  if (!defined RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1) || (RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1 != 2U)
#   error "Enumeration constant <Cx2_Anzeigesegment_AN__Blinken_Stufe_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
#  define Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
# endif
# if (defined RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2) || (defined Cx3_Anzeigesegment_AN__Blinken_Stufe_2)
#  if (!defined RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2) || (RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2 != 3U)
#   error "Enumeration constant <Cx3_Anzeigesegment_AN__Blinken_Stufe_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
#  define Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
# endif
# if (defined RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3) || (defined Cx4_Anzeigesegment_AN__Blinken_Stufe_3)
#  if (!defined RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3) || (RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3 != 4U)
#   error "Enumeration constant <Cx4_Anzeigesegment_AN__Blinken_Stufe_3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
#  define Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#  if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#   error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung (8U)
#  define Cx8_Initialisierung (8U)
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

# define Rte_TypeDef_New_Coding_66
typedef uint8 New_Coding_66;
# define New_Coding_66_LowerLimit (0U)
# define New_Coding_66_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_66 (15U)
# define InvalidValue_New_Coding_66 (15U)
# if (defined RTE_CONST_Cx0_Anzeigesegment_AUS) || (defined Cx0_Anzeigesegment_AUS)
#  if (!defined RTE_CONST_Cx0_Anzeigesegment_AUS) || (RTE_CONST_Cx0_Anzeigesegment_AUS != 0U)
#   error "Enumeration constant <Cx0_Anzeigesegment_AUS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Anzeigesegment_AUS (0U)
#  define Cx0_Anzeigesegment_AUS (0U)
# endif
# if (defined RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken) || (defined Cx1_Anzeigesegment_AN__kein_Blinken)
#  if (!defined RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken) || (RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken != 1U)
#   error "Enumeration constant <Cx1_Anzeigesegment_AN__kein_Blinken> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Anzeigesegment_AN__kein_Blinken (1U)
#  define Cx1_Anzeigesegment_AN__kein_Blinken (1U)
# endif
# if (defined RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1) || (defined Cx2_Anzeigesegment_AN__Blinken_Stufe_1)
#  if (!defined RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1) || (RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1 != 2U)
#   error "Enumeration constant <Cx2_Anzeigesegment_AN__Blinken_Stufe_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
#  define Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
# endif
# if (defined RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2) || (defined Cx3_Anzeigesegment_AN__Blinken_Stufe_2)
#  if (!defined RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2) || (RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2 != 3U)
#   error "Enumeration constant <Cx3_Anzeigesegment_AN__Blinken_Stufe_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
#  define Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
# endif
# if (defined RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3) || (defined Cx4_Anzeigesegment_AN__Blinken_Stufe_3)
#  if (!defined RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3) || (RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3 != 4U)
#   error "Enumeration constant <Cx4_Anzeigesegment_AN__Blinken_Stufe_3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
#  define Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
# endif
# if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#  if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#   error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Initialisierung (8U)
#  define Cx8_Initialisierung (8U)
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

# define Rte_TypeDef_New_Coding_67
typedef uint8 New_Coding_67;
# define New_Coding_67_LowerLimit (0U)
# define New_Coding_67_UpperLimit (3U)
# define Rte_InvalidValue_New_Coding_67 (3U)
# define InvalidValue_New_Coding_67 (3U)
# if (defined RTE_CONST_Cx0_Kein_Wert) || (defined Cx0_Kein_Wert)
#  if (!defined RTE_CONST_Cx0_Kein_Wert) || (RTE_CONST_Cx0_Kein_Wert != 0U)
#   error "Enumeration constant <Cx0_Kein_Wert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Kein_Wert (0U)
#  define Cx0_Kein_Wert (0U)
# endif
# if (defined RTE_CONST_Cx1_Mit_Trigger_beenden) || (defined Cx1_Mit_Trigger_beenden)
#  if (!defined RTE_CONST_Cx1_Mit_Trigger_beenden) || (RTE_CONST_Cx1_Mit_Trigger_beenden != 1U)
#   error "Enumeration constant <Cx1_Mit_Trigger_beenden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Mit_Trigger_beenden (1U)
#  define Cx1_Mit_Trigger_beenden (1U)
# endif
# if (defined RTE_CONST_Cx2_Mit_Aktivzeit_beenden) || (defined Cx2_Mit_Aktivzeit_beenden)
#  if (!defined RTE_CONST_Cx2_Mit_Aktivzeit_beenden) || (RTE_CONST_Cx2_Mit_Aktivzeit_beenden != 2U)
#   error "Enumeration constant <Cx2_Mit_Aktivzeit_beenden> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Mit_Aktivzeit_beenden (2U)
#  define Cx2_Mit_Aktivzeit_beenden (2U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_New_Coding_68
typedef uint8 New_Coding_68;
# define New_Coding_68_LowerLimit (0U)
# define New_Coding_68_UpperLimit (3U)
# define Rte_InvalidValue_New_Coding_68 (3U)
# define InvalidValue_New_Coding_68 (3U)
# if (defined RTE_CONST_Cx0_Vibration_AUS) || (defined Cx0_Vibration_AUS)
#  if (!defined RTE_CONST_Cx0_Vibration_AUS) || (RTE_CONST_Cx0_Vibration_AUS != 0U)
#   error "Enumeration constant <Cx0_Vibration_AUS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Vibration_AUS (0U)
#  define Cx0_Vibration_AUS (0U)
# endif
# if (defined RTE_CONST_Cx1_Vibration_EIN__dauerhaft) || (defined Cx1_Vibration_EIN__dauerhaft)
#  if (!defined RTE_CONST_Cx1_Vibration_EIN__dauerhaft) || (RTE_CONST_Cx1_Vibration_EIN__dauerhaft != 1U)
#   error "Enumeration constant <Cx1_Vibration_EIN__dauerhaft> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Vibration_EIN__dauerhaft (1U)
#  define Cx1_Vibration_EIN__dauerhaft (1U)
# endif
# if (defined RTE_CONST_Cx2_Vibration_EIN__intermittierend) || (defined Cx2_Vibration_EIN__intermittierend)
#  if (!defined RTE_CONST_Cx2_Vibration_EIN__intermittierend) || (RTE_CONST_Cx2_Vibration_EIN__intermittierend != 2U)
#   error "Enumeration constant <Cx2_Vibration_EIN__intermittierend> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Vibration_EIN__intermittierend (2U)
#  define Cx2_Vibration_EIN__intermittierend (2U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
# endif

# define Rte_TypeDef_New_Coding_71
typedef uint8 New_Coding_71;
# define New_Coding_71_LowerLimit (0U)
# define New_Coding_71_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_71 (15U)
# define InvalidValue_New_Coding_71 (15U)
# if (defined RTE_CONST_Cx0_Keine_haptische_Warnung) || (defined Cx0_Keine_haptische_Warnung)
#  if (!defined RTE_CONST_Cx0_Keine_haptische_Warnung) || (RTE_CONST_Cx0_Keine_haptische_Warnung != 0U)
#   error "Enumeration constant <Cx0_Keine_haptische_Warnung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Keine_haptische_Warnung (0U)
#  define Cx0_Keine_haptische_Warnung (0U)
# endif
# if (defined RTE_CONST_Cx1_Muster_1) || (defined Cx1_Muster_1)
#  if (!defined RTE_CONST_Cx1_Muster_1) || (RTE_CONST_Cx1_Muster_1 != 1U)
#   error "Enumeration constant <Cx1_Muster_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Muster_1 (1U)
#  define Cx1_Muster_1 (1U)
# endif
# if (defined RTE_CONST_Cx2_Muster_2) || (defined Cx2_Muster_2)
#  if (!defined RTE_CONST_Cx2_Muster_2) || (RTE_CONST_Cx2_Muster_2 != 2U)
#   error "Enumeration constant <Cx2_Muster_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Muster_2 (2U)
#  define Cx2_Muster_2 (2U)
# endif
# if (defined RTE_CONST_Cx3_Muster_3) || (defined Cx3_Muster_3)
#  if (!defined RTE_CONST_Cx3_Muster_3) || (RTE_CONST_Cx3_Muster_3 != 3U)
#   error "Enumeration constant <Cx3_Muster_3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Muster_3 (3U)
#  define Cx3_Muster_3 (3U)
# endif
# if (defined RTE_CONST_Cx4_Muster_4) || (defined Cx4_Muster_4)
#  if (!defined RTE_CONST_Cx4_Muster_4) || (RTE_CONST_Cx4_Muster_4 != 4U)
#   error "Enumeration constant <Cx4_Muster_4> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Muster_4 (4U)
#  define Cx4_Muster_4 (4U)
# endif
# if (defined RTE_CONST_Cx5_Muster_5) || (defined Cx5_Muster_5)
#  if (!defined RTE_CONST_Cx5_Muster_5) || (RTE_CONST_Cx5_Muster_5 != 5U)
#   error "Enumeration constant <Cx5_Muster_5> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx5_Muster_5 (5U)
#  define Cx5_Muster_5 (5U)
# endif
# if (defined RTE_CONST_Cx6_Muster_6) || (defined Cx6_Muster_6)
#  if (!defined RTE_CONST_Cx6_Muster_6) || (RTE_CONST_Cx6_Muster_6 != 6U)
#   error "Enumeration constant <Cx6_Muster_6> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Muster_6 (6U)
#  define Cx6_Muster_6 (6U)
# endif
# if (defined RTE_CONST_Cx7_Muster_7) || (defined Cx7_Muster_7)
#  if (!defined RTE_CONST_Cx7_Muster_7) || (RTE_CONST_Cx7_Muster_7 != 7U)
#   error "Enumeration constant <Cx7_Muster_7> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Muster_7 (7U)
#  define Cx7_Muster_7 (7U)
# endif
# if (defined RTE_CONST_Cx8_Muster_8) || (defined Cx8_Muster_8)
#  if (!defined RTE_CONST_Cx8_Muster_8) || (RTE_CONST_Cx8_Muster_8 != 8U)
#   error "Enumeration constant <Cx8_Muster_8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Muster_8 (8U)
#  define Cx8_Muster_8 (8U)
# endif
# if (defined RTE_CONST_Cx9_Muster_9) || (defined Cx9_Muster_9)
#  if (!defined RTE_CONST_Cx9_Muster_9) || (RTE_CONST_Cx9_Muster_9 != 9U)
#   error "Enumeration constant <Cx9_Muster_9> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx9_Muster_9 (9U)
#  define Cx9_Muster_9 (9U)
# endif
# if (defined RTE_CONST_CxA_Muster_10) || (defined CxA_Muster_10)
#  if (!defined RTE_CONST_CxA_Muster_10) || (RTE_CONST_CxA_Muster_10 != 10U)
#   error "Enumeration constant <CxA_Muster_10> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA_Muster_10 (10U)
#  define CxA_Muster_10 (10U)
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

# define Rte_TypeDef_New_Coding_72
typedef uint8 New_Coding_72;
# define New_Coding_72_LowerLimit (0U)
# define New_Coding_72_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_72 (255U)
# define InvalidValue_New_Coding_72 (255U)
# if (defined RTE_CONST_CxFF_Signal_unbefuellt) || (defined CxFF_Signal_unbefuellt)
#  if (!defined RTE_CONST_CxFF_Signal_unbefuellt) || (RTE_CONST_CxFF_Signal_unbefuellt != 255U)
#   error "Enumeration constant <CxFF_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_unbefuellt (255U)
#  define CxFF_Signal_unbefuellt (255U)
# endif

# define Rte_TypeDef_New_Coding_73
typedef uint8 New_Coding_73;
# define New_Coding_73_LowerLimit (0U)
# define New_Coding_73_UpperLimit (3U)
# define Rte_InvalidValue_New_Coding_73 (3U)
# define InvalidValue_New_Coding_73 (3U)
# if (defined RTE_CONST_Cx0_Keine_Richtung) || (defined Cx0_Keine_Richtung)
#  if (!defined RTE_CONST_Cx0_Keine_Richtung) || (RTE_CONST_Cx0_Keine_Richtung != 0U)
#   error "Enumeration constant <Cx0_Keine_Richtung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Keine_Richtung (0U)
#  define Cx0_Keine_Richtung (0U)
# endif
# if (defined RTE_CONST_Cx1_Richtung_links) || (defined Cx1_Richtung_links)
#  if (!defined RTE_CONST_Cx1_Richtung_links) || (RTE_CONST_Cx1_Richtung_links != 1U)
#   error "Enumeration constant <Cx1_Richtung_links> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Richtung_links (1U)
#  define Cx1_Richtung_links (1U)
# endif
# if (defined RTE_CONST_Cx2_Richtung_rechts) || (defined Cx2_Richtung_rechts)
#  if (!defined RTE_CONST_Cx2_Richtung_rechts) || (RTE_CONST_Cx2_Richtung_rechts != 2U)
#   error "Enumeration constant <Cx2_Richtung_rechts> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Richtung_rechts (2U)
#  define Cx2_Richtung_rechts (2U)
# endif
# if (defined RTE_CONST_Cx3_Signal_unbefuellt) || (defined Cx3_Signal_unbefuellt)
#  if (!defined RTE_CONST_Cx3_Signal_unbefuellt) || (RTE_CONST_Cx3_Signal_unbefuellt != 3U)
#   error "Enumeration constant <Cx3_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_unbefuellt (3U)
#  define Cx3_Signal_unbefuellt (3U)
# endif

# define Rte_TypeDef_New_Coding_74
typedef uint8 New_Coding_74;
# define New_Coding_74_LowerLimit (0U)
# define New_Coding_74_UpperLimit (63U)
# define Rte_InvalidValue_New_Coding_74 (63U)
# define InvalidValue_New_Coding_74 (63U)
# if (defined RTE_CONST_Cx00_Intensitaetsstufen1) || (defined Cx00_Intensitaetsstufen1)
#  if (!defined RTE_CONST_Cx00_Intensitaetsstufen1) || (RTE_CONST_Cx00_Intensitaetsstufen1 != 0U)
#   error "Enumeration constant <Cx00_Intensitaetsstufen1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx00_Intensitaetsstufen1 (0U)
#  define Cx00_Intensitaetsstufen1 (0U)
# endif
# if (defined RTE_CONST_Cx01_Intensitaetsstufen2) || (defined Cx01_Intensitaetsstufen2)
#  if (!defined RTE_CONST_Cx01_Intensitaetsstufen2) || (RTE_CONST_Cx01_Intensitaetsstufen2 != 1U)
#   error "Enumeration constant <Cx01_Intensitaetsstufen2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx01_Intensitaetsstufen2 (1U)
#  define Cx01_Intensitaetsstufen2 (1U)
# endif
# if (defined RTE_CONST_Cx02_Intensitaetsstufen3) || (defined Cx02_Intensitaetsstufen3)
#  if (!defined RTE_CONST_Cx02_Intensitaetsstufen3) || (RTE_CONST_Cx02_Intensitaetsstufen3 != 2U)
#   error "Enumeration constant <Cx02_Intensitaetsstufen3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02_Intensitaetsstufen3 (2U)
#  define Cx02_Intensitaetsstufen3 (2U)
# endif
# if (defined RTE_CONST_Cx03_Intensitaetsstufen4) || (defined Cx03_Intensitaetsstufen4)
#  if (!defined RTE_CONST_Cx03_Intensitaetsstufen4) || (RTE_CONST_Cx03_Intensitaetsstufen4 != 3U)
#   error "Enumeration constant <Cx03_Intensitaetsstufen4> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03_Intensitaetsstufen4 (3U)
#  define Cx03_Intensitaetsstufen4 (3U)
# endif
# if (defined RTE_CONST_Cx04_Intensitaetsstufen5) || (defined Cx04_Intensitaetsstufen5)
#  if (!defined RTE_CONST_Cx04_Intensitaetsstufen5) || (RTE_CONST_Cx04_Intensitaetsstufen5 != 4U)
#   error "Enumeration constant <Cx04_Intensitaetsstufen5> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx04_Intensitaetsstufen5 (4U)
#  define Cx04_Intensitaetsstufen5 (4U)
# endif
# if (defined RTE_CONST_Cx05_Intensitaetsstufen6) || (defined Cx05_Intensitaetsstufen6)
#  if (!defined RTE_CONST_Cx05_Intensitaetsstufen6) || (RTE_CONST_Cx05_Intensitaetsstufen6 != 5U)
#   error "Enumeration constant <Cx05_Intensitaetsstufen6> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx05_Intensitaetsstufen6 (5U)
#  define Cx05_Intensitaetsstufen6 (5U)
# endif
# if (defined RTE_CONST_Cx06_Intensitaetsstufen7) || (defined Cx06_Intensitaetsstufen7)
#  if (!defined RTE_CONST_Cx06_Intensitaetsstufen7) || (RTE_CONST_Cx06_Intensitaetsstufen7 != 6U)
#   error "Enumeration constant <Cx06_Intensitaetsstufen7> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx06_Intensitaetsstufen7 (6U)
#  define Cx06_Intensitaetsstufen7 (6U)
# endif
# if (defined RTE_CONST_Cx07_Intensitaetsstufen8) || (defined Cx07_Intensitaetsstufen8)
#  if (!defined RTE_CONST_Cx07_Intensitaetsstufen8) || (RTE_CONST_Cx07_Intensitaetsstufen8 != 7U)
#   error "Enumeration constant <Cx07_Intensitaetsstufen8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx07_Intensitaetsstufen8 (7U)
#  define Cx07_Intensitaetsstufen8 (7U)
# endif
# if (defined RTE_CONST_Cx08_Intensitaetsstufen9) || (defined Cx08_Intensitaetsstufen9)
#  if (!defined RTE_CONST_Cx08_Intensitaetsstufen9) || (RTE_CONST_Cx08_Intensitaetsstufen9 != 8U)
#   error "Enumeration constant <Cx08_Intensitaetsstufen9> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx08_Intensitaetsstufen9 (8U)
#  define Cx08_Intensitaetsstufen9 (8U)
# endif
# if (defined RTE_CONST_Cx09_Intensitaetsstufen10) || (defined Cx09_Intensitaetsstufen10)
#  if (!defined RTE_CONST_Cx09_Intensitaetsstufen10) || (RTE_CONST_Cx09_Intensitaetsstufen10 != 9U)
#   error "Enumeration constant <Cx09_Intensitaetsstufen10> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx09_Intensitaetsstufen10 (9U)
#  define Cx09_Intensitaetsstufen10 (9U)
# endif
# if (defined RTE_CONST_Cx0A_Intensitaetsstufen11) || (defined Cx0A_Intensitaetsstufen11)
#  if (!defined RTE_CONST_Cx0A_Intensitaetsstufen11) || (RTE_CONST_Cx0A_Intensitaetsstufen11 != 10U)
#   error "Enumeration constant <Cx0A_Intensitaetsstufen11> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0A_Intensitaetsstufen11 (10U)
#  define Cx0A_Intensitaetsstufen11 (10U)
# endif
# if (defined RTE_CONST_Cx0B_Intensitaetsstufen12) || (defined Cx0B_Intensitaetsstufen12)
#  if (!defined RTE_CONST_Cx0B_Intensitaetsstufen12) || (RTE_CONST_Cx0B_Intensitaetsstufen12 != 11U)
#   error "Enumeration constant <Cx0B_Intensitaetsstufen12> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0B_Intensitaetsstufen12 (11U)
#  define Cx0B_Intensitaetsstufen12 (11U)
# endif
# if (defined RTE_CONST_Cx0C_Intensitaetsstufen13) || (defined Cx0C_Intensitaetsstufen13)
#  if (!defined RTE_CONST_Cx0C_Intensitaetsstufen13) || (RTE_CONST_Cx0C_Intensitaetsstufen13 != 12U)
#   error "Enumeration constant <Cx0C_Intensitaetsstufen13> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0C_Intensitaetsstufen13 (12U)
#  define Cx0C_Intensitaetsstufen13 (12U)
# endif
# if (defined RTE_CONST_Cx0D_Intensitaetsstufen14) || (defined Cx0D_Intensitaetsstufen14)
#  if (!defined RTE_CONST_Cx0D_Intensitaetsstufen14) || (RTE_CONST_Cx0D_Intensitaetsstufen14 != 13U)
#   error "Enumeration constant <Cx0D_Intensitaetsstufen14> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0D_Intensitaetsstufen14 (13U)
#  define Cx0D_Intensitaetsstufen14 (13U)
# endif
# if (defined RTE_CONST_Cx0E_Intensitaetsstufen15) || (defined Cx0E_Intensitaetsstufen15)
#  if (!defined RTE_CONST_Cx0E_Intensitaetsstufen15) || (RTE_CONST_Cx0E_Intensitaetsstufen15 != 14U)
#   error "Enumeration constant <Cx0E_Intensitaetsstufen15> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0E_Intensitaetsstufen15 (14U)
#  define Cx0E_Intensitaetsstufen15 (14U)
# endif
# if (defined RTE_CONST_Cx0F_Intensitaetsstufen16) || (defined Cx0F_Intensitaetsstufen16)
#  if (!defined RTE_CONST_Cx0F_Intensitaetsstufen16) || (RTE_CONST_Cx0F_Intensitaetsstufen16 != 15U)
#   error "Enumeration constant <Cx0F_Intensitaetsstufen16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0F_Intensitaetsstufen16 (15U)
#  define Cx0F_Intensitaetsstufen16 (15U)
# endif
# if (defined RTE_CONST_Cx10_Intensitaetsstufen17) || (defined Cx10_Intensitaetsstufen17)
#  if (!defined RTE_CONST_Cx10_Intensitaetsstufen17) || (RTE_CONST_Cx10_Intensitaetsstufen17 != 16U)
#   error "Enumeration constant <Cx10_Intensitaetsstufen17> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx10_Intensitaetsstufen17 (16U)
#  define Cx10_Intensitaetsstufen17 (16U)
# endif
# if (defined RTE_CONST_Cx11_Intensitaetsstufen18) || (defined Cx11_Intensitaetsstufen18)
#  if (!defined RTE_CONST_Cx11_Intensitaetsstufen18) || (RTE_CONST_Cx11_Intensitaetsstufen18 != 17U)
#   error "Enumeration constant <Cx11_Intensitaetsstufen18> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx11_Intensitaetsstufen18 (17U)
#  define Cx11_Intensitaetsstufen18 (17U)
# endif
# if (defined RTE_CONST_Cx12_Intensitaetsstufen19) || (defined Cx12_Intensitaetsstufen19)
#  if (!defined RTE_CONST_Cx12_Intensitaetsstufen19) || (RTE_CONST_Cx12_Intensitaetsstufen19 != 18U)
#   error "Enumeration constant <Cx12_Intensitaetsstufen19> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx12_Intensitaetsstufen19 (18U)
#  define Cx12_Intensitaetsstufen19 (18U)
# endif
# if (defined RTE_CONST_Cx13_Intensitaetsstufen20) || (defined Cx13_Intensitaetsstufen20)
#  if (!defined RTE_CONST_Cx13_Intensitaetsstufen20) || (RTE_CONST_Cx13_Intensitaetsstufen20 != 19U)
#   error "Enumeration constant <Cx13_Intensitaetsstufen20> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx13_Intensitaetsstufen20 (19U)
#  define Cx13_Intensitaetsstufen20 (19U)
# endif
# if (defined RTE_CONST_Cx14_Intensitaetsstufen21) || (defined Cx14_Intensitaetsstufen21)
#  if (!defined RTE_CONST_Cx14_Intensitaetsstufen21) || (RTE_CONST_Cx14_Intensitaetsstufen21 != 20U)
#   error "Enumeration constant <Cx14_Intensitaetsstufen21> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx14_Intensitaetsstufen21 (20U)
#  define Cx14_Intensitaetsstufen21 (20U)
# endif
# if (defined RTE_CONST_Cx15_Intensitaetsstufen22) || (defined Cx15_Intensitaetsstufen22)
#  if (!defined RTE_CONST_Cx15_Intensitaetsstufen22) || (RTE_CONST_Cx15_Intensitaetsstufen22 != 21U)
#   error "Enumeration constant <Cx15_Intensitaetsstufen22> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx15_Intensitaetsstufen22 (21U)
#  define Cx15_Intensitaetsstufen22 (21U)
# endif
# if (defined RTE_CONST_Cx16_Intensitaetsstufen23) || (defined Cx16_Intensitaetsstufen23)
#  if (!defined RTE_CONST_Cx16_Intensitaetsstufen23) || (RTE_CONST_Cx16_Intensitaetsstufen23 != 22U)
#   error "Enumeration constant <Cx16_Intensitaetsstufen23> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx16_Intensitaetsstufen23 (22U)
#  define Cx16_Intensitaetsstufen23 (22U)
# endif
# if (defined RTE_CONST_Cx17_Intensitaetsstufen24) || (defined Cx17_Intensitaetsstufen24)
#  if (!defined RTE_CONST_Cx17_Intensitaetsstufen24) || (RTE_CONST_Cx17_Intensitaetsstufen24 != 23U)
#   error "Enumeration constant <Cx17_Intensitaetsstufen24> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx17_Intensitaetsstufen24 (23U)
#  define Cx17_Intensitaetsstufen24 (23U)
# endif
# if (defined RTE_CONST_Cx18_Intensitaetsstufen25) || (defined Cx18_Intensitaetsstufen25)
#  if (!defined RTE_CONST_Cx18_Intensitaetsstufen25) || (RTE_CONST_Cx18_Intensitaetsstufen25 != 24U)
#   error "Enumeration constant <Cx18_Intensitaetsstufen25> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx18_Intensitaetsstufen25 (24U)
#  define Cx18_Intensitaetsstufen25 (24U)
# endif
# if (defined RTE_CONST_Cx19_Intensitaetsstufen26) || (defined Cx19_Intensitaetsstufen26)
#  if (!defined RTE_CONST_Cx19_Intensitaetsstufen26) || (RTE_CONST_Cx19_Intensitaetsstufen26 != 25U)
#   error "Enumeration constant <Cx19_Intensitaetsstufen26> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx19_Intensitaetsstufen26 (25U)
#  define Cx19_Intensitaetsstufen26 (25U)
# endif
# if (defined RTE_CONST_Cx1A_Intensitaetsstufen27) || (defined Cx1A_Intensitaetsstufen27)
#  if (!defined RTE_CONST_Cx1A_Intensitaetsstufen27) || (RTE_CONST_Cx1A_Intensitaetsstufen27 != 26U)
#   error "Enumeration constant <Cx1A_Intensitaetsstufen27> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1A_Intensitaetsstufen27 (26U)
#  define Cx1A_Intensitaetsstufen27 (26U)
# endif
# if (defined RTE_CONST_Cx1B_Intensitaetsstufen28) || (defined Cx1B_Intensitaetsstufen28)
#  if (!defined RTE_CONST_Cx1B_Intensitaetsstufen28) || (RTE_CONST_Cx1B_Intensitaetsstufen28 != 27U)
#   error "Enumeration constant <Cx1B_Intensitaetsstufen28> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1B_Intensitaetsstufen28 (27U)
#  define Cx1B_Intensitaetsstufen28 (27U)
# endif
# if (defined RTE_CONST_Cx1C_Intensitaetsstufen29) || (defined Cx1C_Intensitaetsstufen29)
#  if (!defined RTE_CONST_Cx1C_Intensitaetsstufen29) || (RTE_CONST_Cx1C_Intensitaetsstufen29 != 28U)
#   error "Enumeration constant <Cx1C_Intensitaetsstufen29> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1C_Intensitaetsstufen29 (28U)
#  define Cx1C_Intensitaetsstufen29 (28U)
# endif
# if (defined RTE_CONST_Cx1D_Intensitaetsstufen30) || (defined Cx1D_Intensitaetsstufen30)
#  if (!defined RTE_CONST_Cx1D_Intensitaetsstufen30) || (RTE_CONST_Cx1D_Intensitaetsstufen30 != 29U)
#   error "Enumeration constant <Cx1D_Intensitaetsstufen30> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1D_Intensitaetsstufen30 (29U)
#  define Cx1D_Intensitaetsstufen30 (29U)
# endif
# if (defined RTE_CONST_Cx1E_Intensitaetsstufen31) || (defined Cx1E_Intensitaetsstufen31)
#  if (!defined RTE_CONST_Cx1E_Intensitaetsstufen31) || (RTE_CONST_Cx1E_Intensitaetsstufen31 != 30U)
#   error "Enumeration constant <Cx1E_Intensitaetsstufen31> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1E_Intensitaetsstufen31 (30U)
#  define Cx1E_Intensitaetsstufen31 (30U)
# endif
# if (defined RTE_CONST_Cx1F_Intensitaetsstufen32) || (defined Cx1F_Intensitaetsstufen32)
#  if (!defined RTE_CONST_Cx1F_Intensitaetsstufen32) || (RTE_CONST_Cx1F_Intensitaetsstufen32 != 31U)
#   error "Enumeration constant <Cx1F_Intensitaetsstufen32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1F_Intensitaetsstufen32 (31U)
#  define Cx1F_Intensitaetsstufen32 (31U)
# endif
# if (defined RTE_CONST_Cx20_Intensitaetsstufen33) || (defined Cx20_Intensitaetsstufen33)
#  if (!defined RTE_CONST_Cx20_Intensitaetsstufen33) || (RTE_CONST_Cx20_Intensitaetsstufen33 != 32U)
#   error "Enumeration constant <Cx20_Intensitaetsstufen33> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx20_Intensitaetsstufen33 (32U)
#  define Cx20_Intensitaetsstufen33 (32U)
# endif
# if (defined RTE_CONST_Cx21_Intensitaetsstufen34) || (defined Cx21_Intensitaetsstufen34)
#  if (!defined RTE_CONST_Cx21_Intensitaetsstufen34) || (RTE_CONST_Cx21_Intensitaetsstufen34 != 33U)
#   error "Enumeration constant <Cx21_Intensitaetsstufen34> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx21_Intensitaetsstufen34 (33U)
#  define Cx21_Intensitaetsstufen34 (33U)
# endif
# if (defined RTE_CONST_Cx22_Intensitaetsstufen35) || (defined Cx22_Intensitaetsstufen35)
#  if (!defined RTE_CONST_Cx22_Intensitaetsstufen35) || (RTE_CONST_Cx22_Intensitaetsstufen35 != 34U)
#   error "Enumeration constant <Cx22_Intensitaetsstufen35> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx22_Intensitaetsstufen35 (34U)
#  define Cx22_Intensitaetsstufen35 (34U)
# endif
# if (defined RTE_CONST_Cx23_Intensitaetsstufen36) || (defined Cx23_Intensitaetsstufen36)
#  if (!defined RTE_CONST_Cx23_Intensitaetsstufen36) || (RTE_CONST_Cx23_Intensitaetsstufen36 != 35U)
#   error "Enumeration constant <Cx23_Intensitaetsstufen36> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx23_Intensitaetsstufen36 (35U)
#  define Cx23_Intensitaetsstufen36 (35U)
# endif
# if (defined RTE_CONST_Cx24_Intensitaetsstufen37) || (defined Cx24_Intensitaetsstufen37)
#  if (!defined RTE_CONST_Cx24_Intensitaetsstufen37) || (RTE_CONST_Cx24_Intensitaetsstufen37 != 36U)
#   error "Enumeration constant <Cx24_Intensitaetsstufen37> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx24_Intensitaetsstufen37 (36U)
#  define Cx24_Intensitaetsstufen37 (36U)
# endif
# if (defined RTE_CONST_Cx25_Intensitaetsstufen38) || (defined Cx25_Intensitaetsstufen38)
#  if (!defined RTE_CONST_Cx25_Intensitaetsstufen38) || (RTE_CONST_Cx25_Intensitaetsstufen38 != 37U)
#   error "Enumeration constant <Cx25_Intensitaetsstufen38> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx25_Intensitaetsstufen38 (37U)
#  define Cx25_Intensitaetsstufen38 (37U)
# endif
# if (defined RTE_CONST_Cx26_Intensitaetsstufen39) || (defined Cx26_Intensitaetsstufen39)
#  if (!defined RTE_CONST_Cx26_Intensitaetsstufen39) || (RTE_CONST_Cx26_Intensitaetsstufen39 != 38U)
#   error "Enumeration constant <Cx26_Intensitaetsstufen39> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx26_Intensitaetsstufen39 (38U)
#  define Cx26_Intensitaetsstufen39 (38U)
# endif
# if (defined RTE_CONST_Cx27_Intensitaetsstufen40) || (defined Cx27_Intensitaetsstufen40)
#  if (!defined RTE_CONST_Cx27_Intensitaetsstufen40) || (RTE_CONST_Cx27_Intensitaetsstufen40 != 39U)
#   error "Enumeration constant <Cx27_Intensitaetsstufen40> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx27_Intensitaetsstufen40 (39U)
#  define Cx27_Intensitaetsstufen40 (39U)
# endif
# if (defined RTE_CONST_Cx28_Intensitaetsstufen41) || (defined Cx28_Intensitaetsstufen41)
#  if (!defined RTE_CONST_Cx28_Intensitaetsstufen41) || (RTE_CONST_Cx28_Intensitaetsstufen41 != 40U)
#   error "Enumeration constant <Cx28_Intensitaetsstufen41> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx28_Intensitaetsstufen41 (40U)
#  define Cx28_Intensitaetsstufen41 (40U)
# endif
# if (defined RTE_CONST_Cx29_Intensitaetsstufen42) || (defined Cx29_Intensitaetsstufen42)
#  if (!defined RTE_CONST_Cx29_Intensitaetsstufen42) || (RTE_CONST_Cx29_Intensitaetsstufen42 != 41U)
#   error "Enumeration constant <Cx29_Intensitaetsstufen42> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx29_Intensitaetsstufen42 (41U)
#  define Cx29_Intensitaetsstufen42 (41U)
# endif
# if (defined RTE_CONST_Cx2A_Intensitaetsstufen43) || (defined Cx2A_Intensitaetsstufen43)
#  if (!defined RTE_CONST_Cx2A_Intensitaetsstufen43) || (RTE_CONST_Cx2A_Intensitaetsstufen43 != 42U)
#   error "Enumeration constant <Cx2A_Intensitaetsstufen43> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2A_Intensitaetsstufen43 (42U)
#  define Cx2A_Intensitaetsstufen43 (42U)
# endif
# if (defined RTE_CONST_Cx2B_Intensitaetsstufen44) || (defined Cx2B_Intensitaetsstufen44)
#  if (!defined RTE_CONST_Cx2B_Intensitaetsstufen44) || (RTE_CONST_Cx2B_Intensitaetsstufen44 != 43U)
#   error "Enumeration constant <Cx2B_Intensitaetsstufen44> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2B_Intensitaetsstufen44 (43U)
#  define Cx2B_Intensitaetsstufen44 (43U)
# endif
# if (defined RTE_CONST_Cx2C_Intensitaetsstufen45) || (defined Cx2C_Intensitaetsstufen45)
#  if (!defined RTE_CONST_Cx2C_Intensitaetsstufen45) || (RTE_CONST_Cx2C_Intensitaetsstufen45 != 44U)
#   error "Enumeration constant <Cx2C_Intensitaetsstufen45> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2C_Intensitaetsstufen45 (44U)
#  define Cx2C_Intensitaetsstufen45 (44U)
# endif
# if (defined RTE_CONST_Cx2D_Intensitaetsstufen46) || (defined Cx2D_Intensitaetsstufen46)
#  if (!defined RTE_CONST_Cx2D_Intensitaetsstufen46) || (RTE_CONST_Cx2D_Intensitaetsstufen46 != 45U)
#   error "Enumeration constant <Cx2D_Intensitaetsstufen46> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2D_Intensitaetsstufen46 (45U)
#  define Cx2D_Intensitaetsstufen46 (45U)
# endif
# if (defined RTE_CONST_Cx2E_Intensitaetsstufen47) || (defined Cx2E_Intensitaetsstufen47)
#  if (!defined RTE_CONST_Cx2E_Intensitaetsstufen47) || (RTE_CONST_Cx2E_Intensitaetsstufen47 != 46U)
#   error "Enumeration constant <Cx2E_Intensitaetsstufen47> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2E_Intensitaetsstufen47 (46U)
#  define Cx2E_Intensitaetsstufen47 (46U)
# endif
# if (defined RTE_CONST_Cx2F_Intensitaetsstufen48) || (defined Cx2F_Intensitaetsstufen48)
#  if (!defined RTE_CONST_Cx2F_Intensitaetsstufen48) || (RTE_CONST_Cx2F_Intensitaetsstufen48 != 47U)
#   error "Enumeration constant <Cx2F_Intensitaetsstufen48> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2F_Intensitaetsstufen48 (47U)
#  define Cx2F_Intensitaetsstufen48 (47U)
# endif
# if (defined RTE_CONST_Cx30_Intensitaetsstufen49) || (defined Cx30_Intensitaetsstufen49)
#  if (!defined RTE_CONST_Cx30_Intensitaetsstufen49) || (RTE_CONST_Cx30_Intensitaetsstufen49 != 48U)
#   error "Enumeration constant <Cx30_Intensitaetsstufen49> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx30_Intensitaetsstufen49 (48U)
#  define Cx30_Intensitaetsstufen49 (48U)
# endif
# if (defined RTE_CONST_Cx31_Intensitaetsstufen50) || (defined Cx31_Intensitaetsstufen50)
#  if (!defined RTE_CONST_Cx31_Intensitaetsstufen50) || (RTE_CONST_Cx31_Intensitaetsstufen50 != 49U)
#   error "Enumeration constant <Cx31_Intensitaetsstufen50> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx31_Intensitaetsstufen50 (49U)
#  define Cx31_Intensitaetsstufen50 (49U)
# endif
# if (defined RTE_CONST_Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar) || (defined Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar)
#  if (!defined RTE_CONST_Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar) || (RTE_CONST_Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar != 61U)
#   error "Enumeration constant <Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar (61U)
#  define Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar (61U)
# endif
# if (defined RTE_CONST_Cx3E_Funktion_meldet_Fehler) || (defined Cx3E_Funktion_meldet_Fehler)
#  if (!defined RTE_CONST_Cx3E_Funktion_meldet_Fehler) || (RTE_CONST_Cx3E_Funktion_meldet_Fehler != 62U)
#   error "Enumeration constant <Cx3E_Funktion_meldet_Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3E_Funktion_meldet_Fehler (62U)
#  define Cx3E_Funktion_meldet_Fehler (62U)
# endif
# if (defined RTE_CONST_Cx3F_Signal_unbefuellt) || (defined Cx3F_Signal_unbefuellt)
#  if (!defined RTE_CONST_Cx3F_Signal_unbefuellt) || (RTE_CONST_Cx3F_Signal_unbefuellt != 63U)
#   error "Enumeration constant <Cx3F_Signal_unbefuellt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3F_Signal_unbefuellt (63U)
#  define Cx3F_Signal_unbefuellt (63U)
# endif

# define Rte_TypeDef_New_Coding_75
typedef uint8 New_Coding_75;
# define New_Coding_75_LowerLimit (0U)
# define New_Coding_75_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_75 (15U)
# define InvalidValue_New_Coding_75 (15U)
# if (defined RTE_CONST_Cx0_Intensitaetsstufe_0) || (defined Cx0_Intensitaetsstufe_0)
#  if (!defined RTE_CONST_Cx0_Intensitaetsstufe_0) || (RTE_CONST_Cx0_Intensitaetsstufe_0 != 0U)
#   error "Enumeration constant <Cx0_Intensitaetsstufe_0> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Intensitaetsstufe_0 (0U)
#  define Cx0_Intensitaetsstufe_0 (0U)
# endif
# if (defined RTE_CONST_Cx1_Intensitaetsstufe_1) || (defined Cx1_Intensitaetsstufe_1)
#  if (!defined RTE_CONST_Cx1_Intensitaetsstufe_1) || (RTE_CONST_Cx1_Intensitaetsstufe_1 != 1U)
#   error "Enumeration constant <Cx1_Intensitaetsstufe_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Intensitaetsstufe_1 (1U)
#  define Cx1_Intensitaetsstufe_1 (1U)
# endif
# if (defined RTE_CONST_Cx2_Intensitaetsstufe_2) || (defined Cx2_Intensitaetsstufe_2)
#  if (!defined RTE_CONST_Cx2_Intensitaetsstufe_2) || (RTE_CONST_Cx2_Intensitaetsstufe_2 != 2U)
#   error "Enumeration constant <Cx2_Intensitaetsstufe_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Intensitaetsstufe_2 (2U)
#  define Cx2_Intensitaetsstufe_2 (2U)
# endif
# if (defined RTE_CONST_Cx3_Intensitaetsstufe_3) || (defined Cx3_Intensitaetsstufe_3)
#  if (!defined RTE_CONST_Cx3_Intensitaetsstufe_3) || (RTE_CONST_Cx3_Intensitaetsstufe_3 != 3U)
#   error "Enumeration constant <Cx3_Intensitaetsstufe_3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Intensitaetsstufe_3 (3U)
#  define Cx3_Intensitaetsstufe_3 (3U)
# endif
# if (defined RTE_CONST_Cx4_Intensitaetsstufe_4) || (defined Cx4_Intensitaetsstufe_4)
#  if (!defined RTE_CONST_Cx4_Intensitaetsstufe_4) || (RTE_CONST_Cx4_Intensitaetsstufe_4 != 4U)
#   error "Enumeration constant <Cx4_Intensitaetsstufe_4> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Intensitaetsstufe_4 (4U)
#  define Cx4_Intensitaetsstufe_4 (4U)
# endif
# if (defined RTE_CONST_Cx5_Intensitaetsstufe_5) || (defined Cx5_Intensitaetsstufe_5)
#  if (!defined RTE_CONST_Cx5_Intensitaetsstufe_5) || (RTE_CONST_Cx5_Intensitaetsstufe_5 != 5U)
#   error "Enumeration constant <Cx5_Intensitaetsstufe_5> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx5_Intensitaetsstufe_5 (5U)
#  define Cx5_Intensitaetsstufe_5 (5U)
# endif
# if (defined RTE_CONST_Cx6_Intensitaetsstufe_6) || (defined Cx6_Intensitaetsstufe_6)
#  if (!defined RTE_CONST_Cx6_Intensitaetsstufe_6) || (RTE_CONST_Cx6_Intensitaetsstufe_6 != 6U)
#   error "Enumeration constant <Cx6_Intensitaetsstufe_6> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx6_Intensitaetsstufe_6 (6U)
#  define Cx6_Intensitaetsstufe_6 (6U)
# endif
# if (defined RTE_CONST_Cx7_Intensitaetsstufe_7) || (defined Cx7_Intensitaetsstufe_7)
#  if (!defined RTE_CONST_Cx7_Intensitaetsstufe_7) || (RTE_CONST_Cx7_Intensitaetsstufe_7 != 7U)
#   error "Enumeration constant <Cx7_Intensitaetsstufe_7> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx7_Intensitaetsstufe_7 (7U)
#  define Cx7_Intensitaetsstufe_7 (7U)
# endif
# if (defined RTE_CONST_Cx8_Intensitaetsstufe_8) || (defined Cx8_Intensitaetsstufe_8)
#  if (!defined RTE_CONST_Cx8_Intensitaetsstufe_8) || (RTE_CONST_Cx8_Intensitaetsstufe_8 != 8U)
#   error "Enumeration constant <Cx8_Intensitaetsstufe_8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx8_Intensitaetsstufe_8 (8U)
#  define Cx8_Intensitaetsstufe_8 (8U)
# endif
# if (defined RTE_CONST_Cx9_Intensitaetsstufe_9) || (defined Cx9_Intensitaetsstufe_9)
#  if (!defined RTE_CONST_Cx9_Intensitaetsstufe_9) || (RTE_CONST_Cx9_Intensitaetsstufe_9 != 9U)
#   error "Enumeration constant <Cx9_Intensitaetsstufe_9> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx9_Intensitaetsstufe_9 (9U)
#  define Cx9_Intensitaetsstufe_9 (9U)
# endif
# if (defined RTE_CONST_CxA_Intensitaetsstufe_10) || (defined CxA_Intensitaetsstufe_10)
#  if (!defined RTE_CONST_CxA_Intensitaetsstufe_10) || (RTE_CONST_CxA_Intensitaetsstufe_10 != 10U)
#   error "Enumeration constant <CxA_Intensitaetsstufe_10> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxA_Intensitaetsstufe_10 (10U)
#  define CxA_Intensitaetsstufe_10 (10U)
# endif
# if (defined RTE_CONST_CxB_Intensitaetsstufe_11) || (defined CxB_Intensitaetsstufe_11)
#  if (!defined RTE_CONST_CxB_Intensitaetsstufe_11) || (RTE_CONST_CxB_Intensitaetsstufe_11 != 11U)
#   error "Enumeration constant <CxB_Intensitaetsstufe_11> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxB_Intensitaetsstufe_11 (11U)
#  define CxB_Intensitaetsstufe_11 (11U)
# endif
# if (defined RTE_CONST_CxC_Intensitaetsstufe_12) || (defined CxC_Intensitaetsstufe_12)
#  if (!defined RTE_CONST_CxC_Intensitaetsstufe_12) || (RTE_CONST_CxC_Intensitaetsstufe_12 != 12U)
#   error "Enumeration constant <CxC_Intensitaetsstufe_12> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxC_Intensitaetsstufe_12 (12U)
#  define CxC_Intensitaetsstufe_12 (12U)
# endif
# if (defined RTE_CONST_CxD_Reserviert) || (defined CxD_Reserviert)
#  if (!defined RTE_CONST_CxD_Reserviert) || (RTE_CONST_CxD_Reserviert != 13U)
#   error "Enumeration constant <CxD_Reserviert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxD_Reserviert (13U)
#  define CxD_Reserviert (13U)
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

# define Rte_TypeDef_New_Coding_76
typedef uint8 New_Coding_76;
# define New_Coding_76_LowerLimit (0U)
# define New_Coding_76_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_76 (15U)
# define InvalidValue_New_Coding_76 (15U)
# if (defined RTE_CONST_Cx0_Verschliffen) || (defined Cx0_Verschliffen)
#  if (!defined RTE_CONST_Cx0_Verschliffen) || (RTE_CONST_Cx0_Verschliffen != 0U)
#   error "Enumeration constant <Cx0_Verschliffen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Verschliffen (0U)
#  define Cx0_Verschliffen (0U)
# endif
# if (defined RTE_CONST_Cx1_Ueberzeichnung) || (defined Cx1_Ueberzeichnung)
#  if (!defined RTE_CONST_Cx1_Ueberzeichnung) || (RTE_CONST_Cx1_Ueberzeichnung != 1U)
#   error "Enumeration constant <Cx1_Ueberzeichnung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Ueberzeichnung (1U)
#  define Cx1_Ueberzeichnung (1U)
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

# define Rte_TypeDef_New_Coding_77
typedef uint8 New_Coding_77;
# define New_Coding_77_LowerLimit (0U)
# define New_Coding_77_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_77 (15U)
# define InvalidValue_New_Coding_77 (15U)
# if (defined RTE_CONST_Cx1_Ultrahart__S__) || (defined Cx1_Ultrahart__S__)
#  if (!defined RTE_CONST_Cx1_Ultrahart__S__) || (RTE_CONST_Cx1_Ultrahart__S__ != 1U)
#   error "Enumeration constant <Cx1_Ultrahart__S__> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Ultrahart__S__ (1U)
#  define Cx1_Ultrahart__S__ (1U)
# endif
# if (defined RTE_CONST_Cx2_Sportlich_optimal__S_e_) || (defined Cx2_Sportlich_optimal__S_e_)
#  if (!defined RTE_CONST_Cx2_Sportlich_optimal__S_e_) || (RTE_CONST_Cx2_Sportlich_optimal__S_e_ != 2U)
#   error "Enumeration constant <Cx2_Sportlich_optimal__S_e_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Sportlich_optimal__S_e_ (2U)
#  define Cx2_Sportlich_optimal__S_e_ (2U)
# endif
# if (defined RTE_CONST_Cx3_Sportlich_ausgewogen__S_) || (defined Cx3_Sportlich_ausgewogen__S_)
#  if (!defined RTE_CONST_Cx3_Sportlich_ausgewogen__S_) || (RTE_CONST_Cx3_Sportlich_ausgewogen__S_ != 3U)
#   error "Enumeration constant <Cx3_Sportlich_ausgewogen__S_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Sportlich_ausgewogen__S_ (3U)
#  define Cx3_Sportlich_ausgewogen__S_ (3U)
# endif
# if (defined RTE_CONST_Cx4_Komfort_ausgewogen__B_) || (defined Cx4_Komfort_ausgewogen__B_)
#  if (!defined RTE_CONST_Cx4_Komfort_ausgewogen__B_) || (RTE_CONST_Cx4_Komfort_ausgewogen__B_ != 4U)
#   error "Enumeration constant <Cx4_Komfort_ausgewogen__B_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Komfort_ausgewogen__B_ (4U)
#  define Cx4_Komfort_ausgewogen__B_ (4U)
# endif
# if (defined RTE_CONST_Cx5_Weich__C_) || (defined Cx5_Weich__C_)
#  if (!defined RTE_CONST_Cx5_Weich__C_) || (RTE_CONST_Cx5_Weich__C_ != 5U)
#   error "Enumeration constant <Cx5_Weich__C_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx5_Weich__C_ (5U)
#  define Cx5_Weich__C_ (5U)
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

# define Rte_TypeDef_New_Coding_78
typedef uint8 New_Coding_78;
# define New_Coding_78_LowerLimit (0U)
# define New_Coding_78_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_78 (15U)
# define InvalidValue_New_Coding_78 (15U)
# if (defined RTE_CONST_Cx1_Luftfeder_in_Normalstellung__B_) || (defined Cx1_Luftfeder_in_Normalstellung__B_)
#  if (!defined RTE_CONST_Cx1_Luftfeder_in_Normalstellung__B_) || (RTE_CONST_Cx1_Luftfeder_in_Normalstellung__B_ != 1U)
#   error "Enumeration constant <Cx1_Luftfeder_in_Normalstellung__B_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Luftfeder_in_Normalstellung__B_ (1U)
#  define Cx1_Luftfeder_in_Normalstellung__B_ (1U)
# endif
# if (defined RTE_CONST_Cx2_Luftfeder_abgesenkt__S_) || (defined Cx2_Luftfeder_abgesenkt__S_)
#  if (!defined RTE_CONST_Cx2_Luftfeder_abgesenkt__S_) || (RTE_CONST_Cx2_Luftfeder_abgesenkt__S_ != 2U)
#   error "Enumeration constant <Cx2_Luftfeder_abgesenkt__S_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Luftfeder_abgesenkt__S_ (2U)
#  define Cx2_Luftfeder_abgesenkt__S_ (2U)
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

# define Rte_TypeDef_New_Coding_79
typedef uint8 New_Coding_79;
# define New_Coding_79_LowerLimit (0U)
# define New_Coding_79_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_79 (15U)
# define InvalidValue_New_Coding_79 (15U)
# if (defined RTE_CONST_Cx1_Ultrahart) || (defined Cx1_Ultrahart)
#  if (!defined RTE_CONST_Cx1_Ultrahart) || (RTE_CONST_Cx1_Ultrahart != 1U)
#   error "Enumeration constant <Cx1_Ultrahart> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Ultrahart (1U)
#  define Cx1_Ultrahart (1U)
# endif
# if (defined RTE_CONST_Cx2_Sportlich_ausgewogen) || (defined Cx2_Sportlich_ausgewogen)
#  if (!defined RTE_CONST_Cx2_Sportlich_ausgewogen) || (RTE_CONST_Cx2_Sportlich_ausgewogen != 2U)
#   error "Enumeration constant <Cx2_Sportlich_ausgewogen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Sportlich_ausgewogen (2U)
#  define Cx2_Sportlich_ausgewogen (2U)
# endif
# if (defined RTE_CONST_Cx3_Ausgewogen) || (defined Cx3_Ausgewogen)
#  if (!defined RTE_CONST_Cx3_Ausgewogen) || (RTE_CONST_Cx3_Ausgewogen != 3U)
#   error "Enumeration constant <Cx3_Ausgewogen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Ausgewogen (3U)
#  define Cx3_Ausgewogen (3U)
# endif
# if (defined RTE_CONST_Cx4_Weich) || (defined Cx4_Weich)
#  if (!defined RTE_CONST_Cx4_Weich) || (RTE_CONST_Cx4_Weich != 4U)
#   error "Enumeration constant <Cx4_Weich> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Weich (4U)
#  define Cx4_Weich (4U)
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

# define Rte_TypeDef_New_Coding_80
typedef uint8 New_Coding_80;
# define New_Coding_80_LowerLimit (0U)
# define New_Coding_80_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_80 (255U)
# define InvalidValue_New_Coding_80 (255U)
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

# define Rte_TypeDef_New_Coding_81
typedef uint8 New_Coding_81;
# define New_Coding_81_LowerLimit (0U)
# define New_Coding_81_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_81 (15U)
# define InvalidValue_New_Coding_81 (15U)
# if (defined RTE_CONST_Cx1_Voll) || (defined Cx1_Voll)
#  if (!defined RTE_CONST_Cx1_Voll) || (RTE_CONST_Cx1_Voll != 1U)
#   error "Enumeration constant <Cx1_Voll> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Voll (1U)
#  define Cx1_Voll (1U)
# endif
# if (defined RTE_CONST_Cx2_Mid) || (defined Cx2_Mid)
#  if (!defined RTE_CONST_Cx2_Mid) || (RTE_CONST_Cx2_Mid != 2U)
#   error "Enumeration constant <Cx2_Mid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Mid (2U)
#  define Cx2_Mid (2U)
# endif
# if (defined RTE_CONST_Cx3_Keine) || (defined Cx3_Keine)
#  if (!defined RTE_CONST_Cx3_Keine) || (RTE_CONST_Cx3_Keine != 3U)
#   error "Enumeration constant <Cx3_Keine> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Keine (3U)
#  define Cx3_Keine (3U)
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

# define Rte_TypeDef_New_Coding_82
typedef uint8 New_Coding_82;
# define New_Coding_82_LowerLimit (0U)
# define New_Coding_82_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_82 (15U)
# define InvalidValue_New_Coding_82 (15U)
# if (defined RTE_CONST_Cx1_Dynamische_Auspraegung_des_EDP) || (defined Cx1_Dynamische_Auspraegung_des_EDP)
#  if (!defined RTE_CONST_Cx1_Dynamische_Auspraegung_des_EDP) || (RTE_CONST_Cx1_Dynamische_Auspraegung_des_EDP != 1U)
#   error "Enumeration constant <Cx1_Dynamische_Auspraegung_des_EDP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Dynamische_Auspraegung_des_EDP (1U)
#  define Cx1_Dynamische_Auspraegung_des_EDP (1U)
# endif
# if (defined RTE_CONST_Cx2_Ausgewogene_Auspraegung_des_EDP) || (defined Cx2_Ausgewogene_Auspraegung_des_EDP)
#  if (!defined RTE_CONST_Cx2_Ausgewogene_Auspraegung_des_EDP) || (RTE_CONST_Cx2_Ausgewogene_Auspraegung_des_EDP != 2U)
#   error "Enumeration constant <Cx2_Ausgewogene_Auspraegung_des_EDP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Ausgewogene_Auspraegung_des_EDP (2U)
#  define Cx2_Ausgewogene_Auspraegung_des_EDP (2U)
# endif
# if (defined RTE_CONST_Cx3_Oekonomische_Auspraegung_des_EDP) || (defined Cx3_Oekonomische_Auspraegung_des_EDP)
#  if (!defined RTE_CONST_Cx3_Oekonomische_Auspraegung_des_EDP) || (RTE_CONST_Cx3_Oekonomische_Auspraegung_des_EDP != 3U)
#   error "Enumeration constant <Cx3_Oekonomische_Auspraegung_des_EDP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Oekonomische_Auspraegung_des_EDP (3U)
#  define Cx3_Oekonomische_Auspraegung_des_EDP (3U)
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

# define Rte_TypeDef_New_Coding_94
typedef uint8 New_Coding_94;
# define New_Coding_94_LowerLimit (0U)
# define New_Coding_94_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_94 (255U)
# define InvalidValue_New_Coding_94 (255U)
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

# define Rte_TypeDef_New_Coding_95
typedef uint8 New_Coding_95;
# define New_Coding_95_LowerLimit (0U)
# define New_Coding_95_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_95 (255U)
# define InvalidValue_New_Coding_95 (255U)
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

# define Rte_TypeDef_New_Coding_96
typedef uint8 New_Coding_96;
# define New_Coding_96_LowerLimit (0U)
# define New_Coding_96_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_96 (255U)
# define InvalidValue_New_Coding_96 (255U)
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

# define Rte_TypeDef_New_Coding_97
typedef uint8 New_Coding_97;
# define New_Coding_97_LowerLimit (0U)
# define New_Coding_97_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_97 (255U)
# define InvalidValue_New_Coding_97 (255U)
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

# define Rte_TypeDef_New_Coding_98
typedef uint8 New_Coding_98;
# define New_Coding_98_LowerLimit (0U)
# define New_Coding_98_UpperLimit (255U)
# define Rte_InvalidValue_New_Coding_98 (255U)
# define InvalidValue_New_Coding_98 (255U)
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

# define Rte_TypeDef_New_Coding_99
typedef uint8 New_Coding_99;
# define New_Coding_99_LowerLimit (0U)
# define New_Coding_99_UpperLimit (15U)
# define Rte_InvalidValue_New_Coding_99 (15U)
# define InvalidValue_New_Coding_99 (15U)
# if (defined RTE_CONST_Cx0_Degradationsstufe_0) || (defined Cx0_Degradationsstufe_0)
#  if (!defined RTE_CONST_Cx0_Degradationsstufe_0) || (RTE_CONST_Cx0_Degradationsstufe_0 != 0U)
#   error "Enumeration constant <Cx0_Degradationsstufe_0> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Degradationsstufe_0 (0U)
#  define Cx0_Degradationsstufe_0 (0U)
# endif
# if (defined RTE_CONST_Cx1_Degradationsstufe_1) || (defined Cx1_Degradationsstufe_1)
#  if (!defined RTE_CONST_Cx1_Degradationsstufe_1) || (RTE_CONST_Cx1_Degradationsstufe_1 != 1U)
#   error "Enumeration constant <Cx1_Degradationsstufe_1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Degradationsstufe_1 (1U)
#  define Cx1_Degradationsstufe_1 (1U)
# endif
# if (defined RTE_CONST_Cx2_Degradationsstufe_2) || (defined Cx2_Degradationsstufe_2)
#  if (!defined RTE_CONST_Cx2_Degradationsstufe_2) || (RTE_CONST_Cx2_Degradationsstufe_2 != 2U)
#   error "Enumeration constant <Cx2_Degradationsstufe_2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Degradationsstufe_2 (2U)
#  define Cx2_Degradationsstufe_2 (2U)
# endif
# if (defined RTE_CONST_Cx3_Degradationsstufe_3) || (defined Cx3_Degradationsstufe_3)
#  if (!defined RTE_CONST_Cx3_Degradationsstufe_3) || (RTE_CONST_Cx3_Degradationsstufe_3 != 3U)
#   error "Enumeration constant <Cx3_Degradationsstufe_3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Degradationsstufe_3 (3U)
#  define Cx3_Degradationsstufe_3 (3U)
# endif
# if (defined RTE_CONST_Cx4_Degradationsstufe_4) || (defined Cx4_Degradationsstufe_4)
#  if (!defined RTE_CONST_Cx4_Degradationsstufe_4) || (RTE_CONST_Cx4_Degradationsstufe_4 != 4U)
#   error "Enumeration constant <Cx4_Degradationsstufe_4> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx4_Degradationsstufe_4 (4U)
#  define Cx4_Degradationsstufe_4 (4U)
# endif
# if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#   error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxF_Signal_ungueltig (15U)
#  define CxF_Signal_ungueltig (15U)
# endif

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;
# define NvM_RequestResultType_LowerLimit (0U)
# define NvM_RequestResultType_UpperLimit (5U)
# if (defined RTE_CONST_NVM_REQ_OK) || (defined NVM_REQ_OK)
#  if (!defined RTE_CONST_NVM_REQ_OK) || (RTE_CONST_NVM_REQ_OK != 0U)
#   error "Enumeration constant <NVM_REQ_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_OK (0U)
#  define NVM_REQ_OK (0U)
# endif
# if (defined RTE_CONST_NVM_REQ_NOT_OK) || (defined NVM_REQ_NOT_OK)
#  if (!defined RTE_CONST_NVM_REQ_NOT_OK) || (RTE_CONST_NVM_REQ_NOT_OK != 1U)
#   error "Enumeration constant <NVM_REQ_NOT_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_NOT_OK (1U)
#  define NVM_REQ_NOT_OK (1U)
# endif
# if (defined RTE_CONST_NVM_REQ_PENDING) || (defined NVM_REQ_PENDING)
#  if (!defined RTE_CONST_NVM_REQ_PENDING) || (RTE_CONST_NVM_REQ_PENDING != 2U)
#   error "Enumeration constant <NVM_REQ_PENDING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_PENDING (2U)
#  define NVM_REQ_PENDING (2U)
# endif
# if (defined RTE_CONST_NVM_REQ_INTEGRITY_FAILED) || (defined NVM_REQ_INTEGRITY_FAILED)
#  if (!defined RTE_CONST_NVM_REQ_INTEGRITY_FAILED) || (RTE_CONST_NVM_REQ_INTEGRITY_FAILED != 3U)
#   error "Enumeration constant <NVM_REQ_INTEGRITY_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_INTEGRITY_FAILED (3U)
#  define NVM_REQ_INTEGRITY_FAILED (3U)
# endif
# if (defined RTE_CONST_NVM_REQ_BLOCK_SKIPPED) || (defined NVM_REQ_BLOCK_SKIPPED)
#  if (!defined RTE_CONST_NVM_REQ_BLOCK_SKIPPED) || (RTE_CONST_NVM_REQ_BLOCK_SKIPPED != 4U)
#   error "Enumeration constant <NVM_REQ_BLOCK_SKIPPED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_BLOCK_SKIPPED (4U)
#  define NVM_REQ_BLOCK_SKIPPED (4U)
# endif
# if (defined RTE_CONST_NVM_REQ_NV_INVALIDATED) || (defined NVM_REQ_NV_INVALIDATED)
#  if (!defined RTE_CONST_NVM_REQ_NV_INVALIDATED) || (RTE_CONST_NVM_REQ_NV_INVALIDATED != 5U)
#   error "Enumeration constant <NVM_REQ_NV_INVALIDATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NVM_REQ_NV_INVALIDATED (5U)
#  define NVM_REQ_NV_INVALIDATED (5U)
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

# define Rte_TypeDef_NxtrOpCycle
typedef uint8 NxtrOpCycle;
# define NxtrOpCycle_LowerLimit (0U)
# define NxtrOpCycle_UpperLimit (0U)
# if (defined RTE_CONST_NxtrDefaultOpCycle) || (defined NxtrDefaultOpCycle)
#  if (!defined RTE_CONST_NxtrDefaultOpCycle) || (RTE_CONST_NxtrDefaultOpCycle != 0U)
#   error "Enumeration constant <NxtrDefaultOpCycle> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NxtrDefaultOpCycle (0U)
#  define NxtrDefaultOpCycle (0U)
# endif

# define Rte_TypeDef_NxtrOpCycleState
typedef uint8 NxtrOpCycleState;
# define NxtrOpCycleState_LowerLimit (1U)
# define NxtrOpCycleState_UpperLimit (2U)
# if (defined RTE_CONST_NXTR_CYCLE_STATE_START) || (defined NXTR_CYCLE_STATE_START)
#  if (!defined RTE_CONST_NXTR_CYCLE_STATE_START) || (RTE_CONST_NXTR_CYCLE_STATE_START != 1U)
#   error "Enumeration constant <NXTR_CYCLE_STATE_START> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NXTR_CYCLE_STATE_START (1U)
#  define NXTR_CYCLE_STATE_START (1U)
# endif
# if (defined RTE_CONST_NXTR_CYCLE_STATE_END) || (defined NXTR_CYCLE_STATE_END)
#  if (!defined RTE_CONST_NXTR_CYCLE_STATE_END) || (RTE_CONST_NXTR_CYCLE_STATE_END != 2U)
#   error "Enumeration constant <NXTR_CYCLE_STATE_END> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NXTR_CYCLE_STATE_END (2U)
#  define NXTR_CYCLE_STATE_END (2U)
# endif

# define Rte_TypeDef_OscTrajCmdStateType
typedef uint8 OscTrajCmdStateType;
# define OscTrajCmdStateType_LowerLimit (0U)
# define OscTrajCmdStateType_UpperLimit (2U)
# if (defined RTE_CONST_CMD_STATE0) || (defined CMD_STATE0)
#  if (!defined RTE_CONST_CMD_STATE0) || (RTE_CONST_CMD_STATE0 != 0U)
#   error "Enumeration constant <CMD_STATE0> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CMD_STATE0 (0U)
#  define CMD_STATE0 (0U)
# endif
# if (defined RTE_CONST_CMD_STATE1) || (defined CMD_STATE1)
#  if (!defined RTE_CONST_CMD_STATE1) || (RTE_CONST_CMD_STATE1 != 1U)
#   error "Enumeration constant <CMD_STATE1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CMD_STATE1 (1U)
#  define CMD_STATE1 (1U)
# endif
# if (defined RTE_CONST_CMD_STATE2) || (defined CMD_STATE2)
#  if (!defined RTE_CONST_CMD_STATE2) || (RTE_CONST_CMD_STATE2 != 2U)
#   error "Enumeration constant <CMD_STATE2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CMD_STATE2 (2U)
#  define CMD_STATE2 (2U)
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

# define Rte_TypeDef_RQ_SU_SW_DRDY
typedef uint16 RQ_SU_SW_DRDY;
# define RQ_SU_SW_DRDY_LowerLimit (0U)
# define RQ_SU_SW_DRDY_UpperLimit (65535U)
# define Rte_InvalidValue_RQ_SU_SW_DRDY (65535U)
# define InvalidValue_RQ_SU_SW_DRDY (65535U)
# if (defined RTE_CONST_Cb1000xxxxxxxxxxxx_Initialisierung) || (defined Cb1000xxxxxxxxxxxx_Initialisierung)
#  if (!defined RTE_CONST_Cb1000xxxxxxxxxxxx_Initialisierung) || (RTE_CONST_Cb1000xxxxxxxxxxxx_Initialisierung != 0U)
#   error "Enumeration constant <Cb1000xxxxxxxxxxxx_Initialisierung> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb1000xxxxxxxxxxxx_Initialisierung (0U)
#  define Cb1000xxxxxxxxxxxx_Initialisierung (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx1101_Antrieb_Race) || (defined Cb0xxxxxxxxxxx1101_Antrieb_Race)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx1101_Antrieb_Race) || (RTE_CONST_Cb0xxxxxxxxxxx1101_Antrieb_Race != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx1101_Antrieb_Race> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx1101_Antrieb_Race (0U)
#  define Cb0xxxxxxxxxxx1101_Antrieb_Race (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx1011_Antrieb_Sport_) || (defined Cb0xxxxxxxxxxx1011_Antrieb_Sport_)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx1011_Antrieb_Sport_) || (RTE_CONST_Cb0xxxxxxxxxxx1011_Antrieb_Sport_ != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx1011_Antrieb_Sport_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx1011_Antrieb_Sport_ (0U)
#  define Cb0xxxxxxxxxxx1011_Antrieb_Sport_ (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx1010_Antrieb_Eco) || (defined Cb0xxxxxxxxxxx1010_Antrieb_Eco)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx1010_Antrieb_Eco) || (RTE_CONST_Cb0xxxxxxxxxxx1010_Antrieb_Eco != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx1010_Antrieb_Eco> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx1010_Antrieb_Eco (0U)
#  define Cb0xxxxxxxxxxx1010_Antrieb_Eco (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx1001_Antrieb_Sport) || (defined Cb0xxxxxxxxxxx1001_Antrieb_Sport)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx1001_Antrieb_Sport) || (RTE_CONST_Cb0xxxxxxxxxxx1001_Antrieb_Sport != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx1001_Antrieb_Sport> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx1001_Antrieb_Sport (0U)
#  define Cb0xxxxxxxxxxx1001_Antrieb_Sport (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx0100_Antrieb_Traction) || (defined Cb0xxxxxxxxxxx0100_Antrieb_Traction)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx0100_Antrieb_Traction) || (RTE_CONST_Cb0xxxxxxxxxxx0100_Antrieb_Traction != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx0100_Antrieb_Traction> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx0100_Antrieb_Traction (0U)
#  define Cb0xxxxxxxxxxx0100_Antrieb_Traction (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx0010_Antrieb_Komfort) || (defined Cb0xxxxxxxxxxx0010_Antrieb_Komfort)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx0010_Antrieb_Komfort) || (RTE_CONST_Cb0xxxxxxxxxxx0010_Antrieb_Komfort != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx0010_Antrieb_Komfort> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx0010_Antrieb_Komfort (0U)
#  define Cb0xxxxxxxxxxx0010_Antrieb_Komfort (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxxxxxx0000_Antrieb_Basis) || (defined Cb0xxxxxxxxxxx0000_Antrieb_Basis)
#  if (!defined RTE_CONST_Cb0xxxxxxxxxxx0000_Antrieb_Basis) || (RTE_CONST_Cb0xxxxxxxxxxx0000_Antrieb_Basis != 0U)
#   error "Enumeration constant <Cb0xxxxxxxxxxx0000_Antrieb_Basis> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxxxxxx0000_Antrieb_Basis (0U)
#  define Cb0xxxxxxxxxxx0000_Antrieb_Basis (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxx1000xxxx_Vertikaldynamik_Komfort) || (defined Cb0xxxxxxx1000xxxx_Vertikaldynamik_Komfort)
#  if (!defined RTE_CONST_Cb0xxxxxxx1000xxxx_Vertikaldynamik_Komfort) || (RTE_CONST_Cb0xxxxxxx1000xxxx_Vertikaldynamik_Komfort != 0U)
#   error "Enumeration constant <Cb0xxxxxxx1000xxxx_Vertikaldynamik_Komfort> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxx1000xxxx_Vertikaldynamik_Komfort (0U)
#  define Cb0xxxxxxx1000xxxx_Vertikaldynamik_Komfort (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxx0101xxxx_Vertikaldynamik_Sport) || (defined Cb0xxxxxxx0101xxxx_Vertikaldynamik_Sport)
#  if (!defined RTE_CONST_Cb0xxxxxxx0101xxxx_Vertikaldynamik_Sport) || (RTE_CONST_Cb0xxxxxxx0101xxxx_Vertikaldynamik_Sport != 0U)
#   error "Enumeration constant <Cb0xxxxxxx0101xxxx_Vertikaldynamik_Sport> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxx0101xxxx_Vertikaldynamik_Sport (0U)
#  define Cb0xxxxxxx0101xxxx_Vertikaldynamik_Sport (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxxxx0000xxxx_Vertikaldynamik_Basis) || (defined Cb0xxxxxxx0000xxxx_Vertikaldynamik_Basis)
#  if (!defined RTE_CONST_Cb0xxxxxxx0000xxxx_Vertikaldynamik_Basis) || (RTE_CONST_Cb0xxxxxxx0000xxxx_Vertikaldynamik_Basis != 0U)
#   error "Enumeration constant <Cb0xxxxxxx0000xxxx_Vertikaldynamik_Basis> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxxxx0000xxxx_Vertikaldynamik_Basis (0U)
#  define Cb0xxxxxxx0000xxxx_Vertikaldynamik_Basis (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxx11xxxxxxxx_Integrated_Chassimanagement_Regler_off) || (defined Cb0xxxxx11xxxxxxxx_Integrated_Chassimanagement_Regler_off)
#  if (!defined RTE_CONST_Cb0xxxxx11xxxxxxxx_Integrated_Chassimanagement_Regler_off) || (RTE_CONST_Cb0xxxxx11xxxxxxxx_Integrated_Chassimanagement_Regler_off != 0U)
#   error "Enumeration constant <Cb0xxxxx11xxxxxxxx_Integrated_Chassimanagement_Regler_off> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxx11xxxxxxxx_Integrated_Chassimanagement_Regler_off (0U)
#  define Cb0xxxxx11xxxxxxxx_Integrated_Chassimanagement_Regler_off (0U)
# endif
# if (defined RTE_CONST_Cb0xxxxx00xxxxxxxx_Integrated_Chassimanagement_Regler_on) || (defined Cb0xxxxx00xxxxxxxx_Integrated_Chassimanagement_Regler_on)
#  if (!defined RTE_CONST_Cb0xxxxx00xxxxxxxx_Integrated_Chassimanagement_Regler_on) || (RTE_CONST_Cb0xxxxx00xxxxxxxx_Integrated_Chassimanagement_Regler_on != 0U)
#   error "Enumeration constant <Cb0xxxxx00xxxxxxxx_Integrated_Chassimanagement_Regler_on> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxxxx00xxxxxxxx_Integrated_Chassimanagement_Regler_on (0U)
#  define Cb0xxxxx00xxxxxxxx_Integrated_Chassimanagement_Regler_on (0U)
# endif
# if (defined RTE_CONST_Cb0xxx10xxxxxxxxxx_Integrated_Chassimanagement_Sport___EPS_Sport_) || (defined Cb0xxx10xxxxxxxxxx_Integrated_Chassimanagement_Sport___EPS_Sport_)
#  if (!defined RTE_CONST_Cb0xxx10xxxxxxxxxx_Integrated_Chassimanagement_Sport___EPS_Sport_) || (RTE_CONST_Cb0xxx10xxxxxxxxxx_Integrated_Chassimanagement_Sport___EPS_Sport_ != 0U)
#   error "Enumeration constant <Cb0xxx10xxxxxxxxxx_Integrated_Chassimanagement_Sport___EPS_Sport_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxx10xxxxxxxxxx_Integrated_Chassimanagement_Sport___EPS_Sport_ (0U)
#  define Cb0xxx10xxxxxxxxxx_Integrated_Chassimanagement_Sport___EPS_Sport_ (0U)
# endif
# if (defined RTE_CONST_Cb0xxx01xxxxxxxxxx_Integrated_Chassimanagement_Sport__EPS_Sport) || (defined Cb0xxx01xxxxxxxxxx_Integrated_Chassimanagement_Sport__EPS_Sport)
#  if (!defined RTE_CONST_Cb0xxx01xxxxxxxxxx_Integrated_Chassimanagement_Sport__EPS_Sport) || (RTE_CONST_Cb0xxx01xxxxxxxxxx_Integrated_Chassimanagement_Sport__EPS_Sport != 0U)
#   error "Enumeration constant <Cb0xxx01xxxxxxxxxx_Integrated_Chassimanagement_Sport__EPS_Sport> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxx01xxxxxxxxxx_Integrated_Chassimanagement_Sport__EPS_Sport (0U)
#  define Cb0xxx01xxxxxxxxxx_Integrated_Chassimanagement_Sport__EPS_Sport (0U)
# endif
# if (defined RTE_CONST_Cb0xxx00xxxxxxxxxx_Integrated_Chassimanagement_Basis__EPS_Basis) || (defined Cb0xxx00xxxxxxxxxx_Integrated_Chassimanagement_Basis__EPS_Basis)
#  if (!defined RTE_CONST_Cb0xxx00xxxxxxxxxx_Integrated_Chassimanagement_Basis__EPS_Basis) || (RTE_CONST_Cb0xxx00xxxxxxxxxx_Integrated_Chassimanagement_Basis__EPS_Basis != 0U)
#   error "Enumeration constant <Cb0xxx00xxxxxxxxxx_Integrated_Chassimanagement_Basis__EPS_Basis> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0xxx00xxxxxxxxxx_Integrated_Chassimanagement_Basis__EPS_Basis (0U)
#  define Cb0xxx00xxxxxxxxxx_Integrated_Chassimanagement_Basis__EPS_Basis (0U)
# endif
# if (defined RTE_CONST_Cb0100xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_off) || (defined Cb0100xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_off)
#  if (!defined RTE_CONST_Cb0100xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_off) || (RTE_CONST_Cb0100xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_off != 0U)
#   error "Enumeration constant <Cb0100xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_off> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0100xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_off (0U)
#  define Cb0100xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_off (0U)
# endif
# if (defined RTE_CONST_Cb0010xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_Anfahrhilfe) || (defined Cb0010xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_Anfahrhilfe)
#  if (!defined RTE_CONST_Cb0010xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_Anfahrhilfe) || (RTE_CONST_Cb0010xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_Anfahrhilfe != 0U)
#   error "Enumeration constant <Cb0010xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_Anfahrhilfe> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0010xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_Anfahrhilfe (0U)
#  define Cb0010xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_Anfahrhilfe (0U)
# endif
# if (defined RTE_CONST_Cb0001xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DTC) || (defined Cb0001xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DTC)
#  if (!defined RTE_CONST_Cb0001xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DTC) || (RTE_CONST_Cb0001xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DTC != 0U)
#   error "Enumeration constant <Cb0001xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DTC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0001xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DTC (0U)
#  define Cb0001xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DTC (0U)
# endif
# if (defined RTE_CONST_Cb0000xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_on) || (defined Cb0000xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_on)
#  if (!defined RTE_CONST_Cb0000xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_on) || (RTE_CONST_Cb0000xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_on != 0U)
#   error "Enumeration constant <Cb0000xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_on> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cb0000xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_on (0U)
#  define Cb0000xxxxxxxxxxxx_Stabilisierung_Fahrdynamik_DSC_on (0U)
# endif
# if (defined RTE_CONST_CxFFFF_Signal_ungueltig) || (defined CxFFFF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxFFFF_Signal_ungueltig) || (RTE_CONST_CxFFFF_Signal_ungueltig != 65535U)
#   error "Enumeration constant <CxFFFF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFFFF_Signal_ungueltig (65535U)
#  define CxFFFF_Signal_ungueltig (65535U)
# endif

# define Rte_TypeDef_ST_DIAG_OBD_MUX_IMME
typedef uint8 ST_DIAG_OBD_MUX_IMME;
# define ST_DIAG_OBD_MUX_IMME_LowerLimit (0U)
# define ST_DIAG_OBD_MUX_IMME_UpperLimit (63U)
# define Rte_InvalidValue_ST_DIAG_OBD_MUX_IMME (63U)
# define InvalidValue_ST_DIAG_OBD_MUX_IMME (63U)
# if (defined RTE_CONST_Cx01_Cal_ID__software_calibration_identification_) || (defined Cx01_Cal_ID__software_calibration_identification_)
#  if (!defined RTE_CONST_Cx01_Cal_ID__software_calibration_identification_) || (RTE_CONST_Cx01_Cal_ID__software_calibration_identification_ != 1U)
#   error "Enumeration constant <Cx01_Cal_ID__software_calibration_identification_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx01_Cal_ID__software_calibration_identification_ (1U)
#  define Cx01_Cal_ID__software_calibration_identification_ (1U)
# endif
# if (defined RTE_CONST_Cx02_CVN__software_calibration_verification_number_) || (defined Cx02_CVN__software_calibration_verification_number_)
#  if (!defined RTE_CONST_Cx02_CVN__software_calibration_verification_number_) || (RTE_CONST_Cx02_CVN__software_calibration_verification_number_ != 2U)
#   error "Enumeration constant <Cx02_CVN__software_calibration_verification_number_> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02_CVN__software_calibration_verification_number_ (2U)
#  define Cx02_CVN__software_calibration_verification_number_ (2U)
# endif
# if (defined RTE_CONST_Cx3F_Ungueltig) || (defined Cx3F_Ungueltig)
#  if (!defined RTE_CONST_Cx3F_Ungueltig) || (RTE_CONST_Cx3F_Ungueltig != 63U)
#   error "Enumeration constant <Cx3F_Ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3F_Ungueltig (63U)
#  define Cx3F_Ungueltig (63U)
# endif

# define Rte_TypeDef_ST_ILK_ERRM_FZM
typedef uint8 ST_ILK_ERRM_FZM;
# define ST_ILK_ERRM_FZM_LowerLimit (0U)
# define ST_ILK_ERRM_FZM_UpperLimit (3U)
# define Rte_InvalidValue_ST_ILK_ERRM_FZM (3U)
# define InvalidValue_ST_ILK_ERRM_FZM (3U)
# if (defined RTE_CONST_Cx0_Fehlerspeicherfreigabe) || (defined Cx0_Fehlerspeicherfreigabe)
#  if (!defined RTE_CONST_Cx0_Fehlerspeicherfreigabe) || (RTE_CONST_Cx0_Fehlerspeicherfreigabe != 0U)
#   error "Enumeration constant <Cx0_Fehlerspeicherfreigabe> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx0_Fehlerspeicherfreigabe (0U)
#  define Cx0_Fehlerspeicherfreigabe (0U)
# endif
# if (defined RTE_CONST_Cx1_Fehlerspeichersperre) || (defined Cx1_Fehlerspeichersperre)
#  if (!defined RTE_CONST_Cx1_Fehlerspeichersperre) || (RTE_CONST_Cx1_Fehlerspeichersperre != 1U)
#   error "Enumeration constant <Cx1_Fehlerspeichersperre> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx1_Fehlerspeichersperre (1U)
#  define Cx1_Fehlerspeichersperre (1U)
# endif
# if (defined RTE_CONST_Cx2_Reserve) || (defined Cx2_Reserve)
#  if (!defined RTE_CONST_Cx2_Reserve) || (RTE_CONST_Cx2_Reserve != 2U)
#   error "Enumeration constant <Cx2_Reserve> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx2_Reserve (2U)
#  define Cx2_Reserve (2U)
# endif
# if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#  if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#   error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx3_Signal_ungueltig (3U)
#  define Cx3_Signal_ungueltig (3U)
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

# define Rte_TypeDef_SYS_STATE_ENUM
typedef uint8 SYS_STATE_ENUM;
# define SYS_STATE_ENUM_LowerLimit (0U)
# define SYS_STATE_ENUM_UpperLimit (255U)
# if (defined RTE_CONST_Cx00_DISABLE) || (defined Cx00_DISABLE)
#  if (!defined RTE_CONST_Cx00_DISABLE) || (RTE_CONST_Cx00_DISABLE != 0U)
#   error "Enumeration constant <Cx00_DISABLE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx00_DISABLE (0U)
#  define Cx00_DISABLE (0U)
# endif
# if (defined RTE_CONST_Cx01_OFF) || (defined Cx01_OFF)
#  if (!defined RTE_CONST_Cx01_OFF) || (RTE_CONST_Cx01_OFF != 1U)
#   error "Enumeration constant <Cx01_OFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx01_OFF (1U)
#  define Cx01_OFF (1U)
# endif
# if (defined RTE_CONST_Cx02_RUN) || (defined Cx02_RUN)
#  if (!defined RTE_CONST_Cx02_RUN) || (RTE_CONST_Cx02_RUN != 2U)
#   error "Enumeration constant <Cx02_RUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx02_RUN (2U)
#  define Cx02_RUN (2U)
# endif
# if (defined RTE_CONST_Cx03_WI) || (defined Cx03_WI)
#  if (!defined RTE_CONST_Cx03_WI) || (RTE_CONST_Cx03_WI != 3U)
#   error "Enumeration constant <Cx03_WI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx03_WI (3U)
#  define Cx03_WI (3U)
# endif
# if (defined RTE_CONST_Cx04_TRANSITION) || (defined Cx04_TRANSITION)
#  if (!defined RTE_CONST_Cx04_TRANSITION) || (RTE_CONST_Cx04_TRANSITION != 4U)
#   error "Enumeration constant <Cx04_TRANSITION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx04_TRANSITION (4U)
#  define Cx04_TRANSITION (4U)
# endif

# define Rte_TypeDef_SigQlfr_State_enum
typedef uint8 SigQlfr_State_enum;
# define SigQlfr_State_enum_LowerLimit (0U)
# define SigQlfr_State_enum_UpperLimit (2U)
# if (defined RTE_CONST_SIGQLFR_NORES) || (defined SIGQLFR_NORES)
#  if (!defined RTE_CONST_SIGQLFR_NORES) || (RTE_CONST_SIGQLFR_NORES != 0U)
#   error "Enumeration constant <SIGQLFR_NORES> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SIGQLFR_NORES (0U)
#  define SIGQLFR_NORES (0U)
# endif
# if (defined RTE_CONST_SIGQLFR_PASS) || (defined SIGQLFR_PASS)
#  if (!defined RTE_CONST_SIGQLFR_PASS) || (RTE_CONST_SIGQLFR_PASS != 1U)
#   error "Enumeration constant <SIGQLFR_PASS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SIGQLFR_PASS (1U)
#  define SIGQLFR_PASS (1U)
# endif
# if (defined RTE_CONST_SIGQLFR_FAIL) || (defined SIGQLFR_FAIL)
#  if (!defined RTE_CONST_SIGQLFR_FAIL) || (RTE_CONST_SIGQLFR_FAIL != 2U)
#   error "Enumeration constant <SIGQLFR_FAIL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SIGQLFR_FAIL (2U)
#  define SIGQLFR_FAIL (2U)
# endif

# define Rte_TypeDef_StaMd_Users
typedef uint8 StaMd_Users;
# define StaMd_Users_LowerLimit (0U)
# define StaMd_Users_UpperLimit (15U)
# if (defined RTE_CONST_STAMD_STOPCTRL) || (defined STAMD_STOPCTRL)
#  if (!defined RTE_CONST_STAMD_STOPCTRL) || (RTE_CONST_STAMD_STOPCTRL != 0U)
#   error "Enumeration constant <STAMD_STOPCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_STOPCTRL (0U)
#  define STAMD_STOPCTRL (0U)
# endif
# if (defined RTE_CONST_STAMD_VEHPWRMD) || (defined STAMD_VEHPWRMD)
#  if (!defined RTE_CONST_STAMD_VEHPWRMD) || (RTE_CONST_STAMD_VEHPWRMD != 1U)
#   error "Enumeration constant <STAMD_VEHPWRMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_VEHPWRMD (1U)
#  define STAMD_VEHPWRMD (1U)
# endif
# if (defined RTE_CONST_STAMD_DIAGMGR) || (defined STAMD_DIAGMGR)
#  if (!defined RTE_CONST_STAMD_DIAGMGR) || (RTE_CONST_STAMD_DIAGMGR != 2U)
#   error "Enumeration constant <STAMD_DIAGMGR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_DIAGMGR (2U)
#  define STAMD_DIAGMGR (2U)
# endif
# if (defined RTE_CONST_STAMD_PHSDSCNCT) || (defined STAMD_PHSDSCNCT)
#  if (!defined RTE_CONST_STAMD_PHSDSCNCT) || (RTE_CONST_STAMD_PHSDSCNCT != 3U)
#   error "Enumeration constant <STAMD_PHSDSCNCT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_PHSDSCNCT (3U)
#  define STAMD_PHSDSCNCT (3U)
# endif
# if (defined RTE_CONST_STAMD_MTRDRVR) || (defined STAMD_MTRDRVR)
#  if (!defined RTE_CONST_STAMD_MTRDRVR) || (RTE_CONST_STAMD_MTRDRVR != 4U)
#   error "Enumeration constant <STAMD_MTRDRVR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_MTRDRVR (4U)
#  define STAMD_MTRDRVR (4U)
# endif
# if (defined RTE_CONST_STAMD_TMPRLMON) || (defined STAMD_TMPRLMON)
#  if (!defined RTE_CONST_STAMD_TMPRLMON) || (RTE_CONST_STAMD_TMPRLMON != 5U)
#   error "Enumeration constant <STAMD_TMPRLMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_TMPRLMON (5U)
#  define STAMD_TMPRLMON (5U)
# endif
# if (defined RTE_CONST_STAMD_HWPWUP) || (defined STAMD_HWPWUP)
#  if (!defined RTE_CONST_STAMD_HWPWUP) || (RTE_CONST_STAMD_HWPWUP != 6U)
#   error "Enumeration constant <STAMD_HWPWUP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_HWPWUP (6U)
#  define STAMD_HWPWUP (6U)
# endif
# if (defined RTE_CONST_STAMD_MTRPOSDIAG) || (defined STAMD_MTRPOSDIAG)
#  if (!defined RTE_CONST_STAMD_MTRPOSDIAG) || (RTE_CONST_STAMD_MTRPOSDIAG != 7U)
#   error "Enumeration constant <STAMD_MTRPOSDIAG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_MTRPOSDIAG (7U)
#  define STAMD_MTRPOSDIAG (7U)
# endif

# define Rte_TypeDef_SteerMod_enum
typedef uint8 SteerMod_enum;
# define SteerMod_enum_LowerLimit (0U)
# define SteerMod_enum_UpperLimit (2U)
# if (defined RTE_CONST_STEERMOD_BASEPS) || (defined STEERMOD_BASEPS)
#  if (!defined RTE_CONST_STEERMOD_BASEPS) || (RTE_CONST_STEERMOD_BASEPS != 0U)
#   error "Enumeration constant <STEERMOD_BASEPS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STEERMOD_BASEPS (0U)
#  define STEERMOD_BASEPS (0U)
# endif
# if (defined RTE_CONST_STEERMOD_SEMIATNMS) || (defined STEERMOD_SEMIATNMS)
#  if (!defined RTE_CONST_STEERMOD_SEMIATNMS) || (RTE_CONST_STEERMOD_SEMIATNMS != 1U)
#   error "Enumeration constant <STEERMOD_SEMIATNMS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STEERMOD_SEMIATNMS (1U)
#  define STEERMOD_SEMIATNMS (1U)
# endif
# if (defined RTE_CONST_STEERMOD_FULLYATNMS) || (defined STEERMOD_FULLYATNMS)
#  if (!defined RTE_CONST_STEERMOD_FULLYATNMS) || (RTE_CONST_STEERMOD_FULLYATNMS != 2U)
#   error "Enumeration constant <STEERMOD_FULLYATNMS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STEERMOD_FULLYATNMS (2U)
#  define STEERMOD_FULLYATNMS (2U)
# endif

# define Rte_TypeDef_SysPrfmncSt_Cnt_enum
typedef uint8 SysPrfmncSt_Cnt_enum;
# define SysPrfmncSt_Cnt_enum_LowerLimit (0U)
# define SysPrfmncSt_Cnt_enum_UpperLimit (15U)
# if (defined RTE_CONST_SYSPRFMNCST_NORM) || (defined SYSPRFMNCST_NORM)
#  if (!defined RTE_CONST_SYSPRFMNCST_NORM) || (RTE_CONST_SYSPRFMNCST_NORM != 0U)
#   error "Enumeration constant <SYSPRFMNCST_NORM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_NORM (0U)
#  define SYSPRFMNCST_NORM (0U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_DUTYCYCDPTWARN) || (defined SYSPRFMNCST_DUTYCYCDPTWARN)
#  if (!defined RTE_CONST_SYSPRFMNCST_DUTYCYCDPTWARN) || (RTE_CONST_SYSPRFMNCST_DUTYCYCDPTWARN != 1U)
#   error "Enumeration constant <SYSPRFMNCST_DUTYCYCDPTWARN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_DUTYCYCDPTWARN (1U)
#  define SYSPRFMNCST_DUTYCYCDPTWARN (1U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_DUTYCYCDPTLIM) || (defined SYSPRFMNCST_DUTYCYCDPTLIM)
#  if (!defined RTE_CONST_SYSPRFMNCST_DUTYCYCDPTLIM) || (RTE_CONST_SYSPRFMNCST_DUTYCYCDPTLIM != 2U)
#   error "Enumeration constant <SYSPRFMNCST_DUTYCYCDPTLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_DUTYCYCDPTLIM (2U)
#  define SYSPRFMNCST_DUTYCYCDPTLIM (2U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_TDPTWARN) || (defined SYSPRFMNCST_TDPTWARN)
#  if (!defined RTE_CONST_SYSPRFMNCST_TDPTWARN) || (RTE_CONST_SYSPRFMNCST_TDPTWARN != 3U)
#   error "Enumeration constant <SYSPRFMNCST_TDPTWARN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_TDPTWARN (3U)
#  define SYSPRFMNCST_TDPTWARN (3U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_TDPTLIM) || (defined SYSPRFMNCST_TDPTLIM)
#  if (!defined RTE_CONST_SYSPRFMNCST_TDPTLIM) || (RTE_CONST_SYSPRFMNCST_TDPTLIM != 4U)
#   error "Enumeration constant <SYSPRFMNCST_TDPTLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_TDPTLIM (4U)
#  define SYSPRFMNCST_TDPTLIM (4U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_ASSISTALLDPTLIM) || (defined SYSPRFMNCST_ASSISTALLDPTLIM)
#  if (!defined RTE_CONST_SYSPRFMNCST_ASSISTALLDPTLIM) || (RTE_CONST_SYSPRFMNCST_ASSISTALLDPTLIM != 6U)
#   error "Enumeration constant <SYSPRFMNCST_ASSISTALLDPTLIM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_ASSISTALLDPTLIM (6U)
#  define SYSPRFMNCST_ASSISTALLDPTLIM (6U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_HWAGTOMOTAGCORRLN) || (defined SYSPRFMNCST_HWAGTOMOTAGCORRLN)
#  if (!defined RTE_CONST_SYSPRFMNCST_HWAGTOMOTAGCORRLN) || (RTE_CONST_SYSPRFMNCST_HWAGTOMOTAGCORRLN != 8U)
#   error "Enumeration constant <SYSPRFMNCST_HWAGTOMOTAGCORRLN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_HWAGTOMOTAGCORRLN (8U)
#  define SYSPRFMNCST_HWAGTOMOTAGCORRLN (8U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_KINEINTDIAGC) || (defined SYSPRFMNCST_KINEINTDIAGC)
#  if (!defined RTE_CONST_SYSPRFMNCST_KINEINTDIAGC) || (RTE_CONST_SYSPRFMNCST_KINEINTDIAGC != 9U)
#   error "Enumeration constant <SYSPRFMNCST_KINEINTDIAGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_KINEINTDIAGC (9U)
#  define SYSPRFMNCST_KINEINTDIAGC (9U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_LOASWBASDMTGTN) || (defined SYSPRFMNCST_LOASWBASDMTGTN)
#  if (!defined RTE_CONST_SYSPRFMNCST_LOASWBASDMTGTN) || (RTE_CONST_SYSPRFMNCST_LOASWBASDMTGTN != 10U)
#   error "Enumeration constant <SYSPRFMNCST_LOASWBASDMTGTN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_LOASWBASDMTGTN (10U)
#  define SYSPRFMNCST_LOASWBASDMTGTN (10U)
# endif
# if (defined RTE_CONST_SYSPRFMNCST_SYSSTDI) || (defined SYSPRFMNCST_SYSSTDI)
#  if (!defined RTE_CONST_SYSPRFMNCST_SYSSTDI) || (RTE_CONST_SYSPRFMNCST_SYSSTDI != 15U)
#   error "Enumeration constant <SYSPRFMNCST_SYSSTDI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCST_SYSSTDI (15U)
#  define SYSPRFMNCST_SYSSTDI (15U)
# endif

# define Rte_TypeDef_TEMP_CPO_HET_MNG
typedef uint8 TEMP_CPO_HET_MNG;
# define TEMP_CPO_HET_MNG_LowerLimit (0U)
# define TEMP_CPO_HET_MNG_UpperLimit (255U)
# define Rte_InvalidValue_TEMP_CPO_HET_MNG (255U)
# define InvalidValue_TEMP_CPO_HET_MNG (255U)
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

# define Rte_TypeDef_TuningSessionAddrPtrEnum
typedef uint8 TuningSessionAddrPtrEnum;
# define TuningSessionAddrPtrEnum_LowerLimit (0U)
# define TuningSessionAddrPtrEnum_UpperLimit (255U)
# if (defined RTE_CONST_TUN_SESSION_PTR_PERS) || (defined TUN_SESSION_PTR_PERS)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_PERS) || (RTE_CONST_TUN_SESSION_PTR_PERS != 0U)
#   error "Enumeration constant <TUN_SESSION_PTR_PERS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_PERS (0U)
#  define TUN_SESSION_PTR_PERS (0U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETS) || (defined TUN_SESSION_PTR_SETS)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETS) || (RTE_CONST_TUN_SESSION_PTR_SETS != 1U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETS (1U)
#  define TUN_SESSION_PTR_SETS (1U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_COMMON) || (defined TUN_SESSION_PTR_COMMON)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_COMMON) || (RTE_CONST_TUN_SESSION_PTR_COMMON != 2U)
#   error "Enumeration constant <TUN_SESSION_PTR_COMMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_COMMON (2U)
#  define TUN_SESSION_PTR_COMMON (2U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETANDPER) || (defined TUN_SESSION_PTR_SETANDPER)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETANDPER) || (RTE_CONST_TUN_SESSION_PTR_SETANDPER != 3U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETANDPER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETANDPER (3U)
#  define TUN_SESSION_PTR_SETANDPER (3U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON) || (defined TUN_SESSION_PTR_SETANDPERANDCOMMON)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON) || (RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON != 4U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETANDPERANDCOMMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON (4U)
#  define TUN_SESSION_PTR_SETANDPERANDCOMMON (4U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_CUSTSEG) || (defined TUN_SESSION_PTR_CUSTSEG)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_CUSTSEG) || (RTE_CONST_TUN_SESSION_PTR_CUSTSEG != 16U)
#   error "Enumeration constant <TUN_SESSION_PTR_CUSTSEG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_CUSTSEG (16U)
#  define TUN_SESSION_PTR_CUSTSEG (16U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_DISABLED) || (defined TUN_SESSION_PTR_DISABLED)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_DISABLED) || (RTE_CONST_TUN_SESSION_PTR_DISABLED != 255U)
#   error "Enumeration constant <TUN_SESSION_PTR_DISABLED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_DISABLED (255U)
#  define TUN_SESSION_PTR_DISABLED (255U)
# endif

# define Rte_TypeDef_TurnsCntrValStateType
typedef uint8 TurnsCntrValStateType;
# define TurnsCntrValStateType_LowerLimit (0U)
# define TurnsCntrValStateType_UpperLimit (255U)
# if (defined RTE_CONST_TCV_COMPUTING) || (defined TCV_COMPUTING)
#  if (!defined RTE_CONST_TCV_COMPUTING) || (RTE_CONST_TCV_COMPUTING != 0U)
#   error "Enumeration constant <TCV_COMPUTING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TCV_COMPUTING (0U)
#  define TCV_COMPUTING (0U)
# endif
# if (defined RTE_CONST_TCV_VALID) || (defined TCV_VALID)
#  if (!defined RTE_CONST_TCV_VALID) || (RTE_CONST_TCV_VALID != 100U)
#   error "Enumeration constant <TCV_VALID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TCV_VALID (100U)
#  define TCV_VALID (100U)
# endif
# if (defined RTE_CONST_TCV_INVALID) || (defined TCV_INVALID)
#  if (!defined RTE_CONST_TCV_INVALID) || (RTE_CONST_TCV_INVALID != 255U)
#   error "Enumeration constant <TCV_INVALID> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TCV_INVALID (255U)
#  define TCV_INVALID (255U)
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

# define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;
# define WdgM_GlobalStatusType_LowerLimit (0U)
# define WdgM_GlobalStatusType_UpperLimit (255U)
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_OK) || (defined WDGM_GLOBAL_STATUS_OK)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_OK) || (RTE_CONST_WDGM_GLOBAL_STATUS_OK != 0U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_OK (0U)
#  define WDGM_GLOBAL_STATUS_OK (0U)
# endif
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_FAILED) || (defined WDGM_GLOBAL_STATUS_FAILED)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_FAILED) || (RTE_CONST_WDGM_GLOBAL_STATUS_FAILED != 1U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_FAILED (1U)
#  define WDGM_GLOBAL_STATUS_FAILED (1U)
# endif
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED) || (defined WDGM_GLOBAL_STATUS_EXPIRED)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED) || (RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED != 2U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_EXPIRED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED (2U)
#  define WDGM_GLOBAL_STATUS_EXPIRED (2U)
# endif
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED) || (defined WDGM_GLOBAL_STATUS_STOPPED)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED) || (RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED != 3U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_STOPPED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED (3U)
#  define WDGM_GLOBAL_STATUS_STOPPED (3U)
# endif
# if (defined RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED) || (defined WDGM_GLOBAL_STATUS_DEACTIVATED)
#  if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED) || (RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED != 4U)
#   error "Enumeration constant <WDGM_GLOBAL_STATUS_DEACTIVATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#  define WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
# endif

# define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;
# define WdgM_LocalStatusType_LowerLimit (0U)
# define WdgM_LocalStatusType_UpperLimit (255U)
# if (defined RTE_CONST_WDGM_LOCAL_STATUS_OK) || (defined WDGM_LOCAL_STATUS_OK)
#  if (!defined RTE_CONST_WDGM_LOCAL_STATUS_OK) || (RTE_CONST_WDGM_LOCAL_STATUS_OK != 0U)
#   error "Enumeration constant <WDGM_LOCAL_STATUS_OK> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_LOCAL_STATUS_OK (0U)
#  define WDGM_LOCAL_STATUS_OK (0U)
# endif
# if (defined RTE_CONST_WDGM_LOCAL_STATUS_FAILED) || (defined WDGM_LOCAL_STATUS_FAILED)
#  if (!defined RTE_CONST_WDGM_LOCAL_STATUS_FAILED) || (RTE_CONST_WDGM_LOCAL_STATUS_FAILED != 1U)
#   error "Enumeration constant <WDGM_LOCAL_STATUS_FAILED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_LOCAL_STATUS_FAILED (1U)
#  define WDGM_LOCAL_STATUS_FAILED (1U)
# endif
# if (defined RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED) || (defined WDGM_LOCAL_STATUS_EXPIRED)
#  if (!defined RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED) || (RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED != 2U)
#   error "Enumeration constant <WDGM_LOCAL_STATUS_EXPIRED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED (2U)
#  define WDGM_LOCAL_STATUS_EXPIRED (2U)
# endif
# if (defined RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED) || (defined WDGM_LOCAL_STATUS_DEACTIVATED)
#  if (!defined RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED) || (RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED != 4U)
#   error "Enumeration constant <WDGM_LOCAL_STATUS_DEACTIVATED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
# endif

# define Rte_TypeDef_AvgFricLrnRangeCounterSubType
typedef UInt16 AvgFricLrnRangeCounterSubType[3];

# define Rte_TypeDef_AvgFricLrnThetaSubType
typedef Float AvgFricLrnThetaSubType[4];

# define Rte_TypeDef_AvgFricLrnVehLearnedFricType
typedef Float AvgFricLrnVehLearnedFricType[4];

# define Rte_TypeDef_Coding_BlockDataType
typedef UInt8 Coding_BlockDataType[132];

# define Rte_TypeDef_DIAG_OBD_DATA_Type
typedef UInt6 DIAG_OBD_DATA_Type[8];

# define Rte_TypeDef_DT_Array144_s8
typedef SInt8 DT_Array144_s8[144];

# define Rte_TypeDef_DT_SinTanLkpTbl_f32
typedef Float DT_SinTanLkpTbl_f32[193];

# define Rte_TypeDef_Dcm_Data_CALID_CVN_ArrayType
typedef UInt8 Dcm_Data_CALID_CVN_ArrayType[20];

# define Rte_TypeDef_EOLTrqStepType
typedef Float EOLTrqStepType[10];

# define Rte_TypeDef_NvM_DestPtr
typedef UInt8 NvM_DestPtr[65535];

# define Rte_TypeDef_Spi_DataPtr
typedef Spi_DataType Spi_DataPtr[65535];

# define Rte_TypeDef_TcPartNumType
typedef UInt8 TcPartNumType[20];

# define Rte_TypeDef_AbsHwPosTrim_DataType
typedef struct
{
  Float VehCntrOffset;
  UInt32 R_VehCntrOffset;
  UInt16 RacktoVehCntrOffset;
  UInt16 R_RacktoVehCntrOffset;
  Boolean LTVehCntrComplete;
  UInt8 R_LTVehCntrComplete;
} AbsHwPosTrim_DataType;

# define Rte_TypeDef_EOLNomMtrParamType
typedef struct
{
  Float NomKe_VpRadpS_f32;
  Float NomLq_Henry_f32;
  Float NomRmtr_Ohm_f32;
} EOLNomMtrParamType;

# define Rte_TypeDef_EOLTurnsCntrCals_Datatype
typedef struct
{
  UInt8 TcEolSineOffset_Cnt_u08;
  UInt8 TcEolCosineOffset_Cnt_u08;
  UInt8 TcEolSin2CosGain_Cnt_u08;
  UInt8 TcEolSinVsCosMin_Cnt_u08;
  UInt8 TcEolSinVsCosMax_Cnt_u08;
  UInt8 TcEolCalChksm_Cnt_u08;
} EOLTurnsCntrCals_Datatype;

# define Rte_TypeDef_EOTLearned_DataType
typedef struct
{
  Float CWEOTPosition_HwDeg_f32;
  Float CCWEOTPosition_HwDeg_f32;
  Boolean CWEOTFound_Cnt_lgc;
  Boolean CCWEOTFound_Cnt_lgc;
} EOTLearned_DataType;

# define Rte_TypeDef_HwTrqScale_Datatype
typedef struct
{
  Float HwTrqScale_VoltsPerDeg_f32;
  Boolean HwTrqScalePerf_Cnt_lgc;
} HwTrqScale_Datatype;

# define Rte_TypeDef_HwTrqTrim_Datatype
typedef struct
{
  Float HwTrqTrim_Volts_f32;
  Float T1Trim_Volts_f32;
  Float T2Trim_Volts_f32;
  Boolean HwTrqTrimPerf_Cnt_lgc;
} HwTrqTrim_Datatype;

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

# define Rte_TypeDef_RT_VIN_NO_VECH
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

# define Rte_TypeDef_RackCenterType
typedef struct
{
  Float TotalRackTravel_HwDeg_f32;
  Float RackCntrMtrDeg_MtrDeg_f32;
  Float RackCntrMtrRev_MtrRev_f32;
  Boolean RackCntrComplete_Cnt_lgc;
  Boolean RackCntrMtrAngleFound_Cnt_lgc;
} RackCenterType;

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

# define Rte_TypeDef_SG_ANFRAGE_DSC_Modul
typedef struct
{
  CD_0x08 ID2_0x08_Mx01_DSC_Modul;
  ID_FN_INQY ID_FN_INQY_DSC_Modul;
} SG_ANFRAGE_DSC_Modul;

# define Rte_TypeDef_SG_ANFRAGE_EPS
typedef struct
{
  ID_FN_INQY ID_FN_INQY_EPS;
  CD_0x08 ID2_0x08_Mx01_EPS;
} SG_ANFRAGE_EPS;

# define Rte_TypeDef_SG_ANFRAGE_SAS
typedef struct
{
  ID_FN_INQY ID_FN_INQY_SAS;
  CD_0x08 ID2_0x08_Mx01_SAS;
} SG_ANFRAGE_SAS;

# define Rte_TypeDef_SG_ANFRAGE_ZGW
typedef struct
{
  ID_FN_INQY ID_FN_INQY_ZGW;
  CD_0x08 ID2_0x08_Mx01_ZGW;
} SG_ANFRAGE_ZGW;

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

# define Rte_TypeDef_ShCurrCal_DataType
typedef struct
{
  Float EOLShcurrOffset_Volts_f32;
  Float EOLShcurrGain_Uls_f32;
} ShCurrCal_DataType;

# define Rte_TypeDef_SysOutpCpbySig_Str
typedef struct
{
  Float CwHwAg1;
  Float CwHwAg2;
  Float CwHwAg3;
  Float CwHwAg4;
  Float CwHwAg5;
  Float CcwHwAg1;
  Float CcwHwAg2;
  Float CcwHwAg3;
  Float CcwHwAg4;
  Float CcwHwAg5;
} SysOutpCpbySig_Str;

# define Rte_TypeDef_ThrmlDutyCycle_FltStVal_Datatype
typedef struct
{
  UInt8 Filt3Val_Cnt_u8;
  UInt8 Filt4Val_Cnt_u8;
  UInt8 Filt5Val_Cnt_u8;
  UInt8 Filt6Val_Cnt_u8;
} ThrmlDutyCycle_FltStVal_Datatype;

# define Rte_TypeDef_TuningSelectParam
typedef struct
{
  UInt16 TuningSet;
  UInt16 TuningPers;
} TuningSelectParam;

# define Rte_TypeDef_AvgFricLrnRangeCounterType
typedef AvgFricLrnRangeCounterSubType AvgFricLrnRangeCounterType[8];

# define Rte_TypeDef_AvgFricLrnThetaType
typedef AvgFricLrnThetaSubType AvgFricLrnThetaType[8];

# define Rte_TypeDef_AvgFricLrnType
typedef struct
{
  Float FricOffset_HwNm_f32;
  Float EOLFric_HwNm_f32;
  Boolean EnableFricOffsetOutput_Cnt_lgc;
  Boolean EnableFricLearning_Cnt_lgc;
  UInt8 OpMode_Cnt_enum;
  AvgFricLrnRangeCounterType RangeCounter_Cnt_u16;
  AvgFricLrnThetaType Theta_HwNm_f32;
  AvgFricLrnVehLearnedFricType VehLearnedFric_HwNm_f32;
} AvgFricLrnType;

# define Rte_TypeDef_Edch_EventStatusIpduDataType
typedef struct
{
  DIAG_OBD_DATA_Type IpduData;
} Edch_EventStatusIpduDataType;

# define Rte_TypeDef_MtrPosCal_DataType
typedef struct
{
  UInt16 BEMFCal_Rev_u0p16;
  UInt16 R_BEMFCal_Rev_u0p16;
  UInt16 Sin1Offset_Volts_u3p13;
  UInt16 Sin1AmpRec_Uls_u3p13;
  UInt16 Cos1Offset_Volts_u3p13;
  UInt16 Cos1AmpRec_Uls_u3p13;
  SInt16 SinDelta1_Uls_s2p13;
  UInt16 CosDelta1Rec_Uls_u3p13;
  SInt16 Sin1OffCorr_Volts_s2p13;
  UInt16 Sin1GainCorr_Uls_u1p15;
  SInt16 Cos1OffCorr_Volts_s2p13;
  UInt16 Cos1GainCorr_Uls_u1p15;
  DT_Array144_s8 SinHarTbl_Cnt_sm6p13;
  DT_Array144_s8 CosHarTbl_Cnt_sm6p13;
} MtrPosCal_DataType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_CD_0x02
typedef uint8 CD_0x02;
#  define CD_0x02_LowerLimit (0U)
#  define CD_0x02_UpperLimit (3U)

#  define Rte_TypeDef_CD_0x10
typedef uint16 CD_0x10;
#  define CD_0x10_LowerLimit (0U)
#  define CD_0x10_UpperLimit (65535U)

#  define Rte_TypeDef_DBG_8Bit
typedef uint8 DBG_8Bit;
#  define DBG_8Bit_LowerLimit (0U)
#  define DBG_8Bit_UpperLimit (255U)

#  define Rte_TypeDef_DT_ACLNY_COG
typedef uint16 DT_ACLNY_COG;
#  define DT_ACLNY_COG_LowerLimit (0U)
#  define DT_ACLNY_COG_UpperLimit (65000U)
#  define Rte_InvalidValue_DT_ACLNY_COG (66U)
#  define InvalidValue_DT_ACLNY_COG (66U)

#  define Rte_TypeDef_DT_ALIV_ACLNY_COG
typedef uint8 DT_ALIV_ACLNY_COG;
#  define DT_ALIV_ACLNY_COG_LowerLimit (0U)
#  define DT_ALIV_ACLNY_COG_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_ACLNY_COG (15U)
#  define InvalidValue_DT_ALIV_ACLNY_COG (15U)

#  define Rte_TypeDef_DT_ALIV_AVL_FORC_GRD
typedef uint8 DT_ALIV_AVL_FORC_GRD;
#  define DT_ALIV_AVL_FORC_GRD_LowerLimit (0U)
#  define DT_ALIV_AVL_FORC_GRD_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_AVL_FORC_GRD (15U)
#  define InvalidValue_DT_ALIV_AVL_FORC_GRD (15U)

#  define Rte_TypeDef_DT_ALIV_AVL_PO_EPS
typedef uint8 DT_ALIV_AVL_PO_EPS;
#  define DT_ALIV_AVL_PO_EPS_LowerLimit (0U)
#  define DT_ALIV_AVL_PO_EPS_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_AVL_PO_EPS (15U)
#  define InvalidValue_DT_ALIV_AVL_PO_EPS (15U)

#  define Rte_TypeDef_DT_ALIV_AVL_STEA_FTAX
typedef uint8 DT_ALIV_AVL_STEA_FTAX;
#  define DT_ALIV_AVL_STEA_FTAX_LowerLimit (0U)
#  define DT_ALIV_AVL_STEA_FTAX_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_AVL_STEA_FTAX (15U)
#  define InvalidValue_DT_ALIV_AVL_STEA_FTAX (15U)

#  define Rte_TypeDef_DT_ALIV_AVL_STMOM_DV_ACT
typedef uint8 DT_ALIV_AVL_STMOM_DV_ACT;
#  define DT_ALIV_AVL_STMOM_DV_ACT_LowerLimit (0U)
#  define DT_ALIV_AVL_STMOM_DV_ACT_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_AVL_STMOM_DV_ACT (15U)
#  define InvalidValue_DT_ALIV_AVL_STMOM_DV_ACT (15U)

#  define Rte_TypeDef_DT_ALIV_COU_KL
typedef uint8 DT_ALIV_COU_KL;
#  define DT_ALIV_COU_KL_LowerLimit (0U)
#  define DT_ALIV_COU_KL_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_COU_KL (15U)
#  define InvalidValue_DT_ALIV_COU_KL (15U)

#  define Rte_TypeDef_DT_ALIV_DISP_CC_DRDY_02
typedef uint8 DT_ALIV_DISP_CC_DRDY_02;
#  define DT_ALIV_DISP_CC_DRDY_02_LowerLimit (0U)
#  define DT_ALIV_DISP_CC_DRDY_02_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_DISP_CC_DRDY_02 (15U)
#  define InvalidValue_DT_ALIV_DISP_CC_DRDY_02 (15U)

#  define Rte_TypeDef_DT_ALIV_DT_PT_2
typedef uint8 DT_ALIV_DT_PT_2;
#  define DT_ALIV_DT_PT_2_LowerLimit (0U)
#  define DT_ALIV_DT_PT_2_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_DT_PT_2 (15U)
#  define InvalidValue_DT_ALIV_DT_PT_2 (15U)

#  define Rte_TypeDef_DT_ALIV_OFFS_QUAD_EPS
typedef uint8 DT_ALIV_OFFS_QUAD_EPS;
#  define DT_ALIV_OFFS_QUAD_EPS_LowerLimit (0U)
#  define DT_ALIV_OFFS_QUAD_EPS_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_OFFS_QUAD_EPS (15U)
#  define InvalidValue_DT_ALIV_OFFS_QUAD_EPS (15U)

#  define Rte_TypeDef_DT_ALIV_ST_EST_FTAX
typedef uint8 DT_ALIV_ST_EST_FTAX;
#  define DT_ALIV_ST_EST_FTAX_LowerLimit (0U)
#  define DT_ALIV_ST_EST_FTAX_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_ST_EST_FTAX (15U)
#  define InvalidValue_DT_ALIV_ST_EST_FTAX (15U)

#  define Rte_TypeDef_DT_ALIV_ST_PMA
typedef uint8 DT_ALIV_ST_PMA;
#  define DT_ALIV_ST_PMA_LowerLimit (0U)
#  define DT_ALIV_ST_PMA_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_ST_PMA (15U)
#  define InvalidValue_DT_ALIV_ST_PMA (15U)

#  define Rte_TypeDef_DT_ALIV_TAR_QTA_STMOM_DV
typedef uint8 DT_ALIV_TAR_QTA_STMOM_DV;
#  define DT_ALIV_TAR_QTA_STMOM_DV_LowerLimit (0U)
#  define DT_ALIV_TAR_QTA_STMOM_DV_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_TAR_QTA_STMOM_DV (15U)
#  define InvalidValue_DT_ALIV_TAR_QTA_STMOM_DV (15U)

#  define Rte_TypeDef_DT_ALIV_TAR_STMOM_DV_ACT
typedef uint8 DT_ALIV_TAR_STMOM_DV_ACT;
#  define DT_ALIV_TAR_STMOM_DV_ACT_LowerLimit (0U)
#  define DT_ALIV_TAR_STMOM_DV_ACT_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_TAR_STMOM_DV_ACT (15U)
#  define InvalidValue_DT_ALIV_TAR_STMOM_DV_ACT (15U)

#  define Rte_TypeDef_DT_ALIV_TORQ_CRSH_1
typedef uint8 DT_ALIV_TORQ_CRSH_1;
#  define DT_ALIV_TORQ_CRSH_1_LowerLimit (0U)
#  define DT_ALIV_TORQ_CRSH_1_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_TORQ_CRSH_1 (15U)
#  define InvalidValue_DT_ALIV_TORQ_CRSH_1 (15U)

#  define Rte_TypeDef_DT_ALIV_VYAW_VEH
typedef uint8 DT_ALIV_VYAW_VEH;
#  define DT_ALIV_VYAW_VEH_LowerLimit (0U)
#  define DT_ALIV_VYAW_VEH_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_VYAW_VEH (15U)
#  define InvalidValue_DT_ALIV_VYAW_VEH (15U)

#  define Rte_TypeDef_DT_ALIV_V_VEH
typedef uint8 DT_ALIV_V_VEH;
#  define DT_ALIV_V_VEH_LowerLimit (0U)
#  define DT_ALIV_V_VEH_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ALIV_V_VEH (15U)
#  define InvalidValue_DT_ALIV_V_VEH (15U)

#  define Rte_TypeDef_DT_AVL_FORC_GRD
typedef uint16 DT_AVL_FORC_GRD;
#  define DT_AVL_FORC_GRD_LowerLimit (0U)
#  define DT_AVL_FORC_GRD_UpperLimit (4047U)
#  define Rte_InvalidValue_DT_AVL_FORC_GRD (17U)
#  define InvalidValue_DT_AVL_FORC_GRD (17U)

#  define Rte_TypeDef_DT_AVL_PO_EPS
typedef uint16 DT_AVL_PO_EPS;
#  define DT_AVL_PO_EPS_LowerLimit (0U)
#  define DT_AVL_PO_EPS_UpperLimit (65534U)
#  define Rte_InvalidValue_DT_AVL_PO_EPS (1440U)
#  define InvalidValue_DT_AVL_PO_EPS (1440U)

#  define Rte_TypeDef_DT_AVL_PO_IDX_EPS
typedef uint16 DT_AVL_PO_IDX_EPS;
#  define DT_AVL_PO_IDX_EPS_LowerLimit (0U)
#  define DT_AVL_PO_IDX_EPS_UpperLimit (65534U)
#  define Rte_InvalidValue_DT_AVL_PO_IDX_EPS (1440U)
#  define InvalidValue_DT_AVL_PO_IDX_EPS (1440U)

#  define Rte_TypeDef_DT_AVL_PO_IDX_ICM
typedef uint16 DT_AVL_PO_IDX_ICM;
#  define DT_AVL_PO_IDX_ICM_LowerLimit (0U)
#  define DT_AVL_PO_IDX_ICM_UpperLimit (65534U)
#  define Rte_InvalidValue_DT_AVL_PO_IDX_ICM (1440U)
#  define InvalidValue_DT_AVL_PO_IDX_ICM (1440U)

#  define Rte_TypeDef_DT_AVL_PWR_EL_EPS_COOD
typedef uint8 DT_AVL_PWR_EL_EPS_COOD;
#  define DT_AVL_PWR_EL_EPS_COOD_LowerLimit (0U)
#  define DT_AVL_PWR_EL_EPS_COOD_UpperLimit (240U)
#  define Rte_InvalidValue_DT_AVL_PWR_EL_EPS_COOD (13U)
#  define InvalidValue_DT_AVL_PWR_EL_EPS_COOD (13U)

#  define Rte_TypeDef_DT_AVL_RPM_ENG_CRSH
typedef uint16 DT_AVL_RPM_ENG_CRSH;
#  define DT_AVL_RPM_ENG_CRSH_LowerLimit (0U)
#  define DT_AVL_RPM_ENG_CRSH_UpperLimit (48000U)
#  define Rte_InvalidValue_DT_AVL_RPM_ENG_CRSH (16383U)
#  define InvalidValue_DT_AVL_RPM_ENG_CRSH (16383U)

#  define Rte_TypeDef_DT_AVL_STEA_FTAX_WHL
typedef uint16 DT_AVL_STEA_FTAX_WHL;
#  define DT_AVL_STEA_FTAX_WHL_LowerLimit (0U)
#  define DT_AVL_STEA_FTAX_WHL_UpperLimit (65526U)
#  define Rte_InvalidValue_DT_AVL_STEA_FTAX_WHL (90U)
#  define InvalidValue_DT_AVL_STEA_FTAX_WHL (90U)

#  define Rte_TypeDef_DT_AVL_STMOM_DV_ACT
typedef uint16 DT_AVL_STMOM_DV_ACT;
#  define DT_AVL_STMOM_DV_ACT_LowerLimit (0U)
#  define DT_AVL_STMOM_DV_ACT_UpperLimit (4000U)
#  define Rte_InvalidValue_DT_AVL_STMOM_DV_ACT (10U)
#  define InvalidValue_DT_AVL_STMOM_DV_ACT (10U)

#  define Rte_TypeDef_DT_CRC_AVL_FORC_GRD
typedef uint8 DT_CRC_AVL_FORC_GRD;
#  define DT_CRC_AVL_FORC_GRD_LowerLimit (0U)
#  define DT_CRC_AVL_FORC_GRD_UpperLimit (255U)
#  define Rte_InvalidValue_DT_CRC_AVL_FORC_GRD (0U)
#  define InvalidValue_DT_CRC_AVL_FORC_GRD (0U)

#  define Rte_TypeDef_DT_CRC_AVL_PO_EPS
typedef uint8 DT_CRC_AVL_PO_EPS;
#  define DT_CRC_AVL_PO_EPS_LowerLimit (0U)
#  define DT_CRC_AVL_PO_EPS_UpperLimit (255U)
#  define Rte_InvalidValue_DT_CRC_AVL_PO_EPS (0U)
#  define InvalidValue_DT_CRC_AVL_PO_EPS (0U)

#  define Rte_TypeDef_DT_CRC_AVL_STMOM_DV_ACT
typedef uint8 DT_CRC_AVL_STMOM_DV_ACT;
#  define DT_CRC_AVL_STMOM_DV_ACT_LowerLimit (0U)
#  define DT_CRC_AVL_STMOM_DV_ACT_UpperLimit (255U)
#  define Rte_InvalidValue_DT_CRC_AVL_STMOM_DV_ACT (0U)
#  define InvalidValue_DT_CRC_AVL_STMOM_DV_ACT (0U)

#  define Rte_TypeDef_DT_CRC_OFFS_QUAD_EPS
typedef uint8 DT_CRC_OFFS_QUAD_EPS;
#  define DT_CRC_OFFS_QUAD_EPS_LowerLimit (0U)
#  define DT_CRC_OFFS_QUAD_EPS_UpperLimit (255U)
#  define Rte_InvalidValue_DT_CRC_OFFS_QUAD_EPS (0U)
#  define InvalidValue_DT_CRC_OFFS_QUAD_EPS (0U)

#  define Rte_TypeDef_DT_CRC_ST_EST_FTAX
typedef uint8 DT_CRC_ST_EST_FTAX;
#  define DT_CRC_ST_EST_FTAX_LowerLimit (0U)
#  define DT_CRC_ST_EST_FTAX_UpperLimit (255U)
#  define Rte_InvalidValue_DT_CRC_ST_EST_FTAX (0U)
#  define InvalidValue_DT_CRC_ST_EST_FTAX (0U)

#  define Rte_TypeDef_DT_CRC_TAR_QTA_STMOM_DV
typedef uint8 DT_CRC_TAR_QTA_STMOM_DV;
#  define DT_CRC_TAR_QTA_STMOM_DV_LowerLimit (0U)
#  define DT_CRC_TAR_QTA_STMOM_DV_UpperLimit (255U)
#  define Rte_InvalidValue_DT_CRC_TAR_QTA_STMOM_DV (0U)
#  define InvalidValue_DT_CRC_TAR_QTA_STMOM_DV (0U)

#  define Rte_TypeDef_DT_CRC_TAR_STMOM_DV_ACT
typedef uint8 DT_CRC_TAR_STMOM_DV_ACT;
#  define DT_CRC_TAR_STMOM_DV_ACT_LowerLimit (0U)
#  define DT_CRC_TAR_STMOM_DV_ACT_UpperLimit (255U)
#  define Rte_InvalidValue_DT_CRC_TAR_STMOM_DV_ACT (0U)
#  define InvalidValue_DT_CRC_TAR_STMOM_DV_ACT (0U)

#  define Rte_TypeDef_DT_CRC_V_VEH
typedef uint8 DT_CRC_V_VEH;
#  define DT_CRC_V_VEH_LowerLimit (0U)
#  define DT_CRC_V_VEH_UpperLimit (255U)
#  define Rte_InvalidValue_DT_CRC_V_VEH (0U)
#  define InvalidValue_DT_CRC_V_VEH (0U)

#  define Rte_TypeDef_DT_DBG_EPS
typedef uint8 DT_DBG_EPS;
#  define DT_DBG_EPS_LowerLimit (0U)
#  define DT_DBG_EPS_UpperLimit (255U)
#  define Rte_InvalidValue_DT_DBG_EPS (0U)
#  define InvalidValue_DT_DBG_EPS (0U)

#  define Rte_TypeDef_DT_DVCO_VEH
typedef uint8 DT_DVCO_VEH;
#  define DT_DVCO_VEH_LowerLimit (0U)
#  define DT_DVCO_VEH_UpperLimit (7U)
#  define Rte_InvalidValue_DT_DVCO_VEH (7U)
#  define InvalidValue_DT_DVCO_VEH (7U)

#  define Rte_TypeDef_DT_FACT_ASS_STMOM_FTAX
typedef uint8 DT_FACT_ASS_STMOM_FTAX;
#  define DT_FACT_ASS_STMOM_FTAX_LowerLimit (0U)
#  define DT_FACT_ASS_STMOM_FTAX_UpperLimit (254U)
#  define Rte_InvalidValue_DT_FACT_ASS_STMOM_FTAX (1U)
#  define InvalidValue_DT_FACT_ASS_STMOM_FTAX (1U)

#  define Rte_TypeDef_DT_FACT_CTRR_STMOM_FTAX
typedef uint8 DT_FACT_CTRR_STMOM_FTAX;
#  define DT_FACT_CTRR_STMOM_FTAX_LowerLimit (0U)
#  define DT_FACT_CTRR_STMOM_FTAX_UpperLimit (254U)
#  define Rte_InvalidValue_DT_FACT_CTRR_STMOM_FTAX (1U)
#  define InvalidValue_DT_FACT_CTRR_STMOM_FTAX (1U)

#  define Rte_TypeDef_DT_FACT_DMPNG_STMOM_FTAX
typedef uint8 DT_FACT_DMPNG_STMOM_FTAX;
#  define DT_FACT_DMPNG_STMOM_FTAX_LowerLimit (0U)
#  define DT_FACT_DMPNG_STMOM_FTAX_UpperLimit (254U)
#  define Rte_InvalidValue_DT_FACT_DMPNG_STMOM_FTAX (1U)
#  define InvalidValue_DT_FACT_DMPNG_STMOM_FTAX (1U)

#  define Rte_TypeDef_DT_IDX_TORQ_SEN
typedef uint8 DT_IDX_TORQ_SEN;
#  define DT_IDX_TORQ_SEN_LowerLimit (0U)
#  define DT_IDX_TORQ_SEN_UpperLimit (3U)
#  define Rte_InvalidValue_DT_IDX_TORQ_SEN (3U)
#  define InvalidValue_DT_IDX_TORQ_SEN (3U)

#  define Rte_TypeDef_DT_MILE_KM
typedef uint32 DT_MILE_KM;
#  define DT_MILE_KM_LowerLimit (0U)
#  define DT_MILE_KM_UpperLimit (16777214U)
#  define Rte_InvalidValue_DT_MILE_KM (16777215U)
#  define InvalidValue_DT_MILE_KM (16777215U)

#  define Rte_TypeDef_DT_NO_CC_DRDY_02
typedef uint16 DT_NO_CC_DRDY_02;
#  define DT_NO_CC_DRDY_02_LowerLimit (0U)
#  define DT_NO_CC_DRDY_02_UpperLimit (65534U)
#  define Rte_InvalidValue_DT_NO_CC_DRDY_02 (65535U)
#  define InvalidValue_DT_NO_CC_DRDY_02 (65535U)

#  define Rte_TypeDef_DT_OFFS_GRD_MID_EPS
typedef uint16 DT_OFFS_GRD_MID_EPS;
#  define DT_OFFS_GRD_MID_EPS_LowerLimit (0U)
#  define DT_OFFS_GRD_MID_EPS_UpperLimit (4093U)
#  define Rte_InvalidValue_DT_OFFS_GRD_MID_EPS (90U)
#  define InvalidValue_DT_OFFS_GRD_MID_EPS (90U)

#  define Rte_TypeDef_DT_OFFS_QUAD_RTR_EPS
typedef uint8 DT_OFFS_QUAD_RTR_EPS;
#  define DT_OFFS_QUAD_RTR_EPS_LowerLimit (0U)
#  define DT_OFFS_QUAD_RTR_EPS_UpperLimit (254U)
#  define Rte_InvalidValue_DT_OFFS_QUAD_RTR_EPS (128U)
#  define InvalidValue_DT_OFFS_QUAD_RTR_EPS (128U)

#  define Rte_TypeDef_DT_QU_ACLNY_COG
typedef uint8 DT_QU_ACLNY_COG;
#  define DT_QU_ACLNY_COG_LowerLimit (0U)
#  define DT_QU_ACLNY_COG_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_ACLNY_COG (15U)
#  define InvalidValue_DT_QU_ACLNY_COG (15U)

#  define Rte_TypeDef_DT_QU_AVL_FORC_GRD
typedef uint8 DT_QU_AVL_FORC_GRD;
#  define DT_QU_AVL_FORC_GRD_LowerLimit (0U)
#  define DT_QU_AVL_FORC_GRD_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_AVL_FORC_GRD (15U)
#  define InvalidValue_DT_QU_AVL_FORC_GRD (15U)

#  define Rte_TypeDef_DT_QU_AVL_PO_EPS
typedef uint8 DT_QU_AVL_PO_EPS;
#  define DT_QU_AVL_PO_EPS_LowerLimit (0U)
#  define DT_QU_AVL_PO_EPS_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_AVL_PO_EPS (15U)
#  define InvalidValue_DT_QU_AVL_PO_EPS (15U)

#  define Rte_TypeDef_DT_QU_AVL_RPM_ENG_CRSH
typedef uint8 DT_QU_AVL_RPM_ENG_CRSH;
#  define DT_QU_AVL_RPM_ENG_CRSH_LowerLimit (0U)
#  define DT_QU_AVL_RPM_ENG_CRSH_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_AVL_RPM_ENG_CRSH (15U)
#  define InvalidValue_DT_QU_AVL_RPM_ENG_CRSH (15U)

#  define Rte_TypeDef_DT_QU_AVL_STEA_FTAX_WHL
typedef uint8 DT_QU_AVL_STEA_FTAX_WHL;
#  define DT_QU_AVL_STEA_FTAX_WHL_LowerLimit (0U)
#  define DT_QU_AVL_STEA_FTAX_WHL_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_AVL_STEA_FTAX_WHL (15U)
#  define InvalidValue_DT_QU_AVL_STEA_FTAX_WHL (15U)

#  define Rte_TypeDef_DT_QU_AVL_STMOM_DV_ACT
typedef uint8 DT_QU_AVL_STMOM_DV_ACT;
#  define DT_QU_AVL_STMOM_DV_ACT_LowerLimit (0U)
#  define DT_QU_AVL_STMOM_DV_ACT_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_AVL_STMOM_DV_ACT (15U)
#  define InvalidValue_DT_QU_AVL_STMOM_DV_ACT (15U)

#  define Rte_TypeDef_DT_QU_FN_EST
typedef uint8 DT_QU_FN_EST;
#  define DT_QU_FN_EST_LowerLimit (0U)
#  define DT_QU_FN_EST_UpperLimit (255U)
#  define Rte_InvalidValue_DT_QU_FN_EST (255U)
#  define InvalidValue_DT_QU_FN_EST (255U)

#  define Rte_TypeDef_DT_QU_FN_PMA
typedef uint8 DT_QU_FN_PMA;
#  define DT_QU_FN_PMA_LowerLimit (0U)
#  define DT_QU_FN_PMA_UpperLimit (255U)
#  define Rte_InvalidValue_DT_QU_FN_PMA (255U)
#  define InvalidValue_DT_QU_FN_PMA (255U)

#  define Rte_TypeDef_DT_QU_HOFF_RCOG
typedef uint8 DT_QU_HOFF_RCOG;
#  define DT_QU_HOFF_RCOG_LowerLimit (0U)
#  define DT_QU_HOFF_RCOG_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_HOFF_RCOG (15U)
#  define InvalidValue_DT_QU_HOFF_RCOG (15U)

#  define Rte_TypeDef_DT_QU_SER_PINA_EST_FTAX
typedef uint8 DT_QU_SER_PINA_EST_FTAX;
#  define DT_QU_SER_PINA_EST_FTAX_LowerLimit (0U)
#  define DT_QU_SER_PINA_EST_FTAX_UpperLimit (255U)
#  define Rte_InvalidValue_DT_QU_SER_PINA_EST_FTAX (255U)
#  define InvalidValue_DT_QU_SER_PINA_EST_FTAX (255U)

#  define Rte_TypeDef_DT_QU_SER_STMOM_DV_ACT
typedef uint8 DT_QU_SER_STMOM_DV_ACT;
#  define DT_QU_SER_STMOM_DV_ACT_LowerLimit (0U)
#  define DT_QU_SER_STMOM_DV_ACT_UpperLimit (255U)
#  define Rte_InvalidValue_DT_QU_SER_STMOM_DV_ACT (255U)
#  define InvalidValue_DT_QU_SER_STMOM_DV_ACT (255U)

#  define Rte_TypeDef_DT_QU_TARVL_PMA
typedef uint8 DT_QU_TARVL_PMA;
#  define DT_QU_TARVL_PMA_LowerLimit (0U)
#  define DT_QU_TARVL_PMA_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_TARVL_PMA (15U)
#  define InvalidValue_DT_QU_TARVL_PMA (15U)

#  define Rte_TypeDef_DT_QU_TAR_FACT_STMOM_FTAX
typedef uint8 DT_QU_TAR_FACT_STMOM_FTAX;
#  define DT_QU_TAR_FACT_STMOM_FTAX_LowerLimit (0U)
#  define DT_QU_TAR_FACT_STMOM_FTAX_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_TAR_FACT_STMOM_FTAX (15U)
#  define InvalidValue_DT_QU_TAR_FACT_STMOM_FTAX (15U)

#  define Rte_TypeDef_DT_QU_TAR_QTA_STMOM_DV
typedef uint8 DT_QU_TAR_QTA_STMOM_DV;
#  define DT_QU_TAR_QTA_STMOM_DV_LowerLimit (0U)
#  define DT_QU_TAR_QTA_STMOM_DV_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_TAR_QTA_STMOM_DV (15U)
#  define InvalidValue_DT_QU_TAR_QTA_STMOM_DV (15U)

#  define Rte_TypeDef_DT_QU_TAR_STMOM_DV_ACT
typedef uint8 DT_QU_TAR_STMOM_DV_ACT;
#  define DT_QU_TAR_STMOM_DV_ACT_LowerLimit (0U)
#  define DT_QU_TAR_STMOM_DV_ACT_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_TAR_STMOM_DV_ACT (15U)
#  define InvalidValue_DT_QU_TAR_STMOM_DV_ACT (15U)

#  define Rte_TypeDef_DT_QU_VYAW_VEH
typedef uint8 DT_QU_VYAW_VEH;
#  define DT_QU_VYAW_VEH_LowerLimit (0U)
#  define DT_QU_VYAW_VEH_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_VYAW_VEH (15U)
#  define InvalidValue_DT_QU_VYAW_VEH (15U)

#  define Rte_TypeDef_DT_QU_V_VEH_COG
typedef uint8 DT_QU_V_VEH_COG;
#  define DT_QU_V_VEH_COG_LowerLimit (0U)
#  define DT_QU_V_VEH_COG_UpperLimit (15U)
#  define Rte_InvalidValue_DT_QU_V_VEH_COG (15U)
#  define InvalidValue_DT_QU_V_VEH_COG (15U)

#  define Rte_TypeDef_DT_RQ_SU_SW_DRDY
typedef uint16 DT_RQ_SU_SW_DRDY;
#  define DT_RQ_SU_SW_DRDY_LowerLimit (0U)
#  define DT_RQ_SU_SW_DRDY_UpperLimit (65535U)
#  define Rte_InvalidValue_DT_RQ_SU_SW_DRDY (65535U)
#  define InvalidValue_DT_RQ_SU_SW_DRDY (65535U)

#  define Rte_TypeDef_DT_SPEC_PWR_EL_EPS_MAX
typedef uint8 DT_SPEC_PWR_EL_EPS_MAX;
#  define DT_SPEC_PWR_EL_EPS_MAX_LowerLimit (0U)
#  define DT_SPEC_PWR_EL_EPS_MAX_UpperLimit (255U)
#  define Rte_InvalidValue_DT_SPEC_PWR_EL_EPS_MAX (255U)
#  define InvalidValue_DT_SPEC_PWR_EL_EPS_MAX (255U)

#  define Rte_TypeDef_DT_ST_CC_DRDY_02
typedef uint8 DT_ST_CC_DRDY_02;
#  define DT_ST_CC_DRDY_02_LowerLimit (0U)
#  define DT_ST_CC_DRDY_02_UpperLimit (3U)
#  define Rte_InvalidValue_DT_ST_CC_DRDY_02 (3U)
#  define InvalidValue_DT_ST_CC_DRDY_02 (3U)

#  define Rte_TypeDef_DT_ST_IDC_CC_DRDY_02
typedef uint8 DT_ST_IDC_CC_DRDY_02;
#  define DT_ST_IDC_CC_DRDY_02_LowerLimit (0U)
#  define DT_ST_IDC_CC_DRDY_02_UpperLimit (3U)
#  define Rte_InvalidValue_DT_ST_IDC_CC_DRDY_02 (3U)
#  define InvalidValue_DT_ST_IDC_CC_DRDY_02 (3U)

#  define Rte_TypeDef_DT_ST_ILK_ERRM_FZM
typedef uint8 DT_ST_ILK_ERRM_FZM;
#  define DT_ST_ILK_ERRM_FZM_LowerLimit (0U)
#  define DT_ST_ILK_ERRM_FZM_UpperLimit (3U)
#  define Rte_InvalidValue_DT_ST_ILK_ERRM_FZM (3U)
#  define InvalidValue_DT_ST_ILK_ERRM_FZM (3U)

#  define Rte_TypeDef_DT_ST_KL
typedef uint8 DT_ST_KL;
#  define DT_ST_KL_LowerLimit (0U)
#  define DT_ST_KL_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ST_KL (15U)
#  define InvalidValue_DT_ST_KL (15U)

#  define Rte_TypeDef_DT_ST_OFFS_QUAD_EPS
typedef uint8 DT_ST_OFFS_QUAD_EPS;
#  define DT_ST_OFFS_QUAD_EPS_LowerLimit (0U)
#  define DT_ST_OFFS_QUAD_EPS_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ST_OFFS_QUAD_EPS (15U)
#  define InvalidValue_DT_ST_OFFS_QUAD_EPS (15U)

#  define Rte_TypeDef_DT_ST_VEH_CON
typedef uint8 DT_ST_VEH_CON;
#  define DT_ST_VEH_CON_LowerLimit (0U)
#  define DT_ST_VEH_CON_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ST_VEH_CON (15U)
#  define InvalidValue_DT_ST_VEH_CON (15U)

#  define Rte_TypeDef_DT_ST_V_VEH_NSS
typedef uint8 DT_ST_V_VEH_NSS;
#  define DT_ST_V_VEH_NSS_LowerLimit (0U)
#  define DT_ST_V_VEH_NSS_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ST_V_VEH_NSS (15U)
#  define InvalidValue_DT_ST_V_VEH_NSS (15U)

#  define Rte_TypeDef_DT_Swa
typedef sint16 DT_Swa;
#  define DT_Swa_LowerLimit (-14400)
#  define DT_Swa_UpperLimit (14400)

#  define Rte_TypeDef_DT_TEMP_EX
typedef uint8 DT_TEMP_EX;
#  define DT_TEMP_EX_LowerLimit (0U)
#  define DT_TEMP_EX_UpperLimit (250U)
#  define Rte_InvalidValue_DT_TEMP_EX (87U)
#  define InvalidValue_DT_TEMP_EX (87U)

#  define Rte_TypeDef_DT_TOT_STR_EPS
typedef uint16 DT_TOT_STR_EPS;
#  define DT_TOT_STR_EPS_LowerLimit (0U)
#  define DT_TOT_STR_EPS_UpperLimit (4093U)
#  define Rte_InvalidValue_DT_TOT_STR_EPS (50U)
#  define InvalidValue_DT_TOT_STR_EPS (50U)

#  define Rte_TypeDef_DT_TRANF_CC_DRDY_02
typedef uint8 DT_TRANF_CC_DRDY_02;
#  define DT_TRANF_CC_DRDY_02_LowerLimit (0U)
#  define DT_TRANF_CC_DRDY_02_UpperLimit (14U)
#  define Rte_InvalidValue_DT_TRANF_CC_DRDY_02 (15U)
#  define InvalidValue_DT_TRANF_CC_DRDY_02 (15U)

#  define Rte_TypeDef_DT_T_SEC_COU_REL
typedef uint32 DT_T_SEC_COU_REL;
#  define DT_T_SEC_COU_REL_LowerLimit (0U)
#  define DT_T_SEC_COU_REL_UpperLimit (4294967294U)
#  define Rte_InvalidValue_DT_T_SEC_COU_REL (4294967295U)
#  define InvalidValue_DT_T_SEC_COU_REL (4294967295U)

#  define Rte_TypeDef_DT_UN_PO_EPS
typedef uint8 DT_UN_PO_EPS;
#  define DT_UN_PO_EPS_LowerLimit (0U)
#  define DT_UN_PO_EPS_UpperLimit (3U)
#  define Rte_InvalidValue_DT_UN_PO_EPS (3U)
#  define InvalidValue_DT_UN_PO_EPS (3U)

#  define Rte_TypeDef_DT_UN_TOT_STR_EPS
typedef uint8 DT_UN_TOT_STR_EPS;
#  define DT_UN_TOT_STR_EPS_LowerLimit (0U)
#  define DT_UN_TOT_STR_EPS_UpperLimit (3U)
#  define Rte_InvalidValue_DT_UN_TOT_STR_EPS (3U)
#  define InvalidValue_DT_UN_TOT_STR_EPS (3U)

#  define Rte_TypeDef_DT_VYAW_VEH
typedef uint16 DT_VYAW_VEH;
#  define DT_VYAW_VEH_LowerLimit (0U)
#  define DT_VYAW_VEH_UpperLimit (65534U)
#  define Rte_InvalidValue_DT_VYAW_VEH (163U)
#  define InvalidValue_DT_VYAW_VEH (163U)

#  define Rte_TypeDef_DT_V_VEH_COG
typedef uint16 DT_V_VEH_COG;
#  define DT_V_VEH_COG_LowerLimit (0U)
#  define DT_V_VEH_COG_UpperLimit (22400U)
#  define Rte_InvalidValue_DT_V_VEH_COG (65535U)
#  define InvalidValue_DT_V_VEH_COG (65535U)

#  define Rte_TypeDef_DT_XCP_Dummysignal_MST
typedef uint8 DT_XCP_Dummysignal_MST;
#  define DT_XCP_Dummysignal_MST_LowerLimit (0U)
#  define DT_XCP_Dummysignal_MST_UpperLimit (255U)
#  define Rte_InvalidValue_DT_XCP_Dummysignal_MST (255U)
#  define InvalidValue_DT_XCP_Dummysignal_MST (255U)

#  define Rte_TypeDef_DT_XCP_Dummysignal_SLV
typedef uint8 DT_XCP_Dummysignal_SLV;
#  define DT_XCP_Dummysignal_SLV_LowerLimit (0U)
#  define DT_XCP_Dummysignal_SLV_UpperLimit (255U)
#  define Rte_InvalidValue_DT_XCP_Dummysignal_SLV (255U)
#  define InvalidValue_DT_XCP_Dummysignal_SLV (255U)

#  define Rte_TypeDef_DT_XCP_Dummysignal_static
typedef uint8 DT_XCP_Dummysignal_static;
#  define DT_XCP_Dummysignal_static_LowerLimit (0U)
#  define DT_XCP_Dummysignal_static_UpperLimit (255U)
#  define Rte_InvalidValue_DT_XCP_Dummysignal_static (255U)
#  define InvalidValue_DT_XCP_Dummysignal_static (255U)

#  define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;
#  define Dem_DTCStatusMaskType_LowerLimit (0U)
#  define Dem_DTCStatusMaskType_UpperLimit (255U)

#  define Rte_TypeDef_Dem_FaultDetectionCounterType
typedef sint8 Dem_FaultDetectionCounterType;
#  define Dem_FaultDetectionCounterType_LowerLimit (-128)
#  define Dem_FaultDetectionCounterType_UpperLimit (127)

#  define Rte_TypeDef_IoHwAb_CurrentType
typedef uint16 IoHwAb_CurrentType;
#  define IoHwAb_CurrentType_LowerLimit (0U)
#  define IoHwAb_CurrentType_UpperLimit (65535U)

#  define Rte_TypeDef_IoHwAb_DiscreteGroupType
typedef uint8 IoHwAb_DiscreteGroupType;
#  define IoHwAb_DiscreteGroupType_LowerLimit (0U)
#  define IoHwAb_DiscreteGroupType_UpperLimit (255U)

#  define Rte_TypeDef_IoHwAb_PwxDutyCycleType
typedef uint16 IoHwAb_PwxDutyCycleType;
#  define IoHwAb_PwxDutyCycleType_LowerLimit (0U)
#  define IoHwAb_PwxDutyCycleType_UpperLimit (65535U)

#  define Rte_TypeDef_IoHwAb_PwxPeriodType
typedef uint16 IoHwAb_PwxPeriodType;
#  define IoHwAb_PwxPeriodType_LowerLimit (0U)
#  define IoHwAb_PwxPeriodType_UpperLimit (65535U)

#  define Rte_TypeDef_IoHwAb_ResistanceType
typedef uint16 IoHwAb_ResistanceType;
#  define IoHwAb_ResistanceType_LowerLimit (0U)
#  define IoHwAb_ResistanceType_UpperLimit (65535U)

#  define Rte_TypeDef_IoHwAb_SignalDiagnosisType
typedef uint16 IoHwAb_SignalDiagnosisType;
#  define IoHwAb_SignalDiagnosisType_LowerLimit (0U)
#  define IoHwAb_SignalDiagnosisType_UpperLimit (65535U)

#  define Rte_TypeDef_IoHwAb_VoltageType
typedef uint16 IoHwAb_VoltageType;
#  define IoHwAb_VoltageType_LowerLimit (0U)
#  define IoHwAb_VoltageType_UpperLimit (65535U)

#  define Rte_TypeDef_MTR_PKCURR_AMPSSQ
typedef uint16 MTR_PKCURR_AMPSSQ;
#  define MTR_PKCURR_AMPSSQ_LowerLimit (0U)
#  define MTR_PKCURR_AMPSSQ_UpperLimit (65535U)

#  define Rte_TypeDef_ModuleIdType
typedef uint16 ModuleIdType;
#  define ModuleIdType_LowerLimit (0U)
#  define ModuleIdType_UpperLimit (65535U)

#  define Rte_TypeDef_NO_CC
typedef uint16 NO_CC;
#  define NO_CC_LowerLimit (0U)
#  define NO_CC_UpperLimit (65534U)
#  define Rte_InvalidValue_NO_CC (65535U)
#  define InvalidValue_NO_CC (65535U)

#  define Rte_TypeDef_New_Coding_1
typedef uint16 New_Coding_1;
#  define New_Coding_1_LowerLimit (0U)
#  define New_Coding_1_UpperLimit (65535U)

#  define Rte_TypeDef_New_Coding_100
typedef uint8 New_Coding_100[65];
#  define Rte_InvalidValue_New_Coding_100 ("18446744073709552000")
#  define InvalidValue_New_Coding_100 ("18446744073709552000")

#  define Rte_TypeDef_New_Coding_11
typedef sint16 New_Coding_11;
#  define New_Coding_11_LowerLimit (-32768)
#  define New_Coding_11_UpperLimit (32767)

#  define Rte_TypeDef_New_Coding_113
typedef uint8 New_Coding_113;
#  define New_Coding_113_LowerLimit (0U)
#  define New_Coding_113_UpperLimit (255U)

#  define Rte_TypeDef_New_Coding_114
typedef uint8 New_Coding_114;
#  define New_Coding_114_LowerLimit (0U)
#  define New_Coding_114_UpperLimit (14U)
#  define Rte_InvalidValue_New_Coding_114 (15U)
#  define InvalidValue_New_Coding_114 (15U)

#  define Rte_TypeDef_New_Coding_12
typedef sint16 New_Coding_12;
#  define New_Coding_12_LowerLimit (-32768)
#  define New_Coding_12_UpperLimit (32767)

#  define Rte_TypeDef_New_Coding_13
typedef uint16 New_Coding_13;
#  define New_Coding_13_LowerLimit (0U)
#  define New_Coding_13_UpperLimit (65535U)

#  define Rte_TypeDef_New_Coding_14
typedef uint16 New_Coding_14;
#  define New_Coding_14_LowerLimit (0U)
#  define New_Coding_14_UpperLimit (65535U)

#  define Rte_TypeDef_New_Coding_2
typedef sint16 New_Coding_2;
#  define New_Coding_2_LowerLimit (-32768)
#  define New_Coding_2_UpperLimit (32767)

#  define Rte_TypeDef_New_Coding_4
typedef sint16 New_Coding_4;
#  define New_Coding_4_LowerLimit (-32768)
#  define New_Coding_4_UpperLimit (32767)

#  define Rte_TypeDef_New_Coding_5
typedef sint16 New_Coding_5;
#  define New_Coding_5_LowerLimit (-32768)
#  define New_Coding_5_UpperLimit (32767)

#  define Rte_TypeDef_New_Coding_6
typedef sint16 New_Coding_6;
#  define New_Coding_6_LowerLimit (-32768)
#  define New_Coding_6_UpperLimit (32767)

#  define Rte_TypeDef_New_Coding_7
typedef uint8 New_Coding_7;
#  define New_Coding_7_LowerLimit (0U)
#  define New_Coding_7_UpperLimit (255U)

#  define Rte_TypeDef_New_Coding_8
typedef uint8 New_Coding_8;
#  define New_Coding_8_LowerLimit (0U)
#  define New_Coding_8_UpperLimit (255U)

#  define Rte_TypeDef_New_Coding_84
typedef uint8 New_Coding_84;
#  define New_Coding_84_LowerLimit (0U)
#  define New_Coding_84_UpperLimit (255U)

#  define Rte_TypeDef_New_Coding_86
typedef uint16 New_Coding_86;
#  define New_Coding_86_LowerLimit (7167U)
#  define New_Coding_86_UpperLimit (58367U)
#  define Rte_InvalidValue_New_Coding_86 (65535U)
#  define InvalidValue_New_Coding_86 (65535U)

#  define Rte_TypeDef_New_Coding_87
typedef uint16 New_Coding_87;
#  define New_Coding_87_LowerLimit (7167U)
#  define New_Coding_87_UpperLimit (58367U)
#  define Rte_InvalidValue_New_Coding_87 (65535U)
#  define InvalidValue_New_Coding_87 (65535U)

#  define Rte_TypeDef_New_Coding_88
typedef uint16 New_Coding_88;
#  define New_Coding_88_LowerLimit (7167U)
#  define New_Coding_88_UpperLimit (58367U)
#  define Rte_InvalidValue_New_Coding_88 (65535U)
#  define InvalidValue_New_Coding_88 (65535U)

#  define Rte_TypeDef_New_Coding_89
typedef uint16 New_Coding_89;
#  define New_Coding_89_LowerLimit (7167U)
#  define New_Coding_89_UpperLimit (58367U)
#  define Rte_InvalidValue_New_Coding_89 (65535U)
#  define InvalidValue_New_Coding_89 (65535U)

#  define Rte_TypeDef_New_Coding_9
typedef uint8 New_Coding_9;
#  define New_Coding_9_LowerLimit (0U)
#  define New_Coding_9_UpperLimit (255U)

#  define Rte_TypeDef_RES_TBD
typedef uint16 RES_TBD;
#  define RES_TBD_LowerLimit (0U)
#  define RES_TBD_UpperLimit (65535U)

#  define Rte_TypeDef_SInt4
typedef sint8 SInt4;
#  define SInt4_LowerLimit (-8)
#  define SInt4_UpperLimit (7)

#  define Rte_TypeDef_SPEC_PWR_EL_EPS_MAX
typedef uint8 SPEC_PWR_EL_EPS_MAX;
#  define SPEC_PWR_EL_EPS_MAX_LowerLimit (0U)
#  define SPEC_PWR_EL_EPS_MAX_UpperLimit (255U)
#  define Rte_InvalidValue_SPEC_PWR_EL_EPS_MAX (255U)
#  define InvalidValue_SPEC_PWR_EL_EPS_MAX (255U)

#  define Rte_TypeDef_ST_I_IBS
typedef uint16 ST_I_IBS;
#  define ST_I_IBS_LowerLimit (0U)
#  define ST_I_IBS_UpperLimit (60000U)
#  define Rte_InvalidValue_ST_I_IBS (65535U)
#  define InvalidValue_ST_I_IBS (65535U)

#  define Rte_TypeDef_TARVL_PMA
typedef uint16 TARVL_PMA;
#  define TARVL_PMA_LowerLimit (0U)
#  define TARVL_PMA_UpperLimit (65534U)
#  define Rte_InvalidValue_TARVL_PMA (65535U)
#  define InvalidValue_TARVL_PMA (65535U)

#  define Rte_TypeDef_TEMP_EX_UNFILT
typedef uint8 TEMP_EX_UNFILT;
#  define TEMP_EX_UNFILT_LowerLimit (0U)
#  define TEMP_EX_UNFILT_UpperLimit (250U)
#  define Rte_InvalidValue_TEMP_EX_UNFILT (255U)
#  define InvalidValue_TEMP_EX_UNFILT (255U)

#  define Rte_TypeDef_UI_32_noIniVal_noDflVal_4294967295_1_0_noEnc_hasRng
typedef uint32 UI_32_noIniVal_noDflVal_4294967295_1_0_noEnc_hasRng;
#  define UI_32_noIniVal_noDflVal_4294967295_1_0_noEnc_hasRng_LowerLimit (0U)
#  define UI_32_noIniVal_noDflVal_4294967295_1_0_noEnc_hasRng_UpperLimit (4294967294U)
#  define Rte_InvalidValue_UI_32_noIniVal_noDflVal_4294967295_1_0_noEnc_hasRng (4294967295U)
#  define InvalidValue_UI_32_noIniVal_noDflVal_4294967295_1_0_noEnc_hasRng (4294967295U)

#  define Rte_TypeDef_UI_8_noIniVal_noDflVal_255_0_50s_MI_40_noEnc_hasRng
typedef uint8 UI_8_noIniVal_noDflVal_255_0_50s_MI_40_noEnc_hasRng;
#  define UI_8_noIniVal_noDflVal_255_0_50s_MI_40_noEnc_hasRng_LowerLimit (0U)
#  define UI_8_noIniVal_noDflVal_255_0_50s_MI_40_noEnc_hasRng_UpperLimit (250U)
#  define Rte_InvalidValue_UI_8_noIniVal_noDflVal_255_0_50s_MI_40_noEnc_hasRng (255U)
#  define InvalidValue_UI_8_noIniVal_noDflVal_255_0_50s_MI_40_noEnc_hasRng (255U)

#  define Rte_TypeDef_UI_8_noIniVal_noDflVal_255_0_50s__40_noEnc_hasRng
typedef uint8 UI_8_noIniVal_noDflVal_255_0_50s__40_noEnc_hasRng;
#  define UI_8_noIniVal_noDflVal_255_0_50s__40_noEnc_hasRng_LowerLimit (0U)
#  define UI_8_noIniVal_noDflVal_255_0_50s__40_noEnc_hasRng_UpperLimit (250U)
#  define Rte_InvalidValue_UI_8_noIniVal_noDflVal_255_0_50s__40_noEnc_hasRng (255U)
#  define InvalidValue_UI_8_noIniVal_noDflVal_255_0_50s__40_noEnc_hasRng (255U)

#  define Rte_TypeDef_UI_8_noIniVal_noDflVal_255_1_0_noEnc_hasRng__12
typedef uint8 UI_8_noIniVal_noDflVal_255_1_0_noEnc_hasRng__12;
#  define UI_8_noIniVal_noDflVal_255_1_0_noEnc_hasRng__12_LowerLimit (0U)
#  define UI_8_noIniVal_noDflVal_255_1_0_noEnc_hasRng__12_UpperLimit (254U)
#  define Rte_InvalidValue_UI_8_noIniVal_noDflVal_255_1_0_noEnc_hasRng__12 (255U)
#  define InvalidValue_UI_8_noIniVal_noDflVal_255_1_0_noEnc_hasRng__12 (255U)

#  define Rte_TypeDef_UInt12
typedef uint16 UInt12;
#  define UInt12_LowerLimit (0U)
#  define UInt12_UpperLimit (4095U)

#  define Rte_TypeDef_UInt5
typedef uint8 UInt5;
#  define UInt5_LowerLimit (0U)
#  define UInt5_UpperLimit (31U)

#  define Rte_TypeDef_WUR_BYTE
typedef uint8 WUR_BYTE;
#  define WUR_BYTE_LowerLimit (0U)
#  define WUR_BYTE_UpperLimit (255U)
#  define Rte_InvalidValue_WUR_BYTE (255U)
#  define InvalidValue_WUR_BYTE (255U)

#  define Rte_TypeDef_WUR_ID2
typedef uint8 WUR_ID2;
#  define WUR_ID2_LowerLimit (0U)
#  define WUR_ID2_UpperLimit (255U)
#  define Rte_InvalidValue_WUR_ID2 (255U)
#  define InvalidValue_WUR_ID2 (255U)

#  define Rte_TypeDef_APA_State_enum
typedef uint8 APA_State_enum;
#  define APA_State_enum_LowerLimit (0U)
#  define APA_State_enum_UpperLimit (4U)
#  if (defined RTE_CONST_APA_TempInhibit) || (defined APA_TempInhibit)
#   if (!defined RTE_CONST_APA_TempInhibit) || (RTE_CONST_APA_TempInhibit != 0U)
#    error "Enumeration constant <APA_TempInhibit> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_APA_TempInhibit (0U)
#   define APA_TempInhibit (0U)
#  endif
#  if (defined RTE_CONST_APA_AvailCntrl) || (defined APA_AvailCntrl)
#   if (!defined RTE_CONST_APA_AvailCntrl) || (RTE_CONST_APA_AvailCntrl != 1U)
#    error "Enumeration constant <APA_AvailCntrl> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_APA_AvailCntrl (1U)
#   define APA_AvailCntrl (1U)
#  endif
#  if (defined RTE_CONST_APA_Active) || (defined APA_Active)
#   if (!defined RTE_CONST_APA_Active) || (RTE_CONST_APA_Active != 2U)
#    error "Enumeration constant <APA_Active> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_APA_Active (2U)
#   define APA_Active (2U)
#  endif
#  if (defined RTE_CONST_APA_PermanentlyFailed) || (defined APA_PermanentlyFailed)
#   if (!defined RTE_CONST_APA_PermanentlyFailed) || (RTE_CONST_APA_PermanentlyFailed != 3U)
#    error "Enumeration constant <APA_PermanentlyFailed> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_APA_PermanentlyFailed (3U)
#   define APA_PermanentlyFailed (3U)
#  endif
#  if (defined RTE_CONST_APA_ManufacturingDisable) || (defined APA_ManufacturingDisable)
#   if (!defined RTE_CONST_APA_ManufacturingDisable) || (RTE_CONST_APA_ManufacturingDisable != 4U)
#    error "Enumeration constant <APA_ManufacturingDisable> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_APA_ManufacturingDisable (4U)
#   define APA_ManufacturingDisable (4U)
#  endif

#  define Rte_TypeDef_AVL_MOD_SW_DRDY_2
typedef uint8 AVL_MOD_SW_DRDY_2;
#  define AVL_MOD_SW_DRDY_2_LowerLimit (0U)
#  define AVL_MOD_SW_DRDY_2_UpperLimit (15U)
#  define Rte_InvalidValue_AVL_MOD_SW_DRDY_2 (15U)
#  define InvalidValue_AVL_MOD_SW_DRDY_2 (15U)
#  if (defined RTE_CONST_Cx0_Initialisierung) || (defined Cx0_Initialisierung)
#   if (!defined RTE_CONST_Cx0_Initialisierung) || (RTE_CONST_Cx0_Initialisierung != 0U)
#    error "Enumeration constant <Cx0_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Initialisierung (0U)
#   define Cx0_Initialisierung (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Modus_Traction_gesetzt) || (defined Cx1_Modus_Traction_gesetzt)
#   if (!defined RTE_CONST_Cx1_Modus_Traction_gesetzt) || (RTE_CONST_Cx1_Modus_Traction_gesetzt != 1U)
#    error "Enumeration constant <Cx1_Modus_Traction_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Modus_Traction_gesetzt (1U)
#   define Cx1_Modus_Traction_gesetzt (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Modus_Komfort_gesetzt) || (defined Cx2_Modus_Komfort_gesetzt)
#   if (!defined RTE_CONST_Cx2_Modus_Komfort_gesetzt) || (RTE_CONST_Cx2_Modus_Komfort_gesetzt != 2U)
#    error "Enumeration constant <Cx2_Modus_Komfort_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Modus_Komfort_gesetzt (2U)
#   define Cx2_Modus_Komfort_gesetzt (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Modus_Basis_gesetzt) || (defined Cx3_Modus_Basis_gesetzt)
#   if (!defined RTE_CONST_Cx3_Modus_Basis_gesetzt) || (RTE_CONST_Cx3_Modus_Basis_gesetzt != 3U)
#    error "Enumeration constant <Cx3_Modus_Basis_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Modus_Basis_gesetzt (3U)
#   define Cx3_Modus_Basis_gesetzt (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Modus_Sport_gesetzt) || (defined Cx4_Modus_Sport_gesetzt)
#   if (!defined RTE_CONST_Cx4_Modus_Sport_gesetzt) || (RTE_CONST_Cx4_Modus_Sport_gesetzt != 4U)
#    error "Enumeration constant <Cx4_Modus_Sport_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Modus_Sport_gesetzt (4U)
#   define Cx4_Modus_Sport_gesetzt (4U)
#  endif
#  if (defined RTE_CONST_Cx5_Modus_Sport__gesetzt) || (defined Cx5_Modus_Sport__gesetzt)
#   if (!defined RTE_CONST_Cx5_Modus_Sport__gesetzt) || (RTE_CONST_Cx5_Modus_Sport__gesetzt != 5U)
#    error "Enumeration constant <Cx5_Modus_Sport__gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx5_Modus_Sport__gesetzt (5U)
#   define Cx5_Modus_Sport__gesetzt (5U)
#  endif
#  if (defined RTE_CONST_Cx6_Modus_Race_gesetzt) || (defined Cx6_Modus_Race_gesetzt)
#   if (!defined RTE_CONST_Cx6_Modus_Race_gesetzt) || (RTE_CONST_Cx6_Modus_Race_gesetzt != 6U)
#    error "Enumeration constant <Cx6_Modus_Race_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Modus_Race_gesetzt (6U)
#   define Cx6_Modus_Race_gesetzt (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Modus_ECO_gesetzt) || (defined Cx7_Modus_ECO_gesetzt)
#   if (!defined RTE_CONST_Cx7_Modus_ECO_gesetzt) || (RTE_CONST_Cx7_Modus_ECO_gesetzt != 7U)
#    error "Enumeration constant <Cx7_Modus_ECO_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Modus_ECO_gesetzt (7U)
#   define Cx7_Modus_ECO_gesetzt (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Modus_ECO__gesetzt) || (defined Cx8_Modus_ECO__gesetzt)
#   if (!defined RTE_CONST_Cx8_Modus_ECO__gesetzt) || (RTE_CONST_Cx8_Modus_ECO__gesetzt != 8U)
#    error "Enumeration constant <Cx8_Modus_ECO__gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Modus_ECO__gesetzt (8U)
#   define Cx8_Modus_ECO__gesetzt (8U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_AVL_MOD_SW_DRDY_STAB
typedef uint8 AVL_MOD_SW_DRDY_STAB;
#  define AVL_MOD_SW_DRDY_STAB_LowerLimit (0U)
#  define AVL_MOD_SW_DRDY_STAB_UpperLimit (15U)
#  define Rte_InvalidValue_AVL_MOD_SW_DRDY_STAB (15U)
#  define InvalidValue_AVL_MOD_SW_DRDY_STAB (15U)
#  if (defined RTE_CONST_Cx0_Initialisierung) || (defined Cx0_Initialisierung)
#   if (!defined RTE_CONST_Cx0_Initialisierung) || (RTE_CONST_Cx0_Initialisierung != 0U)
#    error "Enumeration constant <Cx0_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Initialisierung (0U)
#   define Cx0_Initialisierung (0U)
#  endif
#  if (defined RTE_CONST_Cx1_EIN) || (defined Cx1_EIN)
#   if (!defined RTE_CONST_Cx1_EIN) || (RTE_CONST_Cx1_EIN != 1U)
#    error "Enumeration constant <Cx1_EIN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_EIN (1U)
#   define Cx1_EIN (1U)
#  endif
#  if (defined RTE_CONST_Cx2_eingeschraenkt) || (defined Cx2_eingeschraenkt)
#   if (!defined RTE_CONST_Cx2_eingeschraenkt) || (RTE_CONST_Cx2_eingeschraenkt != 2U)
#    error "Enumeration constant <Cx2_eingeschraenkt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_eingeschraenkt (2U)
#   define Cx2_eingeschraenkt (2U)
#  endif
#  if (defined RTE_CONST_Cx3_AUS_mit_optimiertem_Handling) || (defined Cx3_AUS_mit_optimiertem_Handling)
#   if (!defined RTE_CONST_Cx3_AUS_mit_optimiertem_Handling) || (RTE_CONST_Cx3_AUS_mit_optimiertem_Handling != 3U)
#    error "Enumeration constant <Cx3_AUS_mit_optimiertem_Handling> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_AUS_mit_optimiertem_Handling (3U)
#   define Cx3_AUS_mit_optimiertem_Handling (3U)
#  endif
#  if (defined RTE_CONST_Cx4_AUS) || (defined Cx4_AUS)
#   if (!defined RTE_CONST_Cx4_AUS) || (RTE_CONST_Cx4_AUS != 4U)
#    error "Enumeration constant <Cx4_AUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_AUS (4U)
#   define Cx4_AUS (4U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_DISP_ST_DSC
typedef uint8 DISP_ST_DSC;
#  define DISP_ST_DSC_LowerLimit (0U)
#  define DISP_ST_DSC_UpperLimit (15U)
#  define Rte_InvalidValue_DISP_ST_DSC (15U)
#  define InvalidValue_DISP_ST_DSC (15U)
#  if (defined RTE_CONST_Cx0_DSC_EIN) || (defined Cx0_DSC_EIN)
#   if (!defined RTE_CONST_Cx0_DSC_EIN) || (RTE_CONST_Cx0_DSC_EIN != 0U)
#    error "Enumeration constant <Cx0_DSC_EIN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_DSC_EIN (0U)
#   define Cx0_DSC_EIN (0U)
#  endif
#  if (defined RTE_CONST_Cx1_DSC_AUS) || (defined Cx1_DSC_AUS)
#   if (!defined RTE_CONST_Cx1_DSC_AUS) || (RTE_CONST_Cx1_DSC_AUS != 1U)
#    error "Enumeration constant <Cx1_DSC_AUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_DSC_AUS (1U)
#   define Cx1_DSC_AUS (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Anfahrhilfe_aktiv) || (defined Cx2_Anfahrhilfe_aktiv)
#   if (!defined RTE_CONST_Cx2_Anfahrhilfe_aktiv) || (RTE_CONST_Cx2_Anfahrhilfe_aktiv != 2U)
#    error "Enumeration constant <Cx2_Anfahrhilfe_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Anfahrhilfe_aktiv (2U)
#   define Cx2_Anfahrhilfe_aktiv (2U)
#  endif
#  if (defined RTE_CONST_Cx4_Traktionsmodus_EIN) || (defined Cx4_Traktionsmodus_EIN)
#   if (!defined RTE_CONST_Cx4_Traktionsmodus_EIN) || (RTE_CONST_Cx4_Traktionsmodus_EIN != 4U)
#    error "Enumeration constant <Cx4_Traktionsmodus_EIN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Traktionsmodus_EIN (4U)
#   define Cx4_Traktionsmodus_EIN (4U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_DT_RampType
typedef uint8 DT_RampType;
#  define DT_RampType_LowerLimit (0U)
#  define DT_RampType_UpperLimit (2U)
#  if (defined RTE_CONST_RAMP_TYPE_LINEAR) || (defined RAMP_TYPE_LINEAR)
#   if (!defined RTE_CONST_RAMP_TYPE_LINEAR) || (RTE_CONST_RAMP_TYPE_LINEAR != 0U)
#    error "Enumeration constant <RAMP_TYPE_LINEAR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RAMP_TYPE_LINEAR (0U)
#   define RAMP_TYPE_LINEAR (0U)
#  endif
#  if (defined RTE_CONST_RAMP_TYPE_F1) || (defined RAMP_TYPE_F1)
#   if (!defined RTE_CONST_RAMP_TYPE_F1) || (RTE_CONST_RAMP_TYPE_F1 != 1U)
#    error "Enumeration constant <RAMP_TYPE_F1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RAMP_TYPE_F1 (1U)
#   define RAMP_TYPE_F1 (1U)
#  endif
#  if (defined RTE_CONST_RAMP_TYPE_F2) || (defined RAMP_TYPE_F2)
#   if (!defined RTE_CONST_RAMP_TYPE_F2) || (RTE_CONST_RAMP_TYPE_F2 != 2U)
#    error "Enumeration constant <RAMP_TYPE_F2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RAMP_TYPE_F2 (2U)
#   define RAMP_TYPE_F2 (2U)
#  endif

#  define Rte_TypeDef_DT_ST_KL_15N
typedef uint8 DT_ST_KL_15N;
#  define DT_ST_KL_15N_LowerLimit (0U)
#  define DT_ST_KL_15N_UpperLimit (15U)
#  define Rte_InvalidValue_DT_ST_KL_15N (15U)
#  define InvalidValue_DT_ST_KL_15N (15U)
#  if (defined RTE_CONST_Cx0_Init_Wert) || (defined Cx0_Init_Wert)
#   if (!defined RTE_CONST_Cx0_Init_Wert) || (RTE_CONST_Cx0_Init_Wert != 0U)
#    error "Enumeration constant <Cx0_Init_Wert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Init_Wert (0U)
#   define Cx0_Init_Wert (0U)
#  endif
#  if (defined RTE_CONST_Cx1_KL15N_Aus) || (defined Cx1_KL15N_Aus)
#   if (!defined RTE_CONST_Cx1_KL15N_Aus) || (RTE_CONST_Cx1_KL15N_Aus != 1U)
#    error "Enumeration constant <Cx1_KL15N_Aus> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_KL15N_Aus (1U)
#   define Cx1_KL15N_Aus (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms) || (defined Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms)
#   if (!defined RTE_CONST_Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms) || (RTE_CONST_Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms != 2U)
#    error "Enumeration constant <Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms (2U)
#   define Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms) || (defined Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms)
#   if (!defined RTE_CONST_Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms) || (RTE_CONST_Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms != 3U)
#    error "Enumeration constant <Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms (3U)
#   define Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms) || (defined Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms)
#   if (!defined RTE_CONST_Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms) || (RTE_CONST_Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms != 4U)
#    error "Enumeration constant <Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms (4U)
#   define Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms (4U)
#  endif
#  if (defined RTE_CONST_Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms) || (defined Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms)
#   if (!defined RTE_CONST_Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms) || (RTE_CONST_Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms != 5U)
#    error "Enumeration constant <Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms (5U)
#   define Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms (5U)
#  endif
#  if (defined RTE_CONST_Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms) || (defined Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms)
#   if (!defined RTE_CONST_Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms) || (RTE_CONST_Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms != 6U)
#    error "Enumeration constant <Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms (6U)
#   define Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Reserviert) || (defined Cx7_Reserviert)
#   if (!defined RTE_CONST_Cx7_Reserviert) || (RTE_CONST_Cx7_Reserviert != 7U)
#    error "Enumeration constant <Cx7_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Reserviert (7U)
#   define Cx7_Reserviert (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Reserviert) || (defined Cx8_Reserviert)
#   if (!defined RTE_CONST_Cx8_Reserviert) || (RTE_CONST_Cx8_Reserviert != 8U)
#    error "Enumeration constant <Cx8_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Reserviert (8U)
#   define Cx8_Reserviert (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Reserviert) || (defined Cx9_Reserviert)
#   if (!defined RTE_CONST_Cx9_Reserviert) || (RTE_CONST_Cx9_Reserviert != 9U)
#    error "Enumeration constant <Cx9_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Reserviert (9U)
#   define Cx9_Reserviert (9U)
#  endif
#  if (defined RTE_CONST_CxA_Reserviert) || (defined CxA_Reserviert)
#   if (!defined RTE_CONST_CxA_Reserviert) || (RTE_CONST_CxA_Reserviert != 10U)
#    error "Enumeration constant <CxA_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Reserviert (10U)
#   define CxA_Reserviert (10U)
#  endif
#  if (defined RTE_CONST_CxB_Nachlauf_kleiner_1_min) || (defined CxB_Nachlauf_kleiner_1_min)
#   if (!defined RTE_CONST_CxB_Nachlauf_kleiner_1_min) || (RTE_CONST_CxB_Nachlauf_kleiner_1_min != 11U)
#    error "Enumeration constant <CxB_Nachlauf_kleiner_1_min> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_Nachlauf_kleiner_1_min (11U)
#   define CxB_Nachlauf_kleiner_1_min (11U)
#  endif
#  if (defined RTE_CONST_CxC_Nachlauf_Fahrt_Motorlauf) || (defined CxC_Nachlauf_Fahrt_Motorlauf)
#   if (!defined RTE_CONST_CxC_Nachlauf_Fahrt_Motorlauf) || (RTE_CONST_CxC_Nachlauf_Fahrt_Motorlauf != 12U)
#    error "Enumeration constant <CxC_Nachlauf_Fahrt_Motorlauf> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_Nachlauf_Fahrt_Motorlauf (12U)
#   define CxC_Nachlauf_Fahrt_Motorlauf (12U)
#  endif
#  if (defined RTE_CONST_CxD_KL15N_Dauer_Ein) || (defined CxD_KL15N_Dauer_Ein)
#   if (!defined RTE_CONST_CxD_KL15N_Dauer_Ein) || (RTE_CONST_CxD_KL15N_Dauer_Ein != 13U)
#    error "Enumeration constant <CxD_KL15N_Dauer_Ein> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_KL15N_Dauer_Ein (13U)
#   define CxD_KL15N_Dauer_Ein (13U)
#  endif
#  if (defined RTE_CONST_CxE_Fehler) || (defined CxE_Fehler)
#   if (!defined RTE_CONST_CxE_Fehler) || (RTE_CONST_CxE_Fehler != 14U)
#    error "Enumeration constant <CxE_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Fehler (14U)
#   define CxE_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_Dem_ExtendedDataSegmentNumber
typedef uint8 Dem_ExtendedDataSegmentNumber;
#  define Dem_ExtendedDataSegmentNumber_LowerLimit (1U)
#  define Dem_ExtendedDataSegmentNumber_UpperLimit (255U)
#  if (defined RTE_CONST_DEM_EDS_NUM_CONDITION_BYTE) || (defined DEM_EDS_NUM_CONDITION_BYTE)
#   if (!defined RTE_CONST_DEM_EDS_NUM_CONDITION_BYTE) || (RTE_CONST_DEM_EDS_NUM_CONDITION_BYTE != 1U)
#    error "Enumeration constant <DEM_EDS_NUM_CONDITION_BYTE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_EDS_NUM_CONDITION_BYTE (1U)
#   define DEM_EDS_NUM_CONDITION_BYTE (1U)
#  endif
#  if (defined RTE_CONST_DEM_EDS_NUM_OCCURRENCE_COUNTER) || (defined DEM_EDS_NUM_OCCURRENCE_COUNTER)
#   if (!defined RTE_CONST_DEM_EDS_NUM_OCCURRENCE_COUNTER) || (RTE_CONST_DEM_EDS_NUM_OCCURRENCE_COUNTER != 2U)
#    error "Enumeration constant <DEM_EDS_NUM_OCCURRENCE_COUNTER> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_EDS_NUM_OCCURRENCE_COUNTER (2U)
#   define DEM_EDS_NUM_OCCURRENCE_COUNTER (2U)
#  endif
#  if (defined RTE_CONST_DEM_EDS_NUM_HEALING_COUNTER) || (defined DEM_EDS_NUM_HEALING_COUNTER)
#   if (!defined RTE_CONST_DEM_EDS_NUM_HEALING_COUNTER) || (RTE_CONST_DEM_EDS_NUM_HEALING_COUNTER != 3U)
#    error "Enumeration constant <DEM_EDS_NUM_HEALING_COUNTER> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_EDS_NUM_HEALING_COUNTER (3U)
#   define DEM_EDS_NUM_HEALING_COUNTER (3U)
#  endif

#  define Rte_TypeDef_Dem_FreezeFrameSegmentDataID
typedef uint16 Dem_FreezeFrameSegmentDataID;
#  define Dem_FreezeFrameSegmentDataID_LowerLimit (1U)
#  define Dem_FreezeFrameSegmentDataID_UpperLimit (65535U)
#  if (defined RTE_CONST_DEM_FFS_DID_SS_STRWHL_ANGLE) || (defined DEM_FFS_DID_SS_STRWHL_ANGLE)
#   if (!defined RTE_CONST_DEM_FFS_DID_SS_STRWHL_ANGLE) || (RTE_CONST_DEM_FFS_DID_SS_STRWHL_ANGLE != 20483U)
#    error "Enumeration constant <DEM_FFS_DID_SS_STRWHL_ANGLE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_SS_STRWHL_ANGLE (20483U)
#   define DEM_FFS_DID_SS_STRWHL_ANGLE (20483U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_SS_ST_DRV_VEH) || (defined DEM_FFS_DID_SS_ST_DRV_VEH)
#   if (!defined RTE_CONST_DEM_FFS_DID_SS_ST_DRV_VEH) || (RTE_CONST_DEM_FFS_DID_SS_ST_DRV_VEH != 20484U)
#    error "Enumeration constant <DEM_FFS_DID_SS_ST_DRV_VEH> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_SS_ST_DRV_VEH (20484U)
#   define DEM_FFS_DID_SS_ST_DRV_VEH (20484U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_SS_ECU_VLTS_SUPP) || (defined DEM_FFS_DID_SS_ECU_VLTS_SUPP)
#   if (!defined RTE_CONST_DEM_FFS_DID_SS_ECU_VLTS_SUPP) || (RTE_CONST_DEM_FFS_DID_SS_ECU_VLTS_SUPP != 20486U)
#    error "Enumeration constant <DEM_FFS_DID_SS_ECU_VLTS_SUPP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_SS_ECU_VLTS_SUPP (20486U)
#   define DEM_FFS_DID_SS_ECU_VLTS_SUPP (20486U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_SS_VEHSPD) || (defined DEM_FFS_DID_SS_VEHSPD)
#   if (!defined RTE_CONST_DEM_FFS_DID_SS_VEHSPD) || (RTE_CONST_DEM_FFS_DID_SS_VEHSPD != 20490U)
#    error "Enumeration constant <DEM_FFS_DID_SS_VEHSPD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_SS_VEHSPD (20490U)
#   define DEM_FFS_DID_SS_VEHSPD (20490U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_SS_PSCM_STATUS) || (defined DEM_FFS_DID_SS_PSCM_STATUS)
#   if (!defined RTE_CONST_DEM_FFS_DID_SS_PSCM_STATUS) || (RTE_CONST_DEM_FFS_DID_SS_PSCM_STATUS != 20492U)
#    error "Enumeration constant <DEM_FFS_DID_SS_PSCM_STATUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_SS_PSCM_STATUS (20492U)
#   define DEM_FFS_DID_SS_PSCM_STATUS (20492U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_SS_HW_TRQ) || (defined DEM_FFS_DID_SS_HW_TRQ)
#   if (!defined RTE_CONST_DEM_FFS_DID_SS_HW_TRQ) || (RTE_CONST_DEM_FFS_DID_SS_HW_TRQ != 20494U)
#    error "Enumeration constant <DEM_FFS_DID_SS_HW_TRQ> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_SS_HW_TRQ (20494U)
#   define DEM_FFS_DID_SS_HW_TRQ (20494U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_SS_CMD_MTR_TRQ) || (defined DEM_FFS_DID_SS_CMD_MTR_TRQ)
#   if (!defined RTE_CONST_DEM_FFS_DID_SS_CMD_MTR_TRQ) || (RTE_CONST_DEM_FFS_DID_SS_CMD_MTR_TRQ != 20495U)
#    error "Enumeration constant <DEM_FFS_DID_SS_CMD_MTR_TRQ> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_SS_CMD_MTR_TRQ (20495U)
#   define DEM_FFS_DID_SS_CMD_MTR_TRQ (20495U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_SS_NTC_NUM) || (defined DEM_FFS_DID_SS_NTC_NUM)
#   if (!defined RTE_CONST_DEM_FFS_DID_SS_NTC_NUM) || (RTE_CONST_DEM_FFS_DID_SS_NTC_NUM != 20530U)
#    error "Enumeration constant <DEM_FFS_DID_SS_NTC_NUM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_SS_NTC_NUM (20530U)
#   define DEM_FFS_DID_SS_NTC_NUM (20530U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_KILOMETER) || (defined DEM_FFS_DID_KILOMETER)
#   if (!defined RTE_CONST_DEM_FFS_DID_KILOMETER) || (RTE_CONST_DEM_FFS_DID_KILOMETER != 5888U)
#    error "Enumeration constant <DEM_FFS_DID_KILOMETER> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_KILOMETER (5888U)
#   define DEM_FFS_DID_KILOMETER (5888U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_ABSOLUTE_TIME) || (defined DEM_FFS_DID_ABSOLUTE_TIME)
#   if (!defined RTE_CONST_DEM_FFS_DID_ABSOLUTE_TIME) || (RTE_CONST_DEM_FFS_DID_ABSOLUTE_TIME != 5889U)
#    error "Enumeration constant <DEM_FFS_DID_ABSOLUTE_TIME> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_ABSOLUTE_TIME (5889U)
#   define DEM_FFS_DID_ABSOLUTE_TIME (5889U)
#  endif
#  if (defined RTE_CONST_DEM_FFS_DID_CSM_ERROR_CODE) || (defined DEM_FFS_DID_CSM_ERROR_CODE)
#   if (!defined RTE_CONST_DEM_FFS_DID_CSM_ERROR_CODE) || (RTE_CONST_DEM_FFS_DID_CSM_ERROR_CODE != 5890U)
#    error "Enumeration constant <DEM_FFS_DID_CSM_ERROR_CODE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_FFS_DID_CSM_ERROR_CODE (5890U)
#   define DEM_FFS_DID_CSM_ERROR_CODE (5890U)
#  endif

#  define Rte_TypeDef_Dem_InitMonitorKindType
typedef uint8 Dem_InitMonitorKindType;
#  define Dem_InitMonitorKindType_LowerLimit (1U)
#  define Dem_InitMonitorKindType_UpperLimit (3U)
#  if (defined RTE_CONST_DEM_INIT_MONITOR_CLEAR) || (defined DEM_INIT_MONITOR_CLEAR)
#   if (!defined RTE_CONST_DEM_INIT_MONITOR_CLEAR) || (RTE_CONST_DEM_INIT_MONITOR_CLEAR != 1U)
#    error "Enumeration constant <DEM_INIT_MONITOR_CLEAR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INIT_MONITOR_CLEAR (1U)
#   define DEM_INIT_MONITOR_CLEAR (1U)
#  endif
#  if (defined RTE_CONST_DEM_INIT_MONITOR_RESTART) || (defined DEM_INIT_MONITOR_RESTART)
#   if (!defined RTE_CONST_DEM_INIT_MONITOR_RESTART) || (RTE_CONST_DEM_INIT_MONITOR_RESTART != 2U)
#    error "Enumeration constant <DEM_INIT_MONITOR_RESTART> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INIT_MONITOR_RESTART (2U)
#   define DEM_INIT_MONITOR_RESTART (2U)
#  endif
#  if (defined RTE_CONST_DEM_INIT_MONITOR_END) || (defined DEM_INIT_MONITOR_END)
#   if (!defined RTE_CONST_DEM_INIT_MONITOR_END) || (RTE_CONST_DEM_INIT_MONITOR_END != 3U)
#    error "Enumeration constant <DEM_INIT_MONITOR_END> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_INIT_MONITOR_END (3U)
#   define DEM_INIT_MONITOR_END (3U)
#  endif

#  define Rte_TypeDef_ENUM_ResetCause
typedef uint32 ENUM_ResetCause;
#  define ENUM_ResetCause_LowerLimit (0U)
#  define ENUM_ResetCause_UpperLimit (4294967295U)
#  if (defined RTE_CONST_DATA_ABORT) || (defined DATA_ABORT)
#   if (!defined RTE_CONST_DATA_ABORT) || (RTE_CONST_DATA_ABORT != 4294836225U)
#    error "Enumeration constant <DATA_ABORT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DATA_ABORT (4294836225U)
#   define DATA_ABORT (4294836225U)
#  endif
#  if (defined RTE_CONST_PREFETCH_ABORT) || (defined PREFETCH_ABORT)
#   if (!defined RTE_CONST_PREFETCH_ABORT) || (RTE_CONST_PREFETCH_ABORT != 4294770690U)
#    error "Enumeration constant <PREFETCH_ABORT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PREFETCH_ABORT (4294770690U)
#   define PREFETCH_ABORT (4294770690U)
#  endif
#  if (defined RTE_CONST_UND_INSTR) || (defined UND_INSTR)
#   if (!defined RTE_CONST_UND_INSTR) || (RTE_CONST_UND_INSTR != 4294705155U)
#    error "Enumeration constant <UND_INSTR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_UND_INSTR (4294705155U)
#   define UND_INSTR (4294705155U)
#  endif
#  if (defined RTE_CONST_STACK_OVERWRITE) || (defined STACK_OVERWRITE)
#   if (!defined RTE_CONST_STACK_OVERWRITE) || (RTE_CONST_STACK_OVERWRITE != 4294639620U)
#    error "Enumeration constant <STACK_OVERWRITE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STACK_OVERWRITE (4294639620U)
#   define STACK_OVERWRITE (4294639620U)
#  endif
#  if (defined RTE_CONST_UNUSED_INTERRUPT) || (defined UNUSED_INTERRUPT)
#   if (!defined RTE_CONST_UNUSED_INTERRUPT) || (RTE_CONST_UNUSED_INTERRUPT != 4294574085U)
#    error "Enumeration constant <UNUSED_INTERRUPT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_UNUSED_INTERRUPT (4294574085U)
#   define UNUSED_INTERRUPT (4294574085U)
#  endif
#  if (defined RTE_CONST_UND_INSTR_TEST) || (defined UND_INSTR_TEST)
#   if (!defined RTE_CONST_UND_INSTR_TEST) || (RTE_CONST_UND_INSTR_TEST != 4294508550U)
#    error "Enumeration constant <UND_INSTR_TEST> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_UND_INSTR_TEST (4294508550U)
#   define UND_INSTR_TEST (4294508550U)
#  endif
#  if (defined RTE_CONST_VIM_RAM_PARITY) || (defined VIM_RAM_PARITY)
#   if (!defined RTE_CONST_VIM_RAM_PARITY) || (RTE_CONST_VIM_RAM_PARITY != 4294443016U)
#    error "Enumeration constant <VIM_RAM_PARITY> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_VIM_RAM_PARITY (4294443016U)
#   define VIM_RAM_PARITY (4294443016U)
#  endif
#  if (defined RTE_CONST_ADC2_RAM_PARITY) || (defined ADC2_RAM_PARITY)
#   if (!defined RTE_CONST_ADC2_RAM_PARITY) || (RTE_CONST_ADC2_RAM_PARITY != 4294377481U)
#    error "Enumeration constant <ADC2_RAM_PARITY> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ADC2_RAM_PARITY (4294377481U)
#   define ADC2_RAM_PARITY (4294377481U)
#  endif
#  if (defined RTE_CONST_ADC1_RAM_PARITY) || (defined ADC1_RAM_PARITY)
#   if (!defined RTE_CONST_ADC1_RAM_PARITY) || (RTE_CONST_ADC1_RAM_PARITY != 4294311946U)
#    error "Enumeration constant <ADC1_RAM_PARITY> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ADC1_RAM_PARITY (4294311946U)
#   define ADC1_RAM_PARITY (4294311946U)
#  endif
#  if (defined RTE_CONST_RAM_ECC_MULTIBIT) || (defined RAM_ECC_MULTIBIT)
#   if (!defined RTE_CONST_RAM_ECC_MULTIBIT) || (RTE_CONST_RAM_ECC_MULTIBIT != 4294901760U)
#    error "Enumeration constant <RAM_ECC_MULTIBIT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RAM_ECC_MULTIBIT (4294901760U)
#   define RAM_ECC_MULTIBIT (4294901760U)
#  endif
#  if (defined RTE_CONST_NHET1_RAM_PARITY) || (defined NHET1_RAM_PARITY)
#   if (!defined RTE_CONST_NHET1_RAM_PARITY) || (RTE_CONST_NHET1_RAM_PARITY != 4294246411U)
#    error "Enumeration constant <NHET1_RAM_PARITY> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NHET1_RAM_PARITY (4294246411U)
#   define NHET1_RAM_PARITY (4294246411U)
#  endif
#  if (defined RTE_CONST_NHET2_RAM_PARITY) || (defined NHET2_RAM_PARITY)
#   if (!defined RTE_CONST_NHET2_RAM_PARITY) || (RTE_CONST_NHET2_RAM_PARITY != 4294180876U)
#    error "Enumeration constant <NHET2_RAM_PARITY> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NHET2_RAM_PARITY (4294180876U)
#   define NHET2_RAM_PARITY (4294180876U)
#  endif
#  if (defined RTE_CONST_NORMAL_RESET) || (defined NORMAL_RESET)
#   if (!defined RTE_CONST_NORMAL_RESET) || (RTE_CONST_NORMAL_RESET != 0U)
#    error "Enumeration constant <NORMAL_RESET> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NORMAL_RESET (0U)
#   define NORMAL_RESET (0U)
#  endif

#  define Rte_TypeDef_ENUM_VPM_Modes
typedef uint8 ENUM_VPM_Modes;
#  define ENUM_VPM_Modes_LowerLimit (0U)
#  define ENUM_VPM_Modes_UpperLimit (3U)
#  if (defined RTE_CONST_VPM_INIT) || (defined VPM_INIT)
#   if (!defined RTE_CONST_VPM_INIT) || (RTE_CONST_VPM_INIT != 0U)
#    error "Enumeration constant <VPM_INIT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_VPM_INIT (0U)
#   define VPM_INIT (0U)
#  endif
#  if (defined RTE_CONST_VPM_PAUSE) || (defined VPM_PAUSE)
#   if (!defined RTE_CONST_VPM_PAUSE) || (RTE_CONST_VPM_PAUSE != 1U)
#    error "Enumeration constant <VPM_PAUSE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_VPM_PAUSE (1U)
#   define VPM_PAUSE (1U)
#  endif
#  if (defined RTE_CONST_VPM_RUN) || (defined VPM_RUN)
#   if (!defined RTE_CONST_VPM_RUN) || (RTE_CONST_VPM_RUN != 2U)
#    error "Enumeration constant <VPM_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_VPM_RUN (2U)
#   define VPM_RUN (2U)
#  endif
#  if (defined RTE_CONST_VPM_POSTRUN) || (defined VPM_POSTRUN)
#   if (!defined RTE_CONST_VPM_POSTRUN) || (RTE_CONST_VPM_POSTRUN != 3U)
#    error "Enumeration constant <VPM_POSTRUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_VPM_POSTRUN (3U)
#   define VPM_POSTRUN (3U)
#  endif

#  define Rte_TypeDef_ESC_State_enum
typedef uint8 ESC_State_enum;
#  define ESC_State_enum_LowerLimit (0U)
#  define ESC_State_enum_UpperLimit (4U)
#  if (defined RTE_CONST_ESC_Inactive) || (defined ESC_Inactive)
#   if (!defined RTE_CONST_ESC_Inactive) || (RTE_CONST_ESC_Inactive != 0U)
#    error "Enumeration constant <ESC_Inactive> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ESC_Inactive (0U)
#   define ESC_Inactive (0U)
#  endif
#  if (defined RTE_CONST_ESC_Active) || (defined ESC_Active)
#   if (!defined RTE_CONST_ESC_Active) || (RTE_CONST_ESC_Active != 1U)
#    error "Enumeration constant <ESC_Active> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ESC_Active (1U)
#   define ESC_Active (1U)
#  endif
#  if (defined RTE_CONST_ESC_TemporarilyLimited) || (defined ESC_TemporarilyLimited)
#   if (!defined RTE_CONST_ESC_TemporarilyLimited) || (RTE_CONST_ESC_TemporarilyLimited != 2U)
#    error "Enumeration constant <ESC_TemporarilyLimited> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ESC_TemporarilyLimited (2U)
#   define ESC_TemporarilyLimited (2U)
#  endif
#  if (defined RTE_CONST_ESC_PermanentlyFailed) || (defined ESC_PermanentlyFailed)
#   if (!defined RTE_CONST_ESC_PermanentlyFailed) || (RTE_CONST_ESC_PermanentlyFailed != 3U)
#    error "Enumeration constant <ESC_PermanentlyFailed> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ESC_PermanentlyFailed (3U)
#   define ESC_PermanentlyFailed (3U)
#  endif
#  if (defined RTE_CONST_ESC_ManufacturingDisable) || (defined ESC_ManufacturingDisable)
#   if (!defined RTE_CONST_ESC_ManufacturingDisable) || (RTE_CONST_ESC_ManufacturingDisable != 4U)
#    error "Enumeration constant <ESC_ManufacturingDisable> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ESC_ManufacturingDisable (4U)
#   define ESC_ManufacturingDisable (4U)
#  endif

#  define Rte_TypeDef_Haptic_State_enum
typedef uint8 Haptic_State_enum;
#  define Haptic_State_enum_LowerLimit (0U)
#  define Haptic_State_enum_UpperLimit (2U)
#  if (defined RTE_CONST_Haptic_Inactive) || (defined Haptic_Inactive)
#   if (!defined RTE_CONST_Haptic_Inactive) || (RTE_CONST_Haptic_Inactive != 0U)
#    error "Enumeration constant <Haptic_Inactive> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Haptic_Inactive (0U)
#   define Haptic_Inactive (0U)
#  endif
#  if (defined RTE_CONST_Haptic_Active) || (defined Haptic_Active)
#   if (!defined RTE_CONST_Haptic_Active) || (RTE_CONST_Haptic_Active != 1U)
#    error "Enumeration constant <Haptic_Active> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Haptic_Active (1U)
#   define Haptic_Active (1U)
#  endif
#  if (defined RTE_CONST_Haptic_Waiting) || (defined Haptic_Waiting)
#   if (!defined RTE_CONST_Haptic_Waiting) || (RTE_CONST_Haptic_Waiting != 2U)
#    error "Enumeration constant <Haptic_Waiting> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Haptic_Waiting (2U)
#   define Haptic_Waiting (2U)
#  endif

#  define Rte_TypeDef_ID_FN_RQ_MSA
typedef uint8 ID_FN_RQ_MSA;
#  define ID_FN_RQ_MSA_LowerLimit (0U)
#  define ID_FN_RQ_MSA_UpperLimit (255U)
#  define Rte_InvalidValue_ID_FN_RQ_MSA (255U)
#  define InvalidValue_ID_FN_RQ_MSA (255U)
#  if (defined RTE_CONST_Cx00_JBBF) || (defined Cx00_JBBF)
#   if (!defined RTE_CONST_Cx00_JBBF) || (RTE_CONST_Cx00_JBBF != 0U)
#    error "Enumeration constant <Cx00_JBBF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx00_JBBF (0U)
#   define Cx00_JBBF (0U)
#  endif
#  if (defined RTE_CONST_Cx10_ZGW) || (defined Cx10_ZGW)
#   if (!defined RTE_CONST_Cx10_ZGW) || (RTE_CONST_Cx10_ZGW != 16U)
#    error "Enumeration constant <Cx10_ZGW> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx10_ZGW (16U)
#   define Cx10_ZGW (16U)
#  endif
#  if (defined RTE_CONST_Cx18_EGS_EL___DKG) || (defined Cx18_EGS_EL___DKG)
#   if (!defined RTE_CONST_Cx18_EGS_EL___DKG) || (RTE_CONST_Cx18_EGS_EL___DKG != 24U)
#    error "Enumeration constant <Cx18_EGS_EL___DKG> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx18_EGS_EL___DKG (24U)
#   define Cx18_EGS_EL___DKG (24U)
#  endif
#  if (defined RTE_CONST_Cx1C_ICM_QL) || (defined Cx1C_ICM_QL)
#   if (!defined RTE_CONST_Cx1C_ICM_QL) || (RTE_CONST_Cx1C_ICM_QL != 28U)
#    error "Enumeration constant <Cx1C_ICM_QL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1C_ICM_QL (28U)
#   define Cx1C_ICM_QL (28U)
#  endif
#  if (defined RTE_CONST_Cx22_SAS) || (defined Cx22_SAS)
#   if (!defined RTE_CONST_Cx22_SAS) || (RTE_CONST_Cx22_SAS != 34U)
#    error "Enumeration constant <Cx22_SAS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx22_SAS (34U)
#   define Cx22_SAS (34U)
#  endif
#  if (defined RTE_CONST_Cx29_DSC_Modul) || (defined Cx29_DSC_Modul)
#   if (!defined RTE_CONST_Cx29_DSC_Modul) || (RTE_CONST_Cx29_DSC_Modul != 41U)
#    error "Enumeration constant <Cx29_DSC_Modul> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx29_DSC_Modul (41U)
#   define Cx29_DSC_Modul (41U)
#  endif
#  if (defined RTE_CONST_Cx2C_PMA) || (defined Cx2C_PMA)
#   if (!defined RTE_CONST_Cx2C_PMA) || (RTE_CONST_Cx2C_PMA != 44U)
#    error "Enumeration constant <Cx2C_PMA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2C_PMA (44U)
#   define Cx2C_PMA (44U)
#  endif
#  if (defined RTE_CONST_Cx30_EPS) || (defined Cx30_EPS)
#   if (!defined RTE_CONST_Cx30_EPS) || (RTE_CONST_Cx30_EPS != 48U)
#    error "Enumeration constant <Cx30_EPS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx30_EPS (48U)
#   define Cx30_EPS (48U)
#  endif
#  if (defined RTE_CONST_Cx37_AMP_HIFI) || (defined Cx37_AMP_HIFI)
#   if (!defined RTE_CONST_Cx37_AMP_HIFI) || (RTE_CONST_Cx37_AMP_HIFI != 55U)
#    error "Enumeration constant <Cx37_AMP_HIFI> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx37_AMP_HIFI (55U)
#   define Cx37_AMP_HIFI (55U)
#  endif
#  if (defined RTE_CONST_Cx38_EHC_2) || (defined Cx38_EHC_2)
#   if (!defined RTE_CONST_Cx38_EHC_2) || (RTE_CONST_Cx38_EHC_2 != 56U)
#    error "Enumeration constant <Cx38_EHC_2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx38_EHC_2 (56U)
#   define Cx38_EHC_2 (56U)
#  endif
#  if (defined RTE_CONST_Cx40_CAS) || (defined Cx40_CAS)
#   if (!defined RTE_CONST_Cx40_CAS) || (RTE_CONST_Cx40_CAS != 64U)
#    error "Enumeration constant <Cx40_CAS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx40_CAS (64U)
#   define Cx40_CAS (64U)
#  endif
#  if (defined RTE_CONST_Cx49_SEC1) || (defined Cx49_SEC1)
#   if (!defined RTE_CONST_Cx49_SEC1) || (RTE_CONST_Cx49_SEC1 != 73U)
#    error "Enumeration constant <Cx49_SEC1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx49_SEC1 (73U)
#   define Cx49_SEC1 (73U)
#  endif
#  if (defined RTE_CONST_Cx71_AHM) || (defined Cx71_AHM)
#   if (!defined RTE_CONST_Cx71_AHM) || (RTE_CONST_Cx71_AHM != 113U)
#    error "Enumeration constant <Cx71_AHM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx71_AHM (113U)
#   define Cx71_AHM (113U)
#  endif
#  if (defined RTE_CONST_Cx78_IHKA) || (defined Cx78_IHKA)
#   if (!defined RTE_CONST_Cx78_IHKA) || (RTE_CONST_Cx78_IHKA != 120U)
#    error "Enumeration constant <Cx78_IHKA> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx78_IHKA (120U)
#   define Cx78_IHKA (120U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255U)
#    error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_ungueltig (255U)
#   define CxFF_Signal_ungueltig (255U)
#  endif

#  define Rte_TypeDef_ID_FN_RQ_STG_EFAN
typedef uint8 ID_FN_RQ_STG_EFAN;
#  define ID_FN_RQ_STG_EFAN_LowerLimit (0U)
#  define ID_FN_RQ_STG_EFAN_UpperLimit (255U)
#  define Rte_InvalidValue_ID_FN_RQ_STG_EFAN (255U)
#  define InvalidValue_ID_FN_RQ_STG_EFAN (255U)
#  if (defined RTE_CONST_Cx01_AFS_Anforderung) || (defined Cx01_AFS_Anforderung)
#   if (!defined RTE_CONST_Cx01_AFS_Anforderung) || (RTE_CONST_Cx01_AFS_Anforderung != 1U)
#    error "Enumeration constant <Cx01_AFS_Anforderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx01_AFS_Anforderung (1U)
#   define Cx01_AFS_Anforderung (1U)
#  endif
#  if (defined RTE_CONST_Cx02_EPS_Anforderung) || (defined Cx02_EPS_Anforderung)
#   if (!defined RTE_CONST_Cx02_EPS_Anforderung) || (RTE_CONST_Cx02_EPS_Anforderung != 2U)
#    error "Enumeration constant <Cx02_EPS_Anforderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx02_EPS_Anforderung (2U)
#   define Cx02_EPS_Anforderung (2U)
#  endif
#  if (defined RTE_CONST_Cx03_DSC_Anforderung) || (defined Cx03_DSC_Anforderung)
#   if (!defined RTE_CONST_Cx03_DSC_Anforderung) || (RTE_CONST_Cx03_DSC_Anforderung != 3U)
#    error "Enumeration constant <Cx03_DSC_Anforderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx03_DSC_Anforderung (3U)
#   define Cx03_DSC_Anforderung (3U)
#  endif
#  if (defined RTE_CONST_Cx04_Servotronic_Anforderung) || (defined Cx04_Servotronic_Anforderung)
#   if (!defined RTE_CONST_Cx04_Servotronic_Anforderung) || (RTE_CONST_Cx04_Servotronic_Anforderung != 4U)
#    error "Enumeration constant <Cx04_Servotronic_Anforderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx04_Servotronic_Anforderung (4U)
#   define Cx04_Servotronic_Anforderung (4U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255U)
#    error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_ungueltig (255U)
#   define CxFF_Signal_ungueltig (255U)
#  endif

#  define Rte_TypeDef_ImcArbrDataSrc_enum
typedef uint8 ImcArbrDataSrc_enum;
#  define ImcArbrDataSrc_enum_LowerLimit (0U)
#  define ImcArbrDataSrc_enum_UpperLimit (255U)
#  if (defined RTE_CONST_IMCARBRDS_SCI) || (defined IMCARBRDS_SCI)
#   if (!defined RTE_CONST_IMCARBRDS_SCI) || (RTE_CONST_IMCARBRDS_SCI != 0U)
#    error "Enumeration constant <IMCARBRDS_SCI> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_IMCARBRDS_SCI (0U)
#   define IMCARBRDS_SCI (0U)
#  endif
#  if (defined RTE_CONST_IMCARBRDS_CAN) || (defined IMCARBRDS_CAN)
#   if (!defined RTE_CONST_IMCARBRDS_CAN) || (RTE_CONST_IMCARBRDS_CAN != 1U)
#    error "Enumeration constant <IMCARBRDS_CAN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_IMCARBRDS_CAN (1U)
#   define IMCARBRDS_CAN (1U)
#  endif

#  define Rte_TypeDef_LKA_State_enum
typedef uint8 LKA_State_enum;
#  define LKA_State_enum_LowerLimit (0U)
#  define LKA_State_enum_UpperLimit (4U)
#  if (defined RTE_CONST_LKA_Inactive) || (defined LKA_Inactive)
#   if (!defined RTE_CONST_LKA_Inactive) || (RTE_CONST_LKA_Inactive != 0U)
#    error "Enumeration constant <LKA_Inactive> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_LKA_Inactive (0U)
#   define LKA_Inactive (0U)
#  endif
#  if (defined RTE_CONST_LKA_Active) || (defined LKA_Active)
#   if (!defined RTE_CONST_LKA_Active) || (RTE_CONST_LKA_Active != 1U)
#    error "Enumeration constant <LKA_Active> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_LKA_Active (1U)
#   define LKA_Active (1U)
#  endif
#  if (defined RTE_CONST_LKA_TemporarilyLimited) || (defined LKA_TemporarilyLimited)
#   if (!defined RTE_CONST_LKA_TemporarilyLimited) || (RTE_CONST_LKA_TemporarilyLimited != 2U)
#    error "Enumeration constant <LKA_TemporarilyLimited> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_LKA_TemporarilyLimited (2U)
#   define LKA_TemporarilyLimited (2U)
#  endif
#  if (defined RTE_CONST_LKA_PermanentlyFailed) || (defined LKA_PermanentlyFailed)
#   if (!defined RTE_CONST_LKA_PermanentlyFailed) || (RTE_CONST_LKA_PermanentlyFailed != 3U)
#    error "Enumeration constant <LKA_PermanentlyFailed> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_LKA_PermanentlyFailed (3U)
#   define LKA_PermanentlyFailed (3U)
#  endif
#  if (defined RTE_CONST_LKA_ManufacturingDisable) || (defined LKA_ManufacturingDisable)
#   if (!defined RTE_CONST_LKA_ManufacturingDisable) || (RTE_CONST_LKA_ManufacturingDisable != 4U)
#    error "Enumeration constant <LKA_ManufacturingDisable> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_LKA_ManufacturingDisable (4U)
#   define LKA_ManufacturingDisable (4U)
#  endif

#  define Rte_TypeDef_MOD_SW_DRDY_CHAS
typedef uint8 MOD_SW_DRDY_CHAS;
#  define MOD_SW_DRDY_CHAS_LowerLimit (0U)
#  define MOD_SW_DRDY_CHAS_UpperLimit (15U)
#  define Rte_InvalidValue_MOD_SW_DRDY_CHAS (15U)
#  define InvalidValue_MOD_SW_DRDY_CHAS (15U)
#  if (defined RTE_CONST_Cx0_Initialisierung) || (defined Cx0_Initialisierung)
#   if (!defined RTE_CONST_Cx0_Initialisierung) || (RTE_CONST_Cx0_Initialisierung != 0U)
#    error "Enumeration constant <Cx0_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Initialisierung (0U)
#   define Cx0_Initialisierung (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Basis) || (defined Cx1_Basis)
#   if (!defined RTE_CONST_Cx1_Basis) || (RTE_CONST_Cx1_Basis != 1U)
#    error "Enumeration constant <Cx1_Basis> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Basis (1U)
#   define Cx1_Basis (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Sport) || (defined Cx2_Sport)
#   if (!defined RTE_CONST_Cx2_Sport) || (RTE_CONST_Cx2_Sport != 2U)
#    error "Enumeration constant <Cx2_Sport> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Sport (2U)
#   define Cx2_Sport (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Komfort) || (defined Cx3_Komfort)
#   if (!defined RTE_CONST_Cx3_Komfort) || (RTE_CONST_Cx3_Komfort != 3U)
#    error "Enumeration constant <Cx3_Komfort> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Komfort (3U)
#   define Cx3_Komfort (3U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_MOD_SW_DRDY_DRV
typedef uint8 MOD_SW_DRDY_DRV;
#  define MOD_SW_DRDY_DRV_LowerLimit (0U)
#  define MOD_SW_DRDY_DRV_UpperLimit (15U)
#  define Rte_InvalidValue_MOD_SW_DRDY_DRV (15U)
#  define InvalidValue_MOD_SW_DRDY_DRV (15U)
#  if (defined RTE_CONST_Cx0_Initialisierung) || (defined Cx0_Initialisierung)
#   if (!defined RTE_CONST_Cx0_Initialisierung) || (RTE_CONST_Cx0_Initialisierung != 0U)
#    error "Enumeration constant <Cx0_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Initialisierung (0U)
#   define Cx0_Initialisierung (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Basis) || (defined Cx1_Basis)
#   if (!defined RTE_CONST_Cx1_Basis) || (RTE_CONST_Cx1_Basis != 1U)
#    error "Enumeration constant <Cx1_Basis> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Basis (1U)
#   define Cx1_Basis (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Sport) || (defined Cx2_Sport)
#   if (!defined RTE_CONST_Cx2_Sport) || (RTE_CONST_Cx2_Sport != 2U)
#    error "Enumeration constant <Cx2_Sport> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Sport (2U)
#   define Cx2_Sport (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Traction) || (defined Cx3_Traction)
#   if (!defined RTE_CONST_Cx3_Traction) || (RTE_CONST_Cx3_Traction != 3U)
#    error "Enumeration constant <Cx3_Traction> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Traction (3U)
#   define Cx3_Traction (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Eco) || (defined Cx4_Eco)
#   if (!defined RTE_CONST_Cx4_Eco) || (RTE_CONST_Cx4_Eco != 4U)
#    error "Enumeration constant <Cx4_Eco> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Eco (4U)
#   define Cx4_Eco (4U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_New_Coding_10
typedef uint8 New_Coding_10;
#  define New_Coding_10_LowerLimit (0U)
#  define New_Coding_10_UpperLimit (255U)
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

#  define Rte_TypeDef_New_Coding_115
typedef uint8 New_Coding_115;
#  define New_Coding_115_LowerLimit (0U)
#  define New_Coding_115_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_115 (15U)
#  define InvalidValue_New_Coding_115 (15U)
#  if (defined RTE_CONST_Cx0_Funktion_virtueller_Endanschlag_deaktivieren) || (defined Cx0_Funktion_virtueller_Endanschlag_deaktivieren)
#   if (!defined RTE_CONST_Cx0_Funktion_virtueller_Endanschlag_deaktivieren) || (RTE_CONST_Cx0_Funktion_virtueller_Endanschlag_deaktivieren != 0U)
#    error "Enumeration constant <Cx0_Funktion_virtueller_Endanschlag_deaktivieren> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Funktion_virtueller_Endanschlag_deaktivieren (0U)
#   define Cx0_Funktion_virtueller_Endanschlag_deaktivieren (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Funktion_virtueller_Endanschlag_aktivieren) || (defined Cx1_Funktion_virtueller_Endanschlag_aktivieren)
#   if (!defined RTE_CONST_Cx1_Funktion_virtueller_Endanschlag_aktivieren) || (RTE_CONST_Cx1_Funktion_virtueller_Endanschlag_aktivieren != 1U)
#    error "Enumeration constant <Cx1_Funktion_virtueller_Endanschlag_aktivieren> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Funktion_virtueller_Endanschlag_aktivieren (1U)
#   define Cx1_Funktion_virtueller_Endanschlag_aktivieren (1U)
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

#  define Rte_TypeDef_New_Coding_85
typedef uint8 New_Coding_85;
#  define New_Coding_85_LowerLimit (0U)
#  define New_Coding_85_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_85 (15U)
#  define InvalidValue_New_Coding_85 (15U)
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_New_Coding_90
typedef uint8 New_Coding_90;
#  define New_Coding_90_LowerLimit (0U)
#  define New_Coding_90_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_90 (15U)
#  define InvalidValue_New_Coding_90 (15U)
#  if (defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (defined Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert)
#   if (!defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert != 1U)
#    error "Enumeration constant <Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#   define Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Reserved) || (defined Cx2_Reserved)
#   if (!defined RTE_CONST_Cx2_Reserved) || (RTE_CONST_Cx2_Reserved != 2U)
#    error "Enumeration constant <Cx2_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Reserved (2U)
#   define Cx2_Reserved (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Reserved) || (defined Cx3_Reserved)
#   if (!defined RTE_CONST_Cx3_Reserved) || (RTE_CONST_Cx3_Reserved != 3U)
#    error "Enumeration constant <Cx3_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Reserved (3U)
#   define Cx3_Reserved (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (defined Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt)
#   if (!defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt != 4U)
#    error "Enumeration constant <Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#   define Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#  endif
#  if (defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (defined Cx6_Signalwert_ist_ungueltig)
#   if (!defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (RTE_CONST_Cx6_Signalwert_ist_ungueltig != 6U)
#    error "Enumeration constant <Cx6_Signalwert_ist_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Signalwert_ist_ungueltig (6U)
#   define Cx6_Signalwert_ist_ungueltig (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Reserved) || (defined Cx7_Reserved)
#   if (!defined RTE_CONST_Cx7_Reserved) || (RTE_CONST_Cx7_Reserved != 7U)
#    error "Enumeration constant <Cx7_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Reserved (7U)
#   define Cx7_Reserved (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#   if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#    error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Initialisierung (8U)
#   define Cx8_Initialisierung (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Reserved) || (defined Cx9_Reserved)
#   if (!defined RTE_CONST_Cx9_Reserved) || (RTE_CONST_Cx9_Reserved != 9U)
#    error "Enumeration constant <Cx9_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Reserved (9U)
#   define Cx9_Reserved (9U)
#  endif
#  if (defined RTE_CONST_CxA_Reserved) || (defined CxA_Reserved)
#   if (!defined RTE_CONST_CxA_Reserved) || (RTE_CONST_CxA_Reserved != 10U)
#    error "Enumeration constant <CxA_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Reserved (10U)
#   define CxA_Reserved (10U)
#  endif
#  if (defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (defined CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer)
#   if (!defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer != 11U)
#    error "Enumeration constant <CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#   define CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#  endif
#  if (defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer) || (defined CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer)
#   if (!defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer) || (RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer != 12U)
#    error "Enumeration constant <CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer (12U)
#   define CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer (12U)
#  endif
#  if (defined RTE_CONST_CxE_Signalwert_ist_ungueltig) || (defined CxE_Signalwert_ist_ungueltig)
#   if (!defined RTE_CONST_CxE_Signalwert_ist_ungueltig) || (RTE_CONST_CxE_Signalwert_ist_ungueltig != 14U)
#    error "Enumeration constant <CxE_Signalwert_ist_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Signalwert_ist_ungueltig (14U)
#   define CxE_Signalwert_ist_ungueltig (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_New_Coding_91
typedef uint8 New_Coding_91;
#  define New_Coding_91_LowerLimit (0U)
#  define New_Coding_91_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_91 (15U)
#  define InvalidValue_New_Coding_91 (15U)
#  if (defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (defined Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert)
#   if (!defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert != 1U)
#    error "Enumeration constant <Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#   define Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Reserved) || (defined Cx2_Reserved)
#   if (!defined RTE_CONST_Cx2_Reserved) || (RTE_CONST_Cx2_Reserved != 2U)
#    error "Enumeration constant <Cx2_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Reserved (2U)
#   define Cx2_Reserved (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Reserved) || (defined Cx3_Reserved)
#   if (!defined RTE_CONST_Cx3_Reserved) || (RTE_CONST_Cx3_Reserved != 3U)
#    error "Enumeration constant <Cx3_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Reserved (3U)
#   define Cx3_Reserved (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (defined Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt)
#   if (!defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt != 4U)
#    error "Enumeration constant <Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#   define Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#  endif
#  if (defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (defined Cx6_Signalwert_ist_ungueltig)
#   if (!defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (RTE_CONST_Cx6_Signalwert_ist_ungueltig != 6U)
#    error "Enumeration constant <Cx6_Signalwert_ist_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Signalwert_ist_ungueltig (6U)
#   define Cx6_Signalwert_ist_ungueltig (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Reserved) || (defined Cx7_Reserved)
#   if (!defined RTE_CONST_Cx7_Reserved) || (RTE_CONST_Cx7_Reserved != 7U)
#    error "Enumeration constant <Cx7_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Reserved (7U)
#   define Cx7_Reserved (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#   if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#    error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Initialisierung (8U)
#   define Cx8_Initialisierung (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Reserved) || (defined Cx9_Reserved)
#   if (!defined RTE_CONST_Cx9_Reserved) || (RTE_CONST_Cx9_Reserved != 9U)
#    error "Enumeration constant <Cx9_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Reserved (9U)
#   define Cx9_Reserved (9U)
#  endif
#  if (defined RTE_CONST_CxA_Reserved) || (defined CxA_Reserved)
#   if (!defined RTE_CONST_CxA_Reserved) || (RTE_CONST_CxA_Reserved != 10U)
#    error "Enumeration constant <CxA_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Reserved (10U)
#   define CxA_Reserved (10U)
#  endif
#  if (defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (defined CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer)
#   if (!defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer != 11U)
#    error "Enumeration constant <CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#   define CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#  endif
#  if (defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer) || (defined CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer)
#   if (!defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer) || (RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer != 12U)
#    error "Enumeration constant <CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer (12U)
#   define CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer (12U)
#  endif
#  if (defined RTE_CONST_CxE_Signalwert_ist_ungueltig) || (defined CxE_Signalwert_ist_ungueltig)
#   if (!defined RTE_CONST_CxE_Signalwert_ist_ungueltig) || (RTE_CONST_CxE_Signalwert_ist_ungueltig != 14U)
#    error "Enumeration constant <CxE_Signalwert_ist_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Signalwert_ist_ungueltig (14U)
#   define CxE_Signalwert_ist_ungueltig (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_New_Coding_92
typedef uint8 New_Coding_92;
#  define New_Coding_92_LowerLimit (0U)
#  define New_Coding_92_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_92 (15U)
#  define InvalidValue_New_Coding_92 (15U)
#  if (defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (defined Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert)
#   if (!defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert != 1U)
#    error "Enumeration constant <Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#   define Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Reserved) || (defined Cx2_Reserved)
#   if (!defined RTE_CONST_Cx2_Reserved) || (RTE_CONST_Cx2_Reserved != 2U)
#    error "Enumeration constant <Cx2_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Reserved (2U)
#   define Cx2_Reserved (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Reserved) || (defined Cx3_Reserved)
#   if (!defined RTE_CONST_Cx3_Reserved) || (RTE_CONST_Cx3_Reserved != 3U)
#    error "Enumeration constant <Cx3_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Reserved (3U)
#   define Cx3_Reserved (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (defined Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt)
#   if (!defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt != 4U)
#    error "Enumeration constant <Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#   define Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#  endif
#  if (defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (defined Cx6_Signalwert_ist_ungueltig)
#   if (!defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (RTE_CONST_Cx6_Signalwert_ist_ungueltig != 6U)
#    error "Enumeration constant <Cx6_Signalwert_ist_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Signalwert_ist_ungueltig (6U)
#   define Cx6_Signalwert_ist_ungueltig (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Reserved) || (defined Cx7_Reserved)
#   if (!defined RTE_CONST_Cx7_Reserved) || (RTE_CONST_Cx7_Reserved != 7U)
#    error "Enumeration constant <Cx7_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Reserved (7U)
#   define Cx7_Reserved (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#   if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#    error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Initialisierung (8U)
#   define Cx8_Initialisierung (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Reserved) || (defined Cx9_Reserved)
#   if (!defined RTE_CONST_Cx9_Reserved) || (RTE_CONST_Cx9_Reserved != 9U)
#    error "Enumeration constant <Cx9_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Reserved (9U)
#   define Cx9_Reserved (9U)
#  endif
#  if (defined RTE_CONST_CxA_Reserved) || (defined CxA_Reserved)
#   if (!defined RTE_CONST_CxA_Reserved) || (RTE_CONST_CxA_Reserved != 10U)
#    error "Enumeration constant <CxA_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Reserved (10U)
#   define CxA_Reserved (10U)
#  endif
#  if (defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (defined CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer)
#   if (!defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer != 11U)
#    error "Enumeration constant <CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#   define CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#  endif
#  if (defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer) || (defined CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer)
#   if (!defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer) || (RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer != 12U)
#    error "Enumeration constant <CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer (12U)
#   define CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer (12U)
#  endif
#  if (defined RTE_CONST_CxE_Signalwert_ist_ungueltig) || (defined CxE_Signalwert_ist_ungueltig)
#   if (!defined RTE_CONST_CxE_Signalwert_ist_ungueltig) || (RTE_CONST_CxE_Signalwert_ist_ungueltig != 14U)
#    error "Enumeration constant <CxE_Signalwert_ist_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Signalwert_ist_ungueltig (14U)
#   define CxE_Signalwert_ist_ungueltig (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_New_Coding_93
typedef uint8 New_Coding_93;
#  define New_Coding_93_LowerLimit (0U)
#  define New_Coding_93_UpperLimit (15U)
#  define Rte_InvalidValue_New_Coding_93 (15U)
#  define InvalidValue_New_Coding_93 (15U)
#  if (defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (defined Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert)
#   if (!defined RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) || (RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert != 1U)
#    error "Enumeration constant <Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#   define Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Reserved) || (defined Cx2_Reserved)
#   if (!defined RTE_CONST_Cx2_Reserved) || (RTE_CONST_Cx2_Reserved != 2U)
#    error "Enumeration constant <Cx2_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Reserved (2U)
#   define Cx2_Reserved (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Reserved) || (defined Cx3_Reserved)
#   if (!defined RTE_CONST_Cx3_Reserved) || (RTE_CONST_Cx3_Reserved != 3U)
#    error "Enumeration constant <Cx3_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Reserved (3U)
#   define Cx3_Reserved (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (defined Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt)
#   if (!defined RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt) || (RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt != 4U)
#    error "Enumeration constant <Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#   define Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
#  endif
#  if (defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (defined Cx6_Signalwert_ist_ungueltig)
#   if (!defined RTE_CONST_Cx6_Signalwert_ist_ungueltig) || (RTE_CONST_Cx6_Signalwert_ist_ungueltig != 6U)
#    error "Enumeration constant <Cx6_Signalwert_ist_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Signalwert_ist_ungueltig (6U)
#   define Cx6_Signalwert_ist_ungueltig (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Reserved) || (defined Cx7_Reserved)
#   if (!defined RTE_CONST_Cx7_Reserved) || (RTE_CONST_Cx7_Reserved != 7U)
#    error "Enumeration constant <Cx7_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Reserved (7U)
#   define Cx7_Reserved (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#   if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#    error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Initialisierung (8U)
#   define Cx8_Initialisierung (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Reserved) || (defined Cx9_Reserved)
#   if (!defined RTE_CONST_Cx9_Reserved) || (RTE_CONST_Cx9_Reserved != 9U)
#    error "Enumeration constant <Cx9_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Reserved (9U)
#   define Cx9_Reserved (9U)
#  endif
#  if (defined RTE_CONST_CxA_Reserved) || (defined CxA_Reserved)
#   if (!defined RTE_CONST_CxA_Reserved) || (RTE_CONST_CxA_Reserved != 10U)
#    error "Enumeration constant <CxA_Reserved> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Reserved (10U)
#   define CxA_Reserved (10U)
#  endif
#  if (defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (defined CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer)
#   if (!defined RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer) || (RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer != 11U)
#    error "Enumeration constant <CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#   define CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
#  endif
#  if (defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer) || (defined CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer)
#   if (!defined RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer) || (RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer != 12U)
#    error "Enumeration constant <CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer (12U)
#   define CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt_Zustand___Status_Temporaer (12U)
#  endif
#  if (defined RTE_CONST_CxE_Signalwert_ist_ungueltig) || (defined CxE_Signalwert_ist_ungueltig)
#   if (!defined RTE_CONST_CxE_Signalwert_ist_ungueltig) || (RTE_CONST_CxE_Signalwert_ist_ungueltig != 14U)
#    error "Enumeration constant <CxE_Signalwert_ist_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Signalwert_ist_ungueltig (14U)
#   define CxE_Signalwert_ist_ungueltig (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;
#  define NvM_ServiceIdType_LowerLimit (6U)
#  define NvM_ServiceIdType_UpperLimit (12U)
#  if (defined RTE_CONST_NVM_READ_BLOCK) || (defined NVM_READ_BLOCK)
#   if (!defined RTE_CONST_NVM_READ_BLOCK) || (RTE_CONST_NVM_READ_BLOCK != 6U)
#    error "Enumeration constant <NVM_READ_BLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_READ_BLOCK (6U)
#   define NVM_READ_BLOCK (6U)
#  endif
#  if (defined RTE_CONST_NVM_WRITE_BLOCK) || (defined NVM_WRITE_BLOCK)
#   if (!defined RTE_CONST_NVM_WRITE_BLOCK) || (RTE_CONST_NVM_WRITE_BLOCK != 7U)
#    error "Enumeration constant <NVM_WRITE_BLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_WRITE_BLOCK (7U)
#   define NVM_WRITE_BLOCK (7U)
#  endif
#  if (defined RTE_CONST_NVM_RESTORE_BLOCK_DEFAULTS) || (defined NVM_RESTORE_BLOCK_DEFAULTS)
#   if (!defined RTE_CONST_NVM_RESTORE_BLOCK_DEFAULTS) || (RTE_CONST_NVM_RESTORE_BLOCK_DEFAULTS != 8U)
#    error "Enumeration constant <NVM_RESTORE_BLOCK_DEFAULTS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_RESTORE_BLOCK_DEFAULTS (8U)
#   define NVM_RESTORE_BLOCK_DEFAULTS (8U)
#  endif
#  if (defined RTE_CONST_NVM_ERASE_BLOCK) || (defined NVM_ERASE_BLOCK)
#   if (!defined RTE_CONST_NVM_ERASE_BLOCK) || (RTE_CONST_NVM_ERASE_BLOCK != 9U)
#    error "Enumeration constant <NVM_ERASE_BLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_ERASE_BLOCK (9U)
#   define NVM_ERASE_BLOCK (9U)
#  endif
#  if (defined RTE_CONST_NVM_INVALIDATE_NV_BLOCK) || (defined NVM_INVALIDATE_NV_BLOCK)
#   if (!defined RTE_CONST_NVM_INVALIDATE_NV_BLOCK) || (RTE_CONST_NVM_INVALIDATE_NV_BLOCK != 11U)
#    error "Enumeration constant <NVM_INVALIDATE_NV_BLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_INVALIDATE_NV_BLOCK (11U)
#   define NVM_INVALIDATE_NV_BLOCK (11U)
#  endif
#  if (defined RTE_CONST_NVM_READ_ALL) || (defined NVM_READ_ALL)
#   if (!defined RTE_CONST_NVM_READ_ALL) || (RTE_CONST_NVM_READ_ALL != 12U)
#    error "Enumeration constant <NVM_READ_ALL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_READ_ALL (12U)
#   define NVM_READ_ALL (12U)
#  endif

#  define Rte_TypeDef_NxtrDiagMgr_NTCStatusType
typedef uint8 NxtrDiagMgr_NTCStatusType;
#  define NxtrDiagMgr_NTCStatusType_LowerLimit (0U)
#  define NxtrDiagMgr_NTCStatusType_UpperLimit (255U)
#  if (defined RTE_CONST_NTC_STATUS_PASSED) || (defined NTC_STATUS_PASSED)
#   if (!defined RTE_CONST_NTC_STATUS_PASSED) || (RTE_CONST_NTC_STATUS_PASSED != 0U)
#    error "Enumeration constant <NTC_STATUS_PASSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_STATUS_PASSED (0U)
#   define NTC_STATUS_PASSED (0U)
#  endif
#  if (defined RTE_CONST_NTC_STATUS_FAILED) || (defined NTC_STATUS_FAILED)
#   if (!defined RTE_CONST_NTC_STATUS_FAILED) || (RTE_CONST_NTC_STATUS_FAILED != 1U)
#    error "Enumeration constant <NTC_STATUS_FAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_STATUS_FAILED (1U)
#   define NTC_STATUS_FAILED (1U)
#  endif
#  if (defined RTE_CONST_NTC_STATUS_PREPASSED) || (defined NTC_STATUS_PREPASSED)
#   if (!defined RTE_CONST_NTC_STATUS_PREPASSED) || (RTE_CONST_NTC_STATUS_PREPASSED != 2U)
#    error "Enumeration constant <NTC_STATUS_PREPASSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_STATUS_PREPASSED (2U)
#   define NTC_STATUS_PREPASSED (2U)
#  endif
#  if (defined RTE_CONST_NTC_STATUS_PREFAILED) || (defined NTC_STATUS_PREFAILED)
#   if (!defined RTE_CONST_NTC_STATUS_PREFAILED) || (RTE_CONST_NTC_STATUS_PREFAILED != 3U)
#    error "Enumeration constant <NTC_STATUS_PREFAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NTC_STATUS_PREFAILED (3U)
#   define NTC_STATUS_PREFAILED (3U)
#  endif

#  define Rte_TypeDef_Nxtr_SigSts
typedef uint8 Nxtr_SigSts;
#  define Nxtr_SigSts_LowerLimit (0U)
#  define Nxtr_SigSts_UpperLimit (3U)
#  if (defined RTE_CONST_NXTR_SIG_INIT) || (defined NXTR_SIG_INIT)
#   if (!defined RTE_CONST_NXTR_SIG_INIT) || (RTE_CONST_NXTR_SIG_INIT != 0U)
#    error "Enumeration constant <NXTR_SIG_INIT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NXTR_SIG_INIT (0U)
#   define NXTR_SIG_INIT (0U)
#  endif
#  if (defined RTE_CONST_NXTR_SIG_VALID) || (defined NXTR_SIG_VALID)
#   if (!defined RTE_CONST_NXTR_SIG_VALID) || (RTE_CONST_NXTR_SIG_VALID != 1U)
#    error "Enumeration constant <NXTR_SIG_VALID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NXTR_SIG_VALID (1U)
#   define NXTR_SIG_VALID (1U)
#  endif
#  if (defined RTE_CONST_NXTR_SIG_INVALIDTEMP) || (defined NXTR_SIG_INVALIDTEMP)
#   if (!defined RTE_CONST_NXTR_SIG_INVALIDTEMP) || (RTE_CONST_NXTR_SIG_INVALIDTEMP != 2U)
#    error "Enumeration constant <NXTR_SIG_INVALIDTEMP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NXTR_SIG_INVALIDTEMP (2U)
#   define NXTR_SIG_INVALIDTEMP (2U)
#  endif
#  if (defined RTE_CONST_NXTR_SIG_INVALIDPERM) || (defined NXTR_SIG_INVALIDPERM)
#   if (!defined RTE_CONST_NXTR_SIG_INVALIDPERM) || (RTE_CONST_NXTR_SIG_INVALIDPERM != 3U)
#    error "Enumeration constant <NXTR_SIG_INVALIDPERM> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NXTR_SIG_INVALIDPERM (3U)
#   define NXTR_SIG_INVALIDPERM (3U)
#  endif

#  define Rte_TypeDef_PHSDISCNTSTAT_ENUM
typedef uint8 PHSDISCNTSTAT_ENUM;
#  define PHSDISCNTSTAT_ENUM_LowerLimit (0U)
#  define PHSDISCNTSTAT_ENUM_UpperLimit (5U)
#  if (defined RTE_CONST_PDINIT) || (defined PDINIT)
#   if (!defined RTE_CONST_PDINIT) || (RTE_CONST_PDINIT != 0U)
#    error "Enumeration constant <PDINIT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PDINIT (0U)
#   define PDINIT (0U)
#  endif
#  if (defined RTE_CONST_PDINITCOMP) || (defined PDINITCOMP)
#   if (!defined RTE_CONST_PDINITCOMP) || (RTE_CONST_PDINITCOMP != 1U)
#    error "Enumeration constant <PDINITCOMP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PDINITCOMP (1U)
#   define PDINITCOMP (1U)
#  endif
#  if (defined RTE_CONST_PDCLOSED) || (defined PDCLOSED)
#   if (!defined RTE_CONST_PDCLOSED) || (RTE_CONST_PDCLOSED != 2U)
#    error "Enumeration constant <PDCLOSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PDCLOSED (2U)
#   define PDCLOSED (2U)
#  endif
#  if (defined RTE_CONST_PDFAIL) || (defined PDFAIL)
#   if (!defined RTE_CONST_PDFAIL) || (RTE_CONST_PDFAIL != 3U)
#    error "Enumeration constant <PDFAIL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PDFAIL (3U)
#   define PDFAIL (3U)
#  endif

#  define Rte_TypeDef_PersonalizationType
typedef uint8 PersonalizationType;
#  define PersonalizationType_LowerLimit (0U)
#  define PersonalizationType_UpperLimit (3U)
#  if (defined RTE_CONST_PERSONALIZATION_NOTUSED) || (defined PERSONALIZATION_NOTUSED)
#   if (!defined RTE_CONST_PERSONALIZATION_NOTUSED) || (RTE_CONST_PERSONALIZATION_NOTUSED != 0U)
#    error "Enumeration constant <PERSONALIZATION_NOTUSED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PERSONALIZATION_NOTUSED (0U)
#   define PERSONALIZATION_NOTUSED (0U)
#  endif
#  if (defined RTE_CONST_PERSONALIZATION_COMFORT) || (defined PERSONALIZATION_COMFORT)
#   if (!defined RTE_CONST_PERSONALIZATION_COMFORT) || (RTE_CONST_PERSONALIZATION_COMFORT != 1U)
#    error "Enumeration constant <PERSONALIZATION_COMFORT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PERSONALIZATION_COMFORT (1U)
#   define PERSONALIZATION_COMFORT (1U)
#  endif
#  if (defined RTE_CONST_PERSONALIZATION_NORMAL) || (defined PERSONALIZATION_NORMAL)
#   if (!defined RTE_CONST_PERSONALIZATION_NORMAL) || (RTE_CONST_PERSONALIZATION_NORMAL != 2U)
#    error "Enumeration constant <PERSONALIZATION_NORMAL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PERSONALIZATION_NORMAL (2U)
#   define PERSONALIZATION_NORMAL (2U)
#  endif
#  if (defined RTE_CONST_PERSONALIZATION_SPORT) || (defined PERSONALIZATION_SPORT)
#   if (!defined RTE_CONST_PERSONALIZATION_SPORT) || (RTE_CONST_PERSONALIZATION_SPORT != 3U)
#    error "Enumeration constant <PERSONALIZATION_SPORT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PERSONALIZATION_SPORT (3U)
#   define PERSONALIZATION_SPORT (3U)
#  endif

#  define Rte_TypeDef_QU_FN_PMA
typedef uint8 QU_FN_PMA;
#  define QU_FN_PMA_LowerLimit (0U)
#  define QU_FN_PMA_UpperLimit (255U)
#  define Rte_InvalidValue_QU_FN_PMA (255U)
#  define InvalidValue_QU_FN_PMA (255U)
#  if (defined RTE_CONST_Cb1011xx10_Funktion_in_temporaer_Rueckfallebene_SAE_standby) || (defined Cb1011xx10_Funktion_in_temporaer_Rueckfallebene_SAE_standby)
#   if (!defined RTE_CONST_Cb1011xx10_Funktion_in_temporaer_Rueckfallebene_SAE_standby) || (RTE_CONST_Cb1011xx10_Funktion_in_temporaer_Rueckfallebene_SAE_standby != 0U)
#    error "Enumeration constant <Cb1011xx10_Funktion_in_temporaer_Rueckfallebene_SAE_standby> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb1011xx10_Funktion_in_temporaer_Rueckfallebene_SAE_standby (0U)
#   define Cb1011xx10_Funktion_in_temporaer_Rueckfallebene_SAE_standby (0U)
#  endif
#  if (defined RTE_CONST_Cb1011xx01_Funktion_in_temporaer_Rueckfallebene_SAE_standby) || (defined Cb1011xx01_Funktion_in_temporaer_Rueckfallebene_SAE_standby)
#   if (!defined RTE_CONST_Cb1011xx01_Funktion_in_temporaer_Rueckfallebene_SAE_standby) || (RTE_CONST_Cb1011xx01_Funktion_in_temporaer_Rueckfallebene_SAE_standby != 0U)
#    error "Enumeration constant <Cb1011xx01_Funktion_in_temporaer_Rueckfallebene_SAE_standby> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb1011xx01_Funktion_in_temporaer_Rueckfallebene_SAE_standby (0U)
#   define Cb1011xx01_Funktion_in_temporaer_Rueckfallebene_SAE_standby (0U)
#  endif
#  if (defined RTE_CONST_Cb1011xx00_Funktion_in_temporaer_Rueckfallebene_SAE_standby) || (defined Cb1011xx00_Funktion_in_temporaer_Rueckfallebene_SAE_standby)
#   if (!defined RTE_CONST_Cb1011xx00_Funktion_in_temporaer_Rueckfallebene_SAE_standby) || (RTE_CONST_Cb1011xx00_Funktion_in_temporaer_Rueckfallebene_SAE_standby != 0U)
#    error "Enumeration constant <Cb1011xx00_Funktion_in_temporaer_Rueckfallebene_SAE_standby> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb1011xx00_Funktion_in_temporaer_Rueckfallebene_SAE_standby (0U)
#   define Cb1011xx00_Funktion_in_temporaer_Rueckfallebene_SAE_standby (0U)
#  endif
#  if (defined RTE_CONST_Cb1010xxxx_Funktion_verfuegbar___Aktiv) || (defined Cb1010xxxx_Funktion_verfuegbar___Aktiv)
#   if (!defined RTE_CONST_Cb1010xxxx_Funktion_verfuegbar___Aktiv) || (RTE_CONST_Cb1010xxxx_Funktion_verfuegbar___Aktiv != 0U)
#    error "Enumeration constant <Cb1010xxxx_Funktion_verfuegbar___Aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb1010xxxx_Funktion_verfuegbar___Aktiv (0U)
#   define Cb1010xxxx_Funktion_verfuegbar___Aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cb1000xxxx_Initialisierung) || (defined Cb1000xxxx_Initialisierung)
#   if (!defined RTE_CONST_Cb1000xxxx_Initialisierung) || (RTE_CONST_Cb1000xxxx_Initialisierung != 0U)
#    error "Enumeration constant <Cb1000xxxx_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb1000xxxx_Initialisierung (0U)
#   define Cb1000xxxx_Initialisierung (0U)
#  endif
#  if (defined RTE_CONST_Cb0111xxxx_Funktion_nicht_vorhanden) || (defined Cb0111xxxx_Funktion_nicht_vorhanden)
#   if (!defined RTE_CONST_Cb0111xxxx_Funktion_nicht_vorhanden) || (RTE_CONST_Cb0111xxxx_Funktion_nicht_vorhanden != 0U)
#    error "Enumeration constant <Cb0111xxxx_Funktion_nicht_vorhanden> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0111xxxx_Funktion_nicht_vorhanden (0U)
#   define Cb0111xxxx_Funktion_nicht_vorhanden (0U)
#  endif
#  if (defined RTE_CONST_Cb0110xxx1_Funktion_nicht_verfuegbar__temporaerer_Fehlermode) || (defined Cb0110xxx1_Funktion_nicht_verfuegbar__temporaerer_Fehlermode)
#   if (!defined RTE_CONST_Cb0110xxx1_Funktion_nicht_verfuegbar__temporaerer_Fehlermode) || (RTE_CONST_Cb0110xxx1_Funktion_nicht_verfuegbar__temporaerer_Fehlermode != 0U)
#    error "Enumeration constant <Cb0110xxx1_Funktion_nicht_verfuegbar__temporaerer_Fehlermode> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0110xxx1_Funktion_nicht_verfuegbar__temporaerer_Fehlermode (0U)
#   define Cb0110xxx1_Funktion_nicht_verfuegbar__temporaerer_Fehlermode (0U)
#  endif
#  if (defined RTE_CONST_Cb0110xxx0_Funktion_nicht_verfuegbar__Fehler) || (defined Cb0110xxx0_Funktion_nicht_verfuegbar__Fehler)
#   if (!defined RTE_CONST_Cb0110xxx0_Funktion_nicht_verfuegbar__Fehler) || (RTE_CONST_Cb0110xxx0_Funktion_nicht_verfuegbar__Fehler != 0U)
#    error "Enumeration constant <Cb0110xxx0_Funktion_nicht_verfuegbar__Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0110xxx0_Funktion_nicht_verfuegbar__Fehler (0U)
#   define Cb0110xxx0_Funktion_nicht_verfuegbar__Fehler (0U)
#  endif
#  if (defined RTE_CONST_Cb0010xx10_Funktion_verfuegbar___Bereit_PLV_aktiv) || (defined Cb0010xx10_Funktion_verfuegbar___Bereit_PLV_aktiv)
#   if (!defined RTE_CONST_Cb0010xx10_Funktion_verfuegbar___Bereit_PLV_aktiv) || (RTE_CONST_Cb0010xx10_Funktion_verfuegbar___Bereit_PLV_aktiv != 0U)
#    error "Enumeration constant <Cb0010xx10_Funktion_verfuegbar___Bereit_PLV_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0010xx10_Funktion_verfuegbar___Bereit_PLV_aktiv (0U)
#   define Cb0010xx10_Funktion_verfuegbar___Bereit_PLV_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cb0010xx01_Funktion_verfuegbar___Bereit_PLV_aktiv) || (defined Cb0010xx01_Funktion_verfuegbar___Bereit_PLV_aktiv)
#   if (!defined RTE_CONST_Cb0010xx01_Funktion_verfuegbar___Bereit_PLV_aktiv) || (RTE_CONST_Cb0010xx01_Funktion_verfuegbar___Bereit_PLV_aktiv != 0U)
#    error "Enumeration constant <Cb0010xx01_Funktion_verfuegbar___Bereit_PLV_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0010xx01_Funktion_verfuegbar___Bereit_PLV_aktiv (0U)
#   define Cb0010xx01_Funktion_verfuegbar___Bereit_PLV_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cb0010xx00_Funktion_verfuegbar___Bereit_PLV_aktiv) || (defined Cb0010xx00_Funktion_verfuegbar___Bereit_PLV_aktiv)
#   if (!defined RTE_CONST_Cb0010xx00_Funktion_verfuegbar___Bereit_PLV_aktiv) || (RTE_CONST_Cb0010xx00_Funktion_verfuegbar___Bereit_PLV_aktiv != 0U)
#    error "Enumeration constant <Cb0010xx00_Funktion_verfuegbar___Bereit_PLV_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0010xx00_Funktion_verfuegbar___Bereit_PLV_aktiv (0U)
#   define Cb0010xx00_Funktion_verfuegbar___Bereit_PLV_aktiv (0U)
#  endif
#  if (defined RTE_CONST_CxE0_Funktion_nicht_verfuegbar__ausgeschaltet) || (defined CxE0_Funktion_nicht_verfuegbar__ausgeschaltet)
#   if (!defined RTE_CONST_CxE0_Funktion_nicht_verfuegbar__ausgeschaltet) || (RTE_CONST_CxE0_Funktion_nicht_verfuegbar__ausgeschaltet != 224U)
#    error "Enumeration constant <CxE0_Funktion_nicht_verfuegbar__ausgeschaltet> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE0_Funktion_nicht_verfuegbar__ausgeschaltet (224U)
#   define CxE0_Funktion_nicht_verfuegbar__ausgeschaltet (224U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255U)
#    error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_ungueltig (255U)
#   define CxFF_Signal_ungueltig (255U)
#  endif

#  define Rte_TypeDef_QU_HOFF_RCOG
typedef uint8 QU_HOFF_RCOG;
#  define QU_HOFF_RCOG_LowerLimit (0U)
#  define QU_HOFF_RCOG_UpperLimit (15U)
#  define Rte_InvalidValue_QU_HOFF_RCOG (15U)
#  define InvalidValue_QU_HOFF_RCOG (15U)
#  if (defined RTE_CONST_Cx1_Hands_Off_nicht_erkannt) || (defined Cx1_Hands_Off_nicht_erkannt)
#   if (!defined RTE_CONST_Cx1_Hands_Off_nicht_erkannt) || (RTE_CONST_Cx1_Hands_Off_nicht_erkannt != 1U)
#    error "Enumeration constant <Cx1_Hands_Off_nicht_erkannt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Hands_Off_nicht_erkannt (1U)
#   define Cx1_Hands_Off_nicht_erkannt (1U)
#  endif
#  if (defined RTE_CONST_Cx9_Hands_Off_erkannt) || (defined Cx9_Hands_Off_erkannt)
#   if (!defined RTE_CONST_Cx9_Hands_Off_erkannt) || (RTE_CONST_Cx9_Hands_Off_erkannt != 9U)
#    error "Enumeration constant <Cx9_Hands_Off_erkannt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Hands_Off_erkannt (9U)
#   define Cx9_Hands_Off_erkannt (9U)
#  endif
#  if (defined RTE_CONST_CxD_Hands_Off_nicht_verfuegbar) || (defined CxD_Hands_Off_nicht_verfuegbar)
#   if (!defined RTE_CONST_CxD_Hands_Off_nicht_verfuegbar) || (RTE_CONST_CxD_Hands_Off_nicht_verfuegbar != 13U)
#    error "Enumeration constant <CxD_Hands_Off_nicht_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Hands_Off_nicht_verfuegbar (13U)
#   define CxD_Hands_Off_nicht_verfuegbar (13U)
#  endif
#  if (defined RTE_CONST_CxE_Fehler) || (defined CxE_Fehler)
#   if (!defined RTE_CONST_CxE_Fehler) || (RTE_CONST_CxE_Fehler != 14U)
#    error "Enumeration constant <CxE_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Fehler (14U)
#   define CxE_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_QU_TARVL_PMA
typedef uint8 QU_TARVL_PMA;
#  define QU_TARVL_PMA_LowerLimit (0U)
#  define QU_TARVL_PMA_UpperLimit (15U)
#  define Rte_InvalidValue_QU_TARVL_PMA (15U)
#  define InvalidValue_QU_TARVL_PMA (15U)
#  if (defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (defined Cx2_Sollwerte_umsetzen)
#   if (!defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (RTE_CONST_Cx2_Sollwerte_umsetzen != 2U)
#    error "Enumeration constant <Cx2_Sollwerte_umsetzen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Sollwerte_umsetzen (2U)
#   define Cx2_Sollwerte_umsetzen (2U)
#  endif
#  if (defined RTE_CONST_Cx6_Fehler__Sollwerte_nicht_umsetzen) || (defined Cx6_Fehler__Sollwerte_nicht_umsetzen)
#   if (!defined RTE_CONST_Cx6_Fehler__Sollwerte_nicht_umsetzen) || (RTE_CONST_Cx6_Fehler__Sollwerte_nicht_umsetzen != 6U)
#    error "Enumeration constant <Cx6_Fehler__Sollwerte_nicht_umsetzen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Fehler__Sollwerte_nicht_umsetzen (6U)
#   define Cx6_Fehler__Sollwerte_nicht_umsetzen (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (defined Cx7_Sollwerte_nicht_vorhanden)
#   if (!defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (RTE_CONST_Cx7_Sollwerte_nicht_vorhanden != 7U)
#    error "Enumeration constant <Cx7_Sollwerte_nicht_vorhanden> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Sollwerte_nicht_vorhanden (7U)
#   define Cx7_Sollwerte_nicht_vorhanden (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#   if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#    error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Initialisierung (8U)
#   define Cx8_Initialisierung (8U)
#  endif
#  if (defined RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen) || (defined CxE_Standby__Sollwerte_nicht_umsetzen)
#   if (!defined RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen) || (RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen != 14U)
#    error "Enumeration constant <CxE_Standby__Sollwerte_nicht_umsetzen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen (14U)
#   define CxE_Standby__Sollwerte_nicht_umsetzen (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_QU_TAR_STEA_FTAX_PNI
typedef uint8 QU_TAR_STEA_FTAX_PNI;
#  define QU_TAR_STEA_FTAX_PNI_LowerLimit (0U)
#  define QU_TAR_STEA_FTAX_PNI_UpperLimit (15U)
#  define Rte_InvalidValue_QU_TAR_STEA_FTAX_PNI (15U)
#  define InvalidValue_QU_TAR_STEA_FTAX_PNI (15U)
#  if (defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (defined Cx2_Sollwerte_umsetzen)
#   if (!defined RTE_CONST_Cx2_Sollwerte_umsetzen) || (RTE_CONST_Cx2_Sollwerte_umsetzen != 2U)
#    error "Enumeration constant <Cx2_Sollwerte_umsetzen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Sollwerte_umsetzen (2U)
#   define Cx2_Sollwerte_umsetzen (2U)
#  endif
#  if (defined RTE_CONST_Cx6_Fehler__Sollwerte_nicht_umsetzen) || (defined Cx6_Fehler__Sollwerte_nicht_umsetzen)
#   if (!defined RTE_CONST_Cx6_Fehler__Sollwerte_nicht_umsetzen) || (RTE_CONST_Cx6_Fehler__Sollwerte_nicht_umsetzen != 6U)
#    error "Enumeration constant <Cx6_Fehler__Sollwerte_nicht_umsetzen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Fehler__Sollwerte_nicht_umsetzen (6U)
#   define Cx6_Fehler__Sollwerte_nicht_umsetzen (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (defined Cx7_Sollwerte_nicht_vorhanden)
#   if (!defined RTE_CONST_Cx7_Sollwerte_nicht_vorhanden) || (RTE_CONST_Cx7_Sollwerte_nicht_vorhanden != 7U)
#    error "Enumeration constant <Cx7_Sollwerte_nicht_vorhanden> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Sollwerte_nicht_vorhanden (7U)
#   define Cx7_Sollwerte_nicht_vorhanden (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Initialisierung) || (defined Cx8_Initialisierung)
#   if (!defined RTE_CONST_Cx8_Initialisierung) || (RTE_CONST_Cx8_Initialisierung != 8U)
#    error "Enumeration constant <Cx8_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Initialisierung (8U)
#   define Cx8_Initialisierung (8U)
#  endif
#  if (defined RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen) || (defined CxE_Standby__Sollwerte_nicht_umsetzen)
#   if (!defined RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen) || (RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen != 14U)
#    error "Enumeration constant <CxE_Standby__Sollwerte_nicht_umsetzen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Standby__Sollwerte_nicht_umsetzen (14U)
#   define CxE_Standby__Sollwerte_nicht_umsetzen (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_RQ_MSA_FN_SLCTN
typedef uint8 RQ_MSA_FN_SLCTN;
#  define RQ_MSA_FN_SLCTN_LowerLimit (0U)
#  define RQ_MSA_FN_SLCTN_UpperLimit (63U)
#  define Rte_InvalidValue_RQ_MSA_FN_SLCTN (63U)
#  define InvalidValue_RQ_MSA_FN_SLCTN (63U)
#  if (defined RTE_CONST_Cx00_keine_Anforderung) || (defined Cx00_keine_Anforderung)
#   if (!defined RTE_CONST_Cx00_keine_Anforderung) || (RTE_CONST_Cx00_keine_Anforderung != 0U)
#    error "Enumeration constant <Cx00_keine_Anforderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx00_keine_Anforderung (0U)
#   define Cx00_keine_Anforderung (0U)
#  endif
#  if (defined RTE_CONST_Cb0xxxx1_Abschaltverhinderer) || (defined Cb0xxxx1_Abschaltverhinderer)
#   if (!defined RTE_CONST_Cb0xxxx1_Abschaltverhinderer) || (RTE_CONST_Cb0xxxx1_Abschaltverhinderer != 0U)
#    error "Enumeration constant <Cb0xxxx1_Abschaltverhinderer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xxxx1_Abschaltverhinderer (0U)
#   define Cb0xxxx1_Abschaltverhinderer (0U)
#  endif
#  if (defined RTE_CONST_Cb0xxx1x_Temporaerer_Deaktivierer) || (defined Cb0xxx1x_Temporaerer_Deaktivierer)
#   if (!defined RTE_CONST_Cb0xxx1x_Temporaerer_Deaktivierer) || (RTE_CONST_Cb0xxx1x_Temporaerer_Deaktivierer != 0U)
#    error "Enumeration constant <Cb0xxx1x_Temporaerer_Deaktivierer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xxx1x_Temporaerer_Deaktivierer (0U)
#   define Cb0xxx1x_Temporaerer_Deaktivierer (0U)
#  endif
#  if (defined RTE_CONST_Cb0xx1xx_Einschaltaufforderer) || (defined Cb0xx1xx_Einschaltaufforderer)
#   if (!defined RTE_CONST_Cb0xx1xx_Einschaltaufforderer) || (RTE_CONST_Cb0xx1xx_Einschaltaufforderer != 0U)
#    error "Enumeration constant <Cb0xx1xx_Einschaltaufforderer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0xx1xx_Einschaltaufforderer (0U)
#   define Cb0xx1xx_Einschaltaufforderer (0U)
#  endif
#  if (defined RTE_CONST_Cb0x1xxx_Permanenter_Deaktivierer) || (defined Cb0x1xxx_Permanenter_Deaktivierer)
#   if (!defined RTE_CONST_Cb0x1xxx_Permanenter_Deaktivierer) || (RTE_CONST_Cb0x1xxx_Permanenter_Deaktivierer != 0U)
#    error "Enumeration constant <Cb0x1xxx_Permanenter_Deaktivierer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0x1xxx_Permanenter_Deaktivierer (0U)
#   define Cb0x1xxx_Permanenter_Deaktivierer (0U)
#  endif
#  if (defined RTE_CONST_Cb01xxxx_Abschaltverzoegerer) || (defined Cb01xxxx_Abschaltverzoegerer)
#   if (!defined RTE_CONST_Cb01xxxx_Abschaltverzoegerer) || (RTE_CONST_Cb01xxxx_Abschaltverzoegerer != 0U)
#    error "Enumeration constant <Cb01xxxx_Abschaltverzoegerer> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb01xxxx_Abschaltverzoegerer (0U)
#   define Cb01xxxx_Abschaltverzoegerer (0U)
#  endif
#  if (defined RTE_CONST_Cx3F_Signal_ungueltig) || (defined Cx3F_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3F_Signal_ungueltig) || (RTE_CONST_Cx3F_Signal_ungueltig != 63U)
#    error "Enumeration constant <Cx3F_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3F_Signal_ungueltig (63U)
#   define Cx3F_Signal_ungueltig (63U)
#  endif

#  define Rte_TypeDef_RQ_RST_OBD_DIAG
typedef uint8 RQ_RST_OBD_DIAG;
#  define RQ_RST_OBD_DIAG_LowerLimit (0U)
#  define RQ_RST_OBD_DIAG_UpperLimit (3U)
#  define Rte_InvalidValue_RQ_RST_OBD_DIAG (3U)
#  define InvalidValue_RQ_RST_OBD_DIAG (3U)
#  if (defined RTE_CONST_Cx0_Keine_Anforderung_Reset_OBD_Diagnose) || (defined Cx0_Keine_Anforderung_Reset_OBD_Diagnose)
#   if (!defined RTE_CONST_Cx0_Keine_Anforderung_Reset_OBD_Diagnose) || (RTE_CONST_Cx0_Keine_Anforderung_Reset_OBD_Diagnose != 0U)
#    error "Enumeration constant <Cx0_Keine_Anforderung_Reset_OBD_Diagnose> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Keine_Anforderung_Reset_OBD_Diagnose (0U)
#   define Cx0_Keine_Anforderung_Reset_OBD_Diagnose (0U)
#  endif
#  if (defined RTE_CONST_Cx2_Anforderung_Reset_OBD_Diagnose) || (defined Cx2_Anforderung_Reset_OBD_Diagnose)
#   if (!defined RTE_CONST_Cx2_Anforderung_Reset_OBD_Diagnose) || (RTE_CONST_Cx2_Anforderung_Reset_OBD_Diagnose != 2U)
#    error "Enumeration constant <Cx2_Anforderung_Reset_OBD_Diagnose> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Anforderung_Reset_OBD_Diagnose (2U)
#   define Cx2_Anforderung_Reset_OBD_Diagnose (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#    error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_ungueltig (3U)
#   define Cx3_Signal_ungueltig (3U)
#  endif

#  define Rte_TypeDef_RQ_STG_EFAN
typedef uint8 RQ_STG_EFAN;
#  define RQ_STG_EFAN_LowerLimit (0U)
#  define RQ_STG_EFAN_UpperLimit (15U)
#  define Rte_InvalidValue_RQ_STG_EFAN (15U)
#  define InvalidValue_RQ_STG_EFAN (15U)
#  if (defined RTE_CONST_Cx0_AUS) || (defined Cx0_AUS)
#   if (!defined RTE_CONST_Cx0_AUS) || (RTE_CONST_Cx0_AUS != 0U)
#    error "Enumeration constant <Cx0_AUS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_AUS (0U)
#   define Cx0_AUS (0U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_RQ_SW_DRDY_KDIS
typedef uint8 RQ_SW_DRDY_KDIS;
#  define RQ_SW_DRDY_KDIS_LowerLimit (0U)
#  define RQ_SW_DRDY_KDIS_UpperLimit (3U)
#  define Rte_InvalidValue_RQ_SW_DRDY_KDIS (3U)
#  define InvalidValue_RQ_SW_DRDY_KDIS (3U)
#  if (defined RTE_CONST_Cx0_Kombi_Liste_nicht_anzeigen) || (defined Cx0_Kombi_Liste_nicht_anzeigen)
#   if (!defined RTE_CONST_Cx0_Kombi_Liste_nicht_anzeigen) || (RTE_CONST_Cx0_Kombi_Liste_nicht_anzeigen != 0U)
#    error "Enumeration constant <Cx0_Kombi_Liste_nicht_anzeigen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Kombi_Liste_nicht_anzeigen (0U)
#   define Cx0_Kombi_Liste_nicht_anzeigen (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Kombi_Liste_anzeigen) || (defined Cx1_Kombi_Liste_anzeigen)
#   if (!defined RTE_CONST_Cx1_Kombi_Liste_anzeigen) || (RTE_CONST_Cx1_Kombi_Liste_anzeigen != 1U)
#    error "Enumeration constant <Cx1_Kombi_Liste_anzeigen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Kombi_Liste_anzeigen (1U)
#   define Cx1_Kombi_Liste_anzeigen (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Initialisierung) || (defined Cx2_Initialisierung)
#   if (!defined RTE_CONST_Cx2_Initialisierung) || (RTE_CONST_Cx2_Initialisierung != 2U)
#    error "Enumeration constant <Cx2_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Initialisierung (2U)
#   define Cx2_Initialisierung (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#    error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_ungueltig (3U)
#   define Cx3_Signal_ungueltig (3U)
#  endif

#  define Rte_TypeDef_RequestResultType
typedef uint8 RequestResultType;
#  define RequestResultType_LowerLimit (0U)
#  define RequestResultType_UpperLimit (5U)
#  if (defined RTE_CONST_NVM_REQ_OK) || (defined NVM_REQ_OK)
#   if (!defined RTE_CONST_NVM_REQ_OK) || (RTE_CONST_NVM_REQ_OK != 0U)
#    error "Enumeration constant <NVM_REQ_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_REQ_OK (0U)
#   define NVM_REQ_OK (0U)
#  endif
#  if (defined RTE_CONST_NVM_REQ_NOT_OK) || (defined NVM_REQ_NOT_OK)
#   if (!defined RTE_CONST_NVM_REQ_NOT_OK) || (RTE_CONST_NVM_REQ_NOT_OK != 1U)
#    error "Enumeration constant <NVM_REQ_NOT_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_REQ_NOT_OK (1U)
#   define NVM_REQ_NOT_OK (1U)
#  endif
#  if (defined RTE_CONST_NVM_REQ_PENDING) || (defined NVM_REQ_PENDING)
#   if (!defined RTE_CONST_NVM_REQ_PENDING) || (RTE_CONST_NVM_REQ_PENDING != 2U)
#    error "Enumeration constant <NVM_REQ_PENDING> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_REQ_PENDING (2U)
#   define NVM_REQ_PENDING (2U)
#  endif
#  if (defined RTE_CONST_NVM_REQ_INTEGRITY_FAILED) || (defined NVM_REQ_INTEGRITY_FAILED)
#   if (!defined RTE_CONST_NVM_REQ_INTEGRITY_FAILED) || (RTE_CONST_NVM_REQ_INTEGRITY_FAILED != 3U)
#    error "Enumeration constant <NVM_REQ_INTEGRITY_FAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_REQ_INTEGRITY_FAILED (3U)
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif
#  if (defined RTE_CONST_NVM_REQ_BLOCK_SKIPPED) || (defined NVM_REQ_BLOCK_SKIPPED)
#   if (!defined RTE_CONST_NVM_REQ_BLOCK_SKIPPED) || (RTE_CONST_NVM_REQ_BLOCK_SKIPPED != 4U)
#    error "Enumeration constant <NVM_REQ_BLOCK_SKIPPED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_REQ_BLOCK_SKIPPED (4U)
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif
#  if (defined RTE_CONST_NVM_REQ_NV_INVALIDATED) || (defined NVM_REQ_NV_INVALIDATED)
#   if (!defined RTE_CONST_NVM_REQ_NV_INVALIDATED) || (RTE_CONST_NVM_REQ_NV_INVALIDATED != 5U)
#    error "Enumeration constant <NVM_REQ_NV_INVALIDATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NVM_REQ_NV_INVALIDATED (5U)
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  define Rte_TypeDef_RoutineStatus
typedef uint8 RoutineStatus;
#  define RoutineStatus_LowerLimit (0U)
#  define RoutineStatus_UpperLimit (3U)
#  if (defined RTE_CONST_RTN_INACTIVE) || (defined RTN_INACTIVE)
#   if (!defined RTE_CONST_RTN_INACTIVE) || (RTE_CONST_RTN_INACTIVE != 0U)
#    error "Enumeration constant <RTN_INACTIVE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_INACTIVE (0U)
#   define RTN_INACTIVE (0U)
#  endif
#  if (defined RTE_CONST_RTN_ACTIVE) || (defined RTN_ACTIVE)
#   if (!defined RTE_CONST_RTN_ACTIVE) || (RTE_CONST_RTN_ACTIVE != 1U)
#    error "Enumeration constant <RTN_ACTIVE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_ACTIVE (1U)
#   define RTN_ACTIVE (1U)
#  endif
#  if (defined RTE_CONST_RTN_COMPLETE) || (defined RTN_COMPLETE)
#   if (!defined RTE_CONST_RTN_COMPLETE) || (RTE_CONST_RTN_COMPLETE != 2U)
#    error "Enumeration constant <RTN_COMPLETE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_COMPLETE (2U)
#   define RTN_COMPLETE (2U)
#  endif
#  if (defined RTE_CONST_RTN_CANCELLED) || (defined RTN_CANCELLED)
#   if (!defined RTE_CONST_RTN_CANCELLED) || (RTE_CONST_RTN_CANCELLED != 3U)
#    error "Enumeration constant <RTN_CANCELLED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_RTN_CANCELLED (3U)
#   define RTN_CANCELLED (3U)
#  endif

#  define Rte_TypeDef_SS_State_enum
typedef uint8 SS_State_enum;
#  define SS_State_enum_LowerLimit (0U)
#  define SS_State_enum_UpperLimit (5U)
#  if (defined RTE_CONST_SS_Normal) || (defined SS_Normal)
#   if (!defined RTE_CONST_SS_Normal) || (RTE_CONST_SS_Normal != 0U)
#    error "Enumeration constant <SS_Normal> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SS_Normal (0U)
#   define SS_Normal (0U)
#  endif
#  if (defined RTE_CONST_SS_Intermediate1) || (defined SS_Intermediate1)
#   if (!defined RTE_CONST_SS_Intermediate1) || (RTE_CONST_SS_Intermediate1 != 1U)
#    error "Enumeration constant <SS_Intermediate1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SS_Intermediate1 (1U)
#   define SS_Intermediate1 (1U)
#  endif
#  if (defined RTE_CONST_SS_Stop) || (defined SS_Stop)
#   if (!defined RTE_CONST_SS_Stop) || (RTE_CONST_SS_Stop != 2U)
#    error "Enumeration constant <SS_Stop> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SS_Stop (2U)
#   define SS_Stop (2U)
#  endif
#  if (defined RTE_CONST_SS_Intermediate2) || (defined SS_Intermediate2)
#   if (!defined RTE_CONST_SS_Intermediate2) || (RTE_CONST_SS_Intermediate2 != 3U)
#    error "Enumeration constant <SS_Intermediate2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SS_Intermediate2 (3U)
#   define SS_Intermediate2 (3U)
#  endif
#  if (defined RTE_CONST_SS_Fault) || (defined SS_Fault)
#   if (!defined RTE_CONST_SS_Fault) || (RTE_CONST_SS_Fault != 4U)
#    error "Enumeration constant <SS_Fault> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SS_Fault (4U)
#   define SS_Fault (4U)
#  endif
#  if (defined RTE_CONST_SS_Disable) || (defined SS_Disable)
#   if (!defined RTE_CONST_SS_Disable) || (RTE_CONST_SS_Disable != 5U)
#    error "Enumeration constant <SS_Disable> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SS_Disable (5U)
#   define SS_Disable (5U)
#  endif

#  define Rte_TypeDef_ST_BT_PROTE_WUP
typedef uint8 ST_BT_PROTE_WUP;
#  define ST_BT_PROTE_WUP_LowerLimit (0U)
#  define ST_BT_PROTE_WUP_UpperLimit (3U)
#  define Rte_InvalidValue_ST_BT_PROTE_WUP (3U)
#  define InvalidValue_ST_BT_PROTE_WUP (3U)
#  if (defined RTE_CONST_Cx0_KeineAktion) || (defined Cx0_KeineAktion)
#   if (!defined RTE_CONST_Cx0_KeineAktion) || (RTE_CONST_Cx0_KeineAktion != 0U)
#    error "Enumeration constant <Cx0_KeineAktion> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_KeineAktion (0U)
#   define Cx0_KeineAktion (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Triggerungbatteryguard) || (defined Cx1_Triggerungbatteryguard)
#   if (!defined RTE_CONST_Cx1_Triggerungbatteryguard) || (RTE_CONST_Cx1_Triggerungbatteryguard != 1U)
#    error "Enumeration constant <Cx1_Triggerungbatteryguard> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Triggerungbatteryguard (1U)
#   define Cx1_Triggerungbatteryguard (1U)
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

#  define Rte_TypeDef_ST_CC
typedef uint8 ST_CC;
#  define ST_CC_LowerLimit (0U)
#  define ST_CC_UpperLimit (3U)
#  define Rte_InvalidValue_ST_CC (3U)
#  define InvalidValue_ST_CC (3U)
#  if (defined RTE_CONST_Cx0_Ruecksetzen) || (defined Cx0_Ruecksetzen)
#   if (!defined RTE_CONST_Cx0_Ruecksetzen) || (RTE_CONST_Cx0_Ruecksetzen != 0U)
#    error "Enumeration constant <Cx0_Ruecksetzen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Ruecksetzen (0U)
#   define Cx0_Ruecksetzen (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Setzen) || (defined Cx1_Setzen)
#   if (!defined RTE_CONST_Cx1_Setzen) || (RTE_CONST_Cx1_Setzen != 1U)
#    error "Enumeration constant <Cx1_Setzen> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Setzen (1U)
#   define Cx1_Setzen (1U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#    error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_ungueltig (3U)
#   define Cx3_Signal_ungueltig (3U)
#  endif

#  define Rte_TypeDef_ST_CHC_DRV
typedef uint8 ST_CHC_DRV;
#  define ST_CHC_DRV_LowerLimit (0U)
#  define ST_CHC_DRV_UpperLimit (15U)
#  define Rte_InvalidValue_ST_CHC_DRV (15U)
#  define InvalidValue_ST_CHC_DRV (15U)
#  if (defined RTE_CONST_Cx0_Standard) || (defined Cx0_Standard)
#   if (!defined RTE_CONST_Cx0_Standard) || (RTE_CONST_Cx0_Standard != 0U)
#    error "Enumeration constant <Cx0_Standard> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Standard (0U)
#   define Cx0_Standard (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Sport) || (defined Cx1_Sport)
#   if (!defined RTE_CONST_Cx1_Sport) || (RTE_CONST_Cx1_Sport != 1U)
#    error "Enumeration constant <Cx1_Sport> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Sport (1U)
#   define Cx1_Sport (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Eco) || (defined Cx2_Eco)
#   if (!defined RTE_CONST_Cx2_Eco) || (RTE_CONST_Cx2_Eco != 2U)
#    error "Enumeration constant <Cx2_Eco> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Eco (2U)
#   define Cx2_Eco (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Komfort) || (defined Cx3_Komfort)
#   if (!defined RTE_CONST_Cx3_Komfort) || (RTE_CONST_Cx3_Komfort != 3U)
#    error "Enumeration constant <Cx3_Komfort> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Komfort (3U)
#   define Cx3_Komfort (3U)
#  endif
#  if (defined RTE_CONST_Cx4_EV) || (defined Cx4_EV)
#   if (!defined RTE_CONST_Cx4_EV) || (RTE_CONST_Cx4_EV != 4U)
#    error "Enumeration constant <Cx4_EV> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_EV (4U)
#   define Cx4_EV (4U)
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

#  define Rte_TypeDef_ST_DRV_VEH
typedef uint8 ST_DRV_VEH;
#  define ST_DRV_VEH_LowerLimit (0U)
#  define ST_DRV_VEH_UpperLimit (255U)
#  define Rte_InvalidValue_ST_DRV_VEH (255U)
#  define InvalidValue_ST_DRV_VEH (255U)
#  if (defined RTE_CONST_Cbxxx11110_Verbrennungsmotor_im_Auslauf_mit_Startankuendigung_durch_MSA_Anforderung_) || (defined Cbxxx11110_Verbrennungsmotor_im_Auslauf_mit_Startankuendigung_durch_MSA_Anforderung_)
#   if (!defined RTE_CONST_Cbxxx11110_Verbrennungsmotor_im_Auslauf_mit_Startankuendigung_durch_MSA_Anforderung_) || (RTE_CONST_Cbxxx11110_Verbrennungsmotor_im_Auslauf_mit_Startankuendigung_durch_MSA_Anforderung_ != 0U)
#    error "Enumeration constant <Cbxxx11110_Verbrennungsmotor_im_Auslauf_mit_Startankuendigung_durch_MSA_Anforderung_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx11110_Verbrennungsmotor_im_Auslauf_mit_Startankuendigung_durch_MSA_Anforderung_ (0U)
#   define Cbxxx11110_Verbrennungsmotor_im_Auslauf_mit_Startankuendigung_durch_MSA_Anforderung_ (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx11010_Verbrennungsmotor_im_Auslauf_durch_MSA_Anforderung_) || (defined Cbxxx11010_Verbrennungsmotor_im_Auslauf_durch_MSA_Anforderung_)
#   if (!defined RTE_CONST_Cbxxx11010_Verbrennungsmotor_im_Auslauf_durch_MSA_Anforderung_) || (RTE_CONST_Cbxxx11010_Verbrennungsmotor_im_Auslauf_durch_MSA_Anforderung_ != 0U)
#    error "Enumeration constant <Cbxxx11010_Verbrennungsmotor_im_Auslauf_durch_MSA_Anforderung_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx11010_Verbrennungsmotor_im_Auslauf_durch_MSA_Anforderung_ (0U)
#   define Cbxxx11010_Verbrennungsmotor_im_Auslauf_durch_MSA_Anforderung_ (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx10010_Verbrennungsmotor_im_Auslauf_durch_Fahrerwunsch_) || (defined Cbxxx10010_Verbrennungsmotor_im_Auslauf_durch_Fahrerwunsch_)
#   if (!defined RTE_CONST_Cbxxx10010_Verbrennungsmotor_im_Auslauf_durch_Fahrerwunsch_) || (RTE_CONST_Cbxxx10010_Verbrennungsmotor_im_Auslauf_durch_Fahrerwunsch_ != 0U)
#    error "Enumeration constant <Cbxxx10010_Verbrennungsmotor_im_Auslauf_durch_Fahrerwunsch_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx10010_Verbrennungsmotor_im_Auslauf_durch_Fahrerwunsch_ (0U)
#   define Cbxxx10010_Verbrennungsmotor_im_Auslauf_durch_Fahrerwunsch_ (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx01110_Stoppankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung) || (defined Cbxxx01110_Stoppankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung)
#   if (!defined RTE_CONST_Cbxxx01110_Stoppankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung) || (RTE_CONST_Cbxxx01110_Stoppankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung != 0U)
#    error "Enumeration constant <Cbxxx01110_Stoppankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx01110_Stoppankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung (0U)
#   define Cbxxx01110_Stoppankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx01100_Startankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung_) || (defined Cbxxx01100_Startankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung_)
#   if (!defined RTE_CONST_Cbxxx01100_Startankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung_) || (RTE_CONST_Cbxxx01100_Startankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung_ != 0U)
#    error "Enumeration constant <Cbxxx01100_Startankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx01100_Startankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung_ (0U)
#   define Cbxxx01100_Startankuendigung_des_Verbrennungsmotors_durch_MSA_Anforderung_ (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx01001_Verbrennungsmotor_startet_durch_MSA_Anforderung_) || (defined Cbxxx01001_Verbrennungsmotor_startet_durch_MSA_Anforderung_)
#   if (!defined RTE_CONST_Cbxxx01001_Verbrennungsmotor_startet_durch_MSA_Anforderung_) || (RTE_CONST_Cbxxx01001_Verbrennungsmotor_startet_durch_MSA_Anforderung_ != 0U)
#    error "Enumeration constant <Cbxxx01001_Verbrennungsmotor_startet_durch_MSA_Anforderung_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx01001_Verbrennungsmotor_startet_durch_MSA_Anforderung_ (0U)
#   define Cbxxx01001_Verbrennungsmotor_startet_durch_MSA_Anforderung_ (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx01000_Verbrennungsmotor_steht_durch_MSA_Anforderung) || (defined Cbxxx01000_Verbrennungsmotor_steht_durch_MSA_Anforderung)
#   if (!defined RTE_CONST_Cbxxx01000_Verbrennungsmotor_steht_durch_MSA_Anforderung) || (RTE_CONST_Cbxxx01000_Verbrennungsmotor_steht_durch_MSA_Anforderung != 0U)
#    error "Enumeration constant <Cbxxx01000_Verbrennungsmotor_steht_durch_MSA_Anforderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx01000_Verbrennungsmotor_steht_durch_MSA_Anforderung (0U)
#   define Cbxxx01000_Verbrennungsmotor_steht_durch_MSA_Anforderung (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx00110_Stopankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_) || (defined Cbxxx00110_Stopankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_)
#   if (!defined RTE_CONST_Cbxxx00110_Stopankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_) || (RTE_CONST_Cbxxx00110_Stopankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_ != 0U)
#    error "Enumeration constant <Cbxxx00110_Stopankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx00110_Stopankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_ (0U)
#   define Cbxxx00110_Stopankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_ (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx00100_Startankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_) || (defined Cbxxx00100_Startankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_)
#   if (!defined RTE_CONST_Cbxxx00100_Startankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_) || (RTE_CONST_Cbxxx00100_Startankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_ != 0U)
#    error "Enumeration constant <Cbxxx00100_Startankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx00100_Startankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_ (0U)
#   define Cbxxx00100_Startankuendigung_des_Verbrennungsmotors_durch_Fahrerwunsch_ (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx00010_Verbrennungsmotor_laeuft) || (defined Cbxxx00010_Verbrennungsmotor_laeuft)
#   if (!defined RTE_CONST_Cbxxx00010_Verbrennungsmotor_laeuft) || (RTE_CONST_Cbxxx00010_Verbrennungsmotor_laeuft != 0U)
#    error "Enumeration constant <Cbxxx00010_Verbrennungsmotor_laeuft> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx00010_Verbrennungsmotor_laeuft (0U)
#   define Cbxxx00010_Verbrennungsmotor_laeuft (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx00001_Verbrennungsmotor_startet_durch_Fahrerwunsch_) || (defined Cbxxx00001_Verbrennungsmotor_startet_durch_Fahrerwunsch_)
#   if (!defined RTE_CONST_Cbxxx00001_Verbrennungsmotor_startet_durch_Fahrerwunsch_) || (RTE_CONST_Cbxxx00001_Verbrennungsmotor_startet_durch_Fahrerwunsch_ != 0U)
#    error "Enumeration constant <Cbxxx00001_Verbrennungsmotor_startet_durch_Fahrerwunsch_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx00001_Verbrennungsmotor_startet_durch_Fahrerwunsch_ (0U)
#   define Cbxxx00001_Verbrennungsmotor_startet_durch_Fahrerwunsch_ (0U)
#  endif
#  if (defined RTE_CONST_Cbxxx00000_Verbrennungsmotor_steht_durch_Fahrerwunsch_) || (defined Cbxxx00000_Verbrennungsmotor_steht_durch_Fahrerwunsch_)
#   if (!defined RTE_CONST_Cbxxx00000_Verbrennungsmotor_steht_durch_Fahrerwunsch_) || (RTE_CONST_Cbxxx00000_Verbrennungsmotor_steht_durch_Fahrerwunsch_ != 0U)
#    error "Enumeration constant <Cbxxx00000_Verbrennungsmotor_steht_durch_Fahrerwunsch_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxxx00000_Verbrennungsmotor_steht_durch_Fahrerwunsch_ (0U)
#   define Cbxxx00000_Verbrennungsmotor_steht_durch_Fahrerwunsch_ (0U)
#  endif
#  if (defined RTE_CONST_Cb100xxxxx_Keine_E_Maschine_verfuegbar) || (defined Cb100xxxxx_Keine_E_Maschine_verfuegbar)
#   if (!defined RTE_CONST_Cb100xxxxx_Keine_E_Maschine_verfuegbar) || (RTE_CONST_Cb100xxxxx_Keine_E_Maschine_verfuegbar != 0U)
#    error "Enumeration constant <Cb100xxxxx_Keine_E_Maschine_verfuegbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb100xxxxx_Keine_E_Maschine_verfuegbar (0U)
#   define Cb100xxxxx_Keine_E_Maschine_verfuegbar (0U)
#  endif
#  if (defined RTE_CONST_Cb000xxxxx_E_Maschine_ist_nach__Anforderung_Fahrbereitschaft__von_CAS_FEM_elektr__fahrbereit_od__bereits_aktiv) || (defined Cb000xxxxx_E_Maschine_ist_nach__Anforderung_Fahrbereitschaft__von_CAS_FEM_elektr__fahrbereit_od__bereits_aktiv)
#   if (!defined RTE_CONST_Cb000xxxxx_E_Maschine_ist_nach__Anforderung_Fahrbereitschaft__von_CAS_FEM_elektr__fahrbereit_od__bereits_aktiv) || (RTE_CONST_Cb000xxxxx_E_Maschine_ist_nach__Anforderung_Fahrbereitschaft__von_CAS_FEM_elektr__fahrbereit_od__bereits_aktiv != 0U)
#    error "Enumeration constant <Cb000xxxxx_E_Maschine_ist_nach__Anforderung_Fahrbereitschaft__von_CAS_FEM_elektr__fahrbereit_od__bereits_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb000xxxxx_E_Maschine_ist_nach__Anforderung_Fahrbereitschaft__von_CAS_FEM_elektr__fahrbereit_od__bereits_aktiv (0U)
#   define Cb000xxxxx_E_Maschine_ist_nach__Anforderung_Fahrbereitschaft__von_CAS_FEM_elektr__fahrbereit_od__bereits_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cx83_Initialisierung) || (defined Cx83_Initialisierung)
#   if (!defined RTE_CONST_Cx83_Initialisierung) || (RTE_CONST_Cx83_Initialisierung != 131U)
#    error "Enumeration constant <Cx83_Initialisierung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx83_Initialisierung (131U)
#   define Cx83_Initialisierung (131U)
#  endif
#  if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255U)
#    error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxFF_Signal_ungueltig (255U)
#   define CxFF_Signal_ungueltig (255U)
#  endif

#  define Rte_TypeDef_ST_ENERG_FZM
typedef uint8 ST_ENERG_FZM;
#  define ST_ENERG_FZM_LowerLimit (0U)
#  define ST_ENERG_FZM_UpperLimit (15U)
#  define Rte_InvalidValue_ST_ENERG_FZM (15U)
#  define InvalidValue_ST_ENERG_FZM (15U)
#  if (defined RTE_CONST_Cx0_ENSTATE_GOOD) || (defined Cx0_ENSTATE_GOOD)
#   if (!defined RTE_CONST_Cx0_ENSTATE_GOOD) || (RTE_CONST_Cx0_ENSTATE_GOOD != 0U)
#    error "Enumeration constant <Cx0_ENSTATE_GOOD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_ENSTATE_GOOD (0U)
#   define Cx0_ENSTATE_GOOD (0U)
#  endif
#  if (defined RTE_CONST_Cx1_ENSTATE_OK) || (defined Cx1_ENSTATE_OK)
#   if (!defined RTE_CONST_Cx1_ENSTATE_OK) || (RTE_CONST_Cx1_ENSTATE_OK != 1U)
#    error "Enumeration constant <Cx1_ENSTATE_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_ENSTATE_OK (1U)
#   define Cx1_ENSTATE_OK (1U)
#  endif
#  if (defined RTE_CONST_Cx2_ENSTATE_SHORTAGE) || (defined Cx2_ENSTATE_SHORTAGE)
#   if (!defined RTE_CONST_Cx2_ENSTATE_SHORTAGE) || (RTE_CONST_Cx2_ENSTATE_SHORTAGE != 2U)
#    error "Enumeration constant <Cx2_ENSTATE_SHORTAGE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_ENSTATE_SHORTAGE (2U)
#   define Cx2_ENSTATE_SHORTAGE (2U)
#  endif
#  if (defined RTE_CONST_Cx3_ENSTATE_SEVERE_SHORTAGE) || (defined Cx3_ENSTATE_SEVERE_SHORTAGE)
#   if (!defined RTE_CONST_Cx3_ENSTATE_SEVERE_SHORTAGE) || (RTE_CONST_Cx3_ENSTATE_SEVERE_SHORTAGE != 3U)
#    error "Enumeration constant <Cx3_ENSTATE_SEVERE_SHORTAGE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_ENSTATE_SEVERE_SHORTAGE (3U)
#   define Cx3_ENSTATE_SEVERE_SHORTAGE (3U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_ST_IDC_CC
typedef uint8 ST_IDC_CC;
#  define ST_IDC_CC_LowerLimit (0U)
#  define ST_IDC_CC_UpperLimit (3U)
#  define Rte_InvalidValue_ST_IDC_CC (3U)
#  define InvalidValue_ST_IDC_CC (3U)
#  if (defined RTE_CONST_Cx0_Kein_Blinken) || (defined Cx0_Kein_Blinken)
#   if (!defined RTE_CONST_Cx0_Kein_Blinken) || (RTE_CONST_Cx0_Kein_Blinken != 0U)
#    error "Enumeration constant <Cx0_Kein_Blinken> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Kein_Blinken (0U)
#   define Cx0_Kein_Blinken (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Langsames_Blinken) || (defined Cx1_Langsames_Blinken)
#   if (!defined RTE_CONST_Cx1_Langsames_Blinken) || (RTE_CONST_Cx1_Langsames_Blinken != 1U)
#    error "Enumeration constant <Cx1_Langsames_Blinken> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Langsames_Blinken (1U)
#   define Cx1_Langsames_Blinken (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Schnelles_Blinken) || (defined Cx2_Schnelles_Blinken)
#   if (!defined RTE_CONST_Cx2_Schnelles_Blinken) || (RTE_CONST_Cx2_Schnelles_Blinken != 2U)
#    error "Enumeration constant <Cx2_Schnelles_Blinken> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Schnelles_Blinken (2U)
#   define Cx2_Schnelles_Blinken (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#    error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_ungueltig (3U)
#   define Cx3_Signal_ungueltig (3U)
#  endif

#  define Rte_TypeDef_ST_KL
typedef uint8 ST_KL;
#  define ST_KL_LowerLimit (0U)
#  define ST_KL_UpperLimit (15U)
#  define Rte_InvalidValue_ST_KL (15U)
#  define InvalidValue_ST_KL (15U)
#  if (defined RTE_CONST_Cx0_Init) || (defined Cx0_Init)
#   if (!defined RTE_CONST_Cx0_Init) || (RTE_CONST_Cx0_Init != 0U)
#    error "Enumeration constant <Cx0_Init> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Init (0U)
#   define Cx0_Init (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Reserve) || (defined Cx1_Reserve)
#   if (!defined RTE_CONST_Cx1_Reserve) || (RTE_CONST_Cx1_Reserve != 1U)
#    error "Enumeration constant <Cx1_Reserve> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Reserve (1U)
#   define Cx1_Reserve (1U)
#  endif
#  if (defined RTE_CONST_Cx2_KL30) || (defined Cx2_KL30)
#   if (!defined RTE_CONST_Cx2_KL30) || (RTE_CONST_Cx2_KL30 != 2U)
#    error "Enumeration constant <Cx2_KL30> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_KL30 (2U)
#   define Cx2_KL30 (2U)
#  endif
#  if (defined RTE_CONST_Cx3_KL30F_Aenderung) || (defined Cx3_KL30F_Aenderung)
#   if (!defined RTE_CONST_Cx3_KL30F_Aenderung) || (RTE_CONST_Cx3_KL30F_Aenderung != 3U)
#    error "Enumeration constant <Cx3_KL30F_Aenderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_KL30F_Aenderung (3U)
#   define Cx3_KL30F_Aenderung (3U)
#  endif
#  if (defined RTE_CONST_Cx4_KL30F_Ein) || (defined Cx4_KL30F_Ein)
#   if (!defined RTE_CONST_Cx4_KL30F_Ein) || (RTE_CONST_Cx4_KL30F_Ein != 4U)
#    error "Enumeration constant <Cx4_KL30F_Ein> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_KL30F_Ein (4U)
#   define Cx4_KL30F_Ein (4U)
#  endif
#  if (defined RTE_CONST_Cx5_KL30B_Aenderung) || (defined Cx5_KL30B_Aenderung)
#   if (!defined RTE_CONST_Cx5_KL30B_Aenderung) || (RTE_CONST_Cx5_KL30B_Aenderung != 5U)
#    error "Enumeration constant <Cx5_KL30B_Aenderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx5_KL30B_Aenderung (5U)
#   define Cx5_KL30B_Aenderung (5U)
#  endif
#  if (defined RTE_CONST_Cx6_KL30B_Ein) || (defined Cx6_KL30B_Ein)
#   if (!defined RTE_CONST_Cx6_KL30B_Ein) || (RTE_CONST_Cx6_KL30B_Ein != 6U)
#    error "Enumeration constant <Cx6_KL30B_Ein> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_KL30B_Ein (6U)
#   define Cx6_KL30B_Ein (6U)
#  endif
#  if (defined RTE_CONST_Cx7_KLR_Aenderung) || (defined Cx7_KLR_Aenderung)
#   if (!defined RTE_CONST_Cx7_KLR_Aenderung) || (RTE_CONST_Cx7_KLR_Aenderung != 7U)
#    error "Enumeration constant <Cx7_KLR_Aenderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_KLR_Aenderung (7U)
#   define Cx7_KLR_Aenderung (7U)
#  endif
#  if (defined RTE_CONST_Cx8_KLR_Ein) || (defined Cx8_KLR_Ein)
#   if (!defined RTE_CONST_Cx8_KLR_Ein) || (RTE_CONST_Cx8_KLR_Ein != 8U)
#    error "Enumeration constant <Cx8_KLR_Ein> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_KLR_Ein (8U)
#   define Cx8_KLR_Ein (8U)
#  endif
#  if (defined RTE_CONST_Cx9_KL15_Aenderung) || (defined Cx9_KL15_Aenderung)
#   if (!defined RTE_CONST_Cx9_KL15_Aenderung) || (RTE_CONST_Cx9_KL15_Aenderung != 9U)
#    error "Enumeration constant <Cx9_KL15_Aenderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_KL15_Aenderung (9U)
#   define Cx9_KL15_Aenderung (9U)
#  endif
#  if (defined RTE_CONST_CxA_KL15_Ein) || (defined CxA_KL15_Ein)
#   if (!defined RTE_CONST_CxA_KL15_Ein) || (RTE_CONST_CxA_KL15_Ein != 10U)
#    error "Enumeration constant <CxA_KL15_Ein> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_KL15_Ein (10U)
#   define CxA_KL15_Ein (10U)
#  endif
#  if (defined RTE_CONST_CxB_KL50_Verzoegerung) || (defined CxB_KL50_Verzoegerung)
#   if (!defined RTE_CONST_CxB_KL50_Verzoegerung) || (RTE_CONST_CxB_KL50_Verzoegerung != 11U)
#    error "Enumeration constant <CxB_KL50_Verzoegerung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_KL50_Verzoegerung (11U)
#   define CxB_KL50_Verzoegerung (11U)
#  endif
#  if (defined RTE_CONST_CxC_KL50_Aenderung) || (defined CxC_KL50_Aenderung)
#   if (!defined RTE_CONST_CxC_KL50_Aenderung) || (RTE_CONST_CxC_KL50_Aenderung != 12U)
#    error "Enumeration constant <CxC_KL50_Aenderung> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_KL50_Aenderung (12U)
#   define CxC_KL50_Aenderung (12U)
#  endif
#  if (defined RTE_CONST_CxD_KL50_Ein) || (defined CxD_KL50_Ein)
#   if (!defined RTE_CONST_CxD_KL50_Ein) || (RTE_CONST_CxD_KL50_Ein != 13U)
#    error "Enumeration constant <CxD_KL50_Ein> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_KL50_Ein (13U)
#   define CxD_KL50_Ein (13U)
#  endif
#  if (defined RTE_CONST_CxE_Fehler) || (defined CxE_Fehler)
#   if (!defined RTE_CONST_CxE_Fehler) || (RTE_CONST_CxE_Fehler != 14U)
#    error "Enumeration constant <CxE_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Fehler (14U)
#   define CxE_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_ST_KL_15N
typedef uint8 ST_KL_15N;
#  define ST_KL_15N_LowerLimit (0U)
#  define ST_KL_15N_UpperLimit (15U)
#  define Rte_InvalidValue_ST_KL_15N (15U)
#  define InvalidValue_ST_KL_15N (15U)
#  if (defined RTE_CONST_Cx0_Init_Wert) || (defined Cx0_Init_Wert)
#   if (!defined RTE_CONST_Cx0_Init_Wert) || (RTE_CONST_Cx0_Init_Wert != 0U)
#    error "Enumeration constant <Cx0_Init_Wert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Init_Wert (0U)
#   define Cx0_Init_Wert (0U)
#  endif
#  if (defined RTE_CONST_Cx1_KL15N_Aus) || (defined Cx1_KL15N_Aus)
#   if (!defined RTE_CONST_Cx1_KL15N_Aus) || (RTE_CONST_Cx1_KL15N_Aus != 1U)
#    error "Enumeration constant <Cx1_KL15N_Aus> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_KL15N_Aus (1U)
#   define Cx1_KL15N_Aus (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms) || (defined Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms)
#   if (!defined RTE_CONST_Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms) || (RTE_CONST_Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms != 2U)
#    error "Enumeration constant <Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms (2U)
#   define Cx2_Nachlauf_groesser_0s_und__kleinergleich_1000ms (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms) || (defined Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms)
#   if (!defined RTE_CONST_Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms) || (RTE_CONST_Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms != 3U)
#    error "Enumeration constant <Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms (3U)
#   define Cx3_Nachlauf_groesser_1000ms_und_kleinergleich_2000ms (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms) || (defined Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms)
#   if (!defined RTE_CONST_Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms) || (RTE_CONST_Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms != 4U)
#    error "Enumeration constant <Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms (4U)
#   define Cx4_Nachlauf_groesser_2000ms_und_kleinergleich_3000ms (4U)
#  endif
#  if (defined RTE_CONST_Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms) || (defined Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms)
#   if (!defined RTE_CONST_Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms) || (RTE_CONST_Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms != 5U)
#    error "Enumeration constant <Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms (5U)
#   define Cx5_Nachlauf_groesser_3000ms_und_kleinergleich_4000ms (5U)
#  endif
#  if (defined RTE_CONST_Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms) || (defined Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms)
#   if (!defined RTE_CONST_Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms) || (RTE_CONST_Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms != 6U)
#    error "Enumeration constant <Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms (6U)
#   define Cx6_Nachlauf_groesser_4000ms_undkleinergleich_5000ms (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Reserviert) || (defined Cx7_Reserviert)
#   if (!defined RTE_CONST_Cx7_Reserviert) || (RTE_CONST_Cx7_Reserviert != 7U)
#    error "Enumeration constant <Cx7_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Reserviert (7U)
#   define Cx7_Reserviert (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Reserviert) || (defined Cx8_Reserviert)
#   if (!defined RTE_CONST_Cx8_Reserviert) || (RTE_CONST_Cx8_Reserviert != 8U)
#    error "Enumeration constant <Cx8_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Reserviert (8U)
#   define Cx8_Reserviert (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Reserviert) || (defined Cx9_Reserviert)
#   if (!defined RTE_CONST_Cx9_Reserviert) || (RTE_CONST_Cx9_Reserviert != 9U)
#    error "Enumeration constant <Cx9_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Reserviert (9U)
#   define Cx9_Reserviert (9U)
#  endif
#  if (defined RTE_CONST_CxA_Reserviert) || (defined CxA_Reserviert)
#   if (!defined RTE_CONST_CxA_Reserviert) || (RTE_CONST_CxA_Reserviert != 10U)
#    error "Enumeration constant <CxA_Reserviert> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Reserviert (10U)
#   define CxA_Reserviert (10U)
#  endif
#  if (defined RTE_CONST_CxB_Nachlauf_kleiner_1_min) || (defined CxB_Nachlauf_kleiner_1_min)
#   if (!defined RTE_CONST_CxB_Nachlauf_kleiner_1_min) || (RTE_CONST_CxB_Nachlauf_kleiner_1_min != 11U)
#    error "Enumeration constant <CxB_Nachlauf_kleiner_1_min> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_Nachlauf_kleiner_1_min (11U)
#   define CxB_Nachlauf_kleiner_1_min (11U)
#  endif
#  if (defined RTE_CONST_CxC_Nachlauf_Fahrt_Motorlauf) || (defined CxC_Nachlauf_Fahrt_Motorlauf)
#   if (!defined RTE_CONST_CxC_Nachlauf_Fahrt_Motorlauf) || (RTE_CONST_CxC_Nachlauf_Fahrt_Motorlauf != 12U)
#    error "Enumeration constant <CxC_Nachlauf_Fahrt_Motorlauf> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_Nachlauf_Fahrt_Motorlauf (12U)
#   define CxC_Nachlauf_Fahrt_Motorlauf (12U)
#  endif
#  if (defined RTE_CONST_CxD_KL15N_Dauer_Ein) || (defined CxD_KL15N_Dauer_Ein)
#   if (!defined RTE_CONST_CxD_KL15N_Dauer_Ein) || (RTE_CONST_CxD_KL15N_Dauer_Ein != 13U)
#    error "Enumeration constant <CxD_KL15N_Dauer_Ein> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_KL15N_Dauer_Ein (13U)
#   define CxD_KL15N_Dauer_Ein (13U)
#  endif
#  if (defined RTE_CONST_CxE_Fehler) || (defined CxE_Fehler)
#   if (!defined RTE_CONST_CxE_Fehler) || (RTE_CONST_CxE_Fehler != 14U)
#    error "Enumeration constant <CxE_Fehler> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Fehler (14U)
#   define CxE_Fehler (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_ST_OBD_CYC
typedef uint8 ST_OBD_CYC;
#  define ST_OBD_CYC_LowerLimit (0U)
#  define ST_OBD_CYC_UpperLimit (63U)
#  define Rte_InvalidValue_ST_OBD_CYC (63U)
#  define InvalidValue_ST_OBD_CYC (63U)
#  if (defined RTE_CONST_Cbxx0xx1_Warm_Up_Zyklus_aktiv) || (defined Cbxx0xx1_Warm_Up_Zyklus_aktiv)
#   if (!defined RTE_CONST_Cbxx0xx1_Warm_Up_Zyklus_aktiv) || (RTE_CONST_Cbxx0xx1_Warm_Up_Zyklus_aktiv != 0U)
#    error "Enumeration constant <Cbxx0xx1_Warm_Up_Zyklus_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxx0xx1_Warm_Up_Zyklus_aktiv (0U)
#   define Cbxx0xx1_Warm_Up_Zyklus_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cbxx0xx0_Warm_Up_Zyklus_nicht_aktiv) || (defined Cbxx0xx0_Warm_Up_Zyklus_nicht_aktiv)
#   if (!defined RTE_CONST_Cbxx0xx0_Warm_Up_Zyklus_nicht_aktiv) || (RTE_CONST_Cbxx0xx0_Warm_Up_Zyklus_nicht_aktiv != 0U)
#    error "Enumeration constant <Cbxx0xx0_Warm_Up_Zyklus_nicht_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxx0xx0_Warm_Up_Zyklus_nicht_aktiv (0U)
#   define Cbxx0xx0_Warm_Up_Zyklus_nicht_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cbxx0x1x_Driving_Zyklus_aktiv) || (defined Cbxx0x1x_Driving_Zyklus_aktiv)
#   if (!defined RTE_CONST_Cbxx0x1x_Driving_Zyklus_aktiv) || (RTE_CONST_Cbxx0x1x_Driving_Zyklus_aktiv != 0U)
#    error "Enumeration constant <Cbxx0x1x_Driving_Zyklus_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxx0x1x_Driving_Zyklus_aktiv (0U)
#   define Cbxx0x1x_Driving_Zyklus_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cbxx0x0x_Driving_Zyklus_nicht_aktiv) || (defined Cbxx0x0x_Driving_Zyklus_nicht_aktiv)
#   if (!defined RTE_CONST_Cbxx0x0x_Driving_Zyklus_nicht_aktiv) || (RTE_CONST_Cbxx0x0x_Driving_Zyklus_nicht_aktiv != 0U)
#    error "Enumeration constant <Cbxx0x0x_Driving_Zyklus_nicht_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbxx0x0x_Driving_Zyklus_nicht_aktiv (0U)
#   define Cbxx0x0x_Driving_Zyklus_nicht_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cbx10xxx_PFC_Zyklus_erfuellt) || (defined Cbx10xxx_PFC_Zyklus_erfuellt)
#   if (!defined RTE_CONST_Cbx10xxx_PFC_Zyklus_erfuellt) || (RTE_CONST_Cbx10xxx_PFC_Zyklus_erfuellt != 0U)
#    error "Enumeration constant <Cbx10xxx_PFC_Zyklus_erfuellt> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbx10xxx_PFC_Zyklus_erfuellt (0U)
#   define Cbx10xxx_PFC_Zyklus_erfuellt (0U)
#  endif
#  if (defined RTE_CONST_Cbx00xxx_Kein_PFC_Zyklus) || (defined Cbx00xxx_Kein_PFC_Zyklus)
#   if (!defined RTE_CONST_Cbx00xxx_Kein_PFC_Zyklus) || (RTE_CONST_Cbx00xxx_Kein_PFC_Zyklus != 0U)
#    error "Enumeration constant <Cbx00xxx_Kein_PFC_Zyklus> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cbx00xxx_Kein_PFC_Zyklus (0U)
#   define Cbx00xxx_Kein_PFC_Zyklus (0U)
#  endif
#  if (defined RTE_CONST_Cb1x00xx_RBM_Zyklus_nicht_erfuellbar) || (defined Cb1x00xx_RBM_Zyklus_nicht_erfuellbar)
#   if (!defined RTE_CONST_Cb1x00xx_RBM_Zyklus_nicht_erfuellbar) || (RTE_CONST_Cb1x00xx_RBM_Zyklus_nicht_erfuellbar != 0U)
#    error "Enumeration constant <Cb1x00xx_RBM_Zyklus_nicht_erfuellbar> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb1x00xx_RBM_Zyklus_nicht_erfuellbar (0U)
#   define Cb1x00xx_RBM_Zyklus_nicht_erfuellbar (0U)
#  endif
#  if (defined RTE_CONST_Cb0x01xx_RBM_Zyklus_aktiv) || (defined Cb0x01xx_RBM_Zyklus_aktiv)
#   if (!defined RTE_CONST_Cb0x01xx_RBM_Zyklus_aktiv) || (RTE_CONST_Cb0x01xx_RBM_Zyklus_aktiv != 0U)
#    error "Enumeration constant <Cb0x01xx_RBM_Zyklus_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0x01xx_RBM_Zyklus_aktiv (0U)
#   define Cb0x01xx_RBM_Zyklus_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cb0x00xx_RBM_Zyklus_nicht_aktiv) || (defined Cb0x00xx_RBM_Zyklus_nicht_aktiv)
#   if (!defined RTE_CONST_Cb0x00xx_RBM_Zyklus_nicht_aktiv) || (RTE_CONST_Cb0x00xx_RBM_Zyklus_nicht_aktiv != 0U)
#    error "Enumeration constant <Cb0x00xx_RBM_Zyklus_nicht_aktiv> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cb0x00xx_RBM_Zyklus_nicht_aktiv (0U)
#   define Cb0x00xx_RBM_Zyklus_nicht_aktiv (0U)
#  endif
#  if (defined RTE_CONST_Cx3F_Signal_ungueltig) || (defined Cx3F_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3F_Signal_ungueltig) || (RTE_CONST_Cx3F_Signal_ungueltig != 63U)
#    error "Enumeration constant <Cx3F_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3F_Signal_ungueltig (63U)
#   define Cx3F_Signal_ungueltig (63U)
#  endif

#  define Rte_TypeDef_ST_VEH_CON
typedef uint8 ST_VEH_CON;
#  define ST_VEH_CON_LowerLimit (0U)
#  define ST_VEH_CON_UpperLimit (15U)
#  define Rte_InvalidValue_ST_VEH_CON (15U)
#  define InvalidValue_ST_VEH_CON (15U)
#  if (defined RTE_CONST_Cx0_Initial__VSM_STM_STATE_INIT_) || (defined Cx0_Initial__VSM_STM_STATE_INIT_)
#   if (!defined RTE_CONST_Cx0_Initial__VSM_STM_STATE_INIT_) || (RTE_CONST_Cx0_Initial__VSM_STM_STATE_INIT_ != 0U)
#    error "Enumeration constant <Cx0_Initial__VSM_STM_STATE_INIT_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Initial__VSM_STM_STATE_INIT_ (0U)
#   define Cx0_Initial__VSM_STM_STATE_INIT_ (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Standby__driver_absent__VSM_STM_STATE_STANDBY_) || (defined Cx1_Standby__driver_absent__VSM_STM_STATE_STANDBY_)
#   if (!defined RTE_CONST_Cx1_Standby__driver_absent__VSM_STM_STATE_STANDBY_) || (RTE_CONST_Cx1_Standby__driver_absent__VSM_STM_STATE_STANDBY_ != 1U)
#    error "Enumeration constant <Cx1_Standby__driver_absent__VSM_STM_STATE_STANDBY_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Standby__driver_absent__VSM_STM_STATE_STANDBY_ (1U)
#   define Cx1_Standby__driver_absent__VSM_STM_STATE_STANDBY_ (1U)
#  endif
#  if (defined RTE_CONST_Cx2_Basis_operation__driver_present__VSM_STM_STATE_BASICOP_) || (defined Cx2_Basis_operation__driver_present__VSM_STM_STATE_BASICOP_)
#   if (!defined RTE_CONST_Cx2_Basis_operation__driver_present__VSM_STM_STATE_BASICOP_) || (RTE_CONST_Cx2_Basis_operation__driver_present__VSM_STM_STATE_BASICOP_ != 2U)
#    error "Enumeration constant <Cx2_Basis_operation__driver_present__VSM_STM_STATE_BASICOP_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx2_Basis_operation__driver_present__VSM_STM_STATE_BASICOP_ (2U)
#   define Cx2_Basis_operation__driver_present__VSM_STM_STATE_BASICOP_ (2U)
#  endif
#  if (defined RTE_CONST_Cx3_Basis_operation__vehicle_coasting__VSM_STM_STATE_BASICOP_ROLL_) || (defined Cx3_Basis_operation__vehicle_coasting__VSM_STM_STATE_BASICOP_ROLL_)
#   if (!defined RTE_CONST_Cx3_Basis_operation__vehicle_coasting__VSM_STM_STATE_BASICOP_ROLL_) || (RTE_CONST_Cx3_Basis_operation__vehicle_coasting__VSM_STM_STATE_BASICOP_ROLL_ != 3U)
#    error "Enumeration constant <Cx3_Basis_operation__vehicle_coasting__VSM_STM_STATE_BASICOP_ROLL_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Basis_operation__vehicle_coasting__VSM_STM_STATE_BASICOP_ROLL_ (3U)
#   define Cx3_Basis_operation__vehicle_coasting__VSM_STM_STATE_BASICOP_ROLL_ (3U)
#  endif
#  if (defined RTE_CONST_Cx4_Engine_postrun__VSM_STM_STATE_15OFF_DRIVE_) || (defined Cx4_Engine_postrun__VSM_STM_STATE_15OFF_DRIVE_)
#   if (!defined RTE_CONST_Cx4_Engine_postrun__VSM_STM_STATE_15OFF_DRIVE_) || (RTE_CONST_Cx4_Engine_postrun__VSM_STM_STATE_15OFF_DRIVE_ != 4U)
#    error "Enumeration constant <Cx4_Engine_postrun__VSM_STM_STATE_15OFF_DRIVE_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx4_Engine_postrun__VSM_STM_STATE_15OFF_DRIVE_ (4U)
#   define Cx4_Engine_postrun__VSM_STM_STATE_15OFF_DRIVE_ (4U)
#  endif
#  if (defined RTE_CONST_Cx5_Ignition_On__VSM_STM_STATE_IGNITION_) || (defined Cx5_Ignition_On__VSM_STM_STATE_IGNITION_)
#   if (!defined RTE_CONST_Cx5_Ignition_On__VSM_STM_STATE_IGNITION_) || (RTE_CONST_Cx5_Ignition_On__VSM_STM_STATE_IGNITION_ != 5U)
#    error "Enumeration constant <Cx5_Ignition_On__VSM_STM_STATE_IGNITION_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx5_Ignition_On__VSM_STM_STATE_IGNITION_ (5U)
#   define Cx5_Ignition_On__VSM_STM_STATE_IGNITION_ (5U)
#  endif
#  if (defined RTE_CONST_Cx6_Ignition_On__vehicle_coasting__VSM_STM_STATE_IGNITION_ROLL_) || (defined Cx6_Ignition_On__vehicle_coasting__VSM_STM_STATE_IGNITION_ROLL_)
#   if (!defined RTE_CONST_Cx6_Ignition_On__vehicle_coasting__VSM_STM_STATE_IGNITION_ROLL_) || (RTE_CONST_Cx6_Ignition_On__vehicle_coasting__VSM_STM_STATE_IGNITION_ROLL_ != 6U)
#    error "Enumeration constant <Cx6_Ignition_On__vehicle_coasting__VSM_STM_STATE_IGNITION_ROLL_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx6_Ignition_On__vehicle_coasting__VSM_STM_STATE_IGNITION_ROLL_ (6U)
#   define Cx6_Ignition_On__vehicle_coasting__VSM_STM_STATE_IGNITION_ROLL_ (6U)
#  endif
#  if (defined RTE_CONST_Cx7_Ignition_On__vehicle_not_coasting__VSM_STM_STATE_ENG_IDLE_) || (defined Cx7_Ignition_On__vehicle_not_coasting__VSM_STM_STATE_ENG_IDLE_)
#   if (!defined RTE_CONST_Cx7_Ignition_On__vehicle_not_coasting__VSM_STM_STATE_ENG_IDLE_) || (RTE_CONST_Cx7_Ignition_On__vehicle_not_coasting__VSM_STM_STATE_ENG_IDLE_ != 7U)
#    error "Enumeration constant <Cx7_Ignition_On__vehicle_not_coasting__VSM_STM_STATE_ENG_IDLE_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx7_Ignition_On__vehicle_not_coasting__VSM_STM_STATE_ENG_IDLE_ (7U)
#   define Cx7_Ignition_On__vehicle_not_coasting__VSM_STM_STATE_ENG_IDLE_ (7U)
#  endif
#  if (defined RTE_CONST_Cx8_Driving___VSM_STM_STATE_DRIVE_) || (defined Cx8_Driving___VSM_STM_STATE_DRIVE_)
#   if (!defined RTE_CONST_Cx8_Driving___VSM_STM_STATE_DRIVE_) || (RTE_CONST_Cx8_Driving___VSM_STM_STATE_DRIVE_ != 8U)
#    error "Enumeration constant <Cx8_Driving___VSM_STM_STATE_DRIVE_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx8_Driving___VSM_STM_STATE_DRIVE_ (8U)
#   define Cx8_Driving___VSM_STM_STATE_DRIVE_ (8U)
#  endif
#  if (defined RTE_CONST_Cx9_Impending_start_of_engine__VSM_STM_STATE_ENG_START_PRE_) || (defined Cx9_Impending_start_of_engine__VSM_STM_STATE_ENG_START_PRE_)
#   if (!defined RTE_CONST_Cx9_Impending_start_of_engine__VSM_STM_STATE_ENG_START_PRE_) || (RTE_CONST_Cx9_Impending_start_of_engine__VSM_STM_STATE_ENG_START_PRE_ != 9U)
#    error "Enumeration constant <Cx9_Impending_start_of_engine__VSM_STM_STATE_ENG_START_PRE_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx9_Impending_start_of_engine__VSM_STM_STATE_ENG_START_PRE_ (9U)
#   define Cx9_Impending_start_of_engine__VSM_STM_STATE_ENG_START_PRE_ (9U)
#  endif
#  if (defined RTE_CONST_CxA_Impending_start_of_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_PRE_ROLL_) || (defined CxA_Impending_start_of_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_PRE_ROLL_)
#   if (!defined RTE_CONST_CxA_Impending_start_of_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_PRE_ROLL_) || (RTE_CONST_CxA_Impending_start_of_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_PRE_ROLL_ != 10U)
#    error "Enumeration constant <CxA_Impending_start_of_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_PRE_ROLL_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxA_Impending_start_of_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_PRE_ROLL_ (10U)
#   define CxA_Impending_start_of_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_PRE_ROLL_ (10U)
#  endif
#  if (defined RTE_CONST_CxB_Start_engine__VSM_STM_STATE_ENG_START_) || (defined CxB_Start_engine__VSM_STM_STATE_ENG_START_)
#   if (!defined RTE_CONST_CxB_Start_engine__VSM_STM_STATE_ENG_START_) || (RTE_CONST_CxB_Start_engine__VSM_STM_STATE_ENG_START_ != 11U)
#    error "Enumeration constant <CxB_Start_engine__VSM_STM_STATE_ENG_START_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxB_Start_engine__VSM_STM_STATE_ENG_START_ (11U)
#   define CxB_Start_engine__VSM_STM_STATE_ENG_START_ (11U)
#  endif
#  if (defined RTE_CONST_CxC_Start_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_ROLL_) || (defined CxC_Start_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_ROLL_)
#   if (!defined RTE_CONST_CxC_Start_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_ROLL_) || (RTE_CONST_CxC_Start_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_ROLL_ != 12U)
#    error "Enumeration constant <CxC_Start_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_ROLL_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxC_Start_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_ROLL_ (12U)
#   define CxC_Start_engine__vehicle_coasting__VSM_STM_STATE_ENG_START_ROLL_ (12U)
#  endif
#  if (defined RTE_CONST_CxD_Car_wash_operation__VSM_STM_STATE_WASH_) || (defined CxD_Car_wash_operation__VSM_STM_STATE_WASH_)
#   if (!defined RTE_CONST_CxD_Car_wash_operation__VSM_STM_STATE_WASH_) || (RTE_CONST_CxD_Car_wash_operation__VSM_STM_STATE_WASH_ != 13U)
#    error "Enumeration constant <CxD_Car_wash_operation__VSM_STM_STATE_WASH_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxD_Car_wash_operation__VSM_STM_STATE_WASH_ (13U)
#   define CxD_Car_wash_operation__VSM_STM_STATE_WASH_ (13U)
#  endif
#  if (defined RTE_CONST_CxE_Error__VSM_STM_STATE_ERROR_) || (defined CxE_Error__VSM_STM_STATE_ERROR_)
#   if (!defined RTE_CONST_CxE_Error__VSM_STM_STATE_ERROR_) || (RTE_CONST_CxE_Error__VSM_STM_STATE_ERROR_ != 14U)
#    error "Enumeration constant <CxE_Error__VSM_STM_STATE_ERROR_> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxE_Error__VSM_STM_STATE_ERROR_ (14U)
#   define CxE_Error__VSM_STM_STATE_ERROR_ (14U)
#  endif
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_StOpRamp_User
typedef uint8 StOpRamp_User;
#  define StOpRamp_User_LowerLimit (0U)
#  define StOpRamp_User_UpperLimit (16U)
#  if (defined RTE_CONST_SOR_VEHPWRMD) || (defined SOR_VEHPWRMD)
#   if (!defined RTE_CONST_SOR_VEHPWRMD) || (RTE_CONST_SOR_VEHPWRMD != 0U)
#    error "Enumeration constant <SOR_VEHPWRMD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_VEHPWRMD (0U)
#   define SOR_VEHPWRMD (0U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR0) || (defined SOR_DIAGMGR0)
#   if (!defined RTE_CONST_SOR_DIAGMGR0) || (RTE_CONST_SOR_DIAGMGR0 != 1U)
#    error "Enumeration constant <SOR_DIAGMGR0> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR0 (1U)
#   define SOR_DIAGMGR0 (1U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR1) || (defined SOR_DIAGMGR1)
#   if (!defined RTE_CONST_SOR_DIAGMGR1) || (RTE_CONST_SOR_DIAGMGR1 != 2U)
#    error "Enumeration constant <SOR_DIAGMGR1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR1 (2U)
#   define SOR_DIAGMGR1 (2U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR2) || (defined SOR_DIAGMGR2)
#   if (!defined RTE_CONST_SOR_DIAGMGR2) || (RTE_CONST_SOR_DIAGMGR2 != 3U)
#    error "Enumeration constant <SOR_DIAGMGR2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR2 (3U)
#   define SOR_DIAGMGR2 (3U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR3) || (defined SOR_DIAGMGR3)
#   if (!defined RTE_CONST_SOR_DIAGMGR3) || (RTE_CONST_SOR_DIAGMGR3 != 4U)
#    error "Enumeration constant <SOR_DIAGMGR3> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR3 (4U)
#   define SOR_DIAGMGR3 (4U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR4) || (defined SOR_DIAGMGR4)
#   if (!defined RTE_CONST_SOR_DIAGMGR4) || (RTE_CONST_SOR_DIAGMGR4 != 5U)
#    error "Enumeration constant <SOR_DIAGMGR4> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR4 (5U)
#   define SOR_DIAGMGR4 (5U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR5) || (defined SOR_DIAGMGR5)
#   if (!defined RTE_CONST_SOR_DIAGMGR5) || (RTE_CONST_SOR_DIAGMGR5 != 6U)
#    error "Enumeration constant <SOR_DIAGMGR5> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR5 (6U)
#   define SOR_DIAGMGR5 (6U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR6) || (defined SOR_DIAGMGR6)
#   if (!defined RTE_CONST_SOR_DIAGMGR6) || (RTE_CONST_SOR_DIAGMGR6 != 7U)
#    error "Enumeration constant <SOR_DIAGMGR6> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR6 (7U)
#   define SOR_DIAGMGR6 (7U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR7) || (defined SOR_DIAGMGR7)
#   if (!defined RTE_CONST_SOR_DIAGMGR7) || (RTE_CONST_SOR_DIAGMGR7 != 8U)
#    error "Enumeration constant <SOR_DIAGMGR7> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR7 (8U)
#   define SOR_DIAGMGR7 (8U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR8) || (defined SOR_DIAGMGR8)
#   if (!defined RTE_CONST_SOR_DIAGMGR8) || (RTE_CONST_SOR_DIAGMGR8 != 9U)
#    error "Enumeration constant <SOR_DIAGMGR8> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR8 (9U)
#   define SOR_DIAGMGR8 (9U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR9) || (defined SOR_DIAGMGR9)
#   if (!defined RTE_CONST_SOR_DIAGMGR9) || (RTE_CONST_SOR_DIAGMGR9 != 10U)
#    error "Enumeration constant <SOR_DIAGMGR9> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR9 (10U)
#   define SOR_DIAGMGR9 (10U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR10) || (defined SOR_DIAGMGR10)
#   if (!defined RTE_CONST_SOR_DIAGMGR10) || (RTE_CONST_SOR_DIAGMGR10 != 11U)
#    error "Enumeration constant <SOR_DIAGMGR10> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR10 (11U)
#   define SOR_DIAGMGR10 (11U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR11) || (defined SOR_DIAGMGR11)
#   if (!defined RTE_CONST_SOR_DIAGMGR11) || (RTE_CONST_SOR_DIAGMGR11 != 12U)
#    error "Enumeration constant <SOR_DIAGMGR11> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR11 (12U)
#   define SOR_DIAGMGR11 (12U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR12) || (defined SOR_DIAGMGR12)
#   if (!defined RTE_CONST_SOR_DIAGMGR12) || (RTE_CONST_SOR_DIAGMGR12 != 13U)
#    error "Enumeration constant <SOR_DIAGMGR12> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR12 (13U)
#   define SOR_DIAGMGR12 (13U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR_F2) || (defined SOR_DIAGMGR_F2)
#   if (!defined RTE_CONST_SOR_DIAGMGR_F2) || (RTE_CONST_SOR_DIAGMGR_F2 != 14U)
#    error "Enumeration constant <SOR_DIAGMGR_F2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR_F2 (14U)
#   define SOR_DIAGMGR_F2 (14U)
#  endif
#  if (defined RTE_CONST_SOR_DIAGMGR_F1) || (defined SOR_DIAGMGR_F1)
#   if (!defined RTE_CONST_SOR_DIAGMGR_F1) || (RTE_CONST_SOR_DIAGMGR_F1 != 15U)
#    error "Enumeration constant <SOR_DIAGMGR_F1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_DIAGMGR_F1 (15U)
#   define SOR_DIAGMGR_F1 (15U)
#  endif
#  if (defined RTE_CONST_SOR_NUMUSERS) || (defined SOR_NUMUSERS)
#   if (!defined RTE_CONST_SOR_NUMUSERS) || (RTE_CONST_SOR_NUMUSERS != 16U)
#    error "Enumeration constant <SOR_NUMUSERS> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SOR_NUMUSERS (16U)
#   define SOR_NUMUSERS (16U)
#  endif

#  define Rte_TypeDef_SysSt_CmdType
typedef uint16 SysSt_CmdType;
#  define SysSt_CmdType_LowerLimit (0U)
#  define SysSt_CmdType_UpperLimit (65535U)
#  if (defined RTE_CONST_SYSST_OPERATE) || (defined SYSST_OPERATE)
#   if (!defined RTE_CONST_SYSST_OPERATE) || (RTE_CONST_SYSST_OPERATE != 0U)
#    error "Enumeration constant <SYSST_OPERATE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SYSST_OPERATE (0U)
#   define SYSST_OPERATE (0U)
#  endif
#  if (defined RTE_CONST_SYSST_WARMINIT) || (defined SYSST_WARMINIT)
#   if (!defined RTE_CONST_SYSST_WARMINIT) || (RTE_CONST_SYSST_WARMINIT != 1U)
#    error "Enumeration constant <SYSST_WARMINIT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SYSST_WARMINIT (1U)
#   define SYSST_WARMINIT (1U)
#  endif
#  if (defined RTE_CONST_SYSST_DISABLE) || (defined SYSST_DISABLE)
#   if (!defined RTE_CONST_SYSST_DISABLE) || (RTE_CONST_SYSST_DISABLE != 2U)
#    error "Enumeration constant <SYSST_DISABLE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SYSST_DISABLE (2U)
#   define SYSST_DISABLE (2U)
#  endif
#  if (defined RTE_CONST_SYSST_OFF) || (defined SYSST_OFF)
#   if (!defined RTE_CONST_SYSST_OFF) || (RTE_CONST_SYSST_OFF != 3U)
#    error "Enumeration constant <SYSST_OFF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_SYSST_OFF (3U)
#   define SYSST_OFF (3U)
#  endif

#  define Rte_TypeDef_TRANF_CC
typedef uint8 TRANF_CC;
#  define TRANF_CC_LowerLimit (0U)
#  define TRANF_CC_UpperLimit (15U)
#  define Rte_InvalidValue_TRANF_CC (15U)
#  define InvalidValue_TRANF_CC (15U)
#  if (defined RTE_CONST_CxF_Signal_ungueltig) || (defined CxF_Signal_ungueltig)
#   if (!defined RTE_CONST_CxF_Signal_ungueltig) || (RTE_CONST_CxF_Signal_ungueltig != 15U)
#    error "Enumeration constant <CxF_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CxF_Signal_ungueltig (15U)
#   define CxF_Signal_ungueltig (15U)
#  endif

#  define Rte_TypeDef_TurnsCounterValidity_T
typedef uint8 TurnsCounterValidity_T;
#  define TurnsCounterValidity_T_LowerLimit (0U)
#  define TurnsCounterValidity_T_UpperLimit (255U)
#  if (defined RTE_CONST_TCV_COMPUTING) || (defined TCV_COMPUTING)
#   if (!defined RTE_CONST_TCV_COMPUTING) || (RTE_CONST_TCV_COMPUTING != 0U)
#    error "Enumeration constant <TCV_COMPUTING> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TCV_COMPUTING (0U)
#   define TCV_COMPUTING (0U)
#  endif
#  if (defined RTE_CONST_TCV_VALID) || (defined TCV_VALID)
#   if (!defined RTE_CONST_TCV_VALID) || (RTE_CONST_TCV_VALID != 100U)
#    error "Enumeration constant <TCV_VALID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TCV_VALID (100U)
#   define TCV_VALID (100U)
#  endif
#  if (defined RTE_CONST_TCV_INVALID) || (defined TCV_INVALID)
#   if (!defined RTE_CONST_TCV_INVALID) || (RTE_CONST_TCV_INVALID != 255U)
#    error "Enumeration constant <TCV_INVALID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TCV_INVALID (255U)
#   define TCV_INVALID (255U)
#  endif

#  define Rte_TypeDef_UN_TARVL_PMA
typedef uint8 UN_TARVL_PMA;
#  define UN_TARVL_PMA_LowerLimit (0U)
#  define UN_TARVL_PMA_UpperLimit (3U)
#  define Rte_InvalidValue_UN_TARVL_PMA (3U)
#  define InvalidValue_UN_TARVL_PMA (3U)
#  if (defined RTE_CONST_Cx0_Ritzelschnittstelle) || (defined Cx0_Ritzelschnittstelle)
#   if (!defined RTE_CONST_Cx0_Ritzelschnittstelle) || (RTE_CONST_Cx0_Ritzelschnittstelle != 0U)
#    error "Enumeration constant <Cx0_Ritzelschnittstelle> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx0_Ritzelschnittstelle (0U)
#   define Cx0_Ritzelschnittstelle (0U)
#  endif
#  if (defined RTE_CONST_Cx1_Zahnstangenhubschnittstelle) || (defined Cx1_Zahnstangenhubschnittstelle)
#   if (!defined RTE_CONST_Cx1_Zahnstangenhubschnittstelle) || (RTE_CONST_Cx1_Zahnstangenhubschnittstelle != 1U)
#    error "Enumeration constant <Cx1_Zahnstangenhubschnittstelle> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx1_Zahnstangenhubschnittstelle (1U)
#   define Cx1_Zahnstangenhubschnittstelle (1U)
#  endif
#  if (defined RTE_CONST_Cx3_Signal_ungueltig) || (defined Cx3_Signal_ungueltig)
#   if (!defined RTE_CONST_Cx3_Signal_ungueltig) || (RTE_CONST_Cx3_Signal_ungueltig != 3U)
#    error "Enumeration constant <Cx3_Signal_ungueltig> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_Cx3_Signal_ungueltig (3U)
#   define Cx3_Signal_ungueltig (3U)
#  endif

#  define Rte_TypeDef_DT_Array10_s16
typedef SInt16 DT_Array10_s16[10];

#  define Rte_TypeDef_DT_Array10_u16
typedef UInt16 DT_Array10_u16[10];

#  define Rte_TypeDef_DT_Array11_s16
typedef SInt16 DT_Array11_s16[11];

#  define Rte_TypeDef_DT_Array11_u16
typedef UInt16 DT_Array11_u16[11];

#  define Rte_TypeDef_DT_Array12_s16
typedef SInt16 DT_Array12_s16[12];

#  define Rte_TypeDef_DT_Array12_u16
typedef UInt16 DT_Array12_u16[12];

#  define Rte_TypeDef_DT_Array13_s16
typedef SInt16 DT_Array13_s16[13];

#  define Rte_TypeDef_DT_Array13_u16
typedef UInt16 DT_Array13_u16[13];

#  define Rte_TypeDef_DT_Array14_s16
typedef SInt16 DT_Array14_s16[14];

#  define Rte_TypeDef_DT_Array14_u16
typedef UInt16 DT_Array14_u16[14];

#  define Rte_TypeDef_DT_Array15_s16
typedef SInt16 DT_Array15_s16[15];

#  define Rte_TypeDef_DT_Array15_u16
typedef UInt16 DT_Array15_u16[15];

#  define Rte_TypeDef_DT_Array16_s16
typedef SInt16 DT_Array16_s16[16];

#  define Rte_TypeDef_DT_Array16_u16
typedef UInt16 DT_Array16_u16[16];

#  define Rte_TypeDef_DT_Array17_s16
typedef SInt16 DT_Array17_s16[17];

#  define Rte_TypeDef_DT_Array17_u16
typedef UInt16 DT_Array17_u16[17];

#  define Rte_TypeDef_DT_Array18_s16
typedef SInt16 DT_Array18_s16[18];

#  define Rte_TypeDef_DT_Array18_u16
typedef UInt16 DT_Array18_u16[18];

#  define Rte_TypeDef_DT_Array19_s16
typedef SInt16 DT_Array19_s16[19];

#  define Rte_TypeDef_DT_Array19_u16
typedef UInt16 DT_Array19_u16[19];

#  define Rte_TypeDef_DT_Array20_s16
typedef SInt16 DT_Array20_s16[20];

#  define Rte_TypeDef_DT_Array20_u16
typedef UInt16 DT_Array20_u16[20];

#  define Rte_TypeDef_DT_Array21_s16
typedef SInt16 DT_Array21_s16[21];

#  define Rte_TypeDef_DT_Array21_u16
typedef UInt16 DT_Array21_u16[21];

#  define Rte_TypeDef_DT_Array22_s16
typedef SInt16 DT_Array22_s16[22];

#  define Rte_TypeDef_DT_Array22_u16
typedef UInt16 DT_Array22_u16[22];

#  define Rte_TypeDef_DT_Array23_s16
typedef SInt16 DT_Array23_s16[23];

#  define Rte_TypeDef_DT_Array23_u16
typedef UInt16 DT_Array23_u16[23];

#  define Rte_TypeDef_DT_Array24_s16
typedef SInt16 DT_Array24_s16[24];

#  define Rte_TypeDef_DT_Array24_u16
typedef UInt16 DT_Array24_u16[24];

#  define Rte_TypeDef_DT_Array25_s16
typedef SInt16 DT_Array25_s16[25];

#  define Rte_TypeDef_DT_Array25_u16
typedef UInt16 DT_Array25_u16[25];

#  define Rte_TypeDef_DT_Array26_s16
typedef SInt16 DT_Array26_s16[26];

#  define Rte_TypeDef_DT_Array26_u16
typedef UInt16 DT_Array26_u16[26];

#  define Rte_TypeDef_DT_Array27_s16
typedef SInt16 DT_Array27_s16[27];

#  define Rte_TypeDef_DT_Array27_u16
typedef UInt16 DT_Array27_u16[27];

#  define Rte_TypeDef_DT_Array28_s16
typedef SInt16 DT_Array28_s16[28];

#  define Rte_TypeDef_DT_Array28_u16
typedef UInt16 DT_Array28_u16[28];

#  define Rte_TypeDef_DT_Array29_s16
typedef SInt16 DT_Array29_s16[29];

#  define Rte_TypeDef_DT_Array29_u16
typedef UInt16 DT_Array29_u16[29];

#  define Rte_TypeDef_DT_Array2_f32
typedef Float DT_Array2_f32[2];

#  define Rte_TypeDef_DT_Array2_s16
typedef SInt16 DT_Array2_s16[2];

#  define Rte_TypeDef_DT_Array2_u16
typedef UInt16 DT_Array2_u16[2];

#  define Rte_TypeDef_DT_Array30_s16
typedef SInt16 DT_Array30_s16[30];

#  define Rte_TypeDef_DT_Array30_u16
typedef UInt16 DT_Array30_u16[30];

#  define Rte_TypeDef_DT_Array31_s16
typedef SInt16 DT_Array31_s16[31];

#  define Rte_TypeDef_DT_Array31_u16
typedef UInt16 DT_Array31_u16[31];

#  define Rte_TypeDef_DT_Array32_s16
typedef SInt16 DT_Array32_s16[32];

#  define Rte_TypeDef_DT_Array32_u16
typedef UInt16 DT_Array32_u16[32];

#  define Rte_TypeDef_DT_Array3_s16
typedef SInt16 DT_Array3_s16[3];

#  define Rte_TypeDef_DT_Array3_u16
typedef UInt16 DT_Array3_u16[3];

#  define Rte_TypeDef_DT_Array4_s16
typedef SInt16 DT_Array4_s16[4];

#  define Rte_TypeDef_DT_Array4_u16
typedef UInt16 DT_Array4_u16[4];

#  define Rte_TypeDef_DT_Array5_s16
typedef SInt16 DT_Array5_s16[5];

#  define Rte_TypeDef_DT_Array5_u16
typedef UInt16 DT_Array5_u16[5];

#  define Rte_TypeDef_DT_Array6_s16
typedef SInt16 DT_Array6_s16[6];

#  define Rte_TypeDef_DT_Array6_u16
typedef UInt16 DT_Array6_u16[6];

#  define Rte_TypeDef_DT_Array7_s16
typedef SInt16 DT_Array7_s16[7];

#  define Rte_TypeDef_DT_Array7_u16
typedef UInt16 DT_Array7_u16[7];

#  define Rte_TypeDef_DT_Array8_s16
typedef SInt16 DT_Array8_s16[8];

#  define Rte_TypeDef_DT_Array8_u16
typedef UInt16 DT_Array8_u16[8];

#  define Rte_TypeDef_DT_Array9_s16
typedef SInt16 DT_Array9_s16[9];

#  define Rte_TypeDef_DT_Array9_u16
typedef UInt16 DT_Array9_u16[9];

#  define Rte_TypeDef_DstPtrType
typedef UInt8 DstPtrType[203];

#  define Rte_TypeDef_TypeHRamBufferType
typedef UInt8 TypeHRamBufferType[100];

#  define Rte_TypeDef_DT_NTCStrg
typedef struct
{
  UInt8 NTC;
  UInt8 Param;
  Dem_EventStatusExtendedType Status;
} DT_NTCStrg;

#  define Rte_TypeDef_DiagMgrProxyElement
typedef struct
{
  NTCNumber NTCNumber;
  UInt8 Param;
  NxtrDiagMgrStatus Status;
} DiagMgrProxyElement;

#  define Rte_TypeDef_DiagSettings_Str
typedef struct
{
  UInt16 Threshold;
  UInt16 PStep;
  UInt16 NStep;
} DiagSettings_Str;

#  define Rte_TypeDef_EOLChOffsetTrim_DataType
typedef struct
{
  Float HwTqArb_EOLChOffsetTrim_HwNm_f32;
  Boolean HwTqArb_EOLChOffsetTrimPerf_Cnt_lgc;
} EOLChOffsetTrim_DataType;

#  define Rte_TypeDef_LTVehCntr_DataType
typedef struct
{
  Boolean LTVehCntrComplete;
  UInt8 R_LTVehCntrComplete;
} LTVehCntr_DataType;

#  define Rte_TypeDef_MtrParamCal_DataType
typedef struct
{
  Float EOLNomKe_VpRadpS_f32;
  Float EOLNomL_Henry_f32;
  Float EOLNomRmtr_Ohm_f32;
} MtrParamCal_DataType;

#  define Rte_TypeDef_MtrParmLearned_DataType
typedef struct
{
  Float KeFBckTyH_VpRadpS_f32;
  Float RFBckTyH_Ohm_f32;
} MtrParmLearned_DataType;

#  define Rte_TypeDef_MtrPos2Cal_DataType
typedef struct
{
  UInt16 Sin2Offset_Volts_u3p13;
  UInt16 Sin2AmpRec_Uls_u3p13;
  UInt16 Cos2Offset_Volts_u3p13;
  UInt16 Cos2AmpRec_Uls_u3p13;
  SInt16 SinDelta2_Uls_s2p13;
  UInt16 CosDelta2Rec_Uls_u3p13;
} MtrPos2Cal_DataType;

#  define Rte_TypeDef_MtrPos3Cal_DataType
typedef struct
{
  UInt16 BEMFCal_Rev_u0p16;
  UInt16 Sin3Offset_Volts_u3p13;
  UInt16 Sin3AmpRec_Uls_u3p13;
  UInt16 Cos3Offset_Volts_u3p13;
  UInt16 Cos3AmpRec_Uls_u3p13;
  SInt16 SinDelta3_Uls_s2p13;
  UInt16 CosDelta3Rec_Uls_u3p13;
} MtrPos3Cal_DataType;

#  define Rte_TypeDef_MtrSnsrLearned_DataType
typedef struct
{
  Float Cos1MaxTyH_Volts_f32;
  Float Cos1MinTyH_Volts_f32;
  Float Sin1MaxTyH_Volts_f32;
  Float Sin1MinTyH_Volts_f32;
  Float Cos2MaxTyH_Volts_f32;
  Float Cos2MinTyH_Volts_f32;
  Float Sin2MaxTyH_Volts_f32;
  Float Sin2MinTyH_Volts_f32;
} MtrSnsrLearned_DataType;

#  define Rte_TypeDef_RT_AVL_PO_EPS
typedef struct
{
  DT_CRC_AVL_PO_EPS CRC;
  DT_ALIV_AVL_PO_EPS ALIV_AVL_PO_EPS;
  DT_QU_AVL_PO_EPS QU_AVL;
  DT_AVL_PO_EPS AVL_PO_EPS;
  DT_AVL_PO_IDX_EPS IDX_EPS;
  DT_OFFS_GRD_MID_EPS OFFS;
  DT_IDX_TORQ_SEN TORQ;
  DT_UN_PO_EPS UN_PO;
} RT_AVL_PO_EPS;

#  define Rte_TypeDef_RT_AVL_STMOM
typedef struct
{
  DT_CRC_AVL_STMOM_DV_ACT CRC_AVL_STMOM_DV_ACT;
  DT_ALIV_AVL_STMOM_DV_ACT ALIV_AVL_STMOM_DV_ACT;
  DT_QU_HOFF_RCOG QU_HOFF_RCOG;
  DT_AVL_STMOM_DV_ACT AVL_STMOM_DV_ACT;
  DT_QU_AVL_STMOM_DV_ACT QU_AVL_STMOM_DV_ACT;
  DT_CRC_AVL_FORC_GRD CRC_AVL_FORC_GRD;
  DT_ALIV_AVL_FORC_GRD ALIV_AVL_FORC_GRD;
  DT_AVL_FORC_GRD AVL_FORC_GRD;
  DT_QU_AVL_FORC_GRD QU_AVL_FORC_GRD;
  DT_AVL_PWR_EL_EPS_COOD AVL_PWR_EL_EPS_COOD;
} RT_AVL_STMOM;

#  define Rte_TypeDef_RT_DISP_CC_DRDY_02
typedef struct
{
  DT_ALIV_DISP_CC_DRDY_02 ALIV_DISP_CC_DRDY_02;
  DT_NO_CC_DRDY_02 NO_CC_DRDY_02;
  DT_ST_CC_DRDY_02 ST_CC_DRDY_02;
  DT_TRANF_CC_DRDY_02 TRANF_CC_DRDY_02;
  DT_ST_IDC_CC_DRDY_02 ST_IDC_CC_DRDY_02;
} RT_DISP_CC_DRDY_02;

#  define Rte_TypeDef_RT_RampCmd
typedef struct
{
  Float target_X_f32;
  Float rate_XpmS_f32;
} RT_RampCmd;

#  define Rte_TypeDef_RT_SG_TAR_QTA_STRMOM_DV
typedef struct
{
  ALIV_COU_4 ALIV_TAR_QTA_STMOM_DV;
  CRC8 CRC_TAR_QTA_STMOM_DV;
  FACT_ASS_STMOM_FTAX FACT_ASS_STMOM_FTAX;
  FACT_CTRR_STMOM_FTAX FACT_CTRR_STMOM_FTAX;
  FACT_CTRR_STMOM_FTAX FACT_DMPNG_STMOM_FTAX;
  QU_TAR_FACT_STMOM_FTAX QU_TAR_FACT_STMOM_FTAX;
  QU_TAR_QTA_STMOM_DV QU_TAR_QTA_STMOM_DV;
  STMOM_QTA_DV TAR_QTA_STMOM_DV;
} RT_SG_TAR_QTA_STRMOM_DV;

#  define Rte_TypeDef_RT_SG_TAR_STMOM_DV_ACT
typedef struct
{
  ALIV_COU_4 ALIV_TAR_STMOM_DV_ACT;
  CRC8 CRC_TAR_STMOM_DV_ACT;
  QU_TAR_STMOM_DV_ACT QU_TAR_STMOM_DV_ACT;
  QU_TARVL_PMA QU_TARVL_PMA;
  TAR_STMOM_DV_ACT TAR_STMOM_DV_ACT;
  TARVL_PMA TARVL_PMA;
  UN_TARVL_PMA UN_TARVL_PMA;
} RT_SG_TAR_STMOM_DV_ACT;

#  define Rte_TypeDef_RT_ST_EST
typedef struct
{
  DT_CRC_ST_EST_FTAX CRC_ST_EST_FTAX;
  DT_ALIV_ST_EST_FTAX ALIV_ST_EST_FTAX;
  DT_QU_SER_PINA_EST_FTAX QU_SER_PINA_EST_FTAX;
  DT_QU_SER_STMOM_DV_ACT QU_SER_STMOM_DV_ACT;
  DT_QU_FN_EST QU_FN_EST;
} RT_ST_EST;

#  define Rte_TypeDef_RT_SU_EPS
typedef struct
{
  DT_TOT_STR_EPS TOT_STR_EPS;
  DT_UN_TOT_STR_EPS UN_TOT_STR_EPS;
} RT_SU_EPS;

#  define Rte_TypeDef_RacktoVehCntr_DataType
typedef struct
{
  UInt16 RacktoVehCntrOffset;
  UInt16 R_RacktoVehCntrOffset;
} RacktoVehCntr_DataType;

#  define Rte_TypeDef_SG_SU_SW_DRDY
typedef struct
{
  MOD_SW_DRDY_CHAS AVL_MOD_SW_DRDY_CHAS;
  MOD_SW_DRDY_DRV AVL_MOD_SW_DRDY_DRV;
  RQ_SU_SW_DRDY RQ_SU_SW_DRDY;
  ALIV_COU_4 ALIV_SU_SW_DRDY;
  DISP_ST_DSC DISP_ST_DSC;
  CRC8 CRC_SU_SW_DRDY;
  AVL_MOD_SW_DRDY_2 AVL_MOD_SW_DRDY;
  AVL_MOD_SW_DRDY_STAB AVL_MOD_SW_DRDY_STAB;
} SG_SU_SW_DRDY;

#  define Rte_TypeDef_VehCntrOffset_DataType
typedef struct
{
  Float VehCntrOffset;
  UInt32 R_VehCntrOffset;
} VehCntrOffset_DataType;

#  define Rte_TypeDef_DT_Array16x32_u16
typedef DT_Array32_u16 DT_Array16x32_u16[16];

#  define Rte_TypeDef_DT_Array5x5_u16
typedef DT_Array5_u16 DT_Array5x5_u16[5];

#  define Rte_TypeDef_DT_NTCStrgArray
typedef DT_NTCStrg DT_NTCStrgArray[15];

# endif


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
typedef uint8 Rte_ModeType_EcuM_Mode;
typedef uint8 Rte_ModeType_StaMd_Mode;

# define RTE_MODE_EcuM_Mode_POST_RUN (0U)
# define RTE_MODE_EcuM_Mode_RUN (1U)
# define RTE_MODE_EcuM_Mode_SHUTDOWN (2U)
# define RTE_MODE_EcuM_Mode_SLEEP (3U)
# define RTE_MODE_EcuM_Mode_STARTUP (4U)
# define RTE_MODE_EcuM_Mode_WAKE_SLEEP (5U)
# define RTE_TRANSITION_EcuM_Mode (6U)

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

# if (defined RTE_CONST_D_CAAPAABORTSTNODRVGINTRPT_CNT_U08) || (defined D_CAAPAABORTSTNODRVGINTRPT_CNT_U08)
#  if (!defined RTE_CONST_D_CAAPAABORTSTNODRVGINTRPT_CNT_U08) || (RTE_CONST_D_CAAPAABORTSTNODRVGINTRPT_CNT_U08 != 0U)
#   error "Constant value <D_CAAPAABORTSTNODRVGINTRPT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CAAPAABORTSTNODRVGINTRPT_CNT_U08 (0U)
#  define D_CAAPAABORTSTNODRVGINTRPT_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_CAAPAREQSTNOREQ_CNT_U08) || (defined D_CAAPAREQSTNOREQ_CNT_U08)
#  if (!defined RTE_CONST_D_CAAPAREQSTNOREQ_CNT_U08) || (RTE_CONST_D_CAAPAREQSTNOREQ_CNT_U08 != 0U)
#   error "Constant value <D_CAAPAREQSTNOREQ_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CAAPAREQSTNOREQ_CNT_U08 (0U)
#  define D_CAAPAREQSTNOREQ_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM) || (defined D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM) || (RTE_CONST_D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM != 0U)
#   error "Constant value <D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM (0U)
#  define D_BATTSWDVLTGCORRSTATINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_SYSPRFMNCSTNORMOPERINIT) || (defined SYSPRFMNCSTNORMOPERINIT)
#  if (!defined RTE_CONST_SYSPRFMNCSTNORMOPERINIT) || (RTE_CONST_SYSPRFMNCSTNORMOPERINIT != 0U)
#   error "Constant value <SYSPRFMNCSTNORMOPERINIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCSTNORMOPERINIT (0U)
#  define SYSPRFMNCSTNORMOPERINIT (0U)
# endif

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

# if (defined RTE_CONST_D_SFINVMILLI_ULS_F32) || (defined D_SFINVMILLI_ULS_F32)
#  if (!defined RTE_CONST_D_SFINVMILLI_ULS_F32) || (RTE_CONST_D_SFINVMILLI_ULS_F32 != 1000)
#   error "Constant value <D_SFINVMILLI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SFINVMILLI_ULS_F32 (1000)
#  define D_SFINVMILLI_ULS_F32 (1000)
# endif

# if (defined RTE_CONST_D_DMCINIT_CNT_ENUM) || (defined D_DMCINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_DMCINIT_CNT_ENUM) || (RTE_CONST_D_DMCINIT_CNT_ENUM != 1U)
#   error "Constant value <D_DMCINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_DMCINIT_CNT_ENUM (1U)
#  define D_DMCINIT_CNT_ENUM (1U)
# endif

# if (defined RTE_CONST_D_100MS_SEC_F32) || (defined D_100MS_SEC_F32)
#  if (!defined RTE_CONST_D_100MS_SEC_F32) || (RTE_CONST_D_100MS_SEC_F32 != 0.1F)
#   error "Constant value <D_100MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_100MS_SEC_F32 (0.1F)
#  define D_100MS_SEC_F32 (0.1F)
# endif

# if (defined RTE_CONST_D_180OVRPI_ULS_F32) || (defined D_180OVRPI_ULS_F32)
#  if (!defined RTE_CONST_D_180OVRPI_ULS_F32) || (RTE_CONST_D_180OVRPI_ULS_F32 != 57.295779513082F)
#   error "Constant value <D_180OVRPI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_180OVRPI_ULS_F32 (57.295779513082F)
#  define D_180OVRPI_ULS_F32 (57.295779513082F)
# endif

# if (defined RTE_CONST_D_2MS_MS_F32) || (defined D_2MS_MS_F32)
#  if (!defined RTE_CONST_D_2MS_MS_F32) || (RTE_CONST_D_2MS_MS_F32 != 0.002F)
#   error "Constant value <D_2MS_MS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_MS_F32 (0.002F)
#  define D_2MS_MS_F32 (0.002F)
# endif

# if (defined RTE_CONST_D_2MS_SEC_F32) || (defined D_2MS_SEC_F32)
#  if (!defined RTE_CONST_D_2MS_SEC_F32) || (RTE_CONST_D_2MS_SEC_F32 != 0.002F)
#   error "Constant value <D_2MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_SEC_F32 (0.002F)
#  define D_2MS_SEC_F32 (0.002F)
# endif

# if (defined RTE_CONST_D_2PI_ULS_F32) || (defined D_2PI_ULS_F32)
#  if (!defined RTE_CONST_D_2PI_ULS_F32) || (RTE_CONST_D_2PI_ULS_F32 != 6.2831853071796F)
#   error "Constant value <D_2PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2PI_ULS_F32 (6.2831853071796F)
#  define D_2PI_ULS_F32 (6.2831853071796F)
# endif

# if (defined RTE_CONST_D_BMWVEHICLESPEEDINIT_CNT_F32) || (defined D_BMWVEHICLESPEEDINIT_CNT_F32)
#  if (!defined RTE_CONST_D_BMWVEHICLESPEEDINIT_CNT_F32) || (RTE_CONST_D_BMWVEHICLESPEEDINIT_CNT_F32 != 100.0F)
#   error "Constant value <D_BMWVEHICLESPEEDINIT_CNT_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_BMWVEHICLESPEEDINIT_CNT_F32 (100.0F)
#  define D_BMWVEHICLESPEEDINIT_CNT_F32 (100.0F)
# endif

# if (defined RTE_CONST_D_CCWEOTINIT_HWDEG_F32) || (defined D_CCWEOTINIT_HWDEG_F32)
#  if (!defined RTE_CONST_D_CCWEOTINIT_HWDEG_F32) || (RTE_CONST_D_CCWEOTINIT_HWDEG_F32 != -360.0F)
#   error "Constant value <D_CCWEOTINIT_HWDEG_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CCWEOTINIT_HWDEG_F32 (-360.0F)
#  define D_CCWEOTINIT_HWDEG_F32 (-360.0F)
# endif

# if (defined RTE_CONST_D_CWEOTINIT_HWDEG_F32) || (defined D_CWEOTINIT_HWDEG_F32)
#  if (!defined RTE_CONST_D_CWEOTINIT_HWDEG_F32) || (RTE_CONST_D_CWEOTINIT_HWDEG_F32 != 360.0F)
#   error "Constant value <D_CWEOTINIT_HWDEG_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CWEOTINIT_HWDEG_F32 (360.0F)
#  define D_CWEOTINIT_HWDEG_F32 (360.0F)
# endif

# if (defined RTE_CONST_D_ESTKE_VPRADPS_F32) || (defined D_ESTKE_VPRADPS_F32)
#  if (!defined RTE_CONST_D_ESTKE_VPRADPS_F32) || (RTE_CONST_D_ESTKE_VPRADPS_F32 != 0.025F)
#   error "Constant value <D_ESTKE_VPRADPS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ESTKE_VPRADPS_F32 (0.025F)
#  define D_ESTKE_VPRADPS_F32 (0.025F)
# endif

# if (defined RTE_CONST_D_HALF_ULS_F32) || (defined D_HALF_ULS_F32)
#  if (!defined RTE_CONST_D_HALF_ULS_F32) || (RTE_CONST_D_HALF_ULS_F32 != 0.5F)
#   error "Constant value <D_HALF_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_HALF_ULS_F32 (0.5F)
#  define D_HALF_ULS_F32 (0.5F)
# endif

# if (defined RTE_CONST_D_MAXSUPPLYLMT_WATTS_F32) || (defined D_MAXSUPPLYLMT_WATTS_F32)
#  if (!defined RTE_CONST_D_MAXSUPPLYLMT_WATTS_F32) || (RTE_CONST_D_MAXSUPPLYLMT_WATTS_F32 != 2000.0F)
#   error "Constant value <D_MAXSUPPLYLMT_WATTS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MAXSUPPLYLMT_WATTS_F32 (2000.0F)
#  define D_MAXSUPPLYLMT_WATTS_F32 (2000.0F)
# endif

# if (defined RTE_CONST_D_MSECPERSEC_ULS_F32) || (defined D_MSECPERSEC_ULS_F32)
#  if (!defined RTE_CONST_D_MSECPERSEC_ULS_F32) || (RTE_CONST_D_MSECPERSEC_ULS_F32 != 1000.0F)
#   error "Constant value <D_MSECPERSEC_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MSECPERSEC_ULS_F32 (1000.0F)
#  define D_MSECPERSEC_ULS_F32 (1000.0F)
# endif

# if (defined RTE_CONST_D_MTRCTRLHIGHLMT_VOLTS_F32) || (defined D_MTRCTRLHIGHLMT_VOLTS_F32)
#  if (!defined RTE_CONST_D_MTRCTRLHIGHLMT_VOLTS_F32) || (RTE_CONST_D_MTRCTRLHIGHLMT_VOLTS_F32 != 18.0F)
#   error "Constant value <D_MTRCTRLHIGHLMT_VOLTS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRCTRLHIGHLMT_VOLTS_F32 (18.0F)
#  define D_MTRCTRLHIGHLMT_VOLTS_F32 (18.0F)
# endif

# if (defined RTE_CONST_D_MTRCTRLLOWLMT_VOLTS_F32) || (defined D_MTRCTRLLOWLMT_VOLTS_F32)
#  if (!defined RTE_CONST_D_MTRCTRLLOWLMT_VOLTS_F32) || (RTE_CONST_D_MTRCTRLLOWLMT_VOLTS_F32 != 9.0F)
#   error "Constant value <D_MTRCTRLLOWLMT_VOLTS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRCTRLLOWLMT_VOLTS_F32 (9.0F)
#  define D_MTRCTRLLOWLMT_VOLTS_F32 (9.0F)
# endif

# if (defined RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32) || (defined D_MTRRAMPRATEFALL_MTRNMPS_F32)
#  if (!defined RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32) || (RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32 != -4400.0F)
#   error "Constant value <D_MTRRAMPRATEFALL_MTRNMPS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32 (-4400.0F)
#  define D_MTRRAMPRATEFALL_MTRNMPS_F32 (-4400.0F)
# endif

# if (defined RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32) || (defined D_MTRRAMPRATERISE_MTRNMPS_F32)
#  if (!defined RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32) || (RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32 != 4400.0F)
#   error "Constant value <D_MTRRAMPRATERISE_MTRNMPS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32 (4400.0F)
#  define D_MTRRAMPRATERISE_MTRNMPS_F32 (4400.0F)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (defined D_MTRTRQCMDHILMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 != 8.8F)
#   error "Constant value <D_MTRTRQCMDHILMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
#  define D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32) || (defined D_MTRTRQCMDLOLMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32 != -8.8F)
#   error "Constant value <D_MTRTRQCMDLOLMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32 (-8.8F)
#  define D_MTRTRQCMDLOLMT_MTRNM_F32 (-8.8F)
# endif

# if (defined RTE_CONST_D_MTRTRQCMLOLMT_MTRNM_F32) || (defined D_MTRTRQCMLOLMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMLOLMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMLOLMT_MTRNM_F32 != -8.8F)
#   error "Constant value <D_MTRTRQCMLOLMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMLOLMT_MTRNM_F32 (-8.8F)
#  define D_MTRTRQCMLOLMT_MTRNM_F32 (-8.8F)
# endif

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1.0F)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1.0F)
#  define D_ONE_ULS_F32 (1.0F)
# endif

# if (defined RTE_CONST_D_PIOVR180_ULS_F32) || (defined D_PIOVR180_ULS_F32)
#  if (!defined RTE_CONST_D_PIOVR180_ULS_F32) || (RTE_CONST_D_PIOVR180_ULS_F32 != 0.0174532925199F)
#   error "Constant value <D_PIOVR180_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PIOVR180_ULS_F32 (0.0174532925199F)
#  define D_PIOVR180_ULS_F32 (0.0174532925199F)
# endif

# if (defined RTE_CONST_D_PI_ULS_F32) || (defined D_PI_ULS_F32)
#  if (!defined RTE_CONST_D_PI_ULS_F32) || (RTE_CONST_D_PI_ULS_F32 != 3.1415926535898F)
#   error "Constant value <D_PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PI_ULS_F32 (3.1415926535898F)
#  define D_PI_ULS_F32 (3.1415926535898F)
# endif

# if (defined RTE_CONST_D_RADPERREV_ULS_F32) || (defined D_RADPERREV_ULS_F32)
#  if (!defined RTE_CONST_D_RADPERREV_ULS_F32) || (RTE_CONST_D_RADPERREV_ULS_F32 != 6.28318530718F)
#   error "Constant value <D_RADPERREV_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RADPERREV_ULS_F32 (6.28318530718F)
#  define D_RADPERREV_ULS_F32 (6.28318530718F)
# endif

# if (defined RTE_CONST_D_SFMILLI_ULS_F32) || (defined D_SFMILLI_ULS_F32)
#  if (!defined RTE_CONST_D_SFMILLI_ULS_F32) || (RTE_CONST_D_SFMILLI_ULS_F32 != 0.001F)
#   error "Constant value <D_SFMILLI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SFMILLI_ULS_F32 (0.001F)
#  define D_SFMILLI_ULS_F32 (0.001F)
# endif

# if (defined RTE_CONST_D_SUPPLYCURRINIT_AMP_F32) || (defined D_SUPPLYCURRINIT_AMP_F32)
#  if (!defined RTE_CONST_D_SUPPLYCURRINIT_AMP_F32) || (RTE_CONST_D_SUPPLYCURRINIT_AMP_F32 != 166.67F)
#   error "Constant value <D_SUPPLYCURRINIT_AMP_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SUPPLYCURRINIT_AMP_F32 (166.67F)
#  define D_SUPPLYCURRINIT_AMP_F32 (166.67F)
# endif

# if (defined RTE_CONST_D_TRQOSCFREQINIT_F32) || (defined D_TRQOSCFREQINIT_F32)
#  if (!defined RTE_CONST_D_TRQOSCFREQINIT_F32) || (RTE_CONST_D_TRQOSCFREQINIT_F32 != 50.0F)
#   error "Constant value <D_TRQOSCFREQINIT_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRQOSCFREQINIT_F32 (50.0F)
#  define D_TRQOSCFREQINIT_F32 (50.0F)
# endif

# if (defined RTE_CONST_D_TRQOSCFREQINIT_HZ_F32) || (defined D_TRQOSCFREQINIT_HZ_F32)
#  if (!defined RTE_CONST_D_TRQOSCFREQINIT_HZ_F32) || (RTE_CONST_D_TRQOSCFREQINIT_HZ_F32 != 50.0F)
#   error "Constant value <D_TRQOSCFREQINIT_HZ_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRQOSCFREQINIT_HZ_F32 (50.0F)
#  define D_TRQOSCFREQINIT_HZ_F32 (50.0F)
# endif

# if (defined RTE_CONST_D_TRQOVLFREQINIT_HZ_F32) || (defined D_TRQOVLFREQINIT_HZ_F32)
#  if (!defined RTE_CONST_D_TRQOVLFREQINIT_HZ_F32) || (RTE_CONST_D_TRQOVLFREQINIT_HZ_F32 != 3.0F)
#   error "Constant value <D_TRQOVLFREQINIT_HZ_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRQOVLFREQINIT_HZ_F32 (3.0F)
#  define D_TRQOVLFREQINIT_HZ_F32 (3.0F)
# endif

# if (defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (defined D_VECUMIN_VOLTS_F32)
#  if (!defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (RTE_CONST_D_VECUMIN_VOLTS_F32 != 5.0F)
#   error "Constant value <D_VECUMIN_VOLTS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_VECUMIN_VOLTS_F32 (5.0F)
#  define D_VECUMIN_VOLTS_F32 (5.0F)
# endif

# if (defined RTE_CONST_D_VEHWHLBASEINIT_MM_F32) || (defined D_VEHWHLBASEINIT_MM_F32)
#  if (!defined RTE_CONST_D_VEHWHLBASEINIT_MM_F32) || (RTE_CONST_D_VEHWHLBASEINIT_MM_F32 != 3000.0F)
#   error "Constant value <D_VEHWHLBASEINIT_MM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_VEHWHLBASEINIT_MM_F32 (3000.0F)
#  define D_VEHWHLBASEINIT_MM_F32 (3000.0F)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif

# if (defined RTE_CONST_D_IMCARBRRXSTS_NODATA) || (defined D_IMCARBRRXSTS_NODATA)
#  if (!defined RTE_CONST_D_IMCARBRRXSTS_NODATA) || (RTE_CONST_D_IMCARBRRXSTS_NODATA != 0U)
#   error "Constant value <D_IMCARBRRXSTS_NODATA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_IMCARBRRXSTS_NODATA (0U)
#  define D_IMCARBRRXSTS_NODATA (0U)
# endif

# if (defined RTE_CONST_D_IMCSIGSTSINIT_ENUM) || (defined D_IMCSIGSTSINIT_ENUM)
#  if (!defined RTE_CONST_D_IMCSIGSTSINIT_ENUM) || (RTE_CONST_D_IMCSIGSTSINIT_ENUM != 0U)
#   error "Constant value <D_IMCSIGSTSINIT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_IMCSIGSTSINIT_ENUM (0U)
#  define D_IMCSIGSTSINIT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_LOASTATEINIT_CNT_ENUM) || (defined D_LOASTATEINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_LOASTATEINIT_CNT_ENUM) || (RTE_CONST_D_LOASTATEINIT_CNT_ENUM != 0U)
#   error "Constant value <D_LOASTATEINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_LOASTATEINIT_CNT_ENUM (0U)
#  define D_LOASTATEINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_CALDWSTHAPTCRDY_CNT_U08) || (defined D_CALDWSTHAPTCRDY_CNT_U08)
#  if (!defined RTE_CONST_D_CALDWSTHAPTCRDY_CNT_U08) || (RTE_CONST_D_CALDWSTHAPTCRDY_CNT_U08 != 0U)
#   error "Constant value <D_CALDWSTHAPTCRDY_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CALDWSTHAPTCRDY_CNT_U08 (0U)
#  define D_CALDWSTHAPTCRDY_CNT_U08 (0U)
# endif

# if (defined RTE_CONST_D_CALKASTINACTV_CNT_U08) || (defined D_CALKASTINACTV_CNT_U08)
#  if (!defined RTE_CONST_D_CALKASTINACTV_CNT_U08) || (RTE_CONST_D_CALKASTINACTV_CNT_U08 != 1U)
#   error "Constant value <D_CALKASTINACTV_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CALKASTINACTV_CNT_U08 (1U)
#  define D_CALKASTINACTV_CNT_U08 (1U)
# endif

# if (defined RTE_CONST_D_MSA_CMD_INIT) || (defined D_MSA_CMD_INIT)
#  if (!defined RTE_CONST_D_MSA_CMD_INIT) || (RTE_CONST_D_MSA_CMD_INIT != 3U)
#   error "Constant value <D_MSA_CMD_INIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MSA_CMD_INIT (3U)
#  define D_MSA_CMD_INIT (3U)
# endif

# if (defined RTE_CONST_RQ_SU_SW_DRDY_INIT) || (defined RQ_SU_SW_DRDY_INIT)
#  if (!defined RTE_CONST_RQ_SU_SW_DRDY_INIT) || (RTE_CONST_RQ_SU_SW_DRDY_INIT != 0U)
#   error "Constant value <RQ_SU_SW_DRDY_INIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_RQ_SU_SW_DRDY_INIT (0U)
#  define RQ_SU_SW_DRDY_INIT (0U)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S16) || (defined D_NEGONE_CNT_S16)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S16) || (RTE_CONST_D_NEGONE_CNT_S16 != -1)
#   error "Constant value <D_NEGONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S16 (-1)
#  define D_NEGONE_CNT_S16 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S16) || (defined D_ONE_CNT_S16)
#  if (!defined RTE_CONST_D_ONE_CNT_S16) || (RTE_CONST_D_ONE_CNT_S16 != 1)
#   error "Constant value <D_ONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S16 (1)
#  define D_ONE_CNT_S16 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S16) || (defined D_ZERO_CNT_S16)
#  if (!defined RTE_CONST_D_ZERO_CNT_S16) || (RTE_CONST_D_ZERO_CNT_S16 != 0)
#   error "Constant value <D_ZERO_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S16 (0)
#  define D_ZERO_CNT_S16 (0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S32) || (defined D_NEGONE_CNT_S32)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S32) || (RTE_CONST_D_NEGONE_CNT_S32 != -1)
#   error "Constant value <D_NEGONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S32 (-1)
#  define D_NEGONE_CNT_S32 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S32) || (defined D_ONE_CNT_S32)
#  if (!defined RTE_CONST_D_ONE_CNT_S32) || (RTE_CONST_D_ONE_CNT_S32 != 1)
#   error "Constant value <D_ONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S32 (1)
#  define D_ONE_CNT_S32 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S32) || (defined D_ZERO_CNT_S32)
#  if (!defined RTE_CONST_D_ZERO_CNT_S32) || (RTE_CONST_D_ZERO_CNT_S32 != 0)
#   error "Constant value <D_ZERO_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S32 (0)
#  define D_ZERO_CNT_S32 (0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S8) || (defined D_NEGONE_CNT_S8)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S8) || (RTE_CONST_D_NEGONE_CNT_S8 != -1)
#   error "Constant value <D_NEGONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S8 (-1)
#  define D_NEGONE_CNT_S8 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S8) || (defined D_ONE_CNT_S8)
#  if (!defined RTE_CONST_D_ONE_CNT_S8) || (RTE_CONST_D_ONE_CNT_S8 != 1)
#   error "Constant value <D_ONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S8 (1)
#  define D_ONE_CNT_S8 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S8) || (defined D_ZERO_CNT_S8)
#  if (!defined RTE_CONST_D_ZERO_CNT_S8) || (RTE_CONST_D_ZERO_CNT_S8 != 0)
#   error "Constant value <D_ZERO_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S8 (0)
#  define D_ZERO_CNT_S8 (0)
# endif

# if (defined RTE_CONST_D_SIGQLFRNORES_CNT_ENUM) || (defined D_SIGQLFRNORES_CNT_ENUM)
#  if (!defined RTE_CONST_D_SIGQLFRNORES_CNT_ENUM) || (RTE_CONST_D_SIGQLFRNORES_CNT_ENUM != 0U)
#   error "Constant value <D_SIGQLFRNORES_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SIGQLFRNORES_CNT_ENUM (0U)
#  define D_SIGQLFRNORES_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_D_STEERMODINIT_CNT_ENUM) || (defined D_STEERMODINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_STEERMODINIT_CNT_ENUM) || (RTE_CONST_D_STEERMODINIT_CNT_ENUM != 0U)
#   error "Constant value <D_STEERMODINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_STEERMODINIT_CNT_ENUM (0U)
#  define D_STEERMODINIT_CNT_ENUM (0U)
# endif

# if (defined RTE_CONST_SYSPRFMNCSTNORMINIT) || (defined SYSPRFMNCSTNORMINIT)
#  if (!defined RTE_CONST_SYSPRFMNCSTNORMINIT) || (RTE_CONST_SYSPRFMNCSTNORMINIT != 0U)
#   error "Constant value <SYSPRFMNCSTNORMINIT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SYSPRFMNCSTNORMINIT (0U)
#  define SYSPRFMNCSTNORMINIT (0U)
# endif

# if (defined RTE_CONST_D_TUNSESSIONADRPTRINIT_CNT_ENUM) || (defined D_TUNSESSIONADRPTRINIT_CNT_ENUM)
#  if (!defined RTE_CONST_D_TUNSESSIONADRPTRINIT_CNT_ENUM) || (RTE_CONST_D_TUNSESSIONADRPTRINIT_CNT_ENUM != 255U)
#   error "Constant value <D_TUNSESSIONADRPTRINIT_CNT_ENUM> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TUNSESSIONADRPTRINIT_CNT_ENUM (255U)
#  define D_TUNSESSIONADRPTRINIT_CNT_ENUM (255U)
# endif

# if (defined RTE_CONST_D_CMPVEHLATAINIT_CNT_U16) || (defined D_CMPVEHLATAINIT_CNT_U16)
#  if (!defined RTE_CONST_D_CMPVEHLATAINIT_CNT_U16) || (RTE_CONST_D_CMPVEHLATAINIT_CNT_U16 != 1022U)
#   error "Constant value <D_CMPVEHLATAINIT_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_CMPVEHLATAINIT_CNT_U16 (1022U)
#  define D_CMPVEHLATAINIT_CNT_U16 (1022U)
# endif

# if (defined RTE_CONST_D_FIFTEEN_CNT_U16) || (defined D_FIFTEEN_CNT_U16)
#  if (!defined RTE_CONST_D_FIFTEEN_CNT_U16) || (RTE_CONST_D_FIFTEEN_CNT_U16 != 15U)
#   error "Constant value <D_FIFTEEN_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FIFTEEN_CNT_U16 (15U)
#  define D_FIFTEEN_CNT_U16 (15U)
# endif

# if (defined RTE_CONST_D_MAXCONF_ULS_U8P8) || (defined D_MAXCONF_ULS_U8P8)
#  if (!defined RTE_CONST_D_MAXCONF_ULS_U8P8) || (RTE_CONST_D_MAXCONF_ULS_U8P8 != 256U)
#   error "Constant value <D_MAXCONF_ULS_U8P8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MAXCONF_ULS_U8P8 (256U)
#  define D_MAXCONF_ULS_U8P8 (256U)
# endif

# if (defined RTE_CONST_D_MTRPOLESDIV2_CNT_U16) || (defined D_MTRPOLESDIV2_CNT_U16)
#  if (!defined RTE_CONST_D_MTRPOLESDIV2_CNT_U16) || (RTE_CONST_D_MTRPOLESDIV2_CNT_U16 != 3U)
#   error "Constant value <D_MTRPOLESDIV2_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRPOLESDIV2_CNT_U16 (3U)
#  define D_MTRPOLESDIV2_CNT_U16 (3U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U16) || (defined D_ONE_CNT_U16)
#  if (!defined RTE_CONST_D_ONE_CNT_U16) || (RTE_CONST_D_ONE_CNT_U16 != 1U)
#   error "Constant value <D_ONE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U16 (1U)
#  define D_ONE_CNT_U16 (1U)
# endif

# if (defined RTE_CONST_D_QUADRANT1_CNT_U16) || (defined D_QUADRANT1_CNT_U16)
#  if (!defined RTE_CONST_D_QUADRANT1_CNT_U16) || (RTE_CONST_D_QUADRANT1_CNT_U16 != 1U)
#   error "Constant value <D_QUADRANT1_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT1_CNT_U16 (1U)
#  define D_QUADRANT1_CNT_U16 (1U)
# endif

# if (defined RTE_CONST_D_QUADRANT2_CNT_U16) || (defined D_QUADRANT2_CNT_U16)
#  if (!defined RTE_CONST_D_QUADRANT2_CNT_U16) || (RTE_CONST_D_QUADRANT2_CNT_U16 != 2U)
#   error "Constant value <D_QUADRANT2_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT2_CNT_U16 (2U)
#  define D_QUADRANT2_CNT_U16 (2U)
# endif

# if (defined RTE_CONST_D_QUADRANT3_CNT_U16) || (defined D_QUADRANT3_CNT_U16)
#  if (!defined RTE_CONST_D_QUADRANT3_CNT_U16) || (RTE_CONST_D_QUADRANT3_CNT_U16 != 3U)
#   error "Constant value <D_QUADRANT3_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT3_CNT_U16 (3U)
#  define D_QUADRANT3_CNT_U16 (3U)
# endif

# if (defined RTE_CONST_D_QUADRANT4_CNT_U16) || (defined D_QUADRANT4_CNT_U16)
#  if (!defined RTE_CONST_D_QUADRANT4_CNT_U16) || (RTE_CONST_D_QUADRANT4_CNT_U16 != 4U)
#   error "Constant value <D_QUADRANT4_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT4_CNT_U16 (4U)
#  define D_QUADRANT4_CNT_U16 (4U)
# endif

# if (defined RTE_CONST_D_RACKCNTRUNLEARNED_CNT_U16) || (defined D_RACKCNTRUNLEARNED_CNT_U16)
#  if (!defined RTE_CONST_D_RACKCNTRUNLEARNED_CNT_U16) || (RTE_CONST_D_RACKCNTRUNLEARNED_CNT_U16 != 65535U)
#   error "Constant value <D_RACKCNTRUNLEARNED_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKCNTRUNLEARNED_CNT_U16 (65535U)
#  define D_RACKCNTRUNLEARNED_CNT_U16 (65535U)
# endif

# if (defined RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16) || (defined D_RACKTOVEHCNTRINVALID_CNT_U16)
#  if (!defined RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16) || (RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16 != 4095U)
#   error "Constant value <D_RACKTOVEHCNTRINVALID_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16 (4095U)
#  define D_RACKTOVEHCNTRINVALID_CNT_U16 (4095U)
# endif

# if (defined RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16) || (defined D_RACKTOVEHCNTRUNLEARNED_CNT_U16)
#  if (!defined RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16) || (RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16 != 4095U)
#   error "Constant value <D_RACKTOVEHCNTRUNLEARNED_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16 (4095U)
#  define D_RACKTOVEHCNTRUNLEARNED_CNT_U16 (4095U)
# endif

# if (defined RTE_CONST_D_SEVEN_CNT_U16) || (defined D_SEVEN_CNT_U16)
#  if (!defined RTE_CONST_D_SEVEN_CNT_U16) || (RTE_CONST_D_SEVEN_CNT_U16 != 7U)
#   error "Constant value <D_SEVEN_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SEVEN_CNT_U16 (7U)
#  define D_SEVEN_CNT_U16 (7U)
# endif

# if (defined RTE_CONST_D_THREE_CNT_U16) || (defined D_THREE_CNT_U16)
#  if (!defined RTE_CONST_D_THREE_CNT_U16) || (RTE_CONST_D_THREE_CNT_U16 != 3U)
#   error "Constant value <D_THREE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_THREE_CNT_U16 (3U)
#  define D_THREE_CNT_U16 (3U)
# endif

# if (defined RTE_CONST_D_TWOPTFIVE_VOLT_U3P13) || (defined D_TWOPTFIVE_VOLT_U3P13)
#  if (!defined RTE_CONST_D_TWOPTFIVE_VOLT_U3P13) || (RTE_CONST_D_TWOPTFIVE_VOLT_U3P13 != 20480U)
#   error "Constant value <D_TWOPTFIVE_VOLT_U3P13> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TWOPTFIVE_VOLT_U3P13 (20480U)
#  define D_TWOPTFIVE_VOLT_U3P13 (20480U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U16) || (defined D_ZERO_CNT_U16)
#  if (!defined RTE_CONST_D_ZERO_CNT_U16) || (RTE_CONST_D_ZERO_CNT_U16 != 0U)
#   error "Constant value <D_ZERO_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U16 (0U)
#  define D_ZERO_CNT_U16 (0U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U32) || (defined D_ONE_CNT_U32)
#  if (!defined RTE_CONST_D_ONE_CNT_U32) || (RTE_CONST_D_ONE_CNT_U32 != 1U)
#   error "Constant value <D_ONE_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U32 (1U)
#  define D_ONE_CNT_U32 (1U)
# endif

# if (defined RTE_CONST_D_SVCDFTACTPULLLRNMASK_CNT_B32) || (defined D_SVCDFTACTPULLLRNMASK_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTACTPULLLRNMASK_CNT_B32) || (RTE_CONST_D_SVCDFTACTPULLLRNMASK_CNT_B32 != 524288U)
#   error "Constant value <D_SVCDFTACTPULLLRNMASK_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTACTPULLLRNMASK_CNT_B32 (524288U)
#  define D_SVCDFTACTPULLLRNMASK_CNT_B32 (524288U)
# endif

# if (defined RTE_CONST_D_SVCDFTAVGFRCLRNMASK_CNT_B32) || (defined D_SVCDFTAVGFRCLRNMASK_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTAVGFRCLRNMASK_CNT_B32) || (RTE_CONST_D_SVCDFTAVGFRCLRNMASK_CNT_B32 != 1048576U)
#   error "Constant value <D_SVCDFTAVGFRCLRNMASK_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTAVGFRCLRNMASK_CNT_B32 (1048576U)
#  define D_SVCDFTAVGFRCLRNMASK_CNT_B32 (1048576U)
# endif

# if (defined RTE_CONST_D_SVCDFTDAMPING_CNT_B32) || (defined D_SVCDFTDAMPING_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTDAMPING_CNT_B32) || (RTE_CONST_D_SVCDFTDAMPING_CNT_B32 != 131072U)
#   error "Constant value <D_SVCDFTDAMPING_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTDAMPING_CNT_B32 (131072U)
#  define D_SVCDFTDAMPING_CNT_B32 (131072U)
# endif

# if (defined RTE_CONST_D_SVCDFTDRIVINGDYN_CNT_B32) || (defined D_SVCDFTDRIVINGDYN_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTDRIVINGDYN_CNT_B32) || (RTE_CONST_D_SVCDFTDRIVINGDYN_CNT_B32 != 8192U)
#   error "Constant value <D_SVCDFTDRIVINGDYN_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTDRIVINGDYN_CNT_B32 (8192U)
#  define D_SVCDFTDRIVINGDYN_CNT_B32 (8192U)
# endif

# if (defined RTE_CONST_D_SVCDFTENGON_CNT_B32) || (defined D_SVCDFTENGON_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTENGON_CNT_B32) || (RTE_CONST_D_SVCDFTENGON_CNT_B32 != 1U)
#   error "Constant value <D_SVCDFTENGON_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTENGON_CNT_B32 (1U)
#  define D_SVCDFTENGON_CNT_B32 (1U)
# endif

# if (defined RTE_CONST_D_SVCDFTEOTIMPACT_CNT_B32) || (defined D_SVCDFTEOTIMPACT_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTEOTIMPACT_CNT_B32) || (RTE_CONST_D_SVCDFTEOTIMPACT_CNT_B32 != 16U)
#   error "Constant value <D_SVCDFTEOTIMPACT_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTEOTIMPACT_CNT_B32 (16U)
#  define D_SVCDFTEOTIMPACT_CNT_B32 (16U)
# endif

# if (defined RTE_CONST_D_SVCDFTEOTTHERMAL_CNT_B32) || (defined D_SVCDFTEOTTHERMAL_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTEOTTHERMAL_CNT_B32) || (RTE_CONST_D_SVCDFTEOTTHERMAL_CNT_B32 != 32U)
#   error "Constant value <D_SVCDFTEOTTHERMAL_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTEOTTHERMAL_CNT_B32 (32U)
#  define D_SVCDFTEOTTHERMAL_CNT_B32 (32U)
# endif

# if (defined RTE_CONST_D_SVCDFTFIREWALLMASK_CNT_B32) || (defined D_SVCDFTFIREWALLMASK_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTFIREWALLMASK_CNT_B32) || (RTE_CONST_D_SVCDFTFIREWALLMASK_CNT_B32 != 2097152U)
#   error "Constant value <D_SVCDFTFIREWALLMASK_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTFIREWALLMASK_CNT_B32 (2097152U)
#  define D_SVCDFTFIREWALLMASK_CNT_B32 (2097152U)
# endif

# if (defined RTE_CONST_D_SVCDFTFREQDEPDMP_CNT_B32) || (defined D_SVCDFTFREQDEPDMP_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTFREQDEPDMP_CNT_B32) || (RTE_CONST_D_SVCDFTFREQDEPDMP_CNT_B32 != 2U)
#   error "Constant value <D_SVCDFTFREQDEPDMP_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTFREQDEPDMP_CNT_B32 (2U)
#  define D_SVCDFTFREQDEPDMP_CNT_B32 (2U)
# endif

# if (defined RTE_CONST_D_SVCDFTHYSTADD_CNT_B32) || (defined D_SVCDFTHYSTADD_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTHYSTADD_CNT_B32) || (RTE_CONST_D_SVCDFTHYSTADD_CNT_B32 != 32768U)
#   error "Constant value <D_SVCDFTHYSTADD_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTHYSTADD_CNT_B32 (32768U)
#  define D_SVCDFTHYSTADD_CNT_B32 (32768U)
# endif

# if (defined RTE_CONST_D_SVCDFTHYSTCOMP_CNT_B32) || (defined D_SVCDFTHYSTCOMP_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTHYSTCOMP_CNT_B32) || (RTE_CONST_D_SVCDFTHYSTCOMP_CNT_B32 != 16384U)
#   error "Constant value <D_SVCDFTHYSTCOMP_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTHYSTCOMP_CNT_B32 (16384U)
#  define D_SVCDFTHYSTCOMP_CNT_B32 (16384U)
# endif

# if (defined RTE_CONST_D_SVCDFTKININTDIAG_CNT_B32) || (defined D_SVCDFTKININTDIAG_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTKININTDIAG_CNT_B32) || (RTE_CONST_D_SVCDFTKININTDIAG_CNT_B32 != 4U)
#   error "Constant value <D_SVCDFTKININTDIAG_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTKININTDIAG_CNT_B32 (4U)
#  define D_SVCDFTKININTDIAG_CNT_B32 (4U)
# endif

# if (defined RTE_CONST_D_SVCDFTMODIDX_CNT_B32) || (defined D_SVCDFTMODIDX_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTMODIDX_CNT_B32) || (RTE_CONST_D_SVCDFTMODIDX_CNT_B32 != 512U)
#   error "Constant value <D_SVCDFTMODIDX_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTMODIDX_CNT_B32 (512U)
#  define D_SVCDFTMODIDX_CNT_B32 (512U)
# endif

# if (defined RTE_CONST_D_SVCDFTMTRPARMNRMLRN_CNT_B32) || (defined D_SVCDFTMTRPARMNRMLRN_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTMTRPARMNRMLRN_CNT_B32) || (RTE_CONST_D_SVCDFTMTRPARMNRMLRN_CNT_B32 != 128U)
#   error "Constant value <D_SVCDFTMTRPARMNRMLRN_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTMTRPARMNRMLRN_CNT_B32 (128U)
#  define D_SVCDFTMTRPARMNRMLRN_CNT_B32 (128U)
# endif

# if (defined RTE_CONST_D_SVCDFTMTRVELNRMLRN_CNT_B32) || (defined D_SVCDFTMTRVELNRMLRN_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTMTRVELNRMLRN_CNT_B32) || (RTE_CONST_D_SVCDFTMTRVELNRMLRN_CNT_B32 != 64U)
#   error "Constant value <D_SVCDFTMTRVELNRMLRN_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTMTRVELNRMLRN_CNT_B32 (64U)
#  define D_SVCDFTMTRVELNRMLRN_CNT_B32 (64U)
# endif

# if (defined RTE_CONST_D_SVCDFTMULTIGNMASK_CNT_B32) || (defined D_SVCDFTMULTIGNMASK_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTMULTIGNMASK_CNT_B32) || (RTE_CONST_D_SVCDFTMULTIGNMASK_CNT_B32 != 1342177280U)
#   error "Constant value <D_SVCDFTMULTIGNMASK_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTMULTIGNMASK_CNT_B32 (1342177280U)
#  define D_SVCDFTMULTIGNMASK_CNT_B32 (1342177280U)
# endif

# if (defined RTE_CONST_D_SVCDFTPARKAST_CNT_B32) || (defined D_SVCDFTPARKAST_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTPARKAST_CNT_B32) || (RTE_CONST_D_SVCDFTPARKAST_CNT_B32 != 4096U)
#   error "Constant value <D_SVCDFTPARKAST_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTPARKAST_CNT_B32 (4096U)
#  define D_SVCDFTPARKAST_CNT_B32 (4096U)
# endif

# if (defined RTE_CONST_D_SVCDFTPULLCOMP_CNT_B32) || (defined D_SVCDFTPULLCOMP_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTPULLCOMP_CNT_B32) || (RTE_CONST_D_SVCDFTPULLCOMP_CNT_B32 != 1024U)
#   error "Constant value <D_SVCDFTPULLCOMP_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTPULLCOMP_CNT_B32 (1024U)
#  define D_SVCDFTPULLCOMP_CNT_B32 (1024U)
# endif

# if (defined RTE_CONST_D_SVCDFTRETURN_CNT_B32) || (defined D_SVCDFTRETURN_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTRETURN_CNT_B32) || (RTE_CONST_D_SVCDFTRETURN_CNT_B32 != 65536U)
#   error "Constant value <D_SVCDFTRETURN_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTRETURN_CNT_B32 (65536U)
#  define D_SVCDFTRETURN_CNT_B32 (65536U)
# endif

# if (defined RTE_CONST_D_SVCDFTRXMSGS_CNT_B32) || (defined D_SVCDFTRXMSGS_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTRXMSGS_CNT_B32) || (RTE_CONST_D_SVCDFTRXMSGS_CNT_B32 != 134217728U)
#   error "Constant value <D_SVCDFTRXMSGS_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTRXMSGS_CNT_B32 (134217728U)
#  define D_SVCDFTRXMSGS_CNT_B32 (134217728U)
# endif

# if (defined RTE_CONST_D_SVCDFTTHERMALDC_CNT_B32) || (defined D_SVCDFTTHERMALDC_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTTHERMALDC_CNT_B32) || (RTE_CONST_D_SVCDFTTHERMALDC_CNT_B32 != 8U)
#   error "Constant value <D_SVCDFTTHERMALDC_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTTHERMALDC_CNT_B32 (8U)
#  define D_SVCDFTTHERMALDC_CNT_B32 (8U)
# endif

# if (defined RTE_CONST_D_SVCDFTTRQRMP_CNT_B32) || (defined D_SVCDFTTRQRMP_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTTRQRMP_CNT_B32) || (RTE_CONST_D_SVCDFTTRQRMP_CNT_B32 != 256U)
#   error "Constant value <D_SVCDFTTRQRMP_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTTRQRMP_CNT_B32 (256U)
#  define D_SVCDFTTRQRMP_CNT_B32 (256U)
# endif

# if (defined RTE_CONST_D_SVCDFTWHLIMBREJ_CNT_B32) || (defined D_SVCDFTWHLIMBREJ_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTWHLIMBREJ_CNT_B32) || (RTE_CONST_D_SVCDFTWHLIMBREJ_CNT_B32 != 2048U)
#   error "Constant value <D_SVCDFTWHLIMBREJ_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTWHLIMBREJ_CNT_B32 (2048U)
#  define D_SVCDFTWHLIMBREJ_CNT_B32 (2048U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0U)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0U)
#  define D_ZERO_CNT_U32 (0U)
# endif

# if (defined RTE_CONST_D_BATTVLTGCORRLNSTSINIT_CNT_U08) || (defined D_BATTVLTGCORRLNSTSINIT_CNT_U08)
#  if (!defined RTE_CONST_D_BATTVLTGCORRLNSTSINIT_CNT_U08) || (RTE_CONST_D_BATTVLTGCORRLNSTSINIT_CNT_U08 != 7U)
#   error "Constant value <D_BATTVLTGCORRLNSTSINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_BATTVLTGCORRLNSTSINIT_CNT_U08 (7U)
#  define D_BATTVLTGCORRLNSTSINIT_CNT_U08 (7U)
# endif

# if (defined RTE_CONST_D_DRVGDYNIFSTINIT_CNT_U08) || (defined D_DRVGDYNIFSTINIT_CNT_U08)
#  if (!defined RTE_CONST_D_DRVGDYNIFSTINIT_CNT_U08) || (RTE_CONST_D_DRVGDYNIFSTINIT_CNT_U08 != 128U)
#   error "Constant value <D_DRVGDYNIFSTINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_DRVGDYNIFSTINIT_CNT_U08 (128U)
#  define D_DRVGDYNIFSTINIT_CNT_U08 (128U)
# endif

# if (defined RTE_CONST_D_FOUR_CNT_U08) || (defined D_FOUR_CNT_U08)
#  if (!defined RTE_CONST_D_FOUR_CNT_U08) || (RTE_CONST_D_FOUR_CNT_U08 != 4U)
#   error "Constant value <D_FOUR_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FOUR_CNT_U08 (4U)
#  define D_FOUR_CNT_U08 (4U)
# endif

# if (defined RTE_CONST_D_MTRPOLESDIV2_CNT_U8) || (defined D_MTRPOLESDIV2_CNT_U8)
#  if (!defined RTE_CONST_D_MTRPOLESDIV2_CNT_U8) || (RTE_CONST_D_MTRPOLESDIV2_CNT_U8 != 3U)
#   error "Constant value <D_MTRPOLESDIV2_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRPOLESDIV2_CNT_U8 (3U)
#  define D_MTRPOLESDIV2_CNT_U8 (3U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U8) || (defined D_ONE_CNT_U8)
#  if (!defined RTE_CONST_D_ONE_CNT_U8) || (RTE_CONST_D_ONE_CNT_U8 != 1U)
#   error "Constant value <D_ONE_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U8 (1U)
#  define D_ONE_CNT_U8 (1U)
# endif

# if (defined RTE_CONST_D_QUADRANT1_CNT_U8) || (defined D_QUADRANT1_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT1_CNT_U8) || (RTE_CONST_D_QUADRANT1_CNT_U8 != 1U)
#   error "Constant value <D_QUADRANT1_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT1_CNT_U8 (1U)
#  define D_QUADRANT1_CNT_U8 (1U)
# endif

# if (defined RTE_CONST_D_QUADRANT2_CNT_U8) || (defined D_QUADRANT2_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT2_CNT_U8) || (RTE_CONST_D_QUADRANT2_CNT_U8 != 2U)
#   error "Constant value <D_QUADRANT2_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT2_CNT_U8 (2U)
#  define D_QUADRANT2_CNT_U8 (2U)
# endif

# if (defined RTE_CONST_D_QUADRANT3_CNT_U8) || (defined D_QUADRANT3_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT3_CNT_U8) || (RTE_CONST_D_QUADRANT3_CNT_U8 != 3U)
#   error "Constant value <D_QUADRANT3_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT3_CNT_U8 (3U)
#  define D_QUADRANT3_CNT_U8 (3U)
# endif

# if (defined RTE_CONST_D_QUADRANT4_CNT_U8) || (defined D_QUADRANT4_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT4_CNT_U8) || (RTE_CONST_D_QUADRANT4_CNT_U8 != 4U)
#   error "Constant value <D_QUADRANT4_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT4_CNT_U8 (4U)
#  define D_QUADRANT4_CNT_U8 (4U)
# endif

# if (defined RTE_CONST_D_SEVEN_CNT_U08) || (defined D_SEVEN_CNT_U08)
#  if (!defined RTE_CONST_D_SEVEN_CNT_U08) || (RTE_CONST_D_SEVEN_CNT_U08 != 7U)
#   error "Constant value <D_SEVEN_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SEVEN_CNT_U08 (7U)
#  define D_SEVEN_CNT_U08 (7U)
# endif

# if (defined RTE_CONST_D_THREE_CNT_U08) || (defined D_THREE_CNT_U08)
#  if (!defined RTE_CONST_D_THREE_CNT_U08) || (RTE_CONST_D_THREE_CNT_U08 != 3U)
#   error "Constant value <D_THREE_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_THREE_CNT_U08 (3U)
#  define D_THREE_CNT_U08 (3U)
# endif

# if (defined RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08) || (defined D_TURNSCNTRPARTNUMINIT_CNT_U08)
#  if (!defined RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08) || (RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08 != 255U)
#   error "Constant value <D_TURNSCNTRPARTNUMINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08 (255U)
#  define D_TURNSCNTRPARTNUMINIT_CNT_U08 (255U)
# endif

# if (defined RTE_CONST_D_TWO_CNT_U08) || (defined D_TWO_CNT_U08)
#  if (!defined RTE_CONST_D_TWO_CNT_U08) || (RTE_CONST_D_TWO_CNT_U08 != 2U)
#   error "Constant value <D_TWO_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TWO_CNT_U08 (2U)
#  define D_TWO_CNT_U08 (2U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U8) || (defined D_ZERO_CNT_U8)
#  if (!defined RTE_CONST_D_ZERO_CNT_U8) || (RTE_CONST_D_ZERO_CNT_U8 != 0U)
#   error "Constant value <D_ZERO_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U8 (0U)
#  define D_ZERO_CNT_U8 (0U)
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

# if defined C_ST_DIAG_OBD_DATA_INIT_VAL
#  error "Constant value <C_ST_DIAG_OBD_DATA_INIT_VAL> conflicts with an already defined symbol."
# else
#  define C_ST_DIAG_OBD_DATA_INIT_VAL (Rte_C_ST_DIAG_OBD_DATA_INIT_VAL)
# endif
extern CONST(Edch_EventStatusIpduDataType, RTE_CONST) Rte_C_ST_DIAG_OBD_DATA_INIT_VAL;

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

# if defined C_RT_VIN_NO_VECH
#  error "Constant value <C_RT_VIN_NO_VECH> conflicts with an already defined symbol."
# else
#  define C_RT_VIN_NO_VECH (Rte_C_RT_VIN_NO_VECH)
# endif
extern CONST(RT_VIN_NO_VECH, RTE_CONST) Rte_C_RT_VIN_NO_VECH;

# if defined SG_ACLNY_MASSCNTR_INIT
#  error "Constant value <SG_ACLNY_MASSCNTR_INIT> conflicts with an already defined symbol."
# else
#  define SG_ACLNY_MASSCNTR_INIT (Rte_SG_ACLNY_MASSCNTR_INIT)
# endif
extern CONST(SG_ACLNY_MASSCNTR, RTE_CONST) Rte_SG_ACLNY_MASSCNTR_INIT;

# if defined C_RT_SG_ANFRAGE_DSC_Modul
#  error "Constant value <C_RT_SG_ANFRAGE_DSC_Modul> conflicts with an already defined symbol."
# else
#  define C_RT_SG_ANFRAGE_DSC_Modul (Rte_C_RT_SG_ANFRAGE_DSC_Modul)
# endif
extern CONST(SG_ANFRAGE_DSC_Modul, RTE_CONST) Rte_C_RT_SG_ANFRAGE_DSC_Modul;

# if defined C_RT_SG_ANFRAGE_EPS
#  error "Constant value <C_RT_SG_ANFRAGE_EPS> conflicts with an already defined symbol."
# else
#  define C_RT_SG_ANFRAGE_EPS (Rte_C_RT_SG_ANFRAGE_EPS)
# endif
extern CONST(SG_ANFRAGE_EPS, RTE_CONST) Rte_C_RT_SG_ANFRAGE_EPS;

# if defined C_RT_SG_ANFRAGE_SAS
#  error "Constant value <C_RT_SG_ANFRAGE_SAS> conflicts with an already defined symbol."
# else
#  define C_RT_SG_ANFRAGE_SAS (Rte_C_RT_SG_ANFRAGE_SAS)
# endif
extern CONST(SG_ANFRAGE_SAS, RTE_CONST) Rte_C_RT_SG_ANFRAGE_SAS;

# if defined C_RT_SG_ANFRAGE_ZGW
#  error "Constant value <C_RT_SG_ANFRAGE_ZGW> conflicts with an already defined symbol."
# else
#  define C_RT_SG_ANFRAGE_ZGW (Rte_C_RT_SG_ANFRAGE_ZGW)
# endif
extern CONST(SG_ANFRAGE_ZGW, RTE_CONST) Rte_C_RT_SG_ANFRAGE_ZGW;

# if defined SG_CON_VEH_INIT
#  error "Constant value <SG_CON_VEH_INIT> conflicts with an already defined symbol."
# else
#  define SG_CON_VEH_INIT (Rte_SG_CON_VEH_INIT)
# endif
extern CONST(SG_CON_VEH, RTE_CONST) Rte_SG_CON_VEH_INIT;

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

# if defined T_HWPOSNCOMPINIT_HWDEG_STR
#  error "Constant value <T_HWPOSNCOMPINIT_HWDEG_STR> conflicts with an already defined symbol."
# else
#  define T_HWPOSNCOMPINIT_HWDEG_STR (Rte_T_HWPOSNCOMPINIT_HWDEG_STR)
# endif
extern CONST(SysOutpCpbySig_Str, RTE_CONST) Rte_T_HWPOSNCOMPINIT_HWDEG_STR;

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
  UInt16 value;
} Rte_DE_UInt16;

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  SInt16 value;
} Rte_DE_SInt16;

typedef struct
{
  ST_OFFS_QUAD_EPS value;
} Rte_DE_ST_OFFS_QUAD_EPS;

typedef struct
{
  SInt8 value;
} Rte_DE_SInt8;

typedef struct
{
  TurnsCntrValStateType value;
} Rte_DE_TurnsCntrValStateType;

typedef struct
{
  UInt8 value;
} Rte_DE_UInt8;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  UInt32 value;
} Rte_DE_UInt32;

typedef struct
{
  TuningSessionAddrPtrEnum value;
} Rte_DE_TuningSessionAddrPtrEnum;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  QU_SER_STMOM_STMOM_DV_ACT value;
} Rte_DE_QU_SER_STMOM_STMOM_DV_ACT;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  TJAStateType value;
} Rte_DE_TJAStateType;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  ManufModeType value;
} Rte_DE_ManufModeType;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  FETPHASETYPE_ENUM value;
} Rte_DE_FETPHASETYPE_ENUM;

typedef struct
{
  FETFAULTTYPE_ENUM value;
} Rte_DE_FETFAULTTYPE_ENUM;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  MSA_Cmd_Type value;
} Rte_DE_MSA_Cmd_Type;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  QU_SER_WSTA_EST_FTAX value;
} Rte_DE_QU_SER_WSTA_EST_FTAX;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  HwTrqStatusType value;
} Rte_DE_HwTrqStatusType;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  LktoLkStrStateType value;
} Rte_DE_LktoLkStrStateType;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  OscTrajCmdStateType value;
} Rte_DE_OscTrajCmdStateType;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  ST_V_VEH_NSS value;
} Rte_DE_ST_V_VEH_NSS;

typedef struct
{
  DVCO_VEH value;
} Rte_DE_DVCO_VEH;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  SInt32 value;
} Rte_DE_SInt32;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  UInt4 value;
} Rte_DE_UInt4;

typedef struct
{
  CTR_ERRM_BN_U value;
} Rte_DE_CTR_ERRM_BN_U;

typedef struct
{
  New_Coding_79 value;
} Rte_DE_New_Coding_79;

typedef struct
{
  RT_VIN_NO_VECH value;
  Std_ReturnType status;
} Rte_DES_RT_VIN_NO_VECH;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  EnergyModeStateType value;
} Rte_DE_EnergyModeStateType;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  SG_ST_CENG value;
} Rte_DE_SG_ST_CENG;

typedef struct
{
  New_Coding_64 value;
} Rte_DE_New_Coding_64;


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

extern VAR(EOLTrqStepType, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_EOLTrqStepData;
extern VAR(HwTrqScale_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_HwTrqScaleData;
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_HwTrq_HwTrqTrimData;
extern VAR(ShCurrCal_DataType, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_MtrCurr_ShCurrCal;
extern VAR(EOLTurnsCntrCals_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_TurnsCounter_EOLTurnsCntrCals;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

#  define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

extern VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_ActivePull_PullCmpLTComp_HwNm_f32;
extern VAR(AvgFricLrnType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_AvgFricLrn_AvgFricLrnData;
extern VAR(RackCenterType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_LnRkCr_LearnedRackCntr;
extern VAR(ThrmlDutyCycle_FltStVal_Datatype, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_ThrmlDutyCycle_ThrmlDutyCycle_FltStVal;
extern VAR(TuningSelectParam, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_VehCfg_PrevVldTuningSel;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

#  define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

extern VAR(Float, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_TrqCmdScl_TorqueCmdSF_Uls_f32;
extern VAR(UInt16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Polarity_k_SystemPolarity_Cnt_b16;
extern VAR(AbsHwPosTrim_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_AbsHwPos_Trim;
extern VAR(EOTLearned_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_LrnEOT_LearnedEOT;
extern VAR(MtrPosCal_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_MtrPos_MtrPosSnsr_EOLData;
extern VAR(EOLNomMtrParamType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_ParamComp_EOLNomMtrParam;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"


# endif


/**********************************************************************************************************************
 * Buffer definitions for implicit access to S/R port elements
 *********************************************************************************************************************/

# define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"

typedef struct
{
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
} Rte_tsRB_Ap_ParamComp_ParamComp_Per2;

typedef struct
{
  Rte_DE_Float Rte_FiltEstPkCurr_AmpSq_f32;
} Rte_tsRB_Ap_CurrentEst_CurrentEst_Per2;

typedef union
{
  Rte_tsRB_Ap_ParamComp_ParamComp_Per2 Rte_Ap_ParamComp_ParamComp_Per2;
  Rte_tsRB_Ap_CurrentEst_CurrentEst_Per2 Rte_Ap_CurrentEst_CurrentEst_Per2;
} Rte_tuRB_Task_100ms_10;

typedef struct
{
  Rte_tuRB_Task_100ms_10 Rte_RB;
} Rte_tsTask_100ms_10;

typedef struct
{
  Rte_DE_ManufModeType Rte_MECCounter_Cnt_enum;
} Rte_tsRB_Sa_HwTrq_HwTrq_Per3;

typedef struct
{
  Rte_DE_Float Rte_AmbTemp_DegC_f32;
} Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per2;

typedef struct
{
  Rte_DE_Float Rte_AmbTemp_DegC_f32;
  Rte_DE_Float Rte_CtrlTempFinal_DegC_f32;
  Rte_DE_Float Rte_EngTemp_DegC_f32;
  Rte_DE_Float Rte_EstPkCurr_AmpSq_f32;
  Rte_DE_Float Rte_HwVel_HwRadpS_f32;
  Rte_DE_Boolean Rte_ScomAMDefeat_Cnt_lgc;
  Rte_DE_Boolean Rte_ScomTempDataRcvd_Cnt_lgc;
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
} Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Per1;

typedef union
{
  Rte_tsRB_Sa_HwTrq_HwTrq_Per3 Rte_Sa_HwTrq_HwTrq_Per3;
  Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per2 Rte_Sa_CtrlTemp_CtrlTemp_Per2;
  Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Per1 Rte_Ap_MtrTempEst_MtrTempEst_Per1;
} Rte_tuRB_Task_100ms_7;

typedef struct
{
  Rte_tuRB_Task_100ms_7 Rte_RB;
} Rte_tsTask_100ms_7;

typedef struct
{
  Rte_DE_Float Rte_AnaDiffHwTrq_Volt_f32;
} Rte_tsRB_Sa_HwTrq2_HwTrq2_Per3;

typedef union
{
  Rte_tsRB_Sa_HwTrq2_HwTrq2_Per3 Rte_Sa_HwTrq2_HwTrq2_Per3;
} Rte_tuRB_Task_100ms_8;

typedef struct
{
  Rte_tuRB_Task_100ms_8 Rte_RB;
} Rte_tsTask_100ms_8;

typedef struct
{
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Boolean Rte_DefeatDutySvc_Cnt_lgc;
  Rte_DE_Float Rte_FiltMeasTemp_DegC_f32;
  Rte_DE_Float Rte_FilteredPkCurr_AmpSq_f32;
  Rte_DE_UInt32 Rte_IgnTimeOff_Cnt_u32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_MotorVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_MtrPkCurr_AmpSq_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
  Rte_DE_Boolean Rte_VehTimeValid_Cnt_lgc;
  Rte_DE_Float Rte_DutyCycleLevel_Uls_f32;
  Rte_DE_Float Rte_ThermLimitPerc_Uls_f32;
  Rte_DE_Float Rte_ThermalLimit_MtrNm_f32;
} Rte_tsRB_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1;

typedef struct
{
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Boolean Rte_PullCmpEna_Cnt_lgc;
  Rte_DE_Float Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_PullCmpLongTermIntgtrSt_HwNm_f32;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per3;

typedef union
{
  Rte_tsRB_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1 Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1;
  Rte_tsRB_Ap_ActivePull_ActivePull_Per3 Rte_Ap_ActivePull_ActivePull_Per3;
} Rte_tuRB_Task_100ms_9;

typedef struct
{
  Rte_tuRB_Task_100ms_9 Rte_RB;
} Rte_tsTask_100ms_9;

typedef struct
{
  Rte_DE_Boolean Rte_AVLFORCGRDTxConf_Cnt_lgc;
  Rte_DE_Boolean Rte_AVLSTMOMTxConf_Cnt_lgc;
  Rte_DE_Boolean Rte_CADASMSG_Cnt_lgc;
  Rte_DE_UInt8 Rte_CDISPCCEPS_Cnt_u08;
  Rte_DE_Boolean Rte_CEVIIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CFACTORIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CHWANGLEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CHWTORQUEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CMTTORQUEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsRecRmpToZeroFltPres_Cnt_lgc;
  Rte_DE_Float Rte_LimitPercentFiltered_Uls_f32;
  Rte_DE_UInt16 Rte_RacktoVehCntrOffset_Cnt_u16;
  Rte_DE_UInt8 Rte_RevOffsetState_Cnt_u08;
} Rte_tsRB_Ap_SrlComOutput2_SrlComOutput2_Per1;

typedef union
{
  Rte_tsRB_Ap_SrlComOutput2_SrlComOutput2_Per1 Rte_Ap_SrlComOutput2_SrlComOutput2_Per1;
} Rte_tuRB_Task_10msA_10;

typedef struct
{
  Rte_tuRB_Task_10msA_10 Rte_RB;
} Rte_tsTask_10msA_10;

typedef struct
{
  Rte_DE_Boolean Rte_AVLFORCGRDTxConf_Cnt_lgc;
  Rte_DE_Boolean Rte_AVLSTMOMTxConf_Cnt_lgc;
} Rte_tsRB_Ap_SrlComOutput_SrlComOutput_Per1;

typedef union
{
  Rte_tsRB_Ap_SrlComOutput_SrlComOutput_Per1 Rte_Ap_SrlComOutput_SrlComOutput_Per1;
} Rte_tuRB_Task_10msA_9;

typedef struct
{
  Rte_tuRB_Task_10msA_9 Rte_RB;
} Rte_tsTask_10msA_9;

typedef struct
{
  Rte_DE_Boolean Rte_DefeatKinIntTest_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsDefVehSpd_Cnt_lgc;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
} Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per2;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsHwPosDis_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_PostLimitTorque_MtrNm_f32;
  Rte_DE_Boolean Rte_CCWFound_Cnt_lgc;
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_CWFound_Cnt_lgc;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
} Rte_tsRB_Ap_LrnEOT_LrnEOT_Per1;

typedef struct
{
  Rte_DE_Float Rte_PDChrgPmpFdbkADC_Volt_f32;
  Rte_DE_Float Rte_PDSuplFdbkADC_Volt_f32;
  Rte_DE_Boolean Rte_PDActivateTest_Cnt_lgc;
  Rte_DE_SInt16 Rte_PDPhaseAdvSelect_Cnt_s16;
  Rte_DE_Float Rte_PDTestModIndex_Uls_f32;
  Rte_DE_Boolean Rte_PhsDiscTestComplete_Cnt_lgc;
} Rte_tsRB_Sa_PhaseDscnt_PhaseDscnt_Per2;

typedef struct
{
  Rte_DE_Float Rte_PowerLimitPerc_Uls_f32;
  Rte_DE_Float Rte_ThermLimitPerc_Uls_f32;
  Rte_DE_Float Rte_LimitPercentFiltered_Uls_f32;
} Rte_tsRB_Ap_AssistSumnLmt_AssistSumnLmt_Per2;

typedef union
{
  Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per2 Rte_Ap_AbsHwPos_AbsHwPos_Per2;
  Rte_tsRB_Ap_LrnEOT_LrnEOT_Per1 Rte_Ap_LrnEOT_LrnEOT_Per1;
  Rte_tsRB_Sa_PhaseDscnt_PhaseDscnt_Per2 Rte_Sa_PhaseDscnt_PhaseDscnt_Per2;
  Rte_tsRB_Ap_AssistSumnLmt_AssistSumnLmt_Per2 Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2;
} Rte_tuRB_Task_10msB_10;

typedef struct
{
  Rte_tuRB_Task_10msB_10 Rte_RB;
} Rte_tsTask_10msB_10;

typedef struct
{
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_ModIdx_Uls_f32;
  Rte_DE_Float Rte_TermA_Volt_f32;
  Rte_DE_Float Rte_TermXq_Uls_f32;
  Rte_DE_Float Rte_TermZ_Uls_f32;
  Rte_DE_SInt16 Rte_UncorrPhsAdv_Cnt_s16;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_ElecPower_Watts_f32;
  Rte_DE_Float Rte_SupplyCur_Amp_f32;
} Rte_tsRB_Ap_ElecPwr_ElecPwr_Per1;

typedef struct
{
  Rte_DE_Float Rte_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_HwPos_HwDeg_f32;
  Rte_DE_Float Rte_HwPosAuth_Uls_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_RackLoad_kN_f32;
} Rte_tsRB_Ap_RackLoad_RackLoad_Per1;

typedef struct
{
  Rte_DE_ManufModeType Rte_NxtrMEC_Cnt_enum;
  Rte_DE_QU_SER_WSTA_EST_FTAX Rte_PrkAssistState_Cnt_u08;
  Rte_DE_New_Coding_79 Rte_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP;
  Rte_DE_Boolean Rte_VINValid_Cnt_lgc;
  Rte_DE_EnergyModeStateType Rte_EnergyModeState_Cnt_enum;
} Rte_tsRB_Ap_VehCfg_VehCfg_Per1;

typedef struct
{
  Rte_DE_UInt16 Rte_ActiveTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_ActiveTunSet_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunSet_Cnt_u16;
  Rte_DE_UInt32 Rte_ActiveTunOvrPtrAddr_Cnt_u32;
  Rte_DE_TuningSessionAddrPtrEnum Rte_TuningSessionActPtr_Cnt_u8;
} Rte_tsRB_Ap_ApXcp_ApXcp_Per1;

typedef struct
{
  Rte_DE_Float Rte_CRFMtrTrq_MtrNm_f32;
  Rte_DE_Boolean Rte_DefeatFricLearning_Cnt_lgc;
  Rte_DE_Boolean Rte_FricLrnCustEna_Cnt_lgc;
  Rte_DE_Float Rte_HwAng_HwDeg_f32;
  Rte_DE_Float Rte_HwPosAuthority_Uls_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_HwVel_HwRadpS_f32;
  Rte_DE_Float Rte_LatAcc_MpSecSq_f32;
  Rte_DE_Float Rte_Temperature_DegC_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Float Rte_EstFric_HwNm_f32;
  Rte_DE_Float Rte_FricOffset_HwNm_f32;
  Rte_DE_Float Rte_SatEstFric_HwNm_f32;
} Rte_tsRB_Ap_AvgFricLrn_AvgFricLrn_Per1;

typedef union
{
  Rte_tsRB_Ap_ElecPwr_ElecPwr_Per1 Rte_Ap_ElecPwr_ElecPwr_Per1;
  Rte_tsRB_Ap_RackLoad_RackLoad_Per1 Rte_Ap_RackLoad_RackLoad_Per1;
  Rte_tsRB_Ap_VehCfg_VehCfg_Per1 Rte_Ap_VehCfg_VehCfg_Per1;
  Rte_tsRB_Ap_ApXcp_ApXcp_Per1 Rte_Ap_ApXcp_ApXcp_Per1;
  Rte_tsRB_Ap_AvgFricLrn_AvgFricLrn_Per1 Rte_Ap_AvgFricLrn_AvgFricLrn_Per1;
} Rte_tuRB_Task_10msB_9;

typedef struct
{
  Rte_DE_UInt16 Rte_I_VehCfg_DesiredTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_I_VehCfg_DesiredTunSet_Cnt_u16;
} Rte_tsTB_Task_10msB_9;

typedef struct
{
  Rte_tsTB_Task_10msB_9 Rte_TB;
  Rte_tuRB_Task_10msB_9 Rte_RB;
} Rte_tsTask_10msB_9;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Boolean Rte_CCLMSAActive_Cnt_lgc;
} Rte_tsRB_Ap_BVDiag_BVDiag_Per1;

typedef struct
{
  Rte_DE_UInt32 Rte_ActiveTunOvrPtrAddr_Cnt_u32;
  Rte_DE_UInt16 Rte_DesiredTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunSet_Cnt_u16;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_TuningSessionAddrPtrEnum Rte_TuningSessionActPtr_Cnt_u8;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_UInt16 Rte_ActiveTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_ActiveTunSet_Cnt_u16;
} Rte_tsRB_Ap_TuningSelAuth_TuningSelAuth_Per1;

typedef struct
{
  Rte_DE_Float Rte_AlignedCumMtrPosMRF_Deg_f32;
  Rte_DE_EnergyModeStateType Rte_EnergyModeState_Cnt_enum;
  Rte_DE_Float Rte_HwTargetAuthority_Uls_f32;
  Rte_DE_Float Rte_ICMMtrPosMRF_Deg_f32;
  Rte_DE_Boolean Rte_LTRackCntrComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_LTVehCenterComplete_Cnt_lgc;
  Rte_DE_Float Rte_MotorVelMRF_MtrRadpS_f32;
  Rte_DE_Boolean Rte_RackCenterComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_TCFlash_Cnt_lgc;
  Rte_DE_UInt8 Rte_TcFlashErrors_Cnt_u08;
  Rte_DE_Boolean Rte_TcFlashVerify_Cnt_lgc;
  Rte_DE_Float Rte_TCMtrPosOffsMRF_Deg_f32;
  Rte_DE_UInt32 Rte_TcActivePN_Cnt_u32;
  Rte_DE_UInt32 Rte_TcActivePNVldCnt_Cnt_u32;
  Rte_DE_TurnsCntrValStateType Rte_TurnsCntrValidity_Cnt_enum;
} Rte_tsRB_Cd_TurnsCounter_TurnsCounter_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_CASSISTMSA_Cnt_lgc;
  Rte_DE_Float Rte_CBATCURLIMITCUR_Amp_f32;
  Rte_DE_Float Rte_CVEHSPDCURLIMITCURRENT_Amp_f32;
  Rte_DE_Boolean Rte_CVEHSPDCURLIMITER_Cnt_lgc;
  Rte_DE_Float Rte_CVEHSPDCURLIMITSPEED_Kph_f32;
  Rte_DE_MSA_Cmd_Type Rte_MSACommand_MSACmd_enum;
  Rte_DE_Float Rte_SupplyCurrLmt_Amp_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_CCLMSAActive_Cnt_lgc;
  Rte_DE_Float Rte_CCLTrqRamp_Uls_f32;
  Rte_DE_Float Rte_CustCurrLmt_Amp_f32;
} Rte_tsRB_Ap_CustPL_CustPL_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_CCLMSAActive_Cnt_lgc;
  Rte_DE_Float Rte_PreLimitForPwr_MtrNm_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_PowerLimitPerc_Uls_f32;
} Rte_tsRB_Ap_PwrLmtFunc_PwrLmtFunc_Per2;

typedef union
{
  Rte_tsRB_Ap_BVDiag_BVDiag_Per1 Rte_Ap_BVDiag_BVDiag_Per1;
  Rte_tsRB_Ap_TuningSelAuth_TuningSelAuth_Per1 Rte_Ap_TuningSelAuth_TuningSelAuth_Per1;
  Rte_tsRB_Cd_TurnsCounter_TurnsCounter_Per1 Rte_Cd_TurnsCounter_TurnsCounter_Per1;
  Rte_tsRB_Ap_CustPL_CustPL_Per1 Rte_Ap_CustPL_CustPL_Per1;
  Rte_tsRB_Ap_PwrLmtFunc_PwrLmtFunc_Per2 Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per2;
} Rte_tuRB_Task_10ms_7;

typedef struct
{
  Rte_tuRB_Task_10ms_7 Rte_RB;
} Rte_tsTask_10ms_7;

typedef struct
{
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_CRFMotorVel_MtrRadpS_f32;
  Rte_DE_Float Rte_HandwheelVel_HwRadpS_f32;
  Rte_DE_Boolean Rte_HwVelValid_Cnt_lgc;
  Rte_DE_Float Rte_MRFMotorVelUnfiltered_MtrRadpS_f32;
  Rte_DE_Float Rte_SysCHandwheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_SysCMotorVelMRF_MtrRadpS_f32;
} Rte_tsRB_Sa_MtrVel_MtrVel_Per1;

typedef struct
{
  Rte_DE_SInt8 Rte_AssistAssemblyPolarity_Cnt_s08;
  Rte_DE_Float Rte_AlignedCumMtrPosMRF_Deg_f32;
  Rte_DE_Float Rte_CumMtrPosCRF_Deg_f32;
  Rte_DE_Float Rte_SysCCumMtrPosCRF_Deg_f32;
  Rte_DE_Float Rte_SysCCumMtrPosMRF_Deg_f32;
} Rte_tsRB_Sa_MtrPos_MtrPos_Per2;

typedef struct
{
  Rte_DE_Float Rte_MRFCumMtrPos_Deg_f32;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_SInt8 Rte_InstMtrDir_Cnt_s08;
} Rte_tsRB_Ap_QuadDet_QuadDet_Per1;

typedef struct
{
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_EstLd_Henry_f32;
  Rte_DE_Float Rte_EstLq_Henry_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_MtrEnvSpd_MtrRadpS_f32;
  Rte_DE_UInt8 Rte_MtrQuad_Cnt_u08;
  Rte_DE_Float Rte_TermZ_Uls_f32;
} Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per2;

typedef struct
{
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_UInt8 Rte_MtrQuad_Cnt_u08;
  Rte_DE_Float Rte_TermA_Volt_f32;
  Rte_DE_Float Rte_TermBSS_Volt_f32;
  Rte_DE_Float Rte_TermBTOT_Volt_f32;
  Rte_DE_Float Rte_TermXd_Uls_f32;
  Rte_DE_Float Rte_TermXq_Uls_f32;
  Rte_DE_Float Rte_TermY_Uls_f32;
  Rte_DE_Float Rte_VdTerm_Volt_f32;
  Rte_DE_Float Rte_VqTerm_Volt_f32;
} Rte_tsRB_Ap_PhaseCtrl_PhaseCtrl_Per1;

typedef struct
{
  Rte_DE_UInt8 Rte_MtrQuad_Cnt_u08;
  Rte_DE_Boolean Rte_PDActivateTest_Cnt_lgc;
  Rte_DE_SInt16 Rte_PDPhsAdvSel_Cnt_s16;
  Rte_DE_Float Rte_PDTestModIdx_Uls_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_SInt16 Rte_UnCorrPhsAdv_Cnt_s16;
} Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per4;

typedef struct
{
  Rte_DE_UInt32 Rte_CurrentGainSvc_Cnt_b32;
  Rte_DE_Float Rte_ModulationIndex_Uls_f32;
  Rte_DE_SInt16 Rte_PhaseAdvance_Cnt_s16;
  Rte_DE_Float Rte_TorqueCmdMRF_MtrNm_f32;
} Rte_tsRB_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1;

typedef union
{
  Rte_tsRB_Sa_MtrVel_MtrVel_Per1 Rte_Sa_MtrVel_MtrVel_Per1;
  Rte_tsRB_Sa_MtrPos_MtrPos_Per2 Rte_Sa_MtrPos_MtrPos_Per2;
  Rte_tsRB_Ap_QuadDet_QuadDet_Per1 Rte_Ap_QuadDet_QuadDet_Per1;
  Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per2 Rte_Ap_VltgCtrl_VltgCtrl_Per2;
  Rte_tsRB_Ap_PhaseCtrl_PhaseCtrl_Per1 Rte_Ap_PhaseCtrl_PhaseCtrl_Per1;
  Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per4 Rte_Ap_VltgCtrl_VltgCtrl_Per4;
  Rte_tsRB_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1 Rte_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1;
} Rte_tuRB_Task_1ms_10;

typedef struct
{
  Rte_DE_SInt8 Rte_I_Polarity_AssistAssyPolarity_Cnt_s08;
  Rte_DE_Float Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32;
  Rte_DE_Float Rte_I_MtrPos_CumMtrPosMRF_Deg_f32;
  Rte_DE_Float Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_UInt8 Rte_I_QuadDet_MtrQuad_Cnt_u08;
  Rte_DE_Float Rte_I_BatteryVoltage_Vecu_Volt_f32;
  Rte_DE_Float Rte_I_VltgCtrl_TermA_Volt_f32;
  Rte_DE_Float Rte_I_VltgCtrl_TermBTOT_Volt_f32;
  Rte_DE_Float Rte_I_VltgCtrl_TermXd_Uls_f32;
  Rte_DE_Float Rte_I_VltgCtrl_TermXq_Uls_f32;
  Rte_DE_Float Rte_I_VltgCtrl_TermY_Uls_f32;
  Rte_DE_Float Rte_I_VltgCtrl_VdTerm_Volt_f32;
  Rte_DE_Float Rte_I_VltgCtrl_VqTerm_Volt_f32;
  Rte_DE_Float Rte_I_VltgCtrl_ModIdx_Uls_f32;
  Rte_DE_SInt16 Rte_I_VltgCtrl_PhsAdv_Cnt_s16;
  Rte_DE_UInt16 Rte_I_MtrCtrlOpConv_CommutationOffset_Cnt_u16;
  Rte_DE_Float Rte_I_MtrCtrlOpConv_DeadTimeComp_Uls_f32;
  Rte_DE_Float Rte_I_MtrCtrlOpConv_ModulationIndexFinal_Uls_f32;
  Rte_DE_SInt16 Rte_I_MtrCtrlOpConv_MtrTrqCmdSign_Cnt_s16;
  Rte_DE_UInt16 Rte_I_MtrCtrlOpConv_PhaseAdvanceFinal_Cnt_u16;
} Rte_tsTB_Task_1ms_10;

typedef struct
{
  Rte_tsTB_Task_1ms_10 Rte_TB;
  Rte_tuRB_Task_1ms_10 Rte_RB;
} Rte_tsTask_1ms_10;

typedef struct
{
  Rte_DE_Boolean Rte_DftStallLimit_Cnt_lgc;
  Rte_DE_Float Rte_PreLimitForStall_MtrNm_f32;
  Rte_DE_Float Rte_AssistStallLimit_MtrNm_f32;
} Rte_tsRB_Ap_HiLoadStall_HiLoadStall_Per1;

typedef struct
{
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
  Rte_DE_Float Rte_AstVehSpdLimit_MtrNm_f32;
} Rte_tsRB_Ap_VehSpdLmt_VehSpdLmt_Per1;

typedef struct
{
  Rte_DE_Float Rte_BasicRtnCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_DefeatReturnSvc_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsHwPosDis_Cnt_lgc;
  Rte_DE_Boolean Rte_EnableCVR_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelVelocity_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_Float Rte_PAReturnSclFct_Uls_f32;
  Rte_DE_Float Rte_ReturnDDFactor_Uls_f32;
  Rte_DE_Float Rte_ReturnOffset_HwDeg_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_ReturnCmd_MtrNm_f32;
} Rte_tsRB_Ap_BmwRtnArbn_BmwRtnArbn_Per1;

typedef struct
{
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_HighFreqAssist_MtrNm_f32;
} Rte_tsRB_Ap_TrqBasedInrtCmp_TrqBasedInrtCmp_Per1;

typedef struct
{
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Boolean Rte_HysAddSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
} Rte_tsRB_Ap_HystAdd_HystAdd_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DftAsstTbl_Cnt_lgc;
  Rte_DE_Float Rte_DutyCycleLevel_Uls_f32;
  Rte_DE_Float Rte_DwnldAsstGain_Uls_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_HwTrqHysAdd_HwNm_f32;
  Rte_DE_Float Rte_IpTrqOvr_HwNm_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
} Rte_tsRB_Ap_Assist_Assist_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_DefeatHystService_Cnt_lgc;
  Rte_DE_Float Rte_FricOffset_HwNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
  Rte_DE_Float Rte_HysteresisComp_MtrNm_f32;
} Rte_tsRB_Ap_HystComp_HystComp_Per1;

typedef struct
{
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_TJADampSclRqst_Uls_f32;
  Rte_DE_TJAStateType Rte_TJAStateRqst_Cnt_enum;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_TJAStateType Rte_TJAState_Cnt_enum;
} Rte_tsRB_Ap_TJADamp_TJADamp_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_CustomDamp_MtrNm_f32;
  Rte_DE_Float Rte_DampingDDFactor_Uls_f32;
  Rte_DE_Boolean Rte_DefeatDampingSvc_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_MotorVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_DampingCmd_MtrNm_f32;
} Rte_tsRB_Ap_Damping_Damping_Per1;

typedef struct
{
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_CRFMotorVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleLonAccel_KphpS_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
  Rte_DE_Float Rte_FrqDepDmpnInrtCmp_MtrNm_f32;
} Rte_tsRB_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistDDFactor_Uls_f32;
  Rte_DE_Float Rte_AsstFWActive_Uls_f32;
  Rte_DE_Float Rte_CombinedAssist_MtrNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_SysAssistCmd_MtrNm_f32;
} Rte_tsRB_Ap_StabilityComp2_StabilityComp2_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DisableLearning_Cnt_lgc;
  Rte_DE_Boolean Rte_DisableOutput_Cnt_lgc;
  Rte_DE_Float Rte_EstLatAcc_MpSecSq_f32;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelVelocity_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Boolean Rte_PullCmpCustLrngDi_Cnt_lgc;
  Rte_DE_Boolean Rte_PullCmpEna_Cnt_lgc;
  Rte_DE_Float Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Float Rte_VehicleYawRate_DegpS_f32;
  Rte_DE_Float Rte_PullCmpShoTermIntgtrSt_HwNm_f32;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DisableOutput_Cnt_lgc;
  Rte_DE_Boolean Rte_PullCmpEna_Cnt_lgc;
  Rte_DE_Float Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32;
  Rte_DE_Float Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_PullCompCmd_MtrNm_f32;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per2;

typedef struct
{
  Rte_DE_Boolean Rte_MtrDrvrInitComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscATestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrDrvrInitStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscATestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestStart_Cnt_lgc;
} Rte_tsRB_Ap_HwPwUp_HwPwUp_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_CASSISTMSA_Cnt_lgc;
  Rte_DE_Boolean Rte_EngONSrlComSvcDft_Cnt_lgc;
  Rte_DE_SG_ST_CENG Rte_SrlComEngDrvStatus_ST_CENG;
  Rte_DE_New_Coding_64 Rte_SrlComVehCdnStatus_VehCdnStatus;
  Rte_DE_ST_V_VEH_NSS Rte_SrlComVehNearStandstill_Cnt_u08;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Boolean Rte_ATermActive_Cnt_lgc;
  Rte_DE_Boolean Rte_CTermActive_Cnt_lgc;
  Rte_DE_MSA_Cmd_Type Rte_MSACommand_MSACmd_enum;
  Rte_DE_Float Rte_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_OperRampValue_Uls_f32;
} Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_CERRMVOLTFALLBACK_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsDefVehSpd_Cnt_lgc;
  Rte_DE_CTR_ERRM_BN_U Rte_RxCtrErrmBnU_Cnt_u8;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_HaptcFbEnable_Cnt_lgc;
  Rte_DE_UInt16 Rte_HaptcFbIntenNr_Cnt_u16;
  Rte_DE_Boolean Rte_HaptcFbIntenSigVld_Cnt_lgc;
  Rte_DE_UInt16 Rte_HaptcFbPatNr_Cnt_u16;
  Rte_DE_Boolean Rte_HaptcFbPatSigVld_Cnt_lgc;
  Rte_DE_Float Rte_PostLimitTrq_MtrNm_f32;
  Rte_DE_Float Rte_PreLimitTrq_MtrNm_f32;
  Rte_DE_Boolean Rte_TrqOscActv_Cnt_lgc;
  Rte_DE_Boolean Rte_TrqOscDCExceeded_Cnt_lgc;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_UInt8 Rte_HaptcFbSt_Cnt_u08;
  Rte_DE_Float Rte_TrqOscAmp_MtrNm_f32;
  Rte_DE_Boolean Rte_TrqOscEnable_Cnt_lgc;
  Rte_DE_Float Rte_TrqOscFallingRampRate_MtrNmpS_f32;
  Rte_DE_Float Rte_TrqOscFreq_Hz_f32;
  Rte_DE_Float Rte_TrqOscRisngRampRate_MtrNmpS_f32;
} Rte_tsRB_Ap_BmwHaptcFb_BmwHaptcFb_Per1;

typedef union
{
  Rte_tsRB_Ap_HiLoadStall_HiLoadStall_Per1 Rte_Ap_HiLoadStall_HiLoadStall_Per1;
  Rte_tsRB_Ap_VehSpdLmt_VehSpdLmt_Per1 Rte_Ap_VehSpdLmt_VehSpdLmt_Per1;
  Rte_tsRB_Ap_BmwRtnArbn_BmwRtnArbn_Per1 Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1;
  Rte_tsRB_Ap_TrqBasedInrtCmp_TrqBasedInrtCmp_Per1 Rte_Ap_TrqBasedInrtCmp_TrqBasedInrtCmp_Per1;
  Rte_tsRB_Ap_HystAdd_HystAdd_Per1 Rte_Ap_HystAdd_HystAdd_Per1;
  Rte_tsRB_Ap_Assist_Assist_Per1 Rte_Ap_Assist_Assist_Per1;
  Rte_tsRB_Ap_HystComp_HystComp_Per1 Rte_Ap_HystComp_HystComp_Per1;
  Rte_tsRB_Ap_TJADamp_TJADamp_Per1 Rte_Ap_TJADamp_TJADamp_Per1;
  Rte_tsRB_Ap_Damping_Damping_Per1 Rte_Ap_Damping_Damping_Per1;
  Rte_tsRB_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1 Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1;
  Rte_tsRB_Ap_StabilityComp2_StabilityComp2_Per1 Rte_Ap_StabilityComp2_StabilityComp2_Per1;
  Rte_tsRB_Ap_ActivePull_ActivePull_Per1 Rte_Ap_ActivePull_ActivePull_Per1;
  Rte_tsRB_Ap_ActivePull_ActivePull_Per2 Rte_Ap_ActivePull_ActivePull_Per2;
  Rte_tsRB_Ap_HwPwUp_HwPwUp_Per1 Rte_Ap_HwPwUp_HwPwUp_Per1;
  Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Per1 Rte_Ap_VehPwrMd_VehPwrMd_Per1;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_Per1 Rte_Ap_SrlComInput_SrlComInput_Per1;
  Rte_tsRB_Ap_BmwHaptcFb_BmwHaptcFb_Per1 Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1;
} Rte_tuRB_Task_2msA_9;

typedef struct
{
  Rte_DE_Float Rte_I_MtrVel_CRFMotorVel_MtrRadpS_f32;
  Rte_DE_Float Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_I_SignlCondn_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_I_MtrTempEst_AssistMechTempEst_DegC_f32;
  Rte_DE_Boolean Rte_I_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc;
  Rte_DE_Float Rte_I_MtrVel_HandwheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_I_Sweep_OutputHwTrq_HwNm_f32;
  Rte_DE_Float Rte_I_PosServo_PosSrvoReturnSclFct_Uls_f32;
  Rte_DE_Float Rte_I_DrvDynCtrl_ReturnDDFactor_Uls_f32;
  Rte_DE_Float Rte_I_SrlComInput_ReturnOffset_HwDeg_f32;
  Rte_DE_Float Rte_I_Return_ReturnCmd_MtrNm_f32;
  Rte_DE_Float Rte_I_HystAdd_HysAddHwTrq_HwNm_f32;
  Rte_DE_Float Rte_I_DrvDynCtrl_AssistDDFactor_Uls_f32;
  Rte_DE_Float Rte_I_Assist_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_I_Ap_TJADamp_CustomDamp_MtrNm_f32;
} Rte_tsTB_Task_2msA_9;

typedef struct
{
  Rte_tsTB_Task_2msA_9 Rte_TB;
  Rte_tuRB_Task_2msA_9 Rte_RB;
} Rte_tsTask_2msA_9;

typedef struct
{
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_Defeat_AsstTbl_Service_Cnt_lgc;
  Rte_DE_Float Rte_HighFreqAssist_MtrNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_HysteresisComp_MtrNm_f32;
  Rte_DE_ManufModeType Rte_MEC_Counter_Cnt_enum;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_AsstFirewallActive_Uls_f32;
  Rte_DE_Float Rte_CombinedAssist_MtrNm_f32;
} Rte_tsRB_Ap_AssistFirewall_AssistFirewall_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistDDFactor_Uls_f32;
  Rte_DE_Float Rte_AsstFWActive_Uls_f32;
  Rte_DE_Float Rte_CombinedAssist_MtrNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_SysAssistCmd_MtrNm_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_AssistCmd_MtrNm_f32;
} Rte_tsRB_Ap_StabilityComp_StabilityComp_Per1;

typedef struct
{
  Rte_DE_Float Rte_AsstFirewallActive_Uls_f32;
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_DampingCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_Defeat_Damping_Svc_Cnt_lgc;
  Rte_DE_Boolean Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_InertiaComp_MtrNm_f32;
  Rte_DE_ManufModeType Rte_MEC_Counter_Cnt_enum;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_VehicleLonAccel_KphpS_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
  Rte_DE_Float Rte_CombinedDamping_MtrNm_f32;
} Rte_tsRB_Ap_DampingFirewall_DampingFirewall_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_Defeat_Return_Svc_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_ManufModeType Rte_MEC_Counter_Cnt_enum;
  Rte_DE_Float Rte_ReturnCmd_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_LimitedReturn_MtrNm_f32;
} Rte_tsRB_Ap_ReturnFirewall_ReturnFirewall_Per1;

typedef struct
{
  Rte_DE_Float Rte_CcwEOT_HwDeg_f32;
  Rte_DE_Boolean Rte_CcwFound_Cnt_lgc;
  Rte_DE_Float Rte_CwEOT_HwDeg_f32;
  Rte_DE_Boolean Rte_CwFound_Cnt_lgc;
  Rte_DE_Boolean Rte_EOTDisable_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_OutputRampMultLtd_Uls_f32;
  Rte_DE_Float Rte_PreLimitTorque_MtrNm_f32;
} Rte_tsRB_Ap_EOTActuatorMng_EOTActuatorMng_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistEOTDamping_MtrNm_f32;
  Rte_DE_Float Rte_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_EOTDisable_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_ManufModeType Rte_MEC_Counter_Cnt_enum;
  Rte_DE_Float Rte_Vehicle_Speed_Kph_f32;
  Rte_DE_Float Rte_EOTDampingLtd_MtrNm_f32;
} Rte_tsRB_Ap_EtDmpFw_EtDmpFw_Per1;

typedef struct
{
  Rte_DE_Float Rte_DiagRampRate_XpmS_f32;
  Rte_DE_Float Rte_DiagRampValue_Uls_f32;
  Rte_DE_Boolean Rte_DiagStsDiagRmpActive_Cnt_lgc;
  Rte_DE_Float Rte_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_OperRampValue_Uls_f32;
  Rte_DE_Boolean Rte_RampSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_RampDwnStatusComplete_Cnt_lgc;
} Rte_tsRB_Ap_StOpCtrl_StOpCtrl_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistEOTGain_Uls_f32;
  Rte_DE_Float Rte_AssistEOTLimit_MtrNm_f32;
  Rte_DE_Float Rte_AssistStallLimit_MtrNm_f32;
  Rte_DE_Float Rte_AssistVehSpdLimit_MtrNm_f32;
  Rte_DE_Float Rte_CCLTrqRamp_Uls_f32;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
  Rte_DE_Float Rte_ThermalLimit_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_EOTGainLtd_Uls_f32;
  Rte_DE_Float Rte_EOTLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_OutputRampMultLtd_Uls_f32;
  Rte_DE_Float Rte_StallLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_ThermalLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_VehSpdLimitLtd_MtrNm_f32;
} Rte_tsRB_Ap_LmtCod_LmtCod_Per1;

typedef struct
{
  Rte_DE_Float Rte_TrqOscAmp_MtrNm_f32;
  Rte_DE_Boolean Rte_TrqOscEnable_Cnt_lgc;
  Rte_DE_Float Rte_TrqOscFallRampRate_MtrNmpS_f32;
  Rte_DE_Float Rte_TrqOscFreq_Hz_f32;
  Rte_DE_Float Rte_TrqOscRisngRampRate_MtrNmpS_f32;
  Rte_DE_Boolean Rte_TrqOscActv_Cnt_lgc;
  Rte_DE_Float Rte_TrqOscCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_TrqOscDCExceeded_Cnt_lgc;
} Rte_tsRB_Ap_TrqOsc_TrqOsc_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DrvDynActive_Cnt_lgc;
  Rte_DE_Boolean Rte_DrvgDynErrIfActv_Cnt_lgc;
  Rte_DE_QU_SER_STMOM_STMOM_DV_ACT Rte_DrvgDynIfSt_Cnt_u08;
  Rte_DE_Boolean Rte_OpTrqOvRmpInEnable_Cnt_lgc;
  Rte_DE_Float Rte_SerlComTarSteerTqDrvrActr_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_OutpTqOvrl_MtrNm_f32;
} Rte_tsRB_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_AssistPowerLimit_MtrNm_f32;
  Rte_DE_Float Rte_CombinedDamping_MtrNm_f32;
  Rte_DE_Boolean Rte_DefeatLimitService_Cnt_lgc;
  Rte_DE_Float Rte_EOTDampingLtd_MtrNm_f32;
  Rte_DE_Float Rte_EOTGainLtd_Uls_f32;
  Rte_DE_Float Rte_EOTLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_LimitedReturn_MtrNm_f32;
  Rte_DE_Boolean Rte_LrnPnCtrDisable_Cnt_lgc;
  Rte_DE_Boolean Rte_LrnPnCtrEnable_Cnt_lgc;
  Rte_DE_Float Rte_LrnPnCtrTCmd_MtrNm_f32;
  Rte_DE_Float Rte_OutpTqOvrl_MtrNm_f32;
  Rte_DE_Float Rte_OutputRampMultLtd_Uls_f32;
  Rte_DE_Float Rte_PrkAssistCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_PrkAssistDisable_Cnt_lgc;
  Rte_DE_Float Rte_PullCompCmd_MtrNm_f32;
  Rte_DE_Float Rte_StallLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_ThermalLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_TrqOscCmd_MtrNm_f32;
  Rte_DE_Float Rte_VehSpdLimitLtd_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WhlImbRejCmd_MtrNm_f32;
  Rte_DE_Float Rte_PostLimitTorque_MtrNm_f32;
  Rte_DE_Float Rte_PreLimitForPower_MtrNm_f32;
  Rte_DE_Float Rte_PreLimitForStall_MtrNm_f32;
  Rte_DE_Float Rte_PreLimitTorque_MtrNm_f32;
} Rte_tsRB_Ap_AssistSumnLmt_AssistSumnLmt_Per1;

typedef struct
{
  Rte_DE_Float Rte_InputMtrTrq_MtrNm_f32;
} Rte_tsRB_Ap_Sweep2_Sweep2_Per1;

typedef struct
{
  Rte_DE_Float Rte_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_DiagStsF2Active_Cnt_lgc;
  Rte_DE_Float Rte_SumLimTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_SysC_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_SysC_MRFMtrTrqCmd_MtrNm_f32;
} Rte_tsRB_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1;

typedef struct
{
  Rte_DE_Float Rte_AlignedCumMtrPosMRF_Deg_f32;
  Rte_DE_Boolean Rte_DiagStsDefHwPos_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsHwPosDis_Cnt_lgc;
  Rte_DE_SInt16 Rte_ICMRevOffsetCRF_Rev_s16;
  Rte_DE_ST_OFFS_QUAD_EPS Rte_ICMRevOffsetStatus_Cnt_u08;
  Rte_DE_Boolean Rte_LTRckCntrComplete_Cnt_lgc;
  Rte_DE_SInt8 Rte_Polarity_Cnt_s08;
  Rte_DE_Float Rte_RackCenter_HwDeg_f32;
  Rte_DE_Float Rte_TCMtrPosOffsMRF_Deg_f32;
  Rte_DE_Float Rte_TorqueCmdCRF_MtrNm_f32;
  Rte_DE_TurnsCntrValStateType Rte_TurnsCntrValidity_Cnt_enum;
  Rte_DE_Float Rte_AlignedHwPos_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HwTargetAuthority_Uls_f32;
  Rte_DE_Float Rte_ICMMtrPosMRF_Deg_f32;
  Rte_DE_UInt16 Rte_RacktoVehCntrOffset_Cnt_u16;
  Rte_DE_UInt8 Rte_RevOffsetState_Cnt_u08;
  Rte_DE_Float Rte_SrlComHwPos_HwDeg_f32;
} Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per1;

typedef struct
{
  Rte_DE_FETPHASETYPE_ENUM Rte_FETFaultPhase_Cnt_enum;
  Rte_DE_FETFAULTTYPE_ENUM Rte_FETFaultType_Cnt_enum;
} Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Per3;

typedef struct
{
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_Float Rte_TermBSS_Volt_f32;
} Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per1;

typedef struct
{
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_ExpIq_Amp_f32;
  Rte_DE_Float Rte_ModIdx_Uls_f32;
  Rte_DE_Float Rte_TermXq_Uls_f32;
  Rte_DE_SInt16 Rte_UncorrPhsAdv_Cnt_s16;
  Rte_DE_Float Rte_EstPkCurr_AmpSq_f32;
} Rte_tsRB_Ap_CurrentEst_CurrentEst_Per1;

typedef struct
{
  Rte_DE_Float Rte_IdEst_Amp_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_Float Rte_MtrCurrQax_Amp_f32;
  Rte_DE_Boolean Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_ValidCurrSample_Cnt_lgc;
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_EstLd_Henry_f32;
  Rte_DE_Float Rte_EstLq_Henry_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_ExpIq_Amp_f32;
} Rte_tsRB_Ap_ParamComp_ParamComp_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_CCLMSAActive_Cnt_lgc;
  Rte_DE_Float Rte_MtrEnvSpd_MtrRadpS_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
} Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per3;

typedef struct
{
  Rte_DE_UInt8 Rte_MotorQuadrant_Cnt_u08;
  Rte_DE_Float Rte_MotorVelMRF_MtrRadpS_f32;
  Rte_DE_Float Rte_RawCurrFiltered_Amp_f32;
  Rte_DE_Boolean Rte_PDActivateTest_Cnt_lgc;
  Rte_DE_SInt16 Rte_PDPhaseAdvSelect_Cnt_s16;
  Rte_DE_Float Rte_PDTestModIndex_Uls_f32;
} Rte_tsRB_Sa_PhaseDscnt_PhaseDscnt_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_ATerm_Cnt_lgc;
  Rte_DE_Boolean Rte_CTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_ControlledDampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_FTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_RampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
} Rte_tsRB_Ap_StaMd_StaMd_Per1;

typedef struct
{
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
  Rte_DE_UInt16 Rte_DutyCycleSmall_Cnt_u16;
  Rte_DE_UInt32 Rte_ExpectedOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeC_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeC_Cnt_u32;
  Rte_DE_Float Rte_SWDutyCycleA_Uls_f32;
  Rte_DE_Float Rte_SWDutyCycleB_Uls_f32;
  Rte_DE_Float Rte_SWDutyCycleC_Uls_f32;
} Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsDefVehSpd_Cnt_lgc;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
  Rte_DE_Boolean Rte_SrlComEngCrank_Cnt_lgc;
  Rte_DE_Boolean Rte_VehSpdValid_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput2_SrlComInput2_Per1;

typedef union
{
  Rte_tsRB_Ap_AssistFirewall_AssistFirewall_Per1 Rte_Ap_AssistFirewall_AssistFirewall_Per1;
  Rte_tsRB_Ap_StabilityComp_StabilityComp_Per1 Rte_Ap_StabilityComp_StabilityComp_Per1;
  Rte_tsRB_Ap_DampingFirewall_DampingFirewall_Per1 Rte_Ap_DampingFirewall_DampingFirewall_Per1;
  Rte_tsRB_Ap_ReturnFirewall_ReturnFirewall_Per1 Rte_Ap_ReturnFirewall_ReturnFirewall_Per1;
  Rte_tsRB_Ap_EOTActuatorMng_EOTActuatorMng_Per1 Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1;
  Rte_tsRB_Ap_EtDmpFw_EtDmpFw_Per1 Rte_Ap_EtDmpFw_EtDmpFw_Per1;
  Rte_tsRB_Ap_StOpCtrl_StOpCtrl_Per1 Rte_Ap_StOpCtrl_StOpCtrl_Per1;
  Rte_tsRB_Ap_LmtCod_LmtCod_Per1 Rte_Ap_LmtCod_LmtCod_Per1;
  Rte_tsRB_Ap_TrqOsc_TrqOsc_Per1 Rte_Ap_TrqOsc_TrqOsc_Per1;
  Rte_tsRB_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1 Rte_Ap_BmwTqOvrlCdng_BmwTqOvrlCdng_Per1;
  Rte_tsRB_Ap_AssistSumnLmt_AssistSumnLmt_Per1 Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1;
  Rte_tsRB_Ap_Sweep2_Sweep2_Per1 Rte_Ap_Sweep2_Sweep2_Per1;
  Rte_tsRB_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1 Rte_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1;
  Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Per1 Rte_Ap_AbsHwPos_AbsHwPos_Per1;
  Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Per3 Rte_Sa_CDDInterface10_CDDInterface10_Per3;
  Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per1 Rte_Ap_VltgCtrl_VltgCtrl_Per1;
  Rte_tsRB_Ap_CurrentEst_CurrentEst_Per1 Rte_Ap_CurrentEst_CurrentEst_Per1;
  Rte_tsRB_Ap_ParamComp_ParamComp_Per1 Rte_Ap_ParamComp_ParamComp_Per1;
  Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per3 Rte_Ap_VltgCtrl_VltgCtrl_Per3;
  Rte_tsRB_Sa_PhaseDscnt_PhaseDscnt_Per1 Rte_Sa_PhaseDscnt_PhaseDscnt_Per1;
  Rte_tsRB_Ap_StaMd_StaMd_Per1 Rte_Ap_StaMd_StaMd_Per1;
  Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Per1 Rte_Sa_CDDInterface10_CDDInterface10_Per1;
  Rte_tsRB_Ap_SrlComInput2_SrlComInput2_Per1 Rte_Ap_SrlComInput2_SrlComInput2_Per1;
} Rte_tuRB_Task_2ms_10;

typedef struct
{
  Rte_DE_Float Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_I_MtrVel_CRFMotorVel_MtrRadpS_f32;
  Rte_DE_Float Rte_I_SignlCondn_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_I_EOTActuatorMng_AssistEOTDamping_MtrNm_f32;
  Rte_DE_Float Rte_I_EOTActuatorMng_AssistEOTGain_Uls_f32;
  Rte_DE_Float Rte_I_EOTActuatorMng_AssistEOTLimit_MtrNm_f32;
  Rte_DE_Float Rte_I_StOpCtrl_OutputRampMult_Uls_f32;
  Rte_DE_Float Rte_I_Sweep2_OutputMtrTrq_MtrNm_f32;
  Rte_DE_SInt8 Rte_I_Polarity_AssistAssyPolarity_Cnt_s08;
  Rte_DE_Float Rte_I_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32;
  Rte_DE_Float Rte_I_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32;
  Rte_DE_Boolean Rte_I_CtrldDisShtdn_CtrldDmpStsCmp_Cnt_lgc;
  Rte_DE_Float Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_Float Rte_I_ParamComp_EstR_Ohm_f32;
  Rte_DE_Float Rte_I_BatteryVoltage_Vecu_Volt_f32;
  Rte_DE_Float Rte_I_CurrentEst_IdEst_Amp_f32;
  Rte_DE_Float Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32;
  Rte_DE_UInt8 Rte_I_QuadDet_MtrQuad_Cnt_u08;
} Rte_tsTB_Task_2ms_10;

typedef struct
{
  Rte_tsTB_Task_2ms_10 Rte_TB;
  Rte_tuRB_Task_2ms_10 Rte_RB;
} Rte_tsTask_2ms_10;

typedef struct
{
  Rte_DE_Boolean Rte_MtrDrvrInitStart_Cnt_lgc;
  Rte_DE_Boolean Rte_VswitchClosed_Cnt_lgc;
  Rte_DE_FETPHASETYPE_ENUM Rte_FETFaultPhase_Cnt_enum;
  Rte_DE_FETFAULTTYPE_ENUM Rte_FETFaultType_Cnt_enum;
  Rte_DE_Boolean Rte_MtrDrvrInitComplete_Cnt_lgc;
} Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Per1;

typedef struct
{
  Rte_DE_UInt32 Rte_ExpectedOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeC_Cnt_u32;
  Rte_DE_Float Rte_LRPRCorrectedMtrPosCaptured_Rev_f32;
  Rte_DE_Float Rte_LRPRModulationIndexCaptured_Uls_f32;
  Rte_DE_SInt16 Rte_LRPRPhaseadvanceCaptured_Cnt_s16;
  Rte_DE_UInt32 Rte_MeasuredOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeC_Cnt_u32;
  Rte_DE_Float Rte_MotorVelMRFUnfiltered_MtrRadpS_f32;
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
  Rte_DE_Boolean Rte_PDActivateTest_Cnt_lgc;
} Rte_tsRB_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1;

typedef union
{
  Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Per1 Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1;
  Rte_tsRB_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1;
} Rte_tuRB_Task_2ms_11;

typedef struct
{
  Rte_tuRB_Task_2ms_11 Rte_RB;
} Rte_tsTask_2ms_11;

typedef struct
{
  Rte_DE_Float Rte_ADCMtrCurr1_Volt_f32;
  Rte_DE_Float Rte_SysCT1ADC_Volt_f32;
  Rte_DE_Float Rte_SysCT2ADC_Volt_f32;
  Rte_DE_Float Rte_T1ADC_Volt_f32;
  Rte_DE_Float Rte_T2ADC_Volt_f32;
} Rte_tsRB_IoHwAb7_IoHwAb7_FwdPathAdc;

typedef struct
{
  Rte_DE_Float Rte_MotorVelMRF_MtrRadpS_f32;
  Rte_DE_Float Rte_CorrectedMtrPos_Rev_f32;
  Rte_DE_Float Rte_CosTheta1_Volt_f32;
  Rte_DE_Float Rte_MechMtrPos_Rev_f32;
  Rte_DE_Float Rte_SinTheta1_Volt_f32;
  Rte_DE_Float Rte_SysCCorrectedMtrPos_Rev_f32;
  Rte_DE_Float Rte_SysCMechMtrPos_Rev_f32;
} Rte_tsRB_Sa_MtrPos2_MtrPos2_Per1;

typedef struct
{
  Rte_DE_Float Rte_AlignedHwPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_LrnPnCenterEnable_Cnt_lgc;
  Rte_DE_Float Rte_LrnPnCntrCmd_MtrNm_f32;
  Rte_DE_Float Rte_LrnPnCntrHwCenter_HwDeg_f32;
  Rte_DE_Float Rte_LrnPnCntrHwTravel_HwDeg_f32;
  Rte_DE_LktoLkStrStateType Rte_LrnPnCntrState_Cnt_enum;
} Rte_tsRB_Ap_LktoLkStr_LktoLkStr_Per1;

typedef struct
{
  Rte_DE_Float Rte_HwPos_HwDeg_f32;
  Rte_DE_OscTrajCmdStateType Rte_OscTrajState_Cnt_enum;
} Rte_tsRB_Ap_OscTraj_OscTraj_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsRmpZeroNRec_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStsRmpZeroRec_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_LimitPercentFiltered_Uls_f32;
  Rte_DE_Boolean Rte_PAEnableRqst_Cnt_lgc;
  Rte_DE_Boolean Rte_PAErrInterfaceActive_Cnt_lgc;
  Rte_DE_Float Rte_PAHWAngleRqst_HwDeg_f32;
  Rte_DE_ST_V_VEH_NSS Rte_PASpdHigh_Cnt_u08;
  Rte_DE_DVCO_VEH Rte_PASpdStdStill_Cnt_u08;
  Rte_DE_Boolean Rte_PendEnable_Cnt_lgc;
  Rte_DE_Float Rte_PendHwAngle_HwDeg_f32;
  Rte_DE_Boolean Rte_PosTrajEnable_Cnt_lgc;
  Rte_DE_Float Rte_PosTrajHwAngle_HwDeg_f32;
  Rte_DE_Boolean Rte_PosServEnable_Cnt_lgc;
  Rte_DE_Float Rte_PosServoHwAngle_HwDeg_f32;
  Rte_DE_QU_SER_WSTA_EST_FTAX Rte_PrkAssistState_Cnt_u08;
} Rte_tsRB_Ap_ParkAstEnbl_ParkAstEnbl_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DDEnableRqst_Cnt_lgc;
  Rte_DE_Boolean Rte_DDErrInterfaceActive_Cnt_lgc;
  Rte_DE_Boolean Rte_DiagStatus_Cnt_lgc;
  Rte_DE_QU_SER_WSTA_EST_FTAX Rte_PrkAssistState_Cnt_u08;
  Rte_DE_Boolean Rte_DrvDynActive_Cnt_lgc;
  Rte_DE_QU_SER_STMOM_STMOM_DV_ACT Rte_DrvDynInterfaceState_Cnt_u08;
  Rte_DE_Boolean Rte_OpTrqOvRmpInEnable_Cnt_lgc;
} Rte_tsRB_Ap_DrvDynEnbl_DrvDynEnbl_Per1;

typedef struct
{
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_PosSrvoEnable_Cnt_lgc;
  Rte_DE_Float Rte_PosSrvoHwAngle_HwDeg_f32;
  Rte_DE_Float Rte_PosSrvoCmd_MtrNm_f32;
  Rte_DE_Float Rte_PosSrvoReturnSclFct_Uls_f32;
  Rte_DE_Float Rte_PosSrvoSmoothEnable_Uls_f32;
} Rte_tsRB_Ap_PosServo_PosServo_Per1;

typedef struct
{
  Rte_DE_UInt8 Rte_AbsPosStepSignal_Cnt_u08;
  Rte_DE_Float Rte_T1ADC_Volt_f32;
  Rte_DE_Float Rte_T2ADC_Volt_f32;
  Rte_DE_Float Rte_AnaDiffHwTrq_Volt_f32;
  Rte_DE_HwTrqStatusType Rte_ErrorActiveAnalog_Cnt_enum;
  Rte_DE_Boolean Rte_SrlComHwTrqValid_Cnt_lgc;
  Rte_DE_Float Rte_SysCAnaHwTorque_HwNm_f32;
} Rte_tsRB_Sa_HwTrq_HwTrq_Per1;

typedef struct
{
  Rte_DE_Float Rte_InputHwTrq_HwNm_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Boolean Rte_VehSpdValid_Cnt_lgc;
} Rte_tsRB_Ap_Sweep_Sweep_Per1;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_SysC_Vecu_Volt_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Boolean Rte_VswitchClosed_Cnt_lgc;
} Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per1;

typedef struct
{
  Rte_DE_Float Rte_SrlComVehLatAccel_MpSecSq_f32;
  Rte_DE_Boolean Rte_SrlComVehLatAccelValid_Cnt_lgc;
  Rte_DE_Float Rte_SrlComVehLonAccel_MpSecSq_f32;
  Rte_DE_Boolean Rte_SrlComVehLonAccelValid_Cnt_lgc;
  Rte_DE_Float Rte_SrlComVehSpeed_Kph_f32;
  Rte_DE_Boolean Rte_SrlComVehSpeedValid_Cnt_lgc;
  Rte_DE_Float Rte_SrlComVehYawRate_DegpS_f32;
  Rte_DE_Boolean Rte_SrlComVehYawRateValid_Cnt_lgc;
  Rte_DE_Float Rte_EstimdLatAcce_MpSecSq_f32;
  Rte_DE_Boolean Rte_EstimdLatAcceValid_Cnt_lgc;
  Rte_DE_Boolean Rte_VehicleLatAcceValid_Cnt_lgc;
  Rte_DE_Float Rte_VehicleLatAccel_MpSecSq_f32;
  Rte_DE_Float Rte_VehicleLonAccel_KphpS_f32;
  Rte_DE_Boolean Rte_VehicleLonAccelValid_Cnt_lgc;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
  Rte_DE_Float Rte_VehicleYawRate_DegpS_f32;
  Rte_DE_Boolean Rte_VehicleYawRateValid_Cnt_lgc;
} Rte_tsRB_Ap_SignlCondn_SignlCondn_Per1;

typedef struct
{
  Rte_DE_Float Rte_DDAstFactRqst_Uls_f32;
  Rte_DE_Float Rte_DDDmpFactRqst_Uls_f32;
  Rte_DE_Float Rte_DDRtnFactRqst_Uls_f32;
  Rte_DE_Boolean Rte_DrvDynActive_Cnt_lgc;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Float Rte_AssistDDFactor_Uls_f32;
  Rte_DE_Float Rte_DampingDDFactor_Uls_f32;
  Rte_DE_Float Rte_ReturnDDFactor_Uls_f32;
} Rte_tsRB_Ap_DrvDynCtrl_DrvDynCtrl_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsTempRdPrf_Cnt_lgc;
  Rte_DE_Float Rte_TemperatureADC_Volt_f32;
  Rte_DE_Float Rte_FiltMeasTemp_DegC_f32;
} Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per1;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_MotorVelocityMRFUnfiltered_MtrRadpS_f32;
  Rte_DE_Float Rte_OVERRIDESIGDIAGADC_Volt_f32;
  Rte_DE_Float Rte_PMOSDIAGADC_Volt_f32;
  Rte_DE_Boolean Rte_PwrDiscATestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscATestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscClosed_Cnt_lgc;
} Rte_tsRB_Sa_BkCpPc_BkCpPc_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_CCLMSAActive_Cnt_lgc;
  Rte_DE_Float Rte_CustCurrLmt_Amp_f32;
  Rte_DE_Float Rte_KeEstimate_VpRadpS_f32;
  Rte_DE_Float Rte_MotorVelocityMRF_MtrRadpS_f32;
  Rte_DE_Boolean Rte_PosServEnable_Cnt_lgc;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_AssistPowerLimit_MtrNm_f32;
  Rte_DE_Float Rte_MtrEnvSpd_MtrRadpS_f32;
} Rte_tsRB_Ap_PwrLmtFunc_PwrLmtFunc_Per1;

typedef struct
{
  Rte_DE_Float Rte_ADCMtrCurr1_Volt_f32;
  Rte_DE_Float Rte_CorrectedMtrPos_Rev_f32;
  Rte_DE_UInt16 Rte_DutyCycleSmall_Cnt_u16;
  Rte_DE_SInt8 Rte_InstantaneousMotorDirection_Cnt_s08;
  Rte_DE_UInt16 Rte_PADelta1_Cnt_u16;
  Rte_DE_Float Rte_MtrCurrDax_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQax_Amp_f32;
  Rte_DE_Float Rte_RawCurrFiltered_Amp_f32;
  Rte_DE_Boolean Rte_ValidSampleFlag_Cnt_lgc;
} Rte_tsRB_Sa_MtrCurr_MtrCurr_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_TMFTestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
} Rte_tsRB_Sa_TmprlMon_TmprlMon_Per2;

typedef struct
{
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_InvCos2Scaled_Volt_f32;
  Rte_DE_Float Rte_InvSin2Scaled_Volt_f32;
  Rte_DE_Float Rte_PDChrgPmpFdbkADC_Volt_f32;
  Rte_DE_Float Rte_PDSuplFdbkADC_Volt_f32;
  Rte_DE_Float Rte_SysCVSwitch_Volt_f32;
  Rte_DE_Float Rte_TemperatureADC_Volt_f32;
} Rte_tsRB_IoHwAb7_IoHwAb7_FdbkPathAdc;

typedef union
{
  Rte_tsRB_IoHwAb7_IoHwAb7_FwdPathAdc Rte_IoHwAb7_IoHwAb7_FwdPathAdc;
  Rte_tsRB_Sa_MtrPos2_MtrPos2_Per1 Rte_Sa_MtrPos2_MtrPos2_Per1;
  Rte_tsRB_Ap_LktoLkStr_LktoLkStr_Per1 Rte_Ap_LktoLkStr_LktoLkStr_Per1;
  Rte_tsRB_Ap_OscTraj_OscTraj_Per1 Rte_Ap_OscTraj_OscTraj_Per1;
  Rte_tsRB_Ap_ParkAstEnbl_ParkAstEnbl_Per1 Rte_Ap_ParkAstEnbl_ParkAstEnbl_Per1;
  Rte_tsRB_Ap_DrvDynEnbl_DrvDynEnbl_Per1 Rte_Ap_DrvDynEnbl_DrvDynEnbl_Per1;
  Rte_tsRB_Ap_PosServo_PosServo_Per1 Rte_Ap_PosServo_PosServo_Per1;
  Rte_tsRB_Sa_HwTrq_HwTrq_Per1 Rte_Sa_HwTrq_HwTrq_Per1;
  Rte_tsRB_Ap_Sweep_Sweep_Per1 Rte_Ap_Sweep_Sweep_Per1;
  Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per1 Rte_Ap_BatteryVoltage_BatteryVoltage_Per1;
  Rte_tsRB_Ap_SignlCondn_SignlCondn_Per1 Rte_Ap_SignlCondn_SignlCondn_Per1;
  Rte_tsRB_Ap_DrvDynCtrl_DrvDynCtrl_Per1 Rte_Ap_DrvDynCtrl_DrvDynCtrl_Per1;
  Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per1 Rte_Sa_CtrlTemp_CtrlTemp_Per1;
  Rte_tsRB_Sa_BkCpPc_BkCpPc_Per1 Rte_Sa_BkCpPc_BkCpPc_Per1;
  Rte_tsRB_Ap_PwrLmtFunc_PwrLmtFunc_Per1 Rte_Ap_PwrLmtFunc_PwrLmtFunc_Per1;
  Rte_tsRB_Sa_MtrCurr_MtrCurr_Per1 Rte_Sa_MtrCurr_MtrCurr_Per1;
  Rte_tsRB_Sa_TmprlMon_TmprlMon_Per2 Rte_Sa_TmprlMon_TmprlMon_Per2;
  Rte_tsRB_IoHwAb7_IoHwAb7_FdbkPathAdc Rte_IoHwAb7_IoHwAb7_FdbkPathAdc;
} Rte_tuRB_Task_2ms_7;

typedef struct
{
  Rte_DE_Float Rte_I_MtrVel_CRFMotorVel_MtrRadpS_f32;
  Rte_DE_Float Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_I_CDDInterface9_PosTrajEnable_Cnt_lgc;
  Rte_DE_Float Rte_I_GenPosTraj_PosTrajHwAngle_HwDeg_f32;
  Rte_DE_Boolean Rte_I_CDDInterface9_OscTrajEnable_Cnt_lgc;
  Rte_DE_Float Rte_I_OscTraj_OscillateHwAngle_HwDeg_f32;
  Rte_DE_Float Rte_I_Sweep_OutputHwTrq_HwNm_f32;
  Rte_DE_Float Rte_I_SignlCondn_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_I_HwTrq_AnaHwTorque_HwNm_f32;
} Rte_tsTB_Task_2ms_7;

typedef struct
{
  Rte_tsTB_Task_2ms_7 Rte_TB;
  Rte_tuRB_Task_2ms_7 Rte_RB;
} Rte_tsTask_2ms_7;

typedef struct
{
  Rte_DE_SInt8 Rte_AsstAssemPol_Cnt_s08;
  Rte_DE_Float Rte_CumMtrPosMRF_Deg_f32;
  Rte_DE_Float Rte_SysCDiagHandWheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_SysCDiagMtrVelMRF_MtrRadpS_f32;
} Rte_tsRB_Sa_MtrVel2_MtrVel2_Per1;

typedef struct
{
  Rte_DE_Float Rte_HwTrqScaleVal_VoltsPerDeg_f32;
  Rte_DE_Float Rte_SysCT1ADC_Volt_f32;
  Rte_DE_Float Rte_SysCT2ADC_Volt_f32;
  Rte_DE_Float Rte_T1TrimVal_Volt_f32;
  Rte_DE_Float Rte_T2TrimVal_Volt_f32;
  Rte_DE_Float Rte_SysCHwTorqueSqd_HwNmSq_f32;
} Rte_tsRB_Sa_HwTrq2_HwTrq2_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_ATerm_Cnt_lgc;
  Rte_DE_Boolean Rte_CTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_ControlledDampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_FTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_RampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
} Rte_tsRB_Ap_StaMd8_StaMd8_Per1;

typedef struct
{
  Rte_DE_Float Rte_InvCos2Scaled_Volt_f32;
  Rte_DE_Float Rte_InvSin2Scaled_Volt_f32;
} Rte_tsRB_Sa_MtrPos3_MtrPos3_Per1;

typedef union
{
  Rte_tsRB_Sa_MtrVel2_MtrVel2_Per1 Rte_Sa_MtrVel2_MtrVel2_Per1;
  Rte_tsRB_Sa_HwTrq2_HwTrq2_Per1 Rte_Sa_HwTrq2_HwTrq2_Per1;
  Rte_tsRB_Ap_StaMd8_StaMd8_Per1 Rte_Ap_StaMd8_StaMd8_Per1;
  Rte_tsRB_Sa_MtrPos3_MtrPos3_Per1 Rte_Sa_MtrPos3_MtrPos3_Per1;
} Rte_tuRB_Task_2ms_8;

typedef struct
{
  Rte_tuRB_Task_2ms_8 Rte_RB;
} Rte_tsTask_2ms_8;

typedef struct
{
  Rte_DE_Float Rte_SysCDiagHandWheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_SysCDiagMtrVelMRF_MtrRadpS_f32;
} Rte_tsRB_Sa_MtrVel_MtrVel_Per2;

typedef union
{
  Rte_tsRB_Sa_MtrVel_MtrVel_Per2 Rte_Sa_MtrVel_MtrVel_Per2;
} Rte_tuRB_Task_4ms_10;

typedef struct
{
  Rte_tuRB_Task_4ms_10 Rte_RB;
} Rte_tsTask_4ms_10;

typedef struct
{
  Rte_DE_Boolean Rte_CntrlDisRampComplete_Cnt_lgc;
  Rte_DE_Float Rte_SysCHwTorqueSqd_HwNmSq_f32;
  Rte_DE_Float Rte_T1ADC_Volt_f32;
  Rte_DE_Float Rte_T2ADC_Volt_f32;
} Rte_tsRB_Sa_HwTrq_HwTrq_Per2;

typedef struct
{
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_SysCVSwitch_Volt_f32;
} Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per2;

typedef union
{
  Rte_tsRB_Sa_HwTrq_HwTrq_Per2 Rte_Sa_HwTrq_HwTrq_Per2;
  Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per2 Rte_Ap_BatteryVoltage_BatteryVoltage_Per2;
} Rte_tuRB_Task_4ms_7;

typedef struct
{
  Rte_tuRB_Task_4ms_7 Rte_RB;
} Rte_tsTask_4ms_7;

typedef struct
{
  Rte_DE_Float Rte_HandWheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_MRFMotorVel_MtrRadpS_f32;
} Rte_tsRB_Sa_MtrVel2_MtrVel2_Per2;

typedef struct
{
  Rte_DE_Float Rte_LrnPnCntrCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_LrnPnCntrEnable_Cnt_lgc;
  Rte_DE_ST_V_VEH_NSS Rte_PASpdHigh_Cnt_u08;
  Rte_DE_Boolean Rte_PosServEnable_Cnt_lgc;
  Rte_DE_Float Rte_PosSrvoSmoothEnable_Uls_f32;
  Rte_DE_Float Rte_PrkAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Boolean Rte_SysCLnPnCtrCCDisable_Cnt_lgc;
  Rte_DE_Boolean Rte_SysCPosServCCDisable_Cnt_lgc;
} Rte_tsRB_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1;

typedef struct
{
  Rte_DE_Float Rte_AnaHwTorque_HwNm_f32;
  Rte_DE_Float Rte_SysCT1ADC_Volt_f32;
  Rte_DE_Float Rte_SysCT2ADC_Volt_f32;
  Rte_DE_Float Rte_T1TrimVal_Volt_f32;
  Rte_DE_Float Rte_T2TrimVal_Volt_f32;
} Rte_tsRB_Sa_HwTrq2_HwTrq2_Per2;

typedef struct
{
  Rte_DE_Float Rte_InvCos2Scaled_Volt_f32;
  Rte_DE_Float Rte_InvSin2Scaled_Volt_f32;
} Rte_tsRB_Sa_MtrPos3_MtrPos3_Per2;

typedef union
{
  Rte_tsRB_Sa_MtrVel2_MtrVel2_Per2 Rte_Sa_MtrVel2_MtrVel2_Per2;
  Rte_tsRB_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1 Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1;
  Rte_tsRB_Sa_HwTrq2_HwTrq2_Per2 Rte_Sa_HwTrq2_HwTrq2_Per2;
  Rte_tsRB_Sa_MtrPos3_MtrPos3_Per2 Rte_Sa_MtrPos3_MtrPos3_Per2;
} Rte_tuRB_Task_4ms_8;

typedef struct
{
  Rte_tuRB_Task_4ms_8 Rte_RB;
} Rte_tsTask_4ms_8;

typedef struct
{
  Rte_DE_Float Rte_AlignedHwPos_HwDeg_f32;
  Rte_DE_Float Rte_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_LrnPnCntrEnable_Cnt_lgc;
  Rte_DE_Float Rte_LrnPnCntrHwCenter_HwDeg_f32;
  Rte_DE_Float Rte_LrnPnCntrHwTravel_HwDeg_f32;
  Rte_DE_LktoLkStrStateType Rte_LrnPnCntrState_Cnt_enum;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Boolean Rte_LTRackCntrComplete_Cnt_lgc;
  Rte_DE_Float Rte_RackCenter_HwDeg_f32;
  Rte_DE_Boolean Rte_RackCntrComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_RackCntrMtrAngleError_Cnt_lgc;
  Rte_DE_Boolean Rte_RackCntrMtrAngleFound_Cnt_lgc;
} Rte_tsRB_Ap_LnRkCr_LnRkCr_Per1;

typedef union
{
  Rte_tsRB_Ap_LnRkCr_LnRkCr_Per1 Rte_Ap_LnRkCr_LnRkCr_Per1;
} Rte_tuRB_Task_4ms_9;

typedef struct
{
  Rte_tuRB_Task_4ms_9 Rte_RB;
} Rte_tsTask_4ms_9;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsDefVehSpd_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxVehSpd;

typedef struct
{
  Rte_DES_RT_VIN_NO_VECH Rte_RxVIN_VIN_NO_VECH;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxVIN;

typedef struct
{
  Rte_DE_Boolean Rte_CFACTORIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CHWANGLEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CHWTORQUEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CMTTORQUEIF_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn;

typedef struct
{
  Rte_DE_Boolean Rte_CHWTORQUEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CMTTORQUEIF_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss;

typedef struct
{
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffset;

typedef struct
{
  Rte_DE_Boolean Rte_CDRVDYNMSG_Cnt_lgc;
  Rte_DE_New_Coding_79 Rte_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel;

typedef struct
{
  Rte_DE_Boolean Rte_CDRVDYNMSG_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_TuningSelLoss;

typedef struct
{
  Rte_DE_Boolean Rte_CHWACORRECTION_Cnt_lgc;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
  Rte_DE_Float Rte_ReturnOffset_HwDeg_f32;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs;

typedef struct
{
  Rte_DE_Boolean Rte_CHWACORRECTION_Cnt_lgc;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss;

typedef struct
{
  Rte_DE_UInt32 Rte_TcActivePN_Cnt_u32;
  Rte_DE_UInt32 Rte_TcActivePNVldCnt_Cnt_u32;
  Rte_DE_Boolean Rte_ActPullCompLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_AvgFrcLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_DampingSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_DftAsstTbl_Cnt_lgc;
  Rte_DE_Boolean Rte_DrivingDynSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_DwnldAsstGain_Uls_f32;
  Rte_DE_Boolean Rte_EOTImpactSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_EOTThermalSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_EngONSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_FirewallSrlComSrvDft_Cnt_lgc;
  Rte_DE_Boolean Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_HysAddSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_HystCompSrlComSvcDft_Cnt_lgc;
  Rte_DE_UInt16 Rte_IgnCnt_Cnt_u16;
  Rte_DE_Boolean Rte_KinIntDiagSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_LimitSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_LrnPnCenterEnable_Cnt_lgc;
  Rte_DE_Boolean Rte_MfgDiagInhibit_Cnt_lgc;
  Rte_DE_Boolean Rte_ModIdxSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MultIgnSrlComSvcDft_Cnt_lgc;
  Rte_DE_ManufModeType Rte_NxtrMEC_Cnt_enum;
  Rte_DE_Boolean Rte_OscTrajEnable_Cnt_lgc;
  Rte_DE_Boolean Rte_ParkAstSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_PosTrajEnable_Cnt_lgc;
  Rte_DE_Boolean Rte_PullCompSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_ReturnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_RxMsgsSrlComSvcDft_Cnt_lgc;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
  Rte_DE_UInt8 Rte_TcFlashErrors_Cnt_u08;
  Rte_DE_Boolean Rte_TcFlashVerify_Cnt_lgc;
  Rte_DE_Boolean Rte_TcReflashActive_Cnt_lgc;
  Rte_DE_Boolean Rte_ThermalDCSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_TrqRmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_WhlImbRejSrlComSvcDft_Cnt_lgc;
} Rte_tsRB_Sa_CDDInterface9_CDDInterface9_Per1;

typedef union
{
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxVehSpd Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVehSpd;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxVIN Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss Rte_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffset Rte_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffset;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel Rte_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_TuningSelLoss Rte_Ap_SrlComInput_SrlComInput_TRGD_TuningSelLoss;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs Rte_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss Rte_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss;
  Rte_tsRB_Sa_CDDInterface9_CDDInterface9_Per1 Rte_Sa_CDDInterface9_CDDInterface9_Per1;
} Rte_tuRB_Task_5ms_9;

typedef struct
{
  Rte_tuRB_Task_5ms_9 Rte_RB;
} Rte_tsTask_5ms_9;

typedef struct
{
  Rte_DE_SInt8 Rte_AssistAssyPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_HwPosPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_HwTrqPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_MtrPosPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_MtrVelPolarity_Cnt_s08;
  Rte_DE_SInt32 Rte_SysC_MtrElecMechPolarity_Cnt_s32;
} Rte_tsRB_Ap_Polarity_Polarity_Init1;

typedef union
{
  Rte_tsRB_Ap_Polarity_Polarity_Init1 Rte_Ap_Polarity_Polarity_Init1;
} Rte_tuRB_Task_InitA_10;

typedef struct
{
  Rte_tuRB_Task_InitA_10 Rte_RB;
} Rte_tsTask_InitA_10;

typedef struct
{
  Rte_DE_UInt16 Rte_DesiredTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunSet_Cnt_u16;
  Rte_DE_UInt16 Rte_ActiveTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_ActiveTunSet_Cnt_u16;
} Rte_tsRB_Ap_TuningSelAuth_TuningSelAuth_Init1;

typedef union
{
  Rte_tsRB_Ap_TuningSelAuth_TuningSelAuth_Init1 Rte_Ap_TuningSelAuth_TuningSelAuth_Init1;
} Rte_tuRB_Task_InitA_7;

typedef struct
{
  Rte_tuRB_Task_InitA_7 Rte_RB;
} Rte_tsTask_InitA_7;

typedef struct
{
  Rte_DE_UInt16 Rte_IgnCnt_Cnt_u16;
  Rte_DE_Boolean Rte_MfgDiagInhibit_Cnt_lgc;
  Rte_DE_ManufModeType Rte_NxtrMEC_Cnt_enum;
} Rte_tsRB_Sa_CDDInterface9_CDDInterface9_Init2;

typedef struct
{
  Rte_DE_UInt16 Rte_DesiredTunPers_Cnt_u16;
  Rte_DE_UInt16 Rte_DesiredTunSet_Cnt_u16;
} Rte_tsRB_Ap_VehCfg_VehCfg_Init1;

typedef union
{
  Rte_tsRB_Sa_CDDInterface9_CDDInterface9_Init2 Rte_Sa_CDDInterface9_CDDInterface9_Init2;
  Rte_tsRB_Ap_VehCfg_VehCfg_Init1 Rte_Ap_VehCfg_VehCfg_Init1;
} Rte_tuRB_Task_InitA_9;

typedef struct
{
  Rte_tuRB_Task_InitA_9 Rte_RB;
} Rte_tsTask_InitA_9;

typedef struct
{
  Rte_DE_Boolean Rte_LTVehCenterComplete_Cnt_lgc;
  Rte_DE_UInt16 Rte_RacktoVehCntrOffset_Cnt_u16;
} Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Init1;

typedef struct
{
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
} Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Init1;

typedef struct
{
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_EstLd_Henry_f32;
  Rte_DE_Float Rte_EstLq_Henry_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
} Rte_tsRB_Ap_ParamComp_ParamComp_Init1;

typedef struct
{
  Rte_DE_Boolean Rte_CCWFound_Cnt_lgc;
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_CWFound_Cnt_lgc;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
} Rte_tsRB_Ap_LrnEOT_LrnEOT_Init1;

typedef union
{
  Rte_tsRB_Ap_AbsHwPos_AbsHwPos_Init1 Rte_Ap_AbsHwPos_AbsHwPos_Init1;
  Rte_tsRB_Sa_CDDInterface10_CDDInterface10_Init1 Rte_Sa_CDDInterface10_CDDInterface10_Init1;
  Rte_tsRB_Ap_ParamComp_ParamComp_Init1 Rte_Ap_ParamComp_ParamComp_Init1;
  Rte_tsRB_Ap_LrnEOT_LrnEOT_Init1 Rte_Ap_LrnEOT_LrnEOT_Init1;
} Rte_tuRB_Task_InitB_10;

typedef struct
{
  Rte_tuRB_Task_InitB_10 Rte_RB;
} Rte_tsTask_InitB_10;

typedef struct
{
  Rte_DE_Float Rte_ADCMtrCurr1_Volt_f32;
  Rte_DE_Float Rte_Batt_Volt_f32;
  Rte_DE_Float Rte_BattSwitched_Volt_f32;
  Rte_DE_Float Rte_InvCos2Scaled_Volt_f32;
  Rte_DE_Float Rte_InvSin2Scaled_Volt_f32;
  Rte_DE_Float Rte_PDChrgPmpFdbkADC_Volt_f32;
  Rte_DE_Float Rte_PDSuplFdbkADC_Volt_f32;
  Rte_DE_Float Rte_SysCT1ADC_Volt_f32;
  Rte_DE_Float Rte_SysCT2ADC_Volt_f32;
  Rte_DE_Float Rte_SysCVSwitch_Volt_f32;
  Rte_DE_Float Rte_T1ADC_Volt_f32;
  Rte_DE_Float Rte_T2ADC_Volt_f32;
} Rte_tsRB_IoHwAb7_IoHwAb7_Init;

typedef struct
{
  Rte_DE_Float Rte_HwTrqScaleVal_VoltsPerDeg_f32;
  Rte_DE_Float Rte_T1TrimVal_Volt_f32;
  Rte_DE_Float Rte_T2TrimVal_Volt_f32;
} Rte_tsRB_Sa_HwTrq_HwTrq_Init;

typedef struct
{
  Rte_DE_EnergyModeStateType Rte_EnergyModeState_Cnt_enum;
  Rte_DE_UInt32 Rte_TcActivePN_Cnt_u32;
  Rte_DE_UInt32 Rte_TcActivePNVldCnt_Cnt_u32;
} Rte_tsRB_Cd_TurnsCounter_TurnsCounter_Init1;

typedef struct
{
  Rte_DE_Float Rte_AmbTemp_DegC_f32;
  Rte_DE_Float Rte_CtrlTempFinal_DegC_f32;
  Rte_DE_Float Rte_EngTemp_DegC_f32;
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
} Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Init1;

typedef struct
{
  Rte_DE_Boolean Rte_CCLMSAActive_Cnt_lgc;
  Rte_DE_Float Rte_CCLTrqRamp_Uls_f32;
} Rte_tsRB_Ap_CustPL_CustPL_Init1;

typedef union
{
  Rte_tsRB_IoHwAb7_IoHwAb7_Init Rte_IoHwAb7_IoHwAb7_Init;
  Rte_tsRB_Sa_HwTrq_HwTrq_Init Rte_Sa_HwTrq_HwTrq_Init;
  Rte_tsRB_Cd_TurnsCounter_TurnsCounter_Init1 Rte_Cd_TurnsCounter_TurnsCounter_Init1;
  Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Init1 Rte_Ap_MtrTempEst_MtrTempEst_Init1;
  Rte_tsRB_Ap_CustPL_CustPL_Init1 Rte_Ap_CustPL_CustPL_Init1;
} Rte_tuRB_Task_InitB_7;

typedef struct
{
  Rte_DE_Float Rte_I_IoHwAb7_TemperatureADC_Volt_f32;
  Rte_DE_Float Rte_I_CtrlTemp_FiltMeasTemp_DegC_f32;
} Rte_tsTB_Task_InitB_7;

typedef struct
{
  Rte_tsTB_Task_InitB_7 Rte_TB;
  Rte_tuRB_Task_InitB_7 Rte_RB;
} Rte_tsTask_InitB_7;

typedef struct
{
  Rte_DE_MSA_Cmd_Type Rte_MSACommand_MSACmd_enum;
  Rte_DE_Float Rte_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_OperRampValue_Uls_f32;
} Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Init1;

typedef struct
{
  Rte_DE_Boolean Rte_DefeatDutySvc_Cnt_lgc;
  Rte_DE_UInt32 Rte_IgnTimeOff_Cnt_u32;
  Rte_DE_Boolean Rte_VehTimeValid_Cnt_lgc;
} Rte_tsRB_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1;

typedef struct
{
  Rte_DE_UInt32 Rte_IgnTimeOff_Cnt_u32;
  Rte_DE_UInt4 Rte_SrlComSTKL_ST_KL;
  Rte_DE_Boolean Rte_VehTimeValid_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_Init;

typedef struct
{
  Rte_DE_Float Rte_AlignedHwPos_HwDeg_f32;
  Rte_DE_Boolean Rte_LTRackCntrComplete_Cnt_lgc;
  Rte_DE_Float Rte_RackCenter_HwDeg_f32;
  Rte_DE_Boolean Rte_RackCntrComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_RackCntrMtrAngleError_Cnt_lgc;
  Rte_DE_Boolean Rte_RackCntrMtrAngleFound_Cnt_lgc;
} Rte_tsRB_Ap_LnRkCr_LnRkCr_Init1;

typedef struct
{
  Rte_DE_Float Rte_FricOffset_HwNm_f32;
} Rte_tsRB_Ap_AvgFricLrn_AvgFricLrn_Init1;

typedef union
{
  Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Init1 Rte_Ap_VehPwrMd_VehPwrMd_Init1;
  Rte_tsRB_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1 Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_Init Rte_Ap_SrlComInput_SrlComInput_Init;
  Rte_tsRB_Ap_LnRkCr_LnRkCr_Init1 Rte_Ap_LnRkCr_LnRkCr_Init1;
  Rte_tsRB_Ap_AvgFricLrn_AvgFricLrn_Init1 Rte_Ap_AvgFricLrn_AvgFricLrn_Init1;
} Rte_tuRB_Task_InitB_9;

typedef struct
{
  Rte_tuRB_Task_InitB_9 Rte_RB;
} Rte_tsTask_InitB_9;

typedef struct
{
  Rte_DE_Float Rte_CumMtrPosMRF_Deg_f32;
} Rte_tsRB_Sa_MtrVel2_MtrVel2_Init;

typedef union
{
  Rte_tsRB_Sa_MtrVel2_MtrVel2_Init Rte_Sa_MtrVel2_MtrVel2_Init;
} Rte_tuRB_Task_Init_8;

typedef struct
{
  Rte_tuRB_Task_Init_8 Rte_RB;
} Rte_tsTask_Init_8;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsDefVehSpd_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput2_SrlComInput2_TRGD_RxVehSpd;

typedef struct
{
  Rte_DE_Boolean Rte_CADASIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CFACTORIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CHWANGLEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CHWTORQUEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CMTTORQUEIF_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn;

typedef struct
{
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
} Rte_tsRB_Ap_SrlComInput2_SrlComInput2_TRGD_RxRevOffset;

typedef struct
{
  Rte_DE_Boolean Rte_CFACTORIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CHWANGLEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CHWTORQUEIF_Cnt_lgc;
  Rte_DE_Boolean Rte_CMTTORQUEIF_Cnt_lgc;
} Rte_tsRB_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate;

typedef union
{
  Rte_tsRB_Ap_SrlComInput2_SrlComInput2_TRGD_RxVehSpd Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxVehSpd;
  Rte_tsRB_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn;
  Rte_tsRB_Ap_SrlComInput2_SrlComInput2_TRGD_RxRevOffset Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxRevOffset;
  Rte_tsRB_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate;
} Rte_tuRB_Task_Trgd_10;

typedef struct
{
  Rte_tuRB_Task_Trgd_10 Rte_RB;
} Rte_tsTask_Trgd_10;

typedef struct
{
  Rte_DE_Boolean Rte_MtrDrvrInitComplete_Cnt_lgc;
} Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Trns1;

typedef union
{
  Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Trns1 Rte_Sa_MtrDrvDiag_MtrDrvDiag_Trns1;
} Rte_tuRB_Task_Trns_11;

typedef struct
{
  Rte_tuRB_Task_Trns_11 Rte_RB;
} Rte_tsTask_Trns_11;

typedef struct
{
  Rte_DE_Boolean Rte_PwrDiscATestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestComplete_Cnt_lgc;
} Rte_tsRB_Sa_BkCpPc_BkCpPc_Trns1;

typedef struct
{
  Rte_DE_Boolean Rte_TMFTestComplete_Cnt_lgc;
} Rte_tsRB_Sa_TmprlMon_TmprlMon_Trns1;

typedef struct
{
  Rte_DE_Boolean Rte_PwrDiscATestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscClosed_Cnt_lgc;
} Rte_tsRB_Sa_BkCpPc_BkCpPc_Trns2;

typedef union
{
  Rte_tsRB_Sa_BkCpPc_BkCpPc_Trns1 Rte_Sa_BkCpPc_BkCpPc_Trns1;
  Rte_tsRB_Sa_TmprlMon_TmprlMon_Trns1 Rte_Sa_TmprlMon_TmprlMon_Trns1;
  Rte_tsRB_Sa_BkCpPc_BkCpPc_Trns2 Rte_Sa_BkCpPc_BkCpPc_Trns2;
} Rte_tuRB_Task_Trns_7;

typedef struct
{
  Rte_tuRB_Task_Trns_7 Rte_RB;
} Rte_tsTask_Trns_7;

typedef struct
{
  Rte_DE_Boolean Rte_MtrDrvrInitStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscATestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_PwrDiscBTestStart_Cnt_lgc;
  Rte_DE_Boolean Rte_TMFTestStart_Cnt_lgc;
} Rte_tsRB_Ap_HwPwUp_HwPwUp_Trns1;

typedef union
{
  Rte_tsRB_Ap_HwPwUp_HwPwUp_Trns1 Rte_Ap_HwPwUp_HwPwUp_Trns1;
} Rte_tuRB_Task_Trns_9;

typedef struct
{
  Rte_tuRB_Task_Trns_9 Rte_RB;
} Rte_tsTask_Trns_9;

# define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"

# ifndef RTE_DISABLE_ISUPDATED

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

typedef unsigned int Rte_BitType;

/*****************************************************************************/
/* extern declaration of RTE Update Flags for optimized macro implementation */
/*****************************************************************************/
typedef struct
{
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComCONVEH_CON_VEH : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComSGVVEH_SG_V_VEH : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComVYAWVEH_VYAW_VEH : 1;
} Rte_Ap_10_RxUpdateFlagsType;

typedef struct
{
  Rte_BitType Rte_RxUpdate_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS_Sender : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_Sender : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComCONVEH_CON_VEH_Sender : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_Sender : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_Sender : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_Sender : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComSGVVEH_SG_V_VEH_Sender : 1;
  Rte_BitType Rte_RxUpdate_SrlComInput2_SrlComVYAWVEH_VYAW_VEH_Sender : 1;
} Rte_Ap_9_RxUpdateFlagsType;

#  define RTE_START_SEC_VAR_Ap_10_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h"

extern VAR(Rte_Ap_10_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_Ap_10_RxUpdateFlags;

#  define RTE_STOP_SEC_VAR_Ap_10_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h"

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h"

extern VAR(Rte_Ap_9_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_Ap_9_RxUpdateFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h"


# endif /* !defined(RTE_DISABLE_ISUPDATED) */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
