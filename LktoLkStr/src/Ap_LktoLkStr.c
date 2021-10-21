/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_LktoLkStr.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LktoLkStr-nzt9hv/LktoLkStr/autosar
 *     SW-C Type:  Ap_LktoLkStr
 *  Generated at:  Sun Sep 23 09:51:44 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_LktoLkStr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* Version Control:
 * Date Created:      Tue Jan 09 17:16:01 2012
 * %version:          6 %
 * %derived_by:       czmgrw %
 * %date_modified:    Tue Oct 16 13:05:31 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/14/12   1       VK        Initial Version implementing SF#24 V001                                        4375
 * 03/06/12   2       VK        Anomaly 3016 and 3011 fixes													 5033, 5034
 * 06/26/12   3       OT        Updated to SF-24 v002                                                          5736
 * 09/21/2012 4       SELVA     Updated to checkpoints and stddef	                                           6231
 * 10/16/12   5       NRAR      Removed abs macro in case1, case 3 for XInitial signa 					       6501
 * 08/11/15   6       JK        Updated to FDD SF-24 v004                                                      13522
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_LktoLkStr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_LktoLkStr_Cfg.h"
#include "CalConstants.h"
#include <math.h>
#include "GlobalMacro.h"
#include "fixmath.h"

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance.  Rule suppressed by line at each occurrence.*/

/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */

/* Embedded Constants */
#define D_LRNPNCNTRTARGETMTRPOS_MTRRAD_F32	603.185789F
#define D_MINHWVELOCITY_HWDEGPS_F32			10.0f
#define D_MAXHWVELOCITY_HWDEGPS_F32			1000.0f
#define D_MINHWACCELERATION_HWDEGPSPS_F32	100.0f
#define D_MAXHWACCELERATION_HWDEGPSPS_F32	50000.0f
#define D_MINSTEPFC_HZ_F32					1.0f
#define D_MAXSTEPFC_HZ_F32					150.0f

/* Module Internal */

#define LKTOLKSTR_START_SEC_VAR_CLEARED_32
#include "MemMap.h"    /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) LrnPnCntrCmd_MtrNm_M_f32;                             /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) LrnPnCntrHwCenter_HwDeg_M_f32;                        /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) LrnPnCntrHwTravel_HwDeg_M_f32;                        /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) ITermSV_HwDeg_M_f32;                                  /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CapturedHwPosition_HwDeg_M_f32;                       /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CapturedTargetVelocity_MtrRadpS_M_f32;                /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CapturedStepMultFactor_Uls_M_f32;                     /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) HwDegtoMtrRad_Uls_M_f32;                              /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) TargetVelocity_HwDegpSec_M_f32;                       /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) TargetAcceleration_HwDegpSecSqr_M_f32;                /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) xInitial_HwDeg_M_f32;                                 /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) xInitial_MtrNm_M_f32;                                 /* PRQA S 3218 */
/* Pointer SV */                                                                    
STATIC VAR(float32, AUTOMATIC) MtrPosDeltaSigSV_MtrRad_M_f32;                        /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) MtrPosFilterOpSV_MtrRad_M_f32;                        /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) MtrTrqDeltaSigSV_MtrNm_M_f32;                         /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) MtrTrqFilterOpSV_MtrNm_M_f32;                         /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) HwPosDeltaSigSV_HwDeg_M_f32;                          /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) HwPosFilterOpSV_HwDeg_M_f32;                          /* PRQA S 3218 */
/* Start Timers */
STATIC VAR(uint32, AUTOMATIC) TimeoutStartTime_mS_M_u32;                             /* PRQA S 3218 */
STATIC VAR(uint32, AUTOMATIC) ChangeStateStartTime_mS_M_u32;                         /* PRQA S 3218 */
/* Display Variables */                                                             
STATIC volatile VAR(float32, AUTOMATIC) HwPositionCmd_HwDeg_D_f32;                   /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) PrevMaxHwPosition_HwDeg_M_f32;                        /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) PrevMinHwPosition_HwDeg_M_f32;                        /* PRQA S 3218 */
#define LKTOLKSTR_STOP_SEC_VAR_CLEARED_32                                           
#include "MemMap.h"  /* PRQA S 5087 */                                               
                                                                                     
#define LKTOLKSTR_START_SEC_VAR_CLEARED_BOOLEAN                                      
#include "MemMap.h"  /* PRQA S 5087 */                                              
STATIC VAR(boolean, AUTOMATIC) EnableFlag_Cnt_M_lgc;                                 /* PRQA S 3218 */
#define LKTOLKSTR_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"  /* PRQA S 5087 */

#define LKTOLKSTR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */
STATIC VAR(LktoLkStrStateType, AUTOMATIC) PinionCtrState_Cnt_M_Enum;                /* PRQA S 3218 */
#define LKTOLKSTR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */

