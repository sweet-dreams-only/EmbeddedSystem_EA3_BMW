
/**************************************************************************************************
   Project Name: AUTOSAR XCP on FlexRay Transport Layer
      File Name: FrXcp_CbkS.h

    Description: Callback header of the XCP on FlexRay Transport Layer

  -------------------------------------------------------------------------------------------------
       C O P Y R I G H T
  -------------------------------------------------------------------------------------------------
       Copyright (c) 2011 by Vctr Informatik GmbH. All rights reserved.



       This software is copyright protected and proporietary to Vctr Informatik GmbH.
       Vctr Informatik GmbH grants to you only those rights as set out in the
       license conditions. All other rights remain with Vctr Informatik GmbH.


       Use of this source code is subject to the License Agreement "license.txt"
       distributed with this file. You may not use this source code unless you
       agree to the terms of the License Agreement.

       REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.

  -------------------------------------------------------------------------------------------------
                 A U T H O R   I D E N T I T Y
  -------------------------------------------------------------------------------------------------
   Initials     Name                      Company
   --------     ---------------------     ---------------------------------------------------------
   hr           Andreas Herkommer         Vctr Informatik GmbH
  -------------------------------------------------------------------------------------------------
                 R E V I S I O N   H I S T O R Y
  -------------------------------------------------------------------------------------------------
   Date         Ver      Author  Description
   ----------   -------  ------  ------------------------------------------------------------------
   2006-09-01   2.00.00  hr      Complete Rework for Gen2 - Supports FrIf now
   2007-03-31   2.01.00  hr      Adaptation to D4 requirements: New API
   2007-05-07   2.01.01  hr      ISS001 - Buffer reconfig API includes and type usage reworked to
                                          prevent compile error if not used
                                 ISS002 - Usage of Compiler.h is not mandatory anymore
   2007-05-08   2.02.00  hr      Implementation of features described in XCP_Client_V1.1
   2007-07-23   2.02.01  hr      Minor updates
   2007-07-09   2.03.00  hr      Support AUTOSAR Memory Mapping
   2007-09-03   2.03.01  hr      Unified as Single Source
   2007-10-05   2.04.00  hr      ISS024 - ApplXcpDaqTlResume had a wrong prototype
                                 ISS027 - Support of AUTOSAR GetVersion API
                                 ISS030 - PDU buffer ordering changed
                                 ISS032 - The XCP_ACTIVATE and XCP_DEACTIVATE macros are missing
   2007-12-07   2.05.00  hr      ISS045 - Reception of concatenated frames may lead to
                                          misinterpretation of random data as xcp frame in case
                                          PDU is smaller than MAX_PDU_SIZE
                                 ISS046 - Only CTOs are flushed by the Protocol Layer
   2008-02-07   2.06.00  hr      ISS051 - XCP_ENABLE and XCP_DISABLE have intermixed values
                                 ISS052 - FrXcp_TLService missing length check of new assigned buffer
                                 ISS053 - PDU Reservation shoould happen before FrIf_Transmit as
                                          this might cause race conditions on certain FlexRay Stacks
                                 ISS054 - Copy of XCP PDUs can now also be done during Tx_Confirmation
                                          to detect displacement in the non guaranteed dynamic segment
   2008-03-20   2.07.00  hr      Added various type casts for MISRA compliance
   2008-08-27   2.08.00  hr      Update for ASR 3.0
   2009-03-16   2.09.00  hr      ESCAN00033909: Update due to 
                                                Anforderungsdokument_EA_XCP-Client_Spezifikation_V1_1.PDF
   2009-08-03   2.09.01  hr      ESCAN00036838: Race condition with XCP_FREE_PDU and Event Assign
   2009-09-07   2.09.02  hr      ESCAN00037599: Missing memmap.h and compiler_cfg.h
   2009-09-12   2.10.00  hr      ESCAN00038374: No FrXcp_InitMemory function
   2009-10-13                    ESCAN00038410: Wrong variable section for compiler abstraction
   2009-11-24            hr      ESCAN00039363: Support FrIf_Transmit with E_PENDING
   2009-12-03            hr      ESCAN00039560: Compiler Warning by ON/OFF pre-processor statements
   2009-12-09            hr      ESCAN00039641: FrXcp does not use SchM for Interrupt locks
   2010-02-02   2.10.01  hr      ESCAN00040602: Frame end detection with concatenation is one byte to long.
                                 ESCAN00040124: Support MISRA2004 checks
                                 ESCAN00040810: wrong "component version" define
   2010-08-17   2.10.02  hr      ESCAN00044142: Compiler error occurs when compiling function FrXcp_GetFreePdu
   2010-08-24                    ESCAN00044840: Compiler warning "Invalid pointer cast" might occur
   2010-11-04   2.10.03  hr      ESCAN00046457: Transport Layer not activated in Protocol Layer if frame concatenation is enabled
                                 ESCAN00046235: Adapt AUTOSAR version check
                                 ESCAN00046412: Compiler warning: variable "FrXcp_PduState" was set but never used
                                 ESCAN00046819: Add support for XCP measurement during bus off phases
   2010-12-14   2.10.04  hr      ESCAN00047672: Resume Mode Callbacks do not use Compiler abstraction
                                 ESCAN00047641: Compiler warning: FrXcp.h", line 307: warning (dcc:1479): comma at end of enumerator list ignored
   2011-01-04   2.11.00  hr      ESCAN00046310: AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
                                 ESCAN00047330: Adapt MainFunction for usage with IdentityManagerConfig
   2011-03-03   2.11.01  hr      ESCAN00049062: The SetPduMode shall be pre-compile time configurable
**************************************************************************************************/

