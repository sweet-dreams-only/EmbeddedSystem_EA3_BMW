/*****************************************************************************
* Copyright 2010 Nxtr Automotive., All Rights Reserved.
* Nxtr Confidential
* 
* Module File Name  : CalConstants.c
* Module Description: This file contains the definitions of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Dec  3 09:29:26 2010
* %version:          EA3#260 %
* %date_modified:    Mon Feb 17 16:38:41 2014 %
*---------------------------------------------------------------------------*/

#include "CalConstants.h"

#define CALCONSTANTS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

P2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
P2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;

#define CALCONSTANTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Put this at end of file
CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16] =
{
	&k_TunSet0_Cnt_Str,&k_TunSet1_Cnt_Str,&k_TunSet2_Cnt_Str,&k_TunSet3_Cnt_Str,&k_TunSet4_Cnt_Str,&k_TunSet5_Cnt_Str,&k_TunSet6_Cnt_Str,&k_TunSet7_Cnt_Str,&k_TunSet8_Cnt_Str,&k_TunSet9_Cnt_Str,&k_TunSet10_Cnt_Str,&k_TunSet11_Cnt_Str,&k_TunSet12_Cnt_Str
};


CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16] =
{
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str,&k_TunPer6_Cnt_Str,&k_TunPer7_Cnt_Str,&k_TunPer8_Cnt_Str,&k_TunPer9_Cnt_Str}
};
*/
/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 5/26/2017 1:16:25 PM *******************/
/************************* BMW UKL Program - Rev 273 *************************/


