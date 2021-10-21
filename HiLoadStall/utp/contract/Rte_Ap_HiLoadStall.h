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
 *          File:  Rte_Ap_HiLoadStall.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/HiLoadStall-nzt9hv/HiLoadStall/autosar
 *     SW-C Type:  Ap_HiLoadStall
 *  Generated at:  Fri Sep 21 10:25:50 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_HiLoadStall> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_HILOADSTALL_H
# define _RTE_AP_HILOADSTALL_H

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

typedef P2CONST(struct Rte_CDS_Ap_HiLoadStall, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistStallLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_DftStallLimit_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_PreLimitForStall_MtrNm_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_HiLoadStall_Per1_DftStallLimit_Cnt_lgc() \
  (Rte_Inst_Ap_HiLoadStall->HiLoadStall_Per1_DftStallLimit_Cnt_lgc->value)

# define Rte_IRead_HiLoadStall_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_HiLoadStall->HiLoadStall_Per1_MtrVelCRF_MtrRadpS_f32->value)

# define Rte_IRead_HiLoadStall_Per1_PreLimitForStall_MtrNm_f32() \
  (Rte_Inst_Ap_HiLoadStall->HiLoadStall_Per1_PreLimitForStall_MtrNm_f32->value)

# define Rte_IWrite_HiLoadStall_Per1_AssistStallLimit_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_HiLoadStall->HiLoadStall_Per1_AssistStallLimit_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_HiLoadStall_Per1_AssistStallLimit_MtrNm_f32() \
  (&Rte_Inst_Ap_HiLoadStall->HiLoadStall_Per1_AssistStallLimit_MtrNm_f32->value)




# define RTE_START_SEC_AP_HILOADSTALL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HiLoadStall_Per1
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
 *   Boolean Rte_IRead_HiLoadStall_Per1_DftStallLimit_Cnt_lgc(void)
 *   Float Rte_IRead_HiLoadStall_Per1_MtrVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_HiLoadStall_Per1_PreLimitForStall_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HiLoadStall_Per1_AssistStallLimit_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_HiLoadStall_Per1_AssistStallLimit_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HILOADSTALL_APPL_CODE) HiLoadStall_Per1(void);

# define RTE_STOP_SEC_AP_HILOADSTALL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1348234741
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/HiLoadStall-nzt9hv/HiLoadStall/utp/contract/Rte_Ap_HiLoadStall.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1348234741
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_HILOADSTALL_H */
