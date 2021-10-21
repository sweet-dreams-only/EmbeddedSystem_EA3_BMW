/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PhaseCtrl.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_PhaseCtrl
 *  Generated at:  Sat Apr 13 16:57:23 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PhaseCtrl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Thu Apr 26 10:06:09 2012
 * %version:          9 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Mon Apr 15 10:03:46 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/26/12   2       LWW       Correction for anomaly 2990
 * 09/21/12   3       Selva      Checkpoints added and mempmap macros corrected		                          6239
 * 10/26/12	  4       Selva		 Integration in MtrCtrl_VM (Refer FDD 06B Ver 4)
 * 01/25/13	  5       LWW		 Added limit to delta2 solver
 * 01/25/13	  6       LWW		 Fixed indexing issue on atan solver
 * 02/02/13	  7      Selva		 Updated for MtrCtrl_VM FDD99 version 7
 * 4/12/13	  8,9      Selva		 Updated for MtrCtrl_VM version 9
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

 *********************************************************************************************************************/

#include "Rte_Ap_PhaseCtrl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_PhaseCtrl_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include <float.h>
#include "MtrCtrl.h"


#define D_UNCORRPHSADVMAX_CNT_S16			192
#define D_CORRPHSADVSCALE_CNTSPRAD_F32		(6144.0F / D_2PI_ULS_F32)
#define D_MAXDELTAVAL_CNT_U16               192U
#define D_MAXITERATION_CNT_U16            	8U
#define D_DELTABINSRCMIDPT_CNT_U16          96U
#define D_POWERTWOSCALING_CNT_U16	   		2U
#define D_MAXDELTAINDEX_CNT_U16       		192U
#define D_MAXTANDELTALKUP_ULS_F32			244.460629F /* tan(90-0.46875/2) */	

#define PHASECTRL_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC volatile VAR(float32, AP_PHASECTRL_VAR_NOINIT) PhsAdvY_Uls_D_f32;
#define PHASECTRL_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define PHASECTRL_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
STATIC volatile VAR(uint16, AP_PHASECTRL_VAR_NOINIT) Delta1_Cnt_D_u16;
STATIC volatile VAR(sint16, AP_PHASECTRL_VAR_NOINIT) Delta2_Cnt_D_s16;
STATIC volatile VAR(sint16, AP_PHASECTRL_VAR_NOINIT) Delta3_Cnt_D_s16;
STATIC volatile VAR(sint16, AP_PHASECTRL_VAR_NOINIT) PhsOffCorr_Cnt_D_s16;
VAR(sint16, AP_PHASECTRL_VAR_NOINIT) UncorrPhsAdv_Cnt_M_s16;
VAR(sint16, AP_PHASECTRL_VAR_NOINIT) PhsOffCorr_Cnt_M_s16;
#define PHASECTRL_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

STATIC INLINE FUNC(uint16, AP_PHASECTRL_CODE) CalcDelta1(	VAR(float32, AUTOMATIC) TermXq_Uls_T_f32, 
															VAR(float32, AUTOMATIC) TermXd_Uls_T_f32,
															VAR(float32, AUTOMATIC) TermY_Uls_T_f32);
															
STATIC INLINE FUNC(sint16, AP_PHASECTRL_CODE) CalcDelta2(	VAR(float32, AUTOMATIC) TermA_Volt_T_f32, 
															VAR(float32, AUTOMATIC) TermBSS_Volt_T_f32, VAR(float32, AUTOMATIC) TermBTOT_Volt_T_f32,
															VAR(float32, AUTOMATIC) TermXq_Uls_T_f32);

STATIC INLINE FUNC(sint16, AP_PHASECTRL_CODE) CalcDelta3(	VAR(float32, AUTOMATIC) VdTerm_Volt_T_f32,
															VAR(float32, AUTOMATIC) VqTerm_Volt_T_f32);

STATIC FUNC(sint16, AP_PHASECTRL_CODE) PhsAdvArcTan(	VAR(float32, AUTOMATIC) Num_Uls_T_f32, 
														VAR(float32, AUTOMATIC) Den_Uls_T_f32,
														VAR(float32, AUTOMATIC) ArcTanLmt_Uls_T_f32);
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


