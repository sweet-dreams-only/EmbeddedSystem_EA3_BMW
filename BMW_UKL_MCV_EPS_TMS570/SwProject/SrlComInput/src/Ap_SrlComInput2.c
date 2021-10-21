/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComInput2.c
 *     Workspace:  C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/SwProject/SrlComInput/autosar
 *     SW-C Type:  Ap_SrlComInput2
 *  Generated at:  Thu Jun  1 11:56:28 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComInput2>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar 15 17:16:01 2011
 * %version:          EA3#36 %
 * %derived_by:       nz2378 %
 * %date_modified:    Fri Oct 11 17:02:23 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	          SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	        ----------
 * 10/24/12	  1	      BDO		Initial version of SrComInput2 ASIL_D component from SrlComInput application split.     CR6627
 * 01/07/13	  3	      KJS		Updated alive counter diagnostics for E2EP signals.
 * 01/15/13	  4,5	  KJS		Updates to support Valid Veh Spd for Sweep module.
 * 03/06/13	  6		  KJS		SER updates and QAC corrections.
 * 04/12/13	  7		  KJS		Corrected anomaly 4448 for engine crank status in Per1
 * 04/25/13	  8		  KJS		Corrected anomaly 4674
 * 04/27/13	  9		  BWL		Corrected anomaly 4639
 * 04/27/13	  10	  BWL		Corrected anomaly 4661
 * 04/30/13	  11	  BWL		Corrections for anomaly 4661, and 4639
 * 04/30/13	  12	  BWL		Corrected anomaly 4933
 * 05/09/13	  13	  KJS		Corrected anomaly 4960.
 * 05/22/13	  14	  SP		Corrected anomaly 5037 and 5033															8390
 * 05/30/13	  15	  KJS		Corrected release tag, no src changes. 
 * 06/07/13   16      NRAR      Corrected for anomaly 4873 (MSA)                                                        8595
 * 06/17/13	  17	  KJS		Corrected anomaly 5112 - CRCErrorActivePrkAst											8662
 * 06/20/13	  18	  KJS		Corrected anomaly 5161
 * 10/07/13	  19	  KJS		Added support for TJA.
 * 10/11/13	  20	  KJS		Anomaly 5852 correction.
 * 12/28/16	  24	  KJS		Anomaly 6327 correction.
 * 03/09/16	  24	  ABS		QAC correction.
 * 05/26/16	  26	  ABS		Updated for SCIR 002A																	7977
 * 06/15/16	  26	  ABS		Updated for SCIR 002A																	7977
 * 06/29/16	  27	  ABS		Updated NTCs for ACLNY_MASSCNTR message	and SCIR 002B   								7977
 * 07/18/16	  28	  ABS		Updated for SCIR 002D   															EA3#9684
 * 11/02/16	  29	  ABS		BMW Torque Overlay Updates    														EA3#11165
 * 11/11/16	  30	  ABS		BMW Torque Overlay Updates - correction after dev. sprint testing					EA3#11165
 * 11/19/16	  31	  ABS		Integrate Torque Overlay Issues														EA3#12713
 * 05/05/17	  34	  JK		Component initialization update
 * 05/26/17   35      SWI		Removing DynDrv functionality (moved to BmwTqOvrlCdng swc)							EA3#12890
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
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenfuhrung der Signalklasse Alive_Zahler_Geschwindigkeit [1] mit den Parametern AliveSpeed [1].

  CRC8
    Standartabsicherung Apllikations-CRC.

  CRC_V_VEH
    Standartabsicherung Apllikations-CRC.
     
     				Transp.MOST-GW-Migration, 01.09.2006: Zusammenfuhrung der Signalklasse CRC_Geschwindigkeit_Fahrzeug [1] mit den Parametern ChecksumSpeedCRC [1].

  V_VEH_COG
    Transp.MOST-GW-Migration, 01.09.2006: Zusammenfuhrung der Signalklasse Geschwindigkeit_Fahrzeug_Schwerpunkt [2] mit den Parametern CarSpeedExt [1].

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComInput2.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_SrlComInput2_Cfg.h"
#include "Com.h"
#include "Com_Cbk.h"
#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CheckSums.h"
#include "SystemTime.h"
#include "E2E_P01.h"
#include "CDD_Data.h"
#include "filters.h"
#include "interpolation.h"

#include "Dem.h"


/* E2EP Header Files */
#include "E2EPW_Ap_SrlComInput2_SrlComSGOFFSQUADEPS_SrlComSGOFFSQUADEPS_rx.h"
#include "E2EPW_Ap_SrlComInput2_SrlComSGTARQTASTRMOMDV_SrlComSGTARQTASTRMOMDV_rx.h"
#include "E2EPW_Ap_SrlComInput2_SrlComSGTARSTMOMDVACT_SrlComSGTARSTMOMDVACT_rx.h"
#include "E2EPW_Ap_SrlComInput2_SrlComSGVVEH_SrlComSGVVEH_rx.h"
#include "E2EPW_Ap_SrlComInput2_SrlComACLNYMASSCNTR_SrlComACLNYMASSCNTR_rx.h"
#include "E2EPW_Ap_SrlComInput2_SrlComVYAWVEH_SrlComVYAWVEH_rx.h"
#include "E2EPW_Ap_SrlComInput2_SrlComCONVEH_SrlComCONVEH_rx.h"
#include "E2EPW_Ap_SrlComInput2_SrlComSTCENG_SrlComSTCENG_rx.h"


/* Fault Counters (Invalid,Missing,AliveCnt,Error) */
#define D_INVALIDALIVECOUNT_CNT_U08			15U
#define D_RXMSGINVALID_CNT_U08				3U
#define D_CRCERRCOUNTFAULT_CNT_U08			3U
#define D_ALIVECOUNTFAULT_CNT_U08			3U
#define D_ERRORCOUNTFAULT_CNT_U08			3U

#define D_LOSTMSGPSTEP_CNT_U16				5U
#define D_RXMSGNSTEP_CNT_U16				1U

/* Mask Bits */
#define D_MSBYTESHIFT_CNT_U08				24U

/* VehSpd */
#define D_VEHSPDINVALID_CNT_U16				3U
#define D_VEHSPDSCALE_KPHPCNT_U10P6			FPM_InitFixedPoint_m(0.015625, u10p6_T)
#define D_VEHSPDHILMT_KPH_U10P6				FPM_InitFixedPoint_m(350.0, u10p6_T)
#define D_VEHSPDLOLMT_KPH_U10P6				FPM_InitFixedPoint_m(0.0, u10p6_T)
#define D_MAXVEHSPD_CNT_U16					0x5780U
#define D_MAXVEHDRVCOND_CNT_U08				5U

/* VYAW_VEH */
#define D_VYAWVEHFACTOR_ULS_F32				(0.005F)
#define D_VYAWVEHOFFSET_ULS_F32				(-163.84F)
#define D_VYAWVEHZERO_CNT_U16				0x8000U

#define D_QUVALIDGUARANTEED_CNT_U08			0x01U
#define D_QUVALIDTEMP_CNT_U08				0x0AU
#define D_QUALINVALID_CNT_U08				0x0FU
#define D_QUALINVALSTATETEMP_CNT_U08		0x0EU
#define D_QUALLIMMONTTEMPID_CNT_U08			0x0BU

/* Lateral Acceleration */
#define D_ACLNYCOGINVALID_CNT_U08			0xFFFFU
#define D_QUACLNYCOGINVALID_CNT_U08			0xFU
#define D_ACLNYCOGFACTOR_ULS_F32			(0.002F)
#define D_ACLNYCOGOFFSET_ULS_F32			(-65.0F)
#define D_ACLNYCOGZERO_CNT_U16				0x7EF4U

/* Yaw Rate */
#define D_VYAWVEHINVALID_CNT_U08			0xFFFFU
#define D_QUVYAWVEHINVALID_CNT_U08			0xFU

/* Park Assist, Driving Dynamics, & Torque Overlay */
#define D_RQSTFACTSCALE_ULSPCNT_u8p8		FPM_InitFixedPoint_m(0.00390625, u8p8_T)
#define D_ASTFACTOFFSET_CNT_U16				256U			
#define D_ASTFACTLOLMT_ULS_F32				1.0F
#define D_ASTFACTHILMT_ULS_F32				1.9921875F

#define D_RTNFACTOFFSET_CNT_U16				2U					
#define D_RTNFACTLOLMT_ULS_F32				0.0078125F
#define D_RTNFACTHILMT_ULS_F32				1.0F

#define D_DMPFACTOFFSET_CNT_U16				2U
#define D_DMPFACTLOLMT_ULS_F32				0.0078125F
#define D_DMPFACTHILMT_ULS_F32				1.0F

#define D_IPTRQOVOFFSET_CNT_U16				2000U				
#define D_IPTRQOVSCALE_NMPCNT_u0p16			FPM_InitFixedPoint_m(0.005, u0p16_T)			
#define D_IPTRQOVLOLMT_ULS_F32				(-10.0F)
#define D_IPTRQOVHILMT_ULS_F32				10.0f

#define D_OPTRQOVOFFSET_CNT_U16				2000U
#define D_OPTRQOVSCALE_NMPCNT_u0p16			FPM_InitFixedPoint_m(0.006, u0p16_T)	

#define D_PRKASTHWAOFFSET_CNT_U16			32767U
#define D_PRKASTHWASCALE_HWDEGPCNT_u0p16	FPM_InitFixedPoint_m(0.04395, u0p16_T)
#define D_PRKASTHWALOLMT_HWDEG_F32			(-1440.11F)
#define D_PRKASTHWAHILMT_HWDEG_F32			1440.11F

#define D_TJASCALE_ULSPCNT_F32				0.015625F
#define D_TJALOLMT_ULS_F32					0.0F
#define D_TJAHILMT_ULS_F32					2.0F

#define D_2MS_SEC_F32						(0.002F)
/* Rev Offset Signal */
#define D_REVOFFSETMSGOFFSET_CNTS_U08		127U
#define D_REVOFFSETLOLMT_CNTS_S08			(-127)
#define D_REVOFFSETHILMT_CNTS_S08			127
#define D_MAXREVOFFSETSTATUS_CNT_U08		7U
#define D_INVALIDREVOFFSET_CNT_U08			255U

/* Park Assist Interface override values */
#define D_CODINGDFLTANGQU_CNT_U08			0x0EU
#define D_CODINGDFLTANG_HWDEG_F32			0.0F

/* Drive Dynamics Interface override values */
#define D_CODINGDFLTASTFACT_ULS_F32			1.0F
#define D_CODINGDFLTRTNFACT_ULS_F32			1.0F
#define D_CODINGDFLTDMPFACT_ULS_F32			1.0F
#define D_CODINGDFLTFACTQU_CNT_U08			0x0EU

#define D_CODINGDFLTIPTRQOV_HWNM_F32		0.0F
#define D_CODINGDFLTIPTRQOVQU_CNT_U08		0x0EU

#define D_CODINGDFLTOPTRQOV_MTRNM_F32		0.0F
#define D_CODINGDFLTOPTRQOVQU_CNT_U08		0x0EU

#define D_RESETDIAGCOUNTERS_CNT_U08			0x00U

#define D_DEBOUNCECLEARTHRESH_CNT_U16		3u

#define D_NTCFAILED_CNT_U08					0x01u

#define D_10MS_SEC_F32                		0.01F
#define D_ZERO_MTRNM_F32					0.0F
#define D_ZERO_MTRNM_U16					0x00U

#define SRLCOMINPUT2_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(float32, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpd_Kph_M_f32;

STATIC VAR(float32, AP_SRLCOMINPUT2_VAR_NOINIT) FinalAstFactRqst_Uls_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT2_VAR_NOINIT) FinalRtnFactRqst_Uls_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT2_VAR_NOINIT) FinalDmpFactRqst_Uls_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT2_VAR_NOINIT) FinalIpTrqOvRqst_HwNm_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT2_VAR_NOINIT) FinalOpTrqOvRqst_MtrNm_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT2_VAR_NOINIT) TJADampSclRqst_Uls_M_f32;
STATIC VAR(uint32, AP_SRLCOMINPUT2_VAR_NOINIT) StartUpDTCMaskTimer_Cnt_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT2_VAR_NOINIT) StCengDrvUpateTimer_Cnt_M_u32;

#define SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */

#define SRLCOMINPUT2_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(SG_ST_CENG, AP_SRLCOMINPUT2_VAR_NOINIT) RxStCeng_M_Str;
#define SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */


#define SRLCOMINPUT2_START_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdQFErrorRecovery_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdErrorRecovery_Cnt_M_u16;

STATIC VAR(uint16, AP_SRLCOMINPUT2_VAR_NOINIT) OpTrqOvDbnceCntr_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT2_VAR_NOINIT) OpTrqOvDbnceClearCntr_Cnt_M_u16;

