/**************************************************************************//**
 * \file
 * Callback interfaces to be provided by integrator.
 *
 * \target All
 * \project SWT
 * \author Elektrobit Automotive GmbH
 * \author BMW AG
 * \userchange No
 *
 * This file contains function declarations that must be implemented when
 * integrating the SWT library. The functions in this file provide means for
 * platform abstraction.
 *****************************************************************************/

#if (!defined SWT_APPLSWT_H)  /* preprocessor exclusion definition */
#define SWT_APPLSWT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */

#include "Swt_RSA.h"                        /* declarations of rsa services */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef struct 
{
   uint8    day;
   uint8  month;
   uint16  year;
} SwtDateType;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"

/**************************************************************************//**
 * Writes SWT data to non-volatile memory.
 *
 * \param BlockId
 *		Id of data block to be written. Typically one of #SWT_SW_DATA, #SWT_CERT_DATA
 *		or #SWT_SWSIG_DATA.
 * \retval Swt_RC_OK
 *		Block was correctly written.
 * \retval Swt_RC_FLASH_WRITE_ERROR
 *		Block could not be written.
 */
extern SwtRC_t Appl_SwtWriteBlock( uint16 BlockId );

/**************************************************************************//**
 * Retrieves public FSCS key.
 *
 * This function is used in case no certificate is available for an FSC, e.g.
 * the FSC is an FSC light.
 * If SWT_RSA_USE_BARRETT == SWT_CFG_ON is set fscsPublicKey.ModulusExt has to 
 * be set to 0.
 *
 * \return
 *		Public FSCS key.
 */
#ifdef DOXYGEN
extern const Swt_RSAKeyType* Appl_SwtGetPublicFscsKey( void );
#else
extern P2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) Appl_SwtGetPublicFscsKey( void );
#endif

/**************************************************************************//**
 * Gets internal VIN.
 *
 * The internal VIN is typically stored in the ECU during a programming session
 * (bootloader) or an unlocked SWT session (application) through a diagnostic
 * \c WriteDataByIdentifier job.
 *
 * Note that this function must return 17 alphanumeric characters in all cases.
 * If only 7 characters are available, the leading bytes must be padded with
 * blanks (\c 0x20).
 *
 * \return
 *		Pointer to character array holding internal VIN.
 */
#ifdef DOXYGEN
extern const uint8* Appl_SwtGetVinInternal( void );
#else
extern P2CONST(uint8,AUTOMATIC,SC_FAR) Appl_SwtGetVinInternal( void );
#endif

/**************************************************************************//**
 * Sets internal VIN (by authenticated tester).
 *
 * The internal VIN is typically stored in the ECU during a programming session
 * (bootloader) or an unlocked SWT session (application) through a diagnostic
 * \c WriteDataByIdentifier job.
 *
 * If on system-level only a 7-byte VIN is provided, the VIN17 passed into this
 * function is padded with leading blanks (\c 0x20).
 *
 * \param pVin
 *		17-byte vehicle identification number.
 * \retval Swt_RC_OK
 *		VIN stored successfully.
 * \retval Swt_RC_FGN_ACCESS_FAILURE
 *		VIN could not be stored.
 */
extern SwtRC_t Appl_SwtSetVinInternal( P2CONST(uint8,AUTOMATIC,SC_FAR) pVin );

/**************************************************************************//**
 * Gets external VIN.
 *
 * The external VIN is received by the ECU periodically via a CAN message, e.g.
 * sent from CAS. This ECU must store the received VIN and return it through this
 * function.
 *
 * Note that this function must return 17 alphanumeric characters in all cases.
 * If only 7 characters are available, the leading bytes must be padded with
 * blanks (\c 0x20).
 *
 * \return
 *		Pointer to character array holding internal VIN.
 */
#ifdef DOXYGEN
extern const uint8* Appl_SwtGetVinExternal( void );
#else
extern P2CONST(uint8,AUTOMATIC,SC_FAR) Appl_SwtGetVinExternal( void );
#endif

/**************************************************************************//**
 * Returns the number of data blocks which constitute the SWE whose signature
 * is to be checked.
 *
 * The data returned by this function is determined during creation of the SWEs
 * (flashable software units) for this ECU.
 *
 * \param SGID
 *		Diagnostic address of virtual controller.
 * \return
 *		Number of blocks.
 */
extern uint32 Appl_SwtGetSwBlockNumber( const uint8 SGID );

/**************************************************************************//**
 * Returns a pointer to the start of an array containing the start addresses
 * of the data blocks which constitute the SWE whose signature is to be checked.
 *
 * The array length is equal to the value returned by Appl_SwtGetSwBlockNumber().
 *
 * The data returned by this function is determined during creation of the SWEs
 * (flashable software units) for this ECU.
 *
 * \param SGID
 *		Diagnostic address of virtual controller.
 * \return
 *		Pointer to array of block addresses.
 */
