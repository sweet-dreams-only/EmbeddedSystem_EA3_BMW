/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : EPS_DiagSrvcs_XCP.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains configurations for the XCP services.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          1 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Fri Jun  8 18:38:39 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/06/12 	1		KS		Initial Component Release
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "EPS_DiagSrvcs_XCP.Interface.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#ifndef EPS_DIAGSRVCS_XCP_H
#define EPS_DIAGSRVCS_XCP_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* XCP User Command Valid Responses */
#define D_XCP_NOERROR				0x00U
#define D_XCP_USRCMDRESP_OK			XCP_CMD_OK
#define D_XCP_USRCMDRESP_PENDING	XCP_CMD_PENDING
#define D_XCP_USRCMDRESP_ERR		XCP_CMD_SYNTAX
#define XCP_UserCmd_RespLen_m(x) 	xcp.CrmLen = x
#define XCP_UserCmd_RespByte_m(x)	CRM_BYTE(x)

/* XCP User Command Ranges
 * Valid Ranges
 * 0x0000 - 0x01FF -> DAQ Operations
 * 0x0200 - 0xEFFF -> Reserved
 * 0xF000 - 0xFCFF -> System Commands
 * 0xFD00 - 0xFEFF -> Reserved (ISO PID Range)...XCP not supported in this range
 * 0xFF00 - 0xFFFF -> Read/Write XCP PIDs
 */
#define D_XCP_USERCMD_DAQCMD_USER			0x00
#define D_XCP_USERCMD_DAQCMD_PREDEFINED		0x01
#define D_XCP_USERCMD_SYSCMD_LOLMT			0xF0
#define D_XCP_USERCMD_SYSCMD_HILMT			0xFC
#define D_XCP_USERCMD_PIDCMD				0xFF

/* DAQ  */
#define D_XCP_DAQ_USERDEFTYPE		D_XCP_USERCMD_DAQCMD_USER
#define D_XCP_DAQ_PREDEFINEDTYPE	D_XCP_USERCMD_DAQCMD_PREDEFINED
#define D_XCP_DAQ_MAXEVENT			kXcpMaxEvent
#define D_XCP_USRDEFDAQ_BUFFLEN		(D_XCP_TL_MAXREQLEN - 4)
#define D_XCP_DAQRESP_FULLLEN		(D_XCP_TL_MAXCTO - 0x01)
#define D_XCP_USRDEFDAQ_LISTMODE	0x10 /* Enables time stamp */
#define D_XCP_USRDEFDAQ_DAQNUM		0x00
#define D_XCP_PREDEFDAQ_DAQNUM		0x00

/* Pre build DAQ PID numbers */
#define D_STATICDAQ_MANUFSRVC_MTRLEARNING 				0x0101
#define D_STATICDAQ_MANUFSRVC_TRQRATIO					0x0102
#define D_STATICDAQ_MANUFSRVC_TRQSWEEP					0x0103
#define D_STATICDAQ_MANUFSRVC_STATICEFFNLONGSWEEP		0x0104
#define D_STATICDAQ_MANUFSRVC_ROTORSTIFFNESS			0x0105
#define D_STATICDAQ_MANUFSRVC_NOISE						0x0106


/* PID */
#define D_XCP_PID_READSRV				0u
#define D_XCP_PID_WRITESRV				1u
#define D_XCP_PID_SNGLFRM_RESP			0u
#define D_XCP_PID_MULTIFRM_RESP			1u
#define D_XCP_PID_SNGLFRM_RESPLEN		4u
#define D_XCP_PID_SNGLFRM_WRITELMT		4u
#define D_XCP_PID_BYTELEN				1u
#define D_XCP_PID_WORDLEN				2u
#define D_XCP_PID_FLOATLEN				4u
#define D_XCP_PID_READRESP_BASELEN 		2u

#define XCP_PID_RESPTYPE_m(x)			CRM_BYTE(1) = x
#define XCP_PID_SINGLEFRAMELEN_m(x)		CRM_BYTE(2) = x
#define XCP_PID_MULTIFRAMELENHI_m(x)	CRM_BYTE(2) = x
#define XCP_PID_MULTIFRAMELENLO_m(x)	CRM_BYTE(3) = x
#define XCP_PID_WRITEMULTIFRMLENHI_m(x)	CRM_BYTE(1) = x
#define XCP_PID_WRITEMULTIFRMLENLO_m(x)	CRM_BYTE(2) = x
#define XCP_PID_SINGLEFRAMEDATA_m(x)	CRM_BYTE((3+x))

/* Error Codes */
#define D_XCP_ERR_INVLDSRVID		0x01
#define D_XCP_ERR_SRVIDRESRVD		0x02
#define D_XCP_ERR_INACTIVESRV		0x03
#define D_XCP_ERR_CONFIGERR			0x04
#define D_XCP_ERR_MEMALLOCERR		0x05
#define D_XCP_ERR_INVLDARG			0x06
#define D_XCP_ERR_SRVREADONLY		0x07
#define D_XCP_ERR_INVLDDAQ			0x08
#define D_XCP_ERR_NOVLDDAQPID		0x09
#define D_XCP_ERR_INVLDPREDEFDAQ	0x0A
#define D_XCP_ERR_INVLDPRESACLE		0x0B
#define D_XCP_ERR_INVLDEVENT		0x0C
#define D_XCP_ERR_UNKOWNERR			0x0D
#define D_XCP_ERR_FUNCNOTSUPP		0x0E	/* Equiv to ISO error code 0x12 */
#define D_XCP_ERR_INVLFORMAT		0x0F	/* Equiv to ISO error code 0x13 */
#define D_XCP_ERR_CONDNOTCORRECT	0x10	/* Equiv to ISO error code 0x22 */
#define D_XCP_ERR_REQOUTOFRANGE		0x11	/* Equiv to ISO error code 0x31 */