/* Local function declarations */
STATIC INLINE FUNC(void, AP_LKTOLKSTR_APPL_CODE) StateControl(VAR(boolean, AUTOMATIC) LrnPnCenterEnable_Cnt_T_lgc,
															  VAR(float32, AUTOMATIC) MotorVelCRF_MtrRadpS_T_f32,
															  VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32,
															  VAR(float32, AUTOMATIC) CapturedHwPosition_HwDeg_T_f32,
															  VAR(float32, AUTOMATIC) TargetVelocity_MtrRadpS_T_f32,
															  VAR(float32, AUTOMATIC) StepMultFactor_Uls_T_f32);

STATIC INLINE FUNC(float32, AP_LKTOLKSTR_APPL_CODE) FilteredStep (VAR(float32, AUTOMATIC) xInitial_Uls_T_f32,
																  VAR(float32, AUTOMATIC) xFinal_Uls_T_f32,
																  VAR(float32, AUTOMATIC) RateLimitCal_Uls_T_f32,
																  VAR(float32, AUTOMATIC) StepMultFactor_Uls_T_f32,
																  P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevDeltaSignalSVPtr_Uls_T_f32,
																  P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevFilterOutputSVPtr_T_f32);

STATIC INLINE FUNC(LktoLkStrStateType, AP_LKTOLKSTR_APPL_CODE) TimeoutFn (VAR(boolean, AUTOMATIC) Timeout_Cnt_T_lgc,
																		  VAR(LktoLkStrStateType, AUTOMATIC) PinionCtrState_Cnt_T_Enum);

STATIC INLINE FUNC(boolean, AP_LKTOLKSTR_APPL_CODE) CheckIfTimerElapsed (VAR(uint32, AUTOMATIC) ElapsedTime_mS_T_u32,
																		 VAR(uint32, AUTOMATIC) TimerCal_ms_T_u32);

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
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 *
 * Enumeration Types:
 * ==================
 * LktoLkStrStateType: Enumeration of integer in interval [0...7] with enumerators
 *   HOLD (0u)
 *   POSANGVEL (1u)
 *   POSMTRTRQ (2u)
 *   NEGANGVEL (3u)
 *   NEGMTRTRQ (4u)
 *   MOVETO (5u)
 *   DONE (6u)
 *   TIMEOUT (7u)
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
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * UInt32: D_ZERO_CNT_U32 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_LKTOLKSTR_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ap_LktoLkStr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LKTOLKSTR_APPL_CODE) Ap_LktoLkStr_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ap_LktoLkStr_Init
 *********************************************************************************************************************/
	
	HwDegtoMtrRad_Uls_M_f32 = (k_InvGearRatio_Uls_f32 * D_2PI_ULS_F32)/ 360.0f;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LktoLkStr_Per1
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
 *   Float Rte_IRead_LktoLkStr_Per1_AlignedHwPosition_HwDeg_f32(void)
 *   Boolean Rte_IRead_LktoLkStr_Per1_LrnPnCenterEnable_Cnt_lgc(void)
 *   Float Rte_IRead_LktoLkStr_Per1_MotorVelCRF_MtrRadpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32(void)
 *   void Rte_IWrite_LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32(void)
 *   void Rte_IWrite_LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32(void)
 *   void Rte_IWrite_LktoLkStr_Per1_LrnPnCntrState_Cnt_enum(LktoLkStrStateType data)
 *   LktoLkStrStateType *Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrState_Cnt_enum(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LKTOLKSTR_APPL_CODE) LktoLkStr_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LktoLkStr_Per1
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) MotorVelCRF_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) EnableFlag_Cnt_T_lgc;
	
	VAR(float32, AUTOMATIC) AbsTargetVelocity_HwDegpSec_T_f32;
	VAR(float32, AUTOMATIC) AbsTargetAcceleration_HwDegpSecSqr_T_f32;
	VAR(float32, AUTOMATIC) StepFc_Hz_T_f32;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_LktoLkStr_Per1_CP0_CheckpointReached();
	
	MotorVelCRF_MtrRadpS_T_f32 = Rte_IRead_LktoLkStr_Per1_MotorVelCRF_MtrRadpS_f32();
	HwPosition_HwDeg_T_f32 = Rte_IRead_LktoLkStr_Per1_AlignedHwPosition_HwDeg_f32();
	EnableFlag_Cnt_T_lgc = Rte_IRead_LktoLkStr_Per1_LrnPnCenterEnable_Cnt_lgc();
	
	/* Capture inputs on the raising edge */
	if((EnableFlag_Cnt_M_lgc == FALSE) && (EnableFlag_Cnt_T_lgc == TRUE))
	{
		CapturedHwPosition_HwDeg_M_f32 = HwPosition_HwDeg_T_f32;
		
		AbsTargetVelocity_HwDegpSec_T_f32 = Limit_m(Abs_f32_m(TargetVelocity_HwDegpSec_M_f32), D_MINHWVELOCITY_HWDEGPS_F32, D_MAXHWVELOCITY_HWDEGPS_F32);
		AbsTargetAcceleration_HwDegpSecSqr_T_f32 = Limit_m(Abs_f32_m(TargetAcceleration_HwDegpSecSqr_M_f32), D_MINHWACCELERATION_HWDEGPSPS_F32, D_MAXHWACCELERATION_HWDEGPSPS_F32);
		
		CapturedTargetVelocity_MtrRadpS_M_f32 = AbsTargetVelocity_HwDegpSec_T_f32 * HwDegtoMtrRad_Uls_M_f32;
		StepFc_Hz_T_f32 = Limit_m(AbsTargetAcceleration_HwDegpSecSqr_T_f32 / (AbsTargetVelocity_HwDegpSec_T_f32 * D_2PI_ULS_F32), D_MINSTEPFC_HZ_F32, D_MAXSTEPFC_HZ_F32);
		CapturedStepMultFactor_Uls_M_f32 = D_ONE_ULS_F32 - expf(-StepFc_Hz_T_f32 * D_2PI_ULS_F32 * D_2MS_SEC_F32);
	}
	
	/* Handle local functions */
	StateControl(EnableFlag_Cnt_T_lgc, MotorVelCRF_MtrRadpS_T_f32, HwPosition_HwDeg_T_f32, CapturedHwPosition_HwDeg_M_f32, CapturedTargetVelocity_MtrRadpS_M_f32, CapturedStepMultFactor_Uls_M_f32);
	
	/* Update Module Outputs */
	EnableFlag_Cnt_M_lgc = EnableFlag_Cnt_T_lgc;
	
	Rte_IWrite_LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32(LrnPnCntrCmd_MtrNm_M_f32);
	Rte_IWrite_LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32(LrnPnCntrHwCenter_HwDeg_M_f32);
	Rte_IWrite_LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32(LrnPnCntrHwTravel_HwDeg_M_f32);
	Rte_IWrite_LktoLkStr_Per1_LrnPnCntrState_Cnt_enum(PinionCtrState_Cnt_M_Enum);
	
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_LktoLkStr_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LktoLkStr_SCom_SetInputParam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetInputParam> of PortPrototype <LktoLkStr_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LKTOLKSTR_APPL_CODE) LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LktoLkStr_SCom_SetInputParam
 *********************************************************************************************************************/
	
	TargetVelocity_HwDegpSec_M_f32 = TargetVelocity_HwDegpSec_f32;
	TargetAcceleration_HwDegpSecSqr_M_f32 = TargetAcceleration_HwDegpSecSqr_f32;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_LKTOLKSTR_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define RTE_START_SEC_AP_LKTOLKSTR_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/* Local Functions */

