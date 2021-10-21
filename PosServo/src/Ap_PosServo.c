/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PosServo.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/PosServo-nzt9hv/PosServo/autosar
 *     SW-C Type:  Ap_PosServo
 *  Generated at:  Sat Sep 22 10:52:04 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PosServo>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue May 31 22:40:44 2011
 * %version:          12 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Wed Mar 20 16:48:33 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/01/11   1       JJW       Initial CBD SWC template														4721
 * 06/06/11   2       VK        Implemented FDD SF20 rev001														4721
 * 01/09/12	  3       VK        Changed VehSpd_T_u12p4 to u9p7 and changed the precision for the 
 *								table associated. 
 * 02/02/12   4       VK        Updated the memory segments for local functions and module level variables		4271
 * 08/01/12   5       OT        Updated to SF-20 v002                                                           5906
 * 08/08/12   6       OT        Fix UTP issue (typecasting overflow)                                            5906
 * 08/10/12   7       OT        Fixed another UTP issue (signed math overflow)                                  5906
 * 08/29/12	  8		  KJS		Updated to SF-20 v003															6116
 * 09/21/12   9       Selva     Checkpoints added and mempmap macros corrected		                            6240
 * 03/15/13	  10	  SP		Updated to FDD V004																7618
 * 03/15/13   11      SP		Fixed Anomaly 4651																7634
 * 03/20/13	  12	  KJS		Corrected anomaly 4681															7686
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_PosServo.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_PosServo_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "SystemTime.h"
#include "filters.h"
#include "fixmath.h"
#include "interpolation.h"

/* Embedded COnstants */

#define D_CONVERT_MSPLOOP_F32		2.0f

#define D_PRKASTLOOPRATE_SEC_F32	0.002f
#define D_RECEXECRATE_PSEC_U21P11	FPM_InitFixedPoint_m(500.0, u21p11_T)

#define D_POSSERVOMINRAMP_ULS_F32		0.0f
#define D_POSSERVOMAXRAMP_ULS_F32		1.0f

#define D_RAMPCOMPLETE_ULS_U6P10	FPM_InitFixedPoint_m(0.0, u6p10_T)

#define D_DTERMMIN_MTRNM_F32		(-255.0f)
#define D_DTERMMAX_MTRNM_F32		255.0f

/* Module level variables */
#define POSSERVO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(LPF32KSV_Str, AUTOMATIC) FiltHwPosKSV_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) FiltHwTrqKSV_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) DTermKSV_M_str;
#define POSSERVO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define POSSERVO_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(boolean, AUTOMATIC) PosSrvoRampComplete_Cnt_D_lgc;
#define POSSERVO_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define POSSERVO_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) PrkAstRampSV_Uls_M_f32;
STATIC VAR(sint32, AUTOMATIC) ITermSV_HwDeg_M_s27p4;
STATIC volatile VAR(float32, AUTOMATIC) PosSrvoHWATargFilt_HwDeg_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) PosSrvoPIDCmd_MtrNm_D_f32;
STATIC volatile VAR(sint32, AUTOMATIC) PosServo_PTerm_MtrNm_D_s24p7;
STATIC VAR(float32, AUTOMATIC) PrevLimitedHwPos_HwDeg_M_f32;
#define POSSERVO_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define POSSERVO_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint16, AUTOMATIC) PrevCmdError_HwDeg_M_s11p4;
STATIC volatile VAR(sint16, AUTOMATIC) PosServo_ITerm_MtrNm_D_s8p7;
STATIC volatile VAR(sint16, AUTOMATIC) PosServo_DTerm_MtrNm_D_s8p7;
#define POSSERVO_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
/* Function Prototypes */

STATIC FUNC(float32, AP_POSSERVO_CODE) FilterDesiredAngle(CONST(boolean,AUTOMATIC) Active_T_lgc,
														  CONST(boolean,AUTOMATIC) RampComplete_T_lgc,
														  VAR(float32,AUTOMATIC) HwPos_T_f32);

