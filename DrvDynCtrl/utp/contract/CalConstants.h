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
 * %version:          3 %
 * %derived_by:       rz3h1n %
 * %date_modified:    Wed Sep  5 11:21:41 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 9/5/2012 11:24:41 AM *******************/
/************************ DrvDynCntrl -FDD40A-Ver006 *************************/


extern CONST(float32, CAL_CONST) k_DDActAstSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDActRtnSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDActDmpSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDInActAstSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDInActRtnSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DDInActDmpSlew_UlspS_f32;
extern CONST(uint16, CAL_CONST) t_DDFctrVehSpdBS_Kph_u9p7[8];
extern CONST(uint16, CAL_CONST) t_DDFctrHwTrqX_HwNm_u8p8[9];
extern CONST(uint16, CAL_CONST) t_DDFctrMtrVelX_MtrRadpS_u12p4[9];
extern CONST(uint16, CAL_CONST) t2_DDCFctrAstLimYM_Uls_u8p8[8][9];
extern CONST(uint16, CAL_CONST) t2_DDCFctrDmpLimYM_Uls_u8p8[8][9];
extern CONST(float32, CAL_CONST) k_DDFctrRtnLim_Uls_f32;
#endif
