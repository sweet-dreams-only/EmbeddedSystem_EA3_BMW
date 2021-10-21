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
 *          File:  Rte_Ap_MtrTempEst.h
 *     Workspace:  C:/_Synergy_Projects/Working/MtrTempEst-nz63rn/MtrTempEst/autosar
 *     SW-C Type:  Ap_MtrTempEst
 *  Generated at:  Wed Sep  4 10:05:17 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_MtrTempEst> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_MTRTEMPEST_H
# define _RTE_AP_MTRTEMPEST_H

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

typedef P2CONST(struct Rte_CDS_Ap_MtrTempEst, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AmbTemp_DegC_f32 ((Float)0)
# define Rte_InitValue_AssistMechTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_CtrlTempFinal_DegC_f32 ((Float)0)
# define Rte_InitValue_CuTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_EngTemp_DegC_f32 ((Float)0)
# define Rte_InitValue_EstPkCurr_AmpSq_f32 ((Float)0)
# define Rte_InitValue_HwVel_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_MagTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_ScomAMDefeat_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ScomTempDataRcvd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SiTempEst_DegC_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_MtrTempEst_Init1_AmbTemp_DegC_f32() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_AmbTemp_DegC_f32->value)

# define Rte_IRead_MtrTempEst_Init1_CtrlTempFinal_DegC_f32() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_CtrlTempFinal_DegC_f32->value)

# define Rte_IRead_MtrTempEst_Init1_EngTemp_DegC_f32() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_EngTemp_DegC_f32->value)

# define Rte_IWrite_MtrTempEst_Init1_AssistMechTempEst_DegC_f32(data) \
  ( \
  Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_AssistMechTempEst_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrTempEst_Init1_AssistMechTempEst_DegC_f32() \
  (&Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_AssistMechTempEst_DegC_f32->value)

# define Rte_IWrite_MtrTempEst_Init1_CuTempEst_DegC_f32(data) \
  ( \
  Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_CuTempEst_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrTempEst_Init1_CuTempEst_DegC_f32() \
  (&Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_CuTempEst_DegC_f32->value)

# define Rte_IWrite_MtrTempEst_Init1_MagTempEst_DegC_f32(data) \
  ( \
  Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_MagTempEst_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrTempEst_Init1_MagTempEst_DegC_f32() \
  (&Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_MagTempEst_DegC_f32->value)

# define Rte_IWrite_MtrTempEst_Init1_SiTempEst_DegC_f32(data) \
  ( \
  Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_SiTempEst_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrTempEst_Init1_SiTempEst_DegC_f32() \
  (&Rte_Inst_Ap_MtrTempEst->MtrTempEst_Init1_SiTempEst_DegC_f32->value)

# define Rte_IRead_MtrTempEst_Per1_AmbTemp_DegC_f32() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_AmbTemp_DegC_f32->value)

# define Rte_IRead_MtrTempEst_Per1_CtrlTempFinal_DegC_f32() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_CtrlTempFinal_DegC_f32->value)

# define Rte_IRead_MtrTempEst_Per1_EngTemp_DegC_f32() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_EngTemp_DegC_f32->value)

# define Rte_IRead_MtrTempEst_Per1_EstPkCurr_AmpSq_f32() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_EstPkCurr_AmpSq_f32->value)

# define Rte_IRead_MtrTempEst_Per1_HwVel_HwRadpS_f32() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_HwVel_HwRadpS_f32->value)

# define Rte_IRead_MtrTempEst_Per1_ScomAMDefeat_Cnt_lgc() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_ScomAMDefeat_Cnt_lgc->value)

# define Rte_IRead_MtrTempEst_Per1_ScomTempDataRcvd_Cnt_lgc() \
  (Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_ScomTempDataRcvd_Cnt_lgc->value)

# define Rte_IWrite_MtrTempEst_Per1_AssistMechTempEst_DegC_f32(data) \
  ( \
  Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_AssistMechTempEst_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrTempEst_Per1_AssistMechTempEst_DegC_f32() \
  (&Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_AssistMechTempEst_DegC_f32->value)

# define Rte_IWrite_MtrTempEst_Per1_CuTempEst_DegC_f32(data) \
  ( \
  Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_CuTempEst_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrTempEst_Per1_CuTempEst_DegC_f32() \
  (&Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_CuTempEst_DegC_f32->value)

# define Rte_IWrite_MtrTempEst_Per1_MagTempEst_DegC_f32(data) \
  ( \
  Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_MagTempEst_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrTempEst_Per1_MagTempEst_DegC_f32() \
  (&Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_MagTempEst_DegC_f32->value)

# define Rte_IWrite_MtrTempEst_Per1_SiTempEst_DegC_f32(data) \
  ( \
  Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_SiTempEst_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrTempEst_Per1_SiTempEst_DegC_f32() \
  (&Rte_Inst_Ap_MtrTempEst->MtrTempEst_Per1_SiTempEst_DegC_f32->value)




# define RTE_START_SEC_AP_MTRTEMPEST_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrTempEst_Init1
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
 *   Float Rte_IRead_MtrTempEst_Init1_AmbTemp_DegC_f32(void)
 *   Float Rte_IRead_MtrTempEst_Init1_CtrlTempFinal_DegC_f32(void)
 *   Float Rte_IRead_MtrTempEst_Init1_EngTemp_DegC_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrTempEst_Init1_AssistMechTempEst_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_MtrTempEst_Init1_AssistMechTempEst_DegC_f32(void)
 *   void Rte_IWrite_MtrTempEst_Init1_CuTempEst_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_MtrTempEst_Init1_CuTempEst_DegC_f32(void)
 *   void Rte_IWrite_MtrTempEst_Init1_MagTempEst_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_MtrTempEst_Init1_MagTempEst_DegC_f32(void)
 *   void Rte_IWrite_MtrTempEst_Init1_SiTempEst_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_MtrTempEst_Init1_SiTempEst_DegC_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_MTRTEMPEST_APPL_CODE) MtrTempEst_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrTempEst_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_MtrTempEst_Per1_AmbTemp_DegC_f32(void)
 *   Float Rte_IRead_MtrTempEst_Per1_CtrlTempFinal_DegC_f32(void)
 *   Float Rte_IRead_MtrTempEst_Per1_EngTemp_DegC_f32(void)
 *   Float Rte_IRead_MtrTempEst_Per1_EstPkCurr_AmpSq_f32(void)
 *   Float Rte_IRead_MtrTempEst_Per1_HwVel_HwRadpS_f32(void)
 *   Boolean Rte_IRead_MtrTempEst_Per1_ScomAMDefeat_Cnt_lgc(void)
 *   Boolean Rte_IRead_MtrTempEst_Per1_ScomTempDataRcvd_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrTempEst_Per1_AssistMechTempEst_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_MtrTempEst_Per1_AssistMechTempEst_DegC_f32(void)
 *   void Rte_IWrite_MtrTempEst_Per1_CuTempEst_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_MtrTempEst_Per1_CuTempEst_DegC_f32(void)
 *   void Rte_IWrite_MtrTempEst_Per1_MagTempEst_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_MtrTempEst_Per1_MagTempEst_DegC_f32(void)
 *   void Rte_IWrite_MtrTempEst_Per1_SiTempEst_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_MtrTempEst_Per1_SiTempEst_DegC_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_MTRTEMPEST_APPL_CODE) MtrTempEst_Per1(void);

# define RTE_STOP_SEC_AP_MTRTEMPEST_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1378297657
#    error "The magic number of the generated file <C:/_Synergy_Projects/Working/MtrTempEst-nz63rn/MtrTempEst/utp/contract/Ap_MtrTempEst/Rte_Ap_MtrTempEst.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1378297657
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_MTRTEMPEST_H */
