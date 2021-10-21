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
 * %version:          5 %
 * %derived_by:       gzkys7 %
 * %date_modified:    Fri Oct 25 10:00:55 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 6/16/2015 4:55:09 PM *******************/
/********************* Average Friction Learning - Rev 9 *********************/



extern CONST(float32, CAL_CONST) t_FrHystHwAPts_HwDeg_f32[4];
extern CONST(float32, CAL_CONST) t2_VehSpd_Kph_f32[4][2];
extern CONST(boolean, CAL_CONST) t_MskVehSpd_Cnt_lgc[4];
extern CONST(float32, CAL_CONST) t_FricChgWeight_Uls_f32[4];
extern CONST(uint16, CAL_CONST) t_InvRatioX_HwDeg_u11p5[10];
extern CONST(uint16, CAL_CONST) t_InvRatioY_HwNmpMtrNm_u6p10[10];
extern CONST(float32, CAL_CONST) k_LearningGain_Uls_f32;
extern CONST(uint32, CAL_CONST) k_LearningThreshold_Cnt_u32;
extern CONST(uint16, CAL_CONST) k_RangeCounterLimit_Cnt_u16;
extern CONST(float32, CAL_CONST) k_AvgFricLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwPosAuthMin_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwVelConstLimit_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelMax_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelMin_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_LatAccMax_MpSecSqrd_f32;
extern CONST(float32, CAL_CONST) k_LatAccMin_MpSecSqrd_f32;
extern CONST(float32, CAL_CONST) k_SatFricChgLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_FricOffsetLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TempMin_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempMax_DegC_f32;
extern CONST(float32, CAL_CONST) k_DataPrepLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_IgnCycleFricChgLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_FricOffsetLimitLow_HwNm_f32;
extern CONST(float32, CAL_CONST) k_FricOffsetLimitHigh_HwNm_f32;
extern CONST(float32, CAL_CONST) t2_BaselineTheta_HwNm_f32[8][4];
extern CONST(uint16, CAL_CONST) t2_BaselineRangeCounter_Cnt_u16[8][3];
extern CONST(float32, CAL_CONST) t_BaselineFric_HwNm_f32[4];
extern CONST(float32, CAL_CONST) k_BaselineEOLFric_HwNm_f32;
extern CONST(float32, CAL_CONST) k_EOLFricDiffScalingFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_EOLFricDiffLimitHigh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_EOLFricDiffLimitLow_HwNm_f32;
extern CONST(float32, CAL_CONST) k_FrictionDiagThreshold_HwNm_f32;
extern CONST(uint32, CAL_CONST) k_FrictionDiagTimer_mS_u32;
#endif


