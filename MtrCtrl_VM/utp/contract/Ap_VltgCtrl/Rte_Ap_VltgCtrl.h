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
 *          File:  Rte_Ap_VltgCtrl.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_VltgCtrl
 *  Generated at:  Sat Apr 13 16:58:03 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_VltgCtrl> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_VLTGCTRL_H
# define _RTE_AP_VLTGCTRL_H

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

typedef P2CONST(struct Rte_CDS_Ap_VltgCtrl, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CCLMSAActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_CuTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_EstKe_VpRadpS_f32 ((Float)0)
# define Rte_InitValue_EstLd_Henry_f32 ((Float)0)
# define Rte_InitValue_EstLq_Henry_f32 ((Float)0)
# define Rte_InitValue_EstR_Ohm_f32 ((Float)0)
# define Rte_InitValue_MRFMtrTrqCmdScl_MtrNm_f32 ((Float)0)
# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_ModIdx_Uls_f32 ((Float)0)
# define Rte_InitValue_MtrEnvSpd_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MtrQuad_Cnt_u08 ((UInt8)1u)
# define Rte_InitValue_PDActivateTest_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PDPhsAdvSel_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_PDTestModIdx_Uls_f32 ((Float)0)
# define Rte_InitValue_PhsAdv_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_TermA_Volt_f32 ((Float)0)
# define Rte_InitValue_TermBSS_Volt_f32 ((Float)0)
# define Rte_InitValue_TermBTOT_Volt_f32 ((Float)0)
# define Rte_InitValue_TermXd_Uls_f32 ((Float)0)
# define Rte_InitValue_TermXq_Uls_f32 ((Float)0)
# define Rte_InitValue_TermY_Uls_f32 ((Float)0)
# define Rte_InitValue_TermZ_Uls_f32 ((Float)1)
# define Rte_InitValue_UnCorrPhsAdv_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_VdTerm_Volt_f32 ((Float)0)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)
# define Rte_InitValue_VqTerm_Volt_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_VltgCtrl_SystemState_Mode(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_VltgCtrl_Per1_EstKe_VpRadpS_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per1_EstKe_VpRadpS_f32->value)

# define Rte_IRead_VltgCtrl_Per1_EstR_Ohm_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per1_EstR_Ohm_f32->value)

# define Rte_IRead_VltgCtrl_Per1_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per1_MRFMtrTrqCmdScl_MtrNm_f32->value)

# define Rte_IWrite_VltgCtrl_Per1_TermBSS_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per1_TermBSS_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per1_TermBSS_Volt_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per1_TermBSS_Volt_f32->value)

# define Rte_IRead_VltgCtrl_Per2_CuTempEst_DegC_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_CuTempEst_DegC_f32->value)

# define Rte_IRead_VltgCtrl_Per2_EstKe_VpRadpS_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_EstKe_VpRadpS_f32->value)

# define Rte_IRead_VltgCtrl_Per2_EstLd_Henry_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_EstLd_Henry_f32->value)

# define Rte_IRead_VltgCtrl_Per2_EstLq_Henry_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_EstLq_Henry_f32->value)

# define Rte_IRead_VltgCtrl_Per2_EstR_Ohm_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_EstR_Ohm_f32->value)

# define Rte_IRead_VltgCtrl_Per2_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_MRFMtrTrqCmdScl_MtrNm_f32->value)

# define Rte_IRead_VltgCtrl_Per2_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_VltgCtrl_Per2_MtrEnvSpd_MtrRadpS_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_MtrEnvSpd_MtrRadpS_f32->value)

# define Rte_IRead_VltgCtrl_Per2_MtrQuad_Cnt_u08() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_MtrQuad_Cnt_u08->value)

# define Rte_IRead_VltgCtrl_Per2_Vecu_Volt_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_Vecu_Volt_f32->value)

# define Rte_IWrite_VltgCtrl_Per2_TermA_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermA_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per2_TermA_Volt_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermA_Volt_f32->value)

# define Rte_IWrite_VltgCtrl_Per2_TermBTOT_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermBTOT_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per2_TermBTOT_Volt_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermBTOT_Volt_f32->value)

# define Rte_IWrite_VltgCtrl_Per2_TermXd_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermXd_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per2_TermXd_Uls_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermXd_Uls_f32->value)

# define Rte_IWrite_VltgCtrl_Per2_TermXq_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermXq_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per2_TermXq_Uls_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermXq_Uls_f32->value)

# define Rte_IWrite_VltgCtrl_Per2_TermY_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermY_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per2_TermY_Uls_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermY_Uls_f32->value)

# define Rte_IWrite_VltgCtrl_Per2_TermZ_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermZ_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per2_TermZ_Uls_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_TermZ_Uls_f32->value)

# define Rte_IWrite_VltgCtrl_Per2_VdTerm_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_VdTerm_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per2_VdTerm_Volt_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_VdTerm_Volt_f32->value)

# define Rte_IWrite_VltgCtrl_Per2_VqTerm_Volt_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_VqTerm_Volt_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per2_VqTerm_Volt_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per2_VqTerm_Volt_f32->value)

# define Rte_IRead_VltgCtrl_Per3_CCLMSAActive_Cnt_lgc() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per3_CCLMSAActive_Cnt_lgc->value)

# define Rte_IRead_VltgCtrl_Per3_MtrEnvSpd_MtrRadpS_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per3_MtrEnvSpd_MtrRadpS_f32->value)

# define Rte_IRead_VltgCtrl_Per3_Vecu_Volt_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per3_Vecu_Volt_f32->value)

# define Rte_IRead_VltgCtrl_Per4_MtrQuad_Cnt_u08() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_MtrQuad_Cnt_u08->value)

# define Rte_IRead_VltgCtrl_Per4_PDActivateTest_Cnt_lgc() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_PDActivateTest_Cnt_lgc->value)

# define Rte_IRead_VltgCtrl_Per4_PDPhsAdvSel_Cnt_s16() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_PDPhsAdvSel_Cnt_s16->value)

# define Rte_IRead_VltgCtrl_Per4_PDTestModIdx_Uls_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_PDTestModIdx_Uls_f32->value)

# define Rte_IRead_VltgCtrl_Per4_Vecu_Volt_f32() \
  (Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_Vecu_Volt_f32->value)

# define Rte_IWrite_VltgCtrl_Per4_ModIdx_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_ModIdx_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per4_ModIdx_Uls_f32() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_ModIdx_Uls_f32->value)

# define Rte_IWrite_VltgCtrl_Per4_PhsAdv_Cnt_s16(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_PhsAdv_Cnt_s16->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per4_PhsAdv_Cnt_s16() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_PhsAdv_Cnt_s16->value)

# define Rte_IWrite_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16(data) \
  ( \
  Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16->value = (data) \
  )

# define Rte_IWriteRef_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16() \
  (&Rte_Inst_Ap_VltgCtrl->VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_VltgCtrl_SystemState_Mode




# define RTE_START_SEC_AP_VLTGCTRL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Init1
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Per1
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
 *   Float Rte_IRead_VltgCtrl_Per1_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per1_EstR_Ohm_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per1_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VltgCtrl_Per1_TermBSS_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per1_TermBSS_Volt_f32(void)
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_VltgCtrl_Per2_CuTempEst_DegC_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_EstLd_Henry_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_EstLq_Henry_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_EstR_Ohm_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_MtrEnvSpd_MtrRadpS_f32(void)
 *   UInt8 Rte_IRead_VltgCtrl_Per2_MtrQuad_Cnt_u08(void)
 *   Float Rte_IRead_VltgCtrl_Per2_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VltgCtrl_Per2_TermA_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermA_Volt_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermBTOT_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermBTOT_Volt_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermXd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermXd_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermXq_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermXq_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermY_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermY_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermZ_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermZ_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_VdTerm_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_VdTerm_Volt_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_VqTerm_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_VqTerm_Volt_f32(void)
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Per3
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
 *   Boolean Rte_IRead_VltgCtrl_Per3_CCLMSAActive_Cnt_lgc(void)
 *   Float Rte_IRead_VltgCtrl_Per3_MtrEnvSpd_MtrRadpS_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per3_Vecu_Volt_f32(void)
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Per4
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt8 Rte_IRead_VltgCtrl_Per4_MtrQuad_Cnt_u08(void)
 *   Boolean Rte_IRead_VltgCtrl_Per4_PDActivateTest_Cnt_lgc(void)
 *   SInt16 Rte_IRead_VltgCtrl_Per4_PDPhsAdvSel_Cnt_s16(void)
 *   Float Rte_IRead_VltgCtrl_Per4_PDTestModIdx_Uls_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per4_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VltgCtrl_Per4_ModIdx_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per4_ModIdx_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per4_PhsAdv_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_VltgCtrl_Per4_PhsAdv_Cnt_s16(void)
 *   void Rte_IWrite_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16(void)
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per4(void);

# define RTE_STOP_SEC_AP_VLTGCTRL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1365888301
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/utp/contract/Ap_VltgCtrl/Rte_Ap_VltgCtrl.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1365888301
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_VLTGCTRL_H */
