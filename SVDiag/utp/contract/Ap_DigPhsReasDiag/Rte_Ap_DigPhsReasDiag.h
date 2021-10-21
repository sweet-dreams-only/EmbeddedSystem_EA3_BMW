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
 *          File:  Rte_Ap_DigPhsReasDiag.h
 *     Workspace:  C:/CMSynergy_Projects/CBD/SVDiag/autosar
 *     SW-C Type:  Ap_DigPhsReasDiag
 *  Generated at:  Thu Apr 25 10:47:23 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_DigPhsReasDiag> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DIGPHSREASDIAG_H
# define _RTE_AP_DIGPHSREASDIAG_H

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

typedef P2CONST(struct Rte_CDS_Ap_DigPhsReasDiag, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ExpectedOnTimeA_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_ExpectedOnTimeB_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_ExpectedOnTimeC_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_LRPRCorrectedMtrPosCaptured_Rev_f32 ((Float)0)
# define Rte_InitValue_LRPRModulationIndexCaptured_Uls_f32 ((Float)0)
# define Rte_InitValue_LRPRPhaseadvanceCaptured_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_MeasuredOnTimeA_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_MeasuredOnTimeB_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_MeasuredOnTimeC_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_MotorVelMRFUnfiltered_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_PDActivateTest_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_DigPhsReasDiag_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeA_Cnt_u32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_ExpectedOnTimeA_Cnt_u32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeB_Cnt_u32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_ExpectedOnTimeB_Cnt_u32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeC_Cnt_u32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_ExpectedOnTimeC_Cnt_u32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_LRPRCorrectedMtrPosCaptured_Rev_f32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_LRPRCorrectedMtrPosCaptured_Rev_f32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_LRPRModulationIndexCaptured_Uls_f32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_LRPRModulationIndexCaptured_Uls_f32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_LRPRPhaseadvanceCaptured_Cnt_s16() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_LRPRPhaseadvanceCaptured_Cnt_s16->value)

# define Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeA_Cnt_u32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_MeasuredOnTimeA_Cnt_u32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeB_Cnt_u32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_MeasuredOnTimeB_Cnt_u32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeC_Cnt_u32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_MeasuredOnTimeC_Cnt_u32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_MotorVelMRFUnfiltered_MtrRadpS_f32() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_MotorVelMRFUnfiltered_MtrRadpS_f32->value)

# define Rte_IRead_DigPhsReasDiag_Per1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_MtrElecMechPolarity_Cnt_s08->value)

# define Rte_IRead_DigPhsReasDiag_Per1_PDActivateTest_Cnt_lgc() \
  (Rte_Inst_Ap_DigPhsReasDiag->DigPhsReasDiag_Per1_PDActivateTest_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_DigPhsReasDiag_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_DIGPHSREASDIAG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigPhsReasDiag_Init
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

FUNC(void, RTE_AP_DIGPHSREASDIAG_APPL_CODE) DigPhsReasDiag_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigPhsReasDiag_Per1
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
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   Float Rte_IRead_DigPhsReasDiag_Per1_LRPRCorrectedMtrPosCaptured_Rev_f32(void)
 *   Float Rte_IRead_DigPhsReasDiag_Per1_LRPRModulationIndexCaptured_Uls_f32(void)
 *   SInt16 Rte_IRead_DigPhsReasDiag_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *   Float Rte_IRead_DigPhsReasDiag_Per1_MotorVelMRFUnfiltered_MtrRadpS_f32(void)
 *   SInt8 Rte_IRead_DigPhsReasDiag_Per1_MtrElecMechPolarity_Cnt_s08(void)
 *   Boolean Rte_IRead_DigPhsReasDiag_Per1_PDActivateTest_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DIGPHSREASDIAG_APPL_CODE) DigPhsReasDiag_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigPhsReasDiag_Trans1
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DIGPHSREASDIAG_APPL_CODE) DigPhsReasDiag_Trans1(void);

# define RTE_STOP_SEC_AP_DIGPHSREASDIAG_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1366903382
#    error "The magic number of the generated file <C:/CMSynergy_Projects/CBD/SVDiag/utp/contract/Ap_DigPhsReasDiag/Rte_Ap_DigPhsReasDiag.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1366903382
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DIGPHSREASDIAG_H */
