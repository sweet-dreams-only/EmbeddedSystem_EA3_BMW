/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swe.c                                                         **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : SWE access functions                                          **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** hauf         Hauf Andreas               EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.0.0: 07.07.2009, dabu: CR61622: mapping of external API
 * V1.0.0: 03.06.2009, hauf: CR61622: initial version
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "v_cfg.h"
#include "Std_Types.h"          /* Autosar standard types                     */
#include "Swe_Cfg.h"            /* Swe configuration file                     */
#include "Swe.h"                /* include own header file                    */


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

#ifdef BOOTMANAGER
   #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( SC_HANDLE_ECC == STD_ON )

      #define Swe_GetErrorCheckDoneFlagOfSwe( sweId )                          \
         ( GET_BIT_IN_MULTI_BYTE_BIT_ARRAY( sweErrorCheckDone, sweId ) != 0u )
      #define Swe_SetErrorCheckDoneFlagOfSwe( sweId )                          \
         SET_BIT_IN_MULTI_BYTE_BIT_ARRAY( sweErrorCheckDone, sweId )
      #define Swe_ClearErrorCheckDoneFlagOfSwe( sweId )                        \
         CLEAR_BIT_IN_MULTI_BYTE_BIT_ARRAY( sweErrorCheckDone, sweId )

      #ifndef CRC_INCREMENT_MULTIPLICATOR
         #define CRC_INCREMENT_MULTIPLICATOR   1
      #endif

   #endif
#endif


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#ifdef BOOTMANAGER
   #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( SC_HANDLE_ECC == STD_ON )

      uint8 sweErrorCheckDone[
           CALC_REQUIRED_BYTES_FOR_MULTI_BYTE_BIT_ARRAY( BM_MAX_NUMBER_OF_SWES )
                             ];
                                            /* 0 = CRC of SWE not checked yet */
                                            /* 1 = CRC of SWE already checked */
                                            /* Bit 0: Bootloader SWE          */
                                            /* Bit 1: Application SWE 1       */
                                            /* ...                            */
                                            /* Bit n: Application SWE n       */
   #endif
#endif


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#ifdef BOOTMANAGER
   #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( SC_HANDLE_ECC == STD_ON )
      #ifdef BAC
         static FUNC(void, COMMON_CODE) Swe_GetAddressOfFlashSegmentContainingValidFlag
                (
                   VAR(uint8, COMMON_APPL_DATA) sweId,
                   P2VAR(flashAddress_t, AUTOMATIC, COMMON_APPL_DATA) segmentStartAddress,
                   P2VAR(flashAddress_t, AUTOMATIC, COMMON_APPL_DATA) segmentEndAddress
                );
      #else
      static void Swe_GetAddressOfFlashSegmentContainingValidFlag
                  (
                     uint8 sweId,
                     flashAddress_t *segmentStartAddress,
                     flashAddress_t *segmentEndAddress
                  );
      #endif /* Defined BAC */
   #endif
#endif


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Swe_GetAddressOfFlashSegmentContainingValidFlag            **
**                                                                            **
** DESCRIPTION   : This function returns the flash segment that contains      **
**                 the valid flag                                             **
**                                                                            **
** PRECONDITIONS : This function may not be used if no bootloader is present  **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData                                          **
**                                                                            **
** PARAMETER     : sweId               : Number of SWE to search              **
**                 pSegmentStartAddress: pointer to RAM value to return the   **
**                                       start address of the flash segment   **
**                 pSegmentEndAddress  : pointer to RAM value to return the   **
**                                       end address of the flash segment     **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BOOTMANAGER
   #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( SC_HANDLE_ECC == STD_ON )
      #ifdef BAC
         static FUNC(void, COMMON_CODE) Swe_GetAddressOfFlashSegmentContainingValidFlag
                (
                   VAR(uint8, COMMON_APPL_DATA) sweId,
                   P2VAR(flashAddress_t, AUTOMATIC, COMMON_APPL_DATA) segmentStartAddress,
                   P2VAR(flashAddress_t, AUTOMATIC, COMMON_APPL_DATA) segmentEndAddress
                )
      #else
