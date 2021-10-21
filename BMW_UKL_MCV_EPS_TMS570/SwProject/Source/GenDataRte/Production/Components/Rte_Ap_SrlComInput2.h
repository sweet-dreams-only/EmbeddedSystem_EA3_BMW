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
 *          File:  Components/Rte_Ap_SrlComInput2.h
 *     Workspace:  C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu Jun  1 10:59:41 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT2_H
# define _RTE_AP_SRLCOMINPUT2_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_FRVldVehSpd_Kph_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComAssistScaleFactor_Uls_f32;
extern VAR(SInt16, RTE_VAR_INIT) Rte_SrlComInput2_SrlComCRFRevOffset_Rev_s16;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComDampingScaleFactor_Uls_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComInputTorqueOverlay_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComReturnScaleFactor_Uls_f32;
extern VAR(ST_OFFS_QUAD_EPS, RTE_VAR_INIT) Rte_SrlComInput2_SrlComRevOffsetSts_Cnt_u08;
extern VAR(New_Coding_64, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus;
extern VAR(DVCO_VEH, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehDrvCondition_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc;
extern VAR(ST_V_VEH_NSS, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehNearStandstill_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehSpd_Kph_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehYawRate_DegpS_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc;
extern VAR(QU_V_VEH_COG, RTE_VAR_INIT) Rte_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_TJADampSclRqst_Uls_f32;
extern VAR(TJAStateType, RTE_VAR_INIT) Rte_SrlComInput2_TJAStateRqst_Cnt_enum;
extern VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;
extern VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_VehicleSpeed_Kph_f32;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CADASIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CFACTORIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWANGLEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWTORQUEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CMTTORQUEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc (FALSE)
#  define Rte_InitValue_FRVldVehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_SerlComTarSteerTqDrvrActr_MtrNm_f32 (0.0F)
#  define Rte_InitValue_SrlComAssistScaleFactor_Uls_f32 (1.0F)
#  define Rte_InitValue_SrlComCRFRevOffset_Rev_s16 (0)
#  define Rte_InitValue_SrlComDampingScaleFactor_Uls_f32 (1.0F)
#  define Rte_InitValue_SrlComDrvDynEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComDrvDynInvalid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComEngCrank_Cnt_lgc (TRUE)
#  define Rte_InitValue_SrlComInputTorqueOverlay_HwNm_f32 (0.0F)
#  define Rte_InitValue_SrlComPrkAstHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_SrlComPrkAstInvalid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComReturnScaleFactor_Uls_f32 (1.0F)
#  define Rte_InitValue_SrlComRevOffsetSts_Cnt_u08 (8U)
#  define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
#  define Rte_InitValue_SrlComVehCdnStatus_VehCdnStatus (0U)
#  define Rte_InitValue_SrlComVehDrvCondition_Cnt_u08 (0U)
#  define Rte_InitValue_SrlComVehLatAccel_MpSecSq_f32 (0.0F)
#  define Rte_InitValue_SrlComVehLatAccelValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComVehNearStandstill_Cnt_u08 (15U)
#  define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComVehYawRate_DegpS_f32 (0.0F)
#  define Rte_InitValue_SrlComVehYawRateValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlCom_QU_V_VEH_COG_Cnt_u08 (0U)
#  define Rte_InitValue_TJADampSclRqst_Uls_f32 (0.0F)
#  define Rte_InitValue_TJAStateRqst_Cnt_enum (1U)
#  define Rte_InitValue_VehSpdValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

extern VAR(Rte_tsTask_Trgd_10, RTE_VAR_NOINIT) Rte_Task_Trgd_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH(P2VAR(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput2_SrlComEngDrvStatus_ST_CENG(P2CONST(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT2_APPL_DATA) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_SrlComInput2_Per1_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_DiagStsDefVehSpd_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_Per1_SrlComSvcDft_Cnt_b32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IWrite_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_SrlComEngCrank_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_SrlComEngCrank_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput2_Per1_VehSpdValid_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_VehSpdValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput2_Per1_VehSpdValid_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_Per1.Rte_VehSpdValid_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CADASIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CADASIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CFACTORIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CHWANGLEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CHWTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxPaDrvDyn.Rte_CMTTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxRevOffset.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IRead_SrlComInput2_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_RxVehSpd.Rte_DiagStsDefVehSpd_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CFACTORIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate.Rte_CFACTORIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CHWANGLEIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate.Rte_CHWANGLEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate.Rte_CHWTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Task_Trgd_10.Rte_RB.Rte_Ap_SrlComInput2_SrlComInput2_TRGD_VehCfgUpdate.Rte_CMTTORQUEIF_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR Rte_Read_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR
#  define Rte_Read_SrlComCONVEH_CON_VEH Rte_Read_Ap_SrlComInput2_SrlComCONVEH_CON_VEH
#  define Rte_Read_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS Rte_Read_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS
#  define Rte_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV Rte_Read_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
#  define Rte_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT Rte_Read_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
#  define Rte_Read_SrlComSGVVEH_SG_V_VEH Rte_Read_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH
#  define Rte_Read_SrlComSTCENG_ST_CENG Rte_Read_Ap_SrlComInput2_SrlComSTCENG_ST_CENG
#  define Rte_Read_SrlComSvcDft_Cnt_b32 Rte_Read_Ap_SrlComInput2_SrlComSvcDft_Cnt_b32
#  define Rte_Read_Ap_SrlComInput2_SrlComSvcDft_Cnt_b32(data) (*(data) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComVYAWVEH_VYAW_VEH Rte_Read_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH
#  define Rte_Read_VehicleSpeed_Kph_f32 Rte_Read_Ap_SrlComInput2_VehicleSpeed_Kph_f32
#  define Rte_Read_Ap_SrlComInput2_VehicleSpeed_Kph_f32(data) (*(data) = Rte_SignlCondn_VehicleSpeed_Kph_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR Rte_IsUpdated_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR
#  define Rte_IsUpdated_Ap_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR() (Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR == Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_Sender ? FALSE : TRUE)
#  define Rte_IsUpdated_SrlComCONVEH_CON_VEH Rte_IsUpdated_Ap_SrlComInput2_SrlComCONVEH_CON_VEH
#  define Rte_IsUpdated_Ap_SrlComInput2_SrlComCONVEH_CON_VEH() (Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComCONVEH_CON_VEH == Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComCONVEH_CON_VEH_Sender ? FALSE : TRUE)
#  define Rte_IsUpdated_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS Rte_IsUpdated_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS
#  define Rte_IsUpdated_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS() (Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS == Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_Sender ? FALSE : TRUE)
#  define Rte_IsUpdated_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV Rte_IsUpdated_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
#  define Rte_IsUpdated_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV() (Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV == Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_Sender ? FALSE : TRUE)
#  define Rte_IsUpdated_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT Rte_IsUpdated_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
#  define Rte_IsUpdated_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT() (Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT == Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_Sender ? FALSE : TRUE)
#  define Rte_IsUpdated_SrlComSGVVEH_SG_V_VEH Rte_IsUpdated_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH
#  define Rte_IsUpdated_Ap_SrlComInput2_SrlComSGVVEH_SG_V_VEH() (Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGVVEH_SG_V_VEH == Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComSGVVEH_SG_V_VEH_Sender ? FALSE : TRUE)
#  define Rte_IsUpdated_SrlComVYAWVEH_VYAW_VEH Rte_IsUpdated_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH
#  define Rte_IsUpdated_Ap_SrlComInput2_SrlComVYAWVEH_VYAW_VEH() (Rte_Ap_10_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComVYAWVEH_VYAW_VEH == Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput2_SrlComVYAWVEH_VYAW_VEH_Sender ? FALSE : TRUE)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_FRVldVehSpd_Kph_f32 Rte_Write_Ap_SrlComInput2_FRVldVehSpd_Kph_f32
#  define Rte_Write_Ap_SrlComInput2_FRVldVehSpd_Kph_f32(data) (Rte_SrlComInput2_FRVldVehSpd_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SerlComTarSteerTqDrvrActr_MtrNm_f32 Rte_Write_Ap_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32
#  define Rte_Write_Ap_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32(data) (Rte_SrlComInput2_SerlComTarSteerTqDrvrActr_MtrNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComAssistScaleFactor_Uls_f32 Rte_Write_Ap_SrlComInput2_SrlComAssistScaleFactor_Uls_f32
#  define Rte_Write_Ap_SrlComInput2_SrlComAssistScaleFactor_Uls_f32(data) (Rte_SrlComInput2_SrlComAssistScaleFactor_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComCRFRevOffset_Rev_s16 Rte_Write_Ap_SrlComInput2_SrlComCRFRevOffset_Rev_s16
#  define Rte_Write_Ap_SrlComInput2_SrlComCRFRevOffset_Rev_s16(data) (Rte_SrlComInput2_SrlComCRFRevOffset_Rev_s16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComDampingScaleFactor_Uls_f32 Rte_Write_Ap_SrlComInput2_SrlComDampingScaleFactor_Uls_f32
#  define Rte_Write_Ap_SrlComInput2_SrlComDampingScaleFactor_Uls_f32(data) (Rte_SrlComInput2_SrlComDampingScaleFactor_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComDrvDynEnable_Cnt_lgc Rte_Write_Ap_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc(data) (Rte_SrlComInput2_SrlComDrvDynEnable_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComDrvDynInvalid_Cnt_lgc Rte_Write_Ap_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc(data) (Rte_SrlComInput2_SrlComDrvDynInvalid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComEngDrvStatus_ST_CENG Rte_Write_Ap_SrlComInput2_SrlComEngDrvStatus_ST_CENG
#  define Rte_Write_SrlComInputTorqueOverlay_HwNm_f32 Rte_Write_Ap_SrlComInput2_SrlComInputTorqueOverlay_HwNm_f32
#  define Rte_Write_Ap_SrlComInput2_SrlComInputTorqueOverlay_HwNm_f32(data) (Rte_SrlComInput2_SrlComInputTorqueOverlay_HwNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComReturnScaleFactor_Uls_f32 Rte_Write_Ap_SrlComInput2_SrlComReturnScaleFactor_Uls_f32
#  define Rte_Write_Ap_SrlComInput2_SrlComReturnScaleFactor_Uls_f32(data) (Rte_SrlComInput2_SrlComReturnScaleFactor_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComRevOffsetSts_Cnt_u08 Rte_Write_Ap_SrlComInput2_SrlComRevOffsetSts_Cnt_u08
#  define Rte_Write_Ap_SrlComInput2_SrlComRevOffsetSts_Cnt_u08(data) (Rte_SrlComInput2_SrlComRevOffsetSts_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehCdnStatus_VehCdnStatus Rte_Write_Ap_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus
#  define Rte_Write_Ap_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus(data) (Rte_SrlComInput2_SrlComVehCdnStatus_VehCdnStatus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehDrvCondition_Cnt_u08 Rte_Write_Ap_SrlComInput2_SrlComVehDrvCondition_Cnt_u08
#  define Rte_Write_Ap_SrlComInput2_SrlComVehDrvCondition_Cnt_u08(data) (Rte_SrlComInput2_SrlComVehDrvCondition_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehLatAccel_MpSecSq_f32 Rte_Write_Ap_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32
#  define Rte_Write_Ap_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32(data) (Rte_SrlComInput2_SrlComVehLatAccel_MpSecSq_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehLatAccelValid_Cnt_lgc Rte_Write_Ap_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc(data) (Rte_SrlComInput2_SrlComVehLatAccelValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehNearStandstill_Cnt_u08 Rte_Write_Ap_SrlComInput2_SrlComVehNearStandstill_Cnt_u08
#  define Rte_Write_Ap_SrlComInput2_SrlComVehNearStandstill_Cnt_u08(data) (Rte_SrlComInput2_SrlComVehNearStandstill_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehSpd_Kph_f32 Rte_Write_Ap_SrlComInput2_SrlComVehSpd_Kph_f32
#  define Rte_Write_Ap_SrlComInput2_SrlComVehSpd_Kph_f32(data) (Rte_SrlComInput2_SrlComVehSpd_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehYawRate_DegpS_f32 Rte_Write_Ap_SrlComInput2_SrlComVehYawRate_DegpS_f32
#  define Rte_Write_Ap_SrlComInput2_SrlComVehYawRate_DegpS_f32(data) (Rte_SrlComInput2_SrlComVehYawRate_DegpS_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehYawRateValid_Cnt_lgc Rte_Write_Ap_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc(data) (Rte_SrlComInput2_SrlComVehYawRateValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlCom_QU_V_VEH_COG_Cnt_u08 Rte_Write_Ap_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08
#  define Rte_Write_Ap_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08(data) (Rte_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_TJADampSclRqst_Uls_f32 Rte_Write_Ap_SrlComInput2_TJADampSclRqst_Uls_f32
#  define Rte_Write_Ap_SrlComInput2_TJADampSclRqst_Uls_f32(data) (Rte_SrlComInput2_TJADampSclRqst_Uls_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_TJAStateRqst_Cnt_enum Rte_Write_Ap_SrlComInput2_TJAStateRqst_Cnt_enum
#  define Rte_Write_Ap_SrlComInput2_TJAStateRqst_Cnt_enum(data) (Rte_SrlComInput2_TJAStateRqst_Cnt_enum = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr10_GetNTCStatus
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMINPUT2_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_Init(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_Per1(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxAclnyMassCntr(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxConVeh(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxPaDrvDyn(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxRevOffset(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxStCeng(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxVYawVeh(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxVehSpd(void);

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_VehCfgUpdate(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT2_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_SrlComInput2.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMINPUT2_H */
