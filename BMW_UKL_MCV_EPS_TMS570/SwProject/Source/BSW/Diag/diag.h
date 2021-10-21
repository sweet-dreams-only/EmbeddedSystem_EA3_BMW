/*******************************************************************************
**                                                                            **
**  SRC-MODULE: diag.h                                                        **
**                                                                            **
**  Copyright (C) BMW Group 2010                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Declaration of Subparameter macros of diagnostic services     **
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
** olgo         Oliver Gorisch             EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** cf           Christian Franke           EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
** gedr         Georg Drenkhahn            EB Automotive                      **
** ke           Kai Esbold                 EB Automotive                      **
** cest         Celine Stenzel             EB Automotive                      **
** cma          Chr. Mueller-Albrecht      BMW                                **
** jetc         Jean-Jacques Tchouto       EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** anam         Andreas Amann              MB Technology                      **
** anht         Andreas Hartmann           EB Automotive                      **
** ft           Florian Tausch             MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V6.0.4: 07.09.2010,   ft: CR70737: added missing compiler abstraction
 * V6.0.3: 22.04.2010, anht: CR61839/CR70426: added support for ASC3.x / make common
 *                                            files between Bac and Sc6
 * V6.0.2: 20.04.2010, anam: CR70288: Change storage classes in compiler abstraction for Diag
 * V6.0.1: 03.06.2009, hauf: CR61622: added application specific includes
 * V6.0.0: 03.09.2008, olgo: CR61431: separated independent diag types for BM
 *         18.08.2008, dabu: CR61347: changed Application Extended Session
 *                                    handling according LH FP part 5 v09
 * V5.0.0: 31.10.2006, miwe: CR60592: moved data from unpaged to paged RAM
 *         31.10.2006, olgo: CR60654: Adaptation of DiagSetCommunicationMode()
 *         12.10.2006, miwe: MISRA checked
 *         01.10.2006, olgo: delayed positive response handling of ecu reset an
 *                           session change to programming session request
 *                           + EcuResetHandlingType added
 *         11.09.2006, olgo: CR60309: prepare for SWT session
 *         28.09.2006, miwe: adaptions according to LH FP v07:
 *                           - renamed DiagService 'ReadSweDevelopmentInfo' to
 *                             'ReadDevelopmentInfo'
 *                           - added 'SetVsmOperationModeExtension' to
 *                             Bootloader
 *                           - 'ProgrammingPreConditionType' added
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
 *                           - renamed ReadDataById(ProgrammingStatus) to
 *                             ReadDataById(ReadMemoryAddress)
 *                           - implemented preassigned address and length format
 *                             identifier according to FP_5871
 *                           - process classes altered
 *         18.08.2006, jetc: added memory map section extension
 * V4.0.1: 09.08.2006, dabu: CR60688: neg.Resp. if SVK-Plant with initial values
 * V4.0.0: 21.06.2006, olgo: CR60584: if an BLU was found check only programming
 *                                    status of SWE1
 * V3.0.0: 05.05.2006, cma : DIAG_DID_1726_STANDARD_CORE_MODULE_VERSIONS added
 *         20.04.2006, miwe: + defines for Fingerprint added
 *                           + defines for addressControlInfo added
 *                           + renamed parameter of
 *                             'ApplDcmReadDataByIdentifierActiveDiagSession'
 *         31.03.2006, cma : macro DIAG_ENDIANESS_FITS added
 *                           (for code size optimization)
 *         23.03.2006, ke  : integrate updated crypto modules
 *         17.03.2006, hauf: moved diag specific typedefs from sc_types.h
 *         16.03.2006, cma : version number of c and h adapted, reformated
 *         10.03.2006, miwe: MISRA checked
 *         09.03.2006, miwe: (optional) SVK backup implemented
 *         08.03.2006, dabu: CR60445: paged buffer processing implemented
 *         01.03.2006, cest: CR60464: only if DM_TEST is ON:
 *                           add #define DIAG_DID_1723_IS_DTC_ACTIVE_RESPONSE
 *                               #define DIAG_DID_1724_IS_DTC_LOCKABLE
 *         01.03.2006, ke  : add #define DIAG_RID_020F_CSM_F70
 *         27.02.2006, miwe: DCM splitted task concept (task decoupling)
 *         16.02.2005, dabu: CR60480: Implementaion of an extended op-mode
 *         06.02.2006, dabu: Bootloader adaptions according to LH FP v05:
 *                           + added 'R.D.B.Id.ECUMANUFACTURINGDATA' (0xF18B)
 *                     miwe: + 'MemSegTable' is shared between APPL & BL =>
 *                             moved to BOOTADDRESSTABLE section
 *                           + 'CheckProgDepStatus' added
 *         01.02.2006, dabu: CR60419: added 'R.D.B.Id.ECUID' (0xF18C)
 * V2.4.0: 20.12.2005, mm  : macro name for reprogramming dependencies changed
 * V2.3.0: 16.12.2005, miwe: ForceResponsePending Hotfix
 * V2.2.1: 07.12.2005, gedr: CR60418: added RoutineControl-DM_TEST
 * V2.2.0: 02.12.2005, dabu: CR60121: added RoutineControl-WATCHDOG_TRIGGER_STOP
 * V2.1.0: 28.11.2005, miwe: SCTestService Ids added,
 *                           CR60304: moved 'R.D.B.Id.StandardCoreVersion' to
 *                           'diag.c/-h'
 * V2.0.2: 03.11.2005, cf  : Misra check
 * V2.0.1: 31.10.2005, miwe: CR60215: removed compiler warnings
 * V2.0.0: 24.09.2005, miwe: + ASR-DCM integration,
 *                           + Merged 'appldiag.c' with 'bootdiag.c'
 *                           + Common functions moved to 'diag.c'
 * V1.0.0: 07.09.2005, olgo: initial version, moved macros of diagnostic
 *                           services from 'bootdiag.c' and 'appldiag.c' to
 *                           this file
 */

