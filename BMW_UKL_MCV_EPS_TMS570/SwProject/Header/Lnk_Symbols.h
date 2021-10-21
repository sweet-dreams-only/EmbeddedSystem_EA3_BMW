/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Lnk_Symbols.h
* Module Description: This file contains the declarations of Link Time Symbols
*                     used in the application.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Wed Dec 22 18:51:19 2010
* %version:          7 %
* %derived_by:       cz7lt6 %
* %date_modified:    Sat Sep 29 16:57:41 2012 %
*---------------------------------------------------------------------------*/

#ifndef LNK_SYMBOLS_H
#define LNK_SYMBOLS_H

#include "Std_Types.h"

extern CONST(uint16, AUTOMATIC) Lnk_CalRamLoadStart;
extern CONST(uint16, AUTOMATIC) Lnk_CalRamLen;
extern CONST(uint16, AUTOMATIC) Lnk_CalRamRunStart;

extern CONST(uint16, AUTOMATIC) Lnk_TypeH_Start;
extern CONST(uint16, AUTOMATIC) Lnk_TypeH_Size;

extern CONST(uint16, AUTOMATIC) Lnk_FlsApiLoadStart;
extern CONST(uint16, AUTOMATIC) Lnk_FlsApiLen;
extern CONST(uint16, AUTOMATIC) Lnk_FlsApiRunStart;

extern CONST(uint32, AUTOMATIC) Lnk_BSS_Start;
extern CONST(uint32, AUTOMATIC) Lnk_BSS_End;

extern CONST(uint16, AUTOMATIC) Lnk_Tun0CalRunStart;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0CalLen;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0CalLoadStart;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers0CalRunStart;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers0CalLen;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers0CalLoadStart;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers1CalRunStart;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers1CalLen;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers1CalLoadStart;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers2CalRunStart;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers2CalLen;
extern CONST(uint16, AUTOMATIC) Lnk_Tun0Pers2CalLoadStart;



#endif


/*****************************************************************************
CHANGE HISTORY:

 Date      Rev      Author 			Change Description              SCR #
 				 					 (MDD Rev & Date) 		
-------   -------  --------  -----------------------------------  ----------
12/22/10   1.0   JJW         Initial version
02/09/11   2.0   JJW         Added Crc table symbols
12/23/11   4.0   JJW         Removed Ecc Symbols
                             Added TypeH Symbols
01/24/12   5.0   JJW         Added Ecc Symbols
09/29/12   7.0   KJS		 Added symbols for tuning select
*****************************************************************************/
