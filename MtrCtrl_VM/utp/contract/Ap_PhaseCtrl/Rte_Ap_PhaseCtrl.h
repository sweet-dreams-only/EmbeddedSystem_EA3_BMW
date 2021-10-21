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
 *          File:  Rte_Ap_PhaseCtrl.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_PhaseCtrl
 *  Generated at:  Sat Apr 13 16:57:28 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_PhaseCtrl> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PHASECTRL_H
# define _RTE_AP_PHASECTRL_H

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

typedef P2CONST(struct Rte_CDS_Ap_PhaseCtrl, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MtrQuad_Cnt_u08 ((UInt8)1u)
# define Rte_InitValue_TermA_Volt_f32 ((Float)0)
# define Rte_InitValue_TermBSS_Volt_f32 ((Float)0)
# define Rte_InitValue_TermBTOT_Volt_f32 ((Float)0)
# define Rte_InitValue_TermXd_Uls_f32 ((Float)0)
# define Rte_InitValue_TermXq_Uls_f32 ((Float)0)
# define Rte_InitValue_TermY_Uls_f32 ((Float)0)
# define Rte_InitValue_VdTerm_Volt_f32 ((Float)0)
# define Rte_InitValue_VqTerm_Volt_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_PhaseCtrl_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_PhaseCtrl_Per1_MtrQuad_Cnt_u08() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_MtrQuad_Cnt_u08->value)

# define Rte_IRead_PhaseCtrl_Per1_TermA_Volt_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_TermA_Volt_f32->value)

# define Rte_IRead_PhaseCtrl_Per1_TermBSS_Volt_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_TermBSS_Volt_f32->value)

# define Rte_IRead_PhaseCtrl_Per1_TermBTOT_Volt_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_TermBTOT_Volt_f32->value)

# define Rte_IRead_PhaseCtrl_Per1_TermXd_Uls_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_TermXd_Uls_f32->value)

# define Rte_IRead_PhaseCtrl_Per1_TermXq_Uls_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_TermXq_Uls_f32->value)

# define Rte_IRead_PhaseCtrl_Per1_TermY_Uls_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_TermY_Uls_f32->value)

# define Rte_IRead_PhaseCtrl_Per1_VdTerm_Volt_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_VdTerm_Volt_f32->value)

# define Rte_IRead_PhaseCtrl_Per1_VqTerm_Volt_f32() \
  (Rte_Inst_Ap_PhaseCtrl->PhaseCtrl_Per1_VqTerm_Volt_f32->value)




# define RTE_START_SEC_AP_PHASECTRL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaseCtrl_Per1
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
 *   Float Rte_IRead_PhaseCtrl_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *   UInt8 Rte_IRead_PhaseCtrl_Per1_MtrQuad_Cnt_u08(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermA_Volt_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermBSS_Volt_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermBTOT_Volt_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermXd_Uls_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermXq_Uls_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermY_Uls_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_VdTerm_Volt_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_VqTerm_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PHASECTRL_APPL_CODE) PhaseCtrl_Per1(void);

# define RTE_STOP_SEC_AP_PHASECTRL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1365887395
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/utp/contract/Ap_PhaseCtrl/Rte_Ap_PhaseCtrl.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1365887395
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PHASECTRL_H */
