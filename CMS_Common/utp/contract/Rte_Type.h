


/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs.
  However, they are not thoroughly tested yet (beta-version).
  With regard to the fact that the programs are a beta-version only,
  Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence,
  to the extent admissible by law or statute.
*/



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
 *     Workspace:  C:/CMSynergy_Projects/K2xx_Int/GM_K2XX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue May  1 15:03:31 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
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

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

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

# define Rte_TypeDef_DTCCodeSupported
typedef boolean DTCCodeSupported;

# define Rte_TypeDef_DTCCurrentStatus
typedef boolean DTCCurrentStatus;

# define Rte_TypeDef_DTCFailType
typedef uint8 DTCFailType;
# define DTCFailType_LowerLimit (0U)
# define DTCFailType_UpperLimit (255U)

# define Rte_TypeDef_DTCFaultType
typedef uint8 DTCFaultType;
# define DTCFaultType_LowerLimit (0U)
# define DTCFaultType_UpperLimit (255U)

# define Rte_TypeDef_DTCHistStat
typedef boolean DTCHistStat;

# define Rte_TypeDef_DTCNumber
typedef uint16 DTCNumber;
# define DTCNumber_LowerLimit (0U)
# define DTCNumber_UpperLimit (65535U)

# define Rte_TypeDef_DTCSource
typedef uint8 DTCSource;
# define DTCSource_LowerLimit (0U)
# define DTCSource_UpperLimit (255U)

# define Rte_TypeDef_DTCTriggered
typedef boolean DTCTriggered;

# define Rte_TypeDef_DTCTstFldCdClrdStat
typedef boolean DTCTstFldCdClrdStat;

# define Rte_TypeDef_DTCTstFldPwrUpSt
typedef boolean DTCTstFldPwrUpSt;

# define Rte_TypeDef_DTCTstNPsdCdClrdSt
typedef boolean DTCTstNPsdCdClrdSt;

# define Rte_TypeDef_DTCTstNPsdPwrUpSt
typedef boolean DTCTstNPsdPwrUpSt;

# define Rte_TypeDef_DTCWrnIndRqdSt
typedef boolean DTCWrnIndRqdSt;

# define Rte_TypeDef_Dem_DTCType
typedef uint32 Dem_DTCType;
# define Dem_DTCType_LowerLimit (1U)
# define Dem_DTCType_UpperLimit (16777215U)

# define Rte_TypeDef_Dem_EventIdType
typedef uint8 Dem_EventIdType;
# define Dem_EventIdType_LowerLimit (0U)
# define Dem_EventIdType_UpperLimit (255U)

# define Rte_TypeDef_Dem_EventStatusExtendedType
typedef uint8 Dem_EventStatusExtendedType;
# define Dem_EventStatusExtendedType_LowerLimit (0U)
# define Dem_EventStatusExtendedType_UpperLimit (255U)

# define Rte_TypeDef_Dem_FaultDetectionCounterType
typedef sint8 Dem_FaultDetectionCounterType;
# define Dem_FaultDetectionCounterType_LowerLimit (-128)
# define Dem_FaultDetectionCounterType_UpperLimit (127)

# define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;
# define Dem_OperationCycleIdType_LowerLimit (0U)
# define Dem_OperationCycleIdType_UpperLimit (255U)

# define Rte_TypeDef_Double
typedef float64 Double;
# define Double_LowerLimit (-DBL_MAX)
# define Double_UpperLimit (DBL_MAX)

# define Rte_TypeDef_DrvMdCntrlState
typedef uint8 DrvMdCntrlState;
# define DrvMdCntrlState_LowerLimit (0U)
# define DrvMdCntrlState_UpperLimit (255U)

# define Rte_TypeDef_DummyRxSignal
typedef uint8 DummyRxSignal;
# define DummyRxSignal_LowerLimit (0U)
# define DummyRxSignal_UpperLimit (1U)

# define Rte_TypeDef_EngRunAtv
typedef boolean EngRunAtv;

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_IoHwAb_BoolType
typedef uint8 IoHwAb_BoolType;
# define IoHwAb_BoolType_LowerLimit (0U)
# define IoHwAb_BoolType_UpperLimit (1U)

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;
# define NvM_BlockIdType_LowerLimit (1U)
# define NvM_BlockIdType_UpperLimit (32767U)

# define Rte_TypeDef_OFFS_GRD_MID_EPS
typedef uint16 OFFS_GRD_MID_EPS;
# define OFFS_GRD_MID_EPS_LowerLimit (0U)
# define OFFS_GRD_MID_EPS_UpperLimit (4095U)

# define Rte_TypeDef_PwrStrIO
typedef boolean PwrStrIO;

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

# define Rte_TypeDef_StWhlAngAliveRollCnt
typedef uint8 StWhlAngAliveRollCnt;
# define StWhlAngAliveRollCnt_LowerLimit (0U)
# define StWhlAngAliveRollCnt_UpperLimit (3U)

# define Rte_TypeDef_StrAngSnsChksm
typedef uint16 StrAngSnsChksm;
# define StrAngSnsChksm_LowerLimit (0U)
# define StrAngSnsChksm_UpperLimit (2047U)

# define Rte_TypeDef_StrWhAng
typedef sint16 StrWhAng;
# define StrWhAng_LowerLimit (-32768)
# define StrWhAng_UpperLimit (32767)

# define Rte_TypeDef_StrWhAngGrd
typedef sint16 StrWhAngGrd;
# define StrWhAngGrd_LowerLimit (-2048)
# define StrWhAngGrd_UpperLimit (2047)

# define Rte_TypeDef_StrWhlAngMsgUnused1
typedef uint8 StrWhlAngMsgUnused1;
# define StrWhlAngMsgUnused1_LowerLimit (0U)
# define StrWhlAngMsgUnused1_UpperLimit (3U)

# define Rte_TypeDef_StrWhlAngMsgUnused2
typedef uint8 StrWhlAngMsgUnused2;
# define StrWhlAngMsgUnused2_LowerLimit (0U)
# define StrWhlAngMsgUnused2_UpperLimit (255U)

# define Rte_TypeDef_StrWhlAngMsgUnused3
typedef uint8 StrWhlAngMsgUnused3;
# define StrWhlAngMsgUnused3_LowerLimit (0U)
# define StrWhlAngMsgUnused3_UpperLimit (31U)

# define Rte_TypeDef_SysBkupPwrMdEn
typedef boolean SysBkupPwrMdEn;

# define Rte_TypeDef_TrnShftPtrnActStat
typedef uint8 TrnShftPtrnActStat;
# define TrnShftPtrnActStat_LowerLimit (0U)
# define TrnShftPtrnActStat_UpperLimit (7U)

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

# define Rte_TypeDef_VehSpdAvgNDrvn
typedef uint16 VehSpdAvgNDrvn;
# define VehSpdAvgNDrvn_LowerLimit (0U)
# define VehSpdAvgNDrvn_UpperLimit (32767U)

# define Rte_TypeDef_WRSSeqNum
typedef uint8 WRSSeqNum;
# define WRSSeqNum_LowerLimit (0U)
# define WRSSeqNum_UpperLimit (3U)

# define Rte_TypeDef_WRSWhlDisTpRC
typedef uint8 WRSWhlDisTpRC;
# define WRSWhlDisTpRC_LowerLimit (0U)
# define WRSWhlDisTpRC_UpperLimit (3U)

# define Rte_TypeDef_WRSWhlDistPCntr
typedef uint16 WRSWhlDistPCntr;
# define WRSWhlDistPCntr_LowerLimit (0U)
# define WRSWhlDistPCntr_UpperLimit (1023U)

# define Rte_TypeDef_WRSWhlDistTstm
typedef uint16 WRSWhlDistTstm;
# define WRSWhlDistTstm_LowerLimit (0U)
# define WRSWhlDistTstm_UpperLimit (65535U)

# define Rte_TypeDef_WRSWhlDistVal
typedef uint8 WRSWhlDistVal;
# define WRSWhlDistVal_LowerLimit (0U)
# define WRSWhlDistVal_UpperLimit (1U)

# define Rte_TypeDef_WRSWhlRotStatRst
typedef uint8 WRSWhlRotStatRst;
# define WRSWhlRotStatRst_LowerLimit (0U)
# define WRSWhlRotStatRst_UpperLimit (1U)

# define Rte_TypeDef_WhlPlsPerRevNonDrvn
typedef uint8 WhlPlsPerRevNonDrvn;
# define WhlPlsPerRevNonDrvn_LowerLimit (0U)
# define WhlPlsPerRevNonDrvn_UpperLimit (127U)

# define Rte_TypeDef_WhlRotStatTmstmpRes
typedef uint16 WhlRotStatTmstmpRes;
# define WhlRotStatTmstmpRes_LowerLimit (0U)
# define WhlRotStatTmstmpRes_UpperLimit (2048U)

# define Rte_TypeDef_BkupPwrModeMstrVDA
typedef uint8 BkupPwrModeMstrVDA;
# define BkupPwrModeMstrVDA_LowerLimit (0U)
# define BkupPwrModeMstrVDA_UpperLimit (1U)
# if (defined RTE_CONST_VirtualDeviceUnavailable) || (defined VirtualDeviceUnavailable)
#  if (!defined RTE_CONST_VirtualDeviceUnavailable) || (RTE_CONST_VirtualDeviceUnavailable != 0U)
#   error "Enumeration constant <VirtualDeviceUnavailable> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_VirtualDeviceUnavailable (0U)
#  define VirtualDeviceUnavailable (0U)
# endif
# if (defined RTE_CONST_VirtualDeviceAvailable) || (defined VirtualDeviceAvailable)
#  if (!defined RTE_CONST_VirtualDeviceAvailable) || (RTE_CONST_VirtualDeviceAvailable != 1U)
#   error "Enumeration constant <VirtualDeviceAvailable> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_VirtualDeviceAvailable (1U)
#  define VirtualDeviceAvailable (1U)
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

# define Rte_TypeDef_EngCltTmpV
typedef uint8 EngCltTmpV;
# define EngCltTmpV_LowerLimit (0U)
# define EngCltTmpV_UpperLimit (1U)
# if (defined RTE_CONST_EngCltTmp_Valid) || (defined EngCltTmp_Valid)
#  if (!defined RTE_CONST_EngCltTmp_Valid) || (RTE_CONST_EngCltTmp_Valid != 0U)
#   error "Enumeration constant <EngCltTmp_Valid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EngCltTmp_Valid (0U)
#  define EngCltTmp_Valid (0U)
# endif
# if (defined RTE_CONST_EngCltTmp_Invalid) || (defined EngCltTmp_Invalid)
#  if (!defined RTE_CONST_EngCltTmp_Invalid) || (RTE_CONST_EngCltTmp_Invalid != 1U)
#   error "Enumeration constant <EngCltTmp_Invalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_EngCltTmp_Invalid (1U)
#  define EngCltTmp_Invalid (1U)
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
# if (defined RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt) || (defined NTC_Num_RAMDiag_ADCRamFlt)
#  if (!defined RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt) || (RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt != 26U)
#   error "Enumeration constant <NTC_Num_RAMDiag_ADCRamFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_RAMDiag_ADCRamFlt (26U)
#  define NTC_Num_RAMDiag_ADCRamFlt (26U)
# endif
# if (defined RTE_CONST_NTC_Num_DCANRAMFault) || (defined NTC_Num_DCANRAMFault)
#  if (!defined RTE_CONST_NTC_Num_DCANRAMFault) || (RTE_CONST_NTC_Num_DCANRAMFault != 27U)
#   error "Enumeration constant <NTC_Num_DCANRAMFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_DCANRAMFault (27U)
#  define NTC_Num_DCANRAMFault (27U)
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
# if (defined RTE_CONST_NTC_Num_TurnCntr_PosLoss) || (defined NTC_Num_TurnCntr_PosLoss)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_PosLoss) || (RTE_CONST_NTC_Num_TurnCntr_PosLoss != 128U)
#   error "Enumeration constant <NTC_Num_TurnCntr_PosLoss> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_PosLoss (128U)
#  define NTC_Num_TurnCntr_PosLoss (128U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnCntr_NonPosLoss) || (defined NTC_Num_TurnCntr_NonPosLoss)
#  if (!defined RTE_CONST_NTC_Num_TurnCntr_NonPosLoss) || (RTE_CONST_NTC_Num_TurnCntr_NonPosLoss != 129U)
#   error "Enumeration constant <NTC_Num_TurnCntr_NonPosLoss> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnCntr_NonPosLoss (129U)
#  define NTC_Num_TurnCntr_NonPosLoss (129U)
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
# if (defined RTE_CONST_NTC_Num_LatchActive) || (defined NTC_Num_LatchActive)
#  if (!defined RTE_CONST_NTC_Num_LatchActive) || (RTE_CONST_NTC_Num_LatchActive != 160U)
#   error "Enumeration constant <NTC_Num_LatchActive> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_LatchActive (160U)
#  define NTC_Num_LatchActive (160U)
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
# if (defined RTE_CONST_NTC_Num_IgnConfDiag) || (defined NTC_Num_IgnConfDiag)
#  if (!defined RTE_CONST_NTC_Num_IgnConfDiag) || (RTE_CONST_NTC_Num_IgnConfDiag != 184U)
#   error "Enumeration constant <NTC_Num_IgnConfDiag> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_IgnConfDiag (184U)
#  define NTC_Num_IgnConfDiag (184U)
# endif
# if (defined RTE_CONST_NTC_Num_TurnsCntrLowBattFault) || (defined NTC_Num_TurnsCntrLowBattFault)
#  if (!defined RTE_CONST_NTC_Num_TurnsCntrLowBattFault) || (RTE_CONST_NTC_Num_TurnsCntrLowBattFault != 185U)
#   error "Enumeration constant <NTC_Num_TurnsCntrLowBattFault> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_TurnsCntrLowBattFault (185U)
#  define NTC_Num_TurnsCntrLowBattFault (185U)
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
# if (defined RTE_CONST_NTC_Num_WhlImbAlgFlt) || (defined NTC_Num_WhlImbAlgFlt)
#  if (!defined RTE_CONST_NTC_Num_WhlImbAlgFlt) || (RTE_CONST_NTC_Num_WhlImbAlgFlt != 224U)
#   error "Enumeration constant <NTC_Num_WhlImbAlgFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_WhlImbAlgFlt (224U)
#  define NTC_Num_WhlImbAlgFlt (224U)
# endif
# if (defined RTE_CONST_NTC_Num_PAHwVelFlt) || (defined NTC_Num_PAHwVelFlt)
#  if (!defined RTE_CONST_NTC_Num_PAHwVelFlt) || (RTE_CONST_NTC_Num_PAHwVelFlt != 225U)
#   error "Enumeration constant <NTC_Num_PAHwVelFlt> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_PAHwVelFlt (225U)
#  define NTC_Num_PAHwVelFlt (225U)
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
# if (defined RTE_CONST_NTC_Num_SysConsistencyVerf) || (defined NTC_Num_SysConsistencyVerf)
#  if (!defined RTE_CONST_NTC_Num_SysConsistencyVerf) || (RTE_CONST_NTC_Num_SysConsistencyVerf != 496U)
#   error "Enumeration constant <NTC_Num_SysConsistencyVerf> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NTC_Num_SysConsistencyVerf (496U)
#  define NTC_Num_SysConsistencyVerf (496U)
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