#if !defined(__FRXCP_CBK_H__)
#define __FRXCP_CBK_H__

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "Std_Types.h"            /* Include standard types */
#include "FrXcp.h"

/**************************************************************************************************
* Version check
**************************************************************************************************/
#if defined ( __FRXCP_H__ )
  #if ( CP_XCPONFRASR_VERSION != 0x0211u )
    #error "The header versions of FrXcp.h and FrXcp_Cbk.h are incompatible."
  #endif
  #if ( CP_XCPONFRASR_RELEASE_VERSION != 0x01u )
    #error "The release versions of FrXcp.h and FrXcp_Cbk.h are incompatible."
  #endif
#endif

/**************************************************************************************************
* Prototypes of callback functions
**************************************************************************************************/

/*------------------ XCP on FlexRay services called by FlexRay IF ------------------*/

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_START_SEC_CODE
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif

/* This function is called by the FlexRay Interface after a XcpOnFr L-PDU has been transmitted. */
extern FUNC(void, FRXCP_CODE) FrXcp_TxConfirmation
(
  VAR(PduIdType, AUTOMATIC) XcpTxPduId
);

/* This function is called by the FlexRay Interface after a XcpOnFr L-PDU has been received. */
#if ( FRXCP_USE_PDUINFOTYPE == STD_ON )
extern FUNC(void, FRXCP_CODE) FrXcp_RxIndication
(
  VAR(PduIdType, AUTOMATIC) XcpRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, FRXCP_APPL_VAR) PduInfoPtr
);
#else
extern FUNC(void, FRXCP_CODE) FrXcp_RxIndication
(
  VAR(PduIdType, AUTOMATIC) XcpRxPduId,
  P2CONST(uint8, AUTOMATIC, FRXCP_APPL_VAR) SduPtr
);
#endif

/* This function is called by the FlexRay Interface if a XcpOnFr L-PDU transmission is pending. */
#if ( FRXCP_USE_PDUINFOTYPE == STD_ON )
extern FUNC(Std_ReturnType, FRXCP_CODE) FrXcp_TriggerTransmit
(
  VAR(PduIdType, AUTOMATIC) XcpTxPduId,
  P2VAR(PduInfoType, AUTOMATIC, FRXCP_APPL_VAR) PduInfoPtr
);
#else
extern FUNC(void, FRXCP_CODE) FrXcp_TriggerTransmit
(
  VAR(PduIdType, AUTOMATIC) XcpTxPduId,
  P2VAR(uint8, AUTOMATIC, FRXCP_APPL_VAR) SduPtr
);
#endif

#if ( FRXCP_MEM_MAPPING_ENABLED == STD_ON )
  #define FRXCP_STOP_SEC_CODE
  /* PRQA S 5087 2 *//* MISRA-C:2004 Rule 19.1, #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
  #include "MemMap.h"
#endif


#endif
  /* __FRXCP_CBK_H__ */
