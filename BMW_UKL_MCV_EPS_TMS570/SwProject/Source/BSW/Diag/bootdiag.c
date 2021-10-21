/*******************************************************************************
**                                                                            **
**  SRC-MODULE: bootdiag.c                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2010                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Support of DCM diagnostic services corresponding              **
**              to specification for AUTOSAR                                  **
**                                                                            **
**  REMARKS   : Implementation of bootloader specific diagnostic              **
**              services                                                      **
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
** mm           Miroslaw Missalla          EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** chwi         Christian Wilmes           EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
** jetc         Jean-Jacques Tchouto       EB Automotive                      **
** ke           Kai Esbold                 EB Automotive                      **
** cma          Chr. Mueller-Albrecht      BMW                                **
** dare         Daniel Reiss               EB Automotive                      **
** chfr         Christian Franke           EB Automotive                      **
** masc         Marko Schneider            EB Automotive                      **
** anht         Andreas Hartmann           EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
** ft			Florian Tausch			   MB Technology					  **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 *V13.3.0: 02.11.2010, ft  : CR70873: fixed check of FLASH_DRIVER_INVALID_ACTIVATION_CODE
 *V13.2.0: 27.09.2010, ft  : CR70845: integrated new version of operation
 *                           FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat
 *V13.1.0: 06.09.2010, ft  : CR70684/CR70735: Added missing or imcomplete
											  compiler abstraction
 *V13.0.5: 01.04.2010, anht: CR61808/CR70436: Creation of common files SC6/Bac
 *         01.04.2010, anht: CR61829: Missing casts when using SC_MEMxxx functions
 *         22.04.2010, anht: CR61839/CR70426: added support for ASC3.x / make common
 *                                            files between Bac and Sc6
 *V13.0.4: 20.04.2010, anam: CR70288: Change storage classes in compiler abstraction for Diag
 *V13.0.3: 27.01.2010, gema: CR70527: Compiler switches shall have defined values
 *V13.0.2: 08.12.2009, gema: CR70475: Two different symbols for VSM Nvm-Block
 *                                    in SC6/BAC
 *                                    ==> BAC switch implemented
 *V13.0.1: 27.10.2009, gema: CR70429: Relocation of wrapper between DCM and
 *                                    bootdiag
 *                           CR70427: bootdiag: CR70219 - fixed
 *V13.0.0: 03.06.2009, hauf: CR61622: reworked by using functions with ECC/CRC
 *                                    handling from new Swe module
 *         29.05.2009, anht: CR61712: Added switch for noncompressed date stream
 *V12.0.1: 11.11.2008, miwe: CR61494/CR61524: fixed problem in NRV integration
 *V12.0.0: 05.11.2008, miwe: CR61489: extended BootMode flag to 64 bit
 *V11.5.0: 02.09.2008, masc: CR61431: added bootloader ECC error handling
 *         30.07.2008, dare: CR61388: added Blu Nv data conversion support
 *V11.4.0: 12.02.2008, dare: CR61332: fixed programming dependencies counter
 *V11.3.0: 31.01.2008, miwe: CR61314: removed check for unknown system supplier
 *                                    Id's
 *V11.2.0: 27.09.2007, miwe: CR61261: reworked FreeTimer integration
 *V11.1.0: 20.06.2007, chfr: CR61098: removed checks for valid BCD code for
 *                                    BMWWerksCode/BMWHaendlerNr
 *V11.0.1: 26.04.2007, miwe: Send ResponsePending when Flash driver performs a
 *                           valid check
 *         24.04.2007, miwe: BMWSCCRINT-384: do not reset on DefaultSession
 *                                           self-transition
 *                           Send ResponsePendig before updating FlashStatus
 *         12.04.2007, miwe: CR61024: Integration of DCM v3.1.0 with
 *                                    'Dcm_GetCurrentSessionTimings' API
 *         05.04.2007, miwe: CR61052: Force transmission of ResponsePending on
 *                           TransferData when EEPROM is updated (on physical
 *                           Flash segment borders)
 *V11.0.0: 22.03.2007, miwe: BMWSCCRINT-320: NegativeResponse on
 *                                           'NRVSTREAM_FINISHED' when requested
 *                                           amount of data was not transmitted
 *         22.02.2007, jetc: CR61024: added issues to solved P2/P2* timeout;
 *                           renamed Nvm_Vsm_NvData to NVM_VSM_NV_DATA.
 *V10.0.1: 08.12.2006, miwe: CR60872: fixed problem with extended operation mode
 *                                    in 'VSM_MM_MODE_NORMAL'
 *                           CR60877: resData-buffer is used instead of reqData
 *                                    to calculate the AlignOffset needed to
 *                                    write the ValidFlags and ProgDep-results
 *                                    to flash
 *                           BMWSCCRINT-258: fixed problem on processing of
 *                                           short fingerprints
 *                           BMWSCCRINT-256: fixed wrong initial value of
 *                                           'maxCounter' in 'GetCheckProgDep-
 *                                           ResultFromProgDepFlags'
 *         22.11.2006, miwe: CR60898: solved NRV problem:
 *                           when temp-buffer is full and the decomression
 *                           finishes at the same time, the module returns
 *                           'NRVSTREAM_TEMP_BUFFER_FULL' instead of
 *                           'NRVSTREAM_FINISHED'
 *V10.0.0: 04.11.2006, olgo: fixed NvStatusByte problem
 *                           + rename and expand WriteNvData to OperateNvData
 *         31.10.2006, miwe: CR60592: moved data from unpaged to paged RAM
 *         31.10.2006, olgo: changes because of compiler warnings
 *                           Led indicates tp reception and transmission
 *         23.10.2006, dare: adaptions for 16 bit platforms
 *         12.10.2006, miwe: MISRA checked
 *         29.09.2006, dare: prepare Rte_Dcm* functions for configurator
 *         21.09.2006, dabu: CR60758: no ProcessingDone in some cases of
 *                                    ReadDataById-request with wrong length
 *         13.09.2006, olgo: changes after review (only formating)
 *         04.09.2006, miwe: CR60714: adapted programming status range check in
 *                           function 'FlashWriteMaskingProgStat'
 *         31.08.2006, olgo: replaced nv memory write operations by function
 *                           'WriteNvData'
 *         30.08.2006, dabu: corrected DCM_BUFFER_SIZE checks
 *         25.08.2006, cma : non volatile data is accessed via MemIf instead of
 *                           EepIf => both Fee and Eep can be used
 *         24.07.2006, olgo: adaptions according to LH FP v07:
 *                           - restart of programming session
 *                           - new function for format checks of fingerprint
 *                           - NRC's of 'CheckMemory'-Request
 *                     miwe: - added 'ReadDataByIdentifier'
 *                             'VSM_OPERATION_MODE_EXTENSION' to Bootloader
 *                           - removed 'RoutineControl'
 *                             'CheckProgrammingPreConditions' from Bootloader
 *                           - renamed DiagService 'ReadSweDevelopmentInfo' to
 *                             'ReadDevelopmentInfo'
 *                           - PreconditionCheck of RoutineControl services of
 *                             the unlocked ProgrammingSession altered
 *                           - added 'SetVsmOperationModeExtension' to
 *                             Bootloader
 *                           - 'CheckMemory': 'lengthInformation' parameter
 *                             checked for value 0x0000
 *                           - removed ReadDataById(MaxBlockLength),
 *                             removed 'FlashBlockLength' from
 *                             'sharedBootROMData' because it's not needed in
 *                             the application any more
 *                           - ReadDataById(EcuManufacturingData) is now
 *                             mandatory: removed pre processor switches
 *                           - removed 'Rte_DcmCommunicationControl' from
 *                             Bootloader
 *                           - renamed ReadDataById(EcuId) to
 *                             ReadDataById(EcuSerialNumber)
 *                           - handling of session change to default session
 *                             altered: always reset the ECU, BootManager has to
 *                             determine the actual bootmode
 *                           - added new SWEProgrammingStatus type
 *                             'PROGSTAT_MEMORYSUCCESSFULLYERASED'
 *                           - handling of 'RequestTransferExit' changed because
 *                             the service can be used to cancel a running
 *                             transmission
 *                           - moved functions 'CheckProgDepStatus' and
 *                             'CheckSWEProgrammingStatus' from 'diag' to
 *                             'bootdiag'
 *                           - address check of FlashErase(EraseMethodAddressed)
 *                             improved, removed redundant config parameters
 *                           - removed the forced transmission of a
 *                             ResponsePending before writing the data in
 *                             'TransferData'
 *                           - reset op-mode extension in case of an op-mode
 *                             change
 *                           - renamed ReadDataById(ProgrammingStatus) to
 *                             ReadDataById(ReadMemoryAddress)
 *                           - implemented preassigned address and length format
 *                             identifier according to FP_5871
 *                           - FP_4919: added all the necessary parameters of
 *                             the SWE configuration to 'sharedBootROMData' -
 *                             needed by the BLU to detect a change in the SWE
 *                             configuration
 *                           - FP_5503: short Fingerprint is filled up with
 *                             default values
 *                           - renamed function 'WriteSvkBackup' to
 *                             'WriteSvkHistoryMemory'
 *                           - NRCs updated
 *                           - merged 'WriteFingerprint' and
 *                             'WriteApplStartedFirstFlag' to one function
 *                             because they write the same nv block at the same
 *                             time
 *                           - valid check of VIN added
 *                           - removed global flash driver activation code,
 *                             because 'FlashInit' is only used in function
 *                             'EraseMemory'
 *                           - removed the contrained of FP_5462 and the memory
 *                             segmentation config in 'Bootloader_Cfg_xxx.h'
 *                           - changes after review
 *                           - implemented download restart of transmission
 *                             ('Wiederaufsetzen') according to the new draft:
 *                             + address check in RequestDownload
 *                             + ReadDataById(ReadMemoryAddress)
 *                           - FP_5597: added 'FlashSegmentStatus'
 *                           - FP_5884: Low level retries of diagnostic services
 *         23.06.2006, miwe: 'sharedBootROMData' is linked near to save ROM
 *                           during the frequent access in 'diag' and 'bootdiag'
 *         23.06.2006, miwe: made bootdiag architecture independent:
 *                           dependencies in 'RequestDownload' removed
 *         22.06.2006, miwe: optimized 'SWE_VALID_FLAG_TABLE' away
 *         20.06.2006, miwe: + added function 'ConvertExtAddress2IntPointer' to
 *                             convert logical block numbers sent by the tester
 *                             to internal (far) data pointers
 *                           + added MemMap support for 'Vsm_NvData' to avoid
 *                             compiler warnings
 *                           + restructured the sharing of data between
 *                             bootloader and application
 *         12.06.2006, miwe: integration of nrv2b module
 *         18.05.2006, miwe: using type flash driver type 'flashAddress_t' for
 *                           all kind of flash addresses
 * V9.0.0: 21.06.2006, olgo: CR60584: if an BLU was found check only programming
 *                                    status of SWE1
 * V8.0.0: 24.04.2006, dabu: + CR60340: added support for MPC5553
 *                     ke  : + SC_MEMCPY modified to SC_MEMCPY_ROM
 *                           + SC_MEMSET modified to SC_MEMSET_ROM (=far)
 *                           + SweId initializes uncoditional
 *                           + offset_left an offset_right initializes uncoditional
 *                           + (defined (CPU_DERIVATIVE_IS_f276)) added
 *         20.04.2006, miwe: + check of Fingerprint format activated
 *                           + minor changes during integration of new cozyFlash
 *                           + 'Rte_DcmGetSesChgPermission' API changed from 2
 *                             to 3 parameters
 *         14.04.2006, miwe: changes due to testing of the bootloader
 *         12.04.2006, miwe: format check in 'WriteDataById(Fingerprint)' added
 *         06.04.2006, dabu: CR60479: Vsm_NvData decl. is now in Vsm_Client.h
 *         01.04.2006, cma : CR60215: compiler warnings removed
 *                           SignatureObject renamed to SweId, comments added
 *                           CRLFs inserted, superfluous 'extern' removed
 *                           Missing data block Vsm_NvData added
 *         27.03.2006, ke  : added support for CPU_DERIVATIVE_IS_xfr128
 *         23.03.2006, ke  : integrate updated crypto modules
 *         15.03.2006, olgo: replace EEPIF_CONST_PTR with P2CONST macro
 *         10.03.2006, miwe: MISRA checked
 *         09.03.2006, miwe: + (optional) SVK backup implemented
 *                           + length checks according ALFID added
 *         08.03.2006, dabu: CR60445: paged buffer processing implemented
 *         28.02.2006, dabu: CR60445: check RDByID-services whether the
 *                           response fit into the dcm buffer
 *         27.02.2006, miwe: DCM splitted task concept (task decoupling)
 *         23.02.2006, mm  : adaptations regarding 'SWEProgrammingStatus',
 *                           former 'SweStatus'
 *         16.02.2005, dabu: CR60480: Implementaion of op-mode SERVICE
 *         15.02.2006, hauf: Coding: if in bootloader send the NRC 'CNC' when
 *                                   adressing a coding relevant data identifier
 *         06.02.2006, dabu: Bootloader adaptions according to LH FP v05:
 *                           + added 'R.D.B.Id.ECUMANUFACTURINGDATA' (0xF18B)
 *                           + write op-mode (flash mode) to EEPROM
 *                           + implementation of CommunicationControl as dummy
 *                     miwe: + Deinitialization of Flash driver according to
 *                             FP_1505 and FP_4242
 *                           + Flash driver activation code introduced
 *                           + handling of ProgrammingCounter adapted
 *                           + handling of BSC adapted
 *                     olgo: + bootloader state machine adapted
 *                           + Application first startup
 *         01.02.2006, dabu: CR60419: added 'R.D.B.Id.ECUID' (0xF18C)
 * V7.8.0: 20.12.2005, mm  : + name of subparameter and subfunction in
 *                             'ApplDcmRoutineControl' changed
 *                           + request length check in 'ApplDcmTransferData' added
 *                           + 'controller id' for authentication changed:'SSECUSN'
 *                           + adaptation of indicated erase and memory check
 * V7.7.0: 16.12.2005, miwe: ForceResponsePending Hotfix
 * V7.6.0: 14.12.2005, jetc: added define FLASH_ERASED_BYTE in ApplDcmTransferData()
 * V7.5.0: 07.12.2005, hauf: added support for MB91
 * V7.4.0: 28.11.2005, miwe: CR60358: Session handling adapted,
 *                           SCTestService Set- and GetBootMode added,
 *                           CR60304: + ReadDataById(StandardCoreVersion)
 *                                    + RoutineControl(EraseMemory)
 *                                    + ReadDataByIdentifier(ENERGYSAVINGSTATE)
 *                                    + RoutineControl(ControlEnergySavingMode)
 * V7.3.0: 15.11.2005, chwi: added return to Bootmanager on testerpresent timeout
 * V7.2.1: 12.11.2005, hauf: added crypto activation/deactivation switch
 * V7.2.0: 11.11.2005, miwe: + moved parameter 'FLASH_DRIVER_SRC_ALIGNMENT' from
 *                             'bootdiag.c' to 'Bootloader_Cfg.h',
 *                           + function 'WriteSweValidFlag' fixed
 * V7.1.0: 10.11.2005, olgo: removed error in TransferData
 * V7.0.2: 07.11.2005, dabu: changes according internal code review
 * V7.0.1: 31.10.2005, miwe: CR60215: removed compiler warnings
 * V7.0.0: 21.10.2005, miwe: + ASR-DCM integration,
 *                           + Merged with 'appldiag.c',
 *                           + Common functions moved to 'diag.c'
 * V6.0.0: 28.09.2005, olgo: changes according new startup. BootStatus are stored
 *                           in RAM and must not be saved to EEPROM
 * V5.5.0: 29.09.2005, miwe: 'template_flexray/bootloader' integration
 * V5.4.0: 25.07.2005, miwe: code optimisations
 * V5.3.0: 07.09.2005, olgo: CR60232: moved Subparameter macros of diagnostic
 *                           services to diag.h, include diag.h
 * V5.2.0: 02.09.2005, gedr: CR60251, ECUReset in default session
 * V5.1.0: 30.08.2005, miwe: Phoenix-F support added
 * V5.0.0: 16.08.2005, mm  : adaptation of communicaton bus dependent
 *                           functionality into the new module 'BootNetInterface'
 * V4.5.0: 26.07.2005, mm  : session startup status improoved
 * V4.4.1: 25.07.2005, miwe: code optimisations
 * V4.4.0: 21.07.2005, miwe: + implementation of 'ProgrammingCounter' services
 *                           + 'FlashTimingParameter' response reworked
 * V4.3.0: 20.07.2005, mm  : + SVK backup hanadling changed
 *                           + new func. 'WriteFingerprint' added for
 *                             fingerprint saving into NVRAM memory
 *                           + handling of state 'FLASH_STATE_9b' in func.
 *                             'ApplDescProcessRoutineControl' added
 *                           + conditions for reprogramming without authentication
 *                             removed in 'ApplDescProcessReadDataByIdentifier'
 *                           + reset of 'sLastProgrammedAddressInRAM' in case of
 *                             a FLAH programming fault in
 *                             'ApplDescProcessTransferData' added
 *                           + 'sFingerprint' renamed to 'FingerprintInRam'
 * V4.2.0: 15.07.2005, miwe: adaptions in TransferData-Request
 * V4.1.0: 07.07.2005, miwe: Function 'WaitUntilEepromReady' moved to this file,
 *                           EEPROM write calls optimized,
 *                           Types renamed, aymbols used instead of magic numbers
 * V4.0.0: 05.07.2005, miwe: CR60047: HWE Sgbm Id(s) implemented
 * V3.0.1: 30.06.2005, miwe: used type xxx_least for loop counters when appropriate
 * V3.00 : 30.06.2005, miwe: + 'Read Data By Identifier' identifiers changed
 *                             according to LH v3
 *                           + Subparameter for 'requestSeed' and 'sendKey'
 *                             adapted
 *                           + made diag independend from number of SWEs
 *                           + 'RequestDownload' response extended by format
 *                             identifier
 * V2.01 : 27.06.2005, chwi: replaced EepDisp/Eeps calls with EepIf/EepRam calls
 * V2.00 : 27.06.2005, hauf: renamed boot_src_mcfg.h to Boot_Src_Cfg.h
 *                           changed typename BOOL to boolean
 *                           removed include bootloader_mcfg.h
 * V1.07 : 13.06.2005, miwe: invalid pointers at memcopy fixed
 * V1.06 : 20.04.2005, miwe: distinguish between ASYM and SYM crypto includes
 * V1.05 : 13.04.2005, hauf: removed include <string.h>
 * V1.04 : 15.03.2005, miwe: adapted swe addresses to V850
 * V1.03 : 14.03.2005, hauf: formated
 * V1.02 : 09.03.2005, hauf: removed unused, formated file
 * V1.01 : 19.01.2005, mm  : implementation of support according to the BMW specific
 *                           programming process for BNKSP (ISO14229-1/ISO15765-3)
 * V1.00 : 19.11.2004, mm  : initial implementation
 */

/*******************************************************************************
**                      MISRA Rules                                           **
*******************************************************************************/

/*

 11 MISRA Rule Violation:
    Indentifiers that do not differ from others within the specified number of
    significant characters are used because the compilers used in the
    StandardCore project do not have this limitation. This makes the code easier
    to read and the indentifiers can be consistent to the specifications

 33 MISRA Rule Violation:
    The nesting deepth is decreased, when a right hand operand that has side
    effects is used. In addition it decreases the code size in some cases when
    only one exception handling must be implemented

 43 MISRA Rule Violation:
 86 MISRA Rule Violation:
    This exceptions are created by a bug in the QAC-MISRA checker that doesn't
    support the autosar compiler abstraction

 44 MISRA Rule Violation:
    Redundant explicit casts should not be used.
    The redundant casts are in macros and should prevent use of wrong data type

 45 MISRA Rule Violation:
    Casts between a pointer to an integral type are used to calculate if a
    pointer address is aligned and to use the crypto API

 52 MISRA Rule Violation:
    Some control expressions may always be 'false/true':
    Reasons: The StandardCore is only a template that must be extended by the
    user

 61 MISRA Rule Violation:
    Every non-empty case clause in a switch statement shall be terminated with
    a break statement.
    Reason: Decreases the code size. Missing breaks are commented.

 63 MISRA Rule Violation:
    A switch statement with only 2 branches should usually be replaced with an
    "if ... else" construct.
    Reason: The amount of switch case statements depends on macro definitions
    and the code is easier to extend

 82 MISRA Rule Violation:
    More then one 'return' paths are used to make the code easier to read (e.g
    checking of preconditions), to save stack, to decrease nesting depth and to
    speedup execution

 87 MISRA Rule Violation:
    #include statements in a file shall only be preceded by other pre-processor
    directives or comments.
    Reason: This is necessary to support the MemMap concept

101 MISRA Rule Violation:
    Arithmetic operations shall not be performed on pointers - even with the
    value "1".
    Reason: code size optimization

*/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "bootdiag.h"          /* module own h-file                           */
/* -------------------------------------------------------------------------- */
#include "diag.h"              /* Subparameter macros of diagnostic services  */
/* -------------------------------------------------------------------------- */
#include "bootmain.h"          /* for 'WriteNvData' and 'WaitMemDriverReady'  */
                               /* prototypes                                  */
/* -------------------------------------------------------------------------- */
#include "Std_Types.h"         /* include AUTOSAR standard types              */
/* -------------------------------------------------------------------------- */
#include "Boot_Src_Cfg.h"      /* Module configuration header                 */
/* -------------------------------------------------------------------------- */
#include "sc_target.h"         /* Contains architecture independent general   */
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
#include "MemIf.h"             /* Memory interface (NvM is not used in        */
                               /* Bootloader)                                 */
/* -------------------------------------------------------------------------- */
#include "Bootloader_Cfg.h"    /* Programming specific timing parameters      */
/* -------------------------------------------------------------------------- */
#include "BootNetInterface.h"  /* contains all communication bus dependent    */
                               /* functions                                   */
/* -------------------------------------------------------------------------- */
#include "flash.h"             /* Contains the prototypes of the flash        */
                               /* functions. E.g.: 'FlashWrite' used in       */
                               /* some of the subsequent diagnostic servi-    */
                               /* ces to erase and write the flash memory.    */
/* -------------------------------------------------------------------------- */
#include "Boot_Crypto.h"       /* Crypto routines                             */
/* -------------------------------------------------------------------------- */
#include "Vsm_Client.h"        /* VSM modul specific include                  */
/* -------------------------------------------------------------------------- */
#if (SC_NRV2B_ENABLE == STD_ON)
   #include "nrv2b_stream.h"   /* nrv2b module include                        */
#endif
/* -------------------------------------------------------------------------- */
#if ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON))
   #include "Boot_Test.h"
#endif
/* -------------------------------------------------------------------------- */
#if (SC_LED_DEMO_ON == STD_ON || defined BAC)
                               /* can be enabled in 'StandardCore.mcfg' (SC6) */
							   /* in BAC the LED could be Enabled in Led.epc  */
   #include "Led.h"            /* LED Api                                     */
#endif
/* -------------------------------------------------------------------------- */
#include "FreeTimer.h"         /* free running timer data type and calls      */
/* -------------------------------------------------------------------------- */


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

#define BLU_TABLE_FLAG_LENGTH       0x08u /*
                                           * Length of valid flag of Blu table
                                           */

#define BLU_TABLE_FLAG_VALID        0xEBu /*
                                           * valid value of valid flag of Blu
                                           * table
                                           */

#define BLU_FLASHBUFFER_LENGTH     0x100u /*
                                           * Size of the flash buffer for
                                           * storing Nv data to flash in the
                                           * old Bootloader.
                                           */

#define BSC_INIT_VALUE              0x00u /*
                                           * initial value of
                                           * BlockSequenceCounter used during
                                           * TransferData Requests
                                           */
#define BSC_MAX_FALLBACK            0x0Au /*
                                           * for a restart of the transmission
                                           * the tester can send a
                                           * 'TransferData' with an BSC of the
                                           * past in  range of this value.
                                           */
#define BSC_MAX_RETRANSMISSIONS     0x05u /*
                                           * FP_5392: Max number of
                                           * retransmissions of the same BSC
                                           */
#if (SC_NONCOMPRESSED_ENABLE == STD_ON)
  #define DFI_NOTCOMPRESSED_NOTENCRYPTED    0x00u
#endif

#if (SC_NRV2B_ENABLE == STD_ON)
  #define DFI_NRV2B_COMPRESSED_NOTENCRYPTED 0x10u
#endif                                    /*
                                           * DataFormatIdentifier for
                                           * RequestDownload
                                           */

#define BCD2DEC(BCD)   (uint8)                                                 \
                       (                                                       \
                         ( ( ((BCD)>>4u) & 0x0Fu) * 10u) +                     \
                           (  (BCD)      & 0x0Fu)                              \
                       )
                                          /*
                                           * converts a 8 bit BCD value to
                                           * decimal system
                                           */
#define IsBCDDigit(digit)    ((((uint8)(digit)) <= (uint8)0x09u) ? TRUE : FALSE)
                                          /*
                                           * check, if the given digit is a BCD
                                           * value
                                           */
#define ByteIsBCDValue(Byte)   (                                               \
                                 (IsBCDDigit(((uint8)(Byte)) >> (uint8)4u)) && \
                                 (IsBCDDigit(((uint8)(Byte)) &  (uint8)0x0Fu)) \
                               )
                                          /*
                                           * check, if the given byte is a BCD
                                           * encoded value
                                           */

#define FLASH_DRIVER_VALID_ACTIVATION_CODE 0x06u

/*
 * The 'FLASH_BLOCK_LEN' is used to inform the Tester about the maximum length
 * of the 'TransferData' message including the service ID. The Tester gets this
 * information in the response message of 'RequestDownload'.
 * The 'FLASH_BLOCK_LEN' contains: 'Message ID [1 byte]' +
 * 'block sequence counter [1 byte]' + data to be programmed [FLASH_BLOCK_LEN-2]
 * The 'FLASH_BLOCK_LEN' minus 2 Bytes has to be an even number because the
 * flash driver is able to handle even count of bytes ('FLASH_PAGE_SIZE' bytes)
 * At least 'FLASH_SRC_ADDR_ALIGN - 1' bytes have to be reserved in the diag
 * buffer for moving the data to even address
 */
#define HEADER_LEN 0x02u
#define TMP_FLASH_BLOCK_LEN                                                    \
  (DCM_BUFFER_SIZE - HEADER_LEN - (FLASH_SRC_ADDR_ALIGN - 0x01u))

#define FLASH_BLOCK_LEN                                                        \
  ( TMP_FLASH_BLOCK_LEN - (TMP_FLASH_BLOCK_LEN % FLASH_PAGE_SIZE) + HEADER_LEN )

#if (SC_NRV2B_ENABLE == STD_ON)

   /* special values needed for ResponsePending supervision                   */
   #define TIMER_RESTART                                            0x00000000uL
   #define TIMER_INACTIVE                                           0xFFFFFFFFuL

   #ifdef DCM_TIMEOUT_P2STAR_ADJUST
      #define ADJUST_TIMEOUT_P2EX(timeOutP2Ex) ((timeOutP2Ex) -                \
                                                (DCM_TIMEOUT_P2STAR_ADJUST)    \
                                               )
   #elif ( defined (DCM_TIMEOUT_P2EX_75_ENABLED) &&                            \
           (DCM_TIMEOUT_P2EX_75_ENABLED == CONFIG_TRUE)                        \
         )
      /* 75% of P2Ex */
      #define ADJUST_TIMEOUT_P2EX(timeOutP2Ex)   (uint16)( ((timeOutP2Ex)   )- \
                                                           ((timeOutP2Ex)>>1)+ \
                                                           ((timeOutP2Ex)>>2)  \
                                                         )
   #elif ( defined (DCM_TIMEOUT_P2EX_87_5_ENABLED) &&                          \
         (DCM_TIMEOUT_P2EX_87_5_ENABLED == CONFIG_TRUE)                        \
         )
      /* 87.5% of P2Ex */
      #define ADJUST_TIMEOUT_P2EX(timeOutP2Ex)   (uint16)( ((timeOutP2Ex))  )- \
                                                           ((timeOutP2Ex)>>1)+ \
                                                           ((timeOutP2Ex)>>2)+ \
                                                           ((timeOutP2Ex)>>3)  \
                                                         )
   #else
      /* 100% of P2Ex */
      #define ADJUST_TIMEOUT_P2EX(timeOutP2Ex)                     (timeOutP2Ex)
   #endif

#endif /* (SC_NRV2B_ENABLE == STD_ON)                                             */


/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/* table header within Blu with information for Nv data backup                */
typedef struct
{
   uint8 validFlag[BLU_TABLE_FLAG_LENGTH];  /*
                                             * This entry indicates if the
                                             * corresponding table is valid.
                                             */
   uint8 version[SWESOFTWAREVERSIONLENGTH]; /*
                                             * This entry has to correspond to
                                             * the BOOTSWESOFTWAREVERSIONDATA
                                             * of the old Bootloader.
                                             */
   uint16 numberFlashSegments;              /*
                                             * This entry indicates the number
                                             * of flash segments to be erased.
                                             */
   uint16 numberNvBlocks;                   /*
                                             * This entry indicates the number
                                             * of Nv blocks to be stored.
                                             */
   uint32 statusAddress;                    /*
                                             * Pointer to flash addresses to
                                             * which the version data, key data
                                             * and valid flag have to be stored.
                                             */
} Blu_BackupTableHeaderType;