# define Rte_TypeDef_OtsAirTmpCrValV
typedef uint8 OtsAirTmpCrValV;
# define OtsAirTmpCrValV_LowerLimit (0U)
# define OtsAirTmpCrValV_UpperLimit (1U)
# if (defined RTE_CONST_OtsAirTmpCrVal_Valid) || (defined OtsAirTmpCrVal_Valid)
#  if (!defined RTE_CONST_OtsAirTmpCrVal_Valid) || (RTE_CONST_OtsAirTmpCrVal_Valid != 0U)
#   error "Enumeration constant <OtsAirTmpCrVal_Valid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_OtsAirTmpCrVal_Valid (0U)
#  define OtsAirTmpCrVal_Valid (0U)
# endif
# if (defined RTE_CONST_OtsAirTmpCrVal_Invalid) || (defined OtsAirTmpCrVal_Invalid)
#  if (!defined RTE_CONST_OtsAirTmpCrVal_Invalid) || (RTE_CONST_OtsAirTmpCrVal_Invalid != 1U)
#   error "Enumeration constant <OtsAirTmpCrVal_Invalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_OtsAirTmpCrVal_Invalid (1U)
#  define OtsAirTmpCrVal_Invalid (1U)
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

# define Rte_TypeDef_StrWhAngGrdMsk
typedef uint8 StrWhAngGrdMsk;
# define StrWhAngGrdMsk_LowerLimit (0U)
# define StrWhAngGrdMsk_UpperLimit (1U)
# if (defined RTE_CONST_StrWhAngGrd_DontUseData) || (defined StrWhAngGrd_DontUseData)
#  if (!defined RTE_CONST_StrWhAngGrd_DontUseData) || (RTE_CONST_StrWhAngGrd_DontUseData != 0U)
#   error "Enumeration constant <StrWhAngGrd_DontUseData> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_StrWhAngGrd_DontUseData (0U)
#  define StrWhAngGrd_DontUseData (0U)
# endif
# if (defined RTE_CONST_StrWhAngGrd_UseData) || (defined StrWhAngGrd_UseData)
#  if (!defined RTE_CONST_StrWhAngGrd_UseData) || (RTE_CONST_StrWhAngGrd_UseData != 1U)
#   error "Enumeration constant <StrWhAngGrd_UseData> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_StrWhAngGrd_UseData (1U)
#  define StrWhAngGrd_UseData (1U)
# endif

# define Rte_TypeDef_StrWhAngGrdV
typedef uint8 StrWhAngGrdV;
# define StrWhAngGrdV_LowerLimit (0U)
# define StrWhAngGrdV_UpperLimit (1U)
# if (defined RTE_CONST_StrWhAngGrd_Valid) || (defined StrWhAngGrd_Valid)
#  if (!defined RTE_CONST_StrWhAngGrd_Valid) || (RTE_CONST_StrWhAngGrd_Valid != 0U)
#   error "Enumeration constant <StrWhAngGrd_Valid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_StrWhAngGrd_Valid (0U)
#  define StrWhAngGrd_Valid (0U)
# endif
# if (defined RTE_CONST_StrWhAngGrd_Invalid) || (defined StrWhAngGrd_Invalid)
#  if (!defined RTE_CONST_StrWhAngGrd_Invalid) || (RTE_CONST_StrWhAngGrd_Invalid != 1U)
#   error "Enumeration constant <StrWhAngGrd_Invalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_StrWhAngGrd_Invalid (1U)
#  define StrWhAngGrd_Invalid (1U)
# endif

# define Rte_TypeDef_StrWhAngMsk
typedef uint8 StrWhAngMsk;
# define StrWhAngMsk_LowerLimit (0U)
# define StrWhAngMsk_UpperLimit (1U)
# if (defined RTE_CONST_StrWhAng_DontUseData) || (defined StrWhAng_DontUseData)
#  if (!defined RTE_CONST_StrWhAng_DontUseData) || (RTE_CONST_StrWhAng_DontUseData != 0U)
#   error "Enumeration constant <StrWhAng_DontUseData> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_StrWhAng_DontUseData (0U)
#  define StrWhAng_DontUseData (0U)
# endif
# if (defined RTE_CONST_StrWhAng_UseData) || (defined StrWhAng_UseData)
#  if (!defined RTE_CONST_StrWhAng_UseData) || (RTE_CONST_StrWhAng_UseData != 1U)
#   error "Enumeration constant <StrWhAng_UseData> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_StrWhAng_UseData (1U)
#  define StrWhAng_UseData (1U)
# endif

# define Rte_TypeDef_StrWhAngV
typedef uint8 StrWhAngV;
# define StrWhAngV_LowerLimit (0U)
# define StrWhAngV_UpperLimit (1U)
# if (defined RTE_CONST_StrWhAng_Valid) || (defined StrWhAng_Valid)
#  if (!defined RTE_CONST_StrWhAng_Valid) || (RTE_CONST_StrWhAng_Valid != 0U)
#   error "Enumeration constant <StrWhAng_Valid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_StrWhAng_Valid (0U)
#  define StrWhAng_Valid (0U)
# endif
# if (defined RTE_CONST_StrWhAng_Invalid) || (defined StrWhAng_Invalid)
#  if (!defined RTE_CONST_StrWhAng_Invalid) || (RTE_CONST_StrWhAng_Invalid != 1U)
#   error "Enumeration constant <StrWhAng_Invalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_StrWhAng_Invalid (1U)
#  define StrWhAng_Invalid (1U)
# endif

# define Rte_TypeDef_StrWhlAngSenCalStat
typedef uint8 StrWhlAngSenCalStat;
# define StrWhlAngSenCalStat_LowerLimit (0U)
# define StrWhlAngSenCalStat_UpperLimit (3U)
# if (defined RTE_CONST_CalStatus_Unknown) || (defined CalStatus_Unknown)
#  if (!defined RTE_CONST_CalStatus_Unknown) || (RTE_CONST_CalStatus_Unknown != 0U)
#   error "Enumeration constant <CalStatus_Unknown> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CalStatus_Unknown (0U)
#  define CalStatus_Unknown (0U)
# endif
# if (defined RTE_CONST_CalStatus_Estimated) || (defined CalStatus_Estimated)
#  if (!defined RTE_CONST_CalStatus_Estimated) || (RTE_CONST_CalStatus_Estimated != 1U)
#   error "Enumeration constant <CalStatus_Estimated> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CalStatus_Estimated (1U)
#  define CalStatus_Estimated (1U)
# endif
# if (defined RTE_CONST_CalStatus_Calibrated) || (defined CalStatus_Calibrated)
#  if (!defined RTE_CONST_CalStatus_Calibrated) || (RTE_CONST_CalStatus_Calibrated != 2U)
#   error "Enumeration constant <CalStatus_Calibrated> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CalStatus_Calibrated (2U)
#  define CalStatus_Calibrated (2U)
# endif

# define Rte_TypeDef_StrWhlAngSenTyp
typedef uint8 StrWhlAngSenTyp;
# define StrWhlAngSenTyp_LowerLimit (0U)
# define StrWhlAngSenTyp_UpperLimit (3U)
# if (defined RTE_CONST_SenTyp_Type1) || (defined SenTyp_Type1)
#  if (!defined RTE_CONST_SenTyp_Type1) || (RTE_CONST_SenTyp_Type1 != 0U)
#   error "Enumeration constant <SenTyp_Type1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SenTyp_Type1 (0U)
#  define SenTyp_Type1 (0U)
# endif
# if (defined RTE_CONST_SenTyp_Type2) || (defined SenTyp_Type2)
#  if (!defined RTE_CONST_SenTyp_Type2) || (RTE_CONST_SenTyp_Type2 != 1U)
#   error "Enumeration constant <SenTyp_Type2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SenTyp_Type2 (1U)
#  define SenTyp_Type2 (1U)
# endif
# if (defined RTE_CONST_SenTyp_Type3) || (defined SenTyp_Type3)
#  if (!defined RTE_CONST_SenTyp_Type3) || (RTE_CONST_SenTyp_Type3 != 2U)
#   error "Enumeration constant <SenTyp_Type3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SenTyp_Type3 (2U)
#  define SenTyp_Type3 (2U)
# endif
# if (defined RTE_CONST_SenTyp_Type4) || (defined SenTyp_Type4)
#  if (!defined RTE_CONST_SenTyp_Type4) || (RTE_CONST_SenTyp_Type4 != 3U)
#   error "Enumeration constant <SenTyp_Type4> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_SenTyp_Type4 (3U)
#  define SenTyp_Type4 (3U)
# endif

# define Rte_TypeDef_SysPwrMd
typedef uint8 SysPwrMd;
# define SysPwrMd_LowerLimit (0U)
# define SysPwrMd_UpperLimit (3U)
# if (defined RTE_CONST_Off) || (defined Off)
#  if (!defined RTE_CONST_Off) || (RTE_CONST_Off != 0U)
#   error "Enumeration constant <Off> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Off (0U)
#  define Off (0U)
# endif
# if (defined RTE_CONST_Accessory) || (defined Accessory)
#  if (!defined RTE_CONST_Accessory) || (RTE_CONST_Accessory != 1U)
#   error "Enumeration constant <Accessory> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Accessory (1U)
#  define Accessory (1U)
# endif
# if (defined RTE_CONST_Run) || (defined Run)
#  if (!defined RTE_CONST_Run) || (RTE_CONST_Run != 2U)
#   error "Enumeration constant <Run> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Run (2U)
#  define Run (2U)
# endif
# if (defined RTE_CONST_CrankRequest) || (defined CrankRequest)
#  if (!defined RTE_CONST_CrankRequest) || (RTE_CONST_CrankRequest != 3U)
#   error "Enumeration constant <CrankRequest> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CrankRequest (3U)
#  define CrankRequest (3U)
# endif

# define Rte_TypeDef_VSELatAccV
typedef uint8 VSELatAccV;
# define VSELatAccV_LowerLimit (0U)
# define VSELatAccV_UpperLimit (1U)
# if (defined RTE_CONST_VSELatAcc_Valid) || (defined VSELatAcc_Valid)
#  if (!defined RTE_CONST_VSELatAcc_Valid) || (RTE_CONST_VSELatAcc_Valid != 0U)
#   error "Enumeration constant <VSELatAcc_Valid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_VSELatAcc_Valid (0U)
#  define VSELatAcc_Valid (0U)
# endif
# if (defined RTE_CONST_VSELatAcc_Invalid) || (defined VSELatAcc_Invalid)
#  if (!defined RTE_CONST_VSELatAcc_Invalid) || (RTE_CONST_VSELatAcc_Invalid != 1U)
#   error "Enumeration constant <VSELatAcc_Invalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_VSELatAcc_Invalid (1U)
#  define VSELatAcc_Invalid (1U)
# endif

# define Rte_TypeDef_VehDynYawRateV
typedef uint8 VehDynYawRateV;
# define VehDynYawRateV_LowerLimit (0U)
# define VehDynYawRateV_UpperLimit (1U)
# if (defined RTE_CONST_VehDynYawRate_Valid) || (defined VehDynYawRate_Valid)
#  if (!defined RTE_CONST_VehDynYawRate_Valid) || (RTE_CONST_VehDynYawRate_Valid != 0U)
#   error "Enumeration constant <VehDynYawRate_Valid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_VehDynYawRate_Valid (0U)
#  define VehDynYawRate_Valid (0U)
# endif
# if (defined RTE_CONST_VehDynYawRate_Invalid) || (defined VehDynYawRate_Invalid)
#  if (!defined RTE_CONST_VehDynYawRate_Invalid) || (RTE_CONST_VehDynYawRate_Invalid != 1U)
#   error "Enumeration constant <VehDynYawRate_Invalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_VehDynYawRate_Invalid (1U)
#  define VehDynYawRate_Invalid (1U)
# endif

# define Rte_TypeDef_VehSpdAvgNDrvnV
typedef uint8 VehSpdAvgNDrvnV;
# define VehSpdAvgNDrvnV_LowerLimit (0U)
# define VehSpdAvgNDrvnV_UpperLimit (1U)
# if (defined RTE_CONST_VehSpd_Valid) || (defined VehSpd_Valid)
#  if (!defined RTE_CONST_VehSpd_Valid) || (RTE_CONST_VehSpd_Valid != 0U)
#   error "Enumeration constant <VehSpd_Valid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_VehSpd_Valid (0U)
#  define VehSpd_Valid (0U)
# endif
# if (defined RTE_CONST_VehSpd_Invalid) || (defined VehSpd_Invalid)
#  if (!defined RTE_CONST_VehSpd_Invalid) || (RTE_CONST_VehSpd_Invalid != 1U)
#   error "Enumeration constant <VehSpd_Invalid> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_VehSpd_Invalid (1U)
#  define VehSpd_Invalid (1U)
# endif

# define Rte_TypeDef_DT_Array144_s8
typedef SInt8 DT_Array144_s8[144];

# define Rte_TypeDef_DT_SinTanLkpTbl_f32
typedef Float DT_SinTanLkpTbl_f32[193];

# define Rte_TypeDef_NvM_DestPtr
typedef UInt8 NvM_DestPtr[65535];

# define Rte_TypeDef_TypeHRamBufferType
typedef UInt8 TypeHRamBufferType[100];

# define Rte_TypeDef_EOLNomMtrParamType
typedef struct
{
  Float NomKe_VpRadpS_f32;
  Float NomL_Henry_f32;
  Float NomRmtr_Ohm_f32;
} EOLNomMtrParamType;

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

# define Rte_TypeDef_MtrSnsrLearned_DataType
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

# define Rte_TypeDef_NTCStrg
typedef struct
{
  NTCNumber NTC;
  UInt8 Status;
} NTCStrg;

# define Rte_TypeDef_RT_Chassis_General_Status_1
typedef struct
{
  UInt16 VSELatAcc;
  UInt16 VehDynYawRate;
  VSELatAccV VSELatAccV;
  VehDynYawRateV VehDynYawRateV;
} RT_Chassis_General_Status_1;

# define Rte_TypeDef_RT_DTC_Triggered_778
typedef struct
{
  DTCTriggered DTCTriggered;
  DTCSource DTCSource;
  DTCNumber DTCNumber;
  DTCFailType DTCFailType;
  DTCWrnIndRqdSt DTCWrnIndRqdSt;
  DTCTstFldPwrUpSt DTCTstFldPwrUpSt;
  DTCTstNPsdPwrUpSt DTCTstNPsdPwrupSt;
  DTCHistStat DTCHistStat;
  DTCTstFldCdClrdStat DTCTstFldCdClrdStat;
  DTCTstNPsdCdClrdSt DTCTstNPsdCdClrdSt;
  DTCCurrentStatus DTCCurrentStatus;
  DTCCodeSupported DTCCodeSupported;
  DTCFaultType DTCFaulttype;
} RT_DTC_Triggered_778;

