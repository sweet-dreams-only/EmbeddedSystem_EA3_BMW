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
* %version:          7 %
* %derived_by:       cz7lt6 %
* %date_modified:    Tue Sep 17 14:28:13 2013 %
*---------------------------------------------------------------------------*/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/******************* File Generated on 4/9/2013 2:52:25 PM *******************/
/****************** Thermal Duty  Cycle Protection - Rev 10 ******************/


extern CONST(float32, CAL_CONST) k_EOCCtrlTemp_DegC_f32;
extern CONST(boolean, CAL_CONST) k_CtrlTempSlc_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_MtrPrTempSlc_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_AbsMtrVelBkt_MtrRadps_f32;
extern CONST(sint16, CAL_CONST) t_MultTblX_DegC_s15p0[5];
extern CONST(uint16, CAL_CONST) t_Mult1NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult2NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult3NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult4NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult5NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult6NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult1STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult2STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult3STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult4STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult5STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult6STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_LastTblValNS_MtrNm_u9p7[5];
extern CONST(uint16, CAL_CONST) t_LastTblValS_MtrNm_u9p7[5];
extern CONST(uint16, CAL_CONST) k_TrqCmdSlewDown_MtrNm_u9p7;
extern CONST(uint16, CAL_CONST) k_TrqCmdSlewUp_MtrNm_u9p7;
extern CONST(boolean, CAL_CONST) k_SlowFltTempSlc_Cnt_lgc;
extern CONST(sint16, CAL_CONST) t_AbsCtrlTmpTblX_DegC_s15p0[4];
extern CONST(uint16, CAL_CONST) t_AbsCtrlTmpTblY_MtrNm_u9p7[4];
extern CONST(sint16, CAL_CONST) t_AbsCuTmpTblX_DegC_s15p0[4];
extern CONST(uint16, CAL_CONST) t_AbsCuTmpTblY_MtrNm_u9p7[4];
extern CONST(float32, CAL_CONST) k_AbsTmpTrqSlewLmt_MtrNm_f32;
extern CONST(boolean, CAL_CONST) k_MultTempSlc_Cnt_lgc;
extern CONST(DiagSettings_Str, CAL_CONST) k_AbsTempDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_DutyCycFltTrshld_Uls_u16p0;
extern CONST(uint16, CAL_CONST) t_ThrmLoadLmtTblX_Uls_u16p0[8];
extern CONST(uint16, CAL_CONST) t_ThrmLoadLmtTblY_MtrNm_u9p7[8];
extern CONST(float32, CAL_CONST) k_DefaultIgnOffTime_Sec_f32;
extern CONST(boolean, CAL_CONST) k_IgnOffCntrEnb_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_IgnOffMsgWaitTime_Sec_f32;
#endif
