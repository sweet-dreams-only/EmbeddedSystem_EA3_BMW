/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Coding.c                                                      **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Source file of coding module                                  **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
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
** hauf         Andreas Hauf               EB Automotive                      **
** rois         Roman Iseler               EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
** bemo         Benjamin Moenius           EB Automotive                      **
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.3.3: 17.05.2011, olho: CR70890: Implemented findings from shared
 *                                    resources analysis
 *         12.05.2011, olho: CR71025: Commented or used return values
 *         11.05.2011, olho: CR71043: Added Crypto-Wrapper macro
 * V1.3.2: 15.02.2011, thmi: CR70905: updated MISRA comments to MISRA 2004
 *                                    revise MISRA deviations:
 *                                    Fixed uninitialized variables
 *                                    Fixed const pointer qualifiers
 * V1.3.1: 18.11.2010, olho: removed misra warnings
 * V1.3.0: 27.09.2010, olho: CR70727: CodingStampValid returns wrong value in
 *                                    case no Signal was yet received
 * V1.3.0: 23.09.2010, olho: CR70784: CodingAllowed() should treat Coding
 *                                    preconditions
 * V1.2.0: 16.07.2010, bemo: CR70715: Coding_NvData.data shall be configured
 *                                    instead of Coding_NvData
 * V1.1.5: 05.07.2010, bemo: CR70697: optimize stack, while using asymmetric
 *                                    signature check
 * V1.1.5: 16.06.2010, olho: CR70672: Coding using symmetric signature check
 * V1.1.4: 23.03.2010, olho: CR70559: Replaced VIN signal with signalgroup
 * V1.1.3: 28.10.2009, hauf: CR70347: Fixed wrong call of Coding_BlockValid()
 *                                    and Coding_ReceiveBlock(),
 *                                    Fixed compiler abstraction findings
 * V1.1.2: 30.06.2009, hauf: changed module version
 * V1.1.0: 17.03.2009, hauf: CR70090: New API Coding_GetVinCpsComparisonResult
 *         12.02.2009, hauf: CR70143: Revert CR61308, this may block the system
 * V1.0.2: 11.11.2008, rois: CR61272: Replace resData with reqData in
 *                                    Coding_DiagWriteDataByIdentifier
 *         26.11.2008, hauf: Removed MISRA warnings and updated MISRA comments
 * V1.0.1: 01.10.2008, hauf: CR70013: Dont't call PIA notification after startup
 * V1.0.0: 29.05.2008, hauf: CR61371: Allow coding if vehicle speed is < 6 km/h
 *                           CR61376: Avoid restoring defaults if speed >= 6 km/h
 *         20.02.2008, rois: MISRA-Check
 *         15.02.2008, rois: formatted function descriptions according to
 *                           the review
 *         07.02.2008, hauf: CR61308: Wait for restauration of default
 *                                    data after session timeout
 *         30.11.2007, hauf: ported from SC6.7.2 file version V4.1.0
 */

#define CODING_C

/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/
 /* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 11.4 (advisory)
  *   A cast should not be performed between a pointer to object type and a
  *   different pointer to object type.
  *
  *   Reason:
  *   This coding design requires this cast.
  *
  * MISRA-2) Deviated Rule: 17.4 (required)
  *   Array indexing shall be the only allowed form of pointer arithmetic.
  *
  *   Reason:
  *   Depends on specification.
  *
  * MISRA-3)  Deviated Rule: 18.4 (required)
  *   Unions shall not be used.
  *
  *   Reason:
  *   Used to align data to 32 bit
  *
  * MISRA-4) Deviated Rule: 19.7 (advisory)
  *   A function should be used in preference to a function-like macro.
  *
  *   Reason:
  *   As the function is called very often and consists only of a one line
  *   the macro based implmentation is more run time efficient.
  *
  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR standard types                   */
#include <Coding.h>               /* Coding header file                       */
#include <Coding_Diagnostic.h>    /* Coding diagnostic header file            */
#include <SchM_Coding.h>          /* Schedule Manager header file             */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*
 * Version check
 */
#if ((CODING_H_MAJOR_VERSION != 2u) || \
     (CODING_H_MINOR_VERSION != 2u))
  #error "Wrong version of Coding.h found!!"
#endif

#if ((CODING_CFG_H_MAJOR_VERSION != 2u) || \
     (CODING_CFG_H_MINOR_VERSION != 2u))
  #error "Wrong version of Coding_Cfg.h found!!"
#endif

#if ((CODING_DIAGNOSTIC_H_MAJOR_VERSION != 2u) || \
     (CODING_DIAGNOSTIC_H_MINOR_VERSION != 2u))
  #error "Wrong version of Coding_Diagnostic.h found!!"
#endif

/*
 * Additional error types (for internal use only)
 */
#define CODING_E_NEXT_CHECK   ((Coding_ErrorType)4)

/*
 * Additional block id types (for internal use only)
 */
#define CODING_ID_STAMP   ((Coding_BlockIdType)CODING_NUMBER_OF_BLOCKS)

/*
 * DCM Session ids
 */
#define CODING_DIAG_SESSION_DEFAULT   0x01
#define CODING_DIAG_SESSION_CODING    0x41

/*
 * DCM session security levels
 */
#define CODING_DIAG_SECURITY_DEFAULT   0x00
#define CODING_DIAG_SECURITY_CODING    0x01

/*
 * Macros to get, set and clear a flag inside an array
 */
/* Deviation MISRA-4 */
#define Coding_GetFlag( array, bit ) \
           ((boolean)((uint8)((array)[(bit)/(8U)] & (uint8)(1U << ((bit)%(8U)))) >> (uint8)((bit)%(8U))))

/* Deviation MISRA-4 */
#define Coding_SetFlag( array, bit ) \
           ((array)[(bit)/(8U)] = (array)[(bit)/(8U)] | (uint8)(1U << ((bit)%(8U))))

/* Deviation MISRA-4 */
#define Coding_ClearFlag( array, bit ) \
           ((array)[(bit)/(8U)] = (array)[(bit)/(8U)] & (uint8)~(1U << ((bit)%(8U))))


/*
 * Coding state type values
 * Used by the internal state machine (Coding_StateType).
 */
#define CODING_STATE_DATA_CHANGED               0
#define CODING_STATE_IDLE                       1
#define CODING_STATE_SESSION_LOCKED             2
#define CODING_STATE_SESSION_UNLOCKED           3
#define CODING_STATE_SESSION_CHECK_SIGNATURE    4
#define CODING_STATE_SESSION_WRITE_STAMP        5

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

typedef uint8 Coding_StateType;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


#define CODING_START_SEC_VAR_NO_INIT_NVDATA
#include "MemMap.h"

/*
 * Coding nv status
 * The RAM mirror of NVM_CODING_STATUS_BLOCK.
 * Size = 1 + (CODING_NUMBER_OF_BLOCKS - 1) / 8
 */
VAR(uint8, CODING_VAR_NVDATA) Coding_NvStatus[CODING_NVSTATUS_IDX];

/*
 * Coding nv data
 * The RAM mirror of NVM_CODING_DATA_BLOCK.
 * Size = size is all blocks + 7 bytes for the Coding proof stamp (CPS)
 */
/* Deviation MISRA-3 */
VAR(Coding_NvDataType, CODING_VAR_NVDATA) Coding_NvDataInternal;

#define CODING_STOP_SEC_VAR_NO_INIT_NVDATA
#include "MemMap.h"

#define CODING_START_SEC_CONST_8BIT
#include "MemMap.h"

/*
 * Coding nv status defaults
 * Coding status default values used as ROM backup of NVM_CODING_STATUS_BLOCK.
 * Size = 1 + (CODING_NUMBER_OF_BLOCKS - 1) / 8
 */
CONST( uint8, CODING_CONST ) Coding_NvStatusDefaults[CODING_NVSTATUS_IDX] =
    CODING_NVSTATUSDEFAULTS_INIT;

/*
 * Coding nv data defaults
 * Coding data default values used as ROM backup of NVM_CODING_DATA_BLOCK.
 * Size = size is all blocks + 7 bytes for the Coding proof stamp (CPS)
 */
CONST( uint8, CODING_CONST ) Coding_NvDataDefaults[SIZEOF_ALL_BLOCKS] =
     CODING_NVDATADEFAULTS_INIT;

#define CODING_STOP_SEC_CONST_8BIT
#include "MemMap.h"

/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#define CODING_START_SEC_CONST_UNSPECIFIED_DESCRIPTOR_TABLE
#include "MemMap.h"

   /*
    * Coding area descriptor table
    * The area descriptor table contains the following offsets of the
    * Coding_NvData array for each area:
    * - offset of the first block
    * - offset of signature block
    */
  _STATIC_ CONST(Coding_AreaDescriptorTableType, CODING_CONST_DESCRIPTOR_TABLE)
    codingAreaDescriptorTable[ CODING_NUMBER_OF_AREAS ] =
      CODING_AREA_DESCRIPTORTABLE_INIT;

   /*
    * Coding block descriptor table
    * The block descriptor table contains the following information for each block:
    * - diagnostic data identifier
    * - offset of the block in Coding_NvData array
    * - size of the block in bytes
    */
  _STATIC_ CONST(Coding_BlockDescriptorTableType, CODING_CONST_DESCRIPTOR_TABLE)
    codingBlockDescriptorTable[ CODING_NUMBER_OF_BLOCKS + 1 ] =
      CODING_BLOCK_DESCRIPTORTABLE_INIT;

