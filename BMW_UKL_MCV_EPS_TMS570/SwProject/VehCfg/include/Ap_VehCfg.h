/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_VehCfg.h file
* Module Description: Header file for the integration specific Vehicle Configuration source file
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
*
**********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          4 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Tue Nov 26 18:38:46 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/14/13     1		KJS      Initial Version
 * 03/24/15     4		ABS      Add EEPROM to FEE fault RAM shadow variable
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Rte_type.h"
#include "DataLogistic.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef AP_VEHCFG_H_
#define AP_VEHCFG_H_

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define D_SVKSIZE_CNT_U8	74U /* Hardcoded since this SGBMs make up 65 bytes of data. However, the EEPROM is configured for 74 bytes. */
extern VAR(uint8, AP_VEHCFG_VAR) VehCfg_SvkSysSupp[D_SVKSIZE_CNT_U8];
extern VAR(uint8, AP_VEHCFG_VAR) VehCfg_SvkPlant[D_SVKSIZE_CNT_U8];
extern VAR(uint8, NVM_APPL_DATA) Nxtr_FeeInitialized_Cnt_u8[2u];


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#endif /* AP_VEHCFG_H_ */
