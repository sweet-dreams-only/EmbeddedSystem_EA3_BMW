
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Cd_NvMProxy_PBcfg.h
* Module Description: Configuration of the Cd_NvMProxy BSW
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
 * Version Control:
 * Date Created:      Tue Feb  7 11:23:49 2012
 * %version:          14 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Tue Jan 14 17:28:56 2014 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/07/12   1        JJW       Initial creation
 * 10/17/12   2        JJW       Generated output file
 * 11/20/12   3        JJW       Removed generation of Block status mirror array.  It is defined in the static SWC
 * 05/30/13   4        JJW       Removed unsuported config feature, added multi-block support
 */

#include "Std_Types.h"
#include "Cd_NvMProxy_Cfg.h"


/* Global data buffers to be used in NvM cfg for Read All destinations */
#define NVMPROXY_START_SEC_VAR_NOINIT_8
#include "MemMap.h"


#pragma DATA_ALIGN ( NvMP_Rte_MtrPos_MtrPosSnsr_EOLData, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_MtrPos_MtrPosSnsr_EOLData[sizeof(Rte_MtrPos_MtrPosSnsr_EOLData)];

#pragma DATA_ALIGN ( NvMP_Rte_MtrCurr_ShCurrCal, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_MtrCurr_ShCurrCal[sizeof(Rte_MtrCurr_ShCurrCal)];

#pragma DATA_ALIGN ( NvMP_Rte_HwTrq_HwTrqScaleData, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_HwTrqScaleData[sizeof(Rte_HwTrq_HwTrqScaleData)];

#pragma DATA_ALIGN ( NvMP_Rte_HwTrq_HwTrqTrimData, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_HwTrqTrimData[sizeof(Rte_HwTrq_HwTrqTrimData)];

#pragma DATA_ALIGN ( NvMP_Rte_HwTrq_EOLTrqStepData, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_EOLTrqStepData[sizeof(Rte_HwTrq_EOLTrqStepData)];

#pragma DATA_ALIGN ( NvMP_Rte_ParamComp_EOLNomMtrParam, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_ParamComp_EOLNomMtrParam[sizeof(Rte_ParamComp_EOLNomMtrParam)];

#pragma DATA_ALIGN ( NvMP_Rte_AbsHwPos_Trim, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_AbsHwPos_Trim[sizeof(Rte_AbsHwPos_Trim)];

#pragma DATA_ALIGN ( NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32[sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32)];

#pragma DATA_ALIGN ( NvMP_Rte_Polarity_k_SystemPolarity_Cnt_b16, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_Polarity_k_SystemPolarity_Cnt_b16[sizeof(Rte_Polarity_k_SystemPolarity_Cnt_b16)];

#pragma DATA_ALIGN ( NvMP_Rte_TurnsCounter_EOLTurnsCntrCals, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[sizeof(Rte_TurnsCounter_EOLTurnsCntrCals)];

#pragma DATA_ALIGN ( NvMP_CloseCheck_Cnt_u32, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_CloseCheck_Cnt_u32[sizeof(CloseCheck_Cnt_u32)];

#pragma DATA_ALIGN ( NvMP_Rte_LrnEOT_LearnedEOT, 4U); /* NXTR PATCH: Added to force 32-bit alignment: A_5202 */
VAR(uint8, AUTOMATIC) NvMP_Rte_LrnEOT_LearnedEOT[sizeof(Rte_LrnEOT_LearnedEOT)];

#define NVMPROXY_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

/* Block Test and Copy Configuration */
#define NVMPROXY_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(NvMProxyCfg_Type, AUTOMATIC) NvMProxyCfg[ D_NUMPRXYBLOCKS_CNT_U16 ] = {
	{0, NULL_PTR,  NULL_PTR, 0}, /* Multi-block fixed config */
	{Rte_NvmBlock_MtrPos_MtrPosSnsr_EOLData, (uint8*)&NvMP_Rte_MtrPos_MtrPosSnsr_EOLData,  (uint8*)&Rte_MtrPos_MtrPosSnsr_EOLData, sizeof(Rte_MtrPos_MtrPosSnsr_EOLData)},
	{Rte_NvmBlock_MtrCurr_ShCurrCal, (uint8*)&NvMP_Rte_MtrCurr_ShCurrCal,  (uint8*)&Rte_MtrCurr_ShCurrCal, sizeof(Rte_MtrCurr_ShCurrCal)},
	{Rte_NvmBlock_HwTrq_HwTrqScaleData, (uint8*)&NvMP_Rte_HwTrq_HwTrqScaleData,  (uint8*)&Rte_HwTrq_HwTrqScaleData, sizeof(Rte_HwTrq_HwTrqScaleData)},
	{Rte_NvmBlock_HwTrq_HwTrqTrimData, (uint8*)&NvMP_Rte_HwTrq_HwTrqTrimData,  (uint8*)&Rte_HwTrq_HwTrqTrimData, sizeof(Rte_HwTrq_HwTrqTrimData)},
	{Rte_NvmBlock_HwTrq_EOLTrqStepData_HwNm_f32, (uint8*)&NvMP_Rte_HwTrq_EOLTrqStepData,  (uint8*)&Rte_HwTrq_EOLTrqStepData, sizeof(Rte_HwTrq_EOLTrqStepData)},
	{Rte_NvmBlock_ParamComp_EOLNomMtrParam, (uint8*)&NvMP_Rte_ParamComp_EOLNomMtrParam,  (uint8*)&Rte_ParamComp_EOLNomMtrParam, sizeof(Rte_ParamComp_EOLNomMtrParam)},
	{Rte_NvmBlock_AbsHwPos_Trim, (uint8*)&NvMP_Rte_AbsHwPos_Trim,  (uint8*)&Rte_AbsHwPos_Trim, sizeof(Rte_AbsHwPos_Trim)},
	{Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32, (uint8*)&NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32,  (uint8*)&Rte_TrqCmdScl_TorqueCmdSF_Uls_f32, sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32)},
	{Rte_NvmBlock_Polarity_EOLCtrlPolarity, (uint8*)&NvMP_Rte_Polarity_k_SystemPolarity_Cnt_b16,  (uint8*)&Rte_Polarity_k_SystemPolarity_Cnt_b16, sizeof(Rte_Polarity_k_SystemPolarity_Cnt_b16)},
	{Rte_NvmBlock_TurnsCounter_EOLTurnsCntrCals, (uint8*)&NvMP_Rte_TurnsCounter_EOLTurnsCntrCals,  (uint8*)&Rte_TurnsCounter_EOLTurnsCntrCals, sizeof(Rte_TurnsCounter_EOLTurnsCntrCals)},
	{NVM_BLOCK_STAMD_CLOSECHECK, (uint8*)&NvMP_CloseCheck_Cnt_u32,  (uint8*)&CloseCheck_Cnt_u32, sizeof(CloseCheck_Cnt_u32)},
	{Rte_NvmBlock_LrnEOT_LearnedEOT, (uint8*)&NvMP_Rte_LrnEOT_LearnedEOT,  (uint8*)&Rte_LrnEOT_LearnedEOT, sizeof(Rte_LrnEOT_LearnedEOT)},
};
#define NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


