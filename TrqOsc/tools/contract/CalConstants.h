/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lovepreet Kaur
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 04 9:47:23 2014
 * %version:          2 %
 * %derived_by:       pznywf %
 * %date_modified:    Thu Apr 04 9:47:23 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 4/8/2016 9:48:12 AM *******************/
/************************ Torque Oscillation - Rev 4 *************************/



extern CONST(uint16, CAL_CONST) t_TrqOscFreqIn_Hz_u12p4[11];
extern CONST(uint16, CAL_CONST) t_TrqOscAmpLimit_MtrNm_u5p11[11];
extern CONST(boolean, CAL_CONST) k_TrqOsc_UseRampRateCal_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_TrqOsc_FallRampRate_MtrNmpS_f32;
extern CONST(float32, CAL_CONST) k_TrqOsc_RisngRampRate_MtrNmpS_f32;
#endif


