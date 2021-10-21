/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_VltgCtrl.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_VltgCtrl
 *  Generated at:  Sat Apr 13 16:57:56 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_VltgCtrl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Sun Dec 4 17:16:01 2011
 * %version:          19 %
 * %derived_by:       nz63rn %
 * %date_modified:    Thu Sep  5 16:26:26 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 12/07/11   2       JJW       Bilinear use cast correction 
 * 13/12/11   3       NRAR      In per3, Limit macro is added for LmtdModIdx
 * 09/23/12   4        Selva      Checkpoints added and mempmap macros corrected		                          6255
 * 09/23/12   7		   Selva      Corrected for missing semicolons in memmap statements                           6255  
 * 10/26/12	  8       Selva		 Code Changes for Integration in MtrCtrl_VM (Refer FDD 06B Ver 4)
 * 11/04/12	  9       Selva		 Bilinear lookup table corrected with P2CONST macro fort2_Id DesTblYM_Amp_s11p4	 
 * 02/05/13	 10,11       Selva		 Updated for MtrCtrl_VM version 7 SF99A
 * 03/08/13   12       Selva       Updated to FDD SF99 v8
 * 03/13/13   13       Selva      Fixed Anomoly  4627
 * 4/12/13	  14,15,16,17    Selva		 Updated for MtrCtrl_VM version 9
 * 5/13/13		18		Selva		Updated the Max CuTempEst from 150	to 200 
 * 9/5/13	  19		KMC			Updated max CuTempEst from 200 to 300; updated fixed point data type         10049
 *                                      for CuTempEst; QAC updates                                        
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


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_VltgCtrl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "interpolation.h"
#include "Ap_VltgCtrl_Cfg.h"
#include "MtrCtrl.h"

#include <math.h>
#include <float.h>

#define D_IDDESDELTAX_MTRRADPS_U12P4		FPM_InitFixedPoint_m(25.0, u12p4_T)
#define D_MODIDXMAX_ULS_F32					1.0F
#define D_TERMAMAX_VOLT_F32					83.9F
#define D_TERMBMAX_VOLT_F32					44.2288F
#define D_TERMDMAX_VOLT_F32					238.1812348F
#define D_TERMEMIN_VOLT_F32					(-21.7632184F)
#define D_TERMEMAX_VOLT_F32					0.0F
#define D_TERMXMAX_ULS_F32					275.028F
#define D_TERMYMAX_ULS_F32					26631.36308F

#define D_SQRT3OVR2_ULS_F32					0.866025403784F
#define D_MINCUTEMPEST_DEGC_F32             (-50.0F)
#define D_MAXCUTEMPEST_DEGC_F32				300.0F
#define D_MINVECU_VOLT_F32                 5.0F
#define D_MAXVECU_VOLT_F32                 31.0F
#define D_MINMTRENVSPD_MTRRADPS_F32         0.0F
#define D_MAXMTRENVSPD_MTRRADPS_F32         1118.0F 
#define D_COUNTERLIMIT_CNT_U16				100U

#define D_CORRPHSADVSCALEADJ_CNT_U8			8U
#define D_CORRPHSADVMAX_CNT_S16				1536
#define D_MAXDELTAVAL_CNT_U16               192
#define D_UNCORRPHSADVMAX_CNT_S16 			192
#define D_TWO_ULS_S16						2 /*Used for converting pi/2 to pi*/


#define VLTGCTRL_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_VLTGCTRL_VAR_NOINIT) IdDesTblX_MtrRadpS_M_u12p4[TableSize_m(t2_IdDesTblYM_Amp_s8p7[0])];
STATIC VAR(uint16, AP_VLTGCTRL_VAR_NOINIT) PDOverrideCounter_Cnt_M_u16;
STATIC volatile VAR(sint16, AP_VLTGCTRL_VAR_NOINIT) DisplayAfterUncorrPhsAdv_Cnt_D_s16;
STATIC volatile VAR(uint16, AP_VLTGCTRL_VAR_NOINIT) PhaseCorrec_Cnt_D_u16;
#define VLTGCTRL_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define VLTGCTRL_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermA_Volt_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermB_Volt_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermBTOT_Volt_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermD_Volt_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermE_Volt_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermETOT_Volt_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermXd_Uls_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermXq_Uls_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermY_Uls_M_f32;
STATIC VAR(float32, AP_VLTGCTRL_VAR_NOINIT) LmtdModIdx_Uls_M_f32;
STATIC VAR(float32, AUTOMATIC) PreTermG_Volt_M_f32 ;
STATIC VAR(float32, AUTOMATIC)  TermTauD_Uls_M_f32;
STATIC VAR(float32, AUTOMATIC) Vqcoef_Uls_M_f32[7];
STATIC VAR(float32, AUTOMATIC) Vdcoef_Uls_M_f32[7];
STATIC VAR(float32, AUTOMATIC) VqTerm_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) VdTerm_Volt_M_f32;
STATIC volatile VAR(float32,AUTOMATIC) TermH_Volt_D_f32;
STATIC volatile VAR(float32,AUTOMATIC) KTimeConstanst_Uls_D_f32;
STATIC volatile VAR(float32, AUTOMATIC) IntTermG_Volt_D_f32;
STATIC volatile VAR(float32,AUTOMATIC) TermGInput_Volt_D_f32;
STATIC volatile VAR(float32,AUTOMATIC) TermGOutput_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermZ_Uls_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) VoltageLimit_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) IdDes_Amp_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) VdTerm_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) VqTerm_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) VFinal_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) VltgDenom_Uls_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermBDerifinal_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermEDeriScalefinal_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermBDeri_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) TermEDeriScale_Volt_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) SineLkpTbl_Uls_D_f32;
STATIC volatile VAR(float32, AP_VLTGCTRL_VAR_NOINIT) IdDesRaw_Amp_D_f32;
#define VLTGCTRL_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define VLTGCTRL_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_VLTGCTRL_VAR_NOINIT) PDTestTimeNOTElapsed_Cnt_M_lgc;
#define VLTGCTRL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


