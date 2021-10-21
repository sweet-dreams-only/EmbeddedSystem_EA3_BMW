/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_BmwRtnArbn.c
 *     Workspace:  C:/SynergyWorkArea/Working/CBD_BmwRtnAbrn/autosar
 *     SW-C Type:  Ap_BmwRtnArbn
 *  Generated at:  Wed Feb 24 11:59:18 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_BmwRtnArbn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2014, 2015, 2016 Nxtr
 * Nxtr Confidential
 *
 * Module File Name	 : BmwRtnArbn.c
 * Module Description: Implementation of CF019A BMW Return Arbitration component
 * Project           : CBD
 * Author            : Sankardu Varadapureddi
 **********************************************************************************************************************
 * Version Control:
 * %version:          5 %
 * %derived_by:       czmgrw %
 *-------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * -------   -------  --------  -------------------------------------------------------------------------  ----------
 * 11/24/15  1        SV        Initial Version                                                             EA3#3042
 * 02/24/16  2        JK        Implemented CF019A v 1.3.0                                                  EA3#6284
 * 03/02/16  3        KK        Implemented CF019A v 1.4.0                                                  EA3#6428
 * 03/02/16  4        KK        Implemented CF019A v 1.5.0 (Fixes for EA3#6418, EA3#8056, EA3#6153)         EA3#8106
 * 06/28/16  5        JK        Anomaly fix EA3#9016 - Misusage of vehspd look up table                     EA3#9188
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_BmwRtnArbn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "filters.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "interpolation.h"

/* PRQA S 4395 EOF *
 * MISRA-C:2004 Rule 10.4: A composite expression of 'essentially floating' type (%1s) is being cast to a different type category, '%2s'. */

/* PRQA S 310 EOF *
 * MISRA-C:2004 Rule 11.4: Casting to different object pointer type. */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

#define D_TRQGRADCALCNWGHTGFAC1_ULS_F32		1.1978F
#define D_TRQGRADCALCNWGHTGFAC2_ULS_F32		3.3286F
#define D_TRQGRADCALCNWGHTGFAC3_ULS_F32		4.3159F
#define D_TRQGRADCALCNWGHTGFAC4_ULS_F32		18.0384F
#define D_DRVRTQOBSVRVELTHD_HWRADPERSEC_F32	420.0F
#define D_DRVRTQOBSVRTQTHD_HWNWTMTR_F32		100.0F
#define D_DRVRTQOBSVRAGTHD_HWRAD_F32		252.0F
#define D_DRVRTQOBSVRFINALTHD_HWNWTMTR_F32	10.0F

#define	D_MAX5_CNT_U08		5U
#define	D_MAX4_CNT_U08		4U
#define	D_THREE_CNT_U08		3U
#define	D_TWO_CNT_U08		2U
#define	D_ONE_CNT_U08		1U
#define	D_ZERO_CNT_U08		0U

#define BmwRtnArbn_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevADrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevBDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevCDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevDDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevEDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevFDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevRtnOffsetSlew_HwDeg_M_f32;			/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevHwTrqScaSelector_Uls_M_f32;			/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevITermB_HwNm_M_f32;					/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevITermC_HwNm_M_f32;					/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevITermLim_HwNm_M_f32;						/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[5];				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) BmwRtnArbn_PrevHwAuthySca_Uls_M_f32;					/* PRQA S 3218 */

STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_HwPosComp_HwDeg_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_DrvTrqEst_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_DrvTrqFilt_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_TrqGrdtSca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_TrqGrdt_HwNmpS_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_TbarTrqSca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_PosSca_Uls_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_VelErrorSca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_HwTrqSca_Uls_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_HwTrqScaSelector_Uls_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_HwAuthySca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_CtrlScaPreFilt_Uls_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_DesVelScaPreFilt_Uls_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_PTermCmd_HwNm_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_IntgtrLim_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_ITermCmd_HwNm_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_DampgCmd_HwNm_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_RtnCmdPreLim_MtrNm_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_ReturnCmd_MtrNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_CtrlSca_Uls_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_DesVelSca_Uls_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) BmwRtnArbn_DesVel_HwDegpS_D_f32;			/* PRQA S 3218 */
#define BmwRtnArbn_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define BmwRtnArbn_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(boolean, AUTOMATIC) BmwRtnArbn_EnableCVR_Cnt_M_lgc;						/* PRQA S 3218 */

#define BmwRtnArbn_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


#define BmwRtnArbn_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, BmwRtnArbn_VAR) BmwRtnArbn_DesVelLPFSV_HwDegpS_M_Str;
STATIC VAR(LPF32KSV_Str, BmwRtnArbn_VAR) BmwRtnArbn_DrvTrqLPFSV_HwNm_M_Str;
STATIC VAR(LPF32KSV_Str, BmwRtnArbn_VAR) BmwRtnArbn_TbarTrqLPFSV_HwNm_M_Str;
STATIC VAR(LPF32KSV_Str, BmwRtnArbn_VAR) BmwRtnArbn_DesVelScaLPFSV_Uls_M_Str;
STATIC VAR(LPF32KSV_Str, BmwRtnArbn_VAR) BmwRtnArbn_CtrlScaLPFSV_Uls_M_Str;
#define BmwRtnArbn_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Function Prototypes */
STATIC FUNC(void, BmwRtnArbn_APPL_CODE) InpCdng(VAR(float32,AUTOMATIC) ReturnOffset_HwDeg_T_f32,
		                                        VAR(float32,AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
												VAR(float32,AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32,
												P2VAR(float32, AUTOMATIC, BmwRtnArbn_APPL_VAR) CompHwPos_HwDeg_T_f32,
												P2VAR(float32, AUTOMATIC, BmwRtnArbn_APPL_VAR) HwVel_HwDegpS_T_f32);
												 
STATIC FUNC(float32, BmwRtnArbn_APPL_CODE) DrvrTqSelctr(VAR(float32,AUTOMATIC) MtrTrqCmd_MtrNm_T_f32,
														VAR(float32,AUTOMATIC) TbarTrq_HwNm_T_f32,
									                    VAR(float32,AUTOMATIC) HwPos_HwDeg_T_f32,
									                    VAR(float32,AUTOMATIC) HwVel_HwRadpS_T_f32);
														 
STATIC FUNC(float32, BmwRtnArbn_APPL_CODE) TqGrdtSca(VAR(float32,AUTOMATIC) DrvTrqFilt_HwNm_T_f32,
                                                     VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32);
													 
STATIC FUNC(float32, BmwRtnArbn_APPL_CODE) VelErrSca(VAR(float32,AUTOMATIC) HwPos_HwDeg_T_f32,
													 VAR(float32,AUTOMATIC) HwVel_HwDegpS_T_f32,
													 VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32,
													 VAR(float32,AUTOMATIC) DesVel_HwDegpS_T_f32);

STATIC FUNC(float32, BmwRtnArbn_APPL_CODE) HwTrqSca(VAR(float32,AUTOMATIC) DrvTrqFilt_HwNm_T_f32,
													VAR(float32,AUTOMATIC) HwVel_HwDegpS_T_f32,
													VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32);													  
											 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_BMWRTNARBN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwRtnArbn_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWRTNARBN_APPL_CODE) BmwRtnArbn_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwRtnArbn_Init1
 *********************************************************************************************************************/
	{
		LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_DesVelLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_DesVelLPFSV_HwDegpS_M_Str);
		LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_HwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_DrvTrqLPFSV_HwNm_M_Str);
		LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_HwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_TbarTrqLPFSV_HwNm_M_Str);
		LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_ScaLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_DesVelScaLPFSV_Uls_M_Str);
		LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_ScaLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_CtrlScaLPFSV_Uls_M_Str);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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