/* State Control */
STATIC INLINE FUNC(void, AP_LKTOLKSTR_APPL_CODE) StateControl(VAR(boolean, AUTOMATIC) LrnPnCenterEnable_Cnt_T_lgc,
															  VAR(float32, AUTOMATIC) MotorVelCRF_MtrRadpS_T_f32,
															  VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32,
															  VAR(float32, AUTOMATIC) CapturedHwPosition_HwDeg_T_f32,
															  VAR(float32, AUTOMATIC) TargetVelocity_MtrRadpS_T_f32,
															  VAR(float32, AUTOMATIC) StepMultFactor_Uls_T_f32)
{
	VAR(float32, AUTOMATIC) LrnPnCntrCmd_MtrNm_T_f32;
	VAR(LktoLkStrStateType, AUTOMATIC) PinionCtrState_Cnt_T_Enum;
	VAR(boolean, AUTOMATIC) Timeout_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) bThreshold_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) FilteredOutCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) MtrPositionCmd_MtrRad_T_f32;
	VAR(float32, AUTOMATIC) ITermOut_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) ITermError_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) ITermAWLmt_HwDeg_T_f32;	
	VAR(float32, AUTOMATIC) LrnPnCntrKi_MtrNmpHwDegS_T_f32;
	VAR(uint32, AUTOMATIC) ChgStElapsedTime_mS_T_u32;
	VAR(uint32, AUTOMATIC) TimeoutElapsedTime_mS_T_u32;
	VAR(float32, AUTOMATIC) HwPositionCmd_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) ITerm_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) MaxHwPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) MinHwPosition_HwDeg_T_f32;
	
	/* Check if Learn Pinion Center flag is enabled */
	if (LrnPnCenterEnable_Cnt_T_lgc == TRUE)
	{
		PinionCtrState_Cnt_T_Enum = PinionCtrState_Cnt_M_Enum;
	}
	else
	{
		PinionCtrState_Cnt_T_Enum = HOLD;
		LrnPnCntrHwCenter_HwDeg_M_f32 = D_ZERO_ULS_F32;
		LrnPnCntrHwTravel_HwDeg_M_f32 = D_ZERO_ULS_F32;
	}
	
	if((LrnPnCenterEnable_Cnt_T_lgc == TRUE) && (PinionCtrState_Cnt_T_Enum == HOLD))
	{
		MaxHwPosition_HwDeg_T_f32 = HwPosition_HwDeg_T_f32;
		MinHwPosition_HwDeg_T_f32 = HwPosition_HwDeg_T_f32;
	}
	else
	{
		MaxHwPosition_HwDeg_T_f32 = Max_m(HwPosition_HwDeg_T_f32,PrevMaxHwPosition_HwDeg_M_f32);
		MinHwPosition_HwDeg_T_f32 = Min_m(HwPosition_HwDeg_T_f32,PrevMinHwPosition_HwDeg_M_f32);
	}
	
	PrevMaxHwPosition_HwDeg_M_f32 = MaxHwPosition_HwDeg_T_f32;
	PrevMinHwPosition_HwDeg_M_f32 = MinHwPosition_HwDeg_T_f32;
	
	switch(PinionCtrState_Cnt_T_Enum)
	{
		
		case POSANGVEL: /* State 1 */
			
			MtrPositionCmd_MtrRad_T_f32 = FilteredStep(	(xInitial_HwDeg_M_f32 * HwDegtoMtrRad_Uls_M_f32),
														D_LRNPNCNTRTARGETMTRPOS_MTRRAD_F32,
														TargetVelocity_MtrRadpS_T_f32,
														StepMultFactor_Uls_T_f32,
														&MtrPosDeltaSigSV_MtrRad_M_f32,
														&MtrPosFilterOpSV_MtrRad_M_f32);
			
			LrnPnCntrCmd_MtrNm_T_f32 = ((MtrPositionCmd_MtrRad_T_f32 - (HwPosition_HwDeg_T_f32 * HwDegtoMtrRad_Uls_M_f32)) * k_LrnPnCntrKp_MtrNmpMtrRad_f32) - (MotorVelCRF_MtrRadpS_T_f32 * k_LrnPnCntrMtrDamp_MtrNmpMtrRadpS_f32);
			
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TimeoutStartTime_mS_M_u32, &TimeoutElapsedTime_mS_T_u32);
			
			/* Stopped Motor Criteria */
			if ((Abs_f32_m(MotorVelCRF_MtrRadpS_T_f32) <= k_LrnPnCntrMotVelStoppedThresh_MtrRadpS_f32) &&
				(LrnPnCntrCmd_MtrNm_M_f32 >= k_LrnPnCntrMinApplyTorque_MtrNm_f32))
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(ChangeStateStartTime_mS_M_u32, &ChgStElapsedTime_mS_T_u32);
				bThreshold_Cnt_T_lgc = CheckIfTimerElapsed(ChgStElapsedTime_mS_T_u32, k_LrnPnCntrTimeThresh_mS_u32);
				
				if (bThreshold_Cnt_T_lgc == TRUE)
				{
					PinionCtrState_Cnt_T_Enum = POSMTRTRQ;
					xInitial_MtrNm_M_f32 = LrnPnCntrCmd_MtrNm_M_f32;
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(TimeoutStartTime_mS_M_u32));
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
			}
			
			Timeout_Cnt_T_lgc = CheckIfTimerElapsed(TimeoutElapsedTime_mS_T_u32, k_LrnPnCntrTimeout_mS_u32);
			
			PinionCtrState_Cnt_T_Enum = TimeoutFn(Timeout_Cnt_T_lgc, PinionCtrState_Cnt_T_Enum);
			
		break;
		
		case POSMTRTRQ: /* State 2 */
			
			LrnPnCntrCmd_MtrNm_T_f32 = FilteredStep((Abs_f32_m(xInitial_MtrNm_M_f32)),
													k_LrnPnCntrHoldTorque_MtrNm_f32,
													k_LrnPnCntrHoldTorqueRateLimit_MtrNmpS_f32,
													StepMultFactor_Uls_T_f32,
													&MtrTrqDeltaSigSV_MtrNm_M_f32,
													&MtrTrqFilterOpSV_MtrNm_M_f32);
			
			MtrPositionCmd_MtrRad_T_f32 = D_ZERO_ULS_F32;
			
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TimeoutStartTime_mS_M_u32, &TimeoutElapsedTime_mS_T_u32);
			
			/* HOLD constant torque */
			if (Abs_f32_m(k_LrnPnCntrHoldTorque_MtrNm_f32 - LrnPnCntrCmd_MtrNm_T_f32) <= k_LrnPnCntrHoldTorqueErrThresh_MtrNm_f32)
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(ChangeStateStartTime_mS_M_u32, &ChgStElapsedTime_mS_T_u32);
				bThreshold_Cnt_T_lgc = CheckIfTimerElapsed(ChgStElapsedTime_mS_T_u32, k_LrnPnCntrTimeThresh_mS_u32);
				
				if (bThreshold_Cnt_T_lgc == TRUE)
				{
					PinionCtrState_Cnt_T_Enum = NEGANGVEL;
					xInitial_MtrNm_M_f32 = LrnPnCntrCmd_MtrNm_M_f32;
					xInitial_HwDeg_M_f32 = HwPosition_HwDeg_T_f32;

					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(TimeoutStartTime_mS_M_u32));
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
					
					MtrPosDeltaSigSV_MtrRad_M_f32 = D_ZERO_ULS_F32;
					MtrPosFilterOpSV_MtrRad_M_f32 = D_ZERO_ULS_F32;
					MtrTrqDeltaSigSV_MtrNm_M_f32 = D_ZERO_ULS_F32;
					MtrTrqFilterOpSV_MtrNm_M_f32 = D_ZERO_ULS_F32;
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
			}
			
			Timeout_Cnt_T_lgc = CheckIfTimerElapsed(TimeoutElapsedTime_mS_T_u32, k_LrnPnCntrTimeout_mS_u32);
			
			PinionCtrState_Cnt_T_Enum = TimeoutFn(Timeout_Cnt_T_lgc, PinionCtrState_Cnt_T_Enum);
			
		break;
		
		case NEGANGVEL: /* State 3 */
			
			MtrPositionCmd_MtrRad_T_f32 = FilteredStep(	(xInitial_HwDeg_M_f32 * HwDegtoMtrRad_Uls_M_f32),
														-D_LRNPNCNTRTARGETMTRPOS_MTRRAD_F32,
														TargetVelocity_MtrRadpS_T_f32,
														StepMultFactor_Uls_T_f32,
														&MtrPosDeltaSigSV_MtrRad_M_f32,
														&MtrPosFilterOpSV_MtrRad_M_f32);
			
			FilteredOutCmd_MtrNm_T_f32 = FilteredStep(	xInitial_MtrNm_M_f32,
														D_ZERO_ULS_F32,
														k_LrnPnCntrHoldTorqueRateLimit_MtrNmpS_f32,
														StepMultFactor_Uls_T_f32,
														&MtrTrqDeltaSigSV_MtrNm_M_f32,
														&MtrTrqFilterOpSV_MtrNm_M_f32);
			
			LrnPnCntrCmd_MtrNm_T_f32 = (((MtrPositionCmd_MtrRad_T_f32 - (HwPosition_HwDeg_T_f32 * HwDegtoMtrRad_Uls_M_f32)) * k_LrnPnCntrKp_MtrNmpMtrRad_f32) + FilteredOutCmd_MtrNm_T_f32) - (MotorVelCRF_MtrRadpS_T_f32 * k_LrnPnCntrMtrDamp_MtrNmpMtrRadpS_f32);
			
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TimeoutStartTime_mS_M_u32, &TimeoutElapsedTime_mS_T_u32);
			
			/* Stopped Motor Criteria */
			if ((Abs_f32_m(MotorVelCRF_MtrRadpS_T_f32) <= k_LrnPnCntrMotVelStoppedThresh_MtrRadpS_f32) &&
				((-LrnPnCntrCmd_MtrNm_M_f32) >= k_LrnPnCntrMinApplyTorque_MtrNm_f32))
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(ChangeStateStartTime_mS_M_u32, &ChgStElapsedTime_mS_T_u32);
				bThreshold_Cnt_T_lgc = CheckIfTimerElapsed(ChgStElapsedTime_mS_T_u32, k_LrnPnCntrTimeThresh_mS_u32);
				
				if (bThreshold_Cnt_T_lgc == TRUE)
				{
					PinionCtrState_Cnt_T_Enum = NEGMTRTRQ;
					xInitial_MtrNm_M_f32 = LrnPnCntrCmd_MtrNm_M_f32;
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(TimeoutStartTime_mS_M_u32));
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
					
					MtrTrqDeltaSigSV_MtrNm_M_f32 = D_ZERO_ULS_F32;
					MtrTrqFilterOpSV_MtrNm_M_f32 = D_ZERO_ULS_F32;
					
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
			}
			
			Timeout_Cnt_T_lgc = CheckIfTimerElapsed(TimeoutElapsedTime_mS_T_u32, k_LrnPnCntrTimeout_mS_u32);
			
			PinionCtrState_Cnt_T_Enum = TimeoutFn(Timeout_Cnt_T_lgc, PinionCtrState_Cnt_T_Enum);
			
		break;
		
		case NEGMTRTRQ: /* State 4 */
			
			LrnPnCntrCmd_MtrNm_T_f32 = FilteredStep((Abs_f32_m(xInitial_MtrNm_M_f32)),
													k_LrnPnCntrHoldTorque_MtrNm_f32,
													k_LrnPnCntrHoldTorqueRateLimit_MtrNmpS_f32,
													StepMultFactor_Uls_T_f32,
													&MtrTrqDeltaSigSV_MtrNm_M_f32,
													&MtrTrqFilterOpSV_MtrNm_M_f32);
			
			MtrPositionCmd_MtrRad_T_f32 = D_ZERO_ULS_F32;
			
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TimeoutStartTime_mS_M_u32, &TimeoutElapsedTime_mS_T_u32);
			
			/* HOLD constant torque */
			if (Abs_f32_m(k_LrnPnCntrHoldTorque_MtrNm_f32 - LrnPnCntrCmd_MtrNm_T_f32) <= k_LrnPnCntrHoldTorqueErrThresh_MtrNm_f32)
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(ChangeStateStartTime_mS_M_u32, &ChgStElapsedTime_mS_T_u32);
				bThreshold_Cnt_T_lgc = CheckIfTimerElapsed(ChgStElapsedTime_mS_T_u32, k_LrnPnCntrTimeThresh_mS_u32);
				
				if (bThreshold_Cnt_T_lgc == TRUE)
				{
					PinionCtrState_Cnt_T_Enum = MOVETO;
					xInitial_HwDeg_M_f32 = HwPosition_HwDeg_T_f32;
					xInitial_MtrNm_M_f32 = LrnPnCntrCmd_MtrNm_M_f32;
					LrnPnCntrHwCenter_HwDeg_M_f32 = ((MinHwPosition_HwDeg_T_f32 + MaxHwPosition_HwDeg_T_f32)/ 2.0f);
					LrnPnCntrHwTravel_HwDeg_M_f32 = (Abs_f32_m(MinHwPosition_HwDeg_T_f32 - MaxHwPosition_HwDeg_T_f32));
					
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(TimeoutStartTime_mS_M_u32));
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
					
					HwPosDeltaSigSV_HwDeg_M_f32 = D_ZERO_ULS_F32;
					HwPosFilterOpSV_HwDeg_M_f32 = D_ZERO_ULS_F32;
					MtrTrqDeltaSigSV_MtrNm_M_f32 = D_ZERO_ULS_F32;
					MtrTrqFilterOpSV_MtrNm_M_f32 = D_ZERO_ULS_F32;
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
			}
			LrnPnCntrCmd_MtrNm_T_f32 = -D_ONE_ULS_F32 * LrnPnCntrCmd_MtrNm_T_f32;
			Timeout_Cnt_T_lgc = CheckIfTimerElapsed(TimeoutElapsedTime_mS_T_u32, k_LrnPnCntrTimeout_mS_u32);
			
			PinionCtrState_Cnt_T_Enum = TimeoutFn(Timeout_Cnt_T_lgc, PinionCtrState_Cnt_T_Enum);
			
		break;
		
		case MOVETO: /* State 5 */
			
			HwPositionCmd_HwDeg_T_f32 = FilteredStep(	xInitial_HwDeg_M_f32,
														CapturedHwPosition_HwDeg_T_f32,
														(TargetVelocity_MtrRadpS_T_f32 / HwDegtoMtrRad_Uls_M_f32),
														StepMultFactor_Uls_T_f32,
														&HwPosDeltaSigSV_HwDeg_M_f32,
														&HwPosFilterOpSV_HwDeg_M_f32);
			
			FilteredOutCmd_MtrNm_T_f32 = FilteredStep(	xInitial_MtrNm_M_f32,
														D_ZERO_ULS_F32,
														k_LrnPnCntrHoldTorqueRateLimit_MtrNmpS_f32,
														StepMultFactor_Uls_T_f32,
														&MtrTrqDeltaSigSV_MtrNm_M_f32,
														&MtrTrqFilterOpSV_MtrNm_M_f32);
			
			MtrPositionCmd_MtrRad_T_f32 = HwPositionCmd_HwDeg_T_f32 * HwDegtoMtrRad_Uls_M_f32;
			
			ITermError_HwDeg_T_f32 = HwPositionCmd_HwDeg_T_f32 - HwPosition_HwDeg_T_f32;
			
			LrnPnCntrKi_MtrNmpHwDegS_T_f32 = FPM_FixedToFloat_m(k_LrnPnCntrKi_MtrNmpHwDegS_u4p12, u4p12_T);
			
			/* I-Term */
			/* I-Anti Windup State */
			if (k_LrnPnCntrKi_MtrNmpHwDegS_u4p12 == 0u)
			{
				ITermAWLmt_HwDeg_T_f32 = D_ZERO_ULS_F32;
			}
			else
			{
				ITermAWLmt_HwDeg_T_f32 = (k_LrnPnCntrMaxTcmd_MtrNm_f32)/ (LrnPnCntrKi_MtrNmpHwDegS_T_f32 * D_2MS_SEC_F32);
			}
			
			ITerm_HwDeg_T_f32 = ITermError_HwDeg_T_f32 + ITermSV_HwDeg_M_f32;
			ITerm_HwDeg_T_f32 = Limit_m(ITerm_HwDeg_T_f32, -ITermAWLmt_HwDeg_T_f32, ITermAWLmt_HwDeg_T_f32);
			ITermSV_HwDeg_M_f32 = ITerm_HwDeg_T_f32;
			ITermOut_MtrNm_T_f32 = ITerm_HwDeg_T_f32 * LrnPnCntrKi_MtrNmpHwDegS_T_f32 * D_2MS_SEC_F32;
			
			LrnPnCntrCmd_MtrNm_T_f32 = (((ITermError_HwDeg_T_f32 * k_LrnPnCntrKp_MtrNmpMtrRad_f32 * HwDegtoMtrRad_Uls_M_f32) + ITermOut_MtrNm_T_f32) + FilteredOutCmd_MtrNm_T_f32) - (MotorVelCRF_MtrRadpS_T_f32 * k_LrnPnCntrMtrDamp_MtrNmpMtrRadpS_f32);
			
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TimeoutStartTime_mS_M_u32, &TimeoutElapsedTime_mS_T_u32);
			
			/* Arrived Motor Position Criteria */
			if ((Abs_f32_m(CapturedHwPosition_HwDeg_T_f32 - HwPosition_HwDeg_T_f32)) <= k_LrnPnCntrHwPosErrThresh_HwDeg_f32)
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(ChangeStateStartTime_mS_M_u32, &ChgStElapsedTime_mS_T_u32);
				bThreshold_Cnt_T_lgc = CheckIfTimerElapsed(ChgStElapsedTime_mS_T_u32, k_LrnPnCntrTimeThresh_mS_u32);
				
				if (bThreshold_Cnt_T_lgc == TRUE)
				{
					PinionCtrState_Cnt_T_Enum = DONE;
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
			}
			
			Timeout_Cnt_T_lgc = CheckIfTimerElapsed(TimeoutElapsedTime_mS_T_u32, k_LrnPnCntrTimeout_mS_u32);
			
			PinionCtrState_Cnt_T_Enum = TimeoutFn(Timeout_Cnt_T_lgc, PinionCtrState_Cnt_T_Enum);
			
		break;
		
		case DONE: /* State 6 */
			
			LrnPnCntrCmd_MtrNm_T_f32 = D_ZERO_ULS_F32;
			MtrPositionCmd_MtrRad_T_f32 = D_ZERO_ULS_F32;
			
		break;
		
		case TIMEOUT: /* State 7 */
			
			LrnPnCntrCmd_MtrNm_T_f32 = D_ZERO_ULS_F32;
			MtrPositionCmd_MtrRad_T_f32 = D_ZERO_ULS_F32;
			
		break;
		
		default: /* HOLD - State 0 */
			
			/* Reset SV and Timers */
			ITermSV_HwDeg_M_f32 = D_ZERO_ULS_F32;
			MtrPosDeltaSigSV_MtrRad_M_f32 = D_ZERO_ULS_F32;
			MtrPosFilterOpSV_MtrRad_M_f32 = D_ZERO_ULS_F32;
			MtrTrqDeltaSigSV_MtrNm_M_f32 = D_ZERO_ULS_F32;
			MtrTrqFilterOpSV_MtrNm_M_f32 = D_ZERO_ULS_F32;
			HwPosDeltaSigSV_HwDeg_M_f32 = D_ZERO_ULS_F32;
			HwPosFilterOpSV_HwDeg_M_f32 = D_ZERO_ULS_F32;
			
			TimeoutStartTime_mS_M_u32 = D_ZERO_CNT_U32;
			ChangeStateStartTime_mS_M_u32 = D_ZERO_CNT_U32;
			MtrPositionCmd_MtrRad_T_f32 = D_ZERO_ULS_F32;
			LrnPnCntrCmd_MtrNm_T_f32 = D_ZERO_ULS_F32;
			
			if (LrnPnCenterEnable_Cnt_T_lgc == TRUE)
			{
				PinionCtrState_Cnt_T_Enum = POSANGVEL; /* Goto next state */
				xInitial_HwDeg_M_f32 = HwPosition_HwDeg_T_f32;
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(TimeoutStartTime_mS_M_u32));
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(ChangeStateStartTime_mS_M_u32));
			}
			
		break;
		
	}/* End of switch */
	
	PinionCtrState_Cnt_M_Enum = PinionCtrState_Cnt_T_Enum;
	LrnPnCntrCmd_MtrNm_M_f32 = Limit_m(LrnPnCntrCmd_MtrNm_T_f32, -k_LrnPnCntrMaxTcmd_MtrNm_f32, k_LrnPnCntrMaxTcmd_MtrNm_f32);
	HwPositionCmd_HwDeg_D_f32 = MtrPositionCmd_MtrRad_T_f32 / HwDegtoMtrRad_Uls_M_f32;
	
}

