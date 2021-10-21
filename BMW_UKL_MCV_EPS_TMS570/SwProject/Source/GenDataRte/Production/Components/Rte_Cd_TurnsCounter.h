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
 *          File:  Components/Rte_Cd_TurnsCounter.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:22 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_TURNSCOUNTER_H
# define _RTE_CD_TURNSCOUNTER_H

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

#  define Rte_InitValue_AlignedCumMtrPosMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_EnergyModeState_Cnt_enum (0U)
#  define Rte_InitValue_HwTargetAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_ICMMtrPosMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_LTRackCntrComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_LTVehCenterComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_MotorVelMRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_RackCenterComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_TCFlash_Cnt_lgc (FALSE)
#  define Rte_InitValue_TCMtrPosOffsMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_TcActivePN_Cnt_u32 (0U)
#  define Rte_InitValue_TcActivePNVldCnt_Cnt_u32 (0U)
#  define Rte_InitValue_TcFlashErrors_Cnt_u08 (0U)
#  define Rte_InitValue_TcFlashVerify_Cnt_lgc (FALSE)
#  define Rte_InitValue_TurnsCntrValidity_Cnt_enum (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitB_7, RTE_VAR_NOINIT) Rte_Task_InitB_7;

extern VAR(Rte_tsTask_10ms_7, RTE_VAR_NOINIT) Rte_Task_10ms_7;

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

#  define Rte_IRead_TurnsCounter_Init1_EnergyModeState_Cnt_enum() \
  (Rte_Task_InitB_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Init1.Rte_EnergyModeState_Cnt_enum.value)

