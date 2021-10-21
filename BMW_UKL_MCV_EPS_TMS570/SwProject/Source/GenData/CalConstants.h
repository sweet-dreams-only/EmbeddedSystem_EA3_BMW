/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri May  9 16:48:22 2003
* %version:          EA3#215.1.24 %
* %date_modified:    Mon Feb 17 16:39:11 2014 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Dem_Api_Depend.h"
#include "filters.h"
#include "Ap_DiagMgr_Types.h"

#define D_NUMOFTUNSETS_CNT_U16 	8U
#define D_NUMOFPERS_CNT_U16 	6U

/* Put this at end of file
extern P2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
extern P2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;
extern CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16];
extern CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16];
*/
/* Manually removed the macro for the k_CalID_Cnt_u16. This was required because the tuning sets/personalities needed to be
 * looped through to find the correct offset for the tuning set and personalities. *//* <- Remove this extra comment
#ifdef k_CalID_Cnt_u16
	#undef k_CalID_Cnt_u16
#endif

#ifdef k_PMAPersonality_CalID_Cnt_u16
	#undef k_PMAPersonality_CalID_Cnt_u16
#endif

#ifdef k_HWAPId_Cnt_u32
	#undef k_HWAPId_Cnt_u32
#endif

extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer3_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer4_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer5_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer6_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer7_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer8_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer9_Cnt_Str;


extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet0_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet1_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet2_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet3_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet4_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet5_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet6_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet7_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet8_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet9_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet10_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet11_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet12_Cnt_Str;
*/


/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 5/26/2017 1:16:24 PM *******************/
/************************* BMW UKL Program - Rev 273 *************************/



/************* Tuning Structure Definition for "Y" Calibrations **************/

typedef struct
{
	float32	k_EnableHwAuthMin_Uls_f32;
	float32	k_EnableHwPosMax_HwDeg_f32;
	float32	k_EnableHwTrqMax_HwNm_f32;
	float32	k_EnableHwVelMax_DegpS_f32;
	float32	k_EnableLatAccMax_MpSecSq_f32;
	uint32	k_EnableTime_mS_u32;
	float32	k_EnableVehSpdMax_Kph_f32;
	float32	k_EnableVehSpdMin_Kph_f32;
	float32	k_EnableVehSpdRateMax_KphpS_f32;
	float32	k_EnableYawRateMax_DegpS_f32;
	float32	k_FiltDeadband_HwNm_f32;
	float32	k_HwNmToMtrNm_MtrNmpHwNm_f32;
	float32	k_HwTrqFilt_Hz_f32;
	float32	k_LTFilt_Hz_f32;
	float32	k_LTIntInputLimit_HwNm_f32;
	float32	k_LTLearnTime_Min_f32;
	float32	k_LTLimit_HwNm_f32;
	float32	k_OutputMaxRate_HwNmpS_f32;
	float32	k_STFilt_Hz_f32;
	float32	k_STIntInputLimit_HwNm_f32;
	float32	k_STLearnTimeDec_Sec_f32;
	float32	k_STLearnTimeInc_Sec_f32;
	float32	k_STLimit_HwNm_f32;
	uint32	k_STOppSignTime_mS_u32;
	float32	k_STRampTime_Sec_f32;
	float32	k_STResetHwPos_HwDeg_f32;
	float32	k_STResetHwTrq_HwNm_f32;
	float32	k_STResetLatAcc_MpSecSq_f32;
	float32	k_STResetYawRate_DegpS_f32;
	float32	k_TotalLimit_HwNm_f32;
	float32	k_YawRateFilt_Hz_f32;
	uint16	t_VehSpdScaleTblX_Kph_u9p7[4];
	uint16	t_VehSpdScaleTblY_Uls_u2p14[4];
	float32	k_RestoreThresh_MtrNm_f32;
	float32	k_SnLPullCmpFwLmt_MtrNm_f32;
	float32	k_EOLFricDiffLimitHigh_HwNm_f32;
	float32	k_EOLFricDiffLimitLow_HwNm_f32;
	float32	k_EOLFricDiffScalingFactor_Uls_f32;
	float32	k_FricOffsetLimitHigh_HwNm_f32;
	float32	k_FricOffsetLimitLow_HwNm_f32;
	float32	k_HwVelConstLimit_HwDegpS_f32;
	float32	k_HwVelMax_HwDegpS_f32;
	float32	k_HwVelMin_HwDegpS_f32;
	float32	k_LatAccMax_MpSecSqrd_f32;
	float32	k_LatAccMin_MpSecSqrd_f32;
	float32	t_BaselineFric_HwNm_f32[4];
	float32	t_FrHystHwAPts_HwDeg_f32[4];
	float32	t_FricChgWeight_Uls_f32[4];
	boolean	t_MskVehSpd_Cnt_lgc[4];
	float32	t2_BaselineTheta_HwNm_f32[8][4];
	float32	k_BmwHF_EPSDegradedFltThd_Uls_f32;
	float32	k_BmwHF_SysDegradedDivFilFrq_Hz_f32;
	float32	k_BmwTOC_OutpTqOvrlSlew_MtrNmpS_f32;
	float32	k_BmwTOC_TarSteerTqDrvrActrLPFFrq_Hz_f32;
	uint16	t_BmwTOC_TarSteerTqDrvrActrMaxY_MtrNm_u4p12[10];
	uint16	t_BmwTOC_TarSteerTqDrvrActrSpdX_Kph_u9p7[10];
	float32	k_BmwRA_DesVelLPFKn_Hz_f32;
	float32	k_BmwRA_HwAuthySlew_UlspS_f32;
	float32	k_BmwRA_HwTrqLPFKn_Hz_f32;
	float32	k_BmwRA_Kb_Uls_f32;
	float32	k_BmwRA_OffsRng_HwDeg_f32;
	float32	k_BmwRA_OffsSlew_HwDegpS_f32;
	float32	k_BmwRA_Polarity_Uls_f32;
	float32	k_BmwRA_ScaLPFKn_Hz_f32;
	float32	k_BmwRA_SelHwTrqScaTrqThr_HwNm_f32;
	float32	k_BmwRA_SelHwTrqScaVelThr_HwDegpS_f32;
	float32	t_BmwRA_DrvTrqMtrxC_Uls_f32[5];
	float32	t_BmwRA_DrvTrqMtrxD_Uls_f32[4];
	uint16	t_BmwRA_HwAuthyScaX_Uls_u2p14[4];
	uint16	t_BmwRA_HwAuthyScaY_Uls_u2p14[4];
	uint16	t_BmwRA_Ki_Uls_u8p8[8];
	uint16	t_BmwRA_Kp_Uls_u4p12[8];
	uint16	t_BmwRA_OutpLimTblY_MtrNm_u4p12[8];
	float32	t2_BmwRA_DrvTrqMtrxA_Uls_f32[5][5];
	float32	t2_BmwRA_DrvTrqMtrxB_Uls_f32[4][5];
	float32	k_CCLTrqRampDecAsstDis_Sec_f32;
	float32	k_CCLTrqRampDecAsstEn_Sec_f32;
	float32	k_CCLTrqRampInc_Sec_f32;
	float32	k_ILimitThresh1Mult_Uls_f32;
	float32	k_ILimitThresh2_Amps_f32;
	float32	k_MSARamp3AsstEn_Sec_f32;
	float32	k_VariantImax_Amps_f32;
	uint16	t_VehSpdLmtTblY_Amps_u12p4[6];
	float32	k_MtrVelDampLPFKn_Hz_f32;
	sint16	t_TempScaleX_DegC_s8p7[11];
	uint16	t_TempScaleY_Uls_u4p12[11];
	uint16	k_DampFWPstep_Cnt_u16;
	float32	k_DmpBoundLPFKn_Hz_f32;
	uint16	t_DampFWDefltDampY_MtrNm_u5p11[11];
	uint16	t_DampFWPNstepThresh_Cnt_u16[2];
	uint16	t_DampFWVehSpd_Kph_u9p7[12];
	float32	k_InrtCmp_MtrInertia_KgmSq_f32;
	float32	k_InrtCmp_TBarVelLPFKn_Hz_f32;
	uint16	t_DmpADDCoefX_MtrNm_u4p12[10];
	uint16	t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17[10];
	uint16	t_FDD_AttenTblX_MtrRadpS_u12p4[2];
	uint16	t_FDD_AttenTblY_Uls_u8p8[2];
	uint16	t_FDD_BlendTblY_Uls_u8p8[12];
	uint16	t_InrtCmp_ScaleFactorTblY_Uls_u9p7[12];
	uint16	t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7[12];
	uint16	t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17[2][10];
	uint16	t2_FDD_FreqTblYM_Hz_u12p4[2][12];
	float32	k_DDFctrRtnLim_Uls_f32;
	uint16	k_EOTDefltPosition_HwDeg_u12p4;
	uint16	k_EOTDeltaTrqThrsh_HwNm_u9p7;
	uint16	k_EOTEnterLPFKn_Cnt_u16;
	uint16	k_EOTExitLPFKn_Cnt_u16;
	uint16	k_EOTImpSpdEn_Kph_u9p7;
	uint16	k_EOTStateHwTrqLPFKn_Cnt_u16;
	uint16	k_MaxRackTrvl_HwDeg_u12p4;
	uint16	k_PosRampStep_HwDeg_u12p4;
	Boolean	k_SoftStopEOTEnable_Cnt_lgc;
	uint16	k_SpdIptScale_MtrNmpRadpS_u4p12;
	uint16	t_EOTDmpVspd_Kph_u9p7[4];
	uint16	t_EOTEnterGainVspd_Kph_u9p7[4];
	uint16	t_SpdIptTblXTbl_HwDeg_u12p4[2];
	uint16	t_SpdIptTblYTbl_MtrRadpS_u12p4[2];
	uint16	t_TrqTableX_HwNm_u8p8[2];
	uint16	t2_EOTEnterGainX_HwDeg_u12p4[4][4];
	uint16	t2_EOTEnterGainY_Uls_u1p15[4][4];
	uint16	t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16[4][2];
	uint16	t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16[4][2];
	uint16	k_MinRackTrvl_HwDeg_u12p4;
	uint16	t2_EOTPosDepDmpTblX_HwDeg_u12p4[4][2];
	sint16	t2_EOTDmpFWActiveBoundY_MtrNm_s7p8[4][5];
	float32	k_PosTrajMaxAngle_HwDeg_f32;
	uint16	k_EOTThrmPrtLPFKn_Cnt_u16;
	float32	k_EOTThrmSlwLmtStp_MtrNm_f32;
	uint16	t_EOTThrmDpntTbl_MtrNm_u8p8[4];
	uint16	t_EOTThrmIndptTbl_MtrNm_u8p8[4];
	uint16	k_HysAddHwTrqLPFKn_Cnt_u16;
	uint16	t_HysAddFallTblX_Uls_u6p10[6];
	uint16	t_HysAddFallTblY_Uls_u6p10[6];
	uint16	t_HysAddOffsetTblY_HwNm_u4p12[8];
	uint16	t_HysAddRiseTblX_Uls_u6p10[6];
	uint16	t_HysAddRiseTblY_Uls_u6p10[6];
	uint16	t_HysAddSlopeTblY_Uls_u2p14[8];
	uint16	t_HysAddVehSpdTblX_Kph_u12p4[8];
	float32	k_HysCmpHwTrqLPFKn_Hz_f32;
	float32	k_HysCmpLPAstLPFKn_Hz_f32;
	float32	k_HysFinalOutLPFKn_Hz_f32;
	float32	k_HysOutLIm_HwNm_f32;
	float32	k_HysRevGain_InvHwNm_f32;
	uint16	k_LpFricIpLim_HwNm_u9p7;
	sint16	t_HysCompCoulFricTempScaleX_DegC_s14p1[8];
	uint16	t_HysCompCoulFricTempScaleY_HwNm_u9p7[8];
	uint16	t_HysRiseTblX_HwNm_u2p14[6];
	uint16	t_HysRiseTblY_Uls_u2p14[6];
	uint16	t_HysSpdTblX_Kph_u9p7[8];
	uint16	k_LrnPnCntrKi_MtrNmpHwDegS_u4p12;
	float32	k_LrnPnCntrKp_MtrNmpMtrRad_f32;
	float32	k_LrnPnCntrMtrDamp_MtrNmpMtrRadpS_f32;
	float32	k_AuthorityStartLrn_Uls_f32;
	uint16	k_EOTLrnTimer_mS_u16;
	float32	k_HwTrqEOTLrn_HwNm_f32;
	float32	k_MaxRackTrvl_HwDeg_f32;
	float32	k_MinRackTrvl_HwDeg_f32;
	float32	k_MinResetAuthority_Uls_f32;
	float32	k_MtrVelEOTLrn_MtrRadpS_f32;
	float32	k_AccKeGn_VpRadpSpAmp_f32;
	float32	k_AccRItgGain_OhmpAmp_f32;
	float32	k_DeriScaleB_Uls_f32;
	float32	k_DeriScaleId_Uls_f32;
	uint16	k_EstPkCurr2msLPFKn_Uls_u16;
	uint16	k_EstPkCurrSlowLoopLPFKn_Uls_u16;
	float32	k_IdOffSpdGain_Sec_f32;
	uint16	k_IqErrDelay_mS_u17pm1;
	float32	k_KeIntgAntiWindup_Amp_f32;
	float32	k_KeItgGn_VpRadpSpAmp_f32;
	float32	k_MaxErrValidKe_Amp_f32;
	float32	k_MaxErrValidR_Amp_f32;
	float32	k_MaxKeRngLmt_VpRadpS_f32;
	float32	k_MaxLdRngLmt_Henry_f32;
	float32	k_MaxLqRngLmt_Henry_f32;
	float32	k_MaxRRngLmt_Ohm_f32;
	float32	k_MinKeRngLmt_VpRadpS_f32;
	float32	k_MinLdRngLmt_Henry_f32;
	float32	k_MinLqRngLmt_Henry_f32;
	float32	k_MinRRngLmt_Ohm_f32;
	float32	k_NomLd_Henry_f32;
	float32	k_RIntgAntiWindup_Amp_f32;
	float32	k_RIntgGain_OhmpAmp_f32;
	uint16	t_IdDesTcmdLvlBS_MtrNm_u5p11[6];
	sint16	t_IdDesTempGainTblX_DegC_s10p5[5];
	uint16	t_IdDesTempGainTblY_Uls_u2p14[5];
	uint16	t_KeCurrOffTblX_MtrRadpS_u12p4[2];
	sint16	t_KeCurrOffTblY_Amp_s11p4[2];
	uint16	t_KeIntgLoBndTbl_Amp_u12p4[13];
	uint16	t_KeIntgUpBndTbl_Amp_u12p4[13];
	uint16	t_KeSatTblX_Amp_u12p4[16];
	uint16	t_KeSatTblY_Uls_u2p14[16];
	uint16	t_OvrSpdDmpTblX_MtrRadpS_u12p4[3];
	uint16	t_OvrSpdDmpTblY_Volt_u8p8[3];
	uint16	t_ParamCompDaxRef_Amp_u9p7[6];
	uint16	t_ParamCompQaxRef_Amp_u9p7[7];
	uint16	t_RCurrOffTblX_MtrRadpS_u12p4[2];
	sint16	t_RCurrOffTblY_Amp_s11p4[2];
	uint16	t_RIntgLoBndTbl_Amp_u12p4[17];
	uint16	t_RIntgUpBndTbl_Amp_u12p4[17];
	uint16	t_TimeConstantTblX_Sec_u5p11[5];
	uint16	t_TimeConstantTblY_Uls_u8p8[5];
	float32	t_VdfilterCoeff_Uls_f32[3];
	float32	t_VqfilterCoeff_Uls_f32[3];
	sint16	t2_IdDesTblYM_Amp_s8p7[6][32];
	uint16	t2_ParamLdSatSclFac_Uls_u2p14[6][7];
	uint16	t2_ParamLqSatSclFac_Uls_u2p14[6][7];
	float32	k_CuAmbLPFKn_Hz_f32;
	float32	k_CuAmbMult_DegCpWatt_f32;
	float32	k_CuLLFiltKA1_Uls_f32;
	float32	k_CuLLFiltKB0_Uls_f32;
	float32	k_CuLLFiltKB1_Uls_f32;
	float32	k_MagAmbLPFKn_Hz_f32;
	float32	k_MagAmbMult_DegCpWatt_f32;
	float32	k_MagLLFiltKA1_Uls_f32;
	float32	k_MagLLFiltKB0_Uls_f32;
	float32	k_MagLLFiltKB1_Uls_f32;
	float32	k_SiAmbLPFKn_Hz_f32;
	float32	k_SiAmbMult_DegCpWatt_f32;
	float32	k_SiLLFiltKA1_Uls_f32;
	float32	k_SiLLFiltKB0_Uls_f32;
	float32	k_SiLLFiltKB1_Uls_f32;
	float32	k_TrimTempAM_DegC_f32;
	float32	k_TrimTempCu_DegC_f32;
	float32	k_TrimTempMag_DegC_f32;
	float32	k_TrimTempSi_DegC_f32;
	uint16	t_MtrVelTimeOffsetTblX_Kph_u9p7[3];
	uint16	t_MtrVelTimeOffsetYTbl_uS_u16[3];
	uint16	k_HandsOnLPFCutoff_Cnt_u16;
	uint32	k_PrkAstHandsOn2Time_mS_u32;
	uint16	k_PrkAstHandsOnTrq1_HwNm_u8p8;
	uint16	k_PrkAstHandsOnTrq2_HwNm_u8p8;
	float32	k_PrkAstHwDeltaMax_HwDeg_f32;
	uint32	k_PrkAstHwDeltaMaxTime_mS_u32;
	float32	k_PrkAstHwVelFltThrsh_HwRadpS_f32;
	uint32	k_PrkAstHwVelFltTime_mS_u32;
	float32	k_PrkAstTrgtDeltaMin_HwDeg_f32;
	float32	k_PrkAstDTermKn_Hz_f32;
	float32	k_PrkAstEnableRate_pSec_f32;
	float32	k_PrkAstHwaLPFKn_Hz_f32;
	float32	k_PrkAstHwTrqLPFKn_Hz_f32;
	uint16	k_PrkAstPIDLimit_MtrNm_u9p7;
	uint16	t_HwaRateLimit_HwDegpSec_u12p4[3];
	uint16	t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9[3];
	uint16	t_PrkAstDisableRateX_HwNm_u11p5[6];
	uint16	t_PrkAstDisableRateY_pSec_u12p4[6];
	uint16	t_PrkAstDmpGainY_MtrNmpRadpS_u3p13[3];
	uint16	t_PrkAstIGainY_MtrNmpHwDegS_u2p14[3];
	uint16	t_PrkAstPGainX_HwDeg_u12p4[7];
	uint16	t_PrkAstSmoothX_Uls_u6p10[10];
	uint16	t_PrkAstSmoothY_Uls_u6p10[10];
	uint16	t_PrkAstVehSpdBS_Kph_u9p7[3];
	float32	k_LrnPnCtrCorrLim_MtrNm_f32;
	float32	k_PrkAssistCorrLim_MtrNm_f32;
	float32	k_KeStdTemp_VpRadpS_f32;
	uint16	k_SpdAdjSlewDec_MtrRadpSpL_u12p4;
	uint16	k_SpdAdjSlewInc_MtrRadpSpL_u12p4;
	uint16	t_APAMtrEnvTblX_MtrRadpS_u12p4[6];
	uint16	t_APAMtrEnvTblY_MtrNm_u5p11[6];
	uint16	t_CustCurrentLmtTblX_Amps_u12p4[10];
	uint16	t_CustCurrentLmtTblY_MtrRadpS_u12p4[10];
	uint16	t_DLVTblX_Volts_u8p8[10];
	sint16	t_DLVTblY_MtrRadpS_s11p4[10];
	uint16	t_MSADLVTblX_Volts_u8p8[10];
	sint16	t_MSADLVTblY_MtrRadpS_s11p4[10];
	uint16	t_MtrEnvTblX_MtrRadpS_u12p4[6];
	uint16	t_MtrEnvTblY_MtrNm_u5p11[6];
	uint16	t_StdOpMtrEnvTblX_MtrRadpS_u12p4[6];
	uint16	t_StdOpMtrEnvTblY_MtrNm_u5p11[6];
	sint8	k_TrqPolGain_Uls_s8;
	uint16	t_CfactorTblX_HwDeg_u10p6[18];
	uint16	t_CfactorTblY_MmpRev_u10p6[18];
	float32	k_RtnLimit_MtrNm_f32;
	float32	k_RtnOffsetRange_HWDeg_f32;
	float32	k_RtnOffsetSlew_HwDegpS_f32;
	uint16	t_RtrnFWVehSpd_Kph_u9p7[8];
	boolean	k_StCmpCrosChkEnbl_Uls_lgc;
	float32	k_StCmpHwTrqLPFKn_Hz_f32;
	float32	k_StCmpSysCorrThresh_MtrNm_f32;
	uint16	t_StCmpADDFBlendX_Uls_u2p14[2];
	uint16	t_StCmpADDFBlendY_Uls_u2p14[2];
	uint16	t_StCmpBlend12Trq_HwNm_u8p8[5];
	uint16	t_StCmpBlend34Trq_HwNm_u8p8[5];
	uint16	t_StCmpBlendSpdBS_Kph_u9p7[6];
	NotchFiltK_Str	t_StCmpNFK_Str[4];
	uint16	t2_StCmpBlend02TblY_Uls_u2p14[6][5];
	uint16	t2_StCmpBlend04TblY_Uls_u2p14[6][5];
	uint16	t2_StCmpBlend12TblY_Uls_u2p14[6][5];
	uint16	t2_StCmpBlend34TblY_Uls_u2p14[6][5];
	boolean	k_CtrlTempSlc_Cnt_lgc;
	uint16	k_TrqCmdSlewDown_MtrNm_u9p7;
	uint16	k_TrqCmdSlewUp_MtrNm_u9p7;
	uint16	t_AbsCtrlTmpTblY_MtrNm_u9p7[4];
	uint16	t_AbsCuTmpTblY_MtrNm_u9p7[4];
	uint16	t_LastTblValNS_MtrNm_u9p7[5];
	uint16	t_LastTblValS_MtrNm_u9p7[5];
	uint16	t_Mult1NSTblY_Uls_u3p13[5];
	uint16	t_Mult1STblY_Uls_u3p13[5];
	uint16	t_Mult2NSTblY_Uls_u3p13[5];
	uint16	t_Mult2STblY_Uls_u3p13[5];
	uint16	t_Mult3NSTblY_Uls_u3p13[5];
	uint16	t_Mult3STblY_Uls_u3p13[5];
	uint16	t_Mult4NSTblY_Uls_u3p13[5];
	uint16	t_Mult4STblY_Uls_u3p13[5];
	uint16	t_Mult5NSTblY_Uls_u3p13[5];
	uint16	t_Mult5STblY_Uls_u3p13[5];
	uint16	t_Mult6NSTblY_Uls_u3p13[5];
	uint16	t_Mult6STblY_Uls_u3p13[5];
	sint16	t_MultTblX_DegC_s15p0[5];
	uint16	t_ThrmLoadLmtTblX_Uls_u16p0[8];
	uint16	t_ThrmLoadLmtTblY_MtrNm_u9p7[8];
	uint16	t_TJABoundX_MtrRadpS_u12p4[6];
	uint16	t_TJADampX_MtrRadpS_u12p4[6];
	uint16	t_TJADampY_MtrNm_u4p12[6];
	uint16	t_TJAVehSpd_Kph_u9p7[6];
	uint16	t2_TJABoundY_MtrNm_u4p12[6][6];
	uint16	t_TBICFc1LPFKn_Hz_u8p8[6];
	uint16	t_TBICFc2LPFKn_Hz_u8p8[6];
	float32	k_TrqOsc_FallRampRate_MtrNmpS_f32;
	float32	k_TrqOsc_RisngRampRate_MtrNmpS_f32;
	boolean	k_TrqOsc_UseRampRateCal_Cnt_lgc;
	uint16	t_TrqOscAmpLimit_MtrNm_u5p11[11];
	uint16	t_TrqOscFreqIn_Hz_u12p4[11];
	uint32	k_HWAPId_Cnt_u32;
	boolean	k_SWTPresentSwitch_Uls_lgc;
	uint16	k_PosMaxOfstOne_HwDeg_u12p4;
	uint16	k_PosMaxOfstTwo_HwDeg_u12p4;
	uint16	t_MaxAsstTblX_Kph_u9p7[5];
	uint16	t_MaxAsstTblY_MtrNm_u5p11[5];
	uint16	t_AsstFWDefltAssistX_HwNm_u8p8[20];
	sint16	t_AsstFWDefltAssistY_MtrNm_s4p11[20];
	uint16	t_AsstSpeed_Kph_u9p7[10];
	uint16	t_CmnVehSpd_Kph_u9p7[12];
	uint16	t_HPSAsstLimY_MtrNm_u4p12[12];
	uint16	t_HPSscaleC1Y_Uls_u4p12[12];
	uint16	t_HPSscaleC2Y_Uls_u4p12[12];
	uint16	t_HPSscaleC3Y_Uls_u4p12[12];
	uint16	t_HPSscaleC4Y_Uls_u4p12[12];
	sint16	t_RtrnFWUprBoundX_HwDeg_s11p4[11];
	sint16	t2_AsstFWUprBoundY_MtrNm_s4p11[12][11];
	sint16	t2_DampFWUprBoundY_MtrNm_s7p8[12][11];
	sint16	t2_RtrnFWUprBoundY_MtrNm_s4p11[8][11];

} TUNING_Y_Str;