STATIC INLINE FUNC(float32, AP_LKTOLKSTR_APPL_CODE) FilteredStep (VAR(float32, AUTOMATIC) xInitial_Uls_T_f32,
																  VAR(float32, AUTOMATIC) xFinal_Uls_T_f32,
																  VAR(float32, AUTOMATIC) RateLimitCal_Uls_T_f32,
																  VAR(float32, AUTOMATIC) StepMultFactor_Uls_T_f32,
																  P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevDeltaSignalSVPtr_Uls_T_f32,
																  P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevFilterOutputSVPtr_T_f32)
{
	VAR(float32, AUTOMATIC) DeltaSignal_Uls_T_f32;
	VAR(float32, AUTOMATIC) FiltSignal_Uls_T_f32;
	VAR(float32, AUTOMATIC) OutSignal_Uls_T_f32;
	
	DeltaSignal_Uls_T_f32 = xFinal_Uls_T_f32 - xInitial_Uls_T_f32;
	
	/* Rate Limiter */
	DeltaSignal_Uls_T_f32 = Limit_m(DeltaSignal_Uls_T_f32,
									(*PrevDeltaSignalSVPtr_Uls_T_f32 - (RateLimitCal_Uls_T_f32 * D_2MS_SEC_F32)),
									(*PrevDeltaSignalSVPtr_Uls_T_f32 + (RateLimitCal_Uls_T_f32 * D_2MS_SEC_F32)));
	
	/* Save the current delta signal value to use it in the next loop run */
	(*PrevDeltaSignalSVPtr_Uls_T_f32) = DeltaSignal_Uls_T_f32;
	
	FiltSignal_Uls_T_f32 = (StepMultFactor_Uls_T_f32 * (DeltaSignal_Uls_T_f32 - (*PrevFilterOutputSVPtr_T_f32)));
	
	FiltSignal_Uls_T_f32 = FiltSignal_Uls_T_f32 + (*PrevFilterOutputSVPtr_T_f32);
	
	(*PrevFilterOutputSVPtr_T_f32) = FiltSignal_Uls_T_f32;
	
	OutSignal_Uls_T_f32 = (*PrevFilterOutputSVPtr_T_f32) + xInitial_Uls_T_f32;
	
	return(OutSignal_Uls_T_f32);
	
}

