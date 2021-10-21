/* Kernbauer Version: 1.16 Konfiguration: Il_AsrCom Erzeugungsgangnummer: 1577 */

/* STARTSINGLE_OF_MULTIPLE */
/* KB begin Com_HeaderText */
/* KB end Com_HeaderText */
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2011 by Vctr Informatik GmbH.                                                  All rights reserved.
 
                This software is copyright protected and proprietary to Vctr Informatik GmbH.
                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vctr Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Com.c
      Project:  MICROSAR Com
       Module:  -
    Generator:  -

  \brief Description:  Vector AUTOSAR Com code file
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Gunnar Meiss                  visms         Vctr Informatik GmbH
  Hannes Haas                   vishs         Vctr Informatik GmbH
  Michael Bissinger             visbsm        Vctr Informatik GmbH
  Safiulla Shakir               visssa        Vctr Informatik GmbH
  Dominik Biber                 visdbi        Vctr Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  01.00.00  2006-08-01  visms,vishs,visbsm    Creation
  01.01.00  2007-02-02  visbsm  ESCAN00018670 Post build support (Com_ConfigStruct)
                        visms   ESCAN00018767 No changes here
                        visms   ESCAN00018739 Compiler warning due to static prototypes
                        visms   ESCAN00018863 CodeInspection
                        visms   ESCAN00018882 No changes here
                        visms   ESCAN00018919 No changes here
                        visbsm,
                        vishs   ESCAN00018690 Intel bytearray signals on Motorola targets
                        visms   ESCAN00018681 Expression must be a modifiable lvalue
                        visms   ESCAN00019017 Remove CPU_BIT_ORDER MSB_FIRST Error Directive
  02.00.00  2007-08-08  visms   ESCAN00019386 Improve Performance of small static interfaces
                        visms   ESCAN00019661 Support COM_IPDU_SIZE as PduInfoPtr ->SduLength
                        visms   ESCAN00019557 No changes here
                        visms   ESCAN00019555 Pclint Misra Improvements
                        visms   ESCAN00019778 [SR:032] Com_IpduGroupTransmit
                        visbsm  ESCAN00019638 No changes here
                        vishs   ESCAN00019840 Allow variable signal count
                        visms,
                        vishs   ESCAN00019909 Add AUTOSAR 2.1 and Gw Support
                        vishs   ESCAN00017202 Optimized shadow buffer handling
                        vishs   ESCAN00019903 Reduce IR lock time when reading and wrinting partial signals
                        visms   ESCAN00020258 Com_ServideIdType Prefix
                        vishs   ESCAN00020214 Added GenSigMissingSourceValue support for signal gateway
                        visbsm  ESCAN00021422 Replaced boolean with uint8 in generated ROM data
                        visbsm  ESCAN00021849 post build indirection
  02.01.00 2007-08-16   visms   ESCAN00021239 No changes here
                        visbsm  ESCAN00022299 No changes here
                        visms   ESCAN00022624 Remove Non-Selectable Post-build feature
                        visbsm  ESCAN00022735 MISRA rework
                        visbsm  ESCAN00022715 Support Com_GetConfigurationId in all configuration variants
                        visbsm  ESCAN00022811 Support signal conversion
  02.02.00 2007-11-27   visbsm  ESCAN00023050 Callout support
                        visbsm  ESCAN00023194 Support indication and rx timeout flags
                        visbsm  ESCAN00023144 Invalid Rx timeout value for signals with update bits
  02.03.00 2008-01-24   vishs   ESCAN00023768 Support for PDUs, signals and signal groups >8Bytes
                        vishs   ESCAN00023769 Added TP layer PDU support
                        visbsm  ESCAN00024191 Added transmission mode selector, tx signal filters
  02.03.01 2008-02-14   visbsm  ESCAN00024598 Fixed COM495
  03.00.00 2008-02-22   visms   ESCAN00024213 No changes here
                        visms   ESCAN00024475 No changes here
                        visms   ESCAN00024624 Remove Com_ApplicationDataRefType
                        visms   ESCAN00024632 Management API Repeated Calls
                        visms   ESCAN00024631 COM_E_PARAM in Com_Init
                        visms   ESCAN00024630 *MainFunction Calls before Com_Init
                        visms   ESCAN00024643 Rx Deadline Notification Prototype
                        visms   ESCAN00024330 Harmonize Prototypes
                        vishs   ESCAN00024849 Supporting dynamic PDU lengths for J1939
                        visbsm  ESCAN00018744 Compiler Abstraction
                        visbsm  ESCAN00024602 Memory Abstraction
                        visms   ESCAN00024730 Com_TxBuffer_WriteIpduWithMask Preprocessor
                        visms   ESCAN00024633 No changes here
                        visms   ESCAN00023624 Revise Comments
                        visms   ESCAN00025232 Com_GetVersionInfo instanceID
                        visms   ESCAN00025239 Remove V_CRITICAL_SECTION_USE_VECTOR_COMMENT
                        visbsm  ESCAN00025421 Added static qualifier according to prototype
                        visbsm  ESCAN00025452 Com_IpduGroupTransmit
  03.01.00 2008-04-14   visbsm  ESCAN00025997 boolean signal filters
                        visms   ESCAN00026159 PduIdType Check
                        visms   ESCAN00026220 MSR3.0 LinkTime checks
                        visms   ESCAN00026346 Com_Tp API Assertions
                        visms   ESCAN00027082 Statement not reached in Com_Init
  03.02.00 2008-06-02   visms   ESCAN00027222 VStdLib MemCpy
                        visbsm  ESCAN00026655 Generator Version Checks
  03.03.00 2008-06-05   visms   ESCAN00027390 Multiple message transmissions in Com_IpduGroupTransmit
                        visms   ESCAN00027131 Com_TriggerIPDUSend
                        visbsm  ESCAN00027503 Pure cyclic PDU transmitted spontaneously
                        visbsm  ESCAN00027871 Unexpected transition to Tx mode false
                        visms   ESCAN00027998 Compile Error with Indication or Timeout Flags
                        visms   ESCAN00027257 Support TMS 320
  03.04.00 2008-07-28   vishs   ESCAN00027074 Removed unused constants
                        vishs   ESCAN00028432 Optimized Com_XxBuffer implementation
                        vishs   ESCAN00028436 Precompile variants for signal access
                        visbsm  ESCAN00025070 ComIPduSignalProcessing
                        vishs   ESCAN00028444 Precompile variants for notification handling
                        visbsm  ESCAN00028442 Precompile Optimization of Tx Algorithm
                        vishs   ESCAN00028441 Used function like macros for critical internal routines
                        visbsm  ESCAN00028432 Precompile Optimization for Signal Access
                        visbsm  ESCAN00022803 Compiler switches shall have defined values
                        visbsm  ESCAN00028355 Callouts Com_TriggerTransmit
                        visms   ESCAN00029123 Compile Error VStdMemCpy APIs with Postbuild data in GPAGE for MCS12x
                        visms   ESCAN00029251 Compile Error with Flag API
                        visms   ESCAN00029125 Compile Error if COM_PBCFG and COM_CONST are different
                        visssa  ESCAN00029357 Remove SubComponent Testsuite API
  03.05.00 2008-09-08   visms   ESCAN00029411 PreCompile and Linktime Crc Check
                        visbsm  ESCAN00028446 Signal Access Macro API
                        visms   ESCAN00030426 Remove Com_EnableReceptionDM, Com_DisableReceptionDM Return Value
                        visms   ESCAN00030236 Add Com_GetConfigurationStringPtr
                        visms   ESCAN00030398 Precompile Optimization of Com_GetConfigurationId
                        visms   ESCAN00030400 Precompile Optimization of Com_GetStatus
                        visms   ESCAN00030402 Precompile Optimization of Com_TriggerTransmit
                        visms   ESCAN00030404 Precompile Optimization of Com_TriggerIPDUSend
                        visms   ESCAN00030408 Precompile Optimization of Com_DeInit
                        visms   ESCAN00030430 Precompile Optimization of Com_MainFunctionRx or Com_MainFunctionTx
                        visms   ESCAN00030432 Precompile Optimization of Com_EnableReceptionDM or Com_DisableReceptionDM
                        visms   ESCAN00028453 Optimize Runtime by Reduction of Static Methods
                        visms   ESCAN00028450 Precompile Optimization of Subcomponents
  03.06.00 2008-11-05   visbsm  ESCAN00031040 Remove signal group routing buffers
           2008-11-11   visms   ESCAN00031097 Dependency Error with v_ver.h
                        visms   ESCAN00031089 Use COM_VAR_NOINIT for com_ConfigStructPtr
                        visms   ESCAN00031086 Memory Class TYPEDEF for typedefs
                        visms   ESCAN00030867 No changes here
           2008-11-12   visbsm  ESCAN00030036 Error notifications for outstanding not confirmed I-PDUs
           2008-11-14   visms   ESCAN00031090 Compiler Abstraction for CONST Expressions
                        visms   ESCAN00030561 Remove Redundant Loops in Com_DeInit
           2008-11-21   visbsm  ESCAN00028805 Signal invalidation
           2008-11-24   visms   ESCAN00031363 Compile Error with Gnu in Com_Signal_GetSignalAttribute
                        visms   ESCAN00031511 Add Rx Signal Write Access as Macro
           2008-11-27   visms   ESCAN00031687 No changes here
                        visms   ESCAN00031840 No changes here
  03.07.00 2008-12-23   visms   ESCAN00031392 Add ComFirstTimeoutFactor
  03.07.01 2009-02-05   visms   ESCAN00032663 Missing Notifications for Rx ComSignals or ComSignalGroups
  03.07.02 2009-02-06   visms   ESCAN00032893 Compile Error without Invalidation API
  03.07.03 2009-03-02   visms   ESCAN00033507 osSysShutdownOS is triggered with osLastError=0x4105
  03.08.00 2009-03-04   visms   ESCAN00032228 BAC 2.1 Compatibility
                        visms   ESCAN00031092 BSW00441
                        visms   ESCAN00031000 Compiler Error with Com_Signal_SignalBitLengthType
                        visms   ESCAN00033465 Compiler Warning: unused static function "Com_RxBuffer_WriteIpduWithMask"
                        visms   ESCAN00033898 No changes here
                        visms   ESCAN00032804 Invalidation Returns Last Valid Value
  03.09.00 2009-04-29   visms   ESCAN00034536 Stopy Cyclic Transmission in case of a Rx I-PDU timeout
                        visms   ESCAN00033724 CAN MOST Gateway
                        visdbi  ESCAN00035230 Compiler warning: variable "IpduDataPtr" was declared but never referenced
                        visdbi  ESCAN00035411 Com_RxIndication Callout SduPtr is not valid
  03.10.00 2009-06-24   visdbi  ESCAN00035941 Compiler warning: variable "ComRxPduId" was declared but never referenced
                        visdbi  ESCAN00035950 Compiler warning: variable "AccessAttr" was declared but never referenced
           2009-07-09   visdbi  ESCAN00036343 Generate Com_InvalidateSignal and Com_InvalidateSignalGroup as Defines
           2009-07-16   visms   ESCAN00036121 No changes here
           2009-07-16   visms   ESCAN00036378 Invalidation Notification Function is called with Disabled Interrupts.
           2009-07-20   visssa  ESCAN00036526 No changes here
           2009-07-20   visms   ESCAN00035785 Queueing of Failed Transmissions shall be configurable
           2009-07-20   visssa  ESCAN00036435 Use the Common Defines generated by GenTool_GenyVcfgNameDecorator
           2009-07-22   visms   ESCAN00036578 Com_ReceiveSignal or Com_ReceiveShadowSignal Returns Unexpected The Invalid Value
                        visms   ESCAN00034816 Preprocessor error with "memory protection OS"
           2009-07-29   visms   ESCAN00036238 SduLength variable not declared in Com_RxIndication
                        visms   ESCAN00036359 No changes here
                        visms   ESCAN00036734 Remove Interrupt Lock in Com_Init()
           2009-07-30   visdbi  ESCAN00036485 ComInvalidNotification at Com_Init, Com_Deinit, Com_IPduGroupStart and Timeout
                        visdbi  ESCAN00036742 Rx Indication notification function is not called for ubdate bit signals and signal groups
                        visdbi  ESCAN00038420 Timeout Notification Function is called with Disabled Interrupts.
           2009-08-05   visms   ESCAN00036845 Tx ComPdus via TP are not transmitted
                        visdbi  ESCAN00036846 Reception deadline monitoring could not be enabled or disabled within configurations containing only update bit signals
                        visdbi  ESCAN00036881 Transmission Mode Switch is updated for Rx signal groups in Com_SendSignalGroup()
                        visdbi  ESCAN00036887 Update bit state is not evaluated while routing Rx signals or signal groups
                        visdbi  ESCAN00036892 Linker Error: unresolved external symbol _Com_RxBuffer_BitIsSet referenced
                                              in function _Com_MainFunctionRouteSignals
           2009-08-06   visdbi  ESCAN00036124 Compiler warning :unused static function "Com_Buffer_ReadShadowSignal"
                        visdbi  ESCAN00036986 Compiler warning: Symbol 'Com_Signal_ReadSignal' not referenced
                        visdbi  ESCAN00036987 Compiler warning: Symbol 'Com_Signal_ReadSignalSignConversion' not referenced
           2009-08-06   visms   ESCAN00035442 Cyclic Transmission of Routed Signals with MSV in Timeout
           2009-08-10   visdbi  ESCAN00036974 Compiler warning: Symbol 'AccessAttr' not subsequently referenced
                        visdbi  ESCAN00036979 Compiler warning: Symbol 'Com_TxModeHdlr_Confirmation' not referenced
                        visdbi  ESCAN00036982 Compiler warning: Symbol 'Com_TxNHdlr_Confirmation' not referenced
  03.11.00 2009-09-01   visdbi  ESCAN00037509 GenSigMissingSourceValue is not written to the Tx signals after an Rx update bit signal timeout
                        visdbi  ESCAN00037500 Invalidate Tx signals of a routing relation if an Rx timeout occurs
                        visdbi  ESCAN00037470 Wrong ApiId in DET reporting for Com_TpProvideTxBuffer
                        visdbi  ESCAN00037222 Com_TxModeHdlr_TriggerIpduSend* and MISRA-C:2004 Rule 5.1
                        visdbi  ESCAN00037549 No changes here
           2009-09-15   visdbi  ESCAN00037695 Rx signal invalidation overrides old signal value in case of 'Data Invalid Action' set to 'NOTIFY'
           2009-09-16   visdbi  ESCAN00037781 Compiler warning: Symbol 'SignalDataZero' not accessed
                        visdbi  ESCAN00037594 Tx signals are not triggered in transmission mode 'False'
           2009-09-17   visdbi  ESCAN00037814 No changes here
  03.12.00 2009-10-15   visdbi  ESCAN00038203 Optimization of Critical Sections
                        visdbi  ESCAN00038424 Rx timeout notification function is called before signal data is updated
                        visdbi  ESCAN00038419 Timeout Notification Function is called with Disabled Interrupts.
                        visdbi  ESCAN00038208 Com_MainFunctionRouteSignals ISR Switch per Received Pdu
           2009-10-22   visdbi  ESCAN00038041 compiler warning: Possible loss of data
                        visdbi  ESCAN00038628 Support PduR_ComTransmit with E_PENDING
           2009-11-02   visdbi  ESCAN00038678 Memory Mapping for IL_ASRCOM_LIB_SYMBOL
           2009-11-19   visdbi  ESCAN00039266 MISRA-C:2004 Rule 8.8 violation: Com_RxInv_NotiInvalidNoUb()/Com_RxInv_NotiInvalidUb()
                        visdbi  ESCAN00039267 MISRA-C:2004 Rule 10.1 violation: Implicit conversion: short to unsigned short.
                        visdbi  ESCAN00039268 MISRA-C:2004 Rule 12.5 violation
                        visdbi  ESCAN00039269 MISRA-C:2004 Rule 8.8 violation: 'Com_InvalidateSignal()' has more than one 'return' path.
           2009-11-27   visdbi  ESCAN00039437 MISRA-C:2004 Rule 5.1 violation (e.g. 'Com_TxModeHdlr_TriggerDeferredIpduSend_Param')
           2009-12-04   visdbi  ESCAN00039531 Execution continues after reporting DET
  03.13.00 2010-01-22   visdbi  ESCAN00040086 Signal data is not updated with signal filter 'MaskedNewDiffersMaskedOld'
           2010-02-24   visdbi  ESCAN00040984 Support Optional Invalidation (F334)
           2010-02-26   visdbi  ESCAN00041232 Signal Data with ComBitPosition > 63 are not received or transmitted.
  03.14.00 2010-01-22   visdbi  ESCAN00040337 Support signal access macros for Tx signals (if TMS is not required)
           2010-01-27   visdbi  ESCAN00040403 Support signal access macros with numerical literal as parameter (HisCom0004)
           2010-02-02   visdbi  ESCAN00039640 No changes here
                        visdbi  ESCAN00039639 Use compiler abstraction for pointers to local variables
           2010-02-10   visdbi  ESCAN00040622 No changes here
           2010-03-11   visdbi  ESCAN00041503 Feature 'ComGwInvalidateTxOnRxTimeout' is not fully functional
           2010-04-07   visdbi  ESCAN00042122 Update bit based indication and timeout flags are not initialized
           2010-04-07   visdbi  ESCAN00042123 Implement indication flag handling depending on 'ComIPduSignalProcessing'
           2010-04-07   visdbi  ESCAN00042125 Pre-compile optimization for flag provider macro access
           2010-04-07   visdbi  ESCAN00042014 No changes here
           2010-04-07   visdbi  ESCAN00042135 Reset timeout flag if the signal / signal group is received again
           2010-04-13   visdbi  ESCAN00042258 Indication flag is set, if an invalid value is received and 'ComDataInvalidAction' is configured to 'NOTIFY'
           2010-04-13   visdbi  ESCAN00041306 Rx Invalidation is not supported in Link-Time and Post-Build Variant
  03.15.00 2010-04-26   visdbi  ESCAN00042540 Support transfer property TRIGGERED_ON_CHANGE
           2010-04-26   visdbi  ESCAN00042004 Support RxFilter "MaskedNewDiffersMaskedOld" (F352)
           2010-04-26   visdbi  ESCAN00042404 No changes here
           2010-04-27   visdbi  ESCAN00041661 Optimization of invalid value detection for Rx signals
           2010-04-27   visdbi  ESCAN00041497 Global interrupt is locked with 'Com_SendSignalGroup()' Call and Invalid Handle 
           2010-04-27   visdbi  ESCAN00042584 Global interrupt is locked, if a DET occurs in 'Com_MainFunctionRouteSignals()'
           2010-04-29   visdbi  ESCAN00041490 No changes here
           2010-04-29   visdbi  ESCAN00041672 Frequent locks could be optimized
           2010-04-30   visdbi  ESCAN00042672 Adapt function 'Com_TxSigIf_SendByteArray()'
           2010-05-04   visdbi  ESCAN00042723 No changes here
           2010-05-11   visdbi  ESCAN00042851 No changes here
  03.16.00 2010-05-18   visdbi  ESCAN00043003 Optimization of read signal macros for the API Com_ReceiveSignal()
           2010-05-21   visdbi  ESCAN00043064 Support Transmission Deadline Monitoring
           2010-06-29   visdbi  ESCAN00043649 Support unlimited number of I-Pdu groups
           2010-07-01   visdbi  ESCAN00043741 Support Transmission Deadline Monitoring for Tx Mode None
           2010-07-14   visdbi  ESCAN00043945 Support Transmission Mode Selection Indication
           2010-07-22   visdbi  ESCAN00044038 ComPdus shall Reference multiple ComIPduGroups
           2010-07-22   visdbi  ESCAN00040121 Redundant reset of reception deadline monitoring timeout time
           2010-07-22   visdbi  ESCAN00044285 Timeout timers are restarted by a call to 'Com_IPduGrouStart()'
           2010-08-05   visdbi  ESCAN00044472 Adapt function 'Com_RxSigIf_ReceiveByteArray()'
  03.16.01 2010-10-20   visdbi  ESCAN00046208 No changes here
                        visdbi  ESCAN00046209 No changes here
                        visdbi  ESCAN00046214 Compiler warning: '-=' conversion from 'int' to 'PduIdType', possible loss of data
  03.17.00 2010-11-18   visdbi  ESCAN00046126 Support PduInfoType instead of the DataPtr
           2010-11-30   visms   ESCAN00046263 Perform AUTOSAR version check only for Vector
           2010-12-01   visdbi  ESCAN00047018 Support Dynamic DLC
           2010-12-09   visdbi  ESCAN00045993 Compiler warning: Useless assignment to variable pPduInfo. Assigned value not used.
                        visdbi  ESCAN00045889 Compiler warning: parameter 'Length' unused in function 'Com_TpProvideTxBuffer'
                        visdbi  ESCAN00047075 No changes here
                        visdbi  ESCAN00045539 Remove ComTriggerTmsEnterFalse
           2011-01-27   visdbi  ESCAN00048094 ComPdu data can be modified after the call of the IPdu Callout function
                        visdbi  ESCAN00048190 Compiler warning: possible redundant expression
  03.17.01 2011-07-12   visdbi  ESCAN00050132 Evaluate 'TRIGGERED_ON_CHANGE' condition in signal access macros
                        visdbi  ESCAN00050106 No changes here
                        visdbi  ESCAN00049931 MISRA-C:2004 Rule 5.6 violation in function 'Com_Signal_ApplyFilter()'
**********************************************************************************************************************/
/* KB begin Com_LMgt_SourceFileProlog */
/* KB end Com_LMgt_SourceFileProlog */
/* KB begin Com_Signal_SourceFileProlog */
/* KB end Com_Signal_SourceFileProlog */
/* KB begin Com_Buffer_SourceFileProlog */
/* KB end Com_Buffer_SourceFileProlog */
/* KB begin Com_RxBuffer_SourceFileProlog */
/* KB end Com_RxBuffer_SourceFileProlog */
/* KB begin Com_RxDlMon_SourceFileProlog */
/* KB end Com_RxDlMon_SourceFileProlog */
/* KB begin Com_RxLLIf_SourceFileProlog */
/* KB end Com_RxLLIf_SourceFileProlog */
/* KB begin Com_RxNHdlr_SourceFileProlog */
/* KB end Com_RxNHdlr_SourceFileProlog */
/* KB begin Com_RxSigIf_SourceFileProlog */
/* KB end Com_RxSigIf_SourceFileProlog */
/* KB begin Com_RxUbHdlr_SourceFileProlog */
/* KB end Com_RxUbHdlr_SourceFileProlog */
/* KB begin Com_RxInv_SourceFileProlog */
/* KB end Com_RxInv_SourceFileProlog */
/* KB begin Com_TxInv_SourceFileProlog */
/* KB end Com_TxInv_SourceFileProlog */
/* KB begin Com_TxBuffer_SourceFileProlog */
/* KB end Com_TxBuffer_SourceFileProlog */
/* KB begin Com_TxDlMon_SourceFileProlog */
/* KB end Com_TxDlMon_SourceFileProlog */
/* KB begin Com_TxLLIf_SourceFileProlog */
/* KB end Com_TxLLIf_SourceFileProlog */
/* KB begin Com_TxModeHdlr_SourceFileProlog */
/* KB end Com_TxModeHdlr_SourceFileProlog */
/* KB begin Com_TxNHdlr_SourceFileProlog */
/* KB end Com_TxNHdlr_SourceFileProlog */
/* KB begin Com_TxSigIf_SourceFileProlog */
/* KB end Com_TxSigIf_SourceFileProlog */
/* KB begin Com_SignalGw_SourceFileProlog */
/* KB end Com_SignalGw_SourceFileProlog */

/*lint -function(exit,Det_ReportError)*/
#define V_IL_ASRCOM_COMPONENT_SOURCE

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com.h"
#include "Com_Cbk.h"
#include "PduR_Com.h"
#if (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF) && (COM_PROTECT_TIMEOUTFLAG == STD_OFF) && (COM_PROTECT_NOTIFICATIONFLAG == STD_OFF)
# if (COM_TSC_TESTCODE != STD_ON)
#   include "SchM_Com.h"
# endif
#endif
#if (COM_PROD_ERROR_DETECT == STD_ON)
# include "Dem.h"
#endif
#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
# include "v_ver.h"
#endif
#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK ) || (COM_CRC_CHECK == STD_ON)
# include "EcuM_Cbk.h"
#endif

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
#if ( IL_ASRCOM_VERSION != 0x0317u )
# error "File Com.c: Source and Header file are inconsistent!"
#endif
#if ( IL_ASRCOM_RELEASE_VERSION != 0x01u )
# error "File Com.c: Source and Header file are inconsistent!"
#endif

#if defined ( PDUR_VENDOR_ID )
# if ( PDUR_VENDOR_ID == COM_VENDOR_ID )
#  if ( PDUR_AR_MAJOR_VERSION != 2u )
#   error "Incompatible PDUR_AR_MAJOR_VERSION with this Com Implementation!"
#  endif
#  if ( PDUR_AR_MINOR_VERSION != 2u )
#   error "Incompatible PDUR_AR_MINOR_VERSION with this Com Implementation!"
#  endif
# endif
#endif

#if (COM_PROD_ERROR_DETECT == STD_ON)
# if defined ( DEM_VENDOR_ID )
#  if ( DEM_VENDOR_ID == COM_VENDOR_ID )
#   if ( DEM_AR_MAJOR_VERSION != 2u )
#    error "Incompatible DEM_AR_MAJOR_VERSION with this Com Implementation!"
#   endif
#   if ( DEM_AR_MINOR_VERSION != 2u )
#    error "Incompatible DEM_AR_MINOR_VERSION with this Com Implementation!"
#   endif
#  endif
# endif
#endif /* COM_PROD_ERROR_DETECT */

#if (COM_DEV_ERROR_DETECT == STD_ON)
# if defined ( DET_VENDOR_ID )
#  if ( DET_VENDOR_ID == COM_VENDOR_ID )
#   if ( DET_AR_MAJOR_VERSION != 2u )
#    error "Incompatible DET_AR_MAJOR_VERSION with this Com Implementation!"
#   endif
#   if ( DET_AR_MINOR_VERSION != 2u )
#    error "Incompatible DET_AR_MINOR_VERSION with this Com Implementation!"
#   endif
#  endif
# endif
#endif /* COM_DEV_ERROR_DETECT */

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/
/* KB begin Com_LMgt_LocalConstantMacros */
/* KB end Com_LMgt_LocalConstantMacros */
/* KB begin Com_Signal_LocalConstantMacros */

/* Access masks for Com_Signal_AccessAttrType */
#define COM_SIGNAL_APPLTYPE_BOOLEAN       ((Com_Signal_AccessAttrType)0x00000001UL)
#define COM_SIGNAL_APPLTYPE_UINT8         ((Com_Signal_AccessAttrType)0x00000002UL)
#define COM_SIGNAL_APPLTYPE_SINT8         ((Com_Signal_AccessAttrType)0x00000004UL)
#define COM_SIGNAL_APPLTYPE_UINT16        ((Com_Signal_AccessAttrType)0x00000008UL)
#define COM_SIGNAL_APPLTYPE_SINT16        ((Com_Signal_AccessAttrType)0x00000010UL)
#define COM_SIGNAL_APPLTYPE_UINT32        ((Com_Signal_AccessAttrType)0x00000020UL)
#define COM_SIGNAL_APPLTYPE_SINT32        ((Com_Signal_AccessAttrType)0x00000040UL)
#define COM_SIGNAL_APPLTYPE_UINT8_N       ((Com_Signal_AccessAttrType)0x00000080UL)
#define COM_SIGNAL_APPLTYPE_XINT8         (COM_SIGNAL_APPLTYPE_UINT8   | COM_SIGNAL_APPLTYPE_SINT8)
#define COM_SIGNAL_APPLTYPE_XINT16        (COM_SIGNAL_APPLTYPE_UINT16  | COM_SIGNAL_APPLTYPE_SINT16)
#define COM_SIGNAL_APPLTYPE_XINT32        (COM_SIGNAL_APPLTYPE_UINT32  | COM_SIGNAL_APPLTYPE_SINT32)
#define COM_SIGNAL_APPLTYPE_NOLOCK        (COM_SIGNAL_APPLTYPE_BOOLEAN | COM_SIGNAL_APPLTYPE_XINT8)

#define COM_SIGNAL_BUSACC_NBIT            ((Com_Signal_AccessAttrType)0x00000100UL)
#define COM_SIGNAL_BUSACC_BYTE            ((Com_Signal_AccessAttrType)0x00000200UL)
#define COM_SIGNAL_BUSACC_NBYTE           ((Com_Signal_AccessAttrType)0x00000400UL)
#define COM_SIGNAL_BUSACC_NBYTE_SW        ((Com_Signal_AccessAttrType)0x00000800UL)
#define COM_SIGNAL_BUSACC_NBITNBYTE       ((Com_Signal_AccessAttrType)0x00001000UL)
#define COM_SIGNAL_BUSACC_NBITNBYTE_SW    ((Com_Signal_AccessAttrType)0x00002000UL)
#define COM_SIGNAL_BUSACC_NOLOCK          (COM_SIGNAL_BUSACC_NBIT      | COM_SIGNAL_BUSACC_BYTE)

#define COM_SIGNAL_SAMEBITCOUNT           ((Com_Signal_AccessAttrType)0x00004000UL)
#define COM_SIGNAL_SIGN_EXTENSION         ((Com_Signal_AccessAttrType)0x00008000UL)

#define COM_SIGNAL_FALSE                  ((Com_Signal_AccessAttrType)0u)

#define COM_SIGNAL_NOSIGNALGROUP          ((Com_SignalGroupIdType)COM_SIGNALGROUPID_MAXVAL)

#define COM_SIGNAL_NO_CONVERSION          ((Com_Signal_ConversionHdlType)COM_SIGNAL_CONVERSIONHDL_MAXVAL)

#define COM_SIGNAL_NOINVALIDVALUE         COM_UINT16_MAX

#define COM_SIGNAL_CONV_FALSE             ((Com_Signal_ConversionVariantType)0x00u)
#define COM_SIGNAL_CONV_TYPE_MASK         ((Com_Signal_ConversionVariantType)0x0Fu)
#define COM_SIGNAL_CONV_TYPE_SIGNED       ((Com_Signal_ConversionVariantType)0x80u)
#define COM_SIGNAL_CONV_TYPE1             ((Com_Signal_ConversionVariantType)0x01u)
#define COM_SIGNAL_CONV_TYPE2             ((Com_Signal_ConversionVariantType)0x02u)
#define COM_SIGNAL_CONV_TYPE10            ((Com_Signal_ConversionVariantType)0x03u)

#define COM_SIGNAL_F_NONE                 ((Com_Signal_FilterHdlType)COM_SIGNAL_FILTERHDL_MAXVAL)
#define COM_SIGNAL_F_ALWAYS               ((Com_Signal_FilterHdlType)(COM_SIGNAL_FILTERHDL_MAXVAL - 1))
#define COM_SIGNAL_F_NEVER                ((Com_Signal_FilterHdlType)(COM_SIGNAL_FILTERHDL_MAXVAL - 2))
#define COM_SIGNAL_F_NEWISDIFFERENT       ((Com_Signal_FilterHdlType)(COM_SIGNAL_FILTERHDL_MAXVAL - 3))

#define COM_SIGNAL_F_MASKEDNEWDIFFERSOLD  ((Com_Signal_FilterAlgorithmType)0x01u)
#define COM_SIGNAL_F_MASKEDNEWEQUALSX     ((Com_Signal_FilterAlgorithmType)0x02u)
#define COM_SIGNAL_F_MASKEDNEWDIFFERSX    ((Com_Signal_FilterAlgorithmType)0x03u)
#define COM_SIGNAL_F_NEWISOUTSIDE         ((Com_Signal_FilterAlgorithmType)0x04u)
#define COM_SIGNAL_F_NEWISWITHIN          ((Com_Signal_FilterAlgorithmType)0x05u)

#define COM_SIGNAL_F_PARAM_MASK           ((Com_Signal_FilterParamRef)0x00u)
#define COM_SIGNAL_F_PARAM_X              ((Com_Signal_FilterParamRef)0x01u)
#define COM_SIGNAL_F_PARAM_MIN            ((Com_Signal_FilterParamRef)0x00u)
#define COM_SIGNAL_F_PARAM_MAX            ((Com_Signal_FilterParamRef)0x01u)
/* KB end Com_Signal_LocalConstantMacros */
/* KB begin Com_Buffer_LocalConstantMacros */
/* KB end Com_Buffer_LocalConstantMacros */
/* KB begin Com_RxBuffer_LocalConstantMacros */
/* KB end Com_RxBuffer_LocalConstantMacros */
/* KB begin Com_RxDlMon_LocalConstantMacros */
/* KB end Com_RxDlMon_LocalConstantMacros */
/* KB begin Com_RxLLIf_LocalConstantMacros */
#if (COM_RXLLIF == STD_ON) && (COM_RXPDUCALLOUT == STD_ON)
# define COM_RXLLIF_NO_PDUCALLOUT  ((Com_RxLLIf_PduCalloutIdType)0)
#endif
/* KB end Com_RxLLIf_LocalConstantMacros */
/* KB begin Com_RxNHdlr_LocalConstantMacros */
/* KB end Com_RxNHdlr_LocalConstantMacros */
/* KB begin Com_RxSigIf_LocalConstantMacros */
/* KB end Com_RxSigIf_LocalConstantMacros */
/* KB begin Com_RxUbHdlr_LocalConstantMacros */
/* KB end Com_RxUbHdlr_LocalConstantMacros */
/* KB begin Com_RxInv_LocalConstantMacros */
/* KB end Com_RxInv_LocalConstantMacros */
/* KB begin Com_TxInv_LocalConstantMacros */
/* KB end Com_TxInv_LocalConstantMacros */
/* KB begin Com_TxBuffer_LocalConstantMacros */
/* KB end Com_TxBuffer_LocalConstantMacros */
/* KB begin Com_TxDlMon_LocalConstantMacros */
#define COM_TXDLMON_COMTRANSMITCONTEXT     0x00u
/* KB end Com_TxDlMon_LocalConstantMacros */
/* KB begin Com_TxLLIf_LocalConstantMacros */
#if (COM_TXLLIF == STD_ON)
# if (COM_TXPDUCALLOUT == STD_ON)
#  define COM_TXLLIF_NO_PDUCALLOUT  ((Com_TxLLIf_PduCalloutIdType)0)
# endif /* (COM_TXPDUCALLOUT == STD_ON) */
# if (COM_TPINTERFACE == STD_ON)
#  define COM_TXLLIF_IFLAYER_PDU ((uint8)0x00u)
#  define COM_TXLLIF_TPLAYER_PDU ((uint8)0x01u)
# endif /* (COM_TPINTERFACE == STD_ON) */
#endif /* COM_TXLLIF == STD_ON */
/* KB end Com_TxLLIf_LocalConstantMacros */
/* KB begin Com_TxModeHdlr_LocalConstantMacros */
#if (COM_TXMODEHDLR == STD_ON)
# define COM_TXMODEHDLR_TXMODE_NONE      ((Com_TxModeHdlr_TxModeMode)0x00u)
# define COM_TXMODEHDLR_TXMODE_DIRECT    ((Com_TxModeHdlr_TxModeMode)0x01u)
# define COM_TXMODEHDLR_TXMODE_PERIODIC  ((Com_TxModeHdlr_TxModeMode)0x02u)
# define COM_TXMODEHDLR_TXMODE_MIXED     ((Com_TxModeHdlr_TxModeMode)0x03u)

# define COM_TXMODE_PARAM_TIMEOFFSET         ((Com_TxModeHdlr_TxModeParamRef)0x00u)
# define COM_TXMODE_PARAM_TIMEPERIOD         ((Com_TxModeHdlr_TxModeParamRef)0x01u)
# define COM_TXMODE_PARAM_REPETITIONCOUNT    ((Com_TxModeHdlr_TxModeParamRef)0x02u)
# define COM_TXMODE_PARAM_REPETITIONPERIOD   ((Com_TxModeHdlr_TxModeParamRef)0x03u)
#endif /* COM_TXMODEHDLR == STD_ON */
/* KB end Com_TxModeHdlr_LocalConstantMacros */
/* KB begin Com_TxNHdlr_LocalConstantMacros */
/* KB end Com_TxNHdlr_LocalConstantMacros */
/* KB begin Com_TxSigIf_LocalConstantMacros */
#if (COM_TXSIGIF == STD_ON)
# if (COM_SIGNALGROUPIF == STD_ON) || (COM_SIGNALIF == STD_ON)
/* this constant is used for signals that do not have an update bit */
#  define COM_TX_SIGIF_NOUPDATEBIT   ((Com_Signal_SignalBitPositionType)COM_SIGNAL_SIGBITPOSITION_MAXVAL)
# endif
# define COM_TX_SIGIF_TRIGGERED           (uint8)0x01u
# define COM_TX_SIGIF_TRIGGERED_ON_CHANGE (uint8)0x02u
#endif /* COM_TXSIGIF == STD_ON */
/* KB end Com_TxSigIf_LocalConstantMacros */
/* KB begin Com_SignalGw_LocalConstantMacros */
#if (COM_SIGNALGW == STD_ON)
# define COM_SIGNALGW_NOROUTINGHDL    ((PduIdType)COM_PDUID_MAXVAL)
# define COM_SIGNALGW_UBNOTUSED       ((Com_Signal_SignalBitPositionType)COM_SIGNAL_SIGBITPOSITION_MAXVAL)
# define COM_SIGNALGW_INVALIDSIGID    ((Com_SignalIdType)COM_SIGNALID_MAXVAL)
# if (COM_SIGNALGROUPIF == STD_ON)
#  define COM_SIGNALGW_INVALIDSIGGRPID ((Com_SignalGroupIdType)COM_SIGNALGROUPID_MAXVAL)
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
#endif /* (COM_SIGNALGW == STD_ON) */
/* KB end Com_SignalGw_LocalConstantMacros */

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/
/* KB begin Com_LMgt_LocalFunctionMacros */
#if (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF) && (COM_PROTECT_TIMEOUTFLAG == STD_OFF) && (COM_PROTECT_NOTIFICATIONFLAG == STD_OFF)
# if (COM_TSC_TESTCODE == STD_ON)
/* ##V_TEST_CODE_START ##Ms */
#  define COM_EXCLUSIVE_AREA_0
#  define COM_EXCLUSIVE_AREA_1
#  define COM_EXCLUSIVE_AREA_2
#  define COM_EXCLUSIVE_AREA_3
#  define COM_EXCLUSIVE_AREA_4
#  define SchM_Enter_Com(ComExlusiveAreaId)
#  define SchM_Exit_Com(ComExlusiveAreaId)
/* ##V_TEST_CODE_STOP ##Ms */
# else
# endif
#endif

#define Com_LMgt_GetIPduGroupCnt()                  (Com_ConfigValue(Com_LMgt_IPduGroupCnt))
#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
# define Com_LMgt_GetSubIPduGroupCnt()               (Com_ConfigValue(Com_LMgt_SubIPduGroupCnt))
#endif

#if ((COM_RXUBHDLR_TIMEOUT == STD_ON) || (COM_RXDLMON == STD_ON))
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
/**********************************************************************************************************************
  Com_LMgt_DmGroupActive
**********************************************************************************************************************/
#  if !defined ( COM_LMGT_DMGROUPACTIVE_STUBBED )
#   define Com_LMgt_DmGroupActive(IpduGroupId)        (FALSE != com_LMgt_DmGroupState[(IpduGroupId)])
#  endif

/**********************************************************************************************************************
  Com_LMgt_ActivateDmGroup
**********************************************************************************************************************/
#  if !defined ( COM_LMGT_ACTIVATEDMGROUP_STUBBED )
#   define Com_LMgt_ActivateDmGroup(IpduGroupId)   com_LMgt_DmGroupState[(IpduGroupId)] = TRUE
#  endif

/**********************************************************************************************************************
  Com_LMgt_DeactivateDmGroup
**********************************************************************************************************************/
#  if !defined ( COM_LMGT_DEACTIVATEDMGROUP_STUBBED )
#   define Com_LMgt_DeactivateDmGroup(IpduGroupId)   com_LMgt_DmGroupState[(IpduGroupId)] = FALSE
#  endif

# endif /* (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) */

/**********************************************************************************************************************
  Com_LMgt_RxIpduDmActive
**********************************************************************************************************************/
# if !defined ( COM_LMGT_RXIPDUDMACTIVE_STUBBED )
#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#   define Com_LMgt_RxIpduDmActive(ComRxPduId)        (0 < com_LMgt_RxDmState[(ComRxPduId)])
#  else
#   define Com_LMgt_RxIpduDmActive(ComRxPduId)        (FALSE != com_LMgt_RxDmState[(ComRxPduId)])
#  endif
# endif

/**********************************************************************************************************************
  Com_LMgt_ActivateRxIpduDm
**********************************************************************************************************************/
# if !defined ( COM_LMGT_ACTIVATERXIPDUDM_STUBBED )
#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#   define Com_LMgt_ActivateRxIpduDm(ComRxPduId)        com_LMgt_RxDmState[(ComRxPduId)]++
#  else
#   define Com_LMgt_ActivateRxIpduDm(ComRxPduId)        com_LMgt_RxDmState[(ComRxPduId)] = TRUE
#  endif
# endif

/**********************************************************************************************************************
  Com_LMgt_DeactivateRxIpduDm
**********************************************************************************************************************/
# if !defined ( COM_LMGT_DEACTIVATERXIPDUDM_STUBBED )
#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#   define Com_LMgt_DeactivateRxIpduDm(ComPduId)  com_LMgt_RxDmState[(ComPduId)]--
#  else
#   define Com_LMgt_DeactivateRxIpduDm(ComPduId)  com_LMgt_RxDmState[(ComPduId)] = FALSE
#  endif
# endif

#endif /* ((COM_RXUBHDLR_TIMEOUT == STD_ON) || (COM_RXDLMON == STD_ON)) */

#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
/**********************************************************************************************************************
  Com_LMgt_IPduGroupActive
**********************************************************************************************************************/
# if !defined ( COM_LMGT_IPDUGROUPACTIVE_STUBBED )
#  define Com_LMgt_IPduGroupActive(IpduGroupId)        (FALSE != com_LMgt_IPduGroupState[(IpduGroupId)])
# endif

/**********************************************************************************************************************
  Com_LMgt_ActivateIPduGroup
**********************************************************************************************************************/
# if !defined ( COM_LMGT_ACTIVATEIPDUGROUP_STUBBED )
#  define Com_LMgt_ActivateIPduGroup(IpduGroupId)      com_LMgt_IPduGroupState[(IpduGroupId)] = TRUE
# endif

/**********************************************************************************************************************
  Com_LMgt_DeactivateIPduGroup
**********************************************************************************************************************/
# if !defined ( COM_LMGT_DEACTIVATEIPDUGROUP_STUBBED )
#  define Com_LMgt_DeactivateIPduGroup(IpduGroupId)    com_LMgt_IPduGroupState[(IpduGroupId)] = FALSE
# endif

#endif /* (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) */

/**********************************************************************************************************************
  Com_LMgt_ActivateRxIpdu
**********************************************************************************************************************/
#if !defined ( COM_LMGT_ACTIVATERXIPDU_STUBBED )
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#  define Com_LMgt_ActivateRxIpdu(ComPduId)        com_LMgt_RxPduGroupState[(ComPduId)]++
# else
#  define Com_LMgt_ActivateRxIpdu(ComPduId)        com_LMgt_RxPduGroupState[(ComPduId)] = TRUE
# endif
#endif

/**********************************************************************************************************************
  Com_LMgt_DeactivateRxIpdu
**********************************************************************************************************************/
#if !defined ( COM_LMGT_DEACTIVATERXIPDU_STUBBED )
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#  define Com_LMgt_DeactivateRxIpdu(ComPduId)  com_LMgt_RxPduGroupState[(ComPduId)]--
# else
#  define Com_LMgt_DeactivateRxIpdu(ComPduId)  com_LMgt_RxPduGroupState[(ComPduId)] = FALSE
# endif
#endif

/**********************************************************************************************************************
  Com_LMgt_ActivateTxIpdu
**********************************************************************************************************************/
#if !defined ( COM_LMGT_ACTIVATETXIPDU_STUBBED )
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#  define Com_LMgt_ActivateTxIpdu(ComPduId)        com_LMgt_TxPduGroupState[(ComPduId)]++
# else
#  define Com_LMgt_ActivateTxIpdu(ComPduId)        com_LMgt_TxPduGroupState[(ComPduId)] = TRUE
# endif
#endif

/**********************************************************************************************************************
  Com_LMgt_DeactivateTxIpdu
**********************************************************************************************************************/
#if !defined ( COM_LMGT_DEACTIVATETXIPDU_STUBBED )
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#  define Com_LMgt_DeactivateTxIpdu(ComPduId)  com_LMgt_TxPduGroupState[(ComPduId)]--
# else
#  define Com_LMgt_DeactivateTxIpdu(ComPduId)  com_LMgt_TxPduGroupState[(ComPduId)] = FALSE
# endif
#endif
/* KB end Com_LMgt_LocalFunctionMacros */
/* KB begin Com_Signal_LocalFunctionMacros */
#if (COM_SIGNEXTENSION != STD_ON)
# define Com_Signal_ReadSignalSignConversion(SignalId, SignalApplDestPtr)
#endif

#if (COM_DEV_ERROR_DETECT == STD_ON)
# define  Com_Signal_GetSignalCnt()           (Com_ConfigValue(Com_Signal_SignalCnt))
#endif

#if (COM_SIGNALGROUPIF == STD_ON)
# define  Com_Signal_GetSignalGroupCnt()      (Com_ConfigValue(Com_Signal_SignalGroupCnt))
#endif

/** Returns the bit index in the byte, where the signal starts (0..7). */
#define Com_Signal_BitOffsetFromBitPos(pos)  ((uint8)((pos) & (uint8)0x07u))
/** Returns the byte index of a bit position. */
#define Com_Signal_ByteFromBitPos(pos)       ((pos) >> 3)

#define Com_SignalGetLength(SignalId)        (Com_Signal_GetSignalAttribute((SignalId), Length))
#define Com_SignalGetBitPosition(SignalId)   (Com_Signal_GetSignalAttribute((SignalId), BitPosition))

#define Com_Signal_GetSignalStartByte(sigId) (Com_Signal_ByteFromBitPos(Com_Signal_GetSignalAttribute((sigId), BitPosition)))

#if !defined ( COM_SIGNAL_GETIPDUFROMSIGNAL_STUBBED )
# define Com_Signal_GetIpduFromSignal(SignalId)             (Com_Signal_GetSignalAttribute((SignalId), Ipdu))
#endif

#if (COM_SIGNALGROUPIF == STD_ON)
# if !defined ( COM_SIGNAL_GETIPDUFROMSIGNALGROUP_STUBBED )
#  define Com_Signal_GetIpduFromSignalGroup(SignalGroupId)  (Com_ConfigValue(Com_Signal_SignalGroup2IpduIndirection)[SignalGroupId])
# endif
# define Com_Signal_GetSignalGroupMaskPtr(SignalGroupId)   (&(Com_ConfigValue(Com_Signal_SignalGroupMask)[Com_ConfigValue(Com_Signal_SignalGroupMaskIdx)[SignalGroupId]]))
# define Com_Signal_GetSignalGroupFromSignal(SignalId)     (Com_Signal_GetSignalAttribute((SignalId), SignalGroup))
# define Com_Signal_GetSignalGroupBufferPtr(SigGrpId)      (&(com_Buffer[Com_ConfigValue(Com_Signal_SigGrpBufferInfo)[SigGrpId].comBufferIdx]))
# define Com_Signal_GetSignalGroupBufferLength(SigGrpId)   (Com_ConfigValue(Com_Signal_SigGrpBufferInfo)[SigGrpId].grpByteLength)
# define Com_Signal_GetSignalGroupPduOffset(SigGrpId)      (Com_ConfigValue(Com_Signal_SigGrpBufferInfo)[SigGrpId].pduOffset)
#endif

#define Com_Signal_ApplTypeIsBoolean(AccessAttr)     ((AccessAttr) & COM_SIGNAL_APPLTYPE_BOOLEAN)
#define Com_Signal_ApplTypeIsUint8(AccessAttr)       ((AccessAttr) & COM_SIGNAL_APPLTYPE_UINT8)
#define Com_Signal_ApplTypeIsSint8(AccessAttr)       ((AccessAttr) & COM_SIGNAL_APPLTYPE_SINT8)
#define Com_Signal_ApplTypeIsUint16(AccessAttr)      ((AccessAttr) & COM_SIGNAL_APPLTYPE_UINT16)
#define Com_Signal_ApplTypeIsSint16(AccessAttr)      ((AccessAttr) & COM_SIGNAL_APPLTYPE_SINT16)
#define Com_Signal_ApplTypeIsUint32(AccessAttr)      ((AccessAttr) & COM_SIGNAL_APPLTYPE_UINT32)
#define Com_Signal_ApplTypeIsSint32(AccessAttr)      ((AccessAttr) & COM_SIGNAL_APPLTYPE_SINT32)
#define Com_Signal_ApplTypeIsUint8_N(AccessAttr)     ((AccessAttr) & COM_SIGNAL_APPLTYPE_UINT8_N)
#define Com_Signal_ApplTypeIsXint8(AccessAttr)       ((AccessAttr) & COM_SIGNAL_APPLTYPE_XINT8)
#define Com_Signal_ApplTypeIsXint16(AccessAttr)      ((AccessAttr) & COM_SIGNAL_APPLTYPE_XINT16)
#define Com_Signal_ApplTypeIsXint32(AccessAttr)      ((AccessAttr) & COM_SIGNAL_APPLTYPE_XINT32)
#define Com_Signal_ApplTypeNoLock(AccessAttr)        ((AccessAttr) & COM_SIGNAL_APPLTYPE_NOLOCK)

#define Com_Signal_BusAccIsNBit(AccessAttr)          ((AccessAttr) & COM_SIGNAL_BUSACC_NBIT)
#define Com_Signal_BusAccIsByte(AccessAttr)          ((AccessAttr) & COM_SIGNAL_BUSACC_BYTE)
#define Com_Signal_BusAccIsNByte(AccessAttr)         ((AccessAttr) & COM_SIGNAL_BUSACC_NBYTE)
#define Com_Signal_BusAccIsNByte_Sw(AccessAttr)      ((AccessAttr) & COM_SIGNAL_BUSACC_NBYTE_SW)
#define Com_Signal_BusAccIsNBitNByte(AccessAttr)     ((AccessAttr) & COM_SIGNAL_BUSACC_NBITNBYTE)
#define Com_Signal_BusAccIsNBitNByte_Sw(AccessAttr)  ((AccessAttr) & COM_SIGNAL_BUSACC_NBITNBYTE_SW)
#define Com_Signal_BusAccNoLock(AccessAttr)          ((AccessAttr) & COM_SIGNAL_BUSACC_NOLOCK)

#define Com_Signal_BusApplHaveSameSize(AccessAttr)   ((AccessAttr) & COM_SIGNAL_SAMEBITCOUNT)
#define Com_Signal_SignExtRequired(AccessAttr)       ((AccessAttr) & COM_SIGNAL_SIGN_EXTENSION)

#if (COM_SIGNALCONVERSION == STD_ON)
# define Com_Signal_GetConversion(SignalId)         (&Com_ConfigValue(Com_Signal_SignalConversion)[Com_Signal_GetSignalAttribute((SignalId), ConversionHdl)])
# define Com_Signal_ConversionIsSigned(convPtr)     (COM_SIGNAL_CONV_FALSE != ((convPtr)->Variant & COM_SIGNAL_CONV_TYPE_SIGNED))
# define Com_Signal_ConversionType(convPtr)         ((Com_Signal_ConversionVariantType)((convPtr)->Variant & COM_SIGNAL_CONV_TYPE_MASK))
#endif

#if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
# define COM_HIBYTE(val)   ((*(tWordToByte*)(&(val))).hibyte)
# define COM_LOBYTE(val)   ((*(tWordToByte*)(&(val))).lobyte)
#endif
/* KB end Com_Signal_LocalFunctionMacros */
/* KB begin Com_Buffer_LocalFunctionMacros */
/* KB end Com_Buffer_LocalFunctionMacros */
/* KB begin Com_RxBuffer_LocalFunctionMacros */
#if (COM_RXBUFFER == STD_ON)

# define Com_RxBuffer_GetRxIpduCnt()                  (Com_ConfigValue(Com_RxBuffer_RxIpduCnt))
# define Com_RxBuffer_GetIpduLength(ComRxPduId)       (Com_ConfigValue(Com_RxBuffer_IpduInfo)[ComRxPduId].length)
# define Com_RxBuffer_GetIpduCfgDataIdx(ComRxPduId)   (Com_ConfigValue(Com_RxBuffer_IpduInfo)[ComRxPduId].configDataIdx)
# define Com_RxBuffer_GetIpduDataPtr(ComRxPduId)      (&(com_Buffer[Com_ConfigValue(Com_RxBuffer_IpduInfo)[ComRxPduId].comBufferIdx]))
# define Com_RxBuffer_GetIpduInitValPtr(ComRxPduId)   (&(Com_ConfigValue(Com_RxBuffer_IpduInitValue)[Com_RxBuffer_GetIpduCfgDataIdx(ComRxPduId)]))

# if (COM_SIGNAL_ACCESS_MACRO_API != STD_ON)
#  if !defined ( COM_RXBUFFER_READIPDUSIGNAL_STUBBED )
#   define Com_RxBuffer_ReadIpduSignal(SignalId, RxPduId, SignalDataPtr)                                                   \
{                                                                                                                          \
  P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) SignalSourcePtr;                                                               \
  Com_Signal_AccessAttrType thisAccessAttr = Com_Signal_GetSignalAttribute((SignalId), AccessAttributes);                  \
  SignalSourcePtr = Com_RxBuffer_GetIpduDataPtr(RxPduId) + Com_Signal_GetSignalStartByte(SignalId);                        \
  if ( (COM_SIGNAL_FALSE != Com_Signal_ApplTypeNoLock(thisAccessAttr))                                                     \
    && (COM_SIGNAL_FALSE == Com_Signal_SignExtRequired(thisAccessAttr))                                                    \
    && (COM_SIGNAL_FALSE != Com_Signal_BusAccNoLock(thisAccessAttr))    ) {                                                \
    Com_Signal_ReadSignal((SignalId), (SignalDataPtr), (SignalSourcePtr), thisAccessAttr);                                 \
  } else {                                                                                                                 \
    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);                                                                                  \
    Com_Signal_ReadSignal((SignalId), (SignalDataPtr), (SignalSourcePtr), thisAccessAttr);                                 \
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);                                                                                   \
  }                                                                                                                        \
}
#  endif /* COM_RXBUFFER_READIPDUSIGNAL_STUBBED */
# endif /* (COM_SIGNAL_ACCESS_MACRO_API != STD_ON) */

# if (COM_RXSIGNAL_WRACCESS == STD_ON)
#  if !defined ( COM_RXBUFFER_WRITEIPDUSIGNAL_STUBBED )
#   define Com_RxBuffer_WriteIpduSignal(SignalId, RxPduId, SignalDataPtr)                                                  \
{                                                                                                                          \
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SignalDestPtr;                                                                   \
  Com_Signal_AccessAttrType thisAccessAttr = Com_Signal_GetSignalAttribute((SignalId), AccessAttributes);                  \
  SignalDestPtr = Com_RxBuffer_GetIpduDataPtr(RxPduId) + Com_Signal_GetSignalStartByte(SignalId);                          \
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsByte(thisAccessAttr)) {                                                       \
    Com_Signal_WriteSignal((SignalId), (SignalDestPtr), (SignalDataPtr), thisAccessAttr);                                  \
  } else {                                                                                                                 \
    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);                                                                                  \
    Com_Signal_WriteSignal((SignalId), (SignalDestPtr), (SignalDataPtr), thisAccessAttr);                                  \
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);                                                                                   \
  }                                                                                                                        \
}
#  endif /* COM_RXBUFFER_WRITEIPDUSIGNAL_STUBBED */
# endif

# if (COM_SIGNALGROUPIF == STD_ON)
#  if !defined ( COM_RXBUFFER_READSIGNALGROUP_STUBBED )
#   define Com_RxBuffer_ReadSignalGroup(SignalGroupId, RxPduId, ShadowBufferPtr)                                         \
{                                                                                                                      \
  Com_LMgt_MemCpyRamToRam(ShadowBufferPtr,                                                                             \
                          Com_RxBuffer_GetIpduDataPtr(RxPduId) + Com_Signal_GetSignalGroupPduOffset(SignalGroupId),    \
                          Com_Signal_GetSignalGroupBufferLength(SignalGroupId));                                       \
}
#  endif /* COM_RXBUFFER_READSIGNALGROUP_STUBBED */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
#endif /* COM_RXBUFFER == STD_ON */
/* KB end Com_RxBuffer_LocalFunctionMacros */
/* KB begin Com_RxDlMon_LocalFunctionMacros */
#if (COM_RXDLMON == STD_ON)
# define Com_RxDlMon_GetIpduTimeoutMask(ComRxPduId) (&(Com_ConfigValue(Com_RxDlMon_IpduTimeoutMask)[Com_RxBuffer_GetIpduCfgDataIdx(ComRxPduId)]))

# if !defined (COM_RXDLMON_INDICATION_STUBBED)
#  define Com_RxDlMon_Indication(ComRxPduId)     com_RxDlMon_TimeoutCnt[(ComRxPduId)] = Com_ConfigValue(Com_RxDlMon_TimeoutTime)[(ComRxPduId)]
# endif

# if !defined (COM_RXDLMON_INITTIMEOUT_STUBBED)
#  if (COM_RXDLMON_FIRSTTIMEOUT == STD_ON)
#   define Com_RxDlMon_InitTimeout(ComRxPduId)           com_RxDlMon_TimeoutCnt[(ComRxPduId)] = Com_ConfigValue(Com_RxDlMon_FirstTimeoutTime)[(ComRxPduId)]
#  else
#   define Com_RxDlMon_InitTimeout(ComRxPduId)           com_RxDlMon_TimeoutCnt[(ComRxPduId)] = Com_ConfigValue(Com_RxDlMon_TimeoutTime)[(ComRxPduId)]
#  endif
# endif

#endif
/* KB end Com_RxDlMon_LocalFunctionMacros */
/* KB begin Com_RxLLIf_LocalFunctionMacros */
/* KB end Com_RxLLIf_LocalFunctionMacros */
/* KB begin Com_RxNHdlr_LocalFunctionMacros */
#if (COM_RXNHDLR == STD_ON)
# if ((COM_RXINV_INHIBITNOTIFUNC == STD_ON) || (COM_RXNHDLR_INHIBITNOTIFUNC == STD_ON) || ((COM_DEV_ERROR_DETECT == STD_ON) && (COM_RXNHDLR_NOTIFICATIONFUNCTION == STD_ON)))
#  define Com_RxNHdlr_GetNotificationCnt()  (Com_RxNHdlr_NotificationCnt)
# endif
# if ((COM_RXINV_INHIBITINDFLAG == STD_ON) || (COM_RXNHDLR_INHIBITINDFLAG == STD_ON) || ((COM_DEV_ERROR_DETECT == STD_ON) && ((COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON) || (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON))))
#  define Com_RxNHdlr_GetNotificationFlagCnt()  (Com_RxNHdlr_NotiFlagCnt)
# endif
# if (COM_DEV_ERROR_DETECT == STD_ON)
#  if (COM_RXNHDLR_TIMEOUTFUNCTION == STD_ON)
#   define Com_RxNHdlr_GetTimeoutNotiCnt()     (Com_RxNHdlr_TimeoutNotiCnt)
#  endif
# endif /* (COM_DEV_ERROR_DETECT == STD_ON) */

# if (COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
#   define Com_RxNHdlr_HandleIPduDeferredEvent(ComRxPduId) (0 < com_RxNHdlr_HandleIPduDeferred[(ComRxPduId)])
#   define Com_RxNHdlr_ClrHandleIPduDeferredEvent(ComRxPduId) com_RxNHdlr_HandleIPduDeferred[(ComRxPduId)] = 0
#  else
#   define Com_RxNHdlr_HandleIPduDeferredEvent(ComRxPduId) (FALSE != com_RxNHdlr_HandleIPduDeferred[(ComRxPduId)])
#   define Com_RxNHdlr_ClrHandleIPduDeferredEvent(ComRxPduId) com_RxNHdlr_HandleIPduDeferred[(ComRxPduId)] = FALSE
#  endif/* (COM_DYNAMIC_DLC_SUPPORT == STD_ON) */
# endif/* (COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON) */
#endif /* COM_RXNHDLR == STD_ON */
/* KB end Com_RxNHdlr_LocalFunctionMacros */
/* KB begin Com_RxSigIf_LocalFunctionMacros */
/* KB end Com_RxSigIf_LocalFunctionMacros */
/* KB begin Com_RxUbHdlr_LocalFunctionMacros */
#if (COM_RXUBHDLR == STD_ON)
# if (COM_RXUBHDLR_TIMEOUTDEFAULTVALUE == STD_ON)
#  define Com_RxUbHdlr_GetIpduTimeoutMask(ubId) (&(Com_ConfigValue(Com_RxUbHdlr_TimeoutMask)[(Com_ConfigValue(Com_RxUbHdlr_TimeoutMaskIdx)[(ubId)])]))
# endif
# define Com_RxUbHdlr_GetUpdateBitCnt()    (Com_ConfigValue(Com_RxUbHdlr_UpdateBitCnt))
#endif
/* KB end Com_RxUbHdlr_LocalFunctionMacros */
/* KB begin Com_RxInv_LocalFunctionMacros */
/* KB end Com_RxInv_LocalFunctionMacros */
/* KB begin Com_TxInv_LocalFunctionMacros */
/* KB end Com_TxInv_LocalFunctionMacros */
/* KB begin Com_TxBuffer_LocalFunctionMacros */
#if (COM_TXBUFFER == STD_ON)
# define Com_TxBuffer_GetTxIpduCnt()                (Com_ConfigValue(Com_TxBuffer_TxIpduCnt))
# define Com_TxBuffer_GetIpduLength(ComTxPduId)     (Com_ConfigValue(Com_TxBuffer_IpduInfo)[ComTxPduId].length)
# define Com_TxBuffer_GetIpduCfgDataIdx(ComTxPduId) (Com_ConfigValue(Com_TxBuffer_IpduInfo)[ComTxPduId].configDataIdx)
# define Com_TxBuffer_GetIpduDataPtr(ComTxPduId)    (&(com_Buffer[Com_ConfigValue(Com_TxBuffer_IpduInfo)[ComTxPduId].comBufferIdx]))
# define Com_TxBuffer_GetIpduInitValPtr(ComTxPduId) (&(Com_ConfigValue(Com_TxBuffer_IpduInitValue)[Com_TxBuffer_GetIpduCfgDataIdx(ComTxPduId)]))

# if !defined ( COM_TXBUFFER_READIPDUSIGNAL_STUBBED )
#  define Com_TxBuffer_ReadIpduSignal(SignalId, TxPduId, SignalDataPtr)                                                    \
{                                                                                                                          \
  P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) SignalSourcePtr;                                                               \
  Com_Signal_AccessAttrType thisAccessAttr = Com_Signal_GetSignalAttribute((SignalId), AccessAttributes);                  \
  SignalSourcePtr = Com_TxBuffer_GetIpduDataPtr(TxPduId) + Com_Signal_GetSignalStartByte(SignalId);                        \
  if ( (COM_SIGNAL_FALSE != Com_Signal_ApplTypeNoLock(thisAccessAttr))                                                     \
    && (COM_SIGNAL_FALSE == Com_Signal_SignExtRequired(thisAccessAttr))                                                    \
    && (COM_SIGNAL_FALSE != Com_Signal_BusAccNoLock(thisAccessAttr))    ) {                                                \
    Com_Signal_ReadSignal((SignalId), (SignalDataPtr), (SignalSourcePtr), thisAccessAttr);                                 \
  } else {                                                                                                                 \
    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);                                                                                  \
    Com_Signal_ReadSignal((SignalId), (SignalDataPtr), (SignalSourcePtr), thisAccessAttr);                                 \
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);                                                                                   \
  }                                                                                                                        \
}
# endif /* COM_TXBUFFER_READIPDUSIGNAL_STUBBED */

# if !defined ( COM_TXBUFFER_WRITEIPDUSIGNAL_STUBBED )
#  define Com_TxBuffer_WriteIpduSignal(SignalId, TxPduId, SignalDataPtr)                                                   \
{                                                                                                                          \
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SignalDestPtr;                                                                   \
  Com_Signal_AccessAttrType thisAccessAttr = Com_Signal_GetSignalAttribute((SignalId), AccessAttributes);                  \
  SignalDestPtr = Com_TxBuffer_GetIpduDataPtr(TxPduId) + Com_Signal_GetSignalStartByte(SignalId);                          \
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsByte(thisAccessAttr)) {                                                       \
    Com_Signal_WriteSignal((SignalId), (SignalDestPtr), (SignalDataPtr), thisAccessAttr);                                  \
  } else {                                                                                                                 \
    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);                                                                                  \
    Com_Signal_WriteSignal((SignalId), (SignalDestPtr), (SignalDataPtr), thisAccessAttr);                                  \
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);                                                                                   \
  }                                                                                                                        \
}
# endif /* COM_TXBUFFER_WRITEIPDUSIGNAL_STUBBED */

# if (COM_SIGNALGROUPIF == STD_ON)
#  if !defined ( COM_TXBUFFER_READSIGNALGROUP_STUBBED )
#   define Com_TxBuffer_ReadSignalGroup(SignalGroupId, TxPduId, ShadowBufferPtr)                                        \
{                                                                                                                     \
  Com_LMgt_MemCpyRamToRam(ShadowBufferPtr,                                                                            \
                          Com_TxBuffer_GetIpduDataPtr(TxPduId) + Com_Signal_GetSignalGroupPduOffset(SignalGroupId),   \
                          Com_Signal_GetSignalGroupBufferLength(SignalGroupId));                                      \
}
#  endif /* COM_TXBUFFER_READSIGNALGROUP_STUBBED */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
#endif /* COM_TXBUFFER == STD_ON */
/* KB end Com_TxBuffer_LocalFunctionMacros */
/* KB begin Com_TxDlMon_LocalFunctionMacros */
#if (COM_TXDLMON == STD_ON)

# if (COM_TXDLMON_TXCONFIRMATION == STD_ON)
#  define Com_TxDlMon_IsComTransmitContext(ComTxPduId)    COM_TXDLMON_COMTRANSMITCONTEXT == Com_ConfigValue(Com_TxDlMon_TimeoutContext)[(ComTxPduId)]
#  define Com_TxDlMon_IsTxConfirmationContext(ComTxPduId) COM_TXDLMON_COMTRANSMITCONTEXT != Com_ConfigValue(Com_TxDlMon_TimeoutContext)[(ComTxPduId)]
# endif

# if !defined (COM_TXDLMON_START_STUBBED)
#  define Com_TxDlMon_Start(ComTxPduId)     com_TxDlMon_TimeoutCnt[(ComTxPduId)] = Com_ConfigValue(Com_TxDlMon_TimeoutTime)[(ComTxPduId)]
# endif

# if !defined (COM_TXDLMON_STOP_STUBBED)
#  define Com_TxDlMon_Stop(ComTxPduId)     com_TxDlMon_TimeoutCnt[(ComTxPduId)] = (uint16) 0
# endif

# if !defined (COM_TXDLMON_COMTRANSMIT_STUBBED)
#  if (COM_TXDLMON_TXCONFIRMATION != STD_ON)
#   define Com_TxDlMon_ComTransmit(ComTxPduId)                                                                        \
      if (0 == com_TxDlMon_TimeoutCnt[(ComTxPduId)]) {                                                                \
        Com_TxDlMon_Start((ComTxPduId));                                                                              \
      }
#  else
#   define Com_TxDlMon_ComTransmit(ComTxPduId)                                                                        \
      if ((Com_TxDlMon_IsComTransmitContext((ComTxPduId))) && (0 == com_TxDlMon_TimeoutCnt[(ComTxPduId)])) {          \
        Com_TxDlMon_Start((ComTxPduId));                                                                              \
      }
#  endif
# endif

# if !defined (COM_TXDLMON_CONFIRMATION_STUBBED)
#  if (COM_TXDLMON_TXCONFIRMATION != STD_ON)
#   define Com_TxDlMon_Confirmation(ComTxPduId)    Com_TxDlMon_Stop((ComTxPduId))
#  else
#   define Com_TxDlMon_Confirmation(ComTxPduId)                                                                       \
      if (Com_TxDlMon_IsComTransmitContext((ComTxPduId))) {                                                           \
        Com_TxDlMon_Stop((ComTxPduId));                                                                               \
      } else {                                                                                                        \
        Com_TxDlMon_Start((ComTxPduId));                                                                              \
      }
#  endif
# endif

# if !defined (COM_TXDLMON_IPDUGROUPSTART_STUBBED)
#  if (COM_TXDLMON_TXCONFIRMATION != STD_ON)
#   define Com_TxDlMon_IPduGroupStart(ComTxPduId)
#  else
#   define Com_TxDlMon_IPduGroupStart(ComTxPduId)                                                                     \
      if (Com_TxDlMon_IsTxConfirmationContext((ComTxPduId))) {                                                        \
        Com_TxDlMon_Start((ComTxPduId));                                                                              \
      }
#  endif
# endif

#endif /* (COM_TXDLMON == STD_ON) */
/* KB end Com_TxDlMon_LocalFunctionMacros */
/* KB begin Com_TxLLIf_LocalFunctionMacros */
#if (COM_TXLLIF == STD_ON)
# define Com_TxLLIf_GetIpduClearUbMask(ComTxIpdu) (&(Com_ConfigValue(Com_TxLLIf_ClearUbMask)[Com_ConfigValue(Com_TxBuffer_IpduInfo)[ComTxPduId].configDataIdx]))
#endif
/* KB end Com_TxLLIf_LocalFunctionMacros */
/* KB begin Com_TxModeHdlr_LocalFunctionMacros */
#if (COM_TXMODEHDLR == STD_ON)
/**********************************************************************************************************************
  Com_TxModeHdlr_TriggerIpduSendOnceDeferred
**********************************************************************************************************************/

# define Com_TxModeHdlr_TriggerIpduSendOnceDeferred(ComTxPduId)\
{\
  Com_LMgt_CheckFatalErrorRetVoid(((ComTxPduId) < Com_TxBuffer_GetTxIpduCnt()), Com_TxModeHdlr_Param_TriggerIpduSendOnceDeferred);\
  if (Com_LMgt_TxIpduActive(ComTxPduId))\
  {\
    com_TxModeHdlr_TransmitRequest[(ComTxPduId)] = TRUE;\
  }\
}                               /* End of Com_TxModeHdlr_TriggerIpduSendOnceDeferred() */

# define Com_TxModeHdlr_GetCurrentTxMode(TxPduId)          (Com_ConfigValue(Com_TxModeHdlr_TxMode)[com_TxModeHdlr_CurrentTxMode[(TxPduId)]].txMode)
# define Com_TxModeHdlr_GetTxModeParameter(TxPduId, Param) (Com_ConfigValue(Com_16BitValue)[Com_ConfigValue(Com_TxModeHdlr_TxMode)[com_TxModeHdlr_CurrentTxMode[(TxPduId)]].paramRef + (Param)])
#endif /* COM_TXMODEHDLR == STD_ON */
/* KB end Com_TxModeHdlr_LocalFunctionMacros */
/* KB begin Com_TxNHdlr_LocalFunctionMacros */
#if (COM_TXNHDLR == STD_ON)
# if (COM_TXERRORNOTIFICATION == STD_ON)
#  define Com_TxNHdlr_WaitForConfirmation(ComTxPduId) com_TxNHdlr_WaitingForConfirmation[(ComTxPduId)] = TRUE
# else
#  define Com_TxNHdlr_WaitForConfirmation(ComTxPduId)
# endif
# if (COM_DEV_ERROR_DETECT == STD_ON)
#  if ((COM_TXCONFIRMATION_DEFERRED == STD_ON) || (COM_TXCONFIRMATION_IMMEDIATE == STD_ON))
#   define Com_TxNHdlr_GetNotificationCnt()  (Com_TxNHdlr_NotificationCnt)
#  endif
#  if (COM_TXNHDLR_TIMEOUTFUNCTION == STD_ON)
#   define Com_TxNHdlr_GetTimeoutNotiCnt()     (Com_TxNHdlr_TimeoutNotiCnt)
#  endif
# endif /* (COM_DEV_ERROR_DETECT == STD_ON) */
#endif /* COM_TXNHDLR == STD_ON */
/* KB end Com_TxNHdlr_LocalFunctionMacros */
/* KB begin Com_TxSigIf_LocalFunctionMacros */
/* KB end Com_TxSigIf_LocalFunctionMacros */
/* KB begin Com_SignalGw_LocalFunctionMacros */
/* KB end Com_SignalGw_LocalFunctionMacros */

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/* KB begin Com_LMgt_LocalDataTypesAndStructures */
/* KB end Com_LMgt_LocalDataTypesAndStructures */
/* KB begin Com_Signal_LocalDataTypesAndStructures */
#if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
typedef unsigned int Com_BitType;

typedef struct
{
  Com_BitType lobyte:8;
  Com_BitType hibyte:8;
}
tWordToByte;
#endif
/* KB end Com_Signal_LocalDataTypesAndStructures */
/* KB begin Com_Buffer_LocalDataTypesAndStructures */
/* KB end Com_Buffer_LocalDataTypesAndStructures */
/* KB begin Com_RxBuffer_LocalDataTypesAndStructures */
/* KB end Com_RxBuffer_LocalDataTypesAndStructures */
/* KB begin Com_RxDlMon_LocalDataTypesAndStructures */
/* KB end Com_RxDlMon_LocalDataTypesAndStructures */
/* KB begin Com_RxLLIf_LocalDataTypesAndStructures */
/* KB end Com_RxLLIf_LocalDataTypesAndStructures */
/* KB begin Com_RxNHdlr_LocalDataTypesAndStructures */
#if (COM_RXNHDLR == STD_ON)
# if ((COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON) || (COM_RXNHDLR_TIMEOUTFLAG == STD_ON) || (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON) || (COM_RXUBHDLR_TIMEOUTFLAG == STD_ON))
typedef P2CONST(Com_RxNHdlr_FlagInfoType, TYPEDEF, COM_CONST) Com_RxNHdlr_FlagInfoRefType;
# endif
#endif /* COM_RXNHDLR == STD_ON */
/* KB end Com_RxNHdlr_LocalDataTypesAndStructures */
/* KB begin Com_RxSigIf_LocalDataTypesAndStructures */
/* KB end Com_RxSigIf_LocalDataTypesAndStructures */
/* KB begin Com_RxUbHdlr_LocalDataTypesAndStructures */
/* KB end Com_RxUbHdlr_LocalDataTypesAndStructures */
/* KB begin Com_RxInv_LocalDataTypesAndStructures */
/* KB end Com_RxInv_LocalDataTypesAndStructures */
/* KB begin Com_TxInv_LocalDataTypesAndStructures */
/* KB end Com_TxInv_LocalDataTypesAndStructures */
/* KB begin Com_TxBuffer_LocalDataTypesAndStructures */
/* KB end Com_TxBuffer_LocalDataTypesAndStructures */
/* KB begin Com_TxDlMon_LocalDataTypesAndStructures */
/* KB end Com_TxDlMon_LocalDataTypesAndStructures */
/* KB begin Com_TxLLIf_LocalDataTypesAndStructures */
/* KB end Com_TxLLIf_LocalDataTypesAndStructures */
/* KB begin Com_TxModeHdlr_LocalDataTypesAndStructures */
/* KB end Com_TxModeHdlr_LocalDataTypesAndStructures */
/* KB begin Com_TxNHdlr_LocalDataTypesAndStructures */
/* KB end Com_TxNHdlr_LocalDataTypesAndStructures */
/* KB begin Com_TxSigIf_LocalDataTypesAndStructures */
/* KB end Com_TxSigIf_LocalDataTypesAndStructures */
/* KB begin Com_SignalGw_LocalDataTypesAndStructures */
/* KB end Com_SignalGw_LocalDataTypesAndStructures */

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/* KB begin Com_LMgt_LocalDataPrototypes */
/* KB end Com_LMgt_LocalDataPrototypes */
/* KB begin Com_Signal_LocalDataPrototypes */
/* KB end Com_Signal_LocalDataPrototypes */
/* KB begin Com_Buffer_LocalDataPrototypes */
/* KB end Com_Buffer_LocalDataPrototypes */
/* KB begin Com_RxBuffer_LocalDataPrototypes */
/* KB end Com_RxBuffer_LocalDataPrototypes */
/* KB begin Com_RxDlMon_LocalDataPrototypes */
/* KB end Com_RxDlMon_LocalDataPrototypes */
/* KB begin Com_RxLLIf_LocalDataPrototypes */
/* KB end Com_RxLLIf_LocalDataPrototypes */
/* KB begin Com_RxNHdlr_LocalDataPrototypes */
/* KB end Com_RxNHdlr_LocalDataPrototypes */
/* KB begin Com_RxSigIf_LocalDataPrototypes */
/* KB end Com_RxSigIf_LocalDataPrototypes */
/* KB begin Com_RxUbHdlr_LocalDataPrototypes */
/* KB end Com_RxUbHdlr_LocalDataPrototypes */
/* KB begin Com_RxInv_LocalDataPrototypes */
/* KB end Com_RxInv_LocalDataPrototypes */
/* KB begin Com_TxInv_LocalDataPrototypes */
/* KB end Com_TxInv_LocalDataPrototypes */
/* KB begin Com_TxBuffer_LocalDataPrototypes */
/* KB end Com_TxBuffer_LocalDataPrototypes */
/* KB begin Com_TxDlMon_LocalDataPrototypes */
/* KB end Com_TxDlMon_LocalDataPrototypes */
/* KB begin Com_TxLLIf_LocalDataPrototypes */
/* KB end Com_TxLLIf_LocalDataPrototypes */
/* KB begin Com_TxModeHdlr_LocalDataPrototypes */
/* KB end Com_TxModeHdlr_LocalDataPrototypes */
/* KB begin Com_TxNHdlr_LocalDataPrototypes */
/* KB end Com_TxNHdlr_LocalDataPrototypes */
/* KB begin Com_TxSigIf_LocalDataPrototypes */
/* KB end Com_TxSigIf_LocalDataPrototypes */
/* KB begin Com_SignalGw_LocalDataPrototypes */
/* KB end Com_SignalGw_LocalDataPrototypes */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* KB begin Com_LMgt_GlobalDataDefinition */

/*======================================COM_START_SEC_CONST_32BIT==============================================*/
#define COM_START_SEC_CONST_32BIT
#include "MemMap.h"

#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
CONST(uint32, COM_CONST) IL_ASRCOM_LIB_SYMBOL = IL_ASRCOM_LIB_VERSION;
#endif

/*======================================COM_STOP_SEC_CONST_32BIT==============================================*/
#define COM_STOP_SEC_CONST_32BIT
#include "MemMap.h"

/*===================================COM_START_SEC_VAR_INIT_UNSPECIFIED=====================================*/
#define COM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

VAR(Com_StatusType, COM_VAR_INIT) com_LMgt_Status = COM_UNINIT;

/*====================================COM_STOP_SEC_VAR_INIT_UNSPECIFIED=====================================*/
#define COM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/*===================================COM_START_SEC_VAR_NOINIT_UNSPECIFIED=====================================*/
#define COM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if (COM_CONFIG_VARIANT == 3)
/**********************************************************************************************************************
  com_ConfigStructPtr
**********************************************************************************************************************/
/** \brief  If post build is configured this pointer points to the actual config struct. It is initialized 
            during Com_Init(...).
**********************************************************************************************************************/
P2CONST(Com_ConfigType, COM_VAR_NOINIT, COM_PBCFG) com_ConfigStructPtr;
#endif

/*====================================COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED=====================================*/
#define COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/* KB end Com_LMgt_GlobalDataDefinition */
/* KB begin Com_Signal_GlobalDataDefinition */
/* KB end Com_Signal_GlobalDataDefinition */
/* KB begin Com_Buffer_GlobalDataDefinition */
/* KB end Com_Buffer_GlobalDataDefinition */
/* KB begin Com_RxBuffer_GlobalDataDefinition */
/* KB end Com_RxBuffer_GlobalDataDefinition */
/* KB begin Com_RxDlMon_GlobalDataDefinition */
/* KB end Com_RxDlMon_GlobalDataDefinition */
/* KB begin Com_RxLLIf_GlobalDataDefinition */
/* KB end Com_RxLLIf_GlobalDataDefinition */
/* KB begin Com_RxNHdlr_GlobalDataDefinition */
/* KB end Com_RxNHdlr_GlobalDataDefinition */
/* KB begin Com_RxSigIf_GlobalDataDefinition */
/* KB end Com_RxSigIf_GlobalDataDefinition */
/* KB begin Com_RxUbHdlr_GlobalDataDefinition */
/* KB end Com_RxUbHdlr_GlobalDataDefinition */
/* KB begin Com_RxInv_GlobalDataDefinition */
/* KB end Com_RxInv_GlobalDataDefinition */
/* KB begin Com_TxInv_GlobalDataDefinition */
/* KB end Com_TxInv_GlobalDataDefinition */
/* KB begin Com_TxBuffer_GlobalDataDefinition */
/* KB end Com_TxBuffer_GlobalDataDefinition */
/* KB begin Com_TxDlMon_GlobalDataDefinition */
/* KB end Com_TxDlMon_GlobalDataDefinition */
/* KB begin Com_TxLLIf_GlobalDataDefinition */
#if (COM_TSI_TESTCODE == STD_ON)
/* ##V_TEST_CODE_START ##visdbi */
COM_STATIC VAR(PduIdType, COM_VAR_NOINIT) wTsiIl_AsrComTxConfirmationPduId;
/* ##V_TEST_CODE_END ##visdbi */
#endif /* (COM_TSI_TESTCODE == STD_ON) */
/* KB end Com_TxLLIf_GlobalDataDefinition */
/* KB begin Com_TxModeHdlr_GlobalDataDefinition */
/* KB end Com_TxModeHdlr_GlobalDataDefinition */
/* KB begin Com_TxNHdlr_GlobalDataDefinition */
/* KB end Com_TxNHdlr_GlobalDataDefinition */
/* KB begin Com_TxSigIf_GlobalDataDefinition */
/* KB end Com_TxSigIf_GlobalDataDefinition */
/* KB begin Com_SignalGw_GlobalDataDefinition */
/* KB end Com_SignalGw_GlobalDataDefinition */

/**********************************************************************************************************************
  GLOBAL COM FUNCTION PROTOTYPES
**********************************************************************************************************************/

/*===========================================COM_START_SEC_CODE======================================================*/
#define COM_START_SEC_CODE
#include "MemMap.h"

/* KB begin Com_LMgt_GlobalIl_AsrComFunctionPrototypes */
/* KB end Com_LMgt_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_Signal_GlobalIl_AsrComFunctionPrototypes */
#if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
/**********************************************************************************************************************
  Com_Signal_WriteSignal
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_Signal_WriteSignal(Com_SignalIdType SignalId,
                                                       P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SignalBusDestPtr,
                                                       P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalApplSourcePtr,
                                                       Com_Signal_AccessAttrType AccessAttr);
#endif /* ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */

#if ((COM_RXSIGNAL_ACCESS_MACRO_API != STD_ON) || (COM_F_MASKEDNEWDIFOLD == STD_ON) || ((COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)) || ((COM_TXMODEHDLR_TMS == STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)))
/**********************************************************************************************************************
  Com_Signal_ReadSignal
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_Signal_ReadSignal(Com_SignalIdType SignalId,
                                                      P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalApplDestPtr,
                                                      P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) SignalBusSourcePtr,
                                                      Com_Signal_AccessAttrType AccessAttr);

# if (COM_SIGNEXTENSION == STD_ON)
#  if ((COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
/**********************************************************************************************************************
  Com_Signal_ReadSignalSignConversion
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_Signal_ReadSignalSignConversion(Com_SignalIdType SignalId,
                                                                    P2VAR(void, AUTOMATIC,
                                                                          COM_APPL_VAR) SignalApplDestPtr,
                                                                    Com_Signal_AccessAttrType AccessAttr);
#  endif /* ((COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
# endif /* (COM_SIGNEXTENSION == STD_ON) */
#endif
/* KB end Com_Signal_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_Buffer_GlobalIl_AsrComFunctionPrototypes */
#if (COM_BUFFER == STD_ON)
# if (COM_SIGNALGROUPIF == STD_ON)
#  if ((COM_F_MASKEDNEWDIFOLD == STD_ON) || (COM_RXSIGNAL_ACCESS_MACRO_API != STD_ON) || ((COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)) || ((COM_TXMODEHDLR_TMS == STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)))
/**********************************************************************************************************************
  Com_Buffer_ReadShadowSignal
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_Buffer_ReadShadowSignal(Com_SignalIdType SignalId,
                                                            P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr,
                                                            P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr);
#  endif

#  if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
/**********************************************************************************************************************
  Com_Buffer_WriteShadowSignal
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_Buffer_WriteShadowSignal(Com_SignalIdType SignalId,
                                                             P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
                                                             P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr);
#  endif /* ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */
# endif
#endif /* COM_BUFFER == STD_ON */
/* KB end Com_Buffer_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_RxBuffer_GlobalIl_AsrComFunctionPrototypes */
#if (COM_RXBUFFER == STD_ON)
# if (COM_RXINV == STD_ON) || (COM_RXDLMON_TIMEOUTDEFAULTVALUE == STD_ON) || (COM_RXUBHDLR_TIMEOUTDEFAULTVALUE == STD_ON)
/**********************************************************************************************************************
  Com_RxBuffer_WriteIpduWithMask
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_RxBuffer_WriteIpduWithMask(PduIdType ComRxPduId,
                                                               P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduDataPtr,
                                                               P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduMaskPtr);
# endif

# if (COM_SIGNALGROUPIF == STD_ON)
#  if (COM_RXSIGNAL_WRACCESS == STD_ON)
/**********************************************************************************************************************
  Com_RxBuffer_WriteSignalGroup
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_RxBuffer_WriteSignalGroup(Com_SignalGroupIdType SignalGroupId,
                                                              P2CONST(uint8, AUTOMATIC,
                                                                      COM_VAR_NOINIT) ShadowBufferPtr);
#  endif
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
#endif /* COM_RXBUFFER == STD_ON */
/* KB end Com_RxBuffer_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_RxDlMon_GlobalIl_AsrComFunctionPrototypes */
/* KB end Com_RxDlMon_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_RxLLIf_GlobalIl_AsrComFunctionPrototypes */
/* KB end Com_RxLLIf_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_RxNHdlr_GlobalIl_AsrComFunctionPrototypes */
#if (COM_RXNHDLR == STD_ON)
# if ((COM_RXNHDLR_NOTIFICATIONFUNCTION == STD_ON) || ((COM_RXNHDLR_TIMEOUTFLAG == STD_ON) && (COM_RESET_TIMEOUTFLAG == STD_ON)) || (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON))
/**********************************************************************************************************************
  Com_RxNHdlr_Indication
**********************************************************************************************************************/
#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_RxNHdlr_Indication(PduIdType ComPduId, PduLengthType ComPduLength);
#  else
COM_STATIC FUNC(void, COM_CODE) Com_RxNHdlr_Indication(PduIdType ComPduId);
#  endif
# endif /* ((COM_RXNHDLR_NOTIFICATIONFUNCTION == STD_ON) || ((COM_RXNHDLR_TIMEOUTFLAG == STD_ON) && (COM_RESET_TIMEOUTFLAG == STD_ON)) || (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON)) */

# if ((COM_RXNHDLR_TIMEOUTFUNCTION == STD_ON) || (COM_RXNHDLR_TIMEOUTFLAG == STD_ON))
/**********************************************************************************************************************
  Com_RxNHdlr_Timeout
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_RxNHdlr_Timeout(PduIdType ComPduId);
# endif /* ((COM_RXNHDLR_TIMEOUTFUNCTION == STD_ON) || (COM_RXNHDLR_TIMEOUTFLAG == STD_ON)) */
#endif /* COM_RXNHDLR == STD_ON */
/* KB end Com_RxNHdlr_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_RxSigIf_GlobalIl_AsrComFunctionPrototypes */
/* KB end Com_RxSigIf_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_RxUbHdlr_GlobalIl_AsrComFunctionPrototypes */
#if ((COM_RXUBHDLR_NOTIFICATIONFUNCTION == STD_ON) || (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON))
/**********************************************************************************************************************
  Com_RxUbHdlr_Indication
**********************************************************************************************************************/
# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_RxUbHdlr_Indication(PduIdType ComPduId, PduLengthType ComPduLength);
# else
COM_STATIC FUNC(void, COM_CODE) Com_RxUbHdlr_Indication(PduIdType ComPduId);
# endif
#endif
/* KB end Com_RxUbHdlr_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_RxInv_GlobalIl_AsrComFunctionPrototypes */
#if (COM_RXINV_NOTIINVFUNC == STD_ON)
/**********************************************************************************************************************
  Com_RxInv_NotiInvalidNoUb
**********************************************************************************************************************/
# if ( (COM_RXINV_NOTIINVFUNC_NOUB_TO == STD_ON) || (COM_RXINV_NOTIINVFUNC_NOUB == STD_ON) )
COM_STATIC FUNC(void, COM_CODE) Com_RxInv_NotiInvalidNoUb(PduIdType ComRxPduId, boolean isContextTimeout);
# endif

/**********************************************************************************************************************
  Com_RxInv_NotiInvalidUb
**********************************************************************************************************************/
# if ( (COM_RXINV_NOTIINVFUNC_UB_TO == STD_ON) || (COM_RXINV_NOTIINVFUNC_UB == STD_ON) )
COM_STATIC FUNC(void, COM_CODE) Com_RxInv_NotiInvalidUb(Com_RxUbHdlr_UbIdType UbId, boolean isContextTimeout);
# endif
#endif /* (COM_RXINV_NOTIINVFUNC == STD_ON) */
/* KB end Com_RxInv_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_TxInv_GlobalIl_AsrComFunctionPrototypes */
/* KB end Com_TxInv_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_TxBuffer_GlobalIl_AsrComFunctionPrototypes */
#if (COM_TXBUFFER == STD_ON)
# if (COM_SIGNALGW_MSV == STD_ON)
/**********************************************************************************************************************
  Com_TxBuffer_WriteIpduWithMask
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxBuffer_WriteIpduWithMask(PduIdType ComTxPduId,
                                                               P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduDataPtr,
                                                               P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduMaskPtr);
# endif /* (COM_SIGNALGW_MSV == STD_ON) */


# if (COM_TXUBHDLR == STD_ON)
/**********************************************************************************************************************
  Com_TxBuffer_ClearMaskedBits
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxBuffer_ClearMaskedBits(PduIdType ComTxPduId,
                                                             P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduMaskPtr);
# endif


# if (COM_SIGNALGROUPIF == STD_ON)
/**********************************************************************************************************************
  Com_TxBuffer_WriteSignalGroup
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxBuffer_WriteSignalGroup(Com_SignalGroupIdType SignalGroupId,
                                                              P2CONST(uint8, AUTOMATIC,
                                                                      COM_VAR_NOINIT) ShadowBufferPtr);
# endif /* (COM_SIGNALGROUPIF == STD_ON) */

# if ((COM_TXSIGIF == STD_ON) && (COM_TXUBHDLR == STD_ON))
#  if ((COM_SIGNALGROUPIF == STD_ON) || ((COM_SIGNALIF == STD_ON) && ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))))
/**********************************************************************************************************************
  Com_TxBuffer_SetBit
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxBuffer_SetBit(PduIdType ComTxPduId, Com_Signal_SignalBitPositionType bitPos);
#  endif /* ((COM_SIGNALGROUPIF == STD_ON) || ((COM_SIGNALIF == STD_ON) && ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)))) */
# endif /* ((COM_TXSIGIF == STD_ON) && (COM_TXUBHDLR == STD_ON)) */
#endif /* COM_TXBUFFER == STD_ON */
/* KB end Com_TxBuffer_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_TxDlMon_GlobalIl_AsrComFunctionPrototypes */
/* KB end Com_TxDlMon_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_TxLLIf_GlobalIl_AsrComFunctionPrototypes */
#if (COM_TXLLIF == STD_ON)
/**********************************************************************************************************************
  Com_TxLLIf_Transmit
**********************************************************************************************************************/
COM_STATIC FUNC(Std_ReturnType, COM_CODE) Com_TxLLIf_Transmit(PduIdType ComTxPduId);
#endif /* COM_TXLLIF == STD_ON */
/* KB end Com_TxLLIf_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_TxModeHdlr_GlobalIl_AsrComFunctionPrototypes */
#if (COM_TXMODEHDLR == STD_ON)
# if ((COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) || (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON))
#  if ((COM_TXNHDLR_EMULATION == STD_OFF) || ((COM_TXNHDLR == STD_OFF) && (COM_TXLLIF == STD_ON)))
/**********************************************************************************************************************
  Com_TxModeHdlr_Confirmation
**********************************************************************************************************************/
COM_STATIC FUNC(boolean, COM_CODE) Com_TxModeHdlr_Confirmation(CONST(PduIdType, AUTOMATIC) ComTxPduId);
#  endif
# endif

/**********************************************************************************************************************
  Com_TxModeHdlr_InitTxMode
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxModeHdlr_InitTxMode(CONST(PduIdType, AUTOMATIC) ComTxPduId);

# if ((COM_SIGNALIF == STD_ON) && (COM_TXMODEHDLR_TMS == STD_ON))
/**********************************************************************************************************************
  Com_TxModeHdlr_UpdateTxMode
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxModeHdlr_UpdateTxMode(CONST(PduIdType, AUTOMATIC) ComTxPduId,
                                                            uint16 FilterByteOffs, uint8 FilterBitMask,
                                                            boolean FilterState);
# endif /* ((COM_SIGNALIF == STD_ON) && (COM_TXMODEHDLR_TMS == STD_ON)) */

# if ((COM_TXMODEHDLR_TMS == STD_ON) && ((COM_SIGNALIF == STD_ON) || (COM_SIGNALGROUPIF == STD_ON)))
/**********************************************************************************************************************
  Com_TxModeHdlr_UpdateTMS
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxModeHdlr_UpdateTMS(CONST(PduIdType, AUTOMATIC) ComTxPduId);
# endif /* ((COM_TXMODEHDLR_TMS == STD_ON) && ((COM_SIGNALIF == STD_ON) || (COM_SIGNALGROUPIF == STD_ON))) */

/**********************************************************************************************************************
  Com_TxModeHdlr_Stop
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxModeHdlr_Stop(CONST(PduIdType, AUTOMATIC) ComTxPduId);
#endif /* COM_TXMODEHDLR == STD_ON */
/* KB end Com_TxModeHdlr_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_TxNHdlr_GlobalIl_AsrComFunctionPrototypes */
#if (COM_TXNHDLR == STD_ON)
# if ((COM_TXNHDLR_EMULATION == STD_OFF) && ((COM_TXCONFIRMATION_DEFERRED == STD_ON) || (COM_TXCONFIRMATION_IMMEDIATE == STD_ON)))
/**********************************************************************************************************************
  Com_TxNHdlr_Confirmation
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxNHdlr_Confirmation(PduIdType ComTxPduId);
# endif

# if (COM_TXNHDLR_TIMEOUTFUNCTION == STD_ON)
/**********************************************************************************************************************
  Com_TxNHdlr_Timeout
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxNHdlr_Timeout(PduIdType ComTxPduId);
# endif
#endif /*COM_TXNHDLR == STD_ON */
/* KB end Com_TxNHdlr_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_TxSigIf_GlobalIl_AsrComFunctionPrototypes */
#if (COM_TXSIGIF == STD_ON)
# if ((COM_SIGNALIF == STD_ON) && (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON))
/**********************************************************************************************************************
  Com_TxSigIf_SendSignal
**********************************************************************************************************************/
COM_STATIC FUNC(uint8, COM_CODE) Com_TxSigIf_SendSignal(Com_SignalIdType SignalId,
                                                        P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr);
# endif /* ((COM_SIGNALIF == STD_ON) && (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)) */

# if (COM_SIGNALGROUPIF == STD_ON)
/**********************************************************************************************************************
  Com_TxSigIf_SendSignalGroup
**********************************************************************************************************************/
COM_STATIC FUNC(uint8, COM_CODE) Com_TxSigIf_SendSignalGroup(Com_SignalGroupIdType SignalGroupId,
                                                             P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr);
# endif /* (COM_SIGNALGROUPIF == STD_ON) */

# if (COM_SIGNALGROUPIF == STD_ON)
#  if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
/**********************************************************************************************************************
  Com_TxSigIf_UpdateShadowSignal
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_TxSigIf_UpdateShadowSignal(Com_SignalIdType SignalId,
                                                               P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
                                                               P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr);
#  endif /* ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
#endif /* COM_TXSIGIF == STD_ON */
/* KB end Com_TxSigIf_GlobalIl_AsrComFunctionPrototypes */
/* KB begin Com_SignalGw_GlobalIl_AsrComFunctionPrototypes */
#if (COM_SIGNALGW == STD_ON)
/**********************************************************************************************************************
  Com_SignalGw_Indication
**********************************************************************************************************************/
# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_SignalGw_Indication(PduIdType ComRxPduId, PduLengthType ComPduLength);
# else
COM_STATIC FUNC(void, COM_CODE) Com_SignalGw_Indication(PduIdType ComRxPduId);
# endif

# if (COM_SIGNALGW_RXTIMEOUT == STD_ON)
/**********************************************************************************************************************
  Com_SignalGw_RxIpduTimeout
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_SignalGw_RxIpduTimeout(PduIdType ComRxPduId);
# endif /* (COM_SIGNALGW_RXTIMEOUT == STD_ON) */
# if (COM_SIGNALGW_RXTIMEOUTUB == STD_ON)
/**********************************************************************************************************************
  Com_SignalGw_RxUbTimeout
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_SignalGw_RxUbTimeout(Com_RxUbHdlr_UbIdType ubId);
# endif /* (COM_SIGNALGW_RXTIMEOUTUB == STD_ON) */
#endif /* (COM_SIGNALGW == STD_ON) */
/* KB end Com_SignalGw_GlobalIl_AsrComFunctionPrototypes */

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/* KB begin Com_LMgt_LocalFunctionPrototypes */
/**********************************************************************************************************************
  Com_LMgt_InitRxIpdu
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_LMgt_InitRxIpdu(PduIdType ComPduId);

/**********************************************************************************************************************
  Com_LMgt_InitTxIpdu
**********************************************************************************************************************/
COM_STATIC FUNC(void, COM_CODE) Com_LMgt_InitTxIpdu(PduIdType ComPduId);
/* KB end Com_LMgt_LocalFunctionPrototypes */
/* KB begin Com_Signal_LocalFunctionPrototypes */
#if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF) || ((COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)))
/**********************************************************************************************************************
  Com_Signal_ApplyFilter
**********************************************************************************************************************/
COM_STATIC FUNC(boolean, COM_CODE) Com_Signal_ApplyFilter(Com_SignalIdType SignalId,
                                                          P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
                                                          Com_Signal_FilterHdlType ComSigFilter,
# if (COM_SIGNALGROUPIF == STD_ON)
                                                          P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) pShadowBuffer,
# endif
                                                          P2VAR(boolean, AUTOMATIC, AUTOMATIC) pWriteData);
#endif /* ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF) || ((COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))) */
/* KB end Com_Signal_LocalFunctionPrototypes */
/* KB begin Com_Buffer_LocalFunctionPrototypes */
/* KB end Com_Buffer_LocalFunctionPrototypes */
/* KB begin Com_RxBuffer_LocalFunctionPrototypes */
/* KB end Com_RxBuffer_LocalFunctionPrototypes */
/* KB begin Com_RxDlMon_LocalFunctionPrototypes */
/* KB end Com_RxDlMon_LocalFunctionPrototypes */
/* KB begin Com_RxLLIf_LocalFunctionPrototypes */
/* KB end Com_RxLLIf_LocalFunctionPrototypes */
/* KB begin Com_RxNHdlr_LocalFunctionPrototypes */
/* KB end Com_RxNHdlr_LocalFunctionPrototypes */
/* KB begin Com_RxSigIf_LocalFunctionPrototypes */
/* KB end Com_RxSigIf_LocalFunctionPrototypes */
/* KB begin Com_RxUbHdlr_LocalFunctionPrototypes */
/* KB end Com_RxUbHdlr_LocalFunctionPrototypes */
/* KB begin Com_RxInv_LocalFunctionPrototypes */
#if ((COM_RXINV == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF))
/**********************************************************************************************************************
  Com_RxInv_HasInvalidValue
**********************************************************************************************************************/
COM_STATIC FUNC(boolean, COM_CODE) Com_RxInv_HasInvalidValue(Com_SignalIdType SignalId,
                                                             P2CONST(void, AUTOMATIC, AUTOMATIC) SignalData);
#endif /* ((COM_RXINV == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF)) */
/* KB end Com_RxInv_LocalFunctionPrototypes */
/* KB begin Com_TxInv_LocalFunctionPrototypes */
/* KB end Com_TxInv_LocalFunctionPrototypes */
/* KB begin Com_TxBuffer_LocalFunctionPrototypes */
/* KB end Com_TxBuffer_LocalFunctionPrototypes */
/* KB begin Com_TxDlMon_LocalFunctionPrototypes */
/* KB end Com_TxDlMon_LocalFunctionPrototypes */
/* KB begin Com_TxLLIf_LocalFunctionPrototypes */
/* KB end Com_TxLLIf_LocalFunctionPrototypes */
/* KB begin Com_TxModeHdlr_LocalFunctionPrototypes */
/* KB end Com_TxModeHdlr_LocalFunctionPrototypes */
/* KB begin Com_TxNHdlr_LocalFunctionPrototypes */
/* KB end Com_TxNHdlr_LocalFunctionPrototypes */
/* KB begin Com_TxSigIf_LocalFunctionPrototypes */
/* KB end Com_TxSigIf_LocalFunctionPrototypes */
/* KB begin Com_SignalGw_LocalFunctionPrototypes */
/* KB end Com_SignalGw_LocalFunctionPrototypes */

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/
/* KB begin Com_LMgt_LocalFunctions */
#if (COM_LMGT_RX == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_LMgt_InitRxIpdu(PduIdType ComPduId)
{
  /* KB begin Com_Signal_InitRxIpdus */
  /* KB end Com_Signal_InitRxIpdus */
  /* KB begin Com_Buffer_InitRxIpdus */
  /* KB end Com_Buffer_InitRxIpdus */
  /* KB begin Com_RxBuffer_InitRxIpdus */
# if (COM_RXBUFFER == STD_ON)
  Com_LMgt_MemCpyRomToRam(Com_RxBuffer_GetIpduDataPtr((PduIdType) ComPduId),
                          Com_RxBuffer_GetIpduInitValPtr((PduIdType) ComPduId),
                          Com_RxBuffer_GetIpduLength((PduIdType) ComPduId));
# endif
  /* KB end Com_RxBuffer_InitRxIpdus */
  /* KB begin Com_RxDlMon_InitRxIpdus */
# if (COM_RXDLMON == STD_ON)
  Com_RxDlMon_InitTimeout((PduIdType) ComPduId);
# endif
  /* KB end Com_RxDlMon_InitRxIpdus */
  /* KB begin Com_RxUbHdlr_ResetDm */
# if (COM_RXUBHDLR_TIMEOUT == STD_ON)
  {
    uint16_least ubId;
    for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
         ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) (ComPduId + 1)]; ubId++)
    {
      Com_LMgt_CheckFatalErrorRetVoid((ubId < Com_RxUbHdlr_GetUpdateBitCnt()), Com_RxUbHdlr_InvalidUbHdl);
#  if (COM_RXUBHDLR_TIMEOUT == STD_ON)
#   if (COM_RXUBHDLR_FIRSTTIMEOUT == STD_ON)
      com_RxUbHdlr_TimeoutCnt[ubId] = Com_ConfigValue(Com_RxUbHdlr_FirstTimeoutTime)[ubId];
#   else
      com_RxUbHdlr_TimeoutCnt[ubId] = Com_ConfigValue(Com_RxUbHdlr_TimeoutTime)[ubId];
#   endif
#  endif
    }
  }
# endif /* (COM_RXUBHDLR_TIMEOUT == STD_ON) */
  /* KB end Com_RxUbHdlr_ResetDm */
  /* KB begin Com_RxLLIf_InitRxIpdus */
  /* KB end Com_RxLLIf_InitRxIpdus */
  /* KB begin Com_RxNHdlr_InitRxIpdus */
# if (COM_RXNHDLR == STD_ON)
#  if (COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
  com_RxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = 0;
#   else
  com_RxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = FALSE;
#   endif
        /* (COM_DYNAMIC_DLC_SUPPORT == STD_ON) */
#  endif

  /* KB begin Com_RxNHdlr_ClrRxNotificationFlag */
#  if (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON)
  {
    uint16_least notiFlagIndex;
    for (notiFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) ComPduId];
         notiFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) ComPduId + 1]; notiFlagIndex++)
    {
      Com_RxNHdlr_FlagInfoRefType notiFlagInfoPtr;
      Com_LMgt_CheckFatalErrorRetVoid((notiFlagIndex < Com_RxNHdlr_GetNotificationFlagCnt()),
                                      Com_RxNHdlr_NotiFlagIdxTooLarge);
      notiFlagInfoPtr =
        &Com_RxNHdlr_NotificationFlagInfo[Com_ConfigValue(Com_RxNHdlr_NotiFlagIndirection)[notiFlagIndex].notiFlagId];
      com_RxNHdlr_NotificationFlags[notiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
        COM_CAST2UINT8(~notiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
    }
  }
#  endif  /* (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON) */
  /* KB end Com_RxNHdlr_ClrRxNotificationFlag */
  /* KB begin Com_RxNHdlr_ClrRxTimeoutFlag */
#  if (COM_RXNHDLR_TIMEOUTFLAG == STD_ON)
  {
    uint16_least timeoutFlagIndex;
    for (timeoutFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) ComPduId];
         timeoutFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) (ComPduId + 1)];
         timeoutFlagIndex++)
    {
      Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
      Com_LMgt_CheckFatalErrorRetVoid((timeoutFlagIndex < Com_RxNHdlr_TimeoutFlagCnt),
                                      Com_RxNHdlr_TimeoutFlagIdxTooLarge);
      timeoutFlagInfoPtr =
        &Com_RxNHdlr_TimeoutFlagInfo[Com_ConfigValue(Com_RxNHdlr_TimeoutFlagIndirection)[timeoutFlagIndex]];
      com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
        COM_CAST2UINT8(~timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
    }
  }
#  endif  /* (COM_RXNHDLR_TIMEOUTFLAG == STD_ON) */
  /* KB end Com_RxNHdlr_ClrRxTimeoutFlag */

# endif /* COM_RXNHDLR == STD_ON */
  /* KB end Com_RxNHdlr_InitRxIpdus */
  /* KB begin Com_RxSigIf_InitRxIpdus */
  /* KB end Com_RxSigIf_InitRxIpdus */
  /* KB begin Com_RxUbHdlr_InitRxIpdus */
# if ((COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON) || (COM_RXUBHDLR_TIMEOUTFLAG == STD_ON) || (COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON))
  {
    uint16_least ubId;
    for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
         ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[((PduIdType) ComPduId) + 1]; ubId++)
    {
      Com_LMgt_CheckFatalErrorRetVoid((ubId < Com_RxUbHdlr_GetUpdateBitCnt()), Com_RxUbHdlr_InvalidUbHdl);
#  if (COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
      com_RxUbHdlr_HandleUbDeferred[ubId] = FALSE;
#  endif
      /* KB begin Com_RxUbHdlr_ClrRxNotificationFlag */
#  if (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON)
      {
        Com_RxNHdlr_NotiFlagIdType notiFlagIdx = Com_ConfigValue(Com_RxUbHdlr_NotiFlagHdl)[ubId];

        if (COM_RX_NHDLR_NONOTIFLAG != notiFlagIdx)
        {
          Com_RxNHdlr_FlagInfoRefType notiFlagInfoPtr;
          Com_LMgt_CheckFatalErrorRetVoid((notiFlagIdx < Com_RxNHdlr_NotiFlagCnt),
                                          Com_RxUbHdlr_NotificationFlagIdxTooLarge);
          notiFlagInfoPtr = &Com_RxNHdlr_NotificationFlagInfo[notiFlagIdx];
          com_RxNHdlr_NotificationFlags[notiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
            COM_CAST2UINT8(~notiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
        }
      }
#  endif /* (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON) */
      /* KB end Com_RxUbHdlr_ClrRxNotificationFlag */
      /* KB begin Com_RxUbHdlr_ClrRxTimeoutFlag */
#  if (COM_RXUBHDLR_TIMEOUTFLAG == STD_ON)
      {
        Com_RxNHdlr_TimeoutFlagIdType timeoutFlagIdx = Com_ConfigValue(Com_RxUbHdlr_TimeoutFlagHdl)[ubId];

        if (COM_RX_NHDLR_NOTIMEOUTFLAG != timeoutFlagIdx)
        {
          Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
          Com_LMgt_CheckFatalErrorBreak((timeoutFlagIdx < Com_RxNHdlr_TimeoutFlagCnt),
                                        Com_RxUbHdlr_TimeoutFlagIdxTooLarge);
          timeoutFlagInfoPtr = &Com_RxNHdlr_TimeoutFlagInfo[timeoutFlagIdx];
          com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
            COM_CAST2UINT8(~timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
        }
      }
#  endif
      /* KB end Com_RxUbHdlr_ClrRxTimeoutFlag */
    }
  }
# endif
  /* KB end Com_RxUbHdlr_InitRxIpdus */
  /* KB begin Com_RxInv_InitRxIpdus */
  {
# if (COM_RXINV_NOTIINVFUNC == STD_ON)
#  if (COM_RXINV_NOTIINVFUNC_UB == STD_ON)
    uint16_least UbIdx;
    uint16_least UbStopIdx;

    UbIdx = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
    UbStopIdx = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId + 1];

    for (; UbIdx < UbStopIdx; UbIdx++)
    {
      Com_RxInv_NotiInvalidUb((Com_RxUbHdlr_UbIdType) UbIdx, FALSE);
    }
#  endif /* (COM_RXINV_NOTIINVFUNC_UB == STD_ON) */
#  if (COM_RXINV_NOTIINVFUNC_NOUB == STD_ON)
    Com_RxInv_NotiInvalidNoUb((PduIdType) ComPduId, FALSE);
#  endif /* (COM_RXINV_NOTIINVFUNC_NOUB == STD_ON) */
# endif /* (COM_RXINV_NOTIINVFUNC == STD_ON) */
  }
  /* KB end Com_RxInv_InitRxIpdus */
  /* KB begin Com_TxInv_InitRxIpdus */
  /* KB end Com_TxInv_InitRxIpdus */
  /* KB begin Com_TxBuffer_InitRxIpdus */
  /* KB end Com_TxBuffer_InitRxIpdus */
  /* KB begin Com_TxDlMon_InitRxIpdus */
  /* KB end Com_TxDlMon_InitRxIpdus */
  /* KB begin Com_TxLLIf_InitRxIpdus */
  /* KB end Com_TxLLIf_InitRxIpdus */
  /* KB begin Com_TxModeHdlr_InitRxIpdus */
  /* KB end Com_TxModeHdlr_InitRxIpdus */
  /* KB begin Com_TxNHdlr_InitRxIpdus */
  /* KB end Com_TxNHdlr_InitRxIpdus */
  /* KB begin Com_TxSigIf_InitRxIpdus */
  /* KB end Com_TxSigIf_InitRxIpdus */
  /* KB begin Com_SignalGw_InitRxIpdus */
# if (COM_SIGNALGW == STD_ON)
  Com_SignalGw_ClrHandleSignalGwEvent((PduIdType) ComPduId);
#  if (COM_SIGNALGW_RXTIMEOUT == STD_ON)
  com_SignalGw_IPduTimeoutFlag[(PduIdType) ComPduId] = FALSE;
#  endif
#  if (COM_SIGNALGW_RXTIMEOUTUB == STD_ON)
  {
    uint16_least ubId;
    for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
         ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[((PduIdType) ComPduId) + 1]; ubId++)
    {
      com_SignalGw_UbTimeoutFlag[(Com_RxUbHdlr_UbIdType) ubId] = FALSE;
    }
  }
#  endif
# endif
  /* KB end Com_SignalGw_InitRxIpdus */
}                               /* End of Com_LMgt_InitRxIpdu() */
#endif

#if (COM_LMGT_TX == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_LMgt_InitTxIpdu(PduIdType ComPduId)
{
  /* KB begin Com_Signal_InitTxIpdus */
# if (COM_SIGNALGROUPIF == STD_ON)
  {
    Com_SignalGroupIdType sigGrpHnd;
    PduIdType iPduHnd;

    for (sigGrpHnd = Com_Signal_GetRxSignalGroupCnt(); sigGrpHnd < Com_Signal_GetSignalGroupCnt(); sigGrpHnd++)
    {
      iPduHnd = Com_Signal_GetIpduFromSignalGroup(sigGrpHnd);
      if ((PduIdType) ComPduId == iPduHnd)
      {
        uint16 initValueIdxOfSigGrp =
          Com_TxBuffer_GetIpduCfgDataIdx(iPduHnd) + Com_Signal_GetSignalGroupPduOffset(sigGrpHnd);
        Com_LMgt_MemCpyRomToRam(Com_Signal_GetSignalGroupBufferPtr(sigGrpHnd),
                                &(Com_ConfigValue(Com_TxBuffer_IpduInitValue)[initValueIdxOfSigGrp]),
                                Com_Signal_GetSignalGroupBufferLength(sigGrpHnd));
      }
    }
  }
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
  /* KB end Com_Signal_InitTxIpdus */
  /* KB begin Com_Buffer_InitTxIpdus */
  /* KB end Com_Buffer_InitTxIpdus */
  /* KB begin Com_RxBuffer_InitTxIpdus */
  /* KB end Com_RxBuffer_InitTxIpdus */
  /* KB begin Com_RxDlMon_InitTxIpdus */
  /* KB end Com_RxDlMon_InitTxIpdus */
  /* KB begin Com_RxLLIf_InitTxIpdus */
  /* KB end Com_RxLLIf_InitTxIpdus */
  /* KB begin Com_RxNHdlr_InitTxIpdus */
  /* KB end Com_RxNHdlr_InitTxIpdus */
  /* KB begin Com_RxSigIf_InitTxIpdus */
  /* KB end Com_RxSigIf_InitTxIpdus */
  /* KB begin Com_RxUbHdlr_InitTxIpdus */
  /* KB end Com_RxUbHdlr_InitTxIpdus */
  /* KB begin Com_RxInv_InitTxIpdus */
  /* KB end Com_RxInv_InitTxIpdus */
  /* KB begin Com_TxInv_InitTxIpdus */
  /* KB end Com_TxInv_InitTxIpdus */
  /* KB begin Com_TxBuffer_InitTxIpdus */
# if (COM_TXBUFFER == STD_ON)
  Com_LMgt_MemCpyRomToRam(Com_TxBuffer_GetIpduDataPtr((PduIdType) ComPduId),
                          Com_TxBuffer_GetIpduInitValPtr((PduIdType) ComPduId),
                          Com_TxBuffer_GetIpduLength((PduIdType) ComPduId));
# endif
  /* KB end Com_TxBuffer_InitTxIpdus */
  /* KB begin Com_TxDlMon_InitTxIpdus */
# if (COM_TXDLMON == STD_ON)
  Com_TxDlMon_Stop((PduIdType) ComPduId);
# endif
  /* KB end Com_TxDlMon_InitTxIpdus */
  /* KB begin Com_TxLLIf_InitTxIpdus */
# if (COM_TPINTERFACE == STD_ON)
  com_TxLLIf_TpPduInfo[(PduIdType) ComPduId].lockedForTpTx = FALSE;
# endif
  /* KB end Com_TxLLIf_InitTxIpdus */
  /* KB begin Com_TxModeHdlr_InitTxIpdus */
# if (COM_TXMODEHDLR == STD_ON)
#  if (COM_TXMODEHDLR_TXMODEFALSE == STD_ON)
  {
    uint16_least FilterStartIndex = Com_ConfigValue(Com_TxModeHdlr_SigFilterStartIdx)[0];
    uint16_least FilterByteIndex = Com_ConfigValue(Com_TxModeHdlr_SigFilterStartIdx)[(PduIdType) ComPduId];
    uint16_least FilterStopIndex = Com_ConfigValue(Com_TxModeHdlr_SigFilterStartIdx)[(PduIdType) ComPduId + 1];
    boolean TxMode = (boolean) ((FilterByteIndex == FilterStopIndex) ? TRUE : FALSE);

    for (; FilterByteIndex < FilterStopIndex; FilterByteIndex++)
    {
      uint8 FilterState = Com_ConfigValue(Com_TxModeHdlr_FilterStateInitBytes)[FilterByteIndex - FilterStartIndex];
      com_Buffer[FilterByteIndex] = FilterState;

      if (FilterState > 0)
      {
        TxMode = TRUE;
      }
    }
    com_TxModeHdlr_CurrentTxMode[(PduIdType) ComPduId] =
      (FALSE ==
       TxMode) ? Com_ConfigValue(Com_TxModeHdlr_TxModeFalse)[(PduIdType) ComPduId] :
      Com_ConfigValue(Com_TxModeHdlr_TxModeTrue)[(PduIdType) ComPduId];
  }
#  else /* (COM_TXMODEHDLR_TXMODEFALSE == STD_OFF) */
  com_TxModeHdlr_CurrentTxMode[(PduIdType) ComPduId] = Com_ConfigValue(Com_TxModeHdlr_TxModeTrue)[(PduIdType) ComPduId];
#  endif /* (COM_TXMODEHDLR_TXMODEFALSE == STD_ON) */
  Com_TxModeHdlr_InitTxMode((PduIdType) ComPduId);
#  if (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON)
  if (com_TxModeHdlr_CyclicSendRequest[(PduIdType) ComPduId] == TRUE)
  {
    com_TxModeHdlr_CycleTimeCnt[(PduIdType) ComPduId] =
      Com_TxModeHdlr_GetTxModeParameter((PduIdType) ComPduId, COM_TXMODE_PARAM_TIMEOFFSET);
  }
#  endif /* (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON) */
#  if (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON)
  com_TxModeHdlr_DelayTimeCnt[(PduIdType) ComPduId] = (uint16) 0u;
#  endif /* (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) */
# endif /* COM_TXMODEHDLR == STD_ON */
  /* KB end Com_TxModeHdlr_InitTxIpdus */
  /* KB begin Com_TxNHdlr_InitTxIpdus */
# if (COM_TXNHDLR == STD_ON)
#  if (COM_TXCONFIRMATION_DEFERRED == STD_ON)
  com_TxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = FALSE;
#  endif
#  if (COM_TXERRORNOTIFICATION == STD_ON)
  com_TxNHdlr_WaitingForConfirmation[(PduIdType) ComPduId] = FALSE;
#  endif
# endif
  /* KB end Com_TxNHdlr_InitTxIpdus */
  /* KB begin Com_TxSigIf_InitTxIpdus */
# if (COM_TXSIGIF == STD_ON)
#  if (COM_SIGNALGROUPIF == STD_ON)
  {
#   if (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)
    Com_SignalGroupIdType sigGrpHnd = Com_Signal_GetRxSignalGroupCnt();
    for (; sigGrpHnd < Com_Signal_GetSignalGroupCnt(); sigGrpHnd++)
    {
      if ((PduIdType) ComPduId == Com_Signal_GetIpduFromSignalGroup(sigGrpHnd))
      {
        com_TxSigIf_SignalGroupEventFlag[(sigGrpHnd - Com_Signal_GetRxSignalGroupCnt())] = FALSE;
      }
    }
#   endif /* (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) */
  }
#  endif /* (COM_SIGNALGROUPIF == STD_ON) */
# endif /*COM_TXSIGIF == STD_ON */
  /* KB end Com_TxSigIf_InitTxIpdus */
  /* KB begin Com_SignalGw_InitTxIpdus */
  /* KB end Com_SignalGw_InitTxIpdus */
}                               /* End of Com_LMgt_InitTxIpdu() */
#endif
/* KB end Com_LMgt_LocalFunctions */
/* KB begin Com_Signal_LocalFunctions */
#if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF) || ((COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)))
COM_STATIC FUNC(boolean, COM_CODE) Com_Signal_ApplyFilter(Com_SignalIdType SignalId,
                                                          P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
                                                          Com_Signal_FilterHdlType ComSigFilter,
# if (COM_SIGNALGROUPIF == STD_ON)
                                                          P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) pShadowBuffer,
# endif
                                                          P2VAR(boolean, AUTOMATIC, AUTOMATIC) pWriteData)
{
  boolean FilterState = FALSE;
  switch (ComSigFilter)
  {

# if (COM_F_ALWAYS == STD_ON)
  case COM_SIGNAL_F_ALWAYS:
    FilterState = TRUE;
    break;
# endif/* (COM_F_ALWAYS == STD_ON) */

# if (COM_TMS_SUPPORT == STD_ON)

#  if (COM_F_NEVER == STD_ON)
  case COM_SIGNAL_F_NEVER:
    break;
#  endif/* (COM_F_NEVER == STD_ON) */
# endif/* (COM_TMS_SUPPORT == STD_ON) */


# if ((COM_F_MASKEDNEWDIFOLD == STD_ON) || (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))
  case COM_SIGNAL_F_NEWISDIFFERENT:
    {
      uint32 OldSignalData = (uint32) 0;
      P2VAR(uint32, AUTOMATIC, COM_APPL_VAR) OldSignalDataPtr = &OldSignalData;
#  if ((COM_APPLTYPE_BOOLEAN == STD_ON) || (COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
      Com_Signal_AccessAttrType AccessAttr = Com_Signal_GetSignalAttribute((SignalId), AccessAttributes);
#  endif
      /* read the old signal data */
#  if (COM_SIGNALGROUPIF == STD_ON)
      if ((P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT)) NULL_PTR != pShadowBuffer)
      {
        Com_Buffer_ReadShadowSignal(SignalId, OldSignalDataPtr, pShadowBuffer);
      }
      else
#  endif
      {
        PduIdType ComTxPduId = Com_Signal_GetIpduFromSignal(SignalId);
        Com_TxBuffer_ReadIpduSignal(SignalId, ComTxPduId, OldSignalDataPtr);
      }
      /* compare the signal data */
#  if (COM_APPLTYPE_BOOLEAN == STD_ON)
      if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsBoolean(AccessAttr))
      {
        FilterState =
          (boolean) (((*((P2CONST(boolean, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) !=
                      (*((P2CONST(boolean, AUTOMATIC, AUTOMATIC)) (void *) OldSignalDataPtr))) ? TRUE : FALSE);
      }
      else
#  endif/* (COM_APPLTYPE_BOOLEAN == STD_ON) */
#  if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON))
      if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint8(AccessAttr))
      {
        FilterState =
          (boolean) (((*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) !=
                      (*((P2CONST(uint8, AUTOMATIC, AUTOMATIC)) (void *) OldSignalDataPtr))) ? TRUE : FALSE);
      }
      else
#  endif/* ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON)) */
#  if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
      if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
      {
        FilterState =
          (boolean) (((*((P2CONST(uint16, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) !=
                      (*((P2CONST(uint16, AUTOMATIC, AUTOMATIC)) (void *) OldSignalDataPtr))) ? TRUE : FALSE);
      }
      else
#  endif/* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
      {
        Com_LMgt_CheckFatalErrorRetValue((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)),
                                         Com_Signal_UnsupportedBusSignalType, FALSE);
#  if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
        FilterState =
          (boolean) (((*((P2CONST(uint32, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) !=
                      (*((P2CONST(uint32, AUTOMATIC, AUTOMATIC)) (void *) OldSignalDataPtr))) ? TRUE : FALSE);
#  endif/* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
      }

      if (FALSE == FilterState)
      {
        /* the data has not changed -> no need to write */
        (*pWriteData) = FALSE;
      }
    }
    break;
# endif/* ((COM_F_MASKEDNEWDIFOLD == STD_ON) || (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)) */

  default:
# if (COM_TXMODEHDLR_TMS == STD_ON)
    {
#  if ((COM_F_MASKEDNEWDIFOLD == STD_ON) || (COM_F_MASKEDNEWEQUALSX == STD_ON) || (COM_F_MASKEDNEWDIFFERSX == STD_ON) || (COM_F_NEWISOUTSIDE == STD_ON) || (COM_F_NEWISWITHIN == STD_ON))
      Com_Signal_AccessAttrType AccessAttr = Com_Signal_GetSignalAttribute((SignalId), AccessAttributes);
      switch (Com_ConfigValue(Com_Signal_SignalFilter)[ComSigFilter].FilterAlgorithm)
      {

#   if (COM_F_MASKEDNEWDIFOLD == STD_ON)
      case COM_SIGNAL_F_MASKEDNEWDIFFERSOLD:
        {
          uint32 OldSignalData = (uint32) 0;
          P2VAR(uint32, AUTOMATIC, COM_APPL_VAR) OldSignalDataPtr = &OldSignalData;
#    if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
          Com_Signal_FilterParamRef FilterParamRef = Com_ConfigValue(Com_Signal_SignalFilter[ComSigFilter]).ParamRef;
#    endif

          /* read the old signal data */
#    if (COM_SIGNALGROUPIF == STD_ON)
          if ((P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT)) NULL_PTR != pShadowBuffer)
          {
            /* grouped signal */
            Com_Buffer_ReadShadowSignal(SignalId, OldSignalDataPtr, pShadowBuffer);
          }
          else
#    endif
          {
            /* ungrouped signal */
            PduIdType ComTxPduId = Com_Signal_GetIpduFromSignal(SignalId);
            Com_TxBuffer_ReadIpduSignal(SignalId, ComTxPduId, OldSignalDataPtr);
          }
          /* compare the signal data */
#    if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON))
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint8(AccessAttr))
          {
            uint8 mask = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            FilterState =
              (boolean) ((((*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) !=
                          ((*((P2CONST(uint8, AUTOMATIC, AUTOMATIC)) (void *) OldSignalDataPtr)) & mask)) ? TRUE :
                         FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_UINT8 == STD_ON) */
#    if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          {
            uint16 mask = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            FilterState =
              (boolean) ((((*((P2CONST(uint16, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) !=
                          ((*((P2CONST(uint16, AUTOMATIC, AUTOMATIC)) (void *) OldSignalDataPtr)) & mask)) ? TRUE :
                         FALSE);
          }
          else
#    endif/* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
          {
            Com_LMgt_CheckFatalErrorRetValue((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)),
                                             Com_Signal_UnsupportedBusSignalType, FALSE);
#    if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
            {
              uint32 mask = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
              FilterState =
                (boolean) ((((*((P2CONST(uint32, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) !=
                            ((*((P2CONST(uint32, AUTOMATIC, AUTOMATIC)) (void *) OldSignalDataPtr)) & mask)) ? TRUE :
                           FALSE);
            }
#    endif/* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
          }
        }
        break;
#   endif/* (COM_F_MASKEDNEWDIFOLD == STD_ON) */


#   if (COM_F_MASKEDNEWEQUALSX == STD_ON)
      case COM_SIGNAL_F_MASKEDNEWEQUALSX:
        {
#    if ((COM_APPLTYPE_BOOLEAN == STD_ON) || (COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
          Com_Signal_FilterParamRef FilterParamRef = Com_ConfigValue(Com_Signal_SignalFilter[ComSigFilter]).ParamRef;
#    endif
#    if (COM_APPLTYPE_BOOLEAN == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsBoolean(AccessAttr))
          {
            boolean mask = (boolean) Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            boolean filterX = (boolean) Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            FilterState =
              (boolean) ((((*((P2CONST(boolean, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) ==
                          filterX) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_BOOLEAN == STD_ON) */
#    if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON))
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint8(AccessAttr))
          {
            uint8 mask = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint8 filterX = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            FilterState =
              (boolean) ((((*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) ==
                          filterX) ? TRUE : FALSE);
          }
          else
#    endif/* ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON)) */
#    if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          {
            uint16 mask = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint16 filterX = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            FilterState =
              (boolean) ((((*((P2CONST(uint16, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) ==
                          filterX) ? TRUE : FALSE);
          }
          else
#    endif/* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
          {
            Com_LMgt_CheckFatalErrorRetValue((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)),
                                             Com_Signal_UnsupportedBusSignalType, FALSE);
#    if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
            {
              uint32 mask = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
              uint32 filterX = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
              FilterState =
                (boolean) ((((*((P2CONST(uint32, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) ==
                            filterX) ? TRUE : FALSE);
            }
#    endif
          }
          break;
        }
#   endif/* (COM_F_MASKEDNEWEQUALSX == STD_ON) */


#   if (COM_F_MASKEDNEWDIFFERSX == STD_ON)
      case COM_SIGNAL_F_MASKEDNEWDIFFERSX:
        {
#    if ((COM_APPLTYPE_BOOLEAN == STD_ON) || (COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
          Com_Signal_FilterParamRef FilterParamRef = Com_ConfigValue(Com_Signal_SignalFilter[ComSigFilter]).ParamRef;
#    endif
#    if (COM_APPLTYPE_BOOLEAN == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsBoolean(AccessAttr))
          {
            boolean mask = (boolean) Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            boolean filterX = (boolean) Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            FilterState =
              (boolean) ((((*((P2CONST(boolean, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) !=
                          filterX) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_BOOLEAN == STD_ON) */
#    if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON))
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint8(AccessAttr))
          {
            uint8 mask = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint8 filterX = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            FilterState =
              (boolean) ((((*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) !=
                          filterX) ? TRUE : FALSE);
          }
          else
#    endif/* ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON)) */
#    if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          {
            uint16 mask = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint16 filterX = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            FilterState =
              (boolean) ((((*((P2CONST(uint16, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) !=
                          filterX) ? TRUE : FALSE);
          }
          else
#    endif/* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
          {
            Com_LMgt_CheckFatalErrorRetValue((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)),
                                             Com_Signal_UnsupportedBusSignalType, FALSE);
#    if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
            {
              uint32 mask = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
              uint32 filterX = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
              FilterState =
                (boolean) ((((*((P2CONST(uint32, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr)) & mask) !=
                            filterX) ? TRUE : FALSE);
            }
#    endif/* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
          }
          break;
        }
#   endif/* (COM_F_MASKEDNEWDIFFERSX == STD_ON) */


#   if (COM_F_NEWISOUTSIDE == STD_ON)
      case COM_SIGNAL_F_NEWISOUTSIDE:
        {
#    if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
          Com_Signal_FilterParamRef FilterParamRef = Com_ConfigValue(Com_Signal_SignalFilter[ComSigFilter]).ParamRef;
#    endif
#    if (COM_APPLTYPE_UINT8 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint8(AccessAttr))
          {
            uint8 min = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint8 max = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            uint8 value = (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((value < min) || (max < value)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_UINT8 == STD_ON) */
#    if (COM_APPLTYPE_SINT8 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint8(AccessAttr))
          {
            sint8 min = (sint8) Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            sint8 max = (sint8) Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            sint8 value = (*((P2CONST(sint8, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((value < min) || (max < value)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_SINT8 == STD_ON) */
#    if (COM_APPLTYPE_UINT16 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint16(AccessAttr))
          {
            uint16 min = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint16 max = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            uint16 value = (*((P2CONST(uint16, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((value < min) || (max < value)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_UINT16 == STD_ON) */
#    if (COM_APPLTYPE_SINT16 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint16(AccessAttr))
          {
            sint16 min = (sint16) Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            sint16 max = (sint16) Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            sint16 value = (*((P2CONST(sint16, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((value < min) || (max < value)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_SINT16 == STD_ON) */
#    if (COM_APPLTYPE_UINT32 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint32(AccessAttr))
          {
            uint32 min = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint32 max = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            uint32 value = (*((P2CONST(uint32, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((value < min) || (max < value)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_UINT32 == STD_ON) */
          {
            Com_LMgt_CheckFatalErrorRetValue((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint32(AccessAttr)),
                                             Com_Signal_UnsupportedBusSignalType, FALSE);
#    if (COM_APPLTYPE_SINT32 == STD_ON)
            {
              sint32 min = (sint32) Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
              sint32 max = (sint32) Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
              sint32 value = (*((P2CONST(sint32, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
              FilterState = (boolean) (((value < min) || (max < value)) ? TRUE : FALSE);
            }
#    endif/* (COM_APPLTYPE_SINT32 == STD_ON) */
          }
          break;
        }
#   endif/* (COM_F_NEWISOUTSIDE == STD_ON) */


#   if (COM_F_NEWISWITHIN == STD_ON)
      case COM_SIGNAL_F_NEWISWITHIN:
        {
#    if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
          Com_Signal_FilterParamRef FilterParamRef = Com_ConfigValue(Com_Signal_SignalFilter[ComSigFilter]).ParamRef;
#    endif
#    if (COM_APPLTYPE_UINT8 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint8(AccessAttr))
          {
            uint8 min = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint8 max = Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            uint8 value = (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((min <= value) && (value <= max)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_UINT8 == STD_ON) */
#    if (COM_APPLTYPE_SINT8 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint8(AccessAttr))
          {
            sint8 min = (sint8) Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            sint8 max = (sint8) Com_ConfigValue(Com_8BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            sint8 value = (*((P2CONST(sint8, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((min <= value) && (value <= max)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_SINT8 == STD_ON) */
#    if (COM_APPLTYPE_UINT16 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint16(AccessAttr))
          {
            uint16 min = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint16 max = Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            uint16 value = (*((P2CONST(uint16, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((min <= value) && (value <= max)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_UINT16 == STD_ON) */
#    if (COM_APPLTYPE_SINT16 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint16(AccessAttr))
          {
            sint16 min = (sint16) Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            sint16 max = (sint16) Com_ConfigValue(Com_16BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            sint16 value = (*((P2CONST(sint16, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((min <= value) && (value <= max)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_SINT16 == STD_ON) */
#    if (COM_APPLTYPE_UINT32 == STD_ON)
          if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint32(AccessAttr))
          {
            uint32 min = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
            uint32 max = Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
            uint32 value = (*((P2CONST(uint32, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
            FilterState = (boolean) (((min <= value) && (value <= max)) ? TRUE : FALSE);
          }
          else
#    endif/* (COM_APPLTYPE_UINT32 == STD_ON) */
          {
            Com_LMgt_CheckFatalErrorRetValue((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint32(AccessAttr)),
                                             Com_Signal_UnsupportedBusSignalType, FALSE);
#    if (COM_APPLTYPE_SINT32 == STD_ON)
            {
              sint32 min = (sint32) Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_MASK];
              sint32 max = (sint32) Com_ConfigValue(Com_32BitValue)[FilterParamRef + COM_SIGNAL_F_PARAM_X];
              sint32 value = (*((P2CONST(sint32, AUTOMATIC, COM_APPL_DATA)) SignalDataPtr));
              FilterState = (boolean) (((min <= value) && (value <= max)) ? TRUE : FALSE);
            }
#    endif/* (COM_APPLTYPE_SINT32 == STD_ON)   */
          }
          break;
        }
#   endif/* (COM_F_NEWISWITHIN == STD_ON) */
      default:
        break;
      }
#  endif
    }
# endif/* (COM_TXMODEHDLR_TMS == STD_ON) */
    break;
  }
  return FilterState;
}                               /* End of Com_Signal_ApplyFilter */
#endif /* ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF) || ((COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))) */

/* KB end Com_Signal_LocalFunctions */
/* KB begin Com_Buffer_LocalFunctions */
#if (COM_BUFFER == STD_ON)
# if (COM_SIGNALGROUPIF == STD_ON)
#  if ((COM_F_MASKEDNEWDIFOLD == STD_ON) || (COM_RXSIGNAL_ACCESS_MACRO_API != STD_ON) || ((COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)) || ((COM_TXMODEHDLR_TMS == STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)))
COM_STATIC FUNC(void, COM_CODE) Com_Buffer_ReadShadowSignal(Com_SignalIdType SignalId,
                                                            P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr,
                                                            P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr)
{
  P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) pSigStartByte;
  Com_SignalGroupIdType sigGrpId = Com_Signal_GetSignalGroupFromSignal(SignalId);

  Com_LMgt_CheckFatalErrorRetVoid((SignalId < Com_Signal_GetSignalCnt()), Com_Buffer_SignalId_Param);
  Com_LMgt_CheckFatalErrorRetVoid((SignalDataPtr != NULL_PTR), Com_Buffer_InvalidPointer_Param);
  pSigStartByte =
    (ShadowBufferPtr + Com_Signal_GetSignalStartByte(SignalId)) - Com_Signal_GetSignalGroupPduOffset(sigGrpId);
  Com_Signal_ReadSignal(SignalId, SignalDataPtr, pSigStartByte,
                        (Com_Signal_AccessAttrType) (Com_Signal_GetSignalAttribute(SignalId, AccessAttributes)));
}                               /* End of Com_Buffer_ReadShadowSignal() */
#  endif

#  if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
COM_STATIC FUNC(void, COM_CODE) Com_Buffer_WriteShadowSignal(Com_SignalIdType SignalId,
                                                             P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
                                                             P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr)
{
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pSigStartByte;
  Com_SignalGroupIdType sigGrpId = Com_Signal_GetSignalGroupFromSignal(SignalId);

  Com_LMgt_CheckFatalErrorRetVoid((SignalId < Com_Signal_GetSignalCnt()), Com_Buffer_SignalId_Param);
  Com_LMgt_CheckFatalErrorRetVoid((SignalDataPtr != NULL_PTR), Com_Buffer_InvalidPointer_Param);
  pSigStartByte =
    (ShadowBufferPtr + Com_Signal_GetSignalStartByte(SignalId)) - Com_Signal_GetSignalGroupPduOffset(sigGrpId);
  Com_Signal_WriteSignal(SignalId, pSigStartByte, SignalDataPtr,
                         (Com_Signal_AccessAttrType) (Com_Signal_GetSignalAttribute(SignalId, AccessAttributes)));
}                               /* End of Com_Buffer_WriteShadowSignal() */
#  endif  /* ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
#endif /* COM_BUFFER == STD_ON */
/* KB end Com_Buffer_LocalFunctions */
/* KB begin Com_RxBuffer_LocalFunctions */
/* KB end Com_RxBuffer_LocalFunctions */
/* KB begin Com_RxDlMon_LocalFunctions */
/* KB end Com_RxDlMon_LocalFunctions */
/* KB begin Com_RxLLIf_LocalFunctions */
/* KB end Com_RxLLIf_LocalFunctions */
/* KB begin Com_RxNHdlr_LocalFunctions */
/* KB end Com_RxNHdlr_LocalFunctions */
/* KB begin Com_RxSigIf_LocalFunctions */
/* KB end Com_RxSigIf_LocalFunctions */
/* KB begin Com_RxUbHdlr_LocalFunctions */
/* KB end Com_RxUbHdlr_LocalFunctions */
/* KB begin Com_RxInv_LocalFunctions */
#if ((COM_RXINV == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF))

COM_STATIC FUNC(boolean, COM_CODE) Com_RxInv_HasInvalidValue(Com_SignalIdType SignalId,
                                                             P2CONST(void, AUTOMATIC, AUTOMATIC) SignalData)
{
  boolean SignalInvalid = FALSE;
# if ((COM_APPLTYPE_BOOLEAN == STD_ON) || (COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
  Com_Signal_AccessAttrType AccessAttr = Com_Signal_GetSignalAttribute(SignalId, AccessAttributes);
# endif
  Com_LMgt_CheckFatalErrorRetValue((COM_SIGNAL_NOINVALIDVALUE !=
                                    Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)), Com_RxInv_NoInvalidValue,
                                   FALSE);

# if (COM_APPLTYPE_BOOLEAN == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsBoolean(AccessAttr))
  {
    SignalInvalid =
      (boolean) ((Com_ConfigValue(Com_8BitValue)[Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)] ==
                  *((P2CONST(uint8, AUTOMATIC, AUTOMATIC)) SignalData)) ? TRUE : FALSE);
  }
  else
# endif /* (COM_APPLTYPE_BOOLEAN == STD_ON) */
# if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON))
  if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint8(AccessAttr))
  {
    SignalInvalid =
      (boolean) ((Com_ConfigValue(Com_8BitValue)[Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)] ==
                  *((P2CONST(uint8, AUTOMATIC, AUTOMATIC)) SignalData)) ? TRUE : FALSE);
  }
  else
# endif /* ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON)) */
# if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
  if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
  {
    SignalInvalid =
      (boolean) ((Com_ConfigValue(Com_16BitValue)[Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)] ==
                  *((P2CONST(uint16, AUTOMATIC, AUTOMATIC)) SignalData)) ? TRUE : FALSE);
  }
  else
# endif /* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
# if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
  if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr))
  {
    SignalInvalid =
      (boolean) ((Com_ConfigValue(Com_32BitValue)[Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)] ==
                  *((P2CONST(uint32, AUTOMATIC, AUTOMATIC)) SignalData)) ? TRUE : FALSE);
  }
  else
# endif /* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
  {
# if (COM_APPLTYPE_UINT8N == STD_ON)
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) InvalidDataPtr =
      &Com_ConfigValue(Com_8BitValue)[Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)];
    SignalInvalid = TRUE;
    {
      sint16_least i;
      for (i = (sint16_least) ((Com_SignalGetLength(SignalId) >> 3) - 1); i >= 0; --i)
      {
        if (((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) InvalidDataPtr)[i] !=
            (((P2CONST(uint8, AUTOMATIC, AUTOMATIC)) SignalData)[i]))
        {
          SignalInvalid = FALSE;
          break;
        }
      }
    }
# endif /* (COM_APPLTYPE_UINT8N == STD_ON) */
  }
  return SignalInvalid;
}

# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
FUNC(void, COM_CODE) Com_RxInv_CheckInvalidation(PduIdType ComRxPduId, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr,
                                                 P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) SduMaskPtr,
                                                 PduLengthType ComPduLength)
# else
FUNC(void, COM_CODE) Com_RxInv_CheckInvalidation(PduIdType ComRxPduId, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr,
                                                 P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) SduMaskPtr)
# endif
{
  uint32 SignalData[(COM_MAXINVVALUELENGTH >> 2)];
  boolean SignalInvalid;
  uint16 InvSigIdx;
  uint16 InvSigStopIdx;
  Com_RxNHdlr_NotiFuncPtrType InvalidFuncPtr;
  Com_SignalIdType SignalId;
  Com_Signal_AccessAttrType AccessAttr;
# if (COM_SIGNALIF == STD_ON)
  uint32 SignalDataZero[(COM_MAXINVVALUELENGTH >> 2)];
#  if (COM_VSTDLIB_MEM_API == STD_ON)
  Com_LMgt_MemSet(SignalDataZero, 0, COM_MAXINVVALUELENGTH);
#  else
  Com_LMgt_MemSet(SignalDataZero, 0, (COM_MAXINVVALUELENGTH >> 2));
#  endif
# endif

# if (COM_SIGNALIF == STD_ON)
  InvSigIdx = Com_ConfigValue(Com_RxInv_IPdu2InvalidSignals)[ComRxPduId];
  InvSigStopIdx = Com_ConfigValue(Com_RxInv_IPdu2InvalidSignals)[ComRxPduId + 1];

#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
  for (;
       ((InvSigIdx < InvSigStopIdx)
        && (Com_ConfigValue(Com_RxInv_InvalidObjectIndirection)[InvSigIdx].validDlc <= ComPduLength)); InvSigIdx++)
#  else
  for (; InvSigIdx < InvSigStopIdx; InvSigIdx++)
#  endif
  {
    Com_SignalIdType InvSigId;

    InvSigId = (Com_SignalIdType) Com_ConfigValue(Com_RxInv_InvalidObjectIndirection)[InvSigIdx].invObjIdx;
    SignalId = Com_ConfigValue(Com_RxInv_InvalidSignalHandles)[InvSigId];
    AccessAttr = Com_Signal_GetSignalAttribute(SignalId, AccessAttributes);
#  if (COM_RXNHDLR == STD_ON)
    InvalidFuncPtr = Com_RxInv_InvalidNotiFuncPtr[InvSigId + 1];
#  endif
    Com_Signal_ReadSignal(SignalId, SignalData, &SduPtr[Com_Signal_GetSignalStartByte(SignalId)], AccessAttr);
    SignalInvalid = Com_RxInv_HasInvalidValue(SignalId, SignalData);

    if (TRUE == SignalInvalid)
    {
      if (NULL_PTR != InvalidFuncPtr)
      {
        Com_Signal_WriteSignal(SignalId, &SduMaskPtr[Com_Signal_GetSignalStartByte(SignalId)], SignalDataZero,
                               AccessAttr);
      }
      else
      {
        uint16 InitValueIdx = Com_ConfigValue(Com_RxInv_InitValueIdx)[InvSigId];
        P2CONST(void, AUTOMATIC, COM_PBCFG) InitValuePtr;
#  if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
        if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr))
        {
          InitValuePtr = &Com_ConfigValue(Com_32BitValue)[InitValueIdx];
        }
        else
#  endif /* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
#  if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
        if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
        {
          InitValuePtr = &Com_ConfigValue(Com_16BitValue)[InitValueIdx];
        }
        else
#  endif /* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
        {
#  if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_BOOLEAN == STD_ON) || (COM_APPLTYPE_UINT8N == STD_ON))
          InitValuePtr = &Com_ConfigValue(Com_8BitValue)[InitValueIdx];
#  endif /* ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_BOOLEAN == STD_ON) || (COM_APPLTYPE_UINT8N == STD_ON)) */
        }
        Com_Signal_WriteSignal(SignalId, &SduPtr[Com_Signal_GetSignalStartByte(SignalId)], InitValuePtr, AccessAttr);
      }
    }

#  if (COM_RXNHDLR == STD_ON)
    if (NULL_PTR != InvalidFuncPtr)
    {
#   if (COM_RXINV_INHIBITNOTIFUNC == STD_ON)
      Com_RxNHdlr_NotificationIdxType NotificationIdx = Com_RxInv_SignalNotificationId[InvSigId];
#   endif
#   if (COM_RXINV_INHIBITINDFLAG == STD_ON)
      Com_RxNHdlr_NotiFlagIdType NotificationFlagIdx = Com_RxInv_SigNotificationFlagId[InvSigId];
#   endif

      if (TRUE == SignalInvalid)
      {
#   if (COM_RXINV_INHIBITNOTIFUNC == STD_ON)
        Com_RxInv_SetInhibitNotification(NotificationIdx);
#   endif
#   if (COM_RXINV_INHIBITINDFLAG == STD_ON)
        if (COM_RX_NHDLR_NONOTIFLAG != NotificationFlagIdx)
        {
          Com_RxInv_SetInhibitNotificationFlag(NotificationFlagIdx);
        }
#   endif
        InvalidFuncPtr();
      }
#   if ((COM_RXINV_INHIBITNOTIFUNC == STD_ON) || (COM_RXINV_INHIBITINDFLAG == STD_ON))
      else
      {
#    if (COM_RXINV_INHIBITNOTIFUNC == STD_ON)
        Com_RxInv_ClrInhibitNotification(NotificationIdx);
#    endif
#    if (COM_RXINV_INHIBITINDFLAG == STD_ON)
        if (COM_RX_NHDLR_NONOTIFLAG != NotificationFlagIdx)
        {
          Com_RxInv_ClrInhibitNotificationFlag(NotificationFlagIdx);
        }
#    endif
      }
#   endif
    }
#  endif /* (COM_RXNHDLR == STD_ON) */
  }
# endif /* (COM_SIGNALIF == STD_ON) */
# if (COM_SIGNALGROUPIF == STD_ON)
  {
    uint16 InvSigGrpIdx;
    uint16 InvSigGrpStopIdx;
    Com_SignalGroupIdType InvSigGrpId;
    P2CONST(uint8, AUTOMATIC, COM_PBCFG) InitValPtr = Com_RxBuffer_GetIpduInitValPtr(ComRxPduId);

    InvSigGrpIdx = Com_ConfigValue(Com_RxInv_IPdu2InvalidSignalGroups)[ComRxPduId];
    InvSigGrpStopIdx = Com_ConfigValue(Com_RxInv_IPdu2InvalidSignalGroups)[ComRxPduId + 1];

#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
    for (;
         ((InvSigGrpIdx < InvSigGrpStopIdx)
          && (Com_ConfigValue(Com_RxInv_InvalidObjectIndirection)[InvSigGrpIdx].validDlc <= ComPduLength));
         InvSigGrpIdx++)
#  else
    for (; InvSigGrpIdx < InvSigGrpStopIdx; InvSigGrpIdx++)
#  endif
    {
      InvSigGrpId = (Com_SignalGroupIdType) Com_ConfigValue(Com_RxInv_InvalidObjectIndirection)[InvSigGrpIdx].invObjIdx;
#  if (COM_RXNHDLR == STD_ON)
      InvalidFuncPtr = Com_RxInv_InvalidNotiFuncPtr[InvSigGrpId + COM_RXINVSIGNALCNT + 1];
#  endif /* (COM_RXNHDLR == STD_ON) */
      InvSigIdx = Com_RxInv_InvalidSignalGroup2GroupSignals[InvSigGrpId];
      InvSigStopIdx = Com_RxInv_InvalidSignalGroup2GroupSignals[InvSigGrpId + 1];
      SignalInvalid = FALSE;

      if (InvSigIdx < InvSigStopIdx)
      {
        SignalId = Com_ConfigValue(Com_RxInv_InvalidGroupSignalHandles)[InvSigIdx];
        AccessAttr = Com_Signal_GetSignalAttribute(SignalId, AccessAttributes);
        Com_Signal_ReadSignal(SignalId, SignalData, &SduPtr[Com_Signal_GetSignalStartByte(SignalId)], AccessAttr);
        SignalInvalid = Com_RxInv_HasInvalidValue(SignalId, SignalData);
      }

      if (TRUE == SignalInvalid)
      {
        Com_SignalGroupIdType SignalGroupId = Com_Signal_GetSignalGroupFromSignal(SignalId);
        PduLengthType PduOffset = Com_Signal_GetSignalGroupPduOffset(SignalGroupId);
        P2CONST(uint8, AUTOMATIC, COM_PBCFG) MaskPtr = Com_Signal_GetSignalGroupMaskPtr(SignalGroupId);
        sint16_least i;

        if (NULL_PTR != InvalidFuncPtr)
        {
          for (i = (sint16_least) Com_Signal_GetSignalGroupBufferLength(SignalGroupId) - 1; i >= 0; i--)
          {
            SduMaskPtr[PduOffset + i] = (SduMaskPtr[PduOffset + i] & COM_CAST2UINT8(~MaskPtr[i]));
          }
        }
        else
        {
          for (i = (sint16_least) Com_Signal_GetSignalGroupBufferLength(SignalGroupId) - 1; i >= 0; i--)
          {
            SduPtr[PduOffset + i] =
              (SduPtr[PduOffset + i] & COM_CAST2UINT8(~MaskPtr[i])) | (InitValPtr[PduOffset + i] & MaskPtr[i]);
          }
        }
      }

#  if (COM_RXNHDLR == STD_ON)
      if (NULL_PTR != InvalidFuncPtr)
      {
#   if (COM_RXINV_INHIBITNOTIFUNC == STD_ON)
        Com_RxNHdlr_NotificationIdxType NotificationIdx = Com_RxInv_SignalGroupNotificationId[InvSigGrpId];
#   endif
#   if (COM_RXINV_INHIBITINDFLAG == STD_ON)
        Com_RxNHdlr_NotiFlagIdType NotificationFlagIdx = Com_RxInv_SigGrpNotificationFlagId[InvSigGrpId];
#   endif
        if (TRUE == SignalInvalid)
        {
#   if (COM_RXINV_INHIBITNOTIFUNC == STD_ON)
          Com_RxInv_SetInhibitNotification(NotificationIdx);
#   endif
#   if (COM_RXINV_INHIBITINDFLAG == STD_ON)
          if (COM_RX_NHDLR_NONOTIFLAG != NotificationFlagIdx)
          {
            Com_RxInv_SetInhibitNotificationFlag(NotificationFlagIdx);
          }
#   endif
          InvalidFuncPtr();
        }
#   if ((COM_RXINV_INHIBITNOTIFUNC == STD_ON) || (COM_RXINV_INHIBITINDFLAG == STD_ON))
        else
        {
#    if (COM_RXINV_INHIBITNOTIFUNC == STD_ON)
          Com_RxInv_ClrInhibitNotification(NotificationIdx);
#    endif
#    if (COM_RXINV_INHIBITINDFLAG == STD_ON)
          if (COM_RX_NHDLR_NONOTIFLAG != NotificationFlagIdx)
          {
            Com_RxInv_ClrInhibitNotificationFlag(NotificationFlagIdx);
          }
#    endif
        }
#   endif
      }
#  endif /* (COM_RXNHDLR == STD_ON) */
    }
  }
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
}
#endif /* ((COM_RXINV == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF)) */
/* KB end Com_RxInv_LocalFunctions */
/* KB begin Com_TxInv_LocalFunctions */
/* KB end Com_TxInv_LocalFunctions */
/* KB begin Com_TxBuffer_LocalFunctions */
/* KB end Com_TxBuffer_LocalFunctions */
/* KB begin Com_TxDlMon_LocalFunctions */
/* KB end Com_TxDlMon_LocalFunctions */
/* KB begin Com_TxLLIf_LocalFunctions */
/* KB end Com_TxLLIf_LocalFunctions */
/* KB begin Com_TxModeHdlr_LocalFunctions */
/* KB end Com_TxModeHdlr_LocalFunctions */
/* KB begin Com_TxNHdlr_LocalFunctions */
/* KB end Com_TxNHdlr_LocalFunctions */
/* KB begin Com_TxSigIf_LocalFunctions */
/* KB end Com_TxSigIf_LocalFunctions */
/* KB begin Com_SignalGw_LocalFunctions */
/* KB end Com_SignalGw_LocalFunctions */

/**********************************************************************************************************************
  GLOBAL COM FUNCTIONS
**********************************************************************************************************************/
/* KB begin Com_LMgt_GlobalIl_AsrComFunctions */
/* KB end Com_LMgt_GlobalIl_AsrComFunctions */
/* KB begin Com_Signal_GlobalIl_AsrComFunctions */

/* Consistency Check */
#if ((CPU_BYTE_ORDER != LOW_BYTE_FIRST) && (CPU_BYTE_ORDER != HIGH_BYTE_FIRST))
# error "The hardware byte order is either not defined or has a not supported value"
#endif

#if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
COM_STATIC FUNC(void, COM_CODE) Com_Signal_WriteSignal(Com_SignalIdType SignalId,
                                                       P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SignalBusDestPtr,
                                                       P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalApplSourcePtr,
                                                       Com_Signal_AccessAttrType AccessAttr)
{
# if ((COM_BUSACC_NBIT == STD_ON) || (COM_BUSACC_NBYTE == STD_ON) || (COM_BUSACC_NBYTE_SW == STD_ON) || (COM_BUSACC_NBITNBYTE == STD_ON) || (COM_BUSACC_NBITNBYTE_SW == STD_ON))
  Com_Signal_SignalBitLengthType signalBitCount = Com_SignalGetLength(SignalId);
# endif
# if ((COM_BUSACC_NBIT == STD_ON) || (COM_BUSACC_NBITNBYTE == STD_ON) || (COM_BUSACC_NBITNBYTE_SW == STD_ON))
  uint8 signalStartBit = Com_Signal_BitOffsetFromBitPos(Com_SignalGetBitPosition(SignalId));
# endif

# if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#  if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
  if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
  {
    SignalApplSourcePtr = (P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + 1;
  }
  else
#  endif/* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
#  if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
  if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr))
  {
    SignalApplSourcePtr = (P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + 3;
  }
  else
#  endif/* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
  {
  }
# endif/* (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) */

# if (COM_BUSACC_NBIT == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBit(AccessAttr))
  {
    uint8 mask = COM_CAST2UINT8((COM_CAST2UINT8(~(COM_CAST2UINT8(0xFFu << signalBitCount)))) << signalStartBit);
    *SignalBusDestPtr &= COM_CAST2UINT8(~mask);
    *SignalBusDestPtr |=
      COM_CAST2UINT8((*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr)) << signalStartBit) & mask;
  }
  else
# endif/* (COM_BUSACC_NBIT == STD_ON) */
# if (COM_BUSACC_BYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsByte(AccessAttr))
  {
    *SignalBusDestPtr = *(P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr;
  }
  else
# endif/* (COM_BUSACC_BYTE == STD_ON) */
# if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#  if (COM_BUSACC_NBYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNByte(AccessAttr))
  {
    sint16_least i;

    for (i = (sint16_least) ((signalBitCount >> 3) - 1); i >= 0; i--)
    {
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
      {
        if (i & (sint16_least) 1)
        {
          /*ODD*/
            *(SignalBusDestPtr + i) =
            COM_HIBYTE(*(((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) + (i >> 1)));
        }
        else
        {
          /*EVEN*/
            *(SignalBusDestPtr + i) =
            COM_LOBYTE(*(((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) + (i >> 1)));
        }
      }
      else
      {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        *(SignalBusDestPtr + i) = *(((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) + i);
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
    }
  }
  else
#  endif/* (COM_BUSACC_NBYTE == STD_ON) */
#  if (COM_BUSACC_NBYTE_SW == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNByte_Sw(AccessAttr))
  {
    sint16_least i;

    for (i = (sint16_least) ((signalBitCount >> 3) - 1); i >= 0; i--)
    {
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
      {
        if (i & (sint16_least) 1)
        {
          /*ODD*/
            *(SignalBusDestPtr - i) =
            COM_HIBYTE(*(((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) + (i >> 1)));
        }
        else
        {
          /*EVEN*/
            *(SignalBusDestPtr - i) =
            COM_LOBYTE(*(((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) + (i >> 1)));
        }
      }
      else
      {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        *(SignalBusDestPtr - i) = *(((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) + i);
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
    }
  }
  else
#  endif/* (COM_BUSACC_NBYTE_SW == STD_ON) */
#  if (COM_BUSACC_NBITNBYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBitNByte(AccessAttr))
  {
    uint8 mask, tmpByte;
    uint16_least nFullBytes;
    Com_Signal_SignalBitLengthType nBitsToWrite;
    *SignalBusDestPtr &= COM_CAST2UINT8(~COM_CAST2UINT8((0xFFu << signalStartBit)));
    *SignalBusDestPtr |=
      COM_CAST2UINT8((*(P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) << signalStartBit);
    nBitsToWrite = signalBitCount - (8 - signalStartBit);

    if (nBitsToWrite > 8)
    {
      sint16_least i;
      nFullBytes = nBitsToWrite >> 3;

      for (i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
      {
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
        if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
            || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
        {
          if (i & (sint16_least) 1)
          {
            /*ODD*/
              tmpByte =
              COM_CAST2UINT8(COM_HIBYTE(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + (i >> 1))) >>
                             (8 - signalStartBit));
            tmpByte |=
              COM_CAST2UINT8(COM_LOBYTE
                             (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + ((i + 1) >> 1))) <<
                             signalStartBit);
          }
          else
          {
            /*EVEN*/
              tmpByte =
              COM_CAST2UINT8(COM_LOBYTE(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + (i >> 1))) >>
                             (8 - signalStartBit));
            tmpByte |=
              COM_CAST2UINT8(COM_HIBYTE
                             (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + ((i + 1) >> 1))) <<
                             signalStartBit);
          }
        }
        else
        {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
          tmpByte =
            COM_CAST2UINT8(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + i) >>
                           (8 - signalStartBit));
          tmpByte |=
            COM_CAST2UINT8(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + i + 1) << signalStartBit);
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
        }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        *(SignalBusDestPtr + 1 + i) = tmpByte;
        nBitsToWrite -= 8;
      }
    }
    else
    {
      nFullBytes = 0;
    }

#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
    if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
        || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
    {
      if (nFullBytes & (sint16_least) 1)
      {
        /*ODD*/
          tmpByte =
          COM_CAST2UINT8(COM_HIBYTE
                         (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + (nFullBytes >> 1))) >> (8 -
                                                                                                                     signalStartBit));
        tmpByte |=
          COM_CAST2UINT8(COM_LOBYTE
                         (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + ((nFullBytes + 1) >> 1)))
                         << signalStartBit);
      }
      else
      {
        /*EVEN*/
          tmpByte =
          COM_CAST2UINT8(COM_LOBYTE
                         (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + (nFullBytes >> 1))) >> (8 -
                                                                                                                     signalStartBit));
        tmpByte |=
          COM_CAST2UINT8(COM_HIBYTE
                         (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + ((nFullBytes + 1) >> 1)))
                         << signalStartBit);
      }
    }
    else
    {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
      tmpByte =
        COM_CAST2UINT8(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + nFullBytes) >>
                       (8 - signalStartBit));
      tmpByte |=
        COM_CAST2UINT8(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + nFullBytes + 1) <<
                       signalStartBit);
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
    }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
    mask = COM_CAST2UINT8(0xFFu << nBitsToWrite);
    tmpByte &= COM_CAST2UINT8(~(mask & 0xFFu));
    *(SignalBusDestPtr + nFullBytes + 1) &= mask;
    *(SignalBusDestPtr + nFullBytes + 1) |= tmpByte;
  }
  else
#  endif/* (COM_BUSACC_NBITNBYTE == STD_ON) */
  {
    Com_LMgt_CheckFatalErrorRetVoid((COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBitNByte_Sw(AccessAttr)),
                                    Com_Signal_UnsupportedBusSignalType);
#  if (COM_BUSACC_NBITNBYTE_SW == STD_ON)
    {
      uint8 mask, tmpByte;
      uint16_least nFullBytes;
      Com_Signal_SignalBitLengthType nBitsToWrite;
      *SignalBusDestPtr &= COM_CAST2UINT8(~COM_CAST2UINT8((0xFFu << signalStartBit)));
      *SignalBusDestPtr |=
        COM_CAST2UINT8((*(P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) << signalStartBit);
      nBitsToWrite = signalBitCount - (8 - signalStartBit);

      if (nBitsToWrite > 8)
      {
        sint16_least i;
        nFullBytes = nBitsToWrite >> 3;
        for (i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
        {
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
          if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
              || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
          {
            if (i & (sint16_least) 1)
            {
              /*ODD*/
                tmpByte =
                COM_CAST2UINT8(COM_HIBYTE(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + (i >> 1)))
                               >> (8 - signalStartBit));
              tmpByte |=
                COM_CAST2UINT8(COM_LOBYTE
                               (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + ((i + 1) >> 1))) <<
                               signalStartBit);
            }
            else
            {
              /*EVEN*/
                tmpByte =
                COM_CAST2UINT8(COM_LOBYTE(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + (i >> 1)))
                               >> (8 - signalStartBit));
              tmpByte |=
                COM_CAST2UINT8(COM_HIBYTE
                               (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + ((i + 1) >> 1))) <<
                               signalStartBit);
            }
          }
          else
          {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
            tmpByte =
              COM_CAST2UINT8(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + i) >>
                             (8 - signalStartBit));
            tmpByte |=
              COM_CAST2UINT8(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + i + 1) <<
                             signalStartBit);
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
          }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
          *((SignalBusDestPtr - 1) - i) = tmpByte;
          nBitsToWrite -= 8;
        }
      }
      else
      {
        nFullBytes = 0;
      }

#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
      {
        if (nFullBytes & (sint16_least) 1)
        {
          /*ODD*/
            tmpByte =
            COM_CAST2UINT8(COM_HIBYTE
                           (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + (nFullBytes >> 1))) >> (8
                                                                                                                       -
                                                                                                                       signalStartBit));
          tmpByte |=
            COM_CAST2UINT8(COM_LOBYTE
                           (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + ((nFullBytes + 1) >> 1)))
                           << signalStartBit);
        }
        else
        {
          /*EVEN*/
            tmpByte =
            COM_CAST2UINT8(COM_LOBYTE
                           (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + (nFullBytes >> 1))) >> (8
                                                                                                                       -
                                                                                                                       signalStartBit));
          tmpByte |=
            COM_CAST2UINT8(COM_HIBYTE
                           (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + ((nFullBytes + 1) >> 1)))
                           << signalStartBit);
        }
      }
      else
      {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        tmpByte =
          COM_CAST2UINT8(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + nFullBytes) >>
                         (8 - signalStartBit));
        tmpByte |=
          COM_CAST2UINT8(*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr + nFullBytes + 1) <<
                         signalStartBit);
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
      mask = COM_CAST2UINT8(0xFFu << nBitsToWrite);
      tmpByte &= COM_CAST2UINT8(~(mask & 0xFFu));
      *((SignalBusDestPtr - nFullBytes) - 1) &= mask;
      *((SignalBusDestPtr - nFullBytes) - 1) |= tmpByte;
    }
#  endif/* (COM_BUSACC_NBITNBYTE_SW == STD_ON) */
  }
# elif (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#  if (COM_BUSACC_NBYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNByte(AccessAttr))
  {
    sint16_least i = (sint16_least) ((signalBitCount >> 3) - 1);
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint8_N(AccessAttr))
    {
      SignalApplSourcePtr = ((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) + i;
    }

    for (; i >= 0; i--)
    {
      *(SignalBusDestPtr - i) = (uint8) * ((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - i);
    }
  }
  else
#  endif/* (COM_BUSACC_NBYTE == STD_ON) */
#  if (COM_BUSACC_NBYTE_SW == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNByte_Sw(AccessAttr))
  {
    sint16_least i;
    for (i = (sint16_least) ((signalBitCount >> 3) - 1); i >= 0; i--)
    {
      *(SignalBusDestPtr + i) = (uint8) * ((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - i);
    }
  }
  else
#  endif/* (COM_BUSACC_NBYTE_SW == STD_ON) */
#  if (COM_BUSACC_NBITNBYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBitNByte(AccessAttr))
  {
    uint8 mask, tmpByte;
    uint16_least nFullBytes;
    Com_Signal_SignalBitLengthType nBitsToWrite;
    *SignalBusDestPtr &= (uint8) (~(uint8) ((0xFFu << signalStartBit)));
    *SignalBusDestPtr |= (uint8) ((*(P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) << signalStartBit);
    nBitsToWrite = signalBitCount - (8 - signalStartBit);

    if (nBitsToWrite > 8)
    {
      sint16_least i;
      nFullBytes = nBitsToWrite >> 3;
      for (i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
      {
        tmpByte =
          (uint8) (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - i) >> (8 - signalStartBit));
        tmpByte |=
          (uint8) (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - i - 1) << signalStartBit);
        *((SignalBusDestPtr - 1) - i) = tmpByte;
        nBitsToWrite -= 8;
      }
    }
    else
    {
      nFullBytes = 0;
    }

    tmpByte =
      (uint8) (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - nFullBytes) >> (8 - signalStartBit));
    tmpByte |=
      (uint8) (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - nFullBytes - 1) << signalStartBit);
    mask = (uint8) (0xFFu << nBitsToWrite);
    tmpByte &= (uint8) (~(mask & 0xFFu));
    *((SignalBusDestPtr - nFullBytes) - 1) &= mask;
    *((SignalBusDestPtr - nFullBytes) - 1) |= tmpByte;
  }
  else
#  endif/* (COM_BUSACC_NBITNBYTE == STD_ON) */
  {
    Com_LMgt_CheckFatalErrorRetVoid((COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBitNByte_Sw(AccessAttr)),
                                    Com_Signal_UnsupportedBusSignalType);
#  if (COM_BUSACC_NBITNBYTE_SW == STD_ON)
    {
      uint8 mask, tmpByte;
      uint16_least nFullBytes;
      Com_Signal_SignalBitLengthType nBitsToWrite;
      tmpByte = (uint8) ((*(P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr) << signalStartBit);
      *SignalBusDestPtr &= (uint8) (~((uint8) (0xFFu << signalStartBit)));
      *SignalBusDestPtr |= tmpByte;
      nBitsToWrite = signalBitCount - (8 - signalStartBit);

      if (nBitsToWrite > 8)
      {
        sint16_least i;
        nFullBytes = nBitsToWrite >> 3;
        for (i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
        {
          tmpByte =
            (uint8) (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - i) >> (8 - signalStartBit));
          tmpByte |=
            (uint8) (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - i - 1) << signalStartBit);
          *(SignalBusDestPtr + 1 + i) = tmpByte;
          nBitsToWrite -= 8;
        }
      }
      else
      {
        nFullBytes = 0;
      }

      tmpByte =
        (uint8) (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - nFullBytes) >>
                 (8 - signalStartBit));
      tmpByte |=
        (uint8) (*((P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) SignalApplSourcePtr - nFullBytes - 1) << signalStartBit);
      mask = (uint8) (0xFFu << nBitsToWrite);
      tmpByte &= (uint8) (~(mask & 0xFFu));
      *(SignalBusDestPtr + nFullBytes + 1) &= mask;
      *(SignalBusDestPtr + nFullBytes + 1) |= tmpByte;
    }
#  endif/* (COM_BUSACC_NBITNBYTE_SW == STD_ON) */
  }
# endif/* (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) */
}                               /* End of Com_Signal_WriteSignal */
#endif /* ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */

#if ((COM_RXSIGNAL_ACCESS_MACRO_API != STD_ON) || (COM_F_MASKEDNEWDIFOLD == STD_ON) || ((COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)) || ((COM_TXMODEHDLR_TMS == STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)))
COM_STATIC FUNC(void, COM_CODE) Com_Signal_ReadSignal(Com_SignalIdType SignalId,
                                                      P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalApplDestPtr,
                                                      P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) SignalBusSourcePtr,
                                                      Com_Signal_AccessAttrType AccessAttr)
{
# if ((COM_BUSACC_NBIT == STD_ON) || (COM_BUSACC_NBYTE == STD_ON) || (COM_BUSACC_NBYTE_SW == STD_ON) || (COM_BUSACC_NBITNBYTE == STD_ON) || (COM_BUSACC_NBITNBYTE_SW == STD_ON))
  Com_Signal_SignalBitLengthType signalBitCount = Com_SignalGetLength(SignalId);
# endif
# if ((COM_BUSACC_NBIT == STD_ON) || (COM_BUSACC_NBITNBYTE == STD_ON) || (COM_BUSACC_NBITNBYTE_SW == STD_ON))
  uint8 signalStartBit = Com_Signal_BitOffsetFromBitPos(Com_SignalGetBitPosition(SignalId));
# endif

  if (COM_SIGNAL_FALSE == Com_Signal_BusApplHaveSameSize(AccessAttr))
  {
# if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
    {
#  if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)) = (uint8) 0x00;
      COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)) = (uint8) 0x00;
#  else
      ((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)[0] = (uint8) 0x00;
      ((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)[1] = (uint8) 0x00;
#  endif
#  if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
      SignalApplDestPtr = (P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + 1;
#  endif
    }
    else
# endif/* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
# if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr))
    {
#  if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)) = (uint8) 0x00;
      COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)) = (uint8) 0x00;
      COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + 1)) = (uint8) 0x00;
      COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + 1)) = (uint8) 0x00;
#  else
      ((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)[0] = (uint8) 0x00;
      ((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)[1] = (uint8) 0x00;
      ((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)[2] = (uint8) 0x00;
      ((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)[3] = (uint8) 0x00;
#  endif
#  if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
      SignalApplDestPtr = (P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + 3;
#  endif
    }
    else
# endif/* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))   */
    {
    }
  }
  else
  {
# if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#  if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
    {
      SignalApplDestPtr = (P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + 1;
    }
    else
#  endif/* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
#  if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr))
    {
      SignalApplDestPtr = (P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + 3;
    }
    else
#  endif/* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
    {
    }
# endif
  }
# if (COM_BUSACC_NBIT == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBit(AccessAttr))
  {
    *(P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr =
      COM_CAST2UINT8((*SignalBusSourcePtr) >> signalStartBit) & COM_CAST2UINT8(0xFFu >> (8 - signalBitCount));
  }
  else
# endif/* (COM_BUSACC_NBIT == STD_ON) */
# if (COM_BUSACC_BYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsByte(AccessAttr))
  {
    *(P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr = COM_CAST2UINT8(*SignalBusSourcePtr);
  }
  else
# endif/* (COM_BUSACC_BYTE == STD_ON) */
# if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#  if (COM_BUSACC_NBYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNByte(AccessAttr))
  {
    sint16_least i;
    for (i = (sint16_least) ((signalBitCount >> 3) - 1); i >= 0; i--)
    {
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
      {
        if (i & (sint16_least) 1)
        {
          /*ODD*/
            COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
            COM_CAST2UINT8(*(SignalBusSourcePtr + i));
        }
        else
        {
          /*EVEN*/
            COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
            COM_CAST2UINT8(*(SignalBusSourcePtr + i));
        }
      }
      else
      {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + i) = COM_CAST2UINT8(*(SignalBusSourcePtr + i));
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
    }
  }
  else
#  endif/* (COM_BUSACC_NBYTE == STD_ON) */
#  if (COM_BUSACC_NBYTE_SW == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNByte_Sw(AccessAttr))
  {
    sint16_least i;
    for (i = (sint16_least) ((signalBitCount >> 3) - 1); i >= 0; i--)
    {
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
      {
        if (i & (sint16_least) 1)
        {
          /*ODD*/
            COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
            COM_CAST2UINT8(*(SignalBusSourcePtr - i));
        }
        else
        {
          /*EVEN*/
            COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
            COM_CAST2UINT8(*(SignalBusSourcePtr - i));
        }
      }
      else
      {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + i) = COM_CAST2UINT8(*(SignalBusSourcePtr - i));
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
    }
  }
  else
#  endif/* (COM_BUSACC_NBYTE_SW == STD_ON) */
#  if (COM_BUSACC_NBITNBYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBitNByte(AccessAttr))
  {
    uint16_least nFullBytes;
    Com_Signal_SignalBitLengthType nBitsToWrite;
    nBitsToWrite = signalBitCount;
    if (signalBitCount > 8)
    {
      sint16_least i;
      nFullBytes = nBitsToWrite >> 3;
      for (i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
      {
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
        if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
            || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
        {
          if (i & (sint16_least) 1)
          {
            /*ODD*/
              COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
              COM_CAST2UINT8(*(SignalBusSourcePtr + i) >> signalStartBit);
            COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) |=
              COM_CAST2UINT8(*(SignalBusSourcePtr + i + 1) << (8 - signalStartBit));
          }
          else
          {
            /*EVEN*/
              COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
              COM_CAST2UINT8(*(SignalBusSourcePtr + i) >> signalStartBit);
            COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) |=
              COM_CAST2UINT8(*(SignalBusSourcePtr + i + 1) << (8 - signalStartBit));
          }
        }
        else
        {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + i) =
            COM_CAST2UINT8(*(SignalBusSourcePtr + i) >> signalStartBit);
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + i) |=
            COM_CAST2UINT8(*(SignalBusSourcePtr + i + 1) << (8 - signalStartBit));
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
        }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        nBitsToWrite -= 8;
      }
    }
    else
    {
      nFullBytes = 0;
    }

    if (0 != nBitsToWrite)
    {
      uint8 tmpByte;
      tmpByte = COM_CAST2UINT8((*(SignalBusSourcePtr + nFullBytes)) >> signalStartBit);
      tmpByte |= COM_CAST2UINT8((*(SignalBusSourcePtr + nFullBytes + 1)) << (8 - signalStartBit));
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
          || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
      {
        if (nFullBytes & (sint16_least) 1)
        {
          /*ODD*/
            COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (nFullBytes >> 1))) =
            tmpByte & COM_CAST2UINT8(~(COM_CAST2UINT8(0xFFu << nBitsToWrite)));
        }
        else
        {
          /*EVEN*/
            COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (nFullBytes >> 1))) =
            tmpByte & COM_CAST2UINT8(~(COM_CAST2UINT8(0xFFu << nBitsToWrite)));
        }
      }
      else
      {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + nFullBytes) =
          tmpByte & COM_CAST2UINT8(~(COM_CAST2UINT8(0xFFu << nBitsToWrite)));
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
    }
  }
  else
#  endif/* (COM_BUSACC_NBITNBYTE == STD_ON) */
  {
    Com_LMgt_CheckFatalErrorRetVoid((COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBitNByte_Sw(AccessAttr)),
                                    Com_Signal_UnsupportedBusSignalType);
#  if (COM_BUSACC_NBITNBYTE_SW == STD_ON)
    {
      uint16_least nFullBytes;
      Com_Signal_SignalBitLengthType nBitsToWrite;
      nBitsToWrite = signalBitCount;
      if (signalBitCount > 8)
      {
        sint16_least i;
        nFullBytes = nBitsToWrite >> 3;
        for (i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
        {
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
          if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
              || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
          {
            if (i & (sint16_least) 1)
            {
              /*ODD*/
                COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
                COM_CAST2UINT8(*(SignalBusSourcePtr - i) >> signalStartBit);
              COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) |=
                COM_CAST2UINT8(*((SignalBusSourcePtr - i) - 1) << (8 - signalStartBit));
            }
            else
            {
              /*EVEN*/
                COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
                COM_CAST2UINT8(*(SignalBusSourcePtr - i) >> signalStartBit);
              COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) |=
                COM_CAST2UINT8(*((SignalBusSourcePtr - i) - 1) << (8 - signalStartBit));
            }
          }
          else
          {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
            *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + i) =
              COM_CAST2UINT8(*(SignalBusSourcePtr - i) >> signalStartBit);
            *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + i) |=
              COM_CAST2UINT8(*((SignalBusSourcePtr - i) - 1) << (8 - signalStartBit));
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
          }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
          nBitsToWrite -= 8;
        }
      }
      else
      {
        nFullBytes = 0;
      }

      if (0 != nBitsToWrite)
      {
        uint8 tmpByte;
        tmpByte = (*(SignalBusSourcePtr - nFullBytes)) >> signalStartBit;
        tmpByte |= (uint8) ((*((SignalBusSourcePtr - nFullBytes) - 1)) << (8 - signalStartBit));
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
        if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
            || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr)))
        {
          if (nFullBytes & (sint16_least) 1)
          {
            /*ODD*/
              COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (nFullBytes >> 1))) =
              tmpByte & COM_CAST2UINT8(~(COM_CAST2UINT8(0xFFu << nBitsToWrite)));
          }
          else
          {
            /*EVEN*/
              COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (nFullBytes >> 1))) =
              tmpByte & COM_CAST2UINT8(~(COM_CAST2UINT8(0xFFu << nBitsToWrite)));
          }
        }
        else
        {
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + nFullBytes) =
            tmpByte & COM_CAST2UINT8(~(COM_CAST2UINT8(0xFFu << nBitsToWrite)));
#   if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
        }
#   endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
      }
    }
#  endif/* (COM_BUSACC_NBITNBYTE_SW == STD_ON) */
  }
# elif (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#  if (COM_BUSACC_NBYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNByte(AccessAttr))
  {
    sint16_least i;
    i = (sint16_least) ((signalBitCount >> 3) - 1);

    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint8_N(AccessAttr))
    {
      SignalApplDestPtr = ((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr) + i;
    }

    for (; i >= 0; i--)
    {
      *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - i) = *(SignalBusSourcePtr - i);
    }
  }
  else
#  endif/* (COM_BUSACC_NBYTE == STD_ON) */
#  if (COM_BUSACC_NBYTE_SW == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNByte_Sw(AccessAttr))
  {
    sint16_least i;
    for (i = (sint16_least) ((signalBitCount >> 3) - 1); i >= 0; i--)
    {
      *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - i) = *(SignalBusSourcePtr + i);
    }
  }
  else
#  endif/* (COM_BUSACC_NBYTE_SW == STD_ON) */
#  if (COM_BUSACC_NBITNBYTE == STD_ON)
  if (COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBitNByte(AccessAttr))
  {
    uint16_least nFullBytes;
    Com_Signal_SignalBitLengthType nBitsToWrite;
    nBitsToWrite = signalBitCount;
    if (signalBitCount > 8)
    {
      sint16_least i;
      nFullBytes = nBitsToWrite >> 3;
      for (i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
      {
        *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - i) =
          (uint8) (*(SignalBusSourcePtr - i) >> signalStartBit);
        *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - i) |=
          (uint8) (*(SignalBusSourcePtr - i - 1) << (8 - signalStartBit));
        nBitsToWrite -= 8;
      }
    }
    else
    {
      nFullBytes = 0;
    }

    if (0 != nBitsToWrite)
    {
      uint8 tmpByte;
      tmpByte = ((uint8) * (SignalBusSourcePtr - nFullBytes)) >> signalStartBit;
      tmpByte |= (uint8) (((uint8) * (SignalBusSourcePtr - nFullBytes - 1)) << (8 - signalStartBit));
      *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - nFullBytes) =
        tmpByte & (uint8) (~((uint8) (0xFFu << nBitsToWrite)));
    }
  }
  else
#  endif/* (COM_BUSACC_NBITNBYTE == STD_ON) */
  {
    Com_LMgt_CheckFatalErrorRetVoid((COM_SIGNAL_FALSE != Com_Signal_BusAccIsNBitNByte_Sw(AccessAttr)),
                                    Com_Signal_UnsupportedBusSignalType);
#  if (COM_BUSACC_NBITNBYTE_SW == STD_ON)
    {
      uint16_least nFullBytes;
      Com_Signal_SignalBitLengthType nBitsToWrite;
      nBitsToWrite = signalBitCount;
      if (signalBitCount > 8)
      {
        sint16_least i;
        nFullBytes = nBitsToWrite >> 3;
        for (i = (sint16_least) (nFullBytes - 1); i >= 0; i--)
        {
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - i) =
            (uint8) (*(SignalBusSourcePtr + i) >> signalStartBit);
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - i) |=
            (uint8) (*(SignalBusSourcePtr + i + 1) << (8 - signalStartBit));
          nBitsToWrite -= 8;
        }
      }
      else
      {
        nFullBytes = 0;
      }

      if (0 != nBitsToWrite)
      {
        uint8 tmpByte;
        tmpByte = ((uint8) * (SignalBusSourcePtr + nFullBytes)) >> signalStartBit;
        tmpByte |= (uint8) (((uint8) * (SignalBusSourcePtr + nFullBytes + 1)) << (8 - signalStartBit));
        *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - nFullBytes) =
          tmpByte & (uint8) (~((uint8) (0xFFu << nBitsToWrite)));
      }
    }
#  endif/* (COM_BUSACC_NBITNBYTE_SW == STD_ON) */
  }
# endif/* (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */

# if (COM_SIGNEXTENSION == STD_ON)
#  if ((COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
  if (COM_SIGNAL_FALSE != Com_Signal_SignExtRequired(AccessAttr))
  {
    Com_Signal_ReadSignalSignConversion(SignalId, SignalApplDestPtr, AccessAttr);
  }
#  endif/* ((COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
# endif/* (COM_SIGNEXTENSION == STD_ON) */
}                               /* End of Com_Signal_ReadSignal() */

# if (COM_SIGNEXTENSION == STD_ON)
#  if ((COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
COM_STATIC FUNC(void, COM_CODE) Com_Signal_ReadSignalSignConversion(Com_SignalIdType SignalId,
                                                                    P2VAR(void, AUTOMATIC,
                                                                          COM_APPL_VAR) SignalApplDestPtr,
                                                                    Com_Signal_AccessAttrType AccessAttr)
{
  uint8 signMask, msbMask;
  Com_Signal_SignalBitLengthType tmp;
  Com_LMgt_CheckFatalErrorRetVoid((COM_SIGNAL_FALSE == Com_Signal_ApplTypeIsBoolean(AccessAttr)),
                                  Com_Signal_InconsistentConfigurationData);
  tmp = Com_SignalGetLength(SignalId) - 1;
  {
#   if ((COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
    Com_Signal_SignalBitLengthType signMSBOffset = Com_Signal_ByteFromBitPos(tmp);
#   endif
    {
      uint8 signBitPos = Com_Signal_BitOffsetFromBitPos(tmp);
      signMask = (uint8) ((uint8) 0x1u << signBitPos);
      msbMask = (uint8) ((uint8) 0xFFu << signBitPos);
    }

#   if (COM_APPLTYPE_SINT8 == STD_ON)
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint8(AccessAttr))
    {
      if (0 != (signMask & (*(P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)))
      {                         /* negative value */
        (*(P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr) |= msbMask;
      }
      else
      {
      }
    }
    else
#   endif/* (COM_APPLTYPE_SINT8 == STD_ON) */
#   if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
      /* Implementation for Intel Plattforms */
#    if (COM_APPLTYPE_SINT16 == STD_ON)
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint16(AccessAttr))
    {
#     if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
      if (((0 !=
            (signMask &
             COM_HIBYTE((*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (signMSBOffset >> 1))))))
           && (0 != ((signMSBOffset) & (sint16_least) 1)))
          ||
          ((0 !=
            (signMask &
             COM_LOBYTE((*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (signMSBOffset >> 1))))))
           && (0 == ((signMSBOffset) & (sint16_least) 1))))
#     else
      if (0 != (signMask & (*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + signMSBOffset))))
#     endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
      {                         /* negative value */
        if (0 == signMSBOffset)
        {                       /* signal smaller or equal 8 bit */
#     if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
          COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)) |= msbMask;
          COM_HIBYTE((*(P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)) = COM_CAST2UINT8(0xFFu);
#     else
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr) |= msbMask;
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + 1) = COM_CAST2UINT8(0xFFu);
#     endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        }
        else
        {
#     if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
          COM_HIBYTE((*(P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr)) |= msbMask;
#     else
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + 1) |= msbMask;
#     endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        }
      }
      else
      {
      }
    }
    else
#    endif/* (COM_APPLTYPE_SINT16 == STD_ON) */
    {
      Com_LMgt_CheckFatalErrorRetVoid((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint32(AccessAttr)),
                                      Com_Signal_InconsistentConfigurationData);
#    if (COM_APPLTYPE_SINT32 == STD_ON)
      {
        sint16_least i;
#     if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
        if (((0 !=
              (signMask &
               COM_HIBYTE((*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (signMSBOffset >> 1))))))
             && (0 != ((signMSBOffset) & (sint16_least) 1)))
            ||
            ((0 !=
              (signMask &
               COM_LOBYTE((*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (signMSBOffset >> 1))))))
             && (0 == ((signMSBOffset) & (sint16_least) 1))))
#     else
        if (0 != (signMask & (*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + signMSBOffset))))
#     endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
        {                       /* negative value */
          (*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + signMSBOffset)) |= msbMask;
          for (i = (sint16_least) (signMSBOffset + 1); i < 4; i++)
          {
#     if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
            if (i & (sint16_least) 1)
            {
              /*ODD*/
                COM_HIBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
                COM_CAST2UINT8(0xFFu);
            }
            else
            {
              /*EVEN*/
                COM_LOBYTE(*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + (i >> 1))) =
                COM_CAST2UINT8(0xFFu);
            }
#     else
            *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr + i) = COM_CAST2UINT8(0xFFu);
#     endif/* _TEXAS_INSTRUMENTS_C_TMS320_ */
          }
        }
        else
        {
        }
      }
#    endif/* (COM_APPLTYPE_SINT32 == STD_ON) */
    }
#   elif (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#    if (COM_APPLTYPE_SINT16 == STD_ON)
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint16(AccessAttr))
    {
      if (0 != (signMask & (*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - signMSBOffset))))
      {                         /* negative value */
        *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - signMSBOffset) |= msbMask;
        if (0 == signMSBOffset)
        {                       /* signal smaller or equal 8 bit */
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - 1) = (uint8) 0xFFu;
        }
      }
      else
      {
      }
    }
    else
#    endif/* (COM_APPLTYPE_SINT16 == STD_ON) */
    {
      Com_LMgt_CheckFatalErrorRetVoid((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsSint32(AccessAttr)),
                                      Com_Signal_InconsistentConfigurationData);
#    if (COM_APPLTYPE_SINT32 == STD_ON)
      {
        sint16_least i;
        if (0 != (signMask & (*((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - signMSBOffset))))
        {                       /* negative value */
          *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - signMSBOffset) |= msbMask;
          for (i = (sint16_least) (signMSBOffset + 1); i < 4; i++)
          {
            *((P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) SignalApplDestPtr - i) = (uint8) 0xFFu;
          }
        }
        else
        {
        }
      }
#    endif/* (COM_APPLTYPE_SINT32 == STD_ON) */
    }
#   endif/* (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
  }
}                               /* End of Com_Signal_ReadSignalSignConversion() */
#  endif /* ((COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
# endif /* (COM_SIGNEXTENSION) */
#endif
/* KB end Com_Signal_GlobalIl_AsrComFunctions */
/* KB begin Com_Buffer_GlobalIl_AsrComFunctions */
/* KB end Com_Buffer_GlobalIl_AsrComFunctions */
/* KB begin Com_RxBuffer_GlobalIl_AsrComFunctions */
#if (COM_RXBUFFER == STD_ON)
# if (COM_RXINV == STD_ON) || (COM_RXDLMON_TIMEOUTDEFAULTVALUE == STD_ON) || (COM_RXUBHDLR_TIMEOUTDEFAULTVALUE == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_RxBuffer_WriteIpduWithMask(PduIdType ComRxPduId,
                                                               P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduDataPtr,
                                                               P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduMaskPtr)
{
  sint16_least i;
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pIpduBuf = Com_RxBuffer_GetIpduDataPtr(ComRxPduId);

  Com_LMgt_CheckFatalErrorRetVoid((ComRxPduId < Com_RxBuffer_GetRxIpduCnt()), Com_RxBuffer_IpduId_Param);
  Com_LMgt_CheckFatalErrorRetVoid((IpduDataPtr != NULL_PTR), Com_RxBuffer_InvalidPointer_Param);
  Com_LMgt_CheckFatalErrorRetVoid((IpduMaskPtr != NULL_PTR), Com_RxBuffer_InvalidPointer_Param);

  for (i = (sint16_least) Com_RxBuffer_GetIpduLength(ComRxPduId) - 1; i >= 0; i--)
  {
    pIpduBuf[i] = (pIpduBuf[i] & COM_CAST2UINT8(~IpduMaskPtr[i])) | (IpduDataPtr[i] & IpduMaskPtr[i]);
  }

}                               /* End of Com_RxBuffer_WriteIpduWithMask() */
# endif


# if (COM_SIGNALGROUPIF == STD_ON)
#  if (COM_RXSIGNAL_WRACCESS == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_RxBuffer_WriteSignalGroup(Com_SignalGroupIdType SignalGroupId,
                                                              P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr)
{
  P2CONST(uint8, AUTOMATIC, COM_PBCFG) maskPtr;
  PduIdType ipdu;
  sint16_least i;
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pIpduBuf;

  Com_LMgt_CheckFatalErrorRetVoid((SignalGroupId < Com_Signal_GetSignalGroupCnt()), Com_RxBuffer_SignalGroupId_Param);

  ipdu = Com_Signal_GetIpduFromSignalGroup(SignalGroupId);
  maskPtr = Com_Signal_GetSignalGroupMaskPtr(SignalGroupId);
  pIpduBuf = Com_RxBuffer_GetIpduDataPtr(ipdu) + Com_Signal_GetSignalGroupPduOffset(SignalGroupId);

  for (i = (sint16_least) Com_Signal_GetSignalGroupBufferLength(SignalGroupId) - 1; i >= 0; i--)
  {
    pIpduBuf[i] = (pIpduBuf[i] & COM_CAST2UINT8(~maskPtr[i])) | (ShadowBufferPtr[i] & maskPtr[i]);
  }

}                               /* End of Com_RxBuffer_WriteSignalGroup() */
#  endif
# endif /* (COM_SIGNALGROUPIF == STD_ON) */

# if ((COM_RXUBHDLR == STD_ON) || (COM_SIGNALGW_UB == STD_ON))
FUNC(boolean, COM_CODE) Com_RxBuffer_BitIsSet(PduIdType ComRxPduId, Com_Signal_SignalBitPositionType bitPos)
{
  uint8 bitMask;
  boolean retVal = FALSE;

  Com_LMgt_CheckFatalErrorRetValue((ComRxPduId < Com_RxBuffer_GetRxIpduCnt()), Com_RxBuffer_IpduId_Param, FALSE);

  bitMask = COM_CAST2UINT8(0x01u << Com_Signal_BitOffsetFromBitPos(bitPos));
  if (0 != (Com_RxBuffer_GetIpduDataPtr(ComRxPduId)[Com_Signal_ByteFromBitPos(bitPos)] & bitMask))
  {
    retVal = TRUE;
  }
  return retVal;

}                               /* End of Com_RxBuffer_BitIsSet() */
# endif /* ((COM_RXUBHDLR == STD_ON) || (COM_SIGNALGW_UB == STD_ON)) */
#endif /* COM_RXBUFFER == STD_ON */
/* KB end Com_RxBuffer_GlobalIl_AsrComFunctions */
/* KB begin Com_RxDlMon_GlobalIl_AsrComFunctions */
/* KB end Com_RxDlMon_GlobalIl_AsrComFunctions */
/* KB begin Com_RxLLIf_GlobalIl_AsrComFunctions */
/* KB end Com_RxLLIf_GlobalIl_AsrComFunctions */
/* KB begin Com_RxNHdlr_GlobalIl_AsrComFunctions */
#if (COM_RXNHDLR == STD_ON)

# if ((COM_RXNHDLR_NOTIFICATIONFUNCTION == STD_ON) || ((COM_RXNHDLR_TIMEOUTFLAG == STD_ON) && (COM_RESET_TIMEOUTFLAG == STD_ON)) || (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON))
#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_RxNHdlr_Indication(PduIdType ComPduId, PduLengthType ComPduLength)
#  else
COM_STATIC FUNC(void, COM_CODE) Com_RxNHdlr_Indication(PduIdType ComPduId)
#  endif
{
  Com_LMgt_CheckFatalErrorRetVoid((ComPduId < Com_RxBuffer_GetRxIpduCnt()), Com_RxNHdlr_IpduIdParamTooLarge);

#  if ((COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON) && (COM_RXNHDLR_IMMEDIATE_SIGNALPROCESSING == STD_ON))
  if (COM_CFG_FALSE == Com_ConfigValue(Com_RxNHdlr_DeferredSignalProcessing)[ComPduId])
#  endif
#  if (COM_RXNHDLR_IMMEDIATE_SIGNALPROCESSING == STD_ON)
  {                             /* immediate */
#   if (COM_RXNHDLR_IMMEDIATE_NOTIFICATIONFLAG == STD_ON)
    /* KB begin Com_RxNHdlr_SetRxNotificationFlag */
#    if (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON)
    {
      uint16_least notiFlagIndex;
#     if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
      for (notiFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) ComPduId];
           ((notiFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) (ComPduId + 1)]) &&
            (Com_ConfigValue(Com_RxNHdlr_NotiFlagIndirection)[notiFlagIndex].validDlc <= ComPduLength));
           notiFlagIndex++)
#     else
      for (notiFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) ComPduId];
           notiFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) (ComPduId + 1)];
           notiFlagIndex++)
#     endif
      {
        Com_RxNHdlr_FlagInfoRefType currentNotiFlagInfoPtr;
        Com_RxNHdlr_NotiFlagIdType currentNotiFlagId;
        Com_LMgt_CheckFatalErrorRetVoid((notiFlagIndex < Com_RxNHdlr_GetNotificationFlagCnt()),
                                        Com_RxNHdlr_NotiFlagIdxTooLarge);

        currentNotiFlagId = Com_ConfigValue(Com_RxNHdlr_NotiFlagIndirection)[notiFlagIndex].notiFlagId;
#     if ((COM_RXNHDLR_INHIBITINDFLAG == STD_ON) || (COM_RXINV_INHIBITINDFLAG == STD_ON))
        if (FALSE == Com_RxNHdlr_NotificationFlagInhibited(currentNotiFlagId))
#     endif
        {
          currentNotiFlagInfoPtr = &Com_RxNHdlr_NotificationFlagInfo[currentNotiFlagId];
          com_RxNHdlr_NotificationFlags[currentNotiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] |=
            currentNotiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask;
        }
      }
    }
#    endif
       /* (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON) */
    /* KB end Com_RxNHdlr_SetRxNotificationFlag */
#   endif /* (COM_RXNHDLR_IMMEDIATE_NOTIFICATIONFLAG == STD_ON) */
#   if ((COM_RESET_TIMEOUTFLAG == STD_ON)  && (COM_RXNHDLR_IMMEDIATE_TIMEOUTFLAG == STD_ON))
    /* KB begin Com_RxNHdlr_ClrRxTimeoutFlag */
#    if (COM_RXNHDLR_TIMEOUTFLAG == STD_ON)
    {
      uint16_least timeoutFlagIndex;
      for (timeoutFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) ComPduId];
           timeoutFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) (ComPduId + 1)];
           timeoutFlagIndex++)
      {
        Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
        Com_LMgt_CheckFatalErrorRetVoid((timeoutFlagIndex < Com_RxNHdlr_TimeoutFlagCnt),
                                        Com_RxNHdlr_TimeoutFlagIdxTooLarge);
        timeoutFlagInfoPtr =
          &Com_RxNHdlr_TimeoutFlagInfo[Com_ConfigValue(Com_RxNHdlr_TimeoutFlagIndirection)[timeoutFlagIndex]];
        com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
          COM_CAST2UINT8(~timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
      }
    }
#    endif/* (COM_RXNHDLR_TIMEOUTFLAG == STD_ON) */
    /* KB end Com_RxNHdlr_ClrRxTimeoutFlag */
#   endif /* ((COM_RESET_TIMEOUTFLAG == STD_ON)  && (COM_RXNHDLR_IMMEDIATE_TIMEOUTFLAG == STD_ON)) */
#   if (COM_RXNHDLR_IMMEDIATE_NOTIFICATIONFUNCTION == STD_ON)
    /* KB begin Com_RxNHdlr_CallNotificationFunction */
#    if (COM_RXNHDLR_NOTIFICATIONFUNCTION == STD_ON)
    {
      uint16_least notiIndex;

#     if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
      for (notiIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFunctions)[(PduIdType) ComPduId];
           ((notiIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFunctions)[(PduIdType) (ComPduId + 1)]) &&
            (Com_ConfigValue(Com_RxNHdlr_NotiFuncIndirection)[notiIndex].validDlc <= ComPduLength)); notiIndex++)
#     else
      for (notiIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFunctions)[(PduIdType) ComPduId];
           notiIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFunctions)[(PduIdType) (ComPduId + 1)]; notiIndex++)
#     endif
      {
        Com_LMgt_CheckFatalErrorRetVoid((notiIndex < Com_RxNHdlr_GetNotificationCnt()),
                                        Com_RxNHdlr_NotiFuncIdxTooLarge);
        Com_RxNHdlr_CallNotificationFunc(Com_ConfigValue(Com_RxNHdlr_NotiFuncIndirection)[notiIndex].notificationIdx);
      }
    }
#    endif
    /* KB end Com_RxNHdlr_CallNotificationFunction */
#   endif /* (COM_RXNHDLR_IMMEDIATE_NOTIFICATIONFUNCTION == STD_ON) */
  }
#  endif /* (COM_RXNHDLR_IMMEDIATE_SIGNALPROCESSING == STD_ON) */
#  if ((COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON) && (COM_RXNHDLR_IMMEDIATE_SIGNALPROCESSING == STD_ON))
  else
#  endif
#  if (COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
  {                             /* deferred */
#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
    com_RxNHdlr_HandleIPduDeferred[ComPduId] = ComPduLength + 1;
#   else
    com_RxNHdlr_HandleIPduDeferred[ComPduId] = TRUE;
#   endif
        /* (COM_DYNAMIC_DLC_SUPPORT == STD_ON) */
  }
#  endif
}                               /* End of Com_RxNHdlr_Indication() */
# endif /* ((COM_RXNHDLR_NOTIFICATIONFUNCTION == STD_ON) || ((COM_RXNHDLR_TIMEOUTFLAG == STD_ON) && (COM_RESET_TIMEOUTFLAG == STD_ON)) || (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON)) */

# if ((COM_RXNHDLR_TIMEOUTFUNCTION == STD_ON) || (COM_RXNHDLR_TIMEOUTFLAG == STD_ON))
COM_STATIC FUNC(void, COM_CODE) Com_RxNHdlr_Timeout(PduIdType ComPduId)
{
  Com_LMgt_CheckFatalErrorRetVoid((ComPduId < Com_RxBuffer_GetRxIpduCnt()), Com_RxNHdlr_IpduIdParamTooLarge);

  /* KB begin Com_RxNHdlr_SetRxTimeoutFlag */
#  if (COM_RXNHDLR_TIMEOUTFLAG == STD_ON)
  {
    uint16_least timeoutFlagIndex;
    for (timeoutFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) ComPduId];
         timeoutFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) (ComPduId + 1)];
         timeoutFlagIndex++)
    {
      Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
      Com_LMgt_CheckFatalErrorRetVoid((timeoutFlagIndex < Com_RxNHdlr_TimeoutFlagCnt),
                                      Com_RxNHdlr_TimeoutFlagIdxTooLarge);
      timeoutFlagInfoPtr =
        &Com_RxNHdlr_TimeoutFlagInfo[Com_ConfigValue(Com_RxNHdlr_TimeoutFlagIndirection)[timeoutFlagIndex]];
      com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] |=
        timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask;
    }
  }
#  endif /* (COM_RXNHDLR_TIMEOUTFLAG == STD_ON) */


  /* KB end Com_RxNHdlr_SetRxTimeoutFlag */
  /* KB begin Com_RxNHdlr_CallTimeoutFunction */
#  if (COM_RXNHDLR_TIMEOUTFUNCTION == STD_ON)
  {
    uint16_least notiIndex;
    for (notiIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFunctions)[(PduIdType) ComPduId];
         notiIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFunctions)[(PduIdType) (ComPduId + 1)]; notiIndex++)
    {
      Com_LMgt_CheckFatalErrorRetVoid((notiIndex < Com_RxNHdlr_GetTimeoutNotiCnt()),
                                      Com_RxNHdlr_TimeoutFuncIdxTooLarge);
      Com_RxNHdlr_TimeoutNotiFuncPtr[Com_ConfigValue(Com_RxNHdlr_TimeoutFuncIndirection)[notiIndex]] ();
    }
  }
#  endif
       /* (COM_RXNHDLR_TIMEOUTFUNCTION == STD_ON) */
  /* KB end Com_RxNHdlr_CallTimeoutFunction */
}                               /* End of Com_RxNHdlr_Timeout() */
# endif /* ((COM_RXNHDLR_TIMEOUTFUNCTION == STD_ON) || (COM_RXNHDLR_TIMEOUTFLAG == STD_ON)) */
#endif /* COM_RXNHDLR == STD_ON */
/* KB end Com_RxNHdlr_GlobalIl_AsrComFunctions */
/* KB begin Com_RxSigIf_GlobalIl_AsrComFunctions */
/* KB end Com_RxSigIf_GlobalIl_AsrComFunctions */
/* KB begin Com_RxUbHdlr_GlobalIl_AsrComFunctions */
#if ((COM_RXUBHDLR_NOTIFICATIONFUNCTION == STD_ON) || (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON))
# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_RxUbHdlr_Indication(PduIdType ComPduId, PduLengthType ComPduLength)
# else
COM_STATIC FUNC(void, COM_CODE) Com_RxUbHdlr_Indication(PduIdType ComPduId)
# endif
{
  uint16_least ubId;
  Com_LMgt_CheckFatalErrorRetVoid((ComPduId < Com_RxBuffer_GetRxIpduCnt()), Com_RxUbHdlr_IpduId_Param);

# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
  for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[ComPduId];
       ((ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[ComPduId + 1]) &&
        (Com_ConfigValue(Com_RxUbHdlr_UbBitPosition)[ubId].validDlc <= ComPduLength)); ubId++)
# else
  for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[ComPduId];
       ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[ComPduId + 1]; ubId++)
# endif
  {
    Com_LMgt_CheckFatalErrorRetVoid((ubId < Com_RxUbHdlr_GetUpdateBitCnt()), Com_RxUbHdlr_InvalidUbHdl);

    if (TRUE == Com_RxBuffer_BitIsSet(ComPduId, Com_ConfigValue(Com_RxUbHdlr_UbBitPosition)[ubId].updatebitPosition))
    {
# if (COM_RXUBHDLR_TIMEOUT == STD_ON)
      com_RxUbHdlr_TimeoutCnt[ubId] = Com_ConfigValue(Com_RxUbHdlr_TimeoutTime)[ubId];
# endif

# if ((COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON) && (COM_RXUBHDLR_IMMEDIATE_SIGNALPROCESSING == STD_ON))
      if (COM_CFG_FALSE == Com_ConfigValue(Com_RxNHdlr_DeferredSignalProcessing)[ComPduId])
# endif
# if (COM_RXUBHDLR_IMMEDIATE_SIGNALPROCESSING == STD_ON)
      {
#  if (COM_RXUBHDLR_IMMEDIATE_NOTIFICATIONFLAG == STD_ON)
        /* KB begin Com_RxUbHdlr_SetRxNotificationFlag */
#   if (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON)
        {
          Com_RxNHdlr_NotiFlagIdType notiFlagIdx = Com_ConfigValue(Com_RxUbHdlr_NotiFlagHdl)[ubId];

          if (COM_RX_NHDLR_NONOTIFLAG != notiFlagIdx)
          {
            Com_RxNHdlr_FlagInfoRefType notiFlagInfoPtr;
            Com_LMgt_CheckFatalErrorBreak((notiFlagIdx < Com_RxNHdlr_NotiFlagCnt),
                                          Com_RxUbHdlr_NotificationFlagIdxTooLarge);
#    if ((COM_RXNHDLR_INHIBITINDFLAG == STD_ON) || (COM_RXINV_INHIBITINDFLAG == STD_ON))
            if (FALSE == Com_RxNHdlr_NotificationFlagInhibited(notiFlagIdx))
#    endif
            {
              notiFlagInfoPtr = &Com_RxNHdlr_NotificationFlagInfo[notiFlagIdx];
              com_RxNHdlr_NotificationFlags[notiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] |=
                notiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask;
            }
          }
        }
#   endif/* (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON) */
        /* KB end Com_RxUbHdlr_SetRxNotificationFlag */
#  endif /* (COM_RXUBHDLR_IMMEDIATE_NOTIFICATIONFLAG == STD_ON) */
#  if ((COM_RESET_TIMEOUTFLAG == STD_ON) && (COM_RXUBHDLR_IMMEDIATE_TIMEOUTFLAG == STD_ON))
        /* KB begin Com_RxUbHdlr_ClrRxTimeoutFlag */
#   if (COM_RXUBHDLR_TIMEOUTFLAG == STD_ON)
        {
          Com_RxNHdlr_TimeoutFlagIdType timeoutFlagIdx = Com_ConfigValue(Com_RxUbHdlr_TimeoutFlagHdl)[ubId];

          if (COM_RX_NHDLR_NOTIMEOUTFLAG != timeoutFlagIdx)
          {
            Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
            Com_LMgt_CheckFatalErrorBreak((timeoutFlagIdx < Com_RxNHdlr_TimeoutFlagCnt),
                                          Com_RxUbHdlr_TimeoutFlagIdxTooLarge);
            timeoutFlagInfoPtr = &Com_RxNHdlr_TimeoutFlagInfo[timeoutFlagIdx];
            com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
              COM_CAST2UINT8(~timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
          }
        }
#   endif
        /* KB end Com_RxUbHdlr_ClrRxTimeoutFlag */
#  endif /* ((COM_RESET_TIMEOUTFLAG == STD_ON) && (COM_RXUBHDLR_IMMEDIATE_TIMEOUTFLAG == STD_ON)) */
#  if (COM_RXUBHDLR_IMMEDIATE_NOTIFICATIONFUNCTION == STD_ON)
        /* KB begin Com_RxUbHdlr_CallNotificationFunction */
#   if (COM_RXUBHDLR_NOTIFICATIONFUNCTION == STD_ON)
        {
          Com_RxNHdlr_NotificationIdxType notiFctIdx = Com_ConfigValue(Com_RxUbHdlr_NotiFuncIndirection)[ubId];
          if (0 < notiFctIdx)
          {
#    if ((COM_CONFIG_VARIANT == 2)||(COM_CONFIG_VARIANT == 3))
            /*lint -e{661} If the number of notifications is 0, the array has minimum 1 value. */
#    endif
            Com_RxNHdlr_CallNotificationFunc(notiFctIdx);
          }
        }
#   endif
        /* KB end Com_RxUbHdlr_CallNotificationFunction */
#  endif /* (COM_RXUBHDLR_IMMEDIATE_NOTIFICATIONFUNCTION == STD_ON) */
      }
# endif /* (COM_RXUBHDLR_IMMEDIATE_SIGNALPROCESSING == STD_ON) */
# if ((COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON) && (COM_RXUBHDLR_IMMEDIATE_SIGNALPROCESSING == STD_ON))
      else
# endif
# if (COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
      {
        com_RxUbHdlr_HandleUbDeferred[ubId] = TRUE;
      }
# endif
    }
  }
}                               /* End of Com_RxUbHdlr_Indication() */
#endif
/* KB end Com_RxUbHdlr_GlobalIl_AsrComFunctions */
/* KB begin Com_RxInv_GlobalIl_AsrComFunctions */
#if ((COM_RXINV == STD_ON) && (COM_RXINV_NOTIINVFUNC == STD_ON))
# if ( (COM_RXINV_NOTIINVFUNC_NOUB_TO == STD_ON) || (COM_RXINV_NOTIINVFUNC_NOUB == STD_ON) )
COM_STATIC FUNC(void, COM_CODE) Com_RxInv_NotiInvalidNoUb(PduIdType ComRxPduId, boolean isContextTimeout)
{
  uint16_least InvObjIdx;
  uint16_least InvObjStopIdx;

  Com_RxNHdlr_NotiFuncPtrType InvFuncPtr;
  Com_RxInv_NotiInvFuncIndirType InvFuncIndir;

  InvObjIdx = Com_ConfigValue(Com_RxInv_IPdu2NotiInvObjNoUb)[ComRxPduId];
  InvObjStopIdx = Com_ConfigValue(Com_RxInv_IPdu2NotiInvObjNoUb)[ComRxPduId + 1];

  for (; InvObjIdx < InvObjStopIdx; InvObjIdx++)
  {
    InvFuncIndir = Com_ConfigValue(Com_RxInv_NotiInvFuncIndirNoUb)[(Com_RxInv_NotiInvObjNoUbIdxType) InvObjIdx];
    if ((!isContextTimeout) || (InvFuncIndir.comRxDataTimeoutAction))
    {
      InvFuncPtr = Com_RxInv_InvalidNotiFuncPtr[InvFuncIndir.invNotiFuncIdx];
      if (InvFuncPtr != NULL_PTR)
      {
        InvFuncPtr();
      }
    }
  }
}
# endif /* ( (COM_RXINV_NOTIINVFUNC_NOUB_TO == STD_ON) || (COM_RXINV_NOTIINVFUNC_NOUB == STD_ON) ) */
# if ( (COM_RXINV_NOTIINVFUNC_UB_TO == STD_ON) || (COM_RXINV_NOTIINVFUNC_UB == STD_ON) )
COM_STATIC FUNC(void, COM_CODE) Com_RxInv_NotiInvalidUb(Com_RxUbHdlr_UbIdType UbId, boolean isContextTimeout)
{
  Com_RxNHdlr_NotiFuncPtrType InvFuncPtr;
  Com_RxInv_NotiInvFuncIndirType InvFuncIndir;

  InvFuncIndir = Com_ConfigValue(Com_RxInv_NotiInvFuncIndirUb)[UbId];
  if ((InvFuncIndir.invNotiFuncIdx != 0) && ((!isContextTimeout) || (InvFuncIndir.comRxDataTimeoutAction)))
  {
    InvFuncPtr = Com_RxInv_InvalidNotiFuncPtr[InvFuncIndir.invNotiFuncIdx];
    if (InvFuncPtr != NULL_PTR)
    {
      InvFuncPtr();
    }
  }
}
# endif /* ( (COM_RXINV_NOTIINVFUNC_UB_TO == STD_ON) || (COM_RXINV_NOTIINVFUNC_UB == STD_ON) ) */
#endif /* ((COM_RXINV == STD_ON) && (COM_RXINV_NOTIINVFUNC == STD_ON)) */
/* KB end Com_RxInv_GlobalIl_AsrComFunctions */
/* KB begin Com_TxInv_GlobalIl_AsrComFunctions */
/* KB end Com_TxInv_GlobalIl_AsrComFunctions */
/* KB begin Com_TxBuffer_GlobalIl_AsrComFunctions */
#if (COM_TXBUFFER == STD_ON)
# if (COM_SIGNALGW_MSV == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_TxBuffer_WriteIpduWithMask(PduIdType ComTxPduId,
                                                               P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduDataPtr,
                                                               P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduMaskPtr)
{
  sint16_least i;
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pIpduBuf = Com_TxBuffer_GetIpduDataPtr(ComTxPduId);

  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), Com_TxBuffer_IpduId_Param);
  Com_LMgt_CheckFatalErrorRetVoid((IpduDataPtr != NULL_PTR), Com_TxBuffer_InvalidPointer_Param);
  Com_LMgt_CheckFatalErrorRetVoid((IpduMaskPtr != NULL_PTR), Com_TxBuffer_InvalidPointer_Param);

  for (i = (sint16_least) Com_TxBuffer_GetIpduLength(ComTxPduId) - 1; i >= 0; i--)
  {
    pIpduBuf[i] = (pIpduBuf[i] & COM_CAST2UINT8(~IpduMaskPtr[i])) | (IpduDataPtr[i] & IpduMaskPtr[i]);
  }

}                               /* End of Com_TxBuffer_WriteIpduWithMask() */
# endif /* (COM_SIGNALGW_MSV == STD_ON) */


# if (COM_TXUBHDLR == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_TxBuffer_ClearMaskedBits(PduIdType ComTxPduId,
                                                             P2CONST(uint8, AUTOMATIC, COM_PBCFG) IpduMaskPtr)
{
  sint16_least i;
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pIpduBuf = Com_TxBuffer_GetIpduDataPtr(ComTxPduId);

  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), Com_TxBuffer_IpduId_Param);
  Com_LMgt_CheckFatalErrorRetVoid((IpduMaskPtr != NULL_PTR), Com_TxBuffer_InvalidPointer_Param);

  for (i = (sint16_least) Com_TxBuffer_GetIpduLength(ComTxPduId) - 1; i >= 0; i--)
  {
    pIpduBuf[i] = (pIpduBuf[i] & IpduMaskPtr[i]);
  }

}                               /* End of Com_TxBuffer_ClearMaskedBits() */
# endif


# if (COM_SIGNALGROUPIF == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_TxBuffer_WriteSignalGroup(Com_SignalGroupIdType SignalGroupId,
                                                              P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr)
{
  P2CONST(uint8, AUTOMATIC, COM_PBCFG) maskPtr;
  PduIdType ipdu;
  sint16_least i;
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pIpduBuf;

  Com_LMgt_CheckFatalErrorRetVoid((SignalGroupId < Com_Signal_GetSignalGroupCnt()), Com_TxBuffer_SignalGroupId_Param);

  ipdu = Com_Signal_GetIpduFromSignalGroup(SignalGroupId);
  maskPtr = Com_Signal_GetSignalGroupMaskPtr(SignalGroupId);
  pIpduBuf = Com_TxBuffer_GetIpduDataPtr(ipdu) + Com_Signal_GetSignalGroupPduOffset(SignalGroupId);

  for (i = (sint16_least) Com_Signal_GetSignalGroupBufferLength(SignalGroupId) - 1; i >= 0; i--)
  {
    pIpduBuf[i] = (pIpduBuf[i] & COM_CAST2UINT8(~maskPtr[i])) | (ShadowBufferPtr[i] & maskPtr[i]);
  }

}                               /* End of Com_TxBuffer_WriteSignalGroup() */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */

# if ((COM_TXSIGIF == STD_ON) && (COM_TXUBHDLR == STD_ON))
#  if ((COM_SIGNALGROUPIF == STD_ON) || ((COM_SIGNALIF == STD_ON) && ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))))
COM_STATIC FUNC(void, COM_CODE) Com_TxBuffer_SetBit(PduIdType ComTxPduId, Com_Signal_SignalBitPositionType bitPos)
{
  uint8 bitMask = COM_CAST2UINT8(0x1u << Com_Signal_BitOffsetFromBitPos(bitPos));
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pIpduBuffer = Com_TxBuffer_GetIpduDataPtr(ComTxPduId);

  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), Com_TxBuffer_IpduId_Param);

  pIpduBuffer[Com_Signal_ByteFromBitPos(bitPos)] |= bitMask;

}                               /* End of Com_TxBuffer_SetBit() */
#  endif /* ((COM_SIGNALGROUPIF == STD_ON) || ((COM_SIGNALIF == STD_ON) && ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)))) */
# endif /* ((COM_TXSIGIF == STD_ON) && (COM_TXUBHDLR == STD_ON)) */
#endif /* COM_TXBUFFER == STD_ON */
/* KB end Com_TxBuffer_GlobalIl_AsrComFunctions */
/* KB begin Com_TxDlMon_GlobalIl_AsrComFunctions */
/* KB end Com_TxDlMon_GlobalIl_AsrComFunctions */
/* KB begin Com_TxLLIf_GlobalIl_AsrComFunctions */
#if (COM_TXLLIF == STD_ON)
COM_STATIC FUNC(Std_ReturnType, COM_CODE) Com_TxLLIf_Transmit(PduIdType ComTxPduId)
{
  Std_ReturnType retVal = E_OK;
  PduInfoType PduInfo;
# if (COM_TXPDUCALLOUT == STD_ON)
  boolean CalloutResult;
# endif /* (COM_TXPDUCALLOUT == STD_ON) */

  Com_LMgt_CheckDetErrorReturnValue((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), COMServiceId_Il_AsrComInternal,
                                    Com_TxLLIf_Transmit_IpduIdParam, E_NOT_OK);
  PduInfo.SduDataPtr = Com_TxBuffer_GetIpduDataPtr(ComTxPduId);
  PduInfo.SduLength = Com_TxBuffer_GetIpduLength(ComTxPduId);
  Com_LMgt_CheckDetErrorReturnValue((PduInfo.SduDataPtr != NULL_PTR), COMServiceId_Il_AsrComInternal,
                                    Com_TxLLIf_Transmit_PduInfoNullPointer, E_NOT_OK);

# if ((COM_TXUBHDLR == STD_ON) || (COM_TXDLMON == STD_ON) || (COM_TXPDUCALLOUT == STD_ON))
  SchM_Enter_Com(COM_EXCLUSIVE_AREA_2);
# endif
# if (COM_TXPDUCALLOUT == STD_ON)
  {
    Com_TxLLIf_PduCalloutIdType CalloutId = Com_ConfigValue(Com_TxLLIf_PduCalloutIndirection)[ComTxPduId];
    if (COM_TXLLIF_NO_PDUCALLOUT == CalloutId)
    {
      CalloutResult = TRUE;
    }
    else
    {
      CalloutResult = Com_TxLLIf_PduCallout[CalloutId] (ComTxPduId, (COM_TXCALLOUT_TYPE) COM_APPLTXCALLOUT_PARA);
    }
  }

  if (TRUE == CalloutResult)
# endif /* (COM_TXPDUCALLOUT == STD_ON) */
  {
# if (COM_TXDLMON == STD_ON)
    Com_TxDlMon_ComTransmit(ComTxPduId);
# endif
# if (COM_TPINTERFACE == STD_ON)
    if (COM_TXLLIF_IFLAYER_PDU == Com_ConfigValue(Com_TxLLIf_IsTpLayerIpdu)[ComTxPduId])
# endif
    {
      retVal = PduR_ComTransmit(ComTxPduId, &PduInfo);
    }
# if (COM_TPINTERFACE == STD_ON)
    else
    {
      /* Transmit PDU using the TP interface */
      if (FALSE == com_TxLLIf_TpPduInfo[ComTxPduId].lockedForTpTx)
      {
        /* Copy data to the shadow buffer and trigger the transmission */
        PduInfoType tpPduInfo;
        P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pShadowBuffer =
          Com_TxBuffer_GetIpduDataPtr(ComTxPduId) + Com_TxBuffer_GetIpduLength(ComTxPduId);
        tpPduInfo.SduLength = PduInfo.SduLength;
        tpPduInfo.SduDataPtr = pShadowBuffer;
        Com_LMgt_MemCpyRamToRam(pShadowBuffer, PduInfo.SduDataPtr, PduInfo.SduLength);
        retVal = PduR_ComTransmit(ComTxPduId, &tpPduInfo);
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
# endif
# if (COM_TXUBHDLR == STD_ON)
    if (E_OK == retVal)
    {
      Com_TxBuffer_ClearMaskedBits(ComTxPduId, Com_TxLLIf_GetIpduClearUbMask(ComTxPduId));
    }
# endif
# if ((COM_TXUBHDLR == STD_ON) || (COM_TXDLMON == STD_ON) || (COM_TXPDUCALLOUT == STD_ON))
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_2);
# endif
# if (COM_TXNHDLR == STD_ON) || (COM_TXNHDLR_EMULATION == STD_ON)
    if (E_NOT_OK != retVal)
    {
#  if (COM_TXNHDLR == STD_ON)
      Com_TxNHdlr_WaitForConfirmation(ComTxPduId);
#  endif
# endif /* (COM_TXNHDLR == STD_ON) || (COM_TXNHDLR_EMULATION == STD_ON) */
# if (COM_TXNHDLR == STD_OFF) && (COM_TXNHDLR_EMULATION == STD_ON)
#  if (COM_TXDLMON == STD_ON)
      Com_TxDlMon_Confirmation(ComTxPduId);
#  endif
#  if (COM_TXMODEHDLR == STD_ON) && ((COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) || (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON))
      (void) Com_TxModeHdlr_Confirmation(ComTxPduId);
#  endif
# endif /* (COM_TXNHDLR == STD_OFF) && (COM_TXNHDLR_EMULATION == STD_ON) */
# if (COM_TXNHDLR == STD_ON) || (COM_TXNHDLR_EMULATION == STD_ON)
    }
# endif
  }
# if (COM_TXPDUCALLOUT == STD_ON)
  else
  {
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_2);
  }
# endif /* (COM_TXPDUCALLOUT == STD_ON) */
  return retVal;
}                               /* End of Com_TxLLIf_Transmit() */
#endif /* COM_TXLLIF == STD_ON */
/* KB end Com_TxLLIf_GlobalIl_AsrComFunctions */
/* KB begin Com_TxModeHdlr_GlobalIl_AsrComFunctions */
#if (COM_TXMODEHDLR == STD_ON)
# if (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)
FUNC(void, COM_CODE) Com_TxModeHdlr_TriggerDeferredIpduSend(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()),
                                  Com_TxModeHdlr_Param_TriggerDeferredIpduSend);
  if (Com_LMgt_TxIpduActive(ComTxPduId))
  {
    if ((Com_TxModeHdlr_GetCurrentTxMode(ComTxPduId) & COM_TXMODEHDLR_TXMODE_DIRECT) != (Com_TxModeHdlr_TxModeMode) 0u)
    {
#  if (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON)
      com_TxModeHdlr_RepetitionCnt[ComTxPduId] =
        COM_CAST2UINT8(Com_TxModeHdlr_GetTxModeParameter(ComTxPduId, COM_TXMODE_PARAM_REPETITIONCOUNT));
      if (com_TxModeHdlr_RepetitionCnt[ComTxPduId] > (uint8) 0u)
      {
        com_TxModeHdlr_RepCycleCnt[ComTxPduId] = (uint16) 1u;
      }
      else
#  endif /* (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON) */
      {
        com_TxModeHdlr_TransmitRequest[ComTxPduId] = TRUE;
      }
    }
  }
}                               /* End of Com_TxModeHdlr_TriggerDeferredIpduSend() */
# endif /* (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) */

COM_STATIC FUNC(void, COM_CODE) Com_TxModeHdlr_InitTxMode(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
# if (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON)
  if ((Com_TxModeHdlr_GetCurrentTxMode(ComTxPduId) & COM_TXMODEHDLR_TXMODE_PERIODIC) !=
      (Com_TxModeHdlr_TxModeMode) 0x00u)
  {
    com_TxModeHdlr_CyclicSendRequest[ComTxPduId] = TRUE;
    com_TxModeHdlr_CycleTimeCnt[ComTxPduId] = (uint16) 1u;
  }
  else
  {
    com_TxModeHdlr_CyclicSendRequest[ComTxPduId] = FALSE;
  }
# endif /* (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON) */
  com_TxModeHdlr_TransmitRequest[ComTxPduId] = FALSE;
# if (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON)
  com_TxModeHdlr_RepetitionCnt[ComTxPduId] = (uint8) 0u;
# endif /* (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON) */
}                               /* End of Com_TxModeHdlr_InitTxMode() */


# if ((COM_SIGNALIF == STD_ON) && (COM_TXMODEHDLR_TMS == STD_ON))
COM_STATIC FUNC(void, COM_CODE) Com_TxModeHdlr_UpdateTxMode(CONST(PduIdType, AUTOMATIC) ComTxPduId,
                                                            uint16 FilterByteOffs, uint8 FilterBitMask,
                                                            boolean FilterState)
{
  if ((((com_Buffer[FilterByteOffs] & FilterBitMask) != (uint8) 0x00u) ? TRUE : FALSE) != FilterState)
  {
    /* set or reset the filter bit */
    if (TRUE == FilterState)
    {
      com_Buffer[FilterByteOffs] |= FilterBitMask;
    }
    else
    {
      com_Buffer[FilterByteOffs] &= COM_CAST2UINT8(~FilterBitMask);
    }
    Com_TxModeHdlr_UpdateTMS(ComTxPduId);
  }
}                               /* End of Com_TxModeHdlr_UpdateTxMode() */
# endif

# if ((COM_TXMODEHDLR_TMS == STD_ON) && ((COM_SIGNALIF == STD_ON) || (COM_SIGNALGROUPIF == STD_ON)))
COM_STATIC FUNC(void, COM_CODE) Com_TxModeHdlr_UpdateTMS(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
  boolean TxMode = FALSE;
  Com_TxModeHdlr_TxModeHdlType NewTxMode;
  uint16_least FilterByteIndex = Com_ConfigValue(Com_TxModeHdlr_SigFilterStartIdx)[ComTxPduId];
  uint16_least FilterStopIndex = Com_ConfigValue(Com_TxModeHdlr_SigFilterStartIdx)[ComTxPduId + 1];

  if (FilterByteIndex != FilterStopIndex)
  {
    /* check if any filter bit is set for this I-PDU */
    for (; FilterByteIndex < FilterStopIndex; FilterByteIndex++)
    {
      if (com_Buffer[FilterByteIndex] != (uint8) 0u)
      {
        TxMode = TRUE;
        break;
      }
    }
    /* calculate new tx mode */
    NewTxMode =
      (TRUE ==
       TxMode) ? Com_ConfigValue(Com_TxModeHdlr_TxModeTrue)[ComTxPduId] :
      Com_ConfigValue(Com_TxModeHdlr_TxModeFalse)[ComTxPduId];
    /* check if tx mode has to be changed */
    if (com_TxModeHdlr_CurrentTxMode[ComTxPduId] != NewTxMode)
    {
      com_TxModeHdlr_CurrentTxMode[ComTxPduId] = NewTxMode;
      Com_TxModeHdlr_InitTxMode(ComTxPduId);
#  if (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)
      Com_TxModeHdlr_TriggerDeferredIpduSend(ComTxPduId);
#  endif /* (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) */
    }
  }
}                               /* End of Com_TxModeHdlr_UpdateTMS() */
# endif

# if ((COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) || (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON))
#  if ((COM_TXNHDLR_EMULATION == STD_OFF) || ((COM_TXNHDLR == STD_OFF) && (COM_TXLLIF == STD_ON)))
COM_STATIC FUNC(boolean, COM_CODE) Com_TxModeHdlr_Confirmation(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
  boolean retVal = TRUE;
  Com_LMgt_CheckFatalErrorRetValue((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), Com_TxModeHdlr_Param_Confirmation,
                                   FALSE);
  if (Com_LMgt_TxIpduActive(ComTxPduId))
  {
#   if (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON)
    com_TxModeHdlr_DelayTimeCnt[ComTxPduId] = Com_ConfigValue(Com_TxModeHdlr_MinDelayTime)[ComTxPduId];
#   endif /* (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) */

#   if (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON)
    if (com_TxModeHdlr_RepetitionCnt[ComTxPduId] > (uint8) 0u)
    {
      com_TxModeHdlr_RepetitionCnt[ComTxPduId]--;
      if (com_TxModeHdlr_RepetitionCnt[ComTxPduId] > (uint8) 0u)
      {
        retVal = FALSE;
      }
    }
#   endif /* (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON) */
  }
  return retVal;
}                               /* End of Com_TxModeHdlr_Confirmation() */
#  endif /* ((COM_TXNHDLR_EMULATION == STD_OFF) || ((COM_TXNHDLR == STD_OFF) && (COM_TXLLIF == STD_ON))) */
# endif /* ((COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) || (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON)) */

COM_STATIC FUNC(void, COM_CODE) Com_TxModeHdlr_Stop(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), Com_TxModeHdlr_Param_Stop);
  com_TxModeHdlr_TransmitRequest[ComTxPduId] = FALSE;
# if (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON)
  com_TxModeHdlr_RepetitionCnt[ComTxPduId] = (uint8) 0u;
  com_TxModeHdlr_RepCycleCnt[ComTxPduId] = (uint16) 0u;
# endif /* (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON) */

# if (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON)
  /* reload the time offset counter. If the I-PDU is started again, the time offset is already set */
  com_TxModeHdlr_CycleTimeCnt[ComTxPduId] = Com_TxModeHdlr_GetTxModeParameter(ComTxPduId, COM_TXMODE_PARAM_TIMEOFFSET);
# endif /* (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON) */

# if (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON)
  com_TxModeHdlr_DelayTimeCnt[ComTxPduId] = (uint16) 0u;
# endif /* (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) */
}                               /* End of Com_TxModeHdlr_Stop() */

#endif /* COM_TXMODEHDLR == STD_ON */
/* KB end Com_TxModeHdlr_GlobalIl_AsrComFunctions */
/* KB begin Com_TxNHdlr_GlobalIl_AsrComFunctions */
#if (COM_TXNHDLR == STD_ON)
# if ((COM_TXNHDLR_EMULATION == STD_OFF) && ((COM_TXCONFIRMATION_DEFERRED == STD_ON) || (COM_TXCONFIRMATION_IMMEDIATE == STD_ON)))
COM_STATIC FUNC(void, COM_CODE) Com_TxNHdlr_Confirmation(PduIdType ComTxPduId)
{
  uint16_least notiIndex;
  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), Com_TxNHdlr_IpduIdParamTooLarge);

#  if (COM_TXERRORNOTIFICATION == STD_ON)
  com_TxNHdlr_WaitingForConfirmation[ComTxPduId] = FALSE;
#  endif

  for (notiIndex = Com_ConfigValue(Com_TxNHdlr_Ipdu2NotificationFunctions)[ComTxPduId];
       notiIndex < Com_ConfigValue(Com_TxNHdlr_Ipdu2NotificationFunctions)[ComTxPduId + 1]; notiIndex++)
  {
    Com_LMgt_CheckFatalErrorRetVoid((notiIndex < Com_TxNHdlr_GetNotificationCnt()), Com_TxNHdlr_NotiFuncIdxTooLarge);
#  if ((COM_TXCONFIRMATION_DEFERRED == STD_ON) && (COM_TXCONFIRMATION_IMMEDIATE == STD_ON))
    if (COM_CFG_FALSE == Com_ConfigValue(Com_TxNHdlr_CallNotiDeferred)[ComTxPduId])
#  endif
#  if (COM_TXCONFIRMATION_IMMEDIATE == STD_ON)
    {                           /* immediate */
      Com_TxNHdlr_NotificationFuncPtr[Com_ConfigValue(Com_TxNHdlr_NotiFuncIndirection)[notiIndex]] ();
    }
#  endif
#  if ((COM_TXCONFIRMATION_DEFERRED == STD_ON) && (COM_TXCONFIRMATION_IMMEDIATE == STD_ON))
    else
#  endif
#  if (COM_TXCONFIRMATION_DEFERRED == STD_ON)
    {                           /* deferred */
      com_TxNHdlr_HandleIPduDeferred[ComTxPduId] = TRUE;
    }
#  endif
  }
}                               /* End of Com_TxNHdlr_Confirmation() */
# endif

# if (COM_TXNHDLR_TIMEOUTFUNCTION == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_TxNHdlr_Timeout(PduIdType ComTxPduId)
{
  uint16_least notiIndex;

  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), Com_TxNHdlr_IpduIdParamTooLarge);
  for (notiIndex = Com_ConfigValue(Com_TxNHdlr_Ipdu2TimeoutFunctions)[ComTxPduId];
       notiIndex < Com_ConfigValue(Com_TxNHdlr_Ipdu2TimeoutFunctions)[ComTxPduId + 1]; notiIndex++)
  {
    Com_LMgt_CheckFatalErrorRetVoid((notiIndex < Com_TxNHdlr_GetTimeoutNotiCnt()), Com_TxNHdlr_TimeoutFuncIdxTooLarge);
    Com_TxNHdlr_TimeoutNotiFuncPtr[Com_ConfigValue(Com_TxNHdlr_TimeoutFuncIndirection)[notiIndex]] ();
  }
}                               /* End of Com_TxNHdlr_Timeout() */

# endif /* (COM_TXNHDLR_TIMEOUTFUNCTION == STD_ON) */
#endif /* COM_TXNHDLR == STD_ON */
/* KB end Com_TxNHdlr_GlobalIl_AsrComFunctions */
/* KB begin Com_TxSigIf_GlobalIl_AsrComFunctions */
#if (COM_TXSIGIF == STD_ON)
# if (COM_SIGNALGROUPIF == STD_ON)
COM_STATIC FUNC(uint8, COM_CODE) Com_TxSigIf_SendSignalGroup(Com_SignalGroupIdType SignalGroupId,
                                                             P2CONST(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr)
{
  uint8 retVal = E_OK;
  PduIdType ComPduId = Com_Signal_GetIpduFromSignalGroup(SignalGroupId);

#  if (COM_RXSIGNAL_WRACCESS == STD_ON)
  if (SignalGroupId >= Com_Signal_GetRxSignalGroupCnt())
#  else
  Com_LMgt_CheckFatalErrorRetValue((SignalGroupId >= Com_Signal_GetRxSignalGroupCnt()),
                                   Com_TxSigIf_Init_SignalGroupIndex, COM_SERVICE_NOT_AVAILABLE);
#  endif /* (COM_RXSIGNAL_WRACCESS == STD_ON) */
  {
    /* only for tx signal groups */
    Com_LMgt_CheckDetErrorReturnValue((ComPduId < Com_TxBuffer_GetTxIpduCnt()), COMServiceId_Il_AsrComInternal,
                                      Com_SendSignalGroup_PduId, COM_SERVICE_NOT_AVAILABLE);

    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
#  if (COM_TXMODEHDLR_TMS == STD_ON)
    Com_TxModeHdlr_UpdateTMS(ComPduId);
#  endif

    {
#  if ((COM_TXUBHDLR == STD_ON) || (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON))
      Com_SignalGroupIdType TxSignalGroupId = SignalGroupId - Com_Signal_GetRxSignalGroupCnt();
#  endif
#  if (COM_TXUBHDLR == STD_ON)
      {
        Com_Signal_SignalBitPositionType ubBitPos = Com_ConfigValue(Com_TxSigIf_SignalGroup2UbBitPos)[TxSignalGroupId];

        if (ubBitPos != COM_TX_SIGIF_NOUPDATEBIT)
        {
          Com_TxBuffer_SetBit(ComPduId, ubBitPos);
        }
      }
#  endif /* (COM_TXUBHDLR == STD_ON) */
      Com_TxBuffer_WriteSignalGroup(SignalGroupId, ShadowBufferPtr);

      if (Com_LMgt_TxIpduActive(ComPduId))
      {
#  if (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)
        if (TRUE == com_TxSigIf_SignalGroupEventFlag[TxSignalGroupId])
        {
          Com_TxModeHdlr_TriggerDeferredIpduSend(ComPduId);
          com_TxSigIf_SignalGroupEventFlag[TxSignalGroupId] = FALSE;
        }
#  endif
      }
      else
      {
        retVal = COM_SERVICE_NOT_AVAILABLE;
      }
    }
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
  }
#  if (COM_RXSIGNAL_WRACCESS == STD_ON)
  else
  {
    /* for rx signals the data must be updated only */
    Com_LMgt_CheckDetErrorReturnValue((ComPduId < Com_RxBuffer_GetRxIpduCnt()), COMServiceId_Il_AsrComInternal,
                                      Com_SendSignalGroup_PduId, COM_SERVICE_NOT_AVAILABLE);

    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
    Com_RxBuffer_WriteSignalGroup(SignalGroupId, ShadowBufferPtr);

    if (!Com_LMgt_RxIpduActive(ComPduId))
    {
      retVal = COM_SERVICE_NOT_AVAILABLE;
    }
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
  }
#  endif /* (COM_RXSIGNAL_WRACCESS == STD_ON) */

  return retVal;

}                               /* End of Com_TxSigIf_SendSignalGroup() */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */

# if (COM_SIGNALGROUPIF == STD_ON)
#  if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
COM_STATIC FUNC(void, COM_CODE) Com_TxSigIf_UpdateShadowSignal(Com_SignalIdType SignalId,
                                                               P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
                                                               P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) ShadowBufferPtr)
{
#   if (COM_RXSIGNAL_WRACCESS == STD_ON)
  if (SignalId >= Com_Signal_GetRxSignalCnt())
#   else
  Com_LMgt_CheckFatalErrorRetVoid((SignalId >= Com_Signal_GetRxSignalCnt()), Com_TxSigIf_Init_SignalGroupIndex);
#   endif/* (COM_RXSIGNAL_WRACCESS == STD_ON) */
  {
    /* only for tx shadow signals */
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF) || (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))
    boolean WriteData = TRUE;
#   endif
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
    Com_Signal_FilterHdlType ComSigFilter = Com_Signal_GetSignalAttribute(SignalId, FilterHdl);
#   endif
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || ((COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) && ((COM_TMS_SUPPORT == STD_OFF) || (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))))
    boolean FilterState = TRUE;
#   endif
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON))
    Com_SignalIdType TxSignalId = (SignalId - Com_Signal_GetRxSignalCnt());
#   endif

#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
#    if (COM_F_NONE == STD_ON)
    if (COM_SIGNAL_F_NONE != ComSigFilter)
#    endif
    {
#    if ((COM_TXMODEHDLR_TMS == STD_ON) || ((COM_TMS_SUPPORT == STD_OFF) && (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)))
      FilterState = Com_Signal_ApplyFilter(SignalId, SignalDataPtr, ComSigFilter, ShadowBufferPtr, &WriteData);
#    else
      (void) Com_Signal_ApplyFilter(SignalId, SignalDataPtr, ComSigFilter, ShadowBufferPtr, &WriteData);
#    endif
#    if (COM_TXMODEHDLR_TMS == STD_ON)
      {
        uint16 FilterStateOffset = Com_ConfigValue(Com_TxSigIf_SignalFilterStateOffset)[TxSignalId];
        uint8 FilterStateMask = Com_ConfigValue(Com_TxSigIf_SignalFilterStateMask)[TxSignalId];
        /* set or reset the filter bit */
        if (TRUE == FilterState)
        {
          com_Buffer[FilterStateOffset] |= FilterStateMask;
        }
        else
        {
          com_Buffer[FilterStateOffset] &= COM_CAST2UINT8(~FilterStateMask);
        }
      }
#    endif
    }
#   endif/* ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */
#   if ((COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))
    if (COM_TX_SIGIF_TRIGGERED_ON_CHANGE == Com_ConfigValue(Com_TxSigIf_SignalTransferEventProperty)[TxSignalId])
    {
      FilterState =
        Com_Signal_ApplyFilter(SignalId, SignalDataPtr, COM_SIGNAL_F_NEWISDIFFERENT, ShadowBufferPtr, &WriteData);
    }
#   endif
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF) || (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))
    if (TRUE == WriteData)
#   endif
    {
      Com_Buffer_WriteShadowSignal(SignalId, SignalDataPtr, ShadowBufferPtr);
    }

#   if (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)
    {
      PduIdType ComPduId = Com_Signal_GetIpduFromSignal(SignalId);
      Com_LMgt_CheckFatalErrorRetVoid((ComPduId < Com_TxBuffer_GetTxIpduCnt()), Com_UpdateShadowSignal_PduId);

      if (Com_LMgt_TxIpduActive(ComPduId))
      {
#    if (COM_TMS_SUPPORT == STD_OFF)
        if (TRUE == FilterState)
#    endif
        {
          Com_SignalGroupIdType SignalGroupId = Com_Signal_GetSignalGroupFromSignal(SignalId);
          Com_LMgt_CheckFatalErrorRetVoid((SignalGroupId < Com_Signal_GetSignalGroupCnt()),
                                          Com_TxSigIf_Init_SignalGroupIndex);
          Com_LMgt_CheckFatalErrorRetVoid((SignalGroupId >= Com_Signal_GetRxSignalGroupCnt()),
                                          Com_TxSigIf_Init_SignalGroupIndex);

          if (COM_TX_SIGIF_TRIGGERED == Com_ConfigValue(Com_TxSigIf_SignalTransferEventProperty)[TxSignalId])
          {
            com_TxSigIf_SignalGroupEventFlag[SignalGroupId - Com_Signal_GetRxSignalGroupCnt()] = TRUE;
          }
#    if (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)
          else if (COM_TX_SIGIF_TRIGGERED_ON_CHANGE ==
                   Com_ConfigValue(Com_TxSigIf_SignalTransferEventProperty)[TxSignalId])
          {
            if (TRUE == FilterState)
            {
              com_TxSigIf_SignalGroupEventFlag[SignalGroupId - Com_Signal_GetRxSignalGroupCnt()] = TRUE;
            }
          }
#    endif/* (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON) */
          else
          {
            /* Signal group has PENDING transfer property */
          }
        }
      }
    }
#   endif/* (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) */
  }
#   if (COM_RXSIGNAL_WRACCESS == STD_ON)
  else
  {
    /* for rx shadow signals only the data must be updated */
    Com_Buffer_WriteShadowSignal(SignalId, SignalDataPtr, ShadowBufferPtr);
  }
#   endif/* (COM_RXSIGNAL_WRACCESS == STD_ON) */

}                               /* End of Com_TxSigIf_UpdateShadowSignal() */
#  endif /* ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */
#endif /* COM_TXSIGIF == STD_ON */
/* KB end Com_TxSigIf_GlobalIl_AsrComFunctions */
/* KB begin Com_SignalGw_GlobalIl_AsrComFunctions */
/* KB end Com_SignalGw_GlobalIl_AsrComFunctions */

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/* KB begin Com_LMgt_GlobalFunctions */
FUNC(void, COM_CODE) Com_Init(P2CONST(Com_ConfigType, AUTOMATIC, COM_PBCFG) config)
{
  sint16_least ComPduId;
#if (COM_CONFIG_VARIANT == 3)
  com_ConfigStructPtr = config;
#else
# if (COM_USE_DUMMY_STATEMENT == STD_ON)
  config = config;
# endif
#endif

#if !defined(V_SUPPRESS_EXTENDED_VERSION_CHECK)
  /* The check tests if major and minor version of generator and library are valid */
  if (((Com_ConfigValue(Com_GeneratorVersion) & (uint32) 0x00FFFF00u) !=
       ((((uint32) IL_ASRCOM_GENTOOL_GENY_MAJOR_VERSION) << 16u) |
        (((uint32) IL_ASRCOM_GENTOOL_GENY_MINOR_VERSION) << 8u)))
# if defined ( IL_ASRCOM_GENTOOL_GENY_PATCH_VERSION )
#  if ( IL_ASRCOM_GENTOOL_GENY_PATCH_VERSION != 0)
      || ((Com_ConfigValue(Com_GeneratorVersion) & (uint32) 0x000000FFu) < IL_ASRCOM_GENTOOL_GENY_PATCH_VERSION)
#  endif
# endif
    )
  {
    EcuM_GeneratorCompatibilityError((uint16) COM_MODULE_ID, (uint8) 0u);
    return;
  }
# if (COM_SIGNALGW == STD_ON)
  if (((Com_ConfigValue(Com_GwGeneratorVersion) & (uint32) 0x00FFFF00u) !=
       ((((uint32) IL_ASRCOMGW_GENTOOL_GENY_MAJOR_VERSION) << 16u) |
        (((uint32) IL_ASRCOMGW_GENTOOL_GENY_MINOR_VERSION) << 8u)))
#  if defined ( IL_ASRCOM_GENTOOL_GENY_PATCH_VERSION )
#   if ( IL_ASRCOM_GENTOOL_GENY_PATCH_VERSION != 0)
      || ((Com_ConfigValue(Com_GwGeneratorVersion) & (uint32) 0x000000FFu) < IL_ASRCOMGW_GENTOOL_GENY_PATCH_VERSION)
#   endif
#  endif
    )
  {
    EcuM_GeneratorCompatibilityError((uint16) COM_MODULE_ID, (uint8) 0u);
    return;
  }
# endif
#endif

#if (COM_CRC_CHECK == STD_ON)
  if (Com_ConfigValue(Com_LMgt_PrecompileCRC) != COM_PRECOMPILE_CRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) COM_MODULE_ID, (uint8) 0u);
    return;
  }
  if (Com_ConfigValue(Com_LMgt_LinktimeCRC) != Com_LMgt_LinktimeCRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) COM_MODULE_ID, (uint8) 0u);
    return;
  }
#endif

  /* Start COM433 */
  Com_LMgt_CheckFatalErrorRetVoid((Com_ConfigValue(FinalMagicNumber) == (uint16) 0xC0DEu), COM_E_PARAM);
#if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
  Com_LMgt_CheckFatalErrorRetVoid((Com_Signal_GetSignalAttribute(Com_Signal_GetSignalCnt(), AccessAttributes) ==
                                   (uint16) 0xC0DEu), COM_E_PARAM);
#endif
  /* Stop COM433 */
#if ( (COM_MAXRXIPDUCNT + COM_MAXTXIPDUCNT) > 255 )
  Com_LMgt_CheckFatalErrorRetVoid((sizeof(PduIdType) > 1), Com_LMgt_PduIdTypeTooSmall);
#endif
#if (COM_APPLTYPE_BOOLEAN == STD_ON)
  Com_LMgt_CheckFatalErrorRetVoid((sizeof(boolean) == 1), Com_LMgt_SizeOfBoolean);
#endif
#if ((COM_RXINV_INHIBITNOTIFUNC == STD_ON) || (COM_RXNHDLR_INHIBITNOTIFUNC == STD_ON))
  Com_LMgt_MemSet(com_RxNHdlr_InhibitNotification, (uint8) 0x00u, Com_RxNHdlr_GetNotificationCnt());
#endif
#if ((COM_RXINV_INHIBITINDFLAG == STD_ON) || (COM_RXNHDLR_INHIBITINDFLAG == STD_ON))
  Com_LMgt_MemSet(com_RxNHdlr_InhibitNotiFlag, (uint8) 0x00u, Com_RxNHdlr_GetNotificationFlagCnt());
#endif
#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
  Com_LMgt_MemSet(com_LMgt_IPduGroupState, FALSE, Com_LMgt_GetSubIPduGroupCnt());
# if ((COM_RXUBHDLR_TIMEOUT == STD_ON) || (COM_RXDLMON == STD_ON))
  Com_LMgt_MemSet(com_LMgt_DmGroupState, FALSE, Com_LMgt_GetSubIPduGroupCnt());
# endif
#endif
#if (COM_TSI_TESTCODE == STD_ON)
/* ##V_TEST_CODE_START ##visdbi */
  Com_TxLLIf_InhibitTxConfirmation(COM_PDUID_MAXVAL);
  /* ##V_TEST_CODE_END ##visdbi */
#endif /* (COM_TSI_TESTCODE == STD_ON) */

#if (COM_LMGT_RX == STD_ON)
  for (ComPduId = (sint16_least) Com_RxBuffer_GetRxIpduCnt() - 1; ComPduId >= 0; ComPduId--)
  {
    Com_LMgt_InitRxIpdu((PduIdType) ComPduId);
    /* KB begin Com_LMgt_InitRxIpdus */
# if ((COM_RXUBHDLR_TIMEOUT == STD_ON) || (COM_RXDLMON == STD_ON))
    com_LMgt_RxDmState[(PduIdType) ComPduId] = FALSE;
# endif
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
    com_LMgt_RxPduGroupState[(PduIdType) ComPduId] = (uint8) 0x00;
# else
    com_LMgt_RxPduGroupState[(PduIdType) ComPduId] = FALSE;
# endif
    /* KB end Com_LMgt_InitRxIpdus */
  }
#endif /* COM_LMGT_RX == STD_ON */
#if (COM_LMGT_TX == STD_ON)
  for (ComPduId = (sint16_least) Com_TxBuffer_GetTxIpduCnt() - 1; ComPduId >= 0; ComPduId--)
  {
    Com_LMgt_InitTxIpdu((PduIdType) ComPduId);
    /* KB begin Com_LMgt_InitTxIpdus */
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
    com_LMgt_TxPduGroupState[(PduIdType) ComPduId] = (uint8) 0x00;
# else
    com_LMgt_TxPduGroupState[(PduIdType) ComPduId] = FALSE;
# endif
    /* KB end Com_LMgt_InitTxIpdus */
  }
#endif /* COM_LMGT_TX == STD_ON */

  /* Com must be enabled after all subcomponents are initialised */
  com_LMgt_Status = COM_INIT;
}                               /* End of Com_Init() */

FUNC(void, COM_CODE) Com_InitMemory(void)
{
  com_LMgt_Status = COM_UNINIT;

}                               /* End of Com_MemoryInit() */

#if (COM_DE_INIT_API == STD_ON )
FUNC(void, COM_CODE) Com_DeInit(void)
{
  sint16_least ComPduId;


  Com_LMgt_CheckDetErrorReturnVoid((com_LMgt_Status == COM_INIT), COMServiceId_DeInit, COM_E_UNINIT);
  com_LMgt_Status = COM_UNINIT;

# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
  Com_LMgt_MemSet(com_LMgt_IPduGroupState, FALSE, Com_LMgt_GetSubIPduGroupCnt());
#  if ((COM_RXUBHDLR_TIMEOUT == STD_ON) || (COM_RXDLMON == STD_ON))
  Com_LMgt_MemSet(com_LMgt_DmGroupState, FALSE, Com_LMgt_GetSubIPduGroupCnt());
#  endif
# endif

# if (COM_LMGT_RX == STD_ON)
  for (ComPduId = (sint16_least) Com_RxBuffer_GetRxIpduCnt() - 1; ComPduId >= 0; ComPduId--)
  {
    Com_LMgt_InitRxIpdu((PduIdType) ComPduId);
    /* KB begin Com_LMgt_InitRxIpdus */
#  if ((COM_RXUBHDLR_TIMEOUT == STD_ON) || (COM_RXDLMON == STD_ON))
    com_LMgt_RxDmState[(PduIdType) ComPduId] = FALSE;
#  endif
#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
    com_LMgt_RxPduGroupState[(PduIdType) ComPduId] = (uint8) 0x00;
#  else
    com_LMgt_RxPduGroupState[(PduIdType) ComPduId] = FALSE;
#  endif
    /* KB end Com_LMgt_InitRxIpdus */
    /* KB begin Com_Signal_StopRxIpdus */
    /* KB end Com_Signal_StopRxIpdus */
    /* KB begin Com_Buffer_StopRxIpdus */
    /* KB end Com_Buffer_StopRxIpdus */
    /* KB begin Com_RxBuffer_StopRxIpdus */
    /* KB end Com_RxBuffer_StopRxIpdus */
    /* KB begin Com_RxDlMon_StopRxIpdus */
    /* KB end Com_RxDlMon_StopRxIpdus */
    /* KB begin Com_RxLLIf_StopRxIpdus */
    /* KB end Com_RxLLIf_StopRxIpdus */
    /* KB begin Com_RxNHdlr_StopRxIpdus */
#  if (COM_RXNHDLR == STD_ON) && (COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
    com_RxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = 0;
#   else
    com_RxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = FALSE;
#   endif
        /* (COM_DYNAMIC_DLC_SUPPORT == STD_ON) */
#  endif
    /* KB end Com_RxNHdlr_StopRxIpdus */
    /* KB begin Com_RxSigIf_StopRxIpdus */
    /* KB end Com_RxSigIf_StopRxIpdus */
    /* KB begin Com_RxUbHdlr_StopRxIpdus */
#  if (COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
    {
      uint16_least ubId;
      for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
           ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) (ComPduId + 1)]; ubId++)
      {
        Com_LMgt_CheckFatalErrorRetVoid((ubId < Com_RxUbHdlr_GetUpdateBitCnt()), Com_RxUbHdlr_InvalidUbHdl);
        com_RxUbHdlr_HandleUbDeferred[ubId] = FALSE;
      }
    }
#  endif
    /* KB end Com_RxUbHdlr_StopRxIpdus */
    /* KB begin Com_RxInv_StopRxIpdus */
    /* KB end Com_RxInv_StopRxIpdus */
    /* KB begin Com_TxInv_StopRxIpdus */
    /* KB end Com_TxInv_StopRxIpdus */
    /* KB begin Com_TxBuffer_StopRxIpdus */
    /* KB end Com_TxBuffer_StopRxIpdus */
    /* KB begin Com_TxDlMon_StopRxIpdus */
    /* KB end Com_TxDlMon_StopRxIpdus */
    /* KB begin Com_TxLLIf_StopRxIpdus */
    /* KB end Com_TxLLIf_StopRxIpdus */
    /* KB begin Com_TxModeHdlr_StopRxIpdus */
    /* KB end Com_TxModeHdlr_StopRxIpdus */
    /* KB begin Com_TxNHdlr_StopRxIpdus */
    /* KB end Com_TxNHdlr_StopRxIpdus */
    /* KB begin Com_TxSigIf_StopRxIpdus */
    /* KB end Com_TxSigIf_StopRxIpdus */
    /* KB begin Com_SignalGw_StopRxIpdus */
    /* KB end Com_SignalGw_StopRxIpdus */
  }
# endif /* COM_LMGT_RX == STD_ON */
# if (COM_LMGT_TX == STD_ON)
  for (ComPduId = (sint16_least) Com_TxBuffer_GetTxIpduCnt() - 1; ComPduId >= 0; ComPduId--)
  {
    Com_LMgt_InitTxIpdu((PduIdType) ComPduId);
    /* KB begin Com_LMgt_InitTxIpdus */
#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
    com_LMgt_TxPduGroupState[(PduIdType) ComPduId] = (uint8) 0x00;
#  else
    com_LMgt_TxPduGroupState[(PduIdType) ComPduId] = FALSE;
#  endif
    /* KB end Com_LMgt_InitTxIpdus */
    /* KB begin Com_Signal_StopTxIpdus */
    /* KB end Com_Signal_StopTxIpdus */
    /* KB begin Com_Buffer_StopTxIpdus */
    /* KB end Com_Buffer_StopTxIpdus */
    /* KB begin Com_RxBuffer_StopTxIpdus */
    /* KB end Com_RxBuffer_StopTxIpdus */
    /* KB begin Com_RxDlMon_StopTxIpdus */
    /* KB end Com_RxDlMon_StopTxIpdus */
    /* KB begin Com_RxLLIf_StopTxIpdus */
    /* KB end Com_RxLLIf_StopTxIpdus */
    /* KB begin Com_RxNHdlr_StopTxIpdus */
    /* KB end Com_RxNHdlr_StopTxIpdus */
    /* KB begin Com_RxSigIf_StopTxIpdus */
    /* KB end Com_RxSigIf_StopTxIpdus */
    /* KB begin Com_RxUbHdlr_StopTxIpdus */
    /* KB end Com_RxUbHdlr_StopTxIpdus */
    /* KB begin Com_RxInv_StopTxIpdus */
    /* KB end Com_RxInv_StopTxIpdus */
    /* KB begin Com_TxInv_StopTxIpdus */
    /* KB end Com_TxInv_StopTxIpdus */
    /* KB begin Com_TxBuffer_StopTxIpdus */
    /* KB end Com_TxBuffer_StopTxIpdus */
    /* KB begin Com_TxDlMon_StopTxIpdus */
#  if (COM_TXDLMON == STD_ON)
    Com_TxDlMon_Stop((PduIdType) ComPduId);
#  endif
    /* KB end Com_TxDlMon_StopTxIpdus */
    /* KB begin Com_TxLLIf_StopTxIpdus */
    /* KB end Com_TxLLIf_StopTxIpdus */
    /* KB begin Com_TxModeHdlr_StopTxIpdus */
#  if (COM_TXMODEHDLR == STD_ON)
    Com_TxModeHdlr_Stop((PduIdType) ComPduId);
#  endif
    /* KB end Com_TxModeHdlr_StopTxIpdus */
    /* KB begin Com_TxNHdlr_StopTxIpdus */
#  if (COM_TXNHDLR == STD_ON)
#   if (COM_TXERRORNOTIFICATION == STD_ON)
    if (TRUE == com_TxNHdlr_WaitingForConfirmation[(PduIdType) ComPduId])
    {
      uint16_least notiIndex = Com_ConfigValue(Com_TxNHdlr_Ipdu2ErrorFunctions)[(PduIdType) ComPduId];
      for (; notiIndex < Com_ConfigValue(Com_TxNHdlr_Ipdu2ErrorFunctions)[((PduIdType) ComPduId) + 1]; notiIndex++)
      {
        Com_TxNHdlr_ErrorNotiFuncPtr[Com_ConfigValue(Com_TxNHdlr_ErrorNotiFuncIndirection)[notiIndex]] ();
      }
      com_TxNHdlr_WaitingForConfirmation[(PduIdType) ComPduId] = FALSE;
    }
#   endif
#   if (COM_TXCONFIRMATION_DEFERRED == STD_ON)
    com_TxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = FALSE;
#   endif
#  endif
    /* KB end Com_TxNHdlr_StopTxIpdus */
    /* KB begin Com_TxSigIf_StopTxIpdus */
    /* KB end Com_TxSigIf_StopTxIpdus */
    /* KB begin Com_SignalGw_StopTxIpdus */
    /* KB end Com_SignalGw_StopTxIpdus */
  }
# endif /* COM_LMGT_TX == STD_ON */
}                               /* End of Com_DeInit() */
#endif /* COM_DE_INIT_API == STD_ON */

#if (COM_RECEPTION_DM_API == STD_ON )
FUNC(void, COM_CODE) Com_EnableReceptionDM(Com_PduGroupIdType IpduGroupId)
{
# if ((COM_LMGT_RX == STD_ON) && ((COM_RXDLMON == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON)))
  Com_LMgt_CheckDetErrorReturnVoid((com_LMgt_Status == COM_INIT), COMServiceId_EnableReceptionDM, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((IpduGroupId < Com_LMgt_GetIPduGroupCnt()), COMServiceId_EnableReceptionDM,
                                   COM_E_PARAM);

#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#   if (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)
  {
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId];
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupStopIdx =
      Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId + 1];
    for (; SubIPduGroupIdx < SubIPduGroupStopIdx; SubIPduGroupIdx++)
    {
      IpduGroupId = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroupsIndirection)[SubIPduGroupIdx];
      Com_LMgt_CheckFatalErrorBreak((IpduGroupId < Com_LMgt_GetSubIPduGroupCnt()), Com_LMgt_SubIpduGroupId);
#   endif /* (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON) */
      SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
      if (!Com_LMgt_DmGroupActive(IpduGroupId))
      {
        Com_LMgt_ActivateDmGroup(IpduGroupId);
#  endif /* (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) */
        {
          Com_LMgt_IPduGroup2IPdusType IPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId];
          Com_LMgt_IPduGroup2IPdusType IPduGroupStopIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId + 1];
          for (; IPduGroupIdx < IPduGroupStopIdx; IPduGroupIdx++)
          {
            PduIdType ComPduId = Com_ConfigValue(Com_LMgt_IPduGroup2IPdusIndirection)[IPduGroupIdx];

            if (ComPduId < Com_RxBuffer_GetRxIpduCnt())
            {
              if (!Com_LMgt_RxIpduDmActive(ComPduId))   /* COM224 */
              {
                /* KB begin Com_RxDlMon_InitRxIpdus */
#  if (COM_RXDLMON == STD_ON)
                Com_RxDlMon_InitTimeout((PduIdType) ComPduId);
#  endif
                /* KB end Com_RxDlMon_InitRxIpdus */
                /* KB begin Com_RxUbHdlr_ResetDm */
#  if (COM_RXUBHDLR_TIMEOUT == STD_ON)
                {
                  uint16_least ubId;
                  for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
                       ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) (ComPduId + 1)]; ubId++)
                  {
                    Com_LMgt_CheckFatalErrorRetVoid((ubId < Com_RxUbHdlr_GetUpdateBitCnt()), Com_RxUbHdlr_InvalidUbHdl);
#   if (COM_RXUBHDLR_TIMEOUT == STD_ON)
#    if (COM_RXUBHDLR_FIRSTTIMEOUT == STD_ON)
                    com_RxUbHdlr_TimeoutCnt[ubId] = Com_ConfigValue(Com_RxUbHdlr_FirstTimeoutTime)[ubId];
#    else
                    com_RxUbHdlr_TimeoutCnt[ubId] = Com_ConfigValue(Com_RxUbHdlr_TimeoutTime)[ubId];
#    endif
#   endif
                  }
                }
#  endif/* (COM_RXUBHDLR_TIMEOUT == STD_ON) */
                /* KB end Com_RxUbHdlr_ResetDm */
                /* KB begin Com_RxNHdlr_ClrRxTimeoutFlag */
#  if (COM_RXNHDLR_TIMEOUTFLAG == STD_ON)
                {
                  uint16_least timeoutFlagIndex;
                  for (timeoutFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) ComPduId];
                       timeoutFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) (ComPduId + 1)];
                       timeoutFlagIndex++)
                  {
                    Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
                    Com_LMgt_CheckFatalErrorRetVoid((timeoutFlagIndex < Com_RxNHdlr_TimeoutFlagCnt),
                                                    Com_RxNHdlr_TimeoutFlagIdxTooLarge);
                    timeoutFlagInfoPtr =
                      &Com_RxNHdlr_TimeoutFlagInfo[Com_ConfigValue(Com_RxNHdlr_TimeoutFlagIndirection)
                                                   [timeoutFlagIndex]];
                    com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
                      COM_CAST2UINT8(~timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
                  }
                }
#  endif  /* (COM_RXNHDLR_TIMEOUTFLAG == STD_ON) */
                /* KB end Com_RxNHdlr_ClrRxTimeoutFlag */
                /* KB begin Com_RxUbHdlr_ClrAllRxTimeoutFlags */
#  if (COM_RXUBHDLR_TIMEOUTFLAG == STD_ON)
                {
                  uint16_least ubId;
                  for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
                       ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) (ComPduId + 1)]; ubId++)
                  {
                    /* KB begin Com_RxUbHdlr_ClrRxTimeoutFlag */
#   if (COM_RXUBHDLR_TIMEOUTFLAG == STD_ON)
                    {
                      Com_RxNHdlr_TimeoutFlagIdType timeoutFlagIdx = Com_ConfigValue(Com_RxUbHdlr_TimeoutFlagHdl)[ubId];

                      if (COM_RX_NHDLR_NOTIMEOUTFLAG != timeoutFlagIdx)
                      {
                        Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
                        Com_LMgt_CheckFatalErrorBreak((timeoutFlagIdx < Com_RxNHdlr_TimeoutFlagCnt),
                                                      Com_RxUbHdlr_TimeoutFlagIdxTooLarge);
                        timeoutFlagInfoPtr = &Com_RxNHdlr_TimeoutFlagInfo[timeoutFlagIdx];
                        com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
                          COM_CAST2UINT8(~timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
                      }
                    }
#   endif
                    /* KB end Com_RxUbHdlr_ClrRxTimeoutFlag */
                  }
                }
#  endif
                /* KB end Com_RxUbHdlr_ClrAllRxTimeoutFlags */
              }
              Com_LMgt_ActivateRxIpduDm(ComPduId);
            }
          }
        }
#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
      }
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
#   if (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)
    }
  }
#   endif
#  endif
# else
#  if (COM_USE_DUMMY_STATEMENT == STD_ON)
  IpduGroupId = IpduGroupId;
#  endif
# endif
}                               /* End of Com_EnableReceptionDM() */

FUNC(void, COM_CODE) Com_DisableReceptionDM(Com_PduGroupIdType IpduGroupId)
{
# if ((COM_LMGT_RX == STD_ON) && ((COM_RXDLMON == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON)))
  Com_LMgt_CheckDetErrorReturnVoid((com_LMgt_Status == COM_INIT), COMServiceId_DisableReceptionDM, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((IpduGroupId < Com_LMgt_GetIPduGroupCnt()), COMServiceId_DisableReceptionDM,
                                   COM_E_PARAM);

#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
#   if (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)
  {
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId];
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupStopIdx =
      Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId + 1];
    for (; SubIPduGroupIdx < SubIPduGroupStopIdx; SubIPduGroupIdx++)
    {
      IpduGroupId = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroupsIndirection)[SubIPduGroupIdx];
      Com_LMgt_CheckFatalErrorBreak((IpduGroupId < Com_LMgt_GetSubIPduGroupCnt()), Com_LMgt_SubIpduGroupId);
#   endif /* (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON) */
      SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
      if (Com_LMgt_DmGroupActive(IpduGroupId))
      {
        Com_LMgt_DeactivateDmGroup(IpduGroupId);
#  endif /* (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) */
        {
          Com_LMgt_IPduGroup2IPdusType IPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId];
          Com_LMgt_IPduGroup2IPdusType IPduGroupStopIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId + 1];
          for (; IPduGroupIdx < IPduGroupStopIdx; IPduGroupIdx++)
          {
            PduIdType ComPduId = Com_ConfigValue(Com_LMgt_IPduGroup2IPdusIndirection)[IPduGroupIdx];

            if (ComPduId < Com_RxBuffer_GetRxIpduCnt())
            {
              if (Com_LMgt_RxIpduDmActive(ComPduId))    /* COM225 */
              {
                Com_LMgt_DeactivateRxIpduDm(ComPduId);
              }
            }
          }
        }
#  if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
      }
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
#   if (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)
    }
  }
#   endif
#  endif
# else
#  if (COM_USE_DUMMY_STATEMENT == STD_ON)
  IpduGroupId = IpduGroupId;
#  endif
# endif
}                               /* End of Com_DisableReceptionDM() */
#endif /* COM_RECEPTION_DM_API */


FUNC(void, COM_CODE) Com_IpduGroupStart(Com_PduGroupIdType IpduGroupId, boolean Initialize)
{
  Com_LMgt_CheckDetErrorReturnVoid((com_LMgt_Status == COM_INIT), COMServiceId_IpduGroupStart, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((IpduGroupId < Com_LMgt_GetIPduGroupCnt()), COMServiceId_IpduGroupStart,
                                   COM_E_PARAM);

#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
# if (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)
  {
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId];
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupStopIdx =
      Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId + 1];
    for (; SubIPduGroupIdx < SubIPduGroupStopIdx; SubIPduGroupIdx++)
    {
      IpduGroupId = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroupsIndirection)[SubIPduGroupIdx];
      Com_LMgt_CheckFatalErrorBreak((IpduGroupId < Com_LMgt_GetSubIPduGroupCnt()), Com_LMgt_SubIpduGroupId);
# endif /* (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON) */
      SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
      if (!Com_LMgt_IPduGroupActive(IpduGroupId))
      {
# if ((COM_RXDLMON == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON))
        boolean bActivateDm = FALSE;
        if (!Com_LMgt_DmGroupActive(IpduGroupId))
        {
          Com_LMgt_ActivateDmGroup(IpduGroupId);
          bActivateDm = TRUE;
        }
# endif
        Com_LMgt_ActivateIPduGroup(IpduGroupId);
#endif /* (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) */
        {
          Com_LMgt_IPduGroup2IPdusType IPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId];
          Com_LMgt_IPduGroup2IPdusType IPduGroupStopIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId + 1];
          for (; IPduGroupIdx < IPduGroupStopIdx; IPduGroupIdx++)
          {
            PduIdType ComPduId = Com_ConfigValue(Com_LMgt_IPduGroup2IPdusIndirection)[IPduGroupIdx];

            if (ComPduId < Com_RxBuffer_GetRxIpduCnt())
            {
              if (!Com_LMgt_RxIpduActive(ComPduId))     /* COM476 */
              {
                if (Initialize == TRUE)
                {
                  Com_LMgt_InitRxIpdu(ComPduId);
                }
              }
              Com_LMgt_ActivateRxIpdu(ComPduId);
#if ((COM_RXDLMON == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON))
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
              if (bActivateDm)
# endif
              {
                Com_LMgt_ActivateRxIpduDm(ComPduId);
              }
#endif  /* ((COM_RXDLMON == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON)) */
            }
            else
            {
              ComPduId = ComPduId - Com_RxBuffer_GetRxIpduCnt();
              Com_LMgt_CheckFatalErrorBreak((ComPduId < Com_TxBuffer_GetTxIpduCnt()), Com_LMgt_IpduId);

              if (!Com_LMgt_TxIpduActive(ComPduId))     /* COM476 */
              {
                if (Initialize == TRUE)
                {
                  Com_LMgt_InitTxIpdu(ComPduId);
#if (COM_SIGNALGW_CANMOST == STD_ON)
                  Com_TxModeHdlr_StopCyclicTransmission(ComPduId);
#endif
                }
#if (COM_TXDLMON == STD_ON)
                Com_TxDlMon_IPduGroupStart(ComPduId);
#endif
              }
              Com_LMgt_ActivateTxIpdu(ComPduId);
            }
          }
        }
#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
      }
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
# if (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)
    }
  }
# endif
#endif
}                               /* End of Com_IpduGroupStart() */

FUNC(void, COM_CODE) Com_IpduGroupStop(Com_PduGroupIdType IpduGroupId)
{
  Com_LMgt_CheckDetErrorReturnVoid((com_LMgt_Status == COM_INIT), COMServiceId_IpduGroupStop, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((IpduGroupId < Com_LMgt_GetIPduGroupCnt()), COMServiceId_IpduGroupStop, COM_E_PARAM);

#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
# if (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)
  {
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId];
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupStopIdx =
      Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId + 1];
    for (; SubIPduGroupIdx < SubIPduGroupStopIdx; SubIPduGroupIdx++)
    {
      IpduGroupId = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroupsIndirection)[SubIPduGroupIdx];
      Com_LMgt_CheckFatalErrorBreak((IpduGroupId < Com_LMgt_GetSubIPduGroupCnt()), Com_LMgt_SubIpduGroupId);
# endif /* (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON) */
      SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
      if (Com_LMgt_IPduGroupActive(IpduGroupId))
      {
# if ((COM_RXDLMON == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON))
        boolean bDeactivateDm = FALSE;
        if (Com_LMgt_DmGroupActive(IpduGroupId))
        {
          Com_LMgt_DeactivateDmGroup(IpduGroupId);
          bDeactivateDm = TRUE;
        }
# endif
        Com_LMgt_DeactivateIPduGroup(IpduGroupId);
#endif /* (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) */
        {
          Com_LMgt_IPduGroup2IPdusType IPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId];
          Com_LMgt_IPduGroup2IPdusType IPduGroupStopIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId + 1];
          for (; IPduGroupIdx < IPduGroupStopIdx; IPduGroupIdx++)
          {
            PduIdType ComPduId = Com_ConfigValue(Com_LMgt_IPduGroup2IPdusIndirection)[IPduGroupIdx];

            if (ComPduId < Com_RxBuffer_GetRxIpduCnt())
            {
              if (Com_LMgt_RxIpduActive(ComPduId))      /* COM461 */
              {
                Com_LMgt_DeactivateRxIpdu(ComPduId);
#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
                if (!Com_LMgt_RxIpduActive(ComPduId))
#endif
                {
                  /* KB begin Com_RxNHdlr_StopRxIpdus */
#if (COM_RXNHDLR == STD_ON) && (COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
                  com_RxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = 0;
# else
                  com_RxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = FALSE;
# endif /* (COM_DYNAMIC_DLC_SUPPORT == STD_ON) */
#endif
                  /* KB end Com_RxNHdlr_StopRxIpdus */
                  /* KB begin Com_RxUbHdlr_StopRxIpdus */
#if (COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
                  {
                    uint16_least ubId;
                    for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
                         ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) (ComPduId + 1)]; ubId++)
                    {
                      Com_LMgt_CheckFatalErrorRetVoid((ubId < Com_RxUbHdlr_GetUpdateBitCnt()),
                                                      Com_RxUbHdlr_InvalidUbHdl);
                      com_RxUbHdlr_HandleUbDeferred[ubId] = FALSE;
                    }
                  }
#endif
                  /* KB end Com_RxUbHdlr_StopRxIpdus */
                }
              }
#if ((COM_RXDLMON == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON))
# if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
              if (bDeactivateDm && Com_LMgt_RxIpduDmActive(ComPduId))
# endif
              {
                Com_LMgt_DeactivateRxIpduDm(ComPduId);
              }
#endif  /* ((COM_RXDLMON == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON)) */
            }
            else
            {
              ComPduId = ComPduId - Com_RxBuffer_GetRxIpduCnt();
              Com_LMgt_CheckFatalErrorBreak((ComPduId < Com_TxBuffer_GetTxIpduCnt()), Com_LMgt_IpduId);

              if (Com_LMgt_TxIpduActive(ComPduId))      /* COM461 */
              {
                Com_LMgt_DeactivateTxIpdu(ComPduId);
#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
                if (!Com_LMgt_TxIpduActive(ComPduId))
#endif
                {
                  /* KB begin Com_TxModeHdlr_StopTxIpdus */
#if (COM_TXMODEHDLR == STD_ON)
                  Com_TxModeHdlr_Stop((PduIdType) ComPduId);
#endif
                  /* KB end Com_TxModeHdlr_StopTxIpdus */
                  /* KB begin Com_TxDlMon_StopTxIpdus */
#if (COM_TXDLMON == STD_ON)
                  Com_TxDlMon_Stop((PduIdType) ComPduId);
#endif
                  /* KB end Com_TxDlMon_StopTxIpdus */
                  /* KB begin Com_TxNHdlr_StopTxIpdus */
#if (COM_TXNHDLR == STD_ON)
# if (COM_TXERRORNOTIFICATION == STD_ON)
                  if (TRUE == com_TxNHdlr_WaitingForConfirmation[(PduIdType) ComPduId])
                  {
                    uint16_least notiIndex = Com_ConfigValue(Com_TxNHdlr_Ipdu2ErrorFunctions)[(PduIdType) ComPduId];
                    for (; notiIndex < Com_ConfigValue(Com_TxNHdlr_Ipdu2ErrorFunctions)[((PduIdType) ComPduId) + 1];
                         notiIndex++)
                    {
                      Com_TxNHdlr_ErrorNotiFuncPtr[Com_ConfigValue(Com_TxNHdlr_ErrorNotiFuncIndirection)[notiIndex]] ();
                    }
                    com_TxNHdlr_WaitingForConfirmation[(PduIdType) ComPduId] = FALSE;
                  }
# endif
# if (COM_TXCONFIRMATION_DEFERRED == STD_ON)
                  com_TxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] = FALSE;
# endif
#endif
                  /* KB end Com_TxNHdlr_StopTxIpdus */
                }
              }
            }
          }
        }
#if (COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON)
      }
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
# if (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)
    }
  }
# endif
#endif
}                               /* End of Com_IpduGroupStop() */

#if (COM_IPDU_GROUP_TRANSMIT_API == STD_ON )
FUNC(void, COM_CODE) Com_IpduGroupTransmit(Com_PduGroupIdType IpduGroupId)
{
# if ((COM_LMGT_TX == STD_ON) && (COM_TXMODEHDLR == STD_ON))
  Com_LMgt_CheckDetErrorReturnVoid((com_LMgt_Status == COM_INIT), COMServiceId_IpduGroupTransmit, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((IpduGroupId < Com_LMgt_GetIPduGroupCnt()), COMServiceId_IpduGroupTransmit,
                                   COM_E_PARAM);

#  if ((COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) && (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON))
  {
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId];
    Com_LMgt_IPduGroup2SubGroupsType SubIPduGroupStopIdx =
      Com_ConfigValue(Com_LMgt_IPduGroup2SubGroups)[IpduGroupId + 1];
    for (; SubIPduGroupIdx < SubIPduGroupStopIdx; SubIPduGroupIdx++)
    {
      IpduGroupId = Com_ConfigValue(Com_LMgt_IPduGroup2SubGroupsIndirection)[SubIPduGroupIdx];
      Com_LMgt_CheckFatalErrorBreak((IpduGroupId < Com_LMgt_GetSubIPduGroupCnt()), Com_LMgt_SubIpduGroupId);
#  endif /* ((COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) && (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON)) */
      {
        Com_LMgt_IPduGroup2IPdusType IPduGroupIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId];
        Com_LMgt_IPduGroup2IPdusType IPduGroupStopIdx = Com_ConfigValue(Com_LMgt_IPduGroup2IPdus)[IpduGroupId + 1];
        for (; IPduGroupIdx < IPduGroupStopIdx; IPduGroupIdx++)
        {
          PduIdType ComPduId = Com_ConfigValue(Com_LMgt_IPduGroup2IPdusIndirection)[IPduGroupIdx];

          if (ComPduId >= Com_RxBuffer_GetRxIpduCnt())
          {
            ComPduId = ComPduId - Com_RxBuffer_GetRxIpduCnt();

            Com_LMgt_CheckDetErrorContinue(Com_LMgt_TxIpduActive(ComPduId), COMServiceId_IpduGroupTransmit,
                                           Com_IpduGroupTransmit_IpduGroupStopped);
            Com_TxModeHdlr_TriggerIpduSendOnceDeferred(ComPduId);
          }
        }
      }
#  if ((COM_LMGT_MULTIPLEIPDUGROUPREF == STD_ON) && (COM_LMGT_IPDUGROUPHIERARCHY == STD_ON))
    }
  }
#  endif
# endif /* ((COM_LMGT_TX == STD_ON) && (COM_TXMODEHDLR == STD_ON)) */
}                               /* End of Com_IpduGroupTransmit() */
#endif

#if (COM_MAIN_FUNCTION_RX_API == STD_ON )
FUNC(void, COM_CODE) Com_MainFunctionRx(void)   /* COM398 */
{
# if (COM_LMGT_RX == STD_ON)
  if (com_LMgt_Status == COM_INIT)
  {
    /* KB begin Com_LMgt_MainFunctionRx */
    /* KB end Com_LMgt_MainFunctionRx */
    /* KB begin Com_Signal_MainFunctionRx */
    /* KB end Com_Signal_MainFunctionRx */
    /* KB begin Com_Buffer_MainFunctionRx */
    /* KB end Com_Buffer_MainFunctionRx */
    /* KB begin Com_RxBuffer_MainFunctionRx */
    /* KB end Com_RxBuffer_MainFunctionRx */
    /* KB begin Com_RxDlMon_MainFunctionRx */
#  if (COM_RXDLMON == STD_ON)
    {
      sint16_least ComRxPduId;

      SchM_Enter_Com(COM_EXCLUSIVE_AREA_3);
      for (ComRxPduId = (sint16_least) Com_RxBuffer_GetRxIpduCnt() - 1; ComRxPduId >= 0; ComRxPduId--)
      {
        if (Com_ConfigValue(Com_RxDlMon_TimeoutTime)[ComRxPduId] != 0)
        {
          if (Com_LMgt_RxIpduDmActive((PduIdType) ComRxPduId))
          {
            SchM_Enter_Com(COM_EXCLUSIVE_AREA_4);
            if (0 < com_RxDlMon_TimeoutCnt[ComRxPduId])
            {
              com_RxDlMon_TimeoutCnt[ComRxPduId]--;
              SchM_Exit_Com(COM_EXCLUSIVE_AREA_4);
            }
            else
            {
              com_RxDlMon_TimeoutCnt[ComRxPduId] = Com_ConfigValue(Com_RxDlMon_TimeoutTime)[ComRxPduId];
#   if (COM_RXDLMON_TIMEOUTDEFAULTVALUE == STD_ON)
              Com_RxBuffer_WriteIpduWithMask((PduIdType) ComRxPduId, Com_RxBuffer_GetIpduInitValPtr(ComRxPduId),
                                             Com_RxDlMon_GetIpduTimeoutMask(ComRxPduId));
#   endif
              SchM_Exit_Com(COM_EXCLUSIVE_AREA_4);
#   if ((COM_RXINV_NOTIINVFUNC_NOUB_TO == STD_ON) && (COM_RXINV_NOTIINVFUNC == STD_ON))
              Com_RxInv_NotiInvalidNoUb((PduIdType) ComRxPduId, TRUE);
#   endif
#   if ((COM_RXNHDLR_TIMEOUTFUNCTION == STD_ON) || (COM_RXNHDLR_TIMEOUTFLAG == STD_ON))
              Com_RxNHdlr_Timeout((PduIdType) ComRxPduId);
#   endif
#   if (COM_SIGNALGW_RXTIMEOUT == STD_ON)
              Com_SignalGw_RxIpduTimeout((PduIdType) ComRxPduId);
#   endif
            }
          }
        }
      }
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_3);
    }                           /* End of Com_RxDlMon_MainFunction() */
#  endif
    /* KB end Com_RxDlMon_MainFunctionRx */
    /* KB begin Com_RxLLIf_MainFunctionRx */
    /* KB end Com_RxLLIf_MainFunctionRx */
    /* KB begin Com_RxNHdlr_MainFunctionRx */
#  if (COM_RXNHDLR == STD_ON) && (COM_RXNHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
    {
      sint16_least ComPduId;

      for (ComPduId = (sint16_least) Com_RxBuffer_GetRxIpduCnt() - 1; ComPduId >= 0; ComPduId--)
      {
        if (Com_RxNHdlr_HandleIPduDeferredEvent((PduIdType) ComPduId))
        {
#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
          PduLengthType ComPduLength = com_RxNHdlr_HandleIPduDeferred[(PduIdType) ComPduId] - 1;
#   endif
          Com_RxNHdlr_ClrHandleIPduDeferredEvent((PduIdType) ComPduId);
#   if (COM_RXNHDLR_DEFERRED_NOTIFICATIONFLAG == STD_ON)
          /* KB begin Com_RxNHdlr_SetRxNotificationFlag */
#    if (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON)
          {
            uint16_least notiFlagIndex;
#     if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
            for (notiFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) ComPduId];
                 ((notiFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) (ComPduId + 1)]) &&
                  (Com_ConfigValue(Com_RxNHdlr_NotiFlagIndirection)[notiFlagIndex].validDlc <= ComPduLength));
                 notiFlagIndex++)
#     else
            for (notiFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) ComPduId];
                 notiFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFlags)[(PduIdType) (ComPduId + 1)];
                 notiFlagIndex++)
#     endif
            {
              Com_RxNHdlr_FlagInfoRefType currentNotiFlagInfoPtr;
              Com_RxNHdlr_NotiFlagIdType currentNotiFlagId;
              Com_LMgt_CheckFatalErrorRetVoid((notiFlagIndex < Com_RxNHdlr_GetNotificationFlagCnt()),
                                              Com_RxNHdlr_NotiFlagIdxTooLarge);

              currentNotiFlagId = Com_ConfigValue(Com_RxNHdlr_NotiFlagIndirection)[notiFlagIndex].notiFlagId;
#     if ((COM_RXNHDLR_INHIBITINDFLAG == STD_ON) || (COM_RXINV_INHIBITINDFLAG == STD_ON))
              if (FALSE == Com_RxNHdlr_NotificationFlagInhibited(currentNotiFlagId))
#     endif
              {
                currentNotiFlagInfoPtr = &Com_RxNHdlr_NotificationFlagInfo[currentNotiFlagId];
                com_RxNHdlr_NotificationFlags[currentNotiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] |=
                  currentNotiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask;
              }
            }
          }
#    endif
       /* (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON) */
          /* KB end Com_RxNHdlr_SetRxNotificationFlag */
#   endif
        /* (COM_RXNHDLR_DEFERRED_NOTIFICATIONFLAG == STD_ON) */
#   if ((COM_RESET_TIMEOUTFLAG == STD_ON)  && (COM_RXNHDLR_DEFERRED_TIMEOUTFLAG == STD_ON))
          /* KB begin Com_RxNHdlr_ClrRxTimeoutFlag */
#    if (COM_RXNHDLR_TIMEOUTFLAG == STD_ON)
          {
            uint16_least timeoutFlagIndex;
            for (timeoutFlagIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) ComPduId];
                 timeoutFlagIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2TimeoutFlags)[(PduIdType) (ComPduId + 1)];
                 timeoutFlagIndex++)
            {
              Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
              Com_LMgt_CheckFatalErrorRetVoid((timeoutFlagIndex < Com_RxNHdlr_TimeoutFlagCnt),
                                              Com_RxNHdlr_TimeoutFlagIdxTooLarge);
              timeoutFlagInfoPtr =
                &Com_RxNHdlr_TimeoutFlagInfo[Com_ConfigValue(Com_RxNHdlr_TimeoutFlagIndirection)[timeoutFlagIndex]];
              com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
                COM_CAST2UINT8(~timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
            }
          }
#    endif/* (COM_RXNHDLR_TIMEOUTFLAG == STD_ON) */
          /* KB end Com_RxNHdlr_ClrRxTimeoutFlag */
#   endif
        /* ((COM_RESET_TIMEOUTFLAG == STD_ON)  && (COM_RXNHDLR_DEFERRED_TIMEOUTFLAG == STD_ON)) */
#   if (COM_RXNHDLR_DEFERRED_NOTIFICATIONFUNCTION == STD_ON)
          /* KB begin Com_RxNHdlr_CallNotificationFunction */
#    if (COM_RXNHDLR_NOTIFICATIONFUNCTION == STD_ON)
          {
            uint16_least notiIndex;

#     if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
            for (notiIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFunctions)[(PduIdType) ComPduId];
                 ((notiIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFunctions)[(PduIdType) (ComPduId + 1)]) &&
                  (Com_ConfigValue(Com_RxNHdlr_NotiFuncIndirection)[notiIndex].validDlc <= ComPduLength)); notiIndex++)
#     else
            for (notiIndex = Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFunctions)[(PduIdType) ComPduId];
                 notiIndex < Com_ConfigValue(Com_RxNHdlr_Ipdu2NotificationFunctions)[(PduIdType) (ComPduId + 1)];
                 notiIndex++)
#     endif
            {
              Com_LMgt_CheckFatalErrorRetVoid((notiIndex < Com_RxNHdlr_GetNotificationCnt()),
                                              Com_RxNHdlr_NotiFuncIdxTooLarge);
              Com_RxNHdlr_CallNotificationFunc(Com_ConfigValue(Com_RxNHdlr_NotiFuncIndirection)[notiIndex].
                                               notificationIdx);
            }
          }
#    endif
          /* KB end Com_RxNHdlr_CallNotificationFunction */
#   endif
        /* (COM_RXNHDLR_DEFERRED_NOTIFICATIONFUNCTION == STD_ON) */
        }
      }
    }
#  endif
    /* KB end Com_RxNHdlr_MainFunctionRx */
    /* KB begin Com_RxSigIf_MainFunctionRx */
    /* KB end Com_RxSigIf_MainFunctionRx */
    /* KB begin Com_RxUbHdlr_MainFunctionRx */
#  if ((COM_RXUBHDLR_TIMEOUT == STD_ON) || (COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON))
    {
      sint16_least ComPduId;
      uint16_least ubId;

      SchM_Enter_Com(COM_EXCLUSIVE_AREA_3);
      for (ComPduId = (sint16_least) Com_RxBuffer_GetRxIpduCnt() - 1; ComPduId >= 0; ComPduId--)
      {
        for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) ComPduId];
             ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[(PduIdType) (ComPduId + 1)]; ubId++)
        {
          Com_LMgt_CheckFatalErrorBreak((ubId < Com_RxUbHdlr_GetUpdateBitCnt()), Com_RxUbHdlr_InvalidUbHdl);
#   if (COM_RXUBHDLR_TIMEOUT == STD_ON)
          if (Com_LMgt_RxIpduDmActive((PduIdType) ComPduId))
          {
            if (Com_ConfigValue(Com_RxUbHdlr_TimeoutTime)[ubId] != 0)
            {
              SchM_Enter_Com(COM_EXCLUSIVE_AREA_4);
              if (0 < com_RxUbHdlr_TimeoutCnt[ubId])
              {
                com_RxUbHdlr_TimeoutCnt[ubId]--;
                SchM_Exit_Com(COM_EXCLUSIVE_AREA_4);
              }
              else
              {
                com_RxUbHdlr_TimeoutCnt[ubId] = Com_ConfigValue(Com_RxUbHdlr_TimeoutTime)[ubId];
#    if (COM_RXUBHDLR_TIMEOUTDEFAULTVALUE == STD_ON)
                Com_RxBuffer_WriteIpduWithMask((PduIdType) ComPduId,
                                               Com_RxBuffer_GetIpduInitValPtr((PduIdType) ComPduId),
                                               Com_RxUbHdlr_GetIpduTimeoutMask(ubId));
#    endif
                SchM_Exit_Com(COM_EXCLUSIVE_AREA_4);

                /* KB begin Com_RxUbHdlr_SetRxTimeoutFlag */
#    if (COM_RXUBHDLR_TIMEOUTFLAG == STD_ON)
                {
                  Com_RxNHdlr_TimeoutFlagIdType timeoutFlagIdx = Com_ConfigValue(Com_RxUbHdlr_TimeoutFlagHdl)[ubId];

                  if (COM_RX_NHDLR_NOTIMEOUTFLAG != timeoutFlagIdx)
                  {
                    Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
                    Com_LMgt_CheckFatalErrorBreak((timeoutFlagIdx < Com_RxNHdlr_TimeoutFlagCnt),
                                                  Com_RxUbHdlr_TimeoutFlagIdxTooLarge);
                    timeoutFlagInfoPtr = &Com_RxNHdlr_TimeoutFlagInfo[timeoutFlagIdx];
                    com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] |=
                      timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask;
                  }
                }
#    endif
                /* KB end Com_RxUbHdlr_SetRxTimeoutFlag */
                /* KB begin Com_RxUbHdlr_CallTimeoutFunction */
#    if (COM_RXUBHDLR_TIMEOUTFUNCTION == STD_ON)
                {
                  Com_RxNHdlr_TimeoutIdxType timeoutFctIdx = Com_ConfigValue(Com_RxUbHdlr_TimeoutFuncIndirection)[ubId];
                  if (0 < timeoutFctIdx)
                  {
#     if ((COM_CONFIG_VARIANT == 2)||(COM_CONFIG_VARIANT == 3))
                    /*lint -e(661) If the number of notifications is 0, the array has minimum 1 value. */
#     endif
                    Com_RxNHdlr_TimeoutNotiFuncPtr[timeoutFctIdx] ();
                  }
                }
#    endif
                /* KB end Com_RxUbHdlr_CallTimeoutFunction */

#    if ((COM_RXINV_NOTIINVFUNC_UB_TO == STD_ON)  && (COM_RXINV_NOTIINVFUNC == STD_ON))
                Com_RxInv_NotiInvalidUb((Com_RxUbHdlr_UbIdType) ubId, TRUE);
#    endif
#    if (COM_SIGNALGW_RXTIMEOUTUB == STD_ON)
                Com_SignalGw_RxUbTimeout((Com_RxUbHdlr_UbIdType) ubId);
#    endif
              }
            }
          }                     /* (Com_LMgt_RxIpduDmActive((PduIdType) ComPduId)) */
#   endif/* (COM_RXUBHDLR_TIMEOUT == STD_ON) */
#   if (COM_RXUBHDLR_DEFERRED_SIGNALPROCESSING == STD_ON)
          if (FALSE != com_RxUbHdlr_HandleUbDeferred[ubId])
          {
            com_RxUbHdlr_HandleUbDeferred[ubId] = FALSE;
#    if (COM_RXUBHDLR_DEFERRED_NOTIFICATIONFLAG == STD_ON)
            /* KB begin Com_RxUbHdlr_SetRxNotificationFlag */
#     if (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON)
            {
              Com_RxNHdlr_NotiFlagIdType notiFlagIdx = Com_ConfigValue(Com_RxUbHdlr_NotiFlagHdl)[ubId];

              if (COM_RX_NHDLR_NONOTIFLAG != notiFlagIdx)
              {
                Com_RxNHdlr_FlagInfoRefType notiFlagInfoPtr;
                Com_LMgt_CheckFatalErrorBreak((notiFlagIdx < Com_RxNHdlr_NotiFlagCnt),
                                              Com_RxUbHdlr_NotificationFlagIdxTooLarge);
#      if ((COM_RXNHDLR_INHIBITINDFLAG == STD_ON) || (COM_RXINV_INHIBITINDFLAG == STD_ON))
                if (FALSE == Com_RxNHdlr_NotificationFlagInhibited(notiFlagIdx))
#      endif
                {
                  notiFlagInfoPtr = &Com_RxNHdlr_NotificationFlagInfo[notiFlagIdx];
                  com_RxNHdlr_NotificationFlags[notiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] |=
                    notiFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask;
                }
              }
            }
#     endif
         /* (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON) */
            /* KB end Com_RxUbHdlr_SetRxNotificationFlag */
#    endif/* (COM_RXUBHDLR_DEFERRED_NOTIFICATIONFLAG == STD_ON) */
#    if ((COM_RESET_TIMEOUTFLAG == STD_ON) && (COM_RXUBHDLR_DEFERRED_TIMEOUTFLAG == STD_ON))
            /* KB begin Com_RxUbHdlr_ClrRxTimeoutFlag */
#     if (COM_RXUBHDLR_TIMEOUTFLAG == STD_ON)
            {
              Com_RxNHdlr_TimeoutFlagIdType timeoutFlagIdx = Com_ConfigValue(Com_RxUbHdlr_TimeoutFlagHdl)[ubId];

              if (COM_RX_NHDLR_NOTIMEOUTFLAG != timeoutFlagIdx)
              {
                Com_RxNHdlr_FlagInfoRefType timeoutFlagInfoPtr;
                Com_LMgt_CheckFatalErrorBreak((timeoutFlagIdx < Com_RxNHdlr_TimeoutFlagCnt),
                                              Com_RxUbHdlr_TimeoutFlagIdxTooLarge);
                timeoutFlagInfoPtr = &Com_RxNHdlr_TimeoutFlagInfo[timeoutFlagIdx];
                com_RxNHdlr_TimeoutFlags[timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeOffset] &=
                  COM_CAST2UINT8(~timeoutFlagInfoPtr->Com_RxNHdlr_FlagInfoTypeMask);
              }
            }
#     endif
            /* KB end Com_RxUbHdlr_ClrRxTimeoutFlag */
#    endif/* ((COM_RESET_TIMEOUTFLAG == STD_ON) && (COM_RXUBHDLR_DEFERRED_TIMEOUTFLAG == STD_ON)) */
#    if (COM_RXUBHDLR_DEFERRED_NOTIFICATIONFUNCTION == STD_ON)
            /* KB begin Com_RxUbHdlr_CallNotificationFunction */
#     if (COM_RXUBHDLR_NOTIFICATIONFUNCTION == STD_ON)
            {
              Com_RxNHdlr_NotificationIdxType notiFctIdx = Com_ConfigValue(Com_RxUbHdlr_NotiFuncIndirection)[ubId];
              if (0 < notiFctIdx)
              {
#      if ((COM_CONFIG_VARIANT == 2)||(COM_CONFIG_VARIANT == 3))
                /*lint -e{661} If the number of notifications is 0, the array has minimum 1 value. */
#      endif
                Com_RxNHdlr_CallNotificationFunc(notiFctIdx);
              }
            }
#     endif
            /* KB end Com_RxUbHdlr_CallNotificationFunction */
#    endif/* (COM_RXUBHDLR_DEFERRED_NOTIFICATIONFUNCTION == STD_ON) */
          }
#   endif
        }
      }
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_3);
    }                           /* End of Com_RxUbHdlr_MainFunction() */
#  endif
    /* KB end Com_RxUbHdlr_MainFunctionRx */
    /* KB begin Com_RxInv_MainFunctionRx */
    /* KB end Com_RxInv_MainFunctionRx */
    /* KB begin Com_TxInv_MainFunctionRx */
    /* KB end Com_TxInv_MainFunctionRx */
    /* KB begin Com_TxBuffer_MainFunctionRx */
    /* KB end Com_TxBuffer_MainFunctionRx */
    /* KB begin Com_TxDlMon_MainFunctionRx */
    /* KB end Com_TxDlMon_MainFunctionRx */
    /* KB begin Com_TxLLIf_MainFunctionRx */
    /* KB end Com_TxLLIf_MainFunctionRx */
    /* KB begin Com_TxModeHdlr_MainFunctionRx */
    /* KB end Com_TxModeHdlr_MainFunctionRx */
    /* KB begin Com_TxNHdlr_MainFunctionRx */
    /* KB end Com_TxNHdlr_MainFunctionRx */
    /* KB begin Com_TxSigIf_MainFunctionRx */
    /* KB end Com_TxSigIf_MainFunctionRx */
    /* KB begin Com_SignalGw_MainFunctionRx */
    /* KB end Com_SignalGw_MainFunctionRx */
  }
# endif
}                               /* End of Com_MainFunctionRx() */
#endif

#if (COM_MAIN_FUNCTION_TX_API == STD_ON )
FUNC(void, COM_CODE) Com_MainFunctionTx(void)   /* COM399 */
{
# if (COM_LMGT_TX == STD_ON)
  if (com_LMgt_Status == COM_INIT)
  {
    /* KB begin Com_LMgt_MainFunctionTx */
    /* KB end Com_LMgt_MainFunctionTx */
    /* KB begin Com_Signal_MainFunctionTx */
    /* KB end Com_Signal_MainFunctionTx */
    /* KB begin Com_Buffer_MainFunctionTx */
    /* KB end Com_Buffer_MainFunctionTx */
    /* KB begin Com_RxBuffer_MainFunctionTx */
    /* KB end Com_RxBuffer_MainFunctionTx */
    /* KB begin Com_RxDlMon_MainFunctionTx */
    /* KB end Com_RxDlMon_MainFunctionTx */
    /* KB begin Com_RxLLIf_MainFunctionTx */
    /* KB end Com_RxLLIf_MainFunctionTx */
    /* KB begin Com_RxNHdlr_MainFunctionTx */
    /* KB end Com_RxNHdlr_MainFunctionTx */
    /* KB begin Com_RxSigIf_MainFunctionTx */
    /* KB end Com_RxSigIf_MainFunctionTx */
    /* KB begin Com_RxUbHdlr_MainFunctionTx */
    /* KB end Com_RxUbHdlr_MainFunctionTx */
    /* KB begin Com_RxInv_MainFunctionTx */
    /* KB end Com_RxInv_MainFunctionTx */
    /* KB begin Com_TxInv_MainFunctionTx */
    /* KB end Com_TxInv_MainFunctionTx */
    /* KB begin Com_TxBuffer_MainFunctionTx */
    /* KB end Com_TxBuffer_MainFunctionTx */
    /* KB begin Com_TxDlMon_MainFunctionTx */
#  if (COM_TXDLMON == STD_ON)
    {
      sint16_least ComTxPduId;

      SchM_Enter_Com(COM_EXCLUSIVE_AREA_1);
      for (ComTxPduId = (sint16_least) Com_TxBuffer_GetTxIpduCnt() - 1; ComTxPduId >= 0; ComTxPduId--)
      {
        if (Com_ConfigValue(Com_TxDlMon_TimeoutTime)[ComTxPduId] != 0)
        {
          SchM_Enter_Com(COM_EXCLUSIVE_AREA_2);
          if (0 < com_TxDlMon_TimeoutCnt[ComTxPduId])
          {
            com_TxDlMon_TimeoutCnt[ComTxPduId]--;

            if (0 == com_TxDlMon_TimeoutCnt[ComTxPduId])
            {
              SchM_Exit_Com(COM_EXCLUSIVE_AREA_2);
#   if (COM_TXNHDLR_TIMEOUTFUNCTION == STD_ON)
              Com_TxNHdlr_Timeout((PduIdType) ComTxPduId);
#   endif
#   if (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON)
              com_TxModeHdlr_DelayTimeCnt[ComTxPduId] = (uint16) 0u;
#   endif/* (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) */
            }
            else
            {
              SchM_Exit_Com(COM_EXCLUSIVE_AREA_2);
            }
          }
          else
          {
            SchM_Exit_Com(COM_EXCLUSIVE_AREA_2);
          }
        }
      }
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_1);
    }                           /* End of Com_TxDlMon_MainFunctionTx() */
#  endif/* (COM_TXDLMON == STD_ON) */
    /* KB end Com_TxDlMon_MainFunctionTx */
    /* KB begin Com_TxLLIf_MainFunctionTx */
    /* KB end Com_TxLLIf_MainFunctionTx */
    /* KB begin Com_TxModeHdlr_MainFunctionTx */
#  if (COM_TXMODEHDLR == STD_ON)
    {
      sint16_least i;
      SchM_Enter_Com(COM_EXCLUSIVE_AREA_1);
      for (i = (sint16_least) Com_TxBuffer_GetTxIpduCnt() - 1; i >= 0; i--)
      {
        if (Com_LMgt_TxIpduActive(((PduIdType) i)))
        {
#   if (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON)
          if (com_TxModeHdlr_CyclicSendRequest[i] == TRUE)
          {
            com_TxModeHdlr_CycleTimeCnt[i]--;
            if (com_TxModeHdlr_CycleTimeCnt[i] == (uint16) 0u)
            {
              com_TxModeHdlr_TransmitRequest[i] = TRUE;
              /* reload the cycle time counter */
              com_TxModeHdlr_CycleTimeCnt[i] = Com_TxModeHdlr_GetTxModeParameter(i, COM_TXMODE_PARAM_TIMEPERIOD);
            }
          }
#   endif/* (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON) */

#   if (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON)
          if (com_TxModeHdlr_RepetitionCnt[i] > (uint8) 0u)
          {
            com_TxModeHdlr_RepCycleCnt[i]--;
            if (com_TxModeHdlr_RepCycleCnt[i] == (uint16) 0u)
            {
              com_TxModeHdlr_TransmitRequest[i] = TRUE;
              /* reload the repetition cycle time counter */
              com_TxModeHdlr_RepCycleCnt[i] = Com_TxModeHdlr_GetTxModeParameter(i, COM_TXMODE_PARAM_REPETITIONPERIOD);
            }
          }
#   endif/* (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON) */

#   if (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON)
          /* Delay Time and Transmission Handling */
          if (com_TxModeHdlr_DelayTimeCnt[i] == (uint16) 0u)
#   endif/* (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) */
          {
            if (com_TxModeHdlr_TransmitRequest[i] == TRUE)
            {
#   if (COM_TXMODEHDLR_QUEUE_FAILED_TRANSMISSION_REQUESTS == STD_ON)
              if (Com_TxLLIf_Transmit(((PduIdType) i)) != E_NOT_OK)
#   else
              (void) Com_TxLLIf_Transmit(((PduIdType) i));
#   endif
              {
                com_TxModeHdlr_TransmitRequest[i] = FALSE;
              }
            }
          }
#   if (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON)
          else
          {
            SchM_Enter_Com(COM_EXCLUSIVE_AREA_2);
            com_TxModeHdlr_DelayTimeCnt[i]--;
            SchM_Exit_Com(COM_EXCLUSIVE_AREA_2);
          }
#   endif/* (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) */
        }
      }
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_1);
    }
#  endif/* COM_TXMODEHDLR == STD_ON */
    /* KB end Com_TxModeHdlr_MainFunctionTx */
    /* KB begin Com_TxNHdlr_MainFunctionTx */
#  if (COM_TXNHDLR == STD_ON) && (COM_TXCONFIRMATION_DEFERRED == STD_ON)
    {
      sint16_least ipduIndex;
      uint16_least notiIndex;

      for (ipduIndex = (sint16_least) Com_TxBuffer_GetTxIpduCnt() - 1; ipduIndex >= 0; ipduIndex--)
      {
        if (FALSE != com_TxNHdlr_HandleIPduDeferred[ipduIndex])
        {
          com_TxNHdlr_HandleIPduDeferred[ipduIndex] = FALSE;

          for (notiIndex = Com_ConfigValue(Com_TxNHdlr_Ipdu2NotificationFunctions)[ipduIndex];
               notiIndex < Com_ConfigValue(Com_TxNHdlr_Ipdu2NotificationFunctions)[ipduIndex + 1]; notiIndex++)
          {
            Com_LMgt_CheckFatalErrorRetVoid((notiIndex < Com_TxNHdlr_GetNotificationCnt()),
                                            Com_TxNHdlr_NotiFuncIdxTooLarge);
            Com_TxNHdlr_NotificationFuncPtr[Com_ConfigValue(Com_TxNHdlr_NotiFuncIndirection)[notiIndex]] ();
          }
        }
      }
    }
#  endif
    /* KB end Com_TxNHdlr_MainFunctionTx */
    /* KB begin Com_TxSigIf_MainFunctionTx */
    /* KB end Com_TxSigIf_MainFunctionTx */
    /* KB begin Com_SignalGw_MainFunctionTx */
    /* KB end Com_SignalGw_MainFunctionTx */
  }
# endif
}                               /* End of Com_MainFunctionTx() */
#endif

#if (COM_GET_CONFIGURATION_ID_API == STD_ON )
FUNC(uint32, COM_CODE) Com_GetConfigurationId(void)
{
  Com_LMgt_CheckDetErrorContinue((com_LMgt_Status == COM_INIT), COMServiceId_GetConfigurationId, COM_E_UNINIT);
  return Com_ConfigValue(Com_LMgt_ConfigurationId);
}                               /* End of Com_GetConfigurationId() */
#endif

#if (COM_GET_CONFIGURATION_STRING_PTR_API == STD_ON )
FUNC(Com_CharTypePtr, COM_CODE) Com_GetConfigurationStringPtr(void)
{
  Com_LMgt_CheckDetErrorContinue((com_LMgt_Status == COM_INIT), COMServiceId_GetConfigurationString, COM_E_UNINIT);
  return Com_ConfigValue(Com_LMgt_ConfigurationStringPtr);
}                               /* End of Com_GetConfigurationString() */
#endif

#if (COM_GET_STATUS_API == STD_ON )
FUNC(Com_StatusType, COM_CODE) Com_GetStatus(void)
{
  Com_LMgt_CheckDetErrorContinue((com_LMgt_Status == COM_INIT), COMServiceId_GetStatus, COM_E_UNINIT);
  return com_LMgt_Status;
}                               /* End of Com_GetStatus() */
#endif

#if (COM_GET_VERSION_INFO_API == STD_ON)
FUNC(void, COM_CODE) Com_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_VAR) versioninfo)
{
  Com_LMgt_CheckDetErrorContinue((com_LMgt_Status == COM_INIT), COMServiceId_GetVersionInfo, COM_E_UNINIT);
  Com_LMgt_CheckFatalErrorRetVoid(versioninfo != NULL_PTR, Com_LMgt_NullPointerParameter);

  versioninfo->vendorID = COM_VENDOR_ID;
  versioninfo->moduleID = COM_MODULE_ID;
  versioninfo->instanceID = (uint8) 0x00u;
  versioninfo->sw_major_version = COM_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = COM_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = COM_SW_PATCH_VERSION;

}                               /* End of Com_GetVersionInfo() */
#endif /* (COM_GET_VERSION_INFO_API == STD_ON) */

#if (COM_TRIGGER_IPDU_SEND_API == STD_ON)
FUNC(void, COM_CODE) Com_TriggerIPDUSend(PduIdType ComTxPduId)
{
# if (COM_LMGT_TX == STD_ON) && (COM_TXMODEHDLR == STD_ON)
  Com_LMgt_CheckDetErrorReturnVoid((Com_GetStatus() == COM_INIT), COMServiceId_TriggerIPDUSend, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), COMServiceId_TriggerIPDUSend,
                                   COM_E_PARAM);

  Com_TxModeHdlr_TriggerIpduSendOnceDeferred(ComTxPduId);
# endif /* COM_TXMODEHDLR == STD_ON */
}                               /* End of Com_TriggerIPDUSend() */
#endif
/* KB end Com_LMgt_GlobalFunctions */
/* KB begin Com_Signal_GlobalFunctions */
#if (COM_SIGNALCONVERSION == STD_ON)
FUNC(void, COM_CODE) Com_ConvertSignal(Com_SignalIdType SignalId, P2CONST(void, AUTOMATIC, COM_APPL_DATA) FromDataPtr,
                                       P2VAR(void, AUTOMATIC, COM_APPL_VAR) ToDataPtr)
{
  Com_Signal_SignalConvRefType conversionPtr;
  Com_Signal_AccessAttrType AccessAttr;
  boolean signedConversion;

# if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
  SignalId = Com_ConfigValue(Com_Signal_Ext2IntSignalId)[SignalId];
# endif

  Com_LMgt_CheckFatalErrorRetVoid((COM_SIGNAL_NO_CONVERSION != Com_Signal_GetSignalAttribute(SignalId, ConversionHdl)),
                                  Com_Signal_InconsistentConfigurationData);

  AccessAttr = Com_Signal_GetSignalAttribute((SignalId), AccessAttributes);
  conversionPtr = Com_Signal_GetConversion(SignalId);
  signedConversion = (boolean) (Com_Signal_ConversionIsSigned(conversionPtr) ? TRUE : FALSE);

  if (SignalId < Com_Signal_GetRxSignalCnt())
  {
# if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint8(AccessAttr))
    {
      if (TRUE == signedConversion)
      {
        (*(P2VAR(sint8, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          (sint8) Com_Convert_SignedBusToEcu(conversionPtr,
                                             (sint32) (*(P2CONST(sint8, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
      else
      {
        (*(P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          (uint8) Com_Convert_UnsignedBusToEcu(conversionPtr,
                                               (uint32) (*(P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
    }
    else
# endif /* ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON)) */
# if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
    {
      if (TRUE == signedConversion)
      {
        (*(P2VAR(sint16, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          (sint16) Com_Convert_SignedBusToEcu(conversionPtr,
                                              (sint32) (*(P2CONST(sint16, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
      else
      {
        (*(P2VAR(uint16, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          (uint16) Com_Convert_UnsignedBusToEcu(conversionPtr,
                                                (uint32) (*(P2CONST(uint16, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
    }
    else
# endif /* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
# if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr))
    {
      if (TRUE == signedConversion)
      {
        (*(P2VAR(sint32, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          Com_Convert_SignedBusToEcu(conversionPtr, (*(P2CONST(sint32, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
      else
      {
        (*(P2VAR(uint32, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          Com_Convert_UnsignedBusToEcu(conversionPtr, (*(P2CONST(uint32, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
    }
    else
# endif /* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
    {
    }
  }
  else
  {
# if ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint8(AccessAttr))
    {
      if (TRUE == signedConversion)
      {
        (*(P2VAR(sint8, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          (sint8) Com_Convert_SignedEcuToBus(conversionPtr,
                                             (sint32) (*(P2CONST(sint8, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
      else
      {
        (*(P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          (uint8) Com_Convert_UnsignedEcuToBus(conversionPtr,
                                               (uint32) (*(P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
    }
    else
# endif /* ((COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON)) */
# if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
    {
      if (TRUE == signedConversion)
      {
        (*(P2VAR(sint16, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          (sint16) Com_Convert_SignedEcuToBus(conversionPtr,
                                              (sint32) (*(P2CONST(sint16, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
      else
      {
        (*(P2VAR(uint16, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          (uint16) Com_Convert_UnsignedEcuToBus(conversionPtr,
                                                (uint32) (*(P2CONST(uint16, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
    }
    else
# endif /* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
# if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr))
    {
      if (TRUE == signedConversion)
      {
        (*(P2VAR(sint32, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          Com_Convert_SignedEcuToBus(conversionPtr, (*(P2CONST(sint32, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
      else
      {
        (*(P2VAR(uint32, AUTOMATIC, COM_APPL_VAR)) ToDataPtr) =
          Com_Convert_UnsignedEcuToBus(conversionPtr, (*(P2CONST(uint32, AUTOMATIC, COM_APPL_DATA)) FromDataPtr));
      }
    }
    else
# endif /* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON)) */
    {
    }
  }
}

FUNC(sint32, COM_CODE) Com_Convert_SignedBusToEcu(Com_Signal_SignalConvRefType ConversionPtr, sint32 BusData)
{
  uint32 scaling;
  sint32 value;
  Com_Signal_ConversionVariantType variant;

  variant = Com_Signal_ConversionType(ConversionPtr);
  value = (BusData * (ConversionPtr->Factor)) + (ConversionPtr->Offset);

  if (COM_SIGNAL_CONV_TYPE2 == variant)
  {
    scaling = ConversionPtr->Scaling;
    if (value >= (sint32) 0)
    {
      value = (sint32) (((uint32) value + ((uint32) 1 << (scaling - (uint32) 1))) >> scaling);
    }
    else
    {
      value = (value - ((sint32) 1 << (scaling - (uint32) 1))) / ((sint32) 1 << scaling);
    }
  }
  else if (COM_SIGNAL_CONV_TYPE10 == variant)
  {
    scaling = ConversionPtr->Scaling;
    if (value > (sint32) 0)
    {
      value = (value + (sint32) (scaling >> (uint32) 1)) / (sint32) scaling;
    }
    else
    {
      value = (value - (sint32) (scaling >> (uint32) 1)) / (sint32) scaling;
    }
  }
  else
  {
  }
  return value;
}

FUNC(uint32, COM_CODE) Com_Convert_UnsignedBusToEcu(Com_Signal_SignalConvRefType ConversionPtr, uint32 BusData)
{
  uint32 scaling, value;
  Com_Signal_ConversionVariantType variant;

  variant = Com_Signal_ConversionType(ConversionPtr);
  value = (BusData * (uint32) (ConversionPtr->Factor)) + (uint32) (ConversionPtr->Offset);

  if (COM_SIGNAL_CONV_TYPE2 == variant)
  {
    scaling = (ConversionPtr->Scaling);
    value = (value + ((uint32) 1 << (scaling - (uint32) 1))) >> scaling;
  }
  else if (COM_SIGNAL_CONV_TYPE10 == variant)
  {
    scaling = (ConversionPtr->Scaling);
    value = (value + (scaling >> (uint32) 1)) / scaling;
  }
  else
  {
  }
  return value;
}

FUNC(sint32, COM_CODE) Com_Convert_SignedEcuToBus(Com_Signal_SignalConvRefType ConversionPtr, sint32 EcuData)
{
  sint32 factor, value;
  Com_Signal_ConversionVariantType variant;

  variant = Com_Signal_ConversionType(ConversionPtr);
  factor = (ConversionPtr->Factor);

  if (COM_SIGNAL_CONV_TYPE1 == variant)
  {
    value = EcuData - (ConversionPtr->Offset);
  }
  else if (COM_SIGNAL_CONV_TYPE2 == variant)
  {
    value = (sint32) ((uint32) EcuData << (ConversionPtr->Scaling)) - (ConversionPtr->Offset);
  }
  else
  {
    value = (EcuData * (sint32) (ConversionPtr->Scaling)) - (ConversionPtr->Offset);
  }

  if ((factor > (sint32) 0) == (value > (sint32) 0))
  {
    value = (value + (factor / (sint32) 2)) / factor;
  }
  else
  {
    value = (value - (factor / (sint32) 2)) / factor;
  }
  return value;
}

FUNC(uint32, COM_CODE) Com_Convert_UnsignedEcuToBus(Com_Signal_SignalConvRefType ConversionPtr, uint32 EcuData)
{
  uint32 factor, value;
  Com_Signal_ConversionVariantType variant;

  variant = Com_Signal_ConversionType(ConversionPtr);
  factor = (uint32) (ConversionPtr->Factor);

  if (COM_SIGNAL_CONV_TYPE1 == variant)
  {
    value = EcuData;
  }
  else if (COM_SIGNAL_CONV_TYPE2 == variant)
  {
    value = EcuData << (ConversionPtr->Scaling);
  }
  else
  {
    value = EcuData * (ConversionPtr->Scaling);
  }
  return ((value - (uint32) (ConversionPtr->Offset)) + (factor >> (uint32) 1)) / factor;
}
#endif /* (COM_SIGNALCONVERSION == STD_ON) */
/* KB end Com_Signal_GlobalFunctions */
/* KB begin Com_Buffer_GlobalFunctions */
/* KB end Com_Buffer_GlobalFunctions */
/* KB begin Com_RxBuffer_GlobalFunctions */
/* KB end Com_RxBuffer_GlobalFunctions */
/* KB begin Com_RxDlMon_GlobalFunctions */
/* KB end Com_RxDlMon_GlobalFunctions */
/* KB begin Com_RxLLIf_GlobalFunctions */
#if (COM_RXLLIF == STD_ON)
# if(COM_USE_PDUINFOTYPE == STD_ON)
#  define COM_RXIND_SDUDATAPTR      (P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) (*COM_RXIND_PARA).SduDataPtr
#  define COM_RXIND_SDULENGTH       (*COM_RXIND_PARA).SduLength
# else
#  define COM_RXIND_SDUDATAPTR      COM_RXIND_PARA
#  define COM_RXIND_SDULENGTH       0
# endif
FUNC(void, COM_CODE) Com_RxIndication(PduIdType ComRxPduId, COM_RXIND_TYPE COM_RXIND_PARA)
{
  Com_LMgt_CheckDetErrorReturnVoid((Com_GetStatus() == COM_INIT), COMServiceId_RxIndication, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((ComRxPduId < Com_RxBuffer_GetRxIpduCnt()), COMServiceId_RxIndication, COM_E_PARAM);

  Com_LMgt_CheckDetErrorReturnVoid((COM_RXIND_PARA != NULL_PTR), COMServiceId_RxIndication, COM_E_PARAM);
# if ((COM_USE_PDUINFOTYPE == STD_ON) && (COM_DYNAMIC_DLC_SUPPORT == STD_OFF))
  Com_LMgt_CheckDetErrorReturnVoid((COM_RXIND_SDULENGTH == Com_RxBuffer_GetIpduLength(ComRxPduId)),
                                   COMServiceId_RxIndication, COM_E_PARAM);
# endif

  if (Com_LMgt_RxIpduActive(ComRxPduId))
  {
# if (COM_RXPDUCALLOUT == STD_ON)
    boolean CalloutResult;
    Com_RxLLIf_PduCalloutIdType CalloutId = Com_ConfigValue(Com_RxLLIf_PduCalloutIndirection)[ComRxPduId];
# endif
# if (COM_RXPDUCALLOUT == STD_ON)
    if (COM_RXLLIF_NO_PDUCALLOUT == CalloutId)
    {
      CalloutResult = TRUE;
    }
    else
    {
      CalloutResult = Com_RxLLIf_PduCallout[CalloutId] (ComRxPduId, (COM_RXCALLOUT_TYPE) COM_RXIND_PARA);
    }

    if (TRUE == CalloutResult)
# endif /* (COM_RXPDUCALLOUT == STD_ON) */
    {
      PduLengthType pduLength = Com_RxBuffer_GetIpduLength(ComRxPduId);
# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
      if (COM_RXIND_SDULENGTH < pduLength)
      {
        pduLength = COM_RXIND_SDULENGTH;
      }
# endif
# if (COM_RXINV == STD_ON)
      {
        VAR(uint8, COM_VAR_NOINIT) invalidMask[COM_MAXIPDULENGTH];
        VAR(uint8, COM_VAR_NOINIT) sduTmpBuffer[COM_MAXIPDULENGTH];
        Com_LMgt_MemSet(invalidMask, 0xFFu, COM_MAXIPDULENGTH);
        Com_LMgt_MemCpyRamToRam(sduTmpBuffer, COM_RXIND_SDUDATAPTR, pduLength);
#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
        Com_RxInv_CheckInvalidation(ComRxPduId, sduTmpBuffer, invalidMask, pduLength);
#  else
        Com_RxInv_CheckInvalidation(ComRxPduId, sduTmpBuffer, invalidMask);
#  endif

        SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);   /*ESCAN00036378 */
#  if (COM_RXNHDLR_RXFILTER == STD_ON)
#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
        Com_RxNHdlr_EvaluateFilter(ComRxPduId, (P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) sduTmpBuffer, pduLength);
#   else
        Com_RxNHdlr_EvaluateFilter(ComRxPduId, (P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)) sduTmpBuffer);
#   endif
#  endif
        Com_RxBuffer_WriteIpduWithMask(ComRxPduId, sduTmpBuffer, invalidMask);
      }
# else /* (COM_RXINV == STD_OFF) */
      {
        P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pduDataPtr = Com_RxBuffer_GetIpduDataPtr(ComRxPduId);
        Com_LMgt_CheckFatalErrorRetVoid((pduDataPtr != NULL_PTR), Com_RxIndication_PduInfoNullPointer);

        SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);   /*ESCAN00036378 */
#  if (COM_RXNHDLR_RXFILTER == STD_ON)
#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
        Com_RxNHdlr_EvaluateFilter(ComRxPduId, COM_RXIND_SDUDATAPTR, pduLength);
#   else
        Com_RxNHdlr_EvaluateFilter(ComRxPduId, COM_RXIND_SDUDATAPTR);
#   endif
#  endif
        Com_LMgt_MemCpyRamToRam(pduDataPtr, COM_RXIND_SDUDATAPTR, pduLength);
      }
# endif /* (COM_RXINV == STD_ON) */
      SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);

# if (COM_RXDLMON == STD_ON)
      Com_RxDlMon_Indication(ComRxPduId);
# endif
# if (COM_RXNHDLR == STD_ON)
#  if ((COM_RXNHDLR_NOTIFICATIONFUNCTION == STD_ON) || ((COM_RXNHDLR_TIMEOUTFLAG == STD_ON) && (COM_RESET_TIMEOUTFLAG == STD_ON)) || (COM_RXNHDLR_NOTIFICATIONFLAG == STD_ON))
#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
      Com_RxNHdlr_Indication(ComRxPduId, pduLength);
#   else
      Com_RxNHdlr_Indication(ComRxPduId);
#   endif
#  endif
# endif /* COM_RXNHDLR == STD_ON */
# if (COM_RXUBHDLR == STD_ON)
#  if ((COM_RXUBHDLR_NOTIFICATIONFUNCTION == STD_ON) || (COM_RXUBHDLR_NOTIFICATIONFLAG == STD_ON) || (COM_RXUBHDLR_TIMEOUT == STD_ON))
#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
      Com_RxUbHdlr_Indication(ComRxPduId, pduLength);
#   else
      Com_RxUbHdlr_Indication(ComRxPduId);
#   endif
#  endif
# endif
# if (COM_SIGNALGW == STD_ON)
#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
      Com_SignalGw_Indication(ComRxPduId, pduLength);
#  else
      Com_SignalGw_Indication(ComRxPduId);
#  endif
# endif
    }
  }
}                               /* End of Com_RxIndication() */

# if (COM_TPINTERFACE == STD_ON)
FUNC(BufReq_ReturnType, COM_CODE) Com_TpProvideRxBuffer(PduIdType ComRxPduId, PduLengthType TpSduLength,
                                                        P2VAR(PduInfoTypeApplPtr, AUTOMATIC, COM_APPL_VAR) PduInfoPtr)
{
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_NOINIT) pPduInfo;

  Com_LMgt_CheckDetErrorReturnValue((Com_GetStatus() == COM_INIT), COMServiceId_TpProvideRxBuffer, COM_E_UNINIT,
                                    BUFREQ_E_NOT_OK);
  Com_LMgt_CheckDetErrorReturnValue((ComRxPduId < Com_RxBuffer_GetRxIpduCnt()), COMServiceId_TpProvideRxBuffer,
                                    COM_E_PARAM, BUFREQ_E_NOT_OK);
  Com_LMgt_CheckDetErrorReturnValue((Com_RxBuffer_GetIpduLength(ComRxPduId) >= TpSduLength),
                                    COMServiceId_TpProvideRxBuffer, COM_E_PARAM, BUFREQ_E_NOT_OK);
  Com_LMgt_CheckDetErrorReturnValue((PduInfoPtr != NULL_PTR), COMServiceId_TpProvideRxBuffer, COM_E_PARAM,
                                    BUFREQ_E_NOT_OK);

  pPduInfo = &(com_RxLLIf_TpPduInfo[ComRxPduId]);

  /* Shadow buffer */
  pPduInfo->SduDataPtr = Com_RxBuffer_GetIpduDataPtr(ComRxPduId) + Com_RxBuffer_GetIpduLength(ComRxPduId);

  pPduInfo->SduLength = TpSduLength;
  *PduInfoPtr = pPduInfo;

  return BUFREQ_OK;
}                               /* End of Com_TpProvideRxBuffer() */


FUNC(void, COM_CODE) Com_TpRxIndication(PduIdType ComRxPduId, NotifResultType Result)
{
  Com_LMgt_CheckDetErrorReturnVoid((ComRxPduId < Com_RxBuffer_GetRxIpduCnt()), COMServiceId_TpRxIndication,
                                   COM_E_PARAM);
  Com_LMgt_CheckDetErrorReturnVoid((Result <= 0x78), COMServiceId_TpRxIndication, COM_E_PARAM);

  if (NTFRSLT_OK == Result)
  {
    /* Copy data from the shadow buffer to the internal buffer using the standard indication mechanism */
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) pShadowBuffer =
      Com_RxBuffer_GetIpduDataPtr(ComRxPduId) + Com_RxBuffer_GetIpduLength(ComRxPduId);
    Com_RxIndication(ComRxPduId, pShadowBuffer);
  }
}                               /* End of Com_TpRxIndication() */
# endif
#endif /* COM_RXLLIF == STD_ON */
/* KB end Com_RxLLIf_GlobalFunctions */
/* KB begin Com_RxNHdlr_GlobalFunctions */
#if ((COM_RXNHDLR_RXFILTER == STD_ON) && (COM_RXSIGNAL_ACCESS_MACRO_API == STD_OFF))
# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
FUNC(void, COM_CODE) Com_RxNHdlr_EvaluateFilter(PduIdType ComRxPduId,
                                                P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) NewIpduBufPtr,
                                                PduLengthType ComPduLength)
# else
FUNC(void, COM_CODE) Com_RxNHdlr_EvaluateFilter(PduIdType ComRxPduId,
                                                P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) NewIpduBufPtr)
# endif
{
  uint32 NewSignalData;
  uint32 OldSignalData;
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) OldIpduBufPtr = Com_RxBuffer_GetIpduDataPtr(ComRxPduId);
  Com_SignalIdType SignalId;
  Com_Signal_AccessAttrType AccessAttr;
# if ((COM_RXNHDLR_RXFILTER_SIGNOTIFUNC == STD_ON) || (COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON))
  Com_RxNHdlr_NotificationIdxType NotificationIdx;
# endif
# if ((COM_RXNHDLR_RXFILTER_SIGINDFLAG == STD_ON) || (COM_RXNHDLR_RXFILTER_SIGGRPINDFLAG == STD_ON))
  Com_RxNHdlr_NotiFlagIdType NotificationFlagIdx;
# endif

# if ((COM_RXNHDLR_RXFILTER_SIGNOTIFUNC == STD_ON) || (COM_RXNHDLR_RXFILTER_SIGINDFLAG == STD_ON))
  {
    Com_RxNHdlr_FilterSigIdxType FilterSigIdx = Com_RxNHdlr_IPdu2FilterSigs[ComRxPduId];
    Com_RxNHdlr_FilterSigIdxType FilterSigStopIdx = Com_RxNHdlr_IPdu2FilterSigs[ComRxPduId + 1];

#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
    for (;
         ((FilterSigIdx < FilterSigStopIdx)
          && (Com_ConfigValue(Com_RxNHdlr_FilterSigInfo)[FilterSigIdx].validDlc <= ComPduLength)); FilterSigIdx++)
#  else
    for (; FilterSigIdx < FilterSigStopIdx; FilterSigIdx++)
#  endif
    {
      SignalId = Com_RxNHdlr_FilterSigInfo[FilterSigIdx].signalId;
      AccessAttr = Com_Signal_GetSignalAttribute(SignalId, AccessAttributes);
#  if (COM_RXNHDLR_RXFILTER_SIGNOTIFUNC == STD_ON)
      NotificationIdx = Com_RxNHdlr_FilterSigInfo[FilterSigIdx].notificationIdx;
      Com_LMgt_CheckFatalErrorRetVoid((NotificationIdx < Com_RxNHdlr_GetNotificationCnt()),
                                      Com_RxNHdlr_NotiFuncIdxTooLarge);
#  endif
#  if (COM_RXNHDLR_RXFILTER_SIGINDFLAG == STD_ON)
      NotificationFlagIdx = Com_RxNHdlr_FilterSigInfo[FilterSigIdx].notificationFlagIdx;
#  endif

      NewSignalData = (uint32) 0;
      OldSignalData = (uint32) 0;
      Com_Signal_ReadSignal(SignalId, &NewSignalData, &NewIpduBufPtr[Com_Signal_GetSignalStartByte(SignalId)],
                            AccessAttr);
      Com_Signal_ReadSignal(SignalId, &OldSignalData, &OldIpduBufPtr[Com_Signal_GetSignalStartByte(SignalId)],
                            AccessAttr);

      if (NewSignalData == OldSignalData)
      {
#  if (COM_RXNHDLR_RXFILTER_SIGNOTIFUNC == STD_ON)
        Com_RxNHdlr_SetInhibitNotification(NotificationIdx);
#  endif
#  if (COM_RXNHDLR_RXFILTER_SIGINDFLAG == STD_ON)
#   if (COM_RXNHDLR_RXFILTER_SIGNOTIFUNC == STD_ON)
        if (COM_RX_NHDLR_NONOTIFLAG != NotificationFlagIdx)
#   endif
        {
          Com_LMgt_CheckFatalErrorRetVoid((NotificationFlagIdx < Com_RxNHdlr_GetNotificationFlagCnt()),
                                          Com_RxNHdlr_NotiFlagIdxTooLarge);
          Com_RxNHdlr_SetInhibitNotificationFlag(NotificationFlagIdx);
        }
#  endif
      }
      else
      {
#  if (COM_RXNHDLR_RXFILTER_SIGNOTIFUNC == STD_ON)
        Com_RxNHdlr_ClrInhibitNotification(NotificationIdx);
#  endif
#  if (COM_RXNHDLR_RXFILTER_SIGINDFLAG == STD_ON)
#   if (COM_RXNHDLR_RXFILTER_SIGNOTIFUNC == STD_ON)
        if (COM_RX_NHDLR_NONOTIFLAG != NotificationFlagIdx)
#   endif
        {
          Com_LMgt_CheckFatalErrorRetVoid((NotificationFlagIdx < Com_RxNHdlr_GetNotificationFlagCnt()),
                                          Com_RxNHdlr_NotiFlagIdxTooLarge);
          Com_RxNHdlr_ClrInhibitNotificationFlag(NotificationFlagIdx);
        }
#  endif
      }
    }
  }
# endif /* ((COM_RXNHDLR_RXFILTER_SIGNOTIFUNC == STD_ON) || (COM_RXNHDLR_RXFILTER_SIGINDFLAG == STD_ON)) */

# if ((COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON) || (COM_RXNHDLR_RXFILTER_SIGGRPINDFLAG == STD_ON))
  {
    Com_RxNHdlr_FilterSigGrpIdxType FilterSigGrpIdx = Com_RxNHdlr_IPdu2FilterSigGrps[ComRxPduId];
    Com_RxNHdlr_FilterSigGrpIdxType FilterSigGrpStopIdx = Com_RxNHdlr_IPdu2FilterSigGrps[ComRxPduId + 1];
#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
    for (;
         ((FilterSigGrpIdx < FilterSigGrpStopIdx)
          && (Com_ConfigValue(Com_RxNHdlr_FilterSigGrpInfo)[FilterSigGrpIdx].validDlc <= ComPduLength));
         FilterSigGrpIdx++)
#  else
    for (; FilterSigGrpIdx < FilterSigGrpStopIdx; FilterSigGrpIdx++)
#  endif
    {
      boolean SignalDataFilterPassed = FALSE;
#  if (COM_RXNHDLR_RXFILTER_GRPSIG == STD_ON)
      Com_RxNHdlr_FilterGrpSigIdxType FilterGrpSigIdx = Com_RxNHdlr_FilterSigGrpInfo[FilterSigGrpIdx].grpSigIdx;
      Com_RxNHdlr_FilterGrpSigIdxType FilterGrpSigStopIdx = Com_RxNHdlr_FilterSigGrpInfo[FilterSigGrpIdx + 1].grpSigIdx;
      for (; FilterGrpSigIdx < FilterGrpSigStopIdx; FilterGrpSigIdx++)
      {
        SignalId = Com_RxNHdlr_FilterGrpSigIndirection[FilterGrpSigIdx];
        AccessAttr = Com_Signal_GetSignalAttribute(SignalId, AccessAttributes);

        NewSignalData = (uint32) 0;
        OldSignalData = (uint32) 0;
        Com_Signal_ReadSignal(SignalId, &NewSignalData, &NewIpduBufPtr[Com_Signal_GetSignalStartByte(SignalId)],
                              AccessAttr);
        Com_Signal_ReadSignal(SignalId, &OldSignalData, &OldIpduBufPtr[Com_Signal_GetSignalStartByte(SignalId)],
                              AccessAttr);

        if (NewSignalData != OldSignalData)
        {
          SignalDataFilterPassed = TRUE;
          break;
        }
#  endif /* (COM_RXNHDLR_RXFILTER_GRPSIG == STD_ON) */
      }
#  if (COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON)
      NotificationIdx = Com_RxNHdlr_FilterSigGrpInfo[FilterSigGrpIdx].notificationIdx;
      Com_LMgt_CheckFatalErrorRetVoid((NotificationIdx < Com_RxNHdlr_GetNotificationCnt()),
                                      Com_RxNHdlr_NotiFuncIdxTooLarge);
#  endif
#  if (COM_RXNHDLR_RXFILTER_SIGGRPINDFLAG == STD_ON)
      NotificationFlagIdx = Com_RxNHdlr_FilterSigGrpInfo[FilterSigGrpIdx].notificationFlagIdx;
#  endif

      if (FALSE == SignalDataFilterPassed)
      {
#  if (COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON)
        Com_RxNHdlr_SetInhibitNotification(NotificationIdx);
#  endif /* (COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON) */
#  if (COM_RXNHDLR_RXFILTER_SIGGRPINDFLAG == STD_ON)
#   if (COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON)
        if (COM_RX_NHDLR_NONOTIFLAG != NotificationFlagIdx)
#   endif /* (COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON) */
        {
          Com_LMgt_CheckFatalErrorRetVoid((NotificationFlagIdx < Com_RxNHdlr_GetNotificationFlagCnt()),
                                          Com_RxNHdlr_NotiFlagIdxTooLarge);
          Com_RxNHdlr_SetInhibitNotificationFlag(NotificationFlagIdx);
        }
#  endif /* (COM_RXNHDLR_RXFILTER_SIGGRPINDFLAG == STD_ON) */
      }
      else
      {
#  if (COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON)
        Com_RxNHdlr_ClrInhibitNotification(NotificationIdx);
#  endif
#  if (COM_RXNHDLR_RXFILTER_SIGGRPINDFLAG == STD_ON)
#   if (COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON)
        if (COM_RX_NHDLR_NONOTIFLAG != NotificationFlagIdx)
#   endif
        {
          Com_LMgt_CheckFatalErrorRetVoid((NotificationFlagIdx < Com_RxNHdlr_GetNotificationFlagCnt()),
                                          Com_RxNHdlr_NotiFlagIdxTooLarge);
          Com_RxNHdlr_ClrInhibitNotificationFlag(NotificationFlagIdx);
        }
#  endif /* (COM_RXNHDLR_RXFILTER_SIGGRPINDFLAG == STD_ON) */
      }
    }
  }
# endif /* ((COM_RXNHDLR_RXFILTER_SIGGRPNOTIFUNC == STD_ON) || (COM_RXNHDLR_RXFILTER_SIGGRPINDFLAG == STD_ON)) */
}
#endif /* ((COM_RXNHDLR_RXFILTER == STD_ON) && (COM_RXSIGNAL_ACCESS_MACRO_API == STD_OFF)) */
/* KB end Com_RxNHdlr_GlobalFunctions */
/* KB begin Com_RxSigIf_GlobalFunctions */
#if (COM_RXSIGIF == STD_ON)
# if ((COM_SIGNALIF == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API != STD_ON))
FUNC(uint8, COM_CODE) Com_ReceiveSignal(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr)
{
  PduIdType ComPduId;
  uint8 retVal = E_OK;

#  if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
  SignalId = Com_ConfigValue(Com_Signal_Ext2IntSignalId)[SignalId];
#  endif

  ComPduId = Com_Signal_GetIpduFromSignal(SignalId);

  Com_LMgt_CheckDetErrorReturnValue((Com_GetStatus() == COM_INIT), COMServiceId_ReceiveSignal, COM_E_UNINIT,
                                    COM_SERVICE_NOT_AVAILABLE);
  Com_LMgt_CheckDetErrorReturnValue((SignalId < Com_Signal_GetSignalCnt()), COMServiceId_ReceiveSignal, COM_E_PARAM,
                                    COM_SERVICE_NOT_AVAILABLE);
  Com_LMgt_CheckDetErrorReturnValue((SignalDataPtr != NULL_PTR), COMServiceId_ReceiveSignal, COM_E_PARAM,
                                    COM_SERVICE_NOT_AVAILABLE);
  Com_LMgt_CheckDetErrorReturnValue((ComPduId <
                                     ((SignalId <
                                       Com_Signal_GetRxSignalCnt())? Com_RxBuffer_GetRxIpduCnt() :
                                      Com_TxBuffer_GetTxIpduCnt())), COMServiceId_Il_AsrComInternal,
                                    Com_ReceiveSignal_PduId, COM_SERVICE_NOT_AVAILABLE);

  if ((SignalId < Com_Signal_GetRxSignalCnt()))
  {
    if (!Com_LMgt_RxIpduActive(ComPduId))
    {
      retVal = COM_SERVICE_NOT_AVAILABLE;
    }
    /* read the rx signal data */
    Com_RxBuffer_ReadIpduSignal(SignalId, ComPduId, SignalDataPtr);
  }
  else
  {
    if (!Com_LMgt_TxIpduActive(ComPduId))
    {
      retVal = COM_SERVICE_NOT_AVAILABLE;
    }
    /* read the tx signal data */
    Com_TxBuffer_ReadIpduSignal(SignalId, ComPduId, SignalDataPtr);
  }

  return retVal;
}                               /* End of Com_ReceiveSignal() */
# endif /* ((COM_SIGNALIF == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API != STD_ON)) */

# if ((COM_SIGNALGROUPIF == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API != STD_ON))
FUNC(void, COM_CODE) Com_ReceiveShadowSignal(Com_SignalIdType SignalId,
                                             P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr)
{
  Com_SignalGroupIdType sigGrp = Com_Signal_GetSignalGroupFromSignal(SignalId);
#  if (COM_DEV_ERROR_DETECT == STD_ON)
  PduIdType ComPduId = Com_Signal_GetIpduFromSignal(SignalId);
#  endif
#  if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
  SignalId = Com_ConfigValue(Com_Signal_Ext2IntSignalId)[SignalId];
#  endif

  Com_LMgt_CheckDetErrorReturnVoid((Com_GetStatus() == COM_INIT), COMServiceId_ReceiveShadowSignal, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((SignalId < Com_Signal_GetSignalCnt()), COMServiceId_ReceiveShadowSignal,
                                   COM_E_PARAM);
  Com_LMgt_CheckDetErrorReturnVoid((SignalDataPtr != NULL_PTR), COMServiceId_ReceiveShadowSignal, COM_E_PARAM);
  Com_LMgt_CheckDetErrorReturnVoid((sigGrp < Com_Signal_GetSignalGroupCnt()), COMServiceId_ReceiveShadowSignal,
                                   COM_E_PARAM);
#  if (COM_DEV_ERROR_DETECT == STD_ON)
  if (SignalId < Com_Signal_GetRxSignalCnt())
  {
    Com_LMgt_CheckDetErrorReturnVoid(ComPduId < Com_RxBuffer_GetRxIpduCnt(), COMServiceId_Il_AsrComInternal,
                                     Com_ReceiveShadowSignal_PduId);
  }
  else
  {
    Com_LMgt_CheckDetErrorReturnVoid(ComPduId < Com_TxBuffer_GetTxIpduCnt(), COMServiceId_Il_AsrComInternal,
                                     Com_ReceiveShadowSignal_PduId);
  }
#  endif

  Com_Buffer_ReadShadowSignal(SignalId, SignalDataPtr, Com_Signal_GetSignalGroupBufferPtr(sigGrp));

}                               /* End of Com_ReceiveShadowSignal() */
# endif /* ((COM_SIGNALGROUPIF == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API != STD_ON)) */

# if (COM_SIGNALGROUPIF == STD_ON)
#  if (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF)
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId)
#  else
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupAsMacro(Com_SignalGroupIdType SignalGroupId)
#  endif
{
  PduIdType ComPduId = Com_Signal_GetIpduFromSignalGroup(SignalGroupId);
  uint8 retVal = E_OK;
#  if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
  SignalGroupId = Com_ConfigValue(Com_Signal_Ext2IntSignalGroupId)[SignalGroupId];
#  endif

  Com_LMgt_CheckDetErrorReturnValue((Com_GetStatus() == COM_INIT), COMServiceId_ReceiveSignalGroup, COM_E_UNINIT,
                                    COM_SERVICE_NOT_AVAILABLE);
  Com_LMgt_CheckDetErrorReturnValue((SignalGroupId < Com_Signal_GetSignalGroupCnt()), COMServiceId_ReceiveSignalGroup,
                                    COM_E_PARAM, COM_SERVICE_NOT_AVAILABLE);

  if ((SignalGroupId < Com_Signal_GetRxSignalGroupCnt()))
  {
    Com_LMgt_CheckDetErrorReturnValue(ComPduId < Com_RxBuffer_GetRxIpduCnt(), COMServiceId_Il_AsrComInternal,
                                      Com_ReceiveSignalGroup_PduId, COM_SERVICE_NOT_AVAILABLE);

    if (!Com_LMgt_RxIpduActive(ComPduId))
    {
      retVal = COM_SERVICE_NOT_AVAILABLE;
    }
    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
    /* read the rx signal group data */
    Com_RxBuffer_ReadSignalGroup(SignalGroupId, ComPduId, Com_Signal_GetSignalGroupBufferPtr(SignalGroupId));
  }
  else
  {
    Com_LMgt_CheckDetErrorReturnValue(ComPduId < Com_TxBuffer_GetTxIpduCnt(), COMServiceId_Il_AsrComInternal,
                                      Com_ReceiveSignalGroup_PduId, COM_SERVICE_NOT_AVAILABLE);

    if (!Com_LMgt_TxIpduActive(ComPduId))
    {
      retVal = COM_SERVICE_NOT_AVAILABLE;
    }
    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
    /* read the tx signal group data */
    Com_TxBuffer_ReadSignalGroup(SignalGroupId, ComPduId, Com_Signal_GetSignalGroupBufferPtr(SignalGroupId));
  }
  SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);

  return retVal;
}                               /* End of Com_ReceiveSignalGroup() */
# endif

# if (COM_SIGNAL_ACCESS_MACRO_API == STD_ON) && (COM_APPLTYPE_UINT8N == STD_ON)
FUNC(void, COM_CODE) Com_RxSigIf_ReceiveByteArray(PduIdType ComPduId,
                                                  P2VAR(uint8, AUTOMATIC, COM_APPL_VAR) SignalDataPtr, P2CONST(uint8,
                                                                                                               AUTOMATIC,
                                                                                                               COM_VAR_NOINIT)
                                                  BufferDataPtr, uint16 count)
{
  while (count > (uint16) 0x0000)
  {
    count--;
    SignalDataPtr[count] = BufferDataPtr[count];
  }
}
# endif

#endif /* COM_RXSIGIF == STD_ON */
/* KB end Com_RxSigIf_GlobalFunctions */
/* KB begin Com_RxUbHdlr_GlobalFunctions */
/* KB end Com_RxUbHdlr_GlobalFunctions */
/* KB begin Com_RxInv_GlobalFunctions */
/* KB end Com_RxInv_GlobalFunctions */
/* KB begin Com_TxInv_GlobalFunctions */
#if ((COM_TXINV == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF) && (COM_SIGNALIF == STD_ON))
FUNC(uint8, COM_CODE) Com_InvalidateSignal(Com_SignalIdType SignalId)
{
  Com_Signal_AccessAttrType AccessAttr = Com_Signal_GetSignalAttribute((SignalId), AccessAttributes);
  uint8 retVal = COM_SERVICE_NOT_AVAILABLE;
# if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
  SignalId = Com_ConfigValue(Com_Signal_Ext2IntSignalId)[SignalId];
# endif/* (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON) */

  Com_LMgt_CheckDetErrorReturnValue((SignalId >= Com_Signal_GetRxSignalCnt()), COMServiceId_InvalidateSignal,
                                    COM_E_PARAM, COM_SERVICE_NOT_AVAILABLE);

  if (COM_SIGNAL_NOINVALIDVALUE != Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl))
  {
# if ((COM_APPLTYPE_BOOLEAN == STD_ON) || (COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT8N == STD_ON))
    if ((COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsBoolean(AccessAttr))
        || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint8(AccessAttr))
        || (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsUint8_N(AccessAttr)))
    {
      retVal =
        Com_SendSignal(SignalId,
                       &Com_ConfigValue(Com_8BitValue)[Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)]);
    }
    else
# endif/* ((COM_APPLTYPE_BOOLEAN == STD_ON) || (COM_APPLTYPE_UINT8 == STD_ON) || (COM_APPLTYPE_SINT8 == STD_ON) || (COM_APPLTYPE_UINT8N == STD_ON)) */
# if ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint16(AccessAttr))
    {
      retVal =
        Com_SendSignal(SignalId,
                       &Com_ConfigValue(Com_16BitValue)[Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)]);
    }
    else
# endif/* ((COM_APPLTYPE_UINT16 == STD_ON) || (COM_APPLTYPE_SINT16 == STD_ON)) */
# if ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))
    if (COM_SIGNAL_FALSE != Com_Signal_ApplTypeIsXint32(AccessAttr))
    {
      retVal =
        Com_SendSignal(SignalId,
                       &Com_ConfigValue(Com_32BitValue)[Com_Signal_GetSignalAttribute(SignalId, InvalidValueHdl)]);
    }
    else
# endif/* ((COM_APPLTYPE_UINT32 == STD_ON) || (COM_APPLTYPE_SINT32 == STD_ON))   */
    {
      Com_LMgt_CallFatalError(Com_Signal_UnsupportedBusSignalType);
    }
  }
  else
  {
    Com_LMgt_CallDetErrorReturnValue(COMServiceId_InvalidateSignal, COM_E_PARAM, COM_SERVICE_NOT_AVAILABLE);
  }
  return retVal;
}
#endif /* ((COM_TXINV == STD_ON) && (COM_SIGNAL_ACCESS_MACRO_API == STD_OFF) && (COM_SIGNALIF == STD_ON)) */
/* KB end Com_TxInv_GlobalFunctions */
/* KB begin Com_TxBuffer_GlobalFunctions */
/* KB end Com_TxBuffer_GlobalFunctions */
/* KB begin Com_TxDlMon_GlobalFunctions */
/* KB end Com_TxDlMon_GlobalFunctions */
/* KB begin Com_TxLLIf_GlobalFunctions */
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType ComTxPduId)
{
#if (COM_TXNHDLR_EMULATION == STD_OFF)
  Com_LMgt_CheckDetErrorReturnVoid((Com_GetStatus() == COM_INIT), COMServiceId_TxConfirmation, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), COMServiceId_TxConfirmation,
                                   COM_E_PARAM);

# if (COM_TSI_TESTCODE == STD_ON)
/* ##V_TEST_CODE_START ##visdbi */
  if (wTsiIl_AsrComTxConfirmationPduId != ComTxPduId)
/* ##V_TEST_CODE_END ##visdbi */
# endif/* (COM_TSI_TESTCODE == STD_ON) */
  {
    if (Com_LMgt_TxIpduActive(ComTxPduId))
    {
# if (COM_TXDLMON == STD_ON)
      Com_TxDlMon_Confirmation(ComTxPduId);
# endif /* (COM_TXDLMON == STD_ON) */
# if (COM_TXMODEHDLR == STD_ON) && ((COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) || (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON))
      if (TRUE == Com_TxModeHdlr_Confirmation(ComTxPduId))
# endif
      {
# if (COM_TXNHDLR == STD_ON) && ((COM_TXCONFIRMATION_DEFERRED == STD_ON) || (COM_TXCONFIRMATION_IMMEDIATE == STD_ON))
        Com_TxNHdlr_Confirmation(ComTxPduId);
# endif
      }
    }
  }
#endif
}                               /* End of Com_TxConfirmation() */

#if ( COM_TXLLIF == STD_ON )
# if (COM_TRIGGER_TRANSMIT_API == STD_ON)
#  if(COM_USE_PDUINFOTYPE == STD_ON)
#   define COM_TT_DATAPTR      (*COM_TT_PARA).SduDataPtr
#  else
#   define COM_TT_DATAPTR      COM_TT_PARA
#  endif
FUNC(COM_TT_RETURN, COM_CODE) Com_TriggerTransmit(PduIdType ComTxPduId, COM_TT_TYPE COM_TT_PARA)
{
  PduInfoType PduInfo;

#  if (COM_USE_PDUINFOTYPE == STD_ON)
  Com_LMgt_CheckDetErrorReturnValue((Com_GetStatus() == COM_INIT), COMServiceId_TriggerTransmit, COM_E_UNINIT,
                                    E_NOT_OK);
  Com_LMgt_CheckDetErrorReturnValue((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), COMServiceId_TriggerTransmit,
                                    COM_E_PARAM, E_NOT_OK);
  Com_LMgt_CheckDetErrorReturnValue((COM_TT_PARA != NULL_PTR), COMServiceId_TriggerTransmit, COM_E_PARAM, E_NOT_OK);
#  else
  Com_LMgt_CheckDetErrorReturnVoid((Com_GetStatus() == COM_INIT), COMServiceId_TriggerTransmit, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), COMServiceId_TriggerTransmit,
                                   COM_E_PARAM);
  Com_LMgt_CheckDetErrorReturnVoid((COM_TT_PARA != NULL_PTR), COMServiceId_TriggerTransmit, COM_E_PARAM);
#  endif

  PduInfo.SduDataPtr = Com_TxBuffer_GetIpduDataPtr(ComTxPduId);
  PduInfo.SduLength = Com_TxBuffer_GetIpduLength(ComTxPduId);
#  if (COM_USE_PDUINFOTYPE == STD_ON)
  Com_LMgt_CheckFatalErrorRetValue((PduInfo.SduDataPtr != NULL_PTR), Com_TriggerTransmit_PduInfoNullPointer, E_NOT_OK);
#  else
  Com_LMgt_CheckFatalErrorRetVoid((PduInfo.SduDataPtr != NULL_PTR), Com_TriggerTransmit_PduInfoNullPointer);
#  endif

#  if (COM_TXPDUCALLOUT == STD_ON)
  {
    Com_TxLLIf_PduCalloutIdType CalloutId = Com_ConfigValue(Com_TxLLIf_PduCalloutIndirection)[ComTxPduId];
    if (COM_TXLLIF_NO_PDUCALLOUT != CalloutId)
    {
		/* Vector ComTxPduCallout workaround */
		ComTxPduCallout_lgc = TRUE;

      (void) Com_TxLLIf_PduCallout[CalloutId] (ComTxPduId, (COM_TXCALLOUT_TYPE) COM_APPLTXCALLOUT_PARA);
     	
		ComTxPduCallout_lgc = FALSE;
    }
  }
#  endif /* (COM_TXPDUCALLOUT == STD_ON) */

  SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);

  Com_LMgt_MemCpyRamToRam(COM_TT_DATAPTR, PduInfo.SduDataPtr, PduInfo.SduLength);
#  if (COM_TXUBHDLR == STD_ON)
  Com_TxBuffer_ClearMaskedBits(ComTxPduId, Com_TxLLIf_GetIpduClearUbMask(ComTxPduId));
#  endif
  SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);

#  if (COM_USE_PDUINFOTYPE == STD_ON)
  (*COM_TT_PARA).SduLength = PduInfo.SduLength;
#  endif

#  if (COM_TXNHDLR == STD_OFF) && (COM_TXNHDLR_EMULATION == STD_ON)
  if (Com_LMgt_TxIpduActive(ComTxPduId))
  {
#   if (COM_TXDLMON == STD_ON)
    Com_TxDlMon_Confirmation(ComTxPduId);
#   endif /* (COM_TXDLMON == STD_ON) */
#   if (COM_TXMODEHDLR == STD_ON) && ((COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) || (COM_TXMODEHDLR_DIRECT_REPETITION == STD_ON))
    (void) Com_TxModeHdlr_Confirmation(ComTxPduId);
#   endif
  }
#  endif
#  if (COM_USE_PDUINFOTYPE == STD_ON)
  return E_OK;
#  endif
}                               /* End of Com_TriggerTransmit() */
# endif /* COM_TRIGGER_TRANSMIT_API == STD_ON */

# if (COM_TPINTERFACE == STD_ON)
FUNC(BufReq_ReturnType, COM_CODE) Com_TpProvideTxBuffer(PduIdType ComTxPduId,
                                                        P2VAR(PduInfoTypeApplPtr, AUTOMATIC, COM_APPL_VAR) PduInfoPtr,
                                                        uint16 Length)
{
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR_NOINIT) pPduInfo;

  Com_LMgt_CheckDetErrorReturnValue((Com_GetStatus() == COM_INIT), COMServiceId_TpProvideTxBuffer, COM_E_UNINIT,
                                    BUFREQ_E_NOT_OK);
  Com_LMgt_CheckDetErrorReturnValue((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), COMServiceId_TpProvideTxBuffer,
                                    COM_E_PARAM, BUFREQ_E_NOT_OK);
  Com_LMgt_CheckDetErrorReturnValue((((uint16) 0x00u == Length)
                                     || (Com_TxBuffer_GetIpduLength(ComTxPduId) >= Length)),
                                    COMServiceId_TpProvideTxBuffer, COM_E_PARAM, BUFREQ_E_NOT_OK);
  Com_LMgt_CheckDetErrorReturnValue((PduInfoPtr != NULL_PTR), COMServiceId_TpProvideTxBuffer, COM_E_PARAM,
                                    BUFREQ_E_NOT_OK);

  pPduInfo = &(com_TxLLIf_TpPduInfo[ComTxPduId].pduInfo);
  com_TxLLIf_TpPduInfo[ComTxPduId].lockedForTpTx = TRUE;
  /* Shadow buffer */
  pPduInfo->SduDataPtr = Com_TxBuffer_GetIpduDataPtr(ComTxPduId) + Com_TxBuffer_GetIpduLength(ComTxPduId);
  pPduInfo->SduLength = Com_TxBuffer_GetIpduLength(ComTxPduId);
  *PduInfoPtr = pPduInfo;

#  if (COM_DEV_ERROR_DETECT == STD_OFF)
#   if (COM_USE_DUMMY_STATEMENT == STD_ON)
  Length = Length;
#   endif
#  endif

  return BUFREQ_OK;
}                               /* End of Com_TpProvideTxBuffer() */

FUNC(void, COM_CODE) Com_TpTxConfirmation(PduIdType ComTxPduId, NotifResultType Result)
{
  Com_LMgt_CheckDetErrorReturnVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()), COMServiceId_TpTxConfirmation,
                                   COM_E_PARAM);
  Com_LMgt_CheckDetErrorReturnVoid((Result <= 0x78), COMServiceId_TpTxConfirmation, COM_E_PARAM);

  com_TxLLIf_TpPduInfo[ComTxPduId].lockedForTpTx = FALSE;

  if (NTFRSLT_OK == Result)
  {
    Com_TxConfirmation(ComTxPduId);
  }
}                               /* End of Com_TpTxConfirmation() */
# endif /* COM_TPINTERFACE == STD_ON */
#endif /* COM_TXLLIF == STD_ON */

#if (COM_TSI_TESTCODE == STD_ON)
/* ##V_TEST_CODE_START ##visdbi */
FUNC(void, COM_CODE) Com_TxLLIf_InhibitTxConfirmation(PduIdType ComTxPduId)
{
  wTsiIl_AsrComTxConfirmationPduId = ComTxPduId;
}

/* ##V_TEST_CODE_END ##visdbi */
#endif /* (COM_TSI_TESTCODE == STD_ON) */
/* KB end Com_TxLLIf_GlobalFunctions */
/* KB begin Com_TxModeHdlr_GlobalFunctions */
#if (COM_TXMODEHDLR == STD_ON)
# if (COM_TSI_TESTCODE == STD_ON) || (COM_SIGNALGW_CANMOST == STD_ON)
FUNC(void, COM_CODE) Com_TxModeHdlr_StopCyclicTransmission(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()),
                                  Com_TxModeHdlr_Param_StopCyclicTransmission);
  if (Com_LMgt_TxIpduActive(ComTxPduId))
  {
    Com_TxModeHdlr_Stop(ComTxPduId);
#  if (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON)
    com_TxModeHdlr_CyclicSendRequest[ComTxPduId] = FALSE;
#  endif /* (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON) */
  }
}                               /* End of Com_TxModeHdlr_StopCyclicTransmission() */
# endif /* (COM_TSI_TESTCODE == STD_ON) || (COM_SIGNALGW_CANMOST == STD_ON) */

# if (COM_TSI_TESTCODE == STD_ON)
/* ##V_TEST_CODE_START ##Ms */
FUNC(void, COM_CODE) Com_TxModeHdlr_StartImmediateCyclicTransmission(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()),
                                  Com_TxModeHdlr_Param_StartImmediateCyclicTransmission);
  if (Com_LMgt_TxIpduActive(ComTxPduId))
  {
#  if (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON)
    com_TxModeHdlr_DelayTimeCnt[ComTxPduId] = (uint16) 0u;
#  endif /* (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) */
#  if (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON)
    com_TxModeHdlr_CyclicSendRequest[ComTxPduId] = TRUE;
#  endif /* (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON) */
  }
}                               /* End of Com_TxModeHdlr_StartImmediateCyclicTransmission() */

FUNC(void, COM_CODE) Com_TxModeHdlr_StartDeferredCyclicTransmission(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()),
                                  Com_TxModeHdlr_Param_StartDeferredCyclicTransmission);
  if (Com_LMgt_TxIpduActive(ComTxPduId))
  {
#  if (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON)
    com_TxModeHdlr_CycleTimeCnt[ComTxPduId] =
      Com_TxModeHdlr_GetTxModeParameter(ComTxPduId, COM_TXMODE_PARAM_TIMEOFFSET);
    com_TxModeHdlr_CyclicSendRequest[ComTxPduId] = TRUE;
#  endif /* (COM_TXMODEHDLR_CYCLIC_TRANSMISSION == STD_ON) */
#  if (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON)
    com_TxModeHdlr_DelayTimeCnt[ComTxPduId] = (uint16) 0u;
#  endif /* (COM_TXMODEHDLR_MINIMUM_DELAY == STD_ON) */
  }
}                               /* End of Com_TxModeHdlr_StartDeferredCyclicTransmission() */

FUNC(void, COM_CODE) Com_TxModeHdlr_TriggerImmediateIpduSend(CONST(PduIdType, AUTOMATIC) ComTxPduId)
{
  Com_LMgt_CheckFatalErrorRetVoid((ComTxPduId < Com_TxBuffer_GetTxIpduCnt()),
                                  Com_TxModeHdlr_Param_TriggerImmediateIpduSend);
  com_TxModeHdlr_TransmitRequest[ComTxPduId] = TRUE;
}                               /* End of Com_TxModeHdlr_TriggerImmediateIpduSend() */

/* ##V_TEST_CODE_END ##Ms */
# endif /* (COM_TSI_TESTCODE == STD_ON) */
#endif /* COM_TXMODEHDLR == STD_ON */
/* KB end Com_TxModeHdlr_GlobalFunctions */
/* KB begin Com_TxNHdlr_GlobalFunctions */
/* KB end Com_TxNHdlr_GlobalFunctions */
/* KB begin Com_TxSigIf_GlobalFunctions */
#if (COM_TXSIGIF == STD_ON)
# if (COM_SIGNALIF == STD_ON)
#  if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
#   if (COM_TXSIGNAL_ACCESS_MACRO_API != STD_ON)
FUNC(uint8, COM_CODE) Com_SendSignal(Com_SignalIdType SignalId, P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr)  /*lint -e818 [MISRA Rule 81]: Prototype is specified by AUTOSAR */
#   else
FUNC(uint8, COM_CODE) Com_SendSignalAsMacro(Com_SignalIdType SignalId, P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr)   /*lint -e818 [MISRA Rule 81]: Prototype is specified by AUTOSAR */
#   endif
{
#   if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
  return Com_TxSigIf_SendSignal(Com_ConfigValue(Com_Signal_Ext2IntSignalId)[SignalId], SignalDataPtr);
}

COM_STATIC FUNC(uint8, COM_CODE) Com_TxSigIf_SendSignal(Com_SignalIdType SignalId, P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr)       /*lint -e818 [MISRA Rule 81]: Prototype is specified by AUTOSAR */
{
#   endif/* (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON) */
  uint8 retVal = E_OK;
  PduIdType ComPduId = Com_Signal_GetIpduFromSignal(SignalId);

  Com_LMgt_CheckDetErrorReturnValue((Com_GetStatus() == COM_INIT), COMServiceId_SendSignal, COM_E_UNINIT,
                                    COM_SERVICE_NOT_AVAILABLE);
  Com_LMgt_CheckDetErrorReturnValue((SignalId < Com_Signal_GetSignalCnt()), COMServiceId_SendSignal, COM_E_PARAM,
                                    COM_SERVICE_NOT_AVAILABLE);
  Com_LMgt_CheckDetErrorReturnValue((SignalDataPtr != NULL_PTR), COMServiceId_SendSignal, COM_E_PARAM,
                                    COM_SERVICE_NOT_AVAILABLE);

  /* valid PduId range depends on whether the signal is a receive or a send signal */
  Com_LMgt_CheckDetErrorReturnValue((ComPduId <
                                     ((SignalId <
                                       Com_Signal_GetRxSignalCnt())? Com_RxBuffer_GetRxIpduCnt() :
                                      Com_TxBuffer_GetTxIpduCnt())), COMServiceId_Il_AsrComInternal,
                                    Com_SendSignal_PduId, COM_SERVICE_NOT_AVAILABLE);

#   if (COM_RXSIGNAL_WRACCESS == STD_ON)
  if (SignalId >= Com_Signal_GetRxSignalCnt())
#   else
  Com_LMgt_CheckDetErrorReturnValue((SignalId >= Com_Signal_GetRxSignalCnt()), COMServiceId_SendSignal, COM_E_PARAM,
                                    COM_SERVICE_NOT_AVAILABLE);
#   endif/* (COM_RXSIGNAL_WRACCESS == STD_ON) */
  {
    /* only for tx signals */
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF) || (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))
    boolean WriteData = TRUE;
#   endif
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
    Com_Signal_FilterHdlType ComSigFilter = Com_Signal_GetSignalAttribute(SignalId, FilterHdl);
#   endif
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || ((COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) && ((COM_TMS_SUPPORT == STD_OFF) || (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))))
    boolean FilterState = TRUE;
#   endif
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TXUBHDLR == STD_ON) || (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON))
    Com_SignalIdType TxSignalId = (SignalId - Com_Signal_GetRxSignalCnt());
#   endif
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
#    if (COM_F_NONE == STD_ON)
    if (COM_SIGNAL_F_NONE != ComSigFilter)
#    endif
    {
#    if ((COM_TXMODEHDLR_TMS == STD_ON) || ((COM_TMS_SUPPORT == STD_OFF) && (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)))
      FilterState = Com_Signal_ApplyFilter(SignalId, SignalDataPtr, ComSigFilter
#     if (COM_SIGNALGROUPIF == STD_ON)
                                           , (P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT)) NULL_PTR
#     endif
                                           , &WriteData);
#    else
      (void) Com_Signal_ApplyFilter(SignalId, SignalDataPtr, ComSigFilter
#     if (COM_SIGNALGROUPIF == STD_ON)
                                    , (P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT)) NULL_PTR
#     endif
                                    , &WriteData);
#    endif
#    if (COM_TXMODEHDLR_TMS == STD_ON)
      {
        uint16 FilterStateOffset = Com_ConfigValue(Com_TxSigIf_SignalFilterStateOffset)[TxSignalId];
        uint8 FilterStateMask = Com_ConfigValue(Com_TxSigIf_SignalFilterStateMask)[TxSignalId];
        Com_TxModeHdlr_UpdateTxMode(ComPduId, FilterStateOffset, FilterStateMask, FilterState);
      }
#    endif
    }
#   endif/* ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */
#   if ((COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))
    if (COM_TX_SIGIF_TRIGGERED_ON_CHANGE == Com_ConfigValue(Com_TxSigIf_SignalTransferEventProperty)[TxSignalId])
    {
      FilterState = Com_Signal_ApplyFilter(SignalId, SignalDataPtr, COM_SIGNAL_F_NEWISDIFFERENT
#    if (COM_SIGNALGROUPIF == STD_ON)
                                           , (P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT)) NULL_PTR
#    endif
                                           , &WriteData);
    }
#   endif/* ((COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON) && (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)) */
#   if (COM_TXUBHDLR == STD_ON)
    SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
    {
      Com_Signal_SignalBitPositionType ubBitPos = Com_ConfigValue(Com_TxSigIf_Signal2UbBitPos)[TxSignalId];

      if (ubBitPos != COM_TX_SIGIF_NOUPDATEBIT)
      {
        Com_TxBuffer_SetBit(ComPduId, ubBitPos);
      }
    }
#   endif/* (COM_TXUBHDLR == STD_ON) */
#   if ((COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF) || (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON))
    if (TRUE == WriteData)
#   endif
    {
      Com_TxBuffer_WriteIpduSignal(SignalId, ComPduId, SignalDataPtr);
    }
#   if (COM_TXUBHDLR == STD_ON)
    SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
#   endif/* (COM_TXUBHDLR == STD_ON) */

    if (Com_LMgt_TxIpduActive(ComPduId))
    {
#   if (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)
#    if (COM_TMS_SUPPORT == STD_OFF)
      if (TRUE == FilterState)
#    endif
      {
        if (COM_TX_SIGIF_TRIGGERED == Com_ConfigValue(Com_TxSigIf_SignalTransferEventProperty)[TxSignalId])
        {
          Com_TxModeHdlr_TriggerDeferredIpduSend(ComPduId);
        }
#    if (COM_TXSIGIF_TRIGGEREDONCHANGE == STD_ON)
        else if (COM_TX_SIGIF_TRIGGERED_ON_CHANGE ==
                 Com_ConfigValue(Com_TxSigIf_SignalTransferEventProperty)[TxSignalId])
        {
          if (TRUE == FilterState)
          {
            Com_TxModeHdlr_TriggerDeferredIpduSend(ComPduId);
          }
        }
#    endif/* (COM_TXSIGIF_TRIGGERED_ON_CHANGE == STD_ON) */
        else
        {
          /* Signal has PENDING transfer property */
        }
      }
#   endif
    }
    else
    {
      retVal = COM_SERVICE_NOT_AVAILABLE;
    }
  }
#   if (COM_RXSIGNAL_WRACCESS == STD_ON)
  else
  {
    /* for rx signals only the data must be updated */
    Com_RxBuffer_WriteIpduSignal(SignalId, ComPduId, SignalDataPtr);

    if (!Com_LMgt_RxIpduActive(ComPduId))
    {
      retVal = COM_SERVICE_NOT_AVAILABLE;
    }
  }
#   endif/* (COM_RXSIGNAL_WRACCESS == STD_ON) */
  return retVal;
}                               /* End of Com_SendSignal() */
#  endif /* ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */
# endif /* (COM_SIGNALIF == STD_ON) */

# if (COM_SIGNALGROUPIF == STD_ON)
#  if (COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF)
FUNC(uint8, COM_CODE) Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId)
#  else
FUNC(uint8, COM_CODE) Com_SendSignalGroupAsMacro(Com_SignalGroupIdType SignalGroupId)
#  endif
{
#  if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
  SignalGroupId = Com_ConfigValue(Com_Signal_Ext2IntSignalGroupId)[SignalGroupId];
#  endif /* (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON) */

  Com_LMgt_CheckDetErrorReturnValue((Com_GetStatus() == COM_INIT), COMServiceId_SendSignalGroup, COM_E_UNINIT,
                                    COM_SERVICE_NOT_AVAILABLE);
  Com_LMgt_CheckDetErrorReturnValue((SignalGroupId < Com_Signal_GetSignalGroupCnt()), COMServiceId_SendSignalGroup,
                                    COM_E_PARAM, COM_SERVICE_NOT_AVAILABLE);

  return Com_TxSigIf_SendSignalGroup(SignalGroupId, Com_Signal_GetSignalGroupBufferPtr(SignalGroupId));
}                               /* End of Com_SendSignalGroup() */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */

# if (COM_SIGNALGROUPIF == STD_ON)
#  if ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF))
#   if (COM_TXSIGNAL_ACCESS_MACRO_API == STD_ON)
FUNC(void, COM_CODE) Com_UpdateShadowSignalAsMacro(Com_SignalIdType SignalId,
                                                   P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr)
#   else
FUNC(void, COM_CODE) Com_UpdateShadowSignal(Com_SignalIdType SignalId,
                                            P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr)
#   endif
{
  Com_SignalGroupIdType sigGrp;

#   if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
  SignalId = Com_ConfigValue(Com_Signal_Ext2IntSignalId)[SignalId];
#   endif/* (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON) */

  Com_LMgt_CheckDetErrorReturnVoid((Com_GetStatus() == COM_INIT), COMServiceId_UpdateShadowSignal, COM_E_UNINIT);
  Com_LMgt_CheckDetErrorReturnVoid((SignalId < Com_Signal_GetSignalCnt()), COMServiceId_UpdateShadowSignal,
                                   COM_E_PARAM);
  Com_LMgt_CheckDetErrorReturnVoid((SignalDataPtr != NULL_PTR), COMServiceId_UpdateShadowSignal, COM_E_PARAM);

  sigGrp = Com_Signal_GetSignalGroupFromSignal(SignalId);
  Com_LMgt_CheckDetErrorReturnVoid((sigGrp < Com_Signal_GetSignalGroupCnt()), COMServiceId_UpdateShadowSignal,
                                   COM_E_PARAM);
  Com_TxSigIf_UpdateShadowSignal(SignalId, SignalDataPtr, Com_Signal_GetSignalGroupBufferPtr(sigGrp));
}                               /* End of Com_UpdateShadowSignal() */
#  endif  /* ((COM_TXSIGNAL_ACCESS_MACRO_API == STD_OFF) || (COM_TXMODEHDLR_TMS == STD_ON) || (COM_TMS_SUPPORT == STD_OFF)) */
# endif /* (COM_SIGNALGROUPIF == STD_ON) */

# if (COM_SIGNAL_ACCESS_MACRO_API == STD_ON) && (COM_APPLTYPE_UINT8N == STD_ON)
FUNC(void, COM_CODE) Com_TxSigIf_SendByteArray(PduIdType ComPduId,
                                               P2CONST(uint8, AUTOMATIC, COM_APPL_VAR) SignalDataPtr, P2VAR(uint8,
                                                                                                            AUTOMATIC,
                                                                                                            COM_VAR_NOINIT)
                                               BufferDataPtr, uint16 count)
{
  while (count > (uint16) 0x0000)
  {
    count--;
    BufferDataPtr[count] = SignalDataPtr[count];
  }
}
# endif
#endif /* COM_TXSIGIF == STD_ON */
/* KB end Com_TxSigIf_GlobalFunctions */
/* KB begin Com_SignalGw_GlobalFunctions */
#if (COM_SIGNALGW == STD_ON)
# if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
#  error "File Com.c: The Target Tms320 is not supported for signal routing!"
# endif /* (_TEXAS_INSTRUMENTS_C_TMS320_) */
# if (COM_SIGNAL_ACCESS_MACRO_API != STD_ON)
FUNC(void, COM_CODE) Com_MainFunctionRouteSignals(void) /* COM400 */
{
  sint16_least gwHdl;
#  if ((COM_SIGNALIF == STD_ON) || (COM_SIGNALGROUPIF == STD_ON))
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pSigBuf = &(com_Buffer[Com_ConfigValue(Com_SignalGw_SignalBufferIdx)]);       /* signal and partial signal buffer */
#  endif
#  if (COM_SIGNALGROUPIF == STD_ON)
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pRxGrpShdBuf; /* shadow buffer for rx signal group */
  P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) pTxGrpShdBuf; /* shadow buffer for tx signal group */
#  endif

  if (com_LMgt_Status == COM_INIT)
  {
    for (gwHdl = (sint16_least) Com_ConfigValue(Com_SignalGw_NumberOfRoutedIpdus) - 1; gwHdl >= 0; gwHdl--)
    {
      if (Com_SignalGw_HandleSignalGwEvent(gwHdl))
      {
#  if ((COM_SIGNALIF == STD_ON) || (COM_SIGNALGROUPIF == STD_ON))
        Com_SignalGw_RRHdlType startIdx, stopIdx, iRR;  /* Start and Stop indices to iterate over routing relations */
        Com_SignalIdType rxSigId, txSigId;
#  endif
#  if (COM_SIGNALGROUPIF == STD_ON)
        Com_SignalGw_RRHdlType startGrpIdx, stopGrpIdx, iGrpRR;
        Com_SignalGroupIdType rxSigGrpId, txSigGrpId;
#  endif
#  if (COM_SIGNALGW_UB == STD_ON)
        boolean ubStateRoute = TRUE;
        Com_Signal_SignalBitPositionType ubPos;
#  endif
#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
        PduLengthType ComPduLength = com_SignalGw_IndicationFlag[gwHdl] - 1;
#  endif/* (COM_DYNAMIC_DLC_SUPPORT == STD_ON) */

        Com_SignalGw_ClrHandleSignalGwEvent(gwHdl);

#  if (COM_SIGNALGW_SUSPENDISRPERPDU == STD_ON)
        SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
#  endif
#  if (COM_SIGNALGW_STOPTXONRXTIMEOUT == STD_ON)
        {
          PduIdType txPduIdx = Com_SignalGw_StopTxOnRxToutIdx[gwHdl];
          PduIdType txPduIdxStop = Com_SignalGw_StopTxOnRxToutIdx[gwHdl + 1];

          for (; txPduIdx < txPduIdxStop; txPduIdx++)
          {
            PduIdType ComTxPduId = Com_SignalGw_StopTxPduList[txPduIdx];

            if ((com_TxModeHdlr_CyclicSendRequest[ComTxPduId] == FALSE)
                && ((Com_TxModeHdlr_GetCurrentTxMode(ComTxPduId) & COM_TXMODEHDLR_TXMODE_PERIODIC) !=
                    (Com_TxModeHdlr_TxModeMode) 0x00u))
            {
              com_TxModeHdlr_CyclicSendRequest[ComTxPduId] = TRUE;
              com_TxModeHdlr_CycleTimeCnt[ComTxPduId] = (uint16) 1u;
            }
          }
        }
#  endif /* (COM_SIGNALGW_STOPTXONRXTIMEOUT == STD_ON) */
#  if (COM_SIGNALIF == STD_ON)
        /* ------ Route Signals ---------------------------------------------------------------- */
        startIdx = Com_ConfigValue(Com_SignalGw_IpduRoutingInfo)[gwHdl].SigRRStartIdx;
        stopIdx = Com_ConfigValue(Com_SignalGw_IpduRoutingInfo)[gwHdl + 1].SigRRStartIdx;
        rxSigId = COM_SIGNALGW_INVALIDSIGID;

#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
        for (iRR = startIdx;
             ((iRR < stopIdx) && (Com_ConfigValue(Com_SignalGw_SignalRR)[iRR].validDlc <= ComPduLength)); iRR++)
#   else
        for (iRR = startIdx; iRR < stopIdx; iRR++)
#   endif
        {
          if (Com_ConfigValue(Com_SignalGw_SignalRR)[iRR].Com_SignalGw_SignalRRTypeRxId != rxSigId)
          {
            rxSigId = Com_ConfigValue(Com_SignalGw_SignalRR)[iRR].Com_SignalGw_SignalRRTypeRxId;
            Com_LMgt_CheckFatalErrorBreak((Com_Signal_GetSignalCnt() > rxSigId), Com_SignalGw_InvalidSignalHandle);

#   if (COM_SIGNALGW_UB == STD_ON)
            /* Evaluate presence and value of update bit */
            ubStateRoute = TRUE;
            ubPos = Com_ConfigValue(Com_SignalGw_SignalRR)[iRR].UbPosition;
            if (COM_SIGNALGW_UBNOTUSED != ubPos)
            {
              /* Ub is used for the Rx Signal. Get Update Bit state */
              ubStateRoute = Com_RxBuffer_BitIsSet(Com_Signal_GetIpduFromSignal(rxSigId), ubPos);
            }
            if (TRUE == ubStateRoute)
#   endif
            {
              PduIdType rxPduId = Com_Signal_GetIpduFromSignal(rxSigId);
              Com_RxBuffer_ReadIpduSignal(rxSigId, rxPduId, pSigBuf);
            }
          }

#   if (COM_SIGNALGW_UB == STD_ON)
          if (TRUE == ubStateRoute)
#   endif
          {
            txSigId = Com_ConfigValue(Com_SignalGw_SignalRR)[iRR].Com_SignalGw_SignalRRTypeTxId;
#   if (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON)
            (void) Com_TxSigIf_SendSignal(txSigId, pSigBuf);
#   else
            (void) Com_SendSignal(txSigId, pSigBuf);
#   endif /* (COM_CONFIG_VARIANT == 3) && (COM_EXTSIGHDLSPACE == STD_ON) */
          }
        }
#  endif /* (COM_SIGNALIF == STD_ON) */

#  if (COM_SIGNALGROUPIF == STD_ON)
        /* ------ Route Signal Groups ---------------------------------------------------------- */

        startGrpIdx = Com_ConfigValue(Com_SignalGw_IpduRoutingInfo)[gwHdl].SigGrpRRStartIdx;
        stopGrpIdx = Com_ConfigValue(Com_SignalGw_IpduRoutingInfo)[gwHdl + 1].SigGrpRRStartIdx;
        rxSigGrpId = COM_SIGNALGW_INVALIDSIGGRPID;

#   if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
        for (iGrpRR = startGrpIdx;
             ((iGrpRR < stopGrpIdx) && (Com_ConfigValue(Com_SignalGw_SignalGroupRR)[iGrpRR].validDlc <= ComPduLength));
             iGrpRR++)
#   else
        for (iGrpRR = startGrpIdx; iGrpRR < stopGrpIdx; iGrpRR++)
#   endif
        {
          if (Com_ConfigValue(Com_SignalGw_SignalGroupRR)[iGrpRR].Com_SignalGw_SignalGroupRRTypeRxId != rxSigGrpId)
          {
            rxSigGrpId = Com_ConfigValue(Com_SignalGw_SignalGroupRR)[iGrpRR].Com_SignalGw_SignalGroupRRTypeRxId;
            Com_LMgt_CheckFatalErrorBreak((Com_Signal_GetSignalGroupCnt() > rxSigGrpId),
                                          Com_SignalGw_InvalidSignalGrpHandle);

#   if (COM_SIGNALGW_UB == STD_ON)
            /* Evaluate presence and value of update bit */
            ubStateRoute = TRUE;
            ubPos = Com_ConfigValue(Com_SignalGw_SignalGroupRR)[iGrpRR].Com_SignalGw_SignalGroupRRTypeUbPosition;
            if (COM_SIGNALGW_UBNOTUSED != ubPos)
            {
              /* Ub is used for the Rx Signal. Get Update Bit state */
              ubStateRoute = Com_RxBuffer_BitIsSet(Com_Signal_GetIpduFromSignalGroup(rxSigGrpId), ubPos);
            }
            if (TRUE == ubStateRoute)
#   endif
            {
              PduIdType rxPduId = Com_Signal_GetIpduFromSignalGroup(rxSigGrpId);
              pRxGrpShdBuf = Com_Signal_GetSignalGroupBufferPtr(rxSigGrpId);
              /* Copy Signal Group to local gateway shadow buffer */
#   if (COM_SIGNALGW_SUSPENDISRPERPDU != STD_ON)
              SchM_Enter_Com(COM_EXCLUSIVE_AREA_0);
#   endif
              Com_RxBuffer_ReadSignalGroup(rxSigGrpId, rxPduId, pRxGrpShdBuf);
#   if (COM_SIGNALGW_SUSPENDISRPERPDU != STD_ON)
              SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
#   endif
            }
          }
#   if (COM_SIGNALGW_UB == STD_ON)
          if (TRUE == ubStateRoute)
#   endif
          {
            /* Copy all Partial Signals from Rx shadow buffer to Tx shadow buffer */
            txSigGrpId = Com_ConfigValue(Com_SignalGw_SignalGroupRR)[iGrpRR].Com_SignalGw_SignalGroupRRTypeTxId;
            pTxGrpShdBuf = Com_Signal_GetSignalGroupBufferPtr(txSigGrpId);
            startIdx =
              Com_ConfigValue(Com_SignalGw_SignalGroupRR)[iGrpRR].Com_SignalGw_SignalGroupRRTypePartSigStartIdx;
            stopIdx =
              Com_ConfigValue(Com_SignalGw_SignalGroupRR)[iGrpRR + 1].Com_SignalGw_SignalGroupRRTypePartSigStartIdx;

            for (iRR = startIdx; iRR < stopIdx; iRR++)
            {
              rxSigId = Com_ConfigValue(Com_SignalGw_GroupSignalRR)[iRR].Com_SignalGw_GroupSignalRRTypeRxId;
              txSigId = Com_ConfigValue(Com_SignalGw_GroupSignalRR)[iRR].Com_SignalGw_GroupSignalRRTypeTxId;

              Com_Buffer_ReadShadowSignal(rxSigId, pSigBuf, pRxGrpShdBuf);
              Com_TxSigIf_UpdateShadowSignal(txSigId, pSigBuf, pTxGrpShdBuf);
            }

            /* Send Signal Group */
            (void) Com_TxSigIf_SendSignalGroup(txSigGrpId, pTxGrpShdBuf);
          }
        }
#  endif /* (COM_SIGNALGROUPIF == STD_ON) */
#  if (COM_SIGNALGW_SUSPENDISRPERPDU == STD_ON)
        SchM_Exit_Com(COM_EXCLUSIVE_AREA_0);
#  endif
      }
    }
  }
}                               /* End of Com_MainFunctionRouteSignals() */
# endif /* (COM_SIGNAL_ACCESS_MACRO_API != STD_ON) */

# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_SignalGw_Indication(PduIdType ComRxPduId, PduLengthType ComPduLength)
# else
COM_STATIC FUNC(void, COM_CODE) Com_SignalGw_Indication(PduIdType ComRxPduId)
# endif
{
  PduIdType gwHdl = Com_ConfigValue(Com_SignalGw_RxIpdu2GwHandle)[(ComRxPduId)];
  if (COM_SIGNALGW_NOROUTINGHDL != gwHdl)
  {
    Com_LMgt_CheckFatalErrorRetVoid((gwHdl < Com_ConfigValue(Com_SignalGw_NumberOfRoutedIpdus)),
                                    Com_SignalGw_InvalidGwHandle);
# if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
    com_SignalGw_IndicationFlag[gwHdl] = ComPduLength + 1;
# else
    com_SignalGw_IndicationFlag[gwHdl] = TRUE;
# endif /* (COM_DYNAMIC_DLC_SUPPORT == STD_ON) */
  }
# if (COM_SIGNALGW_RXTIMEOUT == STD_ON)
  com_SignalGw_IPduTimeoutFlag[ComRxPduId] = FALSE;
# endif
# if (COM_SIGNALGW_RXTIMEOUTUB == STD_ON)
  {
    uint16_least ubId;
#  if (COM_DYNAMIC_DLC_SUPPORT == STD_ON)
    for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[ComRxPduId];
         ((ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[ComRxPduId + 1]) &&
          (Com_ConfigValue(Com_RxUbHdlr_UbBitPosition)[ubId].validDlc > ComPduLength)); ubId++)
#  else
    for (ubId = Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[ComRxPduId];
         ubId < Com_ConfigValue(Com_RxUbHdlr_Ipdu2UpdateBits)[ComRxPduId + 1]; ubId++)
#  endif
    {
      Com_LMgt_CheckFatalErrorRetVoid((ubId < Com_RxUbHdlr_GetUpdateBitCnt()), Com_RxUbHdlr_InvalidUbHdl);
      if (TRUE ==
          Com_RxBuffer_BitIsSet(ComRxPduId, Com_ConfigValue(Com_RxUbHdlr_UbBitPosition)[ubId].updatebitPosition))
      {
        com_SignalGw_UbTimeoutFlag[(Com_RxUbHdlr_UbIdType) ubId] = FALSE;
      }
    }
  }
# endif
}

# if (COM_SIGNALGW_RXTIMEOUT == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_SignalGw_RxIpduTimeout(PduIdType ComRxPduId)
{
#  if ((COM_SIGNALGW_STOPTXONRXTIMEOUT == STD_ON) || (COM_SIGNALGW_INVTXONRXTO_IPDU == STD_ON))
  PduIdType gwHdl = Com_ConfigValue(Com_SignalGw_RxIpdu2GwHandle)[ComRxPduId];
#  endif

  if (FALSE == com_SignalGw_IPduTimeoutFlag[ComRxPduId])
  {
    com_SignalGw_IPduTimeoutFlag[ComRxPduId] = TRUE;
#  if (COM_SIGNALGW_MSV == STD_ON)
    {
      Com_SignalGw_IpduMsvEventIdType iEvent, startIdx, stopIdx;

      startIdx = Com_ConfigValue(Com_SignalGw_RxIpdu2MsvEvents)[ComRxPduId];
      stopIdx = Com_ConfigValue(Com_SignalGw_RxIpdu2MsvEvents)[ComRxPduId + 1];
      for (iEvent = startIdx; iEvent < stopIdx; iEvent++)
      {
        P2CONST(Com_SignalGw_IpduMsvEventType, AUTOMATIC, COM_PBCFG) pEvent;
        pEvent = &(Com_ConfigValue(Com_SignalGw_IpduMsvEvent)[iEvent]);

        /* Write Timeout Value to Tx Buffer */
        SchM_Enter_Com(COM_EXCLUSIVE_AREA_4);
        Com_TxBuffer_WriteIpduWithMask(pEvent->Com_SignalGw_IpduMsvEventTypePduId,
                                       Com_ConfigValue(Com_SignalGw_MissingSourceValue)[pEvent->
                                                                                        Com_SignalGw_IpduMsvEventTypePduId],
                                       pEvent->Com_SignalGw_IpduMsvEventTypeMask);
        SchM_Exit_Com(COM_EXCLUSIVE_AREA_4);

#   if (COM_TXMODEHDLR == STD_ON) && (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)
        /* Trigger transmission if required */
        if (COM_SIGNALGW_NOTRIGGERTX != pEvent->Com_SignalGw_IpduMsvEventTypeTxMode)
        {
          Com_TxModeHdlr_TriggerDeferredIpduSend(pEvent->Com_SignalGw_IpduMsvEventTypePduId);
        }
#   endif
      }
    }
#  endif /* (COM_SIGNALGW_MSV == STD_ON) */

#  if ((COM_SIGNALGW_INVTXONRXTO_IPDU == STD_ON) || (COM_SIGNALGW_STOPTXONRXTIMEOUT == STD_ON))
    if (COM_SIGNALGW_NOROUTINGHDL != gwHdl)
    {
#   if (COM_SIGNALGW_INVTXONRXTO_IPDU == STD_ON)
#    if (COM_SIGNALGW_INVSIG_IPDU == STD_ON)
      /* ------ Invalidate Signals ---------------------------------------------------------------- */
      {
        Com_SignalGw_TxInvSigHdlType sigIdx, sigStopIdx;
        Com_SignalIdType txSigId;
        sigIdx = Com_ConfigValue(Com_SignalGw_RxIPdu2TxInvObj)[gwHdl].TxInvSigStartIdx;
        sigStopIdx = Com_ConfigValue(Com_SignalGw_RxIPdu2TxInvObj)[gwHdl + 1].TxInvSigStartIdx;
        for (; sigIdx < sigStopIdx; sigIdx++)
        {
          txSigId = Com_ConfigValue(Com_SignalGw_TxInvSignals)[sigIdx];
          (void) Com_InvalidateSignal(txSigId);
#     if (COM_SIGNALGW_TRIGGERTXONINV == STD_ON)
          Com_TxModeHdlr_TriggerIpduSendOnceDeferred(Com_Signal_GetIpduFromSignal(txSigId));
#     endif
        }
      }
#    endif /* (COM_SIGNALGW_INVSIG_IPDU == STD_ON) */
#    if (COM_SIGNALGW_INVSIGGRP_IPDU == STD_ON)
      /* ------ Invalidate Signal Groups ---------------------------------------------------------- */
      {
        Com_SignalGw_TxInvSigHdlType sigGroupIdx, sigGroupStopIdx;
        Com_SignalGroupIdType txSigGrpId;
        sigGroupIdx = Com_ConfigValue(Com_SignalGw_RxIPdu2TxInvObj)[gwHdl].TxInvSigGrpStartIdx;
        sigGroupStopIdx = Com_ConfigValue(Com_SignalGw_RxIPdu2TxInvObj)[gwHdl + 1].TxInvSigGrpStartIdx;
        for (; sigGroupIdx < sigGroupStopIdx; sigGroupIdx++)
        {
          txSigGrpId = Com_ConfigValue(Com_SignalGw_TxInvSignalGroups)[sigGroupIdx];
          (void) Com_InvalidateSignalGroup(txSigGrpId);
#     if (COM_SIGNALGW_TRIGGERTXONINV == STD_ON)
          Com_TxModeHdlr_TriggerIpduSendOnceDeferred(Com_Signal_GetIpduFromSignalGroup(txSigGrpId));
#     endif
        }
      }
#    endif /* (COM_SIGNALGW_INVSIGGRP_IPDU == STD_ON) */
#   endif /* (COM_SIGNALGW_INVTXONRXTO_IPDU == STD_ON) */

#   if (COM_SIGNALGW_STOPTXONRXTIMEOUT == STD_ON)
      {
        PduIdType txPduIdx = Com_SignalGw_StopTxOnRxToutIdx[gwHdl];
        PduIdType txPduIdxStop = Com_SignalGw_StopTxOnRxToutIdx[gwHdl + 1];

        for (; txPduIdx < txPduIdxStop; txPduIdx++)
        {
          com_TxModeHdlr_CyclicSendRequest[Com_SignalGw_StopTxPduList[txPduIdx]] = FALSE;
        }
      }
#   endif /* (COM_SIGNALGW_STOPTXONRXTIMEOUT == STD_ON) */
    }
#  endif /* ((COM_SIGNALGW_INVTXONRXTO_IPDU == STD_ON) || (COM_SIGNALGW_STOPTXONRXTIMEOUT == STD_ON)) */
  }
}                               /* End of Com_SignalGw_RxIpduTimeout() */
# endif /* (COM_SIGNALGW_RXTIMEOUT == STD_ON) */


# if (COM_SIGNALGW_RXTIMEOUTUB == STD_ON)
COM_STATIC FUNC(void, COM_CODE) Com_SignalGw_RxUbTimeout(Com_RxUbHdlr_UbIdType ubId)
{
  if (FALSE == com_SignalGw_UbTimeoutFlag[ubId])
  {
    com_SignalGw_UbTimeoutFlag[ubId] = TRUE;
#  if (COM_SIGNALGW_MSV == STD_ON)
    {
      Com_SignalGw_UbMsvEventIdType iEvent, startIdx, stopIdx;
      startIdx = Com_ConfigValue(Com_SignalGw_RxUb2MsvEvents)[ubId];
      stopIdx = Com_ConfigValue(Com_SignalGw_RxUb2MsvEvents)[ubId + 1];
      for (iEvent = startIdx; iEvent < stopIdx; iEvent++)
      {
        P2CONST(Com_SignalGw_UbMsvEventType, AUTOMATIC, COM_PBCFG) pEvent;
        pEvent = &(Com_ConfigValue(Com_SignalGw_UbMsvEvent)[iEvent]);

        /* Write Timeout Value to Tx Buffer */
        SchM_Enter_Com(COM_EXCLUSIVE_AREA_4);
        Com_TxBuffer_WriteIpduWithMask(pEvent->Com_SignalGw_UbMsvEventTypePduId,
                                       Com_ConfigValue(Com_SignalGw_MissingSourceValue)[pEvent->
                                                                                        Com_SignalGw_UbMsvEventTypePduId],
                                       pEvent->Com_SignalGw_UbMsvEventTypeMask);
        SchM_Exit_Com(COM_EXCLUSIVE_AREA_4);

#   if (COM_TXMODEHDLR == STD_ON) && (COM_TXMODEHDLR_DIRECT_TRANSMISSION == STD_ON)
        /* Trigger transmission if required */
        if (COM_SIGNALGW_NOTRIGGERTX != pEvent->Com_SignalGw_UbMsvEventTypeTxMode)
        {
          Com_TxModeHdlr_TriggerDeferredIpduSend(pEvent->Com_SignalGw_UbMsvEventTypePduId);
        }
#   endif
      }
    }
#  endif
#  if (COM_SIGNALGW_INVTXONRXTO_UB == STD_ON)
#   if (COM_SIGNALGW_INVSIG_UB == STD_ON)
    /* ------ Invalidate Signals ---------------------------------------------------------- */
    {
      Com_SignalGw_TxInvSigHdlType sigIdx, sigStopIdx;
      Com_SignalIdType txSigId;
      sigIdx = Com_ConfigValue(Com_SignalGw_RxUb2TxInvObj)[ubId].TxInvSigStartIdx;
      sigStopIdx = Com_ConfigValue(Com_SignalGw_RxUb2TxInvObj)[ubId + 1].TxInvSigStartIdx;
      for (; sigIdx < sigStopIdx; sigIdx++)
      {
        txSigId = Com_ConfigValue(Com_SignalGw_TxInvSignals)[sigIdx];
        (void) Com_InvalidateSignal(txSigId);
#    if (COM_SIGNALGW_TRIGGERTXONINV == STD_ON)
        Com_TxModeHdlr_TriggerIpduSendOnceDeferred(Com_Signal_GetIpduFromSignal(txSigId));
#    endif
      }
    }
#   endif /* (COM_SIGNALGW_INVSIG_UB == STD_ON) */
#   if (COM_SIGNALGW_INVSIGGRP_UB == STD_ON)
    /* ------ Invalidate Signal Groups ---------------------------------------------------------- */
    {
      Com_SignalGw_TxInvSigHdlType sigGroupIdx, sigGroupStopIdx;
      Com_SignalGroupIdType txSigGrpId;
      sigGroupIdx = Com_ConfigValue(Com_SignalGw_RxUb2TxInvObj)[ubId].TxInvSigGrpStartIdx;
      sigGroupStopIdx = Com_ConfigValue(Com_SignalGw_RxUb2TxInvObj)[ubId + 1].TxInvSigGrpStartIdx;
      for (; sigGroupIdx < sigGroupStopIdx; sigGroupIdx++)
      {
        txSigGrpId = Com_ConfigValue(Com_SignalGw_TxInvSignalGroups)[sigGroupIdx];
        (void) Com_InvalidateSignalGroup(txSigGrpId);
#    if (COM_SIGNALGW_TRIGGERTXONINV == STD_ON)
        Com_TxModeHdlr_TriggerIpduSendOnceDeferred(Com_Signal_GetIpduFromSignalGroup(txSigGrpId));
#    endif
      }
    }
#   endif /* (COM_SIGNALGW_INVSIGGRP_UB == STD_ON) */
#  endif /* (COM_SIGNALGW_INVTXONRXTO_UB == STD_ON) */
  }
}                               /* End of Com_SignalGw_RxUbTimeout() */
# endif /* (COM_SIGNALGW_RXTIMEOUTUB == STD_ON) */

#endif /* (COM_SIGNALGW == STD_ON) */
/* KB end Com_SignalGw_GlobalFunctions */

/*=============================================COM_STOP_SEC_CODE=====================================================*/
#define COM_STOP_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************
  END OF FILE: Com.c
**********************************************************************************************************************/
/* STOPSINGLE_OF_MULTIPLE */
