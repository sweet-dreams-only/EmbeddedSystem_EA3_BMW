/*******************************************************************************
**                                                                            **
**  SRC-MODULE: bootdiag.h                                                    **
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
** mm           Miroslaw Missalla          EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** jetc         Jean-Jacques Tchouto       EB Automotive                      **
** sc           Juergen Scherg             EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V9.1.0: 06.09.2010, ft  : CR70684/CR70735: Added missing or imcomplete
											  compiler abstraction
 * V9.0.4: 22.04.2010, anht: CR61839/CR70426: make common files between Bac and SC6
 * V9.0.3: 20.04.2010, anam: CR70288: Change storage classes in compiler abstraction for Diag
 * V9.0.2: 27.01.2010, gema: CR70527: Compiler switches shall have defined values
 * V9.0.1: 27.10.2009, gema: CR70429: Relocation of wrapper between DCM and 
 *                                    bootdiag 
 * V9.0.0: 03.06.2009, hauf: CR61622: removed unused functions
 * V8.0.0: 05.11.2008, miwe: CR61489: extended BootMode flag to 64 bit
 * V7.1.0: 27.09.2007, miwe: CR61261: reworked FreeTimer integration
 * V7.0.0: 28.02.2007, jetc: renamed Nvm_Vsm_NvData to NVM_VSM_NV_DATA.
 * V6.0.0: 12.10.2006, miwe: MISRA checked
 *         05.09.2006, sc  : added '#include "Fee.h"' if 'SC_FEE_ENABLE' is set
 *                           to 'STD_ON'.
 *                           added definitions of NvM block identifiers in case
 *                           'SC_FEE_ENABLE' is set to 'STD_ON'.
 *         30.08.2006, miwe: adaptions according to LH FP v07:
 *                           - moved functions 'CheckProgDepStatus' and
 *                             'CheckSWEProgrammingStatus' from 'diag' to
 *                             'bootdiag'
 *                           - renamed function 'WriteSvkBackup' to
 *                             'WriteSvkHistoryMemory'
 *                           - merged 'WriteFingerprint' and
 *                             'WriteApplStartedFirstFlag' to one function
 *                             because they write the same nv block at the same
 *                             time
 *         18.08.2006, jetc: added memory map section extension
 * V5.0.0: 17.03.2006, hauf: include diag.h instead of sc_types.h
 * V4.0.0: 31.10.2005, miwe: renamed 'SessionStatus' to 'activeSubSession'
 * V3.2.0: 25.10.2005, miwe: DCM integration, session handling adapted
 * V3.1.0: 21.07.2005, olgo: added SessionStatus
 * V3.00 : 21.07.2005, mm  : + 'EepIf_Tapes.h' include added
 *                           + global func. prototype 'WaitUntilEepromReady'
 *                             added
 * V2.00 : 28.06.2005, miwe: EepDisp includes and callbacks removed
 * V1.01 : 15.03.2005, hauf: moved function WaitOnIdle from template/source
 * V1.00 : 18.11.2004, mm  : initial implementation
 */

#ifndef BOOTDIAG_H
#define BOOTDIAG_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"         /* include AUTOSAR standard types              */
/* -------------------------------------------------------------------------- */
#include "diag.h"              /* enumeration type sessionType                */
/* -------------------------------------------------------------------------- */
#include "Dcm.h"               /* DCM Api                                     */
/* -------------------------------------------------------------------------- */
#if (SC_FEE_ENABLE == STD_ON)
    #include "Fee.h"           /* contains definitions of Fee block Id's      */
#else
    #include "EepIf_Types.h"   /* EepIf specific types                        */
#endif

/*
 * Define BOOTLOADER_TEST_ENABLE to prevent compiler warnings because of
 * undefined macro.
 */
#ifndef BOOTLOADER_TEST_ENABLE
   #define BOOTLOADER_TEST_ENABLE OFF
#endif

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 *  The block identifiers for the NVRAM blocks which are used by the bootloader
 *  to be passed as arguments to the MemIf functions must mapped to the
 *  corresponding block identifiers which are generated by the EA-configuration
 *  tool for the FEE module.
 *  In case 'SC_FEE_ENABLE' is set to 'OFF' the block identifiers are defined
 *  by the Eeprom Abstraction (EA) configuration file.
 */
