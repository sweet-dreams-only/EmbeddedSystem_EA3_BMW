/**************************************************************************//**
 * \file
 * Definition of KWP 2000 specific adapter for diagnostic requests to SWT lib.
 *
 * \target All
 * \project SWT
 * \author BMW AG
 * \userchange No
 *****************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Swt_Cfg.h"

/* sources only active for KWP2000 diagnostics */
#if	(SWT_DIAG_USE_KWP2000 == SWT_CFG_ON)

#include "Appl_Swt.h"
#include "Swt_Appl.h"
#include "Swt_Common.h"
#include "Swt_Kwp2000.h"
#include "Swt_Fsc.h"
#include "Swt_Handler.h"
#include "Swt_SWData.h"

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
#include "Swt_Certificate.h"
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

/** Maximal length of KWP2000 message excluding service identifier. */
#define SWT_KWP2000_MAX_MSG_LEN		254u

/** \name SWT routine control options */
/*@{*/
/** SWTGetSwidFunctional */
#define SWT_RCO_GSWIDF				0xF9u
/** SWTGetSwid         */
#define SWT_RCO_GSWID				0xF8u
/** SWTGetStatus       */
#define SWT_RCO_GFSS				0xF6u
/** SWTCheckCert       */
#define SWT_RCO_CCERT				0xF5u
/** SWTGetCertLength   */
#define SWT_RCO_GCERTL				0xF4u
/** SWTGetCert         */
#define SWT_RCO_GCERT				0xF3u
/** SWTSetFSCLength    */
#define SWT_RCO_SFSCL				0xF2u
/** SWTStoreFSC        */
#define SWT_RCO_SFSC				0xF1u
/** SWTSetCertLength   */
#define SWT_RCO_SCERTL				0xF0u
/** SWTStoreCert       */
#define SWT_RCO_SCERT				0xEFu
/** SWTCheckFSC        */
#define SWT_RCO_CFSC				0xEEu
/** SWTDisableFSC      */
#define SWT_RCO_DFSC				0xEDu
/** SWTGetFSCLength    */
#define SWT_RCO_GFSCL				0xECu
/** SWTGetFSC          */
#define SWT_RCO_GFSC				0xEBu
/** SWTPeriodicalCheck */
#define SWT_RCO_PCHECK				0xEAu
/** SWTGetFZG          */
#define SWT_RCO_GVIN				0xE6u
/** SWTSetFZG          */
#define SWT_RCO_SVIN				0xE5u
/*@}*/

/** Number of dispatched routine control jobs. */
#define SWT_NUM_RCOS				(sizeof( Swt_RoutineControlDescriptorTable ) / sizeof( Swt_RoutineControlDescriptorType ))

/** Number of bytes before routine control response data starts in telegram (without service ID). */
#define SWT_RCRES_HEADER_LEN		3u

/** Number of bytes before routine control request data starts in telegram (without service ID). */
#define SWT_RCREQ_HEADER_LEN		2u

/** Bit flag for Swt_RoutineControlDescriptorType::Flags: job requires security access (authentication). */
#define SWT_RCFLAG_REQUIRES_SECURE_ACCESS	0x02u

/** Bit flag for Swt_RoutineControlDescriptorType::Flags: job requires long TP. */
#define SWT_RCFLAG_REQUIRES_LONG_TP			0x04u

/** Number of bytes for running index used in long TP. */#
#define SWT_LTP_INDEX_LEN			1u

/** Number of bytes for LTP call id. */
#define SWT_LTP_CALL_ID_LEN			2u

/** Size of long TP buffer, depending on type of SWT being used. */
#if ((SWT_USE_SWT_FULL == SWT_CFG_ON) && (SWT_CERT_MAX_LEN > SWT_FSC_MAX_LEN))
	#define SWT_LTP_BUFFER_LEN SWT_CERT_MAX_LEN
#else
	#define SWT_LTP_BUFFER_LEN SWT_FSC_MAX_LEN
#endif

/** Number of bytes per SGID. */
#define SWT_SGID_LEN				1u

/** Number of bytes per certificate type. */
#define SWT_CERT_TYPE_LEN			1u

/** Number of bytes per certificate length. */
#define SWT_CERT_LEN_LEN			2u

/** Number of bytes per FSC length. */
#define SWT_FSC_LEN_LEN				2u

/** Number of bytes per MXBL. */
#define SWT_MXBL_LEN				2u

/** Number of bytes per call id. */
#define SWT_CALLID_LEN				2u

/** Number of bytes returned by Swt_GetStatus() for general status (root CA certificate status, SigS certificate status, SW signature status). */
#define SWT_GFSS_STATUS_SKIP		(1u + 1u + 1u)

/** Number of bytes returned by Swt_GetStatus() for each SWID (SWID, FSCS certificate status, FSC status. */
#define SWT_GFSS_ENTRY_LEN			(4u + 1u + 1u)

/** Maximal number of bytes in KWP2000 message. */
#define SWT_KWP_MAX_MSG_LEN			255u

