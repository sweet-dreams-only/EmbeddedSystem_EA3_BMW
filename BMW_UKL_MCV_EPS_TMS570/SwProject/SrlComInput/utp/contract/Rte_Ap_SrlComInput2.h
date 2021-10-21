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
 *          File:  Rte_Ap_SrlComInput2.h
 *     Workspace:  C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComInput/autosar
 *     SW-C Type:  Ap_SrlComInput2
 *  Generated at:  Thu Jun  1 11:56:35 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComInput2> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT2_H
# define _RTE_AP_SRLCOMINPUT2_H

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

typedef P2CONST(struct Rte_CDS_Ap_SrlComInput2, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CADASIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CFACTORIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWANGLEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CHWTORQUEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_CMTTORQUEIF_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc (FALSE)
# define Rte_InitValue_FRVldVehSpd_Kph_f32 (0.0F)
# define Rte_InitValue_SerlComTarSteerTqDrvrActr_MtrNm_f32 (0.0F)
# define Rte_InitValue_SrlComAssistScaleFactor_Uls_f32 (1.0F)
# define Rte_InitValue_SrlComCRFRevOffset_Rev_s16 (0)
# define Rte_InitValue_SrlComDampingScaleFactor_Uls_f32 (1.0F)
# define Rte_InitValue_SrlComDrvDynEnable_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComDrvDynInvalid_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComEngCrank_Cnt_lgc (TRUE)
# define Rte_InitValue_SrlComInputTorqueOverlay_HwNm_f32 (0.0F)
# define Rte_InitValue_SrlComReturnScaleFactor_Uls_f32 (1.0F)
# define Rte_InitValue_SrlComRevOffsetSts_Cnt_u08 (8U)
# define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
# define Rte_InitValue_SrlComVehCdnStatus_VehCdnStatus (0U)
# define Rte_InitValue_SrlComVehDrvCondition_Cnt_u08 (0U)
# define Rte_InitValue_SrlComVehLatAccel_MpSecSq_f32 (0.0F)
# define Rte_InitValue_SrlComVehLatAccelValid_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComVehNearStandstill_Cnt_u08 (15U)
# define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
# define Rte_InitValue_SrlComVehYawRate_DegpS_f32 (0.0F)
# define Rte_InitValue_SrlComVehYawRateValid_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlCom_QU_V_VEH_COG_Cnt_u08 (0U)
# define Rte_InitValue_TJADampSclRqst_Uls_f32 (0.0F)
# define Rte_InitValue_TJAStateRqst_Cnt_enum (1U)
# define Rte_InitValue_VehSpdValid_Cnt_lgc (FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(P2VAR(SG_ACLNY_MASSCNTR, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComCONVEH_CON_VEH(P2VAR(SG_CON_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(P2VAR(SG_OFFS_QUAD_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(P2VAR(SG_TAR_QTA_STRMOM_DV, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(P2VAR(SG_TAR_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH(P2VAR(SG_V_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSTCENG_ST_CENG(P2VAR(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComSvcDft_Cnt_b32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH(P2VAR(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_VehicleSpeed_Kph_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
# ifndef RTE_DISABLE_ISUPDATED
FUNC(boolean, RTE_CODE) Rte_IsUpdated_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(void);
FUNC(boolean, RTE_CODE) Rte_IsUpdated_Ap_SrlComInput2_SrlComCONVEH_CON_VEH(void);
FUNC(boolean, RTE_CODE) Rte_IsUpdated_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(void);
FUNC(boolean, RTE_CODE) Rte_IsUpdated_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(void);
FUNC(boolean, RTE_CODE) Rte_IsUpdated_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(void);
FUNC(boolean, RTE_CODE) Rte_IsUpdated_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH(void);
FUNC(boolean, RTE_CODE) Rte_IsUpdated_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH(void);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_FRVldVehSpd_Kph_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComAssistScaleFactor_Uls_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComCRFRevOffset_Rev_s16(SInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComDampingScaleFactor_Uls_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComEngDrvStatus_ST_CENG(P2CONST(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComInputTorqueOverlay_HwNm_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComReturnScaleFactor_Uls_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComRevOffsetSts_Cnt_u08(ST_OFFS_QUAD_EPS data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus(New_Coding_64 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComVehDrvCondition_Cnt_u08(DVCO_VEH data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComVehNearStandstill_Cnt_u08(ST_V_VEH_NSS data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComVehSpd_Kph_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComVehYawRate_DegpS_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08(QU_V_VEH_COG data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_TJADampSclRqst_Uls_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_TJAStateRqst_Cnt_enum(TJAStateType data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput2_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput2_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput2_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SrlComInput2_Per1_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_Per1_DiagStsDefVehSpd_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_Per1_SrlComSvcDft_Cnt_b32() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_Per1_SrlComSvcDft_Cnt_b32->value)

# define Rte_IWrite_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput2->SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput2->SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput2_Per1_VehSpdValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput2->SrlComInput2_Per1_VehSpdValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput2_Per1_VehSpdValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput2->SrlComInput2_Per1_VehSpdValid_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CADASIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_RxPaDrvDyn_CADASIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32->value)

# define Rte_IRead_SrlComInput2_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CFACTORIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_VehCfgUpdate_CFACTORIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CHWANGLEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_VehCfgUpdate_CHWANGLEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_VehCfgUpdate_CHWTORQUEIF_Cnt_lgc->value)

# define Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput2->SrlComInput2_TRGD_VehCfgUpdate_CMTTORQUEIF_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR Rte_Read_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR
# define Rte_Read_SrlComCONVEH_CON_VEH Rte_Read_Ap_SrlComInput2_SrlComCONVEH_CON_VEH
# define Rte_Read_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS Rte_Read_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS
# define Rte_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV Rte_Read_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
# define Rte_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT Rte_Read_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
# define Rte_Read_SrlComSGVVEH_SG_V_VEH Rte_Read_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH
# define Rte_Read_SrlComSTCENG_ST_CENG Rte_Read_Ap_SrlComInput2_SrlComSTCENG_ST_CENG
# define Rte_Read_SrlComSvcDft_Cnt_b32 Rte_Read_Ap_SrlComInput2_SrlComSvcDft_Cnt_b32
# define Rte_Read_SrlComVYAWVEH_VYAW_VEH Rte_Read_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH
# define Rte_Read_VehicleSpeed_Kph_f32 Rte_Read_Ap_SrlComInput2_VehicleSpeed_Kph_f32


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR Rte_IsUpdated_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR
# define Rte_IsUpdated_SrlComCONVEH_CON_VEH Rte_IsUpdated_Ap_SrlComInput2_SrlComCONVEH_CON_VEH
# define Rte_IsUpdated_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS Rte_IsUpdated_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS
# define Rte_IsUpdated_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV Rte_IsUpdated_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
# define Rte_IsUpdated_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT Rte_IsUpdated_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
# define Rte_IsUpdated_SrlComSGVVEH_SG_V_VEH Rte_IsUpdated_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH
# define Rte_IsUpdated_SrlComVYAWVEH_VYAW_VEH Rte_IsUpdated_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_FRVldVehSpd_Kph_f32 Rte_Write_Ap_SrlComInput2_FRVldVehSpd_Kph_f32
# define Rte_Write_SerlComTarSteerTqDrvrActr_MtrNm_f32 Rte_Write_Ap_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32
# define Rte_Write_SrlComAssistScaleFactor_Uls_f32 Rte_Write_Ap_SrlComInput2_SrlComAssistScaleFactor_Uls_f32
# define Rte_Write_SrlComCRFRevOffset_Rev_s16 Rte_Write_Ap_SrlComInput2_SrlComCRFRevOffset_Rev_s16
# define Rte_Write_SrlComDampingScaleFactor_Uls_f32 Rte_Write_Ap_SrlComInput2_SrlComDampingScaleFactor_Uls_f32
# define Rte_Write_SrlComDrvDynEnable_Cnt_lgc Rte_Write_Ap_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc
# define Rte_Write_SrlComDrvDynInvalid_Cnt_lgc Rte_Write_Ap_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc
# define Rte_Write_SrlComEngDrvStatus_ST_CENG Rte_Write_Ap_SrlComInput2_SrlComEngDrvStatus_ST_CENG
# define Rte_Write_SrlComInputTorqueOverlay_HwNm_f32 Rte_Write_Ap_SrlComInput2_SrlComInputTorqueOverlay_HwNm_f32
# define Rte_Write_SrlComReturnScaleFactor_Uls_f32 Rte_Write_Ap_SrlComInput2_SrlComReturnScaleFactor_Uls_f32
# define Rte_Write_SrlComRevOffsetSts_Cnt_u08 Rte_Write_Ap_SrlComInput2_SrlComRevOffsetSts_Cnt_u08
# define Rte_Write_SrlComVehCdnStatus_VehCdnStatus Rte_Write_Ap_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus
# define Rte_Write_SrlComVehDrvCondition_Cnt_u08 Rte_Write_Ap_SrlComInput2_SrlComVehDrvCondition_Cnt_u08
# define Rte_Write_SrlComVehLatAccel_MpSecSq_f32 Rte_Write_Ap_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32
# define Rte_Write_SrlComVehLatAccelValid_Cnt_lgc Rte_Write_Ap_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc
# define Rte_Write_SrlComVehNearStandstill_Cnt_u08 Rte_Write_Ap_SrlComInput2_SrlComVehNearStandstill_Cnt_u08
# define Rte_Write_SrlComVehSpd_Kph_f32 Rte_Write_Ap_SrlComInput2_SrlComVehSpd_Kph_f32
# define Rte_Write_SrlComVehYawRate_DegpS_f32 Rte_Write_Ap_SrlComInput2_SrlComVehYawRate_DegpS_f32
# define Rte_Write_SrlComVehYawRateValid_Cnt_lgc Rte_Write_Ap_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc
# define Rte_Write_SrlCom_QU_V_VEH_COG_Cnt_u08 Rte_Write_Ap_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08
# define Rte_Write_TJADampSclRqst_Uls_f32 Rte_Write_Ap_SrlComInput2_TJADampSclRqst_Uls_f32
# define Rte_Write_TJAStateRqst_Cnt_enum Rte_Write_Ap_SrlComInput2_TJAStateRqst_Cnt_enum


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComInput2_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_GetNTCStatus Rte_Call_Ap_SrlComInput2_NxtrDiagMgr_GetNTCStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_SrlComInput2_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_SRLCOMINPUT2_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_Per1
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
 *   Boolean Rte_IRead_SrlComInput2_Per1_DiagStsDefVehSpd_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput2_Per1_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComDrvDynInvalid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput2_Per1_VehSpdValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput2_Per1_VehSpdValid_Cnt_lgc(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_Scom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxAclnyMassCntr
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ACLNY_MASSCNTR> of PortPrototype <SrlComACLNYMASSCNTR>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(SG_ACLNY_MASSCNTR *data)
 *   boolean Rte_IsUpdated_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVehLatAccel_MpSecSq_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehLatAccelValid_Cnt_lgc(Boolean data)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxAclnyMassCntr(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxConVeh
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <CON_VEH> of PortPrototype <SrlComCONVEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComCONVEH_CON_VEH(SG_CON_VEH *data)
 *   boolean Rte_IsUpdated_SrlComCONVEH_CON_VEH(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVehCdnStatus_VehCdnStatus(New_Coding_64 data)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxConVeh(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxPaDrvDyn
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_TAR_STMOM_DV_ACT> of PortPrototype <SrlComSGTARSTMOMDVACT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(SG_TAR_QTA_STRMOM_DV *data)
 *   Std_ReturnType Rte_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(SG_TAR_STMOM_DV_ACT *data)
 *   Std_ReturnType Rte_Read_VehicleSpeed_Kph_f32(Float *data)
 *   boolean Rte_IsUpdated_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(void)
 *   boolean Rte_IsUpdated_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CADASIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SerlComTarSteerTqDrvrActr_MtrNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComAssistScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComDampingScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComDrvDynEnable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComInputTorqueOverlay_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComReturnScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_TJADampSclRqst_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_TJAStateRqst_Cnt_enum(TJAStateType data)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxPaDrvDyn(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxRevOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_OFFS_QUAD_EPS> of PortPrototype <SrlComSGOFFSQUADEPS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(SG_OFFS_QUAD_EPS *data)
 *   boolean Rte_IsUpdated_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_SrlComInput2_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComCRFRevOffset_Rev_s16(SInt16 data)
 *   Std_ReturnType Rte_Write_SrlComRevOffsetSts_Cnt_u08(ST_OFFS_QUAD_EPS data)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxRevOffset(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxStCeng
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ST_CENG> of PortPrototype <SrlComSTCENG>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSTCENG_ST_CENG(SG_ST_CENG *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComEngDrvStatus_ST_CENG(const SG_ST_CENG *data)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxStCeng(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxVYawVeh
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VYAW_VEH> of PortPrototype <SrlComVYAWVEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComVYAWVEH_VYAW_VEH(SG_VYAW_VEH *data)
 *   boolean Rte_IsUpdated_SrlComVYAWVEH_VYAW_VEH(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVehYawRate_DegpS_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehYawRateValid_Cnt_lgc(Boolean data)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxVYawVeh(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_V_VEH> of PortPrototype <SrlComSGVVEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSGVVEH_SG_V_VEH(SG_V_VEH *data)
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *   boolean Rte_IsUpdated_SrlComSGVVEH_SG_V_VEH(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FRVldVehSpd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehDrvCondition_Cnt_u08(DVCO_VEH data)
 *   Std_ReturnType Rte_Write_SrlComVehNearStandstill_Cnt_u08(ST_V_VEH_NSS data)
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlCom_QU_V_VEH_COG_Cnt_u08(QU_V_VEH_COG data)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxVehSpd(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_VehCfgUpdate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Cnt_lgc> of PortPrototype <CFACTORIF>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Cnt_lgc> of PortPrototype <CHWANGLEIF>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Cnt_lgc> of PortPrototype <CHWTORQUEIF>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Cnt_lgc> of PortPrototype <CMTTORQUEIF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CFACTORIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CHWANGLEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CMTTORQUEIF_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SerlComTarSteerTqDrvrActr_MtrNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComAssistScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComDampingScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComDrvDynEnable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComInputTorqueOverlay_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComReturnScaleFactor_Uls_f32(Float data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_VehCfgUpdate(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT2_APPL_CODE
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

#endif /* _RTE_AP_SRLCOMINPUT2_H */
