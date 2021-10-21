/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Cd_TurnsCounter.c
 *     Workspace:  C:/SynergyWorkArea/Working/TurnsCounter/autosar
 *     SW-C Type:  Cd_TurnsCounter
 *  Generated at:  Tue Jun 28 14:13:51 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Cd_TurnsCounter>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Sat Feb 25 11:04:40 2012
 * %version:          EA3#28 %
 * %derived_by:       czmgrw %
 * %date_modified:    Thu Oct 23 10:29:34 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/25/12	  1       VK		 Initial version of the component											   4987
 * 03/06/12	  2       JJW		 SWC corrections and changes for utilizing the Spi Api abstractly
 * 03/12/12	  3       JJW		 Removed extraneous function scope variable
 *                               Removed OsResource locking patch that was added to fix an issue with the Vector driver
 * 03/23/12	  4       JJW		 Added TurnsCounter_TxConfirmation to meet FDD requirements
 * 04/19/12	  5       OT 		 Updated to FDD 20C rev 4
 * 06/14/12	  6       OT 		 Updates for PIC v2.0.0 software                                               5651
 * 06/18/12	  7       OT 		 Changed part number from input to constant                                    5651
 * 06/26/12	  8       OT 		 Incremented D_SWPARTNUM_B08 for PIC build 02.00.01                           5765/5766
 * 08/30/12	  9		  KJS		 Anomaly 3690 / FDD 20C Rev5 													6145
 * 09/07/12	  10	  KJS		 Anomaly 3515 - Removed RTE_PTR2ARRAYBASETYPE_PASSING requirement				5816
 * 09/21/12	  11	  KJS		 Anomaly 3819 Corrections														6300
 * 10/26/12	  12	  BWL		 Update to FDD 20C Rev 7 draft & anomoly 3641									6651
 * 10/27/12   13	  KJS		 Added missing global variable
 * 03/01/13   14	  AH		 Update to FDD 20C Rev 10
 * 03/14/13	  15	  KJS		 QAC corrections. 
 * 03/15/13	  16	  KJS		 Corrected pointer reference in part number service call.
 * 03/20/13   17      KJS		 Corrected anomalies 4656, 4659, and 4682 to meet Rev 11 of FDD
 * 04/25/13   18      BWL		 Corrected anomaly 4813. Added range check and removed cast. Update to FDD v13.	8070
 * 05/09/13   19      VK		 Anomaly 4938 fix																8242
 * 06/21/13   21      VT         Anomaly 5087 fix (missed adding comment for version 20)                        8673
 * 01/14/14   22      KMC        Updated to FDD20C ver016 -- autoflash support and fixes for A6181 and A6143    11090
 * 01/21/14   23      KMC        Corrected else path in Tc_ChkPN() for FDD20C ver 017 -- fixes anomaly 6254.    11287
 *                               QAC cleanup.
 * 10/23/14   24      BDO        Update to FDD 20C rev 18 to address anomaly 7323                               11971
 * 06/24/16   25      JK         Updated to FDD 20C rev 19 and unit test redundancy logic removed            EA3#8818
 * 07/15/16   26      ABS        Updated for Rev20            												 EA3#9669
 * 07/26/16   27      JK         Updated to FDD 20C rev 21 - Anomaly fix EA3#9784                            EA3#9852
 * 01/31/17   28      JK         Updated to FDD 20C rev 22                                                  EA3#13661
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

  Spi_DataPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nxtr SystemTime Service

 *********************************************************************************************************************/

#include "Rte_Cd_TurnsCounter.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* == INCLUDES ================================================= */
#include "math.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "CDD_Data.h"

/* PRQA S 310 EOF *
 * MISRA-C:2004 Rule 11.4: Casting to different object pointer type. The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 18.4: Deviation for use of union -union types created for unpacking SPI messages used in communication with the Turns Counter sensor.The rule is suppressed at each line */

/* MISRA-C:2004 Rule 8.7: Deviation required for the module level variables because of memory map.The rule is suppressed at each line */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/* == MACRO CONSTANT =========================================== */

#define D_SPIBUFFERSZ_CNT_U08				((uint8)10)
#define D_RCOFFSET_CNT_U08					((uint8)0x40)

#define D_INITCMDMSK_CNT_B08				((uint8)0x20)
#define D_TRNSMODECMDMSK_CNT_B08			((uint8)0x10)
#define D_CLRINFOCMDMSK_CNT_B08				((uint8)0x08)
#define D_INITMTROCTMSK_CNT_B08				((uint8)0x07)
#define D_EIGHTBITMSK_B08					((uint8)0xFF)
#define D_SENSPOSMSK_B08					((uint8)0x7F)
#define D_SENSPOS1MSK_B08					((uint8)0x6F)
#define D_SCMNMXERRSMSK_B08					((uint8)0x10)
#define D_BATTERYMSK_B08					((uint8)0x80)
#define D_SPICOMMSK_B08						((uint8)0xE0)
#define D_HIQUSCMSK_B08						((uint8)0x06)
#define D_PRIMARYERRMSK_B08					((uint8)0x01)
#define D_BEMFERRMSK_B08					((uint8)0x02)
#define D_TCVSMTRERRMSK_B08					((uint8)0x04)
#define D_TCPRGMEMPNADDR0_CNT_U16			((uint16)0xFE0)
#define D_TCPRGMEMPNADDR1_CNT_U16			((uint16)0xFE1)
#define D_TCPRGMEMPNADDR2_CNT_U16			((uint16)0xFE2)
#define D_TCPRGMEMPNADDR3_CNT_U16			((uint16)0xFE3)
#define D_TCPRGMEMOFSTMNADDR_CNT_U16		((uint16)0xFE6)
#define D_TCPRGMEMOFSTMXADDR_CNT_U16		((uint16)0xFE7)
#define D_TCPRGMEMSCGNMNADDR_CNT_U16		((uint16)0xFE8)
#define D_TCPRGMEMSCGNMXADDR_CNT_U16		((uint16)0xFE9)
#define D_TCPRGMEMSCMNMNADDR_CNT_U16		((uint16)0xFEA)
#define D_TCPRGMEMSCMNMXADDR_CNT_U16		((uint16)0xFEB)
#define D_TCPRGMEMSCMXMNADDR_CNT_U16		((uint16)0xFEC)
#define D_TCPRGMEMSCMXMXADDR_CNT_U16		((uint16)0xFED)

#define D_MCLRDELAY_US_U16					8U
#define D_TXBEGINDELAY_US_U16				50U
#define D_TXENDDELAY_US_U16					2U
#define D_TCRESETDELAY_US_U16				3000U

#define D_MAXCONF_ULS_F32					1.0f
#define D_360_DEGPREV_F32					360.0f
#define D_180_DEG_F32						180.0f
#define D_360_DEG_F32						360.0f
#define D_45_DEGPOCT_F32					45.0f
#define D_HWPOSAUTHRESL_ULS_F32				0.00004f
#define D_TCFLSHSTATINITVAL_CNT_U8			0x50U
#define D_TCALLSTATBITS_CNT_B8				0x53U
#define D_TCSETTSTINCBIT_CNT_B8				0x10U
#define D_TCHOLDSTATBITS_CNT_B8				0x22U
#define D_TCERRSTATBITS_CNT_B8				0x23U
#define D_ASCIINUMOFFSET_CHR				0x30U
#define D_UNKNOWNVALUE_CHR					'?'
#define D_TCPNIMAGEARRSIZE_CNT_U16			4U

#define D_REFLASHVALUE_CHR					'X'
#define D_PROCESSVALUE_CHR					'x'
#define D_MAJMINREVDELIM_CHR				'.'
#define D_SUBSTRINGDELIM_CHR				','

#define D_SCOMMTRPOSLIMIT_DEG_F32			((float32)(121.0f * 360.0f))

#define D_TCFLSHBITS_CNT_U08				((uint8)0xE0)  /* NTC 0x85 bits coming from TcFlshErrors_Cnt_u08 */


/* == DATA TYPES =============================================== */

typedef enum {
	TCSPIMODE_NORMAL	= 0,
	TCSPIMODE_TRANSPORT	= 1,
	TCSPIMODE_RESET		= 2,
	TCSPIMODE_INITTCPOS	= 3 
} TcSpiTransmitMode_T;

enum TcSpiInfoIndex_t {
	TCIDX_STATUS		= 0,
	TCIDX_MTRPOS		= 1,
	TCIDX_ERRHI			= 2,
	TCIDX_ERRLO			= 3,
	TCIDX_INFO			= 4,
	TCIDX_PARTNUM		= 5,
	TCIDX_ADCSIN		= 6,
	TCIDX_ADCCOS		= 7,
	TCIDX_STSCOPY		= 8,
	TCIDX_MTRPOSCOPY	= 9
};

typedef struct {
	Spi_DataType TxBuffer_Cnt_u08[D_SPIBUFFERSZ_CNT_U08];
	Spi_DataType RxBuffer_Cnt_u08[D_SPIBUFFERSZ_CNT_U08];
} TcSpiTransferData_T;

typedef union {                                                        /* PRQA S 750 */
	Spi_DataType Data_Cnt_u08[D_SPIBUFFERSZ_CNT_U08];
	struct {
		unsigned RxCounter				: 2;	/* byte 0 */
		unsigned Initialized			: 1;
		unsigned Error					: 1;
		unsigned BemfActive				: 1;
		unsigned MtrOct					: 3;
		unsigned MtrRev					: 8;	/* byte 1 */
		unsigned Err_Ram				: 1;	/* byte 2 */
		unsigned Err_Flash				: 1;
		unsigned Err_ProgFc				: 1;
		unsigned Err_WDT				: 1;
		unsigned Err_StkOvf				: 1;
		unsigned Err_StkUnf				: 1;
		unsigned Err_CompIntegrity		: 1;
		unsigned Err_RI					: 1;
		unsigned Err_BOR				: 1;	/* byte 3 */
		unsigned Err_BemfComp			: 1;
		unsigned Err_SnsPwrLo			: 1;
		unsigned Err_SinCosMinMax		: 1;
		unsigned Err_SinVsCos			: 1;
		unsigned Err_SineGain			: 1;
		unsigned Err_DeltaOct			: 1;
		unsigned Err_MaxTrvl			: 1;
		unsigned Info_SpiSeq			: 1;	/* byte 4 */
		unsigned Info_SpiData			: 1;
		unsigned Info_SpiCmd			: 1;
		unsigned _rsvd_0				: 2;
		unsigned Info_SnsPwrStuckOn		: 1;
		unsigned Info_TcOvrActPD		: 1;
		unsigned Info_FlashChkProgress	: 1;
		unsigned SwHw_PN				: 8;	/* byte 5 */
		unsigned TC_AdjSine				: 8;	/* byte 6 */
		unsigned TC_AdjCosine			: 8;	/* byte 7 */
		unsigned Inv_RxCounter			: 2;	/* byte 8 */
		unsigned Inv_Initialized		: 1;
		unsigned Inv_Error				: 1;
		unsigned Inv_BemfActive			: 1;
		unsigned Inv_MtrOct				: 3;
		unsigned Inv_MtrRev				: 8;	/* byte 9 */
	} bits;
} TcSpiRxInfo_T; /* PRQA S 750 */

