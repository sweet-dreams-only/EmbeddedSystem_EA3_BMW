/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_CustPL.c
 *     Workspace:  C:/SynergyWorkArea/Working/CustPL_BMW/autosar
 *     SW-C Type:  Ap_CustPL
 *  Generated at:  Tue Jun 14 10:15:17 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_CustPL>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          EA3#17 %
 * %derived_by:       czmgrw %
 * %date_modified:    Fri Jul  5 12:54:47 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/14/12  1        NRAR      CBD Initial creation
 * 06/15/12  2        NRAR      Remove unused temp variables
 * 06/16/12  3        NRAR      Template update (comments only change)
 * 06/22/12  4        KJS       Added display variable for coding battery limit.
 * 06/25/12  5        JJW       Template update to remove mode disabling in Per1.
 *                              Corrected change log to follow file development.
 * 10/06/12  6        Selva     Checkpoints added and mempmap macros corrected                                  6460
 * 10/25/12  7        KJS       Updated component to CF-06, includes MSA
 *                              Added checkpoints/memmap definitions
 * 10/26/12  8        KJS       Updated init MSA state with anomaly correction
 * 10/31/12  9        KJS       Anomaly 4000, updated timer types
 * 02/16/13  10,11    Selva     CBD version 2 update
 * 04/26/13  12       Selva     Updated for unit test
 * 06/05/13  13       NRAR      Updated to FDD ver 4
 * 07/05/13  14       Jared     Updated to FDD ver 004B                                                         8849
 * 02/11/15  15       JK        Updated to FDD ver 006 -Added rate limiter for SupplyPwrLimit                   13017
 *                              Added fault injection location to allow for in-vehicle confirmation 
 *                              of the slew rate calibration.
 * 04/15/16  16       ABS       Fault Injection fix                                                          EA3#7625
 * 06/10/16  17       JK        Updated to FDD ver 007 and updated to new folder structure          EA3#8204,EA3#8205
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_CustPL.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "fixmath.h"
#include "GlobalMacro.h"
#include "interpolation.h"
#include "CalConstants.h"

/* PRQA S 4395 EOF 
* MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* PRQA S 3332 EOF 
* MISRA-C: 2004 Rule 19.11: This deviation is required for fault injection points 
* Warning 3332 is not seen in current file because constant BC_DIGHWTRQSENT_FAULTINJECTIONPOINT is defined in compiler_cfg header file */


#define D_NOMINPUTVOLTAGE_VOLTS_F32			12.0F
#define D_CUSTCURRLMTLOLMT_AMPS_F32			0.0F
#define D_CUSTCURRLMTHILMT_AMPS_F32			150.0F
#define D_CUSTCURRLMT_10MS_SEC_F32          0.01F
#define D_CUSTCURRLMT_INITSUPPLYPWRLMT_AMP_F32 (166.6667F)  /* (D_MAXSUPPLYLMT_WATTS_F32 / D_NOMINPUTVOLTAGE_VOLTS_F32) */

/* MSA State Machine / Variables */
typedef enum
{
	MSA_NORMAL_OP					= 0U,
	MSA_INIT						= 1U,
	MSA_RAMP1_HOLDPERC				= 2U,
	MSA_RAMP2_MSAAMPSHOLD			= 3U,
	MSA_RAMP3_ZEROASSIST_HOLDZERO	= 4U,
	MSA_RAMP4						= 5U
} MSAStateType;

typedef	struct  {
	unsigned Cmd_EngRun 		: 1;
	unsigned Cmd_StopCmd 		: 1;
	unsigned Cmd_StopAnnoun		: 1;
	unsigned AssistEn			: 1;
	unsigned TimeExpired		: 1;
	unsigned Ramp4Complete		: 1;
	unsigned Ramp3Complete		: 1;
	unsigned Ramp2Complete		: 1;
	unsigned Ramp1Complete		: 1;
	unsigned TrqRampDnComplete	: 1;
	unsigned TrqRampUpComplete	: 1;
	unsigned SCRampUpComplete	: 1;
	unsigned Cmd_StartAnnoun	: 1;
	unsigned Unused				: 3;
} MSATransVectorType;


