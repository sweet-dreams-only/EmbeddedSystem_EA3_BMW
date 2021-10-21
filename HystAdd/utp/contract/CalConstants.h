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
 * %derived_by:       tzj9qy %
 * %date_modified:    Tue Nov 22 10:44:43 2011 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 11/18/2011 4:25:00 PM ******************/
/************************* Hysteresis Add - Rev 002 **************************/



/********************************** HystAdd **********************************/
extern CONST(uint16, CAL_CONST) k_HysAddHwTrqLPFKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) t_HysAddVehSpdTblX_Kph_u12p4[8];
extern CONST(uint16, CAL_CONST) t_HysAddSlopeTblY_Uls_u2p14[8];
extern CONST(uint16, CAL_CONST) t_HysAddOffsetTblY_HwNm_u4p12[8];
extern CONST(uint16, CAL_CONST) t_HysAddRiseTblX_Uls_u6p10[6];
extern CONST(uint16, CAL_CONST) t_HysAddRiseTblY_Uls_u6p10[6];
extern CONST(uint16, CAL_CONST) t_HysAddFallTblX_Uls_u6p10[6];
extern CONST(uint16, CAL_CONST) t_HysAddFallTblY_Uls_u6p10[6];
#endif
