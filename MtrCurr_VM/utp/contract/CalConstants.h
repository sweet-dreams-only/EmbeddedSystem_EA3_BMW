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
 * %derived_by:       nzx5jd %
 * %date_modified:    Mon Oct 15 17:27:51 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/***************** File Generated on 2012-10-16 10:54:20 AM ******************/
/****************************** MtrCurr - Rev 1 ******************************/


extern CONST(float32, CAL_CONST) k_MtrCurrFltrKn_Hz_f32;
extern CONST(sint16, CAL_CONST) k_MtrCurrPolarity_Cnt_s16;
extern CONST(uint16, CAL_CONST) t_WidthDutySmallTblX_Cnt_u16[7];
extern CONST(sint16, CAL_CONST) t_ShcurOffCorrTblY_Volts_s2p13[7];
extern CONST(float32, CAL_CONST) k_CurrentScale_AmpspVolt_f32;
extern CONST(float32, CAL_CONST) k_PosTrnsInvldRgn_Rev_f32;
extern CONST(float32, CAL_CONST) k_CurrGainNumerator_Volts_f32;
#endif