typedef union {                                                       /* PRQA S 750 */
	Spi_DataType Data_Cnt_u08[D_SPIBUFFERSZ_CNT_U08];
	struct {
		unsigned TxCounter				: 2;	/* byte 0 */
		unsigned InitCmd				: 1;
		unsigned TransportModeCmd		: 1;
		unsigned ClrInfoBitsCmd			: 1;
		unsigned InitMtrOct				: 3;
		unsigned InitMtrRev				: 8;	/* byte 1 */
		unsigned Tc_EOL_SineOffsetCal	: 8;	/* byte 2 */
		unsigned TC_EOL_CosineOffsetCal	: 8;	/* byte 3 */
		unsigned TC_EOL_Sin2CosGain		: 8;	/* byte 4 */
		unsigned TC_EOL_SinVsCosMin		: 8;	/* byte 5 */
		unsigned TC_EOL_SinVsCosMax		: 8;	/* byte 6 */
		unsigned TC_EOL_CalChkSum		: 8;	/* byte 7 */
		unsigned Inv_TxCounter			: 2;	/* byte 8 */
		unsigned Inv_InitCmd			: 1;
		unsigned Inv_ClrInfoBitsCmd		: 1;
		unsigned Inv_TransportModeCmd	: 1;
		unsigned Inv_InitMtrOct			: 3;
		unsigned Inv_InitMtrRev			: 8;	/* byte 9 */
	} bits;
} TcSpiTxInfo_T;

typedef enum {
	DIAG_ACTIVE	= 0,
	DIAG_PASSED	= 1,
	DIAG_FAILED	= 2
} TCDiagState_T;

typedef enum {
	NORESULT = 0,
	PASSED	= 1,
	FAILED	= 2
} BemfDiagStsTyp;

/* == VARIABLES ================================================ */
#define TURNSCOUNTER_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC)				MRFTcMtrPosOffs_Deg_M_f32;
STATIC VAR(uint32, AUTOMATIC)				TcResetDelayStart_uS_M_u32;
STATIC VAR(uint32, AUTOMATIC)				TcResetTimeout_mS_M_u32;
STATIC VAR(float32, AUTOMATIC)				MtrPos_Deg_M_f32;
STATIC VAR(float32, AUTOMATIC)				MtrVel_MtrRadpS_M_f32;
#define TURNSCOUNTER_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define TURNSCOUNTER_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC)				TcSpiComFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AUTOMATIC)				TcSpiDataFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AUTOMATIC)				TcMOSIErrCnt_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC)				TCvsMtrPosErrCnt_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC)				TcSCMnMxErrCnt_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC)               HighMtrVelHighCnt_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC)               HighMtrVelLowCnt_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC)               TotHighSampleCnt_Cnt_M_u16; /* PRQA S 3218 */
#define TURNSCOUNTER_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define TURNSCOUNTER_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AUTOMATIC)				TcSpiTxRC_Cnt_M_u08;
STATIC VAR(uint8, AUTOMATIC)				TcInitMtrRevField_Cnt_M_b08;
STATIC VAR(uint8, AUTOMATIC)				TcClrInfoBitsField_Cnt_M_b08;
STATIC VAR(uint8, AUTOMATIC)				TcInitMtrOctField_Cnt_M_b08;
STATIC VAR(uint8, AUTOMATIC) 				NTCPrMainResets_Cnt_M_u08;
STATIC VAR(uint8, AUTOMATIC) 				TcFlashStatus_Cnt_M_u08;
STATIC VAR(uint8, AUTOMATIC)				t_TcImagePN_Cnt_M_u8[D_TCPNIMAGEARRSIZE_CNT_U16];
STATIC VAR(uint8, AUTOMATIC)				t_TcActivePN_Cnt_M_u8[D_TCPNIMAGEARRSIZE_CNT_U16];
STATIC VAR(uint8, AUTOMATIC)				t_TcActivePNvldCnt_Cnt_M_u8[D_TCPNIMAGEARRSIZE_CNT_U16];
#define TURNSCOUNTER_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define TURNSCOUNTER_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(TcSpiTransferData_T, AUTOMATIC)	TcSpiBuffer_Cnt_M_str;
STATIC VAR(TcSpiTransmitMode_T, AUTOMATIC)	TcSpiTxMode_Cnt_M_enum;
STATIC VAR(boolean, AUTOMATIC)				AcmpToTcOffsetInit_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC)				TcSpiResetReq_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC)				TcSpiDataValid_Cnt_M_lgc;
STATIC VAR(TurnsCntrValStateType, AUTOMATIC)	TcSignalValidity_Cnt_M_enum;
STATIC VAR(boolean, AUTOMATIC)				TcInitComplete_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC)				RackCenterComplete_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC)				TCprocessing_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC)				AllowProcessTCErrs_Cnt_M_lgc;
STATIC P2VAR(TcSpiRxInfo_T, AUTOMATIC, AUTOMATIC)  pTcRxInfo_Cnt_M_str;
STATIC VAR(boolean, AUTOMATIC)				TcReflashActive_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC)				TcAllowSCMnMxErrs_Cnt_M_lgc;
STATIC VAR(boolean, AUTOMATIC)				TcFlashVerify_Cnt_M_lgc;
STATIC VAR(BemfDiagStsTyp, AUTOMATIC)       BemfDiagSts_Cnt_M_enum; /* PRQA S 3218 */
#define TURNSCOUNTER_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* == PROTOTYPES =============================================== */

STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_CalcInitPos(VAR(float32,AUTOMATIC) MRFScomMtrPos_Deg_T_f32);
STATIC FUNC(TCDiagState_T, CD_TURNSCOUNTER_CODE) Tc_DiagFailure(void);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_InitAcmpToTcOffset(void);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_DataErr(void);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_InfoBits(VAR(uint8, AUTOMATIC) InfoBits_Cnt_b08);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_ErrorBits(VAR(uint8, AUTOMATIC) ErrHi_Cnt_T_u08,
													 VAR(uint8, AUTOMATIC) ErrLo_Cnt_T_u08);

STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_PrepSpiReceive(void);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_ProcSpiReceive(VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum,
														  VAR(float32, AUTOMATIC) HwPosAuth_Uls_T_f32);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_VarInit(void);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_ReInit(VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_Reset(VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_SpiCom(VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum);
STATIC FUNC(boolean, CD_TURNSCOUNTER_CODE) Tc_ChkPN(VAR(uint8, AUTOMATIC) TCSpiRC_Cnt_T_u08);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_ProcPN(VAR(uint8, AUTOMATIC) TCSpiRC_Cnt_T_u08);
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_FlashStat(void);
STATIC FUNC(uint8, CD_TURNSCOUNTER_CODE) ConvertToASCII_HighByte( VAR(uint8, AUTOMATIC)  InputData );
STATIC FUNC(uint8, CD_TURNSCOUNTER_CODE) ConvertToASCII_LowByte( VAR(uint8, AUTOMATIC)  InputData );

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
 * IoHwAb_BoolType: Integer in interval [0...1]
 * Spi_DataType: Integer in interval [0...255]
 * Spi_NumberOfDataType: Integer in interval [0...65535]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * EnergyModeStateType: Enumeration of integer in interval [0...3] with enumerators
 *   NORMAL (0u)
 *   PRODUCTION (1u)
 *   TRANSPORTATION (2u)
 *   FLASH (3u)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_NvMBlkDftActA (6u)
 *   NTC_Num_NvMBlkDftActB (7u)
 *   NTC_Num_NvMBlkDftActC (8u)
 *   NTC_Num_CurrentSensorCalOutOfRange (9u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWACrossChecks (108u)
 *   NTC_Num_HWASnsrCommFault (109u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_BattTransOverVolt (182u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_DataOther2FltMsg_M (295u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_DSTXORActive (399u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 * TurnsCntrValStateType: Enumeration of integer in interval [0...255] with enumerators
 *   TCV_COMPUTING (0u)
 *   TCV_VALID (100u)
 *   TCV_INVALID (255u)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 * Spi_DataPtr: Array with 65535 element(s) of type Spi_DataType
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
 * Float: D_ZERO_ULS_F32 = 0
 * UInt32: D_ZERO_CNT_U32 = 0u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   EOLTurnsCntrCals_Datatype *Rte_Pim_EOLTurnsCntrCals(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_CD_TURNSCOUNTER_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TcEOLCals_Scom_ClearTcEOLCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearTcEOLCals> of PortPrototype <TcEOLCals_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TcEOLCals_Scom_ClearTcEOLCals(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_ClearTcEOLCals(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TcEOLCals_Scom_ClearTcEOLCals
 *********************************************************************************************************************/

	 Rte_Pim_EOLTurnsCntrCals()->TcEolSineOffset_Cnt_u08 = k_TcEolOffsetDef_Cnt_u08;
	 Rte_Pim_EOLTurnsCntrCals()->TcEolCosineOffset_Cnt_u08 = k_TcEolOffsetDef_Cnt_u08;
	 Rte_Pim_EOLTurnsCntrCals()->TcEolSin2CosGain_Cnt_u08 = k_TcEolSin2CosGainDef_Cnt_u08;
	 Rte_Pim_EOLTurnsCntrCals()->TcEolSinVsCosMin_Cnt_u08 = k_TcEolSinVsCosMinDef_Cnt_u08;
	 Rte_Pim_EOLTurnsCntrCals()->TcEolSinVsCosMax_Cnt_u08 = k_TcEolSinVsCosMaxDef_Cnt_u08;
	 Rte_Pim_EOLTurnsCntrCals()->TcEolCalChksm_Cnt_u08 = k_TcEolCalChksmDef_Cnt_u08;

	 TcSpiResetReq_Cnt_M_lgc = TRUE;

	 (void) Rte_Call_EOLTurnsCntrCals_WriteBlock(NULL_PTR);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TcEOLCals_Scom_ReadTcEOLCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadTcEOLCals> of PortPrototype <TcEOLCals_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TcEOLCals_Scom_ReadTcEOLCals(EOLTurnsCntrCals_Datatype *TcEOLCalsPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_ReadTcEOLCals(P2VAR(EOLTurnsCntrCals_Datatype, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcEOLCalsPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TcEOLCals_Scom_ReadTcEOLCals
 *********************************************************************************************************************/

	*TcEOLCalsPtr = *Rte_Pim_EOLTurnsCntrCals();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TcEOLCals_Scom_SetTcEOLCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetTcEOLCals> of PortPrototype <TcEOLCals_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_EOLTurnsCntrCals_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType TcEOLCals_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TcEOLCals_Scom_RequestDataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CD_TURNSCOUNTER_APPL_CODE) TcEOLCals_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TcEOLCals_Scom_SetTcEOLCals (returns application error)
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) TcCalChksm_Cnt_T_u8;
	VAR(Std_ReturnType, AUTOMATIC) ReturnCode_Cnt_T_u08;

		if ( (k_TcEolOffsetDef_Cnt_u08 == Rte_Pim_EOLTurnsCntrCals()->TcEolSineOffset_Cnt_u08)
		  && (k_TcEolOffsetDef_Cnt_u08 == Rte_Pim_EOLTurnsCntrCals()->TcEolCosineOffset_Cnt_u08)
		  && (k_TcEolSin2CosGainDef_Cnt_u08 == Rte_Pim_EOLTurnsCntrCals()->TcEolSin2CosGain_Cnt_u08)
		  && (k_TcEolSinVsCosMinDef_Cnt_u08 == Rte_Pim_EOLTurnsCntrCals()->TcEolSinVsCosMin_Cnt_u08)
		  && (k_TcEolSinVsCosMaxDef_Cnt_u08 == Rte_Pim_EOLTurnsCntrCals()->TcEolSinVsCosMax_Cnt_u08)
		  && (k_TcEolCalChksmDef_Cnt_u08 == Rte_Pim_EOLTurnsCntrCals()->TcEolCalChksm_Cnt_u08) )
		{
			if (  ( ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMOFSTMNADDR_CNT_U16])>>1)) <= TcEolSineOffset_Cnt_P_u8 )
				&& ( TcEolSineOffset_Cnt_P_u8 <= ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMOFSTMXADDR_CNT_U16])>>1)) )
			 && ( ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMOFSTMNADDR_CNT_U16])>>1)) <= TcEolCosineOffset_Cnt_P_u8 )
				&& ( TcEolCosineOffset_Cnt_P_u8 <= ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMOFSTMXADDR_CNT_U16])>>1)) )
			 && ( ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMSCGNMNADDR_CNT_U16])>>1)) <= TcEolSin2CosGain_Cnt_P_u8)
				&& ( TcEolSin2CosGain_Cnt_P_u8 <= ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMSCGNMXADDR_CNT_U16])>>1)) )
			 && ( ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMSCMNMNADDR_CNT_U16])>>1)) <= TcEolSinVsCosMin_Cnt_P_u8)
				&& ( TcEolSinVsCosMin_Cnt_P_u8 <= ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMSCMNMXADDR_CNT_U16])>>1)) )
			 && ( ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMSCMXMNADDR_CNT_U16])>>1)) <= TcEolSinVsCosMax_Cnt_P_u8)
				&& ( TcEolSinVsCosMax_Cnt_P_u8 <= ((uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMSCMXMXADDR_CNT_U16])>>1)) )  )
			{
				TcCalChksm_Cnt_T_u8 = TcEolSineOffset_Cnt_P_u8;
				TcCalChksm_Cnt_T_u8 += TcEolCosineOffset_Cnt_P_u8;
				TcCalChksm_Cnt_T_u8 += TcEolSin2CosGain_Cnt_P_u8;
				TcCalChksm_Cnt_T_u8 += TcEolSinVsCosMin_Cnt_P_u8;
				TcCalChksm_Cnt_T_u8 += TcEolSinVsCosMax_Cnt_P_u8;
				TcCalChksm_Cnt_T_u8 += TcEolCalChksm_Cnt_P_u8;

				if (TcCalChksm_Cnt_T_u8 == 0xFFU)
				{
					Rte_Pim_EOLTurnsCntrCals()->TcEolSineOffset_Cnt_u08 = TcEolSineOffset_Cnt_P_u8;
					Rte_Pim_EOLTurnsCntrCals()->TcEolCosineOffset_Cnt_u08 = TcEolCosineOffset_Cnt_P_u8;
					Rte_Pim_EOLTurnsCntrCals()->TcEolSin2CosGain_Cnt_u08 = TcEolSin2CosGain_Cnt_P_u8;
					Rte_Pim_EOLTurnsCntrCals()->TcEolSinVsCosMin_Cnt_u08 = TcEolSinVsCosMin_Cnt_P_u8;
					Rte_Pim_EOLTurnsCntrCals()->TcEolSinVsCosMax_Cnt_u08 = TcEolSinVsCosMax_Cnt_P_u8;
					Rte_Pim_EOLTurnsCntrCals()->TcEolCalChksm_Cnt_u08 = TcEolCalChksm_Cnt_P_u8;

					(void) Rte_Call_EOLTurnsCntrCals_WriteBlock(NULL_PTR);
					TcSpiResetReq_Cnt_M_lgc = TRUE;
					ReturnCode_Cnt_T_u08 = RTE_E_OK;
				}
				else
				{
					ReturnCode_Cnt_T_u08 = RTE_E_TcEOLCals_Scom_RequestDataOutOfRange; /*TODO: needs to be replaced with 0xFD */
				}
			}
			else
			{
				ReturnCode_Cnt_T_u08 = RTE_E_TcEOLCals_Scom_RequestDataOutOfRange; /*TODO: needs to be replaced with 0xFD */
			}
		}
		else
		{
			ReturnCode_Cnt_T_u08 = RTE_E_TcEOLCals_Scom_RequestDataOutOfRange;
		}

  return ReturnCode_Cnt_T_u08;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   EnergyModeStateType Rte_IRead_TurnsCounter_Init1_EnergyModeState_Cnt_enum(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32(void)
 *   void Rte_IWrite_TurnsCounter_Init1_TcActivePN_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_TurnsCounter_Init1_TcActivePN_Cnt_u32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TcMCLR_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_TcDataCh_SetupEB(const Spi_DataType *SrcDataBufferPtr, const Spi_DataType *DesDataBufferPtr, Spi_NumberOfDataType Length)
#else
 *   Std_ReturnType Rte_Call_TcDataCh_SetupEB(const Spi_DataPtr *SrcDataBufferPtr, const Spi_DataPtr *DesDataBufferPtr, Spi_NumberOfDataType Length)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TurnsCounter_Init1
 *********************************************************************************************************************/
	VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum;
	VAR(uint32, AUTOMATIC) TcActivePN_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) TcActivePNVldCnt_Cnt_T_u32;

	EnergyModeState_Cnt_T_enum = Rte_IRead_TurnsCounter_Init1_EnergyModeState_Cnt_enum();

	(void) Rte_Call_TcMCLR_OP_SET(STD_LOW);
	
	AllowProcessTCErrs_Cnt_M_lgc = TRUE;
	
	
	TcSignalValidity_Cnt_M_enum = TCV_COMPUTING;
	
	TcFlashStatus_Cnt_M_u08 = D_TCFLSHSTATINITVAL_CNT_U8;
	
	t_TcImagePN_Cnt_M_u8[0] = (uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMPNADDR0_CNT_U16])>>1);
	t_TcImagePN_Cnt_M_u8[1] = (uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMPNADDR1_CNT_U16])>>1);
	t_TcImagePN_Cnt_M_u8[2] = (uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMPNADDR2_CNT_U16])>>1);
	t_TcImagePN_Cnt_M_u8[3] = (uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMPNADDR3_CNT_U16])>>1);

	Tc_ReInit(EnergyModeState_Cnt_T_enum);
	
	/* Init Pointer */
	pTcRxInfo_Cnt_M_str = (TcSpiRxInfo_T*)(TcSpiBuffer_Cnt_M_str.RxBuffer_Cnt_u08);

	(void) Rte_Call_TcDataCh_SetupEB((const Spi_DataPtr*)&(TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08), (const Spi_DataPtr*)&(TcSpiBuffer_Cnt_M_str.RxBuffer_Cnt_u08), D_SPIBUFFERSZ_CNT_U08);

	TcActivePN_Cnt_T_u32 = ((uint32)t_TcActivePN_Cnt_M_u8[0] << 24) |
							((uint32)t_TcActivePN_Cnt_M_u8[1] << 16) |
							((uint32)t_TcActivePN_Cnt_M_u8[2] << 8);
	TcActivePNVldCnt_Cnt_T_u32 = ((uint32)t_TcActivePNvldCnt_Cnt_M_u8[0] << 24) |
								  ((uint32)t_TcActivePNvldCnt_Cnt_M_u8[1] << 16) |
								  ((uint32)t_TcActivePNvldCnt_Cnt_M_u8[2] << 8);

	Rte_IWrite_TurnsCounter_Init1_TcActivePNVldCnt_Cnt_u32 (TcActivePNVldCnt_Cnt_T_u32);
	Rte_IWrite_TurnsCounter_Init1_TcActivePN_Cnt_u32 (TcActivePN_Cnt_T_u32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Per1
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
 *   Float Rte_IRead_TurnsCounter_Per1_AlignedCumMtrPosMRF_Deg_f32(void)
 *   EnergyModeStateType Rte_IRead_TurnsCounter_Per1_EnergyModeState_Cnt_enum(void)
 *   Float Rte_IRead_TurnsCounter_Per1_HwTargetAuthority_Uls_f32(void)
 *   Float Rte_IRead_TurnsCounter_Per1_ICMMtrPosMRF_Deg_f32(void)
 *   Float Rte_IRead_TurnsCounter_Per1_MotorVelMRF_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_TurnsCounter_Per1_RackCenterComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_TurnsCounter_Per1_TCFlash_Cnt_lgc(void)
 *   UInt8 Rte_IRead_TurnsCounter_Per1_TcFlashErrors_Cnt_u08(void)
 *   Boolean Rte_IRead_TurnsCounter_Per1_TcFlashVerify_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32(void)
 *   void Rte_IWrite_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32(void)
 *   void Rte_IWrite_TurnsCounter_Per1_TcActivePN_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_TurnsCounter_Per1_TcActivePN_Cnt_u32(void)
 *   void Rte_IWrite_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum(TurnsCntrValStateType data)
 *   TurnsCntrValStateType *Rte_IWriteRef_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_TcMCLR_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TcDataSeq_AsyncTransmit(void)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TcDataSeq_GetSequenceResult(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Spi_Seq_SPI_SEQ_CANCELLED, RTE_E_Spi_Seq_SPI_SEQ_FAILED, RTE_E_Spi_Seq_SPI_SEQ_PENDING
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TurnsCounter_Per1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC)	HwPosAuth_Uls_T_f32;
	VAR(uint16, AUTOMATIC)	ElapsedTime_uS_T_u16;
	VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum;
	VAR(uint8, AUTOMATIC) TcFlashErrors_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) TcActivePN_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) TcActivePNVldCnt_Cnt_T_u32;

	/* capture inputs */
	HwPosAuth_Uls_T_f32 = Rte_IRead_TurnsCounter_Per1_HwTargetAuthority_Uls_f32();
	TcReflashActive_Cnt_M_lgc = Rte_IRead_TurnsCounter_Per1_TCFlash_Cnt_lgc();
	TcFlashVerify_Cnt_M_lgc = Rte_IRead_TurnsCounter_Per1_TcFlashVerify_Cnt_lgc();
	EnergyModeState_Cnt_T_enum = Rte_IRead_TurnsCounter_Per1_EnergyModeState_Cnt_enum();
	RackCenterComplete_Cnt_M_lgc = Rte_IRead_TurnsCounter_Per1_RackCenterComplete_Cnt_lgc();
	TcFlashErrors_Cnt_T_u08 = Rte_IRead_TurnsCounter_Per1_TcFlashErrors_Cnt_u08();

	NTCPrMainResets_Cnt_M_u08 = (NTCPrMainResets_Cnt_M_u08 & ((uint8)(~D_TCFLSHBITS_CNT_U08))) | TcFlashErrors_Cnt_T_u08;
	if(TCprocessing_Cnt_M_lgc==TRUE){
		TCprocessing_Cnt_M_lgc=FALSE;
	}
	else
	{
		/* reset in flash mode */
		if((TRUE == TcReflashActive_Cnt_M_lgc)&&(FALSE == TcFlashVerify_Cnt_M_lgc))
		{
				TcFlashStatus_Cnt_M_u08 = D_TCFLSHSTATINITVAL_CNT_U8;
				Tc_VarInit();


		}
		else
		{
			if((TRUE == TcReflashActive_Cnt_M_lgc)&&(TRUE == TcFlashVerify_Cnt_M_lgc))
			{
				EnergyModeState_Cnt_T_enum = NORMAL;
			}

			if(FALSE == TcInitComplete_Cnt_M_lgc)
			{
				(void) Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(TcResetDelayStart_uS_M_u32, &ElapsedTime_uS_T_u16);
				if(ElapsedTime_uS_T_u16 >= D_TCRESETDELAY_US_U16)
				{
					Tc_SpiCom(EnergyModeState_Cnt_T_enum);
				}
			}
			else
			{

				if(TRUE == TcSpiResetReq_Cnt_M_lgc)
				{
					TcSpiTxMode_Cnt_M_enum = TCSPIMODE_RESET;
				}
				else
				{
					Tc_PrepSpiReceive();
					Tc_ProcSpiReceive(EnergyModeState_Cnt_T_enum, HwPosAuth_Uls_T_f32);
				}
				Tc_SpiCom(EnergyModeState_Cnt_T_enum);
			}
		}
	}
	
	if( 0U != NTCPrMainResets_Cnt_M_u08 )
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_MainResets, NTCPrMainResets_Cnt_M_u08, NTC_STATUS_FAILED);
	}
	else
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_MainResets, 0U, NTC_STATUS_PASSED);
	}
	
	TcActivePN_Cnt_T_u32 = ((uint32)t_TcActivePN_Cnt_M_u8[0] << 24) | 
							((uint32)t_TcActivePN_Cnt_M_u8[1] << 16) |
							((uint32)t_TcActivePN_Cnt_M_u8[2] << 8);
	TcActivePNVldCnt_Cnt_T_u32 = ((uint32)t_TcActivePNvldCnt_Cnt_M_u8[0] << 24) |
								  ((uint32)t_TcActivePNvldCnt_Cnt_M_u8[1] << 16) |
								  ((uint32)t_TcActivePNvldCnt_Cnt_M_u8[2] << 8);

	/* update outputs */
	Rte_IWrite_TurnsCounter_Per1_TurnsCntrValidity_Cnt_enum(TcSignalValidity_Cnt_M_enum);
	Rte_IWrite_TurnsCounter_Per1_TCMtrPosOffsMRF_Deg_f32(MRFTcMtrPosOffs_Deg_M_f32);
	Rte_IWrite_TurnsCounter_Per1_TcActivePNVldCnt_Cnt_u32 (TcActivePNVldCnt_Cnt_T_u32);
	Rte_IWrite_TurnsCounter_Per1_TcActivePN_Cnt_u32 (TcActivePN_Cnt_T_u32);
	CDD_TcFlashStatus_Cnt_G_u08 = TcFlashStatus_Cnt_M_u08;
	CDD_TCprocessing_Cnt_G_lgc = TCprocessing_Cnt_M_lgc;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Scom_PartNumSvc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PartNumSvc> of PortPrototype <TurnsCounter_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void TurnsCounter_Scom_PartNumSvc(UInt8 *TcPrgStatePtr)