#define RTE_START_SEC_AP_PHASECTRL_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaseCtrl_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_PhaseCtrl_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *   UInt8 Rte_IRead_PhaseCtrl_Per1_MtrQuad_Cnt_u08(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermA_Volt_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermBSS_Volt_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermBTOT_Volt_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermXd_Uls_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermXq_Uls_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_TermY_Uls_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_VdTerm_Volt_f32(void)
 *   Float Rte_IRead_PhaseCtrl_Per1_VqTerm_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PHASECTRL_APPL_CODE) PhaseCtrl_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PhaseCtrl_Per1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) MRFMtrVel_MtrRadpS_T_f32;
	VAR(uint8, AUTOMATIC) MtrQuad_Cnt_T_u8;
	VAR(sint16, AUTOMATIC) PhsOffCorr_Cnt_T_s16;
	VAR(float32, AUTOMATIC) TermA_Volt_T_f32;
	VAR(float32, AUTOMATIC) TermBSS_Volt_T_f32;

	VAR(float32, AUTOMATIC) TermXq_Uls_T_f32;
	VAR(float32, AUTOMATIC) TermXd_Uls_T_f32;
	VAR(float32, AUTOMATIC) TermY_Uls_T_f32;
	VAR(sint16, AUTOMATIC) UncorrPhsAdv_Cnt_T_s16;
	VAR(uint16, AUTOMATIC) Delta1_Cnt_T_u16;
	VAR(sint16, AUTOMATIC) Delta2_Cnt_T_s16;
	VAR(float32, AUTOMATIC) PhsOffCorr_Cnt_T_f32;
	VAR(float32, AUTOMATIC) PhsAdvY_Uls_T_f32;
	VAR(float32, AUTOMATIC) TermBTOT_Volt_T_f32;

	VAR(float32, AUTOMATIC) VdTerm_Volt_T_f32;
	VAR(float32, AUTOMATIC) VqTerm_Volt_T_f32;
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_PhaseCtrl_Per1_CP0_CheckpointReached();
  
	MRFMtrVel_MtrRadpS_T_f32 = Rte_IRead_PhaseCtrl_Per1_MRFMtrVel_MtrRadpS_f32();
	MtrQuad_Cnt_T_u8 = Rte_IRead_PhaseCtrl_Per1_MtrQuad_Cnt_u08();
	TermA_Volt_T_f32 = Rte_IRead_PhaseCtrl_Per1_TermA_Volt_f32();
	TermBSS_Volt_T_f32 = Rte_IRead_PhaseCtrl_Per1_TermBSS_Volt_f32();

	TermBTOT_Volt_T_f32 = Rte_IRead_PhaseCtrl_Per1_TermBTOT_Volt_f32();
	TermXq_Uls_T_f32 = Rte_IRead_PhaseCtrl_Per1_TermXq_Uls_f32();
	TermXd_Uls_T_f32 = Rte_IRead_PhaseCtrl_Per1_TermXd_Uls_f32();
	TermY_Uls_T_f32 = Rte_IRead_PhaseCtrl_Per1_TermY_Uls_f32();
	VdTerm_Volt_T_f32 = Rte_IRead_PhaseCtrl_Per1_VdTerm_Volt_f32();
	VqTerm_Volt_T_f32 = Rte_IRead_PhaseCtrl_Per1_VqTerm_Volt_f32();
	PhsAdvY_Uls_T_f32 = TermY_Uls_T_f32 * k_TrmYDeadTimeScl_Uls_f32;
	PhsAdvY_Uls_D_f32 = PhsAdvY_Uls_T_f32;

	if ((MtrQuad_Cnt_T_u8 == D_QUADRANT2_CNT_U8) || (MtrQuad_Cnt_T_u8 == D_QUADRANT4_CNT_U8))
	{
		UncorrPhsAdv_Cnt_T_s16 = CalcDelta3(VdTerm_Volt_T_f32,VqTerm_Volt_T_f32);
		
		Delta3_Cnt_D_s16 = UncorrPhsAdv_Cnt_T_s16;
		Delta1_Cnt_D_u16 = 0U;
		Delta2_Cnt_D_s16 = 0U;
	}
	else
	{
		Delta1_Cnt_T_u16 = CalcDelta1(Abs_f32_m(TermXq_Uls_T_f32),Abs_f32_m(TermXd_Uls_T_f32), Abs_f32_m(PhsAdvY_Uls_T_f32));
		Delta2_Cnt_T_s16 = CalcDelta2(TermA_Volt_T_f32, TermBSS_Volt_T_f32,TermBTOT_Volt_T_f32, TermXq_Uls_T_f32);
		
		if (Abs_s16_m(Delta2_Cnt_T_s16) > Delta1_Cnt_T_u16)
		{
			UncorrPhsAdv_Cnt_T_s16 = Delta2_Cnt_T_s16;
		}
		else
		{
			if (MtrQuad_Cnt_T_u8 == D_QUADRANT1_CNT_U8)
			{
				UncorrPhsAdv_Cnt_T_s16 = (sint16)Delta1_Cnt_T_u16;
			}
			else
			{
				UncorrPhsAdv_Cnt_T_s16 = -(sint16)Delta1_Cnt_T_u16;
			}
		}

		Delta1_Cnt_D_u16 = Delta1_Cnt_T_u16;
		Delta2_Cnt_D_s16 = Delta2_Cnt_T_s16;
		Delta3_Cnt_D_s16 = 0;
	}

	PhsOffCorr_Cnt_T_f32 = MRFMtrVel_MtrRadpS_T_f32 * (float32)D_MTRPOLESDIV2_CNT_U8 * k_PhsOffCorrDelay_Sec_f32 * D_CORRPHSADVSCALE_CNTSPRAD_F32;
	PhsOffCorr_Cnt_T_s16 = FPM_FloatToFixedWithRound_m(PhsOffCorr_Cnt_T_f32, s15p0_T);

	PhsOffCorr_Cnt_D_s16 = PhsOffCorr_Cnt_T_s16;

	

	
	UncorrPhsAdv_Cnt_T_s16 = Limit_m(UncorrPhsAdv_Cnt_T_s16, -D_UNCORRPHSADVMAX_CNT_S16, D_UNCORRPHSADVMAX_CNT_S16);
	

	UncorrPhsAdv_Cnt_M_s16 = UncorrPhsAdv_Cnt_T_s16;
	PhsOffCorr_Cnt_M_s16= PhsOffCorr_Cnt_T_s16;
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_PhaseCtrl_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PHASECTRL_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC INLINE FUNC(uint16, AP_PHASECTRL_CODE) CalcDelta1(	VAR(float32, AUTOMATIC) TermXq_Uls_T_f32, 
															VAR(float32, AUTOMATIC) TermXd_Uls_T_f32,
															VAR(float32, AUTOMATIC) TermY_Uls_T_f32)
{
	VAR(float32, AUTOMATIC) TanDelta_Uls_T_f32;
	VAR(float32, AUTOMATIC) DenTerm_Uls_T_f32;
	VAR(uint16, AUTOMATIC) DeltaMid_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Delta1_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) IterNo_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) IterPow_Cnt_T_u16;
	
	/*** Iterative solution to calculate the ArcTan ***/
	if (TermY_Uls_T_f32 <= 1.0f)
	{
		Delta1_Cnt_T_u16 = 0U;
	}
	else
	{
		IterNo_Cnt_T_u16 = 0U;
		IterPow_Cnt_T_u16 = 1U;
		Delta1_Cnt_T_u16 = D_MAXDELTAVAL_CNT_U16;
	
		while (IterNo_Cnt_T_u16 < D_MAXITERATION_CNT_U16)
		{
	
			DeltaMid_Cnt_T_u16 = Delta1_Cnt_T_u16 - ((D_DELTABINSRCMIDPT_CNT_U16 + (IterPow_Cnt_T_u16>>1U)) / IterPow_Cnt_T_u16);
	
			DenTerm_Uls_T_f32 = (TermXd_Uls_T_f32 * T_SINELKPTBL_ULS_F32[DeltaMid_Cnt_T_u16]) + T_SINELKPTBL_ULS_F32[(TableSize_m(T_SINELKPTBL_ULS_F32)-1U) - DeltaMid_Cnt_T_u16];
			TanDelta_Uls_T_f32= T_TANLKPTBL_ULS_F32[DeltaMid_Cnt_T_u16];
	
			if((TanDelta_Uls_T_f32 >= TermXq_Uls_T_f32) || (DenTerm_Uls_T_f32 >= TermY_Uls_T_f32))
			{
				Delta1_Cnt_T_u16 = DeltaMid_Cnt_T_u16;
			}
	
			IterNo_Cnt_T_u16 = IterNo_Cnt_T_u16 + 1U;
			IterPow_Cnt_T_u16 = IterPow_Cnt_T_u16 * D_POWERTWOSCALING_CNT_U16;
		}
	}

	return(Delta1_Cnt_T_u16);
	
}