#if (SC_FEE_ENABLE == STD_ON)
    #define  NVM_DIAG_BOOTPROGCOUNTER      Fee_NVM_DIAG_BOOTPROGCOUNTER
    #define  NVM_DIAG_BOOTPROGDATA         Fee_NVM_DIAG_BOOTPROGDATA
    #define  NVM_DIAG_BOOTPROGSTATUS       Fee_NVM_DIAG_BOOTPROGSTATUS
    #define  NVM_DIAG_SVKHISTORYMEMORY     Fee_NVM_DIAG_SVKHISTORYMEMORY
    #define  NVM_VSM_NV_DATA               Fee_NVM_VSM_NV_DATA
#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define BOOTDIAG_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

   extern SubSessionType activeSubSession;

#define BOOTDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define BOOTDIAG_START_SEC_CODE
#include "MemMap.h"

#if (SC_NRV2B_ENABLE == STD_ON)
   extern FUNC(void, DCM_FREETIMER_CODE) CheckFreetimer(void);
#else
   #define CheckFreetimer()
#endif /* (SC_NRV2B_ENABLE == STD_ON)                                             */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) Rte_DcmReadDataByIdentifier(CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#else
   extern void Rte_DcmReadDataByIdentifier(Dcm_MsgContextType* const pMsgContext);
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) Rte_DcmWriteDataByIdentifier(CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#else
   extern void Rte_DcmWriteDataByIdentifier(Dcm_MsgContextType* const pMsgContext);
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) Rte_DcmRoutineControl(CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#else
   extern void Rte_DcmRoutineControl(Dcm_MsgContextType* const pMsgContext);
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) Rte_DcmRequestDownload(CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#else
   extern void Rte_DcmRequestDownload(Dcm_MsgContextType* const pMsgContext);
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) Rte_DcmTransferData(CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#else
   extern void Rte_DcmTransferData(Dcm_MsgContextType* const pMsgContext);
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) Rte_DcmRequestTransferExit(CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#else
   extern void Rte_DcmRequestTransferExit(Dcm_MsgContextType* const pMsgContext);
#endif /* Defined BAC */

/* Within BAC the function will be called with 2 parameters */
#ifdef BAC
   extern FUNC(Dcm_StatusType, DCM_APPL_CODE) Rte_DcmGetSesChgPermission
      (
         CONST(uint8, DCM_APPL_CONST) SesCtrlTypeActive,
         CONST(uint8, DCM_APPL_CONST) SesCtrlTypeNew
      );
#else
   extern Dcm_StatusType Rte_DcmGetSesChgPermission
      (
         Dcm_MsgContextType* const pMsgContext,
         const uint8 SesCtrlTypeActive,
         const uint8 SesCtrlTypeNew
      );
#endif /* Defined BAC */

   extern FUNC(void, DCM_APPL_CODE) Rte_DcmSesCtrlChangeIndication
     (
        CONST(uint8, DCM_APPL_CONST) SesCtrlTypeOld,
        CONST(uint8, DCM_APPL_CONST) SesCtrlTypeNew
     );

#ifdef BAC
   extern FUNC(Dcm_StatusType, DCM_APPL_CODE) Rte_DcmIndication
      (
         CONSTP2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
         CONST(uint8, DCM_APPL_CONST)                             SID
      );
#else
   extern Dcm_StatusType Rte_DcmIndication
      (
         Dcm_MsgContextType* const pMsgContext,
         const uint8               SID
      );
#endif /* Defined BAC */

#ifdef BAC
   extern FUNC(void, DCM_APPL_CODE) Rte_DcmConfirmation
     (
        CONST(uint8, DCM_APPL_CONST)                      idContext,
        CONST(uint8, DCM_APPL_CONST)                      dcmRxPduId,
        CONST(Dcm_ConfirmationStatusType, DCM_APPL_CONST) status
     );
#else
   extern void Rte_DcmConfirmation
     (
        const uint8                      idContext,
        const uint8                      dcmRxPduId,
        const Dcm_ConfirmationStatusType status
     );
#endif /* Defined BAC */

   #if ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON))
	#ifdef BAC
		extern FUNC(boolean, DCM_APPL_CODE) WriteSvkHistoryMemory( void );
	#else
   extern boolean WriteSvkHistoryMemory(void);
	#endif /* Defined BAC */
	#ifdef BAC
		extern FUNC(boolean, DCM_APPL_CODE) WriteFingerprintAndApplStartedFirstFlag( void );
	#else
   extern boolean WriteFingerprintAndApplStartedFirstFlag(void);
	#endif /* Defined BAC */
#endif /* ((BOOTLOADER_TEST_ENABLE == STD_ON) && (STANDARD_CORE_TEST == STD_ON)) */

#define BOOTDIAG_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BOOTDIAG_H                                                          */

/*** End of file **************************************************************/
