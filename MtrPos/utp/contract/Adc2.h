/*****************************************************************************
* Copyright 2011 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Adc2.h
* Module Description: This file contains a stub header for UTP and QAC 
*                     projects
* Product           : Gen II Plus EA3.0
* Author            : Jared Julien
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Wed May  23 16:48:22 2003
* %version:          2 %
* %derived_by:       kzdyfh %
* %date_modified:    Fri Jul 13 11:01:10 2012 %
*---------------------------------------------------------------------------*/
#ifndef ADC2_H
#define ADC2_H

#define D_ADC2RSLTBASEADR_CNT_U32      (0xFF3A0000U)

#define  D_SHCURRCHN_CNT_U16           0U
#define  D_COSTHETA1CHN_CNT_U16        2U
#define  D_SINTHETA1CHN_CNT_U16        3U

#define Adc2_GetSinTheta1_Cnt_u16_m  Adc2_ReadConversion(D_SINTHETA1CHN_CNT_U16)
#define Adc2_GetCosTheta1_Cnt_u16_m  Adc2_ReadConversion(D_COSTHETA1CHN_CNT_U16)
#define Adc2_GetShcurr_Cnt_u16_m     Adc2_ReadConversion(D_SHCURRCHN_CNT_U16)

extern inline uint16 Adc2_ReadConversion(uint16 ConvId);

inline uint16 Adc2_ReadConversion(uint16 ConvId)
{
	return((uint16)(0x00000FFFUL & ((uint32*)D_ADC2RSLTBASEADR_CNT_U32)[ConvId]));
}

#endif  /* ADC2_H */