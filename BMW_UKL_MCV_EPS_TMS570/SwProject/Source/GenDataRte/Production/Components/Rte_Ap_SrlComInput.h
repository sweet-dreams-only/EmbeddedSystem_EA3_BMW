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
 *          File:  Components/Rte_Ap_SrlComInput.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Fri Apr 28 16:52:12 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

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

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(CTR_ERRM_BN_U, RTE_VAR_INIT) Rte_SrlComInput_ErrmBnU_Cnt_u8;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_HaptcFbIntenNr_Cnt_u16;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_HaptcFbPatNr_Cnt_u16;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaptcFbPatSigVld_Cnt_lgc;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComInput_IgnTimeOff_Cnt_u32;
extern VAR(UInt4, RTE_VAR_INIT) Rte_SrlComInput_SrlComSTKL_ST_KL;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SupplyCurrLmt_Amp_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_VINValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_VehTimeValid_Cnt_lgc;
extern VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface9_SrlComSvcDft_Cnt_b32;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS (0U)
#  define Rte_InitValue_CDRVDYNMSG_Cnt_lgc (FALSE)
#  define Rte_InitValue_CERRMVOLTFALLBACK_Cnt_lgc (FALSE)
#  define Rte_InitValue_CFACTORIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWACORRECTION_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWANGLEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWTORQUEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CMTTORQUEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_ACDU_IVIB_STW (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_DIM_DSE_EXMI (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_PRG_IVIB_STW (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_PSDU_IVIB_STW (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_VIB_STW (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_WARN_DIR_VIB_EPS (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_STW (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_WARN_LGA_DSE_1_LH (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_WARN_LGA_DSE_1_RH (0U)
#  define Rte_InitValue_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS (0U)
#  define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc (FALSE)
#  define Rte_InitValue_ENERG_DGR_DRDY_ENERG_AVAI_ARS (0U)
#  define Rte_InitValue_ENERG_DGR_DRDY_MAX_I_LD_SPEC_ARS (0U)
#  define Rte_InitValue_ENERG_DGR_DRDY_MAX_I_RECUP_SPEC_ARS (0U)
#  define Rte_InitValue_ENERG_DGR_DRDY_MAX_I_SPEC_BAX_STE (0U)
#  define Rte_InitValue_ENERG_DGR_DRDY_MAX_I_SPEC_EPS (0U)
#  define Rte_InitValue_ENERG_DGR_DRDY_QU_DGR_AISP_ENERG (0U)
#  define Rte_InitValue_ErrmBnU_Cnt_u8 (0U)
#  define Rte_InitValue_HaptcFbIntenNr_Cnt_u16 (0U)
#  define Rte_InitValue_HaptcFbIntenSigVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaptcFbPatNr_Cnt_u16 (0U)
#  define Rte_InitValue_HaptcFbPatSigVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_IgnTimeOff_Cnt_u32 (0U)
#  define Rte_InitValue_IlkErrmFzm_Cnt_u8 (0U)
#  define Rte_InitValue_ReturnOffset_HwDeg_f32 (0.0F)
#  define Rte_InitValue_RxCtrErrmBnU_Cnt_u8 (0U)
#  define Rte_InitValue_RxILK_ERRM_FZM_Cnt_u8 (0U)
#  define Rte_InitValue_RxMILE_KM_Cnt_u32 (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_BE_CHOV_CLU_VE_DYNMC_DXP (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_FACT_MO_STE_SO_DXP (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_SU_CLU_ASS_LIBE (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_SU_CLU_PARASS_DXP (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_SU_CLU_TROPT (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_SU_CLU_VE_DYNMC_DXP (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_SU_FN_EDP_DXP (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_SU_FN_LCS_DXP (0U)
#  define Rte_InitValue_SU_CLE_DRDY_DXP_SU_FN_LCS_UD_DXP (0U)
#  define Rte_InitValue_SrlComSTKL_ST_KL (0U)
#  define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
#  define Rte_InitValue_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP (3U)
#  define Rte_InitValue_SupplyCurrLmt_Amp_f32 (166.67F)
#  define Rte_InitValue_VINValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehTimeValid_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd9_SystemState9_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitB_9, RTE_VAR_NOINIT) Rte_Task_InitB_9;

extern VAR(Rte_tsTask_2msA_9, RTE_VAR_NOINIT) Rte_Task_2msA_9;