/************* Tuning Structure Definition for "P" Calibrations **************/

typedef struct
{
	uint16	k_CalID_Cnt_u16;
	uint16	t_BmwHF_Inten_Uls_u16[13];
	uint16	t_BmwHF_Pat_Cnt_u16[11];
	uint16	t_BmwHF_PatActvTi_mS_u16[11];
	uint16	t_BmwHF_PatPasTi_mS_u16[11];
	uint16	t_BmwHF_PatRisngSlew_MtrNmpS_u11p5[11];
	uint16	t_BmwHF_VehSpd_Kph_u11p5[10];
	uint16	t2_BmwHF_Amp_MtrNm_u2p14[10][13];
	uint16	t2_BmwHF_Frq_Hz_u16[10][13];
	boolean	k_BmwRA_DampgEnable_Cnt_Lgc;
	boolean	k_BmwRA_DampgScaEnable_Cnt_Lgc;
	boolean	k_BmwRA_DrvTrqEnable_Cnt_Lgc;
	float32	k_BmwRA_SelHwTrqScaSlewDec_UlspS_f32;
	float32	k_BmwRA_SelHwTrqScaSlewInc_UlspS_f32;
	boolean	k_BmwRA_TrqGrdtScaEnable_Cnt_lgc;
	boolean	k_BmwRA_VelErrScaEnable_Cnt_lgc;
	uint16	t_BmwRA_BlendFactorTbl1_Uls_u2p14[8];
	uint16	t_BmwRA_BlendFactorTbl2_Uls_u2p14[8];
	uint16	t_BmwRA_PosScaX_HwDeg_u12p4[9];
	uint16	t_BmwRA_PosScaY_Uls_u2p14[9];
	uint16	t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7[5];
	uint16	t_BmwRA_VehSpdTbl_Kph_u9p7[8];
	sint16	t_BmwRA_VelErrorScaX_HwDegpS_s10p5[8];
	uint16	t_BmwRA_VelErrorScaZ_HwDeg_u12p4[7];
	uint16	t_BmwRA_VelErrVehSpdScaY_Uls_u2p14[5];
	uint16	t2_BmwRA_DampgTblX_HwDegpS_u10p6[8][9];
	uint16	t2_BmwRA_DampgTblY_HwNm_u6p10[8][9];
	uint16	t2_BmwRA_DesVelScaX_HwNm_u8p8[5][8];
	uint16	t2_BmwRA_DesVelScaY_Uls_u2p14[5][8];
	uint16	t2_BmwRA_DesVelX_HwDeg_u12p4[8][12];
	uint16	t2_BmwRA_DesVelY_HwDegpS_u10p6[8][12];
	uint16	t2_BmwRA_HwTrqSca1X_HwNm_u8p8[5][10];
	uint16	t2_BmwRA_HwTrqSca1Y_Uls_u2p14[5][10];
	uint16	t2_BmwRA_HwTrqSca2X_HwNm_u8p8[5][10];
	uint16	t2_BmwRA_HwTrqSca2Y_Uls_u2p14[5][10];
	uint16	t2_BmwRA_TBarTrqScaX_HwNm_u8p8[5][8];
	uint16	t2_BmwRA_TBarTrqScaY_Uls_u2p14[5][8];
	uint16	t2_BmwRA_TrqGrdtScaX_HwNmpS_u8p8[5][8];
	uint16	t2_BmwRA_TrqGrdtScaY_Uls_u2p14[5][8];
	uint16	t2_BmwRA_VelErrorScaY_Uls_u2p14[7][8];
	uint16	t_HwTrqDmpTblX_HwNm_u8p8[2];
	uint16	t_HwTrqDmpTblY_Uls_u1p15[2];
	uint16	t_EffLossTblY_Uls_u4p12[8];
	uint16	t_EffOffTblY_HwNm_u9p7[8];
	uint16	t_HysCompCoulFricY_HwNm_u9p7[2][8];
	uint16	t_HysCompHysSatY_HwNm_u9p7[8];
	uint16	t2_HysHwTrqBlndTblX_HwNm_u4p12[8][9];
	uint16	t2_HysHwTrqBlndTblY_Uls_u4p12[8][9];
	uint16	t_TBICHwTrq_HwNm_u4p12[13];
	uint16	t_TBICVehSpd_Kph_u12p4[4];
	uint16	t2_TBICGain_Uls_u0p16[4][13];
	uint16	k_PMAPersonality_CalID_Cnt_u16;
	uint16	t_ReturnVSpdTblBS_Kph_u9p7[6];
	sint16	t2_AsstAsstY0_MtrNm_s4p11[10][20];
	uint16	t2_AsstHwtX0_HwNm_u8p8[10][20];
	uint16	t2_MtrVelDmpTblX_MtrRadpS_u12p4[9][13];
	uint16	t2_MtrVelDmpTblY_MtrNm_u5p11[9][13];
	uint16	t2_ReturnPosTblXM_HwDeg_u12p4[6][11];
	uint16	t2_ReturnPosTblYM_MtrNm_u5p11[6][11];
	uint16	t2_ReturnSclTrqTblXM_HwNm_T_u8p8[6][7];
	uint16	t2_ReturnSclTrqTblYM_Uls_u8p8[6][7];
	uint16	t2_ReturnSclVelTblXM_HwRadpS_T_u7p9[6][4];
	uint16	t2_ReturnSclVelTblYM_Uls_u8p8[6][4];

} TUNING_P_Str;


/********************************* AbsHwPos **********************************/
extern CONST(float32, CAL_CONST) k_HwPosAuthorityStep_Uls_f32;
extern CONST(uint16, CAL_CONST) k_HwPosOutputLPFCoeffK_Cnt_u16;
extern CONST(float32, CAL_CONST) k_HwPosOutputLPFError_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_ICMAuthority_Uls_f32;
extern CONST(uint16, CAL_CONST) k_InpSignalInvalidTimer_mS_u16;
extern CONST(float32, CAL_CONST) k_KinmIntDiagMaxRackLimit_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MinVehSpdReqVldAbsPos_kph_f32;
extern CONST(float32, CAL_CONST) k_MtrToHwResConv_Uls_f32;
extern CONST(float32, CAL_CONST) k_OffCorrAuthority_Uls_f32;
extern CONST(uint16, CAL_CONST) k_OffsCorrectionTimer_mS_u16;
extern CONST(float32, CAL_CONST) k_TmpCompAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_TurnsCntrAuthority_Uls_f32;
extern CONST(uint16, CAL_CONST) t_MtrPosComplTblX_MtrNm_u4p12[6];
extern CONST(uint16, CAL_CONST) t_MtrPosComplTblY_HwDegpMtrNm_u7p9[6];

/************************ AbsHwPos, LktoLkStr, LnRkCr ************************/
extern CONST(float32, CAL_CONST) k_InvGearRatio_Uls_f32;

/******************** AbsHwPos, SrlComInput, SrlComOutput ********************/
extern CONST(sint8, CAL_CONST) k_SComTrqPosPol_Cnt_s08;

/******************************** ActivePull *********************************/
extern CONST(float32, CAL_CONST) k_PullCmp_LTIntgtrStCorrnGain_Uls_f32;
extern CONST(float32, CAL_CONST) k_PullCmp_STIntgtrStCorrnGain_Uls_f32;