#define CUSTPL_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_CUSTPL_VAR) MSACurrLimit_Amps_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) MSAImax_Amps_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) Thresh1_Amps_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) Ramp1Dec_Amps_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) Ramp2Dec_Amps_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) Ramp3Dec_Amps_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) Ramp4Inc_Amps_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) TMSAClock_Sec_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) PrevMSACurrLimit_Amps_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) PrevTMSAClock_Sec_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) CCLTrqRamp_Uls_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) PrevCCLTrqRamp_Uls_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) TrqRampDec_Uls_M_f32;
STATIC VAR(float32, AP_CUSTPL_VAR) TrqRampInc_Uls_M_f32;
STATIC volatile VAR(float32, AP_CUSTPL_VAR) VspdDepIbatLmt_Amps_D_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_CUSTPL_VAR) CusPL_SupplyCurrLmtLtd_Amp_M_f32; /* PRQA S 3218 */
#define CUSTPL_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define CUSTPL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(MSATransVectorType, AP_CUSTPL_VAR) MSAVector_Cnt_M_str;
STATIC VAR(MSAStateType, AP_CUSTPL_VAR) PresentMSAState_Cnt_M_enum; /* PRQA S 3218 */
#define CUSTPL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define CUSTPL_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) CCLMSAActive_Cnt_M_lgc;
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) MSAAssistEnable_Cnt_D_lgc;
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) Ramp1Complete_Cnt_D_lgc;  /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) Ramp2Complete_Cnt_D_lgc;  /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) Ramp3Complete_Cnt_D_lgc;  /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) Ramp4Complete_Cnt_D_lgc;  /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) SCRampUpComplete_Cnt_D_lgc; /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) TrqRampDnComplete_Cnt_D_lgc; /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) TrqRampUpComplete_Cnt_D_lgc; /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_CUSTPL_VAR) TMSAExpired_Cnt_D_lgc;  /* PRQA S 3218 */
#define CUSTPL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

/* Supporting Functions for Per 1*/
STATIC FUNC(float32, AP_CUSTPL_CODE) VehSpdDepCurrLmt(VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32);
STATIC FUNC(float32, AP_CUSTPL_CODE) CodingSwitchSupCurrLmt(VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32, VAR(float32, AUTOMATIC) CVehSpdCurLmtSpd_Kph_T_f32, VAR(boolean, AUTOMATIC) CVehSpdCurLimiter_Cnt_T_lgc,
															VAR(float32, AUTOMATIC) CBattCurLimCur_Amps_T_f32, VAR(float32, AUTOMATIC) CVehSpdCurLmtCurrent_Amps_T_f32);
STATIC FUNC(void, AP_CUSTPL_CODE) MSASupCurrLmt(VAR(boolean, AUTOMATIC) CAssistMSA_Cnt_T_lgc, VAR(MSA_Cmd_Type, AUTOMATIC) MSACommand_Uls_T_enum);

