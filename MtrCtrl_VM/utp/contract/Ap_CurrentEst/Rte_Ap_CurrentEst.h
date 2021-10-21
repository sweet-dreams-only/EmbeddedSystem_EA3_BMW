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
 *          File:  Rte_Ap_CurrentEst.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_CurrentEst
 *  Generated at:  Sat Apr 13 16:57:05 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_CurrentEst> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CURRENTEST_H
# define _RTE_AP_CURRENTEST_H

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

typedef P2CONST(struct Rte_CDS_Ap_CurrentEst, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_EstPkCurr_AmpSq_f32 ((Float)0)
# define Rte_InitValue_EstR_Ohm_f32 ((Float)0)
# define Rte_InitValue_ExpIq_Amp_f32 ((Float)0)
# define Rte_InitValue_FiltEstPkCurr_AmpSq_f32 ((Float)0)
# define Rte_InitValue_IdEst_Amp_f32 ((Float)0)
# define Rte_InitValue_ModIdx_Uls_f32 ((Float)0)
# define Rte_InitValue_TermXq_Uls_f32 ((Float)0)
# define Rte_InitValue_UncorrPhsAdv_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_CurrentEst_SystemState_Mode(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CurrentEst_Per1_EstR_Ohm_f32() \
  (Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_EstR_Ohm_f32->value)

# define Rte_IRead_CurrentEst_Per1_ExpIq_Amp_f32() \
  (Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_ExpIq_Amp_f32->value)

# define Rte_IRead_CurrentEst_Per1_ModIdx_Uls_f32() \
  (Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_ModIdx_Uls_f32->value)

# define Rte_IRead_CurrentEst_Per1_TermXq_Uls_f32() \
  (Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_TermXq_Uls_f32->value)

# define Rte_IRead_CurrentEst_Per1_UncorrPhsAdv_Cnt_s16() \
  (Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_UncorrPhsAdv_Cnt_s16->value)

# define Rte_IRead_CurrentEst_Per1_Vecu_Volt_f32() \
  (Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_Vecu_Volt_f32->value)

# define Rte_IWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(data) \
  ( \
  Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_EstPkCurr_AmpSq_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrentEst_Per1_EstPkCurr_AmpSq_f32() \
  (&Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_EstPkCurr_AmpSq_f32->value)

# define Rte_IWrite_CurrentEst_Per1_IdEst_Amp_f32(data) \
  ( \
  Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_IdEst_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrentEst_Per1_IdEst_Amp_f32() \
  (&Rte_Inst_Ap_CurrentEst->CurrentEst_Per1_IdEst_Amp_f32->value)

# define Rte_IWrite_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32(data) \
  ( \
  Rte_Inst_Ap_CurrentEst->CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32->value = (data) \
  )

# define Rte_IWriteRef_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32() \
  (&Rte_Inst_Ap_CurrentEst->CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_CurrentEst_SystemState_Mode


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

# define Rte_IrvIWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(data) \
  (*(Rte_Inst_Ap_CurrentEst->Irv_CurrentEst_Per1_EstPkCurr_AmpSq_f32) = (data))

# define Rte_IrvIRead_CurrentEst_Per2_EstPkCurr_AmpSq_f32() \
  (*(Rte_Inst_Ap_CurrentEst->Irv_CurrentEst_Per2_EstPkCurr_AmpSq_f32))




# define RTE_START_SEC_AP_CURRENTEST_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrentEst_Per1
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
 *   Float Rte_IRead_CurrentEst_Per1_EstR_Ohm_f32(void)
 *   Float Rte_IRead_CurrentEst_Per1_ExpIq_Amp_f32(void)
 *   Float Rte_IRead_CurrentEst_Per1_ModIdx_Uls_f32(void)
 *   Float Rte_IRead_CurrentEst_Per1_TermXq_Uls_f32(void)
 *   SInt16 Rte_IRead_CurrentEst_Per1_UncorrPhsAdv_Cnt_s16(void)
 *   Float Rte_IRead_CurrentEst_Per1_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(Float data)
 *   Float *Rte_IWriteRef_CurrentEst_Per1_EstPkCurr_AmpSq_f32(void)
 *   void Rte_IWrite_CurrentEst_Per1_IdEst_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CurrentEst_Per1_IdEst_Amp_f32(void)
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
 * Inter Runnable Variables:
 * =========================
 *   Implicit Write Access:
 *   ----------------------
 *   void Rte_IrvIWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(Float data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRENTEST_APPL_CODE) CurrentEst_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrentEst_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *     and not in Mode(s) <WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32(Float data)
 *   Float *Rte_IWriteRef_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32(void)
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
 * Inter Runnable Variables:
 * =========================
 *   Implicit Read Access:
 *   ---------------------
 *   Float Rte_IrvIRead_CurrentEst_Per2_EstPkCurr_AmpSq_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRENTEST_APPL_CODE) CurrentEst_Per2(void);

# define RTE_STOP_SEC_AP_CURRENTEST_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1365887952
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/utp/contract/Ap_CurrentEst/Rte_Ap_CurrentEst.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1365887952
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CURRENTEST_H */
