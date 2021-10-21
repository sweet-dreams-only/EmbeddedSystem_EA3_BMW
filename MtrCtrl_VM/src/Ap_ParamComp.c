/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_ParamComp.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_ParamComp
 *  Generated at:  Fri Apr 12 01:15:49 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_ParamComp>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri Jun  3 08:20:17 2011
 * %version:          25 %
 * %derived_by:       nz63rn %
 * %date_modified:    Thu Sep  5 16:26:18 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/03/11   9       LWW       Fixed Per2 to use IRVs for Ke, R SV, added version log.
 *                              Added DISABLE mode disabling on periodics to match EA1.5 implementation 
 * 06/17/11   10      JJW       FWK Updates
 * 06/17/11   11      LWW       TypeH NVM storage anomaly fix
 * 12/03/11   12      LWW/OKT   Moved to Component Based Design / Added casts in ParameterCalc calls
 * 13/12/11   13      NRAR      Abs_f32_m added in line 318,323
 * 16/12/11   14      NRAR      fix in SCom_EOLNomMtrParam_Set() for NomL_Henry_f32
 * 04/21/12   15      BG        Added Scom functions to allow updating Ke & R SV's by CMS
 * 06/04/12   16      OT		Updated to SF-99A v003 (added R Current Offset factor)                         	5399
 * 09/21/12   17      Selva     Checkpoints added and mempmap macros corrected		                          	6238
 * 10/26/12	  18      Selva		Code Changes for Integration in MtrCtrl_VM (Refer FDD 06B Ver 4)
 * 02/02/13	  19      Selva		Updated for MtrCtrl_VM FDD99 version 7
 * 4/12/13	  20      Selva		Updated for MtrCtrl_VM version 9
 * 4/19/13	  21      KJS		Corrected anomaly 4848 for Iq saturation lookup.								7950
 * 5/13/13	  22      Selva     Updated the Max CuTempEst from 150	to 200 
 * 6/23/13	  23      Selva     Updated for Anamoly 4999                                                        8675
 * 8/14/13	  24	  SP		Updated for Anomaly 4641														9425
 * 9/5/13     25	  KMC       Update max CuTempEst from 200 to 300 and max SiTempEst from 150 to 200.        10049
 *                              Also QAC updates.
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks

 *********************************************************************************************************************/

