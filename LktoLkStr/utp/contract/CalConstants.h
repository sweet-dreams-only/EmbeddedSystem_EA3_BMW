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
 * %derived_by:       nzx5jd %
 * %date_modified:    Mon Jun 25 16:46:52 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 2012-06-25 4:46:32 PM ******************/
/***************************** LktoLkStr - Rev 6 *****************************/


extern CONST(float32, CAL_CONST) k_LrnPnCntrMotVelStoppedThresh_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrMinApplyTorque_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorqueRateLimit_MtrNmpS_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorqueErrThresh_MtrNm_f32;
extern CONST(uint32, CAL_CONST) k_LrnPnCntrTimeout_mS_u32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrMaxTcmd_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_InvGearRatio_Uls_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorque_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrHwPosErrThresh_HwDeg_f32;
extern CONST(uint32, CAL_CONST) k_LrnPnCntrTimeThresh_mS_u32;
extern CONST(float32, CAL_CONST) k_LrnPnCntrKp_MtrNmpMtrRad_f32;
extern CONST(uint16, CAL_CONST) k_LrnPnCntrKi_MtrNmpHwDegS_u4p12;
extern CONST(float32, CAL_CONST) k_LrnPnCntrMtrDamp_MtrNmpMtrRadpS_f32;
#endif