#pragma DATA_SECTION(k_TunSet0_Cnt_Str, ".TunSet0");
CONST(TUNING_Y_Str, CAL_CONST)k_TunSet0_Cnt_Str = { 1.0f, 45.0f, 2.8f, 10.0f, 0.5f, 2000UL, 160.0f, 60.0f, 1.0f, 1.0f, 0.25f, 0.05f, 20.0f, 0.269597308951354f, 3.0f, 45.0f, 0.5f, 100.0f, 6.26348737522175E-03f, 3.0f, 45.0f, 45.0f, 1.0f, 100UL, 1.0f, 45.0f, 3.0f, 1.0f, 1.0f, 1.0f, 3.0f, {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(30.0, u9p7_T),
	 FPM_InitFixedPoint_m(60.0, u9p7_T), FPM_InitFixedPoint_m(90.0, u9p7_T)}, {FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)}, 5.0f, 8.8f, 1.0f, -1.0f, 0.8f, 1.0f, -1.0f, 360.0f, 180.0f, 10.0f, 9.8f, 0.0f, {0.0f, 0.0f, 0.0f, 0.0f}, {-15.0f, -5.0f, 5.0f, 15.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {1, 1, 1, 1}, {{0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f,
	 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f,
	 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}}, 0.9f, 10.0f, 2.0f, 0.3f, {FPM_InitFixedPoint_m(3.5, u4p12_T), FPM_InitFixedPoint_m(3.0, u4p12_T),
	 FPM_InitFixedPoint_m(2.5, u4p12_T), FPM_InitFixedPoint_m(2.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.5, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.75, u4p12_T), FPM_InitFixedPoint_m(0.5, u4p12_T),
	 FPM_InitFixedPoint_m(0.25, u4p12_T), FPM_InitFixedPoint_m(0.1, u4p12_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(2.0, u9p7_T),
	 FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(25.0, u9p7_T),
	 FPM_InitFixedPoint_m(50.0, u9p7_T), FPM_InitFixedPoint_m(75.0, u9p7_T),
	 FPM_InitFixedPoint_m(100.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T),
	 FPM_InitFixedPoint_m(200.0, u9p7_T),
	 FPM_InitFixedPoint_m(249.0, u9p7_T)}, 20.0f, 0.5f, 20.0f, 1.0f, 17.0f, 0.04f, -1.0f, 20.0f, 0.0f, 0.0f, {0.0f,0.0f,0.0f,0.0f,1.0f}, {0.0f,0.0f,0.0f,0.0f}, {FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.5, u2p14_T),
	FPM_InitFixedPoint_m(0.75, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T)}, {FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T)}, {FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.1499, u8p8_T),
	FPM_InitFixedPoint_m(0.1499, u8p8_T),
	FPM_InitFixedPoint_m(0.19995, u8p8_T),FPM_InitFixedPoint_m(0.25, u8p8_T),
	FPM_InitFixedPoint_m(0.25, u8p8_T),FPM_InitFixedPoint_m(0.25, u8p8_T),
	FPM_InitFixedPoint_m(0.25, u8p8_T)}, {FPM_InitFixedPoint_m(0.0, u4p12_T),
	FPM_InitFixedPoint_m(0.02002, u4p12_T),
	FPM_InitFixedPoint_m(0.02002, u4p12_T),
	FPM_InitFixedPoint_m(0.050049, u4p12_T),
	FPM_InitFixedPoint_m(0.12012, u4p12_T),
	FPM_InitFixedPoint_m(0.12012, u4p12_T),
	FPM_InitFixedPoint_m(0.12012, u4p12_T),
	FPM_InitFixedPoint_m(0.12012, u4p12_T)}, {FPM_InitFixedPoint_m(4.0, u4p12_T),FPM_InitFixedPoint_m(4.0, u4p12_T),
	FPM_InitFixedPoint_m(4.0, u4p12_T),FPM_InitFixedPoint_m(4.0, u4p12_T),
	FPM_InitFixedPoint_m(4.0, u4p12_T),FPM_InitFixedPoint_m(4.0, u4p12_T),
	FPM_InitFixedPoint_m(4.0, u4p12_T),FPM_InitFixedPoint_m(4.0, u4p12_T)}, {{-0.17159f, 0.00010352f, 1.1696f, 0.00024516f, 1.9834e-05f},{-240.58f,
	 0.060289f, 240.53f, 0.17028f, 0.047148f},{0.0018246f, -4.2826e-06f,
	 0.99616f, 0.00025897f, -2.8965e-07f},{-6.1943f, 0.014635f, 5.9127f,
	 0.11656f, 0.00098854f},{-70.875f, -0.28572f, 70.86f, 0.053221f,
	 0.98679f}}, {{3.2994e-07f, 0.0081464f, 0.0019034f, 0.0016485f, 0.0016485f},
	{0.00045434f, 1.6329f, 0.0015119f, 0.76734f, 0.76734f},{1.1488e-06f,
	 -2.4566e-05f, 0.0019002f, 0.001743f, 0.001743f},{0.0027499f, 0.045004f,
	 0.00025007f, 0.86756f, 0.86756f}}, 2.0f, 1.5f, 1.0f, 0.7f, 50.0f, 6.0f, 120.0f, { FPM_InitFixedPoint_m(120.0, u12p4_T),
	FPM_InitFixedPoint_m(120.0, u12p4_T),
	FPM_InitFixedPoint_m(120.0, u12p4_T),
	FPM_InitFixedPoint_m(120.0, u12p4_T),
	FPM_InitFixedPoint_m(120.0, u12p4_T),
	FPM_InitFixedPoint_m(120.0, u12p4_T) }, 15.0f, { FPM_InitFixedPoint_m(-40.0, s8p7_T),
	 FPM_InitFixedPoint_m(-35.0, s8p7_T),
	 FPM_InitFixedPoint_m(-30.0, s8p7_T),
	  FPM_InitFixedPoint_m(-20.0, s8p7_T),
	 FPM_InitFixedPoint_m(-10.0, s8p7_T),  FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(10.0, s8p7_T), FPM_InitFixedPoint_m(20.0, s8p7_T),
	 FPM_InitFixedPoint_m(30.0, s8p7_T), FPM_InitFixedPoint_m(40.0, s8p7_T),
	 FPM_InitFixedPoint_m(50.0, s8p7_T) }, { FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T) }, 1U, 25.0f, {FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.05, u5p11_T), FPM_InitFixedPoint_m(0.1, u5p11_T),
	 FPM_InitFixedPoint_m(0.15, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(1.4, u5p11_T), FPM_InitFixedPoint_m(2.5, u5p11_T),
	 FPM_InitFixedPoint_m(4.0, u5p11_T), FPM_InitFixedPoint_m(6.0, u5p11_T),
	 FPM_InitFixedPoint_m(10.0, u5p11_T),
	 FPM_InitFixedPoint_m(14.0, u5p11_T)}, {50U,200U}, {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T),
	 FPM_InitFixedPoint_m(50.0, u9p7_T), FPM_InitFixedPoint_m(75.0, u9p7_T),
	 FPM_InitFixedPoint_m(100.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T),
	 FPM_InitFixedPoint_m(200.0, u9p7_T),
	 FPM_InitFixedPoint_m(255.0, u9p7_T), FPM_InitFixedPoint_m(0.0, u9p7_T),
	 FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(0.0, u9p7_T),
	 FPM_InitFixedPoint_m(0.0, u9p7_T)}, 0.00004f, 20.0f, {FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(0.5, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T),FPM_InitFixedPoint_m(1.5, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T), FPM_InitFixedPoint_m(2.5, u4p12_T),
	 FPM_InitFixedPoint_m(3.0, u4p12_T), FPM_InitFixedPoint_m(3.5, u4p12_T),
	 FPM_InitFixedPoint_m(4.0, u4p12_T), FPM_InitFixedPoint_m(4.5, u4p12_T)}, { FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T) }, { FPM_InitFixedPoint_m(62.8125, u12p4_T),
	 FPM_InitFixedPoint_m(586.4375, u12p4_T) }, { FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T) }, { FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3, u8p8_T), FPM_InitFixedPoint_m(0.2, u8p8_T),
	 FPM_InitFixedPoint_m(0.1, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T) }, { FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T),FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T),FPM_InitFixedPoint_m(1.0, u9p7_T) }, { FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T),FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T),FPM_InitFixedPoint_m(1.0, u9p7_T) }, {{FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T)},
	{FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T),
	 FPM_InitFixedPoint_m(0.005, um1p17_T)}}, {{FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),FPM_InitFixedPoint_m(15.0, u12p4_T),
	FPM_InitFixedPoint_m(15.0, u12p4_T), FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),FPM_InitFixedPoint_m(15.0, u12p4_T),
	FPM_InitFixedPoint_m(15.0, u12p4_T),FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T)},
	{FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),FPM_InitFixedPoint_m(15.0, u12p4_T),
	FPM_InitFixedPoint_m(15.0, u12p4_T), FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T)}}, 0.0f, FPM_InitFixedPoint_m(100.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u9p7_T), 20583U, 3991U, FPM_InitFixedPoint_m(30.0, u9p7_T), 20583U, FPM_InitFixedPoint_m(550.0, u12p4_T), FPM_InitFixedPoint_m(3.0, u12p4_T), FALSE, FPM_InitFixedPoint_m(0.0195, u4p12_T), { FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(5.0, u9p7_T),
	 FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T) }, { FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(5.0, u9p7_T),
	 FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T) }, { FPM_InitFixedPoint_m(25.0, u12p4_T),
	 FPM_InitFixedPoint_m(50.0, u12p4_T) }, { FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T) }, { FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T) }, {{FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T)},
	{FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T)},
	{FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T)},
	{FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T)}}, {{FPM_InitFixedPoint_m(1.0, u1p15_T),
	 FPM_InitFixedPoint_m(0.66, u1p15_T),
	 FPM_InitFixedPoint_m(0.33, u1p15_T),
	 FPM_InitFixedPoint_m(0.0, u1p15_T)},{FPM_InitFixedPoint_m(1.0, u1p15_T),
	 FPM_InitFixedPoint_m(0.66, u1p15_T),
	 FPM_InitFixedPoint_m(0.33, u1p15_T),
	 FPM_InitFixedPoint_m(0.0, u1p15_T)},{FPM_InitFixedPoint_m(1.0, u1p15_T),
	 FPM_InitFixedPoint_m(0.66, u1p15_T),
	 FPM_InitFixedPoint_m(0.33, u1p15_T),
	 FPM_InitFixedPoint_m(0.0, u1p15_T)},{FPM_InitFixedPoint_m(1.0, u1p15_T),
	 FPM_InitFixedPoint_m(0.66, u1p15_T),
	 FPM_InitFixedPoint_m(0.33, u1p15_T),
	 FPM_InitFixedPoint_m(0.0, u1p15_T)}}, {{FPM_InitFixedPoint_m(0.0, u0p16_T),
	 FPM_InitFixedPoint_m(0.004, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),
	 FPM_InitFixedPoint_m(0.004, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),
	 FPM_InitFixedPoint_m(0.004, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),
	 FPM_InitFixedPoint_m(0.004, u0p16_T)}}, {{FPM_InitFixedPoint_m(0.0, u0p16_T),
	 FPM_InitFixedPoint_m(0.001953125, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),
	 FPM_InitFixedPoint_m(0.001953125, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),
	 FPM_InitFixedPoint_m(0.001953125, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0, u0p16_T),
	 FPM_InitFixedPoint_m(0.001953125, u0p16_T)}}, FPM_InitFixedPoint_m(550.0, u12p4_T), {{FPM_InitFixedPoint_m(20.0, u12p4_T),
	FPM_InitFixedPoint_m(0.0, u12p4_T)},{FPM_InitFixedPoint_m(20.0, u12p4_T),
	FPM_InitFixedPoint_m(0.0, u12p4_T)},{FPM_InitFixedPoint_m(20.0, u12p4_T),
	FPM_InitFixedPoint_m(0.0, u12p4_T)},{FPM_InitFixedPoint_m(20.0, u12p4_T),
	FPM_InitFixedPoint_m(0.0, u12p4_T)}}, {{FPM_InitFixedPoint_m(8.8, s7p8_T),FPM_InitFixedPoint_m(8.8, s7p8_T),
	FPM_InitFixedPoint_m(8.8, s7p8_T),FPM_InitFixedPoint_m(8.8, s7p8_T),
	FPM_InitFixedPoint_m(8.8, s7p8_T)},{FPM_InitFixedPoint_m(8.8, s7p8_T),
	FPM_InitFixedPoint_m(8.8, s7p8_T),FPM_InitFixedPoint_m(8.8, s7p8_T),
	FPM_InitFixedPoint_m(8.8, s7p8_T),FPM_InitFixedPoint_m(8.8, s7p8_T)},
	{FPM_InitFixedPoint_m(8.8, s7p8_T),FPM_InitFixedPoint_m(8.8, s7p8_T),
	FPM_InitFixedPoint_m(8.8, s7p8_T),FPM_InitFixedPoint_m(8.8, s7p8_T),
	FPM_InitFixedPoint_m(8.8, s7p8_T)},{FPM_InitFixedPoint_m(8.8, s7p8_T),
	FPM_InitFixedPoint_m(8.8, s7p8_T),FPM_InitFixedPoint_m(8.8, s7p8_T),
	FPM_InitFixedPoint_m(8.8, s7p8_T),FPM_InitFixedPoint_m(8.8, s7p8_T)}}, 40.0f, 1130U, 0.1015625f, { FPM_InitFixedPoint_m(8.5, u8p8_T), FPM_InitFixedPoint_m(8.0, u8p8_T),
	 FPM_InitFixedPoint_m(7.5, u8p8_T), FPM_InitFixedPoint_m(7.0, u8p8_T) }, { FPM_InitFixedPoint_m(5.75, u8p8_T),
	 FPM_InitFixedPoint_m(6.22, u8p8_T), FPM_InitFixedPoint_m(6.67, u8p8_T),
	 FPM_InitFixedPoint_m(7.125, u8p8_T) }, 30573U, { FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.2, u6p10_T),
	FPM_InitFixedPoint_m(0.4, u6p10_T),FPM_InitFixedPoint_m(0.6, u6p10_T),
	FPM_InitFixedPoint_m(0.8, u6p10_T),FPM_InitFixedPoint_m(1.0, u6p10_T) }, { FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T) }, { FPM_InitFixedPoint_m(0.0, u4p12_T),FPM_InitFixedPoint_m(0.0, u4p12_T),
	FPM_InitFixedPoint_m(0.0, u4p12_T),FPM_InitFixedPoint_m(0.0, u4p12_T),
	FPM_InitFixedPoint_m(0.0, u4p12_T),FPM_InitFixedPoint_m(0.0, u4p12_T),
	FPM_InitFixedPoint_m(0.0, u4p12_T),FPM_InitFixedPoint_m(0.0, u4p12_T) }, { FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.2, u6p10_T),
	FPM_InitFixedPoint_m(0.4, u6p10_T),FPM_InitFixedPoint_m(0.5, u6p10_T),
	FPM_InitFixedPoint_m(0.8, u6p10_T),FPM_InitFixedPoint_m(1.0, u6p10_T) }, { FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T) }, { FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T) }, { FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(10.0, u12p4_T),FPM_InitFixedPoint_m(30.0, u12p4_T),
	FPM_InitFixedPoint_m(60.0, u12p4_T),FPM_InitFixedPoint_m(80.0, u12p4_T),
	FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(120.0, u12p4_T),
	FPM_InitFixedPoint_m(150.0, u12p4_T) }, 50.0f, 50.0f, 50.0f, 16.0f, 6.0f, FPM_InitFixedPoint_m(100.0, u9p7_T), { FPM_InitFixedPoint_m(-40.0, s14p1_T),
	 FPM_InitFixedPoint_m(-30.0, s14p1_T),
	 FPM_InitFixedPoint_m(-20.0, s14p1_T),
	 FPM_InitFixedPoint_m(-10.0, s14p1_T),
	 FPM_InitFixedPoint_m(0.0, s14p1_T), FPM_InitFixedPoint_m(25.0, s14p1_T),
	 FPM_InitFixedPoint_m(50.0, s14p1_T),
	 FPM_InitFixedPoint_m(80.0, s14p1_T) }, { FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T) }, { FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.094773206, u2p14_T),
	 FPM_InitFixedPoint_m(0.128210527, u2p14_T),
	 FPM_InitFixedPoint_m(0.154492771, u2p14_T),
	 FPM_InitFixedPoint_m(0.181721481, u2p14_T),
	 FPM_InitFixedPoint_m(0.2, u2p14_T) }, { FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.6015625, u2p14_T),
	 FPM_InitFixedPoint_m(0.797, u2p14_T),
	 FPM_InitFixedPoint_m(0.912, u2p14_T),
	 FPM_InitFixedPoint_m(0.981, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T) }, { FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(25.0, u9p7_T),
	 FPM_InitFixedPoint_m(60.0, u9p7_T), FPM_InitFixedPoint_m(80.0, u9p7_T),
	 FPM_InitFixedPoint_m(100.0, u9p7_T),
	 FPM_InitFixedPoint_m(120.0, u9p7_T),
	 FPM_InitFixedPoint_m(139.897255453309, u9p7_T),
	 FPM_InitFixedPoint_m(160.0, u9p7_T) }, FPM_InitFixedPoint_m(0.1, u4p12_T), 0.1f, 0.02f, 1.0f, 100U, 2.0f, 450.0f, 400.0f, 1.0f, 50.0f, 0.00000119954f, 0.00000119954f, 35.018224f, 35.018224f, 6268U, 1224U, 0.000133f, FPM_InitFixedPoint_m(2.0, u17pm1_T), 1826.1f, 0.000000603497f, 11.0f, 37.0f, 0.041f, 0.00018f, 0.00018f, 0.052f, 0.026f, 0.00012f, 0.00012f, 0.022f, 0.000156f, 4954.3125f, 0.000000603497f, {FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.05, u5p11_T), FPM_InitFixedPoint_m(0.1, u5p11_T),
	 FPM_InitFixedPoint_m(1.0, u5p11_T), FPM_InitFixedPoint_m(2.0, u5p11_T),
	 FPM_InitFixedPoint_m(3.53955781, u5p11_T)}, {FPM_InitFixedPoint_m(-40.0, s10p5_T),
	FPM_InitFixedPoint_m(0.0, s10p5_T),FPM_InitFixedPoint_m(25.0, s10p5_T),
	FPM_InitFixedPoint_m(80.0, s10p5_T),FPM_InitFixedPoint_m(180.0, s10p5_T)}, {FPM_InitFixedPoint_m(1.15, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.95, u2p14_T),FPM_InitFixedPoint_m(0.85, u2p14_T),
	FPM_InitFixedPoint_m(0.75, u2p14_T)}, { FPM_InitFixedPoint_m(50.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T) }, { FPM_InitFixedPoint_m(-0.3125, s11p4_T),
	 FPM_InitFixedPoint_m(-1.0625, s11p4_T) }, { FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(15.0, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T) }, { FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T) }, { FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(10.0, u12p4_T),
	 FPM_InitFixedPoint_m(25.0, u12p4_T),
	 FPM_InitFixedPoint_m(35.0, u12p4_T),
	 FPM_InitFixedPoint_m(45.0, u12p4_T),
	 FPM_InitFixedPoint_m(55.0, u12p4_T),
	 FPM_InitFixedPoint_m(65.0, u12p4_T),
	 FPM_InitFixedPoint_m(75.0, u12p4_T),
	 FPM_InitFixedPoint_m(85.0, u12p4_T),
	 FPM_InitFixedPoint_m(95.0, u12p4_T),
	 FPM_InitFixedPoint_m(105.0, u12p4_T),
	 FPM_InitFixedPoint_m(115.0, u12p4_T),
	 FPM_InitFixedPoint_m(125.0, u12p4_T),
	 FPM_InitFixedPoint_m(135.0, u12p4_T),
	 FPM_InitFixedPoint_m(145.0, u12p4_T),
	 FPM_InitFixedPoint_m(150.0, u12p4_T) }, { FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.998046875, u2p14_T),
	 FPM_InitFixedPoint_m(0.998046875, u2p14_T),
	 FPM_InitFixedPoint_m(0.994140625, u2p14_T),
	 FPM_InitFixedPoint_m(0.9921875, u2p14_T),
	 FPM_InitFixedPoint_m(0.98828125, u2p14_T),
	 FPM_InitFixedPoint_m(0.982421875, u2p14_T),
	 FPM_InitFixedPoint_m(0.974609375, u2p14_T),
	 FPM_InitFixedPoint_m(0.966796875, u2p14_T),
	 FPM_InitFixedPoint_m(0.95703125, u2p14_T),
	 FPM_InitFixedPoint_m(0.9453125, u2p14_T),
	 FPM_InitFixedPoint_m(0.931640625, u2p14_T),
	 FPM_InitFixedPoint_m(0.916015625, u2p14_T),
	 FPM_InitFixedPoint_m(0.90625, u2p14_T) }, {FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(545.0, u12p4_T),
	 FPM_InitFixedPoint_m(600.0, u12p4_T)}, {FPM_InitFixedPoint_m(18.0, u8p8_T), FPM_InitFixedPoint_m(14.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(25.0, u9p7_T),
	FPM_InitFixedPoint_m(50.0, u9p7_T),FPM_InitFixedPoint_m(75.0, u9p7_T),
	FPM_InitFixedPoint_m(100.0, u9p7_T),FPM_InitFixedPoint_m(125.0, u9p7_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(25.0, u9p7_T),
	FPM_InitFixedPoint_m(50.0, u9p7_T),FPM_InitFixedPoint_m(75.0, u9p7_T),
	FPM_InitFixedPoint_m(100.0, u9p7_T),FPM_InitFixedPoint_m(125.0, u9p7_T),
	FPM_InitFixedPoint_m(150.0, u9p7_T)}, { FPM_InitFixedPoint_m(50.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T) }, { FPM_InitFixedPoint_m(0.0, s11p4_T),
	 FPM_InitFixedPoint_m(0.0, s11p4_T) }, { FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(40.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T),
	 FPM_InitFixedPoint_m(156.25, u12p4_T) }, { FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(145.0, u12p4_T),
	 FPM_InitFixedPoint_m(145.0, u12p4_T),
	 FPM_InitFixedPoint_m(145.0, u12p4_T),
	 FPM_InitFixedPoint_m(145.0, u12p4_T),
	 FPM_InitFixedPoint_m(145.0, u12p4_T),
	 FPM_InitFixedPoint_m(145.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T) }, {FPM_InitFixedPoint_m(0.0029296875, u5p11_T),
	 FPM_InitFixedPoint_m(0.00390625, u5p11_T),
	 FPM_InitFixedPoint_m(0.0048828125, u5p11_T),
	 FPM_InitFixedPoint_m(0.005859375, u5p11_T),
	 FPM_InitFixedPoint_m(0.0068359375, u5p11_T)}, {FPM_InitFixedPoint_m(0.2890625, u8p8_T),
	 FPM_InitFixedPoint_m(0.2265625, u8p8_T),
	 FPM_InitFixedPoint_m(0.18359375, u8p8_T),
	 FPM_InitFixedPoint_m(0.15625, u8p8_T),
	 FPM_InitFixedPoint_m(0.13671875, u8p8_T)}, { 1.19775559568469f, 3.32861150614105f, 4.31589914096864f}, {1.56501686361234f, 5.57162661427276f, 8.26784148299549f}, {{FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T)},
	{FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(-4.67080988446433, s8p7_T),
	 FPM_InitFixedPoint_m(-6.88128982000513, s8p7_T),
	 FPM_InitFixedPoint_m(-8.51022744104161, s8p7_T),
	 FPM_InitFixedPoint_m(-9.8721646172778, s8p7_T),
	 FPM_InitFixedPoint_m(-11.0672851773818, s8p7_T),
	 FPM_InitFixedPoint_m(-12.1451828285188, s8p7_T),
	 FPM_InitFixedPoint_m(-13.1348309437181, s8p7_T),
	 FPM_InitFixedPoint_m(-14.0549181070709, s8p7_T),
	 FPM_InitFixedPoint_m(-14.9183371325726, s8p7_T),
	 FPM_InitFixedPoint_m(-15.7344287305295, s8p7_T),
	 FPM_InitFixedPoint_m(-16.5102177632168, s8p7_T),
	 FPM_InitFixedPoint_m(-17.2511455900539, s8p7_T),
	 FPM_InitFixedPoint_m(-17.9615289930963, s8p7_T),
	 FPM_InitFixedPoint_m(-18.644861013119, s8p7_T),
	 FPM_InitFixedPoint_m(-19.3040155791483, s8p7_T),
	 FPM_InitFixedPoint_m(-19.941391067123, s8p7_T),
	 FPM_InitFixedPoint_m(-21.1085904672482, s8p7_T),
	 FPM_InitFixedPoint_m(-24.3045030654481, s8p7_T),
	 FPM_InitFixedPoint_m(-28.7007700964385, s8p7_T),
	 FPM_InitFixedPoint_m(-31.8052698526471, s8p7_T),
	 FPM_InitFixedPoint_m(-34.0984437577089, s8p7_T),
	 FPM_InitFixedPoint_m(-35.577750755255, s8p7_T),
	 FPM_InitFixedPoint_m(-37.057057752801, s8p7_T),
	 FPM_InitFixedPoint_m(-38.2354222215153, s8p7_T),
	 FPM_InitFixedPoint_m(-39.0277322404774, s8p7_T),
	 FPM_InitFixedPoint_m(-39.8200422594396, s8p7_T),
	 FPM_InitFixedPoint_m(-27.4447092572404, s8p7_T),
	 FPM_InitFixedPoint_m(-12.180116817389, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T)},{FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(-6.28644390571263, s8p7_T),
	 FPM_InitFixedPoint_m(-9.4941277077943, s8p7_T),
	 FPM_InitFixedPoint_m(-11.8453637939242, s8p7_T),
	 FPM_InitFixedPoint_m(-13.7983091606927, s8p7_T),
	 FPM_InitFixedPoint_m(-15.5063915242015, s8p7_T),
	 FPM_InitFixedPoint_m(-17.043830311382, s8p7_T),
	 FPM_InitFixedPoint_m(-18.4534691437353, s8p7_T),
	 FPM_InitFixedPoint_m(-19.762733305097, s8p7_T),
	 FPM_InitFixedPoint_m(-20.9904420894956, s8p7_T),
	 FPM_InitFixedPoint_m(-22.150175912254, s8p7_T),
	 FPM_InitFixedPoint_m(-23.2521168870964, s8p7_T),
	 FPM_InitFixedPoint_m(-24.3041326424902, s8p7_T),
	 FPM_InitFixedPoint_m(-25.3124523071397, s8p7_T),
	 FPM_InitFixedPoint_m(-26.2821079523226, s8p7_T),
	 FPM_InitFixedPoint_m(-27.2172339210375, s8p7_T),
	 FPM_InitFixedPoint_m(-28.1212762701395, s8p7_T),
	 FPM_InitFixedPoint_m(-29.2908899057968, s8p7_T),
	 FPM_InitFixedPoint_m(-31.6621701752347, s8p7_T),
	 FPM_InitFixedPoint_m(-35.1690054639638, s8p7_T),
	 FPM_InitFixedPoint_m(-37.7671287248822, s8p7_T),
	 FPM_InitFixedPoint_m(-39.7376156641685, s8p7_T),
	 FPM_InitFixedPoint_m(-41.0391514980999, s8p7_T),
	 FPM_InitFixedPoint_m(-42.3406873320313, s8p7_T),
	 FPM_InitFixedPoint_m(-43.38381400779, s8p7_T),
	 FPM_InitFixedPoint_m(-44.0954488011735, s8p7_T),
	 FPM_InitFixedPoint_m(-44.807083594557, s8p7_T),
	 FPM_InitFixedPoint_m(-30.8596387899976, s8p7_T),
	 FPM_InitFixedPoint_m(-13.6956818118027, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T)},{FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(-8.24298460174262, s8p7_T),
	 FPM_InitFixedPoint_m(-13.8183746929688, s8p7_T),
	 FPM_InitFixedPoint_m(-24.2988651417935, s8p7_T),
	 FPM_InitFixedPoint_m(-32.9649199494075, s8p7_T),
	 FPM_InitFixedPoint_m(-39.8685364171024, s8p7_T),
	 FPM_InitFixedPoint_m(-45.726675789549, s8p7_T),
	 FPM_InitFixedPoint_m(-50.9103409065716, s8p7_T),
	 FPM_InitFixedPoint_m(-55.6108158563611, s8p7_T),
	 FPM_InitFixedPoint_m(-59.9427531062988, s8p7_T),
	 FPM_InitFixedPoint_m(-63.9814466151315, s8p7_T),
	 FPM_InitFixedPoint_m(-67.7795366831045, s8p7_T),
	 FPM_InitFixedPoint_m(-71.3755551608371, s8p7_T),
	 FPM_InitFixedPoint_m(-74.7987190380691, s8p7_T),
	 FPM_InitFixedPoint_m(-78.0718110134619, s8p7_T),
	 FPM_InitFixedPoint_m(-81.213005808975, s8p7_T),
	 FPM_InitFixedPoint_m(-84.2370790509134, s8p7_T),
	 FPM_InitFixedPoint_m(-87.0924964394319, s8p7_T),
	 FPM_InitFixedPoint_m(-89.4604521584086, s8p7_T),
	 FPM_InitFixedPoint_m(-90.9118918350216, s8p7_T),
	 FPM_InitFixedPoint_m(-92.0753925272471, s8p7_T),
	 FPM_InitFixedPoint_m(-92.702116492519, s8p7_T),
	 FPM_InitFixedPoint_m(-87.901982479654, s8p7_T),
	 FPM_InitFixedPoint_m(-83.101848466789, s8p7_T),
	 FPM_InitFixedPoint_m(-76.7377559649277, s8p7_T),
	 FPM_InitFixedPoint_m(-68.3673895866286, s8p7_T),
	 FPM_InitFixedPoint_m(-59.9970232083296, s8p7_T),
	 FPM_InitFixedPoint_m(-40.1691714016803, s8p7_T),
	 FPM_InitFixedPoint_m(-17.8273049112777, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T)},{FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(-8.24298460174262, s8p7_T),
	 FPM_InitFixedPoint_m(-13.8183746929688, s8p7_T),
	 FPM_InitFixedPoint_m(-24.2988651417935, s8p7_T),
	 FPM_InitFixedPoint_m(-32.9649199494075, s8p7_T),
	 FPM_InitFixedPoint_m(-39.8685364171024, s8p7_T),
	 FPM_InitFixedPoint_m(-48.9310916018151, s8p7_T),
	 FPM_InitFixedPoint_m(-58.0736445275509, s8p7_T),
	 FPM_InitFixedPoint_m(-66.1531625410429, s8p7_T),
	 FPM_InitFixedPoint_m(-73.3393998900978, s8p7_T),
	 FPM_InitFixedPoint_m(-79.8778003052942, s8p7_T),
	 FPM_InitFixedPoint_m(-85.9179717649986, s8p7_T),
	 FPM_InitFixedPoint_m(-91.5593108403641, s8p7_T),
	 FPM_InitFixedPoint_m(-96.8719083396671, s8p7_T),
	 FPM_InitFixedPoint_m(-101.907411810839, s8p7_T),
	 FPM_InitFixedPoint_m(-105.791780202808, s8p7_T),
	 FPM_InitFixedPoint_m(-107.049927100508, s8p7_T),
	 FPM_InitFixedPoint_m(-106.32975581125, s8p7_T),
	 FPM_InitFixedPoint_m(-104.565808155433, s8p7_T),
	 FPM_InitFixedPoint_m(-102.036856438429, s8p7_T),
	 FPM_InitFixedPoint_m(-98.7524997792789, s8p7_T),
	 FPM_InitFixedPoint_m(-94.6415408998113, s8p7_T),
	 FPM_InitFixedPoint_m(-89.0843943509482, s8p7_T),
	 FPM_InitFixedPoint_m(-83.5272478020852, s8p7_T),
	 FPM_InitFixedPoint_m(-76.7377559649277, s8p7_T),
	 FPM_InitFixedPoint_m(-68.3673895866286, s8p7_T),
	 FPM_InitFixedPoint_m(-59.9970232083296, s8p7_T),
	 FPM_InitFixedPoint_m(-40.1691714016803, s8p7_T),
	 FPM_InitFixedPoint_m(-17.8273049112777, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T)},{FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(-8.24298460174262, s8p7_T),
	 FPM_InitFixedPoint_m(-13.8183746929688, s8p7_T),
	 FPM_InitFixedPoint_m(-24.2988651417935, s8p7_T),
	 FPM_InitFixedPoint_m(-32.9649199494075, s8p7_T),
	 FPM_InitFixedPoint_m(-39.8685364171024, s8p7_T),
	 FPM_InitFixedPoint_m(-48.9310916018151, s8p7_T),
	 FPM_InitFixedPoint_m(-58.0736445275509, s8p7_T),
	 FPM_InitFixedPoint_m(-66.1531625410429, s8p7_T),
	 FPM_InitFixedPoint_m(-74.4458533287768, s8p7_T),
	 FPM_InitFixedPoint_m(-82.9506676394028, s8p7_T),
	 FPM_InitFixedPoint_m(-90.3417334664003, s8p7_T),
	 FPM_InitFixedPoint_m(-96.1168652382987, s8p7_T),
	 FPM_InitFixedPoint_m(-100.560316330817, s8p7_T),
	 FPM_InitFixedPoint_m(-103.845746704477, s8p7_T),
	 FPM_InitFixedPoint_m(-106.082235620262, s8p7_T),
	 FPM_InitFixedPoint_m(-107.049927100508, s8p7_T),
	 FPM_InitFixedPoint_m(-106.32975581125, s8p7_T),
	 FPM_InitFixedPoint_m(-104.565808155433, s8p7_T),
	 FPM_InitFixedPoint_m(-102.036856438429, s8p7_T),
	 FPM_InitFixedPoint_m(-98.7524997792789, s8p7_T),
	 FPM_InitFixedPoint_m(-94.6415408998113, s8p7_T),
	 FPM_InitFixedPoint_m(-89.0843943509482, s8p7_T),
	 FPM_InitFixedPoint_m(-83.5272478020852, s8p7_T),
	 FPM_InitFixedPoint_m(-76.7377559649277, s8p7_T),
	 FPM_InitFixedPoint_m(-68.3673895866286, s8p7_T),
	 FPM_InitFixedPoint_m(-59.9970232083296, s8p7_T),
	 FPM_InitFixedPoint_m(-40.1691714016803, s8p7_T),
	 FPM_InitFixedPoint_m(-17.8273049112777, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T), FPM_InitFixedPoint_m(0.0, s8p7_T),
	 FPM_InitFixedPoint_m(0.0, s8p7_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9961, u2p14_T),
	FPM_InitFixedPoint_m(0.9883, u2p14_T),
	FPM_InitFixedPoint_m(0.9707, u2p14_T),
	FPM_InitFixedPoint_m(0.9453, u2p14_T),
	FPM_InitFixedPoint_m(0.9063, u2p14_T)}}, 0.00045f, 0.75f, 0.99994282f, 0.86667048f, -0.8666133f, 0.0004f, 0.01f, 0.9999623f, 0.57143665f, -0.571399f, 0.024f, 0.0f, 0.99988879f, 1.68567616f, -1.685565f, -2.0f, -2.0f, -2.0f, 0.0f, { FPM_InitFixedPoint_m(10.0, u9p7_T),
	 FPM_InitFixedPoint_m(40.0, u9p7_T),
	 FPM_InitFixedPoint_m(100.0, u9p7_T) }, { 0U, 100U, 300U }, 1627U, 100UL, FPM_InitFixedPoint_m(3.0, u8p8_T), FPM_InitFixedPoint_m(5.0, u8p8_T), 0.1f, 500UL, 7.0f, 750UL, 30.0f, 10.0f, 0.5f, 2.0f, 2.0f, FPM_InitFixedPoint_m(3.2578125, u9p7_T), {FPM_InitFixedPoint_m(600.0, u12p4_T),
	FPM_InitFixedPoint_m(600.0, u12p4_T),
	FPM_InitFixedPoint_m(600.0, u12p4_T)}, {FPM_InitFixedPoint_m(6.0, u7p9_T), FPM_InitFixedPoint_m(6.0, u7p9_T),
	 FPM_InitFixedPoint_m(6.0, u7p9_T)}, {FPM_InitFixedPoint_m(0.0, u11p5_T), FPM_InitFixedPoint_m(1.0, u11p5_T),
	 FPM_InitFixedPoint_m(2.0, u11p5_T), FPM_InitFixedPoint_m(3.0, u11p5_T),
	 FPM_InitFixedPoint_m(4.0, u11p5_T), FPM_InitFixedPoint_m(7.0, u11p5_T)}, {FPM_InitFixedPoint_m(0.3, u12p4_T), FPM_InitFixedPoint_m(0.4, u12p4_T),
	 FPM_InitFixedPoint_m(0.5, u12p4_T), FPM_InitFixedPoint_m(1.0, u12p4_T),
	 FPM_InitFixedPoint_m(2.0, u12p4_T), FPM_InitFixedPoint_m(5.0, u12p4_T)}, {FPM_InitFixedPoint_m(0.002, u3p13_T),
	 FPM_InitFixedPoint_m(0.002, u3p13_T),
	 FPM_InitFixedPoint_m(0.002, u3p13_T)}, {FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)}, {FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(2.0, u12p4_T),
	 FPM_InitFixedPoint_m(4.0, u12p4_T), FPM_InitFixedPoint_m(8.0, u12p4_T),
	 FPM_InitFixedPoint_m(20.0, u12p4_T),
	 FPM_InitFixedPoint_m(25.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T)}, {FPM_InitFixedPoint_m(0.0, u6p10_T), FPM_InitFixedPoint_m(0.1, u6p10_T),
	 FPM_InitFixedPoint_m(0.2, u6p10_T), FPM_InitFixedPoint_m(0.3, u6p10_T),
	 FPM_InitFixedPoint_m(0.4, u6p10_T), FPM_InitFixedPoint_m(0.6, u6p10_T),
	 FPM_InitFixedPoint_m(0.7, u6p10_T), FPM_InitFixedPoint_m(0.8, u6p10_T),
	 FPM_InitFixedPoint_m(0.9, u6p10_T), FPM_InitFixedPoint_m(1.0, u6p10_T)}, {FPM_InitFixedPoint_m(0.000, u6p10_T),
	 FPM_InitFixedPoint_m(0.024, u6p10_T),
	 FPM_InitFixedPoint_m(0.095, u6p10_T),
	 FPM_InitFixedPoint_m(0.206, u6p10_T),
	 FPM_InitFixedPoint_m(0.345, u6p10_T),
	 FPM_InitFixedPoint_m(0.655, u6p10_T),
	 FPM_InitFixedPoint_m(0.794, u6p10_T),
	 FPM_InitFixedPoint_m(0.905, u6p10_T),
	 FPM_InitFixedPoint_m(0.976, u6p10_T),
	 FPM_InitFixedPoint_m(1.000, u6p10_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(2.0, u9p7_T),
	 FPM_InitFixedPoint_m(5.0, u9p7_T)}, 0.1f, 0.1f, 3.31878662109375E-02f, FPM_InitFixedPoint_m(0.0625, u12p4_T), FPM_InitFixedPoint_m(6.25, u12p4_T), { FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(89.25, u12p4_T),
	FPM_InitFixedPoint_m(153.3125, u12p4_T),
	FPM_InitFixedPoint_m(382.6875, u12p4_T),
	FPM_InitFixedPoint_m(543.625, u12p4_T),
	FPM_InitFixedPoint_m(564.5625, u12p4_T) }, { FPM_InitFixedPoint_m(3.625, u5p11_T),
	FPM_InitFixedPoint_m(3.625, u5p11_T),
	FPM_InitFixedPoint_m(3.28076171875, u5p11_T),
	FPM_InitFixedPoint_m(1.47900390625, u5p11_T),
	FPM_InitFixedPoint_m(0.26611328125, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T) }, { FPM_InitFixedPoint_m(20.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(40.0, u12p4_T),
	 FPM_InitFixedPoint_m(50.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(70.0, u12p4_T),
	 FPM_InitFixedPoint_m(85.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(100.0, u12p4_T),
	 FPM_InitFixedPoint_m(120.0, u12p4_T) }, { FPM_InitFixedPoint_m(322.0, u12p4_T),
	 FPM_InitFixedPoint_m(246.0625, u12p4_T),
	 FPM_InitFixedPoint_m(183.25, u12p4_T),
	 FPM_InitFixedPoint_m(128.3125, u12p4_T),
	 FPM_InitFixedPoint_m(89.0, u12p4_T),
	 FPM_InitFixedPoint_m(54.4375, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T) }, { FPM_InitFixedPoint_m(8.5, u8p8_T),FPM_InitFixedPoint_m(9.0, u8p8_T),
	FPM_InitFixedPoint_m(9.1484375, u8p8_T),
	FPM_InitFixedPoint_m(9.25, u8p8_T),
	FPM_InitFixedPoint_m(9.3515625, u8p8_T),
	FPM_InitFixedPoint_m(9.44921875, u8p8_T),
	FPM_InitFixedPoint_m(9.69921875, u8p8_T),
	FPM_InitFixedPoint_m(10.1640625, u8p8_T),
	FPM_InitFixedPoint_m(10.6640625, u8p8_T),
	FPM_InitFixedPoint_m(11.1640625, u8p8_T) }, { FPM_InitFixedPoint_m(544.5, s11p4_T),
	FPM_InitFixedPoint_m(544.5, s11p4_T),
	FPM_InitFixedPoint_m(460.75, s11p4_T),
	FPM_InitFixedPoint_m(429.3125, s11p4_T),
	FPM_InitFixedPoint_m(397.875, s11p4_T),
	FPM_InitFixedPoint_m(366.5, s11p4_T),
	FPM_InitFixedPoint_m(94.1875, s11p4_T),
	FPM_InitFixedPoint_m(37.6875, s11p4_T),
	FPM_InitFixedPoint_m(18.8125, s11p4_T),
	FPM_InitFixedPoint_m(0.0, s11p4_T) }, {FPM_InitFixedPoint_m(5.5, u8p8_T), FPM_InitFixedPoint_m(6.0, u8p8_T),
	 FPM_InitFixedPoint_m(6.125, u8p8_T),
	 FPM_InitFixedPoint_m(6.625, u8p8_T),
	 FPM_InitFixedPoint_m(7.625, u8p8_T),
	 FPM_InitFixedPoint_m(8.4765625, u8p8_T),
	 FPM_InitFixedPoint_m(9.4765625, u8p8_T),
	 FPM_InitFixedPoint_m(9.86328125, u8p8_T),
	 FPM_InitFixedPoint_m(10.36328125, u8p8_T),
	 FPM_InitFixedPoint_m(10.86328125, u8p8_T)}, {FPM_InitFixedPoint_m(670.1875, s11p4_T),
	 FPM_InitFixedPoint_m(670.1875, s11p4_T),
	 FPM_InitFixedPoint_m(418.875, s11p4_T),
	 FPM_InitFixedPoint_m(282.6875, s11p4_T),
	 FPM_InitFixedPoint_m(214.625, s11p4_T),
	 FPM_InitFixedPoint_m(117.75, s11p4_T),
	 FPM_InitFixedPoint_m(83.75, s11p4_T),
	 FPM_InitFixedPoint_m(27.1875, s11p4_T),
	 FPM_InitFixedPoint_m(13.5625, s11p4_T),
	 FPM_InitFixedPoint_m(0.0, s11p4_T)}, { FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(89.25, u12p4_T),
	FPM_InitFixedPoint_m(133.3125, u12p4_T),
	FPM_InitFixedPoint_m(362.6875, u12p4_T),
	FPM_InitFixedPoint_m(523.625, u12p4_T),
	FPM_InitFixedPoint_m(544.5625, u12p4_T) }, { FPM_InitFixedPoint_m(3.53955078125, u5p11_T),
	FPM_InitFixedPoint_m(3.53955078125, u5p11_T),
	FPM_InitFixedPoint_m(3.28076171875, u5p11_T),
	FPM_InitFixedPoint_m(1.47900390625, u5p11_T),
	FPM_InitFixedPoint_m(0.26611328125, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T) }, { FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(70.4375, u12p4_T),
	FPM_InitFixedPoint_m(114.5, u12p4_T),
	FPM_InitFixedPoint_m(343.875, u12p4_T),
	FPM_InitFixedPoint_m(504.8125, u12p4_T),
	FPM_InitFixedPoint_m(525.75, u12p4_T) }, { FPM_InitFixedPoint_m(3.53955078125, u5p11_T),
	FPM_InitFixedPoint_m(3.53955078125, u5p11_T),
	FPM_InitFixedPoint_m(3.28076171875, u5p11_T),
	FPM_InitFixedPoint_m(1.47900390625, u5p11_T),
	FPM_InitFixedPoint_m(0.26611328125, u5p11_T),
	FPM_InitFixedPoint_m(0.0, u5p11_T) }, -1, { FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(30.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(90.0, u10p6_T),FPM_InitFixedPoint_m(120.0, u10p6_T),
	FPM_InitFixedPoint_m(150.0, u10p6_T),
	FPM_InitFixedPoint_m(180.0, u10p6_T),
	FPM_InitFixedPoint_m(210.0, u10p6_T),
	FPM_InitFixedPoint_m(240.0, u10p6_T),
	FPM_InitFixedPoint_m(270.0, u10p6_T),
	FPM_InitFixedPoint_m(300.0, u10p6_T),
	FPM_InitFixedPoint_m(330.0, u10p6_T),
	FPM_InitFixedPoint_m(360.0, u10p6_T),
	FPM_InitFixedPoint_m(390.0, u10p6_T),
	FPM_InitFixedPoint_m(420.0, u10p6_T),
	FPM_InitFixedPoint_m(450.0, u10p6_T),
	FPM_InitFixedPoint_m(480.0, u10p6_T),
	FPM_InitFixedPoint_m(482.0, u10p6_T) }, { FPM_InitFixedPoint_m(59.0, u10p6_T),
	FPM_InitFixedPoint_m(59.33, u10p6_T),
	FPM_InitFixedPoint_m(61.64, u10p6_T),
	FPM_InitFixedPoint_m(64.89, u10p6_T),
	FPM_InitFixedPoint_m(67.18, u10p6_T),FPM_InitFixedPoint_m(67.5, u10p6_T),
	FPM_InitFixedPoint_m(67.5, u10p6_T),FPM_InitFixedPoint_m(67.5, u10p6_T),
	FPM_InitFixedPoint_m(67.23, u10p6_T),FPM_InitFixedPoint_m(66.1, u10p6_T),
	FPM_InitFixedPoint_m(64.91, u10p6_T),
	FPM_InitFixedPoint_m(63.71, u10p6_T),
	FPM_InitFixedPoint_m(62.51, u10p6_T),
	FPM_InitFixedPoint_m(61.32, u10p6_T),
	FPM_InitFixedPoint_m(60.12, u10p6_T),
	FPM_InitFixedPoint_m(59.11, u10p6_T),FPM_InitFixedPoint_m(59.0, u10p6_T),
	FPM_InitFixedPoint_m(59.0, u10p6_T) }, 0.1f, 17.0f, 0.04f, {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(3.0, u9p7_T),
	 FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T),
	 FPM_InitFixedPoint_m(30.0, u9p7_T), FPM_InitFixedPoint_m(60.0, u9p7_T),
	 FPM_InitFixedPoint_m(100.0, u9p7_T),
	 FPM_InitFixedPoint_m(255.0, u9p7_T)}, 1, 1.0f, 0.15f, {FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(2.0, u2p14_T)}, {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)}, {FPM_InitFixedPoint_m(0.0, u8p8_T),  FPM_InitFixedPoint_m(2.0, u8p8_T),
	  FPM_InitFixedPoint_m(4.0, u8p8_T), FPM_InitFixedPoint_m(6.0, u8p8_T),
	 FPM_InitFixedPoint_m(8.0, u8p8_T)}, {FPM_InitFixedPoint_m(0.0, u8p8_T),  FPM_InitFixedPoint_m(2.0, u8p8_T),
	  FPM_InitFixedPoint_m(4.0, u8p8_T), FPM_InitFixedPoint_m(6.0, u8p8_T),
	 FPM_InitFixedPoint_m(8.0, u8p8_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(10.0, u9p7_T),
	 FPM_InitFixedPoint_m(30.0, u9p7_T), FPM_InitFixedPoint_m(45.0, u9p7_T),
	 FPM_InitFixedPoint_m(60.0, u9p7_T), FPM_InitFixedPoint_m(80.0, u9p7_T)}, {{-0.2362671F,-0.6796265F,2.6297000F,-4.753113F,2.2075200F},
	{-0.1722412F,-0.6889648F,11.530700F,-20.35083F,8.9589230F},{-0.2362671F,
	-0.6796265F,2.6297000F,-4.753113F,2.2075200F},{-0.1722412F,-0.6889648F,
	11.530700F,-20.35083F,8.9589230F}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)}}, {{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(0.25, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T)},
	{FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T)},
	{FPM_InitFixedPoint_m(0.75, u2p14_T),
	 FPM_InitFixedPoint_m(0.75, u2p14_T),
	 FPM_InitFixedPoint_m(0.75, u2p14_T),
	 FPM_InitFixedPoint_m(0.75, u2p14_T),
	 FPM_InitFixedPoint_m(0.75, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)}}, {{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(0.25, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T),
	 FPM_InitFixedPoint_m(0.25, u2p14_T)},
	{FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T)},
	{FPM_InitFixedPoint_m(0.75, u2p14_T),
	 FPM_InitFixedPoint_m(0.75, u2p14_T),
	 FPM_InitFixedPoint_m(0.75, u2p14_T),
	 FPM_InitFixedPoint_m(0.75, u2p14_T),
	 FPM_InitFixedPoint_m(0.75, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)}}, TRUE, FPM_InitFixedPoint_m(0.0390625, u9p7_T), FPM_InitFixedPoint_m(0.0390625, u9p7_T), {FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.242188, u9p7_T),
	 FPM_InitFixedPoint_m(1.828125, u9p7_T),
	 FPM_InitFixedPoint_m(0.0, u9p7_T)}, {FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.242188, u9p7_T),
	 FPM_InitFixedPoint_m(1.828125, u9p7_T),
	 FPM_InitFixedPoint_m(0.0, u9p7_T)}, {FPM_InitFixedPoint_m(1.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(0.34375, u9p7_T),
	 FPM_InitFixedPoint_m(0.34375, u9p7_T)}, {FPM_InitFixedPoint_m(0.96875, u9p7_T),
	 FPM_InitFixedPoint_m(0.96875, u9p7_T),
	 FPM_InitFixedPoint_m(0.96875, u9p7_T),
	 FPM_InitFixedPoint_m(0.3125, u9p7_T),
	 FPM_InitFixedPoint_m(0.3125, u9p7_T)}, {FPM_InitFixedPoint_m(0.0155029, u3p13_T),
	 FPM_InitFixedPoint_m(0.0155029, u3p13_T),
	 FPM_InitFixedPoint_m(0.0155029, u3p13_T),
	 FPM_InitFixedPoint_m(0.198975, u3p13_T),
	 FPM_InitFixedPoint_m(0.198975, u3p13_T)}, {FPM_InitFixedPoint_m(0.016235, u3p13_T),
	 FPM_InitFixedPoint_m(0.016235, u3p13_T),
	 FPM_InitFixedPoint_m(0.016235, u3p13_T),
	 FPM_InitFixedPoint_m(0.021973, u3p13_T),
	 FPM_InitFixedPoint_m(0.021973, u3p13_T)}, {FPM_InitFixedPoint_m(0.019409, u3p13_T),
	 FPM_InitFixedPoint_m(0.019409, u3p13_T),
	 FPM_InitFixedPoint_m(0.019409, u3p13_T),
	 FPM_InitFixedPoint_m(0.034302, u3p13_T),
	 FPM_InitFixedPoint_m(0.034302, u3p13_T)}, {FPM_InitFixedPoint_m(0.020386, u3p13_T),
	 FPM_InitFixedPoint_m(0.020386, u3p13_T),
	 FPM_InitFixedPoint_m(0.020386, u3p13_T),
	 FPM_InitFixedPoint_m(0.037842, u3p13_T),
	 FPM_InitFixedPoint_m(0.037842, u3p13_T)}, {FPM_InitFixedPoint_m(0.024292, u3p13_T),
	 FPM_InitFixedPoint_m(0.024292, u3p13_T),
	 FPM_InitFixedPoint_m(0.024292, u3p13_T),
	 FPM_InitFixedPoint_m(0.1564941, u3p13_T),
	 FPM_InitFixedPoint_m(0.1564941, u3p13_T)}, {FPM_InitFixedPoint_m(0.025635, u3p13_T),
	 FPM_InitFixedPoint_m(0.025635, u3p13_T),
	 FPM_InitFixedPoint_m(0.025635, u3p13_T),
	 FPM_InitFixedPoint_m(0.208374, u3p13_T),
	 FPM_InitFixedPoint_m(0.208374, u3p13_T)}, {FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T)}, {FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T)}, {FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(1.16394, u3p13_T),
	 FPM_InitFixedPoint_m(1.16394, u3p13_T)}, {FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(0.121826, u3p13_T),
	 FPM_InitFixedPoint_m(1.16394, u3p13_T),
	 FPM_InitFixedPoint_m(1.16394, u3p13_T)}, {FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T)}, {FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T),
	 FPM_InitFixedPoint_m(0.000122, u3p13_T)}, {FPM_InitFixedPoint_m(-40.0, s15p0_T),
	 FPM_InitFixedPoint_m(0.0, s15p0_T), FPM_InitFixedPoint_m(83.0, s15p0_T),
	 FPM_InitFixedPoint_m(84.0, s15p0_T),
	 FPM_InitFixedPoint_m(85.0, s15p0_T)}, {FPM_InitFixedPoint_m(0.0, u16p0_T),
	 FPM_InitFixedPoint_m(76.0, u16p0_T),
	 FPM_InitFixedPoint_m(80.0, u16p0_T),
	 FPM_InitFixedPoint_m(84.0, u16p0_T),
	 FPM_InitFixedPoint_m(88.0, u16p0_T),
	 FPM_InitFixedPoint_m(92.0, u16p0_T),
	 FPM_InitFixedPoint_m(96.0, u16p0_T),
	 FPM_InitFixedPoint_m(100.0, u16p0_T)}, {FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.703125, u9p7_T),
	 FPM_InitFixedPoint_m(2.242188, u9p7_T),
	 FPM_InitFixedPoint_m(1.828125, u9p7_T),
	 FPM_InitFixedPoint_m(1.414063, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T)}, { FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(50.0, u12p4_T),FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(150.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T)}, { FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(50.0, u12p4_T),FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(150.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T)}, {FPM_InitFixedPoint_m(0.0, u4p12_T),FPM_InitFixedPoint_m(0.0, u4p12_T),
	FPM_InitFixedPoint_m(0.0, u4p12_T),FPM_InitFixedPoint_m(0.0, u4p12_T),
	FPM_InitFixedPoint_m(0.0, u4p12_T),FPM_InitFixedPoint_m(0.0, u4p12_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(2.0, u9p7_T),
	FPM_InitFixedPoint_m(10.0, u9p7_T),FPM_InitFixedPoint_m(25.0, u9p7_T),
	FPM_InitFixedPoint_m(40.0, u9p7_T),FPM_InitFixedPoint_m(60.0, u9p7_T)}, {{FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T)},
	{FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T)},
	{FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T)},
	{FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T)},
	{FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T)},
	{FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T),
	FPM_InitFixedPoint_m(8.8, u4p12_T),FPM_InitFixedPoint_m(8.8, u4p12_T)}}, {FPM_InitFixedPoint_m(0.1, u8p8_T),FPM_InitFixedPoint_m(0.1, u8p8_T),
	FPM_InitFixedPoint_m(0.1, u8p8_T),FPM_InitFixedPoint_m(0.1, u8p8_T),
	FPM_InitFixedPoint_m(0.1, u8p8_T),FPM_InitFixedPoint_m(0.1, u8p8_T)}, {FPM_InitFixedPoint_m(100.0, u8p8_T),
	FPM_InitFixedPoint_m(100.0, u8p8_T),FPM_InitFixedPoint_m(100.0, u8p8_T),
	FPM_InitFixedPoint_m(100.0, u8p8_T),FPM_InitFixedPoint_m(100.0, u8p8_T),
	FPM_InitFixedPoint_m(100.0, u8p8_T)}, -4400.0f, 4400.0f, TRUE, {FPM_InitFixedPoint_m(0.3, u5p11_T),FPM_InitFixedPoint_m(0.3, u5p11_T),
	FPM_InitFixedPoint_m(0.3, u5p11_T),FPM_InitFixedPoint_m(0.3, u5p11_T),
	FPM_InitFixedPoint_m(0.3, u5p11_T),FPM_InitFixedPoint_m(0.3, u5p11_T),
	FPM_InitFixedPoint_m(0.3, u5p11_T),FPM_InitFixedPoint_m(0.3, u5p11_T),
	FPM_InitFixedPoint_m(0.3, u5p11_T),FPM_InitFixedPoint_m(0.3, u5p11_T),
	FPM_InitFixedPoint_m(0.3, u5p11_T)}, {FPM_InitFixedPoint_m(10.0, u12p4_T),
	FPM_InitFixedPoint_m(14.0, u12p4_T),FPM_InitFixedPoint_m(18.0, u12p4_T),
	FPM_InitFixedPoint_m(22.0, u12p4_T),FPM_InitFixedPoint_m(26.0, u12p4_T),
	FPM_InitFixedPoint_m(30.0, u12p4_T),FPM_InitFixedPoint_m(34.0, u12p4_T),
	FPM_InitFixedPoint_m(38.0, u12p4_T),FPM_InitFixedPoint_m(42.0, u12p4_T),
	FPM_InitFixedPoint_m(46.0, u12p4_T),FPM_InitFixedPoint_m(50.0, u12p4_T)}, 0UL, FALSE, FPM_InitFixedPoint_m(140.0, u12p4_T), FPM_InitFixedPoint_m(120.0, u12p4_T), { FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(25.0, u9p7_T),
	 FPM_InitFixedPoint_m(50.0, u9p7_T), FPM_InitFixedPoint_m(65.0, u9p7_T),
	 FPM_InitFixedPoint_m(75.0, u9p7_T) }, { FPM_InitFixedPoint_m(8.8, u5p11_T),FPM_InitFixedPoint_m(8.8, u5p11_T),
	FPM_InitFixedPoint_m(8.8, u5p11_T),FPM_InitFixedPoint_m(8.8, u5p11_T),
	FPM_InitFixedPoint_m(8.8, u5p11_T) }, {FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.15, u8p8_T),
	 FPM_InitFixedPoint_m(0.3, u8p8_T), FPM_InitFixedPoint_m(0.4, u8p8_T),
	 FPM_InitFixedPoint_m(0.6, u8p8_T), FPM_InitFixedPoint_m(0.8, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.3, u8p8_T),
	 FPM_InitFixedPoint_m(1.55, u8p8_T), FPM_InitFixedPoint_m(1.8, u8p8_T),
	 FPM_InitFixedPoint_m(2.05, u8p8_T), FPM_InitFixedPoint_m(2.3, u8p8_T),
	 FPM_InitFixedPoint_m(2.55, u8p8_T), FPM_InitFixedPoint_m(2.8, u8p8_T),
	 FPM_InitFixedPoint_m(3.05, u8p8_T), FPM_InitFixedPoint_m(3.3, u8p8_T),
	 FPM_InitFixedPoint_m(3.55, u8p8_T), FPM_InitFixedPoint_m(3.8, u8p8_T),
	 FPM_InitFixedPoint_m(5.0, u8p8_T), FPM_InitFixedPoint_m(10.0, u8p8_T)}, {FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015, s4p11_T),
	 FPM_InitFixedPoint_m(0.028, s4p11_T),
	 FPM_InitFixedPoint_m(0.065, s4p11_T),
	 FPM_InitFixedPoint_m(0.11, s4p11_T),
	 FPM_InitFixedPoint_m(0.158, s4p11_T),
	 FPM_InitFixedPoint_m(0.24, s4p11_T),
	 FPM_InitFixedPoint_m(0.32, s4p11_T),
	 FPM_InitFixedPoint_m(0.41, s4p11_T),
	 FPM_InitFixedPoint_m(0.51, s4p11_T),
	 FPM_InitFixedPoint_m(0.62, s4p11_T),
	 FPM_InitFixedPoint_m(0.74, s4p11_T),
	 FPM_InitFixedPoint_m(0.86, s4p11_T), FPM_InitFixedPoint_m(1.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.15, s4p11_T),
	 FPM_InitFixedPoint_m(1.31, s4p11_T),
	 FPM_InitFixedPoint_m(1.47, s4p11_T), FPM_InitFixedPoint_m(2.3, s4p11_T),
	 FPM_InitFixedPoint_m(5.7, s4p11_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(5.0, u9p7_T),
	 FPM_InitFixedPoint_m(30.0, u9p7_T), FPM_InitFixedPoint_m(60.0, u9p7_T),
	 FPM_InitFixedPoint_m(80.0, u9p7_T), FPM_InitFixedPoint_m(100.0, u9p7_T),
	 FPM_InitFixedPoint_m(120.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T),
	 FPM_InitFixedPoint_m(248.0, u9p7_T),
	 FPM_InitFixedPoint_m(249.0, u9p7_T)}, { FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(5.0, u9p7_T),
	 FPM_InitFixedPoint_m(15.0, u9p7_T), FPM_InitFixedPoint_m(30.0, u9p7_T),
	 FPM_InitFixedPoint_m(60.0, u9p7_T), FPM_InitFixedPoint_m(80.0, u9p7_T),
	 FPM_InitFixedPoint_m(100.0, u9p7_T),
	 FPM_InitFixedPoint_m(120.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T),
	 FPM_InitFixedPoint_m(180.0, u9p7_T),
	 FPM_InitFixedPoint_m(200.0, u9p7_T),
	 FPM_InitFixedPoint_m(220.0, u9p7_T) }, { FPM_InitFixedPoint_m(8.8, u4p12_T),
	 FPM_InitFixedPoint_m(8.8, u4p12_T), FPM_InitFixedPoint_m(8.8, u4p12_T),
	 FPM_InitFixedPoint_m(8.8, u4p12_T), FPM_InitFixedPoint_m(8.8, u4p12_T),
	 FPM_InitFixedPoint_m(8.8, u4p12_T), FPM_InitFixedPoint_m(8.8, u4p12_T),
	 FPM_InitFixedPoint_m(8.8, u4p12_T), FPM_InitFixedPoint_m(8.8, u4p12_T),
	 FPM_InitFixedPoint_m(8.8, u4p12_T), FPM_InitFixedPoint_m(8.8, u4p12_T),
	 FPM_InitFixedPoint_m(8.8, u4p12_T) }, { FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T) }, { FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T) }, { FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T) }, { FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T) }, {FPM_InitFixedPoint_m(-400.0, s11p4_T),
	 FPM_InitFixedPoint_m(-100.0, s11p4_T),
	 FPM_InitFixedPoint_m(0.0, s11p4_T), FPM_InitFixedPoint_m(50.0, s11p4_T),
	 FPM_InitFixedPoint_m(100.0, s11p4_T),
	 FPM_InitFixedPoint_m(150.0, s11p4_T),
	 FPM_InitFixedPoint_m(200.0, s11p4_T),
	 FPM_InitFixedPoint_m(250.0, s11p4_T),
	 FPM_InitFixedPoint_m(300.0, s11p4_T),
	 FPM_InitFixedPoint_m(350.0, s11p4_T),
	 FPM_InitFixedPoint_m(400.0, s11p4_T)}, {{FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)}}, {{FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)},
	 {FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T), FPM_InitFixedPoint_m(16.0, s7p8_T),
	 FPM_InitFixedPoint_m(16.0, s7p8_T)}}, {{FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)},
	 {FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T),
	 FPM_InitFixedPoint_m(15.99951171875, s4p11_T)}} };

