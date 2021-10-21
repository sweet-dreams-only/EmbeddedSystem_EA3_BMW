/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : SchM_Wdg.h
* Module Description: Definition of SchM configuration for Wdg
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       xz0btk %
 * %date_modified:    Wed Oct  3 16:31:57 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/13/24  1        JJW       Updates for integration of new Wdg
 */

#ifndef SCHM_WDG_H
#define SCHM_WDG_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

/* Wdg is not scheduled through SchM in the Nxtr EPS project, but rather by integrator placement in a task */

# define WDG_TMS570LS3x_EXCLUSIVE_AREA_0   			(SCHM_EA_SUSPENDALLINTERRUPTS)
# define SchM_Enter_Wdg_TMS570LS3x(ExclusiveArea)   	SCHM_ENTER_EXCLUSIVE(ExclusiveArea)
# define SchM_Exit_Wdg_TMS570LS3x(ExclusiveArea)    	SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_WDG_H */

