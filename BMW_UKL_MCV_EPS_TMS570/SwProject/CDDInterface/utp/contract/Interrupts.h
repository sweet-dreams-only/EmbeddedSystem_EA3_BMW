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
* %derived_by:       wz7x3j %
* %date_modified:    Fri Mar 23 15:57:54 2012 % 
*---------------------------------------------------------------------------*/

#ifndef INTERRUPTS_H 
#define INTERRUPTS_H  

/***************************************************************************************************
* Include files
***************************************************************************************************/

//#include "Platform_Types.h"

/**************************************************************************************************
* Global function externs
**************************************************************************************************/

//extern void EnableFrInterrupt(void);
extern void EnableMtrCtlInterrupt(void);
//extern void EnableEeSpiInterrupt(void);

//extern void DisableMtrCtlInterrupt(void);

#endif /*INTERRUPTS_H*/


