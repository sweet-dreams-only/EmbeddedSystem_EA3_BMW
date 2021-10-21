/*******************************************************************************
**                                                                            **
**  SRC-MODULE: diag.c                                                        **
**                                                                            **
**  Copyright (C) BMW Group 2010                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Implementation of common (application and bootloader)         **
**              diagnostic services                                           **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
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
** dabu         Daniel Buder               EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** cma          Chr. Mueller-Albrecht      BMW                                **
** sc           Juergen Scherg             EB Automotive                      **
** jetc         Jean-Jacques Tchouto       EB Automotive                      **
** dare         Daniel Reiss               EB Automotive                      **
** jetc         Jean-Jacques Tchouto       EB Automotive                      **
** ke           Kai Esbold                 EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
** anht         Andreas Hartmann           EB Automotive                      **
** ft           Florian Tausch             MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V7.0.4: 07.09.2010,   ft: CR70737: added missing compiler abstraction
 * V7.0.3: 22.04.2010, anht: CR61839/CR70426: added support for ASC3.x / make common
 *                                            files between Bac and Sc6
 * V7.0.2: 20.04.2010, anam: CR70288: Change storage classes in compiler abstraction for Diag
 * V7.0.1: 27.01.2010, gema: CR70526: Compiler switches shall have defined values
 * V7.0.0: 27.10.2009, gema: CR70426: diag/bootdiag: DCM Paged-Processing doesn't
 *                                    work
 * V6.0.0: 03.06.2009, hauf: CR61622: reworked by using functions with ECC/CRC
 *                                    handling from new Swe module
 *                                    removed unnecessary includes
 *                                    use Make32Bit instead of Dcm_Make32Bit
 *                                    removed compiler warnings
 * V5.0.0: 05.11.2008, miwe: CR61521: Excluded Application ExtendedSession code
 *                                    from compilation in Bootloader
 * V4.2.0: 02.09.2008, olgo: CR61431: separated bootloader and bootmanager
 *         18.08.2008, dabu: CR61347: changed Application Extended Session
 *                                    handling according LH FP part 5 v09
 * V4.1.0: 13.09.2007, ke  : CR61209: Bootloading does not vanished random number
 * V4.0.2: 05.04.2007, miwe: removed compiler warning
 * V4.0.1: 01.12.2006, miwe: CR60893: fixed compiler error when
 *                           'NUMBEROFSVKBACKUPS == 0u'
 * V4.0.0: 04.11.2006, olgo: fixed NvStatusByte problem
 *                           + rename and expand WriteNvData to OperateNvData
 *         31.10.2006, miwe: CR60592: moved data from unpaged to paged RAM
 *         23.10.2006, dare: adaptions for 16 platforms
 *         12.10.2006, miwe: MISRA checked
 *         01.10.2006, olgo: delayed positive response handling of ecu reset an
 *                           session change to programming session request
 *         21.09.2006, olgo: CR60738: SWEDevelopmentInfoField is 255 byte
 *         11.09.2006, olgo: some changes after review
 *         31.08.2006, olgo: replaced nv memory write operations by function
 *                           'WriteNvData'
 *                           + correct order of SVK reading
 *         29.08.2006, sc  : added '#include Memif.h'.
 *                     dabu: CR60732: neg.Resp. ResponseTooLong if paged
 *                                    processing not used at too long responses
 *                           - corrected DCM_BUFFER_SIZE checks
 *                           - reset of static variables in case of canceled
 *                             paged processing
 *         22.08.2006, cma : non volatile data is accessed via MemIf instead of
 *                           EepIf => both Fee and Eep can be used
 *                     olgo: adaptions according to LH FP v07:
 *                           - current SVK only lists SGBM's of signature
 *                             checked SWEs
 *                     miwe: - FP_5029: removed TLRT and TPRG from
 *                                      'ReadSweDevelopmentInfo'
 *                           - renamed DiagService 'ReadSweDevelopmentInfo' to
 *                             'ReadDevelopmentInfo'
 *                           - adapted 'CheckSWEProgrammingStatus' according to
 *                             FP_4462
 *                           - removed ReadDataById(MaxBlockLength),
 *                             removed 'FlashBlockLength' from
 *                             'sharedBootROMData' because it's not needed in
 *                             the application any more
 *                           - ReadDataById(EcuManufacturingData) is now
 *                             mandatory: removed pre processor switches
 *                           - renamed ReadDataById(EcuId) to
 *                             ReadDataById(EcuSerialNumber)
 *                           - added new SWEProgrammingStatus type
 *                             'PROGSTAT_MEMORYSUCCESSFULLYERASED'
 *                           - moved functions 'CheckProgDepStatus' and
 *                             'CheckSWEProgrammingStatus' from 'diag' to
 *                             'bootdiag'
 *                           - implemented preassigned address and length format
 *                             identifier according to FP_5871
 *                           - process classes altered
 *         21.08.2006, dare: CR60741: Dcm_SeedReady() and Dcm_CompareKeyReady()
 *                                    replaced
 *         18.08.2006, jetc: added memory map section extension
 *         23.06.2006, miwe: 'sharedBootROMData' and 'HwDescData' are linked near
 *                           to save ROM during the frequent access in 'diag' and
 *                           'bootdiag'
 *         21.06.2006, miwe: implemented run length encoding to
 *                           'ReadDataById(MemSegTable)'
 *         20.06.2006, miwe: restructured the sharing of data between bootloader
 *                           and application
 *         18.05.2006, miwe: using type flash driver type 'flashAddress_t' for
 *                           all kind of flash addresses
 * V3.0.1: 09.08.2006, dabu: CR60688: neg.Resp. if SVK-Plant with initial values
 * V3.0.0: 21.06.2006, olgo: CR60584: if an BLU was found check only programming
 *                                    status of SWE1
 * V2.1.0: 24.05.2006, dabu: CR60627: removed error with activated
 *                                    paged buffering
 * V2.0.0: 24.04.2006, miwe: 'FLASH_BLOCK_LEN' length check removed because it
 *                           is calculated in 'AddressTable.c'
 *                     ke  : + SC_MEMCPY changed to SC_MEMCPY_ROM
 *                           + init RetVal in CheckProgDepStatus unconditional
 *         20.04.2006, miwe: + renamed parameter of
 *                             'ApplDcmReadDataByIdentifierActiveDiagSession'
 *                           + RT2823: added compiler abstraction symbols for
 *                             EepIf function calls
 *         31.03.2006, cma : CR60215: compiler warnings removed
 *                           data copy operations optimized (DIAG_ENDIANESS_FITS)
 *         17.03.2006, cma : CheckSWEProgrammingStatus optimized
 *                           Formatting revised
 *                           Checking of #defines done by preprocessor instead
 *                           during runtime
 *         15.03.2006, olgo: replace EEPIF_CONST_PTR with const
 *         10.03.2006, miwe: MISRA checked
 *         08.03.2006, dabu: CR60445: paged buffer processing implemented
 *         28.02.2005, olgo: include for Std_Types.h added
 *         28.02.2006, dabu: CR60445: check whether dcm buffer size < 350
 *                           + check RDByID-services whether the response fit
 *                             into the dcm buffer
 *         27.02.2006, miwe: DCM splitted task concept (task decoupling)
 *         23.02.2006, mm  : adaptations regarding 'SWEProgrammingStatus',
 *                           former 'SweStatus'
 *         16.02.2006, hauf: Coding: Changed function names to get valid CAF ids
 *         06.02.2006, dabu: Bootloader adaptions according to LH FP v05:
 *                           + added 'R.D.B.Id.ECUMANUFACTURINGDATA' (0xF18B)
 *                     miwe: + handling of (SWE_DEV_INFO_LENGTH == 0u) adapted
 *                           + HWEDevInfo support added
 *                           + 'MemSegTable' is shared between APPL & BL =>
 *                             moved to BOOTADDRESSTABLE section
 *                           + 'CheckProgDepStatus' added
 *         01.02.2006, dabu: CR60419: added 'R.D.B.Id.ECUID' (0xF18C)
 *                           changeover to usage of HwDescData from DataLogistic
 * V1.6.0: 20.12.2005, olgo: response of current SVK in function 'GetCurrentSvk'
 *                           changed
 * V1.5.0: 28.11.2005, miwe: CR60304: moved 'R.D.B.Id.StandardCoreVersion' to
 *                           'diag.c/-h'
 * V1.4.1: 25.11.2005, dabu: CR60359: added request length check for service 11
 * V1.4.0: 18.11.2005, hauf: added include of coding header file
 * V1.3.0: 15.11.2005, miwe: 'Bootloader_Cfg.h' include added
 * V1.2.0: 15.11.2005, dabu: length check at ECUReset
 * V1.1.0: 11.11.2005, miwe: added 'FLASH_DRIVER_SRC_ALIGNMENT' to
 *                           'DCM_BUFFER_SIZE' check
 * V1.0.1: 31.10.2005, miwe: CR60215: removed compiler warnings
 * V1.0.0: 21.10.2005, miwe: + ASR-DCM integration,
 *                           + Merged 'appldiag.c' with 'bootdiag.c',
 *                           + Common functions moved to 'diag.c'
 */

#ifndef BOOTMANAGER
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* -------------------------------------------------------------------------- */
#include "Std_Types.h"         /* module own header file                      */
/* -------------------------------------------------------------------------- */
#include "diag.h"              /* module own header file                      */
/* -------------------------------------------------------------------------- */
#include "bootmain.h"          /* for 'WriteNvData' and 'WaitMemDriverReady'  */
                               /* prototypes                                  */
/* -------------------------------------------------------------------------- */
#include "sc_target.h"         /* Contains  architecture independent general  */
                               /* definitions. E.g. prototype for function    */
                               /*'ResetEcu'                                   */
/* -------------------------------------------------------------------------- */
#include "sc_ee_data.h"        /* Contains extern declarations of structs     */
                               /* with non volatile bootloader data. They are */
                               /* accessed in the subsequent diagnostic       */
                               /* services.                                   */
