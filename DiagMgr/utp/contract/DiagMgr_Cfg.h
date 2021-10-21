
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : DiagMgr_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 19.09.2012 17:43:54
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          4 %
 * %date_modified:    Fri Apr 26 16:16:57 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/13/12   1       JJW       Initial template creation
 */

#ifndef DIAGMGR_CFG_H
#define DIAGMGR_CFG_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*** Public Part (used by DiagMgr API) *****************************************/

#include "Std_Types.h"                   /* Standard type definitions      */

 



extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgrQM_GetNTCFailed( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCFailed_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgrQM_GetNTCActive( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(boolean, AUTOMATIC, AUTOMATIC) NTCActive_Ptr_T_lgc );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgrQM_GetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08 );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgrQM_SetNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgrQM_ReportNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );



/*** Private Part (used by DiagMgr.c only) *************************************/
#ifdef DIAGMGR_C
/* Provide access to the direct access S/R port definitions for black box data */
#if defined(DIAGMGR_DEMIF_RTEHEADER)	
#include "Rte_Ap_DiagMgr.h"
#elif defined(DIAGMGR_FAILACTION_RTEHEADER)
/* Provide access to the direct access S/R port definitions for black box data */
#include "Rte_Ap_DiagMgr.h"
#else
#endif
#define DIAGMGR_DEV_ERROR_DETECT					STD_OFF

#define D_NUMOFDEMEVENTS_CNT_U08					29U

/* DiagMgr Event Block Configuration Definitions */
typedef struct {
	uint8 Param;
   	uint8 Status;
	uint8 AgingCounter;
} NTCInfo_Str;

typedef struct {
	NTCNumber NTC;
	uint8 Param;
   	NxtrDiagMgrStatus Status;
} NTCInfoQueue_Str;

typedef struct {
	P2VAR(NTCInfo_Str, AUTOMATIC, AUTOMATIC) NTCInfoPtr;
   	uint8 NumElements;
} DiagMgrNtcInfoMap_Str;

typedef struct {
	uint8 AppIdx;	/* Application index, key to DiagMgrNtcInfoMap_Str table */
   	uint8 InfoIdx;  /* NTCInfo index of of table found by using the AppIdx into the DiagMgrNtcInfoMap_Str table */
} DiagMgrNtcAppMap_Str;

 

/* APP_QM Application SWC Internal Defs*/
#define DIAGMGR_EVENTNUM_QM                               91u
#define DIAGMGR_APID_QM                                   0u

extern VAR(uint8, AP_DIAGMGR_VAR) ActDiagStsQM_Cnt_M_u08;
extern VAR(uint8, AP_DIAGMGR_VAR) ResetNTCFlagQM_Cnt_M_u08;
extern VAR(uint8, AP_DIAGMGR_VAR) ResetNTCFlag_Cnt_M_u08;
extern VAR(uint16, AP_DIAGMGR_VAR) DiagStsQM_Cnt_M_b16[2u];
extern VAR(float32, AP_DIAGMGR_VAR) ActiveRmpRateQM_UlspmS_M_f32[2u];
extern VAR(boolean, AP_DIAGMGR_VAR) DiagMgrInitCompQM_Cnt_M_lgc;
extern VAR(NTCInfo_Str, AP_DIAGMGR_VAR)	DiagMgr_NTCInfoQM_Cnt_M_str[DIAGMGR_EVENTNUM_QM];
extern CONST(NTCNumber, AUTOMATIC) T_NTCMapTblQM_Cnt_enum[DIAGMGR_EVENTNUM_QM];
extern VAR(uint8, AP_DIAGMGR_VAR) NTCQueueIndexQM_Cnt_M_u08;
extern VAR(NTCInfoQueue_Str, AP_DIAGMGR_VAR)	NTCInfoQueueQM_Cnt_M_str[3];

#define DIAGMGR_NUMAPPS                                   1u
extern CONST(DiagMgrNtcAppMap_Str, AP_DIAGMGR_CONST) T_DiagMgrNtcAppInfoMap_Cnt_Str[512u];
extern CONST(DiagMgrNtcInfoMap_Str, AP_DIAGMGR_CONST) T_DiagMgrNtcInfoPtr_Cnt_Str[DIAGMGR_NUMAPPS];
extern CONSTP2VAR(uint16, AUTOMATIC, AP_DIAGMGR_CONST) T_DiagMgrDiagSts_Ptr_b16[DIAGMGR_NUMAPPS];
extern CONSTP2VAR(float32, AUTOMATIC, AP_DIAGMGR_CONST) T_DiagMgrRmpRate_Ptr_f32[DIAGMGR_NUMAPPS];

extern void Rte_Call_DiagMgr_Per1_CP0_CheckpointReached(void);
extern void Rte_Call_DiagMgr_Per1_CP1_CheckpointReached(void);
extern void Rte_Call_DiagMgr_Per2_CP0_CheckpointReached(void);
extern void Rte_Call_DiagMgr_Per2_CP1_CheckpointReached(void);

#endif /* DIAGMGR_C                                                            */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*** Public Part (DiagMgr API) *****************************************/

/*
 * File version information
 */
#define DIAGMGR_CFG_H_MAJOR_VERSION   1u
#define DIAGMGR_CFG_H_MINOR_VERSION   0u
#define DIAGMGR_CFG_H_PATCH_VERSION   0u

/*
 * API enable settings
 */

   
#endif /* DIAGMGR_CFG_H */

/*** End of file **************************************************************/
