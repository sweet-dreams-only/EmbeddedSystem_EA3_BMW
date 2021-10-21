/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_CDDInterface9.c
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface9
 *  Generated at:  Fri Oct 30 15:43:29 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Sa_CDDInterface9>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Aug 15 20:53:00 2011
 * %version:          EA3#16.1.16 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Sat Jan 18 14:17:23 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/15/11  13       LWW       Phase Reasonableness Updates
 * 10/11/11  14       BDO       Add TcReflashActive interface
 * 11/23/11  15       BDO       Add SrlComSvcDft boolean flags based on CDD_EOLSrlComSvcDft_Cnt_G_b32 
 * 12/02/11  16       BDO       Add LimitSrlComSvcDft boolean flags												CR4678 
 * 01/27/12  17       OT        Added Functionality for Digital NHET Feedback
 * 02/15/12  16.1.2   BDO       Added enable flags for BMW functions - OscEnable, GenPosTrajEnable, LocktoLockEnable
 * 03/22/12  16.1.3   BDO       Add CDD_DftAsstTbl_Cnt_G_lgc and CDD_DwnldAsstGain_Uls_G_f32 back to Per4 - anomaly 3038, CR5074
 * 08/06/12  16.1.6   KJS       Anomaly correction for 3248
 * 09/11/12	 16.1.7	  KJS		Added Nxtr MEC output for new HwTrq component.
 * 09/21/12	 16.1.9	  JJW		Removed application 10 relevant processing
 * 02/14/13  16.1.10  KJS		QAC corrections.
 * 03/15/13  16.1.11  KJS		QAC corrections and added Tc Flash Verify port.
 * 04/11/13	 16.1.12  KJS		Anomaly 4393 correction. Added Init2 with MEC and IgnCntr.						CR7827
 * 06/18/13	 16.1.13  KJS		Added support for SrlCom fire wall defeats
 * 06/04/14	 16.1.15  KJS		Added first application run support for Edch integration.
 * 11/09/15	 16.1.16  ABS		Added enable flags for AvgFrcLrn and ActPullComp
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

 *********************************************************************************************************************/

#include "Rte_Sa_CDDInterface9.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"
#include "Interrupts.h"
#include "sc_ee_data.h"
#include "Nvm_Cfg.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"

#define D_SVCDFTLIMIT_CNT_B32 			0x40000U /* DFT BIT 18 (2^18 = 262144) */

#define CDDINTERFACE9_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, CDDInterface9_VAR_NOINIT) ApplFirstStartFlag_M_lgc;
#define CDDINTERFACE9_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

STATIC void ECU_FirstRunFunc_Init(void);
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
 * Enumeration Types:
 * ==================
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0U)
 *   ManufacturingMode (1U)
 *   EngineeringMode (2U)
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
 * Float: D_MAXSUPPLYLMT_WATTS_F32 = 2000.0F
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
 * UInt32: D_SVCDFTFIREWALLMASK_CNT_B32 = 2097152U
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