#else
 *   void TurnsCounter_Scom_PartNumSvc(TcPartNumType *TcPrgStatePtr)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(UInt8, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr)
#else
FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_PartNumSvc(P2VAR(TcPartNumType, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TurnsCounter_Scom_PartNumSvc
 *********************************************************************************************************************/


	VAR(uint8, AUTOMATIC)  t_TcPrtNumSrvcOutput_Cnt_T_u8[D_TcPNArraySize_Cnt_U16];
	VAR(uint8, AUTOMATIC)  i;

	if ((TcReflashActive_Cnt_M_lgc==TRUE) && (TcFlashVerify_Cnt_M_lgc == FALSE))
	{
		t_TcPrtNumSrvcOutput_Cnt_T_u8[0] = (uint8)D_REFLASHVALUE_CHR;
		t_TcPrtNumSrvcOutput_Cnt_T_u8[1] = (uint8)D_REFLASHVALUE_CHR;
		t_TcPrtNumSrvcOutput_Cnt_T_u8[3] = (uint8)D_REFLASHVALUE_CHR;
		t_TcPrtNumSrvcOutput_Cnt_T_u8[4] = (uint8)D_REFLASHVALUE_CHR;
		t_TcPrtNumSrvcOutput_Cnt_T_u8[6] = (uint8)D_REFLASHVALUE_CHR;
		t_TcPrtNumSrvcOutput_Cnt_T_u8[7] = (uint8)D_REFLASHVALUE_CHR;
		t_TcPrtNumSrvcOutput_Cnt_T_u8[18] = (uint8)D_REFLASHVALUE_CHR;
		t_TcPrtNumSrvcOutput_Cnt_T_u8[19] = (uint8)D_REFLASHVALUE_CHR;
	}
	else
	{
		if (t_TcActivePNvldCnt_Cnt_M_u8[0] == 0U)
		{
			t_TcPrtNumSrvcOutput_Cnt_T_u8[0] = ConvertToASCII_HighByte(t_TcActivePN_Cnt_M_u8[0]);
			t_TcPrtNumSrvcOutput_Cnt_T_u8[1] = ConvertToASCII_LowByte(t_TcActivePN_Cnt_M_u8[0]);
		}
		else
		{
			t_TcPrtNumSrvcOutput_Cnt_T_u8[0] = ConvertToASCII_LowByte(t_TcActivePNvldCnt_Cnt_M_u8[0]);
			t_TcPrtNumSrvcOutput_Cnt_T_u8[1] = (uint8)D_PROCESSVALUE_CHR;
		}
		
		if (t_TcActivePNvldCnt_Cnt_M_u8[1] == 0U)
		{
			t_TcPrtNumSrvcOutput_Cnt_T_u8[3] = ConvertToASCII_HighByte(t_TcActivePN_Cnt_M_u8[1]);
			t_TcPrtNumSrvcOutput_Cnt_T_u8[4] = ConvertToASCII_LowByte(t_TcActivePN_Cnt_M_u8[1]);
		}
		else
		{
			t_TcPrtNumSrvcOutput_Cnt_T_u8[3] = ConvertToASCII_LowByte(t_TcActivePNvldCnt_Cnt_M_u8[1]);
			t_TcPrtNumSrvcOutput_Cnt_T_u8[4] = (uint8)D_PROCESSVALUE_CHR;
		}
		
		if (t_TcActivePNvldCnt_Cnt_M_u8[2] == 0U)
		{
			t_TcPrtNumSrvcOutput_Cnt_T_u8[6] = ConvertToASCII_HighByte(t_TcActivePN_Cnt_M_u8[2]);
			t_TcPrtNumSrvcOutput_Cnt_T_u8[7] = ConvertToASCII_LowByte(t_TcActivePN_Cnt_M_u8[2]);
		}
		else
		{
			t_TcPrtNumSrvcOutput_Cnt_T_u8[6] = ConvertToASCII_LowByte(t_TcActivePNvldCnt_Cnt_M_u8[2]);
			t_TcPrtNumSrvcOutput_Cnt_T_u8[7] = (uint8)D_PROCESSVALUE_CHR;
		}
		
		if (t_TcActivePNvldCnt_Cnt_M_u8[3] == 0U)
		{
			t_TcPrtNumSrvcOutput_Cnt_T_u8[18] = ConvertToASCII_HighByte(t_TcActivePN_Cnt_M_u8[3] & 0x1FU);
			t_TcPrtNumSrvcOutput_Cnt_T_u8[19] = ConvertToASCII_LowByte(t_TcActivePN_Cnt_M_u8[3] & 0x1FU);
		}
		else
		{
			t_TcPrtNumSrvcOutput_Cnt_T_u8[18] = ConvertToASCII_LowByte(t_TcActivePNvldCnt_Cnt_M_u8[3]);
			t_TcPrtNumSrvcOutput_Cnt_T_u8[19] = (uint8)D_PROCESSVALUE_CHR;
		}
	}

	t_TcPrtNumSrvcOutput_Cnt_T_u8[2] = (uint8)D_MAJMINREVDELIM_CHR;
	t_TcPrtNumSrvcOutput_Cnt_T_u8[5] = (uint8)D_MAJMINREVDELIM_CHR;
	t_TcPrtNumSrvcOutput_Cnt_T_u8[8] = (uint8)D_SUBSTRINGDELIM_CHR;
	t_TcPrtNumSrvcOutput_Cnt_T_u8[9] = ConvertToASCII_HighByte( t_TcImagePN_Cnt_M_u8[0] );
	t_TcPrtNumSrvcOutput_Cnt_T_u8[10] = ConvertToASCII_LowByte( t_TcImagePN_Cnt_M_u8[0] );
	t_TcPrtNumSrvcOutput_Cnt_T_u8[11] = (uint8)D_MAJMINREVDELIM_CHR;
	t_TcPrtNumSrvcOutput_Cnt_T_u8[12] = ConvertToASCII_HighByte( t_TcImagePN_Cnt_M_u8[1] );
	t_TcPrtNumSrvcOutput_Cnt_T_u8[13] = ConvertToASCII_LowByte( t_TcImagePN_Cnt_M_u8[1] );
	t_TcPrtNumSrvcOutput_Cnt_T_u8[14] = (uint8)D_MAJMINREVDELIM_CHR;
	t_TcPrtNumSrvcOutput_Cnt_T_u8[15] = ConvertToASCII_HighByte( t_TcImagePN_Cnt_M_u8[2] );
	t_TcPrtNumSrvcOutput_Cnt_T_u8[16] = ConvertToASCII_LowByte( t_TcImagePN_Cnt_M_u8[2] );
	t_TcPrtNumSrvcOutput_Cnt_T_u8[17] = (uint8)D_SUBSTRINGDELIM_CHR;

	for( i = 0U; i < D_TcPNArraySize_Cnt_U16; i++ ){
		(*TcPrgStatePtr)[i] = t_TcPrtNumSrvcOutput_Cnt_T_u8[i];
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_Scom_ResetTC
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTC> of PortPrototype <TurnsCounter_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TurnsCounter_Scom_ResetTC(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_Scom_ResetTC(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TurnsCounter_Scom_ResetTC
 *********************************************************************************************************************/

 TcSpiResetReq_Cnt_M_lgc = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnsCounter_TxConfirmation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SequenceEnd> of PortPrototype <Spi_Notification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TurnsCounter_TxConfirmation(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCounter_TxConfirmation(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TurnsCounter_TxConfirmation
 *********************************************************************************************************************/

TcInitComplete_Cnt_M_lgc = TRUE;
TCprocessing_Cnt_M_lgc = FALSE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_CD_TURNSCOUNTER_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define RTE_START_SEC_CD_TURNSCOUNTER_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/*****************************************************************************
 * Local Fn: CalcTCinitPos
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_CalcInitPos( VAR(float32,AUTOMATIC) MRFScomMtrPos_Deg_T_f32 )
{
	VAR(float32, AUTOMATIC) ScomToTc_Deg_T_f32;
	VAR(sint16, AUTOMATIC) ScomToTc_Oct_T_s16;
	
	/* calculate fields */
	ScomToTc_Deg_T_f32 = (MRFScomMtrPos_Deg_T_f32 + k_MtrPosToTcMechOffset_Deg_f32);
	
	ScomToTc_Oct_T_s16 = (sint16)((float32)(ScomToTc_Deg_T_f32 / D_45_DEGPOCT_F32));
	if ( ScomToTc_Deg_T_f32 < 0.0F )
	{
		ScomToTc_Oct_T_s16--;
	}
	TcInitMtrRevField_Cnt_M_b08 = (uint8)(((uint16)(ScomToTc_Oct_T_s16) >> 3) & D_EIGHTBITMSK_B08);
	TcInitMtrOctField_Cnt_M_b08 = (uint8)(ScomToTc_Oct_T_s16) & D_INITMTROCTMSK_CNT_B08;
	
}

/*****************************************************************************
 * Local Fn: RunDiags
 *****************************************************************************/
STATIC FUNC(TCDiagState_T, CD_TURNSCOUNTER_CODE) Tc_DiagFailure( void )
{
	VAR(uint8, AUTOMATIC) TcMtrOct_Cnt_T_u08;
	VAR(sint8, AUTOMATIC) TcMtrRev_Cnt_T_s08;
	VAR(float32, AUTOMATIC) TcRevAngle_Deg_T_f32;
	VAR(float32, AUTOMATIC) AdjAngle_Deg_T_f32;
	VAR(float32, AUTOMATIC) MinAngle_Deg_T_f32;
	VAR(float32, AUTOMATIC) MaxAngle_Deg_T_f32;
	VAR(TCDiagState_T, AUTOMATIC) TCDiagState_Cnt_T_enum;
	VAR(float32, AUTOMATIC) AbsMtrVel_MtrRadpS_T_f32;

	TCDiagState_Cnt_T_enum = DIAG_ACTIVE;

	/* capture inputs */
	pTcRxInfo_Cnt_M_str = (TcSpiRxInfo_T*)(TcSpiBuffer_Cnt_M_str.RxBuffer_Cnt_u08);
	TcMtrOct_Cnt_T_u08 = (*pTcRxInfo_Cnt_M_str).bits.MtrOct;
	TcMtrRev_Cnt_T_s08 = (sint8)((*pTcRxInfo_Cnt_M_str).bits.MtrRev);
	
	/* TC to Aligned Cumulative Motor Position Correlation Diagnostics */
	TcRevAngle_Deg_T_f32 = (float32)TcMtrRev_Cnt_T_s08 * D_360_DEGPREV_F32;
	AdjAngle_Deg_T_f32 = MtrPos_Deg_M_f32 + MRFTcMtrPosOffs_Deg_M_f32;
	MinAngle_Deg_T_f32 = t_TcToAcmpMin_Deg_f32[TcMtrOct_Cnt_T_u08] + TcRevAngle_Deg_T_f32;
	MaxAngle_Deg_T_f32 = t_TcToAcmpMax_Deg_f32[TcMtrOct_Cnt_T_u08] + TcRevAngle_Deg_T_f32;

	if( (AdjAngle_Deg_T_f32 < MinAngle_Deg_T_f32) ||
		(AdjAngle_Deg_T_f32 > MaxAngle_Deg_T_f32) )
	{
		TCvsMtrPosErrCnt_Cnt_M_u16 = DiagPStep_m(TCvsMtrPosErrCnt_Cnt_M_u16, k_TCvsMtrPosErr_Cnt_str);
		if(TRUE == DiagFailed_m(TCvsMtrPosErrCnt_Cnt_M_u16, k_TCvsMtrPosErr_Cnt_str))
		{
			NTCPrMainResets_Cnt_M_u08 |= D_TCVSMTRERRMSK_B08;
			TCDiagState_Cnt_T_enum = DIAG_FAILED;
		}
	}
	else
	{
		TCvsMtrPosErrCnt_Cnt_M_u16 = DiagNStep_m(TCvsMtrPosErrCnt_Cnt_M_u16, k_TCvsMtrPosErr_Cnt_str);
		if (TCvsMtrPosErrCnt_Cnt_M_u16 == 0U)
		{
			NTCPrMainResets_Cnt_M_u08 &= (uint8)(~D_TCVSMTRERRMSK_B08);
		}
	}

	AbsMtrVel_MtrRadpS_T_f32 = Abs_f32_m(MtrVel_MtrRadpS_M_f32);

	/* Back Emf Diagnostics */
	if(BemfDiagSts_Cnt_M_enum == NORESULT)
	{
		if((AbsMtrVel_MtrRadpS_T_f32 > k_MinBemfActive_MtrRadpS_f32) && (TotHighSampleCnt_Cnt_M_u16 <= k_MinTotHighSampleCnt_Cnt_u16))
		{
			if(((*pTcRxInfo_Cnt_M_str).bits.BemfActive) == FALSE)
			{
				HighMtrVelLowCnt_Cnt_M_u16++;
			}
			else
			{
				HighMtrVelHighCnt_Cnt_M_u16++;
			}

			TotHighSampleCnt_Cnt_M_u16 = HighMtrVelLowCnt_Cnt_M_u16 + HighMtrVelHighCnt_Cnt_M_u16;

			if(HighMtrVelHighCnt_Cnt_M_u16 >= k_MinHighMtrVelHighCnt_Cnt_u16)
			{
				BemfDiagSts_Cnt_M_enum = PASSED;
				NTCPrMainResets_Cnt_M_u08 &= (uint8)(~D_BEMFERRMSK_B08);
			}
			else if(TotHighSampleCnt_Cnt_M_u16 == k_MinTotHighSampleCnt_Cnt_u16)
			{
				BemfDiagSts_Cnt_M_enum = FAILED;
				NTCPrMainResets_Cnt_M_u08 |= D_BEMFERRMSK_B08;
				TCDiagState_Cnt_T_enum = DIAG_FAILED;
			}
			else
			{
				/* Do Nothing */
			}
		}
		else
		{
				/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}


	if((TCvsMtrPosErrCnt_Cnt_M_u16 == 0U) && (BemfDiagSts_Cnt_M_enum == PASSED))
	{
		TCDiagState_Cnt_T_enum = DIAG_PASSED;
	}

	return TCDiagState_Cnt_T_enum;
}

/*****************************************************************************
 * Local Fn: initACMPtoTCoffset
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_InitAcmpToTcOffset( void )
{
	VAR(uint8, AUTOMATIC) TcMtrOct_Cnt_T_u08;
	VAR(sint8, AUTOMATIC) TcMtrRev_Cnt_T_s08;
	P2VAR(TcSpiRxInfo_T, AUTOMATIC, AUTOMATIC) pTcRxInfo_Cnt_T_str;
	VAR(float32, AUTOMATIC) Ang_Deg_T_f32;
	VAR(sint8, AUTOMATIC) MtrPos_Rev_T_s08;
	
	/* capture inputs */
	pTcRxInfo_Cnt_T_str = (TcSpiRxInfo_T*)(TcSpiBuffer_Cnt_M_str.RxBuffer_Cnt_u08);
	TcMtrOct_Cnt_T_u08 = (*pTcRxInfo_Cnt_T_str).bits.MtrOct;
	TcMtrRev_Cnt_T_s08 = (sint8)((*pTcRxInfo_Cnt_T_str).bits.MtrRev);
	
	/* compute the offset */
	MtrPos_Rev_T_s08 = (sint8)((float32)(MtrPos_Deg_M_f32 / D_360_DEGPREV_F32));

	if ( MtrPos_Deg_M_f32 < 0.0F )
	{
		MtrPos_Rev_T_s08--;
	}
	
	Ang_Deg_T_f32 = MtrPos_Deg_M_f32 - ( (float32)(MtrPos_Rev_T_s08) * D_360_DEGPREV_F32 );
	
	MRFTcMtrPosOffs_Deg_M_f32 = ((float32) TcMtrRev_Cnt_T_s08 - (float32) MtrPos_Rev_T_s08) * D_360_DEGPREV_F32;
	
	if(Ang_Deg_T_f32  < t_TcToAcmpMin_Deg_f32[TcMtrOct_Cnt_T_u08])
	{
		MRFTcMtrPosOffs_Deg_M_f32 += D_360_DEGPREV_F32;
	}
	else
	{
		if(Ang_Deg_T_f32  > t_TcToAcmpMax_Deg_f32[TcMtrOct_Cnt_T_u08])
		{
			MRFTcMtrPosOffs_Deg_M_f32 -= D_360_DEGPREV_F32;
		}
	}
}

/*****************************************************************************
 * Local Fn: (update data error accumlator and TC data actions)
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_DataErr( void )
{
	/* update data fault status */
	TcSpiDataFltAcc_Cnt_M_u16 = DiagPStep_m(TcSpiDataFltAcc_Cnt_M_u16, k_TcSpiDataDiag_Cnt_str);
	if(TRUE == DiagFailed_m(TcSpiDataFltAcc_Cnt_M_u16, k_TcSpiDataDiag_Cnt_str))
	{
		NTCPrMainResets_Cnt_M_u08 |= D_PRIMARYERRMSK_B08;
		
		TcSpiResetReq_Cnt_M_lgc = TRUE;
		TcSpiDataValid_Cnt_M_lgc = FALSE;
	}
	else
	{
		TcSpiResetReq_Cnt_M_lgc = FALSE;
		TcSpiDataValid_Cnt_M_lgc = FALSE;
	}
	
	TcClrInfoBitsField_Cnt_M_b08 = 0U;
}

/*****************************************************************************
 * Local Fn: ChkInfoBits, Process Info Bits & Log Faults
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_InfoBits( uint8 InfoBits_Cnt_b08 )
{
	/* Process Info Bits & Log Faults */
	if( (InfoBits_Cnt_b08 & D_SPICOMMSK_B08) != (uint8)0U )
	{
		if((TCSPIMODE_TRANSPORT == TcSpiTxMode_Cnt_M_enum )||(TCSPIMODE_INITTCPOS == TcSpiTxMode_Cnt_M_enum ))
		{
			TcMOSIErrCnt_Cnt_M_u16 = DiagPStep_m(TcMOSIErrCnt_Cnt_M_u16, k_TcMOSIErr_Cnt_str);
			
			if(TRUE == DiagFailed_m(TcMOSIErrCnt_Cnt_M_u16, k_TcMOSIErr_Cnt_str))
			{
				(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_SpiComFlt, (InfoBits_Cnt_b08 & D_SPICOMMSK_B08), NTC_STATUS_FAILED);
			}
		}
		TcClrInfoBitsField_Cnt_M_b08 = D_CLRINFOCMDMSK_CNT_B08;
	}
	else
	{
		TcMOSIErrCnt_Cnt_M_u16 = DiagNStep_m(TcMOSIErrCnt_Cnt_M_u16, k_TcMOSIErr_Cnt_str);
		if (TcMOSIErrCnt_Cnt_M_u16 == 0U)
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_SpiComFlt, 0U, NTC_STATUS_PASSED);
		}
		TcClrInfoBitsField_Cnt_M_b08 = 0U;
	}
	
	if( (InfoBits_Cnt_b08 & D_HIQUSCMSK_B08) != (uint8)0U )
	{
		if( TRUE == AllowProcessTCErrs_Cnt_M_lgc )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_HighQuiescCur, (InfoBits_Cnt_b08 & D_HIQUSCMSK_B08), NTC_STATUS_FAILED);
		}
		TcClrInfoBitsField_Cnt_M_b08 = D_CLRINFOCMDMSK_CNT_B08;
	}
	else
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_HighQuiescCur, 0U, NTC_STATUS_PASSED);
	}
}

