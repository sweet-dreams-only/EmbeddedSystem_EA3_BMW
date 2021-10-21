/*****************************************************************************
* Copyright 2012 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : PwmCdd_Cfg.h
* Module Description: Pwm Complex Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          1 %
* %derived_by:       nzt9hv %
* %date_modified:    Thu Feb 14 16:00:18 2013 %
*---------------------------------------------------------------------------*/


#ifndef PWMCDD_CFG_H
#define PWMCDD_CFG_H

#include "Sa_MtrPos.h"

#define d_PWMClockFreq_Hz_u32           75000000UL
#define d_PwmFreq_Hz_Cnt_u16           75000000UL

#define CDD_Read_PhaseAdvanceFinal_Rev_u0p16( ptr )		*(ptr) = (uint16)(((uint32)CDD_PhaseAdvFinal_Cnt_G_u16[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16] * d_RevpCnt_Uls_u0p32)>>d_Scaler16_Cnt_u16)

#define CDD_Read_CorrectedMtrPos_Rev_u0p16( ptr )		*(ptr) = MtrPos_CorrectedMtrPos_Rev_G_u0p16
									
#define CDD_Read_CommOffset_Cnt_u16( ptr )				*(ptr) = CDD_CommOffset_Cnt_G_u16[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16]
#define CDD_Write_DCPhsBComp_Cnt_u16p0( val ) 	(void)0 /* Disable optional write, not required */
#define CDD_Write_DCPhsCComp_Cnt_u16p0( val ) 	(void)0 /* Disable optional write, not required */

#endif