STATIC FUNC(void, AP_POSSERVO_CODE) TransitionControl(CONST(boolean,AUTOMATIC) Active_T_lgc,
												      P2VAR(float32,AUTOMATIC,AUTOMATIC) pSmoothEnable_T_f32,
													  P2VAR(float32,AUTOMATIC,AUTOMATIC) pReturnScl_T_f32,
													  P2VAR(boolean,AUTOMATIC,AUTOMATIC) pRampComplete_T_lgc);

STATIC FUNC(float32, AP_POSSERVO_CODE) PIDControl(CONST(boolean,AUTOMATIC) Active_T_lgc,
												  CONST(boolean,AUTOMATIC) RampComplete_T_lgc,
												  CONST(float32,AUTOMATIC) HwPos_T_f32,
												  CONST(float32,AUTOMATIC) DesiredHwAngle_T_f32,
												  CONST(uint16, AUTOMATIC) VehSpd_T_u9p7);
													 
STATIC FUNC(float32, AP_POSSERVO_CODE) OutputTorque(VAR(float32, AUTOMATIC) PrkAstCmd_T_f32,
													CONST(float32, AUTOMATIC) SmoothEnable_T_f32,
													CONST(uint16, AUTOMATIC) VehSpd_T_u9p7);

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
 * Boolean: Boolean (standard type)
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
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_POSSERVO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PosServo_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_POSSERVO_APPL_CODE) PosServo_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PosServo_Init1
 *********************************************************************************************************************/
	
	
	LPF_KUpdate_f32_m(k_PrkAstHwaLPFKn_Hz_f32, D_2MS_SEC_F32, &FiltHwPosKSV_M_str);
	LPF_KUpdate_f32_m(k_PrkAstHwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &FiltHwTrqKSV_M_str);
	LPF_KUpdate_f32_m(k_PrkAstDTermKn_Hz_f32, D_2MS_SEC_F32, &DTermKSV_M_str);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PosServo_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_PosServo_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_PosServo_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PosServo_Per1_MotorVelCRF_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_PosServo_Per1_PosSrvoEnable_Cnt_lgc(void)
 *   Float Rte_IRead_PosServo_Per1_PosSrvoHwAngle_HwDeg_f32(void)
 *   Float Rte_IRead_PosServo_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PosServo_Per1_PosSrvoCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PosServo_Per1_PosSrvoCmd_MtrNm_f32(void)
 *   void Rte_IWrite_PosServo_Per1_PosSrvoReturnSclFct_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PosServo_Per1_PosSrvoReturnSclFct_Uls_f32(void)
 *   void Rte_IWrite_PosServo_Per1_PosSrvoSmoothEnable_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_PosServo_Per1_PosSrvoSmoothEnable_Uls_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_POSSERVO_APPL_CODE) PosServo_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PosServo_Per1
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) Active_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) TrgtAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) SmoothEnable_Uls_T_f32;
	VAR(float32, AUTOMATIC) ReturnScale_Uls_T_f32;
	VAR(boolean, AUTOMATIC) RampComplete_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HwPos_HwDeg_T_f32;

	/* Rate Limiter Variables */
	VAR(uint16, AUTOMATIC) HwPosRateLimit_HwDegpSec_T_u12p4;
	VAR(float32, AUTOMATIC) HwPosLimit_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) LimitedHwPos_HwDeg_T_f32;

	VAR(float32, AUTOMATIC) PrkAstCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u9p7;
	VAR(float32, AUTOMATIC) PosSrvoCmd_MtrNm_T_f32;
	VAR(float32,AUTOMATIC) TrgtHwAngle_HwDeg_T_f32;

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_PosServo_Per1_CP0_CheckpointReached();

	/* capture inputs */
	HwPos_HwDeg_T_f32 = Rte_IRead_PosServo_Per1_HandwheelPosition_HwDeg_f32(); /* HWA */
	VehSpd_Kph_T_f32 = Rte_IRead_PosServo_Per1_VehicleSpeed_Kph_f32();
	VehSpd_Kph_T_u9p7 = FPM_FloatToFixed_m(VehSpd_Kph_T_f32, u9p7_T);
	Active_Cnt_T_lgc = Rte_IRead_PosServo_Per1_PosSrvoEnable_Cnt_lgc(); /* bActive */
	TrgtHwAngle_HwDeg_T_f32 = Rte_IRead_PosServo_Per1_PosSrvoHwAngle_HwDeg_f32();	/* HWA_Target */

	/* handle sub-functions */
	TransitionControl(Active_Cnt_T_lgc, &SmoothEnable_Uls_T_f32, &ReturnScale_Uls_T_f32, &RampComplete_Cnt_T_lgc);


	/* Rate limiter */
	HwPosRateLimit_HwDegpSec_T_u12p4 = IntplVarXY_u16_u16Xu16Y_Cnt( t_PrkAstVehSpdBS_Kph_u9p7,
																	t_HwaRateLimit_HwDegpSec_u12p4,
																	TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
																	VehSpd_Kph_T_u9p7);

	HwPosLimit_HwDeg_T_f32 = FPM_FixedToFloat_m(HwPosRateLimit_HwDegpSec_T_u12p4, u12p4_T) * D_2MS_SEC_F32; /* Rate limited VehSpd_Kpd */
	if( Active_Cnt_T_lgc == TRUE)
	{
		LimitedHwPos_HwDeg_T_f32 = Limit_m(TrgtHwAngle_HwDeg_T_f32, (PrevLimitedHwPos_HwDeg_M_f32 - HwPosLimit_HwDeg_T_f32), (PrevLimitedHwPos_HwDeg_M_f32 + HwPosLimit_HwDeg_T_f32));
	}
	else
	{
		LimitedHwPos_HwDeg_T_f32 = Limit_m(HwPos_HwDeg_T_f32, (PrevLimitedHwPos_HwDeg_M_f32 - HwPosLimit_HwDeg_T_f32), (PrevLimitedHwPos_HwDeg_M_f32 + HwPosLimit_HwDeg_T_f32));
	}
	PrevLimitedHwPos_HwDeg_M_f32 = LimitedHwPos_HwDeg_T_f32; /* Update for next run */

	TrgtAngle_HwDeg_T_f32 = FilterDesiredAngle(Active_Cnt_T_lgc, RampComplete_Cnt_T_lgc, LimitedHwPos_HwDeg_T_f32);
	PrkAstCmd_MtrNm_T_f32 = PIDControl(Active_Cnt_T_lgc, RampComplete_Cnt_T_lgc, HwPos_HwDeg_T_f32,
									   TrgtAngle_HwDeg_T_f32, VehSpd_Kph_T_u9p7);
	PosSrvoCmd_MtrNm_T_f32 = OutputTorque(PrkAstCmd_MtrNm_T_f32, SmoothEnable_Uls_T_f32, VehSpd_Kph_T_u9p7);
	
	/* update outputs */
	PosSrvoRampComplete_Cnt_D_lgc = RampComplete_Cnt_T_lgc;
	PosSrvoHWATargFilt_HwDeg_D_f32 = TrgtAngle_HwDeg_T_f32;
	PosSrvoPIDCmd_MtrNm_D_f32 = PrkAstCmd_MtrNm_T_f32;
	Rte_IWrite_PosServo_Per1_PosSrvoCmd_MtrNm_f32(PosSrvoCmd_MtrNm_T_f32);
	Rte_IWrite_PosServo_Per1_PosSrvoReturnSclFct_Uls_f32(ReturnScale_Uls_T_f32);
	Rte_IWrite_PosServo_Per1_PosSrvoSmoothEnable_Uls_f32(SmoothEnable_Uls_T_f32);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_PosServo_Per1_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_POSSERVO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define RTE_START_SEC_AP_POSSERVO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/* Local Functions */

