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
 * %derived_by:       cz7lt6 %
 * %date_modified:    Fri Jun 21 09:29:20 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 6/21/2013 9:27:05 AM *******************/
/*********************** EOTDampingFirewall - Rev 004 ************************/



extern CONST(uint16, CAL_CONST) k_MinRackTrvl_HwDeg_u12p4;
extern CONST(uint16, CAL_CONST) t2_EOTPosDepDmpTblX_HwDeg_u12p4[4][2];
extern CONST(uint16, CAL_CONST) k_EOTDynConf_Uls_u8p8;
extern CONST(sint16, CAL_CONST) t_EOTDmpFWActiveBoundX_MtrRadpS_s11p4[5];
extern CONST(sint16, CAL_CONST) t2_EOTDmpFWActiveBoundY_MtrNm_s7p8[4][5];
extern CONST(float32, CAL_CONST) k_EOTDmpFWInactiveLim_MtrNm_f32;
extern CONST(uint16, CAL_CONST) t_EOTDmpFWVehSpd_Kph_u9p7[4];
#endif


