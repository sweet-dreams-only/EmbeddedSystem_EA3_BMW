/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComOutput2.c
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComOutput/autosar
 *     SW-C Type:  Ap_SrlComOutput2
 *  Generated at:  Thu Feb  2 14:05:09 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComOutput2>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          EA3#26 %
 * %date_modified:    Fri Jan 17 07:38:26 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                                              SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------                    	   ----------
 * 10/24/12	  1	      BDO		Initial version of SrComOutput2 ASIL_D component from SrlComInput application split.              	CR6627
 * 10/24/12	  2	      BDO		Move Tx COM callouts and SrlComOutput_MainFunction from SrComOutput2(ASIL_D) to SrComOutput(QM)   	CR6627
 * 11/02/12	  3	      BDO		Modify transmission of ST_EST to ensure alive counter processing is in synch with tx rate			CR6627
 * 11/07/12	  4	      JJW		Replaced NTC num magic numbers with enumeration names in Swa Qual function
 * 11/21/12   5		  KJS		Added ports for transmission notification between SrlComOuput and SrlComOutput2
 * 03/06/13	  6		  KJS		SER updates and QAC corrections.
 * 04/25/13	  7		  KJS		Anomaly correction for A_4788.
 * 04/27/13	  8		  BWL		Anomaly correction for anomaly 4839																	CR8137
 * 10/07/13	  9		  KJS		Added support for TJA in the QU_SER_STMOM_DV_ACT message.
 * 01/16/13	  11	  KJS		Added support for TJA Enum for version 2 of the TJA component.
 * 03/09/16	  15	  ABS		QAC Correction																						EA3#6554
 * 05/26/16	  16	  ABS		SCIR 002A Implementation																			EA3#7977
 * 06/29/16	  17	  ABS		Updated to prevent null frames for DT_EST and proper timing trigger for SU_EPS   		  EA3#9243, EA3#9245
 * 07/19/16	  18	  ABS		Anomaly correction for unused bits   		  														EA3#9653
 * 08/01/16   19      RMV   	Output Periodic functions is split according the messages
 * 08/08/16   20      RMV   	Anomaly corrections for DISP_CC_EPS message timing handling
 * 11/02/16   21      ABS   	BMW Torque Overlay Updates, ELMA Diagnosis                                               EA3#11165, EA3#11918
 * 11/11/16   22      ABS   	BMW Torque Overlay Updates, ELMA Diagnosis - updated after unit testing                  EA3#11165, EA3#11918
 * 11/11/16   23      ABS   	BMW Torque Overlay Updates - updated after testing  (wrong checkin comment)						    EA3#11918
 * 11/19/16	  24	  ABS		Integrate Torque Overlay Issue																	    EA3#12713
 * 02/03/17	  24	  ABS		Updated for SCIR002M - ELMA and EVI														 EA3#13116, EA3#12921
 * 04/28/17   25      RMV   	Updated for ELMA EA3#15436
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
  CRC8
    Standartabsicherung Apllikations-CRC.

  QU_SER_WSTA_EST_FTAX
    Service-Qualifier zur Lenkradvibration


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nxtr SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComOutput2.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_SrlComOutput2_Cfg.h"
#include "Com.h"
#include "Com_Cbk.h"
#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CheckSums.h"

#include "osek.h"
#include "CDD_Data.h"

/* E2EP Library Header Includes */
#include "E2EPW_Ap_SrlComOutput2_SrlComAVLSTMOM_SrlComAVLFORCGRD_tx.h"
#include "E2EPW_Ap_SrlComOutput2_SrlComSTEST_SrlComSTEST_tx.h"
#include "E2EPW_Ap_SrlComOutput2_SrlComAVLPOEPS_SrlComAVLPOEPS_tx.h"
#include "E2EPW_Ap_SrlComOutput2_SrlComAVLSTMOM_SrlComAVLSTMOMDVACT_tx.h"
#include "E2EPW_Ap_SrlComOutput2_SrlComDISPCCEPS_SrlComDISPCCEPS_tx.h"
#include "E2EPW_Ap_SrlComOutput2_SrlComDTEST_SrlComDTEST_tx.h"
#include "E2EPW_Ap_SrlComOutput2_SrlComSTEST_SrlComSTEST_tx.h"
#include "E2EPW_Ap_SrlComOutput2_SrlComSUEPS_SrlComSUEPS_tx.h"

#define D_HWTRQLOLMT_HWNM_F32				(-10.0F)
#define D_HWTRQHILMT_HWNM_F32				10.0F
#define D_HWTRQSCALE_CNTSPHWNM_F32			200.0F		
#define D_HWTRQOFFSET_HWNM_F32				10.0F
#define D_HWTRQINVALID_CNT_U16				0xFFFU

#define D_ELECPWRLOLMT_WATTS_F32			(-12000.0F)
#define D_ELECPWRHILMT_WATTS_F32			12000.0F
#define D_ELECPWRSCALE_CNTSPKWATTS_F32		0.01F /* Combined input and com signal conversion */
#define D_ELECPWROFFSET_WATTS_F32			12000.0F
#define D_INVALIDELECPWR_CNT_U08			0x78U

#define D_RCKLDLOLMT_KN_F32					(-17.0F)
#define D_RCKLDHILMT_KN_F32					17.0F
#define D_RCKLDSCALE_CNTSPKN_F32			119.04761904761904761904761904762F		
#define D_RCKLDOFFSET_KN_F32				17.0F
#define D_RCKLDINVALID_CNT_U16				0xFFFU
#define D_RCKLDQUALVLDGUAR_CNT_U8			0x02U
#define D_RCKLDQUALINVTEMP_CNT_U8			0x0EU

#define D_HWTRQQUALVLDGUAR_CNT_U8			0x01U
#define D_HWTRQQUALINVTEMP_CNT_U8  			0x0EU
#define D_HWTRQQUALINV_CNT_U8				0x0FU

#define D_SWALOLMT_HWDEG_F32				(-1440.11F)
#define D_SWAHILMT_HWDEG_F32				1440.11F
#define D_SWASCALE_CNTSPHWDEG_F32			22.75313F
#define D_SWAOFFSET_HWDEG_F32				1440.11F
#define D_SWAINVALID_CNT_U16				0xFFFFU

#define D_RCKVEHCNTROFFSETLOLMT_CNTS_S16	(-2047)
#define D_RCKVEHCNTROFFSETHILMT_CNTS_U16	2047U
#define D_RCKVEHCNTRMSGOFFSET_CNTS_U16		2047U
#define D_RCKVEHCNTROFFSETSCALE_CNTS_U0P16   (FPM_InitFixedPoint_m (0.04395, u0p16_T))

#define D_SWAQUALINVTEMP_CNT_U8				0x0EU
#define D_SWAQUALVLDGUAR_CNT_U8				0x01U
#define D_SWAQUALVLD_CNT_U8					0x02U
#define D_SWAREPLVALSET_CNT_U8				0x04U
#define D_SWAQUALINV_CNT_U8					0x0FU

#define D_DRVDYNSTATEOVRRD_CNT_U08    	  	0xE1U

#define D_ASTLIMITTHRESHOLD_ULS_F32         0.3F

#define D_STESTSLOWTXCNT_CNT_U08			49U
#define D_STESTFASTTXCNT_CNT_U08			4U
#define D_TXREPETITIONS_CNT_U08			    3U

#define D_INITIALIZATION_CNT_U16			8U

#define D_DRVDYNAVAL_TJAACTV_CNT_U16		0x22U
#define D_DRVDYNACTV_TJAACTV_CNT_U16		0x23U

#define D_TWOSECTIME_CNT_U16				2000U
#define D_TEN_CNT_U16						0x0AU
#define D_ZERO_CNT_U16						0x0U

/* SU_EPS message */
#define D_TOTSTREPSVLDVALUE1_CNT_U08		0x4CCU
#define D_TOTSTREPSVLDVALUE2_CNT_U08		0x53CU
#define D_EPSROTORREV_DEG_F32				360.0F
#define D_GEARRATIOSCALE_ULS_F32			81.87996397281585196102513714894F
#define D_GEARPINANGLELOLMT_DEG_F32			0.0F
#define D_GEARPINANGLEHILMT_DEG_F32			50.0F
#define D_GEARPINANGLEOFFSET_DEG_F32		0.0F

/* Check Control Message */
#define D_INDICATORLAMPON_CNT_U08			1U
#define D_INDICATORLAMPOFF_CNT_U08			0U
#define D_CCMSGCOUNTER_CNT_U16              627U			/* Hardcode to 0x273 per SER */
#define D_CCMSGCOUNTER_THRMLDEGRADN_CNT_U16 0x3E5U			/* Hardcode to 997 per SER */
#define D_CCMSGCOUNTERMAX_CNT_U16 			0xFFFEU
#define D_CDISPCCEPS_MAXMASK_CNT_U08			0x03U
#define D_CDISPCCEPS_DEDICATEDMASK_CNT_U08	0x02U