/* MSA Supporting functions */
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_NormalOp(void);
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Init(void);
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Ramp1_HoldPerc(void);
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Ramp2_MSAAmpsHold(void);
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Ramp3_ZeroAssist_HoldZero(void);
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Ramp4(void);

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
 * MSA_Cmd_Type: Enumeration of integer in interval [0...3] with enumerators
 *   MSA_STOP_ANNOUNCEMENT (0u)
 *   MSA_STOP_COMMAND (1u)
 *   MSA_START_ANNOUNCEMENT (2u)
 *   MSA_ENGINE_RUN (3u)
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
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_SUPPLYCURRINIT_AMP_F32 = 166.67
 * Float: D_ZERO_ULS_F32 = 0
 * MSA_Cmd_Type: D_MSA_CMD_INIT = 3u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_CUSTPL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CustPL_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CASSISTMSA_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_CBATCURLIMITCUR_Amp_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CustPL_Init1_CCLMSAActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CustPL_Init1_CCLMSAActive_Cnt_lgc(void)
 *   void Rte_IWrite_CustPL_Init1_CCLTrqRamp_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CustPL_Init1_CCLTrqRamp_Uls_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CUSTPL_APPL_CODE) CustPL_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CustPL_Init1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) CodingBatCurrLimit_Amp_T_f32;
	VAR(boolean, AUTOMATIC) CodingAssistMSA_Cnt_T_lgc;

	(void)Rte_Read_CBATCURLIMITCUR_Amp_f32(&CodingBatCurrLimit_Amp_T_f32);
	(void)Rte_Read_CASSISTMSA_Cnt_lgc(&CodingAssistMSA_Cnt_T_lgc);

	/*** Initialize rate limiter output ***/
	CusPL_SupplyCurrLmtLtd_Amp_M_f32 = D_CUSTCURRLMT_INITSUPPLYPWRLMT_AMP_F32;

	/*** Vehicle Specific Maximum Supply Current Limit ***/
	MSAImax_Amps_M_f32 = Min_m(Min_m(k_VariantImax_Amps_f32, FPM_FixedToFloat_m(t_VehSpdLmtTblY_Amps_u12p4[0],u12p4_T)), CodingBatCurrLimit_Amp_T_f32);

	/*** Calculate State of Coding Switch ***/
	if (CodingAssistMSA_Cnt_T_lgc == FALSE)
	{
		MSAVector_Cnt_M_str.AssistEn = FALSE;
		MSAAssistEnable_Cnt_D_lgc = FALSE;
	}
	else
	{
		MSAVector_Cnt_M_str.AssistEn = TRUE;
		MSAAssistEnable_Cnt_D_lgc = TRUE;
	}

	/*** Supply Current Ramp Step Size ***/
	Ramp1Dec_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp1Time_Sec_f32;
	Ramp2Dec_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp2Time_Sec_f32;
	if (MSAVector_Cnt_M_str.AssistEn == TRUE)
	{
		Ramp3Dec_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp3AsstEn_Sec_f32;
	}
	else
	{
		Ramp3Dec_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp3AsstDis_Sec_f32;
	}
	Ramp4Inc_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp4Time_Sec_f32;

	/*** Torque Command Multiplier Ramp Step Size ***/
	if (MSAVector_Cnt_M_str.AssistEn == TRUE)
	{
		TrqRampDec_Uls_M_f32 = k_TLoopMSA_Sec_f32 / k_CCLTrqRampDecAsstEn_Sec_f32;
	}
	else
	{
		TrqRampDec_Uls_M_f32 = k_TLoopMSA_Sec_f32 / k_CCLTrqRampDecAsstDis_Sec_f32;
	}
	TrqRampInc_Uls_M_f32 = k_TLoopMSA_Sec_f32 / k_CCLTrqRampInc_Sec_f32;

	/*** Threshold 1 Supply Current Limit ***/
	Thresh1_Amps_M_f32 = MSAImax_Amps_M_f32 * k_ILimitThresh1Mult_Uls_f32;

	/*** Initialize MSA Active Flag and Torque Ramp Multiplier ***/
	CCLMSAActive_Cnt_M_lgc = FALSE;
	CCLTrqRamp_Uls_M_f32 = D_ONE_ULS_F32;

	Rte_IWrite_CustPL_Init1_CCLMSAActive_Cnt_lgc(CCLMSAActive_Cnt_M_lgc);
	Rte_IWrite_CustPL_Init1_CCLTrqRamp_Uls_f32(CCLTrqRamp_Uls_M_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CustPL_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_CustPL_Per1_CASSISTMSA_Cnt_lgc(void)
 *   Float Rte_IRead_CustPL_Per1_CBATCURLIMITCUR_Amp_f32(void)
 *   Float Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITCURRENT_Amp_f32(void)
 *   Boolean Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITER_Cnt_lgc(void)
 *   Float Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITSPEED_Kph_f32(void)
 *   MSA_Cmd_Type Rte_IRead_CustPL_Per1_MSACommand_MSACmd_enum(void)
 *   Float Rte_IRead_CustPL_Per1_SupplyCurrLmt_Amp_f32(void)
 *   Float Rte_IRead_CustPL_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CustPL_Per1_CCLMSAActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CustPL_Per1_CCLMSAActive_Cnt_lgc(void)
 *   void Rte_IWrite_CustPL_Per1_CCLTrqRamp_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CustPL_Per1_CCLTrqRamp_Uls_f32(void)
 *   void Rte_IWrite_CustPL_Per1_CustCurrLmt_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CustPL_Per1_CustCurrLmt_Amp_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CUSTPL_APPL_CODE) CustPL_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CustPL_Per1
 *********************************************************************************************************************/

	/* Local Vars */
	VAR(float32, AUTOMATIC) SupplyCurrLmt_Amp_T_f32;
	VAR(float32, AUTOMATIC) SupplyCurrLmtLtd_Amp_T_f32;

	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(float32, AUTOMATIC) VSpdDepIBatLmt_Amps_T_f32;

	VAR(float32, AUTOMATIC) CodingCurrLmt_Amps_T_f32;
	VAR(boolean, AUTOMATIC) CVehSpdCurLimiter_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) CBattCurLimCur_Amps_T_f32;
	VAR(float32, AUTOMATIC) CVehSpdCurLmtSpd_Kph_T_f32;
	VAR(float32, AUTOMATIC) CVehSpdCurLmtCurrent_Amps_T_f32;

	VAR(MSA_Cmd_Type, AUTOMATIC) MSACommand_Uls_T_enum;
	VAR(boolean, AUTOMATIC) CAssistMSA_Cnt_T_lgc;

	/* Output */
	VAR(float32, AUTOMATIC) CustCurrLmt_Amps_T_f32;

	/* Gather inputs from RTE */
	SupplyCurrLmt_Amp_T_f32 = Rte_IRead_CustPL_Per1_SupplyCurrLmt_Amp_f32();
	VehSpd_Kph_T_f32 = Rte_IRead_CustPL_Per1_VehicleSpeed_Kph_f32();
	CVehSpdCurLimiter_Cnt_T_lgc = Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITER_Cnt_lgc();
	CBattCurLimCur_Amps_T_f32 = Rte_IRead_CustPL_Per1_CBATCURLIMITCUR_Amp_f32();
	CVehSpdCurLmtCurrent_Amps_T_f32 = Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITCURRENT_Amp_f32();
	CVehSpdCurLmtSpd_Kph_T_f32 = Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITSPEED_Kph_f32();
	MSACommand_Uls_T_enum = Rte_IRead_CustPL_Per1_MSACommand_MSACmd_enum();
	CAssistMSA_Cnt_T_lgc = Rte_IRead_CustPL_Per1_CASSISTMSA_Cnt_lgc();

	/* Process Data */
	VSpdDepIBatLmt_Amps_T_f32 = VehSpdDepCurrLmt(VehSpd_Kph_T_f32);
	CodingCurrLmt_Amps_T_f32 = CodingSwitchSupCurrLmt(VehSpd_Kph_T_f32, CVehSpdCurLmtSpd_Kph_T_f32, CVehSpdCurLimiter_Cnt_T_lgc, CBattCurLimCur_Amps_T_f32, CVehSpdCurLmtCurrent_Amps_T_f32);
	MSASupCurrLmt(CAssistMSA_Cnt_T_lgc, MSACommand_Uls_T_enum);

