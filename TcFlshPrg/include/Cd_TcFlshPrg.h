/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Cd_TcFlshPrg.h
* Module Description: Turns Counter PIC Programming
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          2 %
 * %derived_by:       nz63rn %
 * %date_modified:    Tue Jan 14 12:09:18 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        KJS       Initial K2xx Synergy Version
 * 01/14/14  2        KMC       Updated TcFlshPrg_Scom_FlshPrgStatus() and added 								11183
 *                              TcFlshPrg_Scom_TcFlashTraceability(); added new typedefs and NVM extern
 *                              for updates to FDD98 ver 003 autoflash support
 */

#ifndef CD_TCFLSHPRG_H_
#define CD_TCFLSHPRG_H_

/***************************************************************************************************
* Include files
***************************************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"


/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/

typedef enum {
	NotActivated		=	0,
	EnterPrgMode		= 	1,
	SendKey				=	2,
	BulkErase			=	3,
	ConfigWords1		=	4,
	ConfigWords2		=	5,
	PrgMemBlock1		=	6,
	PrgMemBlockSeq		=	7,
	VerifyPrgMem		=	8,
	PrgCompletePass		=	9,
	PrgCompleteFail		=	10
} TcFlshPrgMode_T;

typedef struct  {
	uint32 LastVldTcPnFlashed_Cnt_u32;
	uint16 TcFlashComplete_Cnt_u16;
	uint16 TcFlashIgnCnt_Cnt_u16;
	uint16 TcFlashCounter_Cnt_u16;
}TcFlshNvmType;
	
typedef struct  {
	uint32 ExpectedTcPn_Cnt_u32;
	TcFlshNvmType TcFlashNvm_Uls_str;
	uint8 TcFlashStatus_Cnt_u08;
}TcFlshTraceabilityType;

extern VAR(TcFlshNvmType, NVM_APPL_DATA) TcFlshDataNvm_Uls_str;

/* Prototypes */
extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Init(void);
extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Per1(void);
extern FUNC(uint8, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_StartPrg(void);
extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_TcFlashTraceability(P2VAR(TcFlshTraceabilityType, AUTOMATIC, AUTOMATIC) pTcFlshTraceabilityData);

extern FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_FlshPrgStatus( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pTcFlashActive, P2VAR(uint16, AUTOMATIC, AUTOMATIC) ptrTcDataCntr,
																	   P2VAR(TcFlshPrgMode_T, AUTOMATIC, AUTOMATIC) ptrTcPrgState);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
extern FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(UInt8, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr);
# else
extern FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(TcPartNumType, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr);
# endif

#endif /* CD_TCFLSHPRG_H_ */
