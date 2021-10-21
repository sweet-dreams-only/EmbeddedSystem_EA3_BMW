/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : EPS_DiagSrvcs_CommonFunc.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains configurations that are shared between ISO and XCP services.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          16 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Sat Jan 18 14:18:40 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/12/12 	1		KS		Initial Version
 * 12/07/12     5       JJW     Default data anomaly correction
 * 01/28/13     6       KJS     Updates for new polarity RAM variable
 * 03/21/13		7		KJS		Updates for new EOL Turns Counter calibration defaults
 * 04/03/13		8		JJW		Rte_Call_Nvm_RpNotifyInit__Rte_NvmBlock_TurnsCounter_EOLTurnsCntrCals_InitBlock manual
 *								mapping
 * 06/27/13		10	    JJW		Consolidated AbsHwPos Pim Nvm into a single Trim Block
 * 09/25/13		11	    KJS		Added HWAP support
 * 01/14/14		13	    KJS		Added NvMP support for learned EOT values.
 * 11/05/14		15	    KJS		Added Fee Init flag
 * 03/25/15     16		ABS	    EA3#259 Taigene/Letrika Motor Service
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"
#include "GlobalMacro.h"
#include "NvM.h"
#include "CDD_Data.h"
#include "DataLogistic.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef RTE_AP_DFLTCONFIGDATA_H
#define RTE_AP_DFLTCONFIGDATA_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* RAM references */

extern CONST(uint8, CDD_PARTNUMBER)k_SWRelNum_Cnt_u8[50];
extern CONST(uint8, CDD_PARTNUMBER) k_CalRelNum_Cnt_u8[50];
extern CONST(uint8, CDD_PARTNUMBER) k_SysSupplierID[3];

/* CMS Values */
extern VAR(uint8, CDD_PARTNUMBER) Nvm_NMEC_Cnt_u8;
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EcuSrlNum_Cnt_u8[4];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EpsSrlNum_Cnt_u8[4];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EcuHwPn_Cnt_u8[12];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_NxtrManfScrpd_Cnt_u8[64];
extern VAR(uint16, CDD_PARTNUMBER) Nvm_IgnCntr_Cnt_u16;



/*******************************************************************************
 *	NvM Block Value Init Definitions
 */
 
/* The NvM Generator produces Rte_Call style definitions for blocks which are configured to provide service ports
 * The correct use of these functions through the Rte is not understood at this time because the Rte is not 
 * initialized while the NvM Read All occurs.  For the time being the macros are being defined here to map the NvM
 * init call backs to the appropriate function provided by this module.
 */ 
#define  Rte_Call_Nvm_RpNotifyInit__Rte_NvmBlock_MtrPosSnsrLearning_MtrSnsrLrnParam_InitBlock	DfltConfigData_MtrPosSnsrLearning_MtrSnsrLrnParam
#define  Rte_Call_Nvm_RpNotifyInit__NVM_BLOCK_DIAGMGR_NTCSTRG_InitBlock							DfltConfigData_DIAGMGR_NTCSTRG
#define  Rte_Call_Nvm_RpNotifyInit__NVM_BLOCK_CMS_ECUHWPN_InitBlock								DfltConfigData_CMS_ECUHWPN
#define  Rte_Call_Nvm_RpNotifyInit__Rte_NvmBlock_TurnsCounter_EOLTurnsCntrCals_InitBlock		DfltConfigData_TurnsCounter_TcEOLCals

/* NVM ROM Value Blocks */
extern CONST(HwTrqTrim_Datatype, CDD_PARTNUMBER) T_InitHwTrq_HwTrqTrimData;
extern CONST(HwTrqScale_Datatype, CDD_PARTNUMBER) T_InitHwTrq_HwTrqScaleData;
extern CONST(EOTLearned_DataType, CDD_PARTNUMBER) T_InitLearnedEOT;
extern CONST(RackCenterType, CDD_PARTNUMBER) T_InitLnRkCtr_RackCntrData;
extern CONST(uint32, CDD_PARTNUMBER) T_InitEPSDefeats_Cnt_u32;
extern CONST(uint8, CDD_PARTNUMBER) T_InitNMEC_Cnt_u8;
extern CONST(AbsHwPosTrim_DataType, CDD_PARTNUMBER) T_InitAbsHwPos_Trim;
extern CONST(uint8, CDD_PARTNUMBER) T_MtrSuplrService_Data;

