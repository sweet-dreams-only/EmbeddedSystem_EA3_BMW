/**************************************************************************//**
 * \file
 * Declaration of UDS/AUTOSAR DCM specific adapter for diagnostic requests to SWT lib.
 *
 * \target All
 * \project SWT
 * \author BMW AG
 * \userchange No
 *
 * The SWT library comes packaged with a set of diagnostic adapters. This file
 * contains an adapter for the UDS diagnostic protocol, which is used through
 * an AUTOSAR diagnostic communication manager (DCM).
 *****************************************************************************/

#if (!defined __SWT_DCM_H__)                   /* preprocessor exclusion definition */
#define __SWT_DCM_H__

#ifdef __cplusplus
extern "C" {
#endif    /* __cplusplus */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Swt_Cfg.h"
#include "Swt_Types.h"
#include "Dcm.h"


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/
/** Routine control routine identifier \em SwtRoutine. */
#define SWT_RCID_SWT_ROUTINE		0x0F1Fu

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"

/**************************************************************************//**
 * Checks whether DCM is allowed to switch to SWT session.
 *
 * Typically this function will not need to prevent a switch as the session
 * statemachine is already part of DCM/appldiag, i.e. there is no need to
 * check for an active extended session.
 *
 * \param Sgid
 *		Diagnostic address of (this) target ECU running SWT-enabled applications.
 * \retval DCM_E_OK
 *		Session switch is permitted.
 * \retval DCM_E_NOT_OK
 *		Session switch is not permitted.
 */
extern Dcm_StatusType Swt_DcmGetSessionStartPermission(); // /* NXTR SWT */ - CDCSWT extern Dcm_StatusType Swt_DcmGetSessionStartPermission( uint8 Sgid );

/**************************************************************************//**
 * Executes routine control job for SWT enabled ECU.
 *
 * This function must be called for routine control requests with sub-function
 * startRoutine (0x01) and routine identifier SwtRoutine (0x0F1F). The
 * implementation ensures the correct diagnostic session and security level are
 * active and then dispatches the request to the appropriate SWT library
 * function.
 *
 * The result data is eventually placed into \p pMsgContext.
 *
 * \note
 *		Dcm_ProcessingDone() is \em not called within this function and
 *		therefore must be invoked separately.
 *
 * \param Sgid
 *		Diagnostic address of (this) target ECU running SWT-enabled applications.
 * \param pMsgContext
 *		Diagnostic message context from DCM.
 */
extern void Swt_DcmRoutineControlSwtOperation( uint8 Sgid, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

/**************************************************************************//**
 * Executes write data by identifier service setting VIN for SWT.
 *
 * \note
 *		Dcm_ProcessingDone() is \em not called within this function and
 *		therefore must be invoked separately.
 *
 * \param pMsgContext
 *		Diagnostic message context from DCM.
 */
extern void Swt_DcmWriteDataByIdentifierVin( CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );

#if (SWT_USE_ECU_SWTLIST == SWT_CFG_ON)
/**************************************************************************//**
 * Executes RDBI request for SWT ECUs list.
 *
 * This function is typically implemented in VCM only.
 *
 * \note
 *		Dcm_ProcessingDone() is \em not called within this function and
 *		therefore must be invoked separately.
 *
 * \param pMsgContext
 *		Diagnostic message context from DCM.
 */
extern void Swt_DcmReadDataByIdentifierReadEcuSwtList( CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,SC_FAR) pMsgContext );
#endif /* (SWT_USE_ECU_SWTLIST == SWT_CFG_ON) */

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* if (!defined __SWT_DCM_H__) */
/*** End of file **************************************************************/