/*****************************************************************************
 * Local Fn: Process Error Bits & Log Faults
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_ErrorBits( VAR(uint8, AUTOMATIC) ErrHi_Cnt_T_u08,
													  VAR(uint8, AUTOMATIC) ErrLo_Cnt_T_u08 )
{
	VAR(uint8, AUTOMATIC) ErrLo1_Cnt_T_u08;

	ErrLo1_Cnt_T_u08 = 0U;


	if( ErrHi_Cnt_T_u08 != (uint8)0U )
	{
		if( TRUE == AllowProcessTCErrs_Cnt_M_lgc )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_MicroProcFlt, ErrHi_Cnt_T_u08, NTC_STATUS_FAILED);
		}
	}
	else
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_MicroProcFlt, 0U, NTC_STATUS_PASSED);
	}
	
	if( (ErrLo_Cnt_T_u08 & D_SENSPOSMSK_B08) == (uint8)0U )
	{
		TcSCMnMxErrCnt_Cnt_M_u16 = DiagNStep_m(TcSCMnMxErrCnt_Cnt_M_u16, k_TcSCMnMxErr_Cnt_str);
		if (TcSCMnMxErrCnt_Cnt_M_u16 == 0U)
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_SensorPosFlt, 0U, NTC_STATUS_PASSED);
		}
	}
	else{
		if( (ErrLo_Cnt_T_u08 & D_SENSPOS1MSK_B08) != (uint8)0U )
		{
			if( TRUE == AllowProcessTCErrs_Cnt_M_lgc )
			{
				ErrLo1_Cnt_T_u08 = ErrLo_Cnt_T_u08 & D_SENSPOS1MSK_B08;
				(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_SensorPosFlt, (ErrLo1_Cnt_T_u08), NTC_STATUS_FAILED);
			}
		}
		if( (ErrLo_Cnt_T_u08 & D_SCMNMXERRSMSK_B08) == D_SCMNMXERRSMSK_B08 )
		{
			if( (TRUE == TcAllowSCMnMxErrs_Cnt_M_lgc) && (TCV_VALID != TcSignalValidity_Cnt_M_enum) )
			{
				TcSCMnMxErrCnt_Cnt_M_u16 = DiagPStep_m(TcSCMnMxErrCnt_Cnt_M_u16, k_TcSCMnMxErr_Cnt_str);
				TcAllowSCMnMxErrs_Cnt_M_lgc = FALSE;

				if(TRUE == DiagFailed_m(TcSCMnMxErrCnt_Cnt_M_u16, k_TcSCMnMxErr_Cnt_str))
				{
					ErrLo1_Cnt_T_u08 |= D_SCMNMXERRSMSK_B08;
					(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_SensorPosFlt, (ErrLo1_Cnt_T_u08), NTC_STATUS_FAILED);
				}


			}
		}
		else
		{
			TcSCMnMxErrCnt_Cnt_M_u16 = DiagNStep_m(TcSCMnMxErrCnt_Cnt_M_u16, k_TcSCMnMxErr_Cnt_str);
		}
	}

	
	if( (ErrLo_Cnt_T_u08 & D_BATTERYMSK_B08) != (uint8)0U )
	{
		if( TRUE == AllowProcessTCErrs_Cnt_M_lgc )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_LowBattery, 1U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TurnCntr_LowBattery, 0U, NTC_STATUS_PASSED);
	}
}

/*****************************************************************************
 * Local Fn: Pre-Process SPI_Rx
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_PrepSpiReceive( void )
{
	P2VAR(TcSpiRxInfo_T, AUTOMATIC, AUTOMATIC) pTcRxInfo_Cnt_T_str;
	P2VAR(TcSpiTxInfo_T, AUTOMATIC, AUTOMATIC) pTcTxInfo_Cnt_T_str;
	VAR(uint8, AUTOMATIC) Index_T_u08;
	VAR(uint8, AUTOMATIC) SpiRC_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) Fault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PNValid_Cnt_T_lgc;
	
	/* capture inputs */
	pTcRxInfo_Cnt_T_str = (TcSpiRxInfo_T*)(TcSpiBuffer_Cnt_M_str.RxBuffer_Cnt_u08);
	pTcTxInfo_Cnt_T_str = (TcSpiTxInfo_T*)(TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08);
	
	/* check data validity */
	if(pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_STATUS] == (pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_STSCOPY] ^ D_EIGHTBITMSK_B08))
	{
		/* recover communication fault */
		TcSpiComFltAcc_Cnt_M_u16 = DiagNStep_m(TcSpiComFltAcc_Cnt_M_u16, k_TcSpiComDiag_Cnt_str);
		
		/* inspect redundant data */
		if( (pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_MTRPOS] == (pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_MTRPOSCOPY] ^ D_EIGHTBITMSK_B08)) &&
			(((*pTcTxInfo_Cnt_T_str).bits.TxCounter) == ((*pTcRxInfo_Cnt_T_str).bits.RxCounter)) )
		{

			SpiRC_Cnt_T_u08 = (uint8)(((*pTcTxInfo_Cnt_T_str).bits.TxCounter));
			PNValid_Cnt_T_lgc = Tc_ChkPN(SpiRC_Cnt_T_u08);

			if(PNValid_Cnt_T_lgc == TRUE)
			{
				if(1U == (*pTcRxInfo_Cnt_T_str).bits.Error)
				{
					if(1U == (*pTcRxInfo_Cnt_T_str).bits.Initialized)
					{
						Tc_DataErr();
					}
					else
					{
							/* two "if" conditions combined to avoid QAC warning about levels of nesting */
						if( (0U == (*pTcRxInfo_Cnt_T_str).bits.MtrOct) &&
							(0U == (*pTcRxInfo_Cnt_T_str).bits.MtrRev) &&
							(0U != (pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_ERRHI] |
									 pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_ERRLO])) )
						{
							TcSpiResetReq_Cnt_M_lgc = TRUE;
							TcSpiDataValid_Cnt_M_lgc = FALSE;
							TcSpiDataFltAcc_Cnt_M_u16 = DiagNStep_m(TcSpiDataFltAcc_Cnt_M_u16, k_TcSpiDataDiag_Cnt_str);
							if (TcSpiDataFltAcc_Cnt_M_u16 == 0U)
							{
								NTCPrMainResets_Cnt_M_u08 &= (uint8)(~D_PRIMARYERRMSK_B08);
							}
							Tc_ErrorBits(pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_ERRHI],
										 pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_ERRLO]);
							Tc_InfoBits(pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_INFO]);
							AllowProcessTCErrs_Cnt_M_lgc = FALSE;
							Tc_ProcPN(SpiRC_Cnt_T_u08);
							Tc_FlashStat();
						}
						else 
						{ 
							Tc_DataErr(); 
						}
					}
				}
				else if( (0U == pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_ERRHI]) &&
						 (0U == pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_ERRLO]) )
				{
					TcSpiResetReq_Cnt_M_lgc = FALSE;
					TcSpiDataValid_Cnt_M_lgc = TRUE;
					TcSpiDataFltAcc_Cnt_M_u16 = DiagNStep_m(TcSpiDataFltAcc_Cnt_M_u16, k_TcSpiDataDiag_Cnt_str);
					if (TcSpiDataFltAcc_Cnt_M_u16 == 0U)
					{
						NTCPrMainResets_Cnt_M_u08 &= (uint8)(~D_PRIMARYERRMSK_B08);
					}
					Tc_ErrorBits(pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_ERRHI],
								 pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_ERRLO]);
					Tc_InfoBits(pTcRxInfo_Cnt_T_str->Data_Cnt_u08[TCIDX_INFO]);
					AllowProcessTCErrs_Cnt_M_lgc = FALSE;
					Tc_ProcPN(SpiRC_Cnt_T_u08);
					Tc_FlashStat();
				}
				else 
				{ 
					Tc_DataErr(); 
				}
			}
			else 
			{ 
				Tc_DataErr(); 
			}
		}
		else 
		{ 
			Tc_DataErr(); 
		}
	}
	else
	{
		/* check for absence of communication fault */
		Fault_Cnt_T_lgc = TRUE;
		for(Index_T_u08 = 0U; (Index_T_u08 < D_SPIBUFFERSZ_CNT_U08) && (TRUE == Fault_Cnt_T_lgc); Index_T_u08++)
		{
			if(0U != pTcRxInfo_Cnt_T_str->Data_Cnt_u08[Index_T_u08])
			{ 
				Fault_Cnt_T_lgc = FALSE; 
			}
		}
		
		/* determine whether to reset the TC micro */
		if(TRUE == Fault_Cnt_T_lgc)
		{
			TcSpiComFltAcc_Cnt_M_u16 = DiagPStep_m(TcSpiComFltAcc_Cnt_M_u16, k_TcSpiComDiag_Cnt_str);
			
			if(TRUE == DiagFailed_m(TcSpiComFltAcc_Cnt_M_u16, k_TcSpiComDiag_Cnt_str))
			{
				TcSpiResetReq_Cnt_M_lgc = TRUE;
				TcSpiDataValid_Cnt_M_lgc = FALSE; 
			}
			else
			{
				TcSpiResetReq_Cnt_M_lgc = FALSE;
				TcSpiDataValid_Cnt_M_lgc = FALSE;
			}
			TcClrInfoBitsField_Cnt_M_b08 = 0U;
		}
		/* recover communication fault, investigate data fault */
		else
		{
			/* recover communication fault */
			TcSpiComFltAcc_Cnt_M_u16 = DiagNStep_m(TcSpiComFltAcc_Cnt_M_u16, k_TcSpiComDiag_Cnt_str);
			
			/* update data fault status */
			Tc_DataErr();
		}
	}
}