#define RTE_START_SEC_SA_CDDINTERFACE9_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface9_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface9_Init1
 *********************************************************************************************************************/
	
	EnableMtrCtlInterrupt();
	ECU_FirstRunFunc_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface9_Init2
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
 *   void Rte_IWrite_CDDInterface9_Init2_IgnCnt_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Init2_IgnCnt_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Init2_MfgDiagInhibit_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Init2_MfgDiagInhibit_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Init2_NxtrMEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface9_Init2_NxtrMEC_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Init2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface9_Init2
 *********************************************************************************************************************/

	/* Initial Value for the Nxtr MEC and IgnCntr*/
	Rte_IWrite_CDDInterface9_Init2_NxtrMEC_Cnt_enum(NxtrMEC_Uls_G_enum);
	Rte_IWrite_CDDInterface9_Init2_MfgDiagInhibit_Cnt_lgc(MfgDiagInhibit_Uls_G_lgc);
	Rte_IWrite_CDDInterface9_Init2_IgnCnt_Cnt_u16(Nvm_IgnCntr_Cnt_u16);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface9_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_CDDInterface9_Per1_TcActivePNVldCnt_Cnt_u32(void)
 *   UInt32 Rte_IRead_CDDInterface9_Per1_TcActivePN_Cnt_u32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface9_Per1_ActPullCompDisableOutput_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_ActPullCompDisableOutput_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ActPullCompLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_ActPullCompLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_AvgFrcLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_AvgFrcLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_DampingSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_DampingSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_DftAsstTbl_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_DftAsstTbl_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_DwnldAsstGain_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_DwnldAsstGain_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_EngONSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_EngONSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_FirewallSrlComSrvDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_FirewallSrlComSrvDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_HysAddSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_HysAddSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_HystCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_HystCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_IgnCnt_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_IgnCnt_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_LimitSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_LimitSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_LrnPnCenterEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_LrnPnCenterEnable_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MfgDiagInhibit_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_MfgDiagInhibit_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ModIdxSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_ModIdxSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MultIgnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_MultIgnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_NxtrMEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface9_Per1_NxtrMEC_Cnt_enum(void)
 *   void Rte_IWrite_CDDInterface9_Per1_OscTrajEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_OscTrajEnable_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ParkAstSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_ParkAstSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_PosTrajEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_PosTrajEnable_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_PullCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_PullCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ReturnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_ReturnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_SrlComSvcDft_Cnt_b32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_SrlComSvcDft_Cnt_b32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_TcFlashErrors_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_CDDInterface9_Per1_TcFlashErrors_Cnt_u08(void)
 *   void Rte_IWrite_CDDInterface9_Per1_TcFlashVerify_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_TcFlashVerify_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_TcReflashActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_TcReflashActive_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface9_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface9_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface9_Per1
 *********************************************************************************************************************/
	
	/* Update global variables per FDD 20C 16 */
	CDD_TcActivePNVldCnt_Cnt_G_u32 = Rte_IRead_CDDInterface9_Per1_TcActivePNVldCnt_Cnt_u32();
	CDD_TcActivePN_Cnt_G_u32 = Rte_IRead_CDDInterface9_Per1_TcActivePN_Cnt_u32();

	Rte_IWrite_CDDInterface9_Per1_TcFlashErrors_Cnt_u08(CDD_TcFlashErrors_Cnt_G_u08);
	Rte_IWrite_CDDInterface9_Per1_TcReflashActive_Cnt_lgc(CDD_TcFlashActive_Cnt_G_lgc);
	Rte_IWrite_CDDInterface9_Per1_TcFlashVerify_Cnt_lgc(CDD_TcFlashVerify_Cnt_G_lgc);

	/* DIAGNOSTIC SERVICE INTERFACE - ASSIST GAIN FUNCTION */
	Rte_IWrite_CDDInterface9_Per1_DftAsstTbl_Cnt_lgc(CDD_DftAsstTbl_Cnt_G_lgc);
	Rte_IWrite_CDDInterface9_Per1_DwnldAsstGain_Uls_f32(CDD_DwnldAsstGain_Uls_G_f32);

	/* DIAGNOSTIC SERVICE INTERFACE - BMW POSITION CONTROL ENABLE FLAGS */
	Rte_IWrite_CDDInterface9_Per1_OscTrajEnable_Cnt_lgc(CDD_OscEnableFlag_Cnt_G_lgc);
	Rte_IWrite_CDDInterface9_Per1_PosTrajEnable_Cnt_lgc(CDD_GenPosTrajEnableFlag_Cnt_G_lgc);
	Rte_IWrite_CDDInterface9_Per1_LrnPnCenterEnable_Cnt_lgc(CDD_LocktoLockEnableFlag_Cnt_G_lgc);
	
	/* DIAGNOSTIC SERVICE INTERFACE - SRLCOMSVC DEFEAT */
	Rte_IWrite_CDDInterface9_Per1_SrlComSvcDft_Cnt_b32(CDD_EOLSrlComSvcDft_Cnt_G_b32);

	/* NXTR MEC */
	Rte_IWrite_CDDInterface9_Per1_NxtrMEC_Cnt_enum(NxtrMEC_Uls_G_enum);

	/* IGNITION COUNTER */
	Rte_IWrite_CDDInterface9_Per1_IgnCnt_Cnt_u16(Nvm_IgnCntr_Cnt_u16);

	/* MANUFACTURING INHIBIT BIT */
	Rte_IWrite_CDDInterface9_Per1_MfgDiagInhibit_Cnt_lgc(MfgDiagInhibit_Uls_G_lgc);

	/* REQUEST TRANSITION TO OPERATE/RUN STATE */
	if ( (D_SVCDFTENGON_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTENGON_CNT_B32)) ||
		 (D_SVCDFTENGON_CNT_B32 == (CDD_CustEOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTENGON_CNT_B32)) )
	{
		Rte_IWrite_CDDInterface9_Per1_EngONSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_EngONSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTFREQDEPDMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTFREQDEPDMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_FreqDepDmpSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTKININTDIAG_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTKININTDIAG_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_KinIntDiagSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTTHERMALDC_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTTHERMALDC_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_ThermalDCSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTEOTIMPACT_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTEOTIMPACT_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_EOTImpactSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTEOTTHERMAL_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTEOTTHERMAL_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_EOTThermalSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTMTRVELNRMLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTMTRVELNRMLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTMTRPARMNRMLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTMTRPARMNRMLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if ( (D_SVCDFTTRQRMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTTRQRMP_CNT_B32)) ||
	     (D_SVCDFTTRQRMP_CNT_B32 == (CDD_CustEOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTTRQRMP_CNT_B32)) )
	{
		Rte_IWrite_CDDInterface9_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_TrqRmpSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTMODIDX_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTMODIDX_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_ModIdxSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_ModIdxSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTPULLCOMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTPULLCOMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_PullCompSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_PullCompSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTWHLIMBREJ_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTWHLIMBREJ_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_WhlImbRejSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTPARKAST_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTPARKAST_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_ParkAstSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_ParkAstSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTDRIVINGDYN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTDRIVINGDYN_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_DrivingDynSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTHYSTCOMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTHYSTCOMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_HystCompSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_HystCompSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTRETURN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTRETURN_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_ReturnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_ReturnSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTDAMPING_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTDAMPING_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_DampingSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_DampingSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	if (D_SVCDFTLIMIT_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTLIMIT_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_LimitSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_LimitSrlComSvcDft_Cnt_lgc(FALSE);	
	}
		
	/* DEFEAT RECEPTION OF SRLCOMINPUT MESSAGES */
	if (D_SVCDFTRXMSGS_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
	/* MULTIPLE IGNITION CYCLE DEFEATS - store EOLSrlComSvcDft */
	if (D_SVCDFTMULTIGNMASK_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTMULTIGNMASK_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_MultIgnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_MultIgnSrlComSvcDft_Cnt_lgc(FALSE);	
	}
	
 	/* Firewall Defeats */
	if (D_SVCDFTFIREWALLMASK_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTFIREWALLMASK_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_FirewallSrlComSrvDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_FirewallSrlComSrvDft_Cnt_lgc(FALSE);	
	}

	/* Average Friction Learning */
	if (D_SVCDFTAVGFRCLRNMASK_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTAVGFRCLRNMASK_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_AvgFrcLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_AvgFrcLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}

	/* Active Pull Compensation Learning */
	if (D_SVCDFTACTPULLLRNMASK_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTACTPULLLRNMASK_CNT_B32))
	{
		Rte_IWrite_CDDInterface9_Per1_ActPullCompLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface9_Per1_ActPullCompLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}


 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FirstStartPort_GetFirstStart
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetFirstStart> of PortPrototype <FirstStartPort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType FirstStartPort_GetFirstStart(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_FirstStartInterface_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_CDDINTERFACE9_APPL_CODE) FirstStartPort_GetFirstStart(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FirstStartPort_GetFirstStart (returns application error)
 *********************************************************************************************************************/
	VAR(Std_ReturnType, AUTOMATIC) ReturnValue_Uls_T_u8;

	if(ApplFirstStartFlag_M_lgc == TRUE)
	{
		ReturnValue_Uls_T_u8 = E_OK;
	}
	else
	{
		ReturnValue_Uls_T_u8 = E_NOT_OK;
	}

	return ReturnValue_Uls_T_u8;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FirstStartPort_ResetFirstStart
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetFirstStart> of PortPrototype <FirstStartPort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType FirstStartPort_ResetFirstStart(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_FirstStartInterface_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_CDDINTERFACE9_APPL_CODE) FirstStartPort_ResetFirstStart(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FirstStartPort_ResetFirstStart (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FirstStartPort_SetFirstStart
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetFirstStart> of PortPrototype <FirstStartPort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType FirstStartPort_SetFirstStart(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_FirstStartInterface_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_CDDINTERFACE9_APPL_CODE) FirstStartPort_SetFirstStart(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FirstStartPort_SetFirstStart (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_CDDINTERFACE9_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
  * Name:        ECU_FirstRunFunc_Init()
  * Description: Local Function intended to initialize data that only needs to
  *              be initialized upon the first run of the application.
  * 			NOTE:  This function was placed into the CDD interface for 
  * 			convenience only and not other reason.  Also, no thought was put
  *             into what data should be initialized on a first application run
  *             i.e. after a re-flash.  Coding required this so that the first run flag
  *             is all that is completed here at this time.
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
STATIC void ECU_FirstRunFunc_Init(void)
{
	if(BootProgData.ApplicStartedFirst == (uint8)ISFIRSTSTARTOFAPPLICATION)
	{
		/* If the first start of the application, inform Edch by setting this
		 * flag to true for the key cycle. Other key cycles should keep
		 * the flag false. */
		ApplFirstStartFlag_M_lgc = TRUE;
		BootProgData.ApplicStartedFirst = (uint8)ISNOTFIRSTSTARTOFAPPLICATION;
		(void)NvM_WriteBlock((uint8)NVM_BLOCK_BOOT_PROG_DATA, NULL_PTR);
	}
	else
	{
		ApplFirstStartFlag_M_lgc = FALSE;
	}
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