STATIC INLINE FUNC(float32, AP_VLTGCTRL_CODE) CalcIdDes(	VAR(float32, AUTOMATIC) MRFMtrVel_MtrRadpS_T_f32, 
															VAR(float32, AUTOMATIC) MRFMtrTrqCmd_MtrNm_T_f32,
															VAR(float32, AUTOMATIC) MtrEnvSpd_MtrRadpS_T_f32,
															VAR(float32, AUTOMATIC) CuTempEst_DegC_T_f32);
															
STATIC INLINE FUNC(float32, AP_VLTGCTRL_CODE) LowPassFilter( VAR(float32, AUTOMATIC) TermG_Volt_T_f32);

STATIC INLINE FUNC(float32, AP_VLTGCTRL_CODE) Filter_WindowCoff (VAR(float32, AUTOMATIC) InputDeri_Uls_T_f32, P2CONST(float32, AUTOMATIC, AUTOMATIC)TableCalCoff, P2VAR(float32, AUTOMATIC, AUTOMATIC)StateVar_Uls_T_f32 );
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


#define RTE_START_SEC_AP_VLTGCTRL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VltgCtrl_Init1
 *********************************************************************************************************************/
	uint8 i;
	
	for (i = 0U; i < TableSize_m(t2_IdDesTblYM_Amp_s8p7[0]); i++)
	{
		IdDesTblX_MtrRadpS_M_u12p4[i] = (i * D_IDDESDELTAX_MTRRADPS_U12P4);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Per1
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
 *   Float Rte_IRead_VltgCtrl_Per1_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per1_EstR_Ohm_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per1_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VltgCtrl_Per1_TermBSS_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per1_TermBSS_Volt_f32(void)
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VltgCtrl_Per1
 *********************************************************************************************************************/
    
	VAR(float32, AUTOMATIC) MRFMtrTrqCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) EstKe_VpRadpS_T_f32;
	VAR(float32, AUTOMATIC) EstR_Ohm_T_f32;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_VltgCtrl_Per1_CP0_CheckpointReached();

	MRFMtrTrqCmd_MtrNm_T_f32 = Rte_IRead_VltgCtrl_Per1_MRFMtrTrqCmdScl_MtrNm_f32();
	EstKe_VpRadpS_T_f32 = Rte_IRead_VltgCtrl_Per1_EstKe_VpRadpS_f32();
	EstR_Ohm_T_f32 = Rte_IRead_VltgCtrl_Per1_EstR_Ohm_f32();
	
	TermB_Volt_M_f32 = (MRFMtrTrqCmd_MtrNm_T_f32 * EstR_Ohm_T_f32) / EstKe_VpRadpS_T_f32;
	
	TermB_Volt_M_f32 = Limit_m(TermB_Volt_M_f32, -D_TERMBMAX_VOLT_F32, D_TERMBMAX_VOLT_F32);

	Rte_IWrite_VltgCtrl_Per1_TermBSS_Volt_f32(TermB_Volt_M_f32);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_VltgCtrl_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Per2
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
 *   Float Rte_IRead_VltgCtrl_Per2_CuTempEst_DegC_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_EstLd_Henry_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_EstLq_Henry_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_EstR_Ohm_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per2_MtrEnvSpd_MtrRadpS_f32(void)
 *   UInt8 Rte_IRead_VltgCtrl_Per2_MtrQuad_Cnt_u08(void)
 *   Float Rte_IRead_VltgCtrl_Per2_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VltgCtrl_Per2_TermA_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermA_Volt_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermBTOT_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermBTOT_Volt_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermXd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermXd_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermXq_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermXq_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermY_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermY_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_TermZ_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_TermZ_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_VdTerm_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_VdTerm_Volt_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per2_VqTerm_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per2_VqTerm_Volt_f32(void)
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VltgCtrl_Per2
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) EstKe_VpRadpS_T_f32;
	VAR(float32, AUTOMATIC) EstR_Ohm_T_f32;
	VAR(float32, AUTOMATIC) EstLq_Henry_T_f32;
	VAR(float32, AUTOMATIC) EstLd_Henry_T_f32;
	VAR(float32, AUTOMATIC) MRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MRFMtrTrqCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) TermZ_Uls_T_f32;
	VAR(float32, AUTOMATIC) WeLq_Ohm_T_f32;
	VAR(float32, AUTOMATIC) WeLd_Ohm_T_f32;
	VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
	VAR(float32, AUTOMATIC) IdDes_Amp_T_f32;
	VAR(float32, AUTOMATIC) TermBDeri_Volt_T_f32;
	VAR(float32, AUTOMATIC) TermEDeriScale_Volt_T_f32;
	VAR(float32, AUTOMATIC) TermEDeriScalefinal_Volt_T_f32;
	VAR(float32, AUTOMATIC) TermBDerifinal_Volt_T_f32;
	VAR(uint8, AUTOMATIC) MtrQuad_Cnt_T_u8;
	VAR(float32, AUTOMATIC) MtrEnvSpd_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) CuTempEst_DegC_T_f32;	
	
	VAR(float32, AUTOMATIC) TermH_Volt_T_f32;
	VAR(float32, AUTOMATIC) VdTerm_Volt_T_f32;
	VAR(float32, AUTOMATIC) VqTerm_Volt_T_f32;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_VltgCtrl_Per2_CP0_CheckpointReached();
	
	/*** Reading Inputs ***/
	MRFMtrVel_MtrRadpS_T_f32 = Rte_IRead_VltgCtrl_Per2_MRFMtrVel_MtrRadpS_f32();
	EstKe_VpRadpS_T_f32 = Rte_IRead_VltgCtrl_Per2_EstKe_VpRadpS_f32();
	EstR_Ohm_T_f32 = Rte_IRead_VltgCtrl_Per2_EstR_Ohm_f32();
	EstLq_Henry_T_f32 = Rte_IRead_VltgCtrl_Per2_EstLq_Henry_f32();
	EstLd_Henry_T_f32 = Rte_IRead_VltgCtrl_Per2_EstLd_Henry_f32();
	MRFMtrTrqCmd_MtrNm_T_f32 = Rte_IRead_VltgCtrl_Per2_MRFMtrTrqCmdScl_MtrNm_f32();
	Vecu_Volt_T_f32 = Rte_IRead_VltgCtrl_Per2_Vecu_Volt_f32();
	MtrQuad_Cnt_T_u8 = Rte_IRead_VltgCtrl_Per2_MtrQuad_Cnt_u08();
	CuTempEst_DegC_T_f32 = Rte_IRead_VltgCtrl_Per2_CuTempEst_DegC_f32();
	MtrEnvSpd_MtrRadpS_T_f32 = Rte_IRead_VltgCtrl_Per2_MtrEnvSpd_MtrRadpS_f32();
	
	/***Limit Vecu Volt***/
	Vecu_Volt_T_f32 = Limit_m(Vecu_Volt_T_f32,D_MINVECU_VOLT_F32,D_MAXVECU_VOLT_F32);
	MtrEnvSpd_MtrRadpS_T_f32 = Limit_m(MtrEnvSpd_MtrRadpS_T_f32,D_MINMTRENVSPD_MTRRADPS_F32,D_MAXMTRENVSPD_MTRRADPS_F32);
	CuTempEst_DegC_T_f32 =Limit_m(CuTempEst_DegC_T_f32,D_MINCUTEMPEST_DEGC_F32,D_MAXCUTEMPEST_DEGC_F32);
	
	
	
	
	
	/* Calculation of voltage terms */ 
	/*** Term A calculation ***/	
	TermA_Volt_M_f32 = EstKe_VpRadpS_T_f32 * MRFMtrVel_MtrRadpS_T_f32;
	WeLq_Ohm_T_f32 = MRFMtrVel_MtrRadpS_T_f32 * (float32)D_MTRPOLESDIV2_CNT_U8 * EstLq_Henry_T_f32;
	WeLd_Ohm_T_f32 = MRFMtrVel_MtrRadpS_T_f32 * (float32)D_MTRPOLESDIV2_CNT_U8 * EstLd_Henry_T_f32;
	
	/*** Term Xq and Xd calculation ***/
	TermTauD_Uls_M_f32 = EstLd_Henry_T_f32 / EstR_Ohm_T_f32;
	TermXq_Uls_M_f32 = WeLq_Ohm_T_f32 / EstR_Ohm_T_f32;
	TermXd_Uls_M_f32 = WeLd_Ohm_T_f32 / EstR_Ohm_T_f32;

	/*** Term B Derivative and TermBtotal calculation ***/
	TermBDeri_Volt_T_f32= (EstLq_Henry_T_f32 * TermB_Volt_M_f32)/ EstR_Ohm_T_f32;
	TermBDeri_Volt_T_f32 = TermBDeri_Volt_T_f32  * k_DeriScaleB_Uls_f32;

	TermBDerifinal_Volt_T_f32= Filter_WindowCoff(TermBDeri_Volt_T_f32,t_VqfilterCoeff_Uls_f32,Vqcoef_Uls_M_f32);
	
	TermBDeri_Volt_D_f32 = TermBDeri_Volt_T_f32;
	TermBDerifinal_Volt_D_f32 = TermBDerifinal_Volt_T_f32;
	
	TermBTOT_Volt_M_f32 = TermB_Volt_M_f32 + TermBDerifinal_Volt_T_f32;
	
	/*** Term D calculation ***/
	if ((MtrQuad_Cnt_T_u8 == D_QUADRANT1_CNT_U8) || (MtrQuad_Cnt_T_u8 == D_QUADRANT3_CNT_U8))
			 { /* Quadrant 1 and 3 */
				
				IdDes_Amp_T_f32 =  D_ZERO_ULS_F32;
				
			 }
	else
			{
				IdDes_Amp_T_f32 = CalcIdDes(MRFMtrVel_MtrRadpS_T_f32, MRFMtrTrqCmd_MtrNm_T_f32,MtrEnvSpd_MtrRadpS_T_f32,
															CuTempEst_DegC_T_f32);
				
			}
	IdDes_Amp_D_f32 = IdDes_Amp_T_f32;
	TermD_Volt_M_f32 = WeLd_Ohm_T_f32 * IdDes_Amp_T_f32 * D_SQRT3OVR2_ULS_F32;

	/*** Term E and its derivative and  Etotal calculation ***/
	TermE_Volt_M_f32 = EstR_Ohm_T_f32 * IdDes_Amp_T_f32 * D_SQRT3OVR2_ULS_F32;
	TermEDeriScale_Volt_T_f32 = IdDes_Amp_T_f32 * D_SQRT3OVR2_ULS_F32 * k_DeriScaleId_Uls_f32 * EstLd_Henry_T_f32 ;
	TermEDeriScalefinal_Volt_T_f32 = Filter_WindowCoff(TermEDeriScale_Volt_T_f32,t_VdfilterCoeff_Uls_f32,Vdcoef_Uls_M_f32) ;
	TermETOT_Volt_M_f32 = TermE_Volt_M_f32 + TermEDeriScalefinal_Volt_T_f32;
	
	TermEDeriScale_Volt_D_f32 = TermEDeriScale_Volt_T_f32;
	TermEDeriScalefinal_Volt_D_f32	= TermEDeriScalefinal_Volt_T_f32;
	
	TermZ_Uls_T_f32 = D_ONE_ULS_F32 + (TermXq_Uls_M_f32 * TermXd_Uls_M_f32);
	TermZ_Uls_D_f32 = TermZ_Uls_T_f32;
	TermY_Uls_M_f32 = (TermA_Volt_M_f32 + (TermB_Volt_M_f32 * TermZ_Uls_T_f32)) / Vecu_Volt_T_f32;
	

	 /*** Term H Calculation ***/

    TermH_Volt_T_f32 = TermXd_Uls_M_f32 * PreTermG_Volt_M_f32;

	TermH_Volt_D_f32 = TermH_Volt_T_f32;

	/*** Dynamic Voltage equations for Motor control***/
	VqTerm_Volt_T_f32 = TermA_Volt_M_f32 + TermBTOT_Volt_M_f32 + TermH_Volt_T_f32;
	VdTerm_Volt_T_f32 = TermETOT_Volt_M_f32 - (TermB_Volt_M_f32 * TermXq_Uls_M_f32);


	VqTerm_Volt_M_f32 = VqTerm_Volt_T_f32;
	VdTerm_Volt_M_f32 = VdTerm_Volt_T_f32;
	TermA_Volt_M_f32 = Limit_m(TermA_Volt_M_f32, -D_TERMAMAX_VOLT_F32, D_TERMAMAX_VOLT_F32);
	TermD_Volt_M_f32 = Limit_m(TermD_Volt_M_f32, -D_TERMDMAX_VOLT_F32, D_TERMDMAX_VOLT_F32);
	TermE_Volt_M_f32 = Limit_m(TermE_Volt_M_f32, D_TERMEMIN_VOLT_F32, D_TERMEMAX_VOLT_F32);
	TermXq_Uls_M_f32 = Limit_m(TermXq_Uls_M_f32, -D_TERMXMAX_ULS_F32, D_TERMXMAX_ULS_F32);
	TermXd_Uls_M_f32 = Limit_m(TermXd_Uls_M_f32, -D_TERMXMAX_ULS_F32, D_TERMXMAX_ULS_F32);
	TermY_Uls_M_f32 = Limit_m(TermY_Uls_M_f32, -D_TERMYMAX_ULS_F32, D_TERMYMAX_ULS_F32);

	Rte_IWrite_VltgCtrl_Per2_TermA_Volt_f32(TermA_Volt_M_f32);
	Rte_IWrite_VltgCtrl_Per2_TermXq_Uls_f32(TermXq_Uls_M_f32);
	Rte_IWrite_VltgCtrl_Per2_TermXd_Uls_f32(TermXd_Uls_M_f32);
	Rte_IWrite_VltgCtrl_Per2_TermY_Uls_f32(TermY_Uls_M_f32);
	Rte_IWrite_VltgCtrl_Per2_TermZ_Uls_f32(TermZ_Uls_T_f32);
	Rte_IWrite_VltgCtrl_Per2_TermBTOT_Volt_f32(TermBTOT_Volt_M_f32);
	Rte_IWrite_VltgCtrl_Per2_VdTerm_Volt_f32(VdTerm_Volt_T_f32);
	Rte_IWrite_VltgCtrl_Per2_VqTerm_Volt_f32(VqTerm_Volt_T_f32);

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_VltgCtrl_Per2_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Per3
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
 *   Boolean Rte_IRead_VltgCtrl_Per3_CCLMSAActive_Cnt_lgc(void)
 *   Float Rte_IRead_VltgCtrl_Per3_MtrEnvSpd_MtrRadpS_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per3_Vecu_Volt_f32(void)
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VltgCtrl_Per3
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) MtrEnvSpd_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
	VAR(uint16, AUTOMATIC) VoltageLimit_Volt_T_u8p8;
	VAR(uint16, AUTOMATIC) MtrEnvSpd_MtrRadpS_T_u12p4;
	VAR(float32, AUTOMATIC) VoltageLimit_Volt_T_f32;

	VAR(float32, AUTOMATIC) LmtdModIdx_Uls_T_f32;
	VAR(Boolean, AUTOMATIC) CCLMSAActive_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) CurrentSysState_Cnt_T_enum;
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_VltgCtrl_Per3_CP0_CheckpointReached();
	CurrentSysState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	Vecu_Volt_T_f32 = Rte_IRead_VltgCtrl_Per3_Vecu_Volt_f32();
	MtrEnvSpd_MtrRadpS_T_f32 = Rte_IRead_VltgCtrl_Per3_MtrEnvSpd_MtrRadpS_f32();
	CCLMSAActive_Cnt_T_lgc = Rte_IRead_VltgCtrl_Per3_CCLMSAActive_Cnt_lgc();
	
	MtrEnvSpd_MtrRadpS_T_f32 = Limit_m(MtrEnvSpd_MtrRadpS_T_f32,D_MINMTRENVSPD_MTRRADPS_F32,D_MAXMTRENVSPD_MTRRADPS_F32);

	
	if (CCLMSAActive_Cnt_T_lgc == FALSE)
	{
		MtrEnvSpd_MtrRadpS_T_u12p4 = FPM_FloatToFixed_m(Abs_f32_m(MtrEnvSpd_MtrRadpS_T_f32), u12p4_T);
		
		VoltageLimit_Volt_T_u8p8 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_OvrSpdDmpTblX_MtrRadpS_u12p4,
																t_OvrSpdDmpTblY_Volt_u8p8,
																TableSize_m(t_OvrSpdDmpTblX_MtrRadpS_u12p4), 
																MtrEnvSpd_MtrRadpS_T_u12p4);
		
		VoltageLimit_Volt_T_f32 = FPM_FixedToFloat_m(VoltageLimit_Volt_T_u8p8, u8p8_T);
	
		LmtdModIdx_Uls_T_f32 = VoltageLimit_Volt_T_f32 / Vecu_Volt_T_f32;  
		LmtdModIdx_Uls_M_f32 = Limit_m(LmtdModIdx_Uls_T_f32, D_ZERO_ULS_F32, D_MODIDXMAX_ULS_F32);
	}	
	else
	{
		VoltageLimit_Volt_T_f32 = Vecu_Volt_T_f32;
		LmtdModIdx_Uls_M_f32 = D_ONE_ULS_F32;
	}	
	VoltageLimit_Volt_D_f32 = VoltageLimit_Volt_T_f32;
	
	/*** Counter time elapsed on operate***/
	
	if (CurrentSysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE) 
		{       /*** check if counter limit limit to prevent the overflow and saturating the counter***/
				if (PDOverrideCounter_Cnt_M_u16 < D_COUNTERLIMIT_CNT_U16)
				{	
					PDOverrideCounter_Cnt_M_u16 ++;
					PDTestTimeNOTElapsed_Cnt_M_lgc = TRUE;
				}
				else
				{
					/*** Reset the Elapsed time elapsed time ***/
					PDTestTimeNOTElapsed_Cnt_M_lgc = FALSE;
				}
			
		}	
	else
		{	/*** Open entry to state other than operate the reset of the counter ***/
			PDOverrideCounter_Cnt_M_u16 =D_ZERO_CNT_U16;
			PDTestTimeNOTElapsed_Cnt_M_lgc = FALSE;
		}
	
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_VltgCtrl_Per3_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VltgCtrl_Per4
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
 *   UInt8 Rte_IRead_VltgCtrl_Per4_MtrQuad_Cnt_u08(void)
 *   Boolean Rte_IRead_VltgCtrl_Per4_PDActivateTest_Cnt_lgc(void)
 *   SInt16 Rte_IRead_VltgCtrl_Per4_PDPhsAdvSel_Cnt_s16(void)
 *   Float Rte_IRead_VltgCtrl_Per4_PDTestModIdx_Uls_f32(void)
 *   Float Rte_IRead_VltgCtrl_Per4_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VltgCtrl_Per4_ModIdx_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VltgCtrl_Per4_ModIdx_Uls_f32(void)
 *   void Rte_IWrite_VltgCtrl_Per4_PhsAdv_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_VltgCtrl_Per4_PhsAdv_Cnt_s16(void)
 *   void Rte_IWrite_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16(void)
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

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per4(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VltgCtrl_Per4
 *********************************************************************************************************************/
	
	VAR(sint16, AUTOMATIC) UncorrPhsAdv_Cnt_T_s16;
	VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
	VAR(uint8, AUTOMATIC) MtrQuad_Cnt_T_u8;
	VAR(boolean, AUTOMATIC) PDActivateTest_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) PDTestModIdx_Uls_T_f32;
	VAR(float32, AUTOMATIC) ModIdx_Uls_T_f32;
	VAR(uint16, AUTOMATIC) AbsPhAdv_Cnt_T_u16;
	VAR(float32, AUTOMATIC) DenTerm_Uls_T_f32;
	VAR(float32, AUTOMATIC) VdTerm_Volt_T_f32;
	VAR(float32, AUTOMATIC) VqTerm_Volt_T_f32;
	VAR(float32, AUTOMATIC) VSumSqr_VoltSqrd_T_f32;
	VAR(float32, AUTOMATIC) VFinal_Volt_T_f32;
	VAR(float32, AUTOMATIC) TermG_Volt_T_f32;
	VAR(float32, AUTOMATIC) IntTermG_Volt_T_f32;
	VAR(sint16, AUTOMATIC) SignPhAdv_T_s16 ;
	VAR(float32, AUTOMATIC) SineLkpTbl_Uls_T_f32;
	VAR(float32, AUTOMATIC) AbsVecu_Volt_T_f32;
	VAR(sint16, AUTOMATIC) PhsAdv_Cnt_T_s16;
	VAR(sint16, AUTOMATIC) PDPhsAdvSel_Cnt_T_s16;
	VAR(sint16, AUTOMATIC) PhsOffCorr_Cnt_T_s16;
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_VltgCtrl_Per4_CP0_CheckpointReached();

	UncorrPhsAdv_Cnt_T_s16 = UncorrPhsAdv_Cnt_M_s16;
	PhsOffCorr_Cnt_T_s16 = PhsOffCorr_Cnt_M_s16 ;
	Vecu_Volt_T_f32 = Rte_IRead_VltgCtrl_Per4_Vecu_Volt_f32();
	MtrQuad_Cnt_T_u8 = Rte_IRead_VltgCtrl_Per4_MtrQuad_Cnt_u08();
	PDActivateTest_Cnt_T_lgc = Rte_IRead_VltgCtrl_Per4_PDActivateTest_Cnt_lgc();
	PDTestModIdx_Uls_T_f32 = Rte_IRead_VltgCtrl_Per4_PDTestModIdx_Uls_f32();
	PDPhsAdvSel_Cnt_T_s16 = Rte_IRead_VltgCtrl_Per4_PDPhsAdvSel_Cnt_s16();

	Vecu_Volt_T_f32 = Limit_m(Vecu_Volt_T_f32,D_MINVECU_VOLT_F32,D_MAXVECU_VOLT_F32);
	/*** Phase advance terms ***/
	AbsPhAdv_Cnt_T_u16 = Abs_s16_m(UncorrPhsAdv_Cnt_T_s16);
	
	
	/*** Cos (delta) Calculation ***/
	DenTerm_Uls_T_f32 = T_SINELKPTBL_ULS_F32[(TableSize_m(T_SINELKPTBL_ULS_F32)-1U) - AbsPhAdv_Cnt_T_u16];
	VltgDenom_Uls_D_f32 = DenTerm_Uls_T_f32;
	

	  VqTerm_Volt_T_f32=VqTerm_Volt_M_f32;
      VdTerm_Volt_T_f32=VdTerm_Volt_M_f32;
	
	if ((MtrQuad_Cnt_T_u8 == D_QUADRANT1_CNT_U8) || (MtrQuad_Cnt_T_u8 == D_QUADRANT3_CNT_U8))
			 { /* Quadrant 1 and 3 */
			 if (Abs_f32_m(DenTerm_Uls_T_f32) > FLT_EPSILON)
				 {
				  VFinal_Volt_T_f32 = VqTerm_Volt_T_f32/DenTerm_Uls_T_f32;
				 }
			 else
				 {
					VFinal_Volt_T_f32 = D_ZERO_ULS_F32; 
				 }
			 }
	else
		{
		 /* Quadrant 2 and 4 */
		VSumSqr_VoltSqrd_T_f32 = (VdTerm_Volt_T_f32 * VdTerm_Volt_T_f32) + (VqTerm_Volt_T_f32 * VqTerm_Volt_T_f32);
		VFinal_Volt_T_f32 = (float32)Sign_f32_m(VqTerm_Volt_T_f32)*(float32)sqrtf(VSumSqr_VoltSqrd_T_f32);

		}

	ModIdx_Uls_T_f32 = VFinal_Volt_T_f32 / Vecu_Volt_T_f32;
	/*** Limiting the modulation index ***/
	if (LmtdModIdx_Uls_M_f32 < Abs_f32_m(ModIdx_Uls_T_f32))
	{
		ModIdx_Uls_T_f32 = (float32)Sign_f32_m(ModIdx_Uls_T_f32) * LmtdModIdx_Uls_M_f32;
	}
	
	
	
	if ((MtrQuad_Cnt_T_u8 == D_QUADRANT2_CNT_U8) || (MtrQuad_Cnt_T_u8 == D_QUADRANT4_CNT_U8))
		{ /* Quadrant 2 and 4 */
			if (VqTerm_Volt_T_f32 >= D_ZERO_ULS_F32)
			{
				if (VdTerm_Volt_T_f32 >= D_ZERO_ULS_F32)
				{
						if ((UncorrPhsAdv_Cnt_T_s16 -(sint16)k_CorrAngle_Cnt_u16) >= D_ZERO_CNT_S16 )
						{
							UncorrPhsAdv_Cnt_T_s16 =UncorrPhsAdv_Cnt_T_s16-(sint16)(D_TWO_ULS_S16*D_MAXDELTAVAL_CNT_U16);
							 PhaseCorrec_Cnt_D_u16 = 1U;
						}
						else
						{
							PhaseCorrec_Cnt_D_u16 = 2U;
							/*** Do nothing ***/
						}
				}	
				else
				{
						if ((UncorrPhsAdv_Cnt_T_s16 + (sint16)k_CorrAngle_Cnt_u16) >= D_ZERO_CNT_S16)
						{
						    /*** Do nothing ***/
							PhaseCorrec_Cnt_D_u16 = 3U;
						}
						else
						{
							PhaseCorrec_Cnt_D_u16 = 4U;
						UncorrPhsAdv_Cnt_T_s16 =UncorrPhsAdv_Cnt_T_s16+(sint16)(D_TWO_ULS_S16*D_MAXDELTAVAL_CNT_U16) ;

						}
				}
			}
			else
			{
				if (VdTerm_Volt_T_f32 >= D_ZERO_ULS_F32)
				{
						if ((UncorrPhsAdv_Cnt_T_s16 + (sint16)k_CorrAngle_Cnt_u16) >= D_ZERO_CNT_S16)
						{
							PhaseCorrec_Cnt_D_u16 = 5U;
							/*** Do nothing ***/
						}
						else
						{
						UncorrPhsAdv_Cnt_T_s16 =UncorrPhsAdv_Cnt_T_s16+ (sint16)(D_TWO_ULS_S16*D_MAXDELTAVAL_CNT_U16);
						PhaseCorrec_Cnt_D_u16 = 6U;
						}
				}	
				else 
				{
						if ((UncorrPhsAdv_Cnt_T_s16 -(sint16)k_CorrAngle_Cnt_u16) >=D_ZERO_CNT_S16)
						{
							UncorrPhsAdv_Cnt_T_s16 =UncorrPhsAdv_Cnt_T_s16-(sint16)(D_TWO_ULS_S16*D_MAXDELTAVAL_CNT_U16) ;
							PhaseCorrec_Cnt_D_u16 = 7U;
						}
						else
						{
							PhaseCorrec_Cnt_D_u16 = 8U;
						 /*** Do nothing ***/
						}
				}
			}
				
		}	



	if (UncorrPhsAdv_Cnt_T_s16 > D_UNCORRPHSADVMAX_CNT_S16)
	{
		UncorrPhsAdv_Cnt_T_s16 = D_UNCORRPHSADVMAX_CNT_S16;
	}
	else if(UncorrPhsAdv_Cnt_T_s16 <= -D_UNCORRPHSADVMAX_CNT_S16)
	{
		UncorrPhsAdv_Cnt_T_s16 = -D_UNCORRPHSADVMAX_CNT_S16;
	}
	else
	{
		/***Do nothing ***/
	}
	
	DisplayAfterUncorrPhsAdv_Cnt_D_s16 = UncorrPhsAdv_Cnt_T_s16;

	PhsAdv_Cnt_T_s16 = (UncorrPhsAdv_Cnt_T_s16 * (sint16)D_CORRPHSADVSCALEADJ_CNT_U8) + PhsOffCorr_Cnt_T_s16;
	PhsAdv_Cnt_T_s16 = Limit_m(PhsAdv_Cnt_T_s16, -D_CORRPHSADVMAX_CNT_S16, D_CORRPHSADVMAX_CNT_S16);
	
	
	
	if ((TRUE == PDActivateTest_Cnt_T_lgc) && (TRUE == PDTestTimeNOTElapsed_Cnt_M_lgc))
	{
		ModIdx_Uls_T_f32 = PDTestModIdx_Uls_T_f32;
		PhsAdv_Cnt_T_s16 = PDPhsAdvSel_Cnt_T_s16;
		
	}
	ModIdx_Uls_T_f32 = Limit_m(ModIdx_Uls_T_f32, -D_MODIDXMAX_ULS_F32, D_MODIDXMAX_ULS_F32);
	
	
	
	 AbsVecu_Volt_T_f32 = Abs_f32_m(Vecu_Volt_T_f32);
	/*** Limiting VFinal to vecu volt***/
	 VFinal_Volt_T_f32 = Limit_m(VFinal_Volt_T_f32, - AbsVecu_Volt_T_f32, AbsVecu_Volt_T_f32);
	 VdTerm_Volt_D_f32=VdTerm_Volt_T_f32;
	 VqTerm_Volt_D_f32=VqTerm_Volt_T_f32;
	 VFinal_Volt_D_f32=VFinal_Volt_T_f32;
	 
    /*** Term G Calculation ***/
	SignPhAdv_T_s16 = Sign_s16_m(UncorrPhsAdv_Cnt_T_s16);
    SineLkpTbl_Uls_T_f32 = T_SINELKPTBL_ULS_F32[Abs_s16_m(UncorrPhsAdv_Cnt_T_s16)];
	SineLkpTbl_Uls_D_f32 =SineLkpTbl_Uls_T_f32;
	IntTermG_Volt_T_f32= TermXq_Uls_M_f32 * TermB_Volt_M_f32;
	IntTermG_Volt_D_f32 = IntTermG_Volt_T_f32;
	TermG_Volt_T_f32 = IntTermG_Volt_T_f32 - ( VFinal_Volt_T_f32 * SineLkpTbl_Uls_T_f32 * (float32)SignPhAdv_T_s16) ;
	TermGInput_Volt_D_f32 = TermG_Volt_T_f32;
	/*** Switch to bypass the low pass filter ***/
	if (k_TauDLPFByPass_Uls_lgc == FALSE)
	{
		TermG_Volt_T_f32 = LowPassFilter(TermG_Volt_T_f32);
	}
	
	TermGOutput_Volt_D_f32 = TermG_Volt_T_f32;

	

	PreTermG_Volt_M_f32 = TermG_Volt_T_f32;
	Rte_IWrite_VltgCtrl_Per4_ModIdx_Uls_f32(ModIdx_Uls_T_f32);
	Rte_IWrite_VltgCtrl_Per4_PhsAdv_Cnt_s16(PhsAdv_Cnt_T_s16);
	Rte_IWrite_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16(UncorrPhsAdv_Cnt_T_s16);
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_VltgCtrl_Per4_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_VLTGCTRL_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC INLINE FUNC(float32, AP_VLTGCTRL_CODE) CalcIdDes(	VAR(float32, AUTOMATIC) MRFMtrVel_MtrRadpS_T_f32, 
															VAR(float32, AUTOMATIC) MRFMtrTrqCmd_MtrNm_T_f32,
															VAR(float32, AUTOMATIC) MtrEnvSpd_MtrRadpS_T_f32,
															VAR(float32, AUTOMATIC) CuTempEst_DegC_T_f32)
{
	VAR(sint16, AUTOMATIC) IdDes_Amp_T_s8p7;
	VAR(float32, AUTOMATIC) IdDes_Amp_T_f32;
	VAR(float32, AUTOMATIC) IdDesRaw_Amp_T_f32;	
	VAR(uint16, AUTOMATIC) MRFMtrVel_MtrRadpS_T_u12p4;
	VAR(uint16, AUTOMATIC) MRFMtrTrqCmd_MtrNm_T_u5p11;
	VAR(float32, AUTOMATIC) AbsMRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) IdDesTmpScaleGain_Uls_f32;
	VAR(float32, AUTOMATIC) IdOffSpdGain_Uls_f32;
	VAR(sint16, AUTOMATIC) 	CuTempEst_DegC_T_s10p5;
	VAR(uint16, AUTOMATIC) 	IdDesTmpScaleGain_Uls_u2p14;
	
	AbsMRFMtrVel_MtrRadpS_T_f32	=Abs_f32_m(MRFMtrVel_MtrRadpS_T_f32);
	MRFMtrVel_MtrRadpS_T_u12p4 = FPM_FloatToFixed_m(AbsMRFMtrVel_MtrRadpS_T_f32, u12p4_T);
	MRFMtrTrqCmd_MtrNm_T_u5p11 = FPM_FloatToFixed_m((Abs_f32_m(MRFMtrTrqCmd_MtrNm_T_f32)), u5p11_T);

	IdDes_Amp_T_s8p7 = BilinearXYM_s16_u16Xs16YM_Cnt(	MRFMtrTrqCmd_MtrNm_T_u5p11, 
														MRFMtrVel_MtrRadpS_T_u12p4, 
														t_IdDesTcmdLvlBS_MtrNm_u5p11, 
														TableSize_m(t_IdDesTcmdLvlBS_MtrNm_u5p11), 
														IdDesTblX_MtrRadpS_M_u12p4, 
														(P2CONST(sint16, AUTOMATIC, AUTOMATIC))t2_IdDesTblYM_Amp_s8p7, 
														TableSize_m(IdDesTblX_MtrRadpS_M_u12p4));

	IdDesRaw_Amp_T_f32 = FPM_FixedToFloat_m(IdDes_Amp_T_s8p7, s8p7_T);
	IdDesRaw_Amp_D_f32 = IdDesRaw_Amp_T_f32;
	CuTempEst_DegC_T_s10p5   = FPM_FloatToFixed_m(CuTempEst_DegC_T_f32,s10p5_T);
	IdDesTmpScaleGain_Uls_u2p14 = IntplVarXY_u16_s16Xu16Y_Cnt( t_IdDesTempGainTblX_DegC_s10p5,
																t_IdDesTempGainTblY_Uls_u2p14,
																TableSize_m(t_IdDesTempGainTblX_DegC_s10p5),
																CuTempEst_DegC_T_s10p5);
	
	IdDesTmpScaleGain_Uls_f32 = FPM_FixedToFloat_m(IdDesTmpScaleGain_Uls_u2p14,u2p14_T);
	IdOffSpdGain_Uls_f32 = ((AbsMRFMtrVel_MtrRadpS_T_f32 - MtrEnvSpd_MtrRadpS_T_f32)*k_IdOffSpdGain_Sec_f32) + D_ONE_ULS_F32;
    IdDes_Amp_T_f32 = IdDesRaw_Amp_T_f32 * IdDesTmpScaleGain_Uls_f32 * IdOffSpdGain_Uls_f32;

	return(IdDes_Amp_T_f32);
}