STATIC FUNC(float32, AP_POSSERVO_CODE) FilterDesiredAngle(CONST(boolean,AUTOMATIC) Active_T_lgc,
														  CONST(boolean,AUTOMATIC) RampComplete_T_lgc,
														  VAR(float32,AUTOMATIC) HwPos_T_f32)
{
	VAR(float32,AUTOMATIC) HwaPos_T_f32;
	
	if( (FALSE == Active_T_lgc) && (FALSE == RampComplete_T_lgc) )
	{ /* latch current value */ }

	/* determine whether to reset target angle */
	else if( (FALSE == Active_T_lgc) && (TRUE == RampComplete_T_lgc) )
	{
		HwaPos_T_f32 = Rte_IRead_PosServo_Per1_HandwheelPosition_HwDeg_f32(); /* HWA */
		/* reset target and state variable */
		FiltHwPosKSV_M_str.SV_Uls_f32 = HwaPos_T_f32;
	}
	else
	{		
		/* apply filter */
		LPF_OpUpdate_f32_m(HwPos_T_f32, &FiltHwPosKSV_M_str);
	}
	
	return FiltHwPosKSV_M_str.SV_Uls_f32;
}

/* End of FilterDesiredAngle local function */

STATIC FUNC(void, AP_POSSERVO_CODE) TransitionControl(CONST(boolean,AUTOMATIC) Active_T_lgc,
														 P2VAR(float32,AUTOMATIC,AUTOMATIC) pSmoothEnable_T_f32,
														 P2VAR(float32,AUTOMATIC,AUTOMATIC) pReturnScl_T_f32,
														 P2VAR(boolean,AUTOMATIC,AUTOMATIC) pRampComplete_T_lgc)
{
	VAR(float32, AUTOMATIC) PrkAstRampSV_Uls_T_f32;
	VAR(uint16, AUTOMATIC) Rate_pSec_T_u12p4;
	VAR(uint16, AUTOMATIC) Slew_Uls_T_u6p10;
	VAR(float32, AUTOMATIC) SmoothStep_Uls_T_f32;
	VAR(uint16, AUTOMATIC) SmoothEnable_Uls_T_u6p10;
	VAR(float32, AUTOMATIC) EnableStep_Uls_T_f32;
	
	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HwTrqFilt_HwNm_T_f32;
	VAR(uint16, AUTOMATIC) AbsHwTrqFilt_HwNm_T_u11p5;
	
	/* capture inputs */
	PrkAstRampSV_Uls_T_f32 = PrkAstRampSV_Uls_M_f32;
	HwTrq_HwNm_T_f32 = Rte_IRead_PosServo_Per1_HwTorque_HwNm_f32();
	
	/* filter handwheel torque */
	HwTrqFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTrq_HwNm_T_f32, &FiltHwTrqKSV_M_str);
	AbsHwTrqFilt_HwNm_T_u11p5 = FPM_FloatToFixed_m(Abs_f32_m(HwTrqFilt_HwNm_T_f32), u11p5_T);
	
	
	/* update ramp state variable */
	if(TRUE == Active_T_lgc)
	{
		EnableStep_Uls_T_f32 = k_PrkAstEnableRate_pSec_f32 * D_PRKASTLOOPRATE_SEC_F32;
		PrkAstRampSV_Uls_T_f32 += EnableStep_Uls_T_f32;
	}
	else
	{
		Rate_pSec_T_u12p4 = IntplVarXY_u16_u16Xu16Y_Cnt( t_PrkAstDisableRateX_HwNm_u11p5,
				                                         t_PrkAstDisableRateY_pSec_u12p4,
				                                         TableSize_m(t_PrkAstDisableRateX_HwNm_u11p5),
				                                         AbsHwTrqFilt_HwNm_T_u11p5 );
				                                         
		SmoothStep_Uls_T_f32 = FPM_FixedToFloat_m(Rate_pSec_T_u12p4, u12p4_T) * D_PRKASTLOOPRATE_SEC_F32;
		PrkAstRampSV_Uls_T_f32 -= SmoothStep_Uls_T_f32;
	}
	
	PrkAstRampSV_Uls_T_f32 = Limit_m(PrkAstRampSV_Uls_T_f32, D_POSSERVOMINRAMP_ULS_F32, D_POSSERVOMAXRAMP_ULS_F32);
	
	/* determine the smooth enable */
	Slew_Uls_T_u6p10 = FPM_FloatToFixed_m(PrkAstRampSV_Uls_T_f32, u6p10_T);
	SmoothEnable_Uls_T_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PrkAstSmoothX_Uls_u6p10,
                                                           t_PrkAstSmoothY_Uls_u6p10,
                                                           TableSize_m(t_PrkAstSmoothX_Uls_u6p10),
                                                           Slew_Uls_T_u6p10);
	
	/* update outputs */
	if(D_RAMPCOMPLETE_ULS_U6P10 == SmoothEnable_Uls_T_u6p10)
	{ (*pRampComplete_T_lgc) = TRUE; }
	else
	{ (*pRampComplete_T_lgc) = FALSE; }
	
	(*pSmoothEnable_T_f32) = FPM_FixedToFloat_m(SmoothEnable_Uls_T_u6p10, u6p10_T);
	(*pReturnScl_T_f32) = D_POSSERVOMAXRAMP_ULS_F32 - (*pSmoothEnable_T_f32);
	
	PrkAstRampSV_Uls_M_f32 = PrkAstRampSV_Uls_T_f32;
}

