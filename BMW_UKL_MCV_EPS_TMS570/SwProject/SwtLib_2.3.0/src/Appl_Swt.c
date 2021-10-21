/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Appl_Swt.c                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definition of the platform specific functions.                **
**                                                                            **
**  REMARKS   : This file contains only dummy data. This data must be removed **
**              with real values for the SG implementation.                   **
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
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.9.0    : 28.11.2006, mg   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */

/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Aug 18 20:09:21 2012
* %version:          2 %
* %derived_by:       wz7x3j %
* %date_modified:    Sat Sep 29 17:22:12 2012 %
*---------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 09/29/12   2        BDO         SWT updates - anomaly 3782
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
                                 /* declaration of platform specific services */
#include "Swt_Common.h"

#include "Appl_Swt.h"
#include "Swt_RSA.h"                        /* declarations of rsa services */

#include "NvM.h"
#include "NvM_Cfg.h"

#include "sc_ee_data.h"        /* Contains extern declarations of structs     */
                               /* with non volatile bootloader data. They are */
                               /* accessed in the subsequent diagnostic       */
                               /* services.                                   */

#include "Bootloader_Cfg_HW.h"
#include "cr_c_comp_specific.h"
#include "AddressTable.h"

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define SWE_ID_OF_APPL_SWE1   SWENUMBEROFBOOTSWE
#define D_SWTSWEID_CNT_U8     SWE_ID_OF_APPL_SWE1

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/


/*******************************************************************************
**                      External Constants                                    **
*******************************************************************************/


/*******************************************************************************
**                      External Data                                         **
*******************************************************************************/


/*******************************************************************************
**                      Local Constants                                       **
*******************************************************************************/


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

