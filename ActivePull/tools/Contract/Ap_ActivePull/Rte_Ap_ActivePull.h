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
 *          File:  Rte_Ap_ActivePull.h
 *     Workspace:  C:/_Synergy_Projects/Working/ses_dev_ea3/ActivePull/autosar
 *     SW-C Type:  Ap_ActivePull
 *  Generated at:  Mon Oct  3 13:25:46 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_ActivePull> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ACTIVEPULL_H
# define _RTE_AP_ACTIVEPULL_H

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

typedef P2CONST(struct Rte_CDS_Ap_ActivePull, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DisableLearning_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DisableOutput_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EstLatAcc_MpSecSq_f32 ((Float)0)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_PullCmpCustLrngDi_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PullCmpEna_Cnt_lgc ((Boolean)TRUE)
# define Rte_InitValue_PullCmpLongTermIntgtrSt_HwNm_f32 ((Float)0)
# define Rte_InitValue_PullCmpLongTermIntgtrStOffs_HwNm_f32 ((Float)0)
# define Rte_InitValue_PullCmpShoTermIntgtrSt_HwNm_f32 ((Float)0)
# define Rte_InitValue_PullCmpShoTermIntgtrStOffs_HwNm_f32 ((Float)0)
# define Rte_InitValue_PullCompCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleYawRate_DegpS_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_ActivePull_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ActivePull_PullCmpLTComp_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_ActivePull_Per1_DisableLearning_Cnt_lgc() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_DisableLearning_Cnt_lgc->value)

# define Rte_IRead_ActivePull_Per1_DisableOutput_Cnt_lgc() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_DisableOutput_Cnt_lgc->value)

# define Rte_IRead_ActivePull_Per1_EstLatAcc_MpSecSq_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_EstLatAcc_MpSecSq_f32->value)

# define Rte_IRead_ActivePull_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_ActivePull_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_ActivePull_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_HandwheelVelocity_HwRadpS_f32->value)

# define Rte_IRead_ActivePull_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_ActivePull_Per1_PullCmpCustLrngDi_Cnt_lgc() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_PullCmpCustLrngDi_Cnt_lgc->value)

# define Rte_IRead_ActivePull_Per1_PullCmpEna_Cnt_lgc() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_PullCmpEna_Cnt_lgc->value)

# define Rte_IRead_ActivePull_Per1_PullCmpShoTermIntgtrStOffs_HwNm_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_PullCmpShoTermIntgtrStOffs_HwNm_f32->value)

# define Rte_IRead_ActivePull_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_ActivePull_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IRead_ActivePull_Per1_VehicleYawRate_DegpS_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per1_VehicleYawRate_DegpS_f32->value)

# define Rte_IWrite_ActivePull_Per1_PullCmpShoTermIntgtrSt_HwNm_f32(data) \
  ( \
  Rte_Inst_Ap_ActivePull->ActivePull_Per1_PullCmpShoTermIntgtrSt_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_ActivePull_Per1_PullCmpShoTermIntgtrSt_HwNm_f32() \
  (&Rte_Inst_Ap_ActivePull->ActivePull_Per1_PullCmpShoTermIntgtrSt_HwNm_f32->value)

# define Rte_IRead_ActivePull_Per2_DisableOutput_Cnt_lgc() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per2_DisableOutput_Cnt_lgc->value)

# define Rte_IRead_ActivePull_Per2_PullCmpEna_Cnt_lgc() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per2_PullCmpEna_Cnt_lgc->value)

# define Rte_IRead_ActivePull_Per2_PullCmpLongTermIntgtrStOffs_HwNm_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per2_PullCmpLongTermIntgtrStOffs_HwNm_f32->value)

# define Rte_IRead_ActivePull_Per2_PullCmpShoTermIntgtrStOffs_HwNm_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per2_PullCmpShoTermIntgtrStOffs_HwNm_f32->value)

# define Rte_IRead_ActivePull_Per2_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per2_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_ActivePull_Per2_PullCompCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_ActivePull->ActivePull_Per2_PullCompCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_ActivePull_Per2_PullCompCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_ActivePull->ActivePull_Per2_PullCompCmd_MtrNm_f32->value)

# define Rte_IRead_ActivePull_Per3_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per3_HwTorque_HwNm_f32->value)

# define Rte_IRead_ActivePull_Per3_PullCmpEna_Cnt_lgc() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per3_PullCmpEna_Cnt_lgc->value)

# define Rte_IRead_ActivePull_Per3_PullCmpLongTermIntgtrStOffs_HwNm_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per3_PullCmpLongTermIntgtrStOffs_HwNm_f32->value)

# define Rte_IRead_ActivePull_Per3_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_ActivePull->ActivePull_Per3_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_ActivePull_Per3_PullCmpLongTermIntgtrSt_HwNm_f32(data) \
  ( \
  Rte_Inst_Ap_ActivePull->ActivePull_Per3_PullCmpLongTermIntgtrSt_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_ActivePull_Per3_PullCmpLongTermIntgtrSt_HwNm_f32() \
  (&Rte_Inst_Ap_ActivePull->ActivePull_Per3_PullCmpLongTermIntgtrSt_HwNm_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_ActivePull_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_PullCmpLTComp_SetRamBlockStatus Rte_Call_Ap_ActivePull_PullCmpLTComp_SetRamBlockStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PullCmpLTComp_HwNm_f32() (Rte_Inst_Ap_ActivePull->Pim_PullCmpLTComp_HwNm_f32)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Float *Rte_Pim_PullCmpLTComp_HwNm_f32(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_ACTIVEPULL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <WARMINIT, OFF, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_ActivePull_Per1_DisableLearning_Cnt_lgc(void)
 *   Boolean Rte_IRead_ActivePull_Per1_DisableOutput_Cnt_lgc(void)
 *   Float Rte_IRead_ActivePull_Per1_EstLatAcc_MpSecSq_f32(void)
 *   Float Rte_IRead_ActivePull_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_ActivePull_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_ActivePull_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_ActivePull_Per1_HwTorque_HwNm_f32(void)
 *   Boolean Rte_IRead_ActivePull_Per1_PullCmpCustLrngDi_Cnt_lgc(void)
 *   Boolean Rte_IRead_ActivePull_Per1_PullCmpEna_Cnt_lgc(void)
 *   Float Rte_IRead_ActivePull_Per1_PullCmpShoTermIntgtrStOffs_HwNm_f32(void)
 *   Boolean Rte_IRead_ActivePull_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_ActivePull_Per1_VehicleSpeed_Kph_f32(void)
 *   Float Rte_IRead_ActivePull_Per1_VehicleYawRate_DegpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ActivePull_Per1_PullCmpShoTermIntgtrSt_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_ActivePull_Per1_PullCmpShoTermIntgtrSt_HwNm_f32(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_ActivePull_Per2_DisableOutput_Cnt_lgc(void)
 *   Boolean Rte_IRead_ActivePull_Per2_PullCmpEna_Cnt_lgc(void)
 *   Float Rte_IRead_ActivePull_Per2_PullCmpLongTermIntgtrStOffs_HwNm_f32(void)
 *   Float Rte_IRead_ActivePull_Per2_PullCmpShoTermIntgtrStOffs_HwNm_f32(void)
 *   Float Rte_IRead_ActivePull_Per2_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ActivePull_Per2_PullCompCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_ActivePull_Per2_PullCompCmd_MtrNm_f32(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *     and not in Mode(s) <DISABLE, WARMINIT, OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_ActivePull_Per3_HwTorque_HwNm_f32(void)
 *   Boolean Rte_IRead_ActivePull_Per3_PullCmpEna_Cnt_lgc(void)
 *   Float Rte_IRead_ActivePull_Per3_PullCmpLongTermIntgtrStOffs_HwNm_f32(void)
 *   Float Rte_IRead_ActivePull_Per3_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ActivePull_Per3_PullCmpLongTermIntgtrSt_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_ActivePull_Per3_PullCmpLongTermIntgtrSt_HwNm_f32(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_SCom_ReadParam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadParam> of PortPrototype <ActivePull_SCom>
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
 *   void ActivePull_SCom_ReadParam(Float *PullCompCmd_HwNm_f32, Float *STComp_HwNm_f32, Float *LTComp_HwNm_f32, Boolean *EnableLearn_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_ReadParam(P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) PullCompCmd_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) STComp_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) LTComp_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) EnableLearn_Cnt_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_SCom_Reset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Reset> of PortPrototype <ActivePull_SCom>
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
 *   void ActivePull_SCom_Reset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_Reset(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_SCom_SetLTComp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetLTComp> of PortPrototype <ActivePull_SCom>
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
 *   void ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_SCom_SetSTComp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetSTComp> of PortPrototype <ActivePull_SCom>
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
 *   void ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Trns1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivePull_Trns2
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
 *   Std_ReturnType Rte_Call_PullCmpLTComp_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_Trns2(void);

# define RTE_STOP_SEC_AP_ACTIVEPULL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1475518121
#    error "The magic number of the generated file <C:/_Synergy_Projects/Working/ses_dev_ea3/ActivePull/tools/contract/Ap_ActivePull/Rte_Ap_ActivePull.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1475518121
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ACTIVEPULL_H */
