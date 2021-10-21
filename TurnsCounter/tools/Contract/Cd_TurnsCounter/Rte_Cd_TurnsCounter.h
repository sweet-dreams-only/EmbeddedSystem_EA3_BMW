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
 *          File:  Rte_Cd_TurnsCounter.h
 *     Workspace:  C:/SynergyWorkArea/Working/TurnsCounter/autosar
 *     SW-C Type:  Cd_TurnsCounter
 *  Generated at:  Tue Jun 28 14:13:58 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Cd_TurnsCounter> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_TURNSCOUNTER_H
# define _RTE_CD_TURNSCOUNTER_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Cd_TurnsCounter, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AlignedCumMtrPosMRF_Deg_f32 ((Float)0)
# define Rte_InitValue_EnergyModeState_Cnt_enum ((EnergyModeStateType)0u)
# define Rte_InitValue_HwTargetAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_ICMMtrPosMRF_Deg_f32 ((Float)0)
# define Rte_InitValue_MotorVelMRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_RackCenterComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TCFlash_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TCMtrPosOffsMRF_Deg_f32 ((Float)0)
# define Rte_InitValue_TcActivePN_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_TcActivePNVldCnt_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_TcFlashErrors_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_TcFlashVerify_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TurnsCntrValidity_Cnt_enum ((TurnsCntrValStateType)0u)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_EOLTurnsCntrCals_SetRamBlockStatus(Boolean RamBlockStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_EOLTurnsCntrCals_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_EOLTurnsCntrCals_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_SystemTime_GetSystemTime_uS_u32(P2VAR(UInt32, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) CurrentTime);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_TcDataCh_SetupEB(P2CONST(Spi_DataType, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_DATA) SrcDataBufferPtr, P2CONST(Spi_DataType, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_DATA) DesDataBufferPtr, Spi_NumberOfDataType Length);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_TcDataCh_SetupEB(P2CONST(Spi_DataPtr, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_DATA) SrcDataBufferPtr, P2CONST(Spi_DataPtr, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_DATA) DesDataBufferPtr, Spi_NumberOfDataType Length);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_TcDataSeq_AsyncTransmit(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_TcDataSeq_GetSequenceResult(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_TurnsCounter_TcMCLR_OP_SET(IoHwAb_BoolType signal);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_TurnsCounter_Init1_EnergyModeState_Cnt_enum() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Init1_EnergyModeState_Cnt_enum->value)

# define Rte_IWrite_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_TurnsCounter->TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32() \
  (&Rte_Inst_Cd_TurnsCounter->TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32->value)

# define Rte_IWrite_TurnsCounter_Init1_TcActivePN_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_TurnsCounter->TurnsCounter_Init1_TcActivePN_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_TurnsCounter_Init1_TcActivePN_Cnt_u32() \
  (&Rte_Inst_Cd_TurnsCounter->TurnsCounter_Init1_TcActivePN_Cnt_u32->value)

# define Rte_IRead_TurnsCounter_Per1_AlignedCumMtrPosMRF_Deg_f32() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_AlignedCumMtrPosMRF_Deg_f32->value)

# define Rte_IRead_TurnsCounter_Per1_EnergyModeState_Cnt_enum() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_EnergyModeState_Cnt_enum->value)

# define Rte_IRead_TurnsCounter_Per1_HwTargetAuthority_Uls_f32() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_HwTargetAuthority_Uls_f32->value)

# define Rte_IRead_TurnsCounter_Per1_ICMMtrPosMRF_Deg_f32() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_ICMMtrPosMRF_Deg_f32->value)

# define Rte_IRead_TurnsCounter_Per1_MotorVelMRF_MtrRadpS_f32() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_MotorVelMRF_MtrRadpS_f32->value)

# define Rte_IRead_TurnsCounter_Per1_RackCenterComplete_Cnt_lgc() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_RackCenterComplete_Cnt_lgc->value)

# define Rte_IRead_TurnsCounter_Per1_TCFlash_Cnt_lgc() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TCFlash_Cnt_lgc->value)

# define Rte_IRead_TurnsCounter_Per1_TcFlashErrors_Cnt_u08() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TcFlashErrors_Cnt_u08->value)

# define Rte_IRead_TurnsCounter_Per1_TcFlashVerify_Cnt_lgc() \
  (Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TcFlashVerify_Cnt_lgc->value)