typedef struct
{
   uint8 transmittedBlocks;               /*
                                           * This variable counts the
                                           * numberof data blocks that are
                                           * transmitted by the tester
                                           * during a flash download
                                           */
   uint8 dataFormatIdentfier;             /*
                                           * Stores the actual
                                           * 'dataFormatIdentifer' received in
                                           * 'RequestDownload' and needed at
                                           * 'TransferData'. It is used to
                                           * distinguish between compressed and
                                           * uncompressed data
                                           */
   flashAddress_t memStartAddress;        /*
                                           * memStartAddress holds the start
                                           * address of the memory area that
                                           * is requested by the tester
                                           */
   flashAddress_t memEndAddress;          /*
                                           * memEndAddress holds the end
                                           * address of the memory area that
                                           * is requested by the tester
                                           */
} ReprogrammingParamsType;

/* Return values for WriteProgrammingDependencies                             */
typedef enum
{
   PROG_DEP_WRITTEN,                      /* correctly written                */
   PROG_DEP_CONDITIONSNOTCORRECT,         /* invalid value of 'ProgDepVal'    */
   PROG_DEP_ERROR_WRITING                 /* error while flash writing        */
} WriteProgDepRetValType;

/*
 * Return value type of function 'GetFlashSegmentNumberByMemAddress':
 * For the meaning of the values see the function header
 */
typedef enum
{
   ADDRESS_NOT_FOUND,
   ADDRESS_FOUND_NO_FLASH_SEGMENT_BORDER,
   ADDRESS_FOUND_FLASH_SEGMENT_BORDER
} GetFlashSegmentNumberType;

typedef enum
{
   FLASH_SEG_DONT_ERASE          = 0x00u, /*
                                           * value to mark flash segments
                                           * as "do not erase"
                                           */

   FLASH_SEG_ERASE_HIGH_PRIO     = 0x55u, /*
                                           * value to mark memory segments
                                           * for high priority erasing, e.g.
                                           * erasing of the flash segments
                                           * including the valid flags in a
                                           * first run
                                           */

   FLASH_SEG_ERASE_LOW_PRIO      = 0xAAu  /*
                                           * value to mark memory segments
                                           * for low priority erasing
                                           */
} FlashSegmentEraseValueType;

#if (SC_NRV2B_ENABLE == STD_ON)

#if ((NRV2B_TEMP_BUFFER_SIZE%FLASH_PAGE_SIZE) != 0x00u)
   #error "bootdiag.c: 'NRV2B_TEMP_BUFFER_SIZE' must be a multiple of 'FLASH_PAGE_SIZE'"
#endif

typedef struct
{
   /*
    * Pointer to 'nrv2bTempBuffer' that is aligned according to
    * 'FLASH_SRC_ADDR_ALIGN'
    */
#ifdef BAC
	P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) nrv2bTempBufferPtr;
#else
   uint8 * nrv2bTempBufferPtr;
#endif /* Defined BAC */
   /* temporary buffer taking the uncompressed data                           */
   uint8 nrv2bTempBuffer[NRV2B_TEMP_BUFFER_SIZE + FLASH_SRC_ADDR_ALIGN - 1u];
} nrv2bCtrlType;

typedef struct
{
   /*
    * Counting the elapsed time since last RP during processing of NRV
    * compressed data (in ticks).
    */
   FreeTimer_TimeInTicksType elapsedTime;
   /* The active timeout: P2 or P2* in ticks */
   FreeTimer_TimeInTicksType currentTimeOut;
#ifdef BAC
   P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pCurrentMsgContext;
#else
   Dcm_MsgContextType * pCurrentMsgContext;
#endif /* Defined BAC */
} responsePendingSupervisionType;

#endif /* (SC_NRV2B_ENABLE == STD_ON)                                             */


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define BOOTDIAG_START_SEC_CODE
#include "MemMap.h"

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) Blu_BackupNvData
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void Blu_BackupNvData
		   (
			  Dcm_MsgContextType * const pMsgContext
		   );
#endif /* Defined BAC */


#ifdef BAC
	static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) FlashEraseInitEraseMethodAddressed
		   (
			  CONST(Dcm_MsgLenType, DCM_APPL_CODE)        reqDataLen,
			  CONST(Dcm_MsgType, DCM_APPL_CODE)           reqDataPtr,
			  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ptempSWEProgStatus
		   );
#else
	static Dcm_NegativeResponseCodesType FlashEraseInitEraseMethodAddressed
           (
              const Dcm_MsgLenType         reqDataLen,
              const Dcm_MsgType            reqDataPtr,
                    uint8          * const ptempSWEProgStatus
           );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) FlashEraseInitEraseMethodIndicated
		   (
			  CONST(Dcm_MsgLenType, DCM_APPL_CODE)        reqDataLen,
			  CONST(Dcm_MsgType, DCM_APPL_CODE)           reqDataPtr,
			  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ptempSWEProgStatus
		   );
#else
	static Dcm_NegativeResponseCodesType FlashEraseInitEraseMethodIndicated
           (
              const Dcm_MsgLenType       reqDataLen,
              const Dcm_MsgType          reqDataPtr,
              uint8*               const ptempSWEProgStatus
           );
#endif /* Defined BAC */
	
#ifdef BAC
	static FUNC(flashStatus_t, DCM_APPL_CODE) FlashEraseFlash
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
			  CONST(FlashSegmentEraseValueType, DCM_APPL_CONST)        FlashSegmentEraseValue
		   );
#else
	static flashStatus_t FlashEraseFlash
           (
			        Dcm_MsgContextType*        const pMsgContext,
			  const FlashSegmentEraseValueType       FlashSegmentEraseValue
           );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) GetApplSWENumberByFlashSegmentNumber
		   (
			  CONSTP2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) pFlashSegmentNumber,
			  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)   pApplSWENumber
		   );
#else				
	static boolean GetApplSWENumberByFlashSegmentNumber
           (
              const uint8 * const pFlashSegmentNumber,
                    uint8 * const pApplSWENumber
           );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) GetApplSWENumberByLogicalBlockNumber
		   (
			  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA) pLogicalBlockNumber,
			  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)            pApplSWENumber
		   );
#else			  
    static boolean GetApplSWENumberByLogicalBlockNumber
           (
              const flashAddress_t * const pLogicalBlockNumber,
                    uint8          * const pApplSWENumber
           );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(GetFlashSegmentNumberType, DCM_APPL_CODE) GetFlashSegmentNumberByMemAddress
		   (
			  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA) pMemAddress,
			  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)            pFlashSegmentNumber
		   );
#else
	static GetFlashSegmentNumberType GetFlashSegmentNumberByMemAddress
           (
              const flashAddress_t * const pMemAddress,
                    uint8          * const pFlashSegmentNumber
           );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) CheckFingerPrint
		   (
			  CONST(Dcm_MsgType, DCM_APPL_CONST) Fingerprint
		   );
#else					
    static boolean CheckFingerPrint
		   (
			  const Dcm_MsgType Fingerprint
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) CheckProgrammingDate
		   (
			  CONST(uint8, DCM_APPL_CONST) year,
			  CONST(uint8, DCM_APPL_CONST) month,
			  CONST(uint8, DCM_APPL_CONST) day
		   );
#else
	static boolean CheckProgrammingDate
		   (
			  const uint8 year,
			  const uint8 month,
			  const uint8 day
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) ProgrammingCounterLimitExceeded( void );
#else
	static boolean ProgrammingCounterLimitExceeded( void );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(uint8, DCM_APPL_CODE) CalculateAlignOffset
		   (
		      CONST(uint32, DCM_APPL_CONST) Address,
			  CONST(uint8, DCM_APPL_CONST)  Alignment
		   );
#else
	static uint8 CalculateAlignOffset
		   (
			  const uint32 Address, 
			  const uint8 Alignment
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) SetFlashSegmentStatusToNotWritable
		   (
			  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA)   pMemStartAddress,
			  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA)   pMemEndAddress,
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static Dcm_NegativeResponseCodesType SetFlashSegmentStatusToNotWritable
           (
              const flashAddress_t     * const pMemStartAddress,
              const flashAddress_t     * const pMemEndAddress,
			        Dcm_MsgContextType * const pMsgContext
           );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat
		   (
			  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)              pDataBuffer,
			  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA)   pMemStartAddress,
			  CONST(uint16, DCM_APPL_CONST)                            BufferLength,
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static Dcm_NegativeResponseCodesType FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat
           (
			        uint8              * const pDataBuffer,
              const flashAddress_t     * const pMemStartAddress,
              const uint16                     BufferLength,
                    Dcm_MsgContextType * const pMsgContext
		   );
#endif /* Defined BAC */

#if (! ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON)))
	#ifdef BAC
		static FUNC(boolean, DCM_APPL_CODE) WriteSvkHistoryMemory( void );
	#else
		static boolean WriteSvkHistoryMemory( void );
	#endif /* Defined BAC */
	#ifdef BAC
		static FUNC(boolean, DCM_APPL_CODE) WriteFingerprintAndApplStartedFirstFlag( void );
	#else
		static boolean WriteFingerprintAndApplStartedFirstFlag( void );
	#endif /* Defined BAC */
#endif /* Defined (! ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON))) */

#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) WriteSweValidFlag
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
			  CONST(uint8, DCM_APPL_CONST)                             SweNumber,
              CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)              tmpBuffer
		   );
#else
	static boolean WriteSweValidFlag
           (
			        Dcm_MsgContextType * const pMsgContext,
              const uint8                      SweNumber,
                    uint8              * const tmpBuffer
		   );
#endif /* Defined BAC */
								 
#ifdef BAC
	static FUNC(WriteProgDepRetValType, DCM_APPL_CODE) WriteProgrammingDependencies
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
			  CONST(SweProgDepStateType, DCM_APPL_CONST)               ProgDepVal,
			  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)              tmpBuffer
		   );
#else
	static WriteProgDepRetValType WriteProgrammingDependencies
           (
			        Dcm_MsgContextType  * const pMsgContext,
              const SweProgDepStateType         ProgDepVal,
                    uint8               * const tmpBuffer
			);
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) GetAddressAndLengthByFormatIdentifier
		   (
			  VAR(Dcm_MsgType, DCM_APPL_DATA)                      reqDataPtr,
			  CONST(uint8, DCM_APPL_CONST)                         addressOrLengthSize,
			  CONST(uint8, DCM_APPL_CONST)                         addressOrLengthFormatId,
			  CONSTP2VAR(flashAddress_t, AUTOMATIC, DCM_APPL_DATA) pAddress,
			  CONSTP2VAR(flashAddress_t, AUTOMATIC, DCM_APPL_DATA) pLength
			);
