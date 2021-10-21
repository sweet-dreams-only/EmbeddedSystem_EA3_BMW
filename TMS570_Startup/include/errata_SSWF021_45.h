/* Original Header copied from TI file */
/*
 * errata_SSWF021_45.h
 *
 *  Created on: May 4, 2016
 *      Author: a0319960
 */
/*****************************************************************************
* Module File Name  : errata_SSWF021_45.h
* Module Description: This file contains the function definitions for the errata for PLL provided by TI
					  as per the erratum SSWF021#45
* Product           : Gen II Plus EA3.0
* Author            : Avinash James
*****************************************************************************/
/* Version Control:
 * Date Created:      Sat Jun 04 12:17:00 2016
 * %version:          1 %
 * %derived_by:       rzk04c %
 * %date_modified:    Fri Feb 15 16:29:22 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/23/16  1        AJM        Initial version for PLL errata functions									 EA3#9142
 * 08/24/16  2        AJM        Removed the retry count paramter											 EA3#10463
 */
 
#include "errata_SSWF021_45_defs.h"

#ifndef INCLUDE_ERRATA_SSWF021_45_H_
#define INCLUDE_ERRATA_SSWF021_45_H_

extern uint32 _errata_SSWF021_45_both_plls(uint32 count);
extern uint32 _errata_SSWF021_45_pll1(uint32 count);
extern uint32 _errata_SSWF021_45_pll2(uint32 count);

#endif /* INCLUDE_ERRATA_SSWF021_45_H_ */
