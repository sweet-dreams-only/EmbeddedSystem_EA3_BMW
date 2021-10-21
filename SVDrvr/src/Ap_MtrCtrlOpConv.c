/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_MtrCtrlOpConv.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/SVDrvr-nzt9hv/SVDrvr/autosar
 *     SW-C Type:  Ap_MtrCtrlOpConv
 *  Generated at:  Tue Oct 30 15:00:46 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_MtrCtrlOpConv>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 18 18:34:17 2011
 * %version:          4.3 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Thu Feb  7 15:40:51 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 12/13/11   4.1.1   JJW       Phase Adv x8 resolution increase
 * 01/06/12   4.1.2   LWW       Added defeat mask defined locally until component implementation is done
 * 10/25/12	   4.2	  Selva	    QAC fixed. Firewalling phase angle to +/- 90 degreed added (Refer FDD 15c) 		
 * 02/07/13	   4.3	  KJS	    Corrected serial comm service port prototype to use the same as the srl com 
 								service defeat. Also changed motor trq command inital value from 8.8 to 0
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_MtrCtrlOpConv.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_MtrCtrlOpConv_Cfg.h"
#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "Interpolation.h"

#define D_PHSADVCNTSPERREV_CNT_U16		6144U
#define D_PHSADVCNTS180DEG_CNT_U16		(D_PHSADVCNTSPERREV_CNT_U16 / 2U)
#define D_PHSPOSADVCNTS90DEG_CNT_U16	1536U /*	(D_PHSADVCNTSPERREV_CNT_S16 / 4U)*/
#define D_PHSNEGADVCNTS90DEG_CNT_S16	(-1536) /*(-D_PHSADVCNTSPERREV_CNT_S16 / 4U)*/
#define D_SVCDFTMODIDX_CNT_B32			512u
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
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
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
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_ZERO_CNT_S16 = 0
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ZERO_CNT_U32 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_MTRCTRLOPCONV_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCtrlOpConv_Per1
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
 *   UInt32 Rte_IRead_MtrCtrlOpConv_Per1_CurrentGainSvc_Cnt_b32(void)
 *   Float Rte_IRead_MtrCtrlOpConv_Per1_ModulationIndex_Uls_f32(void)
 *   SInt16 Rte_IRead_MtrCtrlOpConv_Per1_PhaseAdvance_Cnt_s16(void)
 *   Float Rte_IRead_MtrCtrlOpConv_Per1_TorqueCmdMRF_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16(void)
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32(void)
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32(void)
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16(void)
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_MTRCTRLOPCONV_APPL_CODE) MtrCtrlOpConv_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrCtrlOpConv_Per1
 *********************************************************************************************************************/
	
	VAR(float32, AUTOMATIC) ModIdx_Uls_T_f32;
	VAR(float32, AUTOMATIC) MtrTrqCmd_MtrNm_T_f32;
	VAR(sint16, AUTOMATIC) PhaseAdvance_Cnt_T_s16;
	VAR(uint16, AUTOMATIC) PhaseAdv_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) DeadTimeComp_Uls_T_u8p8;
	VAR(uint16, AUTOMATIC) AbsModIdx_Uls_T_u3p13;
	VAR(uint16, AUTOMATIC) CommOffset_Cnt_T_u16;
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_MtrCtrlOpConv_Per1_CP0_CheckpointReached();
	ModIdx_Uls_T_f32 = Rte_IRead_MtrCtrlOpConv_Per1_ModulationIndex_Uls_f32();
	MtrTrqCmd_MtrNm_T_f32 = Rte_IRead_MtrCtrlOpConv_Per1_TorqueCmdMRF_MtrNm_f32();
	PhaseAdvance_Cnt_T_s16 = Rte_IRead_MtrCtrlOpConv_Per1_PhaseAdvance_Cnt_s16();
	
	SrlComSvcDft_Cnt_T_b32 = Rte_IRead_MtrCtrlOpConv_Per1_CurrentGainSvc_Cnt_b32();
	PhaseAdvance_Cnt_T_s16=Limit_m(PhaseAdvance_Cnt_T_s16,	
											D_PHSNEGADVCNTS90DEG_CNT_S16,(sint16)D_PHSPOSADVCNTS90DEG_CNT_U16);
	if (ModIdx_Uls_T_f32 < 0.0F)
	{
		PhaseAdv_Cnt_T_u16 = (uint16)(PhaseAdvance_Cnt_T_s16 + (sint16)D_PHSADVCNTS180DEG_CNT_U16);
	}
	else if (PhaseAdvance_Cnt_T_s16 < 0)
	{
		PhaseAdv_Cnt_T_u16 = (uint16)(PhaseAdvance_Cnt_T_s16 + (sint16)D_PHSADVCNTSPERREV_CNT_U16);
	}
	else
	{
		PhaseAdv_Cnt_T_u16 = (uint16)PhaseAdvance_Cnt_T_s16;
	}
	
	ModIdx_Uls_T_f32 = Abs_f32_m(ModIdx_Uls_T_f32);
	AbsModIdx_Uls_T_u3p13 = FPM_FloatToFixed_m(ModIdx_Uls_T_f32, u3p13_T);
	
	if (Abs_f32_m(MtrTrqCmd_MtrNm_T_f32) < k_MinDiodeCondCurr_MtrNm_f32)
	{
		DeadTimeComp_Uls_T_u8p8 = 0U;
	}
	else
	{
		DeadTimeComp_Uls_T_u8p8 = IntplVarXY_u16_u16Xu16Y_Cnt(
									 t_DTCompTblX_Uls_u3p13,
									 t_DTCompTblY_Uls_u8p8,
									 TableSize_m(t_DTCompTblX_Uls_u3p13), 
									 AbsModIdx_Uls_T_u3p13);
	}
	
	CommOffset_Cnt_T_u16 = IntplVarXY_u16_u16Xu16Y_Cnt(
									 t_CommOffsetTblX_Uls_u3p13,
									 t_CommOffsetTblY_Cnt_u16,
									 TableSize_m(t_CommOffsetTblX_Uls_u3p13), 
									 AbsModIdx_Uls_T_u3p13);

	if ((SrlComSvcDft_Cnt_T_b32 & D_SVCDFTMODIDX_CNT_B32) == D_SVCDFTMODIDX_CNT_B32) 
		
	{
		CommOffset_Cnt_T_u16 = 0U;
		ModIdx_Uls_T_f32 = 0.0F;
		DeadTimeComp_Uls_T_u8p8 = 0U;
	}
	
	Rte_IWrite_MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16(CommOffset_Cnt_T_u16);
	Rte_IWrite_MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32(ModIdx_Uls_T_f32);
	Rte_IWrite_MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16(PhaseAdv_Cnt_T_u16);
	Rte_IWrite_MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32((FPM_FixedToFloat_m(DeadTimeComp_Uls_T_u8p8, u8p8_T)));
	Rte_IWrite_MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16(Sign_f32_m(MtrTrqCmd_MtrNm_T_f32));
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_MtrCtrlOpConv_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_MTRCTRLOPCONV_APPL_CODE
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
