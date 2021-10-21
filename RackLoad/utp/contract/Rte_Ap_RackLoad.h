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
 *          File:  Rte_Ap_RackLoad.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/RackLoad-nzt9hv/RackLoad/autosar
 *     SW-C Type:  Ap_RackLoad
 *  Generated at:  Sun Sep 23 15:10:41 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_RackLoad> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_RACKLOAD_H
# define _RTE_AP_RACKLOAD_H

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

typedef P2CONST(struct Rte_CDS_Ap_RackLoad, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CRFMtrTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_CRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_HwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HwPosAuth_Uls_f32 ((Float)0)
# define Rte_InitValue_HwTrq_HwNm_f32 ((Float)0)
# define Rte_InitValue_RackLoad_kN_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_RackLoad_Per1_CRFMtrTrqCmd_MtrNm_f32() \
  (Rte_Inst_Ap_RackLoad->RackLoad_Per1_CRFMtrTrqCmd_MtrNm_f32->value)

# define Rte_IRead_RackLoad_Per1_CRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_RackLoad->RackLoad_Per1_CRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_RackLoad_Per1_HwPosAuth_Uls_f32() \
  (Rte_Inst_Ap_RackLoad->RackLoad_Per1_HwPosAuth_Uls_f32->value)

# define Rte_IRead_RackLoad_Per1_HwPos_HwDeg_f32() \
  (Rte_Inst_Ap_RackLoad->RackLoad_Per1_HwPos_HwDeg_f32->value)

# define Rte_IRead_RackLoad_Per1_HwTrq_HwNm_f32() \
  (Rte_Inst_Ap_RackLoad->RackLoad_Per1_HwTrq_HwNm_f32->value)

# define Rte_IWrite_RackLoad_Per1_RackLoad_kN_f32(data) \
  ( \
  Rte_Inst_Ap_RackLoad->RackLoad_Per1_RackLoad_kN_f32->value = (data) \
  )

# define Rte_IWriteRef_RackLoad_Per1_RackLoad_kN_f32() \
  (&Rte_Inst_Ap_RackLoad->RackLoad_Per1_RackLoad_kN_f32->value)




# define RTE_START_SEC_AP_RACKLOAD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: RackLoad_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_RACKLOAD_APPL_CODE) RackLoad_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RackLoad_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_RackLoad_Per1_CRFMtrTrqCmd_MtrNm_f32(void)
 *   Float Rte_IRead_RackLoad_Per1_CRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_RackLoad_Per1_HwPosAuth_Uls_f32(void)
 *   Float Rte_IRead_RackLoad_Per1_HwPos_HwDeg_f32(void)
 *   Float Rte_IRead_RackLoad_Per1_HwTrq_HwNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_RackLoad_Per1_RackLoad_kN_f32(Float data)
 *   Float *Rte_IWriteRef_RackLoad_Per1_RackLoad_kN_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_RACKLOAD_APPL_CODE) RackLoad_Per1(void);

# define RTE_STOP_SEC_AP_RACKLOAD_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1348422400
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/RackLoad-nzt9hv/RackLoad/utp/contract/Rte_Ap_RackLoad.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1348422400
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_RACKLOAD_H */