extern VAR(Rte_tsTask_5ms_9, RTE_VAR_NOINIT) Rte_Task_5ms_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_VYAW_VEH_VYAW_VEH(P2VAR(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS(P2CONST(SG_ANFRAGE_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(P2CONST(SG_ACLNY_MASSCNTR, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComCONVEH_CON_VEH(P2CONST(SG_CON_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(P2CONST(SG_OFFS_QUAD_EPS, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(P2CONST(SG_TAR_QTA_STRMOM_DV, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(P2CONST(SG_TAR_STMOM_DV_ACT, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSGVVEH_SG_V_VEH(P2CONST(SG_V_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComSTCENG_ST_CENG(P2CONST(SG_ST_CENG, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComVYAWVEH_VYAW_VEH(P2CONST(SG_VYAW_VEH, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) data);

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

#  define Rte_IWrite_SrlComInput_Init_IgnTimeOff_Cnt_u32(data) \
  ( \
    Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_IgnTimeOff_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_IgnTimeOff_Cnt_u32() \
  (&Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_IgnTimeOff_Cnt_u32.value)

#  define Rte_IWrite_SrlComInput_Init_SrlComSTKL_ST_KL(data) \
  ( \
    Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_SrlComSTKL_ST_KL.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_SrlComSTKL_ST_KL() \
  (&Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_SrlComSTKL_ST_KL.value)

#  define Rte_IWrite_SrlComInput_Init_VehTimeValid_Cnt_lgc(data) \
  ( \
    Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_VehTimeValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_VehTimeValid_Cnt_lgc() \
  (&Rte_Task_InitB_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_VehTimeValid_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_CERRMVOLTFALLBACK_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CERRMVOLTFALLBACK_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DiagStsDefVehSpd_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_RxCtrErrmBnU_Cnt_u8() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_RxCtrErrmBnU_Cnt_u8.value)

#  define Rte_IRead_SrlComInput_Per1_SrlComSvcDft_Cnt_b32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_CHWACORRECTION_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss.Rte_CHWACORRECTION_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_SrlComSvcDft_Cnt_b32() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_AvlSteaPniOffsLoss.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss.Rte_CHWTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_PaDrvDynLoss.Rte_CMTTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_CHWACORRECTION_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs.Rte_CHWACORRECTION_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_SrlComSvcDft_Cnt_b32() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IWrite_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs.Rte_ReturnOffset_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxAvlSteaPniOffs.Rte_ReturnOffset_HwDeg_f32.value)

#  define Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn.Rte_CFACTORIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn.Rte_CHWANGLEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn.Rte_CHWTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxPaDrvDyn.Rte_CMTTORQUEIF_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxRevOffset.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IRead_SrlComInput_TRGD_RxTuningSel_CDRVDYNMSG_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel.Rte_CDRVDYNMSG_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(data) \
  ( \
    Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel.Rte_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxTuningSel.Rte_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP.value)

#  define Rte_IRead_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH() \
  (&Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.value)

#  define Rte_IStatus_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVIN.Rte_RxVIN_VIN_NO_VECH.status)

#  define Rte_IRead_SrlComInput_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_RxVehSpd.Rte_DiagStsDefVehSpd_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_TRGD_TuningSelLoss_CDRVDYNMSG_Cnt_lgc() \
  (Rte_Task_5ms_9.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_TRGD_TuningSelLoss.Rte_CDRVDYNMSG_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ACLNY_MASSCNTR_ACLNY_MASSCNTR Rte_Read_Ap_SrlComInput_ACLNY_MASSCNTR_ACLNY_MASSCNTR
#  define Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS Rte_Read_Ap_SrlComInput_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS
#  define Rte_Read_CON_VEH_CON_VEH Rte_Read_Ap_SrlComInput_CON_VEH_CON_VEH
#  define Rte_Read_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS
#  define Rte_Read_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS
#  define Rte_Read_ENERG_DGR_DRDY_MAX_I_SPEC_EPS Rte_Read_Ap_SrlComInput_ENERG_DGR_DRDY_MAX_I_SPEC_EPS
#  define Rte_Read_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS Rte_Read_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS
#  define Rte_Read_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV Rte_Read_Ap_SrlComInput_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV
#  define Rte_Read_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT Rte_Read_Ap_SrlComInput_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT
#  define Rte_Read_SG_V_VEH_SG_V_VEH Rte_Read_Ap_SrlComInput_SG_V_VEH_SG_V_VEH
#  define Rte_Read_ST_CENG_ST_CENG Rte_Read_Ap_SrlComInput_ST_CENG_ST_CENG
#  define Rte_Read_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP Rte_Read_Ap_SrlComInput_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP
#  define Rte_Read_SrlComSvcDft_Cnt_b32 Rte_Read_Ap_SrlComInput_SrlComSvcDft_Cnt_b32
#  define Rte_Read_Ap_SrlComInput_SrlComSvcDft_Cnt_b32(data) (*(data) = Rte_CDDInterface9_SrlComSvcDft_Cnt_b32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_VYAW_VEH_VYAW_VEH Rte_Read_Ap_SrlComInput_VYAW_VEH_VYAW_VEH


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS Rte_IsUpdated_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS
#  define Rte_IsUpdated_Ap_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS() (Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS == Rte_Ap_9_RxUpdateFlags.Rte_RxUpdate_SrlComInput_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS_Sender ? FALSE : TRUE)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ErrmBnU_Cnt_u8 Rte_Write_Ap_SrlComInput_ErrmBnU_Cnt_u8
#  define Rte_Write_Ap_SrlComInput_ErrmBnU_Cnt_u8(data) (Rte_SrlComInput_ErrmBnU_Cnt_u8 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaptcFbIntenNr_Cnt_u16 Rte_Write_Ap_SrlComInput_HaptcFbIntenNr_Cnt_u16
#  define Rte_Write_Ap_SrlComInput_HaptcFbIntenNr_Cnt_u16(data) (Rte_SrlComInput_HaptcFbIntenNr_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaptcFbIntenSigVld_Cnt_lgc Rte_Write_Ap_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc(data) (Rte_SrlComInput_HaptcFbIntenSigVld_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaptcFbPatNr_Cnt_u16 Rte_Write_Ap_SrlComInput_HaptcFbPatNr_Cnt_u16
#  define Rte_Write_Ap_SrlComInput_HaptcFbPatNr_Cnt_u16(data) (Rte_SrlComInput_HaptcFbPatNr_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaptcFbPatSigVld_Cnt_lgc Rte_Write_Ap_SrlComInput_HaptcFbPatSigVld_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HaptcFbPatSigVld_Cnt_lgc(data) (Rte_SrlComInput_HaptcFbPatSigVld_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_IgnTimeOff_Cnt_u32 Rte_Write_Ap_SrlComInput_IgnTimeOff_Cnt_u32
#  define Rte_Write_Ap_SrlComInput_IgnTimeOff_Cnt_u32(data) (Rte_SrlComInput_IgnTimeOff_Cnt_u32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS Rte_Write_Ap_SrlComInput_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS
#  define Rte_Write_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR Rte_Write_Ap_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR
#  define Rte_Write_SrlComCONVEH_CON_VEH Rte_Write_Ap_SrlComInput_SrlComCONVEH_CON_VEH
#  define Rte_Write_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS Rte_Write_Ap_SrlComInput_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS
#  define Rte_Write_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV Rte_Write_Ap_SrlComInput_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV
#  define Rte_Write_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT Rte_Write_Ap_SrlComInput_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT
#  define Rte_Write_SrlComSGVVEH_SG_V_VEH Rte_Write_Ap_SrlComInput_SrlComSGVVEH_SG_V_VEH
#  define Rte_Write_SrlComSTCENG_ST_CENG Rte_Write_Ap_SrlComInput_SrlComSTCENG_ST_CENG
#  define Rte_Write_SrlComSTKL_ST_KL Rte_Write_Ap_SrlComInput_SrlComSTKL_ST_KL
#  define Rte_Write_Ap_SrlComInput_SrlComSTKL_ST_KL(data) (Rte_SrlComInput_SrlComSTKL_ST_KL = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVYAWVEH_VYAW_VEH Rte_Write_Ap_SrlComInput_SrlComVYAWVEH_VYAW_VEH
#  define Rte_Write_SupplyCurrLmt_Amp_f32 Rte_Write_Ap_SrlComInput_SupplyCurrLmt_Amp_f32
#  define Rte_Write_Ap_SrlComInput_SupplyCurrLmt_Amp_f32(data) (Rte_SrlComInput_SupplyCurrLmt_Amp_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VINValid_Cnt_lgc Rte_Write_Ap_SrlComInput_VINValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_VINValid_Cnt_lgc(data) (Rte_SrlComInput_VINValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VehTimeValid_Cnt_lgc Rte_Write_Ap_SrlComInput_VehTimeValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_VehTimeValid_Cnt_lgc(data) (Rte_SrlComInput_VehTimeValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr9_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr9_GetNTCStatus
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr9_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_AclnyCogLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_AvlSteaPniOffsLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_ConVehLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_CtrVibStwDispLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_EnergDgrDrdyLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_FZZSTDLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_MileKMLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_PaDrvDynLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxAclnyCog(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxAvlSteaPniOffs(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxConVeh(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxCtrVibStwDisp(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxEnergDgrDrdy(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxPaDrvDyn(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxRevOffset(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxRevOffsetLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxStCeng(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxTuningSel(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVIN(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVYawVeh(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVehSpd(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_StCengLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_TuningSelLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VINLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VYawVehLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VehSpdLoss(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
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
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_SrlComInput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMINPUT_H */
