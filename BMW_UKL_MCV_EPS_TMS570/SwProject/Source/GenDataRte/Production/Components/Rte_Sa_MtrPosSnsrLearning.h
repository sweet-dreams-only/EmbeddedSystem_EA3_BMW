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
 *          File:  Components/Rte_Sa_MtrPosSnsrLearning.h
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_410PR/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Sun Jan 27 10:44:12 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_MTRPOSSNSRLEARNING_H
# define _RTE_SA_MTRPOSSNSRLEARNING_H

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

#  define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPosSnsrLearning_Cos1RTAmpRec_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPosSnsrLearning_Cos1RTOffset_Volts_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPosSnsrLearning_Cos2RTAmpRec_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPosSnsrLearning_Cos2RTOffset_Volts_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPosSnsrLearning_Sin1RTAmpRec_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPosSnsrLearning_Sin1RTOffset_Volts_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPosSnsrLearning_Sin2RTAmpRec_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_MtrPosSnsrLearning_Sin2RTOffset_Volts_f32;

#  define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Cos1RTAmpRec_Uls_f32 (0.0F)
#  define Rte_InitValue_Cos1RTOffset_Volts_f32 (0.0F)
#  define Rte_InitValue_Cos1Theta_Volts_f32 (0.0F)
#  define Rte_InitValue_Cos2RTAmpRec_Uls_f32 (0.0F)
#  define Rte_InitValue_Cos2RTOffset_Volts_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLCos1AmpRec_Uls_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLCos1GainCorr_Uls_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLCos1OffsetCorr_Volts_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLCos1Offset_Volts_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLCos2AmpRec_Uls_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLCos2Offset_Volts_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLSin1AmpRec_Uls_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLSin1GainCorr_Uls_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLSin1OffsetCorr_Volts_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLSin1Offset_Volts_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLSin2AmpRec_Uls_f32 (0.0F)
#  define Rte_InitValue_EOLMtrSnsrAdjParam_EOLSin2Offset_Volts_f32 (0.0F)
#  define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_MtrPosMech_Rev_f32 (0.0F)
#  define Rte_InitValue_MtrPosMech2_Rev_f32 (0.0F)
#  define Rte_InitValue_Sin1RTAmpRec_Uls_f32 (0.0F)
#  define Rte_InitValue_Sin1RTOffset_Volts_f32 (0.0F)
#  define Rte_InitValue_Sin1Theta_Volts_f32 (0.0F)
#  define Rte_InitValue_Sin2RTAmpRec_Uls_f32 (0.0F)
#  define Rte_InitValue_Sin2RTOffset_Volts_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd7_SystemState7_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

# define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
# include "MemMap.h"

extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Cos1GainCorr_Uls_f32;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Cos1MaxSV_Volts_s2p29;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Cos1MinSV_Volts_s2p29;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Cos1OffsetCorr_Volts_f32;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Cos2MaxSV_Volts_s2p29;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Cos2MinSV_Volts_s2p29;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_CosSin1NomRatio_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_CosSin2NomRatio_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_RTToNomHighLmt_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_RTToNomLowLmt_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Sin1GainCorr_Uls_f32;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Sin1MaxSV_Volts_s2p29;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Sin1MinSV_Volts_s2p29;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Sin1OffsetCorr_Volts_f32;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Sin2MaxSV_Volts_s2p29;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_Sin2MinSV_Volts_s2p29;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_SinCos1NomRatio_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Irv_MtrPosSnsrLearning_SinCos2NomRatio_Uls_f32;

# define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
# include "MemMap.h"


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_7, RTE_VAR_NOINIT) Rte_Task_Init_7;

extern VAR(Rte_tsTask_2ms_7, RTE_VAR_NOINIT) Rte_Task_2ms_7;

