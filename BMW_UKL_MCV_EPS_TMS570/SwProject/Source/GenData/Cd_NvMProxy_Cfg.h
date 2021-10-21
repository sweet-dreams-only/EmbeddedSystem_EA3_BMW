
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Cd_NvMProxy_Cfg.h
* Module Description: Configuration of the Cd_NvMProxy BSW
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
 * Version Control:
 * Date Created:      Tue Feb  7 11:23:49 2012
 * %version:          12 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Tue Jan 14 17:28:56 2014 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/07/12   1        JJW       Initial creation
 * 10/17/12   2        JJW       Generated output file
 * 05/30/13   3        JJW       Removed unsuported config feature, added multi-block support
 */

#ifndef NVMPROXY_CFG_H
#define NVMPROXY_CFG_H


/* Include defs for data block types */
#define RTE_MICROSAR_PIM_EXPORT /* Define the Rte constant to allow exporting of PIM types to this CDD */
#include "Rte_Type.h"
#include "NvM.h"



typedef struct {
	CONST(NvM_BlockIdType, AUTOMATIC) NvMBlock;
	CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) unsecurePtr;
	CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) securePtr;
	CONST(uint16, AUTOMATIC) secureSize;
} NvMProxyCfg_Type;

#define D_NUMPRXYBLOCKS_CNT_U16    13u

extern CONST(NvMProxyCfg_Type, AUTOMATIC) NvMProxyCfg[ D_NUMPRXYBLOCKS_CNT_U16 ];

extern VAR(uint8, AUTOMATIC) NvMP_Rte_MtrPos_MtrPosSnsr_EOLData[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_MtrCurr_ShCurrCal[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_HwTrqScaleData[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_HwTrqTrimData[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_EOLTrqStepData[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_ParamComp_EOLNomMtrParam[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_AbsHwPos_Trim[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Polarity_k_SystemPolarity_Cnt_b16[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[];
extern VAR(uint8, AUTOMATIC) NvMP_CloseCheck_Cnt_u32[];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_LrnEOT_LearnedEOT[];

extern VAR(uint32, AUTOMATIC) CloseCheck_Cnt_u32; /* Nxtr Patch to generator to support variables which are not extern'd via a header file */

#endif