STATIC INLINE FUNC(sint16, AP_PHASECTRL_CODE) CalcDelta2(	VAR(float32, AUTOMATIC) TermA_Volt_T_f32, 
															VAR(float32, AUTOMATIC) TermBSS_Volt_T_f32, 
															VAR(float32, AUTOMATIC) TermBTOT_Volt_T_f32,
															VAR(float32, AUTOMATIC) TermXq_Uls_T_f32)
{
	VAR(float32, AUTOMATIC) TargetNum_Volt_T_f32;
	VAR(float32, AUTOMATIC) TargetDen_Volt_T_f32;
	VAR(sint16, AUTOMATIC) Delta2_Cnt_T_s16;
	
	TargetNum_Volt_T_f32 = TermBSS_Volt_T_f32 * TermXq_Uls_T_f32;
	TargetDen_Volt_T_f32 = TermA_Volt_T_f32 + TermBTOT_Volt_T_f32;
	
	Delta2_Cnt_T_s16 = PhsAdvArcTan(TargetNum_Volt_T_f32, TargetDen_Volt_T_f32, Abs_f32_m(TermXq_Uls_T_f32));

	return(Delta2_Cnt_T_s16);
}

STATIC INLINE FUNC(sint16, AP_PHASECTRL_CODE) CalcDelta3(	VAR(float32, AUTOMATIC) VdTerm_Volt_T_f32,
															VAR(float32, AUTOMATIC) VqTerm_Volt_T_f32
															)
{
	VAR(float32, AUTOMATIC) TargetNum_Volt_T_f32;
	VAR(float32, AUTOMATIC) TargetDen_Volt_T_f32;
	VAR(sint16, AUTOMATIC) Delta3_Cnt_T_s16;
	
	TargetNum_Volt_T_f32 = -VdTerm_Volt_T_f32;
	TargetDen_Volt_T_f32 = VqTerm_Volt_T_f32;
	
	Delta3_Cnt_T_s16 = PhsAdvArcTan(TargetNum_Volt_T_f32, TargetDen_Volt_T_f32, D_MAXTANDELTALKUP_ULS_F32);

	return(Delta3_Cnt_T_s16);
}

