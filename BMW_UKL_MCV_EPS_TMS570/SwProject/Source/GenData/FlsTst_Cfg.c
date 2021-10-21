
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : FlsTst_Cfg.c
* Module Description: Configuration file of FlsTst module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 05.10.2016 11:31:14
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          4 %
 * %date_modified:    Fri May  3 14:44:16 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/13/12   1       JJW       Initial template creation
 * 09/17/12   2       JJW       Remove extra comma in generation of FlsTst_ConfigType definition
 * 11/26/12   3       JJW       Notification funciton generation support added
 */

#include "FlsTst.h" /*[FlsTst003]*/

/* Externally defined symbols */
extern CONST(uint64, AUTOMATIC) _CCT_Range_10_Address;
extern CONST(uint64, AUTOMATIC) _CCT_Range_10_Start;

extern CONST(uint64, AUTOMATIC) _CCT_Range_11_Address;
extern CONST(uint64, AUTOMATIC) _CCT_Range_11_Start;

extern CONST(uint64, AUTOMATIC) _CCT_Range_12_Address;
extern CONST(uint64, AUTOMATIC) _CCT_Range_12_Start;

extern CONST(uint64, AUTOMATIC) _CRC_BootMangr_Address;
extern CONST(uint64, AUTOMATIC) _CRC_BootMangr_Start;

extern CONST(uint64, AUTOMATIC) _CRC_BootLoader1_Address;
extern CONST(uint64, AUTOMATIC) _CRC_BootLoader1_Start;

#define FLSTST_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* FlsTst Notification Function Extern Definitions */
extern FUNC(void, AUTOMATIC) Appl_FlsTstCompletedNotif(void);

/* FlsTst Configuration Definitions */
CONST(FlsTst_MemBlockType, AUTOMATIC) FlsTst_MemBlk_Runtime[ 5u ] = {
	{  /* Cal2 block config */
		0UL,	/* CRC L32 Init Value */
		0UL,	/* CRC H32 Init Value */
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CCT_Range_10_Address, /*crcPtr*/
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CCT_Range_10_Start, /*startPtr*/
		1U, /* secnum */
		4023u, /* seclength */
		4023u, /* dmaElementCnt */
		1u /* dmaFrameCnt */
	},
	{  /* Cal1 block config */
		0UL,	/* CRC L32 Init Value */
		0UL,	/* CRC H32 Init Value */
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CCT_Range_11_Address, /*crcPtr*/
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CCT_Range_11_Start, /*startPtr*/
		1U, /* secnum */
		8116u, /* seclength */
		4058u, /* dmaElementCnt */
		2u /* dmaFrameCnt */
	},
	{  /* App block config */
		0UL,	/* CRC L32 Init Value */
		0UL,	/* CRC H32 Init Value */
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CCT_Range_12_Address, /*crcPtr*/
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CCT_Range_12_Start, /*startPtr*/
		1U, /* secnum */
		65458u, /* seclength */
		2846u, /* dmaElementCnt */
		23u /* dmaFrameCnt */
	},
	{  /* BootMngr block config */
		0UL,	/* CRC L32 Init Value */
		0UL,	/* CRC H32 Init Value */
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CRC_BootMangr_Address, /*crcPtr*/
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CRC_BootMangr_Start, /*startPtr*/
		1U, /* secnum */
		2047u, /* seclength */
		2047u, /* dmaElementCnt */
		1u /* dmaFrameCnt */
	},
	{  /* BootLoader1 block config */
		0UL,	/* CRC L32 Init Value */
		0UL,	/* CRC H32 Init Value */
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CRC_BootLoader1_Address, /*crcPtr*/
		(P2CONST(uint64, AUTOMATIC, AUTOMATIC))&_CRC_BootLoader1_Start, /*startPtr*/
		1U, /* secnum */
		16144u, /* seclength */
		4036u, /* dmaElementCnt */
		4u /* dmaFrameCnt */
	}
};


CONST(FlsTst_ConfigType, AUTOMATIC) FlsTst_Runtime = {
	5, /* numBgndBlks */
	0, /* numBgndBlks */
	FlsTst_MemBlk_Runtime, /* MemBlk */
	Appl_FlsTstCompletedNotif	/*notifFcn*/
};


#define FLSTST_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
