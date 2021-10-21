/*******************************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Edch_NxtrNvM.h
* Module Description: Header file for NvM configuration mappings
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*******************************************************************************************/
/* Version Control:
 * Date Created:      Fri Nov 5 16:33:22 2010
 * %version:          1 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Tue Jan 14 17:34:25 2014 %
 *----------------------------------------------------------------------------------------
 *  Date       Rev     Author   Change Description                           	   SCR #
 * -------   -------  --------  ----------------------------------------------  ----------
 * 06/03/14		1		KJS		Initial version
 *
******************************************************************************************/

#include "NvM.h"
#include "Edch_NvM.h"

#ifndef EDCH_NXTRNVM_H_
#define EDCH_NXTRNVM_H_

/* RTE like define statements */
#define Rte_Call_NvMBlock_CalId_WriteBlock(x)				NvM_WriteBlock((uint8)NVM_EDCH_CALID, x)
#define Rte_Call_NvMBlock_Cvn_WriteBlock(x)                 NvM_WriteBlock((uint8)NVM_EDCH_CVN, x)
#define Rte_Call_NvMBlock_OperationCycleState_WriteBlock(x) NvM_WriteBlock((uint8)NVM_EDCH_OPCYCLESTATE, x)
#define Rte_Call_NvMBlock_SubCvn_0_WriteBlock(x)            NvM_WriteBlock((uint8)NVM_EDCH_SUBCVN0, x)
#define Rte_Call_NvMBlock_SubCvn_1_WriteBlock(x)            NvM_WriteBlock((uint8)NVM_EDCH_SUBCVN1, x)
#define Rte_Call_NvMBlock_SubCvn_2_WriteBlock(x)            NvM_WriteBlock((uint8)NVM_EDCH_SUBCVN2, x)

#endif /* EDCH_NXTRNVM_H_ */
