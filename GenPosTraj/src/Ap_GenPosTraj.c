/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_GenPosTraj.c
 *     Workspace:  C:/CM_Synergy/ccm_wa/Working/CBD/GenPosTraj/GenPosTraj/autosar/Ap_GenPosTraj.dcf
 *     SW-C Type:  Ap_GenPosTraj
 *  Generated at:  Tue Feb 14 18:43:05 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_GenPosTraj>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* Version Control:
 * Date Created:      Tue Dec 20 13:16:01 2011
 * %version:          2 %
 * %derived_by:       qzx0t0 %
 * %date_modified:    Tue Feb 21 16:24:15 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 12/20/11   1       VK        Initial Version implementing SF#21 v001											4374
 * 2/21/12	  2       VK		Changes to the math while calculating angle command when in CONSTANT_VEL_STATE  4374
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_GenPosTraj.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "GlobalMacro.h"
#include <math.h>

#define D_MINTRGTACCEL_HWDEGPSECSQR_F32		0.1F

typedef enum Command_State {
               WAITING_STATE = 0,
               ACCELERATION_STATE = 1,
               CONSTANT_VEL_STATE = 2, 
               DECELERATION_STATE = 3,
			   HOLD_STATE = 4
             } CMDSTATE_Enum; 

#define GENPOSTRAJ_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC VAR(float32, AUTOMATIC) TargetAngle_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) TargetVelocity_HwDegpSec_M_f32;
STATIC VAR(float32, AUTOMATIC) TargetAcceleration_HwDegpSecSqr_M_f32;
STATIC VAR(float32, AUTOMATIC) TargetAngleInitial_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) TargetVelocityInitial_HwDegpSec_M_f32;
STATIC VAR(float32, AUTOMATIC) TargetAccelerationInitial_HwDegpSecSqr_M_f32;
STATIC VAR(float32, AUTOMATIC) HwPosInitial_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) HwAngleOffsetIn_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) StateTime_Sec_M_f32;
#define GENPOSTRAJ_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define GENPOSTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(CMDSTATE_Enum, AUTOMATIC) CmdState_Cnt_M_Enum;
STATIC VAR(boolean, AUTOMATIC) CalculateFlag_Cnt_M_lgc;
#define GENPOSTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

STATIC INLINE FUNC(void, AP_GENPOSTRAJ_APPL_CODE) InitializeVariables(P2VAR(float32,AUTOMATIC,AUTOMATIC) pHwPosOffset_HwDeg_T_f32,
															   		  P2VAR(float32,AUTOMATIC,AUTOMATIC) pSignDeltaTrgtAngle_Cnt_T_f32,
															   		  P2VAR(float32,AUTOMATIC,AUTOMATIC) pDeltaAccel_Sec_T_f32,
															   		  P2VAR(float32,AUTOMATIC,AUTOMATIC) pDeltaVelocity_Sec_T_f32,
															   	 	  P2VAR(float32,AUTOMATIC,AUTOMATIC) pMaxAccel_HwDegpSecSqr_T_f32,
															   		  P2VAR(float32,AUTOMATIC,AUTOMATIC) pMaxVelocity_HwDegpSec_T_f32);

STATIC INLINE FUNC(float32, AP_GENPOSTRAJ_APPL_CODE) GenerateSignal(CONST(float32, AUTOMATIC) HwPosOffset_HwDeg_T_f32,
															 		CONST(float32, AUTOMATIC) SignDeltaTrgtAngle_Cnt_T_f32,
														     		CONST(float32, AUTOMATIC) DeltaAccel_Sec_T_f32,
														     		CONST(float32, AUTOMATIC) DeltaVelocity_Sec_T_f32,
															 		CONST(float32, AUTOMATIC) MaxAccel_HwDegpSecSqr_T_f32,
															 		CONST(float32, AUTOMATIC) MaxVelocity_HwDegpSec_T_f32,
														     		VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32,
														     		VAR(boolean, AUTOMATIC) CalculateFlag_Cnt_T_lgc);

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
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
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
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_GENPOSTRAJ_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GenPosTraj_Per1
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
 *   Float Rte_IRead_GenPosTraj_Per1_HwPosition_HwDeg_f32(void)
 *   Boolean Rte_IRead_GenPosTraj_Per1_PosTrajEnable_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_GenPosTraj_Per1_PosTrajHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_GenPosTraj_Per1_PosTrajHwAngle_HwDeg_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_GENPOSTRAJ_APPL_CODE) GenPosTraj_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GenPosTraj_Per1
 *********************************************************************************************************************/

#ifdef RTE_INIT_IMPLICIT_BUFFERS
  Rte_IWrite_GenPosTraj_Per1_PosTrajHwAngle_HwDeg_f32(Rte_InitValue_PosTrajHwAngle_HwDeg_f32);
#endif

VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32;
VAR(float32, AUTOMATIC) HwAngleCmd_HwDeg_T_f32;
VAR(float32, AUTOMATIC) HwPosOffset_HwDeg_T_f32;
VAR(float32, AUTOMATIC) SignDeltaTrgtAngle_Cnt_T_f32;
VAR(float32, AUTOMATIC) DeltaAccel_Sec_T_f32;
VAR(float32, AUTOMATIC) DeltaVelocity_Sec_T_f32;
VAR(float32, AUTOMATIC) MaxAccel_HwDegpSecSqr_T_f32;
VAR(float32, AUTOMATIC) MaxVelocity_HwDegpSec_T_f32;
VAR(boolean, AUTOMATIC) CalculateFlag_Cnt_T_lgc;

/* Read input signals */
HwPosition_HwDeg_T_f32 = Rte_IRead_GenPosTraj_Per1_HwPosition_HwDeg_f32();
CalculateFlag_Cnt_T_lgc = Rte_IRead_GenPosTraj_Per1_PosTrajEnable_Cnt_lgc();

/* Capture inputs on the raising edge */
if((!CalculateFlag_Cnt_M_lgc) && CalculateFlag_Cnt_T_lgc)
{
	HwPosInitial_HwDeg_M_f32 = HwPosition_HwDeg_T_f32;
	TargetAngleInitial_HwDeg_M_f32 = TargetAngle_HwDeg_M_f32;
	TargetVelocityInitial_HwDegpSec_M_f32 = TargetVelocity_HwDegpSec_M_f32;
	TargetAccelerationInitial_HwDegpSecSqr_M_f32 =	TargetAcceleration_HwDegpSecSqr_M_f32;
}

/* Handle local functions */
InitializeVariables(&HwPosOffset_HwDeg_T_f32, &SignDeltaTrgtAngle_Cnt_T_f32, &DeltaAccel_Sec_T_f32, &DeltaVelocity_Sec_T_f32,
					&MaxAccel_HwDegpSecSqr_T_f32, &MaxVelocity_HwDegpSec_T_f32);

HwAngleCmd_HwDeg_T_f32 = GenerateSignal(HwPosOffset_HwDeg_T_f32, SignDeltaTrgtAngle_Cnt_T_f32, DeltaAccel_Sec_T_f32, DeltaVelocity_Sec_T_f32,
										MaxAccel_HwDegpSecSqr_T_f32, MaxVelocity_HwDegpSec_T_f32, HwPosition_HwDeg_T_f32, CalculateFlag_Cnt_T_lgc);

/* Update Module Level Variables */
CalculateFlag_Cnt_M_lgc = CalculateFlag_Cnt_T_lgc;

/* Update Module Outputs */
Rte_IWrite_GenPosTraj_Per1_PosTrajHwAngle_HwDeg_f32(HwAngleCmd_HwDeg_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GenPosTraj_SCom_SetInputParam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetInputParam> of PortPrototype <GenPosTraj_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_GENPOSTRAJ_APPL_CODE) GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GenPosTraj_SCom_SetInputParam
 *********************************************************************************************************************/
TargetAngle_HwDeg_M_f32 = PosServHwAngle_HwDeg_f32;
TargetVelocity_HwDegpSec_M_f32 = TargetVelocity_HwDegpSec_f32;
TargetAcceleration_HwDegpSecSqr_M_f32 = TargetAcceleration_HwDegpSecSqr_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_GENPOSTRAJ_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define RTE_START_SEC_AP_GENPOSTRAJ_APPL_CODE
#include "MemMap.h"
/* Local Functions */

