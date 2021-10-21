/**************************************************************************//**
 * \file
 * Definition of UDS/AUTOSAR DCM specific adapter for diagnostic requests to SWT lib.
 *
 * \target All
 * \project SWT
 * \author BMW AG
 * \userchange No
 *****************************************************************************/

/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Aug 18 20:09:21 2012
* %version:          2 %
* %derived_by:       wz7x3j %
* %date_modified:    Sat Sep 29 12:37:14 2012 %
*---------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 09/29/12   2        BDO         SWT updates - anomaly 3782
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Swt_Cfg.h"

/* sources only active for UDS diagnostics */
#if	(SWT_DIAG_USE_UDS == SWT_CFG_ON)

#include "Swt_Version.h"
#include "Swt_Appl.h"
#include "Swt_Common.h"
#include "Swt_Dcm.h"
#include "Swt_FSC.h"
#include "Swt_Handler.h"
#include "Appl_Swt.h"
//#include "diag.h"  /* NXTR SWT - added include to Swt_Dcm.h */

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
#include "Swt_Full.h"
#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/** \name SWT routine control options */
/*@{*/
/** SWTGetSwidFunctional */
#define SWT_RCO_GSIDF				0x01u
/** GetSigSID          */
#define SWT_RCO_GSID				0x03u
/** SWTGetStatus       */
#define SWT_RCO_GFSS				0x04u
/** SWTCheckCert       */
#define SWT_RCO_CCERT				0x05u
/** SWTGetCert         */
#define SWT_RCO_GCERT				0x06u
/** SWTStoreFSC        */
#define SWT_RCO_SFSC				0x07u
/** SWTStoreCert       */
#define SWT_RCO_SCERT				0x08u
/** SWTCheckFSC        */
#define SWT_RCO_CFSC				0x09u
/** SWTDisableFSC      */
#define SWT_RCO_DFSC				0x0Au
/** SWTGetFSC          */
#define SWT_RCO_GFSC				0x0Bu
/** SWTPeriodicalCheck */
#define SWT_RCO_PCHECK				0x0Cu
/** SWTGetKeyFactor    */
#define SWT_RCO_GKF					0x0Du
/** SWTGetVersion    */
#define SWT_RCO_GVER					0x0Eu

/*@}*/

/** Number of dispatched routine control jobs. */
#define SWT_NUM_RCOS				(sizeof( Swt_RoutineControlDescriptorTable ) / sizeof( Swt_RoutineControlDescriptorType ))

/** Number of bytes per SGID. */
#define SWT_SGID_LEN				1u

/** Number of bytes per certificate type. */
#define SWT_CERT_TYPE_LEN			1u

/** Number of bytes before routine control response data starts in telegram (without service ID). */
#define SWT_RCRES_HEADER_LEN		5u

/** Number of bytes before routine control request data starts in telegram (without service ID). */
#define SWT_RCREQ_HEADER_LEN		4u

/** Number of bytes before write data by identifier request data starts in telegram (without service ID). */
#define SWT_WDBI_REQ_HEADER_LEN		2u

/** Number of bytes returned by Swt_GetStatus() for general status (root CA certificate status, SigS certificate status, SW signature status). */
#define SWT_GFSS_STATUS_SKIP		(1u + 1u + 1u)

/** Number of bytes returned by Swt_GetStatus() for each SWID (SWID, FSCS certificate status, FSC status, FSC type. */
#define SWT_GFSS_ENTRY_LEN			(4u + 1u + 1u + 1u)

/** Number of bytes returned by Swt_GetVersion() */
#define SWT_GVER_LEN     17u

/** Bit flag for Swt_RoutineControlDescriptorType::Flags: job requires an active SWT session. */
#define SWT_RCFLAG_REQUIRES_SWT_SESSION   0x01u

/** Bit flag for Swt_RoutineControlDescriptorType::Flags: job requires security access (authentication). */
#define SWT_RCFLAG_REQUIRES_SECURE_ACCESS	0x02u

/** Bit flag for Swt_RoutineControlDescriptorType::Flags: job requires security access partly (StoreFSC in case of FULL/LIGHT or SHORT)(authentication). */
#define SWT_RCFLAG_REQUIRES_PARTLY_SECURE_ACCESS	0x04u

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"

