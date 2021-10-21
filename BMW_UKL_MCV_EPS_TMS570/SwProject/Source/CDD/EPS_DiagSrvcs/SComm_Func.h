/*****************************************************************************
* Copyright 2003 Delphi Technologies, Inc., All Rights Reserved.
* Delphi Confidential
*
* Module File Name  : SComm_Func.h
* Module Description: Prototypes for functions used by Serial Communication
*                     Driver
* Product           : Gen II Plus - EA3.0
* Author            : Bobby OSteen
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Aug 29 14:56:37 2003
* %version:          24 %
* %derived_by:       cz7lt6 %
* %date_modified:    Fri Jan 24 10:21:08 2014 %
*---------------------------------------------------------------------------*/

#ifndef SCOMM_FUNC_H
#define SCOMM_FUNC_H


#include "fpmtype.h"
#include <Std_Types.h>              /* include AUTOSAR standard types         */
#include "Rte_type.h"
#include "Cdc.h"
#include "Ap_DiagMgr.h"
#include "Rte_NtWrap.h"
#undef RTE_APPLICATION_HEADER_FILE /* undef to allow inclusion of multiple Rte header files.  Eventually an Rte SwC should be defined for this component */

/***** Diagnostic Application ****/
extern FUNC(void, EPSDIAGSRVCS_CODE) EPSDiagSrvcs_Init(void); 
extern FUNC(void, EPSDIAGSRVCS_CODE) EPSDiagSrvcs_Task(void); 

extern FUNC(void, EPSDIAGSRVCS_CODE) CDCUser_Init(void); 
extern FUNC(void, EPSDIAGSRVCS_CODE) CDCUser_Task(void); 

extern FUNC(Dcm_MsgType, SCOMMFUNC_CODE)EPSInternalPIDRead(Dcm_MsgType pbDiagData, uint16 PID, uint16 diagReqDataLen);
extern FUNC(void, SCOMMFUNC_CODE)EPSInternalPIDWrite(Dcm_MsgType pbDiagData, uint16 PID, uint16 diagReqDataLen);
extern FUNC(void, SCOMMFUNC_CODE)EPSInternalIOControl(Dcm_MsgType pbDiagData, uint16 CPID, uint16 diagReqDataLen);
extern FUNC(void, SCOMMFUNC_CODE)EPSInternalRoutineControl(Dcm_MsgType pbDiagData, uint16 RID, uint16 diagReqDataLen);

extern FUNC(void, EPSDIAGSRVCS_CODE) EPS_DiagSessionChangeIndicator(	CONST(uint8,AUTOMATIC) SesCtrlTypeOld,
   																		CONST(uint8,AUTOMATIC) SesCtrlTypeNew);

/* Diagnostic services to application Scomm functions */ 
/* MtrTrqLmt */
extern FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
extern FUNC(void, RTE_AP_MTRTRQLMT_APPL_CODE) MtrTrqLmt_SCom_ReadEOLTrqCmdSclFac(P2VAR(UInt16, AUTOMATIC, RTE_AP_MTRTRQLMT_APPL_VAR) TrqCmdSclFacPtr_Uls_T_u7p9);
extern FUNC(void, RTE_AP_MTRTRQLMT_APPL_CODE) MtrTrqLmt_SCom_SetEOLTrqCmdSclFac(UInt16 TrqCmdSclFac_Uls_T_u7p9);

/* HwTrq */
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqTrim(void);
extern FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqScale(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);
extern FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqTrim(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);

/* ParameterEst */
extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomL_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);

/* MtrPos */
extern FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_ReadEOLMtrCals(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);

/* Polarity */
extern FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt16, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Cnt_b16);
extern FUNC(Std_ReturnType, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16);

/* MtrCurr */
extern FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_ReadMtrCurrCals(P2VAR(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_VAR) ShCurrCalPtr);

/* Diagnostic Manager */
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ReadStrgArray(void);

/* Sensorless HwPos */
extern FUNC(void, RTE_AP_SNSRLESSHWPOS_APPL_CODE) SnsrlessHwPos_Scom_SetCenterPosition(void);

/* Final HwPos */
extern FUNC(void, RTE_AP_FINALHWPOS_APPL_CODE) FinalHwPos_Scom_ResetEOT(void);