STATIC P2VAR(uint32, AUTOMATIC, SC_FAR) SwSignaturePtr;
STATIC P2VAR(uint32, AUTOMATIC, SC_FAR) SwLengthPtr;
STATIC P2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) SwAddressesPtr;

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtWriteBlock                                        **
**                                                                            **
** DESCRIPTION    : Writes one block to a non-volatile memory.                **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : 'BlockId' The ID of the block.                            **
**                                                                            **
** RETURN         : Swt_RC_FLASH_WRITE_ERROR, if the write request has not    **
**                  been accepted.
**                  Swt_RC_OK, if all operations were successful              **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Appl_SwtWriteBlock( uint16 BlockId )
{
	uint16 block;    
	switch (BlockId)
    {
        case SWT_SW_DATA:
            block = NVM_SWT_SW;
            break;

#if (SWT_USE_SWT_FULL == SWT_CFG_ON)        
        case SWT_CERT_DATA:
            block = NVM_SWT_CERT;
            break;
#endif
        case SWT_SWSIG_DATA:
            block = NVM_SWT_SWSIG;
            break;

#if (SWT_SHORT_STORE == SWT_CFG_ON)
        case SWT_SHORT_DATA:
            block = NVM_SWT_SHORT;
            break;
#endif

        default:
            return Swt_RC_FLASH_WRITE_ERROR;
            break;
    }
    
	if(Swt_RC_OK == NvM_WriteBlock(block, NULL_PTR ) )
	{
		return Swt_RC_OK;
	}
	else
	{
		return Swt_RC_FLASH_WRITE_ERROR;
	}
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetPublicFscsKey                                  **
**                                                                            **
** DESCRIPTION    : Return the public key of the 'FSC-Stelle' necessary to    **
**                  verify the signature of the FSC.                          **
**                  If SWT_RSA_USE_BARRETT == SWT_CFG_ON is set               **
**                  fscsPublicKey.ModulusExt has to be set to 0;              **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     :  None                                                     **
**                                                                            **
** RETURN         :  The public key of the 'FSC-Stelle'.                      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2CONST(Swt_RSAKeyType,AUTOMATIC,SC_FAR) Appl_SwtGetPublicFscsKey
(
   void
)
{
#define SWT_START_SEC_CONST_32BIT
#include "MemMap.h"
    /* The following is a production public key and must be stored in protected memory to prevent manipulation. */
    static const Swt_LNWordType fscsPubKeyExp[] = { 0x00000001, 0x00000003  };

	static const Swt_LNWordType fscsPubKeyMod[] =
    {
        0x00000020,
        0xd669f803, 0x7480b155, 0x2ca63d21, 0xec17c6ad, 0x71c184bb, 0x9713b8ec, 0xd8341f3e, 0x8e189b4b,
        0xaf59f21f, 0x3bec800f, 0xb1df43bd, 0xac6fe290, 0x3c599738, 0x671057e1, 0x1b29a454, 0x7dc93bd0,
        0xd79da611, 0x1dce9738, 0xa65e54d3, 0x1af52a2a, 0x75dddaab, 0x5769ab0a, 0xe5b041ce, 0xf3f36907,
        0x3f36849c, 0x92ea4c57, 0x6435c278, 0x8072075b, 0x6d531079, 0xf78cf95c, 0x8cef3b1f, 0xf57090d4
    };

#define SWT_STOP_SEC_CONST_32BIT
#include "MemMap.h"

#define SWT_START_SEC_CONST_UNSPEC
#include "MemMap.h"
    static const Swt_RSAKeyType fscsPubKey = { fscsPubKeyExp, fscsPubKeyMod, 0 };
#define SWT_STOP_SEC_CONST_UNSPEC
#include "MemMap.h"

   return &fscsPubKey;

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetVinInternal                                    **
**                                                                            **
** DESCRIPTION    : Returns the unique VIN.                                   **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     :  None                                                     **
**                                                                            **
** RETURN         :  The unique VIN of the SG.                                **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2CONST(uint8,AUTOMATIC,SC_FAR)  Appl_SwtGetVinInternal
(
   void
)
{     
   /*
   static const uint8 vin[] =
   //{'W','B','A','K','A','4','1','0','0','0','T','S','P','V','P','0','2'};
   //{'W','B','A','K','A','4','1','0','0','0','H','0','0','2','5','8','3'};
   */

   static uint8 vin[sizeof(BootProgData.VIN)];
   
   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)vin,
                     (const void SC_FAR_POINTER)&BootProgData.VIN[0],
                     sizeof(BootProgData.VIN)
                    );  

   return vin;}

/******************************************************************************/
SwtRC_t Appl_SwtSetVinInternal( P2CONST(uint8,AUTOMATIC,SC_FAR) pVin )
{
    (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)BootProgData.VIN, (const void SC_FAR_POINTER)pVin, sizeof(BootProgData.VIN) );

    /* write data to nv memory */
    NvM_SetBlockProtection(NVM_BLOCK_BOOT_PROG_DATA, FALSE);  /* disable write protection that was set in Cdc_Common_Mandatory */

    if ( NvM_WriteBlock(NVM_BLOCK_BOOT_PROG_DATA, NULL_PTR) != NVM_REQ_OK )	//NXTR SWT if ( NvM_WriteBlock(NVM_DIAG_BOOTPROGDATA) != NVM_E_OK )
    {
        return Swt_RC_FGN_ACCESS_FAILURE;
    }
    
    NvM_SetBlockProtection(NVM_BLOCK_BOOT_PROG_DATA, TRUE); /* enable write protection after VIN write */
    /* it worked */
    return Swt_RC_OK;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetVinExternal                                    **