#if (STD_ON == BC_CUSTPL_FAULTINJECTIONPOINT)
	(void)Rte_Call_FaultInjection_SCom_FltInjection(&SupplyCurrLmt_Amp_T_f32,FLTINJ_SUPPPWRLMT_CUSTPL);
#endif

	/* Rate Limiter */
	SupplyCurrLmtLtd_Amp_T_f32 = Limit_m(SupplyCurrLmt_Amp_T_f32,(CusPL_SupplyCurrLmtLtd_Amp_M_f32 -(k_AmpDecSlew_AmppS_f32*D_CUSTCURRLMT_10MS_SEC_F32 )),
															(CusPL_SupplyCurrLmtLtd_Amp_M_f32+(k_AmpIncSlew_AmppS_f32*D_CUSTCURRLMT_10MS_SEC_F32) ));
	CusPL_SupplyCurrLmtLtd_Amp_M_f32 = SupplyCurrLmtLtd_Amp_T_f32;

	/* Update output */
	CustCurrLmt_Amps_T_f32 = Min_m(Min_m(SupplyCurrLmtLtd_Amp_T_f32, VSpdDepIBatLmt_Amps_T_f32), Min_m(CodingCurrLmt_Amps_T_f32, MSACurrLimit_Amps_M_f32));
	CustCurrLmt_Amps_T_f32 = Limit_m(CustCurrLmt_Amps_T_f32, D_CUSTCURRLMTLOLMT_AMPS_F32, D_CUSTCURRLMTHILMT_AMPS_F32);

	Rte_IWrite_CustPL_Per1_CustCurrLmt_Amp_f32(CustCurrLmt_Amps_T_f32);
	Rte_IWrite_CustPL_Per1_CCLMSAActive_Cnt_lgc(CCLMSAActive_Cnt_M_lgc);
	Rte_IWrite_CustPL_Per1_CCLTrqRamp_Uls_f32(CCLTrqRamp_Uls_M_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_CUSTPL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************************************************
 *	Function Name: 	   VehSpdDepCurrLmt
 *
 *	Description:       Output of this function is a desired supply current
 *					   limit in units of amps based on vehicle speed.
 *
 *	Inputs:		       VehSpd_Kph_T_f32: Current Vehicle Speed
 *
 *	Outputs:	       VSpdDepIBatLmt_Amps_T_f32: Vehicle Speed Dependent Limit
 *												 in Amps
 *
 ******************************************************************************/
STATIC FUNC(float32, AP_CUSTPL_CODE) VehSpdDepCurrLmt(VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32)
{
	/* Local Vars */
	VAR(uint16, AUTOMATIC) VSpdDepIBatLmt_Amps_T_u12p4;
	VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u9p7;

	/* Output */
	VAR(float32, AUTOMATIC) VSpdDepIBatLmt_Amps_T_f32;

	VehSpd_Kph_T_u9p7 = FPM_FloatToFixed_m(VehSpd_Kph_T_f32, u9p7_T);
	VSpdDepIBatLmt_Amps_T_u12p4 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_VehSpdLmtTblX_Kph_u9p7,
																t_VehSpdLmtTblY_Amps_u12p4,
																TableSize_m(t_VehSpdLmtTblX_Kph_u9p7),
																VehSpd_Kph_T_u9p7);
	VSpdDepIBatLmt_Amps_T_f32 = FPM_FixedToFloat_m(VSpdDepIBatLmt_Amps_T_u12p4,u12p4_T);
	VspdDepIbatLmt_Amps_D_f32 = VSpdDepIBatLmt_Amps_T_f32;

	return VSpdDepIBatLmt_Amps_T_f32;
}

