/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  NtWrap.c
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-MCV_UKL/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  NtWrap
 *  Generated at:  Tue Jan 14 11:02:27 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <NtWrap>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          EA3#16 %
 * %date_modified:    Tue Jan 14 17:35:14 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 10/30/12   1       JJW       Initial creation
 * 11/08/12   2       JJW       External function defintions
 * 11/09/12   3       JJW       Created SWC description for inclusion into Rte, and moved TRUSTED function wrappers into
 *								this module.
 * 11/14/12   4       JJW       Added NT wrappers for the Wdg and WdgM Init functions.  Restructured NT return to allow
 *								wrapper invocation from seperate priority levls without consistency concern.  Added Det 
 * 11/14/12   5       JJW       Added dummy periodic function for Rte mapping constraint
 * 11/14/12   6       JJW       Defined Wdg_TMS570LS3x_Init as a Trusted function call to place into privilaged mode required
 *								by function to all write to RTI control register to enable internal timebase.
 *								Defined WdgM_Init as a trusted function to allow initialization of all supervised entity dat
 *								spread across applications.
 * 11/20/12   7       JJW       Added Adc2_Init1 Trusted function call
 * 								Completed AbsHwPos_SetData_SetRacktoVehCntrOffset Trusted function call
 * 12/06/12   8       JJW       Added NT wrapper for TrqCmdScl
 * 01/14/13   9       JJW       Integration of CBD_Xcp_001.1
 * 01/17/13   10      JJW       Integration of Nxtr Adc driver
 * 03/15/13   12      KJS       Integration of turns counter manufacturing services. 
 * 04/03/13   13      KJS       Added calls for ProcessF0FF for CMS.
 * 04/11/13   14      KJS       Anomaly correction for 4707 with TC EOL Sensor cal reutrn. 						7814
 * 01/14/14   15	  KJS		Added support for LearnEOT
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Constants:
 ==========
  D_SFMILLI_ULS_F32
    Scale factor multiplier to convert a SI milli quantity into the standard SI unit (e.g. mm to m)

  D_SVCDFTDRIVINGDYN_CNT_B32
    Torque Overlay defeat is bit 13 per PID 0xFD02 in teh EA 3.0_Nxtr Common Mfg Serv Spec
     
     Bit 13 =  2^13=8192

  D_SVCDFTHYSTADD_CNT_B32
    Hysteresis Add defeat is bit 15 per PID 0xFD02 in the EA 3.0_Nxtr Common Mfg Serv Spec
     
     Bit 15 =  2^15=32768

  D_SVCDFTPARKAST_CNT_B32
    Parking Assist defeay is bit 12 per PID 0xFD02 in teh EA 3.0_Nxtr Common Mfg Serv Spec
     
     Bit 12 =  2^12=4096


 Runnable Entities:
 ==================
  NtWrap_Per1
    Dummy function to map this component onto an application for generation.

 *********************************************************************************************************************/

#include "Rte_NtWrap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define NTWRAP_C /* Expose SWC specific defintions in header */
#include "NtWrap.h"

#include "Cd_NvMProxy.h"
#include "PwmCdd.h"
#include "WdgM.h"
#include "WdgM_PBcfg.h"
#include "Wdg.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "Os.h"
#include "trustfct.h"
#include "Det.h"
#include "Adc.h"

/* There is no known appropriate header for the Rte_Start() definition, so it is defined as extern here */
extern Rte_Start(void);
extern void ApXcpWriteCommon(void);

 typedef union{
	 Std_ReturnType		Std_Return;
 }RetBuf_Type;
 
 /* This design provides a seperate return buffer for each non-trusted function interface.  This provides the ability to call non-trusted 
  * funcitons from different preemtion levels without concern for return buffer consistiency.  However, it does not all re-entrant calling
  * for the same function, since both invocations will be accessing the same buffer. 
  * The Os assigned non-trusted funciton index/id is used to index into the NtWrap_RetBuf[], therefore to have the minimum required size
  * for the return buffer, the functions with non-void return values shoulD be grouped together and starting at id 0.  Note that this
  * conifiguration grouping may not always be possible depending on the Os config, thus the array may contain some unused indexes.
  */
 
 #define D_NUMRETURNBUFF_CNT_U08	20u
 