#pragma DATA_SECTION(k_TunPer0_Cnt_Str, ".TunPer0");
CONST(TUNING_P_Str, CAL_CONST)k_TunPer0_Cnt_Str = { 0U, {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U}, {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U}, {0U, 0U, 200U, 300U, 400U, 500U, 600U, 700U, 800U, 900U, 1000U}, {0U, 0U, 200U,  300U, 400U, 500U, 600U, 700U, 800U, 900U, 1000U}, {FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T),
	 FPM_InitFixedPoint_m(0.83, u11p5_T)}, {FPM_InitFixedPoint_m(0.0, u11p5_T),
	 FPM_InitFixedPoint_m(25.0, u11p5_T),
	 FPM_InitFixedPoint_m(50.0, u11p5_T),
	 FPM_InitFixedPoint_m(75.0, u11p5_T),
	 FPM_InitFixedPoint_m(100.0, u11p5_T),
	 FPM_InitFixedPoint_m(125.0, u11p5_T),
	 FPM_InitFixedPoint_m(150.0, u11p5_T),
	 FPM_InitFixedPoint_m(175.0, u11p5_T),
	 FPM_InitFixedPoint_m(200.0, u11p5_T),
	 FPM_InitFixedPoint_m(250.0, u11p5_T)}, {{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T)},
	 {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)},
	 {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)},
	 {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)},
	 {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)},
	 {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)},
	 {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)},
	 {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)},
	 {FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T)},{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.3, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T)}}, {{25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U},
	 {25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U}, {25U,
	 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U}, {25U, 25U,
	 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U}, {25U, 25U, 25U,
	 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U}, {25U, 25U, 25U, 25U,
	 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U}, {25U, 25U, 25U, 25U, 25U,
	 25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U}, {25U, 25U, 25U, 25U, 25U, 25U,
	 25U, 25U, 25U, 25U, 25U, 25U, 25U}, {25U, 25U, 25U, 25U, 25U, 25U, 25U,
	 25U, 25U, 25U, 25U, 25U, 25U},{25U, 25U, 25U, 25U, 25U, 25U, 25U, 25U,
	 25U, 25U, 25U, 25U, 25U}}, FALSE, FALSE, FALSE, -500.0f, 500.0f, FALSE, FALSE, {FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.5, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)}, {FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.5, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T)}, {FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(10.0, u12p4_T),
	FPM_InitFixedPoint_m(20.0, u12p4_T),FPM_InitFixedPoint_m(40.0, u12p4_T),
	FPM_InitFixedPoint_m(41.0, u12p4_T),FPM_InitFixedPoint_m(90.0, u12p4_T),
	FPM_InitFixedPoint_m(180.0, u12p4_T),
	FPM_InitFixedPoint_m(360.0, u12p4_T),
	FPM_InitFixedPoint_m(1000.0, u12p4_T)}, {FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(10.0, u9p7_T),
	FPM_InitFixedPoint_m(30.0, u9p7_T),FPM_InitFixedPoint_m(50.0, u9p7_T),
	FPM_InitFixedPoint_m(80.0, u9p7_T)}, {FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(2.5, u9p7_T),
	FPM_InitFixedPoint_m(5.0, u9p7_T),FPM_InitFixedPoint_m(20.0, u9p7_T),
	FPM_InitFixedPoint_m(30.0, u9p7_T),FPM_InitFixedPoint_m(50.0, u9p7_T),
	FPM_InitFixedPoint_m(60.0, u9p7_T),FPM_InitFixedPoint_m(80.0, u9p7_T)}, {FPM_InitFixedPoint_m(-200.0, s10p5_T),
	FPM_InitFixedPoint_m(0.0, s10p5_T),FPM_InitFixedPoint_m(20.0, s10p5_T),
	FPM_InitFixedPoint_m(50.0, s10p5_T),FPM_InitFixedPoint_m(100.0, s10p5_T),
	FPM_InitFixedPoint_m(200.0, s10p5_T),
	FPM_InitFixedPoint_m(250.0, s10p5_T),
	FPM_InitFixedPoint_m(800.0, s10p5_T)}, {FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(10.0, u12p4_T),
	FPM_InitFixedPoint_m(20.0, u12p4_T),FPM_InitFixedPoint_m(30.0, u12p4_T),
	FPM_InitFixedPoint_m(50.0, u12p4_T),FPM_InitFixedPoint_m(80.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)}, {FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.7, u2p14_T),
	FPM_InitFixedPoint_m(0.7, u2p14_T)}, {{FPM_InitFixedPoint_m(0.0, u10p6_T),
	 FPM_InitFixedPoint_m(140.0, u10p6_T),
	 FPM_InitFixedPoint_m(165.0, u10p6_T),
	 FPM_InitFixedPoint_m(190.0, u10p6_T),
	 FPM_InitFixedPoint_m(215.0, u10p6_T),
	 FPM_InitFixedPoint_m(240.0, u10p6_T),
	 FPM_InitFixedPoint_m(290.0, u10p6_T),
	 FPM_InitFixedPoint_m(340.0, u10p6_T),
	 FPM_InitFixedPoint_m(390.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	 FPM_InitFixedPoint_m(140.0, u10p6_T),
	 FPM_InitFixedPoint_m(165.0, u10p6_T),
	 FPM_InitFixedPoint_m(190.0, u10p6_T),
	 FPM_InitFixedPoint_m(215.0, u10p6_T),
	 FPM_InitFixedPoint_m(240.0, u10p6_T),
	 FPM_InitFixedPoint_m(290.0, u10p6_T),
	 FPM_InitFixedPoint_m(340.0, u10p6_T),
	 FPM_InitFixedPoint_m(390.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	 FPM_InitFixedPoint_m(140.0, u10p6_T),
	 FPM_InitFixedPoint_m(165.0, u10p6_T),
	 FPM_InitFixedPoint_m(190.0, u10p6_T),
	 FPM_InitFixedPoint_m(215.0, u10p6_T),
	 FPM_InitFixedPoint_m(240.0, u10p6_T),
	 FPM_InitFixedPoint_m(290.0, u10p6_T),
	 FPM_InitFixedPoint_m(340.0, u10p6_T),
	 FPM_InitFixedPoint_m(390.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	 FPM_InitFixedPoint_m(140.0, u10p6_T),
	 FPM_InitFixedPoint_m(165.0, u10p6_T),
	 FPM_InitFixedPoint_m(190.0, u10p6_T),
	 FPM_InitFixedPoint_m(215.0, u10p6_T),
	 FPM_InitFixedPoint_m(240.0, u10p6_T),
	 FPM_InitFixedPoint_m(290.0, u10p6_T),
	 FPM_InitFixedPoint_m(340.0, u10p6_T),
	 FPM_InitFixedPoint_m(390.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	 FPM_InitFixedPoint_m(140.0, u10p6_T),
	 FPM_InitFixedPoint_m(165.0, u10p6_T),
	 FPM_InitFixedPoint_m(190.0, u10p6_T),
	 FPM_InitFixedPoint_m(215.0, u10p6_T),
	 FPM_InitFixedPoint_m(240.0, u10p6_T),
	 FPM_InitFixedPoint_m(290.0, u10p6_T),
	 FPM_InitFixedPoint_m(340.0, u10p6_T),
	 FPM_InitFixedPoint_m(390.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	 FPM_InitFixedPoint_m(250.0, u10p6_T),
	 FPM_InitFixedPoint_m(275.0, u10p6_T),
	 FPM_InitFixedPoint_m(300.0, u10p6_T),
	 FPM_InitFixedPoint_m(325.0, u10p6_T),
	 FPM_InitFixedPoint_m(350.0, u10p6_T),
	 FPM_InitFixedPoint_m(400.0, u10p6_T),
	 FPM_InitFixedPoint_m(450.0, u10p6_T),
	 FPM_InitFixedPoint_m(500.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	 FPM_InitFixedPoint_m(140.0, u10p6_T),
	 FPM_InitFixedPoint_m(165.0, u10p6_T),
	 FPM_InitFixedPoint_m(190.0, u10p6_T),
	 FPM_InitFixedPoint_m(215.0, u10p6_T),
	 FPM_InitFixedPoint_m(240.0, u10p6_T),
	 FPM_InitFixedPoint_m(290.0, u10p6_T),
	 FPM_InitFixedPoint_m(340.0, u10p6_T),
	 FPM_InitFixedPoint_m(390.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	 FPM_InitFixedPoint_m(140.0, u10p6_T),
	 FPM_InitFixedPoint_m(165.0, u10p6_T),
	 FPM_InitFixedPoint_m(190.0, u10p6_T),
	 FPM_InitFixedPoint_m(215.0, u10p6_T),
	 FPM_InitFixedPoint_m(240.0, u10p6_T),
	 FPM_InitFixedPoint_m(290.0, u10p6_T),
	 FPM_InitFixedPoint_m(340.0, u10p6_T),
	 FPM_InitFixedPoint_m(390.0, u10p6_T)}}, {{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T)},{FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T)},{FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T), FPM_InitFixedPoint_m(0.0, u6p10_T),
	 FPM_InitFixedPoint_m(1.0127, u6p10_T),
	 FPM_InitFixedPoint_m(4.2529, u6p10_T),
	 FPM_InitFixedPoint_m(9.5068, u6p10_T),
	FPM_InitFixedPoint_m(16.0117, u6p10_T),
	FPM_InitFixedPoint_m(32.3994, u6p10_T),
	FPM_InitFixedPoint_m(32.3994, u6p10_T),
	FPM_InitFixedPoint_m(32.3994, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(1.125, u6p10_T),
	 FPM_InitFixedPoint_m(4.7256, u6p10_T),
	FPM_InitFixedPoint_m(10.5635, u6p10_T),
	 FPM_InitFixedPoint_m(17.791, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(1.125, u6p10_T),
	 FPM_InitFixedPoint_m(4.7256, u6p10_T),
	FPM_InitFixedPoint_m(10.5635, u6p10_T),
	 FPM_InitFixedPoint_m(17.791, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T)},
	{FPM_InitFixedPoint_m(0.0, u6p10_T),FPM_InitFixedPoint_m(0.0, u6p10_T),
	FPM_InitFixedPoint_m(1.125, u6p10_T),
	 FPM_InitFixedPoint_m(4.7256, u6p10_T),
	FPM_InitFixedPoint_m(10.5635, u6p10_T),
	 FPM_InitFixedPoint_m(17.791, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T),
	 FPM_InitFixedPoint_m(35.999, u6p10_T)}}, {{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)}}, {{FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(16.3125, u12p4_T),
	FPM_InitFixedPoint_m(28.1875, u12p4_T),
	FPM_InitFixedPoint_m(48.5, u12p4_T),
	FPM_InitFixedPoint_m(62.125, u12p4_T),
	FPM_InitFixedPoint_m(76.25, u12p4_T),
	FPM_InitFixedPoint_m(90.0625, u12p4_T),
	FPM_InitFixedPoint_m(110.4375, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(16.3125, u12p4_T),
	FPM_InitFixedPoint_m(28.1875, u12p4_T),
	FPM_InitFixedPoint_m(48.5, u12p4_T),
	FPM_InitFixedPoint_m(62.125, u12p4_T),
	FPM_InitFixedPoint_m(76.25, u12p4_T),
	FPM_InitFixedPoint_m(90.0625, u12p4_T),
	FPM_InitFixedPoint_m(110.4375, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(16.3125, u12p4_T),
	FPM_InitFixedPoint_m(28.1875, u12p4_T),
	FPM_InitFixedPoint_m(48.5, u12p4_T),
	FPM_InitFixedPoint_m(62.125, u12p4_T),
	FPM_InitFixedPoint_m(76.25, u12p4_T),
	FPM_InitFixedPoint_m(90.0625, u12p4_T),
	FPM_InitFixedPoint_m(110.4375, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(16.3125, u12p4_T),
	FPM_InitFixedPoint_m(28.1875, u12p4_T),
	FPM_InitFixedPoint_m(48.5, u12p4_T),
	FPM_InitFixedPoint_m(62.125, u12p4_T),
	FPM_InitFixedPoint_m(76.25, u12p4_T),
	FPM_InitFixedPoint_m(90.0625, u12p4_T),
	FPM_InitFixedPoint_m(110.4375, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(16.3125, u12p4_T),
	FPM_InitFixedPoint_m(28.1875, u12p4_T),
	FPM_InitFixedPoint_m(48.5, u12p4_T),
	FPM_InitFixedPoint_m(62.125, u12p4_T),
	FPM_InitFixedPoint_m(76.25, u12p4_T),
	FPM_InitFixedPoint_m(90.0625, u12p4_T),
	FPM_InitFixedPoint_m(110.4375, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(16.3125, u12p4_T),
	FPM_InitFixedPoint_m(28.1875, u12p4_T),
	FPM_InitFixedPoint_m(48.5, u12p4_T),
	FPM_InitFixedPoint_m(62.125, u12p4_T),
	FPM_InitFixedPoint_m(76.25, u12p4_T),
	FPM_InitFixedPoint_m(90.0625, u12p4_T),
	FPM_InitFixedPoint_m(110.4375, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(16.3125, u12p4_T),
	FPM_InitFixedPoint_m(28.1875, u12p4_T),
	FPM_InitFixedPoint_m(48.5, u12p4_T),
	FPM_InitFixedPoint_m(62.125, u12p4_T),
	FPM_InitFixedPoint_m(76.25, u12p4_T),
	FPM_InitFixedPoint_m(90.0625, u12p4_T),
	FPM_InitFixedPoint_m(110.4375, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T),
	FPM_InitFixedPoint_m(16.3125, u12p4_T),
	FPM_InitFixedPoint_m(28.1875, u12p4_T),
	FPM_InitFixedPoint_m(48.5, u12p4_T),
	FPM_InitFixedPoint_m(62.125, u12p4_T),
	FPM_InitFixedPoint_m(76.25, u12p4_T),
	FPM_InitFixedPoint_m(90.0625, u12p4_T),
	FPM_InitFixedPoint_m(110.4375, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T),
	FPM_InitFixedPoint_m(450.0, u12p4_T)}}, {{FPM_InitFixedPoint_m(0.0, u10p6_T),FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(0.0, u10p6_T),FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(0.0, u10p6_T),FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(0.0, u10p6_T),FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(0.0, u10p6_T),FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(0.0, u10p6_T),FPM_InitFixedPoint_m(0.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(27.9375, u10p6_T),
	FPM_InitFixedPoint_m(52.8906, u10p6_T),
	FPM_InitFixedPoint_m(83.6406, u10p6_T),
	FPM_InitFixedPoint_m(106.3281, u10p6_T),
	FPM_InitFixedPoint_m(126.3906, u10p6_T),
	FPM_InitFixedPoint_m(139.8906, u10p6_T),
	FPM_InitFixedPoint_m(144.6719, u10p6_T),
	FPM_InitFixedPoint_m(144.6719, u10p6_T),
	FPM_InitFixedPoint_m(144.6719, u10p6_T),
	FPM_InitFixedPoint_m(144.6719, u10p6_T),
	FPM_InitFixedPoint_m(144.6719, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(38.2188, u10p6_T),
	FPM_InitFixedPoint_m(72.3438, u10p6_T),
	FPM_InitFixedPoint_m(114.4219, u10p6_T),
	FPM_InitFixedPoint_m(145.4531, u10p6_T),
	FPM_InitFixedPoint_m(172.9063, u10p6_T),
	FPM_InitFixedPoint_m(191.3594, u10p6_T),
	FPM_InitFixedPoint_m(197.9063, u10p6_T),
	FPM_InitFixedPoint_m(197.9063, u10p6_T),
	FPM_InitFixedPoint_m(197.9063, u10p6_T),
	FPM_InitFixedPoint_m(197.9063, u10p6_T),
	FPM_InitFixedPoint_m(197.9063, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(48.2813, u10p6_T),
	FPM_InitFixedPoint_m(91.3906, u10p6_T),
	FPM_InitFixedPoint_m(144.5156, u10p6_T),
	FPM_InitFixedPoint_m(183.7344, u10p6_T),
	FPM_InitFixedPoint_m(218.4063, u10p6_T),
	FPM_InitFixedPoint_m(241.7188, u10p6_T),
	FPM_InitFixedPoint_m(250.0, u10p6_T),
	FPM_InitFixedPoint_m(250.0, u10p6_T),
	FPM_InitFixedPoint_m(250.0, u10p6_T),
	FPM_InitFixedPoint_m(250.0, u10p6_T),
	FPM_InitFixedPoint_m(250.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(57.9375, u10p6_T),
	FPM_InitFixedPoint_m(109.6719, u10p6_T),
	FPM_InitFixedPoint_m(173.4219, u10p6_T),
	FPM_InitFixedPoint_m(220.4844, u10p6_T),
	FPM_InitFixedPoint_m(262.0938, u10p6_T),
	FPM_InitFixedPoint_m(290.0625, u10p6_T),
	FPM_InitFixedPoint_m(300.0, u10p6_T),
	FPM_InitFixedPoint_m(300.0, u10p6_T),
	FPM_InitFixedPoint_m(300.0, u10p6_T),
	FPM_InitFixedPoint_m(300.0, u10p6_T),
	FPM_InitFixedPoint_m(300.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(83.4375, u10p6_T),
	FPM_InitFixedPoint_m(157.9375, u10p6_T),
	FPM_InitFixedPoint_m(249.7344, u10p6_T),
	FPM_InitFixedPoint_m(317.5, u10p6_T),
	FPM_InitFixedPoint_m(377.4219, u10p6_T),
	FPM_InitFixedPoint_m(417.6875, u10p6_T),
	FPM_InitFixedPoint_m(432.0, u10p6_T),
	FPM_InitFixedPoint_m(432.0, u10p6_T),
	FPM_InitFixedPoint_m(432.0, u10p6_T),
	FPM_InitFixedPoint_m(432.0, u10p6_T),
	FPM_InitFixedPoint_m(432.0, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(100.125, u10p6_T),
	FPM_InitFixedPoint_m(189.5313, u10p6_T),
	FPM_InitFixedPoint_m(299.6875, u10p6_T),
	FPM_InitFixedPoint_m(381.0, u10p6_T),
	FPM_InitFixedPoint_m(452.9063, u10p6_T),
	FPM_InitFixedPoint_m(501.2188, u10p6_T),
	FPM_InitFixedPoint_m(518.4063, u10p6_T),
	FPM_InitFixedPoint_m(518.4063, u10p6_T),
	FPM_InitFixedPoint_m(518.4063, u10p6_T),
	FPM_InitFixedPoint_m(518.4063, u10p6_T),
	FPM_InitFixedPoint_m(518.4063, u10p6_T)},
	{FPM_InitFixedPoint_m(0.0, u10p6_T),
	FPM_InitFixedPoint_m(114.1563, u10p6_T),
	FPM_InitFixedPoint_m(216.0625, u10p6_T),
	FPM_InitFixedPoint_m(341.6406, u10p6_T),
	FPM_InitFixedPoint_m(434.3438, u10p6_T),
	FPM_InitFixedPoint_m(516.3125, u10p6_T),
	FPM_InitFixedPoint_m(571.3906, u10p6_T),
	FPM_InitFixedPoint_m(590.9844, u10p6_T),
	FPM_InitFixedPoint_m(590.9844, u10p6_T),
	FPM_InitFixedPoint_m(590.9844, u10p6_T),
	FPM_InitFixedPoint_m(590.9844, u10p6_T),
	FPM_InitFixedPoint_m(590.9844, u10p6_T)}}, {{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)}}, {{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.3984, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.6016, u8p8_T),
	FPM_InitFixedPoint_m(0.7109, u8p8_T),
	FPM_InitFixedPoint_m(1.3164, u8p8_T),
	FPM_InitFixedPoint_m(1.6094, u8p8_T),
	FPM_InitFixedPoint_m(2.0352, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(8.0, u8p8_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.9809, u2p14_T),
	FPM_InitFixedPoint_m(0.9485, u2p14_T),
	FPM_InitFixedPoint_m(0.8847, u2p14_T),
	FPM_InitFixedPoint_m(0.5706, u2p14_T),
	FPM_InitFixedPoint_m(0.4092, u2p14_T),
	FPM_InitFixedPoint_m(0.1902, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T)}}, {{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.5, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.5, u8p8_T),
	FPM_InitFixedPoint_m(3.0, u8p8_T),FPM_InitFixedPoint_m(3.5, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(10.0, u8p8_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.6, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.6, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(0.6, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T),
	FPM_InitFixedPoint_m(0.0, u2p14_T),FPM_InitFixedPoint_m(0.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T)}}, {{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(20.0, u8p8_T),
	FPM_InitFixedPoint_m(25.0, u8p8_T),FPM_InitFixedPoint_m(30.0, u8p8_T),
	FPM_InitFixedPoint_m(35.0, u8p8_T),FPM_InitFixedPoint_m(40.0, u8p8_T),
	FPM_InitFixedPoint_m(45.0, u8p8_T),FPM_InitFixedPoint_m(50.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(20.0, u8p8_T),
	FPM_InitFixedPoint_m(25.0, u8p8_T),FPM_InitFixedPoint_m(30.0, u8p8_T),
	FPM_InitFixedPoint_m(35.0, u8p8_T),FPM_InitFixedPoint_m(40.0, u8p8_T),
	FPM_InitFixedPoint_m(45.0, u8p8_T),FPM_InitFixedPoint_m(50.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(20.0, u8p8_T),
	FPM_InitFixedPoint_m(25.0, u8p8_T),FPM_InitFixedPoint_m(30.0, u8p8_T),
	FPM_InitFixedPoint_m(35.0, u8p8_T),FPM_InitFixedPoint_m(40.0, u8p8_T),
	FPM_InitFixedPoint_m(45.0, u8p8_T),FPM_InitFixedPoint_m(50.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(20.0, u8p8_T),
	FPM_InitFixedPoint_m(25.0, u8p8_T),FPM_InitFixedPoint_m(30.0, u8p8_T),
	FPM_InitFixedPoint_m(35.0, u8p8_T),FPM_InitFixedPoint_m(40.0, u8p8_T),
	FPM_InitFixedPoint_m(45.0, u8p8_T),FPM_InitFixedPoint_m(50.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(20.0, u8p8_T),
	FPM_InitFixedPoint_m(25.0, u8p8_T),FPM_InitFixedPoint_m(30.0, u8p8_T),
	FPM_InitFixedPoint_m(35.0, u8p8_T),FPM_InitFixedPoint_m(40.0, u8p8_T),
	FPM_InitFixedPoint_m(45.0, u8p8_T),FPM_InitFixedPoint_m(50.0, u8p8_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.8, u2p14_T),FPM_InitFixedPoint_m(0.5, u2p14_T),
	FPM_InitFixedPoint_m(0.3, u2p14_T),FPM_InitFixedPoint_m(0.3, u2p14_T),
	FPM_InitFixedPoint_m(0.3, u2p14_T),FPM_InitFixedPoint_m(0.3, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.8, u2p14_T),FPM_InitFixedPoint_m(0.5, u2p14_T),
	FPM_InitFixedPoint_m(0.3, u2p14_T),FPM_InitFixedPoint_m(0.3, u2p14_T),
	FPM_InitFixedPoint_m(0.3, u2p14_T),FPM_InitFixedPoint_m(0.3, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.8, u2p14_T),FPM_InitFixedPoint_m(0.5, u2p14_T),
	FPM_InitFixedPoint_m(0.3, u2p14_T),FPM_InitFixedPoint_m(0.3, u2p14_T),
	FPM_InitFixedPoint_m(0.3, u2p14_T),FPM_InitFixedPoint_m(0.3, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.8, u2p14_T),FPM_InitFixedPoint_m(0.7, u2p14_T),
	FPM_InitFixedPoint_m(0.4, u2p14_T),FPM_InitFixedPoint_m(0.4, u2p14_T),
	FPM_InitFixedPoint_m(0.4, u2p14_T),FPM_InitFixedPoint_m(0.4, u2p14_T)},
	{FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(0.8, u2p14_T),FPM_InitFixedPoint_m(0.7, u2p14_T),
	FPM_InitFixedPoint_m(0.4, u2p14_T),FPM_InitFixedPoint_m(0.4, u2p14_T),
	FPM_InitFixedPoint_m(0.4, u2p14_T),FPM_InitFixedPoint_m(0.4, u2p14_T)}}, {{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(0.8, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.7, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(0.8, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(0.8, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(0.8, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.3, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)}}, { FPM_InitFixedPoint_m(8.0, u8p8_T),
	 FPM_InitFixedPoint_m(10.0, u8p8_T) }, { FPM_InitFixedPoint_m(1.0, u1p15_T),
	  FPM_InitFixedPoint_m(0.0, u1p15_T) }, { FPM_InitFixedPoint_m(0.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T) }, { FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(0.0, u9p7_T),
	 FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(0.0, u9p7_T),
	 FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(0.0, u9p7_T),
	 FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(0.0, u9p7_T) }, {{FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T)},
	{FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T)}}, { FPM_InitFixedPoint_m(15.0, u9p7_T),
	 FPM_InitFixedPoint_m(15.0, u9p7_T), FPM_InitFixedPoint_m(15.0, u9p7_T),
	 FPM_InitFixedPoint_m(15.0, u9p7_T), FPM_InitFixedPoint_m(15.0, u9p7_T),
	 FPM_InitFixedPoint_m(15.0, u9p7_T), FPM_InitFixedPoint_m(15.0, u9p7_T),
	 FPM_InitFixedPoint_m(15.0, u9p7_T) }, {{FPM_InitFixedPoint_m(0.0, u4p12_T),
	  FPM_InitFixedPoint_m(0.2, u4p12_T),
	  FPM_InitFixedPoint_m(0.3, u4p12_T),
	  FPM_InitFixedPoint_m(0.4, u4p12_T),
	  FPM_InitFixedPoint_m(0.6, u4p12_T),
	  FPM_InitFixedPoint_m(0.75, u4p12_T),
	  FPM_InitFixedPoint_m(1.0, u4p12_T),
	  FPM_InitFixedPoint_m(1.4, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T)},{FPM_InitFixedPoint_m(0.0, u4p12_T),
	  FPM_InitFixedPoint_m(0.2, u4p12_T),
	  FPM_InitFixedPoint_m(0.3, u4p12_T),
	  FPM_InitFixedPoint_m(0.4, u4p12_T),
	  FPM_InitFixedPoint_m(0.6, u4p12_T),
	  FPM_InitFixedPoint_m(0.75, u4p12_T),
	  FPM_InitFixedPoint_m(1.0, u4p12_T),
	  FPM_InitFixedPoint_m(1.4, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T)},{FPM_InitFixedPoint_m(0.0, u4p12_T),
	  FPM_InitFixedPoint_m(0.2, u4p12_T),
	  FPM_InitFixedPoint_m(0.3, u4p12_T),
	  FPM_InitFixedPoint_m(0.4, u4p12_T),
	  FPM_InitFixedPoint_m(0.6, u4p12_T),
	  FPM_InitFixedPoint_m(0.75, u4p12_T),
	  FPM_InitFixedPoint_m(1.0, u4p12_T),
	  FPM_InitFixedPoint_m(1.4, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T)},{FPM_InitFixedPoint_m(0.0, u4p12_T),
	  FPM_InitFixedPoint_m(0.2, u4p12_T),
	  FPM_InitFixedPoint_m(0.3, u4p12_T),
	  FPM_InitFixedPoint_m(0.4, u4p12_T),
	  FPM_InitFixedPoint_m(0.6, u4p12_T),
	  FPM_InitFixedPoint_m(0.75, u4p12_T),
	  FPM_InitFixedPoint_m(1.0, u4p12_T),
	  FPM_InitFixedPoint_m(1.4, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T)},{FPM_InitFixedPoint_m(0.0, u4p12_T),
	  FPM_InitFixedPoint_m(0.2, u4p12_T),
	  FPM_InitFixedPoint_m(0.3, u4p12_T),
	  FPM_InitFixedPoint_m(0.4, u4p12_T),
	  FPM_InitFixedPoint_m(0.6, u4p12_T),
	  FPM_InitFixedPoint_m(0.75, u4p12_T),
	  FPM_InitFixedPoint_m(1.0, u4p12_T),
	  FPM_InitFixedPoint_m(1.4, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T)},{FPM_InitFixedPoint_m(0.0, u4p12_T),
	  FPM_InitFixedPoint_m(0.2, u4p12_T),
	  FPM_InitFixedPoint_m(0.3, u4p12_T),
	  FPM_InitFixedPoint_m(0.4, u4p12_T),
	  FPM_InitFixedPoint_m(0.6, u4p12_T),
	  FPM_InitFixedPoint_m(0.75, u4p12_T),
	  FPM_InitFixedPoint_m(1.0, u4p12_T),
	  FPM_InitFixedPoint_m(1.4, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T)},{FPM_InitFixedPoint_m(0.0, u4p12_T),
	  FPM_InitFixedPoint_m(0.2, u4p12_T),
	  FPM_InitFixedPoint_m(0.3, u4p12_T),
	  FPM_InitFixedPoint_m(0.4, u4p12_T),
	  FPM_InitFixedPoint_m(0.6, u4p12_T),
	  FPM_InitFixedPoint_m(0.75, u4p12_T),
	  FPM_InitFixedPoint_m(1.0, u4p12_T),
	  FPM_InitFixedPoint_m(1.4, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T)},{FPM_InitFixedPoint_m(0.0, u4p12_T),
	  FPM_InitFixedPoint_m(0.2, u4p12_T),
	  FPM_InitFixedPoint_m(0.3, u4p12_T),
	  FPM_InitFixedPoint_m(0.4, u4p12_T),
	  FPM_InitFixedPoint_m(0.6, u4p12_T),
	  FPM_InitFixedPoint_m(0.75, u4p12_T),
	  FPM_InitFixedPoint_m(1.0, u4p12_T),
	  FPM_InitFixedPoint_m(1.4, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T)}}, {{FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.9, u4p12_T), FPM_InitFixedPoint_m(0.85, u4p12_T),
	 FPM_InitFixedPoint_m(0.8, u4p12_T), FPM_InitFixedPoint_m(0.7, u4p12_T),
	 FPM_InitFixedPoint_m(0.62, u4p12_T), FPM_InitFixedPoint_m(0.5, u4p12_T),
	 FPM_InitFixedPoint_m(0.3, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T)},
	{FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(0.9, u4p12_T),
	 FPM_InitFixedPoint_m(0.85, u4p12_T), FPM_InitFixedPoint_m(0.8, u4p12_T),
	 FPM_InitFixedPoint_m(0.7, u4p12_T), FPM_InitFixedPoint_m(0.62, u4p12_T),
	 FPM_InitFixedPoint_m(0.5, u4p12_T), FPM_InitFixedPoint_m(0.3, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T)},{FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.9, u4p12_T), FPM_InitFixedPoint_m(0.85, u4p12_T),
	 FPM_InitFixedPoint_m(0.8, u4p12_T), FPM_InitFixedPoint_m(0.7, u4p12_T),
	 FPM_InitFixedPoint_m(0.62, u4p12_T), FPM_InitFixedPoint_m(0.5, u4p12_T),
	 FPM_InitFixedPoint_m(0.3, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T)},
	{FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(0.9, u4p12_T),
	 FPM_InitFixedPoint_m(0.85, u4p12_T), FPM_InitFixedPoint_m(0.8, u4p12_T),
	 FPM_InitFixedPoint_m(0.7, u4p12_T), FPM_InitFixedPoint_m(0.62, u4p12_T),
	 FPM_InitFixedPoint_m(0.5, u4p12_T), FPM_InitFixedPoint_m(0.3, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T)},{FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.9, u4p12_T), FPM_InitFixedPoint_m(0.85, u4p12_T),
	 FPM_InitFixedPoint_m(0.8, u4p12_T), FPM_InitFixedPoint_m(0.7, u4p12_T),
	 FPM_InitFixedPoint_m(0.62, u4p12_T), FPM_InitFixedPoint_m(0.5, u4p12_T),
	 FPM_InitFixedPoint_m(0.3, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T)},
	{FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(0.9, u4p12_T),
	 FPM_InitFixedPoint_m(0.85, u4p12_T), FPM_InitFixedPoint_m(0.8, u4p12_T),
	 FPM_InitFixedPoint_m(0.7, u4p12_T), FPM_InitFixedPoint_m(0.62, u4p12_T),
	 FPM_InitFixedPoint_m(0.5, u4p12_T), FPM_InitFixedPoint_m(0.3, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T)},{FPM_InitFixedPoint_m(1.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.9, u4p12_T), FPM_InitFixedPoint_m(0.85, u4p12_T),
	 FPM_InitFixedPoint_m(0.8, u4p12_T), FPM_InitFixedPoint_m(0.7, u4p12_T),
	 FPM_InitFixedPoint_m(0.62, u4p12_T), FPM_InitFixedPoint_m(0.5, u4p12_T),
	 FPM_InitFixedPoint_m(0.3, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T)},
	{FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(0.9, u4p12_T),
	 FPM_InitFixedPoint_m(0.85, u4p12_T), FPM_InitFixedPoint_m(0.8, u4p12_T),
	 FPM_InitFixedPoint_m(0.7, u4p12_T), FPM_InitFixedPoint_m(0.62, u4p12_T),
	 FPM_InitFixedPoint_m(0.5, u4p12_T), FPM_InitFixedPoint_m(0.3, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T)}}, {FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(0.5, u4p12_T),
	 FPM_InitFixedPoint_m(1.0, u4p12_T), FPM_InitFixedPoint_m(1.5, u4p12_T),
	 FPM_InitFixedPoint_m(2.0, u4p12_T), FPM_InitFixedPoint_m(2.5, u4p12_T),
	 FPM_InitFixedPoint_m(3.0, u4p12_T), FPM_InitFixedPoint_m(3.5, u4p12_T),
	 FPM_InitFixedPoint_m(4.0, u4p12_T), FPM_InitFixedPoint_m(4.5, u4p12_T),
	 FPM_InitFixedPoint_m(5.0, u4p12_T), FPM_InitFixedPoint_m(5.5, u4p12_T),
	 FPM_InitFixedPoint_m(6.0, u4p12_T)}, {FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(10.0, u12p4_T),
	FPM_InitFixedPoint_m(55.0, u12p4_T),FPM_InitFixedPoint_m(75.0, u12p4_T)}, {{FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T)},
	{FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T),
	FPM_InitFixedPoint_m(0.0025, u0p16_T)}}, 0U, { FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(3.0, u9p7_T),
	FPM_InitFixedPoint_m(7.0, u9p7_T),FPM_InitFixedPoint_m(12.0, u9p7_T),
	FPM_InitFixedPoint_m(20.0, u9p7_T),FPM_InitFixedPoint_m(30.0, u9p7_T) }, {{FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.03515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.05078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.0703125, s4p11_T),
	 FPM_InitFixedPoint_m(0.09375, s4p11_T),
	 FPM_InitFixedPoint_m(0.12109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.15234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.18359375, s4p11_T),
	 FPM_InitFixedPoint_m(0.21875, s4p11_T),
	 FPM_InitFixedPoint_m(0.26171875, s4p11_T),
	 FPM_InitFixedPoint_m(0.30078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.34765625, s4p11_T),
	 FPM_InitFixedPoint_m(0.3984375, s4p11_T),
	 FPM_InitFixedPoint_m(0.44921875, s4p11_T),
	 FPM_InitFixedPoint_m(0.5078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.56640625, s4p11_T),
	 FPM_InitFixedPoint_m(0.62890625, s4p11_T),
	 FPM_InitFixedPoint_m(0.69140625, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.03125, s4p11_T),
	 FPM_InitFixedPoint_m(0.05078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.07421875, s4p11_T),
	 FPM_InitFixedPoint_m(0.10546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.140625, s4p11_T),
	 FPM_InitFixedPoint_m(0.18359375, s4p11_T),
	 FPM_InitFixedPoint_m(0.23046875, s4p11_T),
	 FPM_InitFixedPoint_m(0.28125, s4p11_T),
	 FPM_InitFixedPoint_m(0.33984375, s4p11_T),
	 FPM_InitFixedPoint_m(0.40234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.47265625, s4p11_T),
	 FPM_InitFixedPoint_m(0.546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.625, s4p11_T),
	 FPM_InitFixedPoint_m(0.7109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.80078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.89453125, s4p11_T),
	 FPM_InitFixedPoint_m(0.99609375, s4p11_T),
	 FPM_InitFixedPoint_m(1.10546875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.0390625, s4p11_T),
	 FPM_InitFixedPoint_m(0.06640625, s4p11_T),
	 FPM_InitFixedPoint_m(0.09765625, s4p11_T),
	 FPM_InitFixedPoint_m(0.1328125, s4p11_T),
	 FPM_InitFixedPoint_m(0.17578125, s4p11_T),
	 FPM_InitFixedPoint_m(0.21875, s4p11_T),
	 FPM_InitFixedPoint_m(0.26953125, s4p11_T),
	 FPM_InitFixedPoint_m(0.328125, s4p11_T),
	 FPM_InitFixedPoint_m(0.38671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.453125, s4p11_T),
	 FPM_InitFixedPoint_m(0.5234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.59765625, s4p11_T),
	 FPM_InitFixedPoint_m(0.6796875, s4p11_T),
	 FPM_InitFixedPoint_m(0.76171875, s4p11_T),
	 FPM_InitFixedPoint_m(0.8515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.94921875, s4p11_T),
	 FPM_InitFixedPoint_m(1.046875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.03515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.0625, s4p11_T),
	 FPM_InitFixedPoint_m(0.0859375, s4p11_T),
	 FPM_InitFixedPoint_m(0.1171875, s4p11_T),
	 FPM_InitFixedPoint_m(0.15234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.1875, s4p11_T),
	 FPM_InitFixedPoint_m(0.23046875, s4p11_T),
	 FPM_InitFixedPoint_m(0.2734375, s4p11_T),
	 FPM_InitFixedPoint_m(0.3203125, s4p11_T),
	 FPM_InitFixedPoint_m(0.37109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.42578125, s4p11_T),
	 FPM_InitFixedPoint_m(0.48046875, s4p11_T),
	 FPM_InitFixedPoint_m(0.54296875, s4p11_T),
	 FPM_InitFixedPoint_m(0.60546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.7421875, s4p11_T),
	 FPM_InitFixedPoint_m(0.81640625, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.03515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.05859375, s4p11_T),
	 FPM_InitFixedPoint_m(0.0859375, s4p11_T),
	 FPM_InitFixedPoint_m(0.11328125, s4p11_T),
	 FPM_InitFixedPoint_m(0.14453125, s4p11_T),
	 FPM_InitFixedPoint_m(0.17578125, s4p11_T),
	 FPM_InitFixedPoint_m(0.21484375, s4p11_T),
	 FPM_InitFixedPoint_m(0.25390625, s4p11_T),
	 FPM_InitFixedPoint_m(0.29296875, s4p11_T),
	 FPM_InitFixedPoint_m(0.33984375, s4p11_T),
	 FPM_InitFixedPoint_m(0.38671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.4375, s4p11_T),
	 FPM_InitFixedPoint_m(0.48828125, s4p11_T),
	 FPM_InitFixedPoint_m(0.546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.60546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.66796875, s4p11_T),
	 FPM_InitFixedPoint_m(0.73046875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.03515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.0546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.08203125, s4p11_T),
	 FPM_InitFixedPoint_m(0.109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.13671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.16796875, s4p11_T),
	 FPM_InitFixedPoint_m(0.203125, s4p11_T),
	 FPM_InitFixedPoint_m(0.2421875, s4p11_T),
	 FPM_InitFixedPoint_m(0.28125, s4p11_T),
	 FPM_InitFixedPoint_m(0.3203125, s4p11_T),
	 FPM_InitFixedPoint_m(0.36328125, s4p11_T),
	 FPM_InitFixedPoint_m(0.41015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.4609375, s4p11_T),
	 FPM_InitFixedPoint_m(0.51171875, s4p11_T),
	 FPM_InitFixedPoint_m(0.5625, s4p11_T),
	 FPM_InitFixedPoint_m(0.62109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.6796875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.03125, s4p11_T),
	 FPM_InitFixedPoint_m(0.0546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.1015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.12890625, s4p11_T),
	 FPM_InitFixedPoint_m(0.15625, s4p11_T),
	 FPM_InitFixedPoint_m(0.18359375, s4p11_T),
	 FPM_InitFixedPoint_m(0.21484375, s4p11_T),
	 FPM_InitFixedPoint_m(0.25, s4p11_T),
	 FPM_InitFixedPoint_m(0.28515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.3203125, s4p11_T),
	 FPM_InitFixedPoint_m(0.359375, s4p11_T),
	 FPM_InitFixedPoint_m(0.3984375, s4p11_T),
	 FPM_InitFixedPoint_m(0.4375, s4p11_T),
	 FPM_InitFixedPoint_m(0.48046875, s4p11_T),
	 FPM_InitFixedPoint_m(0.52734375, s4p11_T),
	 FPM_InitFixedPoint_m(0.57421875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.0390625, s4p11_T),
	 FPM_InitFixedPoint_m(0.05859375, s4p11_T),
	 FPM_InitFixedPoint_m(0.078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.1015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.125, s4p11_T),
	 FPM_InitFixedPoint_m(0.1484375, s4p11_T),
	 FPM_InitFixedPoint_m(0.17578125, s4p11_T),
	 FPM_InitFixedPoint_m(0.203125, s4p11_T),
	 FPM_InitFixedPoint_m(0.234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.265625, s4p11_T),
	 FPM_InitFixedPoint_m(0.296875, s4p11_T),
	 FPM_InitFixedPoint_m(0.33203125, s4p11_T),
	 FPM_InitFixedPoint_m(0.3671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.40625, s4p11_T),
	 FPM_InitFixedPoint_m(0.4453125, s4p11_T),
	 FPM_InitFixedPoint_m(0.48828125, s4p11_T),
	 FPM_InitFixedPoint_m(0.53125, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.039062499, s4p11_T),
	 FPM_InitFixedPoint_m(0.058593749, s4p11_T),
	 FPM_InitFixedPoint_m(0.078124999, s4p11_T),
	 FPM_InitFixedPoint_m(0.101562499, s4p11_T),
	 FPM_InitFixedPoint_m(0.121093748, s4p11_T),
	 FPM_InitFixedPoint_m(0.148437498, s4p11_T),
	 FPM_InitFixedPoint_m(0.171874998, s4p11_T),
	 FPM_InitFixedPoint_m(0.199218747, s4p11_T),
	 FPM_InitFixedPoint_m(0.230468747, s4p11_T),
	 FPM_InitFixedPoint_m(0.261718746, s4p11_T),
	 FPM_InitFixedPoint_m(0.292968746, s4p11_T),
	 FPM_InitFixedPoint_m(0.324218745, s4p11_T),
	 FPM_InitFixedPoint_m(0.359374995, s4p11_T),
	 FPM_InitFixedPoint_m(0.394531244, s4p11_T),
	 FPM_InitFixedPoint_m(0.433593744, s4p11_T),
	 FPM_InitFixedPoint_m(0.472656243, s4p11_T),
	 FPM_InitFixedPoint_m(0.511718742, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.039062499, s4p11_T),
	 FPM_InitFixedPoint_m(0.058593749, s4p11_T),
	 FPM_InitFixedPoint_m(0.078124999, s4p11_T),
	 FPM_InitFixedPoint_m(0.101562499, s4p11_T),
	 FPM_InitFixedPoint_m(0.121093748, s4p11_T),
	 FPM_InitFixedPoint_m(0.148437498, s4p11_T),
	 FPM_InitFixedPoint_m(0.171874998, s4p11_T),
	 FPM_InitFixedPoint_m(0.199218747, s4p11_T),
	 FPM_InitFixedPoint_m(0.230468747, s4p11_T),
	 FPM_InitFixedPoint_m(0.261718746, s4p11_T),
	 FPM_InitFixedPoint_m(0.292968746, s4p11_T),
	 FPM_InitFixedPoint_m(0.324218745, s4p11_T),
	 FPM_InitFixedPoint_m(0.359374995, s4p11_T),
	 FPM_InitFixedPoint_m(0.394531244, s4p11_T),
	 FPM_InitFixedPoint_m(0.433593744, s4p11_T),
	 FPM_InitFixedPoint_m(0.472656243, s4p11_T),
	 FPM_InitFixedPoint_m(0.511718742, s4p11_T)}}, {{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0234375, u8p8_T),
	 FPM_InitFixedPoint_m(0.03515625, u8p8_T),
	 FPM_InitFixedPoint_m(0.05078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.0703125, u8p8_T),
	 FPM_InitFixedPoint_m(0.09375, u8p8_T),
	 FPM_InitFixedPoint_m(0.12109375, u8p8_T),
	 FPM_InitFixedPoint_m(0.15234375, u8p8_T),
	 FPM_InitFixedPoint_m(0.18359375, u8p8_T),
	 FPM_InitFixedPoint_m(0.21875, u8p8_T),
	 FPM_InitFixedPoint_m(0.26171875, u8p8_T),
	 FPM_InitFixedPoint_m(0.30078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.34765625, u8p8_T),
	 FPM_InitFixedPoint_m(0.3984375, u8p8_T),
	 FPM_InitFixedPoint_m(0.44921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.5078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.56640625, u8p8_T),
	 FPM_InitFixedPoint_m(0.62890625, u8p8_T),
	 FPM_InitFixedPoint_m(0.69140625, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.03125, u8p8_T),
	 FPM_InitFixedPoint_m(0.05078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.07421875, u8p8_T),
	 FPM_InitFixedPoint_m(0.10546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.140625, u8p8_T),
	 FPM_InitFixedPoint_m(0.18359375, u8p8_T),
	 FPM_InitFixedPoint_m(0.23046875, u8p8_T),
	 FPM_InitFixedPoint_m(0.28125, u8p8_T),
	 FPM_InitFixedPoint_m(0.33984375, u8p8_T),
	 FPM_InitFixedPoint_m(0.40234375, u8p8_T),
	 FPM_InitFixedPoint_m(0.47265625, u8p8_T),
	 FPM_InitFixedPoint_m(0.546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.625, u8p8_T),
	 FPM_InitFixedPoint_m(0.7109375, u8p8_T),
	 FPM_InitFixedPoint_m(0.80078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.89453125, u8p8_T),
	 FPM_InitFixedPoint_m(0.99609375, u8p8_T),
	 FPM_InitFixedPoint_m(1.10546875, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.015625, u8p8_T),
	 FPM_InitFixedPoint_m(0.0390625, u8p8_T),
	 FPM_InitFixedPoint_m(0.06640625, u8p8_T),
	 FPM_InitFixedPoint_m(0.09765625, u8p8_T),
	 FPM_InitFixedPoint_m(0.1328125, u8p8_T),
	 FPM_InitFixedPoint_m(0.17578125, u8p8_T),
	 FPM_InitFixedPoint_m(0.21875, u8p8_T),
	 FPM_InitFixedPoint_m(0.26953125, u8p8_T),
	 FPM_InitFixedPoint_m(0.328125, u8p8_T),
	 FPM_InitFixedPoint_m(0.38671875, u8p8_T),
	 FPM_InitFixedPoint_m(0.453125, u8p8_T),
	 FPM_InitFixedPoint_m(0.5234375, u8p8_T),
	 FPM_InitFixedPoint_m(0.59765625, u8p8_T),
	 FPM_InitFixedPoint_m(0.6796875, u8p8_T),
	 FPM_InitFixedPoint_m(0.76171875, u8p8_T),
	 FPM_InitFixedPoint_m(0.8515625, u8p8_T),
	 FPM_InitFixedPoint_m(0.94921875, u8p8_T),
	 FPM_InitFixedPoint_m(1.046875, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.015625, u8p8_T),
	 FPM_InitFixedPoint_m(0.03515625, u8p8_T),
	 FPM_InitFixedPoint_m(0.0625, u8p8_T),
	 FPM_InitFixedPoint_m(0.0859375, u8p8_T),
	 FPM_InitFixedPoint_m(0.1171875, u8p8_T),
	 FPM_InitFixedPoint_m(0.15234375, u8p8_T),
	 FPM_InitFixedPoint_m(0.1875, u8p8_T),
	 FPM_InitFixedPoint_m(0.23046875, u8p8_T),
	 FPM_InitFixedPoint_m(0.2734375, u8p8_T),
	 FPM_InitFixedPoint_m(0.3203125, u8p8_T),
	 FPM_InitFixedPoint_m(0.37109375, u8p8_T),
	 FPM_InitFixedPoint_m(0.42578125, u8p8_T),
	 FPM_InitFixedPoint_m(0.48046875, u8p8_T),
	 FPM_InitFixedPoint_m(0.54296875, u8p8_T),
	 FPM_InitFixedPoint_m(0.60546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.671875, u8p8_T),
	 FPM_InitFixedPoint_m(0.7421875, u8p8_T),
	 FPM_InitFixedPoint_m(0.81640625, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.015625, u8p8_T),
	 FPM_InitFixedPoint_m(0.03515625, u8p8_T),
	 FPM_InitFixedPoint_m(0.05859375, u8p8_T),
	 FPM_InitFixedPoint_m(0.0859375, u8p8_T),
	 FPM_InitFixedPoint_m(0.11328125, u8p8_T),
	 FPM_InitFixedPoint_m(0.14453125, u8p8_T),
	 FPM_InitFixedPoint_m(0.17578125, u8p8_T),
	 FPM_InitFixedPoint_m(0.21484375, u8p8_T),
	 FPM_InitFixedPoint_m(0.25390625, u8p8_T),
	 FPM_InitFixedPoint_m(0.29296875, u8p8_T),
	 FPM_InitFixedPoint_m(0.33984375, u8p8_T),
	 FPM_InitFixedPoint_m(0.38671875, u8p8_T),
	 FPM_InitFixedPoint_m(0.4375, u8p8_T),
	 FPM_InitFixedPoint_m(0.48828125, u8p8_T),
	 FPM_InitFixedPoint_m(0.546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.60546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.66796875, u8p8_T),
	 FPM_InitFixedPoint_m(0.73046875, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.01, u8p8_T),
	 FPM_InitFixedPoint_m(0.02, u8p8_T), FPM_InitFixedPoint_m(0.035, u8p8_T),
	 FPM_InitFixedPoint_m(0.06, u8p8_T), FPM_InitFixedPoint_m(0.08, u8p8_T),
	 FPM_InitFixedPoint_m(0.12, u8p8_T), FPM_InitFixedPoint_m(0.16, u8p8_T),
	 FPM_InitFixedPoint_m(0.2, u8p8_T), FPM_InitFixedPoint_m(0.24, u8p8_T),
	 FPM_InitFixedPoint_m(0.29, u8p8_T), FPM_InitFixedPoint_m(0.35, u8p8_T),
	 FPM_InitFixedPoint_m(0.39, u8p8_T), FPM_InitFixedPoint_m(0.46, u8p8_T),
	 FPM_InitFixedPoint_m(0.51171875, u8p8_T),
	 FPM_InitFixedPoint_m(0.5625, u8p8_T),
	 FPM_InitFixedPoint_m(0.62109375, u8p8_T),
	 FPM_InitFixedPoint_m(0.6796875, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.01, u8p8_T),
	 FPM_InitFixedPoint_m(0.02, u8p8_T), FPM_InitFixedPoint_m(0.035, u8p8_T),
	 FPM_InitFixedPoint_m(0.06, u8p8_T), FPM_InitFixedPoint_m(0.08, u8p8_T),
	 FPM_InitFixedPoint_m(0.1, u8p8_T), FPM_InitFixedPoint_m(0.14, u8p8_T),
	 FPM_InitFixedPoint_m(0.18, u8p8_T), FPM_InitFixedPoint_m(0.21, u8p8_T),
	 FPM_InitFixedPoint_m(0.26, u8p8_T), FPM_InitFixedPoint_m(0.3, u8p8_T),
	 FPM_InitFixedPoint_m(0.34, u8p8_T),
	 FPM_InitFixedPoint_m(0.3984375, u8p8_T),
	 FPM_InitFixedPoint_m(0.4375, u8p8_T),
	 FPM_InitFixedPoint_m(0.48046875, u8p8_T),
	 FPM_InitFixedPoint_m(0.52734375, u8p8_T),
	 FPM_InitFixedPoint_m(0.57421875, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.01, u8p8_T), FPM_InitFixedPoint_m(0.03, u8p8_T),
	 FPM_InitFixedPoint_m(0.05, u8p8_T), FPM_InitFixedPoint_m(0.07, u8p8_T),
	 FPM_InitFixedPoint_m(0.095, u8p8_T), FPM_InitFixedPoint_m(0.13, u8p8_T),
	 FPM_InitFixedPoint_m(0.16, u8p8_T), FPM_InitFixedPoint_m(0.2, u8p8_T),
	 FPM_InitFixedPoint_m(0.24, u8p8_T), FPM_InitFixedPoint_m(0.28, u8p8_T),
	 FPM_InitFixedPoint_m(0.32, u8p8_T),
	 FPM_InitFixedPoint_m(0.3671875, u8p8_T),
	 FPM_InitFixedPoint_m(0.40625, u8p8_T),
	 FPM_InitFixedPoint_m(0.4453125, u8p8_T),
	 FPM_InitFixedPoint_m(0.48828125, u8p8_T),
	 FPM_InitFixedPoint_m(0.53125, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.01, u8p8_T), FPM_InitFixedPoint_m(0.015, u8p8_T),
	 FPM_InitFixedPoint_m(0.03, u8p8_T), FPM_InitFixedPoint_m(0.05, u8p8_T),
	 FPM_InitFixedPoint_m(0.07, u8p8_T), FPM_InitFixedPoint_m(0.1, u8p8_T),
	 FPM_InitFixedPoint_m(0.135, u8p8_T), FPM_InitFixedPoint_m(0.16, u8p8_T),
	 FPM_InitFixedPoint_m(0.2, u8p8_T), FPM_InitFixedPoint_m(0.23, u8p8_T),
	 FPM_InitFixedPoint_m(0.26, u8p8_T), FPM_InitFixedPoint_m(0.31, u8p8_T),
	 FPM_InitFixedPoint_m(0.35, u8p8_T), FPM_InitFixedPoint_m(0.38, u8p8_T),
	 FPM_InitFixedPoint_m(0.43, u8p8_T),
	 FPM_InitFixedPoint_m(0.47265625, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.01, u8p8_T), FPM_InitFixedPoint_m(0.015, u8p8_T),
	 FPM_InitFixedPoint_m(0.03, u8p8_T), FPM_InitFixedPoint_m(0.05, u8p8_T),
	 FPM_InitFixedPoint_m(0.07, u8p8_T), FPM_InitFixedPoint_m(0.1, u8p8_T),
	 FPM_InitFixedPoint_m(0.135, u8p8_T), FPM_InitFixedPoint_m(0.16, u8p8_T),
	 FPM_InitFixedPoint_m(0.2, u8p8_T), FPM_InitFixedPoint_m(0.23, u8p8_T),
	 FPM_InitFixedPoint_m(0.26, u8p8_T), FPM_InitFixedPoint_m(0.31, u8p8_T),
	 FPM_InitFixedPoint_m(0.35, u8p8_T), FPM_InitFixedPoint_m(0.38, u8p8_T),
	 FPM_InitFixedPoint_m(0.43, u8p8_T),
	 FPM_InitFixedPoint_m(0.47265625, u8p8_T)}}, {{FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T)},
	{FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T),
	 FPM_InitFixedPoint_m(4.42588677, u12p4_T)},
	{FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T),
	 FPM_InitFixedPoint_m(8.363583762, u12p4_T)},
	{FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T),
	 FPM_InitFixedPoint_m(12.09307604, u12p4_T)},
	{FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T),
	 FPM_InitFixedPoint_m(16.92227444, u12p4_T)},
	{FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T),
	 FPM_InitFixedPoint_m(27.96101449, u12p4_T)},
	{FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T),
	 FPM_InitFixedPoint_m(43.95370866, u12p4_T)},
	{FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T),
	 FPM_InitFixedPoint_m(66.12166607, u12p4_T)},
	{FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T),
	 FPM_InitFixedPoint_m(91.299497, u12p4_T)}}, {{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0000212779, u5p11_T),
	 FPM_InitFixedPoint_m(0.001071305, u5p11_T),
	 FPM_InitFixedPoint_m(0.005090552, u5p11_T),
	 FPM_InitFixedPoint_m(0.01012791, u5p11_T),
	 FPM_InitFixedPoint_m(0.01012791, u5p11_T),
	 FPM_InitFixedPoint_m(0.01012791, u5p11_T),
	 FPM_InitFixedPoint_m(0.01012791, u5p11_T),
	 FPM_InitFixedPoint_m(0.01012791, u5p11_T),
	 FPM_InitFixedPoint_m(0.01012791, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0000759824, u5p11_T),
	 FPM_InitFixedPoint_m(0.00214965, u5p11_T),
	 FPM_InitFixedPoint_m(0.009798468, u5p11_T),
	 FPM_InitFixedPoint_m(0.01940698, u5p11_T),
	 FPM_InitFixedPoint_m(0.01940698, u5p11_T),
	 FPM_InitFixedPoint_m(0.01940698, u5p11_T),
	 FPM_InitFixedPoint_m(0.01940698, u5p11_T),
	 FPM_InitFixedPoint_m(0.01940698, u5p11_T),
	 FPM_InitFixedPoint_m(0.01940698, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.000158855, u5p11_T),
	 FPM_InitFixedPoint_m(0.00327969, u5p11_T),
	 FPM_InitFixedPoint_m(0.014412758, u5p11_T),
	 FPM_InitFixedPoint_m(0.028428379, u5p11_T),
	 FPM_InitFixedPoint_m(0.028428379, u5p11_T),
	 FPM_InitFixedPoint_m(0.028428379, u5p11_T),
	 FPM_InitFixedPoint_m(0.028428379, u5p11_T),
	 FPM_InitFixedPoint_m(0.028428379, u5p11_T),
	 FPM_InitFixedPoint_m(0.028428379, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.000311061, u5p11_T),
	 FPM_InitFixedPoint_m(0.004900079, u5p11_T),
	 FPM_InitFixedPoint_m(0.020612135, u5p11_T),
	 FPM_InitFixedPoint_m(0.040446617, u5p11_T),
	 FPM_InitFixedPoint_m(0.040446617, u5p11_T),
	 FPM_InitFixedPoint_m(0.040446617, u5p11_T),
	 FPM_InitFixedPoint_m(0.040446617, u5p11_T),
	 FPM_InitFixedPoint_m(0.040446617, u5p11_T),
	 FPM_InitFixedPoint_m(0.040446617, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.000849247, u5p11_T),
	 FPM_InitFixedPoint_m(0.009269961, u5p11_T),
	 FPM_InitFixedPoint_m(0.035734217, u5p11_T),
	 FPM_InitFixedPoint_m(0.069345318, u5p11_T),
	 FPM_InitFixedPoint_m(0.069345318, u5p11_T),
	 FPM_InitFixedPoint_m(0.069345318, u5p11_T),
	 FPM_InitFixedPoint_m(0.069345318, u5p11_T),
	 FPM_InitFixedPoint_m(0.069345318, u5p11_T),
	 FPM_InitFixedPoint_m(0.069345318, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.002098549, u5p11_T),
	 FPM_InitFixedPoint_m(0.017244517, u5p11_T),
	 FPM_InitFixedPoint_m(0.059990722, u5p11_T),
	 FPM_InitFixedPoint_m(0.114735072, u5p11_T),
	 FPM_InitFixedPoint_m(0.114735072, u5p11_T),
	 FPM_InitFixedPoint_m(0.114735072, u5p11_T),
	 FPM_InitFixedPoint_m(0.114735072, u5p11_T),
	 FPM_InitFixedPoint_m(0.114735072, u5p11_T),
	 FPM_InitFixedPoint_m(0.114735072, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.004749148, u5p11_T),
	 FPM_InitFixedPoint_m(0.031514452, u5p11_T),
	 FPM_InitFixedPoint_m(0.098207912, u5p11_T),
	 FPM_InitFixedPoint_m(0.184542954, u5p11_T),
	 FPM_InitFixedPoint_m(0.184542954, u5p11_T),
	 FPM_InitFixedPoint_m(0.184542954, u5p11_T),
	 FPM_InitFixedPoint_m(0.184542954, u5p11_T),
	 FPM_InitFixedPoint_m(0.184542954, u5p11_T),
	 FPM_InitFixedPoint_m(0.184542954, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.009054508, u5p11_T),
	 FPM_InitFixedPoint_m(0.05225396, u5p11_T),
	 FPM_InitFixedPoint_m(0.148088447, u5p11_T),
	 FPM_InitFixedPoint_m(0.273540623, u5p11_T),
	 FPM_InitFixedPoint_m(0.273540623, u5p11_T),
	 FPM_InitFixedPoint_m(0.273540623, u5p11_T),
	 FPM_InitFixedPoint_m(0.273540623, u5p11_T),
	 FPM_InitFixedPoint_m(0.273540623, u5p11_T),
	 FPM_InitFixedPoint_m(0.273540623, u5p11_T)}}, {{FPM_InitFixedPoint_m(0.0, u12p4_T),
	 FPM_InitFixedPoint_m(0.5, u12p4_T), FPM_InitFixedPoint_m(1.0, u12p4_T),
	 FPM_InitFixedPoint_m(5.0, u12p4_T), FPM_InitFixedPoint_m(10.0, u12p4_T),
	 FPM_InitFixedPoint_m(20.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(45.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(120.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.5, u12p4_T),
	 FPM_InitFixedPoint_m(1.0, u12p4_T), FPM_InitFixedPoint_m(5.0, u12p4_T),
	 FPM_InitFixedPoint_m(10.0, u12p4_T),
	 FPM_InitFixedPoint_m(20.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(45.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(120.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.5, u12p4_T),
	 FPM_InitFixedPoint_m(1.0, u12p4_T), FPM_InitFixedPoint_m(5.0, u12p4_T),
	 FPM_InitFixedPoint_m(10.0, u12p4_T),
	 FPM_InitFixedPoint_m(20.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(45.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(120.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.5, u12p4_T),
	 FPM_InitFixedPoint_m(1.0, u12p4_T), FPM_InitFixedPoint_m(5.0, u12p4_T),
	 FPM_InitFixedPoint_m(10.0, u12p4_T),
	 FPM_InitFixedPoint_m(20.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(45.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(120.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.5, u12p4_T),
	 FPM_InitFixedPoint_m(1.0, u12p4_T), FPM_InitFixedPoint_m(5.0, u12p4_T),
	 FPM_InitFixedPoint_m(10.0, u12p4_T),
	 FPM_InitFixedPoint_m(20.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(45.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(120.0, u12p4_T)},
	{FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.5, u12p4_T),
	 FPM_InitFixedPoint_m(1.0, u12p4_T), FPM_InitFixedPoint_m(5.0, u12p4_T),
	 FPM_InitFixedPoint_m(10.0, u12p4_T),
	 FPM_InitFixedPoint_m(20.0, u12p4_T),
	 FPM_InitFixedPoint_m(30.0, u12p4_T),
	 FPM_InitFixedPoint_m(45.0, u12p4_T),
	 FPM_InitFixedPoint_m(60.0, u12p4_T),
	 FPM_InitFixedPoint_m(90.0, u12p4_T),
	 FPM_InitFixedPoint_m(120.0, u12p4_T)}}, {{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T)},
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T)}}, {{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.5, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(3.0, u8p8_T), FPM_InitFixedPoint_m(4.0, u8p8_T),
	 FPM_InitFixedPoint_m(5.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.5, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(3.0, u8p8_T),
	 FPM_InitFixedPoint_m(4.0, u8p8_T), FPM_InitFixedPoint_m(5.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.5, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(3.0, u8p8_T), FPM_InitFixedPoint_m(4.0, u8p8_T),
	 FPM_InitFixedPoint_m(5.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.5, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(3.0, u8p8_T),
	 FPM_InitFixedPoint_m(4.0, u8p8_T), FPM_InitFixedPoint_m(5.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.5, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(3.0, u8p8_T), FPM_InitFixedPoint_m(4.0, u8p8_T),
	 FPM_InitFixedPoint_m(5.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.5, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(3.0, u8p8_T),
	 FPM_InitFixedPoint_m(4.0, u8p8_T), FPM_InitFixedPoint_m(5.0, u8p8_T)}}, {{FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T)},{FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T)},
	{FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T)},{FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T)},
	{FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T)},{FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T),
	 FPM_InitFixedPoint_m(1.0, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T)}}, {{FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(40.0, u7p9_T),
	 FPM_InitFixedPoint_m(60.0, u7p9_T), FPM_InitFixedPoint_m(80.0, u7p9_T)},
	{FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(40.0, u7p9_T),
	 FPM_InitFixedPoint_m(60.0, u7p9_T), FPM_InitFixedPoint_m(80.0, u7p9_T)},
	{FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(40.0, u7p9_T),
	 FPM_InitFixedPoint_m(60.0, u7p9_T), FPM_InitFixedPoint_m(80.0, u7p9_T)},
	{FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(40.0, u7p9_T),
	 FPM_InitFixedPoint_m(60.0, u7p9_T), FPM_InitFixedPoint_m(80.0, u7p9_T)},
	{FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(40.0, u7p9_T),
	 FPM_InitFixedPoint_m(60.0, u7p9_T), FPM_InitFixedPoint_m(80.0, u7p9_T)},
	{FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(40.0, u7p9_T),
	 FPM_InitFixedPoint_m(60.0, u7p9_T), FPM_InitFixedPoint_m(80.0, u7p9_T)}}, {{FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T)},
	{FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T)},
	{FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T)},
	{FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T)},
	{FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T)},
	{FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T)}} };


/********************************* AbsHwPos **********************************/
#pragma DATA_SECTION(k_HwPosAuthorityStep_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HwPosAuthorityStep_Uls_f32 = 0.2f;

#pragma DATA_SECTION(k_HwPosOutputLPFCoeffK_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_HwPosOutputLPFCoeffK_Cnt_u16 = 175U;

#pragma DATA_SECTION(k_HwPosOutputLPFError_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HwPosOutputLPFError_HwDeg_f32 = 5.0f;

#pragma DATA_SECTION(k_ICMAuthority_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ICMAuthority_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_InpSignalInvalidTimer_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_InpSignalInvalidTimer_mS_u16 = 20U;

#pragma DATA_SECTION(k_KinmIntDiagMaxRackLimit_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_KinmIntDiagMaxRackLimit_HwDeg_f32 = 2100.0f;

#pragma DATA_SECTION(k_MinVehSpdReqVldAbsPos_kph_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MinVehSpdReqVldAbsPos_kph_f32 = 18.0f;

#pragma DATA_SECTION(k_MtrToHwResConv_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MtrToHwResConv_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_OffCorrAuthority_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_OffCorrAuthority_Uls_f32 = 0.8f;

#pragma DATA_SECTION(k_OffsCorrectionTimer_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_OffsCorrectionTimer_mS_u16 = 50U;

#pragma DATA_SECTION(k_TmpCompAuthority_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TmpCompAuthority_Uls_f32 = 0.6f;

#pragma DATA_SECTION(k_TurnsCntrAuthority_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TurnsCntrAuthority_Uls_f32 = 1.0f;

#pragma DATA_SECTION(t_MtrPosComplTblX_MtrNm_u4p12, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_MtrPosComplTblX_MtrNm_u4p12[6] = 
	{FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T),
	 FPM_InitFixedPoint_m(0.0, u4p12_T), FPM_InitFixedPoint_m(0.0, u4p12_T)};

#pragma DATA_SECTION(t_MtrPosComplTblY_HwDegpMtrNm_u7p9, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_MtrPosComplTblY_HwDegpMtrNm_u7p9[6] = 
	{FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(0.0, u7p9_T),
	 FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(0.0, u7p9_T),
	 FPM_InitFixedPoint_m(0.0, u7p9_T), FPM_InitFixedPoint_m(0.0, u7p9_T)};


/************************ AbsHwPos, LktoLkStr, LnRkCr ************************/
#pragma DATA_SECTION(k_InvGearRatio_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_InvGearRatio_Uls_f32 = 24.0f;


/******************** AbsHwPos, SrlComInput, SrlComOutput ********************/
#pragma DATA_SECTION(k_SComTrqPosPol_Cnt_s08, ".FlashCalSeg");
CONST(sint8, CAL_CONST) k_SComTrqPosPol_Cnt_s08 = -1;


/******************************** ActivePull *********************************/
#pragma DATA_SECTION(k_PullCmp_LTIntgtrStCorrnGain_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PullCmp_LTIntgtrStCorrnGain_Uls_f32 = 0.1f;

#pragma DATA_SECTION(k_PullCmp_STIntgtrStCorrnGain_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PullCmp_STIntgtrStCorrnGain_Uls_f32 = 0.1f;


/********************************** Assist ***********************************/
#pragma DATA_SECTION(t_AsstThermSclX_Cnt_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_AsstThermSclX_Cnt_u16p0[2] = 
	{FPM_InitFixedPoint_m(75.0, u16p0_T),
	 FPM_InitFixedPoint_m(100.0, u16p0_T)};

#pragma DATA_SECTION(t_AsstThermSclY_Uls_u2p14, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_AsstThermSclY_Uls_u2p14[2] = 
	{FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)};

#pragma DATA_SECTION(t2_AsstAsstY1_MtrNm_s4p11, ".FlashCalSeg");
CONST(sint16, CAL_CONST) t2_AsstAsstY1_MtrNm_s4p11[10][20] = 
	{{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.03515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.05078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.0703125, s4p11_T),
	 FPM_InitFixedPoint_m(0.09375, s4p11_T),
	 FPM_InitFixedPoint_m(0.12109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.15234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.18359375, s4p11_T),
	 FPM_InitFixedPoint_m(0.21875, s4p11_T),
	 FPM_InitFixedPoint_m(0.26171875, s4p11_T),
	 FPM_InitFixedPoint_m(0.30078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.34765625, s4p11_T),
	 FPM_InitFixedPoint_m(0.3984375, s4p11_T),
	 FPM_InitFixedPoint_m(0.44921875, s4p11_T),
	 FPM_InitFixedPoint_m(0.5078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.56640625, s4p11_T),
	 FPM_InitFixedPoint_m(0.62890625, s4p11_T),
	 FPM_InitFixedPoint_m(0.69140625, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.03125, s4p11_T),
	 FPM_InitFixedPoint_m(0.05078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.07421875, s4p11_T),
	 FPM_InitFixedPoint_m(0.10546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.140625, s4p11_T),
	 FPM_InitFixedPoint_m(0.18359375, s4p11_T),
	 FPM_InitFixedPoint_m(0.23046875, s4p11_T),
	 FPM_InitFixedPoint_m(0.28125, s4p11_T),
	 FPM_InitFixedPoint_m(0.33984375, s4p11_T),
	 FPM_InitFixedPoint_m(0.40234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.47265625, s4p11_T),
	 FPM_InitFixedPoint_m(0.546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.625, s4p11_T),
	 FPM_InitFixedPoint_m(0.7109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.80078125, s4p11_T),
	 FPM_InitFixedPoint_m(0.89453125, s4p11_T),
	 FPM_InitFixedPoint_m(0.99609375, s4p11_T),
	 FPM_InitFixedPoint_m(1.10546875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.0390625, s4p11_T),
	 FPM_InitFixedPoint_m(0.06640625, s4p11_T),
	 FPM_InitFixedPoint_m(0.09765625, s4p11_T),
	 FPM_InitFixedPoint_m(0.1328125, s4p11_T),
	 FPM_InitFixedPoint_m(0.17578125, s4p11_T),
	 FPM_InitFixedPoint_m(0.21875, s4p11_T),
	 FPM_InitFixedPoint_m(0.26953125, s4p11_T),
	 FPM_InitFixedPoint_m(0.328125, s4p11_T),
	 FPM_InitFixedPoint_m(0.38671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.453125, s4p11_T),
	 FPM_InitFixedPoint_m(0.5234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.59765625, s4p11_T),
	 FPM_InitFixedPoint_m(0.6796875, s4p11_T),
	 FPM_InitFixedPoint_m(0.76171875, s4p11_T),
	 FPM_InitFixedPoint_m(0.8515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.94921875, s4p11_T),
	 FPM_InitFixedPoint_m(1.046875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.03515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.0625, s4p11_T),
	 FPM_InitFixedPoint_m(0.0859375, s4p11_T),
	 FPM_InitFixedPoint_m(0.1171875, s4p11_T),
	 FPM_InitFixedPoint_m(0.15234375, s4p11_T),
	 FPM_InitFixedPoint_m(0.1875, s4p11_T),
	 FPM_InitFixedPoint_m(0.23046875, s4p11_T),
	 FPM_InitFixedPoint_m(0.2734375, s4p11_T),
	 FPM_InitFixedPoint_m(0.3203125, s4p11_T),
	 FPM_InitFixedPoint_m(0.37109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.42578125, s4p11_T),
	 FPM_InitFixedPoint_m(0.48046875, s4p11_T),
	 FPM_InitFixedPoint_m(0.54296875, s4p11_T),
	 FPM_InitFixedPoint_m(0.60546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.7421875, s4p11_T),
	 FPM_InitFixedPoint_m(0.81640625, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.015625, s4p11_T),
	 FPM_InitFixedPoint_m(0.03515625, s4p11_T),
	 FPM_InitFixedPoint_m(0.05859375, s4p11_T),
	 FPM_InitFixedPoint_m(0.0859375, s4p11_T),
	 FPM_InitFixedPoint_m(0.11328125, s4p11_T),
	 FPM_InitFixedPoint_m(0.14453125, s4p11_T),
	 FPM_InitFixedPoint_m(0.17578125, s4p11_T),
	 FPM_InitFixedPoint_m(0.21484375, s4p11_T),
	 FPM_InitFixedPoint_m(0.25390625, s4p11_T),
	 FPM_InitFixedPoint_m(0.29296875, s4p11_T),
	 FPM_InitFixedPoint_m(0.33984375, s4p11_T),
	 FPM_InitFixedPoint_m(0.38671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.4375, s4p11_T),
	 FPM_InitFixedPoint_m(0.48828125, s4p11_T),
	 FPM_InitFixedPoint_m(0.546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.60546875, s4p11_T),
	 FPM_InitFixedPoint_m(0.66796875, s4p11_T),
	 FPM_InitFixedPoint_m(0.73046875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.01, s4p11_T),
	 FPM_InitFixedPoint_m(0.02, s4p11_T),
	 FPM_InitFixedPoint_m(0.035, s4p11_T),
	 FPM_InitFixedPoint_m(0.06, s4p11_T),
	 FPM_InitFixedPoint_m(0.08, s4p11_T),
	 FPM_InitFixedPoint_m(0.12, s4p11_T),
	 FPM_InitFixedPoint_m(0.16, s4p11_T), FPM_InitFixedPoint_m(0.2, s4p11_T),
	 FPM_InitFixedPoint_m(0.24, s4p11_T),
	 FPM_InitFixedPoint_m(0.29, s4p11_T),
	 FPM_InitFixedPoint_m(0.35, s4p11_T),
	 FPM_InitFixedPoint_m(0.39, s4p11_T),
	 FPM_InitFixedPoint_m(0.46, s4p11_T),
	 FPM_InitFixedPoint_m(0.51171875, s4p11_T),
	 FPM_InitFixedPoint_m(0.5625, s4p11_T),
	 FPM_InitFixedPoint_m(0.62109375, s4p11_T),
	 FPM_InitFixedPoint_m(0.6796875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.01, s4p11_T),
	 FPM_InitFixedPoint_m(0.02, s4p11_T),
	 FPM_InitFixedPoint_m(0.035, s4p11_T),
	 FPM_InitFixedPoint_m(0.06, s4p11_T),
	 FPM_InitFixedPoint_m(0.08, s4p11_T), FPM_InitFixedPoint_m(0.1, s4p11_T),
	 FPM_InitFixedPoint_m(0.14, s4p11_T),
	 FPM_InitFixedPoint_m(0.18, s4p11_T),
	 FPM_InitFixedPoint_m(0.21, s4p11_T),
	 FPM_InitFixedPoint_m(0.26, s4p11_T), FPM_InitFixedPoint_m(0.3, s4p11_T),
	 FPM_InitFixedPoint_m(0.34, s4p11_T),
	 FPM_InitFixedPoint_m(0.3984375, s4p11_T),
	 FPM_InitFixedPoint_m(0.4375, s4p11_T),
	 FPM_InitFixedPoint_m(0.48046875, s4p11_T),
	 FPM_InitFixedPoint_m(0.52734375, s4p11_T),
	 FPM_InitFixedPoint_m(0.57421875, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.01, s4p11_T),
	 FPM_InitFixedPoint_m(0.03, s4p11_T),
	 FPM_InitFixedPoint_m(0.05, s4p11_T),
	 FPM_InitFixedPoint_m(0.07, s4p11_T),
	 FPM_InitFixedPoint_m(0.095, s4p11_T),
	 FPM_InitFixedPoint_m(0.13, s4p11_T),
	 FPM_InitFixedPoint_m(0.16, s4p11_T), FPM_InitFixedPoint_m(0.2, s4p11_T),
	 FPM_InitFixedPoint_m(0.24, s4p11_T),
	 FPM_InitFixedPoint_m(0.28, s4p11_T),
	 FPM_InitFixedPoint_m(0.32, s4p11_T),
	 FPM_InitFixedPoint_m(0.3671875, s4p11_T),
	 FPM_InitFixedPoint_m(0.40625, s4p11_T),
	 FPM_InitFixedPoint_m(0.4453125, s4p11_T),
	 FPM_InitFixedPoint_m(0.48828125, s4p11_T),
	 FPM_InitFixedPoint_m(0.53125, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.01, s4p11_T),
	 FPM_InitFixedPoint_m(0.015, s4p11_T),
	 FPM_InitFixedPoint_m(0.03, s4p11_T),
	 FPM_InitFixedPoint_m(0.05, s4p11_T),
	 FPM_InitFixedPoint_m(0.07, s4p11_T), FPM_InitFixedPoint_m(0.1, s4p11_T),
	 FPM_InitFixedPoint_m(0.135, s4p11_T),
	 FPM_InitFixedPoint_m(0.16, s4p11_T), FPM_InitFixedPoint_m(0.2, s4p11_T),
	 FPM_InitFixedPoint_m(0.23, s4p11_T),
	 FPM_InitFixedPoint_m(0.26, s4p11_T),
	 FPM_InitFixedPoint_m(0.31, s4p11_T),
	 FPM_InitFixedPoint_m(0.35, s4p11_T),
	 FPM_InitFixedPoint_m(0.38, s4p11_T),
	 FPM_InitFixedPoint_m(0.43, s4p11_T),
	 FPM_InitFixedPoint_m(0.47265625, s4p11_T)},
	{FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(0.01, s4p11_T),
	 FPM_InitFixedPoint_m(0.015, s4p11_T),
	 FPM_InitFixedPoint_m(0.03, s4p11_T),
	 FPM_InitFixedPoint_m(0.05, s4p11_T),
	 FPM_InitFixedPoint_m(0.07, s4p11_T), FPM_InitFixedPoint_m(0.1, s4p11_T),
	 FPM_InitFixedPoint_m(0.135, s4p11_T),
	 FPM_InitFixedPoint_m(0.16, s4p11_T), FPM_InitFixedPoint_m(0.2, s4p11_T),
	 FPM_InitFixedPoint_m(0.23, s4p11_T),
	 FPM_InitFixedPoint_m(0.26, s4p11_T),
	 FPM_InitFixedPoint_m(0.31, s4p11_T),
	 FPM_InitFixedPoint_m(0.35, s4p11_T),
	 FPM_InitFixedPoint_m(0.38, s4p11_T),
	 FPM_InitFixedPoint_m(0.43, s4p11_T),
	 FPM_InitFixedPoint_m(0.47265625, s4p11_T)}};


