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
 *          File:  Rte_Ap_StabilityComp2.h
 *     Workspace:  C:/CMSynergy_Projects/CBD/StabilityComp/autosar
 *     SW-C Type:  Ap_StabilityComp2
 *  Generated at:  Tue Apr 30 14:02:19 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_StabilityComp2> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_STABILITYCOMP2_H
# define _RTE_AP_STABILITYCOMP2_H

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

typedef P2CONST(struct Rte_CDS_Ap_StabilityComp2, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistDDFactor_Uls_f32 ((Float)1)
# define Rte_InitValue_AsstFWActive_Uls_f32 ((Float)0)
# define Rte_InitValue_CombinedAssist_MtrNm_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_SysAssistCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_StabilityComp2_Per1_AssistDDFactor_Uls_f32() \
  (Rte_Inst_Ap_StabilityComp2->StabilityComp2_Per1_AssistDDFactor_Uls_f32->value)

# define Rte_IRead_StabilityComp2_Per1_AsstFWActive_Uls_f32() \
  (Rte_Inst_Ap_StabilityComp2->StabilityComp2_Per1_AsstFWActive_Uls_f32->value)

# define Rte_IRead_StabilityComp2_Per1_CombinedAssist_MtrNm_f32() \
  (Rte_Inst_Ap_StabilityComp2->StabilityComp2_Per1_CombinedAssist_MtrNm_f32->value)

# define Rte_IRead_StabilityComp2_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_StabilityComp2->StabilityComp2_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_StabilityComp2_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_StabilityComp2->StabilityComp2_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_StabilityComp2_Per1_SysAssistCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_StabilityComp2->StabilityComp2_Per1_SysAssistCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_StabilityComp2_Per1_SysAssistCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_StabilityComp2->StabilityComp2_Per1_SysAssistCmd_MtrNm_f32->value)




# define RTE_START_SEC_AP_STABILITYCOMP2_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: StabilityComp2_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STABILITYCOMP2_APPL_CODE) StabilityComp2_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StabilityComp2_Per1
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
 *   Float Rte_IRead_StabilityComp2_Per1_AssistDDFactor_Uls_f32(void)
 *   Float Rte_IRead_StabilityComp2_Per1_AsstFWActive_Uls_f32(void)
 *   Float Rte_IRead_StabilityComp2_Per1_CombinedAssist_MtrNm_f32(void)
 *   Float Rte_IRead_StabilityComp2_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_StabilityComp2_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_StabilityComp2_Per1_SysAssistCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_StabilityComp2_Per1_SysAssistCmd_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STABILITYCOMP2_APPL_CODE) StabilityComp2_Per1(void);

# define RTE_STOP_SEC_AP_STABILITYCOMP2_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1367348078
#    error "The magic number of the generated file <C:/CMSynergy_Projects/CBD/StabilityComp/utp/contract/Ap_StabilityComp2/Rte_Ap_StabilityComp2.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1367348078
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_STABILITYCOMP2_H */