/* -------------------------------------------------------------------------- */
#include "sc_target_arch.h"    /* Contains architecture specific general      */
                               /* definitions.                                */
/* -------------------------------------------------------------------------- */
#include "sc_types.h"          /* Contains architecture independent           */
                               /* typedefinitions that shall be unique for    */
                               /* all modules.                                */
/* -------------------------------------------------------------------------- */
#include "Bootloader_Cfg.h"    /* Programming specific timing parameters      */
/* -------------------------------------------------------------------------- */
#include "AddressTable.h"      /* Header file dedicated to 'AddressTable.c'.  */
/* -------------------------------------------------------------------------- */
#include "DataLogistic.h"      /* SVK internal structure definition           */
/* -------------------------------------------------------------------------- */
#include "Swe.h"               /* Contains SWE access functions               */
/* -------------------------------------------------------------------------- */
#include "Dcm.h"               /* DCM Api                                     */
/* -------------------------------------------------------------------------- */
#include "os.h"                /* ProOSEK header file.                        */
/* -------------------------------------------------------------------------- */
#include "flash.h"             /* Flash API for 'flashAddress_t'              */
/* -------------------------------------------------------------------------- */

#ifdef BOOTLOADER
   #include "Boot_Src_Cfg.h"   /* for BOOT_NV_DATA_OFFSET                     */
   #include "Boot_Crypto.h"    /* Crypto routines                             */
   #include "MemIf.h"          /* Contains external declarations for Memory   */
                               /* Abstraction Interface. It is only used by   */
                               /* the Bootloader.                             */
#else
   #include "Appl_Crypto.h"    /* include crypto routines                     */
   #include "applmain.h"       /* for ApplInititateShutdown                   */
 #if (SC_CODING_ENABLE == STD_ON)
   #include "Coding_Dcm.h"     /* Coding module DCM services                  */
 #endif
#endif

/* -------------------------------------------------------------------------- */


/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/*

(1) Violation: MISRA Rule 101
    Arithmetic operations shall not be performed on pointers - even with the
    value "1".
    Reason: code size optimization

(2) Violation: MISRA Rule 82
    More then one 'return' paths are used to make the code easier to read (e.g
    checking of preconditions), to save stack, to decrease nesting depth and to
    speedup execution

(3) Violation: MISRA Rule 63
    A switch statement with only 2 branches should usually be replaced with an
    "if ... else" construct.
    Reason: The amount of switch case statements depends on macro definitions
    and the code is easier to extend

(4) Violation: MISRA Rule 33
    The nesting deepth is decreased, when a right hand operand that has side
    effects is used. In addition it decreases the code size in some cases when
    only one exception handling must be implemented

(5) Violation: MISRA Rule 43
    This exception is created by a bug in the QAC-MISRA checker that doesn't
    support the autosar compiler abstraction

*/


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*
 * A diagnostic requirement is, that the dcm buffer has at least 350 bytes.
 */
#if (DCM_BUFFER_SIZE < 350u)
   #error "diag.c: DCM_BUFFER_SIZE too small - at least 350 bytes are necessary"
#endif

#ifdef BOOTLOADER
   #if (SC_BOOT_CRYPTO_ENABLE == STD_ON)
      #define SC_CRYPTO_ENABLE STD_ON
   #else
      #define SC_CRYPTO_ENABLE STD_OFF
   #endif
#else
   #if (SC_APPL_CRYPTO_ENABLE == STD_ON)
      #define SC_CRYPTO_ENABLE STD_ON
   #else
      #define SC_CRYPTO_ENABLE STD_OFF
   #endif
#endif

#define RESPONSE_FIT_INTO_BUFFER   0xFFFFu

/* Calculate the index of the previous element in a fifo buffer               */
#define GetPrevElementInFifo(num,prev,maxelem)                                 \
                                      (((uint8)(num) >= (uint8)(prev)) ?       \
                                        (uint8)((uint8)(num) - (uint8)(prev)): \
                                        (uint8)((uint8)(maxelem) -             \
                                        ((uint8)(prev) - (uint8)(num) ) )      \
                                      )


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define DIAG_START_SEC_CODE
#include "MemMap.h"

#ifdef BAC
   static uint8  GetNumberOfElementsInReadMemorySegmentationTable (void);
#else
	static FUNC(uint8, DCM_APPL_CODE) GetNumberOfElementsInReadMemorySegmentationTable ( void );
#endif /* Defined BAC */

#ifdef BAC
   static FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvk
               (
                       CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
              CONST(SvkHistoryType, DCM_CONST)                         SvkHistory,
              CONST(uint8, DCM_CONST)                                  SvkBackupNumber
          );
#else
   static void ApplDcmReadDataByIdentifierSvk
          (
                       Dcm_MsgContextType * const pMsgContext,
                 const SvkHistoryType             SvkHistory,
                 const uint8                      SvkBackupNumber
               );

#endif /* Defined BAC */

#if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
   #ifdef BAC
   static FUNC(uint8, DCM_APPL_CODE) GetCurrentSvkNear
          (
		     P2VAR(uint8, DCM_APPL_DATA) dataPtrNear,
			 VAR(uint16, DCM_APPL_DATA) dataLen
		  );
   #else
   static void GetCurrentSvkNear
          (
		     uint8 * dataPtrNear, uint16 dataLen
	      );
   #endif /* Defined BAC */
#endif /* DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE                              */

#define DIAG_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define DIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

   /*
    * Pending diag context type
    * Used to save diag parameters for asynchronous processing in
    * 'BackgroundTask'
    */
   VAR(pendingDiagContextType, DCM_VAR) pendingDiagContext;

   /*
    * used to save information for special ecu reset request handling
    */
   VAR(EcuResetHandlingType, DCM_VAR) ecuresetHandling;

#define DIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#define DIAG_START_SEC_VAR_NO_INIT_16BIT
#include "MemMap.h"

   #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
      /*
       * global variable to save the actual position to write the svk via
       * paged buffer processing
	   
       */
      static uint16 gSVKLength;
   #endif /* DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE                           */

#define DIAG_STOP_SEC_VAR_NO_INIT_16BIT
#include "MemMap.h"

#define DIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

   /*
    * Security access params type
    * Used to save security access parameters for asynchronous processing in
    * 'BackgroundTask'
    */
   static VAR(SecurityAccessParamsType, DCM_VAR) SecurityAccessParams;

   #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
      /*
       * global variable to save the actual position to write the svk via
       * paged buffer processing
       */
   static P2VAR(uint8, AUTOMATIC, DCM_VAR) gpSvk;
   #endif /* DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE                           */

#define DIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define DIAG_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

   static uint8_least iLoopStart = (uint8_least)0;    /* static loop variable */

   static uint8_least iStep      = (uint8_least)0;    /* static step variable */

#define DIAG_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define DIAG_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : GetNumberOfElementsInReadMemorySegmentationTable           **
**                                                                            **
** DESCRIPTION   : Calculate the number of elements, that will occur in the   **
**                 MemorySegmentationTable after run length encoding          **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData.MemSegTable                              **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : uint8: The number of elements in the                       **
**                        MemorySegmentationTable                             **
**                                                                            **
** REMARKS       : The result ist stored static, for further use              **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(uint8, DCM_APPL_CODE) GetNumberOfElementsInReadMemorySegmentationTable( void )
#else
static uint8 GetNumberOfElementsInReadMemorySegmentationTable(void)
#endif /* Defined BAC */
{
   static  uint8            numberOfElements          = (uint8)0;
           uint8_least      iLoop;
                                             /* holds temporary addresses     */
           flashAddress_t   expectedStartAddress = (flashAddress_t)0;
           flashAddress_t   expectedSize         = (flashAddress_t)0;
           flashAddress_t   nextStartAddress;
           flashAddress_t   currentSize;

   P2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                            pCurrentStartAddress;

   if (numberOfElements != (uint8)0)
   {
      /* don't calculate it again ...                                         */
      return numberOfElements;
   }

   for ( iLoop = (uint8_least)0;
         iLoop < (uint8_least)FLASH_SEGMENT_NUMBER_ALL;
         iLoop++
       )
   {
      pCurrentStartAddress = &sharedBootROMData.MemSegTable[iLoop][0];
      nextStartAddress     = sharedBootROMData.MemSegTable[iLoop][1] +
                             (flashAddress_t)0x01;
      currentSize = nextStartAddress - *pCurrentStartAddress;

      if ( (*pCurrentStartAddress == expectedStartAddress) &&
           (currentSize           == expectedSize)
         )
      {
         /*
          * A same sized, bordering flash segment was found:
          * No additional element in the MemorySegmentationTable is necessary
          */
      }
      else
      {
         /*
          * An other element in the MemorySegmentationTable is necessary
          */
         ++numberOfElements;
      }

      expectedStartAddress = nextStartAddress;
      expectedSize         = currentSize;
   }

   return numberOfElements;
} /* end of function 'GetNumberOfElementsInReadMemorySegmentationTable'       */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierSvk                             **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F102_SVK_SYSTEM_SUPPLIER /                        **
**                 DIAG_DID_F103_SVK_PLANT /                                  **
**                 DIAG_DID_F1xx_SVK_BACKUP                                   **
**                 Read the system supplier, plant or backup SVK              **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : SvkHistoryMemory                                           **
**                                                                            **
** PARAMETER     : pMsgContext     : diagnostic context                       **
**                 SvkHistory      : system supplier, plant or backup SVK     **
**                 SvkBackupNumber : backup number, in case of backup SVK     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvk
     (
              CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
          CONST(SvkHistoryType, DCM_CONST)                         SvkHistory,
          CONST(uint8, DCM_CONST)                                  SvkBackupNumber
     )