**                                                                            **
** DESCRIPTION    : Returns the unique VIN.                                   **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     :  None                                                     **
**                                                                            **
** RETURN         :  The unique VIN of the SG.                                **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2CONST(uint8,AUTOMATIC,SC_FAR)  Appl_SwtGetVinExternal
(
   void
)
{
   /*
   static const uint8 vin[] = 
   {'W','B','A','K','A','4','1','0','0','0','T','S','P','V','P','0','2'};
   //{'W','B','A','K','A','4','1','0','0','0','H','0','0','2','5','8','3'};
   */
   return Appl_SwtGetVinInternal();
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetSwBlockNumber                                  **
**                                                                            **
** DESCRIPTION    : Returns the number of blocks of data which comprise the   **
**                  software.                                                 **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : void                                                      **
**                                                                            **
** RETURN         : The number of data blocks of the software                 **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
uint32 Appl_SwtGetSwBlockNumber
(
   const uint8 SGID
)
{
	const uint8 tmpSweSignatureNumberAppl =
	      sharedBootROMData.SweSignaturNumberAppl[D_SWTSWEID_CNT_U8 - (uint8)SWE_ID_OF_APPL_SWE1];

	return (uint32)tmpSweSignatureNumberAppl;

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetSwAddresses                                    **
**                                                                            **
** DESCRIPTION    : Returns the start addresses of the blocks of data which   **
**                  comprise the software.                                    **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : 'SGID' The ID of the controller whose SW signature is to  **
**                         be checked.                                        **
**                                                                            **
** RETURN         : A pointer to the start of an array which contains the     **
**                  start addresses of the data blocks of the software        **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2VAR(P2CONST(uint8,AUTOMATIC,SC_FAR),AUTOMATIC,SC_FAR) Appl_SwtGetSwAddresses
(
   const uint8 SGID
)
{
	const uint8 tmpSweSignaturIndexAppl =
		      sharedBootROMData.SweSignaturIndexAppl[D_SWTSWEID_CNT_U8 - (uint8)SWE_ID_OF_APPL_SWE1];

	SwAddressesPtr = (const uint8**)&sharedBootROMData.SignatureSweDataPtr[tmpSweSignaturIndexAppl];

	return (SwAddressesPtr);

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetSwLengths                                      **
**                                                                            **
** DESCRIPTION    : Returns the lengths of the blocks of data which           **
**                  comprise the software.                                    **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : 'SGID' The ID of the controller whose SW signature is to  **
**                         be checked.                                        **
**                                                                            **
** RETURN         : A pointer to the start of an array which contains the     **
**                  lengths of the data blocks of the software                **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2VAR(uint32,AUTOMATIC,SC_FAR) Appl_SwtGetSwLengths
(
   const uint8 SGID
)
{
	const uint8 tmpSweSignaturIndexAppl =
		      sharedBootROMData.SweSignaturIndexAppl[D_SWTSWEID_CNT_U8 - (uint8)SWE_ID_OF_APPL_SWE1];

	SwLengthPtr = (CR_fp_uint32)&sharedBootROMData.SignatureSweDataLength[tmpSweSignaturIndexAppl];

	return(SwLengthPtr);

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetSwSignature                                    **
**                                                                            **
** DESCRIPTION    : Returns the signature of the software.                    **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : 'SGID' The ID of the controller whose SW signature is to  **
**                         be checked.                                        **
**                                                                            **
** RETURN         : A pointer to the start of an array which contains the     **
**                  signature of the software                                 **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2VAR(uint32,AUTOMATIC,SC_FAR) Appl_SwtGetSwSignature
(
   const uint8 SGID
)
{
	SwSignaturePtr = (CR_fp_uint32)(sharedBootROMData.PointerToSweTable[D_SWTSWEID_CNT_U8]->SweSignature);

	return (SwSignaturePtr);

}




/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtParseAppCond                                      **
**                                                                            **
** DESCRIPTION    : Parses a application specific validity condition (AppGB). **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     : 'AppGB' A pointer to the start of the validity condition  **
**                                                                            **
** RETURN         : Swt_RC_INVALID_FSC, if the validity condition could not   **
**                                        be parsed                           **
**                  Swt_RC_OK, if all operations were successful              **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Appl_SwtParseAppCond
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) AppGB
)
{
   return Swt_RC_OK;
}



/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetMinutes                                        **
**                                                                            **
** DESCRIPTION    : Compute the amount of minutes since January 1, 2000.      **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETER      : void                                                      **
**                                                                            **
** RETURN         : The minutes elapsed between the 1.1.2000 and the current  **
**                  date.                                                     **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
uint32 Appl_SwtGetMinutes
(
   void
)
{
   return 0;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetKm                                             **
**                                                                            **
** DESCRIPTION    : Compute the amount of KM the car has travelled.           **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETER      : void                                                      **
**                                                                            **
** RETURN         : The KM the car has travelled.                             **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
uint32 Appl_SwtGetKm
(
   void
)
{
   return 0;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetOperatingHours                                 **
**                                                                            **
** DESCRIPTION    : Compute the amount of KM the car has travelled.           **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETER      : void                                                      **
**                                                                            **
** RETURN         : The KM the car has travelled.                             **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
uint32 Appl_SwtGetOperatingHours
(
   void
)
{
   return 0;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtTellAppCond                                       **
**                                                                            **
** DESCRIPTION    : Tell the application whether the application validity     **
**                  condition is in a valid group or not.                     **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETER      : 'AppGB' A pointer to the start of the validity condition  **
**                  'GroupIsValid', tells whether the group is valid or not   **
**                                                                            **
** RETURN         : The KM the car has travelled.                             **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
void Appl_SwtTellAppCond
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) AppGB,
   const SwtRC_t                      GroupIsValid
)
{
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetRootCert                                       **
**                                                                            **
** DESCRIPTION    : Returns a pointer to the root certificate.                **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     :  None                                                     **
**                                                                            **
** RETURN         :  The root certificate.                                    **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2CONST(uint8,AUTOMATIC,SC_FAR)  Appl_SwtGetRootCert
(
   void
)
{
    /* production root certificate for BMW root CA, must be located in protected memory to prevent manipulation */
    static const uint8 rootCert[] = 
    {
        0x30, 0x82, 0x03, 0x72, 0x30, 0x82, 0x02, 0x5a, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x02, 0x03,
        0xe9, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x04, 0x05, 0x00,
        0x30, 0x69, 0x31, 0x13, 0x30, 0x11, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64,
        0x01, 0x19, 0x16, 0x03, 0x63, 0x6f, 0x6d, 0x31, 0x18, 0x30, 0x16, 0x06, 0x0a, 0x09, 0x92, 0x26,
        0x89, 0x93, 0xf2, 0x2c, 0x64, 0x01, 0x19, 0x16, 0x08, 0x62, 0x6d, 0x77, 0x67, 0x72, 0x6f, 0x75,
        0x70, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x70, 0x6b, 0x69, 0x31,
        0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x0b, 0x62, 0x6d, 0x77, 0x2d, 0x66, 0x7a,
        0x67, 0x2d, 0x70, 0x6b, 0x69, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0b,
        0x66, 0x7a, 0x67, 0x2d, 0x72, 0x6f, 0x6f, 0x74, 0x2d, 0x63, 0x61, 0x30, 0x1e, 0x17, 0x0d, 0x30,
        0x32, 0x30, 0x39, 0x31, 0x39, 0x31, 0x33, 0x31, 0x30, 0x32, 0x34, 0x5a, 0x17, 0x0d, 0x32, 0x37,
        0x30, 0x39, 0x32, 0x30, 0x31, 0x33, 0x31, 0x30, 0x32, 0x34, 0x5a, 0x30, 0x69, 0x31, 0x13, 0x30,
        0x11, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64, 0x01, 0x19, 0x16, 0x03, 0x63,
        0x6f, 0x6d, 0x31, 0x18, 0x30, 0x16, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64,
        0x01, 0x19, 0x16, 0x08, 0x62, 0x6d, 0x77, 0x67, 0x72, 0x6f, 0x75, 0x70, 0x31, 0x0c, 0x30, 0x0a,
        0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x70, 0x6b, 0x69, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03,
        0x55, 0x04, 0x0b, 0x13, 0x0b, 0x62, 0x6d, 0x77, 0x2d, 0x66, 0x7a, 0x67, 0x2d, 0x70, 0x6b, 0x69,
        0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0b, 0x66, 0x7a, 0x67, 0x2d, 0x72,
        0x6f, 0x6f, 0x74, 0x2d, 0x63, 0x61, 0x30, 0x82, 0x01, 0x20, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
        0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0d, 0x00, 0x30, 0x82,
        0x01, 0x08, 0x02, 0x82, 0x01, 0x01, 0x00, 0x94, 0xeb, 0x3f, 0x69, 0xa6, 0x90, 0x6c, 0x9d, 0xf9,
        0xc6, 0xf1, 0x71, 0x89, 0x98, 0x79, 0x12, 0x20, 0xfd, 0xd6, 0xd8, 0x7c, 0xd4, 0x83, 0x98, 0x62,
        0x7e, 0xa5, 0xbf, 0xee, 0xa2, 0xd1, 0x98, 0xc4, 0xef, 0x6c, 0xa2, 0xb7, 0x8f, 0xfe, 0x5c, 0x06,
        0x72, 0x84, 0x53, 0x78, 0xa8, 0x3c, 0x5e, 0xe8, 0xa8, 0x71, 0x00, 0x7e, 0x09, 0x18, 0xd2, 0x89,
        0x04, 0x7e, 0x36, 0x75, 0x8a, 0x2b, 0x34, 0xf5, 0x42, 0xcb, 0xcf, 0x8f, 0x82, 0x34, 0x15, 0x22,
        0x7e, 0x54, 0xa5, 0xd8, 0x69, 0x99, 0x83, 0x7b, 0x36, 0xf8, 0x87, 0xc3, 0xb9, 0x45, 0x0b, 0x9f,
        0xdd, 0x60, 0xe3, 0xad, 0x48, 0x60, 0xb8, 0xeb, 0xd7, 0x8e, 0x0c, 0xf9, 0x05, 0x83, 0x13, 0x2a,
        0x44, 0x06, 0xbb, 0xb1, 0x72, 0x05, 0x7e, 0x9d, 0x0f, 0xe7, 0x69, 0xf4, 0x39, 0xf4, 0x1d, 0xae,
        0x27, 0x30, 0x57, 0x0f, 0xdd, 0xcc, 0x07, 0xad, 0x5a, 0xe0, 0x8e, 0x10, 0x30, 0x5f, 0xf3, 0x61,
        0x3d, 0x90, 0x9b, 0x3a, 0xcc, 0xc4, 0x04, 0x6c, 0x4f, 0xcd, 0x6b, 0xdd, 0xcb, 0xe9, 0xc3, 0xff,
        0x4b, 0x1c, 0x3a, 0x4e, 0xf8, 0xd1, 0xe7, 0x13, 0x96, 0x09, 0x02, 0x1d, 0xd7, 0x67, 0x85, 0x49,
        0x14, 0x6c, 0x28, 0xf4, 0xdd, 0x73, 0xcb, 0xbd, 0x5d, 0x7d, 0x08, 0x68, 0x58, 0x89, 0x8d, 0x46,
        0x60, 0x8c, 0xd1, 0x23, 0xf5, 0xf2, 0x98, 0x1a, 0xf5, 0x56, 0xf7, 0x2c, 0x03, 0x91, 0xe2, 0xd1,
        0xba, 0x75, 0x48, 0xb8, 0x5e, 0x81, 0xd5, 0x16, 0x4e, 0xd0, 0x35, 0xbb, 0xc6, 0xbf, 0x1e, 0xaf,
        0xaf, 0x2b, 0x8c, 0x0d, 0xb6, 0x4d, 0x21, 0x46, 0x2a, 0x6d, 0x1b, 0x7d, 0xcc, 0xd0, 0xf1, 0xb6,
        0x61, 0x6b, 0x6f, 0xeb, 0x59, 0x9f, 0xa8, 0x4d, 0x11, 0x7b, 0x6b, 0x5f, 0xd6, 0x83, 0xb3, 0xa6,
        0x52, 0x28, 0xd1, 0x4a, 0xbe, 0xc2, 0x8f, 0x02, 0x01, 0x03, 0xa3, 0x26, 0x30, 0x24, 0x30, 0x12,
        0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x08, 0x30, 0x06, 0x01, 0x01, 0xff, 0x02,
        0x01, 0x00, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02,
        0x01, 0x06, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x04, 0x05,
        0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0x8e, 0x50, 0x18, 0x89, 0x4a, 0x2a, 0x7d, 0x4d, 0x89, 0x2c,
        0xdb, 0x52, 0xb1, 0x5b, 0xa8, 0x64, 0x2a, 0x72, 0x54, 0xcc, 0x15, 0xc2, 0x90, 0xd4, 0x60, 0x66,
        0x60, 0xe3, 0xca, 0x5e, 0x62, 0x19, 0xa0, 0xc3, 0x42, 0xa3, 0xcb, 0x0c, 0xfb, 0x17, 0x8b, 0xd8,
        0x53, 0x2d, 0x86, 0xc4, 0x6e, 0x71, 0xf3, 0xa2, 0x3e, 0xfd, 0x88, 0x78, 0x23, 0x34, 0xd4, 0xba,
        0xe7, 0xc7, 0xfe, 0x4d, 0x16, 0xd0, 0xef, 0x11, 0x86, 0x5c, 0x98, 0xa8, 0x4b, 0x3c, 0x34, 0x0f,
        0xca, 0x45, 0xc5, 0x21, 0x20, 0xd6, 0x05, 0x6d, 0x7f, 0xa6, 0xa7, 0xd8, 0xb9, 0x47, 0x58, 0xc4,
        0x95, 0x5b, 0xc8, 0xa7, 0xf3, 0xee, 0xd0, 0x2c, 0x94, 0x93, 0x9c, 0x79, 0x10, 0x25, 0xa8, 0x31,
        0xc2, 0xfc, 0xe9, 0x52, 0x68, 0x29, 0x0a, 0x01, 0x7a, 0x26, 0xa2, 0x1d, 0x17, 0x88, 0xf8, 0xb2,
        0x54, 0xb4, 0x1f, 0xee, 0xed, 0x21, 0x28, 0xf3, 0x16, 0x74, 0x83, 0x0c, 0xc1, 0xbb, 0x7c, 0x3b,
        0xfd, 0xf4, 0x3f, 0x4d, 0xf9, 0x05, 0xbb, 0xc4, 0xe4, 0x68, 0x06, 0x99, 0xaa, 0x1b, 0x05, 0xb1,
        0x0e, 0xa5, 0x97, 0x2d, 0xc1, 0x88, 0x37, 0x41, 0x4e, 0x3c, 0x1a, 0x4d, 0xa7, 0xda, 0xe5, 0x2c,
        0x77, 0xcd, 0x63, 0x18, 0xae, 0xb6, 0x70, 0x26, 0x36, 0xd6, 0x0a, 0x32, 0xab, 0x3e, 0xdd, 0x4d,
        0xce, 0x8c, 0xea, 0x9a, 0x9e, 0x4f, 0xef, 0x30, 0x04, 0xa3, 0xce, 0x6a, 0x60, 0xc4, 0x67, 0x86,
        0x73, 0x10, 0x96, 0xb5, 0x0e, 0xc7, 0xe8, 0x48, 0x2c, 0x55, 0xb7, 0x6e, 0x80, 0x8c, 0x09, 0x1d,
        0x92, 0xf1, 0x29, 0xb3, 0x5f, 0x0b, 0xa3, 0xf2, 0x9f, 0x5c, 0x7f, 0x56, 0xb6, 0x4e, 0x4c, 0xcd,
        0x78, 0xf6, 0x8d, 0x4d, 0x72, 0x31, 0x29, 0x02, 0x03, 0x4c, 0xdc, 0x63, 0xc4, 0xed, 0x2a, 0x3b,
        0xbb, 0x47, 0x11, 0xea, 0xad, 0x0d
    };

   return rootCert;
}

#if (SWT_USE_SWT_SHORT == SWT_CFG_ON) 
/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetKeyEcu                                         **
**                                                                            **
** DESCRIPTION    : Returns a pointer to the controller key for SWT short.    **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     :  None                                                     **
**                                                                            **
** RETURN         :  The controller key "K_SG".                               **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Appl_SwtGetKeyEcu( void )
{
   static const Swt_LNWordType ksg[]    
      ={16,
        0x7862, 0xB84C, 0x3766, 0x4FDE, 0xF8E8, 0x80BE, 0x6027, 0x2E80, 
        0x1FBD, 0xDDEC, 0x3D99, 0x6F96, 0x213D, 0x2F18, 0xA7C7, 0x862F};
   return ksg;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Appl_SwtGetModulus                                        **
**                                                                            **
** DESCRIPTION    : Returns a pointer to the public modulus for SWT short.    **
**                                                                            **
** PRECONDITIONS  :                                                           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETERS     :  None                                                     **
**                                                                            **
** RETURN         :  The public modulus "Y".                                  **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
*******************************************************************************/
P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Appl_SwtGetModulus( void )
{
#define SWT_MODULUS_NR_OF_LN_WORDS 0x40

#if!(SWT_DIFFIE_KEY_LEN_BYTES == (SWT_MODULUS_NR_OF_LN_WORDS * SWT_LN_WORD_LEN_BYTES))
   #error("Configuration error")
#endif

   static const Swt_LNWordType modulus[] 
      = {SWT_MODULUS_NR_OF_LN_WORDS,
         0x5127, 0xFFEF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
         0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
         0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
         0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
         0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
         0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
         0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};

   return modulus;
}

#if (SWT_RSA_USE_BARRETT == SWT_CFG_ON)
/******************************************************************************/
P2CONST(Swt_LNWordType,AUTOMATIC,SC_FAR) Appl_SwtGetBarrettValue( void )
{
   static const Swt_LNWordType barrett[] =
     {0x41,
      0xAED9, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,        
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,        
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,        
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,        
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,        
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,        
      0x0000, 0x0000, 0x0000, 0x0000, 0x0001 };

   return barrett;
}
#endif

/******************************************************************************/
uint8 fscNumber = 0;
SwtRC_t Appl_SwtTriggerStoreFscFromMmi( CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId, 
                                        CONSTP2VAR(uint8,AUTOMATIC,SC_FAR) Fsc, 
                                        CONSTP2VAR(uint16,AUTOMATIC,SC_FAR) FscLength )
{
   SwtRC_t retVal = Swt_RC_OK;
   static const uint8 NewFsc0[] = {'Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y','Y'};

      
   *FscLength = 20;
      Swt_CommonCopy(Fsc, NewFsc1, (uint32)*FscLength);
   return retVal;
}

/******************************************************************************/
SwtRC_t Appl_SwtTriggerSwUpdate( CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) SwId, CONSTP2VAR(boolean,AUTOMATIC,SC_FAR) IsUpdated)
{
	SwtRC_t retVal = Swt_RC_OK;
   *IsUpdated = TRUE;
   return retVal;
}

/******************************************************************************/
SwtRC_t Appl_SwtShortFSCCheckValidity(CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Validity, uint16 ValidityLength)
{
   return Swt_RC_OK;
}

#if (SWT_USE_VAL_COND_CURRENT_DATE == SWT_CFG_ON)
SwtDateType Appl_SwtGetCurrentDate( void )
{
   SwtDateType curDate;
   curDate.day   =   1;
   curDate.month =   13;
   curDate.year  = 2015;
   return curDate;
}
#endif /* #if(SWT_USE_VAL_COND_CURRENT_DATE == SWT_CFG_ON)*/

#endif /* #if (SWT_USE_SWT_SHORT == SWT_CFG_ON) */


#define SWT_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/




/*** End of file **************************************************************/