/****************************** AssistFirewall *******************************/
#pragma DATA_SECTION(k_AsstFWFiltKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AsstFWFiltKn_Hz_f32 = 8.0f;

#pragma DATA_SECTION(k_AsstFWFWActiveLPF_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AsstFWFWActiveLPF_Hz_f32 = 50.0f;

#pragma DATA_SECTION(k_AsstFWInpLimitBaseAsst_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AsstFWInpLimitBaseAsst_MtrNm_f32 = 8.8f;

#pragma DATA_SECTION(k_AsstFWInpLimitHFA_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AsstFWInpLimitHFA_MtrNm_f32 = 8.8f;

#pragma DATA_SECTION(k_AsstFWInpLimitHysComp_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AsstFWInpLimitHysComp_MtrNm_f32 = 8.8f;

#pragma DATA_SECTION(k_AsstFWNstep_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_AsstFWNstep_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_AsstFWPstep_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_AsstFWPstep_Cnt_u16 = 1U;

#pragma DATA_SECTION(t_AsstFWPstepNstepThresh_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_AsstFWPstepNstepThresh_Cnt_u16[2] = {50U, 100U};


/******************************** AvgFricLrn *********************************/
#pragma DATA_SECTION(k_AvgFricLPFKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AvgFricLPFKn_Hz_f32 = 0.1f;

