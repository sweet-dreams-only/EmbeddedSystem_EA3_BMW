/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TrqOsc.c
 *     Workspace:  C:/Sankar/New_EA3_Database/Working/TrqOsc/autosar
 *     SW-C Type:  Ap_TrqOsc
 *  Generated at:  Mon Apr 11 11:00:38 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TrqOsc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /*****************************************************************************
* Copyright 2016 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_TrqOsc.c
* Module Description: Torque Oscillation
* Product           : Gen II Plus - EA3.0
* Author            : Lovepreet Kaur
*****************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 25 14:55:10 2014
 * %version:          EA3#4 %
 * %derived_by:       pznywf %
 * %date_modified:    Fri Dec 13 14:08:05 2013 %
 *------------------------------------------------------------------------------------------------------------------
 * Date        Rev      Author  Change Description                                                           SCR #
 * --------  -------  --------  ------------------------------------------------------------------------  ----------
 * 03/26/14  	1        LK		Initial Version (SF 43 v001)                                                11572
 * 11/23/2015	2		 KK		Modified Ap_TrqOsc to include ramping (as per SF043A FDD v2.0)				EA3#4725
 * 02/01/2016	3		 KK		Holding the values calculated in 'Update Variables' to the next periodic	EA3#5881
 * 04/11/2016   4        SV     Fault injection client call name corrected                                  EA3#7449
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_TrqOsc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 4395 EOF
* MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* MISRA-C: 2004 Rule 8.7: Deviation needed to keep the memory map intact. */

/* MISRA-C: 2004 Rule 19.1: Required for AutoSAR compliance so deviation is taken. */

/* PRQA S 3332 EOF
* MISRA-C: 2004 Rule 19.11: This deviation is required for for all Fault Injection points - Build Time config. The rule is suppressed for the entire file */


#include "CalConstants.h"
#include "fixmath.h"
#include "filters.h"
#include "Ap_TrqOsc_Cfg.h"
/*Constants*/
#define D_PRMNTMAXFRQ_HZ_U12P4 			(FPM_InitFixedPoint_m(50.0F,u12p4_T)) 	/* Max Freq*/
#define D_PRMNTMINFRQ_HZ_U12P4 			(FPM_InitFixedPoint_m(10.0F,u12p4_T)) 	/* Min Freq*/
#define	D_MAXAMP_MOTNWTMTR_F32 			(1.2F)
#define	D_MINAMP_MOTNWTMTR_F32 			(0.0F)
#define	D_MAXDC_MOTNWTMTR_F32 			(0.1F)
#define	D_DCTRENDLPFILFRQ_HZ_F32 		(0.32F)
#define	D_MAXRAMPRATE_MOTNWTMTR_F32 	(4400.0F)
#define	D_MINRAMPRATE_MOTNWTMTR_F32 	(0.1F)


#define TRQOSC_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) 			TrqOsc_EnablePrev_Cnt_M_lgc;  					/* PRQA S 3218 */		/* To check for rising edge */						
STATIC VAR(boolean, AUTOMATIC) 			TrqOsc_DCExceeded_Cnt_M_lgc; 					/* PRQA S 3218 */		/* Output for DCExceeded_lgc */						
STATIC VAR(boolean, AUTOMATIC) 			TrqOsc_PrevTrqOscActv_Cnt_M_lgc;
STATIC volatile VAR(boolean, AUTOMATIC) TrqOsc_NonZeroAmplitudeFlag_Cnt_D_lgc;			/* PRQA S 3218 */
#define TRQOSC_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define TRQOSC_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) 			TrqOsc_RateLmtAmplitude_MtrNm_M_f32;									/* This variable shall be Module level to serve unit delay purpose in Dynamic_Rate_Limit block of FDD */
STATIC VAR(float32, AUTOMATIC) 			TrqOsc_PrevAngle_MatRad_M_f32;					/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) 			TrqOsc_PreFinalCmd_MtrNm_M_f32;					/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TrqOsc_SineCmd_Uls_D_f32; 						/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TrqOsc_PreFinalCmd_MtrNm_D_f32;					/* PRQA S 3218 */		
STATIC volatile VAR(float32, AUTOMATIC) TrqOsc_PhaseAngle_MatRad_D_f32;					/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TrqOsc_RateLimitedAmplitude_MtrNm_D_f32;		/* PRQA S 3218 */		/* Display variable for Limited Amplitude */
STATIC volatile VAR(float32, AUTOMATIC) TrqOsc_PhaseAngleIncrease_MatRad_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TrqOsc_LimitedAmplitude_MtrNm_D_f32;			/* PRQA S 3218 */
#define TRQOSC_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */


#define TRQOSC_START_SEC_VAR_INIT_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) 			TrqOsc_LmtAmplitude_MtrNm_M_f32 	= 0.0F;		/* PRQA S 3218 */		/* This variable shall be Module level to hold the value for use in next cycle */
STATIC VAR(float32, AUTOMATIC) 			TrqOsc_PhaseAngleIncrease_Rad_M_f32 = 0.6283F;	/* PRQA S 3218 */		/* This variable shall be Module level to hold the value for use in next cycle */
STATIC VAR(float32, AUTOMATIC) 			TrqOsc_RisngRampRate_MtrNmpS_M_f32 	= 4400.0F;	/* PRQA S 3218 */		/* This variable shall be Module level to hold the value for use in next cycle */
STATIC VAR(float32, AUTOMATIC) 			TrqOsc_FallRampRate_MtrNmpS_M_f32 	= -4400.0F;	/* PRQA S 3218 */		/* This variable shall be Module level to hold the value for use in next cycle */
#define TRQOSC_STOP_SEC_VAR_INIT_32
#include "MemMap.h"/* PRQA S 5087 */


#define TRQOSC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AUTOMATIC) 	TrqOsc_PreFinalCmdKSV_M_str;
#define TRQOSC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

static FUNC(boolean, AUTOMATIC)	AmpRateLim(boolean Enable_Cnt_T_lgc);
static FUNC(float32, AUTOMATIC)  ChkFlg(float32 PhaseAngleOut_Rad_T_f32);

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
 * Enumeration Types:
 * ==================
 * FltInjectionLocType: Enumeration of integer in interval [0...255] with enumerators
 *   FLTINJ_ASSIST (1u)
 *   FLTINJ_RETURN (2u)
 *   FLTINJ_DAMPING (3u)
 *   FLTINJ_ASSTSUMNLMT (4u)
 *   FLTINJ_AVGFRICLRN (7u)
 *   FLTINJ_VECU_BATTERYVOLTAGE (8u)
 *   FLTINJ_HYSTCOMP (12u)
 *   FLTINJ_INERTIACOMP (14u)
 *   FLTINJ_SUPPPWRLMT_CUSTPL (25u)
 *   FLTINJ_EOTDAMPING_ETDMPFW (27u)
 *   FLTINJ_STABILITYCOMP (29u)
 *   FLTINJ_TRQBASEDINRTCOMP (30u)
 *   FLTINJ_SRLCOMVEHSPD_SGNLCOND (33u)
 *   FLTINJ_ASSTFIREWALL (34u)
 *   FLTINJ_ASSTEOTGAIN_LMTCOD (38u)
 *   FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
 *   FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
 *   FLTINJ_TRQOSC_PREFINALCOMMAND (43u)
 *   FLTINJ_GCCDIAG_HWTRQ (46u)
 *   FLTINJ_TRQOVLSTA_LKAFAULT (91u)
 *   FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100u)
 *   FLTINJ_TRQARBLIM_LKACMD (101u)
 *   FLTINJ_GCCDIAG_VEHSPD (146u)
 *   FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150u)
 *   FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151u)
 *   FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152u)
 *   FLTINJ_OUTPUTRAMPMULT_LMTCOD (153u)
 *   FLTINJ_ASSTEOTLIMIT_LMTCOD (154u)
 *   FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155u)
 *   FLTINJ_ANAHWTORQUE (156u)
 *   FLTINJ_MTRVEL (160u)
 *   FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200u)
 *   FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201u)
 *   FLTINJ_GCCDIAG_MTRTRQ (246u)
 *   FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255u)
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
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_MTRRAMPRATEFALL_MTRNMPS_F32 = -4400
 * Float: D_MTRRAMPRATERISE_MTRNMPS_F32 = 4400
 * Float: D_TRQOSCFREQINIT_F32 = 50
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TRQOSC_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOsc_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOSC_APPL_CODE) TrqOsc_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqOsc_Init
 *********************************************************************************************************************/
	/*Initialize Low Pass Filter here*/
	LPF_KUpdate_f32_m(D_DCTRENDLPFILFRQ_HZ_F32, D_2MS_SEC_F32, &TrqOsc_PreFinalCmdKSV_M_str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOsc_Per1
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
 *   Float Rte_IRead_TrqOsc_Per1_TrqOscAmp_MtrNm_f32(void)
 *   Boolean Rte_IRead_TrqOsc_Per1_TrqOscEnable_Cnt_lgc(void)
 *   Float Rte_IRead_TrqOsc_Per1_TrqOscFallRampRate_MtrNmpS_f32(void)
 *   Float Rte_IRead_TrqOsc_Per1_TrqOscFreq_Hz_f32(void)
 *   Float Rte_IRead_TrqOsc_Per1_TrqOscRisngRampRate_MtrNmpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TrqOsc_Per1_TrqOscActv_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqOsc_Per1_TrqOscActv_Cnt_lgc(void)
 *   void Rte_IWrite_TrqOsc_Per1_TrqOscCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqOsc_Per1_TrqOscCmd_MtrNm_f32(void)
 *   void Rte_IWrite_TrqOsc_Per1_TrqOscDCExceeded_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqOsc_Per1_TrqOscDCExceeded_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOSC_APPL_CODE) TrqOsc_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqOsc_Per1
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) Enable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TrqOscActv_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NonZeroAmplitudeFlag_Cnt_T_lgc;

	VAR(uint16, AUTOMATIC) Freq_Hz_T_u12p4;
	VAR(uint16, AUTOMATIC) AmpLmt_MtrNm_T_u5p11;
	VAR(uint16, AUTOMATIC) FreqIndex_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) EffectiveFreq_Hz_T_u12p4;

	VAR(float32, AUTOMATIC) Freq_Hz_T_f32;
	VAR(float32, AUTOMATIC) Amplitude_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) AmplitudeAbs_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) EffectiveFreq_Hz_T_f32;
	VAR(float32, AUTOMATIC) SineCmd_Uls_T_f32;
	VAR(float32, AUTOMATIC) FiltPreFinalCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) AbsFiltPreFinalCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PhaseAngleIn_Rad_T_f32; 				/* Phase Angle Input for Angle wrap */
	VAR(float32, AUTOMATIC) PhaseAngleOut_Rad_T_f32; 				/* Phase Angle Output after Angle wrap */
	VAR(float32, AUTOMATIC) AmpLmt_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) OscTrqCmd_MtrNm_T_f32; 					/* Output for Final OscTrqCmd */
	VAR(float32, AUTOMATIC) TrqOscRisngRampRate_MtrNmpS_T_f32;
	VAR(float32, AUTOMATIC) TrqOscFallRampRate_MtrNmpS_T_f32;
	VAR(float32, AUTOMATIC) PreFinalCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) Angle_MatRad_T_f32;
	VAR(float32, AUTOMATIC) LmtAmplitude_MtrNm_T_f32;



	/*Input Reads*/
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_TrqOsc_Per1_CP0_CheckpointReached();
	Enable_Cnt_T_lgc 					= Rte_IRead_TrqOsc_Per1_TrqOscEnable_Cnt_lgc();
	Freq_Hz_T_f32						= Rte_IRead_TrqOsc_Per1_TrqOscFreq_Hz_f32();
	Amplitude_MtrNm_T_f32 				= Rte_IRead_TrqOsc_Per1_TrqOscAmp_MtrNm_f32();
	TrqOscRisngRampRate_MtrNmpS_T_f32	= Rte_IRead_TrqOsc_Per1_TrqOscRisngRampRate_MtrNmpS_f32();
	TrqOscFallRampRate_MtrNmpS_T_f32	= Rte_IRead_TrqOsc_Per1_TrqOscFallRampRate_MtrNmpS_f32();


		
	if((Enable_Cnt_T_lgc == TRUE) && (TrqOsc_EnablePrev_Cnt_M_lgc == FALSE))
	{
		
		/* Update Variables */
		Freq_Hz_T_f32 	= Abs_f32_m(Freq_Hz_T_f32);
		Freq_Hz_T_u12p4 = FPM_FloatToFixed_m(Freq_Hz_T_f32, u12p4_T);
		
		if (Freq_Hz_T_u12p4 <= t_TrqOscFreqIn_Hz_u12p4[0u])													/* Interpolation based on floor input value (value below) */
		{
			Freq_Hz_T_u12p4 = t_TrqOscFreqIn_Hz_u12p4[0u];
		}
		else if(Freq_Hz_T_u12p4 >= (t_TrqOscFreqIn_Hz_u12p4[TableSize_m(t_TrqOscFreqIn_Hz_u12p4)-1u]))
		{

			Freq_Hz_T_u12p4 = t_TrqOscFreqIn_Hz_u12p4[TableSize_m(t_TrqOscFreqIn_Hz_u12p4)-1u];
		} 
		else
		{
			FreqIndex_Cnt_T_u16 = 0u;
			while( t_TrqOscFreqIn_Hz_u12p4[FreqIndex_Cnt_T_u16+1u] <= Freq_Hz_T_u12p4)
			{

				FreqIndex_Cnt_T_u16++;
			}
			Freq_Hz_T_u12p4 = t_TrqOscFreqIn_Hz_u12p4[FreqIndex_Cnt_T_u16];
		}
		
	
		EffectiveFreq_Hz_T_u12p4 = Limit_m(Freq_Hz_T_u12p4, D_PRMNTMINFRQ_HZ_U12P4, D_PRMNTMAXFRQ_HZ_U12P4);
												
		if (EffectiveFreq_Hz_T_u12p4 <= t_TrqOscFreqIn_Hz_u12p4[0u])										/* Interpolation based on floor input value (value below) */
		{
			AmpLmt_MtrNm_T_u5p11 = t_TrqOscAmpLimit_MtrNm_u5p11[0];
			
		}
		else if(EffectiveFreq_Hz_T_u12p4 >= t_TrqOscFreqIn_Hz_u12p4[TableSize_m(t_TrqOscFreqIn_Hz_u12p4)-1u])
		{
			AmpLmt_MtrNm_T_u5p11 = t_TrqOscAmpLimit_MtrNm_u5p11[TableSize_m(t_TrqOscAmpLimit_MtrNm_u5p11)-1u];
		} 
		else
		{
			FreqIndex_Cnt_T_u16 = 0u;
			while( t_TrqOscFreqIn_Hz_u12p4[FreqIndex_Cnt_T_u16+1u] <= EffectiveFreq_Hz_T_u12p4)
			{
				FreqIndex_Cnt_T_u16++;																		/* Perform floor logic for intermediate values */
			}
			AmpLmt_MtrNm_T_u5p11 = t_TrqOscAmpLimit_MtrNm_u5p11[FreqIndex_Cnt_T_u16];
		}													
															
		AmpLmt_MtrNm_T_f32 						= FPM_FixedToFloat_m(AmpLmt_MtrNm_T_u5p11,u5p11_T);
		AmplitudeAbs_MtrNm_T_f32 				= Abs_f32_m(Amplitude_MtrNm_T_f32);
		LmtAmplitude_MtrNm_T_f32 				= Limit_m(AmplitudeAbs_MtrNm_T_f32,D_ZERO_ULS_F32, AmpLmt_MtrNm_T_f32);
		TrqOsc_LmtAmplitude_MtrNm_M_f32 		= Limit_m(LmtAmplitude_MtrNm_T_f32, D_MINAMP_MOTNWTMTR_F32, D_MAXAMP_MOTNWTMTR_F32);
		TrqOsc_LimitedAmplitude_MtrNm_D_f32		= TrqOsc_LmtAmplitude_MtrNm_M_f32;
		
		
		/* Phase Angle Increase */
		EffectiveFreq_Hz_T_f32  				= FPM_FixedToFloat_m(EffectiveFreq_Hz_T_u12p4, u12p4_T);
		TrqOsc_PhaseAngleIncrease_Rad_M_f32 	= EffectiveFreq_Hz_T_f32 * D_2PI_ULS_F32 * D_2MS_SEC_F32;
		TrqOsc_PhaseAngleIncrease_MatRad_D_f32	= TrqOsc_PhaseAngleIncrease_Rad_M_f32;
		TrqOsc_RisngRampRate_MtrNmpS_M_f32		= TrqOscRisngRampRate_MtrNmpS_T_f32;
		TrqOsc_FallRampRate_MtrNmpS_M_f32		= TrqOscFallRampRate_MtrNmpS_T_f32;
	
	}
	
	TrqOsc_EnablePrev_Cnt_M_lgc = Enable_Cnt_T_lgc; 														/* Update the previous enable */

	/* Unit Delay */
	PhaseAngleIn_Rad_T_f32 = TrqOsc_PhaseAngleIncrease_Rad_M_f32 + TrqOsc_PrevAngle_MatRad_M_f32 ; 		/* Uses previous value of TrqOsc_Angle_Rad_M_f32 */

	/* Angle Wrapper */
	if(PhaseAngleIn_Rad_T_f32 >= D_2PI_ULS_F32)
	{
		PhaseAngleOut_Rad_T_f32 = PhaseAngleIn_Rad_T_f32 - D_2PI_ULS_F32;									/* Pass through to calculate new Phase Angle */
	}
	else
	{
		PhaseAngleOut_Rad_T_f32 = PhaseAngleIn_Rad_T_f32;
	}
		
	/* Check Flag */
	Angle_MatRad_T_f32 = ChkFlg(PhaseAngleOut_Rad_T_f32);

	TrqOsc_PrevAngle_MatRad_M_f32 	= Angle_MatRad_T_f32;
	TrqOsc_PhaseAngle_MatRad_D_f32	= Angle_MatRad_T_f32;
	SineCmd_Uls_T_f32 				= sinf(Angle_MatRad_T_f32);
	TrqOsc_SineCmd_Uls_D_f32 		= SineCmd_Uls_T_f32;
 
	/* Amplitude Rate Limiter */
	NonZeroAmplitudeFlag_Cnt_T_lgc 				= AmpRateLim(Enable_Cnt_T_lgc);

	TrqOsc_NonZeroAmplitudeFlag_Cnt_D_lgc		= NonZeroAmplitudeFlag_Cnt_T_lgc; 								/* Display variable's update */
	TrqOsc_RateLimitedAmplitude_MtrNm_D_f32		= TrqOsc_RateLmtAmplitude_MtrNm_M_f32;
	PreFinalCmd_MtrNm_T_f32 					= SineCmd_Uls_T_f32 * TrqOsc_RateLmtAmplitude_MtrNm_M_f32;
	TrqOsc_PreFinalCmd_MtrNm_D_f32 				= PreFinalCmd_MtrNm_T_f32;										


	/* FLTINJ - EA3 */
	#if (STD_ON == BC_TRQOSC_FAULTINJECTIONPOINT)
	(void) Rte_Call_FaultInjection_SCom_FltInjection(&PreFinalCmd_MtrNm_T_f32, FLTINJ_TRQOSC_PREFINALCOMMAND);
	#endif

	TrqOsc_PreFinalCmd_MtrNm_M_f32 = PreFinalCmd_MtrNm_T_f32;

	/* DC Check */ 	/* DC Trend - LPF */
	FiltPreFinalCmd_MtrNm_T_f32 	= LPF_OpUpdate_f32_m(TrqOsc_PreFinalCmd_MtrNm_M_f32,&TrqOsc_PreFinalCmdKSV_M_str);
	AbsFiltPreFinalCmd_MtrNm_T_f32 	= Abs_f32_m(FiltPreFinalCmd_MtrNm_T_f32);

	if( AbsFiltPreFinalCmd_MtrNm_T_f32 >= D_MAXDC_MOTNWTMTR_F32)
	{
		TrqOsc_DCExceeded_Cnt_M_lgc = TRUE;
	}
		

	if(TrqOsc_DCExceeded_Cnt_M_lgc == TRUE)
	{
		OscTrqCmd_MtrNm_T_f32 = 0.0f;
	}
	else
	{
		OscTrqCmd_MtrNm_T_f32 = TrqOsc_PreFinalCmd_MtrNm_M_f32;
	}
			
	/* Saturation saturation */
	OscTrqCmd_MtrNm_T_f32 	= Limit_m(OscTrqCmd_MtrNm_T_f32, -D_MAXAMP_MOTNWTMTR_F32, D_MAXAMP_MOTNWTMTR_F32);

	if( (TrqOsc_DCExceeded_Cnt_M_lgc == FALSE) && (NonZeroAmplitudeFlag_Cnt_T_lgc == TRUE) )
	{
		TrqOscActv_Cnt_T_lgc = TRUE;
	}
	else
	{
		TrqOscActv_Cnt_T_lgc = FALSE;
	}

	/* Update of the previous value for use in next cycle (Unit delay) */
	TrqOsc_PrevTrqOscActv_Cnt_M_lgc	= TrqOscActv_Cnt_T_lgc;


	/* Output Write outputs to RTE */
	Rte_IWrite_TrqOsc_Per1_TrqOscDCExceeded_Cnt_lgc(TrqOsc_DCExceeded_Cnt_M_lgc);
	Rte_IWrite_TrqOsc_Per1_TrqOscCmd_MtrNm_f32(OscTrqCmd_MtrNm_T_f32);
	Rte_IWrite_TrqOsc_Per1_TrqOscActv_Cnt_lgc(TrqOscActv_Cnt_T_lgc);
		
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_TrqOsc_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TRQOSC_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*****************************************************************************************************************
* Name        :   AmpRateLim
* Description :   Sub function to calculate Amplitude Rate Limiter.
* Inputs      :   TrqOsc_FallRampRate_MtrNmpS_M_f32, TrqOsc_RisngRampRate_MtrNmpS_M_f32, TrqOsc_LmtAmplitude_MtrNm_M_f32, Enable_Cnt_T_lgc, 
				  TrqOsc_RateLmtAmplitude_MtrNm_M_f32