STATIC FUNC(sint16, AP_PHASECTRL_CODE) PhsAdvArcTan(	VAR(float32, AUTOMATIC) Num_Uls_T_f32, 
														VAR(float32, AUTOMATIC) Den_Uls_T_f32,
														VAR(float32, AUTOMATIC) ArcTanLmt_Uls_T_f32)
{
	VAR(float32, AUTOMATIC) Target_Uls_T_f32;
	VAR(float32, AUTOMATIC) TanAngle_Uls_T_f32;
	VAR(sint16, AUTOMATIC) Angle_Cnt_T_s16;
	VAR(sint16, AUTOMATIC) AngleSign_Cnt_T_s16;
	VAR(uint16, AUTOMATIC) AngleMid_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) IterNo_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) IterPow_Cnt_T_u16;

	if (Abs_f32_m(Num_Uls_T_f32) < FLT_EPSILON)
	{
		Angle_Cnt_T_s16 = 0;
	}
	else
	{
		Target_Uls_T_f32 = Num_Uls_T_f32 / Den_Uls_T_f32;

		Target_Uls_T_f32 = Limit_m(Target_Uls_T_f32, -D_MAXTANDELTALKUP_ULS_F32, D_MAXTANDELTALKUP_ULS_F32);

		if (Target_Uls_T_f32 < 0.0F)
		{
			AngleSign_Cnt_T_s16 = -1;
			Target_Uls_T_f32 = -Target_Uls_T_f32;
		}
		else
		{
			AngleSign_Cnt_T_s16 = 1;
		}

		IterNo_Cnt_T_u16 = 0U;  
		Angle_Cnt_T_s16 =  D_MAXDELTAVAL_CNT_U16;
		IterPow_Cnt_T_u16 = 1U;

		while (IterNo_Cnt_T_u16 < D_MAXITERATION_CNT_U16)
		{
			AngleMid_Cnt_T_u16 = (uint16)Angle_Cnt_T_s16 - ((D_DELTABINSRCMIDPT_CNT_U16 + (IterPow_Cnt_T_u16>>1U)) / IterPow_Cnt_T_u16);
			TanAngle_Uls_T_f32 = T_TANLKPTBL_ULS_F32[AngleMid_Cnt_T_u16];

			if((TanAngle_Uls_T_f32 > Target_Uls_T_f32) || (TanAngle_Uls_T_f32 > ArcTanLmt_Uls_T_f32))
			{
				Angle_Cnt_T_s16 = (sint16)AngleMid_Cnt_T_u16;
			}

			IterNo_Cnt_T_u16 = IterNo_Cnt_T_u16 + 1U;

			IterPow_Cnt_T_u16 = IterPow_Cnt_T_u16 * D_POWERTWOSCALING_CNT_U16;
		}
		
		Angle_Cnt_T_s16 = Angle_Cnt_T_s16 * AngleSign_Cnt_T_s16;

  	}
	
	return(Angle_Cnt_T_s16);
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