# define Rte_TypeDef_RT_Driving_Mode_Control_HS
typedef struct
{
  DrvMdCntrlState DrvMdCntrlState;
} RT_Driving_Mode_Control_HS;

# define Rte_TypeDef_RT_Engine_General_Status_1
typedef struct
{
  EngRunAtv EngRunAtv;
} RT_Engine_General_Status_1;

# define Rte_TypeDef_RT_Engine_General_Status_4
typedef struct
{
  UInt8 EngCltTmp;
  EngCltTmpV EngCltTmpV;
} RT_Engine_General_Status_4;

# define Rte_TypeDef_RT_PPEI_Platform_General_Status
typedef struct
{
  SysPwrMd SysPwrMd;
  SysBkupPwrMdEn SysBkupPwrMdEn;
  SysPwrMd SysBkUpPwrMd;
  BkupPwrModeMstrVDA BkupPwrModeMstrVDA;
} RT_PPEI_Platform_General_Status;

# define Rte_TypeDef_RT_PPEI_Steering_Wheel_Angle_CE
typedef struct
{
  StrAngSnsChksm StrAngSnsChksm;
  StrWhAng StrWhAng;
  StWhlAngAliveRollCnt StWhlAngAliveRollCnt;
  StrWhAngGrd StrWhAngGrd;
  StrWhAngGrdMsk StrWhAngGrdMsk;
  StrWhAngGrdV StrWhAngGrdV;
  StrWhAngMsk StrWhAngMsk;
  StrWhlAngSenCalStat StrWhlAngSenCalStat;
  StrWhlAngSenTyp StrWhlAngSenTyp;
  StrWhAngV StrWhAngV;
  StrWhlAngMsgUnused1 StrWhlAngMsgUnused1;
  StrWhlAngMsgUnused2 StrWhlAngMsgUnused2;
  StrWhlAngMsgUnused3 StrWhlAngMsgUnused3;
} RT_PPEI_Steering_Wheel_Angle_CE;

# define Rte_TypeDef_RT_Platform_Eng_Cntrl_Requests
typedef struct
{
  UInt8 OtsAirTmpCrVal;
  OtsAirTmpCrValV OtsAirTmpCrValV;
} RT_Platform_Eng_Cntrl_Requests;

# define Rte_TypeDef_RT_Power_Steering_Information_HS
typedef struct
{
  PwrStrIO PwrStrIO;
} RT_Power_Steering_Information_HS;

# define Rte_TypeDef_RT_Trans_General_Status_2
typedef struct
{
  TrnShftPtrnActStat TrnShftPtrnActStat;
} RT_Trans_General_Status_2;

# define Rte_TypeDef_RT_VehSpdAvgNonDrvnGroup
typedef struct
{
  VehSpdAvgNDrvn VehSpdAvgNDrvn;
  VehSpdAvgNDrvnV VehSpdAvgNDrvnV;
} RT_VehSpdAvgNonDrvnGroup;

# define Rte_TypeDef_RT_Wheel_Pulses_HS
typedef struct
{
  WhlRotStatTmstmpRes WhlRotStatTmstmpRes;
  WhlPlsPerRevNonDrvn WhlPlsPerRevNonDrvn;
} RT_Wheel_Pulses_HS;

# define Rte_TypeDef_ShCurrCal_DataType
typedef struct
{
  Float EOLShcurrOffset_Volts_f32;
  Float EOLShcurrGain_Uls_f32;
} ShCurrCal_DataType;

# define Rte_TypeDef_WhlRotStat
typedef struct
{
  WRSSeqNum WRSSeqNum;
  WRSWhlDistPCntr WRSWhlDistPCntr;
  WRSWhlDisTpRC WRSWhlDisTpRC;
  WRSWhlDistTstm WRSWhlDistTstm;
  WRSWhlDistVal WRSWhlDistVal;
  WRSWhlRotStatRst WRSWhlRotStatRst;
} WhlRotStat;

# define Rte_TypeDef_MtrPosCal_DataType
typedef struct
{
  UInt16 R_BEMFCal_Rev_u0p16;
  UInt16 Sin1Offset_Volts_u3p13;
  UInt16 Sin1AmpRec_Uls_u3p13;
  UInt16 Cos1Offset_Volts_u3p13;
  UInt16 Cos1AmpRec_Uls_u3p13;
  SInt16 SinDelta1_Uls_s2p13;
  UInt16 CosDelta1Rec_Uls_u3p13;
  UInt16 Sin2Offset_Volts_u3p13;
  UInt16 Sin2AmpRec_Uls_u3p13;
  UInt16 Cos2Offset_Volts_u3p13;
  UInt16 Cos2AmpRec_Uls_u3p13;
  SInt16 SinDelta2_Uls_s2p13;
  UInt16 CosDelta2Rec_Uls_u3p13;
  SInt16 Sin1OffCorr_Volts_s2p13;
  UInt16 Sin1GainCorr_Uls_u1p15;
  SInt16 Cos1OffCorr_Volts_s2p13;
  UInt16 Cos1GainCorr_Uls_u1p15;
  DT_Array144_s8 SinHarTbl_Cnt_sm6p13;
  DT_Array144_s8 CosHarTbl_Cnt_sm6p13;
} MtrPosCal_DataType;

# define Rte_TypeDef_NTCStrgArray
typedef NTCStrg NTCStrgArray[15];

# define Rte_TypeDef_RT_PPEI_NonDrivn_Whl_Rotationl_Stat
typedef struct
{
  WhlRotStat WhlRotStatLft;
  WhlRotStat WhlRotStatRght;
} RT_PPEI_NonDrivn_Whl_Rotationl_Stat;

# define Rte_TypeDef_RT_PPEI_Vehicle_Speed_and_Distance
typedef struct
{
  RT_VehSpdAvgNonDrvnGroup RT_VehSpdAvgNonDrvnGroup;
} RT_PPEI_Vehicle_Speed_and_Distance;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_DistRollCntAvgDrvnSrc
typedef uint8 DistRollCntAvgDrvnSrc;
#  define DistRollCntAvgDrvnSrc_LowerLimit (0U)
#  define DistRollCntAvgDrvnSrc_UpperLimit (1U)

#  define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;
#  define EcuM_UserType_LowerLimit (0U)
#  define EcuM_UserType_UpperLimit (255U)

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

#  define Rte_TypeDef_SInt4
typedef sint8 SInt4;
#  define SInt4_LowerLimit (-8)
#  define SInt4_UpperLimit (7)

#  define Rte_TypeDef_TrStLgMdAtv
typedef uint8 TrStLgMdAtv;
#  define TrStLgMdAtv_LowerLimit (0U)
#  define TrStLgMdAtv_UpperLimit (1U)

#  define Rte_TypeDef_UInt4
typedef uint8 UInt4;
#  define UInt4_LowerLimit (0U)
#  define UInt4_UpperLimit (15U)

#  define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;
#  define WdgM_CheckpointIdType_LowerLimit (0U)
#  define WdgM_CheckpointIdType_UpperLimit (65535U)

#  define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;
#  define WdgM_ModeType_LowerLimit (0U)
#  define WdgM_ModeType_UpperLimit (255U)

#  define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;
#  define WdgM_SupervisedEntityIdType_LowerLimit (0U)
#  define WdgM_SupervisedEntityIdType_UpperLimit (65535U)

#  define Rte_TypeDef_CrossCheckOpModeType
typedef uint8 CrossCheckOpModeType;
#  define CrossCheckOpModeType_LowerLimit (0U)
#  define CrossCheckOpModeType_UpperLimit (2U)
#  if (defined RTE_CONST_LimitMode) || (defined LimitMode)
#   if (!defined RTE_CONST_LimitMode) || (RTE_CONST_LimitMode != 0U)
#    error "Enumeration constant <LimitMode> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_LimitMode (0U)
#   define LimitMode (0U)
#  endif
#  if (defined RTE_CONST_TimedLimitMode) || (defined TimedLimitMode)
#   if (!defined RTE_CONST_TimedLimitMode) || (RTE_CONST_TimedLimitMode != 1U)
#    error "Enumeration constant <TimedLimitMode> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TimedLimitMode (1U)
#   define TimedLimitMode (1U)
#  endif
#  if (defined RTE_CONST_DiagnosticMode) || (defined DiagnosticMode)
#   if (!defined RTE_CONST_DiagnosticMode) || (RTE_CONST_DiagnosticMode != 2U)
#    error "Enumeration constant <DiagnosticMode> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DiagnosticMode (2U)
#   define DiagnosticMode (2U)
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

#  define Rte_TypeDef_Dem_ReturnGetDTCOfEventType
typedef uint8 Dem_ReturnGetDTCOfEventType;
#  define Dem_ReturnGetDTCOfEventType_LowerLimit (0U)
#  define Dem_ReturnGetDTCOfEventType_UpperLimit (2U)
#  if (defined RTE_CONST_DEM_GET_DTCOFEVENT_OK) || (defined DEM_GET_DTCOFEVENT_OK)
#   if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_OK) || (RTE_CONST_DEM_GET_DTCOFEVENT_OK != 0U)
#    error "Enumeration constant <DEM_GET_DTCOFEVENT_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_GET_DTCOFEVENT_OK (0U)
#   define DEM_GET_DTCOFEVENT_OK (0U)
#  endif
#  if (defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID) || (defined DEM_GET_DTCOFEVENT_WRONG_EVENTID)
#   if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID) || (RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID != 1U)
#    error "Enumeration constant <DEM_GET_DTCOFEVENT_WRONG_EVENTID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_EVENTID (1U)
#   define DEM_GET_DTCOFEVENT_WRONG_EVENTID (1U)
#  endif
#  if (defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND) || (defined DEM_GET_DTCOFEVENT_WRONG_DTCKIND)
#   if (!defined RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND) || (RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND != 2U)
#    error "Enumeration constant <DEM_GET_DTCOFEVENT_WRONG_DTCKIND> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DEM_GET_DTCOFEVENT_WRONG_DTCKIND (2U)
#   define DEM_GET_DTCOFEVENT_WRONG_DTCKIND (2U)
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

#  define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;
#  define EcuM_StateType_LowerLimit (16U)
#  define EcuM_StateType_UpperLimit (255U)
#  if (defined RTE_CONST_ECUM_STATE_STARTUP) || (defined ECUM_STATE_STARTUP)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP) || (RTE_CONST_ECUM_STATE_STARTUP != 16U)
#    error "Enumeration constant <ECUM_STATE_STARTUP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP (16U)
#   define ECUM_STATE_STARTUP (16U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (defined ECUM_STATE_STARTUP_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (RTE_CONST_ECUM_STATE_STARTUP_ONE != 17U)
#    error "Enumeration constant <ECUM_STATE_STARTUP_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP_ONE (17U)
#   define ECUM_STATE_STARTUP_ONE (17U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (defined ECUM_STATE_STARTUP_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (RTE_CONST_ECUM_STATE_STARTUP_TWO != 18U)
#    error "Enumeration constant <ECUM_STATE_STARTUP_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_STARTUP_TWO (18U)
#   define ECUM_STATE_STARTUP_TWO (18U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP) || (defined ECUM_STATE_WAKEUP)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP) || (RTE_CONST_ECUM_STATE_WAKEUP != 32U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP (32U)
#   define ECUM_STATE_WAKEUP (32U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (defined ECUM_STATE_WAKEUP_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (RTE_CONST_ECUM_STATE_WAKEUP_ONE != 33U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_ONE (33U)
#   define ECUM_STATE_WAKEUP_ONE (33U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (defined ECUM_STATE_WAKEUP_VALIDATION)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION != 34U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_VALIDATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION (34U)
#   define ECUM_STATE_WAKEUP_VALIDATION (34U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (defined ECUM_STATE_WAKEUP_REACTION)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (RTE_CONST_ECUM_STATE_WAKEUP_REACTION != 35U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_REACTION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_REACTION (35U)
#   define ECUM_STATE_WAKEUP_REACTION (35U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (defined ECUM_STATE_WAKEUP_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (RTE_CONST_ECUM_STATE_WAKEUP_TWO != 36U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_TWO (36U)
#   define ECUM_STATE_WAKEUP_TWO (36U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (defined ECUM_STATE_WAKEUP_WAKESLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP != 37U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_WAKESLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#   define ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (defined ECUM_STATE_WAKEUP_TTII)
#   if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (RTE_CONST_ECUM_STATE_WAKEUP_TTII != 38U)
#    error "Enumeration constant <ECUM_STATE_WAKEUP_TTII> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_WAKEUP_TTII (38U)
#   define ECUM_STATE_WAKEUP_TTII (38U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_RUN) || (defined ECUM_STATE_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_RUN) || (RTE_CONST_ECUM_STATE_RUN != 48U)
#    error "Enumeration constant <ECUM_STATE_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_RUN (48U)
#   define ECUM_STATE_RUN (48U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_APP_RUN) || (defined ECUM_STATE_APP_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_APP_RUN) || (RTE_CONST_ECUM_STATE_APP_RUN != 50U)
#    error "Enumeration constant <ECUM_STATE_APP_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_APP_RUN (50U)
#   define ECUM_STATE_APP_RUN (50U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (defined ECUM_STATE_APP_POST_RUN)
#   if (!defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (RTE_CONST_ECUM_STATE_APP_POST_RUN != 51U)
#    error "Enumeration constant <ECUM_STATE_APP_POST_RUN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_APP_POST_RUN (51U)
#   define ECUM_STATE_APP_POST_RUN (51U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (defined ECUM_STATE_SHUTDOWN)
#   if (!defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (RTE_CONST_ECUM_STATE_SHUTDOWN != 64U)
#    error "Enumeration constant <ECUM_STATE_SHUTDOWN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_SHUTDOWN (64U)
#   define ECUM_STATE_SHUTDOWN (64U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (defined ECUM_STATE_PREP_SHUTDOWN)
#   if (!defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (RTE_CONST_ECUM_STATE_PREP_SHUTDOWN != 68U)
#    error "Enumeration constant <ECUM_STATE_PREP_SHUTDOWN> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_PREP_SHUTDOWN (68U)
#   define ECUM_STATE_PREP_SHUTDOWN (68U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (defined ECUM_STATE_GO_SLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (RTE_CONST_ECUM_STATE_GO_SLEEP != 73U)
#    error "Enumeration constant <ECUM_STATE_GO_SLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_SLEEP (73U)
#   define ECUM_STATE_GO_SLEEP (73U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (defined ECUM_STATE_GO_OFF_ONE)
#   if (!defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (RTE_CONST_ECUM_STATE_GO_OFF_ONE != 77U)
#    error "Enumeration constant <ECUM_STATE_GO_OFF_ONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_OFF_ONE (77U)
#   define ECUM_STATE_GO_OFF_ONE (77U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (defined ECUM_STATE_GO_OFF_TWO)
#   if (!defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (RTE_CONST_ECUM_STATE_GO_OFF_TWO != 78U)
#    error "Enumeration constant <ECUM_STATE_GO_OFF_TWO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_GO_OFF_TWO (78U)
#   define ECUM_STATE_GO_OFF_TWO (78U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_SLEEP) || (defined ECUM_STATE_SLEEP)
#   if (!defined RTE_CONST_ECUM_STATE_SLEEP) || (RTE_CONST_ECUM_STATE_SLEEP != 80U)
#    error "Enumeration constant <ECUM_STATE_SLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_SLEEP (80U)
#   define ECUM_STATE_SLEEP (80U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_OFF) || (defined ECUM_STATE_OFF)
#   if (!defined RTE_CONST_ECUM_STATE_OFF) || (RTE_CONST_ECUM_STATE_OFF != 128U)
#    error "Enumeration constant <ECUM_STATE_OFF> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_OFF (128U)
#   define ECUM_STATE_OFF (128U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_RESET) || (defined ECUM_STATE_RESET)
#   if (!defined RTE_CONST_ECUM_STATE_RESET) || (RTE_CONST_ECUM_STATE_RESET != 144U)
#    error "Enumeration constant <ECUM_STATE_RESET> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_RESET (144U)
#   define ECUM_STATE_RESET (144U)
#  endif
#  if (defined RTE_CONST_ECUM_STATE_ERROR) || (defined ECUM_STATE_ERROR)
#   if (!defined RTE_CONST_ECUM_STATE_ERROR) || (RTE_CONST_ECUM_STATE_ERROR != 255U)
#    error "Enumeration constant <ECUM_STATE_ERROR> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_ECUM_STATE_ERROR (255U)
#   define ECUM_STATE_ERROR (255U)
#  endif