#define D_XCP_ERR_BYTEOFFSET		2
#define XCP_ERR_UpperByte_m(x)		XCP_UserCmd_RespByte_m(D_XCP_ERR_BYTEOFFSET) = x	
#define XCP_ERR_LowerByte_m(x)		XCP_UserCmd_RespByte_m((D_XCP_ERR_BYTEOFFSET + 1)) = x
#define XCP_ERR_ErrorCode_m(x)		XCP_UserCmd_RespByte_m((D_XCP_ERR_BYTEOFFSET + 2)) = x
#define XCP_ERR_Determine_m(x)		(((uint8)x > D_ZERO_CNT_U8)?(TRUE):(FALSE))
#define XCP_Error_SetRespLen_m()	XCP_UserCmd_RespLen_m(5)


/* TODO: Correct these indexes */
/* Static DAQ indexes -- The following PIDs are used in the static built DAQs */
#define D_XCP_PIDID_KEFBCKTYH			0x000A
#define D_XCP_PIDID_RFBCKTYH			0x000B
#define D_XCP_PIDID_SIN1MAXTYH			0x000C
#define D_XCP_PIDID_SIN1MINTYH			0x000D
#define D_XCP_PIDID_COS1MAXTYH			0x000E
#define D_XCP_PIDID_COS1MINTYH			0x000F
#define D_XCP_PIDID_MRFMTRTRQCMD		0x0010

#define D_XCP_PIDID_T1_ANALOG_VOLTS		0x0004
#define D_XCP_PIDID_T2_ANALOG_VOLTS		0x0006
#define D_XCP_PIDID_T1_ANALOG_CNTS		0x0003
#define D_XCP_PIDID_T2_ANALOG_CNTS		0x0005

#define D_XCP_PIDID_T1_DIGITAL_VOLTS	0x0015
#define D_XCP_PIDID_T2_DIGITAL_VOLTS	0x0017
#define D_XCP_PIDID_T1_DIGITAL_DUTY		0x0014
#define D_XCP_PIDID_T2_DIGITAL_DUTY		0x0016

#define D_XCP_PIDID_MRFCUMMTRPOS		0x0011
#define D_XCP_PIDID_ABSHWPOSSCOM		0x0008
#define D_XCP_PIDID_MRFMTRVEL			0x0012

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* Function Prototypes */

/* User XCP Services */
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) XcpUserDynamicDaqSetup( VAR(uint8, EPSDIAGSRVCS_VAR) Prescale_Uls_T_u08,
																 VAR(uint8, EPSDIAGSRVCS_VAR) Event_Cnt_T_u08,
																 P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08);

STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) XcpUserStaticDaqSetup( VAR(uint8, EPSDIAGSRVCS_VAR) Prescale_Uls_T_u08,
																 VAR(uint8, EPSDIAGSRVCS_VAR) Event_Cnt_T_u08,
																 VAR(uint8, EPSDIAGSRVCS_VAR) PreBltDaqNum_T_Cnt_u08);

STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) XcpUserRoutineCmd(VAR(uint16, EPSDIAGSRVCS_VAR) SysCmdID_Cnt_T_u16,
														P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08);

STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) XcpUserPIDSrvc(VAR(uint16, EPSDIAGSRVCS_VAR) PID_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcType_Cnt_T_u08,
														 P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08);

/* User XCP Services Supporting Functions */
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) XcpPIDReadResp(VAR(uint16, EPSDIAGSRVCS_VAR) PIDSize_Cnt_T_u16, VAR(uint32, EPSDIAGSRVCS_VAR) ReadValue_Cnt_T_u32,
														VAR(uint8, EPSDIAGSRVCS_VAR) Type_Cnt_T_u08);

STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) XcpErrorHandler(VAR(uint8, EPSDIAGSRVCS_VAR) ErrorCode_Uls_T_u08);
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) XcpODTEntrySetup(	P2CONST(uint16, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_PIDs_Uls_T_u16,
															VAR(uint16, EPSDIAGSRVCS_VAR) PIDCount_Cnt_T_u08,
															VAR(uint8, EPSDIAGSRVCS_VAR) DAQNum_Cnt_T_u08);

STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) XcpISOErrorConverter(VAR(uint8, EPSDIAGSRVCS_VAR) ErrorCode_Cnt_T_u08);

/* Static DAQ functions */
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) StaticDAQ_ManufSrvc_MtrLearning(VAR(uint16, EPSDIAGSRVCS_VAR) PIDidx_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) DAQNum_Cnt_T_u08);
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) StaticDAQ_ManufSrvc_TrqRatio(VAR(uint16, EPSDIAGSRVCS_VAR) PIDidx_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) DAQNum_Cnt_T_u08);
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) StaticDAQ_ManufSrvc_TrqSweep(VAR(uint16, EPSDIAGSRVCS_VAR) PIDidx_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) DAQNum_Cnt_T_u08);
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) StaticDAQ_ManufSrvc_StaticEffnLongSweep(VAR(uint16, EPSDIAGSRVCS_VAR) PIDidx_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) DAQNum_Cnt_T_u08);
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) StaticDAQ_ManufSrvc_RotorStiffness(VAR(uint16, EPSDIAGSRVCS_VAR) PIDidx_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) DAQNum_Cnt_T_u08);
STATIC FUNC(uint8, EPSXCPDIAGSRVCS_CODE) StaticDAQ_ManufSrvc_Noise(VAR(uint16, EPSDIAGSRVCS_VAR) PIDidx_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) DAQNum_Cnt_T_u08);

#endif /*EPS_DIAGSRVCS_XCP_H*/