/********************************** Assist ***********************************/
extern CONST(uint16, CAL_CONST) t_AsstThermSclX_Cnt_u16p0[2];
extern CONST(uint16, CAL_CONST) t_AsstThermSclY_Uls_u2p14[2];
extern CONST(sint16, CAL_CONST) t2_AsstAsstY1_MtrNm_s4p11[10][20];

/****************************** AssistFirewall *******************************/
extern CONST(float32, CAL_CONST) k_AsstFWFiltKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_AsstFWFWActiveLPF_Hz_f32;
extern CONST(float32, CAL_CONST) k_AsstFWInpLimitBaseAsst_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_AsstFWInpLimitHFA_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_AsstFWInpLimitHysComp_MtrNm_f32;
extern CONST(uint16, CAL_CONST) k_AsstFWNstep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AsstFWPstep_Cnt_u16;
extern CONST(uint16, CAL_CONST) t_AsstFWPstepNstepThresh_Cnt_u16[2];

/******************************** AvgFricLrn *********************************/
extern CONST(float32, CAL_CONST) k_AvgFricLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_BaselineEOLFric_HwNm_f32;
extern CONST(float32, CAL_CONST) k_DataPrepLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_FricOffsetLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_FrictionDiagThreshold_HwNm_f32;
extern CONST(uint32, CAL_CONST) k_FrictionDiagTimer_mS_u32;
extern CONST(float32, CAL_CONST) k_HwPosAuthMin_Uls_f32;
extern CONST(float32, CAL_CONST) k_IgnCycleFricChgLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_LearningGain_Uls_f32;
extern CONST(uint32, CAL_CONST) k_LearningThreshold_Cnt_u32;
extern CONST(uint16, CAL_CONST) k_RangeCounterLimit_Cnt_u16;
extern CONST(float32, CAL_CONST) k_SatFricChgLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_TempMax_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempMin_DegC_f32;
extern CONST(uint16, CAL_CONST) t_InvRatioX_HwDeg_u11p5[10];
extern CONST(uint16, CAL_CONST) t_InvRatioY_HwNmpMtrNm_u6p10[10];
extern CONST(uint16, CAL_CONST) t2_BaselineRangeCounter_Cnt_u16[8][3];
extern CONST(float32, CAL_CONST) t2_VehSpd_Kph_f32[4][2];

/****************************** BatteryVoltage *******************************/
extern CONST(float32, CAL_CONST) k_MaxBattVoltDiff_Volts_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VecuCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_VecuVbatCorrLim_Volts_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VswitchCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_VswitchCorrLim_Volts_f32;

/************************** BatteryVoltage, BkCpPc ***************************/
extern CONST(float32, CAL_CONST) k_MaxSwitchedVolt_Volts_f32;

/********************************** BkCpPc ***********************************/
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaExtOp_Volt_f32;
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaNonOp_Volt_f32;
extern CONST(float32, CAL_CONST) k_ChargeMinDeltaNormlOp_Volt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_ChargePumpDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_MaxDischEst_Uls_f32;
extern CONST(float32, CAL_CONST) k_MinDischEst_Uls_f32;
extern CONST(float32, CAL_CONST) k_MtrMotionThresh_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_OVERRIDESIGDIAGOpenThresh_Volts_f32;
extern CONST(float32, CAL_CONST) k_PMOSDIAGOpenThresh_Volts_f32;
extern CONST(uint16, CAL_CONST) k_PMOSTError_mS_u16;
extern CONST(float32, CAL_CONST) k_PMOSVError_Volts_f32;
extern CONST(uint16, CAL_CONST) k_PrechargeThresh_mS_u16;
extern CONST(float32, CAL_CONST) k_PwrDiscCloseThresh_Volts_f32;
extern CONST(float32, CAL_CONST) k_PwrDiscOpenThresh_Volts_f32;
extern CONST(float32, CAL_CONST) k_VbattSwitchThreshExNorm_Volt_f32;
extern CONST(float32, CAL_CONST) k_VbattSwitchThreshNonExt_Volt_f32;
extern CONST(uint16, CAL_CONST) k_VerifyPwrDiscCloseThresh_mS_u16;
extern CONST(uint16, CAL_CONST) k_VerifyPwrDiscOpenThresh_mS_u16;
extern CONST(float32, CAL_CONST) k_VswitchDeltaThresh_Volts_f32;
extern CONST(uint16, CAL_CONST) k_WaitForSqrWaveThresh_mS_u16;

/************************** BMW_UKL_MCV_EPS_TMS570 ***************************/
extern CONST(float32, CAL_CONST) k_CustSrvcHandsOnThres_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_CustSrvcHandsOnTime_mS_u16;
extern CONST(float32, CAL_CONST) k_CustSrvcHandwheelAngDelta_HwDeg_f32;
extern CONST(uint16, CAL_CONST) k_CustSrvcHandwheelAngTime_mS_u16;
extern CONST(float32, CAL_CONST) k_CustSrvcHandwheelVelThres_HwRadpS_f32;
extern CONST(uint16, CAL_CONST) k_CustSrvcHandwheelVelTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_CustSrvcOpStateWaitTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_CustSrvcPosTrajHoldTime_mS_u16;
extern CONST(float32, CAL_CONST) k_CustSrvcPosTrajThres_HwDeg_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VrefOORDiag_Cnt_str;

/*********************** BMW_UKL_MCV_EPS_TMS570, DemIf ***********************/
extern CONST(uint8, CAL_CONST) t_DtcMaskEnbl_Cnt_u08[DEM_NUMBER_OF_EVENTS];

/**************** BMW_UKL_MCV_EPS_TMS570, IoHwAbstractionUsr *****************/
extern CONST(float32, CAL_CONST) k_ADCHwTrqScaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_ADCMtrPosScaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_ADCTempSnsrOffset_Uls_f32;
extern CONST(float32, CAL_CONST) k_ADCTempSnsrScaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_ADCVbattScaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_ADCVbattSwitchScaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_ADCVrefScaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_ChrgPumpScaling_Uls_f32;
extern CONST(uint16, CAL_CONST) k_GenMaxADCWaitTime_uS_u16;
extern CONST(uint16, CAL_CONST) k_MaxADCConvTime_uS_u16;
extern CONST(float32, CAL_CONST) k_PDScaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_VrefMax_Volts_f32;
extern CONST(float32, CAL_CONST) k_VrefMin_Volts_f32;

/******************* BMW_UKL_MCV_EPS_TMS570, SrlComOutput ********************/
extern CONST(uint16, CAL_CONST) k_HwPTrvExAuth_Uls_u8p8;

/****************** BMW_UKL_MCV_EPS_TMS570, SVDiag, SVDrvr *******************/
extern CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2];

/********************** BMW_UKL_MCV_EPS_TMS570, SVDrvr ***********************/
extern CONST(float32, CAL_CONST) k_MinDiodeCondCurr_MtrNm_f32;
extern CONST(uint16, CAL_CONST) t_CommOffsetTblX_Uls_u3p13[2];
extern CONST(uint16, CAL_CONST) t_DTCompTblX_Uls_u3p13[2];
extern CONST(uint16, CAL_CONST) t_DTCompTblY_Uls_u8p8[2];

/********************************** BVDiag ***********************************/
extern CONST(uint16, CAL_CONST) k_LowDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LowDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LowNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LowNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_MSALowDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_MSALowDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_MSALowNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_MSALowNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_OvDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_OvDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_OvNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_OvNotDetect_Volts_u10p6;

/****************************** CBD_BmwRtnAbrn *******************************/
extern CONST(float32, CAL_CONST) k_Cmn_SysTrqRatio_HwNmpMtrNm_f32;
extern CONST(uint16, CAL_CONST) t2_BmwRA_IntgtrLimTblY_HwDeg_u10p6[5][9];

/******************************** CMS_Common *********************************/
extern CONST(sint8, CAL_CONST) k_CMSGotoPosPol_Cnt_s08;
extern CONST(float32, CAL_CONST) k_F00FHandsOnThres_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_NxtrSrvcHandsOnTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_NxtrSrvcPosTrajHoldTime_mS_u16;
extern CONST(float32, CAL_CONST) k_NxtrSrvcPosTrajThres_HwDeg_f32;

/******************************* CtrldDisShtdn *******************************/
extern CONST(uint16, CAL_CONST) k_CntrlDmpRampEnd_Uls_u8p8;
extern CONST(uint16, CAL_CONST) k_CtrlDmpTmrBkptOne_mS_u16;
extern CONST(uint16, CAL_CONST) k_CtrlDmpTmrBkptTwo_mS_u16;
extern CONST(float32, CAL_CONST) k_CtrlDpVelThr_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_F2Damping_MtrNmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MaxCtrlDmpLimit_MtrNm_f32;

/********************************* CtrlTemp **********************************/
extern CONST(boolean, CAL_CONST) k_CustDiagAmbLowEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_CustDiagAmbLowThresh_DegC_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_TempSensDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_TempSensHighLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSensLowLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrDefVal_DegC_f32;
extern CONST(boolean, CAL_CONST) k_TempSnsrFiltDft_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_TempSnsrLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrScaling_DegpVolt_f32;

/******************************** CustPL_BMW *********************************/
extern CONST(float32, CAL_CONST) k_AmpDecSlew_AmppS_f32;
extern CONST(float32, CAL_CONST) k_AmpIncSlew_AmppS_f32;
extern CONST(float32, CAL_CONST) k_MSARamp1Time_Sec_f32;
extern CONST(float32, CAL_CONST) k_MSARamp2Time_Sec_f32;
extern CONST(float32, CAL_CONST) k_MSARamp3AsstDis_Sec_f32;
extern CONST(float32, CAL_CONST) k_MSARamp4Time_Sec_f32;
extern CONST(float32, CAL_CONST) k_TLoopMSA_Sec_f32;
extern CONST(float32, CAL_CONST) k_tMSAClock_Sec_f32;
extern CONST(uint16, CAL_CONST) t_VehSpdLmtTblX_Kph_u9p7[6];

/********************************** Damping **********************************/
extern CONST(float32, CAL_CONST) k_HPSbaseC1_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC2_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC3_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC4_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSOutLimit_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_QDDHwTrqBckLash_HwNm_f32;
extern CONST(float32, CAL_CONST) k_QddHwTrqDampKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QDDMtrVelBckLash_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_QddMtrVelDampKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QddSfLFPKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_Quad13DmpMult_Uls_f32;
extern CONST(float32, CAL_CONST) k_Quad24DmpMult_Uls_f32;

/****************************** DampingFirewall ******************************/
extern CONST(float32, CAL_CONST) k_DampFWErrThresh_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_DampFWFWActiveLPF_Hz_f32;
extern CONST(uint16, CAL_CONST) k_DampFWInCmpNStep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DampFWInCmpPStep_Cnt_u16;
extern CONST(float32, CAL_CONST) k_DampFWInpLimitDamp_MtrNm_f32;
extern CONST(uint16, CAL_CONST) k_DampFWNstep_Cnt_u16;
extern CONST(float32, CAL_CONST) k_DampFWVBICLPF_Hz_f32;
extern CONST(uint16, CAL_CONST) t_DampFWAddDampAFWX_MtrRadpS_u11p5[8];
extern CONST(uint16, CAL_CONST) t_DampFWAddDampAFWY_MtrNm_u5p11[8];
extern CONST(uint16, CAL_CONST) t_DampFWAddDampDFWX_MtrRadpS_u11p5[8];
extern CONST(uint16, CAL_CONST) t_DampFWAddDampDFWY_MtrNm_u5p11[8];
extern CONST(uint16, CAL_CONST) t_DampFWDampInrtCmpPNThesh_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) t_DampFWDefltDampX_MtrRadpS_u11p5[11];

/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
extern CONST(float32, CAL_CONST) k_CmnSysKinRatio_MtrDegpHwDeg_f32;
extern CONST(float32, CAL_CONST) k_CmnTbarStiff_NmpDeg_f32;
extern CONST(float32, CAL_CONST) k_DmpDecelGain_Uls_f32;
extern CONST(float32, CAL_CONST) k_DmpDecelGainFSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DmpGainOffThresh_KphpS_f32;
extern CONST(float32, CAL_CONST) k_DmpGainOnThresh_KphpS_f32;
extern CONST(float32, CAL_CONST) k_InrtCmp_MtrVel_ScaleFactor_Uls_f32;
extern CONST(uint16, CAL_CONST) t_DmpDecelGainSlewX_MtrRadpS_u11p5[6];
extern CONST(uint16, CAL_CONST) t_DmpDecelGainSlewY_UlspS_u13p3[6];
extern CONST(uint16, CAL_CONST) t_DmpFiltKpWIRBlndY_Uls_u2p14[5];
extern CONST(uint16, CAL_CONST) t_RIAstWIRBlndTblY_Uls_u2p14[5];
extern CONST(uint16, CAL_CONST) t_WIRBlndTblX_MtrNm_u8p8[5];

/********************************** DiagMgr **********************************/
extern CONST(float32, CAL_CONST) k_FltRmpRate_UlspmS_f32[13];
extern CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512];
extern CONST(uint32* const, CAL_CONST) t_BlkBoxGrp_Ptr_u32[7][3];
extern CONST(NTCNumber, CAL_CONST) t_SortedNTCs_Cnt_enum[256];

/******************************** DrvDynCtrl *********************************/
extern CONST(float32, CAL_CONST) k_DDActAstSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDActDmpSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDActRtnSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDInActAstSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDInActDmpSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDInActRtnSlew_UlspS_f32;
extern CONST(uint16, CAL_CONST) t_DDFctrHwTrqX_HwNm_u8p8[9];
extern CONST(uint16, CAL_CONST) t_DDFctrMtrVelX_MtrRadpS_u12p4[9];
extern CONST(uint16, CAL_CONST) t_DDFctrVehSpdBS_Kph_u9p7[8];
extern CONST(uint16, CAL_CONST) t2_DDCFctrAstLimYM_Uls_u8p8[8][9];
extern CONST(uint16, CAL_CONST) t2_DDCFctrDmpLimYM_Uls_u8p8[8][9];

/********************************** ElecPwr **********************************/
extern CONST(float32, CAL_CONST) k_CntlrInResist_Ohm_f32;
extern CONST(float32, CAL_CONST) k_PstcPowerLoss_Watts_f32;

/****************************** EOTActuatorMng *******************************/
extern CONST(float32, CAL_CONST) k_EOTActiveRegionBypassMaxThresh_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_EOTOriginalImpactandSoftEnd_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_EOTPosDepDempFinalSlew_MtrNmpS_T_f32;

/************************** EOTActuatorMng, EtDmpFw **************************/
extern CONST(uint16, CAL_CONST) k_EOTDynConf_Uls_u8p8;

/********************************** EtDmpFw **********************************/
extern CONST(float32, CAL_CONST) k_EOTDmpFWInactiveLim_MtrNm_f32;
extern CONST(sint16, CAL_CONST) t_EOTDmpFWActiveBoundX_MtrRadpS_s11p4[5];
extern CONST(uint16, CAL_CONST) t_EOTDmpFWVehSpd_Kph_u9p7[4];

/********************************* FrTrcvPhy *********************************/
extern CONST(uint16, CAL_CONST) k_FrTxcvrBusOffTimer_ms_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_FrTxcvrERRnDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_FrTxcvrSpiDiag_Cnt_str;

/******************************** GenPosTraj *********************************/
extern CONST(float32, CAL_CONST) k_PosTrajMaxAccel_HwDegpSecSqr_f32;
extern CONST(float32, CAL_CONST) k_PosTrajMaxVelocity_HwDegpSec_f32;

/************************ HiLoadStall, ThrmDutyCycle *************************/
extern CONST(float32, CAL_CONST) k_AbsMtrVelBkt_MtrRadps_f32;

