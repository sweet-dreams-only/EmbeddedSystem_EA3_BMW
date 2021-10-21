/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : PwmCdd.h
* Module Description: Pwm Complex Driver external definitions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          3 %
* %derived_by:       xz0btk %
* %date_modified:    Fri Jul 27 13:58:16 2012 % 
*---------------------------------------------------------------------------*/


#ifndef PWMCDD_H
#define PWMCDD_H

#include "PwmCdd_Cfg.h"

extern FUNC(void, PWMCDD_CODE) PwmCdd_Init(void);
extern FUNC(void, PWMCDD_CODE) PwmCdd_Per1(void);

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
12/16/10   1.0      JJW      Initial Creation
12/21/10   2.0      LWW      Added Init
******************************************************************************/