/** Maximal number of bytes for payload (without service id) in KWP2000 message. */
#define SWT_KWP_MAX_PAYLOAD_LEN		((uint8)(SWT_KWP_MAX_MSG_LEN - 1u))

/** Maximal received LTP block length. */
#define SWT_LTP_MXBL_TPREQ			((uint8)(SWT_KWP_MAX_PAYLOAD_LEN - SWT_RCREQ_HEADER_LEN - SWT_LTP_INDEX_LEN - SWT_CALLID_LEN))

/** Maximal sent LTP block length. */
#define SWT_LTP_MXBL_TPRES			((uint8)(SWT_KWP_MAX_PAYLOAD_LEN - SWT_RCRES_HEADER_LEN - SWT_LTP_INDEX_LEN))

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

/** Resets long TP statemachine attributes. */
static void Swt_KwpResetLtpStatemachine( uint8 Sgid );

/** Helper function writing 16 bit constant to uint 8 array, MSB first. */
static void Swt_KwpSetUint16( CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) pBuf, const uint16 Val );

/** Calls SWT library function Swt_GetStatus() and maps result to diagnostic response. */
static SwtRC_t Swt_KwpGetStatus( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_GetSWID() and maps result to diagnostic response. */
static SwtRC_t Swt_KwpGetSwidsFunctional( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_GetSWID() and maps result to diagnostic response. */
static SwtRC_t Swt_KwpGetSwids( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Starts long TP stream for job SFSC. */
static SwtRC_t Swt_KwpStoreFscLength( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_StoreFSC() and maps result to diagnostic message. */
static SwtRC_t Swt_KwpStoreFsc( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_CheckFSC() and maps result to diagnostic message. */
static SwtRC_t Swt_KwpCheckFsc( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_DisableFSC() and maps result to diagnostic message. */
static SwtRC_t Swt_KwpDisableFsc( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Starts long TP stream for job GFSC. */
static SwtRC_t Swt_KwpGetFscLength( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_GetFSC() and maps result to diagnostic message. */
static SwtRC_t Swt_KwpGetFsc( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Class SWT library function Swt_PeriodicalChecks() and maps result to diagnostic message. */
static SwtRC_t Swt_KwpPeriodicalChecks( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

/** Calls SWT library function Swt_CheckCert() and maps result to diagnostic response. */
static SwtRC_t Swt_KwpCheckCert( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Starts long TP stream for job GCERT. */
static SwtRC_t Swt_KwpGetCertLength( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR)pMsgContext );

/** Calls SWT library function Swt_GetCert() and maps result to diagnostic response. */
static SwtRC_t Swt_KwpGetCert( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Starts long TP stream for job SCERT. */
static SwtRC_t Swt_KwpStoreCertLength( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Calls SWT library function Swt_StoreCert() and maps result to diagnostic response. */
static SwtRC_t Swt_KwpStoreCert( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

/** Returns internal VIN to tester. */
static SwtRC_t Swt_KwpGetVin( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/** Stores internal VIN received from tester. */
static SwtRC_t Swt_KwpSetVin( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

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
	/** Flags for this jobs, e.g. #SWT_RCFLAG_REQUIRES_SECURE_ACCESS. */
	uint8 Flags;
	/** Minimal request buffer size of job. */
	uint16 MinReqLen;
	/** Local function implementing this job. */
	CONSTP2FUNC(SwtRC_t,SC_FAR,Func)( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );
} Swt_RoutineControlDescriptorType;

/** States used by long TP state machine. */
typedef uint8 Swt_LtpStateType;

/** State machine is currently not processing a data stream. */
#define SWT_LTP_STATE_IDLE				((Swt_LtpStateType) 0x00u)
/** State machine is waiting for next chunk request while processing a data stream. */
#define SWT_LTP_STATE_AWAITING_NEXT		((Swt_LtpStateType) 0x01u)


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
		/* flags	              */ SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_SWID_LEN,
		/* function               */ Swt_KwpCheckCert
	},
	{
		/* routine control option */ SWT_RCO_GCERTL,
		/* flags	              */ 0,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_SWID_LEN,
		/* function               */ Swt_KwpGetCertLength
	},
	{
		/* routine control option */ SWT_RCO_GCERT,
		/* flags	              */ SWT_RCFLAG_REQUIRES_LONG_TP,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_LTP_INDEX_LEN + SWT_LTP_CALL_ID_LEN,
		/* function               */ Swt_KwpGetCert
	},
	{
		/* routine control option */ SWT_RCO_SCERTL,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_CERT_LEN_LEN + SWT_SWID_LEN,
		/* function               */ Swt_KwpStoreCertLength
	},
	{
		/* routine control option */ SWT_RCO_SCERT,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SECURE_ACCESS | SWT_RCFLAG_REQUIRES_LONG_TP,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_LTP_INDEX_LEN + SWT_LTP_CALL_ID_LEN,
		/* function               */ Swt_KwpStoreCert
	},
#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */
	{
		/* routine control option */ SWT_RCO_GSWIDF,
		/* flags                  */ 0,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ Swt_KwpGetSwidsFunctional
	},
	{
		/* routine control option */ SWT_RCO_GSWID,
		/* flags                  */ 0,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ Swt_KwpGetSwids
	},
	{
		/* routine control option */ SWT_RCO_GFSS,
		/* flags                  */ 0,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ Swt_KwpGetStatus
	},
	{
		/* routine control option */ SWT_RCO_SFSCL,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN + SWT_FSC_LEN_LEN,
		/* function               */ Swt_KwpStoreFscLength
	},
	{
		/* routine control option */ SWT_RCO_SFSC,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SECURE_ACCESS | SWT_RCFLAG_REQUIRES_LONG_TP,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_LTP_INDEX_LEN + SWT_LTP_CALL_ID_LEN,
		/* function               */ Swt_KwpStoreFsc
	},
	{
		/* routine control option */ SWT_RCO_CFSC,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN,
		/* function               */ Swt_KwpCheckFsc
	},
	{
		/* routine control option */ SWT_RCO_DFSC,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN,
		/* function               */ Swt_KwpDisableFsc
	},
	{
		/* routine control option */ SWT_RCO_GFSCL,
		/* flags	              */ 0,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN,
		/* function               */ Swt_KwpGetFscLength
	},
	{
		/* routine control option */ SWT_RCO_GFSC,
		/* flags	              */ SWT_RCFLAG_REQUIRES_LONG_TP,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_LTP_INDEX_LEN + SWT_LTP_CALL_ID_LEN,
		/* function               */ Swt_KwpGetFsc
	},
	{
		/* routine control option */ SWT_RCO_PCHECK,
		/* flags	              */ 0,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN,
		/* function               */ Swt_KwpPeriodicalChecks
	},
	{
		/* routine control option */ SWT_RCO_GVIN,
		/* flags	              */ 0,
		/* min request length     */ SWT_RCREQ_HEADER_LEN,
		/* function               */ Swt_KwpGetVin
	},
	{
		/* routine control option */ SWT_RCO_SVIN,
		/* flags	              */ SWT_RCFLAG_REQUIRES_SECURE_ACCESS,
		/* min request length     */ SWT_RCREQ_HEADER_LEN + SWT_INDIV_SHORT_VIN_LEN,
		/* function               */ Swt_KwpSetVin
	}
};

#define SWT_STOP_SEC_CONST_UNSPEC
#include "MemMap.h"

/*******************************************************************************
**                       Local Data                                           **
*******************************************************************************/
#define SWT_START_SEC_VAR_8BIT_NO_INIT
#include "MemMap.h"

/** Flag whether a successful authentication has taken place. */
static uint8 Swt_Authenticated;

/** Current state of LTP statenmachine. */
static Swt_LtpStateType Swt_LtpState;

/** SGID of currently processed request. */
static uint8 Swt_LtpCurrentSgid;

/** Id of current job being processed by LTP statemachine. */
static uint8 Swt_LtpCurrentRco;

/** Number of chunks processed by LTP statemachine for current job. */
static uint8 Swt_LtpChunkCount;

/** Buffer for concatenated KWP2000 chunks of received data. */
static uint8 Swt_LtpWriteBuffer[SWT_LTP_BUFFER_LEN];

/** SWID for write requests. */
static uint8 Swt_LtpSwid[SWT_SWID_LEN];

/** Certificate type for write requests. */
static uint8 Swt_LtpCertKind;

#define SWT_STOP_SEC_VAR_8BIT_NO_INIT
#include "MemMap.h"

#define SWT_START_SEC_VAR_16BIT_NO_INIT
#include "MemMap.h"

/** Number of bytes to transmit/receive via LTP statemachine. */
static uint16 Swt_LtpBytesLeft;

/** Call id of job process. */
static uint16 Swt_LtpCallId;

#define SWT_STOP_SEC_VAR_16BIT_NO_INIT
#include "MemMap.h"

#define SWT_START_SEC_VAR_FAR_PTR
#include "MemMap.h"

/** Buffer for concatenated KWP2000 chunks of data written to/read from tester. */
static P2VAR(uint8,AUTOMATIC,SC_FAR) Swt_LtpBuffer;

#define SWT_STOP_SEC_VAR_FAR_PTR
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"

void Swt_KwpInit( void )
{
	/* reset authentication state */
	Swt_Authenticated = 0;

	/* initialize long TP state machine */
	Swt_LtpState = SWT_LTP_STATE_IDLE;

	/* initialize call id, value does not matter, just make sure it is changed (incremented) while ECU is running */
	/* do not use 0 as people may be confused when looking at the protocol... */
	Swt_LtpCallId = 0x0815u;
}

/******************************************************************************/
void Swt_KwpRoutineControlSwtOperation( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* index of requested routine in descriptor array */
	uint8 jobIndex;
	P2CONST(Swt_RoutineControlDescriptorType,AUTOMATIC,SC_FAR) pJobDesc = 0;

	/* routine control option of requested SWT job */
	const uint8 rcOption = pMsgContext->reqData[1];

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
	/* make sure the correct routine control function is passed */
	if( SWT_RCID_SWT_ROUTINE != pMsgContext->reqData[0] )
	{
		Det_ReportError( SWT_DET_MODULE_ID, (uint8)SWT_KWP2000_HANDLER_RC_SWT_API_ID, (uint8)Swt_RC_BAD_PARAM );
		DescSetNegResponse( DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange );
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
		DescSetNegResponse( DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcSubfunctionNotSupported );
	}

	if( 0 != pJobDesc )
	{
      /* check whether the LTP statemachine is in IDLE state */
      /* If it is not in idle state and the new command is a correct diagnostics command */
      /* that does not need this statemachine we reset it */
      if (SWT_RCFLAG_REQUIRES_LONG_TP != (pJobDesc->Flags & SWT_RCFLAG_REQUIRES_LONG_TP))
      {
         if (Swt_LtpState != SWT_LTP_STATE_IDLE)
         {
            Swt_KwpResetLtpStatemachine( 0 );
         }
      }

		/* prepare positive response message */
		(void)Swt_CommonCopy( pMsgContext->resData, pMsgContext->reqData, SWT_RCREQ_HEADER_LEN );

		/* check request buffer size (response buffer is checked in sub function if required) */
		if( pMsgContext->reqDataLen < pJobDesc->MinReqLen )
		{
			/* request data is corrupt or incomplete */
			pMsgContext->resData[2] = Swt_RC_BAD_PARAM;
			pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
			pJobDesc = 0;
		}
	}

	/* check whether authentication is required */
	if( 0 != pJobDesc )
	{
		if( 0 != (pJobDesc->Flags & SWT_RCFLAG_REQUIRES_SECURE_ACCESS) )
		{
			/* routine requires SWT security access */
			if( 0 == Swt_Authenticated )
			{
    			/* KWP2000 is not using diagnostic layer message for denial of security access */
    			pMsgContext->resData[2] = Swt_RC_NOT_AUTHENTICATED;
    			pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
				pJobDesc = 0;
			}
		}
	}

	/* check whether job is interrupting/requiring long TP stream */
	if( 0 != pJobDesc )
	{
		if( Swt_LtpState == SWT_LTP_STATE_IDLE )
		{
			/* LTP state machine is idle, check whether requested job can be executed */
			if( 0 != (pJobDesc->Flags & SWT_RCFLAG_REQUIRES_LONG_TP) )
			{
				/* job must be part of TP but is not */
				pMsgContext->resData[2] = Swt_RC_BAD_PARAM;
				pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
				pJobDesc = 0;
			}
		}
		else
		{
			/* LTP state machine is processing stream request, check whether ids match */
			if( (rcOption != Swt_LtpCurrentRco) || (Sgid != Swt_LtpCurrentSgid) )
			{
				/* an id is wrong */
				Swt_KwpResetLtpStatemachine( 0 );
				pMsgContext->resData[2] = Swt_RC_BAD_PARAM;
				pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
				pJobDesc = 0;
			}
		}
	}

	/* dispatch SWT function */
    if( 0 != pJobDesc )
	{
        if( 0 != pJobDesc->Func )
        {
            SwtRC_t ret = pJobDesc->Func( Sgid, pMsgContext );
            pMsgContext->resData[2] = (uint8)ret;
            if( Swt_RC_OK != ret )
            {
                /* if job failed, reset statemachine to make sure state is not hanging */
                Swt_KwpResetLtpStatemachine( 0 );
            }
        }
        else
        {
            /* this function is not supported at this point */
            DescSetNegResponse( DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcSubfunctionNotSupported );
        }
    }
}

/******************************************************************************/
void Swt_KwpNotifyAuthSuccess( void )
{
	/* set library to authenticated, will stay like this for uptime of ECU */
	Swt_Authenticated = 1;
   Swt_KwpResetLtpStatemachine( 0 );
}

/******************************************************************************/
#if (SWT_DIAG_USE_ECU_SWTLIST == SWT_CFG_ON)
void Swt_KwpReadDataByIdentifierReadEcuSwtList( DescMsgContext* pMsgContext )
{
	/* todo: by user, for now just reject */
	DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext)  DCM_NRC_SUBFUNCTIONNOTSUPPORTED );
}
#endif /* (SWT_DIAG_USE_ECU_SWTLIST == SWT_CFG_ON) */

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"

static void Swt_KwpResetLtpStatemachine( uint8 Sgid )
{
	/* reset state variables, state itself can stay as is */
	Swt_LtpChunkCount = 0;
	Swt_LtpCallId++;
	Swt_LtpCurrentSgid = Sgid;
	Swt_LtpBuffer = 0;
   Swt_LtpState = SWT_LTP_STATE_IDLE;   
}

/******************************************************************************/
static void Swt_KwpSetUint16( CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) pBuf, const uint16 Val )
{
	*pBuf = (uint8)(Val >> 8);
	*(pBuf + 1) = (uint8)(Val & 0x00FFu);
}

/******************************************************************************/
static SwtRC_t Swt_KwpGetStatus( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* call SWT library operation */
	ret = Swt_GetStatus( Sgid,
						 (uint8)(SWT_KWP_MAX_PAYLOAD_LEN - SWT_RCRES_HEADER_LEN),
						 &pMsgContext->resData[SWT_RCRES_HEADER_LEN] );

	if( Swt_RC_OK == ret )
	{
		/* re-arrange data (API layout currently does not match diagnostic layout) */
		uint8 numSwids = pMsgContext->resData[SWT_RCRES_HEADER_LEN + 3];
		if( numSwids > 0 )
		{
			(void)Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + 3],
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
static SwtRC_t Swt_KwpGetSwidsFunctional( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* call SWT library operation */
	ret = Swt_GetSWID( Sgid,
					   SWT_KWP_MAX_PAYLOAD_LEN - SWT_RCRES_HEADER_LEN,
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
static SwtRC_t Swt_KwpGetSwids( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* call SWT library operation */
	ret = Swt_GetSWID( Sgid,
					   SWT_KWP_MAX_PAYLOAD_LEN - SWT_RCRES_HEADER_LEN,
					   &pMsgContext->resData[SWT_RCRES_HEADER_LEN] );

	if( Swt_RC_OK == ret )
	{
		/* re-arrange data (API layout currently does not match diagnostic layout) */
		/* number of SWIDs unwanted */
		uint8 swidsLen = pMsgContext->resData[SWT_RCRES_HEADER_LEN] * SWT_SWID_LEN;
		(void)Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], &pMsgContext->resData[SWT_RCRES_HEADER_LEN + 1], swidsLen );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + swidsLen;
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpCheckFsc( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	return Swt_CheckFSC( Sgid, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN], TRUE );
}

/******************************************************************************/
static SwtRC_t Swt_KwpDisableFsc( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;

	/* call SWT library operation */
	return Swt_DisableFSC( Sgid, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN] );
}

/******************************************************************************/
static SwtRC_t Swt_KwpStoreFscLength( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret = Swt_RC_OK;
	P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SwData;
	uint8 noSwids;

	/* initialize LTP statemachine */
	Swt_KwpResetLtpStatemachine( Sgid );

	/* initialize buffer to write chunks to */
	Swt_LtpBuffer = Swt_LtpWriteBuffer;
	Swt_LtpBytesLeft = ((uint16)pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN] << 8) + ((uint16)pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_SWID_LEN + 1]);

	/* check for memory */
	if( Swt_LtpBytesLeft > SWT_LTP_BUFFER_LEN )
	{
		/* not enough buffer for data */
		ret = Swt_RC_NO_FREE_SPACE;
	}

   	/* check for min length */
	if(!( Swt_LtpBytesLeft > 0 ))
	{
		/* not enough buffer for data */
		ret = Swt_RC_BAD_PARAM;
	}

	if( Swt_RC_OK == ret )
	{
		/* store SWID for which FSC is sent */
		(void)Swt_CommonCopy( Swt_LtpSwid, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN], SWT_SWID_LEN );

		/* check whether SWID exists in SWT library */
		SwData = Swt_GetSWData( Sgid, &noSwids );
		if( 0 == SwData )
		{
			ret = Swt_RC_MISSING_SG_DATA;
		}
	}

	if( Swt_RC_OK == ret )
	{
        uint8 index;
		ret = Swt_FindSW( SwData, noSwids, Swt_LtpSwid, &index, FALSE );
	}

	if( Swt_RC_OK == ret )
	{
		/* perform transition: waiting for StoreFsc call */
		Swt_LtpCurrentRco = SWT_RCO_SFSC;
		Swt_LtpState = SWT_LTP_STATE_AWAITING_NEXT;
	}

	/* prepare response */
	if( Swt_RC_OK == ret )
	{
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], SWT_LTP_MXBL_TPREQ );
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + SWT_MXBL_LEN], Swt_LtpCallId );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_MXBL_LEN + SWT_CALLID_LEN;
	}
	else
	{
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpStoreFsc( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret = Swt_RC_OK;

	/* number of bytes received this time */
	uint16 chunkLen = (uint16)(pMsgContext->reqDataLen - SWT_RCREQ_HEADER_LEN - SWT_LTP_INDEX_LEN - SWT_CALLID_LEN);
	if( chunkLen > Swt_LtpBytesLeft )
	{
		/* too much data */
		ret = Swt_RC_BAD_PARAM;
	}

	/* check sequence number here (job specific position) */
	if( (Swt_RC_OK == ret) && (pMsgContext->reqData[SWT_RCREQ_HEADER_LEN] != (Swt_LtpChunkCount + 1u)) )
	{
		ret = Swt_RC_BAD_PARAM;
	}

	if( Swt_RC_OK == ret )
	{
		/* copy chunk */
		ret = Swt_CommonCopy( Swt_LtpBuffer, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_LTP_INDEX_LEN + SWT_LTP_CALL_ID_LEN], chunkLen );

		/* increment index */
		Swt_LtpChunkCount++;
		pMsgContext->resData[SWT_RCRES_HEADER_LEN] = Swt_LtpChunkCount;

		/* update counters */
		Swt_LtpBytesLeft -= chunkLen;
		Swt_LtpBuffer += chunkLen;
	}

	/* check if all bytes have been received */
	if( 0 == Swt_LtpBytesLeft )
	{
        uint16 fscLen = (uint16)(Swt_LtpBuffer - Swt_LtpWriteBuffer);
        uint16 swidPos = 0;
        
        /* compare SWID from request and the one in FSC */
        if( Swt_RC_OK == ret )
		{
			ret = Swt_GetPos( Swt_LtpWriteBuffer, fscLen, Swt_FSC_SWID, &swidPos );
		}

		if( Swt_RC_OK == ret )
		{
			if( Swt_RC_EQUAL != Swt_CommonCompare( &Swt_LtpWriteBuffer[swidPos], Swt_LtpSwid, SWT_SWID_LEN ) )
			{
				ret = Swt_RC_SW_NOT_EXISTENT;
			}
		}

		/* call SWT library operation */
		if( Swt_RC_OK == ret )
		{
 			ret = Swt_StoreFSC( Sgid, Swt_LtpSwid, Swt_LtpWriteBuffer, fscLen );
		}

		/* perform transition if no bytes are left, also if operation failed */
		Swt_LtpState = SWT_LTP_STATE_IDLE;
	}

	/* prepare response */
	if( Swt_RC_OK == ret )
	{
		pMsgContext->resData[SWT_RCRES_HEADER_LEN] = Swt_LtpChunkCount;
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_LTP_INDEX_LEN;
	}
	else
	{
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpGetFscLength( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret;

	/* initialize LTP statemachine */
	Swt_KwpResetLtpStatemachine( Sgid );

	/* call SWT function */
	ret = Swt_GetFSC( Sgid,
					  &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN],
					  &Swt_LtpBuffer,
					  &Swt_LtpBytesLeft );

	if( Swt_RC_OK == ret )
	{
		/* set return data */
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], Swt_LtpBytesLeft );
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + SWT_FSC_LEN_LEN], SWT_LTP_MXBL_TPRES );
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + SWT_FSC_LEN_LEN + SWT_MXBL_LEN], Swt_LtpCallId );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_FSC_LEN_LEN + SWT_MXBL_LEN + SWT_CALLID_LEN;

		/* perform transition: waiting for GetCert call */
		Swt_LtpCurrentRco = SWT_RCO_GFSC;
		Swt_LtpState = SWT_LTP_STATE_AWAITING_NEXT;
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpGetFsc( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret = Swt_RC_OK;

	/* number of bytes to send this time */
	uint16 chunkLen;

	/* check sequence number here (job specific position) */
	if( pMsgContext->reqData[SWT_RCREQ_HEADER_LEN] != (Swt_LtpChunkCount + 1u) )
	{
		ret = Swt_RC_BAD_PARAM;
	}

	/* determine number of bytes to send this time */
	if( Swt_RC_OK == ret )
	{
		if( Swt_LtpBytesLeft >= SWT_LTP_MXBL_TPRES )
		{
			chunkLen = SWT_LTP_MXBL_TPRES;
		}
		else
		{
			chunkLen = Swt_LtpBytesLeft;
		}

		/* increment and write running index */
		Swt_LtpChunkCount++;
		pMsgContext->resData[SWT_RCRES_HEADER_LEN] = Swt_LtpChunkCount;

		/* copy FSC to result buffer */
		ret = Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + SWT_LTP_INDEX_LEN], Swt_LtpBuffer, chunkLen );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_LTP_INDEX_LEN + chunkLen;

		/* update counters */
		Swt_LtpBytesLeft -= chunkLen;
		Swt_LtpBuffer += chunkLen;

		/* perform transition if no bytes are left */
		if( 0 == Swt_LtpBytesLeft )
		{
			Swt_LtpState = SWT_LTP_STATE_IDLE;
		}
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpPeriodicalChecks( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;

	/* call SWT library operation */
	return Swt_PeriodicalChecks( Sgid, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN] );
}

/******************************************************************************/
#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

static SwtRC_t Swt_KwpCheckCert( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* response only consists of reply with error code */ 
	pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	return Swt_CheckCert( Sgid,
						  /* SWID */
						  &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN],
						  /* certificate type */
						  pMsgContext->reqData[SWT_RCREQ_HEADER_LEN],
                    FALSE);
}