#else
	static Dcm_NegativeResponseCodesType GetAddressAndLengthByFormatIdentifier
           (
              Dcm_MsgType            reqDataPtr,
              const uint8            addressOrLengthSize,
              const uint8            addressOrLengthFormatId,
              flashAddress_t * const pAddress,
              flashAddress_t * const pLength
           );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) ApplDcmTransferDataNotCompressedNotEncrypted
		   (
			  CONST(Dcm_MsgType, DCM_APPL_CONST)                       reqDataPtr,
			  CONST(uint16, DCM_APPL_CONST)                            payLoadLength,
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static Dcm_NegativeResponseCodesType ApplDcmTransferDataNotCompressedNotEncrypted
		   (
			  const Dcm_MsgType                reqDataPtr,
			  const uint16                     payLoadLength,
			        Dcm_MsgContextType * const pMsgContext
		   );
#endif /* Defined BAC */
							  
#ifdef BAC
	static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) ApplDcmTransferDataNrvCompressedNotEncrypted
		   (
			  CONST(Dcm_MsgType, DCM_APPL_CONST)                       reqDataPtr,
			  CONST(uint16, DCM_APPL_CONST)                            payLoadLength,
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static Dcm_NegativeResponseCodesType ApplDcmTransferDataNrvCompressedNotEncrypted
		   (
			  const Dcm_MsgType                reqDataPtr,
			  const uint16                     payLoadLength,
			        Dcm_MsgContextType * const pMsgContext
		   );
#endif

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmConfirmationECUReset
		   (
			  CONST(Dcm_ConfirmationStatusType, DCM_APPL_CONST) status,
			  CONST(uint8, DCM_APPL_CONST)                      pendingSubFunction
		   );
#else
	static void ApplDcmConfirmationECUReset
           (
              const Dcm_ConfirmationStatusType status,
              const uint8                      pendingSubFunction
           );
#endif

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierEnergyState
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmReadDataByIdentifierEnergyState
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierEnergyStateExtension
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmReadDataByIdentifierEnergyStateExtension
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierReadMemoryAddress
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmReadDataByIdentifierReadMemoryAddress
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmWriteDataByIdentifierFingerprint
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmWriteDataByIdentifierFingerprint
           (
			  Dcm_MsgContextType* const pMsgContext
           );
#endif /* Defined BAC */

#ifdef BAC
    static FUNC(void, DCM_APPL_CODE) ApplDcmWriteDataByIdentifierVin
		   (
		 	 CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmWriteDataByIdentifierVin
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlCheckMemory
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmRoutineControlCheckMemory
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#if (SC_BOOT_CRYPTO_ENABLE == STD_ON)
#if defined (CRYPTO_AUTH_ASYM)
#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) ApplDcmRoutineControlCheckMemoryAsym
		   (
			  CONST(uint8, DCM_APPL_CONST) SweId
		   );
#else
    static boolean ApplDcmRoutineControlCheckMemoryAsym
		   (
			  const uint8 SweId
		   );
#endif /* Defined BAC */
#elif defined (CRYPTO_AUTH_SYM)
#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) ApplDcmRoutineControlCheckMemorySym
		   (
			  CONST(uint8, DCM_APPL_CODE) SweId
		   );
#else
    static boolean ApplDcmRoutineControlCheckMemorySym
	       (
	          const uint8 SweId
		   );
#endif /* Defined BAC */
#else
    #error "bootdiag.c: No crypto method defined. Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'"
#endif /* Defined (CRYPTO_AUTH_ASYM) */
#endif /* If (SC_BOOT_CRYPTO_ENABLE == STD_ON) */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlReadSWEProgrammingStatus
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmRoutineControlReadSWEProgrammingStatus
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlEraseMemory
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmRoutineControlEraseMemory
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlCheckProgrammingDependencies
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmRoutineControlCheckProgrammingDependencies
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlSetVsmOperationMode
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmRoutineControlSetVsmOperationMode
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
	static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlSetVsmOperationModeExtension
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	static void ApplDcmRoutineControlSetVsmOperationModeExtension
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#define BOOTDIAG_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define BOOTDIAG_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
                                      /* initialized during StartupSequence() */
   SubSessionType activeSubSession = ELSE_SUB_SESSION_STATE;

#define BOOTDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*
 * Instantiation of RAM block for VSM data in bootloader.
 * Initialized in 'bootmain.c'
 */
#define VSM_START_SEC_VAR_NVDATA
#include "MemMap.h"
   Vsm_NvDataType Vsm_NvData;                             /* NVRAM RAM mirror */
#define VSM_STOP_SEC_VAR_NVDATA
#include "MemMap.h"


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

#define BOOTDIAG_START_SEC_VAR_FLASHBUFFER
#include "MemMap.h"

static uint8 Blu_FlashBuffer[BLU_FLASHBUFFER_LENGTH];

#define BOOTDIAG_STOP_SEC_VAR_FLASHBUFFER
#include "MemMap.h"

#define BOOTDIAG_START_SEC_VAR_NO_INIT_8BIT
#include "MemMap.h"

   static uint8 FingerprintInRam[FINGERPRINTLENGTH];
                                            /* reserved memory for the        */
                                            /* temporary, new fingerprint     */

   static uint8 MemSegToErase[FLASH_SEGMENT_NUMBER_APPL];
                                          /*
                                           * This array marks the memory
                                           * segments in 'FlashEraseInit'
                                           * that should be erased in
                                           * 'FlashEraseFlash'
                                           */

#define BOOTDIAG_STOP_SEC_VAR_NO_INIT_8BIT
#include "MemMap.h"

#define BOOTDIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

   static ReprogrammingParamsType ReprogrammingParams;

   #if (SC_NRV2B_ENABLE == STD_ON)
      static nrv2bCtrlType nrv2bCtrl;     /* data used for nrv2b algorithm    */
   #endif /* (SC_NRV2B_ENABLE == STD_ON)                                          */

#define BOOTDIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define BOOTDIAG_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

   #if (SC_NRV2B_ENABLE == STD_ON)
      responsePendingSupervisionType responsePendingSupervision =
      {
         (FreeTimer_TimeInTicksType)TIMER_INACTIVE,
         (FreeTimer_TimeInTicksType)0x00000000uL,
         NULL_PTR
      };
   #endif /* (SC_NRV2B_ENABLE == STD_ON)                                          */

#define BOOTDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define BOOTDIAG_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Blu_BackupNvData                                           **
**                                                                            **
** DESCRIPTION   : This function uses the data given in a table within the    **
**                 Blu to erase flash segments and backup Nv data within      **
**                 the erased flash segments. The backup can be used in the   **
**                 new Bootloader after the Bootloader update to convert Nv   **
**                 data into a new memory layout.                             **
**                                                                            **
** PRECONDITIONS : The flash driver is initialized.                           **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT:        : Dcm_MsgContextType* const pMsgContext                      **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : The Nv data backup process has to be synchronized with the **
**                 Blu and the new Bootloader.                                **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(void, DCM_APPL_CODE) Blu_BackupNvData
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void Blu_BackupNvData
       (
          Dcm_MsgContextType* const pMsgContext
       )
#endif /* Defined BAC */
{
   /* The pointer to the table is located directly before the Blu SWE table.  */
   const uint32 SC_FAR_POINTER const headerPtrLoc =
                            ( ( (const uint32 SC_FAR_POINTER)&Swe1Table ) - 1 );

   const Blu_BackupTableHeaderType SC_FAR_POINTER headerPtr;
   const uint32 SC_FAR_POINTER flashSegmentAddresses;
   const uint32 SC_FAR_POINTER flashSegmentLengths;
   const uint32 SC_FAR_POINTER nvBackupAddresses;
   const uint16 SC_FAR_POINTER nvBlockIds;
   const uint16 SC_FAR_POINTER nvBlockLengths;
   boolean skip = FALSE;
   uint8_least iLoop;
   uint16 blockOffset;
   uint16 readLength;
   uint8 checksum = 0;
   uint16 checksumLoop;
#if (SC_FEE_ENABLE != STD_ON)
   MemIf_JobResultType jobResult;
#endif

   /*
    * Init pointer variables
    */
   headerPtr = (const Blu_BackupTableHeaderType SC_FAR_POINTER) *headerPtrLoc;

   /*
    * Element after table header is an array which contains the addresses to the
    * flash segments which have to be used for Nv data backup.
    */
   flashSegmentAddresses = (const uint32 SC_FAR_POINTER)&headerPtr[1];

   /*
    * Element after flash segment addresses is an array which contains the
    * lengths of the flash segments which have to be used for Nv data backup.
    */
   flashSegmentLengths = (const uint32 SC_FAR_POINTER)
                         &flashSegmentAddresses[headerPtr->numberFlashSegments];

   /*
    * Element after flash segment lengths is an array which contains the
    * addresses within the Nv data backup area for the backup of the Nv blocks.
    */
   nvBackupAddresses = (const uint32 SC_FAR_POINTER)
                           &flashSegmentLengths[headerPtr->numberFlashSegments];

   /*
    * Element after Nv data backup addresses is an array which contains the ids
    * of the blocks for which a backup has to be done in the old Bootloader.
    */
   nvBlockIds = (const uint16 SC_FAR_POINTER)
                                  &nvBackupAddresses[headerPtr->numberNvBlocks];

   /*
    * Element after Nv block ids is an array which contains the lengths of the
    * blocks for which a backup has to be done in the old Bootloader.
    */
   nvBlockLengths = (const uint16 SC_FAR_POINTER)
                                  &nvBlockIds[headerPtr->numberNvBlocks];

   /* Check valid flag of the table                                           */
   for ( iLoop = 0; iLoop < BLU_TABLE_FLAG_LENGTH; iLoop++ )
   {
      if ( (uint8)BLU_TABLE_FLAG_VALID != headerPtr->validFlag[iLoop] )
      {
         skip = TRUE;
      }
   }

   /*
    * Compare the intended Bootloader version of the table with the current
    * BOOTSWESOFTWAREVERSIONDATA.
    */
   if (
        SC_MEMCMP_ROM(
                       (const void SC_FAR_POINTER)&SweBootTable.SgbmId[SWECLASSIFICATIONLENGTH +
                                                                       SWELOGISTICIDENTIFIERLENGTH],
                       (const void SC_FAR_POINTER)&(headerPtr->version[0]),
                       SWESOFTWAREVERSIONLENGTH
                     )
      )
   {
      skip = TRUE;
   }

   /* erase backup area                                                       */
   for (
         iLoop = 0;
         ( FALSE == skip ) && ( iLoop < headerPtr->numberFlashSegments );
         iLoop++
       )
   {
      /* Send response pending prior to erasing flash segment                 */
      Dcm_SendResponsePending(pMsgContext);

      if ( FLASH_OK !=
           FlashErase(
                       (flashAddress_t)flashSegmentAddresses[iLoop],
                       (flashMemoryLength_t)flashSegmentLengths[iLoop]
                     )
         )
      {
         skip = TRUE;
      }
   }

   /* backup Nv data                                                          */
   for (
         iLoop = 0;
         ( FALSE == skip ) && ( iLoop < headerPtr->numberNvBlocks );
         iLoop++
       )
   {
#if (SC_FEE_ENABLE == STD_ON)
      for (
            blockOffset = 0;
            ( FALSE == skip ) && ( blockOffset < nvBlockLengths[iLoop] );
            blockOffset += BLU_FLASHBUFFER_LENGTH
          )
#else /* (SC_FEE_ENABLE == STD_ON) */
      /* take care of NvM valid byte                                          */
      for (
            blockOffset = 0;
            ( FALSE == skip ) && ( blockOffset < (nvBlockLengths[iLoop] + 1) );
            blockOffset += BLU_FLASHBUFFER_LENGTH
          )
#endif /* (SC_FEE_ENABLE == STD_ON) */
      {
         /* calculate new length to be flashed                                */
#if (SC_FEE_ENABLE == STD_ON)
         readLength = nvBlockLengths[iLoop] - blockOffset;
#else
         /* take care of NvM valid byte                                       */
         readLength = nvBlockLengths[iLoop] + 1 - blockOffset;
#endif

         /* adapt to flash buffer size                                        */
         readLength = ( readLength > BLU_FLASHBUFFER_LENGTH ) ?
                                            BLU_FLASHBUFFER_LENGTH : readLength;

#if (SC_FEE_ENABLE == STD_ON)
         /* read content from Nv data                                         */
         if (
              E_OK !=
              MemIf_Read(
                          0u,
                          nvBlockIds[iLoop],
                          blockOffset,
                          &Blu_FlashBuffer[0],
                          readLength
                        )
            )
         {
            skip = TRUE;
            break;
         }

         if ( MEMIF_JOB_OK != WaitMemDriverReady() )
         {
            skip = TRUE;
            break;
         }
#else /* (SC_FEE_ENABLE == STD_ON) */
         /*
          * The Ea module does neither support Application Nv data access nor
          * reading parts starting from an offset != 0. Access EEPROM directly.
          */
         if (
              E_OK !=
              MemIf_Read(
                          0u,
                          nvBlockIds[iLoop],
                          blockOffset,
                          &Blu_FlashBuffer[0],
                          readLength
                        )
            )
         {
            skip = TRUE;
            break;
         }

         if ( MEMIF_JOB_OK != WaitMemDriverReady() )
         {
            skip = TRUE;
            break;
         }
#endif /* (SC_FEE_ENABLE == STD_ON) */

         for (
               checksumLoop = 0;
               checksumLoop < readLength;
               checksumLoop++
             )
         {
            checksum = checksum ^ Blu_FlashBuffer[checksumLoop];
         }

         if (
              FLASH_OK !=
              FlashWrite( &Blu_FlashBuffer[0],
                               (flashAddress_t)
                               ( nvBackupAddresses[iLoop] + blockOffset ),
                               (flashMemoryLength_t) BLU_FLASHBUFFER_LENGTH
                             )
            )
         {
            skip = TRUE;
         }
      }
   }

   if ( FALSE == skip )
   {
      /* store valid flag                                                     */
      (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&Blu_FlashBuffer[0],
                       (uint8)BLU_TABLE_FLAG_VALID,
                       BLU_TABLE_FLAG_LENGTH
                     );

      /* store Bootloader version                                             */
      (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&Blu_FlashBuffer[BLU_TABLE_FLAG_LENGTH],
                           (const void SC_FAR_POINTER)&SweBootTable.SgbmId[SWECLASSIFICATIONLENGTH +
                                                                           SWELOGISTICIDENTIFIERLENGTH],
                           SWESOFTWAREVERSIONLENGTH
                         );

      /* store flash driver initialization key                                */
      Blu_FlashBuffer[BLU_TABLE_FLAG_LENGTH + SWESOFTWAREVERSIONLENGTH] = 0x6;

      /* store checksum                                                       */
      Blu_FlashBuffer[BLU_TABLE_FLAG_LENGTH + SWESOFTWAREVERSIONLENGTH + 1] =
                                                                       checksum;

      (void)FlashWrite( &Blu_FlashBuffer[0],
                        (flashAddress_t)headerPtr->statusAddress,
                        (flashMemoryLength_t) BLU_FLASHBUFFER_LENGTH
                      );
   }
} /* end of function 'Blu_BackupNvData'                                       */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmConfirmationECUReset                                **
**                                                                            **
** DESCRIPTION   : Post handler of 'ApplDcmECUReset' (0x11)                   **
**                 Trigger a reset. This function implements the second step  **
**                 of the operation after the positive response was send.     **
**                 The functions initiates the shutdown (inc. writing         **
**                 data to EEPROM)                                            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : pendingSubFunction: reset Mode                             **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(void, DCM_APPL_CODE) ApplDcmConfirmationECUReset
	   (
		  CONST(Dcm_ConfirmationStatusType, DCM_APPL_CONST) status,
		  CONST(uint8, DCM_APPL_CONST)                      pendingSubFunction
	   )
#else
static void ApplDcmConfirmationECUReset
       (
          const Dcm_ConfirmationStatusType status,
          const uint8                      pendingSubFunction
       )
#endif /* Defined BAC */
{
   switch(status)
   {
      case DCM_RES_POS_OK:
         /* ... positive response has been successfully sent.                 */
         switch (pendingSubFunction)
         {
            case DIAG_UDS11_01_HARD_RESET:
               /*
                * Deinitialize the Flash driver
                */
               (void)FlashDeInit();

               /* Trigger a reset                                             */
               ResetECU();
               break;
            default:
               /* unknown sub parameter                                       */
               break;
         }
         break;
      default:
         break;
   }
} /* end of function 'ApplDcmConfirmationECUReset'                            */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierEnergyState                     **
**                                                                            **
** DESCRIPTION   : read actual operation mode from RAM mirror                 **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierEnergyState
	   (
	      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmReadDataByIdentifierEnergyState
       (
          Dcm_MsgContextType* const pMsgContext
	   )
#endif /* Defined BAC */
{
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   *resDataPtr = Vsm_NvData.Vsm_opMode;

   pMsgContext->resDataLen = (uint16)3;            /* add length of fetra fla */
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierEnergyStateExtension            **
**                                                                            **
** DESCRIPTION   : read actual extended operation mode from RAM mirror        **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierEnergyStateExtension
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmReadDataByIdentifierEnergyStateExtension
       (
          Dcm_MsgContextType* const pMsgContext
	   )
#endif /* Defined BAC */
{
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   *resDataPtr = Vsm_NvData.Vsm_opModeExtension;

   pMsgContext->resDataLen = (uint16)3;          /* add length of ext op-mode */
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmReadDataByIdentifierReadMemoryAddress               **
**                                                                            **
** DESCRIPTION   : read memory address for restart of transmission            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData.MemSegTable                              **
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
#define DIAG_DID_2506_RESPONSE_LENGTH   8u
#if (DIAG_DID_2506_RESPONSE_LENGTH >= DCM_BUFFER_SIZE)
   #error "bootdiag.c: The response length for service ReadDataByIdentifier ReadMemoryAddress is greater than DCM_BUFFER_SIZE"
#endif
#ifdef BAC
static FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierReadMemoryAddress
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmReadDataByIdentifierReadMemoryAddress
       (
          Dcm_MsgContextType* const pMsgContext
       )
#endif /* Defined BAC */
{
   flashAddress_t lastProgrammedAddress;

   /* Cache the pointer                                                       */
   Dcm_MsgType resDataPtr = &pMsgContext->resData[2];

   if ( (BootProgStatus.lastProgrammedSegment >=
                                      (uint8)FLASH_SEGMENT_NUMBER_BOOT)       &&
        (BootProgStatus.lastProgrammedSegment <
                                      (uint8)FLASH_SEGMENT_NUMBER_ALL )       &&
        (BootProgStatus.lastProgrammedSegment !=
                                      (uint8)REPROGRAMMINGNOTVALIDADDRESS)
      )
   {
      /* address of last programmed segment                                   */
      lastProgrammedAddress = sharedBootROMData.
                                 MemSegTable[BootProgStatus.
                                    lastProgrammedSegment][0];
   }
   else
   {
      /* not valid address                                                    */
      lastProgrammedAddress =(flashAddress_t)REPROGRAMMINGNOTVALIDADDRESS;
   }

   /*
    * erasing of current block is required
    */
   *resDataPtr++ = (uint8)DIAG_ADDR_CTRL_INFO_SEGMENT_BOUNDARY;

   /* length format identifier 1 byte                                         */
   *resDataPtr++ = (uint8)DIAG_LENGTH_FORMAT_IDENTIFIER;

#if (DIAG_LENGTH_FORMAT_IDENTIFIER != 0x40u)
   #error "bootdiag.c: invalid 'DIAG_LENGTH_FORMAT_IDENTIFIER'"
#endif

   /* address of last programmed block                                        */
   *resDataPtr++ = Dcm_GetHiHiByte(lastProgrammedAddress);
   *resDataPtr++ = Dcm_GetHiLoByte(lastProgrammedAddress);
   *resDataPtr++ = Dcm_GetLoHiByte(lastProgrammedAddress);
   *resDataPtr   = Dcm_GetLoLoByte(lastProgrammedAddress);

   /* send positive response                                                  */
   pMsgContext->resDataLen = (uint16)DIAG_DID_2506_RESPONSE_LENGTH;
} /* end of function 'ApplDcmReadDataByIdentifierReadMemoryAddress'           */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmWriteDataByIdentifierFingerprint                    **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData                                          **
**                 FingerprintInRam                                           **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmWriteDataByIdentifierFingerprint
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmWriteDataByIdentifierFingerprint
       (
          Dcm_MsgContextType* const pMsgContext
       )
#endif /* Defined BAC */
{
   uint8                         fingerprinttype;
   Dcm_NegativeResponseCodesType ResponseCode    = DCM_NRC_OK;
   /* Cache the request pointer                                               */
   Dcm_MsgType                   reqDataPtr;

   /** check preconditions and return if it isn't correct                    **/
   if ( (activeSubSession != PROG_BOOT_UNLOCKED)            &&
        (activeSubSession != PROG_BOOT_FINGERPRINT_WRITTEN) /* LowLevel retry */
      )
   {
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTSEQUENCEERROR);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* pre length check because of access to fingerprinttype                   */
   if ( pMsgContext->reqDataLen < (uint16)6 )
   {
      /* send neg. response because of wrong Fingerprint length               */
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   reqDataPtr = &pMsgContext->reqData[2];

   /* get type of fingerprint                                                 */
   fingerprinttype = reqDataPtr[DIAG_FINGERPRINT_FORMAT_POS] &
                                            (uint8)DIAG_FINGERPRINT_LENGTH_MASK;

   /** data length check and 'formal check' for normal and short fingerprint **/
   switch (fingerprinttype)
   {
      case DIAG_FINGERPRINT_LONG:
         if ( pMsgContext->reqDataLen != ((uint16)2 +
                                          (uint16)sizeof(FingerprintInRam)) )
         {
            /* send neg. response because of wrong Fingerprint length         */
            ResponseCode = DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
         }
         break;
      case DIAG_FINGERPRINT_SHORT:
         if ( pMsgContext->reqDataLen != ((uint16)2 +
                                          (uint16)FINGERPRINTLENGTH_SHORT) )
         {
            /* send neg. response because of wrong Fingerprint length         */
            ResponseCode = DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
         }
         break;
      default:
         /* send neg. response because of wrong 'fingerprinttype'             */
         ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
         break;
   }

   if ( ResponseCode != DCM_NRC_OK )
   {
      /* send neg. response because of wrong Fingerprint length or format     */
      Dcm_SetNegResponse(pMsgContext, ResponseCode);
      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /** preconditions are correct                                             **/

   if ( CheckFingerPrint(reqDataPtr) == TRUE )
   {
      /*
       * Store fingerprint temporary in RAM. It is written to EEPROM
       * before erasing flash
       */
      if ( fingerprinttype == (uint8)DIAG_FINGERPRINT_SHORT )
      {
         (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&FingerprintInRam[0],
                              (const void SC_FAR_POINTER)&reqDataPtr[0],
                              FINGERPRINTLENGTH_SHORT
                            );

         /* set fingerprint in RAM/EEPROM to long type                        */
         FingerprintInRam[DIAG_FINGERPRINT_FORMAT_POS] =
            (uint8)( (uint8)( FingerprintInRam[DIAG_FINGERPRINT_FORMAT_POS] &
                              (uint8)(~((uint8)DIAG_FINGERPRINT_LENGTH_MASK))
                            ) | (uint8)DIAG_FINGERPRINT_LONG
                   );

         /* FP_5503: short fingerprint is filled up with default values       */
         (void)SC_MEMCPY_ROM
            (
              (void SC_FAR_POINTER)&FingerprintInRam[FINGERPRINTLENGTH_SHORT],
              (const void SC_FAR_POINTER)&sharedBootROMData.
                                  FINGERPRINT_INIT_VAL[FINGERPRINTLENGTH_SHORT],
              (FINGERPRINTLENGTH - FINGERPRINTLENGTH_SHORT)
            );
      }
      else
      {
         (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&FingerprintInRam[0],
                              (const void SC_FAR_POINTER)&reqDataPtr[0],
                              sizeof(FingerprintInRam)
                            );
      }
      activeSubSession = PROG_BOOT_FINGERPRINT_WRITTEN;

      /* send positive response                                               */
      pMsgContext->resDataLen = (uint16)2;
   }
   else
   {
      /*
       * send neg. response because of wrong tester type, wrong programming
       * date
       */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
   }
} /* end of function 'ApplDcmWriteDataByIdentifierFingerprint'                */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmWriteDataByIdentifierVin                            **
**                                                                            **
** DESCRIPTION   : write VIN to EEPROM                                        **
**                                                                            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : BootProgData                                               **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmWriteDataByIdentifierVin
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmWriteDataByIdentifierVin
	   (
		  Dcm_MsgContextType* const pMsgContext
	   )
#endif /* Defined BAC */
{
   uint8_least iLoop;
   Dcm_MsgType reqDataPtr;                       /* Cache the request pointer */

   /** check preconditions                                                   **/

   /* check if programming dependencies was checked                           */
   if ( (activeSubSession != PROG_BOOT_PROGRAM_DEPEND_CHECKED) &&
        (activeSubSession != PROG_BOOT_PROGRAM_DEPEND_CHECK_FAILED)
      )
   {
      /* Programming dependencies wasn't checked or failed                    */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTSEQUENCEERROR);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* data length check                                                       */
   if ( pMsgContext->reqDataLen != ((uint16)2 + (uint16)sizeof(BootProgData.VIN)) )
   {
      /* send neg. response because of wrong VIN length                       */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* Cache the request pointer                                               */
   reqDataPtr = &pMsgContext->reqData[2];

   /* check values of VIN: only 'A' to 'Z' and '0' to '9' is valid            */
   iLoop = (uint8_least)0x00u;
   while ( ( ((reqDataPtr[iLoop] >= 'A') && (reqDataPtr[iLoop] <= 'Z')) ||
             ((reqDataPtr[iLoop] >= '0') && (reqDataPtr[iLoop] <= '9'))
           ) &&
           (iLoop < (uint8_least)sizeof(BootProgData.VIN))
         )
   {
      ++iLoop;
   }

   if ( iLoop < (uint8_least)sizeof(BootProgData.VIN) )
   {
      /* invalid digit found in VIN                                           */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
   }
   else
   {
      /** preconditions are correct                                          **/
      (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&BootProgData.VIN[0],
                           (const void SC_FAR_POINTER)&reqDataPtr[0],
                           sizeof(BootProgData.VIN)
                         );

      /* write data to nv memory                                              */
      if ( OperateNvData(NVM_DIAG_BOOTPROGDATA, NV_WRITE_OPERATION) != TRUE )
      {
         /* writing failed - set negative response                            */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_GENERALPROGRAMMINGFAILURE);
      }
      else
      
      {
         /* writing VIN successfully done: send positive response             */
         pMsgContext->resDataLen = (uint16)2;
      }
   }
} /* end of function 'ApplDcmWriteDataByIdentifierVin'                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlCheckMemory                           **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) - DIAG_RID_0202_CHECK_MEMORY         **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlCheckMemory
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmRoutineControlCheckMemory
	   (
		  Dcm_MsgContextType* const pMsgContext
       )
#endif /* Defined BAC */
{
                                            /* valid state of SWE             */
   SweValidStateType validStateOfSwe = SWE_VALID_STATE_INVALID;
                                            /* negative response code         */
   Dcm_NegativeResponseCodesType negativeResponseCode;
                                            /* requested SWE                  */
   uint8 sweId;

#if defined(DCM_BAC_VERSION)
   #if (DCM_BAC_VERSION == DCM_BAC3X)

   Dcm_SesCtrlType   ActiveSession;

   Dcm_GetSesCtrlType(&ActiveSession);

   /* if programming session not active        */
   if ( ActiveSession != (uint8)DCM_SES_LEV_PROGRAMMING )
   #endif
   #if (DCM_BAC_VERSION == DCM_BAC21)
   if ( Dcm_GetSesCtrlType() != (uint8)DCM_SES_LEV_PROGRAMMING )
   #endif
#else
   if ( Dcm_GetSesCtrlType() != (uint8)DCM_SES_LEV_PROGRAMMING )
#endif /* Defined DCM_BAC_VERSION */
   {
                                            /* set NRC ROOR                   */
      negativeResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }
                                  /* if authentication has not been done      */
   else if ( Dcm_GetSecurityLevel() != (uint8)DCM_SEC_LEV_PROGRAMMINGACCESS )
   {
                                            /* set NRC SAD                    */
      negativeResponseCode = DCM_NRC_SECURITYACCESSDENIED;
   }
                                  /* if not in correct state                  */
   else if ( ( activeSubSession != PROG_BOOT_DOWNLOAD_FINISHED   ) &&
             ( activeSubSession != PROG_BOOT_MEMORY_CHECKED      ) &&
             ( activeSubSession != PROG_BOOT_MEMORY_CHECK_FAILED ) )
   {
                                            /* set NRC RSE                    */
      negativeResponseCode = DCM_NRC_REQUESTSEQUENCEERROR;
   }
                                  /* if request message length is incorrect   */
   else if ( pMsgContext->reqDataLen < (uint16)5 )
   {
                                            /* set NRC IMLOIF                 */
      negativeResponseCode = DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }
                                  /* if request method is not 'indicated'     */
   else if ( pMsgContext->reqData[ 3 ] != (uint8)DIAG_CHECK_MEMORY_METHOD_INDICATED )
   {
                                            /* set NRC ROOR                   */
      negativeResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }
   else
                                  /* if the preconditions are correct         */
   {
                                            /* requested 'indicated' SweTable */
      flashAddress_t sweTable;
                                            /* cache the request pointer      */
      Dcm_MsgType pCheckMemoryRequestData = &pMsgContext->reqData[ 3 ];

                                            /* get address of SWE table in    */
                                            /* ROM from diagnostic request    */
      negativeResponseCode = GetAddressAndLengthByFormatIdentifier
                             (
                                &pCheckMemoryRequestData[ 1 ],
                                (uint8)( pMsgContext->reqDataLen - 5u - 2u ),
                                (uint8)DIAG_LENGTH_FORMAT_IDENTIFIER,
                                &sweTable,
                                &sweTable
                             );

                                  /* if the requested sweTable address exists */
      if ( negativeResponseCode == DCM_NRC_OK )
      {
                                            /* get number of requested SWE    */
         boolean addressOk = GetApplSWENumberByLogicalBlockNumber( &sweTable, &sweId );

                                  /* if no SWE was found                      */
                                  /* or if the request with method 'indicated'*/
                                  /* contains a length != 0 (FP_4459)         */
         if ( ( addressOk != TRUE ) ||
             ( pCheckMemoryRequestData[ 2u + DIAG_SIZEOF_OF_LENGTH_PARAM      ] != 0x00u    ) ||
             ( pCheckMemoryRequestData[ 2u + DIAG_SIZEOF_OF_LENGTH_PARAM + 1u ] != 0x00u    ) )
         {
                                            /* set NRC ROOR                   */
            negativeResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
         }
                                  /* if the requested SWE was found           */
         else
         {
                                  /* iterate all flash segments of SWE        */
            uint8_least flashSegmentId = (uint8_least)
               sharedBootROMData.SweSegmentIndexAppl[ sweId - SWE_ID_OF_APPL_SWE1 ];
            uint8_least flashSegmentIdOfNextSwe = flashSegmentId +
               sharedBootROMData.SweSegmentNumberAppl[ sweId - SWE_ID_OF_APPL_SWE1 ];
            do
            {
                                  /* if a flash segment was not written yet   */
               if ( GET_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootProgStatus.FlashSegmentStatus,
                                                     (uint8)flashSegmentId )
                    != (uint8)FLASH_SEGMENT_STATUS_NOT_WRITABLE )
               {
                                            /* set NRC ROOR                   */
                  negativeResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
               }
               ++flashSegmentId;
            } while ( ( negativeResponseCode == DCM_NRC_OK ) &&
                      ( flashSegmentId < flashSegmentIdOfNextSwe ) );
         }
      }
   }

                                  /* if the requested SWE was found and all   */
                                  /* flash segments have been programmed      */
   if ( negativeResponseCode == DCM_NRC_OK )
   {

                                            /* get valid state of SWE         */
      validStateOfSwe = Swe_GetValidStateOfSwe( sweId );

                                  /* if there are unhandled ECC/CRC errors or */
                                  /* valid flag area contains invalid data    */
      if ( validStateOfSwe == SWE_VALID_STATE_INVALID )
      {
                                            /* set NRC CNC                    */
         negativeResponseCode = DCM_NRC_CONDITIONSNOTCORRECT;
      }
                                  /* if SWE has not been signature checked yet*/
      else if ( validStateOfSwe == SWE_VALID_STATE_UNCHECKED )
      {
                                            /* set programming state to       */
                                            /* signature check started        */
         BootProgStatus.SWEProgrammingStatus[ sweId ] =
                                    (uint8)PROGSTAT_CHECKSIGNATURESTARTED;

                                  /* if writing of programming status to      */
                                  /* NV memory failed                         */
         if ( OperateNvData( NVM_DIAG_BOOTPROGSTATUS, NV_WRITE_OPERATION) != TRUE )
         {
                                            /* set NRC GPF                    */
            negativeResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;
         }
         else
         {
                                  /* if signature check was successful        */
#if (SC_BOOT_CRYPTO_ENABLE == STD_ON)
   #if defined (CRYPTO_AUTH_ASYM)
            if ( ApplDcmRoutineControlCheckMemoryAsym( sweId ) == TRUE )
   #elif defined (CRYPTO_AUTH_SYM)
            if ( ApplDcmRoutineControlCheckMemorySym( sweId ) == TRUE )
   #else
      #error "bootdiag.c: No crypto method defined. Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'"
   #endif
#endif
            {
                                            /* get offset needed for alignment*/
               uint8_least alignmentOffset = CalculateAlignOffset
                                             (
                                                (uint32)&pMsgContext->resData[ 3 ],
                                                FLASH_SRC_ADDR_ALIGN
                                             );

                                            /* set programming status to      */
                                            /* signature check ok             */
               BootProgStatus.SWEProgrammingStatus[ sweId ] =
                                         (uint8)PROGSTAT_CHECKSIGNATUREOK;


                                  /* if writing of valid flag to ROM or       */
                                  /* writing of programming status to         */
                                  /* NV memory failed                         */
               if ( ( WriteSweValidFlag( pMsgContext, sweId,
                                   &pMsgContext->resData[ 3u + alignmentOffset ] ) != TRUE ) ||
                    ( OperateNvData( NVM_DIAG_BOOTPROGSTATUS, NV_WRITE_OPERATION ) != TRUE ) )
               {
                                            /* set NRC GPF                    */
                  negativeResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;
               }
                                  /* if writing of valid flag to ROM and      */
                                  /* writing of programming status to         */
                                  /* NV memory was successful                 */
               else
               {
                  #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
                                            /* clear CRC error flag in RAM    */
                     Swe_ClearCrcErrorFlagOfSwe( sweId );
                  #endif
                                            /* proceed with valid SWE         */
                  validStateOfSwe = SWE_VALID_STATE_VALID_SWFL;
               }
            }
                                  /* if signature check failed                */
            else
            {
                                            /* set programming status to      */
                                            /* signature check not ok         */
               BootProgStatus.SWEProgrammingStatus[ sweId ] =
                                                 (uint8)PROGSTAT_CHECKSIGNATURENOK;

                                  /* if writing of programming status to      */
                                  /* NV memory failed                         */
               if ( OperateNvData( NVM_DIAG_BOOTPROGSTATUS, NV_WRITE_OPERATION ) != TRUE )
               {
                                            /* set NRC GPF                    */
                  negativeResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;
               }
                                  /* if writing of programming status to      */
                                  /* NV memory was successful                 */
               else
               {
                                            /* proceed with invalid SWE       */
                  validStateOfSwe = SWE_VALID_STATE_INVALID;
               }
            }
         }
      }
   }

                                  /* if no error occured                      */
   if ( negativeResponseCode == DCM_NRC_OK )
   {
      switch ( validStateOfSwe )
      {
                                  /* if SWE is valid after signature check    */
         case SWE_VALID_STATE_VALID_SWFL:
         case SWE_VALID_STATE_VALID_BTLD:
                                            /* set sub session status to      */
                                            /* memory checked                 */
            activeSubSession = PROG_BOOT_MEMORY_CHECKED;

                                            /* set positive response buffer   */
                                            /* to signature check successful  */
            pMsgContext->resData[ 3 ] = 0x00;

            break;

                                  /* if SWE is invalid after signature check  */
         case SWE_VALID_STATE_INVALID:
         default:
                                            /* set sub session status to      */
                                            /* memory check failed            */
            activeSubSession = PROG_BOOT_MEMORY_CHECK_FAILED;

                                            /* set positive response buffer   */
                                            /* to signature check failed      */
            pMsgContext->resData[ 3 ] = 0x01;
      }
                                            /* set positive response length   */
      pMsgContext->resDataLen = 4u;
   }
                                  /* if an error occured                      */
   else
   {
                                            /* set negative response code     */
      Dcm_SetNegResponse( pMsgContext, negativeResponseCode );
   }
} /* end of function 'ApplDcmRoutineControlCheckMemory'                       */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlCheckMemoryAsym                       **
**                                                                            **
** DESCRIPTION   : Contains the asymmetric signature check of the SWE with    **
**                 the given number                                           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : SweId: The number of the SWE (Bootloader and Application)  **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : TRUE : Signature check successfull                         **
**                 FALSE: Signature check failed                              **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (SC_BOOT_CRYPTO_ENABLE == STD_ON)
#if defined (CRYPTO_AUTH_ASYM)
#ifdef BAC
static FUNC(boolean, DCM_APPL_CODE) ApplDcmRoutineControlCheckMemoryAsym
	   (
		  CONST(uint8, DCM_APPL_CONST) SweId
	   )
#else
static boolean ApplDcmRoutineControlCheckMemoryAsym
	   (
		  const uint8 SweId
	   )
#endif /* Defined BAC */
{
   /*
    * Violation: MISRA Rule 45:
    * The member 'SweSignature' is 'uint32' and therefore has the correct
    * alignment
    */
   const CR_fpc_uint32 tmpSignaturePointer =
      (CR_fpc_uint32)(sharedBootROMData.PointerToSweTable[SweId]->SweSignature);

   const uint8 tmpSweSignaturIndexAppl =
      sharedBootROMData.SweSignaturIndexAppl[SweId - (uint8)SWE_ID_OF_APPL_SWE1];

   const uint8 tmpSweSignatureNumberAppl =
      sharedBootROMData.SweSignaturNumberAppl[SweId - (uint8)SWE_ID_OF_APPL_SWE1];

   const CR_C_RC_t cryptoResult = Crypto_CheckSigSW
      ( (uint32)tmpSweSignatureNumberAppl,
        (CR_fpcfpc_uint8)&sharedBootROMData.SignatureSweDataPtr[tmpSweSignaturIndexAppl],
        (CR_fpc_uint32)&sharedBootROMData.SignatureSweDataLength[tmpSweSignaturIndexAppl],
        (CR_fpc_uint32)tmpSignaturePointer,
        (uint16)0,
        (CR_fp_uint8)NULL_PTR
      );

   if ( cryptoResult == CR_C_RC_OK )
   {
      return TRUE;
   }
   else
   {
      return FALSE;
   }
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlCheckMemorySym                        **
**                                                                            **
** DESCRIPTION   : Contains the symmetric signature check of the SWE with     **
**                 the given number                                           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : SweId: The number of the SWE (Bootloader and Application)  **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : TRUE : Signature check successfull                         **
**                 FALSE: Signature check failed                              **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#elif defined (CRYPTO_AUTH_SYM)
#ifdef BAC
static FUNC(boolean, DCM_APPL_CODE) ApplDcmRoutineControlCheckMemorySym
	   (
		   CONST(uint8, DCM_APPL_CONST) SweId
	   )
#else
static boolean ApplDcmRoutineControlCheckMemorySym
			   (
			     const uint8 SweId
			   )
#endif /* Defined BAC */
{
   const CR_fpc_uint8 tmpSignaturePointer =
      (CR_fpc_uint8)(sharedBootROMData.PointerToSweTable[SweId]->SweSignature);

   const uint8 tmpSweSignaturIndexAppl =
      sharedBootROMData.SweSignaturIndexAppl[SweId - (uint8)SWE_ID_OF_APPL_SWE1];

   const uint8 tmpSweSignatureNumberAppl =
      sharedBootROMData.SweSignaturNumberAppl[SweId - (uint8)SWE_ID_OF_APPL_SWE1];

   const CR_C_RC_t cryptoResult = Crypto_CheckSigSwSymm
      ( (uint32)tmpSweSignatureNumberAppl,
        (CR_fpcfpc_uint8)&sharedBootROMData.SignatureSweDataPtr[tmpSweSignaturIndexAppl],
        (CR_fpc_uint32)&sharedBootROMData.SignatureSweDataLength[tmpSweSignaturIndexAppl],
        (CR_fpc_uint8)tmpSignaturePointer
      );

   if ( cryptoResult == CR_C_RC_OK )
   {
      return TRUE;
   }
   else
   {
      return FALSE;
   }
}
#endif /* CRYPTO_AUTH_SYM                                                     */
#endif /* SC_BOOT_CRYPTO_ENABLE == STD_ON                                         */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlReadSWEProgrammingStatus              **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_0204_READ_SWE_PROGRAMMING_STATUS                  **
**                 Reads the SWE programming status                           **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : BootProgStatus                                             **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlReadSWEProgrammingStatus
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmRoutineControlReadSWEProgrammingStatus
       (
          Dcm_MsgContextType* const pMsgContext
	   )
#endif /* Defined BAC */
{
   Dcm_NegativeResponseCodesType ResponseCode;
   uint8       SweId;                      /* the affected SWE                */
   boolean     addressOk;                  /* Contains result of address      */
                                           /* check                           */
   flashAddress_t logicalBlockNumber;      /* LBN sent in the request         */
   Dcm_MsgType reqDataPtr;                 /* Cache the request data pointer  */
   Dcm_MsgType resDataPtr;                 /* Cache the response data pointer */

   /*
    * Data length check:
    * 1 Byte SF + 2 Byte RID + 1 Byte reserved + 1 Byte ALFI
    */
   if( pMsgContext->reqDataLen < (uint16)5 )
   {
      /* send neg. response because of wrong request length                   */
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /** preconditions are correct                                             **/

   /* Cache the request and response data pointer                             */
   reqDataPtr = &pMsgContext->reqData[3];
   resDataPtr = &pMsgContext->resData[3];

   /* check reserved byte                                                     */
   if ( reqDataPtr[0] != (uint8)0x00u )
   {
      /* unknown message format                                               */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /*
    * Get the address and length of the request.
    * Data length check:
    * 1 Byte SF + 2 Byte RID + 1 Byte reserved + 1 Byte ALFI + <length>
    */
   ResponseCode = GetAddressAndLengthByFormatIdentifier
      ( &reqDataPtr[1],
        (uint8)(pMsgContext->reqDataLen - 5u),
        (uint8)DIAG_LENGTH_FORMAT_IDENTIFIER,
        &logicalBlockNumber,
        &logicalBlockNumber
      );

   if ( ResponseCode != DCM_NRC_OK )
   {
      /* set neg. response, return and send the response                      */
      Dcm_SetNegResponse(pMsgContext, ResponseCode);
      /* return is used here to decrease nesting depth                        */
      return;
   }

   /* check the LogicalBlockNumber of the SWE                                 */
   addressOk = GetApplSWENumberByLogicalBlockNumber( &logicalBlockNumber,
                                                     &SweId
                                                   );

   if ( addressOk == TRUE )
   {
      /* SWE programming status for the requested SWE                         */
      *resDataPtr = BootProgStatus.SWEProgrammingStatus[SweId];
   }
   else
   {
      *resDataPtr = PROGSTAT_SWENOTFOUND;
   }

   /*
    * AdressControlInfo: not used because service is implemented acccording to
    * LH FP v06
    */

    /* set length of response message                                         */
    pMsgContext->resDataLen = (uint16)4;
} /* end of function 'ApplDcmRoutineControlReadSWEProgrammingStatus'          */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlSetVsmOperationMode                   **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_0F0C_SET_VSM_OPERATION_MODE                       **
**                 Set the actual vehicle operation mode                      **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : Vsm_NvData                                                 **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlSetVsmOperationMode
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmRoutineControlSetVsmOperationMode
       (
          Dcm_MsgContextType* const pMsgContext
       )
#endif /* Defined BAC */
{
   /* request length check                                                    */
   if ( pMsgContext->reqDataLen == (uint16)4 )
   {
#ifdef BAC
      CONSTP2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) pVSMOperationMode = &pMsgContext->reqData[3];
#else
      const uint8 * const pVSMOperationMode = &pMsgContext->reqData[3];
#endif /* Defined BAC */

      /* check VSM operation mode parameter                                   */
      switch (*pVSMOperationMode)
      {
         case VSM_MM_MODE_BMW_FLASH:
         case VSM_MM_MODE_NORMAL:
         case VSM_MM_MODE_ASSEMBLY:
         case VSM_MM_MODE_TRANSPORT:
            /* check if the mode has changed                                  */
            if ( Vsm_NvData.Vsm_opMode != *pVSMOperationMode )
            {
               /* store new mode permanently in nvram                         */
               Vsm_NvData.Vsm_opMode = *pVSMOperationMode;
               /* reset op-mode extension and store it permanently in nvram   */
               Vsm_NvData.Vsm_opModeExtension = VSM_MM_MODE_EXTENSION_NORMAL;

               /* write to nv memory                                          */
#ifdef BAC
               if ( OperateNvData(NVM_BLOCK_VSM_DATA, NV_WRITE_OPERATION) != TRUE )
#else /* SC6 */
               if ( OperateNvData(NVM_VSM_NV_DATA, NV_WRITE_OPERATION) != TRUE )
#endif
               {
                  /* writing failed - set negative response                   */
                  Dcm_SetNegResponse ( pMsgContext,
                                       DCM_NRC_GENERALPROGRAMMINGFAILURE
                                     );
               }
            }
            /*
             * set response length in case of a positive response
             */
            pMsgContext->resDataLen = (uint16)3;
            break;
         default:
            /* VSM operation mode not supported                               */
            Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
            break;
      }
   }
   else
   {
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );
   }
} /* end of function 'ApplDcmRoutineControlSetVsmOperationMode'               */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlSetVsmOperationModeExtension          **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31) -                                    **
**                 DIAG_RID_1003_SET_VSM_OPERATION_MODE_EXTENSION             **
**                 Set the actual vehicle operation mode extension            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : Vsm_NvData                                                 **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlSetVsmOperationModeExtension
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmRoutineControlSetVsmOperationModeExtension
       (
         Dcm_MsgContextType* const pMsgContext
       )
#endif /* Defined BAC */
{
#ifdef BAC
   Dcm_NegativeResponseCodesType ResponseCode = DCM_NRC_OK;

   /* request length check                                                    */
   if ( pMsgContext->reqDataLen != (uint16)4 )
   {
      ResponseCode = DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }
   else
   {
      /* handling for the VSM operation modes                                 */
      switch (Vsm_NvData.Vsm_opMode)
      {
         case (uint8)VSM_MM_MODE_NORMAL:
            /* changing not allowed in NORMAL operation mode                  */
            ResponseCode = DCM_NRC_CONDITIONSNOTCORRECT;
            break;
         case (uint8)VSM_MM_MODE_ASSEMBLY:
            /* no break - further handling below */
         case (uint8)VSM_MM_MODE_TRANSPORT:
            if ( pMsgContext->reqData[3] > VSM_MM_MODE_EXTENSION_SAVE_ENERGY )
            {
               /* VSM extended operation mode not supported                   */
               ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
            }
            else
            {
               /* store new mode permanently in nvram                         */
               Vsm_NvData.Vsm_opModeExtension =
                                     (uint8)pMsgContext->reqData[3];
            }
            break;
         case (uint8)VSM_MM_MODE_BMW_FLASH:
            if ( pMsgContext->reqData[3] == VSM_MM_MODE_EXTENSION_FLASH_ENABLED )
            {
               /* store new mode permanently in nvram                         */
               Vsm_NvData.Vsm_opModeExtension =
                                     (uint8)VSM_MM_MODE_EXTENSION_FLASH_ENABLED;
            }
            else
            {
               /* VSM extended operation mode not supported                   */
               ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
            }
            break;
         default:
            /* VSM operation mode not supported                               */
            ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
            break;
      }

      if ( ResponseCode == DCM_NRC_OK )
      {
#ifdef BAC
         if ( OperateNvData(NVM_BLOCK_VSM_DATA, NV_WRITE_OPERATION) != TRUE )
#else /* SC6 */
         if ( OperateNvData(NVM_VSM_NV_DATA, NV_WRITE_OPERATION) != TRUE )
#endif
         {
            /* writing failed - set negative response                         */
            ResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;
         }
         else
         {
            /*
             * writing VSM extended operation mode successfully done:
             * send positive response
             */
            pMsgContext->resDataLen = (uint16)3;
         }
      }
   }

   if ( ResponseCode != DCM_NRC_OK )
   {
      /* set of new VSM extended operation mode not supported                 */
      Dcm_SetNegResponse ( pMsgContext, ResponseCode );
   }
#else
   /* request length check                                                    */
   if ( pMsgContext->reqDataLen == (uint16)4 )
   {
      if ( Vsm_NvData.Vsm_opMode == (uint8)VSM_MM_MODE_NORMAL )
      {
         /* changing not allowed in NORMAL operation mode                     */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_CONDITIONSNOTCORRECT);
      }
      else
      {
         /* check VSM extended operation mode parameter                       */
         switch (pMsgContext->reqData[3])
         {
            case VSM_MM_MODE_EXTENSION_FLASH_ENABLED:
               /* store new mode permanently in nvram                         */
               Vsm_NvData.Vsm_opModeExtension = pMsgContext->reqData[3];

               if ( OperateNvData(NVM_VSM_NV_DATA, NV_WRITE_OPERATION) != TRUE )
               {
                  /* writing failed - set negative response                   */
                  Dcm_SetNegResponse ( pMsgContext,
                                       DCM_NRC_GENERALPROGRAMMINGFAILURE
                                     );
               }
               else
               {
                  /*
                   * writing VSM extended operation mode successfully done:
                   * send positive response
                   */
                  pMsgContext->resDataLen = (uint16)3;
               }
               break;
            default:
               /* VSM operation mode not supported                            */
               Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
               break;
         }
      }
   }
   else
   {
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );
   }
#endif
} /* end of function 'ApplDcmRoutineControlSetVsmOperationModeExtension'      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlEraseMemory                           **
**                                                                            **
** DESCRIPTION   : ---                                                        **
**                                                                            **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : BootProgStatus                                             **
**                 BootProgCounter                                            **
**                 ReprogrammingParams                                        **
**                 FingerprintInRam                                           **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlEraseMemory
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmRoutineControlEraseMemory
	   (
		  Dcm_MsgContextType* const pMsgContext
	   )
#endif /* Defined BAC */
{
   Dcm_NegativeResponseCodesType ResponseCode;
                                                /* Contains result of address */
                                                /* check                      */
   uint8 *       pFlashDriverActivationCode;
   flashStatus_t lastFlashStatus;
   uint8_least   iLoop;                         /* temporary loop variable    */
   uint8         tempSWEProgStatus[SWENUMBEROFAPPLSWE];

   /* Cache the request pointer                                               */
   Dcm_MsgType reqDataPtr;

#if defined(DCM_BAC_VERSION)
   #if (DCM_BAC_VERSION == DCM_BAC3X)

   Dcm_SesCtrlType   ActiveSession;

   Dcm_GetSesCtrlType(&ActiveSession);

   /** check preconditions and return if it isn't correct                    **/
   if ( ActiveSession != (uint8)DCM_SES_LEV_PROGRAMMING )
   #endif
   #if (DCM_BAC_VERSION == DCM_BAC21)
   if ( Dcm_GetSesCtrlType() != (uint8)DCM_SES_LEV_PROGRAMMING )
   #endif
#else
   if ( Dcm_GetSesCtrlType() != (uint8)DCM_SES_LEV_PROGRAMMING )
#endif /* Defined DCM_BAC_VERSION */
   {
      /* ProgrammingSession not active                                        */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   if ( Dcm_GetSecurityLevel() != (uint8)DCM_SEC_LEV_PROGRAMMINGACCESS )
   {
      /* ProgrammingSession is locked                                         */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_SECURITYACCESSDENIED);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* check request sequence                                                  */
   if ( (activeSubSession != PROG_BOOT_FINGERPRINT_WRITTEN) &&
        (activeSubSession != PROG_BOOT_MEMORY_ERASED)       &&
        (activeSubSession != PROG_BOOT_MEMORY_ERASE_FAILED) &&
        (activeSubSession != PROG_BOOT_MEMORY_CHECKED)
      )
   {
      /* request sequence error                                               */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTSEQUENCEERROR);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /*
    * Data length check:
    * 1 Byte SF + 2 Byte RID + 1 Byte ErasingMethode + 1 Byte ALFI
    */
   if ( pMsgContext->reqDataLen < (uint16)5 )
   {
      /* send neg. response because of wrong request length                   */
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /** preconditions are correct                                             **/

   /* mark every memory segment of the application as "do not erase"          */
   (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&MemSegToErase[0],
                        (uint8)FLASH_SEG_DONT_ERASE,
                        sizeof(MemSegToErase)
                      );

   /* clear temp status buffer                                                */
   (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&tempSWEProgStatus[0],
                        0x00u,
                        sizeof(tempSWEProgStatus)
                      );

   reqDataPtr = &pMsgContext->reqData[3];

   /* check erasing method                                                    */
   switch (reqDataPtr[0])
   {
      case DIAG_FLASH_ERASE_METHOD_ADDRESSED:
         ResponseCode = FlashEraseInitEraseMethodAddressed
                        (
                          pMsgContext->reqDataLen,
                          &reqDataPtr[1],
                          &tempSWEProgStatus[0]
                        );
         pFlashDriverActivationCode =
                      &reqDataPtr[2 + DIAG_SIZEOF_OF_ADDRESS_AND_LENGTH_PARAMS];
         break;
      case DIAG_FLASH_ERASE_METHOD_INDICATED:
         ResponseCode = FlashEraseInitEraseMethodIndicated
                        (
                          pMsgContext->reqDataLen,
                          &reqDataPtr[1],
                          &tempSWEProgStatus[0]
                        );
         pFlashDriverActivationCode =
                      &reqDataPtr[2 + DIAG_SIZEOF_OF_LENGTH_PARAM];
         break;
      default:
         /* RequestOutOfRange will be send in negative response               */
         ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
         /* set this variable for MISRA                                       */
         pFlashDriverActivationCode = NULL_PTR;
         break;
   }

   if ( (ResponseCode == DCM_NRC_OK)             &&
        (pFlashDriverActivationCode != NULL_PTR) &&              /* for MISRA */
		(*pFlashDriverActivationCode != (uint8) FLASH_DRIVER_VALID_ACTIVATION_CODE)
      )
   {
      /*
       * Invalid flash driver activation code
       */
      ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }

   if ( ResponseCode == DCM_NRC_OK )
   {

      if ( Swe_GetProgDepStateOfApplSwes() == SWE_PROGDEP_STATE_CONSISTENT_APPL )
      {
         /*
          * When a BLU is in SWE1, the ProgrammingCounter will not be
          * checked.
          * When the ProgrammingDependencies are incorrect, the
          * ProgrammingCounter will not be checked.
          *
          * Check programming counter if TesterType doesn't equal development
          */
         if ( ( ( FingerprintInRam[DIAG_FINGERPRINT_FORMAT_POS] &
                  (uint8)DIAG_FINGERPRINT_TESTER_SERVICE_ID_MASK
                ) != (uint8)TESTERTYPDEVELOPMENT
              )
              &&
              ( ProgrammingCounterLimitExceeded() != FALSE )
            )
         {
            /*
             * Max. number of reprogramming attempts exceeded:
             * Set neg. response, return and send the response
             */
            Dcm_SetNegResponse(pMsgContext, DCM_NRC_CONDITIONSNOTCORRECT);

            /* return is used here to decrease nesting depth                  */
            return;
         }
      }

      /*
       * Update ProgrammingStatus and ProgrammingCounter
       * Avoid accessing the SWE by setting the CRC error flag
       */
      for ( iLoop = (uint8_least)0;
            iLoop < (uint8_least)SWENUMBEROFAPPLSWE;
            iLoop++
          )
      {
         if ( tempSWEProgStatus[iLoop] == (uint8)PROGSTAT_ERASEMEMORYSTARTED )
         {
            /* set ProgrammingStatus of SWE to 'PROGSTAT_ERASEMEMORYSTARTED'  */
            BootProgStatus.
               SWEProgrammingStatus[iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1] =
                  (uint8)PROGSTAT_ERASEMEMORYSTARTED;

            /*
             * Increase ProgrammingCounter:
             * Overruns are not allowed
             */
            if ( BootProgCounter.
                    ProgrammingCounter[iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1]
                       != (uint16)0xFFFFu
               )
            {
               ++BootProgCounter.
                  ProgrammingCounter[iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1];
            }

            /* Avoid accessing the SWE by setting the CRC error flag          */
            #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
               Swe_SetCrcErrorFlagOfSwe( iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1 );
            #endif
         }
      }

      /*
       * Write the changed SWEProgrammingStatus and the ProgrammingCounter to NV
       * memory.
       * The ProgrammingCounter is always written, even if it's not changed
       * because of a potential overrun of the counter
       */
      if ( ( OperateNvData( NVM_DIAG_BOOTPROGSTATUS,
                            NV_WRITE_OPERATION)  != TRUE
           )
           ||
           ( OperateNvData( NVM_DIAG_BOOTPROGCOUNTER,
                            NV_WRITE_OPERATION)  != TRUE
           )
         )
      {
         /* Set negative response                                             */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_GENERALPROGRAMMINGFAILURE);
         /* return is used here to decrease nesting depth                     */
         return;
      }

      /*
       * If this is the first 'FlashErase' in the sequence of the programming
       * session write first startup indication and the fingerprint from RAM
       * mirror to EEPROM
       */
      if ( activeSubSession == PROG_BOOT_FINGERPRINT_WRITTEN )
      {
         /*
          * Set flag to indicate the first start of an new programmed
          * application and write fingerprint from RAM to EEPROM
          */
         if ( WriteFingerprintAndApplStartedFirstFlag() != TRUE )
         {
            /* set neg. response, return and send the response                */
            Dcm_SetNegResponse(pMsgContext, DCM_NRC_GENERALPROGRAMMINGFAILURE);
            /* return is used here to decrease nesting depth                  */
            return;
         }

         /*
          * Init the flash driver using the current activation code as the flash
          * driver decryption key
          */
         if ( (pFlashDriverActivationCode == NULL_PTR) ||        /* for MISRA */
              (FlashInit((flashKey_t)*pFlashDriverActivationCode) !=
                                                        (flashStatus_t)FLASH_OK)
            )
         {
            /*
             * The flash driver has not been initialized:
             * During development this can happen when the driver is not linked
             * properly.
             * Under normal circumstances this means that the wrong
             * FlashDriverActivationCode was sent.
             */
            Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
            /* return is used here to decrease nesting depth                  */
            return;
         }
      }

      /* -------------------------------------------------------------------- */
      /* flash erase requested                                                */
      /* -------------------------------------------------------------------- */

      /*
       * FP_5462: Erase in two steps:
       * 1.) Flash segments containing the valid flags and SWE tables
       * 2.) The remaining flash segments that need to be erased
       */
      lastFlashStatus = FlashEraseFlash(pMsgContext, FLASH_SEG_ERASE_HIGH_PRIO);

      if ( (lastFlashStatus == (flashStatus_t)FLASH_OK) &&
           (FlashEraseFlash(pMsgContext, FLASH_SEG_ERASE_LOW_PRIO) ==
                                                        (flashStatus_t)FLASH_OK)
         )
      {
         /*
          * Clear ECC error flag and update ProgrammingStatus
          */
         for ( iLoop = (uint8_least)0;
               iLoop < (uint8_least)SWENUMBEROFAPPLSWE;
               iLoop++
             )
         {
            if ( tempSWEProgStatus[iLoop] == (uint8)PROGSTAT_ERASEMEMORYSTARTED )
            {
               #if ( SC_HANDLE_ECC == STD_ON )
                  /* Clear ECC error flag in RAM                              */
                  Swe_ClearEccErrorFlagOfSwe( iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1 );
               #endif

               /*
                * set ProgrammingStatus of the erased SWEs to
                * 'PROGSTAT_MEMORYSUCCESSFULLYERASED'
                */
               BootProgStatus.
                  SWEProgrammingStatus[iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1] =
                     (uint8)PROGSTAT_MEMORYSUCCESSFULLYERASED;
            }
         }

         /*
          * Update FlashSegmentStatus
          */
         for ( iLoop = (uint8_least)0;
               iLoop < (uint8_least)FLASH_SEGMENT_NUMBER_APPL;
               iLoop++
             )
         {
            const uint8 * const pMemSegToErase = &MemSegToErase[iLoop];

            if ( (*pMemSegToErase == (uint8)FLASH_SEG_ERASE_HIGH_PRIO) ||
                 (*pMemSegToErase == (uint8)FLASH_SEG_ERASE_LOW_PRIO)
               )
            {
               /*
                * set FlashSegmentStatus of the erased flash segments to
                * 'WRITABLE'
                */
               SET_BIT_IN_MULTI_BYTE_BIT_ARRAY
                                     (BootProgStatus.FlashSegmentStatus, iLoop);
            }
         }

         /* write the changed BootProgStatus to NV memory                     */
         if ( OperateNvData( NVM_DIAG_BOOTPROGSTATUS,
                             NV_WRITE_OPERATION) != TRUE
            )
         {
            /* Set negative response                                          */
            Dcm_SetNegResponse(pMsgContext, DCM_NRC_GENERALPROGRAMMINGFAILURE);
         }
         else
         {
            /* correct result                                                 */
            pMsgContext->resData[3] = (uint8)0x00u;

            /* store new programming status                                   */
            activeSubSession = PROG_BOOT_MEMORY_ERASED;
         }
      }
      else
      {
         /* incorrect result                                                  */
         pMsgContext->resData[3] = (uint8)0x01u;

         /* store new programming status                                      */
         activeSubSession = PROG_BOOT_MEMORY_ERASE_FAILED;
      }

      /* set length of response                                               */
      pMsgContext->resDataLen = (uint16)4;
   }
   else
   {
      /* start address not supported - set negative response                  */
      Dcm_SetNegResponse(pMsgContext, ResponseCode);
   }

   return;
} /* end of function 'ApplDcmRoutineControlEraseMemory'                       */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmRoutineControlCheckProgrammingDependencies          **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31)                                      **
**                 DIAG_RID_FF01_CHECK_REPROGRAMMING_DEPENDENCIES             **
**                 Checks programming dependencies.                           **
**                 There are following response values possible:              **
**                 CorrectResults                           0x00              **
**                 IncorrectResults                         0x01              **
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
static FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlCheckProgrammingDependencies
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static void ApplDcmRoutineControlCheckProgrammingDependencies
       (
          Dcm_MsgContextType* const pMsgContext
       )
#endif /* Defined BAC */
{
                                            /* prog dep state of appl SWEs    */
   SweProgDepStateType progDepStateOfApplSwes = SWE_PROGDEP_STATE_INVALID;

                                            /* negative response code         */
   Dcm_NegativeResponseCodesType negativeResponseCode = DCM_NRC_OK;


#if defined(DCM_BAC_VERSION)
   #if (DCM_BAC_VERSION == DCM_BAC3X)

   Dcm_SesCtrlType   ActiveSession;

   Dcm_GetSesCtrlType(&ActiveSession);

                                  /* if programming session not active        */
   if ( ActiveSession != (uint8)DCM_SES_LEV_PROGRAMMING )
   #endif
   #if (DCM_BAC_VERSION == DCM_BAC21)
   if ( Dcm_GetSesCtrlType() != (uint8)DCM_SES_LEV_PROGRAMMING )
   #endif
#else
   if ( Dcm_GetSesCtrlType() != (uint8)DCM_SES_LEV_PROGRAMMING )
#endif /* Defined DCM_BAC_VERSION */
   {
                                            /* set NRC ROOR                   */
      negativeResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }
                                  /* if authentication has not been done      */
   else if ( Dcm_GetSecurityLevel() != (uint8)DCM_SEC_LEV_PROGRAMMINGACCESS )
   {
                                            /* set NRC SAD                    */
      negativeResponseCode = DCM_NRC_SECURITYACCESSDENIED;
   }
                                  /* if not in correct state                  */
   else if ( ( activeSubSession != PROG_BOOT_MEMORY_CHECKED              ) &&
             ( activeSubSession != PROG_BOOT_MEMORY_CHECK_FAILED         ) &&
             ( activeSubSession != PROG_BOOT_PROGRAM_DEPEND_CHECKED      ) &&
             ( activeSubSession != PROG_BOOT_PROGRAM_DEPEND_CHECK_FAILED ) )
   {
                                            /* set NRC RSE                    */
      negativeResponseCode = DCM_NRC_REQUESTSEQUENCEERROR;
   }
                                  /* if request message length is incorrect   */
   else if ( pMsgContext->reqDataLen != (uint16)3 )
   {
                                            /* set NRC IMLOIF                 */
      negativeResponseCode = DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }
   else
                                  /* if preconditions are correct             */
   {
                                            /* get prog dep state of appl SWEs*/
      progDepStateOfApplSwes = Swe_GetProgDepStateOfApplSwes();

                                  /* if prog deps haven't been checked before */
      if ( progDepStateOfApplSwes == SWE_PROGDEP_STATE_UNCHECKED_APPL )
      {
         uint8_least             alignmentOffset;
         WriteProgDepRetValType  writeDepCheckResult;

                                            /* check prog deps                */
         progDepStateOfApplSwes = UserCallback_ProgrammingDependenciesCheck();

                                            /* get offset needed for alignment*/
         alignmentOffset = CalculateAlignOffset( (uint32)&pMsgContext->resData[3],
                                                 FLASH_SRC_ADDR_ALIGN
                                               );

                                            /* write prog deps to flash       */
         writeDepCheckResult = WriteProgrammingDependencies( pMsgContext,
                                                             progDepStateOfApplSwes,
                                     &pMsgContext -> resData[ 3u + alignmentOffset ]
                                                           );

         switch ( writeDepCheckResult )
         {
                                  /* if writing to flash was successful       */
            case PROG_DEP_WRITTEN:
                                            /* if application is consistent   */
               if ( progDepStateOfApplSwes == SWE_PROGDEP_STATE_CONSISTENT_APPL )
               {
                                            /* backup SVK to prepare          */
                                            /* for start of application       */
                  if ( WriteSvkHistoryMemory() == FALSE )
                  {
                     negativeResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;
                  }
               }

               break;

                                  /* if writing to flash failed            */
            case PROG_DEP_ERROR_WRITING:
                                            /* set NRC GPF                 */
               negativeResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;

               break;

                                  /* if any other error occured            */
            default:
                                            /* set NRC CNC                 */
               negativeResponseCode = DCM_NRC_CONDITIONSNOTCORRECT;

               break;
         }
      }
   }

                                  /* if no error occured                      */
   if ( negativeResponseCode == DCM_NRC_OK )
   {
      switch ( progDepStateOfApplSwes )
      {
                                  /* if valid BLU was found                   */
         case SWE_PROGDEP_STATE_VALID_BLU:
                                            /* backup old NV memory to        */
                                            /* prepare for start of BLU       */
            Blu_BackupNvData(pMsgContext);

                                            /* set correct state for response */
            progDepStateOfApplSwes = SWE_PROGDEP_STATE_CONSISTENT_APPL;

            /* NO break */                  /* do not break => continue       */

                                  /* if application SWEs are consistent       */
         case SWE_PROGDEP_STATE_CONSISTENT_APPL:
                                            /* deinitialize the flash driver. */
                                            /* it is not needed anymore       */
            (void)FlashDeInit();

                                            /* set sub session status to      */
                                            /* prog dep checked               */
            activeSubSession = PROG_BOOT_PROGRAM_DEPEND_CHECKED;

            break;

                                  /* in no consistent application was found   */
         default:
                                            /* set sub session status to      */
                                            /* prog dep failed                */
            activeSubSession = PROG_BOOT_PROGRAM_DEPEND_CHECK_FAILED;
      }

                                            /* fill positive response buffer  */
                                            /* with prog dep state            */
      pMsgContext->resData[3] = (uint8)progDepStateOfApplSwes;

                                            /* set positive response length   */
      pMsgContext->resDataLen = (uint16)4;
   }
                                  /* if an error occured                      */
   else
   {
                                            /* set negative response code     */
      Dcm_SetNegResponse( pMsgContext, negativeResponseCode );
   }
} /* end of function 'ApplDcmRoutineControlCheckProgrammingDependencies'      */


#if (SC_NONCOMPRESSED_ENABLE == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmTransferDataNotCompressedNotEncrypted               **
**                                                                            **
** DESCRIPTION   : Handles the writing of not compressed and not encrypted    **
**                 data                                                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : reqDataPtr   : req data pointer at payload position        **
**                 payLoadLength: length of the data in req data pointer      **
**                 pMsgContext  : DCM message context                         **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : According to 'Dcm_NegativeResponseCodesType' definition    **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) ApplDcmTransferDataNotCompressedNotEncrypted
	   (
		  CONST(Dcm_MsgType, DCM_APPL_CONST)                       reqDataPtr,
		  CONST(uint16, DCM_APPL_CONST)                            payLoadLength,
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static Dcm_NegativeResponseCodesType ApplDcmTransferDataNotCompressedNotEncrypted
       (
          const Dcm_MsgType                reqDataPtr,
          const uint16                     payLoadLength,
          Dcm_MsgContextType * const pMsgContext
       )
#endif /* Defined BAC */
{
   Dcm_NegativeResponseCodesType ResponseCode;

   /* Check for valid payload length                                          */
   if ( (payLoadLength % (uint16)FLASH_PAGE_SIZE) != (uint16)0x00u )
   {
      ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }
   else
   {
      /* Calc address of the last byte to be programmed                       */
      const flashAddress_t tmpEndAddress = ReprogrammingParams.memStartAddress +
                                           (flashAddress_t)payLoadLength       -
                                           (flashAddress_t)1u;

      /* Check if payload fits into the RequestDownload memory area           */
      if ( tmpEndAddress > ReprogrammingParams.memEndAddress )
      {
         /*
          * The downloaded data block doesn't fit within the requested memory
          * area
          */
         ResponseCode = DCM_NRC_TRANSFERDATASUSPENDED;
      }
      else
      {
         /*
          * There is enough space within the requested memory area to
          * programm the downloaded data block.
          */

         /* Check if data are aligend to flash driver access boundaries       */
         const uint8_least AlignOffset = CalculateAlignOffset
                                            ( (uint32)&reqDataPtr[0],
                                              FLASH_SRC_ADDR_ALIGN
                                            );

         if ( AlignOffset != (uint8_least)0x00u )
         {
            /* move data to a aligned address in the diag buffer              */
            (void)SC_MEMMOVE( (void SC_FAR_POINTER)&reqDataPtr[AlignOffset],
                              (const void SC_FAR_POINTER)&reqDataPtr[0],
                              payLoadLength
                            );
         }

         ResponseCode = FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat
                           ( (void SC_FAR_POINTER) &reqDataPtr[AlignOffset],
                             &ReprogrammingParams.memStartAddress,
                             payLoadLength,
                             pMsgContext
                           );                   /* programming flash memory   */

         if ( ResponseCode == DCM_NRC_OK )
         {
            ReprogrammingParams.memStartAddress += (flashAddress_t)payLoadLength;
                                             /* Calculate the target address  */
                                             /* of the next data block        */
         }
      }
   }

   return ResponseCode;
} /* end of function 'ApplDcmTransferDataNotCompressedNotEncrypted'           */
#endif /* SC_NONCOMPRESSED_ENABLE == STD_ON                                       */


#if (SC_NRV2B_ENABLE == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ApplDcmTransferDataNrvCompressedNotEncrypted               **
**                                                                            **
** DESCRIPTION   : Handles the writing of NRV compressed and not encrypted    **
**                 data                                                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : nrv2bCtrl                                                  **
**                                                                            **
** PARAMETER     : reqDataPtr   : req data pointer at payload position        **
**                 payLoadLength: length of the data in req data pointer      **
**                 pMsgContext  : DCM message context                         **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : According to 'Dcm_NegativeResponseCodesType' definition    **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) ApplDcmTransferDataNrvCompressedNotEncrypted
	   (
		  CONST(Dcm_MsgType, DCM_APPL_CONST)                       reqDataPtr,
		  CONST(uint16, DCM_APPL_CODE)                             payLoadLength,
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static Dcm_NegativeResponseCodesType ApplDcmTransferDataNrvCompressedNotEncrypted
                                     (
                                        const Dcm_MsgType                reqDataPtr,
                                        const uint16                     payLoadLength,
                                              Dcm_MsgContextType * const pMsgContext
                                     )
#endif /* Defined BAC */
{
   sint8                         retVal;
   flashAddress_t                tmpEndAddress;
   Dcm_NegativeResponseCodesType ResponseCode = DCM_NRC_OK;
   Dcm_TimerP2xSettingType       limitP2;       /* P2 timings from DCM module */

   FreeTimer_StartTimeMeasurement();    /* set the global initialization time */

   Boot_EnterCriticalRegion();
   responsePendingSupervision.pCurrentMsgContext = pMsgContext;
   /*
    * check whether a response pending was already sent or not and initialise
    * the current timeout to P2 or P2*:
    * get P2 timings from DCM module
    */
   Dcm_GetCurrentSessionTimings(&limitP2.timeOutP2, &limitP2.timeOutP2Ex);
   if ( Dcm_GetResponsePendingFinished(pMsgContext) == DCM_RP_TYPE_IDLE )
   {
      responsePendingSupervision.currentTimeOut = FreeTimer_ConvertMs2Ticks
                              ( (limitP2.timeOutP2 - (DCM_TIMEOUT_P2_ADJUST)) );
   }
   else
   {
      responsePendingSupervision.currentTimeOut = FreeTimer_ConvertMs2Ticks
                                   ( ADJUST_TIMEOUT_P2EX(limitP2.timeOutP2Ex) );
   }
   responsePendingSupervision.elapsedTime =
                                       (FreeTimer_TimeInTicksType)TIMER_RESTART;
   Boot_LeaveCriticalRegion();

   /*
    * The source buffer will be reinitialized at every
    * 'TransferData', because it cannot be guaranteed that buffer
    * and lenght do not change during the different Requests.
    */
   nrv2bStream_ProvideNewSourceBuffer
      (
         (P2CONST(uint8, AUTOMATIC, NRV2BS_APPL_DATA))&reqDataPtr[0],
         (VAR(uint16, AUTOMATIC))                     payLoadLength
      );

   do
   {
      uint16 tempBufferIndex;

      retVal = nrv2bStream_Decompress();

      switch (retVal)
      {
         case NRVSTREAM_FINISHED:
            /*
             * Decompression has finished:
             * Program remaining data and send positive Response
             */
            tempBufferIndex = nrv2bStream_GetTempBufferIndex();

            /* Calc address of the last byte to be programmed                 */
            tmpEndAddress = ReprogrammingParams.memStartAddress +
                            (flashAddress_t)tempBufferIndex     -
                            (flashAddress_t)1u;
            /*
             * Check if payload fits into the RequestDownload memory
             * area
             */
            if ( tmpEndAddress == ReprogrammingParams.memEndAddress )
            {
               if ( tempBufferIndex == (uint16)0x00u )
               {
                  /* ResponseCode = DCM_NRC_OK; */
               }
               else
               {
                  /* Check for valid payload length                           */
                  if ( (tempBufferIndex % (uint16)FLASH_PAGE_SIZE) ==
                                                                 (uint16)0x00u )
                  {
                     ResponseCode =
                        FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat
                                       (  &nrv2bCtrl.nrv2bTempBufferPtr[0],
                                          &ReprogrammingParams.memStartAddress,
                                          tempBufferIndex,
                                          pMsgContext
                                       );    /* programming flash memory      */

                     if ( ResponseCode == DCM_NRC_OK )
                     {
                        ReprogrammingParams.memStartAddress +=
                                                (flashAddress_t)tempBufferIndex;
                                             /* Calculate the target address  */
                                             /* of the next data block        */
                     }
                  }
                  else
                  {
                     /* invalid payload length                                */
                     ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
                  }
               }
            }
            else
            {
               if ( tmpEndAddress > ReprogrammingParams.memEndAddress )
               {
                  /*
                   * The downloaded data block doesn't fit within the
                   * requested memory area
                   */
                  ResponseCode = DCM_NRC_TRANSFERDATASUSPENDED;
               }
               else /* tmpEndAddress < memEndAddress                    */
               {
                  /*
                   * FINISHED was reached, before the amount of data that
                   * was communicated in 'RequestDownload' was achieved
                   */
                  ResponseCode = DCM_NRC_CONDITIONSNOTCORRECT;
               }
            }
            break;
         case NRVSTREAM_SOURCE_BUFFER_EMPTY:
            /*
             * source buffer empty (-> refill buffer):
             * send positive Response
             */
            break;
         case NRVSTREAM_TEMP_BUFFER_FULL:
            /*
             * temporary buffer full (-> consume current or provide new
             * buffer):
             * program data and decompress the next block
             *
             * Check if it fits into the RequestDownload memory area:
             * Calc address of the last byte to be programmed
             */
            tmpEndAddress = ReprogrammingParams.memStartAddress +
                            (flashAddress_t)NRV2B_TEMP_BUFFER_SIZE-
                            (flashAddress_t)1u;

            if ( tmpEndAddress <= ReprogrammingParams.memEndAddress )
            {
               ResponseCode = FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat
                  ( &nrv2bCtrl.nrv2bTempBufferPtr[0],
                    &ReprogrammingParams.memStartAddress,
                    (uint16)NRV2B_TEMP_BUFFER_SIZE,
                    pMsgContext
                  );                         /* programming flash memory      */

               /* Signalize, the temporary buffer may be reused               */
               nrv2bStream_ReuseTempBuffer();

               if ( ResponseCode == DCM_NRC_OK )
               {
                  ReprogrammingParams.memStartAddress +=
                                         (flashAddress_t)NRV2B_TEMP_BUFFER_SIZE;
                                             /* Calculate the target address  */
                                             /* of the next data block        */
               }
            }
            else
            {
                                    /* The downloaded data block doesn't fit  */
                                    /* within the requested memory area.      */
               ResponseCode = DCM_NRC_TRANSFERDATASUSPENDED;
            }
            break;
         case NRVSTREAM_FATAL_ERROR:
         default:
            /*
             * fatal error, decompression failed:
             * send negative Response
             */
            ResponseCode = DCM_NRC_CONDITIONSNOTCORRECT;
            break;
      }
   } while ( (retVal == (sint8)NRVSTREAM_TEMP_BUFFER_FULL) &&
             (ResponseCode == DCM_NRC_OK)
           );

   /* stop manual response pendig supervision                                 */
   Boot_EnterCriticalRegion();
   responsePendingSupervision.pCurrentMsgContext = NULL_PTR;
   responsePendingSupervision.currentTimeOut     =
                                      (FreeTimer_TimeInTicksType)0x00000000uL;
   responsePendingSupervision.elapsedTime        =
                                      (FreeTimer_TimeInTicksType)TIMER_INACTIVE;
   Boot_LeaveCriticalRegion();

   return ResponseCode;
} /* end of function 'ApplDcmTransferDataNrvCompressedNotEncrypted'           */
#endif /* SC_NRV2B_ENABLE == STD_ON                                               */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : FlashEraseInitEraseMethodAddressed                         **
**                                                                            **
** DESCRIPTION   : get and check addresses for addressed erasing method       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ReprogrammingParams                                        **
**                 sharedBootROMData                                          **
**                 BootProgStatus                                             **
**                                                                            **
** PARAMETER     : reqDataLen        : the length of the diagnostic message   **
**                 reqDataPtr        : req data pointer at AALFID position    **
**                 ptempSWEProgStatus: temporary SWE programming status       **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : TRUE : valid address found                                 **
**                 FALSE: no valid address found                              **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) FlashEraseInitEraseMethodAddressed
	   (
		  CONST(Dcm_MsgLenType, DCM_APPL_CONST)       reqDataLen,
		  CONST(Dcm_MsgType, DCM_APPL_CONST)          reqDataPtr,
		  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ptempSWEProgStatus
	   )
#else
static Dcm_NegativeResponseCodesType FlashEraseInitEraseMethodAddressed
	   (
		  const Dcm_MsgLenType       reqDataLen,
		  const Dcm_MsgType          reqDataPtr,
		        uint8*         const ptempSWEProgStatus
       )
#endif /* Defined BAC */
{
   Dcm_NegativeResponseCodesType ResponseCode;
                                             /* Contains result of address    */
                                             /* check                         */
   uint8 FlashSegmentNumber;
   uint8 ApplSWENumber;

   flashAddress_t startAddress;              /* StartAddress sent in the      */
                                             /* request                       */
   flashAddress_t endAddress;                /* EndAddress calculated from    */
                                             /* the length sent in the        */
                                             /* request                       */

   boolean        addressOk;                 /* Contains result of address    */
                                             /* check                         */

   /*
    * Get the address and length of the request.
    * Data length check:
    * 1 Byte SF + 2 Byte RID + 1 Byte ErasingMethode + 1 Byte ALFI + <address> +
    * <length> + 1 Byte activationCode
    */
   ResponseCode = GetAddressAndLengthByFormatIdentifier
      ( &reqDataPtr[0],
        (uint8)(reqDataLen - 5u - 1u),
        (uint8)DIAG_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER,
        &startAddress,
        &endAddress
      );

   if ( ResponseCode != DCM_NRC_OK )
   {
      /*
       * Return is used here to decrease nesting depth.
       * 'ResponseCode' will be send in negative response
       */
      return ResponseCode;
   }

   endAddress += startAddress - (flashAddress_t)1u;
                                         /* Calculate end address of          */
                                         /* requested memory block            */

   ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   do
   {
      GetFlashSegmentNumberType GetFlashSegmentNumberRetVal =
         GetFlashSegmentNumberByMemAddress (
                                              &startAddress,
                                              &FlashSegmentNumber
                                           );

      if ( GetFlashSegmentNumberRetVal == ADDRESS_FOUND_FLASH_SEGMENT_BORDER )
      {
         addressOk = GetApplSWENumberByFlashSegmentNumber ( &FlashSegmentNumber,
                                                            &ApplSWENumber
                                                          );
         if ( addressOk == TRUE )
         {
            CONSTP2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                         pMemEndAddress =
                         &sharedBootROMData.MemSegTable[FlashSegmentNumber][1];

            FlashSegmentNumber -= (uint8)FLASH_SEGMENT_NUMBER_BOOT;

            /*
             * mark this memory segment for erasing in 'FlashEraseFlash'
             * function
             */
            MemSegToErase[FlashSegmentNumber] = (uint8)FLASH_SEG_ERASE_LOW_PRIO;

            /*
             * mark this SWE with the new SWEProgrammingStatus
             */
            ptempSWEProgStatus[ApplSWENumber] = (uint8)PROGSTAT_ERASEMEMORYSTARTED;

            if ( *pMemEndAddress == endAddress )
            {
               ResponseCode = DCM_NRC_OK;
            }
            else if ( startAddress <= endAddress )
            {
               /*
                * because it's not allowed to erase across gaps a flash segment
                * with this new start address must also be available
                */
               startAddress = *pMemEndAddress + (flashAddress_t)1;
            }
            else
            {
               /*
                * 'endAddress' is not on an flash segment border:
                * NRC ROOR is already set
                */
               addressOk = FALSE;
            }
         }
         else
         {
            /*
             * the flash segment doesn't correspond to an application SWE:
             * NRC ROOR is already set
             */
         }
      }
      else
      {
         /*
          * 'startAddress' is not on an flash segment border:
          * NRC ROOR is already set
          */
         addressOk = FALSE;
      }
   } while ( (addressOk == TRUE) &&
             (ResponseCode != DCM_NRC_OK)
           );

   if ( ResponseCode == DCM_NRC_OK )
   {
      /*
       * FP_5462:
       * If one flash segment in a SWE is going to be erased, the flash segment
       * containig the SWEValidFlags must also be erased during this erase
       * memory, or must have been erased before.
       */

      uint8_least iLoop = (uint8_least)0;
      do
      {
         if ( ptempSWEProgStatus[iLoop] == (uint8)PROGSTAT_ERASEMEMORYSTARTED )
         {
            /*
             * get the address of the flash status of this SWE
             */
            const flashAddress_t tmpSweFlashStatusAddress =
               (flashAddress_t)ConvertIntPointer2ExtAddress
                  (sharedBootROMData.PointerToSweFlashStatus
                     [iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1]);

            (void)GetFlashSegmentNumberByMemAddress ( &tmpSweFlashStatusAddress,
                                                      &FlashSegmentNumber
                                                    );

            FlashSegmentNumber -= (uint8)FLASH_SEGMENT_NUMBER_BOOT;

            if ( MemSegToErase[FlashSegmentNumber] ==
                                               (uint8)FLASH_SEG_ERASE_LOW_PRIO )
            {
               /*
                * The flash segment including the signature and the flash status
                * is going to be erased:
                * It must be erased before the other flash segments
                */
               MemSegToErase[FlashSegmentNumber] =
                                               (uint8)FLASH_SEG_ERASE_HIGH_PRIO;
            }
            else
            {
               /*
                * The flash segment including the signature and the flash status
                * isn't going to be erased:
                * The SWE must be erased to allow this erase
                */
#ifdef BAC
               const uint8 * const SC_FAR tmpSWEProgrammingStatus =
#else
               const uint8 * const tmpSWEProgrammingStatus =
#endif /* Defined BAC */
                  &BootProgStatus.
                     SWEProgrammingStatus[iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1];

               switch (*tmpSWEProgrammingStatus)
               {
                  case PROGSTAT_MEMORYSUCCESSFULLYERASED:         /* no break */
                  case PROGSTAT_DATATRANSFERSTARTED:              /* no break */
                  case PROGSTAT_CHECKSIGNATURESTARTED:            /* no break */
                  case PROGSTAT_CHECKSIGNATURENOK:                /* no break */
                     /*
                      * SWE is already invalid - erasing is allowed:
                      * Nothing to do!
                      */
                     break;
                  default:
                     ResponseCode = DCM_NRC_CONDITIONSNOTCORRECT;
                     break;
               }
            }
         }
         ++iLoop;
      } while ( (ResponseCode == DCM_NRC_OK) &&
                (iLoop < (uint8_least)SWENUMBEROFAPPLSWE)
              );
   }

   return ResponseCode;
} /* end of function 'FlashEraseInitEraseMethodAddressed'                     */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : FlashEraseInitEraseMethodIndicated                         **
**                                                                            **
** DESCRIPTION   : get and check addresses for indicaded erasing method       **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData                                          **
**                                                                            **
** PARAMETER     : reqDataLen        : the length of the diagnostic message   **
**                 reqDataPtr        : req data pointer at AALFID position    **
**                 ptempSWEProgStatus: temporary SWE programming status       **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : TRUE : valid address found                                 **
**                 FALSE: no valid address found                              **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) FlashEraseInitEraseMethodIndicated
	   (
		  CONST(Dcm_MsgLenType, DCM_APPL_CONST)       reqDataLen,
		  CONST(Dcm_MsgType, DCM_APPL_CONST)          reqDataPtr,
		  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ptempSWEProgStatus
	   )
#else
static Dcm_NegativeResponseCodesType FlashEraseInitEraseMethodIndicated
	   (
		  const Dcm_MsgLenType       reqDataLen,
		  const Dcm_MsgType          reqDataPtr,
		        uint8*         const ptempSWEProgStatus
       )
#endif /* Defined BAC */
{
   Dcm_NegativeResponseCodesType ResponseCode;
                                          /* Contains result of address check */
   uint8          SweId;                  /* ID of SWE that shall be erased   */
   uint8          FlashSegmentNumber;

   boolean        addressOk;
   flashAddress_t logicalBlockNumber;     /* LBN sent in the request          */

   /*
    * Get the length of the request.
    * Data length check:
    * 1 Byte SF + 2 Byte RID + 1 Byte ErasingMethode + 1 Byte ALFI + <length> +
    * 1 Byte activationCode
    */
   ResponseCode = GetAddressAndLengthByFormatIdentifier
      ( &reqDataPtr[0],
        (uint8)(reqDataLen - 5u - 1u),
        (uint8)DIAG_LENGTH_FORMAT_IDENTIFIER,
        &logicalBlockNumber,
        &logicalBlockNumber
      );

   if ( ResponseCode != DCM_NRC_OK )
   {
      /*
       * Return is used here to decrease nesting depth.
       * 'ResponseCode' will be send in negative response
       */
      return ResponseCode;
   }

   /* check the LogicalBlockNumber of the SWE                                 */
   addressOk = GetApplSWENumberByLogicalBlockNumber ( &logicalBlockNumber,
                                                      &SweId
                                                    );

   if ( addressOk == TRUE )
   {
      /*
       * valid SWE found
       */
      uint8 tmpSweSegmentIndexAppl;

      /*
       * get the address of the flash status of this SWE
       */
      const flashAddress_t tmpSweFlashStatusAddress =
         (flashAddress_t)ConvertIntPointer2ExtAddress
            (sharedBootROMData.PointerToSweFlashStatus[SweId]);

      SweId -= (uint8)SWE_ID_OF_APPL_SWE1;

      /* Set the SWEProgrammingStatus to 'PROGSTAT_ERASEMEMORYSTARTED'        */
      ptempSWEProgStatus[SweId] = (uint8)PROGSTAT_ERASEMEMORYSTARTED;
      /*
       * mark every memory segment of this SWE for erasing in
       * 'FlashEraseFlash' function
       */
      tmpSweSegmentIndexAppl = sharedBootROMData.SweSegmentIndexAppl[SweId];
      (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&MemSegToErase[tmpSweSegmentIndexAppl],
                           (uint8)FLASH_SEG_ERASE_LOW_PRIO,
                           sharedBootROMData.SweSegmentNumberAppl[SweId]
                         );

      (void)GetFlashSegmentNumberByMemAddress ( &tmpSweFlashStatusAddress,
                                                &FlashSegmentNumber
                                              );
      /*
       * The flash segment including the signature and the flash status
       * must be erased before the other flash segments
       */
      MemSegToErase[FlashSegmentNumber - (uint8)FLASH_SEGMENT_NUMBER_BOOT] =
                                               (uint8)FLASH_SEG_ERASE_HIGH_PRIO;

      ResponseCode = DCM_NRC_OK;
   }
   else
   {
      ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }

   return ResponseCode;
} /* end of function 'FlashEraseInitEraseMethodIndicated'                     */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : FlashEraseFlash                                            **
**                                                                            **
** DESCRIPTION   : The erase function of the flashloader is called for every  **
**                 flash segment that is marked for erasing in this erasing   **
**                 step.                                                      **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : pMsgContext: DCM message context                           **
**                 FlashSegmentEraseValue: specifies the current erasing step **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : flashStatus_t  lastFlashStatus                             **
**                                                                            **
** REMARKS       : Thus the inerrupts are locked during flash erasing, the    **
**                 normal communication will not be processed.                **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(flashStatus_t, DCM_APPL_CODE) FlashEraseFlash
	   (
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
		  CONST(FlashSegmentEraseValueType, DCM_APPL_CONST)        FlashSegmentEraseValue
	   )
#else
static flashStatus_t FlashEraseFlash
       (
                Dcm_MsgContextType         * const pMsgContext,
          const FlashSegmentEraseValueType         FlashSegmentEraseValue
       )
#endif /* Defined BAC */
{
   uint8_least  iLoop;                          /* temporary loop variable    */

   flashAddress_t tempBlockLength;              /* tempBlockLength holds      */
                                                /* the length of a block      */
   flashStatus_t  lastFlashStatus = (flashStatus_t)FLASH_OK;

   iLoop = (uint8_least)0;
   do
   {
      /* if memory segment is marked for erasing in this run                  */
      if ( MemSegToErase[iLoop] == (uint8)FlashSegmentEraseValue )
      {
         CONSTP2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST) pStartAddress =
            &sharedBootROMData.MemSegTable[(uint8_least)FLASH_SEGMENT_NUMBER_BOOT + iLoop][0];
         CONSTP2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST) pEndAddress =
            &sharedBootROMData.MemSegTable[(uint8_least)FLASH_SEGMENT_NUMBER_BOOT + iLoop][1];

         tempBlockLength = (*pEndAddress - *pStartAddress) + (flashAddress_t)1u;

         /*
          * send a response pending, and wait for transmission.
          */
         Dcm_SendResponsePending(pMsgContext);

         while (Dcm_GetResponsePendingFinished(pMsgContext) ==
                                                     DCM_RP_TYPE_TX_IN_PROGRESS)
         {
            /*
             * You may call here the TP state (not timer!!!) tasks
             * to speed-up the transmission processing.
             * Reentrance problem? FlexRay?
             *
             * 'DCM_RP_TYPE_FAILED' is ignored, job is processed anyway
             * 'DCM_RP_TYPE_IDLE' could not happen
             */
         }

         lastFlashStatus = FlashErase(*pStartAddress, tempBlockLength);
      }
      ++iLoop;
   } while ( (iLoop < (uint8_least)FLASH_SEGMENT_NUMBER_APPL) &&
             (lastFlashStatus == (flashStatus_t)FLASH_OK)
           );

   /* response will be send according to 'lastFlashStatus'                    */
   return lastFlashStatus;

} /* end of function 'FlashEraseFlash'                                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : GetApplSWENumberByFlashSegmentNumber                       **
**                                                                            **
** DESCRIPTION   : Check which application SWE corresponds to a given flash   **
**                 segment                                                    **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : SweSegmentIndexAppl                                        **
**                 SweSegmentNumberAppl                                       **
**                                                                            **
** PARAMETER     : pFlashSegmentNumber: INPUT : reference to the flash        **
**                                              segment number                **
**                 pApplSWENumber:      OUTPUT: the corresponding application **
**                                              SWE                           **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : FALSE:                                                     **
**                    The given flash segment number doesn't correspond to an **
**                    application SWE                                         **
**                 TRUE:                                                      **
**                    A corresponding application SWE was found               **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(boolean, DCM_APPL_CODE) GetApplSWENumberByFlashSegmentNumber
	   (
		  CONSTP2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) pFlashSegmentNumber,
		  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)   pApplSWENumber
	   )
#else
static boolean GetApplSWENumberByFlashSegmentNumber
	   (
		  const uint8 * const pFlashSegmentNumber,
                uint8 * const pApplSWENumber
	   )
#endif /* Defined BAC */
{
   uint8_least iLoop     = (uint8_least)0;
   boolean     addressOk = FALSE;

   do
   {
      /*
       * Keeps the number of the first flash segment of the current SWE
       */
      const uint8 firstFlashSegmentOfSWE =
                              ( sharedBootROMData.SweSegmentIndexAppl[iLoop] +
                                (uint8)FLASH_SEGMENT_NUMBER_BOOT
                              );
      /*
       * Keeps the number of the last flash segment of the current SWE
       */
      const uint8 lastFlashSegmentOfSWE =
                              ( firstFlashSegmentOfSWE      +
                                sharedBootROMData.SweSegmentNumberAppl[iLoop] -
                                (uint8)1
                              );
      /*
       * check if the given flash segment is inbetween this SWE
       */
      if ( (*pFlashSegmentNumber >= firstFlashSegmentOfSWE) &&
           (*pFlashSegmentNumber <= lastFlashSegmentOfSWE)
         )
      {
         *pApplSWENumber = (uint8)iLoop;
         addressOk = TRUE;
      }
      else
      {
         ++iLoop;
      }
   } while ( (addressOk != TRUE) &&
             (iLoop < (uint8_least)SWENUMBEROFAPPLSWE)
           );

    return addressOk;
} /* end of function 'GetApplSWENumberByFlashSegmentNumber'                   */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : GetApplSWENumberByLogicalBlockNumber                       **
**                                                                            **
** DESCRIPTION   : Check which application SWE corresponds to a given         **
**                 LogicalBlockNumber                                         **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData.PointerToSweTable                        **
**                                                                            **
** PARAMETER     : pFlashSegmentNumber: INPUT : reference to the              **
**                                              LogicalBlockNumber            **
**                 pApplSWENumber:      OUTPUT: the corresponding application **
**                                              SWE                           **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : FALSE:                                                     **
**                    The given LogicalBlockNumber doesn't correspond to an   **
**                    application SWE                                         **
**                 TRUE:                                                      **
**                    A corresponding application SWE was found               **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(boolean, DCM_APPL_CODE) GetApplSWENumberByLogicalBlockNumber
	   (
		  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA) pLogicalBlockNumber,
		  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)            pApplSWENumber
	   )
