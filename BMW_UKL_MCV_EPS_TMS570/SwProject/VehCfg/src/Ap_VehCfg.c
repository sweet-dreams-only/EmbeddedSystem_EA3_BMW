/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_VehCfg.c
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/VehCfg/autosar
 *     SW-C Type:  Ap_VehCfg
 *  Generated at:  Fri Apr 28 13:56:26 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_VehCfg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr  6 11:45:23 2011
 * %version:          EA3#50 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Tue Dec 10 11:14:14 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/06/11   1       JJW       Initial Template																3963
 * 04/06/11   2       BDO       Set VehConfig feature enable outputs based on coding block data set 1			3963
 * 04/11/11   3       BDO       Modify reading of the pointer to blockData										3963
 * 04/13/11   4       JJW       Cross Check Diag Support Added
 * 06/01/11   5       JJW       Template update for new outputs and removal of RTE output for CrossChk
 * 06/04/11   6       LWW       Added new coding switches
 * 08/03/11   7       JJW       BAC3.0 Integration changes for new coding module and generator
 *            8       YAY       Updates to support TurnsCounter
 * 08/26/11   9       BDO       BAC3.0 Integration: De-reference error pointer in CbkPreConditions_Check()
 * 10/29/11   10      LWW       Anomaly fixes
 * 1/10/12    10.1.1  SMW       Fixed Anomaly 2781 - vehicle to rack center offset      
 * 11/30/11   12      KJS		Updates for FDD 05C																3594
 * 12/02/11   13      JJW       Changed design to utilize the RTE_PTR2ARRAYBASETYPE_PASSING configuration to
 *                               allow proper compilation with the writeblock api.  Due to this change the access to 
 *                               the coding data blocks had to be changed.
 * 01/07/12   14      JJW       Removed invald and conflicting signal RacktoVehCntrOffset_Cnt_T_U16 (changed to u16)
 * 01/10/12   15      JJW       fix of plarity anomaly for rack center
 * 03/12/12   16      JJW       Change TcTrasport S/R port to EnergyModeState for integration of TurnsCounter FDD20C_003.3
 * 04/25/12   17      JJW       Coding Data Block 2 support for enable signals in SER 08: C_FACTOR_IF, C_HW_TORQUE_IF, 
 *								C_MT_TORQUE_IF, C_HW_ANGLE_IF. Remove S/R port RxOvrrdCodingFn because its funcationality is
 *                              replaced by the newly added enable signals.
 * 04/25/12   18      SMW       Fixed the D_DATASET2BYTE0RSVD_CNT_U8 mask to be 0x0F to allow writes to the upper nibble
 * 04/26/12   19      SMW       Updated CbkBlockValid_Check function to return EOK if block is not data Nxtr is managing
 * 06/08/12   20      BDO       New coding enable switches per SER 9C
 * 06/20/12	  21	  KJS		Removed Rack to Veh Center Offset calculation in Per1. Per1 now just handles energy mode.
 * 09/07/12	  22	  KJS		Removed RTE_PTR2ARRAYBASETYPE_PASSING requirement, added de-reference back into pointer calls.
 * 09/25/12   23	  KJS		Anomaly 3810 correction for blockData references
 * 09/29/12   24	  KJS		Created RTE_PTR2ARRAYBASETYPE_PASSING requiremnt again for tuning select values from NvM
 * 09/30/12   25	  KJS		Corrected errors in updating NvM for tuning select. 
              25.1.1  KJS		Corrected anomaly 3869. 
			  26	  JJW		Removed CrossCheck include 
 * 10/16/12	  27	  KJS		Merged paths of 25.1.1 and 26.
 * 10/25/12   25.1.2  KJS		Updates for MSA and anomaly 3954 correction.
 * 10/25/12   25.1.3  BDO		Changed D_DATASET1BYTE0RSVD_CNT_U8 reserve bit mask to allow MSA bit 3. Anomaly 3985
 * 11/07/12	  28	  KJS		Merged i350 and i390 paths. Includes 25.1.2, 25.1.3 and up to version 27 of i390 path.
 * 03/04/13	  29	  KJS		QAC corrections and SER Updates.
 * 04/06/13	  31	  KJS		Anomaly 4762 corrections. 
 * 04/06/13	  32	  KJS		Implementation of changes from PSR 494.
 * 04/12/13	  33	  KJS		Anomaly 4709 corrections for energy mode										CR7877
 * 04/12/13	  34	  KJS		Changes to support variant tuning selection
 * 04/18/13	  35	  KJS		Anomaly 4806 correction. 
 * 05/30/13	  36	  KJS		XCP Disable Support
 * 07/11/13	  37	  KJS		Added support for tune-on-the-fly.
 * 			  37.1.1  KJS		Added support for TJA
 * 			  37.1.2  KJS		Correction for anomaly 5849
 * 10/14/13	  39	  KJS		Added NTC 1F3 to detect if HWAP is not found in calibration sets (ICR 4332)
 * 10/23/13	  40	  KJS		Added NTC 1F3 support in Per1 Anomaly 5912
 * 10/29/13	  41	  KJS		Merge of 17.xx.xx and 18.xx.xx version of VehCfg
 * 11/20/13	  43	  KJS		Added support for 13C SER for HWAP and additional data checks for new SVK data migration.
 * 11/22/13	  44	  KJS		Corrections for HWAP selection and data migration for SVK. Anomalies 6085, 6087
 * 12/10/13	  46	  KJS		Removal of code that is no longer needed from 19.04.00 release. This moved the HWAP lookup
 *								to the bootloader, so this is a clean up change to remove the function that is no longer needed. 
 * 08/29/14	  47	  KJS		Anomaly 6773 correction for missing or invalid VIN and VehCfg coding errors
 * 03/24/15	  47.1.1  ABS		CR 13145 (EA3#250) Invalid HWAP Handling
 * 03/24/15	  47.1.2  ABS		CR 13144 (EA3#256) EEPROM to FEE Fault
 * 04/02/15	  47.1.3  ABS		Corrected masking for invalid HWAP
 * 06/11/15	  47.1.4  ABS		New CC-ID for Thermal Degradation CTC 0x4823FA
 * 06/25/15	  47.1.5  ABS       Incorrect coding bits extracted for DISPCCDRDY02 msg
 * 07/30/15   47.1.6  KJS       Applied correction defined in anomaly EA3#2206                                    EA3#2210
 * 03/09/16   48      KJS       Applied changes for F40                                                           EA3#6554
 * 04/28/17   50	  ABS		Anomaly correction for TuningID selection										  EA3#14748
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

  QU_SER_WSTA_EST_FTAX
    Service-Qualifier zur Lenkradvibration

 *********************************************************************************************************************/

#include "Rte_Ap_VehCfg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_VehCfg.h"
#include "Coding.h"
#include "GlobalMacro.h"
#include "Omc.h"
#include "CDD_Data.h"
#include "CalConstants.h"
#include "XcpProf.h"
#include "ApplCallBacks.h" /* Required for Deprecated data reads */


/* Rack to Vehicle Center Offset */
#define D_R2VRES_HWDEGPCNT_F32			0.04395F
#define D_R2VMSGOFF_CNT_U16				2047U
#define D_R2VMIN_HWDEG_F32				(-89.9656F)
#define D_R2VMAX_HWDEG_F32				89.9656F

/* Reserved Bits Masks */
#define D_DATASET1BYTE0RSVD_CNT_U8			0x00U
#define D_DATASET2BYTE0RSVD_CNT_U8			0x00U
#define D_DATASET3BYTE0RSVD_CNT_U8			0xFFU   /* byte 0 is reserved */

/* DataSet 1 Byte 0 Bits */
#define D_CHWACORRECTION_CNT_U8       		0x80U
#define D_CERRMVOLTFALLBACK_CNT_U8       	0x40U
#define D_CEPSPWRMAX_CNT_U8       			0x20U
#define D_CVEHSPDCURLIMITER_CNT_U8       	0x10U
#define D_CASSISTMSA_CNT_U8					0x08U
#define D_CDISPCCDRDY02_CNT_U8				0x06U
#define D_TXDEBUGMSGEN_CNT_U8       		0x01U

/* DataSet 2 Byte 0 Bits */
#define D_CFACTORIFMSK_CNT_U8      			0x80U
#define D_CHWTORQUEIFMSK_CNT_U8     		0x40U
#define D_CMTTORQUEIFMSK_CNT_U8				0x20U
#define D_CHWANGLEIFMSK_CNT_U8				0x10U
#define D_CEFANMSG_CNT_U8					0x08U
#define D_CDRVDYNMSG_CNT_U8					0x04U
#define D_CADASIF_CNT_U8					0x02U
#define D_CEVIIF_CNT_U8						0x01U

/* DataSet 3 Byte 4 Bits */
#define D_CFRCOMPIF_CNT_U8					0x80U
#define D_CPLCOMPIF_CNT_U8					0x40U
#define D_CSELRETURN_CNT_U8					0x20U

/* VehCfg_Per1 */
#define D_SWAQUALVLDGUAR_CNT_U8				0x01U
#define D_SWAQUALVLD_CNT_U8					0x02U

/* Tuning Select */
#define D_TUNINGSELBASESVT_CNT_U8		0x03U
#define D_TUNINGSELSPORT_CNT_U8			0x02U

#define D_PARKASSISTCALID_CNT_U16		0xAAAAU

#define D_NUMOFPERSBYCODING_CNT_U8		3U

#define D_HWAPDESCINDEX_CNT_U8			1U
#define D_HWAPSGBMNUM_CNT_U8			1U
#define D_HWAPSGBMNUMLEN_CNT_U8			4U

#define D_SVKVERSION_CNT_U8 0U
#define D_SVK_SGBMID_HWAP_PROCESSCLASS_CNT_U8	25U
#define D_SVK_SGBMID_HWAP_MAJORVER_CNT_U8		30U
#define D_SVK_SGBMID_HWAP_MINORVER_CNT_U8		31U
#define D_SVK_SGBMID_HWAP_PATCHVER_CNT_U8		32U

#define D_HWAPINVALID_CNT_U32			0xFFFFFFFFU
#define D_EEPROM_FEE_COPYERR_FLAG1		0x5A5Au
#define D_EEPROM_FEE_COPYERR_FLAG2		0x9595u


typedef enum {
	SGBM_MAJORID_101 = 101u,
	SGBM_MAJORID_102 = 102u,
	SGBM_MAJORID_104 = 104u,
	SGBM_MAJORID_105 = 105u
} SGBM_MajorId_T;

typedef enum {
	SGBM_MINORID_x0x = 0U,
	SGBM_MINORID_x1x = 1U,
	SGBM_MINORID_x2x = 2U,
	SGBM_MINORID_x3x = 3U
} SGBM_MinorId_T;

#define D_SGBM_MINORDIVS_ULS_F32	10.0F
#define D_SGBM_MINORMODDIVS_ULS_U8	10U

typedef enum {
	HWAP_VARIANT_A	= 0x2B6DUL,
	HWAP_VARIANT_E	= 0x2B73UL,
	HWAP_VARIANT_Ah	= 0x2B6EUL,
	HWAP_VARIANT_I	= 0x2B7BUL,
	HWAP_VARIANT_H	= 0x2B79UL,
	HWAP_VARIANT_Fh	= 0x2B75UL,
	HWAP_VARIANT_C	= 0x2B70UL,
	HWAP_VARIANT_F	= 0x2B74UL,
	HWAP_VARIANT_B	= 0x2B6FUL
} HWAP_VariantLUTBL_T;

#define D_1893_SGBMMAJORIDX_CNT_U8	54U
#define D_1893_SGBMMINORIDX_CNT_U8	55U


#define VEHCFG_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC) StrdTuningSelSet_Cnt_M_u16;
STATIC VAR(uint16, AUTOMATIC) StrdTuningSelPers_Cnt_M_u16;
STATIC VAR(uint16, AUTOMATIC) TuningSelSet_Cnt_M_u16;
#define VEHCFG_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define VEHCFG_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AUTOMATIC) CodingTunSelBase_Cnt_M_u8;
STATIC VAR(uint8, AUTOMATIC) CodingTunSelSVT_Cnt_M_u8;
STATIC VAR(uint8, AUTOMATIC) CodingTunSelSport_Cnt_M_u8;
VAR(uint8, AP_VEHCFG_VAR) VehCfg_SvkSysSupp[D_SVKSIZE_CNT_U8]; /* Array is populated by NvM read-all and cannot be static */
VAR(uint8, AP_VEHCFG_VAR) VehCfg_SvkPlant[D_SVKSIZE_CNT_U8]; /* Array is populated by NvM read-all and cannot be static */
#define VEHCFG_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define VEHCFG_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) CodingDrvDyn_Uls_M_lgc;
STATIC VAR(boolean, AUTOMATIC) CodingDebugFrame_Uls_M_lgc;
STATIC VAR(boolean, AUTOMATIC) CodingFrictionComp_Uls_M_lgc;
STATIC VAR(boolean, AUTOMATIC) CodingPullComp_Uls_M_lgc;
#define VEHCFG_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


STATIC FUNC(boolean, AP_VEHCFG_CODE) SVKSupplierChk(P2CONST(uint8, AUTOMATIC, AUTOMATIC) Data_Cnt_T_u8);
STATIC FUNC(void, AP_VEHCFG_CODE) LookupTunVariant(VAR(uint32, AUTOMATIC) HWAPHwDescData_Cnt_T_u32, P2VAR(uint16, AUTOMATIC, AUTOMATIC) TuningSelect_Cnt_T_u16);

STATIC INLINE FUNC(boolean, AP_VEHCFG_CODE) ReadBit_u8(	VAR(uint8, AUTOMATIC) Data,
															VAR(uint8, AUTOMATIC) BitMask);

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
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Coding_BlockIdType: Enumeration of integer in interval [0...5] with enumerators
 *   CODING_ID_AREA_CODINGDATASET1 (0U)
 *   CODING_ID_AREA_CODINGDATASET2 (1U)
 *   CODING_ID_AREA_CODINGDATASET3 (2U)
 *   CODING_ID_AREA_CAFID (3U)
 *   CODING_ID_AREA_SIGNATURE (4U)
 * Coding_DataStatusType: Enumeration of integer in interval [0...2] with enumerators
 *   CODING_DATA_UNDEFINED (0U)
 *   CODING_DATA_NOT_CODED (1U)
 *   CODING_DATA_CODED (2U)
 * Coding_ErrorType: Enumeration of integer in interval [0...3] with enumerators
 *   CODING_E_OK (0U)
 *   CODING_E_NOT_OK (1U)
 *   CODING_E_BUSY (2U)
 *   CODING_E_PENDING (3U)
 * Coding_ProtectionType: Enumeration of integer in interval [0...1] with enumerators
 *   CODING_WRITE_PROTECTION_OFF (0U)
 *   CODING_WRITE_PROTECTION_ON (1U)
 * EnergyModeStateType: Enumeration of integer in interval [0...3] with enumerators
 *   NORMAL (0U)
 *   PRODUCTION (1U)
 *   TRANSPORTATION (2U)
 *   FLASH (3U)
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0U)
 *   ManufacturingMode (1U)
 *   EngineeringMode (2U)
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
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_LimpHomeIgnitionCounter (161U)
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
 *   NTC_Num_MissingMsg_AL (489U)
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
 * New_Coding_79: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Ultrahart (1U)
 *   Cx2_Sportlich_ausgewogen (2U)
 *   Cx3_Ausgewogen (3U)
 *   Cx4_Weich (4U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
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
 *
 * Array Types:
 * ============
 * Coding_BlockDataType: Array with 132 element(s) of type UInt8
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
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
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt8: D_ONE_CNT_U8 = 1U
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   TuningSelectParam *Rte_Pim_PrevVldTuningSel(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_VEHCFG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkBlockValid_Check
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Check> of PortPrototype <CbkBlockValid>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void CbkBlockValid_Check(Coding_BlockIdType blockId, const UInt8 *blockData, UInt8 blockSize, Coding_ErrorType *error)
#else
 *   void CbkBlockValid_Check(Coding_BlockIdType blockId, const Coding_BlockDataType *blockData, UInt8 blockSize, Coding_ErrorType *error)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlockValid_Check(Coding_BlockIdType blockId, P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error)
#else
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlockValid_Check(Coding_BlockIdType blockId, P2CONST(Coding_BlockDataType, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CbkBlockValid_Check
 *********************************************************************************************************************/

	 /* QAC Comment: Suppressing message 492 for this section of code. This is due to the pointers being passed
	  * to the function require the violation to work properly. See anomaly 3810. */

	*error = CODING_E_OK;
 
   	switch ( blockId )
   	{
    	case CODING_ID_AREA_CODINGDATASET1:
    		/* TODO: Investigate simplifying reading of blockdata */    		
        	if (( blockData[0] & D_DATASET1BYTE0RSVD_CNT_U8) != 0U) /* PRQA S 492 */
         	{
            	*error = CODING_E_NOT_OK;
         	}
         break;
         
      	case CODING_ID_AREA_CODINGDATASET2:
      		/* TODO: Investigate simplifying reading of blockdata */     		
         	if (( blockData[0] & D_DATASET2BYTE0RSVD_CNT_U8) != 0U) /* PRQA S 492 */
         	{
            	*error = CODING_E_NOT_OK;
         	}
         break;
         
    	case CODING_ID_AREA_CODINGDATASET3:
          	/* TODO: Investigate simplifying reading of blockdata */
            if (( blockData[0] & D_DATASET3BYTE0RSVD_CNT_U8) != 0U) /* PRQA S 492 */
            {
              	*error = CODING_E_NOT_OK;
            }
         break;

       default:
	            *error = CODING_E_OK;
         break;
   }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkBlock_Receive
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Receive> of PortPrototype <CbkBlock>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CADASIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CASSISTMSA_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CBATCURLIMITCURRENT_Amp_f32(Float data)
 *   Std_ReturnType Rte_Write_CDISPCCDRDY02_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CDRVDYNMSG_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CEFANMSG_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CEPSPWRMAX_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CERRMVOLTFALLBACK_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CEVIIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CFACTORIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CFRCOMPIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CHWACORRECTION_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CHWANGLEIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CHWTORQUEIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CMTTORQUEIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CPLCOMPIF_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CSELRETURN_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CSELTUNINGBASE_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CSELTUNINGSPORT_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CSELTUNINGSVT_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CVEHSPDCURLIMITCURRENT_Amp_f32(Float data)
 *   Std_ReturnType Rte_Write_CVEHSPDCURLIMITER_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CVEHSPDCURLIMITSPEED_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_TxDebugMsgEn_Cnt_lgc(Boolean data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void CbkBlock_Receive(Coding_BlockIdType blockId, const UInt8 *blockData, UInt8 blockSize)
#else
 *   void CbkBlock_Receive(Coding_BlockIdType blockId, const Coding_BlockDataType *blockData, UInt8 blockSize)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlock_Receive(Coding_BlockIdType blockId, P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize)
#else
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlock_Receive(Coding_BlockIdType blockId, P2CONST(Coding_BlockDataType, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CbkBlock_Receive
 *********************************************************************************************************************/

	/* QAC Comment: Suppressing message 492 for this section of code. This is due to the pointers being passed
	 * to the function require the violation to work properly. See anomaly 3810. */

	switch(blockId){
		case CODING_ID_AREA_CODINGDATASET1:

			(void)Rte_Write_TxDebugMsgEn_Cnt_lgc((ReadBit_u8( blockData[0], D_TXDEBUGMSGEN_CNT_U8))); /* PRQA S 492 */
			CodingDebugFrame_Uls_M_lgc = (ReadBit_u8( blockData[0], D_TXDEBUGMSGEN_CNT_U8)); /* PRQA S 492 */
			(void)Rte_Write_CHWACORRECTION_Cnt_lgc((ReadBit_u8( blockData[0], D_CHWACORRECTION_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CERRMVOLTFALLBACK_Cnt_lgc((ReadBit_u8( blockData[0], D_CERRMVOLTFALLBACK_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CEPSPWRMAX_Cnt_lgc((ReadBit_u8( blockData[0], D_CEPSPWRMAX_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CASSISTMSA_Cnt_lgc((ReadBit_u8( blockData[0], D_CASSISTMSA_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CDISPCCDRDY02_Cnt_u08((blockData[0] & D_CDISPCCDRDY02_CNT_U8) >> 0x01);  /* PRQA S 492 */

			(void)Rte_Write_CVEHSPDCURLIMITER_Cnt_lgc((ReadBit_u8( blockData[0], D_CVEHSPDCURLIMITER_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CVEHSPDCURLIMITSPEED_Kph_f32((float32)( blockData[1] )); /* PRQA S 492 */

			(void)Rte_Write_CVEHSPDCURLIMITCURRENT_Amp_f32((float32)( blockData[2] )); /* PRQA S 492 */
			(void)Rte_Write_CBATCURLIMITCURRENT_Amp_f32((float32)( blockData[3] )); /* PRQA S 492 */
			break;

		case CODING_ID_AREA_CODINGDATASET2:

			(void)Rte_Write_CFACTORIF_Cnt_lgc((ReadBit_u8( blockData[0], D_CFACTORIFMSK_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CHWTORQUEIF_Cnt_lgc((ReadBit_u8( blockData[0], D_CHWTORQUEIFMSK_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CMTTORQUEIF_Cnt_lgc((ReadBit_u8( blockData[0], D_CMTTORQUEIFMSK_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CHWANGLEIF_Cnt_lgc((ReadBit_u8( blockData[0], D_CHWANGLEIFMSK_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CEFANMSG_Cnt_lgc((ReadBit_u8( blockData[0], D_CEFANMSG_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CDRVDYNMSG_Cnt_lgc((ReadBit_u8( blockData[0], D_CDRVDYNMSG_CNT_U8))); /* PRQA S 492 */
			CodingDrvDyn_Uls_M_lgc = (ReadBit_u8( blockData[0], D_CDRVDYNMSG_CNT_U8)); /* PRQA S 492 */
			(void)Rte_Write_CADASIF_Cnt_lgc((ReadBit_u8( blockData[0], D_CADASIF_CNT_U8))); /* PRQA S 492 */
			(void)Rte_Write_CEVIIF_Cnt_lgc((ReadBit_u8( blockData[0], D_CEVIIF_CNT_U8))); /* PRQA S 492 */

			(void)Rte_Write_CSELTUNINGBASE_Cnt_u08( blockData[1]); /* PRQA S 492 */
			CodingTunSelBase_Cnt_M_u8 = blockData[1]; /* PRQA S 492 */
			(void)Rte_Write_CSELTUNINGSVT_Cnt_u08( blockData[2]); /* PRQA S 492 */
			CodingTunSelSVT_Cnt_M_u8 = blockData[2]; /* PRQA S 492 */
			(void)Rte_Write_CSELTUNINGSPORT_Cnt_u08( blockData[3]); /* PRQA S 492 */
 			CodingTunSelSport_Cnt_M_u8 = blockData[3]; /* PRQA S 492 */
			break;

		case CODING_ID_AREA_CODINGDATASET3:

			(void)Rte_Write_CFRCOMPIF_Cnt_lgc((ReadBit_u8( blockData[3], D_CFRCOMPIF_CNT_U8))); /* PRQA S 492 */
			CodingFrictionComp_Uls_M_lgc = (ReadBit_u8( blockData[3], D_CFRCOMPIF_CNT_U8)); /* PRQA S 492 */
			(void)Rte_Write_CPLCOMPIF_Cnt_lgc((ReadBit_u8( blockData[3], D_CPLCOMPIF_CNT_U8))); /* PRQA S 492 */
			CodingPullComp_Uls_M_lgc = (ReadBit_u8( blockData[3], D_CPLCOMPIF_CNT_U8)); /* PRQA S 492 */
			(void)Rte_Write_CSELRETURN_Cnt_lgc((ReadBit_u8( blockData[3], D_CSELRETURN_CNT_U8))); /* PRQA S 492 */
            break;
		default:
			/* Invalid coding block Id received, Do Nothing */
			break;
	}
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkDataChange_EndNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EndNotification> of PortPrototype <CbkDataChange>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Block_Request(Coding_BlockIdType blockId)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CbkDataChange_EndNotification(Coding_DataStatusType dataStatus)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkDataChange_EndNotification(Coding_DataStatusType dataStatus)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CbkDataChange_EndNotification
 *********************************************************************************************************************/
	
	Coding_RequestBlock(CODING_ID_AREA_CODINGDATASET1);
	Coding_RequestBlock(CODING_ID_AREA_CODINGDATASET2);
	Coding_RequestBlock(CODING_ID_AREA_CODINGDATASET3);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkDataChange_StartNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <StartNotification> of PortPrototype <CbkDataChange>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CbkDataChange_StartNotification(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkDataChange_StartNotification(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CbkDataChange_StartNotification
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CbkPreConditions_Check
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Check> of PortPrototype <CbkPreConditions>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CbkPreConditions_Check(Coding_ErrorType *error)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkPreConditions_Check(P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CbkPreConditions_Check
 *********************************************************************************************************************/
	*error = CODING_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Init1
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
 *   void Rte_IWrite_VehCfg_Init1_DesiredTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_VehCfg_Init1_DesiredTunPers_Cnt_u16(void)
 *   void Rte_IWrite_VehCfg_Init1_DesiredTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_VehCfg_Init1_DesiredTunSet_Cnt_u16(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_ReadBlock(UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_ReadBlock(NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehCfg_Init1
 *********************************************************************************************************************/
	VAR(TuningSelectParam, AUTOMATIC) TuningSelectParam_Cnt_T_str;
	VAR(uint32, AUTOMATIC) HWAPHwDescData_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) SVKSupplierCheck_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PrevTunSelValid_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) CopyErrorData_Cnt_T_u16;

	TuningSelectParam_Cnt_T_str.TuningSet = Rte_Pim_PrevVldTuningSel()->TuningSet;
	TuningSelectParam_Cnt_T_str.TuningPers = Rte_Pim_PrevVldTuningSel()->TuningPers;

	/* Assign personality */
	StrdTuningSelPers_Cnt_M_u16 = TuningSelectParam_Cnt_T_str.TuningPers;
	StrdTuningSelSet_Cnt_M_u16 = TuningSelectParam_Cnt_T_str.TuningSet;

	/* Assign tuning set */
	if(k_NxtrVariantCalSel_Cnt_u8 >= D_NUMOFTUNSETS_CNT_U16)
	{
		/* Calibration exceeds max number of sets, check EEPROM */
		if(StrdTuningSelSet_Cnt_M_u16 >= D_NUMOFTUNSETS_CNT_U16)
		{
			/* Invalid EEPROM value, set to default. */
			StrdTuningSelSet_Cnt_M_u16 = 0U;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x01U, NTC_STATUS_FAILED);
		}
		else
		{
			/* Read in HWAP Data */
			HWAPHwDescData_Cnt_T_u32 = (uint32)((uint32)(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8)]) << 24u);
			HWAPHwDescData_Cnt_T_u32 |= (uint32)((uint32)(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 1u)]) << 16u);
			HWAPHwDescData_Cnt_T_u32 |= (uint32)((uint32)(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 2u)]) << 8u);
			HWAPHwDescData_Cnt_T_u32 |= (uint32)((uint32)(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 3u)]));

			/* Check if HWAP is valid (non-zero). The block is assumed to be valid since the upgrade procedure will populate all 0's in the block */
			if (HWAPHwDescData_Cnt_T_u32 == D_ZERO_CNT_U32)
			{
				/* Invalid HWAP */
				SVKSupplierCheck_Cnt_T_lgc = SVKSupplierChk(&VehCfg_SvkSysSupp[0]);

				if(SVKSupplierCheck_Cnt_T_lgc == TRUE)
				{
					/* At this point, the assumption is the ECU is in manufacturing mode and HWAP has not been configured.
					 * As a result, the tuning set will be initialized with the EEPROM value (if the block is valid) or the
					 * default of index 0. In Per1, a check is added for the MEC counter, and if the part is in manufacturing mode,
					 * then nothing happens. If it is not, then a fault will set since a tuning set must be selected */

					/* Read the depreciated block into the module buffer to migrate the valid values to the new block definition */
					(void)NvM_GetErrorStatus(Rte_NvmBlock_VehCfg_PrevVldTuningSel, &PrevTunSelValid_Cnt_T_lgc);

					if ( (NVM_REQ_OK != PrevTunSelValid_Cnt_T_lgc) )
					{
						/* Data is not OK, use zero as default */
						StrdTuningSelSet_Cnt_M_u16 = D_ZERO_CNT_U16;
					}
					else
					{
						/* Do nothing, data is already valid */
					}
				}
				else
				{
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x01U, NTC_STATUS_FAILED);
				}
			}
			else if (HWAPHwDescData_Cnt_T_u32 == D_HWAPINVALID_CNT_U32)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x01U, NTC_STATUS_FAILED);
			}
			else
			{
				/* Valid HWAP, lookup the tuning set to use */
				LookupTunVariant(HWAPHwDescData_Cnt_T_u32, &StrdTuningSelSet_Cnt_M_u16);
			}
		}
	}
	else
	{
		/* Set to value in calibration (overrides EEPROM and HWAP) */
		StrdTuningSelSet_Cnt_M_u16 = k_NxtrVariantCalSel_Cnt_u8;
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x00U, NTC_STATUS_PASSED);
	}

	CopyErrorData_Cnt_T_u16 = ( ((uint16)Nxtr_FeeInitialized_Cnt_u8[1] << 0x08u) | ((uint16)Nxtr_FeeInitialized_Cnt_u8[0]) );
	if ((CopyErrorData_Cnt_T_u16 == D_EEPROM_FEE_COPYERR_FLAG1) || (CopyErrorData_Cnt_T_u16 == D_EEPROM_FEE_COPYERR_FLAG2))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMtoFeeCpyError, 0x00u, NTC_STATUS_PASSED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMtoFeeCpyError, 0x01u, NTC_STATUS_FAILED);		
	}


	Rte_IWrite_VehCfg_Init1_DesiredTunSet_Cnt_u16(StrdTuningSelSet_Cnt_M_u16);
	Rte_IWrite_VehCfg_Init1_DesiredTunPers_Cnt_u16(StrdTuningSelPers_Cnt_M_u16);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Per1
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
 *   Implicit S/R API:
 *   -----------------
 *   ManufModeType Rte_IRead_VehCfg_Per1_NxtrMEC_Cnt_enum(void)
 *   QU_SER_WSTA_EST_FTAX Rte_IRead_VehCfg_Per1_PrkAssistState_Cnt_u08(void)
 *   New_Coding_79 Rte_IRead_VehCfg_Per1_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(void)
 *   Boolean Rte_IRead_VehCfg_Per1_VINValid_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VehCfg_Per1_DesiredTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_VehCfg_Per1_DesiredTunPers_Cnt_u16(void)
 *   void Rte_IWrite_VehCfg_Per1_DesiredTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_VehCfg_Per1_DesiredTunSet_Cnt_u16(void)
 *   void Rte_IWrite_VehCfg_Per1_EnergyModeState_Cnt_enum(EnergyModeStateType data)
 *   EnergyModeStateType *Rte_IWriteRef_VehCfg_Per1_EnergyModeState_Cnt_enum(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
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
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehCfg_Per1
 *********************************************************************************************************************/

	VAR(Vsm_OperatingModeType, AUTOMATIC) EnergyMode_T_enum;
	VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum;
	VAR(ManufModeType, AUTOMATIC) NxtrMec_Cnt_T_enum;

	/*Tuning Select */
	VAR(New_Coding_79, AUTOMATIC) TuningSelRxMsgVal_Cnt_T_enum;
	VAR(uint8, AUTOMATIC) SelectedTuningID_Cnt_T_u8 = D_TUNINGSELBASESVT_CNT_U8;
	VAR(uint16, AUTOMATIC) SetIdx_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) PerIdx_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) TuningSelMatch_Uls_T_lgc;
	VAR(uint16, AUTOMATIC) DesiredSet_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) DesiredPer_Cnt_T_u16;
	VAR(QU_SER_WSTA_EST_FTAX, AUTOMATIC) ParkAssistState_Cnt_T_u8;

	VAR(uint32, AUTOMATIC) HWAPHwDescData_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) VINValid_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) CopyErrorData_Cnt_T_u16;

	NxtrMec_Cnt_T_enum = Rte_IRead_VehCfg_Per1_NxtrMEC_Cnt_enum();
	
	VINValid_Cnt_T_lgc = Rte_IRead_VehCfg_Per1_VINValid_Cnt_lgc();

	/* Determine if XCP is enabled or disabled */
	if((NxtrMec_Cnt_T_enum == ProductionMode) && (CodingDebugFrame_Uls_M_lgc == FALSE))
	{
		XcpControl(kXcp_Control_Disable);
	}
	else
	{
		XcpControl(kXcp_Control_Enable);
	}
	
	(void)Vsm_GetMode(&EnergyMode_T_enum);

	/* Map the customer specific vehicle modes to the Standard Nxtr Modes */
	switch(EnergyMode_T_enum)
	{
		case VSM_MM_MODE_NORMAL:
			EnergyModeState_Cnt_T_enum = NORMAL;
		break;
		case VSM_MM_MODE_ASSEMBLY:
			EnergyModeState_Cnt_T_enum = PRODUCTION;
		break;
		case VSM_MM_MODE_TRANSPORT:
			EnergyModeState_Cnt_T_enum = TRANSPORTATION;
		break;
		default:
			EnergyModeState_Cnt_T_enum = FLASH;
		break;
	}
	
	/* update outputs */
	Rte_IWrite_VehCfg_Per1_EnergyModeState_Cnt_enum(EnergyModeState_Cnt_T_enum);

	/* Tuning Select */
	TuningSelRxMsgVal_Cnt_T_enum = Rte_IRead_VehCfg_Per1_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP();

	if( (CDD_SWTEnableFlag_Cnt_G_lgc == TRUE) || (k_SWTPresentSwitch_Uls_lgc == FALSE) )
	{
		if (CodingDrvDyn_Uls_M_lgc == TRUE)
		{
			switch(TuningSelRxMsgVal_Cnt_T_enum)
			{
				case D_TUNINGSELBASESVT_CNT_U8:
					SelectedTuningID_Cnt_T_u8 = CodingTunSelSVT_Cnt_M_u8;
				break;
				case D_TUNINGSELSPORT_CNT_U8:
					SelectedTuningID_Cnt_T_u8 = CodingTunSelSport_Cnt_M_u8;
				break;
				default:
					/* No change */
				break;
			}
		}
		else
		{
			/* Select Base SVT */
			SelectedTuningID_Cnt_T_u8 = CodingTunSelSVT_Cnt_M_u8;
		}
	}
	else
	{
		/* Select base tuning */
		SelectedTuningID_Cnt_T_u8 = CodingTunSelBase_Cnt_M_u8;
	}

	/* Search for Tuning ID */
	TuningSelMatch_Uls_T_lgc = FALSE;

	if(k_NxtrVariantCalSel_Cnt_u8 >= D_NUMOFTUNSETS_CNT_U16)
	{
		/* Calibration exceeds max number of sets, check EEPROM */
		if(StrdTuningSelSet_Cnt_M_u16 >= D_NUMOFTUNSETS_CNT_U16)
		{
			/* Invalid EEPROM value, set to default. */
			SetIdx_Cnt_T_u16 = 0U;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x01U, NTC_STATUS_FAILED);
		}
		else
		{
			SetIdx_Cnt_T_u16 = StrdTuningSelSet_Cnt_M_u16;

			/* Read in HWAP Data */
			HWAPHwDescData_Cnt_T_u32 = (uint32)((uint32)(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8)]) << 24u);
			HWAPHwDescData_Cnt_T_u32 |= (uint32)((uint32)(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 1u)]) << 16u);
			HWAPHwDescData_Cnt_T_u32 |= (uint32)((uint32)(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 2u)]) << 8u);
			HWAPHwDescData_Cnt_T_u32 |= (uint32)((uint32)(HwDescData.HweTable[D_HWAPDESCINDEX_CNT_U8].HWESgbmId[(D_HWAPSGBMNUM_CNT_U8 + 3u)]));

			/* Check if HWAP is valid (non-zero). The block is assumed to be valid since the upgrade procedure will populate all 0's in the block */
			if (HWAPHwDescData_Cnt_T_u32 == D_ZERO_CNT_U32)
			{
				if (NxtrMec_Cnt_T_enum == ManufacturingMode)
				{
					/* Nothing to change */
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x00U, NTC_STATUS_PASSED);
				}
				else
				{
					/* Nothing was configured, set fault */
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x01U, NTC_STATUS_FAILED);
				}
			}
			else
			{
				/* Valid HWAP, lookup the tuning set to use */
				LookupTunVariant(HWAPHwDescData_Cnt_T_u32, &SetIdx_Cnt_T_u16);
			}
		}
	}
	else
	{
		/* Sets the set index to the calibration regardless of HWAP */
		SetIdx_Cnt_T_u16 = k_NxtrVariantCalSel_Cnt_u8;
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x00U, NTC_STATUS_PASSED);
	}

	TuningSelSet_Cnt_M_u16 = SetIdx_Cnt_T_u16;

	ParkAssistState_Cnt_T_u8 = (uint8)Rte_IRead_VehCfg_Per1_PrkAssistState_Cnt_u08();

	for(PerIdx_Cnt_T_u16 = 0U; PerIdx_Cnt_T_u16 < D_NUMOFPERS_CNT_U16; PerIdx_Cnt_T_u16++)
	{
		/* PSR494 Changes. If Park assist is active use this cal set */
		if(ParkAssistState_Cnt_T_u8 == Cx21_Schnittstelle_aktiv)
		{
			if( ( (uint16)((*(((T_TunPersSelectionTbl_Ptr_Str)[SetIdx_Cnt_T_u16])[PerIdx_Cnt_T_u16])).k_PMAPersonality_CalID_Cnt_u16) == D_PARKASSISTCALID_CNT_U16) && (TuningSelMatch_Uls_T_lgc == FALSE))
			{
				TuningSelMatch_Uls_T_lgc = TRUE;
			}
		}
		else
		{
			if( ( (uint16)((*(((T_TunPersSelectionTbl_Ptr_Str)[SetIdx_Cnt_T_u16])[PerIdx_Cnt_T_u16])).k_CalID_Cnt_u16) == (uint16)(SelectedTuningID_Cnt_T_u8)) && (TuningSelMatch_Uls_T_lgc == FALSE))
			{
				TuningSelMatch_Uls_T_lgc = TRUE;

			}
		}
		
		if(TuningSelMatch_Uls_T_lgc == TRUE)
		{
			DesiredSet_Cnt_T_u16 = SetIdx_Cnt_T_u16;
			DesiredPer_Cnt_T_u16 = PerIdx_Cnt_T_u16;
			break;
		}
	}


	if(TuningSelMatch_Uls_T_lgc == TRUE)
	{
		/* Valid select, clear fault and updated outputs */
		Rte_IWrite_VehCfg_Per1_DesiredTunSet_Cnt_u16(DesiredSet_Cnt_T_u16);
		Rte_IWrite_VehCfg_Per1_DesiredTunPers_Cnt_u16(DesiredPer_Cnt_T_u16);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CalNotPrgmd, 0x01U, NTC_STATUS_PASSED);

		/* update eeprom, if there is a change */
		if((StrdTuningSelSet_Cnt_M_u16 != DesiredSet_Cnt_T_u16) || (StrdTuningSelPers_Cnt_M_u16 != DesiredPer_Cnt_T_u16))
		{
			StrdTuningSelSet_Cnt_M_u16 = DesiredSet_Cnt_T_u16;
			StrdTuningSelPers_Cnt_M_u16 = DesiredPer_Cnt_T_u16;

			Rte_Pim_PrevVldTuningSel()->TuningSet =  DesiredSet_Cnt_T_u16;
			Rte_Pim_PrevVldTuningSel()->TuningPers = DesiredPer_Cnt_T_u16;
			(void)Rte_Call_NvM_PrevTuningSel_WriteBlock(NULL_PTR);
		}
	}
	else
	{
		/* Per anomaly 6773, the fault shall only be set if the VIN is valid, in other words missing or invalid VIN values shall not trigger this fault */
		if(TRUE == VINValid_Cnt_T_lgc)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CalNotPrgmd, 0x01U, NTC_STATUS_FAILED);
		}
		Rte_IWrite_VehCfg_Per1_DesiredTunSet_Cnt_u16(StrdTuningSelSet_Cnt_M_u16);
		Rte_IWrite_VehCfg_Per1_DesiredTunPers_Cnt_u16(StrdTuningSelPers_Cnt_M_u16);
	}

	CopyErrorData_Cnt_T_u16 = ( ((uint16)Nxtr_FeeInitialized_Cnt_u8[1] << 0x08u) | ((uint16)Nxtr_FeeInitialized_Cnt_u8[0]) );
	if ((CopyErrorData_Cnt_T_u16 == D_EEPROM_FEE_COPYERR_FLAG1) || (CopyErrorData_Cnt_T_u16 == D_EEPROM_FEE_COPYERR_FLAG2))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMtoFeeCpyError, 0x00u, NTC_STATUS_PASSED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EEPROMtoFeeCpyError, 0x01u, NTC_STATUS_FAILED);		
	}

	/* Clear Friction comp learned data when coding bit is OFF */
	if (CodingFrictionComp_Uls_M_lgc == FALSE)
	{
		(void)AvgFricLrn_SCom_ResetToZero();
	}

	/* Clear Pull Comp learned data when coding bit is OFF */
	if(CodingPullComp_Uls_M_lgc == FALSE)
	{
		(void)ActivePull_SCom_Reset();
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Scom_ClearRacktoVehCntrOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearRacktoVehCntrOffset> of PortPrototype <VehCfg_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void VehCfg_Scom_ClearRacktoVehCntrOffset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_ClearRacktoVehCntrOffset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehCfg_Scom_ClearRacktoVehCntrOffset
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Scom_GetVariantSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetVariantSelect> of PortPrototype <VehCfg_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void VehCfg_Scom_GetVariantSelect(UInt8 *VehicleVariant_Cnt_T_u8)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_GetVariantSelect(P2VAR(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) VehicleVariant_Cnt_T_u8)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehCfg_Scom_GetVariantSelect
 *********************************************************************************************************************/
	*VehicleVariant_Cnt_T_u8 = (uint8)(StrdTuningSelSet_Cnt_M_u16 & 0xFFU);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehCfg_Scom_SetVariantSelect
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetVariantSelect> of PortPrototype <VehCfg_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_NvM_PrevTuningSel_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType VehCfg_Scom_SetVariantSelect(UInt8 VehicleVariant_Cnt_T_u8)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_VehCfg_Scom_E_VARIANT_OUTOFRANGE
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_SetVariantSelect(UInt8 VehicleVariant_Cnt_T_u8)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehCfg_Scom_SetVariantSelect (returns application error)
 *********************************************************************************************************************/
	VAR(Std_ReturnType, AUTOMATIC) ReturnValue;

	if(VehicleVariant_Cnt_T_u8 >= D_NUMOFTUNSETS_CNT_U16)
	{
		/* Error, to high of value */
		ReturnValue = RTE_E_VehCfg_Scom_E_VARIANT_OUTOFRANGE;
	}
	else
	{
		Rte_Pim_PrevVldTuningSel()->TuningSet = VehicleVariant_Cnt_T_u8;
		StrdTuningSelSet_Cnt_M_u16 = VehicleVariant_Cnt_T_u8;
		(void)Rte_Call_NvM_PrevTuningSel_WriteBlock(NULL_PTR);

		ReturnValue = RTE_E_OK;
	}



  return ReturnValue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_VEHCFG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

STATIC INLINE FUNC(boolean, AP_DIAGMGR_CODE) ReadBit_u8(	VAR(uint8, AUTOMATIC) Data, 
															VAR(uint8, AUTOMATIC) BitMask)
{
	return (boolean)(((Data & BitMask) == 0U)?FALSE:TRUE);
}


/* Function loops through all personalities to find the 3 coding bits...in this order:
 * CodingTunSelBase_Cnt_M_u8, CodingTunSelSVT_Cnt_M_u8, CodingTunSelSport_Cnt_M_u8 */
FUNC(void, AUTOMATIC) GetPersIndexes(VAR(uint8, AUTOMATIC) NumOfPers_Cnt_T_u8, P2VAR(uint8, AUTOMATIC, AUTOMATIC) data)
{
	VAR(uint8, AUTOMATIC) i;
	VAR(uint8, AUTOMATIC) x;
	VAR(uint8, AUTOMATIC) CodingData_Cnt_T_u8[D_NUMOFPERSBYCODING_CNT_U8];

	CodingData_Cnt_T_u8[0] = CodingTunSelBase_Cnt_M_u8;
	CodingData_Cnt_T_u8[1] = CodingTunSelSVT_Cnt_M_u8;
	CodingData_Cnt_T_u8[2] = CodingTunSelSport_Cnt_M_u8;

	for (i = 0U; i < NumOfPers_Cnt_T_u8; i++)
	{
		for (x = 0U; x < D_NUMOFPERS_CNT_U16; x++)
		{
			if( (uint16)((*(((T_TunPersSelectionTbl_Ptr_Str)[TuningSelSet_Cnt_M_u16])[x])).k_CalID_Cnt_u16) == (uint16)(CodingData_Cnt_T_u8[i]) )
			{
				/* Match found */
				data[i] = x; /* PRQA S 492 */
				break;
			}
			else
			{
				data[i] = 0u; /* PRQA S 492 */ /* Assign to zero, in case no coding information avialable */
			}
		}
	}

	return;
}


/* Function performs checks on the SVK Supplier data for previous SW data. This has impacts to
 * the upgrade procedure when flashing parts */
STATIC FUNC(boolean, AP_VEHCFG_CODE) SVKSupplierChk(P2CONST(uint8, AUTOMATIC, AUTOMATIC) Data_Cnt_T_u8)
{
	VAR(boolean, AUTOMATIC) Result_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) SGBM_MajorID_Cnt_T_u8;

	/* In 1893 Major SGBM ID, is the value 120 or 130, per SER 13C */
	SGBM_MajorID_Cnt_T_u8 = Data_Cnt_T_u8[D_1893_SGBMMAJORIDX_CNT_U8]; /* PRQA S 492 */

	/* Check for 120.x0x.xxx or 130.xxx.xxx */
	if ( (SGBM_MajorID_Cnt_T_u8 == 120u) || (SGBM_MajorID_Cnt_T_u8 == 130u) )
	{
		Result_Cnt_T_lgc = TRUE;
	}
	else
	{
		Result_Cnt_T_lgc = FALSE;
	}

	return Result_Cnt_T_lgc;
}

/* This function looks up the calibration index, or slot, based on the HWAP value in the HwDesc Table. If no match is found,
 * a NTC is set */
STATIC FUNC(void, AP_VEHCFG_CODE) LookupTunVariant(VAR(uint32, AUTOMATIC) HWAPHwDescData_Cnt_T_u32, P2VAR(uint16, AUTOMATIC, AUTOMATIC) TuningSelect_Cnt_T_u16)
{
	VAR(uint32, AUTOMATIC) HWAPCalData_Cnt_T_u32;
	VAR(uint16, AUTOMATIC) Idx_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) NewTuningSetFound_Cnt_T_lgc = FALSE;

	/* Lookup the HWAP Data in the current calibration set */
	HWAPCalData_Cnt_T_u32 = (uint32)((*((T_TunSetSelectionTbl_Ptr_Str)[(*TuningSelect_Cnt_T_u16)])).k_HWAPId_Cnt_u32);

	if (HWAPCalData_Cnt_T_u32 != HWAPHwDescData_Cnt_T_u32)
	{
		for (Idx_Cnt_T_u16 = 0U; Idx_Cnt_T_u16 < D_NUMOFTUNSETS_CNT_U16; Idx_Cnt_T_u16++)
		{
			/* Look for HWAP in cals */
			HWAPCalData_Cnt_T_u32 = (uint32)((*((T_TunSetSelectionTbl_Ptr_Str)[Idx_Cnt_T_u16])).k_HWAPId_Cnt_u32);
			if (HWAPCalData_Cnt_T_u32 == HWAPHwDescData_Cnt_T_u32)
			{
				/* Update HwDesc */
				NewTuningSetFound_Cnt_T_lgc = TRUE;
				*TuningSelect_Cnt_T_u16 = Idx_Cnt_T_u16;
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x00U, NTC_STATUS_PASSED);
				break;
			}
		}

		if(NewTuningSetFound_Cnt_T_lgc == FALSE)
		{
			/* Nothing was found, set fault */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x01U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		/* No change to TuningSelect data */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TunSetNotPrgmd, 0x00U, NTC_STATUS_PASSED);
	}

	return;
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