/* NVM Block Init functions */
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_MtrPosSnsr_EOLData(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_MtrPosSnsrLearning_MtrSnsrLrnParam(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_IGNCNTR(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_VehCfg_PrevVldTuningSel(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_TrqCmdScl_TorqueCmdSF_Uls_f32(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_ParamComp_EOLNomMtrParam(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Polarity_EOLCtrlPolarity(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_HwTrq_EOLTrqStepData(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_CMS_ECUHWPN(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_DIAGMGR_NTCSTRG(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_TurnsCounter_TcEOLCals(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_HWAPInitSetup(void);
extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_HWAPSysSuppSetup(P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataBuffer_Uls_T_u8);

/* NVM RAM Block externally defined symbols used by NVM Block Init functions */
extern VAR(MtrPosCal_DataType, CDD_PARTNUMBER) Rte_MtrPos_MtrPosSnsr_EOLData;
extern VAR(MtrSnsrLearned_DataType, CDD_PARTNUMBER) Rte_MtrPosSnsrLearning_MtrSnsrLearnedParam;
extern VAR(Float, CDD_PARTNUMBER) Rte_TrqCmdScl_TorqueCmdSF_Uls_f32;
extern VAR(EOLNomMtrParamType, CDD_PARTNUMBER) Rte_ParamComp_EOLNomMtrParam;
extern VAR(EOLTrqStepType, CDD_PARTNUMBER) Rte_HwTrq_EOLTrqStepData;
extern VAR(AbsHwPosTrim_DataType, CDD_PARTNUMBER) Rte_AbsHwPos_Trim;
extern VAR(HwTrqTrim_Datatype, CDD_PARTNUMBER) Rte_HwTrq_HwTrqTrimData;
extern VAR(HwTrqScale_Datatype, CDD_PARTNUMBER) Rte_HwTrq_HwTrqScaleData;
extern VAR(EOLTurnsCntrCals_Datatype, CDD_PARTNUMBER) Rte_TurnsCounter_EOLTurnsCntrCals;

extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_MtrPos_MtrPosSnsr_EOLData[sizeof(Rte_MtrPos_MtrPosSnsr_EOLData)];
extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_MtrPosSnsrLearning_MtrSnsrLearnedParam[sizeof(Rte_MtrPosSnsrLearning_MtrSnsrLearnedParam)];
extern VAR(TuningSelectParam, CDD_PARTNUMBER) Rte_VehCfg_PrevVldTuningSel;
extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32[sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32)];
extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_ParamComp_EOLNomMtrParam[sizeof(Rte_ParamComp_EOLNomMtrParam)];
extern VAR(uint16, CDD_PARTNUMBER) Rte_Polarity_k_SystemPolarity_Cnt_b16;
extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_HwTrq_EOLTrqStepData[sizeof(Rte_HwTrq_EOLTrqStepData)];
extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_AbsHwPos_Trim[sizeof(Rte_AbsHwPos_Trim)];
extern VAR(EOTLearned_DataType, CDD_PARTNUMBER) Rte_LrnEOT_LearnedEOT;
extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_HwTrq_HwTrqTrimData[sizeof(Rte_HwTrq_HwTrqTrimData)];
extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_HwTrq_HwTrqScaleData[sizeof(Rte_HwTrq_HwTrqScaleData)];
extern VAR(RackCenterType, CDD_PARTNUMBER) Rte_LnRkCr_LearnedRackCntr;
extern VAR(uint8, CDD_PARTNUMBER) NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[sizeof(Rte_TurnsCounter_EOLTurnsCntrCals)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_LrnEOT_LearnedEOT[sizeof(Rte_LrnEOT_LearnedEOT)];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_MtrSuplrByte_Cnt_u8;
extern VAR(uint8, NVM_APPL_DATA) Nxtr_FeeInitialized_Cnt_u8[2u];
extern VAR(uint16, CDD_PARTNUMBER) Nvm_ElecHwIndex_Cnt_u16;

extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void);

#endif /* RTE_AP_DFLTCONFIGDATA_H */