/*********************************** HwTrq ***********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_AnaRngDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_AnaT1T2ErrThreshold_Volts_u5p11;
extern CONST(uint16, CAL_CONST) k_CorrDiagFiltActiv_Volts_u5p11;
extern CONST(uint16, CAL_CONST) k_CorrDiagKn_Cnts_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_HwTorqCorrLimDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_HwTorqCorrLimThresh_HwNm_T_f32;
extern CONST(float32, CAL_CONST) k_HwTrqSclNom_VoltspDeg_f32;
extern CONST(float32, CAL_CONST) k_MaxHwTrqTrim_Volts_f32;
extern CONST(float32, CAL_CONST) k_MaxTrqSumLmt_Volts_f32;
extern CONST(uint16, CAL_CONST) k_SSDiagKn_Cnts_u16;
extern CONST(uint16, CAL_CONST) k_SSDiagLim_Volts_u5p11;
extern CONST(uint16, CAL_CONST) k_SSFiltRecLim_Volt_u5p11;
extern CONST(uint16, CAL_CONST) k_SumFiltRecLim_Volt_u5p11;
extern CONST(DiagSettings_Str, CAL_CONST) k_SysCHwTorqCorrLimDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_SysCHwTorqCorrLimThresh_HwNm_T_f32;
extern CONST(uint16, CAL_CONST) k_T1AccRecLim_Cnt_u16;
extern CONST(float32, CAL_CONST) k_T1HghRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_T1LowRange_Volts_f32;
extern CONST(uint16, CAL_CONST) k_T2AccRecLim_Cnt_u16;
extern CONST(float32, CAL_CONST) k_T2HghRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_T2LowRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_TbarStiff_NmpDeg_f32;
extern CONST(uint16, CAL_CONST) k_TdiagCorrLim_Volts_u5p11;
extern CONST(uint16, CAL_CONST) k_TdiagLim_Volts_u5p11;
extern CONST(uint16, CAL_CONST) k_TrqFltRecLim_Cnt_u16;
extern CONST(float32, CAL_CONST) k_TrqSensScaleMax_VoltspDeg_f32;
extern CONST(float32, CAL_CONST) k_TrqSensScaleMin_VoltspDeg_f32;
extern CONST(uint16, CAL_CONST) t_TDiagFiltKnTbl_Cnt_u16[17];
extern CONST(uint16, CAL_CONST) t_TDiagIndptTbl_Volts_u5p11[17];

/********************************* HystComp **********************************/
extern CONST(float32, CAL_CONST) k_MtrNmPerHwNm_Uls_f32;
extern CONST(uint16, CAL_CONST) t_HysCompCoulFricWIRBlendX_MtrNm_u8p8[6];
extern CONST(uint16, CAL_CONST) t_HysCompCoulFricWIRBlendY_Uls_u2p14[6];
extern CONST(uint16, CAL_CONST) t_HysCompNegHysBlendX_HwNm_u9p7[5];
extern CONST(uint16, CAL_CONST) t_HysCompNegHysBlendY_Uls_u2p14[5];
extern CONST(uint16, CAL_CONST) t_HysCompNegHysCompX_MtrNm_u8p8[8];
extern CONST(uint16, CAL_CONST) t_HysCompNegHysCompY_HwNm_u9p7[8];

/**************************** IoHwAbstractionUsr *****************************/
extern CONST(boolean, CAL_CONST) k_T1T2AvgFilterEnable_Uls_lgc;

/********************************* LktoLkStr *********************************/
extern CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorque_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorqueErrThresh_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorqueRateLimit_MtrNmpS_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrHwPosErrThresh_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrMaxTcmd_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrMinApplyTorque_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrMotVelStoppedThresh_MtrRadpS_f32;
extern CONST(uint32, CAL_CONST) k_LrnPnCntrTimeout_mS_u32;
extern CONST(uint32, CAL_CONST) k_LrnPnCntrTimeThresh_mS_u32;

/********************************** LmtCod ***********************************/
extern CONST(float32, CAL_CONST) k_CCLTrqRampIncSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_GainDecSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TorqueDecSlew_MtrNmpS_f32;
extern CONST(uint16, CAL_CONST) t_GainIncSlewTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_GainIncSlewTblY_UlspS_u9p7[2];
extern CONST(uint16, CAL_CONST) t_TorqueIncSlewTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_TorqueIncSlewTblY_MtrNmpS_u13p3[2];

/********************************** LnRkCr ***********************************/
extern CONST(boolean, CAL_CONST) k_AllowFirstTimeManRC_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MinRackCntrDisp_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_OutlierAdjAmt_Uls_f32;
extern CONST(uint16, CAL_CONST) k_RCLPFCoeffK_Cnt_u16;
extern CONST(float32, CAL_CONST) k_RCMtrTrq_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_RCMtrVel_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_RCPosChg_HwDeg_f32;
extern CONST(uint16, CAL_CONST) k_RCTimer_mS_u16;

/******************************** MtrCtrl_VM *********************************/
extern CONST(uint16, CAL_CONST) k_CorrAngle_Cnt_u16;
extern CONST(float32, CAL_CONST) k_CuThermCoeff_OhmpDegC_f32;
extern CONST(float32, CAL_CONST) k_InstMtrDirHyst_Deg_f32;
extern CONST(float32, CAL_CONST) k_MagThrC_VpRadpSpDegC_f32;
extern CONST(float32, CAL_CONST) k_MaxTrqCmdScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_MinTrqCmdScl_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_MtrQuadPosSel_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_NomRfet_Ohm_f32;
extern CONST(float32, CAL_CONST) k_NomTemp_DegC_f32;
extern CONST(float32, CAL_CONST) k_PhsOffCorrDelay_Sec_f32;
extern CONST(float32, CAL_CONST) k_SiThermCoeff_OhmpDegC_f32;
extern CONST(Boolean, CAL_CONST) k_TauDLPFByPass_Uls_lgc;
extern CONST(float32, CAL_CONST) k_TrmYDeadTimeScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqRateThrsh_MtrNm_f32;

/******************************** MtrCurr_VM *********************************/
extern CONST(float32, CAL_CONST) k_CurrentScale_AmpspVolt_f32;
extern CONST(float32, CAL_CONST) k_CurrGainNumerator_Volts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrFltrKn_Hz_f32;
extern CONST(sint16, CAL_CONST) k_MtrCurrPolarity_Cnt_s16;
extern CONST(float32, CAL_CONST) k_PosTrnsInvldRgn_Rev_f32;
extern CONST(sint16, CAL_CONST) t_ShcurOffCorrTblY_Volts_s2p13[7];
extern CONST(uint16, CAL_CONST) t_WidthDutySmallTblX_Cnt_u16[7];

/********************************** MtrPos ***********************************/
extern CONST(float32, CAL_CONST) k_AmpRecVarLmt_Uls_f32;
extern CONST(float32, CAL_CONST) k_CorrelationError_Rev_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPosCorrDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPosValDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_NominalOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_RTFiltEnThresh_Uls_f32;
extern CONST(uint16, CAL_CONST) k_RTOffFiltKn_Cnt_u16;
extern CONST(float32, CAL_CONST) k_RTOffsetLmt_Volts_f32;
extern CONST(float32, CAL_CONST) k_RTOffVelThr_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_RTToNomRatioVar_Uls_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_SysCMtrPosValDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_SysCValMaxError_VoltsSqrd_f32;
extern CONST(float32, CAL_CONST) k_SysCValMinError_VoltsSqrd_f32;
extern CONST(float32, CAL_CONST) k_ValMaxError_VoltsSqrd_f32;
extern CONST(float32, CAL_CONST) k_ValMinError_VoltsSqrd_f32;

/******************************** MtrTempEst *********************************/
extern CONST(float32, CAL_CONST) k_AMAmbLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_AMAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_AmbPwrMult_WtspAmpSq_f32;
extern CONST(float32, CAL_CONST) k_AmbTempScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_AMDampScl_NmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_AMDefaultTemp_DegC_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltCoefB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltCoefB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltPoleA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_AssistMechSlew_DegCpS_f32;
extern CONST(float32, CAL_CONST) k_CuCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_EngTempScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_SiCorrLmt_DegC_f32;
extern CONST(Boolean, CAL_CONST) k_WtAvgTempDFt_Cnt_lgc;

/********************************** MtrVel ***********************************/
extern CONST(float32, CAL_CONST) k_CorrMtrVelFiltKn_Hz_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_HwVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_HwVelCorrLim_HwRadpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelSampleTime_ms_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_MtrVelCorrLim_MtrRadpS_f32;
extern CONST(Boolean, CAL_CONST) k_MtrVelFiltEn_Cnt_lgc;
extern CONST(uint16, CAL_CONST) t_MtrVelBlendTblX_MtrRadpS_u12p4[2];
extern CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblX_MtrRadpS_u12p4[2];
extern CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblY_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) t_MtrVelFiltKpTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_MtrVelFiltKpYTbl_Cnt_u16[2];

/********************************** OscTraj **********************************/
extern CONST(float32, CAL_CONST) k_OscTrajMaxAmp_HwDeg_f32;
extern CONST(uint8, CAL_CONST) k_OscTrajMaxCycles_Cnt_u08;
extern CONST(float32, CAL_CONST) k_OscTrajMaxFreq_Hz_f32;
extern CONST(float32, CAL_CONST) k_OscTrajMinFreq_Hz_f32;

/****************************** ParkAstEnbl_BMW ******************************/
extern CONST(float32, CAL_CONST) k_TcHwPosAuth_Uls_f32;

/******************************** PhaseDscnt *********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_ChrgPmpHi_Cnt_str;
extern CONST(float32, CAL_CONST) k_ChrgPmpHiDetect_Volt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_ChrgPmpLow_Cnt_str;
extern CONST(float32, CAL_CONST) k_ChrgPmpLowDetect_Volt_f32;
extern CONST(float32, CAL_CONST) k_IMeasLPFfc_Hz_f32;
extern CONST(float32, CAL_CONST) k_IMeasNotNull_Amp_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_IMeasNull_Cnt_str;
extern CONST(uint8, CAL_CONST) k_IMeasNullCntsToFlt_Cnt_u08;
extern CONST(float32, CAL_CONST) k_IMeasNullDetectMtrVel_MtrRadpS_f32;
extern CONST(uint16, CAL_CONST) k_IMeasTestDur_mS_u16;
extern CONST(uint8, CAL_CONST) k_PDSuplHiCntsToFlt_Cnt_u08;
extern CONST(DiagSettings_Str, CAL_CONST) k_PDSuplHigh_Cnt_str;
extern CONST(float32, CAL_CONST) k_PDSuplHighDetect_Volt_f32;
extern CONST(uint16, CAL_CONST) k_PDSuplHiInit_mS_u16;
extern CONST(float32, CAL_CONST) k_PDTestFailCurr_Amp_f32;
extern CONST(float32, CAL_CONST) k_PDTestFltrCurrLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) k_PDTestMaxScans_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PDTestMinFail_mS_u16;
extern CONST(uint16, CAL_CONST) k_PDTestMinScans_Cnt_u16;
extern CONST(float32, CAL_CONST) k_PDTestModIdx_Uls_f32;
extern CONST(uint16, CAL_CONST) k_PhDiscOpenTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PhDiscStartTime_mS_u16;

/********************************* PosServo **********************************/
extern CONST(uint16, CAL_CONST) t_PosSrvoMaxCmdX_Kph_u9p7[4];
extern CONST(uint16, CAL_CONST) t_PosSrvoMaxCmdY_MtrNm_u5p11[4];
extern CONST(uint16, CAL_CONST) t_PrkAstITermAWLmtY_MtrNm_u9p7[3];
extern CONST(uint16, CAL_CONST) t2_PrkAstPGainY_MtrNm_u9p7[3][7];

/***************************** PrkAstMfgServCh2 ******************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_LrnPnCntrDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_PrkAssDiagRmpDone_Uls_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PrkAssistDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) t_PrkAssistDiagThresX_kph_u9p7[3];
extern CONST(uint16, CAL_CONST) t_PrkAssistDiagThresY_Uls_u16[3];

/******************************** PwrLmtFunc *********************************/
extern CONST(float32, CAL_CONST) k_AsstReducLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_FiltAsstReducTh_Uls_f32;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTh_Volts_u8p8;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTime_mS_u16p0;
extern CONST(boolean, CAL_CONST) k_SpdAdjSlewEnable_Cnt_lgc;

/********************************* RackLoad **********************************/
extern CONST(uint16, CAL_CONST) k_LumpSysInertia_Kgm2_u6p10;
extern CONST(float32, CAL_CONST) k_MechEffQ1_Uls_f32;
extern CONST(float32, CAL_CONST) k_MechEffQ2_Uls_f32;
extern CONST(float32, CAL_CONST) k_MotorEffQ1_Uls_f32;
extern CONST(float32, CAL_CONST) k_MotorEffQ2_Uls_f32;
extern CONST(uint16, CAL_CONST) k_MtrAccelLPF_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MtrNmtoHwNm_Uls_f32;
extern CONST(float32, CAL_CONST) k_MtrVelDband_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_RackDamp_NmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_RackFriction_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_RackLoadLPF_Cnt_u16;
extern CONST(float32, CAL_CONST) k_TrnsFcnFs_Hz_f32;
extern CONST(float32, CAL_CONST) k_TrnsFcnOmegaD_RadpS_f32;
extern CONST(float32, CAL_CONST) k_TrnsFcnOmegaD2_RadpS_f32;
extern CONST(float32, CAL_CONST) k_TrnsFcnOmegaN_RadpS_f32;
extern CONST(float32, CAL_CONST) k_TrnsFcnTn_Uls_f32;

/********************************** Return ***********************************/
extern CONST(float32, CAL_CONST) k_RtnHWAuthSlew_UlspS_f32;
extern CONST(uint16, CAL_CONST) t_HWAuthRetScl_X_Uls_u8p8[4];
extern CONST(uint16, CAL_CONST) t_HWAuthRetScl_Y_Uls_u9p7[4];
extern CONST(uint16, CAL_CONST) t_ReturnTempScaleSclYTbl_Uls_u8p8[14];
extern CONST(sint16, CAL_CONST) t_ReturnTempScaleXTbl_DegC_s11p4[14];

/********************************* SgnlCond **********************************/
extern CONST(float32, CAL_CONST) k_SigCon_DefaultLatAccel_MpSecSq_f32;
extern CONST(float32, CAL_CONST) k_SigCon_DefaultLonAccel_KphpS_f32;
extern CONST(float32, CAL_CONST) k_SigCon_DefaultVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_SigCon_DefaultYawRate_DegpS_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LatAccelDiffThresh_MpSecSq_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LatAccelSlewRate_MpSecSq_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LatAccFiltFrq_Hz_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LonAccelDiffThresh_KphpS_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LonAccelSlewRate_KphpSecSq_f32;
extern CONST(float32, CAL_CONST) k_SigCon_VehSpdDiffThresh_Kph_f32;
extern CONST(float32, CAL_CONST) k_SigCon_VehSpdSlewRate_KphpS_f32;
extern CONST(float32, CAL_CONST) k_SigCon_YawRateDiffThresh_DegpS_f32;
extern CONST(float32, CAL_CONST) k_VehYawRateSlew_DegpSecSq_f32;

/******************************** SrlComInput ********************************/
extern CONST(uint16, CAL_CONST) k_AclnyMassCntrLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_ConVehCntrLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtrErrmBnUHold_mS_u16;
extern CONST(uint16, CAL_CONST) k_CtrVibStwDispLostMsgThres_Cnt_u16;
extern CONST(float32, CAL_CONST) k_CustPosTrimVehSpdThres_kph_f32;
extern CONST(float32, CAL_CONST) k_CustSrvcHwTrqThres_HwNm_f32;
extern CONST(float32, CAL_CONST) k_CustSrvcVehSpdThres_kph_f32;
extern CONST(float32, CAL_CONST) k_DfltVehSpd_Kph_M_f32;
extern CONST(uint16, CAL_CONST) k_EnergDgrDrdyLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_FZZSTDLostMsgThres_Cnt_u16;
extern CONST(float32, CAL_CONST) k_GarageModeVehSpdThres_kph_f32;
extern CONST(New_Coding_94, CAL_CONST) k_MaxISpecEpsMax_Amp_u8;
extern CONST(New_Coding_94, CAL_CONST) k_MaxISpecEpsMin_Amp_u8;
extern CONST(uint16, CAL_CONST) k_MileKMLostMsgThres_Cnt_u16;
extern CONST(float32, CAL_CONST) k_OpTrqOvEPSSafetyLimit_MtrNm_f32;
extern CONST(uint16, CAL_CONST) k_RevOffsetLostMsgThres_Cnt_u16;
extern CONST(sint8, CAL_CONST) k_SComRevOffsetPol_Cnt_s08;
extern CONST(uint16, CAL_CONST) k_StartUpDTCMaskTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_StCengCntrLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_StCengDrvHold_mS_u16;
extern CONST(New_Coding_104, CAL_CONST) k_StCengDrvMax_Cnt_u8;
extern CONST(uint16, CAL_CONST) k_SteaPniOffsLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_TarQtaStMomLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_TarStMomLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_TrqOvDbnceCntrThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_TuningSelLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VehSpdLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VINLostMsgThres_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VYawVehCntrLostMsgThres_Cnt_u16;

