/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComInput.c
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComInput/autosar
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Tue Oct 25 15:26:31 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComInput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          EA3#111 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Fri Sep 20 17:03:15 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 02/10/11   4       BDO        Added Rx signal callback functions
 * 02/10/11   5       BDO        Added Rx signal diagnostics
 * 02/15/11   6       BDO        Anomaly 2030
 * 02/15/11   7       BDO        Anomaly 2070
 * 02/15/11   8       BDO        Anomaly 2071
 * 02/15/11   9       BDO        Anomaly 2072
 * 02/15/11   10      BDO        Anomaly 2073
 * 02/15/11   11      BDO        Anomaly 2082
 * 02/25/11   12      BDO        TemplateUpdate
 * 02/25/11   13      BDO        Anomaly 2083 - Add VIN request logic
 * 03/30/11   14      BDO		 Template Update for inputs from Ap_CodingInterface
 * 03/30/11   15      BDO		 Update QU_V_VEH_COG diagnostic 													CR3926
 * 03/30/11   16      BDO		 Add SrlComInDfltVehSpd_Cnt_lgc output 												CR3956
 * 04/06/11   17      BDO		 Add DfltVehSpd VehConfig enable switch, remove CodingInterface input 				CR3963
 * 04/06/11   18      BDO		 Add threshold calibrations for missing message diagnostics 						CR3925
 *								 Corrected VehCfgDfltVehSpd CAL name format.
 * 04/13/11   19      JJW        Cross Check Diag Support Added
 * 04/15/11   20      BDO        Initialize DefaultVehSpd_Cnt_lgc
 * 04/15/11   21      JJW        Template Update for NSS signal input to Veh Spd Rx runnable
 * 04/15/11   22      YY         Added vehicle standstill cross-check.                                          	CR4014
 * 04/28/11	  23      BDO        Anomaly 2254 - disable VIN request after loss of msg fault is set					CR4092
 * 05/02/11	  24      JJW        Corrected Typo for Cross Check Vehicle Speed Assignment 
 * 05/26/11	  27      JJW        Template changes for Park Assist and Veh Dyn  
 * 05/26/11	  28      JJW        Template changes for Park Assist and Veh Dyn Missing Message runnable and 
 *                               Scomm service defeat input.
 * 05/31/11	  29      JJW        RTE access changes for VEH_COG and VEH_NSS 
 * 06/03/11   31.1.1  JJW        Stub functions to allow build, This version to be merged with final implementation
 * 06/03/11   32	  BDO        Changes to support ParkAssist and DrivingDynamics Rx signals                   	CR3611
 * 06/04/11   33	  BDO        Changes to support Supply Power Limit signal SPEC_PWR_EL_EPS_MAX 
 * 06/04/11   34	  LWW        Framework update for coding switch changes
 * 06/06/11   35	  BDO        VehSpd and PrkAst/DrvDyn coding switch override updates							CR4199
 * 06/06/11   36	  BDO        Updates to support the SrlCom Rx message defeat and VehSpd override EPSDiagSrvc	CR4188
 * 06/07/11   37      JJW        Template Changes for Error Masking signal 
 * 06/07/11   38      JJW        Template Changes for Vehicle spped override Scom port access to DfltVehSpd
 * 06/07/11   39      BDO        Move all EPS DiagSrvcs VehSpd overrides to the ManualVehSpd Scomm function
 * 06/07/11   40      BDO        Added Under/Over voltage Error masking signal to Per1 - Template to be updated
 * 06/14/11   42      JJW        Update, per SER, to set SrlComPrkAstEnable_Cnt_lgc FALSE when coding disables the Park Assist Intf
 * 08/02/11   43      JJW        BAC3.0 Integration required signal group changes
 * 08/02/11   44      BDO        Updates for Hand-wheel RevOffset message OFFS_QUAD_EPS
 * 08/02/11   45      BDO        Update RevOffset CRC ID
 * 08/02/11   46      BDO        Add local constant for RevOffset INVALID flag, remove global. 
 *                               Add OpTrqOverlay and Qualifier signal reads removed during BAC 3.0 integration.
 * 09/26/11   47      BDO        Add E2E protection to RevOffset message OFFS_QUAD_EPS 
 * 09/27/11   48      BDO        Add V_VEH PDU signals to signal group SG_V_VEH 
 * 09/28/11   49      BDO        Add E2E protection for V_VEH, TAR_QTA_STRMOM, and TAR_STMOM PDUs
 * 09/29/11   50      BDO        Remove module level CRCErrorCounter var and replace with passed parameter in CRCAliveCntDiag()
 * 10/13/11   51      BDO   	 Add Appl_DetEntryCallout() to ignore DET for PDU that should be ignored.
 * 10/14/11   52      BDO   	 Apply polarity cal, k_SComRevOffsetPol_Cnt_s08, to RevOffset - anomaly 2550.
 * 10/23/11	  53      KJS        Apply changes created by Bobby for turns counter update. CR4590
 * 10/28/11	  54      BDO        Add COMM_HALT Flexray diagnostic. Cleanup turns counter update added in prior task
 * 11/15/11   55      BDO        Correct SVC transmit message used to request the VIN - anomaly 2529
 * 11/29/11   56      SMW        Removed NSS cross check on vehicle speed for the Cross Check Interrupt
 * 12/02/11   58      BDO        Change Nxtr NTCs from 8 to 12 bits. 			CR4718
 * 01/18/12   59      BDO        Implement changes made in I-310 bug fix.
 * 01/18/12   60      BDO        Change RxNewSTVEHCONMsg_Cnt_M_lgc. 
 * 01/18/12   61      BDO        Update ST_VEH_CON crank logic in Per1 and RxSTKL15N 
 * 02/27/12   62      JJW        Corrected Signal name on Rte_Write_SrlComVehNearStandstill_Cnt_u08 to support integration of
 *                                ParkAstEnbl_BMW CBD
 * 03/06/12   63      BDO        Change format of SVC VIN request ID in D_VINREQID_CNT_U16 - anomaly 2777
 * 04/13/12   64      BDO        Anomaly 2918 - CR5217
 * 04/13/12   65      BDO        Anomaly 3180, 3203 - Add ClearDiagCounters() call to StartUp masking logic in SrlComInput_Per1
 * 04/26/12   67      JJW        New ParkAssist and Drive Dynamics interface enable signals per SER
 * 06/07/12   68      BDO        Apply EPS Safety Limit calibration to FinalOpTrqOvRqst_MtrNm_M_f32 per SER - CR5618
 * 06/08/12   69      BDO        New coding enable switches per SER 9C
 * 06/13/12   70      BDO        Update COMM_HALT diagnostic to use ApplFr_CBK_CcErrorEvent to check CC errors - CR5429
 * 06/13/12   71      BDO        Update Default Vehicle Speed Handling as Defined in SER 9C - CR5654
 * 06/14/12   72      BDO        Limit SupplyPowerLimit signal SPEC_PWR_EL_EPS_MAX to 0-2000 watts per FDD-SF19A ver006 which expects a unsigned number.
 * 06/14/12   73      BDO        Remove SrlComInDfltVehSpd_Cnt_lgc write from RxVehSpd runnable
 * 06/18/12   74      BDO        Add Fr_VCheckErrorState() periodic call to poll Communication Controller's error state and NTC_Num_FlexrayCommunicationError - CR5429
 * 07/03/12   75      BDO        Add Torque Overlay Debounce function as defined in SER 9C - CR5803
 * 07/19/12   76      BDO        SER 9E - Remove 0x0A as a valid QU_V_VEH_COG value when determining InvalidVehSpdQual_Cnt_M_lgc - CR5871
 * 08/21/12   77      BDO        Anomaly 3470. Loss of Synch customer DTC not setting. SEE TODO below: related to pending DiagMgr change.
 * 08/29/12   78      BDO        Reverse changes made under CR5871 (Rev 76). Add 0x0A as a VALID QU_V_VEH_COG value.
 * 09/29/12   79      KJS        Added RQ_SW_SU_DRDY for tuning select.
 * 			  79.1.1  KJS        Added RQ_SW_SU_DRDY for tuning select.
 * 			  79.1.2  KJS        Added FRVldVehSpd output for anomaly 3788 correction.
 * 			  80	  JJW		 Removed CrossCheck include 
 * 			  81	  JJW		 DiagMgr FDD37B 001.16 integration 
 * 10/16/12	  82	  KJS		 Merge of i350 and i390 paths. 
 * 10/16/12	  83	  BDO		 Updates for SrlComInput and SrComInput2 QM and ASIL_D application split. CR 6627
 * 10/31/12   79.1.3  KJS        SER changes to ST_DRV_VEH signal.
 * 11/13/12   84	  KJS        Merge of i390/i350 paths for MSA integration.
 * 01/11/13   86,87	  KJS        Implementation of STEA_OFFS message, anomaly 4208.
 * 03/06/13	  88	  KJS		 SER updates and QAC corrections.
 * 04/11/13	  89	  KJS		 Anomaly 4499 correction for tuning select.
 * 04/12/13	  90	  KJS		 Peer review updates for tuning select changes. 
 * 06/17/13	  91	  KJS		 Anomaly 5088 correction. 
 * 09/14/13	  92	  KJS		 Added support for IgnOff Time per SER 12D
 * 08/29/14	  94	  KJS		 Anomaly 6773 correction for missing or invalid VIN and VehCfg coding errors
 * 02/13/15   95	  ABS		 ICR 4756 Added limits for SPEC_PWR_EL_EPS_MAX for different value of the signal
 * 04/24/15   96	  KJS		 Corrected anomaly EA3#1065
 * 09/15/15   97      ABS        EA3#2824 correction - Updated D_NTCFAILED_CNT_U08 to 1u
 * 11/11/15   98      ABS		 Added Rx signal Aclny_Cog
 * 03/09/16   101     ABS		 QAC correction
 * 05/26/16   102     ABS		 Updated for SCIR 002A																	7977
 * 06/15/16   103     ABS		 Updated for SCIR 002A																	7977
 * 06/29/16   104     ABS		 Updated NTCs for ACLNY_MASSCNTR message     											7977
 * 08/31/16   107     ABS		 Anomaly correction for Autonomic mode      									   EA3#10457
 * 10/25/16	  109     ABS		 ST_DIAG_OBD_3_DRDY (Msg ID 248.10.32)not transmitted                              EA3#11915
 * 05/24/17	  110	  JK		 Add signal CTR_ERRM_BN_U range check											   EA3#15777_EA3#15440
 * 05/31/17	  111	  ABS		 updated after review															   EA3#15777_EA3#15440
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
  ALIV_COU_V
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Alive_Zähler_Geschwindigkeit [1] mit den Parametern AliveSpeed [1].

  CRC8
    Standartabsicherung Apllikations-CRC.

  CRC_V_VEH
    Standartabsicherung Apllikations-CRC.
     
     				Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse CRC_Geschwindigkeit_Fahrzeug [1] mit den Parametern ChecksumSpeedCRC [1].

  DT_NO_VECH_1
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Nummer_Fahrgestell_1 [1] mit den Parametern ChassisNumber1 [1].

  DT_NO_VECH_2
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Nummer_Fahrgestell_2 [1] mit den Parametern ChassisNumber2 [1].

  DT_NO_VECH_3
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Nummer_Fahrgestell_3 [1] mit den Parametern ChassisNumber3 [1].

  DT_NO_VECH_4
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Nummer_Fahrgestell_4 [1] mit den Parametern ChassisNumber4 [1].

  DT_NO_VECH_5
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Nummer_Fahrgestell_5 [1] mit den Parametern ChassisNumber5 [1].

  DT_NO_VECH_6
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Nummer_Fahrgestell_6 [1] mit den Parametern ChassisNumber6 [1].

  DT_NO_VECH_7
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Nummer_Fahrgestell_7 [1] mit den Parametern ChassisNumber7 [1].

  ID_FN_INQY
    Enthält den Identifier der angefragten Nachricht. 
     				Es sind nur die Identifier erlaubt, die als anfragbare Nachrichten definiert sind.

  MILE_KM
    Automatisch generiert (Migration 2004-10-30)
     
     				Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Wegstrecke_Kilometer [1] mit den Parametern MileageKM [2].

  ST_ILK_ERRM_FZM
    Automatisch generiert (Migration 2004-10-30)
     
     				Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Status_Sperre_Fehlerspeicher_FZM [2] mit den Parametern ErrorMemoryLock [1].

  V_VEH_COG
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenführung der Signalklasse Geschwindigkeit_Fahrzeug_Schwerpunkt [2] mit den Parametern CarSpeedExt [1].


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration


 Runnable Entities:
 ==================
  SrlComInput_TRGD_PaDrvDynLoss
    This runnable is triggered when the Park Assist/Drivign Dynamics frame is not received.  ON frame contains both interfaces for park assist and drivingn dynamics, so only a single runnable is required for this system.  This may mean that multiple DTC's are set when a fault is detected.

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComInput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_SrlComInput_Cfg.h"
#include "Com.h"
#include "Com_Cbk.h"
#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CheckSums.h"
#include "SystemTime.h"
#include "E2E_P01.h"

#include "Det.h"
#include "Fr_Cfg.h"
#include "Fr_ERay.h"
#include "Dem.h"

#include "Fr_GeneralTypes.h"
#include "Fr_Priv.h"

#include "SysTimeClient.h"
#include "SysTimeClient_Wrapper.h"

#include "CDD_Data.h"

/* DetEntryCallout */
#define D_FRTPMODULEID_CNT_U08              0x24U /* FrTp header */			
#define D_FRTPMAINFUNCTSRVCID_CNT_U08    	0x10U /* FrTp header */
#define D_FRTPEIGNOREDRXPDU_CNT_U08			0x10U /* FrTp_Extension header */

/* Fault Counters (Invalid,Missing,AliveCnt,Error) */
#define D_INVALIDALIVECOUNT_CNT_U08			15U
#define D_RXMSGINVALID_CNT_U08				3U
#define D_ALIVECOUNTFAULT_CNT_U08			3U
#define D_ERRORCOUNTFAULT_CNT_U08			3U

#define D_LOSTMSGPSTEP_CNT_U16				5U
#define D_RXMSGNSTEP_CNT_U16				1U

