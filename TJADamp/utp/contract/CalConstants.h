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
 * %version:          1 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Wed Oct  2 14:35:50 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 10/3/2013 3:21:28 PM *******************/
/***************************** TJADamp - Rev   1 *****************************/


extern CONST(float32, CAL_CONST) k_TJADwnSlewInVald_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TJADwnSlewInAct_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TJADwnSlewActive_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TJAUpSlew_UlspS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_TJADampErrAcc_Cnt_Str;
extern CONST(float32, CAL_CONST) k_TJADampRatioThresh_Uls_f32;
extern CONST(uint16, CAL_CONST) t_TJADampX_MtrRadpS_u12p4[6];
extern CONST(uint16, CAL_CONST) t_TJADampY_MtrNm_u4p12[6];
extern CONST(uint16, CAL_CONST) t_TJAVehSpd_Kph_u9p7[6];
extern CONST(uint16, CAL_CONST) t_TJABoundX_MtrRadpS_u12p4[6];
extern CONST(uint16, CAL_CONST) t2_TJABoundY_MtrNm_u4p12[6][6];
#endif
