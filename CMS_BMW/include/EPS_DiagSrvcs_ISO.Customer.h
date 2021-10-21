/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : EPS_DiagSrvcs_ISO.Customer.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Jared Julien
*
* Notes:
* This file contains configurations for ISO services.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Thr Feb 28 09:30:12 2013
 * %version:          7 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Tue Jan 28 13:15:12 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/28/13  1        JWJ       Initial Component Release
 * 11/14/13  3		  KJS		Updated with the latest generation tool
 * 09/29/14	 5		  KJS		Updated for new service FEE5.
 * 11/04/14	 6		  KJS		Updated for new service FEE6.
 * 20/05/15	 7		  ABS		Updated for new service FEE7.
 * 03/24/15	 8		  ABS		Updated for new service FEE8.
 * 07/24/16  9      RMV   Updated for FEE4(Anomaly 6902 changes)
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_CommonData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#ifndef EPS_DIAGSRVCS_ISO_CUSTOMER_H
#define EPS_DIAGSRVCS_ISO_CUSTOMER_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_ISO.Interface.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* This is the number of Program Specific PIDs in the LUT */
#define	D_DIAGSRCVS_PROGPIDTBLSIZE_CNT_U16	9U



/****************************** BEGIN CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT ******************************/

/* PID and I/O Control Services */
#if (D_EPSDIAGSRVPIDFEE0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE0 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE0	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE0_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE1 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE1	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE1_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE2 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE2	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE2_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE3 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE3	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE3_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE4 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
	/* Define the ranges For FEE4 DID (Sec 5.4 PID FEE4 - DSR Rev 002A) */
  
  /* First byte range from 00 - 99 (0x00 - 0x63)*/	 	 
  #define D_FIRSTBYTEFEE4LOWRANGE_CNT_U08   0x00U	 	 
  #define D_FIRSTBYTEFEE4HIGHRANGE_CNT_U08  0x63U	 	 
   	 	 
  /* Second byte range from 01 - 12 (0x01 - 0x0C)*/	 	 
  #define D_SECONDBYTEFEE4LOWRANGE_CNT_U08   0x01U	 	 
  #define D_SECONDBYTEFEE4HIGHRANGE_CNT_U08  0x0CU	 	 
   	 	 
  /* Third byte range from 01 - 31 (0x01 - 0x1F)*/	 	 
  #define D_THIRDBYTEFEE4LOWRANGE_CNT_08   0x01U	 	 
  #define D_THIRDBYTEFEE4HIGHRANGE_CNT_08  0x1FU

  #else
	#define EPSInternal_PID_FEE4	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE4_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE5 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE5	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE5_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE6 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE6	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE6_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE7 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE7	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE7_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE8 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE8	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE8_CNT_ENUM == D_DIAGSRVC_ENABLED) */

/******************************* END CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT *******************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* EPS_DIAGSRVCS_ISO_H */