/*****************************************************************************
* Copyright 2012 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Adc_Cfg.h
* Module Description: Adc Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Jul 28 18:03:04 2012
* %version:          6 %
* %derived_by:       xz0btk %
* %date_modified:    Wed Jan 23 11:57:00 2013 %
*---------------------------------------------------------------------------*/


#ifndef ADC_CFG_H
#define ADC_CFG_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#include "Adc.h"
#include "SchM_Adc.h"

/* Map user defined group conversion names to appropriate group indexer */
#define AdcFwdPath     		D_GROUP1_CNT_U8
#define AdcFdbkPath     	D_GROUP2_CNT_U8
#define adcGROUP0			D_GROUPEV_CNT_U8


#define D_ADC1NUMEVTCH_CNT_U08	0U				/* Number of channels sampled (e.g. number of bits set in D_ADC1EVTCH_CNT_U32) */
#define D_ADC1EVTCH_CNT_U32		0x0000U
#define D_ADC1EVTBUFSZ_CNT_U08	52U				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG1CH_CNT_U08	2U				/* Number of channels sampled (e.g. number of bits set in D_ADC1G1CH_CNT_U32) */
#define D_ADC1G1CH_CNT_U32		0xC000U
#define D_ADC1G1BUFSZ_CNT_U08	2U				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG2CH_CNT_U08	10U				/* Number of channels sampled (e.g. number of bits set in D_ADC1G2CH_CNT_U32) */
#define D_ADC1G2CH_CNT_U32		0x3F65U
#define D_ADC1G2BUFSZ_CNT_U08	10U				/* Number of results allocated in ADC RAM, must be even */

#define ADC1_REPORTERRORSTATUS(event, param, status)		NxtrDiagMgr7_ReportNTCStatus(event, param, status)
#define ADC_EVENT_PASSED				NTC_STATUS_PASSED
#define ADC_EVENT_FAILED				NTC_STATUS_FAILED


typedef uint8	Adc_ConfigType;

#endif
