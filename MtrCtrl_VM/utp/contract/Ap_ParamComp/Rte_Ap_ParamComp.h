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
 *          File:  Rte_Ap_ParamComp.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_ParamComp
 *  Generated at:  Sat Apr 13 16:57:18 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_ParamComp> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PARAMCOMP_H
# define _RTE_AP_PARAMCOMP_H

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

typedef P2CONST(struct Rte_CDS_Ap_ParamComp, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CuTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_EstKe_VpRadpS_f32 ((Float)0)
# define Rte_InitValue_EstLd_Henry_f32 ((Float)0)
# define Rte_InitValue_EstLq_Henry_f32 ((Float)0)
# define Rte_InitValue_EstR_Ohm_f32 ((Float)0)
# define Rte_InitValue_ExpIq_Amp_f32 ((Float)0)
# define Rte_InitValue_IdEst_Amp_f32 ((Float)0)
# define Rte_InitValue_MRFMtrTrqCmdScl_MtrNm_f32 ((Float)0)
# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MagTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQax_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrQuad_Cnt_u08 ((UInt8)1u)
# define Rte_InitValue_SiTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_ValidCurrSample_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ParamComp_EOLNomMtrParamBlk_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_ParamComp_EOLNomMtrParamBlk_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_DATA) DstPtr);
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_ParamComp_Init1_EstKe_VpRadpS_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Init1_EstKe_VpRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Init1_EstKe_VpRadpS_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Init1_EstKe_VpRadpS_f32->value)

# define Rte_IWrite_ParamComp_Init1_EstLd_Henry_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Init1_EstLd_Henry_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Init1_EstLd_Henry_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Init1_EstLd_Henry_f32->value)

# define Rte_IWrite_ParamComp_Init1_EstLq_Henry_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Init1_EstLq_Henry_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Init1_EstLq_Henry_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Init1_EstLq_Henry_f32->value)

# define Rte_IWrite_ParamComp_Init1_EstR_Ohm_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Init1_EstR_Ohm_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Init1_EstR_Ohm_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Init1_EstR_Ohm_f32->value)

# define Rte_IRead_ParamComp_Per1_IdEst_Amp_f32() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per1_IdEst_Amp_f32->value)

# define Rte_IRead_ParamComp_Per1_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per1_MRFMtrTrqCmdScl_MtrNm_f32->value)

# define Rte_IRead_ParamComp_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per1_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_ParamComp_Per1_MtrCurrQax_Amp_f32() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per1_MtrCurrQax_Amp_f32->value)

# define Rte_IRead_ParamComp_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IRead_ParamComp_Per1_MtrQuad_Cnt_u08() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per1_MtrQuad_Cnt_u08->value)

# define Rte_IRead_ParamComp_Per1_ValidCurrSample_Cnt_lgc() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per1_ValidCurrSample_Cnt_lgc->value)

# define Rte_IWrite_ParamComp_Per1_EstKe_VpRadpS_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Per1_EstKe_VpRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Per1_EstKe_VpRadpS_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Per1_EstKe_VpRadpS_f32->value)

# define Rte_IWrite_ParamComp_Per1_EstLd_Henry_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Per1_EstLd_Henry_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Per1_EstLd_Henry_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Per1_EstLd_Henry_f32->value)

# define Rte_IWrite_ParamComp_Per1_EstLq_Henry_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Per1_EstLq_Henry_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Per1_EstLq_Henry_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Per1_EstLq_Henry_f32->value)

# define Rte_IWrite_ParamComp_Per1_EstR_Ohm_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Per1_EstR_Ohm_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Per1_EstR_Ohm_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Per1_EstR_Ohm_f32->value)

# define Rte_IWrite_ParamComp_Per1_ExpIq_Amp_f32(data) \
  ( \
  Rte_Inst_Ap_ParamComp->ParamComp_Per1_ExpIq_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_ParamComp_Per1_ExpIq_Amp_f32() \
  (&Rte_Inst_Ap_ParamComp->ParamComp_Per1_ExpIq_Amp_f32->value)

# define Rte_IRead_ParamComp_Per2_CuTempEst_DegC_f32() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per2_CuTempEst_DegC_f32->value)

# define Rte_IRead_ParamComp_Per2_MagTempEst_DegC_f32() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per2_MagTempEst_DegC_f32->value)

# define Rte_IRead_ParamComp_Per2_SiTempEst_DegC_f32() \
  (Rte_Inst_Ap_ParamComp->ParamComp_Per2_SiTempEst_DegC_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLNomMtrParamBlk_WriteBlock Rte_Call_Ap_ParamComp_EOLNomMtrParamBlk_WriteBlock


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_EOLNomMtrParam() (Rte_Inst_Ap_ParamComp->Pim_EOLNomMtrParam)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   EOLNomMtrParamType *Rte_Pim_EOLNomMtrParam(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_PARAMCOMP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ParamComp_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ParamComp_Init1_EstKe_VpRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Init1_EstKe_VpRadpS_f32(void)
 *   void Rte_IWrite_ParamComp_Init1_EstLd_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Init1_EstLd_Henry_f32(void)
 *   void Rte_IWrite_ParamComp_Init1_EstLq_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Init1_EstLq_Henry_f32(void)
 *   void Rte_IWrite_ParamComp_Init1_EstR_Ohm_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Init1_EstR_Ohm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ParamComp_Per1
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
 *   Float Rte_IRead_ParamComp_Per1_IdEst_Amp_f32(void)
 *   Float Rte_IRead_ParamComp_Per1_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *   Float Rte_IRead_ParamComp_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_ParamComp_Per1_MtrCurrQax_Amp_f32(void)
 *   Boolean Rte_IRead_ParamComp_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   UInt8 Rte_IRead_ParamComp_Per1_MtrQuad_Cnt_u08(void)
 *   Boolean Rte_IRead_ParamComp_Per1_ValidCurrSample_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ParamComp_Per1_EstKe_VpRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_EstKe_VpRadpS_f32(void)
 *   void Rte_IWrite_ParamComp_Per1_EstLd_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_EstLd_Henry_f32(void)
 *   void Rte_IWrite_ParamComp_Per1_EstLq_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_EstLq_Henry_f32(void)
 *   void Rte_IWrite_ParamComp_Per1_EstR_Ohm_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_EstR_Ohm_f32(void)
 *   void Rte_IWrite_ParamComp_Per1_ExpIq_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_ExpIq_Amp_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ParamComp_Per2
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
 *   Float Rte_IRead_ParamComp_Per2_CuTempEst_DegC_f32(void)
 *   Float Rte_IRead_ParamComp_Per2_MagTempEst_DegC_f32(void)
 *   Float Rte_IRead_ParamComp_Per2_SiTempEst_DegC_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_EOLNomMtrParam_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_EOLNomMtrParam_Get(Float *NomKe_VpRadpS_f32, Float *NomLq_Henry_f32, Float *NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomLq_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_EOLNomMtrParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLNomMtrParamBlk_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_EOLNomMtrParamBlk_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_KeIntgSVParam_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <SCom_KeIntgSVParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_KeIntgSVParam_Get(Float *KeIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) KeIntgSV_Amp_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_KeIntgSVParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_KeIntgSVParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_RIntgSVParam_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <SCom_RIntgSVParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_RIntgSVParam_Get(Float *RIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) RIntgSV_Amp_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_RIntgSVParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_RIntgSVParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32);

# define RTE_STOP_SEC_AP_PARAMCOMP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1365887252
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/utp/contract/Ap_ParamComp/Rte_Ap_ParamComp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1365887252
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PARAMCOMP_H */
