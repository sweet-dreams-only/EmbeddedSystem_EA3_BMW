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
 *          File:  Rte_Ap_AvgFricLrn.h
 *     Workspace:  C:/SynergyWorkArea/Working/AvgFricLrn/autosar
 *     SW-C Type:  Ap_AvgFricLrn
 *  Generated at:  Thu Feb 25 13:40:41 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_AvgFricLrn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_AVGFRICLRN_H
# define _RTE_AP_AVGFRICLRN_H

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

typedef P2CONST(struct Rte_CDS_Ap_AvgFricLrn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CRFMtrTrq_MtrNm_f32 ((Float)0)
# define Rte_InitValue_DefeatFricLearning_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EstFric_HwNm_f32 ((Float)0)
# define Rte_InitValue_FricLrnCustEna_Cnt_lgc ((Boolean)TRUE)
# define Rte_InitValue_FricOffset_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwAng_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HwPosAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HwTrq_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwVel_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_LatAcc_MpSecSq_f32 ((Float)0)
# define Rte_InitValue_SatEstFric_HwNm_f32 ((Float)0)
# define Rte_InitValue_Temperature_DegC_f32 ((Float)0)
# define Rte_InitValue_VehSpd_Kph_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_AvgFricLrn_SystemState_Mode(void);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AvgFricLrn_FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_AvgFricLrn_Init1_FricOffset_HwNm_f32(data) \
  ( \
  Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Init1_FricOffset_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AvgFricLrn_Init1_FricOffset_HwNm_f32() \
  (&Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Init1_FricOffset_HwNm_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_CRFMtrTrq_MtrNm_f32() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_CRFMtrTrq_MtrNm_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_DefeatFricLearning_Cnt_lgc() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_DefeatFricLearning_Cnt_lgc->value)

# define Rte_IRead_AvgFricLrn_Per1_FricLrnCustEna_Cnt_lgc() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_FricLrnCustEna_Cnt_lgc->value)

# define Rte_IRead_AvgFricLrn_Per1_HwAng_HwDeg_f32() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_HwAng_HwDeg_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_HwPosAuthority_Uls_f32() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_HwPosAuthority_Uls_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_HwTrq_HwNm_f32() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_HwTrq_HwNm_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_HwVel_HwRadpS_f32() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_HwVel_HwRadpS_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_LatAcc_MpSecSq_f32() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_LatAcc_MpSecSq_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_Temperature_DegC_f32() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_Temperature_DegC_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_VehSpd_Kph_f32->value)

# define Rte_IRead_AvgFricLrn_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IWrite_AvgFricLrn_Per1_EstFric_HwNm_f32(data) \
  ( \
  Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_EstFric_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AvgFricLrn_Per1_EstFric_HwNm_f32() \
  (&Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_EstFric_HwNm_f32->value)

# define Rte_IWrite_AvgFricLrn_Per1_FricOffset_HwNm_f32(data) \
  ( \
  Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_FricOffset_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AvgFricLrn_Per1_FricOffset_HwNm_f32() \
  (&Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_FricOffset_HwNm_f32->value)

# define Rte_IWrite_AvgFricLrn_Per1_SatEstFric_HwNm_f32(data) \
  ( \
  Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_SatEstFric_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_AvgFricLrn_Per1_SatEstFric_HwNm_f32() \
  (&Rte_Inst_Ap_AvgFricLrn->AvgFricLrn_Per1_SatEstFric_HwNm_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_AvgFricLrn_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_AvgFricLrnData_WriteBlock Rte_Call_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock
# define Rte_Call_FltInjection_SCom_FltInjection Rte_Call_Ap_AvgFricLrn_FltInjection_SCom_FltInjection
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_AvgFricLrnData() (Rte_Inst_Ap_AvgFricLrn->Pim_AvgFricLrnData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   AvgFricLrnType *Rte_Pim_AvgFricLrnData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_AVGFRICLRN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_Init1
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
 *   void Rte_IWrite_AvgFricLrn_Init1_FricOffset_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AvgFricLrn_Init1_FricOffset_HwNm_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <OFF, WARMINIT, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AvgFricLrn_Per1_CRFMtrTrq_MtrNm_f32(void)
 *   Boolean Rte_IRead_AvgFricLrn_Per1_DefeatFricLearning_Cnt_lgc(void)
 *   Boolean Rte_IRead_AvgFricLrn_Per1_FricLrnCustEna_Cnt_lgc(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_HwAng_HwDeg_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_HwPosAuthority_Uls_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_HwTrq_HwNm_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_HwVel_HwRadpS_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_LatAcc_MpSecSq_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_Temperature_DegC_f32(void)
 *   Float Rte_IRead_AvgFricLrn_Per1_VehSpd_Kph_f32(void)
 *   Boolean Rte_IRead_AvgFricLrn_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AvgFricLrn_Per1_EstFric_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AvgFricLrn_Per1_EstFric_HwNm_f32(void)
 *   void Rte_IWrite_AvgFricLrn_Per1_FricOffset_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AvgFricLrn_Per1_FricOffset_HwNm_f32(void)
 *   void Rte_IWrite_AvgFricLrn_Per1_SatEstFric_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AvgFricLrn_Per1_SatEstFric_HwNm_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_GetEOLFric
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEOLFric> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_GetEOLFric(Float *EOLFric_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetEOLFric(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EOLFric_HwNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_GetOffsetOutputDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetOffsetOutputDefeat> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_GetOffsetOutputDefeat(Boolean *DefeatOffsetOutput_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetOffsetOutputDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) DefeatOffsetOutput_Cnt_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_GetSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSelect> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_GetSelect(Boolean *EnableFricLearning_Cnt_lgc, Boolean *EnableOffsetOutput_Cnt_lgc, UInt8 *OpMode_Uls_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetSelect(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableFricLearning_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableOffsetOutput_Cnt_lgc, P2VAR(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) OpMode_Uls_u08);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_InitLearnedTables
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitLearnedTables> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_InitLearnedTables(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_InitLearnedTables(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_ResetToZero
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetToZero> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_ResetToZero(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_ResetToZero(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_SetEOLFric
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLFric> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_SetOffsetOutputDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOffsetOutputDefeat> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_SCom_SetSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSelect> of PortPrototype <AvgFricLrn_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AvgFricLrn_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_AvgFricLrnData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_Trns1(void);

# define RTE_STOP_SEC_AP_AVGFRICLRN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1456427771
#    error "The magic number of the generated file <C:/SynergyWorkArea/Working/AvgFricLrn/tools/contract/Ap_AvgFricLrn/Rte_Ap_AvgFricLrn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1456427771
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_AVGFRICLRN_H */