static void Swe_GetAddressOfFlashSegmentContainingValidFlag
     (
        uint8 sweId,
        flashAddress_t *segmentStartAddress,
        flashAddress_t *segmentEndAddress
     )
      #endif /* Defined BAC */
{
   boolean flashSegmentFound = FALSE;

                                            /* get valid flag address of SWE  */
   const flashAddress_t sweValidFlagAddress = ConvertIntPointer2ExtAddress
         ( sharedBootROMData.PointerToSweFlashStatus[ sweId ]->SweValidFlag );

                                  /* iterate all flash segments of SWE        */
   uint8_least flashSegmentId = 0;
   do
   {
                                            /* address of flash segment       */
      *segmentStartAddress = sharedBootROMData.MemSegTable[ flashSegmentId ][ 0 ];
      *segmentEndAddress   = sharedBootROMData.MemSegTable[ flashSegmentId ][ 1 ];

                                  /* if the flash segment contains the valid  */
                                  /* flag of the SWE                          */
      if ( (sweValidFlagAddress >= *segmentStartAddress) &&
           (sweValidFlagAddress <= *segmentEndAddress  ) )
      {
                                            /* return found addresses         */
         flashSegmentFound = TRUE;
      }

      ++flashSegmentId;

   } while ( ( flashSegmentFound == FALSE ) &&
             ( flashSegmentId < (uint8_least)sharedBootROMData.FlashSegmentNumberAll ) );
}

   #endif /* ( SC_VERIFY_SWE_CRC_CHKSUM == ON ) || ( SC_HANDLE_ECC == ON )    */
#endif /* defined BOOTMANAGER                                                 */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Swe_InitErrorFlagsOfAllSwes                                **
**                                                                            **
** DESCRIPTION   : This function clears the CRC and/or ECC error flags of all **
**                 SWEs                                                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : BootStatus                                                 **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BOOTMANAGER
   #if ( SC_HANDLE_ECC == STD_ON ) || ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
      #ifdef BAC
         FUNC(void, COMMON_CODE) Swe_InitErrorFlagsOfAllSwes( void )
      #else
void Swe_InitErrorFlagsOfAllSwes( void )
      #endif /* Defined BAC */
{
                                  /* iterate all bytes of error flags         */
   uint8_least byte;
   for ( byte = 0;
         byte < CALC_REQUIRED_BYTES_FOR_MULTI_BYTE_BIT_ARRAY( BM_MAX_NUMBER_OF_SWES );
         byte++ )
   {
      #if ( SC_HANDLE_ECC == STD_ON )
                                            /* init ECC error flags           */
         BootStatus.EccError[ byte ] = 0x00u;
      #endif
      #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
                                            /* init CRC error flags           */
         BootStatus.CrcError[ byte ] = 0x00u;
                                            /* init error check done flags    */
         sweErrorCheckDone[ byte ] = 0x00u;
      #endif
   }
}

   #endif /* ( SC_HANDLE_ECC == ON ) || ( SC_VERIFY_SWE_CRC_CHKSUM == ON )    */
#endif /* defined BOOTMANAGER                                                 */


#if ( defined BOOTMANAGER ) || ( defined BOOTLOADER )

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Swe_GetValidStateOfSwe                                     **
**                                                                            **
** DESCRIPTION   : This function checks if it is safe to access               **
**                 code/data of a SWE in ROM.                                 **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : BootStatus                                                 **
**                 sharedBootROMData                                          **
**                 Swe1FlashStatus                                            **
**                 Swe1Table                                                  **
**                                                                            **
** PARAMETER     : sweId: Number of SWE to check                              **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : SWE_VALID_STATE_INVALID:                                   **
**                    SWE is invalid and it's ROM area may not be accessed!   **
**                    This is because one of the checks failed (see REMARKS)  **
**                 SWE_VALID_STATE_VALID_SWFL:                                **
**                    SWE is a valid application SWE                          **
**                 SWE_VALID_STATE_VALID_BTLD:                                **
**                    SWE1 is a valid BLU SWE                                 **
**                 SWE_VALID_STATE_UNCHECKED:                                 **
**                    SWE has not been signature checked yet                  **
**                                                                            **
** REMARKS       : This function does the following in this order:            **
**                 - check ECC status (only if ECC check is enabled)          **
**                 - check CRC status (only if CRC check is enabled)          **
**                 - check valid flag of SWE in ROM                           **
**                 - check process class of SWE in ROM                        **
**                                                                            **
**                 In Bootmanager additional error checks are performed:      **
**                 - check CRC of flash segment which contains the valid flag **
**                   to ensure integrity after power failure during flashing  **
**                   (only if CRC check is enabled and has not been done yet) **
**                 - check if an ECC error occured while accessing the SWE    **
**                   (only if ECC check is enabled and has not been done yet) **
**                                                                            **
**                 In Bootloader additional checks are performed:             **
**                 - if valid flag is invalid check if it is blank            **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(SweValidStateType, COMMON_CODE) Swe_GetValidStateOfSwe
                                     (
									    VAR(uint8, COMMON_APPL_DATA) sweId 
									 )