/* Mask Bits */
#define D_LOWNIBBLEMASK_CNT_U16				0x0FU
#define D_DRVVEHINITBITSMASK_CNT_U16		0xE0U			
#define D_DRVVEHSTATUSBITSMASK_CNT_U16		0x1FU

/* VIN RequestID is 0x380 */
#define D_VINREQID_CNT_U16					0x8003U /*send in opposite format not as 0x0380*/
#define D_BROADCASTREQUEST_CNT_U08			0x01U
#define D_IDFNINQY_CNT_B16					0x01U

/* Power Limiting Signal */
#define D_PWRLMTOFFSET_CNTS_U08				120U
#define D_PWRLMTSCALE_WATTSPCNT_U08			100U
#define D_PWRLMTLOLMT_WATTS_F32				0.0F
#define D_PWRLMTHILMT_WATTS_F32				2000.0F
#define D_CEPSPWRMAX_WATTS_F32				1440.0F

/* STEA_OFFS */
#define D_USESTEAPNIOFFS_CNT_U08			0U /* Per SER 10B, 0 = Use STEA value, 1 = assume fixed value */
#define D_STEAPNIOFFS_FIXEDZERO_HWDEG_F32 	0.0F
#define D_STEAPNIOFFS_LOLMT_HWDEG_F32		(-45.0F)
#define D_STEAPNIOFFS_HILMT_HWDEG_F32		45.0F
#define D_STEAPNIOFFS_OFFSET_ULS_F32		(-45.0F)
#define D_STEAPNIOFFS_CNTTOHWDEG_ULS_F32	0.021994F

typedef enum {
	SteaPniOffs_NotAvail_Cnt_enum	= CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar,
	SteaPniOffs_FuncRetErr_Cnt_enum	= CxFFE_Funktion_meldet_Fehler,
	SteaPniOffs_Invalid_Cnt_enum	= CxFFF_Signal_unbefuellt
} SteaPniOffsValue;

/* GlobalVoltage Error Mask Signal */
#define D_UNDERVLTGNORMOP_CNT_U08           0U
#define D_CTRERRMLOWERMASK_CNT_U08			0x01U
#define D_CTRERRMUPPERMASK_CNT_U08			0x07U

#define D_RESETDIAGCOUNTERS_CNT_U08			0U

#define D_CURRSYSTIMEINVLD_SEC_U32			0xFFFFFFFFUL


/* Tuning Select */
#define D_TUNINGSELSPORTPLUS_CNT_U16			0x1U
#define D_TUNINGSELSPORT_CNT_U16				0x2U
#define D_TUNINGSELBASESVT_CNT_U16				0x3U
#define D_TUNINGSELUNAVIALABLE_CNT_U16			0xDU
#define D_TUNINGSELERROR_CNT_U16				0xEU
#define D_TUNINGSELINVALID_CNT_U16				0xFU

#define D_NTCFAILED_CNT_U08						0x01u

#define SRLCOMINPUT_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) CTRERRMUpateTimer_Cnt_M_u32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) PrevSteaPinOffs_HwDeg_M_f32;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) VehSpdLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) TarStMomLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) TarQtaStMomLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) RevOffsetLossFltCounter_Cnt_M_u16;

STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) SteaPniOffsLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) SteaPniOffsInvalidCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) SteaPniOffsErrorCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) SteaPniOffsErrorRecovery_Cnt_M_u16;


STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) FZZSTDLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) MileKMLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) EnergDgrDrdyLossFltCounter_Cnt_M_u16;

STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) SrlComSVCTxReq_Cnt_M_b16;

STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) VINLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) VINErrorRecovery_Cnt_M_u16;

STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) TuningSelLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) AclnyMassCntrLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) VyawVehLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ConVehLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) CtrVibStwDispLossFltCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) StCengLossFltCounter_Cnt_M_u16;

STATIC VAR(New_Coding_79, AP_SRLCOMINPUT_VAR_NOINIT) PrevTuningSelVal_Cnt_M_enum;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_8
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) VINVldCounter_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) InvldTuningSelCntr_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) InvldTuningSelDataCntr_Cnt_M_u8;

STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) InvldEPSVibPatternCntr_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) InvldEPSVibInteLvlCntr_Cnt_M_u8;

STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) HaptcFbIntenNrValidValue_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) HaptcFbPatNrValidValue_Cnt_M_u08;

STATIC VAR(New_Coding_71, AP_SRLCOMINPUT_VAR_NOINIT) AutonomicPattern_Cnt_M_u08;
STATIC VAR(New_Coding_75, AP_SRLCOMINPUT_VAR_NOINIT) AutonomicIntensity_Cnt_M_u08;

STATIC volatile VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) IgnoreDET_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) InvldMaxISpecEpsCntr_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) UndefMaxISpecEpsCntr_Cnt_M_u8;

/* Variable to hold the previous value of the Max I Spec EPS signal */
STATIC VAR(New_Coding_94, AP_SRLCOMINPUT_VAR_NOINIT) RxMaxISpecEpsPrevVal_Cnt_M_u08;

#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"/* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) SysTimeLockout_Cnt_M_lgc;

STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) HaptcFbIntenSigVld_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) HaptcFbPatSigVld_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) AutonomicModeActive_Cnt_M_lgc;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(RT_VIN_NO_VECH, AP_SRLCOMINPUT_VAR_NOINIT) RxVIN_Cnt_M_Str;
STATIC volatile VAR(Fr_VErrorStatusType, AP_SRLCOMINPUT_VAR_NOINIT) FrErrorStatus_Cnt_D_str;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */

#define SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) StrdSysTime_Sec_M_u32;
#define SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_32
#include "MemMap.h" /* PRQA S 5087 */


STATIC INLINE FUNC(uint16, AP_SRLCOMINPUT_CODE) LostMsgDiag( VAR(uint16, AUTOMATIC) FaultCounter, 
															 VAR(uint16, AUTOMATIC) Threshold,
													         VAR(uint16, AUTOMATIC) NTC,
													         VAR(uint8, AUTOMATIC) NTCParam);

STATIC INLINE FUNC(uint16, AP_SRLCOMINPUT_CODE) RxMsgDiag(   VAR(uint16, AUTOMATIC) FaultCounter,
															 VAR(uint16, AUTOMATIC) Threshold, 
													         VAR(uint16, AUTOMATIC) NTC,
													         VAR(uint8, AUTOMATIC) NTCParam);

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ClearDiagCounters(void);

STATIC FUNC(float32, AP_SRLCOMINPUT_CODE) ScaleSignal_f32(VAR(uint16, AUTOMATIC) Signal_Uls_T_u16, VAR(float32, AUTOMATIC) LoLmt_Uls_T_f32,
															VAR(float32, AUTOMATIC) HiLmt_Uls_T_f32, VAR(float32, AUTOMATIC) Scale_Uls_T_f32,
															VAR(float32, AUTOMATIC) Offset_Uls_T_f32);

extern FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus);

