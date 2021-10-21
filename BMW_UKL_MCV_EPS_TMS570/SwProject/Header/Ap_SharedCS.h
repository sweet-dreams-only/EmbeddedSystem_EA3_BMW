/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_SharedCS.h
* Module Description: Application shared client server definitions.  The curent
*                     Autosar/Vector tooling does not allow sharing a client server
*                     function across an application.  This header file externs 
*                     the functions that Nxtr has designed to work on stack 
*                     data such that sharing across applications can occur.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          1 %
* %derived_by:       xz0btk %
* %date_modified:    Mon Oct 17 17:00:23 2011 % 
*---------------------------------------------------------------------------*/
#ifndef APSHAREDCS_H
#define APSHAREDCS_H

extern FUNC(uint8, RTE_SA_MTRPOSDIAG_APPL_CODE) MtrPosDiag_Correlation(VAR(float32, AUTOMATIC) MtrPosMech_Rev_T_f32,
                                                               VAR(float32, AUTOMATIC) MtrPosMech2_Rev_T_f32,
															   P2VAR(uint16, AUTOMATIC, AUTOMATIC) FaultAccPtr_Cnt_T_u16);													 

extern FUNC(uint8, RTE_SA_MTRPOSDIAG_APPL_CODE) MtrPosDiag_SumSqrs(VAR(float32, AUTOMATIC) SinTheta1_Volts_T_f32,
                                                            VAR(float32, AUTOMATIC) CosTheta1_Volts_T_f32,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) FaultAccPtr_Cnt_T_u16);
#endif /*APSHAREDCS_H*/