#else
SweValidStateType Swe_GetValidStateOfSwe
                  (
                     uint8 sweId 
                  )
#endif /* Defined BAC */
{
   SweValidStateType validStateOfSwe = SWE_VALID_STATE_INVALID;

#if ( SC_HANDLE_ECC == STD_ON )
                                  /* if no ECC error occured in this SWE      */
   if ( Swe_GetEccErrorFlagOfSwe( sweId ) == FALSE )
   {
#endif
      uint8 const SC_FAR_POINTER pSweValidFlag;
      uint16 sweValidFlag;
#ifdef BOOTMANAGER
                                  /* if SWE is not first application SWE      */
      if ( sweId != SWE_ID_OF_APPL_SWE1 )
      {
#endif
                                            /* read valid flag of SWE from    */
                                            /* ROM by using address from      */
                                            /* bootloader (sharedBootROMData) */
         pSweValidFlag = sharedBootROMData.PointerToSweFlashStatus[ sweId ]->SweValidFlag;

#ifdef BOOTMANAGER
      }
      else
      {
                                            /* read valid flag of first appl  */
                                            /* SWE from ROM by using          */
                                            /* preconfigured address, because */
                                            /* bootloader may not be present  */
                                            /* in case of unfinished BLU      */
         pSweValidFlag = Swe1FlashStatus.SweValidFlag;
      }
#endif
#if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
                                  /* if no CRC error occured in this SWE      */
      if ( Swe_GetCrcErrorFlagOfSwe( sweId ) == FALSE )
      {
#endif
         sweValidFlag = Make16Bit( pSweValidFlag[0], pSweValidFlag[1] );

                                  /* if valid flag of SWE is ok               */
         if ( sweValidFlag == VALID_FLAG_SWE_VALID )
         {
            ProcessClassType processClassOfSwe;

                                  /* if SWE is application SWE1               */
            if ( sweId == SWE_ID_OF_APPL_SWE1 )
            {
                                            /* get process class from         */
                                            /* preconfigured address          */
               processClassOfSwe = (ProcessClassType)Swe1Table.SgbmId[0];
            }
                                  /* if SWE is not application SWE1           */
            else
            {
                                            /* get process class from address */
                                            /* table (sharedBootROMData)      */
               processClassOfSwe = (ProcessClassType)
                  sharedBootROMData.PointerToSweTable[ sweId ] -> SgbmId[0];
            }

                                  /* if process class of application SWE1     */
                                  /* or boot SWE is 'BTLD'                    */
            if ( ( sweId <= SWE_ID_OF_APPL_SWE1 ) &&
                 ( processClassOfSwe == PROCESSCLASS_BTLD ) )
            {
                                            /* found valid BL or BLU SWE      */
               validStateOfSwe = SWE_VALID_STATE_VALID_BTLD;
            }
                                  /* if process class of application SWE is   */
                                  /* 'SWFL'                                   */
            else if ( ( sweId >= SWE_ID_OF_APPL_SWE1 ) &&
                      ( processClassOfSwe == PROCESSCLASS_SWFL ) )
            {
                                            /* found valid application SWE    */
               validStateOfSwe = SWE_VALID_STATE_VALID_SWFL;
            }

                                  /* perform additional CRC and ECC error     */
                                  /* checks in bootmanager only               */
#if ( defined BOOTMANAGER )
   #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( SC_HANDLE_ECC == STD_ON )
                                  /* if additional error check not done yet   */
            if ( ( validStateOfSwe != SWE_VALID_STATE_INVALID ) &&
                 ( Swe_GetErrorCheckDoneFlagOfSwe( sweId ) == FALSE ) )
               {
      #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
                                            /* variables needed for CRC check */
               const uint8 SC_FAR_POINTER       pCrcInfoInRom;
               flashAddress_t                   segmentStartAddress;
               flashAddress_t                   segmentEndAddress;
               const uint8 SC_FAR_POINTER       pCrcBlockStepArray;
               uint8                            signatureSize;
               P2CONST(uint8,AUTOMATIC,CRC_APPL_DATA)      pCurrentPosition;
               P2CONST(uint8,AUTOMATIC,CRC_APPL_DATA)      pCrcCheckAreaEnd;
         #if ( SC_HANDLE_ECC == STD_ON )
               P2CONST(uint8,AUTOMATIC,CRC_APPL_DATA)      pSegmentEnd;
         #endif
               uint32                                      crcValueInRom;
               uint32                                      crcValue;
               uint8_least                                 currentBlockStepIndex;
               boolean                                     currentDataPointerOverflow;

                                  /* if SWE1 is a BLU                         */
               if ( ( sweId == SWE_ID_OF_APPL_SWE1 ) &&
                    ( processClassOfSwe == PROCESSCLASS_BTLD ) )
               {
                                            /* get information for CRC check  */
                                            /* directly from BLU, because     */
                                            /* bootloader may not be present  */
                                            /* in case of unfinished BLU      */
                  pCrcInfoInRom       = Swe1FlashStatus.SweCrcCheckSum;

                  segmentStartAddress = Make32Bit( pCrcInfoInRom[  4 ],
                                                   pCrcInfoInRom[  5 ],
                                                   pCrcInfoInRom[  6 ],
                                                   pCrcInfoInRom[  7 ] );
                  segmentEndAddress   = Make32Bit( pCrcInfoInRom[  8 ],
                                                   pCrcInfoInRom[  9 ],
                                                   pCrcInfoInRom[ 10 ],
                                                   pCrcInfoInRom[ 11 ] );
                  pCrcBlockStepArray  =           &pCrcInfoInRom[ 12 ];
                  signatureSize       =            pCrcInfoInRom[ 14 ];
               }
                                  /* if SWE is not a BLU                      */
               else
               {
                                            /* get information for CRC check  */
                                            /* from bootloader ROM            */
                                            /* (sharedBootROMData)            */
                  pCrcInfoInRom       =
                     sharedBootROMData.PointerToSweFlashStatus[ sweId ]->SweCrcCheckSum;

                  Swe_GetAddressOfFlashSegmentContainingValidFlag( sweId,
                                                                   &segmentStartAddress,
                                                                   &segmentEndAddress );
                  pCrcBlockStepArray  = sharedBootROMData.CrcBlockStep;
                  signatureSize       = sharedBootROMData.SignatureSize;
               }

                                            /* set pointer to start of segment*/
                                            /* containing the SWE valid flag  */
               pCurrentPosition = (P2CONST(uint8,AUTOMATIC,CRC_APPL_DATA))
                  ConvertExtAddress2IntPointer( segmentStartAddress );

                                            /* get pointer to end of CRC      */
                                            /* check area (SgbmId)            */
               pCrcCheckAreaEnd = (P2CONST(uint8,AUTOMATIC,CRC_APPL_DATA))
                  ConvertExtAddress2IntPointer( (uint32)( segmentEndAddress
                                                          - BM_CRC_CALC_BLOCK_LENGTH
                                                          - SWE_FLASH_STATUS_AREA_LENGTH
                                                          - MAX_XWE_DEV_INFO_LENGTH
                                                          - signatureSize
                                                          - SGBM_ID_LENGTH
                                                          + 1uL ) );

                                            /* get stored CRC from SWE in ROM */
               crcValueInRom = Make32Bit( pCrcInfoInRom[ 0 ],
                                          pCrcInfoInRom[ 1 ],
                                          pCrcInfoInRom[ 2 ],
                                          pCrcInfoInRom[ 3 ] );

                                            /* initialize calculated CRC      */
               crcValue = (uint32)0xFFFFFFFFuL;

                                            /* initialize block step index    */
               currentBlockStepIndex = 0u;

                                            /* initialize overflow indication */
               currentDataPointerOverflow = FALSE;

                                            /* trigger watchdog before CRC    */
                                            /* check to avoid watchdog reset  */
               SWE_WatchdogTrigger();

                                  /* iterate all bytes from start of flash    */
                                  /* segment to start of SgbmId. This area    */
                                  /* is part of the CRC check                 */
               while ( ( pCurrentPosition <= pCrcCheckAreaEnd ) &&
                       ( currentDataPointerOverflow == FALSE  ) )
               {
                  P2CONST(uint8,AUTOMATIC,CRC_APPL_DATA) pNextPosition;

                                            /* add current byte to checksum   */
                  crcValue = Crc_CalculateCRC32 ( pCurrentPosition,
                                                  (uint32)BM_CRC_CALC_BLOCK_LENGTH,
                                                  crcValue );

                                            /* revert checksum                */
                  crcValue ^= (uint32)0xFFFFFFFFuL;

                                            /* get next position from         */
                                            /* pCrcBlockStepArray             */
                  pNextPosition = pCurrentPosition +
                    ( (uint32)pCrcBlockStepArray[ currentBlockStepIndex + 1u ] + 1u ) *
                      (uint32)CRC_INCREMENT_MULTIPLICATOR;

                                  /* if overflow at end of address space      */
                  if ( pNextPosition < pCurrentPosition )
                  {
                                            /* reached end                    */
                     currentDataPointerOverflow = TRUE;
                  }
                                  /* if no overflow accured                   */
                  else
                  {
                                            /* set next position              */
                     pCurrentPosition = pNextPosition;

                                            /* increment block step index     */
                     currentBlockStepIndex  =
                        (uint8_least)( ( (uint8_least)( currentBlockStepIndex + 1u ) ) %
                                         (uint8_least)pCrcBlockStepArray[ 0 ] );
                  }
               }

                                            /* complete CRC calculation       */
               crcValue ^= (uint32)0xFFFFFFFFuL;

                                            /* trigger watchdog after CRC     */
                                            /* check to avoid watchdog reset  */
               SWE_WatchdogTrigger();


         #if ( SC_HANDLE_ECC == STD_ON )
                                            /* get pointer to end of segment  */
                                            /* containing the SWE valid flag  */
               pSegmentEnd = (P2CONST(uint8,AUTOMATIC,CRC_APPL_DATA))
                  ConvertExtAddress2IntPointer( (uint32)(segmentEndAddress
                                                - sizeof(uint8_least)
                                                + 1uL ));

                                  /* iterate all bytes from start of SgbmId   */
                                  /* to end of flash segment. This area will  */
                                  /* be read (touched) to detect ECC errors   */
               while ( ( pCurrentPosition <= pSegmentEnd ) &&
                       ( currentDataPointerOverflow == FALSE ) )
               {
                  P2CONST(uint8,AUTOMATIC,CRC_APPL_DATA) pNextPosition;

                                            /* read (touch) current byte      */
                  const volatile uint8_least devNull = *((uint8_least SC_FAR_POINTER)pCurrentPosition);

                                            /* get next position from         */
                                            /* pCrcBlockStepArray             */
                  pNextPosition = pCurrentPosition +
                     ( (uint32)pCrcBlockStepArray[ currentBlockStepIndex + 1u ] + 1u ) *
                       (uint32)CRC_INCREMENT_MULTIPLICATOR ;

                                  /* if overflow at end of address space      */
                  if ( pNextPosition < pCurrentPosition )
                  {
                                            /* reached end                    */
                     currentDataPointerOverflow = TRUE;
                  }
                  else
                  {
                                            /* set next position              */
                     pCurrentPosition = pNextPosition;

                                            /* increment block step index     */
                     currentBlockStepIndex  =
                        (uint8_least)( ( (uint8_least)( currentBlockStepIndex + 1u ) ) %
                                         (uint8_least)pCrcBlockStepArray[ 0 ] );
                  }
               }
         #endif /* SC_HANDLE_ECC == ON                                        */


                                  /* if calculated CRC value differs from CRC */
                                  /* value in ROM or if an ECC error occured  */
               if ( crcValue != crcValueInRom )
               {
                                            /* set CRC error flag             */
                  Swe_SetCrcErrorFlagOfSwe( sweId );

                                            /* return SWE is invalid          */
                  validStateOfSwe = SWE_VALID_STATE_INVALID;
               }
      #endif /* SC_VERIFY_SWE_CRC_CHKSUM == ON                                */

      #if ( SC_HANDLE_ECC == STD_ON )
         #ifdef BOOTMANAGER_TEST_ENABLE
            #if ( BOOTMANAGER_TEST_ENABLE == STD_ON )
               Bootmanager_Test_ECC_Input( sweId );
            #endif
         #endif
               if ( Swe_GetEccErrorFlagOfSwe( sweId ) != FALSE )
               {
                                            /* return SWE is invalid          */
                  validStateOfSwe = SWE_VALID_STATE_INVALID;
               }
      #endif /* SC_HANDLE_ECC == ON                                           */

                                            /* error check done for this SWE  */
               Swe_SetErrorCheckDoneFlagOfSwe( sweId );
            }
   #endif /* ( SC_VERIFY_SWE_CRC_CHKSUM == ON ) || ( SC_HANDLE_ECC == ON )    */
#endif /* defined BOOTMANAGER                                                 */
         }
#if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
      }
#endif
#ifdef BOOTLOADER
                                  /* if SWE is invalid                        */
      if ( validStateOfSwe == SWE_VALID_STATE_INVALID )
      {
                                            /* calc number of blank bytes     */
                                            /* of prog dep flag of this SWE   */
         uint8_least numberOfBlankBytes = 0u;
         while ( ( numberOfBlankBytes < (uint8_least)SWE_VALID_FLAG_AREA_LENGTH ) &&
                 ( pSweValidFlag[ numberOfBlankBytes ] == (uint8)FLASH_ERASED_BYTE )
               )
         {
            ++numberOfBlankBytes;
         }

                                  /* if all bytes of valid flag are blank     */
         if ( numberOfBlankBytes == (uint8_least)SWE_VALID_FLAG_AREA_LENGTH )
         {
                                            /* return SWE is unchecked yet    */
            validStateOfSwe = SWE_VALID_STATE_UNCHECKED;
         }
      }
#endif /* defined BOOTLOADER                                                  */
#if ( SC_HANDLE_ECC == STD_ON )
   }
#endif

   return validStateOfSwe;
} /* end of function 'Swe_GetValidStateOfSwe'                                 */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Swe_GetValidStateOfApplSwes                                **
**                                                                            **
** DESCRIPTION   : This function checks if it is safe to access               **
**                 code/data of the application SWEs in ROM.                  **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : SWE_VALID_STATE_INVALID   : One or more SWEs are invalid   **
**                 SWE_VALID_STATE_VALID_SWFL: All application SWEs are valid **
**                 SWE_VALID_STATE_VALID_BTLD: A valid BLU was found          **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
   FUNC(SweValidStateType, COMMON_CODE) Swe_GetValidStateOfApplSwes( void )