#define CODING_STOP_SEC_CONST_UNSPECIFIED_DESCRIPTOR_TABLE
#include "MemMap.h"

#define CODING_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* CHECK comment is necessary for code coverage measurement */
/*CHECK: NOPARSE*/

   /*
    * Coding state
    * Used by the internal state machine.
    */
   _STATIC_ VAR(Coding_StateType, CODING_VAR)
                codingState = CODING_STATE_DATA_CHANGED;

   /*
    * Coding data status
    * Used by Coding_GetDataStatus() to return the current coding data status
    */
   _STATIC_ VAR(Coding_DataStatusType, CODING_VAR)
                codingDataStatus = CODING_DATA_UNDEFINED;

   /*
    * Coding stamp valid
    * Used by CodingStampValid() to return
    * the validity of the coding stamp
    */
   _STATIC_ VAR(Coding_ErrorType, CODING_VAR)
                codingStampStatus = CODING_E_PENDING;

/*CHECK: PARSE*/

#define CODING_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define CODING_START_SEC_CODE
#include "MemMap.h"

   _STATIC_ FUNC(Coding_ErrorType, CODING_PRIVATE_CODE)
                 CodingCheckSignature( void );

   _STATIC_ FUNC(void, CODING_PRIVATE_CODE)
                 CodingRestoreDefaults
                 (
                    boolean storePersistent
                 );

   _STATIC_ FUNC(Coding_ErrorType, CODING_PRIVATE_CODE)
                 CodingAllowed( void );

   _STATIC_ FUNC(Coding_ErrorType, CODING_PRIVATE_CODE)
                 CodingStampValid
                 (
                    CONSTP2CONST( uint8, AUTOMATIC, CODING_VAR_NVDATA ) codingStamp
                 );

   _STATIC_ FUNC(void, CODING_PRIVATE_CODE)
                 CodingAbortSession
                 (
                    P2VAR( Dcm_MsgContextType, AUTOMATIC, CODING_VAR_DCMDATA ) pMsgContext,
                    Dcm_NegativeResponseCodeType negativeResponseCode
                 );