/**************************************************************************************************************************/
/* Nxtr Version Control:
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
10/05/16     EA3#3     ABS        Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
**************************************************************************************************************************/

#ifndef DIAG_H
#define DIAG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* -------------------------------------------------------------------------- */
#include "sc_types.h"          /* Contains architecture independent           */
                               /* typedefinitions that shall be unique for    */
                               /* all modules.                                */
/* -------------------------------------------------------------------------- */
#include "Diag_Types.h"        /* Diag types                                  */
/* -------------------------------------------------------------------------- */
#include "Diag_Cfg.h"          /* Diag configuration file                     */
/* -------------------------------------------------------------------------- */
#include "Dcm.h"               /* DCM Api                                     */
/* -------------------------------------------------------------------------- */
#if ( defined BOOTLOADER )
   #include "bootdiag.h"       /* Bootloader specific diganostic              */
   #include "Boot_Crypto.h"    /* Bootloader crypto routines                  */
#elif ( defined APPLICATION )
   #include "appldiag.h"       /* Application specific diagnostic             */
   #include "Appl_Crypto.h"    /* Application crypto routines                 */
#endif

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*
 * Authentication security level
 * SC does only support authentification level 3
 */
#define SC_AUTH_LEVEL 0x03u

/*
 * Authentication key length in bytes
 * Depends on authentication method which can be defined in StandardCore.mcfg
 */
#if defined (CRYPTO_AUTH_ASYM)
   #define SG_KEY_LEN                         ((CR_DEF_AUTH_KEY_LENGTH) * 0x04u)
#elif defined (CRYPTO_AUTH_SYM)
   #define SG_KEY_LEN                         0x10u
#else
   #error "diag.h: No crypto method defined. Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'."
#endif

/*
 * valid parameter(s) of set extended mode
 */
#define VSM_MM_MODE_EXTENSION_FLASH_ENABLED                                0x01u

/*
 * This parameter is used to indicate to the function 'GetCurrentSvk' that the
 * SVK will be used for storing in EEPROM and not as a diag response
 */
#define GET_SVK_CURRENT_FOR_HISTORY_MEM                                  0x0000u

