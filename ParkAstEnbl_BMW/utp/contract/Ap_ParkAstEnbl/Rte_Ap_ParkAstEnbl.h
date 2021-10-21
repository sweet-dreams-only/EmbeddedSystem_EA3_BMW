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
 *          File:  Rte_Ap_ParkAstEnbl.h
 *     Workspace:  C:/SynergyWorkArea/CBD_ParkAsstEnblBMW/ParkAstEnbl_BMW/autosar
 *     SW-C Type:  Ap_ParkAstEnbl
 *  Generated at:  Mon Apr  1 11:46:56 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_ParkAstEnbl> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PARKASTENBL_H
# define _RTE_AP_PARKASTENBL_H

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

typedef P2CONST(struct Rte_CDS_Ap_ParkAstEnbl, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DiagStsRmpZeroNRec_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsRmpZeroRec_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HandwheelVel_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_LimitPercentFiltered_Uls_f32 ((Float)0)
# define Rte_InitValue_PAEnableRqst_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAErrInterfaceActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAHWAngleRqst_HwDeg_f32 ((Float)0)
# define Rte_InitValue_PASpdHigh_Cnt_u08 ((ST_V_VEH_NSS)15u)
# define Rte_InitValue_PASpdStdStill_Cnt_u08 ((DVCO_VEH)0u)
# define Rte_InitValue_PendEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PendHwAngle_HwDeg_f32 ((Float)0)
# define Rte_InitValue_PosServEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PosServoHwAngle_HwDeg_f32 ((Float)0)
# define Rte_InitValue_PosTrajEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PosTrajHwAngle_HwDeg_f32 ((Float)0)
# define Rte_InitValue_PrkAssistState_Cnt_u08 ((QU_SER_WSTA_EST_FTAX)128u)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_ParkAstEnbl_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ParkAstEnbl_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_PARKASTENBL_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ParkAstEnbl_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ParkAstEnbl_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_PARKASTENBL_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ParkAstEnbl_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_PARKASTENBL_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroNRec_Cnt_lgc() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_DiagStsRmpZeroNRec_Cnt_lgc->value)

# define Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroRec_Cnt_lgc() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_DiagStsRmpZeroRec_Cnt_lgc->value)

# define Rte_IRead_ParkAstEnbl_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_ParkAstEnbl_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_ParkAstEnbl_Per1_HandwheelVel_HwRadpS_f32() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_HandwheelVel_HwRadpS_f32->value)

# define Rte_IRead_ParkAstEnbl_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_ParkAstEnbl_Per1_LimitPercentFiltered_Uls_f32() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_LimitPercentFiltered_Uls_f32->value)

# define Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc->value)

# define Rte_IRead_ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc->value)

# define Rte_IRead_ParkAstEnbl_Per1_PAHWAngleRqst_HwDeg_f32() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PAHWAngleRqst_HwDeg_f32->value)

# define Rte_IRead_ParkAstEnbl_Per1_PASpdHigh_Cnt_u08() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PASpdHigh_Cnt_u08->value)

# define Rte_IRead_ParkAstEnbl_Per1_PASpdStdStill_Cnt_u08() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PASpdStdStill_Cnt_u08->value)

# define Rte_IRead_ParkAstEnbl_Per1_PendEnable_Cnt_lgc() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PendEnable_Cnt_lgc->value)

# define Rte_IRead_ParkAstEnbl_Per1_PendHwAngle_HwDeg_f32() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PendHwAngle_HwDeg_f32->value)

# define Rte_IRead_ParkAstEnbl_Per1_PosTrajEnable_Cnt_lgc() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PosTrajEnable_Cnt_lgc->value)

# define Rte_IRead_ParkAstEnbl_Per1_PosTrajHwAngle_HwDeg_f32() \
  (Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PosTrajHwAngle_HwDeg_f32->value)

# define Rte_IWrite_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PosServEnable_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc() \
  (&Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PosServEnable_Cnt_lgc->value)

# define Rte_IWrite_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32() \
  (&Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32->value)

# define Rte_IWrite_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PrkAssistState_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08() \
  (&Rte_Inst_Ap_ParkAstEnbl->ParkAstEnbl_Per1_PrkAssistState_Cnt_u08->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_ParkAstEnbl_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_ParkAstEnbl_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_ParkAstEnbl_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_ParkAstEnbl_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_ParkAstEnbl_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_PARKASTENBL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ParkAstEnbl_Per1
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
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroNRec_Cnt_lgc(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_DiagStsRmpZeroRec_Cnt_lgc(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_HandwheelVel_HwRadpS_f32(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_LimitPercentFiltered_Uls_f32(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_PAEnableRqst_Cnt_lgc(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_PAErrInterfaceActive_Cnt_lgc(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_PAHWAngleRqst_HwDeg_f32(void)
 *   ST_V_VEH_NSS Rte_IRead_ParkAstEnbl_Per1_PASpdHigh_Cnt_u08(void)
 *   DVCO_VEH Rte_IRead_ParkAstEnbl_Per1_PASpdStdStill_Cnt_u08(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_PendEnable_Cnt_lgc(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_PendHwAngle_HwDeg_f32(void)
 *   Boolean Rte_IRead_ParkAstEnbl_Per1_PosTrajEnable_Cnt_lgc(void)
 *   Float Rte_IRead_ParkAstEnbl_Per1_PosTrajHwAngle_HwDeg_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ParkAstEnbl_Per1_PosServEnable_Cnt_lgc(void)
 *   void Rte_IWrite_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_ParkAstEnbl_Per1_PosServoHwAngle_HwDeg_f32(void)
 *   void Rte_IWrite_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08(QU_SER_WSTA_EST_FTAX data)
 *   QU_SER_WSTA_EST_FTAX *Rte_IWriteRef_ParkAstEnbl_Per1_PrkAssistState_Cnt_u08(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
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

FUNC(void, RTE_AP_PARKASTENBL_APPL_CODE) ParkAstEnbl_Per1(void);

# define RTE_STOP_SEC_AP_PARKASTENBL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1364831794
#    error "The magic number of the generated file <C:/SynergyWorkArea/CBD_ParkAsstEnblBMW/ParkAstEnbl_BMW/utp/contract/Ap_ParkAstEnbl/Rte_Ap_ParkAstEnbl.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1364831794
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PARKASTENBL_H */