/******************************************************************************/
static SwtRC_t Swt_KwpGetCertLength( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	SwtRC_t ret;

	/* initialize LTP statemachine */
	Swt_KwpResetLtpStatemachine( Sgid );

	/* call SWT function */
	ret = Swt_GetCert( Sgid,
					   &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN],
					   pMsgContext->reqData[SWT_RCREQ_HEADER_LEN],
					   &Swt_LtpBuffer,
					   &Swt_LtpBytesLeft );

	if( Swt_RC_OK == ret )
	{
		/* set return data */
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], Swt_LtpBytesLeft );
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + SWT_CERT_LEN_LEN], SWT_LTP_MXBL_TPRES );
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + SWT_CERT_LEN_LEN + SWT_MXBL_LEN], Swt_LtpCallId );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_CERT_LEN_LEN + SWT_MXBL_LEN + SWT_CALLID_LEN;

		/* perform transition: waiting for GetCert call */
		Swt_LtpCurrentRco = SWT_RCO_GCERT;
		Swt_LtpState = SWT_LTP_STATE_AWAITING_NEXT;
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpGetCert( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret = Swt_RC_OK;

	/* number of bytes to send this time */
	uint16 chunkLen;

	/* check sequence number here (job specific position) */
	if( pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN] != (Swt_LtpChunkCount + 1u) )
	{
		ret = Swt_RC_BAD_PARAM;
	}

	/* determine number of bytes to send this time */
	if( Swt_RC_OK == ret )
	{
		if( Swt_LtpBytesLeft >= SWT_LTP_MXBL_TPRES )
		{
			chunkLen = SWT_LTP_MXBL_TPRES;
		}
		else
		{
			chunkLen = Swt_LtpBytesLeft;
		}

		/* increment and write running index */
		Swt_LtpChunkCount++;
		pMsgContext->resData[SWT_RCRES_HEADER_LEN] = Swt_LtpChunkCount;

		/* copy certificate to result buffer */
		ret = Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + SWT_LTP_INDEX_LEN], Swt_LtpBuffer, chunkLen );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_LTP_INDEX_LEN + chunkLen;

		/* update counters */
		Swt_LtpBytesLeft -= chunkLen;
		Swt_LtpBuffer += chunkLen;

		/* perform transition if no bytes are left */
		if( 0 == Swt_LtpBytesLeft )
		{
			Swt_LtpState = SWT_LTP_STATE_IDLE;
		}
	}
	else
	{
		/* response only consists of reply with error code */ 
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpStoreCertLength( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret = Swt_RC_OK;

	/* initialize LTP statemachine */
	Swt_KwpResetLtpStatemachine( Sgid );

	/* initialize buffer to write chunks to */
	Swt_LtpBuffer = Swt_LtpWriteBuffer;
	Swt_LtpBytesLeft = ((uint16)pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN] << 8) + ((uint16)pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + 1]);

	/* check for memory */
	if( Swt_LtpBytesLeft > SWT_LTP_BUFFER_LEN )
	{
		/* not enough buffer for data */
		ret = Swt_RC_NO_FREE_SPACE;
	}

	/* check for min length */
	if(!( Swt_LtpBytesLeft > 0 ))
	{
		/* not enough buffer for data */
		ret = Swt_RC_BAD_PARAM;
	}

    /* get certificate type */
	if( Swt_RC_OK == ret )
	{
		Swt_LtpCertKind = pMsgContext->reqData[SWT_RCREQ_HEADER_LEN];
		if( Swt_LtpCertKind != SWT_CERT_TYPE_SIGS && Swt_LtpCertKind != SWT_CERT_TYPE_FSCS && Swt_LtpCertKind != SWT_CERT_TYPE_ROOT )
		{
			ret = Swt_RC_BAD_PARAM;
		}
	}

	if( Swt_RC_OK == ret )
	{
		/* store SWID for which FSC is sent */
		(void)Swt_CommonCopy( Swt_LtpSwid, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_CERT_TYPE_LEN + SWT_CERT_LEN_LEN], SWT_SWID_LEN );

		/* check whether SWID exists in SWT library, if not {0, 0, 0, 0} */
		if( Swt_LtpSwid[0] != 0 || Swt_LtpSwid[1] != 0 || Swt_LtpSwid[2] != 0 || Swt_LtpSwid[3] != 0 )
		{
			P2VAR(Swt_SWDataType,AUTOMATIC,SC_FAR) SwData;
			uint8 noSwids;

			SwData = Swt_GetSWData( Sgid, &noSwids );
			if( 0 == SwData )
			{
				ret = Swt_RC_MISSING_SG_DATA;
			}
			// in case of SigSCert, the SWID is ignored and not tested
         if(( Swt_RC_OK == ret ) && ( Swt_LtpCertKind != SWT_CERT_TYPE_SIGS ))
			{
				uint8 index;
				ret = Swt_FindSW( SwData, noSwids, Swt_LtpSwid, &index, FALSE );
			}
		}
	}

	/* prepare response */
	if( Swt_RC_OK == ret )
	{
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], SWT_LTP_MXBL_TPREQ );
		Swt_KwpSetUint16( &pMsgContext->resData[SWT_RCRES_HEADER_LEN + SWT_MXBL_LEN], Swt_LtpCallId );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_MXBL_LEN + SWT_CALLID_LEN;
	}
	else
	{
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	if( Swt_RC_OK == ret )
	{
		/* perform transition: waiting for StoreCert call */
		Swt_LtpCurrentRco = SWT_RCO_SCERT;
		Swt_LtpState = SWT_LTP_STATE_AWAITING_NEXT;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpStoreCert( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	/* return code */
	SwtRC_t ret = Swt_RC_OK;

	/* number of bytes received this time */
	uint16 chunkLen = (uint16)(pMsgContext->reqDataLen - SWT_RCREQ_HEADER_LEN - SWT_LTP_INDEX_LEN - SWT_CALLID_LEN);
	if( chunkLen > Swt_LtpBytesLeft )
	{
		/* too much data */
		ret = Swt_RC_BAD_PARAM;
	}

	/* check sequence number here (job specific position) */
	if( (Swt_RC_OK == ret) && (pMsgContext->reqData[SWT_RCREQ_HEADER_LEN] != (Swt_LtpChunkCount + 1u)) )
	{
		ret = Swt_RC_BAD_PARAM;
	}

	if( Swt_RC_OK == ret )
	{
		/* copy chunk */
		ret = Swt_CommonCopy( Swt_LtpBuffer, &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN + SWT_LTP_INDEX_LEN + SWT_LTP_CALL_ID_LEN], chunkLen );

		/* increment index */
		Swt_LtpChunkCount++;
		pMsgContext->resData[SWT_RCRES_HEADER_LEN] = Swt_LtpChunkCount;

		/* update counters */
		Swt_LtpBytesLeft -= chunkLen;
		Swt_LtpBuffer += chunkLen;
	}

	/* check if all bytes have been received */
	if( 0 == Swt_LtpBytesLeft )
	{
        uint16 certLen = (uint16)(Swt_LtpBuffer - Swt_LtpWriteBuffer);

		/* call SWT library operation */
		if( Swt_RC_OK == ret )
		{
			ret = Swt_StoreCert( Sgid, Swt_LtpSwid, Swt_LtpCertKind, certLen, Swt_LtpWriteBuffer );
		}

		/* perform transition if no bytes are left, also if operation failed */
		Swt_LtpState = SWT_LTP_STATE_IDLE;
	}

	/* prepare response */
	if( Swt_RC_OK == ret )
	{
		pMsgContext->resData[SWT_RCRES_HEADER_LEN] = Swt_LtpChunkCount;
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_LTP_INDEX_LEN;
	}
	else
	{
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}

	return ret;
}

#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

/******************************************************************************/
static SwtRC_t Swt_KwpGetVin( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	const uint8* pVin = Appl_SwtGetVinInternal();
	SwtRC_t ret;

	/* check for failure of VIN access */
	if( 0 == pVin )
	{
		ret = Swt_RC_FLASH_READ_ERROR;
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	}
	else
	{
		/* copy short vin to diagnostic buffer */
		ret = Swt_CommonCopy( &pMsgContext->resData[SWT_RCRES_HEADER_LEN], &pVin[SWT_INDIV_LONG_VIN_LEN - SWT_INDIV_SHORT_VIN_LEN], SWT_INDIV_SHORT_VIN_LEN );
		pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN + SWT_INDIV_SHORT_VIN_LEN;
	}

	return ret;
}

/******************************************************************************/
static SwtRC_t Swt_KwpSetVin( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext )
{
	SwtRC_t ret;

	/* length of received VIN (result is positive since min length was already checked before) */
	uint8 vinLen = pMsgContext->reqDataLen - SWT_RCREQ_HEADER_LEN;
	switch( vinLen )
	{
		case SWT_INDIV_SHORT_VIN_LEN:
		{
			/* initialize temporary storage for long VIN and copy short vin to end of array */
			uint8 tempVin[SWT_INDIV_LONG_VIN_LEN];
			
			int i;
			for( i = 0; i < (SWT_INDIV_LONG_VIN_LEN - SWT_INDIV_SHORT_VIN_LEN); i++ )
			{
				tempVin[i] = 0x20u;
			}

			ret = Swt_CommonCopy( &tempVin[i], &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN], SWT_INDIV_SHORT_VIN_LEN );

			/* pass temporary long vin to callback */
			if( Swt_RC_OK == ret )
			{
				ret = Appl_SwtSetVinInternal( tempVin );
			}
		}
		break;

		case SWT_INDIV_LONG_VIN_LEN:
		{
			/* long vin can be directly passed through */
			ret = Appl_SwtSetVinInternal( &pMsgContext->reqData[SWT_RCREQ_HEADER_LEN] );
		}
		break;

		default:
			/* unexpected vin length */
			ret = Swt_RC_BAD_PARAM;
	}

    pMsgContext->resDataLen = SWT_RCRES_HEADER_LEN;
	return ret;
}


#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if (SWT_DIAG_USE_UDS == SWT_CFG_ON) */

/*** End of file **************************************************************/