/*
 * The diagnosis data are received/sent high byte first.
 * If the endianess of the microcontroller fits to the diagnosis endianess,
 * simple memcopy operations can be performed instead of copying 'manually'
 */
#if (CPU_TYPE == CPU_TYPE_32)
   #if ((CPU_WORD_ORDER == HIGH_WORD_FIRST) && (CPU_BYTE_ORDER == HIGH_BYTE_FIRST))
      #define DIAG_ENDIANESS_FITS   CONFIG_TRUE
   #else
      #define DIAG_ENDIANESS_FITS   CONFIG_FALSE
   #endif
#elif (CPU_TYPE == CPU_TYPE_16)
   #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
      #define DIAG_ENDIANESS_FITS   CONFIG_TRUE
   #else
      #define DIAG_ENDIANESS_FITS   CONFIG_FALSE
   #endif
#else
   #define DIAG_ENDIANESS_FITS      CONFIG_FALSE
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*
 * needed to handle ecu reset. After a UDS reset request lots of jobs have
 * to be done. For example write of NvM data. The positive response of the
 * request should be send after this jobs. For this reason special handling
 * of this requst is needed.
 */
typedef struct
{
#ifdef BAC
  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext;           /* msg context of pending job    */
#else
  Dcm_MsgContextType* pMsgContext;           /* msg context of pending job    */
#endif /* Defined BAC */
  volatile uint8      ForceEcuResetStatus;   /* used to handle EcuReset       */
                                             /* Request and session changes   */
                                             /* to programming session        */
  volatile uint16 EcuPositivResponseTimer;   /* for timeout handling          */

} EcuResetHandlingType;

/*
 * Security access params type:
 * Used to save security access parameters between GetSeed and CompareKey
 */
typedef struct
{
   uint8  PendingSeed[8];                 /* seed stored temporary in ECU     */
                                          /* between GetSeed -> CompareKey    */
   uint8  TesterId[DCM_SEC_SEED_RECORD_LENGTH];
                                          /* TesterId transfered in GetSeed   */
} SecurityAccessParamsType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define DIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

   /*
    * Pending diag context type
    * Used to save diag parameters for asynchronous processing in 'BackgroundTask'
    */
#ifdef BAC
	extern VAR(pendingDiagContextType, DCM_APPL_DATA) pendingDiagContext;
#else
   extern pendingDiagContextType pendingDiagContext;
#endif /* Defined BAC */
   /*
    * needed to handle ecu reset. After a UDS reset request lots of jobs have
    * to be done. For example write of NvM data. The positive response of the
    * request should be send after this jobs. For this reason special handling
    * of this requst is needed.
    */
#ifdef BAC
	extern VAR(EcuResetHandlingType, DCM_APPL_DATA) ecuresetHandling;
#else
   extern EcuResetHandlingType ecuresetHandling;
#endif

#define DIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define DIAG_START_SEC_CODE
#include "MemMap.h"

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) Rte_DcmECUReset
          (
		     CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		  );
#else
   extern void Rte_DcmECUReset(Dcm_MsgContextType* const pMsgContext);
#endif /* Defined BAC */

#ifdef BAC
	extern FUNC(void, DCM_APPL_CODE) Rte_DcmGetSeed
               (
	 	      VAR(uint8, DCM_APPL_DATA) SecurityLevel, 
	 		  VAR(uint8, DCM_APPL_DATA) SeedLen, 
	 		  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) Seed
	 	   );
#else
	extern void Rte_DcmGetSeed
	       (
                  uint8 SecurityLevel,
			  uint8 SeedLen, 
			  Dcm_MsgContextType* Seed
		   );
#endif /* Defined BAC */

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
#ifdef BAC
	extern FUNC(Dcm_StatusType, DCM_APPL_CODE) Rte_DcmCompareKey
           (
              VAR(uint8, DCM_APPL_DATA) SecurityLevel,
              VAR(uint8, DCM_APPL_DATA) KeyLen,
                  CONSTP2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Key
		   );
#else
	extern Dcm_StatusType Rte_DcmCompareKey
	       (
		      uint8 SecurityLevel,
              uint8 KeyLen,
                  const uint8* const Key
		  );
