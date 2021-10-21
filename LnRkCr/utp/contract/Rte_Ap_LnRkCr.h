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
 *          File:  Rte_Ap_LnRkCr.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LnRkCr-nzt9hv/LnRkCr/autosar
 *     SW-C Type:  Ap_LnRkCr
 *  Generated at:  Fri Sep 21 13:52:54 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_LnRkCr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_LNRKCR_H
# define _RTE_AP_LNRKCR_H

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

typedef P2CONST(struct Rte_CDS_Ap_LnRkCr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AlignedHwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_CRFMtrTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_LTRackCntrComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LrnPnCntrEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LrnPnCntrHwCenter_HwDeg_f32 ((Float)0)
# define Rte_InitValue_LrnPnCntrHwTravel_HwDeg_f32 ((Float)0)
# define Rte_InitValue_LrnPnCntrState_Cnt_enum ((LktoLkStrStateType)0u)
# define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_RackCenter_HwDeg_f32 ((Float)0)
# define Rte_InitValue_RackCntrComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_RackCntrMtrAngleError_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_RackCntrMtrAngleFound_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LnRkCr_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LnRkCr_LearnedRackCntrData_SetRamBlockStatus(Boolean RamBlockStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LnRkCr_LearnedRackCntrData_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_LNRKCR_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LnRkCr_LearnedRackCntrData_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_LNRKCR_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LnRkCr_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_LNRKCR_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LnRkCr_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_LNRKCR_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LnRkCr_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_LNRKCR_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_LnRkCr_Init1_AlignedHwPos_HwDeg_f32() \
  (Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_AlignedHwPos_HwDeg_f32->value)

# define Rte_IWrite_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc->value)

# define Rte_IWrite_LnRkCr_Init1_RackCenter_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_RackCenter_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Init1_RackCenter_HwDeg_f32() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_RackCenter_HwDeg_f32->value)

# define Rte_IWrite_LnRkCr_Init1_RackCntrComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_RackCntrComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Init1_RackCntrComplete_Cnt_lgc() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_RackCntrComplete_Cnt_lgc->value)

# define Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc->value)

# define Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc->value)

# define Rte_IRead_LnRkCr_Per1_AlignedHwPos_HwDeg_f32() \
  (Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_AlignedHwPos_HwDeg_f32->value)

# define Rte_IRead_LnRkCr_Per1_CRFMtrTrqCmd_MtrNm_f32() \
  (Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_CRFMtrTrqCmd_MtrNm_f32->value)

# define Rte_IRead_LnRkCr_Per1_LrnPnCntrEnable_Cnt_lgc() \
  (Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_LrnPnCntrEnable_Cnt_lgc->value)

# define Rte_IRead_LnRkCr_Per1_LrnPnCntrHwCenter_HwDeg_f32() \
  (Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_LrnPnCntrHwCenter_HwDeg_f32->value)

# define Rte_IRead_LnRkCr_Per1_LrnPnCntrHwTravel_HwDeg_f32() \
  (Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_LrnPnCntrHwTravel_HwDeg_f32->value)

# define Rte_IRead_LnRkCr_Per1_LrnPnCntrState_Cnt_enum() \
  (Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_LrnPnCntrState_Cnt_enum->value)

# define Rte_IRead_LnRkCr_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_MtrVelCRF_MtrRadpS_f32->value)

# define Rte_IWrite_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc->value)

# define Rte_IWrite_LnRkCr_Per1_RackCenter_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_RackCenter_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Per1_RackCenter_HwDeg_f32() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_RackCenter_HwDeg_f32->value)

# define Rte_IWrite_LnRkCr_Per1_RackCntrComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_RackCntrComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Per1_RackCntrComplete_Cnt_lgc() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_RackCntrComplete_Cnt_lgc->value)

# define Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc->value)

# define Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc() \
  (&Rte_Inst_Ap_LnRkCr->LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset Rte_Call_Ap_LnRkCr_AbsHwPos_SetData_SetRacktoVehCntrOffset
# define Rte_Call_LearnedRackCntrData_SetRamBlockStatus Rte_Call_Ap_LnRkCr_LearnedRackCntrData_SetRamBlockStatus
# define Rte_Call_LearnedRackCntrData_WriteBlock Rte_Call_Ap_LnRkCr_LearnedRackCntrData_WriteBlock
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_LnRkCr_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_LnRkCr_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_LnRkCr_SystemTime_GetSystemTime_mS_u32


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_LearnedRackCntr() (Rte_Inst_Ap_LnRkCr->Pim_LearnedRackCntr)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   RackCenterType *Rte_Pim_LearnedRackCntr(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_LNRKCR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: LnRkCr_Init1
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
 *   Float Rte_IRead_LnRkCr_Init1_AlignedHwPos_HwDeg_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Init1_RackCenter_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LnRkCr_Init1_RackCenter_HwDeg_f32(void)
 *   void Rte_IWrite_LnRkCr_Init1_RackCntrComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Init1_RackCntrComplete_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LnRkCr_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_LnRkCr_Per1_AlignedHwPos_HwDeg_f32(void)
 *   Float Rte_IRead_LnRkCr_Per1_CRFMtrTrqCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_LnRkCr_Per1_LrnPnCntrEnable_Cnt_lgc(void)
 *   Float Rte_IRead_LnRkCr_Per1_LrnPnCntrHwCenter_HwDeg_f32(void)
 *   Float Rte_IRead_LnRkCr_Per1_LrnPnCntrHwTravel_HwDeg_f32(void)
 *   LktoLkStrStateType Rte_IRead_LnRkCr_Per1_LrnPnCntrState_Cnt_enum(void)
 *   Float Rte_IRead_LnRkCr_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Per1_RackCenter_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LnRkCr_Per1_RackCenter_HwDeg_f32(void)
 *   void Rte_IWrite_LnRkCr_Per1_RackCntrComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Per1_RackCntrComplete_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc(void)
 *   void Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LnRkCr_Scom_ResetRckCntrMtrDeg
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetRckCntrMtrDeg> of PortPrototype <LnRkCr_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_LearnedRackCntrData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void LnRkCr_Scom_ResetRckCntrMtrDeg(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrDeg(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LnRkCr_Scom_ResetRckCntrMtrRev
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetRckCntrMtrRev> of PortPrototype <LnRkCr_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void LnRkCr_Scom_ResetRckCntrMtrRev(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrRev(void);

# define RTE_STOP_SEC_AP_LNRKCR_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1348255092
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LnRkCr-nzt9hv/LnRkCr/utp/contract/Rte_Ap_LnRkCr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1348255092
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_LNRKCR_H */
