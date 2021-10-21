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
 *          File:  Components/Rte_Sa_CDDInterface9.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:20 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE9_H
# define _RTE_SA_CDDINTERFACE9_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ActPullCompLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_AvgFrcLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DampingSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DftAsstTbl_Cnt_lgc (FALSE)
#  define Rte_InitValue_DrivingDynSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DwnldAsstGain_Uls_f32 (0.0F)
#  define Rte_InitValue_EOTImpactSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EOTThermalSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EngONSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_FirewallSrlComSrvDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_FreqDepDmpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_HysAddSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_HystCompSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_IgnCnt_Cnt_u16 (0U)
#  define Rte_InitValue_KinIntDiagSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_LimitSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_LrnPnCenterEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_MfgDiagInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_ModIdxSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MultIgnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_NxtrMEC_Cnt_enum (0U)
#  define Rte_InitValue_OscTrajEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_ParkAstSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosTrajEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PullCompSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_ReturnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
#  define Rte_InitValue_TcActivePN_Cnt_u32 (0U)
#  define Rte_InitValue_TcActivePNVldCnt_Cnt_u32 (0U)
#  define Rte_InitValue_TcFlashErrors_Cnt_u08 (0U)
#  define Rte_InitValue_TcFlashVerify_Cnt_lgc (FALSE)
#  define Rte_InitValue_TcReflashActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_ThermalDCSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqRmpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_WhlImbRejSrlComSvcDft_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitA_9, RTE_VAR_NOINIT) Rte_Task_InitA_9;

extern VAR(Rte_tsTask_5ms_9, RTE_VAR_NOINIT) Rte_Task_5ms_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IWrite_CDDInterface9_Init2_IgnCnt_Cnt_u16(data) \
  ( \
    Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_IgnCnt_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Init2_IgnCnt_Cnt_u16() \
  (&Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_IgnCnt_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Init2_MfgDiagInhibit_Cnt_lgc(data) \
  ( \
    Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_MfgDiagInhibit_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Init2_MfgDiagInhibit_Cnt_lgc() \
  (&Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_MfgDiagInhibit_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Init2_NxtrMEC_Cnt_enum(data) \
  ( \
    Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_NxtrMEC_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Init2_NxtrMEC_Cnt_enum() \
  (&Rte_Task_InitA_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Init2.Rte_NxtrMEC_Cnt_enum.value)

#  define Rte_IRead_CDDInterface9_Per1_TcActivePNVldCnt_Cnt_u32() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcActivePNVldCnt_Cnt_u32.value)

#  define Rte_IRead_CDDInterface9_Per1_TcActivePN_Cnt_u32() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcActivePN_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface9_Per1_ActPullCompLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ActPullCompLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ActPullCompLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ActPullCompLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_AvgFrcLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_AvgFrcLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_AvgFrcLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_AvgFrcLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_DampingSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DampingSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_DampingSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DampingSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_DftAsstTbl_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DftAsstTbl_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_DftAsstTbl_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DftAsstTbl_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_DrivingDynSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_DwnldAsstGain_Uls_f32(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DwnldAsstGain_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_DwnldAsstGain_Uls_f32() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_DwnldAsstGain_Uls_f32.value)

#  define Rte_IWrite_CDDInterface9_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_EOTImpactSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_EOTThermalSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_EngONSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EngONSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_EngONSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_EngONSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_FirewallSrlComSrvDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_FirewallSrlComSrvDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_FirewallSrlComSrvDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_FirewallSrlComSrvDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_HysAddSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_HysAddSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_HysAddSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_HysAddSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_HystCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_HystCompSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_HystCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_HystCompSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_IgnCnt_Cnt_u16(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_IgnCnt_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_IgnCnt_Cnt_u16() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_IgnCnt_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface9_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_KinIntDiagSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_KinIntDiagSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_LimitSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_LimitSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_LimitSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_LimitSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_LrnPnCenterEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_LrnPnCenterEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_LrnPnCenterEnable_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_LrnPnCenterEnable_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_MfgDiagInhibit_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MfgDiagInhibit_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MfgDiagInhibit_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MfgDiagInhibit_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_ModIdxSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ModIdxSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_MultIgnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_MultIgnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_NxtrMEC_Cnt_enum(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_NxtrMEC_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_NxtrMEC_Cnt_enum() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_NxtrMEC_Cnt_enum.value)

#  define Rte_IWrite_CDDInterface9_Per1_OscTrajEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_OscTrajEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_OscTrajEnable_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_OscTrajEnable_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_ParkAstSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ParkAstSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_PosTrajEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_PosTrajEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_PosTrajEnable_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_PosTrajEnable_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_PullCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_PullCompSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_PullCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_PullCompSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_ReturnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ReturnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ReturnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ReturnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_SrlComSvcDft_Cnt_b32(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_SrlComSvcDft_Cnt_b32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_SrlComSvcDft_Cnt_b32() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IWrite_CDDInterface9_Per1_TcFlashErrors_Cnt_u08(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcFlashErrors_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_TcFlashErrors_Cnt_u08() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcFlashErrors_Cnt_u08.value)

#  define Rte_IWrite_CDDInterface9_Per1_TcFlashVerify_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcFlashVerify_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_TcFlashVerify_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcFlashVerify_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_TcReflashActive_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcReflashActive_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_TcReflashActive_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TcReflashActive_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_ThermalDCSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_TrqRmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface9_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_WhlImbRejSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface9_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Sa_CDDInterface9_CDDInterface9_Per1.Rte_WhlImbRejSrlComSvcDft_Cnt_lgc.value)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CDDINTERFACE9_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Init1(void);

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Init2(void);

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Per1(void);

FUNC(Std_ReturnType, RTE_SA_CDDINTERFACE9_APPL_CODE) FirstStartPort_GetFirstStart(void);

FUNC(Std_ReturnType, RTE_SA_CDDINTERFACE9_APPL_CODE) FirstStartPort_ResetFirstStart(void);

FUNC(Std_ReturnType, RTE_SA_CDDINTERFACE9_APPL_CODE) FirstStartPort_SetFirstStart(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE9_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_FirstStartInterface_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_CDDInterface9.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE9_H */