#ifdef DOXYGEN
extern const uint8** Appl_SwtGetSwAddresses( const uint8 SGID );
#else
extern P2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) Appl_SwtGetSwAddresses( const uint8 SGID );
#endif

/**************************************************************************//**
 * Returns a pointer to the start of an array containing the lengths of the
 * data blocks which constitute the SWE whose signature is to be checked.
 *
 * The data returned by this function is determined during creation of the SWEs
 * (flashable software units) for this ECU.
 *
 * The array length is equal to the value returned by Appl_SwtGetSwBlockNumber().
 *
 * \param SGID
 *		Diagnostic address of virtual controller.
 * \return
 *		Pointer to array of block lengths.
 */
#ifdef DOXYGEN
extern uint32* Appl_SwtGetSwLengths( const uint8 SGID );
#else
extern P2VAR(uint32,AUTOMATIC,SC_FAR) Appl_SwtGetSwLengths( const uint8 SGID );
#endif

/**************************************************************************//**
 * Returns a pointer to the start of an byte array containing the signature
 * which is to be checked.
 *
 * The data returned by this function is determined during creation of the SWEs
 * (flashable software units) for this ECU.
 *
 * \param SGID
 *		Diagnostic address of virtual controller.
 * \return
 *		Pointer to SW signature data.
 */
#ifdef DOXYGEN
extern uint32* Appl_SwtGetSwSignature( const uint8 SGID );
#else
extern P2VAR(uint32,AUTOMATIC,SC_FAR) Appl_SwtGetSwSignature( const uint8 SGID );
#endif
/**************************************************************************//**
 * Verifies structure of application validity condition.
 *
 * Only the application knows the exact structure of optional application validity
 * conditions. Therefore the library passes any application conditions found in
 * an FSC to the application through this function.
 *
 * \param AppGB
 *		Application validity condition to be parsed.
 * \retval Swt_RC_OK
 *		Condition is well-formed.
 * \retval Swt_RC_INVALID_FSC
 *		Condition is not well-formed, i.e. the containing FSC is invalid.
 */
extern SwtRC_t Appl_SwtParseAppCond( CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) AppGB );

/**************************************************************************//**
 * Informs application of existence of application validity condition.
 *
 * This function is called during an FSC check and tells the application that an
 * application validity condition applies. In constrast to the requirements document
 * the application simply acknowledges the condition instead of actively checking
 * it. This may change in future implementations.
 *
 * \param AppGB
 *		Application validity condition.
 * \param GroupIsValid
 *		Flag whether the group containing the the constraint is valid, which has an
 *      effect on the validity of the single condition passed here (see RQ document
 *      for explanation of validity rules).
 */
extern void Appl_SwtTellAppCond( CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) AppGB, const SwtRC_t GroupIsValid );

#if (SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON) || (SWT_USE_VAL_COND_DATE == SWT_CFG_ON) || (SWT_USE_SWT_FULL == SWT_CFG_ON)
/**************************************************************************//**
 * Determines current time in minutes since 2000/01/01, 00:00.
 *
 * \return
 *		Number of minutes since 2000/01/01, 00:00.
 */
extern uint32 Appl_SwtGetMinutes( void );
#endif /* #if (SWT_USE_VAL_COND_PERIOD == SWT_CFG_ON) || (SWT_USE_VAL_COND_DATE == SWT_CFG_ON) || (SWT_USE_SWT_FULL == SWT_CFG_ON) */

#if (SWT_USE_VAL_COND_KM == SWT_CFG_ON)
/**************************************************************************//**
 * Determines current mileage.
 *
 * \return
 *		Vehicle mileage in kilometers.
 */
extern uint32 Appl_SwtGetKm( void );
#endif /* #if (SWT_USE_VAL_COND_KM == SWT_CFG_ON) */

#if (SWT_USE_VAL_COND_OP_TIME == SWT_CFG_ON)
/**************************************************************************//**
 * Determines hours of operation.
 *
 * \return
 *		Number of hours vehicle was in operation.
 */
extern uint32 Appl_SwtGetOperatingHours( void );
#endif /* #if ( SWT_USE_VAL_COND_OP_TIME == SWT_CFG_ON ) */

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)
/**************************************************************************//**
 * Retrieves root certificate.
 *
 * For SWT Full the root certificate is used to verify FSCS certificates. The
 * root certificate must be stored in a protected memory region. The certificate
 * must be stored in DER format.
 *
 * \return
 *		Pointer to root certificate data.
 */