/******************************* SrlComOutput ********************************/
extern CONST(uint16, CAL_CONST) k_GlobalPowerMgmt_Warning_mS_u16;
extern CONST(float32, CAL_CONST) k_SupplCurThres_Amp_f32;
extern CONST(uint16, CAL_CONST) k_SupplCurThresTime_mS_u16;

/*********************** SrlComOutput, LnRkCr, MtrVel ************************/
extern CONST(float32, CAL_CONST) k_GearRatio_Uls_f32;

/******************************* StabilityComp *******************************/
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpNstep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpPNThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpPstep_Cnt_u16;

/*************************** StatesandModes, StaMd ***************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_StaMdsSysCDiag_Cnt_str;

/********************************** SVDiag ***********************************/
extern CONST(uint16, CAL_CONST) k_ErrorFiltKn_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_ErrorThresh_Cnt_u32;
extern CONST(DiagSettings_Str, CAL_CONST) k_GateDriveDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_GateDrvInitDwellTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_GenGateDrvFltThrsh_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_LowResPhsReas_Cnt_str;
extern CONST(float32, CAL_CONST) k_LowResPhsReasMaxTol_Uls_f32;
extern CONST(float32, CAL_CONST) k_LowResPhsReasMinTol_Uls_f32;
extern CONST(float32, CAL_CONST) k_LRPRCommOffsetMargin_Uls_f32;
extern CONST(float32, CAL_CONST) k_LRPRMtrVelDiagEnable_MtrRadpS_T_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_OnStateDiag_Cnt_str;
extern CONST(uint32, CAL_CONST) k_PhsReasEnableThresh_Cnt_u32;
extern CONST(sint16, CAL_CONST) k_PhsReasErrorTerm_Cnt_s16;

/********************************** SVDrvr ***********************************/
extern CONST(sint16, CAL_CONST) k_ADCTrig1Offset_Cnt_s16;
extern CONST(sint16, CAL_CONST) k_ADCTrig2Offset_Cnt_s16;
extern CONST(uint16, CAL_CONST) k_DitherLPFKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PwmDeadBand_Cnt_u16;

/********************************* TcFlshPrg *********************************/
extern CONST(uint32, CAL_CONST) k_ExpectedTcPn_Cnt_u32;
extern CONST(uint16, CAL_CONST) k_TcPrgMemSize_Cnt_u16;
extern CONST(uint16, CAL_CONST) t_TcConfigWords_Cnt_u16[2];

/************************** TcFlshPrg, TurnsCounter **************************/
extern CONST(uint16, CAL_CONST) t_TcPrgMemory_Cnt_u16[8192];

/******************************* ThrmDutyCycle *******************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_AbsTempDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_AbsTmpTrqSlewLmt_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_DefaultIgnOffTime_Sec_f32;
extern CONST(uint16, CAL_CONST) k_DutyCycFltTrshld_Uls_u16p0;
extern CONST(float32, CAL_CONST) k_EOCCtrlTemp_DegC_f32;
extern CONST(boolean, CAL_CONST) k_IgnOffCntrEnb_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_IgnOffMsgWaitTime_Sec_f32;
extern CONST(boolean, CAL_CONST) k_MtrPrTempSlc_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_MultTempSlc_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_SlowFltTempSlc_Cnt_lgc;
extern CONST(sint16, CAL_CONST) t_AbsCtrlTmpTblX_DegC_s15p0[4];
extern CONST(sint16, CAL_CONST) t_AbsCuTmpTblX_DegC_s15p0[4];

/********************************** TJADamp **********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_TJADampErrAcc_Cnt_Str;
extern CONST(float32, CAL_CONST) k_TJADampRatioThresh_Uls_f32;
extern CONST(float32, CAL_CONST) k_TJADwnSlewActive_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TJADwnSlewInAct_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TJADwnSlewInVald_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TJAUpSlew_UlspS_f32;

/******************************* TMS570_uDiag ********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_FlashECCDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_MtrCtrlMaxCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MtrCtrlMinCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OneMsLoopMaxCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OneMsLoopMinCount_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_RAMECCDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_VIMParErrThrsh_Cnt_u16;

/******************************* TuningSelAuth *******************************/
extern CONST(float32, CAL_CONST) k_TunSelHwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TunSelHwTrqThresh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_TunSelVehSpdThresh_Kph_f32;

/******************************* TurnsCounter ********************************/
extern CONST(float32, CAL_CONST) k_MaxBemfDeActive_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_MinBemfActive_MtrRadpS_f32;
extern CONST(uint16, CAL_CONST) k_MinHighMtrVelHighCnt_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MinLowMtrVelLowCnt_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MinTotHighSampleCnt_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MinTotLowSampleCnt_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MtrPosToTcMechOffset_Deg_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_RTBemfErr_Cnt_str;
extern CONST(uint8, CAL_CONST) k_TcActivePNvldChks_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolCalChksmDef_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolOffsetDef_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolSin2CosGainDef_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolSinVsCosMaxDef_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TcEolSinVsCosMinDef_Cnt_u08;
extern CONST(DiagSettings_Str, CAL_CONST) k_TcMOSIErr_Cnt_str;
extern CONST(uint16, CAL_CONST) k_TcResetTimeout_mS_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_TcSCMnMxErr_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_TcSpiComDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_TcSpiDataDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_TCvsMtrPosErr_Cnt_str;
extern CONST(float32, CAL_CONST) t_TcToAcmpMax_Deg_f32[8];
extern CONST(float32, CAL_CONST) t_TcToAcmpMin_Deg_f32[8];

/********************************** VehCfg ***********************************/
extern CONST(uint8, CAL_CONST) k_NxtrVariantCalSel_Cnt_u8;

/********************************* VehPwrMd **********************************/
extern CONST(float32, CAL_CONST) k_RampDnRt_UlspmS_f32;
extern CONST(float32, CAL_CONST) k_RampUpRtLoSpd_UlspmS_f32;
extern CONST(uint16, CAL_CONST) k_VehSpdRampDwn_kph_u12p4;
extern CONST(uint16, CAL_CONST) t_AsstFWVehSpd_Kph_u9p7[12];
extern CONST(sint16, CAL_CONST) t_DampFWUprBoundX_MtrRadpS_s11p4[11];
extern CONST(sint16, CAL_CONST) t2_AsstFWUprBoundX_HwNm_s4p11[12][11];
extern CONST(uint16, CAL_CONST) t2_AsstHwtX1_HwNm_u8p8[10][20];
extern CONST(uint16, CAL_CONST) t2_AsstWIRBlendY_Uls_u2p14[10][5];
extern CONST(uint16, CAL_CONST) t2_AsstWIRBlndX_MtrNm_u5p11[10][5];

/******************************** ActivePull *********************************/
#define k_EnableHwAuthMin_Uls_f32	TunSet_Ptr_Str->k_EnableHwAuthMin_Uls_f32
#define k_EnableHwPosMax_HwDeg_f32	TunSet_Ptr_Str->k_EnableHwPosMax_HwDeg_f32
#define k_EnableHwTrqMax_HwNm_f32	TunSet_Ptr_Str->k_EnableHwTrqMax_HwNm_f32
#define k_EnableHwVelMax_DegpS_f32	TunSet_Ptr_Str->k_EnableHwVelMax_DegpS_f32
#define k_EnableLatAccMax_MpSecSq_f32	TunSet_Ptr_Str->k_EnableLatAccMax_MpSecSq_f32
#define k_EnableTime_mS_u32	TunSet_Ptr_Str->k_EnableTime_mS_u32
#define k_EnableVehSpdMax_Kph_f32	TunSet_Ptr_Str->k_EnableVehSpdMax_Kph_f32
#define k_EnableVehSpdMin_Kph_f32	TunSet_Ptr_Str->k_EnableVehSpdMin_Kph_f32
#define k_EnableVehSpdRateMax_KphpS_f32	TunSet_Ptr_Str->k_EnableVehSpdRateMax_KphpS_f32
#define k_EnableYawRateMax_DegpS_f32	TunSet_Ptr_Str->k_EnableYawRateMax_DegpS_f32
#define k_FiltDeadband_HwNm_f32	TunSet_Ptr_Str->k_FiltDeadband_HwNm_f32
#define k_HwNmToMtrNm_MtrNmpHwNm_f32	TunSet_Ptr_Str->k_HwNmToMtrNm_MtrNmpHwNm_f32
#define k_HwTrqFilt_Hz_f32	TunSet_Ptr_Str->k_HwTrqFilt_Hz_f32
#define k_LTFilt_Hz_f32	TunSet_Ptr_Str->k_LTFilt_Hz_f32
#define k_LTIntInputLimit_HwNm_f32	TunSet_Ptr_Str->k_LTIntInputLimit_HwNm_f32
#define k_LTLearnTime_Min_f32	TunSet_Ptr_Str->k_LTLearnTime_Min_f32
#define k_LTLimit_HwNm_f32	TunSet_Ptr_Str->k_LTLimit_HwNm_f32
#define k_OutputMaxRate_HwNmpS_f32	TunSet_Ptr_Str->k_OutputMaxRate_HwNmpS_f32
#define k_STFilt_Hz_f32	TunSet_Ptr_Str->k_STFilt_Hz_f32
#define k_STIntInputLimit_HwNm_f32	TunSet_Ptr_Str->k_STIntInputLimit_HwNm_f32
#define k_STLearnTimeDec_Sec_f32	TunSet_Ptr_Str->k_STLearnTimeDec_Sec_f32
#define k_STLearnTimeInc_Sec_f32	TunSet_Ptr_Str->k_STLearnTimeInc_Sec_f32
#define k_STLimit_HwNm_f32	TunSet_Ptr_Str->k_STLimit_HwNm_f32
#define k_STOppSignTime_mS_u32	TunSet_Ptr_Str->k_STOppSignTime_mS_u32
#define k_STRampTime_Sec_f32	TunSet_Ptr_Str->k_STRampTime_Sec_f32
#define k_STResetHwPos_HwDeg_f32	TunSet_Ptr_Str->k_STResetHwPos_HwDeg_f32
#define k_STResetHwTrq_HwNm_f32	TunSet_Ptr_Str->k_STResetHwTrq_HwNm_f32
#define k_STResetLatAcc_MpSecSq_f32	TunSet_Ptr_Str->k_STResetLatAcc_MpSecSq_f32
#define k_STResetYawRate_DegpS_f32	TunSet_Ptr_Str->k_STResetYawRate_DegpS_f32
#define k_TotalLimit_HwNm_f32	TunSet_Ptr_Str->k_TotalLimit_HwNm_f32
#define k_YawRateFilt_Hz_f32	TunSet_Ptr_Str->k_YawRateFilt_Hz_f32
#define t_VehSpdScaleTblX_Kph_u9p7	TunSet_Ptr_Str->t_VehSpdScaleTblX_Kph_u9p7
#define t_VehSpdScaleTblY_Uls_u2p14	TunSet_Ptr_Str->t_VehSpdScaleTblY_Uls_u2p14

/****************************** AssistFirewall *******************************/
#define k_RestoreThresh_MtrNm_f32	TunSet_Ptr_Str->k_RestoreThresh_MtrNm_f32

/******************************* AssistSumnLmt *******************************/
#define k_SnLPullCmpFwLmt_MtrNm_f32	TunSet_Ptr_Str->k_SnLPullCmpFwLmt_MtrNm_f32

/******************************** AvgFricLrn *********************************/
#define k_EOLFricDiffLimitHigh_HwNm_f32	TunSet_Ptr_Str->k_EOLFricDiffLimitHigh_HwNm_f32
#define k_EOLFricDiffLimitLow_HwNm_f32	TunSet_Ptr_Str->k_EOLFricDiffLimitLow_HwNm_f32
#define k_EOLFricDiffScalingFactor_Uls_f32	TunSet_Ptr_Str->k_EOLFricDiffScalingFactor_Uls_f32
#define k_FricOffsetLimitHigh_HwNm_f32	TunSet_Ptr_Str->k_FricOffsetLimitHigh_HwNm_f32
#define k_FricOffsetLimitLow_HwNm_f32	TunSet_Ptr_Str->k_FricOffsetLimitLow_HwNm_f32
#define k_HwVelConstLimit_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelConstLimit_HwDegpS_f32
#define k_HwVelMax_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelMax_HwDegpS_f32
#define k_HwVelMin_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelMin_HwDegpS_f32
#define k_LatAccMax_MpSecSqrd_f32	TunSet_Ptr_Str->k_LatAccMax_MpSecSqrd_f32
#define k_LatAccMin_MpSecSqrd_f32	TunSet_Ptr_Str->k_LatAccMin_MpSecSqrd_f32
#define t_BaselineFric_HwNm_f32	TunSet_Ptr_Str->t_BaselineFric_HwNm_f32
#define t_FrHystHwAPts_HwDeg_f32	TunSet_Ptr_Str->t_FrHystHwAPts_HwDeg_f32
#define t_FricChgWeight_Uls_f32	TunSet_Ptr_Str->t_FricChgWeight_Uls_f32
#define t_MskVehSpd_Cnt_lgc	TunSet_Ptr_Str->t_MskVehSpd_Cnt_lgc
#define t2_BaselineTheta_HwNm_f32	TunSet_Ptr_Str->t2_BaselineTheta_HwNm_f32

/******************************** BmwHaptcFb *********************************/
#define k_BmwHF_EPSDegradedFltThd_Uls_f32	TunSet_Ptr_Str->k_BmwHF_EPSDegradedFltThd_Uls_f32
#define k_BmwHF_SysDegradedDivFilFrq_Hz_f32	TunSet_Ptr_Str->k_BmwHF_SysDegradedDivFilFrq_Hz_f32

/******************************* BmwTqOvrlCdng *******************************/
#define k_BmwTOC_OutpTqOvrlSlew_MtrNmpS_f32	TunSet_Ptr_Str->k_BmwTOC_OutpTqOvrlSlew_MtrNmpS_f32
#define k_BmwTOC_TarSteerTqDrvrActrLPFFrq_Hz_f32	TunSet_Ptr_Str->k_BmwTOC_TarSteerTqDrvrActrLPFFrq_Hz_f32
#define t_BmwTOC_TarSteerTqDrvrActrMaxY_MtrNm_u4p12	TunSet_Ptr_Str->t_BmwTOC_TarSteerTqDrvrActrMaxY_MtrNm_u4p12
#define t_BmwTOC_TarSteerTqDrvrActrSpdX_Kph_u9p7	TunSet_Ptr_Str->t_BmwTOC_TarSteerTqDrvrActrSpdX_Kph_u9p7

/****************************** CBD_BmwRtnAbrn *******************************/
#define k_BmwRA_DesVelLPFKn_Hz_f32	TunSet_Ptr_Str->k_BmwRA_DesVelLPFKn_Hz_f32
#define k_BmwRA_HwAuthySlew_UlspS_f32	TunSet_Ptr_Str->k_BmwRA_HwAuthySlew_UlspS_f32
#define k_BmwRA_HwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_BmwRA_HwTrqLPFKn_Hz_f32
#define k_BmwRA_Kb_Uls_f32	TunSet_Ptr_Str->k_BmwRA_Kb_Uls_f32
#define k_BmwRA_OffsRng_HwDeg_f32	TunSet_Ptr_Str->k_BmwRA_OffsRng_HwDeg_f32
#define k_BmwRA_OffsSlew_HwDegpS_f32	TunSet_Ptr_Str->k_BmwRA_OffsSlew_HwDegpS_f32
#define k_BmwRA_Polarity_Uls_f32	TunSet_Ptr_Str->k_BmwRA_Polarity_Uls_f32
#define k_BmwRA_ScaLPFKn_Hz_f32	TunSet_Ptr_Str->k_BmwRA_ScaLPFKn_Hz_f32
#define k_BmwRA_SelHwTrqScaTrqThr_HwNm_f32	TunSet_Ptr_Str->k_BmwRA_SelHwTrqScaTrqThr_HwNm_f32
#define k_BmwRA_SelHwTrqScaVelThr_HwDegpS_f32	TunSet_Ptr_Str->k_BmwRA_SelHwTrqScaVelThr_HwDegpS_f32
#define t_BmwRA_DrvTrqMtrxC_Uls_f32	TunSet_Ptr_Str->t_BmwRA_DrvTrqMtrxC_Uls_f32
#define t_BmwRA_DrvTrqMtrxD_Uls_f32	TunSet_Ptr_Str->t_BmwRA_DrvTrqMtrxD_Uls_f32
#define t_BmwRA_HwAuthyScaX_Uls_u2p14	TunSet_Ptr_Str->t_BmwRA_HwAuthyScaX_Uls_u2p14
#define t_BmwRA_HwAuthyScaY_Uls_u2p14	TunSet_Ptr_Str->t_BmwRA_HwAuthyScaY_Uls_u2p14
#define t_BmwRA_Ki_Uls_u8p8	TunSet_Ptr_Str->t_BmwRA_Ki_Uls_u8p8
#define t_BmwRA_Kp_Uls_u4p12	TunSet_Ptr_Str->t_BmwRA_Kp_Uls_u4p12
#define t_BmwRA_OutpLimTblY_MtrNm_u4p12	TunSet_Ptr_Str->t_BmwRA_OutpLimTblY_MtrNm_u4p12
#define t2_BmwRA_DrvTrqMtrxA_Uls_f32	TunSet_Ptr_Str->t2_BmwRA_DrvTrqMtrxA_Uls_f32
#define t2_BmwRA_DrvTrqMtrxB_Uls_f32	TunSet_Ptr_Str->t2_BmwRA_DrvTrqMtrxB_Uls_f32