#  define Rte_TypeDef_EnergyModeStateType
typedef uint8 EnergyModeStateType;
#  define EnergyModeStateType_LowerLimit (0U)
#  define EnergyModeStateType_UpperLimit (3U)
#  if (defined RTE_CONST_NORMAL) || (defined NORMAL)
#   if (!defined RTE_CONST_NORMAL) || (RTE_CONST_NORMAL != 0U)
#    error "Enumeration constant <NORMAL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NORMAL (0U)
#   define NORMAL (0U)
#  endif
#  if (defined RTE_CONST_PRODUCTION) || (defined PRODUCTION)
#   if (!defined RTE_CONST_PRODUCTION) || (RTE_CONST_PRODUCTION != 1U)
#    error "Enumeration constant <PRODUCTION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_PRODUCTION (1U)
#   define PRODUCTION (1U)
#  endif
#  if (defined RTE_CONST_TRANSPORTATION) || (defined TRANSPORTATION)
#   if (!defined RTE_CONST_TRANSPORTATION) || (RTE_CONST_TRANSPORTATION != 2U)
#    error "Enumeration constant <TRANSPORTATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TRANSPORTATION (2U)
#   define TRANSPORTATION (2U)
#  endif
#  if (defined RTE_CONST_FLASH) || (defined FLASH)
#   if (!defined RTE_CONST_FLASH) || (RTE_CONST_FLASH != 3U)
#    error "Enumeration constant <FLASH> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_FLASH (3U)
#   define FLASH (3U)
#  endif

#  define Rte_TypeDef_LktoLkStrStateType
typedef uint8 LktoLkStrStateType;
#  define LktoLkStrStateType_LowerLimit (0U)
#  define LktoLkStrStateType_UpperLimit (7U)
#  if (defined RTE_CONST_HOLD) || (defined HOLD)
#   if (!defined RTE_CONST_HOLD) || (RTE_CONST_HOLD != 0U)
#    error "Enumeration constant <HOLD> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_HOLD (0U)
#   define HOLD (0U)
#  endif
#  if (defined RTE_CONST_POSANGVEL) || (defined POSANGVEL)
#   if (!defined RTE_CONST_POSANGVEL) || (RTE_CONST_POSANGVEL != 1U)
#    error "Enumeration constant <POSANGVEL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_POSANGVEL (1U)
#   define POSANGVEL (1U)
#  endif
#  if (defined RTE_CONST_POSMTRTRQ) || (defined POSMTRTRQ)
#   if (!defined RTE_CONST_POSMTRTRQ) || (RTE_CONST_POSMTRTRQ != 2U)
#    error "Enumeration constant <POSMTRTRQ> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_POSMTRTRQ (2U)
#   define POSMTRTRQ (2U)
#  endif
#  if (defined RTE_CONST_NEGANGVEL) || (defined NEGANGVEL)
#   if (!defined RTE_CONST_NEGANGVEL) || (RTE_CONST_NEGANGVEL != 3U)
#    error "Enumeration constant <NEGANGVEL> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NEGANGVEL (3U)
#   define NEGANGVEL (3U)
#  endif
#  if (defined RTE_CONST_NEGMTRTRQ) || (defined NEGMTRTRQ)
#   if (!defined RTE_CONST_NEGMTRTRQ) || (RTE_CONST_NEGMTRTRQ != 4U)
#    error "Enumeration constant <NEGMTRTRQ> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NEGMTRTRQ (4U)
#   define NEGMTRTRQ (4U)
#  endif
#  if (defined RTE_CONST_MOVETO) || (defined MOVETO)
#   if (!defined RTE_CONST_MOVETO) || (RTE_CONST_MOVETO != 5U)
#    error "Enumeration constant <MOVETO> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_MOVETO (5U)
#   define MOVETO (5U)
#  endif
#  if (defined RTE_CONST_DONE) || (defined DONE)
#   if (!defined RTE_CONST_DONE) || (RTE_CONST_DONE != 6U)
#    error "Enumeration constant <DONE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_DONE (6U)
#   define DONE (6U)
#  endif
#  if (defined RTE_CONST_TIMEOUT) || (defined TIMEOUT)
#   if (!defined RTE_CONST_TIMEOUT) || (RTE_CONST_TIMEOUT != 7U)
#    error "Enumeration constant <TIMEOUT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_TIMEOUT (7U)
#   define TIMEOUT (7U)
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

#  define Rte_TypeDef_OscTrajCmdStateType
typedef uint8 OscTrajCmdStateType;
#  define OscTrajCmdStateType_LowerLimit (0U)
#  define OscTrajCmdStateType_UpperLimit (2U)
#  if (defined RTE_CONST_CMD_STATE0) || (defined CMD_STATE0)
#   if (!defined RTE_CONST_CMD_STATE0) || (RTE_CONST_CMD_STATE0 != 0U)
#    error "Enumeration constant <CMD_STATE0> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CMD_STATE0 (0U)
#   define CMD_STATE0 (0U)
#  endif
#  if (defined RTE_CONST_CMD_STATE1) || (defined CMD_STATE1)
#   if (!defined RTE_CONST_CMD_STATE1) || (RTE_CONST_CMD_STATE1 != 1U)
#    error "Enumeration constant <CMD_STATE1> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CMD_STATE1 (1U)
#   define CMD_STATE1 (1U)
#  endif
#  if (defined RTE_CONST_CMD_STATE2) || (defined CMD_STATE2)
#   if (!defined RTE_CONST_CMD_STATE2) || (RTE_CONST_CMD_STATE2 != 2U)
#    error "Enumeration constant <CMD_STATE2> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_CMD_STATE2 (2U)
#   define CMD_STATE2 (2U)
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

#  define Rte_TypeDef_ST_OFFS_QUAD_EPS
typedef uint8 ST_OFFS_QUAD_EPS;
#  define ST_OFFS_QUAD_EPS_LowerLimit (0U)
#  define ST_OFFS_QUAD_EPS_UpperLimit (15U)
#  if (defined RTE_CONST_STOFFSQUADEPS_SLEEP) || (defined STOFFSQUADEPS_SLEEP)
#   if (!defined RTE_CONST_STOFFSQUADEPS_SLEEP) || (RTE_CONST_STOFFSQUADEPS_SLEEP != 0U)
#    error "Enumeration constant <STOFFSQUADEPS_SLEEP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_SLEEP (0U)
#   define STOFFSQUADEPS_SLEEP (0U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_CALCULATED) || (defined STOFFSQUADEPS_CALCULATED)
#   if (!defined RTE_CONST_STOFFSQUADEPS_CALCULATED) || (RTE_CONST_STOFFSQUADEPS_CALCULATED != 1U)
#    error "Enumeration constant <STOFFSQUADEPS_CALCULATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_CALCULATED (1U)
#   define STOFFSQUADEPS_CALCULATED (1U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_INDEX) || (defined STOFFSQUADEPS_INDEX)
#   if (!defined RTE_CONST_STOFFSQUADEPS_INDEX) || (RTE_CONST_STOFFSQUADEPS_INDEX != 2U)
#    error "Enumeration constant <STOFFSQUADEPS_INDEX> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_INDEX (2U)
#   define STOFFSQUADEPS_INDEX (2U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_MODELCOMP) || (defined STOFFSQUADEPS_MODELCOMP)
#   if (!defined RTE_CONST_STOFFSQUADEPS_MODELCOMP) || (RTE_CONST_STOFFSQUADEPS_MODELCOMP != 3U)
#    error "Enumeration constant <STOFFSQUADEPS_MODELCOMP> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_MODELCOMP (3U)
#   define STOFFSQUADEPS_MODELCOMP (3U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK) || (defined STOFFSQUADEPS_LOCKTOLOCK)
#   if (!defined RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK) || (RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK != 4U)
#    error "Enumeration constant <STOFFSQUADEPS_LOCKTOLOCK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_LOCKTOLOCK (4U)
#   define STOFFSQUADEPS_LOCKTOLOCK (4U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE) || (defined STOFFSQUADEPS_SUMSTEERINGANGLE)
#   if (!defined RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE) || (RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE != 5U)
#    error "Enumeration constant <STOFFSQUADEPS_SUMSTEERINGANGLE> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_SUMSTEERINGANGLE (5U)
#   define STOFFSQUADEPS_SUMSTEERINGANGLE (5U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_CHECK) || (defined STOFFSQUADEPS_CHECK)
#   if (!defined RTE_CONST_STOFFSQUADEPS_CHECK) || (RTE_CONST_STOFFSQUADEPS_CHECK != 6U)
#    error "Enumeration constant <STOFFSQUADEPS_CHECK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_CHECK (6U)
#   define STOFFSQUADEPS_CHECK (6U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_CORRECTION) || (defined STOFFSQUADEPS_CORRECTION)
#   if (!defined RTE_CONST_STOFFSQUADEPS_CORRECTION) || (RTE_CONST_STOFFSQUADEPS_CORRECTION != 7U)
#    error "Enumeration constant <STOFFSQUADEPS_CORRECTION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_CORRECTION (7U)
#   define STOFFSQUADEPS_CORRECTION (7U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_INITIALIZATION) || (defined STOFFSQUADEPS_INITIALIZATION)
#   if (!defined RTE_CONST_STOFFSQUADEPS_INITIALIZATION) || (RTE_CONST_STOFFSQUADEPS_INITIALIZATION != 8U)
#    error "Enumeration constant <STOFFSQUADEPS_INITIALIZATION> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_INITIALIZATION (8U)
#   define STOFFSQUADEPS_INITIALIZATION (8U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_DETERMINED) || (defined STOFFSQUADEPS_DETERMINED)
#   if (!defined RTE_CONST_STOFFSQUADEPS_DETERMINED) || (RTE_CONST_STOFFSQUADEPS_DETERMINED != 9U)
#    error "Enumeration constant <STOFFSQUADEPS_DETERMINED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_DETERMINED (9U)
#   define STOFFSQUADEPS_DETERMINED (9U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_APPROXIMATED) || (defined STOFFSQUADEPS_APPROXIMATED)
#   if (!defined RTE_CONST_STOFFSQUADEPS_APPROXIMATED) || (RTE_CONST_STOFFSQUADEPS_APPROXIMATED != 11U)
#    error "Enumeration constant <STOFFSQUADEPS_APPROXIMATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_APPROXIMATED (11U)
#   define STOFFSQUADEPS_APPROXIMATED (11U)
#  endif
#  if (defined RTE_CONST_STOFFSQUADEPS_INVALID) || (defined STOFFSQUADEPS_INVALID)
#   if (!defined RTE_CONST_STOFFSQUADEPS_INVALID) || (RTE_CONST_STOFFSQUADEPS_INVALID != 15U)
#    error "Enumeration constant <STOFFSQUADEPS_INVALID> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_STOFFSQUADEPS_INVALID (15U)
#   define STOFFSQUADEPS_INVALID (15U)
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

#  define Rte_TypeDef_TurnsCntrValStateType
typedef uint8 TurnsCntrValStateType;
#  define TurnsCntrValStateType_LowerLimit (0U)
#  define TurnsCntrValStateType_UpperLimit (255U)
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

