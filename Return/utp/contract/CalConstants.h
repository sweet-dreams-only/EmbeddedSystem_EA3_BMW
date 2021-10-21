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
 * %version:          8 %
 * %derived_by:       qzx0t0 %
 * %date_modified:    Tue Mar 19 16:21:30 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 5/16/2012 2:30:42 PM *******************/
/****************************** Return - Rev 12 ******************************/


extern CONST(uint16, CAL_CONST) t_ReturnVSpdTblBS_Kph_u9p7[9];
extern CONST(uint16, CAL_CONST) t2_ReturnPosTblXM_HwDeg_u12p4[9][16];
extern CONST(uint16, CAL_CONST) t2_ReturnPosTblYM_MtrNm_u5p11[9][16];
extern CONST(uint16, CAL_CONST) t2_ReturnSclTrqTblXM_HwNm_T_u8p8[9][8];
extern CONST(uint16, CAL_CONST) t2_ReturnSclTrqTblYM_Uls_u8p8[9][8];
extern CONST(uint16, CAL_CONST) t2_ReturnSclVelTblXM_HwRadpS_T_u7p9[9][4];
extern CONST(uint16, CAL_CONST) t2_ReturnSclVelTblYM_Uls_u8p8[9][4];
extern CONST(float32, CAL_CONST) k_RtnOffsetSlew_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_RtnOffsetRange_HWDeg_f32;
extern CONST(sint16, CAL_CONST) t_ReturnTempScaleXTbl_DegC_s11p4[14];
extern CONST(uint16, CAL_CONST) t_ReturnTempScaleSclYTbl_Uls_u8p8[14];
extern CONST(uint16, CAL_CONST) t_HWAuthRetScl_X_Uls_u8p8[4];
extern CONST(uint16, CAL_CONST) t_HWAuthRetScl_Y_Uls_u9p7[4];
extern CONST(float32, CAL_CONST) k_RtnHWAuthSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_RtnLimit_MtrNm_f32;
#endif
