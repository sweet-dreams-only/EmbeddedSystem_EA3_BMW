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
 *          File:  Rte_Ap_BmwRtnArbn.h
 *     Workspace:  C:/SynergyWorkArea/Working/CBD_BmwRtnAbrn/autosar
 *     SW-C Type:  Ap_BmwRtnArbn
 *  Generated at:  Wed Feb 24 11:59:24 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_BmwRtnArbn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_BMWRTNARBN_H
# define _RTE_AP_BMWRTNARBN_H

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

typedef P2CONST(struct Rte_CDS_Ap_BmwRtnArbn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BasicRtnCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_DefeatReturnSvc_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsHwPosDis_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EnableCVR_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_MRFMtrTrqCmdScl_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PAReturnSclFct_Uls_f32 ((Float)1)
# define Rte_InitValue_ReturnCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_ReturnDDFactor_Uls_f32 ((Float)1)
# define Rte_InitValue_ReturnOffset_HwDeg_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_BmwRtnArbn_Per1_BasicRtnCmd_MtrNm_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_BasicRtnCmd_MtrNm_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_DefeatReturnSvc_Cnt_lgc() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_DefeatReturnSvc_Cnt_lgc->value)

# define Rte_IRead_BmwRtnArbn_Per1_DiagStsHwPosDis_Cnt_lgc() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_DiagStsHwPosDis_Cnt_lgc->value)

# define Rte_IRead_BmwRtnArbn_Per1_EnableCVR_Cnt_lgc() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_EnableCVR_Cnt_lgc->value)

# define Rte_IRead_BmwRtnArbn_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_HandwheelVelocity_HwRadpS_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_MRFMtrTrqCmdScl_MtrNm_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_PAReturnSclFct_Uls_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_PAReturnSclFct_Uls_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_ReturnDDFactor_Uls_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_ReturnDDFactor_Uls_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_ReturnOffset_HwDeg_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_ReturnOffset_HwDeg_f32->value)

# define Rte_IRead_BmwRtnArbn_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_BmwRtnArbn->BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32->value)




# define RTE_START_SEC_AP_BMWRTNARBN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwRtnArbn_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWRTNARBN_APPL_CODE) BmwRtnArbn_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwRtnArbn_Per1
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
 *   Float Rte_IRead_BmwRtnArbn_Per1_BasicRtnCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_BmwRtnArbn_Per1_DefeatReturnSvc_Cnt_lgc(void)
 *   Boolean Rte_IRead_BmwRtnArbn_Per1_DiagStsHwPosDis_Cnt_lgc(void)
 *   Boolean Rte_IRead_BmwRtnArbn_Per1_EnableCVR_Cnt_lgc(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_PAReturnSclFct_Uls_f32(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_ReturnDDFactor_Uls_f32(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_ReturnOffset_HwDeg_f32(void)
 *   Float Rte_IRead_BmwRtnArbn_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWRTNARBN_APPL_CODE) BmwRtnArbn_Per1(void);

# define RTE_STOP_SEC_AP_BMWRTNARBN_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1456338827
#    error "The magic number of the generated file <C:/SynergyWorkArea/Working/CBD_BmwRtnAbrn/tools/contract/Ap_BmwRtnArbn/Rte_Ap_BmwRtnArbn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1456338827
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_BMWRTNARBN_H */
