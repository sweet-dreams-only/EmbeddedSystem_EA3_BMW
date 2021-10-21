/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_DfltConfigData.c
* Module Description:
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          EA3#191 %
 * %date_modified:    Mon Feb 24 15:01:20 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/12/12 	1		KS		Initial Version, replaces Part_Numbers.c
 * 06/18/12 	3		JJW		Remove preA from suffix of part numbers
 * 06/25/12 	6		JJW		Updates for 09.00.11 baseline
 * 06/26/12		7		KJS		Updates for 09.00.12 baseline 
 * 06/29/12		8		KJS		Updates for 09.00.13 baseline
 * 07/10/12		9		KJS		Updates for 09.00.14 baseline -- Error in project, needed to rebaseline. 
 * 07/10/12		10		KJS		Updates for 09.00.15 baseline
 * 07/20/12		11		BDO		Updates for 09.00.16 baseline
 * ------------------------ I-350 ---------------------------
 * 08/07/12		12		KJS		Updates for 10.00.00 baseline
 * 08/08/12		13		JJW		Updates for 10.00.01 baseline
 * 08/09/12		14		KJS		Updates for 10.00.02 baseline
 * 08/10/12		15		KJS		Updates for 10.00.03 baseline
 * 08/10/12		16		KJS		Updates for 10.00.04 baseline
 * -- Note: ATS bug fix path branches from this revision with revision 16.1.1 --
 * 08/20/12		17		KJS		Updates for 10.01.00 baseline
 * 08/24/12		18		KJS		Updates for 10.01.01 baseline
 * 08/27/12		19		KJS		Updates for 10.01.02 baseline
 * 08/31/12		20		KJS		Updates for 10.01.03 baseline
 * 08/31/12		20		KJS		Updates for 10.01.03 baseline
 * -- Note: SF bug fix path branches from this revision with revision 20.1.1 --
 * 09/29/12		21		KJS		Updates for 10.02.00 baseline
 * 				22		KJS		Updates for 10.02.01 baseline
 * 				23		KJS		Updates for 10.02.02 baseline
 * 				24		KJS		Updates for 10.02.03 baseline
 * ------------------------ I-390 --------------------------- 
 * 				21.1.1  JJW		Updates for 11.00.00 baseline
 * 				21.1.2  JJW		Updates for 11.00.01 baseline
 * 10/16/12		25		KJS		Updates for 11.00.02 baseline (merge of i350/i390 paths)
 * 10/29/12		26		JJW		Updates for 11.00.03 baseline
 * 11/01/12		27		JJW		Updates for 11.00.04 baseline
 * 11/02/12		28		JJW		Updates for 11.00.05 baseline
 * 11/07/12		29		JJW		Updates for 11.00.06 baseline
 * 11/08/12		30		JJW		Updates for 11.00.07 baseline
 * 11/10/12		31		JJW		Updates for 11.01.00 baseline
 * 11/12/12		32		JJW		Updates for 11.01.01 baseline
 * 11/14/12		33		JJW		Updates for 11.01.02 baseline
 * 11/15/12		34		KJS		Updates for 11.01.03 baseline
 * 11/20/12		35		JJW		Updates for 11.02.00 baseline
 * 11/21/12		36		JJW		Updates for 11.02.01 baseline
 * 11/26/12		37		JJW		Updates for 11.03.00 baseline
 * 11/27/12		38		KJS		Updates for 11.03.01 baseline
 * 11/28/12		39		JJW		Updates for 11.03.02 baseline
 * 12/04/12     40      NRAR    Added new default values
 * 12/04/12     41      KJS     Updates for 11.04.00 baseline
 * 12/06/12     42      JJW     Default data code size optimization, and update PN to 11.04.01 baseline
 * 12/06/12     43      JJW     update PN to 11.04.02 baseline
 * 12/07/12     44      JJW     Default data anomaly correction, and update PN to 11.04.03 baseline
 * 12/11/12     45      KJS     Update PN for 11.04.04 baseline
 * 01/07/13     47      KJS     Update PN for 11.05.00 baseline
 * 01/09/13     48      KJS     Update PN for 11.05.01 baseline
 * 01/27/13     49      KJS     Update PN for 12.00.00 baseline (I-410 PR)
 * 01/28/13     50      KJS     Update PN for 12.00.01 baseline
 * 02/06/13     52      KJS     Update PN for 12.00.02 baseline
 * 02/09/13     53      JJW     Update PN for 12.00.03 baseline (Some CRs in Synergy are marked with 12.01.00 for release version that were built in this build)
 * 02/10/13		54		KJS		Update PN for 12.00.04 baseline
 * 02/12/13		55		KJS		Update PN for 12.00.05 baseline
 * 02/15/13		56		KJS		Update PN for 12.00.06 baseline
 * 02/16/13		57		Selva	Update PN for 12.00.07 baseline
 * 02/22/13		58		KJS		Update PN for 13.00.00 baseline (I-421 PR)
 * 03/02/13		59		KJS		Update PN for 13.00.01 baseline
 * 03/12/13		60		KJS		Update PN for 13.00.02 baseline
 * 03/15/13		61		KJS		Update PN for 13.00.03 baseline
 * 03/18/13		62		KJS		Update PN for 13.00.04 baseline
 * 03/18/13		63		KJS		Update PN for 13.00.05 baseline
 * 03/20/13		64		KJS		Update PN for 13.00.06 baseline and updates for EOL Turns Counter Cals
 * 03/21/13		65		KJS		Update PN for 13.00.07 baseline
 * 03/22/13		66		KJS		Update PN for 13.00.08 baseline
 * 03/26/13		67		KJS		Update PN for 13.00.09 baseline
 * 04/01/13		67.1.1	KJS		Update PN for 13.00.10 baseline
 * 04/03/13		68		KJS		Update PN for 14.00.00 baseline (I-490 PR)
 * 04/06/13		69		KJS		Update PN for 14.00.01 baseline (I-490 PR)
 * 04/10/13		70		JJW		Add R_BEMF redundant init in DfltConfigData_MtrPosSnsr_EOLData()
 * 04/12/13		71		KJS		Update PN for 14.00.02 baseline (I-490 PR)
 * 04/14/13		72		KJS		Update PN for 14.00.03 baseline (I-490 PR)
 * 04/15/13		73		KJS		Update PN for 14.00.04 baseline (I-490 PR)
 * 04/16/13		74		KJS		Update PN for 14.00.05 baseline (I-490)
 * 04/18/13		75		KJS		Update PN for 14.00.06 baseline (I-490 ATS)
 * 04/26/13		76		KJS		Update PN for 14.01.00 baseline
 * 04/27/13		77		KJS		Update PN for 14.01.01 baseline
 * 04/27/13		78		BWL		Update PN for 14.01.02 baseline
 * 05/01/13		79		KJS		Update PN for 14.01.03 baseline 
 * 05/01/13		80		KJS		Update PN for 14.01.04 baseline 
 * 05/02/13		81		KJS		Update PN for 14.01.05 baseline 
 * 05/03/13		82		KJS		Update PN for 14.01.06 baseline
 * 05/07/13		83		KJS		Update PN for 14.02.00 baseline (I-500)
 * 05/09/13		84		KJS		Update PN for 14.02.01 baseline (I-500)
 * 05/21/13		85		KJS		Update PN for 15.00.00 baseline (I-501)
 * 05/28/13		86		KJS		Update PN for 15.00.01 baseline (I-501)
 * 06/01/13		88		KJS		Update PN for 15.00.02 baseline (I-502)
 * 06/05/13		86.1.1	KJS		Update PN for 15.00.91 baseline (I-501 with CCFixes)
 * 06/06/13		86.1.2	KJS		Update PN for 15.00.92 baseline (I-501 with CCFixes)
 * 06/06/13		89		KJS		Update PN for 15.01.00 baseline (I-502 with CCFixes) -- Split of MCV and UKL projects
 * 06/07/13		90		KJS		Update PN for 16.00.00 baseline (I-431 UKL)
 * 06/07/13		91		KJS		Update PN for 16.00.01 baseline (I-431 UKL)
 * 06/18/13		92		KJS		Update PN for 16.01.00 baseline (I-431 UKL)
 * 06/20/13		93		KJS		Update PN for 16.01.01 baseline (I-431 UKL)
 * 06/20/13		94		KJS		Update PN for 16.01.02 baseline (I-431 UKL)
 * 06/21/13		95		KJS		Update PN for 16.01.03 baseline (I-431 UKL)
 * 07/02/13		96		KJS		Merged changes from MCV for AbsHwPos Pim Nvm merged into a single block. 
 * 07/10/13		97		KJS		Update PN for 17.00.00 baseline (I-490 UKL)
 * 07/12/13		98		KJS		Update PN for 17.00.01 baseline (I-490 UKL)
 * -- Note: F56 builds (17.xx.xx series) brached from this revision with revision 98.1.1 -- 
 * 08/30/13		99		KJS		Update PN for 18.00.00 baseline -- 768K Memory changes for UKL
 * 09/06/13		100		KJS		Update PN for 18.00.01 baseline
 * 09/06/13		101		KJS		Update PN for 18.00.02 baseline
 * 09/20/13		102		KJS		Update PN for 18.00.03 baseline
 * 10/14/13		103		KJS		Corrected constant for anomaly 5727
 *								Update PN for 18.01.00 baseline
 * 10/22/13		104		KJS		Corrected anomaly 5909
 *								Update PN for 18.02.00 baseline
 * 10/23/13		105		KJS		Update PN for 18.03.00 baseline
 * 10/29/13		106		KJS		Update PN for 19.00.00 baseline -- 768K memory changes, backwards compatible with older hardware
 * 11/11/13		107		KJS		Update PN for 19.01.00 baseline
 * 11/16/13		108		KJS		Update PN for 19.01.01 baseline
 * 11/19/13		109		KJS		Added function to support loading default data for SVK supplier and plant NvM blocks
								Update PN for 19.01.02 baseline
 * 11/22/13		110		KJS		Update PN for 19.01.03 baseline
 * 11/26/13		111		KJS		Update PN for 19.02.00 baseline
 * 11/27/13		112		BWL		Update PN for 19.03.00 baseline
 * 12/02/13		113		KJS		Update PN for 19.04.00 baseline
 * 12/09/13		114		KJS		Update PN for 19.05.00 baseline
 * 12/19/13		115		KJS		Update PN for 19.06.00 baseline
 * 01/09/14		116		KJS		Update PN for 19.06.01 baseline
 * 01/18/14		117		KJS		Update PN for 19.06.02 baseline
 * 01/18/14		118		KJS		Update PN for 19.06.03 baseline
 * 01/18/14		119		KJS		Update PN for 19.06.04 baseline
 * 01/23/14		120		KJS		Update PN for 19.07.00 baseline
 * 01/28/14		121		KJS		Update PN for 19.08.00 baseline
 * 02/01/14		122		KJS		Update PN for 19.08.01 baseline
 * 02/03/14		123		KJS		Update PN for 19.09.00 baseline
 * 02/24/14     124		NRAR    Update PN for 19.09.01 baseline
 * 03/21/14     125		KJS	    Update PN for 20.00.00 baseline
 * 03/21/14     126		KJS	    Update PN for 20.00.01 baseline
 * 06/04/14     127		KJS	    Update PN for 20.00.02 baseline
 * 06/10/14     128		KJS	    Update PN for 20.01.00 baseline
 * 06/12/14     129		KJS	    Update PN for 20.02.00 baseline
 * 09/03/14     130		KJS	    Update PN for 20.03.00 baseline
 * 09/04/14     131		KJS	    Update PN for 20.03.01 baseline
 * 09/29/14     132		KJS	    Update PN for 20.03.02 baseline
 * 11/03/14     133		AS	    Update PN for 20.04.00 baseline
 * 11/04/14     134		KJS	    Update PN for 21.00.00 baseline
 * 11/07/14     135		KJS	    Update PN for 21.00.01 baseline
 * 11/21/14     136		KJS	    Update PN for 21.01.00 baseline
 * 12/09/14     137		KJS	    Update PN for 21.02.00 baseline
 * 12/10/14     139		KJS	    Corrected #if statement for TI_ENABLE
 * 21/01/15     140		ABS	    Update PN for 21.03.00 baseline
 * 02/01/15     141		ABS	    Update PN for 21.04.00 baseline
 * 03/24/15     142		ABS	    Update PN for 21.05.00 baseline
 * 03/25/15     143		ABS	    EA3#259 Taigene/Letrika Motor Service
 * 03/25/15     144		ABS	    Update PN for 21.05.01 baseline
 * 03/25/15     145		ABS	    Update PN for 21.05.02 baseline
 * 04/01/15     146		ABS	    Update PN for 21.05.03 baseline
 * 04/02/15     147		ABS	    Update PN for 21.05.04 baseline
 * 04/14/15     148		ABS	    Update PN for 21.06.00 baseline
 * 04/24/15     149		KJS	    Update PN for 21.07.00 baseline
 * 04/25/15     150		ABS	    Update PN for 21.08.00 baseline
 * 05/18/15     151     KJS     Update PN for 21.09.00 baseline
 * 06/11/15     152     ABS     Update PN for 21.10.00 baseline
 * 06/25/15     153     ABS     Update PN for 21.11.00 baseline
 * 07/23/15     154     ABS     Update PN for 21.12.00 baseline
 * 07/30/15     155     KJS     Update PN for 21.13.00 baseline
 * 08/13/15     156     ABS     Update PN for 21.14.00 baseline
 * 08/19/15     157     ABS     Update PN for 21.14.02 baseline
 * 08/21/15     158     ABS     Update PN for 21.14.03 baseline
 * 08/21/15     159     ABS     Update PN for 21.14.04 baseline
 * 08/27/15     160     ABS     Update PN for 21.14.05 baseline
 * 09/15/15     161     ABS     Update PN for 22.00.00 baseline
 * 10/06/15     162     ABS     Update PN for 23.00.00 baseline
 * 11/09/15     163     ABS     Update PN for 23.01.00 baseline
 * 11/12/15     164     ABS     Update PN for 23.01.01 baseline
 * 02/09/16     165     ABS     Update PN for 23.02.00 baseline
 * 02/15/16     166     ABS     Update PN for 23.02.01 baseline
 * 02/19/16     167     ABS     Update PN for 23.02.02 baseline
 * 02/25/16     168     ABS     Update PN for 23.02.03 baseline
 * 02/28/16     169     KJS     Update PN for 23.02.04 baseline
 * 03/09/16     170     ABS     Update PN for 23.03.00 baseline
 * 04/26/16     171     ABS     Update PN for 23.04.00 baseline
 * 05/26/16     172     ABS     Update PN for 23.04.01 baseline
 * 06/15/16     173     ABS     Update PN for 23.04.02 baseline
 * 06/17/16     174     ABS     Update PN for 23.04.03 baseline
 * 06/29/16     175     ABS     Update PN for 23.05.00 baseline
 * 07/19/16     176     ABS     Update PN for 23.06.00 baseline
 * 08/01/16     177     RMV     Update PN for 23.07.00 baseline
 * 08/08/16     178     RMV     Update PN for 23.07.01 baseline
 * 08/08/16     179     RMV     Update PN for 23.07.02 baseline
 * 08/09/16     180     RMV     Update PN for 23.07.03 baseline
 * 08/30/16     181     ABS     Update PN for 23.08.00 baseline
 * 09/09/16     182     ABS     Update PN for 23.08.01 baseline
 * 09/22/16     183     RMV     Update PN for 23.09.00 baseline
 * 10/05/16     183.1.1 RMV     Update PN for 23.09.01 baseline
 * 10/06/16     184     ABS     Update PN for 24.00.00 baseline
 * 10/25/16     185     ABS     Update PN for 24.01.00 baseline
 * 11/02/16     186     ABS     Update PN for 24.01.01 baseline
 * 11/11/16     187     ABS     Update PN for 24.01.02 baseline
 * 11/19/16     188     ABS     Update PN for 24.02.00 baseline
 * 11/19/16     188     ABS     Update PN for 24.02.00 baseline
 * 02/07/17     189     ABS     Update PN for 24.03.00 baseline
 * 04/28/17     190     ABS     Update PN for 24.04.00 baseline
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_DfltConfigData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "Ap_CalCompChk.h"
#include "CalConstants.h"
#include <string.h> /* provide memset() and memcpy() definitions */


/* Select the release suffix based on the build type*/
#if defined (T1_ENABLE)
	#define D_SUFFIX    "_T1"
#elif defined(SWEEPBUILD)
	#define D_SUFFIX    "_SWP1"
#elif( BC_FLTINJECTION_ENABLEFAULTINJECTION == STD_ON )
	#define D_SUFFIX    "_FLT"
#elif defined(DEBUG)
	#define D_SUFFIX    "_DBG"
#else
	#define D_SUFFIX	""
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
VAR(uint8, NVM_APPL_DATA) Nxtr_FeeInitialized_Cnt_u8[2u];
VAR(uint8, CDD_PARTNUMBER) Nvm_MtrSuplrByte_Cnt_u8;
VAR(uint16, CDD_PARTNUMBER) Nvm_ElecHwIndex_Cnt_u16;

/*Current Sw Release Number(from CM Synergy)*/

/* Multiple strings separated by a space are combined at compile time.  So the result of the expression is a single string */
CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[50] = "BUKL_24.05.00" D_SUFFIX;

/* Calibration/Application version check
 *
 * Version numbers shall change any time the calibrations change. The check is designed
 * to prevent customer tools from flashing older calibration sets (which just will update
 * the SWE for the cals) with a newer, or older, application that could render the system
 * in a continuous reset state. This number is to be maintained by software.
 *
 * Format:
 * CAL1 version number (for Tuning Set and Common Cals) shall always be 0xFFFF ZZZZ, where ZZZZ is the version number
 * CAL2 version number (for Personalities) shall always be 0xYYYY FFFF, where YYYY is the version number
 * App version number shall always be the logical bit AND of CAL2 and CAL1 or format 0xYYYYZZZZ
 * App version of all 0s or all Fs are invalid.
 */
#define D_CAL1VERNUM_CNT_U32		0xFFFF000EUL
#define D_CAL2VERNUM_CNT_U32		0x0009FFFFUL
#define D_APPVERSIONCHK_CNT_U32		(D_CAL1VERNUM_CNT_U32 & D_CAL2VERNUM_CNT_U32)

#pragma DATA_SECTION(k_Cal1VersionNum_Cnt_u32, ".Cal1VerNum");
CONST(uint32, AUTOMATIC) k_Cal1VersionNum_Cnt_u32 = D_CAL1VERNUM_CNT_U32;

#pragma DATA_SECTION(k_Cal2VerificationNum_Cnt_u32, ".Cal2VerNum");
CONST(uint32, AUTOMATIC) k_Cal2VerificationNum_Cnt_u32 = D_CAL2VERNUM_CNT_U32;

#pragma DATA_SECTION(k_AppCalVerificationNum_Cnt_u32, ".AppCalVerVal");
CONST(uint32, AUTOMATIC) k_AppCalVerificationNum_Cnt_u32 = D_APPVERSIONCHK_CNT_U32;

/* End Calibration/Application version check */

#pragma DATA_SECTION(k_CalRelNum_Cnt_u8, ".FlashCalSeg");
CONST(uint8, CDD_PARTNUMBER) k_CalRelNum_Cnt_u8[50] =  "DEFAULT_CALS";

CONST(uint8, CDD_PARTNUMBER) k_SysSupplierID[3] = {0x00, 0x00, 0xB5};	/* 0x0000B5 or 181 (dec) */

/* SER Defined NvM Data */

/* Externally Visible Initial Data for NvM driver ROM Block defs */
CONST(HwTrqScale_Datatype, CDD_PARTNUMBER) T_InitHwTrq_HwTrqScaleData = { 0.453125F,        /*   Float32 HwTrqScale_VoltsPerDeg_f32; */
																		  FALSE				/*   Boolean HwTrqScalePerf_Cnt_lgc;     */
																		};

CONST(HwTrqTrim_Datatype, CDD_PARTNUMBER) T_InitHwTrq_HwTrqTrimData = { 0.0F,         /*   Float32 HwTrqTrim_Volts_f32; */
																		2.5F,  	      /*   Float32 T1Trim_Volts_f32;    */
																		2.5F,         /*   Float32 T2Trim_Volts_f32;    */
																		FALSE         /*   Boolean HwTrqTrimPerf_Cnt_lgc;*/
    	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 };

CONST(EOTLearned_DataType, CDD_PARTNUMBER) T_InitLearnedEOT = { 400.0F,         /*   Float32 CWEOTPosition_HwDeg_f32; */
																400.0F,  	    /*   Float32 CCWEOTPosition_HwDeg_f32;    */
																FALSE,          /*   Boolean CWEOTFound_Cnt_lgc; */
																FALSE			/*   Boolean CCWEOTFound_Cnt_lgc; */
	 	 	 	       	   	   	   	   	   	   	   	   	   	  };

CONST(RackCenterType, CDD_PARTNUMBER) T_InitLnRkCtr_RackCntrData = { 0.0F,	/* Float32 TotalRackTravel_HwDeg_f32 */
																	 0.0F, 	/* Float32 RackCntrMtrDeg_MtrDeg_f32    */
																	 0.0F, 	/* Float32 RackCntrMtrRev_MtrRev_f32   */
																	 FALSE,	/* Boolean RackCntrComplete_Cnt_lgc*/
																	 FALSE  /* Boolean RackCntrMtrAngleFound_Cnt_lgc */
																   };

CONST(uint32, CDD_PARTNUMBER) T_InitEPSDefeats_Cnt_u32 = 0U;

CONST(uint8, CDD_PARTNUMBER) T_InitNMEC_Cnt_u8 = 0xFEU;

static CONST(uint16, CDD_PARTNUMBER) T_InitEOLCtrlPolarity_Cnt_b16 = 0x30U;

CONST(AbsHwPosTrim_DataType, CDD_PARTNUMBER) T_InitAbsHwPos_Trim = {	0.0F, 0xFFFFFFFFu, 		/* VehCntrOffset R/C          */
																				0x0FFFU, 0xF000u,	/* RacktoVehCntrOffset R/C 	  */
																				FALSE, ~((uint8)FALSE)}; /* LTVehCntrComplete R/C */

static CONST(EOLNomMtrParamType, CDD_PARTNUMBER) T_InitEOLNomMtrParam = { 	0.0344F,	/* Float32 NomKe_VpRadpS_f32 */
																	        24.16F,   /* Float32 NomL_Henry_f32    */
																	        95.5F,   /* Float32 NomRmtr_Ohm_f32   */
																 	 	 };

static CONST(float32, CDD_PARTNUMBER) T_InitTorqueCmdSF_Uls_f32 = 1.0F;

static CONST(TuningSelectParam, CDD_PARTNUMBER) T_InitVehCfg_PrevVldTuningSel = { 	0U,	/* uint16 TuningSet */
																	    0U /* uint16 TuningPers    */
																	 };

static CONST(uint16, CDD_PARTNUMBER) T_InitIgnCntr_Cnt_u16 = 0U;
CONST(uint8, CDD_PARTNUMBER) T_MtrSuplrService_Data = 0U;

/* TODO: <KJS> Remove */
//static CONST(uint8, CDD_PARTNUMBER) T_DfltHWAP_SgbmIdData_Cnt_u8[8] = { 0x02u,
//																		0x00u, 0x00u, 0x00u, 0x00,
//																		0xFFu, 0xFFu, 0xFFu}; /* Rev # -- All 0xFF per anomaly 5727 */


/* TODO: <KJS> Remove
static CONST(uint8, CDD_PARTNUMBER) T_DfltHWAP_HWEDevelopmentData_Cnt_u8[15] = {0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
																				0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
																				0x00u, 0x00u, 0x00u, 0x00u, 0x00u};
*/

/*
 * TODO: Define proper trusted function calls to update the secured blocks so we meet the application
 * safety requirements.
 */

/* Processing Functions */
FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void)
{
	/* Place any required init functionality here. */
	return;
}


FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_MtrPosSnsr_EOLData(void)
{
	/* Require the MEC to be set in Manufacturing Mode for default init */
	if (NxtrMEC_Uls_G_enum == ManufacturingMode )
	{
		/* EOL Motor Sensor Calibration Data */
		/* The desired default value is largely 0 (i.e. 300+ zeros), so for code density use a loop to initialize the entire memory region to 0 and only init non-zero values */
		memset((void*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData, 0u, TableSize_m(NvMP_Rte_MtrPos_MtrPosSnsr_EOLData));

		/* Init the non-zero structure elements */
		((MtrPosCal_DataType*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData)->R_BEMFCal_Rev_u0p16 = 0xFFFFU;
		((MtrPosCal_DataType*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData)->Sin1Offset_Volts_u3p13 = 0x5000U;
		((MtrPosCal_DataType*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData)->Sin1AmpRec_Uls_u3p13 = 0x2000U;
		((MtrPosCal_DataType*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData)->Cos1Offset_Volts_u3p13 = 0x5000U;
		((MtrPosCal_DataType*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData)->Cos1AmpRec_Uls_u3p13 = 0x2000U;
		((MtrPosCal_DataType*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData)->CosDelta1Rec_Uls_u3p13 = 0x2000U;
		((MtrPosCal_DataType*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData)->Sin1GainCorr_Uls_u1p15 = 0x2000U;
		((MtrPosCal_DataType*)NvMP_Rte_MtrPos_MtrPosSnsr_EOLData)->Cos1GainCorr_Uls_u1p15 = 0x2000U;
	}
}

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_IGNCNTR(void)
{
	/* Require the MEC to be set in Manufacturing Mode for default init */
	if (NxtrMEC_Uls_G_enum == ManufacturingMode )
	{
		/* Ign Cntr */
		Nvm_IgnCntr_Cnt_u16 = T_InitIgnCntr_Cnt_u16;
	}
}

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_VehCfg_PrevVldTuningSel(void)
{
	/* Require the MEC to be set in Manufacturing Mode for default init */
	if (NxtrMEC_Uls_G_enum == ManufacturingMode )
	{
		/* VehCfg Prev Vld Tuning select */
		Rte_VehCfg_PrevVldTuningSel = T_InitVehCfg_PrevVldTuningSel;
	}
}

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_TrqCmdScl_TorqueCmdSF_Uls_f32(void)
{
	/* Require the MEC to be set in Manufacturing Mode for default init */
	if (NxtrMEC_Uls_G_enum == ManufacturingMode )
	{
		memcpy((void*)NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32, ((void*) &T_InitTorqueCmdSF_Uls_f32), TableSize_m(NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32));
	}
}

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_ParamComp_EOLNomMtrParam(void)
{
	/* Require the MEC to be set in Manufacturing Mode for default init */
	if (NxtrMEC_Uls_G_enum == ManufacturingMode )
	{
		memcpy((void*)NvMP_Rte_ParamComp_EOLNomMtrParam, ((void*) &T_InitEOLNomMtrParam), TableSize_m(NvMP_Rte_ParamComp_EOLNomMtrParam));
	}
}

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Polarity_EOLCtrlPolarity(void)
{
	/* Require the MEC to be set in Manufacturing Mode for default init */
	if (NxtrMEC_Uls_G_enum == ManufacturingMode )
	{
		Rte_Polarity_k_SystemPolarity_Cnt_b16 = T_InitEOLCtrlPolarity_Cnt_b16;
	}
}


/********************************************************************************************************************************
 * The following section are for blocks that do not require MEC checks
 */

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_HwTrq_EOLTrqStepData(void)
{
	/* Analog Hw Trq Trim Data */
	memset((void*)NvMP_Rte_HwTrq_EOLTrqStepData, 0u, TableSize_m(NvMP_Rte_HwTrq_EOLTrqStepData));
}

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_CMS_ECUHWPN(void)
{
	/* ECU Hardware Part Number */
	memset((void*)Nvm_EcuHwPn_Cnt_u8, 0u, TableSize_m(Nvm_EcuHwPn_Cnt_u8));
}

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_DIAGMGR_NTCSTRG(void)
{
	VAR(uint16, AUTOMATIC) i;

	/* Nxtr Storage Array */
	for (i=0; i<TableSize_m(NTCStrgArray_Cnt_str); i++)
	{
		NTCStrgArray_Cnt_str[i].NTC = 0;
		NTCStrgArray_Cnt_str[i].Status = 0;
		NTCStrgArray_Cnt_str[i].AgingCounter = 0xFF;
	}
}

FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_TurnsCounter_TcEOLCals(void)
{
	NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[0] = k_TcEolOffsetDef_Cnt_u08;
	NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[1] = k_TcEolOffsetDef_Cnt_u08;
	NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[2] = k_TcEolSin2CosGainDef_Cnt_u08;
	NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[3] = k_TcEolSinVsCosMinDef_Cnt_u08;
	NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[4] = k_TcEolSinVsCosMaxDef_Cnt_u08;
	NvMP_Rte_TurnsCounter_EOLTurnsCntrCals[5] = k_TcEolCalChksmDef_Cnt_u08;

	return;
}

/* TODO: <KJS> Remove */
//FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_HWAPInitSetup(void)
//{
//	/* This function is used to set a default set of values in HWAP when upgrading from an older SW set */
//	memcpy((uint8 *)&(HwDescData.HweTable[1].HWESgbmId[0]), (uint8 *)&(T_DfltHWAP_SgbmIdData_Cnt_u8[0]), 8u);
//	memcpy((uint8 *)&(HwDescData.HweTable[1].HWEDevelopmentInfo[0]), (uint8 *)&(T_DfltHWAP_HWEDevelopmentData_Cnt_u8[0]), 15u);
//
//	return;
//}

//FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_HWAPSysSuppSetup(P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataBuffer_Uls_T_u8)
//{
//	/* Move the default SGBM ID information for HWAP into the supplier block */
//	memcpy((uint8 *)&(DataBuffer_Uls_T_u8[0]), (uint8 *)&(T_DfltHWAP_SgbmIdData_Cnt_u8[0]), 8u);
//
//	return;
//}