#  define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;
#  define WdgM_GlobalStatusType_LowerLimit (0U)
#  define WdgM_GlobalStatusType_UpperLimit (255U)
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_OK) || (defined WDGM_GLOBAL_STATUS_OK)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_OK) || (RTE_CONST_WDGM_GLOBAL_STATUS_OK != 0U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_OK (0U)
#   define WDGM_GLOBAL_STATUS_OK (0U)
#  endif
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_FAILED) || (defined WDGM_GLOBAL_STATUS_FAILED)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_FAILED) || (RTE_CONST_WDGM_GLOBAL_STATUS_FAILED != 1U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_FAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_FAILED (1U)
#   define WDGM_GLOBAL_STATUS_FAILED (1U)
#  endif
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED) || (defined WDGM_GLOBAL_STATUS_EXPIRED)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED) || (RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED != 2U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_EXPIRED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_EXPIRED (2U)
#   define WDGM_GLOBAL_STATUS_EXPIRED (2U)
#  endif
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED) || (defined WDGM_GLOBAL_STATUS_STOPPED)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED) || (RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED != 3U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_STOPPED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_STOPPED (3U)
#   define WDGM_GLOBAL_STATUS_STOPPED (3U)
#  endif
#  if (defined RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED) || (defined WDGM_GLOBAL_STATUS_DEACTIVATED)
#   if (!defined RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED) || (RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED != 4U)
#    error "Enumeration constant <WDGM_GLOBAL_STATUS_DEACTIVATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#   define WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#  endif

#  define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;
#  define WdgM_LocalStatusType_LowerLimit (0U)
#  define WdgM_LocalStatusType_UpperLimit (255U)
#  if (defined RTE_CONST_WDGM_LOCAL_STATUS_OK) || (defined WDGM_LOCAL_STATUS_OK)
#   if (!defined RTE_CONST_WDGM_LOCAL_STATUS_OK) || (RTE_CONST_WDGM_LOCAL_STATUS_OK != 0U)
#    error "Enumeration constant <WDGM_LOCAL_STATUS_OK> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_LOCAL_STATUS_OK (0U)
#   define WDGM_LOCAL_STATUS_OK (0U)
#  endif
#  if (defined RTE_CONST_WDGM_LOCAL_STATUS_FAILED) || (defined WDGM_LOCAL_STATUS_FAILED)
#   if (!defined RTE_CONST_WDGM_LOCAL_STATUS_FAILED) || (RTE_CONST_WDGM_LOCAL_STATUS_FAILED != 1U)
#    error "Enumeration constant <WDGM_LOCAL_STATUS_FAILED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_LOCAL_STATUS_FAILED (1U)
#   define WDGM_LOCAL_STATUS_FAILED (1U)
#  endif
#  if (defined RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED) || (defined WDGM_LOCAL_STATUS_EXPIRED)
#   if (!defined RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED) || (RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED != 2U)
#    error "Enumeration constant <WDGM_LOCAL_STATUS_EXPIRED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_LOCAL_STATUS_EXPIRED (2U)
#   define WDGM_LOCAL_STATUS_EXPIRED (2U)
#  endif
#  if (defined RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED) || (defined WDGM_LOCAL_STATUS_DEACTIVATED)
#   if (!defined RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED) || (RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED != 4U)
#    error "Enumeration constant <WDGM_LOCAL_STATUS_DEACTIVATED> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#   define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  endif

#  define Rte_TypeDef_DT_Array2_u16
typedef UInt16 DT_Array2_u16[2];

#  define Rte_TypeDef_DT_Array3_u32
typedef UInt32 DT_Array3_u32[3];

#  define Rte_TypeDef_DiagSettings_Str
typedef struct
{
  UInt16 Threshold;
  UInt16 PStep;
  UInt16 NStep;
} DiagSettings_Str;

#  define Rte_TypeDef_MtrParamCal_DataType
typedef struct
{
  Float EOLNomKe_VpRadpS_f32;
  Float EOLNomL_Henry_f32;
  Float EOLNomRmtr_Ohm_f32;
} MtrParamCal_DataType;

#  define Rte_TypeDef_RT_RampCmd
typedef struct
{
  Float target_X_f32;
  Float rate_XpmS_f32;
} RT_RampCmd;

# endif


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/


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

# if (defined RTE_CONST_D_RACKCNTRUNLEARNED_CNT_U16) || (defined D_RACKCNTRUNLEARNED_CNT_U16)
#  if (!defined RTE_CONST_D_RACKCNTRUNLEARNED_CNT_U16) || (RTE_CONST_D_RACKCNTRUNLEARNED_CNT_U16 != 4095U)
#   error "Constant value <D_RACKCNTRUNLEARNED_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKCNTRUNLEARNED_CNT_U16 (4095U)
#  define D_RACKCNTRUNLEARNED_CNT_U16 (4095U)
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

# if (defined RTE_CONST_D_DELTAROLLASST_MTRNM_U5P11) || (defined D_DELTAROLLASST_MTRNM_U5P11)
#  if (!defined RTE_CONST_D_DELTAROLLASST_MTRNM_U5P11) || (RTE_CONST_D_DELTAROLLASST_MTRNM_U5P11 != 512U)
#   error "Constant value <D_DELTAROLLASST_MTRNM_U5P11> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_DELTAROLLASST_MTRNM_U5P11 (512U)
#  define D_DELTAROLLASST_MTRNM_U5P11 (512U)
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

# if (defined RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16) || (defined D_RACKTOVEHCNTRINVALID_CNT_U16)
#  if (!defined RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16) || (RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16 != 4095U)
#   error "Constant value <D_RACKTOVEHCNTRINVALID_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKTOVEHCNTRINVALID_CNT_U16 (4095U)
#  define D_RACKTOVEHCNTRINVALID_CNT_U16 (4095U)
# endif

# if (defined RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16) || (defined D_RACKTOVEHCNTRUNLEARNED_CNT_U16)
#  if (!defined RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16) || (RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16 != 4094U)
#   error "Constant value <D_RACKTOVEHCNTRUNLEARNED_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RACKTOVEHCNTRUNLEARNED_CNT_U16 (4094U)
#  define D_RACKTOVEHCNTRUNLEARNED_CNT_U16 (4094U)
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

# if (defined RTE_CONST_D_SVCDFTKININTDIAG_CNT_B32) || (defined D_SVCDFTKININTDIAG_CNT_B32)
#  if (!defined RTE_CONST_D_SVCDFTKININTDIAG_CNT_B32) || (RTE_CONST_D_SVCDFTKININTDIAG_CNT_B32 != 4U)
#   error "Constant value <D_SVCDFTKININTDIAG_CNT_B32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SVCDFTKININTDIAG_CNT_B32 (4U)
#  define D_SVCDFTKININTDIAG_CNT_B32 (4U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0U)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0U)
#  define D_ZERO_CNT_U32 (0U)
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

# if (defined RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08) || (defined D_TURNSCNTRPARTNUMINIT_CNT_U08)
#  if (!defined RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08) || (RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08 != 255U)
#   error "Constant value <D_TURNSCNTRPARTNUMINIT_CNT_U08> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TURNSCNTRPARTNUMINIT_CNT_U08 (255U)
#  define D_TURNSCNTRPARTNUMINIT_CNT_U08 (255U)
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

# if defined Init_Chassis_General_Status_1
#  error "Constant value <Init_Chassis_General_Status_1> conflicts with an already defined symbol."
# else
#  define Init_Chassis_General_Status_1 (Rte_Init_Chassis_General_Status_1)
# endif
extern CONST(RT_Chassis_General_Status_1, RTE_CONST) Rte_Init_Chassis_General_Status_1;

# if defined Init_DTC_Triggered_778
#  error "Constant value <Init_DTC_Triggered_778> conflicts with an already defined symbol."
# else
#  define Init_DTC_Triggered_778 (Rte_Init_DTC_Triggered_778)
# endif
extern CONST(RT_DTC_Triggered_778, RTE_CONST) Rte_Init_DTC_Triggered_778;

# if defined Init_Driving_Mode_Control_HS
#  error "Constant value <Init_Driving_Mode_Control_HS> conflicts with an already defined symbol."
# else
#  define Init_Driving_Mode_Control_HS (Rte_Init_Driving_Mode_Control_HS)
# endif
extern CONST(RT_Driving_Mode_Control_HS, RTE_CONST) Rte_Init_Driving_Mode_Control_HS;

# if defined Init_Engine_General_Status_1
#  error "Constant value <Init_Engine_General_Status_1> conflicts with an already defined symbol."
# else
#  define Init_Engine_General_Status_1 (Rte_Init_Engine_General_Status_1)
# endif
extern CONST(RT_Engine_General_Status_1, RTE_CONST) Rte_Init_Engine_General_Status_1;

# if defined Init_Engine_General_Status_4
#  error "Constant value <Init_Engine_General_Status_4> conflicts with an already defined symbol."
# else
#  define Init_Engine_General_Status_4 (Rte_Init_Engine_General_Status_4)
# endif
extern CONST(RT_Engine_General_Status_4, RTE_CONST) Rte_Init_Engine_General_Status_4;

# if defined Init_PPEI_NonDrivn_Whl_Rotationl_Stat
#  error "Constant value <Init_PPEI_NonDrivn_Whl_Rotationl_Stat> conflicts with an already defined symbol."
# else
#  define Init_PPEI_NonDrivn_Whl_Rotationl_Stat (Rte_Init_PPEI_NonDrivn_Whl_Rotationl_Stat)
# endif
extern CONST(RT_PPEI_NonDrivn_Whl_Rotationl_Stat, RTE_CONST) Rte_Init_PPEI_NonDrivn_Whl_Rotationl_Stat;

# if defined Init_PPEI_Platform_General_Status
#  error "Constant value <Init_PPEI_Platform_General_Status> conflicts with an already defined symbol."
# else
#  define Init_PPEI_Platform_General_Status (Rte_Init_PPEI_Platform_General_Status)
# endif
extern CONST(RT_PPEI_Platform_General_Status, RTE_CONST) Rte_Init_PPEI_Platform_General_Status;

# if defined Init_PPEI_Steering_Wheel_Angle_CE
#  error "Constant value <Init_PPEI_Steering_Wheel_Angle_CE> conflicts with an already defined symbol."
# else
#  define Init_PPEI_Steering_Wheel_Angle_CE (Rte_Init_PPEI_Steering_Wheel_Angle_CE)
# endif
extern CONST(RT_PPEI_Steering_Wheel_Angle_CE, RTE_CONST) Rte_Init_PPEI_Steering_Wheel_Angle_CE;

# if defined Init_PPEI_Vehicle_Speed_and_Distance
#  error "Constant value <Init_PPEI_Vehicle_Speed_and_Distance> conflicts with an already defined symbol."
# else
#  define Init_PPEI_Vehicle_Speed_and_Distance (Rte_Init_PPEI_Vehicle_Speed_and_Distance)
# endif
extern CONST(RT_PPEI_Vehicle_Speed_and_Distance, RTE_CONST) Rte_Init_PPEI_Vehicle_Speed_and_Distance;

# if defined Init_Platform_Eng_Cntrl_Requests
#  error "Constant value <Init_Platform_Eng_Cntrl_Requests> conflicts with an already defined symbol."
# else
#  define Init_Platform_Eng_Cntrl_Requests (Rte_Init_Platform_Eng_Cntrl_Requests)
# endif
extern CONST(RT_Platform_Eng_Cntrl_Requests, RTE_CONST) Rte_Init_Platform_Eng_Cntrl_Requests;

# if defined Init_Power_Steering_Information_HS
#  error "Constant value <Init_Power_Steering_Information_HS> conflicts with an already defined symbol."
# else
#  define Init_Power_Steering_Information_HS (Rte_Init_Power_Steering_Information_HS)
# endif
extern CONST(RT_Power_Steering_Information_HS, RTE_CONST) Rte_Init_Power_Steering_Information_HS;

# if defined Init_Trans_General_Status_2
#  error "Constant value <Init_Trans_General_Status_2> conflicts with an already defined symbol."
# else
#  define Init_Trans_General_Status_2 (Rte_Init_Trans_General_Status_2)
# endif
extern CONST(RT_Trans_General_Status_2, RTE_CONST) Rte_Init_Trans_General_Status_2;

# if defined Init_Wheel_Pulses_HS
#  error "Constant value <Init_Wheel_Pulses_HS> conflicts with an already defined symbol."
# else
#  define Init_Wheel_Pulses_HS (Rte_Init_Wheel_Pulses_HS)
# endif
extern CONST(RT_Wheel_Pulses_HS, RTE_CONST) Rte_Init_Wheel_Pulses_HS;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;


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
  SInt8 value;
} Rte_DE_SInt8;

typedef struct
{
  ManufModeType value;
} Rte_DE_ManufModeType;

typedef struct
{
  UInt16 value;
} Rte_DE_UInt16;

typedef struct
{
  UInt32 value;
} Rte_DE_UInt32;

typedef struct
{
  SInt16 value;
} Rte_DE_SInt16;

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
  RT_DTC_Triggered_778 value;
} Rte_DE_RT_DTC_Triggered_778;

typedef struct
{
  RT_Power_Steering_Information_HS value;
} Rte_DE_RT_Power_Steering_Information_HS;


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

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#  include "MemMap.h"

