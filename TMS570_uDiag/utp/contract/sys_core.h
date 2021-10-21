/*****************************************************************************
* Copyright 2012 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : sys_core.h
* Module Description: TI Halcogen based header
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       nz63rn %
 * %date_modified:    Thu Jun  6 12:27:50 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/09/12  1        LWW       Initial Version
 */

#ifndef SYS_CORE_H_
#define SYS_CORE_H_

#include "Std_Types.h"

void _coreEnableVfp_(void);

void _coreInitRegisters_(void);

void _esmCcmErrorsClear_(void);

void _coreEnableRamEcc_(void);

uint32 _coreGetDebugStatusAndControlRegister_(void);

uint32 _coreGetSecondaryAuxiliaryControlRegister_(void);

void _coreSetSecondaryAuxiliaryControlRegister_(uint32 SecAuxCtrlRegVal_Cnt_T_u32);

uint32 _coreGetFPSCR_(void);

#endif
