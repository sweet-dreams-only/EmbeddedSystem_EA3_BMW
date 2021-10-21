/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_ElecPwr.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/ElecPwr-nzt9hv/ElecPwr/autosar
 *     SW-C Type:  Ap_ElecPwr
 *  Generated at:  Wed Feb  6 13:14:08 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_ElecPwr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          14 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Wed Feb  6 13:12:02 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/24/11   3       JJW       Changed to buffered R/W access
 * 03/25/11   4       JJW       Added divide by zero protection by Limiting EcuVoltage minimum
 * 03/28/11   6       JJW       Changed EcuVoltage to Vecu and removed local limiting due to global limiting
 * 06/06/11	  7		  SAH		Applied sign of phase advance when calculating intermediate terms for input power.
 * 06/06/11	  8		  JJW		Changed D_ELECPOWERLOWLMT_WATTS_F32 to -1400
 * 12/20/11   10	  KJS		Component based design release.													3945
 * 04/13/12   11	  JJW		Corrected Rte Port usage to align with core design.  Volts to Volt unit change
 * 09/16/12   12	  BWL		Added watchdog checkpoints.														6222
 * 02/06/13	  13      Selva		Updated to version 6 SF-08	
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
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

  Volt_f32 of Port Interface Vecu_Volt_f32
    This port prototype is inteded to communicate voltage signals that represent the ecu supplied voltage.  This signal has a lower limit, which is non-zero, to allow users of the signal to use it as a denominator in an expression without requiring a divide by 0 check.


 Runnable Entities:
 ==================
  ElecPwr_Per1
    This module performs a battery load estimation function.

 *********************************************************************************************************************/

#include "Rte_Ap_ElecPwr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "fixmath.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "filters.h"
#include "Ap_ElecPwr_Cfg.h"

#define D_ELECPOWERLOWLMT_WATTS_F32			-1400.0f
#define D_ELECPOWERHIGHLMT_WATTS_F32		1400.0f