#define D_SUEPSBURSTCNT_CNT_U08		0x3U
#define D_SUEPSBURSTCNTLMT_CNT_U08	49U
#define D_SUEPSPERCNTLMT_CNT_U16	499U

#define D_DISP_CC_MSG_COUNT  31U

#define SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_8
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(QU_FN_EST, AP_SRLCOMOUTPUT2_VAR_NOINIT) EPSFuncQual_Cnt_M_enum;
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR_NOINIT) StEstFastTxCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR_NOINIT) StEstTxRepetitions_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR_NOINIT) SuEpsBurstCntr_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR_NOINIT) SuEpsBurstTrigger_Cnt_M_u08;

#define SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"/* PRQA S 5087 */

#define SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint16, AP_SRLCOMOUTPUT_VAR_NOINIT) SupplCurInvldTimer_mS_M_u16;
STATIC VAR(uint16, AP_SRLCOMOUTPUT_VAR_NOINIT) SupplCurWarningTimer_mS_M_u16;
STATIC VAR(uint16, AP_SRLCOMOUTPUT_VAR_NOINIT) SuEpsPerCntr_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMOUTPUT_VAR_NOINIT) StEstTxCounter_Cnt_M_u16;
#define SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */


#define SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT2_VAR_NOINIT) DisableModeEntry_Cnt_M_lgc;  /* QU_FN_EST */
STATIC VAR(uint8, AP_SRLCOMOUTPUT2_VAR_NOINIT) SetNtc_DataRngFltMsg_AB_M_lgc; /* NTC 19C handling */
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR_INIT) StEstInitialTx_Cnt_M_lgc;
#define SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */

#define SRLCOMOUTPUT2_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(RT_SG_ST_EST, AP_SRLCOMOUTPUT_VAR_NOINIT) StEst_M_Str;
#define SRLCOMOUTPUT2_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */

STATIC FUNC(uint16, AP_SRLCOMOUTPUT2_CODE) CalcHwTrqSignal(	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32,
															VAR(uint8, AUTOMATIC) HwTrqQualSignal_Cnt_T_u8);

STATIC FUNC(uint16, AP_SRLCOMOUTPUT2_CODE) ScaleSignal_u16(	VAR(float32, AUTOMATIC) Signal_Uls_T_f32,
															VAR(float32, AUTOMATIC) LoLmt_Uls_T_f32,
															VAR(float32, AUTOMATIC) HiLmt_Uls_T_f32,
															VAR(float32, AUTOMATIC) Scale_Uls_T_f32,
															VAR(float32, AUTOMATIC) Offset_Uls_T_f32);

STATIC FUNC(uint8, AP_SRLCOMOUTPUT2_CODE) CalcSWAQualSignal(	VAR(float32, AUTOMATIC) FinHwPosAuth_Uls_T_f32);

STATIC FUNC(uint16, AP_SRLCOMOUTPUT2_CODE) CalcSWASignal(	VAR(float32, AUTOMATIC) SWA_HwDeg_T_f32,
															VAR(uint8, AUTOMATIC) SWAQualSignal_Cnt_T_u8);

STATIC FUNC(AVL_FORC_GRD, AP_SRLCOMOUTPUT2_CODE) CalcRckLdSignal( VAR(float32, AUTOMATIC)RackLoad_kN_T_f32,
															    VAR(QU_AVL_FORC_GRD, AUTOMATIC)RackLoadQual_Cnt_T_enum);

STATIC FUNC(QU_FN_EST, AP_SRLCOMOUTPUT2_CODE) CalcEPSFuncQual( 	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum, VAR(float32, AUTOMATIC) LimitPercentFiltered_Uls_T_f32,
															  	VAR(boolean, AUTOMATIC) RecFltPres_Cnt_T_lgc, VAR(boolean, AUTOMATIC) NonRecFltPres_Cnt_T_lgc  );

STATIC FUNC(uint8, AP_SRLCOMOUTPUT2_CODE) CalcElecPowerSignal( VAR(float32, AUTOMATIC) ElecPower_Watts_T_f32,
                                                             VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum);
/* Subfunctions in the OutpUt Per1 function */                                                             
STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE) SrlComOutput2_Tx_DT_EST(void);

STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE) SrlComOutput2_Tx_DISP_CC_EPS(void);

STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE)SrlComOutput2_Tx_AVL_FORC_GRD_STMOM_DV_ACT(void);

STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE)SrlComOutput2_Tx_ST_EST(void);

STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE)SrlComOutput2_Tx_AVL_PO_EPS(void);
		
STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE)SrlComOutput2_Tx_SU_EPS(void);

#define DEM_NUMBER_OF_INDICATORS	1
#define DEM_NUM_INDICATOR_LINKS		23
#define DEM_NUMBER_OF_EVENTS		108
#define DEM_DTCSTATUSBIT_WIR        0x80U
#define THERMAL_LIMIT				35U

typedef struct
{
   Dem_DTCStatusMaskType    DTCStatusMask[DEM_NUMBER_OF_EVENTS];
                                                    /**< Status of each DTC */
   uint8                    ClearPDTC[(DEM_NUMBER_OF_EVENTS - 1U) / 8U + 1U];
   /**< Bit array to store the condition wheter the pending DTC flag may be
    * cleared at the end of the current/next operation cycle */

   uint8                    EvMemOverflowFlags;
                     /**< Overflow Flags / "Condition Byte" for each origin */
} Dem_NvStatusDataType;

extern VAR(Dem_NvStatusDataType, DEM_VAR_NOINIT) Dem_NvStatusData;

extern CONSTP2VAR(Dem_DTCStatusMaskType, DEM_CONST, DEM_VAR_NOINIT)  Dem_DTCStatusMasks;

#define DEM_IS_BIT_SET(Byte, Mask) \
   (((Byte) & (Mask)) != 0U)

#define DEM_IS_EV_ST_BIT_SET(EventId, Mask) \
   (DEM_IS_BIT_SET(Dem_DTCStatusMasks[(EventId)], (Mask)))

typedef struct
{
   /** Number of events assinged to this indicator */
   Dem_EventIdType Number;
   /** Index in Dem_IndicatorLink[], where the links for this indicators
    ** begin - may be invalid if Number is 0 */
   uint32 StartIdx;
} Dem_IndicatorDescType;

/** \brief Type used for the warning indicator-link configuration list */
typedef struct
{
   /** Event Id to which this indicator is linked to */
   Dem_EventIdType EventId;
   /** Indicator behaviour (which does not use ::DEM_INDICATOR_OFF) */
   Dem_IndicatorStatusType Behaviour;
} Dem_IndicatorLinkType;

extern CONST(Dem_IndicatorDescType, DEM_CONST)
   Dem_IndicatorDesc[DEM_NUMBER_OF_INDICATORS];

