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
 *          File:  Rte_Ap_LrnEOT.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LrnEOT-nzt9hv/LrnEOT/autosar
 *     SW-C Type:  Ap_LrnEOT
 *  Generated at:  Wed Sep 26 16:43:42 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_LrnEOT> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_LRNEOT_H
# define _RTE_AP_LRNEOT_H

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

typedef P2CONST(struct Rte_CDS_Ap_LrnEOT, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CCWFound_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_CCWPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_CWFound_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_CWPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_DiagStsHwPosDis_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_PostLimitTorque_MtrNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus(Boolean RamBlockStatus);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LrnEOT_LearnedEOTData_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_LRNEOT_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LrnEOT_LearnedEOTData_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_LRNEOT_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_LrnEOT_Init1_CCWFound_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LrnEOT->LrnEOT_Init1_CCWFound_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LrnEOT_Init1_CCWFound_Cnt_lgc() \
  (&Rte_Inst_Ap_LrnEOT->LrnEOT_Init1_CCWFound_Cnt_lgc->value)

# define Rte_IWrite_LrnEOT_Init1_CCWPosition_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_LrnEOT->LrnEOT_Init1_CCWPosition_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_LrnEOT_Init1_CCWPosition_HwDeg_f32() \
  (&Rte_Inst_Ap_LrnEOT->LrnEOT_Init1_CCWPosition_HwDeg_f32->value)

# define Rte_IWrite_LrnEOT_Init1_CWFound_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LrnEOT->LrnEOT_Init1_CWFound_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LrnEOT_Init1_CWFound_Cnt_lgc() \
  (&Rte_Inst_Ap_LrnEOT->LrnEOT_Init1_CWFound_Cnt_lgc->value)

# define Rte_IWrite_LrnEOT_Init1_CWPosition_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_LrnEOT->LrnEOT_Init1_CWPosition_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_LrnEOT_Init1_CWPosition_HwDeg_f32() \
  (&Rte_Inst_Ap_LrnEOT->LrnEOT_Init1_CWPosition_HwDeg_f32->value)

# define Rte_IRead_LrnEOT_Per1_DiagStsHwPosDis_Cnt_lgc() \
  (Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_DiagStsHwPosDis_Cnt_lgc->value)

# define Rte_IRead_LrnEOT_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_LrnEOT_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_LrnEOT_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_LrnEOT_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_MtrVelCRF_MtrRadpS_f32->value)

# define Rte_IRead_LrnEOT_Per1_PostLimitTorque_MtrNm_f32() \
  (Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_PostLimitTorque_MtrNm_f32->value)

# define Rte_IWrite_LrnEOT_Per1_CCWFound_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_CCWFound_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LrnEOT_Per1_CCWFound_Cnt_lgc() \
  (&Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_CCWFound_Cnt_lgc->value)

# define Rte_IWrite_LrnEOT_Per1_CCWPosition_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_CCWPosition_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_LrnEOT_Per1_CCWPosition_HwDeg_f32() \
  (&Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_CCWPosition_HwDeg_f32->value)

# define Rte_IWrite_LrnEOT_Per1_CWFound_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_CWFound_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_LrnEOT_Per1_CWFound_Cnt_lgc() \
  (&Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_CWFound_Cnt_lgc->value)

# define Rte_IWrite_LrnEOT_Per1_CWPosition_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_CWPosition_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_LrnEOT_Per1_CWPosition_HwDeg_f32() \
  (&Rte_Inst_Ap_LrnEOT->LrnEOT_Per1_CWPosition_HwDeg_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_LearnedEOTData_SetRamBlockStatus Rte_Call_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus
# define Rte_Call_LearnedEOTData_WriteBlock Rte_Call_Ap_LrnEOT_LearnedEOTData_WriteBlock
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_LearnedEOT() (Rte_Inst_Ap_LrnEOT->Pim_LearnedEOT)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   EOTLearned_DataType *Rte_Pim_LearnedEOT(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_LRNEOT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnEOT_Init1
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
 *   void Rte_IWrite_LrnEOT_Init1_CCWFound_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LrnEOT_Init1_CCWFound_Cnt_lgc(void)
 *   void Rte_IWrite_LrnEOT_Init1_CCWPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LrnEOT_Init1_CCWPosition_HwDeg_f32(void)
 *   void Rte_IWrite_LrnEOT_Init1_CWFound_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LrnEOT_Init1_CWFound_Cnt_lgc(void)
 *   void Rte_IWrite_LrnEOT_Init1_CWPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LrnEOT_Init1_CWPosition_HwDeg_f32(void)
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
 *   Std_ReturnType Rte_Call_LearnedEOTData_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_LearnedEOTData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_LearnedEOTData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnEOT_Per1
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
 *   Boolean Rte_IRead_LrnEOT_Per1_DiagStsHwPosDis_Cnt_lgc(void)
 *   Float Rte_IRead_LrnEOT_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_LrnEOT_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_LrnEOT_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_LrnEOT_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_LrnEOT_Per1_PostLimitTorque_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LrnEOT_Per1_CCWFound_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LrnEOT_Per1_CCWFound_Cnt_lgc(void)
 *   void Rte_IWrite_LrnEOT_Per1_CCWPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LrnEOT_Per1_CCWPosition_HwDeg_f32(void)
 *   void Rte_IWrite_LrnEOT_Per1_CWFound_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_LrnEOT_Per1_CWFound_Cnt_lgc(void)
 *   void Rte_IWrite_LrnEOT_Per1_CWPosition_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LrnEOT_Per1_CWPosition_HwDeg_f32(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LearnedEOTData_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_LearnedEOTData_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_LearnedEOTData_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnEOT_Scom_ResetEOT
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetEOT> of PortPrototype <LrnEOT_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void LrnEOT_Scom_ResetEOT(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetEOT(void);

# define RTE_STOP_SEC_AP_LRNEOT_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1348690149
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LrnEOT-nzt9hv/LrnEOT/utp/contract/Rte_Ap_LrnEOT.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1348690149
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_LRNEOT_H */