#else
static void ApplDcmReadDataByIdentifierSvk
       (
              Dcm_MsgContextType * const pMsgContext,
        const SvkHistoryType             SvkHistory,
        const uint8                      SvkBackupNumber
	   );
#endif /* Defined BAC */
{
   #ifdef BAC
   P2VAR(uint8, AUTOMATIC, COMMON_VAR) pSvk;
   #else
   uint8* pSvk;
   #endif /* Defined BAC */
   uint8 tmpSvkBackupNumber;

   switch (SvkHistory)
   {
      case SVKHISTORY_SYSTEMSUPPLIER:
         /* svk backup of system supplier should be read                      */
         pSvk = &SvkHistoryMemory.SvkSysSupp[0];
         break;
      case SVKHISTORY_PLANT:
         /* svk backup of plant should be read                                */
         pSvk = &SvkHistoryMemory.SvkPlant[0];
         break;
      case SVKHISTORY_BACKUP:                                     /* no break */
      default:
#if (NUMBEROFSVKBACKUPS > 0)
         if ( SvkBackupNumber < (uint8)NUMBEROFSVKBACKUPS )
         {
            /*
             * Calculate position that have to read from svk history memmory.
             * Remark: SvkBackupNumber = 0 means the last backup stored in
             *         history memory during flash download.
             * Remark: The SVK backup memory is a ring buffer
             */
            tmpSvkBackupNumber = SvkHistoryMemory.SvkBackupFIFOCounter;

            tmpSvkBackupNumber = GetPrevElementInFifo
                                    ( tmpSvkBackupNumber,
                                      SvkBackupNumber + (uint8)1,
                                      NUMBEROFSVKBACKUPS
                                    );

            /* normal svk backup should be read                               */
            pSvk = &SvkHistoryMemory.SvkBackup[tmpSvkBackupNumber][0];
         }
         else
#endif /* (NUMBEROFSVKBACKUPS > 0)                                            */
         {
            /*
             * normal svk backup should be read but this backup is not
             * configured in this case send negative response an return here
             */
            Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);

            #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
               Dcm_ProcessingDone(pMsgContext);
            #endif

            return;
         }
         break;
   }

   /*
    * check if SVK history entry has initial value. That means that the
    * requested backup was not written before
    */
   if ( pSvk[0] != sharedBootROMData.SvkVersion )
   {
      /* the requested backup was not written before                          */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_CONDITIONSNOTCORRECT);

      #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
         Dcm_ProcessingDone(pMsgContext);
      #endif

      return;
   }

   /* check the response data length, whether they fit into the dcm buffer    */
   if ( ((uint16)SVK_BACKUP_SIZE + 2) <= pMsgContext->resMaxDataLen )
   {
      (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&pMsgContext->resData[2],
                           (const void SC_FAR_POINTER)pSvk,
                           SVK_BACKUP_SIZE
                         );

      /* send positive response                                               */
      pMsgContext->resDataLen = (uint16)((uint16)2 + (uint16)SVK_BACKUP_SIZE);

      #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
      Dcm_ProcessingDone(pMsgContext);
      #endif
   }
   else
   {
      /* response data don't fit into the dcm buffer                          */
      #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
         /* paged buffer processing is enabled                                */
         static const Dcm_PagedBufferCallbackType pPBCallbackFunc
                              = { ApplDcmProcessReadSVK,
                                  ApplDcmCancelPagedBufferProcessing,
                                  ApplDcmPagedBufferProcessingConfirmation
                                };
         gSVKLength = (uint16)SVK_BACKUP_SIZE;
         gpSvk      = pSvk;

         /* set response length                                               */
         pMsgContext->resDataLen = (uint16)( (uint16)2 +
                                             (uint16)SVK_BACKUP_SIZE
                                           );

         /* start paged buffer processing                                     */
        #ifdef BAC
            Dcm_StartPagedProcessing(pMsgContext);
        #else
            Dcm_StartPagedProcessing(pMsgContext, &pPBCallbackFunc);
        #endif /* Defined BAC */
      #else
         /*
          * paged buffer processing is disabled -> data can't transmitted
          */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_RESPONSETOOLONG);
      #endif
   }
} /* end of function 'ApplDcmReadDataByIdentifierSvk'                         */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : GetCurrentSvkNear                                          **
**                                                                            **
** DESCRIPTION   : This function is needed because the DCM doesn't support    **
**                 compiler abstraction.                                      **
**                 It converts the near pointer from DCM's function pointer   **
**                 prototype 'Dcm_UpdatePageType' to a far pointer.           **
**                 The function is called during paged processing handling of **
**                 ReadDataByIdentifer(CurrentSVK).                           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint8* dataPtr: Pointer to data buffer                     **
**                                                                            **
**                 uint16 dataLen - max. length of the writeable data         **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
#ifdef BAC
static FUNC(void, DCM_APPL_CODE) GetCurrentSvkNear
       (
	      P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) dataPtrNear,
		  VAR(uint16, DCM_APPL_DATA) dataLen
	   );
