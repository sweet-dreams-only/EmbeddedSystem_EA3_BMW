/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Rte_dcm.h                                                     **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : MPC55xx Autosar v2.1                                          **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Wrapper for DCM Module with BMW extensions                    **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.1: 23.08.2008, miwe: BSCTEMPLATE-286 removed compiler warnings
 * V1.0.0: 02.10.2007, miwe: initial version
 */

#ifndef RTE_DCM_H
#define RTE_DCM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types */
#include "Dcm.h"                  /* Autosar Dcm */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* Dcm user callbacks */
#define Rte_DcmStartProtocol(protocol)                                  DCM_E_OK
#define Rte_DcmStopProtocol(pMsgContext)


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef enum
{
  DCM_RP_TYPE_IDLE            = 0x00, /* Reset value after Init or new Diag-Request */
  DCM_RP_TYPE_SUCCESS         = 0x01, /* RP was transmitted */
  DCM_RP_TYPE_TX_IN_PROGRESS  = 0x02, /* RP (async or standard) is waiting for transmission on the Bus */
  DCM_RP_TYPE_FAILED          = 0x03  /* RP Canceled by TP  */
} Dcm_ResponsePendingType;


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*** Start of forward declaration section from directly mapped functions ***/
extern FUNC(void, DCM_APPL_CODE)             Dcm_InputOutputControlByIdentifier
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA)  pMsgContext
);


extern FUNC(void, DCM_APPL_CODE)             Rte_DcmGetSeed
(
   Dcm_SecLevelType SecurityLevel,
   uint8            SeedLen,
   CONSTP2VAR(uint8,AUTOMATIC,CDC_VAR_DCMDATA) Seed
);
/* ----- NXTR PATCH START -----
 * Added By: K. Smith (Nxtr)
 * Date Added: 28Sep16
 *
 * Reason: Due to the increase in key size, the Dcm needed to be patched to support the new key length. However, that value is
 * 260, which is larger than a uint8. As a result, the data type needed to be patched in order to properly hold the correct
 * value.
 */
#if 0
/* ----- Original Code Start ----- */
extern FUNC(Dcm_StatusType, DCM_APPL_CODE)   Rte_DcmCompareKey
(
   Dcm_SecLevelType   SecurityLevel,
   uint8              KeyLen,
   CONSTP2CONST(uint8,AUTOMATIC,CDC_CONST_DCMDATA) Key
);
/* ----- Original Code End ----- */
#endif
/* ----- Patch Code Start ----- */
extern FUNC(Dcm_StatusType, DCM_APPL_CODE)   Rte_DcmCompareKey
(
   Dcm_SecLevelType            SecurityLevel,
   uint16                      KeyLen,
   CONSTP2CONST(uint8, AUTOMATIC, CDC_CONST_DCMDATA)  Key
);
/* ----- Patch Code End ----- */
/* ----- NXTR PATCH END ----- */

extern FUNC(void, DCM_APPL_CODE)             Rte_DcmECUReset
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmReadDataByIdentifier
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
extern FUNC(void, DIAG_PUBLIC_DCMCODE)       Rte_DcmCommunicationControl
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmWriteDataByIdentifier
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmRoutineControl
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmRequestDownload
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmTransferData
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmRequestTransferExit
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
extern FUNC(Dcm_StatusType, DCM_APPL_CODE)   Rte_DcmIndication
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext,
   const uint8          SID
);
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmConfirmation
(
   Dcm_IdContextType idContext,
   PduIdType dcmRxPduId,
   Dcm_StatusType status
);
extern FUNC(Dcm_StatusType, DCM_APPL_CODE)   Rte_DcmGetSesChgPermission
(
   const Dcm_SesCtrlType SesCtrlTypeActive,
   const Dcm_SesCtrlType SesCtrlTypeNew
);
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmSesCtrlChangeIndication
(
   const Dcm_SesCtrlType SesCtrlTypeOld,
   const Dcm_SesCtrlType SesCtrlTypeNew
);

/*** End of forward declaration section from directly mapped functions ***/

extern FUNC(void, DCM_APPL_CODE)             Rte_DcmResponsePendingConfirmation
(
   Dcm_ConfirmationStatusType status
);

#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)

extern FUNC(void, DCM_APPL_CODE) Rte_DcmCancelPagedBufferProcessing (void);

extern FUNC(void, DCM_APPL_CODE)             Rte_DcmUpdatePage
(
   Dcm_MsgType PageBufPtr,
   Dcm_MsgLenType PageLen
);

#endif /* (DCM_PAGEDBUFFER_ENABLED == STD_ON) */

#if (DCM_ROE_ENABLED == STD_ON)
extern FUNC(void, DCM_APPL_CODE)             Rte_DcmResponseOnEvent
(
   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,CDC_VAR_DCMDATA) pMsgContext
);
#endif /* (DCM_ROE_ENABLED == STD_ON) */


#endif /* RTE_DCM_H                                                           */

/*** End of file **************************************************************/
/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              			SCR #
-------   -------  --------  -----------------------------------  		----------
12/14/10   2.0      OSteen      Add Nxtr Diagnositc Service $2F		CR3728
                                (InputOutputControlByIdentifier)					
								
******************************************************************************/