#else
static boolean GetApplSWENumberByLogicalBlockNumber
       (
          const flashAddress_t * const pLogicalBlockNumber,
                uint8          * const pApplSWENumber
       )
#endif /* Defined BAC */
{
   boolean     addressOk = FALSE;
   uint8_least iLoop     = (uint8_least)SWE_ID_OF_APPL_SWE1;

   do
   {
      const flashAddress_t tmpLogicalBlockNumber = (flashAddress_t)
         ConvertIntPointer2ExtAddress(sharedBootROMData.PointerToSweTable[iLoop]);

      if ( *pLogicalBlockNumber == tmpLogicalBlockNumber )
      {
         /*
          * valid application SWE found
          */
         *pApplSWENumber = (uint8)iLoop;
         addressOk       = TRUE;
      }
      else
      {
         ++iLoop;
      }
   } while ( (addressOk != TRUE) &&
             (iLoop < (uint8_least)SWENUMBEROFALLSWE)
           );

   return addressOk;
} /* end of function 'GetApplSWENumberByLogicalBlockNumber'                   */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : GetFlashSegmentNumberByMemAddress                          **
**                                                                            **
** DESCRIPTION   : Check which flash segment of the application corresponds   **
**                 to a given memory address                                  **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData.MemSegTable                              **
**                                                                            **
** PARAMETER     : pMemAddress        : INPUT : reference to the memory       **
**                                              address                       **
**                 pFlashSegmentNumber: OUTPUT: the corresponding flash       **
**                                              segment                       **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : ADDRESS_NOT_FOUND:                                         **
**                    The given address doesn't correspond to a flash segment **
**                    of the application                                      **
**                 ADDRESS_FOUND_NO_FLASH_SEGMENT_BORDER:                     **
**                    A corresponding flash segment was found but the given   **
**                    address was not the start address of this flash segment **
**                 ADDRESS_FOUND_FLASH_SEGMENT_BORDER:                        **
**                    A corresponding flash segment was found and the given   **
**                    address was the start address of this flash segment     **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(GetFlashSegmentNumberType, DCM_APPL_CODE) GetFlashSegmentNumberByMemAddress
	   (
		  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA) pMemAddress,
		  CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)            pFlashSegmentNumber
	   )