/* InitializeVariables */
STATIC INLINE FUNC(void, AP_GENPOSTRAJ_APPL_CODE) InitializeVariables(P2VAR(float32,AUTOMATIC,AUTOMATIC) pHwPosOffset_HwDeg_T_f32,
																		   P2VAR(float32,AUTOMATIC,AUTOMATIC) pSignDeltaTrgtAngle_Cnt_T_f32,
																	       P2VAR(float32,AUTOMATIC,AUTOMATIC) pDeltaAccel_Sec_T_f32,
																	       P2VAR(float32,AUTOMATIC,AUTOMATIC) pDeltaVelocity_Sec_T_f32,
																	       P2VAR(float32,AUTOMATIC,AUTOMATIC) pMaxAccel_HwDegpSecSqr_T_f32,
																	       P2VAR(float32,AUTOMATIC,AUTOMATIC) pMaxVelocity_HwDegpSec_T_f32)
{
	VAR(float32, AUTOMATIC) HwPosFinal_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) MaxVelocityDesired_HwDegpSec_T_f32;
	VAR(float32, AUTOMATIC) MaxAccel_HwDegpSecSqr_T_f32;
	VAR(float32, AUTOMATIC) AbsDeltaTrgtAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) DesiredTrgtAccel_HwDeg_T_f32;

	/* Limit the captured inputs on rising edge */
	HwPosFinal_HwDeg_T_f32 = Limit_m(TargetAngleInitial_HwDeg_M_f32, -k_PosTrajMaxAngle_HwDeg_f32, k_PosTrajMaxAngle_HwDeg_f32);
	MaxVelocityDesired_HwDegpSec_T_f32 = Limit_m(TargetVelocityInitial_HwDegpSec_M_f32, D_ONE_ULS_F32, k_PosTrajMaxVelocity_HwDegpSec_f32);
	MaxAccel_HwDegpSecSqr_T_f32 = Limit_m(TargetAccelerationInitial_HwDegpSecSqr_M_f32, D_MINTRGTACCEL_HWDEGPSECSQR_F32, k_PosTrajMaxAccel_HwDegpSecSqr_f32);

	AbsDeltaTrgtAngle_HwDeg_T_f32 = Abs_f32_m(HwPosFinal_HwDeg_T_f32 - HwPosInitial_HwDeg_M_f32);
	(*pSignDeltaTrgtAngle_Cnt_T_f32) = (float32)(Sign_f32_m(HwPosFinal_HwDeg_T_f32 - HwPosInitial_HwDeg_M_f32));

	DesiredTrgtAccel_HwDeg_T_f32 = ((MaxVelocityDesired_HwDegpSec_T_f32 * MaxVelocityDesired_HwDegpSec_T_f32)/ MaxAccel_HwDegpSecSqr_T_f32)/ 2;

	if ((AbsDeltaTrgtAngle_HwDeg_T_f32/ 2) < DesiredTrgtAccel_HwDeg_T_f32)
	{
		(*pDeltaAccel_Sec_T_f32) = sqrtf(AbsDeltaTrgtAngle_HwDeg_T_f32/ MaxAccel_HwDegpSecSqr_T_f32);
		(*pDeltaVelocity_Sec_T_f32) = D_ZERO_ULS_F32;
		(*pMaxVelocity_HwDegpSec_T_f32) = (*pDeltaAccel_Sec_T_f32) * MaxAccel_HwDegpSecSqr_T_f32;
	
	}
	else
	{
		(*pDeltaAccel_Sec_T_f32) = MaxVelocityDesired_HwDegpSec_T_f32/ MaxAccel_HwDegpSecSqr_T_f32;
		(*pDeltaVelocity_Sec_T_f32) = (AbsDeltaTrgtAngle_HwDeg_T_f32 - ((MaxVelocityDesired_HwDegpSec_T_f32 * MaxVelocityDesired_HwDegpSec_T_f32)/ MaxAccel_HwDegpSecSqr_T_f32))/ MaxVelocityDesired_HwDegpSec_T_f32;
		(*pMaxVelocity_HwDegpSec_T_f32) = MaxVelocityDesired_HwDegpSec_T_f32;
	}

	(*pHwPosOffset_HwDeg_T_f32) = HwPosInitial_HwDeg_M_f32;
	(*pMaxAccel_HwDegpSecSqr_T_f32) = MaxAccel_HwDegpSecSqr_T_f32;

}
/* End of InitializeVariables */