extern CONST(Dem_IndicatorLinkType, DEM_CONST)
   Dem_IndicatorLink[DEM_NUM_INDICATOR_LINKS];

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
 * AVL_FORC_GRD: Integer in interval [0...4048]
 * AVL_PINA_EPS: Integer in interval [0...65534]
 * AVL_PINA_IDX_ICM: Integer in interval [0...65534]
 * AVL_PWR_EL: Integer in interval [0...240]
 * Boolean: Boolean (standard type)
 * CD_0x04: Integer in interval [0...15]
 * CD_0x06: Integer in interval [0...63]
 * CD_0x08: Integer in interval [0...255]
 * CD_0x20: Integer in interval [0...4294967295]
 * CRC8: Integer in interval [0...255]
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * New_Coding_40: Integer in interval [0...255]
 * New_Coding_41: Integer in interval [0...14]
 * New_Coding_42: Integer in interval [0...14]
 * New_Coding_43: Integer in interval [0...65534]
 * New_Coding_45: Integer in interval [0...14]
 * New_Coding_47: Integer in interval [0...255]
 * New_Coding_48: Integer in interval [0...14]
 * New_Coding_51: Integer in interval [0...14]
 * New_Coding_52: Integer in interval [0...255]
 * OFFS_GRD_MID_EPS: Integer in interval [0...4094]
 * STMOM_QTA_DV: Integer in interval [0...4000]
 * TOT_STR_EPS: Integer in interval [0...4094]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_COU_4: Enumeration of integer in interval [0...15] with enumerators
 *   CxF_Signal_ungueltig (15U)
 * IDX_TORQ_SEN: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Initialisierung (0U)
 *   Cx1_Keine_Index_Flanke (1U)
 *   Cx2_Index_Flanke (2U)
 *   Cx3_Signal_ungueltig (3U)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_PLLSlipNrcvrl (22U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PeripheralStartupFlt (55U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73U)
 *   NTC_Num_IvtrPwrDiscnctFailr (74U)
 *   NTC_Num_PowerRelayInit2Flt (75U)
 *   NTC_Num_GateDrvFltInProcess (76U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_Ivtr2PwrDiscnctFailr (90U)
 *   NTC_Num_SysVltgCorrlnFlt (91U)
 *   NTC_Num_Inv2GateDrvFltInProcess (92U)
 *   NTC_Num_Inv2GateDrvFlt (93U)
 *   NTC_Num_Inv2OnStateSingleFET (94U)
 *   NTC_Num_EcuIdnFlt (95U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_ImcArbrFault (127U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_TurnCntr_SpiDataFlt (135U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_EcuCrossChk (150U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_LimpHomeIgnitionCounter (161U)
 *   NTC_Num_AgCompDiagc (167U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_LoaRpdShutdn (170U)
 *   NTC_Num_LoaCtrldShutdn (171U)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_DataOtherFlt2Msg_Q (327U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_InvalidMsg_AJ (472U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_InvalidMsg_AK (480U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AM (482U)
 *   NTC_Num_InvalidMsg_AM (483U)
 *   NTC_Num_CRCFltMsg_AM (484U)
 *   NTC_Num_PgrsCntFltMsg_AM (485U)
 *   NTC_Num_DataRngFltMsg_AM (486U)
 *   NTC_Num_InvalidMsg_AL (488U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_DataRngFltMsg_AL (492U)
 *   NTC_Num_DataOtherFltMsg_AL (494U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
 * New_Coding_39: Enumeration of integer in interval [0...4095] with enumerators
 *   CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar (4093U)
 *   CxFFE_Funktion_meldet_Fehler (4094U)
 *   CxFFF_Signal_unbefuellt (4095U)
 * New_Coding_44: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Kein_Blinken (0U)
 *   Cx1_Langsames_Blinken (1U)
 *   Cx2_Schnelles_Blinken (2U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_46: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Ruecksetzen (0U)
 *   Cx1_Setzen (1U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_49: Enumeration of integer in interval [0...255] with enumerators
 *   CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
 *   CxFE_Funktion_meldet_Fehler (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_50: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Funktion_verfuegbar_nicht_aktiv (1U)
 *   Cx6_Fehler (6U)
 *   Cx9_Funktion_verfuegbar_aktiv (9U)
 *   CxE_Funktion_nicht_verfuegbar (14U)
 *   CxF_Signal_unbefuellt (15U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * QU_AVL_FORC_GRD: Enumeration of integer in interval [0...15] with enumerators
 *   Cx2_Signalwert_ist_gueltig (2U)
 *   Cx8_Initialisierung (8U)
 *   CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
 *   CxF_Signal_ungueltig (15U)
 * QU_AVL_PINA_EPS: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
 *   Cx2_Signalwert_ist_gueltig (2U)
 *   Cx4_Ersatzwert_ist_im_Nutzsignal_gesetzt (4U)
 *   Cx8_Initialisierung (8U)
 *   CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
 *   CxC_Abgleichwert_ist_im_Nutzsignal_gesetzt___Zustand_Status_temporaer (12U)
 *   CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
 *   CxF_Signal_ungueltig (15U)
 * QU_AVL_STMOM_DV_ACT: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
 *   Cx6_Signalwert_ist_ungueltig (6U)
 *   Cx8_Initialisierung (8U)
 *   CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
 *   CxF_Signal_ungueltig (15U)
 * QU_FN_EST: Enumeration of integer in interval [0...255] with enumerators
 *   Cx31_Funktion_in_Rueckfallebene (49U)
 *   Cx33_Funktion_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv (51U)
 *   Cx60_Funktion_nicht_verfuegbar___Fehler (96U)
 *   Cx80_Initialisierung (128U)
 *   CxA0_Funktion_verfuegbar___Aktiv__12V_EPS (160U)
 *   CxA2_Funktion_verfuegbar___Aktiv__Notfallfunktion_Umwelteinfluesse___Aktiv (162U)
 *   CxA4_Funktion_verfuegbar___Aktiv__12V_EAS (164U)
 *   CxA8_Funktion_verfuegbar___Aktiv__24V_EAS (168U)
 *   CxB0_Funktion_temporaer_in_Rueckfallebene (176U)
 *   CxB2_Funktion_temporaer_in_Rueckfallebene__Notfallfunktion_Umwelteinfluesse__Aktiv (178U)
 *   CxE0_Funktion_nicht_verfuegbar___ausgeschaltet (224U)
 *   CxFF_Signal_ungueltig (255U)
 * QU_SER_STMOM_STMOM_DV_ACT: Enumeration of integer in interval [0...255] with enumerators
 *   Cx20_Schnittstelle_verfuegbar___funktionsbereit_ohne_Zusatzdaempfung (32U)
 *   Cx21_Schnittstelle_aktiv___Zusatzdaempfung_nicht_verfuegbar (33U)
 *   Cx22_Schnittstelle_verfuegbar___funktionsbereit_mit_Zusatzdaempfung (34U)
 *   Cx23_Schnittstelle_aktiv___Zusatzdaempfung_verfuegbar (35U)
 *   Cx60_Service_nicht_verfuegbar___Fehler (96U)
 *   Cx80_Schnittstelle_wird_initialisiert (128U)
 *   CxE0_Service_nicht_verfuegbar___Standby___PMA (224U)
 *   CxE1_Service_nicht_verfuegbar___Standby___EPS_Status (225U)
 *   CxFF_Signal_ungueltig (255U)
 * QU_SER_WSTA_EST_FTAX: Enumeration of integer in interval [0...255] with enumerators
 *   Cx20_Schnittstelle_verfuegbar___funktionsbereit (32U)
 *   Cx21_Schnittstelle_aktiv (33U)
 *   Cx60_Service_nicht_verfuegbar___Fehler (96U)
 *   Cx80_Schnittstelle_wird_initialisiert (128U)
 *   CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 (224U)
 *   CxE2_Funktion_in_Rueckfallebene___Hands_On (226U)
 *   CxE3_Funktion_in_Rueckfallebene___EPS_Status (227U)
 *   CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen (228U)
 *   CxE7_Schnittstelle_aktiv_degradiert (231U)
 *   CxFF_Signal_ungueltig (255U)
 * TJAStateType: Enumeration of integer in interval [1...3] with enumerators
 *   TJA_Inactive (1U)
 *   TJA_Active (2U)
 *   TJA_Error (3U)
 * UN_PO_EPS: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Ritzelschnittstelle (0U)
 *   Cx1_Zahnstangenhubschnittstelle (1U)
 *   Cx3_Signal_ungueltig (3U)
 * UN_TOT_STR_EPS: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Ritzelschnittstelle (0U)
 *   Cx1_Zahnstangenhubschnittstelle (1U)
 *   Cx3_Signal_ungueltig (3U)
 *
 * Record Types:
 * =============
 * RT_SG_AVL_FORC_GRD: Record with elements
 *   ALIV_AVL_FORC_GRD of type ALIV_COU_4
 *   AVL_FORC_GRD of type AVL_FORC_GRD
 *   AVL_FORC_GRD_0x0C_0x04 of type CD_0x04
 *   AVL_PWR_EL_EPS_COOD of type AVL_PWR_EL
 *   CRC_AVL_FORC_GRD of type CRC8
 *   QU_AVL_FORC_GRD of type QU_AVL_FORC_GRD
 * RT_SG_AVL_PO_EPS: Record with elements
 *   ALIV_AVL_PO_EPS of type ALIV_COU_4
 *   AVL_PO_EPS of type AVL_PINA_EPS
 *   CRC_AVL_PO_EPS of type CRC8
 *   IDX_TORQ_SEN of type IDX_TORQ_SEN
 *   AVL_PO_IDX_EPS of type AVL_PINA_IDX_ICM
 *   OFFS_GRD_MID_EPS of type OFFS_GRD_MID_EPS
 *   QU_AVL_PO_EPS of type QU_AVL_PINA_EPS
 *   UN_PO_EPS of type UN_PO_EPS
 * RT_SG_AVL_STMOM_DV_ACT: Record with elements
 *   ALIV_AVL_STMOM_DV_ACT of type ALIV_COU_4
 *   AVL_STMOM_DV_ACT of type STMOM_QTA_DV
 *   AVL_STMOM_DV_ACT_0x0C_0x04 of type CD_0x04
 *   CRC_AVL_STMOM_DV_ACT of type CRC8
 *   QU_AVL_STMOM_DV_ACT of type QU_AVL_STMOM_DV_ACT
 * RT_SG_ST_EST: Record with elements
 *   ALIV_ST_EST_FTAX of type ALIV_COU_4
 *   CRC_ST_EST_FTAX of type CRC8
 *   QU_FN_EST of type QU_FN_EST
 *   ST_EST_0x10_0x08 of type CD_0x08
 *   QU_SER_STMOM_DV_ACT of type QU_SER_STMOM_STMOM_DV_ACT
 *   QU_FN_VIB_EPS of type New_Coding_50
 * RT_SG_SU_EPS: Record with elements
 *   TOT_STR_EPS of type TOT_STR_EPS
 *   UN_TOT_STR_EPS of type UN_TOT_STR_EPS
 *   ALIV_SU_EPS of type New_Coding_51
 *   CRC_SU_EPS of type New_Coding_52
 *   SU_EPS_0x0E_0x20 of type CD_0x20
 *   SU_EPS_0x2E_0x06 of type CD_0x06
 * SG_DISP_CC_EPS: Record with elements
 *   TRANF_CC_EPS of type New_Coding_45
 *   NO_CC_EPS of type New_Coding_43
 *   ST_CC_EPS of type New_Coding_46
 *   ST_IDC_CC_EPS of type New_Coding_44
 *   CRC_DISP_CC_EPS of type New_Coding_40
 *   CHL_DISP_CC_EPS of type New_Coding_41
 *   ALIV_DISP_CC_EPS of type New_Coding_42
 * SG_DT_EST: Record with elements
 *   CRC_DT_EST of type New_Coding_47
 *   DT_EST_0x38_0x20 of type CD_0x20
 *   DT_EST_0x2C_0x04 of type CD_0x04
 *   ALIV_DT_EST of type New_Coding_48
 *   AVL_I_ACT_EST of type New_Coding_49
 *   DT_EST_0x78_0x08 of type CD_0x08
 *   DT_EST_0x0C_0x20 of type CD_0x20
 *   DT_EST_0x58_0x20 of type CD_0x20
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
 * Float: D_SUPPLYCURRINIT_AMP_F32 = 166.67F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * UInt16: D_RACKTOVEHCNTRINVALID_CNT_U16 = 4095U
 * UInt8: D_ONE_CNT_U8 = 1U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLCOMOUTPUT2_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput2_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DrvDynState_Cnt_u08(QU_SER_STMOM_STMOM_DV_ACT *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
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

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput2_Init1
 *********************************************************************************************************************/

	E2EPW_Init_SrlComAVLSTMOM_AVL_STMOM_DV_ACT_tx();
	E2EPW_Init_SrlComAVLSTMOM_AVL_FORC_GRD_tx();
	E2EPW_Init_SrlComAVLPOEPS_AVL_PO_EPS_tx();
	E2EPW_Init_SrlComSTEST_ST_EST_tx();
	E2EPW_Init_SrlComDTEST_DT_EST_tx();
	E2EPW_Init_SrlComDISPCCEPS_DISP_CC_EPS_tx();
	E2EPW_Init_SrlComSUEPS_SU_EPS_tx();

	DisableModeEntry_Cnt_M_lgc = FALSE;
	CDD_TxSUEPS_Cnt_G_lgc = TRUE;
	SuEpsPerCntr_Cnt_M_u16 = 0U;
  
	/* Intialise the variables related to ST_EST message handling */
	StEstInitialTx_Cnt_M_lgc = FALSE;
	StEstTxRepetitions_Cnt_M_u08 = 0U;
  
	CDD_TxDispSendMsg_Cnt_G_lgc = FALSE;
	CDD_DispCC_Per_Cnt_G_u08 = D_DISP_CC_MSG_COUNT;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput2_Per1
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
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CustCurrLmt_Amp_f32(Float *data)
 *   Std_ReturnType Rte_Read_DrvDynState_Cnt_u08(QU_SER_STMOM_STMOM_DV_ACT *data)
 *   Std_ReturnType Rte_Read_ElecPower_Watts_f32(Float *data)
 *   Std_ReturnType Rte_Read_FinHwPos_HwDeg_f32(Float *data)
 *   Std_ReturnType Rte_Read_FinHwPosAuth_Uls_f32(Float *data)
 *   Std_ReturnType Rte_Read_HaptcFbSt_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HwTrq_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_PrkAstState_Cnt_u08(QU_SER_WSTA_EST_FTAX *data)
 *   Std_ReturnType Rte_Read_RackLoad_kN_f32(Float *data)
 *   Std_ReturnType Rte_Read_SrlComHwTrqValid_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SupplyCur_Amp_f32(Float *data)
 *   Std_ReturnType Rte_Read_TJAState_Cnt_enum(TJAStateType *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComOutput2_Per1_AVLFORCGRDTxConf_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_AVLSTMOMTxConf_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CADASMSG_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComOutput2_Per1_CDISPCCEPS_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CEVIIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CFACTORIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CHWANGLEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_CMTTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput2_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput2_Per1_LimitPercentFiltered_Uls_f32(void)
 *   UInt16 Rte_IRead_SrlComOutput2_Per1_RacktoVehCntrOffset_Cnt_u16(void)
 *   UInt8 Rte_IRead_SrlComOutput2_Per1_RevOffsetState_Cnt_u08(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComAVLPOEPS_AVL_PO_EPS(const RT_SG_AVL_PO_EPS *data)
 *   Std_ReturnType Rte_Write_SrlComAVLSTMOM_AVL_FORC_GRD(const RT_SG_AVL_FORC_GRD *data)
 *   Std_ReturnType Rte_Write_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(const RT_SG_AVL_STMOM_DV_ACT *data)
 *   Std_ReturnType Rte_Write_SrlComDISPCCEPS_DISP_CC_EPS(const SG_DISP_CC_EPS *data)
 *   Std_ReturnType Rte_Write_SrlComDTEST_DT_EST(const SG_DT_EST *data)
 *   Std_ReturnType Rte_Write_SrlComSTEST_ST_EST(const RT_SG_ST_EST *data)
 *   Std_ReturnType Rte_Write_SrlComSUEPS_SU_EPS(const RT_SG_SU_EPS *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Write_SrlComAVLPOEPS_AVL_PO_EPS(RT_SG_AVL_PO_EPS *data)
 *   uint32 E2EPW_Write_SrlComAVLSTMOM_AVL_FORC_GRD(RT_SG_AVL_FORC_GRD *data)
 *   uint32 E2EPW_Write_SrlComSTEST_ST_EST(RT_SG_ST_EST *data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput2_Per1
 *********************************************************************************************************************/

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_SrlComOutput2_Per1_CP0_CheckpointReached();
  
	if(FrCycleSwitchOddEven_Cnt_G_u08 == 0u)
	{

	  /* Update AVL_PO_EPS Data */
		SrlComOutput2_Tx_AVL_PO_EPS();

	  /* Update AVL_STMOM_DE, AVL_PWR_EL_EPS_COOD and AVL_FORC_GRD */
		SrlComOutput2_Tx_AVL_FORC_GRD_STMOM_DV_ACT();
    
	  /* Update SU_EPS Data */
		SrlComOutput2_Tx_SU_EPS();
    
	  /* Update ST_EST Data */
		SrlComOutput2_Tx_ST_EST();
    
	  /* Update DISP_CC_EPS Data */
		SrlComOutput2_Tx_DISP_CC_EPS();

	}
	else
	{
		/* Update DT_EST Data */
		SrlComOutput2_Tx_DT_EST();
	}

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_SrlComOutput2_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput2_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <DISABLE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_AP_SRLCOMOUTPUT2_APPL_CODE) SrlComOutput2_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput2_Trns1
 *********************************************************************************************************************/

	DisableModeEntry_Cnt_M_lgc = TRUE;   

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMOUTPUT2_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
  * Name:        CalcSWAQualSignal
  * Description: Determines the Qualifier/status signal to be transmitted on the Comm bus for SWA   
  * Inputs:      Application SWA status signal (Authority), and Fault Status 
  * Outputs:     returns value to be transmitted on the Comm bus
  *
***********************************************************************************************************************/
STATIC FUNC(uint8, AP_SRLCOMOUTPUT2_CODE) CalcSWAQualSignal(	VAR(float32, AUTOMATIC) FinHwPosAuth_Uls_T_f32)
{
	VAR(uint8, AUTOMATIC) SWAQualSignal_Cnt_T_u8;
	VAR(uint16, AUTOMATIC) FinHwPosAuth_Uls_T_u8p8;
	VAR(boolean, AUTOMATIC) MtrPosFlt1_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrPosFlt2_Cnt_T_lgc;
	
	/* TODO: See if there are more MSB faults to read */
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PriMSB_SinCosCorr, &MtrPosFlt1_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PriVsSec_SinCosCorr, &MtrPosFlt2_Cnt_T_lgc);
	FinHwPosAuth_Uls_T_u8p8 = FPM_FloatToFixed_m(FinHwPosAuth_Uls_T_f32, u8p8_T);
	
	/* TODO: Process "INVALID" */
	/* TODO: Consider using developer defined enums */
	
	if ((TRUE == MtrPosFlt1_Cnt_T_lgc) || (TRUE == MtrPosFlt2_Cnt_T_lgc))
	{
		SWAQualSignal_Cnt_T_u8 = D_SWAQUALINVTEMP_CNT_U8;
	}
	else if (FinHwPosAuth_Uls_T_u8p8 >= D_MAXCONF_ULS_U8P8)
	{
		SWAQualSignal_Cnt_T_u8 = D_SWAQUALVLDGUAR_CNT_U8;
	}
	else if (FinHwPosAuth_Uls_T_u8p8 >= k_HwPTrvExAuth_Uls_u8p8)
	{
		SWAQualSignal_Cnt_T_u8 = D_SWAQUALVLD_CNT_U8;
	}
	else
	{
		SWAQualSignal_Cnt_T_u8 = D_SWAREPLVALSET_CNT_U8;
	}
	
	return (SWAQualSignal_Cnt_T_u8);
}

/**********************************************************************************************************************
  * Name:        CalcSWASignal
  * Description: Converts the SWA signal from the application scaling/units into the scaling/units for the Comm bus   
  * Inputs:      Application SWA signal and qualifier
  * Outputs:     returns value to be transmitted on the Comm bus
  *
***********************************************************************************************************************/
STATIC FUNC(uint16, AP_SRLCOMOUTPUT2_CODE) CalcSWASignal(	VAR(float32, AUTOMATIC) SWA_HwDeg_T_f32,
															VAR(uint8, AUTOMATIC) SWAQualSignal_Cnt_T_u8)
{
	VAR(uint16, AUTOMATIC) SWASignal_Cnt_T_u16;
	
	if (D_SWAQUALINV_CNT_U8 == SWAQualSignal_Cnt_T_u8)
	{	
		SWASignal_Cnt_T_u16 = D_SWAINVALID_CNT_U16;
	}
	else
	{
		SWA_HwDeg_T_f32 = SWA_HwDeg_T_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
		SWASignal_Cnt_T_u16 = ScaleSignal_u16(SWA_HwDeg_T_f32, D_SWALOLMT_HWDEG_F32, D_SWAHILMT_HWDEG_F32, 
		                                      D_SWASCALE_CNTSPHWDEG_F32, D_SWAOFFSET_HWDEG_F32);
	}
	
	return(SWASignal_Cnt_T_u16);
}

/**********************************************************************************************************************
  * Name:        CalcHwTrqSignal
  * Description: Converts the HwTrq signal from the application scaling/units into the scaling/units for the Comm bus   
  * Inputs:      Application HwTrq signal and qualifier
  * Outputs:     returns value to be transmitted on the Comm bus
  *
***********************************************************************************************************************/
STATIC FUNC(uint16, AP_SRLCOMOUTPUT2_CODE) CalcHwTrqSignal(	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32,
															VAR(uint8, AUTOMATIC) HwTrqQualSignal_Cnt_T_u8)
{
	VAR(uint16, AUTOMATIC) HwTrqSignal_Cnt_T_u16;
	
	if (D_HWTRQQUALINV_CNT_U8 == HwTrqQualSignal_Cnt_T_u8)
	{	
		HwTrqSignal_Cnt_T_u16 = D_HWTRQINVALID_CNT_U16;
	}
	else
	{
		HwTrq_HwNm_T_f32 = HwTrq_HwNm_T_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
		HwTrqSignal_Cnt_T_u16 = ScaleSignal_u16(HwTrq_HwNm_T_f32, D_HWTRQLOLMT_HWNM_F32, D_HWTRQHILMT_HWNM_F32, D_HWTRQSCALE_CNTSPHWNM_F32, D_HWTRQOFFSET_HWNM_F32);
	}
	
	return(HwTrqSignal_Cnt_T_u16);
}

/**********************************************************************************************************************
  * Name:        CalcRckLdSignal
  * Description: Converts the RackLoad signal from the application scaling/units into the scaling/units for the Comm bus   
  * Inputs:      Application RackLoad signal and qualifier
  * Outputs:     returns value to be transmitted on the Comm bus
  *
***********************************************************************************************************************/
STATIC FUNC(AVL_FORC_GRD, AP_SRLCOMOUTPUT2_CODE) CalcRckLdSignal(	VAR(float32, AUTOMATIC) RackLoad_kN_T_f32,
															VAR(QU_AVL_FORC_GRD, AUTOMATIC) RackLoadQual_Cnt_T_enum)
{
	VAR(uint16, AUTOMATIC) RackLoad_Cnt_T_u16;
	
	if (Cx2_Signalwert_ist_gueltig == RackLoadQual_Cnt_T_enum)
	{	
		RackLoad_kN_T_f32 = RackLoad_kN_T_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
		RackLoad_Cnt_T_u16 = ScaleSignal_u16(RackLoad_kN_T_f32, 
		                                     D_RCKLDLOLMT_KN_F32,
		                                     D_RCKLDHILMT_KN_F32,
		                                     D_RCKLDSCALE_CNTSPKN_F32,
		                                     D_RCKLDOFFSET_KN_F32);
	}
	else
	{
		RackLoad_Cnt_T_u16 = D_RCKLDINVALID_CNT_U16;
	}
	
	return((AVL_FORC_GRD)RackLoad_Cnt_T_u16);
}

/**********************************************************************************************************************
  * Name:        CalcEPSFuncQual
  * Description: Calculates EPS Function Qualifier Signal 
  * Inputs:      SystemState_Cnt_T_enum, LimitPercentFiltered_Uls_T_f32, RecFltPres_Cnt_T_lgc, NonRecFltPres_Cnt_T_lgc
  * Outputs:     returns value to be transmitted on the Comm bus
  *
***********************************************************************************************************************/
STATIC FUNC(QU_FN_EST, AP_SRLCOMOUTPUT2_CODE) CalcEPSFuncQual( 	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum, VAR(float32, AUTOMATIC) LimitPercentFiltered_Uls_T_f32,
															  	VAR(boolean, AUTOMATIC) RecFltPres_Cnt_T_lgc, VAR(boolean, AUTOMATIC) NonRecFltPres_Cnt_T_lgc  )
{

	if (RTE_MODE_StaMd_Mode_WARMINIT == SystemState_Cnt_T_enum)
	{
		EPSFuncQual_Cnt_M_enum = Cx80_Initialisierung;
	}
	else if (RTE_MODE_StaMd_Mode_OPERATE == SystemState_Cnt_T_enum)
	{
		if (NonRecFltPres_Cnt_T_lgc == TRUE)
		{
			EPSFuncQual_Cnt_M_enum = Cx60_Funktion_nicht_verfuegbar___Fehler;
		}
		else
		{
			if (LimitPercentFiltered_Uls_T_f32 <= D_ASTLIMITTHRESHOLD_ULS_F32)
			{
				EPSFuncQual_Cnt_M_enum = CxA0_Funktion_verfuegbar___Aktiv__12V_EPS;
			}
			else
			{
					EPSFuncQual_Cnt_M_enum = CxB0_Funktion_temporaer_in_Rueckfallebene;
			}
		}
	}
	else if ((RTE_MODE_StaMd_Mode_DISABLE == SystemState_Cnt_T_enum) ||
			 (RTE_MODE_StaMd_Mode_OFF == SystemState_Cnt_T_enum) ||
			 (DisableModeEntry_Cnt_M_lgc == TRUE))
	{
		DisableModeEntry_Cnt_M_lgc = FALSE;

		if (NonRecFltPres_Cnt_T_lgc == TRUE)
		{
			EPSFuncQual_Cnt_M_enum = Cx60_Funktion_nicht_verfuegbar___Fehler;
		}
		else
		{
			if (RecFltPres_Cnt_T_lgc == TRUE)
			{
				EPSFuncQual_Cnt_M_enum = CxB0_Funktion_temporaer_in_Rueckfallebene;
			}
			else
			{
				EPSFuncQual_Cnt_M_enum = CxE0_Funktion_nicht_verfuegbar___ausgeschaltet;
			}
		}
	}
	else
	{
		/* Retain Last Value (for transition states) */
	}

	return (EPSFuncQual_Cnt_M_enum);
}

/**********************************************************************************************************************
  * Name:        CalcElecPowerSignal
  * Description: Converts the ElecPower signal from the application scaling/units into the scaling/units for the Comm bus   
  * Inputs:      Application ElecPower signal
  * Outputs:     returns value to be transmitted on the Comm bus
  *
***********************************************************************************************************************/
STATIC FUNC(uint8, AP_SRLCOMOUTPUT2_CODE) CalcElecPowerSignal(VAR(float32, AUTOMATIC) ElecPower_Watts_T_f32,
															VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum)
{
	VAR(uint8, AUTOMATIC) ElecPower_Cnt_T_u08;
	
	if (RTE_MODE_StaMd_Mode_OPERATE == SystemState_Cnt_T_enum)
	{
		ElecPower_Cnt_T_u08 = (uint8)ScaleSignal_u16(ElecPower_Watts_T_f32, D_ELECPWRLOLMT_WATTS_F32, D_ELECPWRHILMT_WATTS_F32, 
		                                      D_ELECPWRSCALE_CNTSPKWATTS_F32, D_ELECPWROFFSET_WATTS_F32);
	}
	else
	{
		ElecPower_Cnt_T_u08 = D_INVALIDELECPWR_CNT_U08;
	}
		
	return(ElecPower_Cnt_T_u08);
}
		                                      
/**********************************************************************************************************************
  * Name:        ScaleSignal_u16
  * Description: Scales and limits the input signal based on the passed input parameters  
  * Inputs:      Signal to be scaled, Limits, Scale and offset
  * Outputs:     returns scaled and limited signal
  *
***********************************************************************************************************************/
STATIC FUNC(uint16, AP_SRLCOMOUTPUT2_CODE) ScaleSignal_u16(	VAR(float32, AUTOMATIC) Signal_Uls_T_f32,
															VAR(float32, AUTOMATIC) LoLmt_Uls_T_f32,
															VAR(float32, AUTOMATIC) HiLmt_Uls_T_f32,
															VAR(float32, AUTOMATIC) Scale_Uls_T_f32,
															VAR(float32, AUTOMATIC) Offset_Uls_T_f32)
{
	VAR(uint16, AUTOMATIC) Signal_Cnt_T_u16;
	
	Signal_Uls_T_f32 = Limit_m(Signal_Uls_T_f32, LoLmt_Uls_T_f32, HiLmt_Uls_T_f32);
	Signal_Uls_T_f32 = (Signal_Uls_T_f32 + Offset_Uls_T_f32) * Scale_Uls_T_f32;
	Signal_Cnt_T_u16 = (uint16)Signal_Uls_T_f32;
	
	return(Signal_Cnt_T_u16);
}
/**********************************************************************************************************************
  * Name:        SrlComOutput2_Tx_DT_EST
  * Description: Transmits the DT EST message  
  * Inputs:      None
  * Outputs:     None
  *
***********************************************************************************************************************/
STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE) SrlComOutput2_Tx_DT_EST(void)
{
	VAR(float32, AUTOMATIC)SupplyCur_Amp_T_f32;
	VAR(float32, AUTOMATIC)CustCurrLmt_Amp_T_f32;
	VAR(SG_DT_EST, AUTOMATIC) DtEst_T_Str;
	VAR(New_Coding_49, AUTOMATIC)SupplyCur_Amp_T_u08;
	VAR(uint16, AUTOMATIC)ElapsedTime_mS_T_u16;
  
	(void)Rte_Read_SupplyCur_Amp_f32(&SupplyCur_Amp_T_f32);
	SupplyCur_Amp_T_u08 = (uint8)SupplyCur_Amp_T_f32;

	/* MAX_I_SPEC_EPS value received from the bus */
	(void)Rte_Read_CustCurrLmt_Amp_f32(&CustCurrLmt_Amp_T_f32);

	DtEst_T_Str.AVL_I_ACT_EST = SupplyCur_Amp_T_u08;
	DtEst_T_Str.DT_EST_0x38_0x20 = 0xFFFFFFFFu; /* set unused bits to 1 */
	DtEst_T_Str.DT_EST_0x2C_0x04 = 0xFu; /* set unused bits to 1 */
	DtEst_T_Str.DT_EST_0x78_0x08 = 0xFFu; /* set unused bits to 1 */
	DtEst_T_Str.DT_EST_0x0C_0x20 = 0xFFFFFFFFu; /* set unused bits to 1 */
	DtEst_T_Str.DT_EST_0x58_0x20 = 0xFFFFFFFFu; /* set unused bits to 1 */

	(void)E2EPW_Write_SrlComDTEST_DT_EST(&DtEst_T_Str);

	/* Alternator Diagnostic */
	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CDD_InitialTime_mS_G_u32, &ElapsedTime_mS_T_u16);

	if(ElapsedTime_mS_T_u16 >= D_TWOSECTIME_CNT_U16)
	{
		if((CustCurrLmt_Amp_T_f32 < k_SupplCurThres_Amp_f32) && (SupplyCur_Amp_T_f32 > CustCurrLmt_Amp_T_f32))
		{
			SupplCurInvldTimer_mS_M_u16 = SupplCurInvldTimer_mS_M_u16 + D_TEN_CNT_U16;
			if(SupplCurInvldTimer_mS_M_u16 >= k_SupplCurThresTime_mS_u16)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AB, 0x1U, NTC_STATUS_FAILED);
				SetNtc_DataRngFltMsg_AB_M_lgc = TRUE;
				SupplCurInvldTimer_mS_M_u16 = k_SupplCurThresTime_mS_u16;
				SupplCurWarningTimer_mS_M_u16 = 0x0000u;
			}
			else
			{
				if(SetNtc_DataRngFltMsg_AB_M_lgc == FALSE)
				{
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AB, 0x1U, NTC_STATUS_PASSED);
				}
			}
		}
		else
		{
			if(SetNtc_DataRngFltMsg_AB_M_lgc == FALSE)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AB, 0x1U, NTC_STATUS_PASSED);
				SupplCurInvldTimer_mS_M_u16 = 0x0000u;
			}
			else
			{
				SupplCurWarningTimer_mS_M_u16 = SupplCurWarningTimer_mS_M_u16 + D_TEN_CNT_U16;
				if(SupplCurWarningTimer_mS_M_u16 >= k_GlobalPowerMgmt_Warning_mS_u16)
				{
					SetNtc_DataRngFltMsg_AB_M_lgc = FALSE;
					SupplCurWarningTimer_mS_M_u16 = 0x0000u;
				}
			}
		}
	}

}

/**********************************************************************************************************************
  * Name:        SrlComOutput2_Tx_DISP_CC_EPS
  * Description: Transmits the DISP_CC_EPS message  
  * Inputs:      None
  * Outputs:     None
  *
***********************************************************************************************************************/
STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE) SrlComOutput2_Tx_DISP_CC_EPS(void)
{
	VAR(SG_DISP_CC_EPS, AUTOMATIC) DispCCEps_T_Str;
	VAR(uint8, AUTOMATIC) CDISPCCEPS_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) IndicatorStatus_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ChkCntrlMsgCounter_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) Idx;
  
  
	if(CDD_DispCC_Per_Cnt_G_u08 >= D_DISP_CC_MSG_COUNT)
	{
		/* Reset to zero */
		CDD_DispCC_Per_Cnt_G_u08 = 0u;
		DispCCEps_T_Str.CHL_DISP_CC_EPS = 0x0Cu;

		IndicatorStatus_Cnt_T_u08    = D_INDICATORLAMPOFF_CNT_U08;
		ChkCntrlMsgCounter_Cnt_T_u16 = D_CCMSGCOUNTERMAX_CNT_U16;
    
		for(Idx = 0u; Idx < Dem_IndicatorDesc[0].Number; ++Idx)
		{
			if (DEM_IS_EV_ST_BIT_SET(Dem_IndicatorLink[Idx].EventId, DEM_DTCSTATUSBIT_WIR))
			{
				if(Dem_IndicatorLink[Idx].EventId != THERMAL_LIMIT)
				{
					IndicatorStatus_Cnt_T_u08    = D_INDICATORLAMPON_CNT_U08;
					ChkCntrlMsgCounter_Cnt_T_u16 = D_CCMSGCOUNTER_CNT_U16;
					break;
				}
				else
	  			{
					CDISPCCEPS_Cnt_T_u08 = (uint8)(Rte_IRead_SrlComOutput2_Per1_CDISPCCEPS_Cnt_u08() & D_CDISPCCEPS_MAXMASK_CNT_U08);
					if(CDISPCCEPS_Cnt_T_u08 != D_CDISPCCEPS_MAXMASK_CNT_U08)
					{
						IndicatorStatus_Cnt_T_u08 = D_INDICATORLAMPON_CNT_U08;
    
						if (CDISPCCEPS_Cnt_T_u08 == D_CDISPCCEPS_DEDICATEDMASK_CNT_U08)
						{
							ChkCntrlMsgCounter_Cnt_T_u16 = D_CCMSGCOUNTER_THRMLDEGRADN_CNT_U16;
						}
						else
						{
							ChkCntrlMsgCounter_Cnt_T_u16 = D_CCMSGCOUNTER_CNT_U16;
						}
					}
	  			}
			}
		}
    
	  	DispCCEps_T_Str.NO_CC_EPS = ChkCntrlMsgCounter_Cnt_T_u16; /* Check control message counter */
	  	DispCCEps_T_Str.ST_CC_EPS = IndicatorStatus_Cnt_T_u08; /* Lamp Indication */
	  	DispCCEps_T_Str.ST_IDC_CC_EPS = 0u; /* Hardcode to 0x0 per SER */
	  	DispCCEps_T_Str.TRANF_CC_EPS = 5u; /* Hardcode to 0x5 per SER */
    
	  	CDD_TxDispSendMsg_Cnt_G_lgc = TRUE;
	  	/* Indicate to Output that transmit this message */
	  	(void)E2EPW_Write_SrlComDISPCCEPS_DISP_CC_EPS(&DispCCEps_T_Str);  
	}
	else
	{
		CDD_DispCC_Per_Cnt_G_u08++;
	}
  
}

/**********************************************************************************************************************
  * Name:        SrlComOutput2_Tx_AVL_FORC_GRD_STMOM_DV_ACT
  * Description: Transmits the   
  * Inputs:      None
  * Outputs:     None
  *
***********************************************************************************************************************/
STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE)SrlComOutput2_Tx_AVL_FORC_GRD_STMOM_DV_ACT(void)
{
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(uint16, AUTOMATIC) HwTrqSignal_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) HwTrqQualSignal_Cnt_T_u8;
	VAR(boolean, AUTOMATIC) SrlComHwTrqValid_Cnt_T_lgc;

	VAR(QU_AVL_FORC_GRD, AUTOMATIC) RackLoadQual_Cnt_T_enum;
	VAR(uint16, AUTOMATIC) RackLoad_Cnt_T_u16;
	VAR(float32, AUTOMATIC) RackLoad_kN_T_f32;
	VAR(float32, AUTOMATIC) ElecPower_Watts_T_f32;
	VAR(uint8, AUTOMATIC) ElecPower_Cnt_T_u08;
	VAR(RT_SG_AVL_FORC_GRD, AUTOMATIC) AvlForcGrd_T_Str;
	VAR(RT_SG_AVL_STMOM_DV_ACT, AUTOMATIC) AvlStmomDvAct_T_Str;
  
	VAR(boolean, AUTOMATIC) FlashECCMemFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) FlashCRCMemFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EEPROMDiagPosTrimStr_Cnt_T_lgc;
  
 	VAR(boolean, AUTOMATIC) AVLFORCGRDTxConf_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) AVLSTMOMTxConf_Cnt_T_lgc;

	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();

	(void)Rte_Read_HwTrq_HwNm_f32(&HwTrq_HwNm_T_f32);
	(void)Rte_Read_SrlComHwTrqValid_Cnt_lgc(&SrlComHwTrqValid_Cnt_T_lgc);
  
	AVLFORCGRDTxConf_Cnt_T_lgc = Rte_IRead_SrlComOutput2_Per1_AVLFORCGRDTxConf_Cnt_lgc();
	AVLSTMOMTxConf_Cnt_T_lgc = Rte_IRead_SrlComOutput2_Per1_AVLSTMOMTxConf_Cnt_lgc();

	if(SrlComHwTrqValid_Cnt_T_lgc == TRUE)
	{
		/* Trq signal valid */
		HwTrqQualSignal_Cnt_T_u8 = D_HWTRQQUALVLDGUAR_CNT_U8;
	}
	else
	{
		/* HwTrq CBD Determined Trq signal invalid */
		HwTrqQualSignal_Cnt_T_u8 = D_HWTRQQUALINV_CNT_U8;
	}

	HwTrqSignal_Cnt_T_u16 = CalcHwTrqSignal(HwTrq_HwNm_T_f32, HwTrqQualSignal_Cnt_T_u8);

	(void)Rte_Read_RackLoad_kN_f32(&RackLoad_kN_T_f32);

	/* Add NTC checks */
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_FlashECCMemFlt, &FlashECCMemFlt_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_FlashCRCMemFault, &FlashCRCMemFlt_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_EEPROMDiagPosTrimStr, &EEPROMDiagPosTrimStr_Cnt_T_lgc);

	if ( (SrlComHwTrqValid_Cnt_T_lgc == TRUE) &&
		 (FlashECCMemFlt_Cnt_T_lgc == FALSE) &&
		 (FlashCRCMemFlt_Cnt_T_lgc == FALSE) &&
		 (EEPROMDiagPosTrimStr_Cnt_T_lgc == FALSE) )
	{   
		RackLoadQual_Cnt_T_enum = D_RCKLDQUALVLDGUAR_CNT_U8;	
	}
	else
	{
		RackLoadQual_Cnt_T_enum = D_RCKLDQUALINVTEMP_CNT_U8;
	}

	RackLoad_Cnt_T_u16 = CalcRckLdSignal(RackLoad_kN_T_f32, RackLoadQual_Cnt_T_enum);
	
	/* Update AVL_PWR_EL_EPS_COOD */
	(void)Rte_Read_ElecPower_Watts_f32(&ElecPower_Watts_T_f32);
	
	ElecPower_Cnt_T_u08 = CalcElecPowerSignal(ElecPower_Watts_T_f32, SystemState_Cnt_T_enum);

	if(AVLFORCGRDTxConf_Cnt_T_lgc == FALSE)
	{
		/* Transmit did not occur, send the INIT value */
		AvlForcGrd_T_Str.QU_AVL_FORC_GRD = (uint8)D_INITIALIZATION_CNT_U16;
	}
	else
	{
		AvlForcGrd_T_Str.QU_AVL_FORC_GRD = RackLoadQual_Cnt_T_enum;
	}
	AvlForcGrd_T_Str.AVL_FORC_GRD = RackLoad_Cnt_T_u16;
	AvlForcGrd_T_Str.AVL_PWR_EL_EPS_COOD = ElecPower_Cnt_T_u08;
	AvlForcGrd_T_Str.AVL_FORC_GRD_0x0C_0x04 = 0xFU;	/*set unused bits to 1 */

	if(AVLSTMOMTxConf_Cnt_T_lgc == FALSE)
	{
		/* Transmit did not occur, send the INIT value */
		AvlStmomDvAct_T_Str.QU_AVL_STMOM_DV_ACT = (uint8)D_INITIALIZATION_CNT_U16;
	}
	else
	{
		AvlStmomDvAct_T_Str.QU_AVL_STMOM_DV_ACT = HwTrqQualSignal_Cnt_T_u8;
	}
	AvlStmomDvAct_T_Str.AVL_STMOM_DV_ACT = HwTrqSignal_Cnt_T_u16;
	AvlStmomDvAct_T_Str.AVL_STMOM_DV_ACT_0x0C_0x04 = 0xFU; /* set the unused bits to 1 */

	(void)E2EPW_Write_SrlComAVLSTMOM_AVL_FORC_GRD(&AvlForcGrd_T_Str);
	(void)E2EPW_Write_SrlComAVLSTMOM_AVL_STMOM_DV_ACT(&AvlStmomDvAct_T_Str);
}

/**********************************************************************************************************************
  * Name:        SrlComOutput2_Tx_ST_EST
  * Description: Transmits the ST EST Messsage 
  * Inputs:      None
  * Outputs:     None
***********************************************************************************************************************/
STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE)SrlComOutput2_Tx_ST_EST(void)
{
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(QU_FN_EST, AUTOMATIC) EPSFuncQual_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) NonRecFltPres_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RecFltPres_Cnt_T_lgc;
	VAR(float32, AUTOMATIC)	LimitPercentFiltered_Uls_T_f32;
	VAR(boolean, AUTOMATIC) TJACoding_Cnt_T_lgc;
	
	VAR(RT_SG_ST_EST, AUTOMATIC) StEst_T_Str;
	VAR(TJAStateType, AUTOMATIC) TJAState_Cnt_T_enum;

	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	NonRecFltPres_Cnt_T_lgc = Rte_IRead_SrlComOutput2_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc();
	RecFltPres_Cnt_T_lgc = Rte_IRead_SrlComOutput2_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc();
	LimitPercentFiltered_Uls_T_f32 = Rte_IRead_SrlComOutput2_Per1_LimitPercentFiltered_Uls_f32();

	EPSFuncQual_Cnt_T_enum = CalcEPSFuncQual(SystemState_Cnt_T_enum, LimitPercentFiltered_Uls_T_f32, RecFltPres_Cnt_T_lgc, NonRecFltPres_Cnt_T_lgc);
	
	StEst_T_Str.ST_EST_0x10_0x08 = 0xFFu; /* set unused bits to 1 */
	StEst_T_Str.QU_FN_EST = EPSFuncQual_Cnt_T_enum;
	
	if(TRUE == Rte_IRead_SrlComOutput2_Per1_CEVIIF_Cnt_lgc())
	{
		(void)Rte_Read_HaptcFbSt_Cnt_u08(&StEst_T_Str.QU_FN_VIB_EPS);
	}
	else
	{
		StEst_T_Str.QU_FN_VIB_EPS = 0xFu;
	}


	/* Update Driving Dynamics State */
	if (( FALSE == Rte_IRead_SrlComOutput2_Per1_CFACTORIF_Cnt_lgc() ) ||
		( FALSE == Rte_IRead_SrlComOutput2_Per1_CHWTORQUEIF_Cnt_lgc() ) ||
		( FALSE == Rte_IRead_SrlComOutput2_Per1_CMTTORQUEIF_Cnt_lgc() )
	   )
	{
		(void)Rte_Read_DrvDynState_Cnt_u08(&StEst_T_Str.QU_SER_STMOM_DV_ACT);
		TJACoding_Cnt_T_lgc = Rte_IRead_SrlComOutput2_Per1_CADASMSG_Cnt_lgc();
		(void)Rte_Read_TJAState_Cnt_enum(&TJAState_Cnt_T_enum);

		switch(StEst_T_Str.QU_SER_STMOM_DV_ACT)
		{
			case Cx20_Schnittstelle_verfuegbar___funktionsbereit:
				/* DrvDyn is available */
				if(TJACoding_Cnt_T_lgc == TRUE)
				{
					/* TJA is coded on, check for inactive or active */
					if ( (TJAState_Cnt_T_enum == TJA_Inactive) || (TJAState_Cnt_T_enum == TJA_Active) )
					{
						StEst_T_Str.QU_SER_STMOM_DV_ACT = D_DRVDYNAVAL_TJAACTV_CNT_U16;
					}
				}
			break;
			case Cx21_Schnittstelle_aktiv:
				if(TJACoding_Cnt_T_lgc == TRUE)
				{
					/* TJA is coded on, check for error */
					if ( (TJAState_Cnt_T_enum == TJA_Inactive) || (TJAState_Cnt_T_enum == TJA_Active) )
					{
						StEst_T_Str.QU_SER_STMOM_DV_ACT = D_DRVDYNACTV_TJAACTV_CNT_U16;
					}
				}
			break;
			default:
				/* Do nothing */
			break;
		}
	}
	else
	{
		StEst_T_Str.QU_SER_STMOM_DV_ACT = D_DRVDYNSTATEOVRRD_CNT_U08;
	}

	/* Handle Tx rate of ST_EST signal */
	/* When E2E_Write is updated a runnable is triggered in SrlComOutput and the data is
	 * immediately transmitted by COM. This design ensures that the alive counter remains
	 * in sequence with the ST_EST event driven transmit rate	 */
    if ( (StEst_M_Str.QU_SER_STMOM_DV_ACT != StEst_T_Str.QU_SER_STMOM_DV_ACT) || 
       (StEst_M_Str.QU_FN_EST != StEst_T_Str.QU_FN_EST) || (StEstInitialTx_Cnt_M_lgc == FALSE) )
    {   
    
        StEst_M_Str.QU_SER_STMOM_DV_ACT = StEst_T_Str.QU_SER_STMOM_DV_ACT;
        StEst_M_Str.QU_FN_EST = StEst_T_Str.QU_FN_EST;

		StEstInitialTx_Cnt_M_lgc = TRUE;

		StEstFastTxCounter_Cnt_M_u08 = 0u;
		StEstTxRepetitions_Cnt_M_u08 = D_TXREPETITIONS_CNT_U08;
	}

	if ( (StEstFastTxCounter_Cnt_M_u08 >= D_STESTFASTTXCNT_CNT_U08) && (StEstTxRepetitions_Cnt_M_u08 > 0U) )
	{
      /* Reset Counter */
      StEstFastTxCounter_Cnt_M_u08 = 0U;
      StEstTxRepetitions_Cnt_M_u08--;
			/* Transmit ST_EST message */
      (void)E2EPW_Write_SrlComSTEST_ST_EST(&StEst_T_Str); 

		  CDD_TxSTEPSSendMSg_Cnt_G_lgc = TRUE;
    }
    else if ( (StEstTxCounter_Cnt_M_u16 >= D_STESTSLOWTXCNT_CNT_U08) && (StEstTxRepetitions_Cnt_M_u08 == 0U) )
    {
      StEstTxCounter_Cnt_M_u16 = 0U;
   
      /* Send message */
      (void)E2EPW_Write_SrlComSTEST_ST_EST(&StEst_T_Str);
      CDD_TxSTEPSSendMSg_Cnt_G_lgc = TRUE;
    }
    else
    {
      StEstFastTxCounter_Cnt_M_u08++;
      StEstTxCounter_Cnt_M_u16++;
    }
}

/**********************************************************************************************************************
  * Name:        SrlComOutput2_Tx_SU_EPS
  * Description: Transmits the SU_EPS Messsage 
  * Inputs:      None
  * Outputs:     None
***********************************************************************************************************************/
STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE)SrlComOutput2_Tx_SU_EPS(void)
{
	VAR(float32, AUTOMATIC) EPSPinionAngle_Deg_T_f32;
	VAR(uint16, AUTOMATIC)TopStrEps_T_u16;
	VAR(RT_SG_SU_EPS, AUTOMATIC) SuEps_T_Str;
  	/* Update content */
	EPSPinionAngle_Deg_T_f32 = k_GearRatio_Uls_f32 * D_EPSROTORREV_DEG_F32;
	TopStrEps_T_u16 = ScaleSignal_u16( EPSPinionAngle_Deg_T_f32, D_GEARPINANGLELOLMT_DEG_F32, D_GEARPINANGLEHILMT_DEG_F32,
					                                      D_GEARRATIOSCALE_ULS_F32, D_GEARPINANGLEOFFSET_DEG_F32);
	if((TopStrEps_T_u16 == D_TOTSTREPSVLDVALUE1_CNT_U08) || (TopStrEps_T_u16 == D_TOTSTREPSVLDVALUE2_CNT_U08))
	{
			SuEps_T_Str.TOT_STR_EPS = TopStrEps_T_u16;
	}
	SuEps_T_Str.UN_TOT_STR_EPS = 0U; 	/* 0 = degrees */

	SuEps_T_Str.SU_EPS_0x0E_0x20 = 0xFFFFFFFFu; /* set unused bits to 1 */
	SuEps_T_Str.SU_EPS_0x2E_0x06 = 0x3Fu; /* set unused bits to 1 */

	/* Sending Logic */
	if (CDD_TxSUEPS_Cnt_G_lgc == TRUE)
	{
		SuEpsBurstTrigger_Cnt_M_u08 = D_SUEPSBURSTCNT_CNT_U08;
		SuEpsBurstCntr_Cnt_M_u08 = 0U;
		CDD_TxSUEPS_Cnt_G_lgc = FALSE;
	}

	if ( (SuEpsBurstCntr_Cnt_M_u08 >= D_SUEPSBURSTCNTLMT_CNT_U08) && (SuEpsBurstTrigger_Cnt_M_u08 > 0u) )
	{
		/* Reset burst counter and update trigger condition  */
		SuEpsBurstCntr_Cnt_M_u08 = 0U;
		SuEpsBurstTrigger_Cnt_M_u08--;

		/* Send message */
		(void)E2EPW_Write_SrlComSUEPS_SU_EPS(&SuEps_T_Str);
		CDD_TxSUEPSSendMsg_Cnt_G_lgc = TRUE;
	}
	else if ((SuEpsPerCntr_Cnt_M_u16 >= D_SUEPSPERCNTLMT_CNT_U16) && (SuEpsBurstTrigger_Cnt_M_u08 == 0u))
	{
		/* Reset the periodic counter back to 0 */
		SuEpsPerCntr_Cnt_M_u16 = 0U;

		/* Send Message */
		(void)E2EPW_Write_SrlComSUEPS_SU_EPS(&SuEps_T_Str);
		CDD_TxSUEPSSendMsg_Cnt_G_lgc = TRUE;
	}
	else
	{
		SuEpsPerCntr_Cnt_M_u16++;
		SuEpsBurstCntr_Cnt_M_u08++; /* Counter will roll over, but in a burst event, it is cleared to 0 */
	}

}

/**********************************************************************************************************************
  * Name:        SrlComOutput2_Tx_AVL_PO_EPS
  * Description: Transmits the AVL_PO_EPS Messsage 
  * Inputs:      None
  * Outputs:     None
***********************************************************************************************************************/
STATIC FUNC(void, AP_SRLCOMOUTPUT2_CODE)SrlComOutput2_Tx_AVL_PO_EPS(void)
{
	VAR(float32, AUTOMATIC) FinHwPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) FinHwPosAuth_Uls_T_f32;
	VAR(uint8, AUTOMATIC) SWAQualSignal_Cnt_T_u8;
	VAR(uint16, AUTOMATIC) SWASignal_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) RacktoVehCntrOffset_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) RevOffsetState_Cnt_T_u08;
	VAR(RT_SG_AVL_PO_EPS, AUTOMATIC) AvlPoEpsData_T_Str;
  
	(void)Rte_Read_FinHwPosAuth_Uls_f32(&FinHwPosAuth_Uls_T_f32);
	(void)Rte_Read_FinHwPos_HwDeg_f32(&FinHwPos_HwDeg_T_f32);
	RacktoVehCntrOffset_Cnt_T_u16 = Rte_IRead_SrlComOutput2_Per1_RacktoVehCntrOffset_Cnt_u16();
	RevOffsetState_Cnt_T_u08 = Rte_IRead_SrlComOutput2_Per1_RevOffsetState_Cnt_u08();
	
	SWAQualSignal_Cnt_T_u8 = CalcSWAQualSignal(FinHwPosAuth_Uls_T_f32);
	SWASignal_Cnt_T_u16 = CalcSWASignal(FinHwPos_HwDeg_T_f32, SWAQualSignal_Cnt_T_u8);
	
	AvlPoEpsData_T_Str.QU_AVL_PO_EPS = RevOffsetState_Cnt_T_u08;
	AvlPoEpsData_T_Str.AVL_PO_EPS = SWASignal_Cnt_T_u16;
	AvlPoEpsData_T_Str.OFFS_GRD_MID_EPS = RacktoVehCntrOffset_Cnt_T_u16;	
	AvlPoEpsData_T_Str.UN_PO_EPS = 0U;        /* Select units of degrees */
	
	AvlPoEpsData_T_Str.AVL_PO_IDX_EPS = 0xFFFFU;
	AvlPoEpsData_T_Str.IDX_TORQ_SEN = 3U;

	(void)E2EPW_Write_SrlComAVLPOEPS_AVL_PO_EPS(&AvlPoEpsData_T_Str);
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
