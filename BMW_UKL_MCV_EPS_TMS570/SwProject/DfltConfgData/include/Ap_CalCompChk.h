/*****************************************************************************
* Copyright 2012 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CalCompChk.h
* Module Description: CalCompChk Header File
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Thu Dec  6 16:25:00 2012 %
* %version:          1 %
* %derived_by:       cz7lt6 %
* %date_modified:    Mon Aug 26 13:27:44 2013 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
* 08/22/13  1        KJS       Initial Version
*/

#ifndef AP_CALCOMPCHK
#define AP_CALCOMPCHK

/* Defines and Marcos */
#define D_INVALIDLOAPPCALVERNUM_CNT_32		0x00000000UL
#define D_INVALIDHIAPPCALVERNUM_CNT_32		0xFFFFFFFFUL

/* Extern variables for use in the bootmanager */
extern CONST(uint32, AUTOMATIC) k_Cal1VerificationNum_Cnt_u32;
extern CONST(uint32, AUTOMATIC) k_Cal2VerificationNum_Cnt_u32;
extern CONST(uint32, AUTOMATIC) k_AppCalVerificationNum_Cnt_u32;

#endif /* AP_CALCOMPCHK */