#pragma DATA_SECTION(k_BaselineEOLFric_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_BaselineEOLFric_HwNm_f32 = 0.0f;

#pragma DATA_SECTION(k_DataPrepLPFKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DataPrepLPFKn_Hz_f32 = 30.0f;

#pragma DATA_SECTION(k_FricOffsetLPFKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_FricOffsetLPFKn_Hz_f32 = 2.0f;

#pragma DATA_SECTION(k_FrictionDiagThreshold_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_FrictionDiagThreshold_HwNm_f32 = 15.0f;

#pragma DATA_SECTION(k_FrictionDiagTimer_mS_u32, ".FlashCalSeg");
CONST(uint32, CAL_CONST) k_FrictionDiagTimer_mS_u32 = 50000UL;

#pragma DATA_SECTION(k_HwPosAuthMin_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HwPosAuthMin_Uls_f32 = 0.98f;

#pragma DATA_SECTION(k_IgnCycleFricChgLim_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_IgnCycleFricChgLim_HwNm_f32 = 50.0f;

#pragma DATA_SECTION(k_LearningGain_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LearningGain_Uls_f32 = 0.2f;

#pragma DATA_SECTION(k_LearningThreshold_Cnt_u32, ".FlashCalSeg");
CONST(uint32, CAL_CONST) k_LearningThreshold_Cnt_u32 = 1UL;

#pragma DATA_SECTION(k_RangeCounterLimit_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_RangeCounterLimit_Cnt_u16 = 65534U;

#pragma DATA_SECTION(k_SatFricChgLim_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SatFricChgLim_HwNm_f32 = 50.0f;

#pragma DATA_SECTION(k_TempMax_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TempMax_DegC_f32 = 100.0f;

#pragma DATA_SECTION(k_TempMin_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TempMin_DegC_f32 = 0.0f;

#pragma DATA_SECTION(t_InvRatioX_HwDeg_u11p5, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_InvRatioX_HwDeg_u11p5[10] = 
	{FPM_InitFixedPoint_m(0.0, u11p5_T), FPM_InitFixedPoint_m(30.0, u11p5_T),
	 FPM_InitFixedPoint_m(60.0, u11p5_T),
	 FPM_InitFixedPoint_m(90.0, u11p5_T),
	 FPM_InitFixedPoint_m(120.0, u11p5_T),
	 FPM_InitFixedPoint_m(180.0, u11p5_T),
	 FPM_InitFixedPoint_m(270.0, u11p5_T),
	 FPM_InitFixedPoint_m(360.0, u11p5_T),
	 FPM_InitFixedPoint_m(450.0, u11p5_T),
	 FPM_InitFixedPoint_m(540.0, u11p5_T)};

#pragma DATA_SECTION(t_InvRatioY_HwNmpMtrNm_u6p10, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_InvRatioY_HwNmpMtrNm_u6p10[10] = 
	{FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T),
	 FPM_InitFixedPoint_m(23.7, u6p10_T)};

#pragma DATA_SECTION(t2_BaselineRangeCounter_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t2_BaselineRangeCounter_Cnt_u16[8][3] = {{0U, 0U,
	 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U,
	 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}};

#pragma DATA_SECTION(t2_VehSpd_Kph_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) t2_VehSpd_Kph_f32[4][2] = {{0.0f, 5.0f}, {60.0f,
	 80.0f}, {80.0f, 100.0f}, {100.0f, 120.0f}};


/****************************** BatteryVoltage *******************************/
#pragma DATA_SECTION(k_MaxBattVoltDiff_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MaxBattVoltDiff_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_VecuCorrLim_Cnt_Str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_VecuCorrLim_Cnt_Str = {120,1,3};

#pragma DATA_SECTION(k_VecuVbatCorrLim_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_VecuVbatCorrLim_Volts_f32 = 0.73f;

#pragma DATA_SECTION(k_VswitchCorrLim_Cnt_Str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_VswitchCorrLim_Cnt_Str = {120,1,3};

#pragma DATA_SECTION(k_VswitchCorrLim_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_VswitchCorrLim_Volts_f32 = 0.73f;


/************************** BatteryVoltage, BkCpPc ***************************/
#pragma DATA_SECTION(k_MaxSwitchedVolt_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MaxSwitchedVolt_Volts_f32 = 16.0f;


/********************************** BkCpPc ***********************************/
#pragma DATA_SECTION(k_ChargeMinDeltaExtOp_Volt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ChargeMinDeltaExtOp_Volt_f32 = 5.0f;

#pragma DATA_SECTION(k_ChargeMinDeltaNonOp_Volt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ChargeMinDeltaNonOp_Volt_f32 = 0.0f;

#pragma DATA_SECTION(k_ChargeMinDeltaNormlOp_Volt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ChargeMinDeltaNormlOp_Volt_f32 = 6.0f;

#pragma DATA_SECTION(k_ChargePumpDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_ChargePumpDiag_Cnt_str = {100, 4, 1};

#pragma DATA_SECTION(k_MaxDischEst_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MaxDischEst_Uls_f32 = 0.99f;

#pragma DATA_SECTION(k_MinDischEst_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MinDischEst_Uls_f32 = 0.98f;

#pragma DATA_SECTION(k_MtrMotionThresh_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MtrMotionThresh_MtrRadpS_f32 = 100.0f;

#pragma DATA_SECTION(k_OVERRIDESIGDIAGOpenThresh_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_OVERRIDESIGDIAGOpenThresh_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_PMOSDIAGOpenThresh_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PMOSDIAGOpenThresh_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_PMOSTError_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PMOSTError_mS_u16 = 50U;

#pragma DATA_SECTION(k_PMOSVError_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PMOSVError_Volts_f32 = 1.0f;

#pragma DATA_SECTION(k_PrechargeThresh_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PrechargeThresh_mS_u16 = 400U;

#pragma DATA_SECTION(k_PwrDiscCloseThresh_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PwrDiscCloseThresh_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_PwrDiscOpenThresh_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PwrDiscOpenThresh_Volts_f32 = 2.0f;

#pragma DATA_SECTION(k_VbattSwitchThreshExNorm_Volt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_VbattSwitchThreshExNorm_Volt_f32 = 8.0f;

#pragma DATA_SECTION(k_VbattSwitchThreshNonExt_Volt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_VbattSwitchThreshNonExt_Volt_f32 = 7.0f;

#pragma DATA_SECTION(k_VerifyPwrDiscCloseThresh_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_VerifyPwrDiscCloseThresh_mS_u16 = 100U;

#pragma DATA_SECTION(k_VerifyPwrDiscOpenThresh_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_VerifyPwrDiscOpenThresh_mS_u16 = 100U;

#pragma DATA_SECTION(k_VswitchDeltaThresh_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_VswitchDeltaThresh_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_WaitForSqrWaveThresh_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_WaitForSqrWaveThresh_mS_u16 = 100U;


/************************** BMW_UKL_MCV_EPS_TMS570 ***************************/
#pragma DATA_SECTION(k_CustSrvcHandsOnThres_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CustSrvcHandsOnThres_HwNm_f32 = 2.0f;

#pragma DATA_SECTION(k_CustSrvcHandsOnTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CustSrvcHandsOnTime_mS_u16 = 5000U;

#pragma DATA_SECTION(k_CustSrvcHandwheelAngDelta_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CustSrvcHandwheelAngDelta_HwDeg_f32 = 180.0f;

#pragma DATA_SECTION(k_CustSrvcHandwheelAngTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CustSrvcHandwheelAngTime_mS_u16 = 2000U;

#pragma DATA_SECTION(k_CustSrvcHandwheelVelThres_HwRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CustSrvcHandwheelVelThres_HwRadpS_f32 = 7.0f;

#pragma DATA_SECTION(k_CustSrvcHandwheelVelTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CustSrvcHandwheelVelTime_mS_u16 = 750U;

#pragma DATA_SECTION(k_CustSrvcOpStateWaitTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CustSrvcOpStateWaitTime_mS_u16 = 100U;

#pragma DATA_SECTION(k_CustSrvcPosTrajHoldTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CustSrvcPosTrajHoldTime_mS_u16 = 5000U;

#pragma DATA_SECTION(k_CustSrvcPosTrajThres_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CustSrvcPosTrajThres_HwDeg_f32 = 2.0f;

#pragma DATA_SECTION(k_VrefOORDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_VrefOORDiag_Cnt_str = {100,4,1};


/*********************** BMW_UKL_MCV_EPS_TMS570, DemIf ***********************/
#pragma DATA_SECTION(t_DtcMaskEnbl_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) t_DtcMaskEnbl_Cnt_u08[DEM_NUMBER_OF_EVENTS] = { 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
	 0x02, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x02, 0x00,
	 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


/**************** BMW_UKL_MCV_EPS_TMS570, IoHwAbstractionUsr *****************/
#pragma DATA_SECTION(k_ADCHwTrqScaling_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ADCHwTrqScaling_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_ADCMtrPosScaling_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ADCMtrPosScaling_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_ADCTempSnsrOffset_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ADCTempSnsrOffset_Uls_f32 = 0.0f;

#pragma DATA_SECTION(k_ADCTempSnsrScaling_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ADCTempSnsrScaling_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_ADCVbattScaling_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ADCVbattScaling_Uls_f32 = 6.74712643678f;

#pragma DATA_SECTION(k_ADCVbattSwitchScaling_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ADCVbattSwitchScaling_Uls_f32 = 3.36966824645f;

#pragma DATA_SECTION(k_ADCVrefScaling_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ADCVrefScaling_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_ChrgPumpScaling_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ChrgPumpScaling_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_GenMaxADCWaitTime_uS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_GenMaxADCWaitTime_uS_u16 = 1000U;

#pragma DATA_SECTION(k_MaxADCConvTime_uS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MaxADCConvTime_uS_u16 = 100U;

#pragma DATA_SECTION(k_PDScaling_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PDScaling_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_VrefMax_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_VrefMax_Volts_f32 = 3.0f;

#pragma DATA_SECTION(k_VrefMin_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_VrefMin_Volts_f32 = 3.0f;


/******************* BMW_UKL_MCV_EPS_TMS570, SrlComOutput ********************/
#pragma DATA_SECTION(k_HwPTrvExAuth_Uls_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_HwPTrvExAuth_Uls_u8p8 = 
	FPM_InitFixedPoint_m(0.015, u8p8_T);


/****************** BMW_UKL_MCV_EPS_TMS570, SVDiag, SVDrvr *******************/
#pragma DATA_SECTION(t_CommOffsetTblY_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2] = { 63U, 0U };


/********************** BMW_UKL_MCV_EPS_TMS570, SVDrvr ***********************/
#pragma DATA_SECTION(k_MinDiodeCondCurr_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MinDiodeCondCurr_MtrNm_f32 = 0.01171875f;

#pragma DATA_SECTION(t_CommOffsetTblX_Uls_u3p13, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_CommOffsetTblX_Uls_u3p13[2] = 
	{ FPM_InitFixedPoint_m(0.6, u3p13_T),
	FPM_InitFixedPoint_m(0.95, u3p13_T) };

#pragma DATA_SECTION(t_DTCompTblX_Uls_u3p13, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DTCompTblX_Uls_u3p13[2] = 
	{ FPM_InitFixedPoint_m(0.0, u3p13_T),
	 FPM_InitFixedPoint_m(0.12, u3p13_T) };

#pragma DATA_SECTION(t_DTCompTblY_Uls_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DTCompTblY_Uls_u8p8[2] = 
	{ FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T) };


/********************************** BVDiag ***********************************/
#pragma DATA_SECTION(k_LowDetect_ms_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_LowDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(1000.0, u16p0_T);

#pragma DATA_SECTION(k_LowDetect_Volts_u10p6, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_LowDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_LowNotDetect_ms_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_LowNotDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(600.0, u16p0_T);

#pragma DATA_SECTION(k_LowNotDetect_Volts_u10p6, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_LowNotDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_MSALowDetect_ms_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MSALowDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(1000.0, u16p0_T);

#pragma DATA_SECTION(k_MSALowDetect_Volts_u10p6, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MSALowDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_MSALowNotDetect_ms_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MSALowNotDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(600.0, u16p0_T);

#pragma DATA_SECTION(k_MSALowNotDetect_Volts_u10p6, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MSALowNotDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(9.0, u10p6_T);

#pragma DATA_SECTION(k_OvDetect_ms_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_OvDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(1000.0, u16p0_T);