#else
static void GetCurrentSvkNear(uint8 * dataPtrNear, uint16 dataLen)
#endif /* Defined BAC */
{
   #ifdef BAC
   P2VAR(uint8, AUTOMATIC, COMMON_VAR) dataPtr = dataPtrNear;
   #else
   uint8* dataPtr = dataPtrNear;
   #endif /* Defined BAC */
   GetCurrentSvk(dataPtr, dataLen);
} /* end of function 'GetCurrentSvkNear'                                      */
#endif /* DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE                              */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmECUReset (Service request header:0x11 )             **
**                                                                            **
** DESCRIPTION   : Trigger a reset. This function implements the first step   **
**                 of the operation: the sending of the positive response.    **
**                 The second step, the trigger of the reset, will be done    **
**                 in function 'ApplDcmConfirmationECUReset', to guarantee    **
**                 that the positive response will be sent successfully.      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : pMsgContext:  pointer to diag context:                     **
**                               For more information see the DCM docs        **
**                                                                            **
** INPUT:        : pMsgContext->reqData[0]: reset Mode                        **
**                                                                            **
** RETURN        : positive response: when SubFunction is supported           **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) Rte_DcmECUReset
                          (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void Rte_DcmECUReset
     (
	    Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
#if defined(DCM_BAC_VERSION)
   #if (DCM_BAC_VERSION == DCM_BAC3X)
      Dcm_SesCtrlType   ActiveSession;
   #endif
#endif /* Defined DCM_BAC_VERSION */

   if (pMsgContext->reqDataLen == (uint16)1)
   {
      /* store sub parameter for post handler                                 */
      pendingDiagContext.SubFunction = pMsgContext->reqData[0];

      switch (pendingDiagContext.SubFunction)
      {
         case DIAG_UDS11_01_HARD_RESET:
            /*
             * force RESET. Positive response will send later in
             * ResetSequence()
             */
            /* prepare response                                               */
            pMsgContext->resDataLen = (uint16)1u;
#ifdef BOOTLOADER
            Dcm_ProcessingDone(pMsgContext);
#else
            /* in application special handling is needed                      */
            ecuresetHandling.pMsgContext = pMsgContext;
            ecuresetHandling.ForceEcuResetStatus = ECU_HARD_RESET_REQ;
            ApplInitiateShutdown(TRUE);
#endif /* BOOTLOADER                                                          */
            break;
         default:
            /* Request contains invalid data - send negative response!        */
#ifndef BOOTLOADER

#if defined(DCM_BAC_VERSION)
   #if (DCM_BAC_VERSION == DCM_BAC3X)
            Dcm_GetSesCtrlType(&ActiveSession);
            /* handle sub sessions in the ExtendedSession                     */
            if ( ( ActiveSession == DCM_SES_LEV_EXTENDED ) &&
   #endif
   #if (DCM_BAC_VERSION == DCM_BAC21)
            if ( ( Dcm_GetSesCtrlType() == DCM_SES_LEV_EXTENDED ) &&
   #endif
#else
            if ( ( Dcm_GetSesCtrlType() == DCM_SES_LEV_EXTENDED ) &&
#endif /* Defined DCM_BAC_VERSION */
                 ( activeSubSession != EXTENDED_APPL_FLASH_MODE_ACTIVATED )
               )
            {
               /*
                * an EcuReset with an undefined parameter in the
                * ExtendedSession in all sub sessions <> FLASH_MODE_ACTIVATED
                * cause a change to sub session FLASH_EXIT
                */
               activeSubSession = EXTENDED_APPL_FLASH_EXIT;
            }
#endif /* !BOOTLOADER                                                         */
            Dcm_SetNegResponse(pMsgContext, DCM_NRC_SUBFUNCTIONNOTSUPPORTED);
            Dcm_ProcessingDone(pMsgContext);
            break;
      }
   }
   else
   {
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );
      Dcm_ProcessingDone(pMsgContext);
   }

} /* end of function 'Rte_DcmECUReset'                                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmGetSeed                                             **
**                                                                            **
** DESCRIPTION   : Request for a security level based seed sequence           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SecurityLevel:                                           **
**                   - The security level needed this seed.                   **
**                   - Access type: read                                      **
**                 - SeedLen:                                                 **
**                   - The seed sequence length.                              **
**                   - Access type: read                                      **
**                 - Seed:                                                    **
**                   - Pointer to the seed sequence buffer.                   **
**                   - Access type: write                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) Rte_DcmGetSeed
(
   VAR(Dcm_SecLevelType, DCM_APPL_DATA) SecurityLevel,
   VAR(uint8, DCM_APPL_DATA) SeedLen,
   P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) Seed
)
#else
void Rte_DcmGetSeed
     (
   Dcm_SecLevelType SecurityLevel,
   uint8 SeedLen,
		Dcm_MsgContextType* Seed
)
#endif /* Defined BAC */
{
   #if ( (SC_CRYPTO_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON) )
      /*
       * use constant buffer for SC test. Almost the same seed for
       * security access in programming/coding session are send
       */
      static const uint8 ConstSeed[8] =
      {
         0xA2u,0x0Au,0x1Bu,0xFFu,0x93u,0xEBu,0x8Eu,0x1Bu
      };
   #endif

   /* Copy TesterId from incoming diagnostic buffer to 'SecurityAccessParams' */
   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&SecurityAccessParams.TesterId[0],
                        (const void SC_FAR_POINTER)&Seed[0],
                        DCM_SEC_SEED_RECORD_LENGTH
                      );

   if (SeedLen > (uint8)sizeof(SecurityAccessParams.PendingSeed))
   {
      /* exception handling can not be done with this AUTOSAR DCM version!    */
      SeedLen = (uint8)sizeof(SecurityAccessParams.PendingSeed);
   }

   #if (SC_CRYPTO_ENABLE == STD_ON)
      #if (STANDARD_CORE_TEST == STD_ON)

         /* Copy the random number to DCM buffers                             */
         (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&SecurityAccessParams.
                                                       PendingSeed[0],
                              (const void SC_FAR_POINTER)&ConstSeed[0],
                              SeedLen
                            );

         (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&Seed[0],
                              (const void SC_FAR_POINTER)&ConstSeed[0],
                              SeedLen
                            );
      #else

         /* Copy initial value for random number generator from               */
         /* 'BootProgData.RANDOM' to 'CR_C_S2.reg_a'                          */
         (void)SC_MEMCPY_ROM((void SC_FAR_POINTER)&CR_C_s2.reg_a[0],
                             (const void SC_FAR_POINTER)&BootProgData.RANDOM[0],
                             sizeof(BootProgData.RANDOM)
                            );
         /* XOR the initial value with another "random" value                 */
         CR_C_s2.reg_a[0] ^= CreateRandomNumber();
         CR_C_s2.reg_a[1] ^= CreateRandomNumber();
         CR_C_s2.reg_b[0] ^= CreateRandomNumber();
         CR_C_s2.reg_b[1] ^= CreateRandomNumber();

         /* Generate random number to buffer 'SecurityAccessParams.SeedOrKey' */
         Crypto_MakeChallKey ( (uint32)      SeedLen,
                               (CR_fp_uint8)&SecurityAccessParams.PendingSeed[0]
                             );

         /* Copy the random number to DCM buffer                              */
         (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&Seed[0],
                              (const void SC_FAR_POINTER)&SecurityAccessParams.
                                                             PendingSeed[0],
                              SeedLen
                            );

         /*
          * Save new initial value for the random number generator to
          * 'BootProgData.RANDOM'. It will be used for the generation of the
          * next random number.
          */
         (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&BootProgData.RANDOM[0],
                              (const void SC_FAR_POINTER)&CR_C_s2.reg_a[0],
                              sizeof(BootProgData.RANDOM)
                            );

         #ifdef BOOTLOADER
            /* write to nv memory                                             */
            (void)OperateNvData(NVM_DIAG_BOOTPROGDATA, NV_WRITE_OPERATION);
         #endif

      #endif /* STANDARD_CORE_TEST == STD_ON                                      */
   #endif /* SC_CRYPTO_ENABLE == STD_ON                                           */

} /* end of function 'Rte_DcmGetSeed'                                         */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmCompareKey                                          **
**                                                                            **
** DESCRIPTION   : Request for a security level based key sequence            **
**                 comparision                                                **
**                                                                            **
** PRECONDITIONS : successful SeedRequest                                     **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SecurityLevel:                                           **
**                   - The security level needed this seed.                   **
**                   - Access type: read                                      **
**                 - KeyLen:                                                  **
**                   - The key sequence length.                               **
**                   - Access type: read                                      **
**                 - Key:                                                     **
**                   - Pointer to the key sequence buffer.                    **
**                   - Access type: read                                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : DCM_E_OK:                 authentication successful        **
**                 DCM_E_COMPARE_KEY_FAILED: authentication failed            **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(Dcm_StatusType, DCM_APPL_CODE) Rte_DcmCompareKey
               (
                                       VAR(uint8, DCM_APPL_DATA) SecurityLevel,
                                       VAR(uint8, DCM_APPL_DATA) KeyLen,
                                       CONSTP2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Key
									)
#else
Dcm_StatusType Rte_DcmCompareKey
               (
                  uint8 SecurityLevel,
                  uint8 KeyLen,
                  const uint8* const Key
			   )
#endif /* Defined BAC */
{
   Dcm_StatusType retVal;

   #if (SC_CRYPTO_ENABLE == STD_ON)
      #if defined CRYPTO_AUTH_ASYM
         #if ((SG_KEY_LEN % 0x04u) != 0x00u)
            #error "diag.c: 'SG_KEY_LEN' must be a multiple of '4'"
         #endif
         /* encoded random value in longs                                     */
         static uint32 sgkey[SG_KEY_LEN / sizeof(uint32)];
      #endif

      CR_C_RC_t    res;                /* authentication check response       */

      if (KeyLen != SG_KEY_LEN)
      {
         /* report authentication failure to DCM                              */
         retVal = DCM_E_COMPARE_KEY_FAILED;
      }
      else
      {
         #ifdef CRYPTO_AUTH_SYM
            /* symmetric authentication                                       */
            res = Crypto_CheckAuthUStgSymm
            (
               /* seed for check.                                             */
               (CR_fp_uint8) &SecurityAccessParams.PendingSeed[0],
               /* tester Id                                                   */
               (CR_fp_uint8) &SecurityAccessParams.TesterId[0],
               /* BOOTLOGISTICIDENTIFIERDATA                                  */
               (CR_fpc_uint8)&SweBootTable.SgbmId[1],
               /* auth level                                                  */
               (uint32)       SC_AUTH_LEVEL,
               /* response                                                    */
               (CR_fpc_uint8)&Key[0]
            );

         #elif defined CRYPTO_AUTH_ASYM
            /*
             * Copy key length and encrypted challenge from incoming diagnostic
             * buffer to array 'sgkey'
             */
            #if (DIAG_ENDIANESS_FITS == CONFIG_TRUE)
               (void)SC_MEMCPY( (void SC_FAR_POINTER)sgkey,
                                (const void SC_FAR_POINTER)Key,
                                 SG_KEY_LEN);
            #else /* copy manually                                            */
               uint8_least iLoop;           /* temporary loop variable        */
               for ( iLoop = (uint8_least)0;
                     iLoop < (uint8_least)SG_KEY_LEN;
                     iLoop+= (uint8_least)4
                   )
               {
                  sgkey[iLoop >> (uint8_least)2] = Make32Bit
                                                  ( Key[iLoop + (uint8_least)0],
                                                    Key[iLoop + (uint8_least)1],
                                                    Key[iLoop + (uint8_least)2],
                                                    Key[iLoop + (uint8_least)3]
                                                  );
               }
            #endif

            /* asymmetric authentication                                      */
            res = Crypto_CheckAuthUStg
            (
               /* challenge                                                   */
               (CR_fp_uint8)  &SecurityAccessParams.PendingSeed[0],
               /* tester Id                                                   */
               (CR_fp_uint8)  &SecurityAccessParams.TesterId[0],
               /* BOOTLOGISTICIDENTIFIERDATA                                  */
               (CR_fpc_uint8) &SweBootTable.SgbmId[1],
               /* interrupt cycles                                            */
               (uint16)        0,
               /* auth level                                                  */
               (uint32)        SC_AUTH_LEVEL,
               /* response                                                    */
               (CR_fpc_uint32)&sgkey[0],
               /* state buffer                                                */
               (CR_fp_uint8)   NULL_PTR
            );

         #else
            #error "diag.c: No crypto method defined. " ##                     \
                   "Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'."
         #endif

         /* if authentication successful                                      */
         if (res == CR_C_RC_OK)
         {
            /* Authentication succeeded                                       */
            #ifdef BOOTLOADER
               /* store new programming status                                */
               activeSubSession = PROG_BOOT_UNLOCKED;
            #endif
            /* report successful authentication to DCM                        */
            retVal = DCM_E_OK;
         }
         else
         {
            /* report authentication failure to DCM                           */
            retVal = DCM_E_COMPARE_KEY_FAILED;
         }
      } /* if (KeyLen != SG_KEY_LEN)                                          */

   #else /* SC_CRYPTO_ENABLE == STD_ON                                            */
      #ifdef BOOTLOADER
         /* store new programming status                                      */
         activeSubSession = PROG_BOOT_UNLOCKED;
      #endif
      /* if crypto is disabled the authentication always passes               */
      retVal = DCM_E_OK;
   #endif /* SC_CRYPTO_ENABLE == STD_ON                                           */

   return retVal;
} /* end of function 'Rte_DcmCompareKey'                                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierActiveDiagSession               **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F186_ACTIVE_DIAG_SESSION                          **
**                 Read active session                                        **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_F186_RESPONSE_LENGTH   4u
#if (DIAG_DID_F186_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service ReadDataByIdentifier ActiveDiagnosticSession is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierActiveDiagSession
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierActiveDiagSession
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   SubSessionType    theActiveSubSession;
   /* Cache the pointer                                                       */
   Dcm_MsgType       resDataPtr = &pMsgContext->resData[2];

#if defined(DCM_BAC_VERSION)
   #if (DCM_BAC_VERSION == DCM_BAC3X)
   Dcm_SesCtrlType   ActiveSession;
   Dcm_GetSesCtrlType(&ActiveSession);

   /* activeDiagnosticSession MSB: get active session from DCM                */
   *resDataPtr++ = ActiveSession;
   #endif
   #if (DCM_BAC_VERSION == DCM_BAC21)
   *resDataPtr++ = Dcm_GetSesCtrlType();
   #endif
#else
   *resDataPtr++ = Dcm_GetSesCtrlType();
#endif /* Defined DCM_BAC_VERSION */

#ifndef BOOTLOADER
#if (SC_CODING_ENABLE == STD_ON)
#if defined(DCM_BAC_VERSION)
   #if (DCM_BAC_VERSION == DCM_BAC3X)
   if ( ActiveSession == DCM_SES_LEV_CODING )
   #endif
   #if (DCM_BAC_VERSION == DCM_BAC21)
   if ( Dcm_GetSesCtrlType() == DCM_SES_LEV_CODING )
   #endif
#else
   if ( Dcm_GetSesCtrlType() == DCM_SES_LEV_CODING )
#endif /* Defined DCM_BAC_VERSION */
   {
      theActiveSubSession = (SubSessionType)(Dcm_GetSecurityLevel() + 1);
   }
   else
#endif /* (SC_CODING_ENABLE == STD_ON) */
#endif /* BOOTLOADER */
   {
      theActiveSubSession = activeSubSession;
   }

   /*
    * activeDiagnosticSession LSB:
    * In Bootloader the higher nibble is used to save the substates in case of a
    * positive response with negativ content (e.g.
    * PROG_BOOT_MEMORY_ERASE_FAILED). This states are not reported to the
    * tester.
    */
#ifdef BOOTLOADER
   *resDataPtr = (uint8)((uint8)0x0Fu & (uint8)theActiveSubSession);
#else
   *resDataPtr = (uint8)theActiveSubSession;
#endif

   /* set length of response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F186_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierActiveDiagSession'           */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierTimingParameters                **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2504_FLASH_TIMING_PARAMS                          **
**                 Read program specific timing parameters                    **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_2504_RESPONSE_LENGTH   (2u + TIMINGPARAMETERLENGTH)
#if (DIAG_DID_2504_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service ReadDataByIdentifier FlashTimingParameter is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierTimingParameters
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
					      )
