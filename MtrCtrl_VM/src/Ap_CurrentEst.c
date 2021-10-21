/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_CurrentEst.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_CurrentEst
 *  Generated at:  Fri Apr 12 01:15:38 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_CurrentEst>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          19 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Fri Apr 12 14:44:25 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/26/11   7       JJW       System Framework Update
 * 03/26/11   8       JJW       Change EcuVoltage Read to buffered
 * 03/26/11   9       JJW       BattSwitched change to EcuVoltage
 * 03/28/11  10       JJW       EcuVoltage changed to Vecu
 * 06/03/11  11       LWW       Updated comments for mode disabling
 * 12/01/11	 12		  KJS		Created component based on SF-99. Updated entire source file. 
 * 01/19/12  14		  KJS		Changed Iq_est to a signed number instead of unsigned (Anomaly 2814)			4823
 * 10/26/12	 17       Selva		 Integration in MtrCtrl_VM (Refer FDD 06B Ver 4)
 * 2/2/13	 18       Selva		 Updated for MtrCtrl_VM version 7
 * 4/12/13	 19	      Selva		 Updated for MtrCtrl_VM version 9
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Vecu_Volt_f32
    This port prototype is inteded to communicate voltage signals that represent the ecu supplied voltage.  This signal has a lower limit, which is non-zero, to allow users of the signal to use it as a denominator in an expression without requiring a divide by 0 check.


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_CurrentEst.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "filters.h"
#include "Ap_CurrentEst_Cfg.h"

#define D_ESTDAXCURRLOLMT_AMP_F32			(-250.0F)
#define D_ESTDAXCURRHILMT_AMP_F32			250.0F

#define D_ESTPKCURRLOLMT_AMPSQ_F32			0.0F
#define D_ESTPKCURRHILMT_AMPSQ_F32			62500.0F

#define D_ESTQAXCURRLOLMT_AMP_F32			(-250.0F)
#define D_ESTQAXCURRHILMT_AMP_F32			250.0F

#define D_TWOOVERSQRT3_ULS_F32				1.154700538379F

#define D_MINVECU_VOLT_F32                 5.0F
#define D_MAXVECU_VOLT_F32                 31.0F

#define CURRENTEST_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(sint32, AUTOMATIC) DaxCurrFiltSV_Amp_M_s11p20;
STATIC VAR(sint32, AUTOMATIC) QaxCurrFiltSV_Amp_M_s11p20;
STATIC VAR(uint32, AUTOMATIC) EstPkCurrFiltSV_AmpSq_M_u16p16;

/* Display variables */
STATIC volatile VAR(float32, AUTOMATIC) MtrCurEst_Id_Amp_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) FiltMtrCurEst_Iq_Amp_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) FiltMtrCurEst_Id_Amp_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) MtrCurEst_Iq_AmpSq_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) MtrCurEst_Id_AmpSq_D_f32;
#define CURRENTEST_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */

											
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
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
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
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * Float: D_ZERO_ULS_F32 = 0
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3u
 * UInt8: D_QUADRANT1_CNT_U8 = 1u
 * UInt8: D_QUADRANT2_CNT_U8 = 2u
 * UInt8: D_QUADRANT3_CNT_U8 = 3u
 * UInt8: D_QUADRANT4_CNT_U8 = 4u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_CURRENTEST_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrentEst_Per1
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
 *   Float Rte_IRead_CurrentEst_Per1_EstR_Ohm_f32(void)
 *   Float Rte_IRead_CurrentEst_Per1_ExpIq_Amp_f32(void)
 *   Float Rte_IRead_CurrentEst_Per1_ModIdx_Uls_f32(void)
 *   Float Rte_IRead_CurrentEst_Per1_TermXq_Uls_f32(void)
 *   SInt16 Rte_IRead_CurrentEst_Per1_UncorrPhsAdv_Cnt_s16(void)
 *   Float Rte_IRead_CurrentEst_Per1_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(Float data)
 *   Float *Rte_IWriteRef_CurrentEst_Per1_EstPkCurr_AmpSq_f32(void)
 *   void Rte_IWrite_CurrentEst_Per1_IdEst_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CurrentEst_Per1_IdEst_Amp_f32(void)
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
 * Inter Runnable Variables:
 * =========================
 *   Implicit Write Access:
 *   ----------------------
 *   void Rte_IrvIWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(Float data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRENTEST_APPL_CODE) CurrentEst_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CurrentEst_Per1
 *********************************************************************************************************************/