#else
static GetFlashSegmentNumberType GetFlashSegmentNumberByMemAddress
       (
          const flashAddress_t * const pMemAddress,
                uint8          * const pFlashSegmentNumber
       )
#endif /* Defined BAC */
{
   uint8_least iLoop                = (uint8_least)FLASH_SEGMENT_NUMBER_BOOT;
   GetFlashSegmentNumberType retVal = ADDRESS_NOT_FOUND;

   do
   {
      CONSTP2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
         pStartAddress = &sharedBootROMData.MemSegTable[iLoop][0];
      CONSTP2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
         pEndAddress = &sharedBootROMData.MemSegTable[iLoop][1];

      if ( (*pMemAddress >= *pStartAddress) &&
           (*pMemAddress <= *pEndAddress)
         )
      {
         /*
          * Found the flash segment that belongs to the MemAddress:
          * 'iLoop' is the number of the flash segment.
          */
         *pFlashSegmentNumber = (uint8)iLoop;

         if ( *pMemAddress == *pStartAddress )
         {
            retVal = ADDRESS_FOUND_FLASH_SEGMENT_BORDER;
         }
         else
         {
            retVal = ADDRESS_FOUND_NO_FLASH_SEGMENT_BORDER;
         }
      }
      else
      {
         ++iLoop;
      }
   } while ( (retVal == ADDRESS_NOT_FOUND) &&
             (iLoop < (uint8_least)FLASH_SEGMENT_NUMBER_ALL)
           );

   return retVal;
} /* end of function 'GetFlashSegmentNumberByMemAddress'                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CheckProgrammingDate                                       **
**                                                                            **
** DESCRIPTION   : check for a valid date                                     **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : year :  Year of date   [first calculated from BCD to DEC]  **
**                 month:  Month of date  [first calculated from BCD to DEC]  **
**                 day  :  Day of date    [first calculated from BCD to DEC]  **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : TRUE : format of FingerPrint is valid                      **
**                 FALSE: format of FingerPrint is not valid                  **
**                                                                            **
** REMARKS       : CAUTION: year, month and day are calulated from BCD to DEC **
**                 specials of a lap year are ignored because from year 2000  **
**                 to 2099 there are no special events for a lap year         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(boolean, DCM_APPL_CODE) CheckProgrammingDate
	   (
		  CONST(uint8, DCM_APPL_CONST) year,
		  CONST(uint8, DCM_APPL_CONST) month,
		  CONST(uint8, DCM_APPL_CONST) day
	   )
#else
static boolean CheckProgrammingDate
       (
		  const uint8 year, 
		  const uint8 month, 
		  const uint8 day
	   )
#endif /* Defined BAC */
{
   const uint8 month_length[12] =   { (uint8)31u, (uint8)28u, (uint8)31u,
                                      (uint8)30u, (uint8)31u, (uint8)30u,
                                      (uint8)31u, (uint8)31u, (uint8)30u,
                                      (uint8)31u, (uint8)30u, (uint8)31u
                                    };

         uint8 programmingDateYY;
         uint8 programmingDateMM;
         uint8 programmingDateDD;

   /** check for valid BCD values of year month and day                      **/
   if ( ( ByteIsBCDValue(year)  ) &&
        ( ByteIsBCDValue(month) ) &&
        ( ByteIsBCDValue(day)   )
      )
   {

      /** check format of programming date                                   **/

      /* calculate BCD values to DEC values                                   */
      programmingDateYY = BCD2DEC(year);
      programmingDateMM = BCD2DEC(month);
      programmingDateDD = BCD2DEC(day);

      /*
       * check month and day. Year is from 0 .. 99 because check of valid
       * BCD values
       */
      if ( ( (programmingDateMM > (uint8)0u )   &&
             (programmingDateMM <= (uint8)12u)  &&
             (programmingDateDD > (uint8)0u )
           )
           &&
           (
             /* check day smaller or equal then values in table               */
             (programmingDateDD <= month_length[programmingDateMM-(uint8)1])
             ||
             /* check for leap year conditions                                */
             ( ( programmingDateMM == (uint8)2u )               &&
               ( (programmingDateYY % (uint8)4u) == (uint8)0u ) &&
               ( programmingDateDD == (uint8)29u )
             )
           )
         )
      {
         return TRUE;
      }
   }

   return FALSE;
} /* end of function 'CheckProgrammingDate'                                   */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CheckFingerPrint                                           **
**                                                                            **
** DESCRIPTION   : Check Format of Fingerprint                                **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : msg:   Message buffer containing the fingerprint           **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : TRUE : format of FingerPrint is valid                      **
**                 FALSE: format of FingerPrint is not valid                  **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(boolean, DCM_APPL_CODE) CheckFingerPrint
	   (
		  CONST(Dcm_MsgType, DCM_APPL_CONST) Fingerprint
       )
#else
static boolean CheckFingerPrint
       (
		  const Dcm_MsgType Fingerprint
	   )