/* TurnsCounter Scomm functions */
extern FUNC(void, RTE_AP_TCBASEDHWPOSA_APPL_CODE) TcBasedHwPos_Scom_ClearCenterPosition(void);
extern FUNC(void, RTE_AP_TCBASEDHWPOSA_APPL_CODE) TcBasedHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32);

extern FUNC(void, RTE_AP_FINALHWPOS_APPL_CODE) FinalHwPos_Scom_ClearRackCenter(void);
extern FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_ClearRacktoVehCntrOffset(void);
extern FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_SCom_ResetTC(void);

extern FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearRacktoVehCntrOffset(void);


extern FUNC(uint8, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_StartPrg(void);
extern FUNC(void, RTE_AP_RETURN_APPL_CODE) Return_SCom_SetEOLRtnRange(Float Par_f32);
extern FUNC(void, RTE_AP_RETURN_APPL_CODE) Return_SCom_GetEOLRtnRange(P2VAR(Float, AUTOMATIC, RTE_AP_RETURN_APPL_VAR) Par_f32);

extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Get(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32);
extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32);

extern FUNC(void, RTE_AP_LRNEOT_APPL_CODE) NtWrapC_LrnEOT_Scom_ResetEOT(void);
extern FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrRev(void);
extern FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrDeg(void);

extern FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_DataServicePort_Read(P2VAR(Dcm_Data_CALID_CVN_ArrayType, AUTOMATIC, RTE_EDCH_APPL_VAR) Data);

#endif

/*****************************************************************************
CHANGE HISTORY:

 Date      Rev      Author 			Change Description              SCR #
 				 					 (MDD Rev & Date) 		
-------   -------  --------  -----------------------------------  ----------
12/14/10   1.0	   BDO	 	 BMW Single Nxtr Service to read   CR3728
                             SW Part number 
12/16/10   2.0     BDO   	 Added Write, Routine and I/O Ctrl 	  CR3639, 3644, 3731								  		
01/03/11   3.0     BDO   	 Add extern FUNC definitions of Rte Scom functions
02/24/11   4.0     LWW       Add extern FUNC definitions of functions, added
                             passed parameters to EPS_DiagSessionChangeIndicator
04/04/11   5.0     BDO	 	 Added CDCUser_Init() and CDCUser_Task() to support RID AB6C.
05/16/11   6.0     BDO	 	 Add SnsrlessHwPos_Scom_SetCenterPosition 
							 and FinalHwPos_Scom_ResetEOT			CR4177
08/01/11   7.0     BDO     	 Add Turns Counter Scomm functions							 
10/11/11   8.0     BDO     	 Add TcFlshPrg_Scom_StartPrg 
11/28/11   9.0     BDO     	 Add Return_SCom_SetEOL and Return_SCom_GetEOL functions                CR4700
11/29/11   10.0	   BDO     	 Add TrqCmdScl_SCom_Set and xxx_Get, correct Return_SCom_GetEOL defn 	CR4713
12/22/11   11.0	   BDO     	 Remove old and Add new ParameterEst Read/Write Scom API's for DID FD0C
01/18/11   12	   JJW       Update data type of DiagMgr_SCom_ReadStrgArray passed paramater per new server port def
02/16/12   13      BDO		 Updates to support BMW Position Control Routines AB56, AB71, AB72
03/14/12   14      JJW		 Renamed TurnsCounter_SCom_ResetTC for TurnsCounter FDD20C_003.3 integration
06/20/12   15      BDO       Updates for anomaly 2749, FDDs 5C, 20C and SF-11 changes - CR5712, CR5685, CR5700
08/18/12   16      BDO       Updates for Learn Rack Center FDD 39
10/07/12   17      JJW       Integration of DiagMgr FDD37B_001.16
11/01/12   18      JJW       Integration of Non-Trusted Function call wrappers (direct function definitions removed)
11/09/12   19      JJW       Inclusion of Rte_NtWrap.h to provide the trusted and non-trusted interface functions 
11/12/12   20      JJW       AssistLmtFunc_Scom_ManualTrqCmd() prototype change for integration of AssistSumnLmt SF04A_008.2
01/24/14   23	   KJS		 Updated extern statement for LrnEOT_Scom_ResetEOT for NtWrap support. 
06/04/14   24	   KJS		 Added support for Edch service ReadDataPort
******************************************************************************/