#  define Rte_IWrite_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32(data) \
  ( \
    Rte_Task_InitB_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Init1.Rte_TcActivePNVldCnt_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32() \
  (&Rte_Task_InitB_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Init1.Rte_TcActivePNVldCnt_Cnt_u32.value)

#  define Rte_IWrite_TurnsCounter_Init1_TcActivePN_Cnt_u32(data) \
  ( \
    Rte_Task_InitB_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Init1.Rte_TcActivePN_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_TurnsCounter_Init1_TcActivePN_Cnt_u32() \
  (&Rte_Task_InitB_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Init1.Rte_TcActivePN_Cnt_u32.value)

#  define Rte_IRead_TurnsCounter_Per1_AlignedCumMtrPosMRF_Deg_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_AlignedCumMtrPosMRF_Deg_f32.value)

#  define Rte_IRead_TurnsCounter_Per1_EnergyModeState_Cnt_enum() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_EnergyModeState_Cnt_enum.value)

#  define Rte_IRead_TurnsCounter_Per1_HwTargetAuthority_Uls_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_HwTargetAuthority_Uls_f32.value)

#  define Rte_IRead_TurnsCounter_Per1_ICMMtrPosMRF_Deg_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_ICMMtrPosMRF_Deg_f32.value)

#  define Rte_IRead_TurnsCounter_Per1_LTRackCntrComplete_Cnt_lgc() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_LTRackCntrComplete_Cnt_lgc.value)

#  define Rte_IRead_TurnsCounter_Per1_LTVehCenterComplete_Cnt_lgc() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_LTVehCenterComplete_Cnt_lgc.value)

#  define Rte_IRead_TurnsCounter_Per1_MotorVelMRF_MtrRadpS_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_MotorVelMRF_MtrRadpS_f32.value)

#  define Rte_IRead_TurnsCounter_Per1_RackCenterComplete_Cnt_lgc() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_RackCenterComplete_Cnt_lgc.value)

#  define Rte_IRead_TurnsCounter_Per1_TCFlash_Cnt_lgc() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TCFlash_Cnt_lgc.value)

#  define Rte_IRead_TurnsCounter_Per1_TcFlashErrors_Cnt_u08() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcFlashErrors_Cnt_u08.value)

#  define Rte_IRead_TurnsCounter_Per1_TcFlashVerify_Cnt_lgc() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcFlashVerify_Cnt_lgc.value)

#  define Rte_IWrite_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32(data) \
  ( \
    Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TCMtrPosOffsMRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32() \
  (&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TCMtrPosOffsMRF_Deg_f32.value)

#  define Rte_IWrite_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcActivePNVldCnt_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32() \
  (&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcActivePNVldCnt_Cnt_u32.value)

#  define Rte_IWrite_TurnsCounter_Per1_TcActivePN_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcActivePN_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_TurnsCounter_Per1_TcActivePN_Cnt_u32() \
  (&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TcActivePN_Cnt_u32.value)

#  define Rte_IWrite_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum(data) \
  ( \
    Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TurnsCntrValidity_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum() \
  (&Rte_Task_10ms_7.Rte_RB.Rte_Cd_TurnsCounter_TurnsCounter_Per1.Rte_TurnsCntrValidity_Cnt_enum.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(UInt8 parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLTurnsCntrCals_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((UInt8)10, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLTurnsCntrCals_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)10, arg1))
#  define RTE_START_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR7_APPL_CODE) NxtrDiagMgr7_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR7_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr7_SetNTCStatus
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_uS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(arg1, arg2) (DtrmnElapsedTime_uS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_uS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_uS_u32(arg1) (GetSystemTime_uS_u32(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SPINXT_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SPINXT_APPL_CODE) SpiNxt_SetupEB(Spi_ChannelType parg0, P2CONST(Spi_DataType, AUTOMATIC, RTE_SPINXT_APPL_DATA) SrcDataBufferPtr, P2CONST(Spi_DataType, AUTOMATIC, RTE_SPINXT_APPL_DATA) DesDataBufferPtr, Spi_NumberOfDataType Length);
# else
FUNC(void, RTE_SPINXT_APPL_CODE) SpiNxt_SetupEB(Spi_ChannelType parg0, P2CONST(Spi_DataPtr, AUTOMATIC, RTE_SPINXT_APPL_DATA) SrcDataBufferPtr, P2CONST(Spi_DataPtr, AUTOMATIC, RTE_SPINXT_APPL_DATA) DesDataBufferPtr, Spi_NumberOfDataType Length);
# endif
#  define RTE_STOP_SEC_SPINXT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TcDataCh_SetupEB(arg1, arg2, arg3) (SpiNxt_SetupEB((Spi_ChannelType)0, arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SPINXT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SPINXT_APPL_CODE) SpiNxt_AsyncTransmit(Spi_SequenceType parg0);
#  define RTE_STOP_SEC_SPINXT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TcDataSeq_AsyncTransmit() (SpiNxt_AsyncTransmit((Spi_SequenceType)0), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SPINXT_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SPINXT_APPL_CODE) SpiNxt_GetSequenceResult(Spi_SequenceType parg0);
#  define RTE_STOP_SEC_SPINXT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TcDataSeq_GetSequenceResult() (SpiNxt_GetSequenceResult((Spi_SequenceType)0))
#  define RTE_START_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWABSTRACTION_APPL_CODE) IoHwAb_SetTcMCLR(IoHwAb_BoolType signal);
#  define RTE_STOP_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TcMCLR_OP_SET IoHwAb_SetTcMCLR


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(EOLTurnsCntrCals_Datatype, RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP) Rte_TurnsCounter_EOLTurnsCntrCals;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_EOLTurnsCntrCals() \
  (&Rte_TurnsCounter_EOLTurnsCntrCals)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CD_TURNSCOUNTER_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_ClearTcEOLCals(void);

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_ReadTcEOLCals(P2VAR(EOLTurnsCntrCals_Datatype, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcEOLCalsPtr);

FUNC(Std_ReturnType, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8);

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Init1(void);

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Per1(void);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(UInt8, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr);
# else
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(TcPartNumType, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr);
# endif

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_ResetTC(void);

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_TxConfirmation(void);

# define RTE_STOP_SEC_CD_TURNSCOUNTER_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DigitalOut_E_NOT_OK (1U)

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

#  define RTE_E_Spi_Seq_SPI_SEQ_CANCELLED (3U)

#  define RTE_E_Spi_Seq_SPI_SEQ_FAILED (2U)

#  define RTE_E_Spi_Seq_SPI_SEQ_PENDING (1U)

#  define RTE_E_TcEOLCals_Scom_RequestDataOutOfRange (34U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Cd_TurnsCounter.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CD_TURNSCOUNTER_H */