#endif /* Defined BAC */
{
   const uint8 TesterServiceId =
                  Fingerprint[DIAG_FINGERPRINT_FORMAT_POS] &
                     (uint8)DIAG_FINGERPRINT_TESTER_SERVICE_ID_MASK;
   const uint8 FingerprintType =
                  Fingerprint[DIAG_FINGERPRINT_FORMAT_POS] &
                     (uint8)DIAG_FINGERPRINT_LENGTH_MASK;

         uint8       ProgrammingDeviceType;
         uint16      code;
         boolean     retVal;                          /* return value         */

   /* check format of programming date                                        */
   retVal = CheckProgrammingDate( Fingerprint[0],
                                  Fingerprint[1],
                                  Fingerprint[2]
                                );

   if ( retVal != FALSE )
   {
      if ( FingerprintType == (uint8)DIAG_FINGERPRINT_SHORT )
      {
         switch(TesterServiceId)
         {
            case TESTERTYPFREEREPAIRSHOP:
            case TESTERTYPSERVICEBMWHO:
            case TESTERTYPSYSTEMSUPPLIER:
            case TESTERTYPCARFACTORY:
            case TESTERTYPSPAREPARTFACTORY:
            case TESTERTYPDEVELOPMENT:
               retVal = TRUE;
               break;
            default:
               retVal = FALSE;
               break;
         }
      }
      else
      {
         retVal = TRUE;
         switch (TesterServiceId)                   /* switch TesterServiceId */
         {
            case TESTERTYPFREEREPAIRSHOP:
            case TESTERTYPSERVICEBMWHO:
               /*
                * CR61098: Allowed values for 'BMWHaendlerNr' are 0000 .. FFFF.
                */
               break;
            case TESTERTYPSYSTEMSUPPLIER:
               /* check format for system supplier ids                        */
               code = Make16Bit(Fingerprint[4], Fingerprint[5]);
               if ( (code >= (uint16)0x0200u) && (code <= (uint16)0xFFFEu) )
               {
                  /* reserved values for system supplier                      */
                  retVal = FALSE;
               }
               break;
            case TESTERTYPCARFACTORY:
            case TESTERTYPSPAREPARTFACTORY:
               /*
                * CR61098: Allowed values for 'BMWWerksCode' are 0000 .. FFFF.
                */
               break;
            case TESTERTYPDEVELOPMENT:
               break;
            default:
               retVal = FALSE;
               break;
         }

         /* check programming device type                                     */
         if (retVal != FALSE )
         {
            retVal = FALSE;
            ProgrammingDeviceType = Fingerprint[6];
            /* 0x00 and 0xFF are spezified for system supplier tester device  */
            /* 0x30 .. 0x39 are reserved for L4 tester                        */
            /* 0x02..0x2F and 0x3A..0xFE are reserved for future              */

            /* check for system supplier tester                               */
            if ( ( (ProgrammingDeviceType == (uint8)0x00u) ||
                   (ProgrammingDeviceType == (uint8)0xFFu)
                 ) &&
                 ((Fingerprint[3] & (uint8)0x0Fu) == TESTERTYPSYSTEMSUPPLIER)
               )
            {
                retVal = TRUE;
            }
            else
            {
               /* check for L6 tester                                         */
               if ( ProgrammingDeviceType == (uint8)0x01u )
               {
                   retVal = TRUE;
               }
            }
         }

         /** tester serial number doesn't have to be checked                 **/
         /* check for valid mileage                                           */
         if ( retVal != FALSE )
         {
            /* read mileage                                                   */
            code = Make16Bit(Fingerprint[11], Fingerprint[12]);

            /* 0xFFFF is a invalid value                                      */
            if ( code == (uint16)0xFFFFu )
            {
               retVal = FALSE;
            }
         }
      }
   }

   return retVal;
} /* end of function 'CheckFingerPrint'                                       */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : ProgrammingCounterLimitExceeded                            **
**                                                                            **
** DESCRIPTION   : Check if the programming counter of a SWE has              **
**                 exceeded the limit                                         **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : --                                                         **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : TRUE : programming is not allowed anymore                  **
**                 FALSE: programming is allowed                              **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(boolean, DCM_APPL_CODE) ProgrammingCounterLimitExceeded( void )
#else
static boolean ProgrammingCounterLimitExceeded( void )
#endif /* Defined BAC */
{
   uint8_least sweId = (uint8_least)0;
   boolean     limitExceeded = FALSE;

   do
   {
      if ( BootProgCounter.ProgrammingCounter[ sweId ] >=
                                  sharedBootROMData.ProgrammingCounterMaxValue )
      {
         limitExceeded = TRUE;
      }
      ++sweId;
   } while ( ( sweId < (uint8_least)SWENUMBEROFALLSWE ) &&
             ( limitExceeded == FALSE )
           );

   return limitExceeded;
} /* end of function 'ProgrammingCounterLimitExceeded'                        */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CalculateAlignOffset                                       **
**                                                                            **
** DESCRIPTION   : This function calcs an offset that is needed to get the    **
**                 'Address' aligned by 'Alignment' bytes                     **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : Address:   The address that should be aligned              **
**                 Alingment: The alignment                                   **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : The offset that is needed to get 'Address' aligned by      **
**                 'Alignment' bytes                                          **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(uint8, DCM_APPL_CODE) CalculateAlignOffset
	   (
		  CONST(uint32, DCM_APPL_CONST) Address,
		  CONST(uint8, DCM_APPL_CONST) Alignment
	   )
#else
static uint8 CalculateAlignOffset
	   (
		  const uint32 Address,
		  const uint8 Alignment
	   )
#endif /* Defined BAC */
{
   uint8 dummy = (Alignment - (uint8)(Address % Alignment));

   if ( dummy == Alignment )
   {
      return (uint8)0x00u;
   }
   else
   {
      return dummy;
   }
} /* end of function 'CalculateAlignOffset'                                   */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : SetFlashSegmentStatusToNotWritable                         **
**                                                                            **
** DESCRIPTION   : Mark every flash segment in the range from start address   **
**                 to end address as 'NotWritable'                            **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : pMemStartAddress: Address in Flash memory where the data   **
**                                   are going to be written                  **
**                 pMemEndAddress:   Address of the last byte where the data  **
**                                   are going to be written                  **
**                 pMsgContext       DCM message context                      **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : DCM_NRC_OK:       'OperateNvData' not needed or returned   **
**                                   'TRUE'                                   **
**                 DCM_NRC_GENERALPROGRAMMINGFAILURE:                         **
**                                   'OperateNvData' returned 'FALSE'         **
**                                                                            **
** REMARKS       : --                                                         **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) SetFlashSegmentStatusToNotWritable
	   (
		  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA)   pMemStartAddress,
		  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA)   pMemEndAddress,
		  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static Dcm_NegativeResponseCodesType SetFlashSegmentStatusToNotWritable
	   (
		  const flashAddress_t      * const pMemStartAddress,
		  const flashAddress_t      * const pMemEndAddress,
		         Dcm_MsgContextType * const pMsgContext
       )
#endif /* Defined BAC */
{
   uint8                         startFlashSegmentNumber;
   uint8                         endFlashSegmentNumber;
   uint8_least                   iLoop;
   boolean                       writeNvData  = FALSE;
   Dcm_NegativeResponseCodesType ResponseCode = DCM_NRC_OK;

   (void)GetFlashSegmentNumberByMemAddress
                              ( pMemStartAddress,
                                &startFlashSegmentNumber
                              );

   (void)GetFlashSegmentNumberByMemAddress
                              ( pMemEndAddress,
                                &endFlashSegmentNumber
                              );
   /*
    * set FlashSegmentStatus of the erased flash segments to
    * 'NOT_WRITABLE'
    */
   for ( iLoop  = (uint8_least)startFlashSegmentNumber;
         iLoop <= (uint8_least)endFlashSegmentNumber;
         iLoop++
       )
   {
      const uint8 FlashSegmentNumber = (uint8)iLoop -
                                       (uint8)FLASH_SEGMENT_NUMBER_BOOT;

      const uint8 currentStatus = GET_BIT_IN_MULTI_BYTE_BIT_ARRAY
                     ( BootProgStatus.FlashSegmentStatus,
                       FlashSegmentNumber
                     );

      if ( currentStatus == (uint8)FLASH_SEGMENT_STATUS_WRITABLE )
      {
         /* mark that the Nv memory must be written                           */
         writeNvData = TRUE;

         CLEAR_BIT_IN_MULTI_BYTE_BIT_ARRAY
                         ( BootProgStatus.FlashSegmentStatus,
                           FlashSegmentNumber
                         );
      }
   }

   /* Write Nv memory only if the values have changed                         */
   if ( writeNvData == TRUE )
   {
      /* Write to Nv memory and check for correct writting                    */
      if ( OperateNvData(NVM_DIAG_BOOTPROGSTATUS, NV_WRITE_OPERATION ) != TRUE )
      {
         /* writing failed - set negative response                            */
         ResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;
      }
      else
      {
#if (SC_NONCOMPRESSED_ENABLE == STD_ON)
         if ( ReprogrammingParams.dataFormatIdentfier ==
                                         (uint8)DFI_NOTCOMPRESSED_NOTENCRYPTED )
         {
            /*
             * When EEPROM is updated in 'TransferData' (on physical Flash
             * segment borders), a ResponsePending must be sent to change from
             * P2 to P2*:
             * Check whether a response pending was already sent or not
             */
            if ( Dcm_GetResponsePendingFinished(pMsgContext) ==
                                                              DCM_RP_TYPE_IDLE )
            {
               /*
                * force the transmission of a response pending
                */
               Dcm_SendResponsePending(pMsgContext);
            }
            /* wait for a current response pending to be transmitted          */
            while ( Dcm_GetResponsePendingFinished(pMsgContext)
                                                 == DCM_RP_TYPE_TX_IN_PROGRESS )
            {
               /*
                * You may call here the TP state (not timer!!!) tasks
                * to speed-up the transmission processing.
                * Reentrance problem? FlexRay?
                *
                * 'DCM_RP_TYPE_FAILED' is ignored, job is processed anyway
                */
            }
         }
#endif /* SC_NONCOMPRESSED_ENABLE == STD_ON                                       */
      }
   }

   return ResponseCode;
} /* end of function 'SetFlashSegmentStatusToNotWritable'                     */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat    **
**                                                                            **
** DESCRIPTION   : Programm data to flash. Before the 'FlashSegmentStatus' is **
**                 updated and it is checked, if the SWE valid flags or       **
**                 programming dependencies area is included in the data      **
**                 going to be written                                        **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : pMemStartAddress: Address in Flash memory where the data   **
**                                   are going to be written                  **
**                 BufferLength:     Length of the buffer that is going to be **
**                                   written                                  **
**                 pDataBuffer:      The buffer that is going to be written   **
**                 pMsgContext       DCM message context                      **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : Result of 'SetFlashSegmentStatusToNotWritable' or          **
**                 'FlashWrite' function call                                 **
**                                                                            **
** REMARKS       : The memory area including the valid flags and programming  **
**                 dependencies area is masked out by filling the area with   **
**                 flash driver blank values (e.g. 0xFFu).                    **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat
	   (
          CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)              pDataBuffer,
		  CONSTP2CONST(flashAddress_t, AUTOMATIC, DCM_APPL_DATA)   pMemStartAddress,
		  CONST(uint16, DCM_APPL_CONST)                            BufferLength,
          CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
	   )
#else
static Dcm_NegativeResponseCodesType FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat
       (
                uint8              * const pDataBuffer,
          const flashAddress_t     * const pMemStartAddress,
          const uint16                     BufferLength,
                Dcm_MsgContextType * const pMsgContext
       )
#endif /* Defined BAC */
{
  uint8_least    nLoop;
  flashAddress_t validflagstart, validflagend;
  Dcm_NegativeResponseCodesType ResponseCode;
  flashStatus_t  lastFlashStatus;
  flashAddress_t erasestart;
  flashAddress_t eraseend;
  flashAddress_t temp_MemStart = *pMemStartAddress;
  flashAddress_t temp_MemEnd   = temp_MemStart +
                                 (flashAddress_t)BufferLength -
                                 (flashAddress_t)1;
  uint8 flash_erased_byte;

  /*
   * Set the flash segment status of the segments that are going to be
   * programmed to not writable by a new request download.
   */
  ResponseCode = SetFlashSegmentStatusToNotWritable
                 ( pMemStartAddress,
                   &temp_MemEnd,
                   pMsgContext
                 );

  if ( ResponseCode == DCM_NRC_OK )
  {
    for ( nLoop=(uint8_least)0;
          nLoop<(uint8_least)SWENUMBEROFAPPLSWE;
          nLoop++
        )
    {
      validflagstart =
            (flashAddress_t)ConvertIntPointer2ExtAddress
			   (&sharedBootROMData.PointerToSweFlashStatus
                  [nLoop + (uint8_least)SWE_ID_OF_APPL_SWE1]->SweValidFlag[0]);

      validflagend = validflagstart + (flashAddress_t)SWE_VALID_FLAG_AREA_LENGTH +
                     (flashAddress_t)PROG_DEP_AREA_LENGTH - 1;

      if( ((validflagstart <= temp_MemStart) && (validflagend >= temp_MemStart)) ||
          ((validflagstart <= temp_MemEnd  ) && (validflagend >= temp_MemEnd  )) ||
          ((validflagstart >  temp_MemStart) && (validflagend <  temp_MemEnd  ))
        )
      {
        erasestart = ( (validflagstart > temp_MemStart) ? validflagstart : temp_MemStart);
        eraseend   = ( (validflagend   > temp_MemEnd  ) ? temp_MemEnd    : validflagend );

        (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&pDataBuffer[erasestart - temp_MemStart],
                             FLASH_ERASED_BYTE,
                             (size_t)( eraseend - erasestart + 1 )
                           );
      }
    }

      switch (ReprogrammingParams.dataFormatIdentfier)
      {
#if (SC_NONCOMPRESSED_ENABLE == STD_ON)
         case DFI_NOTCOMPRESSED_NOTENCRYPTED:
#ifdef SEND_RP_ON_LAST_BYTE
            /*
             * On some architectures (e.g. V850 FJ2) the flash driver performs
             * a valid check over physical Flash segments, when the last byte of
             * the segment is written. This check can take several hundred ms
             * (e.g. about 250 ms on V850 FJ2, when the 60k segment is checked).
             * Therefore a ResponsePending must be sent to change from P2 to P2*
             */
            if (Dcm_GetResponsePendingFinished(pMsgContext) == DCM_RP_TYPE_IDLE)
            {
               const flashAddress_t currentEndAddress =
                                                  *pMemStartAddress +
                                                  (flashAddress_t)BufferLength -
                                                  (flashAddress_t)1;
               boolean lastByteOfFlashSegment = FALSE;

               nLoop = (uint8_least)FLASH_SEGMENT_NUMBER_BOOT;
               while ( (nLoop < (uint8_least)FLASH_SEGMENT_NUMBER_ALL) &&
                       (lastByteOfFlashSegment == FALSE)
                     )
               {
                  CONSTP2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                      pMemEndAddress = &sharedBootROMData.MemSegTable[nLoop][1];

                  if ( (*pMemStartAddress <= *pMemEndAddress) &&
                       (currentEndAddress >= *pMemEndAddress)
                     )
                  {
                     lastByteOfFlashSegment = TRUE;
                  }
                  nLoop++;
               }

               if ( lastByteOfFlashSegment == TRUE )
               {
                  /*
                   * force the transmission of a response pending
                   */
                  Dcm_SendResponsePending(pMsgContext);
               }
            }
            /* wait for a current response pending to be transmitted          */
            while ( Dcm_GetResponsePendingFinished(pMsgContext)
                                                 == DCM_RP_TYPE_TX_IN_PROGRESS )
            {
               /*
                * You may call here the TP state (not timer!!!) tasks
                * to speed-up the transmission processing.
                * Reentrance problem? FlexRay?
                *
                * 'DCM_RP_TYPE_FAILED' is ignored, job is processed anyway
                */
            }
#endif /* SEND_RP_ON_LAST_BYTE                                                */
            break;
#endif /* SC_NONCOMPRESSED_ENABLE == STD_ON                                       */

#if (SC_NRV2B_ENABLE == STD_ON)
         case DFI_NRV2B_COMPRESSED_NOTENCRYPTED:
               Boot_EnterCriticalRegion();
               CheckFreetimer();
               Boot_LeaveCriticalRegion();
               /* wait for a current response pending to be transmitted       */
               while ( Dcm_GetResponsePendingFinished(pMsgContext)
                                                 == DCM_RP_TYPE_TX_IN_PROGRESS )
               {
                  /*
                   * You may call here the TP state (not timer!!!) tasks
                   * to speed-up the transmission processing.
                   * Reentrance problem? FlexRay?
                   *
                   * 'DCM_RP_TYPE_FAILED' is ignored, job is processed
                   *                      anyway
                   */
               }
            break;
#endif /* (SC_NRV2B_ENABLE == STD_ON)                                             */
         default:
            /*
             * Send neg. response because of a unsupported
             * 'dataFormatIdentfier' - this is a logical problem
             */
            ResponseCode = DCM_NRC_CONDITIONSNOTCORRECT;
      }

      if ( ResponseCode == DCM_NRC_OK )
      {
#if (SC_LED_DEMO_ON == STD_ON)
         Led_Set(LED_FLASH_WRITE); /* can be used to meassure FlashWrite time */
#endif
         lastFlashStatus = FlashWrite
                  ( (P2VAR(uint8, AUTOMATIC, FLASH_APPL_DATA)) &pDataBuffer[0],
                    *pMemStartAddress,
                    (flashMemoryLength_t)BufferLength
                  );                              /* programming flash memory */
#if (SC_LED_DEMO_ON == STD_ON)
         Led_Clear(LED_FLASH_WRITE);
#endif
         if ( lastFlashStatus == (flashStatus_t)FLASH_OK )
         {
            ResponseCode = DCM_NRC_OK;
         }
         else
         {
            ResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;
         }
      }
   }

   return ResponseCode;
} /* end of function 'FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat'*/


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : WriteSweValidFlag                                          **
**                                                                            **
** DESCRIPTION   : This function writes the SWE valid flag into the Flash.    **
**                                                                            **
** PRECONDITIONS : + FLASH driver must be initialized                         **
**                 + sizeof(tmpBuffer) > 'SWE_VALID_FLAG_AREA_LENGTH'         **
**                 + the valid flag area must be blank: can be checked by     **
**                   'Swe_GetValidStateOfSwe'                                 **
**                                                                            **
** GLOBAL DATA   : --                                                         **
**                                                                            **
** PARAMETER     : pMsgContext   : DCM message context                        **
**                 SweNumber     : Number of the SWE, whose 'SWE_VALID_FLAG'  **
**                                 has to be set                              **
**                 tmpBuffer     : Temporary buffer used to prepare SWE valid **
**                                 data in RAM                                **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : TRUE : correctly written                                   **
**                 FALSE: not correctly written                               **
**                                                                            **
** REMARKS       : It is only allowed to write the SWE valid flag after a     **
**                 successful signature check                                 **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(boolean, DCM_APPL_CODE) WriteSweValidFlag
	   (
          CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
		  CONST(uint8, DCM_APPL_CONST)                             SweNumber,
          CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)              tmpBuffer
	    )
#else
static boolean WriteSweValidFlag
               (
                        Dcm_MsgContextType * const pMsgContext,
                  const uint8                      SweNumber,
                        uint8              * const tmpBuffer
               )
#endif /* Defined BAC */
{
   flashStatus_t  flashRetVal;
   boolean        retVal;

   const flashAddress_t tmpSweValidFlagAddress =
      (flashAddress_t)ConvertIntPointer2ExtAddress
         (&sharedBootROMData.PointerToSweFlashStatus
            [SweNumber]->SweValidFlag[0]);

   /* init 'tmpBuffer' with SWE valid data                                    */
   tmpBuffer[0] = Dcm_GetHiByte((uint16)VALID_FLAG_SWE_VALID);
   tmpBuffer[1] = Dcm_GetLoByte((uint16)VALID_FLAG_SWE_VALID);

#if ( SWE_VALID_FLAG_AREA_LENGTH < 0x02u )
   #error "bootdiag.c: 'SWE_VALID_FLAG_AREA_LENGTH' must not be less 0x02u"
#elif ( SWE_VALID_FLAG_AREA_LENGTH == 0x02u )
   /* nothing else to do                                                      */
#else /* if ( SWE_VALID_FLAG_AREA_LENGTH > 0x02u )                            */
   (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&tmpBuffer[2],
                        0x00u,
                        SWE_VALID_FLAG_AREA_LENGTH - 0x02u
                      );
#endif

   /*
    * When Flash is written a ResponsePending must be sent to get a new P2*
    * timeout
    */
   Dcm_SendResponsePending(pMsgContext);
   /* wait for a current response pending to be transmitted                   */
   while ( Dcm_GetResponsePendingFinished(pMsgContext)
                                                 == DCM_RP_TYPE_TX_IN_PROGRESS )
   {
      /*
       * You may call here the TP state (not timer!!!) tasks
       * to speed-up the transmission processing.
       * Reentrance problem? FlexRay?
       *
       * 'DCM_RP_TYPE_FAILED' is ignored, job is processed anyway
       */
   }

   /* write SWE valid flag into flash memory                                  */
   flashRetVal = FlashWrite
      ( (P2VAR(uint8, AUTOMATIC, FLASH_APPL_DATA)) &tmpBuffer[0],
        tmpSweValidFlagAddress,
        (flashMemoryLength_t)SWE_VALID_FLAG_AREA_LENGTH
      );

   if ( flashRetVal == (flashStatus_t)FLASH_OK )
   {
      retVal = TRUE;
   }
   else
   {
      retVal = FALSE;
   }

   return retVal;
} /* end of function 'WriteSweValidFlag'                                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : WriteProgrammingDependencies                               **
**                                                                            **
** DESCRIPTION   : This function writes the programming dependencies into the **
**                 Flash.                                                     **
**                                                                            **
** PRECONDITIONS : + FLASH driver must be initialized                         **
**                 + sizeof(tmpBuffer) > PROG_DEP_AREA_LENGTH                 **
**                 + the programming dependencies area must be blank: can be  **
**                   checked by 'GetCheckProgDepResultFromProgDepFlags'       **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData.PointerToSweFlashStatus                  **
**                                                                            **
** PARAMETER     : pMsgContext: DCM message context                           **
**                 tmpBuffer:   temporary buffer used to prepare data in RAM  **
**                 ProgDepVal:  value of programming dependencies that should **
**                              be written                                    **
**                                                                            **
** INPUT         : --                                                         **
**                                                                            **
** RETURN        : PROG_DEP_WRITTEN      : correctly written                  **
**                 PROG_DEP_CONDITIONSNOTCORRECT:                             **
**                                         invalid value of 'ProgDepVal'      **
**                 PROG_DEP_ERROR_WRITING: error while flash writing          **
**                                                                            **
** REMARKS       : It is only allowed to write the programming dependencies   **
**                 after a successful/unsuccessful test of the programming    **
**                 dependencies.                                              **
**                 The result is written in each SWE, that has yet no status  **
**                 available. This is neccessary when not all SWEs are        **
**                 reprogrammed during one programming cycle                  **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(WriteProgDepRetValType, DCM_APPL_CODE) WriteProgrammingDependencies
	   (
          CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
          CONST(SweProgDepStateType, DCM_APPL_CONST)               ProgDepVal,
          CONSTP2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)              tmpBuffer
	   )
#else
static WriteProgDepRetValType WriteProgrammingDependencies
                              (
                                       Dcm_MsgContextType  * const pMsgContext,
                                 const SweProgDepStateType         ProgDepVal,
                                       uint8               * const tmpBuffer
                              )
#endif /* Defined BAC */
{
         uint32                 maxCounter             = (uint32)0x00000001uL;
         uint8_least            iLoop;
         uint8_least            ApplSWEwithMaxCounter  = (uint8_least)0;
         uint8_least            writeSWEProgDepCounter = (uint8_least)0;
         flashStatus_t          flashRetVal;
         WriteProgDepRetValType retVal;
   const uint8   SC_FAR_POINTER pProgDepVal;
         uint8                  writeSWEProgDep[SWENUMBEROFAPPLSWE];

   /*
    * Check 'ProgDepVal' for incorrect values from
    * 'UserCallback_ProgrammingDependenciesCheck' that should not written into
    * flash
    */
   if ( ProgDepVal == (uint8)FLASH_ERASED_BYTE )
   {
      /* return is used for faster execution and decrease nesting depth       */
      return PROG_DEP_CONDITIONSNOTCORRECT;
   }

   for ( iLoop = (uint8_least)0;
         iLoop < (uint8_least)SWENUMBEROFAPPLSWE;
         iLoop++
       )
   {
      /*
       * The check for reserved values in the the programming dependencies
       * area was already done in function
       * 'GetCheckProgDepResultFromProgDepFlags'. That's why no checks have
       * to be performed here.
       *
       * Read current counter
       */
      const uint8 SC_FAR_POINTER tmpPointerToProgDeps =
         &sharedBootROMData.
            PointerToSweFlashStatus[iLoop + (uint8_least)SWE_ID_OF_APPL_SWE1]->
               ProgDepFlag[0];

      const uint32 actCounter = Make32Bit ( tmpPointerToProgDeps[1],
                                            tmpPointerToProgDeps[2],
                                            tmpPointerToProgDeps[3],
                                            tmpPointerToProgDeps[4]
                                           );

      /* Blank check of programming dependencies + counter                    */
      if ( (tmpPointerToProgDeps[0] != (uint8)FLASH_ERASED_BYTE) ||
           (actCounter              != Make32Bit ( (uint8)FLASH_ERASED_BYTE,
                                                   (uint8)FLASH_ERASED_BYTE,
                                                   (uint8)FLASH_ERASED_BYTE,
                                                   (uint8)FLASH_ERASED_BYTE
                                                 ))
         )
      {
         /*
          * The programming dependencies area was written before:
          * Determine maximum counter
          */
         if ( actCounter >= maxCounter )
         {
            maxCounter = actCounter;

            /* store SWE number that holds maximum counter                    */
            ApplSWEwithMaxCounter = (iLoop + (uint8_least)0x01u);
         }
      }
      else
      {
         /* store SWE that should be written with a new value                 */
         writeSWEProgDep[writeSWEProgDepCounter] = (uint8)iLoop;
         ++writeSWEProgDepCounter;
      }
   }

   pProgDepVal =
      &sharedBootROMData.
         PointerToSweFlashStatus[ApplSWEwithMaxCounter +
                                 (uint8_least)SWE_ID_OF_APPL_SWE1 -
                                 (uint8_least)1]->ProgDepFlag[0];

   /*
    * At least one blank valid flag space must be available ==> see
    * preconditions of this function.
    *
    * Check the new counter value:
    * If no valid counter was found, the counter hast to start with the initial
    * value of 1.
    * If the current status of the highest counter matches the one that has to
    * be written the same counter value can be used.
    * Else the counter is increased by one.
    */
   if ( (ApplSWEwithMaxCounter != (uint8_least)0x00u) &&
        (*pProgDepVal != (uint8)ProgDepVal)
      )
   {
      maxCounter++;
   }

   if ( writeSWEProgDepCounter > (uint8_least)0x00u )
   {
      /*
       * When Flash is written a ResponsePending must be sent to change from
       * P2 to P2*:
       * Check whether a response pending was already sent or not
       */
      if ( Dcm_GetResponsePendingFinished(pMsgContext) == DCM_RP_TYPE_IDLE )
      {
         /*
          * force the transmission of a response pending
          */
         Dcm_SendResponsePending(pMsgContext);
      }
      /* wait for a current response pending to be transmitted                */
      while ( Dcm_GetResponsePendingFinished(pMsgContext)
                                                 == DCM_RP_TYPE_TX_IN_PROGRESS )
      {
         /*
          * You may call here the TP state (not timer!!!) tasks
          * to speed-up the transmission processing.
          * Reentrance problem? FlexRay?
          *
          * 'DCM_RP_TYPE_FAILED' is ignored, job is processed anyway
          */
      }

      /* writing programming dependencies                                     */
      retVal = PROG_DEP_WRITTEN;
      iLoop  = (uint8_least)0x00u;
      while ( (iLoop   < writeSWEProgDepCounter) &&
              (retVal != PROG_DEP_ERROR_WRITING)
            )
      {
         /*
          * Violation: MISRA Rule 30:
          * Rule is not applicable - when 'writeSWEProgDep' is unset
          * 'writeSWEProgDepCounter' == 0x00u and this code can not be reached
          */
         const flashAddress_t tmpSweProgDepAddress =
            (flashAddress_t)ConvertIntPointer2ExtAddress
               (sharedBootROMData.PointerToSweFlashStatus
                  [writeSWEProgDep[iLoop] + (uint8)SWE_ID_OF_APPL_SWE1]->ProgDepFlag);

         tmpBuffer[0] = (uint8)ProgDepVal;
         tmpBuffer[1] = Dcm_GetHiHiByte(maxCounter);
         tmpBuffer[2] = Dcm_GetHiLoByte(maxCounter);
         tmpBuffer[3] = Dcm_GetLoHiByte(maxCounter);
         tmpBuffer[4] = Dcm_GetLoLoByte(maxCounter);

         /* write programming dependencies area into SWE flash ROM            */
         flashRetVal = FlashWrite
            ( (P2VAR(uint8, AUTOMATIC, FLASH_APPL_DATA)) &tmpBuffer[0],
              tmpSweProgDepAddress,
              (flashMemoryLength_t)PROG_DEP_AREA_LENGTH
            );

         if ( flashRetVal != (flashStatus_t)FLASH_OK )
         {
            /* programming error                                              */
            retVal = PROG_DEP_ERROR_WRITING;
         }
         else
         {
            ++iLoop;
         }
      }
   }
   else
   {
      /*
       * logical problem - no empty space for programming dependencies:
       * 'GetCheckProgDepResultFromProgDepFlags' was not called before
       */
      retVal = PROG_DEP_CONDITIONSNOTCORRECT;
   }

   return retVal;
} /* end of function 'WriteProgrammingDependencies'                           */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : WriteSvkHistoryMemory                                      **
**                                                                            **
** DESCRIPTION   : This function writes a new entry into the SVK history      **
**                 memory in EEPROM.                                          **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : TRUE : if SVK backup not needed or successfully written    **
**                 FALSE: if an error occurs                                  **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#if (! ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON)))
	#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) WriteSvkHistoryMemory( void )
	#else
	static boolean WriteSvkHistoryMemory( void )
	#endif /* Defined BAC */
#else
	#ifdef BAC
	FUNC(boolean, DCM_APPL_CODE) WriteSvkHistoryMemory( void )
	#else
	boolean WriteSvkHistoryMemory(void)
	#endif /* Defined BAC */