#else
SweValidStateType Swe_GetValidStateOfApplSwes( void )
#endif /* Defined BAC */
{
                                            /* get valid state of first SWE   */
   SweValidStateType validStateOfApplSwes = Swe_GetValidStateOfSwe( SWE_ID_OF_APPL_SWE1 );

                                  /* if first SWE has not been sig checked    */
   if ( validStateOfApplSwes == SWE_VALID_STATE_UNCHECKED )
   {
                                            /* return invalid SWE found       */
            validStateOfApplSwes = SWE_VALID_STATE_INVALID;
   }
                                  /* if first SWE is valid and no BLU         */
   else if ( validStateOfApplSwes == SWE_VALID_STATE_VALID_SWFL )
   {
                                  /* iterate other SWEs of application too    */
      uint8_least sweId = (uint8_least)( SWE_ID_OF_APPL_SWE1 + 1u );
      while ( sweId < (uint8_least)SWENUMBEROFALLSWE )
      {
                                  /* if any other SWE is not valid            */
         if ( Swe_GetValidStateOfSwe( (uint8)sweId ) != SWE_VALID_STATE_VALID_SWFL )
         {
                                            /* return invalid SWE found       */
            validStateOfApplSwes = SWE_VALID_STATE_INVALID;
         }
         ++sweId;
      }
   }

   return validStateOfApplSwes;
} /* end of function 'Swe_GetValidStateOfApplSwes'                            */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Swe_GetProgDepStateOfApplSwes                              **
**                                                                            **
** DESCRIPTION   : This function checks if the programming dependencies of    **
**                 all application SWEs are correct.                          **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData                                          **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : SWE_PROGDEP_STATE_UNCHECKED_APPL:                          **
**                    Programming dependencies of application SWEs            **
**                    have not been checked after reprogramming               **
**                 SWE_PROGDEP_STATE_CONSISTENT_APPL:                         **
**                    All application SWEs belong to each other               **
**                 SWE_PROGDEP_STATE_INCONSISTENT_APPL:                       **
**                    One or more application SWEs do not belong to each other**
**                 SWE_PROGDEP_STATE_WRONG_APPL:                              **
**                    The application SWEs do not belong to the HWE           **
**                 SWE_PROGDEP_STATE_VALID_BLU:                               **
**                    A valid BLU was found                                   **
**                 SWE_PROGDEP_STATE_INVALID:                                 **
**                    One or more SWEs are invalid and may not be accessed!   **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
   FUNC(SweProgDepStateType, COMMON_CODE) Swe_GetProgDepStateOfApplSwes( void )
