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
 *          File:  Rte_Ap_AbsHwPos.h
 *     Workspace:  C:/ccm_wa/EPS/570/I490/AbsHwPos/autosar
 *     SW-C Type:  Ap_AbsHwPos
 *  Generated at:  Thu Jun 27 09:06:46 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_AbsHwPos> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ABSHWPOS_H
# define _RTE_AP_ABSHWPOS_H

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

typedef P2CONST(struct Rte_CDS_Ap_AbsHwPos, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AlignedCumMtrPosMRF_Deg_f32 (0.0F)
# define Rte_InitValue_AlignedHwPos_HwDeg_f32 (0.0F)
# define Rte_InitValue_DefeatKinIntTest_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsDefHwPos_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsHwPosDis_Cnt_lgc (FALSE)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
# define Rte_InitValue_HwTargetAuthority_Uls_f32 (0.0F)
# define Rte_InitValue_ICMMtrPosMRF_Deg_f32 (0.0F)
# define Rte_InitValue_ICMRevOffsetCRF_Rev_s16 (0)
# define Rte_InitValue_ICMRevOffsetStatus_Cnt_u08 (8U)
# define Rte_InitValue_LTRckCntrComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_LTVehCenterComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_Polarity_Cnt_s08 (0)
# define Rte_InitValue_RackCenter_HwDeg_f32 (0.0F)
# define Rte_InitValue_RacktoVehCntrOffset_Cnt_u16 (4095U)
# define Rte_InitValue_RevOffsetState_Cnt_u08 (0U)
# define Rte_InitValue_SrlComHwPos_HwDeg_f32 (0.0F)
# define Rte_InitValue_TCMtrPosOffsMRF_Deg_f32 (0.0F)
# define Rte_InitValue_TorqueCmdCRF_MtrNm_f32 (0.0F)
# define Rte_InitValue_TurnsCntrValidity_Cnt_enum (0U)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_AbsHwPos_DiagStsDefHwPos_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_AbsHwPos_LTRckCntrComplete_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_AbsHwPos_RackCenter_HwDeg_f32(P2VAR(Float, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_AbsHwPos_LTVehCenterComplete_Cnt_lgc(Boolean data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_Trim_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_Trim_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_LnRkCr_Scom_ResetRckCntrMtrRev(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_LrnEOT_Scom_ResetEOT(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPos_TurnsCounter_Scom_ResetTC(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc->value)

# define Rte_IWrite_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16->value)

# define Rte_IRead_AbsHwPos_Per1_AlignedCumMtrPosMRF_Deg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_AlignedCumMtrPosMRF_Deg_f32->value)

# define Rte_IRead_AbsHwPos_Per1_DiagStsDefHwPos_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_DiagStsDefHwPos_Cnt_lgc->value)

# define Rte_IRead_AbsHwPos_Per1_DiagStsHwPosDis_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_DiagStsHwPosDis_Cnt_lgc->value)

# define Rte_IRead_AbsHwPos_Per1_ICMRevOffsetCRF_Rev_s16() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_ICMRevOffsetCRF_Rev_s16->value)

# define Rte_IRead_AbsHwPos_Per1_ICMRevOffsetStatus_Cnt_u08() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_ICMRevOffsetStatus_Cnt_u08->value)

# define Rte_IRead_AbsHwPos_Per1_LTRckCntrComplete_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_LTRckCntrComplete_Cnt_lgc->value)

# define Rte_IRead_AbsHwPos_Per1_Polarity_Cnt_s08() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_Polarity_Cnt_s08->value)

# define Rte_IRead_AbsHwPos_Per1_RackCenter_HwDeg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_RackCenter_HwDeg_f32->value)

# define Rte_IRead_AbsHwPos_Per1_TCMtrPosOffsMRF_Deg_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_TCMtrPosOffsMRF_Deg_f32->value)

# define Rte_IRead_AbsHwPos_Per1_TorqueCmdCRF_MtrNm_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_TorqueCmdCRF_MtrNm_f32->value)

# define Rte_IRead_AbsHwPos_Per1_TurnsCntrValidity_Cnt_enum() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_TurnsCntrValidity_Cnt_enum->value)

# define Rte_IWrite_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_AlignedHwPos_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_AlignedHwPos_HwDeg_f32->value)

# define Rte_IWrite_AbsHwPos_Per1_HandwheelAuthority_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_HandwheelAuthority_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_HandwheelAuthority_Uls_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IWrite_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_HandwheelPosition_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IWrite_AbsHwPos_Per1_HwTargetAuthority_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_HwTargetAuthority_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_HwTargetAuthority_Uls_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_HwTargetAuthority_Uls_f32->value)

# define Rte_IWrite_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32->value)

# define Rte_IWrite_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16->value)

# define Rte_IWrite_AbsHwPos_Per1_RevOffsetState_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_RevOffsetState_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_RevOffsetState_Cnt_u08() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_RevOffsetState_Cnt_u08->value)

# define Rte_IWrite_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_SrlComHwPos_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32() \
  (&Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per1_SrlComHwPos_HwDeg_f32->value)

# define Rte_IRead_AbsHwPos_Per2_DefeatKinIntTest_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_DefeatKinIntTest_Cnt_lgc->value)

# define Rte_IRead_AbsHwPos_Per2_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_DiagStsDefVehSpd_Cnt_lgc->value)

# define Rte_IRead_AbsHwPos_Per2_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_AbsHwPos->AbsHwPos_Per2_VehicleSpeed_Kph_f32->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_DiagStsDefHwPos_Cnt_lgc Rte_Read_Ap_AbsHwPos_DiagStsDefHwPos_Cnt_lgc
# define Rte_Read_LTRckCntrComplete_Cnt_lgc Rte_Read_Ap_AbsHwPos_LTRckCntrComplete_Cnt_lgc
# define Rte_Read_RackCenter_HwDeg_f32 Rte_Read_Ap_AbsHwPos_RackCenter_HwDeg_f32


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_LTVehCenterComplete_Cnt_lgc Rte_Write_Ap_AbsHwPos_LTVehCenterComplete_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_Trim_WriteBlock Rte_Call_Ap_AbsHwPos_Trim_WriteBlock
# define Rte_Call_LnRkCr_Scom_ResetRckCntrMtrRev Rte_Call_Ap_AbsHwPos_LnRkCr_Scom_ResetRckCntrMtrRev
# define Rte_Call_LrnEOT_Scom_ResetEOT Rte_Call_Ap_AbsHwPos_LrnEOT_Scom_ResetEOT
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_AbsHwPos_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_AbsHwPos_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_AbsHwPos_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_AbsHwPos_SystemTime_GetSystemTime_mS_u32
# define Rte_Call_TurnsCounter_Scom_ResetTC Rte_Call_Ap_AbsHwPos_TurnsCounter_Scom_ResetTC


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_Trim() (Rte_Inst_Ap_AbsHwPos->Pim_Trim)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   AbsHwPosTrim_DataType *Rte_Pim_Trim(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_ABSHWPOS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_AbsHwPos_Init1_LTVehCenterComplete_Cnt_lgc(void)
 *   void Rte_IWrite_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_AbsHwPos_Init1_RacktoVehCntrOffset_Cnt_u16(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AbsHwPos_Per1_AlignedCumMtrPosMRF_Deg_f32(void)
 *   Boolean Rte_IRead_AbsHwPos_Per1_DiagStsDefHwPos_Cnt_lgc(void)
 *   Boolean Rte_IRead_AbsHwPos_Per1_DiagStsHwPosDis_Cnt_lgc(void)
 *   SInt16 Rte_IRead_AbsHwPos_Per1_ICMRevOffsetCRF_Rev_s16(void)
 *   ST_OFFS_QUAD_EPS Rte_IRead_AbsHwPos_Per1_ICMRevOffsetStatus_Cnt_u08(void)
 *   Boolean Rte_IRead_AbsHwPos_Per1_LTRckCntrComplete_Cnt_lgc(void)
 *   SInt8 Rte_IRead_AbsHwPos_Per1_Polarity_Cnt_s08(void)
 *   Float Rte_IRead_AbsHwPos_Per1_RackCenter_HwDeg_f32(void)
 *   Float Rte_IRead_AbsHwPos_Per1_TCMtrPosOffsMRF_Deg_f32(void)
 *   Float Rte_IRead_AbsHwPos_Per1_TorqueCmdCRF_MtrNm_f32(void)
 *   TurnsCntrValStateType Rte_IRead_AbsHwPos_Per1_TurnsCntrValidity_Cnt_enum(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_AlignedHwPos_HwDeg_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_HandwheelAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_HandwheelAuthority_Uls_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_HandwheelPosition_HwDeg_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_HwTargetAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_HwTargetAuthority_Uls_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_ICMMtrPosMRF_Deg_f32(void)
 *   void Rte_IWrite_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_AbsHwPos_Per1_RacktoVehCntrOffset_Cnt_u16(void)
 *   void Rte_IWrite_AbsHwPos_Per1_RevOffsetState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_AbsHwPos_Per1_RevOffsetState_Cnt_u08(void)
 *   void Rte_IWrite_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPos_Per1_SrlComHwPos_HwDeg_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_LnRkCr_Scom_ResetRckCntrMtrRev(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_LrnEOT_Scom_ResetEOT(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Per2
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
 *   Boolean Rte_IRead_AbsHwPos_Per2_DefeatKinIntTest_Cnt_lgc(void)
 *   Boolean Rte_IRead_AbsHwPos_Per2_DiagStsDefVehSpd_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPos_Per2_VehicleSpeed_Kph_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SCom_VehicleSystemStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehicleSystemStatus> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_SCom_VehicleSystemStatus(SInt16 *NCMAbsHwPos_HwDeg_s11p4)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_VehicleSystemStatus(P2VAR(SInt16, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) NCMAbsHwPos_HwDeg_s11p4);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Scom_ClearCenterPosition
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearCenterPosition> of PortPrototype <VehicleCenter_Scom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LTVehCenterComplete_Cnt_lgc(Boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_LnRkCr_Scom_ResetRckCntrMtrRev(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_LrnEOT_Scom_ResetEOT(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TurnsCounter_Scom_ResetTC(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_Scom_ClearCenterPosition(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearCenterPosition(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Scom_ClearRacktoVehCntrOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearRacktoVehCntrOffset> of PortPrototype <RacktoVehCntrOffset_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_Scom_ClearRacktoVehCntrOffset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearRacktoVehCntrOffset(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Scom_SetCenterPosition
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetCenterPosition> of PortPrototype <VehicleCenter_Scom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DiagStsDefHwPos_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_LTRckCntrComplete_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_RackCenter_HwDeg_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LTVehCenterComplete_Cnt_lgc(Boolean data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_Trim_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_VehicleCenter_Scom_E_NOT_OK
 *   RTE_E_VehicleCenter_Scom_E_NOT_OK_OUTOFRANGE
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SetData_SetRacktoVehCntrOffset
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetRacktoVehCntrOffset> of PortPrototype <AbsHwPos_SetData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc);

# define RTE_STOP_SEC_AP_ABSHWPOS_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# define RTE_E_VehicleCenter_Scom_E_NOT_OK (1U)

# define RTE_E_VehicleCenter_Scom_E_NOT_OK_OUTOFRANGE (49U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1369931973
#    error "The magic number of the generated file <C:/SynergyWorkArea/CBD_AbsHwPos/AbsHwPos/utp/contract/Ap_AbsHwPos/Ap_AbsHwPos/Ap_AbsHwPos/Ap_AbsHwPos/Rte_Ap_AbsHwPos.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1369931973
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ABSHWPOS_H */