STATIC FUNC(void, AP_SRLCOMINPUT_CODE) CtrVibStwDisp_Diagnosis( VAR(New_Coding_71, AUTOMATIC) CtrWarnPtrnVibEps,
																VAR(New_Coding_75, AUTOMATIC) CtrWarnilvlVibEps
															  );

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
 * AVL_PINA_IDX_ICM: Integer in interval [0...65534]
 * Boolean: Boolean (standard type)
 * CD_0x01: Boolean
 * CD_0x04: Integer in interval [0...15]
 * CD_0x08: Integer in interval [0...255]
 * CD_0x16: Integer in interval [0...4194303]
 * CRC8: Integer in interval [0...255]
 * CRC_V_VEH: Integer in interval [0...255]
 * DT_NO_VECH_1: Integer in interval [0...255]
 * DT_NO_VECH_2: Integer in interval [0...255]
 * DT_NO_VECH_3: Integer in interval [0...255]
 * DT_NO_VECH_4: Integer in interval [0...255]
 * DT_NO_VECH_5: Integer in interval [0...255]
 * DT_NO_VECH_6: Integer in interval [0...255]
 * DT_NO_VECH_7: Integer in interval [0...255]
 * FACT_ASS_STMOM_FTAX: Integer in interval [0...254]
 * FACT_CTRR_STMOM_FTAX: Integer in interval [0...254]
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * MILE_KM: Integer in interval [0...16777214]
 * New_Coding_101: Integer in interval [0...255]
 * New_Coding_102: Integer in interval [0...14]
 * New_Coding_29: Integer in interval [0...255]
 * New_Coding_31: Integer in interval [0...65535]
 * New_Coding_32: Integer in interval [0...4095]
 * New_Coding_34: Integer in interval [0...255]
 * New_Coding_36: Integer in interval [0...65000]
 * New_Coding_37: Integer in interval [0...4000]
 * New_Coding_59: Integer in interval [0...255]
 * New_Coding_61: Integer in interval [0...14]
 * New_Coding_69: Integer in interval [0...14]
 * New_Coding_70: Integer in interval [0...14]
 * OFFS_QUAD_PINA_EPS: Integer in interval [0...254]
 * STMOM_QTA_DV: Integer in interval [0...4000]
 * TAR_STMOM_DV_ACT: Integer in interval [0...4000]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt4: Integer in interval [0...15] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 * V_VEH_COG: Integer in interval [0...22400]
 *
 * Enumeration Types:
 * ==================
 * ALIV_COU_4: Enumeration of integer in interval [0...15] with enumerators
 *   CxF_Signal_ungueltig (15U)
 * ALIV_COU_V: Enumeration of integer in interval [0...15] with enumerators
 *   CxF_Signal_ungueltig (15U)
 * AVL_STEA_PNI_OFFS: Enumeration of integer in interval [0...4095] with enumerators
 *   CxFFD_Funktionsschnittstelle_ist_nicht_verfuegbar (4093U)
 *   CxFFE_Funktion_meldet_Fehler (4094U)
 *   CxFFF_Signal_unbefuellt (4095U)
 * CTR_ERRM_BN_U: Enumeration of integer in interval [0...63] with enumerators
 *   Cb0xxxx1_Unterspannung_Normalbetrieb (0U)
 *   Cb0xxxx0_Keine_Unterspannung_Normalbetrieb (0U)
 *   Cb0xxx1x_Unterspannung_MSA_Start (0U)
 *   Cb0xxx0x_Keine_Unterspannung_MSA_Start (0U)
 *   Cb0xx1xx_Ueberspannung (0U)
 *   Cb0xx0xx_Keine_Ueberspannung (0U)
 *   Cx3D_nicht_verfuegbar (61U)
 *   Cx3E_Fehler (62U)
 *   Cx3F_Signal_ungueltig (63U)
 * DVCO_VEH: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Fahrzeug_steht (0U)
 *   Cx1_Fahrzeug_faehrt_vorwaerts (1U)
 *   Cx2_Fahrzeug_faehrt_rueckwaerts (2U)
 *   Cx3_Fahrzeug_faehrt (3U)
 *   Cx4_Fahrzeug_steht__Hinterachse_auf_Rollenpruefstand_erkannt (4U)
 *   Cx5_Fahrzeug_steht__Zwei_Achs_Rollenbetrieb_gesetzt (5U)
 *   Cx6_Fahrzeug_steht__Vorderachse_auf_Rollenpruefstand_erkannt (6U)
 *   Cx7_Signal_ungueltig (7U)
 * FACT_DMPNG_ADDON_STMOM_FTAX: Enumeration of integer in interval [0...255] with enumerators
 *   CxFD_Reserviert (253U)
 *   CxFE_Reserviert (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * ID_FN_INQY: Enumeration of integer in interval [0...65535] with enumerators
 *   Cx03EB_Grenzwerte_Schwenk_Links (1003U)
 *   Cx03EC_Grenzwerte_Schwenk_Rechts (1004U)
 *   Cx03F1_Status_Licht_Erweitert_CKM (1009U)
 *   Cx03F5_Status_Laderaumabdeckung_CKM (1013U)
 *   Cx0424_Status_Konfiguration_Kombi (1060U)
 *   Cx0427_Konfiguration_DSC (1063U)
 *   Cx042E_Status_M_Drive_2 (1070U)
 *   Cx0434_Konfiguration_EPS (1076U)
 *   Cx0435_Messung_Motoroel (1077U)
 *   Cx043F_Identifikationsnummer_Sensorcluster (1087U)
 *   Cx00A1_Bedienung_Tasten_Entertainment (161U)
 *   Cx00F6_Steuerung_Aussenspiegel (246U)
 *   Cx01AA_Effekt_ErgoCommander (426U)
 *   Cx01AE_Effekt_FondCommander (430U)
 *   Cx020D_Position_Lenksaeule (525U)
 *   Cx0226_Regensensor_Wischergeschwindigkeit (550U)
 *   Cx023A_Status_Funkschluessel (570U)
 *   Cx0248_Status_Rueckfahrkamera (584U)
 *   Cx0252_Wischerstatus (594U)
 *   Cx0267_Bedienung_Tastgeber_Bedienelement_Front (615U)
 *   Cx027E_Status_Verdeck_Cabrio (638U)
 *   CxFFFF_Signal_ungueltig (65535U)
 *   Cx0291_Bedienung_Einheiten (657U)
 *   Cx02E6_Status_Klima_Luftverteilung_FA (742U)
 *   Cx02EA_Status_Klima_Luftverteilung_BF (746U)
 *   Cx02EC_Status_Klima_SH_ZH_Zusatzwasserpumpe (748U)
 *   Cx02EE_Status_Klima_Zusatzprogramme (750U)
 *   Cx02F0_Status_Klima_Standfunktionen (752U)
 *   Cx02F7_Einheiten (759U)
 *   Cx02F8_Uhrzeit_Datum (760U)
 *   Cx0300_Status_RSE (768U)
 *   Cx030F_Status_Service_Call_TeleX (783U)
 *   Cx0313_Status_Service_Call_Teleservice (787U)
 *   Cx0332_Verbrauch_Information_Daten (818U)
 *   Cx0336_Anzeige_Checkcontrol_Meldung__Rolle_ (822U)
 *   Cx033A_Status_Monitor_Front (826U)
 *   Cx033C_Status_Monitor_Fond_1 (828U)
 *   Cx033E_Status_Monitor_Fond_2 (830U)
 *   Cx0341_Status_Kartendaten (833U)
 *   Cx0349_Rohdaten_Fuellstand_Tank (841U)
 *   Cx035C_Status_Bordcomputer (860U)
 *   Cx0360_Daten_Bordcomputer__Fahrtbeginn_ (864U)
 *   Cx0380_Fahrgestellnummer (896U)
 *   Cx0381_Elektronischer_Motoroelmessstab (897U)
 *   Cx0382_Elektronischer_Motoroelmessstab_M (898U)
 *   Cx0388_Fahrzeugtyp (904U)
 *   Cx038E_Startdrehzahl (910U)
 *   Cx0395_Codierung_Powermanagement (917U)
 *   Cx0399_Status_M_Drive (921U)
 *   Cx03A9_Status_Motorsteuerung_CKM (937U)
 *   Cx03AB_Status_Shiftlights_CKM (939U)
 *   Cx03B6_Position_Fensterheber_FAT (950U)
 *   Cx03B7_Position_Fensterheber_FATH (951U)
 *   Cx03B8_Position_Fensterheber_BFT (952U)
 *   Cx03B9_Position_Fensterheber_BFTH (953U)
 *   Cx03BA_Position_SHD (954U)
 *   Cx03BC_Position_Fensterheber_Sicherheitsfahrzeug (956U)
 *   Cx03BF_Position_Fensterheber_Heckscheibe (959U)
 *   Cx03C0_Konfiguration_FAS (960U)
 *   Cx03C1_Konfiguration_BFS (961U)
 *   Cx03C2_Konfiguration_FASH (962U)
 *   Cx03C3_Konfiguration_BFSH (963U)
 *   Cx03C4_Status_EDCK_CKM (964U)
 *   Cx03D0_Status_Spurverlassenswarnsystem_CKM (976U)
 *   Cx03D5_Status_Zentralverriegelung_CKM (981U)
 *   Cx03D7_Status_DWA_CKM (983U)
 *   Cx03D9_Status_RLS_CKM (985U)
 *   Cx03DB_Status_Memorypositionen_CKM (987U)
 *   Cx03DD_Status_Licht_CKM (989U)
 *   Cx03DF_Status_Klima_CKM (991U)
 *   Cx03E1_Status_ALC_CKM (993U)
 *   Cx03E3_Status_Heckklappe_CKM (995U)
 *   Cx03E5_Status_Rueckfahrkamera_CKM (997U)
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
 *   NTC_Num_PLLSlipRcvrl (21U)
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
 *   NTC_Num_TurnCntr_DataFlt (135U)
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
 * New_Coding_103: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Kein_Spannungseinbruch (0U)
 *   Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1 (1U)
 *   Cx2_Startspannungseinbruch_bis_maximal_Spannungsschwelle_2 (2U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Reserviert (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_104: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Motor_steht (0U)
 *   Cx1_Motor_startet (1U)
 *   Cx2_Motor_laeuft (2U)
 *   Cx3_Motor_im_Auslauf (3U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Reserviert (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_105: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Kein_Spannungseinbruch (0U)
 *   Cb0xxxxxx1_Startspannungseinbruch_auf_Versorgungszweig_1 (0U)
 *   Cb0xxxxx1x_Startspannungseinbruch_auf_Versorgungszweig_2 (0U)
 *   Cb0xxxx1xx_Spannungsversorgung_48_Volt (0U)
 *   CxFD_Reserviert (253U)
 *   CxFE_Reserviert (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_106: Enumeration of integer in interval [0...15] with enumerators
 *   Cb0xx1_Selbstlaufgrenze_unterschritten (0U)
 *   Cb0xx0_Selbstlaufgrenze_nicht_unterschritten (0U)
 *   Cb0x1x_Selbstlaufgrenze_wird_bald_unterschritten (0U)
 *   Cb0x0x_Keine_Unterschreitung_der_Selbstlaufgrenze_vorraussagbar (0U)
 *   Cb01xx_Retry_Anforderung_Fahrzeug_halten (0U)
 *   Cb00xx_Keine_Retry_Anforderung_um_das_Fahrzeug_zu_halten (0U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_107: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Kein_Ankuendigung (0U)
 *   Cx1_Ankuendigung_MSA_Motorstopp (1U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_108: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Kein_E_Maschine_verfuegbar (0U)
 *   Cx1_E_Maschine_ist_elektrisch_fahrbereit_oder_bereits_aktiv (1U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_109: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_ausschalten (0U)
 *   Cx1_einschalten (1U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_110: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Normalbetrieb (1U)
 *   Cx2_Traktionsoptimiert_Stufe_1 (2U)
 *   Cx3_Traktionsoptimiert_Stufe_2 (3U)
 *   Cx4_Traktionsoptimiert_Stufe_3 (4U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_111: Enumeration of integer in interval [0...15] with enumerators
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_112: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Keine_Anforderung (0U)
 *   Cb0xx1_Automatische_Parkunterstuetzung_unterbinden (0U)
 *   Cb0x1x_Automatische_Parkkollisionsvermeidung_unterbinden (0U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_30: Enumeration of integer in interval [0...15] with enumerators
 *   CxF_Signal_ungueltig (15U)
 * New_Coding_33: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__ (1U)
 *   Cx2_Signalwert_ist_gueltig__ (2U)
 *   Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__ (3U)
 *   Cx4_Reserved (4U)
 *   Cx6_Signalwert_ist_ungueltig__ (6U)
 *   Cx7_Reserved (7U)
 *   Cx8_Initialisierung__ (8U)
 *   Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer (9U)
 *   CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
 *   CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
 *   CxC_Ersatzwert__Abgleichwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer (12U)
 *   CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
 *   CxF_Signal_ungueltig (15U)
 * New_Coding_35: Enumeration of integer in interval [0...15] with enumerators
 *   CxF_Signal_ungueltig (15U)
 * New_Coding_38: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
 *   Cx2_Signalwert_ist_gueltig (2U)
 *   Cx3_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt (3U)
 *   Cx4_Reserved (4U)
 *   Cx6_Signalwert_ist_ungueltig (6U)
 *   Cx7_Reserved (7U)
 *   Cx8_Initialisierung (8U)
 *   Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer (9U)
 *   CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
 *   CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
 *   CxC_Ersatzwert_ist_im_Nutzsignal_gesetzt__Zustand_Status_temporaer (12U)
 *   CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
 *   CxF_Signal_ungueltig (15U)
 * New_Coding_60: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Keine_Kommunikation (0U)
 *   Cx1_Kom_Parken_BN_niO (1U)
 *   Cx2_Kom_Parken_BN_iO (2U)
 *   Cx3_Kom_Standfunktionen_Kunde_nicht_im_FZG (3U)
 *   Cx4_reserviert (4U)
 *   Cx5_Kom_Wohnen (5U)
 *   Cx6_reserviert (6U)
 *   Cx7_Kom_Pruefen_Analyse_Diagnose (7U)
 *   Cx8_Kom_Fahrbereitschaft_herstellen (8U)
 *   Cx9_reserviert (9U)
 *   CxA_Kom_Fahren (10U)
 *   CxB_reserviert (11U)
 *   CxC_Kom_Fahrbereitschaft_beenden (12U)
 *   CxD_reserviert (13U)
 *   CxE_reserviert (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_62: Enumeration of integer in interval [0...4294967295] with enumerators
 *   CxFFFFFFFF_Signal_unbefuellt (4294967295U)
 *   Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1_Konfiguration_ein (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0_Konfiguration_aus (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx1x_Ethernet_Infrastruktur_ein (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxxxxxxxxxxx0x_Ethernet_Infrastruktur_aus (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxxxx1xxxxxxxx_Klimabetrieb_ein (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxxxx0xxxxxxxx_Klimabetrieb_aus (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxxx1xxxxxxxxx_Entertainmentbetrieb_ein (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxxx0xxxxxxxxx_Entertainmentbetrieb_aus (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxx1xxxxxxxxxx_Externe_Kommunikation_ein (0U)
 *   Cb0xxxxxxxxxxxxxxxxxxxx0xxxxxxxxxx_Externe_Kommunikation_aus (0U)
 *   Cb0xxxxxxxxxxxxxxxxxx1xxxxxxxxxxxx_Assistenz_Parken_high_ein (0U)
 *   Cb0xxxxxxxxxxxxxxxxxx0xxxxxxxxxxxx_Assistenz_Parken_high_aus (0U)
 *   Cb0xxxxxxxxxxxxxxx1xxxxxxxxxxxxxxx_Laden_ein (0U)
 *   Cb0xxxxxxxxxxxxxxx0xxxxxxxxxxxxxxx_Laden_aus (0U)
 *   Cb0xxxxxxxxxxxxxx1xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_ein (0U)
 *   Cb0xxxxxxxxxxxxxx0xxxxxxxxxxxxxxxx_Fahrzeug_Infrastruktur_aus (0U)
 *   Cb0xxxxxxxxxxx1xxxxxxxxxxxxxxxxxxx_Licht_ein (0U)
 *   Cb0xxxxxxxxxxx0xxxxxxxxxxxxxxxxxxx_Licht_aus (0U)
 * New_Coding_63: Enumeration of integer in interval [0...15] with enumerators
 *   Cx2_Signalwert_gueltig (2U)
 *   Cx3_Signalwert_eingeschraenkt_gueltig (3U)
 *   Cx6_Reserviert_fuer_die_nicht_umgesetzte_Kennung__Fehler_ (6U)
 *   CxE_Wert_nicht_verfuegbar (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_64: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_reserviert (0U)
 *   Cx1_Parken_BN_niO (1U)
 *   Cx2_Parken_BN_iO (2U)
 *   Cx3_Standfunktionen_Kunde_nicht_im_FZG (3U)
 *   Cx5_Wohnen (5U)
 *   Cx7_Pruefen_Analyse_Diagnose (7U)
 *   Cx8_Fahrbereitschaft_herstellen (8U)
 *   CxA_Fahren (10U)
 *   CxC_Fahrbereitschaft_beenden (12U)
 *   CxD_reserviert (13U)
 *   CxE_reserviert (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_65: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Anzeigesegment_AUS (0U)
 *   Cx1_Anzeigesegment_AN__kein_Blinken (1U)
 *   Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
 *   Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
 *   Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
 *   Cx8_Initialisierung (8U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_66: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Anzeigesegment_AUS (0U)
 *   Cx1_Anzeigesegment_AN__kein_Blinken (1U)
 *   Cx2_Anzeigesegment_AN__Blinken_Stufe_1 (2U)
 *   Cx3_Anzeigesegment_AN__Blinken_Stufe_2 (3U)
 *   Cx4_Anzeigesegment_AN__Blinken_Stufe_3 (4U)
 *   Cx8_Initialisierung (8U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_67: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Kein_Wert (0U)
 *   Cx1_Mit_Trigger_beenden (1U)
 *   Cx2_Mit_Aktivzeit_beenden (2U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_68: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Vibration_AUS (0U)
 *   Cx1_Vibration_EIN__dauerhaft (1U)
 *   Cx2_Vibration_EIN__intermittierend (2U)
 *   Cx3_Signal_ungueltig (3U)
 * New_Coding_71: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Keine_haptische_Warnung (0U)
 *   Cx1_Muster_1 (1U)
 *   Cx2_Muster_2 (2U)
 *   Cx3_Muster_3 (3U)
 *   Cx4_Muster_4 (4U)
 *   Cx5_Muster_5 (5U)
 *   Cx6_Muster_6 (6U)
 *   Cx7_Muster_7 (7U)
 *   Cx8_Muster_8 (8U)
 *   Cx9_Muster_9 (9U)
 *   CxA_Muster_10 (10U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_72: Enumeration of integer in interval [0...255] with enumerators
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_73: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Keine_Richtung (0U)
 *   Cx1_Richtung_links (1U)
 *   Cx2_Richtung_rechts (2U)
 *   Cx3_Signal_unbefuellt (3U)
 * New_Coding_74: Enumeration of integer in interval [0...63] with enumerators
 *   Cx00_Intensitaetsstufen1 (0U)
 *   Cx01_Intensitaetsstufen2 (1U)
 *   Cx02_Intensitaetsstufen3 (2U)
 *   Cx03_Intensitaetsstufen4 (3U)
 *   Cx04_Intensitaetsstufen5 (4U)
 *   Cx05_Intensitaetsstufen6 (5U)
 *   Cx06_Intensitaetsstufen7 (6U)
 *   Cx07_Intensitaetsstufen8 (7U)
 *   Cx08_Intensitaetsstufen9 (8U)
 *   Cx09_Intensitaetsstufen10 (9U)
 *   Cx0A_Intensitaetsstufen11 (10U)
 *   Cx0B_Intensitaetsstufen12 (11U)
 *   Cx0C_Intensitaetsstufen13 (12U)
 *   Cx0D_Intensitaetsstufen14 (13U)
 *   Cx0E_Intensitaetsstufen15 (14U)
 *   Cx0F_Intensitaetsstufen16 (15U)
 *   Cx10_Intensitaetsstufen17 (16U)
 *   Cx11_Intensitaetsstufen18 (17U)
 *   Cx12_Intensitaetsstufen19 (18U)
 *   Cx13_Intensitaetsstufen20 (19U)
 *   Cx14_Intensitaetsstufen21 (20U)
 *   Cx15_Intensitaetsstufen22 (21U)
 *   Cx16_Intensitaetsstufen23 (22U)
 *   Cx17_Intensitaetsstufen24 (23U)
 *   Cx18_Intensitaetsstufen25 (24U)
 *   Cx19_Intensitaetsstufen26 (25U)
 *   Cx1A_Intensitaetsstufen27 (26U)
 *   Cx1B_Intensitaetsstufen28 (27U)
 *   Cx1C_Intensitaetsstufen29 (28U)
 *   Cx1D_Intensitaetsstufen30 (29U)
 *   Cx1E_Intensitaetsstufen31 (30U)
 *   Cx1F_Intensitaetsstufen32 (31U)
 *   Cx20_Intensitaetsstufen33 (32U)
 *   Cx21_Intensitaetsstufen34 (33U)
 *   Cx22_Intensitaetsstufen35 (34U)
 *   Cx23_Intensitaetsstufen36 (35U)
 *   Cx24_Intensitaetsstufen37 (36U)
 *   Cx25_Intensitaetsstufen38 (37U)
 *   Cx26_Intensitaetsstufen39 (38U)
 *   Cx27_Intensitaetsstufen40 (39U)
 *   Cx28_Intensitaetsstufen41 (40U)
 *   Cx29_Intensitaetsstufen42 (41U)
 *   Cx2A_Intensitaetsstufen43 (42U)
 *   Cx2B_Intensitaetsstufen44 (43U)
 *   Cx2C_Intensitaetsstufen45 (44U)
 *   Cx2D_Intensitaetsstufen46 (45U)
 *   Cx2E_Intensitaetsstufen47 (46U)
 *   Cx2F_Intensitaetsstufen48 (47U)
 *   Cx30_Intensitaetsstufen49 (48U)
 *   Cx31_Intensitaetsstufen50 (49U)
 *   Cx3D_Funktionsschnittstelle_ist_nicht_verfuegbar (61U)
 *   Cx3E_Funktion_meldet_Fehler (62U)
 *   Cx3F_Signal_unbefuellt (63U)
 * New_Coding_75: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Intensitaetsstufe_0 (0U)
 *   Cx1_Intensitaetsstufe_1 (1U)
 *   Cx2_Intensitaetsstufe_2 (2U)
 *   Cx3_Intensitaetsstufe_3 (3U)
 *   Cx4_Intensitaetsstufe_4 (4U)
 *   Cx5_Intensitaetsstufe_5 (5U)
 *   Cx6_Intensitaetsstufe_6 (6U)
 *   Cx7_Intensitaetsstufe_7 (7U)
 *   Cx8_Intensitaetsstufe_8 (8U)
 *   Cx9_Intensitaetsstufe_9 (9U)
 *   CxA_Intensitaetsstufe_10 (10U)
 *   CxB_Intensitaetsstufe_11 (11U)
 *   CxC_Intensitaetsstufe_12 (12U)
 *   CxD_Reserviert (13U)
 *   CxE_Reserviert (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_76: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Verschliffen (0U)
 *   Cx1_Ueberzeichnung (1U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_77: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Ultrahart__S__ (1U)
 *   Cx2_Sportlich_optimal__S_e_ (2U)
 *   Cx3_Sportlich_ausgewogen__S_ (3U)
 *   Cx4_Komfort_ausgewogen__B_ (4U)
 *   Cx5_Weich__C_ (5U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_78: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Luftfeder_in_Normalstellung__B_ (1U)
 *   Cx2_Luftfeder_abgesenkt__S_ (2U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_79: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Ultrahart (1U)
 *   Cx2_Sportlich_ausgewogen (2U)
 *   Cx3_Ausgewogen (3U)
 *   Cx4_Weich (4U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_80: Enumeration of integer in interval [0...255] with enumerators
 *   CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
 *   CxFE_Funktion_meldet_Fehler (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_81: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Voll (1U)
 *   Cx2_Mid (2U)
 *   Cx3_Keine (3U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_82: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Dynamische_Auspraegung_des_EDP (1U)
 *   Cx2_Ausgewogene_Auspraegung_des_EDP (2U)
 *   Cx3_Oekonomische_Auspraegung_des_EDP (3U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_83: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Keine_Deaktivierung_EPS_Funktionen (0U)
 *   Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1 (0U)
 *   Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2 (0U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
 * New_Coding_94: Enumeration of integer in interval [0...255] with enumerators
 *   CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
 *   CxFE_Funktion_meldet_Fehler (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_95: Enumeration of integer in interval [0...255] with enumerators
 *   CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
 *   CxFE_Funktion_meldet_Fehler (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_96: Enumeration of integer in interval [0...255] with enumerators
 *   CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
 *   CxFE_Funktion_meldet_Fehler (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_97: Enumeration of integer in interval [0...255] with enumerators
 *   CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
 *   CxFE_Funktion_meldet_Fehler (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_98: Enumeration of integer in interval [0...255] with enumerators
 *   CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
 *   CxFE_Funktion_meldet_Fehler (254U)
 *   CxFF_Signal_unbefuellt (255U)
 * New_Coding_99: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Degradationsstufe_0 (0U)
 *   Cx1_Degradationsstufe_1 (1U)
 *   Cx2_Degradationsstufe_2 (2U)
 *   Cx3_Degradationsstufe_3 (3U)
 *   Cx4_Degradationsstufe_4 (4U)
 *   CxF_Signal_ungueltig (15U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * QU_TAR_DMPNG_ADDON_STMOM_FTAX: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen (1U)
 *   Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen (2U)
 *   CxF_Signal_unbefuellt (15U)
 * QU_TAR_FACT_STMOM_FTAX: Enumeration of integer in interval [0...15] with enumerators
 *   Cx2_Sollwerte_umsetzen (2U)
 *   Cx7_Sollwerte_nicht_vorhanden (7U)
 *   CxE_Standby__Sollwerte_nicht_umsetzen (14U)
 *   CxF_Signal_ungueltig (15U)
 * QU_TAR_QTA_STMOM_DV: Enumeration of integer in interval [0...15] with enumerators
 *   Cx2_Sollwerte_umsetzen (2U)
 *   Cx7_Sollwerte_nicht_vorhanden (7U)
 *   CxE_Sollwerte_nicht_umsetzen___Standby (14U)
 *   CxF_Signal_ungueltig (15U)
 * QU_TAR_STMOM_DV_ACT: Enumeration of integer in interval [0...15] with enumerators
 *   Cx2_Sollwerte_umsetzen (2U)
 *   Cx7_Sollwerte_nicht_vorhanden (7U)
 *   CxE_Standby__Sollwerte_nicht_umsetzen (14U)
 *   CxF_Signal_ungueltig (15U)
 * QU_V_VEH_COG: Enumeration of integer in interval [0...15] with enumerators
 *   Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 *   Cx4_Reserved (4U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 *   Cx8_Initialisierung (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer (10U)
 *   CxB_Signalqualitaet_bzw__Ueberwachung_eingeschraenkt__Zustand_Status_temporaer (11U)
 *   CxC_Reserved (12U)
 *   CxE_Signalwert_ist_ungueltig__Zustand_Status_temporaer (14U)
 *   CxF_Signal_ungueltig (15U)
 * ST_ILK_ERRM_FZM: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Fehlerspeicherfreigabe (0U)
 *   Cx1_Fehlerspeichersperre (1U)
 *   Cx2_Reserve (2U)
 *   Cx3_Signal_ungueltig (3U)
 * ST_OFFS_QUAD_PINA_EPS: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Algorithmus__Funktion__im_Sleep_Modus (0U)
 *   Cx1_Offset__wird_ermittelt (1U)
 *   Cx2_Offset_uebernehmen__Aufsetzen_ueber_Index (2U)
 *   Cx3_Offset_uebernehmen__Aufsetzen_ueber_Modelvergleich (3U)
 *   Cx4_Offset_uebernehmen__Aufsetzen_ueber_Anschlag_Anschlag (4U)
 *   Cx5_Offset_uebernehmen__Aufsetzen_ueber_Summenlenkwinkel__im_AFS_Fall_ (5U)
 *   Cx6_Offset_in_Pruefung (6U)
 *   Cx7_Offset_korrigieren (7U)
 *   Cx8_Initialisierung (8U)
 *   Cx9_Restoffset_wird_ermittelt (9U)
 *   CxB_Offset_uebernehmen__Groboffset_ueber_Modell (11U)
 *   CxF_Signal_ungueltig (15U)
 * ST_V_VEH_NSS: Enumeration of integer in interval [0...15] with enumerators
 *   CxC_Fahrzeug_im_stillstandsnahen_Bereich (12U)
 *   CxD_Fahrzeug_nicht_im_stillstandsnahen_Bereich (13U)
 *   CxF_Signal_ungueltig (15U)
 *
 * Record Types:
 * =============
 * RT_VIN_NO_VECH: Record with elements
 *   VIN_BYTE1 of type DT_NO_VECH_1
 *   VIN_BYTE2 of type DT_NO_VECH_2
 *   VIN_BYTE3 of type DT_NO_VECH_3
 *   VIN_BYTE4 of type DT_NO_VECH_4
 *   VIN_BYTE5 of type DT_NO_VECH_5
 *   VIN_BYTE6 of type DT_NO_VECH_6
 *   VIN_BYTE7 of type DT_NO_VECH_7
 * SG_ACLNY_MASSCNTR: Record with elements
 *   ACLNY_COG_ERR_AMP of type New_Coding_37
 *   ALIV_ACLNY_COG of type New_Coding_35
 *   QU_ACLNY_COG of type New_Coding_38
 *   ACLNY_MASSCNTR_0x0C_0x04 of type CD_0x04
 *   ACLNY_COG of type New_Coding_36
 *   CRC_ACLNY_COG of type New_Coding_34
 * SG_ANFRAGE_EPS: Record with elements
 *   ID_FN_INQY_EPS of type ID_FN_INQY
 *   ID2_0x08_Mx01_EPS of type CD_0x08
 * SG_CON_VEH: Record with elements
 *   ALIV_CON_VEH of type New_Coding_61
 *   ST_CON_VEH of type New_Coding_64
 *   CTR_FKTN_PRTNT of type New_Coding_62
 *   QU_ST_CON_VEH of type New_Coding_63
 *   CON_VEH_0x38_0x08 of type CD_0x08
 *   CTR_BS_PRTNT of type New_Coding_60
 *   CRC_CON_VEH of type New_Coding_59
 * SG_OFFS_QUAD_EPS: Record with elements
 *   OFFS_QUAD_RTR_EPS of type OFFS_QUAD_PINA_EPS
 *   AVL_PO_IDX_ICM of type AVL_PINA_IDX_ICM
 *   CRC_OFFS_QUAD_EPS of type CRC8
 *   ST_OFFS_QUAD_EPS of type ST_OFFS_QUAD_PINA_EPS
 *   ALIV_OFFS_QUAD_EPS of type ALIV_COU_4
 * SG_ST_CENG: Record with elements
 *   CRC_ST_CENG of type New_Coding_101
 *   ST_ANO_MSA_ENG_STOP of type New_Coding_107
 *   CTR_LED_PUBU_MSA of type New_Coding_109
 *   ST_CENG_0x2A_0x16 of type CD_0x16
 *   ST_ENERG_SUPY of type New_Coding_105
 *   ST_MOT_DRV of type New_Coding_108
 *   ST_UDP of type New_Coding_103
 *   ST_CENG_DRV of type New_Coding_104
 *   ALIV_ST_CENG of type New_Coding_102
 *   TR_HHASS_MSA of type New_Coding_106
 *   ST_CENG_0x0C_0x04 of type CD_0x04
 * SG_TAR_QTA_STRMOM_DV: Record with elements
 *   FACT_CTRR_STMOM_FTAX of type FACT_CTRR_STMOM_FTAX
 *   ALIV_TAR_QTA_STMOM_DV of type ALIV_COU_4
 *   QU_TAR_FACT_STMOM_FTAX of type QU_TAR_FACT_STMOM_FTAX
 *   QU_TAR_QTA_STMOM_DV of type QU_TAR_QTA_STMOM_DV
 *   CRC_TAR_QTA_STMOM_DV of type CRC8
 *   FACT_ASS_STMOM_FTAX of type FACT_ASS_STMOM_FTAX
 *   FACT_DMPNG_STMOM_FTAX of type FACT_CTRR_STMOM_FTAX
 *   TAR_QTA_STMOM_DV of type STMOM_QTA_DV
 *   CTR_DEAC_EPS_FNS of type New_Coding_83
 * SG_TAR_STMOM_DV_ACT: Record with elements
 *   QU_TAR_STMOM_DV_ACT of type QU_TAR_STMOM_DV_ACT
 *   ALIV_TAR_STMOM_DV_ACT of type ALIV_COU_4
 *   TAR_STMOM_DV_ACT of type TAR_STMOM_DV_ACT
 *   CRC_TAR_STMOM_DV_ACT of type CRC8
 *   FACT_DMPNG_ADDON_STMOM_FTAX of type FACT_DMPNG_ADDON_STMOM_FTAX
 *   QU_TAR_DMPNG_ADDON_STMOM_FTAX of type QU_TAR_DMPNG_ADDON_STMOM_FTAX
 * SG_VYAW_VEH: Record with elements
 *   ALIV_VYAW_VEH of type New_Coding_30
 *   VYAW_VEH_ERR_AMP of type New_Coding_32
 *   VYAW_VEH_0x0C_0x04 of type CD_0x04
 *   CRC_VYAW_VEH of type New_Coding_29
 *   VYAW_VEH of type New_Coding_31
 *   QU_VYAW_VEH of type New_Coding_33
 * SG_V_VEH: Record with elements
 *   ST_V_VEH_NSS of type ST_V_VEH_NSS
 *   V_VEH_0x27_0x01 of type CD_0x01
 *   ALIV_V_VEH of type ALIV_COU_V
 *   CRC_V_VEH of type CRC_V_VEH
 *   QU_V_VEH_COG of type QU_V_VEH_COG
 *   V_VEH_COG of type V_VEH_COG
 *   DVCO_VEH of type DVCO_VEH
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
 * Float: D_SUPPLYCURRINIT_AMP_F32 = 166.67F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ZERO_CNT_U32 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
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
 *   void Rte_IWrite_SrlComInput_Init_IgnTimeOff_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Init_IgnTimeOff_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Init_SrlComSTKL_ST_KL(UInt4 data)
 *   UInt4 *Rte_IWriteRef_SrlComInput_Init_SrlComSTKL_ST_KL(void)
 *   void Rte_IWrite_SrlComInput_Init_VehTimeValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_VehTimeValid_Cnt_lgc(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Init
 *********************************************************************************************************************/
	VAR(uint32, AUTOMATIC) CurrentSystemTime_Sec_T_u32;
	VAR(sint32, AUTOMATIC) DeltaSysTime_Sec_T_s32;

	
	/* Set wake up broadcast request */
	SrlComSVCTxReq_Cnt_M_b16 |= D_IDFNINQY_CNT_B16;
	
	AutonomicPattern_Cnt_M_u08 = 0x0U;
	AutonomicIntensity_Cnt_M_u08 = 0x0U;

	AutonomicModeActive_Cnt_M_lgc = FALSE;
  
  RxMaxISpecEpsPrevVal_Cnt_M_u08 = 0x0U;

	/* SYSTEM TIME HANDLING INIT */
	(void)SysTimeClient_GetTime(&CurrentSystemTime_Sec_T_u32);

	SysTimeLockout_Cnt_M_lgc = FALSE;
	DeltaSysTime_Sec_T_s32 = (sint32)(CurrentSystemTime_Sec_T_u32) - (sint32)(StrdSysTime_Sec_M_u32);

	if( (DeltaSysTime_Sec_T_s32 >= D_ZERO_CNT_S32) && (CurrentSystemTime_Sec_T_u32 != D_CURRSYSTIMEINVLD_SEC_U32) )
	{
		/* Valid Time */
		Rte_IWrite_SrlComInput_Init_IgnTimeOff_Cnt_u32((uint32)DeltaSysTime_Sec_T_s32);
		Rte_IWrite_SrlComInput_Init_VehTimeValid_Cnt_lgc(TRUE);
	}
	else
	{
		/* Invalid Time */
		Rte_IWrite_SrlComInput_Init_IgnTimeOff_Cnt_u32(D_ZERO_CNT_U32);
		Rte_IWrite_SrlComInput_Init_VehTimeValid_Cnt_lgc(FALSE);
	}

	/* To initialize Edch message to transmit OBD message */
	Rte_IWrite_SrlComInput_Init_SrlComSTKL_ST_KL(0xDu);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
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
 *   Boolean Rte_IRead_SrlComInput_Per1_CERRMVOLTFALLBACK_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_DiagStsDefVehSpd_Cnt_lgc(void)
 *   CTR_ERRM_BN_U Rte_IRead_SrlComInput_Per1_RxCtrErrmBnU_Cnt_u8(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ErrmBnU_Cnt_u8(CTR_ERRM_BN_U data)
 *   Std_ReturnType Rte_Write_IgnTimeOff_Cnt_u32(UInt32 data)
 *   Std_ReturnType Rte_Write_VehTimeValid_Cnt_lgc(Boolean data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Per1
 *********************************************************************************************************************/
	
    VAR(CTR_ERRM_BN_U, AUTOMATIC) RxCtrErrmBnU_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;
	
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;
		
	VAR(boolean, AUTOMATIC) CERRMVOLTFALLBACK_Cnt_T_lgc;
	VAR(Fr_VErrorStatusType, AUTOMATIC) FrErrorStatusPtr_Cnt_T_str = 0UL;

	VAR(uint32, AUTOMATIC) CurrentSystemTime_Sec_T_u32;
	VAR(sint32, AUTOMATIC) DeltaSysTime_Sec_T_s32;

	/* Configurable Start of Runnable Checkpoint */
	(void)Rte_Call_SrlComInput_Per1_CP0_CheckpointReached();
	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);

    /* COMMUNICATION CONTROLLER ERROR STATE CHECK */
    (void)Fr_VCheckErrorState (&FrErrorStatusPtr_Cnt_T_str);
    FrErrorStatus_Cnt_D_str = FrErrorStatusPtr_Cnt_T_str;

	/* CHECK GLOBAL VOLTAGE ERROR MASKING ENABLE SWITCH */
	CERRMVOLTFALLBACK_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_CERRMVOLTFALLBACK_Cnt_lgc();

	if (CERRMVOLTFALLBACK_Cnt_T_lgc == TRUE)
	{
		RxCtrErrmBnU_Cnt_T_u08 = Cx3D_nicht_verfuegbar;
	}
	else
	{
		RxCtrErrmBnU_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_RxCtrErrmBnU_Cnt_u8();
	}

	if (D_SVCDFTRXMSGS_CNT_B32 == (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		ClearDiagCounters();
	}
	else
	{	
		/* GLOBAL VOLTAGE ERROR MASKING */
		if((RxCtrErrmBnU_Cnt_T_u08 >= D_CTRERRMLOWERMASK_CNT_U08) && (RxCtrErrmBnU_Cnt_T_u08 <= D_CTRERRMUPPERMASK_CNT_U08))
		{
			(void)Rte_Write_ErrmBnU_Cnt_u8(RxCtrErrmBnU_Cnt_T_u08);
			GetSystemTime_mS_u32(&CTRERRMUpateTimer_Cnt_M_u32);
		}
		else
		{
			DtrmnElapsedTime_mS_u32(CTRERRMUpateTimer_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);
		
			if (ElapsedTime_Cnt_T_u32 > k_CtrErrmBnUHold_mS_u16)
			{
				(void)Rte_Write_ErrmBnU_Cnt_u8(D_UNDERVLTGNORMOP_CNT_U08);
			} 
		}	

		/* System Time Handling for Ign Off */
		if (SysTimeLockout_Cnt_M_lgc == FALSE)
		{
			/* Check if a message was received */
			if(NxtrPatch_SysTimeClientIndicationFlag == TRUE)
			{
				(void)SysTimeClient_GetTime(&CurrentSystemTime_Sec_T_u32);
				DeltaSysTime_Sec_T_s32 = (sint32)(CurrentSystemTime_Sec_T_u32) - (sint32)(StrdSysTime_Sec_M_u32);

				if( (DeltaSysTime_Sec_T_s32 >= D_ZERO_CNT_S32) && (CurrentSystemTime_Sec_T_u32 != D_CURRSYSTIMEINVLD_SEC_U32) )
				{
					/* Valid Time */
					(void)Rte_Write_IgnTimeOff_Cnt_u32((uint32)DeltaSysTime_Sec_T_s32);
					(void)Rte_Write_VehTimeValid_Cnt_lgc(TRUE);
				}
				else
				{
					/* Invalid Time */
					(void)Rte_Write_IgnTimeOff_Cnt_u32(D_ZERO_CNT_U32);
					(void)Rte_Write_VehTimeValid_Cnt_lgc(FALSE);
				}

				/* Lock out until next key cycle */
				SysTimeLockout_Cnt_M_lgc = TRUE;
			}
		}
	}

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_SrlComInput_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_AclnyCogLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <ACLNY_MASSCNTR> of PortPrototype <ACLNY_MASSCNTR>
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_AclnyCogLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_AclnyCogLoss
 *********************************************************************************************************************/

	AclnyMassCntrLossFltCounter_Cnt_M_u16 =
			LostMsgDiag (AclnyMassCntrLossFltCounter_Cnt_M_u16, k_AclnyMassCntrLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AF, 0x01U);



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_AvlSteaPniOffsLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <AVL_STEA_PNI_OFFS> of PortPrototype <AVL_STEA_PNI_OFFS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_CHWACORRECTION_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_SrlComSvcDft_Cnt_b32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_AvlSteaPniOffsLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_AvlSteaPniOffsLoss
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) CHWACORRECTION_Cnt_T_lgc;

	CHWACORRECTION_Cnt_T_lgc = Rte_IRead_SrlComInput_TRGD_AvlSteaPniOffsLoss_CHWACORRECTION_Cnt_lgc();

	if (CHWACORRECTION_Cnt_T_lgc == D_USESTEAPNIOFFS_CNT_U08)
	{
		/* Only diagnose if enabled via coding */
		SteaPniOffsLossFltCounter_Cnt_M_u16 = LostMsgDiag (SteaPniOffsLossFltCounter_Cnt_M_u16, k_SteaPniOffsLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_V, 0x01U);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_ConVehLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CON_VEH> of PortPrototype <CON_VEH>
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_ConVehLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_ConVehLoss
 *********************************************************************************************************************/

	ConVehLossFltCounter_Cnt_M_u16 =
			LostMsgDiag (ConVehLossFltCounter_Cnt_M_u16, k_ConVehCntrLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AD, 0x01U);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_CtrVibStwDispLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CTR_WARN_ILVL_VIB_EPS> of PortPrototype <CTR_VIB_STW_DISP>
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CTR_WARN_PTRN_VIB_EPS> of PortPrototype <CTR_VIB_STW_DISP>
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_CtrVibStwDispLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_CtrVibStwDispLoss
 *********************************************************************************************************************/

	VAR(New_Coding_71, AUTOMATIC) RxCtrWarnPtrnVibEps = 0x0u;
	VAR(New_Coding_75, AUTOMATIC) RxCtrWarnilvlVibEps = 0x0u;

	CtrVibStwDispLossFltCounter_Cnt_M_u16 =
			LostMsgDiag (CtrVibStwDispLossFltCounter_Cnt_M_u16, k_CtrVibStwDispLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AE, 0x01U);

	if(AutonomicModeActive_Cnt_M_lgc == TRUE)
	{
		RxCtrWarnPtrnVibEps = AutonomicPattern_Cnt_M_u08;
		RxCtrWarnilvlVibEps = AutonomicIntensity_Cnt_M_u08;
		(void)CtrVibStwDisp_Diagnosis(RxCtrWarnPtrnVibEps, RxCtrWarnilvlVibEps);
	}
	else
	{
		HaptcFbPatSigVld_Cnt_M_lgc = FALSE;
		HaptcFbIntenSigVld_Cnt_M_lgc = FALSE;

		(void)Rte_Write_HaptcFbPatSigVld_Cnt_lgc(HaptcFbPatSigVld_Cnt_M_lgc);
		(void)Rte_Write_HaptcFbIntenSigVld_Cnt_lgc(HaptcFbIntenSigVld_Cnt_M_lgc);
	}



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_EnergDgrDrdyLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <MAX_I_SPEC_EPS> of PortPrototype <ENERG_DGR_DRDY>
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_EnergDgrDrdyLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_EnergDgrDrdyLoss
 *********************************************************************************************************************/
	EnergDgrDrdyLossFltCounter_Cnt_M_u16 =
	LostMsgDiag (EnergDgrDrdyLossFltCounter_Cnt_M_u16, k_EnergDgrDrdyLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AB, 0x01U);

	(void)Rte_Write_SupplyCurrLmt_Amp_f32((float32)k_MaxISpecEpsMax_Amp_u8);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_FZZSTDLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <Cnt_u8> of PortPrototype <RxILK_ERRM_FZM>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_FZZSTDLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_FZZSTDLoss
 *********************************************************************************************************************/
	
	FZZSTDLossFltCounter_Cnt_M_u16 = 
	LostMsgDiag (FZZSTDLossFltCounter_Cnt_M_u16, k_FZZSTDLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_Z, 0x01U);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_MileKMLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <Cnt_u32> of PortPrototype <RxMILE_KM>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_MileKMLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_MileKMLoss
 *********************************************************************************************************************/
	
	MileKMLossFltCounter_Cnt_M_u16 =
	LostMsgDiag (MileKMLossFltCounter_Cnt_M_u16, k_MileKMLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_X, 0x01U);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_PaDrvDynLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SG_TAR_QTA_STRMOM_DV> of PortPrototype <SG_TAR_QTA_STRMOM_DV>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CMTTORQUEIF_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_PaDrvDynLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_PaDrvDynLoss
 *********************************************************************************************************************/
	VAR(boolean ,AUTOMATIC) CHWTORQUEIF_Cnt_T_lgc;
	VAR(boolean ,AUTOMATIC) CMTTORQUEIF_Cnt_T_lgc;

	CHWTORQUEIF_Cnt_T_lgc = Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CHWTORQUEIF_Cnt_lgc();
	CMTTORQUEIF_Cnt_T_lgc = Rte_IRead_SrlComInput_TRGD_PaDrvDynLoss_CMTTORQUEIF_Cnt_lgc();

	/* Check SER 08 Coding motor torque interface enable/disble requirement to disable NTC 0x151*/
	if(FALSE == CMTTORQUEIF_Cnt_T_lgc)
	{
		TarStMomLossFltCounter_Cnt_M_u16 =
		LostMsgDiag (TarStMomLossFltCounter_Cnt_M_u16, k_TarStMomLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_S, 0x01U);
	}

	/* Check SER 08 Coding handwheel torque interface enable/disble requirement to disable NTC 0x149*/
	if(FALSE == CHWTORQUEIF_Cnt_T_lgc)
	{
		TarQtaStMomLossFltCounter_Cnt_M_u16 = 
		LostMsgDiag (TarQtaStMomLossFltCounter_Cnt_M_u16, k_TarQtaStMomLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_R, 0x01U);
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxAclnyCog
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ACLNY_MASSCNTR> of PortPrototype <ACLNY_MASSCNTR>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ACLNY_MASSCNTR_ACLNY_MASSCNTR(SG_ACLNY_MASSCNTR *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(const SG_ACLNY_MASSCNTR *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxAclnyCog(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxAclnyCog
 *********************************************************************************************************************/

  VAR(SG_ACLNY_MASSCNTR, AUTOMATIC) RxAclnyMassCntr_T_Str;

  /* Receive Lateral Acceleration (ACLNY_MASSCNTR) message data */
  	 (void)Rte_Read_ACLNY_MASSCNTR_ACLNY_MASSCNTR(&RxAclnyMassCntr_T_Str);

  	AclnyMassCntrLossFltCounter_Cnt_M_u16 =
  	RxMsgDiag (AclnyMassCntrLossFltCounter_Cnt_M_u16, k_AclnyMassCntrLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AF, 0x01U);

	/* Pass Lateral Acceleration (ACLNY_MASSCNTR) message data to ASIL_D application */
	  (void)Rte_Write_Ap_SrlComInput_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(&RxAclnyMassCntr_T_Str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxAvlSteaPniOffs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <AVL_STEA_PNI_OFFS> of PortPrototype <AVL_STEA_PNI_OFFS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(AVL_STEA_PNI_OFFS *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_CHWACORRECTION_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxAvlSteaPniOffs(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxAvlSteaPniOffs
 *********************************************************************************************************************/

	VAR(AVL_STEA_PNI_OFFS, AUTOMATIC) SteaOffs_Cnts_T_u16;
	VAR(float32, AUTOMATIC) ScaledSteaPniOffs_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) CodingHwAngCorrection_Cnt_T_lgc;

	/* Read in variables */
	CodingHwAngCorrection_Cnt_T_lgc = Rte_IRead_SrlComInput_TRGD_RxAvlSteaPniOffs_CHWACORRECTION_Cnt_lgc();

	if (CodingHwAngCorrection_Cnt_T_lgc == D_USESTEAPNIOFFS_CNT_U08)
	{
		/* Bring Previous value back. Will be updated if valid, if not hold previous */
		ScaledSteaPniOffs_HwDeg_T_f32 = PrevSteaPinOffs_HwDeg_M_f32;

		/* Read in new value */
		(void)Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(&SteaOffs_Cnts_T_u16);

		SteaPniOffsLossFltCounter_Cnt_M_u16 = RxMsgDiag(SteaPniOffsLossFltCounter_Cnt_M_u16,
						  	  	  	  	  	  	  	  	  k_SteaPniOffsLostMsgThres_Cnt_u16,
						  	  	  	  	  	  	  	  	  NTC_Num_MissingMsg_V, 0x01U);

		/* Use STEA_OFFS */
		switch(SteaOffs_Cnts_T_u16)
		{
			case (uint16)SteaPniOffs_Invalid_Cnt_enum:
				SteaPniOffsInvalidCounter_Cnt_M_u16++;
				SteaPniOffsErrorCounter_Cnt_M_u16 = 0U;

				if(SteaPniOffsInvalidCounter_Cnt_M_u16 >= D_RXMSGINVALID_CNT_U08)
				{
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_V, 0x01U, NTC_STATUS_FAILED);
					SteaPniOffsInvalidCounter_Cnt_M_u16 = D_RXMSGINVALID_CNT_U08;
					SteaPniOffsErrorRecovery_Cnt_M_u16 = D_RXMSGINVALID_CNT_U08;
				}
			break;
			case (uint16)SteaPniOffs_FuncRetErr_Cnt_enum:
			case (uint16)SteaPniOffs_NotAvail_Cnt_enum:
				SteaPniOffsErrorCounter_Cnt_M_u16++;
				SteaPniOffsInvalidCounter_Cnt_M_u16 = 0U;

				if(SteaPniOffsErrorCounter_Cnt_M_u16 >= D_RXMSGINVALID_CNT_U08)
				{
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_V, 0x01U, NTC_STATUS_FAILED);
					SteaPniOffsErrorCounter_Cnt_M_u16 = D_RXMSGINVALID_CNT_U08;
					SteaPniOffsErrorRecovery_Cnt_M_u16 = D_RXMSGINVALID_CNT_U08;
				}

			break;
			default:
				/* Valid signal */
				SteaPniOffsErrorCounter_Cnt_M_u16 = 0U;
				SteaPniOffsInvalidCounter_Cnt_M_u16 = 0U;

				if(SteaPniOffsErrorRecovery_Cnt_M_u16 > 0U)
				{
					SteaPniOffsErrorRecovery_Cnt_M_u16--;
				}
				else
				{
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_V, 0x01U, NTC_STATUS_PASSED);
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_V, 0x01U, NTC_STATUS_PASSED);

					/* Scale new data to application port */
					ScaledSteaPniOffs_HwDeg_T_f32 =  ScaleSignal_f32(SteaOffs_Cnts_T_u16, D_STEAPNIOFFS_LOLMT_HWDEG_F32, D_STEAPNIOFFS_HILMT_HWDEG_F32,
																	 D_STEAPNIOFFS_CNTTOHWDEG_ULS_F32, D_STEAPNIOFFS_OFFSET_ULS_F32);
				}

			break;
		}

	}
	else
	{
		/* RxMsg Defeated, assume default value */
		ScaledSteaPniOffs_HwDeg_T_f32 = D_STEAPNIOFFS_FIXEDZERO_HWDEG_F32;
	}

	/* Update Previous Value */
	PrevSteaPinOffs_HwDeg_M_f32 = ScaledSteaPniOffs_HwDeg_T_f32;

	Rte_IWrite_SrlComInput_TRGD_RxAvlSteaPniOffs_ReturnOffset_HwDeg_f32(ScaledSteaPniOffs_HwDeg_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxConVeh
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <CON_VEH> of PortPrototype <CON_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CON_VEH_CON_VEH(SG_CON_VEH *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComCONVEH_CON_VEH(const SG_CON_VEH *data)
 *   Std_ReturnType Rte_Write_SrlComSTKL_ST_KL(UInt4 data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxConVeh(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxConVeh
 *********************************************************************************************************************/

  VAR(SG_CON_VEH, AUTOMATIC) RxConVeh_T_Str;

  /* Receive Vehicle Condition (CON_VEH) message data */
  	 (void)Rte_Read_Ap_SrlComInput_CON_VEH_CON_VEH(&RxConVeh_T_Str);

  	ConVehLossFltCounter_Cnt_M_u16 =
  	RxMsgDiag (ConVehLossFltCounter_Cnt_M_u16, k_ConVehCntrLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AD, 0x01U);

  	/* Since Klemmen signal is removed with SCIR Rev 01A, this is a workaround to update the Edch component */
  	if( (RxConVeh_T_Str.ST_CON_VEH == Cx7_Pruefen_Analyse_Diagnose) ||
		(RxConVeh_T_Str.ST_CON_VEH == Cx8_Fahrbereitschaft_herstellen) ||
		(RxConVeh_T_Str.ST_CON_VEH == CxA_Fahren) ||
		(RxConVeh_T_Str.ST_CON_VEH == CxC_Fahrbereitschaft_beenden) )
  	{
  		(void)Rte_Write_SrlComSTKL_ST_KL(0xDu);
  	}
  	else
  	{
  		(void)Rte_Write_SrlComSTKL_ST_KL(0x0u);
  	}

	/* Pass Vehicle Condition (CON_VEH) message data to ASIL_D application */
	  (void)Rte_Write_SrlComCONVEH_CON_VEH(&RxConVeh_T_Str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxCtrVibStwDisp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <CTR_WARN_ILVL_VIB_EPS> of PortPrototype <CTR_VIB_STW_DISP>
 *   - triggered on DataReceivedEvent for DataElementPrototype <CTR_WARN_PTRN_VIB_EPS> of PortPrototype <CTR_VIB_STW_DISP>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS(New_Coding_75 *data)
 *   Std_ReturnType Rte_Read_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS(New_Coding_71 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HaptcFbIntenNr_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_HaptcFbIntenSigVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaptcFbPatNr_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_HaptcFbPatSigVld_Cnt_lgc(Boolean data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxCtrVibStwDisp(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxCtrVibStwDisp
 *********************************************************************************************************************/

	VAR(New_Coding_71, AUTOMATIC) RxCtrWarnPtrnVibEps = 0x0u;
	VAR(New_Coding_75, AUTOMATIC) RxCtrWarnilvlVibEps = 0x0u;

	if(AutonomicModeActive_Cnt_M_lgc == FALSE)
	{
	  	(void)Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_PTRN_VIB_EPS(&RxCtrWarnPtrnVibEps);
		(void)Rte_Read_Ap_SrlComInput_CTR_VIB_STW_DISP_CTR_WARN_ILVL_VIB_EPS(&RxCtrWarnilvlVibEps);
	}
	else
	{
		RxCtrWarnPtrnVibEps = AutonomicPattern_Cnt_M_u08;
		RxCtrWarnilvlVibEps = AutonomicIntensity_Cnt_M_u08;
	}

  	CtrVibStwDispLossFltCounter_Cnt_M_u16 =
  	RxMsgDiag (CtrVibStwDispLossFltCounter_Cnt_M_u16, k_CtrVibStwDispLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AE, 0x01U);

	(void)CtrVibStwDisp_Diagnosis(RxCtrWarnPtrnVibEps, RxCtrWarnilvlVibEps);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxEnergDgrDrdy
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MAX_I_SPEC_EPS> of PortPrototype <ENERG_DGR_DRDY>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ENERG_DGR_DRDY_MAX_I_SPEC_EPS(New_Coding_94 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SupplyCurrLmt_Amp_f32(Float data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxEnergDgrDrdy(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxEnergDgrDrdy
 *********************************************************************************************************************/
	VAR(New_Coding_94, AUTOMATIC) RxMaxISpecEps_Cnt_T_u08;
	VAR(New_Coding_94, AUTOMATIC) CustCurrLimit_Amp_T_u8 = k_MaxISpecEpsMax_Amp_u8;

	VAR(float32, AUTOMATIC) CustCurrLimit_Amp_T_f32;
	VAR(uint8, AUTOMATIC) InvldDataChk_Cnt_T_u8;
	VAR(uint8, AUTOMATIC) UndefDataChk_Cnt_T_u8;

	EnergDgrDrdyLossFltCounter_Cnt_M_u16 =
	RxMsgDiag (EnergDgrDrdyLossFltCounter_Cnt_M_u16, k_EnergDgrDrdyLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AB, 0x01U);

	(void)Rte_Read_ENERG_DGR_DRDY_MAX_I_SPEC_EPS(&RxMaxISpecEps_Cnt_T_u08);


	if((RxMaxISpecEps_Cnt_T_u08 == CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) ||
	   (RxMaxISpecEps_Cnt_T_u08 == CxFE_Funktion_meldet_Fehler) )
	{
    /* Check whether the previous values were FD or FF to ensure fault is being set for three consecutive messages */
    if((RxMaxISpecEpsPrevVal_Cnt_M_u08 != CxFD_Funktionsschnittstelle_ist_nicht_verfuegbar) && 
      (RxMaxISpecEpsPrevVal_Cnt_M_u08 != CxFE_Funktion_meldet_Fehler))
    {
      UndefMaxISpecEpsCntr_Cnt_M_u8 = D_ZERO_CNT_U8;
    }
    
    /* Decrement the In valid counter if previous received message was invalid */
    if(InvldMaxISpecEpsCntr_Cnt_M_u8 > D_ZERO_CNT_U8)
		{
		  InvldMaxISpecEpsCntr_Cnt_M_u8--;
		}
    else
		{
		 (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AB, 0x01U, NTC_STATUS_PASSED);
		}
    
		/* Increment counter for error */
	 	if(UndefMaxISpecEpsCntr_Cnt_M_u8 >= D_RXMSGINVALID_CNT_U08)
	 	{
	 		UndefMaxISpecEpsCntr_Cnt_M_u8 = D_RXMSGINVALID_CNT_U08;
	 		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AB, 0x01U, NTC_STATUS_FAILED);
	  }
	 	else
	 	{
	 		UndefMaxISpecEpsCntr_Cnt_M_u8++;
	 	}
	}

	else if(RxMaxISpecEps_Cnt_T_u08 == CxFF_Signal_unbefuellt)
	{
    if(RxMaxISpecEpsPrevVal_Cnt_M_u08 != CxFF_Signal_unbefuellt)
    {
      InvldMaxISpecEpsCntr_Cnt_M_u8 = D_ZERO_CNT_U8;
    }   
    /* Decrement the In valid counter if previous received message was invalid */
    if(UndefMaxISpecEpsCntr_Cnt_M_u8 > D_ZERO_CNT_U8)
		{
		  UndefMaxISpecEpsCntr_Cnt_M_u8--;
		}
    else
		{
		 (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AB, 0x01U, NTC_STATUS_PASSED);
		}
    
	  if(InvldMaxISpecEpsCntr_Cnt_M_u8 >= D_RXMSGINVALID_CNT_U08)
	  {
	  	InvldMaxISpecEpsCntr_Cnt_M_u8 = D_RXMSGINVALID_CNT_U08;
	  	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AB, 0x01U, NTC_STATUS_FAILED);
	  }
	  else
	  {
	  	InvldMaxISpecEpsCntr_Cnt_M_u8++;
	  }
	}
	else
	{
  	/* Signal is valid, update counters and update output */
  	if(InvldMaxISpecEpsCntr_Cnt_M_u8 > D_ZERO_CNT_U8)
  	{
  		InvldMaxISpecEpsCntr_Cnt_M_u8--;
  	}
  	else
  	{
  		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AB, 0x01U, NTC_STATUS_PASSED);
  	}

  	if(UndefMaxISpecEpsCntr_Cnt_M_u8 > D_ZERO_CNT_U8)
  	{
  		UndefMaxISpecEpsCntr_Cnt_M_u8--;
  	}
  	else
  	{
  		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AB, 0x01U, NTC_STATUS_PASSED);
  	}

  	/* Update output if no faults */
  	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_AB, &InvldDataChk_Cnt_T_u8);
  	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataOtherFltMsg_AB, &UndefDataChk_Cnt_T_u8);

  	if(((InvldDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
  	   ((UndefDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8))
  	{
  	   if((RxMaxISpecEps_Cnt_T_u08 < k_MaxISpecEpsMin_Amp_u8) || (RxMaxISpecEps_Cnt_T_u08 > k_MaxISpecEpsMax_Amp_u8))
  	   {
  		 CustCurrLimit_Amp_T_u8 = k_MaxISpecEpsMax_Amp_u8;
  	   }
  	   else
  	   {
  		 CustCurrLimit_Amp_T_u8 = RxMaxISpecEps_Cnt_T_u08;
  	   }

  	}
	}
  /* Store the values to check for setting fault only for successive messages */
  RxMaxISpecEpsPrevVal_Cnt_M_u08 = RxMaxISpecEps_Cnt_T_u08;
	CustCurrLimit_Amp_T_f32 = (float32)CustCurrLimit_Amp_T_u8;

	(void)Rte_Write_SupplyCurrLmt_Amp_f32(CustCurrLimit_Amp_T_f32);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxPaDrvDyn
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_TAR_STMOM_DV_ACT> of PortPrototype <SG_TAR_STMOM_DV_ACT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV(SG_TAR_QTA_STRMOM_DV *data)
 *   Std_ReturnType Rte_Read_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT(SG_TAR_STMOM_DV_ACT *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(const SG_TAR_QTA_STRMOM_DV *data)
 *   Std_ReturnType Rte_Write_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(const SG_TAR_STMOM_DV_ACT *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxPaDrvDyn(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxPaDrvDyn
 *********************************************************************************************************************/
	
	VAR(SG_TAR_STMOM_DV_ACT, AUTOMATIC) RxPrkAstHWAngle_T_Str;
	VAR(SG_TAR_QTA_STRMOM_DV, AUTOMATIC) RxDrvDyn_T_Str;
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;
	
	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);
	
	if (D_SVCDFTRXMSGS_CNT_B32 != (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		/* Receive Driving Dynamics (TAR_QTA_STRMOM_DV) message data */
		(void)Rte_Read_SG_TAR_QTA_STRMOM_DV_SG_TAR_QTA_STRMOM_DV(&RxDrvDyn_T_Str);

		/* Receive Park Assist (TAR_STMOM_DV_ACT) message data */
		(void)Rte_Read_SG_TAR_STMOM_DV_ACT_SG_TAR_STMOM_DV_ACT(&RxPrkAstHWAngle_T_Str);

		TarStMomLossFltCounter_Cnt_M_u16 =
		RxMsgDiag (TarStMomLossFltCounter_Cnt_M_u16, k_TarStMomLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_S, 0x01U);

		TarQtaStMomLossFltCounter_Cnt_M_u16 =
		RxMsgDiag (TarQtaStMomLossFltCounter_Cnt_M_u16, k_TarQtaStMomLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_R, 0x01U);
		
		/* Pass Driving Dynamics (TAR_QTA_STRMOM_DV) and Park Assist (TAR_STMOM_DV_ACT) message data to ASIL_D application */
		(void)Rte_Write_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(&RxDrvDyn_T_Str);
		(void)Rte_Write_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(&RxPrkAstHWAngle_T_Str);
	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxRevOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_OFFS_QUAD_EPS> of PortPrototype <SG_OFFS_QUAD_EPS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(SG_OFFS_QUAD_EPS *data)
 *   boolean Rte_IsUpdated_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Read_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(SG_OFFS_QUAD_EPS *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_SrlComInput_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(const SG_OFFS_QUAD_EPS *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxRevOffset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxRevOffset
 *********************************************************************************************************************/
	VAR(SG_OFFS_QUAD_EPS, AUTOMATIC) RxRevOffsetMsgData_T_Str;
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;

	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);
	
	if (D_SVCDFTRXMSGS_CNT_B32 != (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		/* Read ICMRevOffset data */
		(void)Rte_Read_SG_OFFS_QUAD_EPS_SG_OFFS_QUAD_EPS(&RxRevOffsetMsgData_T_Str);

		RevOffsetLossFltCounter_Cnt_M_u16 = 
		RxMsgDiag(RevOffsetLossFltCounter_Cnt_M_u16, 
		          k_RevOffsetLostMsgThres_Cnt_u16, 
		          NTC_Num_MissingMsg_Q, 0x01U);
		
		/* Pass ICMRevOffset (SG_OFFS_QUAD_EPS) message data to ASIL_D application */
		(void)Rte_Write_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(&RxRevOffsetMsgData_T_Str);
 	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxRevOffsetLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SG_OFFS_QUAD_EPS> of PortPrototype <SG_OFFS_QUAD_EPS>
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxRevOffsetLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxRevOffsetLoss
 *********************************************************************************************************************/
		RevOffsetLossFltCounter_Cnt_M_u16 = 
		LostMsgDiag(RevOffsetLossFltCounter_Cnt_M_u16, 
		          k_RevOffsetLostMsgThres_Cnt_u16, 
		          NTC_Num_MissingMsg_Q, 0x01U);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxStCeng
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ST_CENG> of PortPrototype <ST_CENG>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ST_CENG_ST_CENG(SG_ST_CENG *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComSTCENG_ST_CENG(const SG_ST_CENG *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxStCeng(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxStCeng
 *********************************************************************************************************************/
	VAR(SG_ST_CENG, AUTOMATIC) RxStCeng_T_Str;

	/* Read ST_CENG message data */
	(void)Rte_Read_ST_CENG_ST_CENG(&RxStCeng_T_Str);

	StCengLossFltCounter_Cnt_M_u16 =
			RxMsgDiag (StCengLossFltCounter_Cnt_M_u16, k_StCengCntrLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AC, 0x01U);

	/* Pass the message to ASIL D application */
	(void)Rte_Write_SrlComSTCENG_ST_CENG(&RxStCeng_T_Str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxTuningSel
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SU_CLU_STMOM_SFE_DXP> of PortPrototype <SU_CLE_DRDY_DXP>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP(New_Coding_79 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxTuningSel_CDRVDYNMSG_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(New_Coding_79 data)
 *   New_Coding_79 *Rte_IWriteRef_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxTuningSel(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxTuningSel
 *********************************************************************************************************************/
	VAR(New_Coding_79, AUTOMATIC) TuningSelVal;
	VAR(uint8, AUTOMATIC) InvldDataChk_Cnt_T_u8;
	VAR(uint8, AUTOMATIC) InvldDataRngChk_Cnt_T_u8;
	VAR(boolean, AUTOMATIC) CodingDrvDyn_Uls_T_lgc;

	CodingDrvDyn_Uls_T_lgc = Rte_IRead_SrlComInput_TRGD_RxTuningSel_CDRVDYNMSG_Cnt_lgc();

	/* Read in value */
	(void)Rte_Read_SU_CLE_DRDY_DXP_SU_CLU_STMOM_SFE_DXP(&TuningSelVal);

	/* Correct error counter for missing message */
	TuningSelLossFltCounter_Cnt_M_u16 = RxMsgDiag(TuningSelLossFltCounter_Cnt_M_u16, k_TuningSelLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_U, 0x01U);

	/* If driving dynamics message is not used, send init value, VehCfg will handle which personality to select */
	if(CodingDrvDyn_Uls_T_lgc == TRUE)
	{
		/* Determine if data is OK */
		if((TuningSelVal == D_TUNINGSELINVALID_CNT_U16) || (TuningSelVal == D_TUNINGSELUNAVIALABLE_CNT_U16) || (TuningSelVal == D_TUNINGSELERROR_CNT_U16))
		{
			/* Increment counter for error, keep previous value */
			if(InvldTuningSelCntr_Cnt_M_u8 >= D_RXMSGINVALID_CNT_U08)
			{
				InvldTuningSelCntr_Cnt_M_u8 = D_RXMSGINVALID_CNT_U08;
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01U, NTC_STATUS_FAILED);
			}
			else
			{
				InvldTuningSelCntr_Cnt_M_u8++;
			}
		}
		else if ((D_TUNINGSELSPORT_CNT_U16 == TuningSelVal) ||
				 (D_TUNINGSELBASESVT_CNT_U16 == TuningSelVal))
		{
			/* Signal is valid, update counters and update output */
			if(InvldTuningSelCntr_Cnt_M_u8 > D_ZERO_CNT_U8)
			{
				InvldTuningSelCntr_Cnt_M_u8--;
			}
			else
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01U, NTC_STATUS_PASSED);
			}

			if(InvldTuningSelDataCntr_Cnt_M_u8 > D_ZERO_CNT_U8)
			{
				InvldTuningSelDataCntr_Cnt_M_u8--;
			}
			else
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_U, 0x01U, NTC_STATUS_PASSED);
			}

			/* Update output and previous value if no faults */
			(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_U, &InvldDataChk_Cnt_T_u8);
			(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataRngFltMsg_U, &InvldDataRngChk_Cnt_T_u8);

			if( ((InvldDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
				((InvldDataRngChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) )
			{
				/* Update output */
				PrevTuningSelVal_Cnt_M_enum = TuningSelVal;
			}
		}
		else
		{
			/* Signal is valid, but not the correct data, keep data the same, increment error counter */
			if(InvldTuningSelDataCntr_Cnt_M_u8 >= D_RXMSGINVALID_CNT_U08)
			{
				InvldTuningSelDataCntr_Cnt_M_u8 = D_RXMSGINVALID_CNT_U08;
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_U, 0x01U, NTC_STATUS_FAILED);
			}
			else
			{
				InvldTuningSelDataCntr_Cnt_M_u8++;
			}
		}
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01U, NTC_STATUS_PASSED);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_U, 0x01U, NTC_STATUS_PASSED);
		PrevTuningSelVal_Cnt_M_enum = D_TUNINGSELBASESVT_CNT_U16;
	}

	/* Value is only updated on valid data */
	Rte_IWrite_SrlComInput_TRGD_RxTuningSel_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP(PrevTuningSelVal_Cnt_M_enum);

	return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxVIN
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VIN_NO_VECH> of PortPrototype <RxVIN>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *   Implicit S/R API:
 *   -----------------
 *   RT_VIN_NO_VECH *Rte_IRead_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS(const SG_ANFRAGE_EPS *data)
 *   Std_ReturnType Rte_Write_VINValid_Cnt_lgc(Boolean data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVIN(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxVIN
 *********************************************************************************************************************/
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;
	VAR(boolean, AUTOMATIC) VINValid_Cnt_T_lgc;
	
	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);
			
	if (D_SVCDFTRXMSGS_CNT_B32 != (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		VINLossFltCounter_Cnt_M_u16 = 
		RxMsgDiag(VINLossFltCounter_Cnt_M_u16, 
		          k_VINLostMsgThres_Cnt_u16, 
		          NTC_Num_MissingMsg_W, 0x01U);
		
		RxVIN_Cnt_M_Str = *Rte_IRead_SrlComInput_TRGD_RxVIN_RxVIN_VIN_NO_VECH();
		
		if( (RxVIN_Cnt_M_Str.VIN_BYTE1 == 0xFFU) ||
			(RxVIN_Cnt_M_Str.VIN_BYTE2 == 0xFFU) ||
			(RxVIN_Cnt_M_Str.VIN_BYTE3 == 0xFFU) ||
			(RxVIN_Cnt_M_Str.VIN_BYTE4 == 0xFFU) ||
			(RxVIN_Cnt_M_Str.VIN_BYTE5 == 0xFFU) ||
			(RxVIN_Cnt_M_Str.VIN_BYTE6 == 0xFFU) ||
			(RxVIN_Cnt_M_Str.VIN_BYTE7 == 0xFFU) )
		{
			VINVldCounter_Cnt_M_u08++;
			
			VINValid_Cnt_T_lgc = FALSE;

			if(VINVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0x01U, NTC_STATUS_FAILED);
				VINVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				VINErrorRecovery_Cnt_M_u16 = D_RXMSGINVALID_CNT_U08;
			}
		}
		else
		{
			VINVldCounter_Cnt_M_u08 = 0U;
			
			VINValid_Cnt_T_lgc = TRUE;

			if (VINErrorRecovery_Cnt_M_u16 > 0U)
			{
				VINErrorRecovery_Cnt_M_u16--;
			}
			else
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0x01U, NTC_STATUS_PASSED);
			}
			
			/* Valid VIN received, cancel Tx request */
			SrlComSVCTxReq_Cnt_M_b16 &= (uint16)(~(uint16)D_IDFNINQY_CNT_B16);
		}
	}
	else
	{
		VINValid_Cnt_T_lgc = TRUE;
	}

	(void)Rte_Write_VINValid_Cnt_lgc(VINValid_Cnt_T_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxVYawVeh
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VYAW_VEH> of PortPrototype <VYAW_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VYAW_VEH_VYAW_VEH(SG_VYAW_VEH *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVYAWVEH_VYAW_VEH(const SG_VYAW_VEH *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVYawVeh(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxVYawVeh
 *********************************************************************************************************************/

	  VAR(SG_VYAW_VEH, AUTOMATIC) RxVYawVehCntr_T_Str;

	  /* Receive Vehicle Yaw Rate (VYAW_VEH) message data */
	  	 (void)Rte_Read_VYAW_VEH_VYAW_VEH(&RxVYawVehCntr_T_Str);

	  	VyawVehLossFltCounter_Cnt_M_u16 =
	  	RxMsgDiag (VyawVehLossFltCounter_Cnt_M_u16, k_VYawVehCntrLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AA, 0x01U);

		/* Pass Vehicle Yaw Rate (VYAW_VEH) message data to ASIL_D application */
		  (void)Rte_Write_SrlComVYAWVEH_VYAW_VEH(&RxVYawVehCntr_T_Str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_RxVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_V_VEH> of PortPrototype <SG_V_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_V_VEH_SG_V_VEH(SG_V_VEH *data)
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComSGVVEH_SG_V_VEH(const SG_V_VEH *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_RxVehSpd(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_RxVehSpd
 *********************************************************************************************************************/
	VAR(SG_V_VEH, AUTOMATIC) RxVVehData_Cnt_T_str;
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;
	
	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);

	if (D_SVCDFTRXMSGS_CNT_B32 != (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		/* Read VehSpd/VehCondition data */
		(void)Rte_Read_SG_V_VEH_SG_V_VEH(&RxVVehData_Cnt_T_str);

		VehSpdLossFltCounter_Cnt_M_u16 = 
		RxMsgDiag(VehSpdLossFltCounter_Cnt_M_u16, 
		          k_VehSpdLostMsgThres_Cnt_u16, 
		          NTC_Num_MissingMsg_O, 0x01U);

		/* Pass VehSpd/VehCondition (V_VEH) message data to ASIL_D application */
		(void)Rte_Write_SrlComSGVVEH_SG_V_VEH(&RxVVehData_Cnt_T_str);
	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_StCengLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <ST_CENG> of PortPrototype <ST_CENG>
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_StCengLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_StCengLoss
 *********************************************************************************************************************/
	StCengLossFltCounter_Cnt_M_u16 =
			LostMsgDiag (StCengLossFltCounter_Cnt_M_u16, k_StCengCntrLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AC, 0x01U);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_TuningSelLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SU_CLU_STMOM_SFE_DXP> of PortPrototype <SU_CLE_DRDY_DXP>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_TRGD_TuningSelLoss_CDRVDYNMSG_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_TuningSelLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_TuningSelLoss
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) CodingDrvDyn_Uls_T_lgc;
	CodingDrvDyn_Uls_T_lgc = Rte_IRead_SrlComInput_TRGD_TuningSelLoss_CDRVDYNMSG_Cnt_lgc();

	/* Only diagnose if the message is enabled */
	if(CodingDrvDyn_Uls_T_lgc == TRUE)
	{
		TuningSelLossFltCounter_Cnt_M_u16 = LostMsgDiag (TuningSelLossFltCounter_Cnt_M_u16, k_TuningSelLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_U, 0x01U);
	}
	else
	{
		/* Clear all faults if message is not received, but coding is turned off */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_U, 0x01U, NTC_STATUS_PASSED);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01U, NTC_STATUS_PASSED);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_U, 0x01U, NTC_STATUS_PASSED);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_VINLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <VIN_NO_VECH> of PortPrototype <RxVIN>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS(const SG_ANFRAGE_EPS *data)
 *   Std_ReturnType Rte_Write_VINValid_Cnt_lgc(Boolean data)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VINLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_VINLoss
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) VINMissingFlt_Cnt_lgc;
	VAR(SG_ANFRAGE_EPS, AUTOMATIC) SVCVinReqMsg_Cnt_T_str;
	
	/* Request VIN if not received and missing fault has not set */
	if (D_IDFNINQY_CNT_B16 == (D_IDFNINQY_CNT_B16 & SrlComSVCTxReq_Cnt_M_b16))
  	{
		/* Per anomaly 6773 if the VIN is missing, do not allow the fault to set in VehCfg */
		(void)Rte_Write_VINValid_Cnt_lgc(FALSE);

		VINLossFltCounter_Cnt_M_u16 = 
		LostMsgDiag (VINLossFltCounter_Cnt_M_u16, k_VINLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_W, 0x01U);
		
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_W, &VINMissingFlt_Cnt_lgc);
			
		if (FALSE == VINMissingFlt_Cnt_lgc)
		{	
			SVCVinReqMsg_Cnt_T_str.ID2_0x08_Mx01_EPS = D_BROADCASTREQUEST_CNT_U08;
			SVCVinReqMsg_Cnt_T_str.ID_FN_INQY_EPS = D_VINREQID_CNT_U16;

			(void)Rte_Write_SG_ANFRAGE_EPS_SG_ANFRAGE_EPS(&SVCVinReqMsg_Cnt_T_str);
		}
		else
		{	/* missing VIN - stop request */
			SrlComSVCTxReq_Cnt_M_b16 &= (uint16)(~(uint16)D_IDFNINQY_CNT_B16);
		}	
  	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_VYawVehLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <VYAW_VEH> of PortPrototype <VYAW_VEH>
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VYawVehLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_VYawVehLoss
 *********************************************************************************************************************/

	VyawVehLossFltCounter_Cnt_M_u16 =
			LostMsgDiag (VyawVehLossFltCounter_Cnt_M_u16, k_VYawVehCntrLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_AA, 0x01U);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_TRGD_VehSpdLoss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SG_V_VEH> of PortPrototype <SG_V_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_TRGD_VehSpdLoss(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_TRGD_VehSpdLoss
 *********************************************************************************************************************/

	VehSpdLossFltCounter_Cnt_M_u16 =
	LostMsgDiag (VehSpdLossFltCounter_Cnt_M_u16, k_VehSpdLostMsgThres_Cnt_u16, NTC_Num_MissingMsg_O, 0x01U);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Trns1
 *********************************************************************************************************************/
	/* Gather the system time at shutdown, write to TypeH */
	(void)SysTimeClient_GetTime(&StrdSysTime_Sec_M_u32);

	return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/* Missing Message Diagnostic */
STATIC INLINE FUNC(uint16, AP_SRLCOMINPUT_CODE) LostMsgDiag( VAR(uint16, AUTOMATIC) FaultCounter,
													 VAR(uint16, AUTOMATIC) Threshold,
													 VAR(uint16, AUTOMATIC) NTC,
													 VAR(uint8, AUTOMATIC) NTCParam)
{
	/* LostMsg P-Step */
	if (FaultCounter < Threshold)
	{
	    FaultCounter += D_LOSTMSGPSTEP_CNT_U16;
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC, NTCParam, NTC_STATUS_FAILED);
	}

	return (FaultCounter);
}


/* Rx Recovery Diagnostic */
STATIC INLINE FUNC(uint16, AP_SRLCOMINPUT_CODE) RxMsgDiag( VAR(uint16, AUTOMATIC) FaultCounter,
													 VAR(uint16, AUTOMATIC) Threshold,
													 VAR(uint16, AUTOMATIC) NTC,
													 VAR(uint8, AUTOMATIC) NTCParam)
{
	/* RxMsg N-Step */
	if (FaultCounter > 0U)
	{
		FaultCounter -= D_RXMSGNSTEP_CNT_U16;
	}
	if (FaultCounter < Threshold)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC, NTCParam, NTC_STATUS_PASSED);
	}

	return (FaultCounter);
}


/* Clear all signal diagnostic counters */
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ClearDiagCounters(void)
{
	VehSpdLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	TuningSelLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

 	SteaPniOffsLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;
 	SteaPniOffsInvalidCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;
 	SteaPniOffsErrorCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;
 	SteaPniOffsErrorRecovery_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

 	FZZSTDLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;
	MileKMLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

 	VINLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;
	VINVldCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;

	TarStMomLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;
	TarQtaStMomLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	RevOffsetLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	AclnyMassCntrLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	ConVehLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	VyawVehLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	CtrVibStwDispLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	StCengLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	EnergDgrDrdyLossFltCounter_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;
}


/* FZZSTD Receive Callout function */
FUNC(boolean, COM_VAR_NOINIT) Appl_COMCout_Pdu_FZZSTD(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, AUTOMATIC) SduPtr)
{
	FZZSTDLossFltCounter_Cnt_M_u16 =
	RxMsgDiag (FZZSTDLossFltCounter_Cnt_M_u16,
	           k_FZZSTDLostMsgThres_Cnt_u16,
	           NTC_Num_MissingMsg_Z, 0x01U);

	return(TRUE);
}


/* KILOMETERSTAND Receive Callout function */
FUNC(boolean, COM_VAR_NOINIT) Appl_COMCout_Pdu_KILOMETERSTAND(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, AUTOMATIC) SduPtr)
{
	MileKMLossFltCounter_Cnt_M_u16 =
	RxMsgDiag (MileKMLossFltCounter_Cnt_M_u16,
	           k_MileKMLostMsgThres_Cnt_u16,
	           NTC_Num_MissingMsg_X, 0x01U);

	return(TRUE);
}


/**************************************************************************************************
Function name    : Appl_DetEntryCallout
------------------------------------------------------------------------------------------------
Description      : Application callback to allow filtering of Development Error Events
**************************************************************************************************/
FUNC(uint8, DET_APPL_CODE) Appl_DetEntryCallout( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
{
	if ((ModuleId == D_FRTPMODULEID_CNT_U08) &&
       	(ApiId ==  D_FRTPMAINFUNCTSRVCID_CNT_U08) &&
       	(ErrorId == D_FRTPEIGNOREDRXPDU_CNT_U08) )
    {
    	IgnoreDET_Cnt_M_u08 = 0xAAU;
    }
    else
    {
    	IgnoreDET_Cnt_M_u08 = 0U;
    }

	return (IgnoreDET_Cnt_M_u08);
}


#if FR_VEXTENDED_CC_STATUS == STD_ON
/**************************************************************************************************
Function name    : ApplFr_CBK_CcErrorEvent
------------------------------------------------------------------------------------------------
Description      : Application callback to handle Communication Controller Errors
**************************************************************************************************/
FUNC(void, FR_APPL_CODE) ApplFr_CBK_CcErrorEvent(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr) /* PRQA S 3673 */ /* Generated file define. */
{
	if (CC_ERROR_ERRM_COMMHALT == (CC_ERROR_ERRM_COMMHALT & (*Fr_VErrorStatusPtr)) )
	{
		/* TODO: The direct setting of the customer DTC can be removed once DiagMgr is updated
		 *       to set the DTC Event immediately. This corrects anomaly 3570 */
		(void)DemIf_SetEventStatus(FR_COMM_FAILURE, DEM_EVENT_STATUS_FAILED);
		(void)NxtrDiagMgr9_SetNTCStatus(NTC_Num_FlexrayCommunicationError, 0x01U, NTC_STATUS_FAILED);
	}
}
#endif /* FR_VEXTENDED_CC_STATUS == STD_ON */


/**********************************************************************************************************************
  * Name:        ScaleSignal_f32
  * Description: Scales and limits the input signal based on the passed input parameters. Used for taking data passed
  * 			 via serial comm for use within the application.
  * Inputs:      Signal to be scaled, Limits, Scale and offset
  * Outputs:     returns scaled signal in floating point format.
  *
***********************************************************************************************************************/
STATIC FUNC(float32, AP_SRLCOMINPUT_CODE) ScaleSignal_f32(VAR(uint16, AUTOMATIC) Signal_Uls_T_u16, VAR(float32, AUTOMATIC) LoLmt_Uls_T_f32,
															VAR(float32, AUTOMATIC) HiLmt_Uls_T_f32, VAR(float32, AUTOMATIC) Scale_Uls_T_f32,
															VAR(float32, AUTOMATIC) Offset_Uls_T_f32)
{
	VAR(float32, AUTOMATIC) Signal_EngUnits_T_f32;

	Signal_EngUnits_T_f32 = ((float32)Signal_Uls_T_u16 * Scale_Uls_T_f32) + Offset_Uls_T_f32;
	Signal_EngUnits_T_f32 = Limit_m(Signal_EngUnits_T_f32, LoLmt_Uls_T_f32, HiLmt_Uls_T_f32);

	return(Signal_EngUnits_T_f32);
}

/**********************************************************************************************************************
  * Name       : CtrVibStwDisp_Diagnosis
  * Description: Diagnosis of EPS Vibration Pattern and Intensity level
  * Inputs     : if Autonomic mode = ACTIVE
  *       			CtrWarnPtrnVibEps - Autonomic Pattern variable
  *  				CtrWarnilvlVibEps - Autonomic Intensity Level variable
  *  			 else
  *       			CtrWarnPtrnVibEps - Vibration Pattern signal of CTR_VIB_STW message
  *  				CtrWarnilvlVibEps - Vibration Intensity level signal of CTR_VIB_STW message
  * Outputs    : void
***********************************************************************************************************************/
STATIC FUNC(void, AP_SRLCOMINPUT_CODE) CtrVibStwDisp_Diagnosis( VAR(New_Coding_71, AUTOMATIC) CtrWarnPtrnVibEps,
																VAR(New_Coding_75, AUTOMATIC) CtrWarnilvlVibEps
															  )
{

	VAR(New_Coding_71, AUTOMATIC) RxCtrWarnPtrnVibEps = 0x0u;
	VAR(New_Coding_75, AUTOMATIC) RxCtrWarnilvlVibEps = 0x0u;

	VAR(uint8, AUTOMATIC) InvldDataChk_Cnt_T_u8 = 0x0u;
	VAR(uint8, AUTOMATIC) UndefDataChk_Cnt_T_u8 = 0x0u;

	RxCtrWarnPtrnVibEps = CtrWarnPtrnVibEps;
	RxCtrWarnilvlVibEps = CtrWarnilvlVibEps;

	if((RxCtrWarnPtrnVibEps == CxF_Signal_unbefuellt) || (RxCtrWarnilvlVibEps == CxF_Signal_unbefuellt))
	  	{
	  		if(RxCtrWarnPtrnVibEps == CxF_Signal_unbefuellt)
	  		{
	  			HaptcFbPatSigVld_Cnt_M_lgc = FALSE;
	  			/* Increment counter for error, keep previous value */
	  	  		if(InvldEPSVibPatternCntr_Cnt_M_u8 >= D_RXMSGINVALID_CNT_U08)
	  	  		{
	  	  			InvldEPSVibPatternCntr_Cnt_M_u8 = D_RXMSGINVALID_CNT_U08;
	  	  			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AE, 0x01U, NTC_STATUS_FAILED);
	  	  		}
	  	  		else
	  	  		{
	  	  			InvldEPSVibPatternCntr_Cnt_M_u8++;
	  	  		}
	  		}

	  		if(RxCtrWarnilvlVibEps == CxF_Signal_unbefuellt)
	  		{
	  			HaptcFbIntenSigVld_Cnt_M_lgc = FALSE;
	  			/* Increment counter for error, keep previous value */
	  	  		if(InvldEPSVibInteLvlCntr_Cnt_M_u8 >= D_RXMSGINVALID_CNT_U08)
	  	  		{
	  	  			InvldEPSVibInteLvlCntr_Cnt_M_u8 = D_RXMSGINVALID_CNT_U08;
	  	  			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AE, 0x01U, NTC_STATUS_FAILED);
	  	  		}
	  	  		else
	  	  		{
	  	  			InvldEPSVibInteLvlCntr_Cnt_M_u8++;
	  	  		}
	  		}
	  	}
	  	else
	  	{
	  		/* Signal is valid, update counters and update output */
	  		if(InvldEPSVibPatternCntr_Cnt_M_u8 > D_ZERO_CNT_U8)
	  		{
	  			InvldEPSVibPatternCntr_Cnt_M_u8--;
	  		}
	  		else
	  		{
	  			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AE, 0x01U, NTC_STATUS_PASSED);
	  		}

	  		/* Signal is valid, update counters and update output */
	  		if(InvldEPSVibInteLvlCntr_Cnt_M_u8 > D_ZERO_CNT_U8)
	  		{
	  			InvldEPSVibInteLvlCntr_Cnt_M_u8--;
	  		}
	  		else
	  		{
	  			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AE, 0x01U, NTC_STATUS_PASSED);
	  		}

	  		/* Update output and previous value if no faults */
	  		(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_AE, &InvldDataChk_Cnt_T_u8);
	  		(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataOtherFltMsg_AE, &UndefDataChk_Cnt_T_u8);

			if((InvldDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8)
			{
			   /* Update Control Warning EPS Vibration Pattern */
				if((RxCtrWarnPtrnVibEps == CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) ||
				   (RxCtrWarnPtrnVibEps == CxE_Funktion_meldet_Fehler))
				{
					HaptcFbPatSigVld_Cnt_M_lgc = FALSE;
				}
				else if((RxCtrWarnPtrnVibEps >= Cx0_Keine_haptische_Warnung) &&	(RxCtrWarnPtrnVibEps <= CxA_Muster_10))
				{
					HaptcFbPatNrValidValue_Cnt_M_u08 = RxCtrWarnPtrnVibEps;
					HaptcFbPatSigVld_Cnt_M_lgc = TRUE;
				}
			}

			if((UndefDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8)
			{
			   /* Update Control Warning EPS Intensity Level */
				if((RxCtrWarnilvlVibEps >= Cx0_Intensitaetsstufe_0) && (RxCtrWarnilvlVibEps <= CxC_Intensitaetsstufe_12))
				{
					HaptcFbIntenNrValidValue_Cnt_M_u08 = RxCtrWarnilvlVibEps;
					HaptcFbIntenSigVld_Cnt_M_lgc = TRUE;
				}
			}
	  	}

			(void)Rte_Write_HaptcFbPatNr_Cnt_u16((uint16)HaptcFbPatNrValidValue_Cnt_M_u08);
			(void)Rte_Write_HaptcFbPatSigVld_Cnt_lgc(HaptcFbPatSigVld_Cnt_M_lgc);
			(void)Rte_Write_HaptcFbIntenNr_Cnt_u16((uint16)HaptcFbIntenNrValidValue_Cnt_M_u08);
			(void)Rte_Write_HaptcFbIntenSigVld_Cnt_lgc(HaptcFbIntenSigVld_Cnt_M_lgc);

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