/*****************************************************************************
 * Local Fn: Process SPI_Rx
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_ProcSpiReceive( VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum,
														   VAR(float32, AUTOMATIC) HwPosAuth_Uls_T_f32)
{
	P2VAR(TcSpiRxInfo_T, AUTOMATIC, AUTOMATIC) pTcRxInfo_Cnt_T_str;
	VAR(uint16, AUTOMATIC) ProcSpiElpTime_mS_T_u16;
	VAR(float32, AUTOMATIC) MRFScomMtrPos_Deg_T_f32;
	VAR(TCDiagState_T, AUTOMATIC) TCDiagState_Cnt_T_enum;

	/* capture inputs */
	pTcRxInfo_Cnt_T_str = (TcSpiRxInfo_T*)(TcSpiBuffer_Cnt_M_str.RxBuffer_Cnt_u08);
	MRFScomMtrPos_Deg_T_f32 = Rte_IRead_TurnsCounter_Per1_ICMMtrPosMRF_Deg_f32();
	
	/* determine offset and validity */
	if(TRUE == TcSpiResetReq_Cnt_M_lgc)
	{
		if(TcSignalValidity_Cnt_M_enum == TCV_COMPUTING)
		{
			TcSignalValidity_Cnt_M_enum = TCV_INVALID;
			MRFTcMtrPosOffs_Deg_M_f32 = 0.0f;
		}
		(void) Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TcResetTimeout_mS_M_u32, &ProcSpiElpTime_mS_T_u16);
		if(ProcSpiElpTime_mS_T_u16 < k_TcResetTimeout_mS_u16)
		{
			TcSpiTxMode_Cnt_M_enum = TCSPIMODE_NORMAL;
		}
		else
		{
			TcSpiTxMode_Cnt_M_enum = TCSPIMODE_RESET;
		}
	}
	else
	{
		if(TRANSPORTATION != EnergyModeState_Cnt_T_enum)
		{
			if(TRUE == TcSpiDataValid_Cnt_M_lgc)
			{
				if(1U == (*pTcRxInfo_Cnt_T_str).bits.Initialized)
				{
					if(FALSE == AcmpToTcOffsetInit_Cnt_M_lgc)
					{
						Tc_InitAcmpToTcOffset();
						AcmpToTcOffsetInit_Cnt_M_lgc = TRUE;
						TcSpiTxMode_Cnt_M_enum = TCSPIMODE_NORMAL;
					}

					/* RunDiags */
					TCDiagState_Cnt_T_enum = Tc_DiagFailure();

					if(DIAG_FAILED == TCDiagState_Cnt_T_enum)
					{
						TcSignalValidity_Cnt_M_enum = TCV_INVALID;
						MRFTcMtrPosOffs_Deg_M_f32 = 0.0f;
						TcSpiTxMode_Cnt_M_enum = TCSPIMODE_RESET;
					}
					else
					{
						TcSignalValidity_Cnt_M_enum = TCV_VALID;
						TcSpiTxMode_Cnt_M_enum = TCSPIMODE_NORMAL;
					}
				}
				else
				{
					if( (D_HWPOSAUTHRESL_ULS_F32 > (Abs_f32_m(HwPosAuth_Uls_T_f32 - D_MAXCONF_ULS_F32))) ||
						(TRUE == RackCenterComplete_Cnt_M_lgc) )
					{
						if(Abs_f32_m(MRFScomMtrPos_Deg_T_f32) < D_SCOMMTRPOSLIMIT_DEG_F32)
						{
							Tc_CalcInitPos(MRFScomMtrPos_Deg_T_f32);
							TcSpiTxMode_Cnt_M_enum = TCSPIMODE_INITTCPOS;
						}
						else
						{
							TcSpiTxMode_Cnt_M_enum = TCSPIMODE_NORMAL;
						}
					}
					else
					{
						TcSignalValidity_Cnt_M_enum = TCV_INVALID;
						MRFTcMtrPosOffs_Deg_M_f32 = 0.0f;
						TcSpiTxMode_Cnt_M_enum = TCSPIMODE_NORMAL;
					}
				}
			}
			else
			{
				TcSpiTxMode_Cnt_M_enum = TCSPIMODE_NORMAL;
			}
		}
		else
		{
			TcSpiComFltAcc_Cnt_M_u16 = 0U;
			if(TCV_COMPUTING == TcSignalValidity_Cnt_M_enum)
			{
				TcSignalValidity_Cnt_M_enum = TCV_INVALID;
				MRFTcMtrPosOffs_Deg_M_f32 = 0.0f;
			}
			TcSpiTxMode_Cnt_M_enum = TCSPIMODE_TRANSPORT;
		}
	}
}