/******************************** CustPL_BMW *********************************/
#define k_CCLTrqRampDecAsstDis_Sec_f32	TunSet_Ptr_Str->k_CCLTrqRampDecAsstDis_Sec_f32
#define k_CCLTrqRampDecAsstEn_Sec_f32	TunSet_Ptr_Str->k_CCLTrqRampDecAsstEn_Sec_f32
#define k_CCLTrqRampInc_Sec_f32	TunSet_Ptr_Str->k_CCLTrqRampInc_Sec_f32
#define k_ILimitThresh1Mult_Uls_f32	TunSet_Ptr_Str->k_ILimitThresh1Mult_Uls_f32
#define k_ILimitThresh2_Amps_f32	TunSet_Ptr_Str->k_ILimitThresh2_Amps_f32
#define k_MSARamp3AsstEn_Sec_f32	TunSet_Ptr_Str->k_MSARamp3AsstEn_Sec_f32
#define k_VariantImax_Amps_f32	TunSet_Ptr_Str->k_VariantImax_Amps_f32
#define t_VehSpdLmtTblY_Amps_u12p4	TunSet_Ptr_Str->t_VehSpdLmtTblY_Amps_u12p4

/********************************** Damping **********************************/
#define k_MtrVelDampLPFKn_Hz_f32	TunSet_Ptr_Str->k_MtrVelDampLPFKn_Hz_f32
#define t_TempScaleX_DegC_s8p7	TunSet_Ptr_Str->t_TempScaleX_DegC_s8p7
#define t_TempScaleY_Uls_u4p12	TunSet_Ptr_Str->t_TempScaleY_Uls_u4p12

/****************************** DampingFirewall ******************************/
#define k_DampFWPstep_Cnt_u16	TunSet_Ptr_Str->k_DampFWPstep_Cnt_u16
#define k_DmpBoundLPFKn_Hz_f32	TunSet_Ptr_Str->k_DmpBoundLPFKn_Hz_f32
#define t_DampFWDefltDampY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWDefltDampY_MtrNm_u5p11
#define t_DampFWPNstepThresh_Cnt_u16	TunSet_Ptr_Str->t_DampFWPNstepThresh_Cnt_u16
#define t_DampFWVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_DampFWVehSpd_Kph_u9p7

/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
#define k_InrtCmp_MtrInertia_KgmSq_f32	TunSet_Ptr_Str->k_InrtCmp_MtrInertia_KgmSq_f32
#define k_InrtCmp_TBarVelLPFKn_Hz_f32	TunSet_Ptr_Str->k_InrtCmp_TBarVelLPFKn_Hz_f32
#define t_DmpADDCoefX_MtrNm_u4p12	TunSet_Ptr_Str->t_DmpADDCoefX_MtrNm_u4p12
#define t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17	TunSet_Ptr_Str->t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17
#define t_FDD_AttenTblX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_FDD_AttenTblX_MtrRadpS_u12p4
#define t_FDD_AttenTblY_Uls_u8p8	TunSet_Ptr_Str->t_FDD_AttenTblY_Uls_u8p8
#define t_FDD_BlendTblY_Uls_u8p8	TunSet_Ptr_Str->t_FDD_BlendTblY_Uls_u8p8
#define t_InrtCmp_ScaleFactorTblY_Uls_u9p7	TunSet_Ptr_Str->t_InrtCmp_ScaleFactorTblY_Uls_u9p7
#define t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7	TunSet_Ptr_Str->t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7
#define t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17	TunSet_Ptr_Str->t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17
#define t2_FDD_FreqTblYM_Hz_u12p4	TunSet_Ptr_Str->t2_FDD_FreqTblYM_Hz_u12p4

/******************************** DrvDynCtrl *********************************/
#define k_DDFctrRtnLim_Uls_f32	TunSet_Ptr_Str->k_DDFctrRtnLim_Uls_f32

/****************************** EOTActuatorMng *******************************/
#define k_EOTDefltPosition_HwDeg_u12p4	TunSet_Ptr_Str->k_EOTDefltPosition_HwDeg_u12p4
#define k_EOTDeltaTrqThrsh_HwNm_u9p7	TunSet_Ptr_Str->k_EOTDeltaTrqThrsh_HwNm_u9p7
#define k_EOTEnterLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTEnterLPFKn_Cnt_u16
#define k_EOTExitLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTExitLPFKn_Cnt_u16
#define k_EOTImpSpdEn_Kph_u9p7	TunSet_Ptr_Str->k_EOTImpSpdEn_Kph_u9p7
#define k_EOTStateHwTrqLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTStateHwTrqLPFKn_Cnt_u16
#define k_MaxRackTrvl_HwDeg_u12p4	TunSet_Ptr_Str->k_MaxRackTrvl_HwDeg_u12p4
#define k_PosRampStep_HwDeg_u12p4	TunSet_Ptr_Str->k_PosRampStep_HwDeg_u12p4
#define k_SoftStopEOTEnable_Cnt_lgc	TunSet_Ptr_Str->k_SoftStopEOTEnable_Cnt_lgc
#define k_SpdIptScale_MtrNmpRadpS_u4p12	TunSet_Ptr_Str->k_SpdIptScale_MtrNmpRadpS_u4p12
#define t_EOTDmpVspd_Kph_u9p7	TunSet_Ptr_Str->t_EOTDmpVspd_Kph_u9p7
#define t_EOTEnterGainVspd_Kph_u9p7	TunSet_Ptr_Str->t_EOTEnterGainVspd_Kph_u9p7
#define t_SpdIptTblXTbl_HwDeg_u12p4	TunSet_Ptr_Str->t_SpdIptTblXTbl_HwDeg_u12p4
#define t_SpdIptTblYTbl_MtrRadpS_u12p4	TunSet_Ptr_Str->t_SpdIptTblYTbl_MtrRadpS_u12p4
#define t_TrqTableX_HwNm_u8p8	TunSet_Ptr_Str->t_TrqTableX_HwNm_u8p8
#define t2_EOTEnterGainX_HwDeg_u12p4	TunSet_Ptr_Str->t2_EOTEnterGainX_HwDeg_u12p4
#define t2_EOTEnterGainY_Uls_u1p15	TunSet_Ptr_Str->t2_EOTEnterGainY_Uls_u1p15
#define t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16	TunSet_Ptr_Str->t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16
#define t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16	TunSet_Ptr_Str->t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16

/************************** EOTActuatorMng, EtDmpFw **************************/
#define k_MinRackTrvl_HwDeg_u12p4	TunSet_Ptr_Str->k_MinRackTrvl_HwDeg_u12p4
#define t2_EOTPosDepDmpTblX_HwDeg_u12p4	TunSet_Ptr_Str->t2_EOTPosDepDmpTblX_HwDeg_u12p4

/********************************** EtDmpFw **********************************/
#define t2_EOTDmpFWActiveBoundY_MtrNm_s7p8	TunSet_Ptr_Str->t2_EOTDmpFWActiveBoundY_MtrNm_s7p8

/******************************** GenPosTraj *********************************/
#define k_PosTrajMaxAngle_HwDeg_f32	TunSet_Ptr_Str->k_PosTrajMaxAngle_HwDeg_f32

/******************************** HiLoadStall ********************************/
#define k_EOTThrmPrtLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTThrmPrtLPFKn_Cnt_u16
#define k_EOTThrmSlwLmtStp_MtrNm_f32	TunSet_Ptr_Str->k_EOTThrmSlwLmtStp_MtrNm_f32
#define t_EOTThrmDpntTbl_MtrNm_u8p8	TunSet_Ptr_Str->t_EOTThrmDpntTbl_MtrNm_u8p8
#define t_EOTThrmIndptTbl_MtrNm_u8p8	TunSet_Ptr_Str->t_EOTThrmIndptTbl_MtrNm_u8p8

/********************************** HystAdd **********************************/
#define k_HysAddHwTrqLPFKn_Cnt_u16	TunSet_Ptr_Str->k_HysAddHwTrqLPFKn_Cnt_u16
#define t_HysAddFallTblX_Uls_u6p10	TunSet_Ptr_Str->t_HysAddFallTblX_Uls_u6p10
#define t_HysAddFallTblY_Uls_u6p10	TunSet_Ptr_Str->t_HysAddFallTblY_Uls_u6p10
#define t_HysAddOffsetTblY_HwNm_u4p12	TunSet_Ptr_Str->t_HysAddOffsetTblY_HwNm_u4p12
#define t_HysAddRiseTblX_Uls_u6p10	TunSet_Ptr_Str->t_HysAddRiseTblX_Uls_u6p10
#define t_HysAddRiseTblY_Uls_u6p10	TunSet_Ptr_Str->t_HysAddRiseTblY_Uls_u6p10
#define t_HysAddSlopeTblY_Uls_u2p14	TunSet_Ptr_Str->t_HysAddSlopeTblY_Uls_u2p14
#define t_HysAddVehSpdTblX_Kph_u12p4	TunSet_Ptr_Str->t_HysAddVehSpdTblX_Kph_u12p4

/********************************* HystComp **********************************/
#define k_HysCmpHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_HysCmpHwTrqLPFKn_Hz_f32
#define k_HysCmpLPAstLPFKn_Hz_f32	TunSet_Ptr_Str->k_HysCmpLPAstLPFKn_Hz_f32
#define k_HysFinalOutLPFKn_Hz_f32	TunSet_Ptr_Str->k_HysFinalOutLPFKn_Hz_f32
#define k_HysOutLIm_HwNm_f32	TunSet_Ptr_Str->k_HysOutLIm_HwNm_f32
#define k_HysRevGain_InvHwNm_f32	TunSet_Ptr_Str->k_HysRevGain_InvHwNm_f32
#define k_LpFricIpLim_HwNm_u9p7	TunSet_Ptr_Str->k_LpFricIpLim_HwNm_u9p7
#define t_HysCompCoulFricTempScaleX_DegC_s14p1	TunSet_Ptr_Str->t_HysCompCoulFricTempScaleX_DegC_s14p1
#define t_HysCompCoulFricTempScaleY_HwNm_u9p7	TunSet_Ptr_Str->t_HysCompCoulFricTempScaleY_HwNm_u9p7
#define t_HysRiseTblX_HwNm_u2p14	TunSet_Ptr_Str->t_HysRiseTblX_HwNm_u2p14
#define t_HysRiseTblY_Uls_u2p14	TunSet_Ptr_Str->t_HysRiseTblY_Uls_u2p14
#define t_HysSpdTblX_Kph_u9p7	TunSet_Ptr_Str->t_HysSpdTblX_Kph_u9p7

/********************************* LktoLkStr *********************************/
#define k_LrnPnCntrKi_MtrNmpHwDegS_u4p12	TunSet_Ptr_Str->k_LrnPnCntrKi_MtrNmpHwDegS_u4p12
#define k_LrnPnCntrKp_MtrNmpMtrRad_f32	TunSet_Ptr_Str->k_LrnPnCntrKp_MtrNmpMtrRad_f32
#define k_LrnPnCntrMtrDamp_MtrNmpMtrRadpS_f32	TunSet_Ptr_Str->k_LrnPnCntrMtrDamp_MtrNmpMtrRadpS_f32

/********************************** LrnEOT ***********************************/
#define k_AuthorityStartLrn_Uls_f32	TunSet_Ptr_Str->k_AuthorityStartLrn_Uls_f32
#define k_EOTLrnTimer_mS_u16	TunSet_Ptr_Str->k_EOTLrnTimer_mS_u16
#define k_HwTrqEOTLrn_HwNm_f32	TunSet_Ptr_Str->k_HwTrqEOTLrn_HwNm_f32
#define k_MaxRackTrvl_HwDeg_f32	TunSet_Ptr_Str->k_MaxRackTrvl_HwDeg_f32
#define k_MinRackTrvl_HwDeg_f32	TunSet_Ptr_Str->k_MinRackTrvl_HwDeg_f32
#define k_MinResetAuthority_Uls_f32	TunSet_Ptr_Str->k_MinResetAuthority_Uls_f32
#define k_MtrVelEOTLrn_MtrRadpS_f32	TunSet_Ptr_Str->k_MtrVelEOTLrn_MtrRadpS_f32

/******************************** MtrCtrl_VM *********************************/
#define k_AccKeGn_VpRadpSpAmp_f32	TunSet_Ptr_Str->k_AccKeGn_VpRadpSpAmp_f32
#define k_AccRItgGain_OhmpAmp_f32	TunSet_Ptr_Str->k_AccRItgGain_OhmpAmp_f32
#define k_DeriScaleB_Uls_f32	TunSet_Ptr_Str->k_DeriScaleB_Uls_f32
#define k_DeriScaleId_Uls_f32	TunSet_Ptr_Str->k_DeriScaleId_Uls_f32
#define k_EstPkCurr2msLPFKn_Uls_u16	TunSet_Ptr_Str->k_EstPkCurr2msLPFKn_Uls_u16
#define k_EstPkCurrSlowLoopLPFKn_Uls_u16	TunSet_Ptr_Str->k_EstPkCurrSlowLoopLPFKn_Uls_u16
#define k_IdOffSpdGain_Sec_f32	TunSet_Ptr_Str->k_IdOffSpdGain_Sec_f32
#define k_IqErrDelay_mS_u17pm1	TunSet_Ptr_Str->k_IqErrDelay_mS_u17pm1
#define k_KeIntgAntiWindup_Amp_f32	TunSet_Ptr_Str->k_KeIntgAntiWindup_Amp_f32
#define k_KeItgGn_VpRadpSpAmp_f32	TunSet_Ptr_Str->k_KeItgGn_VpRadpSpAmp_f32
#define k_MaxErrValidKe_Amp_f32	TunSet_Ptr_Str->k_MaxErrValidKe_Amp_f32
#define k_MaxErrValidR_Amp_f32	TunSet_Ptr_Str->k_MaxErrValidR_Amp_f32
#define k_MaxKeRngLmt_VpRadpS_f32	TunSet_Ptr_Str->k_MaxKeRngLmt_VpRadpS_f32
#define k_MaxLdRngLmt_Henry_f32	TunSet_Ptr_Str->k_MaxLdRngLmt_Henry_f32
#define k_MaxLqRngLmt_Henry_f32	TunSet_Ptr_Str->k_MaxLqRngLmt_Henry_f32
#define k_MaxRRngLmt_Ohm_f32	TunSet_Ptr_Str->k_MaxRRngLmt_Ohm_f32
#define k_MinKeRngLmt_VpRadpS_f32	TunSet_Ptr_Str->k_MinKeRngLmt_VpRadpS_f32
#define k_MinLdRngLmt_Henry_f32	TunSet_Ptr_Str->k_MinLdRngLmt_Henry_f32
#define k_MinLqRngLmt_Henry_f32	TunSet_Ptr_Str->k_MinLqRngLmt_Henry_f32
#define k_MinRRngLmt_Ohm_f32	TunSet_Ptr_Str->k_MinRRngLmt_Ohm_f32
#define k_NomLd_Henry_f32	TunSet_Ptr_Str->k_NomLd_Henry_f32
#define k_RIntgAntiWindup_Amp_f32	TunSet_Ptr_Str->k_RIntgAntiWindup_Amp_f32
#define k_RIntgGain_OhmpAmp_f32	TunSet_Ptr_Str->k_RIntgGain_OhmpAmp_f32
#define t_IdDesTcmdLvlBS_MtrNm_u5p11	TunSet_Ptr_Str->t_IdDesTcmdLvlBS_MtrNm_u5p11
#define t_IdDesTempGainTblX_DegC_s10p5	TunSet_Ptr_Str->t_IdDesTempGainTblX_DegC_s10p5
#define t_IdDesTempGainTblY_Uls_u2p14	TunSet_Ptr_Str->t_IdDesTempGainTblY_Uls_u2p14
#define t_KeCurrOffTblX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_KeCurrOffTblX_MtrRadpS_u12p4
#define t_KeCurrOffTblY_Amp_s11p4	TunSet_Ptr_Str->t_KeCurrOffTblY_Amp_s11p4
#define t_KeIntgLoBndTbl_Amp_u12p4	TunSet_Ptr_Str->t_KeIntgLoBndTbl_Amp_u12p4
#define t_KeIntgUpBndTbl_Amp_u12p4	TunSet_Ptr_Str->t_KeIntgUpBndTbl_Amp_u12p4
#define t_KeSatTblX_Amp_u12p4	TunSet_Ptr_Str->t_KeSatTblX_Amp_u12p4
#define t_KeSatTblY_Uls_u2p14	TunSet_Ptr_Str->t_KeSatTblY_Uls_u2p14
#define t_OvrSpdDmpTblX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_OvrSpdDmpTblX_MtrRadpS_u12p4
#define t_OvrSpdDmpTblY_Volt_u8p8	TunSet_Ptr_Str->t_OvrSpdDmpTblY_Volt_u8p8
#define t_ParamCompDaxRef_Amp_u9p7	TunSet_Ptr_Str->t_ParamCompDaxRef_Amp_u9p7
#define t_ParamCompQaxRef_Amp_u9p7	TunSet_Ptr_Str->t_ParamCompQaxRef_Amp_u9p7
#define t_RCurrOffTblX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_RCurrOffTblX_MtrRadpS_u12p4
#define t_RCurrOffTblY_Amp_s11p4	TunSet_Ptr_Str->t_RCurrOffTblY_Amp_s11p4
#define t_RIntgLoBndTbl_Amp_u12p4	TunSet_Ptr_Str->t_RIntgLoBndTbl_Amp_u12p4
#define t_RIntgUpBndTbl_Amp_u12p4	TunSet_Ptr_Str->t_RIntgUpBndTbl_Amp_u12p4
#define t_TimeConstantTblX_Sec_u5p11	TunSet_Ptr_Str->t_TimeConstantTblX_Sec_u5p11
#define t_TimeConstantTblY_Uls_u8p8	TunSet_Ptr_Str->t_TimeConstantTblY_Uls_u8p8
#define t_VdfilterCoeff_Uls_f32	TunSet_Ptr_Str->t_VdfilterCoeff_Uls_f32
#define t_VqfilterCoeff_Uls_f32	TunSet_Ptr_Str->t_VqfilterCoeff_Uls_f32
#define t2_IdDesTblYM_Amp_s8p7	TunSet_Ptr_Str->t2_IdDesTblYM_Amp_s8p7
#define t2_ParamLdSatSclFac_Uls_u2p14	TunSet_Ptr_Str->t2_ParamLdSatSclFac_Uls_u2p14
#define t2_ParamLqSatSclFac_Uls_u2p14	TunSet_Ptr_Str->t2_ParamLqSatSclFac_Uls_u2p14

