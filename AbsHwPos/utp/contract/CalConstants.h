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
 * Date Created:      Sun Feb 26 18:00:00 2012
 * %version:          4 %
 * %derived_by:       wz7x3j %
 * %date_modified:    Thu Aug 30 11:51:49 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 4/30/2013 4:04:55 PM *******************/
/***************************** AbsHwPos - Rev 11 *****************************/



extern CONST(uint16, CAL_CONST) t_MtrPosComplTblX_MtrNm_u4p12[6];
extern CONST(uint16, CAL_CONST) t_MtrPosComplTblY_HwDegpMtrNm_u7p9[6];
extern CONST(float32, CAL_CONST) k_MtrToHwResConv_Uls_f32;
extern CONST(float32, CAL_CONST) k_InvGearRatio_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwPosAuthorityStep_Uls_f32;
extern CONST(uint16, CAL_CONST) k_HwPosOutputLPFCoeffK_Cnt_u16;
extern CONST(float32, CAL_CONST) k_HwPosOutputLPFError_HwDeg_f32;
extern CONST(uint16, CAL_CONST) k_InpSignalInvalidTimer_mS_u16;
extern CONST(uint16, CAL_CONST) k_OffsCorrectionTimer_mS_u16;
extern CONST(float32, CAL_CONST) k_TurnsCntrAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_ICMAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_TmpCompAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_OffCorrAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_KinmIntDiagMaxRackLimit_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MinVehSpdReqVldAbsPos_kph_f32;

/******************************** SrlComInput ********************************/
extern CONST(sint8, CAL_CONST) k_SComTrqPosPol_Cnt_s08;
#endif