#include "Rte_Ap_ParamComp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	#include "Ap_ParamComp_Cfg.h"
	#include "fixmath.h"
	#include "Interpolation.h"
	#include "GlobalMacro.h"
	#include "CalConstants.h"


	#define D_SQRT3OVR2_ULS_F32					0.866025403784F
	#define D_KETBLOFFSET_MTRRADPS_U12P4		FPM_InitFixedPoint_m(41.8125, u12p4_T)
	#define D_KELKUPFIXXSTP_MTRRADPS_U12P4		FPM_InitFixedPoint_m(5.25,u12p4_T)
	#define D_RLKUPFIXXSTP_MTRRADPS_U12P4		FPM_InitFixedPoint_m(5.25,u12p4_T)
	#define D_EXPIQMAX_AMP_F32					250.0F
	#define D_MINGAINRES_ULS_F32				0.000000009F
    #define D_MINKERNGLMT_VPRADPS_F32  			0.025F
	#define D_MAXKERNGLMT_VPRADPS_F32  			0.075F
	#define D_MINLRNGLMT_HENRY_F32     			0.00003F
	#define D_MAXLRNGLMT_HENRY_F32     			0.00041F
	#define D_MINRRNGLMT_OHM_F32       			0.005F
	#define D_MAXRRNGLMT_OHM_F32       			0.12565F
	#define D_MINCUTEMPEST_DEGC_F32             (-50.0F)
	#define D_MAXCUTEMPEST_DEGC_F32				300.0F
	#define D_MINSITEMPEST_DEGC_F32				(-50.0F)
	#define D_MAXSITEMPEST_DEGC_F32             200.0F
	#define D_MINMAGTEMPEST_DEGC_F32            (-50.0F)
	#define D_MAXMAGTEMPEST_DEGC_F32            150.0F
	#define	D_MINMTRCURRQAX_AMP_F32              0.0F
	#define	D_MAXMTRCURRQAX_AMP_F32              225.0F
		
	
	#define PARAMCOMP_START_SEC_VAR_CLEARED_32
    #include "MemMap.h" /* PRQA S 5087 */
	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) KeIntgSV_Amp_M_f32;
	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) RIntgSV_Amp_M_f32;
	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) PrevMtrTrqCmd_MtrNm_M_f32;
	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) PrevEstKe_VpRadpS_M_f32;
	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) PrvExpIq_Amp_M_f32[3];
	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) EstKeFF_VpRadpS_M_f32;
	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) EstRFF_Ohm_M_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) TrqCmdRate_MtrNmpLp_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) KeIntError_Amp_D_f32;	
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) RIntError_Amp_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) KeSatSclFac_Uls_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) LqSatSclFac_Uls_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) LdSatSclFac_Uls_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) EstRfetFF_Ohm_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) EstRmtrFF_Ohm_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) PreLmtEstKe_VpRadpS_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) PreLmtEstR_Ohm_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) PreLmtEstLq_Henry_D_f32;
	STATIC volatile VAR(float32, AP_PARAMCOMP_VAR_NOINIT) PreLmtEstLd_Henry_D_f32;
	
	#define PARAMCOMP_STOP_SEC_VAR_CLEARED_32
    #include "MemMap.h" /* PRQA S 5087 */

	
	#define PARAMCOMP_START_SEC_VAR_CLEARED_BOOLEAN
	#include "MemMap.h" /* PRQA S 5087 */
	STATIC volatile VAR(boolean, AP_PARAMCOMP_VAR_NOINIT) KeIntValid_Cnt_D_lgc;
	STATIC volatile VAR(boolean, AP_PARAMCOMP_VAR_NOINIT) RIntValid_Cnt_D_lgc;
	#define PARAMCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#include "MemMap.h" /* PRQA S 5087 */

	
	
	#define PARAMCOMP_START_SEC_VAR_SAVED_ZONEH_32
	#include "MemMap.h" /* PRQA S 5087 */

	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) KeFBckTyH_VpRadpS_M_f32;
	STATIC VAR(float32, AP_PARAMCOMP_VAR_NOINIT) RFBckTyH_Ohm_M_f32;
	
	#define PARAMCOMP_STOP_SEC_VAR_SAVED_ZONEH_32
	#include "MemMap.h" /* PRQA S 5087 */


	STATIC FUNC(float32, AP_PARAMCOMP_CODE) ParameterCalc(	VAR(float32, AUTOMATIC) TrqCmdRate_MtrNmpLp_T_f32,
															VAR(boolean, AUTOMATIC) ValidCurrSample_Cnt_T_lgc,
															VAR(uint8, AUTOMATIC) MtrQuad_Cnt_T_u8,
															VAR(uint16, AUTOMATIC) EstMtrCurrQax_Amp_T_u12p4,
															VAR(uint16, AUTOMATIC) IntgUpBnd_Amp_T_u12p4, 
															VAR(uint16, AUTOMATIC) IntgLoBnd_Amp_T_u12p4, 
															VAR(float32, AUTOMATIC) IqError_Amp_T_f32,
															VAR(float32, AUTOMATIC) MaxErr_Amp_T_f32, 
															VAR(float32, AUTOMATIC) Offset_Amp_T_f32, 
															CONSTP2VAR(float32, AUTOMATIC, AP_PARAMCOMP_CONST) StateVarPtr_Amp_T_f32, 
															VAR(float32, AUTOMATIC) AntiWindupLmt_Amp_T_f32, 
															VAR(float32, AUTOMATIC) AccelGain_Uls_T_f32, 
															VAR(float32, AUTOMATIC) NormGain_Uls_T_f32,
															VAR(boolean, AUTOMATIC) AccelGainEnable_Cnt_T_lgc,
															CONSTP2VAR(boolean, AUTOMATIC, AP_PARAMCOMP_CONST) IntValidPtr_Cnt_T_lgc,
															CONSTP2VAR(float32, AUTOMATIC, AP_PARAMCOMP_CONST) IntErrorPtr_Amp_T_f32);

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
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * EOLNomMtrParamType: Record with elements
 *   NomKe_VpRadpS_f32 of type Float
 *   NomLq_Henry_f32 of type Float
 *   NomRmtr_Ohm_f32 of type Float
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


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   EOLNomMtrParamType *Rte_Pim_EOLNomMtrParam(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PARAMCOMP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ParamComp_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ParamComp_Init1_EstKe_VpRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Init1_EstKe_VpRadpS_f32(void)
 *   void Rte_IWrite_ParamComp_Init1_EstLd_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Init1_EstLd_Henry_f32(void)
 *   void Rte_IWrite_ParamComp_Init1_EstLq_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Init1_EstLq_Henry_f32(void)
 *   void Rte_IWrite_ParamComp_Init1_EstR_Ohm_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Init1_EstR_Ohm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ParamComp_Init1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) NomKe_VpRadpS_T_f32;
	VAR(float32, AUTOMATIC) NomRmtr_Ohm_T_f32;
	VAR(float32, AUTOMATIC) NomLq_Henry_T_f32;
	VAR(float32, AUTOMATIC) NomLd_Henry_T_f32;
	VAR(float32, AUTOMATIC) EstR_Ohm_T_f32;
	
	NomKe_VpRadpS_T_f32 = Rte_Pim_EOLNomMtrParam()->NomKe_VpRadpS_f32;
	NomRmtr_Ohm_T_f32 = Rte_Pim_EOLNomMtrParam()->NomRmtr_Ohm_f32;
	NomLq_Henry_T_f32 = Rte_Pim_EOLNomMtrParam()->NomLq_Henry_f32;
	EstR_Ohm_T_f32 = NomRmtr_Ohm_T_f32 + k_NomRfet_Ohm_f32;
	NomLd_Henry_T_f32            =k_NomLd_Henry_f32;
	
	NomKe_VpRadpS_T_f32 = Limit_m(NomKe_VpRadpS_T_f32, D_MINKERNGLMT_VPRADPS_F32, D_MAXKERNGLMT_VPRADPS_F32);
	EstR_Ohm_T_f32 = Limit_m(EstR_Ohm_T_f32, D_MINRRNGLMT_OHM_F32, D_MAXRRNGLMT_OHM_F32);
	NomLq_Henry_T_f32 = Limit_m(NomLq_Henry_T_f32, D_MINLRNGLMT_HENRY_F32, D_MAXLRNGLMT_HENRY_F32);
	NomLd_Henry_T_f32 = Limit_m(NomLd_Henry_T_f32, D_MINLRNGLMT_HENRY_F32, D_MAXLRNGLMT_HENRY_F32);
	
	PrevEstKe_VpRadpS_M_f32 = NomKe_VpRadpS_T_f32;
	
	KeIntgSV_Amp_M_f32 = KeFBckTyH_VpRadpS_M_f32 / k_KeItgGn_VpRadpSpAmp_f32;
	RIntgSV_Amp_M_f32 = RFBckTyH_Ohm_M_f32 / k_RIntgGain_OhmpAmp_f32;
	Rte_IWrite_ParamComp_Init1_EstKe_VpRadpS_f32(NomKe_VpRadpS_T_f32);
	Rte_IWrite_ParamComp_Init1_EstLd_Henry_f32(NomLd_Henry_T_f32);
	Rte_IWrite_ParamComp_Init1_EstR_Ohm_f32(EstR_Ohm_T_f32);
	Rte_IWrite_ParamComp_Init1_EstLq_Henry_f32(NomLq_Henry_T_f32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ParamComp_Per1
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
 *   Float Rte_IRead_ParamComp_Per1_IdEst_Amp_f32(void)
 *   Float Rte_IRead_ParamComp_Per1_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *   Float Rte_IRead_ParamComp_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_ParamComp_Per1_MtrCurrQax_Amp_f32(void)
 *   Boolean Rte_IRead_ParamComp_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   UInt8 Rte_IRead_ParamComp_Per1_MtrQuad_Cnt_u08(void)
 *   Boolean Rte_IRead_ParamComp_Per1_ValidCurrSample_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ParamComp_Per1_EstKe_VpRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_EstKe_VpRadpS_f32(void)
 *   void Rte_IWrite_ParamComp_Per1_EstLd_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_EstLd_Henry_f32(void)
 *   void Rte_IWrite_ParamComp_Per1_EstLq_Henry_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_EstLq_Henry_f32(void)
 *   void Rte_IWrite_ParamComp_Per1_EstR_Ohm_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_EstR_Ohm_f32(void)
 *   void Rte_IWrite_ParamComp_Per1_ExpIq_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_ParamComp_Per1_ExpIq_Amp_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ParamComp_Per1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) MtrTrqCmd_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC) ValidCurrSample_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) MtrQuad_Cnt_T_u8;
	VAR(float32, AUTOMATIC) MtrCurrDax_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrQax_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) AbsMtrVel_MtrRadpS_T_f32;
	VAR(uint16, AUTOMATIC) AbsMtrVel_MtrRadpS_T_u12p4;
	VAR(boolean, AUTOMATIC) AccelGainEnable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) TrqCmdRate_MtrNmpLp_T_f32;
	VAR(float32, AUTOMATIC) IqError_Amp_T_f32;
	VAR(float32, AUTOMATIC) ExpIq_Amp_T_f32;
	VAR(uint16, AUTOMATIC) ExpIq_Amp_T_u12p4;
	VAR(uint16, AUTOMATIC) TableIndex_Cnt_T_u16;
	VAR(sint16, AUTOMATIC) CurrOffset_Amp_T_s11p4;
	VAR(uint16, AUTOMATIC) KeSatSclFac_Uls_T_u2p14;
	VAR(float32, AUTOMATIC) KeSatSclFac_Uls_T_f32;

	VAR(float32, AUTOMATIC) EstKe_VpRadpS_T_f32;
	VAR(float32, AUTOMATIC) EstR_Ohm_T_f32;

	VAR(uint16, AUTOMATIC) i;
	VAR(float32, AUTOMATIC) LqSatSclFac_Uls_T_f32;
	VAR(float32, AUTOMATIC) LdSatSclFac_Uls_T_f32;
	VAR(float32, AUTOMATIC) EstLq_Henry_T_f32;
	VAR(float32, AUTOMATIC) EstLd_Henry_T_f32;
	VAR(float32, AUTOMATIC) NomLq_Henry_T_f32;
	VAR(float32, AUTOMATIC) NomLd_Henry_T_f32;
	VAR(uint16, AUTOMATIC) IqRef_Amp_T_u9p7;
	VAR(uint16, AUTOMATIC) IdRef_Amp_T_u9p7;
	VAR(uint16, AUTOMATIC) LdSatSclFac_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) LqSatSclFac_Uls_T_u2p14;
	VAR(float32, AUTOMATIC) IntError_Amp_T_f32;
	VAR(boolean, AUTOMATIC) IntValid_Cnt_T_lgc;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_ParamComp_Per1_CP0_CheckpointReached();


	MtrTrqCmd_MtrNm_T_f32 = Rte_IRead_ParamComp_Per1_MRFMtrTrqCmdScl_MtrNm_f32();
	ValidCurrSample_Cnt_T_lgc = Rte_IRead_ParamComp_Per1_ValidCurrSample_Cnt_lgc();
	MtrQuad_Cnt_T_u8 = Rte_IRead_ParamComp_Per1_MtrQuad_Cnt_u08();
	MtrCurrQax_Amp_T_f32 = Rte_IRead_ParamComp_Per1_MtrCurrQax_Amp_f32();
	MtrCurrDax_Amp_T_f32=Rte_IRead_ParamComp_Per1_IdEst_Amp_f32();
	MtrVel_MtrRadpS_T_f32 = Rte_IRead_ParamComp_Per1_MRFMtrVel_MtrRadpS_f32();
	NomLq_Henry_T_f32 = Rte_Pim_EOLNomMtrParam()->NomLq_Henry_f32;
	NomLd_Henry_T_f32 = k_NomLd_Henry_f32;
	AccelGainEnable_Cnt_T_lgc = Rte_IRead_ParamComp_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc();
	
	
	MtrCurrQax_Amp_T_f32 =Limit_m(MtrCurrQax_Amp_T_f32,D_MINMTRCURRQAX_AMP_F32,D_MAXMTRCURRQAX_AMP_F32);
	TrqCmdRate_MtrNmpLp_T_f32 = Abs_f32_m(MtrTrqCmd_MtrNm_T_f32 - PrevMtrTrqCmd_MtrNm_M_f32);
	PrevMtrTrqCmd_MtrNm_M_f32 = MtrTrqCmd_MtrNm_T_f32;
	TrqCmdRate_MtrNmpLp_D_f32 = TrqCmdRate_MtrNmpLp_T_f32;
	/* Note: This delay implementation is dependant on this function running every 2ms */	
	IqError_Amp_T_f32 = Abs_f32_m(PrvExpIq_Amp_M_f32[k_IqErrDelay_mS_u17pm1 - 1U]) - MtrCurrQax_Amp_T_f32;
	
	ExpIq_Amp_T_f32 = MtrTrqCmd_MtrNm_T_f32 / (PrevEstKe_VpRadpS_M_f32 * D_SQRT3OVR2_ULS_F32);
	ExpIq_Amp_T_f32 = Limit_m(ExpIq_Amp_T_f32, -D_EXPIQMAX_AMP_F32, D_EXPIQMAX_AMP_F32);

	ExpIq_Amp_T_u12p4 = FPM_FloatToFixed_m(Abs_f32_m(ExpIq_Amp_T_f32), u12p4_T);

	for (i = TableSize_m(PrvExpIq_Amp_M_f32)-1U; i > 0U; i--)
	{
		PrvExpIq_Amp_M_f32[i] = PrvExpIq_Amp_M_f32[i-1U];
	}
	PrvExpIq_Amp_M_f32[0] = ExpIq_Amp_T_f32;
	
	AbsMtrVel_MtrRadpS_T_f32 = Abs_f32_m(MtrVel_MtrRadpS_T_f32);
	AbsMtrVel_MtrRadpS_T_u12p4 = FPM_FloatToFixed_m(AbsMtrVel_MtrRadpS_T_f32, u12p4_T);
	
	if (AbsMtrVel_MtrRadpS_T_u12p4 < D_KETBLOFFSET_MTRRADPS_U12P4)
	{
		TableIndex_Cnt_T_u16 = 0U;
	}
	else
	{
		TableIndex_Cnt_T_u16 = (AbsMtrVel_MtrRadpS_T_u12p4 - D_KETBLOFFSET_MTRRADPS_U12P4) / D_KELKUPFIXXSTP_MTRRADPS_U12P4;
		
		if (TableIndex_Cnt_T_u16 > (TableSize_m(t_KeIntgUpBndTbl_Amp_u12p4) - 1U))
		{
			TableIndex_Cnt_T_u16 = (TableSize_m(t_KeIntgUpBndTbl_Amp_u12p4) - 1U);
		}
	}
	
	CurrOffset_Amp_T_s11p4 = IntplVarXY_s16_u16Xs16Y_Cnt(	t_KeCurrOffTblX_MtrRadpS_u12p4, 
															t_KeCurrOffTblY_Amp_s11p4, 
															TableSize_m(t_KeCurrOffTblX_MtrRadpS_u12p4), 
															AbsMtrVel_MtrRadpS_T_u12p4);
	 
	
	KeFBckTyH_VpRadpS_M_f32 = ParameterCalc(
					TrqCmdRate_MtrNmpLp_T_f32,
					ValidCurrSample_Cnt_T_lgc,
					MtrQuad_Cnt_T_u8,
					ExpIq_Amp_T_u12p4,
					t_KeIntgUpBndTbl_Amp_u12p4[TableIndex_Cnt_T_u16], 
					t_KeIntgLoBndTbl_Amp_u12p4[TableIndex_Cnt_T_u16],
					IqError_Amp_T_f32,
					k_MaxErrValidKe_Amp_f32,
					(FPM_FixedToFloat_m(CurrOffset_Amp_T_s11p4, s11p4_T)),
					&KeIntgSV_Amp_M_f32,
					k_KeIntgAntiWindup_Amp_f32,
					k_AccKeGn_VpRadpSpAmp_f32,
					k_KeItgGn_VpRadpSpAmp_f32,
					AccelGainEnable_Cnt_T_lgc,
					(P2VAR(boolean, AUTOMATIC, AP_PARAMCOMP_CONST))&IntValid_Cnt_T_lgc,
					(P2VAR(float32, AUTOMATIC, AP_PARAMCOMP_CONST))&IntError_Amp_T_f32);
					
	RIntValid_Cnt_D_lgc=IntValid_Cnt_T_lgc;
    RIntError_Amp_D_f32=IntError_Amp_T_f32; 
	TableIndex_Cnt_T_u16 = AbsMtrVel_MtrRadpS_T_u12p4 / D_RLKUPFIXXSTP_MTRRADPS_U12P4;
	
	if (TableIndex_Cnt_T_u16 > (TableSize_m(t_RIntgUpBndTbl_Amp_u12p4) - 1U))
	{
	   TableIndex_Cnt_T_u16 = (TableSize_m(t_RIntgUpBndTbl_Amp_u12p4) - 1U);
	}
	
	CurrOffset_Amp_T_s11p4 = IntplVarXY_s16_u16Xs16Y_Cnt(	t_RCurrOffTblX_MtrRadpS_u12p4, 
															t_RCurrOffTblY_Amp_s11p4, 
															TableSize_m(t_RCurrOffTblX_MtrRadpS_u12p4), 
															AbsMtrVel_MtrRadpS_T_u12p4);
	 
	RFBckTyH_Ohm_M_f32 = ParameterCalc(
					TrqCmdRate_MtrNmpLp_T_f32,
					ValidCurrSample_Cnt_T_lgc,
					MtrQuad_Cnt_T_u8,
					ExpIq_Amp_T_u12p4,
					t_RIntgUpBndTbl_Amp_u12p4[TableIndex_Cnt_T_u16], 
					t_RIntgLoBndTbl_Amp_u12p4[TableIndex_Cnt_T_u16],
					IqError_Amp_T_f32,
					k_MaxErrValidR_Amp_f32,
					(FPM_FixedToFloat_m(CurrOffset_Amp_T_s11p4, s11p4_T)),
					&RIntgSV_Amp_M_f32,
					k_RIntgAntiWindup_Amp_f32,
					k_AccRItgGain_OhmpAmp_f32,
					k_RIntgGain_OhmpAmp_f32,
					AccelGainEnable_Cnt_T_lgc,
					(P2VAR(boolean, AUTOMATIC, AP_PARAMCOMP_CONST))&IntValid_Cnt_T_lgc,
					(P2VAR(float32, AUTOMATIC, AP_PARAMCOMP_CONST))&IntError_Amp_T_f32);		
	KeIntValid_Cnt_D_lgc=IntValid_Cnt_T_lgc;
    KeIntError_Amp_D_f32=IntError_Amp_T_f32;  	

	KeSatSclFac_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_KeSatTblX_Amp_u12p4, 
                          									t_KeSatTblY_Uls_u2p14,
                          									TableSize_m(t_KeSatTblX_Amp_u12p4), 
                          									ExpIq_Amp_T_u12p4);
															
	KeSatSclFac_Uls_T_f32 = FPM_FixedToFloat_m(KeSatSclFac_Uls_T_u2p14, u2p14_T);
	KeSatSclFac_Uls_D_f32 = KeSatSclFac_Uls_T_f32;														
															
															
	
	IqRef_Amp_T_u9p7=FPM_FloatToFixed_m(Abs_f32_m(ExpIq_Amp_T_f32), u9p7_T);
	IdRef_Amp_T_u9p7=FPM_FloatToFixed_m(Abs_f32_m(MtrCurrDax_Amp_T_f32), u9p7_T);

		 /**** Feedforward path estimation (Q axis inductance) Saturation scale factor ****/															
	LdSatSclFac_Uls_T_u2p14 = BilinearXYM_u16_u16Xu16YM_Cnt(IdRef_Amp_T_u9p7,
															IqRef_Amp_T_u9p7,
															t_ParamCompDaxRef_Amp_u9p7,
															TableSize_m(t_ParamCompDaxRef_Amp_u9p7),
															t_ParamCompQaxRef_Amp_u9p7,
															(P2CONST(uint16, AUTOMATIC, AUTOMATIC))t2_ParamLdSatSclFac_Uls_u2p14,
															TableSize_m(t_ParamCompQaxRef_Amp_u9p7));
	
	/**** Feedforward path estimation (D axis inductance) Saturation scale factor ****/	
	LqSatSclFac_Uls_T_u2p14 = BilinearXYM_u16_u16Xu16YM_Cnt(IdRef_Amp_T_u9p7,
															IqRef_Amp_T_u9p7,
															t_ParamCompDaxRef_Amp_u9p7,
															TableSize_m(t_ParamCompDaxRef_Amp_u9p7),
															t_ParamCompQaxRef_Amp_u9p7,
															(P2CONST(uint16, AUTOMATIC, AUTOMATIC))t2_ParamLqSatSclFac_Uls_u2p14,
															TableSize_m(t_ParamCompQaxRef_Amp_u9p7));

   	LqSatSclFac_Uls_T_f32 = FPM_FixedToFloat_m(LqSatSclFac_Uls_T_u2p14, u2p14_T);
	LdSatSclFac_Uls_T_f32 = FPM_FixedToFloat_m(LdSatSclFac_Uls_T_u2p14, u2p14_T);
	
	LqSatSclFac_Uls_D_f32 = LqSatSclFac_Uls_T_f32;	
	LdSatSclFac_Uls_D_f32 = LdSatSclFac_Uls_T_f32;
	
	
	EstKe_VpRadpS_T_f32 = (EstKeFF_VpRadpS_M_f32 * KeSatSclFac_Uls_T_f32) +  KeFBckTyH_VpRadpS_M_f32;
	
	EstR_Ohm_T_f32 = EstRFF_Ohm_M_f32 + RFBckTyH_Ohm_M_f32;
	EstLq_Henry_T_f32 = NomLq_Henry_T_f32 * LqSatSclFac_Uls_T_f32;
	EstLd_Henry_T_f32 = NomLd_Henry_T_f32 * LdSatSclFac_Uls_T_f32;

	PreLmtEstKe_VpRadpS_D_f32 = EstKe_VpRadpS_T_f32;
	PreLmtEstR_Ohm_D_f32 = EstR_Ohm_T_f32;
	PreLmtEstLq_Henry_D_f32 = EstLq_Henry_T_f32;
	PreLmtEstLd_Henry_D_f32 = EstLd_Henry_T_f32;
	
	EstKe_VpRadpS_T_f32 = Limit_m(EstKe_VpRadpS_T_f32, k_MinKeRngLmt_VpRadpS_f32, k_MaxKeRngLmt_VpRadpS_f32);
	EstR_Ohm_T_f32 = Limit_m(EstR_Ohm_T_f32, k_MinRRngLmt_Ohm_f32, k_MaxRRngLmt_Ohm_f32);

	EstLq_Henry_T_f32 = Limit_m(EstLq_Henry_T_f32, k_MinLqRngLmt_Henry_f32, k_MaxLqRngLmt_Henry_f32);
	EstLd_Henry_T_f32 = Limit_m(EstLd_Henry_T_f32, k_MinLdRngLmt_Henry_f32, k_MaxLdRngLmt_Henry_f32);
	
		
	PrevEstKe_VpRadpS_M_f32 = EstKe_VpRadpS_T_f32;
	
	Rte_IWrite_ParamComp_Per1_EstLq_Henry_f32(EstLq_Henry_T_f32);
	Rte_IWrite_ParamComp_Per1_EstLd_Henry_f32(EstLd_Henry_T_f32);
	Rte_IWrite_ParamComp_Per1_EstKe_VpRadpS_f32(EstKe_VpRadpS_T_f32);
	Rte_IWrite_ParamComp_Per1_EstR_Ohm_f32(EstR_Ohm_T_f32);
	Rte_IWrite_ParamComp_Per1_ExpIq_Amp_f32(ExpIq_Amp_T_f32);
	
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_ParamComp_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ParamComp_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_ParamComp_Per2_CuTempEst_DegC_f32(void)
 *   Float Rte_IRead_ParamComp_Per2_MagTempEst_DegC_f32(void)
 *   Float Rte_IRead_ParamComp_Per2_SiTempEst_DegC_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ParamComp_Per2
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) NomKe_VpRadpS_T_f32;
	VAR(float32, AUTOMATIC) NomRmtr_Ohm_T_f32;
	VAR(float32, AUTOMATIC) CuTempEst_DegC_T_f32;
	VAR(float32, AUTOMATIC) MagTempEst_DegC_T_f32;
	VAR(float32, AUTOMATIC) SiTempEst_DegC_T_f32;
	VAR(float32, AUTOMATIC) EstKeFF_VpRadpS_T_f32;
	VAR(float32, AUTOMATIC) EstRfetFF_Ohm_T_f32;
	VAR(float32, AUTOMATIC) EstRmtrFF_Ohm_T_f32;
	VAR(float32, AUTOMATIC) EstRFF_Ohm_T_f32;

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_ParamComp_Per2_CP0_CheckpointReached();

	NomKe_VpRadpS_T_f32 = Rte_Pim_EOLNomMtrParam()->NomKe_VpRadpS_f32;
	NomRmtr_Ohm_T_f32 = Rte_Pim_EOLNomMtrParam()->NomRmtr_Ohm_f32;
	CuTempEst_DegC_T_f32 = Rte_IRead_ParamComp_Per2_CuTempEst_DegC_f32();
	MagTempEst_DegC_T_f32 = Rte_IRead_ParamComp_Per2_MagTempEst_DegC_f32();
	SiTempEst_DegC_T_f32 = Rte_IRead_ParamComp_Per2_SiTempEst_DegC_f32();
	
	CuTempEst_DegC_T_f32 =Limit_m(CuTempEst_DegC_T_f32,D_MINCUTEMPEST_DEGC_F32,D_MAXCUTEMPEST_DEGC_F32);
	MagTempEst_DegC_T_f32=Limit_m(MagTempEst_DegC_T_f32,D_MINMAGTEMPEST_DEGC_F32,D_MAXMAGTEMPEST_DEGC_F32);
	SiTempEst_DegC_T_f32 =Limit_m(SiTempEst_DegC_T_f32,D_MINSITEMPEST_DEGC_F32,D_MAXSITEMPEST_DEGC_F32);
	
	EstKeFF_VpRadpS_T_f32 = NomKe_VpRadpS_T_f32 + ((MagTempEst_DegC_T_f32 - k_NomTemp_DegC_f32) * k_MagThrC_VpRadpSpDegC_f32 * NomKe_VpRadpS_T_f32);
	EstKeFF_VpRadpS_M_f32 = Limit_m(EstKeFF_VpRadpS_T_f32, k_MinKeRngLmt_VpRadpS_f32, k_MaxKeRngLmt_VpRadpS_f32);
	
	EstRfetFF_Ohm_T_f32 = k_NomRfet_Ohm_f32 + ((SiTempEst_DegC_T_f32 - k_NomTemp_DegC_f32) * k_SiThermCoeff_OhmpDegC_f32 * k_NomRfet_Ohm_f32);
	EstRmtrFF_Ohm_T_f32 = NomRmtr_Ohm_T_f32 + ((CuTempEst_DegC_T_f32 - k_NomTemp_DegC_f32) * k_CuThermCoeff_OhmpDegC_f32 * NomRmtr_Ohm_T_f32);

	EstRfetFF_Ohm_D_f32 = EstRfetFF_Ohm_T_f32;
	EstRmtrFF_Ohm_D_f32 = EstRmtrFF_Ohm_T_f32;

	EstRFF_Ohm_T_f32 = EstRfetFF_Ohm_T_f32 + EstRmtrFF_Ohm_T_f32;
	EstRFF_Ohm_M_f32 = Limit_m(EstRFF_Ohm_T_f32, k_MinRRngLmt_Ohm_f32, k_MaxRRngLmt_Ohm_f32);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_ParamComp_Per2_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_EOLNomMtrParam_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_EOLNomMtrParam_Get(Float *NomKe_VpRadpS_f32, Float *NomLq_Henry_f32, Float *NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomLq_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SCom_EOLNomMtrParam_Get
 *********************************************************************************************************************/
	*NomLq_Henry_f32 = Rte_Pim_EOLNomMtrParam()->NomLq_Henry_f32;
	*NomKe_VpRadpS_f32 = Rte_Pim_EOLNomMtrParam()->NomKe_VpRadpS_f32;
	*NomRmtr_Ohm_f32 = Rte_Pim_EOLNomMtrParam()->NomRmtr_Ohm_f32;

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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLNomMtrParamBlk_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_EOLNomMtrParamBlk_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SCom_EOLNomMtrParam_Set
 *********************************************************************************************************************/
	Rte_Pim_EOLNomMtrParam()->NomLq_Henry_f32 = NomLq_Henry_f32;
	Rte_Pim_EOLNomMtrParam()->NomKe_VpRadpS_f32 = NomKe_VpRadpS_f32;
	Rte_Pim_EOLNomMtrParam()->NomRmtr_Ohm_f32 = NomRmtr_Ohm_f32;

	(void)Rte_Call_EOLNomMtrParamBlk_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_KeIntgSVParam_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <SCom_KeIntgSVParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_KeIntgSVParam_Get(Float *KeIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) KeIntgSV_Amp_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SCom_KeIntgSVParam_Get
 *********************************************************************************************************************/
	*KeIntgSV_Amp_f32 = KeIntgSV_Amp_M_f32;

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
 * Runnable prototype:
 * ===================
 *   void SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SCom_KeIntgSVParam_Set
 *********************************************************************************************************************/
	KeIntgSV_Amp_M_f32= KeIntgSV_Amp_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_RIntgSVParam_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <SCom_RIntgSVParam>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SCom_RIntgSVParam_Get(Float *RIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) RIntgSV_Amp_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SCom_RIntgSVParam_Get
 *********************************************************************************************************************/
	*RIntgSV_Amp_f32 = RIntgSV_Amp_M_f32;

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
 * Runnable prototype:
 * ===================
 *   void SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SCom_RIntgSVParam_Set
 *********************************************************************************************************************/
	RIntgSV_Amp_M_f32= RIntgSV_Amp_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PARAMCOMP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC FUNC(float32, AP_PARAMETEREST_CODE) ParameterCalc(	VAR(float32, AUTOMATIC) TrqCmdRate_MtrNmpLp_T_f32,
															VAR(boolean, AUTOMATIC) ValidCurrSample_Cnt_T_lgc,
															VAR(uint8, AUTOMATIC) MtrQuad_Cnt_T_u8,
															VAR(uint16, AUTOMATIC) EstMtrCurrQax_Amp_T_u12p4,
															VAR(uint16, AUTOMATIC) IntgUpBnd_Amp_T_u12p4, 
															VAR(uint16, AUTOMATIC) IntgLoBnd_Amp_T_u12p4, 
															VAR(float32, AUTOMATIC) IqError_Amp_T_f32,
															VAR(float32, AUTOMATIC) MaxErr_Amp_T_f32, 
															VAR(float32, AUTOMATIC) Offset_Amp_T_f32, 
															CONSTP2VAR(float32, AUTOMATIC, AP_PARAMCOMP_CONST) StateVarPtr_Amp_T_f32, 
															VAR(float32, AUTOMATIC) AntiWindupLmt_Amp_T_f32, 
															VAR(float32, AUTOMATIC) AccelGain_Uls_T_f32, 
															VAR(float32, AUTOMATIC) NormGain_Uls_T_f32,
															VAR(boolean, AUTOMATIC) AccelGainEnable_Cnt_T_lgc,
															CONSTP2VAR(boolean, AUTOMATIC, AP_PARAMCOMP_CONST) IntValidPtr_Cnt_T_lgc,
															CONSTP2VAR(float32, AUTOMATIC, AP_PARAMCOMP_CONST) IntErrorPtr_Amp_T_f32)
{
	VAR(float32, AUTOMATIC) ValidError_Amp_T_f32;
	VAR(float32, AUTOMATIC) IntErr_Amp_T_f32;
	VAR(float32, AUTOMATIC) Output_Uls_T_f32;
	
	if(		((Abs_f32_m(IqError_Amp_T_f32)) < MaxErr_Amp_T_f32) &&
			(EstMtrCurrQax_Amp_T_u12p4 > IntgLoBnd_Amp_T_u12p4) && 
	   		(EstMtrCurrQax_Amp_T_u12p4 < IntgUpBnd_Amp_T_u12p4) &&
	   		((D_QUADRANT1_CNT_U8 == MtrQuad_Cnt_T_u8) || (D_QUADRANT3_CNT_U8 == MtrQuad_Cnt_T_u8)) &&
	        (TrqCmdRate_MtrNmpLp_T_f32 < k_TrqRateThrsh_MtrNm_f32) &&
		    (TRUE == ValidCurrSample_Cnt_T_lgc)
	  )
	{
		ValidError_Amp_T_f32 = IqError_Amp_T_f32 + Offset_Amp_T_f32;
		*IntValidPtr_Cnt_T_lgc = TRUE;
	}
	else
	{
		ValidError_Amp_T_f32 = 0.0f;
		*IntValidPtr_Cnt_T_lgc = FALSE;
	}

	*IntErrorPtr_Amp_T_f32 = ValidError_Amp_T_f32;
	
	if	((TRUE == AccelGainEnable_Cnt_T_lgc) && (NormGain_Uls_T_f32 > D_MINGAINRES_ULS_F32))
	{	
		ValidError_Amp_T_f32 = (ValidError_Amp_T_f32 * AccelGain_Uls_T_f32) / NormGain_Uls_T_f32;
	}
	
	IntErr_Amp_T_f32 = ValidError_Amp_T_f32 + *StateVarPtr_Amp_T_f32;
	IntErr_Amp_T_f32 = Limit_m(IntErr_Amp_T_f32, -AntiWindupLmt_Amp_T_f32, AntiWindupLmt_Amp_T_f32);
	*StateVarPtr_Amp_T_f32 = IntErr_Amp_T_f32;
	
	Output_Uls_T_f32 = IntErr_Amp_T_f32 * NormGain_Uls_T_f32;
	
	return (Output_Uls_T_f32);
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