/*****************************************************************************
 * Local Fn: TC_VarInit
 *****************************************************************************/
 STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_VarInit( void )
 {

	TcSpiComFltAcc_Cnt_M_u16 = 0U;
	TcSpiTxRC_Cnt_M_u08 = 0xC0U;
	AcmpToTcOffsetInit_Cnt_M_lgc = FALSE;
	TcInitComplete_Cnt_M_lgc = FALSE;
										
	TcFlashStatus_Cnt_M_u08 &= D_TCALLSTATBITS_CNT_B8;
	TcFlashStatus_Cnt_M_u08 |= D_TCSETTSTINCBIT_CNT_B8;
	TcAllowSCMnMxErrs_Cnt_M_lgc = TRUE;
	
	/*** Reset Active Part Number Variables sub-function ***/
	t_TcActivePN_Cnt_M_u8[0] = t_TcImagePN_Cnt_M_u8[0];
	t_TcActivePN_Cnt_M_u8[1] = t_TcImagePN_Cnt_M_u8[1];
	t_TcActivePN_Cnt_M_u8[2] = t_TcImagePN_Cnt_M_u8[2];
	t_TcActivePN_Cnt_M_u8[3] = t_TcImagePN_Cnt_M_u8[3];

	t_TcActivePNvldCnt_Cnt_M_u8[0] = k_TcActivePNvldChks_Cnt_u08;
	t_TcActivePNvldCnt_Cnt_M_u8[1] = k_TcActivePNvldChks_Cnt_u08;
	t_TcActivePNvldCnt_Cnt_M_u8[2] = k_TcActivePNvldChks_Cnt_u08;
	t_TcActivePNvldCnt_Cnt_M_u8[3] = k_TcActivePNvldChks_Cnt_u08;

}

