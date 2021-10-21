/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : tcram.h
* Module Description: TCRAM (Tightly-Coupled RAM Wrapper) Peripheral Registers
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue May 31 09:10:25 2011 % 
* %version:          1 %
* %derived_by:       czgng4 %
* %date_modified:    Tue May 31 09:10:25 2011 % 
*---------------------------------------------------------------------------*/

#ifndef TCRAM_H
#define TCRAM_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

typedef volatile struct tcram
{
	uint32 RAMCTRL;
	uint32 RAMTHRESHOLD;
	uint32 RAMOCCUR;
	uint32 RAMINTCTRL;
	uint32 RAMERRSTATUS;
	uint32 RAMSERRADDR;
	uint32 : 32;
	uint32 RAMUERRADDR;
	uint32 : 32;
	uint32 : 32;
	uint32 : 32;
	uint32 : 32;
	uint32 RAMTEST;
	uint32 : 32;
	uint32 RAMADDRDECVECT;
	uint32 RAMPERRADDR;
}tcram_t;

#define TCRAM0 ((tcram_t *)0xFFFFF800)
#define TCRAM1 ((tcram_t *)0xFFFFF900)

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
05/31/11   1.0      LWW      Initial Creation
******************************************************************************/