#else
SweProgDepStateType Swe_GetProgDepStateOfApplSwes( void )
#endif /* Defined BAC */
{
   SweProgDepStateType progDepStateOfApplSwes = SWE_PROGDEP_STATE_INVALID;

                                            /* get valid state of appl SWEs   */
   SweValidStateType validStateOfApplSwes = Swe_GetValidStateOfApplSwes();

                                  /* if valid BLU was found                   */
   if ( validStateOfApplSwes == SWE_VALID_STATE_VALID_BTLD )
   {
                                            /* return valid BLU found         */
      progDepStateOfApplSwes = SWE_PROGDEP_STATE_VALID_BLU;
   }
                                  /* if valid application was found           */
   else if ( validStateOfApplSwes == SWE_VALID_STATE_VALID_SWFL )
   {
      uint8_least sweId = (uint8_least)SWE_ID_OF_APPL_SWE1;

                                            /* used to save prog dep value of */
                                            /* SWE with max prog dep counter  */
      uint32 progDepCounterMax = 0uL;
      uint8  progDepValueMax   = 0u;

                                            /* initiate search for prog deps  */
      progDepStateOfApplSwes = SWE_PROGDEP_STATE_CONSISTENT_APPL;

                                  /* iterate all application SWEs             */
      do
      {
                                            /* get pointer to prog dep flag   */
                                            /* of this SWE                    */
         const uint8 SC_FAR_POINTER pProgDepFlag =
            sharedBootROMData.PointerToSweFlashStatus[ sweId ] -> ProgDepFlag;

                                            /* calc number of blank bytes     */
                                            /* of prog dep flag of this SWE   */
         uint8_least numberOfBlankBytes = 0u;
         while ( ( numberOfBlankBytes < (uint8_least)PROG_DEP_AREA_LENGTH ) &&
                 ( pProgDepFlag[ numberOfBlankBytes ] == (uint8)FLASH_ERASED_BYTE )
               )
         {
            ++numberOfBlankBytes;
         }

                                  /* if all bytes of prog dep flag are blank  */
         if ( numberOfBlankBytes == (uint8_least)PROG_DEP_AREA_LENGTH )
         {
                                            /* return prog dep not checked yet*/
            progDepStateOfApplSwes = SWE_PROGDEP_STATE_UNCHECKED_APPL;
         }
                                  /* if prog dep flag has been written before */
         else
         {
                                            /* get value of prog dep flag     */
            const uint8 progDepValue = pProgDepFlag[0];

                                            /* get counter of prog dep flag   */
            const uint32 progDepCounter = Make32Bit( pProgDepFlag[1],
                                                     pProgDepFlag[2],
                                                     pProgDepFlag[3],
                                                     pProgDepFlag[4] );

                                  /* if SWE has the highest prog dep counter  */
            if ( progDepCounter > progDepCounterMax )
            {
                                            /* remember prog dep value        */
               progDepValueMax = progDepValue;

                                            /* remember prog dep counter      */
               progDepCounterMax = progDepCounter;
            }
         }

#if ( defined BOOTMANAGER ) && ( SC_HANDLE_ECC == STD_ON )
                                  /* if an ECC error occured while reading    */
                                  /* the prog dep flag from ROM               */
         if ( Swe_GetEccErrorFlagOfSwe( sweId ) != FALSE )
         {
                                            /* return invalid SWE found       */
            progDepStateOfApplSwes = SWE_PROGDEP_STATE_INVALID;
         }
#endif

         ++sweId;
      } while ( ( progDepStateOfApplSwes == SWE_PROGDEP_STATE_CONSISTENT_APPL ) &&
                ( sweId <= (uint8_least)SWENUMBEROFAPPLSWE ) );

                                  /* if all prog dep flags could be read      */
      if ( progDepStateOfApplSwes == SWE_PROGDEP_STATE_CONSISTENT_APPL )
      {
                                            /* return prog dep value of SWE   */
                                            /* with highest prog dep counter  */
         progDepStateOfApplSwes = (SweProgDepStateType)progDepValueMax;
      }
   }

   return progDepStateOfApplSwes;
} /* end of function 'Swe_GetProgDepStateOfApplSwes'                          */