#pragma DATA_SECTION(k_OvDetect_Volts_u10p6, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_OvDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(18.0, u10p6_T);

#pragma DATA_SECTION(k_OvNotDetect_ms_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_OvNotDetect_ms_u16p0 = 
	FPM_InitFixedPoint_m(600.0, u16p0_T);

#pragma DATA_SECTION(k_OvNotDetect_Volts_u10p6, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_OvNotDetect_Volts_u10p6 = 
	FPM_InitFixedPoint_m(18.0, u10p6_T);


/****************************** CBD_BmwRtnAbrn *******************************/
#pragma DATA_SECTION(k_Cmn_SysTrqRatio_HwNmpMtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_Cmn_SysTrqRatio_HwNmpMtrNm_f32 = 20.0f;

#pragma DATA_SECTION(t2_BmwRA_IntgtrLimTblY_HwDeg_u10p6, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t2_BmwRA_IntgtrLimTblY_HwDeg_u10p6[5][9] = 
	{{FPM_InitFixedPoint_m(12.0, u10p6_T),
	FPM_InitFixedPoint_m(30.0, u10p6_T),FPM_InitFixedPoint_m(30.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(90.0, u10p6_T),FPM_InitFixedPoint_m(90.0, u10p6_T),
	FPM_InitFixedPoint_m(120.0, u10p6_T),
	FPM_InitFixedPoint_m(120.0, u10p6_T)},
	{FPM_InitFixedPoint_m(12.0, u10p6_T),FPM_InitFixedPoint_m(30.0, u10p6_T),
	FPM_InitFixedPoint_m(30.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T),FPM_InitFixedPoint_m(90.0, u10p6_T),
	FPM_InitFixedPoint_m(90.0, u10p6_T),FPM_InitFixedPoint_m(120.0, u10p6_T),
	FPM_InitFixedPoint_m(120.0, u10p6_T)},
	{FPM_InitFixedPoint_m(12.0, u10p6_T),FPM_InitFixedPoint_m(30.0, u10p6_T),
	FPM_InitFixedPoint_m(30.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(90.0, u10p6_T),FPM_InitFixedPoint_m(90.0, u10p6_T),
	FPM_InitFixedPoint_m(90.0, u10p6_T)},
	{FPM_InitFixedPoint_m(12.0, u10p6_T),FPM_InitFixedPoint_m(30.0, u10p6_T),
	FPM_InitFixedPoint_m(30.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T)},
	{FPM_InitFixedPoint_m(12.0, u10p6_T),FPM_InitFixedPoint_m(30.0, u10p6_T),
	FPM_InitFixedPoint_m(30.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T),FPM_InitFixedPoint_m(60.0, u10p6_T),
	FPM_InitFixedPoint_m(60.0, u10p6_T)}};


/******************************** CMS_Common *********************************/
#pragma DATA_SECTION(k_CMSGotoPosPol_Cnt_s08, ".FlashCalSeg");
CONST(sint8, CAL_CONST) k_CMSGotoPosPol_Cnt_s08 = 1;

#pragma DATA_SECTION(k_F00FHandsOnThres_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_F00FHandsOnThres_HwNm_f32 = 0.5f;

#pragma DATA_SECTION(k_NxtrSrvcHandsOnTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_NxtrSrvcHandsOnTime_mS_u16 = 5000U;

#pragma DATA_SECTION(k_NxtrSrvcPosTrajHoldTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_NxtrSrvcPosTrajHoldTime_mS_u16 = 5000U;

#pragma DATA_SECTION(k_NxtrSrvcPosTrajThres_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_NxtrSrvcPosTrajThres_HwDeg_f32 = 2.0f;


/******************************* CtrldDisShtdn *******************************/
#pragma DATA_SECTION(k_CntrlDmpRampEnd_Uls_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CntrlDmpRampEnd_Uls_u8p8 = 
	FPM_InitFixedPoint_m(0.0, u8p8_T);

#pragma DATA_SECTION(k_CtrlDmpTmrBkptOne_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CtrlDmpTmrBkptOne_mS_u16 = 100U;

#pragma DATA_SECTION(k_CtrlDmpTmrBkptTwo_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CtrlDmpTmrBkptTwo_mS_u16 = 1000U;

#pragma DATA_SECTION(k_CtrlDpVelThr_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CtrlDpVelThr_MtrRadpS_f32 = 2.3f;

#pragma DATA_SECTION(k_F2Damping_MtrNmpRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_F2Damping_MtrNmpRadpS_f32 = 0.036f;

#pragma DATA_SECTION(k_MaxCtrlDmpLimit_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MaxCtrlDmpLimit_MtrNm_f32 = 3.0f;


/********************************* CtrlTemp **********************************/
#pragma DATA_SECTION(k_CustDiagAmbLowEnable_Cnt_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_CustDiagAmbLowEnable_Cnt_lgc = FALSE;

#pragma DATA_SECTION(k_CustDiagAmbLowThresh_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CustDiagAmbLowThresh_DegC_f32 = -30.0f;

#pragma DATA_SECTION(k_TempSensDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_TempSensDiag_Cnt_str = {40,2,1};

#pragma DATA_SECTION(k_TempSensHighLimit_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TempSensHighLimit_DegC_f32 = 160.0f;

#pragma DATA_SECTION(k_TempSensLowLimit_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TempSensLowLimit_DegC_f32 = -44.0f;

#pragma DATA_SECTION(k_TempSnsrDefVal_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TempSnsrDefVal_DegC_f32 = 60.0f;

#pragma DATA_SECTION(k_TempSnsrFiltDft_Cnt_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_TempSnsrFiltDft_Cnt_lgc = FALSE;

#pragma DATA_SECTION(k_TempSnsrLPFKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TempSnsrLPFKn_Hz_f32 = 0.1f;

#pragma DATA_SECTION(k_TempSnsrOffset_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TempSnsrOffset_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_TempSnsrScaling_DegpVolt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TempSnsrScaling_DegpVolt_f32 = 100.0f;


/******************************** CustPL_BMW *********************************/
#pragma DATA_SECTION(k_AmpDecSlew_AmppS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AmpDecSlew_AmppS_f32 = 12000.0f;

#pragma DATA_SECTION(k_AmpIncSlew_AmppS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AmpIncSlew_AmppS_f32 = 60.0f;

#pragma DATA_SECTION(k_MSARamp1Time_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MSARamp1Time_Sec_f32 = 0.5f;

#pragma DATA_SECTION(k_MSARamp2Time_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MSARamp2Time_Sec_f32 = 0.5f;

#pragma DATA_SECTION(k_MSARamp3AsstDis_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MSARamp3AsstDis_Sec_f32 = 0.5f;

#pragma DATA_SECTION(k_MSARamp4Time_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MSARamp4Time_Sec_f32 = 0.5f;

#pragma DATA_SECTION(k_TLoopMSA_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TLoopMSA_Sec_f32 = 0.01f;

#pragma DATA_SECTION(k_tMSAClock_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_tMSAClock_Sec_f32 = 2.0f;

#pragma DATA_SECTION(t_VehSpdLmtTblX_Kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_VehSpdLmtTblX_Kph_u9p7[6] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(10.0, u9p7_T),
	FPM_InitFixedPoint_m(40.0, u9p7_T),FPM_InitFixedPoint_m(80.0, u9p7_T),
	FPM_InitFixedPoint_m(100.0, u9p7_T),FPM_InitFixedPoint_m(150.0, u9p7_T) };


/********************************** Damping **********************************/
#pragma DATA_SECTION(k_HPSbaseC1_MtrNmpMtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HPSbaseC1_MtrNmpMtrRadpS_f32 = 0.000521083f;

#pragma DATA_SECTION(k_HPSbaseC2_MtrNmpMtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HPSbaseC2_MtrNmpMtrRadpS_f32 = 0.0000288893f;

#pragma DATA_SECTION(k_HPSbaseC3_MtrNmpMtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HPSbaseC3_MtrNmpMtrRadpS_f32 = 0.00618654f;

#pragma DATA_SECTION(k_HPSbaseC4_MtrNmpMtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HPSbaseC4_MtrNmpMtrRadpS_f32 = 0.00000956832f;

#pragma DATA_SECTION(k_HPSOutLimit_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HPSOutLimit_MtrNm_f32 = 0.0f;

#pragma DATA_SECTION(k_QDDHwTrqBckLash_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_QDDHwTrqBckLash_HwNm_f32 = 0.0f;

#pragma DATA_SECTION(k_QddHwTrqDampKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_QddHwTrqDampKn_Hz_f32 = 15.0f;

#pragma DATA_SECTION(k_QDDMtrVelBckLash_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_QDDMtrVelBckLash_MtrRadpS_f32 = 0.0f;

#pragma DATA_SECTION(k_QddMtrVelDampKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_QddMtrVelDampKn_Hz_f32 = 15.0f;

#pragma DATA_SECTION(k_QddSfLFPKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_QddSfLFPKn_Hz_f32 = 15.0f;

#pragma DATA_SECTION(k_Quad13DmpMult_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_Quad13DmpMult_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_Quad24DmpMult_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_Quad24DmpMult_Uls_f32 = 1.0f;


/****************************** DampingFirewall ******************************/
#pragma DATA_SECTION(k_DampFWErrThresh_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DampFWErrThresh_MtrNm_f32 = 0.2f;

#pragma DATA_SECTION(k_DampFWFWActiveLPF_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DampFWFWActiveLPF_Hz_f32 = 2.0f;

#pragma DATA_SECTION(k_DampFWInCmpNStep_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_DampFWInCmpNStep_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_DampFWInCmpPStep_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_DampFWInCmpPStep_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_DampFWInpLimitDamp_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DampFWInpLimitDamp_MtrNm_f32 = 5.0f;

#pragma DATA_SECTION(k_DampFWNstep_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_DampFWNstep_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_DampFWVBICLPF_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DampFWVBICLPF_Hz_f32 = 10.0f;

#pragma DATA_SECTION(t_DampFWAddDampAFWX_MtrRadpS_u11p5, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DampFWAddDampAFWX_MtrRadpS_u11p5[8] = 
	{FPM_InitFixedPoint_m(0.0, u11p5_T), FPM_InitFixedPoint_m(25.0, u11p5_T),
	 FPM_InitFixedPoint_m(50.0, u11p5_T),
	 FPM_InitFixedPoint_m(75.0, u11p5_T),
	 FPM_InitFixedPoint_m(100.0, u11p5_T),
	 FPM_InitFixedPoint_m(200.0, u11p5_T),
	 FPM_InitFixedPoint_m(300.0, u11p5_T),
	 FPM_InitFixedPoint_m(400.0, u11p5_T)};

#pragma DATA_SECTION(t_DampFWAddDampAFWY_MtrNm_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DampFWAddDampAFWY_MtrNm_u5p11[8] = 
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T)};

#pragma DATA_SECTION(t_DampFWAddDampDFWX_MtrRadpS_u11p5, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DampFWAddDampDFWX_MtrRadpS_u11p5[8] = 
	{FPM_InitFixedPoint_m(0.0, u11p5_T), FPM_InitFixedPoint_m(25.0, u11p5_T),
	 FPM_InitFixedPoint_m(50.0, u11p5_T),
	 FPM_InitFixedPoint_m(75.0, u11p5_T),
	 FPM_InitFixedPoint_m(100.0, u11p5_T),
	 FPM_InitFixedPoint_m(200.0, u11p5_T),
	 FPM_InitFixedPoint_m(300.0, u11p5_T),
	 FPM_InitFixedPoint_m(400.0, u11p5_T)};

#pragma DATA_SECTION(t_DampFWAddDampDFWY_MtrNm_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DampFWAddDampDFWY_MtrNm_u5p11[8] = 
	{FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.0, u5p11_T), FPM_InitFixedPoint_m(0.0, u5p11_T)};

#pragma DATA_SECTION(t_DampFWDampInrtCmpPNThesh_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DampFWDampInrtCmpPNThesh_Cnt_u16[2] = {50U,200U};

#pragma DATA_SECTION(t_DampFWDefltDampX_MtrRadpS_u11p5, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DampFWDefltDampX_MtrRadpS_u11p5[11] = 
	{FPM_InitFixedPoint_m(0.0, u11p5_T), FPM_InitFixedPoint_m(10.0, u11p5_T),
	 FPM_InitFixedPoint_m(25.0, u11p5_T),
	 FPM_InitFixedPoint_m(50.0, u11p5_T),
	 FPM_InitFixedPoint_m(100.0, u11p5_T),
	 FPM_InitFixedPoint_m(150.0, u11p5_T),
	 FPM_InitFixedPoint_m(200.0, u11p5_T),
	 FPM_InitFixedPoint_m(250.0, u11p5_T),
	 FPM_InitFixedPoint_m(300.0, u11p5_T),
	 FPM_InitFixedPoint_m(350.0, u11p5_T),
	 FPM_InitFixedPoint_m(400.0, u11p5_T)};


/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
#pragma DATA_SECTION(k_CmnSysKinRatio_MtrDegpHwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CmnSysKinRatio_MtrDegpHwDeg_f32 = 22.0f;

#pragma DATA_SECTION(k_CmnTbarStiff_NmpDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CmnTbarStiff_NmpDeg_f32 = 2.5f;

#pragma DATA_SECTION(k_DmpDecelGain_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DmpDecelGain_Uls_f32 = 3.0f;

#pragma DATA_SECTION(k_DmpDecelGainFSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DmpDecelGainFSlew_UlspS_f32 = 4500.0f;

#pragma DATA_SECTION(k_DmpGainOffThresh_KphpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DmpGainOffThresh_KphpS_f32 = 1.0f;

#pragma DATA_SECTION(k_DmpGainOnThresh_KphpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DmpGainOnThresh_KphpS_f32 = 10.0f;

#pragma DATA_SECTION(k_InrtCmp_MtrVel_ScaleFactor_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_InrtCmp_MtrVel_ScaleFactor_Uls_f32 = 1.0f;

#pragma DATA_SECTION(t_DmpDecelGainSlewX_MtrRadpS_u11p5, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DmpDecelGainSlewX_MtrRadpS_u11p5[6] = 
	{FPM_InitFixedPoint_m(0.0, u11p5_T), FPM_InitFixedPoint_m(20.0, u11p5_T),
	FPM_InitFixedPoint_m(50.0, u11p5_T),FPM_InitFixedPoint_m(100.0, u11p5_T),
	 FPM_InitFixedPoint_m(200.0, u11p5_T),
	 FPM_InitFixedPoint_m(400.0, u11p5_T)};

#pragma DATA_SECTION(t_DmpDecelGainSlewY_UlspS_u13p3, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DmpDecelGainSlewY_UlspS_u13p3[6] = 
	{FPM_InitFixedPoint_m(4500.0, u13p3_T),
	FPM_InitFixedPoint_m(4500.0, u13p3_T),
	FPM_InitFixedPoint_m(4500.0, u13p3_T),
	FPM_InitFixedPoint_m(4500.0, u13p3_T),
	FPM_InitFixedPoint_m(4500.0, u13p3_T),
	FPM_InitFixedPoint_m(4500.0, u13p3_T)};

#pragma DATA_SECTION(t_DmpFiltKpWIRBlndY_Uls_u2p14, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DmpFiltKpWIRBlndY_Uls_u2p14[5] = 
	{ FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T) };

#pragma DATA_SECTION(t_RIAstWIRBlndTblY_Uls_u2p14, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_RIAstWIRBlndTblY_Uls_u2p14[5] = 
	{ FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T),FPM_InitFixedPoint_m(1.0, u2p14_T),
	FPM_InitFixedPoint_m(1.0, u2p14_T) };

#pragma DATA_SECTION(t_WIRBlndTblX_MtrNm_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_WIRBlndTblX_MtrNm_u8p8[5] = 
	{ FPM_InitFixedPoint_m(0.05078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.10546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.15625, u8p8_T),
	 FPM_InitFixedPoint_m(0.20703125, u8p8_T),
	 FPM_InitFixedPoint_m(0.2578125, u8p8_T) };


/********************************** DiagMgr **********************************/
#pragma DATA_SECTION(k_FltRmpRate_UlspmS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_FltRmpRate_UlspmS_f32[13] = { 0.0005f, 0.0005f,
	 0.0005f, 0.0005f, 0.0005f, 0.0005f, 0.0005f, 0.0005f, 0.0005f, 0.0005f,
	 0.0005f, 0.0005f, 0.0005f };

#pragma DATA_SECTION(k_FltRspTbl_Cnt_str, ".FlashCalSeg");
CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512] = { {0x000000, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0},
	 {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F, 0}, {0xC0000F,
	 0}, {0xC0000F, 0}, {0xC0000F, 0}  };

#pragma DATA_SECTION(t_BlkBoxGrp_Ptr_u32, ".FlashCalSeg");
CONST(uint32* const, CAL_CONST) t_BlkBoxGrp_Ptr_u32[7][3] = {{0,0,0},{0,0,0},
	{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

#pragma DATA_SECTION(t_SortedNTCs_Cnt_enum, ".FlashCalSeg");
CONST(NTCNumber, CAL_CONST) t_SortedNTCs_Cnt_enum[256] = { 0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,0x000,
	0x000 };


/******************************** DrvDynCtrl *********************************/
#pragma DATA_SECTION(k_DDActAstSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DDActAstSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(k_DDActDmpSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DDActDmpSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(k_DDActRtnSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DDActRtnSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(k_DDInActAstSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DDInActAstSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(k_DDInActDmpSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DDInActDmpSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(k_DDInActRtnSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DDInActRtnSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(t_DDFctrHwTrqX_HwNm_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DDFctrHwTrqX_HwNm_u8p8[9] = 
	{ FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(3.0, u8p8_T),
	FPM_InitFixedPoint_m(4.0, u8p8_T),FPM_InitFixedPoint_m(5.0, u8p8_T),
	FPM_InitFixedPoint_m(6.0, u8p8_T),FPM_InitFixedPoint_m(7.0, u8p8_T),
	FPM_InitFixedPoint_m(10.0, u8p8_T) };

#pragma DATA_SECTION(t_DDFctrMtrVelX_MtrRadpS_u12p4, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DDFctrMtrVelX_MtrRadpS_u12p4[9] = 
	{ FPM_InitFixedPoint_m(0.0, u12p4_T),FPM_InitFixedPoint_m(50.0, u12p4_T),
	FPM_InitFixedPoint_m(100.0, u12p4_T),
	FPM_InitFixedPoint_m(150.0, u12p4_T),
	FPM_InitFixedPoint_m(200.0, u12p4_T),
	FPM_InitFixedPoint_m(250.0, u12p4_T),
	FPM_InitFixedPoint_m(300.0, u12p4_T),
	FPM_InitFixedPoint_m(350.0, u12p4_T),
	FPM_InitFixedPoint_m(400.0, u12p4_T) };

#pragma DATA_SECTION(t_DDFctrVehSpdBS_Kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_DDFctrVehSpdBS_Kph_u9p7[8] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(10.0, u9p7_T),
	FPM_InitFixedPoint_m(20.0, u9p7_T),FPM_InitFixedPoint_m(30.0, u9p7_T),
	FPM_InitFixedPoint_m(40.0, u9p7_T),FPM_InitFixedPoint_m(50.0, u9p7_T),
	FPM_InitFixedPoint_m(80.0, u9p7_T),FPM_InitFixedPoint_m(100.0, u9p7_T) };

#pragma DATA_SECTION(t2_DDCFctrAstLimYM_Uls_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t2_DDCFctrAstLimYM_Uls_u8p8[8][9] = 
	{{FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T)},{FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.0, u8p8_T)},
	{FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T)},{FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.0, u8p8_T)},
	{FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T)},{FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.0, u8p8_T)},
	{FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	FPM_InitFixedPoint_m(2.0, u8p8_T)},{FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T), FPM_InitFixedPoint_m(2.0, u8p8_T),
	 FPM_InitFixedPoint_m(2.0, u8p8_T),FPM_InitFixedPoint_m(2.0, u8p8_T)}};

#pragma DATA_SECTION(t2_DDCFctrDmpLimYM_Uls_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t2_DDCFctrDmpLimYM_Uls_u8p8[8][9] = 
	{{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.0, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	FPM_InitFixedPoint_m(0.0, u8p8_T)},{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.0, u8p8_T)}};


/********************************** ElecPwr **********************************/
#pragma DATA_SECTION(k_CntlrInResist_Ohm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CntlrInResist_Ohm_f32 = 0.005f;

#pragma DATA_SECTION(k_PstcPowerLoss_Watts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PstcPowerLoss_Watts_f32 = 10.0f;


/****************************** EOTActuatorMng *******************************/
#pragma DATA_SECTION(k_EOTActiveRegionBypassMaxThresh_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_EOTActiveRegionBypassMaxThresh_Uls_f32 = 0.0f;

#pragma DATA_SECTION(k_EOTOriginalImpactandSoftEnd_Cnt_lgc, ".FlashCalSeg");
CONST(Boolean, CAL_CONST) k_EOTOriginalImpactandSoftEnd_Cnt_lgc = FALSE;

#pragma DATA_SECTION(k_EOTPosDepDempFinalSlew_MtrNmpS_T_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_EOTPosDepDempFinalSlew_MtrNmpS_T_f32 = 400.0f;


/************************** EOTActuatorMng, EtDmpFw **************************/
#pragma DATA_SECTION(k_EOTDynConf_Uls_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_EOTDynConf_Uls_u8p8 = 
	FPM_InitFixedPoint_m(0.80078125, u8p8_T);


/********************************** EtDmpFw **********************************/
#pragma DATA_SECTION(k_EOTDmpFWInactiveLim_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_EOTDmpFWInactiveLim_MtrNm_f32 = 8.8f;

#pragma DATA_SECTION(t_EOTDmpFWActiveBoundX_MtrRadpS_s11p4, ".FlashCalSeg");
CONST(sint16, CAL_CONST) t_EOTDmpFWActiveBoundX_MtrRadpS_s11p4[5] = 
	{FPM_InitFixedPoint_m(-700.0, s11p4_T),
	 FPM_InitFixedPoint_m(-5.0, s11p4_T),
	 FPM_InitFixedPoint_m(10.0, s11p4_T),
	 FPM_InitFixedPoint_m(50.0, s11p4_T),
	 FPM_InitFixedPoint_m(700.0, s11p4_T)};

#pragma DATA_SECTION(t_EOTDmpFWVehSpd_Kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_EOTDmpFWVehSpd_Kph_u9p7[4] = 
	{FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T),
	 FPM_InitFixedPoint_m(40.0, u9p7_T), FPM_InitFixedPoint_m(60.0, u9p7_T)};


/********************************* FrTrcvPhy *********************************/
#pragma DATA_SECTION(k_FrTxcvrBusOffTimer_ms_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_FrTxcvrBusOffTimer_ms_u16 = 0U;

#pragma DATA_SECTION(k_FrTxcvrERRnDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_FrTxcvrERRnDiag_Cnt_str = {200, 4, 1};

#pragma DATA_SECTION(k_FrTxcvrSpiDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_FrTxcvrSpiDiag_Cnt_str = {200, 4, 1};


/******************************** GenPosTraj *********************************/
#pragma DATA_SECTION(k_PosTrajMaxAccel_HwDegpSecSqr_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PosTrajMaxAccel_HwDegpSecSqr_f32 = 500.0f;

#pragma DATA_SECTION(k_PosTrajMaxVelocity_HwDegpSec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PosTrajMaxVelocity_HwDegpSec_f32 = 50.0f;


/************************ HiLoadStall, ThrmDutyCycle *************************/
#pragma DATA_SECTION(k_AbsMtrVelBkt_MtrRadps_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AbsMtrVelBkt_MtrRadps_f32 = 1.375f;


/*********************************** HwTrq ***********************************/
#pragma DATA_SECTION(k_AnaRngDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_AnaRngDiag_Cnt_str = {200, 4, 1};

#pragma DATA_SECTION(k_AnaT1T2ErrThreshold_Volts_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_AnaT1T2ErrThreshold_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.2, u5p11_T);

#pragma DATA_SECTION(k_CorrDiagFiltActiv_Volts_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CorrDiagFiltActiv_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.05, u5p11_T);

#pragma DATA_SECTION(k_CorrDiagKn_Cnts_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CorrDiagKn_Cnts_u16 = 814U;

#pragma DATA_SECTION(k_HwTorqCorrLimDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_HwTorqCorrLimDiag_Cnt_str = {12, 4, 1};

#pragma DATA_SECTION(k_HwTorqCorrLimThresh_HwNm_T_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HwTorqCorrLimThresh_HwNm_T_f32 = 2.5f;

#pragma DATA_SECTION(k_HwTrqSclNom_VoltspDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HwTrqSclNom_VoltspDeg_f32 = 0.5f;

#pragma DATA_SECTION(k_MaxHwTrqTrim_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MaxHwTrqTrim_Volts_f32 = 0.1f;

#pragma DATA_SECTION(k_MaxTrqSumLmt_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MaxTrqSumLmt_Volts_f32 = 3.2f;

#pragma DATA_SECTION(k_SSDiagKn_Cnts_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_SSDiagKn_Cnts_u16 = 814U;

#pragma DATA_SECTION(k_SSDiagLim_Volts_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_SSDiagLim_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.557, u5p11_T);

#pragma DATA_SECTION(k_SSFiltRecLim_Volt_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_SSFiltRecLim_Volt_u5p11 = 
	FPM_InitFixedPoint_m(0.488, u5p11_T);

#pragma DATA_SECTION(k_SumFiltRecLim_Volt_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_SumFiltRecLim_Volt_u5p11 = 
	FPM_InitFixedPoint_m(0.273, u5p11_T);

#pragma DATA_SECTION(k_SysCHwTorqCorrLimDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_SysCHwTorqCorrLimDiag_Cnt_str = {12, 4,
	 1};

#pragma DATA_SECTION(k_SysCHwTorqCorrLimThresh_HwNm_T_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SysCHwTorqCorrLimThresh_HwNm_T_f32 = 2.5f;

#pragma DATA_SECTION(k_T1AccRecLim_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_T1AccRecLim_Cnt_u16 = 0U;

#pragma DATA_SECTION(k_T1HghRange_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_T1HghRange_Volts_f32 = 4.5f;

#pragma DATA_SECTION(k_T1LowRange_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_T1LowRange_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_T2AccRecLim_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_T2AccRecLim_Cnt_u16 = 0U;

#pragma DATA_SECTION(k_T2HghRange_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_T2HghRange_Volts_f32 = 4.5f;

#pragma DATA_SECTION(k_T2LowRange_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_T2LowRange_Volts_f32 = 0.5f;

#pragma DATA_SECTION(k_TbarStiff_NmpDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TbarStiff_NmpDeg_f32 = 2.5f;

#pragma DATA_SECTION(k_TdiagCorrLim_Volts_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_TdiagCorrLim_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.1, u5p11_T);

#pragma DATA_SECTION(k_TdiagLim_Volts_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_TdiagLim_Volts_u5p11 = 
	FPM_InitFixedPoint_m(0.557, u5p11_T);

#pragma DATA_SECTION(k_TrqFltRecLim_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_TrqFltRecLim_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_TrqSensScaleMax_VoltspDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrqSensScaleMax_VoltspDeg_f32 = 0.6f;

#pragma DATA_SECTION(k_TrqSensScaleMin_VoltspDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrqSensScaleMin_VoltspDeg_f32 = 0.4f;

#pragma DATA_SECTION(t_TDiagFiltKnTbl_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_TDiagFiltKnTbl_Cnt_u16[17] = { 10667U, 10667U,
	 10667U, 10667U, 10667U, 7106U, 7330U, 6359U, 5674U, 5927U,6633U,6752U,
	6112U,5584U,5141U,4763U,4437U };

#pragma DATA_SECTION(t_TDiagIndptTbl_Volts_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_TDiagIndptTbl_Volts_u5p11[17] = 
	{ FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.15625, u5p11_T),
	 FPM_InitFixedPoint_m(0.3125, u5p11_T),
	 FPM_InitFixedPoint_m(0.46875, u5p11_T),
	  FPM_InitFixedPoint_m(0.625, u5p11_T),
	 FPM_InitFixedPoint_m(0.78125, u5p11_T),
	 FPM_InitFixedPoint_m(0.9375, u5p11_T),
	 FPM_InitFixedPoint_m(1.09375, u5p11_T),
	 FPM_InitFixedPoint_m(1.25, u5p11_T),
	 FPM_InitFixedPoint_m(1.40625, u5p11_T),
	 FPM_InitFixedPoint_m(1.5625, u5p11_T),
	 FPM_InitFixedPoint_m(1.71875, u5p11_T),
	 FPM_InitFixedPoint_m(1.875, u5p11_T),
	 FPM_InitFixedPoint_m(2.03125, u5p11_T),
	 FPM_InitFixedPoint_m(2.1875, u5p11_T),
	 FPM_InitFixedPoint_m(2.34375, u5p11_T),
	 FPM_InitFixedPoint_m(2.5, u5p11_T) };


/********************************* HystComp **********************************/
#pragma DATA_SECTION(k_MtrNmPerHwNm_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MtrNmPerHwNm_Uls_f32 = 0.05f;

#pragma DATA_SECTION(t_HysCompCoulFricWIRBlendX_MtrNm_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_HysCompCoulFricWIRBlendX_MtrNm_u8p8[6] = 
	{ FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.2, u8p8_T),
	 FPM_InitFixedPoint_m(0.4, u8p8_T), FPM_InitFixedPoint_m(0.6, u8p8_T),
	 FPM_InitFixedPoint_m(0.8, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T) };

#pragma DATA_SECTION(t_HysCompCoulFricWIRBlendY_Uls_u2p14, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_HysCompCoulFricWIRBlendY_Uls_u2p14[6] = 
	{ FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T) };

#pragma DATA_SECTION(t_HysCompNegHysBlendX_HwNm_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_HysCompNegHysBlendX_HwNm_u9p7[5] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(1.0, u9p7_T),
	 FPM_InitFixedPoint_m(2.0, u9p7_T), FPM_InitFixedPoint_m(3.0, u9p7_T),
	 FPM_InitFixedPoint_m(4.0, u9p7_T) };

#pragma DATA_SECTION(t_HysCompNegHysBlendY_Uls_u2p14, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_HysCompNegHysBlendY_Uls_u2p14[5] = 
	{ FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T) };

#pragma DATA_SECTION(t_HysCompNegHysCompX_MtrNm_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_HysCompNegHysCompX_MtrNm_u8p8[8] = 
	{ FPM_InitFixedPoint_m(0.0, u8p8_T), FPM_InitFixedPoint_m(0.1, u8p8_T),
	 FPM_InitFixedPoint_m(0.2, u8p8_T), FPM_InitFixedPoint_m(0.4, u8p8_T),
	 FPM_InitFixedPoint_m(0.6, u8p8_T), FPM_InitFixedPoint_m(0.8, u8p8_T),
	 FPM_InitFixedPoint_m(0.9, u8p8_T), FPM_InitFixedPoint_m(1.0, u8p8_T) };

#pragma DATA_SECTION(t_HysCompNegHysCompY_HwNm_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_HysCompNegHysCompY_HwNm_u9p7[8] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T) };


/**************************** IoHwAbstractionUsr *****************************/
#pragma DATA_SECTION(k_T1T2AvgFilterEnable_Uls_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_T1T2AvgFilterEnable_Uls_lgc = FALSE;


/********************************* LktoLkStr *********************************/
#pragma DATA_SECTION(k_LrnPnCntrHoldTorque_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorque_MtrNm_f32 = 6.0f;

#pragma DATA_SECTION(k_LrnPnCntrHoldTorqueErrThresh_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorqueErrThresh_MtrNm_f32 = 0.05f;

#pragma DATA_SECTION(k_LrnPnCntrHoldTorqueRateLimit_MtrNmpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LrnPnCntrHoldTorqueRateLimit_MtrNmpS_f32 = 2.0f;

