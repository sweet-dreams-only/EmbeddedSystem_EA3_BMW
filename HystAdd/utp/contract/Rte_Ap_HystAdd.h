


/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs.
  However, they are not thoroughly tested yet (beta-version).
  With regard to the fact that the programs are a beta-version only,
  Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence,
  to the extent admissible by law or statute.
*/



/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_HystAdd.h
 *     Workspace:  C:/Synergy_WorkArea/HystAdd-tzj9qy/HystAdd/autosar/Ap_HystAdd.dcf
 *     SW-C Type:  Ap_HystAdd
 *  Generated at:  Mon Nov 21 16:34:24 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_HystAdd> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_HYSTADD_H
# define _RTE_AP_HYSTADD_H

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

typedef P2CONST(struct Rte_CDS_Ap_HystAdd, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_HysAddHwTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_HysAddSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_VehSpd_Kph_f32 (0.0F)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_HystAdd_Per1_HwTrq_HwNm_f32() \
  (Rte_Inst_Ap_HystAdd->HystAdd_Per1_HwTrq_HwNm_f32->value)

# define Rte_IRead_HystAdd_Per1_HysAddSrlComSvcDft_Cnt_lgc() \
  (Rte_Inst_Ap_HystAdd->HystAdd_Per1_HysAddSrlComSvcDft_Cnt_lgc->value)

# define Rte_IRead_HystAdd_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_HystAdd->HystAdd_Per1_VehSpd_Kph_f32->value)

# define Rte_IWrite_HystAdd_Per1_HysAddHwTrq_HwNm_f32(data) \
  ( \
  Rte_Inst_Ap_HystAdd->HystAdd_Per1_HysAddHwTrq_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_HystAdd_Per1_HysAddHwTrq_HwNm_f32() \
  (&Rte_Inst_Ap_HystAdd->HystAdd_Per1_HysAddHwTrq_HwNm_f32->value)




# define RTE_START_SEC_AP_HYSTADD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HystAdd_Per1
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
 *   Float Rte_IRead_HystAdd_Per1_HwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_HystAdd_Per1_HysAddSrlComSvcDft_Cnt_lgc(void)
 *   Float Rte_IRead_HystAdd_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HystAdd_Per1_HysAddHwTrq_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_HystAdd_Per1_HysAddHwTrq_HwNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HYSTADD_APPL_CODE) HystAdd_Per1(void);

# define RTE_STOP_SEC_AP_HYSTADD_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1321913599
#    error "The magic number of the generated file <C:/Component Based Design/HystAdd/Ap_HystAdd/Rte_Ap_HystAdd.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1321913599
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_HYSTADD_H */
