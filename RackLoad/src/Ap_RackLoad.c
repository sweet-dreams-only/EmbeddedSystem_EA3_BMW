/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_RackLoad.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/RackLoad-nzt9hv/RackLoad/autosar
 *     SW-C Type:  Ap_RackLoad
 *  Generated at:  Sun Sep 23 15:10:37 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_RackLoad>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/07/11   1       JJW       Initial implementation
 * 02/11/11   3       JJW       Added polarity compensation calibration
 * 02/15/11   4       JJW       Corrected Rack Load calculation use of C Factor
 * 04/06/11   5       JJW       Changed to buffered port access and removal of polarity compensation
 * 10/14/11   6       NAR       Changed as per FDD SF#10
 * 10/16/11   7       JJW       Calibration and Other name corrections
 * 10/18/11   8       NAR       Calibration Datatype Fix 
 * 10/29/11   9       NAR       Anom 2641, 2644 fixed, added displayvar for AssistTrq(FunctionalTesting),added Limit on RackLoad_kN and Accel Limit value changed
 * 11/20/11   10      NAR       Updated changes as per FDD Ver001c
 * 09/23/12   11      Selva      Checkpoints added and mempmap macros corrected		                          6244
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_RackLoad.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "Interpolation.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "filters.h"
#include "Ap_RackLoad_Cfg.h"

#define   D_MTRACCELHIGHLMT_RADPS2_F32         17500.0f
#define   D_MTRACCELLOWLMT_RADPS2_F32         -17500.0f
#define   D_RACKLOADLOWLMT_KN_F32             -17.0f
#define   D_RACKLOADHIGHLMT_KN_F32            17.0f
#define   D_LEADLAGOPLLMT_HWNM_F32            -352.0f
#define   D_LEADLAGOPHLMT_HWNM_F32            352.0f

#define RACKLOAD_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) PrevDTFilterInputSV_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) PrevDTOpFilterSV_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) PrevLeadLagFilterInputSV_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) PrevLeadLagOpFilterSV_M_f32;
STATIC VAR(sint32, AP_RACKLOAD_VAR_NOINIT) DTOpMtrAccelSV_RadpS2_M_s15p16;
STATIC VAR(sint32, AP_RACKLOAD_VAR_NOINIT) RackLoadSV_kN_M_s7p24;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) DTOpMtrAccel_RadpS2_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) InertiaTrq_Nm_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) RackDmpTrq_Nm_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) RackFrictionTrq_Nm_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) RackTrq_Nm_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) MechEff_Uls_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) CRFMtrTrqCmdQuad_MtrNm_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) MotorEff_Uls_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) DTOpCRFMtrTrqCmdQuad_HwNm_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) b0_DTFilt_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) b1_DTFilt_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) a1_DTFilt_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) bo_LeadLagFilt_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) b1_LeadLagFilt_M_f32;
STATIC VAR(float32, AP_RACKLOAD_VAR_NOINIT) a1_LeadLagFilt_M_f32;
STATIC volatile VAR(float32, AP_RACKLOAD_VAR_NOINIT) AssistTrq_Nm_D_f32;

#define RACKLOAD_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

STATIC FUNC(void, AP_RACKLOAD_CODE) CalcSysEffTerms(	VAR(float32, AUTOMATIC) CRFMtrTrqCmd_MtrNm_T_f32, 
																VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32);

STATIC FUNC(float32, AP_RACKLOAD_CODE) DiscreteFilt(	VAR(float32, AUTOMATIC) FilterInput_T_f32,
															VAR(float32, AUTOMATIC) b0_T_f32, 
															VAR(float32, AUTOMATIC) b1_T_f32, 
															VAR(float32, AUTOMATIC) a1_T_f32,P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevFilterInputSVPtr_T_f32, P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevOpFilterSVPtr_T_f32 );


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Float: D_PI_ULS_F32 = 3.1415926535898
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_RACKLOAD_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RackLoad_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_RACKLOAD_APPL_CODE) RackLoad_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RackLoad_Init1
 *********************************************************************************************************************/