#pragma DATA_SECTION(k_LrnPnCntrHwPosErrThresh_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LrnPnCntrHwPosErrThresh_HwDeg_f32 = 5.0f;

#pragma DATA_SECTION(k_LrnPnCntrMaxTcmd_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LrnPnCntrMaxTcmd_MtrNm_f32 = 8.0f;

#pragma DATA_SECTION(k_LrnPnCntrMinApplyTorque_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LrnPnCntrMinApplyTorque_MtrNm_f32 = 2.0f;

#pragma DATA_SECTION(k_LrnPnCntrMotVelStoppedThresh_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LrnPnCntrMotVelStoppedThresh_MtrRadpS_f32 = 5.0f;

#pragma DATA_SECTION(k_LrnPnCntrTimeout_mS_u32, ".FlashCalSeg");
CONST(uint32, CAL_CONST) k_LrnPnCntrTimeout_mS_u32 = 15000UL;

#pragma DATA_SECTION(k_LrnPnCntrTimeThresh_mS_u32, ".FlashCalSeg");
CONST(uint32, CAL_CONST) k_LrnPnCntrTimeThresh_mS_u32 = 250UL;


/********************************** LmtCod ***********************************/
#pragma DATA_SECTION(k_CCLTrqRampIncSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CCLTrqRampIncSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(k_GainDecSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_GainDecSlew_UlspS_f32 = 500.0f;

#pragma DATA_SECTION(k_TorqueDecSlew_MtrNmpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TorqueDecSlew_MtrNmpS_f32 = 4400.0f;

#pragma DATA_SECTION(t_GainIncSlewTblX_Kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_GainIncSlewTblX_Kph_u9p7[2] = 
	{FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T)};

#pragma DATA_SECTION(t_GainIncSlewTblY_UlspS_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_GainIncSlewTblY_UlspS_u9p7[2] = 
	{FPM_InitFixedPoint_m(500.0, u9p7_T),
	 FPM_InitFixedPoint_m(500.0, u9p7_T)};

#pragma DATA_SECTION(t_TorqueIncSlewTblX_Kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_TorqueIncSlewTblX_Kph_u9p7[2] = 
	{FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(20.0, u9p7_T)};

#pragma DATA_SECTION(t_TorqueIncSlewTblY_MtrNmpS_u13p3, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_TorqueIncSlewTblY_MtrNmpS_u13p3[2] = 
	{FPM_InitFixedPoint_m(4400.0, u13p3_T),
	 FPM_InitFixedPoint_m(4400.0, u13p3_T)};


/********************************** LnRkCr ***********************************/
#pragma DATA_SECTION(k_AllowFirstTimeManRC_Cnt_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_AllowFirstTimeManRC_Cnt_lgc = TRUE;

#pragma DATA_SECTION(k_MinRackCntrDisp_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MinRackCntrDisp_HwDeg_f32 = 800.0f;

#pragma DATA_SECTION(k_OutlierAdjAmt_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_OutlierAdjAmt_Uls_f32 = 0.25f;

#pragma DATA_SECTION(k_RCLPFCoeffK_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_RCLPFCoeffK_Cnt_u16 = 1428U;

#pragma DATA_SECTION(k_RCMtrTrq_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RCMtrTrq_MtrNm_f32 = 2.8f;

#pragma DATA_SECTION(k_RCMtrVel_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RCMtrVel_MtrRadpS_f32 = 25.0f;

#pragma DATA_SECTION(k_RCPosChg_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RCPosChg_HwDeg_f32 = 3.0f;

#pragma DATA_SECTION(k_RCTimer_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_RCTimer_mS_u16 = 250U;


/******************************** MtrCtrl_VM *********************************/
#pragma DATA_SECTION(k_CorrAngle_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CorrAngle_Cnt_u16 = 128U;

#pragma DATA_SECTION(k_CuThermCoeff_OhmpDegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CuThermCoeff_OhmpDegC_f32 = 0.00393f;

#pragma DATA_SECTION(k_InstMtrDirHyst_Deg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_InstMtrDirHyst_Deg_f32 = 2.5f;

#pragma DATA_SECTION(k_MagThrC_VpRadpSpDegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MagThrC_VpRadpSpDegC_f32 = -0.001f;

#pragma DATA_SECTION(k_MaxTrqCmdScl_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MaxTrqCmdScl_Uls_f32 = 1.1f;

#pragma DATA_SECTION(k_MinTrqCmdScl_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MinTrqCmdScl_Uls_f32 = 0.9f;

#pragma DATA_SECTION(k_MtrQuadPosSel_Cnt_lgc, ".FlashCalSeg");
CONST(Boolean, CAL_CONST) k_MtrQuadPosSel_Cnt_lgc = TRUE;

#pragma DATA_SECTION(k_NomRfet_Ohm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_NomRfet_Ohm_f32 = 0.00625f;

#pragma DATA_SECTION(k_NomTemp_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_NomTemp_DegC_f32 = 25.0f;

#pragma DATA_SECTION(k_PhsOffCorrDelay_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PhsOffCorrDelay_Sec_f32 = 0.00009375f;

#pragma DATA_SECTION(k_SiThermCoeff_OhmpDegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SiThermCoeff_OhmpDegC_f32 = 0.005f;

#pragma DATA_SECTION(k_TauDLPFByPass_Uls_lgc, ".FlashCalSeg");
CONST(Boolean, CAL_CONST) k_TauDLPFByPass_Uls_lgc = FALSE;

#pragma DATA_SECTION(k_TrmYDeadTimeScl_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrmYDeadTimeScl_Uls_f32 = 1.0061f;

#pragma DATA_SECTION(k_TrqRateThrsh_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrqRateThrsh_MtrNm_f32 = 0.025f;


/******************************** MtrCurr_VM *********************************/
#pragma DATA_SECTION(k_CurrentScale_AmpspVolt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CurrentScale_AmpspVolt_f32 = 100.0f;

#pragma DATA_SECTION(k_CurrGainNumerator_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CurrGainNumerator_Volts_f32 = 2.0f;

#pragma DATA_SECTION(k_MtrCurrFltrKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MtrCurrFltrKn_Hz_f32 = 1.0f;

#pragma DATA_SECTION(k_MtrCurrPolarity_Cnt_s16, ".FlashCalSeg");
CONST(sint16, CAL_CONST) k_MtrCurrPolarity_Cnt_s16 = 1;

#pragma DATA_SECTION(k_PosTrnsInvldRgn_Rev_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PosTrnsInvldRgn_Rev_f32 = 0.11f;

#pragma DATA_SECTION(t_ShcurOffCorrTblY_Volts_s2p13, ".FlashCalSeg");
CONST(sint16, CAL_CONST) t_ShcurOffCorrTblY_Volts_s2p13[7] = 
	{FPM_InitFixedPoint_m(0.0, s2p13_T), FPM_InitFixedPoint_m(0.0, s2p13_T),
	 FPM_InitFixedPoint_m(0.0, s2p13_T), FPM_InitFixedPoint_m(0.0, s2p13_T),
	 FPM_InitFixedPoint_m(0.0, s2p13_T), FPM_InitFixedPoint_m(0.0, s2p13_T),
	 FPM_InitFixedPoint_m(0.0, s2p13_T)};

#pragma DATA_SECTION(t_WidthDutySmallTblX_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_WidthDutySmallTblX_Cnt_u16[7] = {0U, 0U, 0U, 0U,
	 0U, 0U, 0U};


/********************************** MtrPos ***********************************/
#pragma DATA_SECTION(k_AmpRecVarLmt_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AmpRecVarLmt_Uls_f32 = 0.122f;

#pragma DATA_SECTION(k_CorrelationError_Rev_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CorrelationError_Rev_f32 = 0.222f;

#pragma DATA_SECTION(k_MtrPosCorrDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_MtrPosCorrDiag_Cnt_str = {50, 10, 1};

#pragma DATA_SECTION(k_MtrPosValDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_MtrPosValDiag_Cnt_str = {50, 10, 1};

#pragma DATA_SECTION(k_NominalOffset_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_NominalOffset_Volts_f32 = 2.5f;

#pragma DATA_SECTION(k_RTFiltEnThresh_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RTFiltEnThresh_Uls_f32 = 0.99f;

#pragma DATA_SECTION(k_RTOffFiltKn_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_RTOffFiltKn_Cnt_u16 = 200U;

#pragma DATA_SECTION(k_RTOffsetLmt_Volts_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RTOffsetLmt_Volts_f32 = 0.1f;

#pragma DATA_SECTION(k_RTOffVelThr_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RTOffVelThr_MtrRadpS_f32 = 100.0f;

#pragma DATA_SECTION(k_RTToNomRatioVar_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RTToNomRatioVar_Uls_f32 = 0.1f;

#pragma DATA_SECTION(k_SysCMtrPosValDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_SysCMtrPosValDiag_Cnt_str = {50, 10, 1};

#pragma DATA_SECTION(k_SysCValMaxError_VoltsSqrd_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SysCValMaxError_VoltsSqrd_f32 = 1.96f;

#pragma DATA_SECTION(k_SysCValMinError_VoltsSqrd_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SysCValMinError_VoltsSqrd_f32 = 0.0625f;

#pragma DATA_SECTION(k_ValMaxError_VoltsSqrd_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ValMaxError_VoltsSqrd_f32 = 6.25f;

#pragma DATA_SECTION(k_ValMinError_VoltsSqrd_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ValMinError_VoltsSqrd_f32 = 0.0625f;


/******************************** MtrTempEst *********************************/
#pragma DATA_SECTION(k_AMAmbLPFKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AMAmbLPFKn_Hz_f32 = 0.0005f;

#pragma DATA_SECTION(k_AMAmbMult_DegCpWatt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AMAmbMult_DegCpWatt_f32 = 0.0f;

#pragma DATA_SECTION(k_AmbPwrMult_WtspAmpSq_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AmbPwrMult_WtspAmpSq_f32 = 0.01f;

#pragma DATA_SECTION(k_AmbTempScl_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AmbTempScl_Uls_f32 = 0.95f;

#pragma DATA_SECTION(k_AMCorrLmt_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AMCorrLmt_DegC_f32 = 60.0f;

#pragma DATA_SECTION(k_AMDampScl_NmpRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AMDampScl_NmpRadpS_f32 = 0.0001f;

#pragma DATA_SECTION(k_AMDefaultTemp_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AMDefaultTemp_DegC_f32 = 50.0f;

#pragma DATA_SECTION(k_AMLLFiltCoefB0_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AMLLFiltCoefB0_Uls_f32 = 0.4761987f;

#pragma DATA_SECTION(k_AMLLFiltCoefB1_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AMLLFiltCoefB1_Uls_f32 = -0.4761673f;

#pragma DATA_SECTION(k_AMLLFiltPoleA1_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AMLLFiltPoleA1_Uls_f32 = 0.99996858f;

#pragma DATA_SECTION(k_AssistMechSlew_DegCpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AssistMechSlew_DegCpS_f32 = 1.0f;

#pragma DATA_SECTION(k_CuCorrLmt_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CuCorrLmt_DegC_f32 = 80.0f;

#pragma DATA_SECTION(k_EngTempScl_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_EngTempScl_Uls_f32 = 0.1f;

#pragma DATA_SECTION(k_MagCorrLmt_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MagCorrLmt_DegC_f32 = 60.0f;

#pragma DATA_SECTION(k_SiCorrLmt_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SiCorrLmt_DegC_f32 = 60.0f;

#pragma DATA_SECTION(k_WtAvgTempDFt_Cnt_lgc, ".FlashCalSeg");
CONST(Boolean, CAL_CONST) k_WtAvgTempDFt_Cnt_lgc = FALSE;


/********************************** MtrVel ***********************************/
#pragma DATA_SECTION(k_CorrMtrVelFiltKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CorrMtrVelFiltKn_Hz_f32 = 10.0f;

#pragma DATA_SECTION(k_HwVelCorrLim_Cnt_Str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_HwVelCorrLim_Cnt_Str = {12, 3, 1};

#pragma DATA_SECTION(k_HwVelCorrLim_HwRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HwVelCorrLim_HwRadpS_f32 = 6.4f;

#pragma DATA_SECTION(k_HwVelSampleTime_ms_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_HwVelSampleTime_ms_f32 = 2.0f;

#pragma DATA_SECTION(k_MtrVelCorrLim_Cnt_Str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_MtrVelCorrLim_Cnt_Str = {12, 3, 1};

#pragma DATA_SECTION(k_MtrVelCorrLim_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MtrVelCorrLim_MtrRadpS_f32 = 225.0f;

#pragma DATA_SECTION(k_MtrVelFiltEn_Cnt_lgc, ".FlashCalSeg");
CONST(Boolean, CAL_CONST) k_MtrVelFiltEn_Cnt_lgc = FALSE;

#pragma DATA_SECTION(t_MtrVelBlendTblX_MtrRadpS_u12p4, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_MtrVelBlendTblX_MtrRadpS_u12p4[2] = 
	{FPM_InitFixedPoint_m(0.0, u12p4_T), FPM_InitFixedPoint_m(0.0, u12p4_T)};

#pragma DATA_SECTION(t_MtrVelDeltaKpTblX_MtrRadpS_u12p4, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblX_MtrRadpS_u12p4[2] = 
	{FPM_InitFixedPoint_m(0.9375, u12p4_T),
	 FPM_InitFixedPoint_m(3.125, u12p4_T)};

#pragma DATA_SECTION(t_MtrVelDeltaKpTblY_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblY_Cnt_u16[2] = {40U, 150U};

#pragma DATA_SECTION(t_MtrVelFiltKpTblX_Kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_MtrVelFiltKpTblX_Kph_u9p7[2] = 
	{FPM_InitFixedPoint_m(10.0, u9p7_T), FPM_InitFixedPoint_m(30.0, u9p7_T)};

#pragma DATA_SECTION(t_MtrVelFiltKpYTbl_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_MtrVelFiltKpYTbl_Cnt_u16[2] = {40U, 150U};


/********************************** OscTraj **********************************/
#pragma DATA_SECTION(k_OscTrajMaxAmp_HwDeg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_OscTrajMaxAmp_HwDeg_f32 = 360.0f;

#pragma DATA_SECTION(k_OscTrajMaxCycles_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_OscTrajMaxCycles_Cnt_u08 = 100;

#pragma DATA_SECTION(k_OscTrajMaxFreq_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_OscTrajMaxFreq_Hz_f32 = 10.0f;

#pragma DATA_SECTION(k_OscTrajMinFreq_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_OscTrajMinFreq_Hz_f32 = 0.1f;


/****************************** ParkAstEnbl_BMW ******************************/
#pragma DATA_SECTION(k_TcHwPosAuth_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TcHwPosAuth_Uls_f32 = 1.0f;


/******************************** PhaseDscnt *********************************/
#pragma DATA_SECTION(k_ChrgPmpHi_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_ChrgPmpHi_Cnt_str = {100, 10, 10};

#pragma DATA_SECTION(k_ChrgPmpHiDetect_Volt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ChrgPmpHiDetect_Volt_f32 = 2.2f;

#pragma DATA_SECTION(k_ChrgPmpLow_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_ChrgPmpLow_Cnt_str = {100, 10, 40};

#pragma DATA_SECTION(k_ChrgPmpLowDetect_Volt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_ChrgPmpLowDetect_Volt_f32 = 6.8f;

#pragma DATA_SECTION(k_IMeasLPFfc_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_IMeasLPFfc_Hz_f32 = 2.5f;

#pragma DATA_SECTION(k_IMeasNotNull_Amp_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_IMeasNotNull_Amp_f32 = 10.0f;

#pragma DATA_SECTION(k_IMeasNull_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_IMeasNull_Cnt_str = {30, 2, 1};

#pragma DATA_SECTION(k_IMeasNullCntsToFlt_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_IMeasNullCntsToFlt_Cnt_u08 = 1;

#pragma DATA_SECTION(k_IMeasNullDetectMtrVel_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_IMeasNullDetectMtrVel_MtrRadpS_f32 = 20.0f;

#pragma DATA_SECTION(k_IMeasTestDur_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_IMeasTestDur_mS_u16 = 250U;

#pragma DATA_SECTION(k_PDSuplHiCntsToFlt_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_PDSuplHiCntsToFlt_Cnt_u08 = 1;

#pragma DATA_SECTION(k_PDSuplHigh_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_PDSuplHigh_Cnt_str = {500, 10, 5};

#pragma DATA_SECTION(k_PDSuplHighDetect_Volt_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PDSuplHighDetect_Volt_f32 = 4.2f;

#pragma DATA_SECTION(k_PDSuplHiInit_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PDSuplHiInit_mS_u16 = 150U;

#pragma DATA_SECTION(k_PDTestFailCurr_Amp_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PDTestFailCurr_Amp_f32 = 38.0f;

#pragma DATA_SECTION(k_PDTestFltrCurrLPFKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PDTestFltrCurrLPFKn_Hz_f32 = 30.0f;

#pragma DATA_SECTION(k_PDTestMaxScans_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PDTestMaxScans_Cnt_u16 = 6U;

#pragma DATA_SECTION(k_PDTestMinFail_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PDTestMinFail_mS_u16 = 4U;

#pragma DATA_SECTION(k_PDTestMinScans_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PDTestMinScans_Cnt_u16 = 2U;

#pragma DATA_SECTION(k_PDTestModIdx_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PDTestModIdx_Uls_f32 = 0.3f;

#pragma DATA_SECTION(k_PhDiscOpenTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PhDiscOpenTime_mS_u16 = 90U;

#pragma DATA_SECTION(k_PhDiscStartTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PhDiscStartTime_mS_u16 = 35U;


/********************************* PosServo **********************************/
#pragma DATA_SECTION(t_PosSrvoMaxCmdX_Kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_PosSrvoMaxCmdX_Kph_u9p7[4] = 
	{FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(5.0, u9p7_T),
	 FPM_InitFixedPoint_m(12.0, u9p7_T), FPM_InitFixedPoint_m(12.1, u9p7_T)};

#pragma DATA_SECTION(t_PosSrvoMaxCmdY_MtrNm_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_PosSrvoMaxCmdY_MtrNm_u5p11[4] = 
	{FPM_InitFixedPoint_m(8.8, u5p11_T), FPM_InitFixedPoint_m(8.8, u5p11_T),
	 FPM_InitFixedPoint_m(8.8, u5p11_T), FPM_InitFixedPoint_m(8.8, u5p11_T)};

#pragma DATA_SECTION(t_PrkAstITermAWLmtY_MtrNm_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_PrkAstITermAWLmtY_MtrNm_u9p7[3] = 
	{FPM_InitFixedPoint_m(2.0, u9p7_T), FPM_InitFixedPoint_m(1.5, u9p7_T),
	 FPM_InitFixedPoint_m(1.0, u9p7_T)};

#pragma DATA_SECTION(t2_PrkAstPGainY_MtrNm_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t2_PrkAstPGainY_MtrNm_u9p7[3][7] = 
	{{FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(0.09, u9p7_T),
	 FPM_InitFixedPoint_m(0.25, u9p7_T), FPM_InitFixedPoint_m(0.74, u9p7_T),
	 FPM_InitFixedPoint_m(2.8, u9p7_T), FPM_InitFixedPoint_m(3.2, u9p7_T),
	 FPM_InitFixedPoint_m(3.257, u9p7_T)},
	 {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(0.09, u9p7_T),
	 FPM_InitFixedPoint_m(0.25, u9p7_T), FPM_InitFixedPoint_m(0.74, u9p7_T),
	 FPM_InitFixedPoint_m(2.8, u9p7_T), FPM_InitFixedPoint_m(3.2, u9p7_T),
	 FPM_InitFixedPoint_m(3.257, u9p7_T)},
	 {FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(0.09, u9p7_T),
	 FPM_InitFixedPoint_m(0.25, u9p7_T), FPM_InitFixedPoint_m(0.74, u9p7_T),
	 FPM_InitFixedPoint_m(2.8, u9p7_T), FPM_InitFixedPoint_m(3.2, u9p7_T),
	 FPM_InitFixedPoint_m(3.257, u9p7_T)}};


/***************************** PrkAstMfgServCh2 ******************************/
#pragma DATA_SECTION(k_LrnPnCntrDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_LrnPnCntrDiag_Cnt_str = {200, 5, 3};

#pragma DATA_SECTION(k_PrkAssDiagRmpDone_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_PrkAssDiagRmpDone_Uls_f32 = 1.0f;

#pragma DATA_SECTION(k_PrkAssistDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_PrkAssistDiag_Cnt_str = {200, 5, 3};

#pragma DATA_SECTION(t_PrkAssistDiagThresX_kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_PrkAssistDiagThresX_kph_u9p7[3] = 
	{FPM_InitFixedPoint_m(12.0, u9p7_T),FPM_InitFixedPoint_m(15.0, u9p7_T),
	FPM_InitFixedPoint_m(20.0, u9p7_T)};

#pragma DATA_SECTION(t_PrkAssistDiagThresY_Uls_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_PrkAssistDiagThresY_Uls_u16[3] = {200U,100U,20U};


/******************************** PwrLmtFunc *********************************/
#pragma DATA_SECTION(k_AsstReducLPFKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AsstReducLPFKn_Hz_f32 = 0.365f;

#pragma DATA_SECTION(k_FiltAsstReducTh_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_FiltAsstReducTh_Uls_f32 = 0.6f;

#pragma DATA_SECTION(k_LowVltAstRecTh_Volts_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_LowVltAstRecTh_Volts_u8p8 = 
	FPM_InitFixedPoint_m(13.5, u8p8_T);

#pragma DATA_SECTION(k_LowVltAstRecTime_mS_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_LowVltAstRecTime_mS_u16p0 = 
	FPM_InitFixedPoint_m(2000.0, u16p0_T);

#pragma DATA_SECTION(k_SpdAdjSlewEnable_Cnt_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_SpdAdjSlewEnable_Cnt_lgc = TRUE;


/********************************* RackLoad **********************************/
#pragma DATA_SECTION(k_LumpSysInertia_Kgm2_u6p10, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_LumpSysInertia_Kgm2_u6p10 = 
	FPM_InitFixedPoint_m(0.0553, u6p10_T);

#pragma DATA_SECTION(k_MechEffQ1_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MechEffQ1_Uls_f32 = 0.94f;

#pragma DATA_SECTION(k_MechEffQ2_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MechEffQ2_Uls_f32 = 0.94f;

#pragma DATA_SECTION(k_MotorEffQ1_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MotorEffQ1_Uls_f32 = 0.87f;

#pragma DATA_SECTION(k_MotorEffQ2_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MotorEffQ2_Uls_f32 = 0.87f;

#pragma DATA_SECTION(k_MtrAccelLPF_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MtrAccelLPF_Cnt_u16 = 51912U;

#pragma DATA_SECTION(k_MtrNmtoHwNm_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MtrNmtoHwNm_Uls_f32 = 24.0f;

#pragma DATA_SECTION(k_MtrVelDband_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MtrVelDband_MtrRadpS_f32 = 0.25f;

#pragma DATA_SECTION(k_RackDamp_NmpRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RackDamp_NmpRadpS_f32 = 0.06f;

#pragma DATA_SECTION(k_RackFriction_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RackFriction_HwNm_f32 = 1.6f;

#pragma DATA_SECTION(k_RackLoadLPF_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_RackLoadLPF_Cnt_u16 = 51912U;

#pragma DATA_SECTION(k_TrnsFcnFs_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrnsFcnFs_Hz_f32 = 100.0f;

#pragma DATA_SECTION(k_TrnsFcnOmegaD_RadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrnsFcnOmegaD_RadpS_f32 = 100.0f;

#pragma DATA_SECTION(k_TrnsFcnOmegaD2_RadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrnsFcnOmegaD2_RadpS_f32 = 63.0f;

#pragma DATA_SECTION(k_TrnsFcnOmegaN_RadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrnsFcnOmegaN_RadpS_f32 = 220.0f;

#pragma DATA_SECTION(k_TrnsFcnTn_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TrnsFcnTn_Uls_f32 = 1.0f;


/********************************** Return ***********************************/
#pragma DATA_SECTION(k_RtnHWAuthSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RtnHWAuthSlew_UlspS_f32 = 0.5f;

#pragma DATA_SECTION(t_HWAuthRetScl_X_Uls_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_HWAuthRetScl_X_Uls_u8p8[4] = 
	{ FPM_InitFixedPoint_m(0.0, u8p8_T),FPM_InitFixedPoint_m(0.5, u8p8_T),
	FPM_InitFixedPoint_m(0.75, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T) };

#pragma DATA_SECTION(t_HWAuthRetScl_Y_Uls_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_HWAuthRetScl_Y_Uls_u9p7[4] = 
	{ FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(0.0, u9p7_T),
	FPM_InitFixedPoint_m(0.0, u9p7_T),FPM_InitFixedPoint_m(1.0, u9p7_T) };

#pragma DATA_SECTION(t_ReturnTempScaleSclYTbl_Uls_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_ReturnTempScaleSclYTbl_Uls_u8p8[14] = 
	{ FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T),
	FPM_InitFixedPoint_m(1.0, u8p8_T),FPM_InitFixedPoint_m(1.0, u8p8_T) };

#pragma DATA_SECTION(t_ReturnTempScaleXTbl_DegC_s11p4, ".FlashCalSeg");
CONST(sint16, CAL_CONST) t_ReturnTempScaleXTbl_DegC_s11p4[14] = 
	{ FPM_InitFixedPoint_m(-40.0, s11p4_T),
	 FPM_InitFixedPoint_m(-35.0, s11p4_T),
	 FPM_InitFixedPoint_m(-30.0, s11p4_T),
	 FPM_InitFixedPoint_m(-20.0, s11p4_T),
	 FPM_InitFixedPoint_m(-10.0, s11p4_T),
	 FPM_InitFixedPoint_m(0.0, s11p4_T), FPM_InitFixedPoint_m(10.0, s11p4_T),
	 FPM_InitFixedPoint_m(20.0, s11p4_T),FPM_InitFixedPoint_m(30.0, s11p4_T),
	FPM_InitFixedPoint_m(40.0, s11p4_T),FPM_InitFixedPoint_m(50.0, s11p4_T),
	 FPM_InitFixedPoint_m(60.0, s11p4_T),FPM_InitFixedPoint_m(70.0, s11p4_T),
	 FPM_InitFixedPoint_m(90.0, s11p4_T) };


/********************************* SgnlCond **********************************/
#pragma DATA_SECTION(k_SigCon_DefaultLatAccel_MpSecSq_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_DefaultLatAccel_MpSecSq_f32 = 0.0f;

#pragma DATA_SECTION(k_SigCon_DefaultLonAccel_KphpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_DefaultLonAccel_KphpS_f32 = 0.0f;

#pragma DATA_SECTION(k_SigCon_DefaultVehSpd_Kph_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_DefaultVehSpd_Kph_f32 = 1.0f;

#pragma DATA_SECTION(k_SigCon_DefaultYawRate_DegpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_DefaultYawRate_DegpS_f32 = 0.0f;

#pragma DATA_SECTION(k_SigCon_LatAccelDiffThresh_MpSecSq_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_LatAccelDiffThresh_MpSecSq_f32 = 
	0.200000003f;

#pragma DATA_SECTION(k_SigCon_LatAccelSlewRate_MpSecSq_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_LatAccelSlewRate_MpSecSq_f32 = 10.0f;

#pragma DATA_SECTION(k_SigCon_LatAccFiltFrq_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_LatAccFiltFrq_Hz_f32 = 100.0f;

#pragma DATA_SECTION(k_SigCon_LonAccelDiffThresh_KphpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_LonAccelDiffThresh_KphpS_f32 = 1.0f;

#pragma DATA_SECTION(k_SigCon_LonAccelSlewRate_KphpSecSq_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_LonAccelSlewRate_KphpSecSq_f32 = 50.0f;

#pragma DATA_SECTION(k_SigCon_VehSpdDiffThresh_Kph_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_VehSpdDiffThresh_Kph_f32 = 5.0f;

#pragma DATA_SECTION(k_SigCon_VehSpdSlewRate_KphpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_VehSpdSlewRate_KphpS_f32 = 50.0f;

#pragma DATA_SECTION(k_SigCon_YawRateDiffThresh_DegpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SigCon_YawRateDiffThresh_DegpS_f32 = 20.0f;

#pragma DATA_SECTION(k_VehYawRateSlew_DegpSecSq_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_VehYawRateSlew_DegpSecSq_f32 = 120.0f;


/******************************** SrlComInput ********************************/
#pragma DATA_SECTION(k_AclnyMassCntrLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_AclnyMassCntrLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_ConVehCntrLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_ConVehCntrLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_CtrErrmBnUHold_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CtrErrmBnUHold_mS_u16 = 2000U;

#pragma DATA_SECTION(k_CtrVibStwDispLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_CtrVibStwDispLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_CustPosTrimVehSpdThres_kph_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CustPosTrimVehSpdThres_kph_f32 = 200.0f;

#pragma DATA_SECTION(k_CustSrvcHwTrqThres_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CustSrvcHwTrqThres_HwNm_f32 = 5.0f;

#pragma DATA_SECTION(k_CustSrvcVehSpdThres_kph_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_CustSrvcVehSpdThres_kph_f32 = 10.0f;

#pragma DATA_SECTION(k_DfltVehSpd_Kph_M_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DfltVehSpd_Kph_M_f32 = 100.0f;

#pragma DATA_SECTION(k_EnergDgrDrdyLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_EnergDgrDrdyLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_FZZSTDLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_FZZSTDLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_GarageModeVehSpdThres_kph_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_GarageModeVehSpdThres_kph_f32 = 200.0f;

#pragma DATA_SECTION(k_MaxISpecEpsMax_Amp_u8, ".FlashCalSeg");
CONST(New_Coding_94, CAL_CONST) k_MaxISpecEpsMax_Amp_u8 = 0;

#pragma DATA_SECTION(k_MaxISpecEpsMin_Amp_u8, ".FlashCalSeg");
CONST(New_Coding_94, CAL_CONST) k_MaxISpecEpsMin_Amp_u8 = 0;

#pragma DATA_SECTION(k_MileKMLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MileKMLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_OpTrqOvEPSSafetyLimit_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_OpTrqOvEPSSafetyLimit_MtrNm_f32 = 3.5f;

#pragma DATA_SECTION(k_RevOffsetLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_RevOffsetLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_SComRevOffsetPol_Cnt_s08, ".FlashCalSeg");
CONST(sint8, CAL_CONST) k_SComRevOffsetPol_Cnt_s08 = -1;

#pragma DATA_SECTION(k_StartUpDTCMaskTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_StartUpDTCMaskTime_mS_u16 = 2000U;

#pragma DATA_SECTION(k_StCengCntrLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_StCengCntrLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_StCengDrvHold_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_StCengDrvHold_mS_u16 = 2000U;

#pragma DATA_SECTION(k_StCengDrvMax_Cnt_u8, ".FlashCalSeg");
CONST(New_Coding_104, CAL_CONST) k_StCengDrvMax_Cnt_u8 = 0;

#pragma DATA_SECTION(k_SteaPniOffsLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_SteaPniOffsLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_TarQtaStMomLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_TarQtaStMomLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_TarStMomLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_TarStMomLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_TrqOvDbnceCntrThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_TrqOvDbnceCntrThres_Cnt_u16 = 2U;

#pragma DATA_SECTION(k_TuningSelLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_TuningSelLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_VehSpdLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_VehSpdLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_VINLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_VINLostMsgThres_Cnt_u16 = 500U;

#pragma DATA_SECTION(k_VYawVehCntrLostMsgThres_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_VYawVehCntrLostMsgThres_Cnt_u16 = 500U;


/******************************* SrlComOutput ********************************/
#pragma DATA_SECTION(k_GlobalPowerMgmt_Warning_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_GlobalPowerMgmt_Warning_mS_u16 = 0U;

#pragma DATA_SECTION(k_SupplCurThres_Amp_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_SupplCurThres_Amp_f32 = 0.0f;

