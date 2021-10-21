/**************************************************************************//**
 * \file
 * Declaration of SWT application level interfaces.
 *
 * \target All
 * \project SWT
 * \author BMW AG
 * \userchange No
 *
 * This file contains definitions of public API functions to be invoked by an
 * SWT-enabled application.
 *****************************************************************************/

#if (!defined SWT_APPL_H)           /* preprocessor exclusion definition */
#define SWT_APPL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                          /* configuration of this module */
#include "Swt_Types.h"                                /* types of this module */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/



/*******************************************************************************
**                      Global Constants                                      **
*******************************************************************************/



/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/



/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

#if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_ON)

/**************************************************************************//**
 * Initializes SWT library to state "no data".
 *
 * Use this function only if no NVRAM initialization is available. Otherwise
 * use the ROM defaults specified in Swt_Cfg.h.
 *
 * \param SGID
 *		Controller's diagnostic address.
 * \retval Swt_RC_FLASH_WRITE_ERROR
 *		It was not possible to store the state of the handler persistently.
 * \retval Swt_RC_MISSING_SG_DATA
 *		\p SGID is not known.
 * \retval Swt_RC_OK
 *		Operation finished successfully.
 */
extern SwtRC_t Swt_Init( const uint8 SGID );

/**************************************************************************//**
 * After new software has been flashed, the new SWIDs and SigS certificate
 * are stored through this function.
 *
 * Function not in use today.
 */
extern SwtRC_t Swt_SwDownloadPostAction( const uint8 SGID, const uint16 SigsCertLen, CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SigsCert, const uint8 SwIdCount, CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwIds );

#endif /* #if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_ON) */

/**************************************************************************//**
 * Checks activation state of specified software.
 *
 * This is the main function to be called by an application to check whether it
 * is allowed to run.
 *
 * \param SGID
 *		Controller's diagnostic address.
 * \param SwId
 *		Id of the software to check the state for.
 * \retval Swt_RC_OK
 *		Software is activated and is allowed to run.
 * \retval Swt_RC_SW_NOT_ACTIVATED
 *		Software is not activated.
 * \retval Swt_RC_MISSING_SG_DATA
 *		\p SGID is not known.
 * \retval Swt_RC_SW_NOT_EXISTENT
 *		\p SwId is not known.
 */
extern SwtRC_t Swt_IsSwActivated( const uint8 SGID, CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId );

/**************************************************************************//**
 * Series of checks to be executed on a regular basis.
 *
 * This function can be called by the diagnostic layer as well as directly by
 * the application layer. Typical execution time is during startup or shutdown
 * of an ECU.
 *
 * \note The execution of this function may take a considerable amount of time
 *		and should not be executed in a task with a fixed (short) runtime limit.
 *
 * \param SGID
 *		Controller's diagnostic address.
 * \param SwId
 *		Id of the software to check. The value "0" starts the check for all SWIDs
 *    contained configured in the SWT library.
 * \retval Swt_RC_OK
 *		Software is activated and is allowed to run.
 * \retval Swt_RC_SW_NOT_ACTIVATED
 *		Software is not activated.
 * \retval Swt_RC_MISSING_SG_DATA
 *		\p SGID is not known.
 * \retval Swt_RC_SW_NOT_EXISTENT
 *		\p SwId is not known.
 * \retval Swt_RC_FLASH_READ_ERROR
 *		The internal VIN could not be read.
 * \retval Swt_RC_FGN_ACCESS_FAILURE
 *		The external VIN could not be read.
 * \retval Swt_RC_FGN_CHECK_FAILURE
 *		The VINs are not equal.
 * \retval Swt_RC_SWSIG_CHECK_FAILURE
 *		The software signature check has failed.
 * \retval Swt_RC_FSCS_CERT_CHECK_FAILURE
 *		The check of the FSCS certificate failed.
 * \retval Swt_RC_FSC_CHECK_FAILURE
 *		The check of an FSC failed.
 * \retval Swt_RC_FLASH_WRITE_ERROR
 *		It was not possible to store the state persistently.
 */
extern SwtRC_t Swt_PeriodicalChecks( const uint8 SGID, CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId );

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
/**************************************************************************//**
 * Series of checks to be executed on a regular basis.
 *
 * This function can be called by the diagnostic layer as well as directly by
 * the application layer. Typical execution time is during startup or shutdown
 * of an ECU.
 *
 * \param SGID
 *		Controller's diagnostic address.
 * \param SwId
 *		Id of the software to check.
 * \retval Swt_RC_OK
 *		Software is activated and is allowed to run.
 * \retval Swt_RC_FSC_CANCELLED
      if the FSC has been disabled
 * \retval Swt_RC_SWID_CHECK_FAILURE
      if the upgrade index of the FSC SWID is too old
 * \retval Swt_RC_KEY_DERIVATION_NOT_ACTIVATED
      if the FSC_Enabler for a short FSC is not accepted
 * \retval Swt_RC_FGN_ACCESS_FAILURE
      if the VIN could not be accessed
 * \retval Swt_RC_FGN_CHECK_FAILURE
      if the individualisation attributes of the FSC are invalid
 * \retval Swt_RC_VALIDITY_CHECK_FAILURE
      if the validity conditions of the FSC are invalid
 * \retval Swt_RC_INVALID_FSC, 
      if the stored FSC is too big or too small
 * \retval Swt_RC_FGN_CHECK_FAILURE
      if the FGN or the ECUSNR in the FSC is not the same as in the SG
 * \retval Swt_RC_FLASH_WRITE_ERROR
      if it was not possible to store the state of the handler persistent
 * \retval Swt_RC_FLASH_READ_ERROR
      if the key could not be extracted from the FSCS certificate
 * \retval Swt_RC_UNKNOWN_ERROR
      if something unexpected happens
 * \retval Swt_RC_SW_NOT_EXISTENT
      if no software with the given SwId is stored inside the ECU
 * \retval Swt_RC_MISSING_SG_DATA
      if 'SGID' does not match the SGID of this controller
 * \retval Swt_RC_BAD_PARAM, if one of the arguments was a null pointer
*/

extern SwtRC_t Swt_CheckFscShortForUpdate(const uint8 SGID, CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId );
#endif /* #if (SWT_USE_SWT_SHORT == SWT_CFG_ON) */


#define SWT_STOP_SEC_CODE
#include "MemMap.h"

#endif /* if (!defined SWT_APPL_H) */
/*** End of file **************************************************************/