/** Calls SWT library function Swt_GetVersion() and maps result to diagnostic response. */
static SwtRC_t Swt_DcmGetVersion( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_GetStatus() and maps result to diagnostic response. */
static SwtRC_t Swt_DcmGetStatus( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_GetSWID() and maps result to diagnostic response. */
static SwtRC_t Swt_DcmGetSwids( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_StoreFSC() and maps result to diagnostic message. */
static SwtRC_t Swt_DcmStoreFsc( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_CheckFSC() and maps result to diagnostic message. */
static SwtRC_t Swt_DcmCheckFsc( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_DisableFSC() and maps result to diagnostic message. */
static SwtRC_t Swt_DcmDisableFsc( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_GetFSC() and maps result to diagnostic message. */
static SwtRC_t Swt_DcmGetFsc( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Class SWT library function Swt_PeriodicalChecks() and maps result to diagnostic message. */
static SwtRC_t Swt_DcmPeriodicalChecks( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

/** Calls SWT library function Swt_CheckCert() and maps result to diagnostic response. */
static SwtRC_t Swt_DcmCheckCert( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_GetCert() and maps result to diagnostic response. */
static SwtRC_t Swt_DcmGetCert( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_StoreCert() and maps result to diagnostic response. */
static SwtRC_t Swt_DcmStoreCert( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       External Constants                                   **
*******************************************************************************/


/*******************************************************************************
**                       External Data                                        **
*******************************************************************************/


/*******************************************************************************
**                       Local Data Types                                     **
*******************************************************************************/
/** Type of entry in routine control dispatcher table. */
typedef struct
{
	/** Routine control option for this job. */
	uint8 RcOption;
	/** Flags for this jobs, e.g. #SWT_RCFLAG_REQUIRES_SWT_SESSION. */
	uint8 Flags;
	/** Minimal request buffer size of job. */
	uint16 MinReqLen;
	/** Local function implementing this job. */
	CONSTP2FUNC(SwtRC_t,SC_FAR,Func)( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );
} Swt_RoutineControlDescriptorType;


/*******************************************************************************
**                       Local Constants                                      **
*******************************************************************************/
#define SWT_START_SEC_CONST_UNSPEC
#include "MemMap.h"

/** Constant jump table keeping information about different diagnostic jobs. */
static const Swt_RoutineControlDescriptorType Swt_RoutineControlDescriptorTable[] =
{
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
	{
		/* routine control option */ SWT_RCO_CCERT,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION | SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_SWID_LEN,
		/* function               */ Swt_DcmCheckCert
	},
	{
		/* routine control option */ SWT_RCO_GCERT,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_SWID_LEN,
		/* function               */ Swt_DcmGetCert
	},
	{
		/* routine control option */ SWT_RCO_SCERT,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION | SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_SWID_LEN + SWT_CERT_MIN_LEN,
		/* function               */ Swt_DcmStoreCert
	},
#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */
#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
	{
		/* routine control option */ SWT_RCO_GKF,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ 0
	},
#endif /* #if (SWT_USE_SWT_SHORT == SWT_CFG_ON) */
	{
		/* routine control option */ SWT_RCO_GSIDF,
		/* flags                  */ 0,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ Swt_DcmGetSwids
	},
	{
		/* routine control option */ SWT_RCO_GSID,
		/* flags                  */ SWT_RCFLAG_REQUIRES_SWT_SESSION,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN,
		/* function               */ 0
	},
	{
		/* routine control option */ SWT_RCO_GFSS,
		/* flags                  */ SWT_RCFLAG_REQUIRES_SWT_SESSION,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ Swt_DcmGetStatus
	},
	{
		/* routine control option */ SWT_RCO_SFSC,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION | SWT_RCFLAG_REQUIRES_PARTLY_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN + SWT_FSC_SHORT_LEN /*SWT_FSC_MIN_LEN*/,
		/* function               */ Swt_DcmStoreFsc
	},
	{
		/* routine control option */ SWT_RCO_CFSC,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION | SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN,
		/* function               */ Swt_DcmCheckFsc
	},
	{
		/* routine control option */ SWT_RCO_DFSC,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION | SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN,
		/* function               */ Swt_DcmDisableFsc
	},
	{
		/* routine control option */ SWT_RCO_GFSC,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN,
		/* function               */ Swt_DcmGetFsc
	},
	{
		/* routine control option */ SWT_RCO_PCHECK,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ Swt_DcmPeriodicalChecks
	},
  	{
		/* routine control option */ SWT_RCO_GVER,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SWT_SESSION,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ Swt_DcmGetVersion
	}

};

#define SWT_STOP_SEC_CONST_UNSPEC
#include "MemMap.h"

/*******************************************************************************
**                       Local Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"

///* NXTR SWT */ - CDCSWT Dcm_StatusType Swt_DcmGetSessionStartPermission( uint8 Sgid )
Dcm_StatusType Swt_DcmGetSessionStartPermission()
{
	/* currently, no additional constraints apply */
	return DCM_E_OK;
}

/******************************************************************************/
void Swt_DcmRoutineControlSwtOperation( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* index of requested routine in descriptor array */
	uint8 jobIndex;
	P2CONST(Swt_RoutineControlDescriptorType,AUTOMATIC,SC_FAR) pJobDesc = 0;

	/* routine control option of requested SWT job */
	const uint8 rcOption = pMsgContext->reqData[3];

	///* NXTR SWT */ - CDCSWT
	Dcm_SesCtrlType SesCtrlType;


#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
	/* make sure the correct routine control function is passed */
	if( DIAG_UDS31_01_START_ROUTINE != pMsgContext->reqData[0]	||
		(SWT_RCID_SWT_ROUTINE >> 8) != pMsgContext->reqData[1] ||
		(SWT_RCID_SWT_ROUTINE & 0xFF) != pMsgContext->reqData[2] )
	{
		Det_ReportError( SWT_DET_MODULE_ID, (uint8)SWT_DCM_HANDLER_RC_SWT_API_ID, (uint8)Swt_RC_BAD_PARAM );
		Dcm_SetNegResponse( pMsgContext, DCM_NRC_REQUESTOUTOFRANGE );
		return;
	}
#endif /* #if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

	/* identify job descriptor of requested routine */
   for( jobIndex = 0; jobIndex < SWT_NUM_RCOS; jobIndex++ )
	{
		if( Swt_RoutineControlDescriptorTable[jobIndex].RcOption == rcOption )
		{
			/* routine found */
			pJobDesc = &Swt_RoutineControlDescriptorTable[jobIndex];
			break;
		}
	}

	if( 0 == pJobDesc )
	{
		/* requested routine is not supported */
		Dcm_SetNegResponse( pMsgContext, DCM_NRC_SUBFUNCTIONNOTSUPPORTED );
	}

	/* check whether diagnostic SWT session is required */
	if( 0 != pJobDesc )
	{
		if( 0 != (pJobDesc->Flags & SWT_RCFLAG_REQUIRES_SWT_SESSION) )
		{
			/* routine requires active SWT session */
			Dcm_GetSesCtrlType(&SesCtrlType);	///* NXTR SWT */ - CDCSWT  Dcm_GetSesCtrlType() )
			if( DCM_SES_LEV_SWT != SesCtrlType)
			{
				Dcm_SetNegResponse( pMsgContext, DCM_NRC_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION );
				pJobDesc = 0;
			}
		}
	}

	/* check whether authentication is required */
	if( 0 != pJobDesc )
	{      
		if( 0 != (pJobDesc->Flags & SWT_RCFLAG_REQUIRES_SECURE_ACCESS) )
		{
			/* routine requires SWT security access */
			if( DCM_SEC_LEV_SWTACCESS != Dcm_GetSecurityLevel() )
			{
				Dcm_SetNegResponse( pMsgContext, DCM_NRC_SECURITYACCESSDENIED );
				pJobDesc = 0;
			}
		}            
	}

	if( 0 != pJobDesc )
	{
		/* prepare positive response message */
		Swt_CommonCopy( pMsgContext->resData, pMsgContext->reqData, SWT_RCREQ_HEADER_LEN );

		/* check request buffer size (response buffer is checked in sub function if required) */
		if( pMsgContext->reqDataLen < pJobDesc->MinReqLen )
		{
			/* request data is corrupt or incomplete */
			pMsgContext->resData[4] = Swt_RC_BAD_PARAM;
			pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
			pJobDesc = 0;
		}
	}

	/* dispatch SWT function */
	if( 0 != pJobDesc )
	{
		if( 0 != pJobDesc->Func )
		{
			pMsgContext->resData[4] = pJobDesc->Func( Sgid, pMsgContext );
		}
		else
		{
			/* this function is not supported as this point */
			Dcm_SetNegResponse( pMsgContext, DCM_NRC_SUBFUNCTIONNOTSUPPORTED );
		}
	}
}

/******************************************************************************/
void Swt_DcmWriteDataByIdentifierVin( CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
    /* counter variable for checking VIN data */
    uint8_least i;

	///* NXTR SWT */ - CDCSWT
    Dcm_SesCtrlType  SesCtrlType;
 
	/* must be fully authenticated */
	if( DCM_SEC_LEV_SWTACCESS != Dcm_GetSecurityLevel() )
	{
		Dcm_SetNegResponse( pMsgContext, DCM_NRC_SECURITYACCESSDENIED );
		return;
	}

	Dcm_GetSesCtrlType(&SesCtrlType);

	if( DCM_SES_LEV_SWT != SesCtrlType)
	{
		Dcm_SetNegResponse( pMsgContext, DCM_NRC_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION );
		return;
	}

	/* check incoming data size */
	if( (SWT_WDBI_REQ_HEADER_LEN + SWT_INDIV_LONG_VIN_LEN) > pMsgContext->reqDataLen )
	{
		/* buffer to small */
		Dcm_SetNegResponse( pMsgContext, DCM_NRC_CONDITIONSNOTCORRECT );
		return;
	}

    /* check values of VIN: only 'A' to 'Z' and '0' to '9' is valid */
    for( i = (uint8_least)0u; i < SWT_INDIV_LONG_VIN_LEN; i++ )
    {
        const uint8 value = pMsgContext->reqData[i + SWT_WDBI_REQ_HEADER_LEN];
        if( !(((value >= 'A') && (value <= 'Z')) || ((value >= '0') && (value <= '9'))) )
        {
            // found wrong value:
            Dcm_SetNegResponse( pMsgContext, DCM_NRC_REQUESTOUTOFRANGE );
            return;
        }
    }
    
	/* store VIN */
	if( Swt_RC_OK != Appl_SwtSetVinInternal( &pMsgContext->reqData[SWT_WDBI_REQ_HEADER_LEN] ) )
	{
		/* VIN could not be written */
		Dcm_SetNegResponse( pMsgContext, DCM_NRC_CONDITIONSNOTCORRECT );
	}
	else
	{
		/* get positive response ready */
		pMsgContext->resData[0] = pMsgContext->reqData[0];
		pMsgContext->resData[1] = pMsgContext->reqData[1];
		pMsgContext->resDataLen = 2;
	}
}

/******************************************************************************/
#if (SWT_USE_ECU_SWTLIST == SWT_CFG_ON)
void Swt_DcmReadDataByIdentifierReadEcuSwtList( CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	///* NXTR SWT */ - CDCSWT
	Dcm_SesCtrlType SesCtrlType;

	/* must be in SWT session */
	if( DCM_SES_LEV_SWT != Dcm_GetSesCtrlType(&SesCtrlType) )  ///* NXTR SWT */ - CDCSWT  Dcm_GetSesCtrlType() )
	{
		Dcm_SetNegResponse( pMsgContext, DCM_NRC_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION );
		return;
	}

	/* TODO: by user, for now just reject */
	Dcm_SetNegResponse( pMsgContext, DCM_NRC_SUBFUNCTIONNOTSUPPORTED );
}
#endif /* (SWT_USE_ECU_SWTLIST == SWT_CFG_ON) */

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

static SwtRC_t Swt_DcmGetStatus( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* call SWT library operation */
	ret = Swt_GetStatus( Sgid,
						   pMsgContext->resMaxDataLen - SWT_RCRES_HEADER_LEN,
						   &pMsgContext->resData[SWT_RCRES_HEADER_LEN] );

	if( Swt_RC_OK == ret )
	{
		/* re-arrange data (API layout currently does not match diagnostic layout) */
		uint8 numSwids = pMsgContext->resData[SWT_RCRES_HEADER_LEN + 3];
		if( numSwids > 0 )
		{
			Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + 3],
							  &pMsgContext->resData[SWT_RCRES_HEADER_LEN + 4],
							  numSwids * SWT_GFSS_ENTRY_LEN );
		}

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
		/* For SWT full storage of SigS certificates in SWT lib is not part of process, but the
		   certificate state is still requested to be accepted. This is a process quirks, but we
		   have to support it here.
		   So in case of SWT full, map a non-existent SigS certificate to accepted. */
		if( Swt_STATE_CERT_NOT_EXISTENT == pMsgContext->resData[SWT_RCRES_HEADER_LEN + 1] )
		{
			pMsgContext->resData[SWT_RCRES_HEADER_LEN + 1] = Swt_STATE_CERT_ACCEPTED;
		}
#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_GFSS_STATUS_SKIP + (numSwids * SWT_GFSS_ENTRY_LEN);
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_DcmGetSwids( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* call SWT library operation */    
   /* ChR: Swt_GetSWIDFunctional would be more correct but at the moment it is not sure whether there */
   /* it is needed to search for different SGIDs in one ECU and also the to be reported phy. address is not clear */
	ret = Swt_GetSWID ( Sgid,
					   pMsgContext->resMaxDataLen - SWT_RCRES_HEADER_LEN,
					   &pMsgContext->resData[SWT_RCRES_HEADER_LEN] );

	if( Swt_RC_OK == ret )
	{
		/* re-arrange data (API layout currently does not match diagnostic layout) */
		/* replace number of SWIDs (unwanted) with SGID (missing) */
		uint8 numSwids = pMsgContext->resData[SWT_RCRES_HEADER_LEN];
		pMsgContext->resData[SWT_RCRES_HEADER_LEN] = Sgid;
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_SGID_LEN + (numSwids * SWT_SWID_LEN);
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_DcmCheckFsc( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	return Swt_CheckFSC( Sgid, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN], TRUE );
}

/******************************************************************************/
static SwtRC_t Swt_DcmDisableFsc( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;

	/* call SWT library operation */
	return Swt_DisableFSC( Sgid, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN] );
}

/******************************************************************************/
static SwtRC_t Swt_DcmStoreFsc( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret = Swt_RC_OK;
   boolean isShort = FALSE;

	/* incoming request data (request buffer length was checked in calling operation) */
	P2CONST(uint8,AUTOMATIC,SC_FAR) pFsc = &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN];
	P2CONST(uint8,AUTOMATIC,SC_FAR) pSwid = &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN];
	uint16 fscLen = pMsgContext->reqDataLen - (SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN);
   
   uint16 swidPos = 0;

   /* Check for needed authentification */
   /* Only for FSCfull and FSClight we need secure access */
   /* check the length of the given FSC */ 
#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
   if (SWT_FSC_SHORT_LEN < fscLen)
   {
#endif
	   /* check length in case of FSC classic*/
      if( pMsgContext->reqDataLen < (SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN + SWT_FSC_MIN_LEN))
      {
         /* request data is corrupt or incomplete */
		   pMsgContext->resData[4] = Swt_RC_BAD_PARAM;
		   pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
      }
      isShort = FALSE;

      /* routine requires SWT security access */
     if( DCM_SEC_LEV_SWTACCESS != Dcm_GetSecurityLevel() )
     {
	    Dcm_SetNegResponse( pMsgContext, DCM_NRC_SECURITYACCESSDENIED );
        ret = Swt_RC_NOT_AUTHENTICATED;
		}
#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)   
   }
   else
   {
	   /* check length in case of FSC short*/
      if( pMsgContext->reqDataLen != (SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN + SWT_FSC_SHORT_LEN))
      {
         /* request data is corrupt or incomplete */
		   pMsgContext->resData[4] = Swt_RC_BAD_PARAM;
		   pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
         ret = Swt_RC_BAD_PARAM;
      }
      isShort = TRUE;
   }
#endif   
	//compare SWID applicaiton number from request and the one in FSC
	
   if( Swt_RC_OK == ret )
   {
#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
      if (FALSE == isShort)   
#endif //NXTR SWT PATCH - moved #endif here was on the wrong line in original file according to BMW
      {
//NXTR SWT PATCH BMW expert Bjoern confirmed that this should have been on line 644: #endif
         ret = Swt_GetPos( pFsc, fscLen, Swt_FSC_SWID, &swidPos );
      }
#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
      else
      {         
         swidPos = SWT_SWID_SHORT_POSITION;
      }
#endif
    }//NXTR SWT PATCH the brace is OK, it was the #endif that was on the wrong line according to BMW, functionally the same.
    
	if( Swt_RC_OK == ret )
	{
		if( Swt_RC_EQUAL != Swt_CommonCompare( &pFsc[swidPos], pSwid, SWT_APP_NUMBER_LEN /*SWT_SWID_LEN*/ ) )
		{
			ret = Swt_RC_SW_NOT_EXISTENT; //Swt_RC_BAD_PARAM
		}
	}
   
	/* call SWT library operation */
	if( Swt_RC_OK == ret )
	{
		ret = Swt_StoreFSC( Sgid,
                       &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN],                        //SwIdDiag
							  &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN],         //FSC
							  pMsgContext->reqDataLen - (SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN) );  //FSCLength
	}

	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_DcmGetFsc( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* retrieved FSC data and length */
	P2CONST(uint8,AUTOMATIC,SC_FAR) pFsc;
	uint16 fscLen;

	/* call SWT library operation */
	ret = Swt_GetFSC( Sgid,
					  &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN],
					  &pFsc,
					  &fscLen );

	/* check output buffer size */
	if( Swt_RC_OK == ret )
	{
		if( SWT_RCRES_HEADER_LEN + fscLen > pMsgContext->resMaxDataLen )
		{
			/* buffer too small */
			ret = Swt_RC_BAD_PARAM;
		}
	}

	if( Swt_RC_OK == ret )
	{
		/* copy fsc to result buffer */
		Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], pFsc, fscLen );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + fscLen;
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_DcmPeriodicalChecks( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* optional SWID to check */
	P2CONST(uint8,AUTOMATIC,SC_FAR) pSwid;

	/* if request contains SWID, use it */
	if( pMsgContext->reqDataLen >= (SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN) )
	{
		/* buffer contains SWID */
		pSwid = &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN];
	}
	else
	{
		/* buffer does not contain SWID */
		pSwid = 0;
	}

	/* call SWT library operation */
	ret = Swt_PeriodicalChecks( Sgid, pSwid );

	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;

	return ret;
}

/******************************************************************************/
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

static SwtRC_t Swt_DcmCheckCert( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	return Swt_CheckCert( Sgid,
						  /* SWID */
						  &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN],
						  /* certificate type */
						  pMsgContext->reqData[SWT_RCREQ_HEADER_LEN],
                    TRUE);
}

/******************************************************************************/
static SwtRC_t Swt_DcmGetCert( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* retrieved certificate data and length */
	P2CONST(uint8,AUTOMATIC,SC_FAR) pCert;
	uint16 certLen;

	/* call SWT library operation */
	ret = Swt_GetCert( Sgid,
						&pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN],	/* SWID */
						pMsgContext->reqData[SWT_RCREQ_HEADER_LEN],							/* Certificate type */
						&pCert,
						&certLen );

	/* check output buffer size */
	if( Swt_RC_OK == ret )
	{
		if( SWT_RCRES_HEADER_LEN + certLen > pMsgContext->resMaxDataLen )
		{
			/* buffer too small */
			ret = Swt_RC_BAD_PARAM;
		}
	}

	if( Swt_RC_OK == ret )
	{
		/* copy certificate to result buffer */
		Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], pCert, certLen );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + certLen;
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_DcmStoreCert( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	return Swt_StoreCert( Sgid,
						  /* SWID */
						  &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN],
						  /* certificate type */
						  pMsgContext->reqData[SWT_RCREQ_HEADER_LEN],
						  /* certificate length */
						  pMsgContext->reqDataLen - (SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_SWID_LEN),
						  /* certificate data */
						  &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_SWID_LEN] );
}

#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

/******************************************************************************/
static SwtRC_t Swt_DcmGetVersion( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext )
{
      /* return code */
	SwtRC_t ret;

 	/* retrieved version data and length */
	uint8 pVersion[SWT_GVER_LEN];
	uint16 versionLen = SWT_GVER_LEN;

   ret = Swt_GetVersion(Sgid, pVersion, &versionLen);
   
   /* check output buffer size */
	if( Swt_RC_OK == ret )
	{
		if(( SWT_RCRES_HEADER_LEN + SWT_GVER_LEN > pMsgContext->resMaxDataLen )
       ||( SWT_GVER_LEN != versionLen))
		{
			/* buffer too small */
			ret = Swt_RC_BAD_PARAM;
		}
	}

	if( Swt_RC_OK == ret )
	{
		/* copy certificate to result buffer */
		Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], pVersion, versionLen );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + versionLen;
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

   return ret;
}

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if (SWT_DIAG_USE_UDS == SWT_CFG_ON) */

/*** End of file **************************************************************/