VAR(float32, AUTOMATIC) DenTerm_T_f32;
VAR(float32, AUTOMATIC) DenTerm2_T_f32;

DenTerm_T_f32 = ((1.0F/k_TrnsFcnFs_Hz_f32) + (2.0F/ k_TrnsFcnOmegaD_RadpS_f32));
DenTerm2_T_f32 = ((1.0F/k_TrnsFcnFs_Hz_f32) + (2.0F/ k_TrnsFcnOmegaD2_RadpS_f32));

b0_DTFilt_M_f32 = (2.0F * k_TrnsFcnTn_Uls_f32 ) / DenTerm_T_f32;
b1_DTFilt_M_f32 = -(2.0F * k_TrnsFcnTn_Uls_f32) / DenTerm_T_f32;
a1_DTFilt_M_f32=((1.0F /k_TrnsFcnFs_Hz_f32) - (2.0F /k_TrnsFcnOmegaD_RadpS_f32))/DenTerm_T_f32;

PrevDTFilterInputSV_M_f32=0.0F;
PrevDTOpFilterSV_M_f32=0.0F;
PrevLeadLagFilterInputSV_M_f32=0.0F;
PrevLeadLagOpFilterSV_M_f32=0.0F;
DTOpMtrAccelSV_RadpS2_M_s15p16=0;
RackLoadSV_kN_M_s7p24=0;

bo_LeadLagFilt_M_f32 = ((1.0F/k_TrnsFcnFs_Hz_f32) + (2.0F/k_TrnsFcnOmegaN_RadpS_f32)) / DenTerm2_T_f32;
b1_LeadLagFilt_M_f32=((1.0F/k_TrnsFcnFs_Hz_f32)-(2.0F/k_TrnsFcnOmegaN_RadpS_f32))/DenTerm2_T_f32;
a1_LeadLagFilt_M_f32=((1.0F/k_TrnsFcnFs_Hz_f32)-(2.0F/k_TrnsFcnOmegaD2_RadpS_f32))/DenTerm2_T_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RackLoad_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_RackLoad_Per1_CRFMtrTrqCmd_MtrNm_f32(void)
 *   Float Rte_IRead_RackLoad_Per1_CRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_RackLoad_Per1_HwPosAuth_Uls_f32(void)
 *   Float Rte_IRead_RackLoad_Per1_HwPos_HwDeg_f32(void)
 *   Float Rte_IRead_RackLoad_Per1_HwTrq_HwNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_RackLoad_Per1_RackLoad_kN_f32(Float data)
 *   Float *Rte_IWriteRef_RackLoad_Per1_RackLoad_kN_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_RACKLOAD_APPL_CODE) RackLoad_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RackLoad_Per1
 *********************************************************************************************************************/
VAR(float32, AUTOMATIC) HwPos_HwDeg_T_f32;
VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
VAR(float32, AUTOMATIC) CRFMtrTrqCmd_MtrNm_T_f32;
VAR(float32, AUTOMATIC) Cfactor_mmpRev_T_f32;
VAR(float32, AUTOMATIC) RackLoad_kN_T_f32;
VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32;
VAR(float32, AUTOMATIC) HwAuth_Uls_T_f32;
VAR(float32, AUTOMATIC) AssistTrq_Nm_T_f32;
VAR(uint16, AUTOMATIC) Cfactor_mmpRev_T_u10p6;

VAR(uint16, AUTOMATIC) HwPos_HwDeg_T_u10p6;
VAR(sint16, AUTOMATIC) RackLoad_kN_T_s7p8;
VAR(float32, AUTOMATIC) CurrMtrVel_MtrRadpS_T_f32;
VAR(sint16, AUTOMATIC) DTOpMtrAccel_RadpS2_T_s15P0;
VAR(sint16, AUTOMATIC) CRFMtrAccel_RadpS2_T_s15p0;
VAR(sint32, AUTOMATIC) InertiaTrq_Nm_T_s21p10;
VAR(float32, AUTOMATIC) CurrMtrVelSign_Uls_T_f32;
VAR(float32, AUTOMATIC) CRFMtrTrqCmdQuad_HwNm_T_f32;

