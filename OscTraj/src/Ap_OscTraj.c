/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_OscTraj.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/OscTraj-nzt9hv/OscTraj/autosar
 *     SW-C Type:  Ap_OscTraj
 *  Generated at:  Fri Sep 21 17:28:10 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_OscTraj>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Dec 20 09:36:19 2011
 * %version:          6 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Fri Sep 21 16:28:04 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/20/11   1       JJW       Initial Component Creation
 * 11/20/11   1.0     BG        Initial Release - FDD Rev 001
 * 01/11/12   2.0     BG        Updated for 001A changes and added serial communication interface functions
 * 01/11/12   3.0     BG        Updated for 002A changes for SER services
 * 09/21/12	  4.0     Selva		Checkpoints and memmap statements corrected	
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_OscTraj.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_OscTraj_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "fixmath.h"

#define OSCTRAJMINCYCLES_CNT_U08	1U
#define OSCTRAJMINAMP_HWDEG_F32  	0.0F

#define OSCTRAJ_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC VAR(float32, AP_OSCTRAJ_VAR_NOINIT) Amplitude_HwDeg_M_f32;
STATIC VAR(float32, AP_OSCTRAJ_VAR_NOINIT) Frequency_Hz_M_f32;
STATIC VAR(float32, AP_OSCTRAJ_VAR_NOINIT) AmpInit_HwDeg_M_f32;
STATIC VAR(float32, AP_OSCTRAJ_VAR_NOINIT) FreqInit_Hz_M_f32;
STATIC VAR(float32, AP_OSCTRAJ_VAR_NOINIT) PosInit_HwDeg_M_f32;
STATIC VAR(float32, AP_OSCTRAJ_VAR_NOINIT) StateTime_Sec_M_f32;
#define OSCTRAJ_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define OSCTRAJ_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
STATIC VAR(uint8, AP_OSCTRAJ_VAR_NOINIT) Cycles_Cnt_M_u08;
STATIC VAR(uint8, AP_OSCTRAJ_VAR_NOINIT) CyclesInit_Cnt_M_u08;
#define OSCTRAJ_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define OSCTRAJ_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
STATIC VAR(boolean, AP_OSCTRAJ_VAR_NOINIT) CalcFlag_Cnt_M_lgc;

