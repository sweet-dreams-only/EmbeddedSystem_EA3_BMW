/*****************************************************************************
* Copyright 2014 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : TcFlshPrg_Cfg.h
* Module Description: Turns Counter PIC Programming
* Product           : Gen II Plus - EA3.0
* Author            : Kathleen Creager
*****************************************************************************/
/* Version Control:
 * Date Created:      Tue Jan 14 12:09:18 2014
 * %version:          1 %
 * %derived_by:       nz63rn %
 * %date_modified:    Thu Jan 16 08:25:20 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/14/14  1        KMC       Initial creation for autoflash support			    						  11183
 *
 */
#ifndef TCFLSHPRG_CFG_H
#define TCFLSHPRG_CFG_H

#include "Cd_TcFlshPrg.h" 

/* "IgnCntVarName" to be filled in with correct NVM ignition counter RAM variable name from NVM config for integration project */
#define TcFlshPrg_NVMIgnCntr_Cnt_u16     IgnCntVarName
extern uint16 TcFlshPrg_NVMIgnCntr_Cnt_u16;

#endif /* TCFLSHPRG_CFG_H */