VAR(float32, AUTOMATIC) CRFMtrAccel_RadpS2_T_f32;
VAR(float32, AUTOMATIC) LumpSysInertia_Kgm2_T_f32;

/* Configurable Start of Runnable Checkpoint */
Rte_Call_RackLoad_Per1_CP0_CheckpointReached();

HwPos_HwDeg_T_f32 = Rte_IRead_RackLoad_Per1_HwPos_HwDeg_f32();
HwTrq_HwNm_T_f32 = Rte_IRead_RackLoad_Per1_HwTrq_HwNm_f32();
CRFMtrTrqCmd_MtrNm_T_f32 = Rte_IRead_RackLoad_Per1_CRFMtrTrqCmd_MtrNm_f32();
HwAuth_Uls_T_f32=Rte_IRead_RackLoad_Per1_HwPosAuth_Uls_f32();
CRFMtrVel_MtrRadpS_T_f32=Rte_IRead_RackLoad_Per1_CRFMtrVel_MtrRadpS_f32();

HwPos_HwDeg_T_f32 = Abs_f32_m(HwPos_HwDeg_T_f32);
HwPos_HwDeg_T_u10p6 = FPM_FloatToFixed_m(HwPos_HwDeg_T_f32, u10p6_T);

CurrMtrVel_MtrRadpS_T_f32 = CRFMtrVel_MtrRadpS_T_f32;

/*DiscreteTime Filter Implementation for MtrAccel Calculation */
DTOpMtrAccel_RadpS2_M_f32 = DiscreteFilt(CurrMtrVel_MtrRadpS_T_f32,b0_DTFilt_M_f32,b1_DTFilt_M_f32,a1_DTFilt_M_f32,&PrevDTFilterInputSV_M_f32,&PrevDTOpFilterSV_M_f32);

/*LPF of MtrAccel Calc */
DTOpMtrAccel_RadpS2_M_f32 = Limit_m(DTOpMtrAccel_RadpS2_M_f32,D_MTRACCELLOWLMT_RADPS2_F32,D_MTRACCELHIGHLMT_RADPS2_F32);
DTOpMtrAccel_RadpS2_T_s15P0 = FPM_FloatToFixed_m(DTOpMtrAccel_RadpS2_M_f32,s15p0_T);
DTOpMtrAccelSV_RadpS2_M_s15p16= LPF_SvUpdate_s16InFixKTrunc_m(DTOpMtrAccel_RadpS2_T_s15P0,DTOpMtrAccelSV_RadpS2_M_s15p16,k_MtrAccelLPF_Cnt_u16);
CRFMtrAccel_RadpS2_T_s15p0 = LPF_OpUpdate_s16InFixKTrunc_m(DTOpMtrAccelSV_RadpS2_M_s15p16);

/* Apply Inertia*/
CRFMtrAccel_RadpS2_T_f32 = FPM_FixedToFloat_m(CRFMtrAccel_RadpS2_T_s15p0,s15p0_T);
LumpSysInertia_Kgm2_T_f32 = FPM_FixedToFloat_m(k_LumpSysInertia_Kgm2_u6p10,u6p10_T);
InertiaTrq_Nm_M_f32 = (CRFMtrAccel_RadpS2_T_f32 *(1.0f/ k_MtrNmtoHwNm_Uls_f32) * LumpSysInertia_Kgm2_T_f32);


/* Calculate RackDamp trq*/
RackDmpTrq_Nm_M_f32 = CurrMtrVel_MtrRadpS_T_f32 *(1.0f/ k_MtrNmtoHwNm_Uls_f32) * k_RackDamp_NmpRadpS_f32;