/******************************************************************************
 *	Function Name: 	   CodingSwitchSupCurrLmt
 *
 *	Description:       Function selects the appropriate supply current limit to
 *					   apply to the system based on OEM coding selections.
 *
 *	Inputs:		       VehSpd_Kph_T_f32: Current Vehicle Speed
 *					   CVehSpdCurLmtSpd_Kph_T_f32: Vehicle speed threshold
 *					   CVehSpdCurLimiter_Cnt_T_lgc: Vehicle speed limit enabled
 *					   CBattCurLimCur_Amps_T_f32: Value for Batter Current Limit
 *					   CVehSpdCurLmtCurrent_Amps_T_f32: Value for VehSpd Current Limit
 *
 *	Outputs:	       CodingCurrLmt_Amp_T_f32: Coding limit value
 *
 ******************************************************************************/
STATIC FUNC(float32, AP_CUSTPL_CODE) CodingSwitchSupCurrLmt(VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32, VAR(float32, AUTOMATIC) CVehSpdCurLmtSpd_Kph_T_f32, VAR(boolean, AUTOMATIC) CVehSpdCurLimiter_Cnt_T_lgc, VAR(float32, AUTOMATIC) CBattCurLimCur_Amps_T_f32, VAR(float32, AUTOMATIC) CVehSpdCurLmtCurrent_Amps_T_f32)
{

	/* Local Vars */
	/* Output */
	VAR(float32, AUTOMATIC) CodingCurrLmt_Amp_T_f32;

	if (FALSE == CVehSpdCurLimiter_Cnt_T_lgc)
	{
		CodingCurrLmt_Amp_T_f32 = CBattCurLimCur_Amps_T_f32;
	}
	else
	{
		if (VehSpd_Kph_T_f32 > CVehSpdCurLmtSpd_Kph_T_f32)
		{
			CodingCurrLmt_Amp_T_f32 = CVehSpdCurLmtCurrent_Amps_T_f32;
		}
		else
		{
			CodingCurrLmt_Amp_T_f32 = CBattCurLimCur_Amps_T_f32;
		}

	 }

	return CodingCurrLmt_Amp_T_f32;
}


/******************************************************************************
 *	Function Name: 	   MSASupCurrLmt
 *
 *	Description:       Main functional handling for MSA
 *
 *	Inputs:		       CAssistMSA_Cnt_T_lgc: Coding switch for MSA
 *					   MSACommand_Uls_T_enum: SrlCom MSA command
 *
 *	Outputs:	       MSACurrLmt_Amp_T_f32: MSA limit value
 *
 ******************************************************************************/