/*** Dynamic Low Pass Filter Time Constant Table Calculation ***/
STATIC INLINE FUNC(float32, AP_VLTGCTRL_CODE) LowPassFilter( VAR(float32, AUTOMATIC) TermG_Volt_T_f32 )
{
	VAR(float32, AUTOMATIC) TermGTOT_Volt_T_f32;
	VAR(float32, AUTOMATIC) KTimeConstanst_Uls_T_f32;
	VAR(uint16, AUTOMATIC) TermTauD_Uls_T_u5p11;
	VAR(uint16, AUTOMATIC) KTimeConstanst_Uls_T_u8p8;

	/*** Low pass Dynamic filter implementation ***/
	TermTauD_Uls_T_u5p11 =(uint16) FPM_FloatToFixed_m( TermTauD_Uls_M_f32 ,u5p11_T);
	
	/***Use of interpolation to calculate the time constant ***/
	KTimeConstanst_Uls_T_u8p8 = IntplVarXY_u16_u16Xu16Y_Cnt( t_TimeConstantTblX_Sec_u5p11,
																t_TimeConstantTblY_Uls_u8p8,
																TableSize_m(t_TimeConstantTblX_Sec_u5p11),
																TermTauD_Uls_T_u5p11)	;
	
	KTimeConstanst_Uls_T_f32= FPM_FixedToFloat_m(KTimeConstanst_Uls_T_u8p8,u8p8_T);
	KTimeConstanst_Uls_D_f32 = KTimeConstanst_Uls_T_f32;
	/*** Closed loop calculation of TermG low pass filter ***/
	TermGTOT_Volt_T_f32 = ((TermG_Volt_T_f32 - PreTermG_Volt_M_f32) * KTimeConstanst_Uls_T_f32 ) + PreTermG_Volt_M_f32;
	return TermGTOT_Volt_T_f32;
  

}