#endif /* (! ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON))) */
{
#if (NUMBEROFSVKBACKUPS > 0u)
         P2VAR(uint8, AUTOMATIC, COMMON_APPL_DATA) pendingSvkPtr;
#else
         P2VAR(uint8, AUTOMATIC, COMMON_APPL_DATA) pendingSvkPtr = NULL_PTR;
#endif
   const uint8   currentTesterType  = (FingerprintInRam[3] & (uint8)0x0Fu);
         uint8   newSvkLockedStatus = SvkHistoryMemory.SvkLockedStatus;

   if ( (currentTesterType  == (uint8)TESTERTYPSYSTEMSUPPLIER) &&
        (newSvkLockedStatus == (uint8)SVKSTATUS_SYSSUPPANDPLANTUNLOCKED)
      )
   {
      /* system supplier SVK entry                                            */
      pendingSvkPtr      = &SvkHistoryMemory.SvkSysSupp[0];
      newSvkLockedStatus = (uint8)SVKSTATUS_SYSSUPPANDPLANTUNLOCKED;
   }
   else if ( ( (currentTesterType == (uint8)TESTERTYPCARFACTORY) ||
               (currentTesterType == (uint8)TESTERTYPSPAREPARTFACTORY)
             ) &&
             ( newSvkLockedStatus != (uint8)SVKSTATUS_SYSSUPPANDPLANTLOCKED)
           )
   {
      /* plant SVK entry                                                      */
      pendingSvkPtr      = &SvkHistoryMemory.SvkPlant[0];
      newSvkLockedStatus = (uint8)SVKSTATUS_SYSSUPLOCKEDPLANTUNLOCKED;
   }
   else
   {
      newSvkLockedStatus = (uint8)SVKSTATUS_SYSSUPPANDPLANTLOCKED;
#if (NUMBEROFSVKBACKUPS > 0u)
      /* backup SVK entry                                                     */
      pendingSvkPtr = &SvkHistoryMemory.SvkBackup[SvkHistoryMemory.
                                                  SvkBackupFIFOCounter][0];
#else /* (NUMBEROFSVKBACKUPS > 0u)                                            */
      if ( newSvkLockedStatus == SvkHistoryMemory.SvkLockedStatus )
      {
         /* Nothing to do                                                     */
         return TRUE;
      }
#endif  /* (NUMBEROFSVKBACKUPS > 0u)                                          */
   }

   /* get current svk if required                                             */
   if ( pendingSvkPtr != NULL_PTR )
   {
      GetCurrentSvk(pendingSvkPtr, GET_SVK_CURRENT_FOR_HISTORY_MEM);

      /*
       * programming dependencies must be valid if SVK backup memory is used
       */
      if ( ( newSvkLockedStatus == (uint8)SVKSTATUS_SYSSUPPANDPLANTLOCKED )
           &&
           ( pendingSvkPtr[DIAG_SVK_POS_PROGDEP] != SWE_PROGDEP_STATE_CONSISTENT_APPL )
         )
      {
         return TRUE;
      }
   }

   /** write new SvkBackupFIFOCounter from RAM mirror to EEPROM if required  **/
#if (NUMBEROFSVKBACKUPS > 0u)

   /* update SvkBackupFIFOCounter only if history memory was written          */
   if ( newSvkLockedStatus == (uint8)SVKSTATUS_SYSSUPPANDPLANTLOCKED )
   {
      /*
       * Calculate the position of the next SVK backup.
       * Remark: The SVK backup memory is a ring buffer
       */
      SvkHistoryMemory.SvkBackupFIFOCounter =
         (uint8)((SvkHistoryMemory.SvkBackupFIFOCounter + (uint8)1) %
         (uint8)NUMBEROFSVKBACKUPS);
   }
#endif /* (NUMBEROFSVKBACKUPS > 0u)                                           */

   /* store new locked status                                                 */
   SvkHistoryMemory.SvkLockedStatus = newSvkLockedStatus;

   /** write SVK backup from RAM mirror into EEPROM and return               **/
   return OperateNvData( NVM_DIAG_SVKHISTORYMEMORY, NV_WRITE_OPERATION );

} /* end of function 'WriteSvkHistoryMemory'                                  */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : WriteFingerprintAndApplStartedFirstFlag                    **
**                                                                            **
** DESCRIPTION   : This function writes the Fingerprint in RAM into EEPROM    **
**                 and sets the 'ApplStartedFirstFlag' to 'IsFirstStart'.     **
**                 Thereby the application is able to detect it's first start **
**                 after beeing reprogrammed                                  **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : TRUE : EEPROM was successfully written                     **
**                 FALSE: An error occured while writing EEPROM               **
**                                                                            **
** REMARKS       : 'ApplStartedFirstFlag' and 'Fingerprint' are located in    **
**                 the same nv block                                          **
**                                                                            **
*******************************************************************************/
#if (! ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON)))
	#ifdef BAC
	static FUNC(boolean, DCM_APPL_CODE) WriteFingerprintAndApplStartedFirstFlag( void )
	#else
	static boolean WriteFingerprintAndApplStartedFirstFlag( void )
	#endif /* Defined BAC */
#else
   #ifdef BAC
   FUNC(boolean, DCM_APPL_CODE) WriteFingerprintAndApplStartedFirstFlag( void )
   #else
   boolean WriteFingerprintAndApplStartedFirstFlag(void)
   #endif /* Defined BAC */
#endif
{
   /* set application started first flag in RAM mirror                        */
   BootProgData.ApplicStartedFirst = (uint8)ISFIRSTSTARTOFAPPLICATION;

   /* copy fingerprint from RAM into RAM mirror                               */
   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&BootProgData.FingerPrint[0],
                        (const void SC_FAR_POINTER)&FingerprintInRam[0],
                        sizeof(BootProgData.FingerPrint)
                      );

   /* write data to nv memory and return the result                           */
   return OperateNvData( NVM_DIAG_BOOTPROGDATA, NV_WRITE_OPERATION );

} /* end of function 'WriteFingerprintAndApplStartedFirstFlag'                */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : GetAddressAndLengthByFormatIdentifier                      **
**                                                                            **
** DESCRIPTION   : convert a address and/or a length from an diagnostic       **
**                 request to variables                                       **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : reqDataPtr:     IN : request data buffer at the position   **
**                                      of the AddressAndLengthByFormatId     **
**                                      byte                                  **
**                 addressOrLengthSize: length that the address must take in  **
**                                      the request                           **
**                 addressOrLengthFormatId:                                   **
**                                      Address-/ Length-/ AddressAndLenght-  **
**                                      FormatIdentifier                      **
**                 pAddress:       OUT: taking the address                    **
**                 pLength:        OUT: taking the length                     **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : DCM_NRC_OK               : valid address                   **
**                 DCM_NRC_REQUESTOUTOFRANGE: invalid address and length      **
**                                            format identifier or address    **
**                                            does not fit into the data type **
**                 DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT:             **
**                                            invalid request length          **
**                                                                            **
** REMARKS       : when only a address or a length is requested               **
**                 (AddressAndLenghtFormatIdentifier 0x0? or 0x?0) the        **
**                 function can be called with the same parameter for         **
**                 pAddress and pLength                                       **
**                                                                            **
*******************************************************************************/
#ifdef BAC
static FUNC(Dcm_NegativeResponseCodesType, DCM_APPL_CODE) GetAddressAndLengthByFormatIdentifier
	   (
		  VAR(Dcm_MsgType, DCM_APPL_DATA)                      reqDataPtr,
		  CONST(uint8, DCM_APPL_CONST)                         addressOrLengthSize,
		  CONST(uint8, DCM_APPL_CONST)                         addressOrLengthFormatId,
		  CONSTP2VAR(flashAddress_t, AUTOMATIC, DCM_APPL_DATA) pAddress,
		  CONSTP2VAR(flashAddress_t, AUTOMATIC, DCM_APPL_DATA) pLength
	   )
#else
static Dcm_NegativeResponseCodesType GetAddressAndLengthByFormatIdentifier
       (
                Dcm_MsgType            reqDataPtr,
          const uint8                  addressOrLengthSize,
          const uint8                  addressOrLengthFormatId,
                flashAddress_t * const pAddress,
                flashAddress_t * const pLength
       )
#endif /* Defined BAC */
{
   const uint8 addressFormatIdentifier = reqDataPtr[0] &  (uint8)0x0Fu;
   const uint8 lengthFormatIdentifier  = reqDataPtr[0] >> (uint8)0x04u;

   Dcm_NegativeResponseCodesType ResponseCode;

   if ( *reqDataPtr++ != addressOrLengthFormatId )
   {
      ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }
   else
   {
      const uint8 tmpAddressOrLengthSize = addressFormatIdentifier +
                                           lengthFormatIdentifier;
      if ( addressOrLengthSize != tmpAddressOrLengthSize )
      {
         ResponseCode = DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      else
      {
         #if (DIAG_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER == 0x44u)
            /* optimized for 4 byte addresses                                 */
            if ( addressFormatIdentifier != (uint8)0x00u )
            {
               *pAddress = (flashAddress_t)Make32Bit (
                                                       reqDataPtr[0],
                                                       reqDataPtr[1],
                                                       reqDataPtr[2],
                                                       reqDataPtr[3]
                                                     );
               reqDataPtr+=4;
            }

            if ( lengthFormatIdentifier != (uint8)0x00u )
            {
               *pLength = (flashAddress_t)Make32Bit (
                                                      reqDataPtr[0],
                                                      reqDataPtr[1],
                                                      reqDataPtr[2],
                                                      reqDataPtr[3]
                                                    );
            }

            ResponseCode = DCM_NRC_OK;
         #elif (DIAG_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER == 0x33u)
            /* optimized for 3 byte addresses                                 */
            if ( addressFormatIdentifier != (uint8)0x00u )
            {
               *pAddress = (flashAddress_t)Make32Bit (
                                                       (uint8)0,
                                                       reqDataPtr[0],
                                                       reqDataPtr[1],
                                                       reqDataPtr[2]
                                                     );
               reqDataPtr+=3;
            }

            if ( lengthFormatIdentifier != (uint8)0x00u )
            {
               *pLength = (flashAddress_t)Make32Bit (
                                                      (uint8)0,
                                                      reqDataPtr[0],
                                                      reqDataPtr[1],
                                                      reqDataPtr[2]
                                                    );
            }

            ResponseCode = DCM_NRC_OK;
         #elif (DIAG_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER == 0x22u)
            /* optimized for 2 byte addresses                                 */
            if ( addressFormatIdentifier != (uint8)0x00u )
            {
               *pAddress = (flashAddress_t)Make16Bit (
                                                       reqDataPtr[0],
                                                       reqDataPtr[1]
                                                     );
               reqDataPtr+=2;
            }

            if ( lengthFormatIdentifier != (uint8)0x00u )
            {
               *pLength = (flashAddress_t)Make16Bit (
                                                      reqDataPtr[0],
                                                      reqDataPtr[1]
                                                    );
            }

            ResponseCode = DCM_NRC_OK;
         #else
            /* this code fits the rest: e.g. 0x34, 0x56 ...                   */

            uint8_least iLoop;

            ResponseCode = DCM_NRC_OK;

            *pAddress = (flashAddress_t)0x00u;
            *pLength  = (flashAddress_t)0x00u;

            iLoop=(uint8_least)0;
            if ( addressFormatIdentifier > (uint8)sizeof(*pAddress) )
            {
               /* Check if the address is to big for our data type            */
               do
               {
                  if (*reqDataPtr++ != (uint8)0x00u)
                  {
                     ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
                  }
                  ++iLoop;
               } while ( (iLoop < ((uint8_least)addressFormatIdentifier -
                                   (uint8_least)sizeof(*pAddress))) &&
                         (ResponseCode == DCM_NRC_OK)
                       );
            }
            if ( ResponseCode == DCM_NRC_OK )
            {
               for (; iLoop < (uint8_least)addressFormatIdentifier; iLoop++)
               {
                  *pAddress = ((*pAddress << (uint8)8) + *reqDataPtr++);
               }

               iLoop=(uint8_least)0;
               if ( lengthFormatIdentifier > (uint8)sizeof(*pLength) )
               {
                  /* Check if the length is to big for our data type          */
                  do
                  {
                     if (*reqDataPtr++ != (uint8)0x00u)
                     {
                        ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
                     }
                     ++iLoop;
                  } while ( (iLoop < ((uint8_least)lengthFormatIdentifier -
                                      (uint8_least)sizeof(*pLength))) &&
                            (ResponseCode == DCM_NRC_OK)
                          );
               }
               if ( ResponseCode == DCM_NRC_OK )
               {
                  for (; iLoop < (uint8_least)lengthFormatIdentifier; iLoop++)
                  {
                     *pLength = ((*pLength << (uint8)8) + *reqDataPtr++);
                  }
               }
            }
         #endif
      }
   }

   return ResponseCode;
} /* end of function 'GetAddressAndLengthByFormatIdentifier'                  */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#if (SC_NRV2B_ENABLE == STD_ON)
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CheckFreetimer                                             **
**                                                                            **
** DESCRIPTION   : Increment elapsedTime counter during NRV compressed data   **
**                 processing                                                 **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** INPUT         : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : The priority of the task calling this function cyclic      **
**                 (e.g. Task_Cyclic2) must not be less then the priority of  **
**                 the task that is processing the NRV compressed data (e.g.  **
**                 BackgroundTask)                                            **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_FREETIMER_CODE) CheckFreetimer( void )
#else
void CheckFreetimer( void )
#endif /* Defined BAC */
{
   if ( responsePendingSupervision.elapsedTime != TIMER_INACTIVE )
   {
      const FreeTimer_TimeInTicksType approxFlashWriteTime =
                       FreeTimer_ConvertMs2Ticks(APPROXWORSTCASEFLASHWRITETIME);

      responsePendingSupervision.elapsedTime += FreeTimer_GetTimeInTicks();

      if ( (responsePendingSupervision.elapsedTime + approxFlashWriteTime) >=
                                     responsePendingSupervision.currentTimeOut )
      {
         Dcm_TimerP2xSettingType limitP2;       /* P2 timings from DCM module */

         /* get P2 timings from DCM module                                    */
         Dcm_GetCurrentSessionTimings(&limitP2.timeOutP2, &limitP2.timeOutP2Ex);
         /* initialise the current timeout to P2 or P2                        */
         responsePendingSupervision.currentTimeOut = FreeTimer_ConvertMs2Ticks
                                   ( ADJUST_TIMEOUT_P2EX(limitP2.timeOutP2Ex) );

         responsePendingSupervision.elapsedTime    =
                                       (FreeTimer_TimeInTicksType)TIMER_RESTART;

         /*
          * force the transmission of a response pending
          */
         Dcm_SendResponsePending(responsePendingSupervision.pCurrentMsgContext);
      }

      /* reinitilize the global initialization time                           */
      FreeTimer_StartTimeMeasurement();
   }
}
#endif /* (SC_NRV2B_ENABLE == STD_ON)                                             */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmReadDataByIdentifier                                **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 ReadDataByIdentifier (0x22)                                **
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
FUNC(void, DCM_APPL_CODE) Rte_DcmReadDataByIdentifier
                          (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void Rte_DcmReadDataByIdentifier
     (
	    Dcm_MsgContextType* const pMsgContext
	 )
#endif /* Defined BAC */
{
   /*
    * check request length: only one DataIdentifier (DId) is supported
    */
   if ( pMsgContext->reqDataLen == (uint16)2 )
   {
      /*
       * get DataIdentifier (DId) of the pending 'ReadDataByIdentifier' request.
       * store global for possible use in post handler
       */
      pendingDiagContext.DataOrRoutineId = Make16Bit
                                              ( pMsgContext->reqData[0],
                                                pMsgContext->reqData[1]
                                              );

      /* dispatch between the different DataIdentifiers                       */
      switch (pendingDiagContext.DataOrRoutineId)
      {
         case DIAG_DID_100A_VSM_OPERATION_MODE:
            ApplDcmReadDataByIdentifierEnergyState(pMsgContext);
            break;
         case DIAG_DID_100E_VSM_OPERATION_MODE_EXTENSION:
            ApplDcmReadDataByIdentifierEnergyStateExtension(pMsgContext);
            break;
         case DIAG_DID_1720_STANDARD_CORE_VERSION:
            ApplDcmReadDataByIdentifierStandardCoreVersion(pMsgContext);
            break;
         case DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE:
            ApplDcmReadDataByIdentifierMemorySegmentationTable(pMsgContext);
            break;
         case DIAG_DID_2502_PROG_COUNTER:
            ApplDcmReadDataByIdentifierProgrammingCounter(pMsgContext);
            break;
         case DIAG_DID_2503_PROG_COUNTER_MAX_VALUE:
            ApplDcmReadDataByIdentifierProgrammingCounterMaxValue(pMsgContext);
            break;
         case DIAG_DID_2504_FLASH_TIMING_PARAMS:
            ApplDcmReadDataByIdentifierTimingParameters(pMsgContext);
            break;
         case DIAG_DID_2506_READ_MEMORY_ADDRESS:
            ApplDcmReadDataByIdentifierReadMemoryAddress(pMsgContext);
            break;
         case DIAG_DID_F101_SVK_AKTUELL:
            ApplDcmReadDataByIdentifierSvkCurrent(pMsgContext);
            break;
         case DIAG_DID_F102_SVK_SYSTEM_SUPPLIER:
            ApplDcmReadDataByIdentifierSvkSystemSupplier(pMsgContext);
            break;
         case DIAG_DID_F103_SVK_PLANT:
            ApplDcmReadDataByIdentifierSvkPlant(pMsgContext);
            break;
         case DIAG_DID_F186_ACTIVE_DIAG_SESSION:
            ApplDcmReadDataByIdentifierActiveDiagSession (pMsgContext);
            break;
         case DIAG_DID_F18B_ECU_MANUFACTURING_DATA:
            ApplDcmReadDataByIdentifierEcuManufacturingData(pMsgContext);
            break;
         case DIAG_DID_F18C_ECU_SERIAL_NUMBER:
            ApplDcmReadDataByIdentifierEcuSerialNumber(pMsgContext);
            break;
         case DIAG_DID_F190_VIN:
            ApplDcmReadDataByIdentifierVin(pMsgContext);
            break;
         default:
            if ( (pendingDiagContext.DataOrRoutineId >=
                                   (uint16)DIAG_DID_3000_CODING_BLOCK_RANGE_MIN)
                 &&
                 (pendingDiagContext.DataOrRoutineId <=
                                         (uint16)DIAG_DID_37FE_CODING_TESTSTAMP)
               )
            {
               Dcm_SetNegResponse(pMsgContext, DCM_NRC_CONDITIONSNOTCORRECT);
            }
            else if ( (pendingDiagContext.DataOrRoutineId >=
                      (uint16)DIAG_DID_F104_SVK_BACKUP_MIN)
                      &&
                      (pendingDiagContext.DataOrRoutineId <=
                      (uint16)DIAG_DID_F140_SVK_BACKUP_MAX)
                    )
            {
               ApplDcmReadDataByIdentifierSvkBackup(pMsgContext, pendingDiagContext.DataOrRoutineId);
            }
            else
            {
               Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
            }
            break;
      }
   }
   else
   {
      if ( (pMsgContext->reqDataLen == (uint16)0u) ||
           ((pMsgContext->reqDataLen & (uint16)1u) == (uint16)1u)
         )
      {
         /* Invalid message length                                            */
         Dcm_SetNegResponse ( pMsgContext,
                              DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                            );
      }
      else
      {
         /* Too many DIDs                                                     */
         Dcm_SetNegResponse ( pMsgContext,
                              DCM_NRC_REQUESTOUTOFRANGE
                            );
      }
      /* send ProcessingDone in either cases, even if paged processing is used*/
      Dcm_ProcessingDone(pMsgContext);
      return;
   }

#if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
   if ( !( (pendingDiagContext.DataOrRoutineId   ==
                             (uint16)DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE) ||
           (pendingDiagContext.DataOrRoutineId  ==
                            (uint16)DIAG_DID_F101_SVK_AKTUELL)                ||
           (pendingDiagContext.DataOrRoutineId   ==
                            (uint16)DIAG_DID_F102_SVK_SYSTEM_SUPPLIER)        ||
           (pendingDiagContext.DataOrRoutineId   ==
                            (uint16)DIAG_DID_F103_SVK_PLANT)                  ||
           ( (pendingDiagContext.DataOrRoutineId >=
                                   (uint16)DIAG_DID_F104_SVK_BACKUP_MIN)      &&
             (pendingDiagContext.DataOrRoutineId <=
                                   (uint16)DIAG_DID_F140_SVK_BACKUP_MAX)
           )
         )
       )
#endif
   {
      Dcm_ProcessingDone(pMsgContext);
   }
} /* end of function 'Rte_DcmReadDataByIdentifier'                            */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmWriteDataByIdentifier                               **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 WriteDataByIdentifier (0x2E)                               **
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
FUNC(void, DCM_APPL_CODE) Rte_DcmWriteDataByIdentifier
                          (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void Rte_DcmWriteDataByIdentifier
     (
	    Dcm_MsgContextType* const pMsgContext
	 )
#endif /* Defined BAC */
{
   if ( pMsgContext->reqDataLen >= (uint16)2 )
   {
      /*
       * get DataIdentifier (DId) of the pending 'WriteDataByIdentifier' request,
       * store global for possible use in post handler
       */
      pendingDiagContext.DataOrRoutineId = Make16Bit
                                              (
                                                pMsgContext->reqData[0],
                                                pMsgContext->reqData[1]
                                              );

      /* dispatch between the different DataIdentifiers                       */
      switch (pendingDiagContext.DataOrRoutineId)
      {
         case DIAG_DID_F15A_FINGERPRINT:
            ApplDcmWriteDataByIdentifierFingerprint(pMsgContext);
            break;
         case DIAG_DID_F190_VIN:
            ApplDcmWriteDataByIdentifierVin(pMsgContext);
            break;
         default:
            if ( (pendingDiagContext.DataOrRoutineId >=
                                   (uint16)DIAG_DID_3000_CODING_BLOCK_RANGE_MIN)
                 &&
                 (pendingDiagContext.DataOrRoutineId <=
                                         (uint16)DIAG_DID_37FE_CODING_TESTSTAMP)
               )
            {
               Dcm_SetNegResponse(pMsgContext, DCM_NRC_CONDITIONSNOTCORRECT);
            }
            else
            {
               Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
            }
            break;
      }
   }
   else
   {
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );
   }

   Dcm_ProcessingDone(pMsgContext);
} /* end of function 'Rte_DcmWriteDataByIdentifier'                           */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmRoutineControl                                      **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RoutineControl (0x31)                                      **
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
FUNC(void, DCM_APPL_CODE) Rte_DcmRoutineControl
						  (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void Rte_DcmRoutineControl
     (
	    Dcm_MsgContextType* const pMsgContext
     )
#endif /* Defined BAC */
{
   /* request length check                                                    */
   if ( pMsgContext->reqDataLen > (uint16)2 )
   {
      pendingDiagContext.SubFunction     = pMsgContext->reqData[0];

      pendingDiagContext.DataOrRoutineId = Make16Bit
                                              (
                                                pMsgContext->reqData[1],
                                                pMsgContext->reqData[2]
                                              );

      switch (pendingDiagContext.SubFunction)
      {
         /******** START ROUTINE **********************************************/
         case DIAG_UDS31_01_START_ROUTINE:
            switch (pendingDiagContext.DataOrRoutineId)
            {
               case DIAG_RID_0202_CHECK_MEMORY:
                  ApplDcmRoutineControlCheckMemory(pMsgContext);
                  break;
               case DIAG_RID_0204_READ_SWE_PROGRAMMING_STATUS:
                  ApplDcmRoutineControlReadSWEProgrammingStatus(pMsgContext);
                  break;
               case DIAG_RID_0205_READ_DEVELOPMENT_INFO:
                  ApplDcmRoutineControlReadDevelopmentInfo(pMsgContext);
                  break;
#if ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON))
               case DIAG_RID_0302_STANDARD_CORE_TEST:
                  BootTest_DcmStartRoutine(pMsgContext);
                  break;
#endif /* (BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON)        */
               case DIAG_RID_0F0C_SET_VSM_OPERATION_MODE:
                  ApplDcmRoutineControlSetVsmOperationMode(pMsgContext);
                  break;
               case DIAG_RID_1003_SET_VSM_OPERATION_MODE_EXTENSION:
                  ApplDcmRoutineControlSetVsmOperationModeExtension(pMsgContext);
                  break;
               case DIAG_RID_FF00_ERASE_MEMORY:
                  ApplDcmRoutineControlEraseMemory(pMsgContext);
                  break;
               case DIAG_RID_FF01_CHECK_REPROGRAMMING_DEPENDENCIES:
                  ApplDcmRoutineControlCheckProgrammingDependencies(pMsgContext);
                  break;
               default:
                  /* 'routineIdentifier' not supported                        */
                  Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
                  break;
            }  /* switch(pendingDiagContext.DataOrRoutineId)                  */
            break;
         /******** STOP ROUTINE ***********************************************/
         case DIAG_UDS31_02_STOP_ROUTINE:
#if ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON))
            switch (pendingDiagContext.DataOrRoutineId)
            {
               case DIAG_RID_0302_STANDARD_CORE_TEST:
                  BootTest_DcmStopRoutine(pMsgContext);
                  break;
               default:
                  Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
                  break;
            }
            break;
#endif /* (BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON)        */
            /* stop routine not supported                                     */
            /* no break;                                                      */
         /******** REQUEST RESULT *********************************************/
         case DIAG_UDS31_03_REQUEST_RESULT:
#if ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON))
            switch (pendingDiagContext.DataOrRoutineId)
            {
               case DIAG_RID_0302_STANDARD_CORE_TEST:
                  BootTest_DcmRequestResult(pMsgContext);
                  break;
               default:
                  Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);
                  break;
            }
            break;
#endif /* (BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON)        */
            /* request routine result not supported                           */
            /* no break;                                                      */
         /*********************************************************************/
         default:
            Dcm_SetNegResponse(pMsgContext, DCM_NRC_SUBFUNCTIONNOTSUPPORTED);
            break;
      } /* SubFunction switch                                                 */
   }
   else
   {
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );
   }

   Dcm_ProcessingDone(pMsgContext);
} /* end of function 'Rte_DcmRoutineControl'                                  */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmRequestDownload                                     **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 RequestDownload (0x34)                                     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : sharedBootROMData                                          **
**                 ReprogrammingParams                                        **
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
FUNC(void, DCM_APPL_CODE) Rte_DcmRequestDownload
						  (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void Rte_DcmRequestDownload
     (
	   Dcm_MsgContextType* const pMsgContext
	 )
#endif /* Defined BAC */
{
   uint8                     FlashSegmentNumber;

   /*
    * The next values are initialized to avoid the causeless MISRA warning
    * Rule 30
    */
   uint8                     lastFlashSegment = (uint8)0x00u;
   uint8                     ApplSWENumber    = (uint8)0x00u;

   uint8_least               iLoop;       /* temporary loop variable          */
   boolean                   addressOk;   /* Contains result of address check */
   GetFlashSegmentNumberType GetFlashSegmentNumberRetVal;

   /* Cache the response data pointer                                         */
   Dcm_MsgType resDataPtr;

   Dcm_NegativeResponseCodesType ResponseCode;

   /** check preconditions                                                   **/

   /*
    * service 'RequestDownload' is only possible in unlocked programming
    * session because of GENy configuration for DCM
    */

   /* Check if download is not accepted                                       */
   if ( (activeSubSession == PROG_BOOT_UNLOCKED) ||
        (activeSubSession == PROG_BOOT_MEMORY_ERASE_FAILED)
      )
   {
      /* incorrect preconditions                                              */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_UPLOADDOWNLOADNOTACCEPTED);

      /* send response                                                        */
      Dcm_ProcessingDone(pMsgContext);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* Check subSession state                                                  */
   if ( (activeSubSession != PROG_BOOT_MEMORY_ERASED)     &&
        (activeSubSession != PROG_BOOT_MEMORY_CHECKED)    &&
        (activeSubSession != PROG_BOOT_DOWNLOAD_FINISHED) &&
        (activeSubSession != PROG_BOOT_DOWNLOAD_STARTED)    /* LowLevel retry */
      )
   {
      /* incorrect preconditions                                              */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTSEQUENCEERROR);

      /* send response                                                        */
      Dcm_ProcessingDone(pMsgContext);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* Data length check:                                                      */
   /* 1 Byte dataFormatId + 1 Byte ALFI                                       */
   if ( pMsgContext->reqDataLen < (uint16)2 )
   {
      /* send neg. response because of wrong request length                   */
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );

      /* send response                                                        */
      Dcm_ProcessingDone(pMsgContext);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* preconditions are correct                                               */

   /* check dataFormatIdentfier                                               */
   ReprogrammingParams.dataFormatIdentfier = pMsgContext->reqData[0];
   switch(ReprogrammingParams.dataFormatIdentfier)
   {
#if (SC_NONCOMPRESSED_ENABLE == STD_ON)
      case DFI_NOTCOMPRESSED_NOTENCRYPTED:
#endif /* SC_NONCOMPRESSED_ENABLE == STD_ON                                       */
#if (SC_NRV2B_ENABLE == STD_ON)
      case DFI_NRV2B_COMPRESSED_NOTENCRYPTED:
#endif /* (SC_NRV2B_ENABLE == STD_ON)                                             */
         /* supported dataFormatIdentfier: nothing to do                      */
         break;
      default:
         /* send neg. response because of a unsupported dataFormatIdentfier   */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);

         /* send response                                                     */
         Dcm_ProcessingDone(pMsgContext);

         /* return is used for faster execution and decrease nesting depth    */
         return;
   }

   /*
    * Get the address and length of the request.
    * Data length check:
    * 1 Byte dataFormatId + 1 Byte ALFI + <address> + <length>
    */
   ResponseCode = GetAddressAndLengthByFormatIdentifier
      ( &pMsgContext->reqData[1],
        (uint8)(pMsgContext->reqDataLen - 2u),
        (uint8)DIAG_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER,
        &ReprogrammingParams.memStartAddress,
        &ReprogrammingParams.memEndAddress
      );

   /* check memoryAddress and memorySize from request                         */
   if ( (ResponseCode == DCM_NRC_OK) &&
        (
          ( (ReprogrammingParams.memStartAddress %
                 (flashAddress_t)FLASH_DEST_ADDR_ALIGN
            ) != (flashAddress_t)0
          )
          ||
          ( (ReprogrammingParams.memEndAddress %
                 (flashAddress_t)FLASH_PAGE_SIZE
            ) != (flashAddress_t)0
          )
          ||
          (ReprogrammingParams.memEndAddress == (flashAddress_t)0u)
        )
      )
   {
      ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }

   if ( ResponseCode != DCM_NRC_OK )
   {
      /* Set negative response                                                */
      Dcm_SetNegResponse(pMsgContext, ResponseCode);
      Dcm_ProcessingDone(pMsgContext);

      /* return is used here to decrease nesting depth                        */
      return;
   }

   ReprogrammingParams.memEndAddress += ReprogrammingParams.memStartAddress -
                                        (flashAddress_t)1u;
                                         /* Calculate end address of          */
                                         /* requested memory block            */

   GetFlashSegmentNumberRetVal =
      GetFlashSegmentNumberByMemAddress ( &ReprogrammingParams.memStartAddress,
                                          &FlashSegmentNumber
                                        );

   if ( GetFlashSegmentNumberRetVal == ADDRESS_FOUND_FLASH_SEGMENT_BORDER )
   {
      addressOk = GetApplSWENumberByFlashSegmentNumber ( &FlashSegmentNumber,
                                                         &ApplSWENumber
                                                       );
      if ( addressOk == TRUE )
      {
         flashAddress_t nextStartAddress =
                           sharedBootROMData.MemSegTable[FlashSegmentNumber][0];

         /*
          * Keeps the number of the first flash segment of the current SWE
          */
         const uint8 firstFlashSegment =
                       sharedBootROMData.SweSegmentIndexAppl[ApplSWENumber] +
                       (uint8)FLASH_SEGMENT_NUMBER_BOOT;
         /*
          * Keeps the number of the last flash segment of the current SWE
          */
         lastFlashSegment =
                        firstFlashSegment                                     +
                        sharedBootROMData.SweSegmentNumberAppl[ApplSWENumber] -
                        (uint8)1;

         iLoop     = (uint8_least)FlashSegmentNumber;
         addressOk = FALSE;
         do
         {
            CONSTP2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                    pMemStartAddress = &sharedBootROMData.MemSegTable[iLoop][0];
            CONSTP2CONST(flashAddress_t, AUTOMATIC, SHAREDBOOTROMDATA_CONST)
                    pMemEndAddress = &sharedBootROMData.MemSegTable[iLoop][1];

            if ( *pMemStartAddress == nextStartAddress )
            {
               if ( *pMemEndAddress == ReprogrammingParams.memEndAddress )
               {
                  /* valid end address of this request download found         */
                  addressOk = TRUE;
               }
               else
               {
                  nextStartAddress = *pMemEndAddress + (flashAddress_t)1;
                  ++iLoop;
               }
            }
            else
            {
               /*
                * A gap was found inbetween the memory segments:
                * It is not allowed to programm accross gaps ==> NRC
                */
               ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
            }
         } while ( (addressOk    != TRUE)       &&
                   (ResponseCode == DCM_NRC_OK) &&
                   (iLoop        <= (uint8_least)lastFlashSegment)
                 );
         /*
          * Check if a valid EndAddress was found
          */
         if ( addressOk != TRUE )
         {
            /*
             * No valid EndAddress was found within this SWE ==> NRC
             */
            ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
         }
         else
         {
            lastFlashSegment = (uint8)iLoop;
         }
      }
      else
      {
         ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
      }
   }
   else
   {
      /*
       * 'memStartAddress' is not on an flash segment border:
       */
      ResponseCode = DCM_NRC_REQUESTOUTOFRANGE;
   }

   if ( ResponseCode == DCM_NRC_OK )
   {
      /*
       * Check the FlashSegmentStatus of the flash segments to be written
       * for 'NOT_WRITABLE'
       */
      iLoop = (uint8_least)FlashSegmentNumber;
      do
      {
         /*
          * Violation: MISRA Rule 4:
          * The expression 'iLoop - FLASH_SEGMENT_NUMBER_BOOT' can't be
          * negative
          */
         const uint8 currentStatus = GET_BIT_IN_MULTI_BYTE_BIT_ARRAY
                        ( BootProgStatus.FlashSegmentStatus,
                          (uint8)((uint8)iLoop -
                                  (uint8)FLASH_SEGMENT_NUMBER_BOOT)
                        );

         if ( currentStatus != (uint8)FLASH_SEGMENT_STATUS_WRITABLE )
         {
            /* Set negative response                                       */
            ResponseCode = DCM_NRC_UPLOADDOWNLOADNOTACCEPTED;
         }
         else
         {
            ++iLoop;
         }
      } while ( (ResponseCode == DCM_NRC_OK) &&
                (iLoop <= (uint8_least)lastFlashSegment)
              );

      if ( ResponseCode == DCM_NRC_OK )
      {
         /*
          * Set the SWEProgrammingStatus to
          * 'PROGSTAT_DATATRANSFERSTARTED'
          */
         BootProgStatus.SWEProgrammingStatus[ ApplSWENumber + (uint8)SWE_ID_OF_APPL_SWE1 ] =
            (uint8)PROGSTAT_DATATRANSFERSTARTED;

         /* save the blocknummber in EEPROM                                */
         BootProgStatus.lastProgrammedSegment = FlashSegmentNumber;

         /* write the changed BootProgStatus to NV memory                  */
         if ( OperateNvData( NVM_DIAG_BOOTPROGSTATUS,
                             NV_WRITE_OPERATION) != TRUE
                           )
         {
            /* Set negative response                                       */
            ResponseCode = DCM_NRC_GENERALPROGRAMMINGFAILURE;
         }
      }
   }

   /*
    * If the requested memory block is located within a valid block ...
    */
   if ( ResponseCode == DCM_NRC_OK )
   {
      /* Set counter of downloaded data blocks to initial value               */
      ReprogrammingParams.transmittedBlocks = (uint8)BSC_INIT_VALUE;

#if (SC_NRV2B_ENABLE == STD_ON)
      if ( ReprogrammingParams.dataFormatIdentfier ==
                                      (uint8)DFI_NRV2B_COMPRESSED_NOTENCRYPTED )
      {
         /*
          * Check if nrv2bTempBuffer is aligend to flash driver access
          * boundaries
          */
         uint8_least AlignOffset =
            CalculateAlignOffset((uint32)&nrv2bCtrl.nrv2bTempBuffer[0], FLASH_SRC_ADDR_ALIGN);

         nrv2bCtrl.nrv2bTempBufferPtr = &nrv2bCtrl.nrv2bTempBuffer[AlignOffset];

         /*
          * The source buffer will be reinitialized at every
          * 'TransferData', because it cannot be guaranteed that buffer
          * and lenght do not change during the different Requests.
          */
         nrv2bStream_Init
            ( (P2CONST(uint8,  AUTOMATIC, NRV2BS_APPL_DATA)) &pMsgContext->reqData[1],
              (    VAR(uint16, AUTOMATIC))((uint16)FLASH_BLOCK_LEN - (uint16)2),
              (  P2VAR(uint8,  AUTOMATIC, NRV2BS_APPL_DATA)) nrv2bCtrl.nrv2bTempBufferPtr,
              (    VAR(uint16, AUTOMATIC))               NRV2B_TEMP_BUFFER_SIZE,
              (P2CONST(uint8,  AUTOMATIC, NRV2BS_APPL_DATA)) ConvertExtAddress2IntPointer
                 (
                    ReprogrammingParams.memStartAddress
                 )
            );
      }
#endif /* (SC_NRV2B_ENABLE == STD_ON)                                             */

      /* set new state                                                        */
      activeSubSession = PROG_BOOT_DOWNLOAD_STARTED;

      resDataPtr = &pMsgContext->resData[0];

      /* length format identifier: 1 byte                                     */
      *resDataPtr++ = (uint8)DIAG_LENGTH_FORMAT_IDENTIFIER;

#if (DIAG_LENGTH_FORMAT_IDENTIFIER != 0x40u)
   #error "bootdiag.c: invalid 'DIAG_LENGTH_FORMAT_IDENTIFIER'"
#endif

      /* Set maximum number of block length (MXBL) into response message      */
      *resDataPtr++ = Dcm_GetHiHiByte((flashAddress_t)FLASH_BLOCK_LEN);
      *resDataPtr++ = Dcm_GetHiLoByte((flashAddress_t)FLASH_BLOCK_LEN);
      *resDataPtr++ = Dcm_GetLoHiByte((flashAddress_t)FLASH_BLOCK_LEN);
      *resDataPtr   = Dcm_GetLoLoByte((flashAddress_t)FLASH_BLOCK_LEN);
      /* Set length of response                                               */
      pMsgContext->resDataLen = (uint16)1 + (uint16)DIAG_SIZEOF_OF_LENGTH_PARAM;
   }
   else
   {
      /*
       * Wrong start address or length or error during EEP-access:
       * Set negative response
       */
      Dcm_SetNegResponse(pMsgContext, ResponseCode);
   }

   /* Send response                                                           */
   Dcm_ProcessingDone(pMsgContext);
} /* end of function 'Rte_DcmRequestDownload'                                 */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmTransferData                                        **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 Rte_DcmTransferData (0x36)                                 **
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
FUNC(void, DCM_APPL_CODE) Rte_DcmTransferData
						  (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void Rte_DcmTransferData
     (
	    Dcm_MsgContextType* const pMsgContext
	 )
#endif /* Defined BAC */
{
   static uint8            retransmissionCounter = (uint8)0;
   static uint8            retransmissionBSC     = (uint8)0;

#ifdef BAC
   P2CONST(uint8,          AUTOMATIC, DCM_APPL_DATA) pBlockSequenceCounter;
   P2CONST(Dcm_MsgLenType, AUTOMATIC, DCM_APPL_DATA) pReqDataLen;
#else
   const  uint8          * pBlockSequenceCounter;
   const  Dcm_MsgLenType * pReqDataLen;
#endif /* Defined BAC */
   /* Cache the request pointer                                               */
   Dcm_MsgType                   reqDataPtr;
   Dcm_MsgLenType                payLoadLength;
   Dcm_NegativeResponseCodesType ResponseCode;

   /** check preconditions                                                   **/

   /*
    * service 'TransferData' is only possible in unlocked programming
    * session because of geny configuration for DCM
    */

   /* check if download was started or TransferData is active                 */
   if ( (activeSubSession != PROG_BOOT_TRANSFER_DATA) &&
        (activeSubSession != PROG_BOOT_DOWNLOAD_STARTED)
      )
   {
      /* incorrect preconditions                                              */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTSEQUENCEERROR);

      /* send response                                                        */
      Dcm_ProcessingDone(pMsgContext);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   pReqDataLen = &pMsgContext->reqDataLen;

   /* data length check: part 1                                               */
   if ( (*pReqDataLen < (uint16)1) ||
        (*pReqDataLen > ((uint16)FLASH_BLOCK_LEN - (uint16)1) )
      )                                                       /* - 1 Byte SID */
   {
      /* send neg. response because of wrong request length                   */
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );

      /* send response                                                        */
      Dcm_ProcessingDone(pMsgContext);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* data length check: part 2                                               */
   if ( *pReqDataLen == (uint16)1 )
   {
      /* send neg. response because of wrong request length                   */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTOUTOFRANGE);

      /* send response                                                        */
      Dcm_ProcessingDone(pMsgContext);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /** preconditions are correct                                             **/

   pBlockSequenceCounter = &pMsgContext->reqData[0];
   reqDataPtr            = &pMsgContext->reqData[1];
   payLoadLength         = (*pReqDataLen - (Dcm_MsgLenType)1);

   if ( (uint8)(ReprogrammingParams.transmittedBlocks + (uint8)1) ==
                                                        *pBlockSequenceCounter )
   {
      retransmissionCounter = (uint8)0;
      retransmissionBSC     = *pBlockSequenceCounter;

      switch (ReprogrammingParams.dataFormatIdentfier)
      {
#if (SC_NONCOMPRESSED_ENABLE == STD_ON)
         case DFI_NOTCOMPRESSED_NOTENCRYPTED:
            ResponseCode = ApplDcmTransferDataNotCompressedNotEncrypted
                              ( &reqDataPtr[0],
                                payLoadLength,
                                pMsgContext
                              );
            break;
#endif /* SC_NONCOMPRESSED_ENABLE == STD_ON                                       */
#if (SC_NRV2B_ENABLE == STD_ON)
         case DFI_NRV2B_COMPRESSED_NOTENCRYPTED:
            ResponseCode = ApplDcmTransferDataNrvCompressedNotEncrypted
                              ( &reqDataPtr[0],
                                payLoadLength,
                                pMsgContext
                              );
            break;
#endif /* (SC_NRV2B_ENABLE == STD_ON)                                             */
         default:
            /*
             * Send neg. response because of a unsupported
             * 'dataFormatIdentfier' - this is a logical problem
             */
            ResponseCode = DCM_NRC_CONDITIONSNOTCORRECT;
      }

      switch (ResponseCode)
      {
         case DCM_NRC_OK:
            activeSubSession = PROG_BOOT_TRANSFER_DATA;

            pMsgContext->resData[0] = *pBlockSequenceCounter;
                                                /* Set number of downloaded   */
                                                /* and programmed data blocks */

            /* BSC OK - increment it                                          */
            ++ReprogrammingParams.transmittedBlocks;

            pMsgContext->resDataLen = (uint16)1;       /* Set length of resp. */
            break;
         case DCM_NRC_TRANSFERDATASUSPENDED:
         case DCM_NRC_GENERALPROGRAMMINGFAILURE:
            /*
             * A critical failure occured in 'ApplDcmTransferDataXXX':
             * The transmission must be restarted ('Wiederaufsetzen') by a
             * restart of the ProgrammingSession
             */
            activeSubSession = PROG_BOOT_TRANSFER_DATA_FAILED;
            Dcm_SetNegResponse(pMsgContext, ResponseCode);
            break;
         default:
            /* A noncritical failure occured in 'ApplDcmTransferDataXXX'      */
            #if (SC_NRV2B_ENABLE == STD_ON)
               if ( ReprogrammingParams.dataFormatIdentfier ==
                                      (uint8)DFI_NRV2B_COMPRESSED_NOTENCRYPTED )
               {
                  /*
                   * When compression is used, the transmission must be
                   * restarted ('Wiederaufsetzen') by a restart of the
                   * ProgrammingSession.
                   * When compression is not used, the sub-session status is not
                   * changed.
                   */
                  activeSubSession = PROG_BOOT_TRANSFER_DATA_FAILED;
               }
            #endif /* (SC_NRV2B_ENABLE == STD_ON)                                 */
            Dcm_SetNegResponse(pMsgContext, ResponseCode);
            break;
      }
   }
   else
   {
      /*
       * Check for a retransmission of one of the last blocks:
       * (max 'BSC_MAX_FALLBACK' is allowed)
       */
      uint8 offsetOfBSC;

      /* calculate the offset of the two BSC                                  */
      if ( *pBlockSequenceCounter <= ReprogrammingParams.transmittedBlocks )
      {
         offsetOfBSC  = ReprogrammingParams.transmittedBlocks;
         offsetOfBSC -= *pBlockSequenceCounter;
      }
      else
      {
         offsetOfBSC  = (uint8)0xFFu;
         offsetOfBSC -= *pBlockSequenceCounter;
         offsetOfBSC += ReprogrammingParams.transmittedBlocks + (uint8)1;
      }

      if ( offsetOfBSC <= (uint8)BSC_MAX_FALLBACK )
      {
         /*
          * check FP_5392: number retransmissions of the same BSC.
          * 'ReprogrammingParams.transmittedBlocks' can not be used for the
          * check because it is not updated on retransmission of an block from
          * the past.
          */
         if ( retransmissionBSC == *pBlockSequenceCounter )
         {
            ++retransmissionCounter;
            if ( retransmissionCounter > (uint8)BSC_MAX_RETRANSMISSIONS )
            {
               /* send neg. response because of wrong block sequence counter  */
               Dcm_SetNegResponse(pMsgContext, DCM_NRC_WRONGBLOCKSEQUENCECOUNTER);

               Dcm_ProcessingDone(pMsgContext);
               return;
            }
         }

         retransmissionBSC = *pBlockSequenceCounter;

         /*
          * This is a retransmission of one the last blocks ==> send positive
          * response without programming of this block:
          * Response with the BSC from the request.
          * (redundant if (reqData == resData)
          */
         pMsgContext->resData[0] = *pBlockSequenceCounter;

         pMsgContext->resDataLen = (uint16)1;      /* Set length of response  */
      }
      else
      {
         /* send neg. response because of wrong wrong block sequence counter  */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_WRONGBLOCKSEQUENCECOUNTER);
      }
   }

   Dcm_ProcessingDone(pMsgContext);
} /* end of function 'Rte_DcmTransferData'                                    */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmRequestTransferExit                                 **
**                                                                            **
** DESCRIPTION   : Contains the functionality of the diag service             **
**                 Rte_DcmRequestTransferExit (0x37)                          **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : pMsgContext: pointer to diagnostic internal message        **
**                              data field. For more information see the      **
**                              DCM documentation.                            **
**                                                                            **
** INPUT:        : pMsgContext->reqData                                       **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       : ---                                                        **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) Rte_DcmRequestTransferExit
						  (
						     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
						  )