STATIC FUNC(void, AP_CUSTPL_CODE) MSASupCurrLmt(VAR(boolean, AUTOMATIC) CAssistMSA_Cnt_T_lgc, VAR(MSA_Cmd_Type, AUTOMATIC) MSACommand_Uls_T_enum)
{
	/* Local Vars */
	VAR(MSAStateType, AUTOMATIC) NextMSAState_Cnt_T_enum;
	NextMSAState_Cnt_T_enum = PresentMSAState_Cnt_M_enum;

	/* Build State Vector */
	if (CAssistMSA_Cnt_T_lgc == TRUE)
	{
		MSAVector_Cnt_M_str.AssistEn = TRUE;
	}
	else
	{
		MSAVector_Cnt_M_str.AssistEn = FALSE;
	}

	switch (MSACommand_Uls_T_enum)
	{
		case MSA_STOP_ANNOUNCEMENT:
			MSAVector_Cnt_M_str.Cmd_EngRun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StartAnnoun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StopAnnoun = TRUE;
			MSAVector_Cnt_M_str.Cmd_StopCmd = FALSE;
		break;
		case MSA_STOP_COMMAND:
			MSAVector_Cnt_M_str.Cmd_EngRun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StartAnnoun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StopAnnoun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StopCmd = TRUE;
		break;
		case MSA_START_ANNOUNCEMENT:
			MSAVector_Cnt_M_str.Cmd_EngRun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StartAnnoun = TRUE;
			MSAVector_Cnt_M_str.Cmd_StopAnnoun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StopCmd = FALSE;
		break;
		case MSA_ENGINE_RUN:
		default:
			MSAVector_Cnt_M_str.Cmd_EngRun = TRUE;
			MSAVector_Cnt_M_str.Cmd_StartAnnoun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StopAnnoun = FALSE;
			MSAVector_Cnt_M_str.Cmd_StopCmd = FALSE;
		break;
	}

	/* Execute state operation */
	switch(PresentMSAState_Cnt_M_enum)
	{
		case MSA_NORMAL_OP:

			/* Execute state function */
			MSA_State_NormalOp();

			/* Determine Next State */
			if (MSAVector_Cnt_M_str.Cmd_EngRun == TRUE)
			{
				/* DO NOTHING - stays in same state */
			}
			else if ((MSAVector_Cnt_M_str.Cmd_StopCmd == TRUE) ||(MSAVector_Cnt_M_str.Cmd_StopAnnoun == TRUE))
			{
				NextMSAState_Cnt_T_enum = MSA_INIT;
			}
			else
			{
				/* DO NOTHING - stays in same state */
			}

		break;
		case MSA_INIT:

			/* Execute state function */
			MSA_State_Init();

			/* Determine Next State */

			if (MSAVector_Cnt_M_str.Cmd_EngRun == TRUE)
			{
				NextMSAState_Cnt_T_enum = MSA_NORMAL_OP;
			}
			else if (MSAVector_Cnt_M_str.Cmd_StopCmd == TRUE)
			{
				if (MSAVector_Cnt_M_str.AssistEn == FALSE)
				{
					NextMSAState_Cnt_T_enum = MSA_RAMP3_ZEROASSIST_HOLDZERO;
				}
				else
				{
					NextMSAState_Cnt_T_enum = MSA_RAMP2_MSAAMPSHOLD;
				}
			}
			else if (MSAVector_Cnt_M_str.Cmd_StopAnnoun == TRUE)
			{
				NextMSAState_Cnt_T_enum = MSA_RAMP1_HOLDPERC;
			}
			else
			{
				/* DO NOTHING - stays in same state */
			}

		break;
		case MSA_RAMP1_HOLDPERC:

			/* Execute state function */
			MSA_State_Ramp1_HoldPerc();

			/* Determine Next State */
			if (MSAVector_Cnt_M_str.Cmd_EngRun == TRUE)
			{
				NextMSAState_Cnt_T_enum = MSA_RAMP4;
			}
			else if (MSAVector_Cnt_M_str.Cmd_StopCmd == TRUE)
			{
				if (MSAVector_Cnt_M_str.AssistEn == FALSE)
				{
					NextMSAState_Cnt_T_enum = MSA_RAMP3_ZEROASSIST_HOLDZERO;
				}
				else
				{
					NextMSAState_Cnt_T_enum = MSA_RAMP2_MSAAMPSHOLD;
				}
			}
			else
			{
				/* Do Nothing - stays in same state */
			}
		break;
		case MSA_RAMP2_MSAAMPSHOLD:

			/* Execute state function */
			MSA_State_Ramp2_MSAAmpsHold();

			/* Determine Next State */
			if (MSAVector_Cnt_M_str.Cmd_EngRun == TRUE)
			{
				NextMSAState_Cnt_T_enum = MSA_RAMP4;
			}
			else if (MSAVector_Cnt_M_str.TimeExpired == TRUE)
			{
				NextMSAState_Cnt_T_enum = MSA_RAMP3_ZEROASSIST_HOLDZERO;
			}
			else
			{
				/* Do Nothing- Stays in same state */
			}


		break;
		case MSA_RAMP3_ZEROASSIST_HOLDZERO:

			/* Execute state function */
			MSA_State_Ramp3_ZeroAssist_HoldZero();

			/* Determine Next State */
			if (MSAVector_Cnt_M_str.Cmd_EngRun == TRUE)
			{
				NextMSAState_Cnt_T_enum = MSA_RAMP4;
			}
			else
			{
				/* Do Nothing- Stays in same state */
			}


		break;
		case MSA_RAMP4:

			/* Execute state function */
			MSA_State_Ramp4();

			/* Determine Next State */
			if (MSAVector_Cnt_M_str.Ramp4Complete == TRUE)
			{
				NextMSAState_Cnt_T_enum = MSA_NORMAL_OP;
			}
			else
			{
				/* Do Nothing- Stays in same state */
			}


		break;
		default:
			NextMSAState_Cnt_T_enum = MSA_NORMAL_OP;
		break;
	}

	/* Update previous values for next run */
	PrevTMSAClock_Sec_M_f32 = TMSAClock_Sec_M_f32;
	PrevMSACurrLimit_Amps_M_f32 = MSACurrLimit_Amps_M_f32;
	PrevCCLTrqRamp_Uls_M_f32 = CCLTrqRamp_Uls_M_f32;

	/* Update next state */
	PresentMSAState_Cnt_M_enum = NextMSAState_Cnt_T_enum;

	/* Update Display variables */
	MSAAssistEnable_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.AssistEn;
	Ramp1Complete_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.Ramp1Complete;
	Ramp2Complete_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.Ramp2Complete;
	Ramp3Complete_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.Ramp3Complete;
	Ramp4Complete_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.Ramp4Complete;
	SCRampUpComplete_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.SCRampUpComplete;
	TrqRampDnComplete_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.TrqRampDnComplete;
	TrqRampUpComplete_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.TrqRampUpComplete;
	TMSAExpired_Cnt_D_lgc = (boolean)MSAVector_Cnt_M_str.TimeExpired;

	return;
}