/*** Fourier Series with Hamming Window Filter Design ***/

STATIC INLINE FUNC(float32, AP_VLTGCTRL_CODE) Filter_WindowCoff (VAR(float32, AUTOMATIC) InputDeri_Uls_T_f32, P2CONST(float32, AUTOMATIC, AUTOMATIC)TableCalCoff, P2VAR(float32, AUTOMATIC, AUTOMATIC)StateVar_Uls_T_f32 )
{

 VAR(float32, AUTOMATIC) FilterOutputScaled_Hertz_T_f32;

 /*** Assigning the state variables from the previous and current states ***/
 StateVar_Uls_T_f32[6] =StateVar_Uls_T_f32[5];
 StateVar_Uls_T_f32[5] =StateVar_Uls_T_f32[4];
 StateVar_Uls_T_f32[4] =StateVar_Uls_T_f32[3];
 StateVar_Uls_T_f32[3] =StateVar_Uls_T_f32[2];
 StateVar_Uls_T_f32[2] =StateVar_Uls_T_f32[1];
 StateVar_Uls_T_f32[1] =StateVar_Uls_T_f32[0];
 StateVar_Uls_T_f32[0] =  InputDeri_Uls_T_f32;
 
  /***  Derivative filter 
	Derivative formula : Filter Output = Coef_0 * Z-6 + coef_1 * Z-5 + coef_2 * Z-4 + coef_4 * Z-2 
												+ coef_5 * Z-1 + coef_6 * Z0 ***/
  FilterOutputScaled_Hertz_T_f32 = (StateVar_Uls_T_f32[0]-StateVar_Uls_T_f32[6]) * TableCalCoff[0] ;
  FilterOutputScaled_Hertz_T_f32 = FilterOutputScaled_Hertz_T_f32+((StateVar_Uls_T_f32[1]-StateVar_Uls_T_f32[5]) * TableCalCoff[1]) ;
  FilterOutputScaled_Hertz_T_f32 = FilterOutputScaled_Hertz_T_f32+((StateVar_Uls_T_f32[2]-StateVar_Uls_T_f32[4]) * TableCalCoff[2]) ;
 

return (FilterOutputScaled_Hertz_T_f32);

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