#pragma DATA_SECTION(k_SupplCurThresTime_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_SupplCurThresTime_mS_u16 = 0U;


/*********************** SrlComOutput, LnRkCr, MtrVel ************************/
#pragma DATA_SECTION(k_GearRatio_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_GearRatio_Uls_f32 = 0.045454545f;


/******************************* StabilityComp *******************************/
#pragma DATA_SECTION(k_StCmpStabCmpNstep_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_StCmpStabCmpNstep_Cnt_u16 = 3U;

#pragma DATA_SECTION(k_StCmpStabCmpPNThresh_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_StCmpStabCmpPNThresh_Cnt_u16 = 50U;

#pragma DATA_SECTION(k_StCmpStabCmpPstep_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_StCmpStabCmpPstep_Cnt_u16 = 5U;


/*************************** StatesandModes, StaMd ***************************/
#pragma DATA_SECTION(k_StaMdsSysCDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_StaMdsSysCDiag_Cnt_str = {21,10,1};


/********************************** SVDiag ***********************************/
#pragma DATA_SECTION(k_ErrorFiltKn_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_ErrorFiltKn_Cnt_u16 = 1462U;

#pragma DATA_SECTION(k_ErrorThresh_Cnt_u32, ".FlashCalSeg");
CONST(uint32, CAL_CONST) k_ErrorThresh_Cnt_u32 = 14400UL;

#pragma DATA_SECTION(k_GateDriveDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_GateDriveDiag_Cnt_str = {1500, 512, 1};

#pragma DATA_SECTION(k_GateDrvInitDwellTime_mS_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_GateDrvInitDwellTime_mS_u16p0 = 10U;

#pragma DATA_SECTION(k_GenGateDrvFltThrsh_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_GenGateDrvFltThrsh_Cnt_u16 = 200U;

#pragma DATA_SECTION(k_LowResPhsReas_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_LowResPhsReas_Cnt_str = {100,1,500};

#pragma DATA_SECTION(k_LowResPhsReasMaxTol_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LowResPhsReasMaxTol_Uls_f32 = 1.2f;

#pragma DATA_SECTION(k_LowResPhsReasMinTol_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LowResPhsReasMinTol_Uls_f32 = 0.4f;

#pragma DATA_SECTION(k_LRPRCommOffsetMargin_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LRPRCommOffsetMargin_Uls_f32 = 1.05f;

#pragma DATA_SECTION(k_LRPRMtrVelDiagEnable_MtrRadpS_T_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_LRPRMtrVelDiagEnable_MtrRadpS_T_f32 = 300.0f;

#pragma DATA_SECTION(k_OnStateDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_OnStateDiag_Cnt_str = {1500, 512, 1};

#pragma DATA_SECTION(k_PhsReasEnableThresh_Cnt_u32, ".FlashCalSeg");
CONST(uint32, CAL_CONST) k_PhsReasEnableThresh_Cnt_u32 = 5760UL;

#pragma DATA_SECTION(k_PhsReasErrorTerm_Cnt_s16, ".FlashCalSeg");
CONST(sint16, CAL_CONST) k_PhsReasErrorTerm_Cnt_s16 = 0;


/********************************** SVDrvr ***********************************/
#pragma DATA_SECTION(k_ADCTrig1Offset_Cnt_s16, ".FlashCalSeg");
CONST(sint16, CAL_CONST) k_ADCTrig1Offset_Cnt_s16 = 70;

#pragma DATA_SECTION(k_ADCTrig2Offset_Cnt_s16, ".FlashCalSeg");
CONST(sint16, CAL_CONST) k_ADCTrig2Offset_Cnt_s16 = 70;

#pragma DATA_SECTION(k_DitherLPFKn_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_DitherLPFKn_Cnt_u16 = 20U;

#pragma DATA_SECTION(k_PwmDeadBand_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_PwmDeadBand_Cnt_u16 = 12U;


/********************************* TcFlshPrg *********************************/
#pragma DATA_SECTION(k_ExpectedTcPn_Cnt_u32, ".FlashCal2Seg");
CONST(uint32, CAL_CONST) k_ExpectedTcPn_Cnt_u32 = 50462720UL;

#pragma DATA_SECTION(k_TcPrgMemSize_Cnt_u16, ".FlashCal2Seg");
CONST(uint16, CAL_CONST) k_TcPrgMemSize_Cnt_u16 = 8192U;

#pragma DATA_SECTION(t_TcConfigWords_Cnt_u16, ".FlashCal2Seg");
CONST(uint16, CAL_CONST) t_TcConfigWords_Cnt_u16[2] = { 8152U, 30206U };


/************************** TcFlshPrg, TurnsCounter **************************/
#pragma DATA_SECTION(t_TcPrgMemory_Cnt_u16, ".FlashCal2Seg");
CONST(uint16, CAL_CONST) t_TcPrgMemory_Cnt_u16[8192] = { 0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,
	0U };


/******************************* ThrmDutyCycle *******************************/
#pragma DATA_SECTION(k_AbsTempDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_AbsTempDiag_Cnt_str = {0, 0, 0};

#pragma DATA_SECTION(k_AbsTmpTrqSlewLmt_MtrNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_AbsTmpTrqSlewLmt_MtrNm_f32 = 0.023438f;

#pragma DATA_SECTION(k_DefaultIgnOffTime_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_DefaultIgnOffTime_Sec_f32 = 5000.0f;

#pragma DATA_SECTION(k_DutyCycFltTrshld_Uls_u16p0, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_DutyCycFltTrshld_Uls_u16p0 = 
	FPM_InitFixedPoint_m(92.0, u16p0_T);

#pragma DATA_SECTION(k_EOCCtrlTemp_DegC_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_EOCCtrlTemp_DegC_f32 = 70.0f;

#pragma DATA_SECTION(k_IgnOffCntrEnb_Cnt_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_IgnOffCntrEnb_Cnt_lgc = FALSE;

#pragma DATA_SECTION(k_IgnOffMsgWaitTime_Sec_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_IgnOffMsgWaitTime_Sec_f32 = 0.5f;

#pragma DATA_SECTION(k_MtrPrTempSlc_Cnt_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_MtrPrTempSlc_Cnt_lgc = TRUE;

#pragma DATA_SECTION(k_MultTempSlc_Cnt_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_MultTempSlc_Cnt_lgc = TRUE;

#pragma DATA_SECTION(k_SlowFltTempSlc_Cnt_lgc, ".FlashCalSeg");
CONST(boolean, CAL_CONST) k_SlowFltTempSlc_Cnt_lgc = FALSE;

#pragma DATA_SECTION(t_AbsCtrlTmpTblX_DegC_s15p0, ".FlashCalSeg");
CONST(sint16, CAL_CONST) t_AbsCtrlTmpTblX_DegC_s15p0[4] = 
	{FPM_InitFixedPoint_m(122.0, s15p0_T),
	 FPM_InitFixedPoint_m(123.0, s15p0_T),
	 FPM_InitFixedPoint_m(125.0, s15p0_T),
	 FPM_InitFixedPoint_m(127.0, s15p0_T)};

#pragma DATA_SECTION(t_AbsCuTmpTblX_DegC_s15p0, ".FlashCalSeg");
CONST(sint16, CAL_CONST) t_AbsCuTmpTblX_DegC_s15p0[4] = 
	{FPM_InitFixedPoint_m(122.0, s15p0_T),
	 FPM_InitFixedPoint_m(123.0, s15p0_T),
	 FPM_InitFixedPoint_m(125.0, s15p0_T),
	 FPM_InitFixedPoint_m(127.0, s15p0_T)};


/********************************** TJADamp **********************************/
#pragma DATA_SECTION(k_TJADampErrAcc_Cnt_Str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_TJADampErrAcc_Cnt_Str = {100,0,0};

#pragma DATA_SECTION(k_TJADampRatioThresh_Uls_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TJADampRatioThresh_Uls_f32 = 0.9f;

#pragma DATA_SECTION(k_TJADwnSlewActive_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TJADwnSlewActive_UlspS_f32 = 1000.0f;

#pragma DATA_SECTION(k_TJADwnSlewInAct_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TJADwnSlewInAct_UlspS_f32 = 1000.0f;

#pragma DATA_SECTION(k_TJADwnSlewInVald_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TJADwnSlewInVald_UlspS_f32 = 1000.0f;

#pragma DATA_SECTION(k_TJAUpSlew_UlspS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TJAUpSlew_UlspS_f32 = 1000.0f;


/******************************* TMS570_uDiag ********************************/
#pragma DATA_SECTION(k_FlashECCDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_FlashECCDiag_Cnt_str = {100, 5, 1};

#pragma DATA_SECTION(k_MtrCtrlMaxCount_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MtrCtrlMaxCount_Cnt_u16 = 120U;

#pragma DATA_SECTION(k_MtrCtrlMinCount_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MtrCtrlMinCount_Cnt_u16 = 10U;

#pragma DATA_SECTION(k_OneMsLoopMaxCount_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_OneMsLoopMaxCount_Cnt_u16 = 11U;

#pragma DATA_SECTION(k_OneMsLoopMinCount_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_OneMsLoopMinCount_Cnt_u16 = 1U;

#pragma DATA_SECTION(k_RAMECCDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_RAMECCDiag_Cnt_str = {100, 5, 1};

#pragma DATA_SECTION(k_VIMParErrThrsh_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_VIMParErrThrsh_Cnt_u16 = 20U;


/******************************* TuningSelAuth *******************************/
#pragma DATA_SECTION(k_TunSelHwTrqLPFKn_Hz_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TunSelHwTrqLPFKn_Hz_f32 = 5.0f;

#pragma DATA_SECTION(k_TunSelHwTrqThresh_HwNm_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TunSelHwTrqThresh_HwNm_f32 = 2.0f;

#pragma DATA_SECTION(k_TunSelVehSpdThresh_Kph_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_TunSelVehSpdThresh_Kph_f32 = 100.0f;


/******************************* TurnsCounter ********************************/
#pragma DATA_SECTION(k_MaxBemfDeActive_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MaxBemfDeActive_MtrRadpS_f32 = 18.0f;

#pragma DATA_SECTION(k_MinBemfActive_MtrRadpS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MinBemfActive_MtrRadpS_f32 = 450.0f;

#pragma DATA_SECTION(k_MinHighMtrVelHighCnt_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MinHighMtrVelHighCnt_Cnt_u16 = 5U;

#pragma DATA_SECTION(k_MinLowMtrVelLowCnt_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MinLowMtrVelLowCnt_Cnt_u16 = 50U;

#pragma DATA_SECTION(k_MinTotHighSampleCnt_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MinTotHighSampleCnt_Cnt_u16 = 1000U;

#pragma DATA_SECTION(k_MinTotLowSampleCnt_Cnt_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_MinTotLowSampleCnt_Cnt_u16 = 1000U;

#pragma DATA_SECTION(k_MtrPosToTcMechOffset_Deg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_MtrPosToTcMechOffset_Deg_f32 = 43.8f;

#pragma DATA_SECTION(k_RTBemfErr_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_RTBemfErr_Cnt_str = {100, 100, 50};

#pragma DATA_SECTION(k_TcActivePNvldChks_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_TcActivePNvldChks_Cnt_u08 = 2;

#pragma DATA_SECTION(k_TcEolCalChksmDef_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_TcEolCalChksmDef_Cnt_u08 = 234;

#pragma DATA_SECTION(k_TcEolOffsetDef_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_TcEolOffsetDef_Cnt_u08 = 128;

#pragma DATA_SECTION(k_TcEolSin2CosGainDef_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_TcEolSin2CosGainDef_Cnt_u08 = 16;

#pragma DATA_SECTION(k_TcEolSinVsCosMaxDef_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_TcEolSinVsCosMaxDef_Cnt_u08 = 246;

#pragma DATA_SECTION(k_TcEolSinVsCosMinDef_Cnt_u08, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_TcEolSinVsCosMinDef_Cnt_u08 = 15;

#pragma DATA_SECTION(k_TcMOSIErr_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_TcMOSIErr_Cnt_str = {90, 10, 5};

#pragma DATA_SECTION(k_TcResetTimeout_mS_u16, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_TcResetTimeout_mS_u16 = 1000U;

#pragma DATA_SECTION(k_TcSCMnMxErr_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_TcSCMnMxErr_Cnt_str = {50, 10, 1};

#pragma DATA_SECTION(k_TcSpiComDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_TcSpiComDiag_Cnt_str = {50, 10, 1};

#pragma DATA_SECTION(k_TcSpiDataDiag_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_TcSpiDataDiag_Cnt_str = {30, 10, 1};

#pragma DATA_SECTION(k_TCvsMtrPosErr_Cnt_str, ".FlashCalSeg");
CONST(DiagSettings_Str, CAL_CONST) k_TCvsMtrPosErr_Cnt_str = {200, 100, 50};

#pragma DATA_SECTION(t_TcToAcmpMax_Deg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) t_TcToAcmpMax_Deg_f32[8] = { 136.2f, 181.2f, 226.2f,
	 271.2f, 316.2f, 361.2f, 406.2f, 451.2f };

#pragma DATA_SECTION(t_TcToAcmpMin_Deg_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) t_TcToAcmpMin_Deg_f32[8] = { -178.8f, -133.8f,
	 -88.8f, -43.8f, 1.2f, 46.2f, 91.2f, 136.2f };


/********************************** VehCfg ***********************************/
#pragma DATA_SECTION(k_NxtrVariantCalSel_Cnt_u8, ".FlashCalSeg");
CONST(uint8, CAL_CONST) k_NxtrVariantCalSel_Cnt_u8 = 0;


/********************************* VehPwrMd **********************************/
#pragma DATA_SECTION(k_RampDnRt_UlspmS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RampDnRt_UlspmS_f32 = 0.0005f;

#pragma DATA_SECTION(k_RampUpRtLoSpd_UlspmS_f32, ".FlashCalSeg");
CONST(float32, CAL_CONST) k_RampUpRtLoSpd_UlspmS_f32 = 0.0005f;

#pragma DATA_SECTION(k_VehSpdRampDwn_kph_u12p4, ".FlashCalSeg");
CONST(uint16, CAL_CONST) k_VehSpdRampDwn_kph_u12p4 = 
	FPM_InitFixedPoint_m(50.0, u12p4_T);


/*************************************  **************************************/
#pragma DATA_SECTION(t_AsstFWVehSpd_Kph_u9p7, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t_AsstFWVehSpd_Kph_u9p7[12] = 
	{FPM_InitFixedPoint_m(0.0, u9p7_T), FPM_InitFixedPoint_m(5.0, u9p7_T),
	 FPM_InitFixedPoint_m(30.0, u9p7_T), FPM_InitFixedPoint_m(60.0, u9p7_T),
	 FPM_InitFixedPoint_m(80.0, u9p7_T), FPM_InitFixedPoint_m(100.0, u9p7_T),
	 FPM_InitFixedPoint_m(120.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T),
	 FPM_InitFixedPoint_m(150.0, u9p7_T)};

#pragma DATA_SECTION(t_DampFWUprBoundX_MtrRadpS_s11p4, ".FlashCalSeg");
CONST(sint16, CAL_CONST) t_DampFWUprBoundX_MtrRadpS_s11p4[11] = 
	{FPM_InitFixedPoint_m(-700.0, s10p5_T),
	 FPM_InitFixedPoint_m(-50.0, s10p5_T),
	 FPM_InitFixedPoint_m(0.0, s10p5_T), FPM_InitFixedPoint_m(50.0, s10p5_T),
	 FPM_InitFixedPoint_m(100.0, s10p5_T),
	 FPM_InitFixedPoint_m(150.0, s10p5_T),
	 FPM_InitFixedPoint_m(200.0, s10p5_T),
	 FPM_InitFixedPoint_m(350.0, s10p5_T),
	 FPM_InitFixedPoint_m(400.0, s10p5_T),
	 FPM_InitFixedPoint_m(500.0, s10p5_T),
	 FPM_InitFixedPoint_m(700.0, s10p5_T)};

#pragma DATA_SECTION(t2_AsstFWUprBoundX_HwNm_s4p11, ".FlashCalSeg");
CONST(sint16, CAL_CONST) t2_AsstFWUprBoundX_HwNm_s4p11[12][11] = 
	{{FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)},
	 {FPM_InitFixedPoint_m(-10.0, s4p11_T),
	 FPM_InitFixedPoint_m(-1.0, s4p11_T), FPM_InitFixedPoint_m(0.0, s4p11_T),
	 FPM_InitFixedPoint_m(1.0, s4p11_T), FPM_InitFixedPoint_m(2.0, s4p11_T),
	 FPM_InitFixedPoint_m(3.0, s4p11_T), FPM_InitFixedPoint_m(4.0, s4p11_T),
	 FPM_InitFixedPoint_m(5.0, s4p11_T),FPM_InitFixedPoint_m(6.0, s4p11_T),
	 FPM_InitFixedPoint_m(8.0, s4p11_T),
	 FPM_InitFixedPoint_m(10.0, s4p11_T)}};

#pragma DATA_SECTION(t2_AsstHwtX1_HwNm_u8p8, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t2_AsstHwtX1_HwNm_u8p8[10][20] = 
	{{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.1015625, u8p8_T),
	 FPM_InitFixedPoint_m(0.20703125, u8p8_T),
	 FPM_InitFixedPoint_m(0.24609375, u8p8_T),
	 FPM_InitFixedPoint_m(0.2890625, u8p8_T),
	 FPM_InitFixedPoint_m(0.3359375, u8p8_T),
	 FPM_InitFixedPoint_m(0.3828125, u8p8_T),
	 FPM_InitFixedPoint_m(0.4296875, u8p8_T),
	 FPM_InitFixedPoint_m(0.48046875, u8p8_T),
	 FPM_InitFixedPoint_m(0.5234375, u8p8_T),
	 FPM_InitFixedPoint_m(0.5703125, u8p8_T),
	 FPM_InitFixedPoint_m(0.62109375, u8p8_T),
	 FPM_InitFixedPoint_m(0.6640625, u8p8_T),
	 FPM_InitFixedPoint_m(0.7109375, u8p8_T),
	 FPM_InitFixedPoint_m(0.7578125, u8p8_T),
	 FPM_InitFixedPoint_m(0.80078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.8515625, u8p8_T),
	 FPM_InitFixedPoint_m(0.8984375, u8p8_T),
	 FPM_InitFixedPoint_m(0.9453125, u8p8_T),
	 FPM_InitFixedPoint_m(0.98828125, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.1015625, u8p8_T),
	 FPM_InitFixedPoint_m(0.3046875, u8p8_T),
	 FPM_InitFixedPoint_m(0.39453125, u8p8_T),
	 FPM_InitFixedPoint_m(0.48046875, u8p8_T),
	 FPM_InitFixedPoint_m(0.578125, u8p8_T),
	 FPM_InitFixedPoint_m(0.66796875, u8p8_T),
	 FPM_InitFixedPoint_m(0.765625, u8p8_T),
	 FPM_InitFixedPoint_m(0.859375, u8p8_T),
	 FPM_InitFixedPoint_m(0.94921875, u8p8_T),
	 FPM_InitFixedPoint_m(1.04296875, u8p8_T),
	 FPM_InitFixedPoint_m(1.1328125, u8p8_T),
	 FPM_InitFixedPoint_m(1.23046875, u8p8_T),
	 FPM_InitFixedPoint_m(1.32421875, u8p8_T),
	 FPM_InitFixedPoint_m(1.4140625, u8p8_T),
	 FPM_InitFixedPoint_m(1.5078125, u8p8_T),
	 FPM_InitFixedPoint_m(1.6015625, u8p8_T),
	 FPM_InitFixedPoint_m(1.69140625, u8p8_T),
	 FPM_InitFixedPoint_m(1.78515625, u8p8_T),
	 FPM_InitFixedPoint_m(1.87890625, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.19921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.3125, u8p8_T),
	 FPM_InitFixedPoint_m(0.44140625, u8p8_T),
	 FPM_InitFixedPoint_m(0.56640625, u8p8_T),
	 FPM_InitFixedPoint_m(0.6875, u8p8_T),
	 FPM_InitFixedPoint_m(0.80078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.9296875, u8p8_T),
	 FPM_InitFixedPoint_m(1.0390625, u8p8_T),
	 FPM_InitFixedPoint_m(1.16015625, u8p8_T),
	 FPM_InitFixedPoint_m(1.2890625, u8p8_T),
	 FPM_InitFixedPoint_m(1.40625, u8p8_T),
	 FPM_InitFixedPoint_m(1.52734375, u8p8_T),
	 FPM_InitFixedPoint_m(1.6484375, u8p8_T),
	 FPM_InitFixedPoint_m(1.765625, u8p8_T),
	 FPM_InitFixedPoint_m(1.890625, u8p8_T),
	 FPM_InitFixedPoint_m(2.0078125, u8p8_T),
	 FPM_InitFixedPoint_m(2.12890625, u8p8_T),
	 FPM_InitFixedPoint_m(2.25390625, u8p8_T),
	 FPM_InitFixedPoint_m(2.37109375, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.19921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.3125, u8p8_T),
	 FPM_InitFixedPoint_m(0.4296875, u8p8_T),
	 FPM_InitFixedPoint_m(0.5703125, u8p8_T),
	 FPM_InitFixedPoint_m(0.67578125, u8p8_T),
	 FPM_InitFixedPoint_m(0.80078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.92578125, u8p8_T),
	 FPM_InitFixedPoint_m(1.0390625, u8p8_T),
	 FPM_InitFixedPoint_m(1.16796875, u8p8_T),
	 FPM_InitFixedPoint_m(1.2890625, u8p8_T),
	 FPM_InitFixedPoint_m(1.40625, u8p8_T),
	 FPM_InitFixedPoint_m(1.53125, u8p8_T),
	 FPM_InitFixedPoint_m(1.65234375, u8p8_T),
	 FPM_InitFixedPoint_m(1.765625, u8p8_T),
	 FPM_InitFixedPoint_m(1.890625, u8p8_T),
	 FPM_InitFixedPoint_m(2.01171875, u8p8_T),
	 FPM_InitFixedPoint_m(2.12890625, u8p8_T),
	 FPM_InitFixedPoint_m(2.25, u8p8_T),
	 FPM_InitFixedPoint_m(2.37109375, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.19921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.3125, u8p8_T),
	 FPM_InitFixedPoint_m(0.43359375, u8p8_T),
	 FPM_InitFixedPoint_m(0.55859375, u8p8_T),
	 FPM_InitFixedPoint_m(0.69140625, u8p8_T),
	 FPM_InitFixedPoint_m(0.80859375, u8p8_T),
	 FPM_InitFixedPoint_m(0.9296875, u8p8_T),
	 FPM_InitFixedPoint_m(1.04296875, u8p8_T),
	 FPM_InitFixedPoint_m(1.171875, u8p8_T),
	 FPM_InitFixedPoint_m(1.2890625, u8p8_T),
	 FPM_InitFixedPoint_m(1.40234375, u8p8_T),
	 FPM_InitFixedPoint_m(1.53125, u8p8_T),
	 FPM_InitFixedPoint_m(1.6484375, u8p8_T),
	 FPM_InitFixedPoint_m(1.76953125, u8p8_T),
	 FPM_InitFixedPoint_m(1.88671875, u8p8_T),
	 FPM_InitFixedPoint_m(2.01171875, u8p8_T),
	 FPM_InitFixedPoint_m(2.1328125, u8p8_T),
	 FPM_InitFixedPoint_m(2.25390625, u8p8_T),
	 FPM_InitFixedPoint_m(2.37109375, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.19921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.30859375, u8p8_T),
	 FPM_InitFixedPoint_m(0.43359375, u8p8_T),
	 FPM_InitFixedPoint_m(0.54296875, u8p8_T),
	 FPM_InitFixedPoint_m(0.6796875, u8p8_T),
	 FPM_InitFixedPoint_m(0.8046875, u8p8_T),
	 FPM_InitFixedPoint_m(0.921875, u8p8_T),
	 FPM_InitFixedPoint_m(1.04296875, u8p8_T),
	 FPM_InitFixedPoint_m(1.171875, u8p8_T),
	 FPM_InitFixedPoint_m(1.3046875, u8p8_T),
	 FPM_InitFixedPoint_m(1.4296875, u8p8_T),
	 FPM_InitFixedPoint_m(1.546875, u8p8_T),
	 FPM_InitFixedPoint_m(1.671875, u8p8_T),
	 FPM_InitFixedPoint_m(1.796875, u8p8_T),
	 FPM_InitFixedPoint_m(1.9296875, u8p8_T),
	 FPM_InitFixedPoint_m(2.05078125, u8p8_T),
	 FPM_InitFixedPoint_m(2.171875, u8p8_T),
	 FPM_InitFixedPoint_m(2.30078125, u8p8_T),
	 FPM_InitFixedPoint_m(2.42578125, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.19921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.3125, u8p8_T),
	 FPM_InitFixedPoint_m(0.4140625, u8p8_T),
	 FPM_InitFixedPoint_m(0.5546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.68359375, u8p8_T),
	 FPM_InitFixedPoint_m(0.80078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.93359375, u8p8_T),
	 FPM_InitFixedPoint_m(1.0546875, u8p8_T),
	 FPM_InitFixedPoint_m(1.171875, u8p8_T),
	 FPM_InitFixedPoint_m(1.296875, u8p8_T),
	 FPM_InitFixedPoint_m(1.4296875, u8p8_T),
	 FPM_InitFixedPoint_m(1.5546875, u8p8_T),
	 FPM_InitFixedPoint_m(1.67578125, u8p8_T),
	 FPM_InitFixedPoint_m(1.8046875, u8p8_T),
	 FPM_InitFixedPoint_m(1.9296875, u8p8_T),
	 FPM_InitFixedPoint_m(2.046875, u8p8_T),
	 FPM_InitFixedPoint_m(2.16796875, u8p8_T),
	 FPM_InitFixedPoint_m(2.30078125, u8p8_T),
	 FPM_InitFixedPoint_m(2.42578125, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.19921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.390625, u8p8_T),
	 FPM_InitFixedPoint_m(0.5078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.63671875, u8p8_T),
	 FPM_InitFixedPoint_m(0.7578125, u8p8_T),
	 FPM_InitFixedPoint_m(0.89453125, u8p8_T),
	 FPM_InitFixedPoint_m(1.01953125, u8p8_T),
	 FPM_InitFixedPoint_m(1.13671875, u8p8_T),
	 FPM_InitFixedPoint_m(1.265625, u8p8_T),
	 FPM_InitFixedPoint_m(1.38671875, u8p8_T),
	 FPM_InitFixedPoint_m(1.515625, u8p8_T),
	 FPM_InitFixedPoint_m(1.640625, u8p8_T),
	 FPM_InitFixedPoint_m(1.76171875, u8p8_T),
	 FPM_InitFixedPoint_m(1.88671875, u8p8_T),
	 FPM_InitFixedPoint_m(2.01171875, u8p8_T),
	 FPM_InitFixedPoint_m(2.140625, u8p8_T),
	 FPM_InitFixedPoint_m(2.265625, u8p8_T),
	 FPM_InitFixedPoint_m(2.39453125, u8p8_T),
	 FPM_InitFixedPoint_m(2.51953125, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.19921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.390625, u8p8_T),
	 FPM_InitFixedPoint_m(0.5078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.61328125, u8p8_T),
	 FPM_InitFixedPoint_m(0.73828125, u8p8_T),
	 FPM_InitFixedPoint_m(0.85546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.96484375, u8p8_T),
	 FPM_InitFixedPoint_m(1.08984375, u8p8_T),
	 FPM_InitFixedPoint_m(1.20703125, u8p8_T),
	 FPM_InitFixedPoint_m(1.3359375, u8p8_T),
	 FPM_InitFixedPoint_m(1.44140625, u8p8_T),
	 FPM_InitFixedPoint_m(1.57421875, u8p8_T),
	 FPM_InitFixedPoint_m(1.68359375, u8p8_T),
	 FPM_InitFixedPoint_m(1.8046875, u8p8_T),
	 FPM_InitFixedPoint_m(1.921875, u8p8_T),
	 FPM_InitFixedPoint_m(2.03515625, u8p8_T),
	 FPM_InitFixedPoint_m(2.15625, u8p8_T),
	 FPM_InitFixedPoint_m(2.26953125, u8p8_T),
	 FPM_InitFixedPoint_m(2.39453125, u8p8_T)},
	{FPM_InitFixedPoint_m(0.0, u8p8_T),
	 FPM_InitFixedPoint_m(0.19921875, u8p8_T),
	 FPM_InitFixedPoint_m(0.390625, u8p8_T),
	 FPM_InitFixedPoint_m(0.5078125, u8p8_T),
	 FPM_InitFixedPoint_m(0.61328125, u8p8_T),
	 FPM_InitFixedPoint_m(0.73828125, u8p8_T),
	 FPM_InitFixedPoint_m(0.85546875, u8p8_T),
	 FPM_InitFixedPoint_m(0.96484375, u8p8_T),
	 FPM_InitFixedPoint_m(1.08984375, u8p8_T),
	 FPM_InitFixedPoint_m(1.20703125, u8p8_T),
	 FPM_InitFixedPoint_m(1.3359375, u8p8_T),
	 FPM_InitFixedPoint_m(1.44140625, u8p8_T),
	 FPM_InitFixedPoint_m(1.57421875, u8p8_T),
	 FPM_InitFixedPoint_m(1.68359375, u8p8_T),
	 FPM_InitFixedPoint_m(1.8046875, u8p8_T),
	 FPM_InitFixedPoint_m(1.921875, u8p8_T),
	 FPM_InitFixedPoint_m(2.03515625, u8p8_T),
	 FPM_InitFixedPoint_m(2.15625, u8p8_T),
	 FPM_InitFixedPoint_m(2.26953125, u8p8_T),
	 FPM_InitFixedPoint_m(2.39453125, u8p8_T)}};

#pragma DATA_SECTION(t2_AsstWIRBlendY_Uls_u2p14, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t2_AsstWIRBlendY_Uls_u2p14[10][5] = 
	{{FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.9, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.9, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.9, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.9, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.9, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.9, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.9, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.9, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)},
	{FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.5, u2p14_T), FPM_InitFixedPoint_m(0.9, u2p14_T),
	 FPM_InitFixedPoint_m(1.0, u2p14_T)},{FPM_InitFixedPoint_m(0.0, u2p14_T),
	 FPM_InitFixedPoint_m(0.0, u2p14_T), FPM_InitFixedPoint_m(0.5, u2p14_T),
	 FPM_InitFixedPoint_m(0.9, u2p14_T), FPM_InitFixedPoint_m(1.0, u2p14_T)}};

#pragma DATA_SECTION(t2_AsstWIRBlndX_MtrNm_u5p11, ".FlashCalSeg");
CONST(uint16, CAL_CONST) t2_AsstWIRBlndX_MtrNm_u5p11[10][5] = 
	{{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)},{FPM_InitFixedPoint_m(0.0, u5p11_T),
	 FPM_InitFixedPoint_m(0.25, u5p11_T), FPM_InitFixedPoint_m(0.5, u5p11_T),
	 FPM_InitFixedPoint_m(0.75, u5p11_T),
	 FPM_InitFixedPoint_m(1.1, u5p11_T)}};



/*********************** Start of Code Footer ************************/
CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16] =
{
	&k_TunSet0_Cnt_Str,&k_TunSet1_Cnt_Str,&k_TunSet2_Cnt_Str,&k_TunSet3_Cnt_Str,&k_TunSet4_Cnt_Str,&k_TunSet5_Cnt_Str,&k_TunSet6_Cnt_Str,&k_TunSet7_Cnt_Str
};


CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16] =
{
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str},
	{&k_TunPer0_Cnt_Str,&k_TunPer1_Cnt_Str,&k_TunPer2_Cnt_Str,&k_TunPer3_Cnt_Str,&k_TunPer4_Cnt_Str,&k_TunPer5_Cnt_Str}
};

























