FUNC(void, RTE_AP_BMWRTNARBN_APPL_CODE) BmwRtnArbn_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwRtnArbn_Per1
 *********************************************************************************************************************/

	/* inputs */

	VAR(boolean, AUTOMATIC) DefeatReturnSvc_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DiagStsHwPosDis_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EnableCVR_Cnt_T_lgc;
	
	VAR(uint16, AUTOMATIC) TbarTrqSca_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) PosSca_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) HwAuthySca_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) DesVelScaPreFilt_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
	VAR(uint16, AUTOMATIC) HwPosAbs_HwDeg_T_u12p4;
	VAR(uint16, AUTOMATIC) DesVelScaFacPreFilt_Uls_T_u10p6;
	VAR(uint16, AUTOMATIC) Kp_Uls_T_u4p12;
	VAR(uint16, AUTOMATIC) Ki_Uls_T_u8p8;
	VAR(uint16, AUTOMATIC) IntLimUpper_HwDeg_T_u10p6;
	VAR(uint16, AUTOMATIC) DampgTermInter_HwNm_T_u6p10;
	VAR(uint16, AUTOMATIC) RtnCmdLimUpper_MtrNm_T_u4p12;
	VAR(uint16, AUTOMATIC) BasicRtnVehSpeedBlend_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) CtrldVelRtnVehSpeedBlend_Uls_T_u2p14;

	VAR(float32, AUTOMATIC) BasicRtnCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
	VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) MRFMtrTrqCmdScl_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PAReturnSclFct_Uls_T_f32;
	VAR(float32, AUTOMATIC) ReturnDDFactor_Uls_T_f32;
	VAR(float32, AUTOMATIC) ReturnOffset_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(float32, AUTOMATIC) RtnCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) CompHwPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwVel_HwDegpS_T_f32;
	VAR(float32, AUTOMATIC) DrvTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) DrvTrqFilt_HwNm_T_f32;
	VAR(float32, AUTOMATIC) TbarTrqFilt_HwNm_T_f32;
	VAR(float32, AUTOMATIC) TrqGrdtSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) TbarTrqSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) PosSca_Uls_T_f32;       
	VAR(float32, AUTOMATIC) VelErrSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) HwTrqSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) HwAuthySca_Uls_T_f32;
	VAR(float32, AUTOMATIC) CtrlSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) CtrlScaPreFilt_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelScaPreFilt_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelScaFacPreFilt_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelPreFilt_HwDegpS_T_f32;
	VAR(float32, AUTOMATIC) VelErr_HwDegpS_T_f32;
	VAR(float32, AUTOMATIC) Kp_Uls_T_f32;
	VAR(float32, AUTOMATIC) Ki_Uls_T_f32;
	VAR(float32, AUTOMATIC) PTerm_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITerm_HwNm_T_f32;
	VAR(float32, AUTOMATIC) PITerm_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITermA_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITermB_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITermC_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITermLim_HwNm_T_f32;
	VAR(float32, AUTOMATIC) IntLimUpper_HwNm_T_f32;
	VAR(float32, AUTOMATIC) DampgTermInter_HwNm_T_f32;
	VAR(float32, AUTOMATIC) DampgTerm_HwNm_T_f32;
	VAR(float32, AUTOMATIC) RtnCmdLimUpper_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PreLimRtnCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) CtrldVelRtnCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) BasicRtnVehSpeedBlend_Uls_T_f32;
	VAR(float32, AUTOMATIC) CtrldVelRtnVehSpeedBlend_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVel_HwDegpS_T_f32 = 0.0F;
	
	/* read inputs */
	BasicRtnCmd_MtrNm_T_f32 = Rte_IRead_BmwRtnArbn_Per1_BasicRtnCmd_MtrNm_f32();
	EnableCVR_Cnt_T_lgc     = Rte_IRead_BmwRtnArbn_Per1_EnableCVR_Cnt_lgc();
	
	if(EnableCVR_Cnt_T_lgc == TRUE)
	{
		DefeatReturnSvc_Cnt_T_lgc = Rte_IRead_BmwRtnArbn_Per1_DefeatReturnSvc_Cnt_lgc();
		DiagStsHwPosDis_Cnt_T_lgc = Rte_IRead_BmwRtnArbn_Per1_DiagStsHwPosDis_Cnt_lgc();
		HandwheelAuthority_Uls_T_f32 = Rte_IRead_BmwRtnArbn_Per1_HandwheelAuthority_Uls_f32();
		HandwheelPosition_HwDeg_T_f32 = Rte_IRead_BmwRtnArbn_Per1_HandwheelPosition_HwDeg_f32();
		HandwheelVelocity_HwRadpS_T_f32 = Rte_IRead_BmwRtnArbn_Per1_HandwheelVelocity_HwRadpS_f32();
		HwTorque_HwNm_T_f32 = Rte_IRead_BmwRtnArbn_Per1_HwTorque_HwNm_f32();
		MRFMtrTrqCmdScl_MtrNm_T_f32 = Rte_IRead_BmwRtnArbn_Per1_MRFMtrTrqCmdScl_MtrNm_f32();
		PAReturnSclFct_Uls_T_f32 = Rte_IRead_BmwRtnArbn_Per1_PAReturnSclFct_Uls_f32();
		ReturnDDFactor_Uls_T_f32 = Rte_IRead_BmwRtnArbn_Per1_ReturnDDFactor_Uls_f32();
		ReturnOffset_HwDeg_T_f32 = Rte_IRead_BmwRtnArbn_Per1_ReturnOffset_HwDeg_f32();
		VehicleSpeed_Kph_T_f32 = Rte_IRead_BmwRtnArbn_Per1_VehicleSpeed_Kph_f32();

		/* Input Conditioning */
		InpCdng(ReturnOffset_HwDeg_T_f32,
				HandwheelPosition_HwDeg_T_f32,
				HandwheelVelocity_HwRadpS_T_f32,
				&CompHwPos_HwDeg_T_f32,
				&HwVel_HwDegpS_T_f32);
		
		/* Driver Torque Selector */
		DrvTrq_HwNm_T_f32 = DrvrTqSelctr(MRFMtrTrqCmdScl_MtrNm_T_f32,
										 HwTorque_HwNm_T_f32,
										 CompHwPos_HwDeg_T_f32,
										 HandwheelVelocity_HwRadpS_T_f32);
										 
		/****** Start of 'Return Command' ******/
		
		VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);
		HwPosAbs_HwDeg_T_u12p4 = FPM_FloatToFixed_m(Abs_f32_m(CompHwPos_HwDeg_T_f32), u12p4_T);
		
		/*** Start of 'Scale' ***/
		DrvTrqFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(DrvTrq_HwNm_T_f32, &BmwRtnArbn_DrvTrqLPFSV_HwNm_M_Str);
		BmwRtnArbn_DrvTrqFilt_HwNm_D_f32 = DrvTrqFilt_HwNm_T_f32;
		
		TbarTrqFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &BmwRtnArbn_TbarTrqLPFSV_HwNm_M_Str);

		/* Torque Gradient Scale */
		TrqGrdtSca_Uls_T_f32 = TqGrdtSca(DrvTrqFilt_HwNm_T_f32,VehicleSpeed_Kph_T_f32);
		BmwRtnArbn_TrqGrdtSca_Uls_D_f32 = TrqGrdtSca_Uls_T_f32;
		
		/* TBar Torque Scale */
		TbarTrqSca_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
															   FPM_FloatToFixed_m(Abs_f32_m(TbarTrqFilt_HwNm_T_f32), u8p8_T),
															   t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7,
															   TableSize_m(t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7),
															   (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_TBarTrqScaX_HwNm_u8p8,
															   (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_TBarTrqScaY_Uls_u2p14,
															   TableSize_m(t2_BmwRA_TBarTrqScaX_HwNm_u8p8[0]));
															   
		TbarTrqSca_Uls_T_f32 = FPM_FixedToFloat_m(TbarTrqSca_Uls_T_u2p14, u2p14_T);													   
		BmwRtnArbn_TbarTrqSca_Uls_D_f32 = TbarTrqSca_Uls_T_f32;
		
		/* Position Scale */
		PosSca_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwRA_PosScaX_HwDeg_u12p4,
														 t_BmwRA_PosScaY_Uls_u2p14,
														 TableSize_m(t_BmwRA_PosScaX_HwDeg_u12p4),
														 HwPosAbs_HwDeg_T_u12p4);
		
		PosSca_Uls_T_f32 = FPM_FixedToFloat_m(PosSca_Uls_T_u2p14, u2p14_T);													   
		BmwRtnArbn_PosSca_Uls_D_f32 = PosSca_Uls_T_f32;
		
		/* Velocity Error Scale */
		VelErrSca_Uls_T_f32 = VelErrSca(CompHwPos_HwDeg_T_f32,
										HwVel_HwDegpS_T_f32,
										VehicleSpeed_Kph_T_f32,
										DesVel_HwDegpS_T_f32);
		BmwRtnArbn_VelErrorSca_Uls_D_f32 = VelErrSca_Uls_T_f32;

		/* Hand wheel Torque Scale */
		HwTrqSca_Uls_T_f32 = HwTrqSca(DrvTrqFilt_HwNm_T_f32,
									  HwVel_HwDegpS_T_f32,
									  VehicleSpeed_Kph_T_f32);
		BmwRtnArbn_HwTrqSca_Uls_D_f32 = HwTrqSca_Uls_T_f32;
		
		/* Hand wheel Authority Scale */
		HwAuthySca_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwRA_HwAuthyScaX_Uls_u2p14,
															 t_BmwRA_HwAuthyScaY_Uls_u2p14,
															 TableSize_m(t_BmwRA_HwAuthyScaX_Uls_u2p14),
															 FPM_FloatToFixed_m(HandwheelAuthority_Uls_T_f32, u2p14_T));
		
		HwAuthySca_Uls_T_f32 = FPM_FixedToFloat_m(HwAuthySca_Uls_T_u2p14, u2p14_T);	
		
		HwAuthySca_Uls_T_f32 = Limit_m(HwAuthySca_Uls_T_f32, 
									  (BmwRtnArbn_PrevHwAuthySca_Uls_M_f32 - (k_BmwRA_HwAuthySlew_UlspS_f32 * D_2MS_SEC_F32)),
									  (BmwRtnArbn_PrevHwAuthySca_Uls_M_f32 + (k_BmwRA_HwAuthySlew_UlspS_f32 * D_2MS_SEC_F32)));

		BmwRtnArbn_PrevHwAuthySca_Uls_M_f32 = HwAuthySca_Uls_T_f32;
		
		BmwRtnArbn_HwAuthySca_Uls_D_f32 = HwAuthySca_Uls_T_f32;
		
		/* Control scale */
		CtrlScaPreFilt_Uls_T_f32 = PosSca_Uls_T_f32 * 
								   HwTrqSca_Uls_T_f32 * 
								   TbarTrqSca_Uls_T_f32 *
								   TrqGrdtSca_Uls_T_f32 *
								   VelErrSca_Uls_T_f32 *
								   HwAuthySca_Uls_T_f32;
									
		BmwRtnArbn_CtrlScaPreFilt_Uls_D_f32 = CtrlScaPreFilt_Uls_T_f32;
		
		CtrlSca_Uls_T_f32 = LPF_OpUpdate_f32_m(CtrlScaPreFilt_Uls_T_f32, &BmwRtnArbn_CtrlScaLPFSV_Uls_M_Str);
		
		BmwRtnArbn_CtrlSca_Uls_D_f32 = CtrlSca_Uls_T_f32;
		
		/* Desired Velocity Scale */
		DesVelScaPreFilt_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
																	 FPM_FloatToFixed_m(Abs_f32_m(DrvTrqFilt_HwNm_T_f32), u8p8_T),
																	 t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7,
																	 TableSize_m(t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7),
																	 (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_DesVelScaX_HwNm_u8p8,
																	 (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_DesVelScaY_Uls_u2p14,
																	 TableSize_m(t2_BmwRA_DesVelScaX_HwNm_u8p8[0]));
															   
		DesVelScaPreFilt_Uls_T_f32 = FPM_FixedToFloat_m(DesVelScaPreFilt_Uls_T_u2p14, u2p14_T);													   
		BmwRtnArbn_DesVelScaPreFilt_Uls_D_f32 = DesVelScaPreFilt_Uls_T_f32;
		
		DesVelSca_Uls_T_f32 = LPF_OpUpdate_f32_m(DesVelScaPreFilt_Uls_T_f32, &BmwRtnArbn_DesVelScaLPFSV_Uls_M_Str);
		BmwRtnArbn_DesVelSca_Uls_D_f32 = DesVelSca_Uls_T_f32;
		/*** End of 'Scale' ***/
		
		/*** Start of 'Target Velocity' ***/
		DesVelScaFacPreFilt_Uls_T_u10p6 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
																		HwPosAbs_HwDeg_T_u12p4,
																		t_BmwRA_VehSpdTbl_Kph_u9p7,
																		TableSize_m(t_BmwRA_VehSpdTbl_Kph_u9p7),
																		(P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_DesVelX_HwDeg_u12p4,
																		(P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_DesVelY_HwDegpS_u10p6,
																		TableSize_m(t2_BmwRA_DesVelX_HwDeg_u12p4[0]));
															   
		DesVelScaFacPreFilt_Uls_T_f32 = FPM_FixedToFloat_m(DesVelScaFacPreFilt_Uls_T_u10p6, u10p6_T);		
		
		DesVelPreFilt_HwDegpS_T_f32 = (-(float32)Sign_f32_m(CompHwPos_HwDeg_T_f32)) *
									  DesVelScaFacPreFilt_Uls_T_f32 * 								  
									  DesVelSca_Uls_T_f32;
		
		DesVel_HwDegpS_T_f32 = LPF_OpUpdate_f32_m(DesVelPreFilt_HwDegpS_T_f32, &BmwRtnArbn_DesVelLPFSV_HwDegpS_M_Str);		
		BmwRtnArbn_DesVel_HwDegpS_D_f32 = DesVel_HwDegpS_T_f32;
		/*** End of 'Target Velocity' ***/
		
		/*** Start of 'Control' ***/
		VelErr_HwDegpS_T_f32 = DesVel_HwDegpS_T_f32 - HwVel_HwDegpS_T_f32;
		
		/* Control Gain */
		Kp_Uls_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwRA_VehSpdTbl_Kph_u9p7,
													 t_BmwRA_Kp_Uls_u4p12,
													 TableSize_m(t_BmwRA_VehSpdTbl_Kph_u9p7),
													 VehicleSpeed_Kph_T_u9p7);
		
		Kp_Uls_T_f32 = FPM_FixedToFloat_m(Kp_Uls_T_u4p12, u4p12_T);		
		
		Ki_Uls_T_u8p8 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwRA_VehSpdTbl_Kph_u9p7,
													t_BmwRA_Ki_Uls_u8p8,
													TableSize_m(t_BmwRA_VehSpdTbl_Kph_u9p7),
													VehicleSpeed_Kph_T_u9p7);
		
		Ki_Uls_T_f32 = FPM_FixedToFloat_m(Ki_Uls_T_u8p8, u8p8_T);
		
		/* Proportional Control */
		PTerm_HwNm_T_f32 = Kp_Uls_T_f32 * VelErr_HwDegpS_T_f32 * CtrlSca_Uls_T_f32;
		
		BmwRtnArbn_PTermCmd_HwNm_D_f32 = PTerm_HwNm_T_f32;
		
		/* Integral Control */
		IntLimUpper_HwDeg_T_u10p6 		 = BilinearXYM_u16_u16Xu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
																		 HwPosAbs_HwDeg_T_u12p4,
																		 t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7,
																		 TableSize_m(t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7),
																		 (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t_BmwRA_PosScaX_HwDeg_u12p4,
																		 (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_IntgtrLimTblY_HwDeg_u10p6,
																		 TableSize_m(t_BmwRA_PosScaX_HwDeg_u12p4));
		IntLimUpper_HwNm_T_f32 	 		 = FPM_FixedToFloat_m(IntLimUpper_HwDeg_T_u10p6, u10p6_T) * CtrlSca_Uls_T_f32 ;
		BmwRtnArbn_IntgtrLim_HwNm_D_f32  = IntLimUpper_HwNm_T_f32;
		ITermA_HwNm_T_f32 				 = VelErr_HwDegpS_T_f32 * CtrlSca_Uls_T_f32;
		ITermB_HwNm_T_f32 				 = ITermA_HwNm_T_f32 + BmwRtnArbn_PrevITermC_HwNm_M_f32;
		ITermC_HwNm_T_f32 				 = (((ITermB_HwNm_T_f32 + BmwRtnArbn_PrevITermB_HwNm_M_f32) * 0.5F) * D_2MS_SEC_F32) + BmwRtnArbn_PrevITermLim_HwNm_M_f32;
		ITermLim_HwNm_T_f32 			 = Limit_m(ITermC_HwNm_T_f32, -IntLimUpper_HwNm_T_f32, IntLimUpper_HwNm_T_f32);
		ITerm_HwNm_T_f32 				 	= ITermLim_HwNm_T_f32 * Ki_Uls_T_f32;
		BmwRtnArbn_PrevITermB_HwNm_M_f32 	= ITermB_HwNm_T_f32;
		BmwRtnArbn_PrevITermC_HwNm_M_f32 	= (ITermLim_HwNm_T_f32 - ITermC_HwNm_T_f32) * k_BmwRA_Kb_Uls_f32;
		BmwRtnArbn_PrevITermLim_HwNm_M_f32  = ITermLim_HwNm_T_f32;
		BmwRtnArbn_ITermCmd_HwNm_D_f32 	 	= ITerm_HwNm_T_f32;
		PITerm_HwNm_T_f32 				 	= PTerm_HwNm_T_f32 + ITerm_HwNm_T_f32;
		/*** End of 'Control' ***/
		
		/*** Start of 'Damping' ***/
		DampgTermInter_HwNm_T_u6p10 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
																	FPM_FloatToFixed_m(Abs_f32_m(HwVel_HwDegpS_T_f32), u10p6_T),
																	t_BmwRA_VehSpdTbl_Kph_u9p7,
																	TableSize_m(t_BmwRA_VehSpdTbl_Kph_u9p7),
																	(P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_DampgTblX_HwDegpS_u10p6,
																	(P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_DampgTblY_HwNm_u6p10,
																	TableSize_m(t2_BmwRA_DampgTblX_HwDegpS_u10p6[0]));
															   
		DampgTermInter_HwNm_T_f32 = FPM_FixedToFloat_m(DampgTermInter_HwNm_T_u6p10, u6p10_T);		
		
		DampgTerm_HwNm_T_f32 = ((float32)Sign_f32_m(HwVel_HwDegpS_T_f32)) *
							   DampgTermInter_HwNm_T_f32 *
							   ((k_BmwRA_DampgEnable_Cnt_Lgc == TRUE)? 1.0F : 0.0F) *
							   ((k_BmwRA_DampgScaEnable_Cnt_Lgc == TRUE)? CtrlSca_Uls_T_f32 : 1.0F);
		
		BmwRtnArbn_DampgCmd_HwNm_D_f32 = DampgTerm_HwNm_T_f32;
		
		/*** End of 'Damping' ***/
		
		/*** Start of 'Limit' ***/
		
		RtnCmdLimUpper_MtrNm_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwRA_VehSpdTbl_Kph_u9p7,
																   t_BmwRA_OutpLimTblY_MtrNm_u4p12,
																   TableSize_m(t_BmwRA_VehSpdTbl_Kph_u9p7),
																   VehicleSpeed_Kph_T_u9p7);
		
		RtnCmdLimUpper_MtrNm_T_f32 = FPM_FixedToFloat_m(RtnCmdLimUpper_MtrNm_T_u4p12, u4p12_T);	
		
		if((DefeatReturnSvc_Cnt_T_lgc == TRUE) || (DiagStsHwPosDis_Cnt_T_lgc == TRUE))
		{
			PreLimRtnCmd_MtrNm_T_f32 = 0.0F;
		}
		else
		{
			PreLimRtnCmd_MtrNm_T_f32 = ((PITerm_HwNm_T_f32 - DampgTerm_HwNm_T_f32) *
										k_BmwRA_Polarity_Uls_f32 *
										ReturnDDFactor_Uls_T_f32 *
										PAReturnSclFct_Uls_T_f32) / k_Cmn_SysTrqRatio_HwNmpMtrNm_f32;
		}
		
		BmwRtnArbn_RtnCmdPreLim_MtrNm_D_f32 = PreLimRtnCmd_MtrNm_T_f32;
		
		CtrldVelRtnCmd_MtrNm_T_f32 = Limit_m(PreLimRtnCmd_MtrNm_T_f32, -RtnCmdLimUpper_MtrNm_T_f32, RtnCmdLimUpper_MtrNm_T_f32);
		
		BmwRtnArbn_ReturnCmd_MtrNm_D_f32 = CtrldVelRtnCmd_MtrNm_T_f32;
		/*** End of 'Limit' ***/
		
	
		CtrldVelRtnVehSpeedBlend_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwRA_VehSpdTbl_Kph_u9p7,
																			 t_BmwRA_BlendFactorTbl1_Uls_u2p14,
																			 TableSize_m(t_BmwRA_VehSpdTbl_Kph_u9p7),
																			 VehicleSpeed_Kph_T_u9p7);
		
		CtrldVelRtnVehSpeedBlend_Uls_T_f32 = FPM_FixedToFloat_m(CtrldVelRtnVehSpeedBlend_Uls_T_u2p14, u2p14_T);

		BasicRtnVehSpeedBlend_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwRA_VehSpdTbl_Kph_u9p7,
																		  t_BmwRA_BlendFactorTbl2_Uls_u2p14,
																		  TableSize_m(t_BmwRA_VehSpdTbl_Kph_u9p7),
																		  VehicleSpeed_Kph_T_u9p7);		
		
		BasicRtnVehSpeedBlend_Uls_T_f32 = FPM_FixedToFloat_m(BasicRtnVehSpeedBlend_Uls_T_u2p14, u2p14_T);
		
		RtnCmd_MtrNm_T_f32 = (CtrldVelRtnVehSpeedBlend_Uls_T_f32 * CtrldVelRtnCmd_MtrNm_T_f32) +
							 (BasicRtnVehSpeedBlend_Uls_T_f32 * BasicRtnCmd_MtrNm_T_f32);
							 		
	}
	else
	{
		/*** Reset conditions as mentioned in the below path of FDD simulink model ***/
		/*** Path : CF019A_BmwRtnArbn_update/BmwRtnArbn/BmwRtnArbn_Per1/Control Velocity Return Disabled/Reset state variables ***/
		
		if(FALSE != BmwRtnArbn_EnableCVR_Cnt_M_lgc)
			{
				LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_DesVelLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_DesVelLPFSV_HwDegpS_M_Str);
				LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_HwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_DrvTrqLPFSV_HwNm_M_Str);
				LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_HwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_TbarTrqLPFSV_HwNm_M_Str);
				LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_ScaLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_DesVelScaLPFSV_Uls_M_Str);
				LPF_Init_f32_m(D_ZERO_ULS_F32, k_BmwRA_ScaLPFKn_Hz_f32, D_2MS_SEC_F32, &BmwRtnArbn_CtrlScaLPFSV_Uls_M_Str);
				
				/*** Reseting all state variables used in Unit delays in Control velocity return to zero ***/
				BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_ZERO_CNT_U08]	= 0.0F;
				BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_ONE_CNT_U08]	= 0.0F;
				BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_TWO_CNT_U08]	= 0.0F;
				BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_THREE_CNT_U08]	= 0.0F;
				BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_MAX4_CNT_U08]	= 0.0F;
				BmwRtnArbn_PrevRtnOffsetSlew_HwDeg_M_f32 			= 0.0F;
				BmwRtnArbn_PrevITermC_HwNm_M_f32					= 0.0F;
				BmwRtnArbn_PrevITermB_HwNm_M_f32					= 0.0F;
				BmwRtnArbn_PrevITermLim_HwNm_M_f32						= 0.0F;
				BmwRtnArbn_PrevHwAuthySca_Uls_M_f32					= 0.0F;
				BmwRtnArbn_PrevHwTrqScaSelector_Uls_M_f32			= 0.0F;
				BmwRtnArbn_PrevADrvTrqFilt_HwNm_M_f32				= 0.0F;
				BmwRtnArbn_PrevBDrvTrqFilt_HwNm_M_f32				= 0.0F;
				BmwRtnArbn_PrevCDrvTrqFilt_HwNm_M_f32				= 0.0F;
				BmwRtnArbn_PrevDDrvTrqFilt_HwNm_M_f32				= 0.0F;
				BmwRtnArbn_PrevEDrvTrqFilt_HwNm_M_f32				= 0.0F;
				BmwRtnArbn_PrevFDrvTrqFilt_HwNm_M_f32				= 0.0F;
				
				/*** Reseting all display variables used in Control velocity return to zero ***/
				BmwRtnArbn_HwPosComp_HwDeg_D_f32					= 0.0F;		 		
				BmwRtnArbn_DrvTrqEst_HwNm_D_f32						= 0.0F;		 	
				BmwRtnArbn_TrqGrdt_HwNmpS_D_f32						= 0.0F;		 	
				BmwRtnArbn_HwTrqScaSelector_Uls_D_f32				= 0.0F;		 		
				BmwRtnArbn_DrvTrqFilt_HwNm_D_f32					= 0.0F;		
				BmwRtnArbn_TrqGrdtSca_Uls_D_f32						= 0.0F;		
				BmwRtnArbn_TbarTrqSca_Uls_D_f32						= 0.0F;			
				BmwRtnArbn_PosSca_Uls_D_f32							= 0.0F;			
				BmwRtnArbn_VelErrorSca_Uls_D_f32					= 0.0F;			
				BmwRtnArbn_HwTrqSca_Uls_D_f32						= 0.0F;		
				BmwRtnArbn_HwAuthySca_Uls_D_f32						= 0.0F;
				BmwRtnArbn_CtrlScaPreFilt_Uls_D_f32					= 0.0F;
				BmwRtnArbn_CtrlSca_Uls_D_f32						= 0.0F;
				BmwRtnArbn_DesVelScaPreFilt_Uls_D_f32				= 0.0F;
				BmwRtnArbn_DesVelSca_Uls_D_f32						= 0.0F;
				BmwRtnArbn_DesVel_HwDegpS_D_f32						= 0.0F;
				BmwRtnArbn_PTermCmd_HwNm_D_f32						= 0.0F;
				BmwRtnArbn_IntgtrLim_HwNm_D_f32						= 0.0F;
				BmwRtnArbn_ITermCmd_HwNm_D_f32						= 0.0F;
				BmwRtnArbn_DampgCmd_HwNm_D_f32						= 0.0F;
				BmwRtnArbn_RtnCmdPreLim_MtrNm_D_f32					= 0.0F;
				BmwRtnArbn_ReturnCmd_MtrNm_D_f32					= 0.0F;
			}
		else
			{
				/* Do nothing */
			}
		
		RtnCmd_MtrNm_T_f32 = BasicRtnCmd_MtrNm_T_f32;
	}
	
	BmwRtnArbn_EnableCVR_Cnt_M_lgc	= EnableCVR_Cnt_T_lgc;
	
	RtnCmd_MtrNm_T_f32 = Limit_m(RtnCmd_MtrNm_T_f32, D_MTRTRQCMDLOLMT_MTRNM_F32, D_MTRTRQCMDHILMT_MTRNM_F32);
	
	Rte_IWrite_BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32(RtnCmd_MtrNm_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_BMWRTNARBN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Name		    :	InpCdng
* Description	:	Implementation of "Input Conditioning" block
* Inputs		:	ReturnOffset_HwDeg_T_f32,HandwheelPosition_HwDeg_T_f32,HandwheelVelocity_HwRadpS_T_f32
* 				    *CompHwPos_HwDeg_T_f32,*HwVel_HwDegpS_T_f32
* Outputs		:	None
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(void, BmwRtnArbn_APPL_CODE) InpCdng(VAR(float32,AUTOMATIC) ReturnOffset_HwDeg_T_f32,
		                                        VAR(float32,AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
												VAR(float32,AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32,
												P2VAR(float32, AUTOMATIC, BmwRtnArbn_APPL_VAR) CompHwPos_HwDeg_T_f32,
												P2VAR(float32, AUTOMATIC, BmwRtnArbn_APPL_VAR) HwVel_HwDegpS_T_f32)
{
	VAR(float32,AUTOMATIC) ReturnOffsetLimd_HwDeg_T_f32;
	VAR(float32,AUTOMATIC) ReturnOffsetSlew_HwDeg_T_f32;
	
	ReturnOffsetLimd_HwDeg_T_f32 = Limit_m(ReturnOffset_HwDeg_T_f32, -k_BmwRA_OffsRng_HwDeg_f32, k_BmwRA_OffsRng_HwDeg_f32);
	
	ReturnOffsetSlew_HwDeg_T_f32 = Limit_m(ReturnOffsetLimd_HwDeg_T_f32, 
	                                      (BmwRtnArbn_PrevRtnOffsetSlew_HwDeg_M_f32 - (k_BmwRA_OffsSlew_HwDegpS_f32 * D_2MS_SEC_F32)),
										  (BmwRtnArbn_PrevRtnOffsetSlew_HwDeg_M_f32 + (k_BmwRA_OffsSlew_HwDegpS_f32 * D_2MS_SEC_F32)));
										  
	BmwRtnArbn_PrevRtnOffsetSlew_HwDeg_M_f32 = ReturnOffsetSlew_HwDeg_T_f32;
	
	*CompHwPos_HwDeg_T_f32 = HandwheelPosition_HwDeg_T_f32 - ReturnOffsetSlew_HwDeg_T_f32;
	
	BmwRtnArbn_HwPosComp_HwDeg_D_f32 = *CompHwPos_HwDeg_T_f32;
	
	*HwVel_HwDegpS_T_f32 = HandwheelVelocity_HwRadpS_T_f32/D_PIOVR180_ULS_F32;	                                       
}
/**********************************************************************************************************************
* Name		    :	DrvrTqSelctr
* Description	:	Implementation of "Driver Torque Selector" block
* Inputs		:	MtrTrqCmd_MtrNm_T_f32,TbarTrq_HwNm_T_f32,HwPos_HwDeg_T_f32,HwVel_HwDegpS_T_f32
* Outputs		:	DrvTrq_HwNm_T_f32
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(float32, BmwRtnArbn_APPL_CODE) DrvrTqSelctr(VAR(float32,AUTOMATIC) MtrTrqCmd_MtrNm_T_f32,
														VAR(float32,AUTOMATIC) TbarTrq_HwNm_T_f32,
									                    VAR(float32,AUTOMATIC) HwPos_HwDeg_T_f32,
									                    VAR(float32,AUTOMATIC) HwVel_HwRadpS_T_f32)
{
	VAR(float32,AUTOMATIC) DrvTrq_HwNm_T_f32;
	VAR(float32,AUTOMATIC) TrqMtrx_HwNm_T_f3[4];
	VAR(float32,AUTOMATIC) OutpMtrxA_Uls_T_f32[5];
	VAR(float32,AUTOMATIC) OutpMtrxB_Uls_T_f32[5];
	VAR(float32,AUTOMATIC) Sum_Uls_T_f32 = 0.0F;
	VAR(float32,AUTOMATIC) SumA_Uls_T_f32 = 0.0F;
	VAR(float32,AUTOMATIC) SumB_Uls_T_f32 = 0.0F;
	VAR(float32,AUTOMATIC) PrevOutpMtrxTmp_Uls_T_f32[5];

	VAR(uint8,AUTOMATIC) RowIdx_Uls_T_u08;
	VAR(uint8,AUTOMATIC) ColIdx_Uls_T_u08;
 
	if(k_BmwRA_DrvTrqEnable_Cnt_Lgc != FALSE)
	{
		TrqMtrx_HwNm_T_f3[0] = (MtrTrqCmd_MtrNm_T_f32 * k_Cmn_SysTrqRatio_HwNmpMtrNm_f32);
		TrqMtrx_HwNm_T_f3[1] = TbarTrq_HwNm_T_f32;
		TrqMtrx_HwNm_T_f3[2] = (HwPos_HwDeg_T_f32 * D_PIOVR180_ULS_F32);
		TrqMtrx_HwNm_T_f3[3] = HwVel_HwRadpS_T_f32;

		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX5_CNT_U08; RowIdx_Uls_T_u08++)
		{
			SumA_Uls_T_f32 = SumA_Uls_T_f32 + ((t_BmwRA_DrvTrqMtrxC_Uls_f32[RowIdx_Uls_T_u08]) *
											   (BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[RowIdx_Uls_T_u08]));
		}
		
		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX4_CNT_U08; RowIdx_Uls_T_u08++)
		{
			SumB_Uls_T_f32 = SumB_Uls_T_f32 + ((t_BmwRA_DrvTrqMtrxD_Uls_f32[RowIdx_Uls_T_u08]) *
											   (TrqMtrx_HwNm_T_f3[RowIdx_Uls_T_u08]));
		}

		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX5_CNT_U08; RowIdx_Uls_T_u08++)
		{
			for (ColIdx_Uls_T_u08 = 0U; ColIdx_Uls_T_u08 < D_MAX4_CNT_U08; ColIdx_Uls_T_u08++)
			{
				Sum_Uls_T_f32 = Sum_Uls_T_f32 + ((t2_BmwRA_DrvTrqMtrxB_Uls_f32[RowIdx_Uls_T_u08][ColIdx_Uls_T_u08]) *
												 (TrqMtrx_HwNm_T_f3[ColIdx_Uls_T_u08]));
			}
			OutpMtrxA_Uls_T_f32[RowIdx_Uls_T_u08] = Sum_Uls_T_f32;

			Sum_Uls_T_f32 = 0.0F;
		}
		
		

		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX5_CNT_U08; RowIdx_Uls_T_u08++)
		{
			for (ColIdx_Uls_T_u08 = 0U; ColIdx_Uls_T_u08 < D_MAX5_CNT_U08; ColIdx_Uls_T_u08++)
			{
				Sum_Uls_T_f32 = Sum_Uls_T_f32 + ((t2_BmwRA_DrvTrqMtrxA_Uls_f32[RowIdx_Uls_T_u08][ColIdx_Uls_T_u08]) *
												 (BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[ColIdx_Uls_T_u08]));
			}
			OutpMtrxB_Uls_T_f32[RowIdx_Uls_T_u08] = Sum_Uls_T_f32;
				
			Sum_Uls_T_f32 = 0.0F;
		}
		
		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX5_CNT_U08; RowIdx_Uls_T_u08++)
		{
			PrevOutpMtrxTmp_Uls_T_f32[RowIdx_Uls_T_u08] = OutpMtrxA_Uls_T_f32[RowIdx_Uls_T_u08] + OutpMtrxB_Uls_T_f32[RowIdx_Uls_T_u08];
		}

		BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_ZERO_CNT_U08] 	= Limit_m(PrevOutpMtrxTmp_Uls_T_f32[D_ZERO_CNT_U08], -D_DRVRTQOBSVRAGTHD_HWRAD_F32, D_DRVRTQOBSVRAGTHD_HWRAD_F32);
		BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_ONE_CNT_U08] 	= Limit_m(PrevOutpMtrxTmp_Uls_T_f32[D_ONE_CNT_U08], -D_DRVRTQOBSVRVELTHD_HWRADPERSEC_F32, D_DRVRTQOBSVRVELTHD_HWRADPERSEC_F32);
		BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_TWO_CNT_U08] 	= Limit_m(PrevOutpMtrxTmp_Uls_T_f32[D_TWO_CNT_U08], -D_DRVRTQOBSVRAGTHD_HWRAD_F32, D_DRVRTQOBSVRAGTHD_HWRAD_F32);
		BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_THREE_CNT_U08]	= Limit_m(PrevOutpMtrxTmp_Uls_T_f32[D_THREE_CNT_U08], -D_DRVRTQOBSVRVELTHD_HWRADPERSEC_F32, D_DRVRTQOBSVRVELTHD_HWRADPERSEC_F32);
		BmwRtnArbn_PrevOutpMtrx_Uls_M_f32[D_MAX4_CNT_U08] 	= Limit_m(PrevOutpMtrxTmp_Uls_T_f32[D_MAX4_CNT_U08], -D_DRVRTQOBSVRTQTHD_HWNWTMTR_F32, D_DRVRTQOBSVRTQTHD_HWNWTMTR_F32);
		
		DrvTrq_HwNm_T_f32 = SumA_Uls_T_f32 + SumB_Uls_T_f32;
		
		DrvTrq_HwNm_T_f32 = Limit_m(DrvTrq_HwNm_T_f32, -D_DRVRTQOBSVRFINALTHD_HWNWTMTR_F32, D_DRVRTQOBSVRFINALTHD_HWNWTMTR_F32);
		
		BmwRtnArbn_DrvTrqEst_HwNm_D_f32 = DrvTrq_HwNm_T_f32;
	}
	else
	{
		DrvTrq_HwNm_T_f32 = TbarTrq_HwNm_T_f32;
	}
	
	return (DrvTrq_HwNm_T_f32);

}
/**********************************************************************************************************************
* Name		    :	TqGrdtSca
* Description	:	Implementation of "Torque Gradient Scale" block
* Inputs		:	DrvTrqFilt_HwNm_T_f32,VehicleSpeed_Kph_T_f32
* Outputs		:	TrqGrdtSca_Uls_T_f32
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(float32, BmwRtnArbn_APPL_CODE) TqGrdtSca(VAR(float32,AUTOMATIC) DrvTrqFilt_HwNm_T_f32,
                                                     VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32)
{
	VAR(float32,AUTOMATIC) TrqGrdt_HwNmpS_T_f32;
	VAR(uint16,AUTOMATIC) TrqGrdtSca_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) TrqGrdtSca_Uls_T_f32;
	VAR(float32,AUTOMATIC) DrvTrqFiltInter_HwNm_T_f32;
	
	DrvTrqFiltInter_HwNm_T_f32 = (float32)(DrvTrqFilt_HwNm_T_f32 * D_TRQGRADCALCNWGHTGFAC4_ULS_F32);
	
	if(k_BmwRA_TrqGrdtScaEnable_Cnt_lgc == TRUE)
	{		
		/* Torque Gradient */
		TrqGrdt_HwNmpS_T_f32 = (float32)(((float32)(DrvTrqFiltInter_HwNm_T_f32 - BmwRtnArbn_PrevFDrvTrqFilt_HwNm_M_f32) * D_TRQGRADCALCNWGHTGFAC1_ULS_F32) +
							             ((float32)(BmwRtnArbn_PrevADrvTrqFilt_HwNm_M_f32 - BmwRtnArbn_PrevEDrvTrqFilt_HwNm_M_f32) * D_TRQGRADCALCNWGHTGFAC2_ULS_F32) +
							             ((float32)(BmwRtnArbn_PrevBDrvTrqFilt_HwNm_M_f32 - BmwRtnArbn_PrevDDrvTrqFilt_HwNm_M_f32) * D_TRQGRADCALCNWGHTGFAC3_ULS_F32));
							   
		BmwRtnArbn_TrqGrdt_HwNmpS_D_f32 = TrqGrdt_HwNmpS_T_f32;
		
		BmwRtnArbn_PrevADrvTrqFilt_HwNm_M_f32 = DrvTrqFiltInter_HwNm_T_f32;
		BmwRtnArbn_PrevBDrvTrqFilt_HwNm_M_f32 = BmwRtnArbn_PrevADrvTrqFilt_HwNm_M_f32;
		BmwRtnArbn_PrevCDrvTrqFilt_HwNm_M_f32 = BmwRtnArbn_PrevBDrvTrqFilt_HwNm_M_f32;
		BmwRtnArbn_PrevDDrvTrqFilt_HwNm_M_f32 = BmwRtnArbn_PrevCDrvTrqFilt_HwNm_M_f32;
		BmwRtnArbn_PrevEDrvTrqFilt_HwNm_M_f32 = BmwRtnArbn_PrevDDrvTrqFilt_HwNm_M_f32;
		BmwRtnArbn_PrevFDrvTrqFilt_HwNm_M_f32 = BmwRtnArbn_PrevEDrvTrqFilt_HwNm_M_f32;
		
		TrqGrdtSca_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T),
															   FPM_FloatToFixed_m(Abs_f32_m(TrqGrdt_HwNmpS_T_f32), u8p8_T),
															   t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7,
															   TableSize_m(t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7),
															   (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_TrqGrdtScaX_HwNmpS_u8p8,
															   (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_TrqGrdtScaY_Uls_u2p14,
															   TableSize_m(t2_BmwRA_TrqGrdtScaX_HwNmpS_u8p8[0]));
		
		TrqGrdtSca_Uls_T_f32 = FPM_FixedToFloat_m(TrqGrdtSca_Uls_T_u2p14, u2p14_T);
	}
	else
	{
		TrqGrdtSca_Uls_T_f32 = 1.0F;
	}
	
	return TrqGrdtSca_Uls_T_f32;
}
/**********************************************************************************************************************
* Name		    :	VelErrSca
* Description	:	Implementation of "Velocity Error Scale" block
* Inputs		:	HwPos_HwDeg_T_f32, HwVel_HwDegpS_T_f32, VehicleSpeed_Kph_T_f32, DesVel_HwDegpS_T_f32
* Outputs		:	VelErrSca_Uls_T_f32
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(float32, BmwRtnArbn_APPL_CODE) VelErrSca(VAR(float32,AUTOMATIC) HwPos_HwDeg_T_f32,
													 VAR(float32,AUTOMATIC) HwVel_HwDegpS_T_f32,
													 VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32,
													 VAR(float32,AUTOMATIC) DesVel_HwDegpS_T_f32)
{
	VAR(uint16,AUTOMATIC) VelErrScaIntm_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) VelErrScaIntm_Uls_T_f32;
	VAR(uint16,AUTOMATIC) VehSpdIntpl_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) VehSpdIntpl_Uls_T_f32;
	VAR(float32,AUTOMATIC) VelErrSca_Uls_T_f32;
	
	if(k_BmwRA_VelErrScaEnable_Cnt_lgc == TRUE)
	{
		VelErrScaIntm_Uls_T_u2p14 = BilinearXYM_u16_s16Xu16YM_Cnt(FPM_FloatToFixed_m(Abs_f32_m(HwPos_HwDeg_T_f32), u12p4_T),
																  FPM_FloatToFixed_m((Abs_f32_m(Abs_f32_m(HwVel_HwDegpS_T_f32) - DesVel_HwDegpS_T_f32)), s10p5_T),
																  t_BmwRA_VelErrorScaZ_HwDeg_u12p4,
																  TableSize_m(t_BmwRA_VelErrorScaZ_HwDeg_u12p4),
																  (P2CONST(sint16, AUTOMATIC, BmwRtnArbn_CONST))t_BmwRA_VelErrorScaX_HwDegpS_s10p5,
																  (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_VelErrorScaY_Uls_u2p14,
																  TableSize_m(t_BmwRA_VelErrorScaX_HwDegpS_s10p5));
														
		VelErrScaIntm_Uls_T_f32 = FPM_FixedToFloat_m(VelErrScaIntm_Uls_T_u2p14, u2p14_T);													
	}
	else
	{
		VelErrScaIntm_Uls_T_f32 = 1.0F;
	}
	
	VehSpdIntpl_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7,
														  t_BmwRA_VelErrVehSpdScaY_Uls_u2p14,
														  TableSize_m(t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7),
														  FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T));
	
	VehSpdIntpl_Uls_T_f32 = FPM_FixedToFloat_m(VehSpdIntpl_Uls_T_u2p14, u2p14_T);													   
	
	VelErrSca_Uls_T_f32 = (VelErrScaIntm_Uls_T_f32 * VehSpdIntpl_Uls_T_f32) + 
	                      (1.0F - VehSpdIntpl_Uls_T_f32);
	
	return VelErrSca_Uls_T_f32;
}
/**********************************************************************************************************************
* Name		    :	HwTrqSca
* Description	:	Implementation of "Hand wheel Torque Scale" block
* Inputs		:	DrvTrqFilt_HwNm_T_f32,HwVel_HwDegpS_T_f32,VehicleSpeed_Kph_T_f32
* Outputs		:	HwTrqSca_Uls_T_f32
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(float32, BmwRtnArbn_APPL_CODE) HwTrqSca(VAR(float32,AUTOMATIC) DrvTrqFilt_HwNm_T_f32,
													VAR(float32,AUTOMATIC) HwVel_HwDegpS_T_f32,
													VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32)
{
	VAR(float32,AUTOMATIC) HwTrqSca_Uls_T_f32;
	VAR(float32,AUTOMATIC) HwTrqScaInp_Uls_T_f32;
	VAR(float32,AUTOMATIC) HwTrqScaSelector_Uls_T_f32;
	VAR(uint16,AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
	VAR(uint16,AUTOMATIC) DrvTrqFiltAbs_HwNm_T_u8p8;
	VAR(uint16,AUTOMATIC) HwTrqSca1_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) HwTrqSca1_Uls_T_f32;
	VAR(uint16,AUTOMATIC) HwTrqSca2_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) HwTrqSca2_Uls_T_f32;
	
	/* Select Hand wheel Torque Scale */
	if(((DrvTrqFilt_HwNm_T_f32 > k_BmwRA_SelHwTrqScaTrqThr_HwNm_f32)&&
	    (HwVel_HwDegpS_T_f32 > k_BmwRA_SelHwTrqScaVelThr_HwDegpS_f32))  ||
	   ((DrvTrqFilt_HwNm_T_f32 < -k_BmwRA_SelHwTrqScaTrqThr_HwNm_f32)&&
	    (HwVel_HwDegpS_T_f32 < -k_BmwRA_SelHwTrqScaVelThr_HwDegpS_f32))) 
	{
		HwTrqScaInp_Uls_T_f32 = 1.0F;
	}
	else
	{
		HwTrqScaInp_Uls_T_f32 = 0.0F;
	}
	
	HwTrqScaSelector_Uls_T_f32 = Limit_m(HwTrqScaInp_Uls_T_f32, 
								        (BmwRtnArbn_PrevHwTrqScaSelector_Uls_M_f32 + (k_BmwRA_SelHwTrqScaSlewDec_UlspS_f32 * D_2MS_SEC_F32)),
								        (BmwRtnArbn_PrevHwTrqScaSelector_Uls_M_f32 + (k_BmwRA_SelHwTrqScaSlewInc_UlspS_f32 * D_2MS_SEC_F32)));
	
	BmwRtnArbn_PrevHwTrqScaSelector_Uls_M_f32 = HwTrqScaSelector_Uls_T_f32;
	
	BmwRtnArbn_HwTrqScaSelector_Uls_D_f32 = HwTrqScaSelector_Uls_T_f32;
	
	/* Hand wheel Torque Scale Calculation */
	VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);
	DrvTrqFiltAbs_HwNm_T_u8p8 = FPM_FloatToFixed_m(Abs_f32_m(DrvTrqFilt_HwNm_T_f32), u8p8_T);
	
	HwTrqSca1_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
														  DrvTrqFiltAbs_HwNm_T_u8p8,
														  t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7,
														  TableSize_m(t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7),
														  (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_HwTrqSca1X_HwNm_u8p8,
														  (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_HwTrqSca1Y_Uls_u2p14,
														  TableSize_m(t2_BmwRA_HwTrqSca1X_HwNm_u8p8[0]));
												
	HwTrqSca1_Uls_T_f32 = FPM_FixedToFloat_m(HwTrqSca1_Uls_T_u2p14, u2p14_T);	
	
	HwTrqSca2_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
														  DrvTrqFiltAbs_HwNm_T_u8p8,
														  t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7,
														  TableSize_m(t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7),
														  (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_HwTrqSca2X_HwNm_u8p8,
														  (P2CONST(uint16, AUTOMATIC, BmwRtnArbn_CONST))t2_BmwRA_HwTrqSca2Y_Uls_u2p14,
														  TableSize_m(t2_BmwRA_HwTrqSca2X_HwNm_u8p8[0]));
											
	HwTrqSca2_Uls_T_f32 = FPM_FixedToFloat_m(HwTrqSca2_Uls_T_u2p14, u2p14_T);	
	
	HwTrqSca_Uls_T_f32 = (HwTrqSca1_Uls_T_f32 * HwTrqScaSelector_Uls_T_f32) + 
	                     ((1.0F - HwTrqScaSelector_Uls_T_f32) * HwTrqSca2_Uls_T_f32);
						 
	return HwTrqSca_Uls_T_f32;
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
