/**************************************************************************//**
 * \file
 * Declaration of KWP 2000 specific adapter for diagnostic requests to SWT lib.
 *
 * \target All
 * \project SWT
 * \author BMW AG
 * \userchange No
 *
 * The SWT library comes packaged with a set of diagnostic adapters. This file
 * contains an adapter for the KWP 2000 diagnostic protocol.
 *****************************************************************************/

#if (!defined __SWT_KPW2000_H__)                   /* preprocessor exclusion definition */
#define __SWT_KPW2000_H__

#ifdef __cplusplus
extern "C" {
#endif    /* __cplusplus */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Swt_Cfg.h"

/* sources only active for KWP 2000 diagnostics */
#if	(SWT_DIAG_USE_KWP2000 != SWT_CFG_ON)
	#error KWP2000 support is currently disabled. Either prevent inclusion of this header file or enable KWP2000 support.
#endif
#include "Swt_Types.h"
#include "ccl_cfg.h"

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/
/** Routine control routine identifier \em SwtRoutine. */
#define SWT_RCID_SWT_ROUTINE		0x1Fu

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
 * Initializes KWP2000 adapter.
 *
 * This function must be called before the first invocation of other KWP
 * operations.
 */
extern void Swt_KwpInit( void );

/**************************************************************************//**
 * Executes routine control job for SWT enabled ECU.
 *
 * This function must be called for routine control requests with routine identifier
 * SwtRoutine (0x1F). The implementation ensures the correct diagnostic session
 * and security level are active and then dispatches the request to the appropriate
 * SWT library function.
 *
 * The result data is eventually placed into \p pMsgContext.
 *
 * \note
 *		DescProcessingDone() is \em not called within this function and
 *		therefore must be invoked separately.
 *
 * \param Sgid
 *		Diagnostic address of (this) target ECU running SWT-enabled applications.
 * \param pMsgContext
 *		Diagnostic message context.
 */
extern void Swt_KwpRoutineControlSwtOperation( uint8 Sgid, CONSTP2VAR(DescMsgContext,AUTOMATIC,SC_FAR) pMsgContext );

/**************************************************************************//**
 * Informs SWT library that authentication of the tester was successful.
 */
extern void Swt_KwpNotifyAuthSuccess( void );

#if (SWT_DIAG_USE_ECU_SWTLIST == SWT_CFG_ON)
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
extern void Swt_KwpReadDataByIdentifierReadEcuSwtList( DescMsgContext* pMsgContext );
#endif /* (SWT_DIAG_USE_ECU_SWTLIST == SWT_CFG_ON) */

#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* if (!defined __SWT_KPW2000_H__) */
/*** End of file **************************************************************/