extern VAR(Float, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Return_EOLReturnRange;
extern VAR(Float, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_TrqCmdScl_TorqueCmdSF_Uls_f32;
extern VAR(UInt16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Polarity_k_SystemPolarity_Cnt_b16;
extern VAR(UInt16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_SrlComInput_SrlComWIRFltStatus_Cnt_u16;
extern VAR(Boolean, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_LrnEOT_RackCntrPerf;
extern VAR(NTCStrgArray, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagMgr_NTCStrgArray;
extern VAR(TypeHRamBufferType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_StaMd_TypeHRamBuffer;
extern VAR(HwTrqScale_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DigHwTrq_DigTrqScale;
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DigHwTrq_DigTrqTrim;
extern VAR(HwTrqScale_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_HwTrq_HwTrqScaleData;
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_HwTrq_HwTrqTrimData;
extern VAR(EOTLearned_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_LrnEOT_LearnedEOT;
extern VAR(ShCurrCal_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_MtrCurr_ShCurrCal;
extern VAR(MtrPosCal_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_MtrPos_MtrPosSnsr_EOLData;
extern VAR(MtrSnsrLearned_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_MtrPosSnsrLearning_MtrSnsrLearnedParam;
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
  Rte_DE_Float Rte_PowerLimitPerc_Uls_f32;
  Rte_DE_Float Rte_ThermalLimitPerc_Uls_f32;
  Rte_DE_Float Rte_LimitPercFilt_Uls_f32;
} Rte_tsRB_Ap_AssistSumnLmt_AssistSumnLmt_Per2;

typedef struct
{
  Rte_DE_Boolean Rte_KinIntDiagSrlComSvcDft_Cnt_lgc;
} Rte_tsRB_Ap_AbsHwPosScom_AbsHwPosScom_Per2;

typedef union
{
  Rte_tsRB_Ap_AssistSumnLmt_AssistSumnLmt_Per2 Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per2;
  Rte_tsRB_Ap_AbsHwPosScom_AbsHwPosScom_Per2 Rte_Ap_AbsHwPosScom_AbsHwPosScom_Per2;
} Rte_tuRB_Task_10ms;

typedef struct
{
  Rte_tuRB_Task_10ms Rte_RB;
} Rte_tsTask_10ms;

typedef struct
{
  Rte_DE_Float Rte_FiltEstPkCurr_AmpSq_f32;
} Rte_tsRB_Ap_CurrentEst_CurrentEst_Per2;

typedef struct
{
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
} Rte_tsRB_Ap_ParamComp_ParamComp_Per2;

typedef struct
{
  Rte_DE_Float Rte_AmbTemp_DegC_f32;
  Rte_DE_Float Rte_CtrlTempFinal_DegC_f32;
  Rte_DE_Float Rte_EngTemp_DegC_f32;
  Rte_DE_Float Rte_EstPkCurr_AmpSq_f32;
  Rte_DE_Float Rte_HwVel_HwRadpS_f32;
  Rte_DE_Boolean Rte_ScomTempDataRcvd_Cnt_lgc;
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_CuTempEst_DegC_f32;
  Rte_DE_Float Rte_MagTempEst_DegC_f32;
  Rte_DE_Float Rte_SiTempEst_DegC_f32;
} Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Per1;

typedef struct
{
  Rte_DE_Float Rte_FiltEstPkCurr_AmpSq_f32;
} Rte_tsRB_Ap_DutyCycle_DutyCycle_Per2;

typedef struct
{
  Rte_DE_Float Rte_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_CtrlTempFinal_DegC_f32;
  Rte_DE_Float Rte_EstPkCurr_AmpSq_f32;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
  Rte_DE_Float Rte_ThermalAssistScl_Uls_f32;
  Rte_DE_Float Rte_ThermalLimit_MtrNm_f32;
} Rte_tsRB_Ap_DutyCycle_DutyCycle_Per1;

typedef struct
{
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per3;

typedef union
{
  Rte_tsRB_Ap_CurrentEst_CurrentEst_Per2 Rte_Ap_CurrentEst_CurrentEst_Per2;
  Rte_tsRB_Ap_ParamComp_ParamComp_Per2 Rte_Ap_ParamComp_ParamComp_Per2;
  Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Per1 Rte_Ap_MtrTempEst_MtrTempEst_Per1;
  Rte_tsRB_Ap_DutyCycle_DutyCycle_Per2 Rte_Ap_DutyCycle_DutyCycle_Per2;
  Rte_tsRB_Ap_DutyCycle_DutyCycle_Per1 Rte_Ap_DutyCycle_DutyCycle_Per1;
  Rte_tsRB_Ap_ActivePull_ActivePull_Per3 Rte_Ap_ActivePull_ActivePull_Per3;
} Rte_tuRB_Task_128ms;

typedef struct
{
  Rte_tuRB_Task_128ms Rte_RB;
} Rte_tsTask_128ms;

typedef struct
{
  Rte_DE_Float Rte_Cos1Theta_Volts_f32;
  Rte_DE_UInt16 Rte_DutyCycleSmall_Cnt_u16;
  Rte_DE_UInt32 Rte_ExpectedOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeC_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeC_Cnt_u32;
  Rte_DE_Float Rte_MtrPosElec_Rev_f32;
  Rte_DE_Float Rte_MtrPosMech_Rev_f32;
  Rte_DE_SInt16 Rte_MtrRevCntr_Cnt_s16;
  Rte_DE_Float Rte_PhsReasA_Volts_f32;
  Rte_DE_Float Rte_PhsReasB_Volts_f32;
  Rte_DE_Float Rte_PhsReasC_Volts_f32;
  Rte_DE_Float Rte_SWDutyCycleA_Uls_f32;
  Rte_DE_Float Rte_SWDutyCycleB_Uls_f32;
  Rte_DE_Float Rte_SWDutyCycleC_Uls_f32;
  Rte_DE_Float Rte_Shcurr_Volts_f32;
  Rte_DE_Float Rte_Sin1Theta_Volts_f32;
} Rte_tsRB_Sa_CDDInterface_CDDInterface_Per1;

typedef struct
{
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Boolean Rte_VswitchClosed_Cnt_lgc;
} Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per1;

typedef struct
{
  Rte_DE_Float Rte_T1ADC_Volt_f32;
  Rte_DE_Float Rte_T2ADC_Volt_f32;
  Rte_DE_Boolean Rte_SrlComHwTrqValid_Cnt_lgc;
} Rte_tsRB_Sa_HwTrq_HwTrq_Per1;

typedef struct
{
  Rte_DE_Float Rte_AnaHwTrq_HwNm_f32;
  Rte_DE_Float Rte_AnaHwTrqDiff_Volt_f32;
  Rte_DE_Float Rte_DigHwTrq_HwNm_f32;
  Rte_DE_Float Rte_DigHwTrqDiff_Volt_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Boolean Rte_WIREnable_Cnt_lgc;
} Rte_tsRB_Sa_HwTrqArb_HwTrqArb_Per1;

typedef struct
{
  Rte_DE_SInt8 Rte_AsstAssemPol_Cnt_s08;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Float Rte_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_HwVel_HwRadpS_f32;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
} Rte_tsRB_Sa_MtrVel_MtrVel_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_HysAddSrlComSvcDft_Cnt_lgc;
} Rte_tsRB_Ap_HystAdd_HystAdd_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistDDFactor_Uls_f32;
  Rte_DE_Boolean Rte_DftAsstTbl_Cnt_lgc;
  Rte_DE_Float Rte_DwnldAsstGain_Uls_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_HwTrqHysAdd_HwNm_f32;
  Rte_DE_Float Rte_IpTrqOvr_HwNm_f32;
  Rte_DE_Float Rte_ThermalAssistScl_Uls_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
} Rte_tsRB_Ap_Assist_Assist_Per1;

typedef struct
{
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_DefeatHystService_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
} Rte_tsRB_Ap_HystComp_HystComp_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistDDFactor_Uls_f32;
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_HighFreqAssist_MtrNm_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_HysteresisComp_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_AssistCmd_MtrNm_f32;
} Rte_tsRB_Ap_StabilityComp_StabilityComp_Per1;

typedef struct
{
  Rte_DE_Float Rte_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
  Rte_DE_Float Rte_FrqDepDmpnInrtCmp_MtrNm_f32;
} Rte_tsRB_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_BaseAssistStCmp_MtrNm_f32;
  Rte_DE_Float Rte_DampingDDFactor_Uls_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_MotorVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_DampingCmd_MtrNm_f32;
} Rte_tsRB_Ap_Damping_Damping_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistMechTempEst_DegC_f32;
  Rte_DE_Boolean Rte_DiagStsHwPosDis_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelVel_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_PAReturnSclFct_Uls_f32;
  Rte_DE_Float Rte_ReturnDDFactor_Uls_f32;
  Rte_DE_Float Rte_ReturnOffset_HwDeg_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_ReturnCmd_MtrNm_f32;
} Rte_tsRB_Ap_Return_Return_Per1;

typedef struct
{
  Rte_DE_Float Rte_SrlComLWhlSpd_Hz_f32;
  Rte_DE_Boolean Rte_SrlComLWhlSpdVld_Cnt_lgc;
  Rte_DE_Float Rte_SrlComRWhlSpd_Hz_f32;
  Rte_DE_Boolean Rte_SrlComRWhlSpdVld_Cnt_lgc;
  Rte_DE_Float Rte_QualWhlFreqL_Hz_f32;
  Rte_DE_Float Rte_QualWhlFreqR_Hz_f32;
  Rte_DE_Boolean Rte_WhlFreqQualified_Cnt_lgc;
} Rte_tsRB_Ap_WIRInputQual_WIRInputQual_Per1;

typedef struct
{
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_QualWhlFreqL_Hz_f32;
  Rte_DE_Float Rte_QualWhlFreqR_Hz_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Boolean Rte_VehSpdValid_Cnt_lgc;
  Rte_DE_Boolean Rte_WIRFnEnable_Cnt_lgc;
  Rte_DE_Boolean Rte_WIRMfgEnable_Cnt_lgc;
  Rte_DE_Boolean Rte_WhlFreqQualified_Cnt_lgc;
  Rte_DE_Float Rte_WIRCmdAmpBlnd_MtrNm_f32;
  Rte_DE_Float Rte_WhlImbRejCmd_MtrNm_f32;
} Rte_tsRB_Ap_WhlImbRej_WhlImbRej_Per1;

typedef struct
{
  Rte_DE_Float Rte_WhlImbRejCmd_MtrNm_f32;
} Rte_tsRB_Ap_WhlImbRej_WhlImbRej_Per3;

typedef struct
{
  Rte_DE_Boolean Rte_DisableLearning_Cnt_lgc;
  Rte_DE_Boolean Rte_DisableOutput_Cnt_lgc;
  Rte_DE_Float Rte_HandwheelAuthority_Uls_f32;
  Rte_DE_Float Rte_HandwheelPosition_HwDeg_f32;
  Rte_DE_Float Rte_HandwheelVelocity_HwRadpS_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_SrlComYawRate_DegpS_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_VehicleSpeedRate_KphpS_f32;
  Rte_DE_Boolean Rte_VehicleSpeedValid_Cnt_lgc;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DisableOutput_Cnt_lgc;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_PullCompCmd_MtrNm_f32;
} Rte_tsRB_Ap_ActivePull_ActivePull_Per2;

typedef struct
{
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
  Rte_DE_Float Rte_HwPos_HwDeg_f32;
  Rte_DE_Float Rte_HwPosAuth_Uls_f32;
} Rte_tsRB_Ap_VehSpdLmt_VehSpdLmt_Per1;

typedef struct
{
  Rte_DE_Float Rte_AssistCCLwrBndCh2_MtrNm_f32;
  Rte_DE_Float Rte_AssistCCUprBndCh2_MtrNm_f32;
  Rte_DE_Float Rte_AssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_AstEOTDampingCmd_MtrNm_f32;
  Rte_DE_Float Rte_AstEOTGain_Uls_f32;
  Rte_DE_Float Rte_AstEOTLimit_MtrNm_f32;
  Rte_DE_Float Rte_AstPowerLimit_MtrNm_f32;
  Rte_DE_Float Rte_AstStallLimit_MtrNm_f32;
  Rte_DE_Float Rte_AstVehSpdLimit_MtrNm_f32;
  Rte_DE_Float Rte_Compensation_MtrNm_f32;
  Rte_DE_Float Rte_DampingCCLwrBndCh2_MtrNm_f32;
  Rte_DE_Float Rte_DampingCCUprBndCh2_MtrNm_f32;
  Rte_DE_Float Rte_DampingCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_DampingSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_LimitSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_LrnPnCntrEnable_Cnt_lgc;
  Rte_DE_Float Rte_LrnPnCntrTCmd_MtrNm_f32;
  Rte_DE_Float Rte_OpTrqOvr_MtrNm_f32;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
  Rte_DE_Float Rte_PowerLimitPerc_Uls_f32;
  Rte_DE_Float Rte_PrkAstCommand_MtrNm_f32;
  Rte_DE_Float Rte_PullComp_MtrNm_f32;
  Rte_DE_Float Rte_ReturnCCLwrBndCh2_MtrNm_f32;
  Rte_DE_Float Rte_ReturnCCUprBndCh2_MtrNm_f32;
  Rte_DE_Float Rte_ReturnCmd_MtrNm_f32;
  Rte_DE_Float Rte_ThermalLimit_MtrNm_f32;
  Rte_DE_Float Rte_ThermalLimitPerc_Uls_f32;
  Rte_DE_Float Rte_WhlImbRejCmd_MtrNm_f32;
  Rte_DE_Float Rte_PreLimitForPwr_MtrNm_f32;
  Rte_DE_Float Rte_PreLimitForStall_MtrNm_f32;
  Rte_DE_Float Rte_PreLimitTorque_MtrNm_f32;
} Rte_tsRB_Ap_AssistSumnLmt_AssistSumnLmt_Per1;

typedef struct
{
  Rte_DE_SInt8 Rte_AssistAssyPolarity_Cnt_s08;
  Rte_DE_Boolean Rte_DiagStsF2Active_Cnt_lgc;
  Rte_DE_Float Rte_PostLimitTorque_MtrNm_f32;
  Rte_DE_Float Rte_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Boolean Rte_CtrldDmpStsCmp_Cnt_lgc;
} Rte_tsRB_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1;

typedef struct
{
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_VelOffset_MtrRadpS_f32;
  Rte_DE_Float Rte_MtrEnvSpd_MtrRadpS_f32;
} Rte_tsRB_Ap_MtrTrqLmt_MtrTrqLmt_Per1;

typedef struct
{
  Rte_DE_SInt8 Rte_AsstAssemPol_Cnt_s8;
  Rte_DE_Float Rte_EpsOpTrq_MtrNm_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Float Rte_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_TrqLmt_Pct_f32;
} Rte_tsRB_Ap_MtrTrqLmt_MtrTrqLmt_Per2;

typedef struct
{
  Rte_DE_Float Rte_MRFCumMtrPos_Deg_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_SInt8 Rte_InstMtrDir_Cnt_s08;
  Rte_DE_UInt8 Rte_MtrQuad_Cnt_u08;
} Rte_tsRB_Ap_QuadDet_QuadDet_Per1;

typedef struct
{
  Rte_DE_UInt16 Rte_DutyCycleSmall_Cnt_u16;
  Rte_DE_SInt8 Rte_InstMtrDir_Cnt_s08;
  Rte_DE_Float Rte_MtrPosElec_Rev_f32;
  Rte_DE_UInt16 Rte_PADelta1_Cnt_u16;
  Rte_DE_Float Rte_Shcurr_Volts_f32;
  Rte_DE_Float Rte_MtrCurrDax_Amp_f32;
  Rte_DE_Float Rte_MtrCurrQax_Amp_f32;
  Rte_DE_Boolean Rte_ValidCurrSample_Cnt_lgc;
} Rte_tsRB_Sa_MtrCurr_MtrCurr_Per1;

typedef struct
{
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_TermB_Volt_f32;
} Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per1;

typedef struct
{
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_EstL_Henry_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_MRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_TermA_Volt_f32;
  Rte_DE_Float Rte_TermD_Volt_f32;
  Rte_DE_Float Rte_TermE_Volt_f32;
  Rte_DE_Float Rte_TermX_Uls_f32;
  Rte_DE_Float Rte_TermY_Uls_f32;
} Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per2;

typedef struct
{
  Rte_DE_Float Rte_MtrEnvSpd_MtrRadpS_f32;
  Rte_DE_Float Rte_Vecu_Volt_f32;
} Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per3;

typedef struct
{
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_PDActivateTest_Cnt_lgc;
  Rte_DE_SInt16 Rte_PDPhsAdvSel_Cnt_s16;
  Rte_DE_Float Rte_TermA_Volt_f32;
  Rte_DE_Float Rte_TermB_Volt_f32;
  Rte_DE_Float Rte_TermD_Volt_f32;
  Rte_DE_Float Rte_TermE_Volt_f32;
  Rte_DE_Float Rte_TermX_Uls_f32;
  Rte_DE_Float Rte_TermY_Uls_f32;
} Rte_tsRB_Ap_PhaseCtrl_PhaseCtrl_Per1;

typedef struct
{
  Rte_DE_UInt8 Rte_MtrQuad_Cnt_u08;
  Rte_DE_Boolean Rte_PDActivateTest_Cnt_lgc;
  Rte_DE_Float Rte_PDTestModIdx_Uls_f32;
  Rte_DE_SInt16 Rte_UncorrPhsAdv_Cnt_s16;
  Rte_DE_Float Rte_Vecu_Volt_f32;
} Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per4;

typedef struct
{
  Rte_DE_FETFAULTTYPE_ENUM Rte_FETFaultType_Cnt_enum;
  Rte_DE_Float Rte_ModIdx_Uls_f32;
  Rte_DE_Float Rte_MtrTrqCmd_MtrNm_f32;
  Rte_DE_SInt16 Rte_PhaseAdvance_Cnt_s16;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
} Rte_tsRB_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1;

typedef struct
{
  Rte_DE_Float Rte_TemperatureADC_Volt_f32;
} Rte_tsRB_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc;

typedef struct
{
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_ExpIq_Amp_f32;
  Rte_DE_Float Rte_ModIdx_Uls_f32;
  Rte_DE_Float Rte_TermX_Uls_f32;
  Rte_DE_SInt16 Rte_UncorrPhsAdv_Cnt_s16;
  Rte_DE_Float Rte_Vecu_Volt_f32;
  Rte_DE_Float Rte_EstPkCurr_AmpSq_f32;
} Rte_tsRB_Ap_CurrentEst_CurrentEst_Per1;

typedef struct
{
  Rte_DE_UInt32 Rte_ExpectedOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_ExpectedOnTimeC_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeA_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeB_Cnt_u32;
  Rte_DE_UInt32 Rte_MeasuredOnTimeC_Cnt_u32;
} Rte_tsRB_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1;

typedef struct
{
  Rte_DE_FETPHASETYPE_ENUM Rte_FETFaultPhase_Cnt_enum;
  Rte_DE_Float Rte_PhsReasA_Volts_f32;
  Rte_DE_Float Rte_PhsReasB_Volts_f32;
  Rte_DE_Float Rte_PhsReasC_Volts_f32;
  Rte_DE_Float Rte_SWDutyCycleA_Uls_f32;
  Rte_DE_Float Rte_SWDutyCycleB_Uls_f32;
  Rte_DE_Float Rte_SWDutyCycleC_Uls_f32;
} Rte_tsRB_Ap_PhsReasDiag_PhsReasDiag_Per1;

typedef struct
{
  Rte_DE_Float Rte_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_MtrCurrQax_Amp_f32;
  Rte_DE_Boolean Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_UInt8 Rte_MtrQuad_Cnt_u08;
  Rte_DE_Boolean Rte_ValidCurrSample_Cnt_lgc;
  Rte_DE_Float Rte_EstKe_VpRadpS_f32;
  Rte_DE_Float Rte_EstL_Henry_f32;
  Rte_DE_Float Rte_EstR_Ohm_f32;
  Rte_DE_Float Rte_ExpIq_Amp_f32;
} Rte_tsRB_Ap_ParamComp_ParamComp_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_VswitchClosed_Cnt_lgc;
  Rte_DE_FETPHASETYPE_ENUM Rte_FETFaultPhase_Cnt_enum;
  Rte_DE_FETFAULTTYPE_ENUM Rte_FETFaultType_Cnt_enum;
} Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Per1;

typedef struct
{
  Rte_DE_Float Rte_Cos2RTAmpRec_Uls_f32;
  Rte_DE_Float Rte_Cos2RTOffset_Volts_f32;
  Rte_DE_Float Rte_Sin2RTAmpRec_Uls_f32;
  Rte_DE_Float Rte_Sin2RTOffset_Volts_f32;
} Rte_tsRB_Sa_MtrPos_MtrPos_Per2;

typedef struct
{
  Rte_DE_SInt8 Rte_AsstAssemPol_Cnt_s08;
  Rte_DE_SInt16 Rte_MtrRevCntr_Cnt_s16;
  Rte_DE_Float Rte_MRFAlignedCumMtrPos_Deg_f32;
  Rte_DE_Float Rte_MRFCumMtrPos_Deg_f32;
} Rte_tsRB_Sa_MtrPos_MtrPos_Per3;

typedef struct
{
  Rte_DE_Float Rte_CRFCumMtrPos_Deg_f32;
  Rte_DE_Float Rte_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_DiagStsHwPosDis_Cnt_lgc;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_SrlComRxHwPos_HwDeg_f32;
  Rte_DE_Boolean Rte_SrlComRxHwPosVld_Cnt_lgc;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
  Rte_DE_Boolean Rte_VehSpdValid_Cnt_lgc;
  Rte_DE_Float Rte_HwPos_HwDeg_f32;
  Rte_DE_Float Rte_HwPosAuthority_Uls_f32;
} Rte_tsRB_Ap_AbsHwPosScom_AbsHwPosScom_Per1;

typedef struct
{
  Rte_DE_Float Rte_Cos1RTAmpRec_Uls_f32;
  Rte_DE_Float Rte_Cos1RTOffset_Volts_f32;
  Rte_DE_FETPHASETYPE_ENUM Rte_FETFaultPhase_Cnt_enum;
  Rte_DE_FETFAULTTYPE_ENUM Rte_FETFaultType_Cnt_enum;
  Rte_DE_Float Rte_Sin1RTAmpRec_Uls_f32;
  Rte_DE_Float Rte_Sin1RTOffset_Volts_f32;
} Rte_tsRB_Sa_CDDInterface_CDDInterface_Per3;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsTempRdPrf_Cnt_lgc;
  Rte_DE_Float Rte_TemperatureADC_Volt_f32;
  Rte_DE_Float Rte_FiltMeasTemp_DegC_f32;
} Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per1;

typedef struct
{
  Rte_DE_Float Rte_Cos1Theta_Volts_f32;
  Rte_DE_Float Rte_EOLMtrSnsrAdjParam_EOLCos1Offset_Volts_f32;
  Rte_DE_Float Rte_EOLMtrSnsrAdjParam_EOLCos2Offset_Volts_f32;
  Rte_DE_Float Rte_EOLMtrSnsrAdjParam_EOLSin1AmpRec_Uls_f32;
  Rte_DE_Float Rte_EOLMtrSnsrAdjParam_EOLSin1Offset_Volts_f32;
  Rte_DE_Float Rte_EOLMtrSnsrAdjParam_EOLSin2AmpRec_Uls_f32;
  Rte_DE_Float Rte_EOLMtrSnsrAdjParam_EOLSin2Offset_Volts_f32;
  Rte_DE_Float Rte_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_MtrPosMech_Rev_f32;
  Rte_DE_Float Rte_MtrPosMech2_Rev_f32;
  Rte_DE_Float Rte_Sin1Theta_Volts_f32;
} Rte_tsRB_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_EngONSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_SrlComEngOn_Cnt_lgc;
  Rte_DE_Boolean Rte_SrlComSPMOn_Cnt_lgc;
  Rte_DE_Boolean Rte_VehSpdValid_Cnt_lgc;
} Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Per1;

typedef struct
{
  Rte_DE_Float Rte_DiagRampRate_XpmS_f32;
  Rte_DE_Float Rte_DiagRampValue_Uls_f32;
  Rte_DE_Float Rte_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_OperRampValue_Uls_f32;
  Rte_DE_Boolean Rte_RampSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_OutputRampMult_Uls_f32;
} Rte_tsRB_Ap_StOpCtrl_StOpCtrl_Per1;

typedef struct
{
  Rte_DE_Float Rte_CcwEOT_HwDeg_f32;
  Rte_DE_Boolean Rte_CcwFound_Cnt_lgc;
  Rte_DE_Float Rte_CwEOT_HwDeg_f32;
  Rte_DE_Boolean Rte_CwFound_Cnt_lgc;
  Rte_DE_Float Rte_HandWheelAuth_Uls_f32;
  Rte_DE_Float Rte_HandWheelPos_HwDeg_f32;
  Rte_DE_Float Rte_HwTorque_HwNm_f32;
  Rte_DE_Float Rte_PreLimitTorque_MtrNm_f32;
  Rte_DE_Float Rte_VehicleSpeed_Kph_f32;
  Rte_DE_Float Rte_AssistEOTDamping_MtrNm_f32;
  Rte_DE_Float Rte_AssistEOTGain_Uls_f32;
  Rte_DE_Float Rte_AssistEOTLimit_MtrNm_f32;
} Rte_tsRB_Ap_EOTActuatorMng_EOTActuatorMng_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_DftStallLimit_Cnt_lgc;
  Rte_DE_Float Rte_MtrVelCRF_MtrRadpS_f32;
  Rte_DE_Float Rte_PreLimitForStall_MtrNm_f32;
  Rte_DE_Float Rte_AssistStallLimit_MtrNm_f32;
} Rte_tsRB_Ap_HiLoadStall_HiLoadStall_Per1;

typedef struct
{
  Rte_DE_Boolean Rte_ATerm_Cnt_lgc;
  Rte_DE_Boolean Rte_CTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_ControlledDampStatusComplete_Cnt_lgc;
  Rte_DE_Boolean Rte_FTerm_Cnt_lgc;
  Rte_DE_Boolean Rte_RampStatusComplete_Cnt_lgc;
} Rte_tsRB_Ap_StaMd_StaMd_Per1;

typedef union
{
  Rte_tsRB_Sa_CDDInterface_CDDInterface_Per1 Rte_Sa_CDDInterface_CDDInterface_Per1;
  Rte_tsRB_Ap_BatteryVoltage_BatteryVoltage_Per1 Rte_Ap_BatteryVoltage_BatteryVoltage_Per1;
  Rte_tsRB_Sa_HwTrq_HwTrq_Per1 Rte_Sa_HwTrq_HwTrq_Per1;
  Rte_tsRB_Sa_HwTrqArb_HwTrqArb_Per1 Rte_Sa_HwTrqArb_HwTrqArb_Per1;
  Rte_tsRB_Sa_MtrVel_MtrVel_Per1 Rte_Sa_MtrVel_MtrVel_Per1;
  Rte_tsRB_Ap_HystAdd_HystAdd_Per1 Rte_Ap_HystAdd_HystAdd_Per1;
  Rte_tsRB_Ap_Assist_Assist_Per1 Rte_Ap_Assist_Assist_Per1;
  Rte_tsRB_Ap_HystComp_HystComp_Per1 Rte_Ap_HystComp_HystComp_Per1;
  Rte_tsRB_Ap_StabilityComp_StabilityComp_Per1 Rte_Ap_StabilityComp_StabilityComp_Per1;
  Rte_tsRB_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1 Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1;
  Rte_tsRB_Ap_Damping_Damping_Per1 Rte_Ap_Damping_Damping_Per1;
  Rte_tsRB_Ap_Return_Return_Per1 Rte_Ap_Return_Return_Per1;
  Rte_tsRB_Ap_WIRInputQual_WIRInputQual_Per1 Rte_Ap_WIRInputQual_WIRInputQual_Per1;
  Rte_tsRB_Ap_WhlImbRej_WhlImbRej_Per1 Rte_Ap_WhlImbRej_WhlImbRej_Per1;
  Rte_tsRB_Ap_WhlImbRej_WhlImbRej_Per3 Rte_Ap_WhlImbRej_WhlImbRej_Per3;
  Rte_tsRB_Ap_ActivePull_ActivePull_Per1 Rte_Ap_ActivePull_ActivePull_Per1;
  Rte_tsRB_Ap_ActivePull_ActivePull_Per2 Rte_Ap_ActivePull_ActivePull_Per2;
  Rte_tsRB_Ap_VehSpdLmt_VehSpdLmt_Per1 Rte_Ap_VehSpdLmt_VehSpdLmt_Per1;
  Rte_tsRB_Ap_AssistSumnLmt_AssistSumnLmt_Per1 Rte_Ap_AssistSumnLmt_AssistSumnLmt_Per1;
  Rte_tsRB_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1 Rte_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1;
  Rte_tsRB_Ap_MtrTrqLmt_MtrTrqLmt_Per1 Rte_Ap_MtrTrqLmt_MtrTrqLmt_Per1;
  Rte_tsRB_Ap_MtrTrqLmt_MtrTrqLmt_Per2 Rte_Ap_MtrTrqLmt_MtrTrqLmt_Per2;
  Rte_tsRB_Ap_QuadDet_QuadDet_Per1 Rte_Ap_QuadDet_QuadDet_Per1;
  Rte_tsRB_Sa_MtrCurr_MtrCurr_Per1 Rte_Sa_MtrCurr_MtrCurr_Per1;
  Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per1 Rte_Ap_VltgCtrl_VltgCtrl_Per1;
  Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per2 Rte_Ap_VltgCtrl_VltgCtrl_Per2;
  Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per3 Rte_Ap_VltgCtrl_VltgCtrl_Per3;
  Rte_tsRB_Ap_PhaseCtrl_PhaseCtrl_Per1 Rte_Ap_PhaseCtrl_PhaseCtrl_Per1;
  Rte_tsRB_Ap_VltgCtrl_VltgCtrl_Per4 Rte_Ap_VltgCtrl_VltgCtrl_Per4;
  Rte_tsRB_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1 Rte_Ap_MtrCtrlOpConv_MtrCtrlOpConv_Per1;
  Rte_tsRB_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc Rte_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc;
  Rte_tsRB_Ap_CurrentEst_CurrentEst_Per1 Rte_Ap_CurrentEst_CurrentEst_Per1;
  Rte_tsRB_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1;
  Rte_tsRB_Ap_PhsReasDiag_PhsReasDiag_Per1 Rte_Ap_PhsReasDiag_PhsReasDiag_Per1;
  Rte_tsRB_Ap_ParamComp_ParamComp_Per1 Rte_Ap_ParamComp_ParamComp_Per1;
  Rte_tsRB_Sa_MtrDrvDiag_MtrDrvDiag_Per1 Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1;
  Rte_tsRB_Sa_MtrPos_MtrPos_Per2 Rte_Sa_MtrPos_MtrPos_Per2;
  Rte_tsRB_Sa_MtrPos_MtrPos_Per3 Rte_Sa_MtrPos_MtrPos_Per3;
  Rte_tsRB_Ap_AbsHwPosScom_AbsHwPosScom_Per1 Rte_Ap_AbsHwPosScom_AbsHwPosScom_Per1;
  Rte_tsRB_Sa_CDDInterface_CDDInterface_Per3 Rte_Sa_CDDInterface_CDDInterface_Per3;
  Rte_tsRB_Sa_CtrlTemp_CtrlTemp_Per1 Rte_Sa_CtrlTemp_CtrlTemp_Per1;
  Rte_tsRB_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1 Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1;
  Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Per1 Rte_Ap_VehPwrMd_VehPwrMd_Per1;
  Rte_tsRB_Ap_StOpCtrl_StOpCtrl_Per1 Rte_Ap_StOpCtrl_StOpCtrl_Per1;
  Rte_tsRB_Ap_EOTActuatorMng_EOTActuatorMng_Per1 Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1;
  Rte_tsRB_Ap_HiLoadStall_HiLoadStall_Per1 Rte_Ap_HiLoadStall_HiLoadStall_Per1;
  Rte_tsRB_Ap_StaMd_StaMd_Per1 Rte_Ap_StaMd_StaMd_Per1;
} Rte_tuRB_Task_2ms;

typedef struct
{
  Rte_DE_Float Rte_I_IoHwAbstractionUsr_T1ADC_Volt_f32;
  Rte_DE_Float Rte_I_IoHwAbstractionUsr_T1Duty_Uls_f32;
  Rte_DE_Float Rte_I_IoHwAbstractionUsr_T2ADC_Volt_f32;
  Rte_DE_Float Rte_I_IoHwAbstractionUsr_T2Duty_Uls_f32;
  Rte_DE_Float Rte_I_HwTrq_AnaDiffHwTrq_Volt_f32;
  Rte_DE_Float Rte_I_HwTrq_AnaHwTorque_HwNm_f32;
  Rte_DE_Float Rte_I_DigHwTrq_DigHwTrq_HwNm_f32;
  Rte_DE_Float Rte_I_DigHwTrq_DigHwTrqDiff_Volt_f32;
  Rte_DE_Float Rte_I_HwTrqArb_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_I_VehicleSpeed_VehSpd_Kph_f32;
  Rte_DE_Float Rte_I_HystAdd_HysAddHwTrq_HwNm_f32;
  Rte_DE_Float Rte_I_WhlImbRej_WIRCmdAmpBlnd_MtrNm_f32;
  Rte_DE_Float Rte_I_Assist_BaseAssistCmd_MtrNm_f32;
  Rte_DE_Float Rte_I_HighFreqAssist_HighFreqAssist_MtrNm_f32;
  Rte_DE_Float Rte_I_MtrTempEst_AssistMechTempEst_DegC_f32;
  Rte_DE_Float Rte_I_HystComp_HysteresisComp_MtrNm_f32;
  Rte_DE_Float Rte_I_StabilityComp_BaseAssistStCmp_MtrNm_f32;
  Rte_DE_Float Rte_I_MtrVel_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_I_VehSpdLmt_AstVehSpdLimit_MtrNm_f32;
  Rte_DE_Float Rte_I_AssistSumnLmt_PostLimitTorque_MtrNm_f32;
  Rte_DE_Float Rte_I_MtrVel_MRFMtrVel_MtrRadpS_f32;
  Rte_DE_Float Rte_I_CtrldDisShtdn_MRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_I_BatteryVoltage_Vecu_Volt_f32;
  Rte_DE_Float Rte_I_MtrTrqLmt_MRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;
  Rte_DE_UInt8 Rte_I_QuadDet_MtrQuad_Cnt_u08;
  Rte_DE_SInt16 Rte_I_PhaseCtrl_PhsAdv_Cnt_s16;
  Rte_DE_SInt16 Rte_I_PhaseCtrl_UncorrPhsAdv_Cnt_s16;
  Rte_DE_Float Rte_I_VltgCtrl_ModIdx_Uls_f32;
  Rte_DE_UInt16 Rte_I_MtrCtrlOpConv_CommOffset_Cnt_u16;
  Rte_DE_Float Rte_I_MtrCtrlOpConv_DeadTimeComp_Uls_f32;
  Rte_DE_Float Rte_I_MtrCtrlOpConv_ModIdxFinal_Uls_f32;
  Rte_DE_SInt16 Rte_I_MtrCtrlOpConv_MtrTrqCmdSign_Cnt_s16;
  Rte_DE_UInt16 Rte_I_MtrCtrlOpConv_PhaseAdvFinal_Cnt_u16;
  Rte_DE_Float Rte_I_MtrPos_MtrPosMech2_Rev_f32;
  Rte_DE_Float Rte_I_CDDInterface_MtrPosMech_Rev_f32;
  Rte_DE_Float Rte_I_MtrPos_CRFCumMtrPos_Deg_f32;
  Rte_DE_Float Rte_I_MtrPosSnsrLearning_Cos1RTOffset_Volts_f32;
  Rte_DE_Float Rte_I_MtrPosSnsrLearning_Sin1RTOffset_Volts_f32;
  Rte_DE_Boolean Rte_I_VehPwrMd_ATermActive_Cnt_lgc;
  Rte_DE_Boolean Rte_I_VehPwrMd_CTermActive_Cnt_lgc;
  Rte_DE_Float Rte_I_VehPwrMd_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_I_VehPwrMd_OperRampValue_Uls_f32;
  Rte_DE_Boolean Rte_I_DiagMgr_DiagStsDiagRmpActive_Cnt_lgc;
  Rte_DE_Boolean Rte_I_StOpCtrl_RampDwnStatusComplete_Cnt_lgc;
} Rte_tsTB_Task_2ms;

typedef struct
{
  Rte_tsTB_Task_2ms Rte_TB;
  Rte_tuRB_Task_2ms Rte_RB;
} Rte_tsTask_2ms;

typedef struct
{
  Rte_DE_Float Rte_T1ADC_Volt_f32;
  Rte_DE_Float Rte_T2ADC_Volt_f32;
} Rte_tsRB_Sa_HwTrq_HwTrq_Per2;

typedef struct
{
  Rte_DE_Float Rte_AnaHwTrqDiff_Volt_f32;
  Rte_DE_Float Rte_DigHwTrqDiff_Volt_f32;
} Rte_tsRB_Sa_HwTrqArb_HwTrqArb_Per2;

typedef struct
{
  Rte_DE_Float Rte_AlignedHwPos_HwDeg_f32;
  Rte_DE_Float Rte_CRFMtrVel_MtrRadpS_f32;
  Rte_DE_Boolean Rte_DiagStsHwPosDis_Cnt_lgc;
  Rte_DE_Float Rte_HwPos_HwDeg_f32;
  Rte_DE_Float Rte_HwPosAuth_Uls_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
  Rte_DE_Float Rte_PreLimitTrq_MtrNm_f32;
  Rte_DE_Boolean Rte_CCWFound_Cnt_lgc;
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_CWFound_Cnt_lgc;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
  Rte_DE_Float Rte_RackCenterMag_HwDeg_f32;
  Rte_DE_Boolean Rte_RackCntrCmplt_Cnt_lgc;
} Rte_tsRB_Ap_LrnEOT_LrnEOT_Per1;

typedef union
{
  Rte_tsRB_Sa_HwTrq_HwTrq_Per2 Rte_Sa_HwTrq_HwTrq_Per2;
  Rte_tsRB_Sa_HwTrqArb_HwTrqArb_Per2 Rte_Sa_HwTrqArb_HwTrqArb_Per2;
  Rte_tsRB_Ap_LrnEOT_LrnEOT_Per1 Rte_Ap_LrnEOT_LrnEOT_Per1;
} Rte_tuRB_Task_4ms;

typedef struct
{
  Rte_tuRB_Task_4ms Rte_RB;
} Rte_tsTask_4ms;

typedef struct
{
  Rte_DE_Boolean Rte_DiagStsDefVehSpd_Cnt_lgc;
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
  Rte_DE_Boolean Rte_DampingSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_DftAsstTbl_Cnt_lgc;
  Rte_DE_Boolean Rte_DrivingDynSrlComSvcDft_Cnt_lgc;
  Rte_DE_Float Rte_DwnldAsstGain_Uls_f32;
  Rte_DE_Boolean Rte_EOTImpactSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_EOTThermalSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_EngONSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_HysAddSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_HystCompSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_KinIntDiagSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_LimitSrlComSvcDft_Cnt_lgc;
  Rte_DE_ManufModeType Rte_MEC_Cnt_enum;
  Rte_DE_Boolean Rte_MfgDiagInhibit_Cnt_lgc;
  Rte_DE_Boolean Rte_ModIdxSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_MultIgnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_ParkAstSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_PullCompLrnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_PullCompSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_ReturnSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_RxMsgsSrlComSvcDft_Cnt_lgc;
  Rte_DE_UInt32 Rte_SrlComSvcDft_Cnt_b32;
  Rte_DE_Boolean Rte_ThermalDCSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_TrqRmpSrlComSvcDft_Cnt_lgc;
  Rte_DE_Boolean Rte_VehSpdValid_Cnt_lgc;
  Rte_DE_Boolean Rte_WIRMfgEnabled_Cnt_lgc;
} Rte_tsRB_Sa_CDDInterface_CDDInterface_Per4;

typedef union
{
  Rte_tsRB_Sa_CDDInterface_CDDInterface_Per4 Rte_Sa_CDDInterface_CDDInterface_Per4;
} Rte_tuRB_Task_5ms;

typedef struct
{
  Rte_tuRB_Task_5ms Rte_RB;
} Rte_tsTask_5ms;

typedef struct
{
  Rte_DE_Float Rte_SrlComVehSpd_Kph_f32;
  Rte_DE_Boolean Rte_DefaultVehSpd_Cnt_lgc;
  Rte_DE_Float Rte_VehAccel_KphpS_f32;
  Rte_DE_Float Rte_VehSpd_Kph_f32;
} Rte_tsRB_Ap_VehicleSpeed_VehicleSpeed_Per1;

typedef struct
{
  Rte_DE_Float Rte_CRFMtrTrqCmd_MtrNm_f32;
  Rte_DE_Float Rte_HwTrq_HwNm_f32;
} Rte_tsRB_Ap_AbsHwPosScom_AbsHwPosScom_Per3;

typedef struct
{
  Rte_DE_Float Rte_PhsReasA_Volts_f32;
  Rte_DE_Float Rte_PhsReasB_Volts_f32;
  Rte_DE_Float Rte_PhsReasC_Volts_f32;
} Rte_tsRB_Ap_PhsReasDiag_PhsReasDiag_Per2;

typedef struct
{
  Rte_DE_RT_DTC_Triggered_778 Rte_Tx_DTC_Triggered_778_DTC_Triggered_778;
  Rte_DE_RT_Power_Steering_Information_HS Rte_Tx_Power_Steering_Information_HS_Power_Steering_Information_HS;
} Rte_tsRB_Ap_SrlComOutput_SrlComOutput_Per1;

typedef struct
{
  Rte_DE_RT_Power_Steering_Information_HS Rte_Tx_Power_Steering_Information_HS_Power_Steering_Information_HS;
} Rte_tsRB_CDD_IL_COM_Tx_Power_Steering_Information_HS;

typedef struct
{
  Rte_DE_RT_DTC_Triggered_778 Rte_TX_DTC_Triggered_778_DTC_Triggered_778;
} Rte_tsRB_CDD_IL_COM_Tx_DTC_Triggered_778;

typedef union
{
  Rte_tsRB_Ap_VehicleSpeed_VehicleSpeed_Per1 Rte_Ap_VehicleSpeed_VehicleSpeed_Per1;
  Rte_tsRB_Ap_AbsHwPosScom_AbsHwPosScom_Per3 Rte_Ap_AbsHwPosScom_AbsHwPosScom_Per3;
  Rte_tsRB_Ap_PhsReasDiag_PhsReasDiag_Per2 Rte_Ap_PhsReasDiag_PhsReasDiag_Per2;
  Rte_tsRB_Ap_SrlComOutput_SrlComOutput_Per1 Rte_Ap_SrlComOutput_SrlComOutput_Per1;
  Rte_tsRB_CDD_IL_COM_Tx_Power_Steering_Information_HS Rte_CDD_IL_COM_Tx_Power_Steering_Information_HS;
  Rte_tsRB_CDD_IL_COM_Tx_DTC_Triggered_778 Rte_CDD_IL_COM_Tx_DTC_Triggered_778;
} Rte_tuRB_Task_64ms;

typedef struct
{
  Rte_tuRB_Task_64ms Rte_RB;
} Rte_tsTask_64ms;

typedef struct
{
  Rte_DE_SInt8 Rte_AssistAssyPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_HwPosPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_HwTrqPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_MtrPosPolarity_Cnt_s08;
  Rte_DE_SInt8 Rte_MtrVelPolarity_Cnt_s08;
} Rte_tsRB_Ap_Polarity_Polarity_Init1;

typedef struct
{
  Rte_DE_Float Rte_Cos1RTAmpRec_Uls_f32;
  Rte_DE_Float Rte_Cos1RTOffset_Volts_f32;
  Rte_DE_SInt8 Rte_MtrElecMechPolarity_Cnt_s08;
  Rte_DE_Float Rte_Sin1RTAmpRec_Uls_f32;
  Rte_DE_Float Rte_Sin1RTOffset_Volts_f32;
  Rte_DE_ManufModeType Rte_MEC_Cnt_enum;
} Rte_tsRB_Sa_CDDInterface_CDDInterface_Init1;

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
  Rte_DE_Float Rte_OperRampRate_XpmS_f32;
  Rte_DE_Float Rte_OperRampValue_Uls_f32;
} Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Init1;

typedef struct
{
  Rte_DE_Boolean Rte_CCWFound_Cnt_lgc;
  Rte_DE_Float Rte_CCWPosition_HwDeg_f32;
  Rte_DE_Boolean Rte_CWFound_Cnt_lgc;
  Rte_DE_Float Rte_CWPosition_HwDeg_f32;
} Rte_tsRB_Ap_LrnEOT_LrnEOT_Init1;

typedef struct
{
  Rte_DE_Float Rte_VehSpd_Kph_f32;
} Rte_tsRB_Ap_VehicleSpeed_VehicleSpeed_Init;

typedef struct
{
  Rte_DE_Float Rte_SrlComAmbTemp_DegC_f32;
  Rte_DE_Float Rte_SrlComEngTemp_DegC_f32;
} Rte_tsRB_Ap_SrlComInput_SrlComInput_Init;

typedef union
{
  Rte_tsRB_Ap_Polarity_Polarity_Init1 Rte_Ap_Polarity_Polarity_Init1;
  Rte_tsRB_Sa_CDDInterface_CDDInterface_Init1 Rte_Sa_CDDInterface_CDDInterface_Init1;
  Rte_tsRB_Ap_MtrTempEst_MtrTempEst_Init1 Rte_Ap_MtrTempEst_MtrTempEst_Init1;
  Rte_tsRB_Ap_VehPwrMd_VehPwrMd_Init1 Rte_Ap_VehPwrMd_VehPwrMd_Init1;
  Rte_tsRB_Ap_LrnEOT_LrnEOT_Init1 Rte_Ap_LrnEOT_LrnEOT_Init1;
  Rte_tsRB_Ap_VehicleSpeed_VehicleSpeed_Init Rte_Ap_VehicleSpeed_VehicleSpeed_Init;
  Rte_tsRB_Ap_SrlComInput_SrlComInput_Init Rte_Ap_SrlComInput_SrlComInput_Init;
} Rte_tuRB_Task_Init;

typedef struct
{
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos1AmpRec_Uls_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos1GainCorr_Uls_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos1OffsetCorr_Volts_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos1Offset_Volts_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos2AmpRec_Uls_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos2Offset_Volts_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin1AmpRec_Uls_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin1GainCorr_Uls_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin1OffsetCorr_Volts_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin1Offset_Volts_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin2AmpRec_Uls_f32;
  Rte_DE_Float Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin2Offset_Volts_f32;
  Rte_DE_SInt8 Rte_I_Polarity_MtrElecMechPolarity_Cnt_s08;
} Rte_tsTB_Task_Init;

typedef struct
{
  Rte_tsTB_Task_Init Rte_TB;
  Rte_tuRB_Task_Init Rte_RB;
} Rte_tsTask_Init;

typedef struct
{
  Rte_DE_Float Rte_PhsReasA_Volts_f32;
  Rte_DE_Float Rte_PhsReasB_Volts_f32;
  Rte_DE_Float Rte_PhsReasC_Volts_f32;
} Rte_tsRB_Ap_PhsReasDiag_PhsReasDiag_Trns1;

typedef union
{
  Rte_tsRB_Ap_PhsReasDiag_PhsReasDiag_Trns1 Rte_Ap_PhsReasDiag_PhsReasDiag_Trns1;
} Rte_tuRB_Task_SysStTrans;

typedef struct
{
  Rte_tuRB_Task_SysStTrans Rte_RB;
} Rte_tsTask_SysStTrans;

typedef struct
{
  UInt8 TcEolSineOffset_Cnt_u08;
  UInt8 TcEolCosineOffset_Cnt_u08;
  UInt8 TcEolSin2CosGain_Cnt_u08;
  UInt8 TcEolSinVsCosMin_Cnt_u08;
  UInt8 TcEolSinVsCosMax_Cnt_u08;
  UInt8 TcEolCalChksm_Cnt_u08;
} EOLTurnsCntrCals_Datatype;

typedef UInt8 TcPartNumType[20];

# define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1321055596
#    error "The magic number of the generated file <C:/CMSynergy_Projects/K2xx_Integration/GM_K2XX_EPS_TMS570/SwProject/Source/GenDataRte/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1321055596
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
