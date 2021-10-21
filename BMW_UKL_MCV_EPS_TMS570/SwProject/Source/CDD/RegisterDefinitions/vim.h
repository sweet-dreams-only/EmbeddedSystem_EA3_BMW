/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : vim.h
* Module Description: VIM (Vectored Interrupt Manager) Peripheral Registers
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec 14 14:58:07 2010
* %version:          3 %
* %derived_by:       czgng4 %
* %date_modified:    Thu Oct 13 14:48:41 2011 % 
*---------------------------------------------------------------------------*/

#ifndef VIM_H
#define VIM_H

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"

struct vim
{
    uint32 : 24;
    uint32 IRQIVEC : 8;
    uint32 : 24;
    uint32 FIQIVEC : 8;
    uint32 : 32;
    uint32 : 32;
    uint32 FIRQPR0;
    uint32 FIRQPR1;
    uint32 FIRQPR2;
    uint32 FIRQPR3;
    uint32 INTREQ0;
    uint32 INTREQ1;
    uint32 INTREQ2;
    uint32 INTREQ3;
    uint32 REQMASKSET0;
    uint32 REQMASKSET1;
    uint32 REQMASKSET2;
    uint32 REQMASKSET3;
    uint32 REQMASKCLR0;
    uint32 REQMASKCLR1;
    uint32 REQMASKCLR2;
    uint32 REQMASKCLR3;
    uint32 WAKEMASKSET0;
    uint32 WAKEMASKSET1;
    uint32 WAKEMASKSET2;
    uint32 WAKEMASKSET3;
    uint32 WAKEMASKCLR0;
    uint32 WAKEMASKCLR1;
    uint32 WAKEMASKCLR2;
    uint32 WAKEMASKCLR3;
    uint32 IRQVECREG;
    uint32 FIQVECREG;
    uint32 : 9;
    uint32 CAPEVTSRC1 : 7;
    uint32 : 9;
    uint32 CAPEVTSRC0 : 7;
    uint32 : 32;
    uint8 CHANMAP[64];
};

struct vimparity
{
    uint32 PARFLG;
    uint32 PARCTL;
    uint32 ADDERR;
    uint32 FBPARERR;
};

#define VIM ((volatile struct vim *)0xFFFFFE00)
#define VIMPAR ((volatile struct vimparity *)0xFFFFFDEC)

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
12/14/10   1.0      JJW      Initial Creation
05/31/11   2.0      LWW      Fixed Register Name
10/13/11   3.0      LWW      Added parity registers
******************************************************************************/