#define OSCTRAJ_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define OSCTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(OscTrajCmdStateType, AP_OSCTRAJ_VAR_NOINIT) CmdState_Cnt_M_enum;
#define OSCTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

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
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * OscTrajCmdStateType: Enumeration of integer in interval [0...2] with enumerators
 *   CMD_STATE0 (0u)
 *   CMD_STATE1 (1u)
 *   CMD_STATE2 (2u)
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
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_OSCTRAJ_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OscTraj_Per1
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
 *   Boolean Rte_IRead_OscTraj_Per1_CalculateFlag_Cnt_lgc(void)
 *   Float Rte_IRead_OscTraj_Per1_HwPos_HwDeg_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_OscTraj_Per1_OscTrajState_Cnt_enum(OscTrajCmdStateType data)
 *   OscTrajCmdStateType *Rte_IWriteRef_OscTraj_Per1_OscTrajState_Cnt_enum(void)
 *   void Rte_IWrite_OscTraj_Per1_OscillateHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_OscTraj_Per1_OscillateHwAngle_HwDeg_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_OSCTRAJ_APPL_CODE) OscTraj_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OscTraj_Per1
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) CalcFlag_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) Amplitude_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) Frequency_Hz_T_f32;
	VAR(uint8, AUTOMATIC) Cycles_Cnt_T_u08;
	VAR(float32, AUTOMATIC) HwPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) Pos_HwDeg_T_f32;
	VAR(OscTrajCmdStateType, AUTOMATIC) CmdState_Cnt_T_enum;
	VAR(float32, AUTOMATIC) OscHwAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) DeltaTime_Sec_T_f32;
	VAR(float32, AUTOMATIC) ScaleFactor_Sec_T_f32;
    /* Configurable Start of Runnable Checkpoint */
	Rte_Call_OscTraj_Per1_CP0_CheckpointReached();
	/* Read Inputs */
	HwPos_HwDeg_T_f32 = Rte_IRead_OscTraj_Per1_HwPos_HwDeg_f32();
	CalcFlag_Cnt_T_lgc = Rte_IRead_OscTraj_Per1_CalculateFlag_Cnt_lgc();
	
	/* Update Inputs on a raising edge */
	if((!CalcFlag_Cnt_M_lgc) && CalcFlag_Cnt_T_lgc)
	{
		Amplitude_HwDeg_T_f32 = Amplitude_HwDeg_M_f32;
		Frequency_Hz_T_f32 = Frequency_Hz_M_f32;
		Cycles_Cnt_T_u08 = Cycles_Cnt_M_u08;
		Pos_HwDeg_T_f32 =  HwPos_HwDeg_T_f32;

		/* Update Module level variables for next cycle*/
		AmpInit_HwDeg_M_f32 = Amplitude_HwDeg_T_f32;
		FreqInit_Hz_M_f32 = Frequency_Hz_T_f32;
		CyclesInit_Cnt_M_u08 = Cycles_Cnt_T_u08;
		PosInit_HwDeg_M_f32 = Pos_HwDeg_T_f32;
	}
	else
	{
		/* Use the previous values for variables */
		Amplitude_HwDeg_T_f32 = AmpInit_HwDeg_M_f32;
		Frequency_Hz_T_f32 = FreqInit_Hz_M_f32;
		Cycles_Cnt_T_u08 = CyclesInit_Cnt_M_u08;
		Pos_HwDeg_T_f32 = PosInit_HwDeg_M_f32;
	}
	
   /* Apply limit on inputs */
	Amplitude_HwDeg_T_f32 = Limit_m(Amplitude_HwDeg_T_f32, OSCTRAJMINAMP_HWDEG_F32, k_OscTrajMaxAmp_HwDeg_f32);
	Frequency_Hz_T_f32 = Limit_m(Frequency_Hz_T_f32, k_OscTrajMinFreq_Hz_f32 , k_OscTrajMaxFreq_Hz_f32);
	Cycles_Cnt_T_u08 = Limit_m(Cycles_Cnt_T_u08, OSCTRAJMINCYCLES_CNT_U08 , k_OscTrajMaxCycles_Cnt_u08);

	/* Calculate Current Cmd State */
	if(TRUE == CalcFlag_Cnt_T_lgc)
	{
		CmdState_Cnt_T_enum = CmdState_Cnt_M_enum;
	}
	else
	{
		CmdState_Cnt_T_enum = CMD_STATE0;
	}

	switch(CmdState_Cnt_T_enum)
	{

		case CMD_STATE1:
            DeltaTime_Sec_T_f32 = (float32) Cycles_Cnt_T_u08/Frequency_Hz_T_f32;
			
			if ((DeltaTime_Sec_T_f32 * 0.5F) > StateTime_Sec_M_f32)
			{
				ScaleFactor_Sec_T_f32 = StateTime_Sec_M_f32 / (DeltaTime_Sec_T_f32 * 0.5F);
			}
			else
			{
				ScaleFactor_Sec_T_f32 = 2.0F - (StateTime_Sec_M_f32 / (DeltaTime_Sec_T_f32 * 0.5F));
			}

			OscHwAngle_HwDeg_T_f32 = Pos_HwDeg_T_f32 + (ScaleFactor_Sec_T_f32 * Amplitude_HwDeg_T_f32 * sinf(D_2PI_ULS_F32 * Frequency_Hz_T_f32 * StateTime_Sec_M_f32));
			StateTime_Sec_M_f32 = StateTime_Sec_M_f32 + D_2MS_SEC_F32;

			if (DeltaTime_Sec_T_f32 < StateTime_Sec_M_f32)
			{
				CmdState_Cnt_T_enum = CMD_STATE2;
			}
			else
			{
				CmdState_Cnt_T_enum = CMD_STATE1;
			}
			break;

		case CMD_STATE2:
			
			CmdState_Cnt_T_enum = CMD_STATE2;
 			StateTime_Sec_M_f32 = D_ZERO_ULS_F32;
			OscHwAngle_HwDeg_T_f32 = HwPos_HwDeg_T_f32;
			break;

		 default:
			if(TRUE == CalcFlag_Cnt_T_lgc)
			{
				CmdState_Cnt_T_enum = CMD_STATE1;
			}
			else
			{
				CmdState_Cnt_T_enum = CMD_STATE0;
			} 
			StateTime_Sec_M_f32 = D_ZERO_ULS_F32;
			OscHwAngle_HwDeg_T_f32 = HwPos_HwDeg_T_f32;
			break;
	}


	/* Update Module Level Variables */
	CalcFlag_Cnt_M_lgc = CalcFlag_Cnt_T_lgc;
	CmdState_Cnt_M_enum = CmdState_Cnt_T_enum;

	/* Update Module Outputs */
	Rte_IWrite_OscTraj_Per1_OscTrajState_Cnt_enum(CmdState_Cnt_T_enum);
	Rte_IWrite_OscTraj_Per1_OscillateHwAngle_HwDeg_f32(OscHwAngle_HwDeg_T_f32);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_OscTraj_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OscTraj_SCom_SetInputParams
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetInputParams> of PortPrototype <OscTraj_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_OSCTRAJ_APPL_CODE) OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OscTraj_SCom_SetInputParams
 *********************************************************************************************************************/
	Amplitude_HwDeg_M_f32 = Amplitude_HwDeg_f32;
	Cycles_Cnt_M_u08 = Cycles_Cnt_u08;
	Frequency_Hz_M_f32 = Frequency_Hz_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_OSCTRAJ_APPL_CODE
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