# define Rte_IWrite_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32(data) \
  ( \
  Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32() \
  (&Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32->value)

# define Rte_IWrite_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32() \
  (&Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32->value)

# define Rte_IWrite_TurnsCounter_Per1_TcActivePN_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TcActivePN_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_TurnsCounter_Per1_TcActivePN_Cnt_u32() \
  (&Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TcActivePN_Cnt_u32->value)

# define Rte_IWrite_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum(data) \
  ( \
  Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum() \
  (&Rte_Inst_Cd_TurnsCounter->TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLTurnsCntrCals_SetRamBlockStatus Rte_Call_Cd_TurnsCounter_EOLTurnsCntrCals_SetRamBlockStatus
# define Rte_Call_EOLTurnsCntrCals_WriteBlock Rte_Call_Cd_TurnsCounter_EOLTurnsCntrCals_WriteBlock
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Cd_TurnsCounter_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Cd_TurnsCounter_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16 Rte_Call_Cd_TurnsCounter_SystemTime_DtrmnElapsedTime_uS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Cd_TurnsCounter_SystemTime_GetSystemTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_uS_u32 Rte_Call_Cd_TurnsCounter_SystemTime_GetSystemTime_uS_u32
# define Rte_Call_TcDataCh_SetupEB Rte_Call_Cd_TurnsCounter_TcDataCh_SetupEB
# define Rte_Call_TcDataSeq_AsyncTransmit Rte_Call_Cd_TurnsCounter_TcDataSeq_AsyncTransmit
# define Rte_Call_TcDataSeq_GetSequenceResult Rte_Call_Cd_TurnsCounter_TcDataSeq_GetSequenceResult
# define Rte_Call_TcMCLR_OP_SET Rte_Call_Cd_TurnsCounter_TcMCLR_OP_SET


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_EOLTurnsCntrCals() (Rte_Inst_Cd_TurnsCounter->Pim_EOLTurnsCntrCals)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   EOLTurnsCntrCals_Datatype *Rte_Pim_EOLTurnsCntrCals(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_CD_TURNSCOUNTER_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TcEOLCals_Scom_ClearTcEOLCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearTcEOLCals> of PortPrototype <TcEOLCals_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TcEOLCals_Scom_ClearTcEOLCals(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_ClearTcEOLCals(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TcEOLCals_Scom_ReadTcEOLCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadTcEOLCals> of PortPrototype <TcEOLCals_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TcEOLCals_Scom_ReadTcEOLCals(EOLTurnsCntrCals_Datatype *TcEOLCalsPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_ReadTcEOLCals(P2VAR(EOLTurnsCntrCals_Datatype, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcEOLCalsPtr);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TcEOLCals_Scom_SetTcEOLCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetTcEOLCals> of PortPrototype <TcEOLCals_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType TcEOLCals_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TcEOLCals_Scom_RequestDataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   EnergyModeStateType Rte_IRead_TurnsCounter_Init1_EnergyModeState_Cnt_enum(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32(void)
 *   void Rte_IWrite_TurnsCounter_Init1_TcActivePN_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_TurnsCounter_Init1_TcActivePN_Cnt_u32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TcMCLR_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_TcDataCh_SetupEB(const Spi_DataType *SrcDataBufferPtr, const Spi_DataType *DesDataBufferPtr, Spi_NumberOfDataType Length)
# else
 *   Std_ReturnType Rte_Call_TcDataCh_SetupEB(const Spi_DataPtr *SrcDataBufferPtr, const Spi_DataPtr *DesDataBufferPtr, Spi_NumberOfDataType Length)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_TurnsCounter_Per1_AlignedCumMtrPosMRF_Deg_f32(void)
 *   EnergyModeStateType Rte_IRead_TurnsCounter_Per1_EnergyModeState_Cnt_enum(void)
 *   Float Rte_IRead_TurnsCounter_Per1_HwTargetAuthority_Uls_f32(void)
 *   Float Rte_IRead_TurnsCounter_Per1_ICMMtrPosMRF_Deg_f32(void)
 *   Float Rte_IRead_TurnsCounter_Per1_MotorVelMRF_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_TurnsCounter_Per1_RackCenterComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_TurnsCounter_Per1_TCFlash_Cnt_lgc(void)
 *   UInt8 Rte_IRead_TurnsCounter_Per1_TcFlashErrors_Cnt_u08(void)
 *   Boolean Rte_IRead_TurnsCounter_Per1_TcFlashVerify_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32(void)
 *   void Rte_IWrite_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32(void)
 *   void Rte_IWrite_TurnsCounter_Per1_TcActivePN_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_TurnsCounter_Per1_TcActivePN_Cnt_u32(void)
 *   void Rte_IWrite_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum(TurnsCntrValStateType data)
 *   TurnsCntrValStateType *Rte_IWriteRef_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_TcMCLR_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TcDataSeq_AsyncTransmit(void)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TcDataSeq_GetSequenceResult(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Spi_Seq_SPI_SEQ_CANCELLED, RTE_E_Spi_Seq_SPI_SEQ_FAILED, RTE_E_Spi_Seq_SPI_SEQ_PENDING
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Scom_PartNumSvc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PartNumSvc> of PortPrototype <TurnsCounter_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void TurnsCounter_Scom_PartNumSvc(UInt8 *TcPrgStatePtr)
# else
 *   void TurnsCounter_Scom_PartNumSvc(TcPartNumType *TcPrgStatePtr)
# endif
 *
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(UInt8, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr);
# else
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(TcPartNumType, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr);
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Scom_ResetTC
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTC> of PortPrototype <TurnsCounter_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TurnsCounter_Scom_ResetTC(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_ResetTC(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_TxConfirmation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SequenceEnd> of PortPrototype <Spi_Notification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TurnsCounter_TxConfirmation(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_TxConfirmation(void);

# define RTE_STOP_SEC_CD_TURNSCOUNTER_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_DigitalOut_E_NOT_OK (1u)

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# define RTE_E_Spi_Seq_SPI_SEQ_CANCELLED (3u)

# define RTE_E_Spi_Seq_SPI_SEQ_FAILED (2u)

# define RTE_E_Spi_Seq_SPI_SEQ_PENDING (1u)

# define RTE_E_TcEOLCals_Scom_RequestDataOutOfRange (34u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1467131520
#    error "The magic number of the generated file <C:/SynergyWorkArea/Working/TurnsCounter/tools/contract/Cd_TurnsCounter/Rte_Cd_TurnsCounter.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1467131520
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CD_TURNSCOUNTER_H */