#else
void ApplDcmReadDataByIdentifierTimingParameters
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&pMsgContext->resData[2],
                        (const void SC_FAR_POINTER)&sharedBootROMData.TimingParameters[0],
                        sizeof(sharedBootROMData.TimingParameters)
                      );

   /* set response length                                                     */
   pMsgContext->resDataLen = (uint16)DIAG_DID_2504_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierTimingParameters'            */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierStandardCoreVersion             **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_1720_STANDARD_CORE_VERSION                        **
**                 Read the actual SC version from 'StandardCore_Cfg.h'       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_1720_RESPONSE_LENGTH   6u
#if (DIAG_DID_1720_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service ReadDataByIdentifier StandardCoreVersion is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierStandardCoreVersion
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
					      )
#else
void ApplDcmReadDataByIdentifierStandardCoreVersion
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   *resDataPtr++ = (uint8)STANDARDCORE_MAJOR_VERSION;
   *resDataPtr++ = (uint8)STANDARDCORE_MINOR_VERSION;
   *resDataPtr++ = (uint8)STANDARDCORE_PATCH_VERSION;
   *resDataPtr   = (uint8)0;                                      /* reserved */

   /* set response length                                                     */
   pMsgContext->resDataLen = (uint16)DIAG_DID_1720_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierStandardCoreVersion'         */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierProgrammingCounter              **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2502_PROG_COUNTER                                 **
**                 Read programming counter                                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : BootProgCounter.ProgrammingCounter                         **
**                 sharedBootROMData.ProgrammingCounterMaxValue               **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_2502_RESPONSE_LENGTH   6u
#if (DIAG_DID_2502_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service ReadDataByIdentifier ProgrammingCounter is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierProgrammingCounter
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierProgrammingCounter
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   uint8_least iLoop;                              /* temporary loop variable */
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   /*
    * search for the max. value of all ProgrammingCounters -> store to
    * 'programmingCounter'
    */
   uint16 highestSWEProgrammingCounter = (uint16)0;
   for ( iLoop = (uint8_least)0;
         iLoop < (uint8_least)SWENUMBEROFALLSWE;
         iLoop++
       )
   {
      if ( BootProgCounter.ProgrammingCounter[iLoop] >
                                                  highestSWEProgrammingCounter )
      {
         highestSWEProgrammingCounter =
                                      BootProgCounter.ProgrammingCounter[iLoop];
      }
   }

   *resDataPtr++ = (uint8)0x00;                              /* reserved byte */

   if ( highestSWEProgrammingCounter >=
                                  sharedBootROMData.ProgrammingCounterMaxValue )

   {
      /* the ECU can be reprogrammed never again                              */
      *resDataPtr++ = (uint8)NEVERMORE;
   }
   else if ( highestSWEProgrammingCounter ==
          (uint16)(sharedBootROMData.ProgrammingCounterMaxValue - (uint16)0x1) )
   {
      /* the ECU can be reprogrammed at least for one time                    */
      *resDataPtr++ = (uint8)ATLEASTONETIME;
   }
   else
   {
      /* the ECU can be reprogrammed for several times. It means              */
      *resDataPtr++ = (uint8)SEVERALTIMES;
   }

   /* send max. value of ProgrammingCounters                                  */
   *resDataPtr++ = Dcm_GetHiByte(highestSWEProgrammingCounter);
   *resDataPtr   = Dcm_GetLoByte(highestSWEProgrammingCounter);

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_2502_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierProgrammingCounter'          */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierProgrammingCounterMaxValue      **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2503_PROG_COUNTER_MAX_VALUE                       **
**                 Response with ProgrammingCounterMaxValue                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData.ProgrammingCounterMaxValue               **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_2503_RESPONSE_LENGTH   4u
#if (DIAG_DID_2503_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service ReadDataByIdentifier ProgrammingCounterMaxValue is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierProgrammingCounterMaxValue
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierProgrammingCounterMaxValue
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   *resDataPtr++ = Dcm_GetHiByte(sharedBootROMData.ProgrammingCounterMaxValue);
   *resDataPtr   = Dcm_GetLoByte(sharedBootROMData.ProgrammingCounterMaxValue);

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_2503_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierProgrammingCounterMaxValue'  */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierMemorySegmentationTable         **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE                    **
**                 Read memory segmentation table                             **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_2501_RESPONSE_LENGTH  ( 5u + (FLASH_SEGMENT_NUMBER_ALL * 10u) )
#if ( (DCM_PAGEDBUFFER_ENABLED == CONFIG_FALSE)       &&                       \
      (DIAG_DID_2501_RESPONSE_LENGTH >= DCM_BUFFER_SIZE))
   /*
    * This must not be an error, because a run length encoding of the response
    * is used
    */
   #warning "diag.c: The worst-case response length for service ReadDataByIdentifier MemorySegmentationTable is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierMemorySegmentationTable
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierMemorySegmentationTable
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   /*
    * The response will be run length encoded:
    * calculate response length at runtime
    */
   pMsgContext->resDataLen =
                    ( (uint16)10 *
                      (uint16)GetNumberOfElementsInReadMemorySegmentationTable()
                    ) + (uint16)5u;

   /* check the response data length, whether they fit into the dcm buffer    */
   if ( pMsgContext->resDataLen <= pMsgContext->resMaxDataLen )
   {
      /* all response data fit into the dcm buffer --> process it             */
      ApplDcmProcessReadMemorySegmentationTable(&pMsgContext->resData[0],
                                             (uint16)RESPONSE_FIT_INTO_BUFFER );

      #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
      Dcm_ProcessingDone(pMsgContext);
      #endif
   }
   else
   {
      #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
         /* paged buffer processing is enabled                                */
         static const Dcm_PagedBufferCallbackType pPBCallbackFunc =
                                  { ApplDcmProcessReadMemorySegmentationTable,
                                    ApplDcmCancelPagedBufferProcessing,
                                    ApplDcmPagedBufferProcessingConfirmation
                                  };

        /* start paged buffer processing                                      */
        #ifdef BAC
            Dcm_StartPagedProcessing(pMsgContext);
        #else
            Dcm_StartPagedProcessing(pMsgContext, &pPBCallbackFunc);
        #endif /* Defined BAC */

      #else
         /* paged buffer processing is disabled -> data can't be transmitted  */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_RESPONSETOOLONG);
      #endif
   }
} /* end of function 'ApplDcmReadDataByIdentifierMemorySegmentationTable'     */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierSvkCurrent                      **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F101_SVK_AKTUELL                                  **
**                 Read present/current SVK                                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvkCurrent
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierSvkCurrent
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   uint16 SvkSize = (uint16)SVK_BACKUP_SIZE;

#ifndef BOOTLOADER
#if (SC_CODING_ENABLE == STD_ON)
         SvkSize += ( (uint16)Coding_DcmGetNumberOfCodedAreas() * (uint16)8 );