/******************************** MtrTempEst *********************************/
#define k_CuAmbLPFKn_Hz_f32	TunSet_Ptr_Str->k_CuAmbLPFKn_Hz_f32
#define k_CuAmbMult_DegCpWatt_f32	TunSet_Ptr_Str->k_CuAmbMult_DegCpWatt_f32
#define k_CuLLFiltKA1_Uls_f32	TunSet_Ptr_Str->k_CuLLFiltKA1_Uls_f32
#define k_CuLLFiltKB0_Uls_f32	TunSet_Ptr_Str->k_CuLLFiltKB0_Uls_f32
#define k_CuLLFiltKB1_Uls_f32	TunSet_Ptr_Str->k_CuLLFiltKB1_Uls_f32
#define k_MagAmbLPFKn_Hz_f32	TunSet_Ptr_Str->k_MagAmbLPFKn_Hz_f32
#define k_MagAmbMult_DegCpWatt_f32	TunSet_Ptr_Str->k_MagAmbMult_DegCpWatt_f32
#define k_MagLLFiltKA1_Uls_f32	TunSet_Ptr_Str->k_MagLLFiltKA1_Uls_f32
#define k_MagLLFiltKB0_Uls_f32	TunSet_Ptr_Str->k_MagLLFiltKB0_Uls_f32
#define k_MagLLFiltKB1_Uls_f32	TunSet_Ptr_Str->k_MagLLFiltKB1_Uls_f32
#define k_SiAmbLPFKn_Hz_f32	TunSet_Ptr_Str->k_SiAmbLPFKn_Hz_f32
#define k_SiAmbMult_DegCpWatt_f32	TunSet_Ptr_Str->k_SiAmbMult_DegCpWatt_f32
#define k_SiLLFiltKA1_Uls_f32	TunSet_Ptr_Str->k_SiLLFiltKA1_Uls_f32
#define k_SiLLFiltKB0_Uls_f32	TunSet_Ptr_Str->k_SiLLFiltKB0_Uls_f32
#define k_SiLLFiltKB1_Uls_f32	TunSet_Ptr_Str->k_SiLLFiltKB1_Uls_f32
#define k_TrimTempAM_DegC_f32	TunSet_Ptr_Str->k_TrimTempAM_DegC_f32
#define k_TrimTempCu_DegC_f32	TunSet_Ptr_Str->k_TrimTempCu_DegC_f32
#define k_TrimTempMag_DegC_f32	TunSet_Ptr_Str->k_TrimTempMag_DegC_f32
#define k_TrimTempSi_DegC_f32	TunSet_Ptr_Str->k_TrimTempSi_DegC_f32

/********************************** MtrVel ***********************************/
#define t_MtrVelTimeOffsetTblX_Kph_u9p7	TunSet_Ptr_Str->t_MtrVelTimeOffsetTblX_Kph_u9p7
#define t_MtrVelTimeOffsetYTbl_uS_u16	TunSet_Ptr_Str->t_MtrVelTimeOffsetYTbl_uS_u16

/****************************** ParkAstEnbl_BMW ******************************/
#define k_HandsOnLPFCutoff_Cnt_u16	TunSet_Ptr_Str->k_HandsOnLPFCutoff_Cnt_u16
#define k_PrkAstHandsOn2Time_mS_u32	TunSet_Ptr_Str->k_PrkAstHandsOn2Time_mS_u32
#define k_PrkAstHandsOnTrq1_HwNm_u8p8	TunSet_Ptr_Str->k_PrkAstHandsOnTrq1_HwNm_u8p8
#define k_PrkAstHandsOnTrq2_HwNm_u8p8	TunSet_Ptr_Str->k_PrkAstHandsOnTrq2_HwNm_u8p8
#define k_PrkAstHwDeltaMax_HwDeg_f32	TunSet_Ptr_Str->k_PrkAstHwDeltaMax_HwDeg_f32
#define k_PrkAstHwDeltaMaxTime_mS_u32	TunSet_Ptr_Str->k_PrkAstHwDeltaMaxTime_mS_u32
#define k_PrkAstHwVelFltThrsh_HwRadpS_f32	TunSet_Ptr_Str->k_PrkAstHwVelFltThrsh_HwRadpS_f32
#define k_PrkAstHwVelFltTime_mS_u32	TunSet_Ptr_Str->k_PrkAstHwVelFltTime_mS_u32
#define k_PrkAstTrgtDeltaMin_HwDeg_f32	TunSet_Ptr_Str->k_PrkAstTrgtDeltaMin_HwDeg_f32

/********************************* PosServo **********************************/
#define k_PrkAstDTermKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstDTermKn_Hz_f32
#define k_PrkAstEnableRate_pSec_f32	TunSet_Ptr_Str->k_PrkAstEnableRate_pSec_f32
#define k_PrkAstHwaLPFKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstHwaLPFKn_Hz_f32
#define k_PrkAstHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstHwTrqLPFKn_Hz_f32
#define k_PrkAstPIDLimit_MtrNm_u9p7	TunSet_Ptr_Str->k_PrkAstPIDLimit_MtrNm_u9p7
#define t_HwaRateLimit_HwDegpSec_u12p4	TunSet_Ptr_Str->t_HwaRateLimit_HwDegpSec_u12p4
#define t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9	TunSet_Ptr_Str->t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9
#define t_PrkAstDisableRateX_HwNm_u11p5	TunSet_Ptr_Str->t_PrkAstDisableRateX_HwNm_u11p5
#define t_PrkAstDisableRateY_pSec_u12p4	TunSet_Ptr_Str->t_PrkAstDisableRateY_pSec_u12p4
#define t_PrkAstDmpGainY_MtrNmpRadpS_u3p13	TunSet_Ptr_Str->t_PrkAstDmpGainY_MtrNmpRadpS_u3p13
#define t_PrkAstIGainY_MtrNmpHwDegS_u2p14	TunSet_Ptr_Str->t_PrkAstIGainY_MtrNmpHwDegS_u2p14
#define t_PrkAstPGainX_HwDeg_u12p4	TunSet_Ptr_Str->t_PrkAstPGainX_HwDeg_u12p4
#define t_PrkAstSmoothX_Uls_u6p10	TunSet_Ptr_Str->t_PrkAstSmoothX_Uls_u6p10
#define t_PrkAstSmoothY_Uls_u6p10	TunSet_Ptr_Str->t_PrkAstSmoothY_Uls_u6p10
#define t_PrkAstVehSpdBS_Kph_u9p7	TunSet_Ptr_Str->t_PrkAstVehSpdBS_Kph_u9p7

/***************************** PrkAstMfgServCh2 ******************************/
#define k_LrnPnCtrCorrLim_MtrNm_f32	TunSet_Ptr_Str->k_LrnPnCtrCorrLim_MtrNm_f32
#define k_PrkAssistCorrLim_MtrNm_f32	TunSet_Ptr_Str->k_PrkAssistCorrLim_MtrNm_f32

/******************************** PwrLmtFunc *********************************/
#define k_KeStdTemp_VpRadpS_f32	TunSet_Ptr_Str->k_KeStdTemp_VpRadpS_f32
#define k_SpdAdjSlewDec_MtrRadpSpL_u12p4	TunSet_Ptr_Str->k_SpdAdjSlewDec_MtrRadpSpL_u12p4
#define k_SpdAdjSlewInc_MtrRadpSpL_u12p4	TunSet_Ptr_Str->k_SpdAdjSlewInc_MtrRadpSpL_u12p4
#define t_APAMtrEnvTblX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_APAMtrEnvTblX_MtrRadpS_u12p4
#define t_APAMtrEnvTblY_MtrNm_u5p11	TunSet_Ptr_Str->t_APAMtrEnvTblY_MtrNm_u5p11
#define t_CustCurrentLmtTblX_Amps_u12p4	TunSet_Ptr_Str->t_CustCurrentLmtTblX_Amps_u12p4
#define t_CustCurrentLmtTblY_MtrRadpS_u12p4	TunSet_Ptr_Str->t_CustCurrentLmtTblY_MtrRadpS_u12p4
#define t_DLVTblX_Volts_u8p8	TunSet_Ptr_Str->t_DLVTblX_Volts_u8p8
#define t_DLVTblY_MtrRadpS_s11p4	TunSet_Ptr_Str->t_DLVTblY_MtrRadpS_s11p4
#define t_MSADLVTblX_Volts_u8p8	TunSet_Ptr_Str->t_MSADLVTblX_Volts_u8p8
#define t_MSADLVTblY_MtrRadpS_s11p4	TunSet_Ptr_Str->t_MSADLVTblY_MtrRadpS_s11p4
#define t_MtrEnvTblX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_MtrEnvTblX_MtrRadpS_u12p4
#define t_MtrEnvTblY_MtrNm_u5p11	TunSet_Ptr_Str->t_MtrEnvTblY_MtrNm_u5p11
#define t_StdOpMtrEnvTblX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_StdOpMtrEnvTblX_MtrRadpS_u12p4
#define t_StdOpMtrEnvTblY_MtrNm_u5p11	TunSet_Ptr_Str->t_StdOpMtrEnvTblY_MtrNm_u5p11

/********************************* RackLoad **********************************/
#define k_TrqPolGain_Uls_s8	TunSet_Ptr_Str->k_TrqPolGain_Uls_s8
#define t_CfactorTblX_HwDeg_u10p6	TunSet_Ptr_Str->t_CfactorTblX_HwDeg_u10p6
#define t_CfactorTblY_MmpRev_u10p6	TunSet_Ptr_Str->t_CfactorTblY_MmpRev_u10p6

/********************************** Return ***********************************/
#define k_RtnLimit_MtrNm_f32	TunSet_Ptr_Str->k_RtnLimit_MtrNm_f32
#define k_RtnOffsetRange_HWDeg_f32	TunSet_Ptr_Str->k_RtnOffsetRange_HWDeg_f32
#define k_RtnOffsetSlew_HwDegpS_f32	TunSet_Ptr_Str->k_RtnOffsetSlew_HwDegpS_f32

/****************************** ReturnFirewall *******************************/
#define t_RtrnFWVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_RtrnFWVehSpd_Kph_u9p7

/******************************* StabilityComp *******************************/
#define k_StCmpCrosChkEnbl_Uls_lgc	TunSet_Ptr_Str->k_StCmpCrosChkEnbl_Uls_lgc
#define k_StCmpHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_StCmpHwTrqLPFKn_Hz_f32
#define k_StCmpSysCorrThresh_MtrNm_f32	TunSet_Ptr_Str->k_StCmpSysCorrThresh_MtrNm_f32
#define t_StCmpADDFBlendX_Uls_u2p14	TunSet_Ptr_Str->t_StCmpADDFBlendX_Uls_u2p14
#define t_StCmpADDFBlendY_Uls_u2p14	TunSet_Ptr_Str->t_StCmpADDFBlendY_Uls_u2p14
#define t_StCmpBlend12Trq_HwNm_u8p8	TunSet_Ptr_Str->t_StCmpBlend12Trq_HwNm_u8p8
#define t_StCmpBlend34Trq_HwNm_u8p8	TunSet_Ptr_Str->t_StCmpBlend34Trq_HwNm_u8p8
#define t_StCmpBlendSpdBS_Kph_u9p7	TunSet_Ptr_Str->t_StCmpBlendSpdBS_Kph_u9p7
#define t_StCmpNFK_Str	TunSet_Ptr_Str->t_StCmpNFK_Str
#define t2_StCmpBlend02TblY_Uls_u2p14	TunSet_Ptr_Str->t2_StCmpBlend02TblY_Uls_u2p14
#define t2_StCmpBlend04TblY_Uls_u2p14	TunSet_Ptr_Str->t2_StCmpBlend04TblY_Uls_u2p14
#define t2_StCmpBlend12TblY_Uls_u2p14	TunSet_Ptr_Str->t2_StCmpBlend12TblY_Uls_u2p14
#define t2_StCmpBlend34TblY_Uls_u2p14	TunSet_Ptr_Str->t2_StCmpBlend34TblY_Uls_u2p14

/******************************* ThrmDutyCycle *******************************/
#define k_CtrlTempSlc_Cnt_lgc	TunSet_Ptr_Str->k_CtrlTempSlc_Cnt_lgc
#define k_TrqCmdSlewDown_MtrNm_u9p7	TunSet_Ptr_Str->k_TrqCmdSlewDown_MtrNm_u9p7
#define k_TrqCmdSlewUp_MtrNm_u9p7	TunSet_Ptr_Str->k_TrqCmdSlewUp_MtrNm_u9p7
#define t_AbsCtrlTmpTblY_MtrNm_u9p7	TunSet_Ptr_Str->t_AbsCtrlTmpTblY_MtrNm_u9p7
#define t_AbsCuTmpTblY_MtrNm_u9p7	TunSet_Ptr_Str->t_AbsCuTmpTblY_MtrNm_u9p7
#define t_LastTblValNS_MtrNm_u9p7	TunSet_Ptr_Str->t_LastTblValNS_MtrNm_u9p7
#define t_LastTblValS_MtrNm_u9p7	TunSet_Ptr_Str->t_LastTblValS_MtrNm_u9p7
#define t_Mult1NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult1NSTblY_Uls_u3p13
#define t_Mult1STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult1STblY_Uls_u3p13
#define t_Mult2NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult2NSTblY_Uls_u3p13
#define t_Mult2STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult2STblY_Uls_u3p13
#define t_Mult3NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult3NSTblY_Uls_u3p13
#define t_Mult3STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult3STblY_Uls_u3p13
#define t_Mult4NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult4NSTblY_Uls_u3p13
#define t_Mult4STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult4STblY_Uls_u3p13
#define t_Mult5NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult5NSTblY_Uls_u3p13
#define t_Mult5STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult5STblY_Uls_u3p13
#define t_Mult6NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult6NSTblY_Uls_u3p13
#define t_Mult6STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult6STblY_Uls_u3p13
#define t_MultTblX_DegC_s15p0	TunSet_Ptr_Str->t_MultTblX_DegC_s15p0
#define t_ThrmLoadLmtTblX_Uls_u16p0	TunSet_Ptr_Str->t_ThrmLoadLmtTblX_Uls_u16p0
#define t_ThrmLoadLmtTblY_MtrNm_u9p7	TunSet_Ptr_Str->t_ThrmLoadLmtTblY_MtrNm_u9p7