/* Calculate Friction Trq with deadband implemented to avoid noise*/
if((CurrMtrVel_MtrRadpS_T_f32 < k_MtrVelDband_MtrRadpS_f32) && (CurrMtrVel_MtrRadpS_T_f32 > (-1.0f * k_MtrVelDband_MtrRadpS_f32)))
{
	CurrMtrVel_MtrRadpS_T_f32 = 0.0f;
	CurrMtrVelSign_Uls_T_f32 = 0.0f;
}	
else
{
	CurrMtrVelSign_Uls_T_f32 = (float32) Sign_f32_m(CurrMtrVel_MtrRadpS_T_f32);
}
RackFrictionTrq_Nm_M_f32 = CurrMtrVelSign_Uls_T_f32 * k_RackFriction_HwNm_f32;

/*Calc Efficiency Terms*/
CalcSysEffTerms(CRFMtrTrqCmd_MtrNm_T_f32, CRFMtrVel_MtrRadpS_T_f32);
CRFMtrTrqCmdQuad_HwNm_T_f32 =CRFMtrTrqCmdQuad_MtrNm_M_f32 * k_MtrNmtoHwNm_Uls_f32;
DTOpCRFMtrTrqCmdQuad_HwNm_M_f32 =DiscreteFilt(CRFMtrTrqCmdQuad_HwNm_T_f32, bo_LeadLagFilt_M_f32,b1_LeadLagFilt_M_f32,a1_LeadLagFilt_M_f32,&PrevLeadLagFilterInputSV_M_f32,&PrevLeadLagOpFilterSV_M_f32);
DTOpCRFMtrTrqCmdQuad_HwNm_M_f32 = Limit_m(DTOpCRFMtrTrqCmdQuad_HwNm_M_f32,D_LEADLAGOPLLMT_HWNM_F32,D_LEADLAGOPHLMT_HWNM_F32);
AssistTrq_Nm_T_f32 = DTOpCRFMtrTrqCmdQuad_HwNm_M_f32 * MotorEff_Uls_M_f32;
AssistTrq_Nm_D_f32 = AssistTrq_Nm_T_f32;

RackTrq_Nm_M_f32 = (AssistTrq_Nm_T_f32 + HwTrq_HwNm_T_f32) -(RackFrictionTrq_Nm_M_f32 + RackDmpTrq_Nm_M_f32 + InertiaTrq_Nm_M_f32);

if(HwAuth_Uls_T_f32 >= 1)
{
		
	Cfactor_mmpRev_T_u10p6 = IntplVarXY_u16_u16Xu16Y_Cnt( 
                                       t_CfactorTblX_HwDeg_u10p6,
                                       t_CfactorTblY_MmpRev_u10p6,
                                       TableSize_m(t_CfactorTblX_HwDeg_u10p6),
                                       HwPos_HwDeg_T_u10p6);

	Cfactor_mmpRev_T_f32 = FPM_FixedToFloat_m(Cfactor_mmpRev_T_u10p6, u10p6_T);
	RackLoad_kN_T_f32 = (RackTrq_Nm_M_f32 *2.0f * D_PI_ULS_F32) /Cfactor_mmpRev_T_f32;
	RackLoad_kN_T_f32 = RackLoad_kN_T_f32 * MechEff_Uls_M_f32;
	RackLoad_kN_T_f32 = Limit_m(RackLoad_kN_T_f32, D_RACKLOADLOWLMT_KN_F32, D_RACKLOADHIGHLMT_KN_F32);
	RackLoad_kN_T_s7p8 = FPM_FloatToFixed_m(RackLoad_kN_T_f32,s7p8_T);
	RackLoadSV_kN_M_s7p24 = LPF_SvUpdate_s16InFixKTrunc_m(RackLoad_kN_T_s7p8,RackLoadSV_kN_M_s7p24,k_RackLoadLPF_Cnt_u16);
	RackLoad_kN_T_s7p8 = LPF_OpUpdate_s16InFixKTrunc_m(RackLoadSV_kN_M_s7p24);
	RackLoad_kN_T_f32 = FPM_FixedToFloat_m(RackLoad_kN_T_s7p8,s7p8_T);
}
else
{
	RackLoad_kN_T_f32 = 0.0F;
}

