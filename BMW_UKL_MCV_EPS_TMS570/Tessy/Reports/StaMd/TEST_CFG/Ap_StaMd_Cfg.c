
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_StaMd_Cfg.c
* Module Description: Configuration file of StaMd module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 07.06.2013 20:26:03
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Thu Mar  6 14:38:49 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 10/10/12   1       LWW       Initial template creation
 * 10/24/12   2       LWW       Added exclude configuration for applications to skip generation
 * 06/05/13   3       KJS       Added support for SysC global variables
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#define STAMD_C /* Enable visibility to Module internal definitions in StaMd.h*/
#include "Ap_StaMd_Cfg.h"


/*******************************************************************************
**                      Module Private Data                                   **
*******************************************************************************/
 
#define STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
	
	VAR(Rte_ModeType_StaMd_Mode, AP_STAMD_VAR) SystemState_Cnt_M_enum = RTE_MODE_StaMd_Mode_WARMINIT;
#define STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define STAMD10_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
	
	VAR(uint32, AP_STAMD_VAR) WarmInitMilestoneRqst_Cnt_M_u32;
#define STAMD10_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

	
#define STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
	
	VAR(boolean, AP_STAMD_VAR) StopTODPerOperation_Cnt_M_lgc;
	VAR(boolean, AP_STAMD_VAR) FinalNvMWriteInProgress_Cnt_M_lgc;
	VAR(boolean, AP_STAMD_VAR) TransitionComplete_Cnt_M_lgc;
	VAR(boolean, AP_STAMD_VAR) TODState_Cnt_M_lgc;
	
	/***********Updated Section******************/
	/*uint8 Lnk_TypeH10_Start;
	uint32* Lnk_TypeH10_Size;
	uint16 a;
	
	uint8 Lnk_TypeH8_Start;
	uint32* Lnk_TypeH8_Size;
	
	uint8 Lnk_TypeH9_Start;
	uint32* Lnk_TypeH9_Size;
	
	uint8 Lnk_TypeH11_Start; 
	uint32* Lnk_TypeH11_Size;
	
	uint8 Lnk_TypeH4_Start;
	uint32* Lnk_TypeH4_Size;
	uint8 Lnk_TypeH7_Start;
	uint32* Lnk_TypeH7_Size;
	
	VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;
	VAR(Rte_tsTask_2msB_10, RTE_VAR_NOINIT) Rte_Task_2msB_10;
	CONST(DiagSettings_Str, CAL_CONST) k_StaMdsSysCDiag_Cnt_str; */
	/****************************************************************************************/
	
	
#define STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

	
#define STAMD10_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
	volatile VAR(uint8, AP_STAMD_VAR) StTrnsVctr_Cnt_D_b08;
#define STAMD10_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#define STAMD8_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
	VAR(Rte_ModeType_StaMd_Mode, AP_STAMD_VAR) SystemState8_Cnt_M_enum = RTE_MODE_StaMd_Mode_WARMINIT;
	VAR(Rte_ModeType_StaMd_Mode, AP_STAMD_VAR) SysCSystemState_Cnt_M_enum = RTE_MODE_StaMd_Mode_WARMINIT;
#define STAMD8_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define STAMD8_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
	VAR(uint16, AP_STAMD_VAR) StaMdsSysCFltCntr_Cnt_M_u16;
#define STAMD8_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#define STAMD8_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
	VAR(uint32, AP_STAMD_VAR) WarmInitMilestoneRqst8_Cnt_M_u32;
#define STAMD8_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"


#define STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
	VAR(Rte_ModeType_StaMd_Mode, AP_STAMD_VAR) SystemState9_Cnt_M_enum = RTE_MODE_StaMd_Mode_WARMINIT;
#define STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define STAMD9_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
	VAR(uint32, AP_STAMD_VAR) WarmInitMilestoneRqst9_Cnt_M_u32;
#define STAMD9_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

	
#define STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
	VAR(boolean, AP_STAMD_VAR) EcuResetActive_Cnt_M_lgc;
#define STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define STAMD11_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
	VAR(Rte_ModeType_StaMd_Mode, AP_STAMD_VAR) SystemState11_Cnt_M_enum = RTE_MODE_StaMd_Mode_WARMINIT;
#define STAMD11_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define STAMD11_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
	VAR(uint32, AP_STAMD_VAR) WarmInitMilestoneRqst11_Cnt_M_u32;
#define STAMD11_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"


#define STAMD7_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
	VAR(Rte_ModeType_StaMd_Mode, AP_STAMD_VAR) SystemState7_Cnt_M_enum = RTE_MODE_StaMd_Mode_WARMINIT;
#define STAMD7_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define STAMD7_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
	VAR(uint32, AP_STAMD_VAR) WarmInitMilestoneRqst7_Cnt_M_u32;
#define STAMD7_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"


CONST(TypeHInfoType_Str, AP_STAMD_CONST) T_TypeHInfo_Cnt_Str[6] = {
	{&Lnk_TypeH10_Start, (uint32)&Lnk_TypeH10_Size},
	{&Lnk_TypeH8_Start, (uint32)&Lnk_TypeH8_Size},
	{&Lnk_TypeH9_Start, (uint32)&Lnk_TypeH9_Size},
	{&Lnk_TypeH11_Start, (uint32)&Lnk_TypeH11_Size},
	{&Lnk_TypeH4_Start, (uint32)&Lnk_TypeH4_Size},
	{&Lnk_TypeH7_Start, (uint32)&Lnk_TypeH7_Size},
};
CONSTP2VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC, AP_STAMD_CONST) T_CurrentSystemState_Ptr_enum[5] = {
	&SystemState_Cnt_M_enum,
	&SystemState8_Cnt_M_enum,
	&SystemState9_Cnt_M_enum,
	&SystemState11_Cnt_M_enum,
	&SystemState7_Cnt_M_enum,
};
CONSTP2VAR(uint32, AUTOMATIC, AP_STAMD_CONST) T_WarmInitMilestoneRqst_Ptr_enum[5] = {
	&WarmInitMilestoneRqst_Cnt_M_u32,
	&WarmInitMilestoneRqst8_Cnt_M_u32,
	&WarmInitMilestoneRqst9_Cnt_M_u32,
	&WarmInitMilestoneRqst11_Cnt_M_u32,
	&WarmInitMilestoneRqst7_Cnt_M_u32,
};