/* End of TransitionControl local function */

STATIC FUNC(float32, AP_POSSERVO_CODE) PIDControl(CONST(boolean,AUTOMATIC) Active_T_lgc,
												  CONST(boolean,AUTOMATIC) RampComplete_T_lgc,
												  CONST(float32,AUTOMATIC) HwPos_T_f32,
												  CONST(float32,AUTOMATIC) DesiredHwAngle_T_f32,
												  CONST(uint16, AUTOMATIC) VehSpd_T_u9p7)
{
	VAR(sint32, AUTOMATIC) PTerm_MtrNm_T_s24p7;
	VAR(float32, AUTOMATIC) ITerm_MtrNm_T_f32;
	VAR(sint16, AUTOMATIC) ITerm_MtrNm_T_s8p7;
	VAR(sint16, AUTOMATIC) DTerm_MtrNm_T_s8p7;
	VAR(float32, AUTOMATIC) DTerm_MtrNm_T_f32;
	VAR(sint32, AUTOMATIC) PIDSum_MtrNm_T_s24p7;
	VAR(float32, AUTOMATIC) Error_HwDeg_T_f32;
	VAR(sint16, AUTOMATIC) Error_HwDeg_T_s11p4;
	
	
	VAR(uint16, AUTOMATIC) ITermAWLmt_MtrNm_T_u9p7;
	VAR(sint32, AUTOMATIC) ITermAWLmt_HwDeg_T_s27p4;
	VAR(sint32, AUTOMATIC) ITermSV_HwDeg_T_s27p4;
	VAR(uint16, AUTOMATIC) ITermGain_MtrNmpHwDegS_T_u2p14;
	
	VAR(float32, AUTOMATIC) DTermRate_HwDegpLoop_T_f32;
	VAR(uint16, AUTOMATIC) DTermGain_MtrNmmSpHwDeg_T_u7p9;
	
	VAR(sint16, AUTOMATIC) PrevError_HwDeg_T_s11p4;
	VAR(float32, AUTOMATIC) TmpPrkAssist_MtrNm_T_f32;
	
	/* check for PID reset condition */
	if((FALSE == Active_T_lgc) && (TRUE == RampComplete_T_lgc))
	{
		Error_HwDeg_T_s11p4 = 0;
		ITermSV_HwDeg_T_s27p4 = 0L;
		DTermKSV_M_str.SV_Uls_f32 = 0.0F;
		TmpPrkAssist_MtrNm_T_f32 = 0.0F;
	}
	else /* calculate output */
	{
		/* capture inputs and compute handwheel angle error */
		ITermSV_HwDeg_T_s27p4 = ITermSV_HwDeg_M_s27p4;
		PrevError_HwDeg_T_s11p4 = PrevCmdError_HwDeg_M_s11p4;
		Error_HwDeg_T_f32 = DesiredHwAngle_T_f32 - HwPos_T_f32;
		
		/* perform fixed point conversions */
		Error_HwDeg_T_s11p4 = FPM_FloatToFixed_m(Error_HwDeg_T_f32, s11p4_T);
		
		
		/* calculate P-term */
		PTerm_MtrNm_T_s24p7 = (sint32)BilinearXYM_u16_u16Xu16YM_Cnt( VehSpd_T_u9p7,
																	Abs_s16_m(Error_HwDeg_T_s11p4),
																	t_PrkAstVehSpdBS_Kph_u9p7,
																	TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
																	t_PrkAstPGainX_HwDeg_u12p4,
																	(P2CONST(uint16, AUTOMATIC, AP_POSSERVO_CONST))t2_PrkAstPGainY_MtrNm_u9p7,
																	TableSize_m(t_PrkAstPGainX_HwDeg_u12p4));
		PTerm_MtrNm_T_s24p7 = PTerm_MtrNm_T_s24p7 * (sint32)Sign_s16_m(Error_HwDeg_T_s11p4);
		
		
		/* calculate I-term */
		ITermAWLmt_MtrNm_T_u9p7 = IntplVarXY_u16_u16Xu16Y_Cnt( t_PrkAstVehSpdBS_Kph_u9p7,
															   t_PrkAstITermAWLmtY_MtrNm_u9p7,
															   TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
															   VehSpd_T_u9p7 );
		
		ITermGain_MtrNmpHwDegS_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt( t_PrkAstVehSpdBS_Kph_u9p7,
															   		  t_PrkAstIGainY_MtrNmpHwDegS_u2p14,
															   		  TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
																	  VehSpd_T_u9p7 );
		
		if(0U == ITermGain_MtrNmpHwDegS_T_u2p14)
		{
			ITermAWLmt_HwDeg_T_s27p4 = 0l;
		}
		else
		{
			ITermAWLmt_HwDeg_T_s27p4 = (((sint32)ITermAWLmt_MtrNm_T_u9p7 * (sint32) D_RECEXECRATE_PSEC_U21P11) / 
										(sint32)ITermGain_MtrNmpHwDegS_T_u2p14);
		}
		
		ITermSV_HwDeg_T_s27p4 += (sint32)Error_HwDeg_T_s11p4;
		ITermSV_HwDeg_T_s27p4 = Limit_m(ITermSV_HwDeg_T_s27p4, -ITermAWLmt_HwDeg_T_s27p4, ITermAWLmt_HwDeg_T_s27p4);
		
		ITerm_MtrNm_T_f32 = FPM_FixedToFloat_m(ITermSV_HwDeg_T_s27p4, s27p4_T) *
							FPM_FixedToFloat_m(ITermGain_MtrNmpHwDegS_T_u2p14, u2p14_T) *
							D_PRKASTLOOPRATE_SEC_F32;
		
		ITerm_MtrNm_T_s8p7 = FPM_FloatToFixed_m(ITerm_MtrNm_T_f32, s8p7_T);
		
		
		/* calculate D-term */
		DTermRate_HwDegpLoop_T_f32 = FPM_FixedToFloat_m(Error_HwDeg_T_s11p4, s11p4_T) -
									 FPM_FixedToFloat_m(PrevError_HwDeg_T_s11p4, s11p4_T);
		
		DTermGain_MtrNmmSpHwDeg_T_u7p9 = IntplVarXY_u16_u16Xu16Y_Cnt( t_PrkAstVehSpdBS_Kph_u9p7,
															   		  t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9,
															   		  TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
																	  VehSpd_T_u9p7 );
		
		DTerm_MtrNm_T_f32 = (DTermRate_HwDegpLoop_T_f32 * FPM_FixedToFloat_m(DTermGain_MtrNmmSpHwDeg_T_u7p9, u7p9_T)) / D_CONVERT_MSPLOOP_F32;
								
		DTerm_MtrNm_T_f32 = Limit_m(DTerm_MtrNm_T_f32, D_DTERMMIN_MTRNM_F32, D_DTERMMAX_MTRNM_F32);
		
		DTerm_MtrNm_T_f32 = LPF_OpUpdate_f32_m(DTerm_MtrNm_T_f32, &DTermKSV_M_str);
		DTerm_MtrNm_T_s8p7 = FPM_FloatToFixed_m(DTerm_MtrNm_T_f32, s8p7_T);
		
		/* Update display variables */
		PosServo_PTerm_MtrNm_D_s24p7 = PTerm_MtrNm_T_s24p7;
		PosServo_ITerm_MtrNm_D_s8p7 = ITerm_MtrNm_T_s8p7;
		PosServo_DTerm_MtrNm_D_s8p7 = DTerm_MtrNm_T_s8p7;
		
		/* compute and limit the sum */
		PIDSum_MtrNm_T_s24p7 = PTerm_MtrNm_T_s24p7+(sint32)ITerm_MtrNm_T_s8p7+(sint32)DTerm_MtrNm_T_s8p7;
		PIDSum_MtrNm_T_s24p7 = Limit_m(PIDSum_MtrNm_T_s24p7, -(sint32)k_PrkAstPIDLimit_MtrNm_u9p7, (sint32)k_PrkAstPIDLimit_MtrNm_u9p7);
		
		TmpPrkAssist_MtrNm_T_f32 = FPM_FixedToFloat_m(PIDSum_MtrNm_T_s24p7, s24p7_T);
	}
	
	/* update module level variables and return result */
	ITermSV_HwDeg_M_s27p4 = ITermSV_HwDeg_T_s27p4;
	PrevCmdError_HwDeg_M_s11p4 = Error_HwDeg_T_s11p4;
	
	return TmpPrkAssist_MtrNm_T_f32;
}

