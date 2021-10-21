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
 *          File:  Rte_Ap_SrlComInput.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComInput/autosar
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Fri Apr 28 14:53:33 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComInput> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

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

typedef P2CONST(struct Rte_CDS_Ap_SrlComInput, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS (0U)
# define Rte_InitValue_CDRVDYNMSG_Cnt_lgc (FALSE)
# define Rte_InitValue_CERRMVOLTFALLBACK_Cnt_lgc (FALSE)
# define Rte_InitValue_CFACTORIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWACORRECTION_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWANGLEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWTORQUEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CMTTORQUEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS (0U)
# define Rte_InitValue_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS (0U)
# define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc (FALSE)
# define Rte_InitValue_ENERG_DGR_DRDY_MAX_I_SPEC_EPS (0U)
# define Rte_InitValue_ErrmBnU_Cnt_u8 (0U)
# define Rte_InitValue_HaptcFbIntenNr_Cnt_u16 (0U)
# define Rte_InitValue_HaptcFbIntenSigVld_Cnt_lgc (FALSE)
# define Rte_InitValue_HaptcFbPatNr_Cnt_u16 (0U)
# define Rte_InitValue_HaptcFbPatSigVld_Cnt_lgc (FALSE)
# define Rte_InitValue_IgnTimeOff_Cnt_u32 (0U)
# define Rte_InitValue_ReturnOffset_HwDeg_f32 (0.0F)
# define Rte_InitValue_RxCtrErrmBnU_Cnt_u8 (0U)
# define Rte_InitValue_RxILK_ERRM_FZM_Cnt_u8 (0U)
# define Rte_InitValue_RxMILE_KM_Cnt_u32 (0U)
# define Rte_InitValue_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP (0U)
# define Rte_InitValue_SrlComSTKL_ST_KL (0U)
# define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
# define Rte_InitValue_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP (3U)
# define Rte_InitValue_SupplyCurrLmt_Amp_f32 (166.67F)
# define Rte_InitValue_VINValid_Cnt_lgc (FALSE)
# define Rte_InitValue_VehTimeValid_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ACLNY_MASSCNTR_ACLNY_MASSCNTR(P2VAR(SG_ACLNY_MASSCNTR, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(P2VAR(AVL_STEA_PNI_OFFS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_CON_VEH_CON_VEH(P2VAR(SG_CON_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS(P2VAR(New_Coding_75, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS(P2VAR(New_Coding_71, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ENERG_DGR_DRDY_MAX_I_SPEC_EPS(P2VAR(New_Coding_94, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(P2VAR(SG_OFFS_QUAD_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV(P2VAR(SG_TAR_QTA_STRMOM_DV, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT(P2VAR(SG_TAR_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SG_V_VEH_SG_V_VEH(P2VAR(SG_V_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ST_CENG_ST_CENG(P2VAR(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP(P2VAR(New_Coding_79, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SrlComSvcDft_Cnt_b32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_VYAW_VEH_VYAW_VEH(P2VAR(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# ifndef RTE_DISABLE_ISUPDATED
FUNC(boolean, RTE_CODE) Rte_IsUpdated_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(void);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_ErrmBnU_Cnt_u8(CTR_ERRM_BN_U data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaptcFbIntenNr_Cnt_u16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaptcFbPatNr_Cnt_u16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaptcFbPatSigVld_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_IgnTimeOff_Cnt_u32(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS(P2CONST(SG_ANFRAGE_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(P2CONST(SG_ACLNY_MASSCNTR, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComCONVEH_CON_VEH(P2CONST(SG_CON_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(P2CONST(SG_OFFS_QUAD_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(P2CONST(SG_TAR_QTA_STRMOM_DV, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(P2CONST(SG_TAR_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGVVEH_SG_V_VEH(P2CONST(SG_V_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSTCENG_ST_CENG(P2CONST(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSTKL_ST_KL(UInt4 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComVYAWVEH_VYAW_VEH(P2CONST(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SupplyCurrLmt_Amp_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VINValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VehTimeValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_SrlComInput_Init_IgnTimeOff_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_IgnTimeOff_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_IgnTimeOff_Cnt_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_IgnTimeOff_Cnt_u32->value)

# define Rte_IWrite_SrlComInput_Init_SrlComSTKL_ST_KL(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_SrlComSTKL_ST_KL->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_SrlComSTKL_ST_KL() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_SrlComSTKL_ST_KL->value)

# define Rte_IWrite_SrlComInput_Init_VehTimeValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_VehTimeValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_VehTimeValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_VehTimeValid_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_CERRMVOLTFALLBACK_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CERRMVOLTFALLBACK_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_DiagStsDefVehSpd_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_RxCtrErrmBnU_Cnt_u8() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_RxCtrErrmBnU_Cnt_u8->value)

# define Rte_IRead_SrlComInput_Per1_SrlComSvcDft_Cnt_b32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_SrlComSvcDft_Cnt_b32->value)

# define Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_CHWACORRECTION_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_AvlSteaPniOffsLoss_CHWACORRECTION_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_SrlComSvcDft_Cnt_b32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_AvlSteaPniOffsLoss_SrlComSvcDft_Cnt_b32->value)

# define Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_PaDrvDynLoss_CHWTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_PaDrvDynLoss_CMTTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_CHWACORRECTION_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxAvlSteaPniOffs_CHWACORRECTION_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_SrlComSvcDft_Cnt_b32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxAvlSteaPniOffs_SrlComSvcDft_Cnt_b32->value)

# define Rte_IWrite_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32->value)

# define Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32->value)

# define Rte_IRead_SrlComInput_TRGD_RxTuningSel_CDRVDYNMSG_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxTuningSel_CDRVDYNMSG_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP->value)

# define Rte_IRead_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH->value)

# define Rte_IStatus_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH->status)

# define Rte_IRead_SrlComInput_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_TRGD_TuningSelLoss_CDRVDYNMSG_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_TRGD_TuningSelLoss_CDRVDYNMSG_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_ACLNY_MASSCNTR_ACLNY_MASSCNTR Rte_Read_Ap_SrlComInput_ACLNY_MASSCNTR_ACLNY_MASSCNTR
# define Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS Rte_Read_Ap_SrlComInput_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS
# define Rte_Read_CON_VEH_CON_VEH Rte_Read_Ap_SrlComInput_CON_VEH_CON_VEH
# define Rte_Read_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS
# define Rte_Read_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS
# define Rte_Read_ENERG_DGR_DRDY_MAX_I_SPEC_EPS Rte_Read_Ap_SrlComInput_ENERG_DGR_DRDY_MAX_I_SPEC_EPS
# define Rte_Read_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS Rte_Read_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS
# define Rte_Read_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV Rte_Read_Ap_SrlComInput_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV
# define Rte_Read_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT Rte_Read_Ap_SrlComInput_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT
# define Rte_Read_SG_V_VEH_SG_V_VEH Rte_Read_Ap_SrlComInput_SG_V_VEH_SG_V_VEH
# define Rte_Read_ST_CENG_ST_CENG Rte_Read_Ap_SrlComInput_ST_CENG_ST_CENG
# define Rte_Read_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP Rte_Read_Ap_SrlComInput_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP
# define Rte_Read_SrlComSvcDft_Cnt_b32 Rte_Read_Ap_SrlComInput_SrlComSvcDft_Cnt_b32
# define Rte_Read_VYAW_VEH_VYAW_VEH Rte_Read_Ap_SrlComInput_VYAW_VEH_VYAW_VEH


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS Rte_IsUpdated_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_ErrmBnU_Cnt_u8 Rte_Write_Ap_SrlComInput_ErrmBnU_Cnt_u8
# define Rte_Write_HaptcFbIntenNr_Cnt_u16 Rte_Write_Ap_SrlComInput_HaptcFbIntenNr_Cnt_u16
# define Rte_Write_HaptcFbIntenSigVld_Cnt_lgc Rte_Write_Ap_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc
# define Rte_Write_HaptcFbPatNr_Cnt_u16 Rte_Write_Ap_SrlComInput_HaptcFbPatNr_Cnt_u16
# define Rte_Write_HaptcFbPatSigVld_Cnt_lgc Rte_Write_Ap_SrlComInput_HaptcFbPatSigVld_Cnt_lgc
# define Rte_Write_IgnTimeOff_Cnt_u32 Rte_Write_Ap_SrlComInput_IgnTimeOff_Cnt_u32
# define Rte_Write_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS Rte_Write_Ap_SrlComInput_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS
# define Rte_Write_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR Rte_Write_Ap_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR
# define Rte_Write_SrlComCONVEH_CON_VEH Rte_Write_Ap_SrlComInput_SrlComCONVEH_CON_VEH
# define Rte_Write_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS Rte_Write_Ap_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS
# define Rte_Write_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV Rte_Write_Ap_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
# define Rte_Write_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT Rte_Write_Ap_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
# define Rte_Write_SrlComSGVVEH_SG_V_VEH Rte_Write_Ap_SrlComInput_SrlComSGVVEH_SG_V_VEH
# define Rte_Write_SrlComSTCENG_ST_CENG Rte_Write_Ap_SrlComInput_SrlComSTCENG_ST_CENG
# define Rte_Write_SrlComSTKL_ST_KL Rte_Write_Ap_SrlComInput_SrlComSTKL_ST_KL
# define Rte_Write_SrlComVYAWVEH_VYAW_VEH Rte_Write_Ap_SrlComInput_SrlComVYAWVEH_VYAW_VEH
# define Rte_Write_SupplyCurrLmt_Amp_f32 Rte_Write_Ap_SrlComInput_SupplyCurrLmt_Amp_f32
# define Rte_Write_VINValid_Cnt_lgc Rte_Write_Ap_SrlComInput_VINValid_Cnt_lgc
# define Rte_Write_VehTimeValid_Cnt_lgc Rte_Write_Ap_SrlComInput_VehTimeValid_Cnt_lgc


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComInput_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_GetNTCStatus Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
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
 *   void Rte_IWrite_SrlComInput_Init_IgnTimeOff_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Init_IgnTimeOff_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Init_SrlComSTKL_ST_KL(UInt4 data)
 *   UInt4 *Rte_IWriteRef_SrlComInput_Init_SrlComSTKL_ST_KL(void)
 *   void Rte_IWrite_SrlComInput_Init_VehTimeValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_VehTimeValid_Cnt_lgc(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
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
 *   Boolean Rte_IRead_SrlComInput_Per1_CERRMVOLTFALLBACK_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_DiagStsDefVehSpd_Cnt_lgc(void)
 *   CTR_ERRM_BN_U Rte_IRead_SrlComInput_Per1_RxCtrErrmBnU_Cnt_u8(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ErrmBnU_Cnt_u8(CTR_ERRM_BN_U data)
 *   Std_ReturnType Rte_Write_IgnTimeOff_Cnt_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_VehTimeValid_Cnt_lgc(Boolean data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_AclnyCogLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <ACLNY_MASSCNTR> of PortPrototype <ACLNY_MASSCNTR>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_AclnyCogLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_AvlSteaPniOffsLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <AVL_STEA_PNI_OFFS> of PortPrototype <AVL_STEA_PNI_OFFS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_CHWACORRECTION_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_SrlComSvcDft_Cnt_b32(void)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_AvlSteaPniOffsLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_ConVehLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CON_VEH> of PortPrototype <CON_VEH>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_ConVehLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_CtrVibStwDispLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CTR_WARN_ILVL_VIB_EPS> of PortPrototype <CTR_VIB_STW_DISP>
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CTR_WARN_PTRN_VIB_EPS> of PortPrototype <CTR_VIB_STW_DISP>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_CtrVibStwDispLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_EnergDgrDrdyLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <MAX_I_SPEC_EPS> of PortPrototype <ENERG_DGR_DRDY>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_EnergDgrDrdyLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_FZZSTDLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <Cnt_u8> of PortPrototype <RxILK_ERRM_FZM>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_FZZSTDLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_MileKMLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <Cnt_u32> of PortPrototype <RxMILE_KM>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_MileKMLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_PaDrvDynLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SG_TAR_QTA_STRMOM_DV> of PortPrototype <SG_TAR_QTA_STRMOM_DV>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CMTTORQUEIF_Cnt_lgc(void)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_PaDrvDynLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxAclnyCog
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ACLNY_MASSCNTR> of PortPrototype <ACLNY_MASSCNTR>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ACLNY_MASSCNTR_ACLNY_MASSCNTR(SG_ACLNY_MASSCNTR *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(const SG_ACLNY_MASSCNTR *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxAclnyCog(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxAvlSteaPniOffs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <AVL_STEA_PNI_OFFS> of PortPrototype <AVL_STEA_PNI_OFFS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(AVL_STEA_PNI_OFFS *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_CHWACORRECTION_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32(void)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxAvlSteaPniOffs(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxConVeh
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <CON_VEH> of PortPrototype <CON_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CON_VEH_CON_VEH(SG_CON_VEH *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComCONVEH_CON_VEH(const SG_CON_VEH *data)
 *   Std_ReturnType Rte_Write_SrlComSTKL_ST_KL(UInt4 data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxConVeh(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxCtrVibStwDisp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <CTR_WARN_ILVL_VIB_EPS> of PortPrototype <CTR_VIB_STW_DISP>
 *   - triggered on DataReceivedEvent for DataElementPrototype <CTR_WARN_PTRN_VIB_EPS> of PortPrototype <CTR_VIB_STW_DISP>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS(New_Coding_75 *data)
 *   Std_ReturnType Rte_Read_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS(New_Coding_71 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HaptcFbIntenNr_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_HaptcFbIntenSigVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaptcFbPatNr_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_HaptcFbPatSigVld_Cnt_lgc(Boolean data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxCtrVibStwDisp(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxEnergDgrDrdy
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MAX_I_SPEC_EPS> of PortPrototype <ENERG_DGR_DRDY>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ENERG_DGR_DRDY_MAX_I_SPEC_EPS(New_Coding_94 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SupplyCurrLmt_Amp_f32(Float data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxEnergDgrDrdy(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxPaDrvDyn
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_TAR_STMOM_DV_ACT> of PortPrototype <SG_TAR_STMOM_DV_ACT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV(SG_TAR_QTA_STRMOM_DV *data)
 *   Std_ReturnType Rte_Read_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT(SG_TAR_STMOM_DV_ACT *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(const SG_TAR_QTA_STRMOM_DV *data)
 *   Std_ReturnType Rte_Write_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(const SG_TAR_STMOM_DV_ACT *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxPaDrvDyn(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxRevOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_OFFS_QUAD_EPS> of PortPrototype <SG_OFFS_QUAD_EPS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(SG_OFFS_QUAD_EPS *data)
 *   boolean Rte_IsUpdated_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_SrlComInput_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(const SG_OFFS_QUAD_EPS *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxRevOffset(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxRevOffsetLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SG_OFFS_QUAD_EPS> of PortPrototype <SG_OFFS_QUAD_EPS>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxRevOffsetLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxStCeng
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ST_CENG> of PortPrototype <ST_CENG>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ST_CENG_ST_CENG(SG_ST_CENG *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComSTCENG_ST_CENG(const SG_ST_CENG *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxStCeng(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxTuningSel
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SU_CLU_STMOM_SFE_DXP> of PortPrototype <SU_CLE_DRDY_DXP>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP(New_Coding_79 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxTuningSel_CDRVDYNMSG_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(New_Coding_79 data)
 *   New_Coding_79 *Rte_IWriteRef_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(void)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxTuningSel(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxVIN
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VIN_NO_VECH> of PortPrototype <RxVIN>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   RT_VIN_NO_VECH *Rte_IRead_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS(const SG_ANFRAGE_EPS *data)
 *   Std_ReturnType Rte_Write_VINValid_Cnt_lgc(Boolean data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVIN(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxVYawVeh
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VYAW_VEH> of PortPrototype <VYAW_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VYAW_VEH_VYAW_VEH(SG_VYAW_VEH *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVYAWVEH_VYAW_VEH(const SG_VYAW_VEH *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVYawVeh(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_V_VEH> of PortPrototype <SG_V_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_V_VEH_SG_V_VEH(SG_V_VEH *data)
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComSGVVEH_SG_V_VEH(const SG_V_VEH *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVehSpd(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_StCengLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <ST_CENG> of PortPrototype <ST_CENG>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_StCengLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_TuningSelLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SU_CLU_STMOM_SFE_DXP> of PortPrototype <SU_CLE_DRDY_DXP>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_TuningSelLoss_CDRVDYNMSG_Cnt_lgc(void)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_TuningSelLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_VINLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <VIN_NO_VECH> of PortPrototype <RxVIN>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS(const SG_ANFRAGE_EPS *data)
 *   Std_ReturnType Rte_Write_VINValid_Cnt_lgc(Boolean data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VINLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_VYawVehLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <VYAW_VEH> of PortPrototype <VYAW_VEH>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VYawVehLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_VehSpdLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SG_V_VEH> of PortPrototype <SG_V_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VehSpdLoss(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1457566584
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComInput/utp/contract/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1457566584
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMINPUT_H */
