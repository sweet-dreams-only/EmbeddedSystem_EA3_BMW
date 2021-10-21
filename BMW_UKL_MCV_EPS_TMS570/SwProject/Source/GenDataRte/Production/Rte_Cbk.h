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
 *          File:  Rte_Cbk.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue May 24 13:45:35 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  COM callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CBK_H
# define _RTE_CBK_H

# include "Com.h"

/* Com.h Compatibility Check */
# ifndef RTE_COM_VERSION
#  if defined (IL_VECTOR_VERSION)
#   define RTE_COM_VERSION 20U
#  else
#   if defined (IL_ASRCOM_VERSION)
#    if (IL_ASRCOM_VERSION < 0x0201U)
#     define RTE_COM_VERSION 20U
#    endif
#   endif
#  endif
#  if defined (COM_AR_MAJOR_VERSION) && defined (COM_AR_MINOR_VERSION)
#   define RTE_COM_VERSION ((COM_AR_MAJOR_VERSION * 10) + COM_AR_MINOR_VERSION)
#  endif
# endif
# ifndef RTE_COM_VERSION
#  define RTE_COM_VERSION 33U
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * COM Callbacks for Rx Indication
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_Com_AVL_STEA_PNI_OFFS__STEA_OFFS(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_BE_CHOV_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_ACDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_DIM_DSE_EXMI__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_PRG_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_PSDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_DIR_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_ILVL_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_LGA_DSE_1_LH__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_LGA_DSE_1_RH__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ENERG_AVAI_ARS__ENERG_DGR_DRDY(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_FACT_MO_STE_SO_DXP__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ANFRAGE_DSC_Modul__ANFRAGE_DSC_Modul(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ANFRAGE_SAS__ANFRAGE_SAS(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ANFRAGE_ZGW__ANFRAGE_ZGW(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_CON_VEH__CON_VEH(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_ST_CENG__ST_CENG(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_TAR_STMOM_DV_ACT__TAR_STMOM_DV_ACT(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_VYAW_VEH__VYAW_VEH(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SG_V_VEH__V_VEH(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_MAX_I_LD_SPEC_ARS__ENERG_DGR_DRDY(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_MAX_I_RECUP_SPEC_ARS__ENERG_DGR_DRDY(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_MAX_I_SPEC_BAX_STE__ENERG_DGR_DRDY(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_MILE_KM__KILOMETERSTAND(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_QU_DGR_AISP_ENERG__ENERG_DGR_DRDY(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_RQ_RST_OBD_DIAG_DRDY__CTR_DIAG_OBD_DRDY(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ST_ILK_ERRM_FZM__FZZSTD(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ST_OBD_CYC__DIAG_OBD_ENG(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_ASS_LIBE__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_PARASS_DXP__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_TROPT__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_FN_EDP_DXP__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_FN_LCS_DXP__SU_CLE_DRDY_DXP(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SU_FN_LCS_UD_DXP__SU_CLE_DRDY_DXP(void);

/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_AVL_STEA_PNI_OFFS__STEA_OFFS(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_AVL_STEA_PNI_OFFS__STEA_OFFS(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_BE_CHOV_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_BE_CHOV_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_ACDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_ACDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_DIM_DSE_EXMI__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_DIM_DSE_EXMI__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_PRG_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_PRG_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_PSDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_PSDU_IVIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_DIR_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_DIR_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_ILVL_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_ILVL_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_ILVL_VIB_STW__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_LGA_DSE_1_LH__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_LGA_DSE_1_LH__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_LGA_DSE_1_RH__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_LGA_DSE_1_RH__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_CTR_WARN_PTRN_VIB_EPS__CTR_VIB_STW_DISP_EXMI_SP2015(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ENERG_AVAI_ARS__ENERG_DGR_DRDY(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ENERG_AVAI_ARS__ENERG_DGR_DRDY(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_FACT_MO_STE_SO_DXP__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_FACT_MO_STE_SO_DXP__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_ACLNY_MASSCNTR__ACLNY_MASSCNTR(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_CON_VEH__CON_VEH(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_CON_VEH__CON_VEH(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_FAHRGESTELLNUMMER__FAHRGESTELLNUMMER(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_OFFS_QUAD_EPS__OFFS_QUAD_EPS(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_ST_CENG__ST_CENG(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_ST_CENG__ST_CENG(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_TAR_QTA_STRMOM_DV__TAR_QTA_STRMOM_DV(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_VYAW_VEH__VYAW_VEH(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_VYAW_VEH__VYAW_VEH(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_V_VEH__V_VEH(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SG_V_VEH__V_VEH(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_LD_SPEC_ARS__ENERG_DGR_DRDY(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_LD_SPEC_ARS__ENERG_DGR_DRDY(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_RECUP_SPEC_ARS__ENERG_DGR_DRDY(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_RECUP_SPEC_ARS__ENERG_DGR_DRDY(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_SPEC_BAX_STE__ENERG_DGR_DRDY(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_SPEC_BAX_STE__ENERG_DGR_DRDY(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MAX_I_SPEC_EPS__ENERG_DGR_DRDY(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MILE_KM__KILOMETERSTAND(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MILE_KM__KILOMETERSTAND(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_QU_DGR_AISP_ENERG__ENERG_DGR_DRDY(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_QU_DGR_AISP_ENERG__ENERG_DGR_DRDY(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ST_ILK_ERRM_FZM__FZZSTD(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ST_ILK_ERRM_FZM__FZZSTD(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_ASS_LIBE__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_ASS_LIBE__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_PARASS_DXP__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_PARASS_DXP__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_STMOM_SFE_DXP__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_TROPT__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_TROPT__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_CLU_VE_DYNMC_DXP__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_EDP_DXP__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_EDP_DXP__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_LCS_DXP__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_LCS_DXP__SU_CLE_DRDY_DXP(void);
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_LCS_UD_DXP__SU_CLE_DRDY_DXP(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SU_FN_LCS_UD_DXP__SU_CLE_DRDY_DXP(void);
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Rte_Cbk.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CBK_H */
