/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CDD_Const.h
* Module Description: Header file for common constant data used within Nxtr
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          11 %
* %derived_by:       xz0btk %
* %date_modified:    Wed Jan 30 11:04:35 2013 % 
*---------------------------------------------------------------------------*/

#ifndef CDD_COMST_H
#define CDD_CONST_H

#define  D_NUMADC2GRP1CONV_CNT_U16     4U
#define  D_NUMADC2GRP2CONV_CNT_U16     6U
#define  D_NUMADC2TOTCONV_CNT_U16      (D_NUMADC2GRP1CONV_CNT_U16 + D_NUMADC2GRP1CONV_CNT_U16)

#define  D_MTRISRVIMIDX_CNT_u16        2U /* Indicates location of Cross Check ISR bit in VIM Register */

#define  D_APPCDDBFRSIZE_CNT_U16       2U

#define  D_MAXDTCSTORAGE_CNT_U16	   15U

#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
12/07/10   1        JJW      Initial Creation
12/20/10   5        LWW      Added Shcurr channel macro
01/13/11   6        OSteen   Added D_MAXDTCSTORAGE_CNT_U16
02/08/11   7        LWW      Added PHSREAS constants
04/13/11   9        JJW      Added D_CROSSCHKVIMIDX_CNT_U16
09/19/11  10        JJW      Removed D_CROSSCHKVIMIDX_CNT_U16
******************************************************************************/