#endif
#endif

   /* check the response data length, whether they fit into the dcm buffer    */
   if ( (SvkSize + 2) <= pMsgContext->resMaxDataLen )
   {
      GetCurrentSvk(&pMsgContext->resData[0],
                    (uint16)RESPONSE_FIT_INTO_BUFFER);

      /* send positive response                                               */
      pMsgContext->resDataLen = (uint16)((uint16)2 + SvkSize);

      #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
      Dcm_ProcessingDone(pMsgContext);
      #endif
   }
   else
   {
      /* response data don't fit into the dcm buffer                          */
      #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
         /* paged buffer processing is enabled                                */
         static const Dcm_PagedBufferCallbackType pPBCallbackFunc =
                                    { GetCurrentSvkNear,
                                      ApplDcmCancelPagedBufferProcessing,
                                      ApplDcmPagedBufferProcessingConfirmation
                                    };

         /* set the length of the positive response                           */
         pMsgContext->resDataLen = (uint16)((uint16)2 + SvkSize);

         /* start paged buffer processing                                     */
        #ifdef BAC
            Dcm_StartPagedProcessing(pMsgContext);
        #else
            Dcm_StartPagedProcessing(pMsgContext, &pPBCallbackFunc);
        #endif /* Defined BAC */
      #else
         /* paged buffer processing is disabled -> data can't transmitted     */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_RESPONSETOOLONG);
      #endif
   }
} /* end of function 'ApplDcmReadDataByIdentifierSvkCurrent'                  */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierSvkSystemSupplier               **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F102_SVK_SYSTEM_SUPPLIER                          **
**                 Read the system supplier SVK.                              **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvkSystemSupplier
                          (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierSvkSystemSupplier
     (
	    Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   ApplDcmReadDataByIdentifierSvk (
                                     pMsgContext,
                                     SVKHISTORY_SYSTEMSUPPLIER,
                                     (uint8)0x00u     /* dummy value */
                                  );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierSvkPlant                        **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F103_SVK_PLANT                                    **
**                 Read the plant SVK.                                        **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvkPlant
                          (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierSvkPlant
     (
	    Dcm_MsgContextType* const pMsgContext
	 )
#endif /* Defined BAC */
{
   ApplDcmReadDataByIdentifierSvk (
                                     pMsgContext,
                                     SVKHISTORY_PLANT,
                                     (uint8)0x00u     /* dummy value */
                                  );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierSvkBackup                       **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F104_SVK_BACKUP_MIN - DIAG_DID_F140_SVK_BACKUP_MAX**
**                 Read the backup SVK.                                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : pMsgContext : pointer to Dcm_MsgContextType                **
                   dataId      : data ID                                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvkBackup
            (
               CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
							 VAR(uint16, DCM_APPL_DATA) dataId
						  )
#else
void ApplDcmReadDataByIdentifierSvkBackup
     (
               Dcm_MsgContextType* const pMsgContext,
               uint16 dataId
            )
#endif /* Defined BAC */
{
   ApplDcmReadDataByIdentifierSvk
      (
         pMsgContext,
         SVKHISTORY_BACKUP,
         (uint8)( dataId - (uint16)DIAG_DID_F104_SVK_BACKUP_MIN )
      );
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierEcuManufacturingData            **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F18B_ECU_MANUFACTURING_DATA                       **
**                 Read the ECU Manufacturing Data                            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_F18B_RESPONSE_LENGTH   (2u + ECUMANUFACTURINGDATALENGTH)
#if (DIAG_DID_F18B_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service ReadDataByIdentifier EcuManufacturingData is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierEcuManufacturingData
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierEcuManufacturingData
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
#if (ECUMANUFACTURINGDATALENGTH != 3u)
   #error "diag.c: ECUMANUFACTURINGDATALENGTH must be 3"
#endif

   /* copy ECUManufacturingData to response                                   */
   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&pMsgContext->resData[2],
                        (const void SC_FAR_POINTER)&HwDescData.
                                                       ECUManufacturingData[0],
                        sizeof(HwDescData.ECUManufacturingData)
                      );

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F18B_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierEcuManufacturingData'        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierSerialNumber                    **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F18C_ECU_SERIAL_NUMBER                            **
**                 Read the ECU SerialNumber                                  **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_F18C_RESPONSE_LENGTH   (2u + ECUSERIALNUMBERLENGTH)
#if (DIAG_DID_F18C_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service ReadDataByIdentifier EcuSerialNumber is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierEcuSerialNumber
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierEcuSerialNumber
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
#if (ECUSERIALNUMBERLENGTH != 10u)
   #error "diag.c: ECUSERIALNUMBERLENGTH must be 10"
#endif

   /* copy EcuSerialNumber to response                                        */
   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&pMsgContext->resData[2],
                        (const void SC_FAR_POINTER)&HwDescData.
                                                       ECUSerialNumber[0],
                        sizeof(HwDescData.ECUSerialNumber)
                      );

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F18C_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierEcuSerialNumber'             */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierVin                             **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F190_VIN                                          **
**                 Read VIN                                                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_DID_F190_RESPONSE_LENGTH   (2u + VINLENGTH)
#if (DIAG_DID_F190_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service ReadDataByIdentifier VIN is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierVin
                          (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmReadDataByIdentifierVin
     (
	    Dcm_MsgContextType* const pMsgContext
	 )
#endif /* Defined BAC */
{
   /* copy VIN to response                                                    */
   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&pMsgContext->resData[2],
                        (const void SC_FAR_POINTER)&BootProgData.VIN[0],
                        sizeof(BootProgData.VIN)
                      );

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_F190_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierVin'                         */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlReadDevelopmentInfo                   **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_0205_READ_DEVELOPMENT_INFO                        **
**                 Reads the SWE development info for the sgbm-id             **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#define DIAG_RID_0205_RESPONSE_LENGTH (1u + 2u + 1u + MAX_XWE_DEV_INFO_LENGTH)
#if (DIAG_RID_0205_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "diag.c: The response length for service RoutineControl ReadDevelopmentInfo is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlReadDevelopmentInfo
     (
        CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void ApplDcmRoutineControlReadDevelopmentInfo
     (
        Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   boolean     foundDevelopmentInfo = FALSE;       /*
                                                    * TRUE when an according SWE
                                                    * is found
                                                    */
   /* Cache the request pointer                                               */
   Dcm_MsgType reqDataPtr;

   uint8_least iLoop  = (uint8_least)0;            /* temporary loop variable */

   if (pMsgContext->reqDataLen == ((uint16)3 + (uint16)SGBM_ID_LENGTH))
   {
      reqDataPtr = &pMsgContext->reqData[3];

      switch(reqDataPtr[0])                        /* check process class     */
      {
         case PROCESSCLASS_HWEL:
         case PROCESSCLASS_HWAP:
         case PROCESSCLASS_HWFR:
            /* search in HWEDevelopmentInfo list                              */
#if ((HWEDEVELOPMENTINFOLENGTH > 0u) && (NUMBEROFHWESGBMIDS > 0u))
            do
            {
               /* cache pointers to HWE-Table and SgbmId                      */
               const HweTableType SC_FAR_POINTER const tmpHweTable =
                                                    &HwDescData.HweTable[iLoop];
               const uint8        SC_FAR_POINTER const tmpSgbmId =
                                                    &tmpHweTable->HWESgbmId[0];

               /* check SweClassification                                     */
               if ( SC_MEMCMP_ROM( (const void SC_FAR_POINTER)&tmpSgbmId[0],
                                   (const void SC_FAR_POINTER)reqDataPtr,
                                   SGBM_ID_LENGTH
                                 ) == 0x00
                  )
               {
                  /* an according SWE was found                               */
                  const uint8 SC_FAR_POINTER const tmpXweDevInfo =
                                            &tmpHweTable->HWEDevelopmentInfo[0];
                  (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&pMsgContext->resData[3],
                                       (const void SC_FAR_POINTER)&tmpXweDevInfo[0],
                                       (uint16)(tmpXweDevInfo[0] + 1u)
                                     );

                  pMsgContext->resDataLen = (uint16)( 3u + tmpXweDevInfo[0] + 1u );
                  foundDevelopmentInfo = TRUE;
               }

               ++iLoop;
            } while ( (foundDevelopmentInfo == FALSE) &&
                      (iLoop < (uint8_least)NUMBEROFHWESGBMIDS)
                    );
#endif
            break;
         case PROCESSCLASS_CAFD:
         case PROCESSCLASS_BTLD:
         case PROCESSCLASS_FLSL:
         case PROCESSCLASS_SWFL:
         case PROCESSCLASS_SWFF:
         case PROCESSCLASS_SWPF:
         case PROCESSCLASS_ONPS:
         case PROCESSCLASS_IBAD:
         case PROCESSCLASS_FAFP:
         case PROCESSCLASS_FCFA:
         /* case PROCESSCLASS_TLRT: deactivated because of FP_5029            */
         /* case PROCESSCLASS_TPRG: deactivated because of FP_5029            */
         case PROCESSCLASS_ENTD:
         case PROCESSCLASS_NAVD:
         case PROCESSCLASS_FCFN:
            /* search in SWEDevelopmentInfo list                              */
            do
            {
#ifdef BOOTLOADER
               /* If in bootloader check if SWE is valid. In application SWEs */
               /* are always valid, otherwise it would not have been started  */
               const SweValidStateType validStateOfSwe = Swe_GetValidStateOfSwe( (uint8)iLoop );

               if ( ( validStateOfSwe == SWE_VALID_STATE_VALID_SWFL ) ||
                    ( validStateOfSwe == SWE_VALID_STATE_VALID_BTLD  ) )
               {
#endif
                  /* cache pointers to SWE-Table and SgbmId                   */
                  const SweTableType SC_FAR_POINTER const tmpSweTable =
                                        sharedBootROMData.PointerToSweTable[iLoop];
                  const uint8        SC_FAR_POINTER const tmpSgbmId =
                                        &tmpSweTable->SgbmId[0];

                  /* check SweClassification                                  */
                  if ( SC_MEMCMP_ROM( (const void SC_FAR_POINTER)&tmpSgbmId[0],
                                      (const void SC_FAR_POINTER)reqDataPtr,
                                      SGBM_ID_LENGTH
                                    ) == 0x00
                     )
                  {
                     /* an according SWE was found                            */
                     const uint8 SC_FAR_POINTER const tmpXweDevInfo =
                                                    &tmpSweTable->SweDevInfo[0];
                     (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&pMsgContext->resData[3],
                                          (const void SC_FAR_POINTER)&tmpXweDevInfo[0],
                                          (uint16)(tmpXweDevInfo[0] + 1u)
                                        );

                     pMsgContext->resDataLen = (uint16)( (uint16)3 +
                                                         (uint16)tmpXweDevInfo[0] +
                                                         (uint16)0x01
                                                       );
                     foundDevelopmentInfo = TRUE;
                  }
#ifdef BOOTLOADER
               }
#endif
               ++iLoop;

            } while ( (foundDevelopmentInfo == FALSE) &&
                      (iLoop < (uint8_least)SWENUMBEROFALLSWE)
                    );
            break;
         default:
             /* invalid process class                                         */
             Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
             /* return is used here to decrease nesting depth                 */
             return;
             /* no break;                                                     */
      }

      if (foundDevelopmentInfo == FALSE)
      {
         /*
          * No according SWE found or no DevelopmentInfo is available:
          * Response with 0x00
          */
         pMsgContext->resData[3] = (uint8)0x00;
         pMsgContext->resDataLen = (uint16)4;
      }
   }
   else
   {
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );
   }
} /* end of function 'ApplDcmRoutineControlReadDevelopmentInfo'               */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : GetCurrentSvk                                              **
**                                                                            **
** DESCRIPTION   : collect information about current SVK to data buffer       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : uint8* dataPtr: Pointer to data buffer                     **
**                                                                            **
**                 uint16 dataLen - max. length of the writeable data         **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) GetCurrentSvk
     (
                             P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) dataPtr,
                             VAR(uint16, DCM_APPL_DATA) dataLen
                          )
#else
void GetCurrentSvk
     (
	    uint8 dataPtr,
        uint16 dataLen
     )
#endif /* Defined BAC */
{
   uint8_least iLoop;                              /* temporary loop variable */
   uint16      numberOfSvks;                                /* number of svks */
   uint16      numberOfCodingCafIds = (uint16)0;  /* number of coding caf ids */
   uint16      writtenData;                   /* counter for the written data */
   boolean     bLeaveEarly          = FALSE;

   /* ############################   STEP 0   ################################*/
   /* only at first call of this function during a request do ...             */
   if ( iStep == (uint8_least)0 )
   {
      #ifdef BOOTLOADER
         /* get programming dependency state of all application SWEs */
         SweProgDepStateType progDepStateOfApplSwes = Swe_GetProgDepStateOfApplSwes();

         /* set correct state for response */
         if ( progDepStateOfApplSwes == SWE_PROGDEP_STATE_UNCHECKED_APPL )
         {
            progDepStateOfApplSwes = SWE_PROGDEP_STATE_INVALID;
         }
         else if ( progDepStateOfApplSwes == SWE_PROGDEP_STATE_VALID_BLU)
         {
            progDepStateOfApplSwes = SWE_PROGDEP_STATE_CONSISTENT_APPL;
         }
      #else
         #if (SC_CODING_ENABLE == STD_ON)
               numberOfCodingCafIds += Coding_DcmGetNumberOfCodedAreas();
         #endif
      #endif

      if ( dataLen != (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM )
      {
         *dataPtr++ = (uint8)0xF1;
         *dataPtr++ = (uint8)0x01;
      }

      /* SVK Version                                                          */
      *dataPtr++ = sharedBootROMData.SvkVersion;

      /*
       * set ProgrammingDependencies status:
       * In the Application, the status is always OK, otherwise the BootManager
       * would have started the Bootloader not the Application
       */
      #ifdef BOOTLOADER
         *dataPtr++ = (uint8)progDepStateOfApplSwes;
      #else
         *dataPtr++ = (uint8)SWE_PROGDEP_STATE_CONSISTENT_APPL;
      #endif

      /*
       * Number of SVK entries in dataPtr[2] and dataPtr[3]:
       * Count number of HWE SVKs, number of SWE SVKs and number of coding caf
       * ids
       */
      numberOfSvks = (uint16)NUMBEROFHWESGBMIDS +
                     (uint16)SWENUMBEROFALLSWE  +
                     numberOfCodingCafIds;
      /* set number of SVK entries                                            */
      *dataPtr++ = Dcm_GetHiByte(numberOfSvks);                        /* MSB */
      *dataPtr++ = Dcm_GetLoByte(numberOfSvks);                        /* LSB */

      writtenData =      (uint16)6;
      iStep       = (uint8_least)1;
   }
   else
   {
      writtenData = (uint16)0;
   }

   /* ############################   STEP 1   ################################*/
   if ( ( iStep == (uint8_least)1 ) &&
        ( ( dataLen == (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) ||
          ( (sizeof(BootProgData.FingerPrint) + writtenData) <= dataLen )
        )
      )
   {
      /* copy current FingerPrint                                             */
      (void)SC_MEMCPY_ROM ( (void SC_FAR_POINTER)dataPtr,
                            (const void SC_FAR_POINTER)&BootProgData.
                                                           FingerPrint[0],
                            sizeof(BootProgData.FingerPrint)
                          );

         /* increase data pointer with FingerPrint size                       */
      dataPtr += sizeof(BootProgData.FingerPrint);

      writtenData += sizeof(BootProgData.FingerPrint);
      iStep        = (uint8_least)2;
   }

   /* ############################   STEP 2   ################################*/
   if ( ( iStep == (uint8_least)2 ) &&
        ( ( dataLen == (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) ||
          ( (SGBM_ID_LENGTH + writtenData) <= dataLen )
        )
      )
   {
      iLoop = iLoopStart;
      /* write bootloader and application segmentation table to response      */
      while ( (iLoop < (uint8_least)NUMBEROFHWESGBMIDS) &&
              (bLeaveEarly == FALSE)
            )
      {
         (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)dataPtr,
                              (const void SC_FAR_POINTER)&HwDescData.
                                                   HweTable[iLoop].HWESgbmId[0],
                              SGBM_ID_LENGTH
                            );

         /* increase data pointer                                             */
         dataPtr += SGBM_ID_LENGTH;

         writtenData += SGBM_ID_LENGTH;
         iLoop++;

         /* fit the next data into the buffer or are all data written ?       */
         if ( ( dataLen != (uint16)RESPONSE_FIT_INTO_BUFFER ) &&
              ( dataLen != (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) &&
              ( (writtenData + SGBM_ID_LENGTH) > dataLen ) )
         {
            bLeaveEarly = TRUE;
         }
      }

      if ( iLoop == (uint8_least)NUMBEROFHWESGBMIDS )
      {
         /* reset iLoopStart for the next step                                */
         iLoopStart = (uint8_least)0;
         iStep      = (uint8_least)3;
      }
      else
      {
         /* save the actual iLoop value to continue on next function call     */
         iLoopStart = iLoop;
      }
   }

   /* ############################   STEP 3   ################################*/
   if ( ( iStep == (uint8_least)3 ) &&
        ( ( dataLen == (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) ||
          ( (SGBM_ID_LENGTH + writtenData) <= dataLen )
        )
      )
   {
      iLoop = iLoopStart;
      /* copy all Sgbm Ids of bootloader and application SWE Tables           */
      while ( ( iLoop < (uint8_least)SWENUMBEROFALLSWE ) &&
              ( bLeaveEarly == FALSE)
            )
      {
#ifdef BOOTLOADER
         /* If in bootloader check if SWE is valid. In application SWEs       */
         /* are always valid, otherwise it would not have been started        */
         const SweValidStateType validStateOfSwe = Swe_GetValidStateOfSwe( (uint8)iLoop );

         if ( ( validStateOfSwe == SWE_VALID_STATE_VALID_SWFL ) ||
              ( validStateOfSwe == SWE_VALID_STATE_VALID_BTLD  ) )
         {
#endif
            /* copy each Sgbm Ids of application                              */
            (void)SC_MEMCPY_ROM
               ( (void SC_FAR_POINTER)dataPtr,
                 (const void SC_FAR_POINTER)&sharedBootROMData.
                                            PointerToSweTable[iLoop]->SgbmId[0],
                 SGBM_ID_LENGTH
               );
/*
 * In the Application, the SWEProgrammingStatus is always OK, otherwise
 * the BootManager would have started the Bootloader not the
 * Application
 */
#ifdef BOOTLOADER
         }
         else
         {
            /*
             * set default value for SGBM ids of application and bootloader
             * that are not signature checked
             */
            (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)dataPtr,
                                 (uint8)DIAG_SGBM_ID_DEFAULT_VALUE,
                                 SGBM_ID_LENGTH
                               );
         }
#endif /* #ifdef BOOTLOADER                                                   */

         /* increase data pointer                                             */
         dataPtr += SGBM_ID_LENGTH;

         writtenData += SGBM_ID_LENGTH;

         /* fit the next data into the buffer or are all data written ?       */
         if ( ( dataLen != (uint16)RESPONSE_FIT_INTO_BUFFER ) &&
              ( dataLen != (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) &&
              ( (writtenData + SGBM_ID_LENGTH) > dataLen ) )
         {
            bLeaveEarly = TRUE;
         }
         iLoop++;
      }

      if ( iLoop == (uint8_least)SWENUMBEROFALLSWE )
      {
         /* reset iLoopStart for the next execution of this diagnostic service*/
         iLoopStart = (uint8_least)0;
         iStep      = (uint8_least)4;
      }
      else
      {
         /* save the actual iLoop value to continue on next function call     */
         iLoopStart = iLoop;
      }
   }

   /* ############################   STEP 4   ################################*/
   #ifndef BOOTLOADER
      #if (SC_CODING_ENABLE == STD_ON)
      if ( ( iStep == (uint8_least)4 ) &&
           ( (dataLen == (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM) ||
             ( ( (Coding_DcmGetNumberOfCodedAreas() * (uint16)0x08u)
                 + writtenData ) <= dataLen
             )
           )
         )
      {
         writtenData += Coding_DcmGetCafIdsOfCodedAreas(dataPtr);
         iStep = (uint8_least)0;
      }
   #else
      if ( iStep == (uint8_least)4 )
      {
         iStep = (uint8_least)0;
      }
      #endif
#else
   if ( iStep == (uint8_least)4 )
   {
      iStep = (uint8_least)0;
   }
   #endif

#if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
   /* only if call from diagnosis and if paged buffer processing used, do ... */
   if ( ( dataLen != (uint16)GET_SVK_CURRENT_FOR_HISTORY_MEM ) &&
        ( dataLen != (uint16)RESPONSE_FIT_INTO_BUFFER )
      )
   {
      /* send page to DCM                                                     */
      Dcm_ProcessPage(writtenData);
   }
#endif /* (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)                            */
} /* end of function 'GetCurrentSvk'                                          */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmProcessReadMemorySegmentationTable                  **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE                    **
**                 Read memory segmentation table                             **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : iLoopStart                                                 **
**                                                                            **
** PARAMETER     : dataBufPtr - Pointer for memory segmentation table data    **
**                                                                            **
**                 dataLen - max. length of the writeable data                **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmProcessReadMemorySegmentationTable
               (
        P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) dataBufPtr,
							 VAR(uint16, DCM_APPL_DATA) dataLen
						  )
#else
void ApplDcmProcessReadMemorySegmentationTable
     (
        uint8* dataBufPtr,
        uint16 dataLen
     )
#endif /* Defined BAC */
{
   uint8_least          iLoop;               /* temporary loop variable       */
   uint16               writtenData;         /* counter for the written data  */
   uint16               sameSizedFlashSegments;
                                             /* holds temporary addresses     */
   flashAddress_t       oldEndAddress        = (flashAddress_t)0;
   flashAddress_t       oldSize              = (flashAddress_t)0;
   flashAddress_t       currentSize;
   boolean              bLeaveEarly          = FALSE;
   P2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                        pCurrentStartAddress;
   P2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                        pCurrentEndAddress;

   /* only at first call of this function during a request do ...             */
   if ( iLoopStart == (uint8_least)0 )
   {
      const uint8_least tmpNumberOfSWEs =
         GetNumberOfElementsInReadMemorySegmentationTable();

      *dataBufPtr++ = (uint8)0x25u;
      *dataBufPtr++ = (uint8)0x01u;

      /* set addressAndLengthFormatIdentifier: equivalent uint32 (4 Bytes)    */
      *dataBufPtr++ = (uint8)DIAG_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER;

      /* number of SWEs (boot and appl) MSB/LSB                               */
      *dataBufPtr++ = (uint8)0x00u;
      *dataBufPtr++ = (uint8)tmpNumberOfSWEs;

      writtenData = (uint16)5u;
   }
   else
   {
      writtenData = (uint16)0u;
   }

   iLoop = iLoopStart;

   pCurrentStartAddress   = &sharedBootROMData.MemSegTable[iLoop][0];
   pCurrentEndAddress     = &sharedBootROMData.MemSegTable[iLoop][1];
   currentSize            = *pCurrentEndAddress   -
                            *pCurrentStartAddress +
                            (flashAddress_t)0x01u;
   sameSizedFlashSegments = (uint16)0x00u;

   /* write bootloader and application segmentation table to response         */
   while ( (iLoop < (uint8_least)FLASH_SEGMENT_NUMBER_ALL) && (bLeaveEarly != TRUE))
   {
      if ( (*pCurrentStartAddress == (oldEndAddress + (flashAddress_t)1)) &&
           (currentSize           == oldSize)
         )
      {
         ++sameSizedFlashSegments;

         /*
          * Go back to bytes in the response to increase the number of same
          * sized flash segments
          */
         dataBufPtr -= 2;
      }
      else
      {
         *dataBufPtr++ = Dcm_GetHiHiByte(*pCurrentStartAddress);
         *dataBufPtr++ = Dcm_GetHiLoByte(*pCurrentStartAddress);
         *dataBufPtr++ = Dcm_GetLoHiByte(*pCurrentStartAddress);
         *dataBufPtr++ = Dcm_GetLoLoByte(*pCurrentStartAddress);

         *dataBufPtr++ = Dcm_GetHiHiByte(currentSize);
         *dataBufPtr++ = Dcm_GetHiLoByte(currentSize);
         *dataBufPtr++ = Dcm_GetLoHiByte(currentSize);
         *dataBufPtr++ = Dcm_GetLoLoByte(currentSize);

         sameSizedFlashSegments = (uint16)0x01;
         writtenData += (uint16)10;
      }

      oldEndAddress = *pCurrentEndAddress;
      oldSize       = currentSize;

      /* number of consecutive same sized flash segments                      */
      *dataBufPtr++ = GetHiByte(sameSizedFlashSegments);               /* MSB */
      *dataBufPtr++ = GetLoByte(sameSizedFlashSegments);               /* LSB */

      iLoop++;

      if (iLoop < (uint8_least)FLASH_SEGMENT_NUMBER_ALL)
      {
         pCurrentStartAddress = &sharedBootROMData.MemSegTable[iLoop][0];
         pCurrentEndAddress   = &sharedBootROMData.MemSegTable[iLoop][1];
         currentSize          = *pCurrentEndAddress   -
                                *pCurrentStartAddress +
                                (flashAddress_t)0x01;
      }

#if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
      /* fit the next data into the buffer or are all data written ?          */
      if ( ( dataLen != (uint16)RESPONSE_FIT_INTO_BUFFER ) &&
                                                  /* paged processing is used */
           (
             (
               ((writtenData + (uint16)10) > dataLen) &&
               (
                  (*pCurrentStartAddress != (oldEndAddress + (flashAddress_t)1))
                  ||
                  (currentSize           != oldSize)
               )
             ) ||
             (iLoop == (uint8_least)FLASH_SEGMENT_NUMBER_ALL)
           )
         )
      {
         /* this code is only reached if paged buffer processing is used      */
         /* page buffer is full -> send page to DCM                           */
         Dcm_ProcessPage(writtenData);

         bLeaveEarly = TRUE;
      }
#endif /* (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE) */
   }

   if ( iLoop == (uint8_least)FLASH_SEGMENT_NUMBER_ALL )
   {
      /* reset iLoopStart for the next execution of this diagnostic service   */
      iLoopStart = (uint8_least)0;
   }
   else
   {
      /* save the actual iLoop value to continue on next function call        */
      iLoopStart = iLoop;
   }
} /* end of function 'ApplDcmProcessReadMemorySegmentationTable'              */


#if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmProcessReadSVK                                      **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22) -                              **
**                 DIAG_DID_F102_SVK_SYSTEM_SUPPLIER / DIAG_DID_F103_SVK_PLANT**
**                 Read the system supplier or plant SVK                      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : dataBufPtr - Pointer for memory segmentation table data    **
**                                                                            **
**                 dataLen - max. length of the writeable data                **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmProcessReadSVK
                          (
						     P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) dataBufPtr,
							 VAR(uint16, DCM_APPL_DATA) dataLen
						  )
#else
void ApplDcmProcessReadSVK
     (
	    uint8* dataBufPtr, 
		uint16 dataLen
	 )
#endif /* Defined BAC */
{
   /* only at first call of this function do ...                              */
   if ( iLoopStart == (uint8_least)0 )
   {
      /*
       * at first call the first 2 bytes of the buffer are the service data-id
       */
      dataBufPtr += 2;
      dataLen -= 2;
   }

   /* copy only the valid data in the buffer - correct dataLen                */
   if ( gSVKLength < dataLen )
   {
      dataLen = gSVKLength;
   }
  (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)dataBufPtr,
                       (const void SC_FAR_POINTER)gpSvk,
                       dataLen
                     );

   /* only at first call of this function do ...                              */
   if ( iLoopStart == (uint8_least)0 )
   {
      /* page buffer is full -> send page to DCM                              */
      Dcm_ProcessPage(dataLen + 2);
   }
   else
   {
      /* page buffer is full -> send page to DCM                              */
      Dcm_ProcessPage(dataLen);
   }

   /* increase data pointer for the next function call                        */
   gpSvk += dataLen;
   gSVKLength -= dataLen;

   /* are all data written?                                                   */
   if (gSVKLength == 0)
   {
      /*
       * reset loop counter, to reserve the first 2 bytes at next function call
       */
      iLoopStart = (uint8_least)0;
   }
   else
   {
      /* increase call counter                                                */
      iLoopStart++;
   }
} /* end of function 'ApplDcmProcessReadSVK'                                  */
#endif /* (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)                            */


#if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmCancelPagedBufferProcessing                         **
**                                                                            **
** DESCRIPTION   : Error function for the paged buffer processing             **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmCancelPagedBufferProcessing( void )
#else
void ApplDcmCancelPagedBufferProcessing(void)
#endif
{
   /*
    * reset static loop and step variables for the next execution of a
    * diagnostic service with paged processing
    */
   iLoopStart = (uint8_least)0;
   iStep      = (uint8_least)0;
} /* end of function 'ApplDcmCancelPagedBufferProcessing'                     */
#endif /* (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)                            */


#if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmPagedBufferProcessingConfirmation                   **
**                                                                            **
** DESCRIPTION   : Confirmation function for the paged buffer processing      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - idContext:                                               **
**                   - An identfier of the dcm instance.                      **
**                   - Access type: read                                      **
**                 - dcmRxPduId:                                              **
**                   - The PduId on which the request has been received.      **
**                   - Access type: read                                      **
**                 - status:                                                  **
**                   - Shows the status of the process accomplishment.        **
**                   - Can be:                                                **
**                     + DCM_RES_POS_OK                                       **
**                     + DCM_RES_POS_NOT_OK                                   **
**                     + DCM_RES_NEG_OK                                       **
**                     + DCM_RES_NEG_NOT_OK                                   **
**                   - Access type: read                                      **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) ApplDcmPagedBufferProcessingConfirmation
                          (
						     VAR(uint8, DCM_APPL_DATA) idContext,
							 VAR(uint8, DCM_APPL_DATA) dcmRxPduId,
							 VAR(Dcm_ConfirmationStatusType, DCM_APPL_DATA) status
						  )
#else
void ApplDcmPagedBufferProcessingConfirmation
     (
	    uint8 idContext, 
		uint8 dcmRxPduId, 
		Dcm_ConfirmationStatusType status
     )
#endif /* Defined BAC */
{
   /* nothing to do                                                           */
} /* end of function 'ApplDcmPagedBufferProcessingConfirmation'               */
#endif /* (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)                            */

#define DIAG_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BOOTMANAGER                                                         */

/*** End of file **************************************************************/