#define CODING_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define CODING_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CodingCheckSignature                                       **
**                                                                            **
** DESCRIPTION   : This function checks the signatures of all areas.          **
**                                                                            **
** PRECONDITIONS : Must be called with low priority. It may take very long.   **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : CODING_E_OK    : if signature check ok                     **
**                 CODING_E_NOT_OK: if signature check failed                 **
**                                                                            **
** REMARKS       : This is a synchronous function that may take very long.    **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(Coding_ErrorType, CODING_PRIVATE_CODE) CodingCheckSignature( void )
{
   Coding_ErrorType RetVal = E_OK;
                                            /* return value of crypto call    */
   CR_C_RC_t cryptoResult;
                                            /* index of area descriptor       */
   uint8_least areaId;
                                            /* pointer to area descriptor     */
   P2CONST( Coding_AreaDescriptorTableType, AUTOMATIC,
            CODING_CONST_DESCRIPTOR_TABLE ) pAreaDescriptorTable;
                                            /* pointer to data to be checked  */
   P2VAR( uint8, AUTOMATIC, CODING_VAR_NVDATA ) pData;
                                            /* offset of signature            */
   Coding_DataOffsetType signatureOffset;
                                            /* data size of checked data      */
   uint32 size;
                                            /* crypto expects far pointer     */
   CR_fpc_uint8 fpData;

   #if (CODING_CRYPTO_METHOD == CODING_CRYPTO_METHOD_ASYM)
                                            /* aligned signature on stack     */
      uint32 pSignatureAligned[ CR_DEF_NCD_SIG_KEY_LENGTH ];
                                            /* counter value                  */
      uint8_least i;
   #endif


                                  /* each coding area has its own signature   */
   for ( areaId = 0; areaId < (uint8_least)CODING_NUMBER_OF_AREAS; areaId++ )
   {
                                            /* get descriptor table of area   */
      pAreaDescriptorTable = &codingAreaDescriptorTable[areaId];

                                            /* get data of area               */
      pData = &Coding_NvData[ pAreaDescriptorTable->dataOffsetOfFirstBlock ];

                                            /* get size of area               */
      size = ((uint32)pAreaDescriptorTable->dataOffsetOfSignatureBlock
                                - (uint32)pAreaDescriptorTable->dataOffsetOfFirstBlock);

                                            /* get signature offset           */
      signatureOffset = pAreaDescriptorTable->dataOffsetOfSignatureBlock;

                                            /* crypto expects far pointer     */
      fpData = pData;

                                  /* asymmetric signature check               */
      #if (CODING_CRYPTO_METHOD == CODING_CRYPTO_METHOD_ASYM)

                                            /* copy the unaligned signature   */
                                            /* to the aligned uint32 array    */
         for ( i =  (uint8_least)0;
               i <  (CR_DEF_NCD_SIG_KEY_LENGTH * (uint8_least)4);
               i += (uint8_least)4
             )
         {
            pSignatureAligned[i / (uint8_least)4] = Make32Bit
            (
               Coding_NvData[signatureOffset + i + 0],
               Coding_NvData[signatureOffset + i + 1],
               Coding_NvData[signatureOffset + i + 2],
               Coding_NvData[signatureOffset + i + 3]
            );
         }

         cryptoResult = Coding_CryptoCheckSignatureAsym(
                                               fpData,
                                               size,
                                               pSignatureAligned);

      #else
                                  /* symmetric signature check                */
         cryptoResult = Coding_CryptoCheckSignatureSymm(
                                               fpData,
                                               size,
                                               &Coding_NvData[signatureOffset]);
      #endif

                                  /* if signature check failed                */
      if (( cryptoResult != CR_C_RC_OK ) &&
          ( cryptoResult != CR_C_RC_CANCELED ))
      {
                                            /* set event 'signature error'    */

                                            /* DEM returns an error in case   */
                                            /* of an explicitly locked event  */
                                            /* memory, DEM queue overflow     */
                                            /* dectected by DET-Check         */
         (void)Coding_Call_DemEventSignatureError_SetEventStatus( DEM_EVENT_STATUS_FAILED );

                                            /* set 'signature failed'         */
         RetVal = E_NOT_OK;

                                            /* break at this point and return */
                                            /* with error                     */
         break;
      }
   }

   return RetVal;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CodingRestoreDefaults                                      **
**                                                                            **
** DESCRIPTION   : This function restores the defaults from ROM backup for    **
**                 all non write protected Coding blocks and for the CPS.     **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : storePersistent: TRUE : calls NvM_WriteBlock() afterwards  **
**                                  FALSE: does not call NvM_WriteBlock       **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
**                                                                            **
** REMARKS       : This is a synchronous function.                            **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, CODING_PRIVATE_CODE) CodingRestoreDefaults( boolean storePersistent )
{
                                            /* used to iterate Coding blocks  */
  uint8_least blockId;
                                            /* Offset to RAM mirror           */
  Coding_DataOffsetType nvDataOffset;
                                            /* used to hold size of a block   */
  uint8_least blockSize;
                                            /* counter variable               */
  uint8_least i;


                                  /* iterate all coding blocks                */
  for ( blockId = 0; blockId <= (uint8_least)CODING_NUMBER_OF_BLOCKS; blockId++ )
  {
                                  /* if block is not write protected          */
    if ( (blockId == CODING_ID_STAMP) ||
         (Coding_GetFlag(Coding_NvStatus, (uint8)blockId) == FALSE) )
    {
                                            /* set Offset to start of block   */
                                            /* in RAM mirror / ROM backup     */
      nvDataOffset = codingBlockDescriptorTable[blockId].dataOffset;
                                            /* get size of block              */
      blockSize = codingBlockDescriptorTable[blockId].dataSize;

                                  /* copy default values of block from        */
                                  /* ROM backup to RAM mirror                 */
      for ( i = 0; i < blockSize; i++ )
      {
        Coding_NvData[ nvDataOffset + i ] =
           Coding_NvDataDefaults[ nvDataOffset + i ];
      }
    }
  }

  if ( storePersistent != FALSE )
  {
                                          /* make NvM data block writeable    */
    Coding_Call_NvmBlockData_Administration_SetBlockProtection( FALSE );

                                          /* write data back to NV memory     */

                                          /* an error already occurred,       */
                                          /* ignore return value to keep      */
                                          /* original error code in           */
                                          /* negativeResponseCode             */
    (void)Coding_Call_NvmBlockData_WriteBlock();
  }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CodingAllowed                                              **
**                                                                            **
** DESCRIPTION   : This function shall check if coding is allowed by checking **
**                 if the vehicle is moving.                                  **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : CODING_E_OK : vehicle speed is < 6 km/h or invalid         **
**                        -> coding is allowed                                **
**                 CODING_E_NOT_OK: vehicle is moving with 6 km/h or faster   **
**                        -> coding is not allowed                            **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(Coding_ErrorType, CODING_PRIVATE_CODE) CodingAllowed( void )
{
                                            /* return value of this function */
   Coding_ErrorType codingAllowed = CODING_E_NOT_OK;
                                            /* precondition flag             */
   Coding_ErrorType CheckCodingPreConditions = CODING_E_NOT_OK;
                                            /* used to receive speed signal  */
   uint16 speedSignal;

                                            /* check preconditions           */
   Coding_Call_CbkPreConditions_Check( &CheckCodingPreConditions );

                                  /* if preconditions fulfilled              */
   if ( CheckCodingPreConditions == CODING_E_OK )
   {
                                            /* receive speed signal from COM */
                                            /* last value in receive buffer  */
                                            /* is used, no need to evaluate  */
                                            /* return value                  */
      (void)Coding_Call_ComSignalSpeed_ReceiveSignal( &speedSignal );

                                  /* If speed is < 6 km/h or invalid         */
      if ( (speedSignal <  0x0180U) ||
           (speedSignal == 0xFFFFU) )
      {
                                            /* coding is allowed             */
         codingAllowed = CODING_E_OK;
      }
   }

   return codingAllowed;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CodingStampValid                                           **
**                                                                            **
** DESCRIPTION   : This function checks if the coding proove stamp (CPS) fits **
**                 to the vehicle identification number (VIN) that is beeing  **
**                 sent cyclically around the network.                        **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : codingStamp: 7 byte long coding proof stamp (CPS)          **
**                                                                            **
** RETURN        : - CODING_E_PENDING:                                        **
**                          if the vehicle identification number (VIN) has not**
**                          been received and a comparison can not be made    **
**                          or if the vehicle is moving >= 6 km/h and it is   **
**                          too risky to restore defaults at this time.       **
**                 - CODING_E_OK:                                             **
**                          if the vehicle identification number (VIN) has    **
**                          been received and it fits to the coding proove    **
**                          stamp (CPS).                                      **
**                 - CODING_E_NOT_OK:                                         **
**                          if the vehicle identification number (VIN) has    **
**                          been received but it does not fit to the coding   **
**                          proove stamp (CPS).                               **
**                                                                            **
** REMARKS       : The function is called after ECU start-up as long as it    **
**                 returns CODING_E_PENDING and it is called once before      **
**                 writing the received CPS to NVRAM mirror during coding     **
**                 session.                                                   **
**                                                                            **
**                 If this function returns CODING_E_PENDING the              **
**                 function will be called again after a while, until the VIN **
**                 has been received.                                         **
**                                                                            **
**                 If this function returns CODING_E_NOT_OK the               **
**                 coding module will restore the default values for all      **
**                 non write-protected coding blocks.                         **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(Coding_ErrorType, CODING_PRIVATE_CODE) CodingStampValid
(
   CONSTP2CONST( uint8, AUTOMATIC, CODING_VAR_NVDATA ) codingStamp
)
{
                                            /* set return value to 'pending'  */
   Coding_ErrorType stampStatus = CODING_E_PENDING;
                                            /* loop counter                   */
   uint8_least i;
                                            /* used to receive speed signal   */
   uint16 speedSignal;
                                            /* used to receive vin signal     */
   uint8 vinSignal[7] = { 0, 0, 0, 0, 0, 0, 0 };
#if (CODING_RTE_COM_ENABLE == STD_ON)
   Coding_FAHRGESTELLNUMMERRecordType
      Fahrgestellnummer = { 0, 0, 0, 0, 0, 0, 0 };
   Coding_FAHRGESTELLNUMMERRecordType *Vin = &Fahrgestellnummer;
#else
   uint8 *Vin = &vinSignal[0];
#endif

                                            /* receive speed signal from COM */
                                            /* last value in receive buffer  */
                                            /* is used, no need to evaluate  */
                                            /* return value                  */
   (void)Coding_Call_ComSignalSpeed_ReceiveSignal( &speedSignal );

   /* ----------------------------------- Nxtr Patch START -----------------------------------
    * Description: OS Interrupts are suspended to avoid data inconsistencies while reading VIN
    *              and re-enabled after the complete VIN message is read
    * Date: 03/22/2017
    * Added by: Archana Shivarudrappa
    */

   SuspendOSInterrupts();

   /* receive vin signalgroup from COM */
   Coding_Call_ComSignalGroupFahrgestellnummer_ReceiveSignalGroup( Vin );

   ResumeOSInterrupts();

   /* ------------------------------------ Nxtr Patch END -----------------------------------  */

#if (CODING_RTE_COM_ENABLE == STD_ON)
   /* Copy received data */
   vinSignal[0] = Vin->NO_VECH_1;
   vinSignal[1] = Vin->NO_VECH_2;
   vinSignal[2] = Vin->NO_VECH_3;
   vinSignal[3] = Vin->NO_VECH_4;
   vinSignal[4] = Vin->NO_VECH_5;
   vinSignal[5] = Vin->NO_VECH_6;
   vinSignal[6] = Vin->NO_VECH_7;
#endif

                                  /* check if VIN values are all 0x00s        */
   for ( i = 0; i < (uint8_least)7U; i++ )
   {
      if ( vinSignal[i] != 0x00U )
      {
                                            /* not all values are 0x00s       */
                                            /* -> proceed to next check       */
         stampStatus = CODING_E_NEXT_CHECK;
      }
   }
                                  /* if next check shall be done              */
   if ( stampStatus == CODING_E_NEXT_CHECK )
   {
                                            /* set return value to 'pending'  */
      stampStatus = CODING_E_PENDING;

                                  /* check if VIN values are all 0xFFs        */
      for ( i = 0; i < (uint8_least)7U; i++ )
      {
         if ( vinSignal[i] != 0xFFU )
         {
                                            /* not all values are 0xFFs       */
                                            /* -> proceed to next check       */
            stampStatus = CODING_E_NEXT_CHECK;
         }
      }
                                  /* if next check shall be done              */
      if ( stampStatus == CODING_E_NEXT_CHECK )
      {
                                            /* set return value to 'ok'       */
         stampStatus = CODING_E_OK;

                                  /* check if VIN matches the CPS             */
         for ( i = 0; i < (uint8_least)7U; i++ )
         {
            /* Deviation MISRA-2 */
            if ( vinSignal[i] != codingStamp[i] )
            {
                                            /* VIN does not match the CPS ->  */
                                            /* set return value to 'not ok'   */
               stampStatus = CODING_E_NOT_OK;
            }
         }
      }

                                  /* if wrong vehicle but speed >= 6 km/h     */
      if ( ( stampStatus == CODING_E_NOT_OK ) &&
           ( speedSignal >= 0x0180U ) &&
           ( speedSignal != 0xFFFFU ) )
      {
                                            /* do as if nothing happened      */
         stampStatus = CODING_E_PENDING;
      }
   }

   return stampStatus;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CodingAbortSession                                         **
**                                                                            **
** DESCRIPTION   : This function aborts the coding session after restoring    **
**                 the coding default values.                                 **
**                                                                            **
** PRECONDITIONS : ECU must be in Coding session                              **
**                                                                            **
** PARAMETER     : pMsgContext          : DCM message context                 **
**                 negativeResponseCode : The negative response code that     **
**                                        should be sent or DCM_E_OK if no    **
**                                        negative response should be sent.   **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
**                                                                            **
** REMARKS       : This is a synchronous function that may take very long.    **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, CODING_PRIVATE_CODE)
              CodingAbortSession( P2VAR( Dcm_MsgContextType, AUTOMATIC, CODING_VAR_DCMDATA ) pMsgContext,
                                  Dcm_NegativeResponseCodeType negativeResponseCode )
{
                                  /* if application has not been notified yet */
   if ( codingDataStatus != CODING_DATA_UNDEFINED )
   {
                                            /* notify the application         */
      Coding_Call_CbkDataChange_StartNotification();

                                            /* set data status to 'undefined' */
      codingDataStatus = CODING_DATA_UNDEFINED;

   }
                                            /* restore defaults               */
   CodingRestoreDefaults( TRUE );

                                            /* wait for operation to finish   */
   Coding_NvmWaitUntilBlockIsReady( CODING_NVM_DATA_BLOCK );

                                            /* notify application             */
   codingState = CODING_STATE_DATA_CHANGED;

                                            /* call main function to notify   */
                                            /* the application immediately    */
   Coding_MainFunction();

                                            /* abort coding session           */
   Coding_DiagSetSesCtrlType( CODING_DIAG_SESSION_DEFAULT );

                                  /* if negative response should be send      */
   if ( negativeResponseCode != DCM_E_OK )
   {
                                            /* send negative response         */
      Coding_DiagSetNegResponse( pMsgContext, negativeResponseCode );
   }
}


/*******************************************************************************
**                      Global Application API Functions                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_Init                                                **
**                                                                            **
** DESCRIPTION   : Init function of the coding module.                        **
**                 Must be called during startup.                             **
**                                                                            **
** PRECONDITIONS : 1. NVM module must be initialized.                         **
**                 2. NvM_ReadAll() must be finish.                           **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a asynchronous function.                           **
**                 The function checks if the NVM could load the coding data  **
**                 NV memory to the coding data NVRAM mirror.                 **
**                                                                            **
**                 If the coding data NVRAM mirror contains values from the   **
**                 NV memory:                                                 **
**                 - the function checks if re-coding is required because of  **
**                   a reprogramming of the ECU.                              **
**                   If re-coding is required:                                **
**                   - the function restores the coding data default values   **
**                     from ROM backup for all non write-protected            **
**                     coding blocks.                                         **
**                   - the function requests the writing of the restored      **
**                     default values to the NV memory.                       **
**                 If the coding data NVRAM mirror contains default values:   **
**                 - the function checks if the NVM could load the coding     **
**                   status NV memory to the coding status NVRAM mirror.      **
**                   If the coding status NVRAM mirror contains values from   **
**                   the NV memory:                                           **
**                   - the function requests the restoring of the coding      **
**                     status default values from ROM backup.                 **
**                                                                            **
**                 The function waits for all NVM requests to complete        **
**                 before starting normal operation.                          **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE) Coding_Init( void )
{
                                            /* standard return result         */
   Std_ReturnType result;
                                            /* NvM request result             */
   NvM_RequestResultType nvmRequestResult = NVM_REQ_NOT_OK;


                                            /* get status of the NVRAM mirror */
                                            /* containing the coding data     */
   Coding_Call_NvmBlockData_GetErrorStatus( &nvmRequestResult );

                                  /* if the coding data NVRAM mirror          */
                                  /* contains values from NV memory           */
   if ( nvmRequestResult == NVM_REQ_OK )
   {
                                 /* if re-coding is required                  */
                                 /* e.g. if the ECU has been reprogrammed     */
      if ( Coding_Required() )
      {
                                            /* restore defaults               */
         CodingRestoreDefaults( TRUE );

                                            /* wait until default values have */
                                            /* been written to NV memory      */
         Coding_NvmWaitUntilBlockIsReady( CODING_NVM_DATA_BLOCK );
      }
   }
                                  /* if the coding data NVRAM mirror          */
                                  /* contains default values from ROM backup  */
   else
   {
                                            /* get status of the NVRAM mirror */
                                            /* containing the coding status   */
      Coding_Call_NvmBlockStatus_GetErrorStatus( &nvmRequestResult );

                                  /* if the coding status NVRAM mirror        */
                                  /* contains values from NV memory           */
      if ( nvmRequestResult == NVM_REQ_OK )
      {
                                            /* restore default values of      */
                                            /* coding status block too        */
         result = Coding_Call_NvmBlockStatus_RestoreBlockDefaults();

                                  /* if status restoring was accepted         */
         if (result == E_OK)
         {
                                            /* wait until default values have */
                                            /* been written to NV memory      */
            Coding_NvmWaitUntilBlockIsReady( CODING_NVM_STATUS_BLOCK );
         }
         else
         {
                                            /* restore values manually        */

                                            /* return value is a pointer to   */
                                            /* destination not an errorcode   */
            /* Deviation MISRA-2 */
            (void)Coding_Memcopy(Coding_NvStatus,
                                 Coding_NvStatusDefaults,
                                 CODING_NVSTATUS_IDX);
         }
      }
   }
                                            /* Call Coding_MainFunction(), so */
                                            /* that the coding data status    */
                                            /* will be set from 'undefined'   */
                                            /* to either 'coded' or           */
                                            /* 'not coded' immediately after  */
                                            /* start up                       */
   Coding_MainFunction();
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_MainFunction                                        **
**                                                                            **
** DESCRIPTION   : Main function of the coding module.                        **
**                 Must be called periodically.                               **
**                                                                            **
** PRECONDITIONS : 1. Coding module must be initialized.                      **
**                 2. DEM module must be initialized.                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a asynchronous function that has to be called      **
**                 cyclically.                                                **
**                                                                            **
**                 The coding notification function                           **
**                 Coding_Call_CbkDataChange_EndNotification() is called after**
**                 start-up to inform the application about the coding data   **
**                 status. Before that coding values may not be used.         **
**                                                                            **
**                 If requested, this function restores the coding default    **
**                 values from ROM backup.                                    **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE) Coding_MainFunction( void )
{
                                            /* local semaphore to avoid       */
                                            /* concurrent calls of            */
                                            /* Coding_MainFunction            */
   static boolean functionInUse = FALSE;
                                            /* local variable is only set     */
                                            /* during first run of            */
                                            /* Coding_MainFunction            */
   static boolean functionFirstRun = TRUE;
                                            /* flag to execute MainFunction   */
   boolean executeFlag = FALSE;
                                            /* NvM request result             */
   NvM_RequestResultType nvmRequestResult = NVM_REQ_NOT_OK;


                                  /* if Coding_MainFunction can be executed   */
   if (   ( codingState == CODING_STATE_IDLE )
       || ( codingState == CODING_STATE_DATA_CHANGED ) )
   {
                                            /* enter critical section         */
      SchM_Enter_Coding( SCHM_CODING_EXCLUSIVE_AREA_0 );

                                  /* if Coding_MainFunction is not in use     */
      if ( functionInUse == (boolean)FALSE )
      {
                                            /* function is in use now         */
         functionInUse = TRUE;
                                            /* set MainFunction execute flag  */
         executeFlag = TRUE;
      }
                                            /* leave critical section         */
      SchM_Exit_Coding( SCHM_CODING_EXCLUSIVE_AREA_0 );

      if ( executeFlag == (boolean)TRUE )
      {
                                            /* get status of the NVRAM mirror */
                                            /* containing the coding data     */
         Coding_Call_NvmBlockData_GetErrorStatus( &nvmRequestResult );

                                  /* if the coding data NVRAM mirror is not   */
                                  /* currently in use by a NVM operation      */
         if ( nvmRequestResult != NVM_REQ_PENDING )
         {
                                            /* get status of the NVRAM mirror */
                                            /* containing the coding status   */
            Coding_Call_NvmBlockStatus_GetErrorStatus( &nvmRequestResult );

                                  /* if the coding status NVRAM mirror is not */
                                  /* currently in use by a NVM operation      */
            if ( nvmRequestResult != NVM_REQ_PENDING )
            {

                                  /* if coding data has changed               */
               if ( codingState == CODING_STATE_DATA_CHANGED )
               {
                                           /* get coding stamp offset         */
                  Coding_DataOffsetType stampOffset =
                     codingBlockDescriptorTable[CODING_ID_STAMP].dataOffset;
                                           /* loop counter                    */
                  uint8_least i;


                                           /* set data status to 'not coded'  */
                  codingDataStatus = CODING_DATA_NOT_CODED;

                                  /* set data status to 'coded' if coding     */
                                  /* stamp is not equal its default value     */
                  for ( i = 0; i < (uint8_least)7U; i++ )
                  {
                     if ( Coding_NvData [ stampOffset + i] != 0xFFU )
                     {
                        codingDataStatus = CODING_DATA_CODED;
                     }
                  }
               }

                                  /* if data status is 'coded'                */
                                  /* if coding stamp has not been verified    */
               if ( ( codingDataStatus == CODING_DATA_CODED ) &&
                    ( codingStampStatus == CODING_E_PENDING ) )
               {
                                            /* check if coding stamp fits to  */
                                            /* the vehicle (VIN)              */
                  codingStampStatus = CodingStampValid(
                     &Coding_NvData
                      [ codingBlockDescriptorTable[CODING_ID_STAMP].dataOffset ] );

                                  /* if coding stamp does not fit to vehicle  */
                  if ( codingStampStatus == CODING_E_NOT_OK )
                  {
                                  /* if this is a new data change             */
                     if ( codingState != CODING_STATE_DATA_CHANGED )
                     {
                                               /* notify the application         */
                        Coding_Call_CbkDataChange_StartNotification();

                                            /* set data status to 'undefined' */
                        codingDataStatus = CODING_DATA_UNDEFINED;

                                            /* don't wait for NvM afterwards  */
                                            /* because no persistent writing  */
                        codingState = CODING_STATE_DATA_CHANGED;
                     }

                                            /* set event 'wrong vehicle'      */

                                            /* DEM returns an error in case   */
                                            /* of an explicitly locked event  */
                                            /* memory, DEM queue overflow     */
                                            /* dectected by DET-Check         */
                     (void)Coding_Call_DemEventWrongVehicle_SetEventStatus( DEM_EVENT_STATUS_FAILED );

                                            /* restore defaults but do        */
                                            /* not save them persistent       */
                     CodingRestoreDefaults( FALSE );

                                            /* set data status to 'not coded' */
                     codingDataStatus = CODING_DATA_NOT_CODED;
                  }
               }

                                  /* if coding data has changed               */
               if ( codingState == CODING_STATE_DATA_CHANGED )
               {
                                            /* protect the NvM coding data    */
                  Coding_Call_NvmBlockData_Administration_SetBlockProtection( TRUE );

                                  /* if data is in status 'coded'             */
                  if ( codingDataStatus == CODING_DATA_CODED )
                  {
                                            /* clear all coding events        */

                                            /* DEM returns an error in case   */
                                            /* of an explicitly locked event  */
                                            /* memory, DEM queue overflow     */
                                            /* dectected by DET-Check         */
                     (void)Coding_Call_DemEventNotCoded_SetEventStatus( DEM_EVENT_STATUS_PASSED );
                     (void)Coding_Call_DemEventTransactionFailed_SetEventStatus( DEM_EVENT_STATUS_PASSED );
                     (void)Coding_Call_DemEventSignatureError_SetEventStatus( DEM_EVENT_STATUS_PASSED );
                     (void)Coding_Call_DemEventWrongVehicle_SetEventStatus( DEM_EVENT_STATUS_PASSED );
                     (void)Coding_Call_DemEventInvalidData_SetEventStatus( DEM_EVENT_STATUS_PASSED );
                  }
                                  /* if data is in status 'not coded'         */
                  else
                  {
                                            /* set event 'NOT CODED'          */

                                            /* DEM returns an error in case   */
                                            /* of an explicitly locked event  */
                                            /* memory, DEM queue overflow     */
                                            /* dectected by DET-Check         */
                     (void)Coding_Call_DemEventNotCoded_SetEventStatus( DEM_EVENT_STATUS_FAILED );
                  }

                                            /* switch to idle state           */
                  codingState = CODING_STATE_IDLE;

                                  /* if not first run of Coding_MainFunction  */
                  if ( functionFirstRun == FALSE )
                  {
                                            /* notify the PIA module          */
                     Coding_PiaCodingNotification();
                  }
                  else
                  {
                     functionFirstRun = FALSE;
                  }

                                            /* notify the application         */
                  Coding_Call_CbkDataChange_EndNotification( codingDataStatus );
               }
            }
         }
                                            /* release function               */
         functionInUse = FALSE;
      }
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_GetDataStatus                                       **
**                                                                            **
** DESCRIPTION   : Returns the current coding data status.                    **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : The current coding data status.                            **
**                                                                            **
** REMARKS       : This is a synchronous function.                            **
**                 It does nothing else but returning the coding data status. **
**                 The coding data status depends on the contents of the      **
**                 coding data RAM mirror.                                    **
**                 If it contains coded data from the EEPROM:                 **
**                 - the coding data status is CODING_DATA_CODED.             **
**                 If it contains default values from the ROM backup:         **
**                 - the coding data status is CODING_DATA_NOT_CODED.         **
**                 If the coding data RAM mirror content is undefined:        **
**                 - the coding data status is CODING_DATA_UNDEFINED.         **
**                   This happens:                                            **
**                   - as long as Coding_MainFunction() has not been called.  **
**                   - while a coding diagnostic session is active.           **
**                   - while restoring default values from the ROM backup.    **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_GetDataStatus( P2VAR( Coding_DataStatusType, AUTOMATIC, CODING_VAR ) dataStatus )
{
                                            /* return current data status     */
   *dataStatus = codingDataStatus;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_RequestBlock                                        **
**                                                                            **
** DESCRIPTION   : Calls a callback function that receives the pointer to the **
**                 RAM mirror data of a coding block and its size             **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : blockId: the block id of the block                         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a asynchronous function.                           **
**                 No additional checks will be done whether the data is      **
**                 valid or not.                                              **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_RequestBlock( Coding_BlockIdType blockId )
{
                                            /* pointer to coding block data   */
   P2VAR( uint8, AUTOMATIC, CODING_VAR_DCMDATA ) pData =
                             &Coding_NvData
                             [ codingBlockDescriptorTable[blockId].dataOffset ];

                                            /* call block receive function    */
   /* Deviation MISRA-1 <START> */
   Coding_Call_CbkBlock_Receive( blockId,
                                 (P2VAR( Coding_BlockDataType, AUTOMATIC, CODING_VAR_NVDATA ))pData, /* Nxtr correction to remove extraneous referencing operator since pData is a pointer to the data */
                                 codingBlockDescriptorTable[blockId].dataSize );
   /* Deviation MISRA-1 <STOP> */
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_GetBlockSize                                        **
**                                                                            **
** DESCRIPTION   : Returns the size of a coding block                         **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : blockId  : the block id of the block                       **
**                 blockSize: contains the blockSize return value             **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a synchronous function.                            **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_GetBlockSize( Coding_BlockIdType blockId,
#if (CODING_RTE_ENABLE == STD_ON)
                          P2VAR( UInt8, AUTOMATIC, CODING_VAR ) blockSize )
#else
                          P2VAR( uint8, AUTOMATIC, CODING_VAR ) blockSize )
#endif
{
                                            /* return size of data block      */
   *blockSize = codingBlockDescriptorTable[blockId].dataSize;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_SetBlockProtection                                  **
**                                                                            **
** DESCRIPTION   : Sets the write protection of a coding block.               **
**                                                                            **
** PRECONDITIONS : NVM must be initialized.                                   **
**                                                                            **
** PARAMETER     : blockId: The block id of the coding block. All block ids   **
**                          are defined by Coding.h with the following format **
**                             CODING_ID_<area>_<block>                       **
**                          with                                              **
**                             <area>  area name defined in Coding_Cfg.h      **
**                             <block> block name defined in Coding_Cfg.h     **
**                                                                            **
**                 protection: CODING_WRITE_PROTECTION_ON or                  **
**                             CODING_WRITE_PROTECTION_OFF                    **
**                                                                            **
**                 error: The returned error code                             **
**                        CODING_E_BUSY                                       **
**                                 if the coding or the NvM module is busy.   **
**                        CODING_E_NOT_OK                                     **
*                                  if the requested block is not valid.       **
**                        CODING_E_OK                                         **
**                                 if the request has been accepted.          **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a synchronuous function.                           **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_SetBlockProtection( Coding_BlockIdType blockId,
                                Coding_ProtectionType protection,
                                P2VAR( Coding_ErrorType, AUTOMATIC, CODING_VAR ) error )
{
                                            /* Standard return result         */
   Std_ReturnType result;
                                            /* NvM request result             */
   NvM_RequestResultType nvmRequestResult = NVM_REQ_NOT_OK;

                                            /* get status of the NVRAM mirror */
                                            /* containing the coding status   */
   Coding_Call_NvmBlockStatus_GetErrorStatus( &nvmRequestResult );

                                  /* if coding or NvM module is busy          */
   if ( (codingState != CODING_STATE_IDLE) ||
        (nvmRequestResult == NVM_REQ_PENDING) )
   {
                                            /* coding or nvm busy: return     */
      *error = CODING_E_BUSY;
   }
                                  /* if requested block is an invalid block   */
   else if ( blockId >= CODING_ID_STAMP )
   {
                                            /* block id is not valid: return  */
      *error = CODING_E_NOT_OK;
   }
                                  /* if everything is alright                 */
   else
   {
                                            /* save protection flag           */
      const boolean protectionFlag = Coding_GetFlag( Coding_NvStatus, blockId );

                                  /* if write protection should be set        */
      if ( protection == CODING_WRITE_PROTECTION_ON )
      {
                                            /* set write protection flag of   */
                                            /* the block                      */
         Coding_SetFlag( Coding_NvStatus, blockId );
      }
                                  /* if write protection should be cleared    */
      else
      {
                                            /* clear write protection flag of */
                                            /* the block                      */
         Coding_ClearFlag( Coding_NvStatus, blockId );
      }

                                            /* write NvM status block         */
      result = Coding_Call_NvmBlockStatus_WriteBlock();

                                  /* if request was accepted                  */
      if ( result == E_OK )
      {
                                            /* return                         */
         *error = CODING_E_OK;
      }
      else
      {
                                            /* nvm busy: report to caller     */
         *error = CODING_E_BUSY;

                                  /* if protection bit was set                */
         if ( protectionFlag != FALSE )
         {
                                            /* restore protection flag        */
            Coding_SetFlag( Coding_NvStatus, blockId );
         }
         else
         {
                                            /* restore protection flag        */
            Coding_ClearFlag( Coding_NvStatus, blockId );
         }
      }
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_GetVinCpsComparisonResult                           **
**                                                                            **
** DESCRIPTION   : Returns the result of the comparison of the vehicle        **
**                 identification number (VIN) with the coding proove stamp.  **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : - CODING_E_PENDING:                                        **
**                          if the comparison has not been done               **
**                 - CODING_E_OK:                                             **
**                          if the vehicle identification number (VIN)        **
**                          fits to the coding proove stamp (CPS)             **
**                 - CODING_E_NOT_OK:                                         **
**                          if the vehicle identification number (VIN)        **
**                          does not fit to the coding proove stamp (CPS)     **
**                                                                            **
** REMARKS       : The comparison will only be done in the following cases:   **
**                 - if the ECU is coded                                      **
**                 - if a valid VIN signal has been received                  **
**                 - if the vehicle is not moving with a speed >= 6 km/h      **
**                                                                            **
**                 After the comparison has been done, a new comparison       **
**                 will only be done after reset or recoding of the ECU.      **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_GetVinCpsComparisonResult
     (
        P2VAR( Coding_ErrorType, AUTOMATIC, CODING_VAR ) comparisonResult
     )
{
                                            /* return comparison result       */
   *comparisonResult = codingStampStatus;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_CheckSignatureOnShutdown                            **
**                                                                            **
** DESCRIPTION   : Checks if the coding data has been manipulated.            **
**                 It recalculates the signature(s) of the coding area(s)     **
**                 and compares it with the saved signature(s).               **
**                 If at least one signature is invalid it initiates the      **
**                 restoring of coding data default values from ROM backup.   **
**                                                                            **
** PRECONDITIONS : The function has to be started from a low priority task.   **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : Warning: this function may not be executed in normal       **
**                 operation. Only on ECU shutdown if the                     **
**                 Coding_MainFunction() is not triggered anymore.            **
**                 This is a synchronuos function although it takes very long.**
**                 It can't be implemented asynchronous.                      **
**                 Configure your system to start this routine from a low     **
**                 priority task to ensure the rest of the system will not    **
**                 get blocked by this routine.                               **
**                 If the the ECU is not coded this function will do nothing. **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE) Coding_CheckSignatureOnShutdown( void )
{
                                  /* if data is in status 'coded'             */
   if ( codingDataStatus == CODING_DATA_CODED)
   {
                                  /* if signature check failed                */
      if ( CodingCheckSignature() != CODING_E_OK )
      {
                                            /* restore defaults               */
         CodingRestoreDefaults( TRUE );
      }
   }
}


/*******************************************************************************
**                      Global Diagnostic API Functions                       **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_DiagReadDataByIdentifier                            **
**                                                                            **
** DESCRIPTION   : Handles ReadDataByIdentifier requests.                     **
**                                                                            **
** PRECONDITIONS : Has to be called from Rte_DcmReadDataByIdentifier()        **
**                 if the data identifier is between 0x3000 and 0x37FE.       **
**                                                                            **
** PARAMETER     : pMsgContext   : DCM message context.                       **
**               : dataIdentifier: The data identifier extracted from DCM     **
**                                 request message.                           **
**                                 Must be between 0x3000 and 0x37FE.         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a synchronous function.                            **
**                 It must be called from Cdc if a read data by identifier    **
**                 message was received with an data identifier between       **
**                 0x3000 and 0x37FE.                                         **
**                 The response values will be set directly in the DCM        **
**                 response message buffer. You only have to call             **
**                 Dcm_ProcessingDone() after the function returns.           **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_DiagReadDataByIdentifier( P2VAR( Dcm_MsgContextType, AUTOMATIC, CODING_VAR_DCMDATA ) pMsgContext,
                                      uint16 dataIdentifier )
{
                                  /* if message length is incorrect           */
   if ( pMsgContext->reqDataLen != 2U )
   {
                                            /* send negative response         */
      Coding_DiagSetNegResponse( pMsgContext, DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT );
   }
                                  /* if everything is alright so far          */
   else
   {
                                            /* descriptor of the block        */
      P2CONST( Coding_BlockDescriptorTableType, AUTOMATIC,
               CODING_CONST_DESCRIPTOR_TABLE ) pBlockDescriptorTable = NULL_PTR;
                                            /* internal block id of the block */
      uint8_least blockId;
                                            /* used to stop loop              */
      boolean stopLoop = FALSE;


                                  /* search for requested block               */
                                  /* in list of configured blocks             */
      for ( blockId = 0;
               (blockId <= (uint8_least)CODING_NUMBER_OF_BLOCKS)
            && (stopLoop == FALSE);
            blockId++
          )
      {
                                  /* if requested block was found             */
         if ( codingBlockDescriptorTable[blockId].dataIdentifier == dataIdentifier )
         {
                                             /* get the block descriptor      */
                                             /* of the block                  */
            pBlockDescriptorTable = &codingBlockDescriptorTable[blockId];

                                             /* stop searching                */
            stopLoop = TRUE;
         }
      }

                                  /* if the requested block was not found     */
      if ( pBlockDescriptorTable == NULL_PTR )
      {
                                            /* send negative response         */
         Coding_DiagSetNegResponse( pMsgContext, DCM_E_REQUESTOUTOFRANGE );
      }
                                  /* if the requested block was found         */
      else
      {
                                            /* copy block data to diagnostic  */
                                            /* response message buffer        */
                                            /* return value is a pointer to   */
                                            /* destination not an errorcode   */
         /* Deviation MISRA-2 */
         (void)Coding_Memcopy(
                        &pMsgContext->resData[2],
                        &Coding_NvData[ pBlockDescriptorTable->dataOffset ],
                        pBlockDescriptorTable->dataSize
                       );
                                            /* set length of pos. response    */
         pMsgContext->resDataLen = (uint16)(pBlockDescriptorTable->dataSize + 2);
      }
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_DiagGetSessionStartPermission                       **
**                                                                            **
** DESCRIPTION   : Allows the Cdc to change to coding session or denies it.   **
**                                                                            **
** PRECONDITIONS : Has to be called from Rte_DcmGetSesChgPermission()         **
**                 if coding session is going to be entered.                  **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : DCM_E_SESSION_NOT_ALLOWED if coding session is not allowed.**
**                 DCM_E_OK                  if coding session is allowed.    **
**                                                                            **
** REMARKS       : This is a syncronous function.                             **
**                 It must be called from Cdc before the ecu is switched      **
**                 to coding session. It checks if it is allowed to switch to **
**                 coding session.                                            **
**                 It also asks the application for permission to change to   **
**                 coding session by calling CodingAllowed() before giving    **
**                 permission to the Cdc.                                     **
**                                                                            **
*******************************************************************************/
FUNC(Dcm_StatusType, CODING_PUBLIC_CODE)
     Coding_DiagGetSessionStartPermission( void )
{
                                            /* return value of this function  */
   Dcm_StatusType retval = DCM_E_SESSION_NOT_ALLOWED;


                                  /* if the coding module is idle             */
   if (codingState == CODING_STATE_IDLE)
   {
                                  /* if coding session is allowed             */
                                  /* e.g. the vehicle is not moving           */
      if ( CodingAllowed() == CODING_E_OK )
      {
                                            /* allow writing of coding data   */
                                            /* after successful authentication*/
         codingState = CODING_STATE_SESSION_LOCKED;

                                            /* return with positive retval    */
         retval = DCM_E_OK;
      }
   }

   return retval;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_DiagWriteDataByIdentifier                           **
**                                                                            **
** DESCRIPTION   : Handles WriteDataByIdentifier requests.                    **
**                                                                            **
** PRECONDITIONS : Has to be called from Rte_DcmWriteDataByIdentifier()       **
**                 if the data identifier is between 0x3000 and 0x37FE.       **
**                                                                            **
** PARAMETER     : pMsgContext   : DCM message context.                       **
**                 dataIdentifier: The data identifier extracted from DCM     **
**                                 request message.                           **
**                                 Must be between 0x3000 and 0x37FE.         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a synchronous function.                            **
**                 It must be called from Cdc if a write data by identifier   **
**                 message was received with an data identifier between       **
**                 0x3000 and 0x37FE.                                         **
**                 The response values will be read directly from the DCM     **
**                 response message buffer. You only have to call             **
**                 Dcm_ProcessingDone() after the function returns.           **
**                 In case the data identifier is 0x37FD (coding proof stamp) **
**                 the function may take very long, because the data will be  **
**                 written to the EEPROM all at once.                         **
**                 Configure the operating system to start this routine from  **
**                 a low priority task or something to ensure the rest of     **
**                 the system will not get blocked by this routine.           **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_DiagWriteDataByIdentifier( P2VAR( Dcm_MsgContextType, AUTOMATIC, CODING_VAR_DCMDATA ) pMsgContext,
                                       uint16 dataIdentifier )
{
  /*
   * Coding nv status first write protection
   * Coding status first write protection values used for automatic write
   * protection of nv status after first writing of a coding block.
   * Size = 1 + (CODING_NUMBER_OF_BLOCKS - 1) / 8
   */
  const uint8 codingNvStatusFirstWriteProtection[CODING_NVSTATUS_IDX] =
        CODING_NVSTATUS_FIRST_WRITE_PROTECTION_INIT;
                                            /* Coding nv status buffer        */
   static uint8 codingNvStatusBuffer[sizeof(Coding_NvStatus)];
                                            /* negative response code         */
   Dcm_NegativeResponseCodeType negativeResponseCode = DCM_E_OK;


                                  /* if authentication for coding session     */
                                  /* has not been completed successfully      */
   if ( Coding_DiagGetSecurityLevel() != CODING_DIAG_SECURITY_CODING )
   {
                                            /* send negative response         */
      Coding_DiagSetNegResponse( pMsgContext, DCM_E_SECURITYACCESSDENIED );
   }
                                  /* if already authenticated                 */
   else
   {
                                  /* if coding proof stamp should be written  */
      if ( dataIdentifier == 0x37FEU )
      {
                                  /* if signature check was not successful    */
         if ( codingState != CODING_STATE_SESSION_WRITE_STAMP )
         {
                                            /* set negative response          */
            negativeResponseCode = DCM_E_CONDITIONSNOTCORRECT;
         }
                                  /* if message length is incorrect           */
         else if ( pMsgContext->reqDataLen != 9U )
         {
                                            /* set negative response          */
            negativeResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
         }
                                  /* if everything is alright                 */
         else
         {
                                  /* if coding is not allowed (v<>0)          */
            if ( CodingAllowed() != CODING_E_OK )
            {
                                            /* set negative response          */
               negativeResponseCode = DCM_E_CONDITIONSNOTCORRECT;
            }
                                  /* if coding is allowed (v==0)              */
            else
            {
                                            /* check if coding stamp fits to  */
                                            /* the vehicle (VIN)              */
               /* Deviation MISRA-2 */
               codingStampStatus = CodingStampValid( &pMsgContext->reqData[2u] );

                                  /* if coding stamp does not fit to vehicle  */
               if ( codingStampStatus == CODING_E_NOT_OK )
               {
                                            /* set event 'wrong vehicle'      */

                                            /* DEM returns an error in case   */
                                            /* of an explicitly locked event  */
                                            /* memory, DEM queue overflow     */
                                            /* dectected by DET-Check         */
                  (void)Coding_Call_DemEventWrongVehicle_SetEventStatus( DEM_EVENT_STATUS_FAILED );

                                            /* set negative response          */
                  negativeResponseCode = DCM_E_REQUESTOUTOFRANGE;
               }
                                  /* if coding stamp fits to vehicle or if    */
                                  /* ECU is not within a vehicle network      */
               else
               {
                                            /* NvM request result             */
                  NvM_RequestResultType nvmRequestResult = NVM_REQ_NOT_OK;

                                            /* copy data from diagnostic      */
                                            /* message buffer to NVRAM mirror */
                                            /* return value is a pointer to   */
                                            /* destination not an errorcode   */
                  /* Deviation MISRA-2 */
                  (void)Coding_Memcopy(
                           &Coding_NvData[ codingBlockDescriptorTable[CODING_ID_STAMP].dataOffset ],
                           &pMsgContext->reqData[2],
                           7);

                                            /* make NvM data block writeable  */
                  Coding_Call_NvmBlockData_Administration_SetBlockProtection( FALSE );

                                            /* request writing data to EEPROM */
                                            /* queue overflow check via DET   */
                                            /* during development             */
                  (void)Coding_Call_NvmBlockData_WriteBlock();

                                            /* wait for operation to finish   */
                  Coding_NvmWaitUntilBlockIsReady( CODING_NVM_DATA_BLOCK );

                                            /* get status of the NVRAM mirror */
                                            /* containing the coding data     */
                  Coding_Call_NvmBlockData_GetErrorStatus( &nvmRequestResult );

                                  /* if writing to EEPROM failed              */
                  if ( nvmRequestResult != NVM_REQ_OK )
                  {
                                            /* set negative response          */
                     negativeResponseCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                  }
                                  /* if writing to EEPROM was successful      */
                  else
                  {
                                               /* Coding status backup, used  */
                                               /* to restore Coding_NvStatus  */
                                               /* in case of an error         */
                     uint8 codingNvStatusBackup[CODING_NVSTATUS_IDX];
                                               /* counter value               */
                     uint8_least i;

                                  /* merge the write protection flags with    */
                                  /* the new ones set during the session      */
                     for ( i = 0; i < CODING_NVSTATUS_IDX; i++)
                     {
                        codingNvStatusBackup[i] = Coding_NvStatus[i];
                        Coding_NvStatus[i]     |= codingNvStatusBuffer[i];
                     }

                                            /* wait for operation to finish   */
                     Coding_NvmWaitUntilBlockIsReady( CODING_NVM_STATUS_BLOCK );

                                            /* write coding status to EEPROM  */
                                            /* overflow check via DET during  */
                                            /* development                    */
                     (void)Coding_Call_NvmBlockStatus_WriteBlock();

                                            /* wait for operation to finish   */
                     Coding_NvmWaitUntilBlockIsReady( CODING_NVM_STATUS_BLOCK );

                                            /* get status of the NVRAM mirror */
                                            /* containing the coding status   */
                     Coding_Call_NvmBlockStatus_GetErrorStatus( &nvmRequestResult );

                                  /* if writing to EEPROM failed              */
                     if ( nvmRequestResult != NVM_REQ_OK )
                     {
                                            /* restore values manually        */
                        for (i = 0; i < CODING_NVSTATUS_IDX; i++)
                        {
                           Coding_NvStatus[i] = codingNvStatusBackup[i];
                        }

                                               /* set negative response       */
                        negativeResponseCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                     }
                     else
                     {
                                            /* coding session complete        */
                        codingState = CODING_STATE_DATA_CHANGED;

                                            /* set length of pos. response    */
                        pMsgContext->resDataLen = 2;
                     }
                  }
               }
            }
         }
      }
                                  /* if an ordinary block should be written   */
      else
      {
                                  /* if coding session was locked             */
         if ( codingState == CODING_STATE_SESSION_LOCKED )
         {
                                            /* counter value               */
            uint8_least i;


                                            /* notify the application         */
            Coding_Call_CbkDataChange_StartNotification();

                                            /* set data status to 'undefined' */
            codingDataStatus = CODING_DATA_UNDEFINED;

                                  /* initialize temporary write protection    */
                                  /* flags used during coding session         */
            for ( i = 0; i < sizeof(Coding_NvStatus); i++)
            {
               codingNvStatusBuffer[i] = 0;
            }
                                  /* set coding state to 'session unlocked'   */
            codingState = CODING_STATE_SESSION_UNLOCKED;
         }

                                  /* if coding state is 'session unlocked'    */
         if ( codingState != CODING_STATE_SESSION_UNLOCKED )
         {
                                            /* set negative response          */
            negativeResponseCode = DCM_E_CONDITIONSNOTCORRECT;
         }
                                  /* if the coding session is unlocked        */
         else
         {
                                  /* if coding is not allowed (v<>0)          */
            if ( CodingAllowed() != CODING_E_OK )
            {
                                            /* set negative response          */
               negativeResponseCode = DCM_E_CONDITIONSNOTCORRECT;
            }
                                  /* if coding is allowed (v==0)              */
            else
            {
                                            /* descriptor of the block        */
               P2CONST( Coding_BlockDescriptorTableType, AUTOMATIC,
                        CODING_CONST_DESCRIPTOR_TABLE ) pBlockDescriptorTable = NULL_PTR;
                                            /* internal block id of the block */
               uint8_least blockId;
                                            /* used to stop loop              */
               boolean stopLoop = FALSE;


                                  /* search for requested block               */
                                  /* in list of configured blocks             */
               for ( blockId = 0; (blockId < (uint8_least)CODING_NUMBER_OF_BLOCKS) && (stopLoop == FALSE); blockId++ )
               {
                                  /* if requested block was found             */
                  if ( codingBlockDescriptorTable[blockId].dataIdentifier == dataIdentifier )
                  {
                                             /* get the block descriptor      */
                                             /* of the block                  */
                     pBlockDescriptorTable = &codingBlockDescriptorTable[blockId];

                                             /* stop searching                */
                     stopLoop = TRUE;
                  }
               }
                                             /* correct block id              */
               blockId--;

                                  /* if the requested block was not found     */
                                  /* or if the block is write protected       */
               if ( (pBlockDescriptorTable == NULL_PTR) ||
                    (Coding_GetFlag( Coding_NvStatus, blockId) != FALSE) )
               {
                                            /* set negative response          */
                  negativeResponseCode = DCM_E_REQUESTOUTOFRANGE;
               }
                                  /* if message length is incorrect           */
               else if ( pMsgContext->reqDataLen != (uint16)(pBlockDescriptorTable->dataSize + 2) )
               {
                                            /* set negative response          */
                  negativeResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
               }
                                  /* if everything is alright                 */
               else
               {
                                            /* pointer to coding block data   */
                  /* Deviation MISRA-2 */
                  P2VAR( uint8, AUTOMATIC, CODING_VAR_DCMDATA ) pData = &pMsgContext->reqData[2u];

                                            /* block valid flag               */
                  Coding_ErrorType blockValid = CODING_E_OK;

                                            /* check if coding block is valid */
                  /* Deviation MISRA-1 <START> */
                  Coding_Call_CbkBlockValid_Check(
                               (Coding_BlockIdType)blockId,
                               (P2VAR( Coding_BlockDataType, AUTOMATIC, CODING_VAR_NVDATA ))pData, /* Nxtr correction to remove extraneous referencing operator since pData is a pointer to the data */
                               pBlockDescriptorTable->dataSize,
                               &blockValid);
                  /* Deviation MISRA-1 <STOP> */


                                  /* if coding block is not valid             */
                  if ( blockValid != CODING_E_OK )
                  {
                                            /* set event 'invalid data'       */

                                            /* DEM returns an error in case   */
                                            /* of an explicitly locked event  */
                                            /* memory, DEM queue overflow     */
                                            /* dectected by DET-Check         */
                     (void)Coding_Call_DemEventInvalidData_SetEventStatus( DEM_EVENT_STATUS_FAILED );

                                            /* set negative response          */
                     negativeResponseCode = DCM_E_REQUESTOUTOFRANGE;
                  }
                                  /* if coding block is valid                 */
                  else
                  {
                                            /* copy data from diagnostic      */
                                            /* message buffer to NVRAM mirror */
                                            /* return value is a pointer to   */
                                            /* destination not an errorcode   */
                     /* Deviation MISRA-2 */
                     (void)Coding_Memcopy(
                                    &Coding_NvData
                                          [ pBlockDescriptorTable->dataOffset ],
                                    &pMsgContext->reqData[2],
                                    pBlockDescriptorTable->dataSize
                                   );

                                  /* if the block has write once protection   */
                     if ( Coding_GetFlag( codingNvStatusFirstWriteProtection, (uint8)blockId ) != FALSE )
                     {
                                            /* set the write protection flag  */
                                            /* of the block in the temporary  */
                                            /* write protection buffer        */
                        Coding_SetFlag( codingNvStatusBuffer, (uint8)blockId );
                     }
                                            /* set length of pos. response    */
                     pMsgContext->resDataLen = 2;
                  }
               }
            }
         }
      }

                                  /* if negative response should be send      */
      if ( negativeResponseCode != DCM_E_OK )
      {
                                            /* set event 'transaction failed' */

                                            /* DEM returns an error in case   */
                                            /* of an explicitly locked event  */
                                            /* memory, DEM queue overflow     */
                                            /* dectected by DET-Check         */
         (void)Coding_Call_DemEventTransactionFailed_SetEventStatus( DEM_EVENT_STATUS_FAILED );

                                            /* abort coding session           */
         CodingAbortSession( pMsgContext, negativeResponseCode );
      }
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_DiagRoutineControlCheckSignature                    **
**                                                                            **
** DESCRIPTION   : Handles RoutineControl requests.                           **
**                                                                            **
** PRECONDITIONS : Has to be called from Rte_DcmRoutineControl()              **
**                 if sub function is 0x01 (Start routine)                    **
**                 and routine id is 0x0F01 (Check Coding Signature)          **
**                                                                            **
** PARAMETER     : pMsgContext: DCM message context.                          **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a synchronous function.                            **
**                 It must be called from Cdc if a routine control check      **
**                 signature message was received.                            **
**                 The response values will be set directly in the DCM        **
**                 response message buffer. You only have to call             **
**                 Dcm_ProcessingDone() after the function returns.           **
**                 The function may take very long.                           **
**                 Configure the operating system to start this routine from  **
**                 a low priority task or something to ensure the rest of     **
**                 the system will not get blocked by this routine.           **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_DiagRoutineControlCheckSignature( P2VAR( Dcm_MsgContextType, AUTOMATIC, CODING_VAR_DCMDATA ) pMsgContext )
{
                                            /* negative response code         */
   Dcm_NegativeResponseCodeType negativeResponseCode = DCM_E_OK;


                                  /* if authentication for coding session     */
                                  /* has not been completed successfully      */
   if ( Coding_DiagGetSecurityLevel() != CODING_DIAG_SECURITY_CODING )
   {
                                            /* send negative response         */
      Coding_DiagSetNegResponse( pMsgContext, DCM_E_SECURITYACCESSDENIED );
   }
                                  /* if already authenticated                 */
   else
   {
                                  /* if the message length is not equal 3     */
      if ( pMsgContext->reqDataLen != 3U )
      {
                                            /* set negative response          */
         negativeResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
                                  /* if coding state not 'session unlocked'   */
      else if ( codingState != CODING_STATE_SESSION_UNLOCKED )
      {
                                            /* set negative response          */
         negativeResponseCode = DCM_E_CONDITIONSNOTCORRECT;
      }
                                  /* if the coding session is unlocked        */
      else
      {
                                            /* result of signature check      */
         Coding_ErrorType checkSignatureResult;


                                            /* prevent the coding module from */
                                            /* writing from now on            */
         codingState = CODING_STATE_SESSION_CHECK_SIGNATURE;

                                            /* check signature                */
         checkSignatureResult = CodingCheckSignature();

                                  /* if signature check failed                */
         if ( checkSignatureResult != CODING_E_OK )
         {
                                            /* set response                   */
                                            /* 'signature check failed'       */
            /* Deviation MISRA-2 */
            pMsgContext->resData[3] = 1;
         }
                                  /* if signature check was successful        */
         else
         {
                                            /* enable writing of coding stamp */
            codingState = CODING_STATE_SESSION_WRITE_STAMP;

                                            /* set response                   */
                                            /* 'signature check successful'   */
            /* Deviation MISRA-2 */
            pMsgContext->resData[3] = 0;
         }
                                            /* set length of pos. response    */
         pMsgContext->resDataLen = 4;
      }

                                  /* if negative response should be send      */
                                  /* or if signature check failed             */
      /* Deviation MISRA-2 */
      if ( (negativeResponseCode != DCM_E_OK) ||
           (pMsgContext->resData[3] == 1U) )
      {
                                            /* abort coding session           */
         CodingAbortSession( pMsgContext, negativeResponseCode );
      }
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_DiagSessionEndIndication                            **
**                                                                            **
** DESCRIPTION   : Informs the coding module about the end of a coding        **
**                 session.                                                   **
**                                                                            **
** PRECONDITIONS : Has to be called from Rte_DcmSesCtrlChangeIndication()     **
**                 if coding session is going to be leaved.                   **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a synchronous function. If must be called from Cdc **
**                 if the coding session is to be leaved.                     **
**                 It restores the default values from ROM backup if the      **
**                 session has been aborted by error or by timeout.           **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE) Coding_DiagSessionEndIndication( void )
{
   switch ( codingState )
   {
                                  /* if session ends before anything happened */
      case CODING_STATE_SESSION_LOCKED:

                                            /* go back to idle                */
         codingState = CODING_STATE_IDLE;

         break;

                                  /* if session timeout occured when coding   */
                                  /* session has not been completed           */
      case CODING_STATE_SESSION_UNLOCKED:
      case CODING_STATE_SESSION_CHECK_SIGNATURE:
      case CODING_STATE_SESSION_WRITE_STAMP:

                                            /* restore defaults               */
         CodingRestoreDefaults( TRUE );

                                            /* notify the application         */
         codingState = CODING_STATE_DATA_CHANGED;

         break;

                                  /* in all other cases                       */
      default:
                                            /* do nothing                     */
         break;
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_DiagGetNumberOfCodedAreas                           **
**                                                                            **
** DESCRIPTION   : Returns the number of valid CAF ids.                       **
**                 Each coding area has its own CAF id.                       **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** RETURN        : number of coded areas                                      **
**                                                                            **
** REMARKS       : This is a synchronous function.                            **
**                 It is intended to be used by Cdc when a SVK reading        **
**                 request was received.                                      **
**                                                                            **
*******************************************************************************/
FUNC(uint16, CODING_PUBLIC_CODE) Coding_DiagGetNumberOfCodedAreas( void )
{
                                            /* number of valid CAF ids        */
   uint16 validCafIds = 0;


                                            /* if valid data is coded         */
   if ( codingDataStatus == CODING_DATA_CODED )
   {
                                            /* set number of valid CAF ids    */
      validCafIds = CODING_NUMBER_OF_AREAS;
   }

                                            /* return number of valid CAF ids */
   return validCafIds;
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_DiagGetCafIdsOfCodedAreas                           **
**                                                                            **
** DESCRIPTION   : Returns the CAF ids of all valid coding areas.             **
**                 Each coding area has its own CAF id.                       **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : pData: buffer to which the CAF ids shall be copied.        **
**                                                                            **
** RETURN        : number of bytes copied                                     **
**                                                                            **
** REMARKS       : This is a synchronous function.                            **
**                 It is intended to be used by Cdc when a SVK reading        **
**                 request was received.                                      **
**                                                                            **
*******************************************************************************/
FUNC(uint16, CODING_PUBLIC_CODE)
     Coding_DiagGetCafIdsOfCodedAreas( P2VAR( uint8, AUTOMATIC, CODING_VAR_DIAGDATA ) pData )
{
                                            /* number of bytes copied         */
   uint16 copiedBytes = 0;


                                            /* if valid data is coded         */
   if ( codingDataStatus == CODING_DATA_CODED )
   {
                                            /* index of area descriptor       */
      uint8_least areaId;
                                            /* data offset of CafId block     */
      volatile uint16 dataOffsetOfCafIdBlock;


                                  /* iterate all coding areas                 */
      for ( areaId = 0; areaId < (uint8_least)CODING_NUMBER_OF_AREAS; areaId++ )
      {
                                            /* get data offset of CafId block */
         dataOffsetOfCafIdBlock = codingAreaDescriptorTable[areaId].dataOffsetOfSignatureBlock - 8U;

                                            /* copy the CAF ids of all areas  */
                                            /* return value is a pointer to   */
                                            /* destination not an errorcode   */
         /* Deviation MISRA-2 */
         (void)Coding_Memcopy(&pData[areaId * 8U],
                              &Coding_NvData[ dataOffsetOfCafIdBlock ],
                              8
                             );
                                            /* set number of bytes copied     */
         copiedBytes += 8;
      }
   }

                                            /* return number of bytes copied  */
   return copiedBytes;
}


#define CODING_STOP_SEC_CODE
#include "MemMap.h"


/*** End of file **************************************************************/
