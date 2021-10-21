/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : appinit_cfg.h
* Module Description: This file contains the configuration of the applicaiton init sequence
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri May 11 12:17:00 2012
 * %version:          3 %
 * %derived_by:       nz63rn %
 * %date_modified:    Fri Feb 15 14:06:04 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/15/13  2        BWL        Renamed and moved to contract folder.
 */
 
#ifndef APPINIT_CFG_H_
#define APPINIT_CFG_H_

#include "Std_Types.h"

/* Peripheral Enables */
#define MIBSPI1_ENABLE  			STD_ON
#define MIBSPI3_ENABLE  			STD_ON
#define MIBSPI5_ENABLE  			STD_ON
#define GIO_ENABLE  				STD_ON

/* Peripheral RAM Parity Test Enables */
#define MIBSPI1_PARITY_ENABLE  		STD_ON
#define MIBSPI3_PARITY_ENABLE  		STD_ON
#define MIBSPI5_PARITY_ENABLE  		STD_ON
#define N2HET1_PARITY_ENABLE  		STD_ON
#define N2HET2_PARITY_ENABLE  		STD_ON
#define N2HET1TU_PARITY_ENABLE  	STD_ON
#define N2HET2TU_PARITY_ENABLE  	STD_ON
#define MIBADC1_PARITY_ENABLE  		STD_ON
#define MIBADC2_PARITY_ENABLE  		STD_ON
#define DCAN1_PARITY_ENABLE  		STD_ON
#define DCAN2_PARITY_ENABLE  		STD_ON
#define DCAN3_PARITY_ENABLE  		STD_ON
#define VIM_PARITY_ENABLE  			STD_ON
#define DMA_PARITY_ENABLE  			STD_ON
#define DMA_MPU_ENABLE 				STD_ON
#define N2HET1TU_MPU_ENABLE  		STD_ON
#define N2HET2TU_MPU_ENABLE  		STD_ON

#endif /* APPINIT_CFG_H_ */
