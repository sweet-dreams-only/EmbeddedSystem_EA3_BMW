
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : SpiNxt_Cfg.h
* Module Description: SpiNxt Configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          3 %
* %derived_by:       cz7lt6 %
* %date_modified:    Sat Jan 18 14:20:30 2014 % 
*---------------------------------------------------------------------------*/
/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
08/02/13   3.0      KMC       Changes to make SpiNxt configurable for Turns Counter  
                              or Digital MSB (CR 8834) 
******************************************************************************/

#ifndef SPINXT_CFG_H 
#define SPINXT_CFG_H  

/***************************************************************************************************
* Include files
***************************************************************************************************/

/* Spi used with */
#define D_SPINXT_USEWITHTC 		0U
#define D_SPINXT_USEWITHDIGMSB 	1U

/* SpiNxt used with Turns Counter or Digital MSB. */
#define D_SPINXTUSEWITH_CNT_ENUM			D_SPINXT_USEWITHTC

#endif /*SPINXT_CFG_H*/