/* ********* MSA Supporting Functions ********* */


/******************************************************************************
 *	Function Name: 	   MSA_State_NormalOp
 *
 *	Description:       Normal operation state processing.
 *
 *	Inputs:		       N/A
 *
 *	Outputs:	       N/A
 *
 ******************************************************************************/
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_NormalOp(void)
{
	MSACurrLimit_Amps_M_f32 = MSAImax_Amps_M_f32;
	CCLMSAActive_Cnt_M_lgc = FALSE;
	CCLTrqRamp_Uls_M_f32 = D_ONE_ULS_F32;
	return;
}

/******************************************************************************
 *	Function Name: 	   MSA_State_Init
 *
 *	Description:       Initialization operation state processing.
 *
 *	Inputs:		       N/A
 *
 *	Outputs:	       N/A
 *
 ******************************************************************************/
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Init(void)
{
	MSAVector_Cnt_M_str.Ramp1Complete = FALSE;
	MSAVector_Cnt_M_str.Ramp2Complete = FALSE;
	MSAVector_Cnt_M_str.Ramp3Complete = FALSE;
	MSAVector_Cnt_M_str.TrqRampDnComplete = FALSE;
	MSAVector_Cnt_M_str.Ramp4Complete = FALSE;
	MSAVector_Cnt_M_str.TrqRampUpComplete = FALSE;
	MSAVector_Cnt_M_str.SCRampUpComplete = FALSE;
	MSAVector_Cnt_M_str.TimeExpired = FALSE;

	PrevTMSAClock_Sec_M_f32 = k_tMSAClock_Sec_f32;
	TMSAClock_Sec_M_f32 = k_tMSAClock_Sec_f32;
	CCLMSAActive_Cnt_M_lgc = TRUE;

	Ramp1Dec_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp1Time_Sec_f32;
	Ramp2Dec_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp2Time_Sec_f32;
	Ramp4Inc_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp4Time_Sec_f32;

	if (MSAVector_Cnt_M_str.AssistEn == TRUE)
	{
		Ramp3Dec_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp3AsstEn_Sec_f32;
		TrqRampDec_Uls_M_f32 = k_TLoopMSA_Sec_f32 / k_CCLTrqRampDecAsstEn_Sec_f32;
	}
	else
	{
		Ramp3Dec_Amps_M_f32 = (k_TLoopMSA_Sec_f32 * MSAImax_Amps_M_f32) / k_MSARamp3AsstDis_Sec_f32;
		TrqRampDec_Uls_M_f32 = k_TLoopMSA_Sec_f32 / k_CCLTrqRampDecAsstDis_Sec_f32;
	}

	TrqRampInc_Uls_M_f32 = k_TLoopMSA_Sec_f32 / k_CCLTrqRampInc_Sec_f32;

	return;
}

/******************************************************************************
 *	Function Name: 	   MSA_State_Ramp1_HoldPerc
 *
 *	Description:       Ramp1 & Hold Percent operation state processing.
 *
 *	Inputs:		       N/A
 *
 *	Outputs:	       N/A
 *
 ******************************************************************************/
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Ramp1_HoldPerc(void)
{
	if (PrevMSACurrLimit_Amps_M_f32 > Thresh1_Amps_M_f32)
	{
		MSACurrLimit_Amps_M_f32 = PrevMSACurrLimit_Amps_M_f32 - Ramp1Dec_Amps_M_f32;

		if (MSACurrLimit_Amps_M_f32 <= Thresh1_Amps_M_f32)
		{
			MSACurrLimit_Amps_M_f32 = Thresh1_Amps_M_f32;
			MSAVector_Cnt_M_str.Ramp1Complete = TRUE;
		}
	}
	else
	{
		MSACurrLimit_Amps_M_f32 = Thresh1_Amps_M_f32;
		MSAVector_Cnt_M_str.Ramp1Complete = TRUE;
	}

	return;
}

