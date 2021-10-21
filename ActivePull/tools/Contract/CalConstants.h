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
 * %version:          EA3#5 %
 * %derived_by:       gzkys7 %
 * %date_modified:    Thu Oct 18 17:17:59 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 8/5/2016 12:04:08 PM *******************/
/**************************** ActivePull - Rev 12 ****************************/



extern CONST(float32, CAL_CONST) k_YawRateFilt_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwTrqFilt_Hz_f32;
extern CONST(float32, CAL_CONST) k_STResetHwTrq_HwNm_f32;
extern CONST(float32, CAL_CONST) k_STResetHwPos_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_STResetYawRate_DegpS_f32;
extern CONST(float32, CAL_CONST) k_STResetLatAcc_MpSecSq_f32;
extern CONST(float32, CAL_CONST) k_EnableHwTrqMax_HwNm_f32;
extern CONST(float32, CAL_CONST) k_EnableHwPosMax_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_EnableHwAuthMin_Uls_f32;
extern CONST(float32, CAL_CONST) k_EnableHwVelMax_DegpS_f32;
extern CONST(float32, CAL_CONST) k_EnableVehSpdRateMax_KphpS_f32;
extern CONST(float32, CAL_CONST) k_EnableVehSpdMin_Kph_f32;
extern CONST(float32, CAL_CONST) k_EnableVehSpdMax_Kph_f32;
extern CONST(float32, CAL_CONST) k_EnableYawRateMax_DegpS_f32;
extern CONST(float32, CAL_CONST) k_EnableLatAccMax_MpSecSq_f32;
extern CONST(uint32, CAL_CONST) k_EnableTime_mS_u32;
extern CONST(float32, CAL_CONST) k_STLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_STLearnTimeInc_Sec_f32;
extern CONST(float32, CAL_CONST) k_STLearnTimeDec_Sec_f32;
extern CONST(uint32, CAL_CONST) k_STOppSignTime_mS_u32;
extern CONST(float32, CAL_CONST) k_STRampTime_Sec_f32;
extern CONST(float32, CAL_CONST) k_STIntInputLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_STFilt_Hz_f32;
extern CONST(float32, CAL_CONST) k_FiltDeadband_HwNm_f32;
extern CONST(float32, CAL_CONST) k_LTLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_LTLearnTime_Min_f32;
extern CONST(float32, CAL_CONST) k_LTFilt_Hz_f32;
extern CONST(float32, CAL_CONST) k_LTIntInputLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_TotalLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwNmToMtrNm_MtrNmpHwNm_f32;
extern CONST(uint16, CAL_CONST) t_VehSpdScaleTblX_Kph_u9p7[4];
extern CONST(uint16, CAL_CONST) t_VehSpdScaleTblY_Uls_u2p14[4];
extern CONST(float32, CAL_CONST) k_OutputMaxRate_HwNmpS_f32;
extern CONST(float32, CAL_CONST) k_PullCmp_LTIntgtrStCorrnGain_Uls_f32;
extern CONST(float32, CAL_CONST) k_PullCmp_STIntgtrStCorrnGain_Uls_f32;
#endif