/* End of PIDControl local function */

STATIC FUNC(float32, AP_POSSERVO_CODE) OutputTorque( VAR(float32, AUTOMATIC) PrkAstCmd_T_f32,
													    CONST(float32, AUTOMATIC) SmoothEnable_T_f32,
													    CONST(uint16, AUTOMATIC) VehSpd_T_u9p7 )
{
	VAR(uint16, AUTOMATIC) DmpGain_MtrNmpRadpS_T_u3p13;
	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) DmpTerm_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PrkAstCmd_MtrNm_T_f32;
	VAR(uint16, AUTOMATIC) OutputLimit_MtrNm_T_u5p11;
	VAR(float32, AUTOMATIC) OutputLimit_MtrNm_T_f32;
	
	/* capture inputs */
	MtrVel_MtrRadpS_T_f32 = Rte_IRead_PosServo_Per1_MotorVelCRF_MtrRadpS_f32();
	
	/* determine damping term */
	DmpGain_MtrNmpRadpS_T_u3p13 = IntplVarXY_u16_u16Xu16Y_Cnt( t_PrkAstVehSpdBS_Kph_u9p7,
															   t_PrkAstDmpGainY_MtrNmpRadpS_u3p13,
															   TableSize_m(t_PrkAstVehSpdBS_Kph_u9p7),
															   VehSpd_T_u9p7 );
	
	/* determine output limit */
	OutputLimit_MtrNm_T_u5p11 = IntplVarXY_u16_u16Xu16Y_Cnt( t_PosSrvoMaxCmdX_Kph_u9p7,
															 t_PosSrvoMaxCmdY_MtrNm_u5p11,
															 TableSize_m(t_PosSrvoMaxCmdX_Kph_u9p7),
															 VehSpd_T_u9p7 );
	
	OutputLimit_MtrNm_T_f32 = FPM_FixedToFloat_m(OutputLimit_MtrNm_T_u5p11, u5p11_T);
	
	/* determine final command and return */														   
	DmpTerm_MtrNm_T_f32 = FPM_FixedToFloat_m(DmpGain_MtrNmpRadpS_T_u3p13, u3p13_T) * MtrVel_MtrRadpS_T_f32;
	PrkAstCmd_MtrNm_T_f32 = (PrkAstCmd_T_f32 - DmpTerm_MtrNm_T_f32) * SmoothEnable_T_f32;
	
	PrkAstCmd_MtrNm_T_f32 = Limit_m(PrkAstCmd_MtrNm_T_f32, -OutputLimit_MtrNm_T_f32, OutputLimit_MtrNm_T_f32);
	
	return PrkAstCmd_MtrNm_T_f32;
}

/* End of OutputTorque local function */
#define RTE_STOP_SEC_AP_POSSERVO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
