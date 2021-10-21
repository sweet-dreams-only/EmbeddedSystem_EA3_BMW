/*****************************************************************************
* Copyright 2011 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : esm.h
* Module Description: ESM (Error Signaling Module) Peripheral Registers
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue May 31 09:10:19 2011
* %version:          1 %
* %derived_by:       czgng4 %
* %date_modified:    Tue May 31 09:10:19 2011 % 
*---------------------------------------------------------------------------*/

#ifndef ESM_H
#define ESM_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

typedef volatile struct esmregs
{
	uint32 ESMIEPSR1;
	uint32 ESMIEPCR1;
	uint32 ESMIESR1;
	uint32 ESMIECR1;
	uint32 ESMILSR1;
	uint32 ESMILCR1;
	uint32 ESMSR1;
	uint32 ESMSR2;
	uint32 ESMSR3;
	uint32 ESMEPSR;
	uint32 ESMIOFFHR;
	uint32 ESMIOFFLR;
	uint32 ESMLTCR;
	uint32 ESMLTCPR;
	uint32 ESMEKR;
	uint32 ESMSSR2;
} esmregs_t;

#define ESMREGS ((esmregs_t *)0xFFFFF500)

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
05/31/11   1.0      LWW      Initial Creation
******************************************************************************/