STATIC INLINE FUNC(LktoLkStrStateType, AP_LKTOLKSTR_APPL_CODE) TimeoutFn (VAR(boolean, AUTOMATIC) Timeout_Cnt_T_lgc,
																		  VAR(LktoLkStrStateType, AUTOMATIC) PinionCtrState_Cnt_T_Enum)
{
	VAR(LktoLkStrStateType, AUTOMATIC) State_Cnt_T_Enum;
	
	if (Timeout_Cnt_T_lgc == TRUE)
	{
		State_Cnt_T_Enum = TIMEOUT;
	}
	else
	{
		State_Cnt_T_Enum = PinionCtrState_Cnt_T_Enum;
	}
	
	return(State_Cnt_T_Enum);
}

STATIC INLINE FUNC(boolean, AP_LKTOLKSTR_APPL_CODE) CheckIfTimerElapsed (VAR(uint32, AUTOMATIC) ElapsedTime_mS_T_u32,
																		 VAR(uint32, AUTOMATIC) TimerCal_ms_T_u32)
{
	VAR(boolean, AUTOMATIC) ElapsedFlag_Cnt_T_lgc;
	
	if(ElapsedTime_mS_T_u32 <= TimerCal_ms_T_u32)
	{
		ElapsedFlag_Cnt_T_lgc = FALSE;
	}
	else
	{
		ElapsedFlag_Cnt_T_lgc = TRUE;
	}
	
	return(ElapsedFlag_Cnt_T_lgc);
}

#define RTE_STOP_SEC_AP_LKTOLKSTR_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
