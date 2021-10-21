/*********************************************************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Dma_Cfg.h
* Module Description: DMA Peripheral Configuration Header
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*********************************************************************************************************************/
/***********************************************************************************************************************
* Version Control:
* Date Created:      Tue Mar 11 12:00:00 2014
* %version:          EA3#4 %
* %derived_by:       rzk04c %
* %date_modified:    Wed Apr 30 12:00:00 2014 %
***********************************************************************************************************************/
/***********************************************************************************************************************
* Change History:
* Date      Rev      Author    Change Description                                                                CR#
* --------  -------  --------  --------------------------------------------------------------------------------- -----
* 04/08/14   1       OT        Initial version
* 04/29/14   2       OT        Added DiagMgr configuration                                                       11855
* 09/24/15   3       JK        Anomaly fix EA3#2825 - Made the NHET header file configurable                  EA3#3286
* 08/15/16   4       AJM       Added configuration for SCI Data transfer                                      EA3#9825
***********************************************************************************************************************/


#ifndef DMA_CFG_H
#define DMA_CFG_H


#include "Ap_DiagMgr.h"


#define D_DMAFLSTSTENABLED_CNT_ENUM			STD_ON	/* FlsTst Init Groups */
#define D_FASTSPIGROUPENABLED_CNT_ENUM		STD_ON	/* 50us SPI Group */
#define D_FASTADCGROUPENABLED_CNT_ENUM		STD_ON	/* 50us ADC Group */
#define D_FASTPWMGROUPENABLED_CNT_ENUM		STD_ON	/* 50us PWM Group */
#define D_SLOWADCGROUPENABLED_CNT_ENUM		STD_ON	/* 2ms ADC Group */
#define D_SCIFORIMCGROUPENABLED_CNT_ENUM	STD_ON	/* SCI Group */

#define DMA_REPORTERRORSTATUS				NxtrDiagMgrX_ReportNTCStatus

#define DMA_NHET1PROGHFILE "Nhet_SENT_Prog.h"      /* Header file containing the definition of HET_PRD_BUF1_0 should be used */

#endif