#endif /* Defined BAC */
/* ----- Original Code End ----- */
#endif
/* ----- Patch Code Start ----- */
#ifdef BAC
	extern FUNC(Dcm_StatusType, DCM_APPL_CODE) Rte_DcmCompareKey
           (
              VAR(uint8, DCM_APPL_DATA) SecurityLevel,
              VAR(uint16, DCM_APPL_DATA) KeyLen,
                  CONSTP2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Key
		   );
#else
	extern Dcm_StatusType Rte_DcmCompareKey
	       (
		      uint8 SecurityLevel,
              uint16 KeyLen,
                  const uint8* const Key
		  );
#endif /* Defined BAC */
/* ----- Patch Code End ----- */
/* ----- NXTR PATCH END ----- */


#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierActiveDiagSession
           (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierActiveDiagSession
	       (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierTimingParameters
		   (
			  CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierTimingParameters
		   (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierStandardCoreVersion
           (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierStandardCoreVersion
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierProgrammingCounter
           (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
    extern void ApplDcmReadDataByIdentifierProgrammingCounter
		   (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierProgrammingCounterMaxValue
           (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierProgrammingCounterMaxValue
           (
			  Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierMemorySegmentationTable
           (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierMemorySegmentationTable
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvkCurrent
           (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierSvkCurrent
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvkSystemSupplier
		   (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierSvkSystemSupplier
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvkPlant
		   (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierSvkPlant
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierSvkBackup
		   (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext, uint16 dataId
		   );
#else
    extern void ApplDcmReadDataByIdentifierSvkBackup
           (
		      Dcm_MsgContextType* const pMsgContext, uint16 dataId
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierEcuManufacturingData
           (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierEcuManufacturingData
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierEcuSerialNumber
		   (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierEcuSerialNumber
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmReadDataByIdentifierVin
		   (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmReadDataByIdentifierVin
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmRoutineControlReadDevelopmentInfo
           (
		      CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
		   );
#else
	extern void ApplDcmRoutineControlReadDevelopmentInfo
           (
		      Dcm_MsgContextType* const pMsgContext
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) GetCurrentSvk
              (
             P2VAR(uint8, AUTOMATIC, COMMON_APPL_DATA) dataPtr,
                  uint16 dataLen
              );
#else
	extern void GetCurrentSvk
	       (
		      uint8* dataPtr,
			  uint16 dataLen
		   );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmProcessReadMemorySegmentationTable
               (
                  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) dataBufPtr,
			  VAR(uint16, DCM_APPL_DATA) dataLen
           );
#else
	extern void ApplDcmProcessReadMemorySegmentationTable
	       (
                  uint8* dataBufPtr,
                  uint16 dataLen
               );
#endif /* Defined BAC */

   #if (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)
    #ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmProcessReadSVK
               (
                  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) dataBufPtr,
                  uint16 dataLen
               );
    #else
	extern void ApplDcmProcessReadSVK
	(
	   uint8* dataBufPtr;
	   uint16 dataLen
	);
	#endif /* Defined BAC */

	#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmCancelPagedBufferProcessing(void);
	#else
	extern void ApplDcmCancelPagedBufferProcessing( void );
	#endif /* Defined BAC */

	#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) ApplDcmPagedBufferProcessingConfirmation
               (
              VAR(uint8, DCM_APPL_DATA) idContext,
              VAR(uint8, DCM_APPL_DATA) dcmRxPduId,
              VAR(Dcm_ConfirmationStatusType, DCM_APPL_DATA) status
           );
	#else
	extern void ApplDcmPagedBufferProcessingConfirmation
	       (
                  uint8 idContext,
                  uint8 dcmRxPduId,
                  Dcm_ConfirmationStatusType status
               );
	#endif /* Defined BAC */
   #endif /* (DCM_PAGEDBUFFER_ENABLED == CONFIG_TRUE)                         */

#define DIAG_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* DIAG_H                                                             */

/*** End of file **************************************************************/