STATIC VAR(sint16, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffset_Cnt_M_s16;
#define SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */


#define SRLCOMINPUT2_START_SEC_VAR_CLEARED_8
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdVldCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdAliveFault_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdAliveRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdCRCErrorCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdCRCErrorRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdQFErrorCounter_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdErrorCounter_Cnt_M_u08;

STATIC VAR(ST_V_VEH_NSS, AP_SRLCOMINPUT2_VAR_NOINIT) VehNss_Cnt_M_u08;
STATIC VAR(DVCO_VEH, AP_SRLCOMINPUT2_VAR_NOINIT) VehDrvCond_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) DrvDynRqstVldCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) DrvDynRqstErrorRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) IpTrqOvRqstVldCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) IpTrqOvRqstErrorRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) OpTrqOvRqstVldCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) OpTrqOvRqstErrorRecovery_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) TarQtaStMomAliveFault_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) TarQtaStMomAliveRecovery_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) TarQtaStMomCRCErrorCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) TarQtaStMomCRCErrorRecovery_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) AclnyMassCntrAliveFault_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) AclnyMassCntrAliveRecovery_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) AclnyMassCntrCRCErrorCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) AclnyMassCntrCRCErrorRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) AclnyMassCntrVldCounter_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VYawVehCntrAliveFault_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VYawVehCntrAliveRecovery_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VYawVehCntrCRCErrorCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VYawVehCntrCRCErrorRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) VYawVehVldCounter_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) ConVehAliveFault_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) ConVehAliveRecovery_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) ConVehCRCErrorCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) ConVehCRCErrorRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) ConVehInVldCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) ConVehUndefCounter_Cnt_M_u08;
STATIC VAR(New_Coding_64, AP_SRLCOMINPUT2_VAR_NOINIT) ConVehValidValue_Cnt_M_u8;
STATIC VAR(New_Coding_64, AP_SRLCOMINPUT2_VAR_NOINIT) ConVehPreValue_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) StCengCntrAliveFault_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) StCengCntrAliveRecovery_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) StCengCntrCRCErrorCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) StCengCntrCRCErrorRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) StCengDrvInVldCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) StCengDrvUndefCounter_Cnt_M_u08;
STATIC VAR(New_Coding_104, AP_SRLCOMINPUT2_VAR_NOINIT) RxStCengDrv_Cnt_M_u08;
STATIC VAR(New_Coding_104, AP_SRLCOMINPUT2_VAR_NOINIT) RxStCengDrvPrev_Cnt_M_u08;

STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) TarStMomCRCErrorCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) TarStMomCRCErrorRecovery_Cnt_M_u08;

STATIC VAR(QU_TAR_FACT_STMOM_FTAX, AUTOMATIC) RxAstRtnDmpFactQual_Cnt_M_u08;
STATIC VAR(QU_TAR_QTA_STMOM_DV, AUTOMATIC) RxTarQtaStMomQual_Cnt_M_u08;
STATIC VAR(QU_TAR_STMOM_DV_ACT, AUTOMATIC) RxTarStMomQual_Cnt_M_u08;

STATIC VAR(uint8, AUTOMATIC) TarQtaStMomQualCounter_Cnt_M_u08;
STATIC VAR(uint8, AUTOMATIC) TarQtaStMomQualErrRecovery_Cnt_M_u08;

STATIC VAR(uint8, AUTOMATIC) AstRtnDmpFactQualCounter_Cnt_M_u08;
STATIC VAR(uint8, AUTOMATIC) AstRtnDmpFactQualErrRecovery_Cnt_M_u08;

STATIC VAR(uint8, AUTOMATIC) TarStMomDvActQualCounter_Cnt_M_u08;
STATIC VAR(uint8, AUTOMATIC) TarStMomDvActQualErrRecovery_Cnt_M_u08;

STATIC VAR(uint8, AUTOMATIC) TarDmpAddonStMomFtaxQualCounter_Cnt_M_u08;
STATIC VAR(uint8, AUTOMATIC) TarDmpAddonStMomFtaxQualRecovery_Cnt_M_u08;

STATIC VAR(ST_OFFS_QUAD_EPS, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffsetStatus_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffsetVldCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffsetStatusErrCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffsetAliveFault_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffsetAliveRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffsetCRCErrorCounter_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffsetCRCErrorRecovery_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT2_VAR_NOINIT) RevOffsetErrorRecovery_Cnt_M_u08;

#define SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"/* PRQA S 5087 */


#define SRLCOMINPUT2_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(boolean, AP_SRLCOMINPUT2_VAR_NOINIT) InvalidVehSpdQual_Cnt_M_lgc;

STATIC VAR(boolean, AP_SRLCOMINPUT2_VAR_NOINIT) InvldDrvDynSgnl_Cnt_M_lgc;

STATIC VAR(boolean, AP_SRLCOMINPUT2_VAR_NOINIT) VehSpdValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT2_VAR_NOINIT) SrlComEngCrank_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT2_VAR_NOINIT) StartUpDTCMaskActive_Cnt_M_lgc;

STATIC VAR(boolean, AP_SRLCOMINPUT2_VAR_NOINIT) STCENGDRVInvalid_Cnt_M_lgc;


#define SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"/* PRQA S 5087 */

STATIC FUNC (boolean, AP_SRLCOMINPUT2_CODE) CRCAliveCntDiag ( VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode,
													         VAR(uint8, AUTOMATIC) RxAliveCnt,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) AliveFaultCount,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) AliveFaultRecovery,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) CRCErrorCount,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) CRCErrorRecovery,
													         VAR(uint16, AUTOMATIC) AliveFaultNTC,
													         VAR(uint16, AUTOMATIC) CRCErrorNTC);


STATIC FUNC (void, AP_SRLCOMINPUT2_CODE) VehSpdQFDiag( VAR(uint8, AUTOMATIC) RxVehSpdQF);

STATIC FUNC(void, AP_SRLCOMINPUT2_CODE) ClearDiagCounters(void);

STATIC FUNC (boolean, AP_SRLCOMINPUT2_CODE) TrqOvDebounce ( VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode,
															VAR(uint8, AUTOMATIC) RxAliveCnt,
													        P2VAR(uint8, AUTOMATIC, AUTOMATIC) DrvDynEnable);

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
 * FACT_ASS_STMOM_FTAX: Integer in interval [0...254]
 * FACT_CTRR_STMOM_FTAX: Integer in interval [0...254]
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
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
 * OFFS_QUAD_PINA_EPS: Integer in interval [0...254]
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * STMOM_QTA_DV: Integer in interval [0...4000]
 * TAR_STMOM_DV_ACT: Integer in interval [0...4000]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 * V_VEH_COG: Integer in interval [0...22400]
 *
 * Enumeration Types:
 * ==================
 * ALIV_COU_4: Enumeration of integer in interval [0...15] with enumerators
 *   CxF_Signal_ungueltig (15U)
 * ALIV_COU_V: Enumeration of integer in interval [0...15] with enumerators
 *   CxF_Signal_ungueltig (15U)
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
 *   NTC_Num_IMCLossOfCom (125U)
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
 *   NTC_Num_ImcSigArbHighOffsetCorrection (151U)
 *   NTC_Num_EcuConfigMismatch (152U)
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
 *   NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_PHAScratchPadTrf (503U)
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
 * New_Coding_83: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Keine_Deaktivierung_EPS_Funktionen (0U)
 *   Cb0xx1_Deaktivierung_EPS_Funktionen__Funktionsgruppe_1 (0U)
 *   Cb0x1x_Deaktivierung_EPS_Funktionen__Funktionsgruppe_2 (0U)
 *   CxD_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   CxE_Funktion_meldet_Fehler (14U)
 *   CxF_Signal_unbefuellt (15U)
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
 * ST_OFFS_QUAD_EPS: Enumeration of integer in interval [0...15] with enumerators
 *   STOFFSQUADEPS_SLEEP (0U)
 *   STOFFSQUADEPS_CALCULATED (1U)
 *   STOFFSQUADEPS_INDEX (2U)
 *   STOFFSQUADEPS_MODELCOMP (3U)
 *   STOFFSQUADEPS_LOCKTOLOCK (4U)
 *   STOFFSQUADEPS_SUMSTEERINGANGLE (5U)
 *   STOFFSQUADEPS_CHECK (6U)
 *   STOFFSQUADEPS_CORRECTION (7U)
 *   STOFFSQUADEPS_INITIALIZATION (8U)
 *   STOFFSQUADEPS_DETERMINED (9U)
 *   STOFFSQUADEPS_APPROXIMATED (11U)
 *   STOFFSQUADEPS_INVALID (15U)
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
 * TJAStateType: Enumeration of integer in interval [1...3] with enumerators
 *   TJA_Inactive (1U)
 *   TJA_Active (2U)
 *   TJA_Error (3U)
 *
 * Record Types:
 * =============
 * SG_ACLNY_MASSCNTR: Record with elements
 *   ACLNY_COG_ERR_AMP of type New_Coding_37
 *   ALIV_ACLNY_COG of type New_Coding_35
 *   QU_ACLNY_COG of type New_Coding_38
 *   ACLNY_MASSCNTR_0x0C_0x04 of type CD_0x04
 *   ACLNY_COG of type New_Coding_36
 *   CRC_ACLNY_COG of type New_Coding_34
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


#define RTE_START_SEC_AP_SRLCOMINPUT2_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_Init
 *********************************************************************************************************************/
	E2EPW_Init_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS_rx();
	E2EPW_Init_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV_rx();
	E2EPW_Init_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT_rx();
	E2EPW_Init_SrlComSGVVEH_SG_V_VEH_rx();
	E2EPW_Init_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR_rx();
	E2EPW_Init_SrlComVYAWVEH_VYAW_VEH_rx();
	E2EPW_Init_SrlComCONVEH_CON_VEH_rx();
	E2EPW_Init_SrlComSTCENG_ST_CENG_rx();

	/* enter crank state - MASK DTCS */
	SrlComEngCrank_Cnt_M_lgc = TRUE;

	GetSystemTime_mS_u32(&StartUpDTCMaskTimer_Cnt_M_u32);
	StartUpDTCMaskActive_Cnt_M_lgc = TRUE;

	ConVehValidValue_Cnt_M_u8 = 0x00U;
    ConVehPreValue_Cnt_M_u08 = 0x00U;
  
    RxStCengDrvPrev_Cnt_M_u08 = 0x0U;

	/* Alternator Diagnostic - to enable measuring time after entering drive state */
	CDD_InitialTimeLockout_Cnt_G_lgc = FALSE;



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_Per1
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
 *   Boolean Rte_IRead_SrlComInput2_Per1_DiagStsDefVehSpd_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput2_Per1_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComDrvDynInvalid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput2_Per1_VehSpdValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput2_Per1_VehSpdValid_Cnt_lgc(void)
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_Per1
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) TarStMomMissingFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TarQtaStMomMissingFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TarStMomAliveFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TarQtaStMomAliveFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TarStMomCRCFlt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TarQtaStMomCRCFlt_Cnt_T_lgc;
	
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;
	VAR(boolean, AUTOMATIC) DiagStsDefVehSpd_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) StCengMissingFlt_Cnt_T_lgc;
	
	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) DrvDynInvalid_Cnt_T_lgc;

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_SrlComInput2_Per1_CP0_CheckpointReached();
  
    /* Initialise the variable to false */
    DrvDynInvalid_Cnt_T_lgc = FALSE;
	
	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);
    DiagStsDefVehSpd_Cnt_T_lgc = Rte_IRead_SrlComInput2_Per1_DiagStsDefVehSpd_Cnt_lgc();

	if ((D_SVCDFTRXMSGS_CNT_B32 == (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32)))
	{
		ClearDiagCounters();
	}
	else
	{	
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_AC, &StCengMissingFlt_Cnt_T_lgc);

		if (SrlComEngCrank_Cnt_M_lgc == TRUE)
		{
		  /* crank state - check conditions to enter normal state */
		   ClearDiagCounters();

		  if((STCENGDRVInvalid_Cnt_M_lgc == TRUE) ||
		     (StCengMissingFlt_Cnt_T_lgc == TRUE) ||
		     (RxStCengDrv_Cnt_M_u08 != Cx1_Motor_startet))
		  {
			 /* signal is invalid, missing or not in crank */
		 	 DtrmnElapsedTime_mS_u32(StCengDrvUpateTimer_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);

			if (ElapsedTime_Cnt_T_u32 > k_StCengDrvHold_mS_u16)
			{   /* exit crank state - UNMASK DTCS */
				SrlComEngCrank_Cnt_M_lgc = FALSE;
			}
		  }
		  else
		  {   /* signal is valid and still in crank */
		 		GetSystemTime_mS_u32(&StCengDrvUpateTimer_Cnt_M_u32);
		  }
		}
		else
		{
			if(RxStCengDrv_Cnt_M_u08 == Cx1_Motor_startet)
			{
				/* enter crank state - MASK DTCS */
				SrlComEngCrank_Cnt_M_lgc = TRUE;
				GetSystemTime_mS_u32(&StCengDrvUpateTimer_Cnt_M_u32);
			}
		}

		
		/* STARTUP ERROR MASKING */
		if (StartUpDTCMaskActive_Cnt_M_lgc == TRUE)
		{
			Rte_IWrite_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc(TRUE);
			ClearDiagCounters();
			DtrmnElapsedTime_mS_u32(StartUpDTCMaskTimer_Cnt_M_u32, &ElapsedTime_Cnt_T_u32);

			if (ElapsedTime_Cnt_T_u32 > k_StartUpDTCMaskTime_mS_u16)
			{
				StartUpDTCMaskActive_Cnt_M_lgc = FALSE;
			}
		}
		else
		{
			Rte_IWrite_SrlComInput2_Per1_SrlComEngCrank_Cnt_lgc(SrlComEngCrank_Cnt_M_lgc);
		}

		/* DD_ErrInterface_Active logic */
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_S, &TarStMomMissingFlt_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_R, &TarQtaStMomMissingFlt_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PgrsCntFltMsg_S, &TarStMomAliveFlt_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PgrsCntFltMsg_R, &TarQtaStMomAliveFlt_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_CRCFltMsg_S, &TarStMomCRCFlt_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_CRCFltMsg_R, &TarQtaStMomCRCFlt_Cnt_T_lgc);
	 	
	 	if ( (TarStMomMissingFlt_Cnt_T_lgc == TRUE) ||
			 (TarQtaStMomMissingFlt_Cnt_T_lgc == TRUE) || 
			 (TarStMomAliveFlt_Cnt_T_lgc == TRUE) ||
			 (TarQtaStMomAliveFlt_Cnt_T_lgc == TRUE) ||
			 (TarStMomCRCFlt_Cnt_T_lgc == TRUE) ||
			 (TarQtaStMomCRCFlt_Cnt_T_lgc == TRUE) ||
			 (InvldDrvDynSgnl_Cnt_M_lgc == TRUE) )
	 	{
			DrvDynInvalid_Cnt_T_lgc = TRUE;
	 	}
	 	
		(void)Rte_Write_SrlComDrvDynInvalid_Cnt_lgc(DrvDynInvalid_Cnt_T_lgc);

		/* VEHICLE SPEED OUTPUT DETERMINATION */
		if ( (DiagStsDefVehSpd_Cnt_T_lgc == TRUE) ||
			 (InvalidVehSpdQual_Cnt_M_lgc == TRUE) )
		{
			(void)Rte_Write_SrlComVehSpd_Kph_f32(k_DfltVehSpd_Kph_M_f32);
			VehSpdValid_Cnt_M_lgc = FALSE;
		}
		else
		{
			VehSpdValid_Cnt_M_lgc = TRUE;
		}
	}
	
	Rte_IWrite_SrlComInput2_Per1_VehSpdValid_Cnt_lgc(VehSpdValid_Cnt_M_lgc);
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_SrlComInput2_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_Scom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_SCom_ManualVehSpd
 *********************************************************************************************************************/
	(void)Rte_Write_SrlComVehSpd_Kph_f32(VehSpd_Kph_f32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxAclnyMassCntr
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ACLNY_MASSCNTR> of PortPrototype <SrlComACLNYMASSCNTR>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(SG_ACLNY_MASSCNTR *data)
 *   boolean Rte_IsUpdated_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Read_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(SG_ACLNY_MASSCNTR *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVehLatAccel_MpSecSq_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehLatAccelValid_Cnt_lgc(Boolean data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxAclnyMassCntr(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_TRGD_RxAclnyMassCntr
 *********************************************************************************************************************/

	VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode_Cnt_T_u08;
	VAR(New_Coding_35, AUTOMATIC) RxAliveCounter_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) CRCErrorAclnyMassCntr_Cnt_T_lgc = FALSE;
	VAR(uint32, AUTOMATIC) E2EPWErrorCode_Cnt_T_u32 = 0U;

	VAR(SG_ACLNY_MASSCNTR, AUTOMATIC) RxAclnyMassCntr_T_Str;
	VAR(New_Coding_36, AUTOMATIC) AclnyCog_Cnt_T_u16;
	VAR(New_Coding_36, AUTOMATIC) AclnyCogValidValue_Cnt_T_u16;
	VAR(New_Coding_38, AUTOMATIC) QuAclnyCog_Cnt_T_u8;

	VAR(uint8, AUTOMATIC) InvldDataChk_Cnt_T_u8;
	VAR(float32, AUTOMATIC) LateralAccel_MpSecSq_T_f32 = 0.0f;

	VAR(boolean, AUTOMATIC) LatAccelValid_Cnt_T_lgc = FALSE;

	/* Receive Lateral Acceleration (ACLNY_MASSCNTR) message data */
		E2EPWErrorCode_Cnt_T_u32 = E2EPW_Read_SrlComACLNYMASSCNTR_ACLNY_MASSCNTR(&RxAclnyMassCntr_T_Str);

 		RxAliveCounter_Cnt_T_u08 = RxAclnyMassCntr_T_Str.ALIV_ACLNY_COG;

 		CRCAliveCntErrorCode_Cnt_T_u08 = (uint8)(E2EPWErrorCode_Cnt_T_u32 >> D_MSBYTESHIFT_CNT_U08);
        CRCErrorAclnyMassCntr_Cnt_T_lgc = CRCAliveCntDiag (CRCAliveCntErrorCode_Cnt_T_u08,
                                                          RxAliveCounter_Cnt_T_u08,
                                                          &AclnyMassCntrAliveFault_Cnt_M_u08,
                                                          &AclnyMassCntrAliveRecovery_Cnt_M_u8,
                                                          &AclnyMassCntrCRCErrorCounter_Cnt_M_u08,
                                                          &AclnyMassCntrCRCErrorRecovery_Cnt_M_u08,
                                                          NTC_Num_PgrsCntFltMsg_AF,
                                                          NTC_Num_CRCFltMsg_AF);

 		AclnyCog_Cnt_T_u16 = RxAclnyMassCntr_T_Str.ACLNY_COG;
 		QuAclnyCog_Cnt_T_u8 = RxAclnyMassCntr_T_Str.QU_ACLNY_COG;

       if((AclnyCog_Cnt_T_u16 == D_ACLNYCOGINVALID_CNT_U08) || (QuAclnyCog_Cnt_T_u8 == D_QUACLNYCOGINVALID_CNT_U08))
       {
        	/* Increment counter for error, keep previous value */
        	if(AclnyMassCntrVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
        	{
        		AclnyMassCntrVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
        	   (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AF, 0x01U, NTC_STATUS_FAILED);
        	}
        	else
        	{
        		AclnyMassCntrVldCounter_Cnt_M_u08++;
        	}
       }
       else
       {
			/* Signal is valid, update counters and update output */
			if(AclnyMassCntrVldCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
			{
				AclnyMassCntrVldCounter_Cnt_M_u08--;
			}
			else
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AF, 0x01U, NTC_STATUS_PASSED);
			}

     		if((QuAclnyCog_Cnt_T_u8 == Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert) ||
     		   (QuAclnyCog_Cnt_T_u8 == Cx2_Signalwert_ist_gueltig) ||
     		   (QuAclnyCog_Cnt_T_u8 == Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer) ||
     		   (QuAclnyCog_Cnt_T_u8 == CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer))
     		{
     			AclnyCogValidValue_Cnt_T_u16 = AclnyCog_Cnt_T_u16;
     			LatAccelValid_Cnt_T_lgc = TRUE;
        	}
     		else
     		{
     			AclnyCogValidValue_Cnt_T_u16 = D_ACLNYCOGZERO_CNT_U16;
     		}

			/* Update output and previous value if no faults */
			(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_AF, &InvldDataChk_Cnt_T_u8);

			if((InvldDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8)
			{
			   if(CRCErrorAclnyMassCntr_Cnt_T_lgc == FALSE)
			   {
				   LateralAccel_MpSecSq_T_f32 = (float32)(((float32)AclnyCogValidValue_Cnt_T_u16 * D_ACLNYCOGFACTOR_ULS_F32) + D_ACLNYCOGOFFSET_ULS_F32);
			   }
			   else
			   {
				   LatAccelValid_Cnt_T_lgc = FALSE;
			   }
			}
        }

       (void)Rte_Write_SrlComVehLatAccelValid_Cnt_lgc(LatAccelValid_Cnt_T_lgc);
       (void)Rte_Write_SrlComVehLatAccel_MpSecSq_f32(LateralAccel_MpSecSq_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxConVeh
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <CON_VEH> of PortPrototype <SrlComCONVEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComCONVEH_CON_VEH(SG_CON_VEH *data)
 *   boolean Rte_IsUpdated_SrlComCONVEH_CON_VEH(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Read_SrlComCONVEH_CON_VEH(SG_CON_VEH *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVehCdnStatus_VehCdnStatus(New_Coding_64 data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxConVeh(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_TRGD_RxConVeh
 *********************************************************************************************************************/

	VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) CRCErrorConVeh_Cnt_T_lgc = FALSE;
	VAR(uint32, AUTOMATIC) E2EPWErrorCode_Cnt_T_u32 = 0U;

	VAR(New_Coding_61, AUTOMATIC) RxAliveCounter_Cnt_T_u08;
	VAR(SG_CON_VEH, AUTOMATIC) RxConVeh_T_Str;
	VAR(New_Coding_64, AUTOMATIC) StConVeh_T_u8;

	VAR(uint8, AUTOMATIC) InvldDataChk_Cnt_T_u8;
	VAR(uint8, AUTOMATIC) UndefDataChk_Cnt_T_u8;


	/* Receive Vehicle Condition (CON_VEH) message data */
		E2EPWErrorCode_Cnt_T_u32 = E2EPW_Read_SrlComCONVEH_CON_VEH(&RxConVeh_T_Str);

 		RxAliveCounter_Cnt_T_u08 = RxConVeh_T_Str.ALIV_CON_VEH;

 		CRCAliveCntErrorCode_Cnt_T_u08 = (uint8)(E2EPWErrorCode_Cnt_T_u32 >> D_MSBYTESHIFT_CNT_U08);
        CRCErrorConVeh_Cnt_T_lgc = CRCAliveCntDiag (CRCAliveCntErrorCode_Cnt_T_u08,
                                                          RxAliveCounter_Cnt_T_u08,
                                                          &ConVehAliveFault_Cnt_M_u08,
                                                          &ConVehAliveRecovery_Cnt_M_u8,
                                                          &ConVehCRCErrorCounter_Cnt_M_u08,
                                                          &ConVehCRCErrorRecovery_Cnt_M_u08,
                                                          NTC_Num_PgrsCntFltMsg_AD,
                                                          NTC_Num_CRCFltMsg_AD);

    StConVeh_T_u8 = RxConVeh_T_Str.ST_CON_VEH;
    /* Check the values are reserved */
    if((StConVeh_T_u8 == CxD_reserviert) || (StConVeh_T_u8 == CxE_reserviert))
    {
      /* Reset the counter if the previous received value was not reserved */
      if((ConVehPreValue_Cnt_M_u08 != CxD_reserviert) && (ConVehPreValue_Cnt_M_u08 != CxE_reserviert))
      {
        ConVehUndefCounter_Cnt_M_u08 = D_ZERO_CNT_U8;
      } 
      
      /* Decrement the In valid counter if previous received message was invalid */
      if(ConVehInVldCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
		  {
		 	  ConVehInVldCounter_Cnt_M_u08--;
		  }
      else
		  {
		 	 (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AD, 0x01U, NTC_STATUS_PASSED);
		  }
      /* Increment counter for error, keep previous value */
      if(ConVehUndefCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
      {
         ConVehUndefCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
         (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AD, 0x01U, NTC_STATUS_FAILED);
      }
      else
      {
         ConVehUndefCounter_Cnt_M_u08++;
      }
    }
    else if(StConVeh_T_u8 == CxF_Signal_unbefuellt)
    {
      /* Reset the counter if the previous received value was not reserved */
      if(ConVehPreValue_Cnt_M_u08 != CxF_Signal_unbefuellt)
      {
        ConVehInVldCounter_Cnt_M_u08 = D_ZERO_CNT_U8;
      } 
      /* Decrement the error count for the Undefined or Reserved messages */
		  if(ConVehUndefCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
		  {
		  	 ConVehUndefCounter_Cnt_M_u08--;
		  }
       else
		  {
		  	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AD, 0x01U, NTC_STATUS_PASSED);
		  }
    	/* Increment counter for error, keep previous value */
    	if(ConVehInVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
    	{
    		ConVehInVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
    	   (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AD, 0x01U, NTC_STATUS_FAILED);
    	}
    	else
    	{
    		ConVehInVldCounter_Cnt_M_u08++;
    	}
    }
    else
    {
		  /* Signal is valid, update counters and update output */
		  if(ConVehInVldCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
		  {
		  	ConVehInVldCounter_Cnt_M_u08--;
		  }
		  else
		  {
		  	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AD, 0x01U, NTC_STATUS_PASSED);
		  }
       
		  /* Signal is valid, update counters and update output */
		  if(ConVehUndefCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
		  {
		  	 ConVehUndefCounter_Cnt_M_u08--;
		  }
		  else
		  {
		  	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AD, 0x01U, NTC_STATUS_PASSED);
		  }
       
		  /* Update output and previous value if no faults */
		  (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_AD, &InvldDataChk_Cnt_T_u8);
		  (void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataOtherFltMsg_AD, &UndefDataChk_Cnt_T_u8);
       
		  if(((InvldDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
		     ((UndefDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8))
		  {
	      		if(CRCErrorConVeh_Cnt_T_lgc == FALSE)
	      		{
	      			if((StConVeh_T_u8 == Cx0_Keine_Kommunikation) ||
	      			   (StConVeh_T_u8 == Cx4_reserviert) ||
	      			   (StConVeh_T_u8 == Cx6_reserviert) ||
	      			   (StConVeh_T_u8 == Cx9_reserviert) ||
	      			   (StConVeh_T_u8 == CxB_reserviert) ||
	      			   (StConVeh_T_u8 == CxD_reserviert) ||
	      			   (StConVeh_T_u8 == CxE_reserviert))
	      			{
	      				/* retain the previous valid value */
	      			}
	      			else
	      			{
	      				ConVehValidValue_Cnt_M_u8 = StConVeh_T_u8;
	      			}
	      		}
		  }
    }
    /* Store Previous value for error checking for invalid & reserve values are received in three sucessive messages */
    ConVehPreValue_Cnt_M_u08 = StConVeh_T_u8; 
    
    (void)Rte_Write_SrlComVehCdnStatus_VehCdnStatus(ConVehValidValue_Cnt_M_u8);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxPaDrvDyn
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_TAR_STMOM_DV_ACT> of PortPrototype <SrlComSGTARSTMOMDVACT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(SG_TAR_QTA_STRMOM_DV *data)
 *   Std_ReturnType Rte_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(SG_TAR_STMOM_DV_ACT *data)
 *   Std_ReturnType Rte_Read_VehicleSpeed_Kph_f32(Float *data)
 *   boolean Rte_IsUpdated_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(void)
 *   boolean Rte_IsUpdated_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(SG_TAR_QTA_STRMOM_DV *data)
 *   uint32 E2EPW_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(SG_TAR_STMOM_DV_ACT *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CADASIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWANGLEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SerlComTarSteerTqDrvrActr_MtrNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComAssistScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComDampingScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComDrvDynEnable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComInputTorqueOverlay_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComReturnScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_TJADampSclRqst_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_TJAStateRqst_Cnt_enum(TJAStateType data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxPaDrvDyn(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_TRGD_RxPaDrvDyn
 *********************************************************************************************************************/
	
	VAR(FACT_ASS_STMOM_FTAX, AUTOMATIC) RxAstFactRqst_Cnt_T_u08;
	VAR(FACT_CTRR_STMOM_FTAX, AUTOMATIC) RxRtnFactRqst_Cnt_T_u08;
	VAR(FACT_CTRR_STMOM_FTAX, AUTOMATIC) RxDmpFactRqst_Cnt_T_u08;
	VAR(STMOM_QTA_DV, AUTOMATIC) RxIpTrqOvRqst_Cnt_T_u16;
	VAR(TAR_STMOM_DV_ACT, AUTOMATIC) RxOpTrqOvRqst_Cnt_T_u16;
	VAR(SG_TAR_STMOM_DV_ACT, AUTOMATIC) RxPrkAstHWAngle_T_Str;
	VAR(SG_TAR_QTA_STRMOM_DV, AUTOMATIC) RxDrvDyn_T_Str;
	
	VAR(ALIV_COU_4, AUTOMATIC) RxAliveCounter_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) E2EPWErrorCode_Cnt_T_u32 = 0U;
	VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) CRCErrorActiveDrvDyn_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) CRCErrorActivePrkAst_Cnt_T_lgc = FALSE;

	VAR(boolean, AUTOMATIC) DrvDynEnable_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) RxInvldSclFact_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) RxInvldIpTrqOv_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) RxInvldOpTrqOv_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) CFACTORIF_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CHWTORQUEIF_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CMTTORQUEIF_Cnt_T_lgc;
	
	VAR(uint16, AUTOMATIC) AstFactRqst_Cnt_T_u16;
	VAR(u8p8_T, AUTOMATIC) AstFactRqst_Uls_T_u8p8;
	VAR(float32, AUTOMATIC) AstFactRqst_Uls_T_f32;
	
	VAR(uint16, AUTOMATIC) RtnFactRqst_Cnt_T_u16;
	VAR(u8p8_T, AUTOMATIC) RtnFactRqst_Uls_T_u8p8;
	VAR(float32, AUTOMATIC) RtnFactRqst_Uls_T_f32;	
	
	VAR(uint16, AUTOMATIC) DmpFactRqst_Cnt_T_u16;
	VAR(u8p8_T, AUTOMATIC) DmpFactRqst_Uls_T_u8p8;
	VAR(float32, AUTOMATIC) DmpFactRqst_Uls_T_f32;
	
	VAR(sint32, AUTOMATIC) IpTrqOvRqst_Cnt_T_s32;
	VAR(s15p16_T, AUTOMATIC) IpTrqOvRqst_Nm_T_s15p16;
	VAR(float32, AUTOMATIC) IpTrqOvRqst_Nm_T_f32;
	
	VAR(sint32, AUTOMATIC) OpTrqOvRqst_Cnt_T_s32;
	VAR(s15p16_T, AUTOMATIC) OpTrqOvRqst_Nm_T_s15p16;
	VAR(float32, AUTOMATIC) OpTrqOvRqst_Nm_T_f32;

	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;
	
	VAR(uint8, AUTOMATIC) RxCustDmpFactRqst_Cnt_T_u08;
	VAR(float32, AUTOMATIC) CustDmpFactRqstRaw_Cnt_T_f32;
	VAR(float32, AUTOMATIC) CustDmpFactRqst_Uls_T_f32;
	VAR(boolean, AUTOMATIC) CADASIF_Cnt_T_lgc;

	VAR(boolean, AUTOMATIC) RxInvldTarQtaStMomQual_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) RxInvldTarFactStMomFtaxQual_Cnt_T_lgc = FALSE;

	VAR(boolean, AUTOMATIC) RxInvldTarStMomDvActQual_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) RxInvldTarDmpAddonStMomFtaxQual_Cnt_T_lgc = FALSE;

	VAR(uint8, AUTOMATIC) RxTarDmpAddonStMomFtaxQual_Cnt_T_u08;

	VAR(TJAStateType, AUTOMATIC) TJAStateRqst_Cnt_T_enum;

	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);
	
	if (D_SVCDFTRXMSGS_CNT_B32 != (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{	
		CFACTORIF_Cnt_T_lgc = Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc();
		CHWTORQUEIF_Cnt_T_lgc = Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc();
		CMTTORQUEIF_Cnt_T_lgc = Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc();

		/* Receive Driving Dynamics (TAR_QTA_STRMOM_DV) message data */
		E2EPWErrorCode_Cnt_T_u32 = E2EPW_Read_SrlComSGTARQTASTRMOMDV_SG_TAR_QTA_STRMOM_DV(&RxDrvDyn_T_Str);

 		RxAliveCounter_Cnt_T_u08 = RxDrvDyn_T_Str.ALIV_TAR_QTA_STMOM_DV;
 		CRCAliveCntErrorCode_Cnt_T_u08 = (uint8)(E2EPWErrorCode_Cnt_T_u32 >> D_MSBYTESHIFT_CNT_U08);
        CRCErrorActiveDrvDyn_Cnt_T_lgc = CRCAliveCntDiag (CRCAliveCntErrorCode_Cnt_T_u08,
                                                          RxAliveCounter_Cnt_T_u08,
                                                          &TarQtaStMomAliveFault_Cnt_M_u08,
                                                          &TarQtaStMomAliveRecovery_Cnt_M_u8,
                                                          &TarQtaStMomCRCErrorCounter_Cnt_M_u08,
                                                          &TarQtaStMomCRCErrorRecovery_Cnt_M_u08,
                                                          NTC_Num_PgrsCntFltMsg_R, 
                                                          NTC_Num_CRCFltMsg_R);

        RxAstFactRqst_Cnt_T_u08 = RxDrvDyn_T_Str.FACT_ASS_STMOM_FTAX;
		RxRtnFactRqst_Cnt_T_u08 = RxDrvDyn_T_Str.FACT_CTRR_STMOM_FTAX;
		RxDmpFactRqst_Cnt_T_u08 = RxDrvDyn_T_Str.FACT_DMPNG_STMOM_FTAX;
		if(FALSE == CFACTORIF_Cnt_T_lgc)
		{		
		    RxAstRtnDmpFactQual_Cnt_M_u08 = RxDrvDyn_T_Str.QU_TAR_FACT_STMOM_FTAX;
		}

		/* Copy the Handwheel Torque Interface data to the temp vars referenced throught the current design*/
		RxIpTrqOvRqst_Cnt_T_u16 = RxDrvDyn_T_Str.TAR_QTA_STMOM_DV;
		if(FALSE == CHWTORQUEIF_Cnt_T_lgc)
		{		
			RxTarQtaStMomQual_Cnt_M_u08 = RxDrvDyn_T_Str.QU_TAR_QTA_STMOM_DV;
		}
		
	 	/* Receive Park Assist (TAR_STMOM_DV_ACT) message data */ 
		E2EPWErrorCode_Cnt_T_u32 = E2EPW_Read_SrlComSGTARSTMOMDVACT_SG_TAR_STMOM_DV_ACT(&RxPrkAstHWAngle_T_Str);

	 	RxAliveCounter_Cnt_T_u08 = RxPrkAstHWAngle_T_Str.ALIV_TAR_STMOM_DV_ACT;
	 	CRCAliveCntErrorCode_Cnt_T_u08 = (uint8)(E2EPWErrorCode_Cnt_T_u32 >> D_MSBYTESHIFT_CNT_U08);
	 	CRCErrorActivePrkAst_Cnt_T_lgc = TrqOvDebounce(CRCAliveCntErrorCode_Cnt_T_u08, RxAliveCounter_Cnt_T_u08, &DrvDynEnable_Cnt_T_lgc);


		/* Copy the Motor Torque Interface data to the temp vars referenced through the current design*/
        RxOpTrqOvRqst_Cnt_T_u16 = RxPrkAstHWAngle_T_Str.TAR_STMOM_DV_ACT;

		if(FALSE == CMTTORQUEIF_Cnt_T_lgc)
		{			
			RxTarStMomQual_Cnt_M_u08 = RxPrkAstHWAngle_T_Str.QU_TAR_STMOM_DV_ACT;
		}

		/* Park Assist and Driving Dynamics Enable */
		if ( (RxAstRtnDmpFactQual_Cnt_M_u08 == Cx2_Sollwerte_umsetzen) ||
		     (RxTarQtaStMomQual_Cnt_M_u08 == Cx2_Sollwerte_umsetzen) ||
			 (RxTarStMomQual_Cnt_M_u08 == Cx2_Sollwerte_umsetzen) )
		{
			DrvDynEnable_Cnt_T_lgc = TRUE;
		}	

		/* Receive Customer Damping Command */
		RxCustDmpFactRqst_Cnt_T_u08 = RxPrkAstHWAngle_T_Str.FACT_DMPNG_ADDON_STMOM_FTAX;
		RxTarDmpAddonStMomFtaxQual_Cnt_T_u08 = RxPrkAstHWAngle_T_Str.QU_TAR_DMPNG_ADDON_STMOM_FTAX;


		CADASIF_Cnt_T_lgc = Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CADASIF_Cnt_lgc();
		if (CADASIF_Cnt_T_lgc == TRUE)
		{
			if( (RxPrkAstHWAngle_T_Str.FACT_DMPNG_ADDON_STMOM_FTAX != CxFF_Signal_unbefuellt) )
			{
				/* Signal is valid, pass on to customer damping */
				CustDmpFactRqstRaw_Cnt_T_f32 = FPM_FixedToFloat_m(RxCustDmpFactRqst_Cnt_T_u08, u16p0_T);
				CustDmpFactRqst_Uls_T_f32 = CustDmpFactRqstRaw_Cnt_T_f32 * D_TJASCALE_ULSPCNT_F32;
				TJADampSclRqst_Uls_M_f32 = Limit_m(CustDmpFactRqst_Uls_T_f32, D_TJALOLMT_ULS_F32, D_TJAHILMT_ULS_F32);
				TJAStateRqst_Cnt_T_enum = RxPrkAstHWAngle_T_Str.QU_TAR_DMPNG_ADDON_STMOM_FTAX;
			}
			else
			{
				/* Signal is invalid, set to defaults */
				TJADampSclRqst_Uls_M_f32 = D_ZERO_ULS_F32;
				TJAStateRqst_Cnt_T_enum = TJA_Error;
			}

			if(RxPrkAstHWAngle_T_Str.QU_TAR_DMPNG_ADDON_STMOM_FTAX > TJAStateType_UpperLimit)
			{
				TJAStateRqst_Cnt_T_enum = TJA_Error;
			}
		}
		else
		{
			/* TJA Not active, set to zero. This will cause the CustDmp state machine to be in the
			 * error state, which will keep the output held at zero. */
			TJADampSclRqst_Uls_M_f32 = D_ZERO_ULS_F32;
			TJAStateRqst_Cnt_T_enum = 0u;
		}

		(void)Rte_Write_TJADampSclRqst_Uls_f32(TJADampSclRqst_Uls_M_f32);
		(void)Rte_Write_TJAStateRqst_Cnt_enum(TJAStateRqst_Cnt_T_enum);

		/* Driving Dynamics mode (Qualifier signals) diagnostics */
		/* Qualifier Signal - QU_TAR_QTA_STMOM_DV */
		if((RxTarQtaStMomQual_Cnt_M_u08 != Cx2_Sollwerte_umsetzen) &&
		   (RxTarQtaStMomQual_Cnt_M_u08 != Cx7_Sollwerte_nicht_vorhanden) &&
		   (RxTarQtaStMomQual_Cnt_M_u08 != CxE_Sollwerte_nicht_umsetzen___Standby)
		  )
		{
			TarQtaStMomQualCounter_Cnt_M_u08++;
			if(TarQtaStMomQualCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				RxInvldTarQtaStMomQual_Cnt_T_lgc = TRUE;
				TarQtaStMomQualCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				TarQtaStMomQualErrRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}
		}
		else
		{
			TarQtaStMomQualCounter_Cnt_M_u08 = 0u;
			if(TarQtaStMomQualErrRecovery_Cnt_M_u08 > 0u)
			{
				TarQtaStMomQualErrRecovery_Cnt_M_u08--;
			}
			else
			{
				RxInvldTarQtaStMomQual_Cnt_T_lgc = FALSE;
			}
		}

		/* Qualifier Signal - QU_TAR_FACT_STMOM_FTAX */
		if((RxAstRtnDmpFactQual_Cnt_M_u08 != Cx2_Sollwerte_umsetzen) &&
		   (RxAstRtnDmpFactQual_Cnt_M_u08 != Cx7_Sollwerte_nicht_vorhanden) &&
		   (RxAstRtnDmpFactQual_Cnt_M_u08 != CxE_Sollwerte_nicht_umsetzen___Standby)
		  )
		{
			AstRtnDmpFactQualCounter_Cnt_M_u08++;
			if(AstRtnDmpFactQualCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				RxInvldTarFactStMomFtaxQual_Cnt_T_lgc = TRUE;
				AstRtnDmpFactQualCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				AstRtnDmpFactQualErrRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}
		}
		else
		{
			AstRtnDmpFactQualCounter_Cnt_M_u08 = 0u;
			if(AstRtnDmpFactQualErrRecovery_Cnt_M_u08 > 0u)
			{
				AstRtnDmpFactQualErrRecovery_Cnt_M_u08--;
			}
			else
			{
				RxInvldTarFactStMomFtaxQual_Cnt_T_lgc = FALSE;
			}
		}

		/* Qualifier Signal - QU_TAR_STMOM_DV_ACT */
		if((RxTarStMomQual_Cnt_M_u08 != Cx2_Sollwerte_umsetzen) &&
		   (RxTarStMomQual_Cnt_M_u08 != Cx7_Sollwerte_nicht_vorhanden) &&
		   (RxTarStMomQual_Cnt_M_u08 != CxE_Sollwerte_nicht_umsetzen___Standby)
		  )
		{
			TarStMomDvActQualCounter_Cnt_M_u08++;
			if(TarStMomDvActQualCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				RxInvldTarStMomDvActQual_Cnt_T_lgc = TRUE;
				TarStMomDvActQualCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				TarStMomDvActQualErrRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}
		}
		else
		{
			TarStMomDvActQualCounter_Cnt_M_u08 = 0u;
			if(TarStMomDvActQualErrRecovery_Cnt_M_u08 > 0u)
			{
				TarStMomDvActQualErrRecovery_Cnt_M_u08--;
			}
			else
			{
				RxInvldTarStMomDvActQual_Cnt_T_lgc = FALSE;
			}
		}

		/* Qualifier Signal - QU_TAR_DMPNG_ADDON_STMOM_FTAX */
		if((RxTarDmpAddonStMomFtaxQual_Cnt_T_u08 != 0u) &&
		   (RxTarDmpAddonStMomFtaxQual_Cnt_T_u08 != Cx1_Sollwert_Zusatzdaempfung_nicht_umsetzen) &&
		   (RxTarDmpAddonStMomFtaxQual_Cnt_T_u08 != Cx2_Sollwert_Zusatzdaempfung_nicht_umsetzen)
		  )
		{
			TarDmpAddonStMomFtaxQualCounter_Cnt_M_u08++;
			if(TarDmpAddonStMomFtaxQualCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				RxInvldTarDmpAddonStMomFtaxQual_Cnt_T_lgc = TRUE;
				TarDmpAddonStMomFtaxQualCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				TarDmpAddonStMomFtaxQualRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}
		}
		else
		{
			TarDmpAddonStMomFtaxQualCounter_Cnt_M_u08 = 0u;
			if(TarDmpAddonStMomFtaxQualRecovery_Cnt_M_u08 > 0u)
			{
				TarDmpAddonStMomFtaxQualRecovery_Cnt_M_u08--;
			}
			else
			{
				RxInvldTarDmpAddonStMomFtaxQual_Cnt_T_lgc = FALSE;
			}
		}


		/* Driving Dynamics Scale Factor Diagnostics */
		if ( (RxAstFactRqst_Cnt_T_u08 == Rte_InvalidValue_FACT_ASS_STMOM_FTAX) ||
			 (RxRtnFactRqst_Cnt_T_u08 == Rte_InvalidValue_FACT_CTRR_STMOM_FTAX) ||
			 (RxDmpFactRqst_Cnt_T_u08 == Rte_InvalidValue_FACT_CTRR_STMOM_FTAX) )
		{	 
			DrvDynRqstVldCounter_Cnt_M_u08++;
					
			if(DrvDynRqstVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				RxInvldSclFact_Cnt_T_lgc = TRUE;	
				DrvDynRqstVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				DrvDynRqstErrorRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}
		}
		else
		{
			DrvDynRqstVldCounter_Cnt_M_u08 = 0U;
			
			if (DrvDynRqstErrorRecovery_Cnt_M_u08 > 0U)
			{
				DrvDynRqstErrorRecovery_Cnt_M_u08--;
			}
			else
			{
				RxInvldSclFact_Cnt_T_lgc = FALSE;	
			}
			
			/* Reference SER 21781 */
			if(Cx2_Sollwerte_umsetzen != RxAstRtnDmpFactQual_Cnt_M_u08)
			{
				FinalAstFactRqst_Uls_M_f32 = 1.0f;
				FinalRtnFactRqst_Uls_M_f32 = 1.0f;
				FinalDmpFactRqst_Uls_M_f32 = 1.0f;
			}
			else if (CRCErrorActiveDrvDyn_Cnt_T_lgc == FALSE)
			{
				/* Only update output with valid message data */
				/* Driving Dynamics Assist Factor */
				AstFactRqst_Cnt_T_u16 = RxAstFactRqst_Cnt_T_u08 + D_ASTFACTOFFSET_CNT_U16;
				AstFactRqst_Uls_T_u8p8 = AstFactRqst_Cnt_T_u16 * D_RQSTFACTSCALE_ULSPCNT_u8p8;
				AstFactRqst_Uls_T_f32 = FPM_FixedToFloat_m (AstFactRqst_Uls_T_u8p8, u8p8_T); 
				FinalAstFactRqst_Uls_M_f32 = Limit_m(AstFactRqst_Uls_T_f32, D_ASTFACTLOLMT_ULS_F32, D_ASTFACTHILMT_ULS_F32);
				
				/* Driving Dynamics Return Factor */
				RtnFactRqst_Cnt_T_u16 = (uint16)RxRtnFactRqst_Cnt_T_u08 + D_RTNFACTOFFSET_CNT_U16;
			    RtnFactRqst_Uls_T_u8p8 = RtnFactRqst_Cnt_T_u16 * D_RQSTFACTSCALE_ULSPCNT_u8p8;
				RtnFactRqst_Uls_T_f32 = FPM_FixedToFloat_m (RtnFactRqst_Uls_T_u8p8, u8p8_T); 
				FinalRtnFactRqst_Uls_M_f32 = Limit_m(RtnFactRqst_Uls_T_f32, D_RTNFACTLOLMT_ULS_F32, D_RTNFACTHILMT_ULS_F32);
				
				/* Driving Dynamics Damping Factor */
				DmpFactRqst_Cnt_T_u16 = (uint16)RxDmpFactRqst_Cnt_T_u08 + D_DMPFACTOFFSET_CNT_U16;
				DmpFactRqst_Uls_T_u8p8 = DmpFactRqst_Cnt_T_u16 * D_RQSTFACTSCALE_ULSPCNT_u8p8;
				DmpFactRqst_Uls_T_f32 = FPM_FixedToFloat_m (DmpFactRqst_Uls_T_u8p8, u8p8_T); 
				FinalDmpFactRqst_Uls_M_f32 = Limit_m(DmpFactRqst_Uls_T_f32, D_DMPFACTLOLMT_ULS_F32, D_DMPFACTHILMT_ULS_F32);
			}
			else
			{
				/*Outputs retain last valid value.*/
			}
		}

		/* Input Torque Overlay Command */
		if (RxIpTrqOvRqst_Cnt_T_u16 == Rte_InvalidValue_STMOM_QTA_DV)
		{	 
			IpTrqOvRqstVldCounter_Cnt_M_u08++;
					
			if(IpTrqOvRqstVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				RxInvldIpTrqOv_Cnt_T_lgc = TRUE;	
				IpTrqOvRqstVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				IpTrqOvRqstErrorRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}
		}
		else
		{
			IpTrqOvRqstVldCounter_Cnt_M_u08 = 0U;
			
			if (IpTrqOvRqstErrorRecovery_Cnt_M_u08 > 0U)
			{
				IpTrqOvRqstErrorRecovery_Cnt_M_u08--;
			}
			else
			{
				RxInvldIpTrqOv_Cnt_T_lgc = FALSE;	
			}
			
		if(RxTarQtaStMomQual_Cnt_M_u08 != Cx2_Sollwerte_umsetzen)
		{
			FinalIpTrqOvRqst_HwNm_M_f32 = 0.0f;
		}
		else if (CRCErrorActiveDrvDyn_Cnt_T_lgc == FALSE)
		{	/* Only update output with valid message data */
			IpTrqOvRqst_Cnt_T_s32 = (sint32)RxIpTrqOvRqst_Cnt_T_u16;
			IpTrqOvRqst_Cnt_T_s32 = IpTrqOvRqst_Cnt_T_s32 - (sint32)D_IPTRQOVOFFSET_CNT_U16;
			IpTrqOvRqst_Nm_T_s15p16 = IpTrqOvRqst_Cnt_T_s32 * (s15p16_T)D_IPTRQOVSCALE_NMPCNT_u0p16;
			IpTrqOvRqst_Nm_T_f32 = FPM_FixedToFloat_m (IpTrqOvRqst_Nm_T_s15p16, s15p16_T);
			IpTrqOvRqst_Nm_T_f32 = IpTrqOvRqst_Nm_T_f32 * (float32)k_SComTrqPosPol_Cnt_s08;
			FinalIpTrqOvRqst_HwNm_M_f32 = Limit_m(IpTrqOvRqst_Nm_T_f32, D_IPTRQOVLOLMT_ULS_F32, D_IPTRQOVHILMT_ULS_F32);
		}
		else
		{
				/* Outputs retain last valid values. */
		}
		}

		/* Output Torque Overlay Command */
		if (RxOpTrqOvRqst_Cnt_T_u16 == Rte_InvalidValue_TAR_STMOM_DV_ACT) 
		{	 
			OpTrqOvRqstVldCounter_Cnt_M_u08++;
					
			if(OpTrqOvRqstVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				RxInvldOpTrqOv_Cnt_T_lgc = TRUE;	
				OpTrqOvRqstVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				OpTrqOvRqstErrorRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}
		}
		else
		{
			OpTrqOvRqstVldCounter_Cnt_M_u08 = 0U;
			
			if (OpTrqOvRqstErrorRecovery_Cnt_M_u08 > 0U)
			{
				OpTrqOvRqstErrorRecovery_Cnt_M_u08--;
			}
			else
			{
				RxInvldOpTrqOv_Cnt_T_lgc = FALSE;	
			}
			
			/* Reference SER 21781 */
			if(Cx2_Sollwerte_umsetzen != RxTarStMomQual_Cnt_M_u08)
			{
				FinalOpTrqOvRqst_MtrNm_M_f32 = 0.0f;
			}
			else if (CRCErrorActivePrkAst_Cnt_T_lgc == FALSE)
			{

				/* Only update output with valid message data */
				OpTrqOvRqst_Cnt_T_s32 = (sint32)RxOpTrqOvRqst_Cnt_T_u16;
				OpTrqOvRqst_Cnt_T_s32 = OpTrqOvRqst_Cnt_T_s32 - (sint32)D_OPTRQOVOFFSET_CNT_U16;
				OpTrqOvRqst_Nm_T_s15p16 = OpTrqOvRqst_Cnt_T_s32 * (s15p16_T)D_OPTRQOVSCALE_NMPCNT_u0p16;
				OpTrqOvRqst_Nm_T_f32 = FPM_FixedToFloat_m (OpTrqOvRqst_Nm_T_s15p16, s15p16_T);
				OpTrqOvRqst_Nm_T_f32 = OpTrqOvRqst_Nm_T_f32 * (float32)k_SComTrqPosPol_Cnt_s08;

				FinalOpTrqOvRqst_MtrNm_M_f32 = OpTrqOvRqst_Nm_T_f32;
			}
			else
			{
				/* Do nothing */
			}

		}

		/* Invalid Driving Dynamics signal received */
		if ((RxInvldSclFact_Cnt_T_lgc | RxInvldIpTrqOv_Cnt_T_lgc | RxInvldOpTrqOv_Cnt_T_lgc |
			 RxInvldTarQtaStMomQual_Cnt_T_lgc | RxInvldTarFactStMomFtaxQual_Cnt_T_lgc |
			 RxInvldTarStMomDvActQual_Cnt_T_lgc | RxInvldTarDmpAddonStMomFtaxQual_Cnt_T_lgc) == TRUE)
		{
			InvldDrvDynSgnl_Cnt_M_lgc = TRUE;
		}
		else
		{
			InvldDrvDynSgnl_Cnt_M_lgc = FALSE;
		}

		/* Update Outputs */
		(void)Rte_Write_SrlComDrvDynEnable_Cnt_lgc(DrvDynEnable_Cnt_T_lgc);


		if(FALSE == CFACTORIF_Cnt_T_lgc)
		{
			(void)Rte_Write_SrlComAssistScaleFactor_Uls_f32(FinalAstFactRqst_Uls_M_f32);
			(void)Rte_Write_SrlComReturnScaleFactor_Uls_f32(FinalRtnFactRqst_Uls_M_f32);
			(void)Rte_Write_SrlComDampingScaleFactor_Uls_f32(FinalDmpFactRqst_Uls_M_f32);
		}

		if(FALSE == CHWTORQUEIF_Cnt_T_lgc)
		{
			(void)Rte_Write_SrlComInputTorqueOverlay_HwNm_f32(FinalIpTrqOvRqst_HwNm_M_f32);
		}

		if(FALSE == CMTTORQUEIF_Cnt_T_lgc)
		{
			(void)Rte_Write_SerlComTarSteerTqDrvrActr_MtrNm_f32(FinalOpTrqOvRqst_MtrNm_M_f32);
		}

   }
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxRevOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_OFFS_QUAD_EPS> of PortPrototype <SrlComSGOFFSQUADEPS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(SG_OFFS_QUAD_EPS *data)
 *   boolean Rte_IsUpdated_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Read_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(SG_OFFS_QUAD_EPS *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_SrlComInput2_TRGD_RxRevOffset_SrlComSvcDft_Cnt_b32(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComCRFRevOffset_Rev_s16(SInt16 data)
 *   Std_ReturnType Rte_Write_SrlComRevOffsetSts_Cnt_u08(ST_OFFS_QUAD_EPS data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxRevOffset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_TRGD_RxRevOffset
 *********************************************************************************************************************/

	VAR(SG_OFFS_QUAD_EPS, AUTOMATIC) RxRevOffsetMsgData_T_Str;
	VAR(OFFS_QUAD_PINA_EPS, AUTOMATIC) RxRevOffset_Cnt_T_u08;
	VAR(ALIV_COU_4, AUTOMATIC) RxAliveCounter_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) E2EPWErrorCode_Cnt_T_u32 = 0U;
	VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) CRCErrorActive_Cnt_T_lgc = FALSE;
	VAR(uint16, AUTOMATIC) RevOffset_Cnt_T_u16;
	VAR(sint16, AUTOMATIC) RevOffset_Cnt_T_s16;
	VAR(ST_OFFS_QUAD_EPS, AUTOMATIC) RevOffsetStatus_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;

	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);
	
	if (D_SVCDFTRXMSGS_CNT_B32 != (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		/* Read ICMRevOffset data */
        E2EPWErrorCode_Cnt_T_u32 = E2EPW_Read_SrlComSGOFFSQUADEPS_SG_OFFS_QUAD_EPS(&RxRevOffsetMsgData_T_Str);
		
		RxRevOffset_Cnt_T_u08 = RxRevOffsetMsgData_T_Str.OFFS_QUAD_RTR_EPS;
		RevOffsetStatus_Cnt_T_u08 = RxRevOffsetMsgData_T_Str.ST_OFFS_QUAD_EPS;
	    RxAliveCounter_Cnt_T_u08 = RxRevOffsetMsgData_T_Str.ALIV_OFFS_QUAD_EPS;
	    	    
		CRCAliveCntErrorCode_Cnt_T_u08 = (uint8)(E2EPWErrorCode_Cnt_T_u32 >> D_MSBYTESHIFT_CNT_U08);
        CRCErrorActive_Cnt_T_lgc = CRCAliveCntDiag (CRCAliveCntErrorCode_Cnt_T_u08,
                                                    RxAliveCounter_Cnt_T_u08,
                                                    &RevOffsetAliveFault_Cnt_M_u08,
                                                    &RevOffsetAliveRecovery_Cnt_M_u08,
                                                    &RevOffsetCRCErrorCounter_Cnt_M_u08,
                                                    &RevOffsetCRCErrorRecovery_Cnt_M_u08, 
													NTC_Num_PgrsCntFltMsg_Q,
													NTC_Num_CRCFltMsg_Q);
													
		if( (RxRevOffset_Cnt_T_u08 == D_INVALIDREVOFFSET_CNT_U08) ||
		    (RevOffsetStatus_Cnt_T_u08 == Rte_InvalidValue_DT_ST_OFFS_QUAD_EPS) ) 
		{
			RevOffsetVldCounter_Cnt_M_u08++;
			RevOffsetStatusErrCounter_Cnt_M_u08 = 0U;
			
			if(RevOffsetVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0x01U, NTC_STATUS_FAILED);
				RevOffsetVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				RevOffsetErrorRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}
		}
		/* Check for entries that are not defined in SER for error dignostic, the following were not
		 * defined in version 10A of the BMW SER */
		else if( (RevOffsetStatus_Cnt_T_u08 == 0x0AU) ||
				 (RevOffsetStatus_Cnt_T_u08 == 0x0CU) ||
				 (RevOffsetStatus_Cnt_T_u08 == 0x0DU) ||
				 (RevOffsetStatus_Cnt_T_u08 == 0x0EU) )
		{
			RevOffsetStatusErrCounter_Cnt_M_u08++;
			RevOffsetVldCounter_Cnt_M_u08 = 0U;

			if(RevOffsetStatusErrCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0x01U, NTC_STATUS_FAILED);
				RevOffsetStatusErrCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				RevOffsetErrorRecovery_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			}

		}
		else
		{
			RevOffsetStatusErrCounter_Cnt_M_u08 = 0U;
			RevOffsetVldCounter_Cnt_M_u08 = 0U;
			
			if (RevOffsetErrorRecovery_Cnt_M_u08 > 0U)
			{
				RevOffsetErrorRecovery_Cnt_M_u08--;
			}
			else
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0x01U, NTC_STATUS_PASSED);
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0x01U, NTC_STATUS_PASSED);
			}

		}
		/* Allow all states and RevOffset values to pass through.*/
		/* Send invalid flags if a CRC error is active. */
		if (FALSE == CRCErrorActive_Cnt_T_lgc)
		{
			/* Only update output with valid message data */
			RevOffset_Cnt_T_u16 = (uint16)RxRevOffset_Cnt_T_u08;
			RevOffset_Cnt_T_s16 = ((sint16)RevOffset_Cnt_T_u16) - ((sint16)D_REVOFFSETMSGOFFSET_CNTS_U08);
			RevOffset_Cnt_T_s16 = RevOffset_Cnt_T_s16 * k_SComRevOffsetPol_Cnt_s08;
			RevOffset_Cnt_M_s16 = Limit_m(RevOffset_Cnt_T_s16, ((sint16)D_REVOFFSETLOLMT_CNTS_S08), ((sint16)D_REVOFFSETHILMT_CNTS_S08));
                
            RevOffsetStatus_Cnt_M_u08 = RevOffsetStatus_Cnt_T_u08;
		}
		else
		{	
			RxRevOffset_Cnt_T_u08 = D_INVALIDREVOFFSET_CNT_U08;
		    RevOffsetStatus_Cnt_T_u08 = Rte_InvalidValue_DT_ST_OFFS_QUAD_EPS;
		}
		(void)Rte_Write_SrlComCRFRevOffset_Rev_s16(RevOffset_Cnt_M_s16);
 		(void)Rte_Write_SrlComRevOffsetSts_Cnt_u08(RevOffsetStatus_Cnt_M_u08);
 	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxStCeng
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ST_CENG> of PortPrototype <SrlComSTCENG>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSTCENG_ST_CENG(SG_ST_CENG *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComEngDrvStatus_ST_CENG(const SG_ST_CENG *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxStCeng(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_TRGD_RxStCeng
 *********************************************************************************************************************/
	 VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode_Cnt_T_u08;
	 VAR(boolean, AUTOMATIC) CRCErrorStCengCntr_Cnt_T_lgc = FALSE;
	 VAR(uint32, AUTOMATIC) E2EPWErrorCode_Cnt_T_u32 = 0U;

	 VAR(uint8, AUTOMATIC) InvldDataChk_Cnt_T_u8;
	 VAR(uint8, AUTOMATIC) UndefDataChk_Cnt_T_u8;

	 VAR(SG_ST_CENG, AUTOMATIC) RxStCeng_T_Str;
	 VAR(New_Coding_102, AUTOMATIC) RxAliveCounter_Cnt_T_u08;
	 VAR(New_Coding_104, AUTOMATIC) RxStCengDrv_Cnt_T_u08;
	 VAR(New_Coding_103, AUTOMATIC) RxStUdp_Cnt_T_u08;
	 VAR(New_Coding_105, AUTOMATIC) RxStEnergSupy_Cnt_T_u08;
	 VAR(New_Coding_108, AUTOMATIC) RxStMotDrv_Cnt_T_u08;
	 VAR(New_Coding_107, AUTOMATIC) RxStMsaEngStop_Cnt_T_u08;

	 /* Receive Engine Status message data */
	E2EPWErrorCode_Cnt_T_u32 = E2EPW_Read_SrlComSTCENG_ST_CENG(&RxStCeng_T_Str);

	RxAliveCounter_Cnt_T_u08 = RxStCeng_T_Str.ALIV_ST_CENG;

	CRCAliveCntErrorCode_Cnt_T_u08 = (uint8)(E2EPWErrorCode_Cnt_T_u32 >> D_MSBYTESHIFT_CNT_U08);
      CRCErrorStCengCntr_Cnt_T_lgc = CRCAliveCntDiag (CRCAliveCntErrorCode_Cnt_T_u08,
                                                       RxAliveCounter_Cnt_T_u08,
                                                       &StCengCntrAliveFault_Cnt_M_u08,
                                                       &StCengCntrAliveRecovery_Cnt_M_u8,
                                                       &StCengCntrCRCErrorCounter_Cnt_M_u08,
                                                       &StCengCntrCRCErrorRecovery_Cnt_M_u08,
                                                       NTC_Num_PgrsCntFltMsg_AC,
                                                       NTC_Num_CRCFltMsg_AC);

  RxStCengDrv_Cnt_T_u08 = RxStCeng_T_Str.ST_CENG_DRV;
  RxStUdp_Cnt_T_u08 	= RxStCeng_T_Str.ST_UDP;
  RxStEnergSupy_Cnt_T_u08 = RxStCeng_T_Str.ST_ENERG_SUPY;
  RxStMotDrv_Cnt_T_u08 = RxStCeng_T_Str.ST_MOT_DRV;
  RxStMsaEngStop_Cnt_T_u08 = RxStCeng_T_Str.ST_ANO_MSA_ENG_STOP;

  if(RxStCengDrv_Cnt_T_u08 == CxF_Signal_unbefuellt)
  {
    /* Check the Prev received message was invalid or not */
    if(RxStCengDrvPrev_Cnt_M_u08 != CxF_Signal_unbefuellt)
    {
      StCengDrvInVldCounter_Cnt_M_u08 = D_ZERO_CNT_U8;
    }
    /* Decrement the undefined counter if previous received message was invalid */
    if(StCengDrvUndefCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
		{
		  StCengDrvUndefCounter_Cnt_M_u08--;
		}
    else
		{
		 (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AC, 0x01U, NTC_STATUS_PASSED);
		}
    RxStCengDrv_Cnt_M_u08 = k_StCengDrvMax_Cnt_u8;
    if(StCengDrvInVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
    {
    	StCengDrvInVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
    	STCENGDRVInvalid_Cnt_M_lgc = TRUE;
    	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AC, 0x01U, NTC_STATUS_FAILED);
    }
    else
    {
    	StCengDrvInVldCounter_Cnt_M_u08++;
    }
  }
  else if((RxStCengDrv_Cnt_T_u08 == CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) ||
     (RxStCengDrv_Cnt_T_u08 == CxE_Reserviert))
  {
    
    if((RxStCengDrvPrev_Cnt_M_u08 != CxD_Funktionsschnittstelle_ist_nicht_verfuegbar) &&
      (RxStCengDrvPrev_Cnt_M_u08 != CxE_Reserviert))
    {
      StCengDrvUndefCounter_Cnt_M_u08 = D_ZERO_CNT_U8;   
    }  
    /* Decrement the invalid counter if previous received message was invalid */
    if(StCengDrvInVldCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
		{
		  StCengDrvInVldCounter_Cnt_M_u08--;
		}
    else
		{
		 (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AC, 0x01U, NTC_STATUS_PASSED);
		}
    
    RxStCengDrv_Cnt_M_u08 = k_StCengDrvMax_Cnt_u8;
    if(StCengDrvUndefCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
    {
     StCengDrvUndefCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
     STCENGDRVInvalid_Cnt_M_lgc = TRUE;
    	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AC, 0x01U, NTC_STATUS_FAILED);
    }
    else
    {
     StCengDrvUndefCounter_Cnt_M_u08++;
    }
  }
  else
  {
		/* Signal is valid, update counters and update output */
		if(StCengDrvInVldCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
		{
			RxStCengDrv_Cnt_M_u08 = k_StCengDrvMax_Cnt_u8;
			StCengDrvInVldCounter_Cnt_M_u08--;
		}
		else
		{
			STCENGDRVInvalid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AC, 0x01U, NTC_STATUS_PASSED);
		}

		if(StCengDrvUndefCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
		{
			RxStCengDrv_Cnt_M_u08 = k_StCengDrvMax_Cnt_u8;
			StCengDrvUndefCounter_Cnt_M_u08--;
		}
		else
		{
			STCENGDRVInvalid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AC, 0x01U, NTC_STATUS_PASSED);
		}

		/* Update output and previous value if no faults */
		(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_AC, &InvldDataChk_Cnt_T_u8);
		(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_DataOtherFltMsg_AC, &UndefDataChk_Cnt_T_u8);

		if(CRCErrorStCengCntr_Cnt_T_lgc == FALSE)
		{
			if(((InvldDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8) &&
			   ((UndefDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8))
			{
				RxStCengDrv_Cnt_M_u08 = RxStCengDrv_Cnt_T_u08;
			}

			if(RxStUdp_Cnt_T_u08 == Cx1_Startspannungseinbruch_bis_maximal_Spannungsschwelle_1)
			{
			/* will be implemented in the next build */
			}

			RxStCeng_M_Str.ST_CENG_DRV = RxStCengDrv_Cnt_M_u08;
		  RxStCeng_M_Str.ST_UDP = RxStUdp_Cnt_T_u08;
		  RxStCeng_M_Str.ST_ENERG_SUPY = RxStEnergSupy_Cnt_T_u08;
		  RxStCeng_M_Str.ST_MOT_DRV = RxStMotDrv_Cnt_T_u08;
		  RxStCeng_M_Str.ST_ANO_MSA_ENG_STOP = RxStMsaEngStop_Cnt_T_u08;
		}

	  (void)Rte_Write_SrlComEngDrvStatus_ST_CENG(&RxStCeng_M_Str);
  }
  
  /* Store the Previous Value to check for three successive messages for fault handling */
  RxStCengDrvPrev_Cnt_M_u08 = RxStCengDrv_Cnt_T_u08;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxVYawVeh
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VYAW_VEH> of PortPrototype <SrlComVYAWVEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComVYAWVEH_VYAW_VEH(SG_VYAW_VEH *data)
 *   boolean Rte_IsUpdated_SrlComVYAWVEH_VYAW_VEH(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Read_SrlComVYAWVEH_VYAW_VEH(SG_VYAW_VEH *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComVehYawRate_DegpS_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehYawRateValid_Cnt_lgc(Boolean data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxVYawVeh(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_TRGD_RxVYawVeh
 *********************************************************************************************************************/
   VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode_Cnt_T_u08;
  	VAR(boolean, AUTOMATIC) CRCErrorVYawVehCntr_Cnt_T_lgc = FALSE;
  	VAR(uint32, AUTOMATIC) E2EPWErrorCode_Cnt_T_u32 = 0U;

  	VAR(SG_VYAW_VEH, AUTOMATIC) RxVYawVehCntr_T_Str;
  	VAR(New_Coding_30, AUTOMATIC) RxAliveCounter_Cnt_T_u08;
  	VAR(New_Coding_31, AUTOMATIC) VYawVeh_Cnt_T_u16;
  	VAR(New_Coding_33, AUTOMATIC) QuVYawVeh_Cnt_T_u8;

  	VAR(uint8, AUTOMATIC) InvldDataChk_Cnt_T_u8;
  	VAR(float32, AUTOMATIC) VYawVeh_T_f32 = 0.0f;
  	VAR(uint16, AUTOMATIC) VYawVehValidValue_Cnt_T_u16;

  	VAR(boolean, AUTOMATIC) VehYawRateValid_Cnt_T_lgc = FALSE;

  	/* Receive Lateral Acceleration (ACLNY_MASSCNTR) message data */
  		E2EPWErrorCode_Cnt_T_u32 = E2EPW_Read_SrlComVYAWVEH_VYAW_VEH(&RxVYawVehCntr_T_Str);

   		RxAliveCounter_Cnt_T_u08 = RxVYawVehCntr_T_Str.ALIV_VYAW_VEH;

   		CRCAliveCntErrorCode_Cnt_T_u08 = (uint8)(E2EPWErrorCode_Cnt_T_u32 >> D_MSBYTESHIFT_CNT_U08);
          CRCErrorVYawVehCntr_Cnt_T_lgc = CRCAliveCntDiag (CRCAliveCntErrorCode_Cnt_T_u08,
                                                           RxAliveCounter_Cnt_T_u08,
                                                           &VYawVehCntrAliveFault_Cnt_M_u08,
                                                           &VYawVehCntrAliveRecovery_Cnt_M_u8,
                                                           &VYawVehCntrCRCErrorCounter_Cnt_M_u08,
                                                           &VYawVehCntrCRCErrorRecovery_Cnt_M_u08,
                                                           NTC_Num_PgrsCntFltMsg_AA,
                                                           NTC_Num_CRCFltMsg_AA);

          VYawVeh_Cnt_T_u16 = RxVYawVehCntr_T_Str.VYAW_VEH;
          QuVYawVeh_Cnt_T_u8 = RxVYawVehCntr_T_Str.QU_VYAW_VEH;

          if((VYawVeh_Cnt_T_u16 == D_VYAWVEHINVALID_CNT_U08) || (QuVYawVeh_Cnt_T_u8 == D_QUVYAWVEHINVALID_CNT_U08))
          {
          	/* Increment counter for error, keep previous value */
          	if(VYawVehVldCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
          	{
          		VYawVehVldCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
          	   (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0x01U, NTC_STATUS_FAILED);
          	}
          	else
          	{
          		VYawVehVldCounter_Cnt_M_u08++;
          	}
          }
          else
          {
  			/* Signal is valid, update counters and update output */
  			if(VYawVehVldCounter_Cnt_M_u08 > D_ZERO_CNT_U8)
  			{
  				VYawVehVldCounter_Cnt_M_u08--;
  			}
  			else
  			{
  				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0x01U, NTC_STATUS_PASSED);
  			}

       		if((QuVYawVeh_Cnt_T_u8 == Cx1_Signalwert_ist_gueltig_und_abgesichert_und_plausibilisiert__) ||
       		   (QuVYawVeh_Cnt_T_u8 == Cx2_Signalwert_ist_gueltig__) ||
       		   (QuVYawVeh_Cnt_T_u8 == Cx9_Signalwert_ist_gueltig_und_abgesichert__Zustand_Status_temporaer) ||
       		   (QuVYawVeh_Cnt_T_u8 == CxA_Signalwert_ist_gueltig__Zustand_Status_temporaer))
       		{
       			VYawVehValidValue_Cnt_T_u16 = VYawVeh_Cnt_T_u16;
       			VehYawRateValid_Cnt_T_lgc = TRUE;
          	}
       		else
       		{
       			VYawVehValidValue_Cnt_T_u16 = D_VYAWVEHZERO_CNT_U16;
       		}

  			/* Update output and previous value if no faults */
  			(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_AA, &InvldDataChk_Cnt_T_u8);

  			if((InvldDataChk_Cnt_T_u8 & D_NTCFAILED_CNT_U08) == D_ZERO_CNT_U8)
  			{
  				if(CRCErrorVYawVehCntr_Cnt_T_lgc == FALSE)
  				{
  					VYawVeh_T_f32 = (float32)(((float32)VYawVehValidValue_Cnt_T_u16 * D_VYAWVEHFACTOR_ULS_F32) + D_VYAWVEHOFFSET_ULS_F32);
  				}
  				else
  				{
  					VehYawRateValid_Cnt_T_lgc = FALSE;
  				}
  			}

          }

          (void)Rte_Write_SrlComVehYawRateValid_Cnt_lgc(VehYawRateValid_Cnt_T_lgc);
          (void)Rte_Write_SrlComVehYawRate_DegpS_f32(VYawVeh_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_RxVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SG_V_VEH> of PortPrototype <SrlComSGVVEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComSGVVEH_SG_V_VEH(SG_V_VEH *data)
 *   Std_ReturnType Rte_Read_SrlComSvcDft_Cnt_b32(UInt32 *data)
 *   boolean Rte_IsUpdated_SrlComSGVVEH_SG_V_VEH(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Read_SrlComSGVVEH_SG_V_VEH(SG_V_VEH *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput2_TRGD_RxVehSpd_DiagStsDefVehSpd_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FRVldVehSpd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehDrvCondition_Cnt_u08(DVCO_VEH data)
 *   Std_ReturnType Rte_Write_SrlComVehNearStandstill_Cnt_u08(ST_V_VEH_NSS data)
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlCom_QU_V_VEH_COG_Cnt_u08(QU_V_VEH_COG data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
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

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_RxVehSpd(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_TRGD_RxVehSpd
 *********************************************************************************************************************/
	VAR(SG_V_VEH, AUTOMATIC) RxVVehData_Cnt_T_str;
	VAR(uint16, AUTOMATIC) RxVehSpd_Cnt_T_u16;
	VAR(u10p6_T, AUTOMATIC) VehSpd_Kph_T_u10p6;
	VAR(ST_V_VEH_NSS, AUTOMATIC) RxVehNss_Cnt_T_u08;
	VAR(DVCO_VEH, AUTOMATIC) RxVehDrvCond_Cnt_T_u08;
	VAR(QU_V_VEH_COG, AUTOMATIC) RxVehSpdQF_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) SrlComSvcDft_Cnt_T_b32;
	
	VAR(ALIV_COU_4, AUTOMATIC) RxAliveCounter_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) E2EPWErrorCode_Cnt_T_u32 = 0U;
	VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) CRCErrorActive_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) DiagStsDefVehSpd_Cnt_T_lgc;
	
	(void)Rte_Read_SrlComSvcDft_Cnt_b32 (&SrlComSvcDft_Cnt_T_b32);
    DiagStsDefVehSpd_Cnt_T_lgc = Rte_IRead_SrlComInput2_Per1_DiagStsDefVehSpd_Cnt_lgc();
	
	if (D_SVCDFTRXMSGS_CNT_B32 != (SrlComSvcDft_Cnt_T_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		E2EPWErrorCode_Cnt_T_u32 = E2EPW_Read_SrlComSGVVEH_SG_V_VEH(&RxVVehData_Cnt_T_str);

 		RxAliveCounter_Cnt_T_u08 = RxVVehData_Cnt_T_str.ALIV_V_VEH;
 		CRCAliveCntErrorCode_Cnt_T_u08 = (uint8)(E2EPWErrorCode_Cnt_T_u32 >> D_MSBYTESHIFT_CNT_U08);
  			
 		CRCErrorActive_Cnt_T_lgc = CRCAliveCntDiag (CRCAliveCntErrorCode_Cnt_T_u08,
                                                    RxAliveCounter_Cnt_T_u08,
                                                    &VehSpdAliveFault_Cnt_M_u08,
                                                    &VehSpdAliveRecovery_Cnt_M_u08,
                                                    &VehSpdCRCErrorCounter_Cnt_M_u08,
                                                    &VehSpdCRCErrorRecovery_Cnt_M_u08,
                                                    NTC_Num_PgrsCntFltMsg_O, 
                                                    NTC_Num_CRCFltMsg_O); 
    
 		RxVehSpd_Cnt_T_u16 = RxVVehData_Cnt_T_str.V_VEH_COG;
		RxVehNss_Cnt_T_u08 = RxVVehData_Cnt_T_str.ST_V_VEH_NSS;
	    RxVehDrvCond_Cnt_T_u08 = RxVVehData_Cnt_T_str.DVCO_VEH;
		RxVehSpdQF_Cnt_T_u08 = RxVVehData_Cnt_T_str.QU_V_VEH_COG;

		(void) Rte_Write_SrlCom_QU_V_VEH_COG_Cnt_u08(RxVehSpdQF_Cnt_T_u08);
		
		VehSpdQFDiag(RxVehSpdQF_Cnt_T_u08);
				
		if( (RxVehSpd_Cnt_T_u16 == Rte_InvalidValue_DT_V_VEH_COG) ||
		    (RxVehSpdQF_Cnt_T_u08 == D_QUALINVALID_CNT_U08) ||
			(RxVehSpdQF_Cnt_T_u08 == D_QUALINVALSTATETEMP_CNT_U08) ||
			(RxVehSpdQF_Cnt_T_u08 == D_QUALLIMMONTTEMPID_CNT_U08) ||
		    (RxVehDrvCond_Cnt_T_u08 == Rte_InvalidValue_DVCO_VEH) ) 
		{
			VehSpdVldCounter_Cnt_M_u08++;
			VehSpdErrorCounter_Cnt_M_u08 = 0U;
			
			if(VehSpdVldCounter_Cnt_M_u08 >= D_VEHSPDINVALID_CNT_U16)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0x01U, NTC_STATUS_FAILED);
				VehSpdVldCounter_Cnt_M_u08 = D_VEHSPDINVALID_CNT_U16;
				VehSpdErrorRecovery_Cnt_M_u16 = D_RXMSGINVALID_CNT_U08;
				VehNss_Cnt_M_u08 = CxF_Signal_ungueltig;
			}
		}
		else if ( (RxVehSpd_Cnt_T_u16 > D_MAXVEHSPD_CNT_U16) ||
		          (RxVehDrvCond_Cnt_T_u08 > D_MAXVEHDRVCOND_CNT_U08) ) 
		{
			VehSpdErrorCounter_Cnt_M_u08++;
			VehSpdVldCounter_Cnt_M_u08 = 0U;
			
			if(VehSpdErrorCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_P, 0x01U, NTC_STATUS_FAILED);
				VehSpdErrorCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
				VehSpdErrorRecovery_Cnt_M_u16 = D_RXMSGINVALID_CNT_U08;
				VehNss_Cnt_M_u08 = CxF_Signal_ungueltig;
			}
		}
		else
		{
			VehSpdErrorCounter_Cnt_M_u08 = 0U;
			VehSpdVldCounter_Cnt_M_u08 = 0U;
			
			if (VehSpdErrorRecovery_Cnt_M_u16 > 0U)
			{
				VehSpdErrorRecovery_Cnt_M_u16--;
			}
			else
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_P, 0x01U, NTC_STATUS_PASSED);
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0x01U, NTC_STATUS_PASSED);
			}
			
			if (CRCErrorActive_Cnt_T_lgc == FALSE)
			{
				/* Only update output with valid message data */
				VehSpd_Kph_T_u10p6 = RxVehSpd_Cnt_T_u16 * D_VEHSPDSCALE_KPHPCNT_U10P6;
				VehSpd_Kph_T_u10p6 = Limit_m(VehSpd_Kph_T_u10p6, D_VEHSPDLOLMT_KPH_U10P6, D_VEHSPDHILMT_KPH_U10P6);
				VehSpd_Kph_M_f32 = FPM_FixedToFloat_m(VehSpd_Kph_T_u10p6, u10p6_T);
				
				VehDrvCond_Cnt_M_u08 = RxVehDrvCond_Cnt_T_u08;
				VehNss_Cnt_M_u08 = RxVehNss_Cnt_T_u08;
			}
			else
			{
				VehNss_Cnt_M_u08 = CxF_Signal_ungueltig;
			}
		}

		/* VEHICLE SPEED OUTPUT DETERMINATION */
		if ( (RxVehSpdQF_Cnt_T_u08 != D_QUVALIDGUARANTEED_CNT_U08) &&
			 (RxVehSpdQF_Cnt_T_u08 != D_QUVALIDTEMP_CNT_U08) )
		{
			InvalidVehSpdQual_Cnt_M_lgc = TRUE;
		}
		else
		{
			InvalidVehSpdQual_Cnt_M_lgc = FALSE;
		}

		if ( (DiagStsDefVehSpd_Cnt_T_lgc == FALSE) &&
			 (InvalidVehSpdQual_Cnt_M_lgc == FALSE) )
		{
			/* Anomaly 3788, update FlexRay Valid Vehicle speed with updated data*/
			(void)Rte_Write_FRVldVehSpd_Kph_f32(VehSpd_Kph_M_f32);
			(void)Rte_Write_SrlComVehSpd_Kph_f32(VehSpd_Kph_M_f32);
		}

		(void)Rte_Write_SrlComVehDrvCondition_Cnt_u08(VehDrvCond_Cnt_M_u08);
		(void)Rte_Write_SrlComVehNearStandstill_Cnt_u08(VehNss_Cnt_M_u08);

	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput2_TRGD_VehCfgUpdate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Cnt_lgc> of PortPrototype <CFACTORIF>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Cnt_lgc> of PortPrototype <CHWANGLEIF>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Cnt_lgc> of PortPrototype <CHWTORQUEIF>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Cnt_lgc> of PortPrototype <CMTTORQUEIF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CFACTORIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CHWANGLEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CHWTORQUEIF_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput2_TRGD_VehCfgUpdate_CMTTORQUEIF_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SerlComTarSteerTqDrvrActr_MtrNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComAssistScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComDampingScaleFactor_Uls_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComDrvDynEnable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComInputTorqueOverlay_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComReturnScaleFactor_Uls_f32(Float data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT2_APPL_CODE) SrlComInput2_TRGD_VehCfgUpdate(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput2_TRGD_VehCfgUpdate
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) CFACTORIF_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CHWTORQUEIF_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CMTTORQUEIF_Cnt_T_lgc;

	CFACTORIF_Cnt_T_lgc = Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CFACTORIF_Cnt_lgc();
	CHWTORQUEIF_Cnt_T_lgc = Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CHWTORQUEIF_Cnt_lgc();
	CMTTORQUEIF_Cnt_T_lgc = Rte_IRead_SrlComInput2_TRGD_RxPaDrvDyn_CMTTORQUEIF_Cnt_lgc();


	if(TRUE == CFACTORIF_Cnt_T_lgc)
	{	/* Provide Default values as specified in SER Coding section */
		RxAstRtnDmpFactQual_Cnt_M_u08 = D_CODINGDFLTFACTQU_CNT_U08;

	 	(void)Rte_Write_SrlComAssistScaleFactor_Uls_f32(D_CODINGDFLTASTFACT_ULS_F32);
		(void)Rte_Write_SrlComReturnScaleFactor_Uls_f32(D_CODINGDFLTRTNFACT_ULS_F32);
		(void)Rte_Write_SrlComDampingScaleFactor_Uls_f32(D_CODINGDFLTDMPFACT_ULS_F32);
	}

	if(TRUE == CHWTORQUEIF_Cnt_T_lgc)
	{	/* Provide Default values as specified in SER Coding section */
		RxTarQtaStMomQual_Cnt_M_u08 = D_CODINGDFLTIPTRQOVQU_CNT_U08;

		(void)Rte_Write_SrlComInputTorqueOverlay_HwNm_f32(D_CODINGDFLTIPTRQOV_HWNM_F32);
	}

	if(TRUE == CMTTORQUEIF_Cnt_T_lgc)
	{	/* Provide Default values as specified in SER Coding section */
		RxTarStMomQual_Cnt_M_u08 = D_CODINGDFLTOPTRQOVQU_CNT_U08;

		(void)Rte_Write_SerlComTarSteerTqDrvrActr_MtrNm_f32(D_CODINGDFLTOPTRQOV_MTRNM_F32);
	}


	/*  Driving Dynamics Enable */
	if ((RxAstRtnDmpFactQual_Cnt_M_u08 == D_CODINGDFLTFACTQU_CNT_U08) &&
		 (RxTarQtaStMomQual_Cnt_M_u08 == D_CODINGDFLTIPTRQOVQU_CNT_U08) &&
		 (RxTarStMomQual_Cnt_M_u08 == D_CODINGDFLTOPTRQOVQU_CNT_U08) )
	{
		(void)Rte_Write_SrlComDrvDynEnable_Cnt_lgc(FALSE);
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMINPUT2_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* VehSpd Quality Factor Diagnostic */	
STATIC FUNC (void, AP_SRLCOMINPUT2_CODE) VehSpdQFDiag(VAR(uint8, AUTOMATIC) RxVehSpdQF)
{		
	if ( (RxVehSpdQF == 0x00U) ||
		 ((RxVehSpdQF > 0x01U) && (RxVehSpdQF < 0x08U)) ||
		 (RxVehSpdQF == 0x09U) ||
		 (RxVehSpdQF == 0x0CU) )
	{
		VehSpdQFErrorCounter_Cnt_M_u08++;
		
		if(VehSpdQFErrorCounter_Cnt_M_u08 >= D_RXMSGINVALID_CNT_U08)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_P, 0x01U, NTC_STATUS_FAILED);
			VehSpdQFErrorCounter_Cnt_M_u08 = D_RXMSGINVALID_CNT_U08;
			VehSpdQFErrorRecovery_Cnt_M_u16 = D_RXMSGINVALID_CNT_U08;
		}
	}
	else
	{
		VehSpdQFErrorCounter_Cnt_M_u08 = 0U;
		
		if (VehSpdQFErrorRecovery_Cnt_M_u16 > 0U)
		{
			VehSpdQFErrorRecovery_Cnt_M_u16--;
		}
		else
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_P, 0x01U, NTC_STATUS_PASSED);
		}
	}
}


/* CRC and Alive Counter E2E diagnostic */
STATIC FUNC (boolean, AP_SRLCOMINPUT2_CODE) CRCAliveCntDiag ( VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode,
													         VAR(uint8, AUTOMATIC) RxAliveCnt,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) AliveFaultCount,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) AliveFaultRecovery,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) CRCErrorCount,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) CRCErrorRecovery,
													         VAR(uint16, AUTOMATIC) AliveFaultNTC,
													         VAR(uint16, AUTOMATIC) CRCErrorNTC)
{
	VAR(boolean, AUTOMATIC) CRCErrorActive_Cnt_T_lgc = FALSE;
	
	if (RxAliveCnt >= D_INVALIDALIVECOUNT_CNT_U08)
	{
		(*AliveFaultCount)++;
	}
	else
	{ 	
		if ( ((uint8)E2E_P01STATUS_REPEATED == (CRCAliveCntErrorCode & (uint8)E2E_P01STATUS_REPEATED)) )
		{
			(*AliveFaultCount)++;
		}
		else
		{
			*AliveFaultCount = D_ZERO_CNT_U8;

			if((*AliveFaultRecovery) > 0U)
			{
				(*AliveFaultRecovery)--;
			}
		}
	}	
	
	if ((*AliveFaultCount) >= D_ALIVECOUNTFAULT_CNT_U08)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(AliveFaultNTC, 0x01U, NTC_STATUS_FAILED);
		*AliveFaultCount = D_ALIVECOUNTFAULT_CNT_U08;
		*AliveFaultRecovery = D_ALIVECOUNTFAULT_CNT_U08;
	}
	else
	{
		if((*AliveFaultRecovery) == D_ZERO_CNT_U8)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(AliveFaultNTC, 0x01U, NTC_STATUS_PASSED);
		}
	}

	/* CRC Diagnostic */
    if ((uint8)E2E_P01STATUS_WRONGCRC == (CRCAliveCntErrorCode & (uint8)E2E_P01STATUS_WRONGCRC))
	{
		CRCErrorActive_Cnt_T_lgc = TRUE;
		(*CRCErrorCount)++;
		
		if((*CRCErrorCount) >= D_CRCERRCOUNTFAULT_CNT_U08)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(CRCErrorNTC, 0x01U, NTC_STATUS_FAILED);
			*CRCErrorCount = D_CRCERRCOUNTFAULT_CNT_U08;
			*CRCErrorRecovery = D_CRCERRCOUNTFAULT_CNT_U08;
		}
	}
	else
	{
		*CRCErrorCount = 0U;
		
		if ((*CRCErrorRecovery) > 0U)
		{
			(*CRCErrorRecovery)--;
		}
		else
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(CRCErrorNTC, 0x01U, NTC_STATUS_PASSED);
		}
	}
	return (CRCErrorActive_Cnt_T_lgc);
}


/* Clear all signal diagnostic counters */
STATIC FUNC(void, AP_SRLCOMINPUT2_CODE) ClearDiagCounters(void)
{
	VehSpdVldCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	VehSpdAliveFault_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	VehSpdCRCErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	VehSpdQFErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	VehSpdErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;

	DrvDynRqstVldCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	TarQtaStMomAliveFault_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	TarQtaStMomCRCErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	TarStMomCRCErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	OpTrqOvDbnceCntr_Cnt_M_u16 = D_RESETDIAGCOUNTERS_CNT_U08;

	AclnyMassCntrAliveFault_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	AclnyMassCntrAliveRecovery_Cnt_M_u8 = D_RESETDIAGCOUNTERS_CNT_U08;
	AclnyMassCntrCRCErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	AclnyMassCntrCRCErrorRecovery_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	AclnyMassCntrVldCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;

	VYawVehCntrAliveFault_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	VYawVehCntrAliveRecovery_Cnt_M_u8 = D_RESETDIAGCOUNTERS_CNT_U08;
	VYawVehCntrCRCErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	VYawVehCntrCRCErrorRecovery_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	VYawVehVldCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;

	ConVehAliveFault_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	ConVehAliveRecovery_Cnt_M_u8 = D_RESETDIAGCOUNTERS_CNT_U08;
	ConVehCRCErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	ConVehCRCErrorRecovery_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	ConVehInVldCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
  ConVehUndefCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;

	StCengCntrAliveFault_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	StCengCntrAliveRecovery_Cnt_M_u8 = D_RESETDIAGCOUNTERS_CNT_U08;
	StCengCntrCRCErrorCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	StCengCntrCRCErrorRecovery_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	StCengDrvInVldCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
	StCengDrvUndefCounter_Cnt_M_u08 = D_RESETDIAGCOUNTERS_CNT_U08;
}

/* CRC and Alive Counter E2E diagnostic */
STATIC FUNC (boolean, AP_SRLCOMINPUT2_CODE) TrqOvDebounce ( VAR(uint8, AUTOMATIC) CRCAliveCntErrorCode,
													         VAR(uint8, AUTOMATIC) RxAliveCnt,
													         P2VAR(uint8, AUTOMATIC, AUTOMATIC) DrvDynEnable)
{
	VAR(boolean, AUTOMATIC) CRCErrorActive_Cnt_T_lgc = FALSE;

	/* If there is an invalid CRC, increment the error counter. */
    if ((uint8)E2E_P01STATUS_WRONGCRC == (CRCAliveCntErrorCode & (uint8)E2E_P01STATUS_WRONGCRC))
	{

    	CRCErrorActive_Cnt_T_lgc = TRUE;

		if(TarStMomCRCErrorCounter_Cnt_M_u08 < (k_TrqOvDbnceCntrThres_Cnt_u16 + 1u))
		{
			TarStMomCRCErrorCounter_Cnt_M_u08++;
		}

		TarStMomCRCErrorRecovery_Cnt_M_u08 = D_ZERO_CNT_U8;
	}
	else
	{
		/*Handle CRC error/recovovery counters for a valid CRC.*/
		TarStMomCRCErrorCounter_Cnt_M_u08 = D_ZERO_CNT_U8;

		if(TarStMomCRCErrorRecovery_Cnt_M_u08 < D_DEBOUNCECLEARTHRESH_CNT_U16)
		{
			TarStMomCRCErrorRecovery_Cnt_M_u08++;
		}

		/* Handle incrementing and clearing alive couters. */
		if ((RxAliveCnt >= D_INVALIDALIVECOUNT_CNT_U08) ||
				((uint8)E2E_P01STATUS_REPEATED == (CRCAliveCntErrorCode & (uint8)E2E_P01STATUS_REPEATED)))
		{
			/*The alive counter is invalid. */
			if(OpTrqOvDbnceCntr_Cnt_M_u16 < (k_TrqOvDbnceCntrThres_Cnt_u16 + 1u))
			{
				OpTrqOvDbnceCntr_Cnt_M_u16++;
			}

			OpTrqOvDbnceClearCntr_Cnt_M_u16 = D_ZERO_CNT_U8;
		}
		else
		{
			/*The alive counter is valid. */
			OpTrqOvDbnceCntr_Cnt_M_u16 = D_ZERO_CNT_U8;

			if(OpTrqOvDbnceClearCntr_Cnt_M_u16 < D_DEBOUNCECLEARTHRESH_CNT_U16)
			{
				OpTrqOvDbnceClearCntr_Cnt_M_u16++;
			}
		}
	}

    /* --------------- Handle alive fault counters --------------- */

	/* Prepare to shut down Park Assist. */
	if (OpTrqOvDbnceCntr_Cnt_M_u16 == k_TrqOvDbnceCntrThres_Cnt_u16)
	{
		FinalOpTrqOvRqst_MtrNm_M_f32 = 0.0f;
		*DrvDynEnable = TRUE;
	}
	/* Fault threshold reached. Set the fault, and turn off park assist. */
	else if (OpTrqOvDbnceCntr_Cnt_M_u16 > k_TrqOvDbnceCntrThres_Cnt_u16)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_S, 0U, NTC_STATUS_FAILED);
		*DrvDynEnable = FALSE;
	}
	else
	{
		/*Fault not yet present.*/
	}

	/* A sequence of valid alive counters permits the recovery of the fault. */
	if(D_DEBOUNCECLEARTHRESH_CNT_U16 == OpTrqOvDbnceClearCntr_Cnt_M_u16)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_S, 0U, NTC_STATUS_PASSED);
	}

    /* --------------- Handle CRC fault counters --------------- */

	/* Prepare to shut down Park Assist. */
	if (TarStMomCRCErrorCounter_Cnt_M_u08 == k_TrqOvDbnceCntrThres_Cnt_u16)
	{
		FinalOpTrqOvRqst_MtrNm_M_f32 = 0.0f;
		*DrvDynEnable = TRUE;
	}
	/* Fault threshold reached. Set the fault, and turn off park assist. */
	else if (TarStMomCRCErrorCounter_Cnt_M_u08 > k_TrqOvDbnceCntrThres_Cnt_u16)
	{
		/* Prevents further accumulation in debounce counter */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_S, 0U, NTC_STATUS_FAILED);
		*DrvDynEnable = FALSE;
	}
	else
	{
		/*Fault not yet present.*/
	}

	/* A sequence of valid CRCs permits the recovery of the fault. */
	if(D_DEBOUNCECLEARTHRESH_CNT_U16 == TarStMomCRCErrorRecovery_Cnt_M_u08)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_S, 0U, NTC_STATUS_PASSED);
	}

	return(CRCErrorActive_Cnt_T_lgc);
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