#  define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLCos1AmpRec_Uls_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos1AmpRec_Uls_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLCos1GainCorr_Uls_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos1GainCorr_Uls_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLCos1OffsetCorr_Volts_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos1OffsetCorr_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLCos1Offset_Volts_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos1Offset_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLCos2AmpRec_Uls_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos2AmpRec_Uls_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLCos2Offset_Volts_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLCos2Offset_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLSin1AmpRec_Uls_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin1AmpRec_Uls_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLSin1GainCorr_Uls_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin1GainCorr_Uls_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLSin1OffsetCorr_Volts_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin1OffsetCorr_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLSin1Offset_Volts_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin1Offset_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLSin2AmpRec_Uls_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin2AmpRec_Uls_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Init1_EOLMtrSnsrAdjParam_EOLSin2Offset_Volts_f32() \
  (Rte_Task_Init_7.Rte_TB.Rte_I_MtrPos_EOLMtrSnsrAdjParam_EOLSin2Offset_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_Cos1Theta_Volts_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_Cos1Theta_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_EOLMtrSnsrAdjParam_EOLCos1Offset_Volts_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_EOLMtrSnsrAdjParam_EOLCos1Offset_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_EOLMtrSnsrAdjParam_EOLCos2Offset_Volts_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_EOLMtrSnsrAdjParam_EOLCos2Offset_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_EOLMtrSnsrAdjParam_EOLSin1AmpRec_Uls_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_EOLMtrSnsrAdjParam_EOLSin1AmpRec_Uls_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_EOLMtrSnsrAdjParam_EOLSin1Offset_Volts_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_EOLMtrSnsrAdjParam_EOLSin1Offset_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_EOLMtrSnsrAdjParam_EOLSin2AmpRec_Uls_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_EOLMtrSnsrAdjParam_EOLSin2AmpRec_Uls_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_EOLMtrSnsrAdjParam_EOLSin2Offset_Volts_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_EOLMtrSnsrAdjParam_EOLSin2Offset_Volts_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_MRFMtrVel_MtrRadpS_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_MtrPosMech2_Rev_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_MtrPosMech2_Rev_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_MtrPosMech_Rev_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_MtrPosMech_Rev_f32.value)

