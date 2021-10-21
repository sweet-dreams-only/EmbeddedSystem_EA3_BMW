/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : NtWrap.h
* Module Description: Non-trusted function call wrapper definitions to allow
*						calling of SCom server functions not located in the
*						application with the Diag service handler.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Oct 30 14:56:37 2012
* %version:          5 %
* %derived_by:       xz0btk %
* %date_modified:    Thu Jan 17 15:05:29 2013 %
*---------------------------------------------------------------------------*/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          5 %
 * %date_modified:    Thu Jan 17 15:05:29 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/14/12   3       JJW       Added NT wrappers for the Wdg and WdgM Init functions.  Restructured NT return to allow
 *								wrapper invocation from seperate priority levls without consistency concern.  Added Det
 * 01/14/13   4       JJW       Integration of CBD_Xcp_001.1
 */

#ifndef NTWRAP_H
#define NTWRAP_H

#include "Std_Types.h"
#include "Rte_Type.h"
#include "WdgM.h"
#include "Wdg_TMS570LS3x.h"

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Adc_Init();
FUNC(void, NTWRAP_CODE) NtWrapC_GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqScale(void);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqTrim(void);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);
FUNC(void, NTWRAP_CODE) NtWrapC_HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_SetHwTrqScale(Float ScaleValue);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_SetHwTrqTrim(void);
FUNC(void, NTWRAP_CODE) NtWrapC_LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_MtrCurr_SCom_CalGain(void);
FUNC(void, NTWRAP_CODE) NtWrapC_MtrCurr_SCom_CalOffset(void);
FUNC(void, NTWRAP_CODE) NtWrapC_MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_DATA) ShCurrCalPtr);
FUNC(void, NTWRAP_CODE) NtWrapC_OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32);
FUNC(void, NTWRAP_CODE) NtWrapC_TurnsCounter_SCom_ResetTC(void);
FUNC(void, NTWRAP_CODE) NtWrapC_WdgM_Init(P2CONST (WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) WdgMConfigPtr);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_Wdg_TMS570LS3x_Init(P2CONST(Wdg_TMS570LS3x_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr);

FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp7(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);
FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp8(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);
FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp9(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);
FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp11(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);

FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_XcpWriteAp4(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams);
FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_XcpWriteAp10(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams);

/*** Private Part (NtWrap Internal) *************************************/
#ifdef NTWRAP_C

#define		NTWRAP_DEV_ERROR_DETECT					STD_ON /* TODO: move NTWRAP_DEV_ERROR_DETECT to a cfg file */

#define 	NtWrap_ReportDet( errorId )				Det_ReportError( 0u /*ModuleId*/, 0u /*InstanceId*/, 0u /*ApiId*/, errorId )
#define		D_NTWRAPINVLDINDXDET_CNT_U08			0x00U

#endif


#endif
