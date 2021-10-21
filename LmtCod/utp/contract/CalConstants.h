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
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri May  9 16:48:22 2003
* %version:          4 %
* %derived_by:       nzt9hv %
* %date_modified:    Wed Jul 10 11:32:51 2013 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/10/2013 10:46:03 AM *******************/
/********************** Limiter Conditioning - Rev 005 ***********************/


extern CONST(float32, CAL_CONST) k_GainDecSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TorqueDecSlew_MtrNmpS_f32;
extern CONST(uint16, CAL_CONST) t_GainIncSlewTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_GainIncSlewTblY_UlspS_u9p7[2];
extern CONST(uint16, CAL_CONST) t_TorqueIncSlewTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_TorqueIncSlewTblY_MtrNmpS_u13p3[2];
extern CONST(float32, CAL_CONST) k_CCLTrqRampIncSlew_UlspS_f32;
#endif