#else
void Rte_DcmRequestTransferExit
     (
	    Dcm_MsgContextType* const pMsgContext
	 )
#endif /* Defined BAC */
{
   /*
    * service 'RequestTransferExit' is only possible in unlocked programming
    * session because of geny configuration for DCM
    */

   /*
    * check if download was started (to cancel a running transmission) or
    * TransferData is active
    */
   if ( (activeSubSession != PROG_BOOT_TRANSFER_DATA)     &&
        (activeSubSession != PROG_BOOT_DOWNLOAD_FINISHED)   /* LowLevel retry */
      )
   {
      /* set negative response                                                */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_REQUESTSEQUENCEERROR);

      /* send response                                                        */
      Dcm_ProcessingDone(pMsgContext);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* data length check                                                       */
   if ( pMsgContext->reqDataLen != (uint16)0 )
   {
      /* send neg. response because of wrong request length                   */
      Dcm_SetNegResponse ( pMsgContext,
                           DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT
                         );

      /* send response                                                        */
      Dcm_ProcessingDone(pMsgContext);

      /* return is used for faster execution and decrease nesting depth       */
      return;
   }

   /* preconditions are correct                                               */

   /*
    * 'RequestTransferExit' can not be used to cancel a running transmission:
    * underflow check
    */
   if ( (ReprogrammingParams.memStartAddress - (flashAddress_t)1u) ==
                                             ReprogrammingParams.memEndAddress )
   {
      /*
       * Reprogramming finished at this point:
       * Save invalid block number in EEPROM
       */
      BootProgStatus.lastProgrammedSegment = (uint8)REPROGRAMMINGNOTVALIDADDRESS;

      /* Write to Nv memory and check for correct writting                    */
      if ( OperateNvData(NVM_DIAG_BOOTPROGSTATUS, NV_WRITE_OPERATION) != TRUE )
      {
         /*
          * Writing to Nv memory failed: set negative response
          */
         Dcm_SetNegResponse(pMsgContext, DCM_NRC_GENERALPROGRAMMINGFAILURE);
      }
      else
      {
         /* Set new programming status                                        */
         activeSubSession = PROG_BOOT_DOWNLOAD_FINISHED;

         /* Set length of response                                            */
         pMsgContext->resDataLen = (uint16)0;
      }
   }
   else
   {
      /* Set negative response according to FP_4553                           */
      Dcm_SetNegResponse(pMsgContext, DCM_NRC_CONDITIONSNOTCORRECT);
   }

   /* send response                                                           */
   Dcm_ProcessingDone(pMsgContext);
} /* end of function 'Rte_DcmRequestTransferExit'                             */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmGetSesChgPermission                                 **
**                                                                            **
** DESCRIPTION   : Check if the given session transition is allowed or your   **
**                 ECU is currently not able to perform it.                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - pMsgContext:                                             **
**                    - pointer to diagnostic internal message                **
**                      data field. For more information see the              **
**                      DCM documentation.                                    **
**                 - SesCtrlTypeActive:                                       **
**                    - Contains the current session state which the state    **
**                      group will left.                                      **
**                    - Access type: read                                     **
**                 - SesCtrlTypeNew:                                          **
**                    - Contains the new session state in which the state     **
**                      group will be set.                                    **
**                    - Access type: read                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : DCM_TRUE if the session is accepted, DCM_FALSE if not.     **
**                                                                            **
** REMARKS       : - The function "Dcm_SetNegResponse" may not be called.     **
**                 - The function "Dcm_ProcessingDone" may not be called.     **
**                                                                            **
*******************************************************************************/
/* Within BAC the function will be called with 2 parameters */
#ifdef BAC
FUNC(Dcm_StatusType, DCM_APPL_CODE) Rte_DcmGetSesChgPermission
									(
									   CONST(uint8, DCM_APPL_CONST) SesCtrlTypeActive,
									   CONST(uint8, DCM_APPL_CONST) SesCtrlTypeNew
									)
#else
Dcm_StatusType Rte_DcmGetSesChgPermission
               (
                  Dcm_MsgContextType* const pMsgContext,
                  const uint8 SesCtrlTypeActive,
                  const uint8 SesCtrlTypeNew
               )
#endif /* Defined BAC */
{
   Dcm_StatusType dcmSessionChangePermission = DCM_E_SESSION_NOT_ALLOWED;

   switch (SesCtrlTypeNew)
   {
      case DCM_SES_LEV_DEFAULT:
         /* request for default session                                       */
         switch (SesCtrlTypeActive)
         {
            case DCM_SES_LEV_PROGRAMMING:
            case DCM_SES_LEV_EXTENDED:
            case DCM_SES_LEV_DEFAULT:
               /* currently nothing else to do                                */
               dcmSessionChangePermission = DCM_E_OK;
               break;
            default:
               /* session change is not not allowed                           */
               break;
         }
         break;
      case DCM_SES_LEV_PROGRAMMING:
         /* request for programming session                                   */
         switch (SesCtrlTypeActive)
         {
            case DCM_SES_LEV_EXTENDED:
            case DCM_SES_LEV_PROGRAMMING:
               /*
                * FP_5738:
                * Restart of programming session
                * It is not allowed to send 0x00 .. 0x00 for indication of
                * authenticated programming session
                */

               /* set sec level to unauthenticated programming session in DCM */
               Dcm_SetSecurityLevel(DCM_SEC_LEV_LOCKED);

               /* session change is allowed                                   */
               dcmSessionChangePermission = DCM_E_OK;
               break;
            default:
               /* session change is not allowed                               */
               break;
         }
         break;
      case DCM_SES_LEV_EXTENDED:
         /* request for extended session                                      */
         switch (SesCtrlTypeActive)
         {
            case DCM_SES_LEV_DEFAULT:
            case DCM_SES_LEV_EXTENDED:
               /* currently nothing else to do                                */
               dcmSessionChangePermission = DCM_E_OK;
               break;
            default:
               /* session change is not not allowed                           */
               break;
         }
         break;
      default:
         /* session change is not not allowed                                 */
         break;
   }

   return dcmSessionChangePermission;
} /* end of function 'Rte_DcmGetSesChgPermission'                             */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmSesCtrlChangeIndication                             **
**                                                                            **
** DESCRIPTION   : Notification function for state change of the given        **
**                 state group, defined by CANdelaStudio.                     **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : ---                                                        **
**                                                                            **
** PARAMETER     : - SesCtrlTypeOld:                                          **
**                    - The old state which will be left.                     **
**                    - Access type: read                                     **
**                 - SesCtrlTypeNew:                                          **
**                    - The new state which will be set.                      **
**                    - Access type: read                                     **
**                                                                            **
** INPUT:        : ---                                                        **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : - The function "Dcm_ProcessingDone" may not be called.     **
**                 - The function "Dcm_SetNegResponse" may not be called.     **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) Rte_DcmSesCtrlChangeIndication
						  (
							 CONST(uint8, DCM_APPL_CONST) SesCtrlTypeOld,
							 CONST(uint8, DCM_APPL_CONST) SesCtrlTypeNew
						  )
#else
void Rte_DcmSesCtrlChangeIndication
	 (
	    const uint8 SesCtrlTypeOld,
        const uint8 SesCtrlTypeNew
	 )
#endif /* Defined BAC */
{
   switch (SesCtrlTypeNew)
   {
      case DCM_SES_LEV_DEFAULT:
         /* FP_1471: do not reset on DefaultSession self-transition           */
         if ( SesCtrlTypeOld != DCM_SES_LEV_DEFAULT )
         {
            /*
             * Deinitialize the Flash driver
             */
            (void)FlashDeInit();

            /*
             * Here we assume a TesterPresent timeout or a request by the tester
             * to switch in the application mode:
             * reset ECU
             */
            ResetECU();
         }
         break;
      case DCM_SES_LEV_PROGRAMMING:
         activeSubSession = PROG_BOOT_LOCKED;
         break;
      case DCM_SES_LEV_EXTENDED:
         activeSubSession = EXTENDED_BOOT;
         break;
      default:
         activeSubSession = ELSE_SUB_SESSION_STATE;
         break;
   }
} /* end of function 'Rte_DcmSesCtrlChangeIndication'                         */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmIndication                                          **
**                                                                            **
** DESCRIPTION   : Pre handler for all diag services                          **
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
#if (DCM_REQUEST_INDICATION_ENABLED != CONFIG_TRUE)
 #error "bootdiag.c: Wrong DCM configuration - DCM_REQUEST_INDICATION_ENABLED must be CONFIG_TRUE"
#endif
#ifdef BAC
FUNC(Dcm_StatusType, DCM_APPL_CODE) Rte_DcmIndication
									(
									   CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
									   CONST(uint8, DCM_APPL_CONST)                             SID
									)
#else
DcmStatusType Rte_DcmIndication
			  (
				 Dcm_MsgContextType* const pMsgContext,
				 const uint8               SID
			  )
#endif /* Defined BAC */
{
   /* indicate start of diagnostic processing                                 */
   #if (SC_LED_DEMO_ON == STD_ON)
      Led_Set(TP_ACTIVITY_LED);
   #endif

   /* in BAC the response and request buffer are seperated
      additionally Rte_InitRespPend will be called                            */
#ifdef BAC
   Rte_DcmIndication_Specific(pMsgContext, SID);
#endif

   /* store service-id for post handler                                       */
   pMsgContext->idContext = SID;

   return DCM_E_OK;
} /* end of function 'Rte_DcmIndication'                                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Rte_DcmConfirmation (Service request header:0xff )         **
**                                                                            **
** DESCRIPTION   : Post handler for all diag services                         **
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
** INPUT:        : pendingDiagContext.SubFunction                             **
**                 pendingDiagContext.DataOrRoutineId                         **
**                                                                            **
** RETURN        : ---                                                        **
**                                                                            **
** REMARKS       : - The function "Dcm_ProcessingDone" may not be called.     **
**                 - The function "Dcm_SetNegResponse" may not be called.     **
**                 - 'pMsgContext' can not be used here - it is released      **
**                   before call of 'Rte_DcmConfirmation'.                    **
**                                                                            **
*******************************************************************************/
#ifdef BAC
FUNC(void, DCM_APPL_CODE) Rte_DcmConfirmation
						  (
							 CONST(uint8, DCM_APPL_CONST)                      idContext,
							 CONST(uint8, DCM_APPL_CONST)                      dcmRxPduId,
							 CONST(Dcm_ConfirmationStatusType, DCM_APPL_CONST) status
						  )
#else
void Rte_DcmConfirmation
	 (
	    const uint8                      idContext,
		const uint8                      dcmRxPduId,
		const Dcm_ConfirmationStatusType status
	 )
#endif /* Defined BAC */
{
   switch(status)
   {
      case DCM_RES_POS_OK:
         /* ... positive response has been successfully sent.                 */
      case DCM_RES_NEG_OK:
         /* ... negative response has been successfully sent.                 */
         switch (idContext)
         {
            case DIAG_UDS11_SERVICE_ECU_RESET:
               ApplDcmConfirmationECUReset( status,
                                            pendingDiagContext.SubFunction
                                          );
               break;
            default:
               /* unknown service                                             */
               break;
         }
         break;
      case DCM_RES_POS_NOT_OK:
         /* ... positive response transmission has failed.                    */
      case DCM_RES_NEG_NOT_OK:
         /* ... negative response transmission has failed.                    */
      default:
         break;
   }

   /* indicate end of diagnostic processing                                   */
   #if (SC_LED_DEMO_ON == STD_ON)
      Led_Clear(TP_ACTIVITY_LED);
   #endif
} /* end of function 'Rte_DcmConfirmation'                                    */

#define BOOTDIAG_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
