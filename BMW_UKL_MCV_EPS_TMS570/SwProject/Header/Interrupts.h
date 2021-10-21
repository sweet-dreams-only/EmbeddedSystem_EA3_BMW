/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Interrupts.h
* Module Description: Interrupt API
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          1 %
* %derived_by:       xz0btk %
* %date_modified:    Sun Nov 14 09:01:24 2010 % 
*---------------------------------------------------------------------------*/

#ifndef INTERRUPTS_H 
#define INTERRUPTS_H  

/***************************************************************************************************
* Include files
***************************************************************************************************/

#include "Platform_Types.h"

/**************************************************************************************************
* Global function externs
**************************************************************************************************/

extern void EnableFrInterrupt(void);
extern void EnableMtrCtlInterrupt(void);
extern void EnableEeSpiInterrupt(void);

extern void DisableMtrCtlInterrupt(void);

#endif /*INTERRUPTS_H*/