#ifdef DOXYGEN
extern const uint8* Appl_SwtGetRootCert( void );
#else
extern P2CONST(uint8,AUTOMATIC,SC_FAR) Appl_SwtGetRootCert( void );
#endif
#endif /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
/**************************************************************************//**
 * Retrieves ECU's private component for Diffie Hellman key exchange.
 *
 * This function is used for SWT Short only. The private component must be store
 * in protected memory.
 *
 * \return
 *		Pointer to ECU's private key data.
 */
#ifdef DOXYGEN
extern const Swt_LNWordType* Appl_SwtGetKeyEcu( void );
#else
extern P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Appl_SwtGetKeyEcu( void );
#endif

/**************************************************************************//**
 * Retrieves public modulus for Diffie-Hellman key exchange.
 *
 * This function is used for SWT Short only.
 *
 * \return
 *		Pointer to the modulus data.
 */
#ifdef DOXYGEN
extern const Swt_LNWordType* Appl_SwtGetModulus( void );
#else
extern P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Appl_SwtGetModulus( void );
#endif

#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
/**************************************************************************//**
 * Retrievs the barrett value for the given modulus
 *
 * This function is used for SWT Short only.
 *
 * \return
 *		Pointer to the barrett value.
 * 
 */
#ifdef DOXYGEN
extern const Swt_LNWordType* Appl_SwtGetBarrettValue( void );
#else
extern P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Appl_SwtGetBarrettValue( void );
#endif
#endif

/**************************************************************************//**
 * Retrieves Fsc and FscLength entered via HMI.
 *
 * This function is used for SWT Short only.
 *
 * \param SwId
 *		The software Id the FSC is for.
 * \param Fsc
 *    Pointer to an array where the FSC has to be stored.
 * \param FscLength
 *    Pointer to the FSCLength, holds the length of the given array,
 *    after copying the FSC to the FSC array, it should contain the actual length
 *    of the FSC.
 *    
 * \retval Swt_RC_OK
 *    If FSC contains a correct FSC
 * \retval Swt_RC_UNKNOWN_ERROR 
 *    If user aborts entering the FSC or something else happend, 
 *    so that there is no FSC in the array Fsc
 * 
 */
extern SwtRC_t Appl_SwtTriggerStoreFscFromMmi( CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId, 
                                               CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) Fsc, 
                                               CONSTP2VAR(uint16,AUTOMATIC,SC_FAR) FscLength );

/**************************************************************************//**
 * Triggers the Update of an SW which is secured by SWT Short
 *
 * This function is used for SWT Short only.
 *
 * \param SwId
 *		The software Id of the SW which should be updated.
 * \param IsUpdated
 *    Flag whether the update has taken place, 
 *    - TRUE: the SWT-Lib does a SW signature check, 
 *    - FALSE: the SWT-Lib does no signature check.
 *    
 * \retval Swt_RC_OK
 *       If SW update worked correct
 * \retval Swt_RC_UNKNOWN_ERROR
 *       If an error occured during SW update and no SW signatur 
 *       check has to be done.
 * 
 */
extern SwtRC_t Appl_SwtTriggerSwUpdate( CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId, 
                                        CONSTP2VAR(boolean,AUTOMATIC,SC_FAR) IsUpdated );

#if (SWT_USE_VAL_COND_SHORT_APPLICATION == SWT_CFG_ON)
/**************************************************************************//**
 * Only the application knows the exact structure of application validity
 * conditions in the FSC Short. Therefore the library passes any application 
 * conditions to the application through this function.
 *
 * This function is used for SWT Short only.
 *
 * \param Validity
 *		The validity bytes of the FSC
 * \param ValidityLength
 *    The number of validity bytes
 *    
 * \retval Swt_RC_OK
 *    If Validity is ok
 * \retval Swt_RC_UNKNOWN_ERROR
 *    If Validity is not ok
 * 
 */
extern SwtRC_t Appl_SwtShortFSCCheckValidity(CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Validity, 
                                             uint16 ValidityLength);
#endif

#if (SWT_USE_VAL_COND_SHORT_CURRENT_DATE == SWT_CFG_ON)
/**************************************************************************//**
 * Determines current date from the ECU
 *
 * \return
 *		Pointer to struct with current date
 */
extern SwtDateType Appl_SwtGetCurrentDate( void );
#endif /* #if ( SWT_USE_VAL_COND_SHORT_CURRENT_DATE == SWT_CFG_ON ) */
#endif /* #if (SWT_USE_SWT_SHORT == SWT_CFG_ON) */

#define SWT_STOP_SEC_CODE
#include "MemMap.h"


#endif                              /* if (!defined SWT_APPLSWT_H) */
/*** End of file **************************************************************/
