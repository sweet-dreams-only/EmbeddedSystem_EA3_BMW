
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_DemIf_NxtrAddon.h
* Module Description: File contains the index definitions for the diagnostic monitor generated for the DemIf
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 24.05.2017 10:31:41
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri May 09 10:10:17 2014
 * %version:          EA3#5 %
 * %date_modified:    Fri May 09 10:10:17 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 05/09/14   1       KJS       Initial template creation
 */

#ifndef AP_DEMIF_NXTRADDON_H
#define AP_DEMIF_NXTRADDON_H

extern FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_SetEventStatusIN(Edch_EventIdxType IdxIN, Dem_EventStatusType EventStatus);
typedef Std_ReturnType (*EdchSetMonitor_T)(Edch_EventIdxType IdxIN, Dem_EventStatusType EventStatus);

typedef struct EdchRelDiag_Str {
	uint8				DEMEventId;
	EdchSetMonitor_T	func;
}EdchRelDiag_Str;

/* Values are generated based on the Edch configuration. */

#define D_NUMOFEDCHDIAG_CNT_U8	18U
#define D_DIAGNOSTICMONITOR_19_EDCHIDX_CNT_U8	0U
#define D_DIAGNOSTICMONITOR_36_EDCHIDX_CNT_U8	1U
#define D_DIAGNOSTICMONITOR_37_EDCHIDX_CNT_U8	2U
#define D_DIAGNOSTICMONITOR_41_EDCHIDX_CNT_U8	3U
#define D_DIAGNOSTICMONITOR_38_EDCHIDX_CNT_U8	4U
#define D_DIAGNOSTICMONITOR_40_EDCHIDX_CNT_U8	5U
#define D_DIAGNOSTICMONITOR_39_EDCHIDX_CNT_U8	6U
#define D_DIAGNOSTICMONITOR_42_EDCHIDX_CNT_U8	7U
#define D_DIAGNOSTICMONITOR_55_EDCHIDX_CNT_U8	8U
#define D_DIAGNOSTICMONITOR_58_EDCHIDX_CNT_U8	9U
#define D_DIAGNOSTICMONITOR_74_EDCHIDX_CNT_U8	10U
#define D_DIAGNOSTICMONITOR_75_EDCHIDX_CNT_U8	11U
#define D_DIAGNOSTICMONITOR_23_EDCHIDX_CNT_U8	12U
#define D_DIAGNOSTICMONITOR_76_EDCHIDX_CNT_U8	13U
#define D_DIAGNOSTICMONITOR_77_EDCHIDX_CNT_U8	14U
#define D_DIAGNOSTICMONITOR_78_EDCHIDX_CNT_U8	15U
#define D_DIAGNOSTICMONITOR_79_EDCHIDX_CNT_U8	16U
#define D_DIAGNOSTICMONITOR_80_EDCHIDX_CNT_U8	17U

#define DEMIF_START_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(EdchRelDiag_Str, AP_DEMIF_CODE) t_EdchRelDiagTbl_str[] = 
{
	{19U, &Edch_SetEventStatusIN},	/* MTRPOS_FAILED */
	{36U, &Edch_SetEventStatusIN},	/* FR_PHYS_FAILURE */
	{37U, &Edch_SetEventStatusIN},	/* FR_COMM_FAILURE */
	{41U, &Edch_SetEventStatusIN},	/* OFFS_QUAD_EPS_MULTSIG_INVALID */
	{38U, &Edch_SetEventStatusIN},	/* OFFS_QUAD_EPS_MISSING */
	{40U, &Edch_SetEventStatusIN},	/* CRC_OFFS_QUAD_EPS_ERROR */
	{39U, &Edch_SetEventStatusIN},	/* ALIV_OFFS_QUAD_EPS_ERROR */
	{42U, &Edch_SetEventStatusIN},	/* OFFS_QUAD_EPS_MULTSIG_ERROR */
	{55U, &Edch_SetEventStatusIN},	/* SWA_SENSOR_LOSS_MULTITURN */
	{58U, &Edch_SetEventStatusIN},	/* SWA_NOT_STRAIGHT_LINE_LEARNED */
	{74U, &Edch_SetEventStatusIN},	/* STEERING_ANGLE_SNSR_HW_FAILURE */
	{75U, &Edch_SetEventStatusIN},	/* STEERING_ANGLE_SNSR_HW_FAILURE_INT */
	{23U, &Edch_SetEventStatusIN},	/* ROM_FAILURE */
	{76U, &Edch_SetEventStatusIN},	/* NVM_FAILURE */
	{77U, &Edch_SetEventStatusIN},	/* RAM_FAILURE */
	{78U, &Edch_SetEventStatusIN},	/* GENERAL_MCU_FAILURE */
	{79U, &Edch_SetEventStatusIN},	/* SOFTWARE_RUNTIME_FAILURE */
	{80U, &Edch_SetEventStatusIN} 	/* WATCHDOG_EVENT */
};
#define DEMIF_STOP_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */



#endif /* AP_DEMIF_NXTRADDON_H */
/*** End of file **************************************************************/