#endif /* ( defined BOOTMANAGER ) || (defined BOOTLOADER )                    */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Swe_RomAccessExceptionHandler                              **
**                                                                            **
** DESCRIPTION   : On some platforms this function is called if a flash ROM   **
**                 access exception (ECC) occured. If the hardware does not   **
**                 support this SC_HANDLE_ECC must not be enabled.            **
**                 This function checks if an ECC error occured due to an     **
**                 power failure during bootloader flash operation.           **
**                 It calls RomAccessExceptionHandler() which                 **
**                 can be used to handle ROM ECC errors in general.           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData                                          **
**                                                                            **
** PARAMETER     : codeAddress: Code address where the ROM data was accessed  **
**                 dataAddress: ROM data address which can not be accessed    **
**                                                                            **
** RETURN        : Anything except zero will trigger a reset                  **
**                                                                            **
** REMARKS       : This function runs in interrupt context                    **
**                                                                            **
*******************************************************************************/
#if ( SC_HANDLE_ECC == STD_ON )
   #ifdef BAC
      FUNC(uint32, COMMON_CONST) Swe_RomAccessExceptionHandler
                                 (
                                    VAR(uint32, COMMON_APPL_CODE) codeAddress, 
					                VAR(uint32, COMMON_APPL_CODE) dataAddress 
						         )
   #else
      uint32 Swe_RomAccessExceptionHandler
	         (
			    uint32 codeAddress, 
				uint32 dataAddress 
			 )
   #endif /* Defined BAC */
{
   uint32 resetEcu = 0;

                                  /* check if ECC error occured in FEE        */
   if (
        ( (dataAddress >= sharedBootROMData.FeeSectorConfig.LowerSectorStartAddress) &&
          (dataAddress <= sharedBootROMData.FeeSectorConfig.LowerSectorEndAddress)
        )
        ||
        ( (dataAddress >= sharedBootROMData.FeeSectorConfig.UpperSectorStartAddress) &&
          (dataAddress <= sharedBootROMData.FeeSectorConfig.UpperSectorEndAddress)
        )
      )
   {
   
                                            /* ECC errors in FEE will be      */
      ECC_CLEAR_CFLASH_ERROR_FLAG();
	  
											/* notify the FEE                 */
	  #ifndef BOOTMANAGER
	  ECC_FEE_NOTIFICATION();
	  #endif /* BOOTMANAGER */
	  
   }
   else
   {
      #ifdef BOOTMANAGER
                                  /* iterate all SWEs                         */
         uint8_least sweId = 0;
         do
         {
            flashAddress_t segmentStartAddress;
            flashAddress_t segmentEndAddress;

                                            /* get address of flash segment   */
                                            /* containing the SWE valid flag  */
            Swe_GetAddressOfFlashSegmentContainingValidFlag( (uint8)sweId,
                                                             &segmentStartAddress,
                                                             &segmentEndAddress );

                                  /* if ECC error occured in flash segment    */
                                  /* containing the valid flag of the SWE     */
            if ( ( dataAddress >= segmentStartAddress ) &&
                 ( dataAddress <= segmentEndAddress   ) )
            {
                                            /* set ECC error flag of SWE      */
               Swe_SetEccErrorFlagOfSwe( sweId );

                                            /* clear hardware ECC error flag  */
               ECC_CLEAR_CFLASH_ERROR_FLAG();
            }

            ++sweId;

         } while ( sweId < (uint8_least)sharedBootROMData.NumberOfAllSWEs );
      #endif /* defined ( BOOTMANAGER )                                       */

                                            /* notify the application         */
      resetEcu = SWE_MAP_RomAccessExceptionHandler( codeAddress, dataAddress );
   }

   return resetEcu;
} /* end of function 'Swe_RomAccessExceptionHandler'                          */

#endif /* SC_HANDLE_ECC == ON                                                 */

/*** End of file **************************************************************/