* Outputs     :   NonZeroAmplitudeFlag_Cnt_T_lgc, TrqOsc_RateLmtAmplitude_MtrNm_M_f32
* Usage Notes :   None
****************************************************************************************************************/


static FUNC(boolean, AUTOMATIC)  AmpRateLim(boolean Enable_Cnt_T_lgc)

	{

		VAR(boolean, AUTOMATIC) NonZeroAmplitudeFlag_Cnt_T_lgc;

		VAR(float32, AUTOMATIC) DynLwrLmtAmp_MtrNm_T_f32;
		VAR(float32, AUTOMATIC) DynUprLmtAmp_MtrNm_T_f32;
		VAR(float32, AUTOMATIC) RateLmtdAmplitude_MtrNm_T_f32;
		VAR(float32, AUTOMATIC) PreLmtAmplitude_MtrNm_T_f32;

		/* Amplitude Rate Limiter */

		if(Enable_Cnt_T_lgc == FALSE)
		{

			PreLmtAmplitude_MtrNm_T_f32 = 0.0F;
		}
		else
		{
			PreLmtAmplitude_MtrNm_T_f32 = TrqOsc_LmtAmplitude_MtrNm_M_f32;
		}

		if(TRUE == k_TrqOsc_UseRampRateCal_Cnt_lgc)
		{

			DynLwrLmtAmp_MtrNm_T_f32			= Limit_m(k_TrqOsc_FallRampRate_MtrNmpS_f32, -D_MAXRAMPRATE_MOTNWTMTR_F32, -D_MINRAMPRATE_MOTNWTMTR_F32);
			DynUprLmtAmp_MtrNm_T_f32			= Limit_m(k_TrqOsc_RisngRampRate_MtrNmpS_f32, D_MINRAMPRATE_MOTNWTMTR_F32,  D_MAXRAMPRATE_MOTNWTMTR_F32);
		}

		else
		{
			DynLwrLmtAmp_MtrNm_T_f32			= Limit_m(TrqOsc_FallRampRate_MtrNmpS_M_f32, -D_MAXRAMPRATE_MOTNWTMTR_F32, -D_MINRAMPRATE_MOTNWTMTR_F32);
			DynUprLmtAmp_MtrNm_T_f32			= Limit_m(TrqOsc_RisngRampRate_MtrNmpS_M_f32, D_MINRAMPRATE_MOTNWTMTR_F32,  D_MAXRAMPRATE_MOTNWTMTR_F32);
		}

		RateLmtdAmplitude_MtrNm_T_f32			= Limit_m( PreLmtAmplitude_MtrNm_T_f32,
														   ((DynLwrLmtAmp_MtrNm_T_f32 * D_2MS_SEC_F32) + TrqOsc_RateLmtAmplitude_MtrNm_M_f32),
														   ((DynUprLmtAmp_MtrNm_T_f32 * D_2MS_SEC_F32) + TrqOsc_RateLmtAmplitude_MtrNm_M_f32) );

		if(RateLmtdAmplitude_MtrNm_T_f32 > 0.0F)
		{
			NonZeroAmplitudeFlag_Cnt_T_lgc = TRUE;
		}

		else
		{
			NonZeroAmplitudeFlag_Cnt_T_lgc = FALSE;
		}

		TrqOsc_RateLmtAmplitude_MtrNm_M_f32				= RateLmtdAmplitude_MtrNm_T_f32;

		return NonZeroAmplitudeFlag_Cnt_T_lgc;

	}


/*****************************************************************************************************************
* Name        :   ChkFlg
* Description :   Sub function to calculate Check Flag.
* Inputs      :   PhaseAngleOut_Rad_T_f32
* Outputs     :   Angle_MatRad_T_f32
* Usage Notes :   None
****************************************************************************************************************/
static FUNC(float32, AUTOMATIC)  ChkFlg(float32 PhaseAngleOut_Rad_T_f32)
{
	VAR(float32, AUTOMATIC) Angle_MatRad_T_f32;
	/* Check Flag */
	if(TrqOsc_PrevTrqOscActv_Cnt_M_lgc == TRUE)
	{
		Angle_MatRad_T_f32 = PhaseAngleOut_Rad_T_f32;
	}
	else
	{
		Angle_MatRad_T_f32 = 0.0F;
	}
	return Angle_MatRad_T_f32;
}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