/*****************************************************************************
 * Local Fn: TC_PSCM-ActiveMonitor
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_ReInit(VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum)
{
	
	/* update variables */
	Tc_VarInit();
	
	if(TRANSPORTATION != EnergyModeState_Cnt_T_enum)
	{
		TcSpiTxMode_Cnt_M_enum = TCSPIMODE_NORMAL;
	}
	else
	{
		TcSpiTxMode_Cnt_M_enum = TCSPIMODE_TRANSPORT;
	}
	
	(void) Rte_Call_SystemTime_GetSystemTime_uS_u32(&TcResetDelayStart_uS_M_u32);
	(void) Rte_Call_SystemTime_GetSystemTime_mS_u32(&TcResetTimeout_mS_M_u32);
}

/*****************************************************************************
 * Local Fn: TC_Reset
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_Reset(VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum)
{
	VAR(uint32, AUTOMATIC) StartTime_T_u32;
	VAR(uint16, AUTOMATIC) ElapsedTime_T_u16;

	/* hold reset pin active */
	(void) Rte_Call_TcMCLR_OP_SET(STD_HIGH);
	(void) Rte_Call_SystemTime_GetSystemTime_uS_u32(&StartTime_T_u32);

	do
	{
		(void) Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(StartTime_T_u32,&ElapsedTime_T_u16);
	}
	while(ElapsedTime_T_u16 < D_MCLRDELAY_US_U16);
	
	/* release reset pin */
	(void) Rte_Call_TcMCLR_OP_SET( STD_LOW );
	
	/* update variables */
	TcSpiResetReq_Cnt_M_lgc = FALSE;
	Tc_ReInit(EnergyModeState_Cnt_T_enum);
}

/*****************************************************************************
 * Local Fn: Check Turns Counter Part Numbers
 *****************************************************************************/
STATIC FUNC(boolean, CD_TURNSCOUNTER_CODE) Tc_ChkPN(VAR(uint8, AUTOMATIC) TCSpiRC_Cnt_T_u08)
{
	VAR(uint8, AUTOMATIC) returnval_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) TcRxSwPN_Cnt_T_u08;

	TcRxSwPN_Cnt_T_u08 = (uint8)((*pTcRxInfo_Cnt_M_str).Data_Cnt_u08[TCIDX_PARTNUM]);

	if( t_TcActivePNvldCnt_Cnt_M_u8[TCSpiRC_Cnt_T_u08] == 0U )	
	{
		if( t_TcActivePN_Cnt_M_u8[TCSpiRC_Cnt_T_u08] == TcRxSwPN_Cnt_T_u08 )
		{
			returnval_Cnt_T_u08 = TRUE;
		}
		else
		{
			returnval_Cnt_T_u08 = FALSE;
		}
	}
	else
	{
		returnval_Cnt_T_u08 = TRUE;
	}

	return returnval_Cnt_T_u08;

}

/*****************************************************************************
 * Local Fn: Process Turns Counter Part Numbers
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_ProcPN(VAR(uint8, AUTOMATIC) TCSpiRC_Cnt_T_u08)
{
	VAR(uint8, AUTOMATIC) TcRxSwPN_Cnt_T_u08;

	TcRxSwPN_Cnt_T_u08 = (uint8)((*pTcRxInfo_Cnt_M_str).Data_Cnt_u08[TCIDX_PARTNUM]);

	if ( t_TcActivePNvldCnt_Cnt_M_u8[TCSpiRC_Cnt_T_u08] != 0U )
	{
		if( t_TcActivePN_Cnt_M_u8[TCSpiRC_Cnt_T_u08] == TcRxSwPN_Cnt_T_u08 )	
		{
			t_TcActivePNvldCnt_Cnt_M_u8[TCSpiRC_Cnt_T_u08]--;
		}
		else
		{
			if( t_TcActivePNvldCnt_Cnt_M_u8[TCSpiRC_Cnt_T_u08] < k_TcActivePNvldChks_Cnt_u08 )
			{
				t_TcActivePNvldCnt_Cnt_M_u8[TCSpiRC_Cnt_T_u08]++;
			}
			else
			{
				t_TcActivePNvldCnt_Cnt_M_u8[TCSpiRC_Cnt_T_u08] = k_TcActivePNvldChks_Cnt_u08;
				t_TcActivePN_Cnt_M_u8[TCSpiRC_Cnt_T_u08] = TcRxSwPN_Cnt_T_u08;
			}
		}
	}
}

/*****************************************************************************
 * Local Fn: Process TC Status
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_FlashStat(void)
{

	if( 0U == (*pTcRxInfo_Cnt_M_str).bits.Err_Flash )	
	{	if( 1U == (*pTcRxInfo_Cnt_M_str).bits.Info_FlashChkProgress )
		{
		TcFlashStatus_Cnt_M_u08 &= D_TCHOLDSTATBITS_CNT_B8;
		}
	}
	else
	{
		TcFlashStatus_Cnt_M_u08 = D_TCERRSTATBITS_CNT_B8;
	}

}

/* Get the the decimal tens place value of an input, and convert it to ASCII */
STATIC FUNC(uint8, CD_TURNSCOUNTER_CODE) ConvertToASCII_HighByte( VAR(uint8, AUTOMATIC)  InputData )
{
	VAR(uint8, AUTOMATIC) returnValue;

	/* If the value is >= 100, it cannot be converted to two ASCII characters. */
	if(InputData > 0x63U )
	{
		returnValue = (uint8)D_UNKNOWNVALUE_CHR;
	}
	else
	{
		returnValue = (((uint8)(InputData/10U)) + D_ASCIINUMOFFSET_CHR);
	}

return returnValue;
}

/* Get the ones decimal ones place of a input value, and convert to ASCII */
STATIC FUNC(uint8, CD_TURNSCOUNTER_CODE) ConvertToASCII_LowByte( VAR(uint8, AUTOMATIC)  InputData )
{
	VAR(uint8, AUTOMATIC) returnValue;

	/* If the value is >= 100, it cannot be converted to two ASCII characters. */
	if(InputData > 0x63U )
	{
		returnValue = (uint8)D_UNKNOWNVALUE_CHR;
	}
	else
	{
		returnValue = (uint8)((InputData % 10U) + D_ASCIINUMOFFSET_CHR);
	}

return returnValue;
}


/*****************************************************************************
 * Local Fn: Initiate SPI_Tx
 *****************************************************************************/
STATIC FUNC(void, CD_TURNSCOUNTER_CODE) Tc_SpiCom( VAR(EnergyModeStateType, AUTOMATIC) EnergyModeState_Cnt_T_enum )
{	
	VAR(TcSpiTransmitMode_T, AUTOMATIC) Mode_Cnt_T_enum;
	
	/* capture inputs */
	MtrPos_Deg_M_f32 = Rte_IRead_TurnsCounter_Per1_AlignedCumMtrPosMRF_Deg_f32();
	MtrVel_MtrRadpS_M_f32 = Rte_IRead_TurnsCounter_Per1_MotorVelMRF_MtrRadpS_f32();
	Mode_Cnt_T_enum = TcSpiTxMode_Cnt_M_enum;
	
	/* determine what to transmit */
	switch(Mode_Cnt_T_enum)
	{
	case TCSPIMODE_RESET:
		Tc_Reset(EnergyModeState_Cnt_T_enum);
	break;
	case TCSPIMODE_INITTCPOS:
		TcSpiTxRC_Cnt_M_u08 += D_RCOFFSET_CNT_U08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[0] = TcSpiTxRC_Cnt_M_u08 + TcClrInfoBitsField_Cnt_M_b08 + D_INITCMDMSK_CNT_B08 + TcInitMtrOctField_Cnt_M_b08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[1] = TcInitMtrRevField_Cnt_M_b08;
	break;
	case TCSPIMODE_TRANSPORT:
		TcSpiTxRC_Cnt_M_u08 += D_RCOFFSET_CNT_U08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[0] = TcSpiTxRC_Cnt_M_u08 + TcClrInfoBitsField_Cnt_M_b08 + D_TRNSMODECMDMSK_CNT_B08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[1] = (uint8)0x00;
	break;
	default:
		TcSpiTxRC_Cnt_M_u08 += D_RCOFFSET_CNT_U08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[0] = TcSpiTxRC_Cnt_M_u08 + TcClrInfoBitsField_Cnt_M_b08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[1] = (uint8)0x00;
	break;
	}
	
	if(TCSPIMODE_RESET != Mode_Cnt_T_enum)
	{
		/* update all common bytes */
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[2] = Rte_Pim_EOLTurnsCntrCals()->TcEolSineOffset_Cnt_u08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[3] = Rte_Pim_EOLTurnsCntrCals()->TcEolCosineOffset_Cnt_u08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[4] = Rte_Pim_EOLTurnsCntrCals()->TcEolSin2CosGain_Cnt_u08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[5] = Rte_Pim_EOLTurnsCntrCals()->TcEolSinVsCosMin_Cnt_u08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[6] = Rte_Pim_EOLTurnsCntrCals()->TcEolSinVsCosMax_Cnt_u08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[7] = Rte_Pim_EOLTurnsCntrCals()->TcEolCalChksm_Cnt_u08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[8] = TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[0] ^ D_EIGHTBITMSK_B08;
		TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[9] = TcSpiBuffer_Cnt_M_str.TxBuffer_Cnt_u08[1] ^ D_EIGHTBITMSK_B08;
		
		/* Initiate the asynchronous Spi transfer */
		if(RTE_E_Spi_Seq_SPI_SEQ_PENDING != Rte_Call_TcDataSeq_GetSequenceResult())
		{
			TCprocessing_Cnt_M_lgc = TRUE;
			(void) Rte_Call_TcDataSeq_AsyncTransmit();
		}
	}
}

#define RTE_STOP_SEC_CD_TURNSCOUNTER_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
