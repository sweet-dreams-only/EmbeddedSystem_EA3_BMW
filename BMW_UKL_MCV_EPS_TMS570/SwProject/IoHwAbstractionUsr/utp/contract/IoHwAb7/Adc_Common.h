/*****************************************************************************
* Copyright 2012 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Adc_Common.h
* Module Description: Adc device driver common functions (must be stateless to
*                      execute in all contexts)
* Product           : Gen II Plus - EA3.0
* Author            : Lonnie Newton
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 02 09:15:00 2012
* %version:          1 %
* %derived_by:       cz7lt6 %
* %date_modified:    Tue May 28 17:58:26 2013 %
*---------------------------------------------------------------------------*/

#if !defined (ADC_COMMON_H)
#define ADC_COMMON_H

#include "adc_regs.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Common defines for the operation of Adc and Adc2 BSW's */
#define D_MAXCONVERSIONVALUE_CNT_U16	0x0FFFU
#define D_GROUPEND_CNT_U32				0x00000001U
#define D_GROUPBUSY_CNT_U32				0x00000004U
#define D_GROUPMEMEMPTY_CNT_U32			0x00000008U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define ADC_START_SEC_CODE
#include "MemMap.h"

Std_ReturnType ADCOffsetCalibration( adcctrlregs_t *adcREG );

#define ADC_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* ADC_COMMON_H */
  
/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
01/16/13   1.0      JJW      	Initial file creation				CR6519
******************************************************************************/
