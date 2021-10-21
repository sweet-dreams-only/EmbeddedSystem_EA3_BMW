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
 * %derived_by:       nzt9hv %
 * %date_modified:    Thu Oct  3 18:14:59 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 10/04/2013 2:48:11 AM *******************/
/***************************** Damping - Rev 13 ******************************/


extern CONST(uint16, CAL_CONST) t2_MtrVelDmpTblX_MtrRadpS_u12p4[16][32];
extern CONST(uint16, CAL_CONST) t2_MtrVelDmpTblY_MtrNm_u5p11[16][32];

/***************************** Cmn_t_VehSpd_Kph ******************************/
extern CONST(uint16, CAL_CONST) t_CmnVehSpd_Kph_u9p7[12];
extern CONST(float32, CAL_CONST) k_MtrVelDampLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) t_HwTrqDmpTblX_HwNm_u8p8[2];
extern CONST(uint16, CAL_CONST) t_HwTrqDmpTblY_Uls_u1p15[2];
extern CONST(sint16, CAL_CONST) t_TempScaleX_DegC_s8p7[11];
extern CONST(uint16, CAL_CONST) t_TempScaleY_Uls_u4p12[11];
extern CONST(uint16, CAL_CONST) t_HPSscaleC1Y_Uls_u4p12[12];
extern CONST(uint16, CAL_CONST) t_HPSscaleC2Y_Uls_u4p12[12];
extern CONST(uint16, CAL_CONST) t_HPSscaleC3Y_Uls_u4p12[12];
extern CONST(uint16, CAL_CONST) t_HPSscaleC4Y_Uls_u4p12[12];
extern CONST(uint16, CAL_CONST) t_HPSAsstLimY_MtrNm_u4p12[12];
extern CONST(float32, CAL_CONST) k_HPSOutLimit_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_Quad13DmpMult_Uls_f32;
extern CONST(float32, CAL_CONST) k_Quad24DmpMult_Uls_f32;
extern CONST(float32, CAL_CONST) k_QddHwTrqDampKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QddMtrVelDampKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QDDHwTrqBckLash_HwNm_f32;
extern CONST(float32, CAL_CONST) k_QDDMtrVelBckLash_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_QddSfLFPKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC1_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC2_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC3_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC4_MtrNmpMtrRadpS_f32;
#endif