#define ELECPWR_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT)	ModInPower_Watts_D_f32;
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT)	ElecMtrCmd_Volt_D_f32;
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT)	TermZ_Uls_D_f32;
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT) TrigTermSin_Uls_D_f32;
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT) TrigTermCos_Uls_D_f32;
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT) TrigTerm_Uls_D_f32;
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT) DropInPower_Watts_D_f32;
#define ELECPWR_STOP_SEC_VAR_CLEARED_32
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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
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
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * Float: D_ZERO_ULS_F32 = 0
 * SInt16: D_ZERO_CNT_S16 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_ELECPWR_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ElecPwr_Per1
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
 *   Float Rte_IRead_ElecPwr_Per1_EstR_Ohm_f32(void)
 *   Float Rte_IRead_ElecPwr_Per1_ModIdx_Uls_f32(void)
 *   Float Rte_IRead_ElecPwr_Per1_TermA_Volt_f32(void)
 *   Float Rte_IRead_ElecPwr_Per1_TermXq_Uls_f32(void)
 *   Float Rte_IRead_ElecPwr_Per1_TermZ_Uls_f32(void)
 *   SInt16 Rte_IRead_ElecPwr_Per1_UncorrPhsAdv_Cnt_s16(void)
 *   Float Rte_IRead_ElecPwr_Per1_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ElecPwr_Per1_ElecPower_Watts_f32(Float data)
 *   Float *Rte_IWriteRef_ElecPwr_Per1_ElecPower_Watts_f32(void)
 *   void Rte_IWrite_ElecPwr_Per1_SupplyCur_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_ElecPwr_Per1_SupplyCur_Amp_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ELECPWR_APPL_CODE) ElecPwr_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ElecPwr_Per1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC)		Vecu_Volt_T_f32;
	VAR(float32, AUTOMATIC)		ModIdx_Uls_T_f32;
	VAR(sint16, AUTOMATIC)		UncorrPhsAdv_Cnt_T_s16;
	VAR(float32, AUTOMATIC)		EstR_Ohm_T_f32;
	
	VAR(uint16, AUTOMATIC)		AbsPhAdv_Cnt_T_u16;
	VAR(float32, AUTOMATIC)		TermA_Uls_T_f32;
	VAR(float32, AUTOMATIC)		TermXq_Uls_T_f32;
	VAR(float32, AUTOMATIC)		TermZ_Uls_T_f32;
	VAR(float32, AUTOMATIC)		TmpDuty_Volt_T_f32;
	VAR(float32, AUTOMATIC)		TrigTerm_Uls_T_f32;
	
	VAR(float32, AUTOMATIC)		Numerator_T_SqVolt_f32;
	VAR(float32, AUTOMATIC)		Denominator_T_Ohms_f32;
	VAR(float32, AUTOMATIC)		Pmod_Watts_T_f32;
	
	VAR(float32, AUTOMATIC)		Icntrlrin_Amp_T_f32;
	VAR(float32, AUTOMATIC)		Pcntrlrin_Watts_T_f32;
	
	VAR(float32, AUTOMATIC)		Ptotal_Watts_T_f32;
	VAR(sint16, AUTOMATIC)		SignPhAdv_T_s16;
	VAR(float32, AUTOMIATC) 	SupplyCurrent_Amp_T_f32;
	VAR(float32, AUTOMATIC)		TrigTermSin_Uls_T_f32;
	VAR(float32, AUTOMATIC)		TrigTermCos_Uls_T_f32;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_ElecPwr_Per1_CP0_CheckpointReached();
		
	/* capture inputs */  
	Vecu_Volt_T_f32 = Rte_IRead_ElecPwr_Per1_Vecu_Volt_f32();
	EstR_Ohm_T_f32 = Rte_IRead_ElecPwr_Per1_EstR_Ohm_f32();
	ModIdx_Uls_T_f32 = Rte_IRead_ElecPwr_Per1_ModIdx_Uls_f32();
	UncorrPhsAdv_Cnt_T_s16 = Rte_IRead_ElecPwr_Per1_UncorrPhsAdv_Cnt_s16();
	TermA_Uls_T_f32 = Rte_IRead_ElecPwr_Per1_TermA_Volt_f32();
	TermXq_Uls_T_f32 = Rte_IRead_ElecPwr_Per1_TermXq_Uls_f32();
	TermZ_Uls_T_f32 = Rte_IRead_ElecPwr_Per1_TermZ_Uls_f32();
	
	/* calculate intermediate terms */
	AbsPhAdv_Cnt_T_u16 = Abs_s16_m(UncorrPhsAdv_Cnt_T_s16);
	SignPhAdv_T_s16 = Sign_s16_m(UncorrPhsAdv_Cnt_T_s16);
	TrigTermSin_Uls_T_f32 = (float32)SignPhAdv_T_s16 * T_SINELKPTBL_ULS_F32[AbsPhAdv_Cnt_T_u16];
	TrigTermCos_Uls_T_f32 = T_SINELKPTBL_ULS_F32[(TableSize_m(T_SINELKPTBL_ULS_F32) - 1) - AbsPhAdv_Cnt_T_u16];
	
	TmpDuty_Volt_T_f32 = Vecu_Volt_T_f32 * ModIdx_Uls_T_f32;
	TrigTerm_Uls_T_f32 = (TermXq_Uls_T_f32 * TrigTermSin_Uls_T_f32  ) - TrigTermCos_Uls_T_f32;
	
	/* calculate modulator input power */
	Numerator_T_SqVolt_f32 = TmpDuty_Volt_T_f32 * (TmpDuty_Volt_T_f32 + (TermA_Uls_T_f32 * TrigTerm_Uls_T_f32));
	Denominator_T_Ohms_f32 = EstR_Ohm_T_f32 * TermZ_Uls_T_f32;
	Pmod_Watts_T_f32 = Numerator_T_SqVolt_f32 / Denominator_T_Ohms_f32;
	
	/* Display variable update */
	ModInPower_Watts_D_f32 = Pmod_Watts_T_f32;
	ElecMtrCmd_Volt_D_f32 = TmpDuty_Volt_T_f32; 
	TermZ_Uls_D_f32 = TermZ_Uls_T_f32;
	TrigTermSin_Uls_D_f32 = TrigTermSin_Uls_T_f32;
	TrigTermCos_Uls_D_f32 = TrigTermCos_Uls_T_f32;
	TrigTerm_Uls_D_f32 = TrigTerm_Uls_T_f32;
	
	
	/* calculate input power drop across input resistance */
	Icntrlrin_Amp_T_f32 = Pmod_Watts_T_f32 / Vecu_Volt_T_f32;

	Pcntrlrin_Watts_T_f32 = (Icntrlrin_Amp_T_f32 * Icntrlrin_Amp_T_f32) * k_CntlrInResist_Ohm_f32;
	
	/* Update display variables */
	DropInPower_Watts_D_f32 = Pcntrlrin_Watts_T_f32;
	
	/* calculate electric power */
	Ptotal_Watts_T_f32 = Pmod_Watts_T_f32 + Pcntrlrin_Watts_T_f32 + k_PstcPowerLoss_Watts_f32;

	Ptotal_Watts_T_f32 = Limit_m(Ptotal_Watts_T_f32, D_ELECPOWERLOWLMT_WATTS_F32, 
													 D_ELECPOWERHIGHLMT_WATTS_F32);
	
	/* calculate supply current */
	SupplyCurrent_Amp_T_f32 = Ptotal_Watts_T_f32 / Vecu_Volt_T_f32;
	
	/* store local copy of outputs into mdoule outputs */
	Rte_IWrite_ElecPwr_Per1_ElecPower_Watts_f32(Ptotal_Watts_T_f32);
	Rte_IWrite_ElecPwr_Per1_SupplyCur_Amp_f32(SupplyCurrent_Amp_T_f32);
	 
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_ElecPwr_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_ELECPWR_APPL_CODE
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
