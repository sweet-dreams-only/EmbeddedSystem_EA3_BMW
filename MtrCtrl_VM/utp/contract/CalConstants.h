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
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          6 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Mon Sep  9 13:45:41 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 4/12/2013 7:39:50 PM *******************/
/*************************** MtrlCtrl_VM - Rev 13 ****************************/


extern CONST(uint16, CAL_CONST) k_EstPkCurr2msLPFKn_Uls_u16;
extern CONST(uint16, CAL_CONST) k_EstPkCurrSlowLoopLPFKn_Uls_u16;
extern CONST(float32, CAL_CONST) k_KeItgGn_VpRadpSpAmp_f32;
extern CONST(float32, CAL_CONST) k_RIntgGain_OhmpAmp_f32;
extern CONST(uint16, CAL_CONST) k_IqErrDelay_mS_u17pm1;
extern CONST(float32, CAL_CONST) k_MaxErrValidKe_Amp_f32;
extern CONST(float32, CAL_CONST) k_KeIntgAntiWindup_Amp_f32;
extern CONST(float32, CAL_CONST) k_AccKeGn_VpRadpSpAmp_f32;
extern CONST(float32, CAL_CONST) k_MaxErrValidR_Amp_f32;
extern CONST(float32, CAL_CONST) k_RIntgAntiWindup_Amp_f32;
extern CONST(float32, CAL_CONST) k_AccRItgGain_OhmpAmp_f32;
extern CONST(float32, CAL_CONST) k_MinKeRngLmt_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MaxKeRngLmt_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MinRRngLmt_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MaxRRngLmt_Ohm_f32;
extern CONST(float32, CAL_CONST) k_NomTemp_DegC_f32;
extern CONST(float32, CAL_CONST) k_MagThrC_VpRadpSpDegC_f32;
extern CONST(float32, CAL_CONST) k_NomRfet_Ohm_f32;
extern CONST(float32, CAL_CONST) k_SiThermCoeff_OhmpDegC_f32;
extern CONST(float32, CAL_CONST) k_CuThermCoeff_OhmpDegC_f32;
extern CONST(float32, CAL_CONST) k_TrqRateThrsh_MtrNm_f32;
extern CONST(uint16, CAL_CONST) t_KeIntgUpBndTbl_Amp_u12p4[13];
extern CONST(uint16, CAL_CONST) t_RCurrOffTblX_MtrRadpS_u12p4[2];
extern CONST(sint16, CAL_CONST) t_RCurrOffTblY_Amp_s11p4[2];
extern CONST(uint16, CAL_CONST) t_KeCurrOffTblX_MtrRadpS_u12p4[2];
extern CONST(sint16, CAL_CONST) t_KeCurrOffTblY_Amp_s11p4[2];
extern CONST(uint16, CAL_CONST) t_KeIntgLoBndTbl_Amp_u12p4[13];
extern CONST(uint16, CAL_CONST) t_RIntgUpBndTbl_Amp_u12p4[17];
extern CONST(uint16, CAL_CONST) t_RIntgLoBndTbl_Amp_u12p4[17];
extern CONST(uint16, CAL_CONST) t_KeSatTblX_Amp_u12p4[16];
extern CONST(uint16, CAL_CONST) t_KeSatTblY_Uls_u2p14[16];
extern CONST(float32, CAL_CONST) k_TrmYDeadTimeScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_PhsOffCorrDelay_Sec_f32;
extern CONST(float32, CAL_CONST) k_InstMtrDirHyst_Deg_f32;
extern CONST(float32, CAL_CONST) k_MinTrqCmdScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxTrqCmdScl_Uls_f32;
extern CONST(uint16, CAL_CONST) t_IdDesTcmdLvlBS_MtrNm_u5p11[6];
extern CONST(sint16, CAL_CONST) t2_IdDesTblYM_Amp_s8p7[6][32];
extern CONST(uint16, CAL_CONST) t_OvrSpdDmpTblX_MtrRadpS_u12p4[3];
extern CONST(uint16, CAL_CONST) t_OvrSpdDmpTblY_Volt_u8p8[3];
extern CONST(float32, CAL_CONST) k_NomLd_Henry_f32;
extern CONST(float32, CAL_CONST) k_MinLqRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MinLdRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MaxLqRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MaxLdRngLmt_Henry_f32;
extern CONST(uint16, CAL_CONST) t_ParamCompDaxRef_Amp_u9p7[6];
extern CONST(uint16, CAL_CONST) t_ParamCompQaxRef_Amp_u9p7[7];
extern CONST(uint16, CAL_CONST) t2_ParamLdSatSclFac_Uls_u2p14[6][7];
extern CONST(uint16, CAL_CONST) t2_ParamLqSatSclFac_Uls_u2p14[6][7];
extern CONST(Boolean, CAL_CONST) k_TauDLPFByPass_Uls_lgc;
extern CONST(float32, CAL_CONST) k_DeriScaleB_Uls_f32;
extern CONST(float32, CAL_CONST) k_DeriScaleId_Uls_f32;
extern CONST(float32, CAL_CONST) t_VqfilterCoeff_Uls_f32[3];
extern CONST(float32, CAL_CONST) t_VdfilterCoeff_Uls_f32[3];
extern CONST(uint16, CAL_CONST) t_TimeConstantTblX_Sec_u5p11[5];
extern CONST(uint16, CAL_CONST) t_TimeConstantTblY_Uls_u8p8[5];
extern CONST(sint16, CAL_CONST) t_IdDesTempGainTblX_DegC_s10p5[5];
extern CONST(uint16, CAL_CONST) t_IdDesTempGainTblY_Uls_u2p14[5];
extern CONST(float32, CAL_CONST) k_IdOffSpdGain_Sec_f32;
extern CONST(uint16, CAL_CONST) k_CorrAngle_Cnt_u16;
extern CONST(Boolean, CAL_CONST) k_MtrQuadPosSel_Cnt_lgc;
#endif