#define NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(RetBuf_Type, AUTOMATIC) NtWrap_RetBuf[D_NUMRETURNBUFF_CNT_U08];
#define NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

 typedef struct{
	 float32 arg1_f32;
	 float32 arg2_f32;
	 float32 arg3_f32;
 }NtPar1_Type;
 
 typedef struct{
	 float32 arg1_f32;
	 uint8 	 arg2_u8;
	 float32 arg3_f32;
 }NtPar2_Type;

 typedef struct{
	 uint8 arg1_u8;
	 uint8 arg2_u8;
	 uint8 arg3_u8;
	 uint8 arg4_u8;
	 uint8 arg5_u8;
	 uint8 arg6_u8;
 }NtPar3_Type;

 
 
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
 * Array Types:
 * ============
 * DT_Array144_s8: Array with 144 element(s) of type SInt8
 * EOLTrqStepType: Array with 10 element(s) of type Float
 * TcPartNumType: Array with 20 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * EOLTurnsCntrCals_Datatype: Record with elements
 *   TcEolSineOffset_Cnt_u08 of type UInt8
 *   TcEolCosineOffset_Cnt_u08 of type UInt8
 *   TcEolSin2CosGain_Cnt_u08 of type UInt8
 *   TcEolSinVsCosMin_Cnt_u08 of type UInt8
 *   TcEolSinVsCosMax_Cnt_u08 of type UInt8
 *   TcEolCalChksm_Cnt_u08 of type UInt8
 * HwTrqScale_Datatype: Record with elements
 *   HwTrqScale_VoltsPerDeg_f32 of type Float
 *   HwTrqScalePerf_Cnt_lgc of type Boolean
 * HwTrqTrim_Datatype: Record with elements
 *   HwTrqTrim_Volts_f32 of type Float
 *   T1Trim_Volts_f32 of type Float
 *   T2Trim_Volts_f32 of type Float
 *   HwTrqTrimPerf_Cnt_lgc of type Boolean
 * MtrPosCal_DataType: Record with elements
 *   BEMFCal_Rev_u0p16 of type UInt16
 *   R_BEMFCal_Rev_u0p16 of type UInt16
 *   Sin1Offset_Volts_u3p13 of type UInt16
 *   Sin1AmpRec_Uls_u3p13 of type UInt16
 *   Cos1Offset_Volts_u3p13 of type UInt16
 *   Cos1AmpRec_Uls_u3p13 of type UInt16
 *   SinDelta1_Uls_s2p13 of type SInt16
 *   CosDelta1Rec_Uls_u3p13 of type UInt16
 *   Sin1OffCorr_Volts_s2p13 of type SInt16
 *   Sin1GainCorr_Uls_u1p15 of type UInt16
 *   Cos1OffCorr_Volts_s2p13 of type SInt16
 *   Cos1GainCorr_Uls_u1p15 of type UInt16
 *   SinHarTbl_Cnt_sm6p13 of type DT_Array144_s8
 *   CosHarTbl_Cnt_sm6p13 of type DT_Array144_s8
 * ShCurrCal_DataType: Record with elements
 *   EOLShcurrOffset_Volts_f32 of type Float
 *   EOLShcurrGain_Uls_f32 of type Float
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
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_MS_F32 = 0.002F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRCTRLHIGHLMT_VOLTS_F32 = 18.0F
 * Float: D_MTRCTRLLOWLMT_VOLTS_F32 = 9.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_MTRTRQCMLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
 * Float: D_SFMILLI_ULS_F32 = 0.001F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
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
 * UInt16: D_MAXCONF_ULS_U8P8 = 256U
 * UInt16: D_MTRPOLESDIV2_CNT_U16 = 3U
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_QUADRANT1_CNT_U16 = 1U
 * UInt16: D_QUADRANT2_CNT_U16 = 2U
 * UInt16: D_QUADRANT3_CNT_U16 = 3U
 * UInt16: D_QUADRANT4_CNT_U16 = 4U
 * UInt16: D_RACKCNTRUNLEARNED_CNT_U16 = 65535U
 * UInt16: D_RACKTOVEHCNTRINVALID_CNT_U16 = 4095U
 * UInt16: D_RACKTOVEHCNTRUNLEARNED_CNT_U16 = 4095U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_SVCDFTDAMPING_CNT_B32 = 131072U
 * UInt32: D_SVCDFTDRIVINGDYN_CNT_B32 = 8192U
 * UInt32: D_SVCDFTENGON_CNT_B32 = 1U
 * UInt32: D_SVCDFTEOTIMPACT_CNT_B32 = 16U
 * UInt32: D_SVCDFTEOTTHERMAL_CNT_B32 = 32U
 * UInt32: D_SVCDFTFREQDEPDMP_CNT_B32 = 2U
 * UInt32: D_SVCDFTHYSTADD_CNT_B32 = 32768U
 * UInt32: D_SVCDFTHYSTCOMP_CNT_B32 = 16384U
 * UInt32: D_SVCDFTKININTDIAG_CNT_B32 = 4U
 * UInt32: D_SVCDFTMODIDX_CNT_B32 = 512U
 * UInt32: D_SVCDFTMTRPARMNRMLRN_CNT_B32 = 128U
 * UInt32: D_SVCDFTMTRVELNRMLRN_CNT_B32 = 64U
 * UInt32: D_SVCDFTMULTIGNMASK_CNT_B32 = 1342177280U
 * UInt32: D_SVCDFTPARKAST_CNT_B32 = 4096U
 * UInt32: D_SVCDFTPULLCOMP_CNT_B32 = 1024U
 * UInt32: D_SVCDFTRETURN_CNT_B32 = 65536U
 * UInt32: D_SVCDFTRXMSGS_CNT_B32 = 134217728U
 * UInt32: D_SVCDFTTHERMALDC_CNT_B32 = 8U
 * UInt32: D_SVCDFTTRQRMP_CNT_B32 = 256U
 * UInt32: D_SVCDFTWHLIMBREJ_CNT_B32 = 2048U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_TURNSCNTRPARTNUMINIT_CNT_U08 = 255U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_NTWRAP_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SCom_VehicleSystemStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehicleSystemStatus> of PortPrototype <AbsHwPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SCom_VehicleSystemStatus(SInt16 *NCMAbsHwPos_HwDeg_s11p4)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_AbsHwPos_SCom_VehicleSystemStatus(SInt16 *NCMAbsHwPos_HwDeg_s11p4)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_SCom_VehicleSystemStatus(P2VAR(SInt16, AUTOMATIC, RTE_NTWRAP_APPL_VAR) NCMAbsHwPos_HwDeg_s11p4)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_AbsHwPos_SCom_VehicleSystemStatus
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_AbsHwPos_SCom_VehicleSystemStatus_args. os_arg_NCMAbsHwPos_HwDeg_s11p4 =  NCMAbsHwPos_HwDeg_s11p4;
   (void) CallTrustedFunction(NtWrapS_AbsHwPos_SCom_VehicleSystemStatus, &myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_Scom_ClearRacktoVehCntrOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearRacktoVehCntrOffset> of PortPrototype <RacktoVehCntrOffset_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_RacktoVehCntrOffset_Scom_ClearRacktoVehCntrOffset(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_AbsHwPos_Scom_ClearRacktoVehCntrOffset
 *********************************************************************************************************************/
   (void) CallTrustedFunction(NtWrapS_AbsHwPos_Scom_ClearRacktoVehCntrOffset, (TrustedFunctionParameterRefType)0);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPos_SetData_SetRacktoVehCntrOffset
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetRacktoVehCntrOffset> of PortPrototype <AbsHwPos_SetData>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_AbsHwPos_SetData_SetRacktoVehCntrOffset
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_AbsHwPos_SetData_SetRacktoVehCntrOffset_args.os_arg_RackCntr_HwDeg_P_f32 = RackCntr_HwDeg_P_f32;
   myargs.NtWrapS_AbsHwPos_SetData_SetRacktoVehCntrOffset_args.os_arg_LTRckCntrComplete_Cnt_P_lgc =  LTRckCntrComplete_Cnt_P_lgc;
   (void) CallTrustedFunction(NtWrapS_AbsHwPos_SetData_SetRacktoVehCntrOffset, &myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistLmtFunc_Scom_ManualTrqCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualTrqCmd> of PortPrototype <AssistLmtFunc_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_AssistLmtFunc_Scom_ManualTrqCmd
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd_args. os_arg_EnableManualCtrl =  EnableManualCtrl;
   myargs.NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd_args. os_arg_MtrTrqCmd_MtrNm_f32 =  MtrTrqCmd_MtrNm_f32;
   (void) CallTrustedFunction(NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd, &myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GeneratePosTraj_SCom_SetInputParam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetInputParam> of PortPrototype <GeneratePosTraj_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_GeneratePosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_GenPosTraj_SCom_SetInputParam
 *********************************************************************************************************************/
	NtPar1_Type par; 

	par.arg1_f32 = PosServHwAngle_HwDeg_f32;
	par.arg2_f32 = TargetVelocity_HwDegpSec_f32;
	par.arg3_f32 = TargetAcceleration_HwDegpSecSqr_f32;
	
	CallNonTrustedFunction(NtWrapS_GenPosTraj_SCom_SetInputParam, (NonTrustedFunctionParameterRefType)&par);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ClrHwTrqScale
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqScale> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTrq_SCom_ClrHwTrqScale(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTrq_SCom_ClrHwTrqScale(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqScale(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrq_SCom_ClrHwTrqScale (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_HwTrq_SCom_ClrHwTrqScale, (NonTrustedFunctionParameterRefType)NULL_PTR);

	return(NtWrap_RetBuf[NtWrapS_HwTrq_SCom_ClrHwTrqScale].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ClrHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTrq_SCom_ClrHwTrqTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTrq_SCom_ClrHwTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrq_SCom_ClrHwTrqTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_HwTrq_SCom_ClrHwTrqTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);

	return(NtWrap_RetBuf[NtWrapS_HwTrq_SCom_ClrHwTrqTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_ManualSetHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualSetHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTrq_SCom_ManualSetHwTrqTrim(const HwTrqTrim_Datatype *HwTrqTrimDataPtr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim(const HwTrqTrim_Datatype *HwTrqTrimDataPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_HwTrq_SCom_ManualSetHwTrqTrim, (NonTrustedFunctionParameterRefType)HwTrqTrimDataPtr);

	return(NtWrap_RetBuf[NtWrapS_HwTrq_SCom_ManualSetHwTrqTrim].Std_Return);	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetEOLTrqStep
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLTrqStep> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_C_HwTrq_SCom_SetEOLTrqStep(const Float *TrqStep_HwNm_T_f32)
#else
 *   Std_ReturnType Rte_Call_C_HwTrq_SCom_SetEOLTrqStep(const EOLTrqStepType *TrqStep_HwNm_T_f32)
#endif
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void NtWrapC_HwTrq_SCom_SetEOLTrqStep(const Float *TrqStep_HwNm_T_f32)
#else
 *   void NtWrapC_HwTrq_SCom_SetEOLTrqStep(const EOLTrqStepType *TrqStep_HwNm_T_f32)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetEOLTrqStep(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) TrqStep_HwNm_T_f32)
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) TrqStep_HwNm_T_f32)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrq_SCom_SetEOLTrqStep
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_HwTrq_SCom_SetEOLTrqStep, (NonTrustedFunctionParameterRefType)TrqStep_HwNm_T_f32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetHwTrqScale
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqScale> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTrq_SCom_SetHwTrqScale(Float ScaleValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTrq_SCom_SetHwTrqScale(Float ScaleValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetHwTrqScale(Float ScaleValue)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrq_SCom_SetHwTrqScale (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_HwTrq_SCom_SetHwTrqScale, (NonTrustedFunctionParameterRefType)&ScaleValue);

	return(NtWrap_RetBuf[NtWrapS_HwTrq_SCom_SetHwTrqScale].Std_Return);	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrq_SCom_SetHwTrqTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqTrim> of PortPrototype <HwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTrq_SCom_SetHwTrqTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTrq_SCom_SetHwTrqTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrq_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetHwTrqTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrq_SCom_SetHwTrqTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_HwTrq_SCom_SetHwTrqTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	
	return(NtWrap_RetBuf[NtWrapS_HwTrq_SCom_SetHwTrqTrim].Std_Return);	
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_LktoLkStr_SCom_SetInputParam
 *********************************************************************************************************************/
	NtPar1_Type par; 

	par.arg1_f32 = TargetVelocity_HwDegpSec_f32;
	par.arg2_f32 = TargetAcceleration_HwDegpSecSqr_f32;
	
	CallNonTrustedFunction(NtWrapS_LktoLkStr_SCom_SetInputParam, (NonTrustedFunctionParameterRefType)&par);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnEOT_Scom_ResetEOT
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetEOT> of PortPrototype <LrnEOT_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_LrnEOT_Scom_ResetEOT(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_LrnEOT_Scom_ResetEOT(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_LrnEOT_Scom_ResetEOT(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_LrnEOT_Scom_ResetEOT
 *********************************************************************************************************************/
	(void)CallTrustedFunction(NtWrapS_LrnEOT_Scom_ResetEOT, (TrustedFunctionParameterRefType)0);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_CalGain
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalGain> of PortPrototype <MtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_MtrCurr_SCom_CalGain(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_MtrCurr_SCom_CurrentOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_MtrCurr_SCom_CalGain(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_MtrCurr_SCom_CurrentOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_CalGain(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_MtrCurr_SCom_CalGain (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_MtrCurr_SCom_CalGain, (NonTrustedFunctionParameterRefType)NULL_PTR);

	return(NtWrap_RetBuf[NtWrapS_MtrCurr_SCom_CalGain].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_CalOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalOffset> of PortPrototype <MtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_MtrCurr_SCom_CalOffset(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_MtrCurr_SCom_CalOffset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_CalOffset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_MtrCurr_SCom_CalOffset
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_MtrCurr_SCom_CalOffset, (NonTrustedFunctionParameterRefType)NULL_PTR);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_SetMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMtrCurrCals> of PortPrototype <MtrCurr_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_MtrCurr_SCom_SetMtrCurrCals(const ShCurrCal_DataType *ShCurrCalPtr)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_MtrCurr_SCom_SetMtrCurrCals(const ShCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_MtrCurr_SCom_SetMtrCurrCals
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_MtrCurr_SCom_SetMtrCurrCals, (NonTrustedFunctionParameterRefType)ShCurrCalPtr);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos_SCom_SetEOLMtrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEOLMtrCals> of PortPrototype <MtrPos_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_MtrPos_SCom_SetEOLMtrCals(const MtrPosCal_DataType *MtrCalDataPtr)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_MtrPos_SCom_SetEOLMtrCals(const MtrPosCal_DataType *MtrCalDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrCalDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_MtrPos_SCom_SetEOLMtrCals
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_MtrPos_SCom_SetEOLMtrCals_args. os_arg_MtrCalDataPtr =  MtrCalDataPtr;
   (void) CallTrustedFunction(NtWrapS_MtrPos_SCom_SetEOLMtrCals, &myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrap_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrap_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrap_Per1
 *********************************************************************************************************************/


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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_OscTraj_SCom_SetInputParams
 *********************************************************************************************************************/
	NtPar2_Type par; 

	par.arg1_f32 = Amplitude_HwDeg_f32;
	par.arg2_u8 = Cycles_Cnt_u08;
	par.arg3_f32 = Frequency_Hz_f32;
	
	CallNonTrustedFunction(NtWrapS_OscTraj_SCom_SetInputParams, (NonTrustedFunctionParameterRefType)&par);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_SCom_SetPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Polarity_SCom_RequestOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Call_Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Polarity_SCom_RequestOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) Call_Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_Polarity_SCom_SetPolarity (returns application error)
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_Polarity_SCom_SetPolarity_args.os_arg_Polarity_Cnt_b16 = Polarity_Cnt_b16;
   (void) CallTrustedFunction(NtWrapS_Polarity_SCom_SetPolarity, &myargs);
   return (myargs.NtWrapS_Polarity_SCom_SetPolarity_args.os_result);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_EOLNomMtrParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_SCom_EOLNomMtrParam_Set
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_SCom_EOLNomMtrParam_Set_args. os_arg_NomKe_VpRadpS_f32 =  NomKe_VpRadpS_f32;
   myargs.NtWrapS_SCom_EOLNomMtrParam_Set_args. os_arg_NomLq_Henry_f32 =  NomLq_Henry_f32;
   myargs.NtWrapS_SCom_EOLNomMtrParam_Set_args. os_arg_NomRmtr_Ohm_f32 =  NomRmtr_Ohm_f32;
   (void) CallTrustedFunction(NtWrapS_SCom_EOLNomMtrParam_Set, &myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_KeIntgSVParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_KeIntgSVParam>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_SCom_KeIntgSVParam_Set
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_SCom_KeIntgSVParam_Set_args. os_arg_KeIntgSV_Amp_f32 =  KeIntgSV_Amp_f32;
   (void) CallTrustedFunction(NtWrapS_SCom_KeIntgSVParam_Set, &myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_RIntgSVParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_RIntgSVParam>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_SCom_RIntgSVParam_Set
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_SCom_RIntgSVParam_Set_args. os_arg_RIntgSV_Amp_f32 =  RIntgSV_Amp_f32;
   (void) CallTrustedFunction(NtWrapS_SCom_RIntgSVParam_Set, &myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_SrlComInput2_SCom_ManualVehSpd
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_SrlComInput2_SCom_ManualVehSpd_args. os_arg_VehSpd_Kph_f32 =  VehSpd_Kph_f32;
   (void) CallTrustedFunction(NtWrapS_SrlComInput2_SCom_ManualVehSpd, &myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StaMd_SCom_EcuReset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EcuReset> of PortPrototype <StaMd_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_StaMd_SCom_EcuReset(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_StaMd_SCom_EcuReset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_StaMd_SCom_EcuReset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_StaMd_SCom_EcuReset
 *********************************************************************************************************************/
   (void) CallTrustedFunction(NtWrapS_StaMd_SCom_EcuReset, (TrustedFunctionParameterRefType)0);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCmdScl_SCom_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <TrqCmdScl_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TrqCmdScl_SCom_Set(Float Par_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_TrqCmdScl_SCom_Set(Float Par_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_TrqCmdScl_SCom_Set(Float Par_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_TrqCmdScl_SCom_Set
 *********************************************************************************************************************/
	   TrustedFunctionParameterType myargs;

	   myargs.NtWrapS_TrqCmdScl_SCom_Set_args.os_arg_Par_f32 = Par_f32;

	   (void) CallTrustedFunction(NtWrapS_TrqCmdScl_SCom_Set, (TrustedFunctionParameterRefType)&myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Scom_ClearTcEOLCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearTcEOLCals> of PortPrototype <TcEOLCals_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TcEOLCals_Scom_ClearTcEOLCals(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_TurnsCounter_SCom_ClearTcEOLCals(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_SCom_ClearTcEOLCals(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TurnsCounter_SCom_ClearTcEOLCals
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_TcEOLCals_Scom_ClearTcEOLCals, (NonTrustedFunctionParameterRefType)NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Scom_ResetTC
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTC> of PortPrototype <TurnsCounter_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TurnsCounter_Scom_ResetTC(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_TurnsCounter_SCom_ResetTC(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_SCom_ResetTC(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TurnsCounter_SCom_ResetTC
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_TurnsCounter_SCom_ResetTC, (NonTrustedFunctionParameterRefType)NULL_PTR);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Scom_SetTcEOLCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetTcEOLCals> of PortPrototype <TcEOLCals_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TcEOLCals_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TcEOLCals_Scom_RequestDataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_TurnsCounter_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TcEOLCals_Scom_RequestDataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_TurnsCounter_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TurnsCounter_Scom_SetTcEOLCals (returns application error)
 *********************************************************************************************************************/
	NtPar3_Type par;

	par.arg1_u8 = TcEolSineOffset_Cnt_P_u8;
	par.arg2_u8 = TcEolCosineOffset_Cnt_P_u8;
	par.arg3_u8 = TcEolSin2CosGain_Cnt_P_u8;
	par.arg4_u8 = TcEolSinVsCosMin_Cnt_P_u8;
	par.arg5_u8 = TcEolSinVsCosMax_Cnt_P_u8;
	par.arg6_u8 = TcEolCalChksm_Cnt_P_u8;

	CallNonTrustedFunction(NtWrapS_TcEOLCals_Scom_SetTcEOLCals, (NonTrustedFunctionParameterRefType)&par);
	
	return(NtWrap_RetBuf[NtWrapS_TcEOLCals_Scom_SetTcEOLCals].Std_Return);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehicleCenter_Scom_ClearCenterPosition
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearCenterPosition> of PortPrototype <VehicleCenter_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_VehicleCenter_Scom_ClearCenterPosition(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Call_AbsHwPos_Scom_ClearCenterPosition(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_ClearCenterPosition(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_AbsHwPos_Scom_ClearCenterPosition
 *********************************************************************************************************************/
   (void) CallTrustedFunction(NtWrapS_AbsHwPos_Scom_ClearCenterPosition, (TrustedFunctionParameterRefType)0);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehicleCenter_Scom_SetCenterPosition
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetCenterPosition> of PortPrototype <VehicleCenter_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_VehicleCenter_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VehicleCenter_Scom_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Call_AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_VehicleCenter_Scom_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Call_AbsHwPos_Scom_SetCenterPosition (returns application error)
 *********************************************************************************************************************/
   TrustedFunctionParameterType myargs;

   myargs.NtWrapS_AbsHwPos_Scom_SetCenterPosition_args. os_arg_Offset_HwDeg_P_f32 =  Offset_HwDeg_P_f32;
   (void) CallTrustedFunction(NtWrapS_AbsHwPos_Scom_SetCenterPosition, &myargs);
   return myargs.NtWrapS_AbsHwPos_Scom_SetCenterPosition_args.os_result;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_NTWRAP_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/********************************************************************************************************
 * Client side (Non-Rte) Wrappers (NONTRUSTED API)
 *******************************************************************************************************/
 
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Adc_Init()
{
	CallNonTrustedFunction(NtWrapS_Adc_Init, (NonTrustedFunctionParameterRefType)NULL_PTR);
}

 
/********************************************************************************************************
 * Server side Wrappers (NONTRUSTED API)
 *******************************************************************************************************/
/*TODO: Provide a pointer validation check prior to use to ensure freedom of interference that would result from using an invalid pointer
 * provided by a seperate application */

/*********************
 * Ap_7 Wrappers
 *********************/
/* Non-Trusted Adc_Init Function */
void NONTRUSTED_NtWrapS_Adc_Init(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Adc_Init(&AdcConfigSet);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_GenPosTraj_SCom_SetInputParam(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_GeneratePosTraj_SCom_SetInputParam(	((NtPar1_Type*)par)->arg1_f32,
									((NtPar1_Type*)par)->arg2_f32,
									((NtPar1_Type*)par)->arg3_f32);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_HwTrq_SCom_ClrHwTrqScale(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)	
	if(index >= D_NUMRETURNBUFF_CNT_U08)  {
		NtWrap_ReportDet( D_NTWRAPINVLDINDXDET_CNT_U08 );
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_HwTrq_SCom_ClrHwTrqScale();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_HwTrq_SCom_ClrHwTrqTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)	
	if(index >= D_NUMRETURNBUFF_CNT_U08)  {
		NtWrap_ReportDet( D_NTWRAPINVLDINDXDET_CNT_U08 );
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_HwTrq_SCom_ClrHwTrqTrim();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_HwTrq_SCom_ManualSetHwTrqTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_HwTrq_SCom_ManualSetHwTrqTrim((HwTrqTrim_Datatype*)par);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_HwTrq_SCom_SetEOLTrqStep(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_HwTrq_SCom_SetEOLTrqStep((const EOLTrqStepType*)par);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_HwTrq_SCom_SetHwTrqScale(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)	
	if(index >= D_NUMRETURNBUFF_CNT_U08)  {
		NtWrap_ReportDet( D_NTWRAPINVLDINDXDET_CNT_U08 );
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_HwTrq_SCom_SetHwTrqScale(*(float32*)par);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_HwTrq_SCom_SetHwTrqTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)	
	if(index >= D_NUMRETURNBUFF_CNT_U08)  {
		NtWrap_ReportDet( D_NTWRAPINVLDINDXDET_CNT_U08 );
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_HwTrq_SCom_SetHwTrqTrim();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_LktoLkStr_SCom_SetInputParam(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_LktoLkStr_SCom_SetInputParam(	((NtPar1_Type*)par)->arg1_f32,
									((NtPar1_Type*)par)->arg2_f32);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_MtrCurr_SCom_CalGain(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)	
	if(index >= D_NUMRETURNBUFF_CNT_U08)  {
		NtWrap_ReportDet( D_NTWRAPINVLDINDXDET_CNT_U08 );
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_MtrCurr_SCom_CalGain();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_MtrCurr_SCom_CalOffset(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_MtrCurr_SCom_CalOffset();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_MtrCurr_SCom_SetMtrCurrCals(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_MtrCurr_SCom_SetMtrCurrCals((ShCurrCal_DataType*)par);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_OscTraj_SCom_SetInputParams(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_OscTraj_SCom_SetInputParams(	((NtPar2_Type*)par)->arg1_f32,
									((NtPar2_Type*)par)->arg2_u8,
									((NtPar2_Type*)par)->arg3_f32);
}


void NONTRUSTED_NtWrapS_TcEOLCals_Scom_SetTcEOLCals(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
		if(index >= D_NUMRETURNBUFF_CNT_U08)
		{
			NtWrap_ReportDet( D_NTWRAPINVLDINDXDET_CNT_U08 );
		}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_TcEOLCals_Scom_SetTcEOLCals( ((NtPar3_Type*)par)->arg1_u8, ((NtPar3_Type*)par)->arg2_u8, ((NtPar3_Type*)par)->arg3_u8,
																			  ((NtPar3_Type*)par)->arg4_u8, ((NtPar3_Type*)par)->arg5_u8, ((NtPar3_Type*)par)->arg6_u8);

}

void NONTRUSTED_NtWrapS_TcEOLCals_Scom_ClearTcEOLCals(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_TcEOLCals_Scom_ClearTcEOLCals();
}

void NONTRUSTED_NtWrapS_TurnsCounter_SCom_ResetTC(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_TurnsCounter_Scom_ResetTC();
}

void NONTRUSTED_NtWrapS_XcpWriteAp9(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	ApXcpWriteCommon();
}

void NONTRUSTED_NtWrapS_XcpWriteAp11(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	ApXcpWriteCommon();
}

void NONTRUSTED_NtWrapS_XcpWriteAp8(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	ApXcpWriteCommon();
}

void NONTRUSTED_NtWrapS_XcpWriteAp7(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	ApXcpWriteCommon();
}
/********************************************************************************************************
 * Server side Wrappers (TRUSTED API)
 *******************************************************************************************************/
/*TODO: Provide a pointer validation check prior to use to ensure freedom of interference that would result from using an invalid pointer
 * provided by a seperate application */

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_Adc2_Init1(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
   Adc2_Init1();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_NvMProxy_Init(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
   NvMProxy_Init();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_MtrPos_SCom_SetEOLMtrCals(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_MtrPos_SCom_SetEOLMtrCals(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_MtrPos_SCom_SetEOLMtrCals_args. os_arg_MtrCalDataPtr);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_Rte_Start(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
   Rte_Start();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_PwmCdd_Init(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
   PwmCdd_Init();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_AbsHwPos_SCom_VehicleSystemStatus(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_AbsHwPos_SCom_VehicleSystemStatus(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_AbsHwPos_SCom_VehicleSystemStatus_args. os_arg_NCMAbsHwPos_HwDeg_s11p4);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_AbsHwPos_Scom_ClearCenterPosition(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_VehicleCenter_Scom_ClearCenterPosition();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_AbsHwPos_Scom_ClearRacktoVehCntrOffset(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_RacktoVehCntrOffset_Scom_ClearRacktoVehCntrOffset();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_AbsHwPos_Scom_SetCenterPosition(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
   ((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_AbsHwPos_Scom_SetCenterPosition_args.os_result = AbsHwPos_Scom_SetCenterPosition(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_AbsHwPos_Scom_SetCenterPosition_args. os_arg_Offset_HwDeg_P_f32);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_AbsHwPos_SetData_SetRacktoVehCntrOffset(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	AbsHwPos_SetData_SetRacktoVehCntrOffset(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_AbsHwPos_SetData_SetRacktoVehCntrOffset_args.os_arg_RackCntr_HwDeg_P_f32,
            						((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_AbsHwPos_SetData_SetRacktoVehCntrOffset_args.os_arg_LTRckCntrComplete_Cnt_P_lgc);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
   Rte_Call_C_AssistLmtFunc_Scom_ManualTrqCmd(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd_args. os_arg_EnableManualCtrl,
                                   ((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd_args. os_arg_MtrTrqCmd_MtrNm_f32);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_SrlComInput2_SCom_ManualVehSpd(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_SrlComInput_SCom_ManualVehSpd(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_SrlComInput2_SCom_ManualVehSpd_args. os_arg_VehSpd_Kph_f32);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_StaMd_SCom_EcuReset(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_StaMd_SCom_EcuReset();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_SCom_EOLNomMtrParam_Set(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_SCom_EOLNomMtrParam_Set(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_SCom_EOLNomMtrParam_Set_args. os_arg_NomKe_VpRadpS_f32,
                           ((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_SCom_EOLNomMtrParam_Set_args. os_arg_NomLq_Henry_f32,
                           ((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_SCom_EOLNomMtrParam_Set_args. os_arg_NomRmtr_Ohm_f32);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_SCom_KeIntgSVParam_Set(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_SCom_KeIntgSVParam_Set(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_SCom_KeIntgSVParam_Set_args. os_arg_KeIntgSV_Amp_f32);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_SCom_RIntgSVParam_Set(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Rte_Call_C_SCom_RIntgSVParam_Set(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_SCom_RIntgSVParam_Set_args. os_arg_RIntgSV_Amp_f32);
}

/* Trusted SComm Server Function */
void TRUSTED_NtWrapS_Wdg_TMS570LS3x_Init(TrustedFunctionIndexType index, TrustedFunctionParameterRefType par)
{
	/* Limitied implementation, TODO: improve in the future to make more generic and accept a passed config parameter */
	/* The Wdg Init function requires privileged access to initalize the RTI register for enabling its internal timebase */
	Wdg_TMS570LS3x_Init(&wdg_tms570ls3x_config);
}

/* Trusted SComm Server wrapper Functions */
void TRUSTED_NtWrapS_WdgM_Init(TrustedFunctionIndexType index, TrustedFunctionParameterRefType par)
{
	/* Limitied implementation, TODO: improve in the future to make more generic and accept a passed config parameter */
	/* The WdgM init funciton appears to need access to all application memory for initlaization of the supervised entity variables */
	WdgM_Init(&WdgMConfig_Mode0);
}

/* Trusted SComm Server wrapper Functions */
void TRUSTED_NtWrapS_TrqCmdScl_SCom_Set(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams)   /* PRQA S 1505, 3673 */
{
	Rte_Call_C_TrqCmdScl_SCom_Set(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_TrqCmdScl_SCom_Set_args. os_arg_Par_f32);
}

void TRUSTED_NtWrapS_Polarity_SCom_SetPolarity(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	Rte_Call_C_Polarity_SCom_SetPolarity(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_Polarity_SCom_SetPolarity_args.os_arg_Polarity_Cnt_b16);
}

void TRUSTED_TWrapS_XcpWriteAp10(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams)
{
	ApXcpWriteCommon();
}

void TRUSTED_TWrapS_XcpWriteAp4(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams)
{
	ApXcpWriteCommon();
}

void TRUSTED_NtWrapS_ProcessF0FF(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams)
{
	ProcessF0FF(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_ProcessF0FF_args.os_arg_t_SrvcData_Cnt_T_u08, ((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_ProcessF0FF_args.os_arg_RequestDataIdx_Cnt_T_u16);
}

void TRUSTED_NtWrapS_LrnEOT_Scom_ResetEOT(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	Rte_Call_C_LrnEOT_Scom_ResetEOT();
}


/********************************************************************************************************
 *  Non C/S (TRUSTED API)
 *******************************************************************************************************/
void Call_Adc2_Init1(void)
{
   (void) CallTrustedFunction(NtWrapS_Adc2_Init1, (TrustedFunctionParameterRefType)0);
}

void Call_NvMProxy_Init(void)
{
   (void) CallTrustedFunction(NtWrapS_NvMProxy_Init, (TrustedFunctionParameterRefType)0);
}

void Call_Rte_Start(void)
{
   (void) CallTrustedFunction(NtWrapS_Rte_Start, (TrustedFunctionParameterRefType)0);
}

void Call_PwmCdd_Init(void)
{
   (void) CallTrustedFunction(NtWrapS_PwmCdd_Init, (TrustedFunctionParameterRefType)0);
}

Std_ReturnType NtWrapC_Wdg_TMS570LS3x_Init(P2CONST(Wdg_TMS570LS3x_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr)
{
   (void)CallTrustedFunction(NtWrapS_Wdg_TMS570LS3x_Init, (TrustedFunctionParameterRefType)ConfigPtr);

   /* returning fixed return type as a quick implementation.  Return actual value in future implementation */
   return(E_OK);
}

void NtWrapC_WdgM_Init(P2CONST (WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) WdgMConfigPtr)
{
   (void)CallTrustedFunction(NtWrapS_WdgM_Init, (TrustedFunctionParameterRefType)WdgMConfigPtr);
}

void Call_ProcessF0FF(P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) RequestDataIdx_Cnt_T_u16)
{
	VAR(TrustedFunctionParameterType, AUTOMATIC) myargs;

	myargs.NtWrapS_ProcessF0FF_args.os_arg_RequestDataIdx_Cnt_T_u16 = RequestDataIdx_Cnt_T_u16;
	myargs.NtWrapS_ProcessF0FF_args.os_arg_t_SrvcData_Cnt_T_u08 = t_SrvcData_Cnt_T_u08;

 	(void)CallTrustedFunction(NtWrapS_ProcessF0FF, &myargs);
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
