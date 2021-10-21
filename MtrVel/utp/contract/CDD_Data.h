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
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          2 %
 * %derived_by:       bz1q07 %
 * %date_modified:    Fri Feb 14 13:06:04 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 07/05/11  2        LWW       Added WIR data required for services
 * 08/03/11  3		  SAH		Added Structure for EOL part numbers
 */

#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"
//#include "CDD_Const.h"
#include "Rte_Type.h"

#define D_OVRSMPLBUFFSIZE_CNT_U16 8U
extern VAR(sint16, AP_MTRVEL_VAR_NOINIT) SinBuffer_Uls_G_s2p13[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(sint16, AP_MTRVEL_VAR_NOINIT) CosBuffer_Uls_G_s2p13[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(uint16, AP_MTRVEL_VAR_NOINIT) PosBuffer_Rev_G_u0p16[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(uint16, AP_MTRVEL_VAR_NOINIT) TimeBuffer_uS_G_u16p0[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(boolean, AP_MTRVEL_VAR_NOINIT) CDD_OvrSmplBfrWriteEn_Cnt_G_lgc;


#endif
