/* The following is only part of the header that was required at the 
 * time this component was made. 
 */
#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "CDD_Const.h" /* Header include - KS */

extern VAR(uint32, CDD_VAR_NOINIT) CDD_EOLSrlComSvcDft_Cnt_G_b32;

/* File is part of CDD_Data.c, included it in here */
VAR(float, CDD_VAR_NOINIT) CDD_DwnldAsstGain_Uls_G_f32;

extern VAR(boolean, CDD_VAR_NOINIT) CDD_DftAsstTbl_Cnt_G_lgc;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_EOLNxtrWIRSelect_Cnt_G_u16;

#define D_TcPNArraySize_Cnt_U16 	20U

#endif /* CDD_DATA_H */