/* GenerateSignal */
STATIC INLINE FUNC(float32, AP_GENPOSTRAJ_APPL_CODE) GenerateSignal(CONST(float32, AUTOMATIC) HwPosOffset_HwDeg_T_f32,
																	     CONST(float32, AUTOMATIC) SignDeltaTrgtAngle_Cnt_T_f32,
																	     CONST(float32, AUTOMATIC) DeltaAccel_Sec_T_f32,
																	     CONST(float32, AUTOMATIC) DeltaVelocity_Sec_T_f32,
																	     CONST(float32, AUTOMATIC) MaxAccel_HwDegpSecSqr_T_f32,
																	     CONST(float32, AUTOMATIC) MaxVelocity_HwDegpSec_T_f32,
																	     VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32,
																	     VAR(boolean, AUTOMATIC) CalculateFlag_Cnt_T_lgc)
{

VAR(CMDSTATE_Enum, AUTOMATIC) CmdState_Cnt_T_Enum;
VAR(boolean, AUTOMATIC) bDone_Cnt_T_lgc;
VAR(float32, AUTOMATIC) StateTime_Sec_T_f32;
VAR(float32, AUTOMATIC) HwAngleOffset_HwDeg_T_f32;
VAR(float32, AUTOMATIC) HwAngleCmd_HwDeg_T_f32;

/* Check if calculate flag is enabled then use the previous commanded state */
if (CalculateFlag_Cnt_T_lgc == TRUE)
{
	CmdState_Cnt_T_Enum = CmdState_Cnt_M_Enum;
}
else
{
	CmdState_Cnt_T_Enum = WAITING_STATE;
}
switch(CmdState_Cnt_T_Enum)
	{
	case WAITING_STATE: /* State 0 */

		if (CalculateFlag_Cnt_T_lgc == TRUE)
		{
			CmdState_Cnt_T_Enum = ACCELERATION_STATE;
		}
		else
		{
			CmdState_Cnt_T_Enum = WAITING_STATE;
		}

		StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		HwAngleCmd_HwDeg_T_f32 = HwPosition_HwDeg_T_f32;
		HwAngleOffset_HwDeg_T_f32 = HwPosOffset_HwDeg_T_f32;
		break;

	case ACCELERATION_STATE: /* State 1 */

		HwAngleCmd_HwDeg_T_f32 = HwAngleOffsetIn_HwDeg_M_f32 + (SignDeltaTrgtAngle_Cnt_T_f32 * (MaxAccel_HwDegpSecSqr_T_f32/ 2) * (StateTime_Sec_M_f32 * StateTime_Sec_M_f32));
		if (StateTime_Sec_M_f32 >= DeltaAccel_Sec_T_f32)
		{	
			bDone_Cnt_T_lgc = TRUE;
		}
		else
		{
			bDone_Cnt_T_lgc = FALSE;
		}

		if (bDone_Cnt_T_lgc == TRUE)
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleCmd_HwDeg_T_f32;
			CmdState_Cnt_T_Enum = CONSTANT_VEL_STATE;
			StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		}
		else
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleOffsetIn_HwDeg_M_f32;
			CmdState_Cnt_T_Enum = ACCELERATION_STATE;
			StateTime_Sec_T_f32 = StateTime_Sec_M_f32 + D_2MS_SEC_F32;
		}
		break;

	case CONSTANT_VEL_STATE: /* State 2 */

		HwAngleCmd_HwDeg_T_f32 = HwAngleOffsetIn_HwDeg_M_f32 + (SignDeltaTrgtAngle_Cnt_T_f32 * MaxVelocity_HwDegpSec_T_f32 * StateTime_Sec_M_f32);
		if (StateTime_Sec_M_f32 >= DeltaVelocity_Sec_T_f32)
		{	
			bDone_Cnt_T_lgc = TRUE;
		}
		else
		{
			bDone_Cnt_T_lgc = FALSE;
		}

		if (bDone_Cnt_T_lgc == TRUE)
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleCmd_HwDeg_T_f32;
			CmdState_Cnt_T_Enum = DECELERATION_STATE;
			StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		}
		else
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleOffsetIn_HwDeg_M_f32;
			CmdState_Cnt_T_Enum = CONSTANT_VEL_STATE;
			StateTime_Sec_T_f32 = StateTime_Sec_M_f32 + D_2MS_SEC_F32;
		}
		break;

	case DECELERATION_STATE: /* State 3 */

		HwAngleCmd_HwDeg_T_f32 = HwAngleOffsetIn_HwDeg_M_f32 + (SignDeltaTrgtAngle_Cnt_T_f32 * ((MaxVelocity_HwDegpSec_T_f32 * StateTime_Sec_M_f32) - ((MaxAccel_HwDegpSecSqr_T_f32/ 2) * (StateTime_Sec_M_f32 * StateTime_Sec_M_f32))));
		if (StateTime_Sec_M_f32 >= DeltaAccel_Sec_T_f32)
		{	
			bDone_Cnt_T_lgc = TRUE;
		}
		else
		{
			bDone_Cnt_T_lgc = FALSE;
		}

		if (bDone_Cnt_T_lgc == TRUE)
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleCmd_HwDeg_T_f32;
			CmdState_Cnt_T_Enum = HOLD_STATE;
			StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		}
		else
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleOffsetIn_HwDeg_M_f32;
			CmdState_Cnt_T_Enum = DECELERATION_STATE;
			StateTime_Sec_T_f32 = StateTime_Sec_M_f32 + D_2MS_SEC_F32;
		}
		break;

	case HOLD_STATE: /* State 4 */

		HwAngleCmd_HwDeg_T_f32 = HwAngleOffsetIn_HwDeg_M_f32;
		HwAngleOffset_HwDeg_T_f32 = HwAngleOffsetIn_HwDeg_M_f32;
		CmdState_Cnt_T_Enum = HOLD_STATE;
		StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		break;

	default:
	/* Do Nothing */
	break;
	
	} /* End of switch */

/* Copy temporary to module for the next run */
CmdState_Cnt_M_Enum = CmdState_Cnt_T_Enum;
HwAngleOffsetIn_HwDeg_M_f32 = HwAngleOffset_HwDeg_T_f32;
StateTime_Sec_M_f32 = StateTime_Sec_T_f32;

return(HwAngleCmd_HwDeg_T_f32);

}

#define RTE_STOP_SEC_AP_GENPOSTRAJ_APPL_CODE
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