/********************************** TJADamp **********************************/
#define t_TJABoundX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_TJABoundX_MtrRadpS_u12p4
#define t_TJADampX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_TJADampX_MtrRadpS_u12p4
#define t_TJADampY_MtrNm_u4p12	TunSet_Ptr_Str->t_TJADampY_MtrNm_u4p12
#define t_TJAVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_TJAVehSpd_Kph_u9p7
#define t2_TJABoundY_MtrNm_u4p12	TunSet_Ptr_Str->t2_TJABoundY_MtrNm_u4p12

/****************************** TrqBasedInrtCmp ******************************/
#define t_TBICFc1LPFKn_Hz_u8p8	TunSet_Ptr_Str->t_TBICFc1LPFKn_Hz_u8p8
#define t_TBICFc2LPFKn_Hz_u8p8	TunSet_Ptr_Str->t_TBICFc2LPFKn_Hz_u8p8

/********************************** TrqOsc ***********************************/
#define k_TrqOsc_FallRampRate_MtrNmpS_f32	TunSet_Ptr_Str->k_TrqOsc_FallRampRate_MtrNmpS_f32
#define k_TrqOsc_RisngRampRate_MtrNmpS_f32	TunSet_Ptr_Str->k_TrqOsc_RisngRampRate_MtrNmpS_f32
#define k_TrqOsc_UseRampRateCal_Cnt_lgc	TunSet_Ptr_Str->k_TrqOsc_UseRampRateCal_Cnt_lgc
#define t_TrqOscAmpLimit_MtrNm_u5p11	TunSet_Ptr_Str->t_TrqOscAmpLimit_MtrNm_u5p11
#define t_TrqOscFreqIn_Hz_u12p4	TunSet_Ptr_Str->t_TrqOscFreqIn_Hz_u12p4

/********************************** VehCfg ***********************************/
#define k_HWAPId_Cnt_u32	TunSet_Ptr_Str->k_HWAPId_Cnt_u32
#define k_SWTPresentSwitch_Uls_lgc	TunSet_Ptr_Str->k_SWTPresentSwitch_Uls_lgc

/********************************* VehSpdLmt *********************************/
#define k_PosMaxOfstOne_HwDeg_u12p4	TunSet_Ptr_Str->k_PosMaxOfstOne_HwDeg_u12p4
#define k_PosMaxOfstTwo_HwDeg_u12p4	TunSet_Ptr_Str->k_PosMaxOfstTwo_HwDeg_u12p4
#define t_MaxAsstTblX_Kph_u9p7	TunSet_Ptr_Str->t_MaxAsstTblX_Kph_u9p7
#define t_MaxAsstTblY_MtrNm_u5p11	TunSet_Ptr_Str->t_MaxAsstTblY_MtrNm_u5p11
#define t_AsstFWDefltAssistX_HwNm_u8p8	TunSet_Ptr_Str->t_AsstFWDefltAssistX_HwNm_u8p8
#define t_AsstFWDefltAssistY_MtrNm_s4p11	TunSet_Ptr_Str->t_AsstFWDefltAssistY_MtrNm_s4p11
#define t_AsstSpeed_Kph_u9p7	TunSet_Ptr_Str->t_AsstSpeed_Kph_u9p7
#define t_CmnVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_CmnVehSpd_Kph_u9p7
#define t_HPSAsstLimY_MtrNm_u4p12	TunSet_Ptr_Str->t_HPSAsstLimY_MtrNm_u4p12
#define t_HPSscaleC1Y_Uls_u4p12	TunSet_Ptr_Str->t_HPSscaleC1Y_Uls_u4p12
#define t_HPSscaleC2Y_Uls_u4p12	TunSet_Ptr_Str->t_HPSscaleC2Y_Uls_u4p12
#define t_HPSscaleC3Y_Uls_u4p12	TunSet_Ptr_Str->t_HPSscaleC3Y_Uls_u4p12
#define t_HPSscaleC4Y_Uls_u4p12	TunSet_Ptr_Str->t_HPSscaleC4Y_Uls_u4p12
#define t_RtrnFWUprBoundX_HwDeg_s11p4	TunSet_Ptr_Str->t_RtrnFWUprBoundX_HwDeg_s11p4
#define t2_AsstFWUprBoundY_MtrNm_s4p11	TunSet_Ptr_Str->t2_AsstFWUprBoundY_MtrNm_s4p11
#define t2_DampFWUprBoundY_MtrNm_s7p8	TunSet_Ptr_Str->t2_DampFWUprBoundY_MtrNm_s7p8
#define t2_RtrnFWUprBoundY_MtrNm_s4p11	TunSet_Ptr_Str->t2_RtrnFWUprBoundY_MtrNm_s4p11

/********************** BMW_UKL_MCV_EPS_TMS570, VehCfg ***********************/
#define k_CalID_Cnt_u16	TunPer_Ptr_Str->k_CalID_Cnt_u16

/******************************** BmwHaptcFb *********************************/
#define t_BmwHF_Inten_Uls_u16	TunPer_Ptr_Str->t_BmwHF_Inten_Uls_u16
#define t_BmwHF_Pat_Cnt_u16	TunPer_Ptr_Str->t_BmwHF_Pat_Cnt_u16
#define t_BmwHF_PatActvTi_mS_u16	TunPer_Ptr_Str->t_BmwHF_PatActvTi_mS_u16
#define t_BmwHF_PatPasTi_mS_u16	TunPer_Ptr_Str->t_BmwHF_PatPasTi_mS_u16
#define t_BmwHF_PatRisngSlew_MtrNmpS_u11p5	TunPer_Ptr_Str->t_BmwHF_PatRisngSlew_MtrNmpS_u11p5
#define t_BmwHF_VehSpd_Kph_u11p5	TunPer_Ptr_Str->t_BmwHF_VehSpd_Kph_u11p5
#define t2_BmwHF_Amp_MtrNm_u2p14	TunPer_Ptr_Str->t2_BmwHF_Amp_MtrNm_u2p14
#define t2_BmwHF_Frq_Hz_u16	TunPer_Ptr_Str->t2_BmwHF_Frq_Hz_u16

/****************************** CBD_BmwRtnAbrn *******************************/
#define k_BmwRA_DampgEnable_Cnt_Lgc	TunPer_Ptr_Str->k_BmwRA_DampgEnable_Cnt_Lgc
#define k_BmwRA_DampgScaEnable_Cnt_Lgc	TunPer_Ptr_Str->k_BmwRA_DampgScaEnable_Cnt_Lgc
#define k_BmwRA_DrvTrqEnable_Cnt_Lgc	TunPer_Ptr_Str->k_BmwRA_DrvTrqEnable_Cnt_Lgc
#define k_BmwRA_SelHwTrqScaSlewDec_UlspS_f32	TunPer_Ptr_Str->k_BmwRA_SelHwTrqScaSlewDec_UlspS_f32
#define k_BmwRA_SelHwTrqScaSlewInc_UlspS_f32	TunPer_Ptr_Str->k_BmwRA_SelHwTrqScaSlewInc_UlspS_f32
#define k_BmwRA_TrqGrdtScaEnable_Cnt_lgc	TunPer_Ptr_Str->k_BmwRA_TrqGrdtScaEnable_Cnt_lgc
#define k_BmwRA_VelErrScaEnable_Cnt_lgc	TunPer_Ptr_Str->k_BmwRA_VelErrScaEnable_Cnt_lgc
#define t_BmwRA_BlendFactorTbl1_Uls_u2p14	TunPer_Ptr_Str->t_BmwRA_BlendFactorTbl1_Uls_u2p14
#define t_BmwRA_BlendFactorTbl2_Uls_u2p14	TunPer_Ptr_Str->t_BmwRA_BlendFactorTbl2_Uls_u2p14
#define t_BmwRA_PosScaX_HwDeg_u12p4	TunPer_Ptr_Str->t_BmwRA_PosScaX_HwDeg_u12p4
#define t_BmwRA_PosScaY_Uls_u2p14	TunPer_Ptr_Str->t_BmwRA_PosScaY_Uls_u2p14
#define t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7	TunPer_Ptr_Str->t_BmwRA_ScaFacVehSpdTbl_Kph_u9p7
#define t_BmwRA_VehSpdTbl_Kph_u9p7	TunPer_Ptr_Str->t_BmwRA_VehSpdTbl_Kph_u9p7
#define t_BmwRA_VelErrorScaX_HwDegpS_s10p5	TunPer_Ptr_Str->t_BmwRA_VelErrorScaX_HwDegpS_s10p5
#define t_BmwRA_VelErrorScaZ_HwDeg_u12p4	TunPer_Ptr_Str->t_BmwRA_VelErrorScaZ_HwDeg_u12p4
#define t_BmwRA_VelErrVehSpdScaY_Uls_u2p14	TunPer_Ptr_Str->t_BmwRA_VelErrVehSpdScaY_Uls_u2p14
#define t2_BmwRA_DampgTblX_HwDegpS_u10p6	TunPer_Ptr_Str->t2_BmwRA_DampgTblX_HwDegpS_u10p6
#define t2_BmwRA_DampgTblY_HwNm_u6p10	TunPer_Ptr_Str->t2_BmwRA_DampgTblY_HwNm_u6p10
#define t2_BmwRA_DesVelScaX_HwNm_u8p8	TunPer_Ptr_Str->t2_BmwRA_DesVelScaX_HwNm_u8p8
#define t2_BmwRA_DesVelScaY_Uls_u2p14	TunPer_Ptr_Str->t2_BmwRA_DesVelScaY_Uls_u2p14
#define t2_BmwRA_DesVelX_HwDeg_u12p4	TunPer_Ptr_Str->t2_BmwRA_DesVelX_HwDeg_u12p4
#define t2_BmwRA_DesVelY_HwDegpS_u10p6	TunPer_Ptr_Str->t2_BmwRA_DesVelY_HwDegpS_u10p6
#define t2_BmwRA_HwTrqSca1X_HwNm_u8p8	TunPer_Ptr_Str->t2_BmwRA_HwTrqSca1X_HwNm_u8p8
#define t2_BmwRA_HwTrqSca1Y_Uls_u2p14	TunPer_Ptr_Str->t2_BmwRA_HwTrqSca1Y_Uls_u2p14
#define t2_BmwRA_HwTrqSca2X_HwNm_u8p8	TunPer_Ptr_Str->t2_BmwRA_HwTrqSca2X_HwNm_u8p8
#define t2_BmwRA_HwTrqSca2Y_Uls_u2p14	TunPer_Ptr_Str->t2_BmwRA_HwTrqSca2Y_Uls_u2p14
#define t2_BmwRA_TBarTrqScaX_HwNm_u8p8	TunPer_Ptr_Str->t2_BmwRA_TBarTrqScaX_HwNm_u8p8
#define t2_BmwRA_TBarTrqScaY_Uls_u2p14	TunPer_Ptr_Str->t2_BmwRA_TBarTrqScaY_Uls_u2p14
#define t2_BmwRA_TrqGrdtScaX_HwNmpS_u8p8	TunPer_Ptr_Str->t2_BmwRA_TrqGrdtScaX_HwNmpS_u8p8
#define t2_BmwRA_TrqGrdtScaY_Uls_u2p14	TunPer_Ptr_Str->t2_BmwRA_TrqGrdtScaY_Uls_u2p14
#define t2_BmwRA_VelErrorScaY_Uls_u2p14	TunPer_Ptr_Str->t2_BmwRA_VelErrorScaY_Uls_u2p14

/********************************** Damping **********************************/
#define t_HwTrqDmpTblX_HwNm_u8p8	TunPer_Ptr_Str->t_HwTrqDmpTblX_HwNm_u8p8
#define t_HwTrqDmpTblY_Uls_u1p15	TunPer_Ptr_Str->t_HwTrqDmpTblY_Uls_u1p15

/********************************* HystComp **********************************/
#define t_EffLossTblY_Uls_u4p12	TunPer_Ptr_Str->t_EffLossTblY_Uls_u4p12
#define t_EffOffTblY_HwNm_u9p7	TunPer_Ptr_Str->t_EffOffTblY_HwNm_u9p7
#define t_HysCompCoulFricY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompCoulFricY_HwNm_u9p7
#define t_HysCompHysSatY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompHysSatY_HwNm_u9p7
#define t2_HysHwTrqBlndTblX_HwNm_u4p12	TunPer_Ptr_Str->t2_HysHwTrqBlndTblX_HwNm_u4p12
#define t2_HysHwTrqBlndTblY_Uls_u4p12	TunPer_Ptr_Str->t2_HysHwTrqBlndTblY_Uls_u4p12

/****************************** TrqBasedInrtCmp ******************************/
#define t_TBICHwTrq_HwNm_u4p12	TunPer_Ptr_Str->t_TBICHwTrq_HwNm_u4p12
#define t_TBICVehSpd_Kph_u12p4	TunPer_Ptr_Str->t_TBICVehSpd_Kph_u12p4
#define t2_TBICGain_Uls_u0p16	TunPer_Ptr_Str->t2_TBICGain_Uls_u0p16

/********************************** VehCfg ***********************************/
#define k_PMAPersonality_CalID_Cnt_u16	TunPer_Ptr_Str->k_PMAPersonality_CalID_Cnt_u16
#define t_ReturnVSpdTblBS_Kph_u9p7	TunPer_Ptr_Str->t_ReturnVSpdTblBS_Kph_u9p7
#define t2_AsstAsstY0_MtrNm_s4p11	TunPer_Ptr_Str->t2_AsstAsstY0_MtrNm_s4p11
#define t2_AsstHwtX0_HwNm_u8p8	TunPer_Ptr_Str->t2_AsstHwtX0_HwNm_u8p8
#define t2_MtrVelDmpTblX_MtrRadpS_u12p4	TunPer_Ptr_Str->t2_MtrVelDmpTblX_MtrRadpS_u12p4
#define t2_MtrVelDmpTblY_MtrNm_u5p11	TunPer_Ptr_Str->t2_MtrVelDmpTblY_MtrNm_u5p11
#define t2_ReturnPosTblXM_HwDeg_u12p4	TunPer_Ptr_Str->t2_ReturnPosTblXM_HwDeg_u12p4
#define t2_ReturnPosTblYM_MtrNm_u5p11	TunPer_Ptr_Str->t2_ReturnPosTblYM_MtrNm_u5p11
#define t2_ReturnSclTrqTblXM_HwNm_T_u8p8	TunPer_Ptr_Str->t2_ReturnSclTrqTblXM_HwNm_T_u8p8
#define t2_ReturnSclTrqTblYM_Uls_u8p8	TunPer_Ptr_Str->t2_ReturnSclTrqTblYM_Uls_u8p8
#define t2_ReturnSclVelTblXM_HwRadpS_T_u7p9	TunPer_Ptr_Str->t2_ReturnSclVelTblXM_HwRadpS_T_u7p9
#define t2_ReturnSclVelTblYM_Uls_u8p8	TunPer_Ptr_Str->t2_ReturnSclVelTblYM_Uls_u8p8
#endif

/*********************** Start of Code Footer ************************/

extern P2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
extern P2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;
extern CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16];
extern CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16];

/* Manually removed the macro for the k_CalID_Cnt_u16. This was required because the tuning sets/personalities needed to be
 * looped through to find the correct offset for the tuning set and personalities. */
#ifdef k_CalID_Cnt_u16
	#undef k_CalID_Cnt_u16
#endif

#ifdef k_PMAPersonality_CalID_Cnt_u16
	#undef k_PMAPersonality_CalID_Cnt_u16
#endif

#ifdef k_HWAPId_Cnt_u32
	#undef k_HWAPId_Cnt_u32
#endif

extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer3_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer4_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunPer5_Cnt_Str;


extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet0_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet1_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet2_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet3_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet4_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet5_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet6_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet7_Cnt_Str;






















