/* inputs */
	VAR(float32, AUTOMATIC) Vecu_Volts_T_f32;
	VAR(float32, AUTOMATIC) ModIdx_Uls_T_f32;
	VAR(float32, AUTOMATIC) EstR_Ohm_T_f32;
	VAR(float32, AUTOMATIC) EstMtrCurrQax_Amp_T_f32;
	VAR(float32, AUTOMATIC) TermXq_Uls_T_f32;
	VAR(sint16, AUTOMATIC) 	UncorrPhsAdv_Cnt_T_s16;
	
	/* outputs */
	VAR(float32, AUTOMATIC) EstPkCurr_AmpSq_T_f32;
	
	/* internal vars */
	VAR(sint16, AUTOMATIC) EstMtrCurrQax_Amp_T_s11p4;
	VAR(sint16, AUTOMATIC) FiltQaxCurr_Amp_T_s11p4;
	VAR(float32, AUTOMATIC) FiltQaxCurr_Amp_T_f32;
	VAR(float32, AUTOMATIC) SinPhaseAdv_Uls_T_f32;
	VAR(float32, AUTOMATIC) EstMtrCurrDax_Amp_T_f32;
	VAR(sint16, AUTOMATIC) EstMtrCurrDax_Amp_T_s11p4;
	VAR(sint16, AUTOMATIC) FiltDaxCurr_Amp_T_s11p4;
	VAR(float32, AUTOMATIC) FiltDaxCurr_Amp_T_f32;
	VAR(float32, AUTOMATIC) QaxCurrSqr_AmpSq_T_f32;
	VAR(float32, AUTOMATIC) DaxCurrSqr_AmpSq_T_f32;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) CurrentSysState_Cnt_T_enum;
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_CurrentEst_Per1_CP0_CheckpointReached();
	
	CurrentSysState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	
	if (CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_WARMINIT)
	{
	EstPkCurr_AmpSq_T_f32 = D_ZERO_ULS_F32;
	EstMtrCurrDax_Amp_T_f32 =D_ZERO_ULS_F32;
	}
	
	else
	{
	Vecu_Volts_T_f32 = Rte_IRead_CurrentEst_Per1_Vecu_Volt_f32();
	ModIdx_Uls_T_f32 = Rte_IRead_CurrentEst_Per1_ModIdx_Uls_f32();
	EstR_Ohm_T_f32 = Rte_IRead_CurrentEst_Per1_EstR_Ohm_f32();
	EstMtrCurrQax_Amp_T_f32 = Rte_IRead_CurrentEst_Per1_ExpIq_Amp_f32();
	TermXq_Uls_T_f32 = Rte_IRead_CurrentEst_Per1_TermXq_Uls_f32();
	UncorrPhsAdv_Cnt_T_s16 = Rte_IRead_CurrentEst_Per1_UncorrPhsAdv_Cnt_s16();
	
	/***Limit Vecu Volt***/
	Vecu_Volts_T_f32 = Limit_m(Vecu_Volts_T_f32,D_MINVECU_VOLT_F32,D_MAXVECU_VOLT_F32);
	/*** Estimate Iq ***/
	EstMtrCurrQax_Amp_T_s11p4 = FPM_FloatToFixed_m(EstMtrCurrQax_Amp_T_f32, s11p4_T);
	
	/*** Anti Alisaing Filter on EstimatedIq ***/	
	QaxCurrFiltSV_Amp_M_s11p20 = LPF_SvUpdate_s16InFixKTrunc_m(	EstMtrCurrQax_Amp_T_s11p4,
                                      							QaxCurrFiltSV_Amp_M_s11p20, 
                                      							k_EstPkCurr2msLPFKn_Uls_u16);
                                      							
	
    FiltQaxCurr_Amp_T_s11p4 = LPF_OpUpdate_s16InFixKTrunc_m(QaxCurrFiltSV_Amp_M_s11p20); 
   	FiltQaxCurr_Amp_T_f32 = FPM_FixedToFloat_m(FiltQaxCurr_Amp_T_s11p4, s11p4_T);

	/*** Estimate Id ***/
    SinPhaseAdv_Uls_T_f32 = (float32)Sign_s16_m(UncorrPhsAdv_Cnt_T_s16) * T_SINELKPTBL_ULS_F32[(Abs_s16_m(UncorrPhsAdv_Cnt_T_s16))]; 
    EstMtrCurrDax_Amp_T_f32 = (TermXq_Uls_T_f32 * EstMtrCurrQax_Amp_T_f32) - ((Vecu_Volts_T_f32 * ModIdx_Uls_T_f32 * SinPhaseAdv_Uls_T_f32 * D_TWOOVERSQRT3_ULS_F32) / EstR_Ohm_T_f32);
   
	EstMtrCurrDax_Amp_T_f32 = Limit_m(EstMtrCurrDax_Amp_T_f32, D_ESTDAXCURRLOLMT_AMP_F32, D_ESTDAXCURRHILMT_AMP_F32);
	EstMtrCurrDax_Amp_T_s11p4 = FPM_FloatToFixed_m(EstMtrCurrDax_Amp_T_f32, s11p4_T);
	/*** Anti Alisaing Filter on EstimatedId ***/
	DaxCurrFiltSV_Amp_M_s11p20 = LPF_SvUpdate_s16InFixKTrunc_m(	EstMtrCurrDax_Amp_T_s11p4,
                                      							DaxCurrFiltSV_Amp_M_s11p20, 
                                      							k_EstPkCurr2msLPFKn_Uls_u16);
                                      							
    FiltDaxCurr_Amp_T_s11p4 = (sint16)LPF_OpUpdate_s16InFixKTrunc_m(DaxCurrFiltSV_Amp_M_s11p20); 
   	FiltDaxCurr_Amp_T_f32 = FPM_FixedToFloat_m(FiltDaxCurr_Amp_T_s11p4, s11p4_T);     
   	/*** Peak Current Square Estimatimation ***/
   	QaxCurrSqr_AmpSq_T_f32 = FiltQaxCurr_Amp_T_f32 * FiltQaxCurr_Amp_T_f32;
   	DaxCurrSqr_AmpSq_T_f32 = FiltDaxCurr_Amp_T_f32 * FiltDaxCurr_Amp_T_f32;
   	
   	EstPkCurr_AmpSq_T_f32 = QaxCurrSqr_AmpSq_T_f32 + DaxCurrSqr_AmpSq_T_f32;                      								
	EstPkCurr_AmpSq_T_f32 = Limit_m(EstPkCurr_AmpSq_T_f32, D_ESTPKCURRLOLMT_AMPSQ_F32, D_ESTPKCURRHILMT_AMPSQ_F32);

	/* Update display variables */
	MtrCurEst_Id_Amp_D_f32 = EstMtrCurrDax_Amp_T_f32;
	FiltMtrCurEst_Iq_Amp_D_f32 = FiltQaxCurr_Amp_T_f32;
	FiltMtrCurEst_Id_Amp_D_f32 = FiltDaxCurr_Amp_T_f32;
	MtrCurEst_Iq_AmpSq_D_f32 = QaxCurrSqr_AmpSq_T_f32;
	MtrCurEst_Id_AmpSq_D_f32 = DaxCurrSqr_AmpSq_T_f32;
	}
	/* Update outputs */
	Rte_IWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(EstPkCurr_AmpSq_T_f32);
	Rte_IrvIWrite_CurrentEst_Per1_EstPkCurr_AmpSq_f32(EstPkCurr_AmpSq_T_f32);
	Rte_IWrite_CurrentEst_Per1_IdEst_Amp_f32(EstMtrCurrDax_Amp_T_f32);
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_CurrentEst_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrentEst_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *     and not in Mode(s) <WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32(Float data)
 *   Float *Rte_IWriteRef_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32(void)
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
 * Inter Runnable Variables:
 * =========================
 *   Implicit Read Access:
 *   ---------------------
 *   Float Rte_IrvIRead_CurrentEst_Per2_EstPkCurr_AmpSq_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRENTEST_APPL_CODE) CurrentEst_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CurrentEst_Per2
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) EstPkCurr_AmpSq_T_f32;
	VAR(uint16, AUTOMATIC) 	EstPkCurr_AmpSq_T_u16p0;
	VAR(uint16, AUTOMATIC)	FiltEstPkCurr_AmpSq_T_u16p0;
	VAR(float32, AUTOMATIC) FiltEstPkCurr_AmpSq_T_f32;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) CurrentSysState_Cnt_T_enum;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_CurrentEst_Per2_CP0_CheckpointReached();
	CurrentSysState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	if (CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_WARMINIT)
	{
		FiltEstPkCurr_AmpSq_T_f32 = D_ZERO_ULS_F32;
	}
	else
	{
		EstPkCurr_AmpSq_T_f32 = Rte_IrvIRead_CurrentEst_Per2_EstPkCurr_AmpSq_f32();
		EstPkCurr_AmpSq_T_u16p0 = FPM_FloatToFixed_m(EstPkCurr_AmpSq_T_f32, u16p0_T);
		
		EstPkCurrFiltSV_AmpSq_M_u16p16 = LPF_SvUpdate_u16InFixKTrunc_m(	EstPkCurr_AmpSq_T_u16p0,
																		EstPkCurrFiltSV_AmpSq_M_u16p16, 
																		k_EstPkCurrSlowLoopLPFKn_Uls_u16);
																		
		FiltEstPkCurr_AmpSq_T_u16p0 = (uint16)LPF_OpUpdate_u16InFixKTrunc_m(EstPkCurrFiltSV_AmpSq_M_u16p16);
		
		FiltEstPkCurr_AmpSq_T_f32 = FPM_FixedToFloat_m(FiltEstPkCurr_AmpSq_T_u16p0, u16p0_T);

		FiltEstPkCurr_AmpSq_T_f32 = Limit_m(FiltEstPkCurr_AmpSq_T_f32, D_ESTPKCURRLOLMT_AMPSQ_F32, D_ESTPKCURRHILMT_AMPSQ_F32);
	}
	
	Rte_IWrite_CurrentEst_Per2_FiltEstPkCurr_AmpSq_f32(FiltEstPkCurr_AmpSq_T_f32);

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_CurrentEst_Per2_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_CURRENTEST_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