/* Update Outputs */
Rte_IWrite_RackLoad_Per1_RackLoad_kN_f32(RackLoad_kN_T_f32);
/* TODO: Implement a legitimate status determination when an appropriate architecture is in place */

/* Configurable End of Runnable Checkpoint */
 Rte_Call_RackLoad_Per1_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_RACKLOAD_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define RTE_START_SEC_AP_RACKLOAD_APPL_CODE
#include "MemMap.h"
STATIC FUNC(void, AP_RACKLOAD_CODE) CalcSysEffTerms(	VAR(float32, AUTOMATIC) CRFMtrTrqCmd_MtrNm_T_f32, 
																VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32)
{
	VAR(float32, AUTOMATIC) Power_MtrNmRadpS_T_f32;
	
	CRFMtrTrqCmdQuad_MtrNm_M_f32 = CRFMtrTrqCmd_MtrNm_T_f32* (float32)k_TrqPolGain_Uls_s8;
	Power_MtrNmRadpS_T_f32 =CRFMtrTrqCmdQuad_MtrNm_M_f32 * CRFMtrVel_MtrRadpS_T_f32;

	if(Sign_f32_m(Power_MtrNmRadpS_T_f32) >=0) 
	{
		MotorEff_Uls_M_f32 = k_MotorEffQ1_Uls_f32;
		MechEff_Uls_M_f32 = k_MechEffQ1_Uls_f32;
	}
	else
	{
		MotorEff_Uls_M_f32 = k_MotorEffQ2_Uls_f32;
		MechEff_Uls_M_f32 = k_MechEffQ2_Uls_f32;
	}
}

STATIC FUNC(float32, AP_RACKLOAD_CODE) DiscreteFilt(VAR(float32, AUTOMATIC) FilterInput_T_f32,
															VAR(float32, AUTOMATIC) b0_T_f32, 
															VAR(float32, AUTOMATIC) b1_T_f32, 
															VAR(float32, AUTOMATIC) a1_T_f32,P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevFilterInputSVPtr_T_f32, P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevOpFilterSVPtr_T_f32)
{
	VAR(float32, AUTOMATIC) CurrFilterInput_T_f32;
	VAR(float32, AUTOMATIC) Temp_T_f32;
	VAR(float32, AUTOMATIC) CurrOpFilter_T_f32;
	VAR(float32, AUTOMATIC) FilterOutput_T_f32;
	VAR(float32, AUTOMATIC) PrevFilterInput_T_f32;

	CurrFilterInput_T_f32 = FilterInput_T_f32 * b0_T_f32;
	PrevFilterInput_T_f32 = *PrevFilterInputSVPtr_T_f32 * b1_T_f32;
	*PrevOpFilterSVPtr_T_f32 = *PrevOpFilterSVPtr_T_f32 * a1_T_f32;
	Temp_T_f32 = PrevFilterInput_T_f32 - *PrevOpFilterSVPtr_T_f32;
	CurrOpFilter_T_f32 = CurrFilterInput_T_f32 +Temp_T_f32;

	/*Current calculated o/p is used for next calculation by assigning to prevo/p*/
	*PrevOpFilterSVPtr_T_f32 = CurrOpFilter_T_f32;
	*PrevFilterInputSVPtr_T_f32 = FilterInput_T_f32;

	FilterOutput_T_f32 =CurrOpFilter_T_f32;

	return(FilterOutput_T_f32);

}
#define RTE_STOP_SEC_AP_RACKLOAD_APPL_CODE
#include "MemMap.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