#  define Rte_IRead_MtrPosSnsrLearning_Per1_Sin1Theta_Volts_f32() \
  (Rte_Task_2ms_7.Rte_RB.Rte_Sa_MtrPosSnsrLearning_MtrPosSnsrLearning_Per1.Rte_Sin1Theta_Volts_f32.value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Cos1RTAmpRec_Uls_f32 Rte_Write_Sa_MtrPosSnsrLearning_Cos1RTAmpRec_Uls_f32
#  define Rte_Write_Sa_MtrPosSnsrLearning_Cos1RTAmpRec_Uls_f32(data) (Rte_MtrPosSnsrLearning_Cos1RTAmpRec_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Cos1RTOffset_Volts_f32 Rte_Write_Sa_MtrPosSnsrLearning_Cos1RTOffset_Volts_f32
#  define Rte_Write_Sa_MtrPosSnsrLearning_Cos1RTOffset_Volts_f32(data) (Rte_MtrPosSnsrLearning_Cos1RTOffset_Volts_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Cos2RTAmpRec_Uls_f32 Rte_Write_Sa_MtrPosSnsrLearning_Cos2RTAmpRec_Uls_f32
#  define Rte_Write_Sa_MtrPosSnsrLearning_Cos2RTAmpRec_Uls_f32(data) (Rte_MtrPosSnsrLearning_Cos2RTAmpRec_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Cos2RTOffset_Volts_f32 Rte_Write_Sa_MtrPosSnsrLearning_Cos2RTOffset_Volts_f32
#  define Rte_Write_Sa_MtrPosSnsrLearning_Cos2RTOffset_Volts_f32(data) (Rte_MtrPosSnsrLearning_Cos2RTOffset_Volts_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Sin1RTAmpRec_Uls_f32 Rte_Write_Sa_MtrPosSnsrLearning_Sin1RTAmpRec_Uls_f32
#  define Rte_Write_Sa_MtrPosSnsrLearning_Sin1RTAmpRec_Uls_f32(data) (Rte_MtrPosSnsrLearning_Sin1RTAmpRec_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Sin1RTOffset_Volts_f32 Rte_Write_Sa_MtrPosSnsrLearning_Sin1RTOffset_Volts_f32
#  define Rte_Write_Sa_MtrPosSnsrLearning_Sin1RTOffset_Volts_f32(data) (Rte_MtrPosSnsrLearning_Sin1RTOffset_Volts_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Sin2RTAmpRec_Uls_f32 Rte_Write_Sa_MtrPosSnsrLearning_Sin2RTAmpRec_Uls_f32
#  define Rte_Write_Sa_MtrPosSnsrLearning_Sin2RTAmpRec_Uls_f32(data) (Rte_MtrPosSnsrLearning_Sin2RTAmpRec_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Sin2RTOffset_Volts_f32 Rte_Write_Sa_MtrPosSnsrLearning_Sin2RTOffset_Volts_f32
#  define Rte_Write_Sa_MtrPosSnsrLearning_Sin2RTOffset_Volts_f32(data) (Rte_MtrPosSnsrLearning_Sin2RTOffset_Volts_f32 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd7_SystemState7_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(UInt8 parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_LearnedMtrSnsrParam_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((UInt8)9, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_IOHWAB7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWAB7_APPL_CODE) IoHwAb_InputInvCosTheta2_V_f32(P2VAR(Float, AUTOMATIC, RTE_IOHWAB7_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWAB7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MtrPos_InvCosTheta2_V_f32 IoHwAb_InputInvCosTheta2_V_f32
#  define RTE_START_SEC_IOHWAB7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWAB7_APPL_CODE) IoHwAb_InputInvSinTheta2_V_f32(P2VAR(Float, AUTOMATIC, RTE_IOHWAB7_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWAB7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MtrPos_InvSinTheta2_V_f32 IoHwAb_InputInvSinTheta2_V_f32
#  define RTE_START_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR7_APPL_CODE) NxtrDiagMgr7_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR7_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr7_GetNTCFailed


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Cos1GainCorr_Uls_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos1GainCorr_Uls_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Cos1MaxSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos1MaxSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Cos1MinSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos1MinSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Cos1OffsetCorr_Volts_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos1OffsetCorr_Volts_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Cos2MaxSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos2MaxSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Cos2MinSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos2MinSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_CosSin1NomRatio_Uls_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_CosSin1NomRatio_Uls_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_CosSin2NomRatio_Uls_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_CosSin2NomRatio_Uls_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_RTToNomHighLmt_Uls_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_RTToNomHighLmt_Uls_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_RTToNomLowLmt_Uls_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_RTToNomLowLmt_Uls_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Sin1GainCorr_Uls_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin1GainCorr_Uls_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Sin1MaxSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin1MaxSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Sin1MinSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin1MinSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Sin1OffsetCorr_Volts_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin1OffsetCorr_Volts_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Sin2MaxSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin2MaxSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_Sin2MinSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin2MinSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_SinCos1NomRatio_Uls_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_SinCos1NomRatio_Uls_f32 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Init1_SinCos2NomRatio_Uls_f32(data) \
  (Rte_Irv_MtrPosSnsrLearning_SinCos2NomRatio_Uls_f32 = (data))

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Cos1GainCorr_Uls_f32() \
  Rte_Irv_MtrPosSnsrLearning_Cos1GainCorr_Uls_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Cos1MaxSV_Volts_s2p29() \
  Rte_Irv_MtrPosSnsrLearning_Cos1MaxSV_Volts_s2p29

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Cos1MinSV_Volts_s2p29() \
  Rte_Irv_MtrPosSnsrLearning_Cos1MinSV_Volts_s2p29

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Cos1OffsetCorr_Volts_f32() \
  Rte_Irv_MtrPosSnsrLearning_Cos1OffsetCorr_Volts_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Cos2MaxSV_Volts_s2p29() \
  Rte_Irv_MtrPosSnsrLearning_Cos2MaxSV_Volts_s2p29

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Cos2MinSV_Volts_s2p29() \
  Rte_Irv_MtrPosSnsrLearning_Cos2MinSV_Volts_s2p29

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_CosSin1NomRatio_Uls_f32() \
  Rte_Irv_MtrPosSnsrLearning_CosSin1NomRatio_Uls_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_CosSin2NomRatio_Uls_f32() \
  Rte_Irv_MtrPosSnsrLearning_CosSin2NomRatio_Uls_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_RTToNomHighLmt_Uls_f32() \
  Rte_Irv_MtrPosSnsrLearning_RTToNomHighLmt_Uls_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_RTToNomLowLmt_Uls_f32() \
  Rte_Irv_MtrPosSnsrLearning_RTToNomLowLmt_Uls_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Sin1GainCorr_Uls_f32() \
  Rte_Irv_MtrPosSnsrLearning_Sin1GainCorr_Uls_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Sin1MaxSV_Volts_s2p29() \
  Rte_Irv_MtrPosSnsrLearning_Sin1MaxSV_Volts_s2p29

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Sin1MinSV_Volts_s2p29() \
  Rte_Irv_MtrPosSnsrLearning_Sin1MinSV_Volts_s2p29

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Sin1OffsetCorr_Volts_f32() \
  Rte_Irv_MtrPosSnsrLearning_Sin1OffsetCorr_Volts_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Sin2MaxSV_Volts_s2p29() \
  Rte_Irv_MtrPosSnsrLearning_Sin2MaxSV_Volts_s2p29

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_Sin2MinSV_Volts_s2p29() \
  Rte_Irv_MtrPosSnsrLearning_Sin2MinSV_Volts_s2p29

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_SinCos1NomRatio_Uls_f32() \
  Rte_Irv_MtrPosSnsrLearning_SinCos1NomRatio_Uls_f32

#  define Rte_IrvRead_MtrPosSnsrLearning_Per1_SinCos2NomRatio_Uls_f32() \
  Rte_Irv_MtrPosSnsrLearning_SinCos2NomRatio_Uls_f32

#  define Rte_IrvWrite_MtrPosSnsrLearning_Per1_Cos1MaxSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos1MaxSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Per1_Cos1MinSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos1MinSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Per1_Cos2MaxSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos2MaxSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Per1_Cos2MinSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Cos2MinSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Per1_Sin1MaxSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin1MaxSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Per1_Sin1MinSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin1MinSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Per1_Sin2MaxSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin2MaxSV_Volts_s2p29 = (data))

#  define Rte_IrvWrite_MtrPosSnsrLearning_Per1_Sin2MinSV_Volts_s2p29(data) \
  (Rte_Irv_MtrPosSnsrLearning_Sin2MinSV_Volts_s2p29 = (data))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(MtrSnsrLearned_DataType, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_MtrPosSnsrLearning_MtrSnsrLearnedParam;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_MtrSnsrLearnedParam() \
  (&Rte_MtrPosSnsrLearning_MtrSnsrLearnedParam)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_MTRPOSSNSRLEARNING_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOSSNSRLEARNING_APPL_CODE) MtrPosSnsrLearning_Init1(void);

FUNC(void, RTE_SA_MTRPOSSNSRLEARNING_APPL_CODE) MtrPosSnsrLearning_Per1(void);

FUNC(void, RTE_SA_MTRPOSSNSRLEARNING_APPL_CODE) MtrPosSnsrLearning_Trns1(void);

# define RTE_STOP_SEC_SA_MTRPOSSNSRLEARNING_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_MtrPos_deprecated_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1359305166
#    error "The magic number of the generated file <C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_410PR/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Sa_MtrPosSnsrLearning.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1359305166
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRPOSSNSRLEARNING_H */
