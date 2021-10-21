/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CDD_Data.h
* Module Description: Header file for data communicated between Nxtr
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          2 %
* %derived_by:       nz63rn %
* %date_modified:    Wed Jan 15 11:53:31 2014 % 
*---------------------------------------------------------------------------*/

#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "CDD_Const.h"
#include "Rte_Type.h"


typedef enum {
	TcPrgInit	= 				0,
	TcPrgInPrcs =				1,
	TcPrgCmpl	=	 			2
} TcFlshPrgStatus_T;

#define TcFStTstFailed 	1u
#define TcFStFldTsMon	2u
#define TcFlStNtCmpCl 	4u
#define TcFlStFld 	8u
#define D_TcPNArraySize_Cnt_U16				20u



extern VAR(TcFlshPrgStatus_T, CDD_VAR_NOINIT) CDD_TcPrgStatus_Cnt_G_enum;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashActive_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashVerify_Cnt_G_lgc;
extern VAR(uint8, CDD_VAR_NOINIT) CDD_TcFlashStatus_Cnt_G_u08;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TCprocessing_Cnt_G_lgc;



#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              	 	  SCR #
-------   -------  --------  -----------------------------------  		----------
12/07/10   1.0      JJW      Initial Creation
12/13/10   2.0      LWW      Added initial CDD interface data
12/16/10   3.0      OSteen   Add CDD_EOLSrlComSvcDft_Cnt_G_b32     		CR3639
                             and CM_DiagNegRespCode_u16
12/17/10   4.0      LWW      Changed DeadTimeComp to u8p8
12/19/10   5.0      JJW      Corrected _T_ typo on global vars
12/19/10   6.0      JJW      Added PwmCdd Vars
12/20/10   7.0      LWW      Added Shcurr signal, fixed datatypes
01/13/11   8.0      LWW      Removed Gate Drive Fault boolean
02/08/11   9.0      LWW      Added Phase Resonableness data
03/15/11   10.0     JJW      Initial metrics
04/03/11   11.0     BDO		 Added CDD_EPSInitRoutineStatus_Cnt_G_u16 	
10/11/11   12.0     BDO      Add CDD_TcPrgStatus and CDD_TcReflashActive
10/28/11   13.0		KJS		 Added CDD_Adc_ConvFlag_Uls_u08				#4601
11/23/11   14.0		BDO      Add CDD_DftAsstTbl_Cnt_lgc and CDD_DwnldAsstGain_Uls_f32
02/15/12   14.0     BDO      Add CDD_OscEnableFlag_Cnt_G_lgc, CDD_GenPosTrajEnableFlag_Cnt_G_lgc, CDD_LocktoLockEnableFlag_Cnt_G_lgc
03/28/12   16.0     JJW      Removed Metrics Global signals for new Metrics module integration
08/18/12   18.0     BDO      Updates for Learn Rack Center FDD 39 and anomaly 3188
08/18/12   19.0     BDO      Add enable flag for SweepingTechnologies
08/29/12   20.0     BDO      Correct defn of Rte_AbsHwPos_EOLHwOffsetSnsrCal - anomaly 3691
09/13/12   21.0     KJS      Added CDD_FirstActvNTC_Cnt_G_u16
09/30/12   22.0     KJS      Added CDD_CdcAuthLevel_Cnt_G_u8
11/21/11   25       JJW      Added CDD_CDDMtrPosAccessBfr_Cnt_G_u16 to decouple the MtrPos buffer from the 
 								Phase Reasonableness data in order to provide freedom for synchronizing 
                               the data buffers appropriately.
12/06/12   27     	JJW      PwmCdd FDD34B_001.3 integration.  Removal of unused Analog phase reasonableness signals		
02/07/13   29	 	DD			Change request 7247 Add CDD_DemIdSnapshot_Cnt_G_u8 variable					   
******************************************************************************/
