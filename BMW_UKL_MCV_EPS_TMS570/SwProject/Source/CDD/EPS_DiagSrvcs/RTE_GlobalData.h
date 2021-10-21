/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Delphi Confidential
*
* Module File Name  : RTE_GlobalData.h file
* Module Description: Contains global Rte data used in Diagnostic Srvcs.
* Product           : Gen II Plus - EA3.0
* Author            : Bobby O'Steen
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Apr 20 15:57:01 2010 %
* %version:          EA3#36 %
* %date_modified:    Fri May 31 21:14:39 2013 %
*---------------------------------------------------------------------------*/
#include "fpmtype.h"
#include "Compiler.h"
#include "Rte_type.h"				/* For Rte component outputs */ 


#ifndef RTE_GLOBALDATA_H
#define RTE_GLOBALDATA_H

extern VAR(Float, RTE_VAR_NOINIT) Rte_SrlComInput2_SrlComVehSpd_Kph_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_CurrentEst_EstMtrCurrQax_Amp_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrPos2_MechMtrPos_Rev_f32;
extern VAR(Float, RTE_VAR_NOINIT) MtrPos3_DiagMechMtrPos_Rev_M_f32;

extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr_ResetEventStatus(void);

extern VAR(Boolean, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComEngOn_Cnt_lgc;
extern VAR(RackCenterType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_LnRkCr_LearnedRackCntr;
extern VAR(Float, RTE_VAR_INIT) Rte_LktoLkStr_LrnPnCntrHwTravel_HwDeg_f32;
extern VAR(ManufModeType, RTE_VAR_INIT) Rte_CDDInterface9_NxtrMEC_Cnt_enum;


/* PID Values */
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;
extern VAR(Float, RTE_VAR_NOINIT) Rte_BatteryVoltage_Vecu_Volt_f32;
// T1
// T2
extern VAR(Float, RTE_VAR_NOINIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;
// P1
// P2
// P3
// P4

// HW Pos
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrPos_MfgMtrBasedPos_HwDeg_f32;
// blank
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrTrqLmt_MRFMtrTrqCmd_MtrNm_f32;
// Digital T1 (PWM)
// Digital T2 (PWM)
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrVel_MRFMtrVel_MtrRadpS_f32;
extern VAR(Float, RTE_VAR_NOINIT) Rte_SignlCondn_VehicleSpeed_Kph_f32;

extern VAR(Boolean, RTE_VAR_INIT) Rte_LrnEOT_CCWFound_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_LrnEOT_CCWPosition_HwDeg_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_LrnEOT_CWFound_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_LrnEOT_CWPosition_HwDeg_f32;

extern VAR(Boolean, RTE_VAR_INIT) Rte_LnRkCr_LTRackCntrComplete_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_LnRkCr_RackCntrMtrAngleFound_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_AbsHwPos_RevOffsetState_Cnt_u08;

extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr_ResetEventStatus(void);
extern FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32);
extern VAR(float32, RTE_VAR_NOINIT) Rte_MtrVel_HandwheelVel_HwRadpS_f32;

extern VAR(Float, RTE_VAR_INIT) Rte_TcBasedHwPos_VehCntrOffset_HwDeg_f32;

extern VAR(TurnsCntrValStateType, RTE_VAR_INIT) Rte_TurnsCounter_TurnsCntrValidity_Cnt_enum;
extern VAR(LTVehCntr_DataType, RTE_VAR_DEFAULT_RTE_ASIL_QM_PIM_GROUP) Rte_AbsHwPos_LTVehCntrComplete;
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_SrlComHwPos_HwDeg_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_AlignedHwPos_HwDeg_f32;

extern VAR(LktoLkStrStateType, RTE_VAR_INIT) Rte_LktoLkStr_LrnPnCntrState_Cnt_enum;
extern VAR(OscTrajCmdStateType, RTE_VAR_INIT) Rte_OscTraj_OscTrajState_Cnt_enum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc;

/* HwOffsetSnsrCal - Customer required that data stored be available via read diagnostic service over multiple ignition cycles */
extern VAR(float32, NVM_APPL_DATA) Rte_AbsHwPos_EOLHwOffsetSnsrCal;

/* Snapshot data externs */
extern VAR(Float, RTE_VAR_INIT) Rte_SignlCondn_VehicleSpeed_Kph_f32;
extern VAR(ST_DRV_VEH, RTE_VAR_INIT) Rte_SrlComInput_SrlComDrvVehDTPT2_Cnt_u8;
extern VAR(Float, RTE_VAR_INIT) Rte_BatteryVoltage_Vecu_Volt_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_SrlComHwPos_HwDeg_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_AssistSumnLmt_PostLimitTorque_MtrNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;
extern VAR(QU_SER_WSTA_EST_FTAX, RTE_VAR_INIT) Rte_ParkAssistEnable_PrkAssistState_Cnt_u08;
extern VAR(QU_SER_STMOM_STMOM_DV_ACT, RTE_VAR_INIT) Rte_DrvDynamicsEnable_DrvDynInterfaceState_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelAuthority_Uls_f32;


/* Added to correct anomaly 3751 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_AbsHwPos_RacktoVehCntrOffset_Cnt_u16;
/* Added to correct anomaly 3788 */
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput2_FRVldVehSpd_Kph_f32;

/* Added to correct anomaly 5033 */
extern VAR(QU_V_VEH_COG, RTE_VAR_INIT) Rte_SrlComInput2_SrlCom_QU_V_VEH_COG_Cnt_u08;

/* Added to correct anomaly EA3#2821 */
extern VAR(boolean, RTE_VAR_INIT) Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc;

#define Rte_Pim_LearnedRackCntr()   (&Rte_LnRkCr_LearnedRackCntr)

#endif

/*****************************************************************************
CHANGE HISTORY:

 Date      Rev      Author         Change Description              				SCR #
-------   -------  --------  -----------------------------------  			 ----------
01/06/10   1.0     BDO      	Initial version - add global Rte data for	   CR3759
								MotorStiffnessCheck service
01/13/10   2.0     BDO   		Add NxtrDiagMgr_ResetEventStatus for
								Nexter DTC clear service
02/11/11   3.0     BDO   		Add Rte_FinalHwPos_FinHwPosAuth_Uls_f32 
								and Rte_FinalHwPos_FinHwPos_HwDeg_f32
02/28/11   4.0     LWW   		Name change on MtrTrqCmd
03/16/11   5.0     BDO 			Add Rte_SrlComInput_SrlComVehSpd_Kph_f32		CR3898
03/26/11   6.0     BDO 			Add Rte_HwTrq_HwTrq_HwNm_f32					CR3959
03/28/11   7.0     BDO 			Add Rte_CurrentEst_EstMtrCurrQax_Amp_f32		CR3968	
03/28/11   8.0     BDO 			Add Rte_CDDInterface_MtrPosMech_Rev_f32
								and Rte_MtrPos_MtrPosMech2_Rev_f32				CR3969	
05/16/11   9.0     BDO 			Add FinalHwPos EOT global data					CR4177									
05/25/11   10.0    BDO 			Add Rte_ModeMachine_StaMd_SystemState_Mode		CR4188
06/06/11  11.0     BDO 			Add SrlComInput_SCom_ManualVehSpd				CR4188
08/11/11  12.0     BDO 			Add RackCntrComplete_Cnt_lgc and VehCntrComplete_Cnt_lgc	
10/13/11  13.0	   KJS			Added PID lookup values							CR4554		
10/29/11  14       LWW          New and removed variables
12/02/11  16       JJW          Added Rte_TcBasedHwPos_VehCntrOffset_HwDeg_f32
12/06/11  17       JJW          Renambed HwTrq to Rte_HwTrq_AnaHwTorque_HwNm_f32
12/07/11  19       JJW          Changed Vecu to Rte_BatteryVoltage_Vecu_Volt_f32
02/16/12  20       BDO			Updates to support BMW Position Control Routines AB56, AB71, AB72
06/20/12  21       BDO          Updates for anomaly 2749, FDDs 5C, 20C and SF-11 changes - CR5712, CR5685, CR5700
08/17/12  23       KJS          Updates for snapshot data						CR5931
08/18/12  24       BDO          Updates for Learn Rack Center FDD 39 and anomaly 3188
08/29/12  25       BDO          Correct defn of Rte_AbsHwPos_EOLHwOffsetSnsrCal - anomaly 3691
		  26.1.1   KJS          Added correction for anomaly 3751 and 3788
		  27       JJW          DiagMgr FDD37B_001.16 integration
10/16/12  28	   KJS			Merge of files from i350 and i390 release tags. 
10/22/12  29	   JJW			MtrPosMech moved to CDDInterface10, name updated accordingly. 
10/26/12  30       BDO          Rename vars Rte_SrlComInput2_FRVldVehSpd_Kph_f32 and Rte_SrlComInput2_SrlComVehSpd_Kph_f32 for new SrlComInput2
05/22/13  33	   KJS			Added SrlCom QU_V_VEH_COG for anomaly 5033
09/15/15  35	   ABS			Added Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc for anomaly EA3#2821
*******************************************************************************************************************************************************/