/******************************************************************************
 *	Function Name: 	   MSA_State_Ramp2_MSAAmpsHold
 *
 *	Description:       Ramp2 & Hold MSA Amps operation state processing.
 *
 *	Inputs:		       N/A
 *
 *	Outputs:	       N/A
 *
 ******************************************************************************/
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Ramp2_MSAAmpsHold(void)
{
	if (MSAVector_Cnt_M_str.Ramp2Complete == FALSE)
	{
		if (PrevMSACurrLimit_Amps_M_f32 > k_ILimitThresh2_Amps_f32)
		{
			MSACurrLimit_Amps_M_f32 = PrevMSACurrLimit_Amps_M_f32 - Ramp2Dec_Amps_M_f32;

			if (MSACurrLimit_Amps_M_f32 <= k_ILimitThresh2_Amps_f32)
			{
				MSACurrLimit_Amps_M_f32 = k_ILimitThresh2_Amps_f32;
				MSAVector_Cnt_M_str.Ramp2Complete = TRUE;
			}
		}
		else
		{
			MSACurrLimit_Amps_M_f32 = k_ILimitThresh2_Amps_f32;
			MSAVector_Cnt_M_str.Ramp2Complete = TRUE;
		}
	}
	else
	{
		MSACurrLimit_Amps_M_f32 = PrevMSACurrLimit_Amps_M_f32;
		if (MSAVector_Cnt_M_str.Cmd_StartAnnoun == FALSE)
		{
			TMSAClock_Sec_M_f32 = PrevTMSAClock_Sec_M_f32 - k_TLoopMSA_Sec_f32;

			if (TMSAClock_Sec_M_f32 <= D_ZERO_ULS_F32)
			{
				TMSAClock_Sec_M_f32 = D_ZERO_ULS_F32;
				MSAVector_Cnt_M_str.TimeExpired = TRUE;
			}
		}
	}

	return;
}

/******************************************************************************
 *	Function Name: 	   MSA_State_Ramp3_ZeroAssist_HoldZero
 *
 *	Description:       Ramp3 & Hold Zero operation state processing.
 *
 *	Inputs:		       N/A
 *
 *	Outputs:	       N/A
 *
 ******************************************************************************/
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Ramp3_ZeroAssist_HoldZero(void)
{
	if (MSAVector_Cnt_M_str.Ramp3Complete == FALSE)
	{
		if (MSAVector_Cnt_M_str.Cmd_StartAnnoun == TRUE)
		{
			MSACurrLimit_Amps_M_f32 = PrevMSACurrLimit_Amps_M_f32;
		}
		else
		{
			MSACurrLimit_Amps_M_f32 = PrevMSACurrLimit_Amps_M_f32 - Ramp3Dec_Amps_M_f32;

			if (MSACurrLimit_Amps_M_f32 <= D_ZERO_ULS_F32)
			{
				MSACurrLimit_Amps_M_f32 = D_ZERO_ULS_F32;
				MSAVector_Cnt_M_str.Ramp3Complete = TRUE;
			}
		}
	}
	else
	{
		MSACurrLimit_Amps_M_f32 = D_ZERO_ULS_F32;
	}

	if (MSAVector_Cnt_M_str.TrqRampDnComplete == FALSE)
	{
		if (MSAVector_Cnt_M_str.Cmd_StartAnnoun == TRUE)
		{
			CCLTrqRamp_Uls_M_f32 = PrevCCLTrqRamp_Uls_M_f32;
		}
		else
		{
			CCLTrqRamp_Uls_M_f32 = PrevCCLTrqRamp_Uls_M_f32 - TrqRampDec_Uls_M_f32;

			if (CCLTrqRamp_Uls_M_f32 <= D_ZERO_ULS_F32)
			{
				CCLTrqRamp_Uls_M_f32 = D_ZERO_ULS_F32;
				MSAVector_Cnt_M_str.TrqRampDnComplete = TRUE;
			}
		}
	}
	else
	{
		CCLTrqRamp_Uls_M_f32 = D_ZERO_ULS_F32;
	}

	return;
}

/******************************************************************************
 *	Function Name: 	   MSA_State_Ramp4
 *
 *	Description:       Ramp4 operation state processing.
 *
 *	Inputs:		       N/A
 *
 *	Outputs:	       N/A
 *
 ******************************************************************************/
STATIC FUNC(void, AP_CUSTPL_CODE) MSA_State_Ramp4(void)
{
	MSACurrLimit_Amps_M_f32 = PrevMSACurrLimit_Amps_M_f32 + Ramp4Inc_Amps_M_f32;
	CCLTrqRamp_Uls_M_f32 = PrevCCLTrqRamp_Uls_M_f32 + TrqRampInc_Uls_M_f32;

	if (CCLTrqRamp_Uls_M_f32 >= D_ONE_ULS_F32)
	{
		CCLTrqRamp_Uls_M_f32 = D_ONE_ULS_F32;
		MSAVector_Cnt_M_str.TrqRampUpComplete = TRUE;
	}

	if (MSACurrLimit_Amps_M_f32 >= MSAImax_Amps_M_f32)
	{
		MSACurrLimit_Amps_M_f32 = MSAImax_Amps_M_f32;
		MSAVector_Cnt_M_str.SCRampUpComplete = TRUE;
	}

	if ( (MSAVector_Cnt_M_str.TrqRampUpComplete == TRUE) && 
	     (MSAVector_Cnt_M_str.SCRampUpComplete == TRUE) )
	{
		MSAVector_Cnt_M_str.Ramp4Complete = TRUE;
	}

	return;
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
