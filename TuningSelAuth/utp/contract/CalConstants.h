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
 * %version:          2 %
 * %derived_by:       czgng4 %
 * %date_modified:    Fri Jul 27 16:40:23 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/* Test Definitions of tuning sets for UTP testing */
P2VAR(uint16, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
P2VAR(uint16, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;

P2VAR(uint16, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[3];
P2VAR(uint16, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[3][5];

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/3/2012 12:40:00 PM *******************/
/*********************** TuningSelectAuthority - Rev 1 ***********************/


extern CONST(float32, CAL_CONST) k_TunSelHwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TunSelHwTrqThresh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_TunSelVehSpdThresh_Kph_f32;
#endif